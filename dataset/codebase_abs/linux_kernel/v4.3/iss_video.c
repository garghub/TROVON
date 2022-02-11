const struct V_1 *
F_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
static unsigned int F_3 ( const struct V_5 * V_6 ,
const struct V_7 * V_8 ,
struct V_9 * V_10 )
{
unsigned int V_11 = V_10 -> V_12 ;
unsigned int V_13 ;
unsigned int V_3 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_14 = V_8 -> V_14 ;
V_10 -> V_15 = V_8 -> V_15 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) - 1 ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_8 -> V_2 )
break;
}
V_13 = V_10 -> V_14 * F_4 ( V_4 [ V_3 ] . V_16 , 8 ) / 8 ;
if ( V_6 -> V_17 )
V_11 = F_5 ( V_11 , V_13 , V_6 -> V_17 ) ;
else
V_11 = V_13 ;
if ( ! V_6 -> V_18 || V_11 != V_13 )
V_11 = F_4 ( V_11 , V_6 -> V_19 ) ;
V_10 -> V_20 = V_4 [ V_3 ] . V_20 ;
V_10 -> V_12 = V_11 ;
V_10 -> V_21 = V_10 -> V_12 * V_10 -> V_15 ;
V_10 -> V_22 = V_8 -> V_22 ;
V_10 -> V_23 = V_8 -> V_23 ;
if ( V_10 -> V_20 == V_24 )
V_10 -> V_21 += ( V_10 -> V_12 * V_10 -> V_15 ) / 2 ;
return V_11 - V_13 ;
}
static void F_6 ( const struct V_9 * V_10 ,
struct V_7 * V_8 )
{
unsigned int V_3 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_8 -> V_14 = V_10 -> V_14 ;
V_8 -> V_15 = V_10 -> V_15 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) - 1 ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_20 == V_10 -> V_20 )
break;
}
V_8 -> V_2 = V_4 [ V_3 ] . V_2 ;
V_8 -> V_22 = V_10 -> V_22 ;
V_8 -> V_23 = V_10 -> V_23 ;
}
static struct V_25 *
F_7 ( struct V_5 * V_6 , T_1 * V_26 )
{
struct V_27 * V_28 ;
V_28 = F_8 ( & V_6 -> V_26 ) ;
if ( V_28 == NULL ||
F_9 ( V_28 -> V_29 ) != V_30 )
return NULL ;
if ( V_26 )
* V_26 = V_28 -> V_31 ;
return F_10 ( V_28 -> V_29 ) ;
}
static struct V_5 *
F_11 ( struct V_5 * V_6 )
{
struct V_32 V_33 ;
struct V_34 * V_29 = & V_6 -> V_6 . V_29 ;
struct V_35 * V_36 = V_29 -> V_37 ;
struct V_5 * V_38 = NULL ;
F_12 ( & V_36 -> V_39 ) ;
F_13 ( & V_33 , V_29 ) ;
while ( ( V_29 = F_14 ( & V_33 ) ) ) {
if ( V_29 == & V_6 -> V_6 . V_29 )
continue;
if ( F_9 ( V_29 ) != V_40 )
continue;
V_38 = F_15 ( F_16 ( V_29 ) ) ;
if ( V_38 -> type != V_6 -> type )
break;
V_38 = NULL ;
}
F_17 ( & V_36 -> V_39 ) ;
return V_38 ;
}
static int
F_18 ( struct V_5 * V_6 ,
struct V_7 * V_41 )
{
struct V_42 V_43 ;
struct V_25 * V_44 ;
T_1 V_26 ;
int V_45 ;
V_44 = F_7 ( V_6 , & V_26 ) ;
if ( V_44 == NULL )
return - V_46 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_26 = V_26 ;
V_43 . V_47 = V_48 ;
F_12 ( & V_6 -> V_49 ) ;
V_45 = F_19 ( V_44 , V_26 , V_50 , NULL , & V_43 ) ;
F_17 ( & V_6 -> V_49 ) ;
if ( V_45 )
return V_45 ;
* V_41 = V_43 . V_41 ;
return 0 ;
}
static int
F_20 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
struct V_7 V_41 ;
struct V_9 V_53 ;
int V_45 ;
V_45 = F_18 ( V_6 , & V_41 ) ;
if ( V_45 < 0 )
return V_45 ;
V_53 . V_12 = 0 ;
V_45 = F_3 ( V_6 , & V_41 , & V_53 ) ;
if ( V_52 -> V_41 . V_43 . V_10 . V_20 != V_53 . V_20 ||
V_52 -> V_41 . V_43 . V_10 . V_15 != V_53 . V_15 ||
V_52 -> V_41 . V_43 . V_10 . V_14 != V_53 . V_14 ||
V_52 -> V_41 . V_43 . V_10 . V_12 != V_53 . V_12 ||
V_52 -> V_41 . V_43 . V_10 . V_21 != V_53 . V_21 )
return - V_46 ;
return V_45 ;
}
static int F_21 ( struct V_54 * V_55 ,
const struct V_56 * V_43 ,
unsigned int * V_57 , unsigned int * V_58 ,
unsigned int V_59 [] , void * V_60 [] )
{
struct V_51 * V_52 = F_22 ( V_55 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
* V_58 = 1 ;
V_59 [ 0 ] = V_52 -> V_41 . V_43 . V_10 . V_21 ;
if ( V_59 [ 0 ] == 0 )
return - V_46 ;
V_60 [ 0 ] = V_6 -> V_61 ;
* V_57 = F_23 ( * V_57 , V_6 -> V_62 / F_24 ( V_59 [ 0 ] ) ) ;
return 0 ;
}
static void F_25 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = F_26 ( V_64 , struct V_65 , V_64 ) ;
if ( V_66 -> V_67 )
V_66 -> V_67 = 0 ;
}
static int F_27 ( struct V_63 * V_64 )
{
struct V_51 * V_52 = F_22 ( V_64 -> V_54 ) ;
struct V_65 * V_66 = F_26 ( V_64 , struct V_65 , V_64 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
unsigned long V_68 = V_52 -> V_41 . V_43 . V_10 . V_21 ;
T_2 V_69 ;
if ( F_28 ( V_64 , 0 ) < V_68 )
return - V_70 ;
V_69 = F_29 ( V_64 , 0 ) ;
if ( ! F_30 ( V_69 , 32 ) ) {
F_31 ( V_6 -> V_71 -> V_72 ,
L_1 ) ;
return - V_46 ;
}
F_32 ( V_64 , 0 , V_68 ) ;
V_66 -> V_67 = V_69 ;
return 0 ;
}
static void F_33 ( struct V_63 * V_64 )
{
struct V_51 * V_52 = F_22 ( V_64 -> V_54 ) ;
struct V_5 * V_6 = V_52 -> V_6 ;
struct V_65 * V_66 = F_26 ( V_64 , struct V_65 , V_64 ) ;
struct V_73 * V_74 = F_34 ( & V_6 -> V_6 . V_29 ) ;
unsigned long V_75 ;
bool V_76 ;
F_35 ( & V_6 -> V_77 , V_75 ) ;
if ( F_36 ( V_6 -> error ) ) {
F_37 ( V_64 , V_78 ) ;
F_38 ( & V_6 -> V_77 , V_75 ) ;
return;
}
V_76 = F_39 ( & V_6 -> V_79 ) ;
F_40 ( & V_66 -> V_80 , & V_6 -> V_79 ) ;
F_38 ( & V_6 -> V_77 , V_75 ) ;
if ( V_76 ) {
enum V_81 V_82 ;
unsigned int V_83 ;
if ( V_6 -> type == V_84 )
V_82 = V_85 ;
else
V_82 = V_86 ;
F_35 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 |= V_82 ;
V_6 -> V_88 -> V_89 ( V_6 , V_66 ) ;
V_6 -> V_90 |= V_91 ;
V_83 = F_41 ( V_74 ) ;
if ( V_83 )
V_74 -> V_82 |= V_92 ;
F_38 ( & V_74 -> V_87 , V_75 ) ;
if ( V_83 )
F_42 ( V_74 ,
V_93 ) ;
}
}
struct V_65 * F_43 ( struct V_5 * V_6 )
{
struct V_73 * V_74 = F_34 ( & V_6 -> V_6 . V_29 ) ;
enum V_81 V_82 ;
struct V_65 * V_94 ;
unsigned long V_75 ;
struct V_95 V_96 ;
F_35 ( & V_6 -> V_77 , V_75 ) ;
if ( F_44 ( F_39 ( & V_6 -> V_79 ) ) ) {
F_38 ( & V_6 -> V_77 , V_75 ) ;
return NULL ;
}
V_94 = F_45 ( & V_6 -> V_79 , struct V_65 ,
V_80 ) ;
F_46 ( & V_94 -> V_80 ) ;
F_38 ( & V_6 -> V_77 , V_75 ) ;
F_47 ( & V_96 ) ;
V_94 -> V_64 . V_97 . V_98 . V_99 = V_96 . V_99 ;
V_94 -> V_64 . V_97 . V_98 . V_100 = V_96 . V_101 / V_102 ;
if ( V_6 == V_74 -> V_103 && ! V_74 -> V_104 )
V_94 -> V_64 . V_97 . V_105 =
F_48 ( & V_74 -> V_106 ) ;
else
V_94 -> V_64 . V_97 . V_105 = F_49 ( & V_74 -> V_106 ) ;
F_37 ( & V_94 -> V_64 , V_74 -> error ?
V_78 : V_107 ) ;
V_74 -> error = false ;
F_35 ( & V_6 -> V_77 , V_75 ) ;
if ( F_39 ( & V_6 -> V_79 ) ) {
F_38 ( & V_6 -> V_77 , V_75 ) ;
if ( V_6 -> type == V_84 )
V_82 = V_85
| V_92 ;
else
V_82 = V_86
| V_92 ;
F_35 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 &= ~ V_82 ;
if ( V_6 -> V_74 . V_108 == V_109 )
V_6 -> V_90 |= V_110 ;
F_38 ( & V_74 -> V_87 , V_75 ) ;
return NULL ;
}
if ( V_6 -> type == V_84 && V_74 -> V_111 != NULL ) {
F_50 ( & V_74 -> V_87 ) ;
V_74 -> V_82 &= ~ V_92 ;
F_51 ( & V_74 -> V_87 ) ;
}
V_94 = F_45 ( & V_6 -> V_79 , struct V_65 ,
V_80 ) ;
F_38 ( & V_6 -> V_77 , V_75 ) ;
V_94 -> V_64 . V_82 = V_112 ;
return V_94 ;
}
void F_52 ( struct V_5 * V_6 )
{
unsigned long V_75 ;
F_35 ( & V_6 -> V_77 , V_75 ) ;
while ( ! F_39 ( & V_6 -> V_79 ) ) {
struct V_65 * V_94 ;
V_94 = F_45 ( & V_6 -> V_79 , struct V_65 ,
V_80 ) ;
F_46 ( & V_94 -> V_80 ) ;
F_37 ( & V_94 -> V_64 , V_78 ) ;
}
F_53 ( V_6 -> V_89 ) ;
V_6 -> error = true ;
F_38 ( & V_6 -> V_77 , V_75 ) ;
}
static int
F_54 ( struct V_113 * V_113 , void * V_114 , struct V_115 * V_116 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
F_56 ( V_116 -> V_117 , V_118 , sizeof( V_116 -> V_117 ) ) ;
F_56 ( V_116 -> V_119 , V_6 -> V_6 . V_120 , sizeof( V_116 -> V_119 ) ) ;
F_56 ( V_116 -> V_121 , L_2 , sizeof( V_116 -> V_121 ) ) ;
if ( V_6 -> type == V_84 )
V_116 -> V_122 = V_123 | V_124 ;
else
V_116 -> V_122 = V_125 | V_124 ;
V_116 -> V_126 = V_127 | V_124
| V_123 | V_125 ;
return 0 ;
}
static int
F_57 ( struct V_113 * V_113 , void * V_114 , struct V_128 * V_129 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_7 V_41 ;
unsigned int V_31 = V_129 -> V_31 ;
unsigned int V_3 ;
int V_45 ;
if ( V_129 -> type != V_6 -> type )
return - V_46 ;
V_45 = F_18 ( V_6 , & V_41 ) ;
if ( V_45 < 0 )
return V_45 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; ++ V_3 ) {
const struct V_1 * V_130 = & V_4 [ V_3 ] ;
if ( V_41 . V_2 != V_130 -> V_2 )
continue;
if ( V_31 == 0 ) {
V_129 -> V_20 = V_130 -> V_20 ;
F_56 ( V_129 -> V_131 , V_130 -> V_131 ,
sizeof( V_129 -> V_131 ) ) ;
return 0 ;
}
V_31 -- ;
}
return - V_46 ;
}
static int
F_58 ( struct V_113 * V_113 , void * V_114 , struct V_56 * V_41 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_49 ) ;
* V_41 = V_52 -> V_41 ;
F_17 ( & V_6 -> V_49 ) ;
return 0 ;
}
static int
F_60 ( struct V_113 * V_113 , void * V_114 , struct V_56 * V_41 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_7 V_43 ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_49 ) ;
F_6 ( & V_41 -> V_43 . V_10 , & V_43 ) ;
F_3 ( V_6 , & V_43 , & V_41 -> V_43 . V_10 ) ;
V_52 -> V_41 = * V_41 ;
F_17 ( & V_6 -> V_49 ) ;
return 0 ;
}
static int
F_61 ( struct V_113 * V_113 , void * V_114 , struct V_56 * V_41 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_42 V_43 ;
struct V_25 * V_44 ;
T_1 V_26 ;
int V_45 ;
if ( V_41 -> type != V_6 -> type )
return - V_46 ;
V_44 = F_7 ( V_6 , & V_26 ) ;
if ( V_44 == NULL )
return - V_46 ;
F_6 ( & V_41 -> V_43 . V_10 , & V_43 . V_41 ) ;
V_43 . V_26 = V_26 ;
V_43 . V_47 = V_48 ;
V_45 = F_19 ( V_44 , V_26 , V_50 , NULL , & V_43 ) ;
if ( V_45 )
return V_45 ;
F_3 ( V_6 , & V_43 . V_41 , & V_41 -> V_43 . V_10 ) ;
return 0 ;
}
static int
F_62 ( struct V_113 * V_113 , void * V_114 , struct V_132 * V_133 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
if ( V_6 -> type != V_134 ||
V_6 -> type != V_133 -> type )
return - V_46 ;
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> type = V_134 ;
V_133 -> V_135 . V_103 . V_136 = V_137 ;
V_133 -> V_135 . V_103 . V_138 = V_52 -> V_138 ;
return 0 ;
}
static int
F_63 ( struct V_113 * V_113 , void * V_114 , struct V_132 * V_133 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
if ( V_6 -> type != V_134 ||
V_6 -> type != V_133 -> type )
return - V_46 ;
if ( V_133 -> V_135 . V_103 . V_138 . V_139 == 0 )
V_133 -> V_135 . V_103 . V_138 . V_139 = 1 ;
V_52 -> V_138 = V_133 -> V_135 . V_103 . V_138 ;
return 0 ;
}
static int
F_64 ( struct V_113 * V_113 , void * V_114 , struct V_140 * V_141 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_65 ( & V_52 -> V_89 , V_141 ) ;
}
static int
F_66 ( struct V_113 * V_113 , void * V_114 , struct V_142 * V_143 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_67 ( & V_52 -> V_89 , V_143 ) ;
}
static int
F_68 ( struct V_113 * V_113 , void * V_114 , struct V_142 * V_143 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_69 ( & V_52 -> V_89 , V_143 ) ;
}
static int
F_70 ( struct V_113 * V_113 , void * V_114 , struct V_144 * V_145 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_71 ( & V_52 -> V_89 , V_145 ) ;
}
static int
F_72 ( struct V_113 * V_113 , void * V_114 , struct V_142 * V_143 )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
return F_73 ( & V_52 -> V_89 , V_143 , V_113 -> V_146 & V_147 ) ;
}
static int
F_74 ( struct V_113 * V_113 , void * V_114 , enum V_148 type )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_32 V_33 ;
struct V_34 * V_29 ;
enum V_81 V_82 ;
struct V_73 * V_74 ;
struct V_5 * V_38 ;
unsigned long V_75 ;
int V_45 ;
if ( type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_149 ) ;
V_74 = V_6 -> V_6 . V_29 . V_74
? F_34 ( & V_6 -> V_6 . V_29 ) : & V_6 -> V_74 ;
V_74 -> V_150 = NULL ;
V_74 -> V_151 = 0 ;
V_74 -> V_152 = 0 ;
V_74 -> V_153 = 0 ;
if ( V_6 -> V_71 -> V_154 -> V_155 )
V_6 -> V_71 -> V_154 -> V_155 ( V_6 -> V_71 , true ) ;
V_45 = F_75 ( & V_6 -> V_6 . V_29 , & V_74 -> V_74 ) ;
if ( V_45 < 0 )
goto V_156;
V_29 = & V_6 -> V_6 . V_29 ;
F_13 ( & V_33 , V_29 ) ;
while ( ( V_29 = F_14 ( & V_33 ) ) )
V_74 -> V_153 |= 1 << V_29 -> V_157 ;
V_45 = F_20 ( V_6 , V_52 ) ;
if ( V_45 < 0 )
goto V_158;
V_6 -> V_159 = V_45 ;
V_6 -> V_160 = V_52 -> V_41 . V_43 . V_10 . V_12 ;
V_38 = F_11 ( V_6 ) ;
if ( V_6 -> type == V_84 ) {
V_82 = V_161 | V_162 ;
V_74 -> V_111 = V_38 ;
V_74 -> V_103 = V_6 ;
} else {
if ( V_38 == NULL ) {
V_45 = - V_163 ;
goto V_158;
}
V_82 = V_164 | V_165 ;
V_74 -> V_111 = V_6 ;
V_74 -> V_103 = V_38 ;
}
F_35 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 &= ~ V_92 ;
V_74 -> V_82 |= V_82 ;
F_38 ( & V_74 -> V_87 , V_75 ) ;
if ( V_6 -> type == V_134 )
V_74 -> V_166 = V_52 -> V_138 ;
V_6 -> V_89 = & V_52 -> V_89 ;
F_76 ( & V_6 -> V_79 ) ;
V_6 -> error = false ;
F_77 ( & V_74 -> V_106 , - 1 ) ;
V_45 = F_78 ( & V_52 -> V_89 , type ) ;
if ( V_45 < 0 )
goto V_158;
if ( V_74 -> V_111 == NULL ) {
unsigned long V_75 ;
V_45 = F_42 ( V_74 ,
V_109 ) ;
if ( V_45 < 0 )
goto V_167;
F_35 ( & V_6 -> V_77 , V_75 ) ;
if ( F_39 ( & V_6 -> V_79 ) )
V_6 -> V_90 |= V_110 ;
F_38 ( & V_6 -> V_77 , V_75 ) ;
}
F_17 ( & V_6 -> V_149 ) ;
return 0 ;
V_167:
F_79 ( & V_52 -> V_89 , type ) ;
V_158:
F_80 ( & V_6 -> V_6 . V_29 ) ;
V_156:
if ( V_6 -> V_71 -> V_154 -> V_155 )
V_6 -> V_71 -> V_154 -> V_155 ( V_6 -> V_71 , false ) ;
V_6 -> V_89 = NULL ;
F_17 ( & V_6 -> V_149 ) ;
return V_45 ;
}
static int
F_81 ( struct V_113 * V_113 , void * V_114 , enum V_148 type )
{
struct V_51 * V_52 = F_59 ( V_114 ) ;
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_73 * V_74 = F_34 ( & V_6 -> V_6 . V_29 ) ;
enum V_81 V_82 ;
unsigned long V_75 ;
if ( type != V_6 -> type )
return - V_46 ;
F_12 ( & V_6 -> V_149 ) ;
if ( ! F_82 ( & V_52 -> V_89 ) )
goto V_168;
if ( V_6 -> type == V_84 )
V_82 = V_161
| V_85 ;
else
V_82 = V_164
| V_86 ;
F_35 ( & V_74 -> V_87 , V_75 ) ;
V_74 -> V_82 &= ~ V_82 ;
F_38 ( & V_74 -> V_87 , V_75 ) ;
F_42 ( V_74 , V_169 ) ;
F_79 ( & V_52 -> V_89 , type ) ;
V_6 -> V_89 = NULL ;
if ( V_6 -> V_71 -> V_154 -> V_155 )
V_6 -> V_71 -> V_154 -> V_155 ( V_6 -> V_71 , false ) ;
F_80 ( & V_6 -> V_6 . V_29 ) ;
V_168:
F_17 ( & V_6 -> V_149 ) ;
return 0 ;
}
static int
F_83 ( struct V_113 * V_113 , void * V_114 , struct V_170 * V_111 )
{
if ( V_111 -> V_31 > 0 )
return - V_46 ;
F_56 ( V_111 -> V_120 , L_3 , sizeof( V_111 -> V_120 ) ) ;
V_111 -> type = V_171 ;
return 0 ;
}
static int
F_84 ( struct V_113 * V_113 , void * V_114 , unsigned int * V_111 )
{
* V_111 = 0 ;
return 0 ;
}
static int
F_85 ( struct V_113 * V_113 , void * V_114 , unsigned int V_111 )
{
return V_111 == 0 ? 0 : - V_46 ;
}
static int F_86 ( struct V_113 * V_113 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_51 * V_172 ;
struct V_54 * V_173 ;
int V_45 = 0 ;
V_172 = F_87 ( sizeof( * V_172 ) , V_174 ) ;
if ( V_172 == NULL )
return - V_175 ;
F_88 ( & V_172 -> V_52 , & V_6 -> V_6 ) ;
F_89 ( & V_172 -> V_52 ) ;
if ( F_90 ( V_6 -> V_71 ) == NULL ) {
V_45 = - V_176 ;
goto V_168;
}
V_45 = F_91 ( & V_6 -> V_6 . V_29 , 1 ) ;
if ( V_45 < 0 ) {
F_92 ( V_6 -> V_71 ) ;
goto V_168;
}
V_6 -> V_61 = F_93 ( V_6 -> V_71 -> V_72 ) ;
if ( F_94 ( V_6 -> V_61 ) ) {
V_45 = F_95 ( V_6 -> V_61 ) ;
F_92 ( V_6 -> V_71 ) ;
goto V_168;
}
V_173 = & V_172 -> V_89 ;
V_173 -> type = V_6 -> type ;
V_173 -> V_177 = V_178 | V_179 ;
V_173 -> V_180 = V_172 ;
V_173 -> V_88 = & V_181 ;
V_173 -> V_182 = & V_183 ;
V_173 -> V_184 = sizeof( struct V_65 ) ;
V_173 -> V_185 = V_186 ;
V_45 = F_96 ( V_173 ) ;
if ( V_45 ) {
F_92 ( V_6 -> V_71 ) ;
goto V_168;
}
memset ( & V_172 -> V_41 , 0 , sizeof( V_172 -> V_41 ) ) ;
V_172 -> V_41 . type = V_6 -> type ;
V_172 -> V_138 . V_139 = 1 ;
V_172 -> V_6 = V_6 ;
V_113 -> V_187 = & V_172 -> V_52 ;
V_168:
if ( V_45 < 0 ) {
F_97 ( & V_172 -> V_52 ) ;
F_98 ( V_172 ) ;
}
return V_45 ;
}
static int F_99 ( struct V_113 * V_113 )
{
struct V_5 * V_6 = F_55 ( V_113 ) ;
struct V_188 * V_52 = V_113 -> V_187 ;
struct V_51 * V_172 = F_59 ( V_52 ) ;
F_81 ( V_113 , V_52 , V_6 -> type ) ;
F_91 ( & V_6 -> V_6 . V_29 , 0 ) ;
F_100 ( & V_172 -> V_89 ) ;
F_97 ( V_52 ) ;
F_98 ( V_172 ) ;
V_113 -> V_187 = NULL ;
F_92 ( V_6 -> V_71 ) ;
return 0 ;
}
static unsigned int F_101 ( struct V_113 * V_113 , T_3 * V_189 )
{
struct V_51 * V_52 = F_59 ( V_113 -> V_187 ) ;
return F_102 ( & V_52 -> V_89 , V_113 , V_189 ) ;
}
static int F_103 ( struct V_113 * V_113 , struct V_190 * V_191 )
{
struct V_51 * V_52 = F_59 ( V_113 -> V_187 ) ;
return F_104 ( & V_52 -> V_89 , V_191 ) ;
}
int F_105 ( struct V_5 * V_6 , const char * V_120 )
{
const char * V_192 ;
int V_45 ;
switch ( V_6 -> type ) {
case V_84 :
V_192 = L_4 ;
V_6 -> V_26 . V_75 = V_193 ;
break;
case V_134 :
V_192 = L_5 ;
V_6 -> V_26 . V_75 = V_194 ;
break;
default:
return - V_46 ;
}
V_45 = F_106 ( & V_6 -> V_6 . V_29 , 1 , & V_6 -> V_26 , 0 ) ;
if ( V_45 < 0 )
return V_45 ;
F_107 ( & V_6 -> V_77 ) ;
F_108 ( & V_6 -> V_49 ) ;
F_77 ( & V_6 -> V_195 , 0 ) ;
F_107 ( & V_6 -> V_74 . V_87 ) ;
F_108 ( & V_6 -> V_149 ) ;
if ( V_6 -> V_88 == NULL )
V_6 -> V_88 = & V_196 ;
V_6 -> V_6 . V_197 = & V_198 ;
snprintf ( V_6 -> V_6 . V_120 , sizeof( V_6 -> V_6 . V_120 ) ,
L_6 , V_120 , V_192 ) ;
V_6 -> V_6 . V_199 = V_200 ;
V_6 -> V_6 . V_201 = V_202 ;
V_6 -> V_6 . V_203 = & V_204 ;
V_6 -> V_74 . V_108 = V_169 ;
F_109 ( & V_6 -> V_6 , V_6 ) ;
return 0 ;
}
void F_110 ( struct V_5 * V_6 )
{
F_111 ( & V_6 -> V_6 . V_29 ) ;
F_112 ( & V_6 -> V_149 ) ;
F_112 ( & V_6 -> V_49 ) ;
}
int F_113 ( struct V_5 * V_6 , struct V_205 * V_206 )
{
int V_45 ;
V_6 -> V_6 . V_207 = V_206 ;
V_45 = F_114 ( & V_6 -> V_6 , V_200 , - 1 ) ;
if ( V_45 < 0 )
F_115 ( V_6 -> V_71 -> V_72 ,
L_7 , V_45 ) ;
return V_45 ;
}
void F_116 ( struct V_5 * V_6 )
{
F_117 ( & V_6 -> V_6 ) ;
}
