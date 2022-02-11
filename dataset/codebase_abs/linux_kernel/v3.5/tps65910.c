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
struct V_1 * V_2 = NULL ;
int V_12 = 0 ;
V_2 = V_4 -> V_2 ;
if ( ! V_11 -> V_13 )
return 0 ;
V_12 = F_5 ( V_4 , V_14 ,
V_15 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_1 , V_12 ) ;
goto V_16;
}
if ( ! V_11 -> V_17 )
return 0 ;
if ( V_11 -> V_17 -> V_18 ) {
V_12 = F_5 ( V_4 ,
V_19 ,
V_20 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_2 , V_12 ) ;
goto V_21;
}
}
if ( V_11 -> V_17 -> V_22 ) {
V_12 = F_5 ( V_4 ,
V_19 ,
V_23 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_3 , V_12 ) ;
goto V_21;
}
}
if ( V_11 -> V_17 -> V_24 ) {
V_12 = F_5 ( V_4 ,
V_19 ,
V_25 ) ;
if ( V_12 < 0 ) {
F_6 ( V_2 , L_4 , V_12 ) ;
goto V_21;
}
}
return 0 ;
V_21:
F_7 ( V_4 , V_14 ,
V_15 ) ;
V_16:
return V_12 ;
}
static struct V_10 * F_8 ( struct V_26 * V_27 ,
int * V_28 )
{
struct V_29 * V_30 = V_27 -> V_2 . V_31 ;
struct V_10 * V_32 ;
unsigned int V_33 ;
const struct V_34 * V_35 ;
int V_12 = 0 ;
V_35 = F_9 ( V_36 , & V_27 -> V_2 ) ;
if ( ! V_35 ) {
F_6 ( & V_27 -> V_2 , L_5 ) ;
return NULL ;
}
* V_28 = ( int ) V_35 -> V_37 ;
V_32 = F_10 ( & V_27 -> V_2 , sizeof( * V_32 ) ,
V_38 ) ;
if ( ! V_32 ) {
F_6 ( & V_27 -> V_2 , L_6 ) ;
return NULL ;
}
V_12 = F_11 ( V_30 , L_7 , & V_33 ) ;
if ( ! V_12 )
V_32 -> V_39 = V_33 ;
else if ( * V_28 == V_40 )
F_12 ( & V_27 -> V_2 , L_8 ) ;
V_12 = F_11 ( V_30 , L_9 , & V_33 ) ;
if ( ! V_12 )
V_32 -> V_41 = V_33 ;
else if ( * V_28 == V_40 )
F_12 ( & V_27 -> V_2 , L_10 ) ;
V_32 -> V_42 = V_27 -> V_42 ;
V_32 -> V_43 = - 1 ;
return V_32 ;
}
static inline
struct V_10 * F_8 ( struct V_26 * V_27 ,
int * V_28 )
{
return NULL ;
}
static T_1 int F_13 ( struct V_26 * V_44 ,
const struct V_45 * V_46 )
{
struct V_4 * V_4 ;
struct V_10 * V_47 ;
struct V_10 * V_48 = NULL ;
struct V_49 * V_50 ;
int V_12 = 0 ;
int V_28 = V_46 -> V_51 ;
V_47 = F_14 ( & V_44 -> V_2 ) ;
if ( ! V_47 && V_44 -> V_2 . V_31 ) {
V_47 = F_8 ( V_44 , & V_28 ) ;
V_48 = V_47 ;
}
if ( ! V_47 )
return - V_52 ;
V_50 = F_10 ( & V_44 -> V_2 , sizeof( * V_50 ) , V_38 ) ;
if ( V_50 == NULL )
return - V_53 ;
V_4 = F_10 ( & V_44 -> V_2 , sizeof( * V_4 ) , V_38 ) ;
if ( V_4 == NULL )
return - V_53 ;
V_4 -> V_54 = V_48 ;
F_15 ( V_44 , V_4 ) ;
V_4 -> V_2 = & V_44 -> V_2 ;
V_4 -> V_26 = V_44 ;
V_4 -> V_46 = V_28 ;
F_16 ( & V_4 -> V_55 ) ;
V_4 -> V_56 = F_17 ( V_44 , & V_57 ) ;
if ( F_18 ( V_4 -> V_56 ) ) {
V_12 = F_19 ( V_4 -> V_56 ) ;
F_6 ( & V_44 -> V_2 , L_11 , V_12 ) ;
return V_12 ;
}
V_12 = F_20 ( V_4 -> V_2 , - 1 ,
V_58 , F_21 ( V_58 ) ,
NULL , 0 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_44 -> V_2 , L_12 , V_12 ) ;
return V_12 ;
}
V_50 -> V_42 = V_47 -> V_42 ;
V_50 -> V_43 = V_47 -> V_43 ;
F_22 ( V_4 , V_50 -> V_42 , V_50 ) ;
F_4 ( V_4 , V_47 ) ;
return V_12 ;
}
static T_2 int F_23 ( struct V_26 * V_44 )
{
struct V_4 * V_4 = F_24 ( V_44 ) ;
F_25 ( V_4 ) ;
F_26 ( V_4 -> V_2 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_59 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_59 ) ;
}
