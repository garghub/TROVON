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
void F_6 ( void T_1 * V_1 , unsigned int V_10 ,
unsigned int V_11 )
{
unsigned int V_2 ;
unsigned int V_12 ;
unsigned int V_13 ;
if ( V_11 == V_14 ) {
V_12 = V_15 ;
V_13 = V_16 ;
} else {
V_12 = V_17 ;
V_13 = V_18 ;
}
V_2 = F_2 ( V_1 + V_19 ) &
V_20 ;
switch ( V_10 ) {
case V_21 :
V_2 = V_2 | V_22 | V_23 ;
break;
case V_24 :
V_2 = V_2 | V_25 |
V_26 ;
break;
case V_27 :
V_2 = V_2 | V_25 |
V_28 ;
break;
case V_29 :
V_2 = V_2 | V_30 |
V_31 |
V_12 ;
break;
case V_32 :
V_2 = V_2 | V_30 |
V_31 |
V_13 ;
break;
case V_33 :
V_2 = V_2 | V_34 |
V_35 |
V_12 ;
break;
case V_36 :
V_2 = V_2 | V_34 |
V_35 |
V_13 ;
break;
case V_37 :
V_2 = V_2 | V_34 |
V_38 |
V_12 ;
break;
case V_39 :
V_2 = V_2 | V_34 |
V_38 |
V_13 ;
break;
case V_40 :
V_2 = V_2 | V_41 |
V_42 |
V_12 ;
break;
case V_43 :
V_2 = V_2 | V_41 |
V_42 |
V_13 ;
break;
case V_44 :
V_2 = V_2 | V_41 |
V_45 |
V_12 ;
break;
default:
break;
}
F_3 ( V_2 , V_1 + V_19 ) ;
}
void F_7 ( void T_1 * V_1 , unsigned int V_46 ,
unsigned int V_11 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_19 ) &
~ ( V_11 == V_14 ? V_47 :
V_48 ) ;
switch ( V_46 ) {
case V_49 :
V_2 = V_2 | V_50 ;
break;
case V_51 :
V_2 = V_2 | V_52 ;
break;
case V_53 :
V_2 = V_2 | V_54 ;
break;
case V_55 :
V_2 = V_2 | V_56 ;
break;
default:
break;
}
F_3 ( V_2 , V_1 + V_19 ) ;
}
void F_8 ( void T_1 * V_1 , unsigned int V_11 )
{
unsigned int V_2 ;
if ( V_11 == V_14 ) {
V_2 = F_2 ( V_1 + V_57 ) & ~ V_58 ;
F_3 ( V_2 | V_59 , V_1 + V_57 ) ;
} else {
V_2 = F_2 ( V_1 + V_57 ) &
~ V_60 ;
F_3 ( V_2 | V_61 , V_1 + V_57 ) ;
}
}
unsigned int F_9 ( void T_1 * V_1 )
{
unsigned int V_62 ;
V_62 = F_2 ( V_1 + V_63 ) ;
return V_62 ;
}
unsigned int F_10 ( void T_1 * V_1 )
{
unsigned int V_64 ;
V_64 = F_2 ( V_1 + V_65 ) ;
return V_64 ;
}
void F_11 ( void T_1 * V_1 , int V_66 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ V_67 ;
if ( V_66 == 1 )
F_3 ( V_2 | V_67 ,
V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_67 ,
V_1 + V_3 ) ;
}
void F_12 ( void T_1 * V_1 , int V_66 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ ( V_68 ) ;
if ( V_66 == 1 )
F_3 ( V_2 | V_68 , V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_68 , V_1 + V_3 ) ;
}
void F_13 ( void T_1 * V_1 ,
unsigned int V_69 )
{
F_3 ( V_69 , V_1 + V_70 ) ;
}
void F_14 ( void T_1 * V_1 ,
unsigned int V_71 , unsigned int V_72 )
{
F_3 ( 0x0 , V_1 + V_73 ) ;
F_3 ( F_15 ( V_71 ) | F_16 ( V_72 ) ,
V_1 + V_73 ) ;
}
void F_17 ( void T_1 * V_1 ,
struct V_74 * V_75 )
{
F_3 ( V_75 -> V_76 , V_1 + V_77 ) ;
F_3 ( V_75 -> V_78 , V_1 + V_79 ) ;
F_3 ( V_75 -> V_80 , V_1 + V_81 ) ;
}
void F_18 ( void T_1 * V_1 ,
enum V_82 V_83 )
{
unsigned int V_2 ;
V_2 = V_84 | V_85 |
V_86 |
V_87 |
V_88 |
V_89 ;
F_3 ( V_2 , V_1 + V_90 ) ;
}
void F_19 ( void T_1 * V_1 , int V_91 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_90 ) ;
V_2 |= F_20 ( V_91 ) ;
F_3 ( V_2 , V_1 + V_90 ) ;
}
void F_21 ( void T_1 * V_1 , char V_92 , char V_93 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_90 ) ;
V_2 |= F_22 ( V_92 , V_93 ) ;
F_3 ( V_2 , V_1 + V_90 ) ;
}
void F_23 ( void T_1 * V_1 , char V_92 , char V_93 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_90 ) ;
V_2 |= F_24 ( V_92 , V_93 ) ;
F_3 ( V_2 , V_1 + V_90 ) ;
}
void F_25 ( void T_1 * V_1 , unsigned int V_94 )
{
if ( V_94 == V_21 )
F_3 ( 0xd2 , V_1 + V_95 ) ;
else
F_3 ( 0x1a2 , V_1 + V_95 ) ;
}
unsigned int F_26 ( void T_1 * V_1 )
{
unsigned int V_96 ;
V_96 = F_2 ( V_1 + V_97 ) ;
return V_96 ;
}
void F_27 ( void T_1 * V_1 , unsigned int V_96 )
{
F_3 ( V_96 , V_1 + V_97 ) ;
}
void F_28 ( void T_1 * V_1 ,
unsigned int * V_98 , unsigned int * V_99 )
{
* V_98 = ( F_2 ( V_1 + V_100 ) &
V_101 ) ;
* V_99 = ( F_2 ( V_1 + V_100 ) >> 16 ) &
V_101 ;
}
unsigned int F_29 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_102 ) &
V_103 ;
}
void F_30 ( void T_1 * V_1 , unsigned int V_96 )
{
F_3 ( V_96 , V_1 + V_104 ) ;
}
