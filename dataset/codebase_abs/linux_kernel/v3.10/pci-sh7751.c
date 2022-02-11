static int T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
unsigned long V_4 ;
V_4 = F_2 ( V_5 ) ;
if ( ( ( V_4 >> V_3 ) & 1 ) == 0 ) {
F_3 ( L_1 ,
V_3 , V_4 ) ;
return 0 ;
}
F_4 ( V_2 , V_4 , V_6 ) ;
V_4 = F_5 ( V_7 ) ;
if ( ( ( V_4 >> ( V_3 << 1 ) ) & 0x3 ) != 0x3 ) {
F_3 ( L_2 ,
V_3 , V_4 ) ;
return 0 ;
}
F_4 ( V_2 , V_4 , V_8 ) ;
return 1 ;
}
static int T_1 F_6 ( void )
{
struct V_1 * V_2 = & V_9 ;
unsigned int V_10 ;
T_2 V_4 , V_11 ;
F_3 ( V_12 L_3 ) ;
V_2 -> V_13 = 0xfe200000 ;
V_10 = F_7 ( V_2 , V_14 ) ;
if ( V_10 != ( ( V_15 << 16 ) | V_16 ) &&
V_10 != ( ( V_17 << 16 ) | V_16 ) ) {
F_8 ( L_4 , V_10 ) ;
return - V_18 ;
}
V_11 = F_2 ( V_5 ) ;
V_11 |= 0x80000 ;
F_9 ( V_11 , V_5 ) ;
F_4 ( V_2 , 0 , V_19 ) ;
V_4 = V_20 | V_21 ;
F_4 ( V_2 , V_4 , V_22 ) ;
V_4 = V_23 | V_24 |
V_25 | V_26 ;
F_4 ( V_2 , V_4 , V_27 ) ;
V_4 = V_28 << 24 ;
F_4 ( V_2 , V_4 , V_29 ) ;
V_4 = V_30 . V_31 . V_32 - 1 ;
F_4 ( V_2 , V_4 , V_33 ) ;
V_4 = F_10 ( V_30 . V_31 . V_34 ) ;
F_4 ( V_2 , V_4 , V_35 ) ;
F_4 ( V_2 , V_4 , V_36 ) ;
V_4 = V_2 -> V_37 [ 1 ] . V_38 & V_39 ;
F_8 ( L_5 , V_4 ) ;
F_4 ( V_2 , V_4 , V_40 ) ;
V_4 = V_2 -> V_37 [ 0 ] . V_38 & V_41 ;
F_8 ( L_6 , V_4 ) ;
F_4 ( V_2 , V_4 , V_42 ) ;
switch ( V_30 . V_31 . V_34 ) {
case V_43 : V_4 = F_1 ( V_2 , 0 ) ; break;
case V_44 : V_4 = F_1 ( V_2 , 1 ) ; break;
case V_45 : V_4 = F_1 ( V_2 , 2 ) ; break;
case V_46 : V_4 = F_1 ( V_2 , 3 ) ; break;
case V_47 : V_4 = F_1 ( V_2 , 4 ) ; break;
case V_48 : V_4 = F_1 ( V_2 , 5 ) ; break;
case V_49 : V_4 = F_1 ( V_2 , 6 ) ; break;
}
if ( ! V_4 )
return - 1 ;
V_4 = F_2 ( V_50 ) ;
F_4 ( V_2 , V_4 , V_51 ) ;
V_4 = F_2 ( V_52 ) ;
F_4 ( V_2 , V_4 , V_53 ) ;
V_4 = F_2 ( V_54 ) ;
F_4 ( V_2 , V_4 , V_55 ) ;
V_4 = F_2 ( V_56 ) ;
F_4 ( V_2 , V_4 , V_57 ) ;
F_11 ( V_2 ) ;
V_4 = V_58 | V_59 | V_60 ;
F_4 ( V_2 , V_4 , V_61 ) ;
return F_12 ( V_2 ) ;
}
