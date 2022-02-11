void F_1 ( void T_1 * V_1 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
F_3 ( V_2 & ~ V_4 , V_1 + V_3 ) ;
F_4 ( 100 ) ;
F_3 ( V_2 | V_4 , V_1 + V_3 ) ;
}
void F_5 ( void T_1 * V_1 , unsigned int V_5 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
if ( V_5 == V_6 ) {
F_3 ( ( V_2 & V_7 ) |
V_8 ,
V_1 + V_3 ) ;
} else {
F_3 ( ( V_2 & V_7 ) |
V_9 ,
V_1 + V_3 ) ;
}
}
void F_6 ( void T_1 * V_1 , unsigned int V_10 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_11 ) &
V_12 ;
switch ( V_10 ) {
case V_13 :
V_2 = V_2 | V_14 | V_15 ;
break;
case V_16 :
V_2 = V_2 | V_17 |
V_18 ;
break;
case V_19 :
V_2 = V_2 | V_17 |
V_20 ;
break;
case V_21 :
V_2 = V_2 | V_22 |
V_23 |
V_24 ;
break;
case V_25 :
V_2 = V_2 | V_22 |
V_23 |
V_26 ;
break;
case V_27 :
V_2 = V_2 | V_28 |
V_29 |
V_24 ;
break;
case V_30 :
V_2 = V_2 | V_28 |
V_29 |
V_26 ;
break;
case V_31 :
V_2 = V_2 | V_28 |
V_32 |
V_24 ;
break;
case V_33 :
V_2 = V_2 | V_28 |
V_32 |
V_26 ;
break;
case V_34 :
V_2 = V_2 | V_35 |
V_36 |
V_24 ;
break;
case V_37 :
V_2 = V_2 | V_35 |
V_36 |
V_26 ;
break;
case V_38 :
V_2 = V_2 | V_35 |
V_39 |
V_24 ;
break;
default:
break;
}
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_7 ( void T_1 * V_1 , unsigned int V_40 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_11 ) &
~ V_41 ;
switch ( V_40 ) {
case V_42 :
V_2 = V_2 | V_43 ;
break;
case V_44 :
V_2 = V_2 | V_45 ;
break;
case V_46 :
V_2 = V_2 | V_47 ;
break;
case V_48 :
V_2 = V_2 | V_49 ;
break;
default:
break;
}
F_3 ( V_2 , V_1 + V_11 ) ;
}
void F_8 ( void T_1 * V_1 )
{
F_3 ( V_50 , V_1 + V_51 ) ;
}
unsigned int F_9 ( void T_1 * V_1 )
{
unsigned int V_52 ;
V_52 = F_2 ( V_1 + V_53 ) ;
return V_52 ;
}
unsigned int F_10 ( void T_1 * V_1 )
{
unsigned int V_54 ;
V_54 = F_2 ( V_1 + V_55 ) ;
return V_54 ;
}
void F_11 ( void T_1 * V_1 , int V_56 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ V_57 ;
if ( V_56 == 1 )
F_3 ( V_2 | V_57 ,
V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_57 ,
V_1 + V_3 ) ;
}
void F_12 ( void T_1 * V_1 , int V_56 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ ( V_58 ) ;
if ( V_56 == 1 )
F_3 ( V_2 | V_58 , V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_58 , V_1 + V_3 ) ;
}
void F_13 ( void T_1 * V_1 ,
unsigned int V_59 )
{
F_3 ( V_59 , V_1 + V_60 ) ;
}
void F_14 ( void T_1 * V_1 ,
unsigned int V_61 , unsigned int V_62 )
{
F_3 ( 0x0 , V_1 + V_63 ) ;
F_3 ( F_15 ( V_61 ) | F_16 ( V_62 ) ,
V_1 + V_63 ) ;
}
void F_17 ( void T_1 * V_1 ,
struct V_64 * V_65 )
{
F_3 ( V_65 -> V_66 , V_1 + V_67 ) ;
F_3 ( V_65 -> V_68 , V_1 + V_69 ) ;
F_3 ( V_65 -> V_70 , V_1 + V_71 ) ;
}
void F_18 ( void T_1 * V_1 ,
enum V_72 V_73 )
{
unsigned int V_2 ;
V_2 = V_74 | V_75 |
V_76 |
V_77 |
V_78 |
V_79 ;
F_3 ( V_2 , V_1 + V_80 ) ;
}
void F_19 ( void T_1 * V_1 , unsigned int V_81 )
{
if ( V_81 == V_13 )
F_3 ( 0xd2 , V_1 + V_82 ) ;
else
F_3 ( 0x1a2 , V_1 + V_82 ) ;
}
unsigned int F_20 ( void T_1 * V_1 )
{
unsigned int V_83 ;
V_83 = F_2 ( V_1 + V_84 ) ;
return V_83 ;
}
void F_21 ( void T_1 * V_1 , unsigned int V_83 )
{
F_3 ( V_83 , V_1 + V_84 ) ;
}
void F_22 ( void T_1 * V_1 ,
unsigned int * V_85 , unsigned int * V_86 )
{
* V_85 = ( F_2 ( V_1 + V_87 ) &
V_88 ) ;
* V_86 = ( F_2 ( V_1 + V_87 ) >> 16 ) &
V_88 ;
}
unsigned int F_23 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_89 ) &
V_90 ;
}
void F_24 ( void T_1 * V_1 , unsigned int V_83 )
{
F_3 ( V_83 , V_1 + V_91 ) ;
}
