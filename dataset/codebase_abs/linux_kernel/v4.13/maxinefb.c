void F_1 ( int V_1 , register unsigned int V_2 )
{
register unsigned char * V_3 = ( char * ) V_4 ;
unsigned char * V_5 ;
V_5 = V_3 + 0xa0000 + ( V_1 << 4 ) ;
* ( ( volatile unsigned int * ) ( V_3 ) ) = ( V_2 >> 8 ) & 0xff00 ;
* ( ( volatile unsigned short * ) ( V_5 ) ) = V_2 ;
}
unsigned int F_2 ( int V_1 )
{
register unsigned char * V_3 = ( char * ) V_4 ;
unsigned char * V_6 ;
register unsigned int V_7 , V_8 ;
V_6 = V_3 + 0x80000 + ( V_1 << 4 ) ;
V_7 = * ( ( volatile unsigned short * ) V_6 ) ;
V_8 = * ( ( volatile unsigned short * ) V_3 ) ;
return ( V_7 & 0xffff ) | ( ( V_8 & 0xff00 ) << 8 ) ;
}
static int F_3 ( unsigned V_1 , unsigned V_9 , unsigned V_10 ,
unsigned V_11 , unsigned V_12 , struct V_13 * V_14 )
{
unsigned long V_15 = 0 ;
if ( V_1 > 255 )
return 1 ;
V_9 >>= 8 ;
V_10 >>= 8 ;
V_11 >>= 8 ;
V_15 = ( V_11 << 16 ) + ( V_10 << 8 ) + ( V_9 ) ;
F_1 ( V_16 + V_1 ,
V_15 ) ;
return 0 ;
}
int T_1 F_4 ( void )
{
unsigned long V_17 ;
unsigned long V_18 ;
int V_19 ;
if ( F_5 ( L_1 , NULL ) )
return - V_20 ;
if ( V_21 != V_22 ) {
return - V_23 ;
}
F_6 ( V_24 L_2 ) ;
F_6 ( V_24 L_3 ) ;
V_18 = V_25 ;
for ( V_17 = V_18 ; V_17 < V_18 + 0x1ffff ; V_17 ++ )
* ( volatile unsigned char * ) V_17 = 0x0 ;
V_26 . V_27 = V_18 ;
for ( V_19 = 0 ; V_19 < 512 ; V_19 ++ ) {
F_1 ( V_28 + V_19 ,
0 ) ;
}
V_13 . V_29 = & V_30 ;
V_13 . V_31 = ( char * ) V_26 . V_27 ;
V_13 . V_32 = V_33 ;
V_13 . V_34 = V_26 ;
V_13 . V_35 = V_36 ;
F_7 ( & V_13 . V_37 , 256 , 0 ) ;
if ( F_8 ( & V_13 ) < 0 )
return 1 ;
return 0 ;
}
static void T_2 F_9 ( void )
{
F_10 ( & V_13 ) ;
}
