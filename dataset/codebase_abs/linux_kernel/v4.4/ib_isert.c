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
V_36 . V_42 . V_47 = V_24 -> V_48 . V_20 ;
V_1 -> V_20 = V_27 ( V_24 -> V_48 . V_20 ,
V_24 -> V_48 . V_21 ) ;
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
V_25 = F_10 ( V_1 ) ;
V_1 -> V_58 = F_15 ( V_1 , V_25 , V_34 ) ;
if ( F_19 ( V_1 -> V_58 ) ) {
V_19 = F_20 ( V_1 -> V_58 ) ;
goto V_59;
}
return 0 ;
V_59:
F_14 ( V_25 ) ;
return V_19 ;
}
static void
F_21 ( struct V_8 * V_9 , void * V_10 )
{
F_9 ( L_8 , V_9 -> V_11 ) ;
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
V_63 -> V_74 = V_24 -> V_57 -> V_75 ;
}
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
return - V_76 ;
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
F_30 ( & V_25 -> V_77 ) ;
F_31 ( V_25 -> V_40 ) ;
}
}
F_27 ( V_24 -> V_30 ) ;
}
static int
F_32 ( struct V_23 * V_24 ,
struct V_17 * V_36 )
{
int V_26 , V_78 , V_19 = 0 ;
V_24 -> V_29 = V_27 ( V_79 , F_33 ( int , F_34 () ,
V_24 -> V_15 -> V_80 ) ) ;
F_13 ( L_10
L_11 ,
V_24 -> V_29 , V_24 -> V_15 -> V_81 ,
V_24 -> V_15 -> V_80 , V_24 -> V_82 ,
V_24 -> V_54 ) ;
V_24 -> V_30 = F_35 ( V_24 -> V_29 , sizeof( struct V_22 ) ,
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
F_36 ( & V_25 -> V_77 , V_86 ) ;
V_85 . V_87 = V_78 ;
V_85 . V_88 = V_26 ;
V_25 -> V_40 = F_37 ( V_24 -> V_15 ,
V_89 ,
F_21 ,
( void * ) V_25 ,
& V_85 ) ;
if ( F_19 ( V_25 -> V_40 ) ) {
F_3 ( L_13 ) ;
V_19 = F_20 ( V_25 -> V_40 ) ;
V_25 -> V_40 = NULL ;
goto V_90;
}
V_19 = F_38 ( V_25 -> V_40 , V_91 ) ;
if ( V_19 )
goto V_90;
}
return 0 ;
V_90:
F_29 ( V_24 ) ;
return V_19 ;
}
static int
F_39 ( struct V_23 * V_24 )
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
V_19 = F_32 ( V_24 , V_48 ) ;
if ( V_19 )
return V_19 ;
V_24 -> V_57 = F_40 ( V_24 -> V_15 ) ;
if ( F_19 ( V_24 -> V_57 ) ) {
V_19 = F_20 ( V_24 -> V_57 ) ;
F_3 ( L_14 ,
V_24 , V_19 ) ;
goto V_90;
}
V_24 -> V_54 = V_48 -> V_92 &
V_94 ? true : false ;
return 0 ;
V_90:
F_29 ( V_24 ) ;
return V_19 ;
}
static void
F_41 ( struct V_23 * V_24 )
{
F_13 ( L_15 , V_24 ) ;
F_42 ( V_24 -> V_57 ) ;
F_29 ( V_24 ) ;
}
static void
F_43 ( struct V_23 * V_24 )
{
F_11 ( & V_28 ) ;
V_24 -> V_101 -- ;
F_13 ( L_16 , V_24 , V_24 -> V_101 ) ;
if ( ! V_24 -> V_101 ) {
F_41 ( V_24 ) ;
F_44 ( & V_24 -> V_102 ) ;
F_27 ( V_24 ) ;
}
F_12 ( & V_28 ) ;
}
static struct V_23 *
F_45 ( struct V_33 * V_34 )
{
struct V_23 * V_24 ;
int V_19 ;
F_11 ( & V_28 ) ;
F_46 (device, &device_list, dev_node) {
if ( V_24 -> V_15 -> V_103 == V_34 -> V_24 -> V_103 ) {
V_24 -> V_101 ++ ;
F_13 ( L_17 ,
V_24 , V_24 -> V_101 ) ;
F_12 ( & V_28 ) ;
return V_24 ;
}
}
V_24 = F_23 ( sizeof( struct V_23 ) , V_67 ) ;
if ( ! V_24 ) {
F_12 ( & V_28 ) ;
return F_17 ( - V_76 ) ;
}
F_47 ( & V_24 -> V_102 ) ;
V_24 -> V_15 = V_34 -> V_24 ;
V_19 = F_39 ( V_24 ) ;
if ( V_19 ) {
F_27 ( V_24 ) ;
F_12 ( & V_28 ) ;
return F_17 ( V_19 ) ;
}
V_24 -> V_101 ++ ;
F_48 ( & V_24 -> V_102 , & V_104 ) ;
F_13 ( L_18 ,
V_24 , V_24 -> V_101 ) ;
F_12 ( & V_28 ) ;
return V_24 ;
}
static void
F_49 ( struct V_1 * V_1 )
{
struct V_105 * V_106 , * V_107 ;
int V_26 = 0 ;
if ( F_50 ( & V_1 -> V_108 ) )
return;
F_13 ( L_19 , V_1 ) ;
F_51 (fr_desc, tmp,
&isert_conn->fr_pool, list) {
F_44 ( & V_106 -> V_109 ) ;
F_52 ( V_106 -> V_110 ) ;
if ( V_106 -> V_111 ) {
F_52 ( V_106 -> V_111 -> V_112 ) ;
F_52 ( V_106 -> V_111 -> V_113 ) ;
F_27 ( V_106 -> V_111 ) ;
}
F_27 ( V_106 ) ;
++ V_26 ;
}
if ( V_26 < V_1 -> V_114 )
F_6 ( L_20 ,
V_1 -> V_114 - V_26 ) ;
}
static int
F_53 ( struct V_105 * V_115 ,
struct V_15 * V_24 ,
struct V_116 * V_57 )
{
struct V_117 * V_111 ;
int V_19 ;
V_111 = F_23 ( sizeof( * V_115 -> V_111 ) , V_67 ) ;
if ( ! V_111 ) {
F_3 ( L_21 ) ;
return - V_76 ;
}
V_111 -> V_112 = F_54 ( V_57 , V_118 ,
V_119 ) ;
if ( F_19 ( V_111 -> V_112 ) ) {
F_3 ( L_22 ,
F_20 ( V_111 -> V_112 ) ) ;
V_19 = F_20 ( V_111 -> V_112 ) ;
goto V_120;
}
V_115 -> V_121 |= V_122 ;
V_111 -> V_113 = F_54 ( V_57 , V_123 , 2 ) ;
if ( F_19 ( V_111 -> V_113 ) ) {
F_3 ( L_23 ,
F_20 ( V_111 -> V_113 ) ) ;
V_19 = F_20 ( V_111 -> V_113 ) ;
goto V_124;
}
V_115 -> V_111 = V_111 ;
V_115 -> V_121 |= V_125 ;
V_115 -> V_121 &= ~ V_126 ;
return 0 ;
V_124:
F_52 ( V_111 -> V_112 ) ;
V_120:
F_27 ( V_111 ) ;
return V_19 ;
}
static int
F_55 ( struct V_15 * V_15 , struct V_116 * V_57 ,
struct V_105 * V_106 )
{
V_106 -> V_110 = F_54 ( V_57 , V_118 ,
V_119 ) ;
if ( F_19 ( V_106 -> V_110 ) ) {
F_3 ( L_24 ,
F_20 ( V_106 -> V_110 ) ) ;
return F_20 ( V_106 -> V_110 ) ;
}
V_106 -> V_121 |= V_127 ;
F_9 ( L_25 , V_106 ) ;
return 0 ;
}
static int
F_56 ( struct V_1 * V_1 )
{
struct V_105 * V_106 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_128 * V_129 = V_1 -> V_2 -> V_130 -> V_129 ;
struct V_131 * V_132 = V_129 -> V_131 ;
int V_26 , V_19 , V_133 ;
V_133 = F_57 ( V_134 , V_135 , V_132 -> V_136 ) ;
V_133 = ( V_133 * 2 ) + V_137 ;
V_1 -> V_114 = 0 ;
for ( V_26 = 0 ; V_26 < V_133 ; V_26 ++ ) {
V_106 = F_23 ( sizeof( * V_106 ) , V_67 ) ;
if ( ! V_106 ) {
F_3 ( L_26 ) ;
V_19 = - V_76 ;
goto V_59;
}
V_19 = F_55 ( V_24 -> V_15 ,
V_24 -> V_57 , V_106 ) ;
if ( V_19 ) {
F_3 ( L_27 ,
V_19 ) ;
F_27 ( V_106 ) ;
goto V_59;
}
F_48 ( & V_106 -> V_109 , & V_1 -> V_108 ) ;
V_1 -> V_114 ++ ;
}
F_9 ( L_28 ,
V_1 , V_1 -> V_114 ) ;
return 0 ;
V_59:
F_49 ( V_1 ) ;
return V_19 ;
}
static void
F_58 ( struct V_1 * V_1 )
{
V_1 -> V_138 = V_139 ;
F_47 ( & V_1 -> V_140 ) ;
F_59 ( & V_1 -> V_141 ) ;
F_59 ( & V_1 -> V_142 ) ;
F_59 ( & V_1 -> V_143 ) ;
F_60 ( & V_1 -> V_144 ) ;
F_61 ( & V_1 -> V_145 ) ;
F_62 ( & V_1 -> V_146 ) ;
F_47 ( & V_1 -> V_108 ) ;
F_36 ( & V_1 -> V_147 , V_148 ) ;
}
static void
F_63 ( struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_24 -> V_15 ;
F_26 ( V_16 , V_1 -> V_149 ,
V_150 , V_151 ) ;
F_26 ( V_16 , V_1 -> V_152 ,
V_153 ,
V_70 ) ;
F_27 ( V_1 -> V_154 ) ;
}
static int
F_64 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
int V_19 ;
V_1 -> V_154 = F_23 ( V_153 +
V_150 , V_67 ) ;
if ( ! V_1 -> V_154 ) {
F_3 ( L_29 ) ;
return - V_76 ;
}
V_1 -> V_155 = V_1 -> V_154 ;
V_1 -> V_156 = V_1 -> V_154 +
V_153 ;
F_9 ( L_30 ,
V_1 -> V_154 , V_1 -> V_155 ,
V_1 -> V_156 ) ;
V_1 -> V_152 = F_24 ( V_16 ,
( void * ) V_1 -> V_155 ,
V_153 , V_70 ) ;
V_19 = F_25 ( V_16 , V_1 -> V_152 ) ;
if ( V_19 ) {
F_3 ( L_31 , V_19 ) ;
V_1 -> V_152 = 0 ;
goto V_157;
}
V_1 -> V_149 = F_24 ( V_16 ,
( void * ) V_1 -> V_156 ,
V_150 , V_151 ) ;
V_19 = F_25 ( V_16 , V_1 -> V_149 ) ;
if ( V_19 ) {
F_3 ( L_32 , V_19 ) ;
V_1 -> V_149 = 0 ;
goto V_158;
}
return 0 ;
V_158:
F_26 ( V_16 , V_1 -> V_152 ,
V_153 , V_70 ) ;
V_157:
F_27 ( V_1 -> V_154 ) ;
return V_19 ;
}
static int
F_65 ( struct V_33 * V_34 , struct V_159 * V_11 )
{
struct V_160 * V_160 = V_34 -> V_10 ;
struct V_161 * V_162 = V_160 -> V_162 ;
struct V_1 * V_1 ;
struct V_23 * V_24 ;
int V_19 = 0 ;
F_66 ( & V_162 -> V_163 ) ;
if ( ! V_162 -> V_164 ) {
F_67 ( & V_162 -> V_163 ) ;
F_9 ( L_33 ) ;
return F_68 ( V_34 , NULL , 0 ) ;
}
F_67 ( & V_162 -> V_163 ) ;
F_9 ( L_34 ,
V_34 , V_34 -> V_10 ) ;
V_1 = F_23 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_1 )
return - V_76 ;
F_58 ( V_1 ) ;
V_1 -> V_13 = V_34 ;
V_19 = F_64 ( V_1 , V_34 -> V_24 ) ;
if ( V_19 )
goto V_165;
V_24 = F_45 ( V_34 ) ;
if ( F_19 ( V_24 ) ) {
V_19 = F_20 ( V_24 ) ;
goto V_166;
}
V_1 -> V_24 = V_24 ;
V_1 -> V_167 = F_33 ( V_168 ,
V_11 -> V_169 . V_2 . V_167 ,
V_24 -> V_48 . V_170 ) ;
F_9 ( L_35 , V_1 -> V_167 ) ;
V_19 = F_18 ( V_1 , V_34 ) ;
if ( V_19 )
goto V_171;
V_19 = F_69 ( V_1 ) ;
if ( V_19 )
goto V_171;
V_19 = F_70 ( V_1 ) ;
if ( V_19 )
goto V_171;
F_11 ( & V_160 -> V_145 ) ;
F_48 ( & V_1 -> V_140 , & V_160 -> V_172 ) ;
F_12 ( & V_160 -> V_145 ) ;
return 0 ;
V_171:
F_43 ( V_24 ) ;
V_166:
F_63 ( V_1 ) ;
V_165:
F_27 ( V_1 ) ;
F_68 ( V_34 , NULL , 0 ) ;
return V_19 ;
}
static void
F_71 ( struct V_1 * V_1 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
F_9 ( L_36 , V_1 ) ;
F_72 ( ! V_24 ) ;
if ( V_24 -> V_82 )
F_49 ( V_1 ) ;
F_28 ( V_1 ) ;
if ( V_1 -> V_13 )
F_73 ( V_1 -> V_13 ) ;
if ( V_1 -> V_58 ) {
struct V_22 * V_25 = V_1 -> V_58 -> V_41 -> V_173 ;
F_14 ( V_25 ) ;
F_74 ( V_1 -> V_58 ) ;
}
if ( V_1 -> V_154 )
F_63 ( V_1 ) ;
F_43 ( V_24 ) ;
F_27 ( V_1 ) ;
}
static void
F_75 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
struct V_160 * V_160 = V_34 -> V_10 ;
F_13 ( L_36 , V_1 ) ;
F_11 ( & V_1 -> V_145 ) ;
V_1 -> V_138 = V_174 ;
F_76 ( & V_1 -> V_144 ) ;
F_12 ( & V_1 -> V_145 ) ;
F_11 ( & V_160 -> V_145 ) ;
F_77 ( & V_1 -> V_140 , & V_160 -> V_175 ) ;
F_12 ( & V_160 -> V_145 ) ;
F_13 ( L_37 , V_160 ) ;
F_78 ( & V_160 -> V_176 ) ;
}
static void
F_79 ( struct V_144 * V_144 )
{
struct V_1 * V_1 = F_80 ( V_144 ,
struct V_1 , V_144 ) ;
F_13 ( L_38 , V_1 , V_177 -> V_178 ,
V_177 -> V_179 ) ;
F_71 ( V_1 ) ;
}
static void
F_81 ( struct V_1 * V_1 )
{
F_82 ( & V_1 -> V_144 , F_79 ) ;
}
static void
F_83 ( struct V_1 * V_1 )
{
int V_59 ;
switch ( V_1 -> V_138 ) {
case V_180 :
break;
case V_174 :
case V_181 :
F_13 ( L_39 ,
V_1 , V_1 -> V_138 ) ;
V_1 -> V_138 = V_180 ;
V_59 = F_84 ( V_1 -> V_13 ) ;
if ( V_59 )
F_6 ( L_40 ,
V_1 ) ;
break;
default:
F_6 ( L_41 ,
V_1 , V_1 -> V_138 ) ;
}
}
static int
F_85 ( struct V_160 * V_160 ,
enum V_182 V_11 )
{
F_9 ( L_42 ,
F_86 ( V_11 ) , V_11 , V_160 ) ;
switch ( V_11 ) {
case V_183 :
V_160 -> V_13 = NULL ;
break;
case V_184 :
V_160 -> V_13 = F_87 ( V_160 ) ;
if ( F_19 ( V_160 -> V_13 ) ) {
F_3 ( L_43 ,
V_160 , F_20 ( V_160 -> V_13 ) ) ;
V_160 -> V_13 = NULL ;
}
break;
default:
F_3 ( L_44 ,
V_160 , V_11 ) ;
}
return - 1 ;
}
static int
F_88 ( struct V_33 * V_34 ,
enum V_182 V_11 )
{
struct V_160 * V_160 = V_34 -> V_10 ;
struct V_1 * V_1 ;
bool V_185 = false ;
if ( V_160 -> V_13 == V_34 )
return F_85 ( V_34 -> V_10 , V_11 ) ;
V_1 = V_34 -> V_58 -> V_38 ;
F_11 ( & V_1 -> V_145 ) ;
V_185 = ( V_1 -> V_138 == V_180 ) ;
F_83 ( V_1 ) ;
F_12 ( & V_1 -> V_145 ) ;
F_13 ( L_45 , V_1 ) ;
F_89 ( & V_1 -> V_143 ) ;
if ( V_185 )
goto V_165;
F_11 ( & V_160 -> V_145 ) ;
if ( ! F_50 ( & V_1 -> V_140 ) ) {
F_90 ( & V_1 -> V_140 ) ;
F_81 ( V_1 ) ;
F_91 ( V_186 , & V_1 -> V_147 ) ;
}
F_12 ( & V_160 -> V_145 ) ;
V_165:
return 0 ;
}
static int
F_92 ( struct V_33 * V_34 )
{
struct V_1 * V_1 = V_34 -> V_58 -> V_38 ;
F_90 ( & V_1 -> V_140 ) ;
V_1 -> V_13 = NULL ;
F_81 ( V_1 ) ;
return - 1 ;
}
static int
F_93 ( struct V_33 * V_34 , struct V_159 * V_11 )
{
int V_19 = 0 ;
F_13 ( L_46 ,
F_86 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_187 , V_34 , V_34 -> V_10 ) ;
switch ( V_11 -> V_11 ) {
case V_188 :
V_19 = F_65 ( V_34 , V_11 ) ;
if ( V_19 )
F_3 ( L_47 , V_19 ) ;
break;
case V_189 :
F_75 ( V_34 ) ;
break;
case V_184 :
case V_190 :
case V_183 :
case V_191 :
V_19 = F_88 ( V_34 , V_11 -> V_11 ) ;
break;
case V_192 :
case V_193 :
case V_194 :
V_19 = F_92 ( V_34 ) ;
break;
default:
F_3 ( L_48 , V_11 -> V_11 ) ;
break;
}
return V_19 ;
}
static int
F_94 ( struct V_1 * V_1 , V_134 V_195 )
{
struct V_196 * V_197 , * V_198 ;
int V_26 , V_19 ;
struct V_60 * V_61 ;
for ( V_197 = V_1 -> V_197 , V_26 = 0 ; V_26 < V_195 ; V_26 ++ , V_197 ++ ) {
V_61 = & V_1 -> V_66 [ V_26 ] ;
V_197 -> V_199 = ( V_200 ) V_61 ;
V_197 -> V_201 = & V_61 -> V_63 ;
V_197 -> V_202 = 1 ;
V_197 -> V_203 = V_197 + 1 ;
}
V_197 -- ;
V_197 -> V_203 = NULL ;
V_1 -> V_204 += V_195 ;
V_19 = F_95 ( V_1 -> V_58 , V_1 -> V_197 ,
& V_198 ) ;
if ( V_19 ) {
F_3 ( L_49 , V_19 ) ;
V_1 -> V_204 -= V_195 ;
}
return V_19 ;
}
static int
F_96 ( struct V_1 * V_1 , struct V_60 * V_61 )
{
struct V_196 * V_198 , V_197 ;
int V_19 ;
V_197 . V_199 = ( V_200 ) V_61 ;
V_197 . V_201 = & V_61 -> V_63 ;
V_197 . V_202 = 1 ;
V_197 . V_203 = NULL ;
V_1 -> V_204 ++ ;
V_19 = F_95 ( V_1 -> V_58 , & V_197 , & V_198 ) ;
if ( V_19 ) {
F_3 ( L_49 , V_19 ) ;
V_1 -> V_204 -- ;
}
return V_19 ;
}
static int
F_97 ( struct V_1 * V_1 , struct V_205 * V_206 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_207 V_208 , * V_209 ;
int V_19 ;
F_98 ( V_16 , V_206 -> V_64 ,
V_210 , V_151 ) ;
V_208 . V_203 = NULL ;
V_208 . V_199 = ( V_200 ) V_206 ;
V_208 . V_201 = V_206 -> V_211 ;
V_208 . V_202 = V_206 -> V_202 ;
V_208 . V_212 = V_213 ;
V_208 . V_214 = V_215 ;
V_19 = F_99 ( V_1 -> V_58 , & V_208 , & V_209 ) ;
if ( V_19 )
F_3 ( L_50 , V_19 ) ;
return V_19 ;
}
static void
F_100 ( struct V_1 * V_1 ,
struct V_216 * V_216 ,
struct V_205 * V_206 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
F_101 ( V_16 , V_206 -> V_64 ,
V_210 , V_151 ) ;
memset ( & V_206 -> V_217 , 0 , sizeof( struct V_218 ) ) ;
V_206 -> V_217 . V_219 = V_220 ;
V_206 -> V_202 = 1 ;
V_206 -> V_216 = V_216 ;
if ( V_206 -> V_211 [ 0 ] . V_74 != V_24 -> V_57 -> V_75 ) {
V_206 -> V_211 [ 0 ] . V_74 = V_24 -> V_57 -> V_75 ;
F_9 ( L_51 , V_206 ) ;
}
}
static int
F_102 ( struct V_1 * V_1 ,
struct V_205 * V_206 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
T_1 V_64 ;
V_64 = F_24 ( V_16 , ( void * ) V_206 ,
V_210 , V_151 ) ;
if ( F_25 ( V_16 , V_64 ) ) {
F_3 ( L_52 ) ;
return - V_76 ;
}
V_206 -> V_64 = V_64 ;
V_206 -> V_211 [ 0 ] . V_72 = V_206 -> V_64 ;
V_206 -> V_211 [ 0 ] . V_73 = V_210 ;
V_206 -> V_211 [ 0 ] . V_74 = V_24 -> V_57 -> V_75 ;
F_9 ( L_53 ,
V_206 -> V_211 [ 0 ] . V_72 , V_206 -> V_211 [ 0 ] . V_73 ,
V_206 -> V_211 [ 0 ] . V_74 ) ;
return 0 ;
}
static void
F_103 ( struct V_1 * V_1 , struct V_216 * V_216 ,
struct V_207 * V_208 )
{
struct V_205 * V_206 = & V_216 -> V_206 ;
V_216 -> V_221 . V_222 = V_223 ;
V_208 -> V_199 = ( V_200 ) & V_216 -> V_206 ;
V_208 -> V_212 = V_213 ;
V_208 -> V_201 = & V_206 -> V_211 [ 0 ] ;
V_208 -> V_202 = V_216 -> V_206 . V_202 ;
V_208 -> V_214 = V_215 ;
}
static int
F_69 ( struct V_1 * V_1 )
{
struct V_196 V_197 , * V_224 ;
struct V_62 V_225 ;
int V_19 ;
memset ( & V_225 , 0 , sizeof( struct V_62 ) ) ;
V_225 . V_72 = V_1 -> V_152 ;
V_225 . V_73 = V_150 ;
V_225 . V_74 = V_1 -> V_24 -> V_57 -> V_75 ;
F_9 ( L_54 ,
V_225 . V_72 , V_225 . V_73 , V_225 . V_74 ) ;
memset ( & V_197 , 0 , sizeof( struct V_196 ) ) ;
V_197 . V_199 = ( V_200 ) V_1 -> V_155 ;
V_197 . V_201 = & V_225 ;
V_197 . V_202 = 1 ;
V_1 -> V_204 ++ ;
V_19 = F_95 ( V_1 -> V_58 , & V_197 , & V_224 ) ;
if ( V_19 ) {
F_3 ( L_55 , V_19 ) ;
V_1 -> V_204 -- ;
}
return V_19 ;
}
static int
F_104 ( struct V_226 * V_2 , struct V_227 * V_228 ,
V_134 V_73 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_205 * V_206 = & V_1 -> V_229 ;
int V_19 ;
F_100 ( V_1 , NULL , V_206 ) ;
memcpy ( & V_206 -> V_230 , & V_228 -> V_231 [ 0 ] ,
sizeof( struct V_232 ) ) ;
F_102 ( V_1 , V_206 ) ;
if ( V_73 > 0 ) {
struct V_62 * V_233 = & V_206 -> V_211 [ 1 ] ;
F_101 ( V_16 , V_1 -> V_149 ,
V_73 , V_151 ) ;
memcpy ( V_1 -> V_156 , V_228 -> V_234 , V_73 ) ;
F_98 ( V_16 , V_1 -> V_149 ,
V_73 , V_151 ) ;
V_233 -> V_72 = V_1 -> V_149 ;
V_233 -> V_73 = V_73 ;
V_233 -> V_74 = V_1 -> V_24 -> V_57 -> V_75 ;
V_206 -> V_202 = 2 ;
}
if ( ! V_228 -> V_235 ) {
if ( V_228 -> V_236 ) {
if ( ! V_2 -> V_130 -> V_237 -> V_238 &&
V_1 -> V_24 -> V_82 ) {
V_19 = F_56 ( V_1 ) ;
if ( V_19 ) {
F_3 ( L_56
L_57 , V_1 ) ;
return V_19 ;
}
}
V_19 = F_22 ( V_1 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_94 ( V_1 ,
V_46 ) ;
if ( V_19 )
return V_19 ;
F_11 ( & V_1 -> V_145 ) ;
V_1 -> V_138 = V_181 ;
F_12 ( & V_1 -> V_145 ) ;
goto V_239;
}
V_19 = F_69 ( V_1 ) ;
if ( V_19 )
return V_19 ;
}
V_239:
V_19 = F_97 ( V_1 , V_206 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static void
F_105 ( struct V_1 * V_1 )
{
struct V_60 * V_61 = ( void * ) V_1 -> V_155 ;
int V_240 = V_1 -> V_241 ;
struct V_226 * V_2 = V_1 -> V_2 ;
struct V_227 * V_228 = V_2 -> V_242 ;
int V_243 ;
F_13 ( L_36 , V_1 ) ;
F_106 ( ! V_228 ) ;
if ( V_228 -> V_244 ) {
struct V_245 * V_246 =
(struct V_245 * ) & V_61 -> V_230 ;
V_228 -> V_247 = ( ! V_246 -> V_248 ) ? 1 : 0 ;
V_228 -> V_249 =
( V_246 -> V_219 & V_250 )
>> 2 ;
V_228 -> V_251 = V_246 -> V_252 ;
V_228 -> V_253 = V_246 -> V_254 ;
memcpy ( V_228 -> V_255 , V_246 -> V_255 , 6 ) ;
V_228 -> V_256 = F_107 ( V_246 -> V_257 ) ;
V_228 -> V_258 = V_246 -> V_259 ;
V_228 -> V_260 = F_107 ( V_246 -> V_261 ) ;
V_228 -> V_262 = F_108 ( V_246 -> V_262 ) ;
V_228 -> V_248 = F_108 ( V_246 -> V_248 ) ;
}
memcpy ( & V_228 -> V_263 [ 0 ] , ( void * ) & V_61 -> V_230 , V_264 ) ;
V_243 = V_27 ( V_240 , V_265 ) ;
F_9 ( L_58
L_59 , V_243 , V_240 ,
V_265 ) ;
memcpy ( V_228 -> V_266 , & V_61 -> V_267 [ 0 ] , V_243 ) ;
if ( V_228 -> V_244 ) {
F_89 ( & V_1 -> V_141 ) ;
return;
}
F_109 ( & V_2 -> V_268 , 0 ) ;
}
static struct V_269
* F_110 ( struct V_226 * V_2 , struct V_60 * V_61 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_216 * V_216 ;
struct V_269 * V_4 ;
V_4 = F_111 ( V_2 , V_270 ) ;
if ( ! V_4 ) {
F_3 ( L_60 ) ;
return NULL ;
}
V_216 = F_112 ( V_4 ) ;
V_216 -> V_2 = V_1 ;
V_216 -> V_269 = V_4 ;
V_216 -> V_61 = V_61 ;
return V_4 ;
}
static int
F_113 ( struct V_1 * V_1 ,
struct V_216 * V_216 , struct V_269 * V_4 ,
struct V_60 * V_61 , unsigned char * V_271 )
{
struct V_226 * V_2 = V_1 -> V_2 ;
struct V_272 * V_273 = (struct V_272 * ) V_271 ;
int V_274 , V_275 , V_276 , V_277 , V_278 ;
bool V_279 = false ;
unsigned int V_280 ;
V_278 = F_114 ( V_2 , V_4 , V_271 ) ;
if ( V_278 < 0 )
return V_278 ;
V_274 = V_4 -> V_281 ;
V_275 = V_4 -> V_282 ;
V_276 = V_4 -> V_283 ;
V_280 = V_4 -> V_3 . V_284 ;
if ( V_274 && V_275 == V_280 )
V_4 -> V_3 . V_285 |= V_286 ;
V_278 = F_115 ( V_2 , V_4 , V_273 ) ;
if ( V_278 < 0 ) {
return 0 ;
} else if ( V_278 > 0 ) {
V_279 = true ;
goto V_287;
}
if ( ! V_274 )
return 0 ;
if ( V_275 != V_280 ) {
V_277 = F_116 ( 1UL , F_117 ( V_275 , V_288 ) ) ;
F_118 ( V_4 -> V_3 . V_289 , V_277 ,
& V_61 -> V_267 [ 0 ] , V_275 ) ;
F_9 ( L_61 ,
V_277 , V_275 ) ;
} else {
F_119 ( & V_216 -> V_290 , 1 ) ;
V_4 -> V_3 . V_289 = & V_216 -> V_290 ;
V_4 -> V_3 . V_291 = 1 ;
F_120 ( & V_216 -> V_290 , & V_61 -> V_267 [ 0 ] , V_275 ) ;
F_9 ( L_62 ,
V_275 ) ;
}
V_4 -> V_292 += V_275 ;
if ( V_4 -> V_292 == V_4 -> V_3 . V_284 ) {
F_66 ( & V_4 -> V_293 ) ;
V_4 -> V_294 |= V_295 ;
V_4 -> V_296 = V_297 ;
F_67 ( & V_4 -> V_293 ) ;
}
V_287:
V_278 = F_121 ( V_2 , V_4 , V_271 , V_273 -> V_257 ) ;
if ( ! V_278 && V_279 == false && V_276 )
F_122 ( V_4 ) ;
else if ( V_279 && V_274 )
F_123 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_124 ( struct V_1 * V_1 ,
struct V_60 * V_61 , unsigned char * V_271 )
{
struct V_298 * V_299 ;
struct V_226 * V_2 = V_1 -> V_2 ;
struct V_269 * V_4 = NULL ;
struct V_300 * V_273 = (struct V_300 * ) V_271 ;
V_134 V_301 = F_125 ( V_273 -> V_302 ) ;
int V_278 , V_277 , V_303 , V_304 ;
V_278 = F_126 ( V_2 , V_271 , & V_4 ) ;
if ( V_278 < 0 )
return V_278 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_283 ) {
F_3 ( L_63 ) ;
F_127 () ;
return - 1 ;
}
F_9 ( L_64
L_65 ,
V_301 , V_4 -> V_292 ,
V_4 -> V_3 . V_284 ) ;
V_303 = V_4 -> V_292 / V_288 ;
V_299 = & V_4 -> V_3 . V_289 [ V_303 ] ;
V_277 = F_116 ( 1UL , F_117 ( V_301 , V_288 ) ) ;
V_304 = V_4 -> V_292 % V_288 ;
if ( V_304 ) {
F_3 ( L_66 ) ;
F_127 () ;
return - 1 ;
}
F_9 ( L_67
L_68 , V_299 , V_303 ,
V_277 , & V_61 -> V_267 [ 0 ] , V_301 ) ;
F_118 ( V_299 , V_277 , & V_61 -> V_267 [ 0 ] ,
V_301 ) ;
V_278 = F_128 ( V_4 , V_273 , false ) ;
if ( V_278 < 0 )
return V_278 ;
V_278 = F_96 ( V_1 , V_61 ) ;
if ( V_278 ) {
F_3 ( L_69 , V_278 ) ;
return V_278 ;
}
return 0 ;
}
static int
F_129 ( struct V_1 * V_1 , struct V_216 * V_216 ,
struct V_269 * V_4 , struct V_60 * V_61 ,
unsigned char * V_271 )
{
struct V_226 * V_2 = V_1 -> V_2 ;
struct V_305 * V_273 = (struct V_305 * ) V_271 ;
int V_278 ;
V_278 = F_130 ( V_2 , V_4 , V_273 ) ;
if ( V_278 < 0 )
return V_278 ;
return F_131 ( V_2 , V_4 , V_273 ) ;
}
static int
F_132 ( struct V_1 * V_1 , struct V_216 * V_216 ,
struct V_269 * V_4 , struct V_60 * V_61 ,
struct V_306 * V_273 )
{
struct V_226 * V_2 = V_1 -> V_2 ;
V_134 V_307 = F_125 ( V_273 -> V_302 ) ;
int V_278 ;
unsigned char * V_308 = NULL ;
V_278 = F_133 ( V_2 , V_4 , V_273 ) ;
if ( V_278 < 0 )
return V_278 ;
if ( V_307 ) {
V_308 = F_23 ( V_307 , V_67 ) ;
if ( ! V_308 ) {
F_3 ( L_70 ,
V_307 ) ;
return - V_76 ;
}
}
V_4 -> V_309 = V_308 ;
memcpy ( V_4 -> V_309 , & V_61 -> V_267 [ 0 ] , V_307 ) ;
return F_134 ( V_2 , V_4 , V_273 ) ;
}
static int
F_135 ( struct V_1 * V_1 , struct V_60 * V_61 ,
T_2 V_310 , T_3 V_311 ,
T_2 V_312 , T_3 V_313 )
{
struct V_232 * V_273 = & V_61 -> V_230 ;
struct V_226 * V_2 = V_1 -> V_2 ;
struct V_269 * V_4 ;
struct V_216 * V_216 ;
int V_19 = - V_314 ;
V_168 V_212 = ( V_273 -> V_212 & V_315 ) ;
if ( V_2 -> V_130 -> V_237 -> V_238 &&
( ! ( V_212 & V_316 ) || ! ( V_212 & V_317 ) ) ) {
F_3 ( L_71
L_72 , V_212 ) ;
return 0 ;
}
switch ( V_212 ) {
case V_318 :
V_4 = F_110 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_216 = F_112 ( V_4 ) ;
V_216 -> V_310 = V_310 ;
V_216 -> V_311 = V_311 ;
V_216 -> V_312 = V_312 ;
V_216 -> V_313 = V_313 ;
V_19 = F_113 ( V_1 , V_216 , V_4 ,
V_61 , ( unsigned char * ) V_273 ) ;
break;
case V_319 :
V_4 = F_110 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_216 = F_112 ( V_4 ) ;
V_19 = F_129 ( V_1 , V_216 , V_4 ,
V_61 , ( unsigned char * ) V_273 ) ;
break;
case V_320 :
V_19 = F_124 ( V_1 , V_61 ,
( unsigned char * ) V_273 ) ;
break;
case V_321 :
V_4 = F_110 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_19 = F_136 ( V_2 , V_4 ,
( unsigned char * ) V_273 ) ;
break;
case V_317 :
V_4 = F_110 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_19 = F_137 ( V_2 , V_4 , ( unsigned char * ) V_273 ) ;
break;
case V_316 :
if ( F_107 ( V_273 -> V_322 ) != 0xFFFFFFFF )
V_4 = F_138 ( V_2 , V_273 -> V_259 ) ;
else
V_4 = F_110 ( V_2 , V_61 ) ;
if ( ! V_4 )
break;
V_216 = F_112 ( V_4 ) ;
V_19 = F_132 ( V_1 , V_216 , V_4 ,
V_61 , (struct V_306 * ) V_273 ) ;
break;
default:
F_3 ( L_73 , V_212 ) ;
F_127 () ;
break;
}
return V_19 ;
}
static void
F_139 ( struct V_60 * V_61 , struct V_1 * V_1 )
{
struct V_218 * V_218 = & V_61 -> V_217 ;
T_3 V_311 = 0 , V_313 = 0 ;
T_2 V_310 = 0 , V_312 = 0 ;
switch ( V_218 -> V_219 & 0xF0 ) {
case V_323 :
if ( V_218 -> V_219 & V_324 ) {
V_310 = F_107 ( V_218 -> V_310 ) ;
V_311 = F_140 ( V_218 -> V_311 ) ;
F_9 ( L_74 ,
V_310 , ( unsigned long long ) V_311 ) ;
}
if ( V_218 -> V_219 & V_325 ) {
V_312 = F_107 ( V_218 -> V_312 ) ;
V_313 = F_140 ( V_218 -> V_313 ) ;
F_9 ( L_75 ,
V_312 , ( unsigned long long ) V_313 ) ;
}
F_9 ( L_76 ) ;
break;
case V_326 :
F_3 ( L_77 ) ;
break;
default:
F_6 ( L_78 , V_218 -> V_219 ) ;
break;
}
F_135 ( V_1 , V_61 ,
V_310 , V_311 , V_312 , V_313 ) ;
}
static void
F_141 ( struct V_60 * V_115 ,
struct V_1 * V_1 ,
V_134 V_327 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_232 * V_273 ;
T_1 V_328 ;
int V_240 ;
if ( ( char * ) V_115 == V_1 -> V_155 ) {
V_328 = V_1 -> V_152 ;
V_240 = V_150 ;
F_9 ( L_79 ,
V_328 , V_240 ) ;
} else {
V_328 = V_115 -> V_64 ;
V_240 = V_69 ;
F_9 ( L_80 ,
V_328 , V_240 ) ;
}
F_101 ( V_16 , V_328 , V_240 , V_70 ) ;
V_273 = & V_115 -> V_230 ;
F_9 ( L_81 ,
V_273 -> V_212 , V_273 -> V_259 , V_273 -> V_219 ,
( int ) ( V_327 - V_210 ) ) ;
if ( ( char * ) V_115 == V_1 -> V_155 ) {
V_1 -> V_241 = V_327 - V_210 ;
if ( V_1 -> V_2 ) {
struct V_227 * V_228 = V_1 -> V_2 -> V_242 ;
if ( V_228 && ! V_228 -> V_244 )
F_105 ( V_1 ) ;
}
F_11 ( & V_1 -> V_145 ) ;
F_89 ( & V_1 -> V_142 ) ;
F_12 ( & V_1 -> V_145 ) ;
} else {
F_139 ( V_115 , V_1 ) ;
}
F_98 ( V_16 , V_328 , V_240 ,
V_70 ) ;
V_1 -> V_204 -- ;
}
static int
F_142 ( struct V_1 * V_1 , struct V_216 * V_216 ,
struct V_298 * V_290 , V_134 V_329 , V_134 V_73 , V_134 V_330 ,
enum V_331 V_332 , struct V_333 * V_267 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
V_267 -> V_334 = V_332 == V_335 ?
V_151 : V_70 ;
V_267 -> V_336 = V_73 - V_330 ;
V_267 -> V_330 = V_330 ;
V_267 -> V_303 = V_267 -> V_330 / V_288 ;
V_267 -> V_290 = & V_290 [ V_267 -> V_303 ] ;
V_267 -> V_329 = F_33 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_267 -> V_336 = F_33 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_267 -> V_337 = F_143 ( V_16 , V_267 -> V_290 , V_267 -> V_329 ,
V_267 -> V_334 ) ;
if ( F_144 ( ! V_267 -> V_337 ) ) {
F_3 ( L_82 , V_290 ) ;
return - V_314 ;
}
F_9 ( L_83 ,
V_216 , V_267 -> V_337 , V_267 -> V_290 , V_267 -> V_329 , V_267 -> V_336 ) ;
return 0 ;
}
static void
F_145 ( struct V_1 * V_1 , struct V_333 * V_267 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
F_146 ( V_16 , V_267 -> V_290 , V_267 -> V_329 , V_267 -> V_334 ) ;
memset ( V_267 , 0 , sizeof( * V_267 ) ) ;
}
static void
V_100 ( struct V_216 * V_216 , struct V_1 * V_1 )
{
struct V_338 * V_339 = & V_216 -> V_221 ;
F_9 ( L_84 , V_216 ) ;
if ( V_339 -> V_267 . V_290 ) {
F_9 ( L_85 , V_216 ) ;
F_145 ( V_1 , & V_339 -> V_267 ) ;
}
if ( V_339 -> V_221 ) {
F_9 ( L_86 , V_216 ) ;
F_27 ( V_339 -> V_221 ) ;
V_339 -> V_221 = NULL ;
}
if ( V_339 -> V_62 ) {
F_9 ( L_87 , V_216 ) ;
F_27 ( V_339 -> V_62 ) ;
V_339 -> V_62 = NULL ;
}
}
static void
V_98 ( struct V_216 * V_216 , struct V_1 * V_1 )
{
struct V_338 * V_339 = & V_216 -> V_221 ;
F_9 ( L_84 , V_216 ) ;
if ( V_339 -> V_106 ) {
F_9 ( L_88 , V_216 , V_339 -> V_106 ) ;
if ( V_339 -> V_106 -> V_121 & V_126 ) {
F_145 ( V_1 , & V_339 -> V_340 ) ;
V_339 -> V_106 -> V_121 &= ~ V_126 ;
}
F_66 ( & V_1 -> V_146 ) ;
F_48 ( & V_339 -> V_106 -> V_109 , & V_1 -> V_108 ) ;
F_67 ( & V_1 -> V_146 ) ;
V_339 -> V_106 = NULL ;
}
if ( V_339 -> V_267 . V_290 ) {
F_9 ( L_85 , V_216 ) ;
F_145 ( V_1 , & V_339 -> V_267 ) ;
}
V_339 -> V_62 = NULL ;
V_339 -> V_221 = NULL ;
}
static void
F_147 ( struct V_216 * V_216 , bool V_341 )
{
struct V_269 * V_4 = V_216 -> V_269 ;
struct V_1 * V_1 = V_216 -> V_2 ;
struct V_226 * V_2 = V_1 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_342 * V_273 ;
F_9 ( L_84 , V_216 ) ;
switch ( V_4 -> V_343 ) {
case V_318 :
F_66 ( & V_2 -> V_344 ) ;
if ( ! F_50 ( & V_4 -> V_345 ) )
F_90 ( & V_4 -> V_345 ) ;
F_67 ( & V_2 -> V_344 ) ;
if ( V_4 -> V_346 == V_151 ) {
F_148 ( V_4 ) ;
if ( V_341 &&
V_4 -> V_3 . V_347 == V_348 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_123 ( V_3 ) ;
}
}
V_24 -> V_97 ( V_216 , V_1 ) ;
F_149 ( & V_4 -> V_3 , 0 ) ;
break;
case V_321 :
F_66 ( & V_2 -> V_344 ) ;
if ( ! F_50 ( & V_4 -> V_345 ) )
F_90 ( & V_4 -> V_345 ) ;
F_67 ( & V_2 -> V_344 ) ;
F_149 ( & V_4 -> V_3 , 0 ) ;
break;
case V_349 :
case V_319 :
case V_316 :
V_273 = (struct V_342 * ) & V_216 -> V_206 . V_230 ;
if ( V_273 -> V_219 & V_350 )
break;
F_66 ( & V_2 -> V_344 ) ;
if ( ! F_50 ( & V_4 -> V_345 ) )
F_90 ( & V_4 -> V_345 ) ;
F_67 ( & V_2 -> V_344 ) ;
if ( V_4 -> V_3 . V_351 != NULL ) {
F_9 ( L_89 ,
V_4 -> V_343 ) ;
F_149 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_150 ( V_4 ) ;
break;
}
}
static void
F_151 ( struct V_205 * V_206 , struct V_15 * V_16 )
{
if ( V_206 -> V_64 != 0 ) {
F_9 ( L_90 ) ;
F_26 ( V_16 , V_206 -> V_64 ,
V_210 , V_151 ) ;
V_206 -> V_64 = 0 ;
}
}
static void
F_152 ( struct V_205 * V_206 , struct V_216 * V_216 ,
struct V_15 * V_16 , bool V_341 )
{
if ( V_216 -> V_352 != 0 ) {
F_9 ( L_91 ) ;
F_26 ( V_16 , V_216 -> V_352 ,
V_216 -> V_353 , V_151 ) ;
V_216 -> V_352 = 0 ;
}
F_151 ( V_206 , V_16 ) ;
F_147 ( V_216 , V_341 ) ;
}
static int
F_153 ( struct V_3 * V_3 , struct V_354 * V_113 )
{
struct V_355 V_356 ;
int V_19 ;
V_19 = F_154 ( V_113 , V_357 , & V_356 ) ;
if ( V_19 ) {
F_3 ( L_92 , V_19 ) ;
goto V_358;
}
if ( V_356 . V_359 & V_357 ) {
T_1 V_360 ;
V_134 V_361 = V_3 -> V_362 -> V_363 . V_361 + 8 ;
switch ( V_356 . V_364 . V_365 ) {
case V_366 :
V_3 -> V_367 = V_368 ;
break;
case V_369 :
V_3 -> V_367 = V_370 ;
break;
case V_371 :
V_3 -> V_367 = V_372 ;
break;
}
V_360 = V_356 . V_364 . V_373 ;
F_155 ( V_360 , V_361 ) ;
V_3 -> V_374 = V_360 + V_3 -> V_375 ;
F_3 ( L_93
L_94 ,
V_356 . V_364 . V_365 ,
( unsigned long long ) V_3 -> V_374 ,
V_356 . V_364 . V_376 ,
V_356 . V_364 . V_377 ) ;
V_19 = 1 ;
}
V_358:
return V_19 ;
}
static void
F_156 ( struct V_205 * V_206 ,
struct V_216 * V_216 )
{
struct V_338 * V_339 = & V_216 -> V_221 ;
struct V_269 * V_4 = V_216 -> V_269 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_216 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_339 -> V_106 && V_339 -> V_106 -> V_121 & V_126 ) {
V_19 = F_153 ( V_3 ,
V_339 -> V_106 -> V_111 -> V_113 ) ;
V_339 -> V_106 -> V_121 &= ~ V_126 ;
}
V_24 -> V_97 ( V_216 , V_1 ) ;
V_339 -> V_378 = 0 ;
if ( V_19 )
F_157 ( V_3 ,
V_3 -> V_367 , 0 ) ;
else
F_158 ( V_1 -> V_2 , V_4 ) ;
}
static void
F_159 ( struct V_205 * V_206 ,
struct V_216 * V_216 )
{
struct V_338 * V_339 = & V_216 -> V_221 ;
struct V_269 * V_4 = V_216 -> V_269 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_216 -> V_2 ;
struct V_23 * V_24 = V_1 -> V_24 ;
int V_19 = 0 ;
if ( V_339 -> V_106 && V_339 -> V_106 -> V_121 & V_126 ) {
V_19 = F_153 ( V_3 ,
V_339 -> V_106 -> V_111 -> V_113 ) ;
V_339 -> V_106 -> V_121 &= ~ V_126 ;
}
F_148 ( V_4 ) ;
V_24 -> V_97 ( V_216 , V_1 ) ;
V_4 -> V_292 = V_339 -> V_267 . V_336 ;
V_339 -> V_378 = 0 ;
F_9 ( L_95 , V_216 ) ;
F_66 ( & V_4 -> V_293 ) ;
V_4 -> V_294 |= V_295 ;
V_4 -> V_296 = V_297 ;
F_67 ( & V_4 -> V_293 ) ;
if ( V_19 ) {
F_123 ( V_3 ) ;
F_157 ( V_3 ,
V_3 -> V_367 , 0 ) ;
} else {
F_160 ( V_3 ) ;
}
}
static void
F_161 ( struct V_379 * V_77 )
{
struct V_216 * V_216 = F_80 ( V_77 ,
struct V_216 , V_380 ) ;
struct V_1 * V_1 = V_216 -> V_2 ;
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_269 * V_4 = V_216 -> V_269 ;
F_9 ( L_96 , V_216 , V_4 -> V_296 ) ;
switch ( V_4 -> V_296 ) {
case V_381 :
F_162 ( V_4 , V_4 -> V_2 ) ;
case V_382 :
case V_383 :
V_4 -> V_296 = V_384 ;
F_152 ( & V_216 -> V_206 , V_216 ,
V_16 , false ) ;
break;
case V_385 :
F_163 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_97 , V_4 -> V_296 ) ;
F_127 () ;
break;
}
}
static void
F_164 ( struct V_205 * V_206 ,
struct V_216 * V_216 ,
struct V_1 * V_1 ,
struct V_15 * V_16 )
{
struct V_269 * V_4 = V_216 -> V_269 ;
if ( V_4 -> V_296 == V_381 ||
V_4 -> V_296 == V_385 ||
V_4 -> V_296 == V_382 ||
V_4 -> V_296 == V_383 ) {
F_151 ( V_206 , V_16 ) ;
F_36 ( & V_216 -> V_380 , F_161 ) ;
F_91 ( V_386 , & V_216 -> V_380 ) ;
return;
}
V_4 -> V_296 = V_384 ;
F_152 ( V_206 , V_216 , V_16 , false ) ;
}
static void
F_165 ( struct V_205 * V_206 ,
struct V_1 * V_1 )
{
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_216 * V_216 = V_206 -> V_216 ;
struct V_338 * V_339 ;
if ( ! V_216 ) {
F_151 ( V_206 , V_16 ) ;
return;
}
V_339 = & V_216 -> V_221 ;
F_9 ( L_98 , V_216 , V_339 -> V_222 ) ;
switch ( V_339 -> V_222 ) {
case V_223 :
F_164 ( V_206 , V_216 ,
V_1 , V_16 ) ;
break;
case V_335 :
F_156 ( V_206 , V_216 ) ;
break;
case V_387 :
F_159 ( V_206 , V_216 ) ;
break;
default:
F_3 ( L_99 , V_339 -> V_222 ) ;
F_127 () ;
break;
}
}
static inline bool
F_166 ( struct V_1 * V_1 , void * V_199 )
{
void * V_388 = V_1 -> V_66 ;
int V_336 = V_46 * sizeof( * V_1 -> V_66 ) ;
if ( V_199 >= V_388 && V_199 < V_388 + V_336 )
return false ;
return true ;
}
static void
F_167 ( struct V_1 * V_1 , struct V_389 * V_390 )
{
if ( V_390 -> V_199 == V_391 ) {
F_13 ( L_100 ,
V_1 ) ;
F_89 ( & V_1 -> V_392 ) ;
} else if ( F_166 ( V_1 , ( void * ) ( V_200 ) V_390 -> V_199 ) ) {
struct V_15 * V_16 = V_1 -> V_13 -> V_24 ;
struct V_216 * V_216 ;
struct V_205 * V_115 ;
V_115 = (struct V_205 * ) ( V_200 ) V_390 -> V_199 ;
V_216 = V_115 -> V_216 ;
if ( ! V_216 )
F_151 ( V_115 , V_16 ) ;
else
F_152 ( V_115 , V_216 , V_16 , true ) ;
} else {
V_1 -> V_204 -- ;
if ( ! V_1 -> V_204 )
F_168 ( V_1 -> V_2 , 0 ) ;
}
}
static void
F_169 ( struct V_389 * V_390 )
{
struct V_1 * V_1 ;
struct V_205 * V_206 ;
struct V_60 * V_61 ;
V_1 = V_390 -> V_58 -> V_38 ;
if ( F_170 ( V_390 -> V_187 == V_393 ) ) {
if ( V_390 -> V_212 == V_394 ) {
V_61 = (struct V_60 * ) ( V_200 ) V_390 -> V_199 ;
F_141 ( V_61 , V_1 , V_390 -> V_395 ) ;
} else {
V_206 = (struct V_205 * ) ( V_200 ) V_390 -> V_199 ;
F_165 ( V_206 , V_1 ) ;
}
} else {
if ( V_390 -> V_187 != V_396 )
F_3 ( L_101 ,
F_171 ( V_390 -> V_187 ) , V_390 -> V_187 ,
V_390 -> V_199 , V_390 -> V_397 ) ;
else
F_9 ( L_102 ,
F_171 ( V_390 -> V_187 ) , V_390 -> V_187 ,
V_390 -> V_199 ) ;
if ( V_390 -> V_199 != V_398 )
F_167 ( V_1 , V_390 ) ;
}
}
static void
V_86 ( struct V_379 * V_77 )
{
enum { V_399 = 65536 };
struct V_22 * V_25 = F_80 ( V_77 , struct V_22 ,
V_77 ) ;
struct V_389 * const V_400 = V_25 -> V_400 ;
int V_26 , V_401 , V_402 = 0 ;
while ( ( V_401 = F_172 ( V_25 -> V_40 , F_173 ( V_25 -> V_400 ) , V_400 ) ) > 0 ) {
for ( V_26 = 0 ; V_26 < V_401 ; V_26 ++ )
F_169 ( & V_400 [ V_26 ] ) ;
V_402 += V_401 ;
if ( V_402 >= V_399 )
break;
}
F_38 ( V_25 -> V_40 , V_91 ) ;
}
static void
V_89 ( struct V_403 * V_40 , void * V_10 )
{
struct V_22 * V_25 = V_10 ;
F_91 ( V_386 , & V_25 -> V_77 ) ;
}
static int
F_174 ( struct V_1 * V_1 , struct V_216 * V_216 )
{
struct V_207 * V_404 ;
int V_19 ;
V_19 = F_96 ( V_1 , V_216 -> V_61 ) ;
if ( V_19 ) {
F_3 ( L_69 , V_19 ) ;
return V_19 ;
}
V_19 = F_99 ( V_1 -> V_58 , & V_216 -> V_206 . V_208 ,
& V_404 ) ;
if ( V_19 ) {
F_3 ( L_103 , V_19 ) ;
return V_19 ;
}
return V_19 ;
}
static int
F_158 ( struct V_226 * V_2 , struct V_269 * V_4 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_207 * V_208 = & V_216 -> V_206 . V_208 ;
struct V_405 * V_273 = (struct V_405 * )
& V_216 -> V_206 . V_230 ;
F_100 ( V_1 , V_216 , & V_216 -> V_206 ) ;
F_175 ( V_4 , V_2 , true , V_273 ) ;
F_102 ( V_1 , & V_216 -> V_206 ) ;
if ( V_4 -> V_3 . V_406 &&
( ( V_4 -> V_3 . V_285 & V_407 ) ||
( V_4 -> V_3 . V_285 & V_408 ) ) ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_233 = & V_216 -> V_206 . V_211 [ 1 ] ;
V_134 V_409 , V_410 ;
F_176 ( V_4 -> V_3 . V_411 ,
V_4 -> V_406 ) ;
V_4 -> V_3 . V_411 += sizeof( V_412 ) ;
V_409 = - ( V_4 -> V_3 . V_411 ) & 3 ;
F_177 ( V_273 -> V_302 , ( V_134 ) V_4 -> V_3 . V_411 ) ;
V_410 = V_4 -> V_3 . V_411 + V_409 ;
V_216 -> V_352 = F_24 ( V_16 ,
( void * ) V_4 -> V_406 , V_410 ,
V_151 ) ;
V_216 -> V_353 = V_410 ;
V_233 -> V_72 = V_216 -> V_352 ;
V_233 -> V_73 = V_410 ;
V_233 -> V_74 = V_24 -> V_57 -> V_75 ;
V_216 -> V_206 . V_202 = 2 ;
}
F_103 ( V_1 , V_216 , V_208 ) ;
F_9 ( L_104 ) ;
return F_174 ( V_1 , V_216 ) ;
}
static void
F_178 ( struct V_226 * V_2 , struct V_269 * V_4 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
F_66 ( & V_2 -> V_344 ) ;
if ( ! F_50 ( & V_4 -> V_345 ) )
F_90 ( & V_4 -> V_345 ) ;
F_67 ( & V_2 -> V_344 ) ;
if ( V_4 -> V_346 == V_151 )
F_148 ( V_4 ) ;
V_24 -> V_97 ( V_216 , V_1 ) ;
}
static enum V_413
F_179 ( struct V_226 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
if ( V_2 -> V_414 -> V_415 . V_416 ) {
if ( V_24 -> V_54 ) {
F_13 ( L_105 , V_1 ) ;
V_1 -> V_5 = true ;
return V_417 ;
}
}
F_13 ( L_106 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_180 ( struct V_269 * V_4 , struct V_226 * V_2 ,
bool V_418 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_207 * V_208 = & V_216 -> V_206 . V_208 ;
F_100 ( V_1 , V_216 , & V_216 -> V_206 ) ;
F_181 ( V_4 , V_2 , (struct V_419 * )
& V_216 -> V_206 . V_230 ,
V_418 ) ;
F_102 ( V_1 , & V_216 -> V_206 ) ;
F_103 ( V_1 , V_216 , V_208 ) ;
F_9 ( L_107 , V_1 ) ;
return F_174 ( V_1 , V_216 ) ;
}
static int
F_182 ( struct V_269 * V_4 , struct V_226 * V_2 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_207 * V_208 = & V_216 -> V_206 . V_208 ;
F_100 ( V_1 , V_216 , & V_216 -> V_206 ) ;
F_183 ( V_4 , V_2 , (struct V_420 * )
& V_216 -> V_206 . V_230 ) ;
F_102 ( V_1 , & V_216 -> V_206 ) ;
F_103 ( V_1 , V_216 , V_208 ) ;
F_9 ( L_108 , V_1 ) ;
return F_174 ( V_1 , V_216 ) ;
}
static int
F_184 ( struct V_269 * V_4 , struct V_226 * V_2 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_207 * V_208 = & V_216 -> V_206 . V_208 ;
F_100 ( V_1 , V_216 , & V_216 -> V_206 ) ;
F_185 ( V_4 , V_2 , (struct V_421 * )
& V_216 -> V_206 . V_230 ) ;
F_102 ( V_1 , & V_216 -> V_206 ) ;
F_103 ( V_1 , V_216 , V_208 ) ;
F_9 ( L_109 , V_1 ) ;
return F_174 ( V_1 , V_216 ) ;
}
static int
F_186 ( struct V_269 * V_4 , struct V_226 * V_2 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_207 * V_208 = & V_216 -> V_206 . V_208 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_233 = & V_216 -> V_206 . V_211 [ 1 ] ;
struct V_422 * V_273 =
(struct V_422 * ) & V_216 -> V_206 . V_230 ;
F_100 ( V_1 , V_216 , & V_216 -> V_206 ) ;
F_187 ( V_4 , V_2 , V_273 ) ;
F_102 ( V_1 , & V_216 -> V_206 ) ;
F_177 ( V_273 -> V_302 , V_264 ) ;
V_216 -> V_352 = F_24 ( V_16 ,
( void * ) V_4 -> V_423 , V_264 ,
V_151 ) ;
V_216 -> V_353 = V_264 ;
V_233 -> V_72 = V_216 -> V_352 ;
V_233 -> V_73 = V_264 ;
V_233 -> V_74 = V_24 -> V_57 -> V_75 ;
V_216 -> V_206 . V_202 = 2 ;
F_103 ( V_1 , V_216 , V_208 ) ;
F_9 ( L_110 , V_1 ) ;
return F_174 ( V_1 , V_216 ) ;
}
static int
F_188 ( struct V_269 * V_4 , struct V_226 * V_2 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_207 * V_208 = & V_216 -> V_206 . V_208 ;
struct V_342 * V_273 =
(struct V_342 * ) & V_216 -> V_206 . V_230 ;
V_134 V_424 ;
int V_278 ;
F_100 ( V_1 , V_216 , & V_216 -> V_206 ) ;
V_278 = F_189 ( V_4 , V_2 , V_273 , V_425 ) ;
if ( V_278 < 0 )
return V_278 ;
V_424 = V_278 ;
F_102 ( V_1 , & V_216 -> V_206 ) ;
if ( V_424 ) {
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_62 * V_233 = & V_216 -> V_206 . V_211 [ 1 ] ;
void * V_426 = V_4 -> V_423 ;
V_216 -> V_352 = F_24 ( V_16 ,
V_426 , V_424 , V_151 ) ;
V_216 -> V_353 = V_424 ;
V_233 -> V_72 = V_216 -> V_352 ;
V_233 -> V_73 = V_424 ;
V_233 -> V_74 = V_24 -> V_57 -> V_75 ;
V_216 -> V_206 . V_202 = 2 ;
}
F_103 ( V_1 , V_216 , V_208 ) ;
F_9 ( L_111 , V_1 ) ;
return F_174 ( V_1 , V_216 ) ;
}
static int
F_190 ( struct V_1 * V_1 , struct V_216 * V_216 ,
struct V_62 * V_62 , struct V_427 * V_221 ,
V_134 V_428 , V_134 V_330 )
{
struct V_269 * V_4 = V_216 -> V_269 ;
struct V_298 * V_299 , * V_429 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
V_134 V_303 , V_304 ;
int V_26 = 0 , V_277 ;
V_303 = V_330 / V_288 ;
V_299 = & V_4 -> V_3 . V_289 [ V_303 ] ;
V_277 = V_27 ( V_4 -> V_3 . V_291 - V_303 , V_1 -> V_20 ) ;
V_304 = V_330 % V_288 ;
V_221 -> V_339 . V_201 = V_62 ;
V_221 -> V_339 . V_199 = ( V_200 ) & V_216 -> V_206 ;
F_191 (sg_start, tmp_sg, sg_nents, i) {
F_9 ( L_112
L_113 ,
( unsigned long long ) V_429 -> V_430 ,
V_429 -> V_73 , V_304 ) ;
V_62 -> V_72 = F_192 ( V_16 , V_429 ) + V_304 ;
V_62 -> V_73 = F_33 ( V_134 , V_428 ,
F_193 ( V_16 , V_429 ) - V_304 ) ;
V_62 -> V_74 = V_24 -> V_57 -> V_75 ;
F_9 ( L_114 ,
V_62 -> V_72 , V_62 -> V_73 , V_62 -> V_74 ) ;
V_304 = 0 ;
V_428 -= V_62 -> V_73 ;
if ( ! V_428 )
break;
V_62 ++ ;
F_9 ( L_115 , V_62 ) ;
}
V_221 -> V_339 . V_202 = ++ V_26 ;
F_9 ( L_116 ,
V_221 -> V_339 . V_201 , V_221 -> V_339 . V_202 ) ;
return V_221 -> V_339 . V_202 ;
}
static int
V_99 ( struct V_226 * V_2 , struct V_269 * V_4 ,
struct V_338 * V_339 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_333 * V_267 = & V_339 -> V_267 ;
struct V_427 * V_221 ;
struct V_62 * V_62 ;
V_134 V_330 , V_280 , V_428 , V_431 , V_432 = 0 ;
int V_19 = 0 , V_26 , V_433 ;
V_216 -> V_206 . V_216 = V_216 ;
V_330 = V_339 -> V_222 == V_387 ? V_4 -> V_292 : 0 ;
V_19 = F_142 ( V_1 , V_216 , V_3 -> V_289 ,
V_3 -> V_291 , V_3 -> V_284 ,
V_330 , V_339 -> V_222 , & V_339 -> V_267 ) ;
if ( V_19 )
return V_19 ;
V_428 = V_267 -> V_336 ;
V_330 = V_267 -> V_330 ;
V_62 = F_23 ( sizeof( struct V_62 ) * V_267 -> V_329 , V_67 ) ;
if ( ! V_62 ) {
F_6 ( L_117 ) ;
V_19 = - V_76 ;
goto V_434;
}
V_339 -> V_62 = V_62 ;
V_339 -> V_378 = F_117 ( V_267 -> V_329 , V_1 -> V_20 ) ;
V_339 -> V_221 = F_23 ( sizeof( struct V_427 ) * V_339 -> V_378 ,
V_67 ) ;
if ( ! V_339 -> V_221 ) {
F_9 ( L_118 ) ;
V_19 = - V_76 ;
goto V_434;
}
V_339 -> V_216 = V_216 ;
V_431 = V_1 -> V_20 * V_288 ;
for ( V_26 = 0 ; V_26 < V_339 -> V_378 ; V_26 ++ ) {
V_221 = & V_216 -> V_221 . V_221 [ V_26 ] ;
V_280 = V_27 ( V_428 , V_431 ) ;
V_221 -> V_339 . V_214 = 0 ;
if ( V_339 -> V_222 == V_335 ) {
V_221 -> V_339 . V_212 = V_435 ;
V_221 -> V_436 = V_216 -> V_311 + V_330 ;
V_221 -> V_437 = V_216 -> V_310 ;
if ( V_26 + 1 == V_339 -> V_378 )
V_221 -> V_339 . V_203 = & V_216 -> V_206 . V_208 ;
else
V_221 -> V_339 . V_203 = & V_339 -> V_221 [ V_26 + 1 ] . V_339 ;
} else {
V_221 -> V_339 . V_212 = V_438 ;
V_221 -> V_436 = V_216 -> V_313 + V_432 ;
V_221 -> V_437 = V_216 -> V_312 ;
if ( V_26 + 1 == V_339 -> V_378 )
V_221 -> V_339 . V_214 = V_215 ;
else
V_221 -> V_339 . V_203 = & V_339 -> V_221 [ V_26 + 1 ] . V_339 ;
}
V_433 = F_190 ( V_1 , V_216 , V_62 ,
V_221 , V_280 , V_330 ) ;
V_62 += V_433 ;
V_330 += V_280 ;
V_432 += V_280 ;
V_428 -= V_280 ;
}
return 0 ;
V_434:
F_145 ( V_1 , V_267 ) ;
return V_19 ;
}
static inline void
F_194 ( struct V_207 * V_439 , struct V_354 * V_440 )
{
V_134 V_437 ;
memset ( V_439 , 0 , sizeof( * V_439 ) ) ;
V_439 -> V_199 = V_398 ;
V_439 -> V_212 = V_441 ;
V_439 -> V_442 . V_443 = V_440 -> V_437 ;
V_437 = F_195 ( V_440 -> V_437 ) ;
F_196 ( V_440 , V_437 ) ;
}
static int
F_197 ( struct V_1 * V_1 ,
struct V_105 * V_106 ,
struct V_333 * V_444 ,
enum V_445 V_121 ,
struct V_62 * V_225 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_15 * V_16 = V_24 -> V_15 ;
struct V_354 * V_440 ;
struct V_446 V_447 ;
struct V_207 V_439 , * V_448 , * V_339 = NULL ;
int V_19 , V_401 ;
if ( V_444 -> V_337 == 1 ) {
V_225 -> V_74 = V_24 -> V_57 -> V_75 ;
V_225 -> V_72 = F_192 ( V_16 , & V_444 -> V_290 [ 0 ] ) ;
V_225 -> V_73 = F_193 ( V_16 , & V_444 -> V_290 [ 0 ] ) ;
F_9 ( L_119 ,
V_225 -> V_72 , V_225 -> V_73 , V_225 -> V_74 ) ;
return 0 ;
}
if ( V_121 == V_127 )
V_440 = V_106 -> V_110 ;
else
V_440 = V_106 -> V_111 -> V_112 ;
if ( ! ( V_106 -> V_121 & V_121 ) ) {
F_194 ( & V_439 , V_440 ) ;
V_339 = & V_439 ;
}
V_401 = F_198 ( V_440 , V_444 -> V_290 , V_444 -> V_329 , V_288 ) ;
if ( F_144 ( V_401 != V_444 -> V_329 ) ) {
F_3 ( L_120 ,
V_401 , V_444 -> V_329 ) ;
return V_401 < 0 ? V_401 : - V_314 ;
}
F_9 ( L_121 ,
V_106 , V_444 -> V_329 , V_444 -> V_330 ) ;
V_447 . V_339 . V_203 = NULL ;
V_447 . V_339 . V_212 = V_449 ;
V_447 . V_339 . V_199 = V_398 ;
V_447 . V_339 . V_214 = 0 ;
V_447 . V_339 . V_202 = 0 ;
V_447 . V_440 = V_440 ;
V_447 . V_450 = V_440 -> V_74 ;
V_447 . V_451 = V_452 ;
if ( ! V_339 )
V_339 = & V_447 . V_339 ;
else
V_339 -> V_203 = & V_447 . V_339 ;
V_19 = F_99 ( V_1 -> V_58 , V_339 , & V_448 ) ;
if ( V_19 ) {
F_3 ( L_122 , V_19 ) ;
return V_19 ;
}
V_106 -> V_121 &= ~ V_121 ;
V_225 -> V_74 = V_440 -> V_74 ;
V_225 -> V_72 = V_440 -> V_453 ;
V_225 -> V_73 = V_440 -> V_73 ;
F_9 ( L_119 ,
V_225 -> V_72 , V_225 -> V_73 , V_225 -> V_74 ) ;
return V_19 ;
}
static inline void
F_199 ( struct V_3 * V_3 , struct V_454 * V_455 ,
struct V_456 * V_457 )
{
V_457 -> V_458 = V_459 ;
V_457 -> V_460 . V_461 . V_462 = V_463 ;
V_457 -> V_460 . V_461 . V_464 = V_3 -> V_362 -> V_363 . V_361 ;
V_457 -> V_460 . V_461 . V_465 = V_3 -> V_466 ;
V_457 -> V_460 . V_461 . V_467 = 0xffff ;
V_457 -> V_460 . V_461 . V_468 = true ;
V_457 -> V_460 . V_461 . V_469 = true ;
if ( V_3 -> V_470 == V_471 ||
V_3 -> V_470 == V_472 )
V_457 -> V_460 . V_461 . V_473 = true ;
}
static int
F_200 ( struct V_3 * V_3 , struct V_454 * V_455 )
{
switch ( V_3 -> V_6 ) {
case V_474 :
case V_475 :
V_455 -> V_444 . V_458 = V_476 ;
F_199 ( V_3 , V_455 , & V_455 -> V_477 ) ;
break;
case V_478 :
case V_479 :
V_455 -> V_477 . V_458 = V_476 ;
F_199 ( V_3 , V_455 , & V_455 -> V_444 ) ;
break;
case V_480 :
case V_481 :
F_199 ( V_3 , V_455 , & V_455 -> V_477 ) ;
F_199 ( V_3 , V_455 , & V_455 -> V_444 ) ;
break;
default:
F_3 ( L_123 , V_3 -> V_6 ) ;
return - V_314 ;
}
return 0 ;
}
static inline V_168
F_201 ( V_168 V_482 )
{
return ( V_482 & V_483 ? 0xc0 : 0 ) |
( V_482 & V_484 ? 0x30 : 0 ) |
( V_482 & V_484 ? 0x0f : 0 ) ;
}
static int
F_202 ( struct V_1 * V_1 ,
struct V_3 * V_3 ,
struct V_338 * V_221 ,
struct V_105 * V_106 )
{
struct V_485 V_486 ;
struct V_207 V_439 , * V_448 , * V_339 = NULL ;
struct V_117 * V_111 = V_106 -> V_111 ;
struct V_454 V_455 ;
int V_19 ;
memset ( & V_455 , 0 , sizeof( V_455 ) ) ;
V_19 = F_200 ( V_3 , & V_455 ) ;
if ( V_19 )
goto V_59;
V_455 . V_487 = F_201 ( V_3 -> V_482 ) ;
if ( ! ( V_106 -> V_121 & V_125 ) ) {
F_194 ( & V_439 , V_111 -> V_113 ) ;
V_339 = & V_439 ;
}
memset ( & V_486 , 0 , sizeof( V_486 ) ) ;
V_486 . V_339 . V_212 = V_488 ;
V_486 . V_339 . V_199 = V_398 ;
V_486 . V_339 . V_201 = & V_221 -> V_489 [ V_490 ] ;
V_486 . V_339 . V_202 = 1 ;
V_486 . V_491 = V_452 ;
V_486 . V_455 = & V_455 ;
V_486 . V_113 = V_111 -> V_113 ;
if ( V_3 -> V_492 )
V_486 . V_340 = & V_221 -> V_489 [ V_493 ] ;
if ( ! V_339 )
V_339 = & V_486 . V_339 ;
else
V_339 -> V_203 = & V_486 . V_339 ;
V_19 = F_99 ( V_1 -> V_58 , V_339 , & V_448 ) ;
if ( V_19 ) {
F_3 ( L_122 , V_19 ) ;
goto V_59;
}
V_106 -> V_121 &= ~ V_125 ;
V_221 -> V_489 [ V_494 ] . V_74 = V_111 -> V_113 -> V_74 ;
V_221 -> V_489 [ V_494 ] . V_72 = 0 ;
V_221 -> V_489 [ V_494 ] . V_73 = V_3 -> V_284 ;
if ( V_3 -> V_6 != V_479 &&
V_3 -> V_6 != V_478 )
V_221 -> V_489 [ V_494 ] . V_73 += V_3 -> V_495 ;
F_9 ( L_124 ,
V_221 -> V_489 [ V_494 ] . V_72 , V_221 -> V_489 [ V_494 ] . V_73 ,
V_221 -> V_489 [ V_494 ] . V_74 ) ;
V_59:
return V_19 ;
}
static int
F_203 ( struct V_1 * V_1 ,
struct V_216 * V_216 ,
struct V_338 * V_339 )
{
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_3 * V_3 = & V_216 -> V_269 -> V_3 ;
int V_19 ;
if ( ! V_339 -> V_106 -> V_111 ) {
V_19 = F_53 ( V_339 -> V_106 ,
V_24 -> V_15 ,
V_24 -> V_57 ) ;
if ( V_19 ) {
F_3 ( L_125 ,
V_1 ) ;
return V_19 ;
}
}
if ( V_3 -> V_492 ) {
V_19 = F_142 ( V_1 , V_216 ,
V_3 -> V_492 ,
V_3 -> V_496 ,
V_3 -> V_495 ,
0 , V_339 -> V_222 , & V_339 -> V_340 ) ;
if ( V_19 ) {
F_3 ( L_126 ,
V_1 ) ;
return V_19 ;
}
memset ( & V_339 -> V_489 [ V_493 ] , 0 , sizeof( V_339 -> V_489 [ V_493 ] ) ) ;
V_19 = F_197 ( V_1 , V_339 -> V_106 , & V_339 -> V_340 ,
V_122 , & V_339 -> V_489 [ V_493 ] ) ;
if ( V_19 ) {
F_3 ( L_127 ,
V_1 ) ;
goto V_497;
}
}
V_19 = F_202 ( V_1 , V_3 , V_339 , V_339 -> V_106 ) ;
if ( V_19 ) {
F_3 ( L_127 ,
V_1 ) ;
goto V_497;
}
V_339 -> V_106 -> V_121 |= V_126 ;
return 0 ;
V_497:
if ( V_3 -> V_492 )
F_145 ( V_1 , & V_339 -> V_340 ) ;
return V_19 ;
}
static int
V_96 ( struct V_226 * V_2 , struct V_269 * V_4 ,
struct V_338 * V_339 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_105 * V_106 = NULL ;
struct V_427 * V_221 ;
struct V_62 * V_489 ;
V_134 V_330 ;
int V_19 = 0 ;
unsigned long V_219 ;
V_216 -> V_206 . V_216 = V_216 ;
V_330 = V_339 -> V_222 == V_387 ? V_4 -> V_292 : 0 ;
V_19 = F_142 ( V_1 , V_216 , V_3 -> V_289 ,
V_3 -> V_291 , V_3 -> V_284 ,
V_330 , V_339 -> V_222 , & V_339 -> V_267 ) ;
if ( V_19 )
return V_19 ;
if ( V_339 -> V_267 . V_337 != 1 || F_1 ( V_1 , V_3 ) ) {
F_204 ( & V_1 -> V_146 , V_219 ) ;
V_106 = F_205 ( & V_1 -> V_108 ,
struct V_105 , V_109 ) ;
F_44 ( & V_106 -> V_109 ) ;
F_206 ( & V_1 -> V_146 , V_219 ) ;
V_339 -> V_106 = V_106 ;
}
V_19 = F_197 ( V_1 , V_106 , & V_339 -> V_267 ,
V_127 , & V_339 -> V_489 [ V_490 ] ) ;
if ( V_19 )
goto V_434;
if ( F_1 ( V_1 , V_3 ) ) {
V_19 = F_203 ( V_1 , V_216 , V_339 ) ;
if ( V_19 )
goto V_434;
V_489 = & V_339 -> V_489 [ V_494 ] ;
} else {
V_489 = & V_339 -> V_489 [ V_490 ] ;
}
memcpy ( & V_339 -> V_498 , V_489 , sizeof( * V_489 ) ) ;
V_339 -> V_62 = & V_339 -> V_498 ;
V_339 -> V_378 = 1 ;
memset ( & V_339 -> V_499 , 0 , sizeof( V_339 -> V_499 ) ) ;
V_339 -> V_221 = & V_339 -> V_499 ;
V_339 -> V_216 = V_216 ;
V_221 = & V_216 -> V_221 . V_499 ;
V_221 -> V_339 . V_201 = & V_339 -> V_498 ;
V_221 -> V_339 . V_202 = 1 ;
V_221 -> V_339 . V_199 = ( V_200 ) & V_216 -> V_206 ;
if ( V_339 -> V_222 == V_335 ) {
V_221 -> V_339 . V_212 = V_435 ;
V_221 -> V_436 = V_216 -> V_311 ;
V_221 -> V_437 = V_216 -> V_310 ;
V_221 -> V_339 . V_214 = ! F_1 ( V_1 , V_3 ) ?
0 : V_215 ;
} else {
V_221 -> V_339 . V_212 = V_438 ;
V_221 -> V_436 = V_216 -> V_313 ;
V_221 -> V_437 = V_216 -> V_312 ;
V_221 -> V_339 . V_214 = V_215 ;
}
return 0 ;
V_434:
if ( V_106 ) {
F_204 ( & V_1 -> V_146 , V_219 ) ;
F_48 ( & V_106 -> V_109 , & V_1 -> V_108 ) ;
F_206 ( & V_1 -> V_146 , V_219 ) ;
}
F_145 ( V_1 , & V_339 -> V_267 ) ;
return V_19 ;
}
static int
F_207 ( struct V_226 * V_2 , struct V_269 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_338 * V_339 = & V_216 -> V_221 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_207 * V_404 ;
int V_278 ;
F_9 ( L_128 ,
V_216 , V_3 -> V_284 ) ;
V_339 -> V_222 = V_335 ;
V_278 = V_24 -> V_95 ( V_2 , V_4 , V_339 ) ;
if ( V_278 ) {
F_3 ( L_129 , V_216 ) ;
return V_278 ;
}
if ( ! F_1 ( V_1 , V_3 ) ) {
F_100 ( V_1 , V_216 ,
& V_216 -> V_206 ) ;
F_175 ( V_4 , V_2 , true , (struct V_405 * )
& V_216 -> V_206 . V_230 ) ;
F_102 ( V_1 , & V_216 -> V_206 ) ;
F_103 ( V_1 , V_216 ,
& V_216 -> V_206 . V_208 ) ;
V_216 -> V_221 . V_499 . V_339 . V_203 = & V_216 -> V_206 . V_208 ;
V_339 -> V_378 += 1 ;
V_278 = F_96 ( V_1 , V_216 -> V_61 ) ;
if ( V_278 ) {
F_3 ( L_69 , V_278 ) ;
return V_278 ;
}
}
V_278 = F_99 ( V_1 -> V_58 , & V_339 -> V_221 -> V_339 , & V_404 ) ;
if ( V_278 )
F_6 ( L_130 ) ;
if ( ! F_1 ( V_1 , V_3 ) )
F_9 ( L_131
L_132 , V_216 ) ;
else
F_9 ( L_133 ,
V_216 ) ;
return 1 ;
}
static int
F_208 ( struct V_226 * V_2 , struct V_269 * V_4 , bool V_500 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_216 * V_216 = F_112 ( V_4 ) ;
struct V_338 * V_339 = & V_216 -> V_221 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_23 * V_24 = V_1 -> V_24 ;
struct V_207 * V_404 ;
int V_278 ;
F_9 ( L_134 ,
V_216 , V_3 -> V_284 , V_4 -> V_292 ) ;
V_339 -> V_222 = V_387 ;
V_278 = V_24 -> V_95 ( V_2 , V_4 , V_339 ) ;
if ( V_278 ) {
F_3 ( L_129 , V_216 ) ;
return V_278 ;
}
V_278 = F_99 ( V_1 -> V_58 , & V_339 -> V_221 -> V_339 , & V_404 ) ;
if ( V_278 )
F_6 ( L_135 ) ;
F_9 ( L_136 ,
V_216 ) ;
return 0 ;
}
static int
F_209 ( struct V_226 * V_2 , struct V_269 * V_4 , int V_138 )
{
struct V_216 * V_216 = F_112 ( V_4 ) ;
int V_19 = 0 ;
switch ( V_138 ) {
case V_501 :
F_66 ( & V_2 -> V_344 ) ;
F_90 ( & V_4 -> V_345 ) ;
F_67 ( & V_2 -> V_344 ) ;
F_147 ( V_216 , true ) ;
break;
case V_502 :
V_19 = F_180 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_137 , V_138 ) ;
V_19 = - V_314 ;
break;
}
return V_19 ;
}
static int
F_210 ( struct V_226 * V_2 , struct V_269 * V_4 , int V_138 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
switch ( V_138 ) {
case V_385 :
V_19 = F_182 ( V_4 , V_2 ) ;
if ( ! V_19 )
V_1 -> V_503 = true ;
break;
case V_504 :
V_19 = F_180 ( V_4 , V_2 , true ) ;
break;
case V_381 :
V_19 = F_184 ( V_4 , V_2 ) ;
break;
case V_382 :
V_19 = F_186 ( V_4 , V_2 ) ;
break;
case V_383 :
V_19 = F_188 ( V_4 , V_2 ) ;
break;
case V_505 :
V_19 = F_158 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_138 , V_138 ) ;
V_19 = - V_314 ;
break;
}
return V_19 ;
}
struct V_33 *
F_87 ( struct V_160 * V_160 )
{
struct V_161 * V_162 = V_160 -> V_162 ;
struct V_33 * V_506 ;
struct V_507 * V_508 ;
int V_19 ;
V_508 = (struct V_507 * ) & V_162 -> V_509 ;
F_9 ( L_139 , & V_162 -> V_509 , V_508 ) ;
V_506 = F_211 ( & V_510 , F_93 , V_160 ,
V_511 , V_53 ) ;
if ( F_19 ( V_506 ) ) {
F_3 ( L_140 , F_20 ( V_506 ) ) ;
V_19 = F_20 ( V_506 ) ;
goto V_165;
}
F_9 ( L_141 , V_506 , V_506 -> V_10 ) ;
V_19 = F_212 ( V_506 , V_508 ) ;
if ( V_19 ) {
F_3 ( L_142 , V_19 ) ;
goto V_512;
}
V_19 = F_213 ( V_506 , 0 ) ;
if ( V_19 ) {
F_3 ( L_143 , V_19 ) ;
goto V_512;
}
return V_506 ;
V_512:
F_73 ( V_506 ) ;
V_165:
return F_17 ( V_19 ) ;
}
static int
F_214 ( struct V_161 * V_162 ,
struct V_513 * V_514 )
{
struct V_160 * V_160 ;
struct V_33 * V_515 ;
int V_19 ;
V_160 = F_23 ( sizeof( struct V_160 ) , V_67 ) ;
if ( ! V_160 ) {
F_3 ( L_144 ) ;
return - V_76 ;
}
F_215 ( & V_160 -> V_176 , 0 ) ;
F_61 ( & V_160 -> V_145 ) ;
F_47 ( & V_160 -> V_172 ) ;
F_47 ( & V_160 -> V_175 ) ;
V_160 -> V_162 = V_162 ;
memcpy ( & V_162 -> V_509 , V_514 ,
sizeof( struct V_513 ) ) ;
V_515 = F_87 ( V_160 ) ;
if ( F_19 ( V_515 ) ) {
V_19 = F_20 ( V_515 ) ;
goto V_165;
}
V_160 -> V_13 = V_515 ;
V_162 -> V_516 = V_160 ;
return 0 ;
V_165:
F_27 ( V_160 ) ;
return V_19 ;
}
static int
F_70 ( struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_517 V_518 ;
int V_19 ;
memset ( & V_518 , 0 , sizeof( struct V_517 ) ) ;
V_518 . V_167 = V_1 -> V_167 ;
V_518 . V_519 = 7 ;
V_518 . V_520 = 7 ;
V_19 = F_216 ( V_13 , & V_518 ) ;
if ( V_19 ) {
F_3 ( L_145 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int
F_217 ( struct V_226 * V_2 , struct V_227 * V_228 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_19 ;
F_13 ( L_146 , V_1 ) ;
V_19 = F_218 ( & V_1 -> V_142 ) ;
if ( V_19 ) {
F_3 ( L_147 ,
V_1 ) ;
return V_19 ;
}
F_219 ( & V_1 -> V_142 ) ;
if ( ! V_228 -> V_244 )
return 0 ;
F_105 ( V_1 ) ;
F_13 ( L_148 , V_2 ) ;
V_19 = F_218 ( & V_1 -> V_141 ) ;
if ( V_19 )
return V_19 ;
F_13 ( L_149 , V_228 -> V_263 ) ;
return 0 ;
}
static void
F_220 ( struct V_161 * V_162 , struct V_226 * V_2 ,
struct V_1 * V_1 )
{
struct V_33 * V_13 = V_1 -> V_13 ;
struct V_521 * V_522 = & V_13 -> V_523 ;
V_2 -> V_524 = V_162 -> V_509 . V_525 ;
V_2 -> V_526 = V_522 -> V_72 . V_527 ;
V_2 -> V_528 = V_522 -> V_72 . V_529 ;
}
static int
F_221 ( struct V_161 * V_162 , struct V_226 * V_2 )
{
struct V_160 * V_160 = V_162 -> V_516 ;
struct V_1 * V_1 ;
int V_19 ;
V_530:
V_19 = F_222 ( & V_160 -> V_176 ) ;
if ( V_19 )
return - V_531 ;
F_66 ( & V_162 -> V_163 ) ;
if ( V_162 -> V_532 >= V_533 ) {
F_67 ( & V_162 -> V_163 ) ;
F_9 ( L_150 ,
V_162 -> V_532 ) ;
return - V_531 ;
}
F_67 ( & V_162 -> V_163 ) ;
F_11 ( & V_160 -> V_145 ) ;
if ( F_50 ( & V_160 -> V_175 ) ) {
F_12 ( & V_160 -> V_145 ) ;
goto V_530;
}
V_1 = F_205 ( & V_160 -> V_175 ,
struct V_1 , V_140 ) ;
F_90 ( & V_1 -> V_140 ) ;
F_12 ( & V_160 -> V_145 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
F_220 ( V_162 , V_2 , V_1 ) ;
F_9 ( L_151 , V_1 ) ;
return 0 ;
}
static void
F_223 ( struct V_161 * V_162 )
{
struct V_160 * V_160 = V_162 -> V_516 ;
struct V_1 * V_1 , * V_401 ;
if ( V_160 -> V_13 )
F_73 ( V_160 -> V_13 ) ;
F_11 ( & V_160 -> V_145 ) ;
if ( ! F_50 ( & V_160 -> V_175 ) ) {
F_13 ( L_152 ) ;
F_51 (isert_conn, n,
&isert_np->pending,
node) {
F_13 ( L_153 ,
V_1 , V_1 -> V_138 ) ;
F_71 ( V_1 ) ;
}
}
if ( ! F_50 ( & V_160 -> V_172 ) ) {
F_13 ( L_154 ) ;
F_51 (isert_conn, n,
&isert_np->accepted,
node) {
F_13 ( L_153 ,
V_1 , V_1 -> V_138 ) ;
F_71 ( V_1 ) ;
}
}
F_12 ( & V_160 -> V_145 ) ;
V_162 -> V_516 = NULL ;
F_27 ( V_160 ) ;
}
static void V_148 ( struct V_379 * V_77 )
{
struct V_1 * V_1 = F_80 ( V_77 ,
struct V_1 ,
V_147 ) ;
F_13 ( L_155 , V_1 ) ;
F_224 ( & V_1 -> V_143 ) ;
F_11 ( & V_1 -> V_145 ) ;
V_1 -> V_138 = V_534 ;
F_12 ( & V_1 -> V_145 ) ;
F_13 ( L_156 , V_1 ) ;
F_81 ( V_1 ) ;
}
static void
F_225 ( struct V_1 * V_1 )
{
struct V_226 * V_2 = V_1 -> V_2 ;
F_13 ( L_36 , V_1 ) ;
if ( V_1 -> V_503 ) {
F_13 ( L_157 , V_1 ) ;
F_226 ( & V_2 -> V_535 ,
V_536 * V_537 ) ;
}
}
static void
F_227 ( struct V_226 * V_2 )
{
F_13 ( L_158 , V_2 ) ;
if ( V_2 -> V_130 ) {
F_228 ( V_2 -> V_130 -> V_129 ) ;
F_229 ( V_2 -> V_130 -> V_129 ) ;
}
}
static void
F_230 ( struct V_1 * V_1 )
{
struct V_196 * V_448 ;
F_13 ( L_36 , V_1 ) ;
F_59 ( & V_1 -> V_392 ) ;
V_1 -> V_538 . V_199 = V_391 ;
if ( F_95 ( V_1 -> V_58 , & V_1 -> V_538 , & V_448 ) ) {
F_3 ( L_159 , V_1 ) ;
return;
}
F_224 ( & V_1 -> V_392 ) ;
}
static void
F_231 ( struct V_226 * V_2 )
{
struct V_269 * V_4 , * V_107 ;
static F_232 ( V_539 ) ;
F_66 ( & V_2 -> V_344 ) ;
F_51 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_294 & V_540 ) &&
( V_4 -> V_292 < V_2 -> V_130 -> V_237 -> V_541 ) &&
( V_4 -> V_292 < V_4 -> V_3 . V_284 ) )
F_77 ( & V_4 -> V_345 , & V_539 ) ;
}
F_67 ( & V_2 -> V_344 ) ;
F_51 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_90 ( & V_4 -> V_345 ) ;
if ( V_4 -> V_296 != V_501 ) {
struct V_216 * V_216 = F_112 ( V_4 ) ;
F_13 ( L_160 , V_2 , V_4 ) ;
F_147 ( V_216 , true ) ;
}
}
}
static void F_233 ( struct V_226 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_13 ( L_161 , V_1 ) ;
F_11 ( & V_1 -> V_145 ) ;
if ( V_1 -> V_138 == V_139 ) {
F_12 ( & V_1 -> V_145 ) ;
return;
}
F_83 ( V_1 ) ;
F_12 ( & V_1 -> V_145 ) ;
F_230 ( V_1 ) ;
F_231 ( V_2 ) ;
F_227 ( V_2 ) ;
F_225 ( V_1 ) ;
F_91 ( V_186 , & V_1 -> V_147 ) ;
}
static void F_234 ( struct V_226 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_230 ( V_1 ) ;
F_81 ( V_1 ) ;
}
static int T_4 F_235 ( void )
{
int V_19 ;
V_386 = F_236 ( L_162 ,
V_542 | V_543 , 0 ) ;
if ( ! V_386 ) {
F_3 ( L_163 ) ;
V_19 = - V_76 ;
return - V_76 ;
}
V_186 = F_236 ( L_164 , V_542 ,
V_544 ) ;
if ( ! V_186 ) {
F_3 ( L_165 ) ;
V_19 = - V_76 ;
goto V_545;
}
F_237 ( & V_546 ) ;
F_13 ( L_166 ) ;
return 0 ;
V_545:
F_238 ( V_386 ) ;
return V_19 ;
}
static void T_5 F_239 ( void )
{
F_240 () ;
F_238 ( V_186 ) ;
F_238 ( V_386 ) ;
F_241 ( & V_546 ) ;
F_13 ( L_167 ) ;
}
