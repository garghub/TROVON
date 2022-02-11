static void F_1 ( void )
{
unsigned long V_1 , V_2 , V_3 , V_4 ;
T_1 V_5 , V_6 ;
F_2 ( V_1 , 0 , 0 ) ;
V_2 = V_1 | 0x200 ;
F_3 ( V_2 , 0 , 0 ) ;
V_5 = V_7 . V_8 ;
V_3 = F_4 () ;
V_7 . V_8 . V_9 = V_3 ;
V_6 . V_9 = V_3 | V_10 | V_11 ;
V_7 . V_12 = 0 ;
do {
asm volatile(
" larl %[addr],0f\n"
" stg %[addr],%[psw_wait_addr]\n"
" stg %[addr],%[psw_ext_addr]\n"
" lpswe %[psw_wait]\n"
"0:\n"
: [addr] "=&d" (addr),
[psw_wait_addr] "=Q" (psw_wait.addr),
[psw_ext_addr] "=Q" (S390_lowcore.external_new_psw.addr)
: [psw_wait] "Q" (psw_wait)
: "cc", "memory");
} while ( V_7 . V_12 != V_13 );
F_3 ( V_1 , 0 , 0 ) ;
V_7 . V_8 = V_5 ;
}
static int F_5 ( unsigned int V_14 , char * V_15 )
{
unsigned int V_16 ;
do {
asm volatile(
" .insn rre,0xb2200000,%1,%2\n"
" ipm %0\n"
: "=d" (cc) : "d" (cmd), "a" (sccb)
: "cc", "memory");
V_16 >>= 28 ;
if ( V_16 == 3 )
return - V_17 ;
F_1 () ;
} while ( V_16 != 0 );
return ( * ( unsigned short * ) ( V_15 + 6 ) == 0x20 ) ? 0 : - V_18 ;
}
static int F_6 ( int V_19 )
{
static unsigned char V_20 [] = {
0x00 , 0x1c ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x04 ,
0x80 , 0x00 , 0x00 , 0x00 , 0x40 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
unsigned int * V_21 ;
int V_22 ;
memcpy ( V_23 , V_20 , 28 ) ;
V_21 = ( unsigned int * ) ( V_23 + 12 ) ;
if ( V_19 )
memset ( V_21 , 0 , 16 ) ;
V_22 = F_5 ( 0x00780005 , V_23 ) ;
if ( V_22 )
return V_22 ;
if ( ( V_21 [ 0 ] & V_21 [ 3 ] ) != V_21 [ 0 ] ||
( V_21 [ 1 ] & V_21 [ 2 ] ) != V_21 [ 1 ] )
return - V_18 ;
return 0 ;
}
static int F_7 ( const char * V_24 )
{
static unsigned char V_25 [] = {
0x00 , 0x52 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x4a ,
0x02 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x44 ,
0x00 , 0x01 ,
0xd4 , 0xc4 , 0xc2 , 0x40 ,
0x00 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x38 ,
0x00 , 0x01 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 ,
} ;
static unsigned char V_26 [] = {
0x00 , 0x0a ,
0x00 , 0x04 ,
0x10 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00
} ;
unsigned char * V_27 , V_28 ;
unsigned int V_29 ;
memcpy ( V_23 , V_25 , sizeof( V_25 ) ) ;
V_27 = V_23 + sizeof( V_25 ) ;
do {
memcpy ( V_27 , V_26 , sizeof( V_26 ) ) ;
for ( V_29 = sizeof( V_26 ) ; ( V_28 = * V_24 ++ ) != 0 ; V_29 ++ ) {
if ( V_28 == 0x0a )
break;
V_27 [ V_29 ] = V_30 [ V_28 ] ;
}
* ( unsigned short * ) V_27 = V_29 ;
* ( unsigned short * ) ( V_23 + 14 ) += V_29 ;
* ( unsigned short * ) ( V_23 + 8 ) += V_29 ;
* ( unsigned short * ) ( V_23 + 0 ) += V_29 ;
V_27 += V_29 ;
} while ( V_28 != 0 );
return F_5 ( 0x00760005 , V_23 ) ;
}
int F_8 ( const char * V_24 )
{
int V_22 ;
V_22 = F_6 ( 0 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_7 ( V_24 ) ;
if ( V_22 )
return V_22 ;
return F_6 ( 1 ) ;
}
