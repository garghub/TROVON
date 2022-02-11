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
0x80 , 0x00 , 0x00 , 0x00 , 0x40 , 0x00 , 0x00 , 0x40 ,
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
V_24 = V_21 [ 2 ] & V_25 ;
V_26 = V_21 [ 2 ] & V_27 ;
return 0 ;
}
static void F_7 ( const char * V_28 )
{
static unsigned char V_29 [] = {
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
static unsigned char V_30 [] = {
0x00 , 0x0a ,
0x00 , 0x04 ,
0x10 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00
} ;
unsigned char * V_31 , V_32 ;
unsigned int V_33 ;
memcpy ( V_23 , V_29 , sizeof( V_29 ) ) ;
V_31 = V_23 + sizeof( V_29 ) ;
do {
memcpy ( V_31 , V_30 , sizeof( V_30 ) ) ;
for ( V_33 = sizeof( V_30 ) ; ( V_32 = * V_28 ++ ) != 0 ; V_33 ++ ) {
if ( V_32 == 0x0a )
break;
V_31 [ V_33 ] = V_34 [ V_32 ] ;
}
* ( unsigned short * ) V_31 = V_33 ;
* ( unsigned short * ) ( V_23 + 14 ) += V_33 ;
* ( unsigned short * ) ( V_23 + 8 ) += V_33 ;
* ( unsigned short * ) ( V_23 + 0 ) += V_33 ;
V_31 += V_33 ;
} while ( V_32 != 0 );
F_5 ( 0x00760005 , V_23 ) ;
}
static void F_8 ( const char * V_28 )
{
static unsigned char const V_29 [] = {
0x00 , 0x0e ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x06 ,
0x1a , 0x00 , 0x00 , 0x00 ,
} ;
T_2 V_35 = strlen ( V_28 ) ;
if ( sizeof( V_29 ) + V_35 >= sizeof( V_23 ) )
V_35 = sizeof( V_23 ) - sizeof( V_29 ) - 1 ;
memcpy ( V_23 , V_29 , sizeof( V_29 ) ) ;
memcpy ( V_23 + sizeof( V_29 ) , V_28 , V_35 ) ;
V_23 [ sizeof( V_29 ) + V_35 ] = '\n' ;
* ( unsigned short * ) ( V_23 + 8 ) += V_35 + 1 ;
* ( unsigned short * ) ( V_23 + 0 ) += V_35 + 1 ;
( void ) F_5 ( 0x00760005 , V_23 ) ;
}
void F_9 ( const char * V_28 )
{
if ( F_6 ( 0 ) != 0 )
return;
if ( V_26 )
F_7 ( V_28 ) ;
if ( V_24 )
F_8 ( V_28 ) ;
F_6 ( 1 ) ;
}
