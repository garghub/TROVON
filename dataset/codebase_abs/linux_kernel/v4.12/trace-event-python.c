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
case V_39 :
F_21 ( V_26 , V_11 , args -> V_40 . V_20 ) ;
F_21 ( V_26 , V_11 , args -> V_40 . V_41 ) ;
break;
case V_42 :
F_21 ( V_26 , V_11 , args -> V_43 . V_20 ) ;
F_21 ( V_26 , V_11 , args -> V_43 . V_44 ) ;
F_21 ( V_26 , V_11 , args -> V_43 . V_45 ) ;
break;
case V_46 :
break;
case V_47 :
F_21 ( V_26 , V_11 , args -> V_48 . V_49 ) ;
break;
case V_50 :
if ( strcmp ( args -> V_51 . V_51 , L_8 ) == 0 )
V_32 = 1 ;
F_21 ( V_26 , V_11 , args -> V_51 . V_52 ) ;
F_21 ( V_26 , V_11 , args -> V_51 . V_53 ) ;
break;
default:
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return;
}
if ( args -> V_22 )
F_21 ( V_26 , V_11 , args -> V_22 ) ;
}
static T_1 * F_23 ( struct V_25 * V_26 ,
struct V_59 * V_20 , void * V_60 )
{
bool V_61 = V_20 -> V_35 & V_62 ;
T_1 * V_63 = NULL , * V_64 = NULL ;
unsigned long long V_4 ;
unsigned int V_65 , V_66 , V_67 ;
if ( V_61 ) {
V_64 = F_24 ( V_20 -> V_68 ) ;
V_65 = V_20 -> V_41 / V_20 -> V_68 ;
V_66 = V_20 -> V_68 ;
} else {
V_65 = V_20 -> V_41 ;
V_66 = 1 ;
}
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
V_4 = F_25 ( V_26 , V_60 + V_20 -> V_69 + V_67 * V_65 ,
V_65 ) ;
if ( V_20 -> V_35 & V_70 ) {
if ( ( long long ) V_4 >= V_71 &&
( long long ) V_4 <= V_72 )
V_63 = F_18 ( V_4 ) ;
else
V_63 = F_26 ( V_4 ) ;
} else {
if ( V_4 <= V_72 )
V_63 = F_18 ( V_4 ) ;
else
V_63 = F_27 ( V_4 ) ;
}
if ( V_61 )
F_28 ( V_64 , V_67 , V_63 ) ;
}
if ( V_61 )
V_63 = V_64 ;
return V_63 ;
}
static T_1 * F_29 ( struct V_73 * V_74 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
T_1 * V_79 ;
V_79 = F_24 ( 0 ) ;
if ( ! V_79 )
F_3 ( L_9 ) ;
if ( ! V_80 . V_81 || ! V_74 -> V_82 )
goto exit;
if ( F_30 ( V_78 -> V_83 , & V_84 , V_76 ,
V_74 , NULL , NULL ,
V_85 ) != 0 ) {
F_31 ( L_10 ) ;
goto exit;
}
F_32 ( & V_84 ) ;
while ( 1 ) {
T_1 * V_86 ;
struct V_87 * V_88 ;
V_88 = F_33 ( & V_84 ) ;
if ( ! V_88 )
break;
V_86 = F_34 () ;
if ( ! V_86 )
F_3 ( L_11 ) ;
F_4 ( V_86 , L_12 ,
F_27 ( V_88 -> V_89 ) ) ;
if ( V_88 -> V_90 ) {
T_1 * V_91 = F_34 () ;
if ( ! V_91 )
F_3 ( L_11 ) ;
F_4 ( V_91 , L_13 ,
F_27 ( V_88 -> V_90 -> V_92 ) ) ;
F_4 ( V_91 , L_14 ,
F_27 ( V_88 -> V_90 -> V_93 ) ) ;
F_4 ( V_91 , L_15 ,
F_18 ( V_88 -> V_90 -> V_94 ) ) ;
F_4 ( V_91 , L_16 ,
F_35 ( V_88 -> V_90 -> V_34 ,
V_88 -> V_90 -> V_95 ) ) ;
F_4 ( V_86 , L_17 , V_91 ) ;
}
if ( V_88 -> V_96 ) {
struct V_96 * V_96 = V_88 -> V_96 ;
const char * V_97 = L_18 ;
if ( V_96 && V_96 -> V_98 ) {
if ( V_80 . V_99 && V_96 -> V_98 -> V_100 )
V_97 = V_96 -> V_98 -> V_100 ;
else
V_97 = V_96 -> V_98 -> V_34 ;
}
F_4 ( V_86 , L_19 ,
F_17 ( V_97 ) ) ;
}
F_36 ( & V_84 ) ;
F_37 ( V_79 , V_86 ) ;
F_6 ( V_86 ) ;
}
exit:
return V_79 ;
}
static void F_38 ( struct V_73 * V_74 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_25 * V_26 = V_76 -> V_101 ;
T_1 * V_5 , * V_102 , * V_15 , * V_63 = NULL , * V_82 ;
T_1 * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_59 * V_20 ;
unsigned long V_103 , V_104 ;
unsigned V_17 = 0 ;
int V_105 ;
int V_106 = V_74 -> V_106 ;
void * V_60 = V_74 -> V_107 ;
unsigned long long V_108 = V_74 -> time ;
const char * V_109 = F_39 ( V_78 -> V_83 ) ;
V_15 = F_14 ( V_110 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
if ( ! V_26 ) {
snprintf ( V_1 , sizeof( V_1 ) ,
L_20 V_111 , ( V_112 ) V_76 -> V_113 . V_114 ) ;
F_3 ( V_1 ) ;
}
V_105 = F_40 ( V_26 , L_21 , V_60 ) ;
sprintf ( V_1 , L_22 , V_26 -> system , V_26 -> V_34 ) ;
if ( ! F_41 ( V_26 -> V_115 , V_116 ) )
F_21 ( V_26 , V_1 , V_26 -> V_117 . args ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_103 = V_108 / V_118 ;
V_104 = V_108 - V_103 * V_118 ;
V_119 -> V_120 = V_60 ;
V_119 -> V_121 = V_76 -> V_101 -> V_121 ;
V_102 = F_42 ( V_119 , NULL ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_1 ) ) ;
F_16 ( V_15 , V_17 ++ , V_102 ) ;
V_82 = F_29 ( V_74 , V_76 , V_78 ) ;
if ( V_5 ) {
F_16 ( V_15 , V_17 ++ , F_18 ( V_106 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_103 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_104 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_105 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_109 ) ) ;
F_16 ( V_15 , V_17 ++ , V_82 ) ;
} else {
F_4 ( V_2 , L_24 , F_18 ( V_106 ) ) ;
F_4 ( V_2 , L_25 , F_18 ( V_103 ) ) ;
F_4 ( V_2 , L_26 , F_18 ( V_104 ) ) ;
F_4 ( V_2 , L_21 , F_18 ( V_105 ) ) ;
F_4 ( V_2 , L_27 , F_17 ( V_109 ) ) ;
F_4 ( V_2 , L_28 , V_82 ) ;
}
for ( V_20 = V_26 -> V_122 . V_123 ; V_20 ; V_20 = V_20 -> V_22 ) {
unsigned int V_69 , V_124 ;
unsigned long long V_4 ;
if ( V_20 -> V_35 & V_62 ) {
V_69 = V_20 -> V_69 ;
V_124 = V_20 -> V_41 ;
if ( V_20 -> V_35 & V_125 ) {
V_4 = F_43 ( V_119 -> V_121 ,
V_60 + V_69 , V_124 ) ;
V_69 = V_4 ;
V_124 = V_69 >> 16 ;
V_69 &= 0xffff ;
}
if ( V_20 -> V_35 & V_126 &&
F_44 ( V_60 + V_69 , V_124 ) ) {
V_63 = F_17 ( ( char * ) V_60 + V_69 ) ;
} else {
V_63 = F_45 ( ( const char * ) V_60 + V_69 , V_124 ) ;
V_20 -> V_35 &= ~ V_126 ;
}
} else {
V_63 = F_23 ( V_26 , V_20 , V_60 ) ;
}
if ( V_5 )
F_16 ( V_15 , V_17 ++ , V_63 ) ;
else
F_4 ( V_2 , V_20 -> V_34 , V_63 ) ;
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
static T_1 * F_47 ( unsigned int V_127 )
{
T_1 * V_15 ;
V_15 = F_14 ( V_127 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
return V_15 ;
}
static int F_48 ( T_1 * V_15 , unsigned int V_128 , V_112 V_4 )
{
#if V_129 == 64
return F_16 ( V_15 , V_128 , F_18 ( V_4 ) ) ;
#endif
#if V_129 == 32
return F_16 ( V_15 , V_128 , F_26 ( V_4 ) ) ;
#endif
}
static int F_49 ( T_1 * V_15 , unsigned int V_128 , T_2 V_4 )
{
return F_16 ( V_15 , V_128 , F_18 ( V_4 ) ) ;
}
static int F_50 ( T_1 * V_15 , unsigned int V_128 , const char * V_103 )
{
return F_16 ( V_15 , V_128 , F_17 ( V_103 ) ) ;
}
static int F_51 ( struct V_130 * V_131 , struct V_75 * V_76 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 2 ) ;
F_48 ( V_15 , 0 , V_76 -> V_133 ) ;
F_50 ( V_15 , 1 , F_53 ( V_76 ) ) ;
F_10 ( V_132 -> V_134 , V_15 , L_31 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_54 ( struct V_130 * V_131 ,
struct V_135 * V_135 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 3 ) ;
F_48 ( V_15 , 0 , V_135 -> V_133 ) ;
F_49 ( V_15 , 1 , V_135 -> V_105 ) ;
F_50 ( V_15 , 2 , V_135 -> V_136 ? V_135 -> V_136 : L_32 ) ;
F_10 ( V_132 -> V_137 , V_15 , L_33 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_55 ( struct V_130 * V_131 , struct V_83 * V_83 ,
V_112 V_138 , struct V_135 * V_135 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 5 ) ;
F_48 ( V_15 , 0 , V_83 -> V_133 ) ;
F_48 ( V_15 , 1 , V_135 -> V_133 ) ;
F_48 ( V_15 , 2 , V_138 ) ;
F_49 ( V_15 , 3 , V_83 -> V_139 ) ;
F_49 ( V_15 , 4 , V_83 -> V_140 ) ;
F_10 ( V_132 -> V_141 , V_15 , L_34 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_130 * V_131 , struct V_109 * V_109 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 2 ) ;
F_48 ( V_15 , 0 , V_109 -> V_133 ) ;
F_50 ( V_15 , 1 , F_57 ( V_109 ) ) ;
F_10 ( V_132 -> V_142 , V_15 , L_35 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_58 ( struct V_130 * V_131 , V_112 V_133 ,
struct V_109 * V_109 , struct V_83 * V_83 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 3 ) ;
F_48 ( V_15 , 0 , V_133 ) ;
F_48 ( V_15 , 1 , V_109 -> V_133 ) ;
F_48 ( V_15 , 2 , V_83 -> V_133 ) ;
F_10 ( V_132 -> V_143 , V_15 , L_36 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_59 ( struct V_130 * V_131 , struct V_98 * V_98 ,
struct V_135 * V_135 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
char V_144 [ V_145 ] ;
T_1 * V_15 ;
F_60 ( V_98 -> V_146 , sizeof( V_98 -> V_146 ) , V_144 ) ;
V_15 = F_47 ( 5 ) ;
F_48 ( V_15 , 0 , V_98 -> V_133 ) ;
F_48 ( V_15 , 1 , V_135 -> V_133 ) ;
F_50 ( V_15 , 2 , V_98 -> V_147 ) ;
F_50 ( V_15 , 3 , V_98 -> V_100 ) ;
F_50 ( V_15 , 4 , V_144 ) ;
F_10 ( V_132 -> V_148 , V_15 , L_37 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_130 * V_131 , struct V_36 * V_90 ,
struct V_98 * V_98 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
V_112 * V_149 = F_62 ( V_90 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 6 ) ;
F_48 ( V_15 , 0 , * V_149 ) ;
F_48 ( V_15 , 1 , V_98 -> V_133 ) ;
F_48 ( V_15 , 2 , V_90 -> V_92 ) ;
F_48 ( V_15 , 3 , V_90 -> V_93 ) ;
F_49 ( V_15 , 4 , V_90 -> V_94 ) ;
F_50 ( V_15 , 5 , V_90 -> V_34 ) ;
F_10 ( V_132 -> V_150 , V_15 , L_38 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_63 ( struct V_130 * V_131 , T_3 V_151 ,
const char * V_34 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 2 ) ;
F_49 ( V_15 , 0 , V_151 ) ;
F_50 ( V_15 , 1 , V_34 ) ;
F_10 ( V_132 -> V_152 , V_15 , L_39 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_64 ( struct V_130 * V_131 ,
struct V_153 * V_154 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_15 = F_47 ( 22 ) ;
F_48 ( V_15 , 0 , V_154 -> V_133 ) ;
F_48 ( V_15 , 1 , V_154 -> V_76 -> V_133 ) ;
F_48 ( V_15 , 2 , V_154 -> V_78 -> V_135 -> V_133 ) ;
F_48 ( V_15 , 3 , V_154 -> V_78 -> V_83 -> V_133 ) ;
F_48 ( V_15 , 4 , V_154 -> V_155 ) ;
F_48 ( V_15 , 5 , V_154 -> V_156 ) ;
F_48 ( V_15 , 6 , V_154 -> V_149 ) ;
F_48 ( V_15 , 7 , V_154 -> V_69 ) ;
F_48 ( V_15 , 8 , V_154 -> V_74 -> V_89 ) ;
F_48 ( V_15 , 9 , V_154 -> V_74 -> time ) ;
F_49 ( V_15 , 10 , V_154 -> V_74 -> V_106 ) ;
F_48 ( V_15 , 11 , V_154 -> V_157 ) ;
F_48 ( V_15 , 12 , V_154 -> V_158 ) ;
F_48 ( V_15 , 13 , V_154 -> V_159 ) ;
F_48 ( V_15 , 14 , V_154 -> V_74 -> V_160 ) ;
F_48 ( V_15 , 15 , V_154 -> V_74 -> V_161 ) ;
F_48 ( V_15 , 16 , V_154 -> V_74 -> V_162 ) ;
F_48 ( V_15 , 17 , V_154 -> V_74 -> V_163 ) ;
F_48 ( V_15 , 18 , V_154 -> V_74 -> V_164 ) ;
F_49 ( V_15 , 19 , V_154 -> V_74 -> V_35 & V_165 ) ;
F_49 ( V_15 , 20 , ! ! ( V_154 -> V_74 -> V_35 & V_166 ) ) ;
F_48 ( V_15 , 21 , V_154 -> V_167 ) ;
F_10 ( V_132 -> V_168 , V_15 , L_40 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_130 * V_131 , struct V_169 * V_170 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
T_1 * V_15 ;
V_112 V_171 , V_149 ;
V_171 = V_170 -> V_172 ? V_170 -> V_172 -> V_133 : 0 ;
V_149 = V_170 -> V_90 ? * ( V_112 * ) F_62 ( V_170 -> V_90 ) : 0 ;
V_15 = F_47 ( 4 ) ;
F_48 ( V_15 , 0 , V_170 -> V_133 ) ;
F_48 ( V_15 , 1 , V_171 ) ;
F_48 ( V_15 , 2 , V_149 ) ;
F_48 ( V_15 , 3 , V_170 -> V_89 ) ;
F_10 ( V_132 -> V_173 , V_15 , L_41 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_66 ( struct V_130 * V_131 ,
struct V_174 * V_175 )
{
struct V_132 * V_132 = F_52 ( V_131 , struct V_132 , V_131 ) ;
V_112 V_155 = V_175 -> V_109 ? V_175 -> V_109 -> V_133 : 0 ;
T_1 * V_15 ;
V_15 = F_47 ( 11 ) ;
F_48 ( V_15 , 0 , V_175 -> V_133 ) ;
F_48 ( V_15 , 1 , V_175 -> V_83 -> V_133 ) ;
F_48 ( V_15 , 2 , V_155 ) ;
F_48 ( V_15 , 3 , V_175 -> V_170 -> V_133 ) ;
F_48 ( V_15 , 4 , V_175 -> V_176 ) ;
F_48 ( V_15 , 5 , V_175 -> V_177 ) ;
F_48 ( V_15 , 6 , V_175 -> V_178 ) ;
F_48 ( V_15 , 7 , V_175 -> V_179 ) ;
F_48 ( V_15 , 8 , V_175 -> V_180 ) ;
F_48 ( V_15 , 9 , V_175 -> V_170 -> V_172 -> V_133 ) ;
F_49 ( V_15 , 10 , V_175 -> V_35 ) ;
F_10 ( V_132 -> V_181 , V_15 , L_42 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_67 ( struct V_174 * V_175 , void * V_60 )
{
struct V_130 * V_131 = V_60 ;
return F_68 ( V_131 , V_175 ) ;
}
static void F_69 ( struct V_73 * V_74 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
T_1 * V_5 , * V_15 , * V_2 , * V_82 , * V_182 ;
static char V_1 [ 64 ] ;
unsigned V_17 = 0 ;
V_15 = F_14 ( V_110 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_11 ) ;
V_182 = F_34 () ;
if ( ! V_182 )
F_3 ( L_11 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_43 , L_44 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
goto exit;
F_4 ( V_2 , L_45 , F_17 ( F_53 ( V_76 ) ) ) ;
F_4 ( V_2 , L_46 , F_35 (
( const char * ) & V_76 -> V_113 , sizeof( V_76 -> V_113 ) ) ) ;
F_4 ( V_182 , L_47 ,
F_18 ( V_74 -> V_105 ) ) ;
F_4 ( V_182 , L_48 ,
F_18 ( V_74 -> V_140 ) ) ;
F_4 ( V_182 , L_49 ,
F_18 ( V_74 -> V_106 ) ) ;
F_4 ( V_182 , L_12 ,
F_27 ( V_74 -> V_89 ) ) ;
F_4 ( V_182 , L_50 ,
F_27 ( V_74 -> time ) ) ;
F_4 ( V_182 , L_51 ,
F_27 ( V_74 -> V_161 ) ) ;
F_4 ( V_2 , L_52 , V_182 ) ;
F_4 ( V_2 , L_53 , F_35 (
( const char * ) V_74 -> V_107 , V_74 -> V_183 ) ) ;
F_4 ( V_2 , L_54 ,
F_17 ( F_39 ( V_78 -> V_83 ) ) ) ;
if ( V_78 -> V_96 ) {
F_4 ( V_2 , L_19 ,
F_17 ( V_78 -> V_96 -> V_98 -> V_34 ) ) ;
}
if ( V_78 -> V_90 ) {
F_4 ( V_2 , L_55 ,
F_17 ( V_78 -> V_90 -> V_34 ) ) ;
}
V_82 = F_29 ( V_74 , V_76 , V_78 ) ;
F_4 ( V_2 , L_56 , V_82 ) ;
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_46 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_15 ) ;
}
static void F_70 ( union V_184 * V_26 ,
struct V_73 * V_74 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_132 * V_132 = & V_185 ;
switch ( V_76 -> V_113 . type ) {
case V_186 :
F_38 ( V_74 , V_76 , V_78 ) ;
break;
default:
if ( V_132 -> V_187 )
F_71 ( & V_132 -> V_131 , V_26 , V_74 , V_76 , V_78 ) ;
else
F_69 ( V_74 , V_76 , V_78 ) ;
}
}
static void F_72 ( char * V_21 , T_4 V_41 ,
struct V_75 * V_76 )
{
char * V_188 = V_21 ;
F_73 ( V_21 , V_41 , L_57 , F_53 ( V_76 ) ) ;
while ( ( V_188 = strchr ( V_188 , ':' ) ) ) {
* V_188 = '_' ;
V_188 ++ ;
}
}
static void
F_74 ( struct V_75 * V_189 , int V_106 , int V_83 , V_112 V_190 ,
struct V_191 * V_44 )
{
T_1 * V_5 , * V_15 ;
static char V_1 [ 256 ] ;
int V_17 = 0 ;
V_15 = F_14 ( V_110 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
F_72 ( V_1 , sizeof( V_1 ) ,
V_189 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_75 ( L_58 , V_1 ) ;
return;
}
F_16 ( V_15 , V_17 ++ , F_18 ( V_106 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_83 ) ) ;
F_48 ( V_15 , V_17 ++ , V_190 ) ;
F_48 ( V_15 , V_17 ++ , V_44 -> V_4 ) ;
F_48 ( V_15 , V_17 ++ , V_44 -> V_192 ) ;
F_48 ( V_15 , V_17 ++ , V_44 -> V_193 ) ;
if ( F_46 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
F_6 ( V_15 ) ;
}
static void F_76 ( struct V_194 * V_114 ,
struct V_75 * V_189 , V_112 V_190 )
{
struct V_195 * V_196 = V_189 -> V_196 ;
struct V_197 * V_198 = V_189 -> V_198 ;
int V_106 , V_83 ;
if ( V_114 -> V_199 == V_200 ) {
F_74 ( V_189 , - 1 , - 1 , V_190 ,
& V_189 -> V_201 -> V_202 ) ;
return;
}
for ( V_83 = 0 ; V_83 < V_196 -> V_203 ; V_83 ++ ) {
for ( V_106 = 0 ; V_106 < V_198 -> V_203 ; V_106 ++ ) {
F_74 ( V_189 , V_198 -> V_96 [ V_106 ] ,
F_77 ( V_196 , V_83 ) , V_190 ,
F_78 ( V_189 -> V_201 , V_106 , V_83 ) ) ;
}
}
}
static void F_79 ( V_112 V_190 )
{
T_1 * V_5 , * V_15 ;
static const char V_1 [] = L_59 ;
int V_17 = 0 ;
V_15 = F_14 ( V_110 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
F_75 ( L_58 , V_1 ) ;
return;
}
F_48 ( V_15 , V_17 ++ , V_190 ) ;
if ( F_46 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
F_6 ( V_15 ) ;
}
static int F_80 ( void )
{
V_204 = F_81 ( L_60 ) ;
if ( V_204 == NULL )
return - 1 ;
F_82 ( V_204 ) ;
V_6 = F_83 ( V_204 ) ;
if ( V_6 == NULL )
goto error;
F_82 ( V_6 ) ;
F_12 ( L_61 , NULL ) ;
return 0 ;
error:
F_84 ( V_6 ) ;
F_84 ( V_204 ) ;
return - 1 ;
}
static void F_85 ( struct V_132 * V_132 )
{
const char * V_205 = L_62 ;
const char * V_206 = L_63 ;
const char * V_207 = L_64 ;
T_1 * V_187 , * V_208 , * V_209 ;
bool V_210 = false ;
bool V_211 = false ;
int V_212 ;
memset ( V_132 , 0 , sizeof( struct V_132 ) ) ;
if ( F_86 ( & V_132 -> V_131 ) )
F_3 ( L_65 ) ;
V_187 = F_8 ( V_6 , V_205 ) ;
if ( ! V_187 )
return;
V_212 = F_87 ( V_187 ) ;
if ( V_212 == - 1 )
F_1 ( V_205 ) ;
if ( ! V_212 )
return;
V_132 -> V_131 . V_213 = NULL ;
V_208 = F_8 ( V_6 , V_206 ) ;
if ( V_208 ) {
V_212 = F_87 ( V_208 ) ;
if ( V_212 == - 1 )
F_1 ( V_206 ) ;
V_210 = ! ! V_212 ;
}
if ( V_210 ) {
V_132 -> V_131 . V_213 =
F_88 ( F_67 ,
& V_132 -> V_131 ) ;
if ( ! V_132 -> V_131 . V_213 )
F_3 ( L_66 ) ;
}
V_132 -> V_131 . V_214 = NULL ;
V_209 = F_8 ( V_6 ,
V_207 ) ;
if ( V_209 ) {
V_212 = F_87 ( V_209 ) ;
if ( V_212 == - 1 )
F_1 ( V_207 ) ;
V_211 = ! ! V_212 ;
}
if ( V_211 ) {
if ( V_132 -> V_131 . V_213 )
V_132 -> V_131 . V_214 = V_132 -> V_131 . V_213 -> V_214 ;
else
V_132 -> V_131 . V_214 = F_89 () ;
if ( ! V_132 -> V_131 . V_214 )
F_3 ( L_67 ) ;
}
V_132 -> V_187 = true ;
V_80 . V_215 = sizeof( V_112 ) ;
F_90 ( V_76 ) ;
F_90 ( V_135 ) ;
F_90 ( V_83 ) ;
F_90 ( V_109 ) ;
F_90 ( V_216 ) ;
F_90 ( V_98 ) ;
F_90 ( V_36 ) ;
F_90 ( V_151 ) ;
F_90 ( V_74 ) ;
F_90 ( V_169 ) ;
F_90 ( V_174 ) ;
}
static int F_91 ( const char * V_217 , int V_218 , const char * * V_219 )
{
struct V_132 * V_132 = & V_185 ;
const char * * V_220 ;
char V_221 [ V_222 ] ;
int V_67 , V_223 = 0 ;
T_5 * V_224 ;
V_220 = malloc ( ( V_218 + 1 ) * sizeof( const char * ) ) ;
V_220 [ 0 ] = V_217 ;
for ( V_67 = 1 ; V_67 < V_218 + 1 ; V_67 ++ )
V_220 [ V_67 ] = V_219 [ V_67 - 1 ] ;
F_92 () ;
F_93 () ;
F_94 ( V_218 + 1 , ( char * * ) V_220 ) ;
V_224 = fopen ( V_217 , L_68 ) ;
if ( ! V_224 ) {
sprintf ( V_221 , L_69 , V_217 ) ;
perror ( V_221 ) ;
V_223 = - 1 ;
goto error;
}
V_223 = F_95 ( V_224 , V_217 ) ;
if ( V_223 ) {
fprintf ( V_225 , L_70 , V_217 ) ;
goto error;
}
V_223 = F_80 () ;
if ( V_223 ) {
fprintf ( V_225 , L_71 , V_217 ) ;
goto error;
}
F_85 ( V_132 ) ;
if ( V_132 -> V_187 ) {
V_223 = F_96 ( & V_132 -> V_131 ) ;
if ( V_223 )
goto error;
}
free ( V_220 ) ;
return V_223 ;
error:
F_97 () ;
free ( V_220 ) ;
return V_223 ;
}
static int F_98 ( void )
{
struct V_132 * V_132 = & V_185 ;
return F_99 ( & V_132 -> V_131 ) ;
}
static int F_100 ( void )
{
struct V_132 * V_132 = & V_185 ;
F_12 ( L_72 , NULL ) ;
F_101 ( & V_132 -> V_131 ) ;
F_84 ( V_6 ) ;
F_84 ( V_204 ) ;
F_97 () ;
return 0 ;
}
static int F_102 ( struct V_121 * V_121 , const char * V_226 )
{
struct V_25 * V_26 = NULL ;
struct V_59 * V_227 ;
char V_228 [ V_222 ] ;
int V_229 , V_44 ;
T_5 * V_230 ;
sprintf ( V_228 , L_73 , V_226 ) ;
V_230 = fopen ( V_228 , L_74 ) ;
if ( V_230 == NULL ) {
fprintf ( V_225 , L_75 , V_228 ) ;
return - 1 ;
}
fprintf ( V_230 , L_76
L_77 ) ;
fprintf ( V_230 , L_78
L_79 ) ;
fprintf ( V_230 , L_80
L_81 ) ;
fprintf ( V_230 , L_82
L_83 ) ;
fprintf ( V_230 , L_84
L_85 ) ;
fprintf ( V_230 , L_86
L_87 ) ;
fprintf ( V_230 , L_88
L_89 ) ;
fprintf ( V_230 , L_90 ) ;
fprintf ( V_230 , L_91 ) ;
fprintf ( V_230 , L_92 ) ;
fprintf ( V_230 , L_93 ) ;
fprintf ( V_230 , L_94 ) ;
fprintf ( V_230 , L_95 ) ;
fprintf ( V_230 , L_96 ) ;
fprintf ( V_230 , L_97 ) ;
fprintf ( V_230 , L_98 ) ;
fprintf ( V_230 , L_99 ) ;
while ( ( V_26 = F_103 ( V_121 , V_26 ) ) ) {
fprintf ( V_230 , L_100 , V_26 -> system , V_26 -> V_34 ) ;
fprintf ( V_230 , L_101 ) ;
fprintf ( V_230 , L_102 ) ;
fprintf ( V_230 , L_103 ) ;
fprintf ( V_230 , L_104 ) ;
fprintf ( V_230 , L_105 ) ;
fprintf ( V_230 , L_106 ) ;
fprintf ( V_230 , L_107 ) ;
fprintf ( V_230 , L_108 ) ;
V_229 = 0 ;
V_44 = 0 ;
for ( V_227 = V_26 -> V_122 . V_123 ; V_227 ; V_227 = V_227 -> V_22 ) {
if ( V_229 ++ )
fprintf ( V_230 , L_109 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_230 , L_110 ) ;
fprintf ( V_230 , L_43 , V_227 -> V_34 ) ;
}
fprintf ( V_230 , L_111 ) ;
fprintf ( V_230 , L_112
L_113
L_114 ) ;
fprintf ( V_230 , L_115 ) ;
V_229 = 0 ;
V_44 = 0 ;
for ( V_227 = V_26 -> V_122 . V_123 ; V_227 ; V_227 = V_227 -> V_22 ) {
if ( V_229 ++ )
fprintf ( V_230 , L_109 ) ;
if ( V_44 && V_44 % 3 == 0 ) {
fprintf ( V_230 , L_116 ) ;
}
V_44 ++ ;
fprintf ( V_230 , L_117 , V_227 -> V_34 ) ;
if ( V_227 -> V_35 & V_126 ||
V_227 -> V_35 & V_231 ||
V_227 -> V_35 & V_62 ||
V_227 -> V_35 & V_232 )
fprintf ( V_230 , L_118 ) ;
else if ( V_227 -> V_35 & V_70 )
fprintf ( V_230 , L_119 ) ;
else
fprintf ( V_230 , L_120 ) ;
}
fprintf ( V_230 , L_121 ) ;
V_229 = 0 ;
V_44 = 0 ;
for ( V_227 = V_26 -> V_122 . V_123 ; V_227 ; V_227 = V_227 -> V_22 ) {
if ( V_229 ++ )
fprintf ( V_230 , L_109 ) ;
if ( ++ V_44 % 5 == 0 )
fprintf ( V_230 , L_122 ) ;
if ( V_227 -> V_35 & V_231 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_230 , L_122 ) ;
V_44 = 4 ;
}
fprintf ( V_230 , L_123 ) ;
fprintf ( V_230 , L_124 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_230 , L_125 , V_227 -> V_34 ,
V_227 -> V_34 ) ;
} else if ( V_227 -> V_35 & V_232 ) {
if ( ( V_44 - 1 ) % 5 != 0 ) {
fprintf ( V_230 , L_122 ) ;
V_44 = 4 ;
}
fprintf ( V_230 , L_126 ) ;
fprintf ( V_230 , L_124 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_230 , L_125 , V_227 -> V_34 ,
V_227 -> V_34 ) ;
} else
fprintf ( V_230 , L_43 , V_227 -> V_34 ) ;
}
fprintf ( V_230 , L_127 ) ;
fprintf ( V_230 , L_128 ) ;
fprintf ( V_230 , L_129 ) ;
fprintf ( V_230 , L_130 ) ;
fprintf ( V_230 , L_131 ) ;
fprintf ( V_230 , L_132 ) ;
fprintf ( V_230 , L_133 ) ;
}
fprintf ( V_230 , L_134
L_135 ) ;
fprintf ( V_230 , L_136
L_137 ) ;
fprintf ( V_230 , L_138
L_139
L_140
L_141 ) ;
fclose ( V_230 ) ;
fprintf ( V_225 , L_142 , V_228 ) ;
return 0 ;
}
