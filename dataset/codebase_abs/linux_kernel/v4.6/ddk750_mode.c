static unsigned long F_1 ( T_1 * V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 ;
V_3 = V_1 -> V_5 ;
V_4 = V_1 -> V_6 ;
F_2 ( V_7 , 0 ) ;
F_2 ( V_8 ,
( ( ( V_4 - 1 ) << V_9 ) &
V_10 ) |
( ( V_3 - 1 ) & V_11 ) ) ;
V_2 &= ~ V_12 ;
if ( V_3 == 800 && V_4 == 600 )
V_2 |= V_13 ;
else if ( V_3 == 1024 && V_4 == 768 )
V_2 |= V_14 ;
else if ( V_3 == 1152 && V_4 == 864 )
V_2 |= V_15 ;
else if ( V_3 == 1280 && V_4 == 768 )
V_2 |= V_15 ;
else if ( V_3 == 1280 && V_4 == 720 )
V_2 |= V_16 ;
else if ( V_3 == 1280 && V_4 == 960 )
V_2 |= V_17 ;
else if ( V_3 == 1280 && V_4 == 1024 )
V_2 |= V_17 ;
else
V_2 |= V_18 ;
V_2 |= ( V_19 | V_20 ) ;
V_2 = V_21 ;
F_2 ( V_22 , V_2 ) ;
return V_2 ;
}
static int F_3 ( T_1 * V_1 , T_2 * V_23 )
{
int V_24 = 0 ;
int V_25 = 0 ;
unsigned int V_26 , V_27 ;
if ( V_23 -> V_28 == V_29 ) {
F_2 ( V_30 , F_4 ( V_23 ) ) ;
F_2 ( V_31 ,
( ( ( V_1 -> V_32 - 1 ) <<
V_33 ) &
V_34 ) |
( ( V_1 -> V_5 - 1 ) &
V_35 ) ) ;
F_2 ( V_36 ,
( ( V_1 -> V_37 <<
V_38 ) &
V_39 ) |
( ( V_1 -> V_40 - 1 ) &
V_41 ) ) ;
F_2 ( V_42 ,
( ( ( V_1 -> V_43 - 1 ) <<
V_44 ) &
V_45 ) |
( ( V_1 -> V_6 - 1 ) &
V_46 ) ) ;
F_2 ( V_47 ,
( ( V_1 -> V_48 <<
V_49 ) &
V_50 ) |
( ( V_1 -> V_51 - 1 ) &
V_52 ) ) ;
V_26 = V_53 | V_54 ;
if ( V_1 -> V_55 )
V_26 |= V_56 ;
if ( V_1 -> V_57 )
V_26 |= V_58 ;
if ( F_5 () == V_59 ) {
F_1 ( V_1 , V_26 ) ;
} else {
V_27 = F_6 ( V_22 ) &
~ ( V_56 |
V_58 |
V_53 | V_54 ) ;
F_2 ( V_22 , V_26 | V_27 ) ;
}
} else if ( V_23 -> V_28 == V_60 ) {
unsigned int V_61 ;
F_2 ( V_62 , F_4 ( V_23 ) ) ;
V_27 = ( ( V_1 -> V_32 - 1 ) <<
V_63 ) &
V_64 ;
V_27 |= ( ( V_1 -> V_5 - 1 ) &
V_65 ) ;
F_2 ( V_66 , V_27 ) ;
F_2 ( V_67 ,
( ( V_1 -> V_37 <<
V_68 ) &
V_69 ) |
( ( V_1 -> V_40 - 1 ) &
V_70 ) ) ;
F_2 ( V_71 ,
( ( ( V_1 -> V_43 - 1 ) <<
V_72 ) &
V_73 ) |
( ( V_1 -> V_6 - 1 ) &
V_74 ) ) ;
F_2 ( V_75 ,
( ( V_1 -> V_48 <<
V_76 ) &
V_77 ) |
( ( V_1 -> V_51 - 1 ) &
V_78 ) ) ;
V_26 = V_53 | V_54 ;
if ( V_1 -> V_55 )
V_26 |= V_56 ;
if ( V_1 -> V_57 )
V_26 |= V_58 ;
if ( V_1 -> V_79 )
V_26 |= V_21 ;
V_61 = V_80 |
V_81 ;
V_27 = ( F_6 ( V_82 ) & ~ V_61 ) &
~ ( V_21 | V_56 |
V_58 | V_53 |
V_54 ) ;
F_2 ( V_82 , V_26 | V_27 ) ;
while ( ( F_6 ( V_82 ) & ~ V_61 ) !=
( V_26 | V_27 ) ) {
V_25 ++ ;
if ( V_25 > 1000 )
break;
F_2 ( V_82 , V_26 | V_27 ) ;
}
} else {
V_24 = - 1 ;
}
return V_24 ;
}
int F_7 ( T_1 * V_83 , T_3 clock )
{
T_2 V_23 ;
unsigned int V_84 ;
V_23 . V_85 = V_86 ;
V_23 . V_28 = clock ;
V_84 = F_8 ( V_83 -> V_87 , & V_23 ) ;
if ( F_5 () == V_59 ) {
F_9 ( 0x88 , 0x3d4 ) ;
F_9 ( 0x06 , 0x3d5 ) ;
}
F_3 ( V_83 , & V_23 ) ;
return 0 ;
}
