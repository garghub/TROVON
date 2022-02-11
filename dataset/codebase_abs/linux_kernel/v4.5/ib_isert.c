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
static struct V_15 *
F_7 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_15 * V_18 ;
int V_19 , V_20 = 0 ;
F_8 ( & V_21 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ )
if ( V_17 -> V_23 [ V_19 ] . V_24 <
V_17 -> V_23 [ V_20 ] . V_24 )
V_20 = V_19 ;
V_18 = & V_17 -> V_23 [ V_20 ] ;
V_18 -> V_24 ++ ;
F_9 ( & V_21 ) ;
F_10 ( L_3 ,
V_1 , V_18 , V_20 ) ;
return V_18 ;
}
static void
F_11 ( struct V_15 * V_18 )
{
F_8 ( & V_21 ) ;
V_18 -> V_24 -- ;
F_9 ( & V_21 ) ;
}
static struct V_25 *
F_12 ( struct V_1 * V_1 ,
struct V_15 * V_18 ,
struct V_26 * V_27 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_28 V_29 ;
int V_30 ;
memset ( & V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 . V_31 = F_2 ;
V_29 . V_32 = V_1 ;
V_29 . V_33 = V_18 -> V_34 ;
V_29 . V_35 = V_18 -> V_34 ;
V_29 . V_36 . V_37 = V_38 ;
V_29 . V_36 . V_39 = V_40 + 1 ;
V_29 . V_36 . V_41 = V_17 -> V_42 -> V_43 . V_44 ;
V_1 -> V_44 = V_20 ( V_17 -> V_42 -> V_43 . V_44 ,
V_17 -> V_42 -> V_43 . V_45 ) ;
V_29 . V_36 . V_46 = 1 ;
V_29 . V_47 = V_48 ;
V_29 . V_49 = V_50 ;
if ( V_17 -> V_51 )
V_29 . V_52 |= V_53 ;
V_30 = F_13 ( V_27 , V_17 -> V_54 , & V_29 ) ;
if ( V_30 ) {
F_3 ( L_4 , V_30 ) ;
return F_14 ( V_30 ) ;
}
return V_27 -> V_55 ;
}
static int
F_15 ( struct V_1 * V_1 , struct V_26 * V_27 )
{
struct V_15 * V_18 ;
int V_30 ;
V_18 = F_7 ( V_1 ) ;
V_1 -> V_55 = F_12 ( V_1 , V_18 , V_27 ) ;
if ( F_16 ( V_1 -> V_55 ) ) {
V_30 = F_17 ( V_1 -> V_55 ) ;
goto V_56;
}
return 0 ;
V_56:
F_11 ( V_18 ) ;
return V_30 ;
}
static void
F_18 ( struct V_8 * V_9 , void * V_10 )
{
F_19 ( L_5 , V_9 -> V_11 ) ;
}
static int
F_20 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_1 V_62 ;
int V_19 , V_63 ;
V_1 -> V_64 = F_21 ( V_40 *
sizeof( struct V_58 ) , V_65 ) ;
if ( ! V_1 -> V_64 )
goto V_66;
V_59 = V_1 -> V_64 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_59 ++ ) {
V_62 = F_22 ( V_57 , ( void * ) V_59 ,
V_67 , V_68 ) ;
if ( F_23 ( V_57 , V_62 ) )
goto V_69;
V_59 -> V_62 = V_62 ;
V_61 = & V_59 -> V_61 ;
V_61 -> V_70 = V_59 -> V_62 ;
V_61 -> V_71 = V_67 ;
V_61 -> V_72 = V_17 -> V_54 -> V_73 ;
}
return 0 ;
V_69:
V_59 = V_1 -> V_64 ;
for ( V_63 = 0 ; V_63 < V_19 ; V_63 ++ , V_59 ++ ) {
F_24 ( V_57 , V_59 -> V_62 ,
V_67 , V_68 ) ;
}
F_25 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
V_66:
F_3 ( L_6 , V_1 ) ;
return - V_74 ;
}
static void
F_26 ( struct V_1 * V_1 )
{
struct V_42 * V_57 = V_1 -> V_17 -> V_42 ;
struct V_58 * V_59 ;
int V_19 ;
if ( ! V_1 -> V_64 )
return;
V_59 = V_1 -> V_64 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_59 ++ ) {
F_24 ( V_57 , V_59 -> V_62 ,
V_67 , V_68 ) ;
}
F_25 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
}
static void
F_27 ( struct V_16 * V_17 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
if ( V_18 -> V_34 ) {
F_28 ( & V_18 -> V_75 ) ;
F_29 ( V_18 -> V_34 ) ;
}
}
F_25 ( V_17 -> V_23 ) ;
}
static int
F_30 ( struct V_16 * V_17 )
{
int V_19 , V_76 , V_30 = 0 ;
V_17 -> V_22 = V_20 ( V_77 , F_31 ( int , F_32 () ,
V_17 -> V_42 -> V_78 ) ) ;
F_10 ( L_7
L_8 ,
V_17 -> V_22 , V_17 -> V_42 -> V_79 ,
V_17 -> V_42 -> V_78 , V_17 -> V_80 ,
V_17 -> V_51 ) ;
V_17 -> V_23 = F_33 ( V_17 -> V_22 , sizeof( struct V_15 ) ,
V_65 ) ;
if ( ! V_17 -> V_23 ) {
F_3 ( L_9 ) ;
return - V_74 ;
}
V_76 = V_20 ( V_81 , V_17 -> V_42 -> V_43 . V_76 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_82 V_83 = {} ;
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
V_18 -> V_17 = V_17 ;
F_34 ( & V_18 -> V_75 , V_84 ) ;
V_83 . V_85 = V_76 ;
V_83 . V_86 = V_19 ;
V_18 -> V_34 = F_35 ( V_17 -> V_42 ,
V_87 ,
F_18 ,
( void * ) V_18 ,
& V_83 ) ;
if ( F_16 ( V_18 -> V_34 ) ) {
F_3 ( L_10 ) ;
V_30 = F_17 ( V_18 -> V_34 ) ;
V_18 -> V_34 = NULL ;
goto V_88;
}
V_30 = F_36 ( V_18 -> V_34 , V_89 ) ;
if ( V_30 )
goto V_88;
}
return 0 ;
V_88:
F_27 ( V_17 ) ;
return V_30 ;
}
static int
F_37 ( struct V_16 * V_17 )
{
struct V_42 * V_57 = V_17 -> V_42 ;
int V_30 ;
F_19 ( L_11 , V_57 -> V_43 . V_44 ) ;
F_19 ( L_12 , V_57 -> V_43 . V_45 ) ;
if ( V_57 -> V_43 . V_90 & V_91 &&
V_57 -> V_43 . V_90 & V_92 ) {
V_17 -> V_80 = 1 ;
V_17 -> V_93 = V_94 ;
V_17 -> V_95 = V_96 ;
} else {
V_17 -> V_80 = 0 ;
V_17 -> V_93 = V_97 ;
V_17 -> V_95 = V_98 ;
}
V_30 = F_30 ( V_17 ) ;
if ( V_30 )
goto V_99;
V_17 -> V_54 = F_38 ( V_57 ) ;
if ( F_16 ( V_17 -> V_54 ) ) {
V_30 = F_17 ( V_17 -> V_54 ) ;
F_3 ( L_13 ,
V_17 , V_30 ) ;
goto V_88;
}
V_17 -> V_51 = V_57 -> V_43 . V_90 &
V_92 ? true : false ;
return 0 ;
V_88:
F_27 ( V_17 ) ;
V_99:
if ( V_30 > 0 )
V_30 = - V_100 ;
return V_30 ;
}
static void
F_39 ( struct V_16 * V_17 )
{
F_10 ( L_14 , V_17 ) ;
F_40 ( V_17 -> V_54 ) ;
F_27 ( V_17 ) ;
}
static void
F_41 ( struct V_16 * V_17 )
{
F_8 ( & V_21 ) ;
V_17 -> V_101 -- ;
F_10 ( L_15 , V_17 , V_17 -> V_101 ) ;
if ( ! V_17 -> V_101 ) {
F_39 ( V_17 ) ;
F_42 ( & V_17 -> V_102 ) ;
F_25 ( V_17 ) ;
}
F_9 ( & V_21 ) ;
}
static struct V_16 *
F_43 ( struct V_26 * V_27 )
{
struct V_16 * V_17 ;
int V_30 ;
F_8 ( & V_21 ) ;
F_44 (device, &device_list, dev_node) {
if ( V_17 -> V_42 -> V_103 == V_27 -> V_17 -> V_103 ) {
V_17 -> V_101 ++ ;
F_10 ( L_16 ,
V_17 , V_17 -> V_101 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
}
V_17 = F_21 ( sizeof( struct V_16 ) , V_65 ) ;
if ( ! V_17 ) {
F_9 ( & V_21 ) ;
return F_14 ( - V_74 ) ;
}
F_45 ( & V_17 -> V_102 ) ;
V_17 -> V_42 = V_27 -> V_17 ;
V_30 = F_37 ( V_17 ) ;
if ( V_30 ) {
F_25 ( V_17 ) ;
F_9 ( & V_21 ) ;
return F_14 ( V_30 ) ;
}
V_17 -> V_101 ++ ;
F_46 ( & V_17 -> V_102 , & V_104 ) ;
F_10 ( L_17 ,
V_17 , V_17 -> V_101 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
static void
F_47 ( struct V_1 * V_1 )
{
struct V_105 * V_106 , * V_107 ;
int V_19 = 0 ;
if ( F_48 ( & V_1 -> V_108 ) )
return;
F_10 ( L_18 , V_1 ) ;
F_49 (fr_desc, tmp,
&isert_conn->fr_pool, list) {
F_42 ( & V_106 -> V_109 ) ;
F_50 ( V_106 -> V_110 ) ;
if ( V_106 -> V_111 ) {
F_50 ( V_106 -> V_111 -> V_112 ) ;
F_50 ( V_106 -> V_111 -> V_113 ) ;
F_25 ( V_106 -> V_111 ) ;
}
F_25 ( V_106 ) ;
++ V_19 ;
}
if ( V_19 < V_1 -> V_114 )
F_6 ( L_19 ,
V_1 -> V_114 - V_19 ) ;
}
static int
F_51 ( struct V_105 * V_115 ,
struct V_42 * V_17 ,
struct V_116 * V_54 )
{
struct V_117 * V_111 ;
int V_30 ;
V_111 = F_21 ( sizeof( * V_115 -> V_111 ) , V_65 ) ;
if ( ! V_111 ) {
F_3 ( L_20 ) ;
return - V_74 ;
}
V_111 -> V_112 = F_52 ( V_54 , V_118 ,
V_119 ) ;
if ( F_16 ( V_111 -> V_112 ) ) {
F_3 ( L_21 ,
F_17 ( V_111 -> V_112 ) ) ;
V_30 = F_17 ( V_111 -> V_112 ) ;
goto V_120;
}
V_115 -> V_121 |= V_122 ;
V_111 -> V_113 = F_52 ( V_54 , V_123 , 2 ) ;
if ( F_16 ( V_111 -> V_113 ) ) {
F_3 ( L_22 ,
F_17 ( V_111 -> V_113 ) ) ;
V_30 = F_17 ( V_111 -> V_113 ) ;
goto V_124;
}
V_115 -> V_111 = V_111 ;
V_115 -> V_121 |= V_125 ;
V_115 -> V_121 &= ~ V_126 ;
return 0 ;
V_124:
F_50 ( V_111 -> V_112 ) ;
V_120:
F_25 ( V_111 ) ;
return V_30 ;
}
static int
F_53 ( struct V_42 * V_42 , struct V_116 * V_54 ,
struct V_105 * V_106 )
{
V_106 -> V_110 = F_52 ( V_54 , V_118 ,
V_119 ) ;
if ( F_16 ( V_106 -> V_110 ) ) {
F_3 ( L_23 ,
F_17 ( V_106 -> V_110 ) ) ;
return F_17 ( V_106 -> V_110 ) ;
}
V_106 -> V_121 |= V_127 ;
F_19 ( L_24 , V_106 ) ;
return 0 ;
}
static int
F_54 ( struct V_1 * V_1 )
{
struct V_105 * V_106 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_128 * V_129 = V_1 -> V_2 -> V_130 -> V_129 ;
struct V_131 * V_132 = V_129 -> V_131 ;
int V_19 , V_30 , V_133 ;
V_133 = F_55 ( V_134 , V_135 , V_132 -> V_136 ) ;
V_133 = ( V_133 * 2 ) + V_137 ;
V_1 -> V_114 = 0 ;
for ( V_19 = 0 ; V_19 < V_133 ; V_19 ++ ) {
V_106 = F_21 ( sizeof( * V_106 ) , V_65 ) ;
if ( ! V_106 ) {
F_3 ( L_25 ) ;
V_30 = - V_74 ;
goto V_56;
}
V_30 = F_53 ( V_17 -> V_42 ,
V_17 -> V_54 , V_106 ) ;
if ( V_30 ) {
F_3 ( L_26 ,
V_30 ) ;
F_25 ( V_106 ) ;
goto V_56;
}
F_46 ( & V_106 -> V_109 , & V_1 -> V_108 ) ;
V_1 -> V_114 ++ ;
}
F_19 ( L_27 ,
V_1 , V_1 -> V_114 ) ;
return 0 ;
V_56:
F_47 ( V_1 ) ;
return V_30 ;
}
static void
F_56 ( struct V_1 * V_1 )
{
V_1 -> V_138 = V_139 ;
F_45 ( & V_1 -> V_140 ) ;
F_57 ( & V_1 -> V_141 ) ;
F_57 ( & V_1 -> V_142 ) ;
F_57 ( & V_1 -> V_143 ) ;
F_58 ( & V_1 -> V_144 ) ;
F_59 ( & V_1 -> V_145 ) ;
F_60 ( & V_1 -> V_146 ) ;
F_45 ( & V_1 -> V_108 ) ;
F_34 ( & V_1 -> V_147 , V_148 ) ;
}
static void
F_61 ( struct V_1 * V_1 )
{
struct V_42 * V_57 = V_1 -> V_17 -> V_42 ;
F_24 ( V_57 , V_1 -> V_149 ,
V_150 , V_151 ) ;
F_24 ( V_57 , V_1 -> V_152 ,
V_153 ,
V_68 ) ;
F_25 ( V_1 -> V_154 ) ;
}
static int
F_62 ( struct V_1 * V_1 ,
struct V_42 * V_57 )
{
int V_30 ;
V_1 -> V_154 = F_21 ( V_153 +
V_150 , V_65 ) ;
if ( ! V_1 -> V_154 ) {
F_3 ( L_28 ) ;
return - V_74 ;
}
V_1 -> V_155 = V_1 -> V_154 ;
V_1 -> V_156 = V_1 -> V_154 +
V_153 ;
F_19 ( L_29 ,
V_1 -> V_154 , V_1 -> V_155 ,
V_1 -> V_156 ) ;
V_1 -> V_152 = F_22 ( V_57 ,
( void * ) V_1 -> V_155 ,
V_153 , V_68 ) ;
V_30 = F_23 ( V_57 , V_1 -> V_152 ) ;
if ( V_30 ) {
F_3 ( L_30 , V_30 ) ;
V_1 -> V_152 = 0 ;
goto V_157;
}
V_1 -> V_149 = F_22 ( V_57 ,
( void * ) V_1 -> V_156 ,
V_150 , V_151 ) ;
V_30 = F_23 ( V_57 , V_1 -> V_149 ) ;
if ( V_30 ) {
F_3 ( L_31 , V_30 ) ;
V_1 -> V_149 = 0 ;
goto V_158;
}
return 0 ;
V_158:
F_24 ( V_57 , V_1 -> V_152 ,
V_153 , V_68 ) ;
V_157:
F_25 ( V_1 -> V_154 ) ;
return V_30 ;
}
static void
F_63 ( struct V_1 * V_1 ,
struct V_159 * V_160 )
{
struct V_161 * V_29 = & V_1 -> V_17 -> V_42 -> V_43 ;
V_1 -> V_162 = F_31 ( V_163 , V_160 -> V_162 ,
V_29 -> V_164 ) ;
F_19 ( L_32 , V_1 -> V_162 ) ;
if ( V_160 -> V_165 ) {
V_163 V_166 = * ( V_163 * ) V_160 -> V_165 ;
V_1 -> V_167 = ! ( V_166 & V_168 ) &&
( V_29 -> V_90 &
V_91 ) ;
if ( V_1 -> V_167 )
F_10 ( L_33 ) ;
}
}
static int
F_64 ( struct V_26 * V_27 , struct V_169 * V_11 )
{
struct V_170 * V_170 = V_27 -> V_10 ;
struct V_171 * V_172 = V_170 -> V_172 ;
struct V_1 * V_1 ;
struct V_16 * V_17 ;
int V_30 = 0 ;
F_65 ( & V_172 -> V_173 ) ;
if ( ! V_172 -> V_174 ) {
F_66 ( & V_172 -> V_173 ) ;
F_19 ( L_34 ) ;
return F_67 ( V_27 , NULL , 0 ) ;
}
F_66 ( & V_172 -> V_173 ) ;
F_19 ( L_35 ,
V_27 , V_27 -> V_10 ) ;
V_1 = F_21 ( sizeof( struct V_1 ) , V_65 ) ;
if ( ! V_1 )
return - V_74 ;
F_56 ( V_1 ) ;
V_1 -> V_13 = V_27 ;
V_30 = F_62 ( V_1 , V_27 -> V_17 ) ;
if ( V_30 )
goto V_99;
V_17 = F_43 ( V_27 ) ;
if ( F_16 ( V_17 ) ) {
V_30 = F_17 ( V_17 ) ;
goto V_175;
}
V_1 -> V_17 = V_17 ;
F_63 ( V_1 , & V_11 -> V_160 . V_2 ) ;
V_30 = F_15 ( V_1 , V_27 ) ;
if ( V_30 )
goto V_176;
V_30 = F_68 ( V_1 ) ;
if ( V_30 )
goto V_176;
V_30 = F_69 ( V_1 ) ;
if ( V_30 )
goto V_176;
F_8 ( & V_170 -> V_145 ) ;
F_46 ( & V_1 -> V_140 , & V_170 -> V_177 ) ;
F_9 ( & V_170 -> V_145 ) ;
return 0 ;
V_176:
F_41 ( V_17 ) ;
V_175:
F_61 ( V_1 ) ;
V_99:
F_25 ( V_1 ) ;
F_67 ( V_27 , NULL , 0 ) ;
return V_30 ;
}
static void
F_70 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
F_19 ( L_36 , V_1 ) ;
F_71 ( ! V_17 ) ;
if ( V_17 -> V_80 )
F_47 ( V_1 ) ;
F_26 ( V_1 ) ;
if ( V_1 -> V_13 )
F_72 ( V_1 -> V_13 ) ;
if ( V_1 -> V_55 ) {
struct V_15 * V_18 = V_1 -> V_55 -> V_35 -> V_178 ;
F_11 ( V_18 ) ;
F_73 ( V_1 -> V_55 ) ;
}
if ( V_1 -> V_154 )
F_61 ( V_1 ) ;
F_41 ( V_17 ) ;
F_25 ( V_1 ) ;
}
static void
F_74 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_55 -> V_32 ;
struct V_170 * V_170 = V_27 -> V_10 ;
F_10 ( L_36 , V_1 ) ;
F_8 ( & V_1 -> V_145 ) ;
V_1 -> V_138 = V_179 ;
F_75 ( & V_1 -> V_144 ) ;
F_9 ( & V_1 -> V_145 ) ;
F_8 ( & V_170 -> V_145 ) ;
F_76 ( & V_1 -> V_140 , & V_170 -> V_180 ) ;
F_9 ( & V_170 -> V_145 ) ;
F_10 ( L_37 , V_170 ) ;
F_77 ( & V_170 -> V_181 ) ;
}
static void
F_78 ( struct V_144 * V_144 )
{
struct V_1 * V_1 = F_79 ( V_144 ,
struct V_1 , V_144 ) ;
F_10 ( L_38 , V_1 , V_182 -> V_183 ,
V_182 -> V_184 ) ;
F_70 ( V_1 ) ;
}
static void
F_80 ( struct V_1 * V_1 )
{
F_81 ( & V_1 -> V_144 , F_78 ) ;
}
static void
F_82 ( struct V_1 * V_1 )
{
int V_56 ;
switch ( V_1 -> V_138 ) {
case V_185 :
break;
case V_179 :
case V_186 :
F_10 ( L_39 ,
V_1 , V_1 -> V_138 ) ;
V_1 -> V_138 = V_185 ;
V_56 = F_83 ( V_1 -> V_13 ) ;
if ( V_56 )
F_6 ( L_40 ,
V_1 ) ;
break;
default:
F_6 ( L_41 ,
V_1 , V_1 -> V_138 ) ;
}
}
static int
F_84 ( struct V_170 * V_170 ,
enum V_187 V_11 )
{
F_19 ( L_42 ,
F_85 ( V_11 ) , V_11 , V_170 ) ;
switch ( V_11 ) {
case V_188 :
V_170 -> V_13 = NULL ;
break;
case V_189 :
V_170 -> V_13 = F_86 ( V_170 ) ;
if ( F_16 ( V_170 -> V_13 ) ) {
F_3 ( L_43 ,
V_170 , F_17 ( V_170 -> V_13 ) ) ;
V_170 -> V_13 = NULL ;
}
break;
default:
F_3 ( L_44 ,
V_170 , V_11 ) ;
}
return - 1 ;
}
static int
F_87 ( struct V_26 * V_27 ,
enum V_187 V_11 )
{
struct V_170 * V_170 = V_27 -> V_10 ;
struct V_1 * V_1 ;
bool V_190 = false ;
if ( V_170 -> V_13 == V_27 )
return F_84 ( V_27 -> V_10 , V_11 ) ;
V_1 = V_27 -> V_55 -> V_32 ;
F_8 ( & V_1 -> V_145 ) ;
V_190 = ( V_1 -> V_138 == V_185 ) ;
F_82 ( V_1 ) ;
F_9 ( & V_1 -> V_145 ) ;
F_10 ( L_45 , V_1 ) ;
F_88 ( & V_1 -> V_143 ) ;
if ( V_190 )
goto V_99;
F_8 ( & V_170 -> V_145 ) ;
if ( ! F_48 ( & V_1 -> V_140 ) ) {
F_89 ( & V_1 -> V_140 ) ;
F_80 ( V_1 ) ;
F_90 ( V_191 , & V_1 -> V_147 ) ;
}
F_9 ( & V_170 -> V_145 ) ;
V_99:
return 0 ;
}
static int
F_91 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_55 -> V_32 ;
F_89 ( & V_1 -> V_140 ) ;
V_1 -> V_13 = NULL ;
F_80 ( V_1 ) ;
return - 1 ;
}
static int
F_92 ( struct V_26 * V_27 , struct V_169 * V_11 )
{
int V_30 = 0 ;
F_10 ( L_46 ,
F_85 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_192 , V_27 , V_27 -> V_10 ) ;
switch ( V_11 -> V_11 ) {
case V_193 :
V_30 = F_64 ( V_27 , V_11 ) ;
if ( V_30 )
F_3 ( L_47 , V_30 ) ;
break;
case V_194 :
F_74 ( V_27 ) ;
break;
case V_189 :
case V_195 :
case V_188 :
case V_196 :
V_30 = F_87 ( V_27 , V_11 -> V_11 ) ;
break;
case V_197 :
case V_198 :
case V_199 :
V_30 = F_91 ( V_27 ) ;
break;
default:
F_3 ( L_48 , V_11 -> V_11 ) ;
break;
}
return V_30 ;
}
static int
F_93 ( struct V_1 * V_1 , V_134 V_200 )
{
struct V_201 * V_202 , * V_203 ;
int V_19 , V_30 ;
struct V_58 * V_59 ;
for ( V_202 = V_1 -> V_202 , V_19 = 0 ; V_19 < V_200 ; V_19 ++ , V_202 ++ ) {
V_59 = & V_1 -> V_64 [ V_19 ] ;
V_202 -> V_204 = ( V_205 ) V_59 ;
V_202 -> V_206 = & V_59 -> V_61 ;
V_202 -> V_207 = 1 ;
V_202 -> V_208 = V_202 + 1 ;
}
V_202 -- ;
V_202 -> V_208 = NULL ;
V_1 -> V_209 += V_200 ;
V_30 = F_94 ( V_1 -> V_55 , V_1 -> V_202 ,
& V_203 ) ;
if ( V_30 ) {
F_3 ( L_49 , V_30 ) ;
V_1 -> V_209 -= V_200 ;
}
return V_30 ;
}
static int
F_95 ( struct V_1 * V_1 , struct V_58 * V_59 )
{
struct V_201 * V_203 , V_202 ;
int V_30 ;
V_202 . V_204 = ( V_205 ) V_59 ;
V_202 . V_206 = & V_59 -> V_61 ;
V_202 . V_207 = 1 ;
V_202 . V_208 = NULL ;
V_1 -> V_209 ++ ;
V_30 = F_94 ( V_1 -> V_55 , & V_202 , & V_203 ) ;
if ( V_30 ) {
F_3 ( L_49 , V_30 ) ;
V_1 -> V_209 -- ;
}
return V_30 ;
}
static int
F_96 ( struct V_1 * V_1 , struct V_210 * V_211 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_212 V_213 , * V_214 ;
int V_30 ;
F_97 ( V_57 , V_211 -> V_62 ,
V_215 , V_151 ) ;
V_213 . V_208 = NULL ;
V_213 . V_204 = ( V_205 ) V_211 ;
V_213 . V_206 = V_211 -> V_216 ;
V_213 . V_207 = V_211 -> V_207 ;
V_213 . V_217 = V_218 ;
V_213 . V_219 = V_220 ;
V_30 = F_98 ( V_1 -> V_55 , & V_213 , & V_214 ) ;
if ( V_30 )
F_3 ( L_50 , V_30 ) ;
return V_30 ;
}
static void
F_99 ( struct V_1 * V_1 ,
struct V_221 * V_221 ,
struct V_210 * V_211 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
F_100 ( V_57 , V_211 -> V_62 ,
V_215 , V_151 ) ;
memset ( & V_211 -> V_222 , 0 , sizeof( struct V_223 ) ) ;
V_211 -> V_222 . V_166 = V_224 ;
V_211 -> V_207 = 1 ;
V_211 -> V_221 = V_221 ;
if ( V_211 -> V_216 [ 0 ] . V_72 != V_17 -> V_54 -> V_73 ) {
V_211 -> V_216 [ 0 ] . V_72 = V_17 -> V_54 -> V_73 ;
F_19 ( L_51 , V_211 ) ;
}
}
static int
F_101 ( struct V_1 * V_1 ,
struct V_210 * V_211 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
T_1 V_62 ;
V_62 = F_22 ( V_57 , ( void * ) V_211 ,
V_215 , V_151 ) ;
if ( F_23 ( V_57 , V_62 ) ) {
F_3 ( L_52 ) ;
return - V_74 ;
}
V_211 -> V_62 = V_62 ;
V_211 -> V_216 [ 0 ] . V_70 = V_211 -> V_62 ;
V_211 -> V_216 [ 0 ] . V_71 = V_215 ;
V_211 -> V_216 [ 0 ] . V_72 = V_17 -> V_54 -> V_73 ;
F_19 ( L_53 ,
V_211 -> V_216 [ 0 ] . V_70 , V_211 -> V_216 [ 0 ] . V_71 ,
V_211 -> V_216 [ 0 ] . V_72 ) ;
return 0 ;
}
static void
F_102 ( struct V_1 * V_1 , struct V_221 * V_221 ,
struct V_212 * V_213 )
{
struct V_210 * V_211 = & V_221 -> V_211 ;
V_221 -> V_225 . V_226 = V_227 ;
V_213 -> V_204 = ( V_205 ) & V_221 -> V_211 ;
if ( V_1 -> V_167 && V_221 -> V_228 ) {
V_213 -> V_217 = V_229 ;
V_213 -> V_230 . V_231 = V_221 -> V_228 ;
} else {
V_213 -> V_217 = V_218 ;
}
V_213 -> V_206 = & V_211 -> V_216 [ 0 ] ;
V_213 -> V_207 = V_221 -> V_211 . V_207 ;
V_213 -> V_219 = V_220 ;
}
static int
F_68 ( struct V_1 * V_1 )
{
struct V_201 V_202 , * V_232 ;
struct V_60 V_233 ;
int V_30 ;
memset ( & V_233 , 0 , sizeof( struct V_60 ) ) ;
V_233 . V_70 = V_1 -> V_152 ;
V_233 . V_71 = V_150 ;
V_233 . V_72 = V_1 -> V_17 -> V_54 -> V_73 ;
F_19 ( L_54 ,
V_233 . V_70 , V_233 . V_71 , V_233 . V_72 ) ;
memset ( & V_202 , 0 , sizeof( struct V_201 ) ) ;
V_202 . V_204 = ( V_205 ) V_1 -> V_155 ;
V_202 . V_206 = & V_233 ;
V_202 . V_207 = 1 ;
V_1 -> V_209 ++ ;
V_30 = F_94 ( V_1 -> V_55 , & V_202 , & V_232 ) ;
if ( V_30 ) {
F_3 ( L_55 , V_30 ) ;
V_1 -> V_209 -- ;
}
return V_30 ;
}
static int
F_103 ( struct V_234 * V_2 , struct V_235 * V_236 ,
V_134 V_71 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_210 * V_211 = & V_1 -> V_237 ;
int V_30 ;
F_99 ( V_1 , NULL , V_211 ) ;
memcpy ( & V_211 -> V_238 , & V_236 -> V_239 [ 0 ] ,
sizeof( struct V_240 ) ) ;
F_101 ( V_1 , V_211 ) ;
if ( V_71 > 0 ) {
struct V_60 * V_241 = & V_211 -> V_216 [ 1 ] ;
F_100 ( V_57 , V_1 -> V_149 ,
V_71 , V_151 ) ;
memcpy ( V_1 -> V_156 , V_236 -> V_242 , V_71 ) ;
F_97 ( V_57 , V_1 -> V_149 ,
V_71 , V_151 ) ;
V_241 -> V_70 = V_1 -> V_149 ;
V_241 -> V_71 = V_71 ;
V_241 -> V_72 = V_1 -> V_17 -> V_54 -> V_73 ;
V_211 -> V_207 = 2 ;
}
if ( ! V_236 -> V_243 ) {
if ( V_236 -> V_244 ) {
if ( ! V_2 -> V_130 -> V_245 -> V_246 &&
V_1 -> V_17 -> V_80 ) {
V_30 = F_54 ( V_1 ) ;
if ( V_30 ) {
F_3 ( L_56
L_57 , V_1 ) ;
return V_30 ;
}
}
V_30 = F_20 ( V_1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_93 ( V_1 ,
V_40 ) ;
if ( V_30 )
return V_30 ;
F_8 ( & V_1 -> V_145 ) ;
V_1 -> V_138 = V_186 ;
F_9 ( & V_1 -> V_145 ) ;
goto V_247;
}
V_30 = F_68 ( V_1 ) ;
if ( V_30 )
return V_30 ;
}
V_247:
V_30 = F_96 ( V_1 , V_211 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void
F_104 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = ( void * ) V_1 -> V_155 ;
int V_248 = V_1 -> V_249 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_235 * V_236 = V_2 -> V_250 ;
int V_251 ;
F_10 ( L_36 , V_1 ) ;
F_105 ( ! V_236 ) ;
if ( V_236 -> V_252 ) {
struct V_253 * V_254 =
(struct V_253 * ) & V_59 -> V_238 ;
V_236 -> V_255 = ( ! V_254 -> V_256 ) ? 1 : 0 ;
V_236 -> V_257 =
( V_254 -> V_166 & V_258 )
>> 2 ;
V_236 -> V_259 = V_254 -> V_260 ;
V_236 -> V_261 = V_254 -> V_262 ;
memcpy ( V_236 -> V_263 , V_254 -> V_263 , 6 ) ;
V_236 -> V_264 = F_106 ( V_254 -> V_265 ) ;
V_236 -> V_266 = V_254 -> V_267 ;
V_236 -> V_268 = F_106 ( V_254 -> V_269 ) ;
V_236 -> V_270 = F_107 ( V_254 -> V_270 ) ;
V_236 -> V_256 = F_107 ( V_254 -> V_256 ) ;
}
memcpy ( & V_236 -> V_271 [ 0 ] , ( void * ) & V_59 -> V_238 , V_272 ) ;
V_251 = V_20 ( V_248 , V_273 ) ;
F_19 ( L_58
L_59 , V_251 , V_248 ,
V_273 ) ;
memcpy ( V_236 -> V_274 , & V_59 -> V_275 [ 0 ] , V_251 ) ;
if ( V_236 -> V_252 ) {
F_88 ( & V_1 -> V_141 ) ;
return;
}
F_108 ( & V_2 -> V_276 , 0 ) ;
}
static struct V_277
* F_109 ( struct V_234 * V_2 , struct V_58 * V_59 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_221 * V_221 ;
struct V_277 * V_4 ;
V_4 = F_110 ( V_2 , V_278 ) ;
if ( ! V_4 ) {
F_3 ( L_60 ) ;
return NULL ;
}
V_221 = F_111 ( V_4 ) ;
V_221 -> V_2 = V_1 ;
V_221 -> V_277 = V_4 ;
V_221 -> V_59 = V_59 ;
return V_4 ;
}
static int
F_112 ( struct V_1 * V_1 ,
struct V_221 * V_221 , struct V_277 * V_4 ,
struct V_58 * V_59 , unsigned char * V_279 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_280 * V_281 = (struct V_280 * ) V_279 ;
int V_282 , V_283 , V_284 , V_285 , V_286 ;
bool V_287 = false ;
unsigned int V_288 ;
V_286 = F_113 ( V_2 , V_4 , V_279 ) ;
if ( V_286 < 0 )
return V_286 ;
V_282 = V_4 -> V_289 ;
V_283 = V_4 -> V_290 ;
V_284 = V_4 -> V_291 ;
V_288 = V_4 -> V_3 . V_292 ;
if ( V_282 && V_283 == V_288 )
V_4 -> V_3 . V_293 |= V_294 ;
V_286 = F_114 ( V_2 , V_4 , V_281 ) ;
if ( V_286 < 0 ) {
return 0 ;
} else if ( V_286 > 0 ) {
V_287 = true ;
goto V_295;
}
if ( ! V_282 )
return 0 ;
if ( V_283 != V_288 ) {
V_285 = F_115 ( 1UL , F_116 ( V_283 , V_296 ) ) ;
F_117 ( V_4 -> V_3 . V_297 , V_285 ,
& V_59 -> V_275 [ 0 ] , V_283 ) ;
F_19 ( L_61 ,
V_285 , V_283 ) ;
} else {
F_118 ( & V_221 -> V_298 , 1 ) ;
V_4 -> V_3 . V_297 = & V_221 -> V_298 ;
V_4 -> V_3 . V_299 = 1 ;
F_119 ( & V_221 -> V_298 , & V_59 -> V_275 [ 0 ] , V_283 ) ;
F_19 ( L_62 ,
V_283 ) ;
}
V_4 -> V_300 += V_283 ;
if ( V_4 -> V_300 == V_4 -> V_3 . V_292 ) {
F_65 ( & V_4 -> V_301 ) ;
V_4 -> V_302 |= V_303 ;
V_4 -> V_304 = V_305 ;
F_66 ( & V_4 -> V_301 ) ;
}
V_295:
V_286 = F_120 ( V_2 , V_4 , V_279 , V_281 -> V_265 ) ;
if ( ! V_286 && V_287 == false && V_284 )
F_121 ( V_4 ) ;
else if ( V_287 && V_282 )
F_122 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_123 ( struct V_1 * V_1 ,
struct V_58 * V_59 , unsigned char * V_279 )
{
struct V_306 * V_307 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_277 * V_4 = NULL ;
struct V_308 * V_281 = (struct V_308 * ) V_279 ;
V_134 V_309 = F_124 ( V_281 -> V_310 ) ;
int V_286 , V_285 , V_311 , V_312 ;
V_286 = F_125 ( V_2 , V_279 , & V_4 ) ;
if ( V_286 < 0 )
return V_286 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_291 ) {
F_3 ( L_63 ) ;
F_126 () ;
return - 1 ;
}
F_19 ( L_64
L_65 ,
V_309 , V_4 -> V_300 ,
V_4 -> V_3 . V_292 ) ;
V_311 = V_4 -> V_300 / V_296 ;
V_307 = & V_4 -> V_3 . V_297 [ V_311 ] ;
V_285 = F_115 ( 1UL , F_116 ( V_309 , V_296 ) ) ;
V_312 = V_4 -> V_300 % V_296 ;
if ( V_312 ) {
F_3 ( L_66 ) ;
F_126 () ;
return - 1 ;
}
F_19 ( L_67
L_68 , V_307 , V_311 ,
V_285 , & V_59 -> V_275 [ 0 ] , V_309 ) ;
F_117 ( V_307 , V_285 , & V_59 -> V_275 [ 0 ] ,
V_309 ) ;
V_286 = F_127 ( V_4 , V_281 , false ) ;
if ( V_286 < 0 )
return V_286 ;
V_286 = F_95 ( V_1 , V_59 ) ;
if ( V_286 ) {
F_3 ( L_69 , V_286 ) ;
return V_286 ;
}
return 0 ;
}
static int
F_128 ( struct V_1 * V_1 , struct V_221 * V_221 ,
struct V_277 * V_4 , struct V_58 * V_59 ,
unsigned char * V_279 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_313 * V_281 = (struct V_313 * ) V_279 ;
int V_286 ;
V_286 = F_129 ( V_2 , V_4 , V_281 ) ;
if ( V_286 < 0 )
return V_286 ;
return F_130 ( V_2 , V_4 , V_281 ) ;
}
static int
F_131 ( struct V_1 * V_1 , struct V_221 * V_221 ,
struct V_277 * V_4 , struct V_58 * V_59 ,
struct V_314 * V_281 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
V_134 V_315 = F_124 ( V_281 -> V_310 ) ;
int V_286 ;
unsigned char * V_316 = NULL ;
V_286 = F_132 ( V_2 , V_4 , V_281 ) ;
if ( V_286 < 0 )
return V_286 ;
if ( V_315 ) {
V_316 = F_21 ( V_315 , V_65 ) ;
if ( ! V_316 ) {
F_3 ( L_70 ,
V_315 ) ;
return - V_74 ;
}
}
V_4 -> V_317 = V_316 ;
memcpy ( V_4 -> V_317 , & V_59 -> V_275 [ 0 ] , V_315 ) ;
return F_133 ( V_2 , V_4 , V_281 ) ;
}
static int
F_134 ( struct V_1 * V_1 , struct V_58 * V_59 ,
T_2 V_318 , T_3 V_319 ,
T_2 V_320 , T_3 V_321 )
{
struct V_240 * V_281 = & V_59 -> V_238 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_277 * V_4 ;
struct V_221 * V_221 ;
int V_30 = - V_100 ;
V_163 V_217 = ( V_281 -> V_217 & V_322 ) ;
if ( V_2 -> V_130 -> V_245 -> V_246 &&
( ! ( V_217 & V_323 ) || ! ( V_217 & V_324 ) ) ) {
F_3 ( L_71
L_72 , V_217 ) ;
return 0 ;
}
switch ( V_217 ) {
case V_325 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_221 = F_111 ( V_4 ) ;
V_221 -> V_318 = V_318 ;
V_221 -> V_319 = V_319 ;
V_221 -> V_320 = V_320 ;
V_221 -> V_321 = V_321 ;
V_221 -> V_228 = V_318 ? V_318 : V_320 ;
V_30 = F_112 ( V_1 , V_221 , V_4 ,
V_59 , ( unsigned char * ) V_281 ) ;
break;
case V_326 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_221 = F_111 ( V_4 ) ;
V_30 = F_128 ( V_1 , V_221 , V_4 ,
V_59 , ( unsigned char * ) V_281 ) ;
break;
case V_327 :
V_30 = F_123 ( V_1 , V_59 ,
( unsigned char * ) V_281 ) ;
break;
case V_328 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_30 = F_135 ( V_2 , V_4 ,
( unsigned char * ) V_281 ) ;
break;
case V_324 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_30 = F_136 ( V_2 , V_4 , ( unsigned char * ) V_281 ) ;
break;
case V_323 :
if ( F_106 ( V_281 -> V_329 ) != 0xFFFFFFFF )
V_4 = F_137 ( V_2 , V_281 -> V_267 ) ;
else
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_221 = F_111 ( V_4 ) ;
V_30 = F_131 ( V_1 , V_221 , V_4 ,
V_59 , (struct V_314 * ) V_281 ) ;
break;
default:
F_3 ( L_73 , V_217 ) ;
F_126 () ;
break;
}
return V_30 ;
}
static void
F_138 ( struct V_58 * V_59 , struct V_1 * V_1 )
{
struct V_223 * V_223 = & V_59 -> V_222 ;
T_3 V_319 = 0 , V_321 = 0 ;
T_2 V_318 = 0 , V_320 = 0 ;
switch ( V_223 -> V_166 & 0xF0 ) {
case V_224 :
if ( V_223 -> V_166 & V_330 ) {
V_318 = F_106 ( V_223 -> V_318 ) ;
V_319 = F_139 ( V_223 -> V_319 ) ;
F_19 ( L_74 ,
V_318 , ( unsigned long long ) V_319 ) ;
}
if ( V_223 -> V_166 & V_331 ) {
V_320 = F_106 ( V_223 -> V_320 ) ;
V_321 = F_139 ( V_223 -> V_321 ) ;
F_19 ( L_75 ,
V_320 , ( unsigned long long ) V_321 ) ;
}
F_19 ( L_76 ) ;
break;
case V_332 :
F_3 ( L_77 ) ;
break;
default:
F_6 ( L_78 , V_223 -> V_166 ) ;
break;
}
F_134 ( V_1 , V_59 ,
V_318 , V_319 , V_320 , V_321 ) ;
}
static void
F_140 ( struct V_58 * V_115 ,
struct V_1 * V_1 ,
V_134 V_333 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_240 * V_281 ;
T_1 V_334 ;
int V_248 ;
if ( ( char * ) V_115 == V_1 -> V_155 ) {
V_334 = V_1 -> V_152 ;
V_248 = V_150 ;
F_19 ( L_79 ,
V_334 , V_248 ) ;
} else {
V_334 = V_115 -> V_62 ;
V_248 = V_67 ;
F_19 ( L_80 ,
V_334 , V_248 ) ;
}
F_100 ( V_57 , V_334 , V_248 , V_68 ) ;
V_281 = & V_115 -> V_238 ;
F_19 ( L_81 ,
V_281 -> V_217 , V_281 -> V_267 , V_281 -> V_166 ,
( int ) ( V_333 - V_215 ) ) ;
if ( ( char * ) V_115 == V_1 -> V_155 ) {
V_1 -> V_249 = V_333 - V_215 ;
if ( V_1 -> V_2 ) {
struct V_235 * V_236 = V_1 -> V_2 -> V_250 ;
if ( V_236 && ! V_236 -> V_252 )
F_104 ( V_1 ) ;
}
F_8 ( & V_1 -> V_145 ) ;
F_88 ( & V_1 -> V_142 ) ;
F_9 ( & V_1 -> V_145 ) ;
} else {
F_138 ( V_115 , V_1 ) ;
}
F_97 ( V_57 , V_334 , V_248 ,
V_68 ) ;
V_1 -> V_209 -- ;
}
static int
F_141 ( struct V_1 * V_1 , struct V_221 * V_221 ,
struct V_306 * V_298 , V_134 V_335 , V_134 V_71 , V_134 V_336 ,
enum V_337 V_338 , struct V_339 * V_275 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
V_275 -> V_340 = V_338 == V_341 ?
V_151 : V_68 ;
V_275 -> V_342 = V_71 - V_336 ;
V_275 -> V_336 = V_336 ;
V_275 -> V_311 = V_275 -> V_336 / V_296 ;
V_275 -> V_298 = & V_298 [ V_275 -> V_311 ] ;
V_275 -> V_335 = F_31 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_275 -> V_342 = F_31 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_275 -> V_343 = F_142 ( V_57 , V_275 -> V_298 , V_275 -> V_335 ,
V_275 -> V_340 ) ;
if ( F_143 ( ! V_275 -> V_343 ) ) {
F_3 ( L_82 , V_298 ) ;
return - V_100 ;
}
F_19 ( L_83 ,
V_221 , V_275 -> V_343 , V_275 -> V_298 , V_275 -> V_335 , V_275 -> V_342 ) ;
return 0 ;
}
static void
F_144 ( struct V_1 * V_1 , struct V_339 * V_275 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
F_145 ( V_57 , V_275 -> V_298 , V_275 -> V_335 , V_275 -> V_340 ) ;
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
}
static void
V_98 ( struct V_221 * V_221 , struct V_1 * V_1 )
{
struct V_344 * V_345 = & V_221 -> V_225 ;
F_19 ( L_84 , V_221 ) ;
if ( V_345 -> V_275 . V_298 ) {
F_19 ( L_85 , V_221 ) ;
F_144 ( V_1 , & V_345 -> V_275 ) ;
}
if ( V_345 -> V_225 ) {
F_19 ( L_86 , V_221 ) ;
F_25 ( V_345 -> V_225 ) ;
V_345 -> V_225 = NULL ;
}
if ( V_345 -> V_60 ) {
F_19 ( L_87 , V_221 ) ;
F_25 ( V_345 -> V_60 ) ;
V_345 -> V_60 = NULL ;
}
}
static void
V_96 ( struct V_221 * V_221 , struct V_1 * V_1 )
{
struct V_344 * V_345 = & V_221 -> V_225 ;
F_19 ( L_84 , V_221 ) ;
if ( V_345 -> V_106 ) {
F_19 ( L_88 , V_221 , V_345 -> V_106 ) ;
if ( V_345 -> V_106 -> V_121 & V_126 ) {
F_144 ( V_1 , & V_345 -> V_346 ) ;
V_345 -> V_106 -> V_121 &= ~ V_126 ;
}
F_65 ( & V_1 -> V_146 ) ;
F_46 ( & V_345 -> V_106 -> V_109 , & V_1 -> V_108 ) ;
F_66 ( & V_1 -> V_146 ) ;
V_345 -> V_106 = NULL ;
}
if ( V_345 -> V_275 . V_298 ) {
F_19 ( L_85 , V_221 ) ;
F_144 ( V_1 , & V_345 -> V_275 ) ;
}
V_345 -> V_60 = NULL ;
V_345 -> V_225 = NULL ;
}
static void
F_146 ( struct V_221 * V_221 , bool V_347 )
{
struct V_277 * V_4 = V_221 -> V_277 ;
struct V_1 * V_1 = V_221 -> V_2 ;
struct V_234 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_348 * V_281 ;
F_19 ( L_84 , V_221 ) ;
switch ( V_4 -> V_349 ) {
case V_325 :
F_65 ( & V_2 -> V_350 ) ;
if ( ! F_48 ( & V_4 -> V_351 ) )
F_89 ( & V_4 -> V_351 ) ;
F_66 ( & V_2 -> V_350 ) ;
if ( V_4 -> V_352 == V_151 ) {
F_147 ( V_4 ) ;
if ( V_347 &&
V_4 -> V_3 . V_353 == V_354 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_122 ( V_3 ) ;
}
}
V_17 -> V_95 ( V_221 , V_1 ) ;
F_148 ( & V_4 -> V_3 , 0 ) ;
break;
case V_328 :
F_65 ( & V_2 -> V_350 ) ;
if ( ! F_48 ( & V_4 -> V_351 ) )
F_89 ( & V_4 -> V_351 ) ;
F_66 ( & V_2 -> V_350 ) ;
F_148 ( & V_4 -> V_3 , 0 ) ;
break;
case V_355 :
case V_326 :
case V_323 :
V_281 = (struct V_348 * ) & V_221 -> V_211 . V_238 ;
if ( V_281 -> V_166 & V_356 )
break;
F_65 ( & V_2 -> V_350 ) ;
if ( ! F_48 ( & V_4 -> V_351 ) )
F_89 ( & V_4 -> V_351 ) ;
F_66 ( & V_2 -> V_350 ) ;
if ( V_4 -> V_3 . V_357 != NULL ) {
F_19 ( L_89 ,
V_4 -> V_349 ) ;
F_148 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_149 ( V_4 ) ;
break;
}
}
static void
F_150 ( struct V_210 * V_211 , struct V_42 * V_57 )
{
if ( V_211 -> V_62 != 0 ) {
F_19 ( L_90 ) ;
F_24 ( V_57 , V_211 -> V_62 ,
V_215 , V_151 ) ;
V_211 -> V_62 = 0 ;
}
}
static void
F_151 ( struct V_210 * V_211 , struct V_221 * V_221 ,
struct V_42 * V_57 , bool V_347 )
{
if ( V_221 -> V_358 != 0 ) {
F_19 ( L_91 ) ;
F_24 ( V_57 , V_221 -> V_358 ,
V_221 -> V_359 , V_151 ) ;
V_221 -> V_358 = 0 ;
}
F_150 ( V_211 , V_57 ) ;
F_146 ( V_221 , V_347 ) ;
}
static int
F_152 ( struct V_3 * V_3 , struct V_360 * V_113 )
{
struct V_361 V_362 ;
int V_30 ;
V_30 = F_153 ( V_113 , V_363 , & V_362 ) ;
if ( V_30 ) {
F_3 ( L_92 , V_30 ) ;
goto V_364;
}
if ( V_362 . V_365 & V_363 ) {
T_1 V_366 ;
V_134 V_367 = V_3 -> V_368 -> V_369 . V_367 + 8 ;
switch ( V_362 . V_370 . V_371 ) {
case V_372 :
V_3 -> V_373 = V_374 ;
break;
case V_375 :
V_3 -> V_373 = V_376 ;
break;
case V_377 :
V_3 -> V_373 = V_378 ;
break;
}
V_366 = V_362 . V_370 . V_379 ;
F_154 ( V_366 , V_367 ) ;
V_3 -> V_380 = V_366 + V_3 -> V_381 ;
F_3 ( L_93
L_94 ,
V_362 . V_370 . V_371 ,
( unsigned long long ) V_3 -> V_380 ,
V_362 . V_370 . V_382 ,
V_362 . V_370 . V_383 ) ;
V_30 = 1 ;
}
V_364:
return V_30 ;
}
static void
F_155 ( struct V_210 * V_211 ,
struct V_221 * V_221 )
{
struct V_344 * V_345 = & V_221 -> V_225 ;
struct V_277 * V_4 = V_221 -> V_277 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_221 -> V_2 ;
struct V_16 * V_17 = V_1 -> V_17 ;
int V_30 = 0 ;
if ( V_345 -> V_106 && V_345 -> V_106 -> V_121 & V_126 ) {
V_30 = F_152 ( V_3 ,
V_345 -> V_106 -> V_111 -> V_113 ) ;
V_345 -> V_106 -> V_121 &= ~ V_126 ;
}
V_17 -> V_95 ( V_221 , V_1 ) ;
V_345 -> V_384 = 0 ;
if ( V_30 )
F_156 ( V_3 ,
V_3 -> V_373 , 0 ) ;
else
F_157 ( V_1 -> V_2 , V_4 ) ;
}
static void
F_158 ( struct V_210 * V_211 ,
struct V_221 * V_221 )
{
struct V_344 * V_345 = & V_221 -> V_225 ;
struct V_277 * V_4 = V_221 -> V_277 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_221 -> V_2 ;
struct V_16 * V_17 = V_1 -> V_17 ;
int V_30 = 0 ;
if ( V_345 -> V_106 && V_345 -> V_106 -> V_121 & V_126 ) {
V_30 = F_152 ( V_3 ,
V_345 -> V_106 -> V_111 -> V_113 ) ;
V_345 -> V_106 -> V_121 &= ~ V_126 ;
}
F_147 ( V_4 ) ;
V_17 -> V_95 ( V_221 , V_1 ) ;
V_4 -> V_300 = V_345 -> V_275 . V_342 ;
V_345 -> V_384 = 0 ;
F_19 ( L_95 , V_221 ) ;
F_65 ( & V_4 -> V_301 ) ;
V_4 -> V_302 |= V_303 ;
V_4 -> V_304 = V_305 ;
F_66 ( & V_4 -> V_301 ) ;
if ( V_30 ) {
F_122 ( V_3 ) ;
F_156 ( V_3 ,
V_3 -> V_373 , 0 ) ;
} else {
F_159 ( V_3 ) ;
}
}
static void
F_160 ( struct V_385 * V_75 )
{
struct V_221 * V_221 = F_79 ( V_75 ,
struct V_221 , V_386 ) ;
struct V_1 * V_1 = V_221 -> V_2 ;
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_277 * V_4 = V_221 -> V_277 ;
F_19 ( L_96 , V_221 , V_4 -> V_304 ) ;
switch ( V_4 -> V_304 ) {
case V_387 :
F_161 ( V_4 , V_4 -> V_2 ) ;
case V_388 :
case V_389 :
V_4 -> V_304 = V_390 ;
F_151 ( & V_221 -> V_211 , V_221 ,
V_57 , false ) ;
break;
case V_391 :
F_162 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_97 , V_4 -> V_304 ) ;
F_126 () ;
break;
}
}
static void
F_163 ( struct V_210 * V_211 ,
struct V_221 * V_221 ,
struct V_1 * V_1 ,
struct V_42 * V_57 )
{
struct V_277 * V_4 = V_221 -> V_277 ;
if ( V_4 -> V_304 == V_387 ||
V_4 -> V_304 == V_391 ||
V_4 -> V_304 == V_388 ||
V_4 -> V_304 == V_389 ) {
F_150 ( V_211 , V_57 ) ;
F_34 ( & V_221 -> V_386 , F_160 ) ;
F_90 ( V_392 , & V_221 -> V_386 ) ;
return;
}
V_4 -> V_304 = V_390 ;
F_151 ( V_211 , V_221 , V_57 , false ) ;
}
static void
F_164 ( struct V_210 * V_211 ,
struct V_1 * V_1 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_221 * V_221 = V_211 -> V_221 ;
struct V_344 * V_345 ;
if ( ! V_221 ) {
F_150 ( V_211 , V_57 ) ;
return;
}
V_345 = & V_221 -> V_225 ;
F_19 ( L_98 , V_221 , V_345 -> V_226 ) ;
switch ( V_345 -> V_226 ) {
case V_227 :
F_163 ( V_211 , V_221 ,
V_1 , V_57 ) ;
break;
case V_341 :
F_155 ( V_211 , V_221 ) ;
break;
case V_393 :
F_158 ( V_211 , V_221 ) ;
break;
default:
F_3 ( L_99 , V_345 -> V_226 ) ;
F_126 () ;
break;
}
}
static inline bool
F_165 ( struct V_1 * V_1 , void * V_204 )
{
void * V_394 = V_1 -> V_64 ;
int V_342 = V_40 * sizeof( * V_1 -> V_64 ) ;
if ( V_204 >= V_394 && V_204 < V_394 + V_342 )
return false ;
return true ;
}
static void
F_166 ( struct V_1 * V_1 , struct V_395 * V_396 )
{
if ( V_396 -> V_204 == V_397 ) {
F_10 ( L_100 ,
V_1 ) ;
F_88 ( & V_1 -> V_398 ) ;
} else if ( F_165 ( V_1 , ( void * ) ( V_205 ) V_396 -> V_204 ) ) {
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_221 * V_221 ;
struct V_210 * V_115 ;
V_115 = (struct V_210 * ) ( V_205 ) V_396 -> V_204 ;
V_221 = V_115 -> V_221 ;
if ( ! V_221 )
F_150 ( V_115 , V_57 ) ;
else
F_151 ( V_115 , V_221 , V_57 , true ) ;
} else {
V_1 -> V_209 -- ;
if ( ! V_1 -> V_209 )
F_167 ( V_1 -> V_2 , 0 ) ;
}
}
static void
F_168 ( struct V_395 * V_396 )
{
struct V_1 * V_1 ;
struct V_210 * V_211 ;
struct V_58 * V_59 ;
V_1 = V_396 -> V_55 -> V_32 ;
if ( F_169 ( V_396 -> V_192 == V_399 ) ) {
if ( V_396 -> V_217 == V_400 ) {
V_59 = (struct V_58 * ) ( V_205 ) V_396 -> V_204 ;
F_140 ( V_59 , V_1 , V_396 -> V_401 ) ;
} else {
V_211 = (struct V_210 * ) ( V_205 ) V_396 -> V_204 ;
F_164 ( V_211 , V_1 ) ;
}
} else {
if ( V_396 -> V_192 != V_402 )
F_3 ( L_101 ,
F_170 ( V_396 -> V_192 ) , V_396 -> V_192 ,
V_396 -> V_204 , V_396 -> V_403 ) ;
else
F_19 ( L_102 ,
F_170 ( V_396 -> V_192 ) , V_396 -> V_192 ,
V_396 -> V_204 ) ;
if ( V_396 -> V_204 != V_404 )
F_166 ( V_1 , V_396 ) ;
}
}
static void
V_84 ( struct V_385 * V_75 )
{
enum { V_405 = 65536 };
struct V_15 * V_18 = F_79 ( V_75 , struct V_15 ,
V_75 ) ;
struct V_395 * const V_406 = V_18 -> V_406 ;
int V_19 , V_407 , V_408 = 0 ;
while ( ( V_407 = F_171 ( V_18 -> V_34 , F_172 ( V_18 -> V_406 ) , V_406 ) ) > 0 ) {
for ( V_19 = 0 ; V_19 < V_407 ; V_19 ++ )
F_168 ( & V_406 [ V_19 ] ) ;
V_408 += V_407 ;
if ( V_408 >= V_405 )
break;
}
F_36 ( V_18 -> V_34 , V_89 ) ;
}
static void
V_87 ( struct V_409 * V_34 , void * V_10 )
{
struct V_15 * V_18 = V_10 ;
F_90 ( V_392 , & V_18 -> V_75 ) ;
}
static int
F_173 ( struct V_1 * V_1 , struct V_221 * V_221 )
{
struct V_212 * V_410 ;
int V_30 ;
V_30 = F_95 ( V_1 , V_221 -> V_59 ) ;
if ( V_30 ) {
F_3 ( L_69 , V_30 ) ;
return V_30 ;
}
V_30 = F_98 ( V_1 -> V_55 , & V_221 -> V_211 . V_213 ,
& V_410 ) ;
if ( V_30 ) {
F_3 ( L_103 , V_30 ) ;
return V_30 ;
}
return V_30 ;
}
static int
F_157 ( struct V_234 * V_2 , struct V_277 * V_4 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_212 * V_213 = & V_221 -> V_211 . V_213 ;
struct V_411 * V_281 = (struct V_411 * )
& V_221 -> V_211 . V_238 ;
F_99 ( V_1 , V_221 , & V_221 -> V_211 ) ;
F_174 ( V_4 , V_2 , true , V_281 ) ;
F_101 ( V_1 , & V_221 -> V_211 ) ;
if ( V_4 -> V_3 . V_412 &&
( ( V_4 -> V_3 . V_293 & V_413 ) ||
( V_4 -> V_3 . V_293 & V_414 ) ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_60 * V_241 = & V_221 -> V_211 . V_216 [ 1 ] ;
V_134 V_415 , V_416 ;
F_175 ( V_4 -> V_3 . V_417 ,
V_4 -> V_412 ) ;
V_4 -> V_3 . V_417 += sizeof( V_418 ) ;
V_415 = - ( V_4 -> V_3 . V_417 ) & 3 ;
F_176 ( V_281 -> V_310 , ( V_134 ) V_4 -> V_3 . V_417 ) ;
V_416 = V_4 -> V_3 . V_417 + V_415 ;
V_221 -> V_358 = F_22 ( V_57 ,
( void * ) V_4 -> V_412 , V_416 ,
V_151 ) ;
V_221 -> V_359 = V_416 ;
V_241 -> V_70 = V_221 -> V_358 ;
V_241 -> V_71 = V_416 ;
V_241 -> V_72 = V_17 -> V_54 -> V_73 ;
V_221 -> V_211 . V_207 = 2 ;
}
F_102 ( V_1 , V_221 , V_213 ) ;
F_19 ( L_104 ) ;
return F_173 ( V_1 , V_221 ) ;
}
static void
F_177 ( struct V_234 * V_2 , struct V_277 * V_4 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
F_65 ( & V_2 -> V_350 ) ;
if ( ! F_48 ( & V_4 -> V_351 ) )
F_89 ( & V_4 -> V_351 ) ;
F_66 ( & V_2 -> V_350 ) ;
if ( V_4 -> V_352 == V_151 )
F_147 ( V_4 ) ;
V_17 -> V_95 ( V_221 , V_1 ) ;
}
static enum V_419
F_178 ( struct V_234 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_2 -> V_420 -> V_421 . V_422 ) {
if ( V_17 -> V_51 ) {
F_10 ( L_105 , V_1 ) ;
V_1 -> V_5 = true ;
return V_423 ;
}
}
F_10 ( L_106 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_179 ( struct V_277 * V_4 , struct V_234 * V_2 ,
bool V_424 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_212 * V_213 = & V_221 -> V_211 . V_213 ;
F_99 ( V_1 , V_221 , & V_221 -> V_211 ) ;
F_180 ( V_4 , V_2 , (struct V_425 * )
& V_221 -> V_211 . V_238 ,
V_424 ) ;
F_101 ( V_1 , & V_221 -> V_211 ) ;
F_102 ( V_1 , V_221 , V_213 ) ;
F_19 ( L_107 , V_1 ) ;
return F_173 ( V_1 , V_221 ) ;
}
static int
F_181 ( struct V_277 * V_4 , struct V_234 * V_2 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_212 * V_213 = & V_221 -> V_211 . V_213 ;
F_99 ( V_1 , V_221 , & V_221 -> V_211 ) ;
F_182 ( V_4 , V_2 , (struct V_426 * )
& V_221 -> V_211 . V_238 ) ;
F_101 ( V_1 , & V_221 -> V_211 ) ;
F_102 ( V_1 , V_221 , V_213 ) ;
F_19 ( L_108 , V_1 ) ;
return F_173 ( V_1 , V_221 ) ;
}
static int
F_183 ( struct V_277 * V_4 , struct V_234 * V_2 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_212 * V_213 = & V_221 -> V_211 . V_213 ;
F_99 ( V_1 , V_221 , & V_221 -> V_211 ) ;
F_184 ( V_4 , V_2 , (struct V_427 * )
& V_221 -> V_211 . V_238 ) ;
F_101 ( V_1 , & V_221 -> V_211 ) ;
F_102 ( V_1 , V_221 , V_213 ) ;
F_19 ( L_109 , V_1 ) ;
return F_173 ( V_1 , V_221 ) ;
}
static int
F_185 ( struct V_277 * V_4 , struct V_234 * V_2 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_212 * V_213 = & V_221 -> V_211 . V_213 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_60 * V_241 = & V_221 -> V_211 . V_216 [ 1 ] ;
struct V_428 * V_281 =
(struct V_428 * ) & V_221 -> V_211 . V_238 ;
F_99 ( V_1 , V_221 , & V_221 -> V_211 ) ;
F_186 ( V_4 , V_2 , V_281 ) ;
F_101 ( V_1 , & V_221 -> V_211 ) ;
F_176 ( V_281 -> V_310 , V_272 ) ;
V_221 -> V_358 = F_22 ( V_57 ,
( void * ) V_4 -> V_429 , V_272 ,
V_151 ) ;
V_221 -> V_359 = V_272 ;
V_241 -> V_70 = V_221 -> V_358 ;
V_241 -> V_71 = V_272 ;
V_241 -> V_72 = V_17 -> V_54 -> V_73 ;
V_221 -> V_211 . V_207 = 2 ;
F_102 ( V_1 , V_221 , V_213 ) ;
F_19 ( L_110 , V_1 ) ;
return F_173 ( V_1 , V_221 ) ;
}
static int
F_187 ( struct V_277 * V_4 , struct V_234 * V_2 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_212 * V_213 = & V_221 -> V_211 . V_213 ;
struct V_348 * V_281 =
(struct V_348 * ) & V_221 -> V_211 . V_238 ;
V_134 V_430 ;
int V_286 ;
F_99 ( V_1 , V_221 , & V_221 -> V_211 ) ;
V_286 = F_188 ( V_4 , V_2 , V_281 , V_431 ) ;
if ( V_286 < 0 )
return V_286 ;
V_430 = V_286 ;
F_101 ( V_1 , & V_221 -> V_211 ) ;
if ( V_430 ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_60 * V_241 = & V_221 -> V_211 . V_216 [ 1 ] ;
void * V_432 = V_4 -> V_429 ;
V_221 -> V_358 = F_22 ( V_57 ,
V_432 , V_430 , V_151 ) ;
V_221 -> V_359 = V_430 ;
V_241 -> V_70 = V_221 -> V_358 ;
V_241 -> V_71 = V_430 ;
V_241 -> V_72 = V_17 -> V_54 -> V_73 ;
V_221 -> V_211 . V_207 = 2 ;
}
F_102 ( V_1 , V_221 , V_213 ) ;
F_19 ( L_111 , V_1 ) ;
return F_173 ( V_1 , V_221 ) ;
}
static int
F_189 ( struct V_1 * V_1 , struct V_221 * V_221 ,
struct V_60 * V_60 , struct V_433 * V_225 ,
V_134 V_434 , V_134 V_336 )
{
struct V_277 * V_4 = V_221 -> V_277 ;
struct V_306 * V_307 , * V_435 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
V_134 V_311 , V_312 ;
int V_19 = 0 , V_285 ;
V_311 = V_336 / V_296 ;
V_307 = & V_4 -> V_3 . V_297 [ V_311 ] ;
V_285 = V_20 ( V_4 -> V_3 . V_299 - V_311 , V_1 -> V_44 ) ;
V_312 = V_336 % V_296 ;
V_225 -> V_345 . V_206 = V_60 ;
V_225 -> V_345 . V_204 = ( V_205 ) & V_221 -> V_211 ;
F_190 (sg_start, tmp_sg, sg_nents, i) {
F_19 ( L_112
L_113 ,
( unsigned long long ) V_435 -> V_436 ,
V_435 -> V_71 , V_312 ) ;
V_60 -> V_70 = F_191 ( V_57 , V_435 ) + V_312 ;
V_60 -> V_71 = F_31 ( V_134 , V_434 ,
F_192 ( V_57 , V_435 ) - V_312 ) ;
V_60 -> V_72 = V_17 -> V_54 -> V_73 ;
F_19 ( L_114 ,
V_60 -> V_70 , V_60 -> V_71 , V_60 -> V_72 ) ;
V_312 = 0 ;
V_434 -= V_60 -> V_71 ;
if ( ! V_434 )
break;
V_60 ++ ;
F_19 ( L_115 , V_60 ) ;
}
V_225 -> V_345 . V_207 = ++ V_19 ;
F_19 ( L_116 ,
V_225 -> V_345 . V_206 , V_225 -> V_345 . V_207 ) ;
return V_225 -> V_345 . V_207 ;
}
static int
V_97 ( struct V_234 * V_2 , struct V_277 * V_4 ,
struct V_344 * V_345 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_339 * V_275 = & V_345 -> V_275 ;
struct V_433 * V_225 ;
struct V_60 * V_60 ;
V_134 V_336 , V_288 , V_434 , V_437 , V_438 = 0 ;
int V_30 = 0 , V_19 , V_439 ;
V_221 -> V_211 . V_221 = V_221 ;
V_336 = V_345 -> V_226 == V_393 ? V_4 -> V_300 : 0 ;
V_30 = F_141 ( V_1 , V_221 , V_3 -> V_297 ,
V_3 -> V_299 , V_3 -> V_292 ,
V_336 , V_345 -> V_226 , & V_345 -> V_275 ) ;
if ( V_30 )
return V_30 ;
V_434 = V_275 -> V_342 ;
V_336 = V_275 -> V_336 ;
V_60 = F_21 ( sizeof( struct V_60 ) * V_275 -> V_335 , V_65 ) ;
if ( ! V_60 ) {
F_6 ( L_117 ) ;
V_30 = - V_74 ;
goto V_440;
}
V_345 -> V_60 = V_60 ;
V_345 -> V_384 = F_116 ( V_275 -> V_335 , V_1 -> V_44 ) ;
V_345 -> V_225 = F_21 ( sizeof( struct V_433 ) * V_345 -> V_384 ,
V_65 ) ;
if ( ! V_345 -> V_225 ) {
F_19 ( L_118 ) ;
V_30 = - V_74 ;
goto V_440;
}
V_345 -> V_221 = V_221 ;
V_437 = V_1 -> V_44 * V_296 ;
for ( V_19 = 0 ; V_19 < V_345 -> V_384 ; V_19 ++ ) {
V_225 = & V_221 -> V_225 . V_225 [ V_19 ] ;
V_288 = V_20 ( V_434 , V_437 ) ;
V_225 -> V_345 . V_219 = 0 ;
if ( V_345 -> V_226 == V_341 ) {
V_225 -> V_345 . V_217 = V_441 ;
V_225 -> V_442 = V_221 -> V_319 + V_336 ;
V_225 -> V_443 = V_221 -> V_318 ;
if ( V_19 + 1 == V_345 -> V_384 )
V_225 -> V_345 . V_208 = & V_221 -> V_211 . V_213 ;
else
V_225 -> V_345 . V_208 = & V_345 -> V_225 [ V_19 + 1 ] . V_345 ;
} else {
V_225 -> V_345 . V_217 = V_444 ;
V_225 -> V_442 = V_221 -> V_321 + V_438 ;
V_225 -> V_443 = V_221 -> V_320 ;
if ( V_19 + 1 == V_345 -> V_384 )
V_225 -> V_345 . V_219 = V_220 ;
else
V_225 -> V_345 . V_208 = & V_345 -> V_225 [ V_19 + 1 ] . V_345 ;
}
V_439 = F_189 ( V_1 , V_221 , V_60 ,
V_225 , V_288 , V_336 ) ;
V_60 += V_439 ;
V_336 += V_288 ;
V_438 += V_288 ;
V_434 -= V_288 ;
}
return 0 ;
V_440:
F_144 ( V_1 , V_275 ) ;
return V_30 ;
}
static inline void
F_193 ( struct V_212 * V_445 , struct V_360 * V_446 )
{
V_134 V_443 ;
memset ( V_445 , 0 , sizeof( * V_445 ) ) ;
V_445 -> V_204 = V_404 ;
V_445 -> V_217 = V_447 ;
V_445 -> V_230 . V_231 = V_446 -> V_443 ;
V_443 = F_194 ( V_446 -> V_443 ) ;
F_195 ( V_446 , V_443 ) ;
}
static int
F_196 ( struct V_1 * V_1 ,
struct V_105 * V_106 ,
struct V_339 * V_448 ,
enum V_449 V_121 ,
struct V_60 * V_233 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_360 * V_446 ;
struct V_450 V_451 ;
struct V_212 V_445 , * V_452 , * V_345 = NULL ;
int V_30 , V_407 ;
if ( V_448 -> V_343 == 1 ) {
V_233 -> V_72 = V_17 -> V_54 -> V_73 ;
V_233 -> V_70 = F_191 ( V_57 , & V_448 -> V_298 [ 0 ] ) ;
V_233 -> V_71 = F_192 ( V_57 , & V_448 -> V_298 [ 0 ] ) ;
F_19 ( L_119 ,
V_233 -> V_70 , V_233 -> V_71 , V_233 -> V_72 ) ;
return 0 ;
}
if ( V_121 == V_127 )
V_446 = V_106 -> V_110 ;
else
V_446 = V_106 -> V_111 -> V_112 ;
if ( ! ( V_106 -> V_121 & V_121 ) ) {
F_193 ( & V_445 , V_446 ) ;
V_345 = & V_445 ;
}
V_407 = F_197 ( V_446 , V_448 -> V_298 , V_448 -> V_335 , V_296 ) ;
if ( F_143 ( V_407 != V_448 -> V_335 ) ) {
F_3 ( L_120 ,
V_407 , V_448 -> V_335 ) ;
return V_407 < 0 ? V_407 : - V_100 ;
}
F_19 ( L_121 ,
V_106 , V_448 -> V_335 , V_448 -> V_336 ) ;
V_451 . V_345 . V_208 = NULL ;
V_451 . V_345 . V_217 = V_453 ;
V_451 . V_345 . V_204 = V_404 ;
V_451 . V_345 . V_219 = 0 ;
V_451 . V_345 . V_207 = 0 ;
V_451 . V_446 = V_446 ;
V_451 . V_454 = V_446 -> V_72 ;
V_451 . V_455 = V_456 ;
if ( ! V_345 )
V_345 = & V_451 . V_345 ;
else
V_345 -> V_208 = & V_451 . V_345 ;
V_30 = F_98 ( V_1 -> V_55 , V_345 , & V_452 ) ;
if ( V_30 ) {
F_3 ( L_122 , V_30 ) ;
return V_30 ;
}
V_106 -> V_121 &= ~ V_121 ;
V_233 -> V_72 = V_446 -> V_72 ;
V_233 -> V_70 = V_446 -> V_457 ;
V_233 -> V_71 = V_446 -> V_71 ;
F_19 ( L_119 ,
V_233 -> V_70 , V_233 -> V_71 , V_233 -> V_72 ) ;
return V_30 ;
}
static inline void
F_198 ( struct V_3 * V_3 , struct V_458 * V_459 ,
struct V_460 * V_461 )
{
V_461 -> V_462 = V_463 ;
V_461 -> V_464 . V_465 . V_466 = V_467 ;
V_461 -> V_464 . V_465 . V_468 = V_3 -> V_368 -> V_369 . V_367 ;
V_461 -> V_464 . V_465 . V_469 = V_3 -> V_470 ;
V_461 -> V_464 . V_465 . V_471 = 0xffff ;
V_461 -> V_464 . V_465 . V_472 = true ;
V_461 -> V_464 . V_465 . V_473 = true ;
if ( V_3 -> V_474 == V_475 ||
V_3 -> V_474 == V_476 )
V_461 -> V_464 . V_465 . V_477 = true ;
}
static int
F_199 ( struct V_3 * V_3 , struct V_458 * V_459 )
{
switch ( V_3 -> V_6 ) {
case V_478 :
case V_479 :
V_459 -> V_448 . V_462 = V_480 ;
F_198 ( V_3 , V_459 , & V_459 -> V_481 ) ;
break;
case V_482 :
case V_483 :
V_459 -> V_481 . V_462 = V_480 ;
F_198 ( V_3 , V_459 , & V_459 -> V_448 ) ;
break;
case V_484 :
case V_485 :
F_198 ( V_3 , V_459 , & V_459 -> V_481 ) ;
F_198 ( V_3 , V_459 , & V_459 -> V_448 ) ;
break;
default:
F_3 ( L_123 , V_3 -> V_6 ) ;
return - V_100 ;
}
return 0 ;
}
static inline V_163
F_200 ( V_163 V_486 )
{
return ( V_486 & V_487 ? 0xc0 : 0 ) |
( V_486 & V_488 ? 0x30 : 0 ) |
( V_486 & V_488 ? 0x0f : 0 ) ;
}
static int
F_201 ( struct V_1 * V_1 ,
struct V_3 * V_3 ,
struct V_344 * V_225 ,
struct V_105 * V_106 )
{
struct V_489 V_490 ;
struct V_212 V_445 , * V_452 , * V_345 = NULL ;
struct V_117 * V_111 = V_106 -> V_111 ;
struct V_458 V_459 ;
int V_30 ;
memset ( & V_459 , 0 , sizeof( V_459 ) ) ;
V_30 = F_199 ( V_3 , & V_459 ) ;
if ( V_30 )
goto V_56;
V_459 . V_491 = F_200 ( V_3 -> V_486 ) ;
if ( ! ( V_106 -> V_121 & V_125 ) ) {
F_193 ( & V_445 , V_111 -> V_113 ) ;
V_345 = & V_445 ;
}
memset ( & V_490 , 0 , sizeof( V_490 ) ) ;
V_490 . V_345 . V_217 = V_492 ;
V_490 . V_345 . V_204 = V_404 ;
V_490 . V_345 . V_206 = & V_225 -> V_493 [ V_494 ] ;
V_490 . V_345 . V_207 = 1 ;
V_490 . V_495 = V_456 ;
V_490 . V_459 = & V_459 ;
V_490 . V_113 = V_111 -> V_113 ;
if ( V_3 -> V_496 )
V_490 . V_346 = & V_225 -> V_493 [ V_497 ] ;
if ( ! V_345 )
V_345 = & V_490 . V_345 ;
else
V_345 -> V_208 = & V_490 . V_345 ;
V_30 = F_98 ( V_1 -> V_55 , V_345 , & V_452 ) ;
if ( V_30 ) {
F_3 ( L_122 , V_30 ) ;
goto V_56;
}
V_106 -> V_121 &= ~ V_125 ;
V_225 -> V_493 [ V_498 ] . V_72 = V_111 -> V_113 -> V_72 ;
V_225 -> V_493 [ V_498 ] . V_70 = 0 ;
V_225 -> V_493 [ V_498 ] . V_71 = V_3 -> V_292 ;
if ( V_3 -> V_6 != V_483 &&
V_3 -> V_6 != V_482 )
V_225 -> V_493 [ V_498 ] . V_71 += V_3 -> V_499 ;
F_19 ( L_124 ,
V_225 -> V_493 [ V_498 ] . V_70 , V_225 -> V_493 [ V_498 ] . V_71 ,
V_225 -> V_493 [ V_498 ] . V_72 ) ;
V_56:
return V_30 ;
}
static int
F_202 ( struct V_1 * V_1 ,
struct V_221 * V_221 ,
struct V_344 * V_345 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_3 * V_3 = & V_221 -> V_277 -> V_3 ;
int V_30 ;
if ( ! V_345 -> V_106 -> V_111 ) {
V_30 = F_51 ( V_345 -> V_106 ,
V_17 -> V_42 ,
V_17 -> V_54 ) ;
if ( V_30 ) {
F_3 ( L_125 ,
V_1 ) ;
return V_30 ;
}
}
if ( V_3 -> V_496 ) {
V_30 = F_141 ( V_1 , V_221 ,
V_3 -> V_496 ,
V_3 -> V_500 ,
V_3 -> V_499 ,
0 , V_345 -> V_226 , & V_345 -> V_346 ) ;
if ( V_30 ) {
F_3 ( L_126 ,
V_1 ) ;
return V_30 ;
}
memset ( & V_345 -> V_493 [ V_497 ] , 0 , sizeof( V_345 -> V_493 [ V_497 ] ) ) ;
V_30 = F_196 ( V_1 , V_345 -> V_106 , & V_345 -> V_346 ,
V_122 , & V_345 -> V_493 [ V_497 ] ) ;
if ( V_30 ) {
F_3 ( L_127 ,
V_1 ) ;
goto V_501;
}
}
V_30 = F_201 ( V_1 , V_3 , V_345 , V_345 -> V_106 ) ;
if ( V_30 ) {
F_3 ( L_127 ,
V_1 ) ;
goto V_501;
}
V_345 -> V_106 -> V_121 |= V_126 ;
return 0 ;
V_501:
if ( V_3 -> V_496 )
F_144 ( V_1 , & V_345 -> V_346 ) ;
return V_30 ;
}
static int
V_94 ( struct V_234 * V_2 , struct V_277 * V_4 ,
struct V_344 * V_345 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_105 * V_106 = NULL ;
struct V_433 * V_225 ;
struct V_60 * V_493 ;
V_134 V_336 ;
int V_30 = 0 ;
unsigned long V_166 ;
V_221 -> V_211 . V_221 = V_221 ;
V_336 = V_345 -> V_226 == V_393 ? V_4 -> V_300 : 0 ;
V_30 = F_141 ( V_1 , V_221 , V_3 -> V_297 ,
V_3 -> V_299 , V_3 -> V_292 ,
V_336 , V_345 -> V_226 , & V_345 -> V_275 ) ;
if ( V_30 )
return V_30 ;
if ( V_345 -> V_275 . V_343 != 1 || F_1 ( V_1 , V_3 ) ) {
F_203 ( & V_1 -> V_146 , V_166 ) ;
V_106 = F_204 ( & V_1 -> V_108 ,
struct V_105 , V_109 ) ;
F_42 ( & V_106 -> V_109 ) ;
F_205 ( & V_1 -> V_146 , V_166 ) ;
V_345 -> V_106 = V_106 ;
}
V_30 = F_196 ( V_1 , V_106 , & V_345 -> V_275 ,
V_127 , & V_345 -> V_493 [ V_494 ] ) ;
if ( V_30 )
goto V_440;
if ( F_1 ( V_1 , V_3 ) ) {
V_30 = F_202 ( V_1 , V_221 , V_345 ) ;
if ( V_30 )
goto V_440;
V_493 = & V_345 -> V_493 [ V_498 ] ;
} else {
V_493 = & V_345 -> V_493 [ V_494 ] ;
}
memcpy ( & V_345 -> V_502 , V_493 , sizeof( * V_493 ) ) ;
V_345 -> V_60 = & V_345 -> V_502 ;
V_345 -> V_384 = 1 ;
memset ( & V_345 -> V_503 , 0 , sizeof( V_345 -> V_503 ) ) ;
V_345 -> V_225 = & V_345 -> V_503 ;
V_345 -> V_221 = V_221 ;
V_225 = & V_221 -> V_225 . V_503 ;
V_225 -> V_345 . V_206 = & V_345 -> V_502 ;
V_225 -> V_345 . V_207 = 1 ;
V_225 -> V_345 . V_204 = ( V_205 ) & V_221 -> V_211 ;
if ( V_345 -> V_226 == V_341 ) {
V_225 -> V_345 . V_217 = V_441 ;
V_225 -> V_442 = V_221 -> V_319 ;
V_225 -> V_443 = V_221 -> V_318 ;
V_225 -> V_345 . V_219 = ! F_1 ( V_1 , V_3 ) ?
0 : V_220 ;
} else {
V_225 -> V_345 . V_217 = V_444 ;
V_225 -> V_442 = V_221 -> V_321 ;
V_225 -> V_443 = V_221 -> V_320 ;
V_225 -> V_345 . V_219 = V_220 ;
}
return 0 ;
V_440:
if ( V_106 ) {
F_203 ( & V_1 -> V_146 , V_166 ) ;
F_46 ( & V_106 -> V_109 , & V_1 -> V_108 ) ;
F_205 ( & V_1 -> V_146 , V_166 ) ;
}
F_144 ( V_1 , & V_345 -> V_275 ) ;
return V_30 ;
}
static int
F_206 ( struct V_234 * V_2 , struct V_277 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_344 * V_345 = & V_221 -> V_225 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_212 * V_410 ;
int V_286 ;
F_19 ( L_128 ,
V_221 , V_3 -> V_292 ) ;
V_345 -> V_226 = V_341 ;
V_286 = V_17 -> V_93 ( V_2 , V_4 , V_345 ) ;
if ( V_286 ) {
F_3 ( L_129 , V_221 ) ;
return V_286 ;
}
if ( ! F_1 ( V_1 , V_3 ) ) {
F_99 ( V_1 , V_221 ,
& V_221 -> V_211 ) ;
F_174 ( V_4 , V_2 , true , (struct V_411 * )
& V_221 -> V_211 . V_238 ) ;
F_101 ( V_1 , & V_221 -> V_211 ) ;
F_102 ( V_1 , V_221 ,
& V_221 -> V_211 . V_213 ) ;
V_221 -> V_225 . V_503 . V_345 . V_208 = & V_221 -> V_211 . V_213 ;
V_345 -> V_384 += 1 ;
V_286 = F_95 ( V_1 , V_221 -> V_59 ) ;
if ( V_286 ) {
F_3 ( L_69 , V_286 ) ;
return V_286 ;
}
}
V_286 = F_98 ( V_1 -> V_55 , & V_345 -> V_225 -> V_345 , & V_410 ) ;
if ( V_286 )
F_6 ( L_130 ) ;
if ( ! F_1 ( V_1 , V_3 ) )
F_19 ( L_131
L_132 , V_221 ) ;
else
F_19 ( L_133 ,
V_221 ) ;
return 1 ;
}
static int
F_207 ( struct V_234 * V_2 , struct V_277 * V_4 , bool V_504 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_221 * V_221 = F_111 ( V_4 ) ;
struct V_344 * V_345 = & V_221 -> V_225 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_212 * V_410 ;
int V_286 ;
F_19 ( L_134 ,
V_221 , V_3 -> V_292 , V_4 -> V_300 ) ;
V_345 -> V_226 = V_393 ;
V_286 = V_17 -> V_93 ( V_2 , V_4 , V_345 ) ;
if ( V_286 ) {
F_3 ( L_129 , V_221 ) ;
return V_286 ;
}
V_286 = F_98 ( V_1 -> V_55 , & V_345 -> V_225 -> V_345 , & V_410 ) ;
if ( V_286 )
F_6 ( L_135 ) ;
F_19 ( L_136 ,
V_221 ) ;
return 0 ;
}
static int
F_208 ( struct V_234 * V_2 , struct V_277 * V_4 , int V_138 )
{
struct V_221 * V_221 = F_111 ( V_4 ) ;
int V_30 = 0 ;
switch ( V_138 ) {
case V_505 :
F_65 ( & V_2 -> V_350 ) ;
F_89 ( & V_4 -> V_351 ) ;
F_66 ( & V_2 -> V_350 ) ;
F_146 ( V_221 , true ) ;
break;
case V_506 :
V_30 = F_179 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_137 , V_138 ) ;
V_30 = - V_100 ;
break;
}
return V_30 ;
}
static int
F_209 ( struct V_234 * V_2 , struct V_277 * V_4 , int V_138 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
switch ( V_138 ) {
case V_391 :
V_30 = F_181 ( V_4 , V_2 ) ;
if ( ! V_30 )
V_1 -> V_507 = true ;
break;
case V_508 :
V_30 = F_179 ( V_4 , V_2 , true ) ;
break;
case V_387 :
V_30 = F_183 ( V_4 , V_2 ) ;
break;
case V_388 :
V_30 = F_185 ( V_4 , V_2 ) ;
break;
case V_389 :
V_30 = F_187 ( V_4 , V_2 ) ;
break;
case V_509 :
V_30 = F_157 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_138 , V_138 ) ;
V_30 = - V_100 ;
break;
}
return V_30 ;
}
struct V_26 *
F_86 ( struct V_170 * V_170 )
{
struct V_171 * V_172 = V_170 -> V_172 ;
struct V_26 * V_510 ;
struct V_511 * V_512 ;
int V_30 ;
V_512 = (struct V_511 * ) & V_172 -> V_513 ;
F_19 ( L_139 , & V_172 -> V_513 , V_512 ) ;
V_510 = F_210 ( & V_514 , F_92 , V_170 ,
V_515 , V_50 ) ;
if ( F_16 ( V_510 ) ) {
F_3 ( L_140 , F_17 ( V_510 ) ) ;
V_30 = F_17 ( V_510 ) ;
goto V_99;
}
F_19 ( L_141 , V_510 , V_510 -> V_10 ) ;
V_30 = F_211 ( V_510 , V_512 ) ;
if ( V_30 ) {
F_3 ( L_142 , V_30 ) ;
goto V_516;
}
V_30 = F_212 ( V_510 , 0 ) ;
if ( V_30 ) {
F_3 ( L_143 , V_30 ) ;
goto V_516;
}
return V_510 ;
V_516:
F_72 ( V_510 ) ;
V_99:
return F_14 ( V_30 ) ;
}
static int
F_213 ( struct V_171 * V_172 ,
struct V_517 * V_518 )
{
struct V_170 * V_170 ;
struct V_26 * V_519 ;
int V_30 ;
V_170 = F_21 ( sizeof( struct V_170 ) , V_65 ) ;
if ( ! V_170 ) {
F_3 ( L_144 ) ;
return - V_74 ;
}
F_214 ( & V_170 -> V_181 , 0 ) ;
F_59 ( & V_170 -> V_145 ) ;
F_45 ( & V_170 -> V_177 ) ;
F_45 ( & V_170 -> V_180 ) ;
V_170 -> V_172 = V_172 ;
memcpy ( & V_172 -> V_513 , V_518 ,
sizeof( struct V_517 ) ) ;
V_519 = F_86 ( V_170 ) ;
if ( F_16 ( V_519 ) ) {
V_30 = F_17 ( V_519 ) ;
goto V_99;
}
V_170 -> V_13 = V_519 ;
V_172 -> V_520 = V_170 ;
return 0 ;
V_99:
F_25 ( V_170 ) ;
return V_30 ;
}
static int
F_69 ( struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_159 V_521 ;
int V_30 ;
struct V_522 V_523 ;
memset ( & V_521 , 0 , sizeof( struct V_159 ) ) ;
V_521 . V_162 = V_1 -> V_162 ;
V_521 . V_524 = 7 ;
V_521 . V_525 = 7 ;
memset ( & V_523 , 0 , sizeof( V_523 ) ) ;
V_523 . V_166 = V_526 ;
if ( ! V_1 -> V_167 )
V_523 . V_166 = V_523 . V_166 | V_527 ;
V_521 . V_165 = ( void * ) & V_523 ;
V_521 . V_528 = sizeof( V_523 ) ;
V_30 = F_215 ( V_13 , & V_521 ) ;
if ( V_30 ) {
F_3 ( L_145 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int
F_216 ( struct V_234 * V_2 , struct V_235 * V_236 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
F_10 ( L_146 , V_1 ) ;
V_30 = F_217 ( & V_1 -> V_142 ) ;
if ( V_30 ) {
F_3 ( L_147 ,
V_1 ) ;
return V_30 ;
}
F_218 ( & V_1 -> V_142 ) ;
if ( ! V_236 -> V_252 )
return 0 ;
F_104 ( V_1 ) ;
F_10 ( L_148 , V_2 ) ;
V_30 = F_217 ( & V_1 -> V_141 ) ;
if ( V_30 )
return V_30 ;
F_10 ( L_149 , V_236 -> V_271 ) ;
return 0 ;
}
static void
F_219 ( struct V_171 * V_172 , struct V_234 * V_2 ,
struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_529 * V_530 = & V_13 -> V_531 ;
V_2 -> V_532 = V_172 -> V_513 . V_533 ;
V_2 -> V_534 = V_530 -> V_70 . V_535 ;
V_2 -> V_536 = V_530 -> V_70 . V_537 ;
}
static int
F_220 ( struct V_171 * V_172 , struct V_234 * V_2 )
{
struct V_170 * V_170 = V_172 -> V_520 ;
struct V_1 * V_1 ;
int V_30 ;
V_538:
V_30 = F_221 ( & V_170 -> V_181 ) ;
if ( V_30 )
return - V_539 ;
F_65 ( & V_172 -> V_173 ) ;
if ( V_172 -> V_540 >= V_541 ) {
F_66 ( & V_172 -> V_173 ) ;
F_19 ( L_150 ,
V_172 -> V_540 ) ;
return - V_539 ;
}
F_66 ( & V_172 -> V_173 ) ;
F_8 ( & V_170 -> V_145 ) ;
if ( F_48 ( & V_170 -> V_180 ) ) {
F_9 ( & V_170 -> V_145 ) ;
goto V_538;
}
V_1 = F_204 ( & V_170 -> V_180 ,
struct V_1 , V_140 ) ;
F_89 ( & V_1 -> V_140 ) ;
F_9 ( & V_170 -> V_145 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
F_219 ( V_172 , V_2 , V_1 ) ;
F_19 ( L_151 , V_1 ) ;
return 0 ;
}
static void
F_222 ( struct V_171 * V_172 )
{
struct V_170 * V_170 = V_172 -> V_520 ;
struct V_1 * V_1 , * V_407 ;
if ( V_170 -> V_13 )
F_72 ( V_170 -> V_13 ) ;
F_8 ( & V_170 -> V_145 ) ;
if ( ! F_48 ( & V_170 -> V_180 ) ) {
F_10 ( L_152 ) ;
F_49 (isert_conn, n,
&isert_np->pending,
node) {
F_10 ( L_153 ,
V_1 , V_1 -> V_138 ) ;
F_70 ( V_1 ) ;
}
}
if ( ! F_48 ( & V_170 -> V_177 ) ) {
F_10 ( L_154 ) ;
F_49 (isert_conn, n,
&isert_np->accepted,
node) {
F_10 ( L_153 ,
V_1 , V_1 -> V_138 ) ;
F_70 ( V_1 ) ;
}
}
F_9 ( & V_170 -> V_145 ) ;
V_172 -> V_520 = NULL ;
F_25 ( V_170 ) ;
}
static void V_148 ( struct V_385 * V_75 )
{
struct V_1 * V_1 = F_79 ( V_75 ,
struct V_1 ,
V_147 ) ;
F_10 ( L_155 , V_1 ) ;
F_223 ( & V_1 -> V_143 ) ;
F_8 ( & V_1 -> V_145 ) ;
V_1 -> V_138 = V_542 ;
F_9 ( & V_1 -> V_145 ) ;
F_10 ( L_156 , V_1 ) ;
F_80 ( V_1 ) ;
}
static void
F_224 ( struct V_1 * V_1 )
{
struct V_234 * V_2 = V_1 -> V_2 ;
F_10 ( L_36 , V_1 ) ;
if ( V_1 -> V_507 ) {
F_10 ( L_157 , V_1 ) ;
F_225 ( & V_2 -> V_543 ,
V_544 * V_545 ) ;
}
}
static void
F_226 ( struct V_234 * V_2 )
{
F_10 ( L_158 , V_2 ) ;
if ( V_2 -> V_130 ) {
F_227 ( V_2 -> V_130 -> V_129 ) ;
F_228 ( V_2 -> V_130 -> V_129 ) ;
}
}
static void
F_229 ( struct V_1 * V_1 )
{
struct V_201 * V_452 ;
F_10 ( L_36 , V_1 ) ;
F_57 ( & V_1 -> V_398 ) ;
V_1 -> V_546 . V_204 = V_397 ;
if ( F_94 ( V_1 -> V_55 , & V_1 -> V_546 , & V_452 ) ) {
F_3 ( L_159 , V_1 ) ;
return;
}
F_223 ( & V_1 -> V_398 ) ;
}
static void
F_230 ( struct V_234 * V_2 )
{
struct V_277 * V_4 , * V_107 ;
static F_231 ( V_547 ) ;
F_65 ( & V_2 -> V_350 ) ;
F_49 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_302 & V_548 ) &&
( V_4 -> V_300 < V_2 -> V_130 -> V_245 -> V_549 ) &&
( V_4 -> V_300 < V_4 -> V_3 . V_292 ) )
F_76 ( & V_4 -> V_351 , & V_547 ) ;
}
F_66 ( & V_2 -> V_350 ) ;
F_49 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_89 ( & V_4 -> V_351 ) ;
if ( V_4 -> V_304 != V_505 ) {
struct V_221 * V_221 = F_111 ( V_4 ) ;
F_10 ( L_160 , V_2 , V_4 ) ;
F_146 ( V_221 , true ) ;
}
}
}
static void F_232 ( struct V_234 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_10 ( L_161 , V_1 ) ;
F_8 ( & V_1 -> V_145 ) ;
if ( V_1 -> V_138 == V_139 ) {
F_9 ( & V_1 -> V_145 ) ;
return;
}
F_82 ( V_1 ) ;
F_9 ( & V_1 -> V_145 ) ;
F_229 ( V_1 ) ;
F_230 ( V_2 ) ;
F_226 ( V_2 ) ;
F_224 ( V_1 ) ;
F_90 ( V_191 , & V_1 -> V_147 ) ;
}
static void F_233 ( struct V_234 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_229 ( V_1 ) ;
F_80 ( V_1 ) ;
}
static int T_4 F_234 ( void )
{
int V_30 ;
V_392 = F_235 ( L_162 ,
V_550 | V_551 , 0 ) ;
if ( ! V_392 ) {
F_3 ( L_163 ) ;
V_30 = - V_74 ;
return - V_74 ;
}
V_191 = F_235 ( L_164 , V_550 ,
V_552 ) ;
if ( ! V_191 ) {
F_3 ( L_165 ) ;
V_30 = - V_74 ;
goto V_553;
}
F_236 ( & V_554 ) ;
F_10 ( L_166 ) ;
return 0 ;
V_553:
F_237 ( V_392 ) ;
return V_30 ;
}
static void T_5 F_238 ( void )
{
F_239 () ;
F_237 ( V_191 ) ;
F_237 ( V_392 ) ;
F_240 ( & V_554 ) ;
F_10 ( L_167 ) ;
}
