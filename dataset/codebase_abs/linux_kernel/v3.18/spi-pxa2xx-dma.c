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
enum V_57 V_58 ;
struct V_59 V_60 ;
struct V_61 * V_62 ;
struct V_12 * V_13 ;
int V_6 , V_27 ;
switch ( V_2 -> V_63 ) {
case 1 :
V_58 = V_64 ;
break;
case 2 :
V_58 = V_65 ;
break;
default:
V_58 = V_66 ;
break;
}
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_67 = V_4 ;
if ( V_4 == V_68 ) {
V_60 . V_69 = V_2 -> V_70 ;
V_60 . V_71 = V_58 ;
V_60 . V_72 = V_55 -> V_73 ;
V_13 = & V_2 -> V_19 ;
V_6 = V_2 -> V_74 ;
V_62 = V_2 -> V_17 ;
} else {
V_60 . V_75 = V_2 -> V_70 ;
V_60 . V_76 = V_58 ;
V_60 . V_77 = V_55 -> V_73 ;
V_13 = & V_2 -> V_23 ;
V_6 = V_2 -> V_78 ;
V_62 = V_2 -> V_22 ;
}
V_27 = F_26 ( V_62 , & V_60 ) ;
if ( V_27 ) {
F_27 ( & V_2 -> V_79 -> V_18 , L_1 ) ;
return NULL ;
}
return F_28 ( V_62 , V_13 -> V_31 , V_6 , V_4 ,
V_80 | V_81 ) ;
}
bool F_29 ( T_1 V_7 )
{
return V_7 <= V_82 ;
}
int F_30 ( struct V_1 * V_2 )
{
const struct V_54 * V_55 = V_2 -> V_56 ;
int V_27 ;
if ( ! V_55 -> V_83 )
return 0 ;
if ( V_2 -> V_7 < V_55 -> V_73 )
return 0 ;
V_27 = F_1 ( V_2 , V_16 ) ;
if ( V_27 <= 0 ) {
F_27 ( & V_2 -> V_79 -> V_18 , L_2 ) ;
return 0 ;
}
V_2 -> V_74 = V_27 ;
V_27 = F_1 ( V_2 , V_34 ) ;
if ( V_27 <= 0 ) {
F_9 ( V_2 , V_16 ) ;
F_27 ( & V_2 -> V_79 -> V_18 , L_3 ) ;
return 0 ;
}
V_2 -> V_78 = V_27 ;
return 1 ;
}
T_4 F_31 ( struct V_1 * V_2 )
{
T_3 V_41 ;
V_41 = F_14 ( V_2 -> V_40 ) & V_2 -> V_42 ;
if ( V_41 & V_43 ) {
F_32 ( & V_2 -> V_79 -> V_18 , L_4 ) ;
F_33 ( V_2 -> V_22 ) ;
F_33 ( V_2 -> V_17 ) ;
F_12 ( V_2 , true ) ;
return V_84 ;
}
return V_85 ;
}
int F_34 ( struct V_1 * V_2 , T_3 V_86 )
{
struct V_52 * V_87 , * V_88 ;
V_87 = F_25 ( V_2 , V_68 ) ;
if ( ! V_87 ) {
F_32 ( & V_2 -> V_79 -> V_18 ,
L_5 ) ;
return - V_89 ;
}
V_88 = F_25 ( V_2 , V_90 ) ;
if ( ! V_88 ) {
F_32 ( & V_2 -> V_79 -> V_18 ,
L_6 ) ;
return - V_89 ;
}
V_88 -> V_91 = F_24 ;
V_88 -> V_92 = V_2 ;
F_35 ( V_88 ) ;
F_35 ( V_87 ) ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
F_37 ( V_2 -> V_22 ) ;
F_37 ( V_2 -> V_17 ) ;
F_38 ( & V_2 -> V_38 , 1 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_93 * V_94 = V_2 -> V_95 ;
struct V_10 * V_18 = & V_2 -> V_79 -> V_18 ;
T_5 V_96 ;
F_40 ( V_96 ) ;
F_41 ( V_97 , V_96 ) ;
V_2 -> V_30 = F_42 ( V_18 , V_26 , V_98 ) ;
if ( ! V_2 -> V_30 )
return - V_32 ;
V_2 -> V_17 = F_43 ( V_96 ,
V_94 -> V_99 , V_94 -> V_100 , V_18 , L_7 ) ;
if ( ! V_2 -> V_17 )
return - V_101 ;
V_2 -> V_22 = F_43 ( V_96 ,
V_94 -> V_99 , V_94 -> V_102 , V_18 , L_8 ) ;
if ( ! V_2 -> V_22 ) {
F_44 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return - V_101 ;
}
return 0 ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
F_33 ( V_2 -> V_22 ) ;
F_44 ( V_2 -> V_22 ) ;
F_3 ( & V_2 -> V_23 ) ;
V_2 -> V_22 = NULL ;
}
if ( V_2 -> V_17 ) {
F_33 ( V_2 -> V_17 ) ;
F_44 ( V_2 -> V_17 ) ;
F_3 ( & V_2 -> V_19 ) ;
V_2 -> V_17 = NULL ;
}
}
void F_46 ( struct V_1 * V_2 )
{
}
int F_47 ( struct V_54 * V_55 ,
struct V_103 * V_104 ,
T_6 V_105 , T_3 * V_106 ,
T_3 * V_107 )
{
struct V_108 * V_109 = V_104 -> V_110 ;
* V_106 = V_109 ? V_109 -> V_73 : 1 ;
* V_107 = F_48 ( V_111 )
| F_49 ( V_112 ) ;
return 0 ;
}
