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
struct V_48 * V_13 ;
V_13 = F_34 ( V_91 , struct V_48 , V_91 ) ;
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
V_51 -> V_96 = F_32 () ;
break;
case V_117 :
V_51 -> V_96 = ( ( 222 - ( int ) F_1 ( V_118 ) ) * 1000 ) >> 8 ;
break;
case V_119 :
V_51 -> V_96 = F_3 ( V_120 ) * 10 ;
break;
case V_121 :
V_51 -> V_122 = V_13 -> V_123 ;
break;
case V_124 :
V_51 -> V_122 = V_13 -> V_125 ;
break;
case V_126 :
V_51 -> V_122 = V_13 -> V_127 ;
break;
default:
break;
}
return 0 ;
}
static int F_35 ( const struct V_128 * V_129 )
{
F_36 ( L_3 , V_129 -> V_130 ) ;
V_131 = false ;
return 1 ;
}
static int F_37 ( const struct V_128 * V_129 )
{
F_36 ( L_4 ,
V_129 -> V_130 ) ;
V_131 = true ;
return 1 ;
}
static void F_38 ( struct V_48 * V_13 )
{
V_13 -> V_91 . V_132 = V_133 ;
V_13 -> V_91 . type = V_134 ;
V_13 -> V_91 . V_135 = V_136 ;
V_13 -> V_91 . V_137 = F_39 ( V_136 ) ;
V_13 -> V_91 . V_138 = F_33 ;
F_6 ( V_139 ,
V_13 -> V_125 ,
V_140 ) ;
V_13 -> V_125 [ V_140 ] = 0 ;
F_6 ( V_141 ,
V_13 -> V_123 ,
V_142 ) ;
V_13 -> V_123 [ V_142 ] = 0 ;
F_40 ( V_13 -> V_127 , V_143 + 1 , L_5 ,
F_4 ( V_144 ) ) ;
}
static void F_41 ( struct V_48 * V_13 )
{
V_13 -> V_49 = 2 ;
V_13 -> V_53 = 255 ;
}
static int F_42 ( void )
{
int V_29 ;
V_145 = F_43 ( L_6 , & V_146 -> V_45 ,
V_147 , & V_148 ,
( void * ) V_149 ) ;
if ( ! V_145 )
return - V_150 ;
V_29 = F_44 ( V_145 ) ;
if ( V_29 )
goto V_151;
V_152 = F_43 ( L_7 , & V_146 -> V_45 ,
V_153 , & V_148 ,
( void * ) V_154 ) ;
if ( ! V_152 ) {
V_29 = - V_150 ;
goto V_155;
}
V_29 = F_44 ( V_152 ) ;
if ( V_29 )
goto V_156;
return 0 ;
V_156:
F_45 ( V_152 ) ;
V_155:
F_46 ( V_145 ) ;
V_151:
F_45 ( V_145 ) ;
return V_29 ;
}
static int T_7 F_47 ( void )
{
int V_29 ;
if ( V_157 ) {
F_48 ( L_8 ) ;
return - V_158 ;
}
if ( ! V_159 && ! F_49 ( V_160 ) ) {
F_48 ( L_9 ) ;
return - V_158 ;
}
if ( ! F_50 () ) {
struct V_161 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_161 ) ) ;
V_30 . type = V_162 ;
V_30 . V_163 = V_9 ;
V_164 = F_51 ( V_133 ,
NULL , NULL ,
& V_165 ,
& V_30 ) ;
if ( F_52 ( V_164 ) )
return F_53 ( V_164 ) ;
}
V_29 = F_54 ( & V_166 ) ;
if ( V_29 )
goto V_167;
V_146 = F_55 ( V_133 , - 1 ) ;
if ( ! V_146 ) {
V_29 = - V_150 ;
goto V_168;
}
V_29 = F_56 ( V_146 ) ;
if ( V_29 )
goto V_169;
V_29 = F_42 () ;
if ( V_29 )
goto V_170;
F_36 ( L_10 V_171 L_11 ) ;
return 0 ;
V_170:
F_57 ( V_146 ) ;
V_169:
F_58 ( V_146 ) ;
V_168:
F_59 ( & V_166 ) ;
V_167:
F_60 ( V_164 ) ;
return V_29 ;
}
static int F_61 ( struct V_172 * V_173 )
{
int V_52 ;
struct V_48 * V_13 ;
struct V_44 * V_174 ;
if ( ! V_131 )
return 0 ;
V_13 = F_62 ( & V_173 -> V_45 , sizeof( struct V_48 ) , V_175 ) ;
if ( ! V_13 )
return - V_150 ;
F_41 ( V_13 ) ;
V_52 = F_63 ( & V_173 -> V_45 . V_176 , & V_177 ) ;
if ( V_52 )
return V_52 ;
V_174 = F_64 ( & V_173 -> V_45 ,
L_12 , V_13 ,
V_178 ) ;
if ( F_52 ( V_174 ) ) {
V_52 = F_53 ( V_174 ) ;
goto remove;
}
F_38 ( V_13 ) ;
F_65 ( & V_146 -> V_45 , & V_13 -> V_91 ) ;
F_66 ( V_173 , V_13 ) ;
return 0 ;
remove:
F_67 ( & V_173 -> V_45 . V_176 , & V_177 ) ;
return V_52 ;
}
static void T_8 F_68 ( void )
{
F_69 ( V_146 ) ;
F_59 ( & V_166 ) ;
F_60 ( V_164 ) ;
F_46 ( V_145 ) ;
F_46 ( V_152 ) ;
F_45 ( V_145 ) ;
F_45 ( V_152 ) ;
F_36 ( L_13 ) ;
}
static int F_70 ( struct V_172 * V_173 )
{
struct V_48 * V_13 ;
if ( ! V_131 )
return 0 ;
F_36 ( L_14 ) ;
F_13 () ;
V_13 = F_71 ( V_173 ) ;
F_72 ( & V_13 -> V_91 ) ;
F_67 ( & V_173 -> V_45 . V_176 , & V_177 ) ;
return 0 ;
}
