static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 * V_6 ;
V_2 -> V_7 = 0 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 += 2 ) {
V_6 = & V_2 -> V_6 [ V_4 == 0 ? 0 : 1 ] ;
V_6 -> V_8 = F_2 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_10 = F_3 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_11 = F_4 ( V_2 -> V_9 , V_4 ) ;
V_3 = - V_12 ;
if ( ! V_6 -> V_8 || ! V_6 -> V_10 ) {
F_5 ( L_1 ,
V_4 == 0 ? 0 : 1 , F_6 ( V_2 -> V_9 ) ) ;
goto V_13;
}
V_3 = F_7 ( V_2 -> V_9 , V_4 , V_14 ) ;
if ( V_3 ) {
F_5 ( L_2 ,
F_6 ( V_2 -> V_9 ) ) ;
goto V_13;
}
V_6 -> V_15 = F_8 ( V_6 -> V_8 , V_6 -> V_10 ) ;
if ( ! V_6 -> V_15 ) {
F_5 ( L_3 , V_4 == 0 ? 0 : 1 ,
F_6 ( V_2 -> V_9 ) ) ;
V_3 = - V_16 ;
goto V_17;
}
}
return 0 ;
V_17:
F_9 ( V_2 -> V_9 , V_4 ) ;
V_13:
if ( V_4 > 0 ) {
V_6 = & V_2 -> V_6 [ 0 ] ;
F_10 ( V_6 -> V_15 ) ;
F_9 ( V_2 -> V_9 , 0 ) ;
}
return V_3 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = & V_2 -> V_6 [ 1 ] ;
F_10 ( V_6 -> V_15 ) ;
F_9 ( V_2 -> V_9 , 2 ) ;
V_6 = & V_2 -> V_6 [ 0 ] ;
F_10 ( V_6 -> V_15 ) ;
F_9 ( V_2 -> V_9 , 0 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_4 = V_18 , V_3 ;
struct V_5 * V_6 = & V_2 -> V_6 [ 0 ] ;
V_2 -> V_7 = 1 ;
V_6 -> V_8 = F_2 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_10 = F_3 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_11 = F_4 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_15 = ( void V_19 * ) V_6 -> V_8 ;
if ( ! V_6 -> V_8 || ! V_6 -> V_10 ) {
F_5 ( L_4 ,
F_6 ( V_2 -> V_9 ) ) ;
return - V_12 ;
}
V_3 = F_7 ( V_2 -> V_9 , V_4 , V_14 ) ;
if ( V_3 ) {
F_5 ( L_5 ,
F_6 ( V_2 -> V_9 ) ) ;
}
return V_3 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_9 , V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_20 ;
V_3 = F_15 ( V_2 -> V_9 , V_21 , & V_20 ) ;
if ( V_3 ) {
F_5 ( L_6 ,
F_6 ( V_2 -> V_9 ) ) ;
goto V_13;
}
V_3 = - V_12 ;
if ( V_20 & V_22 ) {
if ( ( V_3 = F_1 ( V_2 ) ) )
goto V_13;
} else if ( V_20 & V_23 ) {
if ( ( V_3 = F_12 ( V_2 ) ) )
goto V_13;
F_5 ( L_7 ,
F_6 ( V_2 -> V_9 ) ) ;
} else {
F_5 ( L_8 ,
F_6 ( V_2 -> V_9 ) ) ;
goto V_13;
}
return 0 ;
V_13:
return V_3 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_13 ( V_2 ) ;
else
F_11 ( V_2 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
V_2 -> V_24 = V_2 -> V_9 -> V_25 ;
V_3 = - V_12 ;
if ( V_2 -> V_24 < V_26 ) {
F_5 ( L_9 ,
F_6 ( V_2 -> V_9 ) ,
V_27 [ V_2 -> V_24 ] ,
V_2 -> V_24 ) ;
goto V_13;
}
V_2 -> V_28 . V_29 = 512 ;
V_2 -> V_28 . V_30 = V_31 ;
V_2 -> V_28 . V_32 = V_33 ;
V_2 -> V_28 . V_34 = 0xFF ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ ) {
V_2 -> V_28 . V_35 [ V_4 ] . V_36 =
V_37 ;
V_2 -> V_28 . V_35 [ V_4 ] . V_38 =
V_39 ;
V_2 -> V_28 . V_35 [ V_4 ] . V_40 =
V_39 ;
V_2 -> V_28 . V_35 [ V_4 ] . V_41 =
V_39 ;
}
return 0 ;
V_13:
return V_3 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 = F_17 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_28 . V_42 = 8 ;
V_2 -> V_28 . V_43 = 0 ;
V_2 -> V_28 . V_44 = 8 ;
V_2 -> V_28 . V_45 = 16 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_3 = F_17 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_28 . V_42 = 4 ;
V_2 -> V_28 . V_43 = 0 ;
V_2 -> V_28 . V_44 = 4 ;
V_2 -> V_28 . V_45 = 8 ;
return 0 ;
}
static T_2 F_20 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
return snprintf ( V_50 , V_51 , L_10 ,
V_27 [ V_2 -> V_24 ] ) ;
}
static T_2 F_22 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
return snprintf ( V_50 , V_51 , L_11 , V_2 -> V_28 . V_52 . V_53 ) ;
}
static T_2 F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
return snprintf ( V_50 , V_51 , L_10 , V_2 -> V_28 . V_54 ) ;
}
static T_2 F_24 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_50 , T_3 V_55 )
{
struct V_1 * V_2 = F_21 ( V_47 ) ;
char * V_56 , * V_57 ;
struct V_58 V_59 , * V_60 ;
int V_61 , V_4 ;
T_4 V_62 = 0 ;
int V_63 = V_64 ;
int V_3 = 0 ;
V_56 = F_25 ( V_55 * 2 , V_65 ) ;
if ( ! V_56 ) {
V_3 = V_66 ;
goto V_67;
}
V_57 = V_56 + V_55 ;
V_61 = sscanf ( V_50 , L_12 , V_56 , V_57 ) ;
if ( V_61 != 2 ) {
V_3 = V_68 ;
goto V_69;
}
for ( V_4 = 0 ; V_70 [ V_4 ] . V_71 != V_64 ; V_4 ++ ) {
if ( ! memcmp ( V_70 [ V_4 ] . V_72 ,
V_56 , strlen ( V_56 ) ) ) {
V_63 = V_70 [ V_4 ] . V_71 ;
break;
}
}
if ( V_63 == V_64 ) {
V_3 = V_68 ;
goto V_69;
}
if ( V_2 -> V_73 == V_74 ) {
V_3 = V_74 ;
goto V_69;
}
V_3 = F_26 ( & V_2 -> V_75 ,
V_57 ,
& V_2 -> V_9 -> V_47 ) ;
if ( V_3 ) {
F_5 ( L_13 ,
V_57 , V_3 ) ;
V_3 = V_76 ;
goto V_69;
}
V_60 = (struct V_58 * ) V_2 -> V_75 -> V_77 ;
if ( ( V_60 -> V_78 . V_79 != V_2 -> V_9 -> V_79 ||
V_60 -> V_78 . V_46 != V_2 -> V_9 -> V_46 ) &&
( V_60 -> V_78 . V_80 != V_2 -> V_9 -> V_79 ||
V_60 -> V_78 . V_81 != V_2 -> V_9 -> V_46 ) ) {
F_27 ( L_14 ) ;
F_27 ( L_15
L_16 ,
V_60 -> V_78 . V_79 ,
V_60 -> V_78 . V_46 ,
V_60 -> V_78 . V_80 ,
V_60 -> V_78 . V_81 ,
V_2 -> V_9 -> V_79 ,
V_2 -> V_9 -> V_46 ) ;
V_3 = V_82 ;
goto V_83;
}
if ( V_60 -> V_84 != V_2 -> V_75 -> V_85 ) {
V_3 = V_86 ;
goto V_83;
}
for ( V_4 = 0 ; V_4 < V_60 -> V_84 ; V_4 ++ )
V_62 += V_2 -> V_75 -> V_77 [ V_4 ] ;
if ( ( V_62 & 0x0000ffff ) != V_60 -> V_87 ) {
F_27 ( L_17 ) ;
V_3 = V_88 ;
goto V_83;
}
if ( V_63 == V_89 ) {
V_2 -> V_73 = V_74 ;
V_3 = F_28 ( V_2 ,
& V_2 -> V_75 -> V_77 [ sizeof( * V_60 ) ] ,
0 , V_60 -> V_84 - sizeof( * V_60 ) ) ;
if ( ! V_3 )
V_3 = F_29 ( V_2 ,
& V_2 -> V_75 -> V_77 [ sizeof( * V_60 ) ] ,
0 , V_60 -> V_84 - sizeof( * V_60 ) ) ;
} else {
V_2 -> V_73 = V_74 ;
V_3 = F_29 ( V_2 ,
& V_2 -> V_75 -> V_77 [ sizeof( V_59 ) ] ,
0 , V_60 -> V_84 - sizeof( V_59 ) ) ;
}
V_83:
F_30 ( V_2 -> V_75 ) ;
V_69:
F_31 ( V_56 ) ;
V_67:
V_2 -> V_73 = V_3 ;
if ( ! V_3 )
return V_55 ;
else
return - V_3 ;
}
static T_2 F_32 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
int V_4 ;
struct V_1 * V_2 = F_21 ( V_47 ) ;
for ( V_4 = 0 ; V_90 [ V_4 ] . V_91 != 0 ; V_4 ++ ) {
if ( V_90 [ V_4 ] . V_91 == V_2 -> V_73 )
break;
}
if ( V_2 -> V_73 != V_74 )
V_2 -> V_73 = V_92 ;
return snprintf ( V_50 , V_51 , L_18 ,
V_90 [ V_4 ] . V_91 ,
V_90 [ V_4 ] . V_93 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_34 ( & V_2 -> V_9 -> V_47 , & V_94 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_34 ( & V_2 -> V_9 -> V_47 , & V_95 ) ;
if ( V_3 )
goto V_96;
V_3 = F_34 ( & V_2 -> V_9 -> V_47 , & V_97 ) ;
if ( V_3 )
goto V_98;
V_3 = F_34 ( & V_2 -> V_9 -> V_47 , & V_99 ) ;
if ( V_3 )
goto V_100;
return 0 ;
V_100:
F_35 ( & V_2 -> V_9 -> V_47 , & V_97 ) ;
V_98:
F_35 ( & V_2 -> V_9 -> V_47 , & V_95 ) ;
V_96:
F_35 ( & V_2 -> V_9 -> V_47 , & V_94 ) ;
return V_3 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_9 -> V_47 , & V_94 ) ;
F_35 ( & V_2 -> V_9 -> V_47 , & V_95 ) ;
F_35 ( & V_2 -> V_9 -> V_47 , & V_97 ) ;
F_35 ( & V_2 -> V_9 -> V_47 , & V_99 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
V_2 -> V_101 = F_38 ( V_14 L_19 ,
& V_2 -> V_9 -> V_47 ,
sizeof( struct V_102 ) ,
8 , 0 ) ;
if ( ! V_2 -> V_101 ) {
F_5 ( L_20 ) ;
return - V_16 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_103 * V_104 = & V_2 -> V_104 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_104 -> V_105 ; V_4 ++ )
F_40 ( V_2 , V_104 -> V_106 [ V_4 ] ) ;
F_31 ( V_104 -> V_106 ) ;
V_104 -> V_106 = NULL ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_103 * V_104 = & V_2 -> V_104 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_104 -> V_107 ; V_4 ++ ) {
if ( ! F_42 ( & V_104 -> V_108 [ V_4 ] -> V_109 ) )
F_43 ( & V_104 -> V_108 [ V_4 ] -> V_109 ) ;
F_44 ( V_104 -> V_108 [ V_4 ] ) ;
}
F_31 ( V_104 -> V_108 ) ;
V_104 -> V_108 = NULL ;
}
static void F_45 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_28 . V_110 )
F_40 ( V_2 , V_2 -> V_28 . V_110 ) ;
if ( V_2 -> V_28 . V_111 )
F_40 ( V_2 , V_2 -> V_28 . V_111 ) ;
if ( V_2 -> V_28 . V_112 )
F_31 ( V_2 -> V_28 . V_112 ) ;
V_2 -> V_28 . V_112 = NULL ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ ) {
struct V_113 * V_114 = & V_2 -> V_115 [ V_4 ] ;
F_40 ( V_2 , V_114 -> V_116 ) ;
}
if ( V_2 -> V_104 . V_108 )
F_41 ( V_2 ) ;
if ( V_2 -> V_104 . V_106 )
F_39 ( V_2 ) ;
if ( V_2 -> V_28 . V_117 . V_118 ) {
F_31 ( V_2 -> V_28 . V_117 . V_118 ) ;
V_2 -> V_28 . V_117 . V_118 = NULL ;
}
if ( V_2 -> V_104 . V_119 ) {
F_31 ( V_2 -> V_104 . V_119 ) ;
F_31 ( V_2 -> V_104 . V_120 ) ;
V_2 -> V_104 . V_119 = NULL ;
V_2 -> V_104 . V_120 = NULL ;
}
if ( V_2 -> V_104 . V_121 ) {
F_40 ( V_2 , V_2 -> V_104 . V_121 ) ;
V_2 -> V_104 . V_121 = NULL ;
V_2 -> V_104 . V_122 = NULL ;
}
if ( V_2 -> V_104 . V_123 . V_124 ) {
F_46 ( V_2 -> V_101 , V_2 -> V_104 . V_123 . V_124 ,
V_2 -> V_104 . V_123 . V_125 ) ;
V_2 -> V_104 . V_123 . V_124 = NULL ;
}
F_47 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
}
static int F_48 ( void )
{
if ( ! V_126 ) {
V_126
= F_49 ( V_14 L_21 ,
sizeof( struct V_127 ) ,
0 ,
V_128 ,
NULL ) ;
if ( ! V_126 ) {
F_5 ( L_22 ) ;
return - V_16 ;
}
}
if ( ! V_129 ) {
V_129 = F_49 ( V_14 L_23 ,
sizeof( struct V_130 ) ,
0 ,
V_128 ,
NULL ) ;
if ( ! V_129 ) {
F_5 ( L_24 ) ;
goto V_13;
}
}
return 0 ;
V_13:
F_50 ( V_126 ) ;
V_126 = NULL ;
return - V_16 ;
}
static void F_51 ( void )
{
if ( V_126 )
F_50 ( V_126 ) ;
V_126 = NULL ;
if ( V_129 )
F_50 ( V_129 ) ;
V_129 = NULL ;
}
static int F_52 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_131 * * V_132 =
F_53 ( V_33 , sizeof( * V_132 ) , V_65 ) ;
struct V_133 * * V_134 =
F_53 ( V_33 , sizeof( * V_134 ) , V_65 ) ;
if ( ! V_132 || ! V_134 ) {
F_31 ( V_132 ) ;
F_31 ( V_134 ) ;
return - V_16 ;
}
V_2 -> V_135 . V_136 = ( char * ) V_2 -> V_137 ;
V_2 -> V_135 . V_138 = V_139 ;
V_2 -> V_135 . V_140 = & V_2 -> V_28 . V_140 [ 0 ] ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ ) {
V_132 [ V_4 ] = & V_2 -> V_115 [ V_4 ] . V_141 ;
V_134 [ V_4 ] = & V_2 -> V_142 [ V_4 ] ;
}
V_2 -> V_135 . V_141 = V_132 ;
V_2 -> V_135 . V_143 = V_134 ;
V_2 -> V_135 . V_32 = V_33 ;
return F_54 ( & V_2 -> V_135 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_56 ( & V_2 -> V_135 ) ;
F_57 ( V_2 -> V_135 . V_144 . V_145 ) ;
F_58 ( V_2 -> V_135 . V_144 . V_145 ) ;
F_59 ( V_2 -> V_135 . V_144 . V_145 ) ;
F_31 ( V_2 -> V_135 . V_141 ) ;
F_31 ( V_2 -> V_135 . V_143 ) ;
return V_3 ;
}
static int F_60 ( struct V_146 * V_47 , const struct V_147 * V_148 )
{
const struct V_149 * V_150 ;
unsigned V_151 = ( unsigned ) V_148 -> V_152 ;
struct V_1 * V_2 ;
struct V_153 * V_145 ;
int V_3 ;
if ( V_151 >= F_61 ( V_154 ) ) {
F_5 ( L_25 ) ;
return - V_12 ;
}
if ( ( V_3 = F_62 ( V_47 ) ) ) {
F_5 ( L_26 , F_6 ( V_47 ) ) ;
return V_3 ;
}
F_63 ( V_47 ) ;
V_3 = - V_16 ;
V_145 = F_64 ( & V_155 , sizeof( void * ) ) ;
if ( ! V_145 )
goto V_13;
V_150 = & V_154 [ V_151 ] ;
V_2 = F_25 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 ) {
F_5 ( L_27 ) ;
goto V_156;
}
V_2 -> V_9 = V_47 ;
V_2 -> V_135 . V_47 = & V_2 -> V_9 -> V_47 ;
V_2 -> V_135 . V_157 = V_2 ;
V_2 -> V_73 = V_92 ;
V_2 -> V_137 = V_150 -> V_137 ;
F_5 ( L_28 , V_2 -> V_137 , F_6 ( V_47 ) ) ;
F_65 ( V_145 ) = & V_2 -> V_135 ;
V_2 -> V_135 . V_144 . V_145 = V_145 ;
V_145 -> V_158 = V_159 ;
V_145 -> V_160 = ~ 0 ;
V_145 -> V_161 = ~ 0 ;
V_145 -> V_162 = 16 ;
V_3 = F_66 ( V_145 , & V_47 -> V_47 ) ;
if ( V_3 )
goto V_163;
V_3 = V_150 -> V_164 ( V_2 ) ;
if ( V_3 )
goto V_165;
V_3 = - V_12 ;
if ( ! F_67 ( V_47 , F_68 ( 64 ) )
&& ! F_69 ( V_47 , F_68 ( 64 ) ) )
;
else if ( ! F_67 ( V_47 , F_68 ( 32 ) )
&& ! F_69 ( V_47 , F_68 ( 32 ) ) )
;
else {
F_5 ( L_29 , F_6 ( V_47 ) ) ;
goto V_165;
}
F_70 ( V_47 , V_2 ) ;
V_3 = F_14 ( V_2 ) ;
if ( V_3 )
goto V_165;
V_3 = F_37 ( V_2 ) ;
if ( V_3 )
goto V_166;
V_3 = F_71 ( V_2 ) ;
if ( V_3 )
goto V_167;
F_5 ( L_30
L_31 ,
F_6 ( V_47 ) , F_72 ( V_2 -> V_28 . V_140 ) ,
V_2 -> V_28 . V_54 , V_2 -> V_28 . V_168 ,
V_2 -> V_28 . V_32 ,
V_2 -> V_28 . V_169 . V_170 ? L_32 : L_33 ,
V_2 -> V_28 . V_52 . V_170 ? L_34 : L_33 ,
V_2 -> V_28 . V_52 . V_53 ) ;
V_145 -> V_171 = V_2 -> V_104 . V_171 ;
if ( V_172 )
F_73 ( V_2 -> V_9 ) ;
V_3 = F_74 ( V_2 -> V_9 -> V_173 , V_174 , V_175 ,
V_14 , V_2 ) ;
if ( V_3 ) {
F_5 ( L_35 ,
V_2 -> V_9 -> V_173 , F_6 ( V_2 -> V_9 ) ) ;
goto V_176;
}
F_75 ( V_2 ) ;
V_3 = F_76 ( V_2 ) ;
if ( V_3 ) {
F_5 ( L_36 ,
F_6 ( V_2 -> V_9 ) ) ;
goto V_177;
}
F_27 ( L_37 ) ;
V_3 = F_33 ( V_2 ) ;
if ( V_3 )
goto V_178;
V_3 = F_52 ( V_2 ) ;
if ( V_3 )
goto V_179;
F_77 ( V_145 ) ;
return 0 ;
V_179:
F_36 ( V_2 ) ;
V_178:
V_177:
F_78 ( V_2 ) ;
F_79 ( V_47 -> V_173 , V_2 ) ;
V_176:
if ( V_172 )
F_80 ( V_47 ) ;
F_81 ( V_2 ) ;
V_167:
F_45 ( V_2 ) ;
V_166:
F_16 ( V_2 ) ;
V_165:
F_58 ( V_145 ) ;
V_163:
F_31 ( V_2 ) ;
V_156:
F_59 ( V_145 ) ;
V_13:
F_82 ( V_47 ) ;
return V_3 ;
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
F_84 ( V_180 ) ;
struct V_181 * V_182 , * V_183 ;
F_85 ( & V_2 -> V_104 . V_184 , V_11 ) ;
V_2 -> V_104 . V_180 = 0 ;
F_86 ( & V_2 -> V_104 . V_185 , & V_180 ) ;
F_87 ( & V_2 -> V_104 . V_184 , V_11 ) ;
if ( ! F_42 ( & V_180 ) )
F_27 ( L_38 ) ;
F_88 (pos, n, &pending) {
struct V_130 * V_186 = F_89 ( V_183 , struct V_130 , V_109 ) ;
F_90 ( & V_186 -> V_187 ) ;
F_91 ( V_186 -> V_102 -> V_59 . V_188 != V_189 ) ;
F_43 ( V_183 ) ;
F_27 ( L_39 ) ;
F_44 ( V_186 ) ;
}
}
static void F_92 ( struct V_1 * V_2 )
{
T_5 V_190 = V_2 -> V_28 . V_34 ;
T_5 V_4 ;
F_93 (phy_mask, phy_mask, i) {
F_94 ( V_2 , V_4 , 0 ) ;
F_95 ( V_2 , V_4 , 0 ) ;
}
}
static void F_96 ( struct V_146 * V_47 )
{
struct V_1 * V_2 = F_97 ( V_47 ) ;
if ( ! V_2 )
return;
F_55 ( V_2 ) ;
F_78 ( V_2 ) ;
F_36 ( V_2 ) ;
F_79 ( V_47 -> V_173 , V_2 ) ;
if ( V_172 )
F_80 ( V_2 -> V_9 ) ;
F_92 ( V_2 ) ;
F_81 ( V_2 ) ;
F_83 ( V_2 ) ;
F_45 ( V_2 ) ;
F_16 ( V_2 ) ;
F_31 ( V_2 ) ;
F_82 ( V_47 ) ;
return;
}
static void F_98 ( struct V_153 * V_145 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_65 ( V_145 ) -> V_157 ;
V_3 = F_99 ( V_2 , V_2 -> V_28 . V_34 ) ;
if ( V_3 )
F_5 ( L_40 , V_3 ) ;
}
static int F_100 ( struct V_153 * V_145 , unsigned long time )
{
if ( time < V_191 )
return 0 ;
F_101 ( F_65 ( V_145 ) ) ;
return 1 ;
}
static T_2 F_102 ( struct V_192 * V_193 , char * V_50 )
{
return snprintf ( V_50 , V_51 , L_10 , V_194 ) ;
}
static int F_103 ( struct V_192 * V_193 )
{
return F_104 ( V_193 , & V_195 ) ;
}
static void F_105 ( struct V_192 * V_193 )
{
F_106 ( V_193 , & V_195 ) ;
}
static int T_6 F_107 ( void )
{
int V_3 ;
F_5 ( L_41 , V_196 ,
V_194 ) ;
V_3 = F_48 () ;
if ( V_3 )
return V_3 ;
V_159 =
F_108 ( & V_197 ) ;
if ( ! V_159 )
goto V_198;
V_3 = F_109 ( & V_199 ) ;
if ( V_3 )
goto V_200;
V_3 = F_103 ( & V_199 . V_193 ) ;
if ( V_3 )
goto V_201;
return V_3 ;
V_201:
F_110 ( & V_199 ) ;
V_200:
F_111 ( V_159 ) ;
V_198:
F_51 () ;
return V_3 ;
}
static void T_7 F_112 ( void )
{
F_105 ( & V_199 . V_193 ) ;
F_110 ( & V_199 ) ;
F_111 ( V_159 ) ;
F_113 () ;
F_51 () ;
F_5 ( L_42 , V_196 ,
V_194 ) ;
}
