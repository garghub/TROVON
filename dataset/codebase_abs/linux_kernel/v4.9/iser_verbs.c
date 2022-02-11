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
if ( F_16 ( & V_7 -> V_33 ) )
goto V_32;
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
( void ) F_21 ( & V_7 -> V_33 ) ;
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
F_24 ( & V_38 -> V_48 ) ;
V_38 -> V_36 = 0 ;
for ( V_15 = 0 ; V_15 < V_35 ; V_15 ++ ) {
V_42 = F_40 ( V_7 , V_7 -> V_24 ,
V_34 -> V_88 , V_36 ) ;
if ( F_13 ( V_42 ) ) {
V_14 = F_28 ( V_42 ) ;
goto V_89;
}
F_43 ( & V_42 -> V_47 , & V_38 -> V_47 ) ;
V_38 -> V_36 ++ ;
}
return 0 ;
V_89:
F_44 ( V_34 ) ;
return V_14 ;
}
void F_44 ( struct V_34 * V_34 )
{
struct V_37 * V_38 = & V_34 -> V_38 ;
struct V_41 * V_42 , * V_90 ;
int V_15 = 0 ;
if ( F_45 ( & V_38 -> V_47 ) )
return;
F_11 ( L_9 , V_34 ) ;
F_46 (desc, tmp, &fr_pool->list, list) {
F_32 ( & V_42 -> V_47 ) ;
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
struct V_91 * V_91 = F_49 ( V_34 ) ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_92 V_93 ;
int V_14 = - V_49 ;
int V_94 , V_95 = 0 ;
F_50 ( V_34 -> V_7 == NULL ) ;
V_7 = V_34 -> V_7 ;
V_13 = V_7 -> V_12 ;
memset ( & V_93 , 0 , sizeof V_93 ) ;
F_51 ( & V_96 . V_97 ) ;
for ( V_94 = 0 ; V_94 < V_7 -> V_17 ; V_94 ++ ) {
if ( V_7 -> V_19 [ V_94 ] . V_98 <
V_7 -> V_19 [ V_95 ] . V_98 )
V_95 = V_94 ;
}
V_34 -> V_29 = & V_7 -> V_19 [ V_95 ] ;
V_34 -> V_29 -> V_98 ++ ;
F_52 ( & V_96 . V_97 ) ;
F_11 ( L_11 , V_95 , V_34 ) ;
V_93 . V_33 = F_1 ;
V_93 . V_99 = ( void * ) V_34 ;
V_93 . V_100 = V_34 -> V_29 -> V_30 ;
V_93 . V_101 = V_34 -> V_29 -> V_30 ;
V_93 . V_102 . V_103 = V_104 ;
V_93 . V_102 . V_105 = 2 ;
V_93 . V_102 . V_106 = 1 ;
V_93 . V_107 = V_108 ;
V_93 . V_109 = V_110 ;
if ( V_34 -> V_88 ) {
V_93 . V_102 . V_111 = V_112 + 1 ;
V_93 . V_113 |= V_114 ;
V_91 -> V_115 =
F_53 ( V_112 ) ;
} else {
if ( V_13 -> V_23 . V_116 > V_117 ) {
V_93 . V_102 . V_111 = V_117 + 1 ;
V_91 -> V_115 =
F_53 ( V_117 ) ;
} else {
V_93 . V_102 . V_111 = V_13 -> V_23 . V_116 ;
V_91 -> V_115 =
F_53 ( V_13 -> V_23 . V_116 ) ;
F_54 ( L_12 ,
V_7 -> V_12 -> V_8 , V_13 -> V_23 . V_116 ) ;
}
}
V_14 = F_55 ( V_34 -> V_118 , V_7 -> V_24 , & V_93 ) ;
if ( V_14 )
goto V_119;
V_34 -> V_120 = V_34 -> V_118 -> V_120 ;
F_11 ( L_13 ,
V_34 , V_34 -> V_118 ,
V_34 -> V_118 -> V_120 ) ;
return V_14 ;
V_119:
F_51 ( & V_96 . V_97 ) ;
V_34 -> V_29 -> V_98 -- ;
F_52 ( & V_96 . V_97 ) ;
F_2 ( L_14 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_56 ( struct V_121 * V_118 )
{
struct V_11 * V_7 ;
F_51 ( & V_96 . V_122 ) ;
F_57 (device, &ig.device_list, ig_list)
if ( V_7 -> V_12 -> V_123 == V_118 -> V_7 -> V_123 )
goto V_124;
V_7 = F_25 ( sizeof *V_7 , V_20 ) ;
if ( V_7 == NULL )
goto V_125;
V_7 -> V_12 = V_118 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_19 ( V_7 ) ;
V_7 = NULL ;
goto V_125;
}
F_29 ( & V_7 -> V_126 , & V_96 . V_127 ) ;
V_124:
V_7 -> V_128 ++ ;
V_125:
F_52 ( & V_96 . V_122 ) ;
return V_7 ;
}
static void F_58 ( struct V_11 * V_7 )
{
F_51 ( & V_96 . V_122 ) ;
V_7 -> V_128 -- ;
F_11 ( L_15 , V_7 , V_7 -> V_128 ) ;
if ( ! V_7 -> V_128 ) {
F_20 ( V_7 ) ;
F_32 ( & V_7 -> V_126 ) ;
F_19 ( V_7 ) ;
}
F_52 ( & V_96 . V_122 ) ;
}
static int F_59 ( struct V_91 * V_91 ,
enum V_129 V_29 ,
enum V_129 V_130 )
{
int V_14 ;
V_14 = ( V_91 -> V_131 == V_29 ) ;
if ( V_14 )
V_91 -> V_131 = V_130 ;
return V_14 ;
}
void F_60 ( struct V_132 * V_133 )
{
struct V_91 * V_91 ;
V_91 = F_61 ( V_133 , struct V_91 , V_134 ) ;
F_62 ( & V_91 -> V_135 ) ;
F_62 ( & V_91 -> V_136 ) ;
F_51 ( & V_91 -> V_137 ) ;
V_91 -> V_131 = V_138 ;
F_52 ( & V_91 -> V_137 ) ;
F_63 ( V_91 ) ;
}
static void F_64 ( struct V_91 * V_91 ,
bool V_139 )
{
struct V_34 * V_34 = & V_91 -> V_34 ;
struct V_11 * V_7 = V_34 -> V_7 ;
F_11 ( L_16 ,
V_91 , V_34 -> V_118 , V_34 -> V_120 ) ;
if ( V_34 -> V_120 != NULL ) {
V_34 -> V_29 -> V_98 -- ;
F_65 ( V_34 -> V_118 ) ;
V_34 -> V_120 = NULL ;
}
if ( V_139 ) {
if ( V_91 -> V_140 )
F_66 ( V_91 ) ;
if ( V_7 != NULL ) {
F_58 ( V_7 ) ;
V_34 -> V_7 = NULL ;
}
}
}
void F_63 ( struct V_91 * V_91 )
{
struct V_34 * V_34 = & V_91 -> V_34 ;
F_51 ( & V_96 . V_97 ) ;
F_32 ( & V_91 -> V_141 ) ;
F_52 ( & V_96 . V_97 ) ;
F_51 ( & V_91 -> V_137 ) ;
if ( V_91 -> V_131 != V_138 ) {
F_47 ( L_17 ,
V_91 , V_91 -> V_131 ) ;
F_67 ( V_91 -> V_142 ) ;
V_91 -> V_131 = V_138 ;
}
F_64 ( V_91 , true ) ;
F_52 ( & V_91 -> V_137 ) ;
if ( V_34 -> V_118 != NULL ) {
F_68 ( V_34 -> V_118 ) ;
V_34 -> V_118 = NULL ;
}
F_19 ( V_91 ) ;
}
int F_69 ( struct V_91 * V_91 )
{
struct V_34 * V_34 = & V_91 -> V_34 ;
int V_89 = 0 ;
if ( ! F_59 ( V_91 , V_143 ,
V_144 ) )
return 0 ;
F_11 ( L_18 , V_91 , V_91 -> V_131 ) ;
if ( V_91 -> V_145 )
F_70 ( V_91 -> V_145 ) ;
if ( V_34 -> V_118 ) {
V_89 = F_71 ( V_34 -> V_118 ) ;
if ( V_89 )
F_2 ( L_19 ,
V_91 , V_89 ) ;
F_72 ( V_34 -> V_120 ) ;
}
return 1 ;
}
static void F_73 ( struct V_121 * V_118 )
{
struct V_91 * V_91 ;
V_91 = (struct V_91 * ) V_118 -> V_3 ;
V_91 -> V_131 = V_144 ;
}
static void
F_74 ( struct V_91 * V_91 ,
unsigned int V_146 )
{
struct V_11 * V_7 = V_91 -> V_34 . V_7 ;
unsigned short V_147 , V_148 ;
V_147 = F_75 ( V_146 * 512 , V_149 ) ;
V_148 = F_7 ( unsigned , V_150 ,
V_7 -> V_12 -> V_23 . V_151 ) ;
if ( V_147 > V_148 ) {
V_147 = V_148 ;
V_91 -> V_152 = V_147 * V_149 / 512 ;
} else {
V_91 -> V_152 = V_146 ;
}
V_91 -> V_153 = V_147 ;
F_54 ( L_20 ,
V_91 , V_91 -> V_153 ,
V_91 -> V_152 ) ;
}
static void F_76 ( struct V_121 * V_118 )
{
struct V_11 * V_7 ;
struct V_91 * V_91 ;
struct V_34 * V_34 ;
int V_14 ;
V_91 = (struct V_91 * ) V_118 -> V_3 ;
if ( V_91 -> V_131 != V_154 )
return;
V_34 = & V_91 -> V_34 ;
V_7 = F_56 ( V_118 ) ;
if ( ! V_7 ) {
F_2 ( L_21 ) ;
F_73 ( V_118 ) ;
return;
}
V_34 -> V_7 = V_7 ;
if ( V_155 ) {
if ( ! ( V_7 -> V_12 -> V_23 . V_71 &
V_156 ) ) {
F_47 ( L_22
L_23 ,
V_34 -> V_7 -> V_12 -> V_8 ) ;
V_34 -> V_88 = false ;
} else {
V_34 -> V_88 = true ;
}
}
F_74 ( V_91 , V_157 ) ;
V_14 = F_77 ( V_118 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_24 , V_14 ) ;
F_73 ( V_118 ) ;
return;
}
}
static void F_78 ( struct V_121 * V_118 )
{
struct V_158 V_159 ;
int V_14 ;
struct V_160 V_161 ;
struct V_91 * V_91 = (struct V_91 * ) V_118 -> V_3 ;
struct V_34 * V_34 = & V_91 -> V_34 ;
struct V_11 * V_7 = V_34 -> V_7 ;
if ( V_91 -> V_131 != V_154 )
return;
V_14 = F_48 ( V_34 ) ;
if ( V_14 )
goto V_162;
memset ( & V_159 , 0 , sizeof V_159 ) ;
V_159 . V_163 = V_7 -> V_12 -> V_23 . V_164 ;
V_159 . V_165 = 1 ;
V_159 . V_166 = 7 ;
V_159 . V_167 = 6 ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_168 = V_169 ;
if ( ! V_7 -> V_170 )
V_161 . V_168 |= V_171 ;
V_159 . V_172 = ( void * ) & V_161 ;
V_159 . V_173 = sizeof( struct V_160 ) ;
V_14 = F_79 ( V_118 , & V_159 ) ;
if ( V_14 ) {
F_2 ( L_25 , V_14 ) ;
goto V_162;
}
return;
V_162:
F_73 ( V_118 ) ;
}
static void F_80 ( struct V_121 * V_118 ,
const void * V_172 )
{
struct V_91 * V_91 ;
struct V_174 V_175 ;
struct V_92 V_93 ;
V_91 = (struct V_91 * ) V_118 -> V_3 ;
if ( V_91 -> V_131 != V_154 )
return;
( void ) F_81 ( V_118 -> V_120 , & V_175 , ~ 0 , & V_93 ) ;
F_11 ( L_26 , V_175 . V_176 , V_118 -> V_120 -> V_177 ) ;
if ( V_172 ) {
T_1 V_168 = * ( T_1 * ) V_172 ;
V_91 -> V_178 = ! ( V_168 & V_171 ) ;
}
F_11 ( L_27 ,
V_91 , V_91 -> V_178 ? L_28 : L_29 ) ;
V_91 -> V_131 = V_143 ;
F_82 ( & V_91 -> V_179 ) ;
}
static void F_83 ( struct V_121 * V_118 )
{
struct V_91 * V_91 = (struct V_91 * ) V_118 -> V_3 ;
if ( F_69 ( V_91 ) ) {
if ( V_91 -> V_145 )
F_84 ( V_91 -> V_145 ,
V_180 ) ;
else
F_2 ( L_30 ) ;
}
}
static void F_85 ( struct V_121 * V_118 ,
bool V_139 )
{
struct V_91 * V_91 = (struct V_91 * ) V_118 -> V_3 ;
F_83 ( V_118 ) ;
F_64 ( V_91 , V_139 ) ;
F_82 ( & V_91 -> V_136 ) ;
}
static int F_86 ( struct V_121 * V_118 , struct V_181 * V_4 )
{
struct V_91 * V_91 ;
int V_14 = 0 ;
V_91 = (struct V_91 * ) V_118 -> V_3 ;
F_11 ( L_31 ,
F_87 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_182 , V_118 -> V_3 , V_118 ) ;
F_51 ( & V_91 -> V_137 ) ;
switch ( V_4 -> V_4 ) {
case V_183 :
F_76 ( V_118 ) ;
break;
case V_184 :
F_78 ( V_118 ) ;
break;
case V_185 :
F_80 ( V_118 , V_4 -> V_186 . V_187 . V_172 ) ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
F_73 ( V_118 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
F_85 ( V_118 , false ) ;
break;
case V_196 :
F_85 ( V_118 , true ) ;
if ( V_91 -> V_131 != V_138 ) {
V_91 -> V_34 . V_118 = NULL ;
V_14 = 1 ;
}
break;
default:
F_2 ( L_32 ,
F_87 ( V_4 -> V_4 ) , V_4 -> V_4 ) ;
break;
}
F_52 ( & V_91 -> V_137 ) ;
return V_14 ;
}
void F_88 ( struct V_91 * V_91 )
{
struct V_34 * V_34 = & V_91 -> V_34 ;
V_91 -> V_131 = V_197 ;
F_89 ( & V_91 -> V_135 ) ;
F_89 ( & V_91 -> V_136 ) ;
F_89 ( & V_91 -> V_179 ) ;
F_23 ( & V_91 -> V_141 ) ;
F_90 ( & V_91 -> V_137 ) ;
V_34 -> V_198 = 0 ;
V_34 -> V_199 . V_200 = V_201 ;
}
int F_91 ( struct V_91 * V_91 ,
struct V_202 * V_203 ,
struct V_202 * V_204 ,
int V_205 )
{
struct V_34 * V_34 = & V_91 -> V_34 ;
int V_89 = 0 ;
F_51 ( & V_91 -> V_137 ) ;
sprintf ( V_91 -> V_8 , L_33 , V_204 ) ;
F_11 ( L_34 , V_91 -> V_8 ) ;
V_34 -> V_7 = NULL ;
V_91 -> V_131 = V_154 ;
V_34 -> V_118 = F_92 ( & V_206 , F_86 ,
( void * ) V_91 ,
V_207 , V_110 ) ;
if ( F_13 ( V_34 -> V_118 ) ) {
V_89 = F_28 ( V_34 -> V_118 ) ;
F_2 ( L_35 , V_89 ) ;
goto V_208;
}
V_89 = F_93 ( V_34 -> V_118 , V_203 , V_204 , 1000 ) ;
if ( V_89 ) {
F_2 ( L_36 , V_89 ) ;
goto V_209;
}
if ( ! V_205 ) {
F_94 ( & V_91 -> V_179 ) ;
if ( V_91 -> V_131 != V_143 ) {
V_89 = - V_210 ;
goto V_211;
}
}
F_52 ( & V_91 -> V_137 ) ;
F_51 ( & V_96 . V_97 ) ;
F_29 ( & V_91 -> V_141 , & V_96 . V_212 ) ;
F_52 ( & V_96 . V_97 ) ;
return 0 ;
V_208:
V_34 -> V_118 = NULL ;
V_209:
V_91 -> V_131 = V_138 ;
V_211:
F_52 ( & V_91 -> V_137 ) ;
F_63 ( V_91 ) ;
return V_89 ;
}
int F_95 ( struct V_91 * V_91 )
{
struct V_34 * V_34 = & V_91 -> V_34 ;
struct V_213 * V_42 = & V_91 -> V_214 ;
struct V_215 V_216 , * V_217 ;
int V_218 ;
V_42 -> V_219 . V_220 = V_42 -> V_221 ;
V_42 -> V_219 . V_222 = V_223 ;
V_42 -> V_219 . V_224 = V_34 -> V_7 -> V_24 -> V_225 ;
V_42 -> V_226 . V_200 = V_227 ;
V_216 . V_228 = & V_42 -> V_226 ;
V_216 . V_229 = & V_42 -> V_219 ;
V_216 . V_230 = 1 ;
V_216 . V_231 = NULL ;
V_34 -> V_198 ++ ;
V_218 = F_96 ( V_34 -> V_120 , & V_216 , & V_217 ) ;
if ( V_218 ) {
F_2 ( L_37 , V_218 ) ;
V_34 -> V_198 -- ;
}
return V_218 ;
}
int F_97 ( struct V_91 * V_91 , int V_232 )
{
struct V_34 * V_34 = & V_91 -> V_34 ;
unsigned int V_233 = V_91 -> V_234 ;
struct V_235 * V_236 ;
struct V_215 * V_216 , * V_217 ;
int V_15 , V_218 ;
for ( V_216 = V_34 -> V_237 , V_15 = 0 ; V_15 < V_232 ; V_15 ++ , V_216 ++ ) {
V_236 = & V_91 -> V_140 [ V_233 ] ;
V_236 -> V_226 . V_200 = V_238 ;
V_216 -> V_228 = & V_236 -> V_226 ;
V_216 -> V_229 = & V_236 -> V_239 ;
V_216 -> V_230 = 1 ;
V_216 -> V_231 = V_216 + 1 ;
V_233 = ( V_233 + 1 ) & V_91 -> V_240 ;
}
V_216 -- ;
V_216 -> V_231 = NULL ;
V_34 -> V_198 += V_232 ;
V_218 = F_96 ( V_34 -> V_120 , V_34 -> V_237 , & V_217 ) ;
if ( V_218 ) {
F_2 ( L_37 , V_218 ) ;
V_34 -> V_198 -= V_232 ;
} else
V_91 -> V_234 = V_233 ;
return V_218 ;
}
int F_98 ( struct V_34 * V_34 , struct V_241 * V_242 ,
bool signal )
{
struct V_243 * V_244 , * V_216 = F_99 ( V_242 ) ;
int V_218 ;
F_100 ( V_34 -> V_7 -> V_12 ,
V_242 -> V_245 , V_246 ,
V_247 ) ;
V_216 -> V_231 = NULL ;
V_216 -> V_228 = & V_242 -> V_226 ;
V_216 -> V_229 = V_242 -> V_248 ;
V_216 -> V_230 = V_242 -> V_230 ;
V_216 -> V_249 = V_250 ;
V_216 -> V_251 = signal ? V_252 : 0 ;
V_218 = F_101 ( V_34 -> V_120 , & V_242 -> V_253 [ 0 ] . V_254 , & V_244 ) ;
if ( V_218 )
F_2 ( L_38 ,
V_218 , V_244 -> V_249 ) ;
return V_218 ;
}
T_1 F_102 ( struct V_255 * V_256 ,
enum V_257 V_258 , T_2 * V_259 )
{
struct V_260 * V_261 = & V_256 -> V_262 [ V_258 ] ;
struct V_41 * V_42 = V_261 -> V_263 ;
unsigned long V_264 = V_256 -> V_265 -> V_7 -> V_264 ;
struct V_266 V_267 ;
int V_14 ;
if ( V_42 && V_42 -> V_78 -> V_84 ) {
V_42 -> V_78 -> V_84 = 0 ;
V_14 = F_103 ( V_42 -> V_78 -> V_80 ,
V_268 , & V_267 ) ;
if ( V_14 ) {
F_104 ( L_39 , V_14 ) ;
goto V_89;
}
if ( V_267 . V_269 & V_268 ) {
T_2 V_270 = V_267 . V_271 . V_272 ;
F_105 ( V_270 , V_264 + 8 ) ;
* V_259 = F_106 ( V_256 -> V_265 ) + V_270 ;
F_104 ( L_40
L_41 ,
V_267 . V_271 . V_273 ,
( unsigned long long ) * V_259 ,
V_267 . V_271 . V_274 ,
V_267 . V_271 . V_275 ) ;
switch ( V_267 . V_271 . V_273 ) {
case V_276 :
return 0x1 ;
case V_277 :
return 0x3 ;
case V_278 :
return 0x2 ;
}
}
}
return 0 ;
V_89:
return 0x1 ;
}
void F_107 ( struct V_279 * V_280 , const char * type )
{
if ( V_280 -> V_182 != V_281 ) {
struct V_91 * V_91 = F_49 ( V_280 -> V_120 -> V_99 ) ;
F_2 ( L_42 , type ,
F_108 ( V_280 -> V_182 ) , V_280 -> V_182 ,
V_280 -> V_282 ) ;
if ( V_91 -> V_145 )
F_84 ( V_91 -> V_145 ,
V_180 ) ;
} else {
F_54 ( L_43 , type ,
F_108 ( V_280 -> V_182 ) , V_280 -> V_182 ) ;
}
}
