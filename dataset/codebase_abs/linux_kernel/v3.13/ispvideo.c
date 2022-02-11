const struct V_1 *
F_1 ( enum V_2 V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_3 )
return & V_5 [ V_4 ] ;
}
return NULL ;
}
static unsigned int F_3 ( const struct V_6 * V_7 ,
const struct V_8 * V_9 ,
struct V_10 * V_11 )
{
unsigned int V_12 = V_11 -> V_13 ;
unsigned int V_14 ;
unsigned int V_4 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_15 = V_9 -> V_15 ;
V_11 -> V_16 = V_9 -> V_16 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_3 == V_9 -> V_3 )
break;
}
if ( F_4 ( V_4 == F_2 ( V_5 ) ) )
return 0 ;
V_14 = V_11 -> V_15 * V_5 [ V_4 ] . V_17 ;
if ( V_7 -> V_18 )
V_12 = F_5 ( V_12 , V_14 , V_7 -> V_18 ) ;
else
V_12 = V_14 ;
if ( ! V_7 -> V_19 || V_12 != V_14 )
V_12 = F_6 ( V_12 , V_7 -> V_20 ) ;
V_11 -> V_21 = V_5 [ V_4 ] . V_21 ;
V_11 -> V_13 = V_12 ;
V_11 -> V_22 = V_11 -> V_13 * V_11 -> V_16 ;
V_11 -> V_23 = V_9 -> V_23 ;
V_11 -> V_24 = V_9 -> V_24 ;
return V_12 - V_14 ;
}
static void F_7 ( const struct V_10 * V_11 ,
struct V_8 * V_9 )
{
unsigned int V_4 ;
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_15 = V_11 -> V_15 ;
V_9 -> V_16 = V_11 -> V_16 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_5 ) - 1 ; ++ V_4 ) {
if ( V_5 [ V_4 ] . V_21 == V_11 -> V_21 )
break;
}
V_9 -> V_3 = V_5 [ V_4 ] . V_3 ;
V_9 -> V_23 = V_11 -> V_23 ;
V_9 -> V_24 = V_11 -> V_24 ;
}
static struct V_25 *
F_8 ( struct V_6 * V_7 , T_1 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_9 ( & V_7 -> V_26 ) ;
if ( V_28 == NULL ||
F_10 ( V_28 -> V_29 ) != V_30 )
return NULL ;
if ( V_26 )
* V_26 = V_28 -> V_31 ;
return F_11 ( V_28 -> V_29 ) ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_32 * V_33 )
{
struct V_34 V_35 ;
struct V_36 * V_29 = & V_7 -> V_7 . V_29 ;
struct V_37 * V_38 = V_29 -> V_39 ;
struct V_6 * V_40 = NULL ;
F_13 ( & V_38 -> V_41 ) ;
F_14 ( & V_35 , V_29 ) ;
while ( ( V_29 = F_15 ( & V_35 ) ) ) {
struct V_6 * V_42 ;
V_33 -> V_43 |= 1 << V_29 -> V_44 ;
if ( V_40 != NULL )
continue;
if ( V_29 == & V_7 -> V_7 . V_29 )
continue;
if ( F_10 ( V_29 ) != V_45 )
continue;
V_42 = F_16 ( F_17 ( V_29 ) ) ;
if ( V_42 -> type != V_7 -> type )
V_40 = V_42 ;
}
F_18 ( & V_38 -> V_41 ) ;
if ( V_7 -> type == V_46 ) {
V_33 -> V_47 = V_40 ;
V_33 -> V_48 = V_7 ;
} else {
if ( V_40 == NULL )
return - V_49 ;
V_33 -> V_47 = V_7 ;
V_33 -> V_48 = V_40 ;
}
return 0 ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_50 * V_51 = V_33 -> V_48 -> V_51 ;
struct V_27 * V_26 ;
struct V_25 * V_52 ;
V_52 = F_8 ( V_33 -> V_48 , NULL ) ;
if ( V_52 == NULL )
return - V_49 ;
while ( 1 ) {
V_26 = & V_52 -> V_29 . V_53 [ 0 ] ;
if ( ! ( V_26 -> V_54 & V_55 ) )
break;
if ( V_52 == & V_51 -> V_56 . V_52 )
F_20 ( & V_51 -> V_56 ,
& V_33 -> V_57 ) ;
V_26 = F_9 ( V_26 ) ;
if ( V_26 == NULL )
return - V_49 ;
if ( F_10 ( V_26 -> V_29 ) != V_30 )
break;
V_52 = F_11 ( V_26 -> V_29 ) ;
}
return 0 ;
}
static int
F_21 ( struct V_6 * V_7 , struct V_58 * V_59 )
{
struct V_60 V_61 ;
struct V_25 * V_52 ;
T_1 V_26 ;
int V_62 ;
V_52 = F_8 ( V_7 , & V_26 ) ;
if ( V_52 == NULL )
return - V_63 ;
V_61 . V_26 = V_26 ;
V_61 . V_64 = V_65 ;
F_13 ( & V_7 -> V_66 ) ;
V_62 = F_22 ( V_52 , V_26 , V_67 , NULL , & V_61 ) ;
F_18 ( & V_7 -> V_66 ) ;
if ( V_62 )
return V_62 ;
V_59 -> type = V_7 -> type ;
return F_3 ( V_7 , & V_61 . V_59 , & V_59 -> V_61 . V_11 ) ;
}
static int
F_23 ( struct V_6 * V_7 , struct V_68 * V_69 )
{
struct V_58 V_59 ;
int V_62 ;
memcpy ( & V_59 , & V_69 -> V_59 , sizeof( V_59 ) ) ;
V_62 = F_21 ( V_7 , & V_59 ) ;
if ( V_62 < 0 )
return V_62 ;
if ( V_69 -> V_59 . V_61 . V_11 . V_21 != V_59 . V_61 . V_11 . V_21 ||
V_69 -> V_59 . V_61 . V_11 . V_16 != V_59 . V_61 . V_11 . V_16 ||
V_69 -> V_59 . V_61 . V_11 . V_15 != V_59 . V_61 . V_11 . V_15 ||
V_69 -> V_59 . V_61 . V_11 . V_13 != V_59 . V_61 . V_11 . V_13 ||
V_69 -> V_59 . V_61 . V_11 . V_22 != V_59 . V_61 . V_11 . V_22 )
return - V_63 ;
return V_62 ;
}
static T_2
F_24 ( struct V_50 * V_51 , const struct V_70 * V_71 , int V_72 )
{
struct V_73 * V_74 ;
T_1 V_75 ;
V_74 = F_25 ( sizeof( * V_74 ) , V_76 ) ;
if ( V_74 == NULL )
return - V_77 ;
V_74 -> V_78 = (struct V_70 * ) V_71 ;
V_74 -> V_79 = V_72 ;
V_74 -> V_80 = V_72 ;
V_75 = F_26 ( V_51 -> V_81 , V_51 -> V_82 , 0 , V_74 , V_83 ) ;
if ( F_27 ( V_75 ) )
F_28 ( V_74 ) ;
return V_75 ;
}
static void F_29 ( struct V_50 * V_51 , T_2 V_75 )
{
struct V_73 * V_74 ;
V_74 = F_30 ( V_51 -> V_81 , V_51 -> V_82 , ( T_1 ) V_75 ) ;
F_28 ( V_74 ) ;
}
static void F_31 ( struct V_84 * V_85 ,
unsigned int * V_86 , unsigned int * V_87 )
{
struct V_68 * V_69 =
F_32 ( V_85 , struct V_68 , V_85 ) ;
struct V_6 * V_7 = V_69 -> V_7 ;
* V_87 = V_69 -> V_59 . V_61 . V_11 . V_22 ;
if ( * V_87 == 0 )
return;
* V_86 = F_33 ( * V_86 , V_7 -> V_88 / F_34 ( * V_87 ) ) ;
}
static void F_35 ( struct V_89 * V_90 )
{
struct V_68 * V_69 = F_36 ( V_90 -> V_85 ) ;
struct V_91 * V_92 = F_37 ( V_90 ) ;
struct V_6 * V_7 = V_69 -> V_7 ;
if ( V_92 -> V_93 ) {
F_29 ( V_7 -> V_51 , V_92 -> V_93 ) ;
V_92 -> V_93 = 0 ;
}
}
static int F_38 ( struct V_89 * V_90 )
{
struct V_68 * V_69 = F_36 ( V_90 -> V_85 ) ;
struct V_91 * V_92 = F_37 ( V_90 ) ;
struct V_6 * V_7 = V_69 -> V_7 ;
unsigned long V_94 ;
V_94 = F_24 ( V_7 -> V_51 , V_90 -> V_71 , V_90 -> V_72 ) ;
if ( F_27 ( V_94 ) )
return - V_95 ;
if ( ! F_39 ( V_94 , 32 ) ) {
F_40 ( V_7 -> V_51 -> V_82 , L_1
L_2 ) ;
F_29 ( V_7 -> V_51 , V_92 -> V_93 ) ;
return - V_63 ;
}
V_90 -> V_96 . V_97 = V_69 -> V_59 . V_61 . V_11 . V_22 ;
V_92 -> V_93 = V_94 ;
return 0 ;
}
static void F_41 ( struct V_89 * V_90 )
{
struct V_68 * V_69 = F_36 ( V_90 -> V_85 ) ;
struct V_91 * V_92 = F_37 ( V_90 ) ;
struct V_6 * V_7 = V_69 -> V_7 ;
struct V_32 * V_33 = F_42 ( & V_7 -> V_7 . V_29 ) ;
enum V_98 V_99 ;
unsigned long V_54 ;
unsigned int V_100 ;
unsigned int V_101 ;
V_100 = F_43 ( & V_7 -> V_102 ) ;
F_44 ( & V_92 -> V_92 . V_103 , & V_7 -> V_102 ) ;
if ( V_100 ) {
if ( V_7 -> type == V_46 )
V_99 = V_104 ;
else
V_99 = V_105 ;
F_45 ( & V_33 -> V_106 , V_54 ) ;
V_33 -> V_99 |= V_99 ;
V_7 -> V_107 -> V_85 ( V_7 , V_92 ) ;
V_7 -> V_108 |= V_109 ;
V_101 = F_46 ( V_33 ) ;
if ( V_101 )
V_33 -> V_99 |= V_110 ;
F_47 ( & V_33 -> V_106 , V_54 ) ;
if ( V_101 )
F_48 ( V_33 ,
V_111 ) ;
}
}
struct V_91 * F_49 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = F_42 ( & V_7 -> V_7 . V_29 ) ;
struct V_84 * V_85 = V_7 -> V_85 ;
enum V_98 V_99 ;
struct V_89 * V_90 ;
unsigned long V_54 ;
struct V_112 V_113 ;
F_45 ( & V_85 -> V_114 , V_54 ) ;
if ( F_4 ( F_43 ( & V_7 -> V_102 ) ) ) {
F_47 ( & V_85 -> V_114 , V_54 ) ;
return NULL ;
}
V_90 = F_50 ( & V_7 -> V_102 , struct V_89 ,
V_103 ) ;
F_51 ( & V_90 -> V_103 ) ;
F_47 ( & V_85 -> V_114 , V_54 ) ;
F_52 ( & V_113 ) ;
V_90 -> V_96 . V_115 . V_116 = V_113 . V_116 ;
V_90 -> V_96 . V_115 . V_117 = V_113 . V_118 / V_119 ;
if ( V_7 == V_33 -> V_48 && ! V_33 -> V_120 )
V_90 -> V_96 . V_121 = F_53 ( & V_33 -> V_122 ) ;
else
V_90 -> V_96 . V_121 = F_54 ( & V_33 -> V_122 ) ;
if ( V_85 -> type == V_46 && V_33 -> error ) {
V_90 -> V_99 = V_123 ;
V_33 -> error = false ;
} else {
V_90 -> V_99 = V_124 ;
}
F_55 ( & V_90 -> V_125 ) ;
if ( F_43 ( & V_7 -> V_102 ) ) {
if ( V_85 -> type == V_46 )
V_99 = V_104
| V_110 ;
else
V_99 = V_105
| V_110 ;
F_45 ( & V_33 -> V_106 , V_54 ) ;
V_33 -> V_99 &= ~ V_99 ;
if ( V_7 -> V_33 . V_126 == V_127 )
V_7 -> V_108 |= V_128 ;
F_47 ( & V_33 -> V_106 , V_54 ) ;
return NULL ;
}
if ( V_85 -> type == V_46 && V_33 -> V_47 != NULL ) {
F_45 ( & V_33 -> V_106 , V_54 ) ;
V_33 -> V_99 &= ~ V_110 ;
F_47 ( & V_33 -> V_106 , V_54 ) ;
}
V_90 = F_50 ( & V_7 -> V_102 , struct V_89 ,
V_103 ) ;
V_90 -> V_99 = V_129 ;
return F_37 ( V_90 ) ;
}
void F_56 ( struct V_6 * V_7 , int V_130 )
{
struct V_91 * V_90 = NULL ;
if ( V_130 && V_7 -> type == V_46 )
F_57 ( V_7 -> V_85 ) ;
if ( ! F_43 ( & V_7 -> V_102 ) ) {
V_90 = F_50 ( & V_7 -> V_102 ,
struct V_91 , V_92 . V_103 ) ;
V_7 -> V_107 -> V_85 ( V_7 , V_90 ) ;
V_7 -> V_108 |= V_109 ;
} else {
if ( V_130 )
V_7 -> V_108 |= V_128 ;
}
}
static int
F_58 ( struct V_131 * V_131 , void * V_132 , struct V_133 * V_134 )
{
struct V_6 * V_7 = F_59 ( V_131 ) ;
F_60 ( V_134 -> V_135 , V_136 , sizeof( V_134 -> V_135 ) ) ;
F_60 ( V_134 -> V_137 , V_7 -> V_7 . V_138 , sizeof( V_134 -> V_137 ) ) ;
F_60 ( V_134 -> V_139 , L_3 , sizeof( V_134 -> V_139 ) ) ;
if ( V_7 -> type == V_46 )
V_134 -> V_140 = V_141 | V_142 ;
else
V_134 -> V_140 = V_143 | V_142 ;
return 0 ;
}
static int
F_61 ( struct V_131 * V_131 , void * V_132 , struct V_58 * V_59 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
struct V_6 * V_7 = F_59 ( V_131 ) ;
if ( V_59 -> type != V_7 -> type )
return - V_63 ;
F_13 ( & V_7 -> V_66 ) ;
* V_59 = V_69 -> V_59 ;
F_18 ( & V_7 -> V_66 ) ;
return 0 ;
}
static int
F_63 ( struct V_131 * V_131 , void * V_132 , struct V_58 * V_59 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_8 V_61 ;
if ( V_59 -> type != V_7 -> type )
return - V_63 ;
F_13 ( & V_7 -> V_66 ) ;
F_7 ( & V_59 -> V_61 . V_11 , & V_61 ) ;
F_3 ( V_7 , & V_61 , & V_59 -> V_61 . V_11 ) ;
V_69 -> V_59 = * V_59 ;
F_18 ( & V_7 -> V_66 ) ;
return 0 ;
}
static int
F_64 ( struct V_131 * V_131 , void * V_132 , struct V_58 * V_59 )
{
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_60 V_61 ;
struct V_25 * V_52 ;
T_1 V_26 ;
int V_62 ;
if ( V_59 -> type != V_7 -> type )
return - V_63 ;
V_52 = F_8 ( V_7 , & V_26 ) ;
if ( V_52 == NULL )
return - V_63 ;
F_7 ( & V_59 -> V_61 . V_11 , & V_61 . V_59 ) ;
V_61 . V_26 = V_26 ;
V_61 . V_64 = V_65 ;
V_62 = F_22 ( V_52 , V_26 , V_67 , NULL , & V_61 ) ;
if ( V_62 )
return V_62 == - V_144 ? - V_145 : V_62 ;
F_3 ( V_7 , & V_61 . V_59 , & V_59 -> V_61 . V_11 ) ;
return 0 ;
}
static int
F_65 ( struct V_131 * V_131 , void * V_132 , struct V_146 * V_147 )
{
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_25 * V_52 ;
int V_62 ;
V_52 = F_8 ( V_7 , NULL ) ;
if ( V_52 == NULL )
return - V_63 ;
F_13 ( & V_7 -> V_66 ) ;
V_62 = F_22 ( V_52 , V_7 , V_147 , V_147 ) ;
F_18 ( & V_7 -> V_66 ) ;
return V_62 == - V_144 ? - V_145 : V_62 ;
}
static int
F_66 ( struct V_131 * V_131 , void * V_132 , struct V_148 * V_149 )
{
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_60 V_59 ;
struct V_25 * V_52 ;
T_1 V_26 ;
int V_62 ;
V_52 = F_8 ( V_7 , & V_26 ) ;
if ( V_52 == NULL )
return - V_63 ;
V_62 = F_22 ( V_52 , V_7 , V_150 , V_149 ) ;
if ( V_62 != - V_144 )
return V_62 ;
V_59 . V_26 = V_26 ;
V_59 . V_64 = V_65 ;
V_62 = F_22 ( V_52 , V_26 , V_67 , NULL , & V_59 ) ;
if ( V_62 < 0 )
return V_62 == - V_144 ? - V_145 : V_62 ;
V_149 -> V_151 . V_152 = 0 ;
V_149 -> V_151 . V_153 = 0 ;
V_149 -> V_151 . V_15 = V_59 . V_59 . V_15 ;
V_149 -> V_151 . V_16 = V_59 . V_59 . V_16 ;
return 0 ;
}
static int
F_67 ( struct V_131 * V_131 , void * V_132 , const struct V_148 * V_149 )
{
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_25 * V_52 ;
int V_62 ;
V_52 = F_8 ( V_7 , NULL ) ;
if ( V_52 == NULL )
return - V_63 ;
F_13 ( & V_7 -> V_66 ) ;
V_62 = F_22 ( V_52 , V_7 , V_154 , V_149 ) ;
F_18 ( & V_7 -> V_66 ) ;
return V_62 == - V_144 ? - V_145 : V_62 ;
}
static int
F_68 ( struct V_131 * V_131 , void * V_132 , struct V_155 * V_156 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
struct V_6 * V_7 = F_59 ( V_131 ) ;
if ( V_7 -> type != V_157 ||
V_7 -> type != V_156 -> type )
return - V_63 ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
V_156 -> type = V_157 ;
V_156 -> V_158 . V_48 . V_159 = V_160 ;
V_156 -> V_158 . V_48 . V_161 = V_69 -> V_161 ;
return 0 ;
}
static int
F_69 ( struct V_131 * V_131 , void * V_132 , struct V_155 * V_156 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
struct V_6 * V_7 = F_59 ( V_131 ) ;
if ( V_7 -> type != V_157 ||
V_7 -> type != V_156 -> type )
return - V_63 ;
if ( V_156 -> V_158 . V_48 . V_161 . V_162 == 0 )
V_156 -> V_158 . V_48 . V_161 . V_162 = 1 ;
V_69 -> V_161 = V_156 -> V_158 . V_48 . V_161 ;
return 0 ;
}
static int
F_70 ( struct V_131 * V_131 , void * V_132 , struct V_163 * V_164 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
return F_71 ( & V_69 -> V_85 , V_164 ) ;
}
static int
F_72 ( struct V_131 * V_131 , void * V_132 , struct V_165 * V_166 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
return F_73 ( & V_69 -> V_85 , V_166 ) ;
}
static int
F_74 ( struct V_131 * V_131 , void * V_132 , struct V_165 * V_166 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
return F_75 ( & V_69 -> V_85 , V_166 ) ;
}
static int
F_76 ( struct V_131 * V_131 , void * V_132 , struct V_165 * V_166 )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
return F_77 ( & V_69 -> V_85 , V_166 ,
V_131 -> V_167 & V_168 ) ;
}
static int F_78 ( struct V_6 * V_7 ,
struct V_32 * V_33 )
{
struct V_50 * V_51 = V_7 -> V_51 ;
struct V_36 * V_169 [] = {
& V_51 -> V_170 . V_52 . V_29 ,
& V_51 -> V_171 . V_52 . V_29 ,
& V_51 -> V_172 . V_52 . V_29 ,
& V_51 -> V_173 . V_52 . V_29
} ;
struct V_27 * V_174 ;
struct V_36 * V_175 = NULL ;
struct V_36 * V_176 ;
struct V_60 V_61 ;
struct V_177 V_178 ;
struct V_179 V_180 ;
unsigned int V_4 ;
int V_62 = 0 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_169 ) ; V_4 ++ ) {
if ( ! ( V_33 -> V_43 & ( 1 << V_169 [ V_4 ] -> V_44 ) ) )
continue;
V_174 = F_9 ( & V_169 [ V_4 ] -> V_53 [ 0 ] ) ;
if ( V_174 == NULL )
continue;
V_175 = V_174 -> V_29 ;
V_176 = V_169 [ V_4 ] ;
break;
}
if ( ! V_175 ) {
F_79 ( V_51 -> V_82 , L_4 ) ;
return V_62 ;
}
if ( F_10 ( V_175 ) != V_30 )
return 0 ;
V_33 -> V_181 = F_11 ( V_175 ) ;
V_61 . V_26 = V_174 -> V_31 ;
V_61 . V_64 = V_65 ;
V_62 = F_22 ( F_11 ( V_176 ) ,
V_26 , V_67 , NULL , & V_61 ) ;
if ( F_80 ( V_62 < 0 ) ) {
F_79 ( V_51 -> V_82 , L_5 ) ;
return V_62 ;
}
V_33 -> V_182 =
F_1 ( V_61 . V_59 . V_3 ) -> V_15 ;
memset ( & V_178 , 0 , sizeof( V_178 ) ) ;
memset ( & V_180 , 0 , sizeof( V_180 ) ) ;
V_180 . V_44 = V_183 ;
V_178 . V_184 = 1 ;
V_178 . V_185 = & V_180 ;
V_62 = F_81 ( V_33 -> V_181 -> V_186 , & V_178 ) ;
if ( V_62 < 0 ) {
F_79 ( V_51 -> V_82 , L_6 ,
V_33 -> V_181 -> V_138 ) ;
return V_62 ;
}
V_33 -> V_187 = V_180 . V_188 ;
if ( V_33 -> V_43 & ( 1 << V_51 -> V_173 . V_52 . V_29 . V_44 ) ) {
unsigned int V_189 = V_190 ;
F_82 ( & V_51 -> V_173 , & V_189 ) ;
if ( V_33 -> V_187 > V_189 )
return - V_191 ;
}
return 0 ;
}
static int
F_83 ( struct V_131 * V_131 , void * V_132 , enum V_192 type )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
struct V_6 * V_7 = F_59 ( V_131 ) ;
enum V_98 V_99 ;
struct V_32 * V_33 ;
unsigned long V_54 ;
int V_62 ;
if ( type != V_7 -> type )
return - V_63 ;
F_13 ( & V_7 -> V_193 ) ;
if ( V_7 -> V_194 ) {
F_18 ( & V_7 -> V_193 ) ;
return - V_195 ;
}
V_33 = V_7 -> V_7 . V_29 . V_33
? F_42 ( & V_7 -> V_7 . V_29 ) : & V_7 -> V_33 ;
V_33 -> V_43 = 0 ;
if ( V_7 -> V_51 -> V_196 -> V_197 )
V_7 -> V_51 -> V_196 -> V_197 ( V_7 -> V_51 , true ) ;
V_33 -> V_198 = F_84 ( V_7 -> V_51 -> clock [ V_199 ] ) ;
V_33 -> V_57 = V_33 -> V_198 ;
V_62 = F_85 ( & V_7 -> V_7 . V_29 , & V_33 -> V_33 ) ;
if ( V_62 < 0 )
goto V_200;
V_62 = F_23 ( V_7 , V_69 ) ;
if ( V_62 < 0 )
goto V_201;
V_7 -> V_202 = V_62 ;
V_7 -> V_203 = V_69 -> V_59 . V_61 . V_11 . V_13 ;
V_62 = F_12 ( V_7 , V_33 ) ;
if ( V_62 < 0 )
goto V_201;
if ( V_7 -> type == V_46 )
V_99 = V_204 | V_205 ;
else
V_99 = V_206 | V_207 ;
V_62 = F_78 ( V_7 , V_33 ) ;
if ( V_62 < 0 )
goto V_201;
V_62 = F_19 ( V_33 ) ;
if ( V_62 < 0 )
goto V_201;
V_33 -> error = false ;
F_45 ( & V_33 -> V_106 , V_54 ) ;
V_33 -> V_99 &= ~ V_110 ;
V_33 -> V_99 |= V_99 ;
F_47 ( & V_33 -> V_106 , V_54 ) ;
if ( V_7 -> type == V_157 )
V_33 -> V_208 = V_69 -> V_161 ;
V_7 -> V_85 = & V_69 -> V_85 ;
F_86 ( & V_7 -> V_102 ) ;
F_87 ( & V_33 -> V_122 , - 1 ) ;
V_62 = F_88 ( & V_69 -> V_85 ) ;
if ( V_62 < 0 )
goto V_201;
if ( V_33 -> V_47 == NULL ) {
V_62 = F_48 ( V_33 ,
V_127 ) ;
if ( V_62 < 0 )
goto V_209;
F_45 ( & V_7 -> V_85 -> V_114 , V_54 ) ;
if ( F_43 ( & V_7 -> V_102 ) )
V_7 -> V_108 |= V_128 ;
F_47 ( & V_7 -> V_85 -> V_114 , V_54 ) ;
}
V_7 -> V_194 = 1 ;
F_18 ( & V_7 -> V_193 ) ;
return 0 ;
V_209:
F_89 ( & V_69 -> V_85 ) ;
V_201:
F_90 ( & V_7 -> V_7 . V_29 ) ;
V_200:
if ( V_7 -> V_51 -> V_196 -> V_197 )
V_7 -> V_51 -> V_196 -> V_197 ( V_7 -> V_51 , false ) ;
F_86 ( & V_7 -> V_102 ) ;
V_7 -> V_85 = NULL ;
F_18 ( & V_7 -> V_193 ) ;
return V_62 ;
}
static int
F_91 ( struct V_131 * V_131 , void * V_132 , enum V_192 type )
{
struct V_68 * V_69 = F_62 ( V_132 ) ;
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_32 * V_33 = F_42 ( & V_7 -> V_7 . V_29 ) ;
enum V_98 V_99 ;
unsigned int V_194 ;
unsigned long V_54 ;
if ( type != V_7 -> type )
return - V_63 ;
F_13 ( & V_7 -> V_193 ) ;
F_13 ( & V_69 -> V_85 . V_106 ) ;
V_194 = V_69 -> V_85 . V_194 ;
F_18 ( & V_69 -> V_85 . V_106 ) ;
if ( ! V_194 )
goto V_210;
if ( V_7 -> type == V_46 )
V_99 = V_204
| V_104 ;
else
V_99 = V_206
| V_105 ;
F_45 ( & V_33 -> V_106 , V_54 ) ;
V_33 -> V_99 &= ~ V_99 ;
F_47 ( & V_33 -> V_106 , V_54 ) ;
F_48 ( V_33 , V_211 ) ;
F_89 ( & V_69 -> V_85 ) ;
V_7 -> V_85 = NULL ;
V_7 -> V_194 = 0 ;
if ( V_7 -> V_51 -> V_196 -> V_197 )
V_7 -> V_51 -> V_196 -> V_197 ( V_7 -> V_51 , false ) ;
F_90 ( & V_7 -> V_7 . V_29 ) ;
V_210:
F_18 ( & V_7 -> V_193 ) ;
return 0 ;
}
static int
F_92 ( struct V_131 * V_131 , void * V_132 , struct V_212 * V_47 )
{
if ( V_47 -> V_31 > 0 )
return - V_63 ;
F_60 ( V_47 -> V_138 , L_7 , sizeof( V_47 -> V_138 ) ) ;
V_47 -> type = V_213 ;
return 0 ;
}
static int
F_93 ( struct V_131 * V_131 , void * V_132 , unsigned int * V_47 )
{
* V_47 = 0 ;
return 0 ;
}
static int
F_94 ( struct V_131 * V_131 , void * V_132 , unsigned int V_47 )
{
return V_47 == 0 ? 0 : - V_63 ;
}
static int F_95 ( struct V_131 * V_131 )
{
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_68 * V_214 ;
int V_62 = 0 ;
V_214 = F_96 ( sizeof( * V_214 ) , V_76 ) ;
if ( V_214 == NULL )
return - V_77 ;
F_97 ( & V_214 -> V_69 , & V_7 -> V_7 ) ;
F_98 ( & V_214 -> V_69 ) ;
if ( F_99 ( V_7 -> V_51 ) == NULL ) {
V_62 = - V_195 ;
goto V_210;
}
V_62 = F_100 ( & V_7 -> V_7 . V_29 , 1 ) ;
if ( V_62 < 0 ) {
F_101 ( V_7 -> V_51 ) ;
goto V_210;
}
F_102 ( & V_214 -> V_85 , V_7 -> type ,
& V_215 , V_7 -> V_51 -> V_82 ,
sizeof( struct V_91 ) ) ;
memset ( & V_214 -> V_59 , 0 , sizeof( V_214 -> V_59 ) ) ;
V_214 -> V_59 . type = V_7 -> type ;
V_214 -> V_161 . V_162 = 1 ;
V_214 -> V_7 = V_7 ;
V_131 -> V_216 = & V_214 -> V_69 ;
V_210:
if ( V_62 < 0 ) {
F_103 ( & V_214 -> V_69 ) ;
F_28 ( V_214 ) ;
}
return V_62 ;
}
static int F_104 ( struct V_131 * V_131 )
{
struct V_6 * V_7 = F_59 ( V_131 ) ;
struct V_217 * V_69 = V_131 -> V_216 ;
struct V_68 * V_214 = F_62 ( V_69 ) ;
F_91 ( V_131 , V_69 , V_7 -> type ) ;
F_13 ( & V_214 -> V_85 . V_106 ) ;
F_105 ( & V_214 -> V_85 ) ;
F_18 ( & V_214 -> V_85 . V_106 ) ;
F_100 ( & V_7 -> V_7 . V_29 , 0 ) ;
F_103 ( V_69 ) ;
F_28 ( V_214 ) ;
V_131 -> V_216 = NULL ;
F_101 ( V_7 -> V_51 ) ;
return 0 ;
}
static unsigned int F_106 ( struct V_131 * V_131 , T_3 * V_125 )
{
struct V_68 * V_69 = F_62 ( V_131 -> V_216 ) ;
struct V_84 * V_85 = & V_69 -> V_85 ;
return F_107 ( V_85 , V_131 , V_125 ) ;
}
static int F_108 ( struct V_131 * V_131 , struct V_218 * V_219 )
{
struct V_68 * V_69 = F_62 ( V_131 -> V_216 ) ;
return F_109 ( & V_69 -> V_85 , V_219 ) ;
}
int F_110 ( struct V_6 * V_7 , const char * V_138 )
{
const char * V_220 ;
int V_62 ;
switch ( V_7 -> type ) {
case V_46 :
V_220 = L_8 ;
V_7 -> V_26 . V_54 = V_55 ;
break;
case V_157 :
V_220 = L_9 ;
V_7 -> V_26 . V_54 = V_221 ;
V_7 -> V_7 . V_222 = V_223 ;
break;
default:
return - V_63 ;
}
V_62 = F_111 ( & V_7 -> V_7 . V_29 , 1 , & V_7 -> V_26 , 0 ) ;
if ( V_62 < 0 )
return V_62 ;
F_112 ( & V_7 -> V_66 ) ;
F_87 ( & V_7 -> V_224 , 0 ) ;
F_113 ( & V_7 -> V_33 . V_106 ) ;
F_112 ( & V_7 -> V_193 ) ;
if ( V_7 -> V_107 == NULL )
V_7 -> V_107 = & V_225 ;
V_7 -> V_7 . V_226 = & V_227 ;
snprintf ( V_7 -> V_7 . V_138 , sizeof( V_7 -> V_7 . V_138 ) ,
L_10 , V_138 , V_220 ) ;
V_7 -> V_7 . V_228 = V_229 ;
V_7 -> V_7 . V_230 = V_231 ;
V_7 -> V_7 . V_232 = & V_233 ;
V_7 -> V_33 . V_126 = V_211 ;
F_114 ( & V_7 -> V_7 , V_7 ) ;
return 0 ;
}
void F_115 ( struct V_6 * V_7 )
{
F_116 ( & V_7 -> V_7 . V_29 ) ;
F_117 ( & V_7 -> V_193 ) ;
F_117 ( & V_7 -> V_66 ) ;
}
int F_118 ( struct V_6 * V_7 , struct V_234 * V_235 )
{
int V_62 ;
V_7 -> V_7 . V_236 = V_235 ;
V_62 = F_119 ( & V_7 -> V_7 , V_229 , - 1 ) ;
if ( V_62 < 0 )
F_120 ( V_7 -> V_51 -> V_82 ,
L_11 ,
V_237 , V_62 ) ;
return V_62 ;
}
void F_121 ( struct V_6 * V_7 )
{
if ( F_122 ( & V_7 -> V_7 ) )
F_123 ( & V_7 -> V_7 ) ;
}
