static void F_1 ( struct V_1 * V_2 , char * V_3 ,
unsigned int V_4 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
unsigned int V_9 ;
F_2 (KERN_DEBUG PPIP32 L_1 , p->name, str) ;
{
static const char V_10 [ 8 ] [ 4 ] = { L_2 , L_3 , L_4 ,
L_5 , L_6 , L_7 ,
L_8 , L_9 } ;
unsigned int V_11 = F_3 ( V_6 -> V_12 . V_11 ) ;
F_2 (KERN_DEBUG PPIP32 L_10 , ecr) ;
F_2 ( L_11 ,
V_10 [ ( V_11 & V_13 ) >> V_14 ] ) ;
if ( V_11 & V_15 )
F_2 ( L_12 ) ;
if ( V_11 & V_16 )
F_2 ( L_13 ) ;
if ( V_11 & V_17 )
F_2 ( L_14 ) ;
if ( V_11 & V_18 )
F_2 ( L_15 ) ;
if ( V_11 & V_19 )
F_2 ( L_16 ) ;
F_2 ( L_17 ) ;
}
if ( V_4 ) {
unsigned int V_20 , V_21 , V_22 ;
V_20 = F_3 ( V_6 -> V_12 . V_11 ) ;
F_4 ( V_23 , V_6 -> V_12 . V_11 ) ;
F_4 ( V_24 , V_6 -> V_12 . V_11 ) ;
V_21 = F_3 ( V_6 -> V_12 . V_21 ) ;
V_22 = F_3 ( V_6 -> V_12 . V_22 ) ;
F_4 ( V_23 , V_6 -> V_12 . V_11 ) ;
F_4 ( V_20 , V_6 -> V_12 . V_11 ) ;
F_2 (KERN_DEBUG PPIP32 L_18 , cnfgA) ;
F_2 ( L_19 , ( V_21 & V_25 ) ? L_20 : L_21 ) ;
switch ( V_21 & V_26 ) {
case V_27 :
F_2 ( L_22 ) ;
break;
case V_28 :
F_2 ( L_23 ) ;
break;
case V_29 :
F_2 ( L_24 ) ;
break;
default:
F_2 ( L_25 ) ;
break;
}
if ( ! ( V_21 & V_30 ) )
F_2 ( L_26 ) ;
if ( ( V_21 & V_26 ) != V_27 )
F_2 ( L_27 , V_21 & V_31 ,
( ( V_21 & V_31 ) > 1 ) ? L_28 : L_29 ) ;
F_2 ( L_17 ) ;
F_2 (KERN_DEBUG PPIP32 L_30 , cnfgB) ;
F_2 ( L_31 ,
( V_22 & V_32 ) >> V_33 ,
( V_22 & V_34 ) >> V_35 ) ;
F_2 ( L_32 , ! ! ( V_22 & V_36 ) ) ;
if ( V_22 & V_37 )
F_2 ( L_33 ) ;
F_2 ( L_17 ) ;
}
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
unsigned int V_38 = V_9 ? V_6 -> V_39 : F_3 ( V_6 -> V_12 . V_38 ) ;
F_2 (KERN_DEBUG PPIP32 L_34 ,
i ? L_35 : L_36 , dcr) ;
F_2 ( L_11 , ( V_38 & V_40 ) ? L_37 : L_38 ) ;
if ( V_38 & V_41 )
F_2 ( L_39 ) ;
if ( ! ( V_38 & V_42 ) )
F_2 ( L_40 ) ;
if ( V_38 & V_43 )
F_2 ( L_41 ) ;
if ( ! ( V_38 & V_44 ) )
F_2 ( L_42 ) ;
if ( ! ( V_38 & V_45 ) )
F_2 ( L_43 ) ;
F_2 ( L_17 ) ;
}
#define F_5 (f++ ? ',' : ' ')
{
unsigned int V_46 = 0 ;
unsigned int V_47 = F_3 ( V_6 -> V_12 . V_47 ) ;
F_2 (KERN_DEBUG PPIP32 L_44 , dsr) ;
if ( ! ( V_47 & V_48 ) )
F_2 ( L_45 , F_5 ) ;
if ( V_47 & V_49 )
F_2 ( L_46 , F_5 ) ;
if ( V_47 & V_50 )
F_2 ( L_47 , F_5 ) ;
if ( V_47 & V_51 )
F_2 ( L_48 , F_5 ) ;
if ( V_47 & V_52 )
F_2 ( L_49 , F_5 ) ;
if ( ! ( V_47 & V_53 ) )
F_2 ( L_50 , F_5 ) ;
if ( V_47 & V_54 )
F_2 ( L_51 , F_5 ) ;
F_2 ( L_17 ) ;
}
#undef F_5
}
static void F_6 ( unsigned int V_55 )
{
unsigned long V_56 ;
F_7 ( & V_57 . V_58 , V_56 ) ;
if ( V_57 . V_59 > 0 ) {
volatile T_1 T_2 * V_60 = ( V_57 . V_61 == 0 ) ?
& V_62 -> V_63 . V_64 . V_1 . V_65 :
& V_62 -> V_63 . V_64 . V_1 . V_66 ;
T_1 V_67 ;
T_1 V_68 ;
if ( V_57 . V_59 <= V_55 ) {
V_67 = V_57 . V_59 ;
V_68 = V_69 ;
} else {
V_67 = V_55 ;
V_68 = 0 ;
}
F_8 ( NULL ,
L_52 ,
V_55 ,
( unsigned int ) V_57 . V_70 ,
( unsigned int ) V_57 . V_71 ,
( unsigned int ) V_67 ,
V_57 . V_61 , V_68 ? L_53 : L_29 ) ;
V_68 |= V_57 . V_71 &
V_72 ;
V_68 |= ( ( V_67 - 1 ) << V_73 ) &
V_74 ;
F_9 ( V_68 , V_60 ) ;
V_57 . V_71 += V_67 ;
V_57 . V_59 -= V_67 ;
V_57 . V_61 ^= 1U ;
}
if ( V_57 . V_59 == 0 && V_57 . V_75 ) {
F_10 ( V_76 L_54 ) ;
F_11 ( V_77 ) ;
F_11 ( V_78 ) ;
V_57 . V_75 = 0 ;
}
F_12 ( & V_57 . V_58 , V_56 ) ;
}
static T_3 F_13 ( int V_79 , void * V_80 )
{
if ( V_57 . V_59 )
F_8 ( NULL , L_55 , V_79 , V_57 . V_61 ) ;
F_6 ( V_81 ) ;
return V_82 ;
}
static T_3 F_14 ( int V_79 , void * V_80 )
{
F_15 ( NULL , L_56 , V_79 ) ;
return V_82 ;
}
static int F_16 ( enum V_83 V_84 ,
void * V_85 , T_4 V_67 )
{
unsigned int V_55 ;
T_1 V_64 ;
F_8 ( NULL , L_57 , V_84 , ( unsigned long ) V_67 ) ;
F_17 ( V_84 != V_86 ) ;
V_64 = V_87 ;
F_9 ( V_64 , & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
if ( ! V_57 . V_75 ) {
F_18 ( 1 ) ;
F_19 ( V_77 ) ;
F_19 ( V_78 ) ;
V_57 . V_75 = 1 ;
}
V_57 . V_84 = V_84 ;
V_57 . V_70 = F_20 ( NULL , V_85 , V_67 , V_84 ) ;
V_57 . V_89 = V_67 ;
V_57 . V_71 = V_57 . V_70 ;
V_57 . V_59 = V_57 . V_89 ;
V_57 . V_61 = 0 ;
V_64 = ( V_84 == V_86 ) ? 0 : V_90 ;
F_9 ( V_64 , & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
V_55 = V_81 -
( V_57 . V_71 & ( V_81 - 1 ) ) ;
F_6 ( V_55 ) ;
F_6 ( V_81 ) ;
V_64 |= V_91 ;
F_9 ( V_64 , & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
return 0 ;
}
static void F_21 ( void )
{
T_1 V_92 ;
T_1 V_93 ;
T_1 V_64 ;
T_1 V_94 ;
T_4 V_95 [ 2 ] ;
F_8 ( NULL , L_58 ) ;
F_22 ( & V_57 . V_58 ) ;
if ( V_57 . V_75 ) {
F_10 ( V_76 L_59 ) ;
F_11 ( V_77 ) ;
F_11 ( V_78 ) ;
V_57 . V_75 = 0 ;
}
F_23 ( & V_57 . V_58 ) ;
F_24 ( V_77 ) ;
F_24 ( V_78 ) ;
V_64 = F_25 ( & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
V_64 &= ~ V_91 ;
F_9 ( V_64 , & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
V_92 = F_25 ( & V_62 -> V_63 . V_64 . V_1 . V_65 ) ;
V_93 = F_25 ( & V_62 -> V_63 . V_64 . V_1 . V_66 ) ;
V_64 = F_25 ( & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
V_94 = F_25 ( & V_62 -> V_63 . V_64 . V_1 . V_96 ) ;
V_95 [ 0 ] = ( V_64 & V_97 ) ?
1 + ( ( V_92 & V_74 ) >>
V_73 ) :
0 ;
V_95 [ 1 ] = ( V_64 & V_98 ) ?
1 + ( ( V_93 & V_74 ) >>
V_73 ) :
0 ;
if ( V_94 & V_99 )
V_95 [ ( V_94 & V_100 ) != 0 ] =
1 + ( ( V_94 & V_101 ) >>
V_102 ) ;
V_57 . V_59 += V_95 [ 0 ] + V_95 [ 1 ] ;
V_64 = V_87 ;
F_9 ( V_64 , & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
F_10 ( V_76 L_60 ) ;
F_19 ( V_77 ) ;
F_19 ( V_78 ) ;
V_57 . V_75 = 1 ;
F_26 ( NULL , V_57 . V_70 , V_57 . V_89 ,
V_57 . V_84 ) ;
}
static inline T_4 F_27 ( void )
{
return V_57 . V_59 ;
}
static int F_28 ( void )
{
int V_103 ;
F_29 ( & V_57 . V_58 ) ;
V_57 . V_75 = 1 ;
F_9 ( V_87 , & V_62 -> V_63 . V_64 . V_1 . V_88 ) ;
V_103 = F_30 ( V_77 , F_13 ,
0 , L_61 , NULL ) ;
if ( V_103 )
goto V_104;
V_103 = F_30 ( V_78 , F_13 ,
0 , L_61 , NULL ) ;
if ( V_103 )
goto V_105;
#if V_106
V_103 = F_30 ( V_107 , F_14 ,
0 , L_61 , NULL ) ;
if ( V_103 )
goto V_108;
#endif
return 0 ;
#if V_106
V_108:
F_31 ( V_78 , NULL ) ;
#endif
V_105:
F_31 ( V_77 , NULL ) ;
V_104:
return V_103 ;
}
static void F_32 ( void )
{
#if V_106
F_31 ( V_107 , NULL ) ;
#endif
F_31 ( V_78 , NULL ) ;
F_31 ( V_77 , NULL ) ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
F_34 ( & V_6 -> V_109 ) ;
}
static T_3 F_35 ( int V_79 , void * V_80 )
{
struct V_1 * const V_2 = V_80 ;
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
enum V_110 V_111 = V_6 -> V_111 ;
switch ( V_111 ) {
case V_112 :
return F_36 ( V_79 , V_80 ) ;
case V_113 :
F_33 ( V_2 ) ;
break;
}
return V_82 ;
}
static inline unsigned int F_37 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return F_3 ( V_6 -> V_12 . V_11 ) ;
}
static inline void F_38 ( struct V_1 * V_2 ,
unsigned int V_114 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
F_4 ( V_114 , V_6 -> V_12 . V_11 ) ;
}
static inline void F_39 ( struct V_1 * V_2 ,
unsigned int V_115 ,
unsigned int V_116 )
{
unsigned int V_114 ;
V_114 = ( F_37 ( V_2 ) & ~ V_115 ) ^ V_116 ;
F_38 ( V_2 , V_114 ) ;
}
static void F_40 ( struct V_1 * V_2 , unsigned int V_117 )
{
unsigned int V_118 ;
V_117 &= V_13 ;
V_118 = F_37 ( V_2 ) & V_13 ;
if ( ! ( V_117 == V_119 || V_117 == V_23
|| V_118 == V_119 || V_118 == V_23 ) ) {
unsigned int V_11 = V_23 | V_15 | V_17 ;
F_38 ( V_2 , V_11 ) ;
}
F_38 ( V_2 , V_117 | V_15 | V_17 ) ;
}
static inline unsigned char F_41 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return F_3 ( V_6 -> V_12 . V_120 ) ;
}
static inline void F_42 ( struct V_1 * V_2 , unsigned char V_121 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
F_4 ( V_121 , V_6 -> V_12 . V_120 ) ;
}
static inline unsigned char F_43 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return F_3 ( V_6 -> V_12 . V_47 ) ;
}
static inline unsigned int F_44 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return V_6 -> V_39 ;
}
static inline void F_45 ( struct V_1 * V_2 ,
unsigned int V_114 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
F_46 ( V_2 , V_114 , V_6 -> V_122 ) ;
V_114 &= V_6 -> V_122 ;
F_4 ( V_114 , V_6 -> V_12 . V_38 ) ;
V_6 -> V_39 = V_114 ;
}
static inline void F_47 ( struct V_1 * V_2 ,
unsigned int V_115 ,
unsigned int V_116 )
{
unsigned int V_114 ;
V_114 = ( F_44 ( V_2 ) & ~ V_115 ) ^ V_116 ;
F_45 ( V_2 , V_114 ) ;
}
static inline unsigned char F_48 ( struct V_1 * V_2 )
{
const unsigned int V_123 =
V_45 | V_44 | V_43 | V_42 ;
return F_44 ( V_2 ) & V_123 ;
}
static inline void F_49 ( struct V_1 * V_2 ,
unsigned char V_114 )
{
const unsigned int V_124 =
V_45 | V_44 | V_43 | V_42 ;
F_46 ( V_2 , V_114 , V_124 ) ;
F_47 ( V_2 , V_124 , V_114 & V_124 ) ;
}
static inline unsigned char F_50 ( struct V_1 * V_2 ,
unsigned char V_115 ,
unsigned char V_116 )
{
const unsigned int V_124 =
V_45 | V_44 | V_43 | V_42 ;
F_46 ( V_2 , V_115 , V_124 ) ;
F_46 ( V_2 , V_116 , V_124 ) ;
F_47 ( V_2 , V_115 & V_124 , V_116 & V_124 ) ;
return F_48 ( V_2 ) ;
}
static inline void F_51 ( struct V_1 * V_2 )
{
F_47 ( V_2 , V_41 , 0 ) ;
}
static inline void F_52 ( struct V_1 * V_2 )
{
F_47 ( V_2 , V_41 , V_41 ) ;
}
static inline void F_53 ( struct V_1 * V_2 )
{
F_47 ( V_2 , V_40 , 0 ) ;
}
static inline void F_54 ( struct V_1 * V_2 )
{
F_47 ( V_2 , V_40 , V_40 ) ;
}
static void F_55 ( struct V_125 * V_126 ,
struct V_127 * V_128 )
{
V_128 -> V_129 . V_130 . V_38 = V_42 | V_43 ;
V_128 -> V_129 . V_130 . V_11 = V_23 | V_15 | V_17 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
V_128 -> V_129 . V_130 . V_38 = F_44 ( V_2 ) ;
V_128 -> V_129 . V_130 . V_11 = F_37 ( V_2 ) ;
}
static void F_57 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
F_40 ( V_2 , V_128 -> V_129 . V_130 . V_11 & V_13 ) ;
F_38 ( V_2 , V_128 -> V_129 . V_130 . V_11 ) ;
F_45 ( V_2 , V_128 -> V_129 . V_130 . V_38 ) ;
}
static unsigned int F_58 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
unsigned int V_131 ;
if ( ! ( F_43 ( V_2 ) & V_54 ) )
V_131 = 1 ;
else {
unsigned int V_132 ;
F_43 ( V_2 ) ;
V_132 = F_43 ( V_2 ) ;
F_4 ( V_132 | V_54 , V_6 -> V_12 . V_47 ) ;
F_4 ( V_132 & ~ V_54 , V_6 -> V_12 . V_47 ) ;
V_132 = F_43 ( V_2 ) ;
V_131 = ! ( V_132 & V_54 ) ;
}
F_8 ( V_2 , L_62 , V_131 ? L_63 : L_64 ) ;
return V_131 ;
}
static T_4 F_59 ( void T_2 * V_133 ,
struct V_1 * V_2 , void * V_70 ,
T_4 V_89 , int V_56 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
T_4 V_134 ;
F_40 ( V_2 , V_135 ) ;
F_54 ( V_2 ) ;
F_49 ( V_2 , V_43 ) ;
if ( ( V_56 & V_136 ) && ( V_89 > 1 ) ) {
F_60 ( V_133 , V_70 , V_89 ) ;
if ( F_3 ( V_6 -> V_12 . V_47 ) & V_54 ) {
F_58 ( V_2 ) ;
return - V_137 ;
}
V_134 = V_89 ;
} else {
T_5 * V_138 = V_70 ;
for ( V_134 = 0 ; V_134 < V_89 ; V_134 ++ ) {
* V_138 ++ = F_3 ( V_133 ) ;
if ( F_3 ( V_6 -> V_12 . V_47 ) & V_54 ) {
F_58 ( V_2 ) ;
break;
}
}
}
F_53 ( V_2 ) ;
F_40 ( V_2 , V_23 ) ;
return V_134 ;
}
static T_4 F_61 ( void T_2 * V_133 ,
struct V_1 * V_2 , const void * V_70 ,
T_4 V_89 , int V_56 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
T_4 V_139 ;
F_40 ( V_2 , V_135 ) ;
F_53 ( V_2 ) ;
F_49 ( V_2 , V_43 ) ;
if ( ( V_56 & V_136 ) && ( V_89 > 1 ) ) {
F_62 ( V_133 , V_70 , V_89 ) ;
if ( F_3 ( V_6 -> V_12 . V_47 ) & V_54 ) {
F_58 ( V_2 ) ;
return - V_137 ;
}
V_139 = V_89 ;
} else {
const T_5 * V_138 = V_70 ;
for ( V_139 = 0 ; V_139 < V_89 ; V_139 ++ ) {
F_4 ( * V_138 ++ , V_133 ) ;
if ( F_3 ( V_6 -> V_12 . V_47 ) & V_54 ) {
F_58 ( V_2 ) ;
break;
}
}
}
F_40 ( V_2 , V_23 ) ;
return V_139 ;
}
static T_4 F_63 ( struct V_1 * V_2 , void * V_70 ,
T_4 V_89 , int V_56 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return F_59 ( V_6 -> V_12 . V_140 , V_2 , V_70 , V_89 , V_56 ) ;
}
static T_4 F_64 ( struct V_1 * V_2 , const void * V_70 ,
T_4 V_89 , int V_56 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return F_61 ( V_6 -> V_12 . V_140 , V_2 , V_70 , V_89 , V_56 ) ;
}
static T_4 F_65 ( struct V_1 * V_2 , void * V_70 ,
T_4 V_89 , int V_56 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return F_59 ( V_6 -> V_12 . V_141 , V_2 , V_70 , V_89 , V_56 ) ;
}
static T_4 F_66 ( struct V_1 * V_2 , const void * V_70 ,
T_4 V_89 , int V_56 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
return F_61 ( V_6 -> V_12 . V_141 , V_2 , V_70 , V_89 , V_56 ) ;
}
static unsigned int F_67 ( struct V_1 * V_2 ,
unsigned long V_142 )
{
F_68 () ;
if ( F_69 ( V_143 , V_142 ) ) {
F_70 ( V_76 L_65 , V_2 -> V_144 ) ;
return 1 ;
}
if ( F_71 ( V_145 ) ) {
F_70 ( V_76 L_66 , V_2 -> V_144 ) ;
return 1 ;
}
if ( ! ( F_43 ( V_2 ) & V_52 ) ) {
F_70 ( V_76 L_67 , V_2 -> V_144 ) ;
return 1 ;
}
return 0 ;
}
static unsigned int F_72 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
struct V_1 * const V_7 = V_2 -> V_7 ;
unsigned long V_142 ;
unsigned int V_67 ;
unsigned int V_11 ;
V_142 = V_143 + V_7 -> V_146 -> V_147 ;
V_67 = 0 ;
while ( 1 ) {
if ( F_67 ( V_2 , V_142 ) )
break;
V_11 = F_37 ( V_2 ) ;
if ( V_11 & V_19 ) {
V_67 = V_6 -> V_148 ;
break;
}
F_73 ( V_149 ) ;
}
return V_67 ;
}
static unsigned int F_74 ( struct V_1 * V_2 )
{
static unsigned int V_150 = 0 ;
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
struct V_1 * const V_7 = V_2 -> V_7 ;
unsigned long V_151 ;
unsigned long V_142 ;
unsigned int V_67 ;
unsigned int V_11 ;
V_151 = F_75 ( ( unsigned long ) V_7 -> V_146 -> V_147 ,
F_76 ( V_152 ) ) ;
V_142 = V_143 + V_7 -> V_146 -> V_147 ;
V_67 = 0 ;
while ( 1 ) {
if ( F_67 ( V_2 , V_142 ) )
break;
F_77 ( & V_6 -> V_109 ) ;
F_39 ( V_2 , V_17 , 0 ) ;
V_11 = F_37 ( V_2 ) ;
if ( ! ( V_11 & V_19 ) ) {
F_78 (
& V_6 -> V_109 , V_151 ) ;
V_11 = F_37 ( V_2 ) ;
if ( ( V_11 & V_19 ) && ! ( V_11 & V_17 )
&& ! V_150 ) {
F_2 (KERN_WARNING PPIP32
L_68 ,
p->name, __func__) ;
V_150 = 1 ;
}
}
F_39 ( V_2 , V_17 , V_17 ) ;
if ( V_11 & V_19 ) {
V_67 = V_6 -> V_148 ;
break;
} else if ( V_11 & V_17 ) {
V_67 = V_6 -> V_153 ;
break;
}
}
return V_67 ;
}
static T_4 F_79 ( struct V_1 * V_2 ,
const void * V_70 , T_4 V_89 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
const T_5 * V_138 = V_70 ;
T_4 V_59 = V_89 ;
V_6 -> V_111 = V_113 ;
while ( V_59 > 0 ) {
unsigned int V_67 ;
V_67 = ( V_2 -> V_79 == V_154 ) ?
F_72 ( V_2 ) :
F_74 ( V_2 ) ;
if ( V_67 == 0 )
break;
if ( V_67 > V_59 )
V_67 = V_59 ;
if ( V_67 == 1 ) {
F_4 ( * V_138 , V_6 -> V_12 . V_155 ) ;
V_138 ++ , V_59 -- ;
} else {
F_62 ( V_6 -> V_12 . V_155 , V_138 , V_67 ) ;
V_138 += V_67 , V_59 -= V_67 ;
}
}
V_6 -> V_111 = V_112 ;
return V_89 - V_59 ;
}
static T_4 F_80 ( struct V_1 * V_2 ,
const void * V_70 , T_4 V_89 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
struct V_1 * const V_7 = V_2 -> V_7 ;
unsigned long V_151 ;
unsigned long V_142 ;
T_4 V_139 ;
unsigned int V_11 ;
V_6 -> V_111 = V_113 ;
F_16 ( V_86 , ( void * ) V_70 , V_89 ) ;
F_77 ( & V_6 -> V_109 ) ;
F_39 ( V_2 , V_16 | V_17 , V_16 ) ;
V_151 = F_75 ( ( unsigned long ) V_7 -> V_146 -> V_147 ,
F_76 ( V_152 ) ) ;
V_142 = V_143 + V_7 -> V_146 -> V_147 ;
while ( 1 ) {
if ( F_67 ( V_2 , V_142 ) )
break;
F_78 ( & V_6 -> V_109 ,
V_151 ) ;
V_11 = F_37 ( V_2 ) ;
if ( V_11 & V_17 )
break;
}
F_21 () ;
V_139 = V_89 - F_27 () ;
V_6 -> V_111 = V_112 ;
return V_139 ;
}
static T_4 F_81 ( struct V_1 * V_2 ,
const void * V_70 , T_4 V_89 )
{
T_4 V_139 = 0 ;
if ( V_89 )
V_139 = ( V_2 -> V_156 & V_157 ) ?
F_80 ( V_2 , V_70 , V_89 ) :
F_79 ( V_2 , V_70 , V_89 ) ;
return V_139 ;
}
static unsigned int F_82 ( struct V_1 * V_2 ,
unsigned long V_147 )
{
unsigned long V_142 = V_143 + V_147 ;
unsigned int V_158 ;
unsigned int V_159 ;
for ( V_159 = 0 ; V_159 < 40 ; V_159 ++ ) {
if ( F_37 ( V_2 ) & V_19 )
break;
if ( F_69 ( V_143 , V_142 ) )
break;
if ( F_71 ( V_145 ) )
break;
F_73 ( 5 ) ;
}
V_158 = 1 ;
while ( ! ( F_37 ( V_2 ) & V_19 ) ) {
if ( F_83 ( V_143 , V_142 ) )
break;
F_84 ( V_158 ) ;
if ( F_71 ( V_145 ) )
break;
if ( V_158 < 128 )
V_158 *= 2 ;
}
return ! ! ( F_37 ( V_2 ) & V_19 ) ;
}
static unsigned int F_85 ( struct V_1 * V_2 ,
unsigned int V_117 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
unsigned int V_160 ;
unsigned int V_161 ;
if ( F_37 ( V_2 ) & V_19 )
V_160 = 0 ;
else {
F_70 ( V_76 L_69 , V_2 -> V_144 ) ;
F_50 ( V_2 , V_45 , 0 ) ;
for ( V_160 = V_6 -> V_148 ; V_160 > 0 ; V_160 -- ) {
if ( F_37 ( V_2 ) & V_18 )
break;
F_4 ( 0x00 , V_6 -> V_12 . V_155 ) ;
}
}
if ( V_160 )
F_70 ( V_76 L_70 ,
V_2 -> V_144 , V_160 ,
( V_160 == 1 ) ? L_71 : L_72 ) ;
F_40 ( V_2 , V_23 ) ;
if ( V_117 == V_162 ) {
F_54 ( V_2 ) ;
F_50 ( V_2 , V_43 , 0 ) ;
if ( F_86 ( V_2 , V_50 , 0 ) )
F_70 ( V_76 L_73 ,
V_2 -> V_144 , V_163 ) ;
F_50 ( V_2 , V_45 , V_45 ) ;
F_50 ( V_2 , V_43 , V_43 ) ;
if ( F_86 ( V_2 , V_50 , V_50 ) )
F_70 ( V_76 L_74 ,
V_2 -> V_144 , V_163 ) ;
}
F_40 ( V_2 , V_24 ) ;
V_161 = F_3 ( V_6 -> V_12 . V_21 ) ;
if ( ! ( V_161 & V_30 ) ) {
F_70 ( V_76 L_75 ,
V_2 -> V_144 , V_161 ) ;
F_70 ( V_76 L_76 ,
V_2 -> V_144 ) ;
V_160 ++ ;
}
F_40 ( V_2 , V_23 ) ;
F_53 ( V_2 ) ;
return V_160 ;
}
static T_4 F_87 ( struct V_1 * V_2 ,
const void * V_70 , T_4 V_89 ,
int V_56 )
{
static unsigned int V_164 = 1 ;
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
struct V_1 * const V_7 = V_2 -> V_7 ;
T_4 V_139 = 0 ;
if ( V_7 -> V_146 -> V_147 <= V_165 )
return F_88 ( V_2 , V_70 , V_89 , V_56 ) ;
F_40 ( V_2 , V_23 ) ;
F_49 ( V_2 , V_42 | V_43 ) ;
F_53 ( V_2 ) ;
F_51 ( V_2 ) ;
F_40 ( V_2 , V_166 ) ;
V_7 -> V_167 . V_168 = V_169 ;
if ( F_86 ( V_2 , V_48 | V_52 ,
V_48 | V_52 ) ) {
if ( V_164 )
F_2 (KERN_INFO PPIP32 L_77 ,
p->name, __func__) ;
V_164 = 0 ;
goto V_170;
}
V_164 = 1 ;
V_139 = F_81 ( V_2 , V_70 , V_89 ) ;
F_82 ( V_2 , V_7 -> V_146 -> V_147 * V_6 -> V_148 ) ;
V_139 -= F_85 ( V_2 , V_166 ) ;
if ( F_86 ( V_2 , V_48 , V_48 ) )
F_2 (KERN_DEBUG PPIP32 L_78 ,
p->name, __func__) ;
V_170:
F_40 ( V_2 , V_23 ) ;
V_7 -> V_167 . V_168 = V_171 ;
return V_139 ;
}
static T_4 F_89 ( struct V_1 * V_2 ,
const void * V_70 , T_4 V_89 ,
int V_56 )
{
static unsigned int V_164 = 1 ;
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
struct V_1 * const V_7 = V_2 -> V_7 ;
T_4 V_139 = 0 ;
if ( V_7 -> V_146 -> V_147 <= V_165 )
return F_90 ( V_2 , V_70 , V_89 , V_56 ) ;
if ( V_7 -> V_167 . V_168 != V_171 ) {
F_50 ( V_2 , V_43 | V_44 ,
V_43 | V_44 ) ;
if ( F_86 ( V_2 , V_50 , V_50 ) ) {
F_2 (KERN_DEBUG PPIP32 L_79 ,
p->name, __func__) ;
V_7 -> V_167 . V_168 = V_172 ;
return 0 ;
}
}
F_40 ( V_2 , V_23 ) ;
F_49 ( V_2 , V_42 | V_43 ) ;
F_53 ( V_2 ) ;
F_51 ( V_2 ) ;
F_40 ( V_2 , V_162 ) ;
V_7 -> V_167 . V_168 = V_169 ;
if ( F_86 ( V_2 , V_48 | V_52 ,
V_48 | V_52 ) ) {
if ( V_164 )
F_2 (KERN_INFO PPIP32 L_77 ,
p->name, __func__) ;
V_164 = 0 ;
goto V_170;
}
V_164 = 1 ;
V_139 = F_81 ( V_2 , V_70 , V_89 ) ;
F_82 ( V_2 , V_7 -> V_146 -> V_147 * V_6 -> V_148 ) ;
V_139 -= F_85 ( V_2 , V_162 ) ;
if ( F_86 ( V_2 , V_48 , V_48 ) )
F_2 (KERN_DEBUG PPIP32 L_78 ,
p->name, __func__) ;
V_170:
F_40 ( V_2 , V_23 ) ;
V_7 -> V_167 . V_168 = V_171 ;
return V_139 ;
}
static T_6 unsigned int F_91 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
unsigned int V_11 ;
V_11 = V_23 | V_15 | V_17 ;
F_4 ( V_11 , V_6 -> V_12 . V_11 ) ;
if ( F_3 ( V_6 -> V_12 . V_11 ) != ( V_11 | V_19 ) )
goto V_173;
F_92 ( V_2 , L_80 ) ;
F_40 ( V_2 , V_119 ) ;
F_49 ( V_2 , V_42 | V_43 ) ;
return 1 ;
V_173:
F_92 ( V_2 , L_81 ) ;
return 0 ;
}
static T_6 unsigned int F_93 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
unsigned int V_174 , V_175 ;
unsigned int V_176 ;
unsigned int V_9 ;
F_40 ( V_2 , V_24 ) ;
V_174 = F_3 ( V_6 -> V_12 . V_21 ) ;
V_175 = F_3 ( V_6 -> V_12 . V_22 ) ;
switch ( V_174 & V_26 ) {
case V_27 :
V_176 = 1 ;
break;
case V_28 :
V_176 = 2 ;
break;
case V_29 :
V_176 = 4 ;
break;
default:
F_92 ( V_2 , L_82 ,
( V_174 & V_26 ) >> V_177 ) ;
goto V_173;
break;
}
if ( V_176 != 1 ) {
F_92 ( V_2 , L_83 , V_176 ) ;
goto V_173;
}
V_6 -> V_176 = V_176 ;
F_92 ( V_2 , L_84 , 8 * V_6 -> V_176 ) ;
F_4 ( V_175 | V_37 , V_6 -> V_12 . V_22 ) ;
if ( F_3 ( V_6 -> V_12 . V_22 ) & V_37 )
F_92 ( V_2 , L_85 ) ;
F_4 ( V_175 & ~ V_37 , V_6 -> V_12 . V_22 ) ;
F_40 ( V_2 , V_178 ) ;
if ( ! ( F_3 ( V_6 -> V_12 . V_11 ) & V_19 ) ) {
F_92 ( V_2 , L_86 ) ;
goto V_173;
}
V_6 -> V_148 = 0 ;
for ( V_9 = 0 ; V_9 < 1024 ; V_9 ++ ) {
if ( F_3 ( V_6 -> V_12 . V_11 ) & V_18 ) {
V_6 -> V_148 = V_9 ;
break;
}
F_4 ( ( T_5 ) V_9 , V_6 -> V_12 . V_155 ) ;
}
if ( V_9 >= 1024 ) {
F_92 ( V_2 , L_87 ) ;
goto V_173;
}
if ( ! V_6 -> V_148 ) {
F_92 ( V_2 , L_88 ) ;
goto V_173;
}
F_92 ( V_2 , L_89 , V_6 -> V_148 ) ;
F_39 ( V_2 , V_17 , 0 ) ;
V_6 -> V_153 = 0 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_148 ; V_9 ++ ) {
if ( F_3 ( V_6 -> V_12 . V_155 ) != ( T_5 ) V_9 ) {
F_92 ( V_2 , L_90 ) ;
goto V_173;
}
if ( ! V_6 -> V_153
&& F_3 ( V_6 -> V_12 . V_11 ) & V_17 )
V_6 -> V_153 = V_9 + 1 ;
if ( V_9 + 1 < V_6 -> V_148
&& F_3 ( V_6 -> V_12 . V_11 ) & V_19 ) {
F_92 ( V_2 , L_91 ) ;
goto V_173;
}
}
if ( ! V_6 -> V_153 ) {
F_92 ( V_2 , L_92 ) ;
goto V_173;
}
F_92 ( V_2 , L_93 , V_6 -> V_153 ) ;
if ( ! ( F_3 ( V_6 -> V_12 . V_11 ) & V_19 ) ) {
F_92 ( V_2 , L_94 ) ;
goto V_173;
}
F_40 ( V_2 , V_23 ) ;
F_54 ( V_2 ) ;
F_40 ( V_2 , V_178 ) ;
F_39 ( V_2 , V_17 , 0 ) ;
V_6 -> V_179 = 0 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_148 ; V_9 ++ ) {
F_4 ( 0xaa , V_6 -> V_12 . V_155 ) ;
if ( F_3 ( V_6 -> V_12 . V_11 ) & V_17 ) {
V_6 -> V_179 = V_9 + 1 ;
break;
}
}
if ( ! V_6 -> V_179 ) {
F_92 ( V_2 , L_95 ) ;
goto V_173;
}
F_92 ( V_2 , L_96 , V_6 -> V_179 ) ;
F_40 ( V_2 , V_23 ) ;
F_53 ( V_2 ) ;
F_40 ( V_2 , V_119 ) ;
return 1 ;
V_173:
V_6 -> V_148 = 0 ;
F_40 ( V_2 , V_119 ) ;
return 0 ;
}
static void T_6
F_94 ( struct V_180 * V_12 ,
void T_2 * V_181 , void T_2 * V_182 ,
unsigned int V_183 )
{
#define F_95 ( T_7 ) ((u8 __iomem *)base + ((offset) << regshift))
#define F_96 ( T_7 ) ((u8 __iomem *)base_hi + ((offset) << regshift))
* V_12 = (struct V_180 ) {
. V_120 = F_95 ( 0 ) ,
. V_47 = F_95 ( 1 ) ,
. V_38 = F_95 ( 2 ) ,
. V_141 = F_95 ( 3 ) ,
. V_140 = F_95 ( 4 ) ,
. V_184 = F_95 ( 5 ) ,
. V_185 = F_95 ( 6 ) ,
. V_186 = F_95 ( 7 ) ,
. V_187 = F_95 ( 0 ) ,
. V_155 = F_96 ( 0 ) ,
. V_21 = F_96 ( 0 ) ,
. V_22 = F_96 ( 1 ) ,
. V_11 = F_96 ( 2 )
} ;
#undef F_96
#undef F_95
}
T_8 void F_97 ( struct V_1 * V_2 )
{
struct V_5 * const V_6 = V_2 -> V_7 -> V_8 ;
struct V_188 * V_189 = V_2 -> V_189 ;
F_98 ( V_2 ) ;
if ( V_2 -> V_156 & V_157 )
F_32 () ;
if ( V_2 -> V_79 != V_154 )
F_31 ( V_2 -> V_79 , V_2 ) ;
F_99 ( V_2 ) ;
F_100 ( V_6 ) ;
F_100 ( V_189 ) ;
}
static int T_6 F_101 ( void )
{
F_102 ( V_76 L_97 ) ;
V_190 = F_103 () ;
return F_104 ( V_190 ) ? F_105 ( V_190 ) : 0 ;
}
static void T_8 F_106 ( void )
{
F_97 ( V_190 ) ;
}
