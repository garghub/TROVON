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
static int F_20 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
T_1 V_27 ;
V_26 -> V_28 &= ~ V_29 ;
V_26 -> V_28 |= V_30 ;
V_27 = F_22 ( V_26 -> V_28 ) ;
if ( V_2 -> V_8 & V_31 ) {
V_26 -> V_27 = F_23 ( V_27 ) ;
} else if ( V_2 -> V_8 & V_32 ) {
V_26 -> V_27 = F_24 ( V_27 ) ;
} else {
F_25 ( V_26 -> V_33 ) ;
F_26 ( V_24 -> V_34 ) ;
V_26 -> V_35 = 0 ;
V_26 -> V_33 = V_24 -> V_34 ;
V_26 -> V_27 = V_27 ;
}
return 0 ;
}
int F_27 ( struct V_36 * V_34 , struct V_25 * V_26 )
{
struct V_1 * V_24 ;
int V_16 ;
V_16 = F_28 ( V_34 , V_26 ) ;
if ( V_16 ) {
F_29 ( L_3 , V_16 ) ;
return V_16 ;
}
V_24 = F_21 ( V_26 -> V_37 ) ;
return F_20 ( V_26 -> V_37 , V_26 ) ;
}
int F_30 ( struct V_25 * V_26 , struct V_38 * V_39 )
{
struct V_23 * V_24 = V_26 -> V_37 ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_13 * * V_15 , * V_13 ;
T_2 V_40 ;
int V_16 ;
V_16 = F_31 ( & V_2 -> V_17 ) ;
if ( V_16 )
goto V_41;
V_15 = F_14 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_15 ) ) {
V_16 = F_9 ( V_15 ) ;
goto V_41;
}
V_40 = ( ( unsigned long ) V_39 -> V_42 -
V_26 -> V_43 ) >> V_22 ;
V_13 = V_15 [ V_40 ] ;
F_33 ( L_4 , V_39 -> V_42 ,
F_34 ( V_13 ) , F_34 ( V_13 ) << V_22 ) ;
V_16 = F_35 ( V_26 , ( unsigned long ) V_39 -> V_42 , V_13 ) ;
V_41:
switch ( V_16 ) {
case - V_44 :
case 0 :
case - V_45 :
case - V_46 :
case - V_47 :
return V_48 ;
case - V_49 :
return V_50 ;
default:
return V_51 ;
}
}
int F_36 ( struct V_23 * V_24 , T_3 * V_52 )
{
int V_16 ;
V_16 = F_37 ( V_24 ) ;
if ( V_16 )
F_8 ( V_24 -> V_4 -> V_4 , L_5 ) ;
else
* V_52 = F_38 ( & V_24 -> V_53 ) ;
return V_16 ;
}
static struct V_54 *
F_39 ( struct V_1 * V_24 ,
struct V_55 * V_56 )
{
struct V_54 * V_57 ;
F_40 (mapping, &obj->vram_list, obj_node) {
if ( V_57 -> V_56 == V_56 )
return V_57 ;
}
return NULL ;
}
void F_41 ( struct V_54 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
F_42 ( & V_2 -> V_5 ) ;
F_43 ( & V_2 -> V_17 ) ;
F_44 ( V_57 -> V_59 == 0 ) ;
V_57 -> V_59 += 1 ;
F_32 ( & V_2 -> V_17 ) ;
}
void F_45 ( struct V_54 * V_57 )
{
struct V_1 * V_2 = V_57 -> V_58 ;
F_43 ( & V_2 -> V_17 ) ;
F_44 ( V_57 -> V_59 == 0 ) ;
V_57 -> V_59 -= 1 ;
F_32 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_5 ) ;
}
struct V_54 * F_47 (
struct V_23 * V_24 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_54 * V_57 ;
struct V_13 * * V_15 ;
int V_16 = 0 ;
F_43 ( & V_2 -> V_17 ) ;
V_57 = F_39 ( V_2 , V_61 -> V_56 ) ;
if ( V_57 ) {
if ( V_57 -> V_59 == 0 ) {
F_43 ( & V_61 -> V_56 -> V_17 ) ;
if ( V_57 -> V_56 == V_61 -> V_56 )
V_57 -> V_59 += 1 ;
else
V_57 = NULL ;
F_32 ( & V_61 -> V_56 -> V_17 ) ;
if ( V_57 )
goto V_41;
} else {
V_57 -> V_59 += 1 ;
goto V_41;
}
}
V_15 = F_14 ( V_2 ) ;
if ( F_7 ( V_15 ) ) {
V_16 = F_9 ( V_15 ) ;
goto V_41;
}
V_57 = F_39 ( V_2 , NULL ) ;
if ( ! V_57 ) {
V_57 = F_48 ( sizeof( * V_57 ) , V_62 ) ;
if ( ! V_57 ) {
V_16 = - V_49 ;
goto V_41;
}
F_49 ( & V_57 -> V_63 ) ;
V_57 -> V_58 = V_2 ;
} else {
F_50 ( & V_57 -> V_64 ) ;
}
V_57 -> V_56 = V_61 -> V_56 ;
V_57 -> V_59 = 1 ;
V_16 = F_51 ( V_61 -> V_56 , V_2 , V_61 -> V_65 ,
V_57 ) ;
if ( V_16 < 0 )
F_12 ( V_57 ) ;
else
F_52 ( & V_57 -> V_64 , & V_2 -> V_66 ) ;
V_41:
F_32 ( & V_2 -> V_17 ) ;
if ( V_16 )
return F_16 ( V_16 ) ;
F_42 ( V_24 ) ;
return V_57 ;
}
void * F_53 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
if ( V_2 -> V_67 )
return V_2 -> V_67 ;
F_43 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_67 )
V_2 -> V_67 = V_2 -> V_18 -> V_68 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
return V_2 -> V_67 ;
}
static void * F_54 ( struct V_1 * V_24 )
{
struct V_13 * * V_15 ;
F_15 ( & V_24 -> V_17 ) ;
V_15 = F_14 ( V_24 ) ;
if ( F_7 ( V_15 ) )
return NULL ;
return V_68 ( V_15 , V_24 -> V_5 . V_21 >> V_22 ,
V_69 , F_23 ( V_70 ) ) ;
}
static inline enum V_71 F_55 ( T_4 V_72 )
{
if ( V_72 & V_73 )
return V_74 ;
else if ( V_72 & V_75 )
return V_76 ;
else
return V_12 ;
}
int F_56 ( struct V_23 * V_24 , T_4 V_72 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_3 * V_4 = V_24 -> V_4 ;
bool V_79 = ! ! ( V_72 & V_75 ) ;
int V_16 ;
if ( V_72 & V_80 ) {
if ( ! F_57 ( V_2 -> V_81 ,
V_79 ) )
return - V_47 ;
} else {
unsigned long V_82 = F_58 ( V_78 ) ;
V_16 = F_59 ( V_2 -> V_81 ,
V_79 , true , V_82 ) ;
if ( V_16 <= 0 )
return V_16 == 0 ? - V_83 : V_16 ;
}
if ( V_2 -> V_8 & V_84 ) {
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
F_55 ( V_72 ) ) ;
V_2 -> V_85 = V_72 ;
}
return 0 ;
}
int F_61 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
if ( V_2 -> V_8 & V_84 ) {
F_44 ( V_2 -> V_85 == 0 ) ;
F_62 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_55 ( V_2 -> V_85 ) ) ;
V_2 -> V_85 = 0 ;
}
return 0 ;
}
int F_63 ( struct V_60 * V_61 , struct V_23 * V_24 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
return F_64 ( V_61 , V_2 , V_78 ) ;
}
static void F_65 ( struct V_86 * V_86 ,
const char * type , struct V_87 * V_88 )
{
if ( ! F_66 ( V_89 , & V_86 -> V_8 ) )
F_67 ( V_88 , L_6 ,
type ,
V_86 -> V_18 -> V_90 ( V_86 ) ,
V_86 -> V_18 -> V_91 ( V_86 ) ,
V_86 -> V_92 ) ;
}
static void F_68 ( struct V_23 * V_24 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_93 * V_94 = V_2 -> V_81 ;
struct V_95 * V_96 ;
struct V_86 * V_86 ;
unsigned long V_97 = F_69 ( & V_24 -> V_53 ) ;
F_67 ( V_88 , L_7 ,
V_2 -> V_8 , F_70 ( V_2 ) ? 'A' : 'I' ,
V_24 -> V_98 , V_24 -> V_99 . V_99 . V_100 ,
V_97 , V_2 -> V_67 , V_24 -> V_21 ) ;
F_71 () ;
V_96 = F_72 ( V_94 -> V_86 ) ;
if ( V_96 ) {
unsigned int V_101 , V_102 = V_96 -> V_102 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
V_86 = F_72 ( V_96 -> V_103 [ V_101 ] ) ;
F_65 ( V_86 , L_8 , V_88 ) ;
}
}
V_86 = F_72 ( V_94 -> V_104 ) ;
if ( V_86 )
F_65 ( V_86 , L_9 , V_88 ) ;
F_73 () ;
}
void F_74 ( struct V_105 * V_106 ,
struct V_87 * V_88 )
{
struct V_1 * V_2 ;
int V_107 = 0 ;
T_5 V_21 = 0 ;
F_43 ( & V_106 -> V_108 ) ;
F_40 (etnaviv_obj, &priv->gem_list, gem_node) {
struct V_23 * V_24 = & V_2 -> V_5 ;
F_75 ( V_88 , L_10 ) ;
F_68 ( V_24 , V_88 ) ;
V_107 ++ ;
V_21 += V_24 -> V_21 ;
}
F_32 ( & V_106 -> V_108 ) ;
F_67 ( V_88 , L_11 , V_107 , V_21 ) ;
}
static void F_76 ( struct V_1 * V_2 )
{
if ( V_2 -> V_67 )
F_77 ( V_2 -> V_67 ) ;
F_10 ( V_2 ) ;
}
void F_78 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_54 * V_57 , * V_109 ;
F_44 ( F_70 ( V_2 ) ) ;
F_50 ( & V_2 -> V_110 ) ;
F_79 (mapping, tmp, &etnaviv_obj->vram_list,
obj_node) {
struct V_55 * V_56 = V_57 -> V_56 ;
F_44 ( V_57 -> V_59 ) ;
if ( V_56 )
F_80 ( V_56 , V_57 ) ;
F_50 ( & V_57 -> V_64 ) ;
F_12 ( V_57 ) ;
}
F_81 ( V_24 ) ;
V_2 -> V_18 -> V_111 ( V_2 ) ;
if ( V_2 -> V_81 == & V_2 -> V_112 )
F_82 ( & V_2 -> V_112 ) ;
F_83 ( V_24 ) ;
F_12 ( V_2 ) ;
}
int F_84 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_105 * V_106 = V_4 -> V_113 ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
F_43 ( & V_106 -> V_108 ) ;
F_52 ( & V_2 -> V_110 , & V_106 -> V_114 ) ;
F_32 ( & V_106 -> V_108 ) ;
return 0 ;
}
static int F_85 ( struct V_3 * V_4 , T_4 V_21 , T_4 V_8 ,
struct V_93 * V_94 , const struct V_115 * V_18 ,
struct V_23 * * V_24 )
{
struct V_1 * V_2 ;
unsigned V_116 = sizeof( * V_2 ) ;
bool V_117 = true ;
switch ( V_8 & V_9 ) {
case V_32 :
case V_84 :
case V_31 :
break;
default:
V_117 = false ;
}
if ( ! V_117 ) {
F_8 ( V_4 -> V_4 , L_12 ,
( V_8 & V_9 ) ) ;
return - V_118 ;
}
V_2 = F_48 ( V_116 , V_62 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_18 = V_18 ;
if ( V_94 ) {
V_2 -> V_81 = V_94 ;
} else {
V_2 -> V_81 = & V_2 -> V_112 ;
F_86 ( & V_2 -> V_112 ) ;
}
F_87 ( & V_2 -> V_17 ) ;
F_49 ( & V_2 -> V_66 ) ;
* V_24 = & V_2 -> V_5 ;
return 0 ;
}
static struct V_23 * F_88 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_23 * V_24 = NULL ;
int V_16 ;
V_21 = F_89 ( V_21 ) ;
V_16 = F_85 ( V_4 , V_21 , V_8 , NULL ,
& V_119 , & V_24 ) ;
if ( V_16 )
goto V_120;
V_16 = F_90 ( V_4 , V_24 , V_21 ) ;
if ( V_16 == 0 ) {
struct V_121 * V_57 ;
V_57 = F_91 ( V_24 -> V_34 ) -> V_122 ;
F_92 ( V_57 , V_123 ) ;
}
if ( V_16 )
goto V_120;
return V_24 ;
V_120:
if ( V_24 )
F_46 ( V_24 ) ;
return F_16 ( V_16 ) ;
}
int F_93 ( struct V_3 * V_4 , struct V_124 * V_36 ,
T_4 V_21 , T_4 V_8 , T_4 * V_125 )
{
struct V_23 * V_24 ;
int V_16 ;
V_24 = F_88 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_24 ) )
return F_9 ( V_24 ) ;
V_16 = F_84 ( V_4 , V_24 ) ;
if ( V_16 < 0 ) {
F_46 ( V_24 ) ;
return V_16 ;
}
V_16 = F_94 ( V_36 , V_24 , V_125 ) ;
F_46 ( V_24 ) ;
return V_16 ;
}
struct V_23 * F_95 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_23 * V_24 ;
int V_16 ;
V_24 = F_88 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_24 ) )
return V_24 ;
V_16 = F_84 ( V_4 , V_24 ) ;
if ( V_16 < 0 ) {
F_46 ( V_24 ) ;
return F_16 ( V_16 ) ;
}
return V_24 ;
}
int F_96 ( struct V_3 * V_4 , T_5 V_21 , T_4 V_8 ,
struct V_93 * V_94 , const struct V_115 * V_18 ,
struct V_1 * * V_126 )
{
struct V_23 * V_24 ;
int V_16 ;
V_16 = F_85 ( V_4 , V_21 , V_8 , V_94 , V_18 , & V_24 ) ;
if ( V_16 )
return V_16 ;
F_97 ( V_4 , V_24 , V_21 ) ;
* V_126 = F_21 ( V_24 ) ;
return 0 ;
}
static struct V_13 * * F_98 (
struct V_1 * V_2 , struct V_127 * V_128 , struct V_129 * V_130 )
{
int V_16 = 0 , V_131 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
struct V_13 * * V_132 ;
T_6 V_133 ;
V_132 = F_99 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_132 )
return F_16 ( - V_49 ) ;
V_131 = 0 ;
V_133 = V_2 -> V_134 . V_133 ;
F_100 ( & V_128 -> V_135 ) ;
while ( V_131 < V_20 ) {
V_16 = F_101 ( V_130 , V_128 , V_133 , V_20 - V_131 ,
! V_2 -> V_134 . V_136 , 0 ,
V_132 + V_131 , NULL ) ;
if ( V_16 < 0 )
break;
V_133 += V_16 * V_137 ;
V_131 += V_16 ;
}
F_102 ( & V_128 -> V_135 ) ;
if ( V_16 < 0 ) {
F_103 ( V_132 , V_131 , 0 ) ;
F_104 ( V_132 ) ;
return F_16 ( V_16 ) ;
}
return V_132 ;
}
static void F_105 ( struct V_138 * V_139 )
{
struct V_140 * V_141 = F_106 ( V_139 , F_107 ( * V_141 ) , V_141 ) ;
struct V_1 * V_2 = V_141 -> V_2 ;
struct V_13 * * V_132 ;
V_132 = F_98 ( V_2 , V_141 -> V_128 , V_141 -> V_130 ) ;
F_43 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_132 ) ) {
V_2 -> V_134 . V_141 = F_18 ( V_132 ) ;
} else {
V_2 -> V_134 . V_141 = NULL ;
V_2 -> V_15 = V_132 ;
}
F_32 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_5 ) ;
F_108 ( V_141 -> V_128 ) ;
F_109 ( V_141 -> V_130 ) ;
F_12 ( V_141 ) ;
}
static int F_110 ( struct V_1 * V_2 )
{
struct V_13 * * V_132 = NULL ;
struct V_140 * V_141 ;
struct V_127 * V_128 ;
int V_16 , V_131 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
if ( V_2 -> V_134 . V_141 ) {
if ( F_7 ( V_2 -> V_134 . V_141 ) ) {
V_16 = F_9 ( V_2 -> V_134 . V_141 ) ;
V_2 -> V_134 . V_141 = NULL ;
} else {
V_16 = - V_44 ;
}
return V_16 ;
}
V_128 = F_111 ( V_2 -> V_134 . V_130 ) ;
V_131 = 0 ;
if ( V_128 == V_142 -> V_128 ) {
V_132 = F_99 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_132 ) {
F_108 ( V_128 ) ;
return - V_49 ;
}
V_131 = F_112 ( V_2 -> V_134 . V_133 , V_20 ,
! V_2 -> V_134 . V_136 , V_132 ) ;
if ( V_131 < 0 ) {
F_104 ( V_132 ) ;
F_108 ( V_128 ) ;
return V_131 ;
}
if ( V_131 == V_20 ) {
V_2 -> V_15 = V_132 ;
F_108 ( V_128 ) ;
return 0 ;
}
}
F_103 ( V_132 , V_131 , 0 ) ;
F_104 ( V_132 ) ;
V_141 = F_113 ( sizeof( * V_141 ) , V_62 ) ;
if ( ! V_141 ) {
F_108 ( V_128 ) ;
return - V_49 ;
}
F_114 ( V_142 ) ;
F_42 ( & V_2 -> V_5 ) ;
V_141 -> V_128 = V_128 ;
V_141 -> V_130 = V_142 ;
V_141 -> V_2 = V_2 ;
V_2 -> V_134 . V_141 = & V_141 -> V_141 ;
F_115 ( & V_141 -> V_141 , F_105 ) ;
F_116 ( V_2 -> V_5 . V_4 , & V_141 -> V_141 ) ;
return - V_44 ;
}
static void F_117 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 ) {
F_3 ( V_2 ) ;
F_11 ( V_2 -> V_7 ) ;
F_12 ( V_2 -> V_7 ) ;
}
if ( V_2 -> V_15 ) {
int V_20 = V_2 -> V_5 . V_21 >> V_22 ;
F_103 ( V_2 -> V_15 , V_20 , 0 ) ;
F_104 ( V_2 -> V_15 ) ;
}
F_109 ( V_2 -> V_134 . V_130 ) ;
}
int F_118 ( struct V_3 * V_4 , struct V_124 * V_36 ,
T_6 V_133 , T_4 V_21 , T_4 V_8 , T_4 * V_125 )
{
struct V_1 * V_2 ;
int V_16 ;
V_16 = F_96 ( V_4 , V_21 , V_84 , NULL ,
& V_143 , & V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_134 . V_133 = V_133 ;
V_2 -> V_134 . V_130 = V_142 ;
V_2 -> V_134 . V_136 = ! ( V_8 & V_144 ) ;
F_114 ( V_142 ) ;
V_16 = F_84 ( V_4 , & V_2 -> V_5 ) ;
if ( V_16 ) {
F_46 ( & V_2 -> V_5 ) ;
return V_16 ;
}
V_16 = F_94 ( V_36 , & V_2 -> V_5 , V_125 ) ;
F_46 ( & V_2 -> V_5 ) ;
return V_16 ;
}
