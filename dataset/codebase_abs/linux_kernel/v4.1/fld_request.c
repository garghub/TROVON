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
static int F_14 ( struct V_17 * V_18 , T_1 V_19 )
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
V_24:
F_19 (target, &fld->lcf_targets, ft_chain) {
if ( V_22 -> V_25 == V_23 )
return V_22 ;
}
if ( V_23 != 0 ) {
V_23 = 0 ;
goto V_24;
}
F_20 ( L_1 ,
V_18 -> V_26 , V_23 , V_19 , V_18 -> V_20 ) ;
F_19 (target, &fld->lcf_targets, ft_chain) {
const char * V_27 = V_22 -> V_28 != NULL ?
V_22 -> V_28 -> V_29 : L_2 ;
const char * V_30 = V_22 -> V_31 != NULL ?
( char * ) V_22 -> V_31 -> V_32 -> V_33 . V_34 :
L_2 ;
F_20 ( L_3 ,
V_22 -> V_31 , V_30 , V_22 -> V_28 ,
V_27 , V_22 -> V_25 ) ;
}
F_21 () ;
return NULL ;
}
static struct V_21 *
F_22 ( struct V_17 * V_18 , T_1 V_19 )
{
struct V_21 * V_22 ;
F_15 ( V_18 -> V_35 != NULL ) ;
F_23 ( & V_18 -> V_36 ) ;
V_22 = V_18 -> V_35 -> V_37 ( V_18 , V_19 ) ;
F_24 ( & V_18 -> V_36 ) ;
if ( V_22 != NULL ) {
F_25 ( V_38 , L_4 ,
V_18 -> V_26 , V_22 -> V_25 , V_19 ) ;
}
return V_22 ;
}
int F_26 ( struct V_17 * V_18 ,
struct V_21 * V_39 )
{
const char * V_40 ;
struct V_21 * V_22 , * V_16 ;
F_15 ( V_39 != NULL ) ;
V_40 = F_27 ( V_39 ) ;
F_15 ( V_40 != NULL ) ;
F_15 ( V_39 -> V_28 != NULL || V_39 -> V_31 != NULL ) ;
if ( V_18 -> V_41 != V_42 ) {
F_20 ( L_5 ,
V_18 -> V_26 , V_40 , V_39 -> V_25 ) ;
return 0 ;
}
F_25 ( V_38 , L_6 ,
V_18 -> V_26 , V_40 , V_39 -> V_25 ) ;
F_28 ( V_22 ) ;
if ( V_22 == NULL )
return - V_43 ;
F_23 ( & V_18 -> V_36 ) ;
F_19 (tmp, &fld->lcf_targets, ft_chain) {
if ( V_16 -> V_25 == V_39 -> V_25 ) {
F_24 ( & V_18 -> V_36 ) ;
F_29 ( V_22 ) ;
F_20 ( L_7 ,
V_40 , F_27 ( V_16 ) , V_16 -> V_25 ) ;
return - V_44 ;
}
}
V_22 -> V_31 = V_39 -> V_31 ;
if ( V_22 -> V_31 != NULL )
F_30 ( V_22 -> V_31 ) ;
V_22 -> V_28 = V_39 -> V_28 ;
V_22 -> V_25 = V_39 -> V_25 ;
F_6 ( & V_22 -> V_45 ,
& V_18 -> V_46 ) ;
V_18 -> V_20 ++ ;
F_24 ( & V_18 -> V_36 ) ;
return 0 ;
}
int F_31 ( struct V_17 * V_18 , T_2 V_47 )
{
struct V_21 * V_22 , * V_16 ;
F_23 ( & V_18 -> V_36 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
if ( V_22 -> V_25 == V_47 ) {
V_18 -> V_20 -- ;
F_33 ( & V_22 -> V_45 ) ;
F_24 ( & V_18 -> V_36 ) ;
if ( V_22 -> V_31 != NULL )
F_34 ( V_22 -> V_31 ) ;
F_29 ( V_22 ) ;
return 0 ;
}
}
F_24 ( & V_18 -> V_36 ) ;
return - V_48 ;
}
static int F_35 ( struct V_17 * V_18 )
{
int V_5 ;
V_18 -> V_49 = F_36 ( V_18 -> V_26 ,
V_50 ,
NULL , NULL ) ;
if ( F_37 ( V_18 -> V_49 ) ) {
F_20 ( L_8 ,
V_18 -> V_26 ) ;
V_5 = F_38 ( V_18 -> V_49 ) ;
return V_5 ;
}
V_5 = F_39 ( V_18 -> V_49 ,
V_51 , V_18 ) ;
if ( V_5 ) {
F_20 ( L_9 ,
V_18 -> V_26 , V_5 ) ;
goto V_52;
}
return 0 ;
V_52:
F_40 ( V_18 ) ;
return V_5 ;
}
void F_40 ( struct V_17 * V_18 )
{
if ( V_18 -> V_49 ) {
if ( ! F_37 ( V_18 -> V_49 ) )
F_41 ( & V_18 -> V_49 ) ;
V_18 -> V_49 = NULL ;
}
}
static int F_35 ( struct V_17 * V_18 )
{
return 0 ;
}
void F_40 ( struct V_17 * V_18 )
{
}
static inline int F_42 ( int V_23 )
{
return ( V_23 >= 0 && V_23 < F_43 ( V_53 ) ) ;
}
int F_44 ( struct V_17 * V_18 ,
const char * V_54 , int V_23 )
{
int V_55 , V_56 ;
int V_5 ;
F_15 ( V_18 != NULL ) ;
snprintf ( V_18 -> V_26 , sizeof( V_18 -> V_26 ) ,
L_10 , V_54 ) ;
if ( ! F_42 ( V_23 ) ) {
F_20 ( L_11 ,
V_18 -> V_26 , V_23 ) ;
return - V_57 ;
}
V_18 -> V_20 = 0 ;
F_45 ( & V_18 -> V_36 ) ;
V_18 -> V_35 = & V_53 [ V_23 ] ;
V_18 -> V_41 = V_42 ;
F_46 ( & V_18 -> V_46 ) ;
V_55 = V_58 /
sizeof( struct V_59 ) ;
V_56 = V_55 *
V_60 / 100 ;
V_18 -> V_61 = F_47 ( V_18 -> V_26 ,
V_55 , V_56 ) ;
if ( F_37 ( V_18 -> V_61 ) ) {
V_5 = F_38 ( V_18 -> V_61 ) ;
V_18 -> V_61 = NULL ;
goto V_62;
}
V_5 = F_35 ( V_18 ) ;
if ( V_5 )
goto V_62;
V_62:
if ( V_5 )
F_48 ( V_18 ) ;
else
F_25 ( V_38 , L_12 ,
V_18 -> V_26 , V_18 -> V_35 -> V_63 ) ;
return V_5 ;
}
void F_48 ( struct V_17 * V_18 )
{
struct V_21 * V_22 , * V_16 ;
F_23 ( & V_18 -> V_36 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
V_18 -> V_20 -- ;
F_33 ( & V_22 -> V_45 ) ;
if ( V_22 -> V_31 != NULL )
F_34 ( V_22 -> V_31 ) ;
F_29 ( V_22 ) ;
}
F_24 ( & V_18 -> V_36 ) ;
if ( V_18 -> V_61 != NULL ) {
if ( ! F_37 ( V_18 -> V_61 ) )
F_49 ( V_18 -> V_61 ) ;
V_18 -> V_61 = NULL ;
}
}
int F_50 ( struct V_64 * exp ,
struct V_65 * V_66 , T_3 V_67 )
{
struct V_68 * V_69 ;
struct V_65 * V_70 ;
T_3 * V_71 ;
int V_5 ;
struct V_72 * V_73 ;
F_15 ( exp != NULL ) ;
V_73 = F_51 ( exp ) ;
V_69 = F_52 ( V_73 , & V_74 , V_75 ,
V_76 ) ;
if ( V_69 == NULL )
return - V_43 ;
V_71 = F_53 ( & V_69 -> V_77 , & V_78 ) ;
* V_71 = V_67 ;
V_70 = F_53 ( & V_69 -> V_77 , & V_79 ) ;
* V_70 = * V_66 ;
F_54 ( V_69 ) ;
V_69 -> V_80 = V_81 ;
V_69 -> V_82 = V_83 ;
F_55 ( V_69 ) ;
if ( V_67 == V_84 &&
V_73 -> V_85 & V_86 )
V_69 -> V_87 = 1 ;
if ( V_67 != V_84 )
F_56 ( exp -> V_32 -> V_88 . V_2 . V_89 , NULL ) ;
F_5 ( & exp -> V_32 -> V_88 . V_2 ) ;
V_5 = F_57 ( V_69 ) ;
F_9 ( & exp -> V_32 -> V_88 . V_2 ) ;
if ( V_67 != V_84 )
F_58 ( exp -> V_32 -> V_88 . V_2 . V_89 , NULL ) ;
if ( V_5 )
goto V_90;
V_70 = F_59 ( & V_69 -> V_77 , & V_79 ) ;
if ( V_70 == NULL ) {
V_5 = - V_91 ;
goto V_90;
}
* V_66 = * V_70 ;
V_90:
F_60 ( V_69 ) ;
return V_5 ;
}
int F_61 ( struct V_17 * V_18 , T_1 V_19 , T_4 * V_92 ,
T_3 V_93 , const struct V_94 * V_95 )
{
struct V_65 V_96 = { 0 } ;
struct V_21 * V_22 ;
int V_5 ;
V_18 -> V_41 |= V_97 ;
V_5 = F_62 ( V_18 -> V_61 , V_19 , & V_96 ) ;
if ( V_5 == 0 ) {
* V_92 = V_96 . V_98 ;
return 0 ;
}
V_22 = F_22 ( V_18 , V_19 ) ;
F_15 ( V_22 != NULL ) ;
F_25 ( V_38 , L_13 ,
V_18 -> V_26 , V_19 , F_27 ( V_22 ) , V_22 -> V_25 ) ;
V_96 . V_99 = V_19 ;
F_63 ( & V_96 , V_93 ) ;
V_5 = F_50 ( V_22 -> V_31 , & V_96 , V_84 ) ;
if ( V_5 == 0 ) {
* V_92 = V_96 . V_98 ;
F_64 ( V_18 -> V_61 , & V_96 ) ;
}
return V_5 ;
}
void F_65 ( struct V_17 * V_18 )
{
F_66 ( V_18 -> V_61 ) ;
}
static int T_5 F_67 ( void )
{
V_50 = F_36 ( V_100 ,
V_101 ,
NULL , NULL ) ;
return F_68 ( V_50 ) ;
}
static void T_6 F_69 ( void )
{
if ( V_50 != NULL && ! F_37 ( V_50 ) ) {
F_41 ( & V_50 ) ;
V_50 = NULL ;
}
}
