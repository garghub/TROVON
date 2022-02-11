static void F_1 ( void )
{
unsigned long V_1 , V_2 , V_3 , V_4 ;
T_1 V_5 , V_6 ;
F_2 ( V_1 , 0 , 0 ) ;
V_2 = V_1 | 0x200 ;
F_3 ( V_2 , 0 , 0 ) ;
V_5 = V_7 . V_8 ;
V_3 = F_4 () & ( V_9 | V_10 ) ;
V_7 . V_8 . V_11 = V_3 ;
V_6 . V_11 = V_3 | V_12 | V_13 ;
V_7 . V_14 = 0 ;
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
} while ( V_7 . V_14 != V_15 );
F_3 ( V_1 , 0 , 0 ) ;
V_7 . V_8 = V_5 ;
}
static int F_5 ( unsigned int V_16 , char * V_17 )
{
unsigned int V_18 ;
do {
asm volatile(
" .insn rre,0xb2200000,%1,%2\n"
" ipm %0\n"
: "=d" (cc) : "d" (cmd), "a" (sccb)
: "cc", "memory");
V_18 >>= 28 ;
if ( V_18 == 3 )
return - V_19 ;
F_1 () ;
} while ( V_18 != 0 );
return ( * ( unsigned short * ) ( V_17 + 6 ) == 0x20 ) ? 0 : - V_20 ;
}
static int F_6 ( int V_21 )
{
static unsigned char V_22 [] = {
0x00 , 0x1c ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x04 ,
0x80 , 0x00 , 0x00 , 0x00 , 0x40 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00
} ;
unsigned int * V_23 ;
int V_24 ;
memcpy ( V_25 , V_22 , 28 ) ;
V_23 = ( unsigned int * ) ( V_25 + 12 ) ;
if ( V_21 )
memset ( V_23 , 0 , 16 ) ;
V_24 = F_5 ( 0x00780005 , V_25 ) ;
if ( V_24 )
return V_24 ;
if ( ( V_23 [ 0 ] & V_23 [ 3 ] ) != V_23 [ 0 ] ||
( V_23 [ 1 ] & V_23 [ 2 ] ) != V_23 [ 1 ] )
return - V_20 ;
return 0 ;
}
static int F_7 ( const char * V_26 )
{
static unsigned char V_27 [] = {
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
static unsigned char V_28 [] = {
0x00 , 0x0a ,
0x00 , 0x04 ,
0x10 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00
} ;
unsigned char * V_29 , V_30 ;
unsigned int V_31 ;
memcpy ( V_25 , V_27 , sizeof( V_27 ) ) ;
V_29 = V_25 + sizeof( V_27 ) ;
do {
memcpy ( V_29 , V_28 , sizeof( V_28 ) ) ;
for ( V_31 = sizeof( V_28 ) ; ( V_30 = * V_26 ++ ) != 0 ; V_31 ++ ) {
if ( V_30 == 0x0a )
break;
V_29 [ V_31 ] = V_32 [ V_30 ] ;
}
* ( unsigned short * ) V_29 = V_31 ;
* ( unsigned short * ) ( V_25 + 14 ) += V_31 ;
* ( unsigned short * ) ( V_25 + 8 ) += V_31 ;
* ( unsigned short * ) ( V_25 + 0 ) += V_31 ;
V_29 += V_31 ;
} while ( V_30 != 0 );
return F_5 ( 0x00760005 , V_25 ) ;
}
int F_8 ( const char * V_26 )
{
int V_24 ;
V_24 = F_6 ( 0 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_7 ( V_26 ) ;
if ( V_24 )
return V_24 ;
return F_6 ( 1 ) ;
}
