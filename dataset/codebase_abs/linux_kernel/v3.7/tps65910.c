static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
if ( ( V_3 >= V_5 ) && ( V_3 <= V_6 ) ) {
if ( F_3 ( V_4 ) == V_7 )
if ( ( V_3 == V_8 ) ||
( V_3 == V_9 ) )
return true ;
return false ;
}
return true ;
}
static int T_1 F_4 ( struct V_4 * V_4 ,
struct V_10 * V_11 )
{
int V_12 ;
if ( ! V_11 -> V_13 )
return 0 ;
V_12 = F_5 ( V_4 , V_14 ,
V_15 ) ;
if ( V_12 < 0 ) {
F_6 ( V_4 -> V_2 , L_1 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static int T_1 F_7 ( struct V_4 * V_4 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = NULL ;
int V_12 = 0 ;
V_2 = V_4 -> V_2 ;
if ( ! V_11 -> V_16 )
return 0 ;
V_12 = F_8 ( V_4 , V_14 ,
V_17 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_2 , V_12 ) ;
goto V_18;
}
if ( ! V_11 -> V_19 )
return 0 ;
if ( V_11 -> V_19 -> V_20 ) {
V_12 = F_8 ( V_4 ,
V_21 ,
V_22 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_3 , V_12 ) ;
goto V_23;
}
}
if ( V_11 -> V_19 -> V_24 ) {
V_12 = F_8 ( V_4 ,
V_21 ,
V_25 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_4 , V_12 ) ;
goto V_23;
}
}
if ( V_11 -> V_19 -> V_26 ) {
V_12 = F_8 ( V_4 ,
V_21 ,
V_27 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_5 , V_12 ) ;
goto V_23;
}
}
return 0 ;
V_23:
F_5 ( V_4 , V_14 ,
V_17 ) ;
V_18:
return V_12 ;
}
static struct V_10 * F_9 ( struct V_28 * V_29 ,
int * V_30 )
{
struct V_31 * V_32 = V_29 -> V_2 . V_33 ;
struct V_10 * V_34 ;
unsigned int V_35 ;
const struct V_36 * V_37 ;
int V_12 = 0 ;
V_37 = F_10 ( V_38 , & V_29 -> V_2 ) ;
if ( ! V_37 ) {
F_6 ( & V_29 -> V_2 , L_6 ) ;
return NULL ;
}
* V_30 = ( int ) V_37 -> V_39 ;
V_34 = F_11 ( & V_29 -> V_2 , sizeof( * V_34 ) ,
V_40 ) ;
if ( ! V_34 ) {
F_6 ( & V_29 -> V_2 , L_7 ) ;
return NULL ;
}
V_12 = F_12 ( V_32 , L_8 , & V_35 ) ;
if ( ! V_12 )
V_34 -> V_41 = V_35 ;
else if ( * V_30 == V_42 )
F_13 ( & V_29 -> V_2 , L_9 ) ;
V_12 = F_12 ( V_32 , L_10 , & V_35 ) ;
if ( ! V_12 )
V_34 -> V_43 = V_35 ;
else if ( * V_30 == V_42 )
F_13 ( & V_29 -> V_2 , L_11 ) ;
V_35 = F_14 ( V_32 , L_12 ) ;
V_34 -> V_13 = V_35 ;
V_34 -> V_44 = V_29 -> V_44 ;
V_34 -> V_45 = - 1 ;
V_34 -> V_46 = F_14 ( V_32 ,
L_13 ) ;
return V_34 ;
}
static inline
struct V_10 * F_9 ( struct V_28 * V_29 ,
int * V_30 )
{
return NULL ;
}
static void F_15 ( void )
{
struct V_4 * V_4 ;
V_4 = F_2 ( & V_47 -> V_2 ) ;
if ( F_8 ( V_4 , V_14 ,
V_48 ) < 0 )
return;
F_5 ( V_4 , V_14 ,
V_49 ) ;
}
static T_1 int F_16 ( struct V_28 * V_50 ,
const struct V_51 * V_52 )
{
struct V_4 * V_4 ;
struct V_10 * V_53 ;
struct V_10 * V_54 = NULL ;
struct V_55 * V_56 ;
int V_12 = 0 ;
int V_30 = V_52 -> V_57 ;
V_53 = F_17 ( & V_50 -> V_2 ) ;
if ( ! V_53 && V_50 -> V_2 . V_33 ) {
V_53 = F_9 ( V_50 , & V_30 ) ;
V_54 = V_53 ;
}
if ( ! V_53 )
return - V_58 ;
V_56 = F_11 ( & V_50 -> V_2 , sizeof( * V_56 ) , V_40 ) ;
if ( V_56 == NULL )
return - V_59 ;
V_4 = F_11 ( & V_50 -> V_2 , sizeof( * V_4 ) , V_40 ) ;
if ( V_4 == NULL )
return - V_59 ;
V_4 -> V_60 = V_54 ;
F_18 ( V_50 , V_4 ) ;
V_4 -> V_2 = & V_50 -> V_2 ;
V_4 -> V_28 = V_50 ;
V_4 -> V_52 = V_30 ;
F_19 ( & V_4 -> V_61 ) ;
V_4 -> V_62 = F_20 ( V_50 , & V_63 ) ;
if ( F_21 ( V_4 -> V_62 ) ) {
V_12 = F_22 ( V_4 -> V_62 ) ;
F_6 ( & V_50 -> V_2 , L_14 , V_12 ) ;
return V_12 ;
}
V_12 = F_23 ( V_4 -> V_2 , - 1 ,
V_64 , F_24 ( V_64 ) ,
NULL , 0 , NULL ) ;
if ( V_12 < 0 ) {
F_6 ( & V_50 -> V_2 , L_15 , V_12 ) ;
return V_12 ;
}
V_56 -> V_44 = V_53 -> V_44 ;
V_56 -> V_45 = V_53 -> V_45 ;
F_25 ( V_4 , V_56 -> V_44 , V_56 ) ;
F_4 ( V_4 , V_53 ) ;
F_7 ( V_4 , V_53 ) ;
if ( V_53 -> V_46 && ! V_65 ) {
V_47 = V_50 ;
V_65 = F_15 ;
}
return V_12 ;
}
static T_2 int F_26 ( struct V_28 * V_50 )
{
struct V_4 * V_4 = F_27 ( V_50 ) ;
F_28 ( V_4 ) ;
F_29 ( V_4 -> V_2 ) ;
return 0 ;
}
static int T_3 F_30 ( void )
{
return F_31 ( & V_66 ) ;
}
static void T_4 F_32 ( void )
{
F_33 ( & V_66 ) ;
}
