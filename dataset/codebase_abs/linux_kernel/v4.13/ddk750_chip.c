T_1 F_1 ( void )
{
return V_1 ;
}
void F_2 ( unsigned short V_2 , T_2 V_3 )
{
if ( V_2 == 0x718 ) {
V_1 = V_4 ;
} else if ( V_2 == 0x750 ) {
V_1 = V_5 ;
if ( V_3 == V_6 ) {
V_1 = V_7 ;
F_3 ( L_1 ) ;
}
} else {
V_1 = V_8 ;
}
}
static unsigned int F_4 ( void )
{
unsigned int V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 ;
if ( F_1 () == V_7 )
return F_5 ( 130 ) ;
V_9 = F_6 ( V_14 ) ;
V_10 = ( V_9 & V_15 ) >> V_16 ;
V_11 = ( V_9 & V_17 ) >> V_18 ;
V_12 = ( V_9 & V_19 ) >> V_20 ;
V_13 = ( V_9 & V_21 ) >> V_22 ;
return V_23 * V_10 / V_11 / ( 1 << V_12 ) / ( 1 << V_13 ) ;
}
static void F_7 ( unsigned int V_24 )
{
struct V_25 V_26 ;
unsigned int V_27 ;
if ( F_1 () == V_7 )
return;
if ( V_24 ) {
V_26 . V_28 = V_23 ;
V_26 . V_29 = V_30 ;
V_27 = F_8 ( V_24 , & V_26 ) ;
F_9 ( V_14 , F_10 ( & V_26 ) ) ;
}
}
static void F_11 ( unsigned int V_24 )
{
unsigned int V_31 , V_32 ;
if ( F_1 () == V_7 )
return;
if ( V_24 ) {
if ( V_24 > F_5 ( 336 ) )
V_24 = F_5 ( 336 ) ;
V_32 = F_12 ( F_4 () , V_24 ) ;
V_31 = F_6 ( V_33 ) & ~ V_34 ;
switch ( V_32 ) {
default:
case 1 :
V_31 |= V_35 ;
break;
case 2 :
V_31 |= V_36 ;
break;
case 3 :
V_31 |= V_37 ;
break;
case 4 :
V_31 |= V_38 ;
break;
}
F_13 ( V_31 ) ;
}
}
static void F_14 ( unsigned int V_24 )
{
unsigned int V_31 , V_32 ;
if ( F_1 () == V_7 )
return;
if ( V_24 ) {
if ( V_24 > F_5 ( 190 ) )
V_24 = F_5 ( 190 ) ;
V_32 = F_12 ( F_4 () , V_24 ) ;
V_31 = F_6 ( V_33 ) & ~ V_39 ;
switch ( V_32 ) {
default:
case 3 :
V_31 |= V_40 ;
break;
case 4 :
V_31 |= V_41 ;
break;
case 6 :
V_31 |= V_42 ;
break;
case 8 :
V_31 |= V_43 ;
break;
}
F_13 ( V_31 ) ;
}
}
unsigned int F_15 ( void )
{
unsigned int V_31 ;
unsigned int V_44 ;
if ( F_1 () == V_7 )
return V_45 ;
V_31 = F_6 ( V_46 ) ;
V_31 |= V_47 ;
F_9 ( V_46 , V_31 ) ;
V_31 = F_6 ( V_48 ) & V_49 ;
switch ( V_31 ) {
case V_50 :
V_44 = V_51 ; break;
case V_52 :
V_44 = V_53 ; break;
case V_54 :
V_44 = V_55 ; break;
case V_56 :
V_44 = V_45 ; break;
default:
V_44 = 0 ;
break;
}
return V_44 ;
}
int F_16 ( struct V_57 * V_58 )
{
unsigned int V_31 ;
if ( V_58 -> V_59 != 0 )
V_58 -> V_59 = 0 ;
F_17 ( V_58 -> V_59 ) ;
V_31 = F_6 ( V_33 ) ;
V_31 |= ( V_60 | V_61 ) ;
F_13 ( V_31 ) ;
if ( F_1 () != V_7 ) {
V_31 = F_6 ( V_62 ) ;
V_31 |= ( V_63 | V_64 ) ;
F_9 ( V_62 , V_31 ) ;
} else {
#if F_18 ( V_65 ) || F_18 ( V_66 )
F_19 ( 0x88 , 0x3d4 ) ;
F_19 ( 0x06 , 0x3d5 ) ;
#endif
}
F_7 ( F_5 ( ( unsigned int ) V_58 -> V_67 ) ) ;
F_11 ( F_5 ( V_58 -> V_68 ) ) ;
F_14 ( F_5 ( V_58 -> V_69 ) ) ;
if ( V_58 -> V_70 == 1 ) {
V_31 = F_6 ( V_48 ) ;
V_31 &= ~ V_71 ;
F_9 ( V_48 , V_31 ) ;
V_31 |= V_71 ;
F_9 ( V_48 , V_31 ) ;
}
if ( V_58 -> V_72 == 1 ) {
F_20 ( 0 ) ;
V_31 = F_6 ( V_73 ) ;
V_31 &= ~ V_74 ;
F_9 ( V_73 , V_31 ) ;
V_31 = F_6 ( V_75 ) ;
V_31 &= ~ V_74 ;
F_9 ( V_75 , V_31 ) ;
V_31 = F_6 ( V_76 ) ;
V_31 &= ~ V_74 ;
F_9 ( V_76 , V_31 ) ;
V_31 = F_6 ( V_77 ) ;
V_31 |= V_78 ;
F_9 ( V_77 , V_31 ) ;
F_21 ( 0 ) ;
}
return 0 ;
}
unsigned int F_8 ( unsigned int V_79 ,
struct V_25 * V_26 )
{
int V_11 , V_10 , V_80 , V_81 ;
int V_82 ;
unsigned int V_83 , V_84 , V_85 , V_86 ;
unsigned int V_87 , V_88 ;
unsigned int V_89 , V_90 ;
const int V_91 = 3 ;
int V_92 = 6 ;
if ( F_1 () == V_7 ) {
return V_79 ;
}
V_90 = 0 ;
V_82 = ~ 0 ;
V_88 = V_79 / 1000 ;
V_87 = V_26 -> V_28 / 1000 ;
if ( V_26 -> V_29 == V_30 )
V_92 = 3 ;
for ( V_11 = 15 ; V_11 > 1 ; V_11 -- ) {
V_83 = V_11 * V_88 ;
V_84 = V_83 / V_87 ;
V_85 = V_83 % V_87 ;
V_86 = V_85 * 10000 / V_87 ;
for ( V_81 = V_92 ; V_81 >= 0 ; V_81 -- ) {
V_80 = F_22 ( V_81 ) ;
V_10 = V_84 * V_80 ;
V_10 += V_86 * V_80 / 10000 ;
V_10 += ( V_86 * V_80 % 10000 ) > 5000 ? 1 : 0 ;
if ( V_10 < 256 && V_10 > 0 ) {
unsigned int V_93 ;
V_89 = V_26 -> V_28 * V_10 / V_11 / V_80 ;
V_93 = abs ( V_89 - V_79 ) ;
if ( V_93 < V_82 ) {
V_26 -> V_10 = V_10 ;
V_26 -> V_11 = V_11 ;
V_26 -> V_13 = 0 ;
if ( V_81 > V_91 )
V_26 -> V_13 = V_81 - V_91 ;
V_26 -> V_12 = V_81 - V_26 -> V_13 ;
V_82 = V_93 ;
V_90 = V_89 ;
}
}
}
}
return V_90 ;
}
unsigned int F_10 ( struct V_25 * V_94 )
{
#ifndef F_23
unsigned int V_13 = V_94 -> V_13 ;
#endif
unsigned int V_12 = V_94 -> V_12 ;
unsigned int V_10 = V_94 -> V_10 ;
unsigned int V_11 = V_94 -> V_11 ;
unsigned int V_31 = 0 ;
V_31 = V_95 |
#ifndef F_23
( ( V_13 << V_22 ) & V_21 ) |
#endif
( ( V_12 << V_20 ) & V_19 ) |
( ( V_11 << V_18 ) & V_17 ) |
( ( V_10 << V_16 ) & V_15 ) ;
return V_31 ;
}
