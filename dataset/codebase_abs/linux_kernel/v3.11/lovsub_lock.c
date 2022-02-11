static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_7 ;
V_6 = F_2 ( V_4 ) ;
F_3 ( F_4 ( & V_6 -> V_8 ) ) ;
F_5 ( V_6 , V_9 ) ;
EXIT ;
}
static void F_6 ( const struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_7 ;
V_13 = V_11 -> V_14 . V_15 ;
F_7 ( V_13 ) ;
F_8 ( & V_13 -> V_16 , L_1 , V_17 ) ;
F_9 ( V_2 , V_13 ) ;
EXIT ;
}
static void F_10 ( const struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
V_7 ;
V_13 = V_11 -> V_14 . V_15 ;
F_11 ( V_2 , V_11 -> V_14 . V_15 ) ;
F_12 ( & V_13 -> V_16 , L_1 , V_17 ) ;
F_13 ( V_2 , V_13 ) ;
EXIT ;
}
static void F_14 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_18 V_19 )
{
struct V_5 * V_20 = F_2 ( V_4 ) ;
struct V_21 * V_22 ;
F_3 ( F_15 ( V_4 -> V_15 ) ) ;
V_7 ;
F_16 (scan, &sub->lss_parents, lll_list) {
struct V_10 * V_11 = V_22 -> V_23 ;
struct V_12 * V_13 = V_11 -> V_14 . V_15 ;
if ( V_20 -> V_24 != V_13 ) {
F_6 ( V_2 , V_11 ) ;
F_17 ( V_2 , V_13 ) ;
F_10 ( V_2 , V_11 ) ;
}
}
EXIT ;
}
static unsigned long F_18 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_25 = F_2 ( V_4 ) ;
struct V_10 * V_11 ;
unsigned long V_26 ;
V_7 ;
F_3 ( F_15 ( V_4 -> V_15 ) ) ;
if ( ! F_4 ( & V_25 -> V_8 ) ) {
V_11 = F_19 ( V_25 -> V_8 . V_27 ,
struct V_21 , V_28 ) -> V_23 ;
F_6 ( V_2 , V_11 ) ;
V_26 = F_20 ( V_2 , V_11 -> V_14 . V_15 ) ;
F_10 ( V_2 , V_11 ) ;
} else
V_26 = 0 ;
RETURN ( V_26 ) ;
}
static void F_21 ( const struct V_29 * V_30 ,
struct V_31 * V_11 ,
int V_32 , struct V_29 * V_33 )
{
T_1 V_34 ;
T_1 V_35 ;
T_1 V_36 ;
T_1 V_37 ;
V_7 ;
V_36 = V_30 -> V_38 ;
V_37 = V_30 -> V_39 ;
if ( V_11 -> V_40 -> V_41 > 1 ) {
V_34 = F_22 ( F_23 ( V_11 ) , V_11 -> V_40 -> V_42 ) ;
V_35 = ( V_11 -> V_40 -> V_41 - 1 ) * V_34 ;
V_36 += V_36 / V_34 * V_35 + V_32 * V_34 ;
if ( V_37 != V_43 ) {
V_37 += V_37 / V_34 * V_35 + V_32 * V_34 ;
if ( V_37 < V_30 -> V_39 )
V_37 = V_43 ;
}
}
V_33 -> V_38 = V_36 ;
V_33 -> V_39 = V_37 ;
EXIT ;
}
int F_24 ( const struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_5 * V_44 ,
const struct V_29 * V_45 , int V_46 )
{
struct V_12 * V_13 ;
struct V_47 * V_48 ;
struct V_29 * V_49 ;
struct V_29 * V_50 ;
int V_51 ;
V_13 = V_11 -> V_14 . V_15 ;
V_50 = & V_13 -> V_52 ;
F_3 ( F_25 ( V_45 -> V_53 , V_50 -> V_53 ) ) ;
V_48 = F_26 ( V_44 -> V_54 . V_55 ) ;
V_49 = & F_27 ( V_2 ) -> V_56 ;
V_49 -> V_57 = V_50 -> V_57 ;
V_49 -> V_53 = V_50 -> V_53 ;
V_49 -> V_58 = V_50 -> V_58 ;
F_21 ( V_45 , V_48 -> V_59 , V_48 -> V_60 , V_49 ) ;
V_11 -> V_61 [ V_46 ] . V_62 = * V_45 ;
if ( ! F_28 ( V_50 , V_49 ) )
V_51 = F_29 ( V_2 , V_13 , V_49 ) ;
else
V_51 = 0 ;
return V_51 ;
}
static int F_30 ( const struct V_1 * V_2 ,
const struct V_3 * V_63 ,
const struct V_29 * V_45 )
{
struct V_5 * V_25 = F_2 ( V_63 ) ;
struct V_21 * V_22 ;
struct V_10 * V_11 ;
int V_51 = 0 ;
V_7 ;
F_3 ( F_25 ( V_45 -> V_53 ,
V_63 -> V_15 -> V_52 . V_53 ) ) ;
F_16 (scan, &lock->lss_parents, lll_list) {
int V_64 ;
V_11 = V_22 -> V_23 ;
F_6 ( V_2 , V_11 ) ;
V_64 = F_24 ( V_2 , V_11 , V_25 , V_45 , V_22 -> V_65 ) ;
F_10 ( V_2 , V_11 ) ;
V_51 = V_51 ? : V_64 ;
}
RETURN ( V_51 ) ;
}
static int F_31 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_66 * V_67 )
{
struct V_5 * V_20 ;
struct V_12 * V_13 ;
struct V_21 * V_22 ;
int V_51 ;
F_3 ( F_15 ( V_4 -> V_15 ) ) ;
V_7 ;
V_20 = F_2 ( V_4 ) ;
V_51 = 0 ;
F_16 (scan, &sub->lss_parents, lll_list) {
V_13 = V_22 -> V_23 -> V_14 . V_15 ;
V_51 = F_32 ( V_2 , V_13 , V_67 ) ;
if ( V_51 != 0 )
break;
}
RETURN ( V_51 ) ;
}
static int F_33 ( const struct V_1 * V_2 ,
struct V_12 * V_68 , struct V_10 * V_11 )
{
struct V_12 * V_13 ;
int V_51 ;
V_7 ;
V_13 = V_11 -> V_14 . V_15 ;
if ( V_13 -> V_69 )
RETURN ( 0 ) ;
V_51 = 0 ;
switch ( V_13 -> V_70 ) {
case V_71 :
F_3 ( V_13 -> V_72 & V_73 ) ;
break;
case V_74 :
case V_75 :
F_17 ( V_2 , V_13 ) ;
break;
case V_76 :
if ( F_34 ( V_13 ) )
V_11 -> V_77 = 1 ;
break;
case V_78 :
F_35 ( V_2 , V_13 , V_79 ) ;
case V_79 :
if ( V_11 -> V_80 == 0 ) {
if ( F_36 ( V_2 ) == 2 ) {
F_11 ( V_2 , V_68 ) ;
F_37 ( V_2 , V_13 ) ;
F_38 ( V_2 , V_13 ) ;
V_51 = 1 ;
}
}
break;
case V_81 :
F_39 ( V_82 , V_2 , V_13 , L_2 ) ;
default:
F_40 ( L_3 , V_13 -> V_70 ) ;
F_41 () ;
break;
}
RETURN ( V_51 ) ;
}
static void F_42 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_12 * V_68 = V_4 -> V_15 ;
struct V_5 * V_20 = F_2 ( V_4 ) ;
int V_83 ;
F_3 ( F_15 ( V_68 ) ) ;
V_7 ;
do {
struct V_10 * V_11 ;
struct V_21 * V_22 ;
struct V_21 * V_84 ;
struct V_85 * V_86 ;
V_83 = 0 ;
F_43 (scan, temp,
&sub->lss_parents, lll_list) {
V_11 = V_22 -> V_23 ;
V_86 = & V_11 -> V_61 [ V_22 -> V_65 ] ;
F_6 ( V_2 , V_11 ) ;
V_86 -> V_62 = V_86 -> V_87 ;
F_44 ( V_2 , V_22 , V_20 ) ;
V_83 = F_33 ( V_2 , V_68 , V_11 ) ;
F_10 ( V_2 , V_11 ) ;
if ( V_83 ) {
F_9 ( V_2 , V_68 ) ;
break;
}
}
} while ( V_83 );
EXIT ;
}
static int F_45 ( const struct V_1 * V_2 , void * V_88 ,
T_2 V_89 , const struct V_3 * V_4 )
{
struct V_5 * V_20 = F_2 ( V_4 ) ;
struct V_10 * V_11 ;
struct V_21 * V_22 ;
F_16 (scan, &sub->lss_parents, lll_list) {
V_11 = V_22 -> V_23 ;
(* V_89)( V_2 , V_88 , L_4 , V_22 -> V_65 , V_11 ) ;
if ( V_11 != NULL )
F_46 ( V_2 , V_88 , V_89 ,
& V_11 -> V_14 . V_15 -> V_52 ) ;
(* V_89)( V_2 , V_88 , L_5 ) ;
}
return 0 ;
}
int F_47 ( const struct V_1 * V_2 , struct V_90 * V_91 ,
struct V_12 * V_25 , const struct V_92 * V_93 )
{
struct V_5 * V_94 ;
int V_51 ;
V_7 ;
F_48 ( V_94 , V_9 , V_95 ) ;
if ( V_94 != NULL ) {
F_49 ( & V_94 -> V_8 ) ;
F_50 ( V_25 , & V_94 -> V_54 , V_91 , & V_96 ) ;
V_51 = 0 ;
} else
V_51 = - V_97 ;
RETURN ( V_51 ) ;
}
