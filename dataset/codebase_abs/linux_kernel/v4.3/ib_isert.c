static inline bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ( V_2 -> V_5 &&
V_4 -> V_6 != V_7 ) ;
}
static void
F_2 ( struct V_8 * V_9 , void * V_10 )
{
struct V_1 * V_1 = V_10 ;
F_3 ( L_1 ,
F_4 ( V_9 -> V_11 ) , V_9 -> V_11 , V_1 ) ;
switch ( V_9 -> V_11 ) {
case V_12 :
F_5 ( V_1 -> V_13 , V_12 ) ;
break;
case V_14 :
F_6 ( L_2 ) ;
break;
default:
break;
}
}
static int
F_7 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_19 ;
V_19 = F_8 ( V_16 , V_18 ) ;
if ( V_19 ) {
F_3 ( L_3 , V_19 ) ;
return V_19 ;
}
F_9 ( L_4 , V_18 -> V_20 ) ;
F_9 ( L_5 , V_18 -> V_21 ) ;
return 0 ;
}
static struct V_22 *
F_10 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_22 * V_25 ;
int V_26 , V_27 = 0 ;
F_11 ( & V_28 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ )
if ( V_24 -> V_30 [ V_26 ] . V_31 <
V_24 -> V_30 [ V_27 ] . V_31 )
V_27 = V_26 ;
V_25 = & V_24 -> V_30 [ V_27 ] ;
V_25 -> V_31 ++ ;
F_12 ( & V_28 ) ;
F_13 ( L_6 ,
V_1 , V_25 , V_27 ) ;
return V_25 ;
}
static void
F_14 ( struct V_22 * V_25 )
{
F_11 ( & V_28 ) ;
V_25 -> V_31 -- ;
F_12 ( & V_28 ) ;
}
static struct V_32 *
F_15 ( struct V_1 * V_1 ,
struct V_22 * V_25 ,
struct V_33 * V_34 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_35 V_36 ;
int V_19 ;
memset ( & V_36 , 0 , sizeof( struct V_35 ) ) ;
V_36 . V_37 = F_2 ;
V_36 . V_38 = V_1 ;
V_36 . V_39 = V_25 -> V_40 ;
V_36 . V_41 = V_25 -> V_40 ;
V_36 . V_42 . V_43 = V_44 ;
V_36 . V_42 . V_45 = V_46 + 1 ;
V_36 . V_42 . V_47 = F_16 ( 2 , V_24 -> V_48 . V_20 - 2 ) ;
V_1 -> V_20 = V_36 . V_42 . V_47 ;
V_36 . V_42 . V_49 = 1 ;
V_36 . V_50 = V_51 ;
V_36 . V_52 = V_53 ;
if ( V_24 -> V_54 )
V_36 . V_55 |= V_56 ;
V_19 = F_17 ( V_34 , V_24 -> V_57 , & V_36 ) ;
if ( V_19 ) {
F_3 ( L_7 , V_19 ) ;
return F_18 ( V_19 ) ;
}
return V_34 -> V_58 ;
}
static int
F_19 ( struct V_1 * V_1 , struct V_33 * V_34 )
{
struct V_22 * V_25 ;
int V_19 ;
V_25 = F_10 ( V_1 ) ;
V_1 -> V_58 = F_15 ( V_1 , V_25 , V_34 ) ;
if ( F_20 ( V_1 -> V_58 ) ) {
V_19 = F_21 ( V_1 -> V_58 ) ;
goto V_59;
}
return 0 ;
V_59:
F_14 ( V_25 ) ;
return V_19 ;
}
static void
F_22 ( struct V_8 * V_9 , void * V_10 )
{
F_9 ( L_8 , V_9 -> V_11 ) ;
}
static int
F_23 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
T_1 V_64 ;
int V_26 , V_65 ;
V_1 -> V_66 = F_24 ( V_46 *
sizeof( struct V_60 ) , V_67 ) ;
if ( ! V_1 -> V_66 )
goto V_68;
V_61 = V_1 -> V_66 ;
for ( V_26 = 0 ; V_26 < V_46 ; V_26 ++ , V_61 ++ ) {
V_64 = F_25 ( V_16 , ( void * ) V_61 ,
V_69 , V_70 ) ;
if ( F_26 ( V_16 , V_64 ) )
goto V_71;
V_61 -> V_64 = V_64 ;
V_63 = & V_61 -> V_63 ;
V_63 -> V_72 = V_61 -> V_64 ;
V_63 -> V_73 = V_69 ;
V_63 -> V_74 = V_24 -> V_57 -> V_75 ;
}
return 0 ;
V_71:
V_61 = V_1 -> V_66 ;
for ( V_65 = 0 ; V_65 < V_26 ; V_65 ++ , V_61 ++ ) {
F_27 ( V_16 , V_61 -> V_64 ,
V_69 , V_70 ) ;
}
F_28 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
V_68:
F_3 ( L_9 , V_1 ) ;
return - V_76 ;
}
static void
F_29 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_24 -> V_15 ;
struct V_60 * V_61 ;
int V_26 ;
if ( ! V_1 -> V_66 )
return;
V_61 = V_1 -> V_66 ;
for ( V_26 = 0 ; V_26 < V_46 ; V_26 ++ , V_61 ++ ) {
F_27 ( V_16 , V_61 -> V_64 ,
V_69 , V_70 ) ;
}
F_28 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
}
static void
F_30 ( struct V_23 * V_24 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ ) {
struct V_22 * V_25 = & V_24 -> V_30 [ V_26 ] ;
if ( V_25 -> V_40 ) {
F_31 ( & V_25 -> V_77 ) ;
F_32 ( V_25 -> V_40 ) ;
}
}
F_28 ( V_24 -> V_30 ) ;
}
static int
F_33 ( struct V_23 * V_24 ,
struct V_17 * V_36 )
{
int V_26 , V_78 , V_19 = 0 ;
V_24 -> V_29 = V_27 ( V_79 , F_34 ( int , F_35 () ,
V_24 -> V_15 -> V_80 ) ) ;
F_13 ( L_10
L_11 ,
V_24 -> V_29 , V_24 -> V_15 -> V_81 ,
V_24 -> V_15 -> V_80 , V_24 -> V_82 ,
V_24 -> V_54 ) ;
V_24 -> V_30 = F_36 ( V_24 -> V_29 , sizeof( struct V_22 ) ,
V_67 ) ;
if ( ! V_24 -> V_30 ) {
F_3 ( L_12 ) ;
return - V_76 ;
}
V_78 = V_27 ( V_83 , V_36 -> V_78 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ ) {
struct V_84 V_85 = {} ;
struct V_22 * V_25 = & V_24 -> V_30 [ V_26 ] ;
V_25 -> V_24 = V_24 ;
F_37 ( & V_25 -> V_77 , V_86 ) ;
V_85 . V_87 = V_78 ;
V_85 . V_88 = V_26 ;
V_25 -> V_40 = F_38 ( V_24 -> V_15 ,
V_89 ,
F_22 ,
( void * ) V_25 ,
& V_85 ) ;
if ( F_20 ( V_25 -> V_40 ) ) {
F_3 ( L_13 ) ;
V_19 = F_21 ( V_25 -> V_40 ) ;
V_25 -> V_40 = NULL ;
goto V_90;
}
V_19 = F_39 ( V_25 -> V_40 , V_91 ) ;
if ( V_19 )
goto V_90;
}
return 0 ;
V_90:
F_30 ( V_24 ) ;
return V_19 ;
}
static int
F_40 ( struct V_23 * V_24 )
{
struct V_17 * V_48 ;
int V_19 ;
V_48 = & V_24 -> V_48 ;
V_19 = F_7 ( V_24 -> V_15 , V_48 ) ;
if ( V_19 )
return V_19 ;
if ( V_48 -> V_92 & V_93 &&
V_48 -> V_92 & V_94 ) {
V_24 -> V_82 = 1 ;
V_24 -> V_95 = V_96 ;
V_24 -> V_97 = V_98 ;
} else {
V_24 -> V_82 = 0 ;
V_24 -> V_95 = V_99 ;
V_24 -> V_97 = V_100 ;
}
V_19 = F_33 ( V_24 , V_48 ) ;
if ( V_19 )
return V_19 ;
V_24 -> V_57 = F_41 ( V_24 -> V_15 ) ;
if ( F_20 ( V_24 -> V_57 ) ) {
V_19 = F_21 ( V_24 -> V_57 ) ;
F_3 ( L_14 ,
V_24 , V_19 ) ;
goto V_90;
}
V_24 -> V_54 = V_48 -> V_92 &
V_94 ? true : false ;
return 0 ;
V_90:
F_30 ( V_24 ) ;
return V_19 ;
}
static void
F_42 ( struct V_23 * V_24 )
{
F_13 ( L_15 , V_24 ) ;
F_43 ( V_24 -> V_57 ) ;
F_30 ( V_24 ) ;
}
static void
F_44 ( struct V_23 * V_24 )
{
F_11 ( & V_28 ) ;
V_24 -> V_101 -- ;
F_13 ( L_16 , V_24 , V_24 -> V_101 ) ;
if ( ! V_24 -> V_101 ) {
F_42 ( V_24 ) ;
F_45 ( & V_24 -> V_102 ) ;
F_28 ( V_24 ) ;
}
F_12 ( & V_28 ) ;
}
static struct V_23 *
F_46 ( struct V_33 * V_34 )
{
struct V_23 * V_24 ;
int V_19 ;
F_11 ( & V_28 ) ;
F_47 (device, &device_list, dev_node) {
if ( V_24 -> V_15 -> V_103 == V_34 -> V_24 -> V_103 ) {
V_24 -> V_101 ++ ;
F_13 ( L_17 ,
V_24 , V_24 -> V_101 ) ;
F_12 ( & V_28 ) ;
return V_24 ;
}
}
V_24 = F_24 ( sizeof( struct V_23 ) , V_67 ) ;
if ( ! V_24 ) {
F_12 ( & V_28 ) ;
return F_18 ( - V_76 ) ;
}
F_48 ( & V_24 -> V_102 ) ;
V_24 -> V_15 = V_34 -> V_24 ;
V_19 = F_40 ( V_24 ) ;
if ( V_19 ) {
F_28 ( V_24 ) ;
F_12 ( & V_28 ) ;
return F_18 ( V_19 ) ;
}
V_24 -> V_101 ++ ;
F_49 ( & V_24 -> V_102 , & V_104 ) ;
F_13 ( L_18 ,
V_24 , V_24 -> V_101 ) ;
F_12 ( & V_28 ) ;
return V_24 ;
}
static void
F_50 ( struct V_1 * V_1 )
{
struct V_105 * V_106 , * V_107 ;
int V_26 = 0 ;
if ( F_51 ( & V_1 -> V_108 ) )
return;
F_13 ( L_19 , V_1 ) ;
F_52 (fr_desc, tmp,
&isert_conn->fr_pool, list) {
F_45 ( & V_106 -> V_109 ) ;
F_53 ( V_106 -> V_110 ) ;
F_54 ( V_106 -> V_111 ) ;
if ( V_106 -> V_112 ) {
F_53 ( V_106 -> V_112 -> V_113 ) ;
F_54 ( V_106 -> V_112 -> V_114 ) ;
F_54 ( V_106 -> V_112 -> V_115 ) ;
F_28 ( V_106 -> V_112 ) ;
}
F_28 ( V_106 ) ;
++ V_26 ;
}
if ( V_26 < V_1 -> V_116 )
F_6 ( L_20 ,
V_1 -> V_116 - V_26 ) ;
}
static int
F_55 ( struct V_105 * V_117 ,
struct V_15 * V_24 ,
struct V_118 * V_57 )
{
struct V_119 * V_112 ;
int V_19 ;
V_112 = F_24 ( sizeof( * V_117 -> V_112 ) , V_67 ) ;
if ( ! V_112 ) {
F_3 ( L_21 ) ;
return - V_76 ;
}
V_112 -> V_113 = F_56 ( V_24 ,
V_120 ) ;
if ( F_20 ( V_112 -> V_113 ) ) {
F_3 ( L_22 ,
F_21 ( V_112 -> V_113 ) ) ;
V_19 = F_21 ( V_112 -> V_113 ) ;
goto V_121;
}
V_112 -> V_114 = F_57 ( V_57 , V_122 ,
V_120 ) ;
if ( F_20 ( V_112 -> V_114 ) ) {
F_3 ( L_23 ,
F_21 ( V_112 -> V_114 ) ) ;
V_19 = F_21 ( V_112 -> V_114 ) ;
goto V_123;
}
V_117 -> V_124 |= V_125 ;
V_112 -> V_115 = F_57 ( V_57 , V_126 , 2 ) ;
if ( F_20 ( V_112 -> V_115 ) ) {
F_3 ( L_24 ,
F_21 ( V_112 -> V_115 ) ) ;
V_19 = F_21 ( V_112 -> V_115 ) ;
goto V_127;
}
V_117 -> V_112 = V_112 ;
V_117 -> V_124 |= V_128 ;
V_117 -> V_124 &= ~ V_129 ;
return 0 ;
V_127:
F_54 ( V_112 -> V_114 ) ;
V_123:
F_53 ( V_112 -> V_113 ) ;
V_121:
F_28 ( V_112 ) ;
return V_19 ;
}
static int
F_58 ( struct V_15 * V_15 , struct V_118 * V_57 ,
struct V_105 * V_106 )
{
int V_19 ;
V_106 -> V_110 = F_56 ( V_15 ,
V_120 ) ;
if ( F_20 ( V_106 -> V_110 ) ) {
F_3 ( L_25 ,
F_21 ( V_106 -> V_110 ) ) ;
return F_21 ( V_106 -> V_110 ) ;
}
V_106 -> V_111 = F_57 ( V_57 , V_122 ,
V_120 ) ;
if ( F_20 ( V_106 -> V_111 ) ) {
F_3 ( L_26 ,
F_21 ( V_106 -> V_111 ) ) ;
V_19 = F_21 ( V_106 -> V_111 ) ;
goto V_130;
}
V_106 -> V_124 |= V_131 ;
F_9 ( L_27 , V_106 ) ;
return 0 ;
V_130:
F_53 ( V_106 -> V_110 ) ;
return V_19 ;
}
static int
F_59 ( struct V_1 * V_1 )
{
struct V_105 * V_106 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_132 * V_133 = V_1 -> V_2 -> V_134 -> V_133 ;
struct V_135 * V_136 = V_133 -> V_135 ;
int V_26 , V_19 , V_137 ;
V_137 = F_60 ( V_138 , V_139 , V_136 -> V_140 ) ;
V_137 = ( V_137 * 2 ) + V_141 ;
V_1 -> V_116 = 0 ;
for ( V_26 = 0 ; V_26 < V_137 ; V_26 ++ ) {
V_106 = F_24 ( sizeof( * V_106 ) , V_67 ) ;
if ( ! V_106 ) {
F_3 ( L_28 ) ;
V_19 = - V_76 ;
goto V_59;
}
V_19 = F_58 ( V_24 -> V_15 ,
V_24 -> V_57 , V_106 ) ;
if ( V_19 ) {
F_3 ( L_29 ,
V_19 ) ;
F_28 ( V_106 ) ;
goto V_59;
}
F_49 ( & V_106 -> V_109 , & V_1 -> V_108 ) ;
V_1 -> V_116 ++ ;
}
F_9 ( L_30 ,
V_1 , V_1 -> V_116 ) ;
return 0 ;
V_59:
F_50 ( V_1 ) ;
return V_19 ;
}
static void
F_61 ( struct V_1 * V_1 )
{
V_1 -> V_142 = V_143 ;
F_48 ( & V_1 -> V_144 ) ;
F_62 ( & V_1 -> V_145 ) ;
F_62 ( & V_1 -> V_146 ) ;
F_62 ( & V_1 -> V_147 ) ;
F_63 ( & V_1 -> V_148 ) ;
F_64 ( & V_1 -> V_149 ) ;
F_65 ( & V_1 -> V_150 ) ;
F_48 ( & V_1 -> V_108 ) ;
F_37 ( & V_1 -> V_151 , V_152 ) ;
}
static void
F_66 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_24 -> V_15 ;
F_27 ( V_16 , V_1 -> V_153 ,
V_154 , V_155 ) ;
F_27 ( V_16 , V_1 -> V_156 ,
V_157 ,
V_70 ) ;
F_28 ( V_1 -> V_158 ) ;
}
static int
F_67 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
int V_19 ;
V_1 -> V_158 = F_24 ( V_157 +
V_154 , V_67 ) ;
if ( ! V_1 -> V_158 ) {
F_3 ( L_31 ) ;
return - V_76 ;
}
V_1 -> V_159 = V_1 -> V_158 ;
V_1 -> V_160 = V_1 -> V_158 +
V_157 ;
F_9 ( L_32 ,
V_1 -> V_158 , V_1 -> V_159 ,
V_1 -> V_160 ) ;
V_1 -> V_156 = F_25 ( V_16 ,
( void * ) V_1 -> V_159 ,
V_157 , V_70 ) ;
V_19 = F_26 ( V_16 , V_1 -> V_156 ) ;
if ( V_19 ) {
F_3 ( L_33 , V_19 ) ;
V_1 -> V_156 = 0 ;
goto V_161;
}
V_1 -> V_153 = F_25 ( V_16 ,
( void * ) V_1 -> V_160 ,
V_154 , V_155 ) ;
V_19 = F_26 ( V_16 , V_1 -> V_153 ) ;
if ( V_19 ) {
F_3 ( L_34 , V_19 ) ;
V_1 -> V_153 = 0 ;
goto V_162;
}
return 0 ;
V_162:
F_27 ( V_16 , V_1 -> V_156 ,
V_157 , V_70 ) ;
V_161:
F_28 ( V_1 -> V_158 ) ;
return V_19 ;
}
static int
F_68 ( struct V_33 * V_34 , struct V_163 * V_11 )
{
struct V_164 * V_164 = V_34 -> V_10 ;
struct V_165 * V_166 = V_164 -> V_166 ;
struct V_1 * V_1 ;
struct V_23 * V_24 ;
int V_19 = 0 ;
F_69 ( & V_166 -> V_167 ) ;
if ( ! V_166 -> V_168 ) {
F_70 ( & V_166 -> V_167 ) ;
F_9 ( L_35 ) ;
return F_71 ( V_34 , NULL , 0 ) ;
}
F_70 ( & V_166 -> V_167 ) ;
F_9 ( L_36 ,
V_34 , V_34 -> V_10 ) ;
V_1 = F_24 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_1 )
return - V_76 ;
F_61 ( V_1 ) ;
V_1 -> V_13 = V_34 ;
V_19 = F_67 ( V_1 , V_34 -> V_24 ) ;
if ( V_19 )
goto V_169;
V_24 = F_46 ( V_34 ) ;
if ( F_20 ( V_24 ) ) {
V_19 = F_21 ( V_24 ) ;
goto V_170;
}
V_1 -> V_24 = V_24 ;
V_1 -> V_171 = F_34 ( V_172 ,
V_11 -> V_173 . V_2 . V_171 ,
V_24 -> V_48 . V_174 ) ;
F_9 ( L_37 , V_1 -> V_171 ) ;
V_19 = F_19 ( V_1 , V_34 ) ;
if ( V_19 )
goto V_175;
V_19 = F_72 ( V_1 ) ;
if ( V_19 )
goto V_175;
V_19 = F_73 ( V_1 ) ;
if ( V_19 )
goto V_175;
F_11 ( & V_164 -> V_149 ) ;
F_49 ( & V_1 -> V_144 , & V_164 -> V_176 ) ;
F_12 ( & V_164 -> V_149 ) ;
return 0 ;
V_175:
F_44 ( V_24 ) ;
V_170:
F_66 ( V_1 ) ;
V_169:
F_28 ( V_1 ) ;
F_71 ( V_34 , NULL , 0 ) ;
return V_19 ;
}
static void
F_74 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
F_9 ( L_38 , V_1 ) ;
F_75 ( ! V_24 ) ;
if ( V_24 -> V_82 )
F_50 ( V_1 ) ;
F_29 ( V_1 ) ;
if ( V_1 -> V_13 )
F_76 ( V_1 -> V_13 ) ;
if ( V_1 -> V_58 ) {
struct V_22 * V_25 = V_1 -> V_58 -> V_41 -> V_177 ;
F_14 ( V_25 ) ;
F_77 ( V_1 -> V_58 ) ;
}
if ( V_1 -> V_158 )
F_66 ( V_1 ) ;
F_44 ( V_24 ) ;
F_28 ( V_1 ) ;
}
static void
F_78 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
struct V_164 * V_164 = V_34 -> V_10 ;
F_13 ( L_38 , V_1 ) ;
F_11 ( & V_1 -> V_149 ) ;
V_1 -> V_142 = V_178 ;
F_79 ( & V_1 -> V_148 ) ;
F_12 ( & V_1 -> V_149 ) ;
F_11 ( & V_164 -> V_149 ) ;
F_80 ( & V_1 -> V_144 , & V_164 -> V_179 ) ;
F_12 ( & V_164 -> V_149 ) ;
F_13 ( L_39 , V_164 ) ;
F_81 ( & V_164 -> V_180 ) ;
}
static void
F_82 ( struct V_148 * V_148 )
{
struct V_1 * V_1 = F_83 ( V_148 ,
struct V_1 , V_148 ) ;
F_13 ( L_40 , V_1 , V_181 -> V_182 ,
V_181 -> V_183 ) ;
F_74 ( V_1 ) ;
}
static void
F_84 ( struct V_1 * V_1 )
{
F_85 ( & V_1 -> V_148 , F_82 ) ;
}
static void
F_86 ( struct V_1 * V_1 )
{
int V_59 ;
switch ( V_1 -> V_142 ) {
case V_184 :
break;
case V_178 :
case V_185 :
F_13 ( L_41 ,
V_1 , V_1 -> V_142 ) ;
V_1 -> V_142 = V_184 ;
V_59 = F_87 ( V_1 -> V_13 ) ;
if ( V_59 )
F_6 ( L_42 ,
V_1 ) ;
break;
default:
F_6 ( L_43 ,
V_1 , V_1 -> V_142 ) ;
}
}
static int
F_88 ( struct V_164 * V_164 ,
enum V_186 V_11 )
{
F_9 ( L_44 ,
F_89 ( V_11 ) , V_11 , V_164 ) ;
switch ( V_11 ) {
case V_187 :
V_164 -> V_13 = NULL ;
break;
case V_188 :
V_164 -> V_13 = F_90 ( V_164 ) ;
if ( F_20 ( V_164 -> V_13 ) ) {
F_3 ( L_45 ,
V_164 , F_21 ( V_164 -> V_13 ) ) ;
V_164 -> V_13 = NULL ;
}
break;
default:
F_3 ( L_46 ,
V_164 , V_11 ) ;
}
return - 1 ;
}
static int
F_91 ( struct V_33 * V_34 ,
enum V_186 V_11 )
{
struct V_164 * V_164 = V_34 -> V_10 ;
struct V_1 * V_1 ;
bool V_189 = false ;
if ( V_164 -> V_13 == V_34 )
return F_88 ( V_34 -> V_10 , V_11 ) ;
V_1 = V_34 -> V_58 -> V_38 ;
F_11 ( & V_1 -> V_149 ) ;
V_189 = ( V_1 -> V_142 == V_184 ) ;
F_86 ( V_1 ) ;
F_12 ( & V_1 -> V_149 ) ;
F_13 ( L_47 , V_1 ) ;
F_92 ( & V_1 -> V_147 ) ;
if ( V_189 )
goto V_169;
F_11 ( & V_164 -> V_149 ) ;
if ( ! F_51 ( & V_1 -> V_144 ) ) {
F_93 ( & V_1 -> V_144 ) ;
F_84 ( V_1 ) ;
F_94 ( V_190 , & V_1 -> V_151 ) ;
}
F_12 ( & V_164 -> V_149 ) ;
V_169:
return 0 ;
}
static int
F_95 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
F_93 ( & V_1 -> V_144 ) ;
V_1 -> V_13 = NULL ;
F_84 ( V_1 ) ;
return - 1 ;
}
static int
F_96 ( struct V_33 * V_34 , struct V_163 * V_11 )
{
int V_19 = 0 ;
F_13 ( L_48 ,
F_89 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_191 , V_34 , V_34 -> V_10 ) ;
switch ( V_11 -> V_11 ) {
case V_192 :
V_19 = F_68 ( V_34 , V_11 ) ;
if ( V_19 )
F_3 ( L_49 , V_19 ) ;
break;
case V_193 :
F_78 ( V_34 ) ;
break;
case V_188 :
case V_194 :
case V_187 :
case V_195 :
V_19 = F_91 ( V_34 , V_11 -> V_11 ) ;
break;
case V_196 :
case V_197 :
case V_198 :
V_19 = F_95 ( V_34 ) ;
break;
default:
F_3 ( L_50 , V_11 -> V_11 ) ;
break;
}
return V_19 ;
}
static int
F_97 ( struct V_1 * V_1 , V_138 V_199 )
{
struct V_200 * V_201 , * V_202 ;
int V_26 , V_19 ;
struct V_60 * V_61 ;
for ( V_201 = V_1 -> V_201 , V_26 = 0 ; V_26 < V_199 ; V_26 ++ , V_201 ++ ) {
V_61 = & V_1 -> V_66 [ V_26 ] ;
V_201 -> V_203 = ( V_204 ) V_61 ;
V_201 -> V_205 = & V_61 -> V_63 ;
V_201 -> V_206 = 1 ;
V_201 -> V_207 = V_201 + 1 ;
}
V_201 -- ;
V_201 -> V_207 = NULL ;
V_1 -> V_208 += V_199 ;
V_19 = F_98 ( V_1 -> V_58 , V_1 -> V_201 ,
& V_202 ) ;
if ( V_19 ) {
F_3 ( L_51 , V_19 ) ;
V_1 -> V_208 -= V_199 ;
}
return V_19 ;
}
static int
F_99 ( struct V_1 * V_1 , struct V_60 * V_61 )
{
struct V_200 * V_202 , V_201 ;
int V_19 ;
V_201 . V_203 = ( V_204 ) V_61 ;
V_201 . V_205 = & V_61 -> V_63 ;
V_201 . V_206 = 1 ;
V_201 . V_207 = NULL ;
V_1 -> V_208 ++ ;
V_19 = F_98 ( V_1 -> V_58 , & V_201 , & V_202 ) ;
if ( V_19 ) {
F_3 ( L_51 , V_19 ) ;
V_1 -> V_208 -- ;
}
return V_19 ;
}
static int
F_100 ( struct V_1 * V_1 , struct V_209 * V_210 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_211 V_212 , * V_213 ;
int V_19 ;
F_101 ( V_16 , V_210 -> V_64 ,
V_214 , V_155 ) ;
V_212 . V_207 = NULL ;
V_212 . V_203 = ( V_204 ) V_210 ;
V_212 . V_205 = V_210 -> V_215 ;
V_212 . V_206 = V_210 -> V_206 ;
V_212 . V_216 = V_217 ;
V_212 . V_218 = V_219 ;
V_19 = F_102 ( V_1 -> V_58 , & V_212 , & V_213 ) ;
if ( V_19 )
F_3 ( L_52 , V_19 ) ;
return V_19 ;
}
static void
F_103 ( struct V_1 * V_1 ,
struct V_220 * V_220 ,
struct V_209 * V_210 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
F_104 ( V_16 , V_210 -> V_64 ,
V_214 , V_155 ) ;
memset ( & V_210 -> V_221 , 0 , sizeof( struct V_222 ) ) ;
V_210 -> V_221 . V_223 = V_224 ;
V_210 -> V_206 = 1 ;
V_210 -> V_220 = V_220 ;
if ( V_210 -> V_215 [ 0 ] . V_74 != V_24 -> V_57 -> V_75 ) {
V_210 -> V_215 [ 0 ] . V_74 = V_24 -> V_57 -> V_75 ;
F_9 ( L_53 , V_210 ) ;
}
}
static int
F_105 ( struct V_1 * V_1 ,
struct V_209 * V_210 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
T_1 V_64 ;
V_64 = F_25 ( V_16 , ( void * ) V_210 ,
V_214 , V_155 ) ;
if ( F_26 ( V_16 , V_64 ) ) {
F_3 ( L_54 ) ;
return - V_76 ;
}
V_210 -> V_64 = V_64 ;
V_210 -> V_215 [ 0 ] . V_72 = V_210 -> V_64 ;
V_210 -> V_215 [ 0 ] . V_73 = V_214 ;
V_210 -> V_215 [ 0 ] . V_74 = V_24 -> V_57 -> V_75 ;
F_9 ( L_55 ,
V_210 -> V_215 [ 0 ] . V_72 , V_210 -> V_215 [ 0 ] . V_73 ,
V_210 -> V_215 [ 0 ] . V_74 ) ;
return 0 ;
}
static void
F_106 ( struct V_1 * V_1 , struct V_220 * V_220 ,
struct V_211 * V_212 )
{
struct V_209 * V_210 = & V_220 -> V_210 ;
V_220 -> V_225 . V_226 = V_227 ;
V_212 -> V_203 = ( V_204 ) & V_220 -> V_210 ;
V_212 -> V_216 = V_217 ;
V_212 -> V_205 = & V_210 -> V_215 [ 0 ] ;
V_212 -> V_206 = V_220 -> V_210 . V_206 ;
V_212 -> V_218 = V_219 ;
}
static int
F_72 ( struct V_1 * V_1 )
{
struct V_200 V_201 , * V_228 ;
struct V_62 V_229 ;
int V_19 ;
memset ( & V_229 , 0 , sizeof( struct V_62 ) ) ;
V_229 . V_72 = V_1 -> V_156 ;
V_229 . V_73 = V_154 ;
V_229 . V_74 = V_1 -> V_24 -> V_57 -> V_75 ;
F_9 ( L_56 ,
V_229 . V_72 , V_229 . V_73 , V_229 . V_74 ) ;
memset ( & V_201 , 0 , sizeof( struct V_200 ) ) ;
V_201 . V_203 = ( V_204 ) V_1 -> V_159 ;
V_201 . V_205 = & V_229 ;
V_201 . V_206 = 1 ;
V_1 -> V_208 ++ ;
V_19 = F_98 ( V_1 -> V_58 , & V_201 , & V_228 ) ;
if ( V_19 ) {
F_3 ( L_57 , V_19 ) ;
V_1 -> V_208 -- ;
}
return V_19 ;
}
static int
F_107 ( struct V_230 * V_2 , struct V_231 * V_232 ,
V_138 V_73 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_209 * V_210 = & V_1 -> V_233 ;
int V_19 ;
F_103 ( V_1 , NULL , V_210 ) ;
memcpy ( & V_210 -> V_234 , & V_232 -> V_235 [ 0 ] ,
sizeof( struct V_236 ) ) ;
F_105 ( V_1 , V_210 ) ;
if ( V_73 > 0 ) {
struct V_62 * V_237 = & V_210 -> V_215 [ 1 ] ;
F_104 ( V_16 , V_1 -> V_153 ,
V_73 , V_155 ) ;
memcpy ( V_1 -> V_160 , V_232 -> V_238 , V_73 ) ;
F_101 ( V_16 , V_1 -> V_153 ,
V_73 , V_155 ) ;
V_237 -> V_72 = V_1 -> V_153 ;
V_237 -> V_73 = V_73 ;
V_237 -> V_74 = V_1 -> V_24 -> V_57 -> V_75 ;
V_210 -> V_206 = 2 ;
}
if ( ! V_232 -> V_239 ) {
if ( V_232 -> V_240 ) {
if ( ! V_2 -> V_134 -> V_241 -> V_242 &&
V_1 -> V_24 -> V_82 ) {
V_19 = F_59 ( V_1 ) ;
if ( V_19 ) {
F_3 ( L_58
L_59 , V_1 ) ;
return V_19 ;
}
}
V_19 = F_23 ( V_1 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_97 ( V_1 ,
V_46 ) ;
if ( V_19 )
return V_19 ;
F_11 ( & V_1 -> V_149 ) ;
V_1 -> V_142 = V_185 ;
F_12 ( & V_1 -> V_149 ) ;
goto V_243;
}
V_19 = F_72 ( V_1 ) ;
if ( V_19 )
return V_19 ;
}
V_243:
V_19 = F_100 ( V_1 , V_210 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void
F_108 ( struct V_1 * V_1 )
{
struct V_60 * V_61 = ( void * ) V_1 -> V_159 ;
int V_244 = V_1 -> V_245 ;
struct V_230 * V_2 = V_1 -> V_2 ;
struct V_231 * V_232 = V_2 -> V_246 ;
int V_247 ;
F_13 ( L_38 , V_1 ) ;
F_109 ( ! V_232 ) ;
if ( V_232 -> V_248 ) {
struct V_249 * V_250 =
(struct V_249 * ) & V_61 -> V_234 ;
V_232 -> V_251 = ( ! V_250 -> V_252 ) ? 1 : 0 ;
V_232 -> V_253 =
( V_250 -> V_223 & V_254 )
>> 2 ;
V_232 -> V_255 = V_250 -> V_256 ;
V_232 -> V_257 = V_250 -> V_258 ;
memcpy ( V_232 -> V_259 , V_250 -> V_259 , 6 ) ;
V_232 -> V_260 = F_110 ( V_250 -> V_261 ) ;
V_232 -> V_262 = V_250 -> V_263 ;
V_232 -> V_264 = F_110 ( V_250 -> V_265 ) ;
V_232 -> V_266 = F_111 ( V_250 -> V_266 ) ;
V_232 -> V_252 = F_111 ( V_250 -> V_252 ) ;
}
memcpy ( & V_232 -> V_267 [ 0 ] , ( void * ) & V_61 -> V_234 , V_268 ) ;
V_247 = V_27 ( V_244 , V_269 ) ;
F_9 ( L_60
L_61 , V_247 , V_244 ,
V_269 ) ;
memcpy ( V_232 -> V_270 , & V_61 -> V_271 [ 0 ] , V_247 ) ;
if ( V_232 -> V_248 ) {
F_92 ( & V_1 -> V_145 ) ;
return;
}
F_112 ( & V_2 -> V_272 , 0 ) ;
}
static struct V_273
* F_113 ( struct V_230 * V_2 , struct V_60 * V_61 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_220 * V_220 ;
struct V_273 * V_4 ;
V_4 = F_114 ( V_2 , V_274 ) ;
if ( ! V_4 ) {
F_3 ( L_62 ) ;
return NULL ;
}
V_220 = F_115 ( V_4 ) ;
V_220 -> V_2 = V_1 ;
V_220 -> V_273 = V_4 ;
V_220 -> V_61 = V_61 ;
return V_4 ;
}
static int
F_116 ( struct V_1 * V_1 ,
struct V_220 * V_220 , struct V_273 * V_4 ,
struct V_60 * V_61 , unsigned char * V_275 )
{
struct V_230 * V_2 = V_1 -> V_2 ;
struct V_276 * V_277 = (struct V_276 * ) V_275 ;
int V_278 , V_279 , V_280 , V_281 , V_282 ;
bool V_283 = false ;
unsigned int V_284 ;
V_282 = F_117 ( V_2 , V_4 , V_275 ) ;
if ( V_282 < 0 )
return V_282 ;
V_278 = V_4 -> V_285 ;
V_279 = V_4 -> V_286 ;
V_280 = V_4 -> V_287 ;
V_284 = V_4 -> V_3 . V_288 ;
if ( V_278 && V_279 == V_284 )
V_4 -> V_3 . V_289 |= V_290 ;
V_282 = F_118 ( V_2 , V_4 , V_277 ) ;
if ( V_282 < 0 ) {
return 0 ;
} else if ( V_282 > 0 ) {
V_283 = true ;
goto V_291;
}
if ( ! V_278 )
return 0 ;
if ( V_279 != V_284 ) {
V_281 = F_16 ( 1UL , F_119 ( V_279 , V_292 ) ) ;
F_120 ( V_4 -> V_3 . V_293 , V_281 ,
& V_61 -> V_271 [ 0 ] , V_279 ) ;
F_9 ( L_63 ,
V_281 , V_279 ) ;
} else {
F_121 ( & V_220 -> V_294 , 1 ) ;
V_4 -> V_3 . V_293 = & V_220 -> V_294 ;
V_4 -> V_3 . V_295 = 1 ;
F_122 ( & V_220 -> V_294 , & V_61 -> V_271 [ 0 ] , V_279 ) ;
F_9 ( L_64 ,
V_279 ) ;
}
V_4 -> V_296 += V_279 ;
if ( V_4 -> V_296 == V_4 -> V_3 . V_288 ) {
F_69 ( & V_4 -> V_297 ) ;
V_4 -> V_298 |= V_299 ;
V_4 -> V_300 = V_301 ;
F_70 ( & V_4 -> V_297 ) ;
}
V_291:
V_282 = F_123 ( V_2 , V_4 , V_275 , V_277 -> V_261 ) ;
if ( ! V_282 && V_283 == false && V_280 )
F_124 ( V_4 ) ;
else if ( V_283 && V_278 )
F_125 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_126 ( struct V_1 * V_1 ,
struct V_60 * V_61 , unsigned char * V_275 )
{
struct V_302 * V_303 ;
struct V_230 * V_2 = V_1 -> V_2 ;
struct V_273 * V_4 = NULL ;
struct V_304 * V_277 = (struct V_304 * ) V_275 ;
V_138 V_305 = F_127 ( V_277 -> V_306 ) ;
int V_282 , V_281 , V_307 , V_308 ;
V_282 = F_128 ( V_2 , V_275 , & V_4 ) ;
if ( V_282 < 0 )
return V_282 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_287 ) {
F_3 ( L_65 ) ;
F_129 () ;
return - 1 ;
}
F_9 ( L_66
L_67 ,
V_305 , V_4 -> V_296 ,
V_4 -> V_3 . V_288 ) ;
V_307 = V_4 -> V_296 / V_292 ;
V_303 = & V_4 -> V_3 . V_293 [ V_307 ] ;
V_281 = F_16 ( 1UL , F_119 ( V_305 , V_292 ) ) ;
V_308 = V_4 -> V_296 % V_292 ;
if ( V_308 ) {
F_3 ( L_68 ) ;
F_129 () ;
return - 1 ;
}
F_9 ( L_69
L_70 , V_303 , V_307 ,
V_281 , & V_61 -> V_271 [ 0 ] , V_305 ) ;
F_120 ( V_303 , V_281 , & V_61 -> V_271 [ 0 ] ,
V_305 ) ;
V_282 = F_130 ( V_4 , V_277 , false ) ;
if ( V_282 < 0 )
return V_282 ;
V_282 = F_99 ( V_1 , V_61 ) ;
if ( V_282 ) {
F_3 ( L_71 , V_282 ) ;
return V_282 ;
}
return 0 ;
}
static int
F_131 ( struct V_1 * V_1 , struct V_220 * V_220 ,
struct V_273 * V_4 , struct V_60 * V_61 ,
unsigned char * V_275 )
{
struct V_230 * V_2 = V_1 -> V_2 ;
struct V_309 * V_277 = (struct V_309 * ) V_275 ;
int V_282 ;
V_282 = F_132 ( V_2 , V_4 , V_277 ) ;
if ( V_282 < 0 )
return V_282 ;
return F_133 ( V_2 , V_4 , V_277 ) ;
}
static int
F_134 ( struct V_1 * V_1 , struct V_220 * V_220 ,
struct V_273 * V_4 , struct V_60 * V_61 ,
struct V_310 * V_277 )
{
struct V_230 * V_2 = V_1 -> V_2 ;
V_138 V_311 = F_127 ( V_277 -> V_306 ) ;
int V_282 ;
unsigned char * V_312 = NULL ;
V_282 = F_135 ( V_2 , V_4 , V_277 ) ;
if ( V_282 < 0 )
return V_282 ;
if ( V_311 ) {
V_312 = F_24 ( V_311 , V_67 ) ;
if ( ! V_312 ) {
F_3 ( L_72 ,
V_311 ) ;
return - V_76 ;
}
}
V_4 -> V_313 = V_312 ;
memcpy ( V_4 -> V_313 , & V_61 -> V_271 [ 0 ] , V_311 ) ;
return F_136 ( V_2 , V_4 , V_277 ) ;
}
static int
F_137 ( struct V_1 * V_1 , struct V_60 * V_61 ,
T_2 V_314 , T_3 V_315 ,
T_2 V_316 , T_3 V_317 )
{
struct V_236 * V_277 = & V_61 -> V_234 ;
struct V_230 * V_2 = V_1 -> V_2 ;
struct V_273 * V_4 ;
struct V_220 * V_220 ;
int V_19 = - V_318 ;
V_172 V_216 = ( V_277 -> V_216 & V_319 ) ;
if ( V_2 -> V_134 -> V_241 -> V_242 &&
( ! ( V_216 & V_320 ) || ! ( V_216 & V_321 ) ) ) {
F_3 ( L_73
L_74 , V_216 ) ;
return 0 ;
}
switch ( V_216 ) {
case V_322 :
V_4 = F_113 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_220 = F_115 ( V_4 ) ;
V_220 -> V_314 = V_314 ;
V_220 -> V_315 = V_315 ;
V_220 -> V_316 = V_316 ;
V_220 -> V_317 = V_317 ;
V_19 = F_116 ( V_1 , V_220 , V_4 ,
V_61 , ( unsigned char * ) V_277 ) ;
break;
case V_323 :
V_4 = F_113 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_220 = F_115 ( V_4 ) ;
V_19 = F_131 ( V_1 , V_220 , V_4 ,
V_61 , ( unsigned char * ) V_277 ) ;
break;
case V_324 :
V_19 = F_126 ( V_1 , V_61 ,
( unsigned char * ) V_277 ) ;
break;
case V_325 :
V_4 = F_113 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_19 = F_138 ( V_2 , V_4 ,
( unsigned char * ) V_277 ) ;
break;
case V_321 :
V_4 = F_113 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_19 = F_139 ( V_2 , V_4 , ( unsigned char * ) V_277 ) ;
break;
case V_320 :
if ( F_110 ( V_277 -> V_326 ) != 0xFFFFFFFF )
V_4 = F_140 ( V_2 , V_277 -> V_263 ) ;
else
V_4 = F_113 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_220 = F_115 ( V_4 ) ;
V_19 = F_134 ( V_1 , V_220 , V_4 ,
V_61 , (struct V_310 * ) V_277 ) ;
break;
default:
F_3 ( L_75 , V_216 ) ;
F_129 () ;
break;
}
return V_19 ;
}
static void
F_141 ( struct V_60 * V_61 , struct V_1 * V_1 )
{
struct V_222 * V_222 = & V_61 -> V_221 ;
T_3 V_315 = 0 , V_317 = 0 ;
T_2 V_314 = 0 , V_316 = 0 ;
int V_282 ;
switch ( V_222 -> V_223 & 0xF0 ) {
case V_327 :
if ( V_222 -> V_223 & V_328 ) {
V_314 = F_110 ( V_222 -> V_314 ) ;
V_315 = F_142 ( V_222 -> V_315 ) ;
F_9 ( L_76 ,
V_314 , ( unsigned long long ) V_315 ) ;
}
if ( V_222 -> V_223 & V_329 ) {
V_316 = F_110 ( V_222 -> V_316 ) ;
V_317 = F_142 ( V_222 -> V_317 ) ;
F_9 ( L_77 ,
V_316 , ( unsigned long long ) V_317 ) ;
}
F_9 ( L_78 ) ;
break;
case V_330 :
F_3 ( L_79 ) ;
break;
default:
F_6 ( L_80 , V_222 -> V_223 ) ;
break;
}
V_282 = F_137 ( V_1 , V_61 ,
V_314 , V_315 , V_316 , V_317 ) ;
}
static void
F_143 ( struct V_60 * V_117 ,
struct V_1 * V_1 ,
V_138 V_331 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_236 * V_277 ;
T_1 V_332 ;
int V_244 ;
if ( ( char * ) V_117 == V_1 -> V_159 ) {
V_332 = V_1 -> V_156 ;
V_244 = V_154 ;
F_9 ( L_81 ,
V_332 , V_244 ) ;
} else {
V_332 = V_117 -> V_64 ;
V_244 = V_69 ;
F_9 ( L_82 ,
V_332 , V_244 ) ;
}
F_104 ( V_16 , V_332 , V_244 , V_70 ) ;
V_277 = & V_117 -> V_234 ;
F_9 ( L_83 ,
V_277 -> V_216 , V_277 -> V_263 , V_277 -> V_223 ,
( int ) ( V_331 - V_214 ) ) ;
if ( ( char * ) V_117 == V_1 -> V_159 ) {
V_1 -> V_245 = V_331 - V_214 ;
if ( V_1 -> V_2 ) {
struct V_231 * V_232 = V_1 -> V_2 -> V_246 ;
if ( V_232 && ! V_232 -> V_248 )
F_108 ( V_1 ) ;
}
F_11 ( & V_1 -> V_149 ) ;
F_92 ( & V_1 -> V_146 ) ;
F_12 ( & V_1 -> V_149 ) ;
} else {
F_141 ( V_117 , V_1 ) ;
}
F_101 ( V_16 , V_332 , V_244 ,
V_70 ) ;
V_1 -> V_208 -- ;
}
static int
F_144 ( struct V_1 * V_1 , struct V_220 * V_220 ,
struct V_302 * V_294 , V_138 V_333 , V_138 V_73 , V_138 V_334 ,
enum V_335 V_336 , struct V_337 * V_271 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
V_271 -> V_338 = V_336 == V_339 ?
V_155 : V_70 ;
V_271 -> V_340 = V_73 - V_334 ;
V_271 -> V_334 = V_334 ;
V_271 -> V_307 = V_271 -> V_334 / V_292 ;
V_271 -> V_294 = & V_294 [ V_271 -> V_307 ] ;
V_271 -> V_333 = F_34 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_271 -> V_340 = F_34 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_271 -> V_341 = F_145 ( V_16 , V_271 -> V_294 , V_271 -> V_333 ,
V_271 -> V_338 ) ;
if ( F_146 ( ! V_271 -> V_341 ) ) {
F_3 ( L_84 , V_294 ) ;
return - V_318 ;
}
F_9 ( L_85 ,
V_220 , V_271 -> V_341 , V_271 -> V_294 , V_271 -> V_333 , V_271 -> V_340 ) ;
return 0 ;
}
static void
F_147 ( struct V_1 * V_1 , struct V_337 * V_271 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
F_148 ( V_16 , V_271 -> V_294 , V_271 -> V_333 , V_271 -> V_338 ) ;
memset ( V_271 , 0 , sizeof( * V_271 ) ) ;
}
static void
V_100 ( struct V_220 * V_220 , struct V_1 * V_1 )
{
struct V_342 * V_343 = & V_220 -> V_225 ;
F_9 ( L_86 , V_220 ) ;
if ( V_343 -> V_271 . V_294 ) {
F_9 ( L_87 , V_220 ) ;
F_147 ( V_1 , & V_343 -> V_271 ) ;
}
if ( V_343 -> V_212 ) {
F_9 ( L_88 , V_220 ) ;
F_28 ( V_343 -> V_212 ) ;
V_343 -> V_212 = NULL ;
}
if ( V_343 -> V_62 ) {
F_9 ( L_89 , V_220 ) ;
F_28 ( V_343 -> V_62 ) ;
V_343 -> V_62 = NULL ;
}
}
static void
V_98 ( struct V_220 * V_220 , struct V_1 * V_1 )
{
struct V_342 * V_343 = & V_220 -> V_225 ;
F_9 ( L_86 , V_220 ) ;
if ( V_343 -> V_106 ) {
F_9 ( L_90 , V_220 , V_343 -> V_106 ) ;
if ( V_343 -> V_106 -> V_124 & V_129 ) {
F_147 ( V_1 , & V_343 -> V_344 ) ;
V_343 -> V_106 -> V_124 &= ~ V_129 ;
}
F_69 ( & V_1 -> V_150 ) ;
F_49 ( & V_343 -> V_106 -> V_109 , & V_1 -> V_108 ) ;
F_70 ( & V_1 -> V_150 ) ;
V_343 -> V_106 = NULL ;
}
if ( V_343 -> V_271 . V_294 ) {
F_9 ( L_87 , V_220 ) ;
F_147 ( V_1 , & V_343 -> V_271 ) ;
}
V_343 -> V_62 = NULL ;
V_343 -> V_212 = NULL ;
}
static void
F_149 ( struct V_220 * V_220 , bool V_345 )
{
struct V_273 * V_4 = V_220 -> V_273 ;
struct V_1 * V_1 = V_220 -> V_2 ;
struct V_230 * V_2 = V_1 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_346 * V_277 ;
F_9 ( L_86 , V_220 ) ;
switch ( V_4 -> V_347 ) {
case V_322 :
F_69 ( & V_2 -> V_348 ) ;
if ( ! F_51 ( & V_4 -> V_349 ) )
F_93 ( & V_4 -> V_349 ) ;
F_70 ( & V_2 -> V_348 ) ;
if ( V_4 -> V_350 == V_155 ) {
F_150 ( V_4 ) ;
if ( V_345 &&
V_4 -> V_3 . V_351 == V_352 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_125 ( V_3 ) ;
}
}
V_24 -> V_97 ( V_220 , V_1 ) ;
F_151 ( & V_4 -> V_3 , 0 ) ;
break;
case V_325 :
F_69 ( & V_2 -> V_348 ) ;
if ( ! F_51 ( & V_4 -> V_349 ) )
F_93 ( & V_4 -> V_349 ) ;
F_70 ( & V_2 -> V_348 ) ;
F_151 ( & V_4 -> V_3 , 0 ) ;
break;
case V_353 :
case V_323 :
case V_320 :
V_277 = (struct V_346 * ) & V_220 -> V_210 . V_234 ;
if ( V_277 -> V_223 & V_354 )
break;
F_69 ( & V_2 -> V_348 ) ;
if ( ! F_51 ( & V_4 -> V_349 ) )
F_93 ( & V_4 -> V_349 ) ;
F_70 ( & V_2 -> V_348 ) ;
if ( V_4 -> V_3 . V_355 != NULL ) {
F_9 ( L_91 ,
V_4 -> V_347 ) ;
F_151 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_152 ( V_4 ) ;
break;
}
}
static void
F_153 ( struct V_209 * V_210 , struct V_15 * V_16 )
{
if ( V_210 -> V_64 != 0 ) {
F_9 ( L_92 ) ;
F_27 ( V_16 , V_210 -> V_64 ,
V_214 , V_155 ) ;
V_210 -> V_64 = 0 ;
}
}
static void
F_154 ( struct V_209 * V_210 , struct V_220 * V_220 ,
struct V_15 * V_16 , bool V_345 )
{
if ( V_220 -> V_356 != 0 ) {
F_9 ( L_93 ) ;
F_27 ( V_16 , V_220 -> V_356 ,
V_220 -> V_357 , V_155 ) ;
V_220 -> V_356 = 0 ;
}
F_153 ( V_210 , V_16 ) ;
F_149 ( V_220 , V_345 ) ;
}
static int
F_155 ( struct V_3 * V_3 , struct V_358 * V_115 )
{
struct V_359 V_360 ;
int V_19 ;
V_19 = F_156 ( V_115 , V_361 , & V_360 ) ;
if ( V_19 ) {
F_3 ( L_94 , V_19 ) ;
goto V_362;
}
if ( V_360 . V_363 & V_361 ) {
T_1 V_364 ;
V_138 V_365 = V_3 -> V_366 -> V_367 . V_365 + 8 ;
switch ( V_360 . V_368 . V_369 ) {
case V_370 :
V_3 -> V_371 = V_372 ;
break;
case V_373 :
V_3 -> V_371 = V_374 ;
break;
case V_375 :
V_3 -> V_371 = V_376 ;
break;
}
V_364 = V_360 . V_368 . V_377 ;
F_157 ( V_364 , V_365 ) ;
V_3 -> V_378 = V_364 + V_3 -> V_379 ;
F_3 ( L_95
L_96 ,
V_360 . V_368 . V_369 ,
( unsigned long long ) V_3 -> V_378 ,
V_360 . V_368 . V_380 ,
V_360 . V_368 . V_381 ) ;
V_19 = 1 ;
}
V_362:
return V_19 ;
}
static void
F_158 ( struct V_209 * V_210 ,
struct V_220 * V_220 )
{
struct V_342 * V_343 = & V_220 -> V_225 ;
struct V_273 * V_4 = V_220 -> V_273 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_220 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_343 -> V_106 && V_343 -> V_106 -> V_124 & V_129 ) {
V_19 = F_155 ( V_3 ,
V_343 -> V_106 -> V_112 -> V_115 ) ;
V_343 -> V_106 -> V_124 &= ~ V_129 ;
}
V_24 -> V_97 ( V_220 , V_1 ) ;
V_343 -> V_382 = 0 ;
if ( V_19 )
F_159 ( V_3 ,
V_3 -> V_371 , 0 ) ;
else
F_160 ( V_1 -> V_2 , V_4 ) ;
}
static void
F_161 ( struct V_209 * V_210 ,
struct V_220 * V_220 )
{
struct V_342 * V_343 = & V_220 -> V_225 ;
struct V_273 * V_4 = V_220 -> V_273 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_220 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_343 -> V_106 && V_343 -> V_106 -> V_124 & V_129 ) {
V_19 = F_155 ( V_3 ,
V_343 -> V_106 -> V_112 -> V_115 ) ;
V_343 -> V_106 -> V_124 &= ~ V_129 ;
}
F_150 ( V_4 ) ;
V_24 -> V_97 ( V_220 , V_1 ) ;
V_4 -> V_296 = V_343 -> V_271 . V_340 ;
V_343 -> V_382 = 0 ;
F_9 ( L_97 , V_220 ) ;
F_69 ( & V_4 -> V_297 ) ;
V_4 -> V_298 |= V_299 ;
V_4 -> V_300 = V_301 ;
F_70 ( & V_4 -> V_297 ) ;
if ( V_19 ) {
F_125 ( V_3 ) ;
F_159 ( V_3 ,
V_3 -> V_371 , 0 ) ;
} else {
F_162 ( V_3 ) ;
}
}
static void
F_163 ( struct V_383 * V_77 )
{
struct V_220 * V_220 = F_83 ( V_77 ,
struct V_220 , V_384 ) ;
struct V_1 * V_1 = V_220 -> V_2 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_273 * V_4 = V_220 -> V_273 ;
F_9 ( L_98 , V_220 , V_4 -> V_300 ) ;
switch ( V_4 -> V_300 ) {
case V_385 :
F_164 ( V_4 , V_4 -> V_2 ) ;
case V_386 :
case V_387 :
V_4 -> V_300 = V_388 ;
F_154 ( & V_220 -> V_210 , V_220 ,
V_16 , false ) ;
break;
case V_389 :
F_165 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_99 , V_4 -> V_300 ) ;
F_129 () ;
break;
}
}
static void
F_166 ( struct V_209 * V_210 ,
struct V_220 * V_220 ,
struct V_1 * V_1 ,
struct V_15 * V_16 )
{
struct V_273 * V_4 = V_220 -> V_273 ;
if ( V_4 -> V_300 == V_385 ||
V_4 -> V_300 == V_389 ||
V_4 -> V_300 == V_386 ||
V_4 -> V_300 == V_387 ) {
F_153 ( V_210 , V_16 ) ;
F_37 ( & V_220 -> V_384 , F_163 ) ;
F_94 ( V_390 , & V_220 -> V_384 ) ;
return;
}
V_4 -> V_300 = V_388 ;
F_154 ( V_210 , V_220 , V_16 , false ) ;
}
static void
F_167 ( struct V_209 * V_210 ,
struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_220 * V_220 = V_210 -> V_220 ;
struct V_342 * V_343 ;
if ( ! V_220 ) {
F_153 ( V_210 , V_16 ) ;
return;
}
V_343 = & V_220 -> V_225 ;
F_9 ( L_100 , V_220 , V_343 -> V_226 ) ;
switch ( V_343 -> V_226 ) {
case V_227 :
F_166 ( V_210 , V_220 ,
V_1 , V_16 ) ;
break;
case V_339 :
F_158 ( V_210 , V_220 ) ;
break;
case V_391 :
F_161 ( V_210 , V_220 ) ;
break;
default:
F_3 ( L_101 , V_343 -> V_226 ) ;
F_129 () ;
break;
}
}
static inline bool
F_168 ( struct V_1 * V_1 , void * V_203 )
{
void * V_392 = V_1 -> V_66 ;
int V_340 = V_46 * sizeof( * V_1 -> V_66 ) ;
if ( V_203 >= V_392 && V_203 < V_392 + V_340 )
return false ;
return true ;
}
static void
F_169 ( struct V_1 * V_1 , struct V_393 * V_394 )
{
if ( V_394 -> V_203 == V_395 ) {
F_13 ( L_102 ,
V_1 ) ;
F_92 ( & V_1 -> V_396 ) ;
} else if ( F_168 ( V_1 , ( void * ) ( V_204 ) V_394 -> V_203 ) ) {
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_220 * V_220 ;
struct V_209 * V_117 ;
V_117 = (struct V_209 * ) ( V_204 ) V_394 -> V_203 ;
V_220 = V_117 -> V_220 ;
if ( ! V_220 )
F_153 ( V_117 , V_16 ) ;
else
F_154 ( V_117 , V_220 , V_16 , true ) ;
} else {
V_1 -> V_208 -- ;
if ( ! V_1 -> V_208 )
F_170 ( V_1 -> V_2 , 0 ) ;
}
}
static void
F_171 ( struct V_393 * V_394 )
{
struct V_1 * V_1 ;
struct V_209 * V_210 ;
struct V_60 * V_61 ;
V_1 = V_394 -> V_58 -> V_38 ;
if ( F_172 ( V_394 -> V_191 == V_397 ) ) {
if ( V_394 -> V_216 == V_398 ) {
V_61 = (struct V_60 * ) ( V_204 ) V_394 -> V_203 ;
F_143 ( V_61 , V_1 , V_394 -> V_399 ) ;
} else {
V_210 = (struct V_209 * ) ( V_204 ) V_394 -> V_203 ;
F_167 ( V_210 , V_1 ) ;
}
} else {
if ( V_394 -> V_191 != V_400 )
F_3 ( L_103 ,
F_173 ( V_394 -> V_191 ) , V_394 -> V_191 ,
V_394 -> V_203 , V_394 -> V_401 ) ;
else
F_9 ( L_104 ,
F_173 ( V_394 -> V_191 ) , V_394 -> V_191 ,
V_394 -> V_203 ) ;
if ( V_394 -> V_203 != V_402 )
F_169 ( V_1 , V_394 ) ;
}
}
static void
V_86 ( struct V_383 * V_77 )
{
enum { V_403 = 65536 };
struct V_22 * V_25 = F_83 ( V_77 , struct V_22 ,
V_77 ) ;
struct V_393 * const V_404 = V_25 -> V_404 ;
int V_26 , V_405 , V_406 = 0 ;
while ( ( V_405 = F_174 ( V_25 -> V_40 , F_175 ( V_25 -> V_404 ) , V_404 ) ) > 0 ) {
for ( V_26 = 0 ; V_26 < V_405 ; V_26 ++ )
F_171 ( & V_404 [ V_26 ] ) ;
V_406 += V_405 ;
if ( V_406 >= V_403 )
break;
}
F_39 ( V_25 -> V_40 , V_91 ) ;
}
static void
V_89 ( struct V_407 * V_40 , void * V_10 )
{
struct V_22 * V_25 = V_10 ;
F_94 ( V_390 , & V_25 -> V_77 ) ;
}
static int
F_176 ( struct V_1 * V_1 , struct V_220 * V_220 )
{
struct V_211 * V_408 ;
int V_19 ;
V_19 = F_99 ( V_1 , V_220 -> V_61 ) ;
if ( V_19 ) {
F_3 ( L_71 , V_19 ) ;
return V_19 ;
}
V_19 = F_102 ( V_1 -> V_58 , & V_220 -> V_210 . V_212 ,
& V_408 ) ;
if ( V_19 ) {
F_3 ( L_105 , V_19 ) ;
return V_19 ;
}
return V_19 ;
}
static int
F_160 ( struct V_230 * V_2 , struct V_273 * V_4 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_211 * V_212 = & V_220 -> V_210 . V_212 ;
struct V_409 * V_277 = (struct V_409 * )
& V_220 -> V_210 . V_234 ;
F_103 ( V_1 , V_220 , & V_220 -> V_210 ) ;
F_177 ( V_4 , V_2 , true , V_277 ) ;
F_105 ( V_1 , & V_220 -> V_210 ) ;
if ( V_4 -> V_3 . V_410 &&
( ( V_4 -> V_3 . V_289 & V_411 ) ||
( V_4 -> V_3 . V_289 & V_412 ) ) ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_237 = & V_220 -> V_210 . V_215 [ 1 ] ;
V_138 V_413 , V_414 ;
F_178 ( V_4 -> V_3 . V_415 ,
V_4 -> V_410 ) ;
V_4 -> V_3 . V_415 += sizeof( V_416 ) ;
V_413 = - ( V_4 -> V_3 . V_415 ) & 3 ;
F_179 ( V_277 -> V_306 , ( V_138 ) V_4 -> V_3 . V_415 ) ;
V_414 = V_4 -> V_3 . V_415 + V_413 ;
V_220 -> V_356 = F_25 ( V_16 ,
( void * ) V_4 -> V_410 , V_414 ,
V_155 ) ;
V_220 -> V_357 = V_414 ;
V_237 -> V_72 = V_220 -> V_356 ;
V_237 -> V_73 = V_414 ;
V_237 -> V_74 = V_24 -> V_57 -> V_75 ;
V_220 -> V_210 . V_206 = 2 ;
}
F_106 ( V_1 , V_220 , V_212 ) ;
F_9 ( L_106 ) ;
return F_176 ( V_1 , V_220 ) ;
}
static void
F_180 ( struct V_230 * V_2 , struct V_273 * V_4 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
F_69 ( & V_2 -> V_348 ) ;
if ( ! F_51 ( & V_4 -> V_349 ) )
F_93 ( & V_4 -> V_349 ) ;
F_70 ( & V_2 -> V_348 ) ;
if ( V_4 -> V_350 == V_155 )
F_150 ( V_4 ) ;
V_24 -> V_97 ( V_220 , V_1 ) ;
}
static enum V_417
F_181 ( struct V_230 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
if ( V_2 -> V_418 -> V_419 . V_420 ) {
if ( V_24 -> V_54 ) {
F_13 ( L_107 , V_1 ) ;
V_1 -> V_5 = true ;
return V_421 ;
}
}
F_13 ( L_108 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_182 ( struct V_273 * V_4 , struct V_230 * V_2 ,
bool V_422 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_211 * V_212 = & V_220 -> V_210 . V_212 ;
F_103 ( V_1 , V_220 , & V_220 -> V_210 ) ;
F_183 ( V_4 , V_2 , (struct V_423 * )
& V_220 -> V_210 . V_234 ,
V_422 ) ;
F_105 ( V_1 , & V_220 -> V_210 ) ;
F_106 ( V_1 , V_220 , V_212 ) ;
F_9 ( L_109 , V_1 ) ;
return F_176 ( V_1 , V_220 ) ;
}
static int
F_184 ( struct V_273 * V_4 , struct V_230 * V_2 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_211 * V_212 = & V_220 -> V_210 . V_212 ;
F_103 ( V_1 , V_220 , & V_220 -> V_210 ) ;
F_185 ( V_4 , V_2 , (struct V_424 * )
& V_220 -> V_210 . V_234 ) ;
F_105 ( V_1 , & V_220 -> V_210 ) ;
F_106 ( V_1 , V_220 , V_212 ) ;
F_9 ( L_110 , V_1 ) ;
return F_176 ( V_1 , V_220 ) ;
}
static int
F_186 ( struct V_273 * V_4 , struct V_230 * V_2 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_211 * V_212 = & V_220 -> V_210 . V_212 ;
F_103 ( V_1 , V_220 , & V_220 -> V_210 ) ;
F_187 ( V_4 , V_2 , (struct V_425 * )
& V_220 -> V_210 . V_234 ) ;
F_105 ( V_1 , & V_220 -> V_210 ) ;
F_106 ( V_1 , V_220 , V_212 ) ;
F_9 ( L_111 , V_1 ) ;
return F_176 ( V_1 , V_220 ) ;
}
static int
F_188 ( struct V_273 * V_4 , struct V_230 * V_2 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_211 * V_212 = & V_220 -> V_210 . V_212 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_237 = & V_220 -> V_210 . V_215 [ 1 ] ;
struct V_426 * V_277 =
(struct V_426 * ) & V_220 -> V_210 . V_234 ;
F_103 ( V_1 , V_220 , & V_220 -> V_210 ) ;
F_189 ( V_4 , V_2 , V_277 ) ;
F_105 ( V_1 , & V_220 -> V_210 ) ;
F_179 ( V_277 -> V_306 , V_268 ) ;
V_220 -> V_356 = F_25 ( V_16 ,
( void * ) V_4 -> V_427 , V_268 ,
V_155 ) ;
V_220 -> V_357 = V_268 ;
V_237 -> V_72 = V_220 -> V_356 ;
V_237 -> V_73 = V_268 ;
V_237 -> V_74 = V_24 -> V_57 -> V_75 ;
V_220 -> V_210 . V_206 = 2 ;
F_106 ( V_1 , V_220 , V_212 ) ;
F_9 ( L_112 , V_1 ) ;
return F_176 ( V_1 , V_220 ) ;
}
static int
F_190 ( struct V_273 * V_4 , struct V_230 * V_2 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_211 * V_212 = & V_220 -> V_210 . V_212 ;
struct V_346 * V_277 =
(struct V_346 * ) & V_220 -> V_210 . V_234 ;
V_138 V_428 ;
int V_282 ;
F_103 ( V_1 , V_220 , & V_220 -> V_210 ) ;
V_282 = F_191 ( V_4 , V_2 , V_277 , V_429 ) ;
if ( V_282 < 0 )
return V_282 ;
V_428 = V_282 ;
F_105 ( V_1 , & V_220 -> V_210 ) ;
if ( V_428 ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_237 = & V_220 -> V_210 . V_215 [ 1 ] ;
void * V_430 = V_4 -> V_427 ;
V_220 -> V_356 = F_25 ( V_16 ,
V_430 , V_428 , V_155 ) ;
V_220 -> V_357 = V_428 ;
V_237 -> V_72 = V_220 -> V_356 ;
V_237 -> V_73 = V_428 ;
V_237 -> V_74 = V_24 -> V_57 -> V_75 ;
V_220 -> V_210 . V_206 = 2 ;
}
F_106 ( V_1 , V_220 , V_212 ) ;
F_9 ( L_113 , V_1 ) ;
return F_176 ( V_1 , V_220 ) ;
}
static int
F_192 ( struct V_1 * V_1 , struct V_220 * V_220 ,
struct V_62 * V_62 , struct V_211 * V_212 ,
V_138 V_431 , V_138 V_334 )
{
struct V_273 * V_4 = V_220 -> V_273 ;
struct V_302 * V_303 , * V_432 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
V_138 V_307 , V_308 ;
int V_26 = 0 , V_281 ;
V_307 = V_334 / V_292 ;
V_303 = & V_4 -> V_3 . V_293 [ V_307 ] ;
V_281 = V_27 ( V_4 -> V_3 . V_295 - V_307 , V_1 -> V_20 ) ;
V_308 = V_334 % V_292 ;
V_212 -> V_205 = V_62 ;
V_212 -> V_203 = ( V_204 ) & V_220 -> V_210 ;
F_193 (sg_start, tmp_sg, sg_nents, i) {
F_9 ( L_114
L_115 ,
( unsigned long long ) V_432 -> V_433 ,
V_432 -> V_73 , V_308 ) ;
V_62 -> V_72 = F_194 ( V_16 , V_432 ) + V_308 ;
V_62 -> V_73 = F_34 ( V_138 , V_431 ,
F_195 ( V_16 , V_432 ) - V_308 ) ;
V_62 -> V_74 = V_24 -> V_57 -> V_75 ;
F_9 ( L_116 ,
V_62 -> V_72 , V_62 -> V_73 , V_62 -> V_74 ) ;
V_308 = 0 ;
V_431 -= V_62 -> V_73 ;
if ( ! V_431 )
break;
V_62 ++ ;
F_9 ( L_117 , V_62 ) ;
}
V_212 -> V_206 = ++ V_26 ;
F_9 ( L_118 ,
V_212 -> V_205 , V_212 -> V_206 ) ;
return V_212 -> V_206 ;
}
static int
V_99 ( struct V_230 * V_2 , struct V_273 * V_4 ,
struct V_342 * V_343 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_337 * V_271 = & V_343 -> V_271 ;
struct V_211 * V_212 ;
struct V_62 * V_62 ;
V_138 V_334 , V_284 , V_431 , V_434 , V_435 = 0 ;
int V_19 = 0 , V_26 , V_436 ;
V_220 -> V_210 . V_220 = V_220 ;
V_334 = V_343 -> V_226 == V_391 ? V_4 -> V_296 : 0 ;
V_19 = F_144 ( V_1 , V_220 , V_3 -> V_293 ,
V_3 -> V_295 , V_3 -> V_288 ,
V_334 , V_343 -> V_226 , & V_343 -> V_271 ) ;
if ( V_19 )
return V_19 ;
V_431 = V_271 -> V_340 ;
V_334 = V_271 -> V_334 ;
V_62 = F_24 ( sizeof( struct V_62 ) * V_271 -> V_333 , V_67 ) ;
if ( ! V_62 ) {
F_6 ( L_119 ) ;
V_19 = - V_76 ;
goto V_437;
}
V_343 -> V_62 = V_62 ;
V_343 -> V_382 = F_119 ( V_271 -> V_333 , V_1 -> V_20 ) ;
V_343 -> V_212 = F_24 ( sizeof( struct V_211 ) * V_343 -> V_382 ,
V_67 ) ;
if ( ! V_343 -> V_212 ) {
F_9 ( L_120 ) ;
V_19 = - V_76 ;
goto V_437;
}
V_343 -> V_220 = V_220 ;
V_434 = V_1 -> V_20 * V_292 ;
for ( V_26 = 0 ; V_26 < V_343 -> V_382 ; V_26 ++ ) {
V_212 = & V_220 -> V_225 . V_212 [ V_26 ] ;
V_284 = V_27 ( V_431 , V_434 ) ;
V_212 -> V_218 = 0 ;
if ( V_343 -> V_226 == V_339 ) {
V_212 -> V_216 = V_438 ;
V_212 -> V_343 . V_439 . V_440 = V_220 -> V_315 + V_334 ;
V_212 -> V_343 . V_439 . V_441 = V_220 -> V_314 ;
if ( V_26 + 1 == V_343 -> V_382 )
V_212 -> V_207 = & V_220 -> V_210 . V_212 ;
else
V_212 -> V_207 = & V_343 -> V_212 [ V_26 + 1 ] ;
} else {
V_212 -> V_216 = V_442 ;
V_212 -> V_343 . V_439 . V_440 = V_220 -> V_317 + V_435 ;
V_212 -> V_343 . V_439 . V_441 = V_220 -> V_316 ;
if ( V_26 + 1 == V_343 -> V_382 )
V_212 -> V_218 = V_219 ;
else
V_212 -> V_207 = & V_343 -> V_212 [ V_26 + 1 ] ;
}
V_436 = F_192 ( V_1 , V_220 , V_62 ,
V_212 , V_284 , V_334 ) ;
V_62 += V_436 ;
V_334 += V_284 ;
V_435 += V_284 ;
V_431 -= V_284 ;
}
return 0 ;
V_437:
F_147 ( V_1 , V_271 ) ;
return V_19 ;
}
static int
F_196 ( struct V_15 * V_16 ,
struct V_302 * V_303 , int V_281 , T_1 * V_443 )
{
T_1 V_444 , V_445 , V_446 , V_447 = 0 ;
struct V_302 * V_432 ;
int V_26 = 0 , V_448 , V_449 , V_450 ;
V_450 = 0 ;
V_448 = 1 ;
V_449 = V_281 - 1 ;
F_193 (sg_start, tmp_sg, sg_nents, i) {
V_444 = F_194 ( V_16 , V_432 ) ;
if ( V_448 )
V_447 = V_444 ;
V_445 = V_444 + F_195 ( V_16 , V_432 ) ;
F_9 ( L_121 ,
V_26 , ( unsigned long long ) V_432 -> V_433 ,
V_432 -> V_73 ) ;
if ( ( V_445 & ~ V_451 ) && V_26 < V_449 ) {
V_448 = 0 ;
continue;
}
V_448 = 1 ;
V_446 = V_447 & V_451 ;
do {
V_443 [ V_450 ++ ] = V_446 ;
F_9 ( L_122 ,
V_450 - 1 , V_446 ) ;
V_446 += V_292 ;
} while ( V_446 < V_445 );
}
return V_450 ;
}
static inline void
F_197 ( struct V_211 * V_452 , struct V_358 * V_453 )
{
V_138 V_441 ;
memset ( V_452 , 0 , sizeof( * V_452 ) ) ;
V_452 -> V_203 = V_402 ;
V_452 -> V_216 = V_454 ;
V_452 -> V_455 . V_456 = V_453 -> V_441 ;
V_441 = F_198 ( V_453 -> V_441 ) ;
F_199 ( V_453 , V_441 ) ;
}
static int
F_200 ( struct V_1 * V_1 ,
struct V_105 * V_106 ,
struct V_337 * V_457 ,
enum V_458 V_124 ,
struct V_62 * V_229 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_358 * V_453 ;
struct V_459 * V_460 ;
struct V_211 V_461 , V_452 ;
struct V_211 * V_462 , * V_343 = NULL ;
int V_19 , V_463 ;
V_138 V_308 ;
if ( V_457 -> V_341 == 1 ) {
V_229 -> V_74 = V_24 -> V_57 -> V_75 ;
V_229 -> V_72 = F_194 ( V_16 , & V_457 -> V_294 [ 0 ] ) ;
V_229 -> V_73 = F_195 ( V_16 , & V_457 -> V_294 [ 0 ] ) ;
F_9 ( L_123 ,
V_229 -> V_72 , V_229 -> V_73 , V_229 -> V_74 ) ;
return 0 ;
}
if ( V_124 == V_131 ) {
V_453 = V_106 -> V_111 ;
V_460 = V_106 -> V_110 ;
} else {
V_453 = V_106 -> V_112 -> V_114 ;
V_460 = V_106 -> V_112 -> V_113 ;
}
V_308 = V_457 -> V_334 % V_292 ;
F_9 ( L_124 ,
V_106 , V_457 -> V_333 , V_457 -> V_334 ) ;
V_463 = F_196 ( V_16 , V_457 -> V_294 , V_457 -> V_333 ,
& V_460 -> V_464 [ 0 ] ) ;
if ( ! ( V_106 -> V_124 & V_124 ) ) {
F_197 ( & V_452 , V_453 ) ;
V_343 = & V_452 ;
}
memset ( & V_461 , 0 , sizeof( V_461 ) ) ;
V_461 . V_203 = V_402 ;
V_461 . V_216 = V_465 ;
V_461 . V_343 . V_466 . V_467 = V_460 -> V_464 [ 0 ] + V_308 ;
V_461 . V_343 . V_466 . V_464 = V_460 ;
V_461 . V_343 . V_466 . V_468 = V_463 ;
V_461 . V_343 . V_466 . V_469 = V_470 ;
V_461 . V_343 . V_466 . V_73 = V_457 -> V_340 ;
V_461 . V_343 . V_466 . V_441 = V_453 -> V_441 ;
V_461 . V_343 . V_466 . V_471 = V_472 ;
if ( ! V_343 )
V_343 = & V_461 ;
else
V_343 -> V_207 = & V_461 ;
V_19 = F_102 ( V_1 -> V_58 , V_343 , & V_462 ) ;
if ( V_19 ) {
F_3 ( L_125 , V_19 ) ;
return V_19 ;
}
V_106 -> V_124 &= ~ V_124 ;
V_229 -> V_74 = V_453 -> V_74 ;
V_229 -> V_72 = V_460 -> V_464 [ 0 ] + V_308 ;
V_229 -> V_73 = V_457 -> V_340 ;
F_9 ( L_123 ,
V_229 -> V_72 , V_229 -> V_73 , V_229 -> V_74 ) ;
return V_19 ;
}
static inline void
F_201 ( struct V_3 * V_3 , struct V_473 * V_474 ,
struct V_475 * V_476 )
{
V_476 -> V_477 = V_478 ;
V_476 -> V_479 . V_480 . V_481 = V_482 ;
V_476 -> V_479 . V_480 . V_483 = V_3 -> V_366 -> V_367 . V_365 ;
V_476 -> V_479 . V_480 . V_484 = V_3 -> V_485 ;
V_476 -> V_479 . V_480 . V_486 = 0xffff ;
V_476 -> V_479 . V_480 . V_487 = true ;
V_476 -> V_479 . V_480 . V_488 = true ;
if ( V_3 -> V_489 == V_490 ||
V_3 -> V_489 == V_491 )
V_476 -> V_479 . V_480 . V_492 = true ;
}
static int
F_202 ( struct V_3 * V_3 , struct V_473 * V_474 )
{
switch ( V_3 -> V_6 ) {
case V_493 :
case V_494 :
V_474 -> V_457 . V_477 = V_495 ;
F_201 ( V_3 , V_474 , & V_474 -> V_496 ) ;
break;
case V_497 :
case V_498 :
V_474 -> V_496 . V_477 = V_495 ;
F_201 ( V_3 , V_474 , & V_474 -> V_457 ) ;
break;
case V_499 :
case V_500 :
F_201 ( V_3 , V_474 , & V_474 -> V_496 ) ;
F_201 ( V_3 , V_474 , & V_474 -> V_457 ) ;
break;
default:
F_3 ( L_126 , V_3 -> V_6 ) ;
return - V_318 ;
}
return 0 ;
}
static inline V_172
F_203 ( V_172 V_501 )
{
return ( V_501 & V_502 ? 0xc0 : 0 ) |
( V_501 & V_503 ? 0x30 : 0 ) |
( V_501 & V_503 ? 0x0f : 0 ) ;
}
static int
F_204 ( struct V_1 * V_1 ,
struct V_3 * V_3 ,
struct V_342 * V_225 ,
struct V_105 * V_106 )
{
struct V_211 V_504 , V_452 ;
struct V_211 * V_462 , * V_343 = NULL ;
struct V_119 * V_112 = V_106 -> V_112 ;
struct V_473 V_474 ;
int V_19 ;
memset ( & V_474 , 0 , sizeof( V_474 ) ) ;
V_19 = F_202 ( V_3 , & V_474 ) ;
if ( V_19 )
goto V_59;
V_474 . V_505 = F_203 ( V_3 -> V_501 ) ;
if ( ! ( V_106 -> V_124 & V_128 ) ) {
F_197 ( & V_452 , V_112 -> V_115 ) ;
V_343 = & V_452 ;
}
memset ( & V_504 , 0 , sizeof( V_504 ) ) ;
V_504 . V_216 = V_506 ;
V_504 . V_203 = V_402 ;
V_504 . V_205 = & V_225 -> V_507 [ V_508 ] ;
V_504 . V_206 = 1 ;
V_504 . V_343 . V_509 . V_471 = V_472 ;
V_504 . V_343 . V_509 . V_474 = & V_474 ;
V_504 . V_343 . V_509 . V_115 = V_112 -> V_115 ;
if ( V_3 -> V_510 )
V_504 . V_343 . V_509 . V_344 = & V_225 -> V_507 [ V_511 ] ;
if ( ! V_343 )
V_343 = & V_504 ;
else
V_343 -> V_207 = & V_504 ;
V_19 = F_102 ( V_1 -> V_58 , V_343 , & V_462 ) ;
if ( V_19 ) {
F_3 ( L_125 , V_19 ) ;
goto V_59;
}
V_106 -> V_124 &= ~ V_128 ;
V_225 -> V_507 [ V_512 ] . V_74 = V_112 -> V_115 -> V_74 ;
V_225 -> V_507 [ V_512 ] . V_72 = 0 ;
V_225 -> V_507 [ V_512 ] . V_73 = V_3 -> V_288 ;
if ( V_3 -> V_6 != V_498 &&
V_3 -> V_6 != V_497 )
V_225 -> V_507 [ V_512 ] . V_73 += V_3 -> V_513 ;
F_9 ( L_127 ,
V_225 -> V_507 [ V_512 ] . V_72 , V_225 -> V_507 [ V_512 ] . V_73 ,
V_225 -> V_507 [ V_512 ] . V_74 ) ;
V_59:
return V_19 ;
}
static int
F_205 ( struct V_1 * V_1 ,
struct V_220 * V_220 ,
struct V_342 * V_343 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_3 * V_3 = & V_220 -> V_273 -> V_3 ;
int V_19 ;
if ( ! V_343 -> V_106 -> V_112 ) {
V_19 = F_55 ( V_343 -> V_106 ,
V_24 -> V_15 ,
V_24 -> V_57 ) ;
if ( V_19 ) {
F_3 ( L_128 ,
V_1 ) ;
return V_19 ;
}
}
if ( V_3 -> V_510 ) {
V_19 = F_144 ( V_1 , V_220 ,
V_3 -> V_510 ,
V_3 -> V_514 ,
V_3 -> V_513 ,
0 , V_343 -> V_226 , & V_343 -> V_344 ) ;
if ( V_19 ) {
F_3 ( L_129 ,
V_1 ) ;
return V_19 ;
}
memset ( & V_343 -> V_507 [ V_511 ] , 0 , sizeof( V_343 -> V_507 [ V_511 ] ) ) ;
V_19 = F_200 ( V_1 , V_343 -> V_106 , & V_343 -> V_344 ,
V_125 , & V_343 -> V_507 [ V_511 ] ) ;
if ( V_19 ) {
F_3 ( L_130 ,
V_1 ) ;
goto V_515;
}
}
V_19 = F_204 ( V_1 , V_3 , V_343 , V_343 -> V_106 ) ;
if ( V_19 ) {
F_3 ( L_130 ,
V_1 ) ;
goto V_515;
}
V_343 -> V_106 -> V_124 |= V_129 ;
return 0 ;
V_515:
if ( V_3 -> V_510 )
F_147 ( V_1 , & V_343 -> V_344 ) ;
return V_19 ;
}
static int
V_96 ( struct V_230 * V_2 , struct V_273 * V_4 ,
struct V_342 * V_343 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_105 * V_106 = NULL ;
struct V_211 * V_212 ;
struct V_62 * V_507 ;
V_138 V_334 ;
int V_19 = 0 ;
unsigned long V_223 ;
V_220 -> V_210 . V_220 = V_220 ;
V_334 = V_343 -> V_226 == V_391 ? V_4 -> V_296 : 0 ;
V_19 = F_144 ( V_1 , V_220 , V_3 -> V_293 ,
V_3 -> V_295 , V_3 -> V_288 ,
V_334 , V_343 -> V_226 , & V_343 -> V_271 ) ;
if ( V_19 )
return V_19 ;
if ( V_343 -> V_271 . V_341 != 1 || F_1 ( V_1 , V_3 ) ) {
F_206 ( & V_1 -> V_150 , V_223 ) ;
V_106 = F_207 ( & V_1 -> V_108 ,
struct V_105 , V_109 ) ;
F_45 ( & V_106 -> V_109 ) ;
F_208 ( & V_1 -> V_150 , V_223 ) ;
V_343 -> V_106 = V_106 ;
}
V_19 = F_200 ( V_1 , V_106 , & V_343 -> V_271 ,
V_131 , & V_343 -> V_507 [ V_508 ] ) ;
if ( V_19 )
goto V_437;
if ( F_1 ( V_1 , V_3 ) ) {
V_19 = F_205 ( V_1 , V_220 , V_343 ) ;
if ( V_19 )
goto V_437;
V_507 = & V_343 -> V_507 [ V_512 ] ;
} else {
V_507 = & V_343 -> V_507 [ V_508 ] ;
}
memcpy ( & V_343 -> V_516 , V_507 , sizeof( * V_507 ) ) ;
V_343 -> V_62 = & V_343 -> V_516 ;
V_343 -> V_382 = 1 ;
memset ( & V_343 -> V_517 , 0 , sizeof( * V_212 ) ) ;
V_343 -> V_212 = & V_343 -> V_517 ;
V_343 -> V_220 = V_220 ;
V_212 = & V_220 -> V_225 . V_517 ;
V_212 -> V_205 = & V_343 -> V_516 ;
V_212 -> V_206 = 1 ;
V_212 -> V_203 = ( V_204 ) & V_220 -> V_210 ;
if ( V_343 -> V_226 == V_339 ) {
V_212 -> V_216 = V_438 ;
V_212 -> V_343 . V_439 . V_440 = V_220 -> V_315 ;
V_212 -> V_343 . V_439 . V_441 = V_220 -> V_314 ;
V_212 -> V_218 = ! F_1 ( V_1 , V_3 ) ?
0 : V_219 ;
} else {
V_212 -> V_216 = V_442 ;
V_212 -> V_343 . V_439 . V_440 = V_220 -> V_317 ;
V_212 -> V_343 . V_439 . V_441 = V_220 -> V_316 ;
V_212 -> V_218 = V_219 ;
}
return 0 ;
V_437:
if ( V_106 ) {
F_206 ( & V_1 -> V_150 , V_223 ) ;
F_49 ( & V_106 -> V_109 , & V_1 -> V_108 ) ;
F_208 ( & V_1 -> V_150 , V_223 ) ;
}
F_147 ( V_1 , & V_343 -> V_271 ) ;
return V_19 ;
}
static int
F_209 ( struct V_230 * V_2 , struct V_273 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_342 * V_343 = & V_220 -> V_225 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_211 * V_408 ;
int V_282 ;
F_9 ( L_131 ,
V_220 , V_3 -> V_288 ) ;
V_343 -> V_226 = V_339 ;
V_282 = V_24 -> V_95 ( V_2 , V_4 , V_343 ) ;
if ( V_282 ) {
F_3 ( L_132 , V_220 ) ;
return V_282 ;
}
if ( ! F_1 ( V_1 , V_3 ) ) {
F_103 ( V_1 , V_220 ,
& V_220 -> V_210 ) ;
F_177 ( V_4 , V_2 , true , (struct V_409 * )
& V_220 -> V_210 . V_234 ) ;
F_105 ( V_1 , & V_220 -> V_210 ) ;
F_106 ( V_1 , V_220 ,
& V_220 -> V_210 . V_212 ) ;
V_220 -> V_225 . V_517 . V_207 = & V_220 -> V_210 . V_212 ;
V_343 -> V_382 += 1 ;
V_282 = F_99 ( V_1 , V_220 -> V_61 ) ;
if ( V_282 ) {
F_3 ( L_71 , V_282 ) ;
return V_282 ;
}
}
V_282 = F_102 ( V_1 -> V_58 , V_343 -> V_212 , & V_408 ) ;
if ( V_282 )
F_6 ( L_133 ) ;
if ( ! F_1 ( V_1 , V_3 ) )
F_9 ( L_134
L_135 , V_220 ) ;
else
F_9 ( L_136 ,
V_220 ) ;
return 1 ;
}
static int
F_210 ( struct V_230 * V_2 , struct V_273 * V_4 , bool V_518 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_220 * V_220 = F_115 ( V_4 ) ;
struct V_342 * V_343 = & V_220 -> V_225 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_211 * V_408 ;
int V_282 ;
F_9 ( L_137 ,
V_220 , V_3 -> V_288 , V_4 -> V_296 ) ;
V_343 -> V_226 = V_391 ;
V_282 = V_24 -> V_95 ( V_2 , V_4 , V_343 ) ;
if ( V_282 ) {
F_3 ( L_132 , V_220 ) ;
return V_282 ;
}
V_282 = F_102 ( V_1 -> V_58 , V_343 -> V_212 , & V_408 ) ;
if ( V_282 )
F_6 ( L_138 ) ;
F_9 ( L_139 ,
V_220 ) ;
return 0 ;
}
static int
F_211 ( struct V_230 * V_2 , struct V_273 * V_4 , int V_142 )
{
struct V_220 * V_220 = F_115 ( V_4 ) ;
int V_19 = 0 ;
switch ( V_142 ) {
case V_519 :
F_69 ( & V_2 -> V_348 ) ;
F_93 ( & V_4 -> V_349 ) ;
F_70 ( & V_2 -> V_348 ) ;
F_149 ( V_220 , true ) ;
break;
case V_520 :
V_19 = F_182 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_140 , V_142 ) ;
V_19 = - V_318 ;
break;
}
return V_19 ;
}
static int
F_212 ( struct V_230 * V_2 , struct V_273 * V_4 , int V_142 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
switch ( V_142 ) {
case V_389 :
V_19 = F_184 ( V_4 , V_2 ) ;
if ( ! V_19 )
V_1 -> V_521 = true ;
break;
case V_522 :
V_19 = F_182 ( V_4 , V_2 , true ) ;
break;
case V_385 :
V_19 = F_186 ( V_4 , V_2 ) ;
break;
case V_386 :
V_19 = F_188 ( V_4 , V_2 ) ;
break;
case V_387 :
V_19 = F_190 ( V_4 , V_2 ) ;
break;
case V_523 :
V_19 = F_160 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_141 , V_142 ) ;
V_19 = - V_318 ;
break;
}
return V_19 ;
}
struct V_33 *
F_90 ( struct V_164 * V_164 )
{
struct V_165 * V_166 = V_164 -> V_166 ;
struct V_33 * V_524 ;
struct V_525 * V_526 ;
int V_19 ;
V_526 = (struct V_525 * ) & V_166 -> V_527 ;
F_9 ( L_142 , & V_166 -> V_527 , V_526 ) ;
V_524 = F_213 ( F_96 , V_164 ,
V_528 , V_53 ) ;
if ( F_20 ( V_524 ) ) {
F_3 ( L_143 , F_21 ( V_524 ) ) ;
V_19 = F_21 ( V_524 ) ;
goto V_169;
}
F_9 ( L_144 , V_524 , V_524 -> V_10 ) ;
V_19 = F_214 ( V_524 , V_526 ) ;
if ( V_19 ) {
F_3 ( L_145 , V_19 ) ;
goto V_529;
}
V_19 = F_215 ( V_524 , 0 ) ;
if ( V_19 ) {
F_3 ( L_146 , V_19 ) ;
goto V_529;
}
return V_524 ;
V_529:
F_76 ( V_524 ) ;
V_169:
return F_18 ( V_19 ) ;
}
static int
F_216 ( struct V_165 * V_166 ,
struct V_530 * V_531 )
{
struct V_164 * V_164 ;
struct V_33 * V_532 ;
int V_19 ;
V_164 = F_24 ( sizeof( struct V_164 ) , V_67 ) ;
if ( ! V_164 ) {
F_3 ( L_147 ) ;
return - V_76 ;
}
F_217 ( & V_164 -> V_180 , 0 ) ;
F_64 ( & V_164 -> V_149 ) ;
F_48 ( & V_164 -> V_176 ) ;
F_48 ( & V_164 -> V_179 ) ;
V_164 -> V_166 = V_166 ;
memcpy ( & V_166 -> V_527 , V_531 ,
sizeof( struct V_530 ) ) ;
V_532 = F_90 ( V_164 ) ;
if ( F_20 ( V_532 ) ) {
V_19 = F_21 ( V_532 ) ;
goto V_169;
}
V_164 -> V_13 = V_532 ;
V_166 -> V_533 = V_164 ;
return 0 ;
V_169:
F_28 ( V_164 ) ;
return V_19 ;
}
static int
F_73 ( struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_534 V_535 ;
int V_19 ;
memset ( & V_535 , 0 , sizeof( struct V_534 ) ) ;
V_535 . V_171 = V_1 -> V_171 ;
V_535 . V_536 = 7 ;
V_535 . V_537 = 7 ;
V_19 = F_218 ( V_13 , & V_535 ) ;
if ( V_19 ) {
F_3 ( L_148 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int
F_219 ( struct V_230 * V_2 , struct V_231 * V_232 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
F_13 ( L_149 , V_1 ) ;
V_19 = F_220 ( & V_1 -> V_146 ) ;
if ( V_19 ) {
F_3 ( L_150 ,
V_1 ) ;
return V_19 ;
}
F_221 ( & V_1 -> V_146 ) ;
if ( ! V_232 -> V_248 )
return 0 ;
F_108 ( V_1 ) ;
F_13 ( L_151 , V_2 ) ;
V_19 = F_220 ( & V_1 -> V_145 ) ;
if ( V_19 )
return V_19 ;
F_13 ( L_152 , V_232 -> V_267 ) ;
return 0 ;
}
static void
F_222 ( struct V_165 * V_166 , struct V_230 * V_2 ,
struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_538 * V_539 = & V_13 -> V_540 ;
V_2 -> V_541 = V_166 -> V_527 . V_542 ;
V_2 -> V_543 = V_539 -> V_72 . V_544 ;
V_2 -> V_545 = V_539 -> V_72 . V_546 ;
}
static int
F_223 ( struct V_165 * V_166 , struct V_230 * V_2 )
{
struct V_164 * V_164 = V_166 -> V_533 ;
struct V_1 * V_1 ;
int V_19 ;
V_547:
V_19 = F_224 ( & V_164 -> V_180 ) ;
if ( V_19 )
return - V_548 ;
F_69 ( & V_166 -> V_167 ) ;
if ( V_166 -> V_549 >= V_550 ) {
F_70 ( & V_166 -> V_167 ) ;
F_9 ( L_153 ,
V_166 -> V_549 ) ;
return - V_548 ;
}
F_70 ( & V_166 -> V_167 ) ;
F_11 ( & V_164 -> V_149 ) ;
if ( F_51 ( & V_164 -> V_179 ) ) {
F_12 ( & V_164 -> V_149 ) ;
goto V_547;
}
V_1 = F_207 ( & V_164 -> V_179 ,
struct V_1 , V_144 ) ;
F_93 ( & V_1 -> V_144 ) ;
F_12 ( & V_164 -> V_149 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
F_222 ( V_166 , V_2 , V_1 ) ;
F_9 ( L_154 , V_1 ) ;
return 0 ;
}
static void
F_225 ( struct V_165 * V_166 )
{
struct V_164 * V_164 = V_166 -> V_533 ;
struct V_1 * V_1 , * V_405 ;
if ( V_164 -> V_13 )
F_76 ( V_164 -> V_13 ) ;
F_11 ( & V_164 -> V_149 ) ;
if ( ! F_51 ( & V_164 -> V_179 ) ) {
F_13 ( L_155 ) ;
F_52 (isert_conn, n,
&isert_np->pending,
node) {
F_13 ( L_156 ,
V_1 , V_1 -> V_142 ) ;
F_74 ( V_1 ) ;
}
}
if ( ! F_51 ( & V_164 -> V_176 ) ) {
F_13 ( L_157 ) ;
F_52 (isert_conn, n,
&isert_np->accepted,
node) {
F_13 ( L_156 ,
V_1 , V_1 -> V_142 ) ;
F_74 ( V_1 ) ;
}
}
F_12 ( & V_164 -> V_149 ) ;
V_166 -> V_533 = NULL ;
F_28 ( V_164 ) ;
}
static void V_152 ( struct V_383 * V_77 )
{
struct V_1 * V_1 = F_83 ( V_77 ,
struct V_1 ,
V_151 ) ;
F_13 ( L_158 , V_1 ) ;
F_226 ( & V_1 -> V_147 ) ;
F_11 ( & V_1 -> V_149 ) ;
V_1 -> V_142 = V_551 ;
F_12 ( & V_1 -> V_149 ) ;
F_13 ( L_159 , V_1 ) ;
F_84 ( V_1 ) ;
}
static void
F_227 ( struct V_1 * V_1 )
{
struct V_230 * V_2 = V_1 -> V_2 ;
F_13 ( L_38 , V_1 ) ;
if ( V_1 -> V_521 ) {
F_13 ( L_160 , V_1 ) ;
F_228 ( & V_2 -> V_552 ,
V_553 * V_554 ) ;
}
}
static void
F_229 ( struct V_230 * V_2 )
{
F_13 ( L_161 , V_2 ) ;
if ( V_2 -> V_134 ) {
F_230 ( V_2 -> V_134 -> V_133 ) ;
F_231 ( V_2 -> V_134 -> V_133 ) ;
}
}
static void
F_232 ( struct V_1 * V_1 )
{
struct V_200 * V_462 ;
F_13 ( L_38 , V_1 ) ;
F_62 ( & V_1 -> V_396 ) ;
V_1 -> V_555 . V_203 = V_395 ;
if ( F_98 ( V_1 -> V_58 , & V_1 -> V_555 , & V_462 ) ) {
F_3 ( L_162 , V_1 ) ;
return;
}
F_226 ( & V_1 -> V_396 ) ;
}
static void
F_233 ( struct V_230 * V_2 )
{
struct V_273 * V_4 , * V_107 ;
static F_234 ( V_556 ) ;
F_69 ( & V_2 -> V_348 ) ;
F_52 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_298 & V_557 ) &&
( V_4 -> V_296 < V_2 -> V_134 -> V_241 -> V_558 ) &&
( V_4 -> V_296 < V_4 -> V_3 . V_288 ) )
F_80 ( & V_4 -> V_349 , & V_556 ) ;
}
F_70 ( & V_2 -> V_348 ) ;
F_52 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_93 ( & V_4 -> V_349 ) ;
if ( V_4 -> V_300 != V_519 ) {
struct V_220 * V_220 = F_115 ( V_4 ) ;
F_13 ( L_163 , V_2 , V_4 ) ;
F_149 ( V_220 , true ) ;
}
}
}
static void F_235 ( struct V_230 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_13 ( L_164 , V_1 ) ;
F_11 ( & V_1 -> V_149 ) ;
if ( V_1 -> V_142 == V_143 ) {
F_12 ( & V_1 -> V_149 ) ;
return;
}
F_86 ( V_1 ) ;
F_12 ( & V_1 -> V_149 ) ;
F_232 ( V_1 ) ;
F_233 ( V_2 ) ;
F_229 ( V_2 ) ;
F_227 ( V_1 ) ;
F_94 ( V_190 , & V_1 -> V_151 ) ;
}
static void F_236 ( struct V_230 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_232 ( V_1 ) ;
F_84 ( V_1 ) ;
}
static int T_4 F_237 ( void )
{
int V_19 ;
V_390 = F_238 ( L_165 ,
V_559 | V_560 , 0 ) ;
if ( ! V_390 ) {
F_3 ( L_166 ) ;
V_19 = - V_76 ;
return - V_76 ;
}
V_190 = F_238 ( L_167 , V_559 ,
V_561 ) ;
if ( ! V_190 ) {
F_3 ( L_168 ) ;
V_19 = - V_76 ;
goto V_562;
}
F_239 ( & V_563 ) ;
F_13 ( L_169 ) ;
return 0 ;
V_562:
F_240 ( V_390 ) ;
return V_19 ;
}
static void T_5 F_241 ( void )
{
F_242 () ;
F_240 ( V_190 ) ;
F_240 ( V_390 ) ;
F_243 ( & V_563 ) ;
F_13 ( L_170 ) ;
}
