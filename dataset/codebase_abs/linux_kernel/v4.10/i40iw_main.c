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
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_35 * V_36 = & V_22 -> V_36 ;
if ( V_34 )
V_12 -> V_37 -> V_38 ( V_12 -> V_36 ) ;
F_21 ( V_12 -> V_19 , & V_36 -> V_39 ) ;
F_22 ( V_36 -> V_40 ) ;
V_22 -> V_36 . V_40 = NULL ;
F_22 ( V_36 -> V_41 ) ;
V_36 -> V_41 = NULL ;
}
static void F_23 ( struct V_11 * V_12 ,
struct V_42 * V_43 ,
void * V_44 )
{
if ( V_12 -> V_18 )
F_11 ( V_12 -> V_19 , F_12 ( V_43 -> V_27 - 1 ) , 0 ) ;
else
F_11 ( V_12 -> V_19 , F_13 ( V_43 -> V_27 - 1 ) , 0 ) ;
F_24 ( V_43 -> V_31 , NULL ) ;
F_25 ( V_43 -> V_31 , V_44 ) ;
}
static void F_26 ( struct V_21 * V_22 , bool V_45 )
{
enum V_46 V_47 = V_48 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_49 * V_50 = & V_22 -> V_50 ;
if ( ! V_22 -> V_23 )
F_23 ( V_12 , V_22 -> V_26 , ( void * ) V_22 ) ;
if ( V_45 )
goto exit;
if ( ! V_12 -> V_51 -> V_52 ( & V_50 -> V_53 , 0 , 1 ) )
V_47 = V_12 -> V_51 -> V_54 ( & V_50 -> V_53 ) ;
if ( V_47 )
F_27 ( L_1 , V_47 ) ;
exit:
F_21 ( V_12 -> V_19 , & V_50 -> V_55 ) ;
}
static void F_28 ( struct V_21 * V_22 ,
struct V_28 * V_29 ,
bool V_45 )
{
enum V_46 V_47 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
if ( V_45 )
goto exit;
V_47 = V_12 -> V_56 -> V_57 ( & V_29 -> V_58 , 0 , 1 ) ;
if ( V_47 ) {
F_27 ( L_2 , V_47 ) ;
goto exit;
}
V_47 = V_12 -> V_56 -> V_59 ( & V_29 -> V_58 ) ;
if ( V_47 )
F_27 ( L_3 , V_47 ) ;
exit:
F_21 ( V_12 -> V_19 , & V_29 -> V_55 ) ;
}
static void F_29 ( struct V_21 * V_22 , bool V_45 )
{
T_1 V_60 = 0 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_28 * V_29 = V_22 -> V_24 ;
struct V_42 * V_43 = V_22 -> V_26 ;
if ( V_22 -> V_23 ) {
F_23 ( V_12 , V_43 , ( void * ) V_22 ) ;
F_28 ( V_22 , V_29 , V_45 ) ;
V_29 ++ ;
V_60 ++ ;
}
for ( V_43 ++ ; V_60 < V_22 -> V_61 ; V_60 ++ , V_43 ++ , V_29 ++ ) {
F_23 ( V_12 , V_43 , ( void * ) V_29 ) ;
F_28 ( V_22 , V_29 , V_45 ) ;
}
}
static void F_30 ( struct V_21 * V_22 , bool V_45 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_62 * V_63 = & V_22 -> V_63 ;
enum V_46 V_47 = 0 ;
if ( ! V_45 )
V_47 = V_12 -> V_64 -> V_65 ( V_12 -> V_63 , 0 , true ) ;
if ( V_47 )
F_27 ( L_4 , V_47 ) ;
F_21 ( V_12 -> V_19 , & V_63 -> V_66 ) ;
}
static void F_31 ( struct V_11 * V_12 ,
enum V_67 V_68 ,
struct V_69 * V_70 ,
bool V_18 ,
bool V_45 )
{
struct V_71 V_72 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_70 = V_70 ;
V_72 . V_73 = V_68 ;
V_72 . V_74 = V_70 -> V_75 [ V_68 ] . V_76 ;
V_72 . V_18 = V_18 ;
if ( V_12 -> V_77 -> V_78 ( V_12 , & V_72 , V_45 ) )
F_27 ( L_5 , V_68 ) ;
}
static void F_32 ( struct V_11 * V_12 ,
struct V_69 * V_70 ,
bool V_18 ,
bool V_45 )
{
unsigned int V_60 ;
for ( V_60 = 0 ; V_60 < V_79 ; V_60 ++ )
F_31 ( V_12 , V_80 [ V_60 ] , V_70 , V_18 , V_45 ) ;
}
static T_2 F_33 ( int V_31 , void * V_20 )
{
struct V_28 * V_29 = (struct V_28 * ) V_20 ;
if ( V_29 -> V_31 != V_31 )
F_27 ( L_6 , V_29 -> V_31 , V_31 ) ;
F_19 ( & V_29 -> V_32 ) ;
return V_33 ;
}
static enum V_46 F_34 ( struct V_11 * V_12 ,
struct V_81 * V_72 )
{
return V_12 -> V_77 -> V_82 ( V_12 , V_72 ) ;
}
static enum V_46 F_35 ( struct V_21 * V_22 ,
bool V_18 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_81 V_72 ;
enum V_46 V_47 ;
int V_60 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_70 = V_12 -> V_70 ;
V_72 . V_18 = V_18 ;
V_72 . V_83 = V_22 -> V_84 ;
for ( V_60 = 0 ; V_60 < V_79 ; V_60 ++ ) {
V_72 . V_73 = V_80 [ V_60 ] ;
V_72 . V_74 = V_12 -> V_70 -> V_75 [ V_72 . V_73 ] . V_76 ;
V_47 = F_34 ( V_12 , & V_72 ) ;
if ( V_47 ) {
F_27 ( L_7 ,
V_80 [ V_60 ] , V_47 ) ;
break;
}
}
if ( ! V_47 )
return ( V_12 -> V_85 -> V_86 ( V_12 -> V_36 , 0 ,
V_12 -> V_87 ,
true , true ) ) ;
while ( V_60 ) {
V_60 -- ;
F_31 ( V_12 ,
V_80 [ V_60 ] ,
V_12 -> V_70 ,
V_18 ,
false ) ;
}
return V_47 ;
}
enum V_46 F_36 ( struct V_21 * V_22 ,
struct V_88 * V_89 ,
T_1 V_90 ,
T_1 V_91 )
{
unsigned long V_92 , V_93 ;
unsigned long V_94 ;
V_92 = ( unsigned long ) V_22 -> V_95 . V_92 ;
V_93 = V_92 ;
if ( V_91 )
V_93 = F_37 ( V_92 , ( V_91 + 1 ) ) ;
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
static enum V_46 F_38 ( struct V_21 * V_22 )
{
enum V_46 V_47 ;
T_1 V_100 = V_101 ;
struct V_88 V_55 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_102 V_103 ;
struct V_35 * V_36 = & V_22 -> V_36 ;
T_3 V_104 , V_105 ;
int V_60 ;
V_36 -> V_41 = F_39 ( V_100 , sizeof( * V_36 -> V_41 ) , V_106 ) ;
if ( ! V_36 -> V_41 )
return V_99 ;
V_36 -> V_40 = F_39 ( V_100 , sizeof( * V_36 -> V_40 ) , V_106 ) ;
if ( ! V_36 -> V_40 ) {
F_22 ( V_36 -> V_41 ) ;
return V_99 ;
}
V_12 -> V_36 = & V_36 -> V_107 ;
V_12 -> V_36 -> V_12 = V_12 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_47 = F_40 ( V_12 -> V_19 , & V_36 -> V_39 ,
( sizeof( struct V_108 ) * V_100 ) ,
V_109 ) ;
if ( V_47 )
goto exit;
V_47 = F_36 ( V_22 , & V_55 , sizeof( struct V_110 ) ,
V_111 ) ;
if ( V_47 )
goto exit;
V_12 -> V_36 -> V_112 = V_55 . V_97 ;
V_12 -> V_36 -> V_113 = V_55 . V_92 ;
V_103 . V_12 = V_12 ;
V_103 . V_114 = V_100 ;
V_103 . V_39 = V_36 -> V_39 . V_92 ;
V_103 . V_115 = V_36 -> V_39 . V_97 ;
V_103 . V_112 = V_55 . V_97 ;
V_103 . V_113 = V_55 . V_92 ;
V_103 . V_116 = V_22 -> V_117 ;
V_103 . V_118 = V_22 -> V_119 ;
V_103 . V_40 = V_36 -> V_40 ;
V_47 = V_12 -> V_37 -> V_120 ( V_12 -> V_36 , & V_103 ) ;
if ( V_47 ) {
F_27 ( L_8 , V_47 ) ;
goto exit;
}
V_47 = V_12 -> V_37 -> V_121 ( V_12 -> V_36 , & V_104 , & V_105 ) ;
if ( V_47 ) {
F_27 ( L_9 ,
V_47 , V_104 , V_105 ) ;
goto exit;
}
F_41 ( & V_36 -> V_122 ) ;
F_42 ( & V_36 -> V_123 ) ;
F_42 ( & V_36 -> V_124 ) ;
for ( V_60 = 0 ; V_60 < V_101 ; V_60 ++ ) {
F_43 ( & V_36 -> V_41 [ V_60 ] . V_125 ) ;
F_44 ( & V_36 -> V_41 [ V_60 ] . V_9 , & V_36 -> V_123 ) ;
}
return 0 ;
exit:
F_20 ( V_22 , false ) ;
return V_47 ;
}
static enum V_46 F_45 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_88 V_55 ;
enum V_46 V_47 ;
struct V_126 V_72 ;
struct V_62 * V_63 = & V_22 -> V_63 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_12 -> V_63 = & V_63 -> V_127 ;
V_12 -> V_63 -> V_12 = V_12 ;
V_72 . V_12 = V_12 ;
V_63 -> V_128 . V_90 = sizeof( struct V_129 ) ;
V_63 -> V_66 . V_90 = sizeof( struct V_130 ) * V_131 ;
V_47 = F_40 ( V_12 -> V_19 , & V_63 -> V_66 ,
V_63 -> V_66 . V_90 , V_132 ) ;
if ( V_47 )
goto exit;
V_47 = F_36 ( V_22 , & V_55 , V_63 -> V_128 . V_90 ,
V_133 ) ;
if ( V_47 )
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
V_47 = V_12 -> V_64 -> V_142 ( V_12 -> V_63 , & V_72 ) ;
if ( ! V_47 )
V_47 = V_12 -> V_64 -> V_143 ( V_12 -> V_63 , 0 , true , true ) ;
exit:
if ( V_47 )
F_21 ( V_12 -> V_19 , & V_63 -> V_66 ) ;
return V_47 ;
}
static enum V_46 F_46 ( struct V_21 * V_22 ,
struct V_28 * V_29 ,
T_1 V_144 ,
struct V_42 * V_43 )
{
enum V_46 V_47 ;
T_4 V_91 ;
if ( V_22 -> V_23 && ! V_144 ) {
F_47 ( & V_22 -> V_32 , F_14 , ( unsigned long ) V_22 ) ;
V_47 = F_48 ( V_43 -> V_31 , F_18 , 0 , L_10 , V_22 ) ;
} else {
F_47 ( & V_29 -> V_32 , F_17 , ( unsigned long ) V_29 ) ;
V_47 = F_48 ( V_43 -> V_31 , F_33 , 0 , L_11 , V_29 ) ;
}
F_49 ( & V_91 ) ;
F_50 ( V_43 -> V_145 , & V_91 ) ;
F_24 ( V_43 -> V_31 , & V_91 ) ;
if ( V_47 ) {
F_27 ( L_12 ) ;
return V_146 ;
}
V_43 -> V_144 = V_144 ;
return 0 ;
}
static enum V_46 F_51 ( struct V_21 * V_22 ,
struct V_28 * V_29 ,
T_1 V_144 )
{
enum V_46 V_47 ;
struct V_147 V_72 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
T_5 V_148 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . V_144 = V_144 ;
V_29 -> V_22 = V_22 ;
V_29 -> V_55 . V_90 = sizeof( struct V_149 ) *
V_22 -> V_25 . V_70 -> V_75 [ V_150 ] . V_76 ;
V_47 = F_40 ( V_12 -> V_19 , & V_29 -> V_55 , V_29 -> V_55 . V_90 ,
V_151 ) ;
if ( V_47 )
goto exit;
V_72 . V_144 = V_144 ;
V_72 . V_152 = V_29 -> V_55 . V_92 ;
V_72 . V_153 = V_29 -> V_55 . V_97 ;
V_72 . V_154 = V_22 -> V_25 . V_70 -> V_75 [ V_150 ] . V_76 ;
V_29 -> V_58 . V_144 = V_144 ;
V_72 . V_12 = V_12 ;
V_148 = ( V_155 ) & V_22 -> V_36 . V_107 ;
V_47 = V_12 -> V_56 -> V_156 ( & V_29 -> V_58 , & V_72 ) ;
if ( ! V_47 )
V_47 = V_12 -> V_56 -> V_157 ( & V_29 -> V_58 , V_148 ) ;
exit:
if ( V_47 )
F_21 ( V_12 -> V_19 , & V_29 -> V_55 ) ;
return V_47 ;
}
void F_52 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_3 ;
V_3 -> V_158 -> V_159 ( V_3 , V_22 -> V_160 , 1 ) ;
}
static enum V_46 F_53 ( struct V_21 * V_22 ,
struct V_2 * V_3 )
{
T_1 V_60 ;
T_1 V_144 ;
struct V_28 * V_29 ;
struct V_42 * V_43 ;
enum V_46 V_47 = 0 ;
T_1 V_161 ;
if ( V_3 && V_3 -> V_158 && V_3 -> V_158 -> V_162 ) {
V_47 = V_3 -> V_158 -> V_162 ( V_3 , & V_163 ,
V_22 -> V_164 ) ;
if ( V_47 )
goto exit;
} else {
V_47 = V_165 ;
goto exit;
}
V_161 = F_54 ( V_22 -> V_166 , V_22 -> V_25 . V_167 . V_168 ) ;
V_22 -> V_24 = F_39 ( V_161 , sizeof( * V_22 -> V_24 ) , V_106 ) ;
if ( ! V_22 -> V_24 ) {
V_47 = V_99 ;
goto exit;
}
V_60 = ( V_22 -> V_23 ) ? 0 : 1 ;
for ( V_144 = 0 ; V_60 < V_161 ; V_60 ++ , V_144 ++ ) {
V_29 = & V_22 -> V_24 [ V_144 ] ;
V_47 = F_51 ( V_22 , V_29 , V_144 ) ;
if ( V_47 ) {
F_27 ( L_13 , V_47 ) ;
break;
}
V_43 = & V_22 -> V_26 [ V_60 ] ;
V_29 -> V_31 = V_43 -> V_31 ;
V_29 -> V_30 = V_43 -> V_27 ;
V_47 = F_46 ( V_22 , V_29 , V_144 , V_43 ) ;
if ( V_47 ) {
F_28 ( V_22 , V_29 , false ) ;
break;
}
F_10 ( & V_22 -> V_25 , V_43 -> V_27 ) ;
V_22 -> V_61 ++ ;
}
exit:
if ( V_47 ) {
if ( ! V_22 -> V_61 ) {
F_22 ( V_22 -> V_24 ) ;
V_22 -> V_24 = NULL ;
} else {
V_47 = 0 ;
}
}
return V_47 ;
}
static enum V_46 F_55 ( struct V_21 * V_22 )
{
struct V_42 * V_43 = V_22 -> V_26 ;
T_1 V_169 = 0 ;
if ( ! V_22 -> V_23 ) {
F_47 ( & V_22 -> V_32 , F_14 , ( unsigned long ) V_22 ) ;
V_169 = F_48 ( V_43 -> V_31 , F_18 , 0 , L_14 , V_22 ) ;
}
if ( V_169 ) {
F_27 ( L_15 ) ;
return V_146 ;
}
return 0 ;
}
static enum V_46 F_56 ( struct V_21 * V_22 )
{
enum V_46 V_47 ;
struct V_170 V_72 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_49 * V_50 = & V_22 -> V_50 ;
T_5 V_148 = 0 ;
T_1 V_171 ;
V_171 = 2 * V_22 -> V_25 . V_70 -> V_75 [ V_172 ] . V_76 +
V_22 -> V_25 . V_70 -> V_75 [ V_150 ] . V_76 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_50 -> V_55 . V_90 = sizeof( struct V_173 ) * V_171 ;
V_47 = F_40 ( V_12 -> V_19 , & V_50 -> V_55 , V_50 -> V_55 . V_90 ,
V_174 ) ;
if ( V_47 )
goto exit;
V_72 . V_175 = V_50 -> V_55 . V_92 ;
V_72 . V_176 = V_50 -> V_55 . V_97 ;
V_72 . V_154 = V_171 ;
V_72 . V_12 = V_12 ;
V_47 = V_12 -> V_51 -> V_177 ( & V_50 -> V_53 , & V_72 ) ;
if ( V_47 )
goto exit;
V_47 = V_12 -> V_51 -> V_178 ( & V_50 -> V_53 , V_148 , 1 ) ;
if ( ! V_47 )
V_47 = V_12 -> V_51 -> V_179 ( & V_50 -> V_53 ) ;
exit:
if ( V_47 )
F_21 ( V_12 -> V_19 , & V_50 -> V_55 ) ;
return V_47 ;
}
static enum V_46 F_57 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
enum V_46 V_47 ;
V_47 = F_56 ( V_22 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_55 ( V_22 ) ;
if ( V_47 ) {
F_26 ( V_22 , false ) ;
return V_47 ;
}
if ( ! V_22 -> V_23 )
F_10 ( V_12 , V_22 -> V_26 [ 0 ] . V_27 ) ;
return 0 ;
}
static enum V_46 F_58 ( struct V_21 * V_22 )
{
struct V_180 V_72 ;
enum V_46 V_47 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . type = V_181 ;
V_72 . V_182 = 1 ;
V_72 . V_183 = 0 ;
V_72 . V_74 = 1 ;
V_72 . V_184 = 1 ;
V_72 . V_114 = 8192 ;
V_72 . V_185 = 8192 ;
V_72 . V_186 = 1024 ;
V_72 . V_187 = 16384 ;
V_72 . V_188 = V_189 ;
V_72 . V_190 = V_191 ;
V_47 = F_59 ( & V_22 -> V_192 , & V_72 ) ;
if ( V_47 )
F_27 ( L_16 ) ;
return V_47 ;
}
static enum V_46 F_60 ( struct V_21 * V_22 )
{
struct V_180 V_72 ;
enum V_46 V_47 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_72 . type = V_193 ;
V_72 . V_182 = 2 ;
V_72 . V_183 = V_22 -> V_25 . V_194 ;
V_72 . V_74 = 1 ;
V_72 . V_184 = 2 ;
V_72 . V_114 = 8192 ;
V_72 . V_185 = 8192 ;
V_72 . V_186 = 2048 ;
V_72 . V_187 = 16384 ;
V_47 = F_59 ( & V_22 -> V_192 , & V_72 ) ;
if ( V_47 )
F_27 ( L_17 ) ;
return V_47 ;
}
static enum V_46 F_61 ( struct V_21 * V_22 )
{
enum V_46 V_47 ;
V_22 -> V_84 = V_195 ;
V_47 = F_62 ( & V_22 -> V_25 , V_196 ) ;
if ( V_47 )
goto exit;
V_47 = F_35 ( V_22 , true ) ;
if ( V_47 )
goto exit;
V_22 -> V_197 = V_198 ;
exit:
return V_47 ;
}
static void F_63 ( struct V_21 * V_22 )
{
struct V_11 * V_12 = & V_22 -> V_25 ;
F_21 ( & V_22 -> V_19 , & V_22 -> V_98 ) ;
F_22 ( V_12 -> V_70 -> V_199 . V_200 ) ;
V_12 -> V_70 -> V_199 . V_200 = NULL ;
F_22 ( V_22 -> V_201 ) ;
V_22 -> V_201 = NULL ;
F_22 ( V_22 -> V_24 ) ;
V_22 -> V_24 = NULL ;
F_22 ( V_22 -> V_26 ) ;
V_22 -> V_26 = NULL ;
F_22 ( V_22 -> V_202 ) ;
V_22 -> V_202 = NULL ;
}
static void F_64 ( struct V_21 * V_22 , V_96 V_27 )
{
struct V_35 * V_203 = & V_22 -> V_36 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
enum V_46 V_47 = 0 ;
V_205 = F_65 ( V_203 , true ) ;
if ( ! V_205 ) {
F_27 ( L_18 ) ;
return;
}
V_207 = & V_205 -> V_72 ;
V_207 -> V_208 = V_209 ;
V_207 -> V_210 = 1 ;
V_207 -> V_211 . V_212 . V_213 . V_36 = & V_203 -> V_107 ;
V_207 -> V_211 . V_212 . V_213 . V_148 = ( V_155 ) V_205 ;
V_207 -> V_211 . V_212 . V_213 . V_214 = V_27 ;
V_207 -> V_211 . V_212 . V_213 . V_215 = 0 ;
V_47 = F_66 ( V_22 , V_205 ) ;
if ( V_47 )
F_27 ( L_19 ) ;
}
static enum V_46 F_67 ( struct V_21 * V_22 ,
V_96 * V_216 ,
V_96 V_27 )
{
struct V_217 * V_72 ;
struct V_35 * V_203 = & V_22 -> V_36 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
enum V_46 V_47 = 0 ;
V_205 = F_65 ( V_203 , true ) ;
if ( ! V_205 ) {
F_27 ( L_18 ) ;
return V_99 ;
}
V_207 = & V_205 -> V_72 ;
V_207 -> V_210 = 1 ;
V_72 = & V_207 -> V_211 . V_212 . V_218 . V_72 ;
F_68 ( V_72 -> V_216 , V_216 ) ;
V_72 -> V_214 = V_27 ;
V_207 -> V_211 . V_212 . V_218 . V_148 = ( V_155 ) V_205 ;
V_207 -> V_208 = V_219 ;
V_207 -> V_211 . V_212 . V_218 . V_36 = & V_203 -> V_107 ;
V_207 -> V_211 . V_212 . V_218 . V_148 = ( V_155 ) V_205 ;
V_47 = F_66 ( V_22 , V_205 ) ;
if ( V_47 )
F_27 ( L_20 ) ;
return V_47 ;
}
static enum V_46 F_69 ( struct V_21 * V_22 ,
T_3 * V_220 )
{
struct V_35 * V_203 = & V_22 -> V_36 ;
struct V_204 * V_205 ;
struct V_206 * V_207 ;
enum V_46 V_47 = 0 ;
V_205 = F_65 ( V_203 , true ) ;
if ( ! V_205 ) {
F_27 ( L_18 ) ;
return V_99 ;
}
F_70 ( & V_205 -> V_221 ) ;
V_207 = & V_205 -> V_72 ;
V_207 -> V_208 = V_222 ;
V_207 -> V_210 = 1 ;
V_207 -> V_211 . V_212 . V_223 . V_36 = & V_203 -> V_107 ;
V_207 -> V_211 . V_212 . V_223 . V_148 = ( V_155 ) V_205 ;
V_47 = F_66 ( V_22 , V_205 ) ;
if ( ! V_47 )
* V_220 = V_205 -> V_224 . V_225 ;
else
F_27 ( L_21 ) ;
F_71 ( V_203 , V_205 ) ;
return V_47 ;
}
static enum V_46 F_72 ( struct V_21 * V_22 ,
V_96 * V_226 )
{
enum V_46 V_47 ;
V_47 = F_69 ( V_22 , & V_22 -> V_227 ) ;
if ( ! V_47 ) {
V_47 = F_67 ( V_22 , V_226 ,
( V_96 ) V_22 -> V_227 ) ;
if ( V_47 )
F_64 ( V_22 , ( V_96 ) V_22 -> V_227 ) ;
}
return V_47 ;
}
static void F_73 ( struct V_21 * V_22 )
{
struct V_8 * V_228 ;
struct V_229 * V_230 ;
struct V_231 * V_232 , * V_233 ;
T_1 V_234 [ 4 ] ;
F_74 () ;
F_75 (&init_net, ip_dev) {
if ( ( ( ( F_76 ( V_228 ) < 0xFFFF ) &&
( F_77 ( V_228 ) == V_22 -> V_7 ) ) ||
( V_228 == V_22 -> V_7 ) ) && ( V_228 -> V_5 & V_235 ) ) {
V_230 = F_78 ( V_228 ) ;
if ( ! V_230 ) {
F_27 ( L_22 ) ;
break;
}
F_79 (ifp, tmp, &idev->addr_list, if_list) {
F_80 ( L_23 , & V_232 -> V_236 ,
F_76 ( V_228 ) , V_228 -> V_237 ) ;
F_81 ( V_234 ,
V_232 -> V_236 . V_238 . V_239 ) ;
F_82 ( V_22 ,
V_228 -> V_237 ,
V_234 ,
false ,
V_240 ) ;
}
}
}
F_83 () ;
}
static void F_84 ( struct V_21 * V_22 )
{
struct V_8 * V_12 ;
struct V_241 * V_230 ;
bool V_242 = true ;
T_1 V_243 ;
if ( ! F_85 () )
V_242 = false ;
F_86 (&init_net, dev) {
if ( ( ( ( F_76 ( V_12 ) < 0xFFFF ) &&
( F_77 ( V_12 ) == V_22 -> V_7 ) ) ||
( V_12 == V_22 -> V_7 ) ) && ( V_12 -> V_5 & V_235 ) ) {
V_230 = F_87 ( V_12 ) ;
F_88 (idev) {
F_89 ( & V_22 -> V_25 , V_244 ,
L_24 , & V_245 -> V_246 ,
F_76 ( V_12 ) , V_12 -> V_237 ) ;
V_243 = F_90 ( V_245 -> V_246 ) ;
F_82 ( V_22 ,
V_12 -> V_237 ,
& V_243 ,
true ,
V_240 ) ;
}
F_91 ( V_230 ) ;
F_92 ( V_230 ) ;
}
}
if ( V_242 )
F_93 () ;
}
static enum V_46 F_94 ( struct V_21 * V_22 )
{
struct V_8 * V_7 = V_22 -> V_7 ;
enum V_46 V_47 ;
V_47 = F_72 ( V_22 , ( V_96 * ) V_7 -> V_237 ) ;
if ( V_47 )
return V_47 ;
F_84 ( V_22 ) ;
F_73 ( V_22 ) ;
return 0 ;
}
static void F_95 ( struct V_247 * V_19 )
{
T_1 V_248 ;
T_1 V_249 ;
T_1 V_250 ;
T_1 V_251 ;
T_1 V_252 = 0 ;
do {
V_248 = F_96 ( V_19 , V_253 ) ;
F_80 ( L_25 , __LINE__ , V_248 ) ;
V_249 = F_96 ( V_19 , V_254 ) ;
F_80 ( L_26 , __LINE__ , V_249 ) ;
V_250 = F_96 ( V_19 , V_255 ) ;
F_80 ( L_27 ,
__LINE__ , V_250 ) ;
V_251 = F_96 ( V_19 , V_256 ) ;
F_80 ( L_28 ,
__LINE__ , V_251 ) ;
if ( ( V_249 == 0x80 ) && ( V_250 == 0x80 ) && ( V_251 == 0x80 ) )
break;
F_97 ( 1000 ) ;
V_252 ++ ;
} while ( V_252 < 14 );
F_11 ( V_19 , 0xb4040 , 0x4C104C5 ) ;
}
static enum V_46 F_98 ( struct V_21 * V_22 ,
struct V_2 * V_3 )
{
enum V_46 V_47 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
struct V_257 V_72 ;
struct V_258 V_259 ;
struct V_88 V_55 ;
struct V_260 V_261 ;
T_1 V_90 ;
struct V_262 V_263 ;
T_3 V_264 = V_265 ;
T_3 V_266 ;
T_1 V_60 ;
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_90 = sizeof( struct V_267 ) + sizeof( struct V_69 ) +
( sizeof( struct V_268 ) * V_269 ) ;
V_22 -> V_202 = F_99 ( V_90 , V_106 ) ;
if ( ! V_22 -> V_202 )
return V_99 ;
V_22 -> V_270 = (struct V_267 * ) V_22 -> V_202 ;
V_12 -> V_70 = & V_22 -> V_19 . V_271 ;
V_12 -> V_70 -> V_75 = (struct V_268 * ) ( V_22 -> V_270 + 1 ) ;
V_47 = F_36 ( V_22 , & V_55 , V_272 ,
V_273 ) ;
if ( V_47 )
goto exit;
V_72 . V_274 = V_55 . V_97 ;
V_72 . V_275 = V_55 . V_92 ;
V_47 = F_36 ( V_22 , & V_55 , V_276 ,
V_277 ) ;
if ( V_47 )
goto exit;
V_72 . V_278 = V_55 . V_97 ;
V_72 . V_279 = V_55 . V_92 ;
V_72 . V_87 = V_3 -> V_280 ;
V_72 . V_18 = ( V_3 -> V_281 ) ? false : true ;
V_72 . V_282 = V_3 -> V_283 ;
V_72 . V_19 = & V_22 -> V_19 ;
V_72 . V_284 = V_285 ;
V_261 . V_286 =
( V_3 -> V_287 . V_288 ) ? V_3 -> V_287 . V_288 - V_289 : V_290 ;
for ( V_60 = 0 ; V_60 < V_291 ; V_60 ++ ) {
V_266 = V_3 -> V_287 . V_292 . V_293 [ V_60 ] . V_294 ;
V_261 . V_295 [ V_60 ] = V_266 ;
if ( V_264 == V_265 )
V_264 = V_266 ;
else if ( ( V_266 != V_264 ) && ( V_266 != V_265 ) )
V_22 -> V_296 = true ;
}
F_80 ( L_29 , V_22 -> V_296 ) ;
V_72 . V_194 = 1 ;
V_72 . V_297 = V_298 ;
V_47 = F_100 ( & V_22 -> V_25 , & V_72 ) ;
exit:
if ( V_47 ) {
F_22 ( V_22 -> V_202 ) ;
V_22 -> V_202 = NULL ;
}
memset ( & V_259 , 0 , sizeof( V_259 ) ) ;
V_259 . V_12 = & V_22 -> V_25 ;
V_259 . V_299 = ( void * ) V_22 ;
V_259 . V_287 = & V_261 ;
F_101 ( & V_22 -> V_192 , & V_259 ) ;
if ( V_12 -> V_18 ) {
memset ( & V_263 , 0 , sizeof( V_263 ) ) ;
V_263 . V_300 = V_3 -> V_280 ;
V_263 . V_301 = F_99 ( sizeof( * V_263 . V_301 ) , V_106 ) ;
V_263 . V_302 = true ;
if ( V_263 . V_301 )
F_102 ( & V_22 -> V_192 , & V_263 ) ;
}
return V_47 ;
}
static void F_103 ( void )
{
if ( F_104 ( & V_303 ) == 1 ) {
F_105 ( & V_304 ) ;
F_106 ( & V_305 ) ;
F_107 ( & V_306 ) ;
}
}
static enum V_46 F_108 ( struct V_21 * V_22 ,
struct V_2 * V_3 )
{
struct V_307 * V_164 ;
struct V_308 * V_309 ;
T_1 V_310 ;
T_1 V_60 ;
T_1 V_90 ;
V_22 -> V_166 = V_3 -> V_166 ;
V_90 = sizeof( struct V_42 ) * V_22 -> V_166 ;
V_90 += sizeof( struct V_307 ) ;
V_90 += sizeof( struct V_308 ) * V_22 -> V_166 - 1 ;
V_22 -> V_26 = F_99 ( V_90 , V_106 ) ;
if ( ! V_22 -> V_26 )
return V_99 ;
V_22 -> V_164 = (struct V_307 * ) ( & V_22 -> V_26 [ V_22 -> V_166 ] ) ;
V_164 = V_22 -> V_164 ;
V_309 = V_164 -> V_311 ;
V_164 -> V_312 = V_22 -> V_166 ;
if ( V_22 -> V_166 <= F_109 () )
V_22 -> V_23 = true ;
for ( V_60 = 0 , V_310 = 0 ; V_60 < V_22 -> V_166 ; V_60 ++ , V_309 ++ ) {
V_22 -> V_26 [ V_60 ] . V_27 = V_3 -> V_313 [ V_60 ] . V_314 ;
V_22 -> V_26 [ V_60 ] . V_31 = V_3 -> V_313 [ V_60 ] . V_315 ;
V_22 -> V_26 [ V_60 ] . V_145 = V_310 ;
if ( V_60 == 0 ) {
V_309 -> V_316 = 0 ;
if ( V_22 -> V_23 )
V_309 -> V_310 = V_310 ++ ;
else
V_309 -> V_310 = V_317 ;
} else {
V_309 -> V_316 = V_317 ;
V_309 -> V_310 = V_310 ++ ;
}
V_309 -> V_318 = 3 ;
V_309 -> V_319 = V_22 -> V_26 [ V_60 ] . V_27 ;
}
return 0 ;
}
static void F_110 ( struct V_21 * V_22 , bool V_45 )
{
struct V_2 * V_3 = V_22 -> V_3 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
F_80 ( L_30 , V_22 -> V_197 ) ;
if ( V_22 -> V_320 )
F_111 ( V_22 -> V_320 ) ;
switch ( V_22 -> V_197 ) {
case V_321 :
V_22 -> V_322 = 0 ;
F_112 ( V_22 ) ;
F_113 ( V_22 -> V_323 ) ;
case V_324 :
if ( ! V_45 )
F_64 ( V_22 , ( V_96 ) V_22 -> V_227 ) ;
case V_325 :
if ( ! F_114 ( & V_303 ) ) {
F_115 ( & V_306 ) ;
F_116 ( & V_304 ) ;
F_117 ( & V_305 ) ;
}
case V_326 :
F_29 ( V_22 , V_45 ) ;
case V_327 :
F_26 ( V_22 , V_45 ) ;
case V_328 :
F_118 ( & V_22 -> V_192 , V_193 , V_45 ) ;
case V_329 :
F_118 ( & V_22 -> V_192 , V_181 , V_45 ) ;
case V_330 :
F_30 ( V_22 , V_45 ) ;
case V_331 :
F_119 ( V_12 , V_22 -> V_270 ) ;
case V_198 :
F_32 ( V_12 , V_12 -> V_70 , true , V_45 ) ;
case V_332 :
F_20 ( V_22 , true ) ;
case V_333 :
F_120 ( & V_22 -> V_334 ) ;
if ( V_22 -> V_192 . V_301 ) {
F_121 ( & V_22 -> V_192 ) ;
F_22 ( V_22 -> V_192 . V_301 ) ;
}
F_63 ( V_22 ) ;
break;
case V_335 :
default:
F_27 ( L_31 , V_22 -> V_197 ) ;
break;
}
F_8 ( F_1 ( V_3 ) ) ;
F_22 ( V_22 -> V_4 ) ;
}
static enum V_46 F_122 ( struct V_1 * V_4 ,
struct V_2 * V_3 ,
struct V_336 * V_160 )
{
struct V_21 * V_22 = & V_4 -> V_337 ;
struct V_11 * V_12 = & V_22 -> V_25 ;
enum V_46 V_47 ;
memcpy ( & V_4 -> V_3 , V_3 , sizeof( * V_3 ) ) ;
if ( V_117 == 1 )
V_117 = 2 ;
V_22 -> V_338 = V_338 ;
V_22 -> V_117 = ( V_117 < V_339 ) ?
( V_96 ) V_117 + V_340 :
V_340 ;
V_22 -> V_119 =
( V_22 -> V_117 != V_340 ) ? V_119 : 0 ;
V_22 -> V_341 = V_22 -> V_119 ;
V_22 -> V_7 = V_3 -> V_7 ;
V_4 -> V_160 = V_160 ;
if ( ! V_3 -> V_281 )
V_22 -> V_342 = F_123 ( V_3 -> V_343 , 0 ) + V_344 ;
else
V_22 -> V_342 = F_123 ( V_3 -> V_343 , 0 ) + V_345 ;
V_47 = F_108 ( V_22 , V_3 ) ;
if ( V_47 )
goto exit;
V_22 -> V_19 . V_346 = ( void * ) V_3 -> V_343 ;
V_22 -> V_19 . V_283 = V_3 -> V_283 ;
V_47 = F_40 ( & V_22 -> V_19 ,
& V_22 -> V_98 , 8192 , 4096 ) ;
if ( V_47 )
goto exit;
V_22 -> V_95 = V_22 -> V_98 ;
V_22 -> V_347 = V_347 ;
F_43 ( & V_22 -> V_348 ) ;
F_43 ( & V_12 -> V_349 ) ;
F_43 ( & V_22 -> V_350 ) ;
V_47 = F_98 ( V_22 , V_3 ) ;
exit:
if ( V_47 ) {
F_22 ( V_22 -> V_26 ) ;
F_21 ( V_12 -> V_19 , & V_22 -> V_98 ) ;
V_22 -> V_26 = NULL ;
}
return V_47 ;
}
static void F_124 ( struct V_21 * V_22 )
{
V_22 -> V_351 = F_125 ( V_22 -> V_352 , V_22 -> V_353 , 0 ) ;
V_22 -> V_354 = F_125 ( V_22 -> V_355 , V_22 -> V_356 , 0 ) ;
V_22 -> V_357 = F_125 ( V_22 -> V_358 , V_22 -> V_359 , 0 ) ;
V_22 -> V_360 = F_125 ( V_22 -> V_361 , V_22 -> V_362 , 0 ) ;
}
static int F_126 ( struct V_2 * V_3 , struct V_336 * V_160 )
{
struct V_21 * V_22 ;
struct V_11 * V_12 ;
enum V_46 V_47 ;
struct V_1 * V_4 ;
V_4 = F_5 ( V_3 -> V_7 ) ;
if ( V_4 )
return 0 ;
V_4 = F_99 ( sizeof( * V_4 ) , V_106 ) ;
if ( ! V_4 )
return - V_363 ;
V_22 = & V_4 -> V_337 ;
V_22 -> V_4 = V_4 ;
V_12 = & V_22 -> V_25 ;
F_127 ( V_22 ) ;
V_12 -> V_364 = ( void * ) V_22 ;
V_22 -> V_3 = & V_4 -> V_3 ;
V_22 -> V_160 = V_160 ;
F_128 ( & V_22 -> V_365 ) ;
F_6 ( V_4 ) ;
do {
V_47 = F_122 ( V_4 , V_3 , V_160 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_333 ;
if ( V_12 -> V_18 )
F_95 ( V_12 -> V_19 ) ;
V_47 = F_38 ( V_22 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_332 ;
V_47 = F_61 ( V_22 ) ;
if ( V_47 )
break;
V_47 = F_45 ( V_22 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_330 ;
V_47 = F_58 ( V_22 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_329 ;
V_47 = F_60 ( V_22 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_328 ;
V_47 = F_57 ( V_22 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_327 ;
V_47 = F_53 ( V_22 , V_3 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_326 ;
V_47 = F_129 ( V_22 ) ;
if ( V_47 )
break;
F_124 ( V_22 ) ;
V_12 -> V_64 -> V_366 ( V_12 -> V_63 ) ;
V_47 = F_130 ( & V_22 -> V_25 , V_22 -> V_270 ) ;
if ( V_47 )
break;
V_22 -> V_367 = F_131 ( L_32 , V_368 ) ;
F_103 () ;
V_22 -> V_197 = V_325 ;
V_47 = F_94 ( V_22 ) ;
if ( V_47 )
break;
V_22 -> V_197 = V_324 ;
if ( F_132 ( V_22 ) ) {
F_27 ( L_33 ) ;
break;
} ;
V_22 -> V_197 = V_321 ;
V_22 -> V_322 = 1 ;
F_112 ( V_22 ) ;
V_22 -> V_320 = F_131 ( L_34 , V_368 ) ;
if( V_22 -> V_320 == NULL )
break;
F_80 ( L_35 ) ;
return 0 ;
} while ( 0 );
F_27 ( L_36 , V_47 , V_22 -> V_197 ) ;
F_110 ( V_22 , false ) ;
return - V_369 ;
}
static void F_133 ( struct V_370 * V_371 )
{
struct V_372 * V_373 =
F_134 ( V_371 , struct V_372 , V_371 ) ;
struct V_21 * V_22 = V_373 -> V_22 ;
F_135 ( & V_22 -> V_192 , & V_373 -> V_261 ) ;
F_136 ( & V_22 -> V_374 ) ;
F_22 ( V_371 ) ;
}
static void F_137 ( struct V_2 * V_3 , struct V_336 * V_160 ,
struct V_375 * V_287 )
{
struct V_1 * V_4 ;
struct V_260 * V_261 ;
struct V_372 * V_371 ;
struct V_21 * V_22 ;
int V_60 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
V_22 = & V_4 -> V_337 ;
if ( F_138 ( & V_22 -> V_374 ) )
return;
V_371 = F_99 ( sizeof( * V_371 ) , V_376 ) ;
if ( ! V_371 )
return;
F_70 ( & V_22 -> V_374 ) ;
V_371 -> V_22 = V_22 ;
V_261 = & V_371 -> V_261 ;
for ( V_60 = 0 ; V_60 < V_291 ; V_60 ++ )
V_261 -> V_295 [ V_60 ] = V_287 -> V_292 . V_293 [ V_60 ] . V_294 ;
V_261 -> V_286 = ( V_287 -> V_288 ) ? V_287 -> V_288 - V_289 : V_22 -> V_192 . V_286 ;
F_139 ( & V_371 -> V_371 , F_133 ) ;
F_140 ( V_22 -> V_320 , & V_371 -> V_371 ) ;
}
static void F_141 ( struct V_2 * V_3 , struct V_336 * V_160 , bool V_45 )
{
struct V_21 * V_22 ;
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
V_22 = & V_4 -> V_337 ;
V_22 -> V_377 = true ;
F_142 ( V_22 ) ;
F_111 ( V_22 -> V_367 ) ;
F_110 ( V_22 , V_45 ) ;
}
static void F_143 ( struct V_2 * V_3 , struct V_336 * V_160 , T_1 V_378 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
struct V_379 V_380 ;
struct V_381 V_382 ;
struct V_383 * V_384 ;
unsigned int V_60 ;
unsigned long V_5 ;
struct V_21 * V_22 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
V_12 = & V_4 -> V_337 . V_25 ;
V_22 = (struct V_21 * ) V_12 -> V_364 ;
for ( V_60 = 0 ; V_60 < V_385 ; V_60 ++ ) {
if ( ! V_12 -> V_386 [ V_60 ] || ( V_12 -> V_386 [ V_60 ] -> V_378 != V_378 ) )
continue;
V_384 = V_12 -> V_386 [ V_60 ] ;
F_2 ( & V_22 -> V_192 . V_301 -> V_387 , V_5 ) ;
V_12 -> V_386 [ V_60 ] = NULL ;
F_4 ( & V_22 -> V_192 . V_301 -> V_387 , V_5 ) ;
F_32 ( V_12 , & V_384 -> V_70 , false , false ) ;
memset ( & V_380 , 0 , sizeof( V_380 ) ) ;
V_380 . V_378 = V_378 ;
V_380 . V_388 = V_384 -> V_388 ;
V_380 . V_389 = true ;
F_144 ( V_12 , & V_380 ) ;
V_382 . V_92 = V_384 ;
V_382 . V_90 = sizeof( struct V_383 ) +
sizeof( struct V_268 ) * V_269 ;
F_145 ( V_12 -> V_19 , & V_382 ) ;
break;
}
}
static void F_146 ( struct V_2 * V_3 ,
struct V_336 * V_160 ,
T_1 V_390 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return;
if ( V_390 > V_385 )
V_4 -> V_337 . V_341 = V_385 ;
else
V_4 -> V_337 . V_341 = V_390 ;
}
static int F_147 ( struct V_2 * V_3 ,
struct V_336 * V_160 ,
T_1 V_378 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
unsigned int V_60 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return 0 ;
V_12 = & V_4 -> V_337 . V_25 ;
for ( V_60 = 0 ; V_60 < V_4 -> V_337 . V_341 ; V_60 ++ ) {
if ( ! V_12 -> V_386 [ V_60 ] || ( V_12 -> V_386 [ V_60 ] -> V_378 == V_378 ) )
return 1 ;
}
return 0 ;
}
static int F_148 ( struct V_2 * V_3 ,
struct V_336 * V_160 ,
T_1 V_378 ,
V_96 * V_391 ,
T_3 V_392 )
{
struct V_1 * V_4 ;
struct V_11 * V_12 ;
struct V_21 * V_22 ;
int V_393 = V_394 ;
if ( ! V_392 || ! V_391 )
return V_395 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return V_395 ;
V_12 = & V_4 -> V_337 . V_25 ;
V_22 = V_12 -> V_364 ;
if ( V_12 -> V_396 . V_397 ) {
V_393 = V_12 -> V_396 . V_397 ( V_12 , V_378 , V_391 , V_392 ) ;
if ( ! V_12 -> V_18 ) {
F_136 ( & V_22 -> V_398 ) ;
F_149 ( & V_22 -> V_348 ) ;
}
}
return V_393 ;
}
bool F_150 ( struct V_11 * V_12 )
{
struct V_21 * V_22 ;
T_6 V_399 ;
V_22 = V_12 -> V_364 ;
if ( ! F_151 ( & V_12 -> V_349 ) &&
( F_138 ( & V_22 -> V_398 ) == 0 ) )
return true ;
F_152 ( & V_399 ) ;
F_153 ( & V_12 -> V_349 , & V_399 ) ;
if ( ! F_154 ( V_12 -> V_349 ,
( F_138 ( & V_22 -> V_398 ) == 0 ) ,
V_400 ) )
V_12 -> V_401 = false ;
F_155 ( & V_12 -> V_349 , & V_399 ) ;
return V_12 -> V_401 ;
}
static enum V_46 V_298 ( struct V_11 * V_12 ,
T_1 V_378 ,
V_96 * V_391 ,
T_3 V_392 )
{
struct V_21 * V_22 ;
struct V_2 * V_3 ;
if ( ! V_12 || ! V_12 -> V_364 )
return V_165 ;
V_22 = V_12 -> V_364 ;
V_3 = V_22 -> V_3 ;
if ( V_3 && V_3 -> V_158 && V_3 -> V_158 -> V_402 )
return V_3 -> V_158 -> V_402 ( V_3 , & V_163 , V_378 , V_391 , V_392 ) ;
return V_165 ;
}
static int T_7 F_156 ( void )
{
int V_169 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_403 . V_404 = V_405 ;
V_163 . V_403 . V_406 = V_407 ;
V_163 . V_403 . V_408 = V_409 ;
V_163 . V_158 = & V_410 ;
memcpy ( V_163 . V_411 , V_412 , V_413 ) ;
V_163 . type = V_414 ;
F_41 ( & V_6 ) ;
V_169 = F_157 ( & V_163 ) ;
return V_169 ;
}
static void T_8 F_158 ( void )
{
F_159 ( & V_163 ) ;
}
