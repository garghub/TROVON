static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( & V_4 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_8 V_9 = { 0 } ;
F_2 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_10 >= V_2 -> V_11 ) {
F_6 ( & V_4 . V_7 , & V_2 -> V_12 ) ;
F_7 ( & V_4 . V_13 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_8 ( V_4 . V_13 , F_1 ( V_2 , & V_4 ) , & V_9 ) ;
} else {
V_2 -> V_10 ++ ;
F_4 ( & V_2 -> V_6 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_14 * V_15 , * V_16 ;
struct V_3 * V_4 ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_10 -- ;
F_10 (l, tmp, &cli->cl_cache_waiters) {
if ( V_2 -> V_10 >= V_2 -> V_11 ) {
break;
}
V_4 = F_11 ( V_15 , struct V_3 , V_7 ) ;
F_12 ( & V_4 -> V_7 ) ;
V_2 -> V_10 ++ ;
F_13 ( & V_4 -> V_13 ) ;
}
F_4 ( & V_2 -> V_6 ) ;
}
static int F_14 ( struct V_17 * V_18 ,
T_1 V_19 )
{
F_15 ( V_18 -> V_20 > 0 ) ;
return F_16 ( V_19 , V_18 -> V_20 ) ;
}
static struct V_21 *
F_17 ( struct V_17 * V_18 , T_1 V_19 )
{
struct V_21 * V_22 ;
int V_23 ;
if ( F_18 ( V_19 ) )
V_23 = F_14 ( V_18 , V_19 ) ;
else
V_23 = 0 ;
F_19 (target, &fld->lcf_targets, ft_chain) {
if ( V_22 -> V_24 == V_23 )
return V_22 ;
}
F_20 ( L_1 V_25 L_2
L_3 , V_18 -> V_26 , V_23 , V_19 ,
V_18 -> V_20 ) ;
F_19 (target, &fld->lcf_targets, ft_chain) {
const char * V_27 = V_22 -> V_28 != NULL ?
V_22 -> V_28 -> V_29 : L_4 ;
const char * V_30 = V_22 -> V_31 != NULL ?
( char * ) V_22 -> V_31 -> V_32 -> V_33 . V_34 :
L_4 ;
F_20 ( L_5 V_35 L_6 ,
V_22 -> V_31 , V_30 , V_22 -> V_28 ,
V_27 , V_22 -> V_24 ) ;
}
F_21 () ;
return NULL ;
}
static struct V_21 *
F_22 ( struct V_17 * V_18 , T_1 V_19 )
{
struct V_21 * V_22 ;
F_15 ( V_18 -> V_36 != NULL ) ;
F_23 ( & V_18 -> V_37 ) ;
V_22 = V_18 -> V_36 -> V_38 ( V_18 , V_19 ) ;
F_24 ( & V_18 -> V_37 ) ;
if ( V_22 != NULL ) {
F_25 ( V_39 , L_7 V_35
L_8 V_25 L_6 , V_18 -> V_26 ,
V_22 -> V_24 , V_19 ) ;
}
return V_22 ;
}
int F_26 ( struct V_17 * V_18 ,
struct V_21 * V_40 )
{
const char * V_41 ;
struct V_21 * V_22 , * V_16 ;
F_15 ( V_40 != NULL ) ;
V_41 = F_27 ( V_40 ) ;
F_15 ( V_41 != NULL ) ;
F_15 ( V_40 -> V_28 != NULL || V_40 -> V_31 != NULL ) ;
if ( V_18 -> V_42 != V_43 ) {
F_20 ( L_9 V_35 L_10
L_11 , V_18 -> V_26 , V_41 ,
V_40 -> V_24 ) ;
return 0 ;
} else {
F_25 ( V_39 , L_12
V_35 L_13 , V_18 -> V_26 , V_41 , V_40 -> V_24 ) ;
}
F_28 ( V_22 ) ;
if ( V_22 == NULL )
return - V_44 ;
F_23 ( & V_18 -> V_37 ) ;
F_19 (tmp, &fld->lcf_targets, ft_chain) {
if ( V_16 -> V_24 == V_40 -> V_24 ) {
F_24 ( & V_18 -> V_37 ) ;
F_29 ( V_22 ) ;
F_20 ( L_14 V_35 L_6 ,
V_41 , F_27 ( V_16 ) , V_16 -> V_24 ) ;
return - V_45 ;
}
}
V_22 -> V_31 = V_40 -> V_31 ;
if ( V_22 -> V_31 != NULL )
F_30 ( V_22 -> V_31 ) ;
V_22 -> V_28 = V_40 -> V_28 ;
V_22 -> V_24 = V_40 -> V_24 ;
F_6 ( & V_22 -> V_46 ,
& V_18 -> V_47 ) ;
V_18 -> V_20 ++ ;
F_24 ( & V_18 -> V_37 ) ;
return 0 ;
}
int F_31 ( struct V_17 * V_18 , T_2 V_48 )
{
struct V_21 * V_22 , * V_16 ;
F_23 ( & V_18 -> V_37 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
if ( V_22 -> V_24 == V_48 ) {
V_18 -> V_20 -- ;
F_33 ( & V_22 -> V_46 ) ;
F_24 ( & V_18 -> V_37 ) ;
if ( V_22 -> V_31 != NULL )
F_34 ( V_22 -> V_31 ) ;
F_29 ( V_22 ) ;
return 0 ;
}
}
F_24 ( & V_18 -> V_37 ) ;
return - V_49 ;
}
static int F_35 ( struct V_17 * V_18 )
{
int V_5 ;
V_18 -> V_50 = F_36 ( V_18 -> V_26 ,
V_51 ,
NULL , NULL ) ;
if ( F_37 ( V_18 -> V_50 ) ) {
F_20 ( L_15 ,
V_18 -> V_26 ) ;
V_5 = F_38 ( V_18 -> V_50 ) ;
return V_5 ;
}
V_5 = F_39 ( V_18 -> V_50 ,
V_52 , V_18 ) ;
if ( V_5 ) {
F_20 ( L_16 ,
V_18 -> V_26 , V_5 ) ;
GOTO ( V_53 , V_5 ) ;
}
return 0 ;
V_53:
F_40 ( V_18 ) ;
return V_5 ;
}
void F_40 ( struct V_17 * V_18 )
{
if ( V_18 -> V_50 ) {
if ( ! F_37 ( V_18 -> V_50 ) )
F_41 ( & V_18 -> V_50 ) ;
V_18 -> V_50 = NULL ;
}
}
static int F_35 ( struct V_17 * V_18 )
{
return 0 ;
}
void F_40 ( struct V_17 * V_18 )
{
return;
}
static inline int F_42 ( int V_23 )
{
return ( V_23 >= 0 && V_23 < F_43 ( V_54 ) ) ;
}
int F_44 ( struct V_17 * V_18 ,
const char * V_55 , int V_23 )
{
int V_56 , V_57 ;
int V_5 ;
F_15 ( V_18 != NULL ) ;
snprintf ( V_18 -> V_26 , sizeof( V_18 -> V_26 ) ,
L_17 , V_55 ) ;
if ( ! F_42 ( V_23 ) ) {
F_20 ( L_18 ,
V_18 -> V_26 , V_23 ) ;
return - V_58 ;
}
V_18 -> V_20 = 0 ;
F_45 ( & V_18 -> V_37 ) ;
V_18 -> V_36 = & V_54 [ V_23 ] ;
V_18 -> V_42 = V_43 ;
F_46 ( & V_18 -> V_47 ) ;
V_56 = V_59 /
sizeof( struct V_60 ) ;
V_57 = V_56 *
V_61 / 100 ;
V_18 -> V_62 = F_47 ( V_18 -> V_26 ,
V_56 , V_57 ) ;
if ( F_37 ( V_18 -> V_62 ) ) {
V_5 = F_38 ( V_18 -> V_62 ) ;
V_18 -> V_62 = NULL ;
GOTO ( V_63 , V_5 ) ;
}
V_5 = F_35 ( V_18 ) ;
if ( V_5 )
GOTO ( V_63 , V_5 ) ;
V_63:
if ( V_5 )
F_48 ( V_18 ) ;
else
F_25 ( V_39 , L_19 ,
V_18 -> V_26 , V_18 -> V_36 -> V_64 ) ;
return V_5 ;
}
void F_48 ( struct V_17 * V_18 )
{
struct V_21 * V_22 , * V_16 ;
F_23 ( & V_18 -> V_37 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
V_18 -> V_20 -- ;
F_33 ( & V_22 -> V_46 ) ;
if ( V_22 -> V_31 != NULL )
F_34 ( V_22 -> V_31 ) ;
F_29 ( V_22 ) ;
}
F_24 ( & V_18 -> V_37 ) ;
if ( V_18 -> V_62 != NULL ) {
if ( ! F_37 ( V_18 -> V_62 ) )
F_49 ( V_18 -> V_62 ) ;
V_18 -> V_62 = NULL ;
}
}
int F_50 ( struct V_65 * exp ,
struct V_66 * V_67 , T_3 V_68 )
{
struct V_69 * V_70 ;
struct V_66 * V_71 ;
T_3 * V_72 ;
int V_5 ;
struct V_73 * V_74 ;
F_15 ( exp != NULL ) ;
V_74 = F_51 ( exp ) ;
V_70 = F_52 ( V_74 , & V_75 , V_76 ,
V_77 ) ;
if ( V_70 == NULL )
return - V_44 ;
V_72 = F_53 ( & V_70 -> V_78 , & V_79 ) ;
* V_72 = V_68 ;
V_71 = F_53 ( & V_70 -> V_78 , & V_80 ) ;
* V_71 = * V_67 ;
F_54 ( V_70 ) ;
V_70 -> V_81 = V_82 ;
F_55 ( V_70 ) ;
if ( V_68 == V_83 &&
V_74 -> V_84 & V_85 )
V_70 -> V_86 = 1 ;
if ( V_68 != V_83 )
F_56 ( exp -> V_32 -> V_87 . V_2 . V_88 , NULL ) ;
F_5 ( & exp -> V_32 -> V_87 . V_2 ) ;
V_5 = F_57 ( V_70 ) ;
F_9 ( & exp -> V_32 -> V_87 . V_2 ) ;
if ( V_68 != V_83 )
F_58 ( exp -> V_32 -> V_87 . V_2 . V_88 , NULL ) ;
if ( V_5 )
GOTO ( V_89 , V_5 ) ;
V_71 = F_59 ( & V_70 -> V_78 , & V_80 ) ;
if ( V_71 == NULL )
GOTO ( V_89 , V_5 = - V_90 ) ;
* V_67 = * V_71 ;
V_89:
F_60 ( V_70 ) ;
return V_5 ;
}
int F_61 ( struct V_17 * V_18 , T_1 V_19 , T_4 * V_91 ,
T_3 V_92 , const struct V_93 * V_94 )
{
struct V_66 V_95 = { 0 } ;
struct V_21 * V_22 ;
int V_5 ;
V_18 -> V_42 |= V_96 ;
V_5 = F_62 ( V_18 -> V_62 , V_19 , & V_95 ) ;
if ( V_5 == 0 ) {
* V_91 = V_95 . V_97 ;
return 0 ;
}
V_22 = F_22 ( V_18 , V_19 ) ;
F_15 ( V_22 != NULL ) ;
F_25 ( V_39 , L_20 V_25 L_21
L_22 V_35 L_13 , V_18 -> V_26 , V_19 ,
F_27 ( V_22 ) , V_22 -> V_24 ) ;
V_95 . V_98 = V_19 ;
F_63 ( & V_95 , V_92 ) ;
V_5 = F_50 ( V_22 -> V_31 , & V_95 , V_83 ) ;
if ( V_5 == 0 ) {
* V_91 = V_95 . V_97 ;
F_64 ( V_18 -> V_62 , & V_95 ) ;
}
return V_5 ;
}
void F_65 ( struct V_17 * V_18 )
{
F_66 ( V_18 -> V_62 ) ;
}
static int T_5 F_67 ( void )
{
V_51 = F_36 ( V_99 ,
V_100 ,
NULL , NULL ) ;
if ( F_37 ( V_51 ) )
return F_38 ( V_51 ) ;
F_68 ( & V_101 ) ;
F_69 ( & V_101 ) ;
return 0 ;
}
static void T_6 F_70 ( void )
{
F_71 ( & V_101 ) ;
if ( V_51 != NULL && ! F_37 ( V_51 ) ) {
F_41 ( & V_51 ) ;
V_51 = NULL ;
}
}
