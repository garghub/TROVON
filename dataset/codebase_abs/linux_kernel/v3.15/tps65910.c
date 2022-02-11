static int F_1 ( struct V_1 * V_1 , int V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
static struct V_6 * V_7 ;
if ( ! V_2 ) {
F_2 ( V_1 -> V_8 , L_1 ) ;
return - V_9 ;
}
if ( ! V_4 ) {
F_2 ( V_1 -> V_8 , L_2 ) ;
return - V_9 ;
}
switch ( F_3 ( V_1 ) ) {
case V_10 :
V_7 = & V_11 ;
break;
case V_12 :
V_7 = & V_13 ;
break;
}
V_1 -> V_14 = V_2 ;
V_5 = F_4 ( V_1 -> V_15 , V_1 -> V_14 ,
V_16 , V_4 -> V_17 ,
V_7 , & V_1 -> V_18 ) ;
if ( V_5 < 0 ) {
F_2 ( V_1 -> V_8 , L_3 , V_5 ) ;
V_1 -> V_14 = 0 ;
}
return V_5 ;
}
static int F_5 ( struct V_1 * V_1 )
{
if ( V_1 -> V_14 > 0 )
F_6 ( V_1 -> V_14 , V_1 -> V_18 ) ;
return 0 ;
}
static bool F_7 ( struct V_19 * V_8 , unsigned int V_20 )
{
struct V_1 * V_1 = F_8 ( V_8 ) ;
if ( ( V_20 >= V_21 ) && ( V_20 <= V_22 ) ) {
if ( F_3 ( V_1 ) == V_10 )
if ( ( V_20 == V_23 ) ||
( V_20 == V_24 ) )
return true ;
return false ;
}
return true ;
}
static int F_9 ( struct V_1 * V_1 ,
struct V_25 * V_26 )
{
int V_5 ;
if ( ! V_26 -> V_27 )
return 0 ;
V_5 = F_10 ( V_1 , V_28 ,
V_29 ) ;
if ( V_5 < 0 ) {
F_11 ( V_1 -> V_8 , L_4 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 ,
struct V_25 * V_26 )
{
struct V_19 * V_8 = NULL ;
int V_5 = 0 ;
V_8 = V_1 -> V_8 ;
if ( ! V_26 -> V_30 )
return 0 ;
V_5 = F_13 ( V_1 , V_28 ,
V_31 ) ;
if ( V_5 < 0 ) {
F_11 ( V_8 , L_5 , V_5 ) ;
goto V_32;
}
if ( ! V_26 -> V_33 )
return 0 ;
if ( V_26 -> V_33 -> V_34 ) {
V_5 = F_13 ( V_1 ,
V_35 ,
V_36 ) ;
if ( V_5 < 0 ) {
F_11 ( V_8 , L_6 , V_5 ) ;
goto V_37;
}
}
if ( V_26 -> V_33 -> V_38 ) {
V_5 = F_13 ( V_1 ,
V_35 ,
V_39 ) ;
if ( V_5 < 0 ) {
F_11 ( V_8 , L_7 , V_5 ) ;
goto V_37;
}
}
if ( V_26 -> V_33 -> V_40 ) {
V_5 = F_13 ( V_1 ,
V_35 ,
V_41 ) ;
if ( V_5 < 0 ) {
F_11 ( V_8 , L_8 , V_5 ) ;
goto V_37;
}
}
return 0 ;
V_37:
F_10 ( V_1 , V_28 ,
V_31 ) ;
V_32:
return V_5 ;
}
static struct V_25 * F_14 ( struct V_42 * V_43 ,
int * V_44 )
{
struct V_45 * V_46 = V_43 -> V_8 . V_47 ;
struct V_25 * V_48 ;
unsigned int V_49 ;
const struct V_50 * V_51 ;
int V_5 = 0 ;
V_51 = F_15 ( V_52 , & V_43 -> V_8 ) ;
if ( ! V_51 ) {
F_11 ( & V_43 -> V_8 , L_9 ) ;
return NULL ;
}
* V_44 = ( int ) V_51 -> V_53 ;
V_48 = F_16 ( & V_43 -> V_8 , sizeof( * V_48 ) ,
V_54 ) ;
if ( ! V_48 ) {
F_11 ( & V_43 -> V_8 , L_10 ) ;
return NULL ;
}
V_5 = F_17 ( V_46 , L_11 , & V_49 ) ;
if ( ! V_5 )
V_48 -> V_55 = V_49 ;
V_5 = F_17 ( V_46 , L_12 , & V_49 ) ;
if ( ! V_5 )
V_48 -> V_56 = V_49 ;
V_49 = F_18 ( V_46 , L_13 ) ;
V_48 -> V_27 = V_49 ;
V_48 -> V_2 = V_43 -> V_2 ;
V_48 -> V_17 = - 1 ;
V_48 -> V_57 = F_18 ( V_46 ,
L_14 ) ;
return V_48 ;
}
static inline
struct V_25 * F_14 ( struct V_42 * V_43 ,
int * V_44 )
{
return NULL ;
}
static void F_19 ( void )
{
struct V_1 * V_1 ;
V_1 = F_8 ( & V_58 -> V_8 ) ;
if ( F_13 ( V_1 , V_28 ,
V_59 ) < 0 )
return;
F_10 ( V_1 , V_28 ,
V_60 ) ;
}
static int F_20 ( struct V_42 * V_61 ,
const struct V_62 * V_63 )
{
struct V_1 * V_1 ;
struct V_25 * V_64 ;
struct V_25 * V_65 = NULL ;
struct V_3 * V_66 ;
int V_5 = 0 ;
int V_44 = V_63 -> V_67 ;
V_64 = F_21 ( & V_61 -> V_8 ) ;
if ( ! V_64 && V_61 -> V_8 . V_47 ) {
V_64 = F_14 ( V_61 , & V_44 ) ;
V_65 = V_64 ;
}
if ( ! V_64 )
return - V_9 ;
V_66 = F_16 ( & V_61 -> V_8 , sizeof( * V_66 ) , V_54 ) ;
if ( V_66 == NULL )
return - V_68 ;
V_1 = F_16 ( & V_61 -> V_8 , sizeof( * V_1 ) , V_54 ) ;
if ( V_1 == NULL )
return - V_68 ;
V_1 -> V_69 = V_65 ;
F_22 ( V_61 , V_1 ) ;
V_1 -> V_8 = & V_61 -> V_8 ;
V_1 -> V_42 = V_61 ;
V_1 -> V_63 = V_44 ;
V_1 -> V_15 = F_23 ( V_61 , & V_70 ) ;
if ( F_24 ( V_1 -> V_15 ) ) {
V_5 = F_25 ( V_1 -> V_15 ) ;
F_11 ( & V_61 -> V_8 , L_15 , V_5 ) ;
return V_5 ;
}
V_66 -> V_2 = V_64 -> V_2 ;
V_66 -> V_17 = V_64 -> V_17 ;
F_1 ( V_1 , V_66 -> V_2 , V_66 ) ;
F_9 ( V_1 , V_64 ) ;
F_12 ( V_1 , V_64 ) ;
if ( V_64 -> V_57 && ! V_71 ) {
V_58 = V_61 ;
V_71 = F_19 ;
}
V_5 = F_26 ( V_1 -> V_8 , - 1 ,
V_72 , F_27 ( V_72 ) ,
NULL , 0 ,
F_28 ( V_1 -> V_18 ) ) ;
if ( V_5 < 0 ) {
F_11 ( & V_61 -> V_8 , L_16 , V_5 ) ;
F_5 ( V_1 ) ;
return V_5 ;
}
return V_5 ;
}
static int F_29 ( struct V_42 * V_61 )
{
struct V_1 * V_1 = F_30 ( V_61 ) ;
F_5 ( V_1 ) ;
F_31 ( V_1 -> V_8 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_73 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_73 ) ;
}
