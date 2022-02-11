static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( V_4 ) ;
F_3 ( F_4 ( & V_6 -> V_7 ) ) ;
F_5 ( V_6 , V_8 ) ;
}
static void F_6 ( const struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = V_10 -> V_13 . V_14 ;
F_7 ( V_12 ) ;
F_8 ( & V_12 -> V_15 , L_1 , V_16 ) ;
F_9 ( V_2 , V_12 ) ;
}
static void F_10 ( const struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
V_12 = V_10 -> V_13 . V_14 ;
F_11 ( V_2 , V_10 -> V_13 . V_14 ) ;
F_12 ( & V_12 -> V_15 , L_1 , V_16 ) ;
F_13 ( V_2 , V_12 ) ;
}
static void F_14 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_17 V_18 )
{
struct V_5 * V_19 = F_2 ( V_4 ) ;
struct V_20 * V_21 ;
F_3 ( F_15 ( V_4 -> V_14 ) ) ;
F_16 (scan, &sub->lss_parents, lll_list) {
struct V_9 * V_10 = V_21 -> V_22 ;
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
if ( V_19 -> V_23 != V_12 ) {
F_6 ( V_2 , V_10 ) ;
F_17 ( V_2 , V_12 ) ;
F_10 ( V_2 , V_10 ) ;
}
}
}
static unsigned long F_18 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_24 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
unsigned long V_25 ;
F_3 ( F_15 ( V_4 -> V_14 ) ) ;
if ( ! F_4 ( & V_24 -> V_7 ) ) {
V_10 = F_19 ( V_24 -> V_7 . V_26 ,
struct V_20 , V_27 ) -> V_22 ;
F_6 ( V_2 , V_10 ) ;
V_25 = F_20 ( V_2 , V_10 -> V_13 . V_14 ) ;
F_10 ( V_2 , V_10 ) ;
} else
V_25 = 0 ;
return V_25 ;
}
static void F_21 ( const struct V_28 * V_29 ,
struct V_30 * V_10 ,
int V_31 , struct V_28 * V_32 )
{
T_1 V_33 ;
T_1 V_34 ;
T_1 V_35 ;
T_1 V_36 ;
V_35 = V_29 -> V_37 ;
V_36 = V_29 -> V_38 ;
if ( V_10 -> V_39 -> V_40 > 1 ) {
V_33 = F_22 ( F_23 ( V_10 ) , V_10 -> V_39 -> V_41 ) ;
V_34 = ( V_10 -> V_39 -> V_40 - 1 ) * V_33 ;
V_35 += V_35 / V_33 * V_34 + V_31 * V_33 ;
if ( V_36 != V_42 ) {
V_36 += V_36 / V_33 * V_34 + V_31 * V_33 ;
if ( V_36 < V_29 -> V_38 )
V_36 = V_42 ;
}
}
V_32 -> V_37 = V_35 ;
V_32 -> V_38 = V_36 ;
}
int F_24 ( const struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_5 * V_43 ,
const struct V_28 * V_44 , int V_45 )
{
struct V_11 * V_12 ;
struct V_46 * V_47 ;
struct V_28 * V_48 ;
struct V_28 * V_49 ;
int V_50 ;
V_12 = V_10 -> V_13 . V_14 ;
V_49 = & V_12 -> V_51 ;
F_3 ( F_25 ( V_44 -> V_52 , V_49 -> V_52 ) ) ;
V_47 = F_26 ( V_43 -> V_53 . V_54 ) ;
V_48 = & F_27 ( V_2 ) -> V_55 ;
V_48 -> V_56 = V_49 -> V_56 ;
V_48 -> V_52 = V_49 -> V_52 ;
V_48 -> V_57 = V_49 -> V_57 ;
F_21 ( V_44 , V_47 -> V_58 , V_47 -> V_59 , V_48 ) ;
V_10 -> V_60 [ V_45 ] . V_61 = * V_44 ;
if ( ! F_28 ( V_49 , V_48 ) )
V_50 = F_29 ( V_2 , V_12 , V_48 ) ;
else
V_50 = 0 ;
return V_50 ;
}
static int F_30 ( const struct V_1 * V_2 ,
const struct V_3 * V_62 ,
const struct V_28 * V_44 )
{
struct V_5 * V_24 = F_2 ( V_62 ) ;
struct V_20 * V_21 ;
struct V_9 * V_10 ;
int V_50 = 0 ;
F_3 ( F_25 ( V_44 -> V_52 ,
V_62 -> V_14 -> V_51 . V_52 ) ) ;
F_16 (scan, &lock->lss_parents, lll_list) {
int V_63 ;
V_10 = V_21 -> V_22 ;
F_6 ( V_2 , V_10 ) ;
V_63 = F_24 ( V_2 , V_10 , V_24 , V_44 , V_21 -> V_64 ) ;
F_10 ( V_2 , V_10 ) ;
V_50 = V_50 ? : V_63 ;
}
return V_50 ;
}
static int F_31 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_65 * V_66 )
{
struct V_5 * V_19 ;
struct V_11 * V_12 ;
struct V_20 * V_21 ;
int V_50 ;
F_3 ( F_15 ( V_4 -> V_14 ) ) ;
V_19 = F_2 ( V_4 ) ;
V_50 = 0 ;
F_16 (scan, &sub->lss_parents, lll_list) {
V_12 = V_21 -> V_22 -> V_13 . V_14 ;
V_50 = F_32 ( V_2 , V_12 , V_66 ) ;
if ( V_50 != 0 )
break;
}
return V_50 ;
}
static int F_33 ( const struct V_1 * V_2 ,
struct V_11 * V_67 , struct V_9 * V_10 )
{
struct V_11 * V_12 ;
int V_50 ;
V_12 = V_10 -> V_13 . V_14 ;
if ( V_12 -> V_68 )
return 0 ;
V_50 = 0 ;
switch ( V_12 -> V_69 ) {
case V_70 :
F_3 ( V_12 -> V_71 & V_72 ) ;
break;
case V_73 :
case V_74 :
F_17 ( V_2 , V_12 ) ;
break;
case V_75 :
if ( F_34 ( V_12 ) )
V_10 -> V_76 = 1 ;
break;
case V_77 :
F_35 ( V_2 , V_12 , V_78 ) ;
case V_78 :
if ( V_10 -> V_79 == 0 ) {
if ( F_36 ( V_2 ) == 2 ) {
F_11 ( V_2 , V_67 ) ;
F_37 ( V_2 , V_12 ) ;
F_38 ( V_2 , V_12 ) ;
V_50 = 1 ;
}
}
break;
case V_80 :
F_39 ( V_81 , V_2 , V_12 , L_2 ) ;
default:
F_40 ( L_3 , V_12 -> V_69 ) ;
F_41 () ;
break;
}
return V_50 ;
}
static void F_42 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_11 * V_67 = V_4 -> V_14 ;
struct V_5 * V_19 = F_2 ( V_4 ) ;
int V_82 ;
F_3 ( F_15 ( V_67 ) ) ;
do {
struct V_9 * V_10 ;
struct V_20 * V_21 ;
struct V_20 * V_83 ;
struct V_84 * V_85 ;
V_82 = 0 ;
F_43 (scan, temp,
&sub->lss_parents, lll_list) {
V_10 = V_21 -> V_22 ;
V_85 = & V_10 -> V_60 [ V_21 -> V_64 ] ;
F_6 ( V_2 , V_10 ) ;
V_85 -> V_61 = V_85 -> V_86 ;
F_44 ( V_2 , V_21 , V_19 ) ;
V_82 = F_33 ( V_2 , V_67 , V_10 ) ;
F_10 ( V_2 , V_10 ) ;
if ( V_82 ) {
F_9 ( V_2 , V_67 ) ;
break;
}
}
} while ( V_82 );
}
static int F_45 ( const struct V_1 * V_2 , void * V_87 ,
T_2 V_88 , const struct V_3 * V_4 )
{
struct V_5 * V_19 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
struct V_20 * V_21 ;
F_16 (scan, &sub->lss_parents, lll_list) {
V_10 = V_21 -> V_22 ;
(* V_88)( V_2 , V_87 , L_4 , V_21 -> V_64 , V_10 ) ;
if ( V_10 != NULL )
F_46 ( V_2 , V_87 , V_88 ,
& V_10 -> V_13 . V_14 -> V_51 ) ;
(* V_88)( V_2 , V_87 , L_5 ) ;
}
return 0 ;
}
int F_47 ( const struct V_1 * V_2 , struct V_89 * V_90 ,
struct V_11 * V_24 , const struct V_91 * V_92 )
{
struct V_5 * V_93 ;
int V_50 ;
F_48 ( V_93 , V_8 , V_94 ) ;
if ( V_93 != NULL ) {
F_49 ( & V_93 -> V_7 ) ;
F_50 ( V_24 , & V_93 -> V_53 , V_90 , & V_95 ) ;
V_50 = 0 ;
} else
V_50 = - V_96 ;
return V_50 ;
}
