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
struct {
struct V_88 V_89 ;
char V_67 [ F_46 ( V_83 ) ] ;
} V_90 ;
int V_77 , V_91 , V_92 ;
V_69 = V_67 -> V_58 . V_69 ;
V_77 = F_47 ( V_69 , V_86 , V_87 ) ;
if ( V_77 )
return V_77 ;
V_90 . V_89 . V_52 = V_83 ;
V_90 . V_89 . V_70 = F_48 ( V_52 ) &
V_71 ;
V_91 = F_49 ( V_83 ) ;
V_92 = F_50 ( V_83 ) ;
F_51 ( V_92 > V_93 ) ;
if ( V_87 > V_91 ) {
V_77 = F_52 ( & V_90 . V_89 , V_86 , V_87 ,
V_67 -> V_94 ) ;
if ( V_77 )
return V_77 ;
V_87 = V_92 ;
} else if ( V_87 <= V_93 )
memcpy ( V_67 -> V_94 , V_86 , V_87 ) ;
V_67 -> V_95 = V_87 ;
return V_77 ;
}
static unsigned long F_53 ( struct V_1 * V_96 )
{
unsigned long V_18 , V_15 ;
do {
V_15 = F_7 ( V_96 -> V_16 , & V_18 ) ;
if ( V_15 != V_19 ) {
F_4 ( L_7 ) ;
break;
}
if ( V_18 == V_96 -> V_22 ) {
V_96 -> V_18 = V_18 ;
break;
}
} while ( 1 );
return V_15 ;
}
static unsigned long F_54 ( struct V_1 * V_96 ,
struct V_97 * V_98 )
{
unsigned long V_15 = F_14 ( V_96 , V_98 ) ;
if ( V_15 == V_19 )
V_15 = F_53 ( V_96 ) ;
return V_15 ;
}
static int F_55 ( struct V_61 * V_62 ,
unsigned int V_32 , unsigned int V_99 ,
unsigned int V_100 , void * V_101 ,
unsigned long V_102 , unsigned int V_103 )
{
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_97 * V_98 ;
struct V_104 V_105 ;
struct V_1 * V_96 ;
unsigned long V_70 ;
int V_77 = - V_106 ;
int V_72 , V_107 ;
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
V_72 = F_58 ( V_62 , & V_105 ) ;
V_107 = F_59 () ;
V_96 = V_108 [ V_107 ] ;
if ( ! V_96 )
goto V_79;
F_60 ( & V_96 -> V_17 , V_70 ) ;
V_98 = V_96 -> V_2 + V_96 -> V_22 ;
V_98 -> V_109 = F_16 ( V_72 , V_103 , 0 ,
V_32 , V_99 ,
false , true , false , false ,
V_110 |
V_111 ) ;
V_98 -> V_112 = F_61 ( V_105 . V_113 ) ;
V_98 -> V_114 = V_102 ;
V_98 -> V_115 = F_61 ( V_101 ) ;
V_98 -> V_116 = 0UL ;
V_98 -> V_117 = 0UL ;
V_98 -> V_118 = 0UL ;
V_98 -> V_119 = F_61 ( V_101 ) ;
V_72 = F_62 ( & V_105 , 0 ) ;
while ( V_72 > 0 ) {
V_98 = F_11 ( V_96 , V_98 ) ;
V_98 -> V_109 = ( V_72 - 1 ) ;
V_98 -> V_112 = F_61 ( V_105 . V_113 ) ;
V_98 -> V_114 = 0UL ;
V_98 -> V_115 = 0UL ;
V_98 -> V_116 = 0UL ;
V_98 -> V_117 = 0UL ;
V_98 -> V_118 = 0UL ;
V_98 -> V_119 = 0UL ;
V_72 = F_62 ( & V_105 , 0 ) ;
}
V_98 -> V_109 |= V_46 ;
if ( F_54 ( V_96 , V_98 ) != V_19 )
V_77 = - V_120 ;
else
V_77 = 0 ;
F_63 ( & V_96 -> V_17 , V_70 ) ;
if ( ! V_77 )
memcpy ( V_62 -> V_74 , V_101 , V_100 ) ;
V_79:
F_64 () ;
return V_77 ;
}
static int F_65 ( struct V_61 * V_62 )
{
struct V_50 * V_81 = V_50 ( V_62 -> V_58 . V_52 ) ;
struct V_63 * V_64 = F_19 ( V_62 ) ;
int V_92 ;
V_92 = V_81 -> V_99 ;
if ( F_56 ( V_62 -> V_72 == 0 ) ) {
memcpy ( V_62 -> V_74 , V_81 -> V_121 , V_92 ) ;
return 0 ;
}
memcpy ( & V_64 -> V_122 , V_81 -> V_123 , V_81 -> V_124 ) ;
return F_55 ( V_62 , V_81 -> V_32 ,
V_81 -> V_124 , V_92 ,
& V_64 -> V_122 , 0UL , 0 ) ;
}
static int F_66 ( struct V_61 * V_62 )
{
struct V_59 * V_81 = V_59 ( V_62 -> V_58 . V_52 ) ;
struct V_63 * V_64 = F_19 ( V_62 ) ;
struct V_65 * V_52 = F_20 ( V_62 ) ;
struct V_80 * V_67 = F_21 ( V_52 ) ;
int V_92 ;
V_92 = V_81 -> V_60 . V_99 ;
if ( F_56 ( V_62 -> V_72 == 0 ) ||
F_56 ( V_67 -> V_95 > V_93 ) ) {
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
memcpy ( & V_64 -> V_122 , V_81 -> V_60 . V_123 ,
V_81 -> V_60 . V_124 ) ;
return F_55 ( V_62 , V_81 -> V_60 . V_125 ,
V_81 -> V_60 . V_124 , V_92 ,
& V_64 -> V_122 ,
F_61 ( & V_67 -> V_94 ) ,
V_67 -> V_95 ) ;
}
static inline struct V_126 * V_126 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
return F_17 ( V_54 , struct V_126 , V_54 ) ;
}
static int F_67 ( struct V_127 * V_128 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_128 ) ;
struct V_129 * V_67 = F_69 ( V_52 ) ;
struct V_126 * V_81 = V_126 ( V_52 ) ;
V_67 -> V_31 = ( V_81 -> V_31 & V_130 ) ;
switch ( V_87 ) {
case V_131 :
V_67 -> V_31 |= V_132 ;
break;
case V_133 :
V_67 -> V_31 |= V_134 ;
break;
case V_135 :
V_67 -> V_31 |= V_136 ;
break;
default:
F_70 ( V_128 , V_137 ) ;
return - V_120 ;
}
V_67 -> V_138 = V_87 ;
memcpy ( V_67 -> V_86 . V_139 , V_86 , V_87 ) ;
return 0 ;
}
static int F_71 ( struct V_127 * V_128 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_128 ) ;
struct V_129 * V_67 = F_69 ( V_52 ) ;
struct V_126 * V_81 = V_126 ( V_52 ) ;
T_4 V_140 [ V_141 ] ;
int V_77 ;
V_67 -> V_31 = V_81 -> V_31 ;
if ( V_87 != V_142 ) {
F_70 ( V_128 , V_137 ) ;
return - V_120 ;
}
V_77 = F_72 ( V_140 , V_86 ) ;
if ( V_77 == 0 && ( V_52 -> V_143 & V_144 ) ) {
V_52 -> V_143 |= V_145 ;
return - V_120 ;
}
V_67 -> V_138 = V_87 ;
memcpy ( V_67 -> V_86 . V_146 , V_86 , V_87 ) ;
return 0 ;
}
static int F_73 ( struct V_127 * V_128 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_128 ) ;
struct V_129 * V_67 = F_69 ( V_52 ) ;
struct V_126 * V_81 = V_126 ( V_52 ) ;
V_67 -> V_31 = V_81 -> V_31 ;
if ( V_87 != ( 3 * V_142 ) ) {
F_70 ( V_128 , V_137 ) ;
return - V_120 ;
}
V_67 -> V_138 = V_87 ;
memcpy ( V_67 -> V_86 . V_147 , V_86 , V_87 ) ;
return 0 ;
}
static int F_74 ( struct V_127 * V_128 , const T_3 * V_86 ,
unsigned int V_87 )
{
struct V_51 * V_52 = F_68 ( V_128 ) ;
struct V_129 * V_67 = F_69 ( V_52 ) ;
struct V_126 * V_81 = V_126 ( V_52 ) ;
T_3 * V_148 = V_67 -> V_86 . V_149 ;
T_3 * V_150 = V_148 + 256 ;
T_3 * V_151 = V_150 + 1 ;
int V_152 , V_153 , V_154 ;
V_67 -> V_31 = V_81 -> V_31 ;
V_153 = V_154 = 0 ;
* V_150 = 0 ;
* V_151 = 0 ;
for ( V_152 = 0 ; V_152 < 256 ; V_152 ++ )
V_148 [ V_152 ] = V_152 ;
for ( V_152 = 0 ; V_152 < 256 ; V_152 ++ ) {
T_3 V_155 = V_148 [ V_152 ] ;
V_153 = ( V_153 + V_86 [ V_154 ] + V_155 ) & 0xff ;
V_148 [ V_152 ] = V_148 [ V_153 ] ;
V_148 [ V_153 ] = V_155 ;
if ( ++ V_154 >= V_87 )
V_154 = 0 ;
}
return 0 ;
}
static inline int F_75 ( int V_72 , unsigned int V_156 )
{
int V_157 = V_72 ;
V_157 -= ( V_72 & ( V_156 - 1 ) ) ;
return V_157 > ( 1 << 16 ) ? ( 1 << 16 ) : V_157 ;
}
static int F_76 ( struct V_51 * V_52 , struct V_158 * V_159 ,
struct V_1 * V_96 , bool V_37 )
{
struct V_129 * V_67 = F_69 ( V_52 ) ;
struct V_97 * V_98 ;
bool V_160 ;
int V_152 ;
V_98 = F_13 ( V_96 , V_159 -> V_161 ) ;
if ( ! V_98 ) {
F_77 ( L_8 ,
V_159 -> V_161 ) ;
return - V_162 ;
}
V_160 = ( V_159 -> V_163 == V_159 -> V_164 [ 0 ] . V_165 ) ;
V_98 -> V_109 = F_16 ( V_159 -> V_164 [ 0 ] . V_166 ,
0 , V_67 -> V_31 , 0 , 0 ,
false , true , false , V_37 ,
V_167 |
( V_160 ? V_110 : 0 ) ) ;
V_98 -> V_112 = V_159 -> V_164 [ 0 ] . V_165 ;
V_98 -> V_114 = 0UL ;
V_98 -> V_115 = 0UL ;
V_98 -> V_116 = 0UL ;
V_98 -> V_117 = F_61 ( & V_67 -> V_86 ) ;
V_98 -> V_118 = V_159 -> V_168 ;
V_98 -> V_119 = ( V_160 ? 0UL : V_159 -> V_163 ) ;
for ( V_152 = 1 ; V_152 < V_159 -> V_161 ; V_152 ++ ) {
V_98 = F_11 ( V_96 , V_98 ) ;
V_98 -> V_109 = V_159 -> V_164 [ V_152 ] . V_166 - 1 ;
V_98 -> V_112 = V_159 -> V_164 [ V_152 ] . V_165 ;
V_98 -> V_114 = 0UL ;
V_98 -> V_115 = 0UL ;
V_98 -> V_116 = 0UL ;
V_98 -> V_117 = 0UL ;
V_98 -> V_118 = 0UL ;
V_98 -> V_119 = 0UL ;
}
V_98 -> V_109 |= V_46 ;
return ( F_14 ( V_96 , V_98 ) != V_19 ) ? - V_120 : 0 ;
}
static int F_78 ( struct V_169 * V_62 )
{
struct V_170 * V_64 = F_79 ( V_62 ) ;
struct V_171 * V_105 = & V_64 -> V_105 ;
struct V_158 * V_172 ;
unsigned long V_173 ;
unsigned int V_174 ;
bool V_175 ;
int V_77 , V_72 ;
F_80 ( V_105 , V_62 -> V_176 , V_62 -> V_73 , V_62 -> V_72 ) ;
V_77 = F_81 ( V_62 , V_105 ) ;
if ( V_77 )
return V_77 ;
F_82 ( & V_64 -> V_177 ) ;
V_172 = & V_64 -> V_172 ;
F_82 ( & V_172 -> V_178 ) ;
V_172 -> V_168 = 0UL ;
V_172 -> V_161 = 0 ;
V_172 -> V_163 = 0UL ;
V_175 = false ;
V_173 = ~ 0UL ;
V_174 = 0 ;
while ( ( V_72 = V_105 -> V_72 ) != 0 ) {
unsigned long V_163 , V_165 ;
bool V_160 ;
int V_157 ;
V_165 = ( F_83 ( V_105 -> V_73 . V_179 ) +
V_105 -> V_73 . V_10 ) ;
V_163 = ( F_83 ( V_105 -> V_176 . V_179 ) +
V_105 -> V_176 . V_10 ) ;
V_160 = ( V_165 == V_163 ) ;
V_157 = F_75 ( V_72 , V_105 -> V_180 ) ;
if ( V_172 -> V_161 != 0 ) {
if ( V_160 != V_175 ||
( ! V_175 &&
V_163 != V_173 ) ||
V_172 -> V_161 == V_181 ||
V_174 + V_157 > ( 1 << 16 ) ) {
V_172 -> V_182 = V_173 ;
F_84 ( & V_172 -> V_178 ,
& V_64 -> V_177 ) ;
V_172 = F_85 ( sizeof( * V_172 ) , V_183 ) ;
if ( ! V_172 ) {
V_77 = - V_184 ;
break;
}
F_82 ( & V_172 -> V_178 ) ;
}
}
if ( V_172 -> V_161 == 0 ) {
V_172 -> V_163 = V_163 ;
V_174 = 0 ;
}
V_172 -> V_164 [ V_172 -> V_161 ] . V_165 = V_165 ;
V_172 -> V_164 [ V_172 -> V_161 ] . V_166 = V_157 ;
V_172 -> V_161 ++ ;
V_173 = V_163 + V_157 ;
V_175 = V_160 ;
V_174 += V_157 ;
V_77 = F_86 ( V_62 , V_105 , V_72 - V_157 ) ;
if ( V_77 )
break;
}
if ( ! V_77 && V_172 -> V_161 != 0 ) {
V_172 -> V_182 = V_173 ;
F_84 ( & V_172 -> V_178 , & V_64 -> V_177 ) ;
}
return V_77 ;
}
static void F_87 ( struct V_169 * V_62 , void * V_185 )
{
struct V_170 * V_64 = F_79 ( V_62 ) ;
struct V_158 * V_186 , * V_140 ;
if ( V_185 )
memcpy ( V_64 -> V_105 . V_187 , V_185 , V_64 -> V_105 . V_180 ) ;
F_88 ( & V_64 -> V_105 ) ;
F_89 (c, tmp, &rctx->chunk_list, entry) {
F_90 ( & V_186 -> V_178 ) ;
if ( F_56 ( V_186 != & V_64 -> V_172 ) )
F_91 ( V_186 ) ;
}
}
static int F_92 ( struct V_169 * V_62 , bool V_37 )
{
struct V_170 * V_64 = F_79 ( V_62 ) ;
struct V_51 * V_52 = V_62 -> V_58 . V_52 ;
int V_77 = F_78 ( V_62 ) ;
struct V_158 * V_186 , * V_140 ;
unsigned long V_70 , V_15 ;
struct V_1 * V_96 ;
if ( V_77 )
return V_77 ;
V_96 = V_108 [ F_59 () ] ;
V_77 = - V_106 ;
if ( ! V_96 )
goto V_79;
F_60 ( & V_96 -> V_17 , V_70 ) ;
F_89 (c, tmp, &rctx->chunk_list, entry) {
V_77 = F_76 ( V_52 , V_186 , V_96 , V_37 ) ;
if ( V_77 )
break;
F_90 ( & V_186 -> V_178 ) ;
if ( F_56 ( V_186 != & V_64 -> V_172 ) )
F_91 ( V_186 ) ;
}
if ( ! V_77 ) {
V_15 = F_53 ( V_96 ) ;
if ( V_15 != V_19 )
V_77 = - V_120 ;
}
F_63 ( & V_96 -> V_17 , V_70 ) ;
V_79:
F_64 () ;
F_87 ( V_62 , NULL ) ;
return V_77 ;
}
static int F_93 ( struct V_169 * V_62 )
{
return F_92 ( V_62 , true ) ;
}
static int F_94 ( struct V_169 * V_62 )
{
return F_92 ( V_62 , false ) ;
}
static int F_95 ( struct V_169 * V_62 , bool V_37 )
{
struct V_170 * V_64 = F_79 ( V_62 ) ;
struct V_51 * V_52 = V_62 -> V_58 . V_52 ;
unsigned long V_70 , V_15 , V_168 ;
int V_77 = F_78 ( V_62 ) ;
struct V_158 * V_186 , * V_140 ;
struct V_1 * V_96 ;
void * V_188 ;
V_188 = NULL ;
if ( V_77 )
return V_77 ;
V_96 = V_108 [ F_59 () ] ;
V_77 = - V_106 ;
if ( ! V_96 )
goto V_79;
F_60 ( & V_96 -> V_17 , V_70 ) ;
if ( V_37 ) {
V_168 = F_61 ( V_64 -> V_105 . V_187 ) ;
F_89 (c, tmp, &rctx->chunk_list,
entry) {
V_186 -> V_168 = V_168 ;
V_77 = F_76 ( V_52 , V_186 , V_96 , true ) ;
if ( V_77 )
break;
V_168 = V_186 -> V_182 - V_64 -> V_105 . V_180 ;
F_90 ( & V_186 -> V_178 ) ;
if ( F_56 ( V_186 != & V_64 -> V_172 ) )
F_91 ( V_186 ) ;
}
V_188 = F_96 ( V_168 ) ;
} else {
F_97 (c, tmp, &rctx->chunk_list,
entry) {
if ( V_186 == & V_64 -> V_172 ) {
V_168 = F_61 ( V_64 -> V_105 . V_187 ) ;
} else {
V_168 = ( V_140 -> V_164 [ V_140 -> V_161 - 1 ] . V_165 +
V_140 -> V_164 [ V_140 -> V_161 - 1 ] . V_166 -
V_64 -> V_105 . V_180 ) ;
}
if ( ! V_188 ) {
unsigned long V_189 ;
V_189 = ( V_186 -> V_164 [ V_186 -> V_161 - 1 ] . V_165 +
V_186 -> V_164 [ V_186 -> V_161 - 1 ] . V_166 -
V_64 -> V_105 . V_180 ) ;
V_188 = V_64 -> V_190 ;
memcpy ( V_64 -> V_190 , F_96 ( V_189 ) ,
V_64 -> V_105 . V_180 ) ;
}
V_186 -> V_168 = V_168 ;
V_77 = F_76 ( V_52 , V_186 , V_96 , false ) ;
if ( V_77 )
break;
F_90 ( & V_186 -> V_178 ) ;
if ( F_56 ( V_186 != & V_64 -> V_172 ) )
F_91 ( V_186 ) ;
}
}
if ( ! V_77 ) {
V_15 = F_53 ( V_96 ) ;
if ( V_15 != V_19 )
V_77 = - V_120 ;
}
F_63 ( & V_96 -> V_17 , V_70 ) ;
V_79:
F_64 () ;
F_87 ( V_62 , V_77 ? NULL : V_188 ) ;
return V_77 ;
}
static int F_98 ( struct V_169 * V_62 )
{
return F_95 ( V_62 , true ) ;
}
static int F_99 ( struct V_169 * V_62 )
{
return F_95 ( V_62 , false ) ;
}
static void F_100 ( void )
{
struct V_126 * V_128 , * V_191 ;
struct V_50 * V_54 , * V_192 ;
struct V_59 * V_193 , * V_194 ;
F_89 (cipher, cipher_tmp, &cipher_algs, entry) {
F_101 ( & V_128 -> V_54 ) ;
F_90 ( & V_128 -> V_178 ) ;
F_91 ( V_128 ) ;
}
F_89 (hmac, hmac_tmp, &hmac_algs, derived.entry) {
F_102 ( & V_193 -> V_60 . V_54 ) ;
F_90 ( & V_193 -> V_60 . V_178 ) ;
F_91 ( V_193 ) ;
}
F_89 (alg, alg_tmp, &ahash_algs, entry) {
F_102 ( & V_54 -> V_54 ) ;
F_90 ( & V_54 -> V_178 ) ;
F_91 ( V_54 ) ;
}
}
static int F_103 ( struct V_51 * V_52 )
{
V_52 -> V_195 . V_196 = sizeof( struct V_170 ) ;
return 0 ;
}
static int F_104 ( const struct V_197 * V_198 )
{
struct V_126 * V_199 = F_85 ( sizeof( * V_199 ) , V_200 ) ;
struct V_53 * V_54 ;
int V_77 ;
if ( ! V_199 )
return - V_184 ;
V_54 = & V_199 -> V_54 ;
snprintf ( V_54 -> V_201 , V_202 , L_9 , V_198 -> V_203 ) ;
snprintf ( V_54 -> V_204 , V_202 , L_10 , V_198 -> V_205 ) ;
V_54 -> V_206 = V_207 ;
V_54 -> V_208 = V_209 |
V_210 | V_211 ;
V_54 -> V_212 = V_198 -> V_156 ;
V_199 -> V_31 = V_198 -> V_31 ;
V_54 -> V_213 = sizeof( struct V_129 ) ;
V_54 -> V_214 = & V_215 ;
V_54 -> V_216 . V_217 = V_198 -> V_217 ;
V_54 -> V_218 = F_103 ;
V_54 -> V_219 = V_220 ;
F_105 ( & V_199 -> V_178 , & V_221 ) ;
V_77 = F_106 ( V_54 ) ;
if ( V_77 ) {
F_4 ( L_11 , V_54 -> V_201 ) ;
F_90 ( & V_199 -> V_178 ) ;
F_91 ( V_199 ) ;
} else {
F_77 ( L_12 , V_54 -> V_201 ) ;
}
return V_77 ;
}
static int F_107 ( struct V_50 * V_222 )
{
struct V_59 * V_199 = F_85 ( sizeof( * V_199 ) , V_200 ) ;
struct V_56 * V_76 ;
struct V_53 * V_58 ;
int V_77 ;
if ( ! V_199 )
return - V_184 ;
V_199 -> V_84 = V_222 -> V_54 . V_57 . V_58 . V_201 ;
memcpy ( & V_199 -> V_60 , V_222 , sizeof( struct V_50 ) ) ;
F_82 ( & V_199 -> V_60 . V_178 ) ;
V_76 = & V_199 -> V_60 . V_54 ;
V_76 -> V_223 = F_66 ;
V_76 -> V_224 = F_45 ;
V_58 = & V_76 -> V_57 . V_58 ;
snprintf ( V_58 -> V_201 , V_202 , L_13 , V_199 -> V_84 ) ;
snprintf ( V_58 -> V_204 , V_202 , L_14 , V_199 -> V_84 ) ;
V_58 -> V_213 = sizeof( struct V_80 ) ;
V_58 -> V_218 = F_41 ;
V_58 -> V_225 = F_43 ;
F_105 ( & V_199 -> V_60 . V_178 , & V_226 ) ;
V_77 = F_108 ( V_76 ) ;
if ( V_77 ) {
F_4 ( L_11 , V_58 -> V_201 ) ;
F_90 ( & V_199 -> V_60 . V_178 ) ;
F_91 ( V_199 ) ;
} else {
F_77 ( L_12 , V_58 -> V_201 ) ;
}
return V_77 ;
}
static int F_109 ( const struct V_227 * V_198 )
{
struct V_50 * V_199 = F_85 ( sizeof( * V_199 ) , V_200 ) ;
struct V_228 * V_57 ;
struct V_53 * V_58 ;
struct V_56 * V_76 ;
int V_77 ;
if ( ! V_199 )
return - V_184 ;
V_199 -> V_121 = V_198 -> V_121 ;
V_199 -> V_123 = V_198 -> V_123 ;
V_199 -> V_32 = V_198 -> V_32 ;
V_199 -> V_125 = V_198 -> V_125 ;
V_199 -> V_124 = V_198 -> V_124 ;
V_199 -> V_99 = V_198 -> V_99 ;
V_76 = & V_199 -> V_54 ;
V_76 -> V_229 = F_18 ;
V_76 -> V_230 = F_24 ;
V_76 -> V_231 = F_26 ;
V_76 -> V_232 = F_28 ;
V_76 -> V_223 = F_65 ;
V_57 = & V_76 -> V_57 ;
V_57 -> V_233 = V_198 -> V_99 ;
V_58 = & V_57 -> V_58 ;
snprintf ( V_58 -> V_201 , V_202 , L_9 , V_198 -> V_203 ) ;
snprintf ( V_58 -> V_204 , V_202 , L_10 , V_198 -> V_203 ) ;
V_58 -> V_206 = V_207 ;
V_58 -> V_208 = V_234 |
V_210 |
V_78 ;
V_58 -> V_212 = V_198 -> V_156 ;
V_58 -> V_213 = sizeof( struct V_66 ) ;
V_58 -> V_219 = V_220 ;
V_58 -> V_218 = F_30 ;
V_58 -> V_225 = F_39 ;
F_105 ( & V_199 -> V_178 , & V_235 ) ;
V_77 = F_108 ( V_76 ) ;
if ( V_77 ) {
F_4 ( L_11 , V_58 -> V_201 ) ;
F_90 ( & V_199 -> V_178 ) ;
F_91 ( V_199 ) ;
} else {
F_77 ( L_12 , V_58 -> V_201 ) ;
}
if ( ! V_77 && V_199 -> V_125 != V_236 )
V_77 = F_107 ( V_199 ) ;
return V_77 ;
}
static int F_110 ( void )
{
int V_152 , V_77 = 0 ;
F_111 ( & V_237 ) ;
if ( V_238 ++ )
goto V_79;
for ( V_152 = 0 ; V_152 < V_239 ; V_152 ++ ) {
V_77 = F_109 ( & V_240 [ V_152 ] ) ;
if ( V_77 ) {
F_100 () ;
goto V_79;
}
}
for ( V_152 = 0 ; V_152 < V_241 ; V_152 ++ ) {
V_77 = F_104 ( & V_242 [ V_152 ] ) ;
if ( V_77 ) {
F_100 () ;
goto V_79;
}
}
V_79:
F_112 ( & V_237 ) ;
return V_77 ;
}
static void F_113 ( void )
{
F_111 ( & V_237 ) ;
if ( ! -- V_238 )
F_100 () ;
F_112 ( & V_237 ) ;
}
static int F_114 ( struct V_243 * V_244 , struct V_245 * V_246 ,
unsigned long V_247 )
{
const unsigned int * V_248 ;
unsigned int V_249 ;
int V_152 ;
for ( V_152 = 0 ; V_152 < V_246 -> V_250 ; V_152 ++ ) {
if ( V_246 -> V_251 [ V_152 ] . V_252 == V_247 )
break;
}
if ( V_152 == V_246 -> V_250 )
return - V_106 ;
V_249 = V_246 -> V_251 [ V_152 ] . V_249 ;
V_248 = F_115 ( V_244 -> V_244 . V_253 , L_15 , NULL ) ;
if ( ! V_248 )
return - V_106 ;
for ( V_152 = 0 ; V_152 < V_244 -> V_254 . V_255 ; V_152 ++ ) {
if ( V_248 [ V_152 ] == V_249 )
return V_152 ;
}
return - V_106 ;
}
static int F_116 ( struct V_243 * V_244 , struct V_245 * V_246 ,
const char * V_256 , struct V_1 * V_199 ,
T_5 V_257 )
{
unsigned long V_258 ;
int V_259 ;
V_258 = F_117 ( V_199 -> V_16 , & V_199 -> V_260 ) ;
if ( V_258 )
return - V_120 ;
V_259 = F_114 ( V_244 , V_246 , V_199 -> V_260 ) ;
if ( V_259 < 0 )
return V_259 ;
V_199 -> V_13 = V_244 -> V_254 . V_261 [ V_259 ] ;
sprintf ( V_199 -> V_256 , L_16 , V_256 , V_259 ) ;
return F_118 ( V_199 -> V_13 , V_257 , 0 , V_199 -> V_256 , V_199 ) ;
}
static void * F_119 ( unsigned long V_4 )
{
return F_120 ( V_262 [ V_4 - 1 ] , V_200 ) ;
}
static void F_121 ( void * V_199 , unsigned long V_4 )
{
return F_122 ( V_262 [ V_4 - 1 ] , V_199 ) ;
}
static int F_123 ( void )
{
if ( ! V_262 [ V_5 - 1 ] )
V_262 [ V_5 - 1 ] =
F_124 ( L_17 ,
( V_7 *
V_6 ) ,
V_6 , 0 , NULL ) ;
if ( ! V_262 [ V_5 - 1 ] )
return - V_184 ;
if ( ! V_262 [ V_263 - 1 ] )
V_262 [ V_263 - 1 ] =
F_124 ( L_18 ,
( V_9 *
V_8 ) ,
V_8 , 0 , NULL ) ;
if ( ! V_262 [ V_263 - 1 ] ) {
F_125 ( V_262 [ V_5 - 1 ] ) ;
return - V_184 ;
}
return 0 ;
}
static void F_126 ( void )
{
F_125 ( V_262 [ V_5 - 1 ] ) ;
F_125 ( V_262 [ V_263 - 1 ] ) ;
}
static int F_127 ( struct V_1 * V_199 , unsigned long V_4 )
{
T_6 V_264 ;
unsigned long V_15 ;
if ( F_128 ( & V_199 -> V_265 ) )
return - V_120 ;
if ( ! F_129 ( & V_264 , V_200 ) )
return - V_184 ;
F_130 ( V_264 , & V_266 -> V_267 ) ;
F_131 ( V_266 , & V_199 -> V_265 ) ;
V_15 = F_132 ( V_4 , F_61 ( V_199 -> V_2 ) ,
V_9 , & V_199 -> V_16 ) ;
if ( ! V_15 )
F_8 ( V_199 -> V_16 , 0 ) ;
F_131 ( V_266 , V_264 ) ;
F_133 ( V_264 ) ;
return ( V_15 ? - V_120 : 0 ) ;
}
static int F_134 ( struct V_1 * V_199 )
{
int V_77 ;
V_199 -> V_2 = F_119 ( V_199 -> V_4 ) ;
if ( ! V_199 -> V_2 )
return - V_184 ;
V_77 = F_127 ( V_199 , V_199 -> V_4 ) ;
if ( V_77 ) {
F_121 ( V_199 -> V_2 , V_199 -> V_4 ) ;
V_199 -> V_2 = NULL ;
}
return V_77 ;
}
static void F_135 ( struct V_1 * V_199 )
{
unsigned long V_15 ;
if ( ! V_199 -> V_2 )
return;
V_15 = F_132 ( V_199 -> V_4 , V_199 -> V_16 , 0 , & V_199 -> V_16 ) ;
if ( ! V_15 )
F_121 ( V_199 -> V_2 , V_199 -> V_4 ) ;
}
static void F_136 ( struct V_268 * V_269 )
{
struct V_1 * V_199 , * V_270 ;
F_89 (p, n, list, list) {
int V_152 ;
for ( V_152 = 0 ; V_152 < V_271 ; V_152 ++ ) {
if ( V_108 [ V_152 ] == V_199 )
V_108 [ V_152 ] = NULL ;
}
if ( V_199 -> V_13 ) {
F_137 ( V_199 -> V_13 , V_199 ) ;
V_199 -> V_13 = 0 ;
}
F_135 ( V_199 ) ;
F_90 ( & V_199 -> V_269 ) ;
F_91 ( V_199 ) ;
}
}
static int F_138 ( struct V_272 * V_273 ,
struct V_243 * V_244 ,
T_2 V_274 , struct V_1 * V_199 ,
struct V_1 * * V_275 )
{
T_2 V_276 ;
F_139 (arc, mdesc, node, MDESC_ARC_TYPE_BACK) {
T_2 V_277 = F_140 ( V_273 , V_276 ) ;
const char * V_203 = F_141 ( V_273 , V_277 ) ;
const T_2 * V_278 ;
if ( strcmp ( V_203 , L_19 ) )
continue;
V_278 = F_142 ( V_273 , V_277 , L_20 , NULL ) ;
if ( V_275 [ * V_278 ] != NULL ) {
F_143 ( & V_244 -> V_244 , L_21 ,
V_244 -> V_244 . V_253 -> V_279 ) ;
return - V_120 ;
}
F_144 ( * V_278 , V_199 -> V_265 ) ;
V_275 [ * V_278 ] = V_199 ;
}
return 0 ;
}
static int F_145 ( struct V_245 * V_246 , struct V_268 * V_269 ,
struct V_243 * V_244 , struct V_272 * V_273 ,
T_2 V_274 , const char * V_280 , unsigned long V_4 ,
T_5 V_257 , struct V_1 * * V_275 )
{
struct V_1 * V_199 ;
int V_77 ;
V_199 = F_85 ( sizeof( struct V_1 ) , V_200 ) ;
if ( ! V_199 ) {
F_143 ( & V_244 -> V_244 , L_22 ,
V_244 -> V_244 . V_253 -> V_279 ) ;
return - V_184 ;
}
F_146 ( V_199 -> V_265 ) ;
F_147 ( & V_199 -> V_17 ) ;
V_199 -> V_4 = V_4 ;
F_82 ( & V_199 -> V_281 ) ;
F_105 ( & V_199 -> V_269 , V_269 ) ;
V_77 = F_138 ( V_273 , V_244 , V_274 , V_199 , V_275 ) ;
if ( V_77 )
return V_77 ;
V_77 = F_134 ( V_199 ) ;
if ( V_77 )
return V_77 ;
return F_116 ( V_244 , V_246 , V_280 , V_199 , V_257 ) ;
}
static int F_148 ( struct V_272 * V_273 , struct V_243 * V_244 ,
struct V_245 * V_246 , struct V_268 * V_269 ,
const char * V_282 , unsigned long V_4 ,
T_5 V_257 , struct V_1 * * V_275 )
{
int V_77 = 0 ;
T_2 V_274 ;
F_149 (mdesc, node, L_23 ) {
const char * type ;
type = F_142 ( V_273 , V_274 , L_24 , NULL ) ;
if ( ! type || strcmp ( type , V_282 ) )
continue;
V_77 = F_145 ( V_246 , V_269 , V_244 , V_273 , V_274 ,
V_282 , V_4 , V_257 , V_275 ) ;
if ( V_77 ) {
F_136 ( V_269 ) ;
break;
}
}
return V_77 ;
}
static int F_150 ( struct V_272 * V_273 , T_2 V_274 ,
struct V_245 * V_246 )
{
const T_2 * V_252 ;
int V_283 ;
int V_152 ;
V_252 = F_142 ( V_273 , V_274 , L_25 , & V_283 ) ;
if ( ! V_252 ) {
F_151 ( L_26 ) ;
return - V_106 ;
}
V_246 -> V_250 = V_283 / sizeof( T_2 ) ;
V_246 -> V_251 = F_85 ( ( sizeof( struct V_284 ) *
V_246 -> V_250 ) ,
V_200 ) ;
if ( ! V_246 -> V_251 )
return - V_184 ;
for ( V_152 = 0 ; V_152 < V_246 -> V_250 ; V_152 ++ ) {
struct V_284 * V_285 = & V_246 -> V_251 [ V_152 ] ;
V_285 -> V_249 = V_152 + 1 ;
V_285 -> V_252 = V_252 [ V_152 ] ;
}
return 0 ;
}
static int F_152 ( struct V_272 * V_273 ,
struct V_243 * V_244 ,
struct V_245 * V_246 ,
const char * V_286 )
{
const unsigned int * V_287 ;
T_2 V_274 ;
V_287 = F_115 ( V_244 -> V_244 . V_253 , L_27 , NULL ) ;
if ( ! V_287 )
return - V_106 ;
F_149 (mdesc, node, L_28 ) {
const char * V_203 ;
const T_2 * V_288 ;
V_203 = F_142 ( V_273 , V_274 , L_29 , NULL ) ;
if ( ! V_203 || strcmp ( V_203 , V_286 ) )
continue;
V_288 = F_142 ( V_273 , V_274 , L_30 , NULL ) ;
if ( ! V_288 || ( * V_288 != * V_287 ) )
continue;
V_246 -> V_289 = * V_288 ;
return F_150 ( V_273 , V_274 , V_246 ) ;
}
return - V_106 ;
}
static int F_153 ( void )
{
int V_77 ;
V_290 = 2 ;
V_291 = 0 ;
V_77 = F_154 ( V_292 ,
V_290 ,
& V_291 ) ;
if ( ! V_77 )
F_77 ( L_31 ,
V_290 ,
V_291 ) ;
return V_77 ;
}
static void F_155 ( void )
{
F_156 ( V_292 ) ;
}
static int F_157 ( void )
{
int V_77 = 0 ;
F_111 ( & V_237 ) ;
if ( V_293 ++ )
goto V_79;
V_77 = F_153 () ;
if ( V_77 )
goto V_79;
V_77 = F_123 () ;
if ( V_77 )
goto V_294;
V_77 = - V_184 ;
V_108 = F_85 ( sizeof( struct V_1 * ) * V_271 ,
V_200 ) ;
if ( ! V_108 )
goto V_295;
V_296 = F_85 ( sizeof( struct V_1 * ) * V_271 ,
V_200 ) ;
if ( ! V_296 )
goto V_297;
V_77 = 0 ;
V_79:
if ( V_77 )
V_293 -- ;
F_112 ( & V_237 ) ;
return V_77 ;
V_297:
F_91 ( V_108 ) ;
V_108 = NULL ;
V_295:
F_126 () ;
V_294:
F_155 () ;
goto V_79;
}
static void F_158 ( void )
{
F_111 ( & V_237 ) ;
if ( ! -- V_293 ) {
F_91 ( V_108 ) ;
V_108 = NULL ;
F_91 ( V_296 ) ;
V_296 = NULL ;
F_126 () ;
F_155 () ;
}
F_112 ( & V_237 ) ;
}
static struct V_298 * F_159 ( void )
{
struct V_298 * V_299 = F_85 ( sizeof( struct V_298 ) , V_200 ) ;
if ( V_299 )
F_82 ( & V_299 -> V_300 ) ;
return V_299 ;
}
static void F_160 ( struct V_298 * V_299 )
{
if ( V_299 -> V_301 . V_251 ) {
F_91 ( V_299 -> V_301 . V_251 ) ;
V_299 -> V_301 . V_251 = NULL ;
}
F_91 ( V_299 ) ;
}
static void F_161 ( void )
{
static int V_302 ;
if ( V_302 ++ == 0 )
F_77 ( L_9 , V_303 ) ;
}
static int F_162 ( struct V_243 * V_244 )
{
struct V_272 * V_273 ;
const char * V_279 ;
struct V_298 * V_299 ;
int V_77 ;
F_161 () ;
V_279 = V_244 -> V_244 . V_253 -> V_279 ;
F_77 ( L_32 , V_279 ) ;
V_299 = F_159 () ;
if ( ! V_299 ) {
F_143 ( & V_244 -> V_244 , L_33 ,
V_279 ) ;
return - V_184 ;
}
V_77 = F_157 () ;
if ( V_77 ) {
F_143 ( & V_244 -> V_244 , L_34
L_35 , V_279 ) ;
goto V_304;
}
V_273 = F_163 () ;
if ( ! V_273 ) {
F_143 ( & V_244 -> V_244 , L_36 ,
V_279 ) ;
V_77 = - V_106 ;
goto V_305;
}
V_77 = F_152 ( V_273 , V_244 , & V_299 -> V_301 , L_37 ) ;
if ( V_77 ) {
F_143 ( & V_244 -> V_244 , L_38 ,
V_279 ) ;
F_164 ( V_273 ) ;
goto V_305;
}
V_77 = F_148 ( V_273 , V_244 , & V_299 -> V_301 , & V_299 -> V_300 ,
L_39 , V_263 , F_3 ,
V_108 ) ;
F_164 ( V_273 ) ;
if ( V_77 ) {
F_143 ( & V_244 -> V_244 , L_40 ,
V_279 ) ;
goto V_305;
}
V_77 = F_110 () ;
if ( V_77 ) {
F_143 ( & V_244 -> V_244 , L_41 ,
V_279 ) ;
goto V_306;
}
F_165 ( & V_244 -> V_244 , V_299 ) ;
return 0 ;
V_306:
F_136 ( & V_299 -> V_300 ) ;
V_305:
F_158 () ;
V_304:
F_160 ( V_299 ) ;
return V_77 ;
}
static int F_166 ( struct V_243 * V_244 )
{
struct V_298 * V_299 = F_167 ( & V_244 -> V_244 ) ;
F_113 () ;
F_136 ( & V_299 -> V_300 ) ;
F_158 () ;
F_160 ( V_299 ) ;
return 0 ;
}
static struct V_307 * F_168 ( void )
{
struct V_307 * V_308 = F_85 ( sizeof( struct V_307 ) , V_200 ) ;
if ( V_308 )
F_82 ( & V_308 -> V_309 ) ;
return V_308 ;
}
static void F_169 ( struct V_307 * V_308 )
{
if ( V_308 -> V_310 . V_251 ) {
F_91 ( V_308 -> V_310 . V_251 ) ;
V_308 -> V_310 . V_251 = NULL ;
}
F_91 ( V_308 ) ;
}
static int F_170 ( struct V_243 * V_244 )
{
struct V_272 * V_273 ;
const char * V_279 ;
struct V_307 * V_308 ;
int V_77 ;
F_161 () ;
V_279 = V_244 -> V_244 . V_253 -> V_279 ;
F_77 ( L_42 , V_279 ) ;
V_308 = F_168 () ;
if ( ! V_308 ) {
F_143 ( & V_244 -> V_244 , L_43 ,
V_279 ) ;
return - V_184 ;
}
V_77 = F_157 () ;
if ( V_77 ) {
F_143 ( & V_244 -> V_244 , L_34
L_35 , V_279 ) ;
goto V_311;
}
V_273 = F_163 () ;
if ( ! V_273 ) {
F_143 ( & V_244 -> V_244 , L_36 ,
V_279 ) ;
V_77 = - V_106 ;
goto V_305;
}
V_77 = F_152 ( V_273 , V_244 , & V_308 -> V_310 , L_44 ) ;
if ( V_77 ) {
F_143 ( & V_244 -> V_244 , L_38 ,
V_279 ) ;
F_164 ( V_273 ) ;
goto V_305;
}
V_77 = F_148 ( V_273 , V_244 , & V_308 -> V_310 , & V_308 -> V_309 ,
L_45 , V_5 , F_10 ,
V_296 ) ;
F_164 ( V_273 ) ;
if ( V_77 ) {
F_143 ( & V_244 -> V_244 , L_46 ,
V_279 ) ;
goto V_305;
}
F_165 ( & V_244 -> V_244 , V_308 ) ;
return 0 ;
V_305:
F_158 () ;
V_311:
F_169 ( V_308 ) ;
return V_77 ;
}
static int F_171 ( struct V_243 * V_244 )
{
struct V_307 * V_308 = F_167 ( & V_244 -> V_244 ) ;
F_136 ( & V_308 -> V_309 ) ;
F_158 () ;
F_169 ( V_308 ) ;
return 0 ;
}
static int T_7 F_172 ( void )
{
int V_77 = F_173 ( & V_312 ) ;
if ( ! V_77 ) {
V_77 = F_173 ( & V_313 ) ;
if ( V_77 )
F_174 ( & V_312 ) ;
}
return V_77 ;
}
static void T_8 F_175 ( void )
{
F_174 ( & V_313 ) ;
F_174 ( & V_312 ) ;
}
