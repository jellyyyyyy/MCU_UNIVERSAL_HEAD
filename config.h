#ifndef __CONFIG_H
#define __CONFIG_H

#ifndef TRUE
#define	TRUE	1
#endif

#ifndef	FALSE
#define	FALSE	0
#endif

/********************************/
/*      CPU无关性定义           */
/********************************/
typedef unsigned char      uint8;
typedef unsigned char      uint8_t;

typedef signed char      int8;
typedef signed char      int8_t;

typedef unsigned short     uint16;
typedef unsigned short     uint16_t;

typedef signed short     int16;
typedef signed short     int16_t;

typedef unsigned long      uint32;
typedef unsigned long      uint32_t;

typedef signed long      int32;
typedef signed long      int32_t;

typedef float              fp32;
typedef double             fp64;

typedef unsigned char		BYTE;				// 8-bit unsigned
typedef unsigned short int	WORD;				// 16-bit unsigned
typedef unsigned long		DWORD;				// 32-bit unsigned
typedef unsigned long long	QWORD;				// 64-bit unsigned
typedef signed char			CHAR;				// 8-bit signed
typedef signed short int	SHORT;				// 16-bit signed
typedef signed long			LONG;				// 32-bit signed
typedef signed long long	LONGLONG;			// 64-bit signed

typedef union{
    uint16 word;
    uint8 byte[2];
}Word16;


typedef union{
    uint32 lword;
    uint16 word[2];
    uint8 byte[4];
}Word32;

typedef union{
    uint64 qword;
    uint32 lword[2];
    uint16 word[4];
    uint8 byte[8];
}Word64;

#define 	BIT0	0x01
#define 	BIT1	0x02
#define 	BIT2	0x04
#define 	BIT3	0x08
#define 	BIT4	0x10
#define 	BIT5	0x20
#define 	BIT6	0x40
#define 	BIT7	0x80

#define     BIT8    0x0100
#define     BIT9    0x0200
#define     BIT10   0x0400
#define     BIT11   0x0800
#define     BIT12   0x1000
#define     BIT13   0x2000
#define     BIT14   0x4000
#define     BIT15   0x8000

#define     BIT16    0x010000
#define     BIT17    0x020000
#define     BIT18   0x040000
#define     BIT19   0x080000
#define     BIT20   0x100000
#define     BIT21   0x200000
#define     BIT22   0x400000
#define     BIT23   0x800000

#define     BIT24    0x01000000
#define     BIT25    0x02000000
#define     BIT26   0x04000000
#define     BIT27   0x08000000
#define     BIT28   0x10000000
#define     BIT29   0x20000000
#define     BIT30   0x40000000
#define     BIT31   0x80000000

typedef union _BYTE_VAL
{
    BYTE Val;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
    } bits;
} BYTE_VAL, BYTE_BITS;

typedef union _WORD_VAL
{
    WORD Val;
    BYTE v[2];
    struct
    {
        BYTE LB;
        BYTE HB;
    } byte;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;
        unsigned char b9:1;
        unsigned char b10:1;
        unsigned char b11:1;
        unsigned char b12:1;
        unsigned char b13:1;
        unsigned char b14:1;
        unsigned char b15:1;
    } bits;
} WORD_VAL, WORD_BITS;

typedef union _DWORD_VAL
{
    DWORD Val;
	WORD w[2];
    BYTE v[4];
    struct
    {
        WORD LW;
        WORD HW;
    } word;
    struct
    {
        BYTE LB;
        BYTE HB;
        BYTE UB;
        BYTE MB;
    } byte;
    struct
    {
        WORD_VAL low;
        WORD_VAL high;
    }wordUnion;
    struct
    {
        unsigned char b0:1;
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char b5:1;
        unsigned char b6:1;
        unsigned char b7:1;
        unsigned char b8:1;
        unsigned char b9:1;
        unsigned char b10:1;
        unsigned char b11:1;
        unsigned char b12:1;
        unsigned char b13:1;
        unsigned char b14:1;
        unsigned char b15:1;
        unsigned char b16:1;
        unsigned char b17:1;
        unsigned char b18:1;
        unsigned char b19:1;
        unsigned char b20:1;
        unsigned char b21:1;
        unsigned char b22:1;
        unsigned char b23:1;
        unsigned char b24:1;
        unsigned char b25:1;
        unsigned char b26:1;
        unsigned char b27:1;
        unsigned char b28:1;
        unsigned char b29:1;
        unsigned char b30:1;
        unsigned char b31:1;
    } bits;
} DWORD_VAL;

//2BYTES
#define LSB(a)          ((a).v[0])
#define MSB(a)          ((a).v[1])

//4BYTES
#define LOWER_LSB(a)    ((a).v[0])
#define LOWER_MSB(a)    ((a).v[1])
#define UPPER_LSB(a)    ((a).v[2])
#define UPPER_MSB(a)    ((a).v[3])

#define       LongToBin(n) \
      (                    \
      ((n >> 21) & 0x80) | \
      ((n >> 18) & 0x40) | \
      ((n >> 15) & 0x20) | \
      ((n >> 12) & 0x10) | \
      ((n >>  9) & 0x08) | \
      ((n >>  6) & 0x04) | \
      ((n >>  3) & 0x02) | \
      ((n      ) & 0x01)   \
      )
#define       Bin(n)                 LongToBin(0x##n##l)	//write binary charactor set,exsample : Bin(11111111) = 0xff
