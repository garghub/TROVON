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
int F_30 ( struct V_23 * V_24 , struct V_38 * V_39 )
{
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
V_41 = ( ( unsigned long ) V_39 -> V_43 -
V_24 -> V_44 ) >> V_22 ;
V_13 = V_15 [ V_41 ] ;
F_33 ( L_4 , V_39 -> V_43 ,
F_34 ( V_13 ) , F_34 ( V_13 ) << V_22 ) ;
V_16 = F_35 ( V_24 , ( unsigned long ) V_39 -> V_43 , V_13 ) ;
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
int V_16 ;
if ( V_73 & V_81 ) {
if ( ! F_57 ( V_2 -> V_82 ,
V_80 ) )
return - V_48 ;
} else {
unsigned long V_83 = F_58 ( V_79 ) ;
V_16 = F_59 ( V_2 -> V_82 ,
V_80 , true , V_83 ) ;
if ( V_16 <= 0 )
return V_16 == 0 ? - V_84 : V_16 ;
}
if ( V_2 -> V_8 & V_85 ) {
if ( ! V_2 -> V_7 ) {
void * V_16 ;
F_43 ( & V_2 -> V_17 ) ;
V_16 = F_14 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_16 ) )
return F_9 ( V_16 ) ;
}
F_60 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_55 ( V_73 ) ) ;
V_2 -> V_86 = V_73 ;
}
return 0 ;
}
int F_61 ( struct V_40 * V_35 )
{
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 = F_29 ( V_35 ) ;
if ( V_2 -> V_8 & V_85 ) {
F_44 ( V_2 -> V_86 == 0 ) ;
F_62 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_55 ( V_2 -> V_86 ) ) ;
V_2 -> V_86 = 0 ;
}
return 0 ;
}
int F_63 ( struct V_61 * V_62 , struct V_40 * V_35 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
return F_64 ( V_62 , V_2 , V_79 ) ;
}
static void F_65 ( struct V_87 * V_87 ,
const char * type , struct V_88 * V_89 )
{
if ( ! F_66 ( V_90 , & V_87 -> V_8 ) )
F_67 ( V_89 , L_6 ,
type ,
V_87 -> V_18 -> V_91 ( V_87 ) ,
V_87 -> V_18 -> V_92 ( V_87 ) ,
V_87 -> V_93 ) ;
}
static void F_68 ( struct V_40 * V_35 , struct V_88 * V_89 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_94 * V_95 = V_2 -> V_82 ;
struct V_96 * V_97 ;
struct V_87 * V_87 ;
unsigned long V_98 = F_69 ( & V_35 -> V_54 ) ;
F_67 ( V_89 , L_7 ,
V_2 -> V_8 , F_70 ( V_2 ) ? 'A' : 'I' ,
V_35 -> V_99 , V_35 -> V_100 . V_100 . V_101 ,
V_98 , V_2 -> V_68 , V_35 -> V_21 ) ;
F_71 () ;
V_97 = F_72 ( V_95 -> V_87 ) ;
if ( V_97 ) {
unsigned int V_102 , V_103 = V_97 -> V_103 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
V_87 = F_72 ( V_97 -> V_104 [ V_102 ] ) ;
F_65 ( V_87 , L_8 , V_89 ) ;
}
}
V_87 = F_72 ( V_95 -> V_105 ) ;
if ( V_87 )
F_65 ( V_87 , L_9 , V_89 ) ;
F_73 () ;
}
void F_74 ( struct V_106 * V_107 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 ;
int V_108 = 0 ;
T_5 V_21 = 0 ;
F_43 ( & V_107 -> V_109 ) ;
F_40 (etnaviv_obj, &priv->gem_list, gem_node) {
struct V_40 * V_35 = & V_2 -> V_5 ;
F_75 ( V_89 , L_10 ) ;
F_68 ( V_35 , V_89 ) ;
V_108 ++ ;
V_21 += V_35 -> V_21 ;
}
F_32 ( & V_107 -> V_109 ) ;
F_67 ( V_89 , L_11 , V_108 , V_21 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
F_77 ( V_2 -> V_68 ) ;
F_10 ( V_2 ) ;
}
void F_78 ( struct V_40 * V_35 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_55 * V_58 , * V_110 ;
F_44 ( F_70 ( V_2 ) ) ;
F_50 ( & V_2 -> V_111 ) ;
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
V_2 -> V_18 -> V_112 ( V_2 ) ;
if ( V_2 -> V_82 == & V_2 -> V_113 )
F_82 ( & V_2 -> V_113 ) ;
F_83 ( V_35 ) ;
F_12 ( V_2 ) ;
}
int F_84 ( struct V_3 * V_4 , struct V_40 * V_35 )
{
struct V_106 * V_107 = V_4 -> V_114 ;
struct V_1 * V_2 = F_29 ( V_35 ) ;
F_43 ( & V_107 -> V_109 ) ;
F_52 ( & V_2 -> V_111 , & V_107 -> V_115 ) ;
F_32 ( & V_107 -> V_109 ) ;
return 0 ;
}
static int F_85 ( struct V_3 * V_4 , T_4 V_21 , T_4 V_8 ,
struct V_94 * V_95 , const struct V_116 * V_18 ,
struct V_40 * * V_35 )
{
struct V_1 * V_2 ;
unsigned V_117 = sizeof( * V_2 ) ;
bool V_118 = true ;
switch ( V_8 & V_9 ) {
case V_30 :
case V_85 :
case V_29 :
break;
default:
V_118 = false ;
}
if ( ! V_118 ) {
F_8 ( V_4 -> V_4 , L_12 ,
( V_8 & V_9 ) ) ;
return - V_119 ;
}
V_2 = F_48 ( V_117 , V_63 ) ;
if ( ! V_2 )
return - V_50 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_18 = V_18 ;
if ( V_95 ) {
V_2 -> V_82 = V_95 ;
} else {
V_2 -> V_82 = & V_2 -> V_113 ;
F_86 ( & V_2 -> V_113 ) ;
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
& V_120 , & V_35 ) ;
if ( V_16 )
goto V_121;
V_16 = F_90 ( V_4 , V_35 , V_21 ) ;
if ( V_16 == 0 ) {
struct V_122 * V_58 ;
V_58 = V_35 -> V_32 -> V_123 ;
F_91 ( V_58 , V_124 ) ;
}
if ( V_16 )
goto V_121;
return V_35 ;
V_121:
F_46 ( V_35 ) ;
return F_16 ( V_16 ) ;
}
int F_92 ( struct V_3 * V_4 , struct V_125 * V_34 ,
T_4 V_21 , T_4 V_8 , T_4 * V_126 )
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
V_16 = F_93 ( V_34 , V_35 , V_126 ) ;
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
struct V_94 * V_95 , const struct V_116 * V_18 ,
struct V_1 * * V_127 )
{
struct V_40 * V_35 ;
int V_16 ;
V_16 = F_85 ( V_4 , V_21 , V_8 , V_95 , V_18 , & V_35 ) ;
if ( V_16 )
return V_16 ;
F_96 ( V_4 , V_35 , V_21 ) ;
* V_127 = F_29 ( V_35 ) ;
return 0 ;
}
static struct V_13 * * F_97 (
struct V_1 * V_2 , struct V_128 * V_129 , struct V_130 * V_131 )
{
int V_16 = 0 , V_132 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
struct V_13 * * V_133 ;
T_6 V_134 ;
unsigned int V_8 = 0 ;
V_133 = F_98 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_133 )
return F_16 ( - V_50 ) ;
if ( ! V_2 -> V_135 . V_136 )
V_8 |= V_137 ;
V_132 = 0 ;
V_134 = V_2 -> V_135 . V_134 ;
F_99 ( & V_129 -> V_138 ) ;
while ( V_132 < V_20 ) {
V_16 = F_100 ( V_131 , V_129 , V_134 , V_20 - V_132 ,
V_8 , V_133 + V_132 , NULL ) ;
if ( V_16 < 0 )
break;
V_134 += V_16 * V_139 ;
V_132 += V_16 ;
}
F_101 ( & V_129 -> V_138 ) ;
if ( V_16 < 0 ) {
F_102 ( V_133 , V_132 , 0 ) ;
F_103 ( V_133 ) ;
return F_16 ( V_16 ) ;
}
return V_133 ;
}
static void F_104 ( struct V_140 * V_141 )
{
struct V_142 * V_143 = F_105 ( V_141 , F_106 ( * V_143 ) , V_143 ) ;
struct V_1 * V_2 = V_143 -> V_2 ;
struct V_13 * * V_133 ;
V_133 = F_97 ( V_2 , V_143 -> V_129 , V_143 -> V_131 ) ;
F_43 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_133 ) ) {
V_2 -> V_135 . V_143 = F_18 ( V_133 ) ;
} else {
V_2 -> V_135 . V_143 = NULL ;
V_2 -> V_15 = V_133 ;
}
F_32 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_5 ) ;
F_107 ( V_143 -> V_129 ) ;
F_108 ( V_143 -> V_131 ) ;
F_12 ( V_143 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_13 * * V_133 = NULL ;
struct V_142 * V_143 ;
struct V_128 * V_129 ;
int V_16 , V_132 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
if ( V_2 -> V_135 . V_143 ) {
if ( F_7 ( V_2 -> V_135 . V_143 ) ) {
V_16 = F_9 ( V_2 -> V_135 . V_143 ) ;
V_2 -> V_135 . V_143 = NULL ;
} else {
V_16 = - V_45 ;
}
return V_16 ;
}
V_129 = F_110 ( V_2 -> V_135 . V_131 ) ;
V_132 = 0 ;
if ( V_129 == V_144 -> V_129 ) {
V_133 = F_98 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_133 ) {
F_107 ( V_129 ) ;
return - V_50 ;
}
V_132 = F_111 ( V_2 -> V_135 . V_134 , V_20 ,
! V_2 -> V_135 . V_136 , V_133 ) ;
if ( V_132 < 0 ) {
F_103 ( V_133 ) ;
F_107 ( V_129 ) ;
return V_132 ;
}
if ( V_132 == V_20 ) {
V_2 -> V_15 = V_133 ;
F_107 ( V_129 ) ;
return 0 ;
}
}
F_102 ( V_133 , V_132 , 0 ) ;
F_103 ( V_133 ) ;
V_143 = F_112 ( sizeof( * V_143 ) , V_63 ) ;
if ( ! V_143 ) {
F_107 ( V_129 ) ;
return - V_50 ;
}
F_113 ( V_144 ) ;
F_42 ( & V_2 -> V_5 ) ;
V_143 -> V_129 = V_129 ;
V_143 -> V_131 = V_144 ;
V_143 -> V_2 = V_2 ;
V_2 -> V_135 . V_143 = & V_143 -> V_143 ;
F_114 ( & V_143 -> V_143 , F_104 ) ;
F_115 ( V_2 -> V_5 . V_4 , & V_143 -> V_143 ) ;
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
F_108 ( V_2 -> V_135 . V_131 ) ;
}
static int F_117 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
return - V_119 ;
}
int F_118 ( struct V_3 * V_4 , struct V_125 * V_34 ,
T_6 V_134 , T_4 V_21 , T_4 V_8 , T_4 * V_126 )
{
struct V_1 * V_2 ;
int V_16 ;
V_16 = F_95 ( V_4 , V_21 , V_85 , NULL ,
& V_145 , & V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_135 . V_134 = V_134 ;
V_2 -> V_135 . V_131 = V_144 ;
V_2 -> V_135 . V_136 = ! ( V_8 & V_146 ) ;
F_113 ( V_144 ) ;
V_16 = F_84 ( V_4 , & V_2 -> V_5 ) ;
if ( V_16 )
goto V_147;
V_16 = F_93 ( V_34 , & V_2 -> V_5 , V_126 ) ;
V_147:
F_46 ( & V_2 -> V_5 ) ;
return V_16 ;
}
