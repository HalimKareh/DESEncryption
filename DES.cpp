#include <iostream>
using namespace std;

const int IP[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
const int E[48]={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
const int S1[64]={14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13};
const int S2[64]={15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9};
const int S3[64]={10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12};
const int S4[64]={7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14};
const int S5[64]={2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3};
const int S6[64]={12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13};
const int S7[64]={4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12};
const int S8[64]={13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11};
const int P[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
const int IIP[64]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
const int PC1[56]={57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
const int PC2[48]={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
const int SoLS[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
const int SoRS[16]={0,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

int Plain[64];
int Temp64[64];
int Temp48[48];
int Temp1[32];
int Temp2[32];
int K1[64];
int K2[64];
int K3[64];
int LeftPlain[32];
int RightPlain[32];
int LeftKey[28];
int RightKey[28];
int TempKey[56];
int RoundKey[48];

// Save function
void SAVE(int main[32],int *temp)
{
	int i = 0;
	while(i < 32)
	{
		temp[i] = main[i];
		i++;
	}
}

// Function for XOR Operation
int XOR(int A, int B)
{
	return ((A+B)%2);
}

// Initial Permutation and Inverse Initial Permutation
void IPe(const int Ref[64], int main[64], int *temp)
{
	int i = 0;
	while(i < 64)
	{
		temp[i] = main[Ref[i]-1];
		i++;
	}
}

// Division in left and right of the Plaintext
void DIPLAIN(int main[64],int *left, int *right)
{
	int i = 0;
	while(i < 64)
	{
		if(i < 32)
		{
			left[i] = main[i];
		}
		else
		{
			right[i-32] = main[i];
		}
		i++;
	}
}


// Expansion / Permutation
void EP(const int Ref[48], int plain[32], int *temp)
{
	int i = 0;
	while(i < 48)
	{
		temp[i] = plain[Ref[i]-1];
		i++;
	}

}

// Row Calculation
int row(int A, int B)
{
	return ((A*2)+B);
}

// Column Calculation
int column(int A, int B, int C, int D)
{
	return ((A*8)+(B*4)+(C*2)+D);
}

// Filling with binary values using one S-BOX
void SB(int *temp, int number, int count)
{
	int i = 3;
	while(i >= 0)
	{
		temp[4*count+i] = number%2;
		number = number / 2;
		i--;
	}
}

// Filling right after the S-BOX
void SBOX(int main[48], int *temp)
{
	int i = 0;
	int rowi = 0;
	int columni = 0;
	int index = 0;
	while(i < 8)
	{
		rowi = row(main[6*i],main[6*i+5])*16;
		columni = column(main[6*i+1],main[6*i+2],main[6*i+3],main[6*i+4]);
		index = rowi + columni;
		if(i == 0)
		{
			SB(temp,S1[index],i);
		}
		if(i == 1)
		{
			SB(temp,S2[index],i);
		}
		if(i == 2)
		{
			SB(temp,S3[index],i);
		}
		if(i == 3)
		{
			SB(temp,S4[index],i);
		}
		if(i == 4)
		{
			SB(temp,S5[index],i);
		}
		if(i == 5)
		{
			SB(temp,S6[index],i);
		}
		if(i == 6)
		{
			SB(temp,S7[index],i);
		}
		if(i == 7)
		{
			SB(temp,S8[index],i);
		}
		i++;
	}
}


// Round Permutation
void RP(const int Ref[32], int plain[32], int *temp)
{
	int i = 0;
	while(i < 32)
	{
		temp[i] = plain[Ref[i]-1];
		i++;
	}
}

// Copying in a main array for Plaintext
void COPYPLAIN(int left[32], int right[32], int *main)
{
	int i = 0;
	while(i < 64)
	{
		if(i < 32)
		{
			main[i] = left[i];
		}
		else
		{
			main[i] = right[i-32];
		}
		i++;
	}
}

// Apply PC1
void PeC1(const int Ref[56], int main[64], int *temp)
{
	int i = 0;
	while(i < 56)
	{
		temp[i] = main[Ref[i]-1];
		i++;
	}

}

// Division in left and right of the Key
void DIKEY(int main[56], int *left, int *right)
{
	int i = 0;
	while(i < 56)
	{
		if(i < 28)
		{
			left[i] = main[i];
		}
		else
		{
			right[i-28] = main[i];
		}
		i++;
	}
}

// Rotate Key for Encryption
void ROTE(int *main, int round)
{
	int temp;
	int i = 0;
	if(SoLS[round] == 1)
	{
		temp = main[i];
		while(i < 27)
		{
			main[i] = main[i+1];
			i++;
		}
		main[i] = temp;
	}
	if(SoLS[round] == 2)
	{
		temp = main[i];
		int temp1 = main[i+1];
		while(i < 26)
		{
			main[i] = main[i+2];
			i++;
		}
		main[i] = temp;
		main[i+1] = temp1;
	}
}

// Rotate Key for Decryption
void ROTD(int *main, int round)
{
	int temp;
	int i = 27;
	if(SoRS[round] == 1)
	{
		temp = main[i];
		while(i > 0)
		{
			main[i] = main[i-1];
			i--;
		}
		main[i] = temp;
	}
	if(SoRS[round] == 2)
	{
		temp = main[i];
		int temp1 = main[i-1];
		while(i > 1)
		{
			main[i] = main[i-2];
			i--;
		}
		main[i] = temp;
		main[i-1] = temp1;
	}
}

// Copying in a main array for Subkey
void COPYKEY(int left[28], int right[28], int *main)
{
	int i = 0;
	while(i < 56)
	{
		if(i < 28)
		{
			main[i] = left[i];
		}
		else
		{
			main[i] = right[i-28];
		}
		i++;
	}
}

// Apply PC2
void PeC2(const int Ref[48], int main[56], int *temp)
{
	int i = 0;
	while(i < 48)
	{
		temp[i] = main[Ref[i]-1];
		i++;
	}

}

// One Encryption 
void EncryptDES(int *Key)
{
	int round = 0;
	int i = 0;
	// Initial permutation
	IPe(IP,Plain,Temp64);
	DIPLAIN(Temp64,LeftPlain,RightPlain);
	// PC1 Key
	PeC1(PC1,Key,TempKey);
	DIKEY(TempKey,LeftKey,RightKey);
	// DES round
	while(round < 16)
	{
		SAVE(LeftPlain,Temp1);
		SAVE(RightPlain,LeftPlain);
		// Expansion
		EP(E,RightPlain,Temp48);
		// Generation of the SubKey
		ROTE(LeftKey,round);
		ROTE(RightKey,round);
		COPYKEY(LeftKey,RightKey,TempKey);
		PeC2(PC2,TempKey,RoundKey);
		// XOR with the Key
		i = 0;
		while(i < 48)
		{
			Temp48[i] = XOR(Temp48[i],RoundKey[i]);
			i++;
		}
		// S-Box Transformation
		SBOX(Temp48,Temp2);
		// Permutation
		RP(P,Temp2,RightPlain);
		// XOR with left
		i = 0;
		while(i < 32)
		{
			RightPlain[i] = XOR(RightPlain[i],Temp1[i]);
			i++;
		}
		round++;
	}
	// 32-bits swap
	COPYPLAIN(RightPlain,LeftPlain,Temp64);
	// Inverse initial permutation
	IPe(IIP,Temp64,Plain);
}

// One Decrypt
void DecryptDES(int *Key)
{
	int round = 0;
	int i = 0;
	// Initial permutation
	IPe(IIP,Plain,Temp64);
	DIPLAIN(Temp64,LeftPlain,RightPlain);
	// PC1 Key
	PeC1(PC1,Key,TempKey);
	DIKEY(TempKey,LeftKey,RightKey);
	// DES round
	while(round < 16)
	{
		SAVE(LeftPlain,Temp1);
		SAVE(RightPlain,LeftPlain);
		// Expansion
		EP(E,RightPlain,Temp48);
		// Generation of the SubKey
		ROTD(LeftKey,round);
		ROTD(RightKey,round);
		COPYKEY(LeftKey,RightKey,TempKey);
		PeC2(PC2,TempKey,RoundKey);
		// XOR with the Key
		while(i < 48)
		{
			Temp48[i] = XOR(Temp48[i],RoundKey[i]);
			i++;
		}
		// S-Box Transformation
		SBOX(Temp48,Temp2);
		// Permutation
		RP(P,Temp2,RightPlain);
		i = 0;
		// XOR with left
		while(i < 32)
		{
			RightPlain[i] = XOR(RightPlain[i],Temp1[i]);
			i++;
		}
		round++;
	}
	// 32-bits swap
	COPYPLAIN(RightPlain,LeftPlain,Temp64);
	// Inverse initial permutation
	IPe(IIP,Temp64,Plain);
}

// Full Encryption
void TripleEnDES()
{
	EncryptDES(K1);
	DecryptDES(K2);
	EncryptDES(K3);
}

// Full Decryption
void TripleDeDES()
{
	DecryptDES(K1);
	EncryptDES(K2);
	DecryptDES(K3);
}
