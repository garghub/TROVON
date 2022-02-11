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
F_3 ( L_1 , V_1 , V_9 -> V_11 ) ;
switch ( V_9 -> V_11 ) {
case V_12 :
F_4 ( V_1 -> V_13 , V_12 ) ;
break;
case V_14 :
F_5 ( L_2 ) ;
break;
default:
break;
}
}
static int
F_6 ( struct V_15 * V_16 , struct V_17 * V_18 )
{
int V_19 ;
V_19 = F_7 ( V_16 , V_18 ) ;
if ( V_19 ) {
F_3 ( L_3 , V_19 ) ;
return V_19 ;
}
F_8 ( L_4 , V_18 -> V_20 ) ;
F_8 ( L_5 , V_18 -> V_21 ) ;
return 0 ;
}
static struct V_22 *
F_9 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_22 * V_25 ;
int V_26 , V_27 = 0 ;
F_10 ( & V_28 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ )
if ( V_24 -> V_30 [ V_26 ] . V_31 <
V_24 -> V_30 [ V_27 ] . V_31 )
V_27 = V_26 ;
V_25 = & V_24 -> V_30 [ V_27 ] ;
V_25 -> V_31 ++ ;
F_11 ( & V_28 ) ;
F_12 ( L_6 ,
V_1 , V_25 , V_27 ) ;
return V_25 ;
}
static void
F_13 ( struct V_22 * V_25 )
{
F_10 ( & V_28 ) ;
V_25 -> V_31 -- ;
F_11 ( & V_28 ) ;
}
static struct V_32 *
F_14 ( struct V_1 * V_1 ,
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
V_36 . V_42 . V_47 = F_15 ( 2 , V_24 -> V_48 . V_20 - 2 ) ;
V_1 -> V_20 = V_36 . V_42 . V_47 ;
V_36 . V_42 . V_49 = 1 ;
V_36 . V_50 = V_51 ;
V_36 . V_52 = V_53 ;
if ( V_24 -> V_54 )
V_36 . V_55 |= V_56 ;
V_19 = F_16 ( V_34 , V_24 -> V_57 , & V_36 ) ;
if ( V_19 ) {
F_3 ( L_7 , V_19 ) ;
return F_17 ( V_19 ) ;
}
return V_34 -> V_58 ;
}
static int
F_18 ( struct V_1 * V_1 , struct V_33 * V_34 )
{
struct V_22 * V_25 ;
int V_19 ;
V_25 = F_9 ( V_1 ) ;
V_1 -> V_58 = F_14 ( V_1 , V_25 , V_34 ) ;
if ( F_19 ( V_1 -> V_58 ) ) {
V_19 = F_20 ( V_1 -> V_58 ) ;
goto V_59;
}
return 0 ;
V_59:
F_13 ( V_25 ) ;
return V_19 ;
}
static void
F_21 ( struct V_8 * V_9 , void * V_10 )
{
F_8 ( L_8 , V_9 -> V_11 ) ;
}
static int
F_22 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
T_1 V_64 ;
int V_26 , V_65 ;
V_1 -> V_66 = F_23 ( V_46 *
sizeof( struct V_60 ) , V_67 ) ;
if ( ! V_1 -> V_66 )
goto V_68;
V_61 = V_1 -> V_66 ;
for ( V_26 = 0 ; V_26 < V_46 ; V_26 ++ , V_61 ++ ) {
V_64 = F_24 ( V_16 , ( void * ) V_61 ,
V_69 , V_70 ) ;
if ( F_25 ( V_16 , V_64 ) )
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
F_26 ( V_16 , V_61 -> V_64 ,
V_69 , V_70 ) ;
}
F_27 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
V_68:
F_3 ( L_9 , V_1 ) ;
return - V_77 ;
}
static void
F_28 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_24 -> V_15 ;
struct V_60 * V_61 ;
int V_26 ;
if ( ! V_1 -> V_66 )
return;
V_61 = V_1 -> V_66 ;
for ( V_26 = 0 ; V_26 < V_46 ; V_26 ++ , V_61 ++ ) {
F_26 ( V_16 , V_61 -> V_64 ,
V_69 , V_70 ) ;
}
F_27 ( V_1 -> V_66 ) ;
V_1 -> V_66 = NULL ;
}
static void
F_29 ( struct V_23 * V_24 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ ) {
struct V_22 * V_25 = & V_24 -> V_30 [ V_26 ] ;
if ( V_25 -> V_40 ) {
F_30 ( & V_25 -> V_78 ) ;
F_31 ( V_25 -> V_40 ) ;
}
}
F_27 ( V_24 -> V_30 ) ;
}
static int
F_32 ( struct V_23 * V_24 ,
struct V_17 * V_36 )
{
int V_26 , V_79 , V_19 = 0 ;
V_24 -> V_29 = V_27 ( V_80 , F_33 ( int , F_34 () ,
V_24 -> V_15 -> V_81 ) ) ;
F_12 ( L_10
L_11 ,
V_24 -> V_29 , V_24 -> V_15 -> V_82 ,
V_24 -> V_15 -> V_81 , V_24 -> V_83 ,
V_24 -> V_54 ) ;
V_24 -> V_30 = F_35 ( V_24 -> V_29 , sizeof( struct V_22 ) ,
V_67 ) ;
if ( ! V_24 -> V_30 ) {
F_3 ( L_12 ) ;
return - V_77 ;
}
V_79 = V_27 ( V_84 , V_36 -> V_79 ) ;
for ( V_26 = 0 ; V_26 < V_24 -> V_29 ; V_26 ++ ) {
struct V_22 * V_25 = & V_24 -> V_30 [ V_26 ] ;
V_25 -> V_24 = V_24 ;
F_36 ( & V_25 -> V_78 , V_85 ) ;
V_25 -> V_40 = F_37 ( V_24 -> V_15 ,
V_86 ,
F_21 ,
( void * ) V_25 ,
V_79 , V_26 ) ;
if ( F_19 ( V_25 -> V_40 ) ) {
F_3 ( L_13 ) ;
V_19 = F_20 ( V_25 -> V_40 ) ;
V_25 -> V_40 = NULL ;
goto V_87;
}
V_19 = F_38 ( V_25 -> V_40 , V_88 ) ;
if ( V_19 )
goto V_87;
}
return 0 ;
V_87:
F_29 ( V_24 ) ;
return V_19 ;
}
static int
F_39 ( struct V_23 * V_24 )
{
struct V_17 * V_48 ;
int V_19 ;
V_48 = & V_24 -> V_48 ;
V_19 = F_6 ( V_24 -> V_15 , V_48 ) ;
if ( V_19 )
return V_19 ;
if ( V_48 -> V_89 & V_90 &&
V_48 -> V_89 & V_91 ) {
V_24 -> V_83 = 1 ;
V_24 -> V_92 = V_93 ;
V_24 -> V_94 = V_95 ;
} else {
V_24 -> V_83 = 0 ;
V_24 -> V_92 = V_96 ;
V_24 -> V_94 = V_97 ;
}
V_19 = F_32 ( V_24 , V_48 ) ;
if ( V_19 )
return V_19 ;
V_24 -> V_57 = F_40 ( V_24 -> V_15 ) ;
if ( F_19 ( V_24 -> V_57 ) ) {
V_19 = F_20 ( V_24 -> V_57 ) ;
F_3 ( L_14 ,
V_24 , V_19 ) ;
goto V_87;
}
V_24 -> V_75 = F_41 ( V_24 -> V_57 , V_98 ) ;
if ( F_19 ( V_24 -> V_75 ) ) {
V_19 = F_20 ( V_24 -> V_75 ) ;
F_3 ( L_15 ,
V_24 , V_19 ) ;
goto V_99;
}
V_24 -> V_54 = V_48 -> V_89 &
V_91 ? true : false ;
return 0 ;
V_99:
F_42 ( V_24 -> V_57 ) ;
V_87:
F_29 ( V_24 ) ;
return V_19 ;
}
static void
F_43 ( struct V_23 * V_24 )
{
F_12 ( L_16 , V_24 ) ;
F_44 ( V_24 -> V_75 ) ;
F_42 ( V_24 -> V_57 ) ;
F_29 ( V_24 ) ;
}
static void
F_45 ( struct V_23 * V_24 )
{
F_10 ( & V_28 ) ;
V_24 -> V_100 -- ;
F_12 ( L_17 , V_24 , V_24 -> V_100 ) ;
if ( ! V_24 -> V_100 ) {
F_43 ( V_24 ) ;
F_46 ( & V_24 -> V_101 ) ;
F_27 ( V_24 ) ;
}
F_11 ( & V_28 ) ;
}
static struct V_23 *
F_47 ( struct V_33 * V_34 )
{
struct V_23 * V_24 ;
int V_19 ;
F_10 ( & V_28 ) ;
F_48 (device, &device_list, dev_node) {
if ( V_24 -> V_15 -> V_102 == V_34 -> V_24 -> V_102 ) {
V_24 -> V_100 ++ ;
F_12 ( L_18 ,
V_24 , V_24 -> V_100 ) ;
F_11 ( & V_28 ) ;
return V_24 ;
}
}
V_24 = F_23 ( sizeof( struct V_23 ) , V_67 ) ;
if ( ! V_24 ) {
F_11 ( & V_28 ) ;
return F_17 ( - V_77 ) ;
}
F_49 ( & V_24 -> V_101 ) ;
V_24 -> V_15 = V_34 -> V_24 ;
V_19 = F_39 ( V_24 ) ;
if ( V_19 ) {
F_27 ( V_24 ) ;
F_11 ( & V_28 ) ;
return F_17 ( V_19 ) ;
}
V_24 -> V_100 ++ ;
F_50 ( & V_24 -> V_101 , & V_103 ) ;
F_12 ( L_19 ,
V_24 , V_24 -> V_100 ) ;
F_11 ( & V_28 ) ;
return V_24 ;
}
static void
F_51 ( struct V_1 * V_1 )
{
struct V_104 * V_105 , * V_106 ;
int V_26 = 0 ;
if ( F_52 ( & V_1 -> V_107 ) )
return;
F_12 ( L_20 , V_1 ) ;
F_53 (fr_desc, tmp,
&isert_conn->fr_pool, list) {
F_46 ( & V_105 -> V_108 ) ;
F_54 ( V_105 -> V_109 ) ;
F_44 ( V_105 -> V_110 ) ;
if ( V_105 -> V_111 ) {
F_54 ( V_105 -> V_111 -> V_112 ) ;
F_44 ( V_105 -> V_111 -> V_113 ) ;
F_55 ( V_105 -> V_111 -> V_114 ) ;
F_27 ( V_105 -> V_111 ) ;
}
F_27 ( V_105 ) ;
++ V_26 ;
}
if ( V_26 < V_1 -> V_115 )
F_5 ( L_21 ,
V_1 -> V_115 - V_26 ) ;
}
static int
F_56 ( struct V_104 * V_116 ,
struct V_15 * V_24 ,
struct V_117 * V_57 )
{
struct V_118 V_119 ;
struct V_120 * V_111 ;
int V_19 ;
V_111 = F_23 ( sizeof( * V_116 -> V_111 ) , V_67 ) ;
if ( ! V_111 ) {
F_3 ( L_22 ) ;
return - V_77 ;
}
V_111 -> V_112 = F_57 ( V_24 ,
V_121 ) ;
if ( F_19 ( V_111 -> V_112 ) ) {
F_3 ( L_23 ,
F_20 ( V_111 -> V_112 ) ) ;
V_19 = F_20 ( V_111 -> V_112 ) ;
goto V_122;
}
V_111 -> V_113 = F_58 ( V_57 , V_121 ) ;
if ( F_19 ( V_111 -> V_113 ) ) {
F_3 ( L_24 ,
F_20 ( V_111 -> V_113 ) ) ;
V_19 = F_20 ( V_111 -> V_113 ) ;
goto V_123;
}
V_116 -> V_124 |= V_125 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_126 = 2 ;
V_119 . V_127 |= V_128 ;
V_111 -> V_114 = F_59 ( V_57 , & V_119 ) ;
if ( F_19 ( V_111 -> V_114 ) ) {
F_3 ( L_25 ,
F_20 ( V_111 -> V_114 ) ) ;
V_19 = F_20 ( V_111 -> V_114 ) ;
goto V_129;
}
V_116 -> V_111 = V_111 ;
V_116 -> V_124 |= V_130 ;
V_116 -> V_124 &= ~ V_131 ;
return 0 ;
V_129:
F_44 ( V_111 -> V_113 ) ;
V_123:
F_54 ( V_111 -> V_112 ) ;
V_122:
F_27 ( V_111 ) ;
return V_19 ;
}
static int
F_60 ( struct V_15 * V_15 , struct V_117 * V_57 ,
struct V_104 * V_105 )
{
int V_19 ;
V_105 -> V_109 = F_57 ( V_15 ,
V_121 ) ;
if ( F_19 ( V_105 -> V_109 ) ) {
F_3 ( L_26 ,
F_20 ( V_105 -> V_109 ) ) ;
return F_20 ( V_105 -> V_109 ) ;
}
V_105 -> V_110 = F_58 ( V_57 , V_121 ) ;
if ( F_19 ( V_105 -> V_110 ) ) {
F_3 ( L_27 ,
F_20 ( V_105 -> V_110 ) ) ;
V_19 = F_20 ( V_105 -> V_110 ) ;
goto V_132;
}
V_105 -> V_124 |= V_133 ;
F_8 ( L_28 , V_105 ) ;
return 0 ;
V_132:
F_54 ( V_105 -> V_109 ) ;
return V_19 ;
}
static int
F_61 ( struct V_1 * V_1 )
{
struct V_104 * V_105 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_134 * V_135 = V_1 -> V_2 -> V_136 -> V_135 ;
struct V_137 * V_138 = V_135 -> V_137 ;
int V_26 , V_19 , V_139 ;
V_139 = F_62 ( V_140 , V_141 , V_138 -> V_142 ) ;
V_139 = ( V_139 * 2 ) + V_143 ;
V_1 -> V_115 = 0 ;
for ( V_26 = 0 ; V_26 < V_139 ; V_26 ++ ) {
V_105 = F_23 ( sizeof( * V_105 ) , V_67 ) ;
if ( ! V_105 ) {
F_3 ( L_29 ) ;
V_19 = - V_77 ;
goto V_59;
}
V_19 = F_60 ( V_24 -> V_15 ,
V_24 -> V_57 , V_105 ) ;
if ( V_19 ) {
F_3 ( L_30 ,
V_19 ) ;
F_27 ( V_105 ) ;
goto V_59;
}
F_50 ( & V_105 -> V_108 , & V_1 -> V_107 ) ;
V_1 -> V_115 ++ ;
}
F_8 ( L_31 ,
V_1 , V_1 -> V_115 ) ;
return 0 ;
V_59:
F_51 ( V_1 ) ;
return V_19 ;
}
static void
F_63 ( struct V_1 * V_1 )
{
V_1 -> V_144 = V_145 ;
F_49 ( & V_1 -> V_146 ) ;
F_64 ( & V_1 -> V_147 ) ;
F_64 ( & V_1 -> V_148 ) ;
F_64 ( & V_1 -> V_149 ) ;
F_65 ( & V_1 -> V_150 ) ;
F_66 ( & V_1 -> V_151 ) ;
F_67 ( & V_1 -> V_152 ) ;
F_49 ( & V_1 -> V_107 ) ;
F_36 ( & V_1 -> V_153 , V_154 ) ;
}
static void
F_68 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_24 -> V_15 ;
F_26 ( V_16 , V_1 -> V_155 ,
V_156 , V_157 ) ;
F_26 ( V_16 , V_1 -> V_158 ,
V_159 ,
V_70 ) ;
F_27 ( V_1 -> V_160 ) ;
}
static int
F_69 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
int V_19 ;
V_1 -> V_160 = F_23 ( V_159 +
V_156 , V_67 ) ;
if ( ! V_1 -> V_160 ) {
F_3 ( L_32 ) ;
return - V_77 ;
}
V_1 -> V_161 = V_1 -> V_160 ;
V_1 -> V_162 = V_1 -> V_160 +
V_159 ;
F_8 ( L_33 ,
V_1 -> V_160 , V_1 -> V_161 ,
V_1 -> V_162 ) ;
V_1 -> V_158 = F_24 ( V_16 ,
( void * ) V_1 -> V_161 ,
V_159 , V_70 ) ;
V_19 = F_25 ( V_16 , V_1 -> V_158 ) ;
if ( V_19 ) {
F_3 ( L_34 , V_19 ) ;
V_1 -> V_158 = 0 ;
goto V_163;
}
V_1 -> V_155 = F_24 ( V_16 ,
( void * ) V_1 -> V_162 ,
V_156 , V_157 ) ;
V_19 = F_25 ( V_16 , V_1 -> V_155 ) ;
if ( V_19 ) {
F_3 ( L_35 , V_19 ) ;
V_1 -> V_155 = 0 ;
goto V_164;
}
return 0 ;
V_164:
F_26 ( V_16 , V_1 -> V_158 ,
V_159 , V_70 ) ;
V_163:
F_27 ( V_1 -> V_160 ) ;
return V_19 ;
}
static int
F_70 ( struct V_33 * V_34 , struct V_165 * V_11 )
{
struct V_166 * V_166 = V_34 -> V_10 ;
struct V_167 * V_168 = V_166 -> V_168 ;
struct V_1 * V_1 ;
struct V_23 * V_24 ;
int V_19 = 0 ;
F_71 ( & V_168 -> V_169 ) ;
if ( ! V_168 -> V_170 ) {
F_72 ( & V_168 -> V_169 ) ;
F_8 ( L_36 ) ;
return F_73 ( V_34 , NULL , 0 ) ;
}
F_72 ( & V_168 -> V_169 ) ;
F_8 ( L_37 ,
V_34 , V_34 -> V_10 ) ;
V_1 = F_23 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_1 )
return - V_77 ;
F_63 ( V_1 ) ;
V_1 -> V_13 = V_34 ;
V_19 = F_69 ( V_1 , V_34 -> V_24 ) ;
if ( V_19 )
goto V_171;
V_24 = F_47 ( V_34 ) ;
if ( F_19 ( V_24 ) ) {
V_19 = F_20 ( V_24 ) ;
goto V_172;
}
V_1 -> V_24 = V_24 ;
V_1 -> V_173 = F_33 ( V_174 ,
V_11 -> V_175 . V_2 . V_173 ,
V_24 -> V_48 . V_176 ) ;
F_8 ( L_38 , V_1 -> V_173 ) ;
V_19 = F_18 ( V_1 , V_34 ) ;
if ( V_19 )
goto V_177;
V_19 = F_74 ( V_1 ) ;
if ( V_19 )
goto V_177;
V_19 = F_75 ( V_1 ) ;
if ( V_19 )
goto V_177;
F_10 ( & V_166 -> V_178 ) ;
F_50 ( & V_1 -> V_146 , & V_166 -> V_179 ) ;
F_11 ( & V_166 -> V_178 ) ;
F_12 ( L_39 , V_168 ) ;
F_76 ( & V_166 -> V_180 ) ;
return 0 ;
V_177:
F_45 ( V_24 ) ;
V_172:
F_68 ( V_1 ) ;
V_171:
F_27 ( V_1 ) ;
F_73 ( V_34 , NULL , 0 ) ;
return V_19 ;
}
static void
F_77 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
F_8 ( L_40 , V_1 ) ;
F_78 ( ! V_24 ) ;
if ( V_24 -> V_83 )
F_51 ( V_1 ) ;
F_28 ( V_1 ) ;
if ( V_1 -> V_13 )
F_79 ( V_1 -> V_13 ) ;
if ( V_1 -> V_58 ) {
struct V_22 * V_25 = V_1 -> V_58 -> V_41 -> V_181 ;
F_13 ( V_25 ) ;
F_80 ( V_1 -> V_58 ) ;
}
if ( V_1 -> V_160 )
F_68 ( V_1 ) ;
F_45 ( V_24 ) ;
F_27 ( V_1 ) ;
}
static void
F_81 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
F_12 ( L_40 , V_1 ) ;
if ( ! F_82 ( & V_1 -> V_150 ) ) {
F_5 ( L_41 , V_1 ) ;
return;
}
F_10 ( & V_1 -> V_151 ) ;
if ( V_1 -> V_144 != V_182 )
V_1 -> V_144 = V_183 ;
F_11 ( & V_1 -> V_151 ) ;
}
static void
F_83 ( struct V_150 * V_150 )
{
struct V_1 * V_1 = F_84 ( V_150 ,
struct V_1 , V_150 ) ;
F_12 ( L_42 , V_1 , V_184 -> V_185 ,
V_184 -> V_186 ) ;
F_77 ( V_1 ) ;
}
static void
F_85 ( struct V_1 * V_1 )
{
F_86 ( & V_1 -> V_150 , F_83 ) ;
}
static void
F_87 ( struct V_1 * V_1 )
{
int V_59 ;
switch ( V_1 -> V_144 ) {
case V_187 :
break;
case V_183 :
case V_182 :
F_12 ( L_43 ,
V_1 , V_1 -> V_144 ) ;
V_1 -> V_144 = V_187 ;
V_59 = F_88 ( V_1 -> V_13 ) ;
if ( V_59 )
F_5 ( L_44 ,
V_1 ) ;
break;
default:
F_5 ( L_45 ,
V_1 , V_1 -> V_144 ) ;
}
}
static int
F_89 ( struct V_166 * V_166 ,
enum V_188 V_11 )
{
F_8 ( L_46 , V_166 , V_11 ) ;
switch ( V_11 ) {
case V_189 :
V_166 -> V_190 = NULL ;
break;
case V_191 :
V_166 -> V_190 = F_90 ( V_166 ) ;
if ( F_19 ( V_166 -> V_190 ) ) {
F_3 ( L_47 ,
V_166 , F_20 ( V_166 -> V_190 ) ) ;
V_166 -> V_190 = NULL ;
}
break;
default:
F_3 ( L_48 ,
V_166 , V_11 ) ;
}
return - 1 ;
}
static int
F_91 ( struct V_33 * V_34 ,
enum V_188 V_11 )
{
struct V_166 * V_166 = V_34 -> V_10 ;
struct V_1 * V_1 ;
bool V_192 = false ;
if ( V_166 -> V_190 == V_34 )
return F_89 ( V_34 -> V_10 , V_11 ) ;
V_1 = V_34 -> V_58 -> V_38 ;
F_10 ( & V_1 -> V_151 ) ;
V_192 = ( V_1 -> V_144 == V_187 ) ;
F_87 ( V_1 ) ;
F_11 ( & V_1 -> V_151 ) ;
F_12 ( L_49 , V_1 ) ;
F_92 ( & V_1 -> V_149 ) ;
if ( V_192 )
goto V_171;
F_10 ( & V_166 -> V_178 ) ;
if ( ! F_52 ( & V_1 -> V_146 ) ) {
F_93 ( & V_1 -> V_146 ) ;
F_85 ( V_1 ) ;
F_94 ( V_193 , & V_1 -> V_153 ) ;
}
F_11 ( & V_166 -> V_178 ) ;
V_171:
return 0 ;
}
static int
F_95 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
V_1 -> V_13 = NULL ;
F_85 ( V_1 ) ;
return - 1 ;
}
static int
F_96 ( struct V_33 * V_34 , struct V_165 * V_11 )
{
int V_19 = 0 ;
F_12 ( L_50 , V_11 -> V_11 ,
V_11 -> V_194 , V_34 , V_34 -> V_10 ) ;
switch ( V_11 -> V_11 ) {
case V_195 :
V_19 = F_70 ( V_34 , V_11 ) ;
if ( V_19 )
F_3 ( L_51 , V_19 ) ;
break;
case V_196 :
F_81 ( V_34 ) ;
break;
case V_191 :
case V_197 :
case V_189 :
case V_198 :
V_19 = F_91 ( V_34 , V_11 -> V_11 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
V_19 = F_95 ( V_34 ) ;
break;
default:
F_3 ( L_52 , V_11 -> V_11 ) ;
break;
}
return V_19 ;
}
static int
F_97 ( struct V_1 * V_1 , V_140 V_202 )
{
struct V_203 * V_204 , * V_205 ;
int V_26 , V_19 ;
unsigned int V_206 = V_1 -> V_76 ;
struct V_60 * V_61 ;
for ( V_204 = V_1 -> V_204 , V_26 = 0 ; V_26 < V_202 ; V_26 ++ , V_204 ++ ) {
V_61 = & V_1 -> V_66 [ V_206 ] ;
V_204 -> V_207 = ( V_208 ) V_61 ;
V_204 -> V_209 = & V_61 -> V_63 ;
V_204 -> V_210 = 1 ;
V_204 -> V_211 = V_204 + 1 ;
V_206 = ( V_206 + 1 ) & ( V_46 - 1 ) ;
}
V_204 -- ;
V_204 -> V_211 = NULL ;
V_1 -> V_212 += V_202 ;
V_19 = F_98 ( V_1 -> V_58 , V_1 -> V_204 ,
& V_205 ) ;
if ( V_19 ) {
F_3 ( L_53 , V_19 ) ;
V_1 -> V_212 -= V_202 ;
} else {
F_8 ( L_54 , V_202 ) ;
V_1 -> V_76 = V_206 ;
}
return V_19 ;
}
static int
F_99 ( struct V_1 * V_1 , struct V_213 * V_214 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_215 V_216 , * V_217 ;
int V_19 ;
F_100 ( V_16 , V_214 -> V_64 ,
V_218 , V_157 ) ;
V_216 . V_211 = NULL ;
V_216 . V_207 = ( V_208 ) V_214 ;
V_216 . V_209 = V_214 -> V_219 ;
V_216 . V_210 = V_214 -> V_210 ;
V_216 . V_220 = V_221 ;
V_216 . V_222 = V_223 ;
V_19 = F_101 ( V_1 -> V_58 , & V_216 , & V_217 ) ;
if ( V_19 )
F_3 ( L_55 , V_19 ) ;
return V_19 ;
}
static void
F_102 ( struct V_1 * V_1 ,
struct V_224 * V_224 ,
struct V_213 * V_214 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
F_103 ( V_16 , V_214 -> V_64 ,
V_218 , V_157 ) ;
memset ( & V_214 -> V_225 , 0 , sizeof( struct V_226 ) ) ;
V_214 -> V_225 . V_127 = V_227 ;
V_214 -> V_210 = 1 ;
V_214 -> V_224 = V_224 ;
if ( V_214 -> V_219 [ 0 ] . V_74 != V_24 -> V_75 -> V_74 ) {
V_214 -> V_219 [ 0 ] . V_74 = V_24 -> V_75 -> V_74 ;
F_8 ( L_56 , V_214 ) ;
}
}
static int
F_104 ( struct V_1 * V_1 ,
struct V_213 * V_214 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
T_1 V_64 ;
V_64 = F_24 ( V_16 , ( void * ) V_214 ,
V_218 , V_157 ) ;
if ( F_25 ( V_16 , V_64 ) ) {
F_3 ( L_57 ) ;
return - V_77 ;
}
V_214 -> V_64 = V_64 ;
V_214 -> V_219 [ 0 ] . V_72 = V_214 -> V_64 ;
V_214 -> V_219 [ 0 ] . V_73 = V_218 ;
V_214 -> V_219 [ 0 ] . V_74 = V_24 -> V_75 -> V_74 ;
F_8 ( L_58 ,
V_214 -> V_219 [ 0 ] . V_72 , V_214 -> V_219 [ 0 ] . V_73 ,
V_214 -> V_219 [ 0 ] . V_74 ) ;
return 0 ;
}
static void
F_105 ( struct V_1 * V_1 , struct V_224 * V_224 ,
struct V_215 * V_216 )
{
struct V_213 * V_214 = & V_224 -> V_214 ;
V_224 -> V_228 . V_229 = V_230 ;
V_216 -> V_207 = ( V_208 ) & V_224 -> V_214 ;
V_216 -> V_220 = V_221 ;
V_216 -> V_209 = & V_214 -> V_219 [ 0 ] ;
V_216 -> V_210 = V_224 -> V_214 . V_210 ;
V_216 -> V_222 = V_223 ;
}
static int
F_74 ( struct V_1 * V_1 )
{
struct V_203 V_204 , * V_231 ;
struct V_62 V_232 ;
int V_19 ;
memset ( & V_232 , 0 , sizeof( struct V_62 ) ) ;
V_232 . V_72 = V_1 -> V_158 ;
V_232 . V_73 = V_156 ;
V_232 . V_74 = V_1 -> V_24 -> V_75 -> V_74 ;
F_8 ( L_59 ,
V_232 . V_72 , V_232 . V_73 , V_232 . V_74 ) ;
memset ( & V_204 , 0 , sizeof( struct V_203 ) ) ;
V_204 . V_207 = ( V_208 ) V_1 -> V_161 ;
V_204 . V_209 = & V_232 ;
V_204 . V_210 = 1 ;
V_1 -> V_212 ++ ;
V_19 = F_98 ( V_1 -> V_58 , & V_204 , & V_231 ) ;
if ( V_19 ) {
F_3 ( L_60 , V_19 ) ;
V_1 -> V_212 -- ;
}
return V_19 ;
}
static int
F_106 ( struct V_233 * V_2 , struct V_234 * V_235 ,
V_140 V_73 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_213 * V_214 = & V_1 -> V_236 ;
int V_19 ;
F_102 ( V_1 , NULL , V_214 ) ;
memcpy ( & V_214 -> V_237 , & V_235 -> V_238 [ 0 ] ,
sizeof( struct V_239 ) ) ;
F_104 ( V_1 , V_214 ) ;
if ( V_73 > 0 ) {
struct V_62 * V_240 = & V_214 -> V_219 [ 1 ] ;
F_103 ( V_16 , V_1 -> V_155 ,
V_73 , V_157 ) ;
memcpy ( V_1 -> V_162 , V_235 -> V_241 , V_73 ) ;
F_100 ( V_16 , V_1 -> V_155 ,
V_73 , V_157 ) ;
V_240 -> V_72 = V_1 -> V_155 ;
V_240 -> V_73 = V_73 ;
V_240 -> V_74 = V_1 -> V_24 -> V_75 -> V_74 ;
V_214 -> V_210 = 2 ;
}
if ( ! V_235 -> V_242 ) {
if ( V_235 -> V_243 ) {
if ( ! V_2 -> V_136 -> V_244 -> V_245 &&
V_1 -> V_24 -> V_83 ) {
V_19 = F_61 ( V_1 ) ;
if ( V_19 ) {
F_3 ( L_61
L_62 , V_1 ) ;
return V_19 ;
}
}
V_19 = F_22 ( V_1 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_97 ( V_1 , V_246 ) ;
if ( V_19 )
return V_19 ;
F_10 ( & V_1 -> V_151 ) ;
V_1 -> V_144 = V_182 ;
F_11 ( & V_1 -> V_151 ) ;
goto V_247;
}
V_19 = F_74 ( V_1 ) ;
if ( V_19 )
return V_19 ;
}
V_247:
V_19 = F_99 ( V_1 , V_214 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void
F_107 ( struct V_1 * V_1 )
{
struct V_60 * V_61 = ( void * ) V_1 -> V_161 ;
int V_248 = V_1 -> V_249 ;
struct V_233 * V_2 = V_1 -> V_2 ;
struct V_234 * V_235 = V_2 -> V_250 ;
int V_251 ;
F_12 ( L_40 , V_1 ) ;
F_108 ( ! V_235 ) ;
if ( V_235 -> V_252 ) {
struct V_253 * V_254 =
(struct V_253 * ) & V_61 -> V_237 ;
V_235 -> V_255 = ( ! V_254 -> V_256 ) ? 1 : 0 ;
V_235 -> V_257 =
( V_254 -> V_127 & V_258 )
>> 2 ;
V_235 -> V_259 = V_254 -> V_260 ;
V_235 -> V_261 = V_254 -> V_262 ;
memcpy ( V_235 -> V_263 , V_254 -> V_263 , 6 ) ;
V_235 -> V_264 = F_109 ( V_254 -> V_265 ) ;
V_235 -> V_266 = V_254 -> V_267 ;
V_235 -> V_268 = F_109 ( V_254 -> V_269 ) ;
V_235 -> V_270 = F_110 ( V_254 -> V_270 ) ;
V_235 -> V_256 = F_110 ( V_254 -> V_256 ) ;
}
memcpy ( & V_235 -> V_271 [ 0 ] , ( void * ) & V_61 -> V_237 , V_272 ) ;
V_251 = V_27 ( V_248 , V_273 ) ;
F_8 ( L_63
L_64 , V_251 , V_248 ,
V_273 ) ;
memcpy ( V_235 -> V_274 , & V_61 -> V_275 [ 0 ] , V_251 ) ;
if ( V_235 -> V_252 ) {
F_92 ( & V_1 -> V_147 ) ;
return;
}
F_111 ( & V_2 -> V_276 , 0 ) ;
}
static struct V_277
* F_112 ( struct V_233 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_224 * V_224 ;
struct V_277 * V_4 ;
V_4 = F_113 ( V_2 , V_278 ) ;
if ( ! V_4 ) {
F_3 ( L_65 ) ;
return NULL ;
}
V_224 = F_114 ( V_4 ) ;
V_224 -> V_2 = V_1 ;
V_224 -> V_277 = V_4 ;
return V_4 ;
}
static int
F_115 ( struct V_1 * V_1 ,
struct V_224 * V_224 , struct V_277 * V_4 ,
struct V_60 * V_61 , unsigned char * V_279 )
{
struct V_233 * V_2 = V_1 -> V_2 ;
struct V_280 * V_281 = (struct V_280 * ) V_279 ;
struct V_282 * V_283 ;
int V_284 , V_285 , V_286 , V_287 , V_288 ;
bool V_289 = false ;
V_288 = F_116 ( V_2 , V_4 , V_279 ) ;
if ( V_288 < 0 )
return V_288 ;
V_284 = V_4 -> V_290 ;
V_285 = V_4 -> V_291 ;
V_286 = V_4 -> V_292 ;
V_288 = F_117 ( V_2 , V_4 , V_281 ) ;
if ( V_288 < 0 ) {
return 0 ;
} else if ( V_288 > 0 ) {
V_289 = true ;
goto V_293;
}
if ( ! V_284 )
return 0 ;
V_283 = & V_4 -> V_3 . V_294 [ 0 ] ;
V_287 = F_15 ( 1UL , F_118 ( V_285 , V_295 ) ) ;
F_8 ( L_66 ,
V_283 , V_287 , & V_61 -> V_275 [ 0 ] , V_285 ) ;
F_119 ( V_283 , V_287 , & V_61 -> V_275 [ 0 ] , V_285 ) ;
V_4 -> V_296 += V_285 ;
if ( V_4 -> V_296 == V_4 -> V_3 . V_297 ) {
F_71 ( & V_4 -> V_298 ) ;
V_4 -> V_299 |= V_300 ;
V_4 -> V_301 = V_302 ;
F_72 ( & V_4 -> V_298 ) ;
}
V_293:
V_288 = F_120 ( V_2 , V_4 , V_279 , V_281 -> V_265 ) ;
if ( ! V_288 && V_289 == false && V_286 )
F_121 ( V_4 ) ;
else if ( V_289 && V_284 )
F_122 ( V_2 -> V_136 -> V_135 , & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_123 ( struct V_1 * V_1 ,
struct V_60 * V_61 , unsigned char * V_279 )
{
struct V_282 * V_303 ;
struct V_233 * V_2 = V_1 -> V_2 ;
struct V_277 * V_4 = NULL ;
struct V_304 * V_281 = (struct V_304 * ) V_279 ;
V_140 V_305 = F_124 ( V_281 -> V_306 ) ;
int V_288 , V_287 , V_307 , V_308 ;
V_288 = F_125 ( V_2 , V_279 , & V_4 ) ;
if ( V_288 < 0 )
return V_288 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_292 ) {
F_3 ( L_67 ) ;
F_126 () ;
return - 1 ;
}
F_8 ( L_68
L_69 ,
V_305 , V_4 -> V_296 ,
V_4 -> V_3 . V_297 ) ;
V_307 = V_4 -> V_296 / V_295 ;
V_303 = & V_4 -> V_3 . V_294 [ V_307 ] ;
V_287 = F_15 ( 1UL , F_118 ( V_305 , V_295 ) ) ;
V_308 = V_4 -> V_296 % V_295 ;
if ( V_308 ) {
F_3 ( L_70 ) ;
F_126 () ;
return - 1 ;
}
F_8 ( L_71
L_72 , V_303 , V_307 ,
V_287 , & V_61 -> V_275 [ 0 ] , V_305 ) ;
F_119 ( V_303 , V_287 , & V_61 -> V_275 [ 0 ] ,
V_305 ) ;
V_288 = F_127 ( V_4 , V_281 , false ) ;
if ( V_288 < 0 )
return V_288 ;
return 0 ;
}
static int
F_128 ( struct V_1 * V_1 , struct V_224 * V_224 ,
struct V_277 * V_4 , struct V_60 * V_61 ,
unsigned char * V_279 )
{
struct V_233 * V_2 = V_1 -> V_2 ;
struct V_309 * V_281 = (struct V_309 * ) V_279 ;
int V_288 ;
V_288 = F_129 ( V_2 , V_4 , V_281 ) ;
if ( V_288 < 0 )
return V_288 ;
return F_130 ( V_2 , V_4 , V_281 ) ;
}
static int
F_131 ( struct V_1 * V_1 , struct V_224 * V_224 ,
struct V_277 * V_4 , struct V_60 * V_61 ,
struct V_310 * V_281 )
{
struct V_233 * V_2 = V_1 -> V_2 ;
V_140 V_311 = F_124 ( V_281 -> V_306 ) ;
int V_288 ;
unsigned char * V_312 = NULL ;
V_288 = F_132 ( V_2 , V_4 , V_281 ) ;
if ( V_288 < 0 )
return V_288 ;
if ( V_311 ) {
V_312 = F_23 ( V_311 , V_67 ) ;
if ( ! V_312 ) {
F_3 ( L_73 ,
V_311 ) ;
return - V_77 ;
}
}
V_4 -> V_313 = V_312 ;
memcpy ( V_4 -> V_313 , & V_61 -> V_275 [ 0 ] , V_311 ) ;
return F_133 ( V_2 , V_4 , V_281 ) ;
}
static int
F_134 ( struct V_1 * V_1 , struct V_60 * V_61 ,
T_2 V_314 , T_3 V_315 ,
T_2 V_316 , T_3 V_317 )
{
struct V_239 * V_281 = & V_61 -> V_237 ;
struct V_233 * V_2 = V_1 -> V_2 ;
struct V_277 * V_4 ;
struct V_224 * V_224 ;
int V_19 = - V_318 ;
V_174 V_220 = ( V_281 -> V_220 & V_319 ) ;
if ( V_2 -> V_136 -> V_244 -> V_245 &&
( ! ( V_220 & V_320 ) || ! ( V_220 & V_321 ) ) ) {
F_3 ( L_74
L_75 , V_220 ) ;
return 0 ;
}
switch ( V_220 ) {
case V_322 :
V_4 = F_112 ( V_2 ) ;
if ( ! V_4 )
break;
V_224 = F_114 ( V_4 ) ;
V_224 -> V_314 = V_314 ;
V_224 -> V_315 = V_315 ;
V_224 -> V_316 = V_316 ;
V_224 -> V_317 = V_317 ;
V_19 = F_115 ( V_1 , V_224 , V_4 ,
V_61 , ( unsigned char * ) V_281 ) ;
break;
case V_323 :
V_4 = F_112 ( V_2 ) ;
if ( ! V_4 )
break;
V_224 = F_114 ( V_4 ) ;
V_19 = F_128 ( V_1 , V_224 , V_4 ,
V_61 , ( unsigned char * ) V_281 ) ;
break;
case V_324 :
V_19 = F_123 ( V_1 , V_61 ,
( unsigned char * ) V_281 ) ;
break;
case V_325 :
V_4 = F_112 ( V_2 ) ;
if ( ! V_4 )
break;
V_19 = F_135 ( V_2 , V_4 ,
( unsigned char * ) V_281 ) ;
break;
case V_321 :
V_4 = F_112 ( V_2 ) ;
if ( ! V_4 )
break;
V_19 = F_136 ( V_2 , V_4 , ( unsigned char * ) V_281 ) ;
break;
case V_320 :
if ( F_109 ( V_281 -> V_326 ) != 0xFFFFFFFF ) {
V_4 = F_137 ( V_2 , V_281 -> V_267 ) ;
if ( ! V_4 )
break;
} else {
V_4 = F_112 ( V_2 ) ;
if ( ! V_4 )
break;
}
V_224 = F_114 ( V_4 ) ;
V_19 = F_131 ( V_1 , V_224 , V_4 ,
V_61 , (struct V_310 * ) V_281 ) ;
break;
default:
F_3 ( L_76 , V_220 ) ;
F_126 () ;
break;
}
return V_19 ;
}
static void
F_138 ( struct V_60 * V_61 , struct V_1 * V_1 )
{
struct V_226 * V_226 = & V_61 -> V_225 ;
T_3 V_315 = 0 , V_317 = 0 ;
T_2 V_314 = 0 , V_316 = 0 ;
int V_288 ;
switch ( V_226 -> V_127 & 0xF0 ) {
case V_327 :
if ( V_226 -> V_127 & V_328 ) {
V_314 = F_109 ( V_226 -> V_314 ) ;
V_315 = F_139 ( V_226 -> V_315 ) ;
F_8 ( L_77 ,
V_314 , ( unsigned long long ) V_315 ) ;
}
if ( V_226 -> V_127 & V_329 ) {
V_316 = F_109 ( V_226 -> V_316 ) ;
V_317 = F_139 ( V_226 -> V_317 ) ;
F_8 ( L_78 ,
V_316 , ( unsigned long long ) V_317 ) ;
}
F_8 ( L_79 ) ;
break;
case V_330 :
F_3 ( L_80 ) ;
break;
default:
F_5 ( L_81 , V_226 -> V_127 ) ;
break;
}
V_288 = F_134 ( V_1 , V_61 ,
V_314 , V_315 , V_316 , V_317 ) ;
}
static void
F_140 ( struct V_60 * V_116 ,
struct V_1 * V_1 ,
V_140 V_331 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_239 * V_281 ;
T_1 V_332 ;
int V_248 , V_333 ;
if ( ( char * ) V_116 == V_1 -> V_161 ) {
V_332 = V_1 -> V_158 ;
V_248 = V_156 ;
F_8 ( L_82 ,
V_332 , V_248 ) ;
} else {
V_332 = V_116 -> V_64 ;
V_248 = V_69 ;
F_8 ( L_83 ,
V_332 , V_248 ) ;
}
F_103 ( V_16 , V_332 , V_248 , V_70 ) ;
V_281 = & V_116 -> V_237 ;
F_8 ( L_84 ,
V_281 -> V_220 , V_281 -> V_267 , V_281 -> V_127 ,
( int ) ( V_331 - V_218 ) ) ;
if ( ( char * ) V_116 == V_1 -> V_161 ) {
V_1 -> V_249 = V_331 - V_218 ;
if ( V_1 -> V_2 ) {
struct V_234 * V_235 = V_1 -> V_2 -> V_250 ;
if ( V_235 && ! V_235 -> V_252 )
F_107 ( V_1 ) ;
}
F_10 ( & V_1 -> V_151 ) ;
F_92 ( & V_1 -> V_148 ) ;
F_11 ( & V_1 -> V_151 ) ;
} else {
F_138 ( V_116 , V_1 ) ;
}
F_100 ( V_16 , V_332 , V_248 ,
V_70 ) ;
V_1 -> V_212 -- ;
F_8 ( L_85 ,
V_1 -> V_212 ) ;
if ( ( char * ) V_116 == V_1 -> V_161 )
return;
V_333 = V_1 -> V_212 ;
if ( V_333 + V_246 <= V_46 ) {
int V_59 , V_202 = V_27 ( V_46 - V_333 ,
V_246 ) ;
V_59 = F_97 ( V_1 , V_202 ) ;
if ( V_59 ) {
F_3 ( L_86 ,
V_202 , V_59 ) ;
}
}
}
static int
F_141 ( struct V_1 * V_1 , struct V_224 * V_224 ,
struct V_282 * V_283 , V_140 V_334 , V_140 V_73 , V_140 V_335 ,
enum V_336 V_337 , struct V_338 * V_275 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
V_275 -> V_339 = V_337 == V_340 ?
V_157 : V_70 ;
V_275 -> V_341 = V_73 - V_335 ;
V_275 -> V_335 = V_335 ;
V_275 -> V_307 = V_275 -> V_335 / V_295 ;
V_275 -> V_283 = & V_283 [ V_275 -> V_307 ] ;
V_275 -> V_334 = F_33 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_275 -> V_341 = F_33 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_275 -> V_342 = F_142 ( V_16 , V_275 -> V_283 , V_275 -> V_334 ,
V_275 -> V_339 ) ;
if ( F_143 ( ! V_275 -> V_342 ) ) {
F_3 ( L_87 , V_283 ) ;
return - V_318 ;
}
F_8 ( L_88 ,
V_224 , V_275 -> V_342 , V_275 -> V_283 , V_275 -> V_334 , V_275 -> V_341 ) ;
return 0 ;
}
static void
F_144 ( struct V_1 * V_1 , struct V_338 * V_275 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
F_145 ( V_16 , V_275 -> V_283 , V_275 -> V_334 , V_275 -> V_339 ) ;
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
}
static void
V_97 ( struct V_224 * V_224 , struct V_1 * V_1 )
{
struct V_343 * V_344 = & V_224 -> V_228 ;
F_8 ( L_89 , V_224 ) ;
if ( V_344 -> V_275 . V_283 ) {
F_8 ( L_90 , V_224 ) ;
F_144 ( V_1 , & V_344 -> V_275 ) ;
}
if ( V_344 -> V_216 ) {
F_8 ( L_91 , V_224 ) ;
F_27 ( V_344 -> V_216 ) ;
V_344 -> V_216 = NULL ;
}
if ( V_344 -> V_62 ) {
F_8 ( L_92 , V_224 ) ;
F_27 ( V_344 -> V_62 ) ;
V_344 -> V_62 = NULL ;
}
}
static void
V_95 ( struct V_224 * V_224 , struct V_1 * V_1 )
{
struct V_343 * V_344 = & V_224 -> V_228 ;
F_8 ( L_89 , V_224 ) ;
if ( V_344 -> V_105 ) {
F_8 ( L_93 , V_224 , V_344 -> V_105 ) ;
if ( V_344 -> V_105 -> V_124 & V_131 ) {
F_144 ( V_1 , & V_344 -> V_345 ) ;
V_344 -> V_105 -> V_124 &= ~ V_131 ;
}
F_71 ( & V_1 -> V_152 ) ;
F_50 ( & V_344 -> V_105 -> V_108 , & V_1 -> V_107 ) ;
F_72 ( & V_1 -> V_152 ) ;
V_344 -> V_105 = NULL ;
}
if ( V_344 -> V_275 . V_283 ) {
F_8 ( L_90 , V_224 ) ;
F_144 ( V_1 , & V_344 -> V_275 ) ;
}
V_344 -> V_62 = NULL ;
V_344 -> V_216 = NULL ;
}
static void
F_146 ( struct V_224 * V_224 , bool V_346 )
{
struct V_277 * V_4 = V_224 -> V_277 ;
struct V_1 * V_1 = V_224 -> V_2 ;
struct V_233 * V_2 = V_1 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_347 * V_281 ;
F_8 ( L_89 , V_224 ) ;
switch ( V_4 -> V_348 ) {
case V_322 :
F_71 ( & V_2 -> V_349 ) ;
if ( ! F_52 ( & V_4 -> V_350 ) )
F_93 ( & V_4 -> V_350 ) ;
F_72 ( & V_2 -> V_349 ) ;
if ( V_4 -> V_351 == V_157 ) {
F_147 ( V_4 ) ;
if ( V_346 &&
V_4 -> V_3 . V_352 == V_353 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_122 ( V_3 -> V_135 , V_3 ) ;
}
}
V_24 -> V_94 ( V_224 , V_1 ) ;
F_148 ( & V_4 -> V_3 , 0 ) ;
break;
case V_325 :
F_71 ( & V_2 -> V_349 ) ;
if ( ! F_52 ( & V_4 -> V_350 ) )
F_93 ( & V_4 -> V_350 ) ;
F_72 ( & V_2 -> V_349 ) ;
F_148 ( & V_4 -> V_3 , 0 ) ;
break;
case V_354 :
case V_323 :
case V_320 :
V_281 = (struct V_347 * ) & V_224 -> V_214 . V_237 ;
if ( V_281 -> V_127 & V_355 )
break;
F_71 ( & V_2 -> V_349 ) ;
if ( ! F_52 ( & V_4 -> V_350 ) )
F_93 ( & V_4 -> V_350 ) ;
F_72 ( & V_2 -> V_349 ) ;
if ( V_4 -> V_3 . V_356 != NULL ) {
F_8 ( L_94 ,
V_4 -> V_348 ) ;
F_148 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_149 ( V_4 ) ;
break;
}
}
static void
F_150 ( struct V_213 * V_214 , struct V_15 * V_16 )
{
if ( V_214 -> V_64 != 0 ) {
F_8 ( L_95 ) ;
F_26 ( V_16 , V_214 -> V_64 ,
V_218 , V_157 ) ;
V_214 -> V_64 = 0 ;
}
}
static void
F_151 ( struct V_213 * V_214 , struct V_224 * V_224 ,
struct V_15 * V_16 , bool V_346 )
{
if ( V_224 -> V_357 != 0 ) {
F_8 ( L_96 ) ;
F_26 ( V_16 , V_224 -> V_357 ,
V_224 -> V_358 , V_157 ) ;
V_224 -> V_357 = 0 ;
}
F_150 ( V_214 , V_16 ) ;
F_146 ( V_224 , V_346 ) ;
}
static int
F_152 ( struct V_3 * V_3 , struct V_359 * V_114 )
{
struct V_360 V_361 ;
int V_19 ;
V_19 = F_153 ( V_114 , V_362 , & V_361 ) ;
if ( V_19 ) {
F_3 ( L_97 , V_19 ) ;
goto V_363;
}
if ( V_361 . V_364 & V_362 ) {
T_1 V_365 ;
V_140 V_366 = V_3 -> V_367 -> V_368 . V_366 + 8 ;
switch ( V_361 . V_369 . V_370 ) {
case V_371 :
V_3 -> V_372 = V_373 ;
break;
case V_374 :
V_3 -> V_372 = V_375 ;
break;
case V_376 :
V_3 -> V_372 = V_377 ;
break;
}
V_365 = V_361 . V_369 . V_378 ;
F_154 ( V_365 , V_366 ) ;
V_3 -> V_379 = V_365 + V_3 -> V_380 ;
F_3 ( L_98
L_99 ,
V_361 . V_369 . V_370 ,
( unsigned long long ) V_3 -> V_379 ,
V_361 . V_369 . V_381 ,
V_361 . V_369 . V_382 ) ;
V_19 = 1 ;
}
V_363:
return V_19 ;
}
static void
F_155 ( struct V_213 * V_214 ,
struct V_224 * V_224 )
{
struct V_343 * V_344 = & V_224 -> V_228 ;
struct V_277 * V_4 = V_224 -> V_277 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_224 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_344 -> V_105 && V_344 -> V_105 -> V_124 & V_131 ) {
V_19 = F_152 ( V_3 ,
V_344 -> V_105 -> V_111 -> V_114 ) ;
V_344 -> V_105 -> V_124 &= ~ V_131 ;
}
V_24 -> V_94 ( V_224 , V_1 ) ;
V_344 -> V_383 = 0 ;
if ( V_19 )
F_156 ( V_3 ,
V_3 -> V_372 , 0 ) ;
else
F_157 ( V_1 -> V_2 , V_4 ) ;
}
static void
F_158 ( struct V_213 * V_214 ,
struct V_224 * V_224 )
{
struct V_343 * V_344 = & V_224 -> V_228 ;
struct V_277 * V_4 = V_224 -> V_277 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_224 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_344 -> V_105 && V_344 -> V_105 -> V_124 & V_131 ) {
V_19 = F_152 ( V_3 ,
V_344 -> V_105 -> V_111 -> V_114 ) ;
V_344 -> V_105 -> V_124 &= ~ V_131 ;
}
F_147 ( V_4 ) ;
V_24 -> V_94 ( V_224 , V_1 ) ;
V_4 -> V_296 = V_344 -> V_275 . V_341 ;
V_344 -> V_383 = 0 ;
F_8 ( L_100 , V_224 ) ;
F_71 ( & V_4 -> V_298 ) ;
V_4 -> V_299 |= V_300 ;
V_4 -> V_301 = V_302 ;
F_72 ( & V_4 -> V_298 ) ;
if ( V_19 ) {
F_122 ( V_3 -> V_135 , V_3 ) ;
F_156 ( V_3 ,
V_3 -> V_372 , 0 ) ;
} else {
F_159 ( V_3 ) ;
}
}
static void
F_160 ( struct V_384 * V_78 )
{
struct V_224 * V_224 = F_84 ( V_78 ,
struct V_224 , V_385 ) ;
struct V_1 * V_1 = V_224 -> V_2 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_277 * V_4 = V_224 -> V_277 ;
F_8 ( L_101 , V_224 , V_4 -> V_301 ) ;
switch ( V_4 -> V_301 ) {
case V_386 :
F_161 ( V_4 , V_4 -> V_2 ) ;
case V_387 :
case V_388 :
V_4 -> V_301 = V_389 ;
F_151 ( & V_224 -> V_214 , V_224 ,
V_16 , false ) ;
break;
case V_390 :
F_162 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_102 , V_4 -> V_301 ) ;
F_126 () ;
break;
}
}
static void
F_163 ( struct V_213 * V_214 ,
struct V_224 * V_224 ,
struct V_1 * V_1 ,
struct V_15 * V_16 )
{
struct V_277 * V_4 = V_224 -> V_277 ;
if ( V_4 -> V_301 == V_386 ||
V_4 -> V_301 == V_390 ||
V_4 -> V_301 == V_387 ||
V_4 -> V_301 == V_388 ) {
F_150 ( V_214 , V_16 ) ;
F_36 ( & V_224 -> V_385 , F_160 ) ;
F_94 ( V_391 , & V_224 -> V_385 ) ;
return;
}
V_4 -> V_301 = V_389 ;
F_151 ( V_214 , V_224 , V_16 , false ) ;
}
static void
F_164 ( struct V_213 * V_214 ,
struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_224 * V_224 = V_214 -> V_224 ;
struct V_343 * V_344 ;
if ( ! V_224 ) {
F_150 ( V_214 , V_16 ) ;
return;
}
V_344 = & V_224 -> V_228 ;
F_8 ( L_103 , V_224 , V_344 -> V_229 ) ;
switch ( V_344 -> V_229 ) {
case V_230 :
F_163 ( V_214 , V_224 ,
V_1 , V_16 ) ;
break;
case V_340 :
F_155 ( V_214 , V_224 ) ;
break;
case V_392 :
F_158 ( V_214 , V_224 ) ;
break;
default:
F_3 ( L_104 , V_344 -> V_229 ) ;
F_126 () ;
break;
}
}
static inline bool
F_165 ( struct V_1 * V_1 , void * V_207 )
{
void * V_393 = V_1 -> V_66 ;
int V_341 = V_46 * sizeof( * V_1 -> V_66 ) ;
if ( V_207 >= V_393 && V_207 < V_393 + V_341 )
return false ;
return true ;
}
static void
F_166 ( struct V_1 * V_1 , struct V_394 * V_395 )
{
if ( V_395 -> V_207 == V_396 ) {
F_12 ( L_105 ,
V_1 ) ;
F_92 ( & V_1 -> V_397 ) ;
} else if ( F_165 ( V_1 , ( void * ) ( V_208 ) V_395 -> V_207 ) ) {
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_224 * V_224 ;
struct V_213 * V_116 ;
V_116 = (struct V_213 * ) ( V_208 ) V_395 -> V_207 ;
V_224 = V_116 -> V_224 ;
if ( ! V_224 )
F_150 ( V_116 , V_16 ) ;
else
F_151 ( V_116 , V_224 , V_16 , true ) ;
} else {
V_1 -> V_212 -- ;
if ( ! V_1 -> V_212 )
F_167 ( V_1 -> V_2 , 0 ) ;
}
}
static void
F_168 ( struct V_394 * V_395 )
{
struct V_1 * V_1 ;
struct V_213 * V_214 ;
struct V_60 * V_61 ;
V_1 = V_395 -> V_58 -> V_38 ;
if ( F_169 ( V_395 -> V_194 == V_398 ) ) {
if ( V_395 -> V_220 == V_399 ) {
V_61 = (struct V_60 * ) ( V_208 ) V_395 -> V_207 ;
F_140 ( V_61 , V_1 , V_395 -> V_400 ) ;
} else {
V_214 = (struct V_213 * ) ( V_208 ) V_395 -> V_207 ;
F_164 ( V_214 , V_1 ) ;
}
} else {
if ( V_395 -> V_194 != V_401 )
F_3 ( L_106 ,
V_395 -> V_207 , V_395 -> V_194 , V_395 -> V_402 ) ;
else
F_8 ( L_107 , V_395 -> V_207 ) ;
if ( V_395 -> V_207 != V_403 )
F_166 ( V_1 , V_395 ) ;
}
}
static void
V_85 ( struct V_384 * V_78 )
{
enum { V_404 = 65536 };
struct V_22 * V_25 = F_84 ( V_78 , struct V_22 ,
V_78 ) ;
struct V_394 * const V_405 = V_25 -> V_405 ;
int V_26 , V_406 , V_407 = 0 ;
while ( ( V_406 = F_170 ( V_25 -> V_40 , F_171 ( V_25 -> V_405 ) , V_405 ) ) > 0 ) {
for ( V_26 = 0 ; V_26 < V_406 ; V_26 ++ )
F_168 ( & V_405 [ V_26 ] ) ;
V_407 += V_406 ;
if ( V_407 >= V_404 )
break;
}
F_38 ( V_25 -> V_40 , V_88 ) ;
}
static void
V_86 ( struct V_408 * V_40 , void * V_10 )
{
struct V_22 * V_25 = V_10 ;
F_94 ( V_391 , & V_25 -> V_78 ) ;
}
static int
F_172 ( struct V_1 * V_1 , struct V_224 * V_224 )
{
struct V_215 * V_409 ;
int V_19 ;
V_19 = F_101 ( V_1 -> V_58 , & V_224 -> V_214 . V_216 ,
& V_409 ) ;
if ( V_19 ) {
F_3 ( L_108 , V_19 ) ;
return V_19 ;
}
return V_19 ;
}
static int
F_157 ( struct V_233 * V_2 , struct V_277 * V_4 )
{
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_215 * V_216 = & V_224 -> V_214 . V_216 ;
struct V_410 * V_281 = (struct V_410 * )
& V_224 -> V_214 . V_237 ;
F_102 ( V_1 , V_224 , & V_224 -> V_214 ) ;
F_173 ( V_4 , V_2 , true , V_281 ) ;
F_104 ( V_1 , & V_224 -> V_214 ) ;
if ( V_4 -> V_3 . V_411 &&
( ( V_4 -> V_3 . V_412 & V_413 ) ||
( V_4 -> V_3 . V_412 & V_414 ) ) ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_240 = & V_224 -> V_214 . V_219 [ 1 ] ;
V_140 V_415 , V_416 ;
F_174 ( V_4 -> V_3 . V_417 ,
V_4 -> V_411 ) ;
V_4 -> V_3 . V_417 += sizeof( V_418 ) ;
V_415 = - ( V_4 -> V_3 . V_417 ) & 3 ;
F_175 ( V_281 -> V_306 , ( V_140 ) V_4 -> V_3 . V_417 ) ;
V_416 = V_4 -> V_3 . V_417 + V_415 ;
V_224 -> V_357 = F_24 ( V_16 ,
( void * ) V_4 -> V_411 , V_416 ,
V_157 ) ;
V_224 -> V_358 = V_416 ;
V_240 -> V_72 = V_224 -> V_357 ;
V_240 -> V_73 = V_416 ;
V_240 -> V_74 = V_24 -> V_75 -> V_74 ;
V_224 -> V_214 . V_210 = 2 ;
}
F_105 ( V_1 , V_224 , V_216 ) ;
F_8 ( L_109 ) ;
return F_172 ( V_1 , V_224 ) ;
}
static void
F_176 ( struct V_233 * V_2 , struct V_277 * V_4 )
{
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
F_71 ( & V_2 -> V_349 ) ;
if ( ! F_52 ( & V_4 -> V_350 ) )
F_93 ( & V_4 -> V_350 ) ;
F_72 ( & V_2 -> V_349 ) ;
if ( V_4 -> V_351 == V_157 )
F_147 ( V_4 ) ;
V_24 -> V_94 ( V_224 , V_1 ) ;
}
static enum V_419
F_177 ( struct V_233 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
if ( V_2 -> V_420 -> V_421 . V_422 ) {
if ( V_24 -> V_54 ) {
F_12 ( L_110 , V_1 ) ;
V_1 -> V_5 = true ;
return V_423 ;
}
}
F_12 ( L_111 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_178 ( struct V_277 * V_4 , struct V_233 * V_2 ,
bool V_424 )
{
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_215 * V_216 = & V_224 -> V_214 . V_216 ;
F_102 ( V_1 , V_224 , & V_224 -> V_214 ) ;
F_179 ( V_4 , V_2 , (struct V_425 * )
& V_224 -> V_214 . V_237 ,
V_424 ) ;
F_104 ( V_1 , & V_224 -> V_214 ) ;
F_105 ( V_1 , V_224 , V_216 ) ;
F_8 ( L_112 , V_1 ) ;
return F_172 ( V_1 , V_224 ) ;
}
static int
F_180 ( struct V_277 * V_4 , struct V_233 * V_2 )
{
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_215 * V_216 = & V_224 -> V_214 . V_216 ;
F_102 ( V_1 , V_224 , & V_224 -> V_214 ) ;
F_181 ( V_4 , V_2 , (struct V_426 * )
& V_224 -> V_214 . V_237 ) ;
F_104 ( V_1 , & V_224 -> V_214 ) ;
F_105 ( V_1 , V_224 , V_216 ) ;
F_8 ( L_113 , V_1 ) ;
return F_172 ( V_1 , V_224 ) ;
}
static int
F_182 ( struct V_277 * V_4 , struct V_233 * V_2 )
{
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_215 * V_216 = & V_224 -> V_214 . V_216 ;
F_102 ( V_1 , V_224 , & V_224 -> V_214 ) ;
F_183 ( V_4 , V_2 , (struct V_427 * )
& V_224 -> V_214 . V_237 ) ;
F_104 ( V_1 , & V_224 -> V_214 ) ;
F_105 ( V_1 , V_224 , V_216 ) ;
F_8 ( L_114 , V_1 ) ;
return F_172 ( V_1 , V_224 ) ;
}
static int
F_184 ( struct V_277 * V_4 , struct V_233 * V_2 )
{
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_215 * V_216 = & V_224 -> V_214 . V_216 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_240 = & V_224 -> V_214 . V_219 [ 1 ] ;
struct V_428 * V_281 =
(struct V_428 * ) & V_224 -> V_214 . V_237 ;
F_102 ( V_1 , V_224 , & V_224 -> V_214 ) ;
F_185 ( V_4 , V_2 , V_281 ) ;
F_104 ( V_1 , & V_224 -> V_214 ) ;
F_175 ( V_281 -> V_306 , V_272 ) ;
V_224 -> V_357 = F_24 ( V_16 ,
( void * ) V_4 -> V_429 , V_272 ,
V_157 ) ;
V_224 -> V_358 = V_272 ;
V_240 -> V_72 = V_224 -> V_357 ;
V_240 -> V_73 = V_272 ;
V_240 -> V_74 = V_24 -> V_75 -> V_74 ;
V_224 -> V_214 . V_210 = 2 ;
F_105 ( V_1 , V_224 , V_216 ) ;
F_8 ( L_115 , V_1 ) ;
return F_172 ( V_1 , V_224 ) ;
}
static int
F_186 ( struct V_277 * V_4 , struct V_233 * V_2 )
{
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_215 * V_216 = & V_224 -> V_214 . V_216 ;
struct V_347 * V_281 =
(struct V_347 * ) & V_224 -> V_214 . V_237 ;
V_140 V_430 ;
int V_288 ;
F_102 ( V_1 , V_224 , & V_224 -> V_214 ) ;
V_288 = F_187 ( V_4 , V_2 , V_281 , V_431 ) ;
if ( V_288 < 0 )
return V_288 ;
V_430 = V_288 ;
F_104 ( V_1 , & V_224 -> V_214 ) ;
if ( V_430 ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_240 = & V_224 -> V_214 . V_219 [ 1 ] ;
void * V_432 = V_4 -> V_429 ;
V_224 -> V_357 = F_24 ( V_16 ,
V_432 , V_430 , V_157 ) ;
V_224 -> V_358 = V_430 ;
V_240 -> V_72 = V_224 -> V_357 ;
V_240 -> V_73 = V_430 ;
V_240 -> V_74 = V_24 -> V_75 -> V_74 ;
V_224 -> V_214 . V_210 = 2 ;
}
F_105 ( V_1 , V_224 , V_216 ) ;
F_8 ( L_116 , V_1 ) ;
return F_172 ( V_1 , V_224 ) ;
}
static int
F_188 ( struct V_1 * V_1 , struct V_224 * V_224 ,
struct V_62 * V_62 , struct V_215 * V_216 ,
V_140 V_433 , V_140 V_335 )
{
struct V_277 * V_4 = V_224 -> V_277 ;
struct V_282 * V_303 , * V_434 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
V_140 V_307 , V_308 ;
int V_26 = 0 , V_287 ;
V_307 = V_335 / V_295 ;
V_303 = & V_4 -> V_3 . V_294 [ V_307 ] ;
V_287 = V_27 ( V_4 -> V_3 . V_435 - V_307 , V_1 -> V_20 ) ;
V_308 = V_335 % V_295 ;
V_216 -> V_209 = V_62 ;
V_216 -> V_207 = ( V_208 ) & V_224 -> V_214 ;
F_189 (sg_start, tmp_sg, sg_nents, i) {
F_8 ( L_117
L_118 ,
( unsigned long long ) V_434 -> V_436 ,
V_434 -> V_73 , V_308 ) ;
V_62 -> V_72 = F_190 ( V_16 , V_434 ) + V_308 ;
V_62 -> V_73 = F_33 ( V_140 , V_433 ,
F_191 ( V_16 , V_434 ) - V_308 ) ;
V_62 -> V_74 = V_24 -> V_75 -> V_74 ;
F_8 ( L_119 ,
V_62 -> V_72 , V_62 -> V_73 , V_62 -> V_74 ) ;
V_308 = 0 ;
V_433 -= V_62 -> V_73 ;
if ( ! V_433 )
break;
V_62 ++ ;
F_8 ( L_120 , V_62 ) ;
}
V_216 -> V_210 = ++ V_26 ;
F_8 ( L_121 ,
V_216 -> V_209 , V_216 -> V_210 ) ;
return V_216 -> V_210 ;
}
static int
V_96 ( struct V_233 * V_2 , struct V_277 * V_4 ,
struct V_343 * V_344 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_338 * V_275 = & V_344 -> V_275 ;
struct V_215 * V_216 ;
struct V_62 * V_62 ;
V_140 V_335 , V_437 , V_433 , V_438 , V_439 = 0 ;
int V_19 = 0 , V_26 , V_440 ;
V_224 -> V_214 . V_224 = V_224 ;
V_335 = V_344 -> V_229 == V_392 ? V_4 -> V_296 : 0 ;
V_19 = F_141 ( V_1 , V_224 , V_3 -> V_294 ,
V_3 -> V_435 , V_3 -> V_297 ,
V_335 , V_344 -> V_229 , & V_344 -> V_275 ) ;
if ( V_19 )
return V_19 ;
V_433 = V_275 -> V_341 ;
V_335 = V_275 -> V_335 ;
V_62 = F_23 ( sizeof( struct V_62 ) * V_275 -> V_334 , V_67 ) ;
if ( ! V_62 ) {
F_5 ( L_122 ) ;
V_19 = - V_77 ;
goto V_441;
}
V_344 -> V_62 = V_62 ;
V_344 -> V_383 = F_118 ( V_275 -> V_334 , V_1 -> V_20 ) ;
V_344 -> V_216 = F_23 ( sizeof( struct V_215 ) * V_344 -> V_383 ,
V_67 ) ;
if ( ! V_344 -> V_216 ) {
F_8 ( L_123 ) ;
V_19 = - V_77 ;
goto V_441;
}
V_344 -> V_224 = V_224 ;
V_438 = V_1 -> V_20 * V_295 ;
for ( V_26 = 0 ; V_26 < V_344 -> V_383 ; V_26 ++ ) {
V_216 = & V_224 -> V_228 . V_216 [ V_26 ] ;
V_437 = V_27 ( V_433 , V_438 ) ;
V_216 -> V_222 = 0 ;
if ( V_344 -> V_229 == V_340 ) {
V_216 -> V_220 = V_442 ;
V_216 -> V_344 . V_443 . V_444 = V_224 -> V_315 + V_335 ;
V_216 -> V_344 . V_443 . V_445 = V_224 -> V_314 ;
if ( V_26 + 1 == V_344 -> V_383 )
V_216 -> V_211 = & V_224 -> V_214 . V_216 ;
else
V_216 -> V_211 = & V_344 -> V_216 [ V_26 + 1 ] ;
} else {
V_216 -> V_220 = V_446 ;
V_216 -> V_344 . V_443 . V_444 = V_224 -> V_317 + V_439 ;
V_216 -> V_344 . V_443 . V_445 = V_224 -> V_316 ;
if ( V_26 + 1 == V_344 -> V_383 )
V_216 -> V_222 = V_223 ;
else
V_216 -> V_211 = & V_344 -> V_216 [ V_26 + 1 ] ;
}
V_440 = F_188 ( V_1 , V_224 , V_62 ,
V_216 , V_437 , V_335 ) ;
V_62 += V_440 ;
V_335 += V_437 ;
V_439 += V_437 ;
V_433 -= V_437 ;
}
return 0 ;
V_441:
F_144 ( V_1 , V_275 ) ;
return V_19 ;
}
static int
F_192 ( struct V_15 * V_16 ,
struct V_282 * V_303 , int V_287 , T_1 * V_447 )
{
T_1 V_448 , V_449 , V_450 , V_451 = 0 ;
struct V_282 * V_434 ;
int V_26 = 0 , V_452 , V_453 , V_454 ;
V_454 = 0 ;
V_452 = 1 ;
V_453 = V_287 - 1 ;
F_189 (sg_start, tmp_sg, sg_nents, i) {
V_448 = F_190 ( V_16 , V_434 ) ;
if ( V_452 )
V_451 = V_448 ;
V_449 = V_448 + F_191 ( V_16 , V_434 ) ;
F_8 ( L_124 ,
V_26 , ( unsigned long long ) V_434 -> V_436 ,
V_434 -> V_73 ) ;
if ( ( V_449 & ~ V_455 ) && V_26 < V_453 ) {
V_452 = 0 ;
continue;
}
V_452 = 1 ;
V_450 = V_451 & V_455 ;
do {
V_447 [ V_454 ++ ] = V_450 ;
F_8 ( L_125 ,
V_454 - 1 , V_450 ) ;
V_450 += V_295 ;
} while ( V_450 < V_449 );
}
return V_454 ;
}
static inline void
F_193 ( struct V_215 * V_456 , struct V_359 * V_75 )
{
V_140 V_445 ;
memset ( V_456 , 0 , sizeof( * V_456 ) ) ;
V_456 -> V_207 = V_403 ;
V_456 -> V_220 = V_457 ;
V_456 -> V_458 . V_459 = V_75 -> V_445 ;
V_445 = F_194 ( V_75 -> V_445 ) ;
F_195 ( V_75 , V_445 ) ;
}
static int
F_196 ( struct V_1 * V_1 ,
struct V_104 * V_105 ,
struct V_338 * V_460 ,
enum V_461 V_124 ,
struct V_62 * V_232 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_359 * V_75 ;
struct V_462 * V_463 ;
struct V_215 V_464 , V_456 ;
struct V_215 * V_465 , * V_344 = NULL ;
int V_19 , V_466 ;
V_140 V_308 ;
if ( V_460 -> V_342 == 1 ) {
V_232 -> V_74 = V_24 -> V_75 -> V_74 ;
V_232 -> V_72 = F_190 ( V_16 , & V_460 -> V_283 [ 0 ] ) ;
V_232 -> V_73 = F_191 ( V_16 , & V_460 -> V_283 [ 0 ] ) ;
F_8 ( L_126 ,
V_232 -> V_72 , V_232 -> V_73 , V_232 -> V_74 ) ;
return 0 ;
}
if ( V_124 == V_133 ) {
V_75 = V_105 -> V_110 ;
V_463 = V_105 -> V_109 ;
} else {
V_75 = V_105 -> V_111 -> V_113 ;
V_463 = V_105 -> V_111 -> V_112 ;
}
V_308 = V_460 -> V_335 % V_295 ;
F_8 ( L_127 ,
V_105 , V_460 -> V_334 , V_460 -> V_335 ) ;
V_466 = F_192 ( V_16 , V_460 -> V_283 , V_460 -> V_334 ,
& V_463 -> V_467 [ 0 ] ) ;
if ( ! ( V_105 -> V_124 & V_124 ) ) {
F_193 ( & V_456 , V_75 ) ;
V_344 = & V_456 ;
}
memset ( & V_464 , 0 , sizeof( V_464 ) ) ;
V_464 . V_207 = V_403 ;
V_464 . V_220 = V_468 ;
V_464 . V_344 . V_469 . V_470 = V_463 -> V_467 [ 0 ] + V_308 ;
V_464 . V_344 . V_469 . V_467 = V_463 ;
V_464 . V_344 . V_469 . V_471 = V_466 ;
V_464 . V_344 . V_469 . V_472 = V_473 ;
V_464 . V_344 . V_469 . V_73 = V_460 -> V_341 ;
V_464 . V_344 . V_469 . V_445 = V_75 -> V_445 ;
V_464 . V_344 . V_469 . V_474 = V_98 ;
if ( ! V_344 )
V_344 = & V_464 ;
else
V_344 -> V_211 = & V_464 ;
V_19 = F_101 ( V_1 -> V_58 , V_344 , & V_465 ) ;
if ( V_19 ) {
F_3 ( L_128 , V_19 ) ;
return V_19 ;
}
V_105 -> V_124 &= ~ V_124 ;
V_232 -> V_74 = V_75 -> V_74 ;
V_232 -> V_72 = V_463 -> V_467 [ 0 ] + V_308 ;
V_232 -> V_73 = V_460 -> V_341 ;
F_8 ( L_126 ,
V_232 -> V_72 , V_232 -> V_73 , V_232 -> V_74 ) ;
return V_19 ;
}
static inline void
F_197 ( struct V_3 * V_3 , struct V_475 * V_476 ,
struct V_477 * V_478 )
{
V_478 -> V_479 = V_480 ;
V_478 -> V_481 . V_482 . V_483 = V_484 ;
V_478 -> V_481 . V_482 . V_485 = V_3 -> V_367 -> V_368 . V_366 ;
V_478 -> V_481 . V_482 . V_486 = V_3 -> V_487 ;
V_478 -> V_481 . V_482 . V_488 = 0xffff ;
V_478 -> V_481 . V_482 . V_489 = true ;
V_478 -> V_481 . V_482 . V_490 = true ;
if ( V_3 -> V_491 == V_492 ||
V_3 -> V_491 == V_493 )
V_478 -> V_481 . V_482 . V_494 = true ;
}
static int
F_198 ( struct V_3 * V_3 , struct V_475 * V_476 )
{
switch ( V_3 -> V_6 ) {
case V_495 :
case V_496 :
V_476 -> V_460 . V_479 = V_497 ;
F_197 ( V_3 , V_476 , & V_476 -> V_498 ) ;
break;
case V_499 :
case V_500 :
V_476 -> V_498 . V_479 = V_497 ;
F_197 ( V_3 , V_476 , & V_476 -> V_460 ) ;
break;
case V_501 :
case V_502 :
F_197 ( V_3 , V_476 , & V_476 -> V_498 ) ;
F_197 ( V_3 , V_476 , & V_476 -> V_460 ) ;
break;
default:
F_3 ( L_129 , V_3 -> V_6 ) ;
return - V_318 ;
}
return 0 ;
}
static inline V_174
F_199 ( V_174 V_503 )
{
return ( V_503 & V_504 ? 0xc0 : 0 ) |
( V_503 & V_505 ? 0x30 : 0 ) |
( V_503 & V_505 ? 0x0f : 0 ) ;
}
static int
F_200 ( struct V_1 * V_1 ,
struct V_3 * V_3 ,
struct V_343 * V_228 ,
struct V_104 * V_105 )
{
struct V_215 V_506 , V_456 ;
struct V_215 * V_465 , * V_344 = NULL ;
struct V_120 * V_111 = V_105 -> V_111 ;
struct V_475 V_476 ;
int V_19 ;
memset ( & V_476 , 0 , sizeof( V_476 ) ) ;
V_19 = F_198 ( V_3 , & V_476 ) ;
if ( V_19 )
goto V_59;
V_476 . V_507 = F_199 ( V_3 -> V_503 ) ;
if ( ! ( V_105 -> V_124 & V_130 ) ) {
F_193 ( & V_456 , V_111 -> V_114 ) ;
V_344 = & V_456 ;
}
memset ( & V_506 , 0 , sizeof( V_506 ) ) ;
V_506 . V_220 = V_508 ;
V_506 . V_207 = V_403 ;
V_506 . V_209 = & V_228 -> V_509 [ V_510 ] ;
V_506 . V_210 = 1 ;
V_506 . V_344 . V_511 . V_474 = V_98 ;
V_506 . V_344 . V_511 . V_476 = & V_476 ;
V_506 . V_344 . V_511 . V_114 = V_111 -> V_114 ;
if ( V_3 -> V_512 )
V_506 . V_344 . V_511 . V_345 = & V_228 -> V_509 [ V_513 ] ;
if ( ! V_344 )
V_344 = & V_506 ;
else
V_344 -> V_211 = & V_506 ;
V_19 = F_101 ( V_1 -> V_58 , V_344 , & V_465 ) ;
if ( V_19 ) {
F_3 ( L_128 , V_19 ) ;
goto V_59;
}
V_105 -> V_124 &= ~ V_130 ;
V_228 -> V_509 [ V_514 ] . V_74 = V_111 -> V_114 -> V_74 ;
V_228 -> V_509 [ V_514 ] . V_72 = 0 ;
V_228 -> V_509 [ V_514 ] . V_73 = V_3 -> V_297 ;
if ( V_3 -> V_6 != V_500 &&
V_3 -> V_6 != V_499 )
V_228 -> V_509 [ V_514 ] . V_73 += V_3 -> V_515 ;
F_8 ( L_130 ,
V_228 -> V_509 [ V_514 ] . V_72 , V_228 -> V_509 [ V_514 ] . V_73 ,
V_228 -> V_509 [ V_514 ] . V_74 ) ;
V_59:
return V_19 ;
}
static int
F_201 ( struct V_1 * V_1 ,
struct V_224 * V_224 ,
struct V_343 * V_344 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_3 * V_3 = & V_224 -> V_277 -> V_3 ;
int V_19 ;
if ( ! V_344 -> V_105 -> V_111 ) {
V_19 = F_56 ( V_344 -> V_105 ,
V_24 -> V_15 ,
V_24 -> V_57 ) ;
if ( V_19 ) {
F_3 ( L_131 ,
V_1 ) ;
return V_19 ;
}
}
if ( V_3 -> V_512 ) {
V_19 = F_141 ( V_1 , V_224 ,
V_3 -> V_512 ,
V_3 -> V_516 ,
V_3 -> V_515 ,
0 , V_344 -> V_229 , & V_344 -> V_345 ) ;
if ( V_19 ) {
F_3 ( L_132 ,
V_1 ) ;
return V_19 ;
}
memset ( & V_344 -> V_509 [ V_513 ] , 0 , sizeof( V_344 -> V_509 [ V_513 ] ) ) ;
V_19 = F_196 ( V_1 , V_344 -> V_105 , & V_344 -> V_345 ,
V_125 , & V_344 -> V_509 [ V_513 ] ) ;
if ( V_19 ) {
F_3 ( L_133 ,
V_1 ) ;
goto V_517;
}
}
V_19 = F_200 ( V_1 , V_3 , V_344 , V_344 -> V_105 ) ;
if ( V_19 ) {
F_3 ( L_133 ,
V_1 ) ;
goto V_517;
}
V_344 -> V_105 -> V_124 |= V_131 ;
return 0 ;
V_517:
if ( V_3 -> V_512 )
F_144 ( V_1 , & V_344 -> V_345 ) ;
return V_19 ;
}
static int
V_93 ( struct V_233 * V_2 , struct V_277 * V_4 ,
struct V_343 * V_344 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_104 * V_105 = NULL ;
struct V_215 * V_216 ;
struct V_62 * V_509 ;
V_140 V_335 ;
int V_19 = 0 ;
unsigned long V_127 ;
V_224 -> V_214 . V_224 = V_224 ;
V_335 = V_344 -> V_229 == V_392 ? V_4 -> V_296 : 0 ;
V_19 = F_141 ( V_1 , V_224 , V_3 -> V_294 ,
V_3 -> V_435 , V_3 -> V_297 ,
V_335 , V_344 -> V_229 , & V_344 -> V_275 ) ;
if ( V_19 )
return V_19 ;
if ( V_344 -> V_275 . V_342 != 1 || F_1 ( V_1 , V_3 ) ) {
F_202 ( & V_1 -> V_152 , V_127 ) ;
V_105 = F_203 ( & V_1 -> V_107 ,
struct V_104 , V_108 ) ;
F_46 ( & V_105 -> V_108 ) ;
F_204 ( & V_1 -> V_152 , V_127 ) ;
V_344 -> V_105 = V_105 ;
}
V_19 = F_196 ( V_1 , V_105 , & V_344 -> V_275 ,
V_133 , & V_344 -> V_509 [ V_510 ] ) ;
if ( V_19 )
goto V_441;
if ( F_1 ( V_1 , V_3 ) ) {
V_19 = F_201 ( V_1 , V_224 , V_344 ) ;
if ( V_19 )
goto V_441;
V_509 = & V_344 -> V_509 [ V_514 ] ;
} else {
V_509 = & V_344 -> V_509 [ V_510 ] ;
}
memcpy ( & V_344 -> V_518 , V_509 , sizeof( * V_509 ) ) ;
V_344 -> V_62 = & V_344 -> V_518 ;
V_344 -> V_383 = 1 ;
memset ( & V_344 -> V_519 , 0 , sizeof( * V_216 ) ) ;
V_344 -> V_216 = & V_344 -> V_519 ;
V_344 -> V_224 = V_224 ;
V_216 = & V_224 -> V_228 . V_519 ;
V_216 -> V_209 = & V_344 -> V_518 ;
V_216 -> V_210 = 1 ;
V_216 -> V_207 = ( V_208 ) & V_224 -> V_214 ;
if ( V_344 -> V_229 == V_340 ) {
V_216 -> V_220 = V_442 ;
V_216 -> V_344 . V_443 . V_444 = V_224 -> V_315 ;
V_216 -> V_344 . V_443 . V_445 = V_224 -> V_314 ;
V_216 -> V_222 = ! F_1 ( V_1 , V_3 ) ?
0 : V_223 ;
} else {
V_216 -> V_220 = V_446 ;
V_216 -> V_344 . V_443 . V_444 = V_224 -> V_317 ;
V_216 -> V_344 . V_443 . V_445 = V_224 -> V_316 ;
V_216 -> V_222 = V_223 ;
}
return 0 ;
V_441:
if ( V_105 ) {
F_202 ( & V_1 -> V_152 , V_127 ) ;
F_50 ( & V_105 -> V_108 , & V_1 -> V_107 ) ;
F_204 ( & V_1 -> V_152 , V_127 ) ;
}
F_144 ( V_1 , & V_344 -> V_275 ) ;
return V_19 ;
}
static int
F_205 ( struct V_233 * V_2 , struct V_277 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_343 * V_344 = & V_224 -> V_228 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_215 * V_409 ;
int V_288 ;
F_8 ( L_134 ,
V_224 , V_3 -> V_297 ) ;
V_344 -> V_229 = V_340 ;
V_288 = V_24 -> V_92 ( V_2 , V_4 , V_344 ) ;
if ( V_288 ) {
F_3 ( L_135 , V_224 ) ;
return V_288 ;
}
if ( ! F_1 ( V_1 , V_3 ) ) {
F_102 ( V_1 , V_224 ,
& V_224 -> V_214 ) ;
F_173 ( V_4 , V_2 , true , (struct V_410 * )
& V_224 -> V_214 . V_237 ) ;
F_104 ( V_1 , & V_224 -> V_214 ) ;
F_105 ( V_1 , V_224 ,
& V_224 -> V_214 . V_216 ) ;
V_224 -> V_228 . V_519 . V_211 = & V_224 -> V_214 . V_216 ;
V_344 -> V_383 += 1 ;
}
V_288 = F_101 ( V_1 -> V_58 , V_344 -> V_216 , & V_409 ) ;
if ( V_288 )
F_5 ( L_136 ) ;
if ( ! F_1 ( V_1 , V_3 ) )
F_8 ( L_137
L_138 , V_224 ) ;
else
F_8 ( L_139 ,
V_224 ) ;
return 1 ;
}
static int
F_206 ( struct V_233 * V_2 , struct V_277 * V_4 , bool V_520 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_224 * V_224 = F_114 ( V_4 ) ;
struct V_343 * V_344 = & V_224 -> V_228 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_215 * V_409 ;
int V_288 ;
F_8 ( L_140 ,
V_224 , V_3 -> V_297 , V_4 -> V_296 ) ;
V_344 -> V_229 = V_392 ;
V_288 = V_24 -> V_92 ( V_2 , V_4 , V_344 ) ;
if ( V_288 ) {
F_3 ( L_135 , V_224 ) ;
return V_288 ;
}
V_288 = F_101 ( V_1 -> V_58 , V_344 -> V_216 , & V_409 ) ;
if ( V_288 )
F_5 ( L_141 ) ;
F_8 ( L_142 ,
V_224 ) ;
return 0 ;
}
static int
F_207 ( struct V_233 * V_2 , struct V_277 * V_4 , int V_144 )
{
int V_19 ;
switch ( V_144 ) {
case V_521 :
V_19 = F_178 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_143 , V_144 ) ;
V_19 = - V_318 ;
break;
}
return V_19 ;
}
static int
F_208 ( struct V_233 * V_2 , struct V_277 * V_4 , int V_144 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
switch ( V_144 ) {
case V_390 :
V_19 = F_180 ( V_4 , V_2 ) ;
if ( ! V_19 )
V_1 -> V_522 = true ;
break;
case V_523 :
V_19 = F_178 ( V_4 , V_2 , true ) ;
break;
case V_386 :
V_19 = F_182 ( V_4 , V_2 ) ;
break;
case V_387 :
V_19 = F_184 ( V_4 , V_2 ) ;
break;
case V_388 :
V_19 = F_186 ( V_4 , V_2 ) ;
break;
case V_524 :
V_19 = F_157 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_144 , V_144 ) ;
V_19 = - V_318 ;
break;
}
return V_19 ;
}
struct V_33 *
F_90 ( struct V_166 * V_166 )
{
struct V_167 * V_168 = V_166 -> V_168 ;
struct V_33 * V_525 ;
struct V_526 * V_527 ;
int V_19 ;
V_527 = (struct V_526 * ) & V_168 -> V_528 ;
F_8 ( L_145 , & V_168 -> V_528 , V_527 ) ;
V_525 = F_209 ( F_96 , V_166 ,
V_529 , V_53 ) ;
if ( F_19 ( V_525 ) ) {
F_3 ( L_146 , F_20 ( V_525 ) ) ;
V_19 = F_20 ( V_525 ) ;
goto V_171;
}
F_8 ( L_147 , V_525 , V_525 -> V_10 ) ;
V_19 = F_210 ( V_525 , V_527 ) ;
if ( V_19 ) {
F_3 ( L_148 , V_19 ) ;
goto V_530;
}
V_19 = F_211 ( V_525 , 0 ) ;
if ( V_19 ) {
F_3 ( L_149 , V_19 ) ;
goto V_530;
}
return V_525 ;
V_530:
F_79 ( V_525 ) ;
V_171:
return F_17 ( V_19 ) ;
}
static int
F_212 ( struct V_167 * V_168 ,
struct V_531 * V_532 )
{
struct V_166 * V_166 ;
struct V_33 * V_533 ;
int V_19 ;
V_166 = F_23 ( sizeof( struct V_166 ) , V_67 ) ;
if ( ! V_166 ) {
F_3 ( L_150 ) ;
return - V_77 ;
}
F_213 ( & V_166 -> V_180 , 0 ) ;
F_66 ( & V_166 -> V_178 ) ;
F_49 ( & V_166 -> V_179 ) ;
F_64 ( & V_166 -> V_534 ) ;
V_166 -> V_168 = V_168 ;
memcpy ( & V_168 -> V_528 , V_532 ,
sizeof( struct V_531 ) ) ;
V_533 = F_90 ( V_166 ) ;
if ( F_19 ( V_533 ) ) {
V_19 = F_20 ( V_533 ) ;
goto V_171;
}
V_166 -> V_190 = V_533 ;
V_168 -> V_535 = V_166 ;
return 0 ;
V_171:
F_27 ( V_166 ) ;
return V_19 ;
}
static int
F_75 ( struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_536 V_537 ;
int V_19 ;
memset ( & V_537 , 0 , sizeof( struct V_536 ) ) ;
V_537 . V_173 = V_1 -> V_173 ;
V_537 . V_538 = 7 ;
V_537 . V_539 = 7 ;
V_19 = F_214 ( V_13 , & V_537 ) ;
if ( V_19 ) {
F_3 ( L_151 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int
F_215 ( struct V_233 * V_2 , struct V_234 * V_235 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
F_12 ( L_152 , V_1 ) ;
V_19 = F_216 ( & V_1 -> V_148 ) ;
if ( V_19 ) {
F_3 ( L_153 ,
V_1 ) ;
return V_19 ;
}
F_217 ( & V_1 -> V_148 ) ;
if ( ! V_235 -> V_252 )
return 0 ;
F_107 ( V_1 ) ;
F_12 ( L_154 , V_2 ) ;
V_19 = F_216 ( & V_1 -> V_147 ) ;
if ( V_19 )
return V_19 ;
F_12 ( L_155 , V_235 -> V_271 ) ;
return 0 ;
}
static void
F_218 ( struct V_167 * V_168 , struct V_233 * V_2 ,
struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_540 * V_541 = & V_13 -> V_542 ;
struct V_543 * V_544 ;
struct V_545 * V_546 ;
V_2 -> V_547 = V_168 -> V_528 . V_548 ;
if ( V_168 -> V_528 . V_548 == V_549 ) {
V_546 = (struct V_545 * ) & V_541 -> V_72 . V_550 ;
snprintf ( V_2 -> V_551 , sizeof( V_2 -> V_551 ) , L_156 ,
& V_546 -> V_552 . V_553 ) ;
V_2 -> V_554 = F_219 ( V_546 -> V_555 ) ;
V_546 = (struct V_545 * ) & V_541 -> V_72 . V_556 ;
snprintf ( V_2 -> V_557 , sizeof( V_2 -> V_557 ) , L_156 ,
& V_546 -> V_552 . V_553 ) ;
V_2 -> V_558 = F_219 ( V_546 -> V_555 ) ;
} else {
V_544 = (struct V_543 * ) & V_541 -> V_72 . V_550 ;
sprintf ( V_2 -> V_551 , L_157 ,
& V_544 -> V_559 . V_560 ) ;
V_2 -> V_554 = F_219 ( V_544 -> V_561 ) ;
V_544 = (struct V_543 * ) & V_541 -> V_72 . V_556 ;
sprintf ( V_2 -> V_557 , L_157 ,
& V_544 -> V_559 . V_560 ) ;
V_2 -> V_558 = F_219 ( V_544 -> V_561 ) ;
}
}
static int
F_220 ( struct V_167 * V_168 , struct V_233 * V_2 )
{
struct V_166 * V_166 = V_168 -> V_535 ;
struct V_1 * V_1 ;
int V_19 ;
V_562:
V_19 = F_221 ( & V_166 -> V_180 ) ;
if ( V_19 )
return - V_563 ;
F_71 ( & V_168 -> V_169 ) ;
if ( V_168 -> V_564 >= V_565 ) {
F_72 ( & V_168 -> V_169 ) ;
F_8 ( L_158 ,
V_168 -> V_564 ) ;
return - V_563 ;
}
F_72 ( & V_168 -> V_169 ) ;
F_10 ( & V_166 -> V_178 ) ;
if ( F_52 ( & V_166 -> V_179 ) ) {
F_11 ( & V_166 -> V_178 ) ;
goto V_562;
}
V_1 = F_203 ( & V_166 -> V_179 ,
struct V_1 , V_146 ) ;
F_93 ( & V_1 -> V_146 ) ;
F_11 ( & V_166 -> V_178 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
F_218 ( V_168 , V_2 , V_1 ) ;
F_8 ( L_159 , V_1 ) ;
return 0 ;
}
static void
F_222 ( struct V_167 * V_168 )
{
struct V_166 * V_166 = V_168 -> V_535 ;
struct V_1 * V_1 , * V_406 ;
if ( V_166 -> V_190 )
F_79 ( V_166 -> V_190 ) ;
F_10 ( & V_166 -> V_178 ) ;
if ( ! F_52 ( & V_166 -> V_179 ) ) {
F_12 ( L_160 ) ;
F_53 (isert_conn, n,
&isert_np->np_accept_list,
accept_node) {
F_12 ( L_161 ,
V_1 , V_1 -> V_144 ) ;
F_77 ( V_1 ) ;
}
}
F_11 ( & V_166 -> V_178 ) ;
V_168 -> V_535 = NULL ;
F_27 ( V_166 ) ;
}
static void V_154 ( struct V_384 * V_78 )
{
struct V_1 * V_1 = F_84 ( V_78 ,
struct V_1 ,
V_153 ) ;
F_12 ( L_162 , V_1 ) ;
F_223 ( & V_1 -> V_149 ) ;
F_10 ( & V_1 -> V_151 ) ;
V_1 -> V_144 = V_566 ;
F_11 ( & V_1 -> V_151 ) ;
F_12 ( L_163 , V_1 ) ;
F_85 ( V_1 ) ;
}
static void
F_224 ( struct V_1 * V_1 )
{
struct V_233 * V_2 = V_1 -> V_2 ;
F_12 ( L_40 , V_1 ) ;
if ( V_1 -> V_522 ) {
F_12 ( L_164 , V_1 ) ;
F_225 ( & V_2 -> V_567 ,
V_568 * V_569 ) ;
}
}
static void
F_226 ( struct V_233 * V_2 )
{
F_12 ( L_165 , V_2 ) ;
if ( V_2 -> V_136 ) {
F_227 ( V_2 -> V_136 -> V_135 ) ;
F_228 ( V_2 -> V_136 -> V_135 ) ;
}
}
static void
F_229 ( struct V_1 * V_1 )
{
struct V_203 * V_465 ;
F_12 ( L_40 , V_1 ) ;
F_64 ( & V_1 -> V_397 ) ;
V_1 -> V_570 . V_207 = V_396 ;
if ( F_98 ( V_1 -> V_58 , & V_1 -> V_570 , & V_465 ) ) {
F_3 ( L_166 , V_1 ) ;
return;
}
F_223 ( & V_1 -> V_397 ) ;
}
static void F_230 ( struct V_233 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_12 ( L_167 , V_1 ) ;
F_10 ( & V_1 -> V_151 ) ;
if ( V_1 -> V_144 == V_145 ) {
F_11 ( & V_1 -> V_151 ) ;
return;
}
F_87 ( V_1 ) ;
F_11 ( & V_1 -> V_151 ) ;
F_226 ( V_2 ) ;
F_229 ( V_1 ) ;
F_224 ( V_1 ) ;
F_94 ( V_193 , & V_1 -> V_153 ) ;
}
static void F_231 ( struct V_233 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_229 ( V_1 ) ;
F_85 ( V_1 ) ;
}
static int T_4 F_232 ( void )
{
int V_19 ;
V_391 = F_233 ( L_168 ,
V_571 | V_572 , 0 ) ;
if ( ! V_391 ) {
F_3 ( L_169 ) ;
V_19 = - V_77 ;
return - V_77 ;
}
V_193 = F_233 ( L_170 , V_571 ,
V_573 ) ;
if ( ! V_193 ) {
F_3 ( L_171 ) ;
V_19 = - V_77 ;
goto V_574;
}
F_234 ( & V_575 ) ;
F_12 ( L_172 ) ;
return 0 ;
V_574:
F_235 ( V_391 ) ;
return V_19 ;
}
static void T_5 F_236 ( void )
{
F_237 () ;
F_235 ( V_193 ) ;
F_235 ( V_391 ) ;
F_238 ( & V_575 ) ;
F_12 ( L_173 ) ;
}
