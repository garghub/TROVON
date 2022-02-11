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
V_29 . V_36 . V_37 = V_38 + 1 ;
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
static int
F_18 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_58 * V_59 ;
struct V_60 * V_61 ;
T_1 V_62 ;
int V_19 , V_63 ;
V_1 -> V_64 = F_19 ( V_40 *
sizeof( struct V_58 ) , V_65 ) ;
if ( ! V_1 -> V_64 )
goto V_66;
V_59 = V_1 -> V_64 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_59 ++ ) {
V_62 = F_20 ( V_57 , ( void * ) V_59 ,
V_67 , V_68 ) ;
if ( F_21 ( V_57 , V_62 ) )
goto V_69;
V_59 -> V_62 = V_62 ;
V_61 = & V_59 -> V_61 ;
V_61 -> V_70 = V_59 -> V_62 ;
V_61 -> V_71 = V_67 ;
V_61 -> V_72 = V_17 -> V_54 -> V_73 ;
V_59 -> V_74 . V_75 = V_76 ;
}
return 0 ;
V_69:
V_59 = V_1 -> V_64 ;
for ( V_63 = 0 ; V_63 < V_19 ; V_63 ++ , V_59 ++ ) {
F_22 ( V_57 , V_59 -> V_62 ,
V_67 , V_68 ) ;
}
F_23 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
V_66:
F_3 ( L_5 , V_1 ) ;
return - V_77 ;
}
static void
F_24 ( struct V_1 * V_1 )
{
struct V_42 * V_57 = V_1 -> V_17 -> V_42 ;
struct V_58 * V_59 ;
int V_19 ;
if ( ! V_1 -> V_64 )
return;
V_59 = V_1 -> V_64 ;
for ( V_19 = 0 ; V_19 < V_40 ; V_19 ++ , V_59 ++ ) {
F_22 ( V_57 , V_59 -> V_62 ,
V_67 , V_68 ) ;
}
F_23 ( V_1 -> V_64 ) ;
V_1 -> V_64 = NULL ;
}
static void
F_25 ( struct V_16 * V_17 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
if ( V_18 -> V_34 )
F_26 ( V_18 -> V_34 ) ;
}
F_23 ( V_17 -> V_23 ) ;
}
static int
F_27 ( struct V_16 * V_17 )
{
int V_19 , V_78 , V_30 = 0 ;
V_17 -> V_22 = V_20 ( V_79 , F_28 ( int , F_29 () ,
V_17 -> V_42 -> V_80 ) ) ;
F_10 ( L_6
L_7 ,
V_17 -> V_22 , V_17 -> V_42 -> V_81 ,
V_17 -> V_42 -> V_80 , V_17 -> V_82 ,
V_17 -> V_51 ) ;
V_17 -> V_23 = F_30 ( V_17 -> V_22 , sizeof( struct V_15 ) ,
V_65 ) ;
if ( ! V_17 -> V_23 ) {
F_3 ( L_8 ) ;
return - V_77 ;
}
V_78 = V_20 ( V_83 , V_17 -> V_42 -> V_43 . V_78 ) ;
for ( V_19 = 0 ; V_19 < V_17 -> V_22 ; V_19 ++ ) {
struct V_15 * V_18 = & V_17 -> V_23 [ V_19 ] ;
V_18 -> V_17 = V_17 ;
V_18 -> V_34 = F_31 ( V_17 -> V_42 , V_18 , V_78 , V_19 ,
V_84 ) ;
if ( F_16 ( V_18 -> V_34 ) ) {
F_3 ( L_9 ) ;
V_30 = F_17 ( V_18 -> V_34 ) ;
V_18 -> V_34 = NULL ;
goto V_85;
}
}
return 0 ;
V_85:
F_25 ( V_17 ) ;
return V_30 ;
}
static int
F_32 ( struct V_16 * V_17 )
{
struct V_42 * V_57 = V_17 -> V_42 ;
int V_30 ;
F_33 ( L_10 , V_57 -> V_43 . V_44 ) ;
F_33 ( L_11 , V_57 -> V_43 . V_45 ) ;
if ( V_57 -> V_43 . V_86 & V_87 &&
V_57 -> V_43 . V_86 & V_88 ) {
V_17 -> V_82 = 1 ;
V_17 -> V_89 = V_90 ;
V_17 -> V_91 = V_92 ;
} else {
V_17 -> V_82 = 0 ;
V_17 -> V_89 = V_93 ;
V_17 -> V_91 = V_94 ;
}
V_30 = F_27 ( V_17 ) ;
if ( V_30 )
goto V_95;
V_17 -> V_54 = F_34 ( V_57 ) ;
if ( F_16 ( V_17 -> V_54 ) ) {
V_30 = F_17 ( V_17 -> V_54 ) ;
F_3 ( L_12 ,
V_17 , V_30 ) ;
goto V_85;
}
V_17 -> V_51 = V_57 -> V_43 . V_86 &
V_88 ? true : false ;
return 0 ;
V_85:
F_25 ( V_17 ) ;
V_95:
if ( V_30 > 0 )
V_30 = - V_96 ;
return V_30 ;
}
static void
F_35 ( struct V_16 * V_17 )
{
F_10 ( L_13 , V_17 ) ;
F_36 ( V_17 -> V_54 ) ;
F_25 ( V_17 ) ;
}
static void
F_37 ( struct V_16 * V_17 )
{
F_8 ( & V_21 ) ;
V_17 -> V_97 -- ;
F_10 ( L_14 , V_17 , V_17 -> V_97 ) ;
if ( ! V_17 -> V_97 ) {
F_35 ( V_17 ) ;
F_38 ( & V_17 -> V_98 ) ;
F_23 ( V_17 ) ;
}
F_9 ( & V_21 ) ;
}
static struct V_16 *
F_39 ( struct V_26 * V_27 )
{
struct V_16 * V_17 ;
int V_30 ;
F_8 ( & V_21 ) ;
F_40 (device, &device_list, dev_node) {
if ( V_17 -> V_42 -> V_99 == V_27 -> V_17 -> V_99 ) {
V_17 -> V_97 ++ ;
F_10 ( L_15 ,
V_17 , V_17 -> V_97 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
}
V_17 = F_19 ( sizeof( struct V_16 ) , V_65 ) ;
if ( ! V_17 ) {
F_9 ( & V_21 ) ;
return F_14 ( - V_77 ) ;
}
F_41 ( & V_17 -> V_98 ) ;
V_17 -> V_42 = V_27 -> V_17 ;
V_30 = F_32 ( V_17 ) ;
if ( V_30 ) {
F_23 ( V_17 ) ;
F_9 ( & V_21 ) ;
return F_14 ( V_30 ) ;
}
V_17 -> V_97 ++ ;
F_42 ( & V_17 -> V_98 , & V_100 ) ;
F_10 ( L_16 ,
V_17 , V_17 -> V_97 ) ;
F_9 ( & V_21 ) ;
return V_17 ;
}
static void
F_43 ( struct V_1 * V_1 )
{
struct V_101 * V_102 , * V_103 ;
int V_19 = 0 ;
if ( F_44 ( & V_1 -> V_104 ) )
return;
F_10 ( L_17 , V_1 ) ;
F_45 (fr_desc, tmp,
&isert_conn->fr_pool, list) {
F_38 ( & V_102 -> V_105 ) ;
F_46 ( V_102 -> V_106 ) ;
if ( V_102 -> V_107 ) {
F_46 ( V_102 -> V_107 -> V_108 ) ;
F_46 ( V_102 -> V_107 -> V_109 ) ;
F_23 ( V_102 -> V_107 ) ;
}
F_23 ( V_102 ) ;
++ V_19 ;
}
if ( V_19 < V_1 -> V_110 )
F_6 ( L_18 ,
V_1 -> V_110 - V_19 ) ;
}
static int
F_47 ( struct V_101 * V_111 ,
struct V_42 * V_17 ,
struct V_112 * V_54 )
{
struct V_113 * V_107 ;
int V_30 ;
V_107 = F_19 ( sizeof( * V_111 -> V_107 ) , V_65 ) ;
if ( ! V_107 ) {
F_3 ( L_19 ) ;
return - V_77 ;
}
V_107 -> V_108 = F_48 ( V_54 , V_114 ,
V_115 ) ;
if ( F_16 ( V_107 -> V_108 ) ) {
F_3 ( L_20 ,
F_17 ( V_107 -> V_108 ) ) ;
V_30 = F_17 ( V_107 -> V_108 ) ;
goto V_116;
}
V_111 -> V_117 |= V_118 ;
V_107 -> V_109 = F_48 ( V_54 , V_119 , 2 ) ;
if ( F_16 ( V_107 -> V_109 ) ) {
F_3 ( L_21 ,
F_17 ( V_107 -> V_109 ) ) ;
V_30 = F_17 ( V_107 -> V_109 ) ;
goto V_120;
}
V_111 -> V_107 = V_107 ;
V_111 -> V_117 |= V_121 ;
V_111 -> V_117 &= ~ V_122 ;
return 0 ;
V_120:
F_46 ( V_107 -> V_108 ) ;
V_116:
F_23 ( V_107 ) ;
return V_30 ;
}
static int
F_49 ( struct V_42 * V_42 , struct V_112 * V_54 ,
struct V_101 * V_102 )
{
V_102 -> V_106 = F_48 ( V_54 , V_114 ,
V_115 ) ;
if ( F_16 ( V_102 -> V_106 ) ) {
F_3 ( L_22 ,
F_17 ( V_102 -> V_106 ) ) ;
return F_17 ( V_102 -> V_106 ) ;
}
V_102 -> V_117 |= V_123 ;
F_33 ( L_23 , V_102 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_1 )
{
struct V_101 * V_102 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_124 * V_125 = V_1 -> V_2 -> V_126 -> V_125 ;
struct V_127 * V_128 = V_125 -> V_127 ;
int V_19 , V_30 , V_129 ;
V_129 = F_51 ( V_130 , V_131 , V_128 -> V_132 ) ;
V_129 = ( V_129 * 2 ) + V_133 ;
V_1 -> V_110 = 0 ;
for ( V_19 = 0 ; V_19 < V_129 ; V_19 ++ ) {
V_102 = F_19 ( sizeof( * V_102 ) , V_65 ) ;
if ( ! V_102 ) {
F_3 ( L_24 ) ;
V_30 = - V_77 ;
goto V_56;
}
V_30 = F_49 ( V_17 -> V_42 ,
V_17 -> V_54 , V_102 ) ;
if ( V_30 ) {
F_3 ( L_25 ,
V_30 ) ;
F_23 ( V_102 ) ;
goto V_56;
}
F_42 ( & V_102 -> V_105 , & V_1 -> V_104 ) ;
V_1 -> V_110 ++ ;
}
F_33 ( L_26 ,
V_1 , V_1 -> V_110 ) ;
return 0 ;
V_56:
F_43 ( V_1 ) ;
return V_30 ;
}
static void
F_52 ( struct V_1 * V_1 )
{
V_1 -> V_134 = V_135 ;
F_41 ( & V_1 -> V_136 ) ;
F_53 ( & V_1 -> V_137 ) ;
F_53 ( & V_1 -> V_138 ) ;
F_54 ( & V_1 -> V_139 ) ;
F_55 ( & V_1 -> V_140 ) ;
F_56 ( & V_1 -> V_141 ) ;
F_41 ( & V_1 -> V_104 ) ;
F_57 ( & V_1 -> V_142 , V_143 ) ;
}
static void
F_58 ( struct V_1 * V_1 )
{
struct V_42 * V_57 = V_1 -> V_17 -> V_42 ;
F_22 ( V_57 , V_1 -> V_144 ,
V_67 , V_145 ) ;
F_23 ( V_1 -> V_146 ) ;
F_22 ( V_57 , V_1 -> V_147 ,
V_67 ,
V_68 ) ;
F_23 ( V_1 -> V_148 ) ;
}
static int
F_59 ( struct V_1 * V_1 ,
struct V_42 * V_57 )
{
int V_30 ;
V_1 -> V_148 = F_19 ( sizeof( * V_1 -> V_148 ) ,
V_65 ) ;
if ( ! V_1 -> V_148 ) {
F_3 ( L_27 ) ;
return - V_77 ;
}
V_1 -> V_147 = F_20 ( V_57 ,
V_1 -> V_148 ,
V_67 , V_68 ) ;
V_30 = F_21 ( V_57 , V_1 -> V_147 ) ;
if ( V_30 ) {
F_3 ( L_28 , V_30 ) ;
V_1 -> V_147 = 0 ;
goto V_149;
}
V_1 -> V_146 = F_19 ( V_67 , V_65 ) ;
if ( ! V_1 -> V_146 ) {
F_3 ( L_29 ) ;
goto V_150;
}
V_1 -> V_144 = F_20 ( V_57 ,
V_1 -> V_146 ,
V_67 , V_145 ) ;
V_30 = F_21 ( V_57 , V_1 -> V_144 ) ;
if ( V_30 ) {
F_3 ( L_30 , V_30 ) ;
V_1 -> V_144 = 0 ;
goto V_151;
}
return 0 ;
V_151:
F_23 ( V_1 -> V_146 ) ;
V_150:
F_22 ( V_57 , V_1 -> V_147 ,
V_67 , V_68 ) ;
V_149:
F_23 ( V_1 -> V_148 ) ;
return V_30 ;
}
static void
F_60 ( struct V_1 * V_1 ,
struct V_152 * V_153 )
{
struct V_154 * V_29 = & V_1 -> V_17 -> V_42 -> V_43 ;
V_1 -> V_155 = F_28 ( V_156 , V_153 -> V_155 ,
V_29 -> V_157 ) ;
F_33 ( L_31 , V_1 -> V_155 ) ;
if ( V_153 -> V_158 ) {
V_156 V_159 = * ( V_156 * ) V_153 -> V_158 ;
V_1 -> V_160 = ! ( V_159 & V_161 ) &&
( V_29 -> V_86 &
V_87 ) ;
if ( V_1 -> V_160 )
F_10 ( L_32 ) ;
}
}
static int
F_61 ( struct V_26 * V_27 , struct V_162 * V_11 )
{
struct V_163 * V_163 = V_27 -> V_10 ;
struct V_164 * V_165 = V_163 -> V_165 ;
struct V_1 * V_1 ;
struct V_16 * V_17 ;
int V_30 = 0 ;
F_62 ( & V_165 -> V_166 ) ;
if ( ! V_165 -> V_167 ) {
F_63 ( & V_165 -> V_166 ) ;
F_33 ( L_33 ) ;
return F_64 ( V_27 , NULL , 0 ) ;
}
F_63 ( & V_165 -> V_166 ) ;
F_33 ( L_34 ,
V_27 , V_27 -> V_10 ) ;
V_1 = F_19 ( sizeof( struct V_1 ) , V_65 ) ;
if ( ! V_1 )
return - V_77 ;
F_52 ( V_1 ) ;
V_1 -> V_13 = V_27 ;
V_30 = F_59 ( V_1 , V_27 -> V_17 ) ;
if ( V_30 )
goto V_95;
V_17 = F_39 ( V_27 ) ;
if ( F_16 ( V_17 ) ) {
V_30 = F_17 ( V_17 ) ;
goto V_168;
}
V_1 -> V_17 = V_17 ;
F_60 ( V_1 , & V_11 -> V_153 . V_2 ) ;
V_30 = F_15 ( V_1 , V_27 ) ;
if ( V_30 )
goto V_169;
V_30 = F_65 ( V_1 ) ;
if ( V_30 )
goto V_169;
V_30 = F_66 ( V_1 ) ;
if ( V_30 )
goto V_169;
F_8 ( & V_163 -> V_140 ) ;
F_42 ( & V_1 -> V_136 , & V_163 -> V_170 ) ;
F_9 ( & V_163 -> V_140 ) ;
return 0 ;
V_169:
F_37 ( V_17 ) ;
V_168:
F_58 ( V_1 ) ;
V_95:
F_23 ( V_1 ) ;
F_64 ( V_27 , NULL , 0 ) ;
return V_30 ;
}
static void
F_67 ( struct V_1 * V_1 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
F_33 ( L_35 , V_1 ) ;
F_68 ( ! V_17 ) ;
if ( V_17 -> V_82 )
F_43 ( V_1 ) ;
F_24 ( V_1 ) ;
if ( V_1 -> V_13 )
F_69 ( V_1 -> V_13 ) ;
if ( V_1 -> V_55 ) {
struct V_15 * V_18 = V_1 -> V_55 -> V_35 -> V_171 ;
F_11 ( V_18 ) ;
F_70 ( V_1 -> V_55 ) ;
}
if ( V_1 -> V_148 )
F_58 ( V_1 ) ;
F_37 ( V_17 ) ;
F_23 ( V_1 ) ;
}
static void
F_71 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_55 -> V_32 ;
struct V_163 * V_163 = V_27 -> V_10 ;
F_10 ( L_35 , V_1 ) ;
F_8 ( & V_1 -> V_140 ) ;
V_1 -> V_134 = V_172 ;
F_72 ( & V_1 -> V_139 ) ;
F_9 ( & V_1 -> V_140 ) ;
F_8 ( & V_163 -> V_140 ) ;
F_73 ( & V_1 -> V_136 , & V_163 -> V_173 ) ;
F_9 ( & V_163 -> V_140 ) ;
F_10 ( L_36 , V_163 ) ;
F_74 ( & V_163 -> V_174 ) ;
}
static void
F_75 ( struct V_139 * V_139 )
{
struct V_1 * V_1 = F_76 ( V_139 ,
struct V_1 , V_139 ) ;
F_10 ( L_37 , V_1 , V_175 -> V_176 ,
V_175 -> V_177 ) ;
F_67 ( V_1 ) ;
}
static void
F_77 ( struct V_1 * V_1 )
{
F_78 ( & V_1 -> V_139 , F_75 ) ;
}
static void
F_79 ( struct V_1 * V_1 )
{
struct V_163 * V_163 = V_1 -> V_13 -> V_10 ;
F_8 ( & V_163 -> V_140 ) ;
if ( ! F_44 ( & V_1 -> V_136 ) ) {
F_80 ( & V_1 -> V_136 ) ;
F_77 ( V_1 ) ;
F_81 ( V_178 , & V_1 -> V_142 ) ;
}
F_9 ( & V_163 -> V_140 ) ;
}
static void
F_82 ( struct V_1 * V_1 )
{
int V_56 ;
if ( V_1 -> V_134 >= V_179 )
return;
F_10 ( L_38 ,
V_1 , V_1 -> V_134 ) ;
V_1 -> V_134 = V_179 ;
V_56 = F_83 ( V_1 -> V_13 ) ;
if ( V_56 )
F_6 ( L_39 ,
V_1 ) ;
}
static int
F_84 ( struct V_163 * V_163 ,
enum V_180 V_11 )
{
F_33 ( L_40 ,
F_85 ( V_11 ) , V_11 , V_163 ) ;
switch ( V_11 ) {
case V_181 :
V_163 -> V_13 = NULL ;
break;
case V_182 :
V_163 -> V_13 = F_86 ( V_163 ) ;
if ( F_16 ( V_163 -> V_13 ) ) {
F_3 ( L_41 ,
V_163 , F_17 ( V_163 -> V_13 ) ) ;
V_163 -> V_13 = NULL ;
}
break;
default:
F_3 ( L_42 ,
V_163 , V_11 ) ;
}
return - 1 ;
}
static int
F_87 ( struct V_26 * V_27 ,
enum V_180 V_11 )
{
struct V_1 * V_1 = V_27 -> V_55 -> V_32 ;
F_8 ( & V_1 -> V_140 ) ;
switch ( V_1 -> V_134 ) {
case V_179 :
break;
case V_172 :
F_82 ( V_1 ) ;
F_88 ( V_1 -> V_55 ) ;
F_79 ( V_1 ) ;
break;
case V_183 :
case V_184 :
F_89 ( V_1 -> V_2 , 0 ) ;
break;
default:
F_6 ( L_43 ,
V_1 , V_1 -> V_134 ) ;
}
F_9 ( & V_1 -> V_140 ) ;
return 0 ;
}
static int
F_90 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_55 -> V_32 ;
F_80 ( & V_1 -> V_136 ) ;
V_1 -> V_13 = NULL ;
F_77 ( V_1 ) ;
return - 1 ;
}
static int
F_91 ( struct V_26 * V_27 , struct V_162 * V_11 )
{
struct V_163 * V_163 = V_27 -> V_10 ;
int V_30 = 0 ;
F_10 ( L_44 ,
F_85 ( V_11 -> V_11 ) , V_11 -> V_11 ,
V_11 -> V_185 , V_27 , V_27 -> V_10 ) ;
if ( V_163 -> V_13 == V_27 )
return F_84 ( V_27 -> V_10 , V_11 -> V_11 ) ;
switch ( V_11 -> V_11 ) {
case V_186 :
V_30 = F_61 ( V_27 , V_11 ) ;
if ( V_30 )
F_3 ( L_45 , V_30 ) ;
break;
case V_187 :
F_71 ( V_27 ) ;
break;
case V_182 :
case V_188 :
case V_181 :
case V_189 :
V_30 = F_87 ( V_27 , V_11 -> V_11 ) ;
break;
case V_190 :
case V_191 :
case V_192 :
V_30 = F_90 ( V_27 ) ;
break;
default:
F_3 ( L_46 , V_11 -> V_11 ) ;
break;
}
return V_30 ;
}
static int
F_92 ( struct V_1 * V_1 , V_130 V_193 )
{
struct V_194 * V_195 , * V_196 ;
int V_19 , V_30 ;
struct V_58 * V_59 ;
for ( V_195 = V_1 -> V_195 , V_19 = 0 ; V_19 < V_193 ; V_19 ++ , V_195 ++ ) {
V_59 = & V_1 -> V_64 [ V_19 ] ;
V_195 -> V_197 = & V_59 -> V_74 ;
V_195 -> V_198 = & V_59 -> V_61 ;
V_195 -> V_199 = 1 ;
V_195 -> V_200 = V_195 + 1 ;
}
V_195 -- ;
V_195 -> V_200 = NULL ;
V_30 = F_93 ( V_1 -> V_55 , V_1 -> V_195 ,
& V_196 ) ;
if ( V_30 )
F_3 ( L_47 , V_30 ) ;
return V_30 ;
}
static int
F_94 ( struct V_1 * V_1 , struct V_58 * V_59 )
{
struct V_194 * V_196 , V_195 ;
int V_30 ;
V_195 . V_197 = & V_59 -> V_74 ;
V_195 . V_198 = & V_59 -> V_61 ;
V_195 . V_199 = 1 ;
V_195 . V_200 = NULL ;
V_30 = F_93 ( V_1 -> V_55 , & V_195 , & V_196 ) ;
if ( V_30 )
F_3 ( L_47 , V_30 ) ;
return V_30 ;
}
static int
F_95 ( struct V_1 * V_1 , struct V_201 * V_202 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_203 V_204 , * V_205 ;
int V_30 ;
F_96 ( V_57 , V_202 -> V_62 ,
V_206 , V_145 ) ;
V_202 -> V_207 . V_75 = V_208 ;
V_204 . V_200 = NULL ;
V_204 . V_197 = & V_202 -> V_207 ;
V_204 . V_198 = V_202 -> V_209 ;
V_204 . V_199 = V_202 -> V_199 ;
V_204 . V_210 = V_211 ;
V_204 . V_212 = V_213 ;
V_30 = F_97 ( V_1 -> V_55 , & V_204 , & V_205 ) ;
if ( V_30 )
F_3 ( L_48 , V_30 ) ;
return V_30 ;
}
static void
F_98 ( struct V_1 * V_1 ,
struct V_214 * V_214 ,
struct V_201 * V_202 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
F_99 ( V_57 , V_202 -> V_62 ,
V_206 , V_145 ) ;
memset ( & V_202 -> V_215 , 0 , sizeof( struct V_216 ) ) ;
V_202 -> V_215 . V_159 = V_217 ;
V_202 -> V_199 = 1 ;
if ( V_202 -> V_209 [ 0 ] . V_72 != V_17 -> V_54 -> V_73 ) {
V_202 -> V_209 [ 0 ] . V_72 = V_17 -> V_54 -> V_73 ;
F_33 ( L_49 , V_202 ) ;
}
}
static int
F_100 ( struct V_1 * V_1 ,
struct V_201 * V_202 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
T_1 V_62 ;
V_62 = F_20 ( V_57 , ( void * ) V_202 ,
V_206 , V_145 ) ;
if ( F_21 ( V_57 , V_62 ) ) {
F_3 ( L_50 ) ;
return - V_77 ;
}
V_202 -> V_62 = V_62 ;
V_202 -> V_209 [ 0 ] . V_70 = V_202 -> V_62 ;
V_202 -> V_209 [ 0 ] . V_71 = V_206 ;
V_202 -> V_209 [ 0 ] . V_72 = V_17 -> V_54 -> V_73 ;
F_33 ( L_51 ,
V_202 -> V_209 [ 0 ] . V_70 , V_202 -> V_209 [ 0 ] . V_71 ,
V_202 -> V_209 [ 0 ] . V_72 ) ;
return 0 ;
}
static void
F_101 ( struct V_1 * V_1 , struct V_214 * V_214 ,
struct V_203 * V_204 )
{
struct V_201 * V_202 = & V_214 -> V_202 ;
V_214 -> V_218 = V_219 ;
V_202 -> V_207 . V_75 = V_220 ;
V_204 -> V_197 = & V_202 -> V_207 ;
if ( V_1 -> V_160 && V_214 -> V_221 ) {
V_204 -> V_210 = V_222 ;
V_204 -> V_223 . V_224 = V_214 -> V_221 ;
} else {
V_204 -> V_210 = V_211 ;
}
V_204 -> V_198 = & V_202 -> V_209 [ 0 ] ;
V_204 -> V_199 = V_214 -> V_202 . V_199 ;
V_204 -> V_212 = V_213 ;
}
static int
F_65 ( struct V_1 * V_1 )
{
struct V_194 V_195 , * V_225 ;
struct V_60 V_226 ;
int V_30 ;
memset ( & V_226 , 0 , sizeof( struct V_60 ) ) ;
V_226 . V_70 = V_1 -> V_147 ;
V_226 . V_71 = V_67 ;
V_226 . V_72 = V_1 -> V_17 -> V_54 -> V_73 ;
F_33 ( L_52 ,
V_226 . V_70 , V_226 . V_71 , V_226 . V_72 ) ;
V_1 -> V_148 -> V_74 . V_75 = V_227 ;
memset ( & V_195 , 0 , sizeof( struct V_194 ) ) ;
V_195 . V_197 = & V_1 -> V_148 -> V_74 ;
V_195 . V_198 = & V_226 ;
V_195 . V_199 = 1 ;
V_30 = F_93 ( V_1 -> V_55 , & V_195 , & V_225 ) ;
if ( V_30 )
F_3 ( L_53 , V_30 ) ;
return V_30 ;
}
static int
F_102 ( struct V_228 * V_2 , struct V_229 * V_230 ,
V_130 V_71 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_201 * V_202 = & V_1 -> V_231 ;
int V_30 ;
F_98 ( V_1 , NULL , V_202 ) ;
memcpy ( & V_202 -> V_232 , & V_230 -> V_233 [ 0 ] ,
sizeof( struct V_234 ) ) ;
F_100 ( V_1 , V_202 ) ;
if ( V_71 > 0 ) {
struct V_60 * V_235 = & V_202 -> V_209 [ 1 ] ;
F_99 ( V_57 , V_1 -> V_144 ,
V_71 , V_145 ) ;
memcpy ( V_1 -> V_146 , V_230 -> V_236 , V_71 ) ;
F_96 ( V_57 , V_1 -> V_144 ,
V_71 , V_145 ) ;
V_235 -> V_70 = V_1 -> V_144 ;
V_235 -> V_71 = V_71 ;
V_235 -> V_72 = V_1 -> V_17 -> V_54 -> V_73 ;
V_202 -> V_199 = 2 ;
}
if ( ! V_230 -> V_237 ) {
if ( V_230 -> V_238 ) {
if ( ! V_2 -> V_126 -> V_239 -> V_240 &&
V_1 -> V_17 -> V_82 ) {
V_30 = F_50 ( V_1 ) ;
if ( V_30 ) {
F_3 ( L_54
L_55 , V_1 ) ;
return V_30 ;
}
}
V_30 = F_18 ( V_1 ) ;
if ( V_30 )
return V_30 ;
V_30 = F_92 ( V_1 ,
V_40 ) ;
if ( V_30 )
return V_30 ;
F_8 ( & V_1 -> V_140 ) ;
V_1 -> V_134 = V_184 ;
F_9 ( & V_1 -> V_140 ) ;
goto V_241;
}
V_30 = F_65 ( V_1 ) ;
if ( V_30 )
return V_30 ;
}
V_241:
V_30 = F_95 ( V_1 , V_202 ) ;
if ( V_30 )
return V_30 ;
return 0 ;
}
static void
F_103 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = V_1 -> V_148 ;
int V_242 = V_1 -> V_243 ;
struct V_228 * V_2 = V_1 -> V_2 ;
struct V_229 * V_230 = V_2 -> V_244 ;
int V_245 ;
F_10 ( L_35 , V_1 ) ;
F_104 ( ! V_230 ) ;
if ( V_230 -> V_246 ) {
struct V_247 * V_248 =
(struct V_247 * ) & V_59 -> V_232 ;
V_230 -> V_249 = ( ! V_248 -> V_250 ) ? 1 : 0 ;
V_230 -> V_251 =
( V_248 -> V_159 & V_252 )
>> 2 ;
V_230 -> V_253 = V_248 -> V_254 ;
V_230 -> V_255 = V_248 -> V_256 ;
memcpy ( V_230 -> V_257 , V_248 -> V_257 , 6 ) ;
V_230 -> V_258 = F_105 ( V_248 -> V_259 ) ;
V_230 -> V_260 = V_248 -> V_261 ;
V_230 -> V_262 = F_105 ( V_248 -> V_263 ) ;
V_230 -> V_264 = F_106 ( V_248 -> V_264 ) ;
V_230 -> V_250 = F_106 ( V_248 -> V_250 ) ;
}
memcpy ( & V_230 -> V_265 [ 0 ] , ( void * ) & V_59 -> V_232 , V_266 ) ;
V_245 = V_20 ( V_242 , V_267 ) ;
F_33 ( L_56
L_57 , V_245 , V_242 ,
V_267 ) ;
memcpy ( V_230 -> V_268 , & V_59 -> V_269 [ 0 ] , V_245 ) ;
if ( V_230 -> V_246 ) {
F_107 ( & V_1 -> V_137 ) ;
return;
}
F_108 ( & V_2 -> V_270 , 0 ) ;
}
static struct V_271
* F_109 ( struct V_228 * V_2 , struct V_58 * V_59 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_214 * V_214 ;
struct V_271 * V_4 ;
V_4 = F_110 ( V_2 , V_272 ) ;
if ( ! V_4 ) {
F_3 ( L_58 ) ;
return NULL ;
}
V_214 = F_111 ( V_4 ) ;
V_214 -> V_2 = V_1 ;
V_214 -> V_271 = V_4 ;
V_214 -> V_59 = V_59 ;
return V_4 ;
}
static int
F_112 ( struct V_1 * V_1 ,
struct V_214 * V_214 , struct V_271 * V_4 ,
struct V_58 * V_59 , unsigned char * V_273 )
{
struct V_228 * V_2 = V_1 -> V_2 ;
struct V_274 * V_275 = (struct V_274 * ) V_273 ;
int V_276 , V_277 , V_278 , V_279 , V_280 ;
bool V_281 = false ;
unsigned int V_282 ;
V_280 = F_113 ( V_2 , V_4 , V_273 ) ;
if ( V_280 < 0 )
return V_280 ;
V_276 = V_4 -> V_283 ;
V_277 = V_4 -> V_284 ;
V_278 = V_4 -> V_285 ;
V_282 = V_4 -> V_3 . V_286 ;
if ( V_276 && V_277 == V_282 )
V_4 -> V_3 . V_287 |= V_288 ;
V_280 = F_114 ( V_2 , V_4 , V_275 ) ;
if ( V_280 < 0 ) {
return 0 ;
} else if ( V_280 > 0 ) {
V_281 = true ;
goto V_289;
}
if ( ! V_276 )
return 0 ;
if ( V_277 != V_282 ) {
V_279 = F_115 ( 1UL , F_116 ( V_277 , V_290 ) ) ;
F_117 ( V_4 -> V_3 . V_291 , V_279 ,
& V_59 -> V_269 [ 0 ] , V_277 ) ;
F_33 ( L_59 ,
V_279 , V_277 ) ;
} else {
F_118 ( & V_214 -> V_292 , 1 ) ;
V_4 -> V_3 . V_291 = & V_214 -> V_292 ;
V_4 -> V_3 . V_293 = 1 ;
F_119 ( & V_214 -> V_292 , & V_59 -> V_269 [ 0 ] , V_277 ) ;
F_33 ( L_60 ,
V_277 ) ;
}
V_4 -> V_294 += V_277 ;
if ( V_4 -> V_294 == V_4 -> V_3 . V_286 ) {
F_62 ( & V_4 -> V_295 ) ;
V_4 -> V_296 |= V_297 ;
V_4 -> V_298 = V_299 ;
F_63 ( & V_4 -> V_295 ) ;
}
V_289:
V_280 = F_120 ( V_2 , V_4 , V_273 , V_275 -> V_259 ) ;
if ( ! V_280 && V_281 == false && V_278 )
F_121 ( V_4 ) ;
else if ( V_281 && V_276 )
F_122 ( & V_4 -> V_3 ) ;
return 0 ;
}
static int
F_123 ( struct V_1 * V_1 ,
struct V_58 * V_59 , unsigned char * V_273 )
{
struct V_300 * V_301 ;
struct V_228 * V_2 = V_1 -> V_2 ;
struct V_271 * V_4 = NULL ;
struct V_302 * V_275 = (struct V_302 * ) V_273 ;
V_130 V_303 = F_124 ( V_275 -> V_304 ) ;
int V_280 , V_279 , V_305 , V_306 ;
V_280 = F_125 ( V_2 , V_273 , & V_4 ) ;
if ( V_280 < 0 )
return V_280 ;
else if ( ! V_4 )
return 0 ;
if ( ! V_4 -> V_285 ) {
F_3 ( L_61 ) ;
F_126 () ;
return - 1 ;
}
F_33 ( L_62
L_63 ,
V_303 , V_4 -> V_294 ,
V_4 -> V_3 . V_286 ) ;
V_305 = V_4 -> V_294 / V_290 ;
V_301 = & V_4 -> V_3 . V_291 [ V_305 ] ;
V_279 = F_115 ( 1UL , F_116 ( V_303 , V_290 ) ) ;
V_306 = V_4 -> V_294 % V_290 ;
if ( V_306 ) {
F_3 ( L_64 ) ;
F_126 () ;
return - 1 ;
}
F_33 ( L_65
L_66 , V_301 , V_305 ,
V_279 , & V_59 -> V_269 [ 0 ] , V_303 ) ;
F_117 ( V_301 , V_279 , & V_59 -> V_269 [ 0 ] ,
V_303 ) ;
V_280 = F_127 ( V_4 , V_275 , false ) ;
if ( V_280 < 0 )
return V_280 ;
V_280 = F_94 ( V_1 , V_59 ) ;
if ( V_280 ) {
F_3 ( L_67 , V_280 ) ;
return V_280 ;
}
return 0 ;
}
static int
F_128 ( struct V_1 * V_1 , struct V_214 * V_214 ,
struct V_271 * V_4 , struct V_58 * V_59 ,
unsigned char * V_273 )
{
struct V_228 * V_2 = V_1 -> V_2 ;
struct V_307 * V_275 = (struct V_307 * ) V_273 ;
int V_280 ;
V_280 = F_129 ( V_2 , V_4 , V_275 ) ;
if ( V_280 < 0 )
return V_280 ;
return F_130 ( V_2 , V_4 , V_275 ) ;
}
static int
F_131 ( struct V_1 * V_1 , struct V_214 * V_214 ,
struct V_271 * V_4 , struct V_58 * V_59 ,
struct V_308 * V_275 )
{
struct V_228 * V_2 = V_1 -> V_2 ;
V_130 V_309 = F_124 ( V_275 -> V_304 ) ;
int V_280 ;
unsigned char * V_310 = NULL ;
V_280 = F_132 ( V_2 , V_4 , V_275 ) ;
if ( V_280 < 0 )
return V_280 ;
if ( V_309 ) {
V_310 = F_19 ( V_309 , V_65 ) ;
if ( ! V_310 ) {
F_3 ( L_68 ,
V_309 ) ;
return - V_77 ;
}
}
V_4 -> V_311 = V_310 ;
memcpy ( V_4 -> V_311 , & V_59 -> V_269 [ 0 ] , V_309 ) ;
return F_133 ( V_2 , V_4 , V_275 ) ;
}
static int
F_134 ( struct V_1 * V_1 , struct V_58 * V_59 ,
T_2 V_312 , T_3 V_313 ,
T_2 V_314 , T_3 V_315 )
{
struct V_234 * V_275 = & V_59 -> V_232 ;
struct V_228 * V_2 = V_1 -> V_2 ;
struct V_271 * V_4 ;
struct V_214 * V_214 ;
int V_30 = - V_96 ;
V_156 V_210 = ( V_275 -> V_210 & V_316 ) ;
if ( V_2 -> V_126 -> V_239 -> V_240 &&
( ! ( V_210 & V_317 ) || ! ( V_210 & V_318 ) ) ) {
F_3 ( L_69
L_70 , V_210 ) ;
return 0 ;
}
switch ( V_210 ) {
case V_319 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_214 = F_111 ( V_4 ) ;
V_214 -> V_312 = V_312 ;
V_214 -> V_313 = V_313 ;
V_214 -> V_314 = V_314 ;
V_214 -> V_315 = V_315 ;
V_214 -> V_221 = V_312 ? V_312 : V_314 ;
V_30 = F_112 ( V_1 , V_214 , V_4 ,
V_59 , ( unsigned char * ) V_275 ) ;
break;
case V_320 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_214 = F_111 ( V_4 ) ;
V_30 = F_128 ( V_1 , V_214 , V_4 ,
V_59 , ( unsigned char * ) V_275 ) ;
break;
case V_321 :
V_30 = F_123 ( V_1 , V_59 ,
( unsigned char * ) V_275 ) ;
break;
case V_322 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_30 = F_135 ( V_2 , V_4 ,
( unsigned char * ) V_275 ) ;
break;
case V_318 :
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_30 = F_136 ( V_2 , V_4 , ( unsigned char * ) V_275 ) ;
break;
case V_317 :
if ( F_105 ( V_275 -> V_323 ) != 0xFFFFFFFF )
V_4 = F_137 ( V_2 , V_275 -> V_261 ) ;
else
V_4 = F_109 ( V_2 , V_59 ) ;
if ( ! V_4 )
break;
V_214 = F_111 ( V_4 ) ;
V_30 = F_131 ( V_1 , V_214 , V_4 ,
V_59 , (struct V_308 * ) V_275 ) ;
break;
default:
F_3 ( L_71 , V_210 ) ;
F_126 () ;
break;
}
return V_30 ;
}
static void
F_138 ( struct V_324 * V_325 , const char * type )
{
if ( V_325 -> V_185 != V_326 )
F_3 ( L_72 , type ,
F_139 ( V_325 -> V_185 ) , V_325 -> V_185 ,
V_325 -> V_327 ) ;
else
F_33 ( L_73 , type ,
F_139 ( V_325 -> V_185 ) , V_325 -> V_185 ) ;
}
static void
V_76 ( struct V_328 * V_34 , struct V_324 * V_325 )
{
struct V_1 * V_1 = V_325 -> V_55 -> V_32 ;
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_58 * V_59 = F_140 ( V_325 -> V_197 ) ;
struct V_234 * V_275 = & V_59 -> V_232 ;
struct V_216 * V_216 = & V_59 -> V_215 ;
T_3 V_313 = 0 , V_315 = 0 ;
T_2 V_312 = 0 , V_314 = 0 ;
if ( F_141 ( V_325 -> V_185 != V_329 ) ) {
F_138 ( V_325 , L_74 ) ;
if ( V_325 -> V_185 != V_326 )
F_89 ( V_1 -> V_2 , 0 ) ;
return;
}
F_99 ( V_57 , V_59 -> V_62 ,
V_67 , V_68 ) ;
F_33 ( L_75 ,
V_59 -> V_62 , V_275 -> V_210 , V_275 -> V_261 , V_275 -> V_159 ,
( int ) ( V_325 -> V_330 - V_206 ) ) ;
switch ( V_216 -> V_159 & 0xF0 ) {
case V_217 :
if ( V_216 -> V_159 & V_331 ) {
V_312 = F_105 ( V_216 -> V_312 ) ;
V_313 = F_142 ( V_216 -> V_313 ) ;
F_33 ( L_76 ,
V_312 , ( unsigned long long ) V_313 ) ;
}
if ( V_216 -> V_159 & V_332 ) {
V_314 = F_105 ( V_216 -> V_314 ) ;
V_315 = F_142 ( V_216 -> V_315 ) ;
F_33 ( L_77 ,
V_314 , ( unsigned long long ) V_315 ) ;
}
F_33 ( L_78 ) ;
break;
case V_333 :
F_3 ( L_79 ) ;
break;
default:
F_6 ( L_80 , V_216 -> V_159 ) ;
break;
}
F_134 ( V_1 , V_59 ,
V_312 , V_313 , V_314 , V_315 ) ;
F_96 ( V_57 , V_59 -> V_62 ,
V_67 , V_68 ) ;
}
static void
V_227 ( struct V_328 * V_34 , struct V_324 * V_325 )
{
struct V_1 * V_1 = V_325 -> V_55 -> V_32 ;
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
if ( F_141 ( V_325 -> V_185 != V_329 ) ) {
F_138 ( V_325 , L_81 ) ;
return;
}
F_99 ( V_57 , V_1 -> V_147 ,
V_67 , V_68 ) ;
V_1 -> V_243 = V_325 -> V_330 - V_206 ;
if ( V_1 -> V_2 ) {
struct V_229 * V_230 = V_1 -> V_2 -> V_244 ;
if ( V_230 && ! V_230 -> V_246 )
F_103 ( V_1 ) ;
}
F_8 ( & V_1 -> V_140 ) ;
F_107 ( & V_1 -> V_138 ) ;
F_9 ( & V_1 -> V_140 ) ;
F_96 ( V_57 , V_1 -> V_147 ,
V_67 , V_68 ) ;
}
static int
F_143 ( struct V_1 * V_1 , struct V_214 * V_214 ,
struct V_300 * V_292 , V_130 V_334 , V_130 V_71 , V_130 V_335 ,
enum V_336 V_337 , struct V_338 * V_269 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
V_269 -> V_339 = V_337 == V_340 ?
V_145 : V_68 ;
V_269 -> V_341 = V_71 - V_335 ;
V_269 -> V_335 = V_335 ;
V_269 -> V_305 = V_269 -> V_335 / V_290 ;
V_269 -> V_292 = & V_292 [ V_269 -> V_305 ] ;
V_269 -> V_334 = F_28 (unsigned int, nents - data->sg_off,
ISCSI_ISER_SG_TABLESIZE) ;
V_269 -> V_341 = F_28 (unsigned int, data->len, ISCSI_ISER_SG_TABLESIZE *
PAGE_SIZE) ;
V_269 -> V_342 = F_144 ( V_57 , V_269 -> V_292 , V_269 -> V_334 ,
V_269 -> V_339 ) ;
if ( F_141 ( ! V_269 -> V_342 ) ) {
F_3 ( L_82 , V_292 ) ;
return - V_96 ;
}
F_33 ( L_83 ,
V_214 , V_269 -> V_342 , V_269 -> V_292 , V_269 -> V_334 , V_269 -> V_341 ) ;
return 0 ;
}
static void
F_145 ( struct V_1 * V_1 , struct V_338 * V_269 )
{
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
F_146 ( V_57 , V_269 -> V_292 , V_269 -> V_334 , V_269 -> V_339 ) ;
memset ( V_269 , 0 , sizeof( * V_269 ) ) ;
}
static void
V_94 ( struct V_214 * V_214 , struct V_1 * V_1 )
{
F_33 ( L_84 , V_214 ) ;
if ( V_214 -> V_269 . V_292 ) {
F_33 ( L_85 , V_214 ) ;
F_145 ( V_1 , & V_214 -> V_269 ) ;
}
if ( V_214 -> V_343 ) {
F_33 ( L_86 , V_214 ) ;
F_23 ( V_214 -> V_343 ) ;
V_214 -> V_343 = NULL ;
}
if ( V_214 -> V_60 ) {
F_33 ( L_87 , V_214 ) ;
F_23 ( V_214 -> V_60 ) ;
V_214 -> V_60 = NULL ;
}
}
static void
V_92 ( struct V_214 * V_214 , struct V_1 * V_1 )
{
F_33 ( L_84 , V_214 ) ;
if ( V_214 -> V_102 ) {
F_33 ( L_88 , V_214 , V_214 -> V_102 ) ;
if ( V_214 -> V_102 -> V_117 & V_122 ) {
F_145 ( V_1 , & V_214 -> V_344 ) ;
V_214 -> V_102 -> V_117 &= ~ V_122 ;
}
F_62 ( & V_1 -> V_141 ) ;
F_42 ( & V_214 -> V_102 -> V_105 , & V_1 -> V_104 ) ;
F_63 ( & V_1 -> V_141 ) ;
V_214 -> V_102 = NULL ;
}
if ( V_214 -> V_269 . V_292 ) {
F_33 ( L_85 , V_214 ) ;
F_145 ( V_1 , & V_214 -> V_269 ) ;
}
V_214 -> V_60 = NULL ;
V_214 -> V_343 = NULL ;
}
static void
F_147 ( struct V_214 * V_214 , bool V_345 )
{
struct V_271 * V_4 = V_214 -> V_271 ;
struct V_1 * V_1 = V_214 -> V_2 ;
struct V_228 * V_2 = V_1 -> V_2 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_346 * V_275 ;
F_33 ( L_84 , V_214 ) ;
switch ( V_4 -> V_347 ) {
case V_319 :
F_62 ( & V_2 -> V_348 ) ;
if ( ! F_44 ( & V_4 -> V_349 ) )
F_80 ( & V_4 -> V_349 ) ;
F_63 ( & V_2 -> V_348 ) ;
if ( V_4 -> V_350 == V_145 ) {
F_148 ( V_4 ) ;
if ( V_345 &&
V_4 -> V_3 . V_351 == V_352 ) {
struct V_3 * V_3 = & V_4 -> V_3 ;
F_122 ( V_3 ) ;
}
}
V_17 -> V_91 ( V_214 , V_1 ) ;
F_149 ( & V_4 -> V_3 , 0 ) ;
break;
case V_322 :
F_62 ( & V_2 -> V_348 ) ;
if ( ! F_44 ( & V_4 -> V_349 ) )
F_80 ( & V_4 -> V_349 ) ;
F_63 ( & V_2 -> V_348 ) ;
F_149 ( & V_4 -> V_3 , 0 ) ;
break;
case V_353 :
case V_320 :
case V_317 :
V_275 = (struct V_346 * ) & V_214 -> V_202 . V_232 ;
if ( V_275 -> V_159 & V_354 )
break;
F_62 ( & V_2 -> V_348 ) ;
if ( ! F_44 ( & V_4 -> V_349 ) )
F_80 ( & V_4 -> V_349 ) ;
F_63 ( & V_2 -> V_348 ) ;
if ( V_4 -> V_3 . V_355 != NULL ) {
F_33 ( L_89 ,
V_4 -> V_347 ) ;
F_149 ( & V_4 -> V_3 , 0 ) ;
break;
}
default:
F_150 ( V_4 ) ;
break;
}
}
static void
F_151 ( struct V_201 * V_202 , struct V_42 * V_57 )
{
if ( V_202 -> V_62 != 0 ) {
F_33 ( L_90 ) ;
F_22 ( V_57 , V_202 -> V_62 ,
V_206 , V_145 ) ;
V_202 -> V_62 = 0 ;
}
}
static void
F_152 ( struct V_201 * V_202 , struct V_214 * V_214 ,
struct V_42 * V_57 , bool V_345 )
{
if ( V_214 -> V_356 != 0 ) {
F_33 ( L_91 ) ;
F_22 ( V_57 , V_214 -> V_356 ,
V_214 -> V_357 , V_145 ) ;
V_214 -> V_356 = 0 ;
}
F_151 ( V_202 , V_57 ) ;
F_147 ( V_214 , V_345 ) ;
}
static int
F_153 ( struct V_3 * V_3 , struct V_358 * V_109 )
{
struct V_359 V_360 ;
int V_30 ;
V_30 = F_154 ( V_109 , V_361 , & V_360 ) ;
if ( V_30 ) {
F_3 ( L_92 , V_30 ) ;
goto V_362;
}
if ( V_360 . V_363 & V_361 ) {
T_1 V_364 ;
V_130 V_365 = V_3 -> V_366 -> V_367 . V_365 + 8 ;
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
F_155 ( V_364 , V_365 ) ;
V_3 -> V_378 = V_364 + V_3 -> V_379 ;
F_3 ( L_93
L_94 ,
V_360 . V_368 . V_369 ,
( unsigned long long ) V_3 -> V_378 ,
V_360 . V_368 . V_380 ,
V_360 . V_368 . V_381 ) ;
V_30 = 1 ;
}
V_362:
return V_30 ;
}
static void
F_156 ( struct V_328 * V_34 , struct V_324 * V_325 )
{
struct V_1 * V_1 = V_325 -> V_55 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_201 * V_111 = F_157 ( V_325 -> V_197 ) ;
struct V_214 * V_214 = F_158 ( V_111 ) ;
struct V_3 * V_4 = & V_214 -> V_271 -> V_3 ;
int V_30 = 0 ;
if ( F_141 ( V_325 -> V_185 != V_329 ) ) {
F_138 ( V_325 , L_95 ) ;
if ( V_325 -> V_185 != V_326 )
F_89 ( V_1 -> V_2 , 0 ) ;
F_152 ( V_111 , V_214 , V_17 -> V_42 , true ) ;
return;
}
F_33 ( L_84 , V_214 ) ;
if ( V_214 -> V_102 && V_214 -> V_102 -> V_117 & V_122 ) {
V_30 = F_153 ( V_4 ,
V_214 -> V_102 -> V_107 -> V_109 ) ;
V_214 -> V_102 -> V_117 &= ~ V_122 ;
}
V_17 -> V_91 ( V_214 , V_1 ) ;
V_214 -> V_382 = 0 ;
if ( V_30 )
F_159 ( V_4 , V_4 -> V_371 , 0 ) ;
else
F_160 ( V_1 -> V_2 , V_214 -> V_271 ) ;
}
static void
F_161 ( struct V_328 * V_34 , struct V_324 * V_325 )
{
struct V_1 * V_1 = V_325 -> V_55 -> V_32 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_201 * V_111 = F_157 ( V_325 -> V_197 ) ;
struct V_214 * V_214 = F_158 ( V_111 ) ;
struct V_271 * V_4 = V_214 -> V_271 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
int V_30 = 0 ;
if ( F_141 ( V_325 -> V_185 != V_329 ) ) {
F_138 ( V_325 , L_96 ) ;
if ( V_325 -> V_185 != V_326 )
F_89 ( V_1 -> V_2 , 0 ) ;
F_152 ( V_111 , V_214 , V_17 -> V_42 , true ) ;
return;
}
F_33 ( L_84 , V_214 ) ;
if ( V_214 -> V_102 && V_214 -> V_102 -> V_117 & V_122 ) {
V_30 = F_153 ( V_3 ,
V_214 -> V_102 -> V_107 -> V_109 ) ;
V_214 -> V_102 -> V_117 &= ~ V_122 ;
}
F_148 ( V_4 ) ;
V_17 -> V_91 ( V_214 , V_1 ) ;
V_4 -> V_294 = V_214 -> V_269 . V_341 ;
V_214 -> V_382 = 0 ;
F_33 ( L_97 , V_214 ) ;
F_62 ( & V_4 -> V_295 ) ;
V_4 -> V_296 |= V_297 ;
V_4 -> V_298 = V_299 ;
F_63 ( & V_4 -> V_295 ) ;
if ( V_30 ) {
F_122 ( V_3 ) ;
F_159 ( V_3 ,
V_3 -> V_371 , 0 ) ;
} else {
F_162 ( V_3 ) ;
}
}
static void
F_163 ( struct V_383 * V_384 )
{
struct V_214 * V_214 = F_76 ( V_384 ,
struct V_214 , V_385 ) ;
struct V_1 * V_1 = V_214 -> V_2 ;
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_271 * V_4 = V_214 -> V_271 ;
F_33 ( L_98 , V_214 , V_4 -> V_298 ) ;
switch ( V_4 -> V_298 ) {
case V_386 :
F_164 ( V_4 , V_4 -> V_2 ) ;
case V_387 :
case V_388 :
V_4 -> V_298 = V_389 ;
F_152 ( & V_214 -> V_202 , V_214 ,
V_57 , false ) ;
break;
case V_390 :
F_165 ( V_4 , V_4 -> V_2 ) ;
break;
default:
F_3 ( L_99 , V_4 -> V_298 ) ;
F_126 () ;
break;
}
}
static void
V_208 ( struct V_328 * V_34 , struct V_324 * V_325 )
{
struct V_1 * V_1 = V_325 -> V_55 -> V_32 ;
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_201 * V_202 = F_157 ( V_325 -> V_197 ) ;
if ( F_141 ( V_325 -> V_185 != V_329 ) ) {
F_138 ( V_325 , L_100 ) ;
if ( V_325 -> V_185 != V_326 )
F_89 ( V_1 -> V_2 , 0 ) ;
}
F_151 ( V_202 , V_57 ) ;
}
static void
V_220 ( struct V_328 * V_34 , struct V_324 * V_325 )
{
struct V_1 * V_1 = V_325 -> V_55 -> V_32 ;
struct V_42 * V_57 = V_1 -> V_13 -> V_17 ;
struct V_201 * V_202 = F_157 ( V_325 -> V_197 ) ;
struct V_214 * V_214 = F_158 ( V_202 ) ;
if ( F_141 ( V_325 -> V_185 != V_329 ) ) {
F_138 ( V_325 , L_101 ) ;
if ( V_325 -> V_185 != V_326 )
F_89 ( V_1 -> V_2 , 0 ) ;
F_152 ( V_202 , V_214 , V_57 , true ) ;
return;
}
F_33 ( L_84 , V_214 ) ;
switch ( V_214 -> V_271 -> V_298 ) {
case V_386 :
case V_390 :
case V_387 :
case V_388 :
F_151 ( V_202 , V_57 ) ;
F_57 ( & V_214 -> V_385 , F_163 ) ;
F_81 ( V_391 , & V_214 -> V_385 ) ;
return;
default:
V_214 -> V_271 -> V_298 = V_389 ;
F_152 ( V_202 , V_214 , V_57 , false ) ;
break;
}
}
static int
F_166 ( struct V_1 * V_1 , struct V_214 * V_214 )
{
struct V_203 * V_392 ;
int V_30 ;
V_30 = F_94 ( V_1 , V_214 -> V_59 ) ;
if ( V_30 ) {
F_3 ( L_67 , V_30 ) ;
return V_30 ;
}
V_30 = F_97 ( V_1 -> V_55 , & V_214 -> V_202 . V_204 ,
& V_392 ) ;
if ( V_30 ) {
F_3 ( L_102 , V_30 ) ;
return V_30 ;
}
return V_30 ;
}
static int
F_160 ( struct V_228 * V_2 , struct V_271 * V_4 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_203 * V_204 = & V_214 -> V_202 . V_204 ;
struct V_393 * V_275 = (struct V_393 * )
& V_214 -> V_202 . V_232 ;
F_98 ( V_1 , V_214 , & V_214 -> V_202 ) ;
F_167 ( V_4 , V_2 , true , V_275 ) ;
F_100 ( V_1 , & V_214 -> V_202 ) ;
if ( V_4 -> V_3 . V_394 &&
( ( V_4 -> V_3 . V_287 & V_395 ) ||
( V_4 -> V_3 . V_287 & V_396 ) ) ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_60 * V_235 = & V_214 -> V_202 . V_209 [ 1 ] ;
V_130 V_397 , V_398 ;
F_168 ( V_4 -> V_3 . V_399 ,
V_4 -> V_394 ) ;
V_4 -> V_3 . V_399 += sizeof( V_400 ) ;
V_397 = - ( V_4 -> V_3 . V_399 ) & 3 ;
F_169 ( V_275 -> V_304 , ( V_130 ) V_4 -> V_3 . V_399 ) ;
V_398 = V_4 -> V_3 . V_399 + V_397 ;
V_214 -> V_356 = F_20 ( V_57 ,
( void * ) V_4 -> V_394 , V_398 ,
V_145 ) ;
V_214 -> V_357 = V_398 ;
V_235 -> V_70 = V_214 -> V_356 ;
V_235 -> V_71 = V_398 ;
V_235 -> V_72 = V_17 -> V_54 -> V_73 ;
V_214 -> V_202 . V_199 = 2 ;
}
F_101 ( V_1 , V_214 , V_204 ) ;
F_33 ( L_103 ) ;
return F_166 ( V_1 , V_214 ) ;
}
static void
F_170 ( struct V_228 * V_2 , struct V_271 * V_4 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
F_62 ( & V_2 -> V_348 ) ;
if ( ! F_44 ( & V_4 -> V_349 ) )
F_80 ( & V_4 -> V_349 ) ;
F_63 ( & V_2 -> V_348 ) ;
if ( V_4 -> V_350 == V_145 )
F_148 ( V_4 ) ;
V_17 -> V_91 ( V_214 , V_1 ) ;
}
static enum V_401
F_171 ( struct V_228 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
if ( V_2 -> V_402 -> V_403 . V_404 ) {
if ( V_17 -> V_51 ) {
F_10 ( L_104 , V_1 ) ;
V_1 -> V_5 = true ;
return V_405 ;
}
}
F_10 ( L_105 , V_1 ) ;
V_1 -> V_5 = false ;
return V_7 ;
}
static int
F_172 ( struct V_271 * V_4 , struct V_228 * V_2 ,
bool V_406 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_203 * V_204 = & V_214 -> V_202 . V_204 ;
F_98 ( V_1 , V_214 , & V_214 -> V_202 ) ;
F_173 ( V_4 , V_2 , (struct V_407 * )
& V_214 -> V_202 . V_232 ,
V_406 ) ;
F_100 ( V_1 , & V_214 -> V_202 ) ;
F_101 ( V_1 , V_214 , V_204 ) ;
F_33 ( L_106 , V_1 ) ;
return F_166 ( V_1 , V_214 ) ;
}
static int
F_174 ( struct V_271 * V_4 , struct V_228 * V_2 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_203 * V_204 = & V_214 -> V_202 . V_204 ;
F_98 ( V_1 , V_214 , & V_214 -> V_202 ) ;
F_175 ( V_4 , V_2 , (struct V_408 * )
& V_214 -> V_202 . V_232 ) ;
F_100 ( V_1 , & V_214 -> V_202 ) ;
F_101 ( V_1 , V_214 , V_204 ) ;
F_33 ( L_107 , V_1 ) ;
return F_166 ( V_1 , V_214 ) ;
}
static int
F_176 ( struct V_271 * V_4 , struct V_228 * V_2 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_203 * V_204 = & V_214 -> V_202 . V_204 ;
F_98 ( V_1 , V_214 , & V_214 -> V_202 ) ;
F_177 ( V_4 , V_2 , (struct V_409 * )
& V_214 -> V_202 . V_232 ) ;
F_100 ( V_1 , & V_214 -> V_202 ) ;
F_101 ( V_1 , V_214 , V_204 ) ;
F_33 ( L_108 , V_1 ) ;
return F_166 ( V_1 , V_214 ) ;
}
static int
F_178 ( struct V_271 * V_4 , struct V_228 * V_2 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_203 * V_204 = & V_214 -> V_202 . V_204 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_60 * V_235 = & V_214 -> V_202 . V_209 [ 1 ] ;
struct V_410 * V_275 =
(struct V_410 * ) & V_214 -> V_202 . V_232 ;
F_98 ( V_1 , V_214 , & V_214 -> V_202 ) ;
F_179 ( V_4 , V_2 , V_275 ) ;
F_100 ( V_1 , & V_214 -> V_202 ) ;
F_169 ( V_275 -> V_304 , V_266 ) ;
V_214 -> V_356 = F_20 ( V_57 ,
( void * ) V_4 -> V_411 , V_266 ,
V_145 ) ;
V_214 -> V_357 = V_266 ;
V_235 -> V_70 = V_214 -> V_356 ;
V_235 -> V_71 = V_266 ;
V_235 -> V_72 = V_17 -> V_54 -> V_73 ;
V_214 -> V_202 . V_199 = 2 ;
F_101 ( V_1 , V_214 , V_204 ) ;
F_33 ( L_109 , V_1 ) ;
return F_166 ( V_1 , V_214 ) ;
}
static int
F_180 ( struct V_271 * V_4 , struct V_228 * V_2 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_203 * V_204 = & V_214 -> V_202 . V_204 ;
struct V_346 * V_275 =
(struct V_346 * ) & V_214 -> V_202 . V_232 ;
V_130 V_412 ;
int V_280 ;
F_98 ( V_1 , V_214 , & V_214 -> V_202 ) ;
V_280 = F_181 ( V_4 , V_2 , V_275 , V_413 ) ;
if ( V_280 < 0 )
return V_280 ;
V_412 = V_280 ;
F_100 ( V_1 , & V_214 -> V_202 ) ;
if ( V_412 ) {
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_60 * V_235 = & V_214 -> V_202 . V_209 [ 1 ] ;
void * V_414 = V_4 -> V_411 ;
V_214 -> V_356 = F_20 ( V_57 ,
V_414 , V_412 , V_145 ) ;
V_214 -> V_357 = V_412 ;
V_235 -> V_70 = V_214 -> V_356 ;
V_235 -> V_71 = V_412 ;
V_235 -> V_72 = V_17 -> V_54 -> V_73 ;
V_214 -> V_202 . V_199 = 2 ;
}
F_101 ( V_1 , V_214 , V_204 ) ;
F_33 ( L_110 , V_1 ) ;
return F_166 ( V_1 , V_214 ) ;
}
static int
F_182 ( struct V_1 * V_1 , struct V_214 * V_214 ,
struct V_60 * V_60 , struct V_415 * V_343 ,
V_130 V_416 , V_130 V_335 )
{
struct V_271 * V_4 = V_214 -> V_271 ;
struct V_300 * V_301 , * V_417 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
V_130 V_305 , V_306 ;
int V_19 = 0 , V_279 ;
V_305 = V_335 / V_290 ;
V_301 = & V_4 -> V_3 . V_291 [ V_305 ] ;
V_279 = V_20 ( V_4 -> V_3 . V_293 - V_305 , V_1 -> V_44 ) ;
V_306 = V_335 % V_290 ;
V_343 -> V_418 . V_198 = V_60 ;
V_343 -> V_418 . V_197 = & V_214 -> V_202 . V_207 ;
F_183 (sg_start, tmp_sg, sg_nents, i) {
F_33 ( L_111
L_112 ,
( unsigned long long ) V_417 -> V_419 ,
V_417 -> V_71 , V_306 ) ;
V_60 -> V_70 = F_184 ( V_57 , V_417 ) + V_306 ;
V_60 -> V_71 = F_28 ( V_130 , V_416 ,
F_185 ( V_57 , V_417 ) - V_306 ) ;
V_60 -> V_72 = V_17 -> V_54 -> V_73 ;
F_33 ( L_113 ,
V_60 -> V_70 , V_60 -> V_71 , V_60 -> V_72 ) ;
V_306 = 0 ;
V_416 -= V_60 -> V_71 ;
if ( ! V_416 )
break;
V_60 ++ ;
F_33 ( L_114 , V_60 ) ;
}
V_343 -> V_418 . V_199 = ++ V_19 ;
F_33 ( L_115 ,
V_343 -> V_418 . V_198 , V_343 -> V_418 . V_199 ) ;
return V_343 -> V_418 . V_199 ;
}
static int
V_93 ( struct V_214 * V_214 , struct V_228 * V_2 )
{
struct V_271 * V_4 = V_214 -> V_271 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_338 * V_269 = & V_214 -> V_269 ;
struct V_415 * V_343 ;
struct V_60 * V_60 ;
V_130 V_335 , V_282 , V_416 , V_420 , V_421 = 0 ;
int V_30 = 0 , V_19 , V_422 ;
V_335 = V_214 -> V_218 == V_423 ?
V_4 -> V_294 : 0 ;
V_30 = F_143 ( V_1 , V_214 , V_3 -> V_291 ,
V_3 -> V_293 , V_3 -> V_286 ,
V_335 , V_214 -> V_218 ,
& V_214 -> V_269 ) ;
if ( V_30 )
return V_30 ;
V_416 = V_269 -> V_341 ;
V_335 = V_269 -> V_335 ;
V_60 = F_19 ( sizeof( struct V_60 ) * V_269 -> V_334 , V_65 ) ;
if ( ! V_60 ) {
F_6 ( L_116 ) ;
V_30 = - V_77 ;
goto V_424;
}
V_214 -> V_60 = V_60 ;
V_214 -> V_382 = F_116 ( V_269 -> V_334 , V_1 -> V_44 ) ;
V_214 -> V_343 = F_19 ( sizeof( struct V_415 ) *
V_214 -> V_382 , V_65 ) ;
if ( ! V_214 -> V_343 ) {
F_33 ( L_117 ) ;
V_30 = - V_77 ;
goto V_424;
}
V_420 = V_1 -> V_44 * V_290 ;
for ( V_19 = 0 ; V_19 < V_214 -> V_382 ; V_19 ++ ) {
V_343 = & V_214 -> V_343 [ V_19 ] ;
V_282 = V_20 ( V_416 , V_420 ) ;
V_343 -> V_418 . V_212 = 0 ;
if ( V_214 -> V_218 == V_340 ) {
V_214 -> V_202 . V_207 . V_75 = F_156 ;
V_343 -> V_418 . V_210 = V_425 ;
V_343 -> V_426 = V_214 -> V_313 + V_335 ;
V_343 -> V_427 = V_214 -> V_312 ;
if ( V_19 + 1 == V_214 -> V_382 )
V_343 -> V_418 . V_200 = & V_214 -> V_202 . V_204 ;
else
V_343 -> V_418 . V_200 = & V_214 -> V_343 [ V_19 + 1 ] . V_418 ;
} else {
V_214 -> V_202 . V_207 . V_75 = F_161 ;
V_343 -> V_418 . V_210 = V_428 ;
V_343 -> V_426 = V_214 -> V_315 + V_421 ;
V_343 -> V_427 = V_214 -> V_314 ;
if ( V_19 + 1 == V_214 -> V_382 )
V_343 -> V_418 . V_212 = V_213 ;
else
V_343 -> V_418 . V_200 = & V_214 -> V_343 [ V_19 + 1 ] . V_418 ;
}
V_422 = F_182 ( V_1 , V_214 , V_60 ,
V_343 , V_282 , V_335 ) ;
V_60 += V_422 ;
V_335 += V_282 ;
V_421 += V_282 ;
V_416 -= V_282 ;
}
return 0 ;
V_424:
F_145 ( V_1 , V_269 ) ;
return V_30 ;
}
static inline void
F_186 ( struct V_203 * V_429 , struct V_358 * V_430 )
{
V_130 V_427 ;
memset ( V_429 , 0 , sizeof( * V_429 ) ) ;
V_429 -> V_197 = NULL ;
V_429 -> V_210 = V_431 ;
V_429 -> V_223 . V_224 = V_430 -> V_427 ;
V_427 = F_187 ( V_430 -> V_427 ) ;
F_188 ( V_430 , V_427 ) ;
}
static int
F_189 ( struct V_1 * V_1 ,
struct V_101 * V_102 ,
struct V_338 * V_432 ,
enum V_433 V_117 ,
struct V_60 * V_226 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_42 * V_57 = V_17 -> V_42 ;
struct V_358 * V_430 ;
struct V_434 V_435 ;
struct V_203 V_429 , * V_436 , * V_418 = NULL ;
int V_30 , V_437 ;
if ( V_432 -> V_342 == 1 ) {
V_226 -> V_72 = V_17 -> V_54 -> V_73 ;
V_226 -> V_70 = F_184 ( V_57 , & V_432 -> V_292 [ 0 ] ) ;
V_226 -> V_71 = F_185 ( V_57 , & V_432 -> V_292 [ 0 ] ) ;
F_33 ( L_118 ,
V_226 -> V_70 , V_226 -> V_71 , V_226 -> V_72 ) ;
return 0 ;
}
if ( V_117 == V_123 )
V_430 = V_102 -> V_106 ;
else
V_430 = V_102 -> V_107 -> V_108 ;
if ( ! ( V_102 -> V_117 & V_117 ) ) {
F_186 ( & V_429 , V_430 ) ;
V_418 = & V_429 ;
}
V_437 = F_190 ( V_430 , V_432 -> V_292 , V_432 -> V_334 , V_290 ) ;
if ( F_141 ( V_437 != V_432 -> V_334 ) ) {
F_3 ( L_119 ,
V_437 , V_432 -> V_334 ) ;
return V_437 < 0 ? V_437 : - V_96 ;
}
F_33 ( L_120 ,
V_102 , V_432 -> V_334 , V_432 -> V_335 ) ;
V_435 . V_418 . V_200 = NULL ;
V_435 . V_418 . V_210 = V_438 ;
V_435 . V_418 . V_197 = NULL ;
V_435 . V_418 . V_212 = 0 ;
V_435 . V_418 . V_199 = 0 ;
V_435 . V_430 = V_430 ;
V_435 . V_439 = V_430 -> V_72 ;
V_435 . V_440 = V_441 ;
if ( ! V_418 )
V_418 = & V_435 . V_418 ;
else
V_418 -> V_200 = & V_435 . V_418 ;
V_30 = F_97 ( V_1 -> V_55 , V_418 , & V_436 ) ;
if ( V_30 ) {
F_3 ( L_121 , V_30 ) ;
return V_30 ;
}
V_102 -> V_117 &= ~ V_117 ;
V_226 -> V_72 = V_430 -> V_72 ;
V_226 -> V_70 = V_430 -> V_442 ;
V_226 -> V_71 = V_430 -> V_71 ;
F_33 ( L_118 ,
V_226 -> V_70 , V_226 -> V_71 , V_226 -> V_72 ) ;
return V_30 ;
}
static inline void
F_191 ( struct V_3 * V_3 , struct V_443 * V_444 ,
struct V_445 * V_446 )
{
V_446 -> V_447 = V_448 ;
V_446 -> V_449 . V_450 . V_451 = V_452 ;
V_446 -> V_449 . V_450 . V_453 = V_3 -> V_366 -> V_367 . V_365 ;
V_446 -> V_449 . V_450 . V_454 = V_3 -> V_455 ;
V_446 -> V_449 . V_450 . V_456 = 0xffff ;
V_446 -> V_449 . V_450 . V_457 = true ;
V_446 -> V_449 . V_450 . V_458 = true ;
if ( V_3 -> V_459 == V_460 ||
V_3 -> V_459 == V_461 )
V_446 -> V_449 . V_450 . V_462 = true ;
}
static int
F_192 ( struct V_3 * V_3 , struct V_443 * V_444 )
{
switch ( V_3 -> V_6 ) {
case V_463 :
case V_464 :
V_444 -> V_432 . V_447 = V_465 ;
F_191 ( V_3 , V_444 , & V_444 -> V_466 ) ;
break;
case V_467 :
case V_468 :
V_444 -> V_466 . V_447 = V_465 ;
F_191 ( V_3 , V_444 , & V_444 -> V_432 ) ;
break;
case V_469 :
case V_470 :
F_191 ( V_3 , V_444 , & V_444 -> V_466 ) ;
F_191 ( V_3 , V_444 , & V_444 -> V_432 ) ;
break;
default:
F_3 ( L_122 , V_3 -> V_6 ) ;
return - V_96 ;
}
return 0 ;
}
static inline V_156
F_193 ( V_156 V_471 )
{
return ( V_471 & V_472 ? 0xc0 : 0 ) |
( V_471 & V_473 ? 0x30 : 0 ) |
( V_471 & V_473 ? 0x0f : 0 ) ;
}
static int
F_194 ( struct V_1 * V_1 ,
struct V_214 * V_214 ,
struct V_101 * V_102 )
{
struct V_3 * V_3 = & V_214 -> V_271 -> V_3 ;
struct V_474 V_475 ;
struct V_203 V_429 , * V_436 , * V_418 = NULL ;
struct V_113 * V_107 = V_102 -> V_107 ;
struct V_443 V_444 ;
int V_30 ;
memset ( & V_444 , 0 , sizeof( V_444 ) ) ;
V_30 = F_192 ( V_3 , & V_444 ) ;
if ( V_30 )
goto V_56;
V_444 . V_476 = F_193 ( V_3 -> V_471 ) ;
if ( ! ( V_102 -> V_117 & V_121 ) ) {
F_186 ( & V_429 , V_107 -> V_109 ) ;
V_418 = & V_429 ;
}
memset ( & V_475 , 0 , sizeof( V_475 ) ) ;
V_475 . V_418 . V_210 = V_477 ;
V_475 . V_418 . V_197 = NULL ;
V_475 . V_418 . V_198 = & V_214 -> V_478 [ V_479 ] ;
V_475 . V_418 . V_199 = 1 ;
V_475 . V_480 = V_441 ;
V_475 . V_444 = & V_444 ;
V_475 . V_109 = V_107 -> V_109 ;
if ( V_3 -> V_481 )
V_475 . V_344 = & V_214 -> V_478 [ V_482 ] ;
if ( ! V_418 )
V_418 = & V_475 . V_418 ;
else
V_418 -> V_200 = & V_475 . V_418 ;
V_30 = F_97 ( V_1 -> V_55 , V_418 , & V_436 ) ;
if ( V_30 ) {
F_3 ( L_121 , V_30 ) ;
goto V_56;
}
V_102 -> V_117 &= ~ V_121 ;
V_214 -> V_478 [ V_483 ] . V_72 = V_107 -> V_109 -> V_72 ;
V_214 -> V_478 [ V_483 ] . V_70 = 0 ;
V_214 -> V_478 [ V_483 ] . V_71 = V_3 -> V_286 ;
if ( V_3 -> V_6 != V_468 &&
V_3 -> V_6 != V_467 )
V_214 -> V_478 [ V_483 ] . V_71 += V_3 -> V_484 ;
F_33 ( L_123 ,
V_214 -> V_478 [ V_483 ] . V_70 , V_214 -> V_478 [ V_483 ] . V_71 ,
V_214 -> V_478 [ V_483 ] . V_72 ) ;
V_56:
return V_30 ;
}
static int
F_195 ( struct V_1 * V_1 ,
struct V_214 * V_214 )
{
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_3 * V_3 = & V_214 -> V_271 -> V_3 ;
int V_30 ;
if ( ! V_214 -> V_102 -> V_107 ) {
V_30 = F_47 ( V_214 -> V_102 ,
V_17 -> V_42 ,
V_17 -> V_54 ) ;
if ( V_30 ) {
F_3 ( L_124 ,
V_1 ) ;
return V_30 ;
}
}
if ( V_3 -> V_481 ) {
V_30 = F_143 ( V_1 , V_214 ,
V_3 -> V_481 ,
V_3 -> V_485 ,
V_3 -> V_484 ,
0 ,
V_214 -> V_218 ,
& V_214 -> V_344 ) ;
if ( V_30 ) {
F_3 ( L_125 ,
V_1 ) ;
return V_30 ;
}
memset ( & V_214 -> V_478 [ V_482 ] , 0 , sizeof( V_214 -> V_478 [ V_482 ] ) ) ;
V_30 = F_189 ( V_1 , V_214 -> V_102 ,
& V_214 -> V_344 ,
V_118 ,
& V_214 -> V_478 [ V_482 ] ) ;
if ( V_30 ) {
F_3 ( L_126 ,
V_1 ) ;
goto V_486;
}
}
V_30 = F_194 ( V_1 , V_214 , V_214 -> V_102 ) ;
if ( V_30 ) {
F_3 ( L_126 ,
V_1 ) ;
goto V_486;
}
V_214 -> V_102 -> V_117 |= V_122 ;
return 0 ;
V_486:
if ( V_3 -> V_481 )
F_145 ( V_1 , & V_214 -> V_344 ) ;
return V_30 ;
}
static int
V_90 ( struct V_214 * V_214 , struct V_228 * V_2 )
{
struct V_271 * V_4 = V_214 -> V_271 ;
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_101 * V_102 = NULL ;
struct V_415 * V_343 ;
struct V_60 * V_478 ;
V_130 V_335 ;
int V_30 = 0 ;
unsigned long V_159 ;
V_335 = V_214 -> V_218 == V_423 ?
V_4 -> V_294 : 0 ;
V_30 = F_143 ( V_1 , V_214 , V_3 -> V_291 ,
V_3 -> V_293 , V_3 -> V_286 ,
V_335 , V_214 -> V_218 ,
& V_214 -> V_269 ) ;
if ( V_30 )
return V_30 ;
if ( V_214 -> V_269 . V_342 != 1 ||
F_1 ( V_1 , V_3 ) ) {
F_196 ( & V_1 -> V_141 , V_159 ) ;
V_102 = F_197 ( & V_1 -> V_104 ,
struct V_101 , V_105 ) ;
F_38 ( & V_102 -> V_105 ) ;
F_198 ( & V_1 -> V_141 , V_159 ) ;
V_214 -> V_102 = V_102 ;
}
V_30 = F_189 ( V_1 , V_102 , & V_214 -> V_269 ,
V_123 , & V_214 -> V_478 [ V_479 ] ) ;
if ( V_30 )
goto V_424;
if ( F_1 ( V_1 , V_3 ) ) {
V_30 = F_195 ( V_1 , V_214 ) ;
if ( V_30 )
goto V_424;
V_478 = & V_214 -> V_478 [ V_483 ] ;
} else {
V_478 = & V_214 -> V_478 [ V_479 ] ;
}
memcpy ( & V_214 -> V_487 , V_478 , sizeof( * V_478 ) ) ;
V_214 -> V_60 = & V_214 -> V_487 ;
V_214 -> V_382 = 1 ;
memset ( & V_214 -> V_488 , 0 , sizeof( V_214 -> V_488 ) ) ;
V_214 -> V_343 = & V_214 -> V_488 ;
V_343 = & V_214 -> V_488 ;
V_343 -> V_418 . V_198 = & V_214 -> V_487 ;
V_343 -> V_418 . V_199 = 1 ;
V_343 -> V_418 . V_197 = & V_214 -> V_202 . V_207 ;
if ( V_214 -> V_218 == V_340 ) {
V_214 -> V_202 . V_207 . V_75 = F_156 ;
V_343 -> V_418 . V_210 = V_425 ;
V_343 -> V_426 = V_214 -> V_313 ;
V_343 -> V_427 = V_214 -> V_312 ;
V_343 -> V_418 . V_212 = ! F_1 ( V_1 , V_3 ) ?
0 : V_213 ;
} else {
V_214 -> V_202 . V_207 . V_75 = F_161 ;
V_343 -> V_418 . V_210 = V_428 ;
V_343 -> V_426 = V_214 -> V_315 ;
V_343 -> V_427 = V_214 -> V_314 ;
V_343 -> V_418 . V_212 = V_213 ;
}
return 0 ;
V_424:
if ( V_102 ) {
F_196 ( & V_1 -> V_141 , V_159 ) ;
F_42 ( & V_102 -> V_105 , & V_1 -> V_104 ) ;
F_198 ( & V_1 -> V_141 , V_159 ) ;
}
F_145 ( V_1 , & V_214 -> V_269 ) ;
return V_30 ;
}
static int
F_199 ( struct V_228 * V_2 , struct V_271 * V_4 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_203 * V_392 ;
int V_280 ;
F_33 ( L_127 ,
V_214 , V_3 -> V_286 ) ;
V_214 -> V_218 = V_340 ;
V_280 = V_17 -> V_89 ( V_214 , V_2 ) ;
if ( V_280 ) {
F_3 ( L_128 , V_214 ) ;
return V_280 ;
}
if ( ! F_1 ( V_1 , V_3 ) ) {
F_98 ( V_1 , V_214 ,
& V_214 -> V_202 ) ;
F_167 ( V_4 , V_2 , true , (struct V_393 * )
& V_214 -> V_202 . V_232 ) ;
F_100 ( V_1 , & V_214 -> V_202 ) ;
F_101 ( V_1 , V_214 ,
& V_214 -> V_202 . V_204 ) ;
V_214 -> V_488 . V_418 . V_200 = & V_214 -> V_202 . V_204 ;
V_214 -> V_382 += 1 ;
V_280 = F_94 ( V_1 , V_214 -> V_59 ) ;
if ( V_280 ) {
F_3 ( L_67 , V_280 ) ;
return V_280 ;
}
}
V_280 = F_97 ( V_1 -> V_55 , & V_214 -> V_343 -> V_418 , & V_392 ) ;
if ( V_280 )
F_6 ( L_129 ) ;
if ( ! F_1 ( V_1 , V_3 ) )
F_33 ( L_130
L_131 , V_214 ) ;
else
F_33 ( L_132 ,
V_214 ) ;
return 1 ;
}
static int
F_200 ( struct V_228 * V_2 , struct V_271 * V_4 , bool V_489 )
{
struct V_3 * V_3 = & V_4 -> V_3 ;
struct V_214 * V_214 = F_111 ( V_4 ) ;
struct V_1 * V_1 = V_2 -> V_10 ;
struct V_16 * V_17 = V_1 -> V_17 ;
struct V_203 * V_392 ;
int V_280 ;
F_33 ( L_133 ,
V_214 , V_3 -> V_286 , V_4 -> V_294 ) ;
V_214 -> V_218 = V_423 ;
V_280 = V_17 -> V_89 ( V_214 , V_2 ) ;
if ( V_280 ) {
F_3 ( L_128 , V_214 ) ;
return V_280 ;
}
V_280 = F_97 ( V_1 -> V_55 , & V_214 -> V_343 -> V_418 , & V_392 ) ;
if ( V_280 )
F_6 ( L_134 ) ;
F_33 ( L_135 ,
V_214 ) ;
return 0 ;
}
static int
F_201 ( struct V_228 * V_2 , struct V_271 * V_4 , int V_134 )
{
struct V_214 * V_214 = F_111 ( V_4 ) ;
int V_30 = 0 ;
switch ( V_134 ) {
case V_490 :
F_62 ( & V_2 -> V_348 ) ;
F_80 ( & V_4 -> V_349 ) ;
F_63 ( & V_2 -> V_348 ) ;
F_147 ( V_214 , true ) ;
break;
case V_491 :
V_30 = F_172 ( V_4 , V_2 , false ) ;
break;
default:
F_3 ( L_136 , V_134 ) ;
V_30 = - V_96 ;
break;
}
return V_30 ;
}
static int
F_202 ( struct V_228 * V_2 , struct V_271 * V_4 , int V_134 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
switch ( V_134 ) {
case V_390 :
V_30 = F_174 ( V_4 , V_2 ) ;
if ( ! V_30 )
V_1 -> V_492 = true ;
break;
case V_493 :
V_30 = F_172 ( V_4 , V_2 , true ) ;
break;
case V_386 :
V_30 = F_176 ( V_4 , V_2 ) ;
break;
case V_387 :
V_30 = F_178 ( V_4 , V_2 ) ;
break;
case V_388 :
V_30 = F_180 ( V_4 , V_2 ) ;
break;
case V_494 :
V_30 = F_160 ( V_2 , V_4 ) ;
break;
default:
F_3 ( L_137 , V_134 ) ;
V_30 = - V_96 ;
break;
}
return V_30 ;
}
struct V_26 *
F_86 ( struct V_163 * V_163 )
{
struct V_164 * V_165 = V_163 -> V_165 ;
struct V_26 * V_495 ;
struct V_496 * V_497 ;
int V_30 ;
V_497 = (struct V_496 * ) & V_165 -> V_498 ;
F_33 ( L_138 , & V_165 -> V_498 , V_497 ) ;
V_495 = F_203 ( & V_499 , F_91 , V_163 ,
V_500 , V_50 ) ;
if ( F_16 ( V_495 ) ) {
F_3 ( L_139 , F_17 ( V_495 ) ) ;
V_30 = F_17 ( V_495 ) ;
goto V_95;
}
F_33 ( L_140 , V_495 , V_495 -> V_10 ) ;
V_30 = F_204 ( V_495 , V_497 ) ;
if ( V_30 ) {
F_3 ( L_141 , V_30 ) ;
goto V_501;
}
V_30 = F_205 ( V_495 , 0 ) ;
if ( V_30 ) {
F_3 ( L_142 , V_30 ) ;
goto V_501;
}
return V_495 ;
V_501:
F_69 ( V_495 ) ;
V_95:
return F_14 ( V_30 ) ;
}
static int
F_206 ( struct V_164 * V_165 ,
struct V_502 * V_503 )
{
struct V_163 * V_163 ;
struct V_26 * V_504 ;
int V_30 ;
V_163 = F_19 ( sizeof( struct V_163 ) , V_65 ) ;
if ( ! V_163 ) {
F_3 ( L_143 ) ;
return - V_77 ;
}
F_207 ( & V_163 -> V_174 , 0 ) ;
F_55 ( & V_163 -> V_140 ) ;
F_41 ( & V_163 -> V_170 ) ;
F_41 ( & V_163 -> V_173 ) ;
V_163 -> V_165 = V_165 ;
memcpy ( & V_165 -> V_498 , V_503 ,
sizeof( struct V_502 ) ) ;
V_504 = F_86 ( V_163 ) ;
if ( F_16 ( V_504 ) ) {
V_30 = F_17 ( V_504 ) ;
goto V_95;
}
V_163 -> V_13 = V_504 ;
V_165 -> V_505 = V_163 ;
return 0 ;
V_95:
F_23 ( V_163 ) ;
return V_30 ;
}
static int
F_66 ( struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_152 V_506 ;
int V_30 ;
struct V_507 V_508 ;
memset ( & V_506 , 0 , sizeof( struct V_152 ) ) ;
V_506 . V_155 = V_1 -> V_155 ;
V_506 . V_509 = 7 ;
V_506 . V_510 = 7 ;
memset ( & V_508 , 0 , sizeof( V_508 ) ) ;
V_508 . V_159 = V_511 ;
if ( ! V_1 -> V_160 )
V_508 . V_159 = V_508 . V_159 | V_512 ;
V_506 . V_158 = ( void * ) & V_508 ;
V_506 . V_513 = sizeof( V_508 ) ;
V_30 = F_208 ( V_13 , & V_506 ) ;
if ( V_30 ) {
F_3 ( L_144 , V_30 ) ;
return V_30 ;
}
return 0 ;
}
static int
F_209 ( struct V_228 * V_2 , struct V_229 * V_230 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
int V_30 ;
F_10 ( L_145 , V_1 ) ;
V_30 = F_210 ( & V_1 -> V_138 ) ;
if ( V_30 ) {
F_3 ( L_146 ,
V_1 ) ;
return V_30 ;
}
F_211 ( & V_1 -> V_138 ) ;
if ( ! V_230 -> V_246 )
return 0 ;
F_103 ( V_1 ) ;
F_10 ( L_147 , V_2 ) ;
V_30 = F_210 ( & V_1 -> V_137 ) ;
if ( V_30 )
return V_30 ;
F_10 ( L_148 , V_230 -> V_265 ) ;
return 0 ;
}
static void
F_212 ( struct V_164 * V_165 , struct V_228 * V_2 ,
struct V_1 * V_1 )
{
struct V_26 * V_13 = V_1 -> V_13 ;
struct V_514 * V_515 = & V_13 -> V_516 ;
V_2 -> V_517 = V_165 -> V_498 . V_518 ;
V_2 -> V_519 = V_515 -> V_70 . V_520 ;
V_2 -> V_521 = V_515 -> V_70 . V_522 ;
}
static int
F_213 ( struct V_164 * V_165 , struct V_228 * V_2 )
{
struct V_163 * V_163 = V_165 -> V_505 ;
struct V_1 * V_1 ;
int V_30 ;
V_523:
V_30 = F_214 ( & V_163 -> V_174 ) ;
if ( V_30 )
return - V_524 ;
F_62 ( & V_165 -> V_166 ) ;
if ( V_165 -> V_525 >= V_526 ) {
F_63 ( & V_165 -> V_166 ) ;
F_33 ( L_149 ,
V_165 -> V_525 ) ;
return - V_524 ;
}
F_63 ( & V_165 -> V_166 ) ;
F_8 ( & V_163 -> V_140 ) ;
if ( F_44 ( & V_163 -> V_173 ) ) {
F_9 ( & V_163 -> V_140 ) ;
goto V_523;
}
V_1 = F_197 ( & V_163 -> V_173 ,
struct V_1 , V_136 ) ;
F_80 ( & V_1 -> V_136 ) ;
F_9 ( & V_163 -> V_140 ) ;
V_2 -> V_10 = V_1 ;
V_1 -> V_2 = V_2 ;
V_1 -> V_134 = V_183 ;
F_212 ( V_165 , V_2 , V_1 ) ;
F_33 ( L_150 , V_1 ) ;
return 0 ;
}
static void
F_215 ( struct V_164 * V_165 )
{
struct V_163 * V_163 = V_165 -> V_505 ;
struct V_1 * V_1 , * V_437 ;
if ( V_163 -> V_13 )
F_69 ( V_163 -> V_13 ) ;
F_8 ( & V_163 -> V_140 ) ;
if ( ! F_44 ( & V_163 -> V_173 ) ) {
F_10 ( L_151 ) ;
F_45 (isert_conn, n,
&isert_np->pending,
node) {
F_10 ( L_152 ,
V_1 , V_1 -> V_134 ) ;
F_67 ( V_1 ) ;
}
}
if ( ! F_44 ( & V_163 -> V_170 ) ) {
F_10 ( L_153 ) ;
F_45 (isert_conn, n,
&isert_np->accepted,
node) {
F_10 ( L_152 ,
V_1 , V_1 -> V_134 ) ;
F_67 ( V_1 ) ;
}
}
F_9 ( & V_163 -> V_140 ) ;
V_165 -> V_505 = NULL ;
F_23 ( V_163 ) ;
}
static void V_143 ( struct V_383 * V_384 )
{
struct V_1 * V_1 = F_76 ( V_384 ,
struct V_1 ,
V_142 ) ;
F_10 ( L_154 , V_1 ) ;
F_8 ( & V_1 -> V_140 ) ;
V_1 -> V_134 = V_527 ;
F_9 ( & V_1 -> V_140 ) ;
F_10 ( L_155 , V_1 ) ;
F_77 ( V_1 ) ;
}
static void
F_216 ( struct V_1 * V_1 )
{
struct V_228 * V_2 = V_1 -> V_2 ;
F_10 ( L_35 , V_1 ) ;
if ( V_1 -> V_492 ) {
F_10 ( L_156 , V_1 ) ;
F_217 ( & V_2 -> V_528 ,
V_529 * V_530 ) ;
}
}
static void
F_218 ( struct V_228 * V_2 )
{
F_10 ( L_157 , V_2 ) ;
if ( V_2 -> V_126 ) {
F_219 ( V_2 -> V_126 -> V_125 ) ;
F_220 ( V_2 -> V_126 -> V_125 ) ;
}
}
static void
F_221 ( struct V_228 * V_2 )
{
struct V_271 * V_4 , * V_103 ;
static F_222 ( V_531 ) ;
F_62 ( & V_2 -> V_348 ) ;
F_45 (cmd, tmp, &conn->conn_cmd_list, i_conn_node) {
if ( ( V_4 -> V_296 & V_532 ) &&
( V_4 -> V_294 < V_2 -> V_126 -> V_239 -> V_533 ) &&
( V_4 -> V_294 < V_4 -> V_3 . V_286 ) )
F_73 ( & V_4 -> V_349 , & V_531 ) ;
}
F_63 ( & V_2 -> V_348 ) ;
F_45 (cmd, tmp, &drop_cmd_list, i_conn_node) {
F_80 ( & V_4 -> V_349 ) ;
if ( V_4 -> V_298 != V_490 ) {
struct V_214 * V_214 = F_111 ( V_4 ) ;
F_10 ( L_158 , V_2 , V_4 ) ;
F_147 ( V_214 , true ) ;
}
}
}
static void F_223 ( struct V_228 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_10 ( L_159 , V_1 ) ;
F_8 ( & V_1 -> V_140 ) ;
F_82 ( V_1 ) ;
F_9 ( & V_1 -> V_140 ) ;
F_88 ( V_1 -> V_55 ) ;
F_221 ( V_2 ) ;
F_218 ( V_2 ) ;
F_216 ( V_1 ) ;
F_81 ( V_178 , & V_1 -> V_142 ) ;
}
static void F_224 ( struct V_228 * V_2 )
{
struct V_1 * V_1 = V_2 -> V_10 ;
F_88 ( V_1 -> V_55 ) ;
F_77 ( V_1 ) ;
}
static int T_4 F_225 ( void )
{
int V_30 ;
V_391 = F_226 ( L_160 ,
V_534 | V_535 , 0 ) ;
if ( ! V_391 ) {
F_3 ( L_161 ) ;
V_30 = - V_77 ;
return - V_77 ;
}
V_178 = F_226 ( L_162 , V_534 ,
V_536 ) ;
if ( ! V_178 ) {
F_3 ( L_163 ) ;
V_30 = - V_77 ;
goto V_537;
}
F_227 ( & V_538 ) ;
F_10 ( L_164 ) ;
return 0 ;
V_537:
F_228 ( V_391 ) ;
return V_30 ;
}
static void T_5 F_229 ( void )
{
F_230 () ;
F_228 ( V_178 ) ;
F_228 ( V_391 ) ;
F_231 ( & V_538 ) ;
F_10 ( L_165 ) ;
}
