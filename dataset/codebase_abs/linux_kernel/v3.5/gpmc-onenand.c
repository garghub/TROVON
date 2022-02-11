static int F_1 ( int V_1 , void T_1 * V_2 )
{
struct V_3 V_4 ;
T_2 V_5 ;
int V_6 ;
const int V_7 = 15 ;
const int V_8 = 12 ;
const int V_9 = 7 ;
const int V_10 = 76 ;
const int V_11 = 76 ;
const int V_12 = 20 ;
const int V_13 = 20 ;
const int V_14 = 30 ;
const int V_15 = 40 ;
const int V_16 = 30 ;
V_5 = F_2 ( V_2 + V_17 ) ;
V_5 &= ~ V_18 & ~ V_19 ;
F_3 ( V_5 , V_2 + V_17 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_20 = 0 ;
V_4 . V_21 = 0 ;
V_4 . V_22 = 0 ;
V_4 . V_23 = F_4 ( F_5 ( int , V_8 , V_7 ) ) ;
V_4 . V_24 = V_4 . V_23 + F_4 ( V_9 ) ;
V_4 . V_25 = V_4 . V_22 + F_4 ( V_11 ) ;
V_4 . V_25 = F_5 ( int , V_4 . V_25 , V_4 . V_21 + F_4 ( V_10 ) ) ;
V_4 . V_25 = F_5 ( int , V_4 . V_25 , V_4 . V_24 + F_4 ( V_12 ) ) ;
V_4 . V_26 = V_4 . V_25 + F_4 ( 1 ) ;
V_4 . V_27 = V_4 . V_26 ;
V_4 . V_28 = V_4 . V_27 + F_4 ( V_13 ) ;
V_4 . V_29 = V_4 . V_23 ;
V_4 . V_30 = V_4 . V_24 ;
if ( F_6 () ) {
V_4 . V_31 = V_4 . V_30 ;
V_4 . V_32 = V_4 . V_30 + F_4 ( V_14 ) ;
}
V_4 . V_33 = V_4 . V_30 + F_4 ( V_15 ) ;
V_4 . V_34 = V_4 . V_33 + F_4 ( V_16 ) ;
V_4 . V_35 = V_4 . V_34 + F_4 ( V_13 ) ;
F_7 ( V_1 , V_36 ,
V_37 |
V_38 ) ;
V_6 = F_8 ( V_1 , & V_4 ) ;
if ( V_6 )
return V_6 ;
V_5 = F_2 ( V_2 + V_17 ) ;
V_5 &= ~ V_18 & ~ V_19 ;
F_3 ( V_5 , V_2 + V_17 ) ;
return 0 ;
}
static void F_9 ( void T_1 * V_2 , int V_39 ,
int V_40 , int V_41 , int V_42 , int V_43 )
{
T_2 V_5 ;
V_5 = F_2 ( V_2 + V_17 ) ;
V_5 &= ~ ( ( 0x7 << V_44 ) | ( 0x7 << 9 ) ) ;
V_5 |= ( V_39 << V_44 ) |
V_45 ;
if ( V_40 )
V_5 |= V_18 ;
else
V_5 &= ~ V_18 ;
if ( V_41 )
V_5 |= V_19 ;
else
V_5 &= ~ V_19 ;
if ( V_42 )
V_5 |= V_46 ;
else
V_5 &= ~ V_46 ;
if ( V_43 )
V_5 |= V_47 ;
else
V_5 &= ~ V_47 ;
F_3 ( V_5 , V_2 + V_17 ) ;
}
static int F_10 ( struct V_48 * V_49 ,
void T_1 * V_2 , bool * V_50 )
{
T_3 V_51 = F_2 ( V_2 + V_52 ) ;
int V_53 = 0 ;
if ( V_49 -> V_54 ) {
struct V_55 V_56 ;
V_56 . V_57 = F_2 ( V_2 + V_58 ) ;
V_56 . V_59 = F_2 ( V_2 + V_60 ) ;
V_56 . V_61 = V_51 ;
V_53 = V_49 -> V_54 ( & V_56 , V_50 ) ;
if ( V_53 )
return V_53 ;
}
switch ( ( V_51 >> 4 ) & 0xf ) {
case 0 :
V_53 = 40 ;
break;
case 1 :
V_53 = 54 ;
break;
case 2 :
V_53 = 66 ;
break;
case 3 :
V_53 = 83 ;
break;
case 4 :
V_53 = 104 ;
break;
default:
V_53 = 54 ;
break;
}
return V_53 ;
}
static int F_11 ( struct V_48 * V_49 ,
void T_1 * V_2 ,
int * V_62 )
{
struct V_3 V_4 ;
const int V_7 = 15 ;
const int V_8 = 12 ;
const int V_13 = 20 ;
const int V_14 = 30 ;
const int V_15 = 40 ;
const int V_16 = 30 ;
int V_63 , V_64 , V_65 , V_66 , V_67 , V_9 , V_68 ;
int div , V_69 , V_70 , V_71 , V_39 ;
int V_72 = 0 , V_42 = 0 , V_43 = 0 , V_40 = 0 , V_41 = 0 ;
int V_6 , V_73 ;
int V_1 = V_49 -> V_1 , V_53 = * V_62 ;
T_2 V_5 ;
bool V_50 = false ;
if ( V_49 -> V_74 & V_75 ) {
V_40 = 1 ;
} else if ( V_49 -> V_74 & V_76 ) {
V_40 = 1 ;
V_41 = 1 ;
} else
return F_1 ( V_1 , V_2 ) ;
if ( ! V_53 ) {
V_6 = F_1 ( V_1 , V_2 ) ;
if ( V_6 )
return V_6 ;
V_53 = F_10 ( V_49 , V_2 , & V_50 ) ;
V_72 = 1 ;
}
switch ( V_53 ) {
case 104 :
V_63 = 9600 ;
V_64 = 3 ;
V_65 = 4 ;
V_66 = 2 ;
V_67 = 3 ;
V_9 = 6 ;
V_68 = 6 ;
break;
case 83 :
V_63 = 12000 ;
V_64 = 5 ;
V_65 = 4 ;
V_66 = 2 ;
V_67 = 6 ;
V_9 = 6 ;
V_68 = 9 ;
break;
case 66 :
V_63 = 15000 ;
V_64 = 6 ;
V_65 = 5 ;
V_66 = 2 ;
V_67 = 6 ;
V_9 = 6 ;
V_68 = 11 ;
break;
default:
V_63 = 18500 ;
V_64 = 7 ;
V_65 = 7 ;
V_66 = 7 ;
V_67 = 9 ;
V_9 = 7 ;
V_68 = 15 ;
V_41 = 0 ;
break;
}
div = F_12 ( V_1 , V_63 ) ;
V_71 = F_13 ( div ) ;
if ( V_71 < 15 )
V_42 = 1 ;
if ( V_71 < 12 )
V_43 = 1 ;
if ( V_43 )
V_39 = 8 ;
else if ( V_42 )
V_39 = 6 ;
else if ( V_71 >= 25 )
V_39 = 3 ;
else
V_39 = 4 ;
if ( V_50 ) {
if ( V_71 < 12 ) {
V_64 = 3 ;
V_65 = 4 ;
} else if ( V_71 < 15 ) {
V_64 = 5 ;
V_65 = 4 ;
} else if ( V_71 < 25 ) {
V_64 = 6 ;
V_65 = 5 ;
} else {
V_64 = 7 ;
V_65 = 7 ;
}
}
if ( V_72 )
F_9 ( V_2 , V_39 ,
V_40 , V_41 , V_42 , V_43 ) ;
if ( div == 1 ) {
V_5 = F_14 ( V_1 , V_77 ) ;
V_5 |= ( 1 << 7 ) ;
F_7 ( V_1 , V_77 , V_5 ) ;
V_5 = F_14 ( V_1 , V_78 ) ;
V_5 |= ( 1 << 7 ) ;
F_7 ( V_1 , V_78 , V_5 ) ;
V_5 = F_14 ( V_1 , V_79 ) ;
V_5 |= ( 1 << 7 ) ;
V_5 |= ( 1 << 23 ) ;
F_7 ( V_1 , V_79 , V_5 ) ;
} else {
V_5 = F_14 ( V_1 , V_77 ) ;
V_5 &= ~ ( 1 << 7 ) ;
F_7 ( V_1 , V_77 , V_5 ) ;
V_5 = F_14 ( V_1 , V_78 ) ;
V_5 &= ~ ( 1 << 7 ) ;
F_7 ( V_1 , V_78 , V_5 ) ;
V_5 = F_14 ( V_1 , V_79 ) ;
V_5 &= ~ ( 1 << 7 ) ;
V_5 &= ~ ( 1 << 23 ) ;
F_7 ( V_1 , V_79 , V_5 ) ;
}
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_20 = V_63 ;
V_4 . V_21 = 0 ;
V_4 . V_22 = 0 ;
V_69 = F_4 ( F_5 ( int , V_64 , V_65 ) ) ;
V_70 = F_15 ( V_69 ) ;
V_4 . V_80 = V_71 ;
V_4 . V_23 = F_13 ( V_70 + F_15 ( V_66 ) ) ;
V_4 . V_24 = F_13 ( V_70 + F_15 ( V_67 ) ) ;
if ( V_4 . V_24 <= V_4 . V_23 )
V_4 . V_24 = V_4 . V_23 + F_4 ( 1 ) ;
V_4 . V_25 = F_13 ( V_70 + ( V_39 + 1 ) * div ) ;
V_4 . V_26 = V_4 . V_25 + F_4 ( 1 ) ;
V_4 . V_27 = V_4 . V_26 ;
V_73 = ( ( F_15 ( V_13 ) + div - 1 ) / div ) * div ;
V_4 . V_28 = F_13 ( V_70 + ( V_39 + 1 ) * div +
V_73 ) ;
if ( V_41 ) {
V_4 . V_29 = V_4 . V_23 ;
V_4 . V_30 = 0 ;
V_4 . V_33 = V_4 . V_27 ;
V_4 . V_34 = V_4 . V_27 ;
V_4 . V_35 = V_4 . V_28 ;
if ( F_6 () ) {
V_4 . V_31 = F_13 ( V_70 +
F_16 ( V_63 +
V_68 * 1000 ) ) ;
V_4 . V_32 = V_4 . V_25 ;
}
} else {
V_4 . V_29 = F_4 ( F_5 ( int ,
V_8 , V_7 ) ) ;
V_4 . V_30 = V_4 . V_29 + F_4 ( V_9 ) ;
V_4 . V_33 = V_4 . V_30 + F_4 ( V_15 ) ;
V_4 . V_34 = V_4 . V_33 + F_4 ( V_16 ) ;
V_4 . V_35 = V_4 . V_34 + F_4 ( V_13 ) ;
if ( F_6 () ) {
V_4 . V_31 = V_4 . V_30 ;
V_4 . V_32 = V_4 . V_30 + F_4 ( V_14 ) ;
}
}
F_7 ( V_1 , V_36 ,
V_81 |
V_82 |
( V_40 ? V_83 : 0 ) |
( V_41 ? V_84 : 0 ) |
( V_41 ? V_85 : 0 ) |
F_17 ( V_70 ) |
F_18 ( 2 ) |
( F_6 () ? 0 :
( V_86 |
F_19 ( 0 ) ) ) |
V_37 |
V_87 |
V_38 ) ;
V_6 = F_8 ( V_1 , & V_4 ) ;
if ( V_6 )
return V_6 ;
F_9 ( V_2 , V_39 , V_40 , V_41 , V_42 , V_43 ) ;
* V_62 = V_53 ;
return 0 ;
}
static int F_20 ( void T_1 * V_2 , int * V_62 )
{
struct V_88 * V_89 = & V_90 . V_89 ;
if ( F_11 ( V_91 , V_2 ,
V_62 ) < 0 ) {
F_21 ( V_89 , L_1 ) ;
return - V_92 ;
}
return 0 ;
}
void T_4 F_22 ( struct V_48 * V_93 )
{
V_91 = V_93 ;
V_91 -> V_94 = F_20 ;
V_90 . V_89 . V_95 = V_91 ;
if ( F_23 () &&
( V_91 -> V_74 & V_76 ) ) {
F_24 ( V_96 L_2 ) ;
V_91 -> V_74 &= ~ V_76 ;
V_91 -> V_74 |= V_75 ;
}
if ( F_25 ( & V_90 ) < 0 ) {
F_24 ( V_96 L_3 ) ;
return;
}
}
