static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
F_2 ( L_1 ,
F_3 ( V_2 -> V_4 ) , V_2 -> V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_1 * V_4 )
{
F_2 ( L_2 ,
F_3 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_7 -> V_8 , V_4 -> V_9 . V_10 ) ;
}
static int F_5 ( struct V_11 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_12 ;
int V_14 , V_15 , V_16 ;
V_14 = F_6 ( V_7 ) ;
if ( V_14 )
return V_14 ;
V_7 -> V_17 = F_7 ( int , F_8 () ,
V_13 -> V_18 ) ;
V_7 -> V_19 = F_9 ( V_7 -> V_17 , sizeof( * V_7 -> V_19 ) ,
V_20 ) ;
if ( ! V_7 -> V_19 )
goto V_21;
V_16 = F_10 ( V_22 , V_13 -> V_23 . V_16 ) ;
F_11 ( L_3 ,
V_7 -> V_17 , V_13 -> V_8 ,
V_13 -> V_18 , V_16 ) ;
V_7 -> V_24 = F_12 ( V_13 ,
V_25 ? 0 : V_26 ) ;
if ( F_13 ( V_7 -> V_24 ) )
goto V_27;
for ( V_15 = 0 ; V_15 < V_7 -> V_17 ; V_15 ++ ) {
struct V_28 * V_29 = & V_7 -> V_19 [ V_15 ] ;
V_29 -> V_30 = F_14 ( V_13 , V_29 , V_16 , V_15 ,
V_31 ) ;
if ( F_13 ( V_29 -> V_30 ) ) {
V_29 -> V_30 = NULL ;
goto V_32;
}
}
F_15 ( & V_7 -> V_33 , V_13 ,
F_4 ) ;
F_16 ( & V_7 -> V_33 ) ;
return 0 ;
V_32:
for ( V_15 = 0 ; V_15 < V_7 -> V_17 ; V_15 ++ ) {
struct V_28 * V_29 = & V_7 -> V_19 [ V_15 ] ;
if ( V_29 -> V_30 )
F_17 ( V_29 -> V_30 ) ;
}
F_18 ( V_7 -> V_24 ) ;
V_27:
F_19 ( V_7 -> V_19 ) ;
V_21:
F_2 ( L_4 ) ;
return - 1 ;
}
static void F_20 ( struct V_11 * V_7 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_17 ; V_15 ++ ) {
struct V_28 * V_29 = & V_7 -> V_19 [ V_15 ] ;
F_17 ( V_29 -> V_30 ) ;
V_29 -> V_30 = NULL ;
}
F_21 ( & V_7 -> V_33 ) ;
F_18 ( V_7 -> V_24 ) ;
F_19 ( V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_24 = NULL ;
}
int F_22 ( struct V_34 * V_34 ,
unsigned V_35 ,
unsigned int V_36 )
{
struct V_11 * V_7 = V_34 -> V_7 ;
struct V_37 * V_38 = & V_34 -> V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
int V_14 ;
F_23 ( & V_38 -> V_47 ) ;
F_24 ( & V_38 -> V_48 ) ;
V_42 = F_25 ( sizeof( * V_42 ) , V_20 ) ;
if ( ! V_42 )
return - V_49 ;
V_40 = F_26 ( sizeof( * V_40 ) + ( sizeof( V_50 ) * V_36 ) ,
V_20 ) ;
if ( ! V_40 ) {
V_14 = - V_49 ;
goto V_51;
}
V_40 -> V_52 = ( V_50 * ) ( V_40 + 1 ) ;
V_46 . V_53 = V_54 ;
V_46 . V_55 = V_36 ;
V_46 . V_56 = V_35 * 2 ;
V_46 . V_57 = V_35 ;
V_46 . V_58 = 0 ;
V_46 . V_59 = NULL ;
V_46 . V_60 = ( V_61 |
V_62 |
V_63 ) ;
V_44 = F_27 ( V_7 -> V_24 , & V_46 ) ;
if ( F_13 ( V_44 ) ) {
V_14 = F_28 ( V_44 ) ;
F_2 ( L_5 , V_14 ) ;
goto V_64;
}
V_42 -> V_65 . V_40 = V_40 ;
V_42 -> V_65 . V_44 = V_44 ;
F_29 ( & V_42 -> V_47 , & V_38 -> V_47 ) ;
return 0 ;
V_64:
F_19 ( V_40 ) ;
V_51:
F_19 ( V_42 ) ;
return V_14 ;
}
void F_30 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = & V_34 -> V_38 ;
struct V_41 * V_42 ;
V_42 = F_31 ( & V_38 -> V_47 ,
struct V_41 , V_47 ) ;
F_32 ( & V_42 -> V_47 ) ;
F_11 ( L_6 ,
V_34 , V_42 -> V_65 . V_44 ) ;
F_33 ( V_42 -> V_65 . V_44 ) ;
F_19 ( V_42 -> V_65 . V_40 ) ;
F_19 ( V_42 ) ;
}
static int
F_34 ( struct V_11 * V_7 ,
struct V_66 * V_24 ,
struct V_67 * V_68 ,
unsigned int V_36 )
{
struct V_12 * V_13 = V_7 -> V_12 ;
enum V_69 V_70 ;
int V_14 ;
if ( V_13 -> V_23 . V_71 & V_72 )
V_70 = V_73 ;
else
V_70 = V_74 ;
V_68 -> V_75 = F_35 ( V_24 , V_70 , V_36 ) ;
if ( F_13 ( V_68 -> V_75 ) ) {
V_14 = F_28 ( V_68 -> V_75 ) ;
F_2 ( L_7 , V_14 ) ;
return V_14 ;
}
V_68 -> V_76 = 0 ;
return 0 ;
}
static void
F_36 ( struct V_67 * V_65 )
{
F_37 ( V_65 -> V_75 ) ;
}
static int
F_38 ( struct V_11 * V_7 ,
struct V_66 * V_24 ,
struct V_41 * V_42 ,
unsigned int V_36 )
{
struct V_77 * V_78 = NULL ;
int V_14 ;
V_42 -> V_78 = F_25 ( sizeof( * V_42 -> V_78 ) , V_20 ) ;
if ( ! V_42 -> V_78 )
return - V_49 ;
V_78 = V_42 -> V_78 ;
V_14 = F_34 ( V_7 , V_24 , & V_78 -> V_65 , V_36 ) ;
if ( V_14 ) {
F_2 ( L_8 ) ;
goto V_79;
}
V_78 -> V_80 = F_35 ( V_24 , V_81 , 2 ) ;
if ( F_13 ( V_78 -> V_80 ) ) {
V_14 = F_28 ( V_78 -> V_80 ) ;
goto V_82;
}
V_78 -> V_83 = 0 ;
V_42 -> V_78 -> V_84 = 0 ;
return 0 ;
V_82:
F_36 ( & V_78 -> V_65 ) ;
V_79:
F_19 ( V_42 -> V_78 ) ;
return V_14 ;
}
static void
F_39 ( struct V_77 * V_78 )
{
F_36 ( & V_78 -> V_65 ) ;
F_37 ( V_78 -> V_80 ) ;
F_19 ( V_78 ) ;
}
static struct V_41 *
F_40 ( struct V_11 * V_7 ,
struct V_66 * V_24 ,
bool V_85 ,
unsigned int V_36 )
{
struct V_41 * V_42 ;
int V_14 ;
V_42 = F_25 ( sizeof( * V_42 ) , V_20 ) ;
if ( ! V_42 )
return F_41 ( - V_49 ) ;
V_14 = F_34 ( V_7 , V_24 , & V_42 -> V_65 , V_36 ) ;
if ( V_14 )
goto V_86;
if ( V_85 ) {
V_14 = F_38 ( V_7 , V_24 , V_42 , V_36 ) ;
if ( V_14 )
goto V_87;
}
return V_42 ;
V_87:
F_36 ( & V_42 -> V_65 ) ;
V_86:
F_19 ( V_42 ) ;
return F_41 ( V_14 ) ;
}
int F_42 ( struct V_34 * V_34 ,
unsigned V_35 ,
unsigned int V_36 )
{
struct V_11 * V_7 = V_34 -> V_7 ;
struct V_37 * V_38 = & V_34 -> V_38 ;
struct V_41 * V_42 ;
int V_15 , V_14 ;
F_23 ( & V_38 -> V_47 ) ;
F_23 ( & V_38 -> V_88 ) ;
F_24 ( & V_38 -> V_48 ) ;
V_38 -> V_36 = 0 ;
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
V_42 = F_40 ( V_7 , V_7 -> V_24 ,
V_34 -> V_89 , V_36 ) ;
if ( F_13 ( V_42 ) ) {
V_14 = F_28 ( V_42 ) ;
goto V_90;
}
F_43 ( & V_42 -> V_47 , & V_38 -> V_47 ) ;
F_43 ( & V_42 -> V_88 , & V_38 -> V_88 ) ;
V_38 -> V_36 ++ ;
}
return 0 ;
V_90:
F_44 ( V_34 ) ;
return V_14 ;
}
void F_44 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = & V_34 -> V_38 ;
struct V_41 * V_42 , * V_91 ;
int V_15 = 0 ;
if ( F_45 ( & V_38 -> V_88 ) )
return;
F_11 ( L_9 , V_34 ) ;
F_46 (desc, tmp, &fr_pool->all_list, all_list) {
F_32 ( & V_42 -> V_88 ) ;
F_36 ( & V_42 -> V_65 ) ;
if ( V_42 -> V_78 )
F_39 ( V_42 -> V_78 ) ;
F_19 ( V_42 ) ;
++ V_15 ;
}
if ( V_15 < V_38 -> V_36 )
F_47 ( L_10 ,
V_38 -> V_36 - V_15 ) ;
}
static int F_48 ( struct V_34 * V_34 )
{
struct V_92 * V_92 = F_49 ( V_34 ) ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_93 V_94 ;
int V_14 = - V_49 ;
int V_95 , V_96 = 0 ;
F_50 ( V_34 -> V_7 == NULL ) ;
V_7 = V_34 -> V_7 ;
V_13 = V_7 -> V_12 ;
memset ( & V_94 , 0 , sizeof V_94 ) ;
F_51 ( & V_97 . V_98 ) ;
for ( V_95 = 0 ; V_95 < V_7 -> V_17 ; V_95 ++ ) {
if ( V_7 -> V_19 [ V_95 ] . V_99 <
V_7 -> V_19 [ V_96 ] . V_99 )
V_96 = V_95 ;
}
V_34 -> V_29 = & V_7 -> V_19 [ V_96 ] ;
V_34 -> V_29 -> V_99 ++ ;
F_52 ( & V_97 . V_98 ) ;
F_11 ( L_11 , V_96 , V_34 ) ;
V_94 . V_33 = F_1 ;
V_94 . V_100 = ( void * ) V_34 ;
V_94 . V_101 = V_34 -> V_29 -> V_30 ;
V_94 . V_102 = V_34 -> V_29 -> V_30 ;
V_94 . V_103 . V_104 = V_105 ;
V_94 . V_103 . V_106 = 2 ;
V_94 . V_103 . V_107 = 1 ;
V_94 . V_108 = V_109 ;
V_94 . V_110 = V_111 ;
if ( V_34 -> V_89 ) {
V_94 . V_103 . V_112 = V_113 + 1 ;
V_94 . V_114 |= V_115 ;
V_92 -> V_116 =
F_53 ( V_113 ) ;
} else {
if ( V_13 -> V_23 . V_117 > V_118 ) {
V_94 . V_103 . V_112 = V_118 + 1 ;
V_92 -> V_116 =
F_53 ( V_118 ) ;
} else {
V_94 . V_103 . V_112 = V_13 -> V_23 . V_117 ;
V_92 -> V_116 =
F_53 ( V_13 -> V_23 . V_117 ) ;
F_54 ( L_12 ,
V_7 -> V_12 -> V_8 , V_13 -> V_23 . V_117 ) ;
}
}
V_14 = F_55 ( V_34 -> V_119 , V_7 -> V_24 , & V_94 ) ;
if ( V_14 )
goto V_120;
V_34 -> V_121 = V_34 -> V_119 -> V_121 ;
F_11 ( L_13 ,
V_34 , V_34 -> V_119 ,
V_34 -> V_119 -> V_121 ) ;
return V_14 ;
V_120:
F_51 ( & V_97 . V_98 ) ;
V_34 -> V_29 -> V_99 -- ;
F_52 ( & V_97 . V_98 ) ;
F_2 ( L_14 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_56 ( struct V_122 * V_119 )
{
struct V_11 * V_7 ;
F_51 ( & V_97 . V_123 ) ;
F_57 (device, &ig.device_list, ig_list)
if ( V_7 -> V_12 -> V_124 == V_119 -> V_7 -> V_124 )
goto V_125;
V_7 = F_25 ( sizeof *V_7 , V_20 ) ;
if ( V_7 == NULL )
goto V_126;
V_7 -> V_12 = V_119 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_19 ( V_7 ) ;
V_7 = NULL ;
goto V_126;
}
F_29 ( & V_7 -> V_127 , & V_97 . V_128 ) ;
V_125:
V_7 -> V_129 ++ ;
V_126:
F_52 ( & V_97 . V_123 ) ;
return V_7 ;
}
static void F_58 ( struct V_11 * V_7 )
{
F_51 ( & V_97 . V_123 ) ;
V_7 -> V_129 -- ;
F_11 ( L_15 , V_7 , V_7 -> V_129 ) ;
if ( ! V_7 -> V_129 ) {
F_20 ( V_7 ) ;
F_32 ( & V_7 -> V_127 ) ;
F_19 ( V_7 ) ;
}
F_52 ( & V_97 . V_123 ) ;
}
static int F_59 ( struct V_92 * V_92 ,
enum V_130 V_29 ,
enum V_130 V_131 )
{
int V_14 ;
V_14 = ( V_92 -> V_132 == V_29 ) ;
if ( V_14 )
V_92 -> V_132 = V_131 ;
return V_14 ;
}
void F_60 ( struct V_133 * V_134 )
{
struct V_92 * V_92 ;
V_92 = F_61 ( V_134 , struct V_92 , V_135 ) ;
F_62 ( & V_92 -> V_136 ) ;
F_62 ( & V_92 -> V_137 ) ;
F_51 ( & V_92 -> V_138 ) ;
V_92 -> V_132 = V_139 ;
F_52 ( & V_92 -> V_138 ) ;
F_63 ( V_92 ) ;
}
static void F_64 ( struct V_92 * V_92 ,
bool V_140 )
{
struct V_34 * V_34 = & V_92 -> V_34 ;
struct V_11 * V_7 = V_34 -> V_7 ;
F_11 ( L_16 ,
V_92 , V_34 -> V_119 , V_34 -> V_121 ) ;
if ( V_34 -> V_121 != NULL ) {
F_51 ( & V_97 . V_98 ) ;
V_34 -> V_29 -> V_99 -- ;
F_52 ( & V_97 . V_98 ) ;
F_65 ( V_34 -> V_119 ) ;
V_34 -> V_121 = NULL ;
}
if ( V_140 ) {
if ( V_92 -> V_141 )
F_66 ( V_92 ) ;
if ( V_7 != NULL ) {
F_58 ( V_7 ) ;
V_34 -> V_7 = NULL ;
}
}
}
void F_63 ( struct V_92 * V_92 )
{
struct V_34 * V_34 = & V_92 -> V_34 ;
F_51 ( & V_97 . V_98 ) ;
F_32 ( & V_92 -> V_142 ) ;
F_52 ( & V_97 . V_98 ) ;
F_51 ( & V_92 -> V_138 ) ;
if ( V_92 -> V_132 != V_139 ) {
F_47 ( L_17 ,
V_92 , V_92 -> V_132 ) ;
F_67 ( V_92 -> V_143 ) ;
V_92 -> V_132 = V_139 ;
}
F_64 ( V_92 , true ) ;
F_52 ( & V_92 -> V_138 ) ;
if ( V_34 -> V_119 != NULL ) {
F_68 ( V_34 -> V_119 ) ;
V_34 -> V_119 = NULL ;
}
F_19 ( V_92 ) ;
}
int F_69 ( struct V_92 * V_92 )
{
struct V_34 * V_34 = & V_92 -> V_34 ;
int V_90 = 0 ;
if ( ! F_59 ( V_92 , V_144 ,
V_145 ) )
return 0 ;
F_11 ( L_18 , V_92 , V_92 -> V_132 ) ;
if ( V_92 -> V_146 )
F_70 ( V_92 -> V_146 ) ;
if ( V_34 -> V_119 ) {
V_90 = F_71 ( V_34 -> V_119 ) ;
if ( V_90 )
F_2 ( L_19 ,
V_92 , V_90 ) ;
F_72 ( V_34 -> V_121 ) ;
}
return 1 ;
}
static void F_73 ( struct V_122 * V_119 )
{
struct V_92 * V_92 ;
V_92 = (struct V_92 * ) V_119 -> V_3 ;
V_92 -> V_132 = V_145 ;
}
static void
F_74 ( struct V_92 * V_92 ,
unsigned int V_147 )
{
struct V_11 * V_7 = V_92 -> V_34 . V_7 ;
unsigned short V_148 , V_149 ;
V_148 = F_75 ( V_147 * 512 , V_150 ) ;
if ( V_7 -> V_12 -> V_23 . V_71 &
V_151 )
V_149 =
F_7 (
V_152 , V_153 ,
V_7 -> V_12 -> V_23 . V_154 ) ;
else
V_149 = V_153 ;
V_92 -> V_155 = F_10 ( V_148 , V_149 ) ;
}
static void F_76 ( struct V_122 * V_119 )
{
struct V_11 * V_7 ;
struct V_92 * V_92 ;
struct V_34 * V_34 ;
int V_14 ;
V_92 = (struct V_92 * ) V_119 -> V_3 ;
if ( V_92 -> V_132 != V_156 )
return;
V_34 = & V_92 -> V_34 ;
V_7 = F_56 ( V_119 ) ;
if ( ! V_7 ) {
F_2 ( L_20 ) ;
F_73 ( V_119 ) ;
return;
}
V_34 -> V_7 = V_7 ;
if ( V_157 ) {
if ( ! ( V_7 -> V_12 -> V_23 . V_71 &
V_158 ) ) {
F_47 ( L_21
L_22 ,
V_34 -> V_7 -> V_12 -> V_8 ) ;
V_34 -> V_89 = false ;
} else {
V_34 -> V_89 = true ;
}
}
F_74 ( V_92 , V_159 ) ;
V_14 = F_77 ( V_119 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_23 , V_14 ) ;
F_73 ( V_119 ) ;
return;
}
}
static void F_78 ( struct V_122 * V_119 )
{
struct V_160 V_161 ;
int V_14 ;
struct V_162 V_163 ;
struct V_92 * V_92 = (struct V_92 * ) V_119 -> V_3 ;
struct V_34 * V_34 = & V_92 -> V_34 ;
struct V_11 * V_7 = V_34 -> V_7 ;
if ( V_92 -> V_132 != V_156 )
return;
V_14 = F_48 ( V_34 ) ;
if ( V_14 )
goto V_164;
memset ( & V_161 , 0 , sizeof V_161 ) ;
V_161 . V_165 = V_7 -> V_12 -> V_23 . V_166 ;
V_161 . V_167 = 1 ;
V_161 . V_168 = 7 ;
V_161 . V_169 = 6 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_170 = V_171 ;
if ( ! V_7 -> V_172 )
V_163 . V_170 |= V_173 ;
V_161 . V_174 = ( void * ) & V_163 ;
V_161 . V_175 = sizeof( struct V_162 ) ;
V_14 = F_79 ( V_119 , & V_161 ) ;
if ( V_14 ) {
F_2 ( L_24 , V_14 ) ;
goto V_164;
}
return;
V_164:
F_73 ( V_119 ) ;
}
static void F_80 ( struct V_122 * V_119 ,
const void * V_174 )
{
struct V_92 * V_92 ;
struct V_176 V_177 ;
struct V_93 V_94 ;
V_92 = (struct V_92 * ) V_119 -> V_3 ;
if ( V_92 -> V_132 != V_156 )
return;
( void ) F_81 ( V_119 -> V_121 , & V_177 , ~ 0 , & V_94 ) ;
F_11 ( L_25 , V_177 . V_178 , V_119 -> V_121 -> V_179 ) ;
if ( V_174 ) {
T_1 V_170 = * ( T_1 * ) V_174 ;
V_92 -> V_180 = ! ( V_170 & V_173 ) ;
}
F_11 ( L_26 ,
V_92 , V_92 -> V_180 ? L_27 : L_28 ) ;
V_92 -> V_132 = V_144 ;
F_82 ( & V_92 -> V_181 ) ;
}
static void F_83 ( struct V_122 * V_119 )
{
struct V_92 * V_92 = (struct V_92 * ) V_119 -> V_3 ;
if ( F_69 ( V_92 ) ) {
if ( V_92 -> V_146 )
F_84 ( V_92 -> V_146 ,
V_182 ) ;
else
F_2 ( L_29 ) ;
}
}
static void F_85 ( struct V_122 * V_119 ,
bool V_140 )
{
struct V_92 * V_92 = (struct V_92 * ) V_119 -> V_3 ;
F_83 ( V_119 ) ;
F_64 ( V_92 , V_140 ) ;
F_82 ( & V_92 -> V_137 ) ;
}
static int F_86 ( struct V_122 * V_119 , struct V_183 * V_4 )
{
struct V_92 * V_92 ;
int V_14 = 0 ;
V_92 = (struct V_92 * ) V_119 -> V_3 ;
F_11 ( L_30 ,
F_87 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_184 , V_119 -> V_3 , V_119 ) ;
F_51 ( & V_92 -> V_138 ) ;
switch ( V_4 -> V_4 ) {
case V_185 :
F_76 ( V_119 ) ;
break;
case V_186 :
F_78 ( V_119 ) ;
break;
case V_187 :
F_80 ( V_119 , V_4 -> V_188 . V_189 . V_174 ) ;
break;
case V_190 :
F_11 ( L_31 ,
F_88 ( V_119 , V_4 -> V_184 ) ) ;
case V_191 :
case V_192 :
case V_193 :
case V_194 :
F_73 ( V_119 ) ;
break;
case V_195 :
case V_196 :
case V_197 :
F_85 ( V_119 , false ) ;
break;
case V_198 :
F_85 ( V_119 , true ) ;
if ( V_92 -> V_132 != V_139 ) {
V_92 -> V_34 . V_119 = NULL ;
V_14 = 1 ;
}
break;
default:
F_2 ( L_32 ,
F_87 ( V_4 -> V_4 ) , V_4 -> V_4 ) ;
break;
}
F_52 ( & V_92 -> V_138 ) ;
return V_14 ;
}
void F_89 ( struct V_92 * V_92 )
{
struct V_34 * V_34 = & V_92 -> V_34 ;
V_92 -> V_132 = V_199 ;
F_90 ( & V_92 -> V_136 ) ;
F_90 ( & V_92 -> V_137 ) ;
F_90 ( & V_92 -> V_181 ) ;
F_23 ( & V_92 -> V_142 ) ;
F_91 ( & V_92 -> V_138 ) ;
V_34 -> V_200 = 0 ;
V_34 -> V_201 . V_202 = V_203 ;
}
int F_92 ( struct V_92 * V_92 ,
struct V_204 * V_205 ,
struct V_204 * V_206 ,
int V_207 )
{
struct V_34 * V_34 = & V_92 -> V_34 ;
int V_90 = 0 ;
F_51 ( & V_92 -> V_138 ) ;
sprintf ( V_92 -> V_8 , L_33 , V_206 ) ;
F_11 ( L_34 , V_92 -> V_8 ) ;
V_34 -> V_7 = NULL ;
V_92 -> V_132 = V_156 ;
V_34 -> V_119 = F_93 ( & V_208 , F_86 ,
( void * ) V_92 ,
V_209 , V_111 ) ;
if ( F_13 ( V_34 -> V_119 ) ) {
V_90 = F_28 ( V_34 -> V_119 ) ;
F_2 ( L_35 , V_90 ) ;
goto V_210;
}
V_90 = F_94 ( V_34 -> V_119 , V_205 , V_206 , 1000 ) ;
if ( V_90 ) {
F_2 ( L_36 , V_90 ) ;
goto V_211;
}
if ( ! V_207 ) {
F_95 ( & V_92 -> V_181 ) ;
if ( V_92 -> V_132 != V_144 ) {
V_90 = - V_212 ;
goto V_213;
}
}
F_52 ( & V_92 -> V_138 ) ;
F_51 ( & V_97 . V_98 ) ;
F_29 ( & V_92 -> V_142 , & V_97 . V_214 ) ;
F_52 ( & V_97 . V_98 ) ;
return 0 ;
V_210:
V_34 -> V_119 = NULL ;
V_211:
V_92 -> V_132 = V_139 ;
V_213:
F_52 ( & V_92 -> V_138 ) ;
F_63 ( V_92 ) ;
return V_90 ;
}
int F_96 ( struct V_92 * V_92 )
{
struct V_34 * V_34 = & V_92 -> V_34 ;
struct V_215 * V_42 = & V_92 -> V_216 ;
struct V_217 V_218 , * V_219 ;
int V_220 ;
V_42 -> V_221 . V_222 = V_42 -> V_223 ;
V_42 -> V_221 . V_224 = V_225 ;
V_42 -> V_221 . V_226 = V_34 -> V_7 -> V_24 -> V_227 ;
V_42 -> V_228 . V_202 = V_229 ;
V_218 . V_230 = & V_42 -> V_228 ;
V_218 . V_231 = & V_42 -> V_221 ;
V_218 . V_232 = 1 ;
V_218 . V_233 = NULL ;
V_34 -> V_200 ++ ;
V_220 = F_97 ( V_34 -> V_121 , & V_218 , & V_219 ) ;
if ( V_220 ) {
F_2 ( L_37 , V_220 ) ;
V_34 -> V_200 -- ;
}
return V_220 ;
}
int F_98 ( struct V_92 * V_92 , int V_234 )
{
struct V_34 * V_34 = & V_92 -> V_34 ;
unsigned int V_235 = V_92 -> V_236 ;
struct V_237 * V_238 ;
struct V_217 * V_218 , * V_219 ;
int V_15 , V_220 ;
for ( V_218 = V_34 -> V_239 , V_15 = 0 ; V_15 < V_234 ; V_15 ++ , V_218 ++ ) {
V_238 = & V_92 -> V_141 [ V_235 ] ;
V_238 -> V_228 . V_202 = V_240 ;
V_218 -> V_230 = & V_238 -> V_228 ;
V_218 -> V_231 = & V_238 -> V_241 ;
V_218 -> V_232 = 1 ;
V_218 -> V_233 = V_218 + 1 ;
V_235 = ( V_235 + 1 ) & V_92 -> V_242 ;
}
V_218 -- ;
V_218 -> V_233 = NULL ;
V_34 -> V_200 += V_234 ;
V_220 = F_97 ( V_34 -> V_121 , V_34 -> V_239 , & V_219 ) ;
if ( V_220 ) {
F_2 ( L_37 , V_220 ) ;
V_34 -> V_200 -= V_234 ;
} else
V_92 -> V_236 = V_235 ;
return V_220 ;
}
int F_99 ( struct V_34 * V_34 , struct V_243 * V_244 ,
bool signal )
{
struct V_245 * V_246 , * V_218 = F_100 ( V_244 ) ;
int V_220 ;
F_101 ( V_34 -> V_7 -> V_12 ,
V_244 -> V_247 , V_248 ,
V_249 ) ;
V_218 -> V_233 = NULL ;
V_218 -> V_230 = & V_244 -> V_228 ;
V_218 -> V_231 = V_244 -> V_250 ;
V_218 -> V_232 = V_244 -> V_232 ;
V_218 -> V_251 = V_252 ;
V_218 -> V_253 = signal ? V_254 : 0 ;
V_220 = F_102 ( V_34 -> V_121 , & V_244 -> V_255 [ 0 ] . V_256 , & V_246 ) ;
if ( V_220 )
F_2 ( L_38 ,
V_220 , V_246 -> V_251 ) ;
return V_220 ;
}
T_1 F_103 ( struct V_257 * V_258 ,
enum V_259 V_260 , T_2 * V_261 )
{
struct V_262 * V_263 = & V_258 -> V_264 [ V_260 ] ;
struct V_41 * V_42 = V_263 -> V_265 ;
unsigned long V_266 = V_258 -> V_267 -> V_7 -> V_266 ;
struct V_268 V_269 ;
int V_14 ;
if ( V_42 && V_42 -> V_78 -> V_84 ) {
V_42 -> V_78 -> V_84 = 0 ;
V_14 = F_104 ( V_42 -> V_78 -> V_80 ,
V_270 , & V_269 ) ;
if ( V_14 ) {
F_105 ( L_39 , V_14 ) ;
goto V_90;
}
if ( V_269 . V_271 & V_270 ) {
T_2 V_272 = V_269 . V_273 . V_274 ;
F_106 ( V_272 , V_266 + 8 ) ;
* V_261 = F_107 ( V_258 -> V_267 ) + V_272 ;
F_105 ( L_40
L_41 ,
V_269 . V_273 . V_275 ,
( unsigned long long ) * V_261 ,
V_269 . V_273 . V_276 ,
V_269 . V_273 . V_277 ) ;
switch ( V_269 . V_273 . V_275 ) {
case V_278 :
return 0x1 ;
case V_279 :
return 0x3 ;
case V_280 :
return 0x2 ;
}
}
}
return 0 ;
V_90:
return 0x1 ;
}
void F_108 ( struct V_281 * V_282 , const char * type )
{
if ( V_282 -> V_184 != V_283 ) {
struct V_92 * V_92 = F_49 ( V_282 -> V_121 -> V_100 ) ;
F_2 ( L_42 , type ,
F_109 ( V_282 -> V_184 ) , V_282 -> V_184 ,
V_282 -> V_284 ) ;
if ( V_92 -> V_146 )
F_84 ( V_92 -> V_146 ,
V_182 ) ;
} else {
F_54 ( L_43 , type ,
F_109 ( V_282 -> V_184 ) , V_282 -> V_184 ) ;
}
}
