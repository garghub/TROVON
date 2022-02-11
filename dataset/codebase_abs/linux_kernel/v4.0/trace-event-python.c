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
break;
case V_42 :
F_21 ( V_26 , V_11 , args -> V_43 . V_44 ) ;
break;
case V_45 :
if ( strcmp ( args -> V_46 . V_46 , L_8 ) == 0 )
V_32 = 1 ;
F_21 ( V_26 , V_11 , args -> V_46 . V_47 ) ;
F_21 ( V_26 , V_11 , args -> V_46 . V_48 ) ;
break;
default:
case V_49 :
case V_50 :
case V_51 :
case V_52 :
return;
}
if ( args -> V_22 )
F_21 ( V_26 , V_11 , args -> V_22 ) ;
}
static T_1 * F_23 ( struct V_25 * V_26 ,
struct V_53 * V_20 , void * V_54 )
{
bool V_55 = V_20 -> V_35 & V_56 ;
T_1 * V_57 , * V_58 = NULL ;
unsigned long long V_4 ;
unsigned int V_59 , V_60 , V_61 ;
if ( V_55 ) {
V_58 = F_24 ( V_20 -> V_62 ) ;
V_59 = V_20 -> V_40 / V_20 -> V_62 ;
V_60 = V_20 -> V_62 ;
} else {
V_59 = V_20 -> V_40 ;
V_60 = 1 ;
}
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_4 = F_25 ( V_26 , V_54 + V_20 -> V_63 + V_61 * V_59 ,
V_59 ) ;
if ( V_20 -> V_35 & V_64 ) {
if ( ( long long ) V_4 >= V_65 &&
( long long ) V_4 <= V_66 )
V_57 = F_18 ( V_4 ) ;
else
V_57 = F_26 ( V_4 ) ;
} else {
if ( V_4 <= V_66 )
V_57 = F_18 ( V_4 ) ;
else
V_57 = F_27 ( V_4 ) ;
}
if ( V_55 )
F_28 ( V_58 , V_61 , V_57 ) ;
}
if ( V_55 )
V_57 = V_58 ;
return V_57 ;
}
static T_1 * F_29 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_71 * V_72 )
{
T_1 * V_73 ;
V_73 = F_24 ( 0 ) ;
if ( ! V_73 )
F_3 ( L_9 ) ;
if ( ! V_74 . V_75 || ! V_68 -> V_76 )
goto exit;
if ( F_30 ( V_72 -> V_77 , V_70 ,
V_68 , NULL , NULL ,
V_78 ) != 0 ) {
F_31 ( L_10 ) ;
goto exit;
}
F_32 ( & V_79 ) ;
while ( 1 ) {
T_1 * V_80 ;
struct V_81 * V_82 ;
V_82 = F_33 ( & V_79 ) ;
if ( ! V_82 )
break;
V_80 = F_34 () ;
if ( ! V_80 )
F_3 ( L_11 ) ;
F_4 ( V_80 , L_12 ,
F_27 ( V_82 -> V_83 ) ) ;
if ( V_82 -> V_84 ) {
T_1 * V_85 = F_34 () ;
if ( ! V_85 )
F_3 ( L_11 ) ;
F_4 ( V_85 , L_13 ,
F_27 ( V_82 -> V_84 -> V_86 ) ) ;
F_4 ( V_85 , L_14 ,
F_27 ( V_82 -> V_84 -> V_87 ) ) ;
F_4 ( V_85 , L_15 ,
F_18 ( V_82 -> V_84 -> V_88 ) ) ;
F_4 ( V_85 , L_16 ,
F_35 ( V_82 -> V_84 -> V_34 ,
V_82 -> V_84 -> V_89 ) ) ;
F_4 ( V_80 , L_17 , V_85 ) ;
}
if ( V_82 -> V_90 ) {
struct V_90 * V_90 = V_82 -> V_90 ;
const char * V_91 = L_18 ;
if ( V_90 && V_90 -> V_92 && ( V_90 -> V_92 -> V_34 || V_90 -> V_92 -> V_93 ) ) {
if ( V_74 . V_94 && V_90 -> V_92 -> V_93 )
V_91 = V_90 -> V_92 -> V_93 ;
else if ( V_90 -> V_92 -> V_34 )
V_91 = V_90 -> V_92 -> V_34 ;
}
F_4 ( V_80 , L_19 ,
F_17 ( V_91 ) ) ;
}
F_36 ( & V_79 ) ;
F_37 ( V_73 , V_80 ) ;
F_6 ( V_80 ) ;
}
exit:
return V_73 ;
}
static void F_38 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_77 * V_77 ,
struct V_71 * V_72 )
{
struct V_25 * V_26 = V_70 -> V_95 ;
T_1 * V_5 , * V_96 , * V_15 , * V_57 , * V_76 ;
T_1 * V_2 = NULL ;
static char V_1 [ 256 ] ;
struct V_53 * V_20 ;
unsigned long V_97 , V_98 ;
unsigned V_17 = 0 ;
int V_99 ;
int V_100 = V_68 -> V_100 ;
void * V_54 = V_68 -> V_101 ;
unsigned long long V_102 = V_68 -> time ;
const char * V_103 = F_39 ( V_77 ) ;
V_15 = F_14 ( V_104 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
if ( ! V_26 )
F_40 ( L_20 , ( int ) V_70 -> V_105 . V_106 ) ;
V_99 = F_41 ( V_26 , L_21 , V_54 ) ;
sprintf ( V_1 , L_22 , V_26 -> system , V_26 -> V_34 ) ;
if ( ! F_42 ( V_26 -> V_107 , V_108 ) )
F_21 ( V_26 , V_1 , V_26 -> V_109 . args ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 ) {
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_23 ) ;
}
V_97 = V_102 / V_110 ;
V_98 = V_102 - V_97 * V_110 ;
V_111 -> V_112 = V_54 ;
V_111 -> V_113 = V_70 -> V_95 -> V_113 ;
V_96 = F_43 ( V_111 , NULL ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_1 ) ) ;
F_16 ( V_15 , V_17 ++ , V_96 ) ;
V_76 = F_29 ( V_68 , V_70 , V_72 ) ;
if ( V_5 ) {
F_16 ( V_15 , V_17 ++ , F_18 ( V_100 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_97 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_98 ) ) ;
F_16 ( V_15 , V_17 ++ , F_18 ( V_99 ) ) ;
F_16 ( V_15 , V_17 ++ , F_17 ( V_103 ) ) ;
F_16 ( V_15 , V_17 ++ , V_76 ) ;
} else {
F_4 ( V_2 , L_24 , F_18 ( V_100 ) ) ;
F_4 ( V_2 , L_25 , F_18 ( V_97 ) ) ;
F_4 ( V_2 , L_26 , F_18 ( V_98 ) ) ;
F_4 ( V_2 , L_21 , F_18 ( V_99 ) ) ;
F_4 ( V_2 , L_27 , F_17 ( V_103 ) ) ;
F_4 ( V_2 , L_28 , V_76 ) ;
}
for ( V_20 = V_26 -> V_114 . V_115 ; V_20 ; V_20 = V_20 -> V_22 ) {
if ( V_20 -> V_35 & V_116 ) {
int V_63 ;
if ( V_20 -> V_35 & V_117 ) {
V_63 = * ( int * ) ( V_54 + V_20 -> V_63 ) ;
V_63 &= 0xffff ;
} else
V_63 = V_20 -> V_63 ;
V_57 = F_17 ( ( char * ) V_54 + V_63 ) ;
} else {
V_57 = F_23 ( V_26 , V_20 , V_54 ) ;
}
if ( V_5 )
F_16 ( V_15 , V_17 ++ , V_57 ) ;
else
F_4 ( V_2 , V_20 -> V_34 , V_57 ) ;
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
static T_1 * F_45 ( unsigned int V_118 )
{
T_1 * V_15 ;
V_15 = F_14 ( V_118 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
return V_15 ;
}
static int F_46 ( T_1 * V_15 , unsigned int V_119 , T_2 V_4 )
{
#if V_120 == 64
return F_16 ( V_15 , V_119 , F_18 ( V_4 ) ) ;
#endif
#if V_120 == 32
return F_16 ( V_15 , V_119 , F_26 ( V_4 ) ) ;
#endif
}
static int F_47 ( T_1 * V_15 , unsigned int V_119 , T_3 V_4 )
{
return F_16 ( V_15 , V_119 , F_18 ( V_4 ) ) ;
}
static int F_48 ( T_1 * V_15 , unsigned int V_119 , const char * V_97 )
{
return F_16 ( V_15 , V_119 , F_17 ( V_97 ) ) ;
}
static int F_49 ( struct V_121 * V_122 , struct V_69 * V_70 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_46 ( V_15 , 0 , V_70 -> V_124 ) ;
F_48 ( V_15 , 1 , F_51 ( V_70 ) ) ;
F_10 ( V_123 -> V_125 , V_15 , L_31 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_121 * V_122 ,
struct V_126 * V_126 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 3 ) ;
F_46 ( V_15 , 0 , V_126 -> V_124 ) ;
F_47 ( V_15 , 1 , V_126 -> V_99 ) ;
F_48 ( V_15 , 2 , V_126 -> V_127 ? V_126 -> V_127 : L_32 ) ;
F_10 ( V_123 -> V_128 , V_15 , L_33 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_53 ( struct V_121 * V_122 , struct V_77 * V_77 ,
T_2 V_129 , struct V_126 * V_126 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 5 ) ;
F_46 ( V_15 , 0 , V_77 -> V_124 ) ;
F_46 ( V_15 , 1 , V_126 -> V_124 ) ;
F_46 ( V_15 , 2 , V_129 ) ;
F_47 ( V_15 , 3 , V_77 -> V_130 ) ;
F_47 ( V_15 , 4 , V_77 -> V_131 ) ;
F_10 ( V_123 -> V_132 , V_15 , L_34 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_54 ( struct V_121 * V_122 , struct V_103 * V_103 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_46 ( V_15 , 0 , V_103 -> V_124 ) ;
F_48 ( V_15 , 1 , F_55 ( V_103 ) ) ;
F_10 ( V_123 -> V_133 , V_15 , L_35 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_56 ( struct V_121 * V_122 , T_2 V_124 ,
struct V_103 * V_103 , struct V_77 * V_77 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 3 ) ;
F_46 ( V_15 , 0 , V_124 ) ;
F_46 ( V_15 , 1 , V_103 -> V_124 ) ;
F_46 ( V_15 , 2 , V_77 -> V_124 ) ;
F_10 ( V_123 -> V_134 , V_15 , L_36 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_57 ( struct V_121 * V_122 , struct V_92 * V_92 ,
struct V_126 * V_126 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
char V_135 [ V_136 * 2 + 1 ] ;
T_1 * V_15 ;
F_58 ( V_92 -> V_137 , sizeof( V_92 -> V_137 ) , V_135 ) ;
V_15 = F_45 ( 5 ) ;
F_46 ( V_15 , 0 , V_92 -> V_124 ) ;
F_46 ( V_15 , 1 , V_126 -> V_124 ) ;
F_48 ( V_15 , 2 , V_92 -> V_138 ) ;
F_48 ( V_15 , 3 , V_92 -> V_93 ) ;
F_48 ( V_15 , 4 , V_135 ) ;
F_10 ( V_123 -> V_139 , V_15 , L_37 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_59 ( struct V_121 * V_122 , struct V_36 * V_84 ,
struct V_92 * V_92 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_2 * V_140 = F_60 ( V_84 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 6 ) ;
F_46 ( V_15 , 0 , * V_140 ) ;
F_46 ( V_15 , 1 , V_92 -> V_124 ) ;
F_46 ( V_15 , 2 , V_84 -> V_86 ) ;
F_46 ( V_15 , 3 , V_84 -> V_87 ) ;
F_47 ( V_15 , 4 , V_84 -> V_88 ) ;
F_48 ( V_15 , 5 , V_84 -> V_34 ) ;
F_10 ( V_123 -> V_141 , V_15 , L_38 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_61 ( struct V_121 * V_122 , T_4 V_142 ,
const char * V_34 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 2 ) ;
F_47 ( V_15 , 0 , V_142 ) ;
F_48 ( V_15 , 1 , V_34 ) ;
F_10 ( V_123 -> V_143 , V_15 , L_39 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_62 ( struct V_121 * V_122 ,
struct V_144 * V_145 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
V_15 = F_45 ( 21 ) ;
F_46 ( V_15 , 0 , V_145 -> V_124 ) ;
F_46 ( V_15 , 1 , V_145 -> V_70 -> V_124 ) ;
F_46 ( V_15 , 2 , V_145 -> V_72 -> V_126 -> V_124 ) ;
F_46 ( V_15 , 3 , V_145 -> V_77 -> V_124 ) ;
F_46 ( V_15 , 4 , V_145 -> V_146 ) ;
F_46 ( V_15 , 5 , V_145 -> V_147 ) ;
F_46 ( V_15 , 6 , V_145 -> V_140 ) ;
F_46 ( V_15 , 7 , V_145 -> V_63 ) ;
F_46 ( V_15 , 8 , V_145 -> V_68 -> V_83 ) ;
F_46 ( V_15 , 9 , V_145 -> V_68 -> time ) ;
F_47 ( V_15 , 10 , V_145 -> V_68 -> V_100 ) ;
F_46 ( V_15 , 11 , V_145 -> V_148 ) ;
F_46 ( V_15 , 12 , V_145 -> V_149 ) ;
F_46 ( V_15 , 13 , V_145 -> V_150 ) ;
F_46 ( V_15 , 14 , V_145 -> V_68 -> V_151 ) ;
F_46 ( V_15 , 15 , V_145 -> V_68 -> V_152 ) ;
F_46 ( V_15 , 16 , V_145 -> V_68 -> V_153 ) ;
F_46 ( V_15 , 17 , V_145 -> V_68 -> V_154 ) ;
F_46 ( V_15 , 18 , V_145 -> V_68 -> V_155 ) ;
F_47 ( V_15 , 19 , V_145 -> V_68 -> V_35 & V_156 ) ;
F_47 ( V_15 , 20 , ! ! ( V_145 -> V_68 -> V_35 & V_157 ) ) ;
F_10 ( V_123 -> V_158 , V_15 , L_40 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_63 ( struct V_121 * V_122 , struct V_159 * V_160 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_1 * V_15 ;
T_2 V_161 , V_140 ;
V_161 = V_160 -> V_162 ? V_160 -> V_162 -> V_124 : 0 ;
V_140 = V_160 -> V_84 ? * ( T_2 * ) F_60 ( V_160 -> V_84 ) : 0 ;
V_15 = F_45 ( 4 ) ;
F_46 ( V_15 , 0 , V_160 -> V_124 ) ;
F_46 ( V_15 , 1 , V_161 ) ;
F_46 ( V_15 , 2 , V_140 ) ;
F_46 ( V_15 , 3 , V_160 -> V_83 ) ;
F_10 ( V_123 -> V_163 , V_15 , L_41 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_64 ( struct V_121 * V_122 ,
struct V_164 * V_165 )
{
struct V_123 * V_123 = F_50 ( V_122 , struct V_123 , V_122 ) ;
T_2 V_146 = V_165 -> V_103 ? V_165 -> V_103 -> V_124 : 0 ;
T_1 * V_15 ;
V_15 = F_45 ( 11 ) ;
F_46 ( V_15 , 0 , V_165 -> V_124 ) ;
F_46 ( V_15 , 1 , V_165 -> V_77 -> V_124 ) ;
F_46 ( V_15 , 2 , V_146 ) ;
F_46 ( V_15 , 3 , V_165 -> V_160 -> V_124 ) ;
F_46 ( V_15 , 4 , V_165 -> V_166 ) ;
F_46 ( V_15 , 5 , V_165 -> V_167 ) ;
F_46 ( V_15 , 6 , V_165 -> V_168 ) ;
F_46 ( V_15 , 7 , V_165 -> V_169 ) ;
F_46 ( V_15 , 8 , V_165 -> V_170 ) ;
F_46 ( V_15 , 9 , V_165 -> V_160 -> V_162 -> V_124 ) ;
F_47 ( V_15 , 10 , V_165 -> V_35 ) ;
F_10 ( V_123 -> V_171 , V_15 , L_42 ) ;
F_6 ( V_15 ) ;
return 0 ;
}
static int F_65 ( struct V_164 * V_165 , void * V_54 )
{
struct V_121 * V_122 = V_54 ;
return F_66 ( V_122 , V_165 ) ;
}
static void F_67 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_77 * V_77 ,
struct V_71 * V_72 )
{
T_1 * V_5 , * V_15 , * V_2 , * V_76 , * V_172 ;
static char V_1 [ 64 ] ;
unsigned V_17 = 0 ;
V_15 = F_14 ( V_104 ) ;
if ( ! V_15 )
F_3 ( L_4 ) ;
V_2 = F_34 () ;
if ( ! V_2 )
F_3 ( L_11 ) ;
V_172 = F_34 () ;
if ( ! V_172 )
F_3 ( L_11 ) ;
snprintf ( V_1 , sizeof( V_1 ) , L_43 , L_44 ) ;
V_5 = F_7 ( V_1 ) ;
if ( ! V_5 )
goto exit;
F_4 ( V_2 , L_45 , F_17 ( F_51 ( V_70 ) ) ) ;
F_4 ( V_2 , L_46 , F_35 (
( const char * ) & V_70 -> V_105 , sizeof( V_70 -> V_105 ) ) ) ;
F_4 ( V_172 , L_47 ,
F_18 ( V_68 -> V_99 ) ) ;
F_4 ( V_172 , L_48 ,
F_18 ( V_68 -> V_131 ) ) ;
F_4 ( V_172 , L_49 ,
F_18 ( V_68 -> V_100 ) ) ;
F_4 ( V_172 , L_12 ,
F_27 ( V_68 -> V_83 ) ) ;
F_4 ( V_172 , L_50 ,
F_27 ( V_68 -> time ) ) ;
F_4 ( V_172 , L_51 ,
F_27 ( V_68 -> V_152 ) ) ;
F_4 ( V_2 , L_52 , V_172 ) ;
F_4 ( V_2 , L_53 , F_35 (
( const char * ) V_68 -> V_101 , V_68 -> V_173 ) ) ;
F_4 ( V_2 , L_54 ,
F_17 ( F_39 ( V_77 ) ) ) ;
if ( V_72 -> V_90 ) {
F_4 ( V_2 , L_19 ,
F_17 ( V_72 -> V_90 -> V_92 -> V_34 ) ) ;
}
if ( V_72 -> V_84 ) {
F_4 ( V_2 , L_55 ,
F_17 ( V_72 -> V_84 -> V_34 ) ) ;
}
V_76 = F_29 ( V_68 , V_70 , V_72 ) ;
F_4 ( V_2 , L_56 , V_76 ) ;
F_16 ( V_15 , V_17 ++ , V_2 ) ;
if ( F_44 ( & V_15 , V_17 ) == - 1 )
F_3 ( L_29 ) ;
F_10 ( V_5 , V_15 , V_1 ) ;
exit:
F_6 ( V_2 ) ;
F_6 ( V_15 ) ;
}
static void F_68 ( union V_174 * V_26 ,
struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_77 * V_77 ,
struct V_71 * V_72 )
{
struct V_123 * V_123 = & V_175 ;
switch ( V_70 -> V_105 . type ) {
case V_176 :
F_38 ( V_68 , V_70 , V_77 , V_72 ) ;
break;
default:
if ( V_123 -> V_177 )
F_69 ( & V_123 -> V_122 , V_26 , V_68 , V_70 ,
V_77 , V_72 ) ;
else
F_67 ( V_68 , V_70 , V_77 , V_72 ) ;
}
}
static int F_70 ( void )
{
V_178 = F_71 ( L_57 ) ;
if ( V_178 == NULL )
return - 1 ;
F_72 ( V_178 ) ;
V_6 = F_73 ( V_178 ) ;
if ( V_6 == NULL )
goto error;
F_72 ( V_6 ) ;
F_12 ( L_58 , NULL ) ;
return 0 ;
error:
F_74 ( V_6 ) ;
F_74 ( V_178 ) ;
return - 1 ;
}
static void F_75 ( struct V_123 * V_123 )
{
const char * V_179 = L_59 ;
const char * V_180 = L_60 ;
T_1 * V_177 , * V_181 ;
bool V_182 = false ;
int V_183 ;
memset ( V_123 , 0 , sizeof( struct V_123 ) ) ;
if ( F_76 ( & V_123 -> V_122 ) )
F_3 ( L_61 ) ;
V_177 = F_8 ( V_6 , V_179 ) ;
if ( ! V_177 )
return;
V_183 = F_77 ( V_177 ) ;
if ( V_183 == - 1 )
F_1 ( V_179 ) ;
if ( ! V_183 )
return;
V_123 -> V_122 . V_184 = NULL ;
V_181 = F_8 ( V_6 , V_180 ) ;
if ( V_181 ) {
V_183 = F_77 ( V_181 ) ;
if ( V_183 == - 1 )
F_1 ( V_180 ) ;
V_182 = ! ! V_183 ;
}
if ( V_182 ) {
V_123 -> V_122 . V_184 =
F_78 ( F_65 ,
& V_123 -> V_122 ) ;
if ( ! V_123 -> V_122 . V_184 )
F_3 ( L_62 ) ;
}
V_123 -> V_177 = true ;
V_74 . V_185 = sizeof( T_2 ) ;
F_79 ( V_70 ) ;
F_79 ( V_126 ) ;
F_79 ( V_77 ) ;
F_79 ( V_103 ) ;
F_79 ( V_186 ) ;
F_79 ( V_92 ) ;
F_79 ( V_36 ) ;
F_79 ( V_142 ) ;
F_79 ( V_68 ) ;
F_79 ( V_159 ) ;
F_79 ( V_164 ) ;
}
static int F_80 ( const char * V_187 , int V_188 , const char * * V_189 )
{
struct V_123 * V_123 = & V_175 ;
const char * * V_190 ;
char V_191 [ V_192 ] ;
int V_61 , V_193 = 0 ;
T_5 * V_194 ;
V_190 = malloc ( ( V_188 + 1 ) * sizeof( const char * ) ) ;
V_190 [ 0 ] = V_187 ;
for ( V_61 = 1 ; V_61 < V_188 + 1 ; V_61 ++ )
V_190 [ V_61 ] = V_189 [ V_61 - 1 ] ;
F_81 () ;
F_82 () ;
F_83 ( V_188 + 1 , ( char * * ) V_190 ) ;
V_194 = fopen ( V_187 , L_63 ) ;
if ( ! V_194 ) {
sprintf ( V_191 , L_64 , V_187 ) ;
perror ( V_191 ) ;
V_193 = - 1 ;
goto error;
}
V_193 = F_84 ( V_194 , V_187 ) ;
if ( V_193 ) {
fprintf ( V_195 , L_65 , V_187 ) ;
goto error;
}
V_193 = F_70 () ;
if ( V_193 ) {
fprintf ( V_195 , L_66 , V_187 ) ;
goto error;
}
free ( V_190 ) ;
F_75 ( V_123 ) ;
if ( V_123 -> V_177 ) {
V_193 = F_85 ( & V_123 -> V_122 ) ;
if ( V_193 )
goto error;
}
return V_193 ;
error:
F_86 () ;
free ( V_190 ) ;
return V_193 ;
}
static int F_87 ( void )
{
struct V_123 * V_123 = & V_175 ;
return F_88 ( & V_123 -> V_122 ) ;
}
static int F_89 ( void )
{
struct V_123 * V_123 = & V_175 ;
F_12 ( L_67 , NULL ) ;
F_90 ( & V_123 -> V_122 ) ;
F_74 ( V_6 ) ;
F_74 ( V_178 ) ;
F_86 () ;
return 0 ;
}
static int F_91 ( struct V_113 * V_113 , const char * V_196 )
{
struct V_25 * V_26 = NULL ;
struct V_53 * V_197 ;
char V_198 [ V_192 ] ;
int V_199 , V_200 ;
T_5 * V_201 ;
sprintf ( V_198 , L_68 , V_196 ) ;
V_201 = fopen ( V_198 , L_69 ) ;
if ( V_201 == NULL ) {
fprintf ( V_195 , L_70 , V_198 ) ;
return - 1 ;
}
fprintf ( V_201 , L_71
L_72 ) ;
fprintf ( V_201 , L_73
L_74 ) ;
fprintf ( V_201 , L_75
L_76 ) ;
fprintf ( V_201 , L_77
L_78 ) ;
fprintf ( V_201 , L_79
L_80 ) ;
fprintf ( V_201 , L_81
L_82 ) ;
fprintf ( V_201 , L_83
L_84 ) ;
fprintf ( V_201 , L_85 ) ;
fprintf ( V_201 , L_86 ) ;
fprintf ( V_201 , L_87 ) ;
fprintf ( V_201 , L_88 ) ;
fprintf ( V_201 , L_89 ) ;
fprintf ( V_201 , L_90 ) ;
fprintf ( V_201 , L_91 ) ;
fprintf ( V_201 , L_92 ) ;
fprintf ( V_201 , L_93 ) ;
fprintf ( V_201 , L_94 ) ;
while ( ( V_26 = F_92 ( V_113 , V_26 ) ) ) {
fprintf ( V_201 , L_95 , V_26 -> system , V_26 -> V_34 ) ;
fprintf ( V_201 , L_96 ) ;
fprintf ( V_201 , L_97 ) ;
fprintf ( V_201 , L_98 ) ;
fprintf ( V_201 , L_99 ) ;
fprintf ( V_201 , L_100 ) ;
fprintf ( V_201 , L_101 ) ;
fprintf ( V_201 , L_102 ) ;
fprintf ( V_201 , L_103 ) ;
V_199 = 0 ;
V_200 = 0 ;
for ( V_197 = V_26 -> V_114 . V_115 ; V_197 ; V_197 = V_197 -> V_22 ) {
if ( V_199 ++ )
fprintf ( V_201 , L_104 ) ;
if ( ++ V_200 % 5 == 0 )
fprintf ( V_201 , L_105 ) ;
fprintf ( V_201 , L_43 , V_197 -> V_34 ) ;
}
fprintf ( V_201 , L_106 ) ;
fprintf ( V_201 , L_107
L_108
L_109 ) ;
fprintf ( V_201 , L_110 ) ;
V_199 = 0 ;
V_200 = 0 ;
for ( V_197 = V_26 -> V_114 . V_115 ; V_197 ; V_197 = V_197 -> V_22 ) {
if ( V_199 ++ )
fprintf ( V_201 , L_104 ) ;
if ( V_200 && V_200 % 3 == 0 ) {
fprintf ( V_201 , L_111 ) ;
}
V_200 ++ ;
fprintf ( V_201 , L_112 , V_197 -> V_34 ) ;
if ( V_197 -> V_35 & V_116 ||
V_197 -> V_35 & V_202 ||
V_197 -> V_35 & V_56 ||
V_197 -> V_35 & V_203 )
fprintf ( V_201 , L_113 ) ;
else if ( V_197 -> V_35 & V_64 )
fprintf ( V_201 , L_114 ) ;
else
fprintf ( V_201 , L_115 ) ;
}
fprintf ( V_201 , L_116 ) ;
V_199 = 0 ;
V_200 = 0 ;
for ( V_197 = V_26 -> V_114 . V_115 ; V_197 ; V_197 = V_197 -> V_22 ) {
if ( V_199 ++ )
fprintf ( V_201 , L_104 ) ;
if ( ++ V_200 % 5 == 0 )
fprintf ( V_201 , L_117 ) ;
if ( V_197 -> V_35 & V_202 ) {
if ( ( V_200 - 1 ) % 5 != 0 ) {
fprintf ( V_201 , L_117 ) ;
V_200 = 4 ;
}
fprintf ( V_201 , L_118 ) ;
fprintf ( V_201 , L_119 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_201 , L_120 , V_197 -> V_34 ,
V_197 -> V_34 ) ;
} else if ( V_197 -> V_35 & V_203 ) {
if ( ( V_200 - 1 ) % 5 != 0 ) {
fprintf ( V_201 , L_117 ) ;
V_200 = 4 ;
}
fprintf ( V_201 , L_121 ) ;
fprintf ( V_201 , L_119 , V_26 -> system ,
V_26 -> V_34 ) ;
fprintf ( V_201 , L_120 , V_197 -> V_34 ,
V_197 -> V_34 ) ;
} else
fprintf ( V_201 , L_43 , V_197 -> V_34 ) ;
}
fprintf ( V_201 , L_122 ) ;
fprintf ( V_201 , L_123 ) ;
fprintf ( V_201 , L_124 ) ;
fprintf ( V_201 , L_125 ) ;
fprintf ( V_201 , L_126 ) ;
fprintf ( V_201 , L_127 ) ;
fprintf ( V_201 , L_128 ) ;
}
fprintf ( V_201 , L_129
L_130 ) ;
fprintf ( V_201 , L_131
L_132 ) ;
fprintf ( V_201 , L_133
L_134
L_135
L_136 ) ;
fclose ( V_201 ) ;
fprintf ( V_195 , L_137 , V_198 ) ;
return 0 ;
}
