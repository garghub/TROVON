int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_2 -> V_9 & V_3 ) {
F_2 ( L_1 ,
V_3 , V_7 -> V_9 ) ;
return 1 ;
}
if ( V_7 -> V_9 & V_3 ) {
F_2 ( L_2 ,
V_7 -> V_9 , V_3 ) ;
return 0 ;
}
V_2 -> V_9 |= V_3 ;
V_7 -> V_9 |= V_3 ;
F_2 ( L_3 , V_3 , V_7 -> V_9 ) ;
return 1 ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_10 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_4 ( ( V_2 -> V_9 & V_10 ) != V_10 ) ;
V_2 -> V_9 &= ~ V_10 ;
V_7 -> V_9 &= ~ V_10 ;
F_2 ( L_4 , V_10 , V_7 -> V_9 ) ;
}
void F_5 ( struct V_4 * V_5 , struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = F_6 ( & V_14 -> V_17 ) ;
F_7 ( L_5 , V_5 , V_14 ) ;
F_4 ( F_8 () ) ;
F_9 ( V_12 , & V_14 -> V_17 , 0 , 0 ) ;
F_10 ( V_12 -> V_5 , V_16 ) ;
F_11 ( V_16 ) ;
V_14 -> V_17 . V_18 = V_19 ;
}
int F_12 ( struct V_4 * V_5 ,
struct V_20 * V_12 ,
struct V_13 * V_14 )
{
F_13 ( & V_5 -> V_21 ) ;
F_7 ( L_6 , V_5 , V_12 , V_14 ) ;
F_4 ( ! V_12 ) ;
if ( NULL == V_12 -> V_22 ) {
V_12 -> V_22 = V_14 ;
F_2 ( L_7 , V_14 ) ;
V_14 -> V_23 ( V_5 , V_14 , NULL ) ;
} else {
F_14 ( & V_14 -> V_17 . V_24 , & V_12 -> V_24 ) ;
V_14 -> V_17 . V_18 = V_25 ;
F_2 ( L_8 ,
V_14 ) ;
}
return 0 ;
}
void F_15 ( struct V_4 * V_5 ,
struct V_20 * V_12 ,
int V_18 )
{
F_13 ( & V_5 -> V_21 ) ;
F_7 ( L_9 , V_5 , V_12 , V_18 ) ;
F_7 ( L_10 , V_12 -> V_22 ) ;
F_4 ( ! V_12 -> V_22 ) ;
if ( NULL == V_12 -> V_22 ) {
F_2 ( L_11 ) ;
return;
}
V_12 -> V_22 -> V_17 . V_18 = V_18 ;
F_16 ( & V_12 -> V_22 -> V_17 . V_26 ) ;
F_17 ( & V_12 -> V_22 -> V_17 . V_27 ) ;
V_12 -> V_22 = NULL ;
}
void F_18 ( struct V_4 * V_5 ,
struct V_20 * V_12 , int V_28 )
{
struct V_13 * V_14 , * V_29 = NULL ;
F_4 ( ! V_12 ) ;
F_19 ( L_12 , V_5 , V_12 , V_28 ) ;
F_13 ( & V_5 -> V_21 ) ;
if ( ! F_20 ( & V_12 -> V_24 ) ) {
V_14 = F_21 ( V_12 -> V_24 . V_29 , struct V_13 , V_17 . V_24 ) ;
F_22 ( & V_14 -> V_17 . V_24 ) ;
if ( ! F_20 ( & V_12 -> V_24 ) )
V_29 = F_21 ( V_12 -> V_24 . V_29 , struct V_13 , V_17 . V_24 ) ;
V_12 -> V_22 = V_14 ;
F_19 ( L_13 ,
V_14 , V_12 -> V_24 . V_30 , V_12 -> V_24 . V_29 ) ;
V_14 -> V_23 ( V_5 , V_14 , V_29 ) ;
} else {
F_19 ( L_14 ) ;
if( 0 != V_28 ) {
F_23 ( V_5 , V_31 , V_32 ) ;
} else {
F_23 ( V_5 , V_33 , 0 ) ;
F_23 ( V_5 , V_34 , ( V_35 | V_36 ) ) ;
F_23 ( V_5 , V_37 , V_5 -> V_38 . V_39 ) ;
F_23 ( V_5 , V_31 , ( V_40 | V_41 ) ) ;
}
F_24 ( & V_12 -> V_42 ) ;
}
}
void F_25 ( unsigned long V_43 )
{
struct V_20 * V_12 = (struct V_20 * ) V_43 ;
struct V_4 * V_5 = V_12 -> V_5 ;
unsigned long V_44 ;
F_7 ( L_15 , V_5 , V_12 ) ;
F_26 ( & V_5 -> V_21 , V_44 ) ;
if ( V_12 -> V_22 ) {
F_2 ( L_16 , V_12 -> V_22 ) ;
F_15 ( V_5 , V_12 , V_45 ) ;
}
F_27 ( & V_5 -> V_21 , V_44 ) ;
}
static int F_28 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_4 * V_5 = F_30 ( V_46 ) ;
struct V_1 * V_2 = NULL ;
int V_49 = 0 ;
F_7 ( L_17 , V_46 , F_31 ( V_48 ) ) ;
if ( F_32 ( V_48 -> V_50 ) )
return - V_51 ;
F_2 ( L_18 , V_5 ) ;
if( NULL == V_5 -> V_52 ) {
F_33 ( L_19 ) ;
V_49 = - V_53 ;
goto V_54;
}
V_2 = F_34 ( sizeof( * V_2 ) , V_55 ) ;
if ( NULL == V_2 ) {
F_33 ( L_20 ) ;
V_49 = - V_56 ;
goto V_54;
}
F_35 ( & V_2 -> V_2 , V_48 ) ;
V_46 -> V_57 = & V_2 -> V_2 ;
V_2 -> V_5 = V_5 ;
if ( V_48 -> V_58 == V_59 ) {
F_33 ( L_21 ) ;
if ( V_5 -> V_60 -> V_61 & V_62 )
V_49 = V_63 . V_64 ( V_5 , V_46 ) ;
if ( V_5 -> V_60 -> V_65 . V_64 )
V_5 -> V_60 -> V_65 . V_64 ( V_46 ) ;
} else {
F_33 ( L_22 ) ;
V_49 = V_66 . V_64 ( V_5 , V_46 ) ;
}
if ( 0 != V_49 ) {
goto V_54;
}
if( 0 == F_36 ( V_5 -> V_52 -> V_67 ) ) {
V_49 = - V_68 ;
goto V_54;
}
V_49 = 0 ;
F_37 ( & V_2 -> V_2 ) ;
V_54:
if ( V_2 && V_49 != 0 ) {
F_38 ( V_2 ) ;
V_46 -> V_57 = NULL ;
}
F_39 ( V_48 -> V_50 ) ;
return V_49 ;
}
static int F_40 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_7 ( L_23 , V_46 ) ;
F_41 ( V_48 -> V_50 ) ;
if ( V_48 -> V_58 == V_59 ) {
if ( V_5 -> V_60 -> V_61 & V_62 )
V_63 . V_69 ( V_5 , V_46 ) ;
if ( V_5 -> V_60 -> V_65 . V_69 )
V_5 -> V_60 -> V_65 . V_69 ( V_46 ) ;
} else {
V_66 . V_69 ( V_5 , V_46 ) ;
}
F_42 ( & V_2 -> V_2 ) ;
F_43 ( & V_2 -> V_2 ) ;
F_44 ( V_5 -> V_52 -> V_67 ) ;
V_46 -> V_57 = NULL ;
F_38 ( V_2 ) ;
F_39 ( V_48 -> V_50 ) ;
return 0 ;
}
static int F_45 ( struct V_46 * V_46 , struct V_70 * V_71 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
struct V_11 * V_12 ;
int V_72 ;
switch ( V_48 -> V_58 ) {
case V_73 : {
F_7 ( L_24 ,
V_46 , V_71 ) ;
V_12 = & V_2 -> V_74 ;
break;
}
case V_59 : {
F_7 ( L_25 ,
V_46 , V_71 ) ;
if ( V_2 -> V_5 -> V_60 -> V_61 & V_75 )
return - V_53 ;
V_12 = & V_2 -> V_76 ;
break;
}
default:
F_46 () ;
return 0 ;
}
if ( F_32 ( V_48 -> V_50 ) )
return - V_51 ;
V_72 = F_47 ( V_12 , V_71 ) ;
F_39 ( V_48 -> V_50 ) ;
return V_72 ;
}
static unsigned int F_48 ( struct V_46 * V_46 , struct V_77 * V_78 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
struct V_79 * V_14 = NULL ;
struct V_11 * V_12 ;
unsigned int V_72 = F_49 ( V_46 , V_78 ) ;
F_7 ( L_26 , V_46 , V_78 ) ;
if ( V_48 -> V_58 == V_59 ) {
if ( V_2 -> V_5 -> V_60 -> V_61 & V_75 )
return V_72 | V_80 | V_81 ;
if( 0 == V_2 -> V_76 . V_82 )
return V_72 | F_50 ( V_46 , & V_2 -> V_76 , V_78 ) ;
V_12 = & V_2 -> V_76 ;
} else {
F_2 ( L_27 ) ;
V_12 = & V_2 -> V_74 ;
}
if ( ! F_20 ( & V_12 -> V_83 ) )
V_14 = F_21 ( V_12 -> V_83 . V_29 , struct V_79 , V_83 ) ;
if ( ! V_14 ) {
F_2 ( L_28 ) ;
return V_72 | V_84 ;
}
F_51 ( V_46 , & V_14 -> V_27 , V_78 ) ;
if ( V_14 -> V_18 == V_85 || V_14 -> V_18 == V_45 ) {
F_2 ( L_29 ) ;
return V_72 | V_86 | V_87 ;
}
F_2 ( L_30 , V_14 -> V_18 ) ;
return V_72 ;
}
static unsigned int F_52 ( struct V_46 * V_46 , struct V_77 * V_78 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
unsigned int V_72 ;
F_41 ( V_48 -> V_50 ) ;
V_72 = F_48 ( V_46 , V_78 ) ;
F_39 ( V_48 -> V_50 ) ;
return V_72 ;
}
static T_1 F_53 ( struct V_46 * V_46 , char T_2 * V_43 , T_3 V_88 , T_4 * V_89 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
int V_90 ;
switch ( V_48 -> V_58 ) {
case V_73 :
return V_66 . V_91 ( V_46 , V_43 , V_88 , V_89 ) ;
case V_59 :
if ( V_2 -> V_5 -> V_60 -> V_61 & V_62 ) {
if ( F_32 ( V_48 -> V_50 ) )
return - V_51 ;
V_90 = V_63 . V_91 ( V_46 , V_43 , V_88 , V_89 ) ;
F_39 ( V_48 -> V_50 ) ;
return V_90 ;
}
return - V_68 ;
default:
F_46 () ;
return 0 ;
}
}
static T_1 F_54 ( struct V_46 * V_46 , const char T_2 * V_43 , T_3 V_88 , T_4 * V_89 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
int V_90 ;
switch ( V_48 -> V_58 ) {
case V_73 :
return - V_68 ;
case V_59 :
if ( V_2 -> V_5 -> V_60 -> V_65 . V_92 ) {
if ( F_32 ( V_48 -> V_50 ) )
return - V_51 ;
V_90 = V_2 -> V_5 -> V_60 -> V_65 . V_92 ( V_46 , V_43 , V_88 , V_89 ) ;
F_39 ( V_48 -> V_50 ) ;
return V_90 ;
}
return - V_68 ;
default:
F_46 () ;
return - V_68 ;
}
}
static void F_55 ( struct V_4 * V_5 , unsigned long V_93 )
{
T_5 V_94 = V_93 ;
F_19 ( L_31 , V_5 , ( T_5 ) V_93 ) ;
if ( 0 != ( V_94 & ( V_95 ) ) ) {
F_19 ( L_32 , V_94 ) ;
V_66 . V_96 ( V_5 , V_94 ) ;
}
if ( 0 != ( V_94 & ( V_41 ) ) ) {
T_5 V_97 = F_56 ( V_5 , V_34 ) ;
if( 0 != ( V_97 & V_98 ) ) {
F_19 ( L_33 , V_94 ) ;
F_17 ( & V_5 -> V_8 -> V_99 ) ;
F_23 ( V_5 , V_34 , V_100 ) ;
return;
}
F_19 ( L_34 , V_94 ) ;
V_63 . V_96 ( V_5 , V_94 ) ;
}
}
int F_57 ( struct V_4 * V_5 , struct V_101 * V_102 )
{
struct V_103 * V_104 = & V_5 -> V_105 ;
struct V_106 * V_107 ;
struct V_108 * V_28 ;
struct V_6 * V_7 ;
int V_109 ;
V_109 = F_58 ( & V_5 -> V_110 -> V_5 , & V_5 -> V_111 ) ;
if ( V_109 )
return V_109 ;
F_59 ( V_104 , 6 ) ;
F_60 ( V_104 , & V_112 ,
V_113 , 0 , 255 , 1 , 128 ) ;
F_60 ( V_104 , & V_112 ,
V_114 , 0 , 127 , 1 , 64 ) ;
F_60 ( V_104 , & V_112 ,
V_115 , 0 , 127 , 1 , 64 ) ;
F_60 ( V_104 , & V_112 ,
V_116 , 0 , 1 , 1 , 0 ) ;
F_60 ( V_104 , & V_112 ,
V_117 , 0 , 1 , 1 , 0 ) ;
if ( V_104 -> error ) {
V_109 = V_104 -> error ;
F_61 ( V_104 ) ;
return V_109 ;
}
V_5 -> V_111 . V_105 = V_104 ;
V_7 = F_34 ( sizeof( struct V_6 ) , V_55 ) ;
if ( V_7 == NULL ) {
F_62 ( L_35 ) ;
F_61 ( V_104 ) ;
return - V_56 ;
}
V_102 -> V_118 = V_119 ;
V_102 -> V_120 = V_121 ;
V_102 -> V_122 = & V_119 ;
F_7 ( L_36 , V_5 ) ;
F_23 ( V_5 , V_123 , 0x80400040 ) ;
F_23 ( V_5 , V_31 , ( V_124 | V_125 ) ) ;
V_5 -> V_60 = V_102 ;
V_7 -> V_126 . V_127 =
F_63 ( V_5 -> V_110 , V_128 ,
& V_7 -> V_126 . V_39 ) ;
if( NULL == V_7 -> V_126 . V_127 ) {
F_62 ( L_35 ) ;
F_38 ( V_7 ) ;
F_61 ( V_104 ) ;
return - 1 ;
}
V_66 . V_129 ( V_5 , V_7 ) ;
if ( V_5 -> V_60 -> V_61 & V_62 )
V_63 . V_129 ( V_5 , V_7 ) ;
V_7 -> V_130 . V_107 . V_131 = V_7 -> V_132 -> V_133 ;
V_7 -> V_130 . V_107 . V_134 = V_7 -> V_132 -> V_135 ;
V_7 -> V_130 . V_107 . V_136 = V_137 ;
V_7 -> V_130 . V_107 . V_138 = 2 * V_7 -> V_130 . V_107 . V_131 ;
V_7 -> V_130 . V_107 . V_139 = V_7 -> V_130 . V_107 . V_138 * V_7 -> V_130 . V_107 . V_134 ;
V_7 -> V_130 . V_107 . V_140 = V_141 ;
V_107 = & V_7 -> V_142 ;
V_107 -> V_131 = 384 ;
V_107 -> V_134 = 288 ;
V_107 -> V_136 = V_143 ;
V_107 -> V_144 = V_145 ;
V_107 -> V_140 = V_146 ;
V_107 -> V_138 = 3 * V_107 -> V_131 ;
V_107 -> V_139 = V_107 -> V_138 * V_107 -> V_134 ;
V_28 = & V_7 -> V_147 ;
V_28 -> V_148 = 27000000 ;
V_28 -> V_149 = 248 ;
V_28 -> V_150 = 720 * 2 ;
V_28 -> V_151 = V_152 ;
V_28 -> V_153 [ 0 ] = 5 ;
V_28 -> V_88 [ 0 ] = 16 ;
V_28 -> V_153 [ 1 ] = 312 ;
V_28 -> V_88 [ 1 ] = 16 ;
F_64 ( & V_7 -> V_154 ) ;
V_7 -> V_130 . V_155 = V_156 ;
V_7 -> V_130 . V_44 = V_157 ;
V_5 -> V_8 = V_7 ;
V_5 -> F_55 = & F_55 ;
return 0 ;
}
int F_65 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_7 ( L_36 , V_5 ) ;
F_66 ( & V_5 -> V_111 ) ;
F_67 ( V_5 -> V_110 , V_128 , V_7 -> V_126 . V_127 , V_7 -> V_126 . V_39 ) ;
F_61 ( & V_5 -> V_105 ) ;
F_38 ( V_7 ) ;
V_5 -> V_8 = NULL ;
V_5 -> F_55 = NULL ;
return 0 ;
}
int F_68 ( struct V_47 * * V_158 , struct V_4 * V_5 ,
char * V_159 , int type )
{
struct V_47 * V_160 ;
int V_109 ;
int V_161 ;
F_7 ( L_37 , V_5 , V_159 , type ) ;
V_160 = F_69 () ;
if ( V_160 == NULL )
return - V_56 ;
V_160 -> V_162 = & V_163 ;
if ( type == V_73 )
V_160 -> V_164 = & V_5 -> V_60 -> V_118 ;
else
V_160 -> V_164 = & V_5 -> V_60 -> V_120 ;
V_160 -> V_69 = V_165 ;
V_160 -> V_50 = & V_5 -> V_166 ;
V_160 -> V_111 = & V_5 -> V_111 ;
V_160 -> V_167 = 0 ;
for ( V_161 = 0 ; V_161 < V_5 -> V_60 -> V_168 ; V_161 ++ )
V_160 -> V_167 |= V_5 -> V_60 -> V_169 [ V_161 ] . V_170 ;
F_70 ( V_160 -> V_159 , V_159 , sizeof( V_160 -> V_159 ) ) ;
F_71 ( V_160 , V_5 ) ;
V_109 = F_72 ( V_160 , type , - 1 ) ;
if ( V_109 < 0 ) {
F_62 ( L_38 ) ;
V_165 ( V_160 ) ;
return V_109 ;
}
F_73 ( L_39 ,
V_5 -> V_159 , F_31 ( V_160 ) ) ;
* V_158 = V_160 ;
return 0 ;
}
int F_74 ( struct V_47 * * V_158 , struct V_4 * V_5 )
{
F_7 ( L_36 , V_5 ) ;
F_75 ( * V_158 ) ;
* V_158 = NULL ;
return 0 ;
}
static int T_6 F_76 ( void )
{
return 0 ;
}
static void T_7 F_77 ( void )
{
}
