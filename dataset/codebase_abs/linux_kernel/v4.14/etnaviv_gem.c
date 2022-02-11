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
F_18 ( V_4 -> V_4 , L_2 ,
F_9 ( V_7 ) ) ;
return F_19 ( V_7 ) ;
}
V_2 -> V_7 = V_7 ;
F_1 ( V_2 ) ;
}
return V_2 -> V_15 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_17 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_1 V_25 ;
V_24 -> V_26 &= ~ V_27 ;
V_24 -> V_26 |= V_28 ;
V_25 = F_22 ( V_24 -> V_26 ) ;
if ( V_2 -> V_8 & V_29 ) {
V_24 -> V_25 = F_23 ( V_25 ) ;
} else if ( V_2 -> V_8 & V_30 ) {
V_24 -> V_25 = F_24 ( V_25 ) ;
} else {
F_25 ( V_24 -> V_31 ) ;
F_26 ( V_2 -> V_5 . V_32 ) ;
V_24 -> V_33 = 0 ;
V_24 -> V_31 = V_2 -> V_5 . V_32 ;
V_24 -> V_25 = V_25 ;
}
return 0 ;
}
int F_27 ( struct V_34 * V_32 , struct V_23 * V_24 )
{
struct V_1 * V_35 ;
int V_16 ;
V_16 = F_28 ( V_32 , V_24 ) ;
if ( V_16 ) {
F_29 ( L_3 , V_16 ) ;
return V_16 ;
}
V_35 = F_30 ( V_24 -> V_36 ) ;
return V_35 -> V_18 -> V_37 ( V_35 , V_24 ) ;
}
int F_31 ( struct V_38 * V_39 )
{
struct V_23 * V_24 = V_39 -> V_24 ;
struct V_40 * V_35 = V_24 -> V_36 ;
struct V_1 * V_2 = F_30 ( V_35 ) ;
struct V_13 * * V_15 , * V_13 ;
T_2 V_41 ;
int V_16 ;
V_16 = F_32 ( & V_2 -> V_17 ) ;
if ( V_16 )
goto V_42;
V_15 = F_14 ( V_2 ) ;
F_33 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_15 ) ) {
V_16 = F_9 ( V_15 ) ;
goto V_42;
}
V_41 = ( V_39 -> V_43 - V_24 -> V_44 ) >> V_22 ;
V_13 = V_15 [ V_41 ] ;
F_34 ( L_4 , ( void * ) V_39 -> V_43 ,
F_35 ( V_13 ) , F_35 ( V_13 ) << V_22 ) ;
V_16 = F_36 ( V_24 , V_39 -> V_43 , V_13 ) ;
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
int F_37 ( struct V_40 * V_35 , T_3 * V_53 )
{
int V_16 ;
V_16 = F_38 ( V_35 ) ;
if ( V_16 )
F_18 ( V_35 -> V_4 -> V_4 , L_5 ) ;
else
* V_53 = F_39 ( & V_35 -> V_54 ) ;
return V_16 ;
}
static struct V_55 *
F_40 ( struct V_1 * V_35 ,
struct V_56 * V_57 )
{
struct V_55 * V_58 ;
F_41 (mapping, &obj->vram_list, obj_node) {
if ( V_58 -> V_57 == V_57 )
return V_58 ;
}
return NULL ;
}
void F_42 ( struct V_55 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
F_43 ( & V_2 -> V_5 ) ;
F_44 ( & V_2 -> V_17 ) ;
F_45 ( V_58 -> V_60 == 0 ) ;
V_58 -> V_60 += 1 ;
F_33 ( & V_2 -> V_17 ) ;
}
void F_46 ( struct V_55 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_59 ;
F_44 ( & V_2 -> V_17 ) ;
F_45 ( V_58 -> V_60 == 0 ) ;
V_58 -> V_60 -= 1 ;
F_33 ( & V_2 -> V_17 ) ;
F_47 ( & V_2 -> V_5 ) ;
}
struct V_55 * F_48 (
struct V_40 * V_35 , struct V_61 * V_62 )
{
struct V_1 * V_2 = F_30 ( V_35 ) ;
struct V_55 * V_58 ;
struct V_13 * * V_15 ;
int V_16 = 0 ;
F_44 ( & V_2 -> V_17 ) ;
V_58 = F_40 ( V_2 , V_62 -> V_57 ) ;
if ( V_58 ) {
if ( V_58 -> V_60 == 0 ) {
F_44 ( & V_62 -> V_57 -> V_17 ) ;
if ( V_58 -> V_57 == V_62 -> V_57 )
V_58 -> V_60 += 1 ;
else
V_58 = NULL ;
F_33 ( & V_62 -> V_57 -> V_17 ) ;
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
V_58 = F_40 ( V_2 , NULL ) ;
if ( ! V_58 ) {
V_58 = F_49 ( sizeof( * V_58 ) , V_63 ) ;
if ( ! V_58 ) {
V_16 = - V_50 ;
goto V_42;
}
F_50 ( & V_58 -> V_64 ) ;
V_58 -> V_59 = V_2 ;
} else {
F_51 ( & V_58 -> V_65 ) ;
}
V_58 -> V_57 = V_62 -> V_57 ;
V_58 -> V_60 = 1 ;
V_16 = F_52 ( V_62 -> V_57 , V_2 , V_62 -> V_66 ,
V_58 ) ;
if ( V_16 < 0 )
F_12 ( V_58 ) ;
else
F_53 ( & V_58 -> V_65 , & V_2 -> V_67 ) ;
V_42:
F_33 ( & V_2 -> V_17 ) ;
if ( V_16 )
return F_16 ( V_16 ) ;
F_43 ( V_35 ) ;
return V_58 ;
}
void * F_54 ( struct V_40 * V_35 )
{
struct V_1 * V_2 = F_30 ( V_35 ) ;
if ( V_2 -> V_68 )
return V_2 -> V_68 ;
F_44 ( & V_2 -> V_17 ) ;
if ( ! V_2 -> V_68 )
V_2 -> V_68 = V_2 -> V_18 -> V_69 ( V_2 ) ;
F_33 ( & V_2 -> V_17 ) ;
return V_2 -> V_68 ;
}
static void * F_55 ( struct V_1 * V_35 )
{
struct V_13 * * V_15 ;
F_15 ( & V_35 -> V_17 ) ;
V_15 = F_14 ( V_35 ) ;
if ( F_7 ( V_15 ) )
return NULL ;
return V_69 ( V_15 , V_35 -> V_5 . V_21 >> V_22 ,
V_70 , F_23 ( V_71 ) ) ;
}
static inline enum V_72 F_56 ( T_4 V_73 )
{
if ( V_73 & V_74 )
return V_75 ;
else if ( V_73 & V_76 )
return V_77 ;
else
return V_12 ;
}
int F_57 ( struct V_40 * V_35 , T_4 V_73 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_30 ( V_35 ) ;
struct V_3 * V_4 = V_35 -> V_4 ;
bool V_80 = ! ! ( V_73 & V_76 ) ;
int V_16 ;
if ( ! V_2 -> V_7 ) {
void * V_16 ;
F_44 ( & V_2 -> V_17 ) ;
V_16 = F_14 ( V_2 ) ;
F_33 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_16 ) )
return F_9 ( V_16 ) ;
}
if ( V_73 & V_81 ) {
if ( ! F_58 ( V_2 -> V_82 ,
V_80 ) )
return - V_48 ;
} else {
unsigned long V_83 = F_59 ( V_79 ) ;
V_16 = F_60 ( V_2 -> V_82 ,
V_80 , true , V_83 ) ;
if ( V_16 <= 0 )
return V_16 == 0 ? - V_84 : V_16 ;
}
if ( V_2 -> V_8 & V_85 ) {
F_61 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_56 ( V_73 ) ) ;
V_2 -> V_86 = V_73 ;
}
return 0 ;
}
int F_62 ( struct V_40 * V_35 )
{
struct V_3 * V_4 = V_35 -> V_4 ;
struct V_1 * V_2 = F_30 ( V_35 ) ;
if ( V_2 -> V_8 & V_85 ) {
F_45 ( V_2 -> V_86 == 0 ) ;
F_63 ( V_4 -> V_4 , V_2 -> V_7 -> V_10 ,
V_2 -> V_7 -> V_11 ,
F_56 ( V_2 -> V_86 ) ) ;
V_2 -> V_86 = 0 ;
}
return 0 ;
}
int F_64 ( struct V_61 * V_62 , struct V_40 * V_35 ,
struct V_78 * V_79 )
{
struct V_1 * V_2 = F_30 ( V_35 ) ;
return F_65 ( V_62 , V_2 , V_79 ) ;
}
static void F_66 ( struct V_87 * V_88 ,
const char * type , struct V_89 * V_90 )
{
if ( ! F_67 ( V_91 , & V_88 -> V_8 ) )
F_68 ( V_90 , L_6 ,
type ,
V_88 -> V_18 -> V_92 ( V_88 ) ,
V_88 -> V_18 -> V_93 ( V_88 ) ,
V_88 -> V_94 ) ;
}
static void F_69 ( struct V_40 * V_35 , struct V_89 * V_90 )
{
struct V_1 * V_2 = F_30 ( V_35 ) ;
struct V_95 * V_96 = V_2 -> V_82 ;
struct V_97 * V_98 ;
struct V_87 * V_88 ;
unsigned long V_99 = F_70 ( & V_35 -> V_54 ) ;
F_68 ( V_90 , L_7 ,
V_2 -> V_8 , F_71 ( V_2 ) ? 'A' : 'I' ,
V_35 -> V_100 , F_72 ( & V_35 -> V_101 ) ,
V_99 , V_2 -> V_68 , V_35 -> V_21 ) ;
F_73 () ;
V_98 = F_74 ( V_96 -> V_88 ) ;
if ( V_98 ) {
unsigned int V_102 , V_103 = V_98 -> V_103 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
V_88 = F_74 ( V_98 -> V_104 [ V_102 ] ) ;
F_66 ( V_88 , L_8 , V_90 ) ;
}
}
V_88 = F_74 ( V_96 -> V_105 ) ;
if ( V_88 )
F_66 ( V_88 , L_9 , V_90 ) ;
F_75 () ;
}
void F_76 ( struct V_106 * V_107 ,
struct V_89 * V_90 )
{
struct V_1 * V_2 ;
int V_108 = 0 ;
T_5 V_21 = 0 ;
F_44 ( & V_107 -> V_109 ) ;
F_41 (etnaviv_obj, &priv->gem_list, gem_node) {
struct V_40 * V_35 = & V_2 -> V_5 ;
F_77 ( V_90 , L_10 ) ;
F_69 ( V_35 , V_90 ) ;
V_108 ++ ;
V_21 += V_35 -> V_21 ;
}
F_33 ( & V_107 -> V_109 ) ;
F_68 ( V_90 , L_11 , V_108 , V_21 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
F_79 ( V_2 -> V_68 ) ;
F_10 ( V_2 ) ;
}
void F_80 ( struct V_40 * V_35 )
{
struct V_1 * V_2 = F_30 ( V_35 ) ;
struct V_106 * V_107 = V_35 -> V_4 -> V_110 ;
struct V_55 * V_58 , * V_111 ;
F_45 ( F_71 ( V_2 ) ) ;
F_44 ( & V_107 -> V_109 ) ;
F_51 ( & V_2 -> V_112 ) ;
F_33 ( & V_107 -> V_109 ) ;
F_81 (mapping, tmp, &etnaviv_obj->vram_list,
obj_node) {
struct V_56 * V_57 = V_58 -> V_57 ;
F_45 ( V_58 -> V_60 ) ;
if ( V_57 )
F_82 ( V_57 , V_58 ) ;
F_51 ( & V_58 -> V_65 ) ;
F_12 ( V_58 ) ;
}
F_83 ( V_35 ) ;
V_2 -> V_18 -> V_113 ( V_2 ) ;
if ( V_2 -> V_82 == & V_2 -> V_114 )
F_84 ( & V_2 -> V_114 ) ;
F_85 ( V_35 ) ;
F_12 ( V_2 ) ;
}
int F_86 ( struct V_3 * V_4 , struct V_40 * V_35 )
{
struct V_106 * V_107 = V_4 -> V_110 ;
struct V_1 * V_2 = F_30 ( V_35 ) ;
F_44 ( & V_107 -> V_109 ) ;
F_53 ( & V_2 -> V_112 , & V_107 -> V_115 ) ;
F_33 ( & V_107 -> V_109 ) ;
return 0 ;
}
static int F_87 ( struct V_3 * V_4 , T_4 V_21 , T_4 V_8 ,
struct V_95 * V_96 , const struct V_116 * V_18 ,
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
F_18 ( V_4 -> V_4 , L_12 ,
( V_8 & V_9 ) ) ;
return - V_119 ;
}
V_2 = F_49 ( V_117 , V_63 ) ;
if ( ! V_2 )
return - V_50 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_18 = V_18 ;
if ( V_96 ) {
V_2 -> V_82 = V_96 ;
} else {
V_2 -> V_82 = & V_2 -> V_114 ;
F_88 ( & V_2 -> V_114 ) ;
}
F_89 ( & V_2 -> V_17 ) ;
F_50 ( & V_2 -> V_67 ) ;
* V_35 = & V_2 -> V_5 ;
return 0 ;
}
static struct V_40 * F_90 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_40 * V_35 = NULL ;
int V_16 ;
V_21 = F_91 ( V_21 ) ;
V_16 = F_87 ( V_4 , V_21 , V_8 , NULL ,
& V_120 , & V_35 ) ;
if ( V_16 )
goto V_121;
V_16 = F_92 ( V_4 , V_35 , V_21 ) ;
if ( V_16 == 0 ) {
struct V_122 * V_58 ;
V_58 = V_35 -> V_32 -> V_123 ;
F_93 ( V_58 , V_124 |
V_125 | V_126 ) ;
}
if ( V_16 )
goto V_121;
return V_35 ;
V_121:
F_47 ( V_35 ) ;
return F_16 ( V_16 ) ;
}
int F_94 ( struct V_3 * V_4 , struct V_127 * V_34 ,
T_4 V_21 , T_4 V_8 , T_4 * V_128 )
{
struct V_40 * V_35 ;
int V_16 ;
V_35 = F_90 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_35 ) )
return F_9 ( V_35 ) ;
V_16 = F_86 ( V_4 , V_35 ) ;
if ( V_16 < 0 ) {
F_47 ( V_35 ) ;
return V_16 ;
}
V_16 = F_95 ( V_34 , V_35 , V_128 ) ;
F_47 ( V_35 ) ;
return V_16 ;
}
struct V_40 * F_96 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_40 * V_35 ;
int V_16 ;
V_35 = F_90 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_35 ) )
return V_35 ;
V_16 = F_86 ( V_4 , V_35 ) ;
if ( V_16 < 0 ) {
F_47 ( V_35 ) ;
return F_16 ( V_16 ) ;
}
return V_35 ;
}
int F_97 ( struct V_3 * V_4 , T_5 V_21 , T_4 V_8 ,
struct V_95 * V_96 , const struct V_116 * V_18 ,
struct V_1 * * V_129 )
{
struct V_40 * V_35 ;
int V_16 ;
V_16 = F_87 ( V_4 , V_21 , V_8 , V_96 , V_18 , & V_35 ) ;
if ( V_16 )
return V_16 ;
F_98 ( V_4 , V_35 , V_21 ) ;
* V_129 = F_30 ( V_35 ) ;
return 0 ;
}
static struct V_13 * * F_99 (
struct V_1 * V_2 , struct V_130 * V_131 , struct V_132 * V_133 )
{
int V_16 = 0 , V_134 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
struct V_13 * * V_135 ;
T_6 V_136 ;
unsigned int V_8 = 0 ;
V_135 = F_100 ( V_20 , sizeof( struct V_13 * ) , V_63 ) ;
if ( ! V_135 )
return F_16 ( - V_50 ) ;
if ( ! V_2 -> V_137 . V_138 )
V_8 |= V_139 ;
V_134 = 0 ;
V_136 = V_2 -> V_137 . V_136 ;
F_101 ( & V_131 -> V_140 ) ;
while ( V_134 < V_20 ) {
V_16 = F_102 ( V_133 , V_131 , V_136 , V_20 - V_134 ,
V_8 , V_135 + V_134 , NULL , NULL ) ;
if ( V_16 < 0 )
break;
V_136 += V_16 * V_141 ;
V_134 += V_16 ;
}
F_103 ( & V_131 -> V_140 ) ;
if ( V_16 < 0 ) {
F_104 ( V_135 , V_134 , 0 ) ;
F_105 ( V_135 ) ;
return F_16 ( V_16 ) ;
}
return V_135 ;
}
static void F_106 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = F_107 ( V_143 , F_108 ( * V_145 ) , V_145 ) ;
struct V_1 * V_2 = V_145 -> V_2 ;
struct V_13 * * V_135 ;
V_135 = F_99 ( V_2 , V_145 -> V_131 , V_145 -> V_133 ) ;
F_44 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_135 ) ) {
V_2 -> V_137 . V_145 = F_19 ( V_135 ) ;
} else {
V_2 -> V_137 . V_145 = NULL ;
V_2 -> V_15 = V_135 ;
}
F_33 ( & V_2 -> V_17 ) ;
F_47 ( & V_2 -> V_5 ) ;
F_109 ( V_145 -> V_131 ) ;
F_110 ( V_145 -> V_133 ) ;
F_12 ( V_145 ) ;
}
static int F_111 ( struct V_1 * V_2 )
{
struct V_13 * * V_135 = NULL ;
struct V_144 * V_145 ;
struct V_130 * V_131 ;
int V_16 , V_134 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
if ( V_2 -> V_137 . V_145 ) {
if ( F_7 ( V_2 -> V_137 . V_145 ) ) {
V_16 = F_9 ( V_2 -> V_137 . V_145 ) ;
V_2 -> V_137 . V_145 = NULL ;
} else {
V_16 = - V_45 ;
}
return V_16 ;
}
V_131 = F_112 ( V_2 -> V_137 . V_133 ) ;
V_134 = 0 ;
if ( V_131 == V_146 -> V_131 ) {
V_135 = F_100 ( V_20 , sizeof( struct V_13 * ) , V_63 ) ;
if ( ! V_135 ) {
F_109 ( V_131 ) ;
return - V_50 ;
}
V_134 = F_113 ( V_2 -> V_137 . V_136 , V_20 ,
! V_2 -> V_137 . V_138 , V_135 ) ;
if ( V_134 < 0 ) {
F_105 ( V_135 ) ;
F_109 ( V_131 ) ;
return V_134 ;
}
if ( V_134 == V_20 ) {
V_2 -> V_15 = V_135 ;
F_109 ( V_131 ) ;
return 0 ;
}
}
F_104 ( V_135 , V_134 , 0 ) ;
F_105 ( V_135 ) ;
V_145 = F_114 ( sizeof( * V_145 ) , V_63 ) ;
if ( ! V_145 ) {
F_109 ( V_131 ) ;
return - V_50 ;
}
F_115 ( V_146 ) ;
F_43 ( & V_2 -> V_5 ) ;
V_145 -> V_131 = V_131 ;
V_145 -> V_133 = V_146 ;
V_145 -> V_2 = V_2 ;
V_2 -> V_137 . V_145 = & V_145 -> V_145 ;
F_116 ( & V_145 -> V_145 , F_106 ) ;
F_117 ( V_2 -> V_5 . V_4 , & V_145 -> V_145 ) ;
return - V_45 ;
}
static void F_118 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 ) {
F_3 ( V_2 ) ;
F_11 ( V_2 -> V_7 ) ;
F_12 ( V_2 -> V_7 ) ;
}
if ( V_2 -> V_15 ) {
int V_20 = V_2 -> V_5 . V_21 >> V_22 ;
F_104 ( V_2 -> V_15 , V_20 , 0 ) ;
F_105 ( V_2 -> V_15 ) ;
}
F_110 ( V_2 -> V_137 . V_133 ) ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
return - V_119 ;
}
int F_120 ( struct V_3 * V_4 , struct V_127 * V_34 ,
T_6 V_136 , T_4 V_21 , T_4 V_8 , T_4 * V_128 )
{
struct V_1 * V_2 ;
int V_16 ;
V_16 = F_97 ( V_4 , V_21 , V_85 , NULL ,
& V_147 , & V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_137 . V_136 = V_136 ;
V_2 -> V_137 . V_133 = V_146 ;
V_2 -> V_137 . V_138 = ! ( V_8 & V_148 ) ;
F_115 ( V_146 ) ;
V_16 = F_86 ( V_4 , & V_2 -> V_5 ) ;
if ( V_16 )
goto V_149;
V_16 = F_95 ( V_34 , & V_2 -> V_5 , V_128 ) ;
V_149:
F_47 ( & V_2 -> V_5 ) ;
return V_16 ;
}
