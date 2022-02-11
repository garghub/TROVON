static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_2 -> V_4 > 0 ) ;
return F_3 ( V_3 , V_2 -> V_4 ) ;
}
static struct V_5 *
F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 ;
int V_7 ;
if ( F_5 ( V_3 ) )
V_7 = F_1 ( V_2 , V_3 ) ;
else
V_7 = 0 ;
V_8:
F_6 (target, &fld->lcf_targets, ft_chain) {
if ( V_6 -> V_9 == V_7 )
return V_6 ;
}
if ( V_7 != 0 ) {
V_7 = 0 ;
goto V_8;
}
F_7 ( L_1 ,
V_2 -> V_10 , V_7 , V_3 , V_2 -> V_4 ) ;
F_6 (target, &fld->lcf_targets, ft_chain) {
const char * V_11 = V_6 -> V_12 ?
V_6 -> V_12 -> V_13 : L_2 ;
const char * V_14 = V_6 -> V_15 ?
( char * ) V_6 -> V_15 -> V_16 -> V_17 . V_18 :
L_2 ;
F_7 ( L_3 ,
V_6 -> V_15 , V_14 , V_6 -> V_12 ,
V_11 , V_6 -> V_9 ) ;
}
F_8 () ;
return NULL ;
}
static struct V_5 *
F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 ;
F_2 ( V_2 -> V_19 ) ;
F_10 ( & V_2 -> V_20 ) ;
V_6 = V_2 -> V_19 -> V_21 ( V_2 , V_3 ) ;
F_11 ( & V_2 -> V_20 ) ;
if ( V_6 ) {
F_12 ( V_22 , L_4 ,
V_2 -> V_10 , V_6 -> V_9 , V_3 ) ;
}
return V_6 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_23 )
{
const char * V_24 ;
struct V_5 * V_6 , * V_25 ;
F_2 ( V_23 ) ;
V_24 = F_14 ( V_23 ) ;
F_2 ( V_24 ) ;
F_2 ( V_23 -> V_12 || V_23 -> V_15 ) ;
F_12 ( V_22 , L_5 ,
V_2 -> V_10 , V_24 , V_23 -> V_9 ) ;
V_6 = F_15 ( sizeof( * V_6 ) , V_26 ) ;
if ( ! V_6 )
return - V_27 ;
F_10 ( & V_2 -> V_20 ) ;
F_6 (tmp, &fld->lcf_targets, ft_chain) {
if ( V_25 -> V_9 == V_23 -> V_9 ) {
F_11 ( & V_2 -> V_20 ) ;
F_16 ( V_6 ) ;
F_7 ( L_6 ,
V_24 , F_14 ( V_25 ) , V_25 -> V_9 ) ;
return - V_28 ;
}
}
V_6 -> V_15 = V_23 -> V_15 ;
if ( V_6 -> V_15 )
F_17 ( V_6 -> V_15 ) ;
V_6 -> V_12 = V_23 -> V_12 ;
V_6 -> V_9 = V_23 -> V_9 ;
F_18 ( & V_6 -> V_29 , & V_2 -> V_30 ) ;
V_2 -> V_4 ++ ;
F_11 ( & V_2 -> V_20 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_2 V_31 )
{
struct V_5 * V_6 , * V_25 ;
F_10 ( & V_2 -> V_20 ) ;
F_20 (target, tmp, &fld->lcf_targets, ft_chain) {
if ( V_6 -> V_9 == V_31 ) {
V_2 -> V_4 -- ;
F_21 ( & V_6 -> V_29 ) ;
F_11 ( & V_2 -> V_20 ) ;
if ( V_6 -> V_15 )
F_22 ( V_6 -> V_15 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
}
F_11 ( & V_2 -> V_20 ) ;
return - V_32 ;
}
static int F_23 ( struct V_1 * V_2 )
{
int V_33 ;
V_2 -> V_34 = F_24 ( V_2 -> V_10 ,
V_35 ,
NULL , NULL ) ;
if ( F_25 ( V_2 -> V_34 ) ) {
F_7 ( L_7 , V_2 -> V_10 ) ;
V_33 = V_2 -> V_34 ? F_26 ( V_2 -> V_34 )
: - V_27 ;
V_2 -> V_34 = NULL ;
return V_33 ;
}
V_33 = F_27 ( V_2 -> V_34 ,
V_36 , V_2 ) ;
if ( V_33 ) {
F_7 ( L_8 , V_2 -> V_10 , V_33 ) ;
goto V_37;
}
return 0 ;
V_37:
F_28 ( V_2 ) ;
return V_33 ;
}
void F_28 ( struct V_1 * V_2 )
{
if ( ! F_25 ( V_2 -> V_34 ) )
F_29 ( & V_2 -> V_34 ) ;
}
static inline int F_30 ( int V_7 )
{
return ( V_7 >= 0 && V_7 < F_31 ( V_38 ) ) ;
}
int F_32 ( struct V_1 * V_2 ,
const char * V_39 , int V_7 )
{
int V_40 , V_41 ;
int V_33 ;
snprintf ( V_2 -> V_10 , sizeof( V_2 -> V_10 ) ,
L_9 , V_39 ) ;
if ( ! F_30 ( V_7 ) ) {
F_7 ( L_10 ,
V_2 -> V_10 , V_7 ) ;
return - V_42 ;
}
V_2 -> V_4 = 0 ;
F_33 ( & V_2 -> V_20 ) ;
V_2 -> V_19 = & V_38 [ V_7 ] ;
F_34 ( & V_2 -> V_30 ) ;
V_40 = V_43 /
sizeof( struct V_44 ) ;
V_41 = V_40 *
V_45 / 100 ;
V_2 -> V_46 = F_35 ( V_2 -> V_10 ,
V_40 , V_41 ) ;
if ( F_36 ( V_2 -> V_46 ) ) {
V_33 = F_26 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
goto V_47;
}
V_33 = F_23 ( V_2 ) ;
if ( V_33 )
goto V_47;
V_47:
if ( V_33 )
F_37 ( V_2 ) ;
else
F_12 ( V_22 , L_11 ,
V_2 -> V_10 , V_2 -> V_19 -> V_48 ) ;
return V_33 ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 , * V_25 ;
F_10 ( & V_2 -> V_20 ) ;
F_20 (target, tmp, &fld->lcf_targets, ft_chain) {
V_2 -> V_4 -- ;
F_21 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_15 )
F_22 ( V_6 -> V_15 ) ;
F_16 ( V_6 ) ;
}
F_11 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_46 ) {
if ( ! F_36 ( V_2 -> V_46 ) )
F_38 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
}
}
int F_39 ( struct V_49 * exp ,
struct V_50 * V_51 , T_3 V_52 ,
struct V_53 * * V_54 )
{
struct V_53 * V_55 = NULL ;
struct V_50 * V_56 ;
T_3 * V_57 ;
int V_33 = 0 ;
struct V_58 * V_59 ;
F_2 ( exp ) ;
V_59 = F_40 ( exp ) ;
switch ( V_52 ) {
case V_60 :
V_55 = F_41 ( V_59 , & V_61 ,
V_62 , V_60 ) ;
if ( ! V_55 )
return - V_27 ;
V_57 = F_42 ( & V_55 -> V_63 , & V_64 ) ;
* V_57 = V_65 ;
if ( V_59 -> V_66 & V_67 )
V_55 -> V_68 = 1 ;
break;
case V_69 :
V_55 = F_41 ( V_59 , & V_70 ,
V_62 , V_69 ) ;
if ( ! V_55 )
return - V_27 ;
F_43 ( & V_55 -> V_63 , & V_71 ,
V_72 , V_73 ) ;
break;
default:
V_33 = - V_42 ;
break;
}
if ( V_33 )
return V_33 ;
V_56 = F_42 ( & V_55 -> V_63 , & V_74 ) ;
* V_56 = * V_51 ;
F_44 ( V_55 ) ;
V_55 -> V_75 = V_76 ;
V_55 -> V_77 = V_78 ;
F_45 ( V_55 ) ;
F_46 ( & exp -> V_16 -> V_79 . V_80 ) ;
V_33 = F_47 ( V_55 ) ;
F_48 ( & exp -> V_16 -> V_79 . V_80 ) ;
if ( V_33 )
goto V_81;
if ( V_52 == V_60 ) {
V_56 = F_49 ( & V_55 -> V_63 , & V_74 ) ;
if ( ! V_56 ) {
V_33 = - V_82 ;
goto V_81;
}
* V_51 = * V_56 ;
}
V_81:
if ( V_33 || ! V_54 ) {
F_50 ( V_55 ) ;
V_55 = NULL ;
}
if ( V_54 )
* V_54 = V_55 ;
return V_33 ;
}
int F_51 ( struct V_1 * V_2 , T_1 V_3 , T_4 * V_83 ,
T_3 V_84 , const struct V_85 * V_86 )
{
struct V_50 V_87 = { 0 } ;
struct V_5 * V_6 ;
int V_33 ;
V_33 = F_52 ( V_2 -> V_46 , V_3 , & V_87 ) ;
if ( V_33 == 0 ) {
* V_83 = V_87 . V_88 ;
return 0 ;
}
V_6 = F_9 ( V_2 , V_3 ) ;
F_2 ( V_6 ) ;
F_12 ( V_22 , L_12 ,
V_2 -> V_10 , V_3 , F_14 ( V_6 ) , V_6 -> V_9 ) ;
V_87 . V_89 = V_3 ;
F_53 ( & V_87 , V_84 ) ;
V_33 = F_39 ( V_6 -> V_15 , & V_87 , V_60 , NULL ) ;
if ( V_33 == 0 ) {
* V_83 = V_87 . V_88 ;
F_54 ( V_2 -> V_46 , & V_87 ) ;
}
return V_33 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 -> V_46 ) ;
}
static int T_5 F_57 ( void )
{
V_35 = F_24 ( V_90 ,
V_91 ,
NULL , NULL ) ;
return F_58 ( V_35 ) ;
}
static void T_6 F_59 ( void )
{
if ( ! F_25 ( V_35 ) )
F_29 ( & V_35 ) ;
}
