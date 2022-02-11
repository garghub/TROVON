static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_5 = F_3 ( & V_4 -> V_8 ) ;
F_4 ( & V_2 -> V_7 ) ;
RETURN ( V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_9 V_10 = { 0 } ;
F_2 ( & V_2 -> V_7 ) ;
if ( V_2 -> V_11 >= V_2 -> V_12 ) {
F_6 ( & V_4 . V_8 , & V_2 -> V_13 ) ;
F_7 ( & V_4 . V_14 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_8 ( V_4 . V_14 , F_1 ( V_2 , & V_4 ) , & V_10 ) ;
} else {
V_2 -> V_11 ++ ;
F_4 ( & V_2 -> V_7 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_15 * V_16 , * V_17 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_7 ) ;
V_2 -> V_11 -- ;
F_10 (l, tmp, &cli->cl_cache_waiters) {
if ( V_2 -> V_11 >= V_2 -> V_12 ) {
break;
}
V_4 = F_11 ( V_16 , struct V_3 , V_8 ) ;
F_12 ( & V_4 -> V_8 ) ;
V_2 -> V_11 ++ ;
F_13 ( & V_4 -> V_14 ) ;
}
F_4 ( & V_2 -> V_7 ) ;
}
static int F_14 ( struct V_18 * V_19 ,
T_1 V_20 )
{
F_15 ( V_19 -> V_21 > 0 ) ;
return F_16 ( V_20 , V_19 -> V_21 ) ;
}
static struct V_22 *
F_17 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_22 * V_23 ;
int V_24 ;
V_6 ;
if ( F_18 ( V_20 ) )
V_24 = F_14 ( V_19 , V_20 ) ;
else
V_24 = 0 ;
F_19 (target, &fld->lcf_targets, ft_chain) {
if ( V_23 -> V_25 == V_24 )
RETURN ( V_23 ) ;
}
F_20 ( L_1 V_26 L_2
L_3 , V_19 -> V_27 , V_24 , V_20 ,
V_19 -> V_21 ) ;
F_19 (target, &fld->lcf_targets, ft_chain) {
const char * V_28 = V_23 -> V_29 != NULL ?
V_23 -> V_29 -> V_30 : L_4 ;
const char * V_31 = V_23 -> V_32 != NULL ?
( char * ) V_23 -> V_32 -> V_33 -> V_34 . V_35 :
L_4 ;
F_20 ( L_5 V_36 L_6 ,
V_23 -> V_32 , V_31 , V_23 -> V_29 ,
V_28 , V_23 -> V_25 ) ;
}
F_21 () ;
RETURN ( NULL ) ;
}
static struct V_22 *
F_22 ( struct V_18 * V_19 , T_1 V_20 )
{
struct V_22 * V_23 ;
V_6 ;
F_15 ( V_19 -> V_37 != NULL ) ;
F_23 ( & V_19 -> V_38 ) ;
V_23 = V_19 -> V_37 -> V_39 ( V_19 , V_20 ) ;
F_24 ( & V_19 -> V_38 ) ;
if ( V_23 != NULL ) {
F_25 ( V_40 , L_7 V_36
L_8 V_26 L_6 , V_19 -> V_27 ,
V_23 -> V_25 , V_20 ) ;
}
RETURN ( V_23 ) ;
}
int F_26 ( struct V_18 * V_19 ,
struct V_22 * V_41 )
{
const char * V_42 ;
struct V_22 * V_23 , * V_17 ;
V_6 ;
F_15 ( V_41 != NULL ) ;
V_42 = F_27 ( V_41 ) ;
F_15 ( V_42 != NULL ) ;
F_15 ( V_41 -> V_29 != NULL || V_41 -> V_32 != NULL ) ;
if ( V_19 -> V_43 != V_44 ) {
F_20 ( L_9 V_36 L_10
L_11 , V_19 -> V_27 , V_42 ,
V_41 -> V_25 ) ;
RETURN ( 0 ) ;
} else {
F_25 ( V_40 , L_12
V_36 L_13 , V_19 -> V_27 , V_42 , V_41 -> V_25 ) ;
}
F_28 ( V_23 ) ;
if ( V_23 == NULL )
RETURN ( - V_45 ) ;
F_23 ( & V_19 -> V_38 ) ;
F_19 (tmp, &fld->lcf_targets, ft_chain) {
if ( V_17 -> V_25 == V_41 -> V_25 ) {
F_24 ( & V_19 -> V_38 ) ;
F_29 ( V_23 ) ;
F_20 ( L_14 V_36 L_6 ,
V_42 , F_27 ( V_17 ) , V_17 -> V_25 ) ;
RETURN ( - V_46 ) ;
}
}
V_23 -> V_32 = V_41 -> V_32 ;
if ( V_23 -> V_32 != NULL )
F_30 ( V_23 -> V_32 ) ;
V_23 -> V_29 = V_41 -> V_29 ;
V_23 -> V_25 = V_41 -> V_25 ;
F_6 ( & V_23 -> V_47 ,
& V_19 -> V_48 ) ;
V_19 -> V_21 ++ ;
F_24 ( & V_19 -> V_38 ) ;
RETURN ( 0 ) ;
}
int F_31 ( struct V_18 * V_19 , T_2 V_49 )
{
struct V_22 * V_23 , * V_17 ;
V_6 ;
F_23 ( & V_19 -> V_38 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
if ( V_23 -> V_25 == V_49 ) {
V_19 -> V_21 -- ;
F_33 ( & V_23 -> V_47 ) ;
F_24 ( & V_19 -> V_38 ) ;
if ( V_23 -> V_32 != NULL )
F_34 ( V_23 -> V_32 ) ;
F_29 ( V_23 ) ;
RETURN ( 0 ) ;
}
}
F_24 ( & V_19 -> V_38 ) ;
RETURN ( - V_50 ) ;
}
static int F_35 ( struct V_18 * V_19 )
{
int V_5 ;
V_6 ;
V_19 -> V_51 = F_36 ( V_19 -> V_27 ,
V_52 ,
NULL , NULL ) ;
if ( F_37 ( V_19 -> V_51 ) ) {
F_20 ( L_15 ,
V_19 -> V_27 ) ;
V_5 = F_38 ( V_19 -> V_51 ) ;
RETURN ( V_5 ) ;
}
V_5 = F_39 ( V_19 -> V_51 ,
V_53 , V_19 ) ;
if ( V_5 ) {
F_20 ( L_16 ,
V_19 -> V_27 , V_5 ) ;
GOTO ( V_54 , V_5 ) ;
}
RETURN ( 0 ) ;
V_54:
F_40 ( V_19 ) ;
return V_5 ;
}
void F_40 ( struct V_18 * V_19 )
{
V_6 ;
if ( V_19 -> V_51 ) {
if ( ! F_37 ( V_19 -> V_51 ) )
F_41 ( & V_19 -> V_51 ) ;
V_19 -> V_51 = NULL ;
}
EXIT ;
}
static int F_35 ( struct V_18 * V_19 )
{
return 0 ;
}
void F_40 ( struct V_18 * V_19 )
{
return;
}
static inline int F_42 ( int V_24 )
{
return ( V_24 >= 0 && V_24 < F_43 ( V_55 ) ) ;
}
int F_44 ( struct V_18 * V_19 ,
const char * V_56 , int V_24 )
{
int V_57 , V_58 ;
int V_5 ;
V_6 ;
F_15 ( V_19 != NULL ) ;
snprintf ( V_19 -> V_27 , sizeof( V_19 -> V_27 ) ,
L_17 , V_56 ) ;
if ( ! F_42 ( V_24 ) ) {
F_20 ( L_18 ,
V_19 -> V_27 , V_24 ) ;
RETURN ( - V_59 ) ;
}
V_19 -> V_21 = 0 ;
F_45 ( & V_19 -> V_38 ) ;
V_19 -> V_37 = & V_55 [ V_24 ] ;
V_19 -> V_43 = V_44 ;
F_46 ( & V_19 -> V_48 ) ;
V_57 = V_60 /
sizeof( struct V_61 ) ;
V_58 = V_57 *
V_62 / 100 ;
V_19 -> V_63 = F_47 ( V_19 -> V_27 ,
V_57 , V_58 ) ;
if ( F_37 ( V_19 -> V_63 ) ) {
V_5 = F_38 ( V_19 -> V_63 ) ;
V_19 -> V_63 = NULL ;
GOTO ( V_64 , V_5 ) ;
}
V_5 = F_35 ( V_19 ) ;
if ( V_5 )
GOTO ( V_64 , V_5 ) ;
EXIT ;
V_64:
if ( V_5 )
F_48 ( V_19 ) ;
else
F_25 ( V_40 , L_19 ,
V_19 -> V_27 , V_19 -> V_37 -> V_65 ) ;
return V_5 ;
}
void F_48 ( struct V_18 * V_19 )
{
struct V_22 * V_23 , * V_17 ;
V_6 ;
F_23 ( & V_19 -> V_38 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
V_19 -> V_21 -- ;
F_33 ( & V_23 -> V_47 ) ;
if ( V_23 -> V_32 != NULL )
F_34 ( V_23 -> V_32 ) ;
F_29 ( V_23 ) ;
}
F_24 ( & V_19 -> V_38 ) ;
if ( V_19 -> V_63 != NULL ) {
if ( ! F_37 ( V_19 -> V_63 ) )
F_49 ( V_19 -> V_63 ) ;
V_19 -> V_63 = NULL ;
}
EXIT ;
}
int F_50 ( struct V_66 * exp ,
struct V_67 * V_68 , T_3 V_69 )
{
struct V_70 * V_71 ;
struct V_67 * V_72 ;
T_3 * V_73 ;
int V_5 ;
struct V_74 * V_75 ;
V_6 ;
F_15 ( exp != NULL ) ;
V_75 = F_51 ( exp ) ;
V_71 = F_52 ( V_75 , & V_76 , V_77 ,
V_78 ) ;
if ( V_71 == NULL )
RETURN ( - V_45 ) ;
V_73 = F_53 ( & V_71 -> V_79 , & V_80 ) ;
* V_73 = V_69 ;
V_72 = F_53 ( & V_71 -> V_79 , & V_81 ) ;
* V_72 = * V_68 ;
F_54 ( V_71 ) ;
V_71 -> V_82 = V_83 ;
F_55 ( V_71 ) ;
if ( V_69 == V_84 &&
V_75 -> V_85 & V_86 )
V_71 -> V_87 = 1 ;
if ( V_69 != V_84 )
F_56 ( exp -> V_33 -> V_88 . V_2 . V_89 , NULL ) ;
F_5 ( & exp -> V_33 -> V_88 . V_2 ) ;
V_5 = F_57 ( V_71 ) ;
F_9 ( & exp -> V_33 -> V_88 . V_2 ) ;
if ( V_69 != V_84 )
F_58 ( exp -> V_33 -> V_88 . V_2 . V_89 , NULL ) ;
if ( V_5 )
GOTO ( V_90 , V_5 ) ;
V_72 = F_59 ( & V_71 -> V_79 , & V_81 ) ;
if ( V_72 == NULL )
GOTO ( V_90 , V_5 = - V_91 ) ;
* V_68 = * V_72 ;
EXIT ;
V_90:
F_60 ( V_71 ) ;
return V_5 ;
}
int F_61 ( struct V_18 * V_19 , T_1 V_20 , T_4 * V_92 ,
T_3 V_93 , const struct V_94 * V_95 )
{
struct V_67 V_96 = { 0 } ;
struct V_22 * V_23 ;
int V_5 ;
V_6 ;
V_19 -> V_43 |= V_97 ;
V_5 = F_62 ( V_19 -> V_63 , V_20 , & V_96 ) ;
if ( V_5 == 0 ) {
* V_92 = V_96 . V_98 ;
RETURN ( 0 ) ;
}
V_23 = F_22 ( V_19 , V_20 ) ;
F_15 ( V_23 != NULL ) ;
F_25 ( V_40 , L_20 V_26 L_21
L_22 V_36 L_13 , V_19 -> V_27 , V_20 ,
F_27 ( V_23 ) , V_23 -> V_25 ) ;
V_96 . V_99 = V_20 ;
F_63 ( & V_96 , V_93 ) ;
if ( V_23 -> V_29 != NULL ) {
F_15 ( V_95 != NULL ) ;
V_5 = F_64 ( V_95 , V_23 -> V_29 , V_20 , & V_96 ) ;
} else {
V_5 = F_50 ( V_23 -> V_32 , & V_96 , V_84 ) ;
}
if ( V_5 == 0 ) {
* V_92 = V_96 . V_98 ;
F_65 ( V_19 -> V_63 , & V_96 ) ;
}
RETURN ( V_5 ) ;
}
void F_66 ( struct V_18 * V_19 )
{
F_67 ( V_19 -> V_63 ) ;
}
