void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 | V_4 |
V_5 | V_6 |
V_7 | V_8 |
V_9 , V_10 ) ;
( void ) F_3 ( V_10 ) ;
F_4 ( 1 ) ;
F_2 ( 0 , V_10 ) ;
F_5 () ;
F_2 ( F_3 ( V_11 ) | V_12 ,
V_11 ) ;
F_5 () ;
( void ) F_3 ( V_11 ) ;
F_4 ( 1 ) ;
F_2 ( F_3 ( V_11 ) & ~ V_12 ,
V_11 ) ;
( void ) F_3 ( V_11 ) ;
F_2 ( V_2 -> V_13 -> V_14 , V_15 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_16 )
{
T_1 V_17 = F_3 ( V_18 ) ;
unsigned long V_19 = V_20 + V_21 ;
while( V_17 < V_16 ) {
V_17 = F_3 ( V_18 ) ;
if ( F_7 ( V_20 , V_19 ) ) {
F_1 ( V_2 ) ;
return - V_22 ;
}
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 , T_1 * V_23 ,
unsigned V_16 )
{
int V_24 = 0 ;
int V_25 ;
unsigned V_26 ;
while ( V_16 > 0 ) {
V_26 = ( V_16 < 0x60 ) ? V_16 : 0x60 ;
V_16 -= V_26 ;
V_24 = F_6 ( V_2 , V_26 ) ;
if ( V_24 )
return V_24 ;
V_26 <<= 2 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 += 4 ) {
F_2 ( * V_23 ++ , V_27 + V_25 ) ;
}
( void ) F_3 ( V_27 + V_25 - 4 ) ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_28 , T_1 V_29 ,
T_1 V_30 , T_2 V_31 ,
T_2 V_32 , T_2 V_33 ,
T_2 V_34 , T_1 V_35 )
{
T_1 V_36 [ 10 ] ;
T_1 * V_37 ;
V_37 = V_36 ;
* V_37 ++ = V_38 ;
* V_37 ++ =
V_39 | V_30 | ( V_29 <<
V_40 ) ;
* V_37 ++ = V_28 ;
* V_37 ++ =
V_41 |
V_42 |
V_43 |
V_44 |
V_45 | V_46 | V_47 ;
* V_37 ++ = V_35 << V_48 ;
* V_37 ++ =
( V_31 << V_49 ) | ( V_32 <<
V_50 ) ;
* V_37 ++ =
( V_33 << V_51 ) | ( V_34 <<
V_52 ) ;
* V_37 ++ = V_53 ;
return F_8 ( V_2 , V_36 , V_37 - V_36 ) ;
}
static void F_10 ( struct V_54 * V_55 ,
const struct V_56 * V_57 )
{
struct V_58 * V_59 = V_55 -> V_60 ;
struct V_61 * V_62 = V_59 -> V_63 ;
struct V_64 * V_65 = V_62 -> V_66 . V_65 ;
struct V_67 * V_68 = V_59 -> V_69 . V_68 ;
struct V_1 * V_2 = V_65 -> V_70 ;
T_1 V_71 ;
T_1 V_72 ;
T_1 V_73 ;
if ( ! V_68 )
return;
V_71 = V_62 -> V_74 -> V_71 ;
V_72 = V_68 -> V_75 ;
switch ( V_68 -> V_76 ) {
case 8 :
V_73 = V_77 ;
break;
case 15 :
V_73 = V_78 ;
break;
case 16 :
V_73 = V_79 ;
break;
case 24 :
case 32 :
V_73 = V_80 ;
break;
default:
F_11 ( V_55 , V_57 ) ;
return;
}
F_9 ( V_2 ,
V_71 , V_72 , V_73 ,
V_57 -> V_81 , V_57 -> V_82 , V_57 -> V_83 , V_57 -> V_84 , V_57 -> V_85 ) ;
}
void F_12 ( struct V_54 * V_55 ,
const struct V_56 * V_86 )
{
if ( F_13 ( V_55 -> V_87 != V_88 ) )
return;
if ( 1 || ( V_55 -> V_89 & V_90 ) )
return F_11 ( V_55 , V_86 ) ;
F_10 ( V_55 , V_86 ) ;
}
static T_3 F_14 ( int V_91 , int V_92 )
{
if ( V_91 < 0 )
return ( V_92 < 0 ) ? V_93 :
V_94 ;
else
return ( V_92 < 0 ) ? V_95 :
V_43 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_96 , T_1 V_97 ,
T_1 V_98 , T_1 V_28 ,
T_1 V_29 , T_1 V_30 ,
T_2 V_99 , T_2 V_100 ,
T_2 V_31 , T_2 V_32 ,
T_2 V_33 , T_2 V_34 )
{
T_1 V_101 ;
T_1 V_36 [ 10 ] ;
T_1 * V_37 ;
T_1 V_102 ;
V_37 = V_36 ;
V_102 =
F_14 ( V_99 - V_31 , V_100 - V_32 ) ;
if ( V_102 == V_93 ||
V_102 == V_94 ) {
V_99 += V_33 - 1 ;
V_31 += V_33 - 1 ;
}
if ( V_102 == V_93 ||
V_102 == V_95 ) {
V_100 += V_34 - 1 ;
V_32 += V_34 - 1 ;
}
V_101 =
V_41 |
V_42 |
V_44 |
V_45 |
V_103 | V_104 | V_102 ;
* V_37 ++ = V_38 ;
* V_37 ++ =
V_39 | V_30 | ( V_29 <<
V_40 ) ;
* V_37 ++ = V_28 ;
* V_37 ++ =
V_105 | V_98 | ( V_97 <<
V_106 ) ;
* V_37 ++ = V_96 ;
* V_37 ++ =
V_107 | ( V_99 << V_108 ) |
( V_100 << V_109 ) ;
* V_37 ++ = V_101 ;
* V_37 ++ =
( V_31 << V_49 ) | ( V_32 <<
V_50 ) ;
* V_37 ++ =
( V_33 << V_51 ) | ( V_34 <<
V_52 ) ;
* V_37 ++ = V_53 ;
return F_8 ( V_2 , V_36 , V_37 - V_36 ) ;
}
static void F_16 ( struct V_54 * V_55 ,
const struct V_110 * V_111 )
{
struct V_58 * V_59 = V_55 -> V_60 ;
struct V_61 * V_62 = V_59 -> V_63 ;
struct V_64 * V_65 = V_62 -> V_66 . V_65 ;
struct V_67 * V_68 = V_59 -> V_69 . V_68 ;
struct V_1 * V_2 = V_65 -> V_70 ;
T_1 V_71 ;
T_1 V_72 ;
T_1 V_98 ;
T_1 V_30 ;
if ( ! V_68 )
return;
V_71 = V_62 -> V_74 -> V_71 ;
V_72 = V_68 -> V_75 ;
switch ( V_68 -> V_76 ) {
case 8 :
V_98 = V_112 ;
V_30 = V_77 ;
break;
case 15 :
V_98 = V_113 ;
V_30 = V_78 ;
break;
case 16 :
V_98 = V_114 ;
V_30 = V_79 ;
break;
case 24 :
case 32 :
V_98 = V_115 ;
V_30 = V_80 ;
break;
default:
F_17 ( V_55 , V_111 ) ;
return;
}
F_15 ( V_2 ,
V_71 , V_72 , V_98 ,
V_71 , V_72 , V_30 ,
V_111 -> V_116 , V_111 -> V_117 , V_111 -> V_81 , V_111 -> V_82 , V_111 -> V_83 , V_111 -> V_84 ) ;
}
void F_18 ( struct V_54 * V_55 ,
const struct V_110 * V_118 )
{
if ( F_13 ( V_55 -> V_87 != V_88 ) )
return;
if ( V_55 -> V_89 & V_90 )
return F_17 ( V_55 , V_118 ) ;
F_16 ( V_55 , V_118 ) ;
}
void F_19 ( struct V_54 * V_55 , const struct V_119 * V_120 )
{
F_20 ( V_55 , V_120 ) ;
}
int F_21 ( struct V_54 * V_55 )
{
struct V_58 * V_59 = V_55 -> V_60 ;
struct V_61 * V_62 = V_59 -> V_63 ;
struct V_64 * V_65 = V_62 -> V_66 . V_65 ;
struct V_1 * V_2 = V_65 -> V_70 ;
unsigned long V_121 = V_20 + V_122 ;
int V_123 = 0 ;
#if 0
u32 test[2] = {
PSB_2D_FENCE_BH,
};
psbfb_2d_submit(dev_priv, test, 1);
#endif
if ( ( F_3 ( V_18 ) == V_124 ) &&
( ( F_3 ( V_125 ) & V_126 ) == 0 ) )
goto V_127;
do {
V_123 = ( F_3 ( V_18 ) != V_124 ) ;
F_22 () ;
} while ( V_123 && ! F_23 ( V_20 , V_121 ) );
if ( V_123 )
V_123 = ( F_3 ( V_18 ) != V_124 ) ;
if ( V_123 )
goto V_127;
do {
V_123 = ( ( F_3 ( V_125 ) &
V_126 ) != 0 ) ;
F_22 () ;
} while ( V_123 && ! F_23 ( V_20 , V_121 ) );
if ( V_123 )
V_123 = ( ( F_3 ( V_125 ) &
V_126 ) != 0 ) ;
V_127:
return ( V_123 ) ? - V_128 : 0 ;
}
