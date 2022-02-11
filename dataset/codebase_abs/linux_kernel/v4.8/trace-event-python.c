static void F_1 ( const char * V_1 )
{
F_2 () ;
F_3 ( L_1 ) ;
abort () ;
}
static void F_4 ( T_1 * V_2 , const char * V_3 , T_1 * V_4 )
{
F_5 ( V_2 , V_3 , V_4 ) ;
F_6 ( V_4 ) ;
}
static T_1 * F_7 ( const char * V_1 )
{
T_1 * V_5 ;
V_5 = F_8 ( V_6 , V_1 ) ;
if ( V_5 && ! F_9 ( V_5 ) )
return NULL ;
return V_5 ;
}
static void F_10 ( T_1 * V_5 , T_1 * args , const char * V_7 )
{
T_1 * V_8 ;
V_8 = F_11 ( V_5 , args ) ;
if ( V_8 == NULL )
F_1 ( V_7 ) ;
F_6 ( V_8 ) ;
}
static void F_12 ( const char * V_1 , T_1 * args )
{
T_1 * V_5 ;
V_5 = F_7 ( V_1 ) ;
if ( V_5 )
F_10 ( V_5 , args , V_1 ) ;
}
static void F_13 ( enum V_9 V_10 ,
const char * V_11 ,
const char * V_12 ,
const char * V_13 ,
const char * V_14 )
{
const char * V_1 = L_2 ;
T_1 * V_15 ;
unsigned long long V_16 ;
unsigned V_17 = 0 ;
if ( V_10 == V_18 )
V_1 = L_3 ;
V_15 = F_14 ( 4 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_16 = F_15 ( V_13 ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_11 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_12 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_16 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_14 ) ) ;
F_12 ( V_1 , V_15 ) ;
F_6 ( V_15 ) ;
}
static void F_19 ( enum V_9 V_10 ,
struct V_19 * V_20 ,
const char * V_11 ,
const char * V_12 )
{
F_13 ( V_10 , V_11 , V_12 , V_20 -> V_16 ,
V_20 -> V_21 ) ;
if ( V_20 -> V_22 )
F_19 ( V_10 , V_20 -> V_22 , V_11 , V_12 ) ;
}
static void F_20 ( enum V_9 V_10 ,
const char * V_11 ,
const char * V_12 ,
const char * V_23 )
{
const char * V_1 = L_5 ;
T_1 * V_15 ;
unsigned V_17 = 0 ;
if ( V_10 == V_18 )
V_1 = L_6 ;
if ( V_10 == V_24 )
V_15 = F_14 ( 3 ) ;
else
V_15 = F_14 ( 2 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_11 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_12 ) ) ;
if ( V_10 == V_24 )
F_16 ( V_15 , V_17 ++ , F_17 ( V_23 ) ) ;
F_12 ( V_1 , V_15 ) ;
F_6 ( V_15 ) ;
}
static void F_21 ( struct V_25 * V_26 ,
const char * V_11 ,
struct V_27 * args )
{
if ( args == NULL )
return;
switch ( args -> type ) {
case V_28 :
break;
case V_29 :
F_13 ( V_24 , V_11 , V_30 , L_7 ,
args -> V_31 . V_31 ) ;
V_32 = 0 ;
break;
case V_33 :
free ( V_30 ) ;
V_30 = F_22 ( args -> V_20 . V_34 ) ;
break;
case V_24 :
F_21 ( V_26 , V_11 , args -> V_35 . V_20 ) ;
F_20 ( V_24 , V_11 , V_30 ,
args -> V_35 . V_23 ) ;
F_19 ( V_24 , args -> V_35 . V_35 , V_11 ,
V_30 ) ;
break;
case V_18 :
F_21 ( V_26 , V_11 , args -> V_36 . V_20 ) ;
F_20 ( V_18 , V_11 , V_30 , NULL ) ;
F_19 ( V_18 , args -> V_36 . V_37 , V_11 ,
V_30 ) ;
break;
case V_38 :
F_21 ( V_26 , V_11 , args -> V_39 . V_20 ) ;
F_21 ( V_26 , V_11 , args -> V_39 . V_40 ) ;
break;
case V_41 :
F_21 ( V_26 , V_11 , args -> V_42 . V_20 ) ;
F_21 ( V_26 , V_11 , args -> V_42 . V_43 ) ;
F_21 ( V_26 , V_11 , args -> V_42 . V_44 ) ;
break;
case V_45 :
break;
case V_46 :
F_21 ( V_26 , V_11 , args -> V_47 . V_48 ) ;
break;
case V_49 :
if ( strcmp ( args -> V_50 . V_50 , L_8 ) == 0 )
V_32 = 1 ;
F_21 ( V_26 , V_11 , args -> V_50 . V_51 ) ;
F_21 ( V_26 , V_11 , args -> V_50 . V_52 ) ;
break;
default:
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
return;
}
if ( args -> V_22 )
F_21 ( V_26 , V_11 , args -> V_22 ) ;
}
static T_1 * F_23 ( struct V_25 * V_26 ,
struct V_58 * V_20 , void * V_59 )
{
bool V_60 = V_20 -> V_35 & V_61 ;
T_1 * V_62 = NULL , * V_63 = NULL ;
unsigned long long V_4 ;
unsigned int V_64 , V_65 , V_66 ;
if ( V_60 ) {
V_63 = F_24 ( V_20 -> V_67 ) ;
V_64 = V_20 -> V_40 / V_20 -> V_67 ;
V_65 = V_20 -> V_67 ;
} else {
V_64 = V_20 -> V_40 ;
V_65 = 1 ;
}
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
V_4 = F_25 ( V_26 , V_59 + V_20 -> V_68 + V_66 * V_64 ,
V_64 ) ;
if ( V_20 -> V_35 & V_69 ) {
if ( ( long long ) V_4 >= V_70 &&
( long long ) V_4 <= V_71 )
V_62 = F_18 ( V_4 ) ;
else
V_62 = F_26 ( V_4 ) ;
} else {
if ( V_4 <= V_71 )
V_62 = F_18 ( V_4 ) ;
else
V_62 = F_27 ( V_4 ) ;
}
if ( V_60 )
F_28 ( V_63 , V_66 , V_62 ) ;
}
if ( V_60 )
V_62 = V_63 ;
return V_62 ;
}
static T_1 * F_29 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
T_1 * V_78 ;
V_78 = F_24 ( 0 ) ;
if ( ! V_78 )
F_3 ( L_9 ) ;
if ( ! V_79 . V_80 || ! V_73 -> V_81 )
goto exit;
if ( F_30 ( V_77 -> V_82 , & V_83 , V_75 ,
V_73 , NULL , NULL ,
V_84 ) != 0 ) {
F_31 ( L_10 ) ;
goto exit;
}
F_32 ( & V_83 ) ;
while ( 1 ) {
T_1 * V_85 ;
struct V_86 * V_87 ;
V_87 = F_33 ( & V_83 ) ;
if ( ! V_87 )
break;
V_85 = F_34 () ;
if ( ! V_85 )
F_3 ( L_11 ) ;
F_4 ( V_85 , L_12 ,
F_27 ( V_87 -> V_88 ) ) ;
if ( V_87 -> V_89 ) {
T_1 * V_90 = F_34 () ;
if ( ! V_90 )
F_3 ( L_11 ) ;
F_4 ( V_90 , L_13 ,
F_27 ( V_87 -> V_89 -> V_91 ) ) ;
F_4 ( V_90 , L_14 ,
F_27 ( V_87 -> V_89 -> V_92 ) ) ;
F_4 ( V_90 , L_15 ,
F_18 ( V_87 -> V_89 -> V_93 ) ) ;
F_4 ( V_90 , L_16 ,
F_35 ( V_87 -> V_89 -> V_34 ,
V_87 -> V_89 -> V_94 ) ) ;
F_4 ( V_85 , L_17 , V_90 ) ;
}
if ( V_87 -> V_95 ) {
struct V_95 * V_95 = V_87 -> V_95 ;
const char * V_96 = L_18 ;
if ( V_95 && V_95 -> V_97 && ( V_95 -> V_97 -> V_34 || V_95 -> V_97 -> V_98 ) ) {
if ( V_79 . V_99 && V_95 -> V_97 -> V_98 )
V_96 = V_95 -> V_97 -> V_98 ;
else if ( V_95 -> V_97 -> V_34 )
V_96 = V_95 -> V_97 -> V_34 ;
}
F_4 ( V_85 , L_19 ,
F_17 ( V_96 ) ) ;
}
F_36 ( & V_83 ) ;
F_37 ( V_78 , V_85 ) ;
F_6 ( V_85 ) ;
}
exit:
return V_78 ;
}
static void F_38 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_25 * V_26 = V_75 -> V_100 ;
T_1 * V_5 , * V_101 , * V_15 , * V_62 = NULL , * V_81 ;
T_1 * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_58 * V_20 ;
unsigned long V_102 , V_103 ;
unsigned V_17 = 0 ;
int V_104 ;
int V_105 = V_73 -> V_105 ;
void * V_59 = V_73 -> V_106 ;
unsigned long long V_107 = V_73 -> time ;
const char * V_108 = F_39 ( V_77 -> V_82 ) ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
if ( ! V_26 ) {
snprintf ( V_1 , sizeof( V_1 ) ,
L_20 V_110 , ( V_111 ) V_75 -> V_112 . V_113 ) ;
F_3 ( V_1 ) ;
}
V_104 = F_40 ( V_26 , L_21 , V_59 ) ;
sprintf ( V_1 , L_22 , V_26 -> system , V_26 -> V_34 ) ;
if ( ! F_41 ( V_26 -> V_114 , V_115 ) )
F_21 ( V_26 , V_1 , V_26 -> V_116 . args ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_102 = V_107 / V_117 ;
V_103 = V_107 - V_102 * V_117 ;
V_118 -> V_119 = V_59 ;
V_118 -> V_120 = V_75 -> V_100 -> V_120 ;
V_101 = F_42 ( V_118 , NULL ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_1 ) ) ;
F_16 ( V_15 , V_17 ++ , V_101 ) ;
V_81 = F_29 ( V_73 , V_75 , V_77 ) ;
if ( V_5 ) {
F_16 ( V_15 , V_17 ++ , F_18 ( V_105 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_102 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_103 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_104 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_108 ) ) ;
F_16 ( V_15 , V_17 ++ , V_81 ) ;
} else {
F_4 ( V_2 , L_24 , F_18 ( V_105 ) ) ;
F_4 ( V_2 , L_25 , F_18 ( V_102 ) ) ;
F_4 ( V_2 , L_26 , F_18 ( V_103 ) ) ;
F_4 ( V_2 , L_21 , F_18 ( V_104 ) ) ;
F_4 ( V_2 , L_27 , F_17 ( V_108 ) ) ;
F_4 ( V_2 , L_28 , V_81 ) ;
}
for ( V_20 = V_26 -> V_121 . V_122 ; V_20 ; V_20 = V_20 -> V_22 ) {
unsigned int V_68 , V_123 ;
unsigned long long V_4 ;
if ( V_20 -> V_35 & V_61 ) {
V_68 = V_20 -> V_68 ;
V_123 = V_20 -> V_40 ;
if ( V_20 -> V_35 & V_124 ) {
V_4 = F_43 ( V_118 -> V_120 ,
V_59 + V_68 , V_123 ) ;
V_68 = V_4 ;
V_123 = V_68 >> 16 ;
V_68 &= 0xffff ;
}
if ( V_20 -> V_35 & V_125 &&
F_44 ( V_59 + V_68 , V_123 ) ) {
V_62 = F_17 ( ( char * ) V_59 + V_68 ) ;
} else {
V_62 = F_45 ( ( const char * ) V_59 + V_68 , V_123 ) ;
V_20 -> V_35 &= ~ V_125 ;
}
} else {
V_62 = F_23 ( V_26 , V_20 , V_59 ) ;
}
if ( V_5 )
F_16 ( V_15 , V_17 ++ , V_62 ) ;
else
F_4 ( V_2 , V_20 -> V_34 , V_62 ) ;
}
if ( ! V_5 )
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_46 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
if ( V_5 ) {
F_10 ( V_5 , V_15 , V_1 ) ;
} else {
F_12 ( L_30 , V_15 ) ;
F_6 ( V_2 ) ;
}
F_6 ( V_15 ) ;
}
static T_1 * F_47 ( unsigned int V_126 )
{
T_1 * V_15 ;
V_15 = F_14 ( V_126 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
return V_15 ;
}
static int F_48 ( T_1 * V_15 , unsigned int V_127 , V_111 V_4 )
{
#if V_128 == 64
return F_16 ( V_15 , V_127 , F_18 ( V_4 ) ) ;
#endif
#if V_128 == 32
return F_16 ( V_15 , V_127 , F_26 ( V_4 ) ) ;
#endif
}
static int F_49 ( T_1 * V_15 , unsigned int V_127 , T_2 V_4 )
{
return F_16 ( V_15 , V_127 , F_18 ( V_4 ) ) ;
}
static int F_50 ( T_1 * V_15 , unsigned int V_127 , const char * V_102 )
{
return F_16 ( V_15 , V_127 , F_17 ( V_102 ) ) ;
}
static int F_51 ( struct V_129 * V_130 , struct V_74 * V_75 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 2 ) ;
F_48 ( V_15 , 0 , V_75 -> V_132 ) ;
F_50 ( V_15 , 1 , F_53 ( V_75 ) ) ;
F_10 ( V_131 -> V_133 , V_15 , L_31 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_54 ( struct V_129 * V_130 ,
struct V_134 * V_134 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 3 ) ;
F_48 ( V_15 , 0 , V_134 -> V_132 ) ;
F_49 ( V_15 , 1 , V_134 -> V_104 ) ;
F_50 ( V_15 , 2 , V_134 -> V_135 ? V_134 -> V_135 : L_32 ) ;
F_10 ( V_131 -> V_136 , V_15 , L_33 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_55 ( struct V_129 * V_130 , struct V_82 * V_82 ,
V_111 V_137 , struct V_134 * V_134 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 5 ) ;
F_48 ( V_15 , 0 , V_82 -> V_132 ) ;
F_48 ( V_15 , 1 , V_134 -> V_132 ) ;
F_48 ( V_15 , 2 , V_137 ) ;
F_49 ( V_15 , 3 , V_82 -> V_138 ) ;
F_49 ( V_15 , 4 , V_82 -> V_139 ) ;
F_10 ( V_131 -> V_140 , V_15 , L_34 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_129 * V_130 , struct V_108 * V_108 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 2 ) ;
F_48 ( V_15 , 0 , V_108 -> V_132 ) ;
F_50 ( V_15 , 1 , F_57 ( V_108 ) ) ;
F_10 ( V_131 -> V_141 , V_15 , L_35 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_58 ( struct V_129 * V_130 , V_111 V_132 ,
struct V_108 * V_108 , struct V_82 * V_82 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 3 ) ;
F_48 ( V_15 , 0 , V_132 ) ;
F_48 ( V_15 , 1 , V_108 -> V_132 ) ;
F_48 ( V_15 , 2 , V_82 -> V_132 ) ;
F_10 ( V_131 -> V_142 , V_15 , L_36 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_59 ( struct V_129 * V_130 , struct V_97 * V_97 ,
struct V_134 * V_134 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
char V_143 [ V_144 ] ;
T_1 * V_15 ;
F_60 ( V_97 -> V_145 , sizeof( V_97 -> V_145 ) , V_143 ) ;
V_15 = F_47 ( 5 ) ;
F_48 ( V_15 , 0 , V_97 -> V_132 ) ;
F_48 ( V_15 , 1 , V_134 -> V_132 ) ;
F_50 ( V_15 , 2 , V_97 -> V_146 ) ;
F_50 ( V_15 , 3 , V_97 -> V_98 ) ;
F_50 ( V_15 , 4 , V_143 ) ;
F_10 ( V_131 -> V_147 , V_15 , L_37 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_129 * V_130 , struct V_36 * V_89 ,
struct V_97 * V_97 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
V_111 * V_148 = F_62 ( V_89 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 6 ) ;
F_48 ( V_15 , 0 , * V_148 ) ;
F_48 ( V_15 , 1 , V_97 -> V_132 ) ;
F_48 ( V_15 , 2 , V_89 -> V_91 ) ;
F_48 ( V_15 , 3 , V_89 -> V_92 ) ;
F_49 ( V_15 , 4 , V_89 -> V_93 ) ;
F_50 ( V_15 , 5 , V_89 -> V_34 ) ;
F_10 ( V_131 -> V_149 , V_15 , L_38 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_63 ( struct V_129 * V_130 , T_3 V_150 ,
const char * V_34 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 2 ) ;
F_49 ( V_15 , 0 , V_150 ) ;
F_50 ( V_15 , 1 , V_34 ) ;
F_10 ( V_131 -> V_151 , V_15 , L_39 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_64 ( struct V_129 * V_130 ,
struct V_152 * V_153 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 22 ) ;
F_48 ( V_15 , 0 , V_153 -> V_132 ) ;
F_48 ( V_15 , 1 , V_153 -> V_75 -> V_132 ) ;
F_48 ( V_15 , 2 , V_153 -> V_77 -> V_134 -> V_132 ) ;
F_48 ( V_15 , 3 , V_153 -> V_77 -> V_82 -> V_132 ) ;
F_48 ( V_15 , 4 , V_153 -> V_154 ) ;
F_48 ( V_15 , 5 , V_153 -> V_155 ) ;
F_48 ( V_15 , 6 , V_153 -> V_148 ) ;
F_48 ( V_15 , 7 , V_153 -> V_68 ) ;
F_48 ( V_15 , 8 , V_153 -> V_73 -> V_88 ) ;
F_48 ( V_15 , 9 , V_153 -> V_73 -> time ) ;
F_49 ( V_15 , 10 , V_153 -> V_73 -> V_105 ) ;
F_48 ( V_15 , 11 , V_153 -> V_156 ) ;
F_48 ( V_15 , 12 , V_153 -> V_157 ) ;
F_48 ( V_15 , 13 , V_153 -> V_158 ) ;
F_48 ( V_15 , 14 , V_153 -> V_73 -> V_159 ) ;
F_48 ( V_15 , 15 , V_153 -> V_73 -> V_160 ) ;
F_48 ( V_15 , 16 , V_153 -> V_73 -> V_161 ) ;
F_48 ( V_15 , 17 , V_153 -> V_73 -> V_162 ) ;
F_48 ( V_15 , 18 , V_153 -> V_73 -> V_163 ) ;
F_49 ( V_15 , 19 , V_153 -> V_73 -> V_35 & V_164 ) ;
F_49 ( V_15 , 20 , ! ! ( V_153 -> V_73 -> V_35 & V_165 ) ) ;
F_48 ( V_15 , 21 , V_153 -> V_166 ) ;
F_10 ( V_131 -> V_167 , V_15 , L_40 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_129 * V_130 , struct V_168 * V_169 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
T_1 * V_15 ;
V_111 V_170 , V_148 ;
V_170 = V_169 -> V_171 ? V_169 -> V_171 -> V_132 : 0 ;
V_148 = V_169 -> V_89 ? * ( V_111 * ) F_62 ( V_169 -> V_89 ) : 0 ;
V_15 = F_47 ( 4 ) ;
F_48 ( V_15 , 0 , V_169 -> V_132 ) ;
F_48 ( V_15 , 1 , V_170 ) ;
F_48 ( V_15 , 2 , V_148 ) ;
F_48 ( V_15 , 3 , V_169 -> V_88 ) ;
F_10 ( V_131 -> V_172 , V_15 , L_41 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_66 ( struct V_129 * V_130 ,
struct V_173 * V_174 )
{
struct V_131 * V_131 = F_52 ( V_130 , struct V_131 , V_130 ) ;
V_111 V_154 = V_174 -> V_108 ? V_174 -> V_108 -> V_132 : 0 ;
T_1 * V_15 ;
V_15 = F_47 ( 11 ) ;
F_48 ( V_15 , 0 , V_174 -> V_132 ) ;
F_48 ( V_15 , 1 , V_174 -> V_82 -> V_132 ) ;
F_48 ( V_15 , 2 , V_154 ) ;
F_48 ( V_15 , 3 , V_174 -> V_169 -> V_132 ) ;
F_48 ( V_15 , 4 , V_174 -> V_175 ) ;
F_48 ( V_15 , 5 , V_174 -> V_176 ) ;
F_48 ( V_15 , 6 , V_174 -> V_177 ) ;
F_48 ( V_15 , 7 , V_174 -> V_178 ) ;
F_48 ( V_15 , 8 , V_174 -> V_179 ) ;
F_48 ( V_15 , 9 , V_174 -> V_169 -> V_171 -> V_132 ) ;
F_49 ( V_15 , 10 , V_174 -> V_35 ) ;
F_10 ( V_131 -> V_180 , V_15 , L_42 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_67 ( struct V_173 * V_174 , void * V_59 )
{
struct V_129 * V_130 = V_59 ;
return F_68 ( V_130 , V_174 ) ;
}
static void F_69 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
T_1 * V_5 , * V_15 , * V_2 , * V_81 , * V_181 ;
static char V_1 [ 64 ] ;
unsigned V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_11 ) ;
V_181 = F_34 () ;
if ( ! V_181 )
F_3 ( L_11 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_43 , L_44 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
goto exit;
F_4 ( V_2 , L_45 , F_17 ( F_53 ( V_75 ) ) ) ;
F_4 ( V_2 , L_46 , F_35 (
( const char * ) & V_75 -> V_112 , sizeof( V_75 -> V_112 ) ) ) ;
F_4 ( V_181 , L_47 ,
F_18 ( V_73 -> V_104 ) ) ;
F_4 ( V_181 , L_48 ,
F_18 ( V_73 -> V_139 ) ) ;
F_4 ( V_181 , L_49 ,
F_18 ( V_73 -> V_105 ) ) ;
F_4 ( V_181 , L_12 ,
F_27 ( V_73 -> V_88 ) ) ;
F_4 ( V_181 , L_50 ,
F_27 ( V_73 -> time ) ) ;
F_4 ( V_181 , L_51 ,
F_27 ( V_73 -> V_160 ) ) ;
F_4 ( V_2 , L_52 , V_181 ) ;
F_4 ( V_2 , L_53 , F_35 (
( const char * ) V_73 -> V_106 , V_73 -> V_182 ) ) ;
F_4 ( V_2 , L_54 ,
F_17 ( F_39 ( V_77 -> V_82 ) ) ) ;
if ( V_77 -> V_95 ) {
F_4 ( V_2 , L_19 ,
F_17 ( V_77 -> V_95 -> V_97 -> V_34 ) ) ;
}
if ( V_77 -> V_89 ) {
F_4 ( V_2 , L_55 ,
F_17 ( V_77 -> V_89 -> V_34 ) ) ;
}
V_81 = F_29 ( V_73 , V_75 , V_77 ) ;
F_4 ( V_2 , L_56 , V_81 ) ;
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_46 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_15 ) ;
}
static void F_70 ( union V_183 * V_26 ,
struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_76 * V_77 )
{
struct V_131 * V_131 = & V_184 ;
switch ( V_75 -> V_112 . type ) {
case V_185 :
F_38 ( V_73 , V_75 , V_77 ) ;
break;
default:
if ( V_131 -> V_186 )
F_71 ( & V_131 -> V_130 , V_26 , V_73 , V_75 , V_77 ) ;
else
F_69 ( V_73 , V_75 , V_77 ) ;
}
}
static void F_72 ( char * V_21 , T_4 V_40 ,
struct V_74 * V_75 )
{
char * V_187 = V_21 ;
F_73 ( V_21 , V_40 , L_57 , F_53 ( V_75 ) ) ;
while ( ( V_187 = strchr ( V_187 , ':' ) ) ) {
* V_187 = '_' ;
V_187 ++ ;
}
}
static void
F_74 ( struct V_74 * V_188 , int V_105 , int V_82 , V_111 V_189 ,
struct V_190 * V_43 )
{
T_1 * V_5 , * V_15 ;
static char V_1 [ 256 ] ;
int V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
F_72 ( V_1 , sizeof( V_1 ) ,
V_188 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_75 ( L_58 , V_1 ) ;
return;
}
F_16 ( V_15 , V_17 ++ , F_18 ( V_105 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_82 ) ) ;
F_48 ( V_15 , V_17 ++ , V_189 ) ;
F_48 ( V_15 , V_17 ++ , V_43 -> V_4 ) ;
F_48 ( V_15 , V_17 ++ , V_43 -> V_191 ) ;
F_48 ( V_15 , V_17 ++ , V_43 -> V_192 ) ;
if ( F_46 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
F_6 ( V_15 ) ;
}
static void F_76 ( struct V_193 * V_113 ,
struct V_74 * V_188 , V_111 V_189 )
{
struct V_194 * V_195 = V_188 -> V_195 ;
struct V_196 * V_197 = V_188 -> V_197 ;
int V_105 , V_82 ;
if ( V_113 -> V_198 == V_199 ) {
F_74 ( V_188 , - 1 , - 1 , V_189 ,
& V_188 -> V_200 -> V_201 ) ;
return;
}
for ( V_82 = 0 ; V_82 < V_195 -> V_202 ; V_82 ++ ) {
for ( V_105 = 0 ; V_105 < V_197 -> V_202 ; V_105 ++ ) {
F_74 ( V_188 , V_197 -> V_95 [ V_105 ] ,
F_77 ( V_195 , V_82 ) , V_189 ,
F_78 ( V_188 -> V_200 , V_105 , V_82 ) ) ;
}
}
}
static void F_79 ( V_111 V_189 )
{
T_1 * V_5 , * V_15 ;
static const char V_1 [] = L_59 ;
int V_17 = 0 ;
V_15 = F_14 ( V_109 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_75 ( L_58 , V_1 ) ;
return;
}
F_48 ( V_15 , V_17 ++ , V_189 ) ;
if ( F_46 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
F_6 ( V_15 ) ;
}
static int F_80 ( void )
{
V_203 = F_81 ( L_60 ) ;
if ( V_203 == NULL )
return - 1 ;
F_82 ( V_203 ) ;
V_6 = F_83 ( V_203 ) ;
if ( V_6 == NULL )
goto error;
F_82 ( V_6 ) ;
F_12 ( L_61 , NULL ) ;
return 0 ;
error:
F_84 ( V_6 ) ;
F_84 ( V_203 ) ;
return - 1 ;
}
static void F_85 ( struct V_131 * V_131 )
{
const char * V_204 = L_62 ;
const char * V_205 = L_63 ;
const char * V_206 = L_64 ;
T_1 * V_186 , * V_207 , * V_208 ;
bool V_209 = false ;
bool V_210 = false ;
int V_211 ;
memset ( V_131 , 0 , sizeof( struct V_131 ) ) ;
if ( F_86 ( & V_131 -> V_130 ) )
F_3 ( L_65 ) ;
V_186 = F_8 ( V_6 , V_204 ) ;
if ( ! V_186 )
return;
V_211 = F_87 ( V_186 ) ;
if ( V_211 == - 1 )
F_1 ( V_204 ) ;
if ( ! V_211 )
return;
V_131 -> V_130 . V_212 = NULL ;
V_207 = F_8 ( V_6 , V_205 ) ;
if ( V_207 ) {
V_211 = F_87 ( V_207 ) ;
if ( V_211 == - 1 )
F_1 ( V_205 ) ;
V_209 = ! ! V_211 ;
}
if ( V_209 ) {
V_131 -> V_130 . V_212 =
F_88 ( F_67 ,
& V_131 -> V_130 ) ;
if ( ! V_131 -> V_130 . V_212 )
F_3 ( L_66 ) ;
}
V_131 -> V_130 . V_213 = NULL ;
V_208 = F_8 ( V_6 ,
V_206 ) ;
if ( V_208 ) {
V_211 = F_87 ( V_208 ) ;
if ( V_211 == - 1 )
F_1 ( V_206 ) ;
V_210 = ! ! V_211 ;
}
if ( V_210 ) {
if ( V_131 -> V_130 . V_212 )
V_131 -> V_130 . V_213 = V_131 -> V_130 . V_212 -> V_213 ;
else
V_131 -> V_130 . V_213 = F_89 () ;
if ( ! V_131 -> V_130 . V_213 )
F_3 ( L_67 ) ;
}
V_131 -> V_186 = true ;
V_79 . V_214 = sizeof( V_111 ) ;
F_90 ( V_75 ) ;
F_90 ( V_134 ) ;
F_90 ( V_82 ) ;
F_90 ( V_108 ) ;
F_90 ( V_215 ) ;
F_90 ( V_97 ) ;
F_90 ( V_36 ) ;
F_90 ( V_150 ) ;
F_90 ( V_73 ) ;
F_90 ( V_168 ) ;
F_90 ( V_173 ) ;
}
static int F_91 ( const char * V_216 , int V_217 , const char * * V_218 )
{
struct V_131 * V_131 = & V_184 ;
const char * * V_219 ;
char V_220 [ V_221 ] ;
int V_66 , V_222 = 0 ;
T_5 * V_223 ;
V_219 = malloc ( ( V_217 + 1 ) * sizeof( const char * ) ) ;
V_219 [ 0 ] = V_216 ;
for ( V_66 = 1 ; V_66 < V_217 + 1 ; V_66 ++ )
V_219 [ V_66 ] = V_218 [ V_66 - 1 ] ;
F_92 () ;
F_93 () ;
F_94 ( V_217 + 1 , ( char * * ) V_219 ) ;
V_223 = fopen ( V_216 , L_68 ) ;
if ( ! V_223 ) {
sprintf ( V_220 , L_69 , V_216 ) ;
perror ( V_220 ) ;
V_222 = - 1 ;
goto error;
}
V_222 = F_95 ( V_223 , V_216 ) ;
if ( V_222 ) {
fprintf ( V_224 , L_70 , V_216 ) ;
goto error;
}
V_222 = F_80 () ;
if ( V_222 ) {
fprintf ( V_224 , L_71 , V_216 ) ;
goto error;
}
F_85 ( V_131 ) ;
if ( V_131 -> V_186 ) {
V_222 = F_96 ( & V_131 -> V_130 ) ;
if ( V_222 )
goto error;
}
free ( V_219 ) ;
return V_222 ;
error:
F_97 () ;
free ( V_219 ) ;
return V_222 ;
}
static int F_98 ( void )
{
struct V_131 * V_131 = & V_184 ;
return F_99 ( & V_131 -> V_130 ) ;
}
static int F_100 ( void )
{
struct V_131 * V_131 = & V_184 ;
F_12 ( L_72 , NULL ) ;
F_101 ( & V_131 -> V_130 ) ;
F_84 ( V_6 ) ;
F_84 ( V_203 ) ;
F_97 () ;
return 0 ;
}
static int F_102 ( struct V_120 * V_120 , const char * V_225 )
{
struct V_25 * V_26 = NULL ;
struct V_58 * V_226 ;
char V_227 [ V_221 ] ;
int V_228 , V_43 ;
T_5 * V_229 ;
sprintf ( V_227 , L_73 , V_225 ) ;
V_229 = fopen ( V_227 , L_74 ) ;
if ( V_229 == NULL ) {
fprintf ( V_224 , L_75 , V_227 ) ;
return - 1 ;
}
fprintf ( V_229 , L_76
L_77 ) ;
fprintf ( V_229 , L_78
L_79 ) ;
fprintf ( V_229 , L_80
L_81 ) ;
fprintf ( V_229 , L_82
L_83 ) ;
fprintf ( V_229 , L_84
L_85 ) ;
fprintf ( V_229 , L_86
L_87 ) ;
fprintf ( V_229 , L_88
L_89 ) ;
fprintf ( V_229 , L_90 ) ;
fprintf ( V_229 , L_91 ) ;
fprintf ( V_229 , L_92 ) ;
fprintf ( V_229 , L_93 ) ;
fprintf ( V_229 , L_94 ) ;
fprintf ( V_229 , L_95 ) ;
fprintf ( V_229 , L_96 ) ;
fprintf ( V_229 , L_97 ) ;
fprintf ( V_229 , L_98 ) ;
fprintf ( V_229 , L_99 ) ;
while ( ( V_26 = F_103 ( V_120 , V_26 ) ) ) {
fprintf ( V_229 , L_100 , V_26 -> system , V_26 -> V_34 ) ;
fprintf ( V_229 , L_101 ) ;
fprintf ( V_229 , L_102 ) ;
fprintf ( V_229 , L_103 ) ;
fprintf ( V_229 , L_104 ) ;
fprintf ( V_229 , L_105 ) ;
fprintf ( V_229 , L_106 ) ;
fprintf ( V_229 , L_107 ) ;
fprintf ( V_229 , L_108 ) ;
V_228 = 0 ;
V_43 = 0 ;
for ( V_226 = V_26 -> V_121 . V_122 ; V_226 ; V_226 = V_226 -> V_22 ) {
if ( V_228 ++ )
fprintf ( V_229 , L_109 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_229 , L_110 ) ;
fprintf ( V_229 , L_43 , V_226 -> V_34 ) ;
}
fprintf ( V_229 , L_111 ) ;
fprintf ( V_229 , L_112
L_113
L_114 ) ;
fprintf ( V_229 , L_115 ) ;
V_228 = 0 ;
V_43 = 0 ;
for ( V_226 = V_26 -> V_121 . V_122 ; V_226 ; V_226 = V_226 -> V_22 ) {
if ( V_228 ++ )
fprintf ( V_229 , L_109 ) ;
if ( V_43 && V_43 % 3 == 0 ) {
fprintf ( V_229 , L_116 ) ;
}
V_43 ++ ;
fprintf ( V_229 , L_117 , V_226 -> V_34 ) ;
if ( V_226 -> V_35 & V_125 ||
V_226 -> V_35 & V_230 ||
V_226 -> V_35 & V_61 ||
V_226 -> V_35 & V_231 )
fprintf ( V_229 , L_118 ) ;
else if ( V_226 -> V_35 & V_69 )
fprintf ( V_229 , L_119 ) ;
else
fprintf ( V_229 , L_120 ) ;
}
fprintf ( V_229 , L_121 ) ;
V_228 = 0 ;
V_43 = 0 ;
for ( V_226 = V_26 -> V_121 . V_122 ; V_226 ; V_226 = V_226 -> V_22 ) {
if ( V_228 ++ )
fprintf ( V_229 , L_109 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_229 , L_122 ) ;
if ( V_226 -> V_35 & V_230 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_229 , L_122 ) ;
V_43 = 4 ;
}
fprintf ( V_229 , L_123 ) ;
fprintf ( V_229 , L_124 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_229 , L_125 , V_226 -> V_34 ,
V_226 -> V_34 ) ;
} else if ( V_226 -> V_35 & V_231 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_229 , L_122 ) ;
V_43 = 4 ;
}
fprintf ( V_229 , L_126 ) ;
fprintf ( V_229 , L_124 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_229 , L_125 , V_226 -> V_34 ,
V_226 -> V_34 ) ;
} else
fprintf ( V_229 , L_43 , V_226 -> V_34 ) ;
}
fprintf ( V_229 , L_127 ) ;
fprintf ( V_229 , L_128 ) ;
fprintf ( V_229 , L_129 ) ;
fprintf ( V_229 , L_130 ) ;
fprintf ( V_229 , L_131 ) ;
fprintf ( V_229 , L_132 ) ;
fprintf ( V_229 , L_133 ) ;
}
fprintf ( V_229 , L_134
L_135 ) ;
fprintf ( V_229 , L_136
L_137 ) ;
fprintf ( V_229 , L_138
L_139
L_140
L_141 ) ;
fclose ( V_229 ) ;
fprintf ( V_224 , L_142 , V_227 ) ;
return 0 ;
}
