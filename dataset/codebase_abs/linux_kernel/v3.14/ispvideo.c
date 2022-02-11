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
static int
F_19 ( struct V_6 * V_7 , struct V_50 * V_51 )
{
struct V_52 V_53 ;
struct V_25 * V_54 ;
T_1 V_26 ;
int V_55 ;
V_54 = F_8 ( V_7 , & V_26 ) ;
if ( V_54 == NULL )
return - V_56 ;
V_53 . V_26 = V_26 ;
V_53 . V_57 = V_58 ;
F_13 ( & V_7 -> V_59 ) ;
V_55 = F_20 ( V_54 , V_26 , V_60 , NULL , & V_53 ) ;
F_18 ( & V_7 -> V_59 ) ;
if ( V_55 )
return V_55 ;
V_51 -> type = V_7 -> type ;
return F_3 ( V_7 , & V_53 . V_51 , & V_51 -> V_53 . V_11 ) ;
}
static int
F_21 ( struct V_6 * V_7 , struct V_61 * V_62 )
{
struct V_50 V_51 ;
int V_55 ;
memcpy ( & V_51 , & V_62 -> V_51 , sizeof( V_51 ) ) ;
V_55 = F_19 ( V_7 , & V_51 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( V_62 -> V_51 . V_53 . V_11 . V_21 != V_51 . V_53 . V_11 . V_21 ||
V_62 -> V_51 . V_53 . V_11 . V_16 != V_51 . V_53 . V_11 . V_16 ||
V_62 -> V_51 . V_53 . V_11 . V_15 != V_51 . V_53 . V_11 . V_15 ||
V_62 -> V_51 . V_53 . V_11 . V_13 != V_51 . V_53 . V_11 . V_13 ||
V_62 -> V_51 . V_53 . V_11 . V_22 != V_51 . V_53 . V_11 . V_22 )
return - V_56 ;
return V_55 ;
}
static T_2
F_22 ( struct V_63 * V_64 , const struct V_65 * V_66 , int V_67 )
{
struct V_68 * V_69 ;
T_1 V_70 ;
V_69 = F_23 ( sizeof( * V_69 ) , V_71 ) ;
if ( V_69 == NULL )
return - V_72 ;
V_69 -> V_73 = (struct V_65 * ) V_66 ;
V_69 -> V_74 = V_67 ;
V_69 -> V_75 = V_67 ;
V_70 = F_24 ( V_64 -> V_76 , V_64 -> V_77 , 0 , V_69 , V_78 ) ;
if ( F_25 ( V_70 ) )
F_26 ( V_69 ) ;
return V_70 ;
}
static void F_27 ( struct V_63 * V_64 , T_2 V_70 )
{
struct V_68 * V_69 ;
V_69 = F_28 ( V_64 -> V_76 , V_64 -> V_77 , ( T_1 ) V_70 ) ;
F_26 ( V_69 ) ;
}
static void F_29 ( struct V_79 * V_80 ,
unsigned int * V_81 , unsigned int * V_82 )
{
struct V_61 * V_62 =
F_30 ( V_80 , struct V_61 , V_80 ) ;
struct V_6 * V_7 = V_62 -> V_7 ;
* V_82 = V_62 -> V_51 . V_53 . V_11 . V_22 ;
if ( * V_82 == 0 )
return;
* V_81 = F_31 ( * V_81 , V_7 -> V_83 / F_32 ( * V_82 ) ) ;
}
static void F_33 ( struct V_84 * V_85 )
{
struct V_61 * V_62 = F_34 ( V_85 -> V_80 ) ;
struct V_86 * V_87 = F_35 ( V_85 ) ;
struct V_6 * V_7 = V_62 -> V_7 ;
if ( V_87 -> V_88 ) {
F_27 ( V_7 -> V_64 , V_87 -> V_88 ) ;
V_87 -> V_88 = 0 ;
}
}
static int F_36 ( struct V_84 * V_85 )
{
struct V_61 * V_62 = F_34 ( V_85 -> V_80 ) ;
struct V_86 * V_87 = F_35 ( V_85 ) ;
struct V_6 * V_7 = V_62 -> V_7 ;
unsigned long V_89 ;
if ( F_37 ( V_7 -> error ) )
return - V_90 ;
V_89 = F_22 ( V_7 -> V_64 , V_85 -> V_66 , V_85 -> V_67 ) ;
if ( F_25 ( V_89 ) )
return - V_90 ;
if ( ! F_38 ( V_89 , 32 ) ) {
F_39 ( V_7 -> V_64 -> V_77 , L_1
L_2 ) ;
F_27 ( V_7 -> V_64 , V_87 -> V_88 ) ;
return - V_56 ;
}
V_85 -> V_91 . V_92 = V_62 -> V_51 . V_53 . V_11 . V_22 ;
V_87 -> V_88 = V_89 ;
return 0 ;
}
static void F_40 ( struct V_84 * V_85 )
{
struct V_61 * V_62 = F_34 ( V_85 -> V_80 ) ;
struct V_86 * V_87 = F_35 ( V_85 ) ;
struct V_6 * V_7 = V_62 -> V_7 ;
struct V_32 * V_33 = F_41 ( & V_7 -> V_7 . V_29 ) ;
enum V_93 V_94 ;
unsigned long V_95 ;
unsigned int V_96 ;
unsigned int V_97 ;
if ( F_37 ( V_7 -> error ) ) {
V_85 -> V_94 = V_98 ;
F_42 ( & V_85 -> V_99 ) ;
return;
}
V_96 = F_43 ( & V_7 -> V_100 ) ;
F_44 ( & V_87 -> V_87 . V_101 , & V_7 -> V_100 ) ;
if ( V_96 ) {
if ( V_7 -> type == V_46 )
V_94 = V_102 ;
else
V_94 = V_103 ;
F_45 ( & V_33 -> V_104 , V_95 ) ;
V_33 -> V_94 |= V_94 ;
V_7 -> V_105 -> V_80 ( V_7 , V_87 ) ;
V_7 -> V_106 |= V_107 ;
V_97 = F_46 ( V_33 ) ;
if ( V_97 )
V_33 -> V_94 |= V_108 ;
F_47 ( & V_33 -> V_104 , V_95 ) ;
if ( V_97 )
F_48 ( V_33 ,
V_109 ) ;
}
}
struct V_86 * F_49 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = F_41 ( & V_7 -> V_7 . V_29 ) ;
struct V_79 * V_80 = V_7 -> V_80 ;
enum V_93 V_94 ;
struct V_84 * V_85 ;
unsigned long V_95 ;
struct V_110 V_111 ;
F_45 ( & V_80 -> V_112 , V_95 ) ;
if ( F_4 ( F_43 ( & V_7 -> V_100 ) ) ) {
F_47 ( & V_80 -> V_112 , V_95 ) ;
return NULL ;
}
V_85 = F_50 ( & V_7 -> V_100 , struct V_84 ,
V_101 ) ;
F_51 ( & V_85 -> V_101 ) ;
F_47 ( & V_80 -> V_112 , V_95 ) ;
F_52 ( & V_111 ) ;
V_85 -> V_91 . V_113 . V_114 = V_111 . V_114 ;
V_85 -> V_91 . V_113 . V_115 = V_111 . V_116 / V_117 ;
if ( V_7 == V_33 -> V_48 && ! V_33 -> V_118 )
V_85 -> V_91 . V_119 = F_53 ( & V_33 -> V_120 ) ;
else
V_85 -> V_91 . V_119 = F_54 ( & V_33 -> V_120 ) ;
if ( V_80 -> type == V_46 && V_33 -> error ) {
V_85 -> V_94 = V_98 ;
V_33 -> error = false ;
} else {
V_85 -> V_94 = V_121 ;
}
F_42 ( & V_85 -> V_99 ) ;
if ( F_43 ( & V_7 -> V_100 ) ) {
if ( V_80 -> type == V_46 )
V_94 = V_102
| V_108 ;
else
V_94 = V_103
| V_108 ;
F_45 ( & V_33 -> V_104 , V_95 ) ;
V_33 -> V_94 &= ~ V_94 ;
if ( V_7 -> V_33 . V_122 == V_123 )
V_7 -> V_106 |= V_124 ;
F_47 ( & V_33 -> V_104 , V_95 ) ;
return NULL ;
}
if ( V_80 -> type == V_46 && V_33 -> V_47 != NULL ) {
F_45 ( & V_33 -> V_104 , V_95 ) ;
V_33 -> V_94 &= ~ V_108 ;
F_47 ( & V_33 -> V_104 , V_95 ) ;
}
V_85 = F_50 ( & V_7 -> V_100 , struct V_84 ,
V_101 ) ;
V_85 -> V_94 = V_125 ;
return F_35 ( V_85 ) ;
}
void F_55 ( struct V_6 * V_7 )
{
struct V_79 * V_80 = V_7 -> V_80 ;
unsigned long V_95 ;
F_45 ( & V_80 -> V_112 , V_95 ) ;
while ( ! F_43 ( & V_7 -> V_100 ) ) {
struct V_84 * V_85 ;
V_85 = F_50 ( & V_7 -> V_100 ,
struct V_84 , V_101 ) ;
F_51 ( & V_85 -> V_101 ) ;
V_85 -> V_94 = V_98 ;
F_42 ( & V_85 -> V_99 ) ;
}
V_7 -> error = true ;
F_47 ( & V_80 -> V_112 , V_95 ) ;
}
void F_56 ( struct V_6 * V_7 , int V_126 )
{
struct V_86 * V_85 = NULL ;
if ( V_126 && V_7 -> type == V_46 )
F_57 ( V_7 -> V_80 ) ;
if ( ! F_43 ( & V_7 -> V_100 ) ) {
V_85 = F_50 ( & V_7 -> V_100 ,
struct V_86 , V_87 . V_101 ) ;
V_7 -> V_105 -> V_80 ( V_7 , V_85 ) ;
V_7 -> V_106 |= V_107 ;
} else {
if ( V_126 )
V_7 -> V_106 |= V_124 ;
}
}
static int
F_58 ( struct V_127 * V_127 , void * V_128 , struct V_129 * V_130 )
{
struct V_6 * V_7 = F_59 ( V_127 ) ;
F_60 ( V_130 -> V_131 , V_132 , sizeof( V_130 -> V_131 ) ) ;
F_60 ( V_130 -> V_133 , V_7 -> V_7 . V_134 , sizeof( V_130 -> V_133 ) ) ;
F_60 ( V_130 -> V_135 , L_3 , sizeof( V_130 -> V_135 ) ) ;
if ( V_7 -> type == V_46 )
V_130 -> V_136 = V_137 | V_138 ;
else
V_130 -> V_136 = V_139 | V_138 ;
return 0 ;
}
static int
F_61 ( struct V_127 * V_127 , void * V_128 , struct V_50 * V_51 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
struct V_6 * V_7 = F_59 ( V_127 ) ;
if ( V_51 -> type != V_7 -> type )
return - V_56 ;
F_13 ( & V_7 -> V_59 ) ;
* V_51 = V_62 -> V_51 ;
F_18 ( & V_7 -> V_59 ) ;
return 0 ;
}
static int
F_63 ( struct V_127 * V_127 , void * V_128 , struct V_50 * V_51 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_8 V_53 ;
if ( V_51 -> type != V_7 -> type )
return - V_56 ;
F_13 ( & V_7 -> V_59 ) ;
F_7 ( & V_51 -> V_53 . V_11 , & V_53 ) ;
F_3 ( V_7 , & V_53 , & V_51 -> V_53 . V_11 ) ;
V_62 -> V_51 = * V_51 ;
F_18 ( & V_7 -> V_59 ) ;
return 0 ;
}
static int
F_64 ( struct V_127 * V_127 , void * V_128 , struct V_50 * V_51 )
{
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_52 V_53 ;
struct V_25 * V_54 ;
T_1 V_26 ;
int V_55 ;
if ( V_51 -> type != V_7 -> type )
return - V_56 ;
V_54 = F_8 ( V_7 , & V_26 ) ;
if ( V_54 == NULL )
return - V_56 ;
F_7 ( & V_51 -> V_53 . V_11 , & V_53 . V_51 ) ;
V_53 . V_26 = V_26 ;
V_53 . V_57 = V_58 ;
V_55 = F_20 ( V_54 , V_26 , V_60 , NULL , & V_53 ) ;
if ( V_55 )
return V_55 == - V_140 ? - V_141 : V_55 ;
F_3 ( V_7 , & V_53 . V_51 , & V_51 -> V_53 . V_11 ) ;
return 0 ;
}
static int
F_65 ( struct V_127 * V_127 , void * V_128 , struct V_142 * V_143 )
{
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_25 * V_54 ;
int V_55 ;
V_54 = F_8 ( V_7 , NULL ) ;
if ( V_54 == NULL )
return - V_56 ;
F_13 ( & V_7 -> V_59 ) ;
V_55 = F_20 ( V_54 , V_7 , V_143 , V_143 ) ;
F_18 ( & V_7 -> V_59 ) ;
return V_55 == - V_140 ? - V_141 : V_55 ;
}
static int
F_66 ( struct V_127 * V_127 , void * V_128 , struct V_144 * V_145 )
{
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_52 V_51 ;
struct V_25 * V_54 ;
T_1 V_26 ;
int V_55 ;
V_54 = F_8 ( V_7 , & V_26 ) ;
if ( V_54 == NULL )
return - V_56 ;
V_55 = F_20 ( V_54 , V_7 , V_146 , V_145 ) ;
if ( V_55 != - V_140 )
return V_55 ;
V_51 . V_26 = V_26 ;
V_51 . V_57 = V_58 ;
V_55 = F_20 ( V_54 , V_26 , V_60 , NULL , & V_51 ) ;
if ( V_55 < 0 )
return V_55 == - V_140 ? - V_141 : V_55 ;
V_145 -> V_147 . V_148 = 0 ;
V_145 -> V_147 . V_149 = 0 ;
V_145 -> V_147 . V_15 = V_51 . V_51 . V_15 ;
V_145 -> V_147 . V_16 = V_51 . V_51 . V_16 ;
return 0 ;
}
static int
F_67 ( struct V_127 * V_127 , void * V_128 , const struct V_144 * V_145 )
{
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_25 * V_54 ;
int V_55 ;
V_54 = F_8 ( V_7 , NULL ) ;
if ( V_54 == NULL )
return - V_56 ;
F_13 ( & V_7 -> V_59 ) ;
V_55 = F_20 ( V_54 , V_7 , V_150 , V_145 ) ;
F_18 ( & V_7 -> V_59 ) ;
return V_55 == - V_140 ? - V_141 : V_55 ;
}
static int
F_68 ( struct V_127 * V_127 , void * V_128 , struct V_151 * V_152 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
struct V_6 * V_7 = F_59 ( V_127 ) ;
if ( V_7 -> type != V_153 ||
V_7 -> type != V_152 -> type )
return - V_56 ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_152 -> type = V_153 ;
V_152 -> V_154 . V_48 . V_155 = V_156 ;
V_152 -> V_154 . V_48 . V_157 = V_62 -> V_157 ;
return 0 ;
}
static int
F_69 ( struct V_127 * V_127 , void * V_128 , struct V_151 * V_152 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
struct V_6 * V_7 = F_59 ( V_127 ) ;
if ( V_7 -> type != V_153 ||
V_7 -> type != V_152 -> type )
return - V_56 ;
if ( V_152 -> V_154 . V_48 . V_157 . V_158 == 0 )
V_152 -> V_154 . V_48 . V_157 . V_158 = 1 ;
V_62 -> V_157 = V_152 -> V_154 . V_48 . V_157 ;
return 0 ;
}
static int
F_70 ( struct V_127 * V_127 , void * V_128 , struct V_159 * V_160 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
return F_71 ( & V_62 -> V_80 , V_160 ) ;
}
static int
F_72 ( struct V_127 * V_127 , void * V_128 , struct V_161 * V_162 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
return F_73 ( & V_62 -> V_80 , V_162 ) ;
}
static int
F_74 ( struct V_127 * V_127 , void * V_128 , struct V_161 * V_162 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
return F_75 ( & V_62 -> V_80 , V_162 ) ;
}
static int
F_76 ( struct V_127 * V_127 , void * V_128 , struct V_161 * V_162 )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
return F_77 ( & V_62 -> V_80 , V_162 ,
V_127 -> V_163 & V_164 ) ;
}
static int F_78 ( struct V_6 * V_7 ,
struct V_32 * V_33 )
{
struct V_63 * V_64 = V_7 -> V_64 ;
struct V_36 * V_165 [] = {
& V_64 -> V_166 . V_54 . V_29 ,
& V_64 -> V_167 . V_54 . V_29 ,
& V_64 -> V_168 . V_54 . V_29 ,
& V_64 -> V_169 . V_54 . V_29
} ;
struct V_27 * V_170 ;
struct V_36 * V_171 = NULL ;
struct V_36 * V_172 ;
struct V_52 V_53 ;
struct V_173 V_174 ;
struct V_175 V_176 ;
unsigned int V_4 ;
int V_55 = 0 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_165 ) ; V_4 ++ ) {
if ( ! ( V_33 -> V_43 & ( 1 << V_165 [ V_4 ] -> V_44 ) ) )
continue;
V_170 = F_9 ( & V_165 [ V_4 ] -> V_177 [ 0 ] ) ;
if ( V_170 == NULL )
continue;
V_171 = V_170 -> V_29 ;
V_172 = V_165 [ V_4 ] ;
break;
}
if ( ! V_171 ) {
F_79 ( V_64 -> V_77 , L_4 ) ;
return V_55 ;
}
if ( F_10 ( V_171 ) != V_30 )
return 0 ;
V_33 -> V_178 = F_11 ( V_171 ) ;
V_53 . V_26 = V_170 -> V_31 ;
V_53 . V_57 = V_58 ;
V_55 = F_20 ( F_11 ( V_172 ) ,
V_26 , V_60 , NULL , & V_53 ) ;
if ( F_37 ( V_55 < 0 ) ) {
F_79 ( V_64 -> V_77 , L_5 ) ;
return V_55 ;
}
V_33 -> V_179 =
F_1 ( V_53 . V_51 . V_3 ) -> V_15 ;
memset ( & V_174 , 0 , sizeof( V_174 ) ) ;
memset ( & V_176 , 0 , sizeof( V_176 ) ) ;
V_176 . V_44 = V_180 ;
V_174 . V_181 = 1 ;
V_174 . V_182 = & V_176 ;
V_55 = F_80 ( V_33 -> V_178 -> V_183 , & V_174 ) ;
if ( V_55 < 0 ) {
F_79 ( V_64 -> V_77 , L_6 ,
V_33 -> V_178 -> V_134 ) ;
return V_55 ;
}
V_33 -> V_184 = V_176 . V_185 ;
if ( V_33 -> V_43 & ( 1 << V_64 -> V_169 . V_54 . V_29 . V_44 ) ) {
unsigned int V_186 = V_187 ;
F_81 ( & V_64 -> V_169 , & V_186 ) ;
if ( V_33 -> V_184 > V_186 )
return - V_188 ;
}
return 0 ;
}
static int
F_82 ( struct V_127 * V_127 , void * V_128 , enum V_189 type )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
struct V_6 * V_7 = F_59 ( V_127 ) ;
enum V_93 V_94 ;
struct V_32 * V_33 ;
unsigned long V_95 ;
int V_55 ;
if ( type != V_7 -> type )
return - V_56 ;
F_13 ( & V_7 -> V_190 ) ;
if ( V_7 -> V_191 ) {
F_18 ( & V_7 -> V_190 ) ;
return - V_192 ;
}
V_33 = V_7 -> V_7 . V_29 . V_33
? F_41 ( & V_7 -> V_7 . V_29 ) : & V_7 -> V_33 ;
V_33 -> V_43 = 0 ;
if ( V_7 -> V_64 -> V_193 -> V_194 )
V_7 -> V_64 -> V_193 -> V_194 ( V_7 -> V_64 , true ) ;
V_33 -> V_195 = F_83 ( V_7 -> V_64 -> clock [ V_196 ] ) ;
V_33 -> V_197 = V_33 -> V_195 ;
V_55 = F_84 ( & V_7 -> V_7 . V_29 , & V_33 -> V_33 ) ;
if ( V_55 < 0 )
goto V_198;
V_55 = F_21 ( V_7 , V_62 ) ;
if ( V_55 < 0 )
goto V_199;
V_7 -> V_200 = V_55 ;
V_7 -> V_201 = V_62 -> V_51 . V_53 . V_11 . V_13 ;
V_55 = F_12 ( V_7 , V_33 ) ;
if ( V_55 < 0 )
goto V_199;
if ( V_7 -> type == V_46 )
V_94 = V_202 | V_203 ;
else
V_94 = V_204 | V_205 ;
V_55 = F_78 ( V_7 , V_33 ) ;
if ( V_55 < 0 )
goto V_199;
V_33 -> error = false ;
F_45 ( & V_33 -> V_104 , V_95 ) ;
V_33 -> V_94 &= ~ V_108 ;
V_33 -> V_94 |= V_94 ;
F_47 ( & V_33 -> V_104 , V_95 ) ;
if ( V_7 -> type == V_153 )
V_33 -> V_206 = V_62 -> V_157 ;
V_7 -> V_80 = & V_62 -> V_80 ;
F_85 ( & V_7 -> V_100 ) ;
F_86 ( & V_33 -> V_120 , - 1 ) ;
V_55 = F_87 ( & V_62 -> V_80 ) ;
if ( V_55 < 0 )
goto V_199;
if ( V_33 -> V_47 == NULL ) {
V_55 = F_48 ( V_33 ,
V_123 ) ;
if ( V_55 < 0 )
goto V_207;
F_45 ( & V_7 -> V_80 -> V_112 , V_95 ) ;
if ( F_43 ( & V_7 -> V_100 ) )
V_7 -> V_106 |= V_124 ;
F_47 ( & V_7 -> V_80 -> V_112 , V_95 ) ;
}
V_7 -> V_191 = 1 ;
F_18 ( & V_7 -> V_190 ) ;
return 0 ;
V_207:
F_88 ( & V_62 -> V_80 ) ;
V_199:
F_89 ( & V_7 -> V_7 . V_29 ) ;
V_198:
if ( V_7 -> V_64 -> V_193 -> V_194 )
V_7 -> V_64 -> V_193 -> V_194 ( V_7 -> V_64 , false ) ;
F_85 ( & V_7 -> V_100 ) ;
V_7 -> V_80 = NULL ;
F_18 ( & V_7 -> V_190 ) ;
return V_55 ;
}
static int
F_90 ( struct V_127 * V_127 , void * V_128 , enum V_189 type )
{
struct V_61 * V_62 = F_62 ( V_128 ) ;
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_32 * V_33 = F_41 ( & V_7 -> V_7 . V_29 ) ;
enum V_93 V_94 ;
unsigned int V_191 ;
unsigned long V_95 ;
if ( type != V_7 -> type )
return - V_56 ;
F_13 ( & V_7 -> V_190 ) ;
F_13 ( & V_62 -> V_80 . V_104 ) ;
V_191 = V_62 -> V_80 . V_191 ;
F_18 ( & V_62 -> V_80 . V_104 ) ;
if ( ! V_191 )
goto V_208;
if ( V_7 -> type == V_46 )
V_94 = V_202
| V_102 ;
else
V_94 = V_204
| V_103 ;
F_45 ( & V_33 -> V_104 , V_95 ) ;
V_33 -> V_94 &= ~ V_94 ;
F_47 ( & V_33 -> V_104 , V_95 ) ;
F_48 ( V_33 , V_209 ) ;
F_88 ( & V_62 -> V_80 ) ;
V_7 -> V_80 = NULL ;
V_7 -> V_191 = 0 ;
V_7 -> error = false ;
if ( V_7 -> V_64 -> V_193 -> V_194 )
V_7 -> V_64 -> V_193 -> V_194 ( V_7 -> V_64 , false ) ;
F_89 ( & V_7 -> V_7 . V_29 ) ;
V_208:
F_18 ( & V_7 -> V_190 ) ;
return 0 ;
}
static int
F_91 ( struct V_127 * V_127 , void * V_128 , struct V_210 * V_47 )
{
if ( V_47 -> V_31 > 0 )
return - V_56 ;
F_60 ( V_47 -> V_134 , L_7 , sizeof( V_47 -> V_134 ) ) ;
V_47 -> type = V_211 ;
return 0 ;
}
static int
F_92 ( struct V_127 * V_127 , void * V_128 , unsigned int * V_47 )
{
* V_47 = 0 ;
return 0 ;
}
static int
F_93 ( struct V_127 * V_127 , void * V_128 , unsigned int V_47 )
{
return V_47 == 0 ? 0 : - V_56 ;
}
static int F_94 ( struct V_127 * V_127 )
{
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_61 * V_212 ;
int V_55 = 0 ;
V_212 = F_95 ( sizeof( * V_212 ) , V_71 ) ;
if ( V_212 == NULL )
return - V_72 ;
F_96 ( & V_212 -> V_62 , & V_7 -> V_7 ) ;
F_97 ( & V_212 -> V_62 ) ;
if ( F_98 ( V_7 -> V_64 ) == NULL ) {
V_55 = - V_192 ;
goto V_208;
}
V_55 = F_99 ( & V_7 -> V_7 . V_29 , 1 ) ;
if ( V_55 < 0 ) {
F_100 ( V_7 -> V_64 ) ;
goto V_208;
}
F_101 ( & V_212 -> V_80 , V_7 -> type ,
& V_213 , V_7 -> V_64 -> V_77 ,
sizeof( struct V_86 ) ) ;
memset ( & V_212 -> V_51 , 0 , sizeof( V_212 -> V_51 ) ) ;
V_212 -> V_51 . type = V_7 -> type ;
V_212 -> V_157 . V_158 = 1 ;
V_212 -> V_7 = V_7 ;
V_127 -> V_214 = & V_212 -> V_62 ;
V_208:
if ( V_55 < 0 ) {
F_102 ( & V_212 -> V_62 ) ;
F_26 ( V_212 ) ;
}
return V_55 ;
}
static int F_103 ( struct V_127 * V_127 )
{
struct V_6 * V_7 = F_59 ( V_127 ) ;
struct V_215 * V_62 = V_127 -> V_214 ;
struct V_61 * V_212 = F_62 ( V_62 ) ;
F_90 ( V_127 , V_62 , V_7 -> type ) ;
F_13 ( & V_212 -> V_80 . V_104 ) ;
F_104 ( & V_212 -> V_80 ) ;
F_18 ( & V_212 -> V_80 . V_104 ) ;
F_99 ( & V_7 -> V_7 . V_29 , 0 ) ;
F_102 ( V_62 ) ;
F_26 ( V_212 ) ;
V_127 -> V_214 = NULL ;
F_100 ( V_7 -> V_64 ) ;
return 0 ;
}
static unsigned int F_105 ( struct V_127 * V_127 , T_3 * V_99 )
{
struct V_61 * V_62 = F_62 ( V_127 -> V_214 ) ;
struct V_79 * V_80 = & V_62 -> V_80 ;
return F_106 ( V_80 , V_127 , V_99 ) ;
}
static int F_107 ( struct V_127 * V_127 , struct V_216 * V_217 )
{
struct V_61 * V_62 = F_62 ( V_127 -> V_214 ) ;
return F_108 ( & V_62 -> V_80 , V_217 ) ;
}
int F_109 ( struct V_6 * V_7 , const char * V_134 )
{
const char * V_218 ;
int V_55 ;
switch ( V_7 -> type ) {
case V_46 :
V_218 = L_8 ;
V_7 -> V_26 . V_95 = V_219
| V_220 ;
break;
case V_153 :
V_218 = L_9 ;
V_7 -> V_26 . V_95 = V_221
| V_220 ;
V_7 -> V_7 . V_222 = V_223 ;
break;
default:
return - V_56 ;
}
V_55 = F_110 ( & V_7 -> V_7 . V_29 , 1 , & V_7 -> V_26 , 0 ) ;
if ( V_55 < 0 )
return V_55 ;
F_111 ( & V_7 -> V_59 ) ;
F_86 ( & V_7 -> V_224 , 0 ) ;
F_112 ( & V_7 -> V_33 . V_104 ) ;
F_111 ( & V_7 -> V_190 ) ;
if ( V_7 -> V_105 == NULL )
V_7 -> V_105 = & V_225 ;
V_7 -> V_7 . V_226 = & V_227 ;
snprintf ( V_7 -> V_7 . V_134 , sizeof( V_7 -> V_7 . V_134 ) ,
L_10 , V_134 , V_218 ) ;
V_7 -> V_7 . V_228 = V_229 ;
V_7 -> V_7 . V_230 = V_231 ;
V_7 -> V_7 . V_232 = & V_233 ;
V_7 -> V_33 . V_122 = V_209 ;
F_113 ( & V_7 -> V_7 , V_7 ) ;
return 0 ;
}
void F_114 ( struct V_6 * V_7 )
{
F_115 ( & V_7 -> V_7 . V_29 ) ;
F_116 ( & V_7 -> V_190 ) ;
F_116 ( & V_7 -> V_59 ) ;
}
int F_117 ( struct V_6 * V_7 , struct V_234 * V_235 )
{
int V_55 ;
V_7 -> V_7 . V_236 = V_235 ;
V_55 = F_118 ( & V_7 -> V_7 , V_229 , - 1 ) ;
if ( V_55 < 0 )
F_119 ( V_7 -> V_64 -> V_77 ,
L_11 ,
V_237 , V_55 ) ;
return V_55 ;
}
void F_120 ( struct V_6 * V_7 )
{
if ( F_121 ( & V_7 -> V_7 ) )
F_122 ( & V_7 -> V_7 ) ;
}
