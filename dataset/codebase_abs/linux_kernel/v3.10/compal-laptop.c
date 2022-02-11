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
return sprintf ( V_5 , L_1 , V_48 ) ;
}
static T_5 F_22 ( struct V_44 * V_45 ,
struct V_46 * V_47 , char * V_5 )
{
struct V_49 * V_13 = F_23 ( V_45 ) ;
return sprintf ( V_5 , L_2 , V_13 -> V_50 ) ;
}
static T_5 F_24 ( struct V_44 * V_45 ,
struct V_46 * V_47 , const char * V_5 , T_6 V_51 )
{
struct V_49 * V_13 = F_23 ( V_45 ) ;
long V_52 ;
int V_53 ;
V_53 = F_25 ( V_5 , 10 , & V_52 ) ;
if ( V_53 )
return V_53 ;
if ( V_52 < 0 )
return - V_10 ;
V_13 -> V_50 = V_52 ;
switch ( V_52 ) {
case 0 :
F_12 () ;
F_14 ( 255 ) ;
break;
case 1 :
F_12 () ;
F_14 ( V_13 -> V_54 ) ;
break;
default:
F_13 () ;
break;
}
return V_51 ;
}
static T_5 F_26 ( struct V_44 * V_45 , struct V_46 * V_47 ,
char * V_5 )
{
struct V_49 * V_13 = F_23 ( V_45 ) ;
return sprintf ( V_5 , L_3 , V_13 -> V_54 ) ;
}
static T_5 F_27 ( struct V_44 * V_45 , struct V_46 * V_47 ,
const char * V_5 , T_6 V_51 )
{
struct V_49 * V_13 = F_23 ( V_45 ) ;
long V_52 ;
int V_53 ;
V_53 = F_25 ( V_5 , 10 , & V_52 ) ;
if ( V_53 )
return V_53 ;
if ( V_52 < 0 || V_52 > 255 )
return - V_10 ;
V_13 -> V_54 = V_52 ;
if ( V_13 -> V_50 != 1 )
return V_51 ;
F_14 ( V_52 ) ;
return V_51 ;
}
static T_5 F_28 ( struct V_44 * V_45 , struct V_46 * V_47 ,
char * V_5 )
{
return sprintf ( V_5 , L_2 , F_15 () ) ;
}
static int F_29 ( void )
{
T_1 V_55 = F_1 ( V_56 ) ;
T_1 V_57 = F_1 ( V_58 ) ;
if ( V_55 & V_59 )
return V_60 ;
if ( V_55 & V_61 )
return V_62 ;
if ( V_57 & V_63 )
return V_64 ;
return V_65 ;
}
static int F_30 ( void )
{
T_1 V_66 = F_1 ( V_67 ) ;
if ( V_66 & V_68 )
return V_69 ;
if ( V_66 & V_70 )
return V_71 ;
if ( V_66 & V_72 )
return V_73 ;
if ( V_66 & V_74 )
return V_75 ;
return V_76 ;
}
static int F_31 ( void )
{
T_1 V_66 = F_1 ( V_77 ) ;
return ( ( V_66 & V_78 ) != 0 ) ;
}
static int F_32 ( void )
{
T_1 V_66 = F_1 ( V_58 ) ;
if ( V_66 & V_79 )
return V_80 ;
return V_81 ;
}
static int F_33 ( void )
{
T_1 V_55 = F_1 ( V_56 ) ;
T_1 V_57 = F_1 ( V_58 ) ;
T_1 V_82 = F_1 ( V_77 ) ;
if ( V_55 & V_83
|| V_57 & V_84
|| V_82 & V_85 )
return V_86 ;
if ( V_55 & V_87 )
return V_88 ;
if ( V_57 & V_63 )
return V_89 ;
return V_90 ;
}
static int F_34 ( struct V_91 * V_92 ,
enum V_93 V_94 ,
union V_95 * V_52 )
{
struct V_49 * V_13 ;
V_13 = F_35 ( V_92 , struct V_49 , V_92 ) ;
switch ( V_94 ) {
case V_96 :
V_52 -> V_97 = F_29 () ;
break;
case V_98 :
V_52 -> V_97 = F_30 () ;
break;
case V_99 :
V_52 -> V_97 = F_31 () ;
break;
case V_100 :
V_52 -> V_97 = F_32 () ;
break;
case V_101 :
V_52 -> V_97 = F_4 ( V_102 ) * 1000 ;
break;
case V_103 :
V_52 -> V_97 = F_4 ( V_104 ) * 1000 ;
break;
case V_105 :
V_52 -> V_97 = F_5 ( V_106 ) * 1000 ;
break;
case V_107 :
V_52 -> V_97 = F_5 ( V_108 ) * 1000 ;
break;
case V_109 :
V_52 -> V_97 = F_1 ( V_110 ) * 1000000 ;
break;
case V_111 :
V_52 -> V_97 = F_4 ( V_112 ) * 1000 ;
break;
case V_113 :
V_52 -> V_97 = F_4 ( V_114 ) * 1000 ;
break;
case V_115 :
V_52 -> V_97 = F_1 ( V_116 ) ;
break;
case V_117 :
V_52 -> V_97 = F_33 () ;
break;
case V_118 :
V_52 -> V_97 = ( ( 222 - ( int ) F_1 ( V_119 ) ) * 1000 ) >> 8 ;
break;
case V_120 :
V_52 -> V_97 = F_3 ( V_121 ) * 10 ;
break;
case V_122 :
V_52 -> V_123 = V_13 -> V_124 ;
break;
case V_125 :
V_52 -> V_123 = V_13 -> V_126 ;
break;
case V_127 :
V_52 -> V_123 = V_13 -> V_128 ;
break;
default:
break;
}
return 0 ;
}
static int F_36 ( const struct V_129 * V_130 )
{
F_37 ( L_4 , V_130 -> V_131 ) ;
V_132 = false ;
return 1 ;
}
static int F_38 ( const struct V_129 * V_130 )
{
F_37 ( L_5 ,
V_130 -> V_131 ) ;
V_132 = true ;
return 1 ;
}
static void F_39 ( struct V_49 * V_13 )
{
V_13 -> V_92 . V_133 = V_48 ;
V_13 -> V_92 . type = V_134 ;
V_13 -> V_92 . V_135 = V_136 ;
V_13 -> V_92 . V_137 = F_40 ( V_136 ) ;
V_13 -> V_92 . V_138 = F_34 ;
F_6 ( V_139 ,
V_13 -> V_126 ,
V_140 ) ;
V_13 -> V_126 [ V_140 ] = 0 ;
F_6 ( V_141 ,
V_13 -> V_124 ,
V_142 ) ;
V_13 -> V_124 [ V_142 ] = 0 ;
F_41 ( V_13 -> V_128 , V_143 + 1 , L_6 ,
F_4 ( V_144 ) ) ;
}
static void F_42 ( struct V_49 * V_13 )
{
V_13 -> V_50 = 2 ;
V_13 -> V_54 = 255 ;
}
static int F_43 ( void )
{
int V_29 ;
V_145 = F_44 ( L_7 , & V_146 -> V_45 ,
V_147 , & V_148 ,
( void * ) V_149 ) ;
if ( ! V_145 )
return - V_150 ;
V_29 = F_45 ( V_145 ) ;
if ( V_29 )
goto V_151;
V_152 = F_44 ( L_8 , & V_146 -> V_45 ,
V_153 , & V_148 ,
( void * ) V_154 ) ;
if ( ! V_152 ) {
V_29 = - V_150 ;
goto V_155;
}
V_29 = F_45 ( V_152 ) ;
if ( V_29 )
goto V_156;
return 0 ;
V_156:
F_46 ( V_152 ) ;
V_155:
F_47 ( V_145 ) ;
V_151:
F_46 ( V_145 ) ;
return V_29 ;
}
static int T_7 F_48 ( void )
{
int V_29 ;
if ( V_157 ) {
F_49 ( L_9 ) ;
return - V_158 ;
}
if ( ! V_159 && ! F_50 ( V_160 ) ) {
F_49 ( L_10 ) ;
return - V_158 ;
}
if ( ! F_51 () ) {
struct V_161 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_161 ) ) ;
V_30 . type = V_162 ;
V_30 . V_163 = V_9 ;
V_164 = F_52 ( V_48 ,
NULL , NULL ,
& V_165 ,
& V_30 ) ;
if ( F_53 ( V_164 ) )
return F_54 ( V_164 ) ;
}
V_29 = F_55 ( & V_166 ) ;
if ( V_29 )
goto V_167;
V_146 = F_56 ( V_48 , - 1 ) ;
if ( ! V_146 ) {
V_29 = - V_150 ;
goto V_168;
}
V_29 = F_57 ( V_146 ) ;
if ( V_29 )
goto V_169;
V_29 = F_43 () ;
if ( V_29 )
goto V_170;
F_37 ( L_11 V_171 L_12 ) ;
return 0 ;
V_170:
F_58 ( V_146 ) ;
V_169:
F_59 ( V_146 ) ;
V_168:
F_60 ( & V_166 ) ;
V_167:
F_61 ( V_164 ) ;
return V_29 ;
}
static int F_62 ( struct V_172 * V_173 )
{
int V_53 ;
struct V_49 * V_13 ;
if ( ! V_132 )
return 0 ;
V_13 = F_63 ( sizeof( struct V_49 ) , V_174 ) ;
if ( ! V_13 )
return - V_150 ;
F_42 ( V_13 ) ;
V_53 = F_64 ( & V_173 -> V_45 . V_175 , & V_176 ) ;
if ( V_53 ) {
F_65 ( V_13 ) ;
return V_53 ;
}
V_13 -> V_177 = F_66 ( & V_173 -> V_45 ) ;
if ( F_53 ( V_13 -> V_177 ) ) {
V_53 = F_54 ( V_13 -> V_177 ) ;
F_67 ( & V_173 -> V_45 . V_175 ,
& V_176 ) ;
F_65 ( V_13 ) ;
return V_53 ;
}
F_39 ( V_13 ) ;
F_68 ( & V_146 -> V_45 , & V_13 -> V_92 ) ;
F_69 ( V_173 , V_13 ) ;
return 0 ;
}
static void T_8 F_70 ( void )
{
F_71 ( V_146 ) ;
F_60 ( & V_166 ) ;
F_61 ( V_164 ) ;
F_47 ( V_145 ) ;
F_47 ( V_152 ) ;
F_46 ( V_145 ) ;
F_46 ( V_152 ) ;
F_37 ( L_13 ) ;
}
static int F_72 ( struct V_172 * V_173 )
{
struct V_49 * V_13 ;
if ( ! V_132 )
return 0 ;
F_37 ( L_14 ) ;
F_13 () ;
V_13 = F_73 ( V_173 ) ;
F_74 ( V_13 -> V_177 ) ;
F_75 ( & V_13 -> V_92 ) ;
F_69 ( V_173 , NULL ) ;
F_65 ( V_13 ) ;
F_67 ( & V_173 -> V_45 . V_175 , & V_176 ) ;
return 0 ;
}
