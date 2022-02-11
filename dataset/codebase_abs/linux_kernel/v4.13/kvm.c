static inline void F_1 ( T_1 * V_1 , T_1 V_2 )
{
* V_1 = V_2 ;
F_2 ( ( V_3 ) V_1 , ( V_3 ) V_1 + 4 ) ;
}
static void F_3 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
#ifdef F_4
F_1 ( V_1 , V_6 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#else
F_1 ( V_1 , V_7 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#endif
}
static void F_5 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
#ifdef F_4
F_1 ( V_1 , V_6 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#else
F_1 ( V_1 , V_7 | V_5 | ( ( V_4 + 4 ) & 0x0000fffc ) ) ;
#endif
}
static void F_6 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
F_1 ( V_1 , V_7 | V_5 | ( V_4 & 0x0000ffff ) ) ;
}
static void F_7 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
#ifdef F_4
F_1 ( V_1 , V_8 | V_5 | ( V_4 & 0x0000fffc ) ) ;
#else
F_1 ( V_1 , V_9 | V_5 | ( ( V_4 + 4 ) & 0x0000fffc ) ) ;
#endif
}
static void F_8 ( T_1 * V_1 , long V_4 , T_1 V_5 )
{
F_1 ( V_1 , V_9 | V_5 | ( V_4 & 0x0000fffc ) ) ;
}
static void F_9 ( T_1 * V_1 )
{
F_1 ( V_1 , V_10 ) ;
}
static void F_10 ( T_1 * V_1 , int V_4 )
{
#if F_11 ( V_11 ) && F_11 ( V_12 )
if ( ( V_3 ) V_1 < ( V_3 ) & V_13 )
return;
#endif
F_1 ( V_1 , V_14 | ( V_4 & V_15 ) ) ;
}
static T_1 * F_12 ( int V_16 )
{
T_1 * V_17 ;
if ( ( V_18 + V_16 ) > F_13 ( V_19 ) ) {
F_14 ( V_20 L_1 ,
V_18 , V_16 ) ;
V_21 = false ;
return NULL ;
}
V_17 = ( void * ) & V_19 [ V_18 ] ;
V_18 += V_16 ;
return V_17 ;
}
static void F_15 ( T_1 * V_1 , T_1 V_5 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_25 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_26 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_28 , V_25 * 4 ) ;
V_17 [ V_26 ] |= V_23 & V_15 ;
switch ( F_16 ( V_5 ) ) {
case 30 :
F_3 ( & V_17 [ V_29 ] ,
F_17 ( V_30 ) , V_31 ) ;
break;
case 31 :
F_3 ( & V_17 [ V_29 ] ,
F_17 ( V_32 ) , V_31 ) ;
break;
default:
V_17 [ V_29 ] |= V_5 ;
break;
}
V_17 [ V_33 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_25 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_18 ( T_1 * V_1 , T_1 V_5 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_34 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_35 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_36 , V_34 * 4 ) ;
V_17 [ V_35 ] |= V_23 & V_15 ;
switch ( F_16 ( V_5 ) ) {
case 30 :
F_3 ( & V_17 [ V_37 ] ,
F_17 ( V_30 ) , V_31 ) ;
F_3 ( & V_17 [ V_38 ] ,
F_17 ( V_30 ) , V_31 ) ;
break;
case 31 :
F_3 ( & V_17 [ V_37 ] ,
F_17 ( V_32 ) , V_31 ) ;
F_3 ( & V_17 [ V_38 ] ,
F_17 ( V_32 ) , V_31 ) ;
break;
default:
V_17 [ V_37 ] |= V_5 ;
V_17 [ V_38 ] |= V_5 ;
break;
}
V_17 [ V_39 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_34 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_19 ( T_1 * V_1 , T_1 V_5 , int V_40 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_41 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_42 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_43 , V_41 * 4 ) ;
V_17 [ V_42 ] |= V_23 & V_15 ;
if ( V_40 ) {
V_17 [ V_44 ] =
V_45 | F_20 ( V_46 ) | V_47 ;
} else {
switch ( F_16 ( V_5 ) ) {
case 30 :
F_3 ( & V_17 [ V_44 ] ,
F_17 ( V_30 ) , V_31 ) ;
break;
case 31 :
F_3 ( & V_17 [ V_44 ] ,
F_17 ( V_32 ) , V_31 ) ;
break;
default:
V_17 [ V_44 ] |= V_5 ;
break;
}
}
V_17 [ V_48 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_41 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_21 ( T_1 * V_1 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_49 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_50 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_51 , V_49 * 4 ) ;
V_17 [ V_50 ] |= V_23 & V_15 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_49 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_22 ( T_1 * V_1 , T_1 V_5 , T_1 V_52 )
{
T_1 * V_17 ;
int V_22 ;
int V_23 ;
V_3 V_24 ;
V_17 = F_12 ( V_53 * 4 ) ;
if ( ! V_17 )
return;
V_22 = ( V_3 ) V_17 - ( V_3 ) V_1 ;
V_24 = ( ( V_3 ) V_1 + 4 ) ;
V_23 = V_24 - ( V_3 ) & V_17 [ V_54 ] ;
if ( V_22 > V_27 ) {
V_21 = false ;
return;
}
memcpy ( V_17 , V_55 , V_53 * 4 ) ;
V_17 [ V_54 ] |= V_23 & V_15 ;
V_17 [ V_56 ] |= ( V_52 << 10 ) ;
V_17 [ V_57 ] |= V_5 ;
V_17 [ V_58 ] = * V_1 ;
F_2 ( ( V_3 ) V_17 , ( V_3 ) V_17 + V_53 * 4 ) ;
F_10 ( V_1 , V_22 ) ;
}
static void F_23 ( void * V_59 )
{
T_1 * V_60 = V_59 ;
V_3 V_61 [ 8 ] = { 0 } ;
V_3 V_62 [ 8 ] ;
V_61 [ 0 ] = V_63 ;
V_61 [ 1 ] = V_63 | V_64 ;
F_24 ( V_61 , V_62 , F_25 ( V_65 ) ) ;
* V_60 = V_62 [ 0 ] ;
}
static void F_26 ( T_1 * V_1 , T_1 V_60 )
{
T_1 V_66 = * V_1 ;
T_1 V_67 = V_66 & ~ V_68 ;
T_1 V_69 = V_66 & V_68 ;
switch ( V_67 ) {
case V_70 :
F_5 ( V_1 , F_17 ( V_71 ) , V_69 ) ;
break;
case F_27 ( V_72 ) :
F_5 ( V_1 , F_17 ( V_73 ) , V_69 ) ;
break;
case F_27 ( V_74 ) :
F_5 ( V_1 , F_17 ( V_75 ) , V_69 ) ;
break;
case F_27 ( V_76 ) :
F_5 ( V_1 , F_17 ( V_77 ) , V_69 ) ;
break;
case F_27 ( V_78 ) :
F_5 ( V_1 , F_17 ( V_79 ) , V_69 ) ;
break;
case F_27 ( V_80 ) :
F_5 ( V_1 , F_17 ( V_81 ) , V_69 ) ;
break;
case F_27 ( V_82 ) :
F_5 ( V_1 , F_17 ( V_83 ) , V_69 ) ;
break;
#ifdef F_28
case F_27 ( V_84 ) :
#else
case F_27 ( V_85 ) :
#endif
F_5 ( V_1 , F_17 ( V_86 ) , V_69 ) ;
break;
case F_27 ( V_87 ) :
F_6 ( V_1 , F_17 ( V_88 ) , V_69 ) ;
break;
#ifdef F_29
case F_27 ( V_89 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_91 ) , V_69 ) ;
break;
case F_27 ( V_92 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_93 ) , V_69 ) ;
break;
case F_27 ( V_94 ) :
if ( V_60 & V_90 )
F_5 ( V_1 , F_17 ( V_95 ) , V_69 ) ;
break;
case F_27 ( V_96 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_97 ) + 4 , V_69 ) ;
break;
case F_27 ( V_98 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_99 ) , V_69 ) ;
break;
case F_27 ( V_100 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_101 ) , V_69 ) ;
break;
case F_27 ( V_102 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_97 ) , V_69 ) ;
break;
#endif
case F_27 ( V_103 ) :
#ifdef F_28
case F_27 ( V_104 ) :
#endif
if ( V_60 & V_90 )
F_5 ( V_1 , F_17 ( V_105 ) , V_69 ) ;
break;
case F_27 ( V_106 ) :
#ifdef F_28
case F_27 ( V_107 ) :
#endif
if ( V_60 & V_90 )
F_5 ( V_1 , F_17 ( V_108 ) , V_69 ) ;
break;
case F_27 ( V_109 ) :
#ifdef F_28
case F_27 ( V_110 ) :
#endif
if ( V_60 & V_90 )
F_5 ( V_1 , F_17 ( V_111 ) , V_69 ) ;
break;
case F_27 ( V_112 ) :
#ifdef F_28
case F_27 ( V_113 ) :
#endif
if ( V_60 & V_90 )
F_5 ( V_1 , F_17 ( V_114 ) , V_69 ) ;
break;
#ifdef F_28
case F_27 ( V_115 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_116 ) , V_69 ) ;
break;
#endif
case F_27 ( V_117 ) :
if ( V_60 & V_90 )
F_6 ( V_1 , F_17 ( V_118 ) , V_69 ) ;
break;
case F_30 ( V_72 ) :
F_7 ( V_1 , F_17 ( V_73 ) , V_69 ) ;
break;
case F_30 ( V_74 ) :
F_7 ( V_1 , F_17 ( V_75 ) , V_69 ) ;
break;
case F_30 ( V_76 ) :
F_7 ( V_1 , F_17 ( V_77 ) , V_69 ) ;
break;
case F_30 ( V_78 ) :
F_7 ( V_1 , F_17 ( V_79 ) , V_69 ) ;
break;
case F_30 ( V_80 ) :
F_7 ( V_1 , F_17 ( V_81 ) , V_69 ) ;
break;
case F_30 ( V_82 ) :
F_7 ( V_1 , F_17 ( V_83 ) , V_69 ) ;
break;
#ifdef F_28
case F_30 ( V_84 ) :
#else
case F_30 ( V_85 ) :
#endif
F_7 ( V_1 , F_17 ( V_86 ) , V_69 ) ;
break;
case F_30 ( V_87 ) :
F_8 ( V_1 , F_17 ( V_88 ) , V_69 ) ;
break;
#ifdef F_29
case F_30 ( V_89 ) :
if ( V_60 & V_90 )
F_8 ( V_1 , F_17 ( V_91 ) , V_69 ) ;
break;
case F_30 ( V_92 ) :
if ( V_60 & V_90 )
F_8 ( V_1 , F_17 ( V_93 ) , V_69 ) ;
break;
case F_30 ( V_94 ) :
if ( V_60 & V_90 )
F_7 ( V_1 , F_17 ( V_95 ) , V_69 ) ;
break;
case F_30 ( V_96 ) :
if ( V_60 & V_90 )
F_8 ( V_1 , F_17 ( V_97 ) + 4 , V_69 ) ;
break;
case F_30 ( V_98 ) :
if ( V_60 & V_90 )
F_8 ( V_1 , F_17 ( V_99 ) , V_69 ) ;
break;
case F_30 ( V_100 ) :
if ( V_60 & V_90 )
F_8 ( V_1 , F_17 ( V_101 ) , V_69 ) ;
break;
case F_30 ( V_102 ) :
if ( V_60 & V_90 )
F_8 ( V_1 , F_17 ( V_97 ) , V_69 ) ;
break;
#endif
case F_30 ( V_103 ) :
if ( V_60 & V_90 )
F_7 ( V_1 , F_17 ( V_105 ) , V_69 ) ;
break;
case F_30 ( V_106 ) :
if ( V_60 & V_90 )
F_7 ( V_1 , F_17 ( V_108 ) , V_69 ) ;
break;
case F_30 ( V_109 ) :
if ( V_60 & V_90 )
F_7 ( V_1 , F_17 ( V_111 ) , V_69 ) ;
break;
case F_30 ( V_112 ) :
if ( V_60 & V_90 )
F_7 ( V_1 , F_17 ( V_114 ) , V_69 ) ;
break;
#ifdef F_28
case F_30 ( V_115 ) :
if ( V_60 & V_90 )
F_8 ( V_1 , F_17 ( V_116 ) , V_69 ) ;
break;
#endif
case V_119 :
F_9 ( V_1 ) ;
break;
case V_120 :
F_15 ( V_1 , V_69 ) ;
break;
case V_121 :
case V_122 :
F_18 ( V_1 , V_69 ) ;
break;
#ifdef F_28
case V_123 :
F_19 ( V_1 , V_69 , 0 ) ;
break;
#endif
}
switch ( V_67 & ~ V_124 ) {
#ifdef F_31
case V_125 :
if ( V_60 & V_126 ) {
T_1 V_127 = V_66 & V_124 ;
F_22 ( V_1 , V_69 , V_127 ) ;
}
break;
#endif
}
switch ( V_66 ) {
#ifdef F_28
case V_128 :
F_21 ( V_1 ) ;
break;
case V_129 :
F_19 ( V_1 , 0 , 1 ) ;
break;
#endif
}
}
static void F_32 ( void )
{
T_1 * V_17 ;
T_1 * V_130 , * V_131 ;
T_1 V_132 ;
T_1 V_60 ;
F_33 ( F_23 , & V_60 , 1 ) ;
if ( F_34 ( V_132 , ( T_1 * ) V_63 ) ) {
V_21 = false ;
return;
}
V_130 = ( void * ) V_133 ;
V_131 = ( void * ) V_134 ;
F_35 () ;
for ( V_17 = V_130 ; V_17 < V_131 ; V_17 ++ ) {
if ( V_17 >= V_135 && V_17 < V_136 ) {
V_17 = V_136 - 1 ;
continue;
}
F_26 ( V_17 , V_60 ) ;
}
F_36 () ;
F_14 ( V_137 L_2 ,
V_21 ? L_3 : L_4 ) ;
}
static T_2 void F_37 ( void )
{
F_38 ( & V_19 [ V_18 ] ,
& V_19 [ F_13 ( V_19 ) ] , - 1 , NULL ) ;
}
static int T_2 F_39 ( void )
{
F_40 () ;
if ( ! F_41 () )
goto V_138;
if ( ! V_139 )
goto V_138;
if ( F_42 ( V_140 ) )
F_32 () ;
#ifdef F_43
V_141 = 1 ;
#endif
V_138:
F_37 () ;
return 0 ;
}
