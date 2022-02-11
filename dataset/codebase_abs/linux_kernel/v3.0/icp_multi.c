static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static int F_5 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 , V_10 ;
#ifdef F_6
F_7 ( V_11 L_1 ) ;
#endif
V_12 -> V_13 &= ~ V_14 ;
F_8 ( V_12 -> V_13 , V_12 -> V_15 + V_16 ) ;
V_12 -> V_17 |= V_14 ;
F_8 ( V_12 -> V_17 , V_12 -> V_15 + V_18 ) ;
F_9 ( V_3 , V_5 , & V_7 -> V_19 , 1 ) ;
#ifdef F_6
F_7 ( V_11 L_2 ,
F_10 ( V_12 -> V_15 + V_20 ) ,
V_12 -> V_15 + V_20 ) ;
#endif
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ ) {
V_12 -> V_21 |= V_22 ;
F_8 ( V_12 -> V_21 ,
V_12 -> V_15 + V_20 ) ;
V_12 -> V_21 &= ~ V_22 ;
#ifdef F_6
F_7 ( V_11 L_3 , V_9 ,
F_10 ( V_12 -> V_15 + V_20 ) ) ;
#endif
F_11 ( 1 ) ;
#ifdef F_6
F_7 ( V_11 L_4 , V_9 ,
F_10 ( V_12 -> V_15 + V_20 ) ) ;
#endif
V_10 = 100 ;
while ( V_10 -- ) {
if ( ! ( F_10 ( V_12 -> V_15 +
V_20 ) & V_23 ) )
goto V_24;
#ifdef F_6
if ( ! ( V_10 % 10 ) )
F_7 ( V_11
L_5 , V_9 ,
V_10 ,
F_10 ( V_12 -> V_15 +
V_20 ) ) ;
#endif
F_11 ( 1 ) ;
}
F_12 ( V_3 , L_6 ) ;
V_12 -> V_13 &= ~ V_14 ;
F_8 ( V_12 -> V_13 , V_12 -> V_15 + V_16 ) ;
V_12 -> V_17 |= V_14 ;
F_8 ( V_12 -> V_17 ,
V_12 -> V_15 + V_18 ) ;
V_8 [ V_9 ] = 0 ;
#ifdef F_6
F_7 ( V_11
L_7 ,
V_9 ) ;
#endif
return - V_25 ;
V_24:
V_8 [ V_9 ] =
( F_10 ( V_12 -> V_15 + V_26 ) >> 4 ) & 0x0fff ;
}
V_12 -> V_13 &= ~ V_14 ;
F_8 ( V_12 -> V_13 , V_12 -> V_15 + V_16 ) ;
V_12 -> V_17 |= V_14 ;
F_8 ( V_12 -> V_17 , V_12 -> V_15 + V_18 ) ;
#ifdef F_6
F_7 ( V_11
L_7 , V_9 ) ;
#endif
return V_9 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 , V_27 , V_28 , V_10 ;
#ifdef F_6
F_7 ( V_11
L_8 ) ;
#endif
V_12 -> V_13 &= ~ V_29 ;
F_8 ( V_12 -> V_13 , V_12 -> V_15 + V_16 ) ;
V_12 -> V_17 |= V_29 ;
F_8 ( V_12 -> V_17 , V_12 -> V_15 + V_18 ) ;
V_27 = F_14 ( V_7 -> V_19 ) ;
V_28 = F_15 ( V_7 -> V_19 ) ;
V_12 -> V_30 &= 0xfccf ;
V_12 -> V_30 |= V_31 -> V_32 [ V_28 ] ;
V_12 -> V_30 |= ( V_27 << 8 ) ;
F_8 ( V_12 -> V_30 , V_12 -> V_15 + V_33 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ ) {
V_10 = 100 ;
while ( V_10 -- ) {
if ( ! ( F_10 ( V_12 -> V_15 +
V_33 ) & V_34 ) )
goto V_35;
#ifdef F_6
if ( ! ( V_10 % 10 ) )
F_7 ( V_11
L_9 , V_9 ,
V_10 ,
F_10 ( V_12 -> V_15 +
V_33 ) ) ;
#endif
F_11 ( 1 ) ;
}
F_12 ( V_3 , L_10 ) ;
V_12 -> V_13 &= ~ V_29 ;
F_8 ( V_12 -> V_13 , V_12 -> V_15 + V_16 ) ;
V_12 -> V_17 |= V_29 ;
F_8 ( V_12 -> V_17 ,
V_12 -> V_15 + V_18 ) ;
V_12 -> V_36 [ V_27 ] = 0 ;
#ifdef F_6
F_7 ( V_11
L_11 ,
V_9 ) ;
#endif
return - V_25 ;
V_35:
F_8 ( V_8 [ V_9 ] , V_12 -> V_15 + V_37 ) ;
V_12 -> V_30 |= V_38 ;
F_8 ( V_12 -> V_30 ,
V_12 -> V_15 + V_33 ) ;
V_12 -> V_30 &= ~ V_38 ;
V_12 -> V_36 [ V_27 ] = V_8 [ V_9 ] ;
}
#ifdef F_6
F_7 ( V_11
L_11 , V_9 ) ;
#endif
return V_9 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
int V_9 , V_27 ;
V_27 = F_14 ( V_7 -> V_19 ) ;
for ( V_9 = 0 ; V_9 < V_7 -> V_9 ; V_9 ++ )
V_8 [ V_9 ] = V_12 -> V_36 [ V_27 ] ;
return V_9 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
V_8 [ 1 ] = F_10 ( V_12 -> V_15 + V_39 ) ;
return 2 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
#ifdef F_6
F_7 ( V_11 L_12 ) ;
#endif
if ( V_8 [ 0 ] ) {
V_5 -> V_40 &= ~ V_8 [ 0 ] ;
V_5 -> V_40 |= ( V_8 [ 0 ] & V_8 [ 1 ] ) ;
F_7 ( V_11 L_13 , V_5 -> V_40 ) ;
F_8 ( V_5 -> V_40 , V_12 -> V_15 + V_41 ) ;
}
V_8 [ 1 ] = F_10 ( V_12 -> V_15 + V_39 ) ;
#ifdef F_6
F_7 ( V_11 L_14 ) ;
#endif
return 2 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 , unsigned int * V_8 )
{
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 ,
unsigned int * V_8 )
{
return 0 ;
}
static T_3 F_21 ( int V_42 , void * V_43 )
{
struct V_2 * V_3 = V_43 ;
int V_44 ;
#ifdef F_6
F_7 ( V_11
L_15 ,
V_42 ) ;
#endif
V_44 = F_10 ( V_12 -> V_15 + V_18 ) & V_45 ;
if ( ! V_44 )
return V_46 ;
#ifdef F_6
F_7 ( V_11
L_16 ,
F_10 ( V_12 -> V_15 + V_18 ) ) ;
#endif
switch ( V_44 ) {
case V_14 :
break;
case V_29 :
break;
case V_47 :
break;
case V_48 :
break;
case V_49 :
break;
case V_50 :
break;
case V_51 :
break;
case V_52 :
break;
default:
break;
}
#ifdef F_6
F_7 ( V_11
L_17 ) ;
#endif
return V_53 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
unsigned int * V_54 , unsigned int V_55 )
{
unsigned int V_56 , V_28 , V_57 ;
unsigned int V_58 ;
#ifdef F_6
F_7 ( V_11
L_18 , V_55 ) ;
#endif
V_12 -> V_59 = V_55 ;
V_12 -> V_60 = 0 ;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
V_57 = F_14 ( V_54 [ V_56 ] ) ;
if ( F_22 ( V_54 [ V_56 ] ) == V_61 ) {
V_58 = 1 ;
V_57 &= 0x0007 ;
} else {
V_58 = 0 ;
V_57 &= 0x000f ;
}
V_12 -> V_21 &= 0xf00f ;
if ( V_58 ) {
V_12 -> V_21 |= ( V_57 << 9 ) ;
V_12 -> V_21 |= V_62 ;
} else
V_12 -> V_21 |= ( V_57 << 8 ) ;
V_28 = V_31 -> V_32 [ F_15 ( V_54 [ V_56 ] ) ] ;
V_12 -> V_21 |= V_28 ;
F_8 ( V_12 -> V_21 ,
V_12 -> V_15 + V_20 ) ;
#ifdef F_6
F_7 ( V_11
L_19 , V_56 , V_57 , V_28 ,
V_12 -> V_63 [ V_56 ] ) ;
#endif
}
}
static int F_23 ( struct V_2 * V_3 )
{
unsigned int V_56 ;
#ifdef F_6
F_7 ( V_11
L_20 ) ;
#endif
F_8 ( 0 , V_12 -> V_15 + V_16 ) ;
F_8 ( 0x00ff , V_12 -> V_15 + V_18 ) ;
if ( V_31 -> V_64 )
for ( V_56 = 0 ; V_56 < V_31 -> V_64 ; V_56 ++ ) {
V_12 -> V_30 &= 0xfcce ;
V_12 -> V_30 |= ( V_56 << 8 ) ;
F_8 ( 0 , V_12 -> V_15 + V_37 ) ;
V_12 -> V_30 |= V_38 ;
F_8 ( V_12 -> V_30 ,
V_12 -> V_15 + V_33 ) ;
F_11 ( 1 ) ;
}
F_8 ( 0 , V_12 -> V_15 + V_41 ) ;
#ifdef F_6
F_7 ( V_11
L_21 ) ;
#endif
return 0 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_65 * V_66 )
{
struct V_4 * V_5 ;
int V_67 , V_68 , V_69 ;
unsigned int V_42 ;
struct V_70 * V_71 = NULL ;
T_4 V_15 [ 5 ] , V_72 ;
unsigned char V_73 , V_74 , V_75 ;
F_7 ( V_76
L_22 ) ;
V_67 = F_25 ( V_3 , sizeof( struct V_77 ) ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_78 ++ == 0 ) {
F_26 ( V_79 ,
#ifdef F_6
1
#else
0
#endif
) ;
}
F_7 ( V_76
L_23 , V_3 -> V_80 ,
V_31 -> V_81 ) ;
V_71 = F_27 ( V_79 ,
V_31 -> V_82 , V_66 -> V_83 [ 0 ] ,
V_66 -> V_83 [ 1 ] ) ;
if ( V_71 == NULL )
return - V_84 ;
V_12 -> V_71 = V_71 ;
if ( ( F_28 ( V_71 , & V_73 , & V_74 , & V_75 , & V_15 [ 0 ] ,
& V_42 ) ) < 0 ) {
F_7 ( V_76 L_24 ) ;
return - V_84 ;
}
V_72 = V_15 [ 2 ] ;
V_12 -> V_85 = V_72 ;
F_7 ( V_76
L_25 , V_73 , V_74 , V_75 ,
( unsigned long long ) V_72 ) ;
V_12 -> V_15 = F_29 ( V_72 , V_86 ) ;
if ( V_12 -> V_15 == NULL ) {
F_7 ( V_76 L_26 ) ;
return - V_87 ;
}
#ifdef F_6
F_7 ( V_11
L_27 , ( unsigned long long ) V_72 ,
V_12 -> V_15 ) ;
#endif
V_3 -> V_88 = V_31 -> V_81 ;
V_69 = 0 ;
if ( V_31 -> V_89 )
V_69 ++ ;
if ( V_31 -> V_64 )
V_69 ++ ;
if ( V_31 -> V_90 )
V_69 ++ ;
if ( V_31 -> V_91 )
V_69 ++ ;
if ( V_31 -> V_92 )
V_69 ++ ;
V_67 = F_30 ( V_3 , V_69 ) ;
if ( V_67 < 0 )
return V_67 ;
F_23 ( V_3 ) ;
if ( V_31 -> V_93 ) {
if ( V_42 ) {
if ( F_31 ( V_42 , F_21 ,
V_94 , L_28 , V_3 ) ) {
F_7 ( V_76
L_29 ,
V_42 ) ;
V_42 = 0 ;
} else
F_7 ( V_76 L_30 , V_42 ) ;
} else
F_7 ( V_76 L_31 ) ;
} else
V_42 = 0 ;
V_3 -> V_42 = V_42 ;
F_7 ( V_76 L_32 ) ;
V_68 = 0 ;
if ( V_31 -> V_89 ) {
V_5 = V_3 -> V_95 + V_68 ;
V_3 -> V_96 = V_5 ;
V_5 -> type = V_97 ;
V_5 -> V_98 = V_99 | V_100 | V_101 ;
if ( V_31 -> V_102 )
V_5 -> V_98 |= V_103 ;
V_5 -> V_55 = V_31 -> V_89 ;
V_5 -> V_104 = V_31 -> V_105 ;
V_5 -> V_106 = V_31 -> V_89 ;
V_5 -> V_107 = V_31 -> V_108 ;
V_5 -> V_109 = F_5 ;
V_68 ++ ;
}
if ( V_31 -> V_64 ) {
V_5 = V_3 -> V_95 + V_68 ;
V_5 -> type = V_110 ;
V_5 -> V_98 = V_111 | V_101 | V_100 ;
V_5 -> V_55 = V_31 -> V_64 ;
V_5 -> V_104 = V_31 -> V_112 ;
V_5 -> V_106 = V_31 -> V_64 ;
V_5 -> V_107 = V_31 -> V_113 ;
V_5 -> V_114 = F_13 ;
V_5 -> V_109 = F_16 ;
V_68 ++ ;
}
if ( V_31 -> V_90 ) {
V_5 = V_3 -> V_95 + V_68 ;
V_5 -> type = V_115 ;
V_5 -> V_98 = V_99 ;
V_5 -> V_55 = V_31 -> V_90 ;
V_5 -> V_104 = 1 ;
V_5 -> V_106 = V_31 -> V_90 ;
V_5 -> V_107 = & V_116 ;
V_5 -> V_117 = 0 ;
V_5 -> V_118 = F_17 ;
V_68 ++ ;
}
if ( V_31 -> V_91 ) {
V_5 = V_3 -> V_95 + V_68 ;
V_5 -> type = V_119 ;
V_5 -> V_98 = V_111 | V_99 ;
V_5 -> V_55 = V_31 -> V_91 ;
V_5 -> V_104 = 1 ;
V_5 -> V_106 = V_31 -> V_91 ;
V_5 -> V_107 = & V_116 ;
V_5 -> V_117 = ( 1 << V_31 -> V_91 ) - 1 ;
V_5 -> V_40 = 0 ;
V_5 -> V_118 = F_18 ;
V_68 ++ ;
}
if ( V_31 -> V_92 ) {
V_5 = V_3 -> V_95 + V_68 ;
V_5 -> type = V_120 ;
V_5 -> V_98 = V_111 | V_101 | V_100 ;
V_5 -> V_55 = V_31 -> V_92 ;
V_5 -> V_104 = 0xffff ;
V_5 -> V_106 = V_31 -> V_92 ;
V_5 -> V_40 = 0 ;
V_5 -> V_109 = F_19 ;
V_5 -> V_114 = F_20 ;
V_68 ++ ;
}
V_12 -> V_121 = 1 ;
#ifdef F_6
F_7 ( V_11 L_33 ) ;
#endif
return 0 ;
}
static int F_32 ( struct V_2 * V_3 )
{
if ( V_3 -> V_122 )
if ( V_12 -> V_121 )
F_23 ( V_3 ) ;
if ( V_3 -> V_42 )
F_33 ( V_3 -> V_42 , V_3 ) ;
if ( V_3 -> V_122 && V_12 -> V_15 )
F_34 ( V_12 -> V_15 ) ;
if ( V_3 -> V_122 && V_12 -> V_71 )
F_35 ( V_12 -> V_71 ) ;
if ( -- V_78 == 0 )
F_36 ( V_79 ) ;
return 0 ;
}
