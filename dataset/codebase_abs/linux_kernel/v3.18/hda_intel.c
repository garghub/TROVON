static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , bool V_5 )
{
int V_6 ;
if ( F_2 ( V_2 ) )
return;
if ( ! V_4 || ! V_4 -> V_7 || ! V_4 -> V_8 )
return;
#ifdef F_3
if ( V_4 -> V_9 . type == V_10 ) {
struct V_11 * V_12 = V_4 -> V_13 ;
if ( V_2 -> V_14 == V_15 )
return;
if ( V_5 )
F_4 ( V_12 -> V_16 , V_12 -> V_6 ) ;
else
F_5 ( V_12 -> V_16 , V_12 -> V_6 ) ;
return;
}
#endif
V_6 = ( V_4 -> V_8 + V_17 - 1 ) >> V_18 ;
if ( V_5 )
F_6 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
else
F_7 ( ( unsigned long ) V_4 -> V_7 , V_6 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_19 ,
bool V_5 )
{
F_1 ( V_2 , V_19 , V_5 ) ;
}
static inline void F_9 ( struct V_1 * V_2 , struct V_20 * V_20 ,
struct V_21 * V_22 , bool V_5 )
{
if ( V_20 -> V_23 != V_5 ) {
F_1 ( V_2 , F_10 ( V_22 ) , V_5 ) ;
V_20 -> V_23 = V_5 ;
}
}
static inline void F_8 ( struct V_1 * V_2 , struct V_3 * V_19 ,
bool V_5 )
{
}
static inline void F_9 ( struct V_1 * V_2 , struct V_20 * V_20 ,
struct V_21 * V_22 , bool V_5 )
{
}
static void F_11 ( struct V_24 * V_25 , unsigned int V_26 ,
unsigned char V_27 , unsigned char V_28 )
{
unsigned char V_29 ;
F_12 ( V_25 , V_26 , & V_29 ) ;
V_29 &= ~ V_27 ;
V_29 |= ( V_28 & V_27 ) ;
F_13 ( V_25 , V_26 , V_29 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_30 & V_31 ) ) {
F_15 ( V_2 -> V_32 -> V_9 , L_1 ) ;
F_11 ( V_2 -> V_25 , V_33 , 0x07 , 0 ) ;
}
if ( V_2 -> V_30 & V_34 ) {
F_15 ( V_2 -> V_32 -> V_9 , L_2 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_25 ,
V_35 , 0x07 ,
F_2 ( V_2 ) ? V_36 : 0 ) ;
}
if ( V_2 -> V_30 & V_37 ) {
F_15 ( V_2 -> V_32 -> V_9 , L_3 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_25 ,
V_38 ,
0x0f , V_39 ) ;
F_11 ( V_2 -> V_25 ,
V_40 ,
0x01 , V_41 ) ;
F_11 ( V_2 -> V_25 ,
V_42 ,
0x01 , V_41 ) ;
}
if ( V_2 -> V_30 & V_43 ) {
unsigned short V_44 ;
F_16 ( V_2 -> V_25 , V_45 , & V_44 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_44 & V_46 ) ) ||
( F_2 ( V_2 ) && ( V_44 & V_46 ) ) ) {
V_44 &= ~ V_46 ;
if ( ! F_2 ( V_2 ) )
V_44 |= V_46 ;
F_17 ( V_2 -> V_25 , V_45 , V_44 ) ;
F_16 ( V_2 -> V_25 ,
V_45 , & V_44 ) ;
}
F_15 ( V_2 -> V_32 -> V_9 , L_4 ,
( V_44 & V_46 ) ?
L_5 : L_6 ) ;
}
}
static int F_18 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_47 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
int V_48 = V_22 -> V_48 ;
unsigned int V_49 = F_19 ( V_2 , V_20 ) ;
int V_50 ;
if ( V_48 == V_51 )
V_50 = V_47 - V_49 ;
else
V_50 = V_49 - V_47 ;
if ( V_50 < 0 ) {
if ( V_50 >= V_20 -> V_52 )
V_50 = 0 ;
else
V_50 += V_20 -> V_53 ;
}
if ( V_50 >= V_20 -> V_54 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_7 ,
V_50 , V_20 -> V_54 ) ;
V_50 = 0 ;
V_2 -> V_30 &= ~ V_55 ;
V_2 -> V_56 [ V_48 ] = NULL ;
}
return F_21 ( V_22 -> V_57 , V_50 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
int V_60 ;
V_60 = F_24 ( V_2 , V_20 ) ;
if ( V_60 == 1 ) {
V_20 -> V_61 = 0 ;
return V_60 ;
} else if ( V_60 == 0 && V_2 -> V_62 && V_2 -> V_62 -> V_63 ) {
V_20 -> V_61 = 1 ;
F_25 ( V_2 -> V_62 -> V_63 , & V_59 -> V_64 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
int V_48 = V_22 -> V_48 ;
T_1 V_65 ;
unsigned int V_47 ;
V_65 = F_26 ( V_2 , V_66 ) - V_20 -> V_67 ;
if ( V_65 < ( V_20 -> V_68 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_69 [ V_48 ] )
V_47 = V_2 -> V_69 [ V_48 ] ( V_2 , V_20 ) ;
else {
V_47 = F_27 ( V_2 , V_20 ) ;
if ( ! V_47 || V_47 == ( T_1 ) - 1 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_8 ) ;
V_2 -> V_69 [ V_48 ] = F_19 ;
V_47 = F_19 ( V_2 , V_20 ) ;
V_2 -> V_56 [ V_48 ] = NULL ;
} else {
V_2 -> V_69 [ V_48 ] = F_27 ;
if ( V_2 -> V_30 & V_55 )
V_2 -> V_56 [ V_48 ] = F_18 ;
}
}
if ( V_47 >= V_20 -> V_53 )
V_47 = 0 ;
if ( F_28 ( ! V_20 -> V_54 ,
L_9 ) )
return - 1 ;
if ( V_65 < ( V_20 -> V_68 * 5 ) / 4 &&
V_47 % V_20 -> V_54 > V_20 -> V_54 / 2 )
return V_2 -> V_70 [ V_2 -> V_71 ] ? 0 : - 1 ;
V_20 -> V_67 += V_65 ;
return 1 ;
}
static void F_29 ( struct V_72 * V_73 )
{
struct V_58 * V_59 = F_23 ( V_73 , struct V_58 , V_64 ) ;
struct V_1 * V_2 = & V_59 -> V_2 ;
int V_74 , V_75 , V_60 ;
if ( ! V_59 -> V_76 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_10 ,
V_2 -> V_32 -> V_77 ) ;
V_59 -> V_76 = 1 ;
}
for (; ; ) {
V_75 = 0 ;
F_30 ( & V_2 -> V_78 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_79 ; V_74 ++ ) {
struct V_20 * V_20 = & V_2 -> V_20 [ V_74 ] ;
if ( ! V_20 -> V_61 ||
! V_20 -> V_22 ||
! V_20 -> V_80 )
continue;
V_60 = F_24 ( V_2 , V_20 ) ;
if ( V_60 > 0 ) {
V_20 -> V_61 = 0 ;
F_31 ( & V_2 -> V_78 ) ;
F_32 ( V_20 -> V_22 ) ;
F_33 ( & V_2 -> V_78 ) ;
} else if ( V_60 < 0 ) {
V_75 = 0 ;
} else
V_75 ++ ;
}
F_34 ( & V_2 -> V_78 ) ;
if ( ! V_75 )
return;
F_35 ( 1 ) ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
int V_74 ;
F_30 ( & V_2 -> V_78 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_79 ; V_74 ++ )
V_2 -> V_20 [ V_74 ] . V_61 = 0 ;
F_34 ( & V_2 -> V_78 ) ;
}
static int F_37 ( struct V_1 * V_2 , int V_81 )
{
if ( F_38 ( V_2 -> V_25 -> V_82 , V_83 ,
V_2 -> V_84 ? 0 : V_85 ,
V_86 , V_2 ) ) {
F_39 ( V_2 -> V_32 -> V_9 ,
L_11 ,
V_2 -> V_25 -> V_82 ) ;
if ( V_81 )
F_40 ( V_2 -> V_32 ) ;
return - 1 ;
}
V_2 -> V_82 = V_2 -> V_25 -> V_82 ;
F_41 ( V_2 -> V_25 , ! V_2 -> V_84 ) ;
return 0 ;
}
static unsigned int F_42 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_87 , V_88 , V_89 ;
unsigned int V_90 , V_91 , V_92 ;
unsigned int V_93 ;
V_87 = F_43 ( V_2 , V_20 , V_94 ) ;
if ( V_20 -> V_22 -> V_48 == V_51 ) {
return V_87 ;
}
V_91 = F_44 ( * V_20 -> V_95 ) ;
V_91 %= V_20 -> V_54 ;
V_93 = F_45 ( V_2 -> V_96 + V_97 ) ;
if ( V_20 -> V_98 ) {
if ( V_87 <= V_93 )
return 0 ;
V_20 -> V_98 = 0 ;
}
if ( V_87 <= V_93 )
V_88 = V_20 -> V_53 + V_87 - V_93 ;
else
V_88 = V_87 - V_93 ;
V_92 = V_88 % V_20 -> V_54 ;
V_90 = V_87 % V_20 -> V_54 ;
if ( V_90 >= V_93 )
V_89 = V_87 - V_90 ;
else if ( V_91 >= V_92 )
V_89 = V_88 - V_92 ;
else {
V_89 = V_88 - V_92 + V_20 -> V_54 ;
if ( V_89 >= V_20 -> V_53 )
V_89 = 0 ;
}
return V_89 + V_91 ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
F_47 ( & V_99 ) ;
F_48 ( & V_59 -> V_100 , & V_101 ) ;
F_49 ( & V_99 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
F_47 ( & V_99 ) ;
F_51 ( & V_59 -> V_100 ) ;
F_49 ( & V_99 ) ;
}
static int F_52 ( const char * V_28 , const struct V_102 * V_103 )
{
struct V_58 * V_59 ;
struct V_1 * V_2 ;
struct V_104 * V_105 ;
int V_106 = V_107 ;
int V_108 = F_53 ( V_28 , V_103 ) ;
if ( V_108 || V_106 == V_107 )
return V_108 ;
F_47 ( & V_99 ) ;
F_54 (hda, &card_list, list) {
V_2 = & V_59 -> V_2 ;
if ( ! V_2 -> V_62 || V_2 -> V_109 )
continue;
F_54 (c, &chip->bus->codec_list, list)
F_55 ( V_105 ) ;
}
F_49 ( & V_99 ) ;
return 0 ;
}
static int F_56 ( struct V_110 * V_9 )
{
struct V_24 * V_25 = F_57 ( V_9 ) ;
struct V_111 * V_32 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_112 * V_113 ;
if ( ! V_32 )
return 0 ;
V_2 = V_32 -> V_13 ;
V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
if ( V_2 -> V_109 || V_59 -> V_114 )
return 0 ;
F_59 ( V_32 , V_115 ) ;
F_36 ( V_2 ) ;
F_54 (p, &chip->pcm_list, list)
F_60 ( V_113 -> V_116 ) ;
if ( V_2 -> V_117 )
F_61 ( V_2 -> V_62 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_82 >= 0 ) {
F_64 ( V_2 -> V_82 , V_2 ) ;
V_2 -> V_82 = - 1 ;
}
if ( V_2 -> V_84 )
F_65 ( V_2 -> V_25 ) ;
F_66 ( V_25 ) ;
F_67 ( V_25 ) ;
F_68 ( V_25 , V_118 ) ;
if ( V_2 -> V_30 & V_119 )
F_69 ( false ) ;
return 0 ;
}
static int F_70 ( struct V_110 * V_9 )
{
struct V_24 * V_25 = F_57 ( V_9 ) ;
struct V_111 * V_32 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
if ( ! V_32 )
return 0 ;
V_2 = V_32 -> V_13 ;
V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
if ( V_2 -> V_109 || V_59 -> V_114 )
return 0 ;
if ( V_2 -> V_30 & V_119 ) {
F_69 ( true ) ;
F_71 ( V_2 ) ;
}
F_68 ( V_25 , V_120 ) ;
F_72 ( V_25 ) ;
if ( F_73 ( V_25 ) < 0 ) {
F_39 ( V_2 -> V_32 -> V_9 ,
L_12 ) ;
F_40 ( V_32 ) ;
return - V_121 ;
}
F_74 ( V_25 ) ;
if ( V_2 -> V_84 )
if ( F_75 ( V_25 ) < 0 )
V_2 -> V_84 = 0 ;
if ( F_37 ( V_2 , 1 ) < 0 )
return - V_121 ;
F_14 ( V_2 ) ;
F_76 ( V_2 , true ) ;
F_77 ( V_2 -> V_62 ) ;
F_59 ( V_32 , V_122 ) ;
return 0 ;
}
static int F_78 ( struct V_110 * V_9 )
{
struct V_111 * V_32 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
if ( ! V_32 )
return 0 ;
V_2 = V_32 -> V_13 ;
V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
if ( V_2 -> V_109 || V_59 -> V_114 )
return 0 ;
if ( ! ( V_2 -> V_30 & V_123 ) )
return 0 ;
F_79 ( V_2 , V_124 , F_80 ( V_2 , V_124 ) |
V_125 ) ;
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( V_2 -> V_30 & V_119 )
F_69 ( false ) ;
return 0 ;
}
static int F_81 ( struct V_110 * V_9 )
{
struct V_111 * V_32 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_126 * V_62 ;
struct V_104 * V_127 ;
int V_128 ;
if ( ! V_32 )
return 0 ;
V_2 = V_32 -> V_13 ;
V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
if ( V_2 -> V_109 || V_59 -> V_114 )
return 0 ;
if ( ! ( V_2 -> V_30 & V_123 ) )
return 0 ;
if ( V_2 -> V_30 & V_119 ) {
F_69 ( true ) ;
F_71 ( V_2 ) ;
}
V_128 = F_80 ( V_2 , V_129 ) ;
F_14 ( V_2 ) ;
F_76 ( V_2 , true ) ;
V_62 = V_2 -> V_62 ;
if ( V_128 && V_62 ) {
F_54 (codec, &bus->codec_list, list)
if ( V_128 & ( 1 << V_127 -> V_130 ) )
F_82 ( V_127 -> V_62 -> V_63 ,
& V_127 -> V_131 , V_127 -> V_132 ) ;
}
F_79 ( V_2 , V_124 , F_80 ( V_2 , V_124 ) &
~ V_125 ) ;
return 0 ;
}
static int F_83 ( struct V_110 * V_9 )
{
struct V_111 * V_32 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
if ( ! V_32 )
return 0 ;
V_2 = V_32 -> V_13 ;
V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
if ( V_2 -> V_109 || V_59 -> V_114 )
return 0 ;
if ( ! V_133 ||
! ( V_2 -> V_30 & V_123 ) )
return - V_134 ;
return 0 ;
}
static void F_84 ( struct V_24 * V_25 ,
enum V_135 V_136 )
{
struct V_111 * V_32 = F_85 ( V_25 ) ;
struct V_1 * V_2 = V_32 -> V_13 ;
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
bool V_109 ;
F_86 ( & V_59 -> V_137 ) ;
if ( V_59 -> V_114 )
return;
V_109 = ( V_136 == V_138 ) ;
if ( V_2 -> V_109 == V_109 )
return;
if ( ! V_2 -> V_62 ) {
V_2 -> V_109 = V_109 ;
if ( ! V_109 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_13 ) ;
if ( F_87 ( V_2 ) < 0 ) {
F_39 ( V_2 -> V_32 -> V_9 , L_14 ) ;
V_59 -> V_114 = true ;
}
}
} else {
F_20 ( V_2 -> V_32 -> V_9 , L_15 ,
V_109 ? L_16 : L_17 ) ;
if ( V_109 ) {
F_88 ( V_32 -> V_9 ) ;
F_56 ( V_32 -> V_9 ) ;
V_25 -> V_139 = V_140 ;
V_2 -> V_109 = true ;
if ( F_89 ( V_2 -> V_62 ) )
F_90 ( V_2 -> V_32 -> V_9 ,
L_18 ) ;
} else {
F_91 ( V_2 -> V_62 ) ;
F_92 ( V_32 -> V_9 ) ;
V_2 -> V_109 = false ;
F_70 ( V_32 -> V_9 ) ;
}
}
}
static bool F_93 ( struct V_24 * V_25 )
{
struct V_111 * V_32 = F_85 ( V_25 ) ;
struct V_1 * V_2 = V_32 -> V_13 ;
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
F_86 ( & V_59 -> V_137 ) ;
if ( V_59 -> V_114 )
return false ;
if ( V_2 -> V_109 || ! V_2 -> V_62 )
return true ;
if ( F_89 ( V_2 -> V_62 ) )
return false ;
F_91 ( V_2 -> V_62 ) ;
return true ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
struct V_24 * V_113 = F_95 ( V_2 -> V_25 ) ;
if ( V_113 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_19 ) ;
V_59 -> V_141 = 1 ;
F_96 ( V_113 ) ;
}
}
static int F_97 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
int V_142 ;
if ( ! V_59 -> V_141 )
return 0 ;
V_142 = F_98 ( V_2 -> V_25 , & V_143 ,
V_144 ,
V_2 -> V_62 != NULL ) ;
if ( V_142 < 0 )
return V_142 ;
V_59 -> V_145 = 1 ;
F_99 ( V_2 -> V_32 -> V_9 ,
& V_59 -> V_146 ) ;
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
int V_74 ;
if ( ( V_2 -> V_30 & V_123 )
&& V_2 -> V_80 )
F_92 ( & V_25 -> V_9 ) ;
F_50 ( V_2 ) ;
F_101 ( V_2 ) ;
V_59 -> V_114 = 1 ;
F_102 ( & V_59 -> V_137 ) ;
if ( V_141 ( V_59 ) ) {
if ( V_2 -> V_109 && V_2 -> V_62 )
F_91 ( V_2 -> V_62 ) ;
if ( V_59 -> V_145 )
F_103 ( V_2 -> V_25 ) ;
}
if ( V_2 -> V_117 ) {
F_36 ( V_2 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_79 ; V_74 ++ )
F_104 ( V_2 , & V_2 -> V_20 [ V_74 ] ) ;
F_62 ( V_2 ) ;
}
if ( V_2 -> V_82 >= 0 )
F_64 ( V_2 -> V_82 , ( void * ) V_2 ) ;
if ( V_2 -> V_84 )
F_65 ( V_2 -> V_25 ) ;
if ( V_2 -> V_96 )
F_105 ( V_2 -> V_96 ) ;
F_106 ( V_2 ) ;
if ( V_2 -> V_147 )
F_107 ( V_2 -> V_25 ) ;
F_66 ( V_2 -> V_25 ) ;
F_108 ( V_2 -> V_20 ) ;
#ifdef F_109
if ( V_2 -> V_148 )
F_110 ( V_2 -> V_148 ) ;
#endif
if ( V_2 -> V_30 & V_119 ) {
F_69 ( false ) ;
F_111 () ;
}
F_108 ( V_59 ) ;
return 0 ;
}
static int F_112 ( struct V_149 * V_110 )
{
return F_100 ( V_110 -> V_150 ) ;
}
static struct V_24 * F_95 ( struct V_24 * V_25 )
{
struct V_24 * V_113 ;
switch ( V_25 -> V_151 ) {
case V_152 :
case V_153 :
case V_154 :
if ( V_25 -> V_155 == 1 ) {
V_113 = F_113 ( F_114 ( V_25 -> V_62 ) ,
V_25 -> V_62 -> V_77 , 0 ) ;
if ( V_113 ) {
if ( ( V_113 -> V_156 >> 8 ) == V_157 )
return V_113 ;
F_96 ( V_113 ) ;
}
}
break;
}
return NULL ;
}
static bool F_115 ( struct V_24 * V_25 )
{
bool V_158 = false ;
struct V_24 * V_113 = F_95 ( V_25 ) ;
if ( V_113 ) {
if ( F_116 ( V_113 ) == V_138 )
V_158 = true ;
F_96 ( V_113 ) ;
}
return V_158 ;
}
static int F_117 ( struct V_1 * V_2 , int V_159 )
{
const struct V_160 * V_161 ;
switch ( V_159 ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
return V_159 ;
}
V_161 = F_118 ( V_2 -> V_25 , V_167 ) ;
if ( V_161 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_20 ,
V_161 -> V_168 , V_161 -> V_169 , V_161 -> V_170 ) ;
return V_161 -> V_168 ;
}
if ( V_2 -> V_30 & V_171 ) {
F_15 ( V_2 -> V_32 -> V_9 , L_21 ) ;
return V_165 ;
}
if ( V_2 -> V_30 & V_172 ) {
F_15 ( V_2 -> V_32 -> V_9 , L_22 ) ;
return V_163 ;
}
return V_162 ;
}
static void F_119 ( struct V_1 * V_2 , int V_159 )
{
static T_2 V_173 [] = {
[ V_162 ] = NULL ,
[ V_163 ] = F_19 ,
[ V_164 ] = F_27 ,
[ V_165 ] = F_42 ,
[ V_166 ] = F_19 ,
} ;
V_2 -> V_69 [ 0 ] = V_2 -> V_69 [ 1 ] = V_173 [ V_159 ] ;
if ( V_159 == V_166 )
V_2 -> V_69 [ 1 ] = NULL ;
if ( V_159 == V_164 &&
( V_2 -> V_30 & V_55 ) ) {
V_2 -> V_56 [ 0 ] = V_2 -> V_56 [ 1 ] =
F_18 ;
}
}
static void F_120 ( struct V_1 * V_2 , int V_9 )
{
const struct V_160 * V_161 ;
V_2 -> V_174 = V_175 [ V_9 ] ;
if ( V_2 -> V_174 == - 1 ) {
V_161 = F_118 ( V_2 -> V_25 , V_176 ) ;
if ( V_161 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_23 ,
V_161 -> V_168 , V_161 -> V_169 , V_161 -> V_170 ) ;
V_2 -> V_174 = V_161 -> V_168 ;
}
}
if ( V_2 -> V_174 != - 1 &&
( V_2 -> V_174 & V_177 ) ) {
V_2 -> V_178 = V_2 -> V_174 & 0xff ;
F_20 ( V_2 -> V_32 -> V_9 , L_24 ,
V_2 -> V_178 ) ;
}
}
static void F_121 ( struct V_1 * V_2 )
{
const struct V_160 * V_161 ;
if ( V_179 >= 0 ) {
V_2 -> V_84 = ! ! V_179 ;
return;
}
V_2 -> V_84 = 1 ;
V_161 = F_118 ( V_2 -> V_25 , V_180 ) ;
if ( V_161 ) {
F_20 ( V_2 -> V_32 -> V_9 ,
L_25 ,
V_161 -> V_169 , V_161 -> V_170 , V_161 -> V_168 ) ;
V_2 -> V_84 = V_161 -> V_168 ;
return;
}
if ( V_2 -> V_30 & V_181 ) {
F_20 ( V_2 -> V_32 -> V_9 , L_26 ) ;
V_2 -> V_84 = 0 ;
}
}
static void F_122 ( struct V_1 * V_2 )
{
bool V_44 = V_2 -> V_44 ;
switch ( V_2 -> V_14 ) {
case V_182 :
if ( V_44 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_183 == 0x30 )
V_44 = false ;
}
break;
case V_184 :
V_44 = false ;
break;
case V_185 :
case V_15 :
V_44 = false ;
break;
}
if ( V_44 != V_2 -> V_44 ) {
F_20 ( V_2 -> V_32 -> V_9 , L_27 ,
V_44 ? L_28 : L_29 ) ;
V_2 -> V_44 = V_44 ;
}
}
static void F_123 ( struct V_72 * V_73 )
{
struct V_58 * V_59 = F_23 ( V_73 , struct V_58 , V_186 ) ;
F_87 ( & V_59 -> V_2 ) ;
}
static int F_124 ( struct V_111 * V_32 , struct V_24 * V_25 ,
int V_9 , unsigned int V_30 ,
const struct V_187 * V_188 ,
struct V_1 * * V_189 )
{
static struct V_190 V_191 = {
. V_192 = F_112 ,
} ;
struct V_58 * V_59 ;
struct V_1 * V_2 ;
int V_142 ;
* V_189 = NULL ;
V_142 = F_73 ( V_25 ) ;
if ( V_142 < 0 )
return V_142 ;
V_59 = F_125 ( sizeof( * V_59 ) , V_193 ) ;
if ( ! V_59 ) {
F_39 ( V_32 -> V_9 , L_30 ) ;
F_66 ( V_25 ) ;
return - V_194 ;
}
V_2 = & V_59 -> V_2 ;
F_126 ( & V_2 -> V_78 ) ;
F_127 ( & V_2 -> V_195 ) ;
V_2 -> V_32 = V_32 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_191 = V_188 ;
V_2 -> V_82 = - 1 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_14 = V_30 & 0xff ;
F_121 ( V_2 ) ;
V_2 -> V_71 = V_9 ;
V_2 -> V_196 = V_196 ;
F_128 ( & V_2 -> V_197 ) ;
F_129 ( & V_59 -> V_64 , F_29 ) ;
F_128 ( & V_59 -> V_100 ) ;
F_94 ( V_2 ) ;
F_130 ( & V_59 -> V_137 ) ;
F_119 ( V_2 , F_117 ( V_2 , V_198 [ V_9 ] ) ) ;
F_120 ( V_2 , V_9 ) ;
V_2 -> V_199 = V_199 ;
V_2 -> V_44 = V_200 ;
F_122 ( V_2 ) ;
if ( V_70 [ V_9 ] < 0 ) {
switch ( V_2 -> V_14 ) {
case V_201 :
case V_202 :
V_70 [ V_9 ] = 1 ;
break;
default:
V_70 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_70 = V_70 ;
V_142 = F_131 ( V_32 , V_203 , V_2 , & V_191 ) ;
if ( V_142 < 0 ) {
F_39 ( V_32 -> V_9 , L_31 ) ;
F_100 ( V_2 ) ;
return V_142 ;
}
F_129 ( & V_59 -> V_186 , F_123 ) ;
* V_189 = V_2 ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_71 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_111 * V_32 = V_2 -> V_32 ;
int V_142 ;
unsigned short V_204 ;
unsigned int V_205 = 64 ;
#if V_206 != 64
if ( V_2 -> V_14 == V_207 ) {
T_4 V_208 ;
F_16 ( V_25 , 0x40 , & V_208 ) ;
F_17 ( V_25 , 0x40 , V_208 | 0x10 ) ;
F_133 ( V_25 , V_209 , 0 ) ;
}
#endif
V_142 = F_134 ( V_25 , L_32 ) ;
if ( V_142 < 0 )
return V_142 ;
V_2 -> V_147 = 1 ;
V_2 -> V_130 = F_135 ( V_25 , 0 ) ;
V_2 -> V_96 = F_136 ( V_25 , 0 ) ;
if ( V_2 -> V_96 == NULL ) {
F_39 ( V_32 -> V_9 , L_33 ) ;
return - V_210 ;
}
if ( V_2 -> V_84 ) {
if ( V_2 -> V_30 & V_211 ) {
F_15 ( V_32 -> V_9 , L_34 ) ;
V_25 -> V_212 = true ;
}
if ( F_75 ( V_25 ) < 0 )
V_2 -> V_84 = 0 ;
}
if ( F_37 ( V_2 , 0 ) < 0 )
return - V_134 ;
F_74 ( V_25 ) ;
F_137 ( V_2 -> V_82 ) ;
V_204 = F_80 ( V_2 , V_213 ) ;
F_15 ( V_32 -> V_9 , L_35 , V_204 ) ;
if ( V_2 -> V_25 -> V_151 == V_153 )
V_205 = 40 ;
if ( V_2 -> V_25 -> V_151 == V_152 ) {
struct V_24 * V_214 ;
V_205 = 40 ;
V_214 = F_138 ( V_152 ,
V_215 ,
NULL ) ;
if ( V_214 ) {
if ( V_214 -> V_183 < 0x30 )
V_204 &= ~ V_216 ;
F_96 ( V_214 ) ;
}
}
if ( V_2 -> V_30 & V_217 ) {
F_15 ( V_32 -> V_9 , L_36 ) ;
V_204 &= ~ V_216 ;
}
if ( V_218 >= 0 )
V_2 -> V_218 = ! ! V_218 ;
else {
if ( V_2 -> V_30 & V_219 )
V_2 -> V_218 = 0 ;
else if ( V_2 -> V_30 & V_220 )
V_2 -> V_218 = 1 ;
else
V_2 -> V_218 = 1 ;
}
if ( ! ( V_204 & V_216 ) )
V_205 = 32 ;
if ( ! F_139 ( V_25 , F_140 ( V_205 ) ) ) {
F_141 ( V_25 , F_140 ( V_205 ) ) ;
} else {
F_139 ( V_25 , F_140 ( 32 ) ) ;
F_141 ( V_25 , F_140 ( 32 ) ) ;
}
V_2 -> V_221 = ( V_204 >> 8 ) & 0x0f ;
V_2 -> V_222 = ( V_204 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_222 && ! V_2 -> V_221 ) {
switch ( V_2 -> V_14 ) {
case V_207 :
V_2 -> V_222 = V_223 ;
V_2 -> V_221 = V_224 ;
break;
case V_225 :
case V_184 :
V_2 -> V_222 = V_226 ;
V_2 -> V_221 = V_227 ;
break;
case V_228 :
default:
V_2 -> V_222 = V_229 ;
V_2 -> V_221 = V_230 ;
break;
}
}
V_2 -> V_231 = 0 ;
V_2 -> V_232 = V_2 -> V_221 ;
V_2 -> V_79 = V_2 -> V_222 + V_2 -> V_221 ;
V_2 -> V_20 = F_142 ( V_2 -> V_79 , sizeof( * V_2 -> V_20 ) ,
V_193 ) ;
if ( ! V_2 -> V_20 ) {
F_39 ( V_32 -> V_9 , L_37 ) ;
return - V_194 ;
}
V_142 = F_143 ( V_2 ) ;
if ( V_142 < 0 )
return V_142 ;
F_144 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_30 & V_119 )
F_71 ( V_2 ) ;
F_76 ( V_2 , ( V_233 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_178 ) {
F_39 ( V_32 -> V_9 , L_38 ) ;
return - V_234 ;
}
strcpy ( V_32 -> V_235 , L_39 ) ;
F_145 ( V_32 -> V_236 , V_237 [ V_2 -> V_14 ] ,
sizeof( V_32 -> V_236 ) ) ;
snprintf ( V_32 -> V_238 , sizeof( V_32 -> V_238 ) ,
L_40 ,
V_32 -> V_236 , V_2 -> V_130 , V_2 -> V_82 ) ;
return 0 ;
}
static void F_146 ( struct V_1 * V_2 )
{
#ifdef F_147
struct V_104 * V_127 ;
F_54 (codec, &chip->bus->codec_list, list) {
F_148 ( V_127 ) ;
}
#endif
}
static void F_149 ( const struct V_239 * V_148 , void * V_240 )
{
struct V_111 * V_32 = V_240 ;
struct V_1 * V_2 = V_32 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_148 ) {
F_39 ( V_32 -> V_9 , L_41 ) ;
goto error;
}
V_2 -> V_148 = V_148 ;
if ( ! V_2 -> V_109 ) {
if ( F_87 ( V_2 ) )
goto error;
}
return;
error:
F_150 ( V_32 ) ;
F_151 ( V_25 , NULL ) ;
}
static void F_152 ( T_1 V_168 , T_1 T_5 * V_130 )
{
F_153 ( V_168 , V_130 ) ;
}
static T_1 F_154 ( T_1 T_5 * V_130 )
{
return F_155 ( V_130 ) ;
}
static void F_156 ( T_4 V_168 , T_4 T_5 * V_130 )
{
F_157 ( V_168 , V_130 ) ;
}
static T_4 F_158 ( T_4 T_5 * V_130 )
{
return F_45 ( V_130 ) ;
}
static void F_159 ( T_3 V_168 , T_3 T_5 * V_130 )
{
F_160 ( V_168 , V_130 ) ;
}
static T_3 F_161 ( T_3 T_5 * V_130 )
{
return F_162 ( V_130 ) ;
}
static int F_163 ( struct V_1 * V_2 )
{
int V_142 ;
F_64 ( V_2 -> V_82 , V_2 ) ;
V_2 -> V_82 = - 1 ;
F_65 ( V_2 -> V_25 ) ;
V_2 -> V_84 = 0 ;
V_142 = F_37 ( V_2 , 1 ) ;
if ( V_142 < 0 )
return V_142 ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 ,
int type ,
T_6 V_241 ,
struct V_3 * V_19 )
{
int V_142 ;
V_142 = F_165 ( type ,
V_2 -> V_32 -> V_9 ,
V_241 , V_19 ) ;
if ( V_142 < 0 )
return V_142 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_166 ( struct V_1 * V_2 , struct V_3 * V_19 )
{
F_8 ( V_2 , V_19 , false ) ;
F_167 ( V_19 ) ;
}
static int F_168 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_241 )
{
struct V_20 * V_20 = F_169 ( V_22 ) ;
int V_108 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_20 -> V_53 = 0 ;
V_20 -> V_54 = 0 ;
V_20 -> V_242 = 0 ;
V_108 = F_170 ( V_22 , V_241 ) ;
if ( V_108 < 0 )
return V_108 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_171 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_169 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_172 ( V_22 ) ;
}
static void F_173 ( struct V_21 * V_22 ,
struct V_243 * V_7 )
{
#ifdef F_174
struct V_112 * V_244 = F_175 ( V_22 ) ;
struct V_1 * V_2 = V_244 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_245 = F_176 ( V_7 -> V_245 ) ;
#endif
}
static int F_177 ( struct V_24 * V_25 ,
const struct V_246 * V_247 )
{
static int V_9 ;
struct V_111 * V_32 ;
struct V_58 * V_59 ;
struct V_1 * V_2 ;
bool V_248 ;
int V_142 ;
if ( V_9 >= V_249 )
return - V_234 ;
if ( ! V_250 [ V_9 ] ) {
V_9 ++ ;
return - V_251 ;
}
V_142 = F_178 ( & V_25 -> V_9 , V_252 [ V_9 ] , V_253 [ V_9 ] , V_254 ,
0 , & V_32 ) ;
if ( V_142 < 0 ) {
F_39 ( & V_25 -> V_9 , L_42 ) ;
return V_142 ;
}
V_142 = F_124 ( V_32 , V_25 , V_9 , V_247 -> V_255 ,
& V_256 , & V_2 ) ;
if ( V_142 < 0 )
goto V_257;
V_32 -> V_13 = V_2 ;
V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
F_151 ( V_25 , V_32 ) ;
V_142 = F_97 ( V_2 ) ;
if ( V_142 < 0 ) {
F_39 ( V_32 -> V_9 , L_43 ) ;
goto V_257;
}
if ( F_115 ( V_25 ) ) {
F_20 ( V_32 -> V_9 , L_44 ) ;
F_20 ( V_32 -> V_9 , L_45 ) ;
V_2 -> V_109 = true ;
}
V_248 = ! V_2 -> V_109 ;
#ifdef F_109
if ( V_258 [ V_9 ] && * V_258 [ V_9 ] ) {
F_20 ( V_32 -> V_9 , L_46 ,
V_258 [ V_9 ] ) ;
V_142 = F_179 ( V_254 , true , V_258 [ V_9 ] ,
& V_25 -> V_9 , V_193 , V_32 ,
F_149 ) ;
if ( V_142 < 0 )
goto V_257;
V_248 = false ;
}
#endif
#ifndef F_180
if ( V_2 -> V_30 & V_119 )
F_39 ( V_32 -> V_9 , L_47 ) ;
#endif
if ( V_248 )
F_181 ( & V_59 -> V_186 ) ;
V_9 ++ ;
if ( V_2 -> V_109 )
F_102 ( & V_59 -> V_137 ) ;
return 0 ;
V_257:
F_150 ( V_32 ) ;
return V_142 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_58 * V_59 = F_23 ( V_2 , struct V_58 , V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_71 ;
int V_142 ;
if ( V_2 -> V_30 & V_119 ) {
#ifdef F_180
V_142 = F_182 () ;
if ( V_142 < 0 ) {
F_39 ( V_2 -> V_32 -> V_9 ,
L_48 ) ;
goto V_257;
}
V_142 = F_69 ( true ) ;
if ( V_142 < 0 ) {
F_39 ( V_2 -> V_32 -> V_9 ,
L_49 ) ;
goto V_257;
}
#endif
}
V_142 = F_132 ( V_2 ) ;
if ( V_142 < 0 )
goto V_257;
#ifdef F_183
V_2 -> V_259 = V_259 [ V_9 ] ;
#endif
V_142 = F_184 ( V_2 , V_260 [ V_9 ] ,
V_261 [ V_2 -> V_14 ] ,
V_262 ) ;
if ( V_142 < 0 )
goto V_257;
#ifdef F_109
if ( V_2 -> V_148 ) {
V_142 = F_185 ( V_2 -> V_62 , V_2 -> V_148 -> V_241 ,
V_2 -> V_148 -> V_29 ) ;
if ( V_142 < 0 )
goto V_257;
#ifndef F_147
F_110 ( V_2 -> V_148 ) ;
V_2 -> V_148 = NULL ;
#endif
}
#endif
if ( ( V_233 [ V_9 ] & 1 ) == 0 ) {
V_142 = F_186 ( V_2 ) ;
if ( V_142 < 0 )
goto V_257;
}
V_142 = F_187 ( V_2 -> V_62 ) ;
if ( V_142 < 0 )
goto V_257;
V_142 = F_188 ( V_2 ) ;
if ( V_142 < 0 )
goto V_257;
V_142 = F_189 ( V_2 -> V_32 ) ;
if ( V_142 < 0 )
goto V_257;
V_2 -> V_80 = 1 ;
F_146 ( V_2 ) ;
F_190 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( ( V_2 -> V_30 & V_123 ) || V_59 -> V_141 )
F_191 ( & V_25 -> V_9 ) ;
V_257:
if ( V_142 < 0 )
V_59 -> V_114 = 1 ;
F_102 ( & V_59 -> V_137 ) ;
return V_142 ;
}
static void F_192 ( struct V_24 * V_25 )
{
struct V_111 * V_32 = F_85 ( V_25 ) ;
if ( V_32 )
F_150 ( V_32 ) ;
}
