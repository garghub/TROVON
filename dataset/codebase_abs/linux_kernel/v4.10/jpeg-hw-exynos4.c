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
return F_2 ( V_1 + V_62 ) ;
}
unsigned int F_10 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_63 ) ;
}
void F_11 ( void T_1 * V_1 , int V_64 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ V_65 ;
if ( V_64 == 1 )
F_3 ( V_2 | V_65 ,
V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_65 ,
V_1 + V_3 ) ;
}
void F_12 ( void T_1 * V_1 , int V_64 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_3 ) & ~ ( V_66 ) ;
if ( V_64 == 1 )
F_3 ( V_2 | V_66 , V_1 + V_3 ) ;
else
F_3 ( V_2 & ~ V_66 , V_1 + V_3 ) ;
}
void F_13 ( void T_1 * V_1 ,
unsigned int V_67 )
{
F_3 ( V_67 , V_1 + V_68 ) ;
}
void F_14 ( void T_1 * V_1 ,
unsigned int V_69 , unsigned int V_70 )
{
F_3 ( 0x0 , V_1 + V_71 ) ;
F_3 ( F_15 ( V_69 ) | F_16 ( V_70 ) ,
V_1 + V_71 ) ;
}
void F_17 ( void T_1 * V_1 ,
struct V_72 * V_73 )
{
F_3 ( V_73 -> V_74 , V_1 + V_75 ) ;
F_3 ( V_73 -> V_76 , V_1 + V_77 ) ;
F_3 ( V_73 -> V_78 , V_1 + V_79 ) ;
}
void F_18 ( void T_1 * V_1 ,
enum V_80 V_81 )
{
unsigned int V_2 ;
V_2 = V_82 | V_83 |
V_84 |
V_85 |
V_86 |
V_87 ;
F_3 ( V_2 , V_1 + V_88 ) ;
}
void F_19 ( void T_1 * V_1 , int V_89 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_88 ) ;
V_2 |= F_20 ( V_89 ) ;
F_3 ( V_2 , V_1 + V_88 ) ;
}
void F_21 ( void T_1 * V_1 , char V_90 , char V_91 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_88 ) ;
V_2 |= F_22 ( V_90 , V_91 ) ;
F_3 ( V_2 , V_1 + V_88 ) ;
}
void F_23 ( void T_1 * V_1 , char V_90 , char V_91 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 + V_88 ) ;
V_2 |= F_24 ( V_90 , V_91 ) ;
F_3 ( V_2 , V_1 + V_88 ) ;
}
void F_25 ( void T_1 * V_1 , unsigned int V_92 )
{
if ( V_92 == V_21 )
F_3 ( 0xd2 , V_1 + V_93 ) ;
else
F_3 ( 0x1a2 , V_1 + V_93 ) ;
}
unsigned int F_26 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_94 ) ;
}
void F_27 ( void T_1 * V_1 , unsigned int V_95 )
{
F_3 ( V_95 , V_1 + V_94 ) ;
}
void F_28 ( void T_1 * V_1 ,
unsigned int * V_96 , unsigned int * V_97 )
{
* V_96 = ( F_2 ( V_1 + V_98 ) &
V_99 ) ;
* V_97 = ( F_2 ( V_1 + V_98 ) >> 16 ) &
V_99 ;
}
unsigned int F_29 ( void T_1 * V_1 )
{
return F_2 ( V_1 + V_100 ) &
V_101 ;
}
void F_30 ( void T_1 * V_1 , unsigned int V_95 )
{
F_3 ( V_95 , V_1 + V_102 ) ;
}
