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
V_63 -> V_74 = V_24 -> V_75 -> V_74 ;
}
V_1 -> V_76 = 0 ;
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
return - V_77 ;
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
F_31 ( & V_25 -> V_78 ) ;
F_32 ( V_25 -> V_40 ) ;
}
}
F_28 ( V_24 -> V_30 ) ;
}
static int
F_33 ( struct V_23 * V_24 ,
struct V_17 * V_36 )
{
int V_26 , V_79 , V_19 = 0 ;
V_24 -> V_29 = V_27 ( V_80 , F_34 ( int , F_35 () ,
V_24 -> V_15 -> V_81 ) ) ;
F_13 ( L_10
L_11 ,
V_24 -> V_29 , V_24 -> V_15 -> V_82 ,
V_24 -> V_15 -> V_81 , V_24 -> V_83 ,
V_24 -> V_54 ) ;
V_24 -> V_30 = F_36 ( V_24 -> V_29 , sizeof( struct V_22 ) ,
V_67 ) ;
if ( ! V_24 -> V_30 ) {
F_3 ( L_12 ) ;
return - V_77 ;
}
V_79 = V_27 ( V_84 , V_36 -> V_79 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ ) {
struct V_85 V_86 = {} ;
struct V_22 * V_25 = & V_24 -> V_30 [ V_26 ] ;
V_25 -> V_24 = V_24 ;
F_37 ( & V_25 -> V_78 , V_87 ) ;
V_86 . V_88 = V_79 ;
V_86 . V_89 = V_26 ;
V_25 -> V_40 = F_38 ( V_24 -> V_15 ,
V_90 ,
F_22 ,
( void * ) V_25 ,
& V_86 ) ;
if ( F_20 ( V_25 -> V_40 ) ) {
F_3 ( L_13 ) ;
V_19 = F_21 ( V_25 -> V_40 ) ;
V_25 -> V_40 = NULL ;
goto V_91;
}
V_19 = F_39 ( V_25 -> V_40 , V_92 ) ;
if ( V_19 )
goto V_91;
}
return 0 ;
V_91:
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
if ( V_48 -> V_93 & V_94 &&
V_48 -> V_93 & V_95 ) {
V_24 -> V_83 = 1 ;
V_24 -> V_96 = V_97 ;
V_24 -> V_98 = V_99 ;
} else {
V_24 -> V_83 = 0 ;
V_24 -> V_96 = V_100 ;
V_24 -> V_98 = V_101 ;
}
V_19 = F_33 ( V_24 , V_48 ) ;
if ( V_19 )
return V_19 ;
V_24 -> V_57 = F_41 ( V_24 -> V_15 ) ;
if ( F_20 ( V_24 -> V_57 ) ) {
V_19 = F_21 ( V_24 -> V_57 ) ;
F_3 ( L_14 ,
V_24 , V_19 ) ;
goto V_91;
}
V_24 -> V_75 = F_42 ( V_24 -> V_57 , V_102 ) ;
if ( F_20 ( V_24 -> V_75 ) ) {
V_19 = F_21 ( V_24 -> V_75 ) ;
F_3 ( L_15 ,
V_24 , V_19 ) ;
goto V_103;
}
V_24 -> V_54 = V_48 -> V_93 &
V_95 ? true : false ;
return 0 ;
V_103:
F_43 ( V_24 -> V_57 ) ;
V_91:
F_30 ( V_24 ) ;
return V_19 ;
}
static void
F_44 ( struct V_23 * V_24 )
{
F_13 ( L_16 , V_24 ) ;
F_45 ( V_24 -> V_75 ) ;
F_43 ( V_24 -> V_57 ) ;
F_30 ( V_24 ) ;
}
static void
F_46 ( struct V_23 * V_24 )
{
F_11 ( & V_28 ) ;
V_24 -> V_104 -- ;
F_13 ( L_17 , V_24 , V_24 -> V_104 ) ;
if ( ! V_24 -> V_104 ) {
F_44 ( V_24 ) ;
F_47 ( & V_24 -> V_105 ) ;
F_28 ( V_24 ) ;
}
F_12 ( & V_28 ) ;
}
static struct V_23 *
F_48 ( struct V_33 * V_34 )
{
struct V_23 * V_24 ;
int V_19 ;
F_11 ( & V_28 ) ;
F_49 (device, &device_list, dev_node) {
if ( V_24 -> V_15 -> V_106 == V_34 -> V_24 -> V_106 ) {
V_24 -> V_104 ++ ;
F_13 ( L_18 ,
V_24 , V_24 -> V_104 ) ;
F_12 ( & V_28 ) ;
return V_24 ;
}
}
V_24 = F_24 ( sizeof( struct V_23 ) , V_67 ) ;
if ( ! V_24 ) {
F_12 ( & V_28 ) ;
return F_18 ( - V_77 ) ;
}
F_50 ( & V_24 -> V_105 ) ;
V_24 -> V_15 = V_34 -> V_24 ;
V_19 = F_40 ( V_24 ) ;
if ( V_19 ) {
F_28 ( V_24 ) ;
F_12 ( & V_28 ) ;
return F_18 ( V_19 ) ;
}
V_24 -> V_104 ++ ;
F_51 ( & V_24 -> V_105 , & V_107 ) ;
F_13 ( L_19 ,
V_24 , V_24 -> V_104 ) ;
F_12 ( & V_28 ) ;
return V_24 ;
}
static void
F_52 ( struct V_1 * V_1 )
{
struct V_108 * V_109 , * V_110 ;
int V_26 = 0 ;
if ( F_53 ( & V_1 -> V_111 ) )
return;
F_13 ( L_20 , V_1 ) ;
F_54 (fr_desc, tmp,
&isert_conn->fr_pool, list) {
F_47 ( & V_109 -> V_112 ) ;
F_55 ( V_109 -> V_113 ) ;
F_45 ( V_109 -> V_114 ) ;
if ( V_109 -> V_115 ) {
F_55 ( V_109 -> V_115 -> V_116 ) ;
F_45 ( V_109 -> V_115 -> V_117 ) ;
F_56 ( V_109 -> V_115 -> V_118 ) ;
F_28 ( V_109 -> V_115 ) ;
}
F_28 ( V_109 ) ;
++ V_26 ;
}
if ( V_26 < V_1 -> V_119 )
F_6 ( L_21 ,
V_1 -> V_119 - V_26 ) ;
}
static int
F_57 ( struct V_108 * V_120 ,
struct V_15 * V_24 ,
struct V_121 * V_57 )
{
struct V_122 V_123 ;
struct V_124 * V_115 ;
int V_19 ;
V_115 = F_24 ( sizeof( * V_120 -> V_115 ) , V_67 ) ;
if ( ! V_115 ) {
F_3 ( L_22 ) ;
return - V_77 ;
}
V_115 -> V_116 = F_58 ( V_24 ,
V_125 ) ;
if ( F_20 ( V_115 -> V_116 ) ) {
F_3 ( L_23 ,
F_21 ( V_115 -> V_116 ) ) ;
V_19 = F_21 ( V_115 -> V_116 ) ;
goto V_126;
}
V_115 -> V_117 = F_59 ( V_57 , V_125 ) ;
if ( F_20 ( V_115 -> V_117 ) ) {
F_3 ( L_24 ,
F_21 ( V_115 -> V_117 ) ) ;
V_19 = F_21 ( V_115 -> V_117 ) ;
goto V_127;
}
V_120 -> V_128 |= V_129 ;
memset ( & V_123 , 0 , sizeof( V_123 ) ) ;
V_123 . V_130 = 2 ;
V_123 . V_131 |= V_132 ;
V_115 -> V_118 = F_60 ( V_57 , & V_123 ) ;
if ( F_20 ( V_115 -> V_118 ) ) {
F_3 ( L_25 ,
F_21 ( V_115 -> V_118 ) ) ;
V_19 = F_21 ( V_115 -> V_118 ) ;
goto V_133;
}
V_120 -> V_115 = V_115 ;
V_120 -> V_128 |= V_134 ;
V_120 -> V_128 &= ~ V_135 ;
return 0 ;
V_133:
F_45 ( V_115 -> V_117 ) ;
V_127:
F_55 ( V_115 -> V_116 ) ;
V_126:
F_28 ( V_115 ) ;
return V_19 ;
}
static int
F_61 ( struct V_15 * V_15 , struct V_121 * V_57 ,
struct V_108 * V_109 )
{
int V_19 ;
V_109 -> V_113 = F_58 ( V_15 ,
V_125 ) ;
if ( F_20 ( V_109 -> V_113 ) ) {
F_3 ( L_26 ,
F_21 ( V_109 -> V_113 ) ) ;
return F_21 ( V_109 -> V_113 ) ;
}
V_109 -> V_114 = F_59 ( V_57 , V_125 ) ;
if ( F_20 ( V_109 -> V_114 ) ) {
F_3 ( L_27 ,
F_21 ( V_109 -> V_114 ) ) ;
V_19 = F_21 ( V_109 -> V_114 ) ;
goto V_136;
}
V_109 -> V_128 |= V_137 ;
F_9 ( L_28 , V_109 ) ;
return 0 ;
V_136:
F_55 ( V_109 -> V_113 ) ;
return V_19 ;
}
static int
F_62 ( struct V_1 * V_1 )
{
struct V_108 * V_109 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_138 * V_139 = V_1 -> V_2 -> V_140 -> V_139 ;
struct V_141 * V_142 = V_139 -> V_141 ;
int V_26 , V_19 , V_143 ;
V_143 = F_63 ( V_144 , V_145 , V_142 -> V_146 ) ;
V_143 = ( V_143 * 2 ) + V_147 ;
V_1 -> V_119 = 0 ;
for ( V_26 = 0 ; V_26 < V_143 ; V_26 ++ ) {
V_109 = F_24 ( sizeof( * V_109 ) , V_67 ) ;
if ( ! V_109 ) {
F_3 ( L_29 ) ;
V_19 = - V_77 ;
goto V_59;
}
V_19 = F_61 ( V_24 -> V_15 ,
V_24 -> V_57 , V_109 ) ;
if ( V_19 ) {
F_3 ( L_30 ,
V_19 ) ;
F_28 ( V_109 ) ;
goto V_59;
}
F_51 ( & V_109 -> V_112 , & V_1 -> V_111 ) ;
V_1 -> V_119 ++ ;
}
F_9 ( L_31 ,
V_1 , V_1 -> V_119 ) ;
return 0 ;
V_59:
F_52 ( V_1 ) ;
return V_19 ;
}
static void
F_64 ( struct V_1 * V_1 )
{
V_1 -> V_148 = V_149 ;
F_50 ( & V_1 -> V_150 ) ;
F_65 ( & V_1 -> V_151 ) ;
F_65 ( & V_1 -> V_152 ) ;
F_65 ( & V_1 -> V_153 ) ;
F_66 ( & V_1 -> V_154 ) ;
F_67 ( & V_1 -> V_155 ) ;
F_68 ( & V_1 -> V_156 ) ;
F_50 ( & V_1 -> V_111 ) ;
F_37 ( & V_1 -> V_157 , V_158 ) ;
}
static void
F_69 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_24 -> V_15 ;
F_27 ( V_16 , V_1 -> V_159 ,
V_160 , V_161 ) ;
F_27 ( V_16 , V_1 -> V_162 ,
V_163 ,
V_70 ) ;
F_28 ( V_1 -> V_164 ) ;
}
static int
F_70 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
int V_19 ;
V_1 -> V_164 = F_24 ( V_163 +
V_160 , V_67 ) ;
if ( ! V_1 -> V_164 ) {
F_3 ( L_32 ) ;
return - V_77 ;
}
V_1 -> V_165 = V_1 -> V_164 ;
V_1 -> V_166 = V_1 -> V_164 +
V_163 ;
F_9 ( L_33 ,
V_1 -> V_164 , V_1 -> V_165 ,
V_1 -> V_166 ) ;
V_1 -> V_162 = F_25 ( V_16 ,
( void * ) V_1 -> V_165 ,
V_163 , V_70 ) ;
V_19 = F_26 ( V_16 , V_1 -> V_162 ) ;
if ( V_19 ) {
F_3 ( L_34 , V_19 ) ;
V_1 -> V_162 = 0 ;
goto V_167;
}
V_1 -> V_159 = F_25 ( V_16 ,
( void * ) V_1 -> V_166 ,
V_160 , V_161 ) ;
V_19 = F_26 ( V_16 , V_1 -> V_159 ) ;
if ( V_19 ) {
F_3 ( L_35 , V_19 ) ;
V_1 -> V_159 = 0 ;
goto V_168;
}
return 0 ;
V_168:
F_27 ( V_16 , V_1 -> V_162 ,
V_163 , V_70 ) ;
V_167:
F_28 ( V_1 -> V_164 ) ;
return V_19 ;
}
static int
F_71 ( struct V_33 * V_34 , struct V_169 * V_11 )
{
struct V_170 * V_170 = V_34 -> V_10 ;
struct V_171 * V_172 = V_170 -> V_172 ;
struct V_1 * V_1 ;
struct V_23 * V_24 ;
int V_19 = 0 ;
F_72 ( & V_172 -> V_173 ) ;
if ( ! V_172 -> V_174 ) {
F_73 ( & V_172 -> V_173 ) ;
F_9 ( L_36 ) ;
return F_74 ( V_34 , NULL , 0 ) ;
}
F_73 ( & V_172 -> V_173 ) ;
F_9 ( L_37 ,
V_34 , V_34 -> V_10 ) ;
V_1 = F_24 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_1 )
return - V_77 ;
F_64 ( V_1 ) ;
V_1 -> V_13 = V_34 ;
V_19 = F_70 ( V_1 , V_34 -> V_24 ) ;
if ( V_19 )
goto V_175;
V_24 = F_48 ( V_34 ) ;
if ( F_20 ( V_24 ) ) {
V_19 = F_21 ( V_24 ) ;
goto V_176;
}
V_1 -> V_24 = V_24 ;
V_1 -> V_177 = F_34 ( V_178 ,
V_11 -> V_179 . V_2 . V_177 ,
V_24 -> V_48 . V_180 ) ;
F_9 ( L_38 , V_1 -> V_177 ) ;
V_19 = F_19 ( V_1 , V_34 ) ;
if ( V_19 )
goto V_181;
V_19 = F_75 ( V_1 ) ;
if ( V_19 )
goto V_181;
if ( ! F_76 ( & V_1 -> V_154 ) ) {
F_6 ( L_39 , V_1 ) ;
goto V_181;
}
V_19 = F_77 ( V_1 ) ;
if ( V_19 )
goto V_181;
F_11 ( & V_170 -> V_182 ) ;
F_51 ( & V_1 -> V_150 , & V_170 -> V_183 ) ;
F_12 ( & V_170 -> V_182 ) ;
F_13 ( L_40 , V_172 ) ;
F_78 ( & V_170 -> V_184 ) ;
return 0 ;
V_181:
F_46 ( V_24 ) ;
V_176:
F_69 ( V_1 ) ;
V_175:
F_28 ( V_1 ) ;
F_74 ( V_34 , NULL , 0 ) ;
return V_19 ;
}
static void
F_79 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
F_9 ( L_41 , V_1 ) ;
F_80 ( ! V_24 ) ;
if ( V_24 -> V_83 )
F_52 ( V_1 ) ;
F_29 ( V_1 ) ;
if ( V_1 -> V_13 )
F_81 ( V_1 -> V_13 ) ;
if ( V_1 -> V_58 ) {
struct V_22 * V_25 = V_1 -> V_58 -> V_41 -> V_185 ;
F_14 ( V_25 ) ;
F_82 ( V_1 -> V_58 ) ;
}
if ( V_1 -> V_164 )
F_69 ( V_1 ) ;
F_46 ( V_24 ) ;
F_28 ( V_1 ) ;
}
static void
F_83 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
F_13 ( L_41 , V_1 ) ;
F_11 ( & V_1 -> V_155 ) ;
if ( V_1 -> V_148 != V_186 )
V_1 -> V_148 = V_187 ;
F_12 ( & V_1 -> V_155 ) ;
}
static void
F_84 ( struct V_154 * V_154 )
{
struct V_1 * V_1 = F_85 ( V_154 ,
struct V_1 , V_154 ) ;
F_13 ( L_42 , V_1 , V_188 -> V_189 ,
V_188 -> V_190 ) ;
F_79 ( V_1 ) ;
}
static void
F_86 ( struct V_1 * V_1 )
{
F_87 ( & V_1 -> V_154 , F_84 ) ;
}
static void
F_88 ( struct V_1 * V_1 )
{
int V_59 ;
switch ( V_1 -> V_148 ) {
case V_191 :
break;
case V_187 :
case V_186 :
F_13 ( L_43 ,
V_1 , V_1 -> V_148 ) ;
V_1 -> V_148 = V_191 ;
V_59 = F_89 ( V_1 -> V_13 ) ;
if ( V_59 )
F_6 ( L_44 ,
V_1 ) ;
break;
default:
F_6 ( L_45 ,
V_1 , V_1 -> V_148 ) ;
}
}
static int
F_90 ( struct V_170 * V_170 ,
enum V_192 V_11 )
{
F_9 ( L_46 ,
F_91 ( V_11 ) , V_11 , V_170 ) ;
switch ( V_11 ) {
case V_193 :
V_170 -> V_194 = NULL ;
break;
case V_195 :
V_170 -> V_194 = F_92 ( V_170 ) ;
if ( F_20 ( V_170 -> V_194 ) ) {
F_3 ( L_47 ,
V_170 , F_21 ( V_170 -> V_194 ) ) ;
V_170 -> V_194 = NULL ;
}
break;
default:
F_3 ( L_48 ,
V_170 , V_11 ) ;
}
return - 1 ;
}
static int
F_93 ( struct V_33 * V_34 ,
enum V_192 V_11 )
{
struct V_170 * V_170 = V_34 -> V_10 ;
struct V_1 * V_1 ;
bool V_196 = false ;
if ( V_170 -> V_194 == V_34 )
return F_90 ( V_34 -> V_10 , V_11 ) ;
V_1 = V_34 -> V_58 -> V_38 ;
F_11 ( & V_1 -> V_155 ) ;
V_196 = ( V_1 -> V_148 == V_191 ) ;
F_88 ( V_1 ) ;
F_12 ( & V_1 -> V_155 ) ;
F_13 ( L_49 , V_1 ) ;
F_94 ( & V_1 -> V_153 ) ;
if ( V_196 )
goto V_175;
F_11 ( & V_170 -> V_182 ) ;
if ( ! F_53 ( & V_1 -> V_150 ) ) {
F_95 ( & V_1 -> V_150 ) ;
F_86 ( V_1 ) ;
F_96 ( V_197 , & V_1 -> V_157 ) ;
}
F_12 ( & V_170 -> V_182 ) ;
V_175:
return 0 ;
}
static int
F_97 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
V_1 -> V_13 = NULL ;
F_86 ( V_1 ) ;
return - 1 ;
}
static int
F_98 ( struct V_33 * V_34 , struct V_169 * V_11 )
{
int V_19 = 0 ;
F_13 ( L_50 ,
F_91 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_198 , V_34 , V_34 -> V_10 ) ;
switch ( V_11 -> V_11 ) {
case V_199 :
V_19 = F_71 ( V_34 , V_11 ) ;
if ( V_19 )
F_3 ( L_51 , V_19 ) ;
break;
case V_200 :
F_83 ( V_34 ) ;
break;
case V_195 :
case V_201 :
case V_193 :
case V_202 :
V_19 = F_93 ( V_34 , V_11 -> V_11 ) ;
break;
case V_203 :
case V_204 :
case V_205 :
V_19 = F_97 ( V_34 ) ;
break;
default:
F_3 ( L_52 , V_11 -> V_11 ) ;
break;
}
return V_19 ;
}
static int
F_99 ( struct V_1 * V_1 , V_144 V_206 )
{
struct V_207 * V_208 , * V_209 ;
int V_26 , V_19 ;
unsigned int V_210 = V_1 -> V_76 ;
struct V_60 * V_61 ;
for ( V_208 = V_1 -> V_208 , V_26 = 0 ; V_26 < V_206 ; V_26 ++ , V_208 ++ ) {
V_61 = & V_1 -> V_66 [ V_210 ] ;
V_208 -> V_211 = ( V_212 ) V_61 ;
V_208 -> V_213 = & V_61 -> V_63 ;
V_208 -> V_214 = 1 ;
V_208 -> V_215 = V_208 + 1 ;
V_210 = ( V_210 + 1 ) & ( V_46 - 1 ) ;
}
V_208 -- ;
V_208 -> V_215 = NULL ;
V_1 -> V_216 += V_206 ;
V_19 = F_100 ( V_1 -> V_58 , V_1 -> V_208 ,
& V_209 ) ;
if ( V_19 ) {
F_3 ( L_53 , V_19 ) ;
V_1 -> V_216 -= V_206 ;
} else {
F_9 ( L_54 , V_206 ) ;
V_1 -> V_76 = V_210 ;
}
return V_19 ;
}
static int
F_101 ( struct V_1 * V_1 , struct V_217 * V_218 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_219 V_220 , * V_221 ;
int V_19 ;
F_102 ( V_16 , V_218 -> V_64 ,
V_222 , V_161 ) ;
V_220 . V_215 = NULL ;
V_220 . V_211 = ( V_212 ) V_218 ;
V_220 . V_213 = V_218 -> V_223 ;
V_220 . V_214 = V_218 -> V_214 ;
V_220 . V_224 = V_225 ;
V_220 . V_226 = V_227 ;
V_19 = F_103 ( V_1 -> V_58 , & V_220 , & V_221 ) ;
if ( V_19 )
F_3 ( L_55 , V_19 ) ;
return V_19 ;
}
static void
F_104 ( struct V_1 * V_1 ,
struct V_228 * V_228 ,
struct V_217 * V_218 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
F_105 ( V_16 , V_218 -> V_64 ,
V_222 , V_161 ) ;
memset ( & V_218 -> V_229 , 0 , sizeof( struct V_230 ) ) ;
V_218 -> V_229 . V_131 = V_231 ;
V_218 -> V_214 = 1 ;
V_218 -> V_228 = V_228 ;
if ( V_218 -> V_223 [ 0 ] . V_74 != V_24 -> V_75 -> V_74 ) {
V_218 -> V_223 [ 0 ] . V_74 = V_24 -> V_75 -> V_74 ;
F_9 ( L_56 , V_218 ) ;
}
}
static int
F_106 ( struct V_1 * V_1 ,
struct V_217 * V_218 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
T_1 V_64 ;
V_64 = F_25 ( V_16 , ( void * ) V_218 ,
V_222 , V_161 ) ;
if ( F_26 ( V_16 , V_64 ) ) {
F_3 ( L_57 ) ;
return - V_77 ;
}
V_218 -> V_64 = V_64 ;
V_218 -> V_223 [ 0 ] . V_72 = V_218 -> V_64 ;
V_218 -> V_223 [ 0 ] . V_73 = V_222 ;
V_218 -> V_223 [ 0 ] . V_74 = V_24 -> V_75 -> V_74 ;
F_9 ( L_58 ,
V_218 -> V_223 [ 0 ] . V_72 , V_218 -> V_223 [ 0 ] . V_73 ,
V_218 -> V_223 [ 0 ] . V_74 ) ;
return 0 ;
}
static void
F_107 ( struct V_1 * V_1 , struct V_228 * V_228 ,
struct V_219 * V_220 )
{
struct V_217 * V_218 = & V_228 -> V_218 ;
V_228 -> V_232 . V_233 = V_234 ;
V_220 -> V_211 = ( V_212 ) & V_228 -> V_218 ;
V_220 -> V_224 = V_225 ;
V_220 -> V_213 = & V_218 -> V_223 [ 0 ] ;
V_220 -> V_214 = V_228 -> V_218 . V_214 ;
V_220 -> V_226 = V_227 ;
}
static int
F_75 ( struct V_1 * V_1 )
{
struct V_207 V_208 , * V_235 ;
struct V_62 V_236 ;
int V_19 ;
memset ( & V_236 , 0 , sizeof( struct V_62 ) ) ;
V_236 . V_72 = V_1 -> V_162 ;
V_236 . V_73 = V_160 ;
V_236 . V_74 = V_1 -> V_24 -> V_75 -> V_74 ;
F_9 ( L_59 ,
V_236 . V_72 , V_236 . V_73 , V_236 . V_74 ) ;
memset ( & V_208 , 0 , sizeof( struct V_207 ) ) ;
V_208 . V_211 = ( V_212 ) V_1 -> V_165 ;
V_208 . V_213 = & V_236 ;
V_208 . V_214 = 1 ;
V_1 -> V_216 ++ ;
V_19 = F_100 ( V_1 -> V_58 , & V_208 , & V_235 ) ;
if ( V_19 ) {
F_3 ( L_60 , V_19 ) ;
V_1 -> V_216 -- ;
}
return V_19 ;
}
static int
F_108 ( struct V_237 * V_2 , struct V_238 * V_239 ,
V_144 V_73 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_217 * V_218 = & V_1 -> V_240 ;
int V_19 ;
F_104 ( V_1 , NULL , V_218 ) ;
memcpy ( & V_218 -> V_241 , & V_239 -> V_242 [ 0 ] ,
sizeof( struct V_243 ) ) ;
F_106 ( V_1 , V_218 ) ;
if ( V_73 > 0 ) {
struct V_62 * V_244 = & V_218 -> V_223 [ 1 ] ;
F_105 ( V_16 , V_1 -> V_159 ,
V_73 , V_161 ) ;
memcpy ( V_1 -> V_166 , V_239 -> V_245 , V_73 ) ;
F_102 ( V_16 , V_1 -> V_159 ,
V_73 , V_161 ) ;
V_244 -> V_72 = V_1 -> V_159 ;
V_244 -> V_73 = V_73 ;
V_244 -> V_74 = V_1 -> V_24 -> V_75 -> V_74 ;
V_218 -> V_214 = 2 ;
}
if ( ! V_239 -> V_246 ) {
if ( V_239 -> V_247 ) {
if ( ! V_2 -> V_140 -> V_248 -> V_249 &&
V_1 -> V_24 -> V_83 ) {
V_19 = F_62 ( V_1 ) ;
if ( V_19 ) {
F_3 ( L_61
L_62 , V_1 ) ;
return V_19 ;
}
}
V_19 = F_23 ( V_1 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_99 ( V_1 , V_250 ) ;
if ( V_19 )
return V_19 ;
F_11 ( & V_1 -> V_155 ) ;
V_1 -> V_148 = V_186 ;
F_12 ( & V_1 -> V_155 ) ;
goto V_251;
}
V_19 = F_75 ( V_1 ) ;
if ( V_19 )
return V_19 ;
}
V_251:
V_19 = F_101 ( V_1 , V_218 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void
F_109 ( struct V_1 * V_1 )
{
struct V_60 * V_61 = ( void * ) V_1 -> V_165 ;
int V_252 = V_1 -> V_253 ;
struct V_237 * V_2 = V_1 -> V_2 ;
struct V_238 * V_239 = V_2 -> V_254 ;
int V_255 ;
F_13 ( L_41 , V_1 ) ;
F_110 ( ! V_239 ) ;
if ( V_239 -> V_256 ) {
struct V_257 * V_258 =
(struct V_257 * ) & V_61 -> V_241 ;
V_239 -> V_259 = ( ! V_258 -> V_260 ) ? 1 : 0 ;
V_239 -> V_261 =
( V_258 -> V_131 & V_262 )
>> 2 ;
V_239 -> V_263 = V_258 -> V_264 ;
V_239 -> V_265 = V_258 -> V_266 ;
memcpy ( V_239 -> V_267 , V_258 -> V_267 , 6 ) ;
V_239 -> V_268 = F_111 ( V_258 -> V_269 ) ;
V_239 -> V_270 = V_258 -> V_271 ;
V_239 -> V_272 = F_111 ( V_258 -> V_273 ) ;
V_239 -> V_274 = F_112 ( V_258 -> V_274 ) ;
V_239 -> V_260 = F_112 ( V_258 -> V_260 ) ;
}
memcpy ( & V_239 -> V_275 [ 0 ] , ( void * ) & V_61 -> V_241 , V_276 ) ;
V_255 = V_27 ( V_252 , V_277 ) ;
F_9 ( L_63
L_64 , V_255 , V_252 ,
V_277 ) ;
memcpy ( V_239 -> V_278 , & V_61 -> V_279 [ 0 ] , V_255 ) ;
if ( V_239 -> V_256 ) {
F_94 ( & V_1 -> V_151 ) ;
return;
}
F_113 ( & V_2 -> V_280 , 0 ) ;
}
static struct V_281
* F_114 ( struct V_237 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_228 * V_228 ;
struct V_281 * V_4 ;
V_4 = F_115 ( V_2 , V_282 ) ;
if ( ! V_4 ) {
F_3 ( L_65 ) ;
return NULL ;
}
V_228 = F_116 ( V_4 ) ;
V_228 -> V_2 = V_1 ;
V_228 -> V_281 = V_4 ;
return V_4 ;
}
static int
F_117 ( struct V_1 * V_1 ,
struct V_228 * V_228 , struct V_281 * V_4 ,
struct V_60 * V_61 , unsigned char * V_283 )
{
struct V_237 * V_2 = V_1 -> V_2 ;
struct V_284 * V_285 = (struct V_284 * ) V_283 ;
struct V_286 * V_287 ;
int V_288 , V_289 , V_290 , V_291 , V_292 ;
bool V_293 = false ;
V_292 = F_118 ( V_2 , V_4 , V_283 ) ;
if ( V_292 < 0 )
return V_292 ;
V_288 = V_4 -> V_294 ;
V_289 = V_4 -> V_295 ;
V_290 = V_4 -> V_296 ;
V_292 = F_119 ( V_2 , V_4 , V_285 ) ;
if ( V_292 < 0 ) {
return 0 ;
} else if ( V_292 > 0 ) {
V_293 = true ;
goto V_297;
}
if ( ! V_288 )
return 0 ;
V_287 = & V_4 -> V_3 . V_298 [ 0 ] ;
V_291 = F_16 ( 1UL , F_120 ( V_289 , V_299 ) ) ;
F_9 ( L_66 ,
V_287 , V_291 , & V_61 -> V_279 [ 0 ] , V_289 ) ;
F_121 ( V_287 , V_291 , & V_61 -> V_279 [ 0 ] , V_289 ) ;
V_4 -> V_300 += V_289 ;
if ( V_4 -> V_300 == V_4 -> V_3 . V_301 ) {
F_72 ( & V_4 -> V_302 ) ;
V_4 -> V_303 |= V_304 ;
V_4 -> V_305 = V_306 ;
F_73 ( & V_4 -> V_302 ) ;
}
V_297:
V_292 = F_122 ( V_2 , V_4 , V_283 , V_285 -> V_269 ) ;
if ( ! V_292 && V_293 == false && V_290 )
F_123 ( V_4 ) ;
else if ( V_293 && V_288 )
F_124 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_125 ( struct V_1 * V_1 ,
struct V_60 * V_61 , unsigned char * V_283 )
{
struct V_286 * V_307 ;
struct V_237 * V_2 = V_1 -> V_2 ;
struct V_281 * V_4 = NULL ;
struct V_308 * V_285 = (struct V_308 * ) V_283 ;
V_144 V_309 = F_126 ( V_285 -> V_310 ) ;
int V_292 , V_291 , V_311 , V_312 ;
V_292 = F_127 ( V_2 , V_283 , & V_4 ) ;
if ( V_292 < 0 )
return V_292 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_296 ) {
F_3 ( L_67 ) ;
F_128 () ;
return - 1 ;
}
F_9 ( L_68
L_69 ,
V_309 , V_4 -> V_300 ,
V_4 -> V_3 . V_301 ) ;
V_311 = V_4 -> V_300 / V_299 ;
V_307 = & V_4 -> V_3 . V_298 [ V_311 ] ;
V_291 = F_16 ( 1UL , F_120 ( V_309 , V_299 ) ) ;
V_312 = V_4 -> V_300 % V_299 ;
if ( V_312 ) {
F_3 ( L_70 ) ;
F_128 () ;
return - 1 ;
}
F_9 ( L_71
L_72 , V_307 , V_311 ,
V_291 , & V_61 -> V_279 [ 0 ] , V_309 ) ;
F_121 ( V_307 , V_291 , & V_61 -> V_279 [ 0 ] ,
V_309 ) ;
V_292 = F_129 ( V_4 , V_285 , false ) ;
if ( V_292 < 0 )
return V_292 ;
return 0 ;
}
static int
F_130 ( struct V_1 * V_1 , struct V_228 * V_228 ,
struct V_281 * V_4 , struct V_60 * V_61 ,
unsigned char * V_283 )
{
struct V_237 * V_2 = V_1 -> V_2 ;
struct V_313 * V_285 = (struct V_313 * ) V_283 ;
int V_292 ;
V_292 = F_131 ( V_2 , V_4 , V_285 ) ;
if ( V_292 < 0 )
return V_292 ;
return F_132 ( V_2 , V_4 , V_285 ) ;
}
static int
F_133 ( struct V_1 * V_1 , struct V_228 * V_228 ,
struct V_281 * V_4 , struct V_60 * V_61 ,
struct V_314 * V_285 )
{
struct V_237 * V_2 = V_1 -> V_2 ;
V_144 V_315 = F_126 ( V_285 -> V_310 ) ;
int V_292 ;
unsigned char * V_316 = NULL ;
V_292 = F_134 ( V_2 , V_4 , V_285 ) ;
if ( V_292 < 0 )
return V_292 ;
if ( V_315 ) {
V_316 = F_24 ( V_315 , V_67 ) ;
if ( ! V_316 ) {
F_3 ( L_73 ,
V_315 ) ;
return - V_77 ;
}
}
V_4 -> V_317 = V_316 ;
memcpy ( V_4 -> V_317 , & V_61 -> V_279 [ 0 ] , V_315 ) ;
return F_135 ( V_2 , V_4 , V_285 ) ;
}
static int
F_136 ( struct V_1 * V_1 , struct V_60 * V_61 ,
T_2 V_318 , T_3 V_319 ,
T_2 V_320 , T_3 V_321 )
{
struct V_243 * V_285 = & V_61 -> V_241 ;
struct V_237 * V_2 = V_1 -> V_2 ;
struct V_281 * V_4 ;
struct V_228 * V_228 ;
int V_19 = - V_322 ;
V_178 V_224 = ( V_285 -> V_224 & V_323 ) ;
if ( V_2 -> V_140 -> V_248 -> V_249 &&
( ! ( V_224 & V_324 ) || ! ( V_224 & V_325 ) ) ) {
F_3 ( L_74
L_75 , V_224 ) ;
return 0 ;
}
switch ( V_224 ) {
case V_326 :
V_4 = F_114 ( V_2 ) ;
if ( ! V_4 )
break;
V_228 = F_116 ( V_4 ) ;
V_228 -> V_318 = V_318 ;
V_228 -> V_319 = V_319 ;
V_228 -> V_320 = V_320 ;
V_228 -> V_321 = V_321 ;
V_19 = F_117 ( V_1 , V_228 , V_4 ,
V_61 , ( unsigned char * ) V_285 ) ;
break;
case V_327 :
V_4 = F_114 ( V_2 ) ;
if ( ! V_4 )
break;
V_228 = F_116 ( V_4 ) ;
V_19 = F_130 ( V_1 , V_228 , V_4 ,
V_61 , ( unsigned char * ) V_285 ) ;
break;
case V_328 :
V_19 = F_125 ( V_1 , V_61 ,
( unsigned char * ) V_285 ) ;
break;
case V_329 :
V_4 = F_114 ( V_2 ) ;
if ( ! V_4 )
break;
V_19 = F_137 ( V_2 , V_4 ,
( unsigned char * ) V_285 ) ;
break;
case V_325 :
V_4 = F_114 ( V_2 ) ;
if ( ! V_4 )
break;
V_19 = F_138 ( V_2 , V_4 , ( unsigned char * ) V_285 ) ;
break;
case V_324 :
if ( F_111 ( V_285 -> V_330 ) != 0xFFFFFFFF ) {
V_4 = F_139 ( V_2 , V_285 -> V_271 ) ;
if ( ! V_4 )
break;
} else {
V_4 = F_114 ( V_2 ) ;
if ( ! V_4 )
break;
}
V_228 = F_116 ( V_4 ) ;
V_19 = F_133 ( V_1 , V_228 , V_4 ,
V_61 , (struct V_314 * ) V_285 ) ;
break;
default:
F_3 ( L_76 , V_224 ) ;
F_128 () ;
break;
}
return V_19 ;
}
static void
F_140 ( struct V_60 * V_61 , struct V_1 * V_1 )
{
struct V_230 * V_230 = & V_61 -> V_229 ;
T_3 V_319 = 0 , V_321 = 0 ;
T_2 V_318 = 0 , V_320 = 0 ;
int V_292 ;
switch ( V_230 -> V_131 & 0xF0 ) {
case V_331 :
if ( V_230 -> V_131 & V_332 ) {
V_318 = F_111 ( V_230 -> V_318 ) ;
V_319 = F_141 ( V_230 -> V_319 ) ;
F_9 ( L_77 ,
V_318 , ( unsigned long long ) V_319 ) ;
}
if ( V_230 -> V_131 & V_333 ) {
V_320 = F_111 ( V_230 -> V_320 ) ;
V_321 = F_141 ( V_230 -> V_321 ) ;
F_9 ( L_78 ,
V_320 , ( unsigned long long ) V_321 ) ;
}
F_9 ( L_79 ) ;
break;
case V_334 :
F_3 ( L_80 ) ;
break;
default:
F_6 ( L_81 , V_230 -> V_131 ) ;
break;
}
V_292 = F_136 ( V_1 , V_61 ,
V_318 , V_319 , V_320 , V_321 ) ;
}
static void
F_142 ( struct V_60 * V_120 ,
struct V_1 * V_1 ,
V_144 V_335 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_243 * V_285 ;
T_1 V_336 ;
int V_252 , V_337 ;
if ( ( char * ) V_120 == V_1 -> V_165 ) {
V_336 = V_1 -> V_162 ;
V_252 = V_160 ;
F_9 ( L_82 ,
V_336 , V_252 ) ;
} else {
V_336 = V_120 -> V_64 ;
V_252 = V_69 ;
F_9 ( L_83 ,
V_336 , V_252 ) ;
}
F_105 ( V_16 , V_336 , V_252 , V_70 ) ;
V_285 = & V_120 -> V_241 ;
F_9 ( L_84 ,
V_285 -> V_224 , V_285 -> V_271 , V_285 -> V_131 ,
( int ) ( V_335 - V_222 ) ) ;
if ( ( char * ) V_120 == V_1 -> V_165 ) {
V_1 -> V_253 = V_335 - V_222 ;
if ( V_1 -> V_2 ) {
struct V_238 * V_239 = V_1 -> V_2 -> V_254 ;
if ( V_239 && ! V_239 -> V_256 )
F_109 ( V_1 ) ;
}
F_11 ( & V_1 -> V_155 ) ;
F_94 ( & V_1 -> V_152 ) ;
F_12 ( & V_1 -> V_155 ) ;
} else {
F_140 ( V_120 , V_1 ) ;
}
F_102 ( V_16 , V_336 , V_252 ,
V_70 ) ;
V_1 -> V_216 -- ;
F_9 ( L_85 ,
V_1 -> V_216 ) ;
if ( ( char * ) V_120 == V_1 -> V_165 )
return;
V_337 = V_1 -> V_216 ;
if ( V_337 + V_250 <= V_46 ) {
int V_59 , V_206 = V_27 ( V_46 - V_337 ,
V_250 ) ;
V_59 = F_99 ( V_1 , V_206 ) ;
if ( V_59 ) {
F_3 ( L_86 ,
V_206 , V_59 ) ;
}
}
}
static int
F_143 ( struct V_1 * V_1 , struct V_228 * V_228 ,
struct V_286 * V_287 , V_144 V_338 , V_144 V_73 , V_144 V_339 ,
enum V_340 V_341 , struct V_342 * V_279 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
V_279 -> V_343 = V_341 == V_344 ?
V_161 : V_70 ;
V_279 -> V_345 = V_73 - V_339 ;
V_279 -> V_339 = V_339 ;
V_279 -> V_311 = V_279 -> V_339 / V_299 ;
V_279 -> V_287 = & V_287 [ V_279 -> V_311 ] ;
V_279 -> V_338 = F_34 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_279 -> V_345 = F_34 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_279 -> V_346 = F_144 ( V_16 , V_279 -> V_287 , V_279 -> V_338 ,
V_279 -> V_343 ) ;
if ( F_145 ( ! V_279 -> V_346 ) ) {
F_3 ( L_87 , V_287 ) ;
return - V_322 ;
}
F_9 ( L_88 ,
V_228 , V_279 -> V_346 , V_279 -> V_287 , V_279 -> V_338 , V_279 -> V_345 ) ;
return 0 ;
}
static void
F_146 ( struct V_1 * V_1 , struct V_342 * V_279 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
F_147 ( V_16 , V_279 -> V_287 , V_279 -> V_338 , V_279 -> V_343 ) ;
memset ( V_279 , 0 , sizeof( * V_279 ) ) ;
}
static void
V_101 ( struct V_228 * V_228 , struct V_1 * V_1 )
{
struct V_347 * V_348 = & V_228 -> V_232 ;
F_9 ( L_89 , V_228 ) ;
if ( V_348 -> V_279 . V_287 ) {
F_9 ( L_90 , V_228 ) ;
F_146 ( V_1 , & V_348 -> V_279 ) ;
}
if ( V_348 -> V_220 ) {
F_9 ( L_91 , V_228 ) ;
F_28 ( V_348 -> V_220 ) ;
V_348 -> V_220 = NULL ;
}
if ( V_348 -> V_62 ) {
F_9 ( L_92 , V_228 ) ;
F_28 ( V_348 -> V_62 ) ;
V_348 -> V_62 = NULL ;
}
}
static void
V_99 ( struct V_228 * V_228 , struct V_1 * V_1 )
{
struct V_347 * V_348 = & V_228 -> V_232 ;
F_9 ( L_89 , V_228 ) ;
if ( V_348 -> V_109 ) {
F_9 ( L_93 , V_228 , V_348 -> V_109 ) ;
if ( V_348 -> V_109 -> V_128 & V_135 ) {
F_146 ( V_1 , & V_348 -> V_349 ) ;
V_348 -> V_109 -> V_128 &= ~ V_135 ;
}
F_72 ( & V_1 -> V_156 ) ;
F_51 ( & V_348 -> V_109 -> V_112 , & V_1 -> V_111 ) ;
F_73 ( & V_1 -> V_156 ) ;
V_348 -> V_109 = NULL ;
}
if ( V_348 -> V_279 . V_287 ) {
F_9 ( L_90 , V_228 ) ;
F_146 ( V_1 , & V_348 -> V_279 ) ;
}
V_348 -> V_62 = NULL ;
V_348 -> V_220 = NULL ;
}
static void
F_148 ( struct V_228 * V_228 , bool V_350 )
{
struct V_281 * V_4 = V_228 -> V_281 ;
struct V_1 * V_1 = V_228 -> V_2 ;
struct V_237 * V_2 = V_1 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_351 * V_285 ;
F_9 ( L_89 , V_228 ) ;
switch ( V_4 -> V_352 ) {
case V_326 :
F_72 ( & V_2 -> V_353 ) ;
if ( ! F_53 ( & V_4 -> V_354 ) )
F_95 ( & V_4 -> V_354 ) ;
F_73 ( & V_2 -> V_353 ) ;
if ( V_4 -> V_355 == V_161 ) {
F_149 ( V_4 ) ;
if ( V_350 &&
V_4 -> V_3 . V_356 == V_357 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_124 ( V_3 ) ;
}
}
V_24 -> V_98 ( V_228 , V_1 ) ;
F_150 ( & V_4 -> V_3 , 0 ) ;
break;
case V_329 :
F_72 ( & V_2 -> V_353 ) ;
if ( ! F_53 ( & V_4 -> V_354 ) )
F_95 ( & V_4 -> V_354 ) ;
F_73 ( & V_2 -> V_353 ) ;
F_150 ( & V_4 -> V_3 , 0 ) ;
break;
case V_358 :
case V_327 :
case V_324 :
V_285 = (struct V_351 * ) & V_228 -> V_218 . V_241 ;
if ( V_285 -> V_131 & V_359 )
break;
F_72 ( & V_2 -> V_353 ) ;
if ( ! F_53 ( & V_4 -> V_354 ) )
F_95 ( & V_4 -> V_354 ) ;
F_73 ( & V_2 -> V_353 ) ;
if ( V_4 -> V_3 . V_360 != NULL ) {
F_9 ( L_94 ,
V_4 -> V_352 ) ;
F_150 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_151 ( V_4 ) ;
break;
}
}
static void
F_152 ( struct V_217 * V_218 , struct V_15 * V_16 )
{
if ( V_218 -> V_64 != 0 ) {
F_9 ( L_95 ) ;
F_27 ( V_16 , V_218 -> V_64 ,
V_222 , V_161 ) ;
V_218 -> V_64 = 0 ;
}
}
static void
F_153 ( struct V_217 * V_218 , struct V_228 * V_228 ,
struct V_15 * V_16 , bool V_350 )
{
if ( V_228 -> V_361 != 0 ) {
F_9 ( L_96 ) ;
F_27 ( V_16 , V_228 -> V_361 ,
V_228 -> V_362 , V_161 ) ;
V_228 -> V_361 = 0 ;
}
F_152 ( V_218 , V_16 ) ;
F_148 ( V_228 , V_350 ) ;
}
static int
F_154 ( struct V_3 * V_3 , struct V_363 * V_118 )
{
struct V_364 V_365 ;
int V_19 ;
V_19 = F_155 ( V_118 , V_366 , & V_365 ) ;
if ( V_19 ) {
F_3 ( L_97 , V_19 ) ;
goto V_367;
}
if ( V_365 . V_368 & V_366 ) {
T_1 V_369 ;
V_144 V_370 = V_3 -> V_371 -> V_372 . V_370 + 8 ;
switch ( V_365 . V_373 . V_374 ) {
case V_375 :
V_3 -> V_376 = V_377 ;
break;
case V_378 :
V_3 -> V_376 = V_379 ;
break;
case V_380 :
V_3 -> V_376 = V_381 ;
break;
}
V_369 = V_365 . V_373 . V_382 ;
F_156 ( V_369 , V_370 ) ;
V_3 -> V_383 = V_369 + V_3 -> V_384 ;
F_3 ( L_98
L_99 ,
V_365 . V_373 . V_374 ,
( unsigned long long ) V_3 -> V_383 ,
V_365 . V_373 . V_385 ,
V_365 . V_373 . V_386 ) ;
V_19 = 1 ;
}
V_367:
return V_19 ;
}
static void
F_157 ( struct V_217 * V_218 ,
struct V_228 * V_228 )
{
struct V_347 * V_348 = & V_228 -> V_232 ;
struct V_281 * V_4 = V_228 -> V_281 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_228 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_348 -> V_109 && V_348 -> V_109 -> V_128 & V_135 ) {
V_19 = F_154 ( V_3 ,
V_348 -> V_109 -> V_115 -> V_118 ) ;
V_348 -> V_109 -> V_128 &= ~ V_135 ;
}
V_24 -> V_98 ( V_228 , V_1 ) ;
V_348 -> V_387 = 0 ;
if ( V_19 )
F_158 ( V_3 ,
V_3 -> V_376 , 0 ) ;
else
F_159 ( V_1 -> V_2 , V_4 ) ;
}
static void
F_160 ( struct V_217 * V_218 ,
struct V_228 * V_228 )
{
struct V_347 * V_348 = & V_228 -> V_232 ;
struct V_281 * V_4 = V_228 -> V_281 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_228 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_348 -> V_109 && V_348 -> V_109 -> V_128 & V_135 ) {
V_19 = F_154 ( V_3 ,
V_348 -> V_109 -> V_115 -> V_118 ) ;
V_348 -> V_109 -> V_128 &= ~ V_135 ;
}
F_149 ( V_4 ) ;
V_24 -> V_98 ( V_228 , V_1 ) ;
V_4 -> V_300 = V_348 -> V_279 . V_345 ;
V_348 -> V_387 = 0 ;
F_9 ( L_100 , V_228 ) ;
F_72 ( & V_4 -> V_302 ) ;
V_4 -> V_303 |= V_304 ;
V_4 -> V_305 = V_306 ;
F_73 ( & V_4 -> V_302 ) ;
if ( V_19 ) {
F_124 ( V_3 ) ;
F_158 ( V_3 ,
V_3 -> V_376 , 0 ) ;
} else {
F_161 ( V_3 ) ;
}
}
static void
F_162 ( struct V_388 * V_78 )
{
struct V_228 * V_228 = F_85 ( V_78 ,
struct V_228 , V_389 ) ;
struct V_1 * V_1 = V_228 -> V_2 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_281 * V_4 = V_228 -> V_281 ;
F_9 ( L_101 , V_228 , V_4 -> V_305 ) ;
switch ( V_4 -> V_305 ) {
case V_390 :
F_163 ( V_4 , V_4 -> V_2 ) ;
case V_391 :
case V_392 :
V_4 -> V_305 = V_393 ;
F_153 ( & V_228 -> V_218 , V_228 ,
V_16 , false ) ;
break;
case V_394 :
F_164 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_102 , V_4 -> V_305 ) ;
F_128 () ;
break;
}
}
static void
F_165 ( struct V_217 * V_218 ,
struct V_228 * V_228 ,
struct V_1 * V_1 ,
struct V_15 * V_16 )
{
struct V_281 * V_4 = V_228 -> V_281 ;
if ( V_4 -> V_305 == V_390 ||
V_4 -> V_305 == V_394 ||
V_4 -> V_305 == V_391 ||
V_4 -> V_305 == V_392 ) {
F_152 ( V_218 , V_16 ) ;
F_37 ( & V_228 -> V_389 , F_162 ) ;
F_96 ( V_395 , & V_228 -> V_389 ) ;
return;
}
V_4 -> V_305 = V_393 ;
F_153 ( V_218 , V_228 , V_16 , false ) ;
}
static void
F_166 ( struct V_217 * V_218 ,
struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_228 * V_228 = V_218 -> V_228 ;
struct V_347 * V_348 ;
if ( ! V_228 ) {
F_152 ( V_218 , V_16 ) ;
return;
}
V_348 = & V_228 -> V_232 ;
F_9 ( L_103 , V_228 , V_348 -> V_233 ) ;
switch ( V_348 -> V_233 ) {
case V_234 :
F_165 ( V_218 , V_228 ,
V_1 , V_16 ) ;
break;
case V_344 :
F_157 ( V_218 , V_228 ) ;
break;
case V_396 :
F_160 ( V_218 , V_228 ) ;
break;
default:
F_3 ( L_104 , V_348 -> V_233 ) ;
F_128 () ;
break;
}
}
static inline bool
F_167 ( struct V_1 * V_1 , void * V_211 )
{
void * V_397 = V_1 -> V_66 ;
int V_345 = V_46 * sizeof( * V_1 -> V_66 ) ;
if ( V_211 >= V_397 && V_211 < V_397 + V_345 )
return false ;
return true ;
}
static void
F_168 ( struct V_1 * V_1 , struct V_398 * V_399 )
{
if ( V_399 -> V_211 == V_400 ) {
F_13 ( L_105 ,
V_1 ) ;
F_94 ( & V_1 -> V_401 ) ;
} else if ( F_167 ( V_1 , ( void * ) ( V_212 ) V_399 -> V_211 ) ) {
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_228 * V_228 ;
struct V_217 * V_120 ;
V_120 = (struct V_217 * ) ( V_212 ) V_399 -> V_211 ;
V_228 = V_120 -> V_228 ;
if ( ! V_228 )
F_152 ( V_120 , V_16 ) ;
else
F_153 ( V_120 , V_228 , V_16 , true ) ;
} else {
V_1 -> V_216 -- ;
if ( ! V_1 -> V_216 )
F_169 ( V_1 -> V_2 , 0 ) ;
}
}
static void
F_170 ( struct V_398 * V_399 )
{
struct V_1 * V_1 ;
struct V_217 * V_218 ;
struct V_60 * V_61 ;
V_1 = V_399 -> V_58 -> V_38 ;
if ( F_171 ( V_399 -> V_198 == V_402 ) ) {
if ( V_399 -> V_224 == V_403 ) {
V_61 = (struct V_60 * ) ( V_212 ) V_399 -> V_211 ;
F_142 ( V_61 , V_1 , V_399 -> V_404 ) ;
} else {
V_218 = (struct V_217 * ) ( V_212 ) V_399 -> V_211 ;
F_166 ( V_218 , V_1 ) ;
}
} else {
if ( V_399 -> V_198 != V_405 )
F_3 ( L_106 ,
F_172 ( V_399 -> V_198 ) , V_399 -> V_198 ,
V_399 -> V_211 , V_399 -> V_406 ) ;
else
F_9 ( L_107 ,
F_172 ( V_399 -> V_198 ) , V_399 -> V_198 ,
V_399 -> V_211 ) ;
if ( V_399 -> V_211 != V_407 )
F_168 ( V_1 , V_399 ) ;
}
}
static void
V_87 ( struct V_388 * V_78 )
{
enum { V_408 = 65536 };
struct V_22 * V_25 = F_85 ( V_78 , struct V_22 ,
V_78 ) ;
struct V_398 * const V_409 = V_25 -> V_409 ;
int V_26 , V_410 , V_411 = 0 ;
while ( ( V_410 = F_173 ( V_25 -> V_40 , F_174 ( V_25 -> V_409 ) , V_409 ) ) > 0 ) {
for ( V_26 = 0 ; V_26 < V_410 ; V_26 ++ )
F_170 ( & V_409 [ V_26 ] ) ;
V_411 += V_410 ;
if ( V_411 >= V_408 )
break;
}
F_39 ( V_25 -> V_40 , V_92 ) ;
}
static void
V_90 ( struct V_412 * V_40 , void * V_10 )
{
struct V_22 * V_25 = V_10 ;
F_96 ( V_395 , & V_25 -> V_78 ) ;
}
static int
F_175 ( struct V_1 * V_1 , struct V_228 * V_228 )
{
struct V_219 * V_413 ;
int V_19 ;
V_19 = F_103 ( V_1 -> V_58 , & V_228 -> V_218 . V_220 ,
& V_413 ) ;
if ( V_19 ) {
F_3 ( L_108 , V_19 ) ;
return V_19 ;
}
return V_19 ;
}
static int
F_159 ( struct V_237 * V_2 , struct V_281 * V_4 )
{
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_219 * V_220 = & V_228 -> V_218 . V_220 ;
struct V_414 * V_285 = (struct V_414 * )
& V_228 -> V_218 . V_241 ;
F_104 ( V_1 , V_228 , & V_228 -> V_218 ) ;
F_176 ( V_4 , V_2 , true , V_285 ) ;
F_106 ( V_1 , & V_228 -> V_218 ) ;
if ( V_4 -> V_3 . V_415 &&
( ( V_4 -> V_3 . V_416 & V_417 ) ||
( V_4 -> V_3 . V_416 & V_418 ) ) ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_244 = & V_228 -> V_218 . V_223 [ 1 ] ;
V_144 V_419 , V_420 ;
F_177 ( V_4 -> V_3 . V_421 ,
V_4 -> V_415 ) ;
V_4 -> V_3 . V_421 += sizeof( V_422 ) ;
V_419 = - ( V_4 -> V_3 . V_421 ) & 3 ;
F_178 ( V_285 -> V_310 , ( V_144 ) V_4 -> V_3 . V_421 ) ;
V_420 = V_4 -> V_3 . V_421 + V_419 ;
V_228 -> V_361 = F_25 ( V_16 ,
( void * ) V_4 -> V_415 , V_420 ,
V_161 ) ;
V_228 -> V_362 = V_420 ;
V_244 -> V_72 = V_228 -> V_361 ;
V_244 -> V_73 = V_420 ;
V_244 -> V_74 = V_24 -> V_75 -> V_74 ;
V_228 -> V_218 . V_214 = 2 ;
}
F_107 ( V_1 , V_228 , V_220 ) ;
F_9 ( L_109 ) ;
return F_175 ( V_1 , V_228 ) ;
}
static void
F_179 ( struct V_237 * V_2 , struct V_281 * V_4 )
{
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
F_72 ( & V_2 -> V_353 ) ;
if ( ! F_53 ( & V_4 -> V_354 ) )
F_95 ( & V_4 -> V_354 ) ;
F_73 ( & V_2 -> V_353 ) ;
if ( V_4 -> V_355 == V_161 )
F_149 ( V_4 ) ;
V_24 -> V_98 ( V_228 , V_1 ) ;
}
static enum V_423
F_180 ( struct V_237 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
if ( V_2 -> V_424 -> V_425 . V_426 ) {
if ( V_24 -> V_54 ) {
F_13 ( L_110 , V_1 ) ;
V_1 -> V_5 = true ;
return V_427 ;
}
}
F_13 ( L_111 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_181 ( struct V_281 * V_4 , struct V_237 * V_2 ,
bool V_428 )
{
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_219 * V_220 = & V_228 -> V_218 . V_220 ;
F_104 ( V_1 , V_228 , & V_228 -> V_218 ) ;
F_182 ( V_4 , V_2 , (struct V_429 * )
& V_228 -> V_218 . V_241 ,
V_428 ) ;
F_106 ( V_1 , & V_228 -> V_218 ) ;
F_107 ( V_1 , V_228 , V_220 ) ;
F_9 ( L_112 , V_1 ) ;
return F_175 ( V_1 , V_228 ) ;
}
static int
F_183 ( struct V_281 * V_4 , struct V_237 * V_2 )
{
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_219 * V_220 = & V_228 -> V_218 . V_220 ;
F_104 ( V_1 , V_228 , & V_228 -> V_218 ) ;
F_184 ( V_4 , V_2 , (struct V_430 * )
& V_228 -> V_218 . V_241 ) ;
F_106 ( V_1 , & V_228 -> V_218 ) ;
F_107 ( V_1 , V_228 , V_220 ) ;
F_9 ( L_113 , V_1 ) ;
return F_175 ( V_1 , V_228 ) ;
}
static int
F_185 ( struct V_281 * V_4 , struct V_237 * V_2 )
{
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_219 * V_220 = & V_228 -> V_218 . V_220 ;
F_104 ( V_1 , V_228 , & V_228 -> V_218 ) ;
F_186 ( V_4 , V_2 , (struct V_431 * )
& V_228 -> V_218 . V_241 ) ;
F_106 ( V_1 , & V_228 -> V_218 ) ;
F_107 ( V_1 , V_228 , V_220 ) ;
F_9 ( L_114 , V_1 ) ;
return F_175 ( V_1 , V_228 ) ;
}
static int
F_187 ( struct V_281 * V_4 , struct V_237 * V_2 )
{
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_219 * V_220 = & V_228 -> V_218 . V_220 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_244 = & V_228 -> V_218 . V_223 [ 1 ] ;
struct V_432 * V_285 =
(struct V_432 * ) & V_228 -> V_218 . V_241 ;
F_104 ( V_1 , V_228 , & V_228 -> V_218 ) ;
F_188 ( V_4 , V_2 , V_285 ) ;
F_106 ( V_1 , & V_228 -> V_218 ) ;
F_178 ( V_285 -> V_310 , V_276 ) ;
V_228 -> V_361 = F_25 ( V_16 ,
( void * ) V_4 -> V_433 , V_276 ,
V_161 ) ;
V_228 -> V_362 = V_276 ;
V_244 -> V_72 = V_228 -> V_361 ;
V_244 -> V_73 = V_276 ;
V_244 -> V_74 = V_24 -> V_75 -> V_74 ;
V_228 -> V_218 . V_214 = 2 ;
F_107 ( V_1 , V_228 , V_220 ) ;
F_9 ( L_115 , V_1 ) ;
return F_175 ( V_1 , V_228 ) ;
}
static int
F_189 ( struct V_281 * V_4 , struct V_237 * V_2 )
{
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_219 * V_220 = & V_228 -> V_218 . V_220 ;
struct V_351 * V_285 =
(struct V_351 * ) & V_228 -> V_218 . V_241 ;
V_144 V_434 ;
int V_292 ;
F_104 ( V_1 , V_228 , & V_228 -> V_218 ) ;
V_292 = F_190 ( V_4 , V_2 , V_285 , V_435 ) ;
if ( V_292 < 0 )
return V_292 ;
V_434 = V_292 ;
F_106 ( V_1 , & V_228 -> V_218 ) ;
if ( V_434 ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_244 = & V_228 -> V_218 . V_223 [ 1 ] ;
void * V_436 = V_4 -> V_433 ;
V_228 -> V_361 = F_25 ( V_16 ,
V_436 , V_434 , V_161 ) ;
V_228 -> V_362 = V_434 ;
V_244 -> V_72 = V_228 -> V_361 ;
V_244 -> V_73 = V_434 ;
V_244 -> V_74 = V_24 -> V_75 -> V_74 ;
V_228 -> V_218 . V_214 = 2 ;
}
F_107 ( V_1 , V_228 , V_220 ) ;
F_9 ( L_116 , V_1 ) ;
return F_175 ( V_1 , V_228 ) ;
}
static int
F_191 ( struct V_1 * V_1 , struct V_228 * V_228 ,
struct V_62 * V_62 , struct V_219 * V_220 ,
V_144 V_437 , V_144 V_339 )
{
struct V_281 * V_4 = V_228 -> V_281 ;
struct V_286 * V_307 , * V_438 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
V_144 V_311 , V_312 ;
int V_26 = 0 , V_291 ;
V_311 = V_339 / V_299 ;
V_307 = & V_4 -> V_3 . V_298 [ V_311 ] ;
V_291 = V_27 ( V_4 -> V_3 . V_439 - V_311 , V_1 -> V_20 ) ;
V_312 = V_339 % V_299 ;
V_220 -> V_213 = V_62 ;
V_220 -> V_211 = ( V_212 ) & V_228 -> V_218 ;
F_192 (sg_start, tmp_sg, sg_nents, i) {
F_9 ( L_117
L_118 ,
( unsigned long long ) V_438 -> V_440 ,
V_438 -> V_73 , V_312 ) ;
V_62 -> V_72 = F_193 ( V_16 , V_438 ) + V_312 ;
V_62 -> V_73 = F_34 ( V_144 , V_437 ,
F_194 ( V_16 , V_438 ) - V_312 ) ;
V_62 -> V_74 = V_24 -> V_75 -> V_74 ;
F_9 ( L_119 ,
V_62 -> V_72 , V_62 -> V_73 , V_62 -> V_74 ) ;
V_312 = 0 ;
V_437 -= V_62 -> V_73 ;
if ( ! V_437 )
break;
V_62 ++ ;
F_9 ( L_120 , V_62 ) ;
}
V_220 -> V_214 = ++ V_26 ;
F_9 ( L_121 ,
V_220 -> V_213 , V_220 -> V_214 ) ;
return V_220 -> V_214 ;
}
static int
V_100 ( struct V_237 * V_2 , struct V_281 * V_4 ,
struct V_347 * V_348 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_342 * V_279 = & V_348 -> V_279 ;
struct V_219 * V_220 ;
struct V_62 * V_62 ;
V_144 V_339 , V_441 , V_437 , V_442 , V_443 = 0 ;
int V_19 = 0 , V_26 , V_444 ;
V_228 -> V_218 . V_228 = V_228 ;
V_339 = V_348 -> V_233 == V_396 ? V_4 -> V_300 : 0 ;
V_19 = F_143 ( V_1 , V_228 , V_3 -> V_298 ,
V_3 -> V_439 , V_3 -> V_301 ,
V_339 , V_348 -> V_233 , & V_348 -> V_279 ) ;
if ( V_19 )
return V_19 ;
V_437 = V_279 -> V_345 ;
V_339 = V_279 -> V_339 ;
V_62 = F_24 ( sizeof( struct V_62 ) * V_279 -> V_338 , V_67 ) ;
if ( ! V_62 ) {
F_6 ( L_122 ) ;
V_19 = - V_77 ;
goto V_445;
}
V_348 -> V_62 = V_62 ;
V_348 -> V_387 = F_120 ( V_279 -> V_338 , V_1 -> V_20 ) ;
V_348 -> V_220 = F_24 ( sizeof( struct V_219 ) * V_348 -> V_387 ,
V_67 ) ;
if ( ! V_348 -> V_220 ) {
F_9 ( L_123 ) ;
V_19 = - V_77 ;
goto V_445;
}
V_348 -> V_228 = V_228 ;
V_442 = V_1 -> V_20 * V_299 ;
for ( V_26 = 0 ; V_26 < V_348 -> V_387 ; V_26 ++ ) {
V_220 = & V_228 -> V_232 . V_220 [ V_26 ] ;
V_441 = V_27 ( V_437 , V_442 ) ;
V_220 -> V_226 = 0 ;
if ( V_348 -> V_233 == V_344 ) {
V_220 -> V_224 = V_446 ;
V_220 -> V_348 . V_447 . V_448 = V_228 -> V_319 + V_339 ;
V_220 -> V_348 . V_447 . V_449 = V_228 -> V_318 ;
if ( V_26 + 1 == V_348 -> V_387 )
V_220 -> V_215 = & V_228 -> V_218 . V_220 ;
else
V_220 -> V_215 = & V_348 -> V_220 [ V_26 + 1 ] ;
} else {
V_220 -> V_224 = V_450 ;
V_220 -> V_348 . V_447 . V_448 = V_228 -> V_321 + V_443 ;
V_220 -> V_348 . V_447 . V_449 = V_228 -> V_320 ;
if ( V_26 + 1 == V_348 -> V_387 )
V_220 -> V_226 = V_227 ;
else
V_220 -> V_215 = & V_348 -> V_220 [ V_26 + 1 ] ;
}
V_444 = F_191 ( V_1 , V_228 , V_62 ,
V_220 , V_441 , V_339 ) ;
V_62 += V_444 ;
V_339 += V_441 ;
V_443 += V_441 ;
V_437 -= V_441 ;
}
return 0 ;
V_445:
F_146 ( V_1 , V_279 ) ;
return V_19 ;
}
static int
F_195 ( struct V_15 * V_16 ,
struct V_286 * V_307 , int V_291 , T_1 * V_451 )
{
T_1 V_452 , V_453 , V_454 , V_455 = 0 ;
struct V_286 * V_438 ;
int V_26 = 0 , V_456 , V_457 , V_458 ;
V_458 = 0 ;
V_456 = 1 ;
V_457 = V_291 - 1 ;
F_192 (sg_start, tmp_sg, sg_nents, i) {
V_452 = F_193 ( V_16 , V_438 ) ;
if ( V_456 )
V_455 = V_452 ;
V_453 = V_452 + F_194 ( V_16 , V_438 ) ;
F_9 ( L_124 ,
V_26 , ( unsigned long long ) V_438 -> V_440 ,
V_438 -> V_73 ) ;
if ( ( V_453 & ~ V_459 ) && V_26 < V_457 ) {
V_456 = 0 ;
continue;
}
V_456 = 1 ;
V_454 = V_455 & V_459 ;
do {
V_451 [ V_458 ++ ] = V_454 ;
F_9 ( L_125 ,
V_458 - 1 , V_454 ) ;
V_454 += V_299 ;
} while ( V_454 < V_453 );
}
return V_458 ;
}
static inline void
F_196 ( struct V_219 * V_460 , struct V_363 * V_75 )
{
V_144 V_449 ;
memset ( V_460 , 0 , sizeof( * V_460 ) ) ;
V_460 -> V_211 = V_407 ;
V_460 -> V_224 = V_461 ;
V_460 -> V_462 . V_463 = V_75 -> V_449 ;
V_449 = F_197 ( V_75 -> V_449 ) ;
F_198 ( V_75 , V_449 ) ;
}
static int
F_199 ( struct V_1 * V_1 ,
struct V_108 * V_109 ,
struct V_342 * V_464 ,
enum V_465 V_128 ,
struct V_62 * V_236 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_363 * V_75 ;
struct V_466 * V_467 ;
struct V_219 V_468 , V_460 ;
struct V_219 * V_469 , * V_348 = NULL ;
int V_19 , V_470 ;
V_144 V_312 ;
if ( V_464 -> V_346 == 1 ) {
V_236 -> V_74 = V_24 -> V_75 -> V_74 ;
V_236 -> V_72 = F_193 ( V_16 , & V_464 -> V_287 [ 0 ] ) ;
V_236 -> V_73 = F_194 ( V_16 , & V_464 -> V_287 [ 0 ] ) ;
F_9 ( L_126 ,
V_236 -> V_72 , V_236 -> V_73 , V_236 -> V_74 ) ;
return 0 ;
}
if ( V_128 == V_137 ) {
V_75 = V_109 -> V_114 ;
V_467 = V_109 -> V_113 ;
} else {
V_75 = V_109 -> V_115 -> V_117 ;
V_467 = V_109 -> V_115 -> V_116 ;
}
V_312 = V_464 -> V_339 % V_299 ;
F_9 ( L_127 ,
V_109 , V_464 -> V_338 , V_464 -> V_339 ) ;
V_470 = F_195 ( V_16 , V_464 -> V_287 , V_464 -> V_338 ,
& V_467 -> V_471 [ 0 ] ) ;
if ( ! ( V_109 -> V_128 & V_128 ) ) {
F_196 ( & V_460 , V_75 ) ;
V_348 = & V_460 ;
}
memset ( & V_468 , 0 , sizeof( V_468 ) ) ;
V_468 . V_211 = V_407 ;
V_468 . V_224 = V_472 ;
V_468 . V_348 . V_473 . V_474 = V_467 -> V_471 [ 0 ] + V_312 ;
V_468 . V_348 . V_473 . V_471 = V_467 ;
V_468 . V_348 . V_473 . V_475 = V_470 ;
V_468 . V_348 . V_473 . V_476 = V_477 ;
V_468 . V_348 . V_473 . V_73 = V_464 -> V_345 ;
V_468 . V_348 . V_473 . V_449 = V_75 -> V_449 ;
V_468 . V_348 . V_473 . V_478 = V_102 ;
if ( ! V_348 )
V_348 = & V_468 ;
else
V_348 -> V_215 = & V_468 ;
V_19 = F_103 ( V_1 -> V_58 , V_348 , & V_469 ) ;
if ( V_19 ) {
F_3 ( L_128 , V_19 ) ;
return V_19 ;
}
V_109 -> V_128 &= ~ V_128 ;
V_236 -> V_74 = V_75 -> V_74 ;
V_236 -> V_72 = V_467 -> V_471 [ 0 ] + V_312 ;
V_236 -> V_73 = V_464 -> V_345 ;
F_9 ( L_126 ,
V_236 -> V_72 , V_236 -> V_73 , V_236 -> V_74 ) ;
return V_19 ;
}
static inline void
F_200 ( struct V_3 * V_3 , struct V_479 * V_480 ,
struct V_481 * V_482 )
{
V_482 -> V_483 = V_484 ;
V_482 -> V_485 . V_486 . V_487 = V_488 ;
V_482 -> V_485 . V_486 . V_489 = V_3 -> V_371 -> V_372 . V_370 ;
V_482 -> V_485 . V_486 . V_490 = V_3 -> V_491 ;
V_482 -> V_485 . V_486 . V_492 = 0xffff ;
V_482 -> V_485 . V_486 . V_493 = true ;
V_482 -> V_485 . V_486 . V_494 = true ;
if ( V_3 -> V_495 == V_496 ||
V_3 -> V_495 == V_497 )
V_482 -> V_485 . V_486 . V_498 = true ;
}
static int
F_201 ( struct V_3 * V_3 , struct V_479 * V_480 )
{
switch ( V_3 -> V_6 ) {
case V_499 :
case V_500 :
V_480 -> V_464 . V_483 = V_501 ;
F_200 ( V_3 , V_480 , & V_480 -> V_502 ) ;
break;
case V_503 :
case V_504 :
V_480 -> V_502 . V_483 = V_501 ;
F_200 ( V_3 , V_480 , & V_480 -> V_464 ) ;
break;
case V_505 :
case V_506 :
F_200 ( V_3 , V_480 , & V_480 -> V_502 ) ;
F_200 ( V_3 , V_480 , & V_480 -> V_464 ) ;
break;
default:
F_3 ( L_129 , V_3 -> V_6 ) ;
return - V_322 ;
}
return 0 ;
}
static inline V_178
F_202 ( V_178 V_507 )
{
return ( V_507 & V_508 ? 0xc0 : 0 ) |
( V_507 & V_509 ? 0x30 : 0 ) |
( V_507 & V_509 ? 0x0f : 0 ) ;
}
static int
F_203 ( struct V_1 * V_1 ,
struct V_3 * V_3 ,
struct V_347 * V_232 ,
struct V_108 * V_109 )
{
struct V_219 V_510 , V_460 ;
struct V_219 * V_469 , * V_348 = NULL ;
struct V_124 * V_115 = V_109 -> V_115 ;
struct V_479 V_480 ;
int V_19 ;
memset ( & V_480 , 0 , sizeof( V_480 ) ) ;
V_19 = F_201 ( V_3 , & V_480 ) ;
if ( V_19 )
goto V_59;
V_480 . V_511 = F_202 ( V_3 -> V_507 ) ;
if ( ! ( V_109 -> V_128 & V_134 ) ) {
F_196 ( & V_460 , V_115 -> V_118 ) ;
V_348 = & V_460 ;
}
memset ( & V_510 , 0 , sizeof( V_510 ) ) ;
V_510 . V_224 = V_512 ;
V_510 . V_211 = V_407 ;
V_510 . V_213 = & V_232 -> V_513 [ V_514 ] ;
V_510 . V_214 = 1 ;
V_510 . V_348 . V_515 . V_478 = V_102 ;
V_510 . V_348 . V_515 . V_480 = & V_480 ;
V_510 . V_348 . V_515 . V_118 = V_115 -> V_118 ;
if ( V_3 -> V_516 )
V_510 . V_348 . V_515 . V_349 = & V_232 -> V_513 [ V_517 ] ;
if ( ! V_348 )
V_348 = & V_510 ;
else
V_348 -> V_215 = & V_510 ;
V_19 = F_103 ( V_1 -> V_58 , V_348 , & V_469 ) ;
if ( V_19 ) {
F_3 ( L_128 , V_19 ) ;
goto V_59;
}
V_109 -> V_128 &= ~ V_134 ;
V_232 -> V_513 [ V_518 ] . V_74 = V_115 -> V_118 -> V_74 ;
V_232 -> V_513 [ V_518 ] . V_72 = 0 ;
V_232 -> V_513 [ V_518 ] . V_73 = V_3 -> V_301 ;
if ( V_3 -> V_6 != V_504 &&
V_3 -> V_6 != V_503 )
V_232 -> V_513 [ V_518 ] . V_73 += V_3 -> V_519 ;
F_9 ( L_130 ,
V_232 -> V_513 [ V_518 ] . V_72 , V_232 -> V_513 [ V_518 ] . V_73 ,
V_232 -> V_513 [ V_518 ] . V_74 ) ;
V_59:
return V_19 ;
}
static int
F_204 ( struct V_1 * V_1 ,
struct V_228 * V_228 ,
struct V_347 * V_348 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_3 * V_3 = & V_228 -> V_281 -> V_3 ;
int V_19 ;
if ( ! V_348 -> V_109 -> V_115 ) {
V_19 = F_57 ( V_348 -> V_109 ,
V_24 -> V_15 ,
V_24 -> V_57 ) ;
if ( V_19 ) {
F_3 ( L_131 ,
V_1 ) ;
return V_19 ;
}
}
if ( V_3 -> V_516 ) {
V_19 = F_143 ( V_1 , V_228 ,
V_3 -> V_516 ,
V_3 -> V_520 ,
V_3 -> V_519 ,
0 , V_348 -> V_233 , & V_348 -> V_349 ) ;
if ( V_19 ) {
F_3 ( L_132 ,
V_1 ) ;
return V_19 ;
}
memset ( & V_348 -> V_513 [ V_517 ] , 0 , sizeof( V_348 -> V_513 [ V_517 ] ) ) ;
V_19 = F_199 ( V_1 , V_348 -> V_109 , & V_348 -> V_349 ,
V_129 , & V_348 -> V_513 [ V_517 ] ) ;
if ( V_19 ) {
F_3 ( L_133 ,
V_1 ) ;
goto V_521;
}
}
V_19 = F_203 ( V_1 , V_3 , V_348 , V_348 -> V_109 ) ;
if ( V_19 ) {
F_3 ( L_133 ,
V_1 ) ;
goto V_521;
}
V_348 -> V_109 -> V_128 |= V_135 ;
return 0 ;
V_521:
if ( V_3 -> V_516 )
F_146 ( V_1 , & V_348 -> V_349 ) ;
return V_19 ;
}
static int
V_97 ( struct V_237 * V_2 , struct V_281 * V_4 ,
struct V_347 * V_348 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_108 * V_109 = NULL ;
struct V_219 * V_220 ;
struct V_62 * V_513 ;
V_144 V_339 ;
int V_19 = 0 ;
unsigned long V_131 ;
V_228 -> V_218 . V_228 = V_228 ;
V_339 = V_348 -> V_233 == V_396 ? V_4 -> V_300 : 0 ;
V_19 = F_143 ( V_1 , V_228 , V_3 -> V_298 ,
V_3 -> V_439 , V_3 -> V_301 ,
V_339 , V_348 -> V_233 , & V_348 -> V_279 ) ;
if ( V_19 )
return V_19 ;
if ( V_348 -> V_279 . V_346 != 1 || F_1 ( V_1 , V_3 ) ) {
F_205 ( & V_1 -> V_156 , V_131 ) ;
V_109 = F_206 ( & V_1 -> V_111 ,
struct V_108 , V_112 ) ;
F_47 ( & V_109 -> V_112 ) ;
F_207 ( & V_1 -> V_156 , V_131 ) ;
V_348 -> V_109 = V_109 ;
}
V_19 = F_199 ( V_1 , V_109 , & V_348 -> V_279 ,
V_137 , & V_348 -> V_513 [ V_514 ] ) ;
if ( V_19 )
goto V_445;
if ( F_1 ( V_1 , V_3 ) ) {
V_19 = F_204 ( V_1 , V_228 , V_348 ) ;
if ( V_19 )
goto V_445;
V_513 = & V_348 -> V_513 [ V_518 ] ;
} else {
V_513 = & V_348 -> V_513 [ V_514 ] ;
}
memcpy ( & V_348 -> V_522 , V_513 , sizeof( * V_513 ) ) ;
V_348 -> V_62 = & V_348 -> V_522 ;
V_348 -> V_387 = 1 ;
memset ( & V_348 -> V_523 , 0 , sizeof( * V_220 ) ) ;
V_348 -> V_220 = & V_348 -> V_523 ;
V_348 -> V_228 = V_228 ;
V_220 = & V_228 -> V_232 . V_523 ;
V_220 -> V_213 = & V_348 -> V_522 ;
V_220 -> V_214 = 1 ;
V_220 -> V_211 = ( V_212 ) & V_228 -> V_218 ;
if ( V_348 -> V_233 == V_344 ) {
V_220 -> V_224 = V_446 ;
V_220 -> V_348 . V_447 . V_448 = V_228 -> V_319 ;
V_220 -> V_348 . V_447 . V_449 = V_228 -> V_318 ;
V_220 -> V_226 = ! F_1 ( V_1 , V_3 ) ?
0 : V_227 ;
} else {
V_220 -> V_224 = V_450 ;
V_220 -> V_348 . V_447 . V_448 = V_228 -> V_321 ;
V_220 -> V_348 . V_447 . V_449 = V_228 -> V_320 ;
V_220 -> V_226 = V_227 ;
}
return 0 ;
V_445:
if ( V_109 ) {
F_205 ( & V_1 -> V_156 , V_131 ) ;
F_51 ( & V_109 -> V_112 , & V_1 -> V_111 ) ;
F_207 ( & V_1 -> V_156 , V_131 ) ;
}
F_146 ( V_1 , & V_348 -> V_279 ) ;
return V_19 ;
}
static int
F_208 ( struct V_237 * V_2 , struct V_281 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_347 * V_348 = & V_228 -> V_232 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_219 * V_413 ;
int V_292 ;
F_9 ( L_134 ,
V_228 , V_3 -> V_301 ) ;
V_348 -> V_233 = V_344 ;
V_292 = V_24 -> V_96 ( V_2 , V_4 , V_348 ) ;
if ( V_292 ) {
F_3 ( L_135 , V_228 ) ;
return V_292 ;
}
if ( ! F_1 ( V_1 , V_3 ) ) {
F_104 ( V_1 , V_228 ,
& V_228 -> V_218 ) ;
F_176 ( V_4 , V_2 , true , (struct V_414 * )
& V_228 -> V_218 . V_241 ) ;
F_106 ( V_1 , & V_228 -> V_218 ) ;
F_107 ( V_1 , V_228 ,
& V_228 -> V_218 . V_220 ) ;
V_228 -> V_232 . V_523 . V_215 = & V_228 -> V_218 . V_220 ;
V_348 -> V_387 += 1 ;
}
V_292 = F_103 ( V_1 -> V_58 , V_348 -> V_220 , & V_413 ) ;
if ( V_292 )
F_6 ( L_136 ) ;
if ( ! F_1 ( V_1 , V_3 ) )
F_9 ( L_137
L_138 , V_228 ) ;
else
F_9 ( L_139 ,
V_228 ) ;
return 1 ;
}
static int
F_209 ( struct V_237 * V_2 , struct V_281 * V_4 , bool V_524 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_228 * V_228 = F_116 ( V_4 ) ;
struct V_347 * V_348 = & V_228 -> V_232 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_219 * V_413 ;
int V_292 ;
F_9 ( L_140 ,
V_228 , V_3 -> V_301 , V_4 -> V_300 ) ;
V_348 -> V_233 = V_396 ;
V_292 = V_24 -> V_96 ( V_2 , V_4 , V_348 ) ;
if ( V_292 ) {
F_3 ( L_135 , V_228 ) ;
return V_292 ;
}
V_292 = F_103 ( V_1 -> V_58 , V_348 -> V_220 , & V_413 ) ;
if ( V_292 )
F_6 ( L_141 ) ;
F_9 ( L_142 ,
V_228 ) ;
return 0 ;
}
static int
F_210 ( struct V_237 * V_2 , struct V_281 * V_4 , int V_148 )
{
int V_19 ;
switch ( V_148 ) {
case V_525 :
V_19 = F_181 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_143 , V_148 ) ;
V_19 = - V_322 ;
break;
}
return V_19 ;
}
static int
F_211 ( struct V_237 * V_2 , struct V_281 * V_4 , int V_148 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
switch ( V_148 ) {
case V_394 :
V_19 = F_183 ( V_4 , V_2 ) ;
if ( ! V_19 )
V_1 -> V_526 = true ;
break;
case V_527 :
V_19 = F_181 ( V_4 , V_2 , true ) ;
break;
case V_390 :
V_19 = F_185 ( V_4 , V_2 ) ;
break;
case V_391 :
V_19 = F_187 ( V_4 , V_2 ) ;
break;
case V_392 :
V_19 = F_189 ( V_4 , V_2 ) ;
break;
case V_528 :
V_19 = F_159 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_144 , V_148 ) ;
V_19 = - V_322 ;
break;
}
return V_19 ;
}
struct V_33 *
F_92 ( struct V_170 * V_170 )
{
struct V_171 * V_172 = V_170 -> V_172 ;
struct V_33 * V_529 ;
struct V_530 * V_531 ;
int V_19 ;
V_531 = (struct V_530 * ) & V_172 -> V_532 ;
F_9 ( L_145 , & V_172 -> V_532 , V_531 ) ;
V_529 = F_212 ( F_98 , V_170 ,
V_533 , V_53 ) ;
if ( F_20 ( V_529 ) ) {
F_3 ( L_146 , F_21 ( V_529 ) ) ;
V_19 = F_21 ( V_529 ) ;
goto V_175;
}
F_9 ( L_147 , V_529 , V_529 -> V_10 ) ;
V_19 = F_213 ( V_529 , V_531 ) ;
if ( V_19 ) {
F_3 ( L_148 , V_19 ) ;
goto V_534;
}
V_19 = F_214 ( V_529 , 0 ) ;
if ( V_19 ) {
F_3 ( L_149 , V_19 ) ;
goto V_534;
}
return V_529 ;
V_534:
F_81 ( V_529 ) ;
V_175:
return F_18 ( V_19 ) ;
}
static int
F_215 ( struct V_171 * V_172 ,
struct V_535 * V_536 )
{
struct V_170 * V_170 ;
struct V_33 * V_537 ;
int V_19 ;
V_170 = F_24 ( sizeof( struct V_170 ) , V_67 ) ;
if ( ! V_170 ) {
F_3 ( L_150 ) ;
return - V_77 ;
}
F_216 ( & V_170 -> V_184 , 0 ) ;
F_67 ( & V_170 -> V_182 ) ;
F_50 ( & V_170 -> V_183 ) ;
F_65 ( & V_170 -> V_538 ) ;
V_170 -> V_172 = V_172 ;
memcpy ( & V_172 -> V_532 , V_536 ,
sizeof( struct V_535 ) ) ;
V_537 = F_92 ( V_170 ) ;
if ( F_20 ( V_537 ) ) {
V_19 = F_21 ( V_537 ) ;
goto V_175;
}
V_170 -> V_194 = V_537 ;
V_172 -> V_539 = V_170 ;
return 0 ;
V_175:
F_28 ( V_170 ) ;
return V_19 ;
}
static int
F_77 ( struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_540 V_541 ;
int V_19 ;
memset ( & V_541 , 0 , sizeof( struct V_540 ) ) ;
V_541 . V_177 = V_1 -> V_177 ;
V_541 . V_542 = 7 ;
V_541 . V_543 = 7 ;
V_19 = F_217 ( V_13 , & V_541 ) ;
if ( V_19 ) {
F_3 ( L_151 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int
F_218 ( struct V_237 * V_2 , struct V_238 * V_239 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
F_13 ( L_152 , V_1 ) ;
V_19 = F_219 ( & V_1 -> V_152 ) ;
if ( V_19 ) {
F_3 ( L_153 ,
V_1 ) ;
return V_19 ;
}
F_220 ( & V_1 -> V_152 ) ;
if ( ! V_239 -> V_256 )
return 0 ;
F_109 ( V_1 ) ;
F_13 ( L_154 , V_2 ) ;
V_19 = F_219 ( & V_1 -> V_151 ) ;
if ( V_19 )
return V_19 ;
F_13 ( L_155 , V_239 -> V_275 ) ;
return 0 ;
}
static void
F_221 ( struct V_171 * V_172 , struct V_237 * V_2 ,
struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_544 * V_545 = & V_13 -> V_546 ;
struct V_547 * V_548 ;
struct V_549 * V_550 ;
V_2 -> V_551 = V_172 -> V_532 . V_552 ;
if ( V_172 -> V_532 . V_552 == V_553 ) {
V_550 = (struct V_549 * ) & V_545 -> V_72 . V_554 ;
snprintf ( V_2 -> V_555 , sizeof( V_2 -> V_555 ) , L_156 ,
& V_550 -> V_556 . V_557 ) ;
V_2 -> V_558 = F_222 ( V_550 -> V_559 ) ;
V_550 = (struct V_549 * ) & V_545 -> V_72 . V_560 ;
snprintf ( V_2 -> V_561 , sizeof( V_2 -> V_561 ) , L_156 ,
& V_550 -> V_556 . V_557 ) ;
V_2 -> V_562 = F_222 ( V_550 -> V_559 ) ;
} else {
V_548 = (struct V_547 * ) & V_545 -> V_72 . V_554 ;
sprintf ( V_2 -> V_555 , L_157 ,
& V_548 -> V_563 . V_564 ) ;
V_2 -> V_558 = F_222 ( V_548 -> V_565 ) ;
V_548 = (struct V_547 * ) & V_545 -> V_72 . V_560 ;
sprintf ( V_2 -> V_561 , L_157 ,
& V_548 -> V_563 . V_564 ) ;
V_2 -> V_562 = F_222 ( V_548 -> V_565 ) ;
}
}
static int
F_223 ( struct V_171 * V_172 , struct V_237 * V_2 )
{
struct V_170 * V_170 = V_172 -> V_539 ;
struct V_1 * V_1 ;
int V_19 ;
V_566:
V_19 = F_224 ( & V_170 -> V_184 ) ;
if ( V_19 )
return - V_567 ;
F_72 ( & V_172 -> V_173 ) ;
if ( V_172 -> V_568 >= V_569 ) {
F_73 ( & V_172 -> V_173 ) ;
F_9 ( L_158 ,
V_172 -> V_568 ) ;
return - V_567 ;
}
F_73 ( & V_172 -> V_173 ) ;
F_11 ( & V_170 -> V_182 ) ;
if ( F_53 ( & V_170 -> V_183 ) ) {
F_12 ( & V_170 -> V_182 ) ;
goto V_566;
}
V_1 = F_206 ( & V_170 -> V_183 ,
struct V_1 , V_150 ) ;
F_95 ( & V_1 -> V_150 ) ;
F_12 ( & V_170 -> V_182 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
F_221 ( V_172 , V_2 , V_1 ) ;
F_9 ( L_159 , V_1 ) ;
return 0 ;
}
static void
F_225 ( struct V_171 * V_172 )
{
struct V_170 * V_170 = V_172 -> V_539 ;
struct V_1 * V_1 , * V_410 ;
if ( V_170 -> V_194 )
F_81 ( V_170 -> V_194 ) ;
F_11 ( & V_170 -> V_182 ) ;
if ( ! F_53 ( & V_170 -> V_183 ) ) {
F_13 ( L_160 ) ;
F_54 (isert_conn, n,
&isert_np->np_accept_list,
accept_node) {
F_13 ( L_161 ,
V_1 , V_1 -> V_148 ) ;
F_79 ( V_1 ) ;
}
}
F_12 ( & V_170 -> V_182 ) ;
V_172 -> V_539 = NULL ;
F_28 ( V_170 ) ;
}
static void V_158 ( struct V_388 * V_78 )
{
struct V_1 * V_1 = F_85 ( V_78 ,
struct V_1 ,
V_157 ) ;
F_13 ( L_162 , V_1 ) ;
F_226 ( & V_1 -> V_153 ) ;
F_11 ( & V_1 -> V_155 ) ;
V_1 -> V_148 = V_570 ;
F_12 ( & V_1 -> V_155 ) ;
F_13 ( L_163 , V_1 ) ;
F_86 ( V_1 ) ;
}
static void
F_227 ( struct V_1 * V_1 )
{
struct V_237 * V_2 = V_1 -> V_2 ;
F_13 ( L_41 , V_1 ) ;
if ( V_1 -> V_526 ) {
F_13 ( L_164 , V_1 ) ;
F_228 ( & V_2 -> V_571 ,
V_572 * V_573 ) ;
}
}
static void
F_229 ( struct V_237 * V_2 )
{
F_13 ( L_165 , V_2 ) ;
if ( V_2 -> V_140 ) {
F_230 ( V_2 -> V_140 -> V_139 ) ;
F_231 ( V_2 -> V_140 -> V_139 ) ;
}
}
static void
F_232 ( struct V_1 * V_1 )
{
struct V_207 * V_469 ;
F_13 ( L_41 , V_1 ) ;
F_65 ( & V_1 -> V_401 ) ;
V_1 -> V_574 . V_211 = V_400 ;
if ( F_100 ( V_1 -> V_58 , & V_1 -> V_574 , & V_469 ) ) {
F_3 ( L_166 , V_1 ) ;
return;
}
F_226 ( & V_1 -> V_401 ) ;
}
static void F_233 ( struct V_237 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_13 ( L_167 , V_1 ) ;
F_11 ( & V_1 -> V_155 ) ;
if ( V_1 -> V_148 == V_149 ) {
F_12 ( & V_1 -> V_155 ) ;
return;
}
F_88 ( V_1 ) ;
F_12 ( & V_1 -> V_155 ) ;
F_229 ( V_2 ) ;
F_232 ( V_1 ) ;
F_227 ( V_1 ) ;
F_96 ( V_197 , & V_1 -> V_157 ) ;
}
static void F_234 ( struct V_237 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_232 ( V_1 ) ;
F_86 ( V_1 ) ;
}
static int T_4 F_235 ( void )
{
int V_19 ;
V_395 = F_236 ( L_168 ,
V_575 | V_576 , 0 ) ;
if ( ! V_395 ) {
F_3 ( L_169 ) ;
V_19 = - V_77 ;
return - V_77 ;
}
V_197 = F_236 ( L_170 , V_575 ,
V_577 ) ;
if ( ! V_197 ) {
F_3 ( L_171 ) ;
V_19 = - V_77 ;
goto V_578;
}
F_237 ( & V_579 ) ;
F_13 ( L_172 ) ;
return 0 ;
V_578:
F_238 ( V_395 ) ;
return V_19 ;
}
static void T_5 F_239 ( void )
{
F_240 () ;
F_238 ( V_197 ) ;
F_238 ( V_395 ) ;
F_241 ( & V_579 ) ;
F_13 ( L_173 ) ;
}
