static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 , unsigned int V_6 )
{
unsigned int V_7 , V_8 , V_9 ;
unsigned int V_10 ;
#ifdef F_2
F_3 ( V_11
L_1 , V_6 ) ;
#endif
V_12 -> V_13 = V_6 ;
V_12 -> V_14 = 0 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
V_9 = F_4 ( V_5 [ V_7 ] ) ;
if ( F_5 ( V_5 [ V_7 ] ) == V_15 ) {
V_10 = 1 ;
V_9 &= 0x0007 ;
} else {
V_10 = 0 ;
V_9 &= 0x000f ;
}
V_12 -> V_16 &= 0xf00f ;
if ( V_10 ) {
V_12 -> V_16 |= ( V_9 << 9 ) ;
V_12 -> V_16 |= V_17 ;
} else
V_12 -> V_16 |= ( V_9 << 8 ) ;
V_8 = V_18 -> V_19 [ F_6 ( V_5 [ V_7 ] ) ] ;
V_12 -> V_16 |= V_8 ;
F_7 ( V_12 -> V_16 ,
V_12 -> V_20 + V_21 ) ;
#ifdef F_2
F_3 ( V_11
L_2 , V_7 , V_9 , V_8 ,
V_12 -> V_22 [ V_7 ] ) ;
#endif
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_26 , V_27 ;
#ifdef F_2
F_3 ( V_11 L_3 ) ;
#endif
V_12 -> V_28 &= ~ V_29 ;
F_7 ( V_12 -> V_28 , V_12 -> V_20 + V_30 ) ;
V_12 -> V_31 |= V_29 ;
F_7 ( V_12 -> V_31 , V_12 -> V_20 + V_32 ) ;
F_1 ( V_2 , V_4 , & V_24 -> V_33 , 1 ) ;
#ifdef F_2
F_3 ( V_11 L_4 ,
F_9 ( V_12 -> V_20 + V_21 ) ,
V_12 -> V_20 + V_21 ) ;
#endif
for ( V_26 = 0 ; V_26 < V_24 -> V_26 ; V_26 ++ ) {
V_12 -> V_16 |= V_34 ;
F_7 ( V_12 -> V_16 ,
V_12 -> V_20 + V_21 ) ;
V_12 -> V_16 &= ~ V_34 ;
#ifdef F_2
F_3 ( V_11 L_5 , V_26 ,
F_9 ( V_12 -> V_20 + V_21 ) ) ;
#endif
F_10 ( 1 ) ;
#ifdef F_2
F_3 ( V_11 L_6 , V_26 ,
F_9 ( V_12 -> V_20 + V_21 ) ) ;
#endif
V_27 = 100 ;
while ( V_27 -- ) {
if ( ! ( F_9 ( V_12 -> V_20 +
V_21 ) & V_35 ) )
goto V_36;
#ifdef F_2
if ( ! ( V_27 % 10 ) )
F_3 ( V_11
L_7 , V_26 ,
V_27 ,
F_9 ( V_12 -> V_20 +
V_21 ) ) ;
#endif
F_10 ( 1 ) ;
}
F_11 ( V_2 , L_8 ) ;
V_12 -> V_28 &= ~ V_29 ;
F_7 ( V_12 -> V_28 , V_12 -> V_20 + V_30 ) ;
V_12 -> V_31 |= V_29 ;
F_7 ( V_12 -> V_31 ,
V_12 -> V_20 + V_32 ) ;
V_25 [ V_26 ] = 0 ;
#ifdef F_2
F_3 ( V_11
L_9 ,
V_26 ) ;
#endif
return - V_37 ;
V_36:
V_25 [ V_26 ] =
( F_9 ( V_12 -> V_20 + V_38 ) >> 4 ) & 0x0fff ;
}
V_12 -> V_28 &= ~ V_29 ;
F_7 ( V_12 -> V_28 , V_12 -> V_20 + V_30 ) ;
V_12 -> V_31 |= V_29 ;
F_7 ( V_12 -> V_31 , V_12 -> V_20 + V_32 ) ;
#ifdef F_2
F_3 ( V_11
L_9 , V_26 ) ;
#endif
return V_26 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_26 , V_39 , V_8 , V_27 ;
#ifdef F_2
F_3 ( V_11
L_10 ) ;
#endif
V_12 -> V_28 &= ~ V_40 ;
F_7 ( V_12 -> V_28 , V_12 -> V_20 + V_30 ) ;
V_12 -> V_31 |= V_40 ;
F_7 ( V_12 -> V_31 , V_12 -> V_20 + V_32 ) ;
V_39 = F_4 ( V_24 -> V_33 ) ;
V_8 = F_6 ( V_24 -> V_33 ) ;
V_12 -> V_41 &= 0xfccf ;
V_12 -> V_41 |= V_18 -> V_19 [ V_8 ] ;
V_12 -> V_41 |= ( V_39 << 8 ) ;
F_7 ( V_12 -> V_41 , V_12 -> V_20 + V_42 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_26 ; V_26 ++ ) {
V_27 = 100 ;
while ( V_27 -- ) {
if ( ! ( F_9 ( V_12 -> V_20 +
V_42 ) & V_43 ) )
goto V_44;
#ifdef F_2
if ( ! ( V_27 % 10 ) )
F_3 ( V_11
L_11 , V_26 ,
V_27 ,
F_9 ( V_12 -> V_20 +
V_42 ) ) ;
#endif
F_10 ( 1 ) ;
}
F_11 ( V_2 , L_12 ) ;
V_12 -> V_28 &= ~ V_40 ;
F_7 ( V_12 -> V_28 , V_12 -> V_20 + V_30 ) ;
V_12 -> V_31 |= V_40 ;
F_7 ( V_12 -> V_31 ,
V_12 -> V_20 + V_32 ) ;
V_12 -> V_45 [ V_39 ] = 0 ;
#ifdef F_2
F_3 ( V_11
L_13 ,
V_26 ) ;
#endif
return - V_37 ;
V_44:
F_7 ( V_25 [ V_26 ] , V_12 -> V_20 + V_46 ) ;
V_12 -> V_41 |= V_47 ;
F_7 ( V_12 -> V_41 ,
V_12 -> V_20 + V_42 ) ;
V_12 -> V_41 &= ~ V_47 ;
V_12 -> V_45 [ V_39 ] = V_25 [ V_26 ] ;
}
#ifdef F_2
F_3 ( V_11
L_13 , V_26 ) ;
#endif
return V_26 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
int V_26 , V_39 ;
V_39 = F_4 ( V_24 -> V_33 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_26 ; V_26 ++ )
V_25 [ V_26 ] = V_12 -> V_45 [ V_39 ] ;
return V_26 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
V_25 [ 1 ] = F_9 ( V_12 -> V_20 + V_48 ) ;
return 2 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
#ifdef F_2
F_3 ( V_11 L_14 ) ;
#endif
if ( V_25 [ 0 ] ) {
V_4 -> V_49 &= ~ V_25 [ 0 ] ;
V_4 -> V_49 |= ( V_25 [ 0 ] & V_25 [ 1 ] ) ;
F_3 ( V_11 L_15 , V_4 -> V_49 ) ;
F_7 ( V_4 -> V_49 , V_12 -> V_20 + V_50 ) ;
}
V_25 [ 1 ] = F_9 ( V_12 -> V_20 + V_48 ) ;
#ifdef F_2
F_3 ( V_11 L_16 ) ;
#endif
return 2 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_23 * V_24 , unsigned int * V_25 )
{
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_23 * V_24 ,
unsigned int * V_25 )
{
return 0 ;
}
static T_1 F_18 ( int V_51 , void * V_52 )
{
struct V_1 * V_2 = V_52 ;
int V_53 ;
#ifdef F_2
F_3 ( V_11
L_17 ,
V_51 ) ;
#endif
V_53 = F_9 ( V_12 -> V_20 + V_32 ) & V_54 ;
if ( ! V_53 )
return V_55 ;
#ifdef F_2
F_3 ( V_11
L_18 ,
F_9 ( V_12 -> V_20 + V_32 ) ) ;
#endif
switch ( V_53 ) {
case V_29 :
break;
case V_40 :
break;
case V_56 :
break;
case V_57 :
break;
case V_58 :
break;
case V_59 :
break;
case V_60 :
break;
case V_61 :
break;
default:
break;
}
#ifdef F_2
F_3 ( V_11
L_19 ) ;
#endif
return V_62 ;
}
static int F_19 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
#ifdef F_2
F_3 ( V_11
L_20 ) ;
#endif
F_7 ( 0 , V_12 -> V_20 + V_30 ) ;
F_7 ( 0x00ff , V_12 -> V_20 + V_32 ) ;
if ( V_18 -> V_63 )
for ( V_7 = 0 ; V_7 < V_18 -> V_63 ; V_7 ++ ) {
V_12 -> V_41 &= 0xfcce ;
V_12 -> V_41 |= ( V_7 << 8 ) ;
F_7 ( 0 , V_12 -> V_20 + V_46 ) ;
V_12 -> V_41 |= V_47 ;
F_7 ( V_12 -> V_41 ,
V_12 -> V_20 + V_42 ) ;
F_10 ( 1 ) ;
}
F_7 ( 0 , V_12 -> V_20 + V_50 ) ;
#ifdef F_2
F_3 ( V_11
L_21 ) ;
#endif
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_3 * V_4 ;
int V_66 , V_67 , V_68 ;
unsigned int V_51 ;
struct V_69 * V_70 = NULL ;
T_2 V_20 [ 5 ] , V_71 ;
unsigned char V_72 , V_73 , V_74 ;
F_3 ( V_75
L_22 ) ;
V_66 = F_21 ( V_2 , sizeof( struct V_76 ) ) ;
if ( V_66 < 0 )
return V_66 ;
if ( V_77 ++ == 0 ) {
F_22 ( V_78 ,
#ifdef F_2
1
#else
0
#endif
) ;
}
F_3 ( V_75
L_23 , V_2 -> V_79 ,
V_18 -> V_80 ) ;
V_70 = F_23 ( V_78 ,
V_18 -> V_81 , V_65 -> V_82 [ 0 ] ,
V_65 -> V_82 [ 1 ] ) ;
if ( V_70 == NULL )
return - V_83 ;
V_12 -> V_70 = V_70 ;
if ( ( F_24 ( V_70 , & V_72 , & V_73 , & V_74 , & V_20 [ 0 ] ,
& V_51 ) ) < 0 ) {
F_3 ( V_75 L_24 ) ;
return - V_83 ;
}
V_71 = V_20 [ 2 ] ;
V_12 -> V_84 = V_71 ;
F_3 ( V_75
L_25 , V_72 , V_73 , V_74 ,
( unsigned long long ) V_71 ) ;
V_12 -> V_20 = F_25 ( V_71 , V_85 ) ;
if ( V_12 -> V_20 == NULL ) {
F_3 ( V_75 L_26 ) ;
return - V_86 ;
}
#ifdef F_2
F_3 ( V_11
L_27 , ( unsigned long long ) V_71 ,
V_12 -> V_20 ) ;
#endif
V_2 -> V_87 = V_18 -> V_80 ;
V_68 = 0 ;
if ( V_18 -> V_88 )
V_68 ++ ;
if ( V_18 -> V_63 )
V_68 ++ ;
if ( V_18 -> V_89 )
V_68 ++ ;
if ( V_18 -> V_90 )
V_68 ++ ;
if ( V_18 -> V_91 )
V_68 ++ ;
V_66 = F_26 ( V_2 , V_68 ) ;
if ( V_66 < 0 )
return V_66 ;
F_19 ( V_2 ) ;
if ( V_18 -> V_92 ) {
if ( V_51 ) {
if ( F_27 ( V_51 , F_18 ,
V_93 , L_28 , V_2 ) ) {
F_3 ( V_75
L_29 ,
V_51 ) ;
V_51 = 0 ;
} else
F_3 ( V_75 L_30 , V_51 ) ;
} else
F_3 ( V_75 L_31 ) ;
} else
V_51 = 0 ;
V_2 -> V_51 = V_51 ;
F_3 ( V_75 L_32 ) ;
V_67 = 0 ;
if ( V_18 -> V_88 ) {
V_4 = V_2 -> V_94 + V_67 ;
V_2 -> V_95 = V_4 ;
V_4 -> type = V_96 ;
V_4 -> V_97 = V_98 | V_99 | V_100 ;
if ( V_18 -> V_101 )
V_4 -> V_97 |= V_102 ;
V_4 -> V_6 = V_18 -> V_88 ;
V_4 -> V_103 = V_18 -> V_104 ;
V_4 -> V_105 = V_18 -> V_88 ;
V_4 -> V_106 = V_18 -> V_107 ;
V_4 -> V_108 = F_8 ;
V_67 ++ ;
}
if ( V_18 -> V_63 ) {
V_4 = V_2 -> V_94 + V_67 ;
V_4 -> type = V_109 ;
V_4 -> V_97 = V_110 | V_100 | V_99 ;
V_4 -> V_6 = V_18 -> V_63 ;
V_4 -> V_103 = V_18 -> V_111 ;
V_4 -> V_105 = V_18 -> V_63 ;
V_4 -> V_106 = V_18 -> V_112 ;
V_4 -> V_113 = F_12 ;
V_4 -> V_108 = F_13 ;
V_67 ++ ;
}
if ( V_18 -> V_89 ) {
V_4 = V_2 -> V_94 + V_67 ;
V_4 -> type = V_114 ;
V_4 -> V_97 = V_98 ;
V_4 -> V_6 = V_18 -> V_89 ;
V_4 -> V_103 = 1 ;
V_4 -> V_105 = V_18 -> V_89 ;
V_4 -> V_106 = & V_115 ;
V_4 -> V_116 = 0 ;
V_4 -> V_117 = F_14 ;
V_67 ++ ;
}
if ( V_18 -> V_90 ) {
V_4 = V_2 -> V_94 + V_67 ;
V_4 -> type = V_118 ;
V_4 -> V_97 = V_110 | V_98 ;
V_4 -> V_6 = V_18 -> V_90 ;
V_4 -> V_103 = 1 ;
V_4 -> V_105 = V_18 -> V_90 ;
V_4 -> V_106 = & V_115 ;
V_4 -> V_116 = ( 1 << V_18 -> V_90 ) - 1 ;
V_4 -> V_49 = 0 ;
V_4 -> V_117 = F_15 ;
V_67 ++ ;
}
if ( V_18 -> V_91 ) {
V_4 = V_2 -> V_94 + V_67 ;
V_4 -> type = V_119 ;
V_4 -> V_97 = V_110 | V_100 | V_99 ;
V_4 -> V_6 = V_18 -> V_91 ;
V_4 -> V_103 = 0xffff ;
V_4 -> V_105 = V_18 -> V_91 ;
V_4 -> V_49 = 0 ;
V_4 -> V_108 = F_16 ;
V_4 -> V_113 = F_17 ;
V_67 ++ ;
}
V_12 -> V_120 = 1 ;
#ifdef F_2
F_3 ( V_11 L_33 ) ;
#endif
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_121 )
if ( V_12 -> V_120 )
F_19 ( V_2 ) ;
if ( V_2 -> V_51 )
F_29 ( V_2 -> V_51 , V_2 ) ;
if ( V_2 -> V_121 && V_12 -> V_20 )
F_30 ( V_12 -> V_20 ) ;
if ( V_2 -> V_121 && V_12 -> V_70 )
F_31 ( V_12 -> V_70 ) ;
if ( -- V_77 == 0 )
F_32 ( V_78 ) ;
}
