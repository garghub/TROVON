static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_8 & V_9 )
F_2 ( V_4 -> V_4 , V_7 -> V_10 , V_7 -> V_11 , V_12 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( V_2 -> V_8 & V_9 )
F_4 ( V_4 -> V_4 , V_7 -> V_10 , V_7 -> V_11 , V_12 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
struct V_13 * * V_14 = F_6 ( & V_2 -> V_5 ) ;
if ( F_7 ( V_14 ) ) {
F_8 ( V_4 -> V_4 , L_1 , F_9 ( V_14 ) ) ;
return F_9 ( V_14 ) ;
}
V_2 -> V_15 = V_14 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 ) {
F_3 ( V_2 ) ;
F_11 ( V_2 -> V_7 ) ;
F_12 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
if ( V_2 -> V_15 ) {
F_13 ( & V_2 -> V_5 , V_2 -> V_15 ,
true , false ) ;
V_2 -> V_15 = NULL ;
}
}
struct V_13 * * F_14 ( struct V_1 * V_2 )
{
int V_16 ;
F_15 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_15 ) {
V_16 = V_2 -> V_18 -> V_19 ( V_2 ) ;
if ( V_16 < 0 )
return F_16 ( V_16 ) ;
}
if ( ! V_2 -> V_7 ) {
struct V_3 * V_4 = V_2 -> V_5 . V_4 ;
int V_20 = V_2 -> V_5 . V_21 >> V_22 ;
struct V_6 * V_7 ;
V_7 = F_17 ( V_2 -> V_15 , V_20 ) ;
if ( F_7 ( V_7 ) ) {
F_8 ( V_4 -> V_4 , L_2 ,
F_9 ( V_7 ) ) ;
return F_18 ( V_7 ) ;
}
V_2 -> V_7 = V_7 ;
F_1 ( V_2 ) ;
}
return V_2 -> V_15 ;
}
void F_19 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_17 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_1 V_25 ;
V_24 -> V_26 &= ~ V_27 ;
V_24 -> V_26 |= V_28 ;
V_25 = F_21 ( V_24 -> V_26 ) ;
if ( V_2 -> V_8 & V_29 ) {
V_24 -> V_25 = F_22 ( V_25 ) ;
} else if ( V_2 -> V_8 & V_30 ) {
V_24 -> V_25 = F_23 ( V_25 ) ;
} else {
F_24 ( V_24 -> V_31 ) ;
F_25 ( V_2 -> V_5 . V_32 ) ;
V_24 -> V_33 = 0 ;
V_24 -> V_31 = V_2 -> V_5 . V_32 ;
V_24 -> V_25 = V_25 ;
}
return 0 ;
}
int F_26 ( struct V_34 * V_32 , struct V_23 * V_24 )
{
struct V_1 * V_35 ;
int V_16 ;
V_16 = F_27 ( V_32 , V_24 ) ;
if ( V_16 ) {
F_28 ( L_3 , V_16 ) ;
return V_16 ;
}
V_35 = F_29 ( V_24 -> V_36 ) ;
return V_35 -> V_18 -> V_37 ( V_35 , V_24 ) ;
}
int F_30 ( struct V_38 * V_39 )
{
struct V_23 * V_24 = V_39 -> V_24 ;
struct V_40 * V_35 = V_24 -> V_36 ;
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_13 * * V_15 , * V_13 ;
T_2 V_41 ;
int V_16 ;
V_16 = F_31 ( & V_2 -> V_17 ) ;
if ( V_16 )
goto V_42;
V_15 = F_14 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_15 ) ) {
V_16 = F_9 ( V_15 ) ;
goto V_42;
}
V_41 = ( V_39 -> V_43 - V_24 -> V_44 ) >> V_22 ;
V_13 = V_15 [ V_41 ] ;
F_33 ( L_4 , ( void * ) V_39 -> V_43 ,
F_34 ( V_13 ) , F_34 ( V_13 ) << V_22 ) ;
V_16 = F_35 ( V_24 , V_39 -> V_43 , V_13 ) ;
V_42:
switch ( V_16 ) {
case - V_45 :
case 0 :
case - V_46 :
case - V_47 :
case - V_48 :
return V_49 ;
case - V_50 :
return V_51 ;
default:
return V_52 ;
}
}
int F_36 ( struct V_40 * V_35 , T_3 * V_53 )
{
int V_16 ;
V_16 = F_37 ( V_35 ) ;
if ( V_16 )
F_8 ( V_35 -> V_4 -> V_4 , L_5 ) ;
else
* V_53 = F_38 ( & V_35 -> V_54 ) ;
return V_16 ;
}
static struct V_55 *
F_39 ( struct V_1 * V_35 ,
struct V_56 * V_57 )
{
struct V_55 * V_58 ;
F_40 (mapping, &obj->vram_list, obj_node) {
if ( V_58 -> V_57 == V_57 )
return V_58 ;
}
return NULL ;
}
void F_41 ( struct V_55 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
F_42 ( & V_2 -> V_5 ) ;
F_43 ( & V_2 -> V_17 ) ;
F_44 ( V_58 -> V_60 == 0 ) ;
V_58 -> V_60 += 1 ;
F_32 ( & V_2 -> V_17 ) ;
}
void F_45 ( struct V_55 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
F_43 ( & V_2 -> V_17 ) ;
F_44 ( V_58 -> V_60 == 0 ) ;
V_58 -> V_60 -= 1 ;
F_32 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_5 ) ;
}
struct V_55 * F_47 (
struct V_40 * V_35 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_55 * V_58 ;
struct V_13 * * V_15 ;
int V_16 = 0 ;
F_43 ( & V_2 -> V_17 ) ;
V_58 = F_39 ( V_2 , V_62 -> V_57 ) ;
if ( V_58 ) {
if ( V_58 -> V_60 == 0 ) {
F_43 ( & V_62 -> V_57 -> V_17 ) ;
if ( V_58 -> V_57 == V_62 -> V_57 )
V_58 -> V_60 += 1 ;
else
V_58 = NULL ;
F_32 ( & V_62 -> V_57 -> V_17 ) ;
if ( V_58 )
goto V_42;
} else {
V_58 -> V_60 += 1 ;
goto V_42;
}
}
V_15 = F_14 ( V_2 ) ;
if ( F_7 ( V_15 ) ) {
V_16 = F_9 ( V_15 ) ;
goto V_42;
}
V_58 = F_39 ( V_2 , NULL ) ;
if ( ! V_58 ) {
V_58 = F_48 ( sizeof( * V_58 ) , V_63 ) ;
if ( ! V_58 ) {
V_16 = - V_50 ;
goto V_42;
}
F_49 ( & V_58 -> V_64 ) ;
V_58 -> V_59 = V_2 ;
} else {
F_50 ( & V_58 -> V_65 ) ;
}
V_58 -> V_57 = V_62 -> V_57 ;
V_58 -> V_60 = 1 ;
V_16 = F_51 ( V_62 -> V_57 , V_2 , V_62 -> V_66 ,
V_58 ) ;
if ( V_16 < 0 )
F_12 ( V_58 ) ;
else
F_52 ( & V_58 -> V_65 , & V_2 -> V_67 ) ;
V_42:
F_32 ( & V_2 -> V_17 ) ;
if ( V_16 )
return F_16 ( V_16 ) ;
F_42 ( V_35 ) ;
return V_58 ;
}
void * F_53 ( struct V_40 * V_35 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
if ( V_2 -> V_68 )
return V_2 -> V_68 ;
F_43 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_68 )
V_2 -> V_68 = V_2 -> V_18 -> V_69 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
return V_2 -> V_68 ;
}
static void * F_54 ( struct V_1 * V_35 )
{
struct V_13 * * V_15 ;
F_15 ( & V_35 -> V_17 ) ;
V_15 = F_14 ( V_35 ) ;
if ( F_7 ( V_15 ) )
return NULL ;
return V_69 ( V_15 , V_35 -> V_5 . V_21 >> V_22 ,
V_70 , F_22 ( V_71 ) ) ;
}
static inline enum V_72 F_55 ( T_4 V_73 )
{
if ( V_73 & V_74 )
return V_75 ;
else if ( V_73 & V_76 )
return V_77 ;
else
return V_12 ;
}
int F_56 ( struct V_40 * V_35 , T_4 V_73 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_3 * V_4 = V_35 -> V_4 ;
bool V_80 = ! ! ( V_73 & V_76 ) ;
unsigned long V_81 =
V_73 & V_82 ? 0 : F_57 ( V_79 ) ;
long V_83 ;
V_83 = F_58 ( V_2 -> V_84 ,
V_80 , true , V_81 ) ;
if ( V_83 < 0 )
return V_83 ;
else if ( V_83 == 0 )
return V_81 == 0 ? - V_48 : - V_85 ;
if ( V_2 -> V_8 & V_86 ) {
if ( ! V_2 -> V_7 ) {
void * V_16 ;
F_43 ( & V_2 -> V_17 ) ;
V_16 = F_14 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_16 ) )
return F_9 ( V_16 ) ;
}
F_59 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_55 ( V_73 ) ) ;
V_2 -> V_87 = V_73 ;
}
return 0 ;
}
int F_60 ( struct V_40 * V_35 )
{
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 = F_29 ( V_35 ) ;
if ( V_2 -> V_8 & V_86 ) {
F_44 ( V_2 -> V_87 == 0 ) ;
F_61 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_55 ( V_2 -> V_87 ) ) ;
V_2 -> V_87 = 0 ;
}
return 0 ;
}
int F_62 ( struct V_61 * V_62 , struct V_40 * V_35 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
return F_63 ( V_62 , V_2 , V_79 ) ;
}
static void F_64 ( struct V_88 * V_89 ,
const char * type , struct V_90 * V_91 )
{
if ( ! F_65 ( V_92 , & V_89 -> V_8 ) )
F_66 ( V_91 , L_6 ,
type ,
V_89 -> V_18 -> V_93 ( V_89 ) ,
V_89 -> V_18 -> V_94 ( V_89 ) ,
V_89 -> V_95 ) ;
}
static void F_67 ( struct V_40 * V_35 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_96 * V_97 = V_2 -> V_84 ;
struct V_98 * V_99 ;
struct V_88 * V_89 ;
unsigned long V_100 = F_68 ( & V_35 -> V_54 ) ;
F_66 ( V_91 , L_7 ,
V_2 -> V_8 , F_69 ( V_2 ) ? 'A' : 'I' ,
V_35 -> V_101 , F_70 ( & V_35 -> V_102 ) ,
V_100 , V_2 -> V_68 , V_35 -> V_21 ) ;
F_71 () ;
V_99 = F_72 ( V_97 -> V_89 ) ;
if ( V_99 ) {
unsigned int V_103 , V_104 = V_99 -> V_104 ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ ) {
V_89 = F_72 ( V_99 -> V_105 [ V_103 ] ) ;
F_64 ( V_89 , L_8 , V_91 ) ;
}
}
V_89 = F_72 ( V_97 -> V_106 ) ;
if ( V_89 )
F_64 ( V_89 , L_9 , V_91 ) ;
F_73 () ;
}
void F_74 ( struct V_107 * V_108 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 ;
int V_109 = 0 ;
T_5 V_21 = 0 ;
F_43 ( & V_108 -> V_110 ) ;
F_40 (etnaviv_obj, &priv->gem_list, gem_node) {
struct V_40 * V_35 = & V_2 -> V_5 ;
F_75 ( V_91 , L_10 ) ;
F_67 ( V_35 , V_91 ) ;
V_109 ++ ;
V_21 += V_35 -> V_21 ;
}
F_32 ( & V_108 -> V_110 ) ;
F_66 ( V_91 , L_11 , V_109 , V_21 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 -> V_68 ) ;
F_10 ( V_2 ) ;
}
void F_78 ( struct V_40 * V_35 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_55 * V_58 , * V_111 ;
F_44 ( F_69 ( V_2 ) ) ;
F_50 ( & V_2 -> V_112 ) ;
F_79 (mapping, tmp, &etnaviv_obj->vram_list,
obj_node) {
struct V_56 * V_57 = V_58 -> V_57 ;
F_44 ( V_58 -> V_60 ) ;
if ( V_57 )
F_80 ( V_57 , V_58 ) ;
F_50 ( & V_58 -> V_65 ) ;
F_12 ( V_58 ) ;
}
F_81 ( V_35 ) ;
V_2 -> V_18 -> V_113 ( V_2 ) ;
if ( V_2 -> V_84 == & V_2 -> V_114 )
F_82 ( & V_2 -> V_114 ) ;
F_83 ( V_35 ) ;
F_12 ( V_2 ) ;
}
int F_84 ( struct V_3 * V_4 , struct V_40 * V_35 )
{
struct V_107 * V_108 = V_4 -> V_115 ;
struct V_1 * V_2 = F_29 ( V_35 ) ;
F_43 ( & V_108 -> V_110 ) ;
F_52 ( & V_2 -> V_112 , & V_108 -> V_116 ) ;
F_32 ( & V_108 -> V_110 ) ;
return 0 ;
}
static int F_85 ( struct V_3 * V_4 , T_4 V_21 , T_4 V_8 ,
struct V_96 * V_97 , const struct V_117 * V_18 ,
struct V_40 * * V_35 )
{
struct V_1 * V_2 ;
unsigned V_118 = sizeof( * V_2 ) ;
bool V_119 = true ;
switch ( V_8 & V_9 ) {
case V_30 :
case V_86 :
case V_29 :
break;
default:
V_119 = false ;
}
if ( ! V_119 ) {
F_8 ( V_4 -> V_4 , L_12 ,
( V_8 & V_9 ) ) ;
return - V_120 ;
}
V_2 = F_48 ( V_118 , V_63 ) ;
if ( ! V_2 )
return - V_50 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_18 = V_18 ;
if ( V_97 ) {
V_2 -> V_84 = V_97 ;
} else {
V_2 -> V_84 = & V_2 -> V_114 ;
F_86 ( & V_2 -> V_114 ) ;
}
F_87 ( & V_2 -> V_17 ) ;
F_49 ( & V_2 -> V_67 ) ;
* V_35 = & V_2 -> V_5 ;
return 0 ;
}
static struct V_40 * F_88 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_40 * V_35 = NULL ;
int V_16 ;
V_21 = F_89 ( V_21 ) ;
V_16 = F_85 ( V_4 , V_21 , V_8 , NULL ,
& V_121 , & V_35 ) ;
if ( V_16 )
goto V_122;
V_16 = F_90 ( V_4 , V_35 , V_21 ) ;
if ( V_16 == 0 ) {
struct V_123 * V_58 ;
V_58 = V_35 -> V_32 -> V_124 ;
F_91 ( V_58 , V_125 ) ;
}
if ( V_16 )
goto V_122;
return V_35 ;
V_122:
F_46 ( V_35 ) ;
return F_16 ( V_16 ) ;
}
int F_92 ( struct V_3 * V_4 , struct V_126 * V_34 ,
T_4 V_21 , T_4 V_8 , T_4 * V_127 )
{
struct V_40 * V_35 ;
int V_16 ;
V_35 = F_88 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_35 ) )
return F_9 ( V_35 ) ;
V_16 = F_84 ( V_4 , V_35 ) ;
if ( V_16 < 0 ) {
F_46 ( V_35 ) ;
return V_16 ;
}
V_16 = F_93 ( V_34 , V_35 , V_127 ) ;
F_46 ( V_35 ) ;
return V_16 ;
}
struct V_40 * F_94 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_40 * V_35 ;
int V_16 ;
V_35 = F_88 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_35 ) )
return V_35 ;
V_16 = F_84 ( V_4 , V_35 ) ;
if ( V_16 < 0 ) {
F_46 ( V_35 ) ;
return F_16 ( V_16 ) ;
}
return V_35 ;
}
int F_95 ( struct V_3 * V_4 , T_5 V_21 , T_4 V_8 ,
struct V_96 * V_97 , const struct V_117 * V_18 ,
struct V_1 * * V_128 )
{
struct V_40 * V_35 ;
int V_16 ;
V_16 = F_85 ( V_4 , V_21 , V_8 , V_97 , V_18 , & V_35 ) ;
if ( V_16 )
return V_16 ;
F_96 ( V_4 , V_35 , V_21 ) ;
* V_128 = F_29 ( V_35 ) ;
return 0 ;
}
static struct V_13 * * F_97 (
struct V_1 * V_2 , struct V_129 * V_130 , struct V_131 * V_132 )
{
int V_16 = 0 , V_133 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
struct V_13 * * V_134 ;
T_6 V_135 ;
unsigned int V_8 = 0 ;
V_134 = F_98 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_134 )
return F_16 ( - V_50 ) ;
if ( ! V_2 -> V_136 . V_137 )
V_8 |= V_138 ;
V_133 = 0 ;
V_135 = V_2 -> V_136 . V_135 ;
F_99 ( & V_130 -> V_139 ) ;
while ( V_133 < V_20 ) {
V_16 = F_100 ( V_132 , V_130 , V_135 , V_20 - V_133 ,
V_8 , V_134 + V_133 , NULL , NULL ) ;
if ( V_16 < 0 )
break;
V_135 += V_16 * V_140 ;
V_133 += V_16 ;
}
F_101 ( & V_130 -> V_139 ) ;
if ( V_16 < 0 ) {
F_102 ( V_134 , V_133 , 0 ) ;
F_103 ( V_134 ) ;
return F_16 ( V_16 ) ;
}
return V_134 ;
}
static void F_104 ( struct V_141 * V_142 )
{
struct V_143 * V_144 = F_105 ( V_142 , F_106 ( * V_144 ) , V_144 ) ;
struct V_1 * V_2 = V_144 -> V_2 ;
struct V_13 * * V_134 ;
V_134 = F_97 ( V_2 , V_144 -> V_130 , V_144 -> V_132 ) ;
F_43 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_134 ) ) {
V_2 -> V_136 . V_144 = F_18 ( V_134 ) ;
} else {
V_2 -> V_136 . V_144 = NULL ;
V_2 -> V_15 = V_134 ;
}
F_32 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_5 ) ;
F_107 ( V_144 -> V_130 ) ;
F_108 ( V_144 -> V_132 ) ;
F_12 ( V_144 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_13 * * V_134 = NULL ;
struct V_143 * V_144 ;
struct V_129 * V_130 ;
int V_16 , V_133 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
if ( V_2 -> V_136 . V_144 ) {
if ( F_7 ( V_2 -> V_136 . V_144 ) ) {
V_16 = F_9 ( V_2 -> V_136 . V_144 ) ;
V_2 -> V_136 . V_144 = NULL ;
} else {
V_16 = - V_45 ;
}
return V_16 ;
}
V_130 = F_110 ( V_2 -> V_136 . V_132 ) ;
V_133 = 0 ;
if ( V_130 == V_145 -> V_130 ) {
V_134 = F_98 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_134 ) {
F_107 ( V_130 ) ;
return - V_50 ;
}
V_133 = F_111 ( V_2 -> V_136 . V_135 , V_20 ,
! V_2 -> V_136 . V_137 , V_134 ) ;
if ( V_133 < 0 ) {
F_103 ( V_134 ) ;
F_107 ( V_130 ) ;
return V_133 ;
}
if ( V_133 == V_20 ) {
V_2 -> V_15 = V_134 ;
F_107 ( V_130 ) ;
return 0 ;
}
}
F_102 ( V_134 , V_133 , 0 ) ;
F_103 ( V_134 ) ;
V_144 = F_112 ( sizeof( * V_144 ) , V_63 ) ;
if ( ! V_144 ) {
F_107 ( V_130 ) ;
return - V_50 ;
}
F_113 ( V_145 ) ;
F_42 ( & V_2 -> V_5 ) ;
V_144 -> V_130 = V_130 ;
V_144 -> V_132 = V_145 ;
V_144 -> V_2 = V_2 ;
V_2 -> V_136 . V_144 = & V_144 -> V_144 ;
F_114 ( & V_144 -> V_144 , F_104 ) ;
F_115 ( V_2 -> V_5 . V_4 , & V_144 -> V_144 ) ;
return - V_45 ;
}
static void F_116 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 ) {
F_3 ( V_2 ) ;
F_11 ( V_2 -> V_7 ) ;
F_12 ( V_2 -> V_7 ) ;
}
if ( V_2 -> V_15 ) {
int V_20 = V_2 -> V_5 . V_21 >> V_22 ;
F_102 ( V_2 -> V_15 , V_20 , 0 ) ;
F_103 ( V_2 -> V_15 ) ;
}
F_108 ( V_2 -> V_136 . V_132 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
return - V_120 ;
}
int F_118 ( struct V_3 * V_4 , struct V_126 * V_34 ,
T_6 V_135 , T_4 V_21 , T_4 V_8 , T_4 * V_127 )
{
struct V_1 * V_2 ;
int V_16 ;
V_16 = F_95 ( V_4 , V_21 , V_86 , NULL ,
& V_146 , & V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_136 . V_135 = V_135 ;
V_2 -> V_136 . V_132 = V_145 ;
V_2 -> V_136 . V_137 = ! ( V_8 & V_147 ) ;
F_113 ( V_145 ) ;
V_16 = F_84 ( V_4 , & V_2 -> V_5 ) ;
if ( V_16 )
goto V_148;
V_16 = F_93 ( V_34 , & V_2 -> V_5 , V_127 ) ;
V_148:
F_46 ( & V_2 -> V_5 ) ;
return V_16 ;
}
