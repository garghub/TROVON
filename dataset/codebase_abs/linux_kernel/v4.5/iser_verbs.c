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
V_7 -> V_24 = F_12 ( V_13 ) ;
if ( F_13 ( V_7 -> V_24 ) )
goto V_25;
for ( V_15 = 0 ; V_15 < V_7 -> V_17 ; V_15 ++ ) {
struct V_26 * V_27 = & V_7 -> V_19 [ V_15 ] ;
V_27 -> V_28 = F_14 ( V_13 , V_27 , V_16 , V_15 ,
V_29 ) ;
if ( F_13 ( V_27 -> V_28 ) ) {
V_27 -> V_28 = NULL ;
goto V_30;
}
}
if ( ! V_31 ) {
int V_32 = V_33 |
V_34 |
V_35 ;
V_7 -> V_36 = F_15 ( V_7 -> V_24 , V_32 ) ;
if ( F_13 ( V_7 -> V_36 ) )
goto V_30;
}
F_16 ( & V_7 -> V_37 , V_13 ,
F_4 ) ;
if ( F_17 ( & V_7 -> V_37 ) )
goto V_38;
return 0 ;
V_38:
if ( V_7 -> V_36 )
F_18 ( V_7 -> V_36 ) ;
V_30:
for ( V_15 = 0 ; V_15 < V_7 -> V_17 ; V_15 ++ ) {
struct V_26 * V_27 = & V_7 -> V_19 [ V_15 ] ;
if ( V_27 -> V_28 )
F_19 ( V_27 -> V_28 ) ;
}
F_20 ( V_7 -> V_24 ) ;
V_25:
F_21 ( V_7 -> V_19 ) ;
V_21:
F_2 ( L_4 ) ;
return - 1 ;
}
static void F_22 ( struct V_11 * V_7 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_7 -> V_17 ; V_15 ++ ) {
struct V_26 * V_27 = & V_7 -> V_19 [ V_15 ] ;
F_19 ( V_27 -> V_28 ) ;
V_27 -> V_28 = NULL ;
}
( void ) F_23 ( & V_7 -> V_37 ) ;
if ( V_7 -> V_36 )
( void ) F_18 ( V_7 -> V_36 ) ;
F_20 ( V_7 -> V_24 ) ;
F_21 ( V_7 -> V_19 ) ;
V_7 -> V_19 = NULL ;
V_7 -> V_36 = NULL ;
V_7 -> V_24 = NULL ;
}
int F_24 ( struct V_39 * V_39 ,
unsigned V_40 ,
unsigned int V_41 )
{
struct V_11 * V_7 = V_39 -> V_7 ;
struct V_42 * V_43 = & V_39 -> V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
int V_14 ;
F_25 ( & V_43 -> V_52 ) ;
F_26 ( & V_43 -> V_53 ) ;
V_47 = F_27 ( sizeof( * V_47 ) , V_20 ) ;
if ( ! V_47 )
return - V_54 ;
V_45 = F_28 ( sizeof( * V_45 ) + ( sizeof( V_55 ) * V_41 ) ,
V_20 ) ;
if ( ! V_45 ) {
V_14 = - V_54 ;
goto V_56;
}
V_45 -> V_57 = ( V_55 * ) ( V_45 + 1 ) ;
V_51 . V_58 = V_59 ;
V_51 . V_60 = V_41 ;
V_51 . V_61 = V_40 * 2 ;
V_51 . V_62 = V_40 ;
V_51 . V_63 = 0 ;
V_51 . V_64 = NULL ;
V_51 . V_32 = ( V_33 |
V_34 |
V_35 ) ;
V_49 = F_29 ( V_7 -> V_24 , & V_51 ) ;
if ( F_13 ( V_49 ) ) {
V_14 = F_30 ( V_49 ) ;
F_2 ( L_5 , V_14 ) ;
goto V_65;
}
V_47 -> V_66 . V_45 = V_45 ;
V_47 -> V_66 . V_49 = V_49 ;
F_31 ( & V_47 -> V_52 , & V_43 -> V_52 ) ;
return 0 ;
V_65:
F_21 ( V_45 ) ;
V_56:
F_21 ( V_47 ) ;
return V_14 ;
}
void F_32 ( struct V_39 * V_39 )
{
struct V_42 * V_43 = & V_39 -> V_43 ;
struct V_46 * V_47 ;
V_47 = F_33 ( & V_43 -> V_52 ,
struct V_46 , V_52 ) ;
F_34 ( & V_47 -> V_52 ) ;
F_11 ( L_6 ,
V_39 , V_47 -> V_66 . V_49 ) ;
F_35 ( V_47 -> V_66 . V_49 ) ;
F_21 ( V_47 -> V_66 . V_45 ) ;
F_21 ( V_47 ) ;
}
static int
F_36 ( struct V_12 * V_12 ,
struct V_67 * V_24 ,
struct V_68 * V_69 ,
unsigned int V_41 )
{
int V_14 ;
V_69 -> V_36 = F_37 ( V_24 , V_70 , V_41 ) ;
if ( F_13 ( V_69 -> V_36 ) ) {
V_14 = F_30 ( V_69 -> V_36 ) ;
F_2 ( L_7 , V_14 ) ;
return V_14 ;
}
V_69 -> V_71 = 0 ;
return 0 ;
}
static void
F_38 ( struct V_68 * V_66 )
{
F_18 ( V_66 -> V_36 ) ;
}
static int
F_39 ( struct V_12 * V_12 ,
struct V_67 * V_24 ,
struct V_46 * V_47 ,
unsigned int V_41 )
{
struct V_72 * V_73 = NULL ;
int V_14 ;
V_47 -> V_73 = F_27 ( sizeof( * V_47 -> V_73 ) , V_20 ) ;
if ( ! V_47 -> V_73 )
return - V_54 ;
V_73 = V_47 -> V_73 ;
V_14 = F_36 ( V_12 , V_24 , & V_73 -> V_66 , V_41 ) ;
if ( V_14 ) {
F_2 ( L_8 ) ;
goto V_74;
}
V_73 -> V_75 = F_37 ( V_24 , V_76 , 2 ) ;
if ( F_13 ( V_73 -> V_75 ) ) {
V_14 = F_30 ( V_73 -> V_75 ) ;
goto V_77;
}
V_73 -> V_78 = 0 ;
V_47 -> V_73 -> V_79 = 0 ;
return 0 ;
V_77:
F_38 ( & V_73 -> V_66 ) ;
V_74:
F_21 ( V_47 -> V_73 ) ;
return V_14 ;
}
static void
F_40 ( struct V_72 * V_73 )
{
F_38 ( & V_73 -> V_66 ) ;
F_18 ( V_73 -> V_75 ) ;
F_21 ( V_73 ) ;
}
static struct V_46 *
F_41 ( struct V_12 * V_12 ,
struct V_67 * V_24 ,
bool V_80 ,
unsigned int V_41 )
{
struct V_46 * V_47 ;
int V_14 ;
V_47 = F_27 ( sizeof( * V_47 ) , V_20 ) ;
if ( ! V_47 )
return F_42 ( - V_54 ) ;
V_14 = F_36 ( V_12 , V_24 , & V_47 -> V_66 , V_41 ) ;
if ( V_14 )
goto V_81;
if ( V_80 ) {
V_14 = F_39 ( V_12 , V_24 , V_47 , V_41 ) ;
if ( V_14 )
goto V_82;
}
return V_47 ;
V_82:
F_38 ( & V_47 -> V_66 ) ;
V_81:
F_21 ( V_47 ) ;
return F_42 ( V_14 ) ;
}
int F_43 ( struct V_39 * V_39 ,
unsigned V_40 ,
unsigned int V_41 )
{
struct V_11 * V_7 = V_39 -> V_7 ;
struct V_42 * V_43 = & V_39 -> V_43 ;
struct V_46 * V_47 ;
int V_15 , V_14 ;
F_25 ( & V_43 -> V_52 ) ;
F_26 ( & V_43 -> V_53 ) ;
V_43 -> V_41 = 0 ;
for ( V_15 = 0 ; V_15 < V_40 ; V_15 ++ ) {
V_47 = F_41 ( V_7 -> V_12 , V_7 -> V_24 ,
V_39 -> V_83 , V_41 ) ;
if ( F_13 ( V_47 ) ) {
V_14 = F_30 ( V_47 ) ;
goto V_84;
}
F_44 ( & V_47 -> V_52 , & V_43 -> V_52 ) ;
V_43 -> V_41 ++ ;
}
return 0 ;
V_84:
F_45 ( V_39 ) ;
return V_14 ;
}
void F_45 ( struct V_39 * V_39 )
{
struct V_42 * V_43 = & V_39 -> V_43 ;
struct V_46 * V_47 , * V_85 ;
int V_15 = 0 ;
if ( F_46 ( & V_43 -> V_52 ) )
return;
F_11 ( L_9 , V_39 ) ;
F_47 (desc, tmp, &fr_pool->list, list) {
F_34 ( & V_47 -> V_52 ) ;
F_38 ( & V_47 -> V_66 ) ;
if ( V_47 -> V_73 )
F_40 ( V_47 -> V_73 ) ;
F_21 ( V_47 ) ;
++ V_15 ;
}
if ( V_15 < V_43 -> V_41 )
F_48 ( L_10 ,
V_43 -> V_41 - V_15 ) ;
}
static int F_49 ( struct V_39 * V_39 )
{
struct V_86 * V_86 = F_50 ( V_39 ) ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
struct V_87 V_88 ;
int V_14 = - V_54 ;
int V_89 , V_90 = 0 ;
F_51 ( V_39 -> V_7 == NULL ) ;
V_7 = V_39 -> V_7 ;
V_13 = V_7 -> V_12 ;
memset ( & V_88 , 0 , sizeof V_88 ) ;
F_52 ( & V_91 . V_92 ) ;
for ( V_89 = 0 ; V_89 < V_7 -> V_17 ; V_89 ++ ) {
if ( V_7 -> V_19 [ V_89 ] . V_93 <
V_7 -> V_19 [ V_90 ] . V_93 )
V_90 = V_89 ;
}
V_39 -> V_27 = & V_7 -> V_19 [ V_90 ] ;
V_39 -> V_27 -> V_93 ++ ;
F_53 ( & V_91 . V_92 ) ;
F_11 ( L_11 , V_90 , V_39 ) ;
V_88 . V_37 = F_1 ;
V_88 . V_94 = ( void * ) V_39 ;
V_88 . V_95 = V_39 -> V_27 -> V_28 ;
V_88 . V_96 = V_39 -> V_27 -> V_28 ;
V_88 . V_97 . V_98 = V_99 ;
V_88 . V_97 . V_100 = 2 ;
V_88 . V_97 . V_101 = 1 ;
V_88 . V_102 = V_103 ;
V_88 . V_104 = V_105 ;
if ( V_39 -> V_83 ) {
V_88 . V_97 . V_106 = V_107 + 1 ;
V_88 . V_108 |= V_109 ;
V_86 -> V_110 =
F_54 ( V_107 ) ;
} else {
if ( V_13 -> V_23 . V_111 > V_112 ) {
V_88 . V_97 . V_106 = V_112 + 1 ;
V_86 -> V_110 =
F_54 ( V_112 ) ;
} else {
V_88 . V_97 . V_106 = V_13 -> V_23 . V_111 ;
V_86 -> V_110 =
F_54 ( V_13 -> V_23 . V_111 ) ;
F_55 ( L_12 ,
V_7 -> V_12 -> V_8 , V_13 -> V_23 . V_111 ) ;
}
}
V_14 = F_56 ( V_39 -> V_113 , V_7 -> V_24 , & V_88 ) ;
if ( V_14 )
goto V_114;
V_39 -> V_115 = V_39 -> V_113 -> V_115 ;
F_11 ( L_13 ,
V_39 , V_39 -> V_113 ,
V_39 -> V_113 -> V_115 ) ;
return V_14 ;
V_114:
F_52 ( & V_91 . V_92 ) ;
V_39 -> V_27 -> V_93 -- ;
F_53 ( & V_91 . V_92 ) ;
F_2 ( L_14 , V_14 ) ;
return V_14 ;
}
static
struct V_11 * F_57 ( struct V_116 * V_113 )
{
struct V_11 * V_7 ;
F_52 ( & V_91 . V_117 ) ;
F_58 (device, &ig.device_list, ig_list)
if ( V_7 -> V_12 -> V_118 == V_113 -> V_7 -> V_118 )
goto V_119;
V_7 = F_27 ( sizeof *V_7 , V_20 ) ;
if ( V_7 == NULL )
goto V_120;
V_7 -> V_12 = V_113 -> V_7 ;
if ( F_5 ( V_7 ) ) {
F_21 ( V_7 ) ;
V_7 = NULL ;
goto V_120;
}
F_31 ( & V_7 -> V_121 , & V_91 . V_122 ) ;
V_119:
V_7 -> V_123 ++ ;
V_120:
F_53 ( & V_91 . V_117 ) ;
return V_7 ;
}
static void F_59 ( struct V_11 * V_7 )
{
F_52 ( & V_91 . V_117 ) ;
V_7 -> V_123 -- ;
F_11 ( L_15 , V_7 , V_7 -> V_123 ) ;
if ( ! V_7 -> V_123 ) {
F_22 ( V_7 ) ;
F_34 ( & V_7 -> V_121 ) ;
F_21 ( V_7 ) ;
}
F_53 ( & V_91 . V_117 ) ;
}
static int F_60 ( struct V_86 * V_86 ,
enum V_124 V_27 ,
enum V_124 V_125 )
{
int V_14 ;
V_14 = ( V_86 -> V_126 == V_27 ) ;
if ( V_14 )
V_86 -> V_126 = V_125 ;
return V_14 ;
}
void F_61 ( struct V_127 * V_128 )
{
struct V_86 * V_86 ;
V_86 = F_62 ( V_128 , struct V_86 , V_129 ) ;
F_63 ( & V_86 -> V_130 ) ;
F_63 ( & V_86 -> V_131 ) ;
F_52 ( & V_86 -> V_132 ) ;
V_86 -> V_126 = V_133 ;
F_53 ( & V_86 -> V_132 ) ;
F_64 ( V_86 ) ;
}
static void F_65 ( struct V_86 * V_86 ,
bool V_134 )
{
struct V_39 * V_39 = & V_86 -> V_39 ;
struct V_11 * V_7 = V_39 -> V_7 ;
F_11 ( L_16 ,
V_86 , V_39 -> V_113 , V_39 -> V_115 ) ;
if ( V_39 -> V_115 != NULL ) {
V_39 -> V_27 -> V_93 -- ;
F_66 ( V_39 -> V_113 ) ;
V_39 -> V_115 = NULL ;
}
if ( V_134 ) {
if ( V_86 -> V_135 )
F_67 ( V_86 ) ;
if ( V_7 != NULL ) {
F_59 ( V_7 ) ;
V_39 -> V_7 = NULL ;
}
}
}
void F_64 ( struct V_86 * V_86 )
{
struct V_39 * V_39 = & V_86 -> V_39 ;
F_52 ( & V_91 . V_92 ) ;
F_34 ( & V_86 -> V_136 ) ;
F_53 ( & V_91 . V_92 ) ;
F_52 ( & V_86 -> V_132 ) ;
if ( V_86 -> V_126 != V_133 ) {
F_48 ( L_17 ,
V_86 , V_86 -> V_126 ) ;
F_68 ( V_86 -> V_137 ) ;
V_86 -> V_126 = V_133 ;
}
F_65 ( V_86 , true ) ;
F_53 ( & V_86 -> V_132 ) ;
if ( V_39 -> V_113 != NULL ) {
F_69 ( V_39 -> V_113 ) ;
V_39 -> V_113 = NULL ;
}
F_21 ( V_86 ) ;
}
int F_70 ( struct V_86 * V_86 )
{
struct V_39 * V_39 = & V_86 -> V_39 ;
struct V_138 * V_139 ;
int V_84 = 0 ;
if ( ! F_60 ( V_86 , V_140 ,
V_141 ) )
return 0 ;
F_11 ( L_18 , V_86 , V_86 -> V_126 ) ;
if ( V_86 -> V_142 )
F_71 ( V_86 -> V_142 ) ;
if ( V_39 -> V_113 ) {
V_84 = F_72 ( V_39 -> V_113 ) ;
if ( V_84 )
F_2 ( L_19 ,
V_86 , V_84 ) ;
V_84 = F_73 ( V_39 -> V_115 , & V_39 -> V_143 , & V_139 ) ;
if ( V_84 ) {
F_2 ( L_20 , V_39 ) ;
return 1 ;
}
F_63 ( & V_39 -> V_144 ) ;
}
return 1 ;
}
static void F_74 ( struct V_116 * V_113 )
{
struct V_86 * V_86 ;
V_86 = (struct V_86 * ) V_113 -> V_3 ;
V_86 -> V_126 = V_141 ;
}
static void
F_75 ( struct V_86 * V_86 ,
unsigned int V_145 )
{
struct V_11 * V_7 = V_86 -> V_39 . V_7 ;
unsigned short V_146 , V_147 ;
V_146 = F_76 ( V_145 * 512 , V_148 ) ;
V_147 = F_7 ( unsigned , V_149 ,
V_7 -> V_12 -> V_23 . V_150 ) ;
if ( V_146 > V_147 ) {
V_146 = V_147 ;
V_86 -> V_151 = V_146 * V_148 / 512 ;
} else {
V_86 -> V_151 = V_145 ;
}
V_86 -> V_152 = V_146 ;
F_55 ( L_21 ,
V_86 , V_86 -> V_152 ,
V_86 -> V_151 ) ;
}
static void F_77 ( struct V_116 * V_113 )
{
struct V_11 * V_7 ;
struct V_86 * V_86 ;
struct V_39 * V_39 ;
int V_14 ;
V_86 = (struct V_86 * ) V_113 -> V_3 ;
if ( V_86 -> V_126 != V_153 )
return;
V_39 = & V_86 -> V_39 ;
V_7 = F_57 ( V_113 ) ;
if ( ! V_7 ) {
F_2 ( L_22 ) ;
F_74 ( V_113 ) ;
return;
}
V_39 -> V_7 = V_7 ;
if ( V_154 ) {
if ( ! ( V_7 -> V_12 -> V_23 . V_155 &
V_156 ) ) {
F_48 ( L_23
L_24 ,
V_39 -> V_7 -> V_12 -> V_8 ) ;
V_39 -> V_83 = false ;
} else {
V_39 -> V_83 = true ;
}
}
F_75 ( V_86 , V_157 ) ;
V_14 = F_78 ( V_113 , 1000 ) ;
if ( V_14 ) {
F_2 ( L_25 , V_14 ) ;
F_74 ( V_113 ) ;
return;
}
}
static void F_79 ( struct V_116 * V_113 )
{
struct V_158 V_159 ;
int V_14 ;
struct V_160 V_161 ;
struct V_86 * V_86 = (struct V_86 * ) V_113 -> V_3 ;
struct V_39 * V_39 = & V_86 -> V_39 ;
struct V_11 * V_7 = V_39 -> V_7 ;
if ( V_86 -> V_126 != V_153 )
return;
V_14 = F_49 ( V_39 ) ;
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
V_14 = F_80 ( V_113 , & V_159 ) ;
if ( V_14 ) {
F_2 ( L_26 , V_14 ) ;
goto V_162;
}
return;
V_162:
F_74 ( V_113 ) ;
}
static void F_81 ( struct V_116 * V_113 ,
const void * V_172 )
{
struct V_86 * V_86 ;
struct V_174 V_175 ;
struct V_87 V_88 ;
V_86 = (struct V_86 * ) V_113 -> V_3 ;
if ( V_86 -> V_126 != V_153 )
return;
( void ) F_82 ( V_113 -> V_115 , & V_175 , ~ 0 , & V_88 ) ;
F_11 ( L_27 , V_175 . V_176 , V_113 -> V_115 -> V_177 ) ;
if ( V_172 ) {
T_1 V_168 = * ( T_1 * ) V_172 ;
V_86 -> V_178 = ! ( V_168 & V_171 ) ;
}
F_11 ( L_28 ,
V_86 , V_86 -> V_178 ? L_29 : L_30 ) ;
V_86 -> V_126 = V_140 ;
F_83 ( & V_86 -> V_179 ) ;
}
static void F_84 ( struct V_116 * V_113 )
{
struct V_86 * V_86 = (struct V_86 * ) V_113 -> V_3 ;
if ( F_70 ( V_86 ) ) {
if ( V_86 -> V_142 )
F_85 ( V_86 -> V_142 ,
V_180 ) ;
else
F_2 ( L_31 ) ;
}
}
static void F_86 ( struct V_116 * V_113 ,
bool V_134 )
{
struct V_86 * V_86 = (struct V_86 * ) V_113 -> V_3 ;
F_84 ( V_113 ) ;
F_65 ( V_86 , V_134 ) ;
F_83 ( & V_86 -> V_131 ) ;
}
static int F_87 ( struct V_116 * V_113 , struct V_181 * V_4 )
{
struct V_86 * V_86 ;
int V_14 = 0 ;
V_86 = (struct V_86 * ) V_113 -> V_3 ;
F_11 ( L_32 ,
F_88 ( V_4 -> V_4 ) , V_4 -> V_4 ,
V_4 -> V_182 , V_113 -> V_3 , V_113 ) ;
F_52 ( & V_86 -> V_132 ) ;
switch ( V_4 -> V_4 ) {
case V_183 :
F_77 ( V_113 ) ;
break;
case V_184 :
F_79 ( V_113 ) ;
break;
case V_185 :
F_81 ( V_113 , V_4 -> V_186 . V_187 . V_172 ) ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
case V_192 :
F_74 ( V_113 ) ;
break;
case V_193 :
case V_194 :
case V_195 :
F_86 ( V_113 , false ) ;
break;
case V_196 :
F_86 ( V_113 , true ) ;
if ( V_86 -> V_126 != V_133 ) {
V_86 -> V_39 . V_113 = NULL ;
V_14 = 1 ;
}
break;
default:
F_2 ( L_33 ,
F_88 ( V_4 -> V_4 ) , V_4 -> V_4 ) ;
break;
}
F_53 ( & V_86 -> V_132 ) ;
return V_14 ;
}
void F_89 ( struct V_86 * V_86 )
{
struct V_39 * V_39 = & V_86 -> V_39 ;
V_86 -> V_126 = V_197 ;
F_90 ( & V_86 -> V_130 ) ;
F_90 ( & V_86 -> V_131 ) ;
F_90 ( & V_86 -> V_179 ) ;
F_25 ( & V_86 -> V_136 ) ;
F_91 ( & V_86 -> V_132 ) ;
V_39 -> V_198 = 0 ;
V_39 -> V_199 . V_200 = V_201 ;
V_39 -> V_202 . V_200 = V_203 ;
V_39 -> V_143 . V_204 = & V_39 -> V_202 ;
V_39 -> V_143 . V_205 = V_206 ;
F_90 ( & V_39 -> V_144 ) ;
}
int F_92 ( struct V_86 * V_86 ,
struct V_207 * V_208 ,
struct V_207 * V_209 ,
int V_210 )
{
struct V_39 * V_39 = & V_86 -> V_39 ;
int V_84 = 0 ;
F_52 ( & V_86 -> V_132 ) ;
sprintf ( V_86 -> V_8 , L_34 , V_209 ) ;
F_11 ( L_35 , V_86 -> V_8 ) ;
V_39 -> V_7 = NULL ;
V_86 -> V_126 = V_153 ;
V_39 -> V_113 = F_93 ( & V_211 , F_87 ,
( void * ) V_86 ,
V_212 , V_105 ) ;
if ( F_13 ( V_39 -> V_113 ) ) {
V_84 = F_30 ( V_39 -> V_113 ) ;
F_2 ( L_36 , V_84 ) ;
goto V_213;
}
V_84 = F_94 ( V_39 -> V_113 , V_208 , V_209 , 1000 ) ;
if ( V_84 ) {
F_2 ( L_37 , V_84 ) ;
goto V_214;
}
if ( ! V_210 ) {
F_95 ( & V_86 -> V_179 ) ;
if ( V_86 -> V_126 != V_140 ) {
V_84 = - V_215 ;
goto V_216;
}
}
F_53 ( & V_86 -> V_132 ) ;
F_52 ( & V_91 . V_92 ) ;
F_31 ( & V_86 -> V_136 , & V_91 . V_217 ) ;
F_53 ( & V_91 . V_92 ) ;
return 0 ;
V_213:
V_39 -> V_113 = NULL ;
V_214:
V_86 -> V_126 = V_133 ;
V_216:
F_53 ( & V_86 -> V_132 ) ;
F_64 ( V_86 ) ;
return V_84 ;
}
int F_96 ( struct V_86 * V_86 )
{
struct V_39 * V_39 = & V_86 -> V_39 ;
struct V_218 * V_47 = & V_86 -> V_219 ;
struct V_220 V_221 , * V_222 ;
int V_223 ;
V_47 -> V_224 . V_225 = V_47 -> V_226 ;
V_47 -> V_224 . V_227 = V_228 ;
V_47 -> V_224 . V_229 = V_39 -> V_7 -> V_24 -> V_230 ;
V_47 -> V_231 . V_200 = V_232 ;
V_221 . V_204 = & V_47 -> V_231 ;
V_221 . V_233 = & V_47 -> V_224 ;
V_221 . V_234 = 1 ;
V_221 . V_235 = NULL ;
V_39 -> V_198 ++ ;
V_223 = F_97 ( V_39 -> V_115 , & V_221 , & V_222 ) ;
if ( V_223 ) {
F_2 ( L_38 , V_223 ) ;
V_39 -> V_198 -- ;
}
return V_223 ;
}
int F_98 ( struct V_86 * V_86 , int V_236 )
{
struct V_39 * V_39 = & V_86 -> V_39 ;
unsigned int V_237 = V_86 -> V_238 ;
struct V_239 * V_240 ;
struct V_220 * V_221 , * V_222 ;
int V_15 , V_223 ;
for ( V_221 = V_39 -> V_241 , V_15 = 0 ; V_15 < V_236 ; V_15 ++ , V_221 ++ ) {
V_240 = & V_86 -> V_135 [ V_237 ] ;
V_240 -> V_231 . V_200 = V_242 ;
V_221 -> V_204 = & V_240 -> V_231 ;
V_221 -> V_233 = & V_240 -> V_243 ;
V_221 -> V_234 = 1 ;
V_221 -> V_235 = V_221 + 1 ;
V_237 = ( V_237 + 1 ) & V_86 -> V_244 ;
}
V_221 -- ;
V_221 -> V_235 = NULL ;
V_39 -> V_198 += V_236 ;
V_223 = F_97 ( V_39 -> V_115 , V_39 -> V_241 , & V_222 ) ;
if ( V_223 ) {
F_2 ( L_38 , V_223 ) ;
V_39 -> V_198 -= V_236 ;
} else
V_86 -> V_238 = V_237 ;
return V_223 ;
}
int F_99 ( struct V_39 * V_39 , struct V_245 * V_246 ,
bool signal )
{
struct V_138 * V_139 , * V_221 = F_100 ( V_246 ) ;
int V_223 ;
F_101 ( V_39 -> V_7 -> V_12 ,
V_246 -> V_247 , V_248 ,
V_249 ) ;
V_221 -> V_235 = NULL ;
V_221 -> V_204 = & V_246 -> V_231 ;
V_221 -> V_233 = V_246 -> V_250 ;
V_221 -> V_234 = V_246 -> V_234 ;
V_221 -> V_205 = V_206 ;
V_221 -> V_251 = signal ? V_252 : 0 ;
V_223 = F_73 ( V_39 -> V_115 , & V_246 -> V_253 [ 0 ] . V_254 , & V_139 ) ;
if ( V_223 )
F_2 ( L_39 ,
V_223 , V_139 -> V_205 ) ;
return V_223 ;
}
T_1 F_102 ( struct V_255 * V_256 ,
enum V_257 V_258 , T_2 * V_259 )
{
struct V_260 * V_261 = & V_256 -> V_262 [ V_258 ] ;
struct V_46 * V_47 = V_261 -> V_263 ;
unsigned long V_264 = V_256 -> V_265 -> V_7 -> V_264 ;
struct V_266 V_267 ;
int V_14 ;
if ( V_47 && V_47 -> V_73 -> V_79 ) {
V_47 -> V_73 -> V_79 = 0 ;
V_14 = F_103 ( V_47 -> V_73 -> V_75 ,
V_268 , & V_267 ) ;
if ( V_14 ) {
F_104 ( L_40 , V_14 ) ;
goto V_84;
}
if ( V_267 . V_269 & V_268 ) {
T_2 V_270 = V_267 . V_271 . V_272 ;
F_105 ( V_270 , V_264 + 8 ) ;
* V_259 = F_106 ( V_256 -> V_265 ) + V_270 ;
F_104 ( L_41
L_42 ,
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
V_84:
return 0x1 ;
}
void F_107 ( struct V_279 * V_280 , const char * type )
{
if ( V_280 -> V_182 != V_281 ) {
struct V_86 * V_86 = F_50 ( V_280 -> V_115 -> V_94 ) ;
F_2 ( L_43 , type ,
F_108 ( V_280 -> V_182 ) , V_280 -> V_182 ,
V_280 -> V_282 ) ;
if ( V_86 -> V_142 )
F_85 ( V_86 -> V_142 ,
V_180 ) ;
} else {
F_55 ( L_44 , type ,
F_108 ( V_280 -> V_182 ) , V_280 -> V_182 ) ;
}
}
