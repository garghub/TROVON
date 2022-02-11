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
V_35 -> V_101 , V_35 -> V_102 . V_102 . V_103 ,
V_100 , V_2 -> V_68 , V_35 -> V_21 ) ;
F_70 () ;
V_99 = F_71 ( V_97 -> V_89 ) ;
if ( V_99 ) {
unsigned int V_104 , V_105 = V_99 -> V_105 ;
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ ) {
V_89 = F_71 ( V_99 -> V_106 [ V_104 ] ) ;
F_64 ( V_89 , L_8 , V_91 ) ;
}
}
V_89 = F_71 ( V_97 -> V_107 ) ;
if ( V_89 )
F_64 ( V_89 , L_9 , V_91 ) ;
F_72 () ;
}
void F_73 ( struct V_108 * V_109 ,
struct V_90 * V_91 )
{
struct V_1 * V_2 ;
int V_110 = 0 ;
T_5 V_21 = 0 ;
F_43 ( & V_109 -> V_111 ) ;
F_40 (etnaviv_obj, &priv->gem_list, gem_node) {
struct V_40 * V_35 = & V_2 -> V_5 ;
F_74 ( V_91 , L_10 ) ;
F_67 ( V_35 , V_91 ) ;
V_110 ++ ;
V_21 += V_35 -> V_21 ;
}
F_32 ( & V_109 -> V_111 ) ;
F_66 ( V_91 , L_11 , V_110 , V_21 ) ;
}
static void F_75 ( struct V_1 * V_2 )
{
F_76 ( V_2 -> V_68 ) ;
F_10 ( V_2 ) ;
}
void F_77 ( struct V_40 * V_35 )
{
struct V_1 * V_2 = F_29 ( V_35 ) ;
struct V_55 * V_58 , * V_112 ;
F_44 ( F_69 ( V_2 ) ) ;
F_50 ( & V_2 -> V_113 ) ;
F_78 (mapping, tmp, &etnaviv_obj->vram_list,
obj_node) {
struct V_56 * V_57 = V_58 -> V_57 ;
F_44 ( V_58 -> V_60 ) ;
if ( V_57 )
F_79 ( V_57 , V_58 ) ;
F_50 ( & V_58 -> V_65 ) ;
F_12 ( V_58 ) ;
}
F_80 ( V_35 ) ;
V_2 -> V_18 -> V_114 ( V_2 ) ;
if ( V_2 -> V_84 == & V_2 -> V_115 )
F_81 ( & V_2 -> V_115 ) ;
F_82 ( V_35 ) ;
F_12 ( V_2 ) ;
}
int F_83 ( struct V_3 * V_4 , struct V_40 * V_35 )
{
struct V_108 * V_109 = V_4 -> V_116 ;
struct V_1 * V_2 = F_29 ( V_35 ) ;
F_43 ( & V_109 -> V_111 ) ;
F_52 ( & V_2 -> V_113 , & V_109 -> V_117 ) ;
F_32 ( & V_109 -> V_111 ) ;
return 0 ;
}
static int F_84 ( struct V_3 * V_4 , T_4 V_21 , T_4 V_8 ,
struct V_96 * V_97 , const struct V_118 * V_18 ,
struct V_40 * * V_35 )
{
struct V_1 * V_2 ;
unsigned V_119 = sizeof( * V_2 ) ;
bool V_120 = true ;
switch ( V_8 & V_9 ) {
case V_30 :
case V_86 :
case V_29 :
break;
default:
V_120 = false ;
}
if ( ! V_120 ) {
F_8 ( V_4 -> V_4 , L_12 ,
( V_8 & V_9 ) ) ;
return - V_121 ;
}
V_2 = F_48 ( V_119 , V_63 ) ;
if ( ! V_2 )
return - V_50 ;
V_2 -> V_8 = V_8 ;
V_2 -> V_18 = V_18 ;
if ( V_97 ) {
V_2 -> V_84 = V_97 ;
} else {
V_2 -> V_84 = & V_2 -> V_115 ;
F_85 ( & V_2 -> V_115 ) ;
}
F_86 ( & V_2 -> V_17 ) ;
F_49 ( & V_2 -> V_67 ) ;
* V_35 = & V_2 -> V_5 ;
return 0 ;
}
static struct V_40 * F_87 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_40 * V_35 = NULL ;
int V_16 ;
V_21 = F_88 ( V_21 ) ;
V_16 = F_84 ( V_4 , V_21 , V_8 , NULL ,
& V_122 , & V_35 ) ;
if ( V_16 )
goto V_123;
V_16 = F_89 ( V_4 , V_35 , V_21 ) ;
if ( V_16 == 0 ) {
struct V_124 * V_58 ;
V_58 = V_35 -> V_32 -> V_125 ;
F_90 ( V_58 , V_126 ) ;
}
if ( V_16 )
goto V_123;
return V_35 ;
V_123:
F_46 ( V_35 ) ;
return F_16 ( V_16 ) ;
}
int F_91 ( struct V_3 * V_4 , struct V_127 * V_34 ,
T_4 V_21 , T_4 V_8 , T_4 * V_128 )
{
struct V_40 * V_35 ;
int V_16 ;
V_35 = F_87 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_35 ) )
return F_9 ( V_35 ) ;
V_16 = F_83 ( V_4 , V_35 ) ;
if ( V_16 < 0 ) {
F_46 ( V_35 ) ;
return V_16 ;
}
V_16 = F_92 ( V_34 , V_35 , V_128 ) ;
F_46 ( V_35 ) ;
return V_16 ;
}
struct V_40 * F_93 ( struct V_3 * V_4 ,
T_4 V_21 , T_4 V_8 )
{
struct V_40 * V_35 ;
int V_16 ;
V_35 = F_87 ( V_4 , V_21 , V_8 ) ;
if ( F_7 ( V_35 ) )
return V_35 ;
V_16 = F_83 ( V_4 , V_35 ) ;
if ( V_16 < 0 ) {
F_46 ( V_35 ) ;
return F_16 ( V_16 ) ;
}
return V_35 ;
}
int F_94 ( struct V_3 * V_4 , T_5 V_21 , T_4 V_8 ,
struct V_96 * V_97 , const struct V_118 * V_18 ,
struct V_1 * * V_129 )
{
struct V_40 * V_35 ;
int V_16 ;
V_16 = F_84 ( V_4 , V_21 , V_8 , V_97 , V_18 , & V_35 ) ;
if ( V_16 )
return V_16 ;
F_95 ( V_4 , V_35 , V_21 ) ;
* V_129 = F_29 ( V_35 ) ;
return 0 ;
}
static struct V_13 * * F_96 (
struct V_1 * V_2 , struct V_130 * V_131 , struct V_132 * V_133 )
{
int V_16 = 0 , V_134 , V_20 = V_2 -> V_5 . V_21 >> V_22 ;
struct V_13 * * V_135 ;
T_6 V_136 ;
unsigned int V_8 = 0 ;
V_135 = F_97 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_135 )
return F_16 ( - V_50 ) ;
if ( ! V_2 -> V_137 . V_138 )
V_8 |= V_139 ;
V_134 = 0 ;
V_136 = V_2 -> V_137 . V_136 ;
F_98 ( & V_131 -> V_140 ) ;
while ( V_134 < V_20 ) {
V_16 = F_99 ( V_133 , V_131 , V_136 , V_20 - V_134 ,
V_8 , V_135 + V_134 , NULL , NULL ) ;
if ( V_16 < 0 )
break;
V_136 += V_16 * V_141 ;
V_134 += V_16 ;
}
F_100 ( & V_131 -> V_140 ) ;
if ( V_16 < 0 ) {
F_101 ( V_135 , V_134 , 0 ) ;
F_102 ( V_135 ) ;
return F_16 ( V_16 ) ;
}
return V_135 ;
}
static void F_103 ( struct V_142 * V_143 )
{
struct V_144 * V_145 = F_104 ( V_143 , F_105 ( * V_145 ) , V_145 ) ;
struct V_1 * V_2 = V_145 -> V_2 ;
struct V_13 * * V_135 ;
V_135 = F_96 ( V_2 , V_145 -> V_131 , V_145 -> V_133 ) ;
F_43 ( & V_2 -> V_17 ) ;
if ( F_7 ( V_135 ) ) {
V_2 -> V_137 . V_145 = F_18 ( V_135 ) ;
} else {
V_2 -> V_137 . V_145 = NULL ;
V_2 -> V_15 = V_135 ;
}
F_32 ( & V_2 -> V_17 ) ;
F_46 ( & V_2 -> V_5 ) ;
F_106 ( V_145 -> V_131 ) ;
F_107 ( V_145 -> V_133 ) ;
F_12 ( V_145 ) ;
}
static int F_108 ( struct V_1 * V_2 )
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
V_131 = F_109 ( V_2 -> V_137 . V_133 ) ;
V_134 = 0 ;
if ( V_131 == V_146 -> V_131 ) {
V_135 = F_97 ( V_20 , sizeof( struct V_13 * ) ) ;
if ( ! V_135 ) {
F_106 ( V_131 ) ;
return - V_50 ;
}
V_134 = F_110 ( V_2 -> V_137 . V_136 , V_20 ,
! V_2 -> V_137 . V_138 , V_135 ) ;
if ( V_134 < 0 ) {
F_102 ( V_135 ) ;
F_106 ( V_131 ) ;
return V_134 ;
}
if ( V_134 == V_20 ) {
V_2 -> V_15 = V_135 ;
F_106 ( V_131 ) ;
return 0 ;
}
}
F_101 ( V_135 , V_134 , 0 ) ;
F_102 ( V_135 ) ;
V_145 = F_111 ( sizeof( * V_145 ) , V_63 ) ;
if ( ! V_145 ) {
F_106 ( V_131 ) ;
return - V_50 ;
}
F_112 ( V_146 ) ;
F_42 ( & V_2 -> V_5 ) ;
V_145 -> V_131 = V_131 ;
V_145 -> V_133 = V_146 ;
V_145 -> V_2 = V_2 ;
V_2 -> V_137 . V_145 = & V_145 -> V_145 ;
F_113 ( & V_145 -> V_145 , F_103 ) ;
F_114 ( V_2 -> V_5 . V_4 , & V_145 -> V_145 ) ;
return - V_45 ;
}
static void F_115 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 ) {
F_3 ( V_2 ) ;
F_11 ( V_2 -> V_7 ) ;
F_12 ( V_2 -> V_7 ) ;
}
if ( V_2 -> V_15 ) {
int V_20 = V_2 -> V_5 . V_21 >> V_22 ;
F_101 ( V_2 -> V_15 , V_20 , 0 ) ;
F_102 ( V_2 -> V_15 ) ;
}
F_107 ( V_2 -> V_137 . V_133 ) ;
}
static int F_116 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
return - V_121 ;
}
int F_117 ( struct V_3 * V_4 , struct V_127 * V_34 ,
T_6 V_136 , T_4 V_21 , T_4 V_8 , T_4 * V_128 )
{
struct V_1 * V_2 ;
int V_16 ;
V_16 = F_94 ( V_4 , V_21 , V_86 , NULL ,
& V_147 , & V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_137 . V_136 = V_136 ;
V_2 -> V_137 . V_133 = V_146 ;
V_2 -> V_137 . V_138 = ! ( V_8 & V_148 ) ;
F_112 ( V_146 ) ;
V_16 = F_83 ( V_4 , & V_2 -> V_5 ) ;
if ( V_16 )
goto V_149;
V_16 = F_92 ( V_34 , & V_2 -> V_5 , V_128 ) ;
V_149:
F_46 ( & V_2 -> V_5 ) ;
return V_16 ;
}
