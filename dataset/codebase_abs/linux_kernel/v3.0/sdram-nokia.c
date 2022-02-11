static unsigned long F_1 ( long V_1 )
{
return 1000000000 / V_1 ;
}
static unsigned int F_2 ( unsigned int V_2 , long V_1 )
{
unsigned long V_3 ;
V_3 = F_1 ( V_1 ) ;
return ( V_2 + V_3 - 1 ) / V_3 ;
}
static int F_3 ( int V_4 , long V_1 ,
const struct V_5 * V_6 )
{
T_1 V_7 ;
T_1 V_8 , V_9 ;
T_1 V_10 = 0 , V_11 = 0 ;
T_1 V_12 ;
int V_13 = 0 ;
long V_14 = V_1 / 1000 ;
F_4 ( & V_10 , 0 , 4 , V_15 , V_14 ) ;
F_4 ( & V_10 , 6 , 8 , V_16 , V_14 ) ;
F_4 ( & V_10 , 9 , 11 , V_17 , V_14 ) ;
F_4 ( & V_10 , 12 , 14 , V_18 , V_14 ) ;
F_4 ( & V_10 , 15 , 17 , V_19 , V_14 ) ;
F_4 ( & V_10 , 18 , 21 , V_20 , V_14 ) ;
F_4 ( & V_10 , 22 , 26 , V_21 , V_14 ) ;
F_4 ( & V_10 , 27 , 31 , V_22 , V_14 ) ;
F_4 ( & V_11 , 0 , 7 , V_23 , V_14 ) ;
F_5 ( & V_11 , 8 , 10 , V_24 , V_14 ) ;
F_5 ( & V_11 , 12 , 14 , V_25 , V_14 ) ;
F_5 ( & V_11 , 16 , 17 , V_26 , V_14 ) ;
V_7 = V_14 ;
V_8 = V_6 [ 0 ] . V_27 * V_7 / 1000000 ;
if ( V_8 > 65535 + 50 )
V_8 = 65535 ;
else
V_8 -= 50 ;
#ifdef F_6
F_7 ( V_28 L_1 , V_8 ) ;
#endif
V_9 = V_8 << 8 ;
V_12 = V_9 | 0x1 ;
V_29 [ V_4 ] . V_1 = V_1 ;
V_29 [ V_4 ] . V_10 = V_10 ;
V_29 [ V_4 ] . V_11 = V_11 ;
V_29 [ V_4 ] . V_12 = V_12 ;
V_29 [ V_4 ] . V_30 = 0x32 ;
V_29 [ V_4 + 1 ] . V_1 = 0 ;
return V_13 ;
}
struct V_31 * F_8 ( void )
{
int V_13 = 0 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_9 ( V_33 ) ; V_32 ++ ) {
V_13 |= F_3 ( V_32 , V_33 [ V_32 ] . V_1 ,
V_33 [ V_32 ] . V_34 ) ;
if ( V_13 )
F_10 ( L_2 , V_35 ,
V_33 [ V_32 ] . V_1 , V_13 ) ;
}
return V_13 ? NULL : V_29 ;
}
