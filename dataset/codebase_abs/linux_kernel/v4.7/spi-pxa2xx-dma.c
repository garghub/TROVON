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
} else {
V_11 = V_2 -> V_21 -> V_10 -> V_18 ;
V_13 = & V_2 -> V_22 ;
V_14 = V_2 -> V_23 ;
}
V_6 = F_2 ( V_7 , V_24 ) ;
if ( V_6 != V_13 -> V_6 ) {
int V_25 ;
F_3 ( V_13 ) ;
V_25 = F_4 ( V_13 , V_6 , V_26 ) ;
if ( V_25 )
return V_25 ;
}
V_15 = V_14 ;
F_5 (sgt->sgl, sg, sgt->nents, i) {
T_1 V_27 = F_6 ( T_1 , V_7 , V_24 ) ;
F_7 ( V_9 , V_15 , V_27 ) ;
V_15 += V_27 ;
V_7 -= V_27 ;
}
V_6 = F_8 ( V_11 , V_13 -> V_28 , V_13 -> V_6 , V_4 ) ;
if ( ! V_6 )
return - V_29 ;
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
V_11 = V_2 -> V_21 -> V_10 -> V_18 ;
V_13 = & V_2 -> V_22 ;
}
F_10 ( V_11 , V_13 -> V_28 , V_13 -> V_6 , V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_30 )
return;
F_9 ( V_2 , V_31 ) ;
F_9 ( V_2 , V_16 ) ;
V_2 -> V_30 = 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
bool error )
{
struct V_32 * V_33 = V_2 -> V_34 ;
if ( F_13 ( & V_2 -> V_35 ) ) {
if ( ! error ) {
T_2 V_36 = F_14 ( V_2 , V_37 )
& V_2 -> V_38 ;
error = V_36 & V_39 ;
}
F_15 ( V_2 , V_40 ,
F_14 ( V_2 , V_40 )
& ~ V_2 -> V_41 ) ;
F_16 ( V_2 , V_2 -> V_42 ) ;
if ( ! F_17 ( V_2 ) )
F_15 ( V_2 , V_43 , 0 ) ;
if ( ! error ) {
F_11 ( V_2 ) ;
V_33 -> V_44 += V_2 -> V_7 ;
V_33 -> V_45 = F_18 ( V_2 ) ;
} else {
F_15 ( V_2 , V_46 ,
F_14 ( V_2 , V_46 )
& ~ V_47 ) ;
V_33 -> V_45 = V_48 ;
}
F_19 ( & V_2 -> V_49 ) ;
}
}
static void F_20 ( void * V_50 )
{
F_12 ( V_50 , false ) ;
}
static struct V_51 *
F_21 ( struct V_1 * V_2 ,
enum V_52 V_4 )
{
struct V_53 * V_54 = V_2 -> V_55 ;
enum V_56 V_57 ;
struct V_58 V_59 ;
struct V_60 * V_61 ;
struct V_12 * V_13 ;
int V_6 , V_25 ;
switch ( V_2 -> V_62 ) {
case 1 :
V_57 = V_63 ;
break;
case 2 :
V_57 = V_64 ;
break;
default:
V_57 = V_65 ;
break;
}
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
V_59 . V_66 = V_4 ;
if ( V_4 == V_67 ) {
V_59 . V_68 = V_2 -> V_69 ;
V_59 . V_70 = V_57 ;
V_59 . V_71 = V_54 -> V_72 ;
V_13 = & V_2 -> V_19 ;
V_6 = V_2 -> V_73 ;
V_61 = V_2 -> V_17 ;
} else {
V_59 . V_74 = V_2 -> V_69 ;
V_59 . V_75 = V_57 ;
V_59 . V_76 = V_54 -> V_72 ;
V_13 = & V_2 -> V_22 ;
V_6 = V_2 -> V_77 ;
V_61 = V_2 -> V_21 ;
}
V_25 = F_22 ( V_61 , & V_59 ) ;
if ( V_25 ) {
F_23 ( & V_2 -> V_78 -> V_18 , L_1 ) ;
return NULL ;
}
return F_24 ( V_61 , V_13 -> V_28 , V_6 , V_4 ,
V_79 | V_80 ) ;
}
bool F_25 ( T_1 V_7 )
{
return V_7 <= V_81 ;
}
int F_26 ( struct V_1 * V_2 )
{
const struct V_53 * V_54 = V_2 -> V_55 ;
int V_25 ;
if ( ! V_54 -> V_82 )
return 0 ;
if ( V_2 -> V_7 < V_54 -> V_72 )
return 0 ;
V_25 = F_1 ( V_2 , V_16 ) ;
if ( V_25 <= 0 ) {
F_23 ( & V_2 -> V_78 -> V_18 , L_2 ) ;
return 0 ;
}
V_2 -> V_73 = V_25 ;
V_25 = F_1 ( V_2 , V_31 ) ;
if ( V_25 <= 0 ) {
F_9 ( V_2 , V_16 ) ;
F_23 ( & V_2 -> V_78 -> V_18 , L_3 ) ;
return 0 ;
}
V_2 -> V_77 = V_25 ;
return 1 ;
}
T_3 F_27 ( struct V_1 * V_2 )
{
T_2 V_36 ;
V_36 = F_14 ( V_2 , V_37 ) & V_2 -> V_38 ;
if ( V_36 & V_39 ) {
F_28 ( & V_2 -> V_78 -> V_18 , L_4 ) ;
F_29 ( V_2 -> V_21 ) ;
F_29 ( V_2 -> V_17 ) ;
F_12 ( V_2 , true ) ;
return V_83 ;
}
return V_84 ;
}
int F_30 ( struct V_1 * V_2 , T_2 V_85 )
{
struct V_51 * V_86 , * V_87 ;
int V_88 = 0 ;
V_86 = F_21 ( V_2 , V_67 ) ;
if ( ! V_86 ) {
F_28 ( & V_2 -> V_78 -> V_18 ,
L_5 ) ;
V_88 = - V_89 ;
goto V_90;
}
V_87 = F_21 ( V_2 , V_91 ) ;
if ( ! V_87 ) {
F_28 ( & V_2 -> V_78 -> V_18 ,
L_6 ) ;
V_88 = - V_89 ;
goto V_92;
}
V_87 -> V_93 = F_20 ;
V_87 -> V_94 = V_2 ;
F_31 ( V_87 ) ;
F_31 ( V_86 ) ;
return 0 ;
V_92:
F_29 ( V_2 -> V_17 ) ;
V_90:
F_11 ( V_2 ) ;
return V_88 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_33 ( V_2 -> V_21 ) ;
F_33 ( V_2 -> V_17 ) ;
F_34 ( & V_2 -> V_35 , 1 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_95 * V_96 = V_2 -> V_97 ;
struct V_10 * V_18 = & V_2 -> V_78 -> V_18 ;
T_4 V_98 ;
F_36 ( V_98 ) ;
F_37 ( V_99 , V_98 ) ;
V_2 -> V_17 = F_38 ( V_98 ,
V_96 -> V_100 , V_96 -> V_101 , V_18 , L_7 ) ;
if ( ! V_2 -> V_17 )
return - V_102 ;
V_2 -> V_21 = F_38 ( V_98 ,
V_96 -> V_100 , V_96 -> V_103 , V_18 , L_8 ) ;
if ( ! V_2 -> V_21 ) {
F_39 ( V_2 -> V_17 ) ;
V_2 -> V_17 = NULL ;
return - V_102 ;
}
return 0 ;
}
void F_40 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 ) {
F_41 ( V_2 -> V_21 ) ;
F_39 ( V_2 -> V_21 ) ;
F_3 ( & V_2 -> V_22 ) ;
V_2 -> V_21 = NULL ;
}
if ( V_2 -> V_17 ) {
F_41 ( V_2 -> V_17 ) ;
F_39 ( V_2 -> V_17 ) ;
F_3 ( & V_2 -> V_19 ) ;
V_2 -> V_17 = NULL ;
}
}
int F_42 ( struct V_53 * V_54 ,
struct V_104 * V_105 ,
T_5 V_106 , T_2 * V_107 ,
T_2 * V_108 )
{
struct V_109 * V_110 = V_105 -> V_111 ;
* V_107 = V_110 ? V_110 -> V_72 : 1 ;
* V_108 = F_43 ( V_112 )
| F_44 ( V_113 ) ;
return 0 ;
}
