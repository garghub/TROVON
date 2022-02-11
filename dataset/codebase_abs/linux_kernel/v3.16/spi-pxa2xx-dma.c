static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 , V_6 , V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
void * V_14 , * V_15 ;
if ( V_4 == V_16 ) {
V_11 = V_2 -> V_17 -> V_10 -> V_18 ;
V_13 = & V_2 -> V_19 ;
V_14 = V_2 -> V_20 ;
V_2 -> V_21 = V_7 ;
} else {
V_11 = V_2 -> V_22 -> V_10 -> V_18 ;
V_13 = & V_2 -> V_23 ;
V_14 = V_2 -> V_24 ;
V_2 -> V_25 = V_7 ;
}
V_6 = F_2 ( V_7 , V_26 ) ;
if ( V_6 != V_13 -> V_6 ) {
int V_27 ;
F_3 ( V_13 ) ;
V_27 = F_4 ( V_13 , V_6 , V_28 ) ;
if ( V_27 )
return V_27 ;
}
V_15 = V_14 ;
F_5 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_29 = F_6 ( T_1 , V_7 , V_26 ) ;
if ( V_14 )
F_7 ( V_9 , V_15 , V_29 ) ;
else
F_7 ( V_9 , V_2 -> V_30 , V_29 ) ;
V_15 += V_29 ;
V_7 -= V_29 ;
}
V_6 = F_8 ( V_11 , V_13 -> V_31 , V_13 -> V_6 , V_4 ) ;
if ( ! V_6 )
return - V_32 ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
if ( V_4 == V_16 ) {
V_11 = V_2 -> V_17 -> V_10 -> V_18 ;
V_13 = & V_2 -> V_19 ;
} else {
V_11 = V_2 -> V_22 -> V_10 -> V_18 ;
V_13 = & V_2 -> V_23 ;
}
F_10 ( V_11 , V_13 -> V_31 , V_13 -> V_6 , V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_33 )
return;
F_9 ( V_2 , V_34 ) ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_33 = 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
bool error )
{
struct V_35 * V_36 = V_2 -> V_37 ;
if ( F_13 ( & V_2 -> V_38 ) ) {
void T_2 * V_39 = V_2 -> V_40 ;
if ( ! error ) {
T_3 V_41 = F_14 ( V_39 ) & V_2 -> V_42 ;
error = V_41 & V_43 ;
}
F_15 ( F_16 ( V_39 ) & ~ V_2 -> V_44 , V_39 ) ;
F_17 ( V_2 , V_2 -> V_45 ) ;
if ( ! F_18 ( V_2 ) )
F_19 ( 0 , V_39 ) ;
if ( ! error ) {
F_11 ( V_2 ) ;
V_2 -> V_20 += V_2 -> V_21 ;
V_2 -> V_24 += V_2 -> V_25 ;
V_36 -> V_46 += V_2 -> V_7 ;
V_36 -> V_47 = F_20 ( V_2 ) ;
} else {
F_21 ( F_22 ( V_39 ) & ~ V_48 , V_39 ) ;
V_36 -> V_47 = V_49 ;
}
F_23 ( & V_2 -> V_50 ) ;
}
}
static void F_24 ( void * V_51 )
{
F_12 ( V_51 , false ) ;
}
static struct V_52 *
F_25 ( struct V_1 * V_2 ,
enum V_53 V_4 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
struct V_57 * V_58 = V_2 -> V_59 ;
enum V_60 V_61 ;
struct V_62 V_63 ;
struct V_64 * V_65 ;
struct V_12 * V_13 ;
int V_6 , V_27 ;
switch ( V_2 -> V_66 ) {
case 1 :
V_61 = V_67 ;
break;
case 2 :
V_61 = V_68 ;
break;
default:
V_61 = V_69 ;
break;
}
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_70 = V_4 ;
if ( V_4 == V_71 ) {
V_63 . V_72 = V_2 -> V_73 ;
V_63 . V_74 = V_61 ;
V_63 . V_75 = V_58 -> V_76 ;
V_63 . V_77 = V_55 -> V_78 ;
V_13 = & V_2 -> V_19 ;
V_6 = V_2 -> V_79 ;
V_65 = V_2 -> V_17 ;
} else {
V_63 . V_80 = V_2 -> V_73 ;
V_63 . V_81 = V_61 ;
V_63 . V_82 = V_58 -> V_76 ;
V_63 . V_77 = V_55 -> V_83 ;
V_13 = & V_2 -> V_23 ;
V_6 = V_2 -> V_84 ;
V_65 = V_2 -> V_22 ;
}
V_27 = F_26 ( V_65 , & V_63 ) ;
if ( V_27 ) {
F_27 ( & V_2 -> V_85 -> V_18 , L_1 ) ;
return NULL ;
}
return F_28 ( V_65 , V_13 -> V_31 , V_6 , V_4 ,
V_86 | V_87 ) ;
}
static bool F_29 ( struct V_64 * V_65 , void * V_88 )
{
const struct V_54 * V_55 = V_88 ;
return V_65 -> V_89 == V_55 -> V_90 ||
V_65 -> V_89 == V_55 -> V_91 ;
}
bool F_30 ( T_1 V_7 )
{
return V_7 <= V_92 ;
}
int F_31 ( struct V_1 * V_2 )
{
const struct V_57 * V_58 = V_2 -> V_59 ;
int V_27 ;
if ( ! V_58 -> V_93 )
return 0 ;
if ( V_2 -> V_7 < V_58 -> V_76 )
return 0 ;
V_27 = F_1 ( V_2 , V_16 ) ;
if ( V_27 <= 0 ) {
F_27 ( & V_2 -> V_85 -> V_18 , L_2 ) ;
return 0 ;
}
V_2 -> V_79 = V_27 ;
V_27 = F_1 ( V_2 , V_34 ) ;
if ( V_27 <= 0 ) {
F_9 ( V_2 , V_16 ) ;
F_27 ( & V_2 -> V_85 -> V_18 , L_3 ) ;
return 0 ;
}
V_2 -> V_84 = V_27 ;
return 1 ;
}
T_4 F_32 ( struct V_1 * V_2 )
{
T_3 V_41 ;
V_41 = F_14 ( V_2 -> V_40 ) & V_2 -> V_42 ;
if ( V_41 & V_43 ) {
F_33 ( & V_2 -> V_85 -> V_18 , L_4 ) ;
F_34 ( V_2 -> V_22 ) ;
F_34 ( V_2 -> V_17 ) ;
F_12 ( V_2 , true ) ;
return V_94 ;
}
return V_95 ;
}
int F_35 ( struct V_1 * V_2 , T_3 V_96 )
{
struct V_52 * V_97 , * V_98 ;
V_97 = F_25 ( V_2 , V_71 ) ;
if ( ! V_97 ) {
F_33 ( & V_2 -> V_85 -> V_18 ,
L_5 ) ;
return - V_99 ;
}
V_98 = F_25 ( V_2 , V_100 ) ;
if ( ! V_98 ) {
F_33 ( & V_2 -> V_85 -> V_18 ,
L_6 ) ;
return - V_99 ;
}
V_98 -> V_101 = F_24 ;
V_98 -> V_102 = V_2 ;
F_36 ( V_98 ) ;
F_36 ( V_97 ) ;
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_38 ( V_2 -> V_22 ) ;
F_38 ( V_2 -> V_17 ) ;
F_39 ( & V_2 -> V_38 , 1 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = V_2 -> V_56 ;
struct V_10 * V_18 = & V_2 -> V_85 -> V_18 ;
T_5 V_103 ;
F_41 ( V_103 ) ;
F_42 ( V_104 , V_103 ) ;
V_2 -> V_30 = F_43 ( V_18 , V_26 , V_105 ) ;
if ( ! V_2 -> V_30 )
return - V_32 ;
V_2 -> V_17 = F_44 ( V_103 ,
F_29 , V_55 , V_18 , L_7 ) ;
if ( ! V_2 -> V_17 )
return - V_106 ;
V_2 -> V_22 = F_44 ( V_103 ,
F_29 , V_55 , V_18 , L_8 ) ;
if ( ! V_2 -> V_22 ) {
F_45 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return - V_106 ;
}
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
F_34 ( V_2 -> V_22 ) ;
F_45 ( V_2 -> V_22 ) ;
F_3 ( & V_2 -> V_23 ) ;
V_2 -> V_22 = NULL ;
}
if ( V_2 -> V_17 ) {
F_34 ( V_2 -> V_17 ) ;
F_45 ( V_2 -> V_17 ) ;
F_3 ( & V_2 -> V_19 ) ;
V_2 -> V_17 = NULL ;
}
}
void F_47 ( struct V_1 * V_2 )
{
}
int F_48 ( struct V_57 * V_58 ,
struct V_107 * V_108 ,
T_6 V_109 , T_3 * V_110 ,
T_3 * V_111 )
{
struct V_112 * V_113 = V_108 -> V_114 ;
* V_110 = V_113 ? V_113 -> V_76 : 1 ;
* V_111 = F_49 ( V_115 )
| F_50 ( V_116 ) ;
return 0 ;
}
