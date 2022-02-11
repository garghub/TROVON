void F_1 ( void T_1 * V_1 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
F_3 ( V_2 & ~ ( V_4 | V_5 ) ,
V_1 + V_3 ) ;
V_2 = F_2 ( V_1 + V_3 ) ;
F_3 ( V_2 & ~ V_6 , V_1 + V_3 ) ;
F_4 ( 100 ) ;
F_3 ( V_2 | V_6 , V_1 + V_3 ) ;
}
void F_5 ( void T_1 * V_1 , unsigned int V_7 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) ;
if ( V_7 == V_8 ) {
F_3 ( ( V_2 & V_9 ) |
V_4 ,
V_1 + V_3 ) ;
} else if ( V_7 == V_10 ) {
F_3 ( ( V_2 & V_9 ) |
V_5 ,
V_1 + V_3 ) ;
} else {
F_3 ( V_2 & V_9 ,
V_1 + V_3 ) ;
}
}
void F_6 ( void T_1 * V_1 , unsigned int V_11 ,
unsigned int V_12 )
{
unsigned int V_2 ;
unsigned int V_13 ;
unsigned int V_14 ;
if ( V_12 == V_15 ) {
V_13 = V_16 ;
V_14 = V_17 ;
} else {
V_13 = V_18 ;
V_14 = V_19 ;
}
V_2 = F_2 ( V_1 + V_20 ) &
V_21 ;
switch ( V_11 ) {
case V_22 :
V_2 = V_2 | V_23 | V_24 ;
break;
case V_25 :
V_2 = V_2 | V_26 |
V_27 ;
break;
case V_28 :
V_2 = V_2 | V_26 |
V_29 ;
break;
case V_30 :
V_2 = V_2 | V_31 |
V_32 |
V_13 ;
break;
case V_33 :
V_2 = V_2 | V_31 |
V_32 |
V_14 ;
break;
case V_34 :
V_2 = V_2 | V_35 |
V_36 |
V_13 ;
break;
case V_37 :
V_2 = V_2 | V_35 |
V_36 |
V_14 ;
break;
case V_38 :
V_2 = V_2 | V_35 |
V_39 |
V_13 ;
break;
case V_40 :
V_2 = V_2 | V_35 |
V_39 |
V_14 ;
break;
case V_41 :
V_2 = V_2 | V_42 |
V_43 |
V_13 ;
break;
case V_44 :
V_2 = V_2 | V_42 |
V_43 |
V_14 ;
break;
case V_45 :
V_2 = V_2 | V_42 |
V_46 |
V_13 ;
break;
default:
break;
}
F_3 ( V_2 , V_1 + V_20 ) ;
}
void F_7 ( void T_1 * V_1 , unsigned int V_47 ,
unsigned int V_12 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_20 ) &
~ ( V_12 == V_15 ? V_48 :
V_49 ) ;
switch ( V_47 ) {
case V_50 :
V_2 = V_2 | V_51 ;
break;
case V_52 :
V_2 = V_2 | V_53 ;
break;
case V_54 :
V_2 = V_2 | V_55 ;
break;
case V_56 :
V_2 = V_2 | V_57 ;
break;
default:
break;
}
F_3 ( V_2 , V_1 + V_20 ) ;
}
void F_8 ( void T_1 * V_1 , unsigned int V_12 )
{
unsigned int V_2 ;
if ( V_12 == V_15 ) {
V_2 = F_2 ( V_1 + V_58 ) & ~ V_59 ;
F_3 ( V_2 | V_60 , V_1 + V_58 ) ;
} else {
V_2 = F_2 ( V_1 + V_58 ) &
~ V_61 ;
F_3 ( V_2 | V_62 , V_1 + V_58 ) ;
}
}
unsigned int F_9 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_63 ) ;
}
unsigned int F_10 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_64 ) ;
}
void F_11 ( void T_1 * V_1 , int V_65 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ V_66 ;
if ( V_65 == 1 )
F_3 ( V_2 | V_66 ,
V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_66 ,
V_1 + V_3 ) ;
}
void F_12 ( void T_1 * V_1 , int V_65 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ ( V_67 ) ;
if ( V_65 == 1 )
F_3 ( V_2 | V_67 , V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_67 , V_1 + V_3 ) ;
}
void F_13 ( void T_1 * V_1 ,
unsigned int V_68 )
{
F_3 ( V_68 , V_1 + V_69 ) ;
}
void F_14 ( void T_1 * V_1 ,
unsigned int V_70 , unsigned int V_71 )
{
F_3 ( 0x0 , V_1 + V_72 ) ;
F_3 ( F_15 ( V_70 ) | F_16 ( V_71 ) ,
V_1 + V_72 ) ;
}
void F_17 ( void T_1 * V_1 ,
struct V_73 * V_74 )
{
F_3 ( V_74 -> V_75 , V_1 + V_76 ) ;
F_3 ( V_74 -> V_77 , V_1 + V_78 ) ;
F_3 ( V_74 -> V_79 , V_1 + V_80 ) ;
}
void F_18 ( void T_1 * V_1 ,
enum V_81 V_82 )
{
unsigned int V_2 ;
V_2 = V_83 | V_84 |
V_85 |
V_86 |
V_87 |
V_88 ;
F_3 ( V_2 , V_1 + V_89 ) ;
}
void F_19 ( void T_1 * V_1 , int V_90 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_89 ) ;
V_2 |= F_20 ( V_90 ) ;
F_3 ( V_2 , V_1 + V_89 ) ;
}
void F_21 ( void T_1 * V_1 , char V_91 , char V_92 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_89 ) ;
V_2 |= F_22 ( V_91 , V_92 ) ;
F_3 ( V_2 , V_1 + V_89 ) ;
}
void F_23 ( void T_1 * V_1 , char V_91 , char V_92 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_89 ) ;
V_2 |= F_24 ( V_91 , V_92 ) ;
F_3 ( V_2 , V_1 + V_89 ) ;
}
void F_25 ( void T_1 * V_1 , unsigned int V_93 )
{
if ( V_93 == V_22 )
F_3 ( 0xd2 , V_1 + V_94 ) ;
else
F_3 ( 0x1a2 , V_1 + V_94 ) ;
}
unsigned int F_26 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_95 ) ;
}
void F_27 ( void T_1 * V_1 , unsigned int V_96 )
{
F_3 ( V_96 , V_1 + V_95 ) ;
}
void F_28 ( void T_1 * V_1 ,
unsigned int * V_97 , unsigned int * V_98 )
{
* V_97 = ( F_2 ( V_1 + V_99 ) &
V_100 ) ;
* V_98 = ( F_2 ( V_1 + V_99 ) >> 16 ) &
V_100 ;
}
unsigned int F_29 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_101 ) &
V_102 ;
}
void F_30 ( void T_1 * V_1 , unsigned int V_96 )
{
F_3 ( V_96 , V_1 + V_103 ) ;
}
