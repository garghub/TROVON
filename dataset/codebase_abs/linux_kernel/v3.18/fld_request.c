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
F_19 (target, &fld->lcf_targets, ft_chain) {
if ( V_22 -> V_24 == V_23 )
return V_22 ;
}
F_20 ( L_1 ,
V_18 -> V_25 , V_23 , V_19 , V_18 -> V_20 ) ;
F_19 (target, &fld->lcf_targets, ft_chain) {
const char * V_26 = V_22 -> V_27 != NULL ?
V_22 -> V_27 -> V_28 : L_2 ;
const char * V_29 = V_22 -> V_30 != NULL ?
( char * ) V_22 -> V_30 -> V_31 -> V_32 . V_33 :
L_2 ;
F_20 ( L_3 ,
V_22 -> V_30 , V_29 , V_22 -> V_27 ,
V_26 , V_22 -> V_24 ) ;
}
F_21 () ;
return NULL ;
}
static struct V_21 *
F_22 ( struct V_17 * V_18 , T_1 V_19 )
{
struct V_21 * V_22 ;
F_15 ( V_18 -> V_34 != NULL ) ;
F_23 ( & V_18 -> V_35 ) ;
V_22 = V_18 -> V_34 -> V_36 ( V_18 , V_19 ) ;
F_24 ( & V_18 -> V_35 ) ;
if ( V_22 != NULL ) {
F_25 ( V_37 , L_4 ,
V_18 -> V_25 , V_22 -> V_24 , V_19 ) ;
}
return V_22 ;
}
int F_26 ( struct V_17 * V_18 ,
struct V_21 * V_38 )
{
const char * V_39 ;
struct V_21 * V_22 , * V_16 ;
F_15 ( V_38 != NULL ) ;
V_39 = F_27 ( V_38 ) ;
F_15 ( V_39 != NULL ) ;
F_15 ( V_38 -> V_27 != NULL || V_38 -> V_30 != NULL ) ;
if ( V_18 -> V_40 != V_41 ) {
F_20 ( L_5 ,
V_18 -> V_25 , V_39 , V_38 -> V_24 ) ;
return 0 ;
} else {
F_25 ( V_37 , L_6 ,
V_18 -> V_25 , V_39 , V_38 -> V_24 ) ;
}
F_28 ( V_22 ) ;
if ( V_22 == NULL )
return - V_42 ;
F_23 ( & V_18 -> V_35 ) ;
F_19 (tmp, &fld->lcf_targets, ft_chain) {
if ( V_16 -> V_24 == V_38 -> V_24 ) {
F_24 ( & V_18 -> V_35 ) ;
F_29 ( V_22 ) ;
F_20 ( L_7 ,
V_39 , F_27 ( V_16 ) , V_16 -> V_24 ) ;
return - V_43 ;
}
}
V_22 -> V_30 = V_38 -> V_30 ;
if ( V_22 -> V_30 != NULL )
F_30 ( V_22 -> V_30 ) ;
V_22 -> V_27 = V_38 -> V_27 ;
V_22 -> V_24 = V_38 -> V_24 ;
F_6 ( & V_22 -> V_44 ,
& V_18 -> V_45 ) ;
V_18 -> V_20 ++ ;
F_24 ( & V_18 -> V_35 ) ;
return 0 ;
}
int F_31 ( struct V_17 * V_18 , T_2 V_46 )
{
struct V_21 * V_22 , * V_16 ;
F_23 ( & V_18 -> V_35 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
if ( V_22 -> V_24 == V_46 ) {
V_18 -> V_20 -- ;
F_33 ( & V_22 -> V_44 ) ;
F_24 ( & V_18 -> V_35 ) ;
if ( V_22 -> V_30 != NULL )
F_34 ( V_22 -> V_30 ) ;
F_29 ( V_22 ) ;
return 0 ;
}
}
F_24 ( & V_18 -> V_35 ) ;
return - V_47 ;
}
static int F_35 ( struct V_17 * V_18 )
{
int V_5 ;
V_18 -> V_48 = F_36 ( V_18 -> V_25 ,
V_49 ,
NULL , NULL ) ;
if ( F_37 ( V_18 -> V_48 ) ) {
F_20 ( L_8 ,
V_18 -> V_25 ) ;
V_5 = F_38 ( V_18 -> V_48 ) ;
return V_5 ;
}
V_5 = F_39 ( V_18 -> V_48 ,
V_50 , V_18 ) ;
if ( V_5 ) {
F_20 ( L_9 ,
V_18 -> V_25 , V_5 ) ;
goto V_51;
}
return 0 ;
V_51:
F_40 ( V_18 ) ;
return V_5 ;
}
void F_40 ( struct V_17 * V_18 )
{
if ( V_18 -> V_48 ) {
if ( ! F_37 ( V_18 -> V_48 ) )
F_41 ( & V_18 -> V_48 ) ;
V_18 -> V_48 = NULL ;
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
return ( V_23 >= 0 && V_23 < F_43 ( V_52 ) ) ;
}
int F_44 ( struct V_17 * V_18 ,
const char * V_53 , int V_23 )
{
int V_54 , V_55 ;
int V_5 ;
F_15 ( V_18 != NULL ) ;
snprintf ( V_18 -> V_25 , sizeof( V_18 -> V_25 ) ,
L_10 , V_53 ) ;
if ( ! F_42 ( V_23 ) ) {
F_20 ( L_11 ,
V_18 -> V_25 , V_23 ) ;
return - V_56 ;
}
V_18 -> V_20 = 0 ;
F_45 ( & V_18 -> V_35 ) ;
V_18 -> V_34 = & V_52 [ V_23 ] ;
V_18 -> V_40 = V_41 ;
F_46 ( & V_18 -> V_45 ) ;
V_54 = V_57 /
sizeof( struct V_58 ) ;
V_55 = V_54 *
V_59 / 100 ;
V_18 -> V_60 = F_47 ( V_18 -> V_25 ,
V_54 , V_55 ) ;
if ( F_37 ( V_18 -> V_60 ) ) {
V_5 = F_38 ( V_18 -> V_60 ) ;
V_18 -> V_60 = NULL ;
goto V_61;
}
V_5 = F_35 ( V_18 ) ;
if ( V_5 )
goto V_61;
V_61:
if ( V_5 )
F_48 ( V_18 ) ;
else
F_25 ( V_37 , L_12 ,
V_18 -> V_25 , V_18 -> V_34 -> V_62 ) ;
return V_5 ;
}
void F_48 ( struct V_17 * V_18 )
{
struct V_21 * V_22 , * V_16 ;
F_23 ( & V_18 -> V_35 ) ;
F_32 (target, tmp,
&fld->lcf_targets, ft_chain) {
V_18 -> V_20 -- ;
F_33 ( & V_22 -> V_44 ) ;
if ( V_22 -> V_30 != NULL )
F_34 ( V_22 -> V_30 ) ;
F_29 ( V_22 ) ;
}
F_24 ( & V_18 -> V_35 ) ;
if ( V_18 -> V_60 != NULL ) {
if ( ! F_37 ( V_18 -> V_60 ) )
F_49 ( V_18 -> V_60 ) ;
V_18 -> V_60 = NULL ;
}
}
int F_50 ( struct V_63 * exp ,
struct V_64 * V_65 , T_3 V_66 )
{
struct V_67 * V_68 ;
struct V_64 * V_69 ;
T_3 * V_70 ;
int V_5 ;
struct V_71 * V_72 ;
F_15 ( exp != NULL ) ;
V_72 = F_51 ( exp ) ;
V_68 = F_52 ( V_72 , & V_73 , V_74 ,
V_75 ) ;
if ( V_68 == NULL )
return - V_42 ;
V_70 = F_53 ( & V_68 -> V_76 , & V_77 ) ;
* V_70 = V_66 ;
V_69 = F_53 ( & V_68 -> V_76 , & V_78 ) ;
* V_69 = * V_65 ;
F_54 ( V_68 ) ;
V_68 -> V_79 = V_80 ;
V_68 -> V_81 = V_82 ;
F_55 ( V_68 ) ;
if ( V_66 == V_83 &&
V_72 -> V_84 & V_85 )
V_68 -> V_86 = 1 ;
if ( V_66 != V_83 )
F_56 ( exp -> V_31 -> V_87 . V_2 . V_88 , NULL ) ;
F_5 ( & exp -> V_31 -> V_87 . V_2 ) ;
V_5 = F_57 ( V_68 ) ;
F_9 ( & exp -> V_31 -> V_87 . V_2 ) ;
if ( V_66 != V_83 )
F_58 ( exp -> V_31 -> V_87 . V_2 . V_88 , NULL ) ;
if ( V_5 )
goto V_89;
V_69 = F_59 ( & V_68 -> V_76 , & V_78 ) ;
if ( V_69 == NULL ) {
V_5 = - V_90 ;
goto V_89;
}
* V_65 = * V_69 ;
V_89:
F_60 ( V_68 ) ;
return V_5 ;
}
int F_61 ( struct V_17 * V_18 , T_1 V_19 , T_4 * V_91 ,
T_3 V_92 , const struct V_93 * V_94 )
{
struct V_64 V_95 = { 0 } ;
struct V_21 * V_22 ;
int V_5 ;
V_18 -> V_40 |= V_96 ;
V_5 = F_62 ( V_18 -> V_60 , V_19 , & V_95 ) ;
if ( V_5 == 0 ) {
* V_91 = V_95 . V_97 ;
return 0 ;
}
V_22 = F_22 ( V_18 , V_19 ) ;
F_15 ( V_22 != NULL ) ;
F_25 ( V_37 , L_13 ,
V_18 -> V_25 , V_19 , F_27 ( V_22 ) , V_22 -> V_24 ) ;
V_95 . V_98 = V_19 ;
F_63 ( & V_95 , V_92 ) ;
V_5 = F_50 ( V_22 -> V_30 , & V_95 , V_83 ) ;
if ( V_5 == 0 ) {
* V_91 = V_95 . V_97 ;
F_64 ( V_18 -> V_60 , & V_95 ) ;
}
return V_5 ;
}
void F_65 ( struct V_17 * V_18 )
{
F_66 ( V_18 -> V_60 ) ;
}
static int T_5 F_67 ( void )
{
V_49 = F_36 ( V_99 ,
V_100 ,
NULL , NULL ) ;
return F_68 ( V_49 ) ;
}
static void T_6 F_69 ( void )
{
if ( V_49 != NULL && ! F_37 ( V_49 ) ) {
F_41 ( & V_49 ) ;
V_49 = NULL ;
}
}
