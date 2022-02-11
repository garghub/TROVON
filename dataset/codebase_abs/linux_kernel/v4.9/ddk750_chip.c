T_1 F_1 ( void )
{
unsigned short V_1 ;
char V_2 ;
T_1 V_3 ;
V_1 = V_4 ;
V_2 = V_5 ;
if ( V_1 == 0x718 )
V_3 = V_6 ;
else if ( V_1 == 0x750 ) {
V_3 = V_7 ;
if ( V_2 == V_8 )
V_3 = V_9 ;
} else
V_3 = V_10 ;
return V_3 ;
}
static unsigned int F_2 ( void )
{
unsigned int V_11 ;
unsigned int V_12 , V_13 , V_14 , V_15 ;
if ( F_1 () == V_9 )
return F_3 ( 130 ) ;
V_11 = F_4 ( V_16 ) ;
V_12 = ( V_11 & V_17 ) >> V_18 ;
V_13 = ( V_11 & V_19 ) >> V_18 ;
V_14 = ( V_11 & V_20 ) >> V_21 ;
V_15 = ( V_11 & V_22 ) >> V_23 ;
return V_24 * V_12 / V_13 / ( 1 << V_14 ) / ( 1 << V_15 ) ;
}
static void F_5 ( unsigned int V_25 )
{
T_2 V_26 ;
unsigned int V_27 ;
if ( F_1 () == V_9 )
return;
if ( V_25 ) {
V_26 . V_28 = V_24 ;
V_26 . V_29 = V_30 ;
V_27 = F_6 ( V_25 , & V_26 ) ;
F_7 ( V_16 , F_8 ( & V_26 ) ) ;
}
}
static void F_9 ( unsigned int V_25 )
{
unsigned int V_31 , V_32 ;
if ( F_1 () == V_9 )
return;
if ( V_25 ) {
if ( V_25 > F_3 ( 336 ) )
V_25 = F_3 ( 336 ) ;
V_32 = F_10 ( F_2 () , V_25 ) ;
V_31 = F_4 ( V_33 ) & ~ V_34 ;
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
F_11 ( V_31 ) ;
}
}
static void F_12 ( unsigned int V_25 )
{
unsigned int V_31 , V_32 ;
if ( F_1 () == V_9 )
return;
if ( V_25 ) {
if ( V_25 > F_3 ( 190 ) )
V_25 = F_3 ( 190 ) ;
V_32 = F_10 ( F_2 () , V_25 ) ;
V_31 = F_4 ( V_33 ) & ~ V_39 ;
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
F_11 ( V_31 ) ;
}
}
unsigned int F_13 ( void )
{
unsigned int V_31 ;
unsigned int V_44 ;
if ( F_1 () == V_9 )
return V_45 ;
V_31 = F_4 ( V_46 ) ;
V_31 |= V_47 ;
F_7 ( V_46 , V_31 ) ;
V_31 = F_4 ( V_48 ) & V_49 ;
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
int F_14 ( T_3 * V_57 )
{
unsigned int V_31 ;
if ( V_57 -> V_58 != 0 )
V_57 -> V_58 = 0 ;
F_15 ( V_57 -> V_58 ) ;
V_31 = F_4 ( V_33 ) ;
V_31 |= ( V_59 | V_60 ) ;
F_11 ( V_31 ) ;
if ( F_1 () != V_9 ) {
V_31 = F_4 ( V_61 ) ;
V_31 |= ( V_62 | V_63 ) ;
F_7 ( V_61 , V_31 ) ;
} else {
#if F_16 ( V_64 ) || F_16 ( V_65 )
F_17 ( 0x88 , 0x3d4 ) ;
F_17 ( 0x06 , 0x3d5 ) ;
#endif
}
F_5 ( F_3 ( ( unsigned int ) V_57 -> V_66 ) ) ;
F_9 ( F_3 ( V_57 -> V_67 ) ) ;
F_12 ( F_3 ( V_57 -> V_68 ) ) ;
if ( V_57 -> V_69 == 1 ) {
V_31 = F_4 ( V_48 ) ;
V_31 &= ~ V_70 ;
F_7 ( V_48 , V_31 ) ;
V_31 |= V_70 ;
F_7 ( V_48 , V_31 ) ;
}
if ( V_57 -> V_71 == 1 ) {
F_18 ( 0 ) ;
V_31 = F_4 ( V_72 ) ;
V_31 &= ~ V_73 ;
F_7 ( V_72 , V_31 ) ;
V_31 = F_4 ( V_74 ) ;
V_31 &= ~ V_73 ;
F_7 ( V_74 , V_31 ) ;
V_31 = F_4 ( V_75 ) ;
V_31 &= ~ V_73 ;
F_7 ( V_75 , V_31 ) ;
V_31 = F_4 ( V_76 ) ;
V_31 |= V_77 ;
F_7 ( V_76 , V_31 ) ;
F_19 ( 0 ) ;
}
return 0 ;
}
unsigned int F_6 ( unsigned int V_78 , T_2 * V_26 )
{
int V_13 , V_12 , V_79 , V_80 ;
int V_81 ;
unsigned int V_82 , V_83 , V_84 , V_85 ;
unsigned int V_86 , V_87 ;
unsigned int V_88 , V_89 ;
const int V_90 = 3 ;
int V_91 = 6 ;
if ( F_1 () == V_9 ) {
return V_78 ;
}
V_89 = 0 ;
V_81 = ~ 0 ;
V_87 = V_78 / 1000 ;
V_86 = V_26 -> V_28 / 1000 ;
if ( V_26 -> V_29 == V_30 )
V_91 = 3 ;
for ( V_13 = 15 ; V_13 > 1 ; V_13 -- ) {
V_82 = V_13 * V_87 ;
V_83 = V_82 / V_86 ;
V_84 = V_82 % V_86 ;
V_85 = ( V_84 * 10000 / V_86 ) ;
for ( V_80 = V_91 ; V_80 >= 0 ; V_80 -- ) {
V_79 = F_20 ( V_80 ) ;
V_12 = V_83 * V_79 ;
V_12 += V_85 * V_79 / 10000 ;
V_12 += ( V_85 * V_79 % 10000 ) > 5000 ? 1 : 0 ;
if ( V_12 < 256 && V_12 > 0 ) {
unsigned int V_92 ;
V_88 = V_26 -> V_28 * V_12 / V_13 / V_79 ;
V_92 = abs ( V_88 - V_78 ) ;
if ( V_92 < V_81 ) {
V_26 -> V_12 = V_12 ;
V_26 -> V_13 = V_13 ;
V_26 -> V_15 = 0 ;
if ( V_80 > V_90 )
V_26 -> V_15 = V_80 - V_90 ;
V_26 -> V_14 = V_80 - V_26 -> V_15 ;
V_81 = V_92 ;
V_89 = V_88 ;
}
}
}
}
return V_89 ;
}
unsigned int F_8 ( T_2 * V_93 )
{
#ifndef F_21
unsigned int V_15 = V_93 -> V_15 ;
#endif
unsigned int V_14 = V_93 -> V_14 ;
unsigned int V_12 = V_93 -> V_12 ;
unsigned int V_13 = V_93 -> V_13 ;
unsigned int V_31 = 0 ;
V_31 = V_94 |
#ifndef F_21
( ( V_15 << V_23 ) & V_22 ) |
#endif
( ( V_14 << V_21 ) & V_20 ) |
( ( V_13 << V_95 ) & V_19 ) |
( ( V_12 << V_18 ) & V_17 ) ;
return V_31 ;
}
