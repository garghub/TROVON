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
static T_1 F_13 ( struct V_14 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
int V_22 = 0 ;
if ( V_21 -> V_23 . V_24 & V_25 )
V_22 = 2 ;
else if ( V_21 -> V_23 . V_24 & V_26 )
V_22 = 1 ;
V_19 = snprintf ( V_18 , V_27 , L_1 , V_22 ) ;
return V_19 ;
}
static T_1 F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 , const char * V_18 , T_2 V_28 )
{
int V_19 ;
struct V_1 * V_4 , * V_29 ;
struct V_20 * V_21 ;
unsigned long V_30 ;
if ( F_16 ( V_18 , 0 , & V_30 ) )
return - V_31 ;
if ( V_30 != 1 )
return V_28 ;
V_4 = F_1 ( F_14 ( V_15 ) ) ;
V_21 = V_4 -> V_12 . V_21 ;
F_17 ( V_21 -> V_32 ) ;
V_19 = F_18 ( V_21 , V_33 , V_34 ,
V_21 -> V_23 . V_24 |
V_26 ,
V_21 -> V_23 . V_35 ) ;
if ( V_19 )
F_19 ( L_2 , V_4 -> V_3 -> V_36 , V_19 ) ;
else
V_21 -> V_23 . V_24 |= V_26 ;
F_20 ( V_21 -> V_32 ) ;
if ( ! V_19 ) {
F_21 ( L_3 ,
V_4 -> V_3 -> V_36 ) ;
F_22 ( V_4 -> V_3 , 1 ) ;
F_23 (part_md, &md->part, part)
if ( V_29 -> V_37 == V_38 ) {
F_21 ( L_3 , V_29 -> V_3 -> V_36 ) ;
F_22 ( V_29 -> V_3 , 1 ) ;
}
}
F_8 ( V_4 ) ;
return V_28 ;
}
static T_1 F_24 ( struct V_14 * V_15 , struct V_16 * V_17 ,
char * V_18 )
{
int V_19 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
V_19 = snprintf ( V_18 , V_27 , L_4 ,
F_25 ( F_14 ( V_15 ) ) ^
V_4 -> V_39 ) ;
F_8 ( V_4 ) ;
return V_19 ;
}
static T_1 F_26 ( struct V_14 * V_15 , struct V_16 * V_17 ,
const char * V_18 , T_2 V_28 )
{
int V_19 ;
char * V_40 ;
struct V_1 * V_4 = F_1 ( F_14 ( V_15 ) ) ;
unsigned long V_30 = F_27 ( V_18 , & V_40 , 0 ) ;
if ( V_40 == V_18 ) {
V_19 = - V_31 ;
goto V_41;
}
F_22 ( F_14 ( V_15 ) , V_30 || V_4 -> V_39 ) ;
V_19 = V_28 ;
V_41:
F_8 ( V_4 ) ;
return V_19 ;
}
static int F_28 ( struct V_42 * V_43 , T_3 V_44 )
{
struct V_1 * V_4 = F_1 ( V_43 -> V_45 ) ;
int V_19 = - V_46 ;
F_2 ( & V_47 ) ;
if ( V_4 ) {
if ( V_4 -> V_7 == 2 )
F_29 ( V_43 ) ;
V_19 = 0 ;
if ( ( V_44 & V_48 ) && V_4 -> V_39 ) {
F_8 ( V_4 ) ;
V_19 = - V_49 ;
}
}
F_3 ( & V_47 ) ;
return V_19 ;
}
static int F_30 ( struct V_2 * V_3 , T_3 V_44 )
{
struct V_1 * V_4 = V_3 -> V_6 ;
F_2 ( & V_47 ) ;
F_8 ( V_4 ) ;
F_3 ( & V_47 ) ;
return 0 ;
}
static int
F_31 ( struct V_42 * V_43 , struct V_50 * V_51 )
{
V_51 -> V_52 = F_32 ( V_43 -> V_45 ) / ( 4 * 16 ) ;
V_51 -> V_53 = 4 ;
V_51 -> V_54 = 16 ;
return 0 ;
}
static struct V_55 * F_33 (
struct V_56 T_4 * V_57 )
{
struct V_55 * V_58 ;
int V_59 ;
V_58 = F_34 ( sizeof( * V_58 ) , V_60 ) ;
if ( ! V_58 ) {
V_59 = - V_61 ;
goto V_41;
}
if ( F_35 ( & V_58 -> V_62 , V_57 , sizeof( V_58 -> V_62 ) ) ) {
V_59 = - V_63 ;
goto V_64;
}
V_58 -> V_65 = ( V_66 ) V_58 -> V_62 . V_67 * V_58 -> V_62 . V_68 ;
if ( V_58 -> V_65 > V_69 ) {
V_59 = - V_70 ;
goto V_64;
}
if ( ! V_58 -> V_65 )
return V_58 ;
V_58 -> V_18 = F_34 ( V_58 -> V_65 , V_60 ) ;
if ( ! V_58 -> V_18 ) {
V_59 = - V_61 ;
goto V_64;
}
if ( F_35 ( V_58 -> V_18 , ( void T_4 * ) ( unsigned long )
V_58 -> V_62 . V_71 , V_58 -> V_65 ) ) {
V_59 = - V_63 ;
goto V_72;
}
return V_58 ;
V_72:
F_12 ( V_58 -> V_18 ) ;
V_64:
F_12 ( V_58 ) ;
V_41:
return F_36 ( V_59 ) ;
}
static int F_37 ( struct V_42 * V_43 ,
struct V_56 T_4 * V_73 )
{
struct V_55 * V_58 ;
struct V_1 * V_4 ;
struct V_20 * V_21 ;
struct V_74 V_75 = { 0 } ;
struct V_76 V_77 = { 0 } ;
struct V_78 V_79 = { NULL } ;
struct V_80 V_81 ;
int V_59 ;
if ( ( ! F_38 ( V_82 ) ) || ( V_43 != V_43 -> V_83 ) )
return - V_84 ;
V_58 = F_33 ( V_73 ) ;
if ( F_39 ( V_58 ) )
return F_40 ( V_58 ) ;
V_4 = F_1 ( V_43 -> V_45 ) ;
if ( ! V_4 ) {
V_59 = - V_31 ;
goto V_85;
}
V_21 = V_4 -> V_12 . V_21 ;
if ( F_39 ( V_21 ) ) {
V_59 = F_40 ( V_21 ) ;
goto V_85;
}
V_75 . V_86 = V_58 -> V_62 . V_86 ;
V_75 . V_87 = V_58 -> V_62 . V_87 ;
V_75 . V_88 = V_58 -> V_62 . V_88 ;
if ( V_58 -> V_65 ) {
V_77 . V_81 = & V_81 ;
V_77 . V_89 = 1 ;
V_77 . V_67 = V_58 -> V_62 . V_67 ;
V_77 . V_68 = V_58 -> V_62 . V_68 ;
F_41 ( V_77 . V_81 , V_58 -> V_18 , V_58 -> V_65 ) ;
if ( V_58 -> V_62 . V_90 )
V_77 . V_88 = V_91 ;
else
V_77 . V_88 = V_92 ;
F_42 ( & V_77 , V_21 ) ;
if ( V_58 -> V_62 . V_93 )
V_77 . V_94 = V_58 -> V_62 . V_93 ;
if ( ( V_75 . V_88 & V_95 ) == V_95 ) {
V_77 . V_94 = V_58 -> V_62 . V_96 * 1000000 ;
}
V_79 . V_77 = & V_77 ;
}
V_79 . V_75 = & V_75 ;
F_17 ( V_21 -> V_32 ) ;
if ( V_58 -> V_62 . V_97 ) {
V_59 = F_43 ( V_21 -> V_32 , V_21 ) ;
if ( V_59 )
goto V_98;
}
F_44 ( V_21 -> V_32 , & V_79 ) ;
if ( V_75 . error ) {
F_45 ( F_46 ( V_21 -> V_32 ) , L_5 ,
V_99 , V_75 . error ) ;
V_59 = V_75 . error ;
goto V_98;
}
if ( V_77 . error ) {
F_45 ( F_46 ( V_21 -> V_32 ) , L_6 ,
V_99 , V_77 . error ) ;
V_59 = V_77 . error ;
goto V_98;
}
if ( V_58 -> V_62 . V_100 )
F_47 ( V_58 -> V_62 . V_100 , V_58 -> V_62 . V_101 ) ;
if ( F_48 ( & ( V_73 -> V_102 ) , V_75 . V_103 , sizeof( V_75 . V_103 ) ) ) {
V_59 = - V_63 ;
goto V_98;
}
if ( ! V_58 -> V_62 . V_90 ) {
if ( F_48 ( ( void T_4 * ) ( unsigned long ) V_58 -> V_62 . V_71 ,
V_58 -> V_18 , V_58 -> V_65 ) ) {
V_59 = - V_63 ;
goto V_98;
}
}
V_98:
F_20 ( V_21 -> V_32 ) ;
V_85:
F_8 ( V_4 ) ;
F_12 ( V_58 -> V_18 ) ;
F_12 ( V_58 ) ;
return V_59 ;
}
static int F_49 ( struct V_42 * V_43 , T_3 V_44 ,
unsigned int V_75 , unsigned long V_87 )
{
int V_19 = - V_31 ;
if ( V_75 == V_104 )
V_19 = F_37 ( V_43 , (struct V_56 T_4 * ) V_87 ) ;
return V_19 ;
}
static int F_50 ( struct V_42 * V_43 , T_3 V_44 ,
unsigned int V_75 , unsigned long V_87 )
{
return F_49 ( V_43 , V_44 , V_75 , ( unsigned long ) F_51 ( V_87 ) ) ;
}
static inline int F_52 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
int V_19 ;
struct V_1 * V_105 = F_53 ( V_21 ) ;
if ( V_105 -> V_106 == V_4 -> V_107 )
return 0 ;
if ( F_54 ( V_21 ) ) {
T_5 V_108 = V_21 -> V_23 . V_108 ;
V_108 &= ~ V_109 ;
V_108 |= V_4 -> V_107 ;
V_19 = F_18 ( V_21 , V_33 ,
V_110 , V_108 ,
V_21 -> V_23 . V_35 ) ;
if ( V_19 )
return V_19 ;
V_21 -> V_23 . V_108 = V_108 ;
}
V_105 -> V_106 = V_4 -> V_107 ;
return 0 ;
}
static T_6 F_55 ( struct V_20 * V_21 )
{
int V_59 ;
T_6 V_111 ;
T_7 * V_68 ;
struct V_78 V_79 = { NULL } ;
struct V_74 V_75 = { 0 } ;
struct V_76 V_77 = { 0 } ;
unsigned int V_112 ;
struct V_80 V_81 ;
V_75 . V_86 = V_113 ;
V_75 . V_87 = V_21 -> V_114 << 16 ;
V_75 . V_88 = V_115 | V_116 | V_117 ;
V_59 = F_56 ( V_21 -> V_32 , & V_75 , 0 ) ;
if ( V_59 )
return ( T_6 ) - 1 ;
if ( ! F_57 ( V_21 -> V_32 ) && ! ( V_75 . V_103 [ 0 ] & V_118 ) )
return ( T_6 ) - 1 ;
memset ( & V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 . V_86 = V_119 ;
V_75 . V_87 = 0 ;
V_75 . V_88 = V_115 | V_116 | V_120 ;
V_77 . V_94 = V_21 -> V_121 . V_122 * 100 ;
V_77 . V_123 = V_21 -> V_121 . V_124 * 100 ;
V_112 = V_77 . V_94 / 1000 ;
V_112 += V_77 . V_123 * 1000 /
( V_21 -> V_32 -> V_125 . clock / 1000 ) ;
if ( V_112 > 100000 ) {
V_77 . V_94 = 100000000 ;
V_77 . V_123 = 0 ;
}
V_77 . V_67 = 4 ;
V_77 . V_68 = 1 ;
V_77 . V_88 = V_92 ;
V_77 . V_81 = & V_81 ;
V_77 . V_89 = 1 ;
V_79 . V_75 = & V_75 ;
V_79 . V_77 = & V_77 ;
V_68 = F_58 ( 4 , V_60 ) ;
if ( ! V_68 )
return ( T_6 ) - 1 ;
F_41 ( & V_81 , V_68 , 4 ) ;
F_44 ( V_21 -> V_32 , & V_79 ) ;
V_111 = F_59 ( * V_68 ) ;
F_12 ( V_68 ) ;
if ( V_75 . error || V_77 . error )
V_111 = ( T_6 ) - 1 ;
return V_111 ;
}
static int F_60 ( struct V_20 * V_21 , T_6 * V_126 )
{
struct V_74 V_75 = { 0 } ;
int V_59 ;
V_75 . V_86 = V_127 ;
V_75 . V_88 = V_128 | V_95 | V_117 ;
V_59 = F_56 ( V_21 -> V_32 , & V_75 , 5 ) ;
if ( V_59 == 0 )
* V_126 = V_75 . V_103 [ 0 ] ;
return V_59 ;
}
static int F_61 ( struct V_20 * V_21 , T_6 * V_126 , int V_129 )
{
struct V_74 V_75 = { 0 } ;
int V_59 ;
V_75 . V_86 = V_130 ;
if ( ! F_57 ( V_21 -> V_32 ) )
V_75 . V_87 = V_21 -> V_114 << 16 ;
V_75 . V_88 = V_131 | V_116 | V_117 ;
V_59 = F_56 ( V_21 -> V_32 , & V_75 , V_129 ) ;
if ( V_59 == 0 )
* V_126 = V_75 . V_103 [ 0 ] ;
return V_59 ;
}
static int F_62 ( struct V_132 * V_133 , const char * V_134 , int error ,
bool V_135 , T_6 V_126 )
{
switch ( error ) {
case - V_136 :
F_19 ( L_7 ,
V_133 -> V_137 -> V_36 , L_8 ,
V_134 , V_126 ) ;
return V_138 ;
case - V_139 :
F_19 ( L_7 ,
V_133 -> V_137 -> V_36 , L_9 , V_134 , V_126 ) ;
if ( ! V_135 )
return V_138 ;
if ( V_126 & ( V_140 | V_141 ) )
return V_138 ;
return V_142 ;
default:
F_19 ( L_10 ,
V_133 -> V_137 -> V_36 , error , V_126 ) ;
return V_142 ;
}
}
static int F_63 ( struct V_20 * V_21 , struct V_132 * V_133 ,
struct V_143 * V_144 , int * V_145 )
{
bool V_146 = true ;
T_6 V_126 , V_147 = 0 ;
int V_59 , V_148 ;
if ( F_64 ( V_21 ) )
return V_149 ;
for ( V_148 = 2 ; V_148 >= 0 ; V_148 -- ) {
V_59 = F_61 ( V_21 , & V_126 , 0 ) ;
if ( ! V_59 )
break;
V_146 = false ;
F_19 ( L_11 ,
V_133 -> V_137 -> V_36 , V_59 , V_148 ? L_12 : L_13 ) ;
}
if ( V_59 ) {
if ( F_65 ( V_21 -> V_32 ) )
return V_149 ;
return V_142 ;
}
if ( ( V_126 & V_150 ) ||
( V_144 -> V_151 . V_103 [ 0 ] & V_150 ) ||
( V_144 -> V_75 . V_103 [ 0 ] & V_150 ) )
* V_145 = 1 ;
if ( F_66 ( V_126 ) == V_152 ||
F_66 ( V_126 ) == V_153 ) {
V_59 = F_60 ( V_21 , & V_147 ) ;
if ( V_59 )
F_19 ( L_14 ,
V_133 -> V_137 -> V_36 , V_59 ) ;
if ( V_59 )
return V_142 ;
if ( V_147 & V_150 )
* V_145 = 1 ;
}
if ( V_144 -> V_154 . error )
return F_62 ( V_133 , L_15 , V_144 -> V_154 . error ,
V_146 , V_126 ) ;
if ( V_144 -> V_75 . error )
return F_62 ( V_133 , L_16 , V_144 -> V_75 . error ,
V_146 , V_126 ) ;
if ( ! V_144 -> V_151 . error )
return V_155 ;
F_19 ( L_17 ,
V_133 -> V_137 -> V_36 , V_144 -> V_151 . error ,
V_144 -> V_75 . V_103 [ 0 ] , V_126 ) ;
if ( V_147 ) {
V_144 -> V_151 . V_103 [ 0 ] = V_147 ;
V_144 -> V_151 . error = 0 ;
}
return V_155 ;
}
static int F_67 ( struct V_1 * V_4 , struct V_156 * V_32 ,
int type )
{
int V_59 ;
if ( V_4 -> V_157 & type )
return - V_158 ;
V_4 -> V_157 |= type ;
V_59 = F_68 ( V_32 ) ;
if ( V_59 != - V_159 ) {
struct V_1 * V_105 = F_53 ( V_32 -> V_21 ) ;
int V_160 ;
V_105 -> V_106 = V_105 -> V_107 ;
V_160 = F_52 ( V_32 -> V_21 , V_4 ) ;
if ( V_160 ) {
return - V_161 ;
}
}
return V_59 ;
}
static inline void F_69 ( struct V_1 * V_4 , int type )
{
V_4 -> V_157 &= ~ type ;
}
static int F_70 ( struct V_162 * V_163 , struct V_132 * V_133 )
{
struct V_1 * V_4 = V_163 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
unsigned int V_164 , V_165 , V_87 ;
int V_59 = 0 , type = V_166 ;
if ( ! F_71 ( V_21 ) ) {
V_59 = - V_159 ;
goto V_41;
}
V_164 = F_72 ( V_133 ) ;
V_165 = F_73 ( V_133 ) ;
if ( F_74 ( V_21 ) )
V_87 = V_167 ;
else if ( F_75 ( V_21 ) )
V_87 = V_168 ;
else
V_87 = V_169 ;
V_148:
if ( V_21 -> V_170 & V_171 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_172 ,
V_87 == V_168 ?
V_173 :
V_174 ,
0 ) ;
if ( V_59 )
goto V_41;
}
V_59 = F_76 ( V_21 , V_164 , V_165 , V_87 ) ;
V_41:
if ( V_59 == - V_175 && ! F_67 ( V_4 , V_21 -> V_32 , type ) )
goto V_148;
if ( ! V_59 )
F_69 ( V_4 , type ) ;
F_77 ( & V_4 -> V_176 ) ;
F_78 ( V_133 , V_59 , F_79 ( V_133 ) ) ;
F_80 ( & V_4 -> V_176 ) ;
return V_59 ? 0 : 1 ;
}
static int F_81 ( struct V_162 * V_163 ,
struct V_132 * V_133 )
{
struct V_1 * V_4 = V_163 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
unsigned int V_164 , V_165 , V_87 ;
int V_59 = 0 , type = V_177 ;
if ( ! ( F_82 ( V_21 ) || F_83 ( V_21 ) ) ) {
V_59 = - V_159 ;
goto V_41;
}
if ( F_83 ( V_21 ) ) {
V_59 = F_18 ( V_21 , V_33 ,
V_178 , 1 , 0 ) ;
goto V_41;
}
V_164 = F_72 ( V_133 ) ;
V_165 = F_73 ( V_133 ) ;
if ( F_75 ( V_21 ) && ! F_84 ( V_21 , V_164 , V_165 ) )
V_87 = V_179 ;
else
V_87 = V_180 ;
V_148:
if ( V_21 -> V_170 & V_171 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_172 ,
V_87 == V_179 ?
V_181 :
V_182 ,
0 ) ;
if ( V_59 )
goto V_41;
}
V_59 = F_76 ( V_21 , V_164 , V_165 , V_87 ) ;
if ( ! V_59 && V_87 == V_179 ) {
if ( V_21 -> V_170 & V_171 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_172 ,
V_183 ,
0 ) ;
if ( V_59 )
goto V_41;
}
V_59 = F_76 ( V_21 , V_164 , V_165 , V_184 ) ;
}
V_41:
if ( V_59 == - V_175 && ! F_67 ( V_4 , V_21 -> V_32 , type ) )
goto V_148;
if ( ! V_59 )
F_69 ( V_4 , type ) ;
F_77 ( & V_4 -> V_176 ) ;
F_78 ( V_133 , V_59 , F_79 ( V_133 ) ) ;
F_80 ( & V_4 -> V_176 ) ;
return V_59 ? 0 : 1 ;
}
static int F_85 ( struct V_162 * V_163 , struct V_132 * V_133 )
{
struct V_1 * V_4 = V_163 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
int V_19 = 0 ;
V_19 = F_86 ( V_21 ) ;
if ( V_19 )
V_19 = - V_175 ;
F_77 ( & V_4 -> V_176 ) ;
F_87 ( V_133 , V_19 ) ;
F_80 ( & V_4 -> V_176 ) ;
return V_19 ? 0 : 1 ;
}
static inline void F_88 ( struct V_143 * V_144 ,
struct V_20 * V_21 ,
struct V_132 * V_133 )
{
if ( ! ( V_21 -> V_23 . V_185 & V_186 ) ) {
if ( ! F_89 ( V_144 -> V_75 . V_87 , V_21 -> V_23 . V_187 ) )
V_144 -> V_77 . V_68 = 1 ;
if ( V_144 -> V_77 . V_68 > V_21 -> V_23 . V_187 )
V_144 -> V_77 . V_68 = V_21 -> V_23 . V_187 ;
else if ( V_144 -> V_77 . V_68 < V_21 -> V_23 . V_187 )
V_144 -> V_77 . V_68 = 1 ;
}
}
static int F_90 ( struct V_20 * V_21 ,
struct V_188 * V_189 )
{
struct V_190 * V_191 = F_91 ( V_189 , struct V_190 ,
V_192 ) ;
struct V_143 * V_144 = & V_191 -> V_144 ;
struct V_132 * V_133 = V_191 -> V_133 ;
int V_145 = 0 ;
if ( V_144 -> V_154 . error || V_144 -> V_75 . error || V_144 -> V_151 . error ||
V_144 -> V_77 . error ) {
switch ( F_63 ( V_21 , V_133 , V_144 , & V_145 ) ) {
case V_138 :
return V_193 ;
case V_142 :
return V_194 ;
case V_149 :
return V_195 ;
case V_155 :
break;
}
}
if ( V_144 -> V_75 . V_103 [ 0 ] & V_196 ) {
F_19 ( L_18 ,
V_133 -> V_137 -> V_36 , V_144 -> V_75 . V_103 [ 0 ] ) ;
return V_194 ;
}
if ( ! F_57 ( V_21 -> V_32 ) && F_92 ( V_133 ) != V_197 ) {
T_6 V_126 ;
do {
int V_59 = F_61 ( V_21 , & V_126 , 5 ) ;
if ( V_59 ) {
F_19 ( L_19 ,
V_133 -> V_137 -> V_36 , V_59 ) ;
return V_198 ;
}
} while ( ! ( V_126 & V_199 ) ||
( F_66 ( V_126 ) == V_200 ) );
}
if ( V_144 -> V_77 . error ) {
F_19 ( L_20 ,
V_133 -> V_137 -> V_36 , V_144 -> V_77 . error ,
( unsigned ) F_72 ( V_133 ) ,
( unsigned ) F_73 ( V_133 ) ,
V_144 -> V_75 . V_103 [ 0 ] , V_144 -> V_151 . V_103 [ 0 ] ) ;
if ( F_92 ( V_133 ) == V_197 ) {
if ( V_145 )
return V_201 ;
return V_202 ;
} else {
return V_198 ;
}
}
if ( ! V_144 -> V_77 . V_203 )
return V_193 ;
if ( F_79 ( V_133 ) != V_144 -> V_77 . V_203 )
return V_204 ;
return V_205 ;
}
static void F_93 ( struct V_190 * V_206 ,
struct V_20 * V_21 ,
int V_207 ,
struct V_162 * V_163 )
{
T_6 V_208 , V_209 ;
struct V_143 * V_144 = & V_206 -> V_144 ;
struct V_132 * V_133 = V_206 -> V_133 ;
struct V_1 * V_4 = V_163 -> V_77 ;
bool V_210 = ( ( V_133 -> V_211 & V_212 ) ||
( V_133 -> V_211 & V_213 ) ) &&
( F_92 ( V_133 ) == V_214 ) &&
( V_4 -> V_88 & V_215 ) ;
memset ( V_144 , 0 , sizeof( struct V_143 ) ) ;
V_144 -> V_79 . V_75 = & V_144 -> V_75 ;
V_144 -> V_79 . V_77 = & V_144 -> V_77 ;
V_144 -> V_75 . V_87 = F_72 ( V_133 ) ;
if ( ! F_94 ( V_21 ) )
V_144 -> V_75 . V_87 <<= 9 ;
V_144 -> V_75 . V_88 = V_115 | V_116 | V_120 ;
V_144 -> V_77 . V_67 = 512 ;
V_144 -> V_151 . V_86 = V_127 ;
V_144 -> V_151 . V_87 = 0 ;
V_144 -> V_151 . V_88 = V_128 | V_95 | V_117 ;
V_144 -> V_77 . V_68 = F_73 ( V_133 ) ;
if ( V_144 -> V_77 . V_68 > V_21 -> V_32 -> V_216 )
V_144 -> V_77 . V_68 = V_21 -> V_32 -> V_216 ;
if ( V_144 -> V_77 . V_68 > 1 ) {
if ( V_207 )
V_144 -> V_77 . V_68 = 1 ;
if ( V_21 -> V_32 -> V_217 & V_218 &&
F_92 ( V_133 ) == V_197 )
V_144 -> V_77 . V_68 = 1 ;
}
if ( V_144 -> V_77 . V_68 > 1 || V_210 ) {
if ( ! F_57 ( V_21 -> V_32 ) ||
F_92 ( V_133 ) == V_197 )
V_144 -> V_79 . V_151 = & V_144 -> V_151 ;
V_208 = V_219 ;
V_209 = V_220 ;
} else {
V_144 -> V_79 . V_151 = NULL ;
V_208 = V_221 ;
V_209 = V_222 ;
}
if ( F_92 ( V_133 ) == V_197 ) {
V_144 -> V_75 . V_86 = V_208 ;
V_144 -> V_77 . V_88 |= V_92 ;
} else {
V_144 -> V_75 . V_86 = V_209 ;
V_144 -> V_77 . V_88 |= V_91 ;
}
if ( V_210 )
F_88 ( V_144 , V_21 , V_133 ) ;
if ( ( V_4 -> V_88 & V_223 ) &&
F_95 ( V_144 -> V_75 . V_86 ) &&
( V_210 || ! ( V_21 -> V_170 & V_224 ) ) ) {
V_144 -> V_154 . V_86 = V_225 ;
V_144 -> V_154 . V_87 = V_144 -> V_77 . V_68 |
( V_210 ? ( 1 << 31 ) : 0 ) ;
V_144 -> V_154 . V_88 = V_116 | V_117 ;
V_144 -> V_79 . V_154 = & V_144 -> V_154 ;
}
F_42 ( & V_144 -> V_77 , V_21 ) ;
V_144 -> V_77 . V_81 = V_206 -> V_81 ;
V_144 -> V_77 . V_89 = F_96 ( V_163 , V_206 ) ;
if ( V_144 -> V_77 . V_68 != F_73 ( V_133 ) ) {
int V_226 , V_227 = V_144 -> V_77 . V_68 << 9 ;
struct V_80 * V_81 ;
F_97 (brq->data.sg, sg, brq->data.sg_len, i) {
V_227 -= V_81 -> V_228 ;
if ( V_227 <= 0 ) {
V_81 -> V_228 += V_227 ;
V_226 ++ ;
break;
}
}
V_144 -> V_77 . V_89 = V_226 ;
}
V_206 -> V_192 . V_79 = & V_144 -> V_79 ;
V_206 -> V_192 . V_229 = F_90 ;
F_98 ( V_206 ) ;
}
static int F_99 ( struct V_1 * V_4 , struct V_20 * V_21 ,
struct V_143 * V_144 , struct V_132 * V_133 ,
int V_19 )
{
if ( F_100 ( V_21 ) ) {
T_6 V_68 ;
V_68 = F_55 ( V_21 ) ;
if ( V_68 != ( T_6 ) - 1 ) {
F_77 ( & V_4 -> V_176 ) ;
V_19 = F_78 ( V_133 , 0 , V_68 << 9 ) ;
F_80 ( & V_4 -> V_176 ) ;
}
} else {
F_77 ( & V_4 -> V_176 ) ;
V_19 = F_78 ( V_133 , 0 , V_144 -> V_77 . V_203 ) ;
F_80 ( & V_4 -> V_176 ) ;
}
return V_19 ;
}
static int F_101 ( struct V_162 * V_163 , struct V_132 * V_230 )
{
struct V_1 * V_4 = V_163 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
struct V_143 * V_144 = & V_163 -> V_231 -> V_144 ;
int V_19 = 1 , V_207 = 0 , V_148 = 0 , type ;
enum V_232 V_126 ;
struct V_190 * V_233 ;
struct V_132 * V_133 ;
struct V_188 * V_189 ;
if ( ! V_230 && ! V_163 -> V_234 -> V_133 )
return 0 ;
do {
if ( V_230 ) {
F_93 ( V_163 -> V_231 , V_21 , 0 , V_163 ) ;
V_189 = & V_163 -> V_231 -> V_192 ;
} else
V_189 = NULL ;
V_189 = F_102 ( V_21 -> V_32 , V_189 , ( int * ) & V_126 ) ;
if ( ! V_189 )
return 0 ;
V_233 = F_91 ( V_189 , struct V_190 , V_192 ) ;
V_144 = & V_233 -> V_144 ;
V_133 = V_233 -> V_133 ;
type = F_92 ( V_133 ) == V_197 ? V_235 : V_236 ;
F_103 ( V_233 ) ;
switch ( V_126 ) {
case V_205 :
case V_204 :
F_69 ( V_4 , type ) ;
F_77 ( & V_4 -> V_176 ) ;
V_19 = F_78 ( V_133 , 0 ,
V_144 -> V_77 . V_203 ) ;
F_80 ( & V_4 -> V_176 ) ;
if ( V_126 == V_205 && V_19 ) {
F_19 ( L_21 ,
V_99 , F_79 ( V_133 ) ,
V_144 -> V_77 . V_203 ) ;
V_230 = NULL ;
goto V_237;
}
break;
case V_198 :
V_19 = F_99 ( V_4 , V_21 , V_144 , V_133 , V_19 ) ;
if ( ! F_67 ( V_4 , V_21 -> V_32 , type ) )
break;
goto V_237;
case V_193 :
if ( V_148 ++ < 5 )
break;
case V_194 :
if ( ! F_67 ( V_4 , V_21 -> V_32 , type ) )
break;
goto V_237;
case V_202 : {
int V_59 ;
V_59 = F_67 ( V_4 , V_21 -> V_32 , type ) ;
if ( ! V_59 )
break;
if ( V_59 == - V_161 )
goto V_237;
}
case V_201 :
if ( V_144 -> V_77 . V_68 > 1 ) {
F_104 ( L_22 ,
V_133 -> V_137 -> V_36 ) ;
V_207 = 1 ;
break;
}
F_77 ( & V_4 -> V_176 ) ;
V_19 = F_78 ( V_133 , - V_175 ,
V_144 -> V_77 . V_67 ) ;
F_80 ( & V_4 -> V_176 ) ;
if ( ! V_19 )
goto V_238;
break;
case V_195 :
goto V_237;
}
if ( V_19 ) {
F_93 ( V_233 , V_21 , V_207 , V_163 ) ;
F_102 ( V_21 -> V_32 , & V_233 -> V_192 , NULL ) ;
}
} while ( V_19 );
return 1 ;
V_237:
F_77 ( & V_4 -> V_176 ) ;
if ( F_64 ( V_21 ) )
V_133 -> V_211 |= V_239 ;
while ( V_19 )
V_19 = F_78 ( V_133 , - V_175 , F_105 ( V_133 ) ) ;
F_80 ( & V_4 -> V_176 ) ;
V_238:
if ( V_230 ) {
F_93 ( V_163 -> V_231 , V_21 , 0 , V_163 ) ;
F_102 ( V_21 -> V_32 , & V_163 -> V_231 -> V_192 , NULL ) ;
}
return 0 ;
}
static int F_106 ( struct V_162 * V_163 , struct V_132 * V_133 )
{
int V_19 ;
struct V_1 * V_4 = V_163 -> V_77 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
if ( V_133 && ! V_163 -> V_234 -> V_133 )
F_17 ( V_21 -> V_32 ) ;
V_19 = F_52 ( V_21 , V_4 ) ;
if ( V_19 ) {
if ( V_133 ) {
F_77 ( & V_4 -> V_176 ) ;
F_87 ( V_133 , - V_175 ) ;
F_80 ( & V_4 -> V_176 ) ;
}
V_19 = 0 ;
goto V_41;
}
if ( V_133 && V_133 -> V_211 & V_240 ) {
if ( V_21 -> V_32 -> V_189 )
F_101 ( V_163 , NULL ) ;
if ( V_133 -> V_211 & V_241 )
V_19 = F_81 ( V_163 , V_133 ) ;
else
V_19 = F_70 ( V_163 , V_133 ) ;
} else if ( V_133 && V_133 -> V_211 & V_242 ) {
if ( V_21 -> V_32 -> V_189 )
F_101 ( V_163 , NULL ) ;
V_19 = F_85 ( V_163 , V_133 ) ;
} else {
V_19 = F_101 ( V_163 , V_133 ) ;
}
V_41:
if ( ! V_133 )
F_20 ( V_21 -> V_32 ) ;
return V_19 ;
}
static inline int F_107 ( struct V_20 * V_21 )
{
return F_108 ( V_21 ) ||
! ( V_21 -> V_121 . V_243 & V_244 ) ;
}
static struct V_1 * F_109 ( struct V_20 * V_21 ,
struct V_14 * V_245 ,
T_8 V_246 ,
bool V_247 ,
const char * V_248 ,
int V_37 )
{
struct V_1 * V_4 ;
int V_9 , V_19 ;
V_9 = F_110 ( V_13 , V_249 ) ;
if ( V_9 >= V_249 )
return F_36 ( - V_250 ) ;
F_111 ( V_9 , V_13 ) ;
V_4 = F_34 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_4 ) {
V_19 = - V_61 ;
goto V_41;
}
if ( ! V_248 ) {
V_4 -> V_251 = F_110 ( V_252 , V_249 ) ;
F_111 ( V_4 -> V_251 , V_252 ) ;
} else
V_4 -> V_251 = ( (struct V_1 * )
F_14 ( V_245 ) -> V_6 ) -> V_251 ;
V_4 -> V_37 = V_37 ;
V_4 -> V_39 = F_107 ( V_21 ) ;
V_4 -> V_3 = F_112 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_19 = - V_61 ;
goto V_253;
}
F_113 ( & V_4 -> V_176 ) ;
F_114 ( & V_4 -> V_254 ) ;
V_4 -> V_7 = 1 ;
V_19 = F_115 ( & V_4 -> V_12 , V_21 , & V_4 -> V_176 , V_248 ) ;
if ( V_19 )
goto V_255;
V_4 -> V_12 . V_256 = F_106 ;
V_4 -> V_12 . V_77 = V_4 ;
V_4 -> V_3 -> V_257 = V_258 ;
V_4 -> V_3 -> V_11 = V_9 * V_10 ;
V_4 -> V_3 -> V_259 = & V_260 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_12 = V_4 -> V_12 . V_12 ;
V_4 -> V_3 -> V_261 = V_245 ;
F_22 ( V_4 -> V_3 , V_4 -> V_39 || V_247 ) ;
snprintf ( V_4 -> V_3 -> V_36 , sizeof( V_4 -> V_3 -> V_36 ) ,
L_23 , V_4 -> V_251 , V_248 ? V_248 : L_24 ) ;
F_116 ( V_4 -> V_12 . V_12 , 512 ) ;
F_117 ( V_4 -> V_3 , V_246 ) ;
if ( F_118 ( V_21 -> V_32 ) ) {
if ( F_54 ( V_21 ) ||
( F_100 ( V_21 ) &&
V_21 -> V_262 . V_263 & V_264 ) )
V_4 -> V_88 |= V_223 ;
}
if ( F_54 ( V_21 ) &&
V_4 -> V_88 & V_223 &&
( ( V_21 -> V_23 . V_185 & V_186 ) ||
V_21 -> V_23 . V_187 ) ) {
V_4 -> V_88 |= V_215 ;
F_119 ( V_4 -> V_12 . V_12 , V_242 | V_212 ) ;
}
return V_4 ;
V_255:
F_11 ( V_4 -> V_3 ) ;
V_253:
F_12 ( V_4 ) ;
V_41:
return F_36 ( V_19 ) ;
}
static struct V_1 * F_120 ( struct V_20 * V_21 )
{
T_8 V_246 ;
struct V_1 * V_4 ;
if ( ! F_100 ( V_21 ) && F_94 ( V_21 ) ) {
V_246 = V_21 -> V_23 . V_54 ;
} else {
V_246 = V_21 -> V_121 . V_265 << ( V_21 -> V_121 . V_266 - 9 ) ;
}
V_4 = F_109 ( V_21 , & V_21 -> V_15 , V_246 , false , NULL ,
V_267 ) ;
return V_4 ;
}
static int F_121 ( struct V_20 * V_21 ,
struct V_1 * V_4 ,
unsigned int V_107 ,
T_8 V_246 ,
bool V_247 ,
const char * V_248 ,
int V_37 )
{
char V_268 [ 10 ] ;
struct V_1 * V_29 ;
V_29 = F_109 ( V_21 , F_122 ( V_4 -> V_3 ) , V_246 , V_247 ,
V_248 , V_37 ) ;
if ( F_39 ( V_29 ) )
return F_40 ( V_29 ) ;
V_29 -> V_107 = V_107 ;
F_123 ( & V_29 -> V_254 , & V_4 -> V_254 ) ;
F_124 ( ( V_66 ) F_32 ( V_29 -> V_3 ) << 9 , V_269 ,
V_268 , sizeof( V_268 ) ) ;
F_21 ( L_25 ,
V_29 -> V_3 -> V_36 , F_125 ( V_21 ) ,
F_126 ( V_21 ) , V_29 -> V_107 , V_268 ) ;
return 0 ;
}
static int F_127 ( struct V_20 * V_21 , struct V_1 * V_4 )
{
int V_270 , V_19 = 0 ;
if ( ! F_54 ( V_21 ) )
return 0 ;
for ( V_270 = 0 ; V_270 < V_21 -> V_271 ; V_270 ++ ) {
if ( V_21 -> V_254 [ V_270 ] . V_246 ) {
V_19 = F_121 ( V_21 , V_4 ,
V_21 -> V_254 [ V_270 ] . V_272 ,
V_21 -> V_254 [ V_270 ] . V_246 >> 9 ,
V_21 -> V_254 [ V_270 ] . V_273 ,
V_21 -> V_254 [ V_270 ] . V_134 ,
V_21 -> V_254 [ V_270 ] . V_37 ) ;
if ( V_19 )
return V_19 ;
}
}
return V_19 ;
}
static int
F_128 ( struct V_1 * V_4 , struct V_20 * V_21 )
{
int V_59 ;
F_17 ( V_21 -> V_32 ) ;
V_59 = F_129 ( V_21 , 512 ) ;
F_20 ( V_21 -> V_32 ) ;
if ( V_59 ) {
F_19 ( L_26 ,
V_4 -> V_3 -> V_36 , V_59 ) ;
return - V_31 ;
}
return 0 ;
}
static void F_130 ( struct V_1 * V_4 )
{
struct V_20 * V_21 ;
if ( V_4 ) {
V_21 = V_4 -> V_12 . V_21 ;
if ( V_4 -> V_3 -> V_88 & V_274 ) {
F_131 ( F_122 ( V_4 -> V_3 ) , & V_4 -> V_273 ) ;
if ( ( V_4 -> V_37 & V_38 ) &&
V_21 -> V_23 . V_275 )
F_131 ( F_122 ( V_4 -> V_3 ) ,
& V_4 -> V_276 ) ;
F_132 ( V_4 -> V_3 ) ;
}
F_133 ( & V_4 -> V_12 ) ;
F_8 ( V_4 ) ;
}
}
static void F_134 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
struct V_277 * V_278 , * V_279 ;
struct V_1 * V_29 ;
F_10 ( V_4 -> V_251 , V_252 ) ;
F_135 (pos, q, &md->part) {
V_29 = F_136 ( V_278 , struct V_1 , V_254 ) ;
F_137 ( V_278 ) ;
F_130 ( V_29 ) ;
}
}
static int F_138 ( struct V_1 * V_4 )
{
int V_19 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
F_139 ( V_4 -> V_3 ) ;
V_4 -> V_273 . V_280 = F_24 ;
V_4 -> V_273 . V_281 = F_26 ;
F_140 ( & V_4 -> V_273 . V_17 ) ;
V_4 -> V_273 . V_17 . V_134 = L_27 ;
V_4 -> V_273 . V_17 . V_44 = V_282 | V_283 ;
V_19 = F_141 ( F_122 ( V_4 -> V_3 ) , & V_4 -> V_273 ) ;
if ( V_19 )
goto V_284;
if ( ( V_4 -> V_37 & V_38 ) &&
V_21 -> V_23 . V_275 ) {
T_9 V_44 ;
if ( V_21 -> V_23 . V_24 & V_285 )
V_44 = V_282 ;
else
V_44 = V_282 | V_283 ;
V_4 -> V_276 . V_280 = F_13 ;
V_4 -> V_276 . V_281 = F_15 ;
F_140 ( & V_4 -> V_276 . V_17 ) ;
V_4 -> V_276 . V_17 . V_44 = V_44 ;
V_4 -> V_276 . V_17 . V_134 =
L_28 ;
V_19 = F_141 ( F_122 ( V_4 -> V_3 ) ,
& V_4 -> V_276 ) ;
if ( V_19 )
goto V_286;
}
return V_19 ;
V_286:
F_131 ( F_122 ( V_4 -> V_3 ) , & V_4 -> V_273 ) ;
V_284:
F_132 ( V_4 -> V_3 ) ;
return V_19 ;
}
static int F_142 ( struct V_20 * V_21 )
{
struct V_1 * V_4 , * V_29 ;
int V_59 ;
char V_268 [ 10 ] ;
if ( ! ( V_21 -> V_121 . V_243 & V_287 ) )
return - V_161 ;
V_4 = F_120 ( V_21 ) ;
if ( F_39 ( V_4 ) )
return F_40 ( V_4 ) ;
V_59 = F_128 ( V_4 , V_21 ) ;
if ( V_59 )
goto V_41;
F_124 ( ( V_66 ) F_32 ( V_4 -> V_3 ) << 9 , V_269 ,
V_268 , sizeof( V_268 ) ) ;
F_21 ( L_29 ,
V_4 -> V_3 -> V_36 , F_125 ( V_21 ) , F_126 ( V_21 ) ,
V_268 , V_4 -> V_39 ? L_30 : L_24 ) ;
if ( F_127 ( V_21 , V_4 ) )
goto V_41;
F_143 ( V_21 , V_4 ) ;
F_144 ( V_21 , V_288 ) ;
if ( F_138 ( V_4 ) )
goto V_41;
F_23 (part_md, &md->part, part) {
if ( F_138 ( V_29 ) )
goto V_41;
}
return 0 ;
V_41:
F_134 ( V_21 , V_4 ) ;
F_130 ( V_4 ) ;
return V_59 ;
}
static void F_145 ( struct V_20 * V_21 )
{
struct V_1 * V_4 = F_53 ( V_21 ) ;
F_134 ( V_21 , V_4 ) ;
F_17 ( V_21 -> V_32 ) ;
F_52 ( V_21 , V_4 ) ;
F_20 ( V_21 -> V_32 ) ;
F_130 ( V_4 ) ;
F_143 ( V_21 , NULL ) ;
}
static int F_146 ( struct V_20 * V_21 , T_10 V_289 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_53 ( V_21 ) ;
if ( V_4 ) {
F_147 ( & V_4 -> V_12 ) ;
F_23 (part_md, &md->part, part) {
F_147 ( & V_29 -> V_12 ) ;
}
}
return 0 ;
}
static int F_148 ( struct V_20 * V_21 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_53 ( V_21 ) ;
if ( V_4 ) {
F_128 ( V_4 , V_21 ) ;
V_4 -> V_106 = V_4 -> V_107 ;
F_149 ( & V_4 -> V_12 ) ;
F_23 (part_md, &md->part, part) {
F_149 ( & V_29 -> V_12 ) ;
}
}
return 0 ;
}
static int T_11 F_150 ( void )
{
int V_290 ;
if ( V_10 != V_291 )
F_21 ( L_31 , V_10 ) ;
V_249 = 256 / V_10 ;
V_290 = F_151 ( V_258 , L_32 ) ;
if ( V_290 )
goto V_41;
V_290 = F_152 ( & V_292 ) ;
if ( V_290 )
goto V_293;
return 0 ;
V_293:
F_153 ( V_258 , L_32 ) ;
V_41:
return V_290 ;
}
static void T_12 F_154 ( void )
{
F_155 ( & V_292 ) ;
F_153 ( V_258 , L_32 ) ;
}
