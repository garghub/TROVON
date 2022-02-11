static unsigned long F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
if ( V_2 -> V_4 == V_5 ) {
V_3 += V_6 ;
if ( V_3 == ( V_6 * V_7 ) )
V_3 = 0 ;
} else {
V_3 += V_8 ;
if ( V_3 == ( V_8 * V_9 ) )
V_3 = 0 ;
}
return V_3 ;
}
static inline bool F_2 ( struct V_1 * V_2 , unsigned int V_10 ,
unsigned long V_11 , unsigned long V_12 )
{
if ( V_11 <= V_12 ) {
if ( V_10 > V_11 && V_10 <= V_12 )
return true ;
} else {
if ( V_10 > V_11 || V_10 <= V_12 )
return true ;
}
return false ;
}
static T_1 F_3 ( int V_13 , void * V_14 )
{
unsigned long V_3 , V_12 , V_15 ;
struct V_1 * V_2 = V_14 ;
F_4 ( L_1 ,
F_5 () , V_2 -> V_16 ) ;
F_6 ( & V_2 -> V_17 ) ;
V_15 = F_7 ( V_2 -> V_16 , & V_12 ) ;
F_4 ( L_2 ,
F_5 () , V_12 , V_15 ) ;
for ( V_3 = V_2 -> V_18 ; V_3 != V_12 ; V_3 = F_1 ( V_2 , V_3 ) ) {
}
V_15 = F_8 ( V_2 -> V_16 , V_12 ) ;
if ( V_15 == V_19 )
V_2 -> V_18 = V_12 ;
F_9 ( & V_2 -> V_17 ) ;
return V_20 ;
}
static T_1 F_10 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
unsigned long V_18 , V_15 ;
F_6 ( & V_2 -> V_17 ) ;
F_4 ( L_3 ,
F_5 () , V_2 -> V_16 ) ;
V_15 = F_7 ( V_2 -> V_16 , & V_18 ) ;
F_4 ( L_4 ,
F_5 () , V_18 , V_15 ) ;
F_8 ( V_2 -> V_16 , V_18 ) ;
F_9 ( & V_2 -> V_17 ) ;
return V_20 ;
}
static void * F_11 ( struct V_1 * V_2 , void * V_21 )
{
return V_2 -> V_2 + F_1 ( V_2 , V_21 - V_2 -> V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
unsigned long V_18 = V_2 -> V_18 ;
unsigned long V_22 = V_2 -> V_22 ;
unsigned long V_23 = ( V_8 * V_9 ) ;
unsigned long V_24 ;
if ( V_18 > V_22 )
V_24 = V_18 - V_22 ;
else
V_24 = ( V_23 - V_22 ) + V_18 ;
return ( V_24 / V_8 ) - 1 ;
}
static void * F_13 ( struct V_1 * V_2 , int V_25 )
{
int V_26 = F_12 ( V_2 ) ;
if ( V_26 >= V_25 )
return V_2 -> V_2 + V_2 -> V_22 ;
return NULL ;
}
static unsigned long F_14 ( struct V_1 * V_2 , void * V_27 )
{
unsigned long V_15 , V_28 ;
V_28 = F_1 ( V_2 , V_27 - V_2 -> V_2 ) ;
V_15 = F_15 ( V_2 -> V_16 , V_28 ) ;
if ( V_15 == V_19 )
V_2 -> V_22 = V_28 ;
return V_15 ;
}
static T_2 F_16 ( unsigned int V_29 , unsigned int V_30 ,
int V_31 , int V_32 ,
unsigned int V_33 ,
bool V_34 , bool V_35 , bool V_36 , bool V_37 ,
int V_38 )
{
T_2 V_39 = ( V_29 - 1 ) & V_40 ;
V_39 |= ( ( T_2 ) V_38 << V_41 ) ;
V_39 |= ( ( T_2 ) V_31 << V_42 ) ;
V_39 |= ( ( T_2 ) V_32 << V_43 ) ;
if ( V_34 )
V_39 |= V_44 ;
if ( V_35 )
V_39 |= V_45 ;
if ( V_36 )
V_39 |= V_46 ;
if ( V_37 )
V_39 |= V_47 ;
if ( V_30 )
V_39 |= ( ( T_2 ) ( V_30 - 1 ) ) << V_48 ;
if ( V_33 )
V_39 |= ( ( T_2 ) ( V_33 - 1 ) ) << V_49 ;
return V_39 ;
}
static inline struct V_50 * V_50 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_56 * V_56 ;
V_56 = F_17 ( V_54 , struct V_56 , V_57 . V_58 ) ;
return F_17 ( V_56 , struct V_50 , V_54 ) ;
}
static inline struct V_59 * V_59 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_56 * V_56 ;
V_56 = F_17 ( V_54 , struct V_56 , V_57 . V_58 ) ;
return F_17 ( V_56 , struct V_59 , V_60 . V_54 ) ;
}
static int F_18 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
return F_23 ( & V_64 -> V_68 ) ;
}
static int F_24 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
return F_25 ( & V_64 -> V_68 ) ;
}
static int F_26 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_27 ( & V_64 -> V_68 ) ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 = V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_29 ( & V_64 -> V_68 ) ;
}
static int F_30 ( struct V_51 * V_52 )
{
const char * V_75 = F_31 ( V_52 ) ;
struct V_65 * V_76 = F_32 ( V_52 ) ;
struct V_66 * V_67 = F_21 ( V_76 ) ;
struct V_65 * V_69 ;
int V_77 ;
V_69 = F_33 ( V_75 , 0 ,
V_78 ) ;
if ( F_34 ( V_69 ) ) {
F_35 ( L_5 ,
V_75 ) ;
V_77 = F_36 ( V_69 ) ;
goto V_79;
}
F_37 ( V_76 , ( sizeof( struct V_63 ) +
F_38 ( V_69 ) ) ) ;
V_67 -> V_69 = V_69 ;
return 0 ;
V_79:
return V_77 ;
}
static void F_39 ( struct V_51 * V_52 )
{
struct V_65 * V_76 = F_32 ( V_52 ) ;
struct V_66 * V_67 = F_21 ( V_76 ) ;
F_40 ( V_67 -> V_69 ) ;
}
static int F_41 ( struct V_51 * V_52 )
{
const char * V_75 = F_31 ( V_52 ) ;
struct V_65 * V_76 = F_32 ( V_52 ) ;
struct V_80 * V_67 = F_21 ( V_76 ) ;
struct V_59 * V_81 = V_59 ( V_52 ) ;
struct V_65 * V_69 ;
struct V_82 * V_83 ;
int V_77 ;
V_69 = F_33 ( V_75 , 0 ,
V_78 ) ;
if ( F_34 ( V_69 ) ) {
F_35 ( L_5 ,
V_75 ) ;
V_77 = F_36 ( V_69 ) ;
goto V_79;
}
V_83 = F_42 ( V_81 -> V_84 , 0 , 0 ) ;
if ( F_34 ( V_83 ) ) {
F_35 ( L_6 ,
V_81 -> V_84 ) ;
V_77 = F_36 ( V_83 ) ;
goto V_85;
}
F_37 ( V_76 , ( sizeof( struct V_63 ) +
F_38 ( V_69 ) ) ) ;
V_67 -> V_83 = V_83 ;
V_67 -> V_58 . V_69 = V_69 ;
return 0 ;
V_85:
F_40 ( V_69 ) ;
V_79:
return V_77 ;
}
static void F_43 ( struct V_51 * V_52 )
{
struct V_65 * V_76 = F_32 ( V_52 ) ;
struct V_80 * V_67 = F_21 ( V_76 ) ;
F_40 ( V_67 -> V_58 . V_69 ) ;
F_44 ( V_67 -> V_83 ) ;
}
static int F_45 ( struct V_65 * V_52 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_80 * V_67 = F_21 ( V_52 ) ;
struct V_82 * V_83 = V_67 -> V_83 ;
struct V_65 * V_69 ;
F_46 ( V_88 , V_83 ) ;
int V_77 , V_89 , V_90 ;
V_69 = V_67 -> V_58 . V_69 ;
V_77 = F_47 ( V_69 , V_86 , V_87 ) ;
if ( V_77 )
return V_77 ;
V_88 -> V_52 = V_83 ;
V_88 -> V_70 = F_48 ( V_52 ) &
V_71 ;
V_89 = F_49 ( V_83 ) ;
V_90 = F_50 ( V_83 ) ;
F_51 ( V_90 > V_91 ) ;
if ( V_87 > V_89 ) {
V_77 = F_52 ( V_88 , V_86 , V_87 ,
V_67 -> V_92 ) ;
if ( V_77 )
return V_77 ;
V_87 = V_90 ;
} else if ( V_87 <= V_91 )
memcpy ( V_67 -> V_92 , V_86 , V_87 ) ;
V_67 -> V_93 = V_87 ;
return V_77 ;
}
static unsigned long F_53 ( struct V_1 * V_94 )
{
unsigned long V_18 , V_15 ;
do {
V_15 = F_7 ( V_94 -> V_16 , & V_18 ) ;
if ( V_15 != V_19 ) {
F_4 ( L_7 ) ;
break;
}
if ( V_18 == V_94 -> V_22 ) {
V_94 -> V_18 = V_18 ;
break;
}
} while ( 1 );
return V_15 ;
}
static unsigned long F_54 ( struct V_1 * V_94 ,
struct V_95 * V_96 )
{
unsigned long V_15 = F_14 ( V_94 , V_96 ) ;
if ( V_15 == V_19 )
V_15 = F_53 ( V_94 ) ;
return V_15 ;
}
static int F_55 ( struct V_61 * V_62 ,
unsigned int V_32 , unsigned int V_97 ,
unsigned int V_98 , void * V_99 ,
unsigned long V_100 , unsigned int V_101 )
{
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_95 * V_96 ;
struct V_102 V_103 ;
struct V_1 * V_94 ;
unsigned long V_70 ;
int V_77 = - V_104 ;
int V_72 , V_105 ;
if ( F_56 ( V_62 -> V_72 > ( 1 << 16 ) ) ) {
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 =
V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_57 ( & V_64 -> V_68 ) ;
}
V_72 = F_58 ( V_62 , & V_103 ) ;
V_105 = F_59 () ;
V_94 = V_106 [ V_105 ] ;
if ( ! V_94 )
goto V_79;
F_60 ( & V_94 -> V_17 , V_70 ) ;
V_96 = V_94 -> V_2 + V_94 -> V_22 ;
V_96 -> V_107 = F_16 ( V_72 , V_101 , 0 ,
V_32 , V_97 ,
false , true , false , false ,
V_108 |
V_109 ) ;
V_96 -> V_110 = F_61 ( V_103 . V_111 ) ;
V_96 -> V_112 = V_100 ;
V_96 -> V_113 = F_61 ( V_99 ) ;
V_96 -> V_114 = 0UL ;
V_96 -> V_115 = 0UL ;
V_96 -> V_116 = 0UL ;
V_96 -> V_117 = F_61 ( V_99 ) ;
V_72 = F_62 ( & V_103 , 0 ) ;
while ( V_72 > 0 ) {
V_96 = F_11 ( V_94 , V_96 ) ;
V_96 -> V_107 = ( V_72 - 1 ) ;
V_96 -> V_110 = F_61 ( V_103 . V_111 ) ;
V_96 -> V_112 = 0UL ;
V_96 -> V_113 = 0UL ;
V_96 -> V_114 = 0UL ;
V_96 -> V_115 = 0UL ;
V_96 -> V_116 = 0UL ;
V_96 -> V_117 = 0UL ;
V_72 = F_62 ( & V_103 , 0 ) ;
}
V_96 -> V_107 |= V_46 ;
if ( F_54 ( V_94 , V_96 ) != V_19 )
V_77 = - V_118 ;
else
V_77 = 0 ;
F_63 ( & V_94 -> V_17 , V_70 ) ;
if ( ! V_77 )
memcpy ( V_62 -> V_74 , V_99 , V_98 ) ;
V_79:
F_64 () ;
return V_77 ;
}
static int F_65 ( struct V_61 * V_62 )
{
struct V_50 * V_81 = V_50 ( V_62 -> V_58 . V_52 ) ;
struct V_63 * V_64 = F_19 ( V_62 ) ;
int V_90 ;
V_90 = V_81 -> V_97 ;
if ( F_56 ( V_62 -> V_72 == 0 ) ) {
memcpy ( V_62 -> V_74 , V_81 -> V_119 , V_90 ) ;
return 0 ;
}
memcpy ( & V_64 -> V_120 , V_81 -> V_121 , V_81 -> V_122 ) ;
return F_55 ( V_62 , V_81 -> V_32 ,
V_81 -> V_122 , V_90 ,
& V_64 -> V_120 , 0UL , 0 ) ;
}
static int F_66 ( struct V_61 * V_62 )
{
struct V_59 * V_81 = V_59 ( V_62 -> V_58 . V_52 ) ;
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_80 * V_67 = F_21 ( V_52 ) ;
int V_90 ;
V_90 = V_81 -> V_60 . V_97 ;
if ( F_56 ( V_62 -> V_72 == 0 ) ||
F_56 ( V_67 -> V_93 > V_91 ) ) {
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_66 * V_67 = F_21 ( V_52 ) ;
F_22 ( & V_64 -> V_68 , V_67 -> V_69 ) ;
V_64 -> V_68 . V_58 . V_70 =
V_62 -> V_58 . V_70 & V_71 ;
V_64 -> V_68 . V_72 = V_62 -> V_72 ;
V_64 -> V_68 . V_73 = V_62 -> V_73 ;
V_64 -> V_68 . V_74 = V_62 -> V_74 ;
return F_57 ( & V_64 -> V_68 ) ;
}
memcpy ( & V_64 -> V_120 , V_81 -> V_60 . V_121 ,
V_81 -> V_60 . V_122 ) ;
return F_55 ( V_62 , V_81 -> V_60 . V_123 ,
V_81 -> V_60 . V_122 , V_90 ,
& V_64 -> V_120 ,
F_61 ( & V_67 -> V_92 ) ,
V_67 -> V_93 ) ;
}
static inline struct V_124 * V_124 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
return F_17 ( V_54 , struct V_124 , V_54 ) ;
}
static int F_67 ( struct V_125 * V_126 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_126 ) ;
struct V_127 * V_67 = F_69 ( V_52 ) ;
struct V_124 * V_81 = V_124 ( V_52 ) ;
V_67 -> V_31 = ( V_81 -> V_31 & V_128 ) ;
switch ( V_87 ) {
case V_129 :
V_67 -> V_31 |= V_130 ;
break;
case V_131 :
V_67 -> V_31 |= V_132 ;
break;
case V_133 :
V_67 -> V_31 |= V_134 ;
break;
default:
F_70 ( V_126 , V_135 ) ;
return - V_118 ;
}
V_67 -> V_136 = V_87 ;
memcpy ( V_67 -> V_86 . V_137 , V_86 , V_87 ) ;
return 0 ;
}
static int F_71 ( struct V_125 * V_126 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_126 ) ;
struct V_127 * V_67 = F_69 ( V_52 ) ;
struct V_124 * V_81 = V_124 ( V_52 ) ;
T_4 V_138 [ V_139 ] ;
int V_77 ;
V_67 -> V_31 = V_81 -> V_31 ;
if ( V_87 != V_140 ) {
F_70 ( V_126 , V_135 ) ;
return - V_118 ;
}
V_77 = F_72 ( V_138 , V_86 ) ;
if ( V_77 == 0 && ( V_52 -> V_141 & V_142 ) ) {
V_52 -> V_141 |= V_143 ;
return - V_118 ;
}
V_67 -> V_136 = V_87 ;
memcpy ( V_67 -> V_86 . V_144 , V_86 , V_87 ) ;
return 0 ;
}
static int F_73 ( struct V_125 * V_126 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_126 ) ;
struct V_127 * V_67 = F_69 ( V_52 ) ;
struct V_124 * V_81 = V_124 ( V_52 ) ;
V_67 -> V_31 = V_81 -> V_31 ;
if ( V_87 != ( 3 * V_140 ) ) {
F_70 ( V_126 , V_135 ) ;
return - V_118 ;
}
V_67 -> V_136 = V_87 ;
memcpy ( V_67 -> V_86 . V_145 , V_86 , V_87 ) ;
return 0 ;
}
static int F_74 ( struct V_125 * V_126 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_126 ) ;
struct V_127 * V_67 = F_69 ( V_52 ) ;
struct V_124 * V_81 = V_124 ( V_52 ) ;
T_3 * V_146 = V_67 -> V_86 . V_147 ;
T_3 * V_148 = V_146 + 256 ;
T_3 * V_149 = V_148 + 1 ;
int V_150 , V_151 , V_152 ;
V_67 -> V_31 = V_81 -> V_31 ;
V_151 = V_152 = 0 ;
* V_148 = 0 ;
* V_149 = 0 ;
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ )
V_146 [ V_150 ] = V_150 ;
for ( V_150 = 0 ; V_150 < 256 ; V_150 ++ ) {
T_3 V_153 = V_146 [ V_150 ] ;
V_151 = ( V_151 + V_86 [ V_152 ] + V_153 ) & 0xff ;
V_146 [ V_150 ] = V_146 [ V_151 ] ;
V_146 [ V_151 ] = V_153 ;
if ( ++ V_152 >= V_87 )
V_152 = 0 ;
}
return 0 ;
}
static inline int F_75 ( int V_72 , unsigned int V_154 )
{
int V_155 = V_72 ;
V_155 -= ( V_72 & ( V_154 - 1 ) ) ;
return V_155 > ( 1 << 16 ) ? ( 1 << 16 ) : V_155 ;
}
static int F_76 ( struct V_51 * V_52 , struct V_156 * V_157 ,
struct V_1 * V_94 , bool V_37 )
{
struct V_127 * V_67 = F_69 ( V_52 ) ;
struct V_95 * V_96 ;
bool V_158 ;
int V_150 ;
V_96 = F_13 ( V_94 , V_157 -> V_159 ) ;
if ( ! V_96 ) {
F_77 ( L_8 ,
V_157 -> V_159 ) ;
return - V_160 ;
}
V_158 = ( V_157 -> V_161 == V_157 -> V_162 [ 0 ] . V_163 ) ;
V_96 -> V_107 = F_16 ( V_157 -> V_162 [ 0 ] . V_164 ,
0 , V_67 -> V_31 , 0 , 0 ,
false , true , false , V_37 ,
V_165 |
( V_158 ? V_108 : 0 ) ) ;
V_96 -> V_110 = V_157 -> V_162 [ 0 ] . V_163 ;
V_96 -> V_112 = 0UL ;
V_96 -> V_113 = 0UL ;
V_96 -> V_114 = 0UL ;
V_96 -> V_115 = F_61 ( & V_67 -> V_86 ) ;
V_96 -> V_116 = V_157 -> V_166 ;
V_96 -> V_117 = ( V_158 ? 0UL : V_157 -> V_161 ) ;
for ( V_150 = 1 ; V_150 < V_157 -> V_159 ; V_150 ++ ) {
V_96 = F_11 ( V_94 , V_96 ) ;
V_96 -> V_107 = V_157 -> V_162 [ V_150 ] . V_164 - 1 ;
V_96 -> V_110 = V_157 -> V_162 [ V_150 ] . V_163 ;
V_96 -> V_112 = 0UL ;
V_96 -> V_113 = 0UL ;
V_96 -> V_114 = 0UL ;
V_96 -> V_115 = 0UL ;
V_96 -> V_116 = 0UL ;
V_96 -> V_117 = 0UL ;
}
V_96 -> V_107 |= V_46 ;
return ( F_14 ( V_94 , V_96 ) != V_19 ) ? - V_118 : 0 ;
}
static int F_78 ( struct V_167 * V_62 )
{
struct V_168 * V_64 = F_79 ( V_62 ) ;
struct V_169 * V_103 = & V_64 -> V_103 ;
struct V_156 * V_170 ;
unsigned long V_171 ;
unsigned int V_172 ;
bool V_173 ;
int V_77 , V_72 ;
F_80 ( V_103 , V_62 -> V_174 , V_62 -> V_73 , V_62 -> V_72 ) ;
V_77 = F_81 ( V_62 , V_103 ) ;
if ( V_77 )
return V_77 ;
F_82 ( & V_64 -> V_175 ) ;
V_170 = & V_64 -> V_170 ;
F_82 ( & V_170 -> V_176 ) ;
V_170 -> V_166 = 0UL ;
V_170 -> V_159 = 0 ;
V_170 -> V_161 = 0UL ;
V_173 = false ;
V_171 = ~ 0UL ;
V_172 = 0 ;
while ( ( V_72 = V_103 -> V_72 ) != 0 ) {
unsigned long V_161 , V_163 ;
bool V_158 ;
int V_155 ;
V_163 = ( F_83 ( V_103 -> V_73 . V_177 ) +
V_103 -> V_73 . V_10 ) ;
V_161 = ( F_83 ( V_103 -> V_174 . V_177 ) +
V_103 -> V_174 . V_10 ) ;
V_158 = ( V_163 == V_161 ) ;
V_155 = F_75 ( V_72 , V_103 -> V_178 ) ;
if ( V_170 -> V_159 != 0 ) {
if ( V_158 != V_173 ||
( ! V_173 &&
V_161 != V_171 ) ||
V_170 -> V_159 == V_179 ||
V_172 + V_155 > ( 1 << 16 ) ) {
V_170 -> V_180 = V_171 ;
F_84 ( & V_170 -> V_176 ,
& V_64 -> V_175 ) ;
V_170 = F_85 ( sizeof( * V_170 ) , V_181 ) ;
if ( ! V_170 ) {
V_77 = - V_182 ;
break;
}
F_82 ( & V_170 -> V_176 ) ;
}
}
if ( V_170 -> V_159 == 0 ) {
V_170 -> V_161 = V_161 ;
V_172 = 0 ;
}
V_170 -> V_162 [ V_170 -> V_159 ] . V_163 = V_163 ;
V_170 -> V_162 [ V_170 -> V_159 ] . V_164 = V_155 ;
V_170 -> V_159 ++ ;
V_171 = V_161 + V_155 ;
V_173 = V_158 ;
V_172 += V_155 ;
V_77 = F_86 ( V_62 , V_103 , V_72 - V_155 ) ;
if ( V_77 )
break;
}
if ( ! V_77 && V_170 -> V_159 != 0 ) {
V_170 -> V_180 = V_171 ;
F_84 ( & V_170 -> V_176 , & V_64 -> V_175 ) ;
}
return V_77 ;
}
static void F_87 ( struct V_167 * V_62 , void * V_183 )
{
struct V_168 * V_64 = F_79 ( V_62 ) ;
struct V_156 * V_184 , * V_138 ;
if ( V_183 )
memcpy ( V_64 -> V_103 . V_185 , V_183 , V_64 -> V_103 . V_178 ) ;
F_88 ( & V_64 -> V_103 ) ;
F_89 (c, tmp, &rctx->chunk_list, entry) {
F_90 ( & V_184 -> V_176 ) ;
if ( F_56 ( V_184 != & V_64 -> V_170 ) )
F_91 ( V_184 ) ;
}
}
static int F_92 ( struct V_167 * V_62 , bool V_37 )
{
struct V_168 * V_64 = F_79 ( V_62 ) ;
struct V_51 * V_52 = V_62 -> V_58 . V_52 ;
int V_77 = F_78 ( V_62 ) ;
struct V_156 * V_184 , * V_138 ;
unsigned long V_70 , V_15 ;
struct V_1 * V_94 ;
if ( V_77 )
return V_77 ;
V_94 = V_106 [ F_59 () ] ;
V_77 = - V_104 ;
if ( ! V_94 )
goto V_79;
F_60 ( & V_94 -> V_17 , V_70 ) ;
F_89 (c, tmp, &rctx->chunk_list, entry) {
V_77 = F_76 ( V_52 , V_184 , V_94 , V_37 ) ;
if ( V_77 )
break;
F_90 ( & V_184 -> V_176 ) ;
if ( F_56 ( V_184 != & V_64 -> V_170 ) )
F_91 ( V_184 ) ;
}
if ( ! V_77 ) {
V_15 = F_53 ( V_94 ) ;
if ( V_15 != V_19 )
V_77 = - V_118 ;
}
F_63 ( & V_94 -> V_17 , V_70 ) ;
V_79:
F_64 () ;
F_87 ( V_62 , NULL ) ;
return V_77 ;
}
static int F_93 ( struct V_167 * V_62 )
{
return F_92 ( V_62 , true ) ;
}
static int F_94 ( struct V_167 * V_62 )
{
return F_92 ( V_62 , false ) ;
}
static int F_95 ( struct V_167 * V_62 , bool V_37 )
{
struct V_168 * V_64 = F_79 ( V_62 ) ;
struct V_51 * V_52 = V_62 -> V_58 . V_52 ;
unsigned long V_70 , V_15 , V_166 ;
int V_77 = F_78 ( V_62 ) ;
struct V_156 * V_184 , * V_138 ;
struct V_1 * V_94 ;
void * V_186 ;
V_186 = NULL ;
if ( V_77 )
return V_77 ;
V_94 = V_106 [ F_59 () ] ;
V_77 = - V_104 ;
if ( ! V_94 )
goto V_79;
F_60 ( & V_94 -> V_17 , V_70 ) ;
if ( V_37 ) {
V_166 = F_61 ( V_64 -> V_103 . V_185 ) ;
F_89 (c, tmp, &rctx->chunk_list,
entry) {
V_184 -> V_166 = V_166 ;
V_77 = F_76 ( V_52 , V_184 , V_94 , true ) ;
if ( V_77 )
break;
V_166 = V_184 -> V_180 - V_64 -> V_103 . V_178 ;
F_90 ( & V_184 -> V_176 ) ;
if ( F_56 ( V_184 != & V_64 -> V_170 ) )
F_91 ( V_184 ) ;
}
V_186 = F_96 ( V_166 ) ;
} else {
F_97 (c, tmp, &rctx->chunk_list,
entry) {
if ( V_184 == & V_64 -> V_170 ) {
V_166 = F_61 ( V_64 -> V_103 . V_185 ) ;
} else {
V_166 = ( V_138 -> V_162 [ V_138 -> V_159 - 1 ] . V_163 +
V_138 -> V_162 [ V_138 -> V_159 - 1 ] . V_164 -
V_64 -> V_103 . V_178 ) ;
}
if ( ! V_186 ) {
unsigned long V_187 ;
V_187 = ( V_184 -> V_162 [ V_184 -> V_159 - 1 ] . V_163 +
V_184 -> V_162 [ V_184 -> V_159 - 1 ] . V_164 -
V_64 -> V_103 . V_178 ) ;
V_186 = V_64 -> V_188 ;
memcpy ( V_64 -> V_188 , F_96 ( V_187 ) ,
V_64 -> V_103 . V_178 ) ;
}
V_184 -> V_166 = V_166 ;
V_77 = F_76 ( V_52 , V_184 , V_94 , false ) ;
if ( V_77 )
break;
F_90 ( & V_184 -> V_176 ) ;
if ( F_56 ( V_184 != & V_64 -> V_170 ) )
F_91 ( V_184 ) ;
}
}
if ( ! V_77 ) {
V_15 = F_53 ( V_94 ) ;
if ( V_15 != V_19 )
V_77 = - V_118 ;
}
F_63 ( & V_94 -> V_17 , V_70 ) ;
V_79:
F_64 () ;
F_87 ( V_62 , V_77 ? NULL : V_186 ) ;
return V_77 ;
}
static int F_98 ( struct V_167 * V_62 )
{
return F_95 ( V_62 , true ) ;
}
static int F_99 ( struct V_167 * V_62 )
{
return F_95 ( V_62 , false ) ;
}
static void F_100 ( void )
{
struct V_124 * V_126 , * V_189 ;
struct V_50 * V_54 , * V_190 ;
struct V_59 * V_191 , * V_192 ;
F_89 (cipher, cipher_tmp, &cipher_algs, entry) {
F_101 ( & V_126 -> V_54 ) ;
F_90 ( & V_126 -> V_176 ) ;
F_91 ( V_126 ) ;
}
F_89 (hmac, hmac_tmp, &hmac_algs, derived.entry) {
F_102 ( & V_191 -> V_60 . V_54 ) ;
F_90 ( & V_191 -> V_60 . V_176 ) ;
F_91 ( V_191 ) ;
}
F_89 (alg, alg_tmp, &ahash_algs, entry) {
F_102 ( & V_54 -> V_54 ) ;
F_90 ( & V_54 -> V_176 ) ;
F_91 ( V_54 ) ;
}
}
static int F_103 ( struct V_51 * V_52 )
{
V_52 -> V_193 . V_194 = sizeof( struct V_168 ) ;
return 0 ;
}
static int F_104 ( const struct V_195 * V_196 )
{
struct V_124 * V_197 = F_85 ( sizeof( * V_197 ) , V_198 ) ;
struct V_53 * V_54 ;
int V_77 ;
if ( ! V_197 )
return - V_182 ;
V_54 = & V_197 -> V_54 ;
snprintf ( V_54 -> V_199 , V_200 , L_9 , V_196 -> V_201 ) ;
snprintf ( V_54 -> V_202 , V_200 , L_10 , V_196 -> V_203 ) ;
V_54 -> V_204 = V_205 ;
V_54 -> V_206 = V_207 |
V_208 | V_209 ;
V_54 -> V_210 = V_196 -> V_154 ;
V_197 -> V_31 = V_196 -> V_31 ;
V_54 -> V_211 = sizeof( struct V_127 ) ;
V_54 -> V_212 = & V_213 ;
V_54 -> V_214 . V_215 = V_196 -> V_215 ;
V_54 -> V_216 = F_103 ;
V_54 -> V_217 = V_218 ;
F_105 ( & V_197 -> V_176 , & V_219 ) ;
V_77 = F_106 ( V_54 ) ;
if ( V_77 ) {
F_4 ( L_11 , V_54 -> V_199 ) ;
F_90 ( & V_197 -> V_176 ) ;
F_91 ( V_197 ) ;
} else {
F_77 ( L_12 , V_54 -> V_199 ) ;
}
return V_77 ;
}
static int F_107 ( struct V_50 * V_220 )
{
struct V_59 * V_197 = F_85 ( sizeof( * V_197 ) , V_198 ) ;
struct V_56 * V_76 ;
struct V_53 * V_58 ;
int V_77 ;
if ( ! V_197 )
return - V_182 ;
V_197 -> V_84 = V_220 -> V_54 . V_57 . V_58 . V_199 ;
memcpy ( & V_197 -> V_60 , V_220 , sizeof( struct V_50 ) ) ;
F_82 ( & V_197 -> V_60 . V_176 ) ;
V_76 = & V_197 -> V_60 . V_54 ;
V_76 -> V_221 = F_66 ;
V_76 -> V_222 = F_45 ;
V_58 = & V_76 -> V_57 . V_58 ;
snprintf ( V_58 -> V_199 , V_200 , L_13 , V_197 -> V_84 ) ;
snprintf ( V_58 -> V_202 , V_200 , L_14 , V_197 -> V_84 ) ;
V_58 -> V_211 = sizeof( struct V_80 ) ;
V_58 -> V_216 = F_41 ;
V_58 -> V_223 = F_43 ;
F_105 ( & V_197 -> V_60 . V_176 , & V_224 ) ;
V_77 = F_108 ( V_76 ) ;
if ( V_77 ) {
F_4 ( L_11 , V_58 -> V_199 ) ;
F_90 ( & V_197 -> V_60 . V_176 ) ;
F_91 ( V_197 ) ;
} else {
F_77 ( L_12 , V_58 -> V_199 ) ;
}
return V_77 ;
}
static int F_109 ( const struct V_225 * V_196 )
{
struct V_50 * V_197 = F_85 ( sizeof( * V_197 ) , V_198 ) ;
struct V_226 * V_57 ;
struct V_53 * V_58 ;
struct V_56 * V_76 ;
int V_77 ;
if ( ! V_197 )
return - V_182 ;
V_197 -> V_119 = V_196 -> V_119 ;
V_197 -> V_121 = V_196 -> V_121 ;
V_197 -> V_32 = V_196 -> V_32 ;
V_197 -> V_123 = V_196 -> V_123 ;
V_197 -> V_122 = V_196 -> V_122 ;
V_197 -> V_97 = V_196 -> V_97 ;
V_76 = & V_197 -> V_54 ;
V_76 -> V_227 = F_18 ;
V_76 -> V_228 = F_24 ;
V_76 -> V_229 = F_26 ;
V_76 -> V_230 = F_28 ;
V_76 -> V_221 = F_65 ;
V_57 = & V_76 -> V_57 ;
V_57 -> V_231 = V_196 -> V_97 ;
V_58 = & V_57 -> V_58 ;
snprintf ( V_58 -> V_199 , V_200 , L_9 , V_196 -> V_201 ) ;
snprintf ( V_58 -> V_202 , V_200 , L_10 , V_196 -> V_201 ) ;
V_58 -> V_204 = V_205 ;
V_58 -> V_206 = V_232 |
V_208 |
V_78 ;
V_58 -> V_210 = V_196 -> V_154 ;
V_58 -> V_211 = sizeof( struct V_66 ) ;
V_58 -> V_217 = V_218 ;
V_58 -> V_216 = F_30 ;
V_58 -> V_223 = F_39 ;
F_105 ( & V_197 -> V_176 , & V_233 ) ;
V_77 = F_108 ( V_76 ) ;
if ( V_77 ) {
F_4 ( L_11 , V_58 -> V_199 ) ;
F_90 ( & V_197 -> V_176 ) ;
F_91 ( V_197 ) ;
} else {
F_77 ( L_12 , V_58 -> V_199 ) ;
}
if ( ! V_77 && V_197 -> V_123 != V_234 )
V_77 = F_107 ( V_197 ) ;
return V_77 ;
}
static int F_110 ( void )
{
int V_150 , V_77 = 0 ;
F_111 ( & V_235 ) ;
if ( V_236 ++ )
goto V_79;
for ( V_150 = 0 ; V_150 < V_237 ; V_150 ++ ) {
V_77 = F_109 ( & V_238 [ V_150 ] ) ;
if ( V_77 ) {
F_100 () ;
goto V_79;
}
}
for ( V_150 = 0 ; V_150 < V_239 ; V_150 ++ ) {
V_77 = F_104 ( & V_240 [ V_150 ] ) ;
if ( V_77 ) {
F_100 () ;
goto V_79;
}
}
V_79:
F_112 ( & V_235 ) ;
return V_77 ;
}
static void F_113 ( void )
{
F_111 ( & V_235 ) ;
if ( ! -- V_236 )
F_100 () ;
F_112 ( & V_235 ) ;
}
static int F_114 ( struct V_241 * V_242 , struct V_243 * V_244 ,
unsigned long V_245 )
{
const unsigned int * V_246 ;
unsigned int V_247 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_244 -> V_248 ; V_150 ++ ) {
if ( V_244 -> V_249 [ V_150 ] . V_250 == V_245 )
break;
}
if ( V_150 == V_244 -> V_248 )
return - V_104 ;
V_247 = V_244 -> V_249 [ V_150 ] . V_247 ;
V_246 = F_115 ( V_242 -> V_242 . V_251 , L_15 , NULL ) ;
if ( ! V_246 )
return - V_104 ;
for ( V_150 = 0 ; V_150 < V_242 -> V_252 . V_253 ; V_150 ++ ) {
if ( V_246 [ V_150 ] == V_247 )
return V_150 ;
}
return - V_104 ;
}
static int F_116 ( struct V_241 * V_242 , struct V_243 * V_244 ,
const char * V_254 , struct V_1 * V_197 ,
T_5 V_255 )
{
unsigned long V_256 ;
int V_257 ;
V_256 = F_117 ( V_197 -> V_16 , & V_197 -> V_258 ) ;
if ( V_256 )
return - V_118 ;
V_257 = F_114 ( V_242 , V_244 , V_197 -> V_258 ) ;
if ( V_257 < 0 )
return V_257 ;
V_197 -> V_13 = V_242 -> V_252 . V_259 [ V_257 ] ;
sprintf ( V_197 -> V_254 , L_16 , V_254 , V_257 ) ;
return F_118 ( V_197 -> V_13 , V_255 , 0 , V_197 -> V_254 , V_197 ) ;
}
static void * F_119 ( unsigned long V_4 )
{
return F_120 ( V_260 [ V_4 - 1 ] , V_198 ) ;
}
static void F_121 ( void * V_197 , unsigned long V_4 )
{
F_122 ( V_260 [ V_4 - 1 ] , V_197 ) ;
}
static int F_123 ( void )
{
if ( ! V_260 [ V_5 - 1 ] )
V_260 [ V_5 - 1 ] =
F_124 ( L_17 ,
( V_7 *
V_6 ) ,
V_6 , 0 , NULL ) ;
if ( ! V_260 [ V_5 - 1 ] )
return - V_182 ;
if ( ! V_260 [ V_261 - 1 ] )
V_260 [ V_261 - 1 ] =
F_124 ( L_18 ,
( V_9 *
V_8 ) ,
V_8 , 0 , NULL ) ;
if ( ! V_260 [ V_261 - 1 ] ) {
F_125 ( V_260 [ V_5 - 1 ] ) ;
return - V_182 ;
}
return 0 ;
}
static void F_126 ( void )
{
F_125 ( V_260 [ V_5 - 1 ] ) ;
F_125 ( V_260 [ V_261 - 1 ] ) ;
}
static long F_127 ( void * V_262 )
{
struct V_263 * V_264 = V_262 ;
struct V_1 * V_197 = V_264 -> V_265 ;
unsigned long V_4 = V_264 -> type ;
unsigned long V_15 ;
V_15 = F_128 ( V_4 , F_61 ( V_197 -> V_2 ) ,
V_9 , & V_197 -> V_16 ) ;
if ( ! V_15 )
F_8 ( V_197 -> V_16 , 0 ) ;
return V_15 ? - V_118 : 0 ;
}
static int F_129 ( struct V_1 * V_197 , unsigned long V_4 )
{
int V_105 = F_130 ( & V_197 -> V_266 , V_267 ) ;
struct V_263 V_264 = { . V_265 = V_197 , . type = V_4 } ;
return F_131 ( V_105 , F_127 , & V_264 ) ;
}
static int F_132 ( struct V_1 * V_197 )
{
int V_77 ;
V_197 -> V_2 = F_119 ( V_197 -> V_4 ) ;
if ( ! V_197 -> V_2 )
return - V_182 ;
V_77 = F_129 ( V_197 , V_197 -> V_4 ) ;
if ( V_77 ) {
F_121 ( V_197 -> V_2 , V_197 -> V_4 ) ;
V_197 -> V_2 = NULL ;
}
return V_77 ;
}
static void F_133 ( struct V_1 * V_197 )
{
unsigned long V_15 ;
if ( ! V_197 -> V_2 )
return;
V_15 = F_128 ( V_197 -> V_4 , V_197 -> V_16 , 0 , & V_197 -> V_16 ) ;
if ( ! V_15 )
F_121 ( V_197 -> V_2 , V_197 -> V_4 ) ;
}
static void F_134 ( struct V_268 * V_269 )
{
struct V_1 * V_197 , * V_270 ;
F_89 (p, n, list, list) {
int V_150 ;
for ( V_150 = 0 ; V_150 < V_271 ; V_150 ++ ) {
if ( V_106 [ V_150 ] == V_197 )
V_106 [ V_150 ] = NULL ;
}
if ( V_197 -> V_13 ) {
F_135 ( V_197 -> V_13 , V_197 ) ;
V_197 -> V_13 = 0 ;
}
F_133 ( V_197 ) ;
F_90 ( & V_197 -> V_269 ) ;
F_91 ( V_197 ) ;
}
}
static int F_136 ( struct V_272 * V_273 ,
struct V_241 * V_242 ,
T_2 V_274 , struct V_1 * V_197 ,
struct V_1 * * V_275 )
{
T_2 V_276 ;
F_137 (arc, mdesc, node, MDESC_ARC_TYPE_BACK) {
T_2 V_277 = F_138 ( V_273 , V_276 ) ;
const char * V_201 = F_139 ( V_273 , V_277 ) ;
const T_2 * V_278 ;
if ( strcmp ( V_201 , L_19 ) )
continue;
V_278 = F_140 ( V_273 , V_277 , L_20 , NULL ) ;
if ( V_275 [ * V_278 ] != NULL ) {
F_141 ( & V_242 -> V_242 , L_21 ,
V_242 -> V_242 . V_251 ) ;
return - V_118 ;
}
F_142 ( * V_278 , & V_197 -> V_266 ) ;
V_275 [ * V_278 ] = V_197 ;
}
return 0 ;
}
static int F_143 ( struct V_243 * V_244 , struct V_268 * V_269 ,
struct V_241 * V_242 , struct V_272 * V_273 ,
T_2 V_274 , const char * V_279 , unsigned long V_4 ,
T_5 V_255 , struct V_1 * * V_275 )
{
struct V_1 * V_197 ;
int V_77 ;
V_197 = F_85 ( sizeof( struct V_1 ) , V_198 ) ;
if ( ! V_197 ) {
F_141 ( & V_242 -> V_242 , L_22 ,
V_242 -> V_242 . V_251 ) ;
return - V_182 ;
}
F_144 ( & V_197 -> V_266 ) ;
F_145 ( & V_197 -> V_17 ) ;
V_197 -> V_4 = V_4 ;
F_82 ( & V_197 -> V_280 ) ;
F_105 ( & V_197 -> V_269 , V_269 ) ;
V_77 = F_136 ( V_273 , V_242 , V_274 , V_197 , V_275 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_132 ( V_197 ) ;
if ( V_77 )
return V_77 ;
return F_116 ( V_242 , V_244 , V_279 , V_197 , V_255 ) ;
}
static int F_146 ( struct V_272 * V_273 , struct V_241 * V_242 ,
struct V_243 * V_244 , struct V_268 * V_269 ,
const char * V_281 , unsigned long V_4 ,
T_5 V_255 , struct V_1 * * V_275 )
{
int V_77 = 0 ;
T_2 V_274 ;
F_147 (mdesc, node, L_23 ) {
const char * type ;
type = F_140 ( V_273 , V_274 , L_24 , NULL ) ;
if ( ! type || strcmp ( type , V_281 ) )
continue;
V_77 = F_143 ( V_244 , V_269 , V_242 , V_273 , V_274 ,
V_281 , V_4 , V_255 , V_275 ) ;
if ( V_77 ) {
F_134 ( V_269 ) ;
break;
}
}
return V_77 ;
}
static int F_148 ( struct V_272 * V_273 , T_2 V_274 ,
struct V_243 * V_244 )
{
const T_2 * V_250 ;
int V_282 ;
int V_150 ;
V_250 = F_140 ( V_273 , V_274 , L_25 , & V_282 ) ;
if ( ! V_250 ) {
F_149 ( L_26 ) ;
return - V_104 ;
}
V_244 -> V_248 = V_282 / sizeof( T_2 ) ;
V_244 -> V_249 = F_85 ( ( sizeof( struct V_283 ) *
V_244 -> V_248 ) ,
V_198 ) ;
if ( ! V_244 -> V_249 )
return - V_182 ;
for ( V_150 = 0 ; V_150 < V_244 -> V_248 ; V_150 ++ ) {
struct V_283 * V_284 = & V_244 -> V_249 [ V_150 ] ;
V_284 -> V_247 = V_150 + 1 ;
V_284 -> V_250 = V_250 [ V_150 ] ;
}
return 0 ;
}
static int F_150 ( struct V_272 * V_273 ,
struct V_241 * V_242 ,
struct V_243 * V_244 ,
const char * V_285 )
{
const unsigned int * V_286 ;
T_2 V_274 ;
V_286 = F_115 ( V_242 -> V_242 . V_251 , L_27 , NULL ) ;
if ( ! V_286 )
return - V_104 ;
F_147 (mdesc, node, L_28 ) {
const char * V_201 ;
const T_2 * V_287 ;
V_201 = F_140 ( V_273 , V_274 , L_29 , NULL ) ;
if ( ! V_201 || strcmp ( V_201 , V_285 ) )
continue;
V_287 = F_140 ( V_273 , V_274 , L_30 , NULL ) ;
if ( ! V_287 || ( * V_287 != * V_286 ) )
continue;
V_244 -> V_288 = * V_287 ;
return F_148 ( V_273 , V_274 , V_244 ) ;
}
return - V_104 ;
}
static int F_151 ( void )
{
int V_77 ;
V_289 = 2 ;
V_290 = 0 ;
V_77 = F_152 ( V_291 ,
V_289 ,
& V_290 ) ;
if ( ! V_77 )
F_77 ( L_31 ,
V_289 ,
V_290 ) ;
return V_77 ;
}
static void F_153 ( void )
{
F_154 ( V_291 ) ;
}
static int F_155 ( void )
{
int V_77 = 0 ;
F_111 ( & V_235 ) ;
if ( V_292 ++ )
goto V_79;
V_77 = F_151 () ;
if ( V_77 )
goto V_79;
V_77 = F_123 () ;
if ( V_77 )
goto V_293;
V_77 = - V_182 ;
V_106 = F_85 ( sizeof( struct V_1 * ) * V_271 ,
V_198 ) ;
if ( ! V_106 )
goto V_294;
V_295 = F_85 ( sizeof( struct V_1 * ) * V_271 ,
V_198 ) ;
if ( ! V_295 )
goto V_296;
V_77 = 0 ;
V_79:
if ( V_77 )
V_292 -- ;
F_112 ( & V_235 ) ;
return V_77 ;
V_296:
F_91 ( V_106 ) ;
V_106 = NULL ;
V_294:
F_126 () ;
V_293:
F_153 () ;
goto V_79;
}
static void F_156 ( void )
{
F_111 ( & V_235 ) ;
if ( ! -- V_292 ) {
F_91 ( V_106 ) ;
V_106 = NULL ;
F_91 ( V_295 ) ;
V_295 = NULL ;
F_126 () ;
F_153 () ;
}
F_112 ( & V_235 ) ;
}
static struct V_297 * F_157 ( void )
{
struct V_297 * V_298 = F_85 ( sizeof( struct V_297 ) , V_198 ) ;
if ( V_298 )
F_82 ( & V_298 -> V_299 ) ;
return V_298 ;
}
static void F_158 ( struct V_297 * V_298 )
{
if ( V_298 -> V_300 . V_249 ) {
F_91 ( V_298 -> V_300 . V_249 ) ;
V_298 -> V_300 . V_249 = NULL ;
}
F_91 ( V_298 ) ;
}
static void F_159 ( void )
{
static int V_301 ;
if ( V_301 ++ == 0 )
F_77 ( L_9 , V_302 ) ;
}
static int F_160 ( struct V_241 * V_242 )
{
struct V_272 * V_273 ;
struct V_297 * V_298 ;
int V_77 ;
F_159 () ;
F_77 ( L_32 , V_242 -> V_242 . V_251 ) ;
V_298 = F_157 () ;
if ( ! V_298 ) {
F_141 ( & V_242 -> V_242 , L_33 ,
V_242 -> V_242 . V_251 ) ;
return - V_182 ;
}
V_77 = F_155 () ;
if ( V_77 ) {
F_141 ( & V_242 -> V_242 , L_34 ,
V_242 -> V_242 . V_251 ) ;
goto V_303;
}
V_273 = F_161 () ;
if ( ! V_273 ) {
F_141 ( & V_242 -> V_242 , L_35 ,
V_242 -> V_242 . V_251 ) ;
V_77 = - V_104 ;
goto V_304;
}
V_77 = F_150 ( V_273 , V_242 , & V_298 -> V_300 , L_36 ) ;
if ( V_77 ) {
F_141 ( & V_242 -> V_242 , L_37 ,
V_242 -> V_242 . V_251 ) ;
F_162 ( V_273 ) ;
goto V_304;
}
V_77 = F_146 ( V_273 , V_242 , & V_298 -> V_300 , & V_298 -> V_299 ,
L_38 , V_261 , F_3 ,
V_106 ) ;
F_162 ( V_273 ) ;
if ( V_77 ) {
F_141 ( & V_242 -> V_242 , L_39 ,
V_242 -> V_242 . V_251 ) ;
goto V_304;
}
V_77 = F_110 () ;
if ( V_77 ) {
F_141 ( & V_242 -> V_242 , L_40 ,
V_242 -> V_242 . V_251 ) ;
goto V_305;
}
F_163 ( & V_242 -> V_242 , V_298 ) ;
return 0 ;
V_305:
F_134 ( & V_298 -> V_299 ) ;
V_304:
F_156 () ;
V_303:
F_158 ( V_298 ) ;
return V_77 ;
}
static int F_164 ( struct V_241 * V_242 )
{
struct V_297 * V_298 = F_165 ( & V_242 -> V_242 ) ;
F_113 () ;
F_134 ( & V_298 -> V_299 ) ;
F_156 () ;
F_158 ( V_298 ) ;
return 0 ;
}
static struct V_306 * F_166 ( void )
{
struct V_306 * V_307 = F_85 ( sizeof( struct V_306 ) , V_198 ) ;
if ( V_307 )
F_82 ( & V_307 -> V_308 ) ;
return V_307 ;
}
static void F_167 ( struct V_306 * V_307 )
{
if ( V_307 -> V_309 . V_249 ) {
F_91 ( V_307 -> V_309 . V_249 ) ;
V_307 -> V_309 . V_249 = NULL ;
}
F_91 ( V_307 ) ;
}
static int F_168 ( struct V_241 * V_242 )
{
struct V_272 * V_273 ;
struct V_306 * V_307 ;
int V_77 ;
F_159 () ;
F_77 ( L_41 , V_242 -> V_242 . V_251 ) ;
V_307 = F_166 () ;
if ( ! V_307 ) {
F_141 ( & V_242 -> V_242 , L_42 ,
V_242 -> V_242 . V_251 ) ;
return - V_182 ;
}
V_77 = F_155 () ;
if ( V_77 ) {
F_141 ( & V_242 -> V_242 , L_34 ,
V_242 -> V_242 . V_251 ) ;
goto V_310;
}
V_273 = F_161 () ;
if ( ! V_273 ) {
F_141 ( & V_242 -> V_242 , L_35 ,
V_242 -> V_242 . V_251 ) ;
V_77 = - V_104 ;
goto V_304;
}
V_77 = F_150 ( V_273 , V_242 , & V_307 -> V_309 , L_43 ) ;
if ( V_77 ) {
F_141 ( & V_242 -> V_242 , L_37 ,
V_242 -> V_242 . V_251 ) ;
F_162 ( V_273 ) ;
goto V_304;
}
V_77 = F_146 ( V_273 , V_242 , & V_307 -> V_309 , & V_307 -> V_308 ,
L_44 , V_5 , F_10 ,
V_295 ) ;
F_162 ( V_273 ) ;
if ( V_77 ) {
F_141 ( & V_242 -> V_242 , L_45 ,
V_242 -> V_242 . V_251 ) ;
goto V_304;
}
F_163 ( & V_242 -> V_242 , V_307 ) ;
return 0 ;
V_304:
F_156 () ;
V_310:
F_167 ( V_307 ) ;
return V_77 ;
}
static int F_169 ( struct V_241 * V_242 )
{
struct V_306 * V_307 = F_165 ( & V_242 -> V_242 ) ;
F_134 ( & V_307 -> V_308 ) ;
F_156 () ;
F_167 ( V_307 ) ;
return 0 ;
}
static int T_6 F_170 ( void )
{
return F_171 ( V_311 , F_172 ( V_311 ) ) ;
}
static void T_7 F_173 ( void )
{
F_174 ( V_311 , F_172 ( V_311 ) ) ;
}
