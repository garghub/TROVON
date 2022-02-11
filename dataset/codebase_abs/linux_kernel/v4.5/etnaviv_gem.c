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
int F_41 ( struct V_58 * V_59 ,
struct V_23 * V_24 , T_4 * V_60 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_54 * V_57 ;
struct V_13 * * V_15 ;
int V_16 = 0 ;
F_42 ( & V_2 -> V_17 ) ;
V_57 = F_39 ( V_2 , V_59 -> V_56 ) ;
if ( V_57 ) {
if ( V_57 -> V_61 == 0 ) {
F_42 ( & V_59 -> V_56 -> V_17 ) ;
if ( V_57 -> V_56 == V_59 -> V_56 )
V_57 -> V_61 += 1 ;
else
V_57 = NULL ;
F_32 ( & V_59 -> V_56 -> V_17 ) ;
if ( V_57 )
goto V_41;
} else {
V_57 -> V_61 += 1 ;
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
V_57 = F_43 ( sizeof( * V_57 ) , V_62 ) ;
if ( ! V_57 ) {
V_16 = - V_49 ;
goto V_41;
}
F_44 ( & V_57 -> V_63 ) ;
V_57 -> V_64 = V_2 ;
} else {
F_45 ( & V_57 -> V_65 ) ;
}
V_57 -> V_56 = V_59 -> V_56 ;
V_57 -> V_61 = 1 ;
V_16 = F_46 ( V_59 -> V_56 , V_2 , V_59 -> V_66 ,
V_57 ) ;
if ( V_16 < 0 )
F_12 ( V_57 ) ;
else
F_47 ( & V_57 -> V_65 , & V_2 -> V_67 ) ;
V_41:
F_32 ( & V_2 -> V_17 ) ;
if ( ! V_16 ) {
F_48 ( V_24 ) ;
* V_60 = V_57 -> V_60 ;
}
return V_16 ;
}
void F_49 ( struct V_58 * V_59 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_54 * V_57 ;
F_42 ( & V_2 -> V_17 ) ;
V_57 = F_39 ( V_2 , V_59 -> V_56 ) ;
F_50 ( V_57 -> V_61 == 0 ) ;
V_57 -> V_61 -= 1 ;
F_32 ( & V_2 -> V_17 ) ;
F_51 ( V_24 ) ;
}
void * F_52 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
if ( V_2 -> V_68 )
return V_2 -> V_68 ;
F_42 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_68 )
V_2 -> V_68 = V_2 -> V_18 -> V_69 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
return V_2 -> V_68 ;
}
static void * F_53 ( struct V_1 * V_24 )
{
struct V_13 * * V_15 ;
F_15 ( & V_24 -> V_17 ) ;
V_15 = F_14 ( V_24 ) ;
if ( F_7 ( V_15 ) )
return NULL ;
return V_69 ( V_15 , V_24 -> V_5 . V_21 >> V_22 ,
V_70 , F_23 ( V_71 ) ) ;
}
static inline enum V_72 F_54 ( T_4 V_73 )
{
if ( V_73 & V_74 )
return V_75 ;
else if ( V_73 & V_76 )
return V_77 ;
else
return V_12 ;
}
int F_55 ( struct V_23 * V_24 , T_4 V_73 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_3 * V_4 = V_24 -> V_4 ;
bool V_80 = ! ! ( V_73 & V_76 ) ;
int V_16 ;
if ( V_73 & V_81 ) {
if ( ! F_56 ( V_2 -> V_82 ,
V_80 ) )
return - V_47 ;
} else {
unsigned long V_83 = F_57 ( V_79 ) ;
V_16 = F_58 ( V_2 -> V_82 ,
V_80 , true , V_83 ) ;
if ( V_16 <= 0 )
return V_16 == 0 ? - V_84 : V_16 ;
}
if ( V_2 -> V_8 & V_85 ) {
if ( ! V_2 -> V_7 ) {
void * V_16 ;
F_42 ( & V_2 -> V_17 ) ;
V_16 = F_14 ( V_2 ) ;
F_32 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_16 ) )
return F_9 ( V_16 ) ;
}
F_59 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_54 ( V_73 ) ) ;
V_2 -> V_86 = V_73 ;
}
return 0 ;
}
int F_60 ( struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_4 ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
if ( V_2 -> V_8 & V_85 ) {
F_50 ( V_2 -> V_86 == 0 ) ;
F_61 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_54 ( V_2 -> V_86 ) ) ;
V_2 -> V_86 = 0 ;
}
return 0 ;
}
int F_62 ( struct V_58 * V_59 , struct V_23 * V_24 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
return F_63 ( V_59 , V_2 , V_79 ) ;
}
static void F_64 ( struct V_87 * V_87 ,
const char * type , struct V_88 * V_89 )
{
if ( ! F_65 ( V_90 , & V_87 -> V_8 ) )
F_66 ( V_89 , L_6 ,
type ,
V_87 -> V_18 -> V_91 ( V_87 ) ,
V_87 -> V_18 -> V_92 ( V_87 ) ,
V_87 -> V_93 ) ;
}
static void F_67 ( struct V_23 * V_24 , struct V_88 * V_89 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_94 * V_95 = V_2 -> V_82 ;
struct V_96 * V_97 ;
struct V_87 * V_87 ;
unsigned long V_98 = F_68 ( & V_24 -> V_53 ) ;
F_66 ( V_89 , L_7 ,
V_2 -> V_8 , F_69 ( V_2 ) ? 'A' : 'I' ,
V_24 -> V_99 , V_24 -> V_100 . V_100 . V_101 ,
V_98 , V_2 -> V_68 , V_24 -> V_21 ) ;
F_70 () ;
V_97 = F_71 ( V_95 -> V_87 ) ;
if ( V_97 ) {
unsigned int V_102 , V_103 = V_97 -> V_103 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
V_87 = F_71 ( V_97 -> V_104 [ V_102 ] ) ;
F_64 ( V_87 , L_8 , V_89 ) ;
}
}
V_87 = F_71 ( V_95 -> V_105 ) ;
if ( V_87 )
F_64 ( V_87 , L_9 , V_89 ) ;
F_72 () ;
}
void F_73 ( struct V_106 * V_107 ,
struct V_88 * V_89 )
{
struct V_1 * V_2 ;
int V_108 = 0 ;
T_5 V_21 = 0 ;
F_42 ( & V_107 -> V_109 ) ;
F_40 (etnaviv_obj, &priv->gem_list, gem_node) {
struct V_23 * V_24 = & V_2 -> V_5 ;
F_74 ( V_89 , L_10 ) ;
F_67 ( V_24 , V_89 ) ;
V_108 ++ ;
V_21 += V_24 -> V_21 ;
}
F_32 ( & V_107 -> V_109 ) ;
F_66 ( V_89 , L_11 , V_108 , V_21 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_68 )
F_76 ( V_2 -> V_68 ) ;
F_10 ( V_2 ) ;
}
void F_77 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_21 ( V_24 ) ;
struct V_54 * V_57 , * V_110 ;
F_50 ( F_69 ( V_2 ) ) ;
F_45 ( & V_2 -> V_111 ) ;
F_78 (mapping, tmp, &etnaviv_obj->vram_list,
obj_node) {
struct V_55 * V_56 = V_57 -> V_56 ;
F_50 ( V_57 -> V_61 ) ;
if ( V_56 )
F_79 ( V_56 , V_57 ) ;
F_45 ( & V_57 -> V_65 ) ;
F_12 ( V_57 ) ;
}
F_80 ( V_24 ) ;
V_2 -> V_18 -> V_112 ( V_2 ) ;
if ( V_2 -> V_82 == & V_2 -> V_113 )
F_81 ( & V_2 -> V_113 ) ;
F_82 ( V_24 ) ;
F_12 ( V_2 ) ;
}
int F_83 ( struct V_3 * V_4 , struct V_23 * V_24 )
{
struct V_106 * V_107 = V_4 -> V_114 ;
struct V_1 * V_2 = F_21 ( V_24 ) ;
F_42 ( & V_107 -> V_109 ) ;
F_47 ( & V_2 -> V_111 , & V_107 -> V_115 ) ;
F_32 ( & V_107 -> V_109 ) ;
return 0 ;
}
static int F_84 ( struct V_3 * V_4 , T_4 V_21 , T_4 V_8 ,
struct V_94 * V_95 , const struct V_116 * V_18 ,
struct V_23 * * V_24 )
{
struct V_1 * V_2 ;
unsigned V_117 = sizeof( * V_2 ) ;
bool V_118 = true ;
switch ( V_8 & V_9 ) {
case V_32 :
case V_85 :
case V_31 :
break;
default:
V_118 = false ;
}
if ( ! V_118 ) {
F_8 ( V_4 -> V_4 , L_12 ,
( V_8 & V_9 ) ) ;
return - V_119 ;
}
V_2 = F_43 ( V_117 , V_62 ) ;
if ( ! V_2 )
return - V_49 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_18 = V_18 ;
if ( V_95 ) {
V_2 -> V_82 = V_95 ;
} else {
V_2 -> V_82 = & V_2 -> V_113 ;
F_85 ( & V_2 -> V_113 ) ;
}
F_86 ( & V_2 -> V_17 ) ;
F_44 ( & V_2 -> V_67 ) ;
* V_24 = & V_2 -> V_5 ;
return 0 ;
}
static struct V_23 * F_87 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_23 * V_24 = NULL ;
int V_16 ;
V_21 = F_88 ( V_21 ) ;
V_16 = F_84 ( V_4 , V_21 , V_8 , NULL ,
& V_120 , & V_24 ) ;
if ( V_16 )
goto V_121;
V_16 = F_89 ( V_4 , V_24 , V_21 ) ;
if ( V_16 == 0 ) {
struct V_122 * V_57 ;
V_57 = F_90 ( V_24 -> V_34 ) -> V_123 ;
F_91 ( V_57 , V_124 ) ;
}
if ( V_16 )
goto V_121;
return V_24 ;
V_121:
if ( V_24 )
F_51 ( V_24 ) ;
return F_16 ( V_16 ) ;
}
int F_92 ( struct V_3 * V_4 , struct V_125 * V_36 ,
T_4 V_21 , T_4 V_8 , T_4 * V_126 )
{
struct V_23 * V_24 ;
int V_16 ;
V_24 = F_87 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_24 ) )
return F_9 ( V_24 ) ;
V_16 = F_83 ( V_4 , V_24 ) ;
if ( V_16 < 0 ) {
F_51 ( V_24 ) ;
return V_16 ;
}
V_16 = F_93 ( V_36 , V_24 , V_126 ) ;
F_51 ( V_24 ) ;
return V_16 ;
}
struct V_23 * F_94 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_23 * V_24 ;
int V_16 ;
V_24 = F_87 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_24 ) )
return V_24 ;
V_16 = F_83 ( V_4 , V_24 ) ;
if ( V_16 < 0 ) {
F_51 ( V_24 ) ;
return F_16 ( V_16 ) ;
}
return V_24 ;
}
int F_95 ( struct V_3 * V_4 , T_5 V_21 , T_4 V_8 ,
struct V_94 * V_95 , const struct V_116 * V_18 ,
struct V_1 * * V_127 )
{
struct V_23 * V_24 ;
int V_16 ;
V_16 = F_84 ( V_4 , V_21 , V_8 , V_95 , V_18 , & V_24 ) ;
if ( V_16 )
return V_16 ;
F_96 ( V_4 , V_24 , V_21 ) ;
* V_127 = F_21 ( V_24 ) ;
return 0 ;
}
static struct V_13 * * F_97 (
struct V_1 * V_2 , struct V_128 * V_129 , struct V_130 * V_131 )
{
int V_16 = 0 , V_132 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
struct V_13 * * V_133 ;
T_6 V_134 ;
V_133 = F_98 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_133 )
return F_16 ( - V_49 ) ;
V_132 = 0 ;
V_134 = V_2 -> V_135 . V_134 ;
F_99 ( & V_129 -> V_136 ) ;
while ( V_132 < V_20 ) {
V_16 = F_100 ( V_131 , V_129 , V_134 , V_20 - V_132 ,
! V_2 -> V_135 . V_137 , 0 ,
V_133 + V_132 , NULL ) ;
if ( V_16 < 0 )
break;
V_134 += V_16 * V_138 ;
V_132 += V_16 ;
}
F_101 ( & V_129 -> V_136 ) ;
if ( V_16 < 0 ) {
F_102 ( V_133 , V_132 , 0 ) ;
F_103 ( V_133 ) ;
return F_16 ( V_16 ) ;
}
return V_133 ;
}
static void F_104 ( struct V_139 * V_140 )
{
struct V_141 * V_142 = F_105 ( V_140 , F_106 ( * V_142 ) , V_142 ) ;
struct V_1 * V_2 = V_142 -> V_2 ;
struct V_13 * * V_133 ;
V_133 = F_97 ( V_2 , V_142 -> V_129 , V_142 -> V_131 ) ;
F_42 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_133 ) ) {
V_2 -> V_135 . V_142 = F_18 ( V_133 ) ;
} else {
V_2 -> V_135 . V_142 = NULL ;
V_2 -> V_15 = V_133 ;
}
F_32 ( & V_2 -> V_17 ) ;
F_51 ( & V_2 -> V_5 ) ;
F_107 ( V_142 -> V_129 ) ;
F_108 ( V_142 -> V_131 ) ;
F_12 ( V_142 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_13 * * V_133 = NULL ;
struct V_141 * V_142 ;
struct V_128 * V_129 ;
int V_16 , V_132 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
if ( V_2 -> V_135 . V_142 ) {
if ( F_7 ( V_2 -> V_135 . V_142 ) ) {
V_16 = F_9 ( V_2 -> V_135 . V_142 ) ;
V_2 -> V_135 . V_142 = NULL ;
} else {
V_16 = - V_44 ;
}
return V_16 ;
}
V_129 = F_110 ( V_2 -> V_135 . V_131 ) ;
V_132 = 0 ;
if ( V_129 == V_143 -> V_129 ) {
V_133 = F_98 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_133 ) {
F_107 ( V_129 ) ;
return - V_49 ;
}
V_132 = F_111 ( V_2 -> V_135 . V_134 , V_20 ,
! V_2 -> V_135 . V_137 , V_133 ) ;
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
V_142 = F_112 ( sizeof( * V_142 ) , V_62 ) ;
if ( ! V_142 ) {
F_107 ( V_129 ) ;
return - V_49 ;
}
F_113 ( V_143 ) ;
F_48 ( & V_2 -> V_5 ) ;
V_142 -> V_129 = V_129 ;
V_142 -> V_131 = V_143 ;
V_142 -> V_2 = V_2 ;
V_2 -> V_135 . V_142 = & V_142 -> V_142 ;
F_114 ( & V_142 -> V_142 , F_104 ) ;
F_115 ( V_2 -> V_5 . V_4 , & V_142 -> V_142 ) ;
return - V_44 ;
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
int F_117 ( struct V_3 * V_4 , struct V_125 * V_36 ,
T_6 V_134 , T_4 V_21 , T_4 V_8 , T_4 * V_126 )
{
struct V_1 * V_2 ;
int V_16 ;
V_16 = F_95 ( V_4 , V_21 , V_85 , NULL ,
& V_144 , & V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_135 . V_134 = V_134 ;
V_2 -> V_135 . V_131 = V_143 ;
V_2 -> V_135 . V_137 = ! ( V_8 & V_145 ) ;
F_113 ( V_143 ) ;
V_16 = F_83 ( V_4 , & V_2 -> V_5 ) ;
if ( V_16 ) {
F_51 ( & V_2 -> V_5 ) ;
return V_16 ;
}
V_16 = F_93 ( V_36 , & V_2 -> V_5 , V_126 ) ;
F_51 ( & V_2 -> V_5 ) ;
return V_16 ;
}
