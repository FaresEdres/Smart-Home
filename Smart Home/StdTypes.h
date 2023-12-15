#ifndef STDTYPES_H_
#define STDTYPES_H_

typedef unsigned char u8 ;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef enum{
	False,
	True
}Bool_t;

typedef enum{
	OK,
	NOK,
	NULLPTR=0,
	OUTOFRANGE
};

#define NULL_PTR  ((void*)0)
#define NULL      ((char)0)
#define MAX_uint8 ((u8)255)
#define MIN_uint8 ((u8)0)

#endif