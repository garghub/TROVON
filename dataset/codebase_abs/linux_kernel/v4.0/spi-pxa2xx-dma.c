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
if ( ! error ) {
T_2 V_39 = F_14 ( V_2 , V_40 )
& V_2 -> V_41 ;
error = V_39 & V_42 ;
}
F_15 ( V_2 , V_43 ,
F_14 ( V_2 , V_43 )
& ~ V_2 -> V_44 ) ;
F_16 ( V_2 , V_2 -> V_45 ) ;
if ( ! F_17 ( V_2 ) )
F_15 ( V_2 , V_46 , 0 ) ;
if ( ! error ) {
F_11 ( V_2 ) ;
V_2 -> V_20 += V_2 -> V_21 ;
V_2 -> V_24 += V_2 -> V_25 ;
V_36 -> V_47 += V_2 -> V_7 ;
V_36 -> V_48 = F_18 ( V_2 ) ;
} else {
F_15 ( V_2 , V_49 ,
F_14 ( V_2 , V_49 )
& ~ V_50 ) ;
V_36 -> V_48 = V_51 ;
}
F_19 ( & V_2 -> V_52 ) ;
}
}
static void F_20 ( void * V_53 )
{
F_12 ( V_53 , false ) ;
}
static struct V_54 *
F_21 ( struct V_1 * V_2 ,
enum V_55 V_4 )
{
struct V_56 * V_57 = V_2 -> V_58 ;
enum V_59 V_60 ;
struct V_61 V_62 ;
struct V_63 * V_64 ;
struct V_12 * V_13 ;
int V_6 , V_27 ;
switch ( V_2 -> V_65 ) {
case 1 :
V_60 = V_66 ;
break;
case 2 :
V_60 = V_67 ;
break;
default:
V_60 = V_68 ;
break;
}
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_69 = V_4 ;
if ( V_4 == V_70 ) {
V_62 . V_71 = V_2 -> V_72 ;
V_62 . V_73 = V_60 ;
V_62 . V_74 = V_57 -> V_75 ;
V_13 = & V_2 -> V_19 ;
V_6 = V_2 -> V_76 ;
V_64 = V_2 -> V_17 ;
} else {
V_62 . V_77 = V_2 -> V_72 ;
V_62 . V_78 = V_60 ;
V_62 . V_79 = V_57 -> V_75 ;
V_13 = & V_2 -> V_23 ;
V_6 = V_2 -> V_80 ;
V_64 = V_2 -> V_22 ;
}
V_27 = F_22 ( V_64 , & V_62 ) ;
if ( V_27 ) {
F_23 ( & V_2 -> V_81 -> V_18 , L_1 ) ;
return NULL ;
}
return F_24 ( V_64 , V_13 -> V_31 , V_6 , V_4 ,
V_82 | V_83 ) ;
}
bool F_25 ( T_1 V_7 )
{
return V_7 <= V_84 ;
}
int F_26 ( struct V_1 * V_2 )
{
const struct V_56 * V_57 = V_2 -> V_58 ;
int V_27 ;
if ( ! V_57 -> V_85 )
return 0 ;
if ( V_2 -> V_7 < V_57 -> V_75 )
return 0 ;
V_27 = F_1 ( V_2 , V_16 ) ;
if ( V_27 <= 0 ) {
F_23 ( & V_2 -> V_81 -> V_18 , L_2 ) ;
return 0 ;
}
V_2 -> V_76 = V_27 ;
V_27 = F_1 ( V_2 , V_34 ) ;
if ( V_27 <= 0 ) {
F_9 ( V_2 , V_16 ) ;
F_23 ( & V_2 -> V_81 -> V_18 , L_3 ) ;
return 0 ;
}
V_2 -> V_80 = V_27 ;
return 1 ;
}
T_3 F_27 ( struct V_1 * V_2 )
{
T_2 V_39 ;
V_39 = F_14 ( V_2 , V_40 ) & V_2 -> V_41 ;
if ( V_39 & V_42 ) {
F_28 ( & V_2 -> V_81 -> V_18 , L_4 ) ;
F_29 ( V_2 -> V_22 ) ;
F_29 ( V_2 -> V_17 ) ;
F_12 ( V_2 , true ) ;
return V_86 ;
}
return V_87 ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_88 )
{
struct V_54 * V_89 , * V_90 ;
V_89 = F_21 ( V_2 , V_70 ) ;
if ( ! V_89 ) {
F_28 ( & V_2 -> V_81 -> V_18 ,
L_5 ) ;
return - V_91 ;
}
V_90 = F_21 ( V_2 , V_92 ) ;
if ( ! V_90 ) {
F_28 ( & V_2 -> V_81 -> V_18 ,
L_6 ) ;
return - V_91 ;
}
V_90 -> V_93 = F_20 ;
V_90 -> V_94 = V_2 ;
F_31 ( V_90 ) ;
F_31 ( V_89 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_22 ) ;
F_33 ( V_2 -> V_17 ) ;
F_34 ( & V_2 -> V_38 , 1 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_95 * V_96 = V_2 -> V_97 ;
struct V_10 * V_18 = & V_2 -> V_81 -> V_18 ;
T_4 V_98 ;
F_36 ( V_98 ) ;
F_37 ( V_99 , V_98 ) ;
V_2 -> V_30 = F_38 ( V_18 , V_26 , V_100 ) ;
if ( ! V_2 -> V_30 )
return - V_32 ;
V_2 -> V_17 = F_39 ( V_98 ,
V_96 -> V_101 , V_96 -> V_102 , V_18 , L_7 ) ;
if ( ! V_2 -> V_17 )
return - V_103 ;
V_2 -> V_22 = F_39 ( V_98 ,
V_96 -> V_101 , V_96 -> V_104 , V_18 , L_8 ) ;
if ( ! V_2 -> V_22 ) {
F_40 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return - V_103 ;
}
return 0 ;
}
void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
F_29 ( V_2 -> V_22 ) ;
F_40 ( V_2 -> V_22 ) ;
F_3 ( & V_2 -> V_23 ) ;
V_2 -> V_22 = NULL ;
}
if ( V_2 -> V_17 ) {
F_29 ( V_2 -> V_17 ) ;
F_40 ( V_2 -> V_17 ) ;
F_3 ( & V_2 -> V_19 ) ;
V_2 -> V_17 = NULL ;
}
}
void F_42 ( struct V_1 * V_2 )
{
}
int F_43 ( struct V_56 * V_57 ,
struct V_105 * V_106 ,
T_5 V_107 , T_2 * V_108 ,
T_2 * V_109 )
{
struct V_110 * V_111 = V_106 -> V_112 ;
* V_108 = V_111 ? V_111 -> V_75 : 1 ;
* V_109 = F_44 ( V_113 )
| F_45 ( V_114 ) ;
return 0 ;
}
