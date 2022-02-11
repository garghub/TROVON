static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 ;
F_2 ( V_1 , & V_2 ) ;
return V_2 ;
}
static T_2 F_3 ( T_1 V_1 )
{
return ( T_2 ) F_1 ( V_1 ) ;
}
static T_3 F_4 ( T_1 V_1 )
{
int V_3 , V_4 ;
V_4 = F_1 ( V_1 ) ;
V_3 = F_1 ( V_1 + 1 ) ;
return ( V_3 << 8 ) + V_4 ;
}
static T_4 F_5 ( T_1 V_1 )
{
return ( T_4 ) F_4 ( V_1 ) ;
}
static void F_6 ( T_1 V_1 , T_1 * V_5 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
F_2 ( V_1 + V_7 , V_5 + V_7 ) ;
}
static int F_7 ( int V_8 )
{
if ( V_8 < 0 || V_8 > V_9 )
return - V_10 ;
F_8 ( V_11 , V_8 ) ;
return 0 ;
}
static int F_9 ( void )
{
return ( int ) F_1 ( V_11 ) ;
}
static void F_10 ( bool V_12 )
{
T_1 V_13 = V_12 ? V_14 : V_15 ;
F_11 ( V_16 , & V_13 , 1 , NULL , 0 ) ;
}
static void F_12 ( void )
{
unsigned char V_17 = V_18 ;
F_11 ( V_19 , & V_17 , 1 , NULL , 0 ) ;
}
static void F_13 ( void )
{
unsigned char V_17 = V_20 ;
F_11 ( V_21 , & V_17 , 1 , NULL , 0 ) ;
}
static void F_14 ( int V_22 )
{
F_11 ( V_23 , & V_24 [ V_22 ] , 1 , NULL , 0 ) ;
}
static int F_15 ( void )
{
T_1 V_2 , V_13 = V_25 ;
F_11 ( V_26 , & V_13 , 1 , & V_2 , 1 ) ;
return 100 * ( int ) V_2 ;
}
static int F_16 ( struct V_27 * V_28 )
{
return F_9 () ;
}
static int F_17 ( struct V_27 * V_28 )
{
int V_29 = F_7 ( V_28 -> V_30 . V_31 ) ;
if ( V_29 )
return V_29 ;
F_10 ( ( V_28 -> V_30 . V_32 == V_33 )
&& ! ( V_28 -> V_30 . V_34 & V_35 )
&& ! ( V_28 -> V_30 . V_34 & V_36 ) ) ;
return 0 ;
}
static int F_18 ( void * V_13 , bool V_37 )
{
unsigned long V_38 = ( unsigned long ) V_13 ;
T_1 V_39 = F_1 ( V_40 ) ;
T_1 V_2 ;
if ( ! V_37 )
V_2 = ( T_1 ) ( V_39 | V_38 ) ;
else
V_2 = ( T_1 ) ( V_39 & ~ V_38 ) ;
F_8 ( V_40 , V_2 ) ;
return 0 ;
}
static void F_19 ( struct V_41 * V_41 , void * V_13 )
{
T_1 V_39 = F_1 ( V_40 ) ;
bool V_42 = ! ( V_39 & V_43 ) ;
F_20 ( V_41 , V_42 ) ;
}
static T_5 F_21 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_5 )
{
struct V_48 * V_13 = F_22 ( V_45 ) ;
return sprintf ( V_5 , L_1 , V_13 -> V_49 ) ;
}
static T_5 F_23 ( struct V_44 * V_45 ,
struct V_46 * V_47 , const char * V_5 , T_6 V_50 )
{
struct V_48 * V_13 = F_22 ( V_45 ) ;
long V_51 ;
int V_52 ;
V_52 = F_24 ( V_5 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
if ( V_51 < 0 )
return - V_10 ;
V_13 -> V_49 = V_51 ;
switch ( V_51 ) {
case 0 :
F_12 () ;
F_14 ( 255 ) ;
break;
case 1 :
F_12 () ;
F_14 ( V_13 -> V_53 ) ;
break;
default:
F_13 () ;
break;
}
return V_50 ;
}
static T_5 F_25 ( struct V_44 * V_45 , struct V_46 * V_47 ,
char * V_5 )
{
struct V_48 * V_13 = F_22 ( V_45 ) ;
return sprintf ( V_5 , L_2 , V_13 -> V_53 ) ;
}
static T_5 F_26 ( struct V_44 * V_45 , struct V_46 * V_47 ,
const char * V_5 , T_6 V_50 )
{
struct V_48 * V_13 = F_22 ( V_45 ) ;
long V_51 ;
int V_52 ;
V_52 = F_24 ( V_5 , 10 , & V_51 ) ;
if ( V_52 )
return V_52 ;
if ( V_51 < 0 || V_51 > 255 )
return - V_10 ;
V_13 -> V_53 = V_51 ;
if ( V_13 -> V_49 != 1 )
return V_50 ;
F_14 ( V_51 ) ;
return V_50 ;
}
static T_5 F_27 ( struct V_44 * V_45 , struct V_46 * V_47 ,
char * V_5 )
{
return sprintf ( V_5 , L_1 , F_15 () ) ;
}
static int F_28 ( void )
{
T_1 V_54 = F_1 ( V_55 ) ;
T_1 V_56 = F_1 ( V_57 ) ;
if ( V_54 & V_58 )
return V_59 ;
if ( V_54 & V_60 )
return V_61 ;
if ( V_56 & V_62 )
return V_63 ;
return V_64 ;
}
static int F_29 ( void )
{
T_1 V_65 = F_1 ( V_66 ) ;
if ( V_65 & V_67 )
return V_68 ;
if ( V_65 & V_69 )
return V_70 ;
if ( V_65 & V_71 )
return V_72 ;
if ( V_65 & V_73 )
return V_74 ;
return V_75 ;
}
static int F_30 ( void )
{
T_1 V_65 = F_1 ( V_76 ) ;
return ( ( V_65 & V_77 ) != 0 ) ;
}
static int F_31 ( void )
{
T_1 V_65 = F_1 ( V_57 ) ;
if ( V_65 & V_78 )
return V_79 ;
return V_80 ;
}
static int F_32 ( void )
{
T_1 V_54 = F_1 ( V_55 ) ;
T_1 V_56 = F_1 ( V_57 ) ;
T_1 V_81 = F_1 ( V_76 ) ;
if ( V_54 & V_82
|| V_56 & V_83
|| V_81 & V_84 )
return V_85 ;
if ( V_54 & V_86 )
return V_87 ;
if ( V_56 & V_62 )
return V_88 ;
return V_89 ;
}
static int F_33 ( struct V_90 * V_91 ,
enum V_92 V_93 ,
union V_94 * V_51 )
{
struct V_48 * V_13 = F_34 ( V_91 ) ;
switch ( V_93 ) {
case V_95 :
V_51 -> V_96 = F_28 () ;
break;
case V_97 :
V_51 -> V_96 = F_29 () ;
break;
case V_98 :
V_51 -> V_96 = F_30 () ;
break;
case V_99 :
V_51 -> V_96 = F_31 () ;
break;
case V_100 :
V_51 -> V_96 = F_4 ( V_101 ) * 1000 ;
break;
case V_102 :
V_51 -> V_96 = F_4 ( V_103 ) * 1000 ;
break;
case V_104 :
V_51 -> V_96 = F_5 ( V_105 ) * 1000 ;
break;
case V_106 :
V_51 -> V_96 = F_5 ( V_107 ) * 1000 ;
break;
case V_108 :
V_51 -> V_96 = F_1 ( V_109 ) * 1000000 ;
break;
case V_110 :
V_51 -> V_96 = F_4 ( V_111 ) * 1000 ;
break;
case V_112 :
V_51 -> V_96 = F_4 ( V_113 ) * 1000 ;
break;
case V_114 :
V_51 -> V_96 = F_1 ( V_115 ) ;
break;
case V_116 :
V_51 -> V_96 = V_117 ;
break;
case V_118 :
V_51 -> V_96 = F_1 ( V_119 ) ;
break;
case V_120 :
V_51 -> V_96 = F_32 () ;
break;
case V_121 :
V_51 -> V_96 = ( ( 222 - ( int ) F_1 ( V_122 ) ) * 1000 ) >> 8 ;
break;
case V_123 :
V_51 -> V_96 = F_3 ( V_124 ) * 10 ;
break;
case V_125 :
V_51 -> V_126 = V_13 -> V_127 ;
break;
case V_128 :
V_51 -> V_126 = V_13 -> V_129 ;
break;
case V_130 :
V_51 -> V_126 = V_13 -> V_131 ;
break;
default:
break;
}
return 0 ;
}
static int F_35 ( struct V_90 * V_91 ,
enum V_92 V_93 ,
const union V_94 * V_51 )
{
int V_8 ;
switch ( V_93 ) {
case V_114 :
V_8 = V_51 -> V_96 ;
if ( V_8 < 0 || V_8 > V_117 )
return - V_10 ;
if ( F_8 ( V_115 , V_8 ) < 0 )
return - V_132 ;
break;
default:
break;
}
return 0 ;
}
static int F_36 ( struct V_90 * V_91 ,
enum V_92 V_93 )
{
switch ( V_93 ) {
case V_114 :
return 1 ;
default:
return 0 ;
}
}
static int F_37 ( const struct V_133 * V_134 )
{
F_38 ( L_3 , V_134 -> V_135 ) ;
V_136 = false ;
return 1 ;
}
static int F_39 ( const struct V_133 * V_134 )
{
F_38 ( L_4 ,
V_134 -> V_135 ) ;
V_136 = true ;
return 1 ;
}
static void F_40 ( struct V_48 * V_13 )
{
F_6 ( V_137 ,
V_13 -> V_129 ,
V_138 ) ;
V_13 -> V_129 [ V_138 ] = 0 ;
F_6 ( V_139 ,
V_13 -> V_127 ,
V_140 ) ;
V_13 -> V_127 [ V_140 ] = 0 ;
F_41 ( V_13 -> V_131 , V_141 + 1 , L_5 ,
F_4 ( V_142 ) ) ;
}
static void F_42 ( struct V_48 * V_13 )
{
V_13 -> V_49 = 2 ;
V_13 -> V_53 = 255 ;
}
static int F_43 ( void )
{
int V_29 ;
V_143 = F_44 ( L_6 , & V_144 -> V_45 ,
V_145 , & V_146 ,
( void * ) V_147 ) ;
if ( ! V_143 )
return - V_148 ;
V_29 = F_45 ( V_143 ) ;
if ( V_29 )
goto V_149;
V_150 = F_44 ( L_7 , & V_144 -> V_45 ,
V_151 , & V_146 ,
( void * ) V_152 ) ;
if ( ! V_150 ) {
V_29 = - V_148 ;
goto V_153;
}
V_29 = F_45 ( V_150 ) ;
if ( V_29 )
goto V_154;
return 0 ;
V_154:
F_46 ( V_150 ) ;
V_153:
F_47 ( V_143 ) ;
V_149:
F_46 ( V_143 ) ;
return V_29 ;
}
static int T_7 F_48 ( void )
{
int V_29 ;
if ( V_155 ) {
F_49 ( L_8 ) ;
return - V_156 ;
}
if ( ! V_157 && ! F_50 ( V_158 ) ) {
F_49 ( L_9 ) ;
return - V_156 ;
}
if ( F_51 () == V_159 ) {
struct V_160 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_160 ) ) ;
V_30 . type = V_161 ;
V_30 . V_162 = V_9 ;
V_163 = F_52 ( V_164 ,
NULL , NULL ,
& V_165 ,
& V_30 ) ;
if ( F_53 ( V_163 ) )
return F_54 ( V_163 ) ;
}
V_29 = F_55 ( & V_166 ) ;
if ( V_29 )
goto V_167;
V_144 = F_56 ( V_164 , - 1 ) ;
if ( ! V_144 ) {
V_29 = - V_148 ;
goto V_168;
}
V_29 = F_57 ( V_144 ) ;
if ( V_29 )
goto V_169;
V_29 = F_43 () ;
if ( V_29 )
goto V_170;
F_38 ( L_10 V_171 L_11 ) ;
return 0 ;
V_170:
F_58 ( V_144 ) ;
V_169:
F_59 ( V_144 ) ;
V_168:
F_60 ( & V_166 ) ;
V_167:
F_61 ( V_163 ) ;
return V_29 ;
}
static int F_62 ( struct V_172 * V_173 )
{
int V_52 ;
struct V_48 * V_13 ;
struct V_44 * V_174 ;
struct V_175 V_176 = {} ;
if ( ! V_136 )
return 0 ;
V_13 = F_63 ( & V_173 -> V_45 , sizeof( struct V_48 ) , V_177 ) ;
if ( ! V_13 )
return - V_148 ;
F_42 ( V_13 ) ;
V_52 = F_64 ( & V_173 -> V_45 . V_178 , & V_179 ) ;
if ( V_52 )
return V_52 ;
V_174 = F_65 ( & V_173 -> V_45 ,
L_12 , V_13 ,
V_180 ) ;
if ( F_53 ( V_174 ) ) {
V_52 = F_54 ( V_174 ) ;
goto remove;
}
F_40 ( V_13 ) ;
V_176 . V_181 = V_13 ;
V_13 -> V_91 = F_66 ( & V_144 -> V_45 , & V_182 ,
& V_176 ) ;
if ( F_53 ( V_13 -> V_91 ) ) {
V_52 = F_54 ( V_13 -> V_91 ) ;
goto remove;
}
F_67 ( V_173 , V_13 ) ;
return 0 ;
remove:
F_68 ( & V_173 -> V_45 . V_178 , & V_179 ) ;
return V_52 ;
}
static void T_8 F_69 ( void )
{
F_70 ( V_144 ) ;
F_60 ( & V_166 ) ;
F_61 ( V_163 ) ;
F_47 ( V_143 ) ;
F_47 ( V_150 ) ;
F_46 ( V_143 ) ;
F_46 ( V_150 ) ;
F_38 ( L_13 ) ;
}
static int F_71 ( struct V_172 * V_173 )
{
struct V_48 * V_13 ;
if ( ! V_136 )
return 0 ;
F_38 ( L_14 ) ;
F_13 () ;
V_13 = F_72 ( V_173 ) ;
F_73 ( V_13 -> V_91 ) ;
F_68 ( & V_173 -> V_45 . V_178 , & V_179 ) ;
return 0 ;
}
