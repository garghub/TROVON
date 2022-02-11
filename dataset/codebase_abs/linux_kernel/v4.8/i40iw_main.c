static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_3 (hdl, &i40iw_handlers, list) {
if ( V_4 -> V_3 . V_7 == V_3 -> V_7 ) {
F_4 ( & V_6 , V_5 ) ;
return V_4 ;
}
}
F_4 ( & V_6 , V_5 ) ;
return NULL ;
}
struct V_1 * F_5 ( struct V_8 * V_7 )
{
struct V_1 * V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_3 (hdl, &i40iw_handlers, list) {
if ( V_4 -> V_3 . V_7 == V_7 ) {
F_4 ( & V_6 , V_5 ) ;
return V_4 ;
}
}
F_4 ( & V_6 , V_5 ) ;
return NULL ;
}
static void F_6 ( struct V_1 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_7 ( & V_4 -> V_9 , & V_10 ) ;
F_4 ( & V_6 , V_5 ) ;
}
static int F_8 ( struct V_1 * V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
F_9 ( & V_4 -> V_9 ) ;
F_4 ( & V_6 , V_5 ) ;
return 0 ;
}
static void F_10 ( struct V_11 * V_12 , T_1 V_13 )
{
T_1 V_14 ;
V_14 = V_15 |
V_16 |
( 3 << V_17 ) ;
if ( V_12 -> V_18 )
F_11 ( V_12 -> V_19 , F_12 ( V_13 - 1 ) , V_14 ) ;
else
F_11 ( V_12 -> V_19 , F_13 ( V_13 - 1 ) , V_14 ) ;
}
static void F_14 ( unsigned long V_20 )
{
struct V_21 * V_22 = (struct V_21 * ) V_20 ;
if ( V_22 -> V_23 )
F_15 ( V_22 , V_22 -> V_24 ) ;
F_16 ( V_22 ) ;
F_10 ( & V_22 -> V_25 , V_22 -> V_26 [ 0 ] . V_27 ) ;
}
static void F_17 ( unsigned long V_20 )
{
struct V_28 * V_29 = (struct V_28 * ) V_20 ;
struct V_21 * V_22 = V_29 -> V_22 ;
F_15 ( V_22 , V_29 ) ;
F_10 ( & V_22 -> V_25 , V_29 -> V_30 ) ;
}
static T_2 F_18 ( int V_31 , void * V_20 )
{
struct V_21 * V_22 = (struct V_21 * ) V_20 ;
F_19 ( & V_22 -> V_32 ) ;
return V_33 ;
}
static void F_20 ( struct V_21 * V_22 , bool V_34 )
{
enum V_35 V_36 = 0 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_37 * V_38 = & V_22 -> V_38 ;
if ( V_34 && V_12 -> V_39 -> V_40 )
V_36 = V_12 -> V_39 -> V_40 ( V_12 -> V_38 ) ;
if ( V_36 )
F_21 ( L_1 ) ;
F_22 ( V_12 -> V_19 , & V_38 -> V_41 ) ;
F_23 ( V_38 -> V_42 ) ;
V_22 -> V_38 . V_42 = NULL ;
F_23 ( V_38 -> V_43 ) ;
V_38 -> V_43 = NULL ;
}
static void F_24 ( struct V_11 * V_12 ,
struct V_44 * V_45 ,
void * V_46 )
{
if ( V_12 -> V_18 )
F_11 ( V_12 -> V_19 , F_12 ( V_45 -> V_27 - 1 ) , 0 ) ;
else
F_11 ( V_12 -> V_19 , F_13 ( V_45 -> V_27 - 1 ) , 0 ) ;
F_25 ( V_45 -> V_31 , V_46 ) ;
}
static void F_26 ( struct V_21 * V_22 , bool V_47 )
{
enum V_35 V_36 = V_48 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_49 * V_50 = & V_22 -> V_50 ;
if ( ! V_22 -> V_23 )
F_24 ( V_12 , V_22 -> V_26 , ( void * ) V_22 ) ;
if ( V_47 )
goto exit;
if ( ! V_12 -> V_51 -> V_52 ( & V_50 -> V_53 , 0 , 1 ) )
V_36 = V_12 -> V_51 -> V_54 ( & V_50 -> V_53 ) ;
if ( V_36 )
F_21 ( L_2 , V_36 ) ;
exit:
F_22 ( V_12 -> V_19 , & V_50 -> V_55 ) ;
}
static void F_27 ( struct V_21 * V_22 ,
struct V_28 * V_29 ,
bool V_47 )
{
enum V_35 V_36 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
if ( V_47 )
goto exit;
V_36 = V_12 -> V_56 -> V_57 ( & V_29 -> V_58 , 0 , 1 ) ;
if ( V_36 ) {
F_21 ( L_3 , V_36 ) ;
goto exit;
}
V_36 = V_12 -> V_56 -> V_59 ( & V_29 -> V_58 ) ;
if ( V_36 )
F_21 ( L_4 , V_36 ) ;
exit:
F_22 ( V_12 -> V_19 , & V_29 -> V_55 ) ;
}
static void F_28 ( struct V_21 * V_22 , bool V_47 )
{
T_1 V_60 = 0 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_28 * V_29 = V_22 -> V_24 ;
struct V_44 * V_45 = V_22 -> V_26 ;
if ( V_22 -> V_23 ) {
F_24 ( V_12 , V_45 , ( void * ) V_22 ) ;
F_27 ( V_22 , V_29 , V_47 ) ;
V_29 ++ ;
V_60 ++ ;
}
for ( V_45 ++ ; V_60 < V_22 -> V_61 ; V_60 ++ , V_45 ++ , V_29 ++ ) {
F_24 ( V_12 , V_45 , ( void * ) V_29 ) ;
F_27 ( V_22 , V_29 , V_47 ) ;
}
}
static void F_29 ( struct V_21 * V_22 , bool V_47 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_62 * V_63 = & V_22 -> V_63 ;
enum V_35 V_36 = 0 ;
if ( ! V_47 )
V_36 = V_12 -> V_64 -> V_65 ( V_12 -> V_63 , 0 , true ) ;
if ( V_36 )
F_21 ( L_5 , V_36 ) ;
F_22 ( V_12 -> V_19 , & V_63 -> V_66 ) ;
}
static void F_30 ( struct V_11 * V_12 ,
enum V_67 V_68 ,
struct V_69 * V_70 ,
bool V_18 ,
bool V_47 )
{
struct V_71 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_70 = V_70 ;
V_72 . V_73 = V_68 ;
V_72 . V_74 = V_70 -> V_75 [ V_68 ] . V_76 ;
V_72 . V_18 = V_18 ;
if ( V_12 -> V_77 -> V_78 ( V_12 , & V_72 , V_47 ) )
F_21 ( L_6 , V_68 ) ;
}
static void F_31 ( struct V_11 * V_12 ,
struct V_69 * V_70 ,
bool V_18 ,
bool V_47 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_79 ; V_60 ++ )
F_30 ( V_12 , V_80 [ V_60 ] , V_70 , V_18 , V_47 ) ;
}
static T_2 F_32 ( int V_31 , void * V_20 )
{
struct V_28 * V_29 = (struct V_28 * ) V_20 ;
if ( V_29 -> V_31 != V_31 )
F_21 ( L_7 , V_29 -> V_31 , V_31 ) ;
F_19 ( & V_29 -> V_32 ) ;
return V_33 ;
}
static enum V_35 F_33 ( struct V_11 * V_12 ,
struct V_81 * V_72 )
{
return V_12 -> V_77 -> V_82 ( V_12 , V_72 ) ;
}
static enum V_35 F_34 ( struct V_21 * V_22 ,
bool V_18 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_81 V_72 ;
enum V_35 V_36 ;
int V_60 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_70 = V_12 -> V_70 ;
V_72 . V_18 = V_18 ;
V_72 . V_83 = V_22 -> V_84 ;
for ( V_60 = 0 ; V_60 < V_79 ; V_60 ++ ) {
V_72 . V_73 = V_80 [ V_60 ] ;
V_72 . V_74 = V_12 -> V_70 -> V_75 [ V_72 . V_73 ] . V_76 ;
V_36 = F_33 ( V_12 , & V_72 ) ;
if ( V_36 ) {
F_21 ( L_8 ,
V_80 [ V_60 ] , V_36 ) ;
break;
}
}
if ( ! V_36 )
return ( V_12 -> V_85 -> V_86 ( V_12 -> V_38 , 0 ,
V_12 -> V_87 ,
true , true ) ) ;
while ( V_60 ) {
V_60 -- ;
F_30 ( V_12 ,
V_80 [ V_60 ] ,
V_12 -> V_70 ,
V_18 ,
false ) ;
}
return V_36 ;
}
enum V_35 F_35 ( struct V_21 * V_22 ,
struct V_88 * V_89 ,
T_1 V_90 ,
T_1 V_91 )
{
unsigned long V_92 , V_93 ;
unsigned long V_94 ;
V_92 = ( unsigned long ) V_22 -> V_95 . V_92 ;
V_93 = V_92 ;
if ( V_91 )
V_93 = F_36 ( V_92 , ( V_91 + 1 ) ) ;
V_94 = V_93 - V_92 ;
V_89 -> V_92 = ( V_96 * ) V_92 + V_94 ;
V_89 -> V_97 = V_22 -> V_95 . V_97 + V_94 ;
V_89 -> V_90 = V_90 ;
if ( ( V_89 -> V_92 + V_90 ) > ( V_22 -> V_98 . V_92 + V_22 -> V_98 . V_90 ) )
return V_99 ;
V_22 -> V_95 . V_92 = V_89 -> V_92 + V_90 ;
V_22 -> V_95 . V_97 = V_89 -> V_97 + V_90 ;
return 0 ;
}
static enum V_35 F_37 ( struct V_21 * V_22 )
{
enum V_35 V_36 ;
T_1 V_100 = V_101 ;
struct V_88 V_55 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_102 V_103 ;
struct V_37 * V_38 = & V_22 -> V_38 ;
T_3 V_104 , V_105 ;
int V_60 ;
V_38 -> V_43 = F_38 ( V_100 , sizeof( * V_38 -> V_43 ) , V_106 ) ;
if ( ! V_38 -> V_43 )
return V_99 ;
V_38 -> V_42 = F_38 ( V_100 , sizeof( * V_38 -> V_42 ) , V_106 ) ;
if ( ! V_38 -> V_42 ) {
F_23 ( V_38 -> V_43 ) ;
return V_99 ;
}
V_12 -> V_38 = & V_38 -> V_107 ;
V_12 -> V_38 -> V_12 = V_12 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_36 = F_39 ( V_12 -> V_19 , & V_38 -> V_41 ,
( sizeof( struct V_108 ) * V_100 ) ,
V_109 ) ;
if ( V_36 )
goto exit;
V_36 = F_35 ( V_22 , & V_55 , sizeof( struct V_110 ) ,
V_111 ) ;
if ( V_36 )
goto exit;
V_12 -> V_38 -> V_112 = V_55 . V_97 ;
V_12 -> V_38 -> V_113 = V_55 . V_92 ;
V_103 . V_12 = V_12 ;
V_103 . V_114 = V_100 ;
V_103 . V_41 = V_38 -> V_41 . V_92 ;
V_103 . V_115 = V_38 -> V_41 . V_97 ;
V_103 . V_112 = V_55 . V_97 ;
V_103 . V_113 = V_55 . V_92 ;
V_103 . V_116 = V_22 -> V_117 ;
V_103 . V_118 = V_22 -> V_119 ;
V_103 . V_42 = V_38 -> V_42 ;
V_36 = V_12 -> V_39 -> V_120 ( V_12 -> V_38 , & V_103 ) ;
if ( V_36 ) {
F_21 ( L_9 , V_36 ) ;
goto exit;
}
V_36 = V_12 -> V_39 -> V_121 ( V_12 -> V_38 , true , & V_104 , & V_105 ) ;
if ( V_36 ) {
F_21 ( L_10 ,
V_36 , V_104 , V_105 ) ;
goto exit;
}
F_40 ( & V_38 -> V_122 ) ;
F_41 ( & V_38 -> V_123 ) ;
F_41 ( & V_38 -> V_124 ) ;
for ( V_60 = 0 ; V_60 < V_101 ; V_60 ++ ) {
F_42 ( & V_38 -> V_43 [ V_60 ] . V_125 ) ;
F_43 ( & V_38 -> V_43 [ V_60 ] . V_9 , & V_38 -> V_123 ) ;
}
return 0 ;
exit:
F_20 ( V_22 , false ) ;
return V_36 ;
}
static enum V_35 F_44 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_88 V_55 ;
enum V_35 V_36 ;
struct V_126 V_72 ;
struct V_62 * V_63 = & V_22 -> V_63 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_12 -> V_63 = & V_63 -> V_127 ;
V_12 -> V_63 -> V_12 = V_12 ;
V_72 . V_12 = V_12 ;
V_63 -> V_128 . V_90 = sizeof( struct V_129 ) ;
V_63 -> V_66 . V_90 = sizeof( struct V_130 ) * V_131 ;
V_36 = F_39 ( V_12 -> V_19 , & V_63 -> V_66 ,
V_63 -> V_66 . V_90 , V_132 ) ;
if ( V_36 )
goto exit;
V_36 = F_35 ( V_22 , & V_55 , V_63 -> V_128 . V_90 ,
V_133 ) ;
if ( V_36 )
goto exit;
V_63 -> V_127 . V_134 = ( void * ) V_63 ;
V_72 . V_135 = V_63 -> V_66 . V_92 ;
V_72 . V_136 = V_63 -> V_66 . V_97 ;
V_72 . V_137 = V_131 ;
V_72 . V_128 = V_55 . V_92 ;
V_72 . V_138 = V_55 . V_97 ;
V_72 . V_139 = false ;
V_72 . V_140 = true ;
V_72 . V_141 = 16 ;
V_36 = V_12 -> V_64 -> V_142 ( V_12 -> V_63 , & V_72 ) ;
if ( ! V_36 )
V_36 = V_12 -> V_64 -> V_143 ( V_12 -> V_63 , 0 , true , true ) ;
exit:
if ( V_36 )
F_22 ( V_12 -> V_19 , & V_63 -> V_66 ) ;
return V_36 ;
}
static enum V_35 F_45 ( struct V_21 * V_22 ,
struct V_28 * V_29 ,
T_1 V_144 ,
struct V_44 * V_45 )
{
enum V_35 V_36 ;
if ( V_22 -> V_23 && ! V_144 ) {
F_46 ( & V_22 -> V_32 , F_14 , ( unsigned long ) V_22 ) ;
V_36 = F_47 ( V_45 -> V_31 , F_18 , 0 , L_11 , V_22 ) ;
} else {
F_46 ( & V_29 -> V_32 , F_17 , ( unsigned long ) V_29 ) ;
V_36 = F_47 ( V_45 -> V_31 , F_32 , 0 , L_12 , V_29 ) ;
}
if ( V_36 ) {
F_21 ( L_13 ) ;
return V_145 ;
}
V_45 -> V_144 = V_144 ;
V_45 -> V_146 = 0 ;
return 0 ;
}
static enum V_35 F_48 ( struct V_21 * V_22 ,
struct V_28 * V_29 ,
T_1 V_144 )
{
enum V_35 V_36 ;
struct V_147 V_72 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
T_4 V_148 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_144 = V_144 ;
V_29 -> V_22 = V_22 ;
V_29 -> V_55 . V_90 = sizeof( struct V_149 ) *
V_22 -> V_25 . V_70 -> V_75 [ V_150 ] . V_76 ;
V_36 = F_39 ( V_12 -> V_19 , & V_29 -> V_55 , V_29 -> V_55 . V_90 ,
V_151 ) ;
if ( V_36 )
goto exit;
V_72 . V_144 = V_144 ;
V_72 . V_152 = V_29 -> V_55 . V_92 ;
V_72 . V_153 = V_29 -> V_55 . V_97 ;
V_72 . V_154 = V_22 -> V_25 . V_70 -> V_75 [ V_150 ] . V_76 ;
V_29 -> V_58 . V_144 = V_144 ;
V_72 . V_12 = V_12 ;
V_148 = ( V_155 ) & V_22 -> V_38 . V_107 ;
V_36 = V_12 -> V_56 -> V_156 ( & V_29 -> V_58 , & V_72 ) ;
if ( ! V_36 )
V_36 = V_12 -> V_56 -> V_157 ( & V_29 -> V_58 , V_148 ) ;
exit:
if ( V_36 )
F_22 ( V_12 -> V_19 , & V_29 -> V_55 ) ;
return V_36 ;
}
void F_49 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_3 ;
V_3 -> V_158 -> V_159 ( V_3 , V_22 -> V_160 , 1 ) ;
}
static enum V_35 F_50 ( struct V_21 * V_22 ,
struct V_2 * V_3 )
{
T_1 V_60 ;
T_1 V_144 ;
struct V_28 * V_29 ;
struct V_44 * V_45 ;
enum V_35 V_36 = 0 ;
T_1 V_161 ;
if ( V_3 && V_3 -> V_158 && V_3 -> V_158 -> V_162 ) {
V_36 = V_3 -> V_158 -> V_162 ( V_3 , & V_163 ,
V_22 -> V_164 ) ;
if ( V_36 )
goto exit;
} else {
V_36 = V_165 ;
goto exit;
}
V_161 = F_51 ( V_22 -> V_166 , V_22 -> V_25 . V_167 . V_168 ) ;
V_22 -> V_24 = F_38 ( V_161 , sizeof( * V_22 -> V_24 ) , V_106 ) ;
if ( ! V_22 -> V_24 ) {
V_36 = V_99 ;
goto exit;
}
V_60 = ( V_22 -> V_23 ) ? 0 : 1 ;
for ( V_144 = 0 ; V_60 < V_161 ; V_60 ++ , V_144 ++ ) {
V_29 = & V_22 -> V_24 [ V_144 ] ;
V_36 = F_48 ( V_22 , V_29 , V_144 ) ;
if ( V_36 ) {
F_21 ( L_14 , V_36 ) ;
break;
}
V_45 = & V_22 -> V_26 [ V_60 ] ;
V_29 -> V_31 = V_45 -> V_31 ;
V_29 -> V_30 = V_45 -> V_27 ;
V_36 = F_45 ( V_22 , V_29 , V_144 , V_45 ) ;
if ( V_36 ) {
F_27 ( V_22 , V_29 , false ) ;
break;
}
F_10 ( & V_22 -> V_25 , V_45 -> V_27 ) ;
V_22 -> V_61 ++ ;
}
exit:
if ( V_36 ) {
if ( ! V_22 -> V_61 ) {
F_23 ( V_22 -> V_24 ) ;
V_22 -> V_24 = NULL ;
} else {
V_36 = 0 ;
}
}
return V_36 ;
}
static enum V_35 F_52 ( struct V_21 * V_22 )
{
struct V_44 * V_45 = V_22 -> V_26 ;
T_1 V_169 = 0 ;
if ( ! V_22 -> V_23 ) {
F_46 ( & V_22 -> V_32 , F_14 , ( unsigned long ) V_22 ) ;
V_169 = F_47 ( V_45 -> V_31 , F_18 , 0 , L_15 , V_22 ) ;
}
if ( V_169 ) {
F_21 ( L_16 ) ;
return V_145 ;
}
return 0 ;
}
static enum V_35 F_53 ( struct V_21 * V_22 )
{
enum V_35 V_36 ;
struct V_170 V_72 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_49 * V_50 = & V_22 -> V_50 ;
T_4 V_148 = 0 ;
T_1 V_171 ;
V_171 = 2 * V_22 -> V_25 . V_70 -> V_75 [ V_172 ] . V_76 +
V_22 -> V_25 . V_70 -> V_75 [ V_150 ] . V_76 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_50 -> V_55 . V_90 = sizeof( struct V_173 ) * V_171 ;
V_36 = F_39 ( V_12 -> V_19 , & V_50 -> V_55 , V_50 -> V_55 . V_90 ,
V_174 ) ;
if ( V_36 )
goto exit;
V_72 . V_175 = V_50 -> V_55 . V_92 ;
V_72 . V_176 = V_50 -> V_55 . V_97 ;
V_72 . V_154 = V_171 ;
V_72 . V_12 = V_12 ;
V_36 = V_12 -> V_51 -> V_177 ( & V_50 -> V_53 , & V_72 ) ;
if ( V_36 )
goto exit;
V_36 = V_12 -> V_51 -> V_178 ( & V_50 -> V_53 , V_148 , 1 ) ;
if ( ! V_36 )
V_36 = V_12 -> V_51 -> V_179 ( & V_50 -> V_53 ) ;
exit:
if ( V_36 )
F_22 ( V_12 -> V_19 , & V_50 -> V_55 ) ;
return V_36 ;
}
static enum V_35 F_54 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
enum V_35 V_36 ;
V_36 = F_53 ( V_22 ) ;
if ( V_36 )
return V_36 ;
V_36 = F_52 ( V_22 ) ;
if ( V_36 ) {
F_26 ( V_22 , false ) ;
return V_36 ;
}
if ( ! V_22 -> V_23 )
F_10 ( V_12 , V_22 -> V_26 [ 0 ] . V_27 ) ;
return 0 ;
}
static enum V_35 F_55 ( struct V_21 * V_22 )
{
struct V_180 V_72 ;
enum V_35 V_36 ;
V_72 . type = V_181 ;
V_72 . V_182 = 1 ;
V_72 . V_183 = 0 ;
V_72 . V_74 = 1 ;
V_72 . V_184 = 1 ;
V_72 . V_114 = 8192 ;
V_72 . V_185 = 8192 ;
V_72 . V_186 = 1024 ;
V_72 . V_187 = 16384 ;
V_72 . V_188 = V_22 -> V_188 ;
V_72 . V_189 = V_190 ;
V_72 . V_191 = V_192 ;
V_36 = F_56 ( & V_22 -> V_25 , & V_72 ) ;
if ( V_36 )
F_21 ( L_17 ) ;
return V_36 ;
}
static enum V_35 F_57 ( struct V_21 * V_22 )
{
struct V_180 V_72 ;
enum V_35 V_36 ;
V_72 . type = V_193 ;
V_72 . V_182 = 2 ;
V_72 . V_183 = V_22 -> V_25 . V_194 ;
V_72 . V_74 = 1 ;
V_72 . V_184 = 2 ;
V_72 . V_114 = 8192 ;
V_72 . V_185 = 8192 ;
V_72 . V_186 = 2048 ;
V_72 . V_188 = V_22 -> V_188 ;
V_72 . V_187 = 16384 ;
V_36 = F_56 ( & V_22 -> V_25 , & V_72 ) ;
if ( V_36 )
F_21 ( L_18 ) ;
return V_36 ;
}
static enum V_35 F_58 ( struct V_21 * V_22 )
{
enum V_35 V_36 ;
V_22 -> V_84 = V_195 ;
V_36 = F_59 ( & V_22 -> V_25 , V_196 ) ;
if ( V_36 )
goto exit;
V_36 = F_34 ( V_22 , true ) ;
if ( V_36 )
goto exit;
V_22 -> V_197 = V_198 ;
exit:
return V_36 ;
}
static void F_60 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
F_22 ( & V_22 -> V_19 , & V_22 -> V_98 ) ;
F_23 ( V_12 -> V_70 -> V_199 . V_200 ) ;
V_12 -> V_70 -> V_199 . V_200 = NULL ;
F_23 ( V_22 -> V_201 ) ;
V_22 -> V_201 = NULL ;
F_23 ( V_22 -> V_24 ) ;
V_22 -> V_24 = NULL ;
F_23 ( V_22 -> V_26 ) ;
V_22 -> V_26 = NULL ;
F_23 ( V_22 -> V_202 ) ;
V_22 -> V_202 = NULL ;
}
static void F_61 ( struct V_21 * V_22 , V_96 V_27 )
{
struct V_37 * V_203 = & V_22 -> V_38 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
enum V_35 V_36 = 0 ;
V_205 = F_62 ( V_203 , true ) ;
if ( ! V_205 ) {
F_21 ( L_19 ) ;
return;
}
V_207 = & V_205 -> V_72 ;
V_207 -> V_208 = V_209 ;
V_207 -> V_210 = 1 ;
V_207 -> V_211 . V_212 . V_213 . V_38 = & V_203 -> V_107 ;
V_207 -> V_211 . V_212 . V_213 . V_148 = ( V_155 ) V_205 ;
V_207 -> V_211 . V_212 . V_213 . V_214 = V_27 ;
V_207 -> V_211 . V_212 . V_213 . V_215 = 0 ;
V_36 = F_63 ( V_22 , V_205 ) ;
if ( V_36 )
F_21 ( L_20 ) ;
}
static enum V_35 F_64 ( struct V_21 * V_22 ,
V_96 * V_216 ,
V_96 V_27 )
{
struct V_217 * V_72 ;
struct V_37 * V_203 = & V_22 -> V_38 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
enum V_35 V_36 = 0 ;
V_205 = F_62 ( V_203 , true ) ;
if ( ! V_205 ) {
F_21 ( L_19 ) ;
return V_99 ;
}
V_207 = & V_205 -> V_72 ;
V_207 -> V_210 = 1 ;
V_72 = & V_207 -> V_211 . V_212 . V_218 . V_72 ;
F_65 ( V_72 -> V_216 , V_216 ) ;
V_72 -> V_214 = V_27 ;
V_207 -> V_211 . V_212 . V_218 . V_148 = ( V_155 ) V_205 ;
V_207 -> V_208 = V_219 ;
V_207 -> V_211 . V_212 . V_218 . V_38 = & V_203 -> V_107 ;
V_207 -> V_211 . V_212 . V_218 . V_148 = ( V_155 ) V_205 ;
V_36 = F_63 ( V_22 , V_205 ) ;
if ( V_36 )
F_21 ( L_21 ) ;
return V_36 ;
}
static enum V_35 F_66 ( struct V_21 * V_22 ,
T_3 * V_220 )
{
struct V_37 * V_203 = & V_22 -> V_38 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
enum V_35 V_36 = 0 ;
V_205 = F_62 ( V_203 , true ) ;
if ( ! V_205 ) {
F_21 ( L_19 ) ;
return V_99 ;
}
F_67 ( & V_205 -> V_221 ) ;
V_207 = & V_205 -> V_72 ;
V_207 -> V_208 = V_222 ;
V_207 -> V_210 = 1 ;
V_207 -> V_211 . V_212 . V_223 . V_38 = & V_203 -> V_107 ;
V_207 -> V_211 . V_212 . V_223 . V_148 = ( V_155 ) V_205 ;
V_36 = F_63 ( V_22 , V_205 ) ;
if ( ! V_36 )
* V_220 = V_205 -> V_224 . V_225 ;
else
F_21 ( L_22 ) ;
F_68 ( V_203 , V_205 ) ;
return V_36 ;
}
static enum V_35 F_69 ( struct V_21 * V_22 ,
V_96 * V_226 )
{
enum V_35 V_36 ;
V_36 = F_66 ( V_22 , & V_22 -> V_227 ) ;
if ( ! V_36 ) {
V_36 = F_64 ( V_22 , V_226 ,
( V_96 ) V_22 -> V_227 ) ;
if ( V_36 )
F_61 ( V_22 , ( V_96 ) V_22 -> V_227 ) ;
}
return V_36 ;
}
static void F_70 ( struct V_21 * V_22 )
{
struct V_8 * V_228 ;
struct V_229 * V_230 ;
struct V_231 * V_232 ;
T_1 V_233 [ 4 ] ;
F_71 () ;
F_72 (&init_net, ip_dev) {
if ( ( ( ( F_73 ( V_228 ) < 0xFFFF ) &&
( F_74 ( V_228 ) == V_22 -> V_7 ) ) ||
( V_228 == V_22 -> V_7 ) ) && ( V_228 -> V_5 & V_234 ) ) {
V_230 = F_75 ( V_228 ) ;
if ( ! V_230 ) {
F_21 ( L_23 ) ;
break;
}
F_3 (ifp, &idev->addr_list, if_list) {
F_76 ( L_24 , & V_232 -> V_235 ,
F_73 ( V_228 ) , V_228 -> V_236 ) ;
F_77 ( V_233 ,
V_232 -> V_235 . V_237 . V_238 ) ;
F_78 ( V_22 ,
V_228 -> V_236 ,
V_233 ,
false ,
V_239 ) ;
}
}
}
F_79 () ;
}
static void F_80 ( struct V_21 * V_22 )
{
struct V_8 * V_12 ;
struct V_240 * V_230 ;
bool V_241 = true ;
T_1 V_242 ;
if ( ! F_81 () )
V_241 = false ;
F_82 (&init_net, dev) {
if ( ( ( ( F_73 ( V_12 ) < 0xFFFF ) &&
( F_74 ( V_12 ) == V_22 -> V_7 ) ) ||
( V_12 == V_22 -> V_7 ) ) && ( V_12 -> V_5 & V_234 ) ) {
V_230 = F_83 ( V_12 ) ;
F_84 (idev) {
F_85 ( & V_22 -> V_25 , V_243 ,
L_25 , & V_244 -> V_245 ,
F_73 ( V_12 ) , V_12 -> V_236 ) ;
V_242 = F_86 ( V_244 -> V_245 ) ;
F_78 ( V_22 ,
V_12 -> V_236 ,
& V_242 ,
true ,
V_239 ) ;
}
F_87 ( V_230 ) ;
F_88 ( V_230 ) ;
}
}
if ( V_241 )
F_89 () ;
}
static enum V_35 F_90 ( struct V_21 * V_22 )
{
struct V_8 * V_7 = V_22 -> V_7 ;
enum V_35 V_36 ;
V_36 = F_69 ( V_22 , ( V_96 * ) V_7 -> V_236 ) ;
if ( V_36 )
return V_36 ;
F_80 ( V_22 ) ;
F_70 ( V_22 ) ;
return 0 ;
}
static void F_91 ( struct V_246 * V_19 )
{
T_1 V_247 ;
T_1 V_248 ;
T_1 V_249 ;
T_1 V_250 ;
T_1 V_251 = 0 ;
do {
V_247 = F_92 ( V_19 , V_252 ) ;
F_76 ( L_26 , __LINE__ , V_247 ) ;
V_248 = F_92 ( V_19 , V_253 ) ;
F_76 ( L_27 , __LINE__ , V_248 ) ;
V_249 = F_92 ( V_19 , V_254 ) ;
F_76 ( L_28 ,
__LINE__ , V_249 ) ;
V_250 = F_92 ( V_19 , V_255 ) ;
F_76 ( L_29 ,
__LINE__ , V_250 ) ;
if ( ( V_248 == 0x80 ) && ( V_249 == 0x80 ) && ( V_250 == 0x80 ) )
break;
F_93 ( 1000 ) ;
V_251 ++ ;
} while ( V_251 < 14 );
F_11 ( V_19 , 0xb4040 , 0x4C104C5 ) ;
}
static enum V_35 F_94 ( struct V_21 * V_22 ,
struct V_2 * V_3 )
{
enum V_35 V_36 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_256 V_72 ;
struct V_88 V_55 ;
T_1 V_90 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_90 = sizeof( struct V_257 ) + sizeof( struct V_69 ) +
( sizeof( struct V_258 ) * V_259 ) ;
V_22 -> V_202 = F_95 ( V_90 , V_106 ) ;
if ( ! V_22 -> V_202 ) {
F_21 ( L_30 ) ;
return V_99 ;
}
V_22 -> V_260 = (struct V_257 * ) V_22 -> V_202 ;
V_12 -> V_70 = & V_22 -> V_19 . V_261 ;
V_12 -> V_70 -> V_75 = (struct V_258 * ) ( V_22 -> V_260 + 1 ) ;
V_36 = F_35 ( V_22 , & V_55 , V_262 ,
V_263 ) ;
if ( V_36 )
goto exit;
V_72 . V_264 = V_55 . V_97 ;
V_72 . V_265 = V_55 . V_92 ;
V_36 = F_35 ( V_22 , & V_55 , V_266 ,
V_267 ) ;
if ( V_36 )
goto exit;
V_72 . V_268 = V_55 . V_97 ;
V_72 . V_269 = V_55 . V_92 ;
V_72 . V_87 = V_3 -> V_270 ;
V_72 . V_18 = ( V_3 -> V_271 ) ? false : true ;
V_72 . V_272 = V_3 -> V_273 ;
V_72 . V_19 = & V_22 -> V_19 ;
V_72 . V_274 = V_275 ;
V_72 . V_276 = V_3 -> V_277 . V_278 . V_279 [ 0 ] . V_276 ;
V_72 . V_194 = 1 ;
V_72 . V_280 = V_281 ;
V_36 = F_96 ( & V_22 -> V_25 , & V_72 ) ;
exit:
if ( V_36 ) {
F_23 ( V_22 -> V_202 ) ;
V_22 -> V_202 = NULL ;
}
return V_36 ;
}
static void F_97 ( void )
{
if ( F_98 ( & V_282 ) == 1 ) {
F_99 ( & V_283 ) ;
F_100 ( & V_284 ) ;
F_101 ( & V_285 ) ;
}
}
static enum V_35 F_102 ( struct V_21 * V_22 ,
struct V_2 * V_3 )
{
struct V_286 * V_164 ;
struct V_287 * V_288 ;
T_1 V_289 ;
T_1 V_60 ;
T_1 V_90 ;
V_22 -> V_166 = V_3 -> V_166 ;
V_90 = sizeof( struct V_44 ) * V_22 -> V_166 ;
V_90 += sizeof( struct V_286 ) ;
V_90 += sizeof( struct V_287 ) * V_22 -> V_166 - 1 ;
V_22 -> V_26 = F_95 ( V_90 , V_106 ) ;
if ( ! V_22 -> V_26 )
return V_99 ;
V_22 -> V_164 = (struct V_286 * ) ( & V_22 -> V_26 [ V_22 -> V_166 ] ) ;
V_164 = V_22 -> V_164 ;
V_288 = V_164 -> V_290 ;
V_164 -> V_291 = V_22 -> V_166 ;
if ( V_22 -> V_166 <= F_103 () )
V_22 -> V_23 = true ;
for ( V_60 = 0 , V_289 = 0 ; V_60 < V_22 -> V_166 ; V_60 ++ , V_288 ++ ) {
V_22 -> V_26 [ V_60 ] . V_27 = V_3 -> V_292 [ V_60 ] . V_293 ;
V_22 -> V_26 [ V_60 ] . V_31 = V_3 -> V_292 [ V_60 ] . V_294 ;
if ( V_60 == 0 ) {
V_288 -> V_295 = 0 ;
if ( V_22 -> V_23 )
V_288 -> V_289 = V_289 ++ ;
else
V_288 -> V_289 = V_296 ;
} else {
V_288 -> V_295 = V_296 ;
V_288 -> V_289 = V_289 ++ ;
}
V_288 -> V_297 = 3 ;
V_288 -> V_298 = V_22 -> V_26 [ V_60 ] . V_27 ;
}
return 0 ;
}
static void F_104 ( struct V_21 * V_22 , bool V_47 , bool V_299 )
{
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
F_76 ( L_31 , V_22 -> V_197 ) ;
switch ( V_22 -> V_197 ) {
case V_300 :
V_22 -> V_301 = 0 ;
F_105 ( V_22 ) ;
F_106 ( V_22 -> V_302 ) ;
case V_303 :
if ( ! V_47 )
F_61 ( V_22 , ( V_96 ) V_22 -> V_227 ) ;
case V_304 :
if ( ! F_107 ( & V_282 ) ) {
F_108 ( & V_285 ) ;
F_109 ( & V_283 ) ;
F_110 ( & V_284 ) ;
}
case V_305 :
F_28 ( V_22 , V_47 ) ;
case V_306 :
F_26 ( V_22 , V_47 ) ;
case V_307 :
F_111 ( V_12 , V_193 , V_47 ) ;
case V_308 :
F_111 ( V_12 , V_181 , V_47 ) ;
case V_309 :
F_29 ( V_22 , V_47 ) ;
case V_310 :
F_112 ( V_12 , V_22 -> V_260 ) ;
case V_198 :
F_31 ( V_12 , V_12 -> V_70 , true , V_47 ) ;
case V_311 :
F_20 ( V_22 , ! V_47 ) ;
case V_312 :
F_113 ( & V_22 -> V_313 ) ;
if ( V_12 -> V_18 )
F_114 ( V_12 ) ;
F_60 ( V_22 ) ;
break;
case V_314 :
default:
F_21 ( L_32 , V_22 -> V_197 ) ;
break;
}
if ( V_299 )
F_8 ( F_1 ( V_3 ) ) ;
F_23 ( V_22 -> V_4 ) ;
}
static enum V_35 F_115 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_315 * V_160 )
{
struct V_21 * V_22 = & V_4 -> V_316 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
enum V_35 V_36 ;
memcpy ( & V_4 -> V_3 , V_3 , sizeof( * V_3 ) ) ;
if ( V_117 == 1 )
V_117 = 2 ;
V_22 -> V_317 = V_317 ;
V_22 -> V_117 = ( V_117 < V_318 ) ?
( V_96 ) V_117 + V_319 :
V_319 ;
V_22 -> V_119 =
( V_22 -> V_117 != V_319 ) ? V_119 : 0 ;
V_22 -> V_320 = V_22 -> V_119 ;
V_22 -> V_7 = V_3 -> V_7 ;
V_4 -> V_160 = V_160 ;
V_22 -> V_188 = ( ! V_3 -> V_277 . V_321 ) ? V_322 : V_3 -> V_277 . V_321 - V_323 ;
if ( ! V_3 -> V_271 )
V_22 -> V_324 = F_116 ( V_3 -> V_325 , 0 ) + V_326 ;
else
V_22 -> V_324 = F_116 ( V_3 -> V_325 , 0 ) + V_327 ;
V_36 = F_102 ( V_22 , V_3 ) ;
if ( V_36 )
goto exit;
V_22 -> V_19 . V_328 = ( void * ) V_3 -> V_325 ;
V_22 -> V_19 . V_273 = V_3 -> V_273 ;
V_36 = F_39 ( & V_22 -> V_19 ,
& V_22 -> V_98 , 8192 , 4096 ) ;
if ( V_36 )
goto exit;
V_22 -> V_95 = V_22 -> V_98 ;
V_22 -> V_329 = V_329 ;
F_42 ( & V_22 -> V_330 ) ;
F_42 ( & V_12 -> V_331 ) ;
V_36 = F_94 ( V_22 , V_3 ) ;
exit:
if ( V_36 ) {
F_23 ( V_22 -> V_26 ) ;
F_22 ( V_12 -> V_19 , & V_22 -> V_98 ) ;
V_22 -> V_26 = NULL ;
}
return V_36 ;
}
static int F_117 ( struct V_2 * V_3 , struct V_315 * V_160 )
{
struct V_21 * V_22 ;
struct V_11 * V_12 ;
enum V_35 V_36 ;
struct V_1 * V_4 ;
V_4 = F_5 ( V_3 -> V_7 ) ;
if ( V_4 )
return 0 ;
V_4 = F_95 ( sizeof( * V_4 ) , V_106 ) ;
if ( ! V_4 )
return - V_332 ;
V_22 = & V_4 -> V_316 ;
V_22 -> V_4 = V_4 ;
V_12 = & V_22 -> V_25 ;
F_118 ( V_22 ) ;
V_12 -> V_333 = ( void * ) V_22 ;
V_22 -> V_3 = & V_4 -> V_3 ;
V_22 -> V_160 = V_160 ;
F_119 ( & V_22 -> V_334 ) ;
F_6 ( V_4 ) ;
do {
V_36 = F_115 ( V_4 , V_3 , V_160 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_312 ;
if ( V_12 -> V_18 )
F_91 ( V_12 -> V_19 ) ;
V_36 = F_37 ( V_22 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_311 ;
V_36 = F_58 ( V_22 ) ;
if ( V_36 )
break;
V_36 = F_44 ( V_22 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_309 ;
V_36 = F_55 ( V_22 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_308 ;
V_36 = F_57 ( V_22 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_307 ;
V_36 = F_54 ( V_22 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_306 ;
V_36 = F_50 ( V_22 , V_3 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_305 ;
V_36 = F_120 ( V_22 ) ;
if ( V_36 )
break;
V_12 -> V_64 -> V_335 ( V_12 -> V_63 ) ;
V_36 = F_121 ( & V_22 -> V_25 , V_22 -> V_260 ) ;
if ( V_36 )
break;
V_22 -> V_336 = F_122 ( L_33 ) ;
F_97 () ;
V_22 -> V_197 = V_304 ;
V_36 = F_90 ( V_22 ) ;
if ( V_36 )
break;
V_22 -> V_197 = V_303 ;
if ( F_123 ( V_22 ) ) {
F_21 ( L_34 ) ;
break;
} ;
V_22 -> V_197 = V_300 ;
V_22 -> V_301 = 1 ;
F_105 ( V_22 ) ;
F_76 ( L_35 ) ;
return 0 ;
} while ( 0 );
F_21 ( L_36 , V_36 , V_22 -> V_197 ) ;
F_104 ( V_22 , false , false ) ;
return - V_337 ;
}
static void F_124 ( struct V_2 * V_3 ,
struct V_315 * V_160 ,
struct V_338 * V_277 )
{
struct V_1 * V_4 ;
struct V_21 * V_22 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
V_22 = & V_4 -> V_316 ;
if ( V_277 -> V_321 )
V_22 -> V_188 = V_277 -> V_321 - V_323 ;
}
static void F_125 ( struct V_2 * V_3 , struct V_315 * V_160 , bool V_47 )
{
struct V_21 * V_22 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
V_22 = & V_4 -> V_316 ;
F_126 ( V_22 -> V_336 ) ;
F_104 ( V_22 , V_47 , true ) ;
}
static void F_127 ( struct V_2 * V_3 , struct V_315 * V_160 , T_1 V_339 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
struct V_340 V_341 ;
struct V_342 V_343 ;
struct V_344 * V_345 ;
unsigned int V_60 ;
unsigned long V_5 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
V_12 = & V_4 -> V_316 . V_25 ;
for ( V_60 = 0 ; V_60 < V_346 ; V_60 ++ ) {
if ( ! V_12 -> V_347 [ V_60 ] || ( V_12 -> V_347 [ V_60 ] -> V_339 != V_339 ) )
continue;
V_345 = V_12 -> V_347 [ V_60 ] ;
F_2 ( & V_12 -> V_348 . V_349 , V_5 ) ;
V_12 -> V_347 [ V_60 ] = NULL ;
F_4 ( & V_12 -> V_348 . V_349 , V_5 ) ;
F_31 ( V_12 , & V_345 -> V_70 , false , false ) ;
memset ( & V_341 , 0 , sizeof( V_341 ) ) ;
V_341 . V_339 = V_339 ;
V_341 . V_350 = V_345 -> V_350 ;
V_341 . V_351 = true ;
F_128 ( V_12 , & V_341 ) ;
V_343 . V_92 = V_345 ;
V_343 . V_90 = sizeof( struct V_344 ) +
sizeof( struct V_258 ) * V_259 ;
F_129 ( V_12 -> V_19 , & V_343 ) ;
break;
}
}
static void F_130 ( struct V_2 * V_3 ,
struct V_315 * V_160 ,
T_1 V_352 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
if ( V_352 > V_346 )
V_4 -> V_316 . V_320 = V_346 ;
else
V_4 -> V_316 . V_320 = V_352 ;
}
static int F_131 ( struct V_2 * V_3 ,
struct V_315 * V_160 ,
T_1 V_339 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
unsigned int V_60 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
V_12 = & V_4 -> V_316 . V_25 ;
for ( V_60 = 0 ; V_60 < V_4 -> V_316 . V_320 ; V_60 ++ ) {
if ( ! V_12 -> V_347 [ V_60 ] || ( V_12 -> V_347 [ V_60 ] -> V_339 == V_339 ) )
return 1 ;
}
return 0 ;
}
static int F_132 ( struct V_2 * V_3 ,
struct V_315 * V_160 ,
T_1 V_339 ,
V_96 * V_353 ,
T_3 V_354 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
struct V_21 * V_22 ;
int V_355 = V_356 ;
if ( ! V_354 || ! V_353 )
return V_357 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return V_357 ;
V_12 = & V_4 -> V_316 . V_25 ;
V_22 = V_12 -> V_333 ;
if ( V_12 -> V_358 . V_359 ) {
V_355 = V_12 -> V_358 . V_359 ( V_12 , V_339 , V_353 , V_354 ) ;
if ( ! V_12 -> V_18 ) {
F_133 ( & V_22 -> V_360 ) ;
F_134 ( & V_22 -> V_330 ) ;
}
}
return V_355 ;
}
bool F_135 ( struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_5 V_361 ;
V_22 = V_12 -> V_333 ;
if ( ! F_136 ( & V_12 -> V_331 ) &&
( F_137 ( & V_22 -> V_360 ) == 0 ) )
return true ;
F_138 ( & V_361 ) ;
F_139 ( & V_12 -> V_331 , & V_361 ) ;
if ( ! F_140 ( V_12 -> V_331 ,
( F_137 ( & V_22 -> V_360 ) == 0 ) ,
V_362 ) )
V_12 -> V_363 = false ;
F_141 ( & V_12 -> V_331 , & V_361 ) ;
return V_12 -> V_363 ;
}
static enum V_35 V_281 ( struct V_11 * V_12 ,
T_1 V_339 ,
V_96 * V_353 ,
T_3 V_354 )
{
struct V_21 * V_22 ;
struct V_2 * V_3 ;
if ( ! V_12 || ! V_12 -> V_333 )
return V_165 ;
V_22 = V_12 -> V_333 ;
V_3 = V_22 -> V_3 ;
if ( V_3 && V_3 -> V_158 && V_3 -> V_158 -> V_364 )
return V_3 -> V_158 -> V_364 ( V_3 , & V_163 , V_339 , V_353 , V_354 ) ;
return V_165 ;
}
static int T_6 F_142 ( void )
{
int V_169 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_365 . V_366 = V_367 ;
V_163 . V_365 . V_368 = V_369 ;
V_163 . V_365 . V_370 = V_371 ;
V_163 . V_158 = & V_372 ;
memcpy ( V_163 . V_373 , V_374 , V_375 ) ;
V_163 . type = V_376 ;
F_40 ( & V_6 ) ;
V_169 = F_143 ( & V_163 ) ;
return V_169 ;
}
static void T_7 F_144 ( void )
{
F_145 ( & V_163 ) ;
}
