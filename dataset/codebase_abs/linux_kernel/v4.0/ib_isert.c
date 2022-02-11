static inline bool
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return ( V_2 -> V_5 &&
V_4 -> V_6 != V_7 ) ;
}
static void
F_2 ( struct V_8 * V_9 , void * V_10 )
{
struct V_1 * V_1 = (struct V_1 * ) V_10 ;
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
static int
F_9 ( struct V_1 * V_1 , struct V_22 * V_23 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_27 V_28 ;
struct V_29 * V_30 ;
int V_19 , V_31 , V_32 = 0 ;
F_10 ( & V_33 ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_34 ; V_31 ++ )
if ( V_25 -> V_35 [ V_31 ] . V_36 <
V_25 -> V_35 [ V_32 ] . V_36 )
V_32 = V_31 ;
V_30 = & V_25 -> V_35 [ V_32 ] ;
V_30 -> V_36 ++ ;
F_11 ( L_6 ,
V_1 , V_30 , V_32 ) ;
F_12 ( & V_33 ) ;
memset ( & V_28 , 0 , sizeof( struct V_27 ) ) ;
V_28 . V_37 = F_2 ;
V_28 . V_38 = V_1 ;
V_28 . V_39 = V_30 -> V_40 ;
V_28 . V_41 = V_30 -> V_40 ;
V_28 . V_42 . V_43 = V_44 ;
V_28 . V_42 . V_45 = V_46 + 1 ;
V_28 . V_42 . V_47 = F_13 ( 2 , V_25 -> V_48 . V_20 - 2 ) ;
V_1 -> V_20 = V_28 . V_42 . V_47 ;
V_28 . V_42 . V_49 = 1 ;
V_28 . V_50 = V_51 ;
V_28 . V_52 = V_53 ;
if ( V_25 -> V_54 )
V_28 . V_55 |= V_56 ;
V_19 = F_14 ( V_23 , V_1 -> V_57 , & V_28 ) ;
if ( V_19 ) {
F_3 ( L_7 , V_19 ) ;
goto V_58;
}
V_1 -> V_59 = V_23 -> V_60 ;
return 0 ;
V_58:
F_10 ( & V_33 ) ;
V_30 -> V_36 -- ;
F_12 ( & V_33 ) ;
return V_19 ;
}
static void
F_15 ( struct V_8 * V_9 , void * V_10 )
{
F_8 ( L_8 , V_9 -> V_11 ) ;
}
static int
F_16 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
T_1 V_65 ;
int V_31 , V_66 ;
V_1 -> V_67 = F_17 ( V_46 *
sizeof( struct V_61 ) , V_68 ) ;
if ( ! V_1 -> V_67 )
goto V_69;
V_62 = V_1 -> V_67 ;
for ( V_31 = 0 ; V_31 < V_46 ; V_31 ++ , V_62 ++ ) {
V_65 = F_18 ( V_16 , ( void * ) V_62 ,
V_70 , V_71 ) ;
if ( F_19 ( V_16 , V_65 ) )
goto V_72;
V_62 -> V_65 = V_65 ;
V_64 = & V_62 -> V_64 ;
V_64 -> V_73 = V_62 -> V_65 ;
V_64 -> V_74 = V_70 ;
V_64 -> V_75 = V_1 -> V_76 -> V_75 ;
}
V_1 -> V_77 = 0 ;
return 0 ;
V_72:
V_62 = V_1 -> V_67 ;
for ( V_66 = 0 ; V_66 < V_31 ; V_66 ++ , V_62 ++ ) {
F_20 ( V_16 , V_62 -> V_65 ,
V_70 , V_71 ) ;
}
F_21 ( V_1 -> V_67 ) ;
V_1 -> V_67 = NULL ;
V_69:
F_3 ( L_9 , V_1 ) ;
return - V_78 ;
}
static void
F_22 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_61 * V_62 ;
int V_31 ;
if ( ! V_1 -> V_67 )
return;
V_62 = V_1 -> V_67 ;
for ( V_31 = 0 ; V_31 < V_46 ; V_31 ++ , V_62 ++ ) {
F_20 ( V_16 , V_62 -> V_65 ,
V_70 , V_71 ) ;
}
F_21 ( V_1 -> V_67 ) ;
V_1 -> V_67 = NULL ;
}
static int
F_23 ( struct V_24 * V_25 )
{
struct V_15 * V_16 = V_25 -> V_15 ;
struct V_17 * V_48 ;
int V_19 = 0 , V_31 ;
int V_79 ;
V_48 = & V_25 -> V_48 ;
V_19 = F_6 ( V_16 , V_48 ) ;
if ( V_19 )
return V_19 ;
V_79 = V_32 ( V_80 , V_48 -> V_79 ) ;
if ( V_48 -> V_81 & V_82 &&
V_48 -> V_81 & V_83 ) {
V_25 -> V_84 = 1 ;
V_25 -> V_85 = V_86 ;
V_25 -> V_87 = V_88 ;
} else {
V_25 -> V_84 = 0 ;
V_25 -> V_85 = V_89 ;
V_25 -> V_87 = V_90 ;
}
V_25 -> V_54 = V_48 -> V_81 &
V_83 ? true : false ;
V_25 -> V_34 = V_32 ( V_91 , F_24 ( int , F_25 () ,
V_25 -> V_15 -> V_92 ) ) ;
F_11 ( L_10
L_11 ,
V_25 -> V_34 , V_25 -> V_15 -> V_93 ,
V_25 -> V_15 -> V_92 , V_25 -> V_84 ,
V_25 -> V_54 ) ;
V_25 -> V_35 = F_26 ( V_25 -> V_34 , sizeof( struct V_29 ) ,
V_68 ) ;
if ( ! V_25 -> V_35 ) {
F_3 ( L_12 ) ;
return - V_78 ;
}
for ( V_31 = 0 ; V_31 < V_25 -> V_34 ; V_31 ++ ) {
struct V_29 * V_30 = & V_25 -> V_35 [ V_31 ] ;
V_30 -> V_25 = V_25 ;
F_27 ( & V_30 -> V_94 , V_95 ) ;
V_30 -> V_40 = F_28 ( V_25 -> V_15 ,
V_96 ,
F_15 ,
( void * ) V_30 ,
V_79 , V_31 ) ;
if ( F_29 ( V_30 -> V_40 ) ) {
V_19 = F_30 ( V_30 -> V_40 ) ;
V_30 -> V_40 = NULL ;
goto V_97;
}
V_19 = F_31 ( V_30 -> V_40 , V_98 ) ;
if ( V_19 )
goto V_97;
}
return 0 ;
V_97:
for ( V_31 = 0 ; V_31 < V_25 -> V_34 ; V_31 ++ ) {
struct V_29 * V_30 = & V_25 -> V_35 [ V_31 ] ;
if ( V_30 -> V_40 ) {
F_32 ( & V_30 -> V_94 ) ;
F_33 ( V_30 -> V_40 ) ;
}
}
F_21 ( V_25 -> V_35 ) ;
return V_19 ;
}
static void
F_34 ( struct V_24 * V_25 )
{
int V_31 ;
F_11 ( L_13 , V_25 ) ;
for ( V_31 = 0 ; V_31 < V_25 -> V_34 ; V_31 ++ ) {
struct V_29 * V_30 = & V_25 -> V_35 [ V_31 ] ;
F_32 ( & V_30 -> V_94 ) ;
F_33 ( V_30 -> V_40 ) ;
V_30 -> V_40 = NULL ;
}
F_21 ( V_25 -> V_35 ) ;
}
static void
F_35 ( struct V_24 * V_25 )
{
F_10 ( & V_33 ) ;
V_25 -> V_99 -- ;
F_11 ( L_14 , V_25 , V_25 -> V_99 ) ;
if ( ! V_25 -> V_99 ) {
F_34 ( V_25 ) ;
F_36 ( & V_25 -> V_100 ) ;
F_21 ( V_25 ) ;
}
F_12 ( & V_33 ) ;
}
static struct V_24 *
F_37 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
int V_19 ;
F_10 ( & V_33 ) ;
F_38 (device, &device_list, dev_node) {
if ( V_25 -> V_15 -> V_101 == V_23 -> V_25 -> V_101 ) {
V_25 -> V_99 ++ ;
F_11 ( L_15 ,
V_25 , V_25 -> V_99 ) ;
F_12 ( & V_33 ) ;
return V_25 ;
}
}
V_25 = F_17 ( sizeof( struct V_24 ) , V_68 ) ;
if ( ! V_25 ) {
F_12 ( & V_33 ) ;
return F_39 ( - V_78 ) ;
}
F_40 ( & V_25 -> V_100 ) ;
V_25 -> V_15 = V_23 -> V_25 ;
V_19 = F_23 ( V_25 ) ;
if ( V_19 ) {
F_21 ( V_25 ) ;
F_12 ( & V_33 ) ;
return F_39 ( V_19 ) ;
}
V_25 -> V_99 ++ ;
F_41 ( & V_25 -> V_100 , & V_102 ) ;
F_11 ( L_16 ,
V_25 , V_25 -> V_99 ) ;
F_12 ( & V_33 ) ;
return V_25 ;
}
static void
F_42 ( struct V_1 * V_1 )
{
struct V_103 * V_104 , * V_105 ;
int V_31 = 0 ;
if ( F_43 ( & V_1 -> V_106 ) )
return;
F_11 ( L_17 , V_1 ) ;
F_44 (fr_desc, tmp,
&isert_conn->conn_fr_pool, list) {
F_36 ( & V_104 -> V_107 ) ;
F_45 ( V_104 -> V_108 ) ;
F_46 ( V_104 -> V_109 ) ;
if ( V_104 -> V_110 ) {
F_45 ( V_104 -> V_110 -> V_111 ) ;
F_46 ( V_104 -> V_110 -> V_112 ) ;
F_47 ( V_104 -> V_110 -> V_113 ) ;
F_21 ( V_104 -> V_110 ) ;
}
F_21 ( V_104 ) ;
++ V_31 ;
}
if ( V_31 < V_1 -> V_114 )
F_5 ( L_18 ,
V_1 -> V_114 - V_31 ) ;
}
static int
F_48 ( struct V_103 * V_115 ,
struct V_15 * V_25 ,
struct V_116 * V_117 )
{
struct V_118 V_119 ;
struct V_120 * V_110 ;
int V_19 ;
V_110 = F_17 ( sizeof( * V_115 -> V_110 ) , V_68 ) ;
if ( ! V_110 ) {
F_3 ( L_19 ) ;
return - V_78 ;
}
V_110 -> V_111 = F_49 ( V_25 ,
V_121 ) ;
if ( F_29 ( V_110 -> V_111 ) ) {
F_3 ( L_20 ,
F_30 ( V_110 -> V_111 ) ) ;
V_19 = F_30 ( V_110 -> V_111 ) ;
goto V_122;
}
V_110 -> V_112 = F_50 ( V_117 , V_121 ) ;
if ( F_29 ( V_110 -> V_112 ) ) {
F_3 ( L_21 ,
F_30 ( V_110 -> V_112 ) ) ;
V_19 = F_30 ( V_110 -> V_112 ) ;
goto V_123;
}
V_115 -> V_124 |= V_125 ;
memset ( & V_119 , 0 , sizeof( V_119 ) ) ;
V_119 . V_126 = 2 ;
V_119 . V_127 |= V_128 ;
V_110 -> V_113 = F_51 ( V_117 , & V_119 ) ;
if ( F_29 ( V_110 -> V_113 ) ) {
F_3 ( L_22 ,
F_30 ( V_110 -> V_113 ) ) ;
V_19 = F_30 ( V_110 -> V_113 ) ;
goto V_129;
}
V_115 -> V_110 = V_110 ;
V_115 -> V_124 |= V_130 ;
V_115 -> V_124 &= ~ V_131 ;
return 0 ;
V_129:
F_46 ( V_115 -> V_110 -> V_112 ) ;
V_123:
F_45 ( V_115 -> V_110 -> V_111 ) ;
V_122:
F_21 ( V_115 -> V_110 ) ;
return V_19 ;
}
static int
F_52 ( struct V_15 * V_15 , struct V_116 * V_117 ,
struct V_103 * V_104 )
{
int V_19 ;
V_104 -> V_108 = F_49 ( V_15 ,
V_121 ) ;
if ( F_29 ( V_104 -> V_108 ) ) {
F_3 ( L_23 ,
F_30 ( V_104 -> V_108 ) ) ;
return F_30 ( V_104 -> V_108 ) ;
}
V_104 -> V_109 = F_50 ( V_117 , V_121 ) ;
if ( F_29 ( V_104 -> V_109 ) ) {
F_3 ( L_24 ,
F_30 ( V_104 -> V_109 ) ) ;
V_19 = F_30 ( V_104 -> V_109 ) ;
goto V_132;
}
V_104 -> V_124 |= V_133 ;
F_8 ( L_25 , V_104 ) ;
return 0 ;
V_132:
F_45 ( V_104 -> V_108 ) ;
return V_19 ;
}
static int
F_53 ( struct V_1 * V_1 )
{
struct V_103 * V_104 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_134 * V_135 = V_1 -> V_2 -> V_136 -> V_135 ;
struct V_137 * V_138 = V_135 -> V_137 ;
int V_31 , V_19 , V_139 ;
V_139 = F_54 ( V_140 , V_141 , V_138 -> V_142 ) ;
V_139 = ( V_139 * 2 ) + V_143 ;
V_1 -> V_114 = 0 ;
for ( V_31 = 0 ; V_31 < V_139 ; V_31 ++ ) {
V_104 = F_17 ( sizeof( * V_104 ) , V_68 ) ;
if ( ! V_104 ) {
F_3 ( L_26 ) ;
V_19 = - V_78 ;
goto V_58;
}
V_19 = F_52 ( V_25 -> V_15 ,
V_1 -> V_57 , V_104 ) ;
if ( V_19 ) {
F_3 ( L_27 ,
V_19 ) ;
F_21 ( V_104 ) ;
goto V_58;
}
F_41 ( & V_104 -> V_107 , & V_1 -> V_106 ) ;
V_1 -> V_114 ++ ;
}
F_8 ( L_28 ,
V_1 , V_1 -> V_114 ) ;
return 0 ;
V_58:
F_42 ( V_1 ) ;
return V_19 ;
}
static int
F_55 ( struct V_22 * V_23 , struct V_144 * V_11 )
{
struct V_145 * V_145 = V_23 -> V_10 ;
struct V_146 * V_147 = V_145 -> V_147 ;
struct V_1 * V_1 ;
struct V_24 * V_25 ;
struct V_15 * V_16 = V_23 -> V_25 ;
int V_19 = 0 ;
F_56 ( & V_147 -> V_148 ) ;
if ( ! V_147 -> V_149 ) {
F_57 ( & V_147 -> V_148 ) ;
F_8 ( L_29 ) ;
return F_58 ( V_23 , NULL , 0 ) ;
}
F_57 ( & V_147 -> V_148 ) ;
F_8 ( L_30 ,
V_23 , V_23 -> V_10 ) ;
V_1 = F_17 ( sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_1 ) {
F_3 ( L_31 ) ;
return - V_78 ;
}
V_1 -> V_150 = V_151 ;
F_40 ( & V_1 -> V_152 ) ;
F_59 ( & V_1 -> V_153 ) ;
F_59 ( & V_1 -> V_154 ) ;
F_59 ( & V_1 -> V_155 ) ;
F_60 ( & V_1 -> V_156 ) ;
F_61 ( & V_1 -> V_157 ) ;
F_62 ( & V_1 -> V_158 ) ;
F_40 ( & V_1 -> V_106 ) ;
V_1 -> V_13 = V_23 ;
V_1 -> V_159 = F_17 ( V_160 +
V_161 , V_68 ) ;
if ( ! V_1 -> V_159 ) {
F_3 ( L_32 ) ;
V_19 = - V_78 ;
goto V_162;
}
V_1 -> V_163 = V_1 -> V_159 ;
V_1 -> V_164 = V_1 -> V_159 +
V_160 ;
F_8 ( L_33 ,
V_1 -> V_159 , V_1 -> V_163 ,
V_1 -> V_164 ) ;
V_1 -> V_165 = F_18 ( V_16 ,
( void * ) V_1 -> V_163 ,
V_160 , V_71 ) ;
V_19 = F_19 ( V_16 , V_1 -> V_165 ) ;
if ( V_19 ) {
F_3 ( L_34 ,
V_19 ) ;
V_1 -> V_165 = 0 ;
goto V_166;
}
V_1 -> V_167 = F_18 ( V_16 ,
( void * ) V_1 -> V_164 ,
V_161 , V_168 ) ;
V_19 = F_19 ( V_16 , V_1 -> V_167 ) ;
if ( V_19 ) {
F_3 ( L_35 ,
V_19 ) ;
V_1 -> V_167 = 0 ;
goto V_169;
}
V_25 = F_37 ( V_23 ) ;
if ( F_29 ( V_25 ) ) {
V_19 = F_30 ( V_25 ) ;
goto V_170;
}
V_1 -> V_171 = F_24 ( V_172 ,
V_11 -> V_173 . V_2 . V_171 ,
V_25 -> V_48 . V_174 ) ;
F_8 ( L_36 , V_1 -> V_171 ) ;
V_1 -> V_26 = V_25 ;
V_1 -> V_57 = F_63 ( V_1 -> V_26 -> V_15 ) ;
if ( F_29 ( V_1 -> V_57 ) ) {
V_19 = F_30 ( V_1 -> V_57 ) ;
F_3 ( L_37 ,
V_1 , V_19 ) ;
goto V_175;
}
V_1 -> V_76 = F_64 ( V_1 -> V_57 ,
V_176 ) ;
if ( F_29 ( V_1 -> V_76 ) ) {
V_19 = F_30 ( V_1 -> V_76 ) ;
F_3 ( L_38 ,
V_1 , V_19 ) ;
goto V_177;
}
V_19 = F_9 ( V_1 , V_23 ) ;
if ( V_19 )
goto V_178;
V_19 = F_65 ( V_1 ) ;
if ( V_19 )
goto V_178;
V_19 = F_66 ( V_1 ) ;
if ( V_19 )
goto V_178;
F_10 ( & V_145 -> V_179 ) ;
F_41 ( & V_1 -> V_152 , & V_145 -> V_180 ) ;
F_12 ( & V_145 -> V_179 ) ;
F_11 ( L_39 , V_147 ) ;
F_67 ( & V_145 -> V_181 ) ;
return 0 ;
V_178:
F_46 ( V_1 -> V_76 ) ;
V_177:
F_68 ( V_1 -> V_57 ) ;
V_175:
F_35 ( V_25 ) ;
V_170:
F_20 ( V_16 , V_1 -> V_167 ,
V_161 , V_168 ) ;
V_169:
F_20 ( V_16 , V_1 -> V_165 ,
V_160 , V_71 ) ;
V_166:
F_21 ( V_1 -> V_159 ) ;
V_162:
F_21 ( V_1 ) ;
F_58 ( V_23 , NULL , 0 ) ;
return V_19 ;
}
static void
F_69 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_24 * V_25 = V_1 -> V_26 ;
F_8 ( L_40 , V_1 ) ;
if ( V_25 && V_25 -> V_84 )
F_42 ( V_1 ) ;
F_22 ( V_1 ) ;
F_70 ( V_1 -> V_13 ) ;
if ( V_1 -> V_59 ) {
struct V_29 * V_30 = V_1 -> V_59 -> V_41 -> V_182 ;
F_8 ( L_41 , V_30 ) ;
F_10 ( & V_33 ) ;
V_30 -> V_36 -- ;
F_12 ( & V_33 ) ;
F_71 ( V_1 -> V_59 ) ;
}
F_46 ( V_1 -> V_76 ) ;
F_68 ( V_1 -> V_57 ) ;
if ( V_1 -> V_159 ) {
F_20 ( V_16 , V_1 -> V_167 ,
V_161 , V_168 ) ;
F_20 ( V_16 , V_1 -> V_165 ,
V_160 ,
V_71 ) ;
F_21 ( V_1 -> V_159 ) ;
}
F_21 ( V_1 ) ;
if ( V_25 )
F_35 ( V_25 ) ;
}
static void
F_72 ( struct V_22 * V_23 )
{
struct V_1 * V_1 = V_23 -> V_60 -> V_38 ;
F_11 ( L_40 , V_1 ) ;
if ( ! F_73 ( & V_1 -> V_156 ) ) {
F_5 ( L_42 , V_1 ) ;
return;
}
F_10 ( & V_1 -> V_157 ) ;
if ( V_1 -> V_150 != V_183 )
V_1 -> V_150 = V_184 ;
F_12 ( & V_1 -> V_157 ) ;
}
static void
F_74 ( struct V_185 * V_185 )
{
struct V_1 * V_1 = F_75 ( V_185 ,
struct V_1 , V_156 ) ;
F_11 ( L_43 , V_1 , V_186 -> V_187 ,
V_186 -> V_188 ) ;
F_69 ( V_1 ) ;
}
static void
F_76 ( struct V_1 * V_1 )
{
F_77 ( & V_1 -> V_156 , F_74 ) ;
}
static void
F_78 ( struct V_1 * V_1 )
{
int V_58 ;
switch ( V_1 -> V_150 ) {
case V_189 :
break;
case V_184 :
case V_183 :
F_11 ( L_44 ,
V_1 , V_1 -> V_150 ) ;
V_1 -> V_150 = V_189 ;
V_58 = F_79 ( V_1 -> V_13 ) ;
if ( V_58 )
F_5 ( L_45 ,
V_1 ) ;
break;
default:
F_5 ( L_46 ,
V_1 , V_1 -> V_150 ) ;
}
}
static int
F_80 ( struct V_145 * V_145 ,
enum V_190 V_11 )
{
F_8 ( L_47 , V_145 , V_11 ) ;
switch ( V_11 ) {
case V_191 :
V_145 -> V_192 = NULL ;
break;
case V_193 :
V_145 -> V_192 = F_81 ( V_145 ) ;
if ( F_29 ( V_145 -> V_192 ) ) {
F_3 ( L_48 ,
V_145 , F_30 ( V_145 -> V_192 ) ) ;
V_145 -> V_192 = NULL ;
}
break;
default:
F_3 ( L_49 ,
V_145 , V_11 ) ;
}
return - 1 ;
}
static int
F_82 ( struct V_22 * V_23 ,
enum V_190 V_11 )
{
struct V_145 * V_145 = V_23 -> V_10 ;
struct V_1 * V_1 ;
if ( V_145 -> V_192 == V_23 )
return F_80 ( V_23 -> V_10 , V_11 ) ;
V_1 = V_23 -> V_60 -> V_38 ;
F_10 ( & V_1 -> V_157 ) ;
F_78 ( V_1 ) ;
F_12 ( & V_1 -> V_157 ) ;
F_11 ( L_50 , V_1 ) ;
F_83 ( & V_1 -> V_155 ) ;
return 0 ;
}
static void
F_84 ( struct V_22 * V_23 )
{
struct V_1 * V_1 = V_23 -> V_60 -> V_38 ;
F_76 ( V_1 ) ;
}
static int
F_85 ( struct V_22 * V_23 , struct V_144 * V_11 )
{
int V_19 = 0 ;
F_11 ( L_51 , V_11 -> V_11 ,
V_11 -> V_194 , V_23 , V_23 -> V_10 ) ;
switch ( V_11 -> V_11 ) {
case V_195 :
V_19 = F_55 ( V_23 , V_11 ) ;
if ( V_19 )
F_3 ( L_52 , V_19 ) ;
break;
case V_196 :
F_72 ( V_23 ) ;
break;
case V_193 :
case V_197 :
case V_191 :
case V_198 :
V_19 = F_82 ( V_23 , V_11 -> V_11 ) ;
break;
case V_199 :
case V_200 :
case V_201 :
F_84 ( V_23 ) ;
break;
default:
F_3 ( L_53 , V_11 -> V_11 ) ;
break;
}
return V_19 ;
}
static int
F_86 ( struct V_1 * V_1 , V_140 V_202 )
{
struct V_203 * V_204 , * V_205 ;
int V_31 , V_19 ;
unsigned int V_206 = V_1 -> V_77 ;
struct V_61 * V_62 ;
for ( V_204 = V_1 -> V_207 , V_31 = 0 ; V_31 < V_202 ; V_31 ++ , V_204 ++ ) {
V_62 = & V_1 -> V_67 [ V_206 ] ;
V_204 -> V_208 = ( V_209 ) V_62 ;
V_204 -> V_210 = & V_62 -> V_64 ;
V_204 -> V_211 = 1 ;
V_204 -> V_212 = V_204 + 1 ;
V_206 = ( V_206 + 1 ) & ( V_46 - 1 ) ;
}
V_204 -- ;
V_204 -> V_212 = NULL ;
V_1 -> V_213 += V_202 ;
V_19 = F_87 ( V_1 -> V_59 , V_1 -> V_207 ,
& V_205 ) ;
if ( V_19 ) {
F_3 ( L_54 , V_19 ) ;
V_1 -> V_213 -= V_202 ;
} else {
F_8 ( L_55 , V_202 ) ;
V_1 -> V_77 = V_206 ;
}
return V_19 ;
}
static int
F_88 ( struct V_1 * V_1 , struct V_214 * V_215 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_216 V_217 , * V_218 ;
int V_19 ;
F_89 ( V_16 , V_215 -> V_65 ,
V_219 , V_168 ) ;
V_217 . V_212 = NULL ;
V_217 . V_208 = ( V_209 ) V_215 ;
V_217 . V_210 = V_215 -> V_220 ;
V_217 . V_211 = V_215 -> V_211 ;
V_217 . V_221 = V_222 ;
V_217 . V_223 = V_224 ;
V_19 = F_90 ( V_1 -> V_59 , & V_217 , & V_218 ) ;
if ( V_19 )
F_3 ( L_56 , V_19 ) ;
return V_19 ;
}
static void
F_91 ( struct V_1 * V_1 ,
struct V_225 * V_225 ,
struct V_214 * V_215 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
F_92 ( V_16 , V_215 -> V_65 ,
V_219 , V_168 ) ;
memset ( & V_215 -> V_226 , 0 , sizeof( struct V_227 ) ) ;
V_215 -> V_226 . V_127 = V_228 ;
V_215 -> V_211 = 1 ;
V_215 -> V_225 = V_225 ;
if ( V_215 -> V_220 [ 0 ] . V_75 != V_1 -> V_76 -> V_75 ) {
V_215 -> V_220 [ 0 ] . V_75 = V_1 -> V_76 -> V_75 ;
F_8 ( L_57 , V_215 ) ;
}
}
static int
F_93 ( struct V_1 * V_1 ,
struct V_214 * V_215 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
T_1 V_65 ;
V_65 = F_18 ( V_16 , ( void * ) V_215 ,
V_219 , V_168 ) ;
if ( F_19 ( V_16 , V_65 ) ) {
F_3 ( L_58 ) ;
return - V_78 ;
}
V_215 -> V_65 = V_65 ;
V_215 -> V_220 [ 0 ] . V_73 = V_215 -> V_65 ;
V_215 -> V_220 [ 0 ] . V_74 = V_219 ;
V_215 -> V_220 [ 0 ] . V_75 = V_1 -> V_76 -> V_75 ;
F_8 ( L_59 ,
V_215 -> V_220 [ 0 ] . V_73 , V_215 -> V_220 [ 0 ] . V_74 ,
V_215 -> V_220 [ 0 ] . V_75 ) ;
return 0 ;
}
static void
F_94 ( struct V_1 * V_1 , struct V_225 * V_225 ,
struct V_216 * V_217 )
{
struct V_214 * V_215 = & V_225 -> V_215 ;
V_225 -> V_229 . V_230 = V_231 ;
V_217 -> V_208 = ( V_209 ) & V_225 -> V_215 ;
V_217 -> V_221 = V_222 ;
V_217 -> V_210 = & V_215 -> V_220 [ 0 ] ;
V_217 -> V_211 = V_225 -> V_215 . V_211 ;
V_217 -> V_223 = V_224 ;
}
static int
F_65 ( struct V_1 * V_1 )
{
struct V_203 V_204 , * V_232 ;
struct V_63 V_233 ;
int V_19 ;
memset ( & V_233 , 0 , sizeof( struct V_63 ) ) ;
V_233 . V_73 = V_1 -> V_165 ;
V_233 . V_74 = V_161 ;
V_233 . V_75 = V_1 -> V_76 -> V_75 ;
F_8 ( L_60 ,
V_233 . V_73 , V_233 . V_74 , V_233 . V_75 ) ;
memset ( & V_204 , 0 , sizeof( struct V_203 ) ) ;
V_204 . V_208 = ( V_209 ) V_1 -> V_163 ;
V_204 . V_210 = & V_233 ;
V_204 . V_211 = 1 ;
V_1 -> V_213 ++ ;
V_19 = F_87 ( V_1 -> V_59 , & V_204 , & V_232 ) ;
if ( V_19 ) {
F_3 ( L_61 , V_19 ) ;
V_1 -> V_213 -- ;
}
return V_19 ;
}
static int
F_95 ( struct V_234 * V_2 , struct V_235 * V_236 ,
V_140 V_74 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_214 * V_215 = & V_1 -> V_237 ;
int V_19 ;
F_91 ( V_1 , NULL , V_215 ) ;
memcpy ( & V_215 -> V_238 , & V_236 -> V_239 [ 0 ] ,
sizeof( struct V_240 ) ) ;
F_93 ( V_1 , V_215 ) ;
if ( V_74 > 0 ) {
struct V_63 * V_241 = & V_215 -> V_220 [ 1 ] ;
F_92 ( V_16 , V_1 -> V_167 ,
V_74 , V_168 ) ;
memcpy ( V_1 -> V_164 , V_236 -> V_242 , V_74 ) ;
F_89 ( V_16 , V_1 -> V_167 ,
V_74 , V_168 ) ;
V_241 -> V_73 = V_1 -> V_167 ;
V_241 -> V_74 = V_74 ;
V_241 -> V_75 = V_1 -> V_76 -> V_75 ;
V_215 -> V_211 = 2 ;
}
if ( ! V_236 -> V_243 ) {
if ( V_236 -> V_244 ) {
if ( ! V_2 -> V_136 -> V_245 -> V_246 &&
V_1 -> V_26 -> V_84 ) {
V_19 = F_53 ( V_1 ) ;
if ( V_19 ) {
F_3 ( L_62
L_63 , V_1 ) ;
return V_19 ;
}
}
V_19 = F_16 ( V_1 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_86 ( V_1 , V_247 ) ;
if ( V_19 )
return V_19 ;
F_10 ( & V_1 -> V_157 ) ;
V_1 -> V_150 = V_183 ;
F_12 ( & V_1 -> V_157 ) ;
goto V_248;
}
V_19 = F_65 ( V_1 ) ;
if ( V_19 )
return V_19 ;
}
V_248:
V_19 = F_88 ( V_1 , V_215 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void
F_96 ( struct V_1 * V_1 )
{
struct V_61 * V_62 = ( void * ) V_1 -> V_163 ;
int V_249 = V_1 -> V_250 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_235 * V_236 = V_2 -> V_251 ;
int V_252 ;
F_11 ( L_40 , V_1 ) ;
F_97 ( ! V_236 ) ;
if ( V_236 -> V_253 ) {
struct V_254 * V_255 =
(struct V_254 * ) & V_62 -> V_238 ;
V_236 -> V_256 = ( ! V_255 -> V_257 ) ? 1 : 0 ;
V_236 -> V_258 =
( V_255 -> V_127 & V_259 )
>> 2 ;
V_236 -> V_260 = V_255 -> V_261 ;
V_236 -> V_262 = V_255 -> V_263 ;
memcpy ( V_236 -> V_264 , V_255 -> V_264 , 6 ) ;
V_236 -> V_265 = F_98 ( V_255 -> V_266 ) ;
V_236 -> V_267 = V_255 -> V_268 ;
V_236 -> V_269 = F_98 ( V_255 -> V_270 ) ;
V_236 -> V_271 = F_99 ( V_255 -> V_271 ) ;
V_236 -> V_257 = F_99 ( V_255 -> V_257 ) ;
}
memcpy ( & V_236 -> V_272 [ 0 ] , ( void * ) & V_62 -> V_238 , V_273 ) ;
V_252 = V_32 ( V_249 , V_274 ) ;
F_8 ( L_64
L_65 , V_252 , V_249 ,
V_274 ) ;
memcpy ( V_236 -> V_275 , & V_62 -> V_276 [ 0 ] , V_252 ) ;
if ( V_236 -> V_253 ) {
F_83 ( & V_1 -> V_153 ) ;
return;
}
F_100 ( & V_2 -> V_277 , 0 ) ;
}
static struct V_278
* F_101 ( struct V_234 * V_2 )
{
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_225 * V_225 ;
struct V_278 * V_4 ;
V_4 = F_102 ( V_2 , V_279 ) ;
if ( ! V_4 ) {
F_3 ( L_66 ) ;
return NULL ;
}
V_225 = F_103 ( V_4 ) ;
V_225 -> V_2 = V_1 ;
V_225 -> V_278 = V_4 ;
return V_4 ;
}
static int
F_104 ( struct V_1 * V_1 ,
struct V_225 * V_225 , struct V_278 * V_4 ,
struct V_61 * V_62 , unsigned char * V_280 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_281 * V_282 = (struct V_281 * ) V_280 ;
struct V_283 * V_284 ;
int V_285 , V_286 , V_287 , V_288 , V_289 ;
bool V_290 = false ;
V_289 = F_105 ( V_2 , V_4 , V_280 ) ;
if ( V_289 < 0 )
return V_289 ;
V_285 = V_4 -> V_291 ;
V_286 = V_4 -> V_292 ;
V_287 = V_4 -> V_293 ;
V_289 = F_106 ( V_2 , V_4 , V_282 ) ;
if ( V_289 < 0 ) {
return 0 ;
} else if ( V_289 > 0 ) {
V_290 = true ;
goto V_294;
}
if ( ! V_285 )
return 0 ;
V_284 = & V_4 -> V_3 . V_295 [ 0 ] ;
V_288 = F_13 ( 1UL , F_107 ( V_286 , V_296 ) ) ;
F_8 ( L_67 ,
V_284 , V_288 , & V_62 -> V_276 [ 0 ] , V_286 ) ;
F_108 ( V_284 , V_288 , & V_62 -> V_276 [ 0 ] , V_286 ) ;
V_4 -> V_297 += V_286 ;
if ( V_4 -> V_297 == V_4 -> V_3 . V_298 ) {
F_56 ( & V_4 -> V_299 ) ;
V_4 -> V_300 |= V_301 ;
V_4 -> V_302 = V_303 ;
F_57 ( & V_4 -> V_299 ) ;
}
V_294:
V_289 = F_109 ( V_2 , V_4 , V_280 , V_282 -> V_266 ) ;
if ( ! V_289 && V_290 == false && V_287 )
F_110 ( V_4 ) ;
else if ( V_290 && V_285 )
F_111 ( V_2 -> V_136 -> V_135 , & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_112 ( struct V_1 * V_1 ,
struct V_61 * V_62 , unsigned char * V_280 )
{
struct V_283 * V_304 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_278 * V_4 = NULL ;
struct V_305 * V_282 = (struct V_305 * ) V_280 ;
V_140 V_306 = F_113 ( V_282 -> V_307 ) ;
int V_289 , V_288 , V_308 , V_309 ;
V_289 = F_114 ( V_2 , V_280 , & V_4 ) ;
if ( V_289 < 0 )
return V_289 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_293 ) {
F_3 ( L_68 ) ;
F_115 () ;
return - 1 ;
}
F_8 ( L_69
L_70 ,
V_306 , V_4 -> V_297 ,
V_4 -> V_3 . V_298 ) ;
V_308 = V_4 -> V_297 / V_296 ;
V_304 = & V_4 -> V_3 . V_295 [ V_308 ] ;
V_288 = F_13 ( 1UL , F_107 ( V_306 , V_296 ) ) ;
V_309 = V_4 -> V_297 % V_296 ;
if ( V_309 ) {
F_3 ( L_71 ) ;
F_115 () ;
return - 1 ;
}
F_8 ( L_72
L_73 , V_304 , V_308 ,
V_288 , & V_62 -> V_276 [ 0 ] , V_306 ) ;
F_108 ( V_304 , V_288 , & V_62 -> V_276 [ 0 ] ,
V_306 ) ;
V_289 = F_116 ( V_4 , V_282 , false ) ;
if ( V_289 < 0 )
return V_289 ;
return 0 ;
}
static int
F_117 ( struct V_1 * V_1 , struct V_225 * V_225 ,
struct V_278 * V_4 , struct V_61 * V_62 ,
unsigned char * V_280 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_310 * V_282 = (struct V_310 * ) V_280 ;
int V_289 ;
V_289 = F_118 ( V_2 , V_4 , V_282 ) ;
if ( V_289 < 0 )
return V_289 ;
return F_119 ( V_2 , V_4 , V_282 ) ;
}
static int
F_120 ( struct V_1 * V_1 , struct V_225 * V_225 ,
struct V_278 * V_4 , struct V_61 * V_62 ,
struct V_311 * V_282 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
V_140 V_312 = F_113 ( V_282 -> V_307 ) ;
int V_289 ;
unsigned char * V_313 = NULL ;
V_289 = F_121 ( V_2 , V_4 , V_282 ) ;
if ( V_289 < 0 )
return V_289 ;
if ( V_312 ) {
V_313 = F_17 ( V_312 , V_68 ) ;
if ( ! V_313 ) {
F_3 ( L_74 ,
V_312 ) ;
return - V_78 ;
}
}
V_4 -> V_314 = V_313 ;
memcpy ( V_4 -> V_314 , & V_62 -> V_276 [ 0 ] , V_312 ) ;
return F_122 ( V_2 , V_4 , V_282 ) ;
}
static int
F_123 ( struct V_1 * V_1 , struct V_61 * V_62 ,
T_2 V_315 , T_3 V_316 ,
T_2 V_317 , T_3 V_318 )
{
struct V_240 * V_282 = & V_62 -> V_238 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_319 * V_136 = V_2 -> V_136 ;
struct V_278 * V_4 ;
struct V_225 * V_225 ;
int V_19 = - V_320 ;
V_172 V_221 = ( V_282 -> V_221 & V_321 ) ;
if ( V_136 -> V_245 -> V_246 &&
( ! ( V_221 & V_322 ) || ! ( V_221 & V_323 ) ) ) {
F_3 ( L_75
L_76 , V_221 ) ;
return 0 ;
}
switch ( V_221 ) {
case V_324 :
V_4 = F_101 ( V_2 ) ;
if ( ! V_4 )
break;
V_225 = F_103 ( V_4 ) ;
V_225 -> V_315 = V_315 ;
V_225 -> V_316 = V_316 ;
V_225 -> V_317 = V_317 ;
V_225 -> V_318 = V_318 ;
V_19 = F_104 ( V_1 , V_225 , V_4 ,
V_62 , ( unsigned char * ) V_282 ) ;
break;
case V_325 :
V_4 = F_101 ( V_2 ) ;
if ( ! V_4 )
break;
V_225 = F_103 ( V_4 ) ;
V_19 = F_117 ( V_1 , V_225 , V_4 ,
V_62 , ( unsigned char * ) V_282 ) ;
break;
case V_326 :
V_19 = F_112 ( V_1 , V_62 ,
( unsigned char * ) V_282 ) ;
break;
case V_327 :
V_4 = F_101 ( V_2 ) ;
if ( ! V_4 )
break;
V_19 = F_124 ( V_2 , V_4 ,
( unsigned char * ) V_282 ) ;
break;
case V_323 :
V_4 = F_101 ( V_2 ) ;
if ( ! V_4 )
break;
V_19 = F_125 ( V_2 , V_4 , ( unsigned char * ) V_282 ) ;
break;
case V_322 :
if ( F_98 ( V_282 -> V_328 ) != 0xFFFFFFFF ) {
V_4 = F_126 ( V_2 , V_282 -> V_268 ) ;
if ( ! V_4 )
break;
} else {
V_4 = F_101 ( V_2 ) ;
if ( ! V_4 )
break;
}
V_225 = F_103 ( V_4 ) ;
V_19 = F_120 ( V_1 , V_225 , V_4 ,
V_62 , (struct V_311 * ) V_282 ) ;
break;
default:
F_3 ( L_77 , V_221 ) ;
F_115 () ;
break;
}
return V_19 ;
}
static void
F_127 ( struct V_61 * V_62 , struct V_1 * V_1 )
{
struct V_227 * V_227 = & V_62 -> V_226 ;
T_3 V_316 = 0 , V_318 = 0 ;
T_2 V_315 = 0 , V_317 = 0 ;
int V_289 ;
switch ( V_227 -> V_127 & 0xF0 ) {
case V_329 :
if ( V_227 -> V_127 & V_330 ) {
V_315 = F_98 ( V_227 -> V_315 ) ;
V_316 = F_128 ( V_227 -> V_316 ) ;
F_8 ( L_78 ,
V_315 , ( unsigned long long ) V_316 ) ;
}
if ( V_227 -> V_127 & V_331 ) {
V_317 = F_98 ( V_227 -> V_317 ) ;
V_318 = F_128 ( V_227 -> V_318 ) ;
F_8 ( L_79 ,
V_317 , ( unsigned long long ) V_318 ) ;
}
F_8 ( L_80 ) ;
break;
case V_332 :
F_3 ( L_81 ) ;
break;
default:
F_5 ( L_82 , V_227 -> V_127 ) ;
break;
}
V_289 = F_123 ( V_1 , V_62 ,
V_315 , V_316 , V_317 , V_318 ) ;
}
static void
F_129 ( struct V_61 * V_115 , struct V_1 * V_1 ,
V_140 V_333 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_240 * V_282 ;
T_1 V_334 ;
int V_249 , V_335 ;
if ( ( char * ) V_115 == V_1 -> V_163 ) {
V_334 = V_1 -> V_165 ;
V_249 = V_161 ;
F_8 ( L_83 ,
V_334 , V_249 ) ;
} else {
V_334 = V_115 -> V_65 ;
V_249 = V_70 ;
F_8 ( L_84 ,
V_334 , V_249 ) ;
}
F_92 ( V_16 , V_334 , V_249 , V_71 ) ;
V_282 = & V_115 -> V_238 ;
F_8 ( L_85 ,
V_282 -> V_221 , V_282 -> V_268 , V_282 -> V_127 ,
( int ) ( V_333 - V_219 ) ) ;
if ( ( char * ) V_115 == V_1 -> V_163 ) {
V_1 -> V_250 = V_333 - V_219 ;
if ( V_1 -> V_2 ) {
struct V_235 * V_236 = V_1 -> V_2 -> V_251 ;
if ( V_236 && ! V_236 -> V_253 )
F_96 ( V_1 ) ;
}
F_10 ( & V_1 -> V_157 ) ;
F_83 ( & V_1 -> V_154 ) ;
F_12 ( & V_1 -> V_157 ) ;
} else {
F_127 ( V_115 , V_1 ) ;
}
F_89 ( V_16 , V_334 , V_249 ,
V_71 ) ;
V_1 -> V_213 -- ;
F_8 ( L_86 ,
V_1 -> V_213 ) ;
if ( ( char * ) V_115 == V_1 -> V_163 )
return;
V_335 = V_1 -> V_213 ;
if ( V_335 + V_247 <= V_46 ) {
int V_58 , V_202 = V_32 ( V_46 - V_335 ,
V_247 ) ;
V_58 = F_86 ( V_1 , V_202 ) ;
if ( V_58 ) {
F_3 ( L_87 ,
V_202 , V_58 ) ;
}
}
}
static int
F_130 ( struct V_1 * V_1 , struct V_225 * V_225 ,
struct V_283 * V_284 , V_140 V_336 , V_140 V_74 , V_140 V_337 ,
enum V_338 V_339 , struct V_340 * V_276 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
V_276 -> V_341 = V_339 == V_342 ?
V_168 : V_71 ;
V_276 -> V_343 = V_74 - V_337 ;
V_276 -> V_337 = V_337 ;
V_276 -> V_308 = V_276 -> V_337 / V_296 ;
V_276 -> V_284 = & V_284 [ V_276 -> V_308 ] ;
V_276 -> V_336 = F_24 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_276 -> V_343 = F_24 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_276 -> V_344 = F_131 ( V_16 , V_276 -> V_284 , V_276 -> V_336 ,
V_276 -> V_341 ) ;
if ( F_132 ( ! V_276 -> V_344 ) ) {
F_3 ( L_88 , V_284 ) ;
return - V_320 ;
}
F_8 ( L_89 ,
V_225 , V_276 -> V_344 , V_276 -> V_284 , V_276 -> V_336 , V_276 -> V_343 ) ;
return 0 ;
}
static void
F_133 ( struct V_1 * V_1 , struct V_340 * V_276 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
F_134 ( V_16 , V_276 -> V_284 , V_276 -> V_336 , V_276 -> V_341 ) ;
memset ( V_276 , 0 , sizeof( * V_276 ) ) ;
}
static void
V_90 ( struct V_225 * V_225 , struct V_1 * V_1 )
{
struct V_345 * V_346 = & V_225 -> V_229 ;
F_8 ( L_90 , V_225 ) ;
if ( V_346 -> V_276 . V_284 ) {
F_8 ( L_91 , V_225 ) ;
F_133 ( V_1 , & V_346 -> V_276 ) ;
}
if ( V_346 -> V_217 ) {
F_8 ( L_92 , V_225 ) ;
F_21 ( V_346 -> V_217 ) ;
V_346 -> V_217 = NULL ;
}
if ( V_346 -> V_63 ) {
F_8 ( L_93 , V_225 ) ;
F_21 ( V_346 -> V_63 ) ;
V_346 -> V_63 = NULL ;
}
}
static void
V_88 ( struct V_225 * V_225 , struct V_1 * V_1 )
{
struct V_345 * V_346 = & V_225 -> V_229 ;
F_135 ( V_347 ) ;
F_8 ( L_90 , V_225 ) ;
if ( V_346 -> V_104 ) {
F_8 ( L_94 , V_225 , V_346 -> V_104 ) ;
if ( V_346 -> V_104 -> V_124 & V_131 ) {
F_133 ( V_1 , & V_346 -> V_348 ) ;
V_346 -> V_104 -> V_124 &= ~ V_131 ;
}
F_56 ( & V_1 -> V_158 ) ;
F_41 ( & V_346 -> V_104 -> V_107 , & V_1 -> V_106 ) ;
F_57 ( & V_1 -> V_158 ) ;
V_346 -> V_104 = NULL ;
}
if ( V_346 -> V_276 . V_284 ) {
F_8 ( L_91 , V_225 ) ;
F_133 ( V_1 , & V_346 -> V_276 ) ;
}
V_346 -> V_63 = NULL ;
V_346 -> V_217 = NULL ;
}
static void
F_136 ( struct V_225 * V_225 , bool V_349 )
{
struct V_278 * V_4 = V_225 -> V_278 ;
struct V_1 * V_1 = V_225 -> V_2 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_350 * V_282 ;
F_8 ( L_90 , V_225 ) ;
switch ( V_4 -> V_351 ) {
case V_324 :
F_56 ( & V_2 -> V_352 ) ;
if ( ! F_43 ( & V_4 -> V_353 ) )
F_137 ( & V_4 -> V_353 ) ;
F_57 ( & V_2 -> V_352 ) ;
if ( V_4 -> V_354 == V_168 ) {
F_138 ( V_4 ) ;
if ( V_349 &&
V_4 -> V_3 . V_355 == V_356 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_111 ( V_3 -> V_135 , V_3 ) ;
}
}
V_25 -> V_87 ( V_225 , V_1 ) ;
F_139 ( & V_4 -> V_3 , 0 ) ;
break;
case V_327 :
F_56 ( & V_2 -> V_352 ) ;
if ( ! F_43 ( & V_4 -> V_353 ) )
F_137 ( & V_4 -> V_353 ) ;
F_57 ( & V_2 -> V_352 ) ;
F_139 ( & V_4 -> V_3 , 0 ) ;
break;
case V_357 :
case V_325 :
case V_322 :
V_282 = (struct V_350 * ) & V_225 -> V_215 . V_238 ;
if ( V_282 -> V_127 & V_358 )
break;
F_56 ( & V_2 -> V_352 ) ;
if ( ! F_43 ( & V_4 -> V_353 ) )
F_137 ( & V_4 -> V_353 ) ;
F_57 ( & V_2 -> V_352 ) ;
if ( V_4 -> V_3 . V_359 != NULL ) {
F_8 ( L_95 ,
V_4 -> V_351 ) ;
F_139 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_140 ( V_4 ) ;
break;
}
}
static void
F_141 ( struct V_214 * V_215 , struct V_15 * V_16 )
{
if ( V_215 -> V_65 != 0 ) {
F_8 ( L_96 ) ;
F_20 ( V_16 , V_215 -> V_65 ,
V_219 , V_168 ) ;
V_215 -> V_65 = 0 ;
}
}
static void
F_142 ( struct V_214 * V_215 , struct V_225 * V_225 ,
struct V_15 * V_16 , bool V_349 )
{
if ( V_225 -> V_360 != 0 ) {
F_8 ( L_97 ) ;
F_20 ( V_16 , V_225 -> V_360 ,
V_225 -> V_361 , V_168 ) ;
V_225 -> V_360 = 0 ;
}
F_141 ( V_215 , V_16 ) ;
F_136 ( V_225 , V_349 ) ;
}
static int
F_143 ( struct V_3 * V_3 , struct V_362 * V_113 )
{
struct V_363 V_364 ;
int V_19 ;
V_19 = F_144 ( V_113 , V_365 , & V_364 ) ;
if ( V_19 ) {
F_3 ( L_98 , V_19 ) ;
goto V_366;
}
if ( V_364 . V_367 & V_365 ) {
T_1 V_368 ;
V_140 V_369 = V_3 -> V_370 -> V_371 . V_369 + 8 ;
switch ( V_364 . V_372 . V_373 ) {
case V_374 :
V_3 -> V_375 = V_376 ;
break;
case V_377 :
V_3 -> V_375 = V_378 ;
break;
case V_379 :
V_3 -> V_375 = V_380 ;
break;
}
V_368 = V_364 . V_372 . V_381 ;
F_145 ( V_368 , V_369 ) ;
V_3 -> V_382 = V_368 + V_3 -> V_383 ;
F_3 ( L_99
L_100 ,
V_364 . V_372 . V_373 ,
( unsigned long long ) V_3 -> V_382 ,
V_364 . V_372 . V_384 ,
V_364 . V_372 . V_385 ) ;
V_19 = 1 ;
}
V_366:
return V_19 ;
}
static void
F_146 ( struct V_214 * V_215 ,
struct V_225 * V_225 )
{
struct V_345 * V_346 = & V_225 -> V_229 ;
struct V_278 * V_4 = V_225 -> V_278 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_225 -> V_2 ;
struct V_24 * V_25 = V_1 -> V_26 ;
int V_19 = 0 ;
if ( V_346 -> V_104 && V_346 -> V_104 -> V_124 & V_131 ) {
V_19 = F_143 ( V_3 ,
V_346 -> V_104 -> V_110 -> V_113 ) ;
V_346 -> V_104 -> V_124 &= ~ V_131 ;
}
V_25 -> V_87 ( V_225 , V_1 ) ;
V_346 -> V_386 = 0 ;
if ( V_19 )
F_147 ( V_3 ,
V_3 -> V_375 , 0 ) ;
else
F_148 ( V_1 -> V_2 , V_4 ) ;
}
static void
F_149 ( struct V_214 * V_215 ,
struct V_225 * V_225 )
{
struct V_345 * V_346 = & V_225 -> V_229 ;
struct V_278 * V_4 = V_225 -> V_278 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_225 -> V_2 ;
struct V_24 * V_25 = V_1 -> V_26 ;
int V_19 = 0 ;
if ( V_346 -> V_104 && V_346 -> V_104 -> V_124 & V_131 ) {
V_19 = F_143 ( V_3 ,
V_346 -> V_104 -> V_110 -> V_113 ) ;
V_346 -> V_104 -> V_124 &= ~ V_131 ;
}
F_138 ( V_4 ) ;
V_25 -> V_87 ( V_225 , V_1 ) ;
V_4 -> V_297 = V_346 -> V_276 . V_343 ;
V_346 -> V_386 = 0 ;
F_8 ( L_101 , V_225 ) ;
F_56 ( & V_4 -> V_299 ) ;
V_4 -> V_300 |= V_301 ;
V_4 -> V_302 = V_303 ;
F_57 ( & V_4 -> V_299 ) ;
if ( V_19 )
F_147 ( V_3 ,
V_3 -> V_375 , 0 ) ;
else
F_150 ( V_3 ) ;
}
static void
F_151 ( struct V_387 * V_94 )
{
struct V_225 * V_225 = F_75 ( V_94 ,
struct V_225 , V_388 ) ;
struct V_1 * V_1 = V_225 -> V_2 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_278 * V_4 = V_225 -> V_278 ;
F_8 ( L_102 , V_225 , V_4 -> V_302 ) ;
switch ( V_4 -> V_302 ) {
case V_389 :
F_152 ( V_4 , V_4 -> V_2 ) ;
case V_390 :
case V_391 :
V_4 -> V_302 = V_392 ;
F_142 ( & V_225 -> V_215 , V_225 ,
V_16 , false ) ;
break;
case V_393 :
F_153 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_103 , V_4 -> V_302 ) ;
F_115 () ;
break;
}
}
static void
F_154 ( struct V_214 * V_215 ,
struct V_225 * V_225 ,
struct V_1 * V_1 ,
struct V_15 * V_16 )
{
struct V_278 * V_4 = V_225 -> V_278 ;
if ( V_4 -> V_302 == V_389 ||
V_4 -> V_302 == V_393 ||
V_4 -> V_302 == V_390 ||
V_4 -> V_302 == V_391 ) {
F_141 ( V_215 , V_16 ) ;
F_27 ( & V_225 -> V_388 , F_151 ) ;
F_155 ( V_394 , & V_225 -> V_388 ) ;
return;
}
V_4 -> V_302 = V_392 ;
F_142 ( V_215 , V_225 , V_16 , false ) ;
}
static void
F_156 ( struct V_214 * V_215 ,
struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_225 * V_225 = V_215 -> V_225 ;
struct V_345 * V_346 ;
if ( ! V_225 ) {
F_141 ( V_215 , V_16 ) ;
return;
}
V_346 = & V_225 -> V_229 ;
F_8 ( L_104 , V_225 , V_346 -> V_230 ) ;
switch ( V_346 -> V_230 ) {
case V_395 :
F_3 ( L_105 ) ;
F_115 () ;
break;
case V_231 :
F_154 ( V_215 , V_225 ,
V_1 , V_16 ) ;
break;
case V_342 :
F_146 ( V_215 , V_225 ) ;
break;
case V_396 :
F_149 ( V_215 , V_225 ) ;
break;
default:
F_3 ( L_106 , V_346 -> V_230 ) ;
F_115 () ;
break;
}
}
static inline bool
F_157 ( struct V_1 * V_1 , void * V_208 )
{
void * V_397 = V_1 -> V_67 ;
int V_343 = V_46 * sizeof( * V_1 -> V_67 ) ;
if ( V_208 >= V_397 && V_208 < V_397 + V_343 )
return false ;
return true ;
}
static void
F_158 ( struct V_1 * V_1 , struct V_398 * V_399 )
{
if ( V_399 -> V_208 == V_400 ) {
F_11 ( L_107 ,
V_1 ) ;
F_83 ( & V_1 -> V_401 ) ;
} else if ( F_157 ( V_1 , ( void * ) ( V_209 ) V_399 -> V_208 ) ) {
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_225 * V_225 ;
struct V_214 * V_115 ;
V_115 = (struct V_214 * ) ( V_209 ) V_399 -> V_208 ;
V_225 = V_115 -> V_225 ;
if ( ! V_225 )
F_141 ( V_115 , V_16 ) ;
else
F_142 ( V_115 , V_225 , V_16 , true ) ;
} else {
V_1 -> V_213 -- ;
if ( ! V_1 -> V_213 )
F_159 ( V_1 -> V_2 , 0 ) ;
}
}
static void
F_160 ( struct V_398 * V_399 )
{
struct V_1 * V_1 ;
struct V_214 * V_215 ;
struct V_61 * V_62 ;
V_1 = V_399 -> V_60 -> V_38 ;
if ( F_161 ( V_399 -> V_194 == V_402 ) ) {
if ( V_399 -> V_221 == V_403 ) {
V_62 = (struct V_61 * ) ( V_209 ) V_399 -> V_208 ;
F_129 ( V_62 , V_1 , V_399 -> V_404 ) ;
} else {
V_215 = (struct V_214 * ) ( V_209 ) V_399 -> V_208 ;
F_156 ( V_215 , V_1 ) ;
}
} else {
if ( V_399 -> V_194 != V_405 )
F_3 ( L_108 ,
V_399 -> V_208 , V_399 -> V_194 , V_399 -> V_406 ) ;
else
F_8 ( L_109 , V_399 -> V_208 ) ;
if ( V_399 -> V_208 != V_407 )
F_158 ( V_1 , V_399 ) ;
}
}
static void
V_95 ( struct V_387 * V_94 )
{
enum { V_408 = 65536 };
struct V_29 * V_30 = F_75 ( V_94 , struct V_29 ,
V_94 ) ;
struct V_398 * const V_409 = V_30 -> V_409 ;
int V_31 , V_410 , V_411 = 0 ;
while ( ( V_410 = F_162 ( V_30 -> V_40 , F_163 ( V_30 -> V_409 ) , V_409 ) ) > 0 ) {
for ( V_31 = 0 ; V_31 < V_410 ; V_31 ++ )
F_160 ( & V_409 [ V_31 ] ) ;
V_411 += V_410 ;
if ( V_411 >= V_408 )
break;
}
F_31 ( V_30 -> V_40 , V_98 ) ;
}
static void
V_96 ( struct V_412 * V_40 , void * V_10 )
{
struct V_29 * V_30 = V_10 ;
F_155 ( V_394 , & V_30 -> V_94 ) ;
}
static int
F_164 ( struct V_1 * V_1 , struct V_225 * V_225 )
{
struct V_216 * V_413 ;
int V_19 ;
V_19 = F_90 ( V_1 -> V_59 , & V_225 -> V_215 . V_217 ,
& V_413 ) ;
if ( V_19 ) {
F_3 ( L_110 , V_19 ) ;
return V_19 ;
}
return V_19 ;
}
static int
F_148 ( struct V_234 * V_2 , struct V_278 * V_4 )
{
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_216 * V_217 = & V_225 -> V_215 . V_217 ;
struct V_414 * V_282 = (struct V_414 * )
& V_225 -> V_215 . V_238 ;
F_91 ( V_1 , V_225 , & V_225 -> V_215 ) ;
F_165 ( V_4 , V_2 , true , V_282 ) ;
F_93 ( V_1 , & V_225 -> V_215 ) ;
if ( V_4 -> V_3 . V_415 &&
( ( V_4 -> V_3 . V_416 & V_417 ) ||
( V_4 -> V_3 . V_416 & V_418 ) ) ) {
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_63 * V_241 = & V_225 -> V_215 . V_220 [ 1 ] ;
V_140 V_419 , V_420 ;
F_166 ( V_4 -> V_3 . V_421 ,
V_4 -> V_415 ) ;
V_4 -> V_3 . V_421 += sizeof( V_422 ) ;
V_419 = - ( V_4 -> V_3 . V_421 ) & 3 ;
F_167 ( V_282 -> V_307 , ( V_140 ) V_4 -> V_3 . V_421 ) ;
V_420 = V_4 -> V_3 . V_421 + V_419 ;
V_225 -> V_360 = F_18 ( V_16 ,
( void * ) V_4 -> V_415 , V_420 ,
V_168 ) ;
V_225 -> V_361 = V_420 ;
V_241 -> V_73 = V_225 -> V_360 ;
V_241 -> V_74 = V_420 ;
V_241 -> V_75 = V_1 -> V_76 -> V_75 ;
V_225 -> V_215 . V_211 = 2 ;
}
F_94 ( V_1 , V_225 , V_217 ) ;
F_8 ( L_111 ) ;
return F_164 ( V_1 , V_225 ) ;
}
static void
F_168 ( struct V_234 * V_2 , struct V_278 * V_4 )
{
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_24 * V_25 = V_1 -> V_26 ;
F_56 ( & V_2 -> V_352 ) ;
if ( ! F_43 ( & V_4 -> V_353 ) )
F_137 ( & V_4 -> V_353 ) ;
F_57 ( & V_2 -> V_352 ) ;
if ( V_4 -> V_354 == V_168 )
F_138 ( V_4 ) ;
V_25 -> V_87 ( V_225 , V_1 ) ;
}
static enum V_423
F_169 ( struct V_234 * V_2 )
{
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_24 * V_25 = V_1 -> V_26 ;
if ( V_2 -> V_424 -> V_425 . V_426 ) {
if ( V_25 -> V_54 ) {
F_11 ( L_112 , V_1 ) ;
V_1 -> V_5 = true ;
return V_427 ;
}
}
F_11 ( L_113 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_170 ( struct V_278 * V_4 , struct V_234 * V_2 ,
bool V_428 )
{
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_216 * V_217 = & V_225 -> V_215 . V_217 ;
F_91 ( V_1 , V_225 , & V_225 -> V_215 ) ;
F_171 ( V_4 , V_2 , (struct V_429 * )
& V_225 -> V_215 . V_238 ,
V_428 ) ;
F_93 ( V_1 , & V_225 -> V_215 ) ;
F_94 ( V_1 , V_225 , V_217 ) ;
F_8 ( L_114 , V_1 ) ;
return F_164 ( V_1 , V_225 ) ;
}
static int
F_172 ( struct V_278 * V_4 , struct V_234 * V_2 )
{
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_216 * V_217 = & V_225 -> V_215 . V_217 ;
F_91 ( V_1 , V_225 , & V_225 -> V_215 ) ;
F_173 ( V_4 , V_2 , (struct V_430 * )
& V_225 -> V_215 . V_238 ) ;
F_93 ( V_1 , & V_225 -> V_215 ) ;
F_94 ( V_1 , V_225 , V_217 ) ;
F_8 ( L_115 , V_1 ) ;
return F_164 ( V_1 , V_225 ) ;
}
static int
F_174 ( struct V_278 * V_4 , struct V_234 * V_2 )
{
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_216 * V_217 = & V_225 -> V_215 . V_217 ;
F_91 ( V_1 , V_225 , & V_225 -> V_215 ) ;
F_175 ( V_4 , V_2 , (struct V_431 * )
& V_225 -> V_215 . V_238 ) ;
F_93 ( V_1 , & V_225 -> V_215 ) ;
F_94 ( V_1 , V_225 , V_217 ) ;
F_8 ( L_116 , V_1 ) ;
return F_164 ( V_1 , V_225 ) ;
}
static int
F_176 ( struct V_278 * V_4 , struct V_234 * V_2 )
{
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_216 * V_217 = & V_225 -> V_215 . V_217 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_63 * V_241 = & V_225 -> V_215 . V_220 [ 1 ] ;
struct V_432 * V_282 =
(struct V_432 * ) & V_225 -> V_215 . V_238 ;
F_91 ( V_1 , V_225 , & V_225 -> V_215 ) ;
F_177 ( V_4 , V_2 , V_282 ) ;
F_93 ( V_1 , & V_225 -> V_215 ) ;
F_167 ( V_282 -> V_307 , V_273 ) ;
V_225 -> V_360 = F_18 ( V_16 ,
( void * ) V_4 -> V_433 , V_273 ,
V_168 ) ;
V_225 -> V_361 = V_273 ;
V_241 -> V_73 = V_225 -> V_360 ;
V_241 -> V_74 = V_273 ;
V_241 -> V_75 = V_1 -> V_76 -> V_75 ;
V_225 -> V_215 . V_211 = 2 ;
F_94 ( V_1 , V_225 , V_217 ) ;
F_8 ( L_117 , V_1 ) ;
return F_164 ( V_1 , V_225 ) ;
}
static int
F_178 ( struct V_278 * V_4 , struct V_234 * V_2 )
{
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_216 * V_217 = & V_225 -> V_215 . V_217 ;
struct V_350 * V_282 =
(struct V_350 * ) & V_225 -> V_215 . V_238 ;
V_140 V_434 ;
int V_289 ;
F_91 ( V_1 , V_225 , & V_225 -> V_215 ) ;
V_289 = F_179 ( V_4 , V_2 , V_282 , V_435 ) ;
if ( V_289 < 0 )
return V_289 ;
V_434 = V_289 ;
F_93 ( V_1 , & V_225 -> V_215 ) ;
if ( V_434 ) {
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_63 * V_241 = & V_225 -> V_215 . V_220 [ 1 ] ;
void * V_436 = V_4 -> V_433 ;
V_225 -> V_360 = F_18 ( V_16 ,
V_436 , V_434 , V_168 ) ;
V_225 -> V_361 = V_434 ;
V_241 -> V_73 = V_225 -> V_360 ;
V_241 -> V_74 = V_434 ;
V_241 -> V_75 = V_1 -> V_76 -> V_75 ;
V_225 -> V_215 . V_211 = 2 ;
}
F_94 ( V_1 , V_225 , V_217 ) ;
F_8 ( L_118 , V_1 ) ;
return F_164 ( V_1 , V_225 ) ;
}
static int
F_180 ( struct V_1 * V_1 , struct V_225 * V_225 ,
struct V_63 * V_63 , struct V_216 * V_217 ,
V_140 V_437 , V_140 V_337 )
{
struct V_278 * V_4 = V_225 -> V_278 ;
struct V_283 * V_304 , * V_438 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
V_140 V_308 , V_309 ;
int V_31 = 0 , V_288 ;
V_308 = V_337 / V_296 ;
V_304 = & V_4 -> V_3 . V_295 [ V_308 ] ;
V_288 = V_32 ( V_4 -> V_3 . V_439 - V_308 , V_1 -> V_20 ) ;
V_309 = V_337 % V_296 ;
V_217 -> V_210 = V_63 ;
V_217 -> V_211 = V_288 ;
V_217 -> V_208 = ( V_209 ) & V_225 -> V_215 ;
F_181 (sg_start, tmp_sg, sg_nents, i) {
F_8 ( L_119
L_120 ,
( unsigned long long ) V_438 -> V_440 ,
V_438 -> V_74 , V_309 ) ;
V_63 -> V_73 = F_182 ( V_16 , V_438 ) + V_309 ;
V_63 -> V_74 = F_24 ( V_140 , V_437 ,
F_183 ( V_16 , V_438 ) - V_309 ) ;
V_63 -> V_75 = V_1 -> V_76 -> V_75 ;
F_8 ( L_121 ,
V_63 -> V_73 , V_63 -> V_74 , V_63 -> V_75 ) ;
V_309 = 0 ;
V_437 -= V_63 -> V_74 ;
V_63 ++ ;
F_8 ( L_122 , V_63 ) ;
}
F_8 ( L_123 ,
V_217 -> V_210 , V_217 -> V_211 ) ;
return V_288 ;
}
static int
V_89 ( struct V_234 * V_2 , struct V_278 * V_4 ,
struct V_345 * V_346 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_340 * V_276 = & V_346 -> V_276 ;
struct V_216 * V_217 ;
struct V_63 * V_63 ;
V_140 V_337 , V_441 , V_437 , V_442 , V_443 = 0 ;
int V_19 = 0 , V_31 , V_444 ;
V_225 -> V_215 . V_225 = V_225 ;
V_337 = V_346 -> V_230 == V_396 ? V_4 -> V_297 : 0 ;
V_19 = F_130 ( V_1 , V_225 , V_3 -> V_295 ,
V_3 -> V_439 , V_3 -> V_298 ,
V_337 , V_346 -> V_230 , & V_346 -> V_276 ) ;
if ( V_19 )
return V_19 ;
V_437 = V_276 -> V_343 ;
V_337 = V_276 -> V_337 ;
V_63 = F_17 ( sizeof( struct V_63 ) * V_276 -> V_336 , V_68 ) ;
if ( ! V_63 ) {
F_5 ( L_124 ) ;
V_19 = - V_78 ;
goto V_445;
}
V_346 -> V_63 = V_63 ;
V_346 -> V_386 = F_107 ( V_276 -> V_336 , V_1 -> V_20 ) ;
V_346 -> V_217 = F_17 ( sizeof( struct V_216 ) * V_346 -> V_386 ,
V_68 ) ;
if ( ! V_346 -> V_217 ) {
F_8 ( L_125 ) ;
V_19 = - V_78 ;
goto V_445;
}
V_346 -> V_225 = V_225 ;
V_442 = V_1 -> V_20 * V_296 ;
for ( V_31 = 0 ; V_31 < V_346 -> V_386 ; V_31 ++ ) {
V_217 = & V_225 -> V_229 . V_217 [ V_31 ] ;
V_441 = V_32 ( V_437 , V_442 ) ;
V_217 -> V_223 = 0 ;
if ( V_346 -> V_230 == V_342 ) {
V_217 -> V_221 = V_446 ;
V_217 -> V_346 . V_447 . V_448 = V_225 -> V_316 + V_337 ;
V_217 -> V_346 . V_447 . V_449 = V_225 -> V_315 ;
if ( V_31 + 1 == V_346 -> V_386 )
V_217 -> V_212 = & V_225 -> V_215 . V_217 ;
else
V_217 -> V_212 = & V_346 -> V_217 [ V_31 + 1 ] ;
} else {
V_217 -> V_221 = V_450 ;
V_217 -> V_346 . V_447 . V_448 = V_225 -> V_318 + V_443 ;
V_217 -> V_346 . V_447 . V_449 = V_225 -> V_317 ;
if ( V_31 + 1 == V_346 -> V_386 )
V_217 -> V_223 = V_224 ;
else
V_217 -> V_212 = & V_346 -> V_217 [ V_31 + 1 ] ;
}
V_444 = F_180 ( V_1 , V_225 , V_63 ,
V_217 , V_441 , V_337 ) ;
V_63 += V_444 ;
V_337 += V_441 ;
V_443 += V_441 ;
V_437 -= V_441 ;
}
return 0 ;
V_445:
F_133 ( V_1 , V_276 ) ;
return V_19 ;
}
static int
F_184 ( struct V_15 * V_16 ,
struct V_283 * V_304 , int V_288 , T_1 * V_451 )
{
T_1 V_452 , V_453 , V_454 , V_455 = 0 ;
struct V_283 * V_438 ;
int V_31 = 0 , V_456 , V_457 , V_458 ;
V_458 = 0 ;
V_456 = 1 ;
V_457 = V_288 - 1 ;
F_181 (sg_start, tmp_sg, sg_nents, i) {
V_452 = F_182 ( V_16 , V_438 ) ;
if ( V_456 )
V_455 = V_452 ;
V_453 = V_452 + F_183 ( V_16 , V_438 ) ;
F_8 ( L_126 ,
V_31 , ( unsigned long long ) V_438 -> V_440 ,
V_438 -> V_74 ) ;
if ( ( V_453 & ~ V_459 ) && V_31 < V_457 ) {
V_456 = 0 ;
continue;
}
V_456 = 1 ;
V_454 = V_455 & V_459 ;
do {
V_451 [ V_458 ++ ] = V_454 ;
F_8 ( L_127 ,
V_458 - 1 , V_454 ) ;
V_454 += V_296 ;
} while ( V_454 < V_453 );
}
return V_458 ;
}
static inline void
F_185 ( struct V_216 * V_460 , struct V_362 * V_461 )
{
V_140 V_449 ;
memset ( V_460 , 0 , sizeof( * V_460 ) ) ;
V_460 -> V_208 = V_407 ;
V_460 -> V_221 = V_462 ;
V_460 -> V_463 . V_464 = V_461 -> V_449 ;
V_449 = F_186 ( V_461 -> V_449 ) ;
F_187 ( V_461 , V_449 ) ;
}
static int
F_188 ( struct V_1 * V_1 ,
struct V_103 * V_104 ,
struct V_340 * V_465 ,
enum V_466 V_124 ,
struct V_63 * V_233 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_25 ;
struct V_362 * V_461 ;
struct V_467 * V_468 ;
struct V_216 V_469 , V_460 ;
struct V_216 * V_470 , * V_346 = NULL ;
int V_19 , V_471 ;
V_140 V_309 ;
if ( V_465 -> V_344 == 1 ) {
V_233 -> V_75 = V_1 -> V_76 -> V_75 ;
V_233 -> V_73 = F_182 ( V_16 , & V_465 -> V_284 [ 0 ] ) ;
V_233 -> V_74 = F_183 ( V_16 , & V_465 -> V_284 [ 0 ] ) ;
F_8 ( L_128 ,
V_233 -> V_73 , V_233 -> V_74 , V_233 -> V_75 ) ;
return 0 ;
}
if ( V_124 == V_133 ) {
V_461 = V_104 -> V_109 ;
V_468 = V_104 -> V_108 ;
} else {
V_461 = V_104 -> V_110 -> V_112 ;
V_468 = V_104 -> V_110 -> V_111 ;
}
V_309 = V_465 -> V_337 % V_296 ;
F_8 ( L_129 ,
V_104 , V_465 -> V_336 , V_465 -> V_337 ) ;
V_471 = F_184 ( V_16 , V_465 -> V_284 , V_465 -> V_336 ,
& V_468 -> V_472 [ 0 ] ) ;
if ( ! ( V_104 -> V_124 & V_124 ) ) {
F_185 ( & V_460 , V_461 ) ;
V_346 = & V_460 ;
}
memset ( & V_469 , 0 , sizeof( V_469 ) ) ;
V_469 . V_208 = V_407 ;
V_469 . V_221 = V_473 ;
V_469 . V_346 . V_474 . V_475 = V_468 -> V_472 [ 0 ] + V_309 ;
V_469 . V_346 . V_474 . V_472 = V_468 ;
V_469 . V_346 . V_474 . V_476 = V_471 ;
V_469 . V_346 . V_474 . V_477 = V_478 ;
V_469 . V_346 . V_474 . V_74 = V_465 -> V_343 ;
V_469 . V_346 . V_474 . V_449 = V_461 -> V_449 ;
V_469 . V_346 . V_474 . V_479 = V_176 ;
if ( ! V_346 )
V_346 = & V_469 ;
else
V_346 -> V_212 = & V_469 ;
V_19 = F_90 ( V_1 -> V_59 , V_346 , & V_470 ) ;
if ( V_19 ) {
F_3 ( L_130 , V_19 ) ;
return V_19 ;
}
V_104 -> V_124 &= ~ V_124 ;
V_233 -> V_75 = V_461 -> V_75 ;
V_233 -> V_73 = V_468 -> V_472 [ 0 ] + V_309 ;
V_233 -> V_74 = V_465 -> V_343 ;
F_8 ( L_128 ,
V_233 -> V_73 , V_233 -> V_74 , V_233 -> V_75 ) ;
return V_19 ;
}
static inline void
F_189 ( struct V_3 * V_3 , struct V_480 * V_481 ,
struct V_482 * V_483 )
{
V_483 -> V_484 = V_485 ;
V_483 -> V_486 . V_487 . V_488 = V_489 ;
V_483 -> V_486 . V_487 . V_490 = V_3 -> V_370 -> V_371 . V_369 ;
V_483 -> V_486 . V_487 . V_491 = V_3 -> V_492 ;
V_483 -> V_486 . V_487 . V_493 = 0xffff ;
V_483 -> V_486 . V_487 . V_494 = true ;
V_483 -> V_486 . V_487 . V_495 = true ;
if ( V_3 -> V_496 == V_497 ||
V_3 -> V_496 == V_498 )
V_483 -> V_486 . V_487 . V_499 = true ;
}
static int
F_190 ( struct V_3 * V_3 , struct V_480 * V_481 )
{
switch ( V_3 -> V_6 ) {
case V_500 :
case V_501 :
V_481 -> V_465 . V_484 = V_502 ;
F_189 ( V_3 , V_481 , & V_481 -> V_503 ) ;
break;
case V_504 :
case V_505 :
V_481 -> V_503 . V_484 = V_502 ;
F_189 ( V_3 , V_481 , & V_481 -> V_465 ) ;
break;
case V_506 :
case V_507 :
F_189 ( V_3 , V_481 , & V_481 -> V_503 ) ;
F_189 ( V_3 , V_481 , & V_481 -> V_465 ) ;
break;
default:
F_3 ( L_131 , V_3 -> V_6 ) ;
return - V_320 ;
}
return 0 ;
}
static inline V_172
F_191 ( V_172 V_508 )
{
return ( V_508 & V_509 ? 0xc0 : 0 ) |
( V_508 & V_510 ? 0x30 : 0 ) |
( V_508 & V_510 ? 0x0f : 0 ) ;
}
static int
F_192 ( struct V_1 * V_1 ,
struct V_3 * V_3 ,
struct V_345 * V_229 ,
struct V_103 * V_104 )
{
struct V_216 V_511 , V_460 ;
struct V_216 * V_470 , * V_346 = NULL ;
struct V_120 * V_110 = V_104 -> V_110 ;
struct V_480 V_481 ;
int V_19 ;
memset ( & V_481 , 0 , sizeof( V_481 ) ) ;
V_19 = F_190 ( V_3 , & V_481 ) ;
if ( V_19 )
goto V_58;
V_481 . V_512 = F_191 ( V_3 -> V_508 ) ;
if ( ! ( V_104 -> V_124 & V_130 ) ) {
F_185 ( & V_460 , V_110 -> V_113 ) ;
V_346 = & V_460 ;
}
memset ( & V_511 , 0 , sizeof( V_511 ) ) ;
V_511 . V_221 = V_513 ;
V_511 . V_208 = V_407 ;
V_511 . V_210 = & V_229 -> V_514 [ V_515 ] ;
V_511 . V_211 = 1 ;
V_511 . V_346 . V_516 . V_479 = V_176 ;
V_511 . V_346 . V_516 . V_481 = & V_481 ;
V_511 . V_346 . V_516 . V_113 = V_110 -> V_113 ;
if ( V_3 -> V_517 )
V_511 . V_346 . V_516 . V_348 = & V_229 -> V_514 [ V_518 ] ;
if ( ! V_346 )
V_346 = & V_511 ;
else
V_346 -> V_212 = & V_511 ;
V_19 = F_90 ( V_1 -> V_59 , V_346 , & V_470 ) ;
if ( V_19 ) {
F_3 ( L_130 , V_19 ) ;
goto V_58;
}
V_104 -> V_124 &= ~ V_130 ;
V_229 -> V_514 [ V_519 ] . V_75 = V_110 -> V_113 -> V_75 ;
V_229 -> V_514 [ V_519 ] . V_73 = 0 ;
V_229 -> V_514 [ V_519 ] . V_74 = V_3 -> V_298 ;
if ( V_3 -> V_6 != V_505 &&
V_3 -> V_6 != V_504 )
V_229 -> V_514 [ V_519 ] . V_74 += V_3 -> V_520 ;
F_8 ( L_132 ,
V_229 -> V_514 [ V_519 ] . V_73 , V_229 -> V_514 [ V_519 ] . V_74 ,
V_229 -> V_514 [ V_519 ] . V_75 ) ;
V_58:
return V_19 ;
}
static int
F_193 ( struct V_1 * V_1 ,
struct V_225 * V_225 ,
struct V_345 * V_346 )
{
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_3 * V_3 = & V_225 -> V_278 -> V_3 ;
int V_19 ;
if ( ! V_346 -> V_104 -> V_110 ) {
V_19 = F_48 ( V_346 -> V_104 ,
V_25 -> V_15 ,
V_1 -> V_57 ) ;
if ( V_19 ) {
F_3 ( L_133 ,
V_1 ) ;
return V_19 ;
}
}
if ( V_3 -> V_517 ) {
V_19 = F_130 ( V_1 , V_225 ,
V_3 -> V_517 ,
V_3 -> V_521 ,
V_3 -> V_520 ,
0 , V_346 -> V_230 , & V_346 -> V_348 ) ;
if ( V_19 ) {
F_3 ( L_134 ,
V_1 ) ;
return V_19 ;
}
memset ( & V_346 -> V_514 [ V_518 ] , 0 , sizeof( V_346 -> V_514 [ V_518 ] ) ) ;
V_19 = F_188 ( V_1 , V_346 -> V_104 , & V_346 -> V_348 ,
V_125 , & V_346 -> V_514 [ V_518 ] ) ;
if ( V_19 ) {
F_3 ( L_135 ,
V_1 ) ;
goto V_522;
}
}
V_19 = F_192 ( V_1 , V_3 , V_346 , V_346 -> V_104 ) ;
if ( V_19 ) {
F_3 ( L_135 ,
V_1 ) ;
goto V_522;
}
V_346 -> V_104 -> V_124 |= V_131 ;
return 0 ;
V_522:
if ( V_3 -> V_517 )
F_133 ( V_1 , & V_346 -> V_348 ) ;
return V_19 ;
}
static int
V_86 ( struct V_234 * V_2 , struct V_278 * V_4 ,
struct V_345 * V_346 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_103 * V_104 = NULL ;
struct V_216 * V_217 ;
struct V_63 * V_514 ;
V_140 V_337 ;
int V_19 = 0 ;
unsigned long V_127 ;
V_225 -> V_215 . V_225 = V_225 ;
V_337 = V_346 -> V_230 == V_396 ? V_4 -> V_297 : 0 ;
V_19 = F_130 ( V_1 , V_225 , V_3 -> V_295 ,
V_3 -> V_439 , V_3 -> V_298 ,
V_337 , V_346 -> V_230 , & V_346 -> V_276 ) ;
if ( V_19 )
return V_19 ;
if ( V_346 -> V_276 . V_344 != 1 || F_1 ( V_1 , V_3 ) ) {
F_194 ( & V_1 -> V_158 , V_127 ) ;
V_104 = F_195 ( & V_1 -> V_106 ,
struct V_103 , V_107 ) ;
F_36 ( & V_104 -> V_107 ) ;
F_196 ( & V_1 -> V_158 , V_127 ) ;
V_346 -> V_104 = V_104 ;
}
V_19 = F_188 ( V_1 , V_104 , & V_346 -> V_276 ,
V_133 , & V_346 -> V_514 [ V_515 ] ) ;
if ( V_19 )
goto V_445;
if ( F_1 ( V_1 , V_3 ) ) {
V_19 = F_193 ( V_1 , V_225 , V_346 ) ;
if ( V_19 )
goto V_445;
V_514 = & V_346 -> V_514 [ V_519 ] ;
} else {
V_514 = & V_346 -> V_514 [ V_515 ] ;
}
memcpy ( & V_346 -> V_523 , V_514 , sizeof( * V_514 ) ) ;
V_346 -> V_63 = & V_346 -> V_523 ;
V_346 -> V_386 = 1 ;
memset ( & V_346 -> V_524 , 0 , sizeof( * V_217 ) ) ;
V_346 -> V_217 = & V_346 -> V_524 ;
V_346 -> V_225 = V_225 ;
V_217 = & V_225 -> V_229 . V_524 ;
V_217 -> V_210 = & V_346 -> V_523 ;
V_217 -> V_211 = 1 ;
V_217 -> V_208 = ( V_209 ) & V_225 -> V_215 ;
if ( V_346 -> V_230 == V_342 ) {
V_217 -> V_221 = V_446 ;
V_217 -> V_346 . V_447 . V_448 = V_225 -> V_316 ;
V_217 -> V_346 . V_447 . V_449 = V_225 -> V_315 ;
V_217 -> V_223 = ! F_1 ( V_1 , V_3 ) ?
0 : V_224 ;
} else {
V_217 -> V_221 = V_450 ;
V_217 -> V_346 . V_447 . V_448 = V_225 -> V_318 ;
V_217 -> V_346 . V_447 . V_449 = V_225 -> V_317 ;
V_217 -> V_223 = V_224 ;
}
return 0 ;
V_445:
if ( V_104 ) {
F_194 ( & V_1 -> V_158 , V_127 ) ;
F_41 ( & V_104 -> V_107 , & V_1 -> V_106 ) ;
F_196 ( & V_1 -> V_158 , V_127 ) ;
}
F_133 ( V_1 , & V_346 -> V_276 ) ;
return V_19 ;
}
static int
F_197 ( struct V_234 * V_2 , struct V_278 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_345 * V_346 = & V_225 -> V_229 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_216 * V_413 ;
int V_289 ;
F_8 ( L_136 ,
V_225 , V_3 -> V_298 ) ;
V_346 -> V_230 = V_342 ;
V_289 = V_25 -> V_85 ( V_2 , V_4 , V_346 ) ;
if ( V_289 ) {
F_3 ( L_137 , V_225 ) ;
return V_289 ;
}
if ( ! F_1 ( V_1 , V_3 ) ) {
F_91 ( V_1 , V_225 ,
& V_225 -> V_215 ) ;
F_165 ( V_4 , V_2 , true , (struct V_414 * )
& V_225 -> V_215 . V_238 ) ;
F_93 ( V_1 , & V_225 -> V_215 ) ;
F_94 ( V_1 , V_225 ,
& V_225 -> V_215 . V_217 ) ;
V_225 -> V_229 . V_524 . V_212 = & V_225 -> V_215 . V_217 ;
V_346 -> V_386 += 1 ;
}
V_289 = F_90 ( V_1 -> V_59 , V_346 -> V_217 , & V_413 ) ;
if ( V_289 )
F_5 ( L_138 ) ;
if ( ! F_1 ( V_1 , V_3 ) )
F_8 ( L_139
L_140 , V_225 ) ;
else
F_8 ( L_141 ,
V_225 ) ;
return 1 ;
}
static int
F_198 ( struct V_234 * V_2 , struct V_278 * V_4 , bool V_525 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_225 * V_225 = F_103 ( V_4 ) ;
struct V_345 * V_346 = & V_225 -> V_229 ;
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
struct V_24 * V_25 = V_1 -> V_26 ;
struct V_216 * V_413 ;
int V_289 ;
F_8 ( L_142 ,
V_225 , V_3 -> V_298 , V_4 -> V_297 ) ;
V_346 -> V_230 = V_396 ;
V_289 = V_25 -> V_85 ( V_2 , V_4 , V_346 ) ;
if ( V_289 ) {
F_3 ( L_137 , V_225 ) ;
return V_289 ;
}
V_289 = F_90 ( V_1 -> V_59 , V_346 -> V_217 , & V_413 ) ;
if ( V_289 )
F_5 ( L_143 ) ;
F_8 ( L_144 ,
V_225 ) ;
return 0 ;
}
static int
F_199 ( struct V_234 * V_2 , struct V_278 * V_4 , int V_150 )
{
int V_19 ;
switch ( V_150 ) {
case V_526 :
V_19 = F_170 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_145 , V_150 ) ;
V_19 = - V_320 ;
break;
}
return V_19 ;
}
static int
F_200 ( struct V_234 * V_2 , struct V_278 * V_4 , int V_150 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
switch ( V_150 ) {
case V_393 :
V_19 = F_172 ( V_4 , V_2 ) ;
if ( ! V_19 )
V_1 -> V_527 = true ;
break;
case V_528 :
V_19 = F_170 ( V_4 , V_2 , true ) ;
break;
case V_389 :
V_19 = F_174 ( V_4 , V_2 ) ;
break;
case V_390 :
V_19 = F_176 ( V_4 , V_2 ) ;
break;
case V_391 :
V_19 = F_178 ( V_4 , V_2 ) ;
break;
case V_529 :
V_19 = F_148 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_146 , V_150 ) ;
V_19 = - V_320 ;
break;
}
return V_19 ;
}
struct V_22 *
F_81 ( struct V_145 * V_145 )
{
struct V_146 * V_147 = V_145 -> V_147 ;
struct V_22 * V_530 ;
struct V_531 * V_532 ;
int V_19 ;
V_532 = (struct V_531 * ) & V_147 -> V_533 ;
F_8 ( L_147 , & V_147 -> V_533 , V_532 ) ;
V_530 = F_201 ( F_85 , V_145 ,
V_534 , V_53 ) ;
if ( F_29 ( V_530 ) ) {
F_3 ( L_148 , F_30 ( V_530 ) ) ;
V_19 = F_30 ( V_530 ) ;
goto V_162;
}
F_8 ( L_149 , V_530 , V_530 -> V_10 ) ;
V_19 = F_202 ( V_530 , V_532 ) ;
if ( V_19 ) {
F_3 ( L_150 , V_19 ) ;
goto V_535;
}
V_19 = F_203 ( V_530 , V_536 ) ;
if ( V_19 ) {
F_3 ( L_151 , V_19 ) ;
goto V_535;
}
return V_530 ;
V_535:
F_70 ( V_530 ) ;
V_162:
return F_39 ( V_19 ) ;
}
static int
F_204 ( struct V_146 * V_147 ,
struct V_537 * V_538 )
{
struct V_145 * V_145 ;
struct V_22 * V_539 ;
int V_19 ;
V_145 = F_17 ( sizeof( struct V_145 ) , V_68 ) ;
if ( ! V_145 ) {
F_3 ( L_152 ) ;
return - V_78 ;
}
F_205 ( & V_145 -> V_181 , 0 ) ;
F_61 ( & V_145 -> V_179 ) ;
F_40 ( & V_145 -> V_180 ) ;
F_59 ( & V_145 -> V_540 ) ;
V_145 -> V_147 = V_147 ;
memcpy ( & V_147 -> V_533 , V_538 ,
sizeof( struct V_537 ) ) ;
V_539 = F_81 ( V_145 ) ;
if ( F_29 ( V_539 ) ) {
V_19 = F_30 ( V_539 ) ;
goto V_162;
}
V_145 -> V_192 = V_539 ;
V_147 -> V_541 = V_145 ;
return 0 ;
V_162:
F_21 ( V_145 ) ;
return V_19 ;
}
static int
F_66 ( struct V_1 * V_1 )
{
struct V_22 * V_542 = V_1 -> V_13 ;
struct V_543 V_544 ;
int V_19 ;
memset ( & V_544 , 0 , sizeof( struct V_543 ) ) ;
V_544 . V_171 = V_1 -> V_171 ;
V_544 . V_545 = 7 ;
V_544 . V_546 = 7 ;
V_19 = F_206 ( V_542 , & V_544 ) ;
if ( V_19 ) {
F_3 ( L_153 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int
F_207 ( struct V_234 * V_2 , struct V_235 * V_236 )
{
struct V_1 * V_1 = (struct V_1 * ) V_2 -> V_10 ;
int V_19 ;
F_11 ( L_154 , V_1 ) ;
V_19 = F_208 ( & V_1 -> V_154 ) ;
if ( V_19 ) {
F_3 ( L_155 ,
V_1 ) ;
return V_19 ;
}
F_209 ( & V_1 -> V_154 ) ;
if ( ! V_236 -> V_253 )
return 0 ;
F_96 ( V_1 ) ;
F_11 ( L_156 , V_2 ) ;
V_19 = F_208 ( & V_1 -> V_153 ) ;
if ( V_19 )
return V_19 ;
F_11 ( L_157 , V_236 -> V_272 ) ;
return 0 ;
}
static void
F_210 ( struct V_146 * V_147 , struct V_234 * V_2 ,
struct V_1 * V_1 )
{
struct V_22 * V_542 = V_1 -> V_13 ;
struct V_547 * V_548 = & V_542 -> V_549 ;
struct V_550 * V_551 ;
struct V_552 * V_553 ;
V_2 -> V_554 = V_147 -> V_533 . V_555 ;
if ( V_147 -> V_533 . V_555 == V_556 ) {
V_553 = (struct V_552 * ) & V_548 -> V_73 . V_557 ;
snprintf ( V_2 -> V_558 , sizeof( V_2 -> V_558 ) , L_158 ,
& V_553 -> V_559 . V_560 ) ;
V_2 -> V_561 = F_211 ( V_553 -> V_562 ) ;
V_553 = (struct V_552 * ) & V_548 -> V_73 . V_563 ;
snprintf ( V_2 -> V_564 , sizeof( V_2 -> V_564 ) , L_158 ,
& V_553 -> V_559 . V_560 ) ;
V_2 -> V_565 = F_211 ( V_553 -> V_562 ) ;
} else {
V_551 = (struct V_550 * ) & V_548 -> V_73 . V_557 ;
sprintf ( V_2 -> V_558 , L_159 ,
& V_551 -> V_566 . V_567 ) ;
V_2 -> V_561 = F_211 ( V_551 -> V_568 ) ;
V_551 = (struct V_550 * ) & V_548 -> V_73 . V_563 ;
sprintf ( V_2 -> V_564 , L_159 ,
& V_551 -> V_566 . V_567 ) ;
V_2 -> V_565 = F_211 ( V_551 -> V_568 ) ;
}
}
static int
F_212 ( struct V_146 * V_147 , struct V_234 * V_2 )
{
struct V_145 * V_145 = (struct V_145 * ) V_147 -> V_541 ;
struct V_1 * V_1 ;
int V_569 = 0 , V_19 ;
V_570:
V_19 = F_213 ( & V_145 -> V_181 ) ;
if ( V_19 || V_569 > 5 )
return - V_571 ;
F_56 ( & V_147 -> V_148 ) ;
if ( V_147 -> V_572 >= V_573 ) {
F_57 ( & V_147 -> V_148 ) ;
F_8 ( L_160 ,
V_147 -> V_572 ) ;
return - V_571 ;
}
F_57 ( & V_147 -> V_148 ) ;
F_10 ( & V_145 -> V_179 ) ;
if ( F_43 ( & V_145 -> V_180 ) ) {
F_12 ( & V_145 -> V_179 ) ;
V_569 ++ ;
goto V_570;
}
V_1 = F_195 ( & V_145 -> V_180 ,
struct V_1 , V_152 ) ;
F_137 ( & V_1 -> V_152 ) ;
F_12 ( & V_145 -> V_179 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
V_569 = 0 ;
F_210 ( V_147 , V_2 , V_1 ) ;
F_8 ( L_161 , V_1 ) ;
return 0 ;
}
static void
F_214 ( struct V_146 * V_147 )
{
struct V_145 * V_145 = (struct V_145 * ) V_147 -> V_541 ;
struct V_1 * V_1 , * V_410 ;
if ( V_145 -> V_192 )
F_70 ( V_145 -> V_192 ) ;
F_10 ( & V_145 -> V_179 ) ;
if ( ! F_43 ( & V_145 -> V_180 ) ) {
F_11 ( L_162 ) ;
F_44 (isert_conn, n,
&isert_np->np_accept_list,
conn_accept_node) {
F_11 ( L_163 ,
V_1 , V_1 -> V_150 ) ;
F_69 ( V_1 ) ;
}
}
F_12 ( & V_145 -> V_179 ) ;
V_147 -> V_541 = NULL ;
F_21 ( V_145 ) ;
}
static void F_215 ( struct V_387 * V_94 )
{
struct V_1 * V_1 = F_75 ( V_94 ,
struct V_1 ,
V_574 ) ;
F_11 ( L_164 , V_1 ) ;
F_216 ( & V_1 -> V_155 ) ;
F_10 ( & V_1 -> V_157 ) ;
V_1 -> V_150 = V_575 ;
F_12 ( & V_1 -> V_157 ) ;
F_11 ( L_165 , V_1 ) ;
F_76 ( V_1 ) ;
}
static void
F_217 ( struct V_1 * V_1 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
F_11 ( L_40 , V_1 ) ;
if ( V_1 -> V_527 ) {
F_11 ( L_166 , V_1 ) ;
F_218 ( & V_2 -> V_576 ,
V_577 * V_578 ) ;
}
}
static void
F_219 ( struct V_234 * V_2 )
{
F_11 ( L_167 , V_2 ) ;
if ( V_2 -> V_136 ) {
F_220 ( V_2 -> V_136 -> V_135 ) ;
F_221 ( V_2 -> V_136 -> V_135 ) ;
}
}
static void
F_222 ( struct V_1 * V_1 )
{
struct V_203 * V_470 ;
F_11 ( L_40 , V_1 ) ;
F_59 ( & V_1 -> V_401 ) ;
V_1 -> V_579 . V_208 = V_400 ;
if ( F_87 ( V_1 -> V_59 , & V_1 -> V_579 , & V_470 ) ) {
F_3 ( L_168 , V_1 ) ;
return;
}
F_216 ( & V_1 -> V_401 ) ;
}
static void F_223 ( struct V_234 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_11 ( L_169 , V_1 ) ;
F_10 ( & V_1 -> V_157 ) ;
if ( V_1 -> V_150 == V_151 ) {
F_12 ( & V_1 -> V_157 ) ;
return;
}
F_78 ( V_1 ) ;
F_12 ( & V_1 -> V_157 ) ;
F_219 ( V_2 ) ;
F_222 ( V_1 ) ;
F_217 ( V_1 ) ;
F_27 ( & V_1 -> V_574 , F_215 ) ;
F_155 ( V_580 , & V_1 -> V_574 ) ;
}
static void F_224 ( struct V_234 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_76 ( V_1 ) ;
}
static int T_4 F_225 ( void )
{
int V_19 ;
V_394 = F_226 ( L_170 ,
V_581 | V_582 , 0 ) ;
if ( ! V_394 ) {
F_3 ( L_171 ) ;
V_19 = - V_78 ;
return - V_78 ;
}
V_580 = F_226 ( L_172 , V_581 ,
V_583 ) ;
if ( ! V_580 ) {
F_3 ( L_173 ) ;
V_19 = - V_78 ;
goto V_584;
}
F_227 ( & V_585 ) ;
F_11 ( L_174 ) ;
return 0 ;
V_584:
F_228 ( V_394 ) ;
return V_19 ;
}
static void T_5 F_229 ( void )
{
F_230 () ;
F_228 ( V_580 ) ;
F_228 ( V_394 ) ;
F_231 ( & V_585 ) ;
F_11 ( L_175 ) ;
}
