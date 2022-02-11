static int F_1 ( unsigned int V_1 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 ) ;
F_4 ( V_1 ) ;
return 0 ;
}
static void F_5 ( unsigned int V_1 )
{
F_6 ( V_1 ) ;
F_7 ( V_1 ) ;
F_8 ( V_1 ) ;
if ( V_1 == V_2 )
V_3 [ V_4 ] = V_5 ;
}
void T_1 F_9 ( void )
{
F_10 ( V_6 , V_7 - V_8 , NULL ) ;
F_11 ( & V_9 , 1 , V_7 - 1 ) ;
#ifdef F_12
V_10 . V_11 = 0x48 ;
#else
V_10 . V_11 = 0x40 ;
#endif
V_10 . V_12 = 0x00 ;
V_10 . V_13 = 0x00 ;
V_10 . V_14 = 0xff ;
V_10 . V_15 = 0xff ;
if ( F_13 ( V_16 ) ) {
#ifdef F_12
V_17 . V_11 = 0x58 ;
#else
V_17 . V_11 = 0x50 ;
#endif
V_17 . V_12 = 0x00 ;
V_17 . V_13 = 0x00 ;
V_17 . V_14 = 0xff ;
V_17 . V_15 = 0xff ;
}
if ( F_13 ( V_18 ) && ! V_19 ) {
V_20 . V_21 = 9 ;
F_14 () ;
V_20 . V_21 = ( char ) 0xc0 ;
}
if ( F_13 ( V_22 ) ) {
V_23 . V_24 = 0x10 ;
V_23 . V_25 = 0x60 ;
} else {
V_3 [ V_26 ] = V_5 ;
V_3 [ V_4 ] = V_5 ;
}
if ( F_13 ( V_27 ) && F_13 ( V_28 ) ) {
F_15 ( V_29 ) ;
}
F_16 () ;
V_30 . V_31 = 7 ;
V_30 . V_32 = 0xff ;
}
unsigned long F_17 ( void )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < 32 ; V_33 ++ )
if ( ( V_34 & ( 1 << V_33 ) ) == 0 )
break;
if ( V_33 == 16 )
return 0 ;
V_34 |= 1 << V_33 ;
return V_35 + V_33 ;
}
void F_18 ( unsigned long V_1 )
{
if ( V_1 >= V_35 && V_1 < V_35 + V_36 ) {
V_1 -= V_35 ;
V_34 &= ~ ( 1 << V_1 ) ;
}
}
