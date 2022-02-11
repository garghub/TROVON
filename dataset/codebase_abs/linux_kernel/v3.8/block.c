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
static int F_37 ( struct V_20 * V_21 , T_5 * V_73 ,
T_5 V_74 )
{
int V_59 ;
T_5 V_75 = 0 ;
if ( ! V_73 || ! V_74 )
return - V_31 ;
do {
V_59 = F_38 ( V_21 , V_73 , 5 ) ;
if ( V_59 )
break;
if ( ! F_39 ( * V_73 ) &&
( F_40 ( * V_73 ) != V_76 ) )
break;
F_41 ( 1000 , 5000 ) ;
} while ( ++ V_75 < V_74 );
if ( V_75 == V_74 )
V_59 = - V_77 ;
return V_59 ;
}
static int F_42 ( struct V_42 * V_43 ,
struct V_56 T_4 * V_78 )
{
struct V_55 * V_58 ;
struct V_1 * V_4 ;
struct V_20 * V_21 ;
struct V_79 V_80 = { 0 } ;
struct V_81 V_82 = { 0 } ;
struct V_83 V_84 = { NULL } ;
struct V_85 V_86 ;
int V_59 ;
int V_87 = false ;
T_5 V_73 = 0 ;
if ( ( ! F_43 ( V_88 ) ) || ( V_43 != V_43 -> V_89 ) )
return - V_77 ;
V_58 = F_33 ( V_78 ) ;
if ( F_44 ( V_58 ) )
return F_45 ( V_58 ) ;
V_4 = F_1 ( V_43 -> V_45 ) ;
if ( ! V_4 ) {
V_59 = - V_31 ;
goto V_90;
}
if ( V_4 -> V_37 & V_91 )
V_87 = true ;
V_21 = V_4 -> V_12 . V_21 ;
if ( F_44 ( V_21 ) ) {
V_59 = F_45 ( V_21 ) ;
goto V_92;
}
V_80 . V_93 = V_58 -> V_62 . V_93 ;
V_80 . V_94 = V_58 -> V_62 . V_94 ;
V_80 . V_95 = V_58 -> V_62 . V_95 ;
if ( V_58 -> V_65 ) {
V_82 . V_86 = & V_86 ;
V_82 . V_96 = 1 ;
V_82 . V_67 = V_58 -> V_62 . V_67 ;
V_82 . V_68 = V_58 -> V_62 . V_68 ;
F_46 ( V_82 . V_86 , V_58 -> V_18 , V_58 -> V_65 ) ;
if ( V_58 -> V_62 . V_97 )
V_82 . V_95 = V_98 ;
else
V_82 . V_95 = V_99 ;
F_47 ( & V_82 , V_21 ) ;
if ( V_58 -> V_62 . V_100 )
V_82 . V_101 = V_58 -> V_62 . V_100 ;
if ( ( V_80 . V_95 & V_102 ) == V_102 ) {
V_82 . V_101 = V_58 -> V_62 . V_103 * 1000000 ;
}
V_84 . V_82 = & V_82 ;
}
V_84 . V_80 = & V_80 ;
F_17 ( V_21 -> V_32 ) ;
V_59 = F_48 ( V_21 , V_4 ) ;
if ( V_59 )
goto V_104;
if ( V_58 -> V_62 . V_105 ) {
V_59 = F_49 ( V_21 -> V_32 , V_21 ) ;
if ( V_59 )
goto V_104;
}
if ( V_87 ) {
V_59 = F_50 ( V_21 , V_82 . V_68 ,
V_58 -> V_62 . V_97 & ( 1 << 31 ) ) ;
if ( V_59 )
goto V_104;
}
F_51 ( V_21 -> V_32 , & V_84 ) ;
if ( V_80 . error ) {
F_52 ( F_53 ( V_21 -> V_32 ) , L_5 ,
V_106 , V_80 . error ) ;
V_59 = V_80 . error ;
goto V_104;
}
if ( V_82 . error ) {
F_52 ( F_53 ( V_21 -> V_32 ) , L_6 ,
V_106 , V_82 . error ) ;
V_59 = V_82 . error ;
goto V_104;
}
if ( V_58 -> V_62 . V_107 )
F_41 ( V_58 -> V_62 . V_107 , V_58 -> V_62 . V_108 ) ;
if ( F_54 ( & ( V_78 -> V_109 ) , V_80 . V_110 , sizeof( V_80 . V_110 ) ) ) {
V_59 = - V_63 ;
goto V_104;
}
if ( ! V_58 -> V_62 . V_97 ) {
if ( F_54 ( ( void T_4 * ) ( unsigned long ) V_58 -> V_62 . V_71 ,
V_58 -> V_18 , V_58 -> V_65 ) ) {
V_59 = - V_63 ;
goto V_104;
}
}
if ( V_87 ) {
V_59 = F_37 ( V_21 , & V_73 , 5 ) ;
if ( V_59 )
F_52 ( F_53 ( V_21 -> V_32 ) ,
L_7 ,
V_106 , V_73 , V_59 ) ;
}
V_104:
F_20 ( V_21 -> V_32 ) ;
V_92:
F_8 ( V_4 ) ;
V_90:
F_12 ( V_58 -> V_18 ) ;
F_12 ( V_58 ) ;
return V_59 ;
}
static int F_55 ( struct V_42 * V_43 , T_3 V_44 ,
unsigned int V_80 , unsigned long V_94 )
{
int V_19 = - V_31 ;
if ( V_80 == V_111 )
V_19 = F_42 ( V_43 , (struct V_56 T_4 * ) V_94 ) ;
return V_19 ;
}
static int F_56 ( struct V_42 * V_43 , T_3 V_44 ,
unsigned int V_80 , unsigned long V_94 )
{
return F_55 ( V_43 , V_44 , V_80 , ( unsigned long ) F_57 ( V_94 ) ) ;
}
static inline int F_48 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
int V_19 ;
struct V_1 * V_112 = F_58 ( V_21 ) ;
if ( V_112 -> V_113 == V_4 -> V_114 )
return 0 ;
if ( F_59 ( V_21 ) ) {
T_6 V_115 = V_21 -> V_23 . V_115 ;
V_115 &= ~ V_116 ;
V_115 |= V_4 -> V_114 ;
V_19 = F_18 ( V_21 , V_33 ,
V_117 , V_115 ,
V_21 -> V_23 . V_35 ) ;
if ( V_19 )
return V_19 ;
V_21 -> V_23 . V_115 = V_115 ;
}
V_112 -> V_113 = V_4 -> V_114 ;
return 0 ;
}
static T_5 F_60 ( struct V_20 * V_21 )
{
int V_59 ;
T_5 V_118 ;
T_7 * V_68 ;
struct V_83 V_84 = { NULL } ;
struct V_79 V_80 = { 0 } ;
struct V_81 V_82 = { 0 } ;
struct V_85 V_86 ;
V_80 . V_93 = V_119 ;
V_80 . V_94 = V_21 -> V_120 << 16 ;
V_80 . V_95 = V_121 | V_122 | V_123 ;
V_59 = F_61 ( V_21 -> V_32 , & V_80 , 0 ) ;
if ( V_59 )
return ( T_5 ) - 1 ;
if ( ! F_62 ( V_21 -> V_32 ) && ! ( V_80 . V_110 [ 0 ] & V_124 ) )
return ( T_5 ) - 1 ;
memset ( & V_80 , 0 , sizeof( struct V_79 ) ) ;
V_80 . V_93 = V_125 ;
V_80 . V_94 = 0 ;
V_80 . V_95 = V_121 | V_122 | V_126 ;
V_82 . V_67 = 4 ;
V_82 . V_68 = 1 ;
V_82 . V_95 = V_99 ;
V_82 . V_86 = & V_86 ;
V_82 . V_96 = 1 ;
F_47 ( & V_82 , V_21 ) ;
V_84 . V_80 = & V_80 ;
V_84 . V_82 = & V_82 ;
V_68 = F_63 ( 4 , V_60 ) ;
if ( ! V_68 )
return ( T_5 ) - 1 ;
F_46 ( & V_86 , V_68 , 4 ) ;
F_51 ( V_21 -> V_32 , & V_84 ) ;
V_118 = F_64 ( * V_68 ) ;
F_12 ( V_68 ) ;
if ( V_80 . error || V_82 . error )
V_118 = ( T_5 ) - 1 ;
return V_118 ;
}
static int F_65 ( struct V_20 * V_21 , T_5 * V_73 )
{
struct V_79 V_80 = { 0 } ;
int V_59 ;
V_80 . V_93 = V_127 ;
V_80 . V_95 = V_128 | V_102 | V_123 ;
V_59 = F_61 ( V_21 -> V_32 , & V_80 , 5 ) ;
if ( V_59 == 0 )
* V_73 = V_80 . V_110 [ 0 ] ;
return V_59 ;
}
static int F_38 ( struct V_20 * V_21 , T_5 * V_73 , int V_129 )
{
struct V_79 V_80 = { 0 } ;
int V_59 ;
V_80 . V_93 = V_130 ;
if ( ! F_62 ( V_21 -> V_32 ) )
V_80 . V_94 = V_21 -> V_120 << 16 ;
V_80 . V_95 = V_131 | V_122 | V_123 ;
V_59 = F_61 ( V_21 -> V_32 , & V_80 , V_129 ) ;
if ( V_59 == 0 )
* V_73 = V_80 . V_110 [ 0 ] ;
return V_59 ;
}
static int F_66 ( struct V_132 * V_133 , const char * V_134 , int error ,
bool V_135 , T_5 V_73 )
{
switch ( error ) {
case - V_136 :
F_19 ( L_8 ,
V_133 -> V_137 -> V_36 , L_9 ,
V_134 , V_73 ) ;
return V_138 ;
case - V_139 :
F_19 ( L_8 ,
V_133 -> V_137 -> V_36 , L_10 , V_134 , V_73 ) ;
if ( ! V_135 )
return V_138 ;
if ( V_73 & ( V_140 | V_141 ) )
return V_138 ;
return V_142 ;
default:
F_19 ( L_11 ,
V_133 -> V_137 -> V_36 , error , V_73 ) ;
return V_142 ;
}
}
static int F_67 ( struct V_20 * V_21 , struct V_132 * V_133 ,
struct V_143 * V_144 , int * V_145 )
{
bool V_146 = true ;
T_5 V_73 , V_147 = 0 ;
int V_59 , V_148 ;
if ( F_68 ( V_21 ) )
return V_149 ;
for ( V_148 = 2 ; V_148 >= 0 ; V_148 -- ) {
V_59 = F_38 ( V_21 , & V_73 , 0 ) ;
if ( ! V_59 )
break;
V_146 = false ;
F_19 ( L_12 ,
V_133 -> V_137 -> V_36 , V_59 , V_148 ? L_13 : L_14 ) ;
}
if ( V_59 ) {
if ( F_69 ( V_21 -> V_32 ) )
return V_149 ;
return V_142 ;
}
if ( ( V_73 & V_150 ) ||
( V_144 -> V_151 . V_110 [ 0 ] & V_150 ) ||
( V_144 -> V_80 . V_110 [ 0 ] & V_150 ) )
* V_145 = 1 ;
if ( F_40 ( V_73 ) == V_152 ||
F_40 ( V_73 ) == V_153 ) {
V_59 = F_65 ( V_21 , & V_147 ) ;
if ( V_59 )
F_19 ( L_15 ,
V_133 -> V_137 -> V_36 , V_59 ) ;
if ( V_59 )
return V_142 ;
if ( V_147 & V_150 )
* V_145 = 1 ;
}
if ( V_144 -> V_154 . error )
return F_66 ( V_133 , L_16 , V_144 -> V_154 . error ,
V_146 , V_73 ) ;
if ( V_144 -> V_80 . error )
return F_66 ( V_133 , L_17 , V_144 -> V_80 . error ,
V_146 , V_73 ) ;
if ( ! V_144 -> V_151 . error )
return V_155 ;
F_19 ( L_18 ,
V_133 -> V_137 -> V_36 , V_144 -> V_151 . error ,
V_144 -> V_80 . V_110 [ 0 ] , V_73 ) ;
if ( V_147 ) {
V_144 -> V_151 . V_110 [ 0 ] = V_147 ;
V_144 -> V_151 . error = 0 ;
}
return V_155 ;
}
static int F_70 ( struct V_1 * V_4 , struct V_156 * V_32 ,
int type )
{
int V_59 ;
if ( V_4 -> V_157 & type )
return - V_158 ;
V_4 -> V_157 |= type ;
V_59 = F_71 ( V_32 ) ;
if ( V_59 != - V_159 ) {
struct V_1 * V_112 = F_58 ( V_32 -> V_21 ) ;
int V_160 ;
V_112 -> V_113 = V_112 -> V_114 ;
V_160 = F_48 ( V_32 -> V_21 , V_4 ) ;
if ( V_160 ) {
return - V_161 ;
}
}
return V_59 ;
}
static inline void F_72 ( struct V_1 * V_4 , int type )
{
V_4 -> V_157 &= ~ type ;
}
static int F_73 ( struct V_162 * V_163 , struct V_132 * V_133 )
{
struct V_1 * V_4 = V_163 -> V_82 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
unsigned int V_164 , V_165 , V_94 ;
int V_59 = 0 , type = V_166 ;
if ( ! F_74 ( V_21 ) ) {
V_59 = - V_159 ;
goto V_41;
}
V_164 = F_75 ( V_133 ) ;
V_165 = F_76 ( V_133 ) ;
if ( F_77 ( V_21 ) )
V_94 = V_167 ;
else if ( F_78 ( V_21 ) )
V_94 = V_168 ;
else
V_94 = V_169 ;
V_148:
if ( V_21 -> V_170 & V_171 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_172 ,
V_94 == V_168 ?
V_173 :
V_174 ,
0 ) ;
if ( V_59 )
goto V_41;
}
V_59 = F_79 ( V_21 , V_164 , V_165 , V_94 ) ;
V_41:
if ( V_59 == - V_175 && ! F_70 ( V_4 , V_21 -> V_32 , type ) )
goto V_148;
if ( ! V_59 )
F_72 ( V_4 , type ) ;
F_80 ( V_133 , V_59 , F_81 ( V_133 ) ) ;
return V_59 ? 0 : 1 ;
}
static int F_82 ( struct V_162 * V_163 ,
struct V_132 * V_133 )
{
struct V_1 * V_4 = V_163 -> V_82 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
unsigned int V_164 , V_165 , V_94 , V_176 , V_177 ;
int V_59 = 0 , type = V_178 ;
if ( ! ( F_83 ( V_21 ) || F_84 ( V_21 ) ) ) {
V_59 = - V_159 ;
goto V_41;
}
V_164 = F_75 ( V_133 ) ;
V_165 = F_76 ( V_133 ) ;
if ( F_84 ( V_21 ) ) {
V_177 = V_169 ;
V_176 = V_168 ;
} else {
V_177 = V_179 ;
V_176 = V_180 ;
}
if ( F_85 ( V_21 , V_164 , V_165 ) )
V_94 = V_177 ;
else if ( F_78 ( V_21 ) )
V_94 = V_176 ;
else {
V_59 = - V_31 ;
goto V_41;
}
V_148:
if ( V_21 -> V_170 & V_171 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_172 ,
V_94 == V_180 ?
V_181 :
V_182 ,
0 ) ;
if ( V_59 )
goto V_183;
}
V_59 = F_79 ( V_21 , V_164 , V_165 , V_94 ) ;
if ( V_59 == - V_175 )
goto V_183;
if ( V_59 )
goto V_41;
if ( V_94 == V_180 ) {
if ( V_21 -> V_170 & V_171 ) {
V_59 = F_18 ( V_21 , V_33 ,
V_172 ,
V_184 ,
0 ) ;
if ( V_59 )
goto V_183;
}
V_59 = F_79 ( V_21 , V_164 , V_165 , V_185 ) ;
if ( V_59 == - V_175 )
goto V_183;
if ( V_59 )
goto V_41;
}
if ( F_84 ( V_21 ) )
V_59 = F_18 ( V_21 , V_33 ,
V_186 , 1 , 0 ) ;
V_183:
if ( V_59 && ! F_70 ( V_4 , V_21 -> V_32 , type ) )
goto V_148;
if ( ! V_59 )
F_72 ( V_4 , type ) ;
V_41:
F_80 ( V_133 , V_59 , F_81 ( V_133 ) ) ;
return V_59 ? 0 : 1 ;
}
static int F_86 ( struct V_162 * V_163 , struct V_132 * V_133 )
{
struct V_1 * V_4 = V_163 -> V_82 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
int V_19 = 0 ;
V_19 = F_87 ( V_21 ) ;
if ( V_19 )
V_19 = - V_175 ;
F_88 ( V_133 , V_19 ) ;
return V_19 ? 0 : 1 ;
}
static inline void F_89 ( struct V_143 * V_144 ,
struct V_20 * V_21 ,
struct V_132 * V_133 )
{
if ( ! ( V_21 -> V_23 . V_187 & V_188 ) ) {
if ( ! F_90 ( V_144 -> V_80 . V_94 , V_21 -> V_23 . V_189 ) )
V_144 -> V_82 . V_68 = 1 ;
if ( V_144 -> V_82 . V_68 > V_21 -> V_23 . V_189 )
V_144 -> V_82 . V_68 = V_21 -> V_23 . V_189 ;
else if ( V_144 -> V_82 . V_68 < V_21 -> V_23 . V_189 )
V_144 -> V_82 . V_68 = 1 ;
}
}
static int F_91 ( struct V_20 * V_21 ,
struct V_190 * V_191 )
{
struct V_192 * V_193 = F_92 ( V_191 , struct V_192 ,
V_194 ) ;
struct V_143 * V_144 = & V_193 -> V_144 ;
struct V_132 * V_133 = V_193 -> V_133 ;
int V_145 = 0 ;
if ( V_144 -> V_154 . error || V_144 -> V_80 . error || V_144 -> V_151 . error ||
V_144 -> V_82 . error ) {
switch ( F_67 ( V_21 , V_133 , V_144 , & V_145 ) ) {
case V_138 :
return V_195 ;
case V_142 :
return V_196 ;
case V_149 :
return V_197 ;
case V_155 :
break;
}
}
if ( V_144 -> V_80 . V_110 [ 0 ] & V_198 ) {
F_19 ( L_19 ,
V_133 -> V_137 -> V_36 , V_144 -> V_80 . V_110 [ 0 ] ) ;
return V_196 ;
}
if ( ! F_62 ( V_21 -> V_32 ) && F_93 ( V_133 ) != V_199 ) {
T_5 V_73 ;
unsigned long V_200 ;
V_200 = V_201 + F_94 ( V_202 ) ;
do {
int V_59 = F_38 ( V_21 , & V_73 , 5 ) ;
if ( V_59 ) {
F_19 ( L_20 ,
V_133 -> V_137 -> V_36 , V_59 ) ;
return V_203 ;
}
if ( F_95 ( V_201 , V_200 ) ) {
F_19 ( L_21\
L_22 , F_96 ( V_21 -> V_32 ) ,
V_133 -> V_137 -> V_36 , V_106 ) ;
return V_203 ;
}
} while ( ! ( V_73 & V_204 ) ||
( F_40 ( V_73 ) == V_76 ) );
}
if ( V_144 -> V_82 . error ) {
F_19 ( L_23 ,
V_133 -> V_137 -> V_36 , V_144 -> V_82 . error ,
( unsigned ) F_75 ( V_133 ) ,
( unsigned ) F_76 ( V_133 ) ,
V_144 -> V_80 . V_110 [ 0 ] , V_144 -> V_151 . V_110 [ 0 ] ) ;
if ( F_93 ( V_133 ) == V_199 ) {
if ( V_145 )
return V_205 ;
return V_206 ;
} else {
return V_203 ;
}
}
if ( ! V_144 -> V_82 . V_207 )
return V_195 ;
if ( F_81 ( V_133 ) != V_144 -> V_82 . V_207 )
return V_208 ;
return V_209 ;
}
static void F_97 ( struct V_192 * V_210 ,
struct V_20 * V_21 ,
int V_211 ,
struct V_162 * V_163 )
{
T_5 V_212 , V_213 ;
struct V_143 * V_144 = & V_210 -> V_144 ;
struct V_132 * V_133 = V_210 -> V_133 ;
struct V_1 * V_4 = V_163 -> V_82 ;
bool V_214 ;
bool V_215 = ( ( V_133 -> V_216 & V_217 ) ||
( V_133 -> V_216 & V_218 ) ) &&
( F_93 ( V_133 ) == V_219 ) &&
( V_4 -> V_95 & V_220 ) ;
memset ( V_144 , 0 , sizeof( struct V_143 ) ) ;
V_144 -> V_84 . V_80 = & V_144 -> V_80 ;
V_144 -> V_84 . V_82 = & V_144 -> V_82 ;
V_144 -> V_80 . V_94 = F_75 ( V_133 ) ;
if ( ! F_98 ( V_21 ) )
V_144 -> V_80 . V_94 <<= 9 ;
V_144 -> V_80 . V_95 = V_121 | V_122 | V_126 ;
V_144 -> V_82 . V_67 = 512 ;
V_144 -> V_151 . V_93 = V_127 ;
V_144 -> V_151 . V_94 = 0 ;
V_144 -> V_151 . V_95 = V_128 | V_102 | V_123 ;
V_144 -> V_82 . V_68 = F_76 ( V_133 ) ;
if ( V_144 -> V_82 . V_68 > V_21 -> V_32 -> V_221 )
V_144 -> V_82 . V_68 = V_21 -> V_32 -> V_221 ;
if ( V_144 -> V_82 . V_68 > 1 ) {
if ( V_211 )
V_144 -> V_82 . V_68 = 1 ;
if ( V_21 -> V_32 -> V_222 & V_223 &&
F_93 ( V_133 ) == V_199 )
V_144 -> V_82 . V_68 = 1 ;
}
if ( V_144 -> V_82 . V_68 > 1 || V_215 ) {
if ( ! F_62 ( V_21 -> V_32 ) ||
F_93 ( V_133 ) == V_199 )
V_144 -> V_84 . V_151 = & V_144 -> V_151 ;
V_212 = V_224 ;
V_213 = V_225 ;
} else {
V_144 -> V_84 . V_151 = NULL ;
V_212 = V_226 ;
V_213 = V_227 ;
}
if ( F_93 ( V_133 ) == V_199 ) {
V_144 -> V_80 . V_93 = V_212 ;
V_144 -> V_82 . V_95 |= V_99 ;
} else {
V_144 -> V_80 . V_93 = V_213 ;
V_144 -> V_82 . V_95 |= V_98 ;
}
if ( V_215 )
F_89 ( V_144 , V_21 , V_133 ) ;
V_214 = ( V_21 -> V_23 . V_228 ) &&
( V_133 -> V_216 & V_218 ) &&
( F_93 ( V_133 ) == V_219 ) &&
( ( V_144 -> V_82 . V_68 * V_144 -> V_82 . V_67 ) >=
V_21 -> V_23 . V_228 ) ;
if ( ( V_4 -> V_95 & V_229 ) && F_99 ( V_144 -> V_80 . V_93 ) &&
( V_215 || ! ( V_21 -> V_170 & V_230 ) ||
V_214 ) ) {
V_144 -> V_154 . V_93 = V_231 ;
V_144 -> V_154 . V_94 = V_144 -> V_82 . V_68 |
( V_215 ? ( 1 << 31 ) : 0 ) |
( V_214 ? ( 1 << 29 ) : 0 ) ;
V_144 -> V_154 . V_95 = V_122 | V_123 ;
V_144 -> V_84 . V_154 = & V_144 -> V_154 ;
}
F_47 ( & V_144 -> V_82 , V_21 ) ;
V_144 -> V_82 . V_86 = V_210 -> V_86 ;
V_144 -> V_82 . V_96 = F_100 ( V_163 , V_210 ) ;
if ( V_144 -> V_82 . V_68 != F_76 ( V_133 ) ) {
int V_232 , V_233 = V_144 -> V_82 . V_68 << 9 ;
struct V_85 * V_86 ;
F_101 (brq->data.sg, sg, brq->data.sg_len, i) {
V_233 -= V_86 -> V_234 ;
if ( V_233 <= 0 ) {
V_86 -> V_234 += V_233 ;
V_232 ++ ;
break;
}
}
V_144 -> V_82 . V_96 = V_232 ;
}
V_210 -> V_194 . V_84 = & V_144 -> V_84 ;
V_210 -> V_194 . V_235 = F_91 ;
F_102 ( V_210 ) ;
}
static int F_103 ( struct V_1 * V_4 , struct V_20 * V_21 ,
struct V_143 * V_144 , struct V_132 * V_133 ,
int V_19 )
{
if ( F_104 ( V_21 ) ) {
T_5 V_68 ;
V_68 = F_60 ( V_21 ) ;
if ( V_68 != ( T_5 ) - 1 ) {
V_19 = F_80 ( V_133 , 0 , V_68 << 9 ) ;
}
} else {
V_19 = F_80 ( V_133 , 0 , V_144 -> V_82 . V_207 ) ;
}
return V_19 ;
}
static int F_105 ( struct V_162 * V_163 , struct V_132 * V_236 )
{
struct V_1 * V_4 = V_163 -> V_82 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
struct V_143 * V_144 = & V_163 -> V_237 -> V_144 ;
int V_19 = 1 , V_211 = 0 , V_148 = 0 , type ;
enum V_238 V_73 ;
struct V_192 * V_239 ;
struct V_132 * V_133 = V_236 ;
struct V_190 * V_191 ;
if ( ! V_236 && ! V_163 -> V_240 -> V_133 )
return 0 ;
do {
if ( V_236 ) {
if ( ( V_144 -> V_82 . V_68 & 0x07 ) &&
( V_21 -> V_23 . V_241 == 4096 ) ) {
F_19 ( L_24 ,
V_133 -> V_137 -> V_36 ) ;
goto V_242;
}
F_97 ( V_163 -> V_237 , V_21 , 0 , V_163 ) ;
V_191 = & V_163 -> V_237 -> V_194 ;
} else
V_191 = NULL ;
V_191 = F_106 ( V_21 -> V_32 , V_191 , ( int * ) & V_73 ) ;
if ( ! V_191 )
return 0 ;
V_239 = F_92 ( V_191 , struct V_192 , V_194 ) ;
V_144 = & V_239 -> V_144 ;
V_133 = V_239 -> V_133 ;
type = F_93 ( V_133 ) == V_199 ? V_243 : V_244 ;
F_107 ( V_239 ) ;
switch ( V_73 ) {
case V_209 :
case V_208 :
F_72 ( V_4 , type ) ;
V_19 = F_80 ( V_133 , 0 ,
V_144 -> V_82 . V_207 ) ;
if ( V_73 == V_209 && V_19 ) {
F_19 ( L_25 ,
V_106 , F_81 ( V_133 ) ,
V_144 -> V_82 . V_207 ) ;
V_236 = NULL ;
goto V_242;
}
break;
case V_203 :
V_19 = F_103 ( V_4 , V_21 , V_144 , V_133 , V_19 ) ;
if ( ! F_70 ( V_4 , V_21 -> V_32 , type ) )
break;
goto V_242;
case V_195 :
if ( V_148 ++ < 5 )
break;
case V_196 :
if ( ! F_70 ( V_4 , V_21 -> V_32 , type ) )
break;
goto V_242;
case V_206 : {
int V_59 ;
V_59 = F_70 ( V_4 , V_21 -> V_32 , type ) ;
if ( ! V_59 )
break;
if ( V_59 == - V_161 )
goto V_242;
}
case V_205 :
if ( V_144 -> V_82 . V_68 > 1 ) {
F_108 ( L_26 ,
V_133 -> V_137 -> V_36 ) ;
V_211 = 1 ;
break;
}
V_19 = F_80 ( V_133 , - V_175 ,
V_144 -> V_82 . V_67 ) ;
if ( ! V_19 )
goto V_245;
break;
case V_197 :
goto V_242;
}
if ( V_19 ) {
F_97 ( V_239 , V_21 , V_211 , V_163 ) ;
F_106 ( V_21 -> V_32 , & V_239 -> V_194 , NULL ) ;
}
} while ( V_19 );
return 1 ;
V_242:
if ( F_68 ( V_21 ) )
V_133 -> V_216 |= V_246 ;
while ( V_19 )
V_19 = F_80 ( V_133 , - V_175 , F_109 ( V_133 ) ) ;
V_245:
if ( V_236 ) {
F_97 ( V_163 -> V_237 , V_21 , 0 , V_163 ) ;
F_106 ( V_21 -> V_32 , & V_163 -> V_237 -> V_194 , NULL ) ;
}
return 0 ;
}
static int F_110 ( struct V_162 * V_163 , struct V_132 * V_133 )
{
int V_19 ;
struct V_1 * V_4 = V_163 -> V_82 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
if ( V_133 && ! V_163 -> V_240 -> V_133 )
F_17 ( V_21 -> V_32 ) ;
V_19 = F_48 ( V_21 , V_4 ) ;
if ( V_19 ) {
if ( V_133 ) {
F_88 ( V_133 , - V_175 ) ;
}
V_19 = 0 ;
goto V_41;
}
if ( V_133 && V_133 -> V_216 & V_247 ) {
if ( V_21 -> V_32 -> V_191 )
F_105 ( V_163 , NULL ) ;
if ( V_133 -> V_216 & V_248 &&
! ( V_21 -> V_170 & V_249 ) )
V_19 = F_82 ( V_163 , V_133 ) ;
else
V_19 = F_73 ( V_163 , V_133 ) ;
} else if ( V_133 && V_133 -> V_216 & V_250 ) {
if ( V_21 -> V_32 -> V_191 )
F_105 ( V_163 , NULL ) ;
V_19 = F_86 ( V_163 , V_133 ) ;
} else {
V_19 = F_105 ( V_163 , V_133 ) ;
}
V_41:
if ( ! V_133 )
F_20 ( V_21 -> V_32 ) ;
return V_19 ;
}
static inline int F_111 ( struct V_20 * V_21 )
{
return F_112 ( V_21 ) ||
! ( V_21 -> V_251 . V_252 & V_253 ) ;
}
static struct V_1 * F_113 ( struct V_20 * V_21 ,
struct V_14 * V_254 ,
T_8 V_255 ,
bool V_256 ,
const char * V_257 ,
int V_37 )
{
struct V_1 * V_4 ;
int V_9 , V_19 ;
V_9 = F_114 ( V_13 , V_258 ) ;
if ( V_9 >= V_258 )
return F_36 ( - V_259 ) ;
F_115 ( V_9 , V_13 ) ;
V_4 = F_34 ( sizeof( struct V_1 ) , V_60 ) ;
if ( ! V_4 ) {
V_19 = - V_61 ;
goto V_41;
}
if ( ! V_257 ) {
V_4 -> V_260 = F_114 ( V_261 , V_258 ) ;
F_115 ( V_4 -> V_260 , V_261 ) ;
} else
V_4 -> V_260 = ( (struct V_1 * )
F_14 ( V_254 ) -> V_6 ) -> V_260 ;
V_4 -> V_37 = V_37 ;
V_4 -> V_39 = F_111 ( V_21 ) ;
V_4 -> V_3 = F_116 ( V_10 ) ;
if ( V_4 -> V_3 == NULL ) {
V_19 = - V_61 ;
goto V_262;
}
F_117 ( & V_4 -> V_263 ) ;
F_118 ( & V_4 -> V_264 ) ;
V_4 -> V_7 = 1 ;
V_19 = F_119 ( & V_4 -> V_12 , V_21 , & V_4 -> V_263 , V_257 ) ;
if ( V_19 )
goto V_265;
V_4 -> V_12 . V_266 = F_110 ;
V_4 -> V_12 . V_82 = V_4 ;
V_4 -> V_3 -> V_267 = V_268 ;
V_4 -> V_3 -> V_11 = V_9 * V_10 ;
V_4 -> V_3 -> V_269 = & V_270 ;
V_4 -> V_3 -> V_6 = V_4 ;
V_4 -> V_3 -> V_12 = V_4 -> V_12 . V_12 ;
V_4 -> V_3 -> V_271 = V_254 ;
F_22 ( V_4 -> V_3 , V_4 -> V_39 || V_256 ) ;
if ( V_37 & V_91 )
V_4 -> V_3 -> V_95 |= V_272 ;
snprintf ( V_4 -> V_3 -> V_36 , sizeof( V_4 -> V_3 -> V_36 ) ,
L_27 , V_4 -> V_260 , V_257 ? V_257 : L_28 ) ;
if ( F_59 ( V_21 ) )
F_120 ( V_4 -> V_12 . V_12 ,
V_21 -> V_23 . V_241 ) ;
else
F_120 ( V_4 -> V_12 . V_12 , 512 ) ;
F_121 ( V_4 -> V_3 , V_255 ) ;
if ( F_122 ( V_21 -> V_32 ) ) {
if ( F_59 ( V_21 ) ||
( F_104 ( V_21 ) &&
V_21 -> V_273 . V_274 & V_275 ) )
V_4 -> V_95 |= V_229 ;
}
if ( F_59 ( V_21 ) &&
V_4 -> V_95 & V_229 &&
( ( V_21 -> V_23 . V_187 & V_188 ) ||
V_21 -> V_23 . V_189 ) ) {
V_4 -> V_95 |= V_220 ;
F_123 ( V_4 -> V_12 . V_12 , V_250 | V_217 ) ;
}
return V_4 ;
V_265:
F_11 ( V_4 -> V_3 ) ;
V_262:
F_12 ( V_4 ) ;
V_41:
return F_36 ( V_19 ) ;
}
static struct V_1 * F_124 ( struct V_20 * V_21 )
{
T_8 V_255 ;
struct V_1 * V_4 ;
if ( ! F_104 ( V_21 ) && F_98 ( V_21 ) ) {
V_255 = V_21 -> V_23 . V_54 ;
} else {
V_255 = V_21 -> V_251 . V_276 << ( V_21 -> V_251 . V_277 - 9 ) ;
}
V_4 = F_113 ( V_21 , & V_21 -> V_15 , V_255 , false , NULL ,
V_278 ) ;
return V_4 ;
}
static int F_125 ( struct V_20 * V_21 ,
struct V_1 * V_4 ,
unsigned int V_114 ,
T_8 V_255 ,
bool V_256 ,
const char * V_257 ,
int V_37 )
{
char V_279 [ 10 ] ;
struct V_1 * V_29 ;
V_29 = F_113 ( V_21 , F_126 ( V_4 -> V_3 ) , V_255 , V_256 ,
V_257 , V_37 ) ;
if ( F_44 ( V_29 ) )
return F_45 ( V_29 ) ;
V_29 -> V_114 = V_114 ;
F_127 ( & V_29 -> V_264 , & V_4 -> V_264 ) ;
F_128 ( ( V_66 ) F_32 ( V_29 -> V_3 ) << 9 , V_280 ,
V_279 , sizeof( V_279 ) ) ;
F_21 ( L_29 ,
V_29 -> V_3 -> V_36 , F_129 ( V_21 ) ,
F_130 ( V_21 ) , V_29 -> V_114 , V_279 ) ;
return 0 ;
}
static int F_131 ( struct V_20 * V_21 , struct V_1 * V_4 )
{
int V_281 , V_19 = 0 ;
if ( ! F_59 ( V_21 ) )
return 0 ;
for ( V_281 = 0 ; V_281 < V_21 -> V_282 ; V_281 ++ ) {
if ( V_21 -> V_264 [ V_281 ] . V_255 ) {
V_19 = F_125 ( V_21 , V_4 ,
V_21 -> V_264 [ V_281 ] . V_283 ,
V_21 -> V_264 [ V_281 ] . V_255 >> 9 ,
V_21 -> V_264 [ V_281 ] . V_284 ,
V_21 -> V_264 [ V_281 ] . V_134 ,
V_21 -> V_264 [ V_281 ] . V_37 ) ;
if ( V_19 )
return V_19 ;
}
}
return V_19 ;
}
static void F_132 ( struct V_1 * V_4 )
{
struct V_20 * V_21 ;
if ( V_4 ) {
V_21 = V_4 -> V_12 . V_21 ;
if ( V_4 -> V_3 -> V_95 & V_285 ) {
F_133 ( F_126 ( V_4 -> V_3 ) , & V_4 -> V_284 ) ;
if ( ( V_4 -> V_37 & V_38 ) &&
V_21 -> V_23 . V_286 )
F_133 ( F_126 ( V_4 -> V_3 ) ,
& V_4 -> V_287 ) ;
F_134 ( V_4 -> V_3 ) ;
}
F_135 ( & V_4 -> V_12 ) ;
F_8 ( V_4 ) ;
}
}
static void F_136 ( struct V_20 * V_21 ,
struct V_1 * V_4 )
{
struct V_288 * V_289 , * V_290 ;
struct V_1 * V_29 ;
F_10 ( V_4 -> V_260 , V_261 ) ;
F_137 (pos, q, &md->part) {
V_29 = F_138 ( V_289 , struct V_1 , V_264 ) ;
F_139 ( V_289 ) ;
F_132 ( V_29 ) ;
}
}
static int F_140 ( struct V_1 * V_4 )
{
int V_19 ;
struct V_20 * V_21 = V_4 -> V_12 . V_21 ;
F_141 ( V_4 -> V_3 ) ;
V_4 -> V_284 . V_291 = F_24 ;
V_4 -> V_284 . V_292 = F_26 ;
F_142 ( & V_4 -> V_284 . V_17 ) ;
V_4 -> V_284 . V_17 . V_134 = L_30 ;
V_4 -> V_284 . V_17 . V_44 = V_293 | V_294 ;
V_19 = F_143 ( F_126 ( V_4 -> V_3 ) , & V_4 -> V_284 ) ;
if ( V_19 )
goto V_295;
if ( ( V_4 -> V_37 & V_38 ) &&
V_21 -> V_23 . V_286 ) {
T_9 V_44 ;
if ( V_21 -> V_23 . V_24 & V_296 )
V_44 = V_293 ;
else
V_44 = V_293 | V_294 ;
V_4 -> V_287 . V_291 = F_13 ;
V_4 -> V_287 . V_292 = F_15 ;
F_142 ( & V_4 -> V_287 . V_17 ) ;
V_4 -> V_287 . V_17 . V_44 = V_44 ;
V_4 -> V_287 . V_17 . V_134 =
L_31 ;
V_19 = F_143 ( F_126 ( V_4 -> V_3 ) ,
& V_4 -> V_287 ) ;
if ( V_19 )
goto V_297;
}
return V_19 ;
V_297:
F_133 ( F_126 ( V_4 -> V_3 ) , & V_4 -> V_284 ) ;
V_295:
F_134 ( V_4 -> V_3 ) ;
return V_19 ;
}
static int F_144 ( struct V_20 * V_21 )
{
struct V_1 * V_4 , * V_29 ;
char V_279 [ 10 ] ;
if ( ! ( V_21 -> V_251 . V_252 & V_298 ) )
return - V_161 ;
V_4 = F_124 ( V_21 ) ;
if ( F_44 ( V_4 ) )
return F_45 ( V_4 ) ;
F_128 ( ( V_66 ) F_32 ( V_4 -> V_3 ) << 9 , V_280 ,
V_279 , sizeof( V_279 ) ) ;
F_21 ( L_32 ,
V_4 -> V_3 -> V_36 , F_129 ( V_21 ) , F_130 ( V_21 ) ,
V_279 , V_4 -> V_39 ? L_33 : L_28 ) ;
if ( F_131 ( V_21 , V_4 ) )
goto V_41;
F_145 ( V_21 , V_4 ) ;
F_146 ( V_21 , V_299 ) ;
if ( F_140 ( V_4 ) )
goto V_41;
F_23 (part_md, &md->part, part) {
if ( F_140 ( V_29 ) )
goto V_41;
}
return 0 ;
V_41:
F_136 ( V_21 , V_4 ) ;
F_132 ( V_4 ) ;
return 0 ;
}
static void F_147 ( struct V_20 * V_21 )
{
struct V_1 * V_4 = F_58 ( V_21 ) ;
F_136 ( V_21 , V_4 ) ;
F_17 ( V_21 -> V_32 ) ;
F_48 ( V_21 , V_4 ) ;
F_20 ( V_21 -> V_32 ) ;
F_132 ( V_4 ) ;
F_145 ( V_21 , NULL ) ;
}
static int F_148 ( struct V_20 * V_21 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_58 ( V_21 ) ;
if ( V_4 ) {
F_149 ( & V_4 -> V_12 ) ;
F_23 (part_md, &md->part, part) {
F_149 ( & V_29 -> V_12 ) ;
}
}
return 0 ;
}
static int F_150 ( struct V_20 * V_21 )
{
struct V_1 * V_29 ;
struct V_1 * V_4 = F_58 ( V_21 ) ;
if ( V_4 ) {
V_4 -> V_113 = V_4 -> V_114 ;
F_151 ( & V_4 -> V_12 ) ;
F_23 (part_md, &md->part, part) {
F_151 ( & V_29 -> V_12 ) ;
}
}
return 0 ;
}
static int T_10 F_152 ( void )
{
int V_300 ;
if ( V_10 != V_301 )
F_21 ( L_34 , V_10 ) ;
V_258 = 256 / V_10 ;
V_300 = F_153 ( V_268 , L_35 ) ;
if ( V_300 )
goto V_41;
V_300 = F_154 ( & V_302 ) ;
if ( V_300 )
goto V_303;
return 0 ;
V_303:
F_155 ( V_268 , L_35 ) ;
V_41:
return V_300 ;
}
static void T_11 F_156 ( void )
{
F_157 ( & V_302 ) ;
F_155 ( V_268 , L_35 ) ;
}
