T_1 F_1 ( void )
{
return V_1 ;
}
void F_2 ( unsigned short V_2 , T_2 V_3 )
{
if ( V_2 == 0x718 )
V_1 = V_4 ;
else if ( V_2 == 0x750 ) {
V_1 = V_5 ;
if ( V_3 == V_6 ) {
V_1 = V_7 ;
F_3 ( L_1 ) ;
}
} else
V_1 = V_8 ;
}
static unsigned int F_4 ( void )
{
unsigned int V_9 ;
unsigned int V_10 , V_11 , V_12 , V_13 ;
if ( F_1 () == V_7 )
return F_5 ( 130 ) ;
V_9 = F_6 ( V_14 ) ;
V_10 = ( V_9 & V_15 ) >> V_16 ;
V_11 = ( V_9 & V_17 ) >> V_16 ;
V_12 = ( V_9 & V_18 ) >> V_19 ;
V_13 = ( V_9 & V_20 ) >> V_21 ;
return V_22 * V_10 / V_11 / ( 1 << V_12 ) / ( 1 << V_13 ) ;
}
static void F_7 ( unsigned int V_23 )
{
struct V_24 V_25 ;
unsigned int V_26 ;
if ( F_1 () == V_7 )
return;
if ( V_23 ) {
V_25 . V_27 = V_22 ;
V_25 . V_28 = V_29 ;
V_26 = F_8 ( V_23 , & V_25 ) ;
F_9 ( V_14 , F_10 ( & V_25 ) ) ;
}
}
static void F_11 ( unsigned int V_23 )
{
unsigned int V_30 , V_31 ;
if ( F_1 () == V_7 )
return;
if ( V_23 ) {
if ( V_23 > F_5 ( 336 ) )
V_23 = F_5 ( 336 ) ;
V_31 = F_12 ( F_4 () , V_23 ) ;
V_30 = F_6 ( V_32 ) & ~ V_33 ;
switch ( V_31 ) {
default:
case 1 :
V_30 |= V_34 ;
break;
case 2 :
V_30 |= V_35 ;
break;
case 3 :
V_30 |= V_36 ;
break;
case 4 :
V_30 |= V_37 ;
break;
}
F_13 ( V_30 ) ;
}
}
static void F_14 ( unsigned int V_23 )
{
unsigned int V_30 , V_31 ;
if ( F_1 () == V_7 )
return;
if ( V_23 ) {
if ( V_23 > F_5 ( 190 ) )
V_23 = F_5 ( 190 ) ;
V_31 = F_12 ( F_4 () , V_23 ) ;
V_30 = F_6 ( V_32 ) & ~ V_38 ;
switch ( V_31 ) {
default:
case 3 :
V_30 |= V_39 ;
break;
case 4 :
V_30 |= V_40 ;
break;
case 6 :
V_30 |= V_41 ;
break;
case 8 :
V_30 |= V_42 ;
break;
}
F_13 ( V_30 ) ;
}
}
unsigned int F_15 ( void )
{
unsigned int V_30 ;
unsigned int V_43 ;
if ( F_1 () == V_7 )
return V_44 ;
V_30 = F_6 ( V_45 ) ;
V_30 |= V_46 ;
F_9 ( V_45 , V_30 ) ;
V_30 = F_6 ( V_47 ) & V_48 ;
switch ( V_30 ) {
case V_49 :
V_43 = V_50 ; break;
case V_51 :
V_43 = V_52 ; break;
case V_53 :
V_43 = V_54 ; break;
case V_55 :
V_43 = V_44 ; break;
default:
V_43 = 0 ;
break;
}
return V_43 ;
}
int F_16 ( struct V_56 * V_57 )
{
unsigned int V_30 ;
if ( V_57 -> V_58 != 0 )
V_57 -> V_58 = 0 ;
F_17 ( V_57 -> V_58 ) ;
V_30 = F_6 ( V_32 ) ;
V_30 |= ( V_59 | V_60 ) ;
F_13 ( V_30 ) ;
if ( F_1 () != V_7 ) {
V_30 = F_6 ( V_61 ) ;
V_30 |= ( V_62 | V_63 ) ;
F_9 ( V_61 , V_30 ) ;
} else {
#if F_18 ( V_64 ) || F_18 ( V_65 )
F_19 ( 0x88 , 0x3d4 ) ;
F_19 ( 0x06 , 0x3d5 ) ;
#endif
}
F_7 ( F_5 ( ( unsigned int ) V_57 -> V_66 ) ) ;
F_11 ( F_5 ( V_57 -> V_67 ) ) ;
F_14 ( F_5 ( V_57 -> V_68 ) ) ;
if ( V_57 -> V_69 == 1 ) {
V_30 = F_6 ( V_47 ) ;
V_30 &= ~ V_70 ;
F_9 ( V_47 , V_30 ) ;
V_30 |= V_70 ;
F_9 ( V_47 , V_30 ) ;
}
if ( V_57 -> V_71 == 1 ) {
F_20 ( 0 ) ;
V_30 = F_6 ( V_72 ) ;
V_30 &= ~ V_73 ;
F_9 ( V_72 , V_30 ) ;
V_30 = F_6 ( V_74 ) ;
V_30 &= ~ V_73 ;
F_9 ( V_74 , V_30 ) ;
V_30 = F_6 ( V_75 ) ;
V_30 &= ~ V_73 ;
F_9 ( V_75 , V_30 ) ;
V_30 = F_6 ( V_76 ) ;
V_30 |= V_77 ;
F_9 ( V_76 , V_30 ) ;
F_21 ( 0 ) ;
}
return 0 ;
}
unsigned int F_8 ( unsigned int V_78 , struct V_24 * V_25 )
{
int V_11 , V_10 , V_79 , V_80 ;
int V_81 ;
unsigned int V_82 , V_83 , V_84 , V_85 ;
unsigned int V_86 , V_87 ;
unsigned int V_88 , V_89 ;
const int V_90 = 3 ;
int V_91 = 6 ;
if ( F_1 () == V_7 ) {
return V_78 ;
}
V_89 = 0 ;
V_81 = ~ 0 ;
V_87 = V_78 / 1000 ;
V_86 = V_25 -> V_27 / 1000 ;
if ( V_25 -> V_28 == V_29 )
V_91 = 3 ;
for ( V_11 = 15 ; V_11 > 1 ; V_11 -- ) {
V_82 = V_11 * V_87 ;
V_83 = V_82 / V_86 ;
V_84 = V_82 % V_86 ;
V_85 = ( V_84 * 10000 / V_86 ) ;
for ( V_80 = V_91 ; V_80 >= 0 ; V_80 -- ) {
V_79 = F_22 ( V_80 ) ;
V_10 = V_83 * V_79 ;
V_10 += V_85 * V_79 / 10000 ;
V_10 += ( V_85 * V_79 % 10000 ) > 5000 ? 1 : 0 ;
if ( V_10 < 256 && V_10 > 0 ) {
unsigned int V_92 ;
V_88 = V_25 -> V_27 * V_10 / V_11 / V_79 ;
V_92 = abs ( V_88 - V_78 ) ;
if ( V_92 < V_81 ) {
V_25 -> V_10 = V_10 ;
V_25 -> V_11 = V_11 ;
V_25 -> V_13 = 0 ;
if ( V_80 > V_90 )
V_25 -> V_13 = V_80 - V_90 ;
V_25 -> V_12 = V_80 - V_25 -> V_13 ;
V_81 = V_92 ;
V_89 = V_88 ;
}
}
}
}
return V_89 ;
}
unsigned int F_10 ( struct V_24 * V_93 )
{
#ifndef F_23
unsigned int V_13 = V_93 -> V_13 ;
#endif
unsigned int V_12 = V_93 -> V_12 ;
unsigned int V_10 = V_93 -> V_10 ;
unsigned int V_11 = V_93 -> V_11 ;
unsigned int V_30 = 0 ;
V_30 = V_94 |
#ifndef F_23
( ( V_13 << V_21 ) & V_20 ) |
#endif
( ( V_12 << V_19 ) & V_18 ) |
( ( V_11 << V_95 ) & V_17 ) |
( ( V_10 << V_16 ) & V_15 ) ;
return V_30 ;
}
