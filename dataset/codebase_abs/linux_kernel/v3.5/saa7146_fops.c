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
if ( F_32 ( & V_50 ) )
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
F_39 ( & V_50 ) ;
return V_49 ;
}
static int F_40 ( struct V_46 * V_46 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_7 ( L_23 , V_46 ) ;
if ( F_32 ( & V_50 ) )
return - V_51 ;
if ( V_48 -> V_58 == V_59 ) {
if ( V_5 -> V_60 -> V_61 & V_62 )
V_63 . V_69 ( V_5 , V_46 ) ;
if ( V_5 -> V_60 -> V_65 . V_69 )
V_5 -> V_60 -> V_65 . V_69 ( V_46 ) ;
} else {
V_66 . V_69 ( V_5 , V_46 ) ;
}
F_41 ( & V_2 -> V_2 ) ;
F_42 ( & V_2 -> V_2 ) ;
F_43 ( V_5 -> V_52 -> V_67 ) ;
V_46 -> V_57 = NULL ;
F_38 ( V_2 ) ;
F_39 ( & V_50 ) ;
return 0 ;
}
static int F_44 ( struct V_46 * V_46 , struct V_70 * V_71 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
struct V_11 * V_12 ;
switch ( V_48 -> V_58 ) {
case V_72 : {
F_7 ( L_24 ,
V_46 , V_71 ) ;
V_12 = & V_2 -> V_73 ;
break;
}
case V_59 : {
F_7 ( L_25 ,
V_46 , V_71 ) ;
if ( V_2 -> V_5 -> V_60 -> V_61 & V_74 )
return - V_53 ;
V_12 = & V_2 -> V_75 ;
break;
}
default:
F_45 () ;
return 0 ;
}
return F_46 ( V_12 , V_71 ) ;
}
static unsigned int F_47 ( struct V_46 * V_46 , struct V_76 * V_77 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
struct V_78 * V_14 = NULL ;
struct V_11 * V_12 ;
unsigned int V_79 = F_48 ( V_46 , V_77 ) ;
F_7 ( L_26 , V_46 , V_77 ) ;
if ( V_48 -> V_58 == V_59 ) {
if ( V_2 -> V_5 -> V_60 -> V_61 & V_74 )
return V_79 | V_80 | V_81 ;
if( 0 == V_2 -> V_75 . V_82 )
return V_79 | F_49 ( V_46 , & V_2 -> V_75 , V_77 ) ;
V_12 = & V_2 -> V_75 ;
} else {
F_2 ( L_27 ) ;
V_12 = & V_2 -> V_73 ;
}
if ( ! F_20 ( & V_12 -> V_83 ) )
V_14 = F_21 ( V_12 -> V_83 . V_29 , struct V_78 , V_83 ) ;
if ( ! V_14 ) {
F_2 ( L_28 ) ;
return V_79 | V_84 ;
}
F_50 ( V_46 , & V_14 -> V_27 , V_77 ) ;
if ( V_14 -> V_18 == V_85 || V_14 -> V_18 == V_45 ) {
F_2 ( L_29 ) ;
return V_79 | V_86 | V_87 ;
}
F_2 ( L_30 , V_14 -> V_18 ) ;
return V_79 ;
}
static T_1 F_51 ( struct V_46 * V_46 , char T_2 * V_43 , T_3 V_88 , T_4 * V_89 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
switch ( V_48 -> V_58 ) {
case V_72 :
return V_66 . V_90 ( V_46 , V_43 , V_88 , V_89 ) ;
case V_59 :
if ( V_2 -> V_5 -> V_60 -> V_61 & V_62 )
return V_63 . V_90 ( V_46 , V_43 , V_88 , V_89 ) ;
return - V_68 ;
default:
F_45 () ;
return 0 ;
}
}
static T_1 F_52 ( struct V_46 * V_46 , const char T_2 * V_43 , T_3 V_88 , T_4 * V_89 )
{
struct V_47 * V_48 = F_29 ( V_46 ) ;
struct V_1 * V_2 = V_46 -> V_57 ;
switch ( V_48 -> V_58 ) {
case V_72 :
return - V_68 ;
case V_59 :
if ( V_2 -> V_5 -> V_60 -> V_65 . V_91 )
return V_2 -> V_5 -> V_60 -> V_65 . V_91 ( V_46 , V_43 , V_88 , V_89 ) ;
else
return - V_68 ;
default:
F_45 () ;
return - V_68 ;
}
}
static void F_53 ( struct V_4 * V_5 , unsigned long V_92 )
{
T_5 V_93 = V_92 ;
F_19 ( L_31 , V_5 , ( T_5 ) V_92 ) ;
if ( 0 != ( V_93 & ( V_94 ) ) ) {
F_19 ( L_32 , V_93 ) ;
V_66 . V_95 ( V_5 , V_93 ) ;
}
if ( 0 != ( V_93 & ( V_41 ) ) ) {
T_5 V_96 = F_54 ( V_5 , V_34 ) ;
if( 0 != ( V_96 & V_97 ) ) {
F_19 ( L_33 , V_93 ) ;
F_17 ( & V_5 -> V_8 -> V_98 ) ;
F_23 ( V_5 , V_34 , V_99 ) ;
return;
}
F_19 ( L_34 , V_93 ) ;
V_63 . V_95 ( V_5 , V_93 ) ;
}
}
int F_55 ( struct V_4 * V_5 , struct V_100 * V_101 )
{
struct V_102 * V_103 = & V_5 -> V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_28 ;
struct V_6 * V_7 ;
int V_108 ;
V_108 = F_56 ( & V_5 -> V_109 -> V_5 , & V_5 -> V_110 ) ;
if ( V_108 )
return V_108 ;
F_57 ( V_103 , 6 ) ;
F_58 ( V_103 , & V_111 ,
V_112 , 0 , 255 , 1 , 128 ) ;
F_58 ( V_103 , & V_111 ,
V_113 , 0 , 127 , 1 , 64 ) ;
F_58 ( V_103 , & V_111 ,
V_114 , 0 , 127 , 1 , 64 ) ;
F_58 ( V_103 , & V_111 ,
V_115 , 0 , 1 , 1 , 0 ) ;
F_58 ( V_103 , & V_111 ,
V_116 , 0 , 1 , 1 , 0 ) ;
if ( V_103 -> error ) {
V_108 = V_103 -> error ;
F_59 ( V_103 ) ;
return V_108 ;
}
V_5 -> V_110 . V_104 = V_103 ;
V_7 = F_34 ( sizeof( struct V_6 ) , V_55 ) ;
if ( V_7 == NULL ) {
F_60 ( L_35 ) ;
F_59 ( V_103 ) ;
return - V_56 ;
}
V_101 -> V_117 = V_118 ;
V_101 -> V_119 = V_120 ;
V_101 -> V_121 = & V_118 ;
F_7 ( L_36 , V_5 ) ;
F_23 ( V_5 , V_122 , 0x80400040 ) ;
F_23 ( V_5 , V_31 , ( V_123 | V_124 ) ) ;
V_5 -> V_60 = V_101 ;
V_7 -> V_125 . V_126 = F_61 ( V_5 -> V_109 , V_127 , & V_7 -> V_125 . V_39 ) ;
if( NULL == V_7 -> V_125 . V_126 ) {
F_60 ( L_35 ) ;
F_38 ( V_7 ) ;
F_59 ( V_103 ) ;
return - 1 ;
}
memset ( V_7 -> V_125 . V_126 , 0x0 , V_127 ) ;
V_66 . V_128 ( V_5 , V_7 ) ;
if ( V_5 -> V_60 -> V_61 & V_62 )
V_63 . V_128 ( V_5 , V_7 ) ;
V_106 = & V_7 -> V_129 . V_106 ;
V_106 -> V_130 = V_7 -> V_131 -> V_132 ;
V_106 -> V_133 = V_7 -> V_131 -> V_134 ;
V_106 -> V_135 = V_136 ;
V_106 -> V_137 = 2 * V_106 -> V_130 ;
V_106 -> V_138 = V_106 -> V_137 * V_106 -> V_133 ;
V_106 -> V_139 = V_140 ;
V_106 = & V_7 -> V_141 ;
V_106 -> V_130 = 384 ;
V_106 -> V_133 = 288 ;
V_106 -> V_135 = V_142 ;
V_106 -> V_143 = V_144 ;
V_106 -> V_139 = V_145 ;
V_106 -> V_137 = 3 * V_106 -> V_130 ;
V_106 -> V_138 = V_106 -> V_137 * V_106 -> V_133 ;
V_28 = & V_7 -> V_146 ;
V_28 -> V_147 = 27000000 ;
V_28 -> V_148 = 248 ;
V_28 -> V_149 = 720 * 2 ;
V_28 -> V_150 = V_151 ;
V_28 -> V_152 [ 0 ] = 5 ;
V_28 -> V_88 [ 0 ] = 16 ;
V_28 -> V_152 [ 1 ] = 312 ;
V_28 -> V_88 [ 1 ] = 16 ;
F_62 ( & V_7 -> V_153 ) ;
V_7 -> V_129 . V_154 = V_155 ;
V_7 -> V_129 . V_44 = V_156 ;
V_5 -> V_8 = V_7 ;
V_5 -> F_53 = & F_53 ;
return 0 ;
}
int F_63 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 ;
F_7 ( L_36 , V_5 ) ;
F_64 ( & V_5 -> V_110 ) ;
F_65 ( V_5 -> V_109 , V_127 , V_7 -> V_125 . V_126 , V_7 -> V_125 . V_39 ) ;
F_59 ( & V_5 -> V_104 ) ;
F_38 ( V_7 ) ;
V_5 -> V_8 = NULL ;
V_5 -> F_53 = NULL ;
return 0 ;
}
int F_66 ( struct V_47 * * V_157 , struct V_4 * V_5 ,
char * V_158 , int type )
{
struct V_47 * V_159 ;
int V_108 ;
int V_160 ;
F_7 ( L_37 , V_5 , V_158 , type ) ;
V_159 = F_67 () ;
if ( V_159 == NULL )
return - V_56 ;
V_159 -> V_161 = & V_162 ;
if ( type == V_72 )
V_159 -> V_163 = & V_5 -> V_60 -> V_117 ;
else
V_159 -> V_163 = & V_5 -> V_60 -> V_119 ;
V_159 -> V_69 = V_164 ;
F_68 ( V_165 , & V_159 -> V_44 ) ;
V_159 -> V_166 = & V_5 -> V_167 ;
V_159 -> V_110 = & V_5 -> V_110 ;
V_159 -> V_168 = 0 ;
F_68 ( V_169 , & V_159 -> V_44 ) ;
for ( V_160 = 0 ; V_160 < V_5 -> V_60 -> V_170 ; V_160 ++ )
V_159 -> V_168 |= V_5 -> V_60 -> V_171 [ V_160 ] . V_172 ;
F_69 ( V_159 -> V_158 , V_158 , sizeof( V_159 -> V_158 ) ) ;
F_70 ( V_159 , V_5 ) ;
V_108 = F_71 ( V_159 , type , - 1 ) ;
if ( V_108 < 0 ) {
F_60 ( L_38 ) ;
V_164 ( V_159 ) ;
return V_108 ;
}
F_72 ( L_39 ,
V_5 -> V_158 , F_31 ( V_159 ) ) ;
* V_157 = V_159 ;
return 0 ;
}
int F_73 ( struct V_47 * * V_157 , struct V_4 * V_5 )
{
F_7 ( L_36 , V_5 ) ;
F_74 ( * V_157 ) ;
* V_157 = NULL ;
return 0 ;
}
static int T_6 F_75 ( void )
{
return 0 ;
}
static void T_7 F_76 ( void )
{
}
