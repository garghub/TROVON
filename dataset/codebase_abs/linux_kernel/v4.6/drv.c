static T_1 F_1 ( struct V_1 * V_2 , union V_3 * V_4 )
{
union V_3 * V_5 , * V_6 , * V_7 ;
if ( V_4 -> type != V_8 ||
V_4 -> V_9 . V_10 != 2 ||
V_4 -> V_9 . V_11 [ 0 ] . type != V_12 ||
V_4 -> V_9 . V_11 [ 0 ] . integer . V_13 != 0 ) {
F_2 ( V_2 , L_1 ) ;
return 0 ;
}
V_5 = & V_4 -> V_9 . V_11 [ 1 ] ;
if ( V_5 -> type != V_8 ||
V_5 -> V_9 . V_10 < 2 ||
V_5 -> V_9 . V_11 [ 0 ] . type != V_12 ||
V_5 -> V_9 . V_11 [ 1 ] . type != V_12 ) {
F_2 ( V_2 , L_2 ) ;
return 0 ;
}
V_6 = & V_5 -> V_9 . V_11 [ 0 ] ;
V_7 = & V_5 -> V_9 . V_11 [ 1 ] ;
if ( ! ( V_6 -> integer . V_13 & V_14 ) ) {
F_3 ( V_2 , L_3 ) ;
return 0 ;
}
return V_7 -> integer . V_13 ;
}
static void F_4 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
T_2 V_17 ;
T_2 V_18 ;
struct V_19 V_4 = { V_20 , NULL } ;
T_3 V_21 ;
V_17 = F_5 ( & V_16 -> V_22 ) ;
if ( ! V_17 ) {
F_3 ( V_2 ,
L_4 ) ;
return;
}
V_21 = F_6 ( V_17 , ( V_23 ) V_24 , & V_18 ) ;
if ( F_7 ( V_21 ) ) {
F_3 ( V_2 , L_5 ) ;
return;
}
V_21 = F_8 ( V_18 , NULL , NULL , & V_4 ) ;
if ( F_7 ( V_21 ) ) {
F_2 ( V_2 , L_6 , V_21 ) ;
return;
}
V_2 -> V_25 = F_1 ( V_2 , V_4 . V_26 ) ;
F_3 ( V_2 , L_7 ,
V_2 -> V_25 ) ;
F_9 ( V_4 . V_26 ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_15 * V_16 ) {}
static int F_10 ( struct V_15 * V_16 , const struct V_27 * V_28 )
{
const struct V_29 * V_30 = (struct V_29 * ) ( V_28 -> V_31 ) ;
const struct V_29 * T_4 V_32 = NULL ;
struct V_1 * V_1 ;
struct V_33 * V_34 ;
int V_35 ;
V_1 = F_11 ( V_16 , V_28 , V_30 ) ;
if ( F_12 ( V_1 ) )
return F_13 ( V_1 ) ;
#if F_14 ( V_36 )
if ( V_30 == & V_37 )
T_4 = & V_38 ;
else if ( V_30 == & V_39 )
T_4 = & V_40 ;
else if ( V_30 == & V_41 )
T_4 = & V_42 ;
if ( T_4 &&
( V_1 -> V_43 & V_44 ) == V_45 ) {
V_30 = T_4 ;
V_1 -> V_30 = T_4 ;
}
#endif
F_15 ( V_16 , V_1 ) ;
V_34 = F_16 ( V_1 ) ;
V_34 -> V_46 = F_17 ( V_1 , V_30 ) ;
if ( F_12 ( V_34 -> V_46 ) ) {
V_35 = F_13 ( V_34 -> V_46 ) ;
goto V_47;
}
F_4 ( V_1 , V_16 ) ;
V_35 = F_18 ( V_1 ) ;
if ( V_35 )
goto V_48;
if ( V_1 -> V_49 != V_50 ) {
F_19 ( & V_16 -> V_22 ) ;
F_20 ( & V_16 -> V_22 ,
V_51 . V_52 ) ;
F_21 ( & V_16 -> V_22 ) ;
F_22 ( & V_16 -> V_22 ) ;
}
V_34 -> V_53 = 1 ;
return 0 ;
V_48:
F_23 ( V_34 -> V_46 ) ;
V_47:
F_24 ( V_1 ) ;
return V_35 ;
}
static void F_25 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_26 ( V_16 ) ;
struct V_33 * V_34 = F_16 ( V_2 ) ;
if ( V_2 -> V_49 != V_50 ) {
F_27 ( V_2 -> V_22 ) ;
}
F_23 ( V_34 -> V_46 ) ;
F_24 ( V_2 ) ;
}
static int F_28 ( struct V_54 * V_54 )
{
return 0 ;
}
static int F_29 ( struct V_54 * V_54 )
{
struct V_15 * V_16 = F_30 ( V_54 ) ;
struct V_1 * V_2 = F_26 ( V_16 ) ;
struct V_33 * V_34 = F_16 ( V_2 ) ;
bool V_55 ;
F_31 ( V_16 , V_56 , 0x00 ) ;
if ( ! V_2 -> V_57 )
return 0 ;
F_32 ( V_2 ) ;
V_55 = F_33 ( V_2 ) ;
F_34 ( & V_34 -> V_58 ) ;
F_35 ( V_2 , V_55 ) ;
F_36 ( & V_34 -> V_58 ) ;
return 0 ;
}
int F_37 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_16 ( V_2 ) ;
int V_35 ;
if ( F_38 ( V_59 , & V_2 -> V_21 ) )
return 0 ;
F_39 ( V_60 , & V_2 -> V_21 ) ;
V_35 = F_40 ( V_2 -> V_57 ) ;
if ( V_35 == 1 ) {
F_41 ( V_2 , L_8 ) ;
F_42 ( V_60 , & V_2 -> V_21 ) ;
return - V_61 ;
}
if ( V_35 )
goto V_62;
V_35 = F_43 ( V_34 -> V_63 ,
F_38 ( V_64 , & V_2 -> V_21 ) ,
F_44 ( V_65 ) ) ;
if ( ! V_35 ) {
F_2 ( V_2 , L_9 ) ;
V_35 = - V_66 ;
goto V_62;
}
F_42 ( V_60 , & V_2 -> V_21 ) ;
return 0 ;
V_62:
F_42 ( V_60 , & V_2 -> V_21 ) ;
F_45 ( V_2 ) ;
return V_35 ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_16 ( V_2 ) ;
int V_35 ;
if ( ! F_38 ( V_64 , & V_2 -> V_21 ) )
return 0 ;
V_35 = F_47 ( V_2 -> V_57 ) ;
if ( V_35 )
goto V_62;
V_35 = F_43 ( V_34 -> V_63 ,
! F_38 ( V_64 , & V_2 -> V_21 ) ,
F_44 ( V_65 ) ) ;
if ( ! V_35 ) {
F_2 ( V_2 , L_10 ) ;
V_35 = - V_66 ;
goto V_62;
}
return 0 ;
V_62:
F_42 ( V_64 , & V_2 -> V_21 ) ;
F_45 ( V_2 ) ;
return V_35 ;
}
static int F_48 ( struct V_54 * V_54 )
{
struct V_15 * V_16 = F_30 ( V_54 ) ;
struct V_1 * V_2 = F_26 ( V_16 ) ;
int V_35 ;
F_41 ( V_2 , L_11 ) ;
if ( F_38 ( V_67 , & V_2 -> V_21 ) ) {
V_35 = F_37 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
}
V_2 -> V_68 = V_69 ;
F_49 ( V_2 , false , false ) ;
return 0 ;
}
static int F_50 ( struct V_54 * V_54 )
{
struct V_15 * V_16 = F_30 ( V_54 ) ;
struct V_1 * V_2 = F_26 ( V_16 ) ;
enum V_70 V_71 ;
F_41 ( V_2 , L_12 ) ;
F_51 ( V_2 , & V_71 , false , false ) ;
if ( F_38 ( V_67 , & V_2 -> V_21 ) )
return F_46 ( V_2 ) ;
return 0 ;
}
static int F_52 ( struct V_54 * V_54 )
{
struct V_15 * V_16 = F_30 ( V_54 ) ;
struct V_1 * V_2 = F_26 ( V_16 ) ;
F_41 ( V_2 , L_13 ) ;
V_2 -> V_72 = true ;
F_53 ( V_54 ) ;
return 0 ;
}
static void F_54 ( struct V_54 * V_54 )
{
struct V_15 * V_16 = F_30 ( V_54 ) ;
struct V_1 * V_2 = F_26 ( V_16 ) ;
F_41 ( V_2 , L_14 ) ;
V_2 -> V_72 = false ;
}
int T_5 F_55 ( void )
{
int V_35 ;
V_35 = F_56 ( & V_73 ) ;
if ( V_35 )
F_57 ( L_15 ) ;
return V_35 ;
}
void F_58 ( void )
{
F_59 ( & V_73 ) ;
}
