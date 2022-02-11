static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
V_4 = V_3 -> V_6 ;
if ( V_4 && V_4 -> V_7 == 0 )
V_4 = NULL ;
if ( V_4 )
V_4 -> V_7 ++ ;
F_3 ( & V_5 ) ;
return V_4 ;
}
static inline int F_4 ( struct V_2 * V_3 )
{
int V_8 = F_5 ( F_6 ( V_3 ) ) ;
int V_9 = F_7 ( F_6 ( V_3 ) ) / V_10 ;
if ( ! V_8 )
V_9 = V_3 -> V_11 / V_10 ;
return V_9 ;
}
static void F_8 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
V_4 -> V_7 -- ;
if ( V_4 -> V_7 == 0 ) {
int V_9 = F_4 ( V_4 -> V_3 ) ;
F_9 ( V_4 -> V_12 . V_12 ) ;
F_10 ( V_9 , V_13 ) ;
F_11 ( V_4 -> V_3 ) ;
F_12 ( V_4 ) ;
}
F_3 ( & V_5 ) ;
}
static T_1 F_13 ( struct V_14 * V_15 , struct V_16 * V_17 ,
char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
V_19 = snprintf ( V_18 , V_20 , L_1 ,
F_15 ( F_14 ( V_15 ) ) ^
V_4 -> V_21 ) ;
F_8 ( V_4 ) ;
return V_19 ;
}
static T_1 F_16 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const char * V_18 , T_2 V_22 )
{
int V_19 ;
char * V_23 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
unsigned long V_24 = F_17 ( V_18 , & V_23 , 0 ) ;
if ( V_23 == V_18 ) {
V_19 = - V_25 ;
goto V_26;
}
F_18 ( F_14 ( V_15 ) , V_24 || V_4 -> V_21 ) ;
V_19 = V_22 ;
V_26:
F_8 ( V_4 ) ;
return V_19 ;
}
static int F_19 ( struct V_27 * V_28 , T_3 V_29 )
{
struct V_1 * V_4 = F_1 ( V_28 -> V_30 ) ;
int V_19 = - V_31 ;
F_2 ( & V_32 ) ;
if ( V_4 ) {
if ( V_4 -> V_7 == 2 )
F_20 ( V_28 ) ;
V_19 = 0 ;
if ( ( V_29 & V_33 ) && V_4 -> V_21 ) {
F_8 ( V_4 ) ;
V_19 = - V_34 ;
}
}
F_3 ( & V_32 ) ;
return V_19 ;
}
static int F_21 ( struct V_2 * V_3 , T_3 V_29 )
{
struct V_1 * V_4 = V_3 -> V_6 ;
F_2 ( & V_32 ) ;
F_8 ( V_4 ) ;
F_3 ( & V_32 ) ;
return 0 ;
}
static int
F_22 ( struct V_27 * V_28 , struct V_35 * V_36 )
{
V_36 -> V_37 = F_23 ( V_28 -> V_30 ) / ( 4 * 16 ) ;
V_36 -> V_38 = 4 ;
V_36 -> V_39 = 16 ;
return 0 ;
}
static struct V_40 * F_24 (
struct V_41 T_4 * V_42 )
{
struct V_40 * V_43 ;
int V_44 ;
V_43 = F_25 ( sizeof( * V_43 ) , V_45 ) ;
if ( ! V_43 ) {
V_44 = - V_46 ;
goto V_26;
}
if ( F_26 ( & V_43 -> V_47 , V_42 , sizeof( V_43 -> V_47 ) ) ) {
V_44 = - V_48 ;
goto V_49;
}
V_43 -> V_50 = ( V_51 ) V_43 -> V_47 . V_52 * V_43 -> V_47 . V_53 ;
if ( V_43 -> V_50 > V_54 ) {
V_44 = - V_55 ;
goto V_49;
}
V_43 -> V_18 = F_25 ( V_43 -> V_50 , V_45 ) ;
if ( ! V_43 -> V_18 ) {
V_44 = - V_46 ;
goto V_49;
}
if ( F_26 ( V_43 -> V_18 , ( void T_4 * ) ( unsigned long )
V_43 -> V_47 . V_56 , V_43 -> V_50 ) ) {
V_44 = - V_48 ;
goto V_57;
}
return V_43 ;
V_57:
F_12 ( V_43 -> V_18 ) ;
V_49:
F_12 ( V_43 ) ;
V_26:
return F_27 ( V_44 ) ;
}
static int F_28 ( struct V_27 * V_28 ,
struct V_41 T_4 * V_58 )
{
struct V_40 * V_43 ;
struct V_1 * V_4 ;
struct V_59 * V_60 ;
struct V_61 V_62 = { 0 } ;
struct V_63 V_64 = { 0 } ;
struct V_65 V_66 = { 0 } ;
struct V_67 V_68 ;
int V_44 ;
if ( ( ! F_29 ( V_69 ) ) || ( V_28 != V_28 -> V_70 ) )
return - V_71 ;
V_43 = F_24 ( V_58 ) ;
if ( F_30 ( V_43 ) )
return F_31 ( V_43 ) ;
V_62 . V_72 = V_43 -> V_47 . V_72 ;
V_62 . V_73 = V_43 -> V_47 . V_73 ;
V_62 . V_74 = V_43 -> V_47 . V_74 ;
V_64 . V_68 = & V_68 ;
V_64 . V_75 = 1 ;
V_64 . V_52 = V_43 -> V_47 . V_52 ;
V_64 . V_53 = V_43 -> V_47 . V_53 ;
F_32 ( V_64 . V_68 , V_43 -> V_18 , V_43 -> V_50 ) ;
if ( V_43 -> V_47 . V_76 )
V_64 . V_74 = V_77 ;
else
V_64 . V_74 = V_78 ;
V_66 . V_62 = & V_62 ;
V_66 . V_64 = & V_64 ;
V_4 = F_1 ( V_28 -> V_30 ) ;
if ( ! V_4 ) {
V_44 = - V_25 ;
goto V_79;
}
V_60 = V_4 -> V_12 . V_60 ;
if ( F_30 ( V_60 ) ) {
V_44 = F_31 ( V_60 ) ;
goto V_79;
}
F_33 ( V_60 -> V_80 ) ;
if ( V_43 -> V_47 . V_81 ) {
V_44 = F_34 ( V_60 -> V_80 , V_60 ) ;
if ( V_44 )
goto V_82;
}
F_35 ( & V_64 , V_60 ) ;
if ( V_43 -> V_47 . V_83 )
V_64 . V_84 = V_43 -> V_47 . V_83 ;
if ( ( V_62 . V_74 & V_85 ) == V_85 ) {
V_64 . V_84 = V_43 -> V_47 . V_86 * 1000000 ;
}
F_36 ( V_60 -> V_80 , & V_66 ) ;
if ( V_62 . error ) {
F_37 ( F_38 ( V_60 -> V_80 ) , L_2 ,
V_87 , V_62 . error ) ;
V_44 = V_62 . error ;
goto V_82;
}
if ( V_64 . error ) {
F_37 ( F_38 ( V_60 -> V_80 ) , L_3 ,
V_87 , V_64 . error ) ;
V_44 = V_64 . error ;
goto V_82;
}
if ( V_43 -> V_47 . V_88 )
F_39 ( V_43 -> V_47 . V_88 , V_43 -> V_47 . V_89 ) ;
if ( F_40 ( & ( V_58 -> V_90 ) , V_62 . V_91 , sizeof( V_62 . V_91 ) ) ) {
V_44 = - V_48 ;
goto V_82;
}
if ( ! V_43 -> V_47 . V_76 ) {
if ( F_40 ( ( void T_4 * ) ( unsigned long ) V_43 -> V_47 . V_56 ,
V_43 -> V_18 , V_43 -> V_50 ) ) {
V_44 = - V_48 ;
goto V_82;
}
}
V_82:
F_41 ( V_60 -> V_80 ) ;
V_79:
F_8 ( V_4 ) ;
F_12 ( V_43 -> V_18 ) ;
F_12 ( V_43 ) ;
return V_44 ;
}
static int F_42 ( struct V_27 * V_28 , T_3 V_29 ,
unsigned int V_62 , unsigned long V_73 )
{
int V_19 = - V_25 ;
if ( V_62 == V_92 )
V_19 = F_28 ( V_28 , (struct V_41 T_4 * ) V_73 ) ;
return V_19 ;
}
static int F_43 ( struct V_27 * V_28 , T_3 V_29 ,
unsigned int V_62 , unsigned long V_73 )
{
return F_42 ( V_28 , V_29 , V_62 , ( unsigned long ) F_44 ( V_73 ) ) ;
}
static inline int F_45 ( struct V_59 * V_60 ,
struct V_1 * V_4 )
{
int V_19 ;
struct V_1 * V_93 = F_46 ( V_60 ) ;
if ( V_93 -> V_94 == V_4 -> V_95 )
return 0 ;
if ( F_47 ( V_60 ) ) {
V_60 -> V_96 . V_97 &= ~ V_98 ;
V_60 -> V_96 . V_97 |= V_4 -> V_95 ;
V_19 = F_48 ( V_60 , V_99 ,
V_100 , V_60 -> V_96 . V_97 ,
V_60 -> V_96 . V_101 ) ;
if ( V_19 )
return V_19 ;
}
V_93 -> V_94 = V_4 -> V_95 ;
return 0 ;
}
static T_5 F_49 ( struct V_59 * V_60 )
{
int V_44 ;
T_5 V_102 ;
T_6 * V_53 ;
struct V_65 V_66 = { 0 } ;
struct V_61 V_62 = { 0 } ;
struct V_63 V_64 = { 0 } ;
unsigned int V_103 ;
struct V_67 V_68 ;
V_62 . V_72 = V_104 ;
V_62 . V_73 = V_60 -> V_105 << 16 ;
V_62 . V_74 = V_106 | V_107 | V_108 ;
V_44 = F_50 ( V_60 -> V_80 , & V_62 , 0 ) ;
if ( V_44 )
return ( T_5 ) - 1 ;
if ( ! F_51 ( V_60 -> V_80 ) && ! ( V_62 . V_91 [ 0 ] & V_109 ) )
return ( T_5 ) - 1 ;
memset ( & V_62 , 0 , sizeof( struct V_61 ) ) ;
V_62 . V_72 = V_110 ;
V_62 . V_73 = 0 ;
V_62 . V_74 = V_106 | V_107 | V_111 ;
V_64 . V_84 = V_60 -> V_112 . V_113 * 100 ;
V_64 . V_114 = V_60 -> V_112 . V_115 * 100 ;
V_103 = V_64 . V_84 / 1000 ;
V_103 += V_64 . V_114 * 1000 /
( V_60 -> V_80 -> V_116 . clock / 1000 ) ;
if ( V_103 > 100000 ) {
V_64 . V_84 = 100000000 ;
V_64 . V_114 = 0 ;
}
V_64 . V_52 = 4 ;
V_64 . V_53 = 1 ;
V_64 . V_74 = V_78 ;
V_64 . V_68 = & V_68 ;
V_64 . V_75 = 1 ;
V_66 . V_62 = & V_62 ;
V_66 . V_64 = & V_64 ;
V_53 = F_52 ( 4 , V_45 ) ;
if ( ! V_53 )
return ( T_5 ) - 1 ;
F_32 ( & V_68 , V_53 , 4 ) ;
F_36 ( V_60 -> V_80 , & V_66 ) ;
V_102 = F_53 ( * V_53 ) ;
F_12 ( V_53 ) ;
if ( V_62 . error || V_64 . error )
V_102 = ( T_5 ) - 1 ;
return V_102 ;
}
static T_5 F_54 ( struct V_59 * V_60 , struct V_117 * V_118 )
{
struct V_61 V_62 = { 0 } ;
int V_44 ;
V_62 . V_72 = V_119 ;
if ( ! F_51 ( V_60 -> V_80 ) )
V_62 . V_73 = V_60 -> V_105 << 16 ;
V_62 . V_74 = V_120 | V_107 | V_108 ;
V_44 = F_50 ( V_60 -> V_80 , & V_62 , 0 ) ;
if ( V_44 )
F_55 ( V_121 L_4 ,
V_118 -> V_122 -> V_123 , V_44 ) ;
return V_62 . V_91 [ 0 ] ;
}
static int F_56 ( struct V_124 * V_125 , struct V_117 * V_118 )
{
struct V_1 * V_4 = V_125 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
unsigned int V_126 , V_127 , V_73 ;
int V_44 = 0 ;
if ( ! F_57 ( V_60 ) ) {
V_44 = - V_128 ;
goto V_26;
}
V_126 = F_58 ( V_118 ) ;
V_127 = F_59 ( V_118 ) ;
if ( F_60 ( V_60 ) )
V_73 = V_129 ;
else
V_73 = V_130 ;
if ( V_60 -> V_131 & V_132 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_133 ,
V_73 == V_129 ?
V_134 :
V_135 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_61 ( V_60 , V_126 , V_127 , V_73 ) ;
V_26:
F_62 ( & V_4 -> V_136 ) ;
F_63 ( V_118 , V_44 , F_64 ( V_118 ) ) ;
F_65 ( & V_4 -> V_136 ) ;
return V_44 ? 0 : 1 ;
}
static int F_66 ( struct V_124 * V_125 ,
struct V_117 * V_118 )
{
struct V_1 * V_4 = V_125 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
unsigned int V_126 , V_127 , V_73 ;
int V_44 = 0 ;
if ( ! F_67 ( V_60 ) ) {
V_44 = - V_128 ;
goto V_26;
}
V_126 = F_58 ( V_118 ) ;
V_127 = F_59 ( V_118 ) ;
if ( F_60 ( V_60 ) && ! F_68 ( V_60 , V_126 , V_127 ) )
V_73 = V_137 ;
else
V_73 = V_138 ;
if ( V_60 -> V_131 & V_132 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_133 ,
V_73 == V_137 ?
V_139 :
V_140 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_61 ( V_60 , V_126 , V_127 , V_73 ) ;
if ( ! V_44 && V_73 == V_137 ) {
if ( V_60 -> V_131 & V_132 ) {
V_44 = F_48 ( V_60 , V_99 ,
V_133 ,
V_141 ,
0 ) ;
if ( V_44 )
goto V_26;
}
V_44 = F_61 ( V_60 , V_126 , V_127 , V_142 ) ;
}
V_26:
F_62 ( & V_4 -> V_136 ) ;
F_63 ( V_118 , V_44 , F_64 ( V_118 ) ) ;
F_65 ( & V_4 -> V_136 ) ;
return V_44 ? 0 : 1 ;
}
static int F_69 ( struct V_124 * V_125 , struct V_117 * V_118 )
{
struct V_1 * V_4 = V_125 -> V_64 ;
F_62 ( & V_4 -> V_136 ) ;
F_70 ( V_118 , 0 ) ;
F_65 ( & V_4 -> V_136 ) ;
return 1 ;
}
static inline void F_71 ( struct V_143 * V_144 ,
struct V_59 * V_60 ,
struct V_117 * V_118 )
{
if ( ! ( V_60 -> V_96 . V_145 & V_146 ) ) {
if ( ! F_72 ( V_144 -> V_62 . V_73 , V_60 -> V_96 . V_147 ) )
V_144 -> V_64 . V_53 = 1 ;
if ( V_144 -> V_64 . V_53 > V_60 -> V_96 . V_147 )
V_144 -> V_64 . V_53 = V_60 -> V_96 . V_147 ;
else if ( V_144 -> V_64 . V_53 < V_60 -> V_96 . V_147 )
V_144 -> V_64 . V_53 = 1 ;
}
}
static int F_73 ( struct V_124 * V_125 , struct V_117 * V_118 )
{
struct V_1 * V_4 = V_125 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
struct V_143 V_144 ;
int V_19 = 1 , V_148 = 0 ;
bool V_149 = ( ( V_118 -> V_150 & V_151 ) ||
( V_118 -> V_150 & V_152 ) ) &&
( F_74 ( V_118 ) == V_153 ) &&
( V_4 -> V_74 & V_154 ) ;
do {
struct V_61 V_62 = { 0 } ;
T_5 V_155 , V_156 , V_157 = 0 ;
memset ( & V_144 , 0 , sizeof( struct V_143 ) ) ;
V_144 . V_66 . V_62 = & V_144 . V_62 ;
V_144 . V_66 . V_64 = & V_144 . V_64 ;
V_144 . V_62 . V_73 = F_58 ( V_118 ) ;
if ( ! F_75 ( V_60 ) )
V_144 . V_62 . V_73 <<= 9 ;
V_144 . V_62 . V_74 = V_106 | V_107 | V_111 ;
V_144 . V_64 . V_52 = 512 ;
V_144 . V_158 . V_72 = V_159 ;
V_144 . V_158 . V_73 = 0 ;
V_144 . V_158 . V_74 = V_160 | V_85 | V_108 ;
V_144 . V_64 . V_53 = F_59 ( V_118 ) ;
if ( V_144 . V_64 . V_53 > V_60 -> V_80 -> V_161 )
V_144 . V_64 . V_53 = V_60 -> V_80 -> V_161 ;
if ( V_148 && V_144 . V_64 . V_53 > 1 )
V_144 . V_64 . V_53 = 1 ;
if ( V_144 . V_64 . V_53 > 1 || V_149 ) {
if ( ! F_51 ( V_60 -> V_80 ) ||
F_74 ( V_118 ) == V_162 )
V_144 . V_66 . V_158 = & V_144 . V_158 ;
V_155 = V_163 ;
V_156 = V_164 ;
} else {
V_144 . V_66 . V_158 = NULL ;
V_155 = V_165 ;
V_156 = V_166 ;
}
if ( F_74 ( V_118 ) == V_162 ) {
V_144 . V_62 . V_72 = V_155 ;
V_144 . V_64 . V_74 |= V_78 ;
} else {
V_144 . V_62 . V_72 = V_156 ;
V_144 . V_64 . V_74 |= V_77 ;
}
if ( V_149 )
F_71 ( & V_144 , V_60 , V_118 ) ;
if ( ( V_4 -> V_74 & V_167 ) &&
F_76 ( V_144 . V_62 . V_72 ) &&
( V_149 || ! ( V_60 -> V_131 & V_168 ) ) ) {
V_144 . V_169 . V_72 = V_170 ;
V_144 . V_169 . V_73 = V_144 . V_64 . V_53 |
( V_149 ? ( 1 << 31 ) : 0 ) ;
V_144 . V_169 . V_74 = V_107 | V_108 ;
V_144 . V_66 . V_169 = & V_144 . V_169 ;
}
F_35 ( & V_144 . V_64 , V_60 ) ;
V_144 . V_64 . V_68 = V_125 -> V_68 ;
V_144 . V_64 . V_75 = F_77 ( V_125 ) ;
if ( V_144 . V_64 . V_53 != F_59 ( V_118 ) ) {
int V_171 , V_172 = V_144 . V_64 . V_53 << 9 ;
struct V_67 * V_68 ;
F_78 (brq.data.sg, sg, brq.data.sg_len, i) {
V_172 -= V_68 -> V_173 ;
if ( V_172 <= 0 ) {
V_68 -> V_173 += V_172 ;
V_171 ++ ;
break;
}
}
V_144 . V_64 . V_75 = V_171 ;
}
F_79 ( V_125 ) ;
F_36 ( V_60 -> V_80 , & V_144 . V_66 ) ;
F_80 ( V_125 ) ;
if ( V_144 . V_169 . error || V_144 . V_62 . error ||
V_144 . V_64 . error || V_144 . V_158 . error ) {
if ( V_144 . V_64 . V_53 > 1 && F_74 ( V_118 ) == V_162 ) {
F_55 ( V_174 L_5
L_6 , V_118 -> V_122 -> V_123 ) ;
V_148 = 1 ;
continue;
}
V_157 = F_54 ( V_60 , V_118 ) ;
}
if ( V_144 . V_169 . error ) {
F_55 ( V_121 L_7
L_8 ,
V_118 -> V_122 -> V_123 , V_144 . V_169 . error ,
V_144 . V_169 . V_91 [ 0 ] , V_157 ) ;
}
if ( V_144 . V_62 . error ) {
F_55 ( V_121 L_9
L_8 ,
V_118 -> V_122 -> V_123 , V_144 . V_62 . error ,
V_144 . V_62 . V_91 [ 0 ] , V_157 ) ;
}
if ( V_144 . V_64 . error ) {
if ( V_144 . V_64 . error == - V_175 && V_144 . V_66 . V_158 )
V_157 = V_144 . V_66 . V_158 -> V_91 [ 0 ] ;
F_55 ( V_121 L_10
L_11 ,
V_118 -> V_122 -> V_123 , V_144 . V_64 . error ,
( unsigned ) F_58 ( V_118 ) ,
( unsigned ) F_59 ( V_118 ) , V_157 ) ;
}
if ( V_144 . V_158 . error ) {
F_55 ( V_121 L_12
L_13 ,
V_118 -> V_122 -> V_123 , V_144 . V_158 . error ,
V_144 . V_158 . V_91 [ 0 ] , V_157 ) ;
}
if ( ! F_51 ( V_60 -> V_80 ) && F_74 ( V_118 ) != V_162 ) {
do {
int V_44 ;
V_62 . V_72 = V_119 ;
V_62 . V_73 = V_60 -> V_105 << 16 ;
V_62 . V_74 = V_107 | V_108 ;
V_44 = F_50 ( V_60 -> V_80 , & V_62 , 5 ) ;
if ( V_44 ) {
F_55 ( V_121 L_14 ,
V_118 -> V_122 -> V_123 , V_44 ) ;
goto V_176;
}
} while ( ! ( V_62 . V_91 [ 0 ] & V_177 ) ||
( F_81 ( V_62 . V_91 [ 0 ] ) == 7 ) );
#if 0
if (cmd.resp[0] & ~0x00000900)
printk(KERN_ERR "%s: status = %08x\n",
req->rq_disk->disk_name, cmd.resp[0]);
if (mmc_decode_status(cmd.resp))
goto cmd_err;
#endif
}
if ( V_144 . V_62 . error || V_144 . V_158 . error || V_144 . V_64 . error ) {
if ( F_74 ( V_118 ) == V_162 ) {
F_62 ( & V_4 -> V_136 ) ;
V_19 = F_63 ( V_118 , - V_178 , V_144 . V_64 . V_52 ) ;
F_65 ( & V_4 -> V_136 ) ;
continue;
}
goto V_176;
}
F_62 ( & V_4 -> V_136 ) ;
V_19 = F_63 ( V_118 , 0 , V_144 . V_64 . V_179 ) ;
F_65 ( & V_4 -> V_136 ) ;
} while ( V_19 );
return 1 ;
V_176:
if ( F_82 ( V_60 ) ) {
T_5 V_53 ;
V_53 = F_49 ( V_60 ) ;
if ( V_53 != ( T_5 ) - 1 ) {
F_62 ( & V_4 -> V_136 ) ;
V_19 = F_63 ( V_118 , 0 , V_53 << 9 ) ;
F_65 ( & V_4 -> V_136 ) ;
}
} else {
F_62 ( & V_4 -> V_136 ) ;
V_19 = F_63 ( V_118 , 0 , V_144 . V_64 . V_179 ) ;
F_65 ( & V_4 -> V_136 ) ;
}
F_62 ( & V_4 -> V_136 ) ;
while ( V_19 )
V_19 = F_63 ( V_118 , - V_178 , F_83 ( V_118 ) ) ;
F_65 ( & V_4 -> V_136 ) ;
return 0 ;
}
static int F_84 ( struct V_124 * V_125 , struct V_117 * V_118 )
{
int V_19 ;
struct V_1 * V_4 = V_125 -> V_64 ;
struct V_59 * V_60 = V_4 -> V_12 . V_60 ;
F_33 ( V_60 -> V_80 ) ;
V_19 = F_45 ( V_60 , V_4 ) ;
if ( V_19 ) {
V_19 = 0 ;
goto V_26;
}
if ( V_118 -> V_150 & V_180 ) {
if ( V_118 -> V_150 & V_181 )
V_19 = F_66 ( V_125 , V_118 ) ;
else
V_19 = F_56 ( V_125 , V_118 ) ;
} else if ( V_118 -> V_150 & V_182 ) {
V_19 = F_69 ( V_125 , V_118 ) ;
} else {
V_19 = F_73 ( V_125 , V_118 ) ;
}
V_26:
F_41 ( V_60 -> V_80 ) ;
return V_19 ;
}
static inline int F_85 ( struct V_59 * V_60 )
{
return F_86 ( V_60 ) ||
! ( V_60 -> V_112 . V_183 & V_184 ) ;
}
static struct V_1 * F_87 ( struct V_59 * V_60 ,
struct V_14 * V_185 ,
T_7 V_186 ,
bool V_187 ,
const char * V_188 )
{
struct V_1 * V_4 ;
int V_9 , V_19 ;
V_9 = F_88 ( V_13 , V_189 ) ;
if ( V_9 >= V_189 )
return F_27 ( - V_190 ) ;
F_89 ( V_9 , V_13 ) ;
V_4 = F_25 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_4 ) {
V_19 = - V_46 ;
goto V_26;
}
if ( ! V_188 ) {
V_4 -> V_191 = F_88 ( V_192 , V_189 ) ;
F_89 ( V_4 -> V_191 , V_192 ) ;
}
else
V_4 -> V_191 = ( (struct V_1 * )
F_14 ( V_185 ) -> V_6 ) -> V_191 ;
V_4 -> V_21 = F_85 ( V_60 ) ;
V_4 -> V_3 = F_90 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_19 = - V_46 ;
goto V_193;
}
F_91 ( & V_4 -> V_136 ) ;
F_92 ( & V_4 -> V_194 ) ;
V_4 -> V_7 = 1 ;
V_19 = F_93 ( & V_4 -> V_12 , V_60 , & V_4 -> V_136 , V_188 ) ;
if ( V_19 )
goto V_195;
V_4 -> V_12 . V_196 = F_84 ;
V_4 -> V_12 . V_64 = V_4 ;
V_4 -> V_3 -> V_197 = V_198 ;
V_4 -> V_3 -> V_11 = V_9 * V_10 ;
V_4 -> V_3 -> V_199 = & V_200 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_12 = V_4 -> V_12 . V_12 ;
V_4 -> V_3 -> V_201 = V_185 ;
F_18 ( V_4 -> V_3 , V_4 -> V_21 || V_187 ) ;
snprintf ( V_4 -> V_3 -> V_123 , sizeof( V_4 -> V_3 -> V_123 ) ,
L_15 , V_4 -> V_191 , V_188 ? V_188 : L_16 ) ;
F_94 ( V_4 -> V_12 . V_12 , 512 ) ;
F_95 ( V_4 -> V_3 , V_186 ) ;
if ( F_96 ( V_60 -> V_80 ) ) {
if ( F_47 ( V_60 ) ||
( F_82 ( V_60 ) &&
V_60 -> V_202 . V_203 & V_204 ) )
V_4 -> V_74 |= V_167 ;
}
if ( F_47 ( V_60 ) &&
V_4 -> V_74 & V_167 &&
( ( V_60 -> V_96 . V_145 & V_146 ) ||
V_60 -> V_96 . V_147 ) ) {
V_4 -> V_74 |= V_154 ;
F_97 ( V_4 -> V_12 . V_12 , V_182 | V_151 ) ;
}
return V_4 ;
V_195:
F_11 ( V_4 -> V_3 ) ;
V_193:
F_12 ( V_4 ) ;
V_26:
return F_27 ( V_19 ) ;
}
static struct V_1 * F_98 ( struct V_59 * V_60 )
{
T_7 V_186 ;
struct V_1 * V_4 ;
if ( ! F_82 ( V_60 ) && F_75 ( V_60 ) ) {
V_186 = V_60 -> V_96 . V_39 ;
} else {
V_186 = V_60 -> V_112 . V_205 << ( V_60 -> V_112 . V_206 - 9 ) ;
}
V_4 = F_87 ( V_60 , & V_60 -> V_15 , V_186 , false , NULL ) ;
return V_4 ;
}
static int F_99 ( struct V_59 * V_60 ,
struct V_1 * V_4 ,
unsigned int V_95 ,
T_7 V_186 ,
bool V_187 ,
const char * V_188 )
{
char V_207 [ 10 ] ;
struct V_1 * V_208 ;
V_208 = F_87 ( V_60 , F_100 ( V_4 -> V_3 ) , V_186 , V_187 ,
V_188 ) ;
if ( F_30 ( V_208 ) )
return F_31 ( V_208 ) ;
V_208 -> V_95 = V_95 ;
F_101 ( & V_208 -> V_194 , & V_4 -> V_194 ) ;
F_102 ( ( V_51 ) F_23 ( V_208 -> V_3 ) << 9 , V_209 ,
V_207 , sizeof( V_207 ) ) ;
F_55 ( V_210 L_17 ,
V_208 -> V_3 -> V_123 , F_103 ( V_60 ) ,
F_104 ( V_60 ) , V_208 -> V_95 , V_207 ) ;
return 0 ;
}
static int F_105 ( struct V_59 * V_60 , struct V_1 * V_4 )
{
int V_19 = 0 ;
if ( ! F_47 ( V_60 ) )
return 0 ;
if ( V_60 -> V_96 . V_211 ) {
V_19 = F_99 ( V_60 , V_4 , V_212 ,
V_60 -> V_96 . V_211 >> 9 ,
true ,
L_18 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_99 ( V_60 , V_4 , V_213 ,
V_60 -> V_96 . V_211 >> 9 ,
true ,
L_19 ) ;
if ( V_19 )
return V_19 ;
}
return V_19 ;
}
static int
F_106 ( struct V_1 * V_4 , struct V_59 * V_60 )
{
int V_44 ;
F_33 ( V_60 -> V_80 ) ;
V_44 = F_107 ( V_60 , 512 ) ;
F_41 ( V_60 -> V_80 ) ;
if ( V_44 ) {
F_55 ( V_121 L_20 ,
V_4 -> V_3 -> V_123 , V_44 ) ;
return - V_25 ;
}
return 0 ;
}
static void F_108 ( struct V_1 * V_4 )
{
if ( V_4 ) {
if ( V_4 -> V_3 -> V_74 & V_214 ) {
F_109 ( F_100 ( V_4 -> V_3 ) , & V_4 -> V_215 ) ;
F_110 ( V_4 -> V_3 ) ;
}
F_111 ( & V_4 -> V_12 ) ;
F_8 ( V_4 ) ;
}
}
static void F_112 ( struct V_59 * V_60 ,
struct V_1 * V_4 )
{
struct V_216 * V_217 , * V_218 ;
struct V_1 * V_208 ;
F_10 ( V_4 -> V_191 , V_192 ) ;
F_113 (pos, q, &md->part) {
V_208 = F_114 ( V_217 , struct V_1 , V_194 ) ;
F_115 ( V_217 ) ;
F_108 ( V_208 ) ;
}
}
static int F_116 ( struct V_1 * V_4 )
{
int V_19 ;
F_117 ( V_4 -> V_3 ) ;
V_4 -> V_215 . V_219 = F_13 ;
V_4 -> V_215 . V_220 = F_16 ;
F_118 ( & V_4 -> V_215 . V_17 ) ;
V_4 -> V_215 . V_17 . V_221 = L_21 ;
V_4 -> V_215 . V_17 . V_29 = V_222 | V_223 ;
V_19 = F_119 ( F_100 ( V_4 -> V_3 ) , & V_4 -> V_215 ) ;
if ( V_19 )
F_110 ( V_4 -> V_3 ) ;
return V_19 ;
}
static int F_120 ( struct V_59 * V_60 )
{
struct V_1 * V_4 , * V_208 ;
int V_44 ;
char V_207 [ 10 ] ;
if ( ! ( V_60 -> V_112 . V_183 & V_224 ) )
return - V_225 ;
V_4 = F_98 ( V_60 ) ;
if ( F_30 ( V_4 ) )
return F_31 ( V_4 ) ;
V_44 = F_106 ( V_4 , V_60 ) ;
if ( V_44 )
goto V_26;
F_102 ( ( V_51 ) F_23 ( V_4 -> V_3 ) << 9 , V_209 ,
V_207 , sizeof( V_207 ) ) ;
F_55 ( V_210 L_22 ,
V_4 -> V_3 -> V_123 , F_103 ( V_60 ) , F_104 ( V_60 ) ,
V_207 , V_4 -> V_21 ? L_23 : L_16 ) ;
if ( F_105 ( V_60 , V_4 ) )
goto V_26;
F_121 ( V_60 , V_4 ) ;
F_122 ( V_60 , V_226 ) ;
if ( F_116 ( V_4 ) )
goto V_26;
F_123 (part_md, &md->part, part) {
if ( F_116 ( V_208 ) )
goto V_26;
}
return 0 ;
V_26:
F_112 ( V_60 , V_4 ) ;
F_108 ( V_4 ) ;
return V_44 ;
}
static void F_124 ( struct V_59 * V_60 )
{
struct V_1 * V_4 = F_46 ( V_60 ) ;
F_112 ( V_60 , V_4 ) ;
F_33 ( V_60 -> V_80 ) ;
F_45 ( V_60 , V_4 ) ;
F_41 ( V_60 -> V_80 ) ;
F_108 ( V_4 ) ;
F_121 ( V_60 , NULL ) ;
}
static int F_125 ( struct V_59 * V_60 , T_8 V_227 )
{
struct V_1 * V_208 ;
struct V_1 * V_4 = F_46 ( V_60 ) ;
if ( V_4 ) {
F_126 ( & V_4 -> V_12 ) ;
F_123 (part_md, &md->part, part) {
F_126 ( & V_208 -> V_12 ) ;
}
}
return 0 ;
}
static int F_127 ( struct V_59 * V_60 )
{
struct V_1 * V_208 ;
struct V_1 * V_4 = F_46 ( V_60 ) ;
if ( V_4 ) {
F_106 ( V_4 , V_60 ) ;
V_4 -> V_94 = V_4 -> V_95 ;
F_128 ( & V_4 -> V_12 ) ;
F_123 (part_md, &md->part, part) {
F_128 ( & V_208 -> V_12 ) ;
}
}
return 0 ;
}
static int T_9 F_129 ( void )
{
int V_228 ;
if ( V_10 != V_229 )
F_130 ( L_24 , V_10 ) ;
V_189 = 256 / V_10 ;
V_228 = F_131 ( V_198 , L_25 ) ;
if ( V_228 )
goto V_26;
V_228 = F_132 ( & V_230 ) ;
if ( V_228 )
goto V_231;
return 0 ;
V_231:
F_133 ( V_198 , L_25 ) ;
V_26:
return V_228 ;
}
static void T_10 F_134 ( void )
{
F_135 ( & V_230 ) ;
F_133 ( V_198 , L_25 ) ;
}
