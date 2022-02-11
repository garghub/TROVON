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
int V_30 = F_15 ( V_2 ) ;
if ( ! ( V_2 -> V_31 & V_32 ) ) {
F_16 ( V_2 -> V_33 -> V_9 , L_1 ) ;
F_11 ( V_2 -> V_25 , V_34 , 0x07 , 0 ) ;
}
if ( V_30 == V_35 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_2 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_25 ,
V_36 , 0x07 ,
F_2 ( V_2 ) ? V_37 : 0 ) ;
}
if ( V_30 == V_38 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_3 ,
F_2 ( V_2 ) ) ;
F_11 ( V_2 -> V_25 ,
V_39 ,
0x0f , V_40 ) ;
F_11 ( V_2 -> V_25 ,
V_41 ,
0x01 , V_42 ) ;
F_11 ( V_2 -> V_25 ,
V_43 ,
0x01 , V_42 ) ;
}
if ( V_30 == V_44 ) {
unsigned short V_45 ;
F_17 ( V_2 -> V_25 , V_46 , & V_45 ) ;
if ( ( ! F_2 ( V_2 ) && ! ( V_45 & V_47 ) ) ||
( F_2 ( V_2 ) && ( V_45 & V_47 ) ) ) {
V_45 &= ~ V_47 ;
if ( ! F_2 ( V_2 ) )
V_45 |= V_47 ;
F_18 ( V_2 -> V_25 , V_46 , V_45 ) ;
F_17 ( V_2 -> V_25 ,
V_46 , & V_45 ) ;
}
F_16 ( V_2 -> V_33 -> V_9 , L_4 ,
( V_45 & V_47 ) ?
L_5 : L_6 ) ;
}
}
static int F_19 ( struct V_1 * V_2 , struct V_20 * V_20 ,
unsigned int V_48 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
int V_49 = V_22 -> V_49 ;
unsigned int V_50 = F_20 ( V_2 , V_20 ) ;
int V_51 ;
if ( V_49 == V_52 )
V_51 = V_48 - V_50 ;
else
V_51 = V_50 - V_48 ;
if ( V_51 < 0 ) {
if ( V_51 >= V_20 -> V_53 )
V_51 = 0 ;
else
V_51 += V_20 -> V_54 ;
}
if ( V_51 >= V_20 -> V_55 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_7 ,
V_51 , V_20 -> V_55 ) ;
V_51 = 0 ;
V_2 -> V_31 &= ~ V_56 ;
V_2 -> V_57 [ V_49 ] = NULL ;
}
return F_22 ( V_22 -> V_58 , V_51 ) ;
}
static int F_23 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_61 ;
V_61 = F_25 ( V_2 , V_20 ) ;
if ( V_61 == 1 ) {
V_20 -> V_62 = 0 ;
return V_61 ;
} else if ( V_61 == 0 ) {
V_20 -> V_62 = 1 ;
F_26 ( & V_60 -> V_63 ) ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_20 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_22 ;
int V_49 = V_22 -> V_49 ;
T_1 V_64 ;
unsigned int V_48 ;
V_64 = F_27 ( V_2 , V_65 ) - V_20 -> V_66 ;
if ( V_64 < ( V_20 -> V_67 * 2 ) / 3 )
return - 1 ;
if ( V_2 -> V_68 [ V_49 ] )
V_48 = V_2 -> V_68 [ V_49 ] ( V_2 , V_20 ) ;
else {
V_48 = F_28 ( V_2 , V_20 ) ;
if ( ! V_48 || V_48 == ( T_1 ) - 1 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_8 ) ;
V_2 -> V_68 [ V_49 ] = F_20 ;
V_48 = F_20 ( V_2 , V_20 ) ;
V_2 -> V_57 [ V_49 ] = NULL ;
} else {
V_2 -> V_68 [ V_49 ] = F_28 ;
if ( V_2 -> V_31 & V_56 )
V_2 -> V_57 [ V_49 ] = F_19 ;
}
}
if ( V_48 >= V_20 -> V_54 )
V_48 = 0 ;
if ( F_29 ( ! V_20 -> V_55 ,
L_9 ) )
return - 1 ;
if ( V_64 < ( V_20 -> V_67 * 5 ) / 4 &&
V_48 % V_20 -> V_55 > V_20 -> V_55 / 2 )
return V_2 -> V_69 [ V_2 -> V_70 ] ? 0 : - 1 ;
V_20 -> V_66 += V_64 ;
return 1 ;
}
static void F_30 ( struct V_71 * V_72 )
{
struct V_59 * V_60 = F_24 ( V_72 , struct V_59 , V_63 ) ;
struct V_1 * V_2 = & V_60 -> V_2 ;
int V_73 , V_74 , V_61 ;
if ( ! V_60 -> V_75 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_10 ,
V_2 -> V_33 -> V_76 ) ;
V_60 -> V_75 = 1 ;
}
for (; ; ) {
V_74 = 0 ;
F_31 ( & V_2 -> V_77 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_78 ; V_73 ++ ) {
struct V_20 * V_20 = & V_2 -> V_20 [ V_73 ] ;
if ( ! V_20 -> V_62 ||
! V_20 -> V_22 ||
! V_20 -> V_79 )
continue;
V_61 = F_25 ( V_2 , V_20 ) ;
if ( V_61 > 0 ) {
V_20 -> V_62 = 0 ;
F_32 ( & V_2 -> V_77 ) ;
F_33 ( V_20 -> V_22 ) ;
F_34 ( & V_2 -> V_77 ) ;
} else if ( V_61 < 0 ) {
V_74 = 0 ;
} else
V_74 ++ ;
}
F_35 ( & V_2 -> V_77 ) ;
if ( ! V_74 )
return;
F_36 ( 1 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
int V_73 ;
F_31 ( & V_2 -> V_77 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_78 ; V_73 ++ )
V_2 -> V_20 [ V_73 ] . V_62 = 0 ;
F_35 ( & V_2 -> V_77 ) ;
}
static int F_38 ( struct V_1 * V_2 , int V_80 )
{
if ( F_39 ( V_2 -> V_25 -> V_81 , V_82 ,
V_2 -> V_83 ? 0 : V_84 ,
V_85 , V_2 ) ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_11 ,
V_2 -> V_25 -> V_81 ) ;
if ( V_80 )
F_41 ( V_2 -> V_33 ) ;
return - 1 ;
}
V_2 -> V_81 = V_2 -> V_25 -> V_81 ;
F_42 ( V_2 -> V_25 , ! V_2 -> V_83 ) ;
return 0 ;
}
static unsigned int F_43 ( struct V_1 * V_2 ,
struct V_20 * V_20 )
{
unsigned int V_86 , V_87 , V_88 ;
unsigned int V_89 , V_90 , V_91 ;
unsigned int V_92 ;
V_86 = F_44 ( V_2 , V_20 , V_93 ) ;
if ( V_20 -> V_22 -> V_49 == V_52 ) {
return V_86 ;
}
V_90 = F_45 ( * V_20 -> V_94 ) ;
V_90 %= V_20 -> V_55 ;
V_92 = F_46 ( V_2 -> V_95 + V_96 ) ;
if ( V_20 -> V_97 ) {
if ( V_86 <= V_92 )
return 0 ;
V_20 -> V_97 = 0 ;
}
if ( V_86 <= V_92 )
V_87 = V_20 -> V_54 + V_86 - V_92 ;
else
V_87 = V_86 - V_92 ;
V_91 = V_87 % V_20 -> V_55 ;
V_89 = V_86 % V_20 -> V_55 ;
if ( V_89 >= V_92 )
V_88 = V_86 - V_89 ;
else if ( V_90 >= V_91 )
V_88 = V_87 - V_91 ;
else {
V_88 = V_87 - V_91 + V_20 -> V_55 ;
if ( V_88 >= V_20 -> V_54 )
V_88 = 0 ;
}
return V_88 + V_90 ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_48 ( & V_98 ) ;
F_49 ( & V_60 -> V_99 , & V_100 ) ;
F_50 ( & V_98 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_48 ( & V_98 ) ;
F_52 ( & V_60 -> V_99 ) ;
F_50 ( & V_98 ) ;
}
static int F_53 ( const char * V_28 , const struct V_101 * V_102 )
{
struct V_59 * V_60 ;
struct V_1 * V_2 ;
int V_103 = V_104 ;
int V_105 = F_54 ( V_28 , V_102 ) ;
if ( V_105 || V_103 == V_104 )
return V_105 ;
F_48 ( & V_98 ) ;
F_55 (hda, &card_list, list) {
V_2 = & V_60 -> V_2 ;
if ( ! V_2 -> V_106 || V_2 -> V_107 )
continue;
F_56 ( V_2 -> V_106 , V_104 * 1000 ) ;
}
F_50 ( & V_98 ) ;
return 0 ;
}
static int F_57 ( struct V_108 * V_9 )
{
struct V_109 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_107 || V_60 -> V_110 )
return 0 ;
F_59 ( V_33 , V_111 ) ;
F_37 ( V_2 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_81 >= 0 ) {
F_62 ( V_2 -> V_81 , V_2 ) ;
V_2 -> V_81 = - 1 ;
}
if ( V_2 -> V_83 )
F_63 ( V_2 -> V_25 ) ;
if ( V_2 -> V_31 & V_112 )
F_64 ( V_60 , false ) ;
return 0 ;
}
static int F_65 ( struct V_108 * V_9 )
{
struct V_24 * V_25 = F_66 ( V_9 ) ;
struct V_109 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_107 || V_60 -> V_110 )
return 0 ;
if ( V_2 -> V_31 & V_112 ) {
F_64 ( V_60 , true ) ;
F_67 ( V_60 ) ;
}
if ( V_2 -> V_83 )
if ( F_68 ( V_25 ) < 0 )
V_2 -> V_83 = 0 ;
if ( F_38 ( V_2 , 1 ) < 0 )
return - V_113 ;
F_14 ( V_2 ) ;
F_69 ( V_2 , true ) ;
F_59 ( V_33 , V_114 ) ;
return 0 ;
}
static int F_70 ( struct V_108 * V_9 )
{
struct V_109 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_107 || V_60 -> V_110 )
return 0 ;
if ( ! F_71 ( V_2 ) )
return 0 ;
F_72 ( V_2 , V_115 , F_73 ( V_2 , V_115 ) |
V_116 ) ;
F_60 ( V_2 ) ;
F_61 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_31 & V_112 )
F_64 ( V_60 , false ) ;
return 0 ;
}
static int F_74 ( struct V_108 * V_9 )
{
struct V_109 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_117 * V_106 ;
struct V_118 * V_119 ;
int V_120 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_107 || V_60 -> V_110 )
return 0 ;
if ( ! F_71 ( V_2 ) )
return 0 ;
if ( V_2 -> V_31 & V_112 ) {
F_64 ( V_60 , true ) ;
F_67 ( V_60 ) ;
}
V_120 = F_73 ( V_2 , V_121 ) ;
F_14 ( V_2 ) ;
F_69 ( V_2 , true ) ;
V_106 = V_2 -> V_106 ;
if ( V_120 && V_106 ) {
F_75 (codec, bus)
if ( V_120 & ( 1 << V_119 -> V_122 ) )
F_76 ( & V_119 -> V_123 ,
V_119 -> V_124 ) ;
}
F_72 ( V_2 , V_115 , F_73 ( V_2 , V_115 ) &
~ V_116 ) ;
return 0 ;
}
static int F_77 ( struct V_108 * V_9 )
{
struct V_109 * V_33 = F_58 ( V_9 ) ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
if ( ! V_33 )
return 0 ;
V_2 = V_33 -> V_13 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
if ( V_2 -> V_107 || V_60 -> V_110 )
return 0 ;
if ( ! V_125 || ! F_71 ( V_2 ) ||
V_2 -> V_106 -> V_126 . V_127 )
return - V_128 ;
return 0 ;
}
static void F_78 ( struct V_24 * V_25 ,
enum V_129 V_130 )
{
struct V_109 * V_33 = F_79 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
bool V_107 ;
F_80 ( & V_60 -> V_131 ) ;
if ( V_60 -> V_110 )
return;
V_107 = ( V_130 == V_132 ) ;
if ( V_2 -> V_107 == V_107 )
return;
if ( ! V_2 -> V_106 ) {
V_2 -> V_107 = V_107 ;
if ( ! V_107 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_12 ) ;
if ( F_81 ( V_2 ) < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 , L_13 ) ;
V_60 -> V_110 = true ;
}
}
} else {
F_21 ( V_2 -> V_33 -> V_9 , L_14 ,
V_107 ? L_15 : L_16 ) ;
if ( V_107 ) {
F_82 ( V_33 -> V_9 ) ;
F_57 ( V_33 -> V_9 ) ;
V_25 -> V_133 = V_134 ;
V_2 -> V_107 = true ;
if ( F_83 ( V_2 -> V_106 ) )
F_84 ( V_2 -> V_33 -> V_9 ,
L_17 ) ;
} else {
F_85 ( V_2 -> V_106 ) ;
F_86 ( V_33 -> V_9 ) ;
V_2 -> V_107 = false ;
F_65 ( V_33 -> V_9 ) ;
}
}
}
static bool F_87 ( struct V_24 * V_25 )
{
struct V_109 * V_33 = F_79 ( V_25 ) ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_80 ( & V_60 -> V_131 ) ;
if ( V_60 -> V_110 )
return false ;
if ( V_2 -> V_107 || ! V_2 -> V_106 )
return true ;
if ( F_83 ( V_2 -> V_106 ) )
return false ;
F_85 ( V_2 -> V_106 ) ;
return true ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
struct V_24 * V_135 = F_89 ( V_2 -> V_25 ) ;
if ( V_135 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_18 ) ;
V_60 -> V_136 = 1 ;
F_90 ( V_135 ) ;
}
}
static int F_91 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_137 ;
if ( ! V_60 -> V_136 )
return 0 ;
V_137 = F_92 ( V_2 -> V_25 , & V_138 ,
V_139 ,
V_2 -> V_106 != NULL ) ;
if ( V_137 < 0 )
return V_137 ;
V_60 -> V_140 = 1 ;
F_93 ( V_2 -> V_33 -> V_9 ,
& V_60 -> V_141 ) ;
return 0 ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
int V_73 ;
if ( F_71 ( V_2 ) && V_2 -> V_79 )
F_86 ( & V_25 -> V_9 ) ;
F_51 ( V_2 ) ;
V_60 -> V_110 = 1 ;
F_95 ( & V_60 -> V_131 ) ;
if ( V_136 ( V_60 ) ) {
if ( V_2 -> V_107 && V_2 -> V_106 )
F_85 ( V_2 -> V_106 ) ;
if ( V_60 -> V_140 )
F_96 ( V_2 -> V_25 ) ;
}
if ( V_2 -> V_142 ) {
F_37 ( V_2 ) ;
for ( V_73 = 0 ; V_73 < V_2 -> V_78 ; V_73 ++ )
F_97 ( V_2 , & V_2 -> V_20 [ V_73 ] ) ;
F_60 ( V_2 ) ;
}
if ( V_2 -> V_81 >= 0 )
F_62 ( V_2 -> V_81 , ( void * ) V_2 ) ;
if ( V_2 -> V_83 )
F_63 ( V_2 -> V_25 ) ;
F_98 ( V_2 -> V_95 ) ;
F_99 ( V_2 ) ;
if ( V_2 -> V_143 )
F_100 ( V_2 -> V_25 ) ;
F_101 ( V_2 -> V_25 ) ;
F_102 ( V_2 -> V_20 ) ;
#ifdef F_103
F_104 ( V_2 -> V_144 ) ;
#endif
if ( V_2 -> V_31 & V_112 ) {
F_64 ( V_60 , false ) ;
F_105 ( V_60 ) ;
}
F_102 ( V_60 ) ;
return 0 ;
}
static int F_106 ( struct V_145 * V_108 )
{
return F_94 ( V_108 -> V_146 ) ;
}
static struct V_24 * F_89 ( struct V_24 * V_25 )
{
struct V_24 * V_135 ;
switch ( V_25 -> V_147 ) {
case V_148 :
case V_149 :
case V_150 :
if ( V_25 -> V_151 == 1 ) {
V_135 = F_107 ( F_108 ( V_25 -> V_106 ) ,
V_25 -> V_106 -> V_76 , 0 ) ;
if ( V_135 ) {
if ( ( V_135 -> V_152 >> 8 ) == V_153 )
return V_135 ;
F_90 ( V_135 ) ;
}
}
break;
}
return NULL ;
}
static bool F_109 ( struct V_24 * V_25 )
{
bool V_154 = false ;
struct V_24 * V_135 = F_89 ( V_25 ) ;
if ( V_135 ) {
if ( F_110 ( V_135 ) == V_132 )
V_154 = true ;
F_90 ( V_135 ) ;
}
return V_154 ;
}
static int F_111 ( struct V_1 * V_2 , int V_155 )
{
const struct V_156 * V_157 ;
switch ( V_155 ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
return V_155 ;
}
V_157 = F_112 ( V_2 -> V_25 , V_163 ) ;
if ( V_157 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_19 ,
V_157 -> V_164 , V_157 -> V_165 , V_157 -> V_166 ) ;
return V_157 -> V_164 ;
}
if ( V_2 -> V_31 & V_167 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_20 ) ;
return V_161 ;
}
if ( V_2 -> V_31 & V_168 ) {
F_16 ( V_2 -> V_33 -> V_9 , L_21 ) ;
return V_159 ;
}
return V_158 ;
}
static void F_113 ( struct V_1 * V_2 , int V_155 )
{
static T_2 V_169 [] = {
[ V_158 ] = NULL ,
[ V_159 ] = F_20 ,
[ V_160 ] = F_28 ,
[ V_161 ] = F_43 ,
[ V_162 ] = F_20 ,
} ;
V_2 -> V_68 [ 0 ] = V_2 -> V_68 [ 1 ] = V_169 [ V_155 ] ;
if ( V_155 == V_162 )
V_2 -> V_68 [ 1 ] = NULL ;
if ( V_155 == V_160 &&
( V_2 -> V_31 & V_56 ) ) {
V_2 -> V_57 [ 0 ] = V_2 -> V_57 [ 1 ] =
F_19 ;
}
}
static void F_114 ( struct V_1 * V_2 , int V_9 )
{
const struct V_156 * V_157 ;
V_2 -> V_170 = V_171 [ V_9 ] ;
if ( V_2 -> V_170 == - 1 ) {
V_157 = F_112 ( V_2 -> V_25 , V_172 ) ;
if ( V_157 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_22 ,
V_157 -> V_164 , V_157 -> V_165 , V_157 -> V_166 ) ;
V_2 -> V_170 = V_157 -> V_164 ;
}
}
if ( V_2 -> V_170 != - 1 &&
( V_2 -> V_170 & V_173 ) ) {
V_2 -> V_174 = V_2 -> V_170 & 0xff ;
F_21 ( V_2 -> V_33 -> V_9 , L_23 ,
V_2 -> V_174 ) ;
}
}
static void F_115 ( struct V_1 * V_2 )
{
const struct V_156 * V_157 ;
if ( V_175 >= 0 ) {
V_2 -> V_83 = ! ! V_175 ;
return;
}
V_2 -> V_83 = 1 ;
V_157 = F_112 ( V_2 -> V_25 , V_176 ) ;
if ( V_157 ) {
F_21 ( V_2 -> V_33 -> V_9 ,
L_24 ,
V_157 -> V_165 , V_157 -> V_166 , V_157 -> V_164 ) ;
V_2 -> V_83 = V_157 -> V_164 ;
return;
}
if ( V_2 -> V_31 & V_177 ) {
F_21 ( V_2 -> V_33 -> V_9 , L_25 ) ;
V_2 -> V_83 = 0 ;
}
}
static void F_116 ( struct V_1 * V_2 )
{
int V_45 = V_178 ;
if ( V_45 >= 0 ) {
F_21 ( V_2 -> V_33 -> V_9 , L_26 ,
V_45 ? L_27 : L_28 ) ;
V_2 -> V_45 = V_45 ;
return;
}
V_45 = true ;
if ( F_15 ( V_2 ) == V_179 &&
V_2 -> V_14 == V_180 ) {
T_3 V_28 ;
F_12 ( V_2 -> V_25 , 0x42 , & V_28 ) ;
if ( ! ( V_28 & 0x80 ) && V_2 -> V_25 -> V_181 == 0x30 )
V_45 = false ;
}
if ( V_2 -> V_31 & V_182 )
V_45 = false ;
V_2 -> V_45 = V_45 ;
if ( ! V_45 )
F_21 ( V_2 -> V_33 -> V_9 , L_29 ) ;
}
static void F_117 ( struct V_71 * V_72 )
{
struct V_59 * V_60 = F_24 ( V_72 , struct V_59 , V_183 ) ;
F_81 ( & V_60 -> V_2 ) ;
}
static int F_118 ( struct V_109 * V_33 , struct V_24 * V_25 ,
int V_9 , unsigned int V_31 ,
const struct V_184 * V_185 ,
struct V_1 * * V_186 )
{
static struct V_187 V_188 = {
. V_189 = F_106 ,
} ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
int V_137 ;
* V_186 = NULL ;
V_137 = F_119 ( V_25 ) ;
if ( V_137 < 0 )
return V_137 ;
V_60 = F_120 ( sizeof( * V_60 ) , V_190 ) ;
if ( ! V_60 ) {
F_101 ( V_25 ) ;
return - V_191 ;
}
V_2 = & V_60 -> V_2 ;
F_121 ( & V_2 -> V_77 ) ;
F_122 ( & V_2 -> V_192 ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_25 = V_25 ;
V_2 -> V_188 = V_185 ;
V_2 -> V_81 = - 1 ;
V_2 -> V_31 = V_31 ;
V_2 -> V_14 = V_31 & 0xff ;
F_115 ( V_2 ) ;
V_2 -> V_70 = V_9 ;
V_2 -> V_193 = V_193 ;
F_123 ( & V_2 -> V_194 ) ;
F_124 ( & V_60 -> V_63 , F_30 ) ;
F_123 ( & V_60 -> V_99 ) ;
F_88 ( V_2 ) ;
F_125 ( & V_60 -> V_131 ) ;
F_113 ( V_2 , F_111 ( V_2 , V_195 [ V_9 ] ) ) ;
F_114 ( V_2 , V_9 ) ;
V_2 -> V_196 = V_196 ;
F_116 ( V_2 ) ;
if ( V_69 [ V_9 ] < 0 ) {
switch ( V_2 -> V_14 ) {
case V_197 :
case V_198 :
V_69 [ V_9 ] = 1 ;
break;
default:
V_69 [ V_9 ] = 32 ;
break;
}
}
V_2 -> V_69 = V_69 ;
V_137 = F_126 ( V_33 , V_199 , V_2 , & V_188 ) ;
if ( V_137 < 0 ) {
F_40 ( V_33 -> V_9 , L_30 ) ;
F_94 ( V_2 ) ;
return V_137 ;
}
F_124 ( & V_60 -> V_183 , F_117 ) ;
* V_186 = V_2 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_9 = V_2 -> V_70 ;
struct V_24 * V_25 = V_2 -> V_25 ;
struct V_109 * V_33 = V_2 -> V_33 ;
int V_137 ;
unsigned short V_200 ;
unsigned int V_201 = 64 ;
#if V_202 != 64
if ( V_2 -> V_14 == V_203 ) {
T_4 V_204 ;
F_17 ( V_25 , 0x40 , & V_204 ) ;
F_18 ( V_25 , 0x40 , V_204 | 0x10 ) ;
F_128 ( V_25 , V_205 , 0 ) ;
}
#endif
V_137 = F_129 ( V_25 , L_31 ) ;
if ( V_137 < 0 )
return V_137 ;
V_2 -> V_143 = 1 ;
V_2 -> V_122 = F_130 ( V_25 , 0 ) ;
V_2 -> V_95 = F_131 ( V_25 , 0 ) ;
if ( V_2 -> V_95 == NULL ) {
F_40 ( V_33 -> V_9 , L_32 ) ;
return - V_206 ;
}
if ( V_2 -> V_83 ) {
if ( V_2 -> V_31 & V_207 ) {
F_16 ( V_33 -> V_9 , L_33 ) ;
V_25 -> V_208 = true ;
}
if ( F_68 ( V_25 ) < 0 )
V_2 -> V_83 = 0 ;
}
if ( F_38 ( V_2 , 0 ) < 0 )
return - V_128 ;
F_132 ( V_25 ) ;
F_133 ( V_2 -> V_81 ) ;
V_200 = F_73 ( V_2 , V_209 ) ;
F_16 ( V_33 -> V_9 , L_34 , V_200 ) ;
if ( V_2 -> V_25 -> V_147 == V_149 )
V_201 = 40 ;
if ( V_2 -> V_25 -> V_147 == V_148 ) {
struct V_24 * V_210 ;
V_201 = 40 ;
V_210 = F_134 ( V_148 ,
V_211 ,
NULL ) ;
if ( V_210 ) {
if ( V_210 -> V_181 < 0x30 )
V_200 &= ~ V_212 ;
F_90 ( V_210 ) ;
}
}
if ( V_2 -> V_31 & V_213 ) {
F_16 ( V_33 -> V_9 , L_35 ) ;
V_200 &= ~ V_212 ;
}
if ( V_214 >= 0 )
V_2 -> V_214 = ! ! V_214 ;
else {
if ( V_2 -> V_31 & V_215 )
V_2 -> V_214 = 0 ;
else
V_2 -> V_214 = 1 ;
}
if ( ! ( V_200 & V_212 ) )
V_201 = 32 ;
if ( ! F_135 ( V_25 , F_136 ( V_201 ) ) ) {
F_137 ( V_25 , F_136 ( V_201 ) ) ;
} else {
F_135 ( V_25 , F_136 ( 32 ) ) ;
F_137 ( V_25 , F_136 ( 32 ) ) ;
}
V_2 -> V_216 = ( V_200 >> 8 ) & 0x0f ;
V_2 -> V_217 = ( V_200 >> 12 ) & 0x0f ;
if ( ! V_2 -> V_217 && ! V_2 -> V_216 ) {
switch ( V_2 -> V_14 ) {
case V_203 :
V_2 -> V_217 = V_218 ;
V_2 -> V_216 = V_219 ;
break;
case V_220 :
case V_221 :
V_2 -> V_217 = V_222 ;
V_2 -> V_216 = V_223 ;
break;
case V_224 :
default:
V_2 -> V_217 = V_225 ;
V_2 -> V_216 = V_226 ;
break;
}
}
V_2 -> V_227 = 0 ;
V_2 -> V_228 = V_2 -> V_216 ;
V_2 -> V_78 = V_2 -> V_217 + V_2 -> V_216 ;
V_2 -> V_20 = F_138 ( V_2 -> V_78 , sizeof( * V_2 -> V_20 ) ,
V_190 ) ;
if ( ! V_2 -> V_20 )
return - V_191 ;
V_137 = F_139 ( V_2 ) ;
if ( V_137 < 0 )
return V_137 ;
F_140 ( V_2 ) ;
F_14 ( V_2 ) ;
if ( V_2 -> V_31 & V_112 ) {
struct V_59 * V_60 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_67 ( V_60 ) ;
}
F_69 ( V_2 , ( V_229 [ V_9 ] & 2 ) == 0 ) ;
if ( ! V_2 -> V_174 ) {
F_40 ( V_33 -> V_9 , L_36 ) ;
return - V_230 ;
}
strcpy ( V_33 -> V_231 , L_37 ) ;
F_141 ( V_33 -> V_232 , V_233 [ V_2 -> V_14 ] ,
sizeof( V_33 -> V_232 ) ) ;
snprintf ( V_33 -> V_234 , sizeof( V_33 -> V_234 ) ,
L_38 ,
V_33 -> V_232 , V_2 -> V_122 , V_2 -> V_81 ) ;
return 0 ;
}
static void F_142 ( const struct V_235 * V_144 , void * V_236 )
{
struct V_109 * V_33 = V_236 ;
struct V_1 * V_2 = V_33 -> V_13 ;
struct V_24 * V_25 = V_2 -> V_25 ;
if ( ! V_144 ) {
F_40 ( V_33 -> V_9 , L_39 ) ;
goto error;
}
V_2 -> V_144 = V_144 ;
if ( ! V_2 -> V_107 ) {
if ( F_81 ( V_2 ) )
goto error;
}
return;
error:
F_143 ( V_33 ) ;
F_144 ( V_25 , NULL ) ;
}
static void F_145 ( T_1 V_164 , T_1 T_5 * V_122 )
{
F_146 ( V_164 , V_122 ) ;
}
static T_1 F_147 ( T_1 T_5 * V_122 )
{
return F_148 ( V_122 ) ;
}
static void F_149 ( T_4 V_164 , T_4 T_5 * V_122 )
{
F_150 ( V_164 , V_122 ) ;
}
static T_4 F_151 ( T_4 T_5 * V_122 )
{
return F_46 ( V_122 ) ;
}
static void F_152 ( T_3 V_164 , T_3 T_5 * V_122 )
{
F_153 ( V_164 , V_122 ) ;
}
static T_3 F_154 ( T_3 T_5 * V_122 )
{
return F_155 ( V_122 ) ;
}
static int F_156 ( struct V_1 * V_2 )
{
int V_137 ;
F_62 ( V_2 -> V_81 , V_2 ) ;
V_2 -> V_81 = - 1 ;
F_63 ( V_2 -> V_25 ) ;
V_2 -> V_83 = 0 ;
V_137 = F_38 ( V_2 , 1 ) ;
if ( V_137 < 0 )
return V_137 ;
return 0 ;
}
static int F_157 ( struct V_1 * V_2 ,
int type ,
T_6 V_237 ,
struct V_3 * V_19 )
{
int V_137 ;
V_137 = F_158 ( type ,
V_2 -> V_33 -> V_9 ,
V_237 , V_19 ) ;
if ( V_137 < 0 )
return V_137 ;
F_8 ( V_2 , V_19 , true ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 , struct V_3 * V_19 )
{
F_8 ( V_2 , V_19 , false ) ;
F_160 ( V_19 ) ;
}
static int F_161 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
T_6 V_237 )
{
struct V_20 * V_20 = F_162 ( V_22 ) ;
int V_105 ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
V_20 -> V_54 = 0 ;
V_20 -> V_55 = 0 ;
V_20 -> V_238 = 0 ;
V_105 = F_163 ( V_22 , V_237 ) ;
if ( V_105 < 0 )
return V_105 ;
F_9 ( V_2 , V_20 , V_22 , true ) ;
return 0 ;
}
static int F_164 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_20 * V_20 = F_162 ( V_22 ) ;
F_9 ( V_2 , V_20 , V_22 , false ) ;
return F_165 ( V_22 ) ;
}
static void F_166 ( struct V_21 * V_22 ,
struct V_239 * V_7 )
{
#ifdef F_167
struct V_240 * V_241 = F_168 ( V_22 ) ;
struct V_1 * V_2 = V_241 -> V_2 ;
if ( ! F_2 ( V_2 ) && V_2 -> V_14 != V_15 )
V_7 -> V_242 = F_169 ( V_7 -> V_242 ) ;
#endif
}
static int F_170 ( struct V_24 * V_25 ,
const struct V_243 * V_244 )
{
static int V_9 ;
struct V_109 * V_33 ;
struct V_59 * V_60 ;
struct V_1 * V_2 ;
bool V_245 ;
int V_137 ;
if ( V_9 >= V_246 )
return - V_230 ;
if ( ! V_247 [ V_9 ] ) {
V_9 ++ ;
return - V_248 ;
}
V_137 = F_171 ( & V_25 -> V_9 , V_249 [ V_9 ] , V_250 [ V_9 ] , V_251 ,
0 , & V_33 ) ;
if ( V_137 < 0 ) {
F_40 ( & V_25 -> V_9 , L_40 ) ;
return V_137 ;
}
V_137 = F_118 ( V_33 , V_25 , V_9 , V_244 -> V_252 ,
& V_253 , & V_2 ) ;
if ( V_137 < 0 )
goto V_254;
V_33 -> V_13 = V_2 ;
V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
F_144 ( V_25 , V_33 ) ;
V_137 = F_91 ( V_2 ) ;
if ( V_137 < 0 ) {
F_40 ( V_33 -> V_9 , L_41 ) ;
goto V_254;
}
if ( F_109 ( V_25 ) ) {
F_21 ( V_33 -> V_9 , L_42 ) ;
F_21 ( V_33 -> V_9 , L_43 ) ;
V_2 -> V_107 = true ;
}
V_245 = ! V_2 -> V_107 ;
#ifdef F_103
if ( V_255 [ V_9 ] && * V_255 [ V_9 ] ) {
F_21 ( V_33 -> V_9 , L_44 ,
V_255 [ V_9 ] ) ;
V_137 = F_172 ( V_251 , true , V_255 [ V_9 ] ,
& V_25 -> V_9 , V_190 , V_33 ,
F_142 ) ;
if ( V_137 < 0 )
goto V_254;
V_245 = false ;
}
#endif
#ifndef F_173
if ( V_2 -> V_31 & V_112 )
F_40 ( V_33 -> V_9 , L_45 ) ;
#endif
if ( V_245 )
F_26 ( & V_60 -> V_183 ) ;
V_9 ++ ;
if ( V_2 -> V_107 )
F_95 ( & V_60 -> V_131 ) ;
return 0 ;
V_254:
F_143 ( V_33 ) ;
return V_137 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_59 * V_60 = F_24 ( V_2 , struct V_59 , V_2 ) ;
struct V_24 * V_25 = V_2 -> V_25 ;
int V_9 = V_2 -> V_70 ;
int V_137 ;
if ( V_2 -> V_31 & V_112 ) {
#ifdef F_173
V_137 = F_174 ( V_60 ) ;
if ( V_137 < 0 ) {
if ( F_175 ( V_25 ) )
goto V_254;
else
goto V_256;
}
V_137 = F_64 ( V_60 , true ) ;
if ( V_137 < 0 ) {
F_40 ( V_2 -> V_33 -> V_9 ,
L_46 ) ;
goto V_254;
}
#endif
}
#ifdef F_173
V_256:
#endif
V_137 = F_127 ( V_2 ) ;
if ( V_137 < 0 )
goto V_254;
#ifdef F_176
V_2 -> V_257 = V_257 [ V_9 ] ;
#endif
V_137 = F_177 ( V_2 , V_258 [ V_9 ] ) ;
if ( V_137 < 0 )
goto V_254;
V_137 = F_178 ( V_2 , V_259 [ V_2 -> V_14 ] ) ;
if ( V_137 < 0 )
goto V_254;
#ifdef F_103
if ( V_2 -> V_144 ) {
V_137 = F_179 ( V_2 -> V_106 , V_2 -> V_144 -> V_237 ,
V_2 -> V_144 -> V_29 ) ;
if ( V_137 < 0 )
goto V_254;
#ifndef F_180
F_104 ( V_2 -> V_144 ) ;
V_2 -> V_144 = NULL ;
#endif
}
#endif
if ( ( V_229 [ V_9 ] & 1 ) == 0 ) {
V_137 = F_181 ( V_2 ) ;
if ( V_137 < 0 )
goto V_254;
}
V_137 = F_182 ( V_2 -> V_33 ) ;
if ( V_137 < 0 )
goto V_254;
V_2 -> V_79 = 1 ;
F_47 ( V_2 ) ;
F_56 ( V_2 -> V_106 , V_104 * 1000 ) ;
if ( F_71 ( V_2 ) || V_60 -> V_136 )
F_183 ( & V_25 -> V_9 ) ;
V_254:
if ( V_137 < 0 )
V_60 -> V_110 = 1 ;
F_95 ( & V_60 -> V_131 ) ;
return V_137 ;
}
static void F_184 ( struct V_24 * V_25 )
{
struct V_109 * V_33 = F_79 ( V_25 ) ;
if ( V_33 )
F_143 ( V_33 ) ;
}
static void F_185 ( struct V_24 * V_25 )
{
struct V_109 * V_33 = F_79 ( V_25 ) ;
struct V_1 * V_2 ;
if ( ! V_33 )
return;
V_2 = V_33 -> V_13 ;
if ( V_2 && V_2 -> V_79 )
F_60 ( V_2 ) ;
}
