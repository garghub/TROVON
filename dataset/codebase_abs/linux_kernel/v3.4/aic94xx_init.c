static int T_1 F_1 ( struct V_1 * V_2 )
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
if ( V_6 -> V_11 & V_15 )
V_6 -> V_16 = F_8 ( V_6 -> V_8 ,
V_6 -> V_10 ) ;
else
V_6 -> V_16 = F_9 ( V_6 -> V_8 ,
V_6 -> V_10 ) ;
if ( ! V_6 -> V_16 ) {
F_5 ( L_3 , V_4 == 0 ? 0 : 1 ,
F_6 ( V_2 -> V_9 ) ) ;
goto V_17;
}
}
return 0 ;
V_17:
F_10 ( V_2 -> V_9 , V_4 ) ;
V_13:
if ( V_4 > 0 ) {
V_6 = & V_2 -> V_6 [ 0 ] ;
F_11 ( V_6 -> V_16 ) ;
F_10 ( V_2 -> V_9 , 0 ) ;
}
return V_3 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = & V_2 -> V_6 [ 1 ] ;
F_11 ( V_6 -> V_16 ) ;
F_10 ( V_2 -> V_9 , 2 ) ;
V_6 = & V_2 -> V_6 [ 0 ] ;
F_11 ( V_6 -> V_16 ) ;
F_10 ( V_2 -> V_9 , 0 ) ;
}
static int T_1 F_13 ( struct V_1 * V_2 )
{
int V_4 = V_18 , V_3 ;
struct V_5 * V_6 = & V_2 -> V_6 [ 0 ] ;
V_2 -> V_7 = 1 ;
V_6 -> V_8 = F_2 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_10 = F_3 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_11 = F_4 ( V_2 -> V_9 , V_4 ) ;
V_6 -> V_16 = ( void V_19 * ) V_6 -> V_8 ;
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
static void F_14 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_9 , V_18 ) ;
}
static int T_1 F_15 ( struct V_1 * V_2 )
{
int V_3 ;
T_2 V_20 ;
V_3 = F_16 ( V_2 -> V_9 , V_21 , & V_20 ) ;
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
if ( ( V_3 = F_13 ( V_2 ) ) )
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
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 )
F_14 ( V_2 ) ;
else
F_12 ( V_2 ) ;
}
static int T_1 F_18 ( struct V_1 * V_2 )
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
static int T_1 F_19 ( struct V_1 * V_2 )
{
int V_3 = F_18 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_28 . V_42 = 8 ;
V_2 -> V_28 . V_43 = 0 ;
V_2 -> V_28 . V_44 = 8 ;
V_2 -> V_28 . V_45 = 16 ;
return 0 ;
}
static int T_1 F_20 ( struct V_1 * V_2 )
{
int V_3 = F_18 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_28 . V_42 = 4 ;
V_2 -> V_28 . V_43 = 0 ;
V_2 -> V_28 . V_44 = 4 ;
V_2 -> V_28 . V_45 = 8 ;
return 0 ;
}
static T_3 F_21 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_22 ( V_47 ) ;
return snprintf ( V_50 , V_51 , L_10 ,
V_27 [ V_2 -> V_24 ] ) ;
}
static T_3 F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_22 ( V_47 ) ;
return snprintf ( V_50 , V_51 , L_11 , V_2 -> V_28 . V_52 . V_53 ) ;
}
static T_3 F_24 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_22 ( V_47 ) ;
return snprintf ( V_50 , V_51 , L_10 , V_2 -> V_28 . V_54 ) ;
}
static T_3 F_25 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
const char * V_50 , T_4 V_55 )
{
struct V_1 * V_2 = F_22 ( V_47 ) ;
char * V_56 , * V_57 ;
struct V_58 V_59 , * V_60 ;
int V_61 , V_4 ;
T_5 V_62 = 0 ;
int V_63 = V_64 ;
int V_3 = 0 ;
V_56 = F_26 ( V_55 * 2 , V_65 ) ;
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
V_3 = F_27 ( & V_2 -> V_75 ,
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
F_28 ( L_14 ) ;
F_28 ( L_15
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
F_28 ( L_17 ) ;
V_3 = V_88 ;
goto V_83;
}
if ( V_63 == V_89 ) {
V_2 -> V_73 = V_74 ;
V_3 = F_29 ( V_2 ,
& V_2 -> V_75 -> V_77 [ sizeof( * V_60 ) ] ,
0 , V_60 -> V_84 - sizeof( * V_60 ) ) ;
if ( ! V_3 )
V_3 = F_30 ( V_2 ,
& V_2 -> V_75 -> V_77 [ sizeof( * V_60 ) ] ,
0 , V_60 -> V_84 - sizeof( * V_60 ) ) ;
} else {
V_2 -> V_73 = V_74 ;
V_3 = F_30 ( V_2 ,
& V_2 -> V_75 -> V_77 [ sizeof( V_59 ) ] ,
0 , V_60 -> V_84 - sizeof( V_59 ) ) ;
}
V_83:
F_31 ( V_2 -> V_75 ) ;
V_69:
F_32 ( V_56 ) ;
V_67:
V_2 -> V_73 = V_3 ;
if ( ! V_3 )
return V_55 ;
else
return - V_3 ;
}
static T_3 F_33 ( struct V_46 * V_47 ,
struct V_48 * V_49 , char * V_50 )
{
int V_4 ;
struct V_1 * V_2 = F_22 ( V_47 ) ;
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
static int F_34 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_35 ( & V_2 -> V_9 -> V_47 , & V_94 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_35 ( & V_2 -> V_9 -> V_47 , & V_95 ) ;
if ( V_3 )
goto V_96;
V_3 = F_35 ( & V_2 -> V_9 -> V_47 , & V_97 ) ;
if ( V_3 )
goto V_98;
V_3 = F_35 ( & V_2 -> V_9 -> V_47 , & V_99 ) ;
if ( V_3 )
goto V_100;
return 0 ;
V_100:
F_36 ( & V_2 -> V_9 -> V_47 , & V_97 ) ;
V_98:
F_36 ( & V_2 -> V_9 -> V_47 , & V_95 ) ;
V_96:
F_36 ( & V_2 -> V_9 -> V_47 , & V_94 ) ;
return V_3 ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_9 -> V_47 , & V_94 ) ;
F_36 ( & V_2 -> V_9 -> V_47 , & V_95 ) ;
F_36 ( & V_2 -> V_9 -> V_47 , & V_97 ) ;
F_36 ( & V_2 -> V_9 -> V_47 , & V_99 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
V_2 -> V_101 = F_39 ( V_14 L_19 ,
& V_2 -> V_9 -> V_47 ,
sizeof( struct V_102 ) ,
8 , 0 ) ;
if ( ! V_2 -> V_101 ) {
F_5 ( L_20 ) ;
return - V_103 ;
}
return 0 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_104 * V_105 = & V_2 -> V_105 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_105 -> V_106 ; V_4 ++ )
F_41 ( V_2 , V_105 -> V_107 [ V_4 ] ) ;
F_32 ( V_105 -> V_107 ) ;
V_105 -> V_107 = NULL ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_104 * V_105 = & V_2 -> V_105 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < V_105 -> V_108 ; V_4 ++ ) {
if ( ! F_43 ( & V_105 -> V_109 [ V_4 ] -> V_110 ) )
F_44 ( & V_105 -> V_109 [ V_4 ] -> V_110 ) ;
F_45 ( V_105 -> V_109 [ V_4 ] ) ;
}
F_32 ( V_105 -> V_109 ) ;
V_105 -> V_109 = NULL ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_28 . V_111 )
F_41 ( V_2 , V_2 -> V_28 . V_111 ) ;
if ( V_2 -> V_28 . V_112 )
F_41 ( V_2 , V_2 -> V_28 . V_112 ) ;
if ( V_2 -> V_28 . V_113 )
F_32 ( V_2 -> V_28 . V_113 ) ;
V_2 -> V_28 . V_113 = NULL ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ ) {
struct V_114 * V_115 = & V_2 -> V_116 [ V_4 ] ;
F_41 ( V_2 , V_115 -> V_117 ) ;
}
if ( V_2 -> V_105 . V_109 )
F_42 ( V_2 ) ;
if ( V_2 -> V_105 . V_107 )
F_40 ( V_2 ) ;
if ( V_2 -> V_28 . V_118 . V_119 ) {
F_32 ( V_2 -> V_28 . V_118 . V_119 ) ;
V_2 -> V_28 . V_118 . V_119 = NULL ;
}
if ( V_2 -> V_105 . V_120 ) {
F_32 ( V_2 -> V_105 . V_120 ) ;
F_32 ( V_2 -> V_105 . V_121 ) ;
V_2 -> V_105 . V_120 = NULL ;
V_2 -> V_105 . V_121 = NULL ;
}
if ( V_2 -> V_105 . V_122 ) {
F_41 ( V_2 , V_2 -> V_105 . V_122 ) ;
V_2 -> V_105 . V_122 = NULL ;
V_2 -> V_105 . V_123 = NULL ;
}
if ( V_2 -> V_105 . V_124 . V_125 ) {
F_47 ( V_2 -> V_101 , V_2 -> V_105 . V_124 . V_125 ,
V_2 -> V_105 . V_124 . V_126 ) ;
V_2 -> V_105 . V_124 . V_125 = NULL ;
}
F_48 ( V_2 -> V_101 ) ;
V_2 -> V_101 = NULL ;
}
static int F_49 ( void )
{
if ( ! V_127 ) {
V_127
= F_50 ( V_14 L_21 ,
sizeof( struct V_128 ) ,
0 ,
V_129 ,
NULL ) ;
if ( ! V_127 ) {
F_5 ( L_22 ) ;
return - V_103 ;
}
}
if ( ! V_130 ) {
V_130 = F_50 ( V_14 L_23 ,
sizeof( struct V_131 ) ,
0 ,
V_129 ,
NULL ) ;
if ( ! V_130 ) {
F_5 ( L_24 ) ;
goto V_13;
}
}
return 0 ;
V_13:
F_51 ( V_127 ) ;
V_127 = NULL ;
return - V_103 ;
}
static void F_52 ( void )
{
if ( V_127 )
F_51 ( V_127 ) ;
V_127 = NULL ;
if ( V_130 )
F_51 ( V_130 ) ;
V_130 = NULL ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_4 ;
struct V_132 * * V_133 =
F_54 ( V_33 , sizeof( * V_133 ) , V_65 ) ;
struct V_134 * * V_135 =
F_54 ( V_33 , sizeof( * V_135 ) , V_65 ) ;
if ( ! V_133 || ! V_135 ) {
F_32 ( V_133 ) ;
F_32 ( V_135 ) ;
return - V_103 ;
}
V_2 -> V_136 . V_137 = ( char * ) V_2 -> V_138 ;
V_2 -> V_136 . V_139 = V_140 ;
V_2 -> V_136 . V_141 = & V_2 -> V_28 . V_141 [ 0 ] ;
for ( V_4 = 0 ; V_4 < V_33 ; V_4 ++ ) {
V_133 [ V_4 ] = & V_2 -> V_116 [ V_4 ] . V_142 ;
V_135 [ V_4 ] = & V_2 -> V_143 [ V_4 ] ;
}
V_2 -> V_136 . V_142 = V_133 ;
V_2 -> V_136 . V_144 = V_135 ;
V_2 -> V_136 . V_32 = V_33 ;
V_2 -> V_136 . V_145 = V_2 -> V_105 . V_146 ;
V_2 -> V_136 . V_147 = V_147 ;
return F_55 ( & V_2 -> V_136 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_57 ( & V_2 -> V_136 ) ;
F_58 ( V_2 -> V_136 . V_148 . V_149 ) ;
F_59 ( V_2 -> V_136 . V_148 . V_149 ) ;
F_60 ( V_2 -> V_136 . V_148 . V_149 ) ;
F_32 ( V_2 -> V_136 . V_142 ) ;
F_32 ( V_2 -> V_136 . V_144 ) ;
return V_3 ;
}
static int T_1 F_61 ( struct V_150 * V_47 ,
const struct V_151 * V_152 )
{
const struct V_153 * V_154 ;
unsigned V_155 = ( unsigned ) V_152 -> V_156 ;
struct V_1 * V_2 ;
struct V_157 * V_149 ;
int V_3 ;
if ( V_155 >= F_62 ( V_158 ) ) {
F_5 ( L_25 ) ;
return - V_12 ;
}
if ( ( V_3 = F_63 ( V_47 ) ) ) {
F_5 ( L_26 , F_6 ( V_47 ) ) ;
return V_3 ;
}
F_64 ( V_47 ) ;
V_3 = - V_103 ;
V_149 = F_65 ( & V_159 , sizeof( void * ) ) ;
if ( ! V_149 )
goto V_13;
V_154 = & V_158 [ V_155 ] ;
V_2 = F_26 ( sizeof( * V_2 ) , V_65 ) ;
if ( ! V_2 ) {
F_5 ( L_27 ) ;
goto V_160;
}
V_2 -> V_9 = V_47 ;
V_2 -> V_136 . V_47 = & V_2 -> V_9 -> V_47 ;
V_2 -> V_136 . V_161 = V_2 ;
V_2 -> V_73 = V_92 ;
V_2 -> V_138 = V_154 -> V_138 ;
F_5 ( L_28 , V_2 -> V_138 , F_6 ( V_47 ) ) ;
F_66 ( V_149 ) = & V_2 -> V_136 ;
V_2 -> V_136 . V_148 . V_149 = V_149 ;
V_149 -> V_162 = V_163 ;
V_149 -> V_164 = ~ 0 ;
V_149 -> V_165 = ~ 0 ;
V_149 -> V_166 = 16 ;
V_3 = F_67 ( V_149 , & V_47 -> V_47 ) ;
if ( V_3 )
goto V_167;
V_3 = V_154 -> V_168 ( V_2 ) ;
if ( V_3 )
goto V_169;
V_3 = - V_12 ;
if ( ! F_68 ( V_47 , F_69 ( 64 ) )
&& ! F_70 ( V_47 , F_69 ( 64 ) ) )
;
else if ( ! F_68 ( V_47 , F_69 ( 32 ) )
&& ! F_70 ( V_47 , F_69 ( 32 ) ) )
;
else {
F_5 ( L_29 , F_6 ( V_47 ) ) ;
goto V_169;
}
F_71 ( V_47 , V_2 ) ;
V_3 = F_15 ( V_2 ) ;
if ( V_3 )
goto V_169;
V_3 = F_38 ( V_2 ) ;
if ( V_3 )
goto V_170;
V_3 = F_72 ( V_2 ) ;
if ( V_3 )
goto V_171;
F_5 ( L_30
L_31 ,
F_6 ( V_47 ) , F_73 ( V_2 -> V_28 . V_141 ) ,
V_2 -> V_28 . V_54 , V_2 -> V_28 . V_172 ,
V_2 -> V_28 . V_32 ,
V_2 -> V_28 . V_173 . V_174 ? L_32 : L_33 ,
V_2 -> V_28 . V_52 . V_174 ? L_34 : L_33 ,
V_2 -> V_28 . V_52 . V_53 ) ;
V_149 -> V_146 = V_2 -> V_105 . V_146 ;
if ( V_175 )
F_74 ( V_2 -> V_9 ) ;
V_3 = F_75 ( V_2 -> V_9 -> V_176 , V_177 , V_178 ,
V_14 , V_2 ) ;
if ( V_3 ) {
F_5 ( L_35 ,
V_2 -> V_9 -> V_176 , F_6 ( V_2 -> V_9 ) ) ;
goto V_179;
}
F_76 ( V_2 ) ;
V_3 = F_77 ( V_2 ) ;
if ( V_3 ) {
F_5 ( L_36 ,
F_6 ( V_2 -> V_9 ) ) ;
goto V_180;
}
F_28 ( L_37 ) ;
V_3 = F_34 ( V_2 ) ;
if ( V_3 )
goto V_181;
V_3 = F_53 ( V_2 ) ;
if ( V_3 )
goto V_182;
F_78 ( V_149 ) ;
return 0 ;
V_182:
F_37 ( V_2 ) ;
V_181:
V_180:
F_79 ( V_2 ) ;
F_80 ( V_47 -> V_176 , V_2 ) ;
V_179:
if ( V_175 )
F_81 ( V_47 ) ;
F_82 ( V_2 ) ;
V_171:
F_46 ( V_2 ) ;
V_170:
F_17 ( V_2 ) ;
V_169:
F_59 ( V_149 ) ;
V_167:
F_32 ( V_2 ) ;
V_160:
F_60 ( V_149 ) ;
V_13:
F_83 ( V_47 ) ;
return V_3 ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
F_85 ( V_183 ) ;
struct V_184 * V_185 , * V_186 ;
F_86 ( & V_2 -> V_105 . V_187 , V_11 ) ;
V_2 -> V_105 . V_183 = 0 ;
F_87 ( & V_2 -> V_105 . V_188 , & V_183 ) ;
F_88 ( & V_2 -> V_105 . V_187 , V_11 ) ;
if ( ! F_43 ( & V_183 ) )
F_28 ( L_38 ) ;
F_89 (pos, n, &pending) {
struct V_131 * V_189 = F_90 ( V_186 , struct V_131 , V_110 ) ;
F_91 ( & V_189 -> V_190 ) ;
F_92 ( V_189 -> V_102 -> V_59 . V_191 != V_192 ) ;
F_44 ( V_186 ) ;
F_28 ( L_39 ) ;
F_45 ( V_189 ) ;
}
}
static void F_93 ( struct V_1 * V_2 )
{
T_6 V_193 = V_2 -> V_28 . V_34 ;
T_6 V_4 ;
F_94 (phy_mask, phy_mask, i) {
F_95 ( V_2 , V_4 , 0 ) ;
F_96 ( V_2 , V_4 , 0 ) ;
}
}
static void T_7 F_97 ( struct V_150 * V_47 )
{
struct V_1 * V_2 = F_98 ( V_47 ) ;
if ( ! V_2 )
return;
F_56 ( V_2 ) ;
F_79 ( V_2 ) ;
F_37 ( V_2 ) ;
F_80 ( V_47 -> V_176 , V_2 ) ;
if ( V_175 )
F_81 ( V_2 -> V_9 ) ;
F_93 ( V_2 ) ;
F_82 ( V_2 ) ;
F_84 ( V_2 ) ;
F_46 ( V_2 ) ;
F_17 ( V_2 ) ;
F_32 ( V_2 ) ;
F_83 ( V_47 ) ;
return;
}
static void F_99 ( struct V_157 * V_149 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_66 ( V_149 ) -> V_161 ;
V_3 = F_100 ( V_2 , V_2 -> V_28 . V_34 ) ;
if ( V_3 )
F_5 ( L_40 , V_3 ) ;
}
static int F_101 ( struct V_157 * V_149 , unsigned long time )
{
if ( time < V_194 )
return 0 ;
F_102 ( F_66 ( V_149 ) ) ;
return 1 ;
}
static T_3 F_103 ( struct V_195 * V_196 , char * V_50 )
{
return snprintf ( V_50 , V_51 , L_10 , V_197 ) ;
}
static int F_104 ( struct V_195 * V_196 )
{
return F_105 ( V_196 , & V_198 ) ;
}
static void F_106 ( struct V_195 * V_196 )
{
F_107 ( V_196 , & V_198 ) ;
}
static int T_8 F_108 ( void )
{
int V_3 ;
F_5 ( L_41 , V_199 ,
V_197 ) ;
V_3 = F_49 () ;
if ( V_3 )
return V_3 ;
V_163 =
F_109 ( & V_200 ) ;
if ( ! V_163 )
goto V_201;
V_3 = F_110 ( & V_202 ) ;
if ( V_3 )
goto V_203;
V_3 = F_104 ( & V_202 . V_196 ) ;
if ( V_3 )
goto V_204;
return V_3 ;
V_204:
F_111 ( & V_202 ) ;
V_203:
F_112 ( V_163 ) ;
V_201:
F_52 () ;
return V_3 ;
}
static void T_9 F_113 ( void )
{
F_106 ( & V_202 . V_196 ) ;
F_111 ( & V_202 ) ;
F_112 ( V_163 ) ;
F_114 () ;
F_52 () ;
F_5 ( L_42 , V_199 ,
V_197 ) ;
}
