static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 , V_6 , V_4 -> V_7 . V_7 ) ;
F_4 ( V_4 -> V_7 . V_7 ) ;
F_5 ( V_4 ) ;
}
static struct V_3 * F_6 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_7 ( V_9 -> V_12 , V_9 -> V_13 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
return V_4 ;
}
static struct V_3 *
F_8 ( const struct V_8 * V_9 ,
const struct V_10 * V_11 , struct V_14 * V_7 ,
T_1 V_15 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = F_9 ( sizeof( * V_4 ) , V_15 ) ;
struct V_3 * V_16 ;
if ( ! V_4 ) {
F_3 ( L_2 , V_6 , V_7 ) ;
return NULL ;
}
F_3 ( L_3 , V_6 , V_7 ) ;
F_10 ( & V_4 -> V_5 ,
V_9 -> V_12 ,
V_9 -> V_13 ,
V_11 ) ;
V_4 -> V_7 . V_7 = V_7 ;
V_2 = F_11 ( & V_4 -> V_5 ) ;
V_16 = F_2 ( V_2 , struct V_3 , V_5 ) ;
if ( V_16 != V_4 ) {
F_3 ( L_4 , V_6 , V_16 -> V_7 . V_7 ) ;
F_1 ( & V_4 -> V_5 ) ;
V_4 = V_16 ;
}
return V_4 ;
}
static inline struct V_17 *
F_12 ( struct V_18 * V_19 )
{
return F_2 ( V_19 , struct V_17 , V_19 ) ;
}
static int F_13 ( struct V_20 * V_21 ,
struct V_17 * V_22 , unsigned V_23 , struct V_10 * V_11 ,
T_1 V_15 )
{
struct V_24 * V_25 ;
struct V_3 * V_26 ;
struct V_14 * V_7 ;
struct V_27 V_28 ;
int V_29 ;
V_26 = F_6 ( F_14 ( V_21 -> V_30 ) , V_11 ) ;
if ( V_26 ) {
V_22 -> V_31 . V_32 [ V_23 ] = & V_26 -> V_7 ;
return 0 ;
}
V_29 = F_15 ( V_21 , V_11 , & V_25 , V_15 ) ;
if ( F_16 ( V_29 ) ) {
F_3 ( L_5 ,
V_6 , F_17 ( V_11 ) , F_18 ( V_11 ) , V_29 ) ;
return V_29 ;
}
V_28 . V_33 = V_25 -> V_34 . V_35 ;
if ( V_28 . V_33 > sizeof( V_28 . V_36 ) ) {
F_3 ( L_6 ,
V_6 , sizeof( V_28 . V_36 ) ) ;
V_29 = - V_37 ;
goto V_38;
} else if ( V_28 . V_33 )
memcpy ( V_28 . V_36 , V_25 -> V_34 . V_39 ,
V_28 . V_33 ) ;
V_28 . V_40 = V_25 -> V_41 . V_35 ;
V_28 . V_42 = ( V_43 * ) V_25 -> V_41 . V_39 ;
if ( ! V_28 . V_40 && ! V_28 . V_33 ) {
F_3 ( L_7 ,
V_6 ) ;
V_29 = - V_44 ;
goto V_38;
}
V_7 = F_19 ( & V_28 ) ;
if ( F_16 ( F_20 ( V_7 ) ) ) {
V_29 = F_21 ( V_7 ) ;
F_3 ( L_8 , V_6 , V_29 ) ;
goto V_38;
}
V_26 = F_8 ( F_14 ( V_21 -> V_30 ) , V_11 , V_7 ,
V_15 ) ;
V_22 -> V_31 . V_32 [ V_23 ] = & V_26 -> V_7 ;
F_3 ( L_9 ,
F_17 ( V_11 ) , F_18 ( V_11 ) ) ;
V_38:
F_22 ( V_25 ) ;
return V_29 ;
}
static void F_23 ( struct V_45 * V_31 , unsigned V_23 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = & V_31 -> V_50 [ V_23 ] ;
F_24 ( V_47 -> V_51 . V_52 > 0 ) ;
F_24 ( V_47 -> V_53 . V_52 > sizeof( V_49 -> V_54 ) ) ;
V_49 -> V_55 . V_56 = V_47 -> V_57 . V_58 ;
V_49 -> V_55 . V_59 = V_47 -> V_57 . V_60 ;
memcpy ( V_49 -> V_54 , V_47 -> V_53 . V_54 , sizeof( V_49 -> V_54 ) ) ;
}
int F_25 ( unsigned V_61 , T_1 V_15 ,
struct V_17 * * V_62 )
{
struct V_63 {
struct V_17 V_64 ;
struct V_65 * V_32 [ V_61 ] ;
struct V_48 V_50 [ V_61 ] ;
} * V_66 ;
V_66 = F_9 ( sizeof( * V_66 ) , V_15 ) ;
if ( F_16 ( ! V_66 ) ) {
F_3 ( L_10 , V_6 ,
V_61 , sizeof( * V_66 ) ) ;
return - V_67 ;
}
V_66 -> V_64 . V_31 . V_61 = V_61 ;
V_66 -> V_64 . V_31 . V_68 = V_69 ;
V_66 -> V_64 . V_31 . V_50 = V_66 -> V_50 ;
V_66 -> V_64 . V_31 . V_32 = V_66 -> V_32 ;
* V_62 = & V_66 -> V_64 ;
return 0 ;
}
int F_26 ( struct V_18 * * V_70 ,
struct V_20 * V_21 ,
struct V_71 * V_72 ,
struct V_73 * V_74 ,
T_1 V_15 )
{
struct V_17 * V_22 ;
struct V_75 V_76 ;
struct V_77 V_78 ;
struct V_46 V_47 ;
unsigned V_79 ;
int V_29 ;
V_29 = F_27 ( & V_78 , & V_76 , V_74 ) ;
if ( F_16 ( V_29 ) )
return V_29 ;
V_29 = F_25 ( V_78 . V_80 , V_15 , & V_22 ) ;
if ( F_16 ( V_29 ) )
return V_29 ;
V_22 -> V_78 . V_81 = V_78 . V_82 . V_83 ;
V_22 -> V_78 . V_84 = V_78 . V_82 . V_85 ;
V_22 -> V_78 . V_86 = V_78 . V_82 . V_87 ;
V_22 -> V_78 . V_88 = V_78 . V_82 . V_89 + 1 ;
V_22 -> V_78 . V_90 = V_78 . V_82 . V_91 ;
V_29 = F_28 ( V_78 . V_82 . V_92 ,
& V_22 -> V_78 ) ;
if ( F_16 ( V_29 ) )
goto V_29;
V_22 -> V_31 . V_93 = V_78 . V_94 ;
V_79 = 0 ;
while ( F_29 ( & V_47 , & V_76 , V_74 , & V_29 ) ) {
F_23 ( & V_22 -> V_31 , V_79 , & V_47 ) ;
V_29 = F_13 ( V_21 , V_22 , V_79 ,
& V_47 . V_57 . V_95 ,
V_15 ) ;
if ( V_29 )
goto V_29;
++ V_79 ;
}
if ( F_16 ( V_29 ) )
goto V_29;
* V_70 = & V_22 -> V_19 ;
return 0 ;
V_29:
F_5 ( V_22 ) ;
F_3 ( L_11 , V_6 , V_29 ) ;
* V_70 = NULL ;
return V_29 ;
}
void F_30 ( struct V_18 * V_19 )
{
int V_96 ;
struct V_17 * V_22 = F_12 ( V_19 ) ;
for ( V_96 = 0 ; V_96 < V_22 -> V_31 . V_61 ; V_96 ++ ) {
struct V_65 * V_7 = V_22 -> V_31 . V_32 [ V_96 ] ;
struct V_3 * V_26 ;
if ( ! V_7 )
break;
V_26 = F_2 ( V_7 , F_31 ( * V_26 ) , V_7 ) ;
F_32 ( & V_26 -> V_5 ) ;
}
F_5 ( V_22 ) ;
}
static int
F_33 ( struct V_20 * V_97 , bool V_98 ,
struct V_18 * V_19 , struct V_99 * * V_100 , unsigned V_101 ,
T_2 V_102 , T_3 V_103 , void * V_104 , T_1 V_15 ,
struct V_105 * * V_70 )
{
struct V_17 * V_22 = F_12 ( V_19 ) ;
struct V_106 * V_107 ;
int V_108 ;
struct V_109 {
struct V_105 V_110 ;
struct V_111 V_112 [ V_22 -> V_31 . V_61 ] ;
} * V_113 ;
V_113 = F_9 ( sizeof( * V_113 ) , V_15 ) ;
if ( F_16 ( ! V_113 ) )
return - V_67 ;
F_34 ( & V_113 -> V_110 . V_114 , V_22 -> V_31 . V_61 ,
V_113 -> V_112 , V_104 , V_97 ) ;
V_108 = F_35 ( & V_22 -> V_78 , & V_22 -> V_31 , V_98 ,
V_102 , V_103 , & V_107 ) ;
if ( F_16 ( V_108 ) ) {
F_5 ( V_113 ) ;
return V_108 ;
}
V_107 -> V_100 = V_100 ;
V_107 -> V_101 = V_101 ;
V_107 -> V_115 = V_113 ;
F_36 ( V_107 -> V_116 > ( V_101 + V_103 + V_117 - 1 ) >> V_118 ) ;
V_113 -> V_110 . V_119 = 0 ;
V_113 -> V_110 . V_107 = V_107 ;
* V_70 = & V_113 -> V_110 ;
return 0 ;
}
void F_37 ( struct V_120 * V_114 )
{
struct V_105 * V_110 = F_2 ( V_114 , struct V_105 , V_114 ) ;
F_38 ( V_110 -> V_107 ) ;
F_5 ( V_110 ) ;
}
enum V_121 F_39 ( enum V_122 V_123 )
{
switch ( V_123 ) {
case V_124 :
return (enum V_121 ) 0 ;
case V_125 :
F_36 ( 1 ) ;
return 0 ;
case V_126 :
return V_127 ;
case V_128 :
return V_129 ;
case V_130 :
return V_131 ;
case V_132 :
return V_133 ;
case V_134 :
return V_135 ;
case V_136 :
return V_137 ;
default:
F_24 ( 1 ) ;
case V_138 :
return V_139 ;
}
}
static void F_40 ( struct V_106 * V_107 ,
struct V_65 * V_7 , unsigned V_140 , enum V_122 V_123 ,
T_4 V_141 , T_4 V_142 )
{
struct V_105 * V_110 = V_107 -> V_115 ;
struct V_143 V_144 ;
struct V_3 * V_26 = F_2 ( V_7 , F_31 ( * V_26 ) , V_7 ) ;
unsigned V_145 = V_140 ;
V_144 . V_95 = V_26 -> V_5 . V_146 ;
V_144 . V_58 = V_107 -> V_31 -> V_50 [ V_145 ] . V_55 . V_56 ;
V_144 . V_60 = V_107 -> V_31 -> V_50 [ V_145 ] . V_55 . V_59 ;
F_41 ( & V_110 -> V_114 , V_145 ,
& V_144 , F_39 ( V_123 ) ,
V_141 , V_142 , ! V_107 -> V_147 ) ;
}
static void F_42 ( struct V_106 * V_107 , void * V_115 )
{
struct V_105 * V_110 = V_115 ;
T_5 V_148 ;
int V_108 = F_43 ( V_107 , & F_40 ) ;
if ( F_44 ( ! V_108 ) )
V_148 = V_107 -> V_149 ;
else
V_148 = V_108 ;
F_45 ( & V_110 -> V_114 , V_148 , V_110 -> V_119 ) ;
}
int F_46 ( struct V_150 * V_151 )
{
struct V_105 * V_110 ;
int V_108 ;
V_108 = F_33 ( F_47 ( V_151 -> V_152 ) -> V_78 , true ,
V_151 -> V_19 , V_151 -> args . V_100 , V_151 -> args . V_101 ,
V_151 -> args . V_102 , V_151 -> args . V_103 , V_151 ,
V_153 , & V_110 ) ;
if ( F_16 ( V_108 ) )
return V_108 ;
V_110 -> V_107 -> V_154 = F_42 ;
F_3 ( L_12 , V_6 ,
V_151 -> args . V_102 , V_151 -> args . V_103 ) ;
return F_48 ( V_110 -> V_107 ) ;
}
static void F_49 ( struct V_106 * V_107 , void * V_115 )
{
struct V_105 * V_110 = V_115 ;
T_5 V_148 ;
int V_108 = F_43 ( V_107 , & F_40 ) ;
if ( F_44 ( ! V_108 ) ) {
V_110 -> V_114 . V_155 = V_156 ;
V_148 = V_107 -> V_149 ;
} else {
V_148 = V_108 ;
}
F_50 ( & V_110 -> V_114 , V_148 , V_110 -> V_119 ) ;
}
static struct V_99 * F_51 ( void * V_157 , T_4 V_102 , bool * V_158 )
{
struct V_105 * V_110 = V_157 ;
struct V_159 * V_160 = V_110 -> V_114 . V_104 ;
T_6 V_161 = V_102 / V_117 ;
struct V_99 * V_99 = F_52 ( V_160 -> V_152 -> V_162 , V_161 ) ;
if ( ! V_99 ) {
V_99 = F_53 ( V_160 -> V_152 -> V_162 ,
V_161 , V_163 ) ;
if ( F_16 ( ! V_99 ) ) {
F_3 ( L_13 ,
V_6 , V_161 ) ;
return NULL ;
}
F_54 ( V_99 ) ;
}
if ( F_55 ( V_99 ) || F_56 ( V_99 ) )
* V_158 = true ;
else
* V_158 = F_57 ( V_99 ) ;
F_3 ( L_14 , V_6 , V_161 , * V_158 ) ;
return V_99 ;
}
static void F_58 ( void * V_157 , struct V_99 * V_99 )
{
F_3 ( L_15 , V_6 , V_99 -> V_161 ) ;
F_59 ( V_99 ) ;
return;
}
int F_60 ( struct V_159 * V_160 , int V_164 )
{
struct V_105 * V_110 ;
int V_108 ;
V_108 = F_33 ( F_47 ( V_160 -> V_152 ) -> V_78 , false ,
V_160 -> V_19 , V_160 -> args . V_100 , V_160 -> args . V_101 ,
V_160 -> args . V_102 , V_160 -> args . V_103 , V_160 , V_163 ,
& V_110 ) ;
if ( F_16 ( V_108 ) )
return V_108 ;
V_110 -> V_119 = 0 != ( V_164 & V_165 ) ;
V_110 -> V_107 -> V_166 = & V_167 ;
if ( ! V_110 -> V_119 )
V_110 -> V_107 -> V_154 = F_49 ;
F_3 ( L_12 , V_6 ,
V_160 -> args . V_102 , V_160 -> args . V_103 ) ;
V_108 = F_61 ( V_110 -> V_107 ) ;
if ( F_16 ( V_108 ) )
return V_108 ;
if ( V_110 -> V_119 )
F_49 ( V_110 -> V_107 , V_110 ) ;
return 0 ;
}
static bool F_62 ( struct V_168 * V_169 ,
struct V_170 * V_171 , struct V_170 * V_172 )
{
if ( ! F_63 ( V_169 , V_171 , V_172 ) )
return false ;
return V_169 -> V_173 + V_172 -> V_174 <=
F_12 ( V_169 -> V_175 ) -> V_78 . V_176 ;
}
static int T_7
F_64 ( void )
{
int V_108 = F_65 ( & V_177 ) ;
if ( V_108 )
F_66 ( V_178
L_16 ,
V_6 , V_108 ) ;
else
F_66 ( V_178 L_17 ,
V_6 ) ;
return V_108 ;
}
static void T_8
F_67 ( void )
{
F_68 ( & V_177 ) ;
F_66 ( V_178 L_18 ,
V_6 ) ;
}
