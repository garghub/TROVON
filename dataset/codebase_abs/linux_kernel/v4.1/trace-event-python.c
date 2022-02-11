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
return;
}
if ( args -> V_22 )
F_21 ( V_26 , V_11 , args -> V_22 ) ;
}
static T_1 * F_23 ( struct V_25 * V_26 ,
struct V_57 * V_20 , void * V_58 )
{
bool V_59 = V_20 -> V_35 & V_60 ;
T_1 * V_61 , * V_62 = NULL ;
unsigned long long V_4 ;
unsigned int V_63 , V_64 , V_65 ;
if ( V_59 ) {
V_62 = F_24 ( V_20 -> V_66 ) ;
V_63 = V_20 -> V_40 / V_20 -> V_66 ;
V_64 = V_20 -> V_66 ;
} else {
V_63 = V_20 -> V_40 ;
V_64 = 1 ;
}
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
V_4 = F_25 ( V_26 , V_58 + V_20 -> V_67 + V_65 * V_63 ,
V_63 ) ;
if ( V_20 -> V_35 & V_68 ) {
if ( ( long long ) V_4 >= V_69 &&
( long long ) V_4 <= V_70 )
V_61 = F_18 ( V_4 ) ;
else
V_61 = F_26 ( V_4 ) ;
} else {
if ( V_4 <= V_70 )
V_61 = F_18 ( V_4 ) ;
else
V_61 = F_27 ( V_4 ) ;
}
if ( V_59 )
F_28 ( V_62 , V_65 , V_61 ) ;
}
if ( V_59 )
V_61 = V_62 ;
return V_61 ;
}
static T_1 * F_29 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
T_1 * V_77 ;
V_77 = F_24 ( 0 ) ;
if ( ! V_77 )
F_3 ( L_9 ) ;
if ( ! V_78 . V_79 || ! V_72 -> V_80 )
goto exit;
if ( F_30 ( V_76 -> V_81 , V_74 ,
V_72 , NULL , NULL ,
V_82 ) != 0 ) {
F_31 ( L_10 ) ;
goto exit;
}
F_32 ( & V_83 ) ;
while ( 1 ) {
T_1 * V_84 ;
struct V_85 * V_86 ;
V_86 = F_33 ( & V_83 ) ;
if ( ! V_86 )
break;
V_84 = F_34 () ;
if ( ! V_84 )
F_3 ( L_11 ) ;
F_4 ( V_84 , L_12 ,
F_27 ( V_86 -> V_87 ) ) ;
if ( V_86 -> V_88 ) {
T_1 * V_89 = F_34 () ;
if ( ! V_89 )
F_3 ( L_11 ) ;
F_4 ( V_89 , L_13 ,
F_27 ( V_86 -> V_88 -> V_90 ) ) ;
F_4 ( V_89 , L_14 ,
F_27 ( V_86 -> V_88 -> V_91 ) ) ;
F_4 ( V_89 , L_15 ,
F_18 ( V_86 -> V_88 -> V_92 ) ) ;
F_4 ( V_89 , L_16 ,
F_35 ( V_86 -> V_88 -> V_34 ,
V_86 -> V_88 -> V_93 ) ) ;
F_4 ( V_84 , L_17 , V_89 ) ;
}
if ( V_86 -> V_94 ) {
struct V_94 * V_94 = V_86 -> V_94 ;
const char * V_95 = L_18 ;
if ( V_94 && V_94 -> V_96 && ( V_94 -> V_96 -> V_34 || V_94 -> V_96 -> V_97 ) ) {
if ( V_78 . V_98 && V_94 -> V_96 -> V_97 )
V_95 = V_94 -> V_96 -> V_97 ;
else if ( V_94 -> V_96 -> V_34 )
V_95 = V_94 -> V_96 -> V_34 ;
}
F_4 ( V_84 , L_19 ,
F_17 ( V_95 ) ) ;
}
F_36 ( & V_83 ) ;
F_37 ( V_77 , V_84 ) ;
F_6 ( V_84 ) ;
}
exit:
return V_77 ;
}
static void F_38 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_25 * V_26 = V_74 -> V_99 ;
T_1 * V_5 , * V_100 , * V_15 , * V_61 , * V_80 ;
T_1 * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_57 * V_20 ;
unsigned long V_101 , V_102 ;
unsigned V_17 = 0 ;
int V_103 ;
int V_104 = V_72 -> V_104 ;
void * V_58 = V_72 -> V_105 ;
unsigned long long V_106 = V_72 -> time ;
const char * V_107 = F_39 ( V_76 -> V_81 ) ;
V_15 = F_14 ( V_108 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
if ( ! V_26 )
F_40 ( L_20 , ( int ) V_74 -> V_109 . V_110 ) ;
V_103 = F_41 ( V_26 , L_21 , V_58 ) ;
sprintf ( V_1 , L_22 , V_26 -> system , V_26 -> V_34 ) ;
if ( ! F_42 ( V_26 -> V_111 , V_112 ) )
F_21 ( V_26 , V_1 , V_26 -> V_113 . args ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_101 = V_106 / V_114 ;
V_102 = V_106 - V_101 * V_114 ;
V_115 -> V_116 = V_58 ;
V_115 -> V_117 = V_74 -> V_99 -> V_117 ;
V_100 = F_43 ( V_115 , NULL ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_1 ) ) ;
F_16 ( V_15 , V_17 ++ , V_100 ) ;
V_80 = F_29 ( V_72 , V_74 , V_76 ) ;
if ( V_5 ) {
F_16 ( V_15 , V_17 ++ , F_18 ( V_104 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_101 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_102 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_103 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_107 ) ) ;
F_16 ( V_15 , V_17 ++ , V_80 ) ;
} else {
F_4 ( V_2 , L_24 , F_18 ( V_104 ) ) ;
F_4 ( V_2 , L_25 , F_18 ( V_101 ) ) ;
F_4 ( V_2 , L_26 , F_18 ( V_102 ) ) ;
F_4 ( V_2 , L_21 , F_18 ( V_103 ) ) ;
F_4 ( V_2 , L_27 , F_17 ( V_107 ) ) ;
F_4 ( V_2 , L_28 , V_80 ) ;
}
for ( V_20 = V_26 -> V_118 . V_119 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_120 ) {
int V_67 ;
if ( V_20 -> V_35 & V_121 ) {
V_67 = * ( int * ) ( V_58 + V_20 -> V_67 ) ;
V_67 &= 0xffff ;
} else
V_67 = V_20 -> V_67 ;
V_61 = F_17 ( ( char * ) V_58 + V_67 ) ;
} else {
V_61 = F_23 ( V_26 , V_20 , V_58 ) ;
}
if ( V_5 )
F_16 ( V_15 , V_17 ++ , V_61 ) ;
else
F_4 ( V_2 , V_20 -> V_34 , V_61 ) ;
}
if ( ! V_5 )
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_44 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
if ( V_5 ) {
F_10 ( V_5 , V_15 , V_1 ) ;
} else {
F_12 ( L_30 , V_15 ) ;
F_6 ( V_2 ) ;
}
F_6 ( V_15 ) ;
}
static T_1 * F_45 ( unsigned int V_122 )
{
T_1 * V_15 ;
V_15 = F_14 ( V_122 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
return V_15 ;
}
static int F_46 ( T_1 * V_15 , unsigned int V_123 , T_2 V_4 )
{
#if V_124 == 64
return F_16 ( V_15 , V_123 , F_18 ( V_4 ) ) ;
#endif
#if V_124 == 32
return F_16 ( V_15 , V_123 , F_26 ( V_4 ) ) ;
#endif
}
static int F_47 ( T_1 * V_15 , unsigned int V_123 , T_3 V_4 )
{
return F_16 ( V_15 , V_123 , F_18 ( V_4 ) ) ;
}
static int F_48 ( T_1 * V_15 , unsigned int V_123 , const char * V_101 )
{
return F_16 ( V_15 , V_123 , F_17 ( V_101 ) ) ;
}
static int F_49 ( struct V_125 * V_126 , struct V_73 * V_74 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_46 ( V_15 , 0 , V_74 -> V_128 ) ;
F_48 ( V_15 , 1 , F_51 ( V_74 ) ) ;
F_10 ( V_127 -> V_129 , V_15 , L_31 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_125 * V_126 ,
struct V_130 * V_130 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 3 ) ;
F_46 ( V_15 , 0 , V_130 -> V_128 ) ;
F_47 ( V_15 , 1 , V_130 -> V_103 ) ;
F_48 ( V_15 , 2 , V_130 -> V_131 ? V_130 -> V_131 : L_32 ) ;
F_10 ( V_127 -> V_132 , V_15 , L_33 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_125 * V_126 , struct V_81 * V_81 ,
T_2 V_133 , struct V_130 * V_130 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 5 ) ;
F_46 ( V_15 , 0 , V_81 -> V_128 ) ;
F_46 ( V_15 , 1 , V_130 -> V_128 ) ;
F_46 ( V_15 , 2 , V_133 ) ;
F_47 ( V_15 , 3 , V_81 -> V_134 ) ;
F_47 ( V_15 , 4 , V_81 -> V_135 ) ;
F_10 ( V_127 -> V_136 , V_15 , L_34 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_54 ( struct V_125 * V_126 , struct V_107 * V_107 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_46 ( V_15 , 0 , V_107 -> V_128 ) ;
F_48 ( V_15 , 1 , F_55 ( V_107 ) ) ;
F_10 ( V_127 -> V_137 , V_15 , L_35 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_125 * V_126 , T_2 V_128 ,
struct V_107 * V_107 , struct V_81 * V_81 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 3 ) ;
F_46 ( V_15 , 0 , V_128 ) ;
F_46 ( V_15 , 1 , V_107 -> V_128 ) ;
F_46 ( V_15 , 2 , V_81 -> V_128 ) ;
F_10 ( V_127 -> V_138 , V_15 , L_36 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_57 ( struct V_125 * V_126 , struct V_96 * V_96 ,
struct V_130 * V_130 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
char V_139 [ V_140 * 2 + 1 ] ;
T_1 * V_15 ;
F_58 ( V_96 -> V_141 , sizeof( V_96 -> V_141 ) , V_139 ) ;
V_15 = F_45 ( 5 ) ;
F_46 ( V_15 , 0 , V_96 -> V_128 ) ;
F_46 ( V_15 , 1 , V_130 -> V_128 ) ;
F_48 ( V_15 , 2 , V_96 -> V_142 ) ;
F_48 ( V_15 , 3 , V_96 -> V_97 ) ;
F_48 ( V_15 , 4 , V_139 ) ;
F_10 ( V_127 -> V_143 , V_15 , L_37 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_59 ( struct V_125 * V_126 , struct V_36 * V_88 ,
struct V_96 * V_96 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_2 * V_144 = F_60 ( V_88 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 6 ) ;
F_46 ( V_15 , 0 , * V_144 ) ;
F_46 ( V_15 , 1 , V_96 -> V_128 ) ;
F_46 ( V_15 , 2 , V_88 -> V_90 ) ;
F_46 ( V_15 , 3 , V_88 -> V_91 ) ;
F_47 ( V_15 , 4 , V_88 -> V_92 ) ;
F_48 ( V_15 , 5 , V_88 -> V_34 ) ;
F_10 ( V_127 -> V_145 , V_15 , L_38 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_125 * V_126 , T_4 V_146 ,
const char * V_34 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_47 ( V_15 , 0 , V_146 ) ;
F_48 ( V_15 , 1 , V_34 ) ;
F_10 ( V_127 -> V_147 , V_15 , L_39 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_62 ( struct V_125 * V_126 ,
struct V_148 * V_149 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 21 ) ;
F_46 ( V_15 , 0 , V_149 -> V_128 ) ;
F_46 ( V_15 , 1 , V_149 -> V_74 -> V_128 ) ;
F_46 ( V_15 , 2 , V_149 -> V_76 -> V_130 -> V_128 ) ;
F_46 ( V_15 , 3 , V_149 -> V_76 -> V_81 -> V_128 ) ;
F_46 ( V_15 , 4 , V_149 -> V_150 ) ;
F_46 ( V_15 , 5 , V_149 -> V_151 ) ;
F_46 ( V_15 , 6 , V_149 -> V_144 ) ;
F_46 ( V_15 , 7 , V_149 -> V_67 ) ;
F_46 ( V_15 , 8 , V_149 -> V_72 -> V_87 ) ;
F_46 ( V_15 , 9 , V_149 -> V_72 -> time ) ;
F_47 ( V_15 , 10 , V_149 -> V_72 -> V_104 ) ;
F_46 ( V_15 , 11 , V_149 -> V_152 ) ;
F_46 ( V_15 , 12 , V_149 -> V_153 ) ;
F_46 ( V_15 , 13 , V_149 -> V_154 ) ;
F_46 ( V_15 , 14 , V_149 -> V_72 -> V_155 ) ;
F_46 ( V_15 , 15 , V_149 -> V_72 -> V_156 ) ;
F_46 ( V_15 , 16 , V_149 -> V_72 -> V_157 ) ;
F_46 ( V_15 , 17 , V_149 -> V_72 -> V_158 ) ;
F_46 ( V_15 , 18 , V_149 -> V_72 -> V_159 ) ;
F_47 ( V_15 , 19 , V_149 -> V_72 -> V_35 & V_160 ) ;
F_47 ( V_15 , 20 , ! ! ( V_149 -> V_72 -> V_35 & V_161 ) ) ;
F_10 ( V_127 -> V_162 , V_15 , L_40 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_63 ( struct V_125 * V_126 , struct V_163 * V_164 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_1 * V_15 ;
T_2 V_165 , V_144 ;
V_165 = V_164 -> V_166 ? V_164 -> V_166 -> V_128 : 0 ;
V_144 = V_164 -> V_88 ? * ( T_2 * ) F_60 ( V_164 -> V_88 ) : 0 ;
V_15 = F_45 ( 4 ) ;
F_46 ( V_15 , 0 , V_164 -> V_128 ) ;
F_46 ( V_15 , 1 , V_165 ) ;
F_46 ( V_15 , 2 , V_144 ) ;
F_46 ( V_15 , 3 , V_164 -> V_87 ) ;
F_10 ( V_127 -> V_167 , V_15 , L_41 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_64 ( struct V_125 * V_126 ,
struct V_168 * V_169 )
{
struct V_127 * V_127 = F_50 ( V_126 , struct V_127 , V_126 ) ;
T_2 V_150 = V_169 -> V_107 ? V_169 -> V_107 -> V_128 : 0 ;
T_1 * V_15 ;
V_15 = F_45 ( 11 ) ;
F_46 ( V_15 , 0 , V_169 -> V_128 ) ;
F_46 ( V_15 , 1 , V_169 -> V_81 -> V_128 ) ;
F_46 ( V_15 , 2 , V_150 ) ;
F_46 ( V_15 , 3 , V_169 -> V_164 -> V_128 ) ;
F_46 ( V_15 , 4 , V_169 -> V_170 ) ;
F_46 ( V_15 , 5 , V_169 -> V_171 ) ;
F_46 ( V_15 , 6 , V_169 -> V_172 ) ;
F_46 ( V_15 , 7 , V_169 -> V_173 ) ;
F_46 ( V_15 , 8 , V_169 -> V_174 ) ;
F_46 ( V_15 , 9 , V_169 -> V_164 -> V_166 -> V_128 ) ;
F_47 ( V_15 , 10 , V_169 -> V_35 ) ;
F_10 ( V_127 -> V_175 , V_15 , L_42 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_168 * V_169 , void * V_58 )
{
struct V_125 * V_126 = V_58 ;
return F_66 ( V_126 , V_169 ) ;
}
static void F_67 ( struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
T_1 * V_5 , * V_15 , * V_2 , * V_80 , * V_176 ;
static char V_1 [ 64 ] ;
unsigned V_17 = 0 ;
V_15 = F_14 ( V_108 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_11 ) ;
V_176 = F_34 () ;
if ( ! V_176 )
F_3 ( L_11 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_43 , L_44 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
goto exit;
F_4 ( V_2 , L_45 , F_17 ( F_51 ( V_74 ) ) ) ;
F_4 ( V_2 , L_46 , F_35 (
( const char * ) & V_74 -> V_109 , sizeof( V_74 -> V_109 ) ) ) ;
F_4 ( V_176 , L_47 ,
F_18 ( V_72 -> V_103 ) ) ;
F_4 ( V_176 , L_48 ,
F_18 ( V_72 -> V_135 ) ) ;
F_4 ( V_176 , L_49 ,
F_18 ( V_72 -> V_104 ) ) ;
F_4 ( V_176 , L_12 ,
F_27 ( V_72 -> V_87 ) ) ;
F_4 ( V_176 , L_50 ,
F_27 ( V_72 -> time ) ) ;
F_4 ( V_176 , L_51 ,
F_27 ( V_72 -> V_156 ) ) ;
F_4 ( V_2 , L_52 , V_176 ) ;
F_4 ( V_2 , L_53 , F_35 (
( const char * ) V_72 -> V_105 , V_72 -> V_177 ) ) ;
F_4 ( V_2 , L_54 ,
F_17 ( F_39 ( V_76 -> V_81 ) ) ) ;
if ( V_76 -> V_94 ) {
F_4 ( V_2 , L_19 ,
F_17 ( V_76 -> V_94 -> V_96 -> V_34 ) ) ;
}
if ( V_76 -> V_88 ) {
F_4 ( V_2 , L_55 ,
F_17 ( V_76 -> V_88 -> V_34 ) ) ;
}
V_80 = F_29 ( V_72 , V_74 , V_76 ) ;
F_4 ( V_2 , L_56 , V_80 ) ;
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_44 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_15 ) ;
}
static void F_68 ( union V_178 * V_26 ,
struct V_71 * V_72 ,
struct V_73 * V_74 ,
struct V_75 * V_76 )
{
struct V_127 * V_127 = & V_179 ;
switch ( V_74 -> V_109 . type ) {
case V_180 :
F_38 ( V_72 , V_74 , V_76 ) ;
break;
default:
if ( V_127 -> V_181 )
F_69 ( & V_127 -> V_126 , V_26 , V_72 , V_74 , V_76 ) ;
else
F_67 ( V_72 , V_74 , V_76 ) ;
}
}
static int F_70 ( void )
{
V_182 = F_71 ( L_57 ) ;
if ( V_182 == NULL )
return - 1 ;
F_72 ( V_182 ) ;
V_6 = F_73 ( V_182 ) ;
if ( V_6 == NULL )
goto error;
F_72 ( V_6 ) ;
F_12 ( L_58 , NULL ) ;
return 0 ;
error:
F_74 ( V_6 ) ;
F_74 ( V_182 ) ;
return - 1 ;
}
static void F_75 ( struct V_127 * V_127 )
{
const char * V_183 = L_59 ;
const char * V_184 = L_60 ;
T_1 * V_181 , * V_185 ;
bool V_186 = false ;
int V_187 ;
memset ( V_127 , 0 , sizeof( struct V_127 ) ) ;
if ( F_76 ( & V_127 -> V_126 ) )
F_3 ( L_61 ) ;
V_181 = F_8 ( V_6 , V_183 ) ;
if ( ! V_181 )
return;
V_187 = F_77 ( V_181 ) ;
if ( V_187 == - 1 )
F_1 ( V_183 ) ;
if ( ! V_187 )
return;
V_127 -> V_126 . V_188 = NULL ;
V_185 = F_8 ( V_6 , V_184 ) ;
if ( V_185 ) {
V_187 = F_77 ( V_185 ) ;
if ( V_187 == - 1 )
F_1 ( V_184 ) ;
V_186 = ! ! V_187 ;
}
if ( V_186 ) {
V_127 -> V_126 . V_188 =
F_78 ( F_65 ,
& V_127 -> V_126 ) ;
if ( ! V_127 -> V_126 . V_188 )
F_3 ( L_62 ) ;
}
V_127 -> V_181 = true ;
V_78 . V_189 = sizeof( T_2 ) ;
F_79 ( V_74 ) ;
F_79 ( V_130 ) ;
F_79 ( V_81 ) ;
F_79 ( V_107 ) ;
F_79 ( V_190 ) ;
F_79 ( V_96 ) ;
F_79 ( V_36 ) ;
F_79 ( V_146 ) ;
F_79 ( V_72 ) ;
F_79 ( V_163 ) ;
F_79 ( V_168 ) ;
}
static int F_80 ( const char * V_191 , int V_192 , const char * * V_193 )
{
struct V_127 * V_127 = & V_179 ;
const char * * V_194 ;
char V_195 [ V_196 ] ;
int V_65 , V_197 = 0 ;
T_5 * V_198 ;
V_194 = malloc ( ( V_192 + 1 ) * sizeof( const char * ) ) ;
V_194 [ 0 ] = V_191 ;
for ( V_65 = 1 ; V_65 < V_192 + 1 ; V_65 ++ )
V_194 [ V_65 ] = V_193 [ V_65 - 1 ] ;
F_81 () ;
F_82 () ;
F_83 ( V_192 + 1 , ( char * * ) V_194 ) ;
V_198 = fopen ( V_191 , L_63 ) ;
if ( ! V_198 ) {
sprintf ( V_195 , L_64 , V_191 ) ;
perror ( V_195 ) ;
V_197 = - 1 ;
goto error;
}
V_197 = F_84 ( V_198 , V_191 ) ;
if ( V_197 ) {
fprintf ( V_199 , L_65 , V_191 ) ;
goto error;
}
V_197 = F_70 () ;
if ( V_197 ) {
fprintf ( V_199 , L_66 , V_191 ) ;
goto error;
}
free ( V_194 ) ;
F_75 ( V_127 ) ;
if ( V_127 -> V_181 ) {
V_197 = F_85 ( & V_127 -> V_126 ) ;
if ( V_197 )
goto error;
}
return V_197 ;
error:
F_86 () ;
free ( V_194 ) ;
return V_197 ;
}
static int F_87 ( void )
{
struct V_127 * V_127 = & V_179 ;
return F_88 ( & V_127 -> V_126 ) ;
}
static int F_89 ( void )
{
struct V_127 * V_127 = & V_179 ;
F_12 ( L_67 , NULL ) ;
F_90 ( & V_127 -> V_126 ) ;
F_74 ( V_6 ) ;
F_74 ( V_182 ) ;
F_86 () ;
return 0 ;
}
static int F_91 ( struct V_117 * V_117 , const char * V_200 )
{
struct V_25 * V_26 = NULL ;
struct V_57 * V_201 ;
char V_202 [ V_196 ] ;
int V_203 , V_43 ;
T_5 * V_204 ;
sprintf ( V_202 , L_68 , V_200 ) ;
V_204 = fopen ( V_202 , L_69 ) ;
if ( V_204 == NULL ) {
fprintf ( V_199 , L_70 , V_202 ) ;
return - 1 ;
}
fprintf ( V_204 , L_71
L_72 ) ;
fprintf ( V_204 , L_73
L_74 ) ;
fprintf ( V_204 , L_75
L_76 ) ;
fprintf ( V_204 , L_77
L_78 ) ;
fprintf ( V_204 , L_79
L_80 ) ;
fprintf ( V_204 , L_81
L_82 ) ;
fprintf ( V_204 , L_83
L_84 ) ;
fprintf ( V_204 , L_85 ) ;
fprintf ( V_204 , L_86 ) ;
fprintf ( V_204 , L_87 ) ;
fprintf ( V_204 , L_88 ) ;
fprintf ( V_204 , L_89 ) ;
fprintf ( V_204 , L_90 ) ;
fprintf ( V_204 , L_91 ) ;
fprintf ( V_204 , L_92 ) ;
fprintf ( V_204 , L_93 ) ;
fprintf ( V_204 , L_94 ) ;
while ( ( V_26 = F_92 ( V_117 , V_26 ) ) ) {
fprintf ( V_204 , L_95 , V_26 -> system , V_26 -> V_34 ) ;
fprintf ( V_204 , L_96 ) ;
fprintf ( V_204 , L_97 ) ;
fprintf ( V_204 , L_98 ) ;
fprintf ( V_204 , L_99 ) ;
fprintf ( V_204 , L_100 ) ;
fprintf ( V_204 , L_101 ) ;
fprintf ( V_204 , L_102 ) ;
fprintf ( V_204 , L_103 ) ;
V_203 = 0 ;
V_43 = 0 ;
for ( V_201 = V_26 -> V_118 . V_119 ; V_201 ; V_201 = V_201 -> V_22 ) {
if ( V_203 ++ )
fprintf ( V_204 , L_104 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_204 , L_105 ) ;
fprintf ( V_204 , L_43 , V_201 -> V_34 ) ;
}
fprintf ( V_204 , L_106 ) ;
fprintf ( V_204 , L_107
L_108
L_109 ) ;
fprintf ( V_204 , L_110 ) ;
V_203 = 0 ;
V_43 = 0 ;
for ( V_201 = V_26 -> V_118 . V_119 ; V_201 ; V_201 = V_201 -> V_22 ) {
if ( V_203 ++ )
fprintf ( V_204 , L_104 ) ;
if ( V_43 && V_43 % 3 == 0 ) {
fprintf ( V_204 , L_111 ) ;
}
V_43 ++ ;
fprintf ( V_204 , L_112 , V_201 -> V_34 ) ;
if ( V_201 -> V_35 & V_120 ||
V_201 -> V_35 & V_205 ||
V_201 -> V_35 & V_60 ||
V_201 -> V_35 & V_206 )
fprintf ( V_204 , L_113 ) ;
else if ( V_201 -> V_35 & V_68 )
fprintf ( V_204 , L_114 ) ;
else
fprintf ( V_204 , L_115 ) ;
}
fprintf ( V_204 , L_116 ) ;
V_203 = 0 ;
V_43 = 0 ;
for ( V_201 = V_26 -> V_118 . V_119 ; V_201 ; V_201 = V_201 -> V_22 ) {
if ( V_203 ++ )
fprintf ( V_204 , L_104 ) ;
if ( ++ V_43 % 5 == 0 )
fprintf ( V_204 , L_117 ) ;
if ( V_201 -> V_35 & V_205 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_204 , L_117 ) ;
V_43 = 4 ;
}
fprintf ( V_204 , L_118 ) ;
fprintf ( V_204 , L_119 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_204 , L_120 , V_201 -> V_34 ,
V_201 -> V_34 ) ;
} else if ( V_201 -> V_35 & V_206 ) {
if ( ( V_43 - 1 ) % 5 != 0 ) {
fprintf ( V_204 , L_117 ) ;
V_43 = 4 ;
}
fprintf ( V_204 , L_121 ) ;
fprintf ( V_204 , L_119 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_204 , L_120 , V_201 -> V_34 ,
V_201 -> V_34 ) ;
} else
fprintf ( V_204 , L_43 , V_201 -> V_34 ) ;
}
fprintf ( V_204 , L_122 ) ;
fprintf ( V_204 , L_123 ) ;
fprintf ( V_204 , L_124 ) ;
fprintf ( V_204 , L_125 ) ;
fprintf ( V_204 , L_126 ) ;
fprintf ( V_204 , L_127 ) ;
fprintf ( V_204 , L_128 ) ;
}
fprintf ( V_204 , L_129
L_130 ) ;
fprintf ( V_204 , L_131
L_132 ) ;
fprintf ( V_204 , L_133
L_134
L_135
L_136 ) ;
fclose ( V_204 ) ;
fprintf ( V_199 , L_137 , V_202 ) ;
return 0 ;
}
