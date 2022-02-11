static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 ;
int V_4 = 0 ;
struct V_5 * V_6 ;
V_6 = F_2 ( V_2 ) ;
if ( ! V_6 )
return - V_7 ;
if ( V_6 -> V_8 != V_9 )
return - V_10 ;
F_3 ( V_11 , 0 ) ;
if ( V_6 -> V_12 . V_13 == V_14 ) {
F_3 ( V_15 , 0x0081B697 ) ;
} else {
F_3 ( V_15 , 0x008bc4a3 ) ;
V_3 |= V_16 ;
}
F_3 ( V_17 , 0x0 ) ;
F_3 ( V_18 , 0x0020009e ) ;
F_3 ( V_19 , 0x011306B4 ) ;
F_3 ( V_20 , 0x0006000C ) ;
F_3 ( V_21 , 0x0028020D ) ;
F_3 ( V_22 , 0x005E02FB ) ;
F_3 ( V_23 , 0x0006000C ) ;
F_3 ( V_24 , 0x00000012 ) ;
F_3 ( V_25 , 0x0013020D ) ;
F_3 ( V_26 , 0x0014020C ) ;
F_3 ( V_27 , 0x0013020D ) ;
F_3 ( V_28 , 0x0014020C ) ;
F_3 ( V_29 , 0x00AE00F2 ) ;
F_3 ( V_30 , 0x00280208 ) ;
F_3 ( V_31 , 0x00290209 ) ;
V_3 |= V_32 ;
V_3 |= V_33 |
V_34 |
V_35 | V_36 ;
#ifdef F_4
V_3 |= V_37 ;
#endif
F_3 ( V_38 , 0x00000000 ) ;
F_3 ( V_39 , 0x008080f0 ) ;
#ifdef F_5
F_3 ( V_40 , 0x29 ) ;
#endif
F_3 ( V_11 , V_3 ) ;
V_3 |= V_41 ;
F_3 ( V_11 , V_3 ) ;
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_3 ( V_11 , 0 ) ;
return 0 ;
}
static int T_2 F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
return 0 ;
}
static int T_2 F_9 ( void )
{
int V_4 ;
V_4 = F_10 ( & V_42 ) ;
if ( ! V_4 ) {
V_4 = F_11 ( & V_43 ) ;
if ( V_4 )
F_12 ( & V_42 ) ;
}
return V_4 ;
}
