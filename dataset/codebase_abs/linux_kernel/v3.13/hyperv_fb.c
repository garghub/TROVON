static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static T_1 V_5 = F_2 ( 0 ) ;
int V_6 ;
V_4 -> V_7 . type = V_8 ;
V_4 -> V_7 . V_9 = V_4 -> V_10 . V_9 ;
V_6 = F_3 ( V_2 -> V_11 , V_4 ,
V_4 -> V_10 . V_9 + sizeof( struct V_12 ) ,
F_4 ( & V_5 ) ,
V_13 , 0 ) ;
if ( V_6 )
F_5 ( L_1 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_3 V_4 ;
if ( ! V_15 )
return - V_16 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_17 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_19 ) ;
V_4 . V_20 . V_21 = 0 ;
V_4 . V_20 . V_22 = 1 ;
V_4 . V_20 . V_23 [ 0 ] . V_24 = 1 ;
V_4 . V_20 . V_23 [ 0 ] . V_25 = 0 ;
V_4 . V_20 . V_23 [ 0 ] . V_26 = V_15 -> V_27 . V_28 ;
V_4 . V_20 . V_23 [ 0 ] . V_29 = V_15 -> V_27 . V_30 ;
V_4 . V_20 . V_23 [ 0 ] . V_31 = V_15 -> V_27 . V_32 ;
V_4 . V_20 . V_23 [ 0 ] . V_33 = V_15 -> V_34 . V_35 ;
F_1 ( V_2 , & V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_36 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_37 ) ;
V_4 . V_38 . V_39 = 1 ;
V_4 . V_38 . V_23 = 0 ;
V_4 . V_38 . V_40 = 0 ;
V_4 . V_38 . V_41 = 0 ;
F_1 ( V_2 , & V_4 ) ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_42 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_43 ) ;
V_4 . V_44 . V_45 = V_46 ;
V_4 . V_44 . V_47 = 1 ;
V_4 . V_44 . V_48 = 1 ;
V_4 . V_44 . V_49 = 1 ;
V_4 . V_44 . V_50 = 0 ;
V_4 . V_44 . V_51 = 0 ;
V_4 . V_44 . V_52 [ 0 ] = 0 ;
V_4 . V_44 . V_52 [ 1 ] = 1 ;
V_4 . V_44 . V_52 [ 2 ] = 1 ;
V_4 . V_44 . V_52 [ 3 ] = 1 ;
F_1 ( V_2 , & V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 -> V_53 ) ;
struct V_3 V_4 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 . V_10 . type = V_54 ;
V_4 . V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_55 ) ;
V_4 . V_56 . V_23 = 0 ;
V_4 . V_56 . V_57 = 1 ;
V_4 . V_56 . V_58 [ 0 ] . V_59 = 0 ;
V_4 . V_56 . V_58 [ 0 ] . y1 = 0 ;
V_4 . V_56 . V_58 [ 0 ] . V_60 = V_15 -> V_27 . V_30 ;
V_4 . V_56 . V_58 [ 0 ] . V_61 = V_15 -> V_27 . V_32 ;
F_1 ( V_2 , & V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 ;
struct V_3 * V_4 ;
if ( ! V_15 )
return;
V_63 = V_15 -> V_63 ;
V_4 = (struct V_3 * ) V_63 -> V_64 ;
if ( V_4 -> V_10 . type == V_65 ||
V_4 -> V_10 . type == V_66 ) {
memcpy ( V_63 -> V_67 , V_4 , V_68 ) ;
F_12 ( & V_63 -> V_69 ) ;
return;
}
if ( V_4 -> V_10 . type == V_70 ) {
if ( V_63 -> V_71 ) {
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
}
V_63 -> V_72 = V_4 -> V_73 . V_74 ;
if ( V_63 -> V_72 )
F_13 ( & V_63 -> V_75 , V_76 ) ;
}
}
static void F_14 ( void * V_77 )
{
struct V_1 * V_2 = V_77 ;
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 ;
struct V_3 * V_64 ;
T_2 V_78 ;
T_3 V_79 ;
int V_6 ;
if ( ! V_15 )
return;
V_63 = V_15 -> V_63 ;
V_64 = (struct V_3 * ) V_63 -> V_64 ;
do {
V_6 = F_15 ( V_2 -> V_11 , V_64 ,
V_68 ,
& V_78 , & V_79 ) ;
if ( V_78 > 0 &&
V_64 -> V_7 . type == V_8 )
F_11 ( V_2 ) ;
} while ( V_78 > 0 && V_6 == 0 );
}
static int F_16 ( struct V_1 * V_2 , T_2 V_80 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
struct V_3 * V_4 = (struct V_3 * ) V_63 -> V_67 ;
int V_81 , V_6 = 0 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_10 . type = V_82 ;
V_4 -> V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_83 ) ;
V_4 -> V_84 . V_85 = V_80 ;
F_1 ( V_2 , V_4 ) ;
V_81 = F_17 ( & V_63 -> V_69 , V_86 ) ;
if ( ! V_81 ) {
F_5 ( L_2 ) ;
V_6 = - V_87 ;
goto V_88;
}
if ( ! V_4 -> V_89 . V_90 ) {
V_6 = - V_16 ;
goto V_88;
}
V_63 -> V_91 = V_80 ;
V_88:
return V_6 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
int V_6 ;
V_6 = F_19 ( V_2 -> V_11 , V_92 , V_92 ,
NULL , 0 , F_14 , V_2 ) ;
if ( V_6 ) {
F_5 ( L_3 ) ;
return V_6 ;
}
if ( V_93 == V_94 ||
V_93 == V_95 )
V_6 = F_16 ( V_2 , V_96 ) ;
else
V_6 = F_16 ( V_2 , V_97 ) ;
if ( V_6 ) {
F_5 ( L_4 ) ;
goto error;
}
if ( V_63 -> V_91 == V_96 ) {
V_98 = V_99 ;
V_100 = V_101 ;
} else {
V_98 = V_102 ;
V_100 = V_103 ;
}
return 0 ;
error:
F_20 ( V_2 -> V_11 ) ;
return V_6 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
struct V_3 * V_4 = (struct V_3 * ) V_63 -> V_67 ;
int V_81 , V_6 = 0 ;
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
V_4 -> V_10 . type = V_104 ;
V_4 -> V_10 . V_9 = sizeof( struct V_18 ) +
sizeof( struct V_105 ) ;
V_4 -> V_106 . V_21 = V_4 -> V_106 . V_107 = V_15 -> V_34 . V_108 ;
V_4 -> V_106 . V_109 = 1 ;
F_1 ( V_2 , V_4 ) ;
V_81 = F_17 ( & V_63 -> V_69 , V_86 ) ;
if ( ! V_81 ) {
F_5 ( L_5 ) ;
V_6 = - V_87 ;
goto V_88;
}
if ( V_4 -> V_110 . V_21 != V_15 -> V_34 . V_108 ) {
F_5 ( L_6 ) ;
V_6 = - V_16 ;
goto V_88;
}
F_8 ( V_2 ) ;
F_6 ( V_2 ) ;
V_88:
return V_6 ;
}
static void F_22 ( struct V_111 * V_112 )
{
struct V_62 * V_63 = F_23 ( V_112 , struct V_62 , V_75 . V_113 ) ;
struct V_14 * V_15 = V_63 -> V_15 ;
if ( V_63 -> V_71 )
F_9 ( V_15 ) ;
if ( V_63 -> V_72 )
F_13 ( & V_63 -> V_75 , V_76 ) ;
}
static int F_24 ( struct V_114 * V_27 , struct V_14 * V_15 )
{
if ( V_27 -> V_30 < V_115 || V_27 -> V_32 < V_116 ||
V_27 -> V_30 > V_117 || V_27 -> V_32 > V_118 ||
V_27 -> V_28 != V_98 )
return - V_119 ;
V_27 -> V_120 = V_27 -> V_30 ;
V_27 -> V_121 = V_27 -> V_32 ;
return 0 ;
}
static int F_25 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 -> V_53 ) ;
return F_6 ( V_2 ) ;
}
static inline T_2 F_26 ( T_2 V_122 , struct V_123 * V_124 )
{
return ( ( V_122 & 0xffff ) >> ( 16 - V_124 -> V_125 ) ) << V_124 -> V_126 ;
}
static int F_27 ( unsigned V_127 , unsigned V_128 , unsigned V_129 ,
unsigned V_130 , unsigned V_131 , struct V_14 * V_15 )
{
T_2 * V_132 = V_15 -> V_133 ;
if ( V_127 > 15 )
return - V_119 ;
V_132 [ V_127 ] = F_26 ( V_128 , & V_15 -> V_27 . V_128 )
| F_26 ( V_129 , & V_15 -> V_27 . V_129 )
| F_26 ( V_130 , & V_15 -> V_27 . V_130 )
| F_26 ( V_131 , & V_15 -> V_27 . V_131 ) ;
return 0 ;
}
static int F_28 ( int V_134 , struct V_14 * V_15 )
{
return 1 ;
}
static void F_29 ( struct V_14 * V_15 )
{
struct V_62 * V_63 = V_15 -> V_63 ;
char * V_135 = NULL , * V_136 ;
T_4 V_137 = 0 , V_138 = 0 ;
if ( F_30 ( V_139 , & V_135 ) || ! V_135 || ! * V_135 )
return;
V_136 = F_31 ( & V_135 , L_7 ) ;
if ( ! * V_136 || F_32 ( V_136 , 0 , & V_137 ) ||
! V_135 || ! * V_135 || F_32 ( V_135 , 0 , & V_138 ) ) {
F_5 ( L_8 ) ;
return;
}
if ( V_137 < V_115 || V_138 < V_116 ||
( V_63 -> V_91 == V_97 &&
V_137 * V_138 * V_98 / 8 > V_103 ) ||
( V_63 -> V_91 == V_96 &&
( V_137 > V_140 || V_138 > V_141 ) ) ) {
F_5 ( L_9 ) ;
return;
}
V_117 = V_137 ;
V_118 = V_138 ;
return;
}
static int F_33 ( struct V_14 * V_15 )
{
struct V_142 * V_143 ;
T_5 V_144 ;
void T_6 * V_145 ;
V_143 = F_34 ( V_146 ,
V_147 , NULL ) ;
if ( ! V_143 ) {
F_5 ( L_10 ) ;
return - V_16 ;
}
if ( ! ( F_35 ( V_143 , 0 ) & V_148 ) ||
F_36 ( V_143 , 0 ) < V_100 )
goto V_149;
V_144 = F_37 ( V_143 , 0 ) - V_100 + 1 ;
if ( ! F_38 ( V_144 , V_100 , V_139 ) )
goto V_149;
V_145 = F_39 ( V_144 , V_100 ) ;
if ( ! V_145 )
goto V_150;
V_15 -> V_151 = F_40 ( 1 ) ;
if ( ! V_15 -> V_151 )
goto V_152;
V_15 -> V_151 -> V_153 [ 0 ] . V_154 = F_41 ( V_143 , 0 ) ;
V_15 -> V_151 -> V_153 [ 0 ] . V_9 = F_36 ( V_143 , 0 ) ;
V_15 -> V_34 . V_108 = V_144 ;
V_15 -> V_34 . V_155 = V_100 ;
V_15 -> V_156 = V_145 ;
V_15 -> V_157 = V_100 ;
F_42 ( V_143 ) ;
return 0 ;
V_152:
F_43 ( V_145 ) ;
V_150:
F_44 ( V_144 , V_100 ) ;
V_149:
F_42 ( V_143 ) ;
return - V_158 ;
}
static void F_45 ( struct V_14 * V_15 )
{
F_43 ( V_15 -> V_156 ) ;
F_44 ( V_15 -> V_34 . V_108 , V_100 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_159 * V_160 )
{
struct V_14 * V_15 ;
struct V_62 * V_63 ;
int V_6 ;
V_15 = F_47 ( sizeof( struct V_62 ) , & V_2 -> V_53 ) ;
if ( ! V_15 ) {
F_5 ( L_11 ) ;
return - V_158 ;
}
V_63 = V_15 -> V_63 ;
V_63 -> V_15 = V_15 ;
V_63 -> V_71 = false ;
F_48 ( & V_63 -> V_69 ) ;
F_49 ( & V_63 -> V_75 , F_22 ) ;
F_50 ( V_2 , V_15 ) ;
V_6 = F_18 ( V_2 ) ;
if ( V_6 ) {
F_5 ( L_12 ) ;
goto V_161;
}
V_6 = F_33 ( V_15 ) ;
if ( V_6 ) {
F_5 ( L_13 ) ;
goto V_162;
}
F_29 ( V_15 ) ;
F_51 ( L_14 ,
V_117 , V_118 , V_98 ) ;
V_15 -> V_163 = V_164 ;
V_15 -> V_27 . V_120 = V_15 -> V_27 . V_30 = V_117 ;
V_15 -> V_27 . V_121 = V_15 -> V_27 . V_32 = V_118 ;
V_15 -> V_27 . V_28 = V_98 ;
if ( V_15 -> V_27 . V_28 == 16 ) {
V_15 -> V_27 . V_128 = (struct V_123 ) { 11 , 5 , 0 } ;
V_15 -> V_27 . V_129 = (struct V_123 ) { 5 , 6 , 0 } ;
V_15 -> V_27 . V_130 = (struct V_123 ) { 0 , 5 , 0 } ;
V_15 -> V_27 . V_131 = (struct V_123 ) { 0 , 0 , 0 } ;
} else {
V_15 -> V_27 . V_128 = (struct V_123 ) { 16 , 8 , 0 } ;
V_15 -> V_27 . V_129 = (struct V_123 ) { 8 , 8 , 0 } ;
V_15 -> V_27 . V_130 = (struct V_123 ) { 0 , 8 , 0 } ;
V_15 -> V_27 . V_131 = (struct V_123 ) { 24 , 8 , 0 } ;
}
V_15 -> V_27 . V_165 = V_166 ;
V_15 -> V_27 . V_49 = - 1 ;
V_15 -> V_27 . V_48 = - 1 ;
V_15 -> V_27 . V_167 = V_168 ;
strcpy ( V_15 -> V_34 . V_169 , V_139 ) ;
V_15 -> V_34 . type = V_170 ;
V_15 -> V_34 . V_171 = V_172 ;
V_15 -> V_34 . V_35 = V_117 * V_98 / 8 ;
V_15 -> V_34 . V_173 = V_174 ;
V_15 -> V_175 = & V_176 ;
V_15 -> V_133 = V_63 -> V_133 ;
V_6 = F_21 ( V_2 ) ;
if ( V_6 )
goto error;
V_6 = F_52 ( V_15 ) ;
if ( V_6 ) {
F_5 ( L_15 ) ;
goto error;
}
V_63 -> V_71 = true ;
return 0 ;
error:
F_45 ( V_15 ) ;
V_162:
F_20 ( V_2 -> V_11 ) ;
V_161:
F_53 ( & V_63 -> V_75 ) ;
F_50 ( V_2 , NULL ) ;
F_54 ( V_15 ) ;
return V_6 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_7 ( V_2 ) ;
struct V_62 * V_63 = V_15 -> V_63 ;
V_63 -> V_72 = false ;
V_63 -> V_71 = false ;
F_56 ( V_15 ) ;
F_53 ( & V_63 -> V_75 ) ;
F_20 ( V_2 -> V_11 ) ;
F_50 ( V_2 , NULL ) ;
F_45 ( V_15 ) ;
F_54 ( V_15 ) ;
return 0 ;
}
static int F_57 ( struct V_142 * V_143 ,
const struct V_177 * V_178 )
{
return 0 ;
}
static void F_58 ( struct V_142 * V_143 )
{
}
static int T_7 F_59 ( void )
{
int V_6 ;
V_6 = F_60 ( & V_179 ) ;
if ( V_6 != 0 )
return V_6 ;
V_6 = F_61 ( & V_180 ) ;
if ( V_6 != 0 ) {
F_62 ( & V_179 ) ;
return V_6 ;
}
return 0 ;
}
static void T_8 F_63 ( void )
{
F_64 ( & V_180 ) ;
F_62 ( & V_179 ) ;
}
