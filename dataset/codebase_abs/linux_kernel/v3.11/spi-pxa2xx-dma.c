static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 , V_6 , V_7 = V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
void * V_14 , * V_15 ;
V_7 = F_2 ( V_2 -> V_7 , 4 ) ;
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
V_6 = F_3 ( V_7 , V_26 ) ;
if ( V_6 != V_13 -> V_6 ) {
int V_27 ;
F_4 ( V_13 ) ;
V_27 = F_5 ( V_13 , V_6 , V_28 ) ;
if ( V_27 )
return V_27 ;
}
V_15 = V_14 ;
F_6 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_29 = F_7 ( T_1 , V_7 , V_26 ) ;
if ( V_14 )
F_8 ( V_9 , V_15 , V_29 ) ;
else
F_8 ( V_9 , V_2 -> V_30 , V_29 ) ;
V_15 += V_29 ;
V_7 -= V_29 ;
}
V_6 = F_9 ( V_11 , V_13 -> V_31 , V_13 -> V_6 , V_4 ) ;
if ( ! V_6 )
return - V_32 ;
return V_6 ;
}
static void F_10 ( struct V_1 * V_2 ,
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
F_11 ( V_11 , V_13 -> V_31 , V_13 -> V_6 , V_4 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_33 )
return;
F_10 ( V_2 , V_34 ) ;
F_10 ( V_2 , V_16 ) ;
V_2 -> V_33 = 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
bool error )
{
struct V_35 * V_36 = V_2 -> V_37 ;
if ( F_14 ( & V_2 -> V_38 ) ) {
void T_2 * V_39 = V_2 -> V_40 ;
if ( ! error ) {
T_3 V_41 = F_15 ( V_39 ) & V_2 -> V_42 ;
error = V_41 & V_43 ;
}
F_16 ( F_17 ( V_39 ) & ~ V_2 -> V_44 , V_39 ) ;
F_18 ( V_2 , V_2 -> V_45 ) ;
if ( ! F_19 ( V_2 ) )
F_20 ( 0 , V_39 ) ;
if ( ! error ) {
F_12 ( V_2 ) ;
V_2 -> V_20 += V_2 -> V_21 ;
V_2 -> V_46 ( V_2 ) ;
V_2 -> V_24 += V_2 -> V_25 ;
V_2 -> V_47 ( V_2 ) ;
V_36 -> V_48 += V_2 -> V_7 ;
V_36 -> V_49 = F_21 ( V_2 ) ;
} else {
F_22 ( F_23 ( V_39 ) & ~ V_50 , V_39 ) ;
V_36 -> V_49 = V_51 ;
}
F_24 ( & V_2 -> V_52 ) ;
}
}
static void F_25 ( void * V_53 )
{
F_13 ( V_53 , false ) ;
}
static struct V_54 *
F_26 ( struct V_1 * V_2 ,
enum V_55 V_4 )
{
struct V_56 * V_57 = V_2 -> V_58 ;
struct V_59 * V_60 = V_2 -> V_61 ;
enum V_62 V_63 ;
struct V_64 V_65 ;
struct V_66 * V_67 ;
struct V_12 * V_13 ;
int V_6 , V_27 ;
switch ( V_2 -> V_68 ) {
case 1 :
V_63 = V_69 ;
break;
case 2 :
V_63 = V_70 ;
break;
default:
V_63 = V_71 ;
break;
}
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
V_65 . V_72 = V_4 ;
if ( V_4 == V_73 ) {
V_65 . V_74 = V_2 -> V_75 ;
V_65 . V_76 = V_63 ;
V_65 . V_77 = V_60 -> V_78 ;
V_65 . V_79 = V_57 -> V_80 ;
V_13 = & V_2 -> V_19 ;
V_6 = V_2 -> V_81 ;
V_67 = V_2 -> V_17 ;
} else {
V_65 . V_82 = V_2 -> V_75 ;
V_65 . V_83 = V_63 ;
V_65 . V_84 = V_60 -> V_78 ;
V_65 . V_79 = V_57 -> V_85 ;
V_13 = & V_2 -> V_23 ;
V_6 = V_2 -> V_86 ;
V_67 = V_2 -> V_22 ;
}
V_27 = F_27 ( V_67 , & V_65 ) ;
if ( V_27 ) {
F_28 ( & V_2 -> V_87 -> V_18 , L_1 ) ;
return NULL ;
}
return F_29 ( V_67 , V_13 -> V_31 , V_6 , V_4 ,
V_88 | V_89 ) ;
}
static bool F_30 ( struct V_66 * V_67 , void * V_90 )
{
const struct V_56 * V_57 = V_90 ;
return V_67 -> V_91 == V_57 -> V_92 ||
V_67 -> V_91 == V_57 -> V_93 ;
}
bool F_31 ( T_1 V_7 )
{
return V_7 <= V_94 ;
}
int F_32 ( struct V_1 * V_2 )
{
const struct V_59 * V_60 = V_2 -> V_61 ;
int V_27 ;
if ( ! V_60 -> V_95 )
return 0 ;
if ( V_2 -> V_7 < V_60 -> V_78 )
return 0 ;
V_27 = F_1 ( V_2 , V_16 ) ;
if ( V_27 <= 0 ) {
F_28 ( & V_2 -> V_87 -> V_18 , L_2 ) ;
return 0 ;
}
V_2 -> V_81 = V_27 ;
V_27 = F_1 ( V_2 , V_34 ) ;
if ( V_27 <= 0 ) {
F_10 ( V_2 , V_16 ) ;
F_28 ( & V_2 -> V_87 -> V_18 , L_3 ) ;
return 0 ;
}
V_2 -> V_86 = V_27 ;
return 1 ;
}
T_4 F_33 ( struct V_1 * V_2 )
{
T_3 V_41 ;
V_41 = F_15 ( V_2 -> V_40 ) & V_2 -> V_42 ;
if ( V_41 & V_43 ) {
F_34 ( & V_2 -> V_87 -> V_18 , L_4 ) ;
F_35 ( V_2 -> V_22 ) ;
F_35 ( V_2 -> V_17 ) ;
F_13 ( V_2 , true ) ;
return V_96 ;
}
return V_97 ;
}
int F_36 ( struct V_1 * V_2 , T_3 V_98 )
{
struct V_54 * V_99 , * V_100 ;
V_99 = F_26 ( V_2 , V_73 ) ;
if ( ! V_99 ) {
F_34 ( & V_2 -> V_87 -> V_18 ,
L_5 ) ;
return - V_101 ;
}
V_100 = F_26 ( V_2 , V_102 ) ;
if ( ! V_100 ) {
F_34 ( & V_2 -> V_87 -> V_18 ,
L_6 ) ;
return - V_101 ;
}
V_100 -> V_103 = F_25 ;
V_100 -> V_104 = V_2 ;
F_37 ( V_100 ) ;
F_37 ( V_99 ) ;
return 0 ;
}
void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_22 ) ;
F_39 ( V_2 -> V_17 ) ;
F_40 ( & V_2 -> V_38 , 1 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_56 * V_57 = V_2 -> V_58 ;
struct V_10 * V_18 = & V_2 -> V_87 -> V_18 ;
T_5 V_105 ;
F_42 ( V_105 ) ;
F_43 ( V_106 , V_105 ) ;
V_2 -> V_30 = F_44 ( V_18 , V_26 , V_107 ) ;
if ( ! V_2 -> V_30 )
return - V_32 ;
V_2 -> V_17 = F_45 ( V_105 ,
F_30 , V_57 , V_18 , L_7 ) ;
if ( ! V_2 -> V_17 )
return - V_108 ;
V_2 -> V_22 = F_45 ( V_105 ,
F_30 , V_57 , V_18 , L_8 ) ;
if ( ! V_2 -> V_22 ) {
F_46 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return - V_108 ;
}
return 0 ;
}
void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
F_35 ( V_2 -> V_22 ) ;
F_46 ( V_2 -> V_22 ) ;
F_4 ( & V_2 -> V_23 ) ;
V_2 -> V_22 = NULL ;
}
if ( V_2 -> V_17 ) {
F_35 ( V_2 -> V_17 ) ;
F_46 ( V_2 -> V_17 ) ;
F_4 ( & V_2 -> V_19 ) ;
V_2 -> V_17 = NULL ;
}
}
void F_48 ( struct V_1 * V_2 )
{
}
int F_49 ( struct V_59 * V_60 ,
struct V_109 * V_110 ,
T_6 V_111 , T_3 * V_112 ,
T_3 * V_113 )
{
struct V_114 * V_115 = V_110 -> V_116 ;
* V_112 = V_115 ? V_115 -> V_78 : 16 ;
* V_113 = F_50 ( V_117 )
| F_51 ( V_118 ) ;
return 0 ;
}
