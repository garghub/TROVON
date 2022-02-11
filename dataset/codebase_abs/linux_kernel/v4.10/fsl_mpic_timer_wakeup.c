static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( & V_6 ) ;
if ( V_4 -> V_7 ) {
F_4 ( V_4 -> V_7 -> V_8 ) ;
F_5 ( V_4 -> V_7 ) ;
}
V_4 -> V_7 = NULL ;
F_6 ( & V_6 ) ;
}
static T_1 F_7 ( int V_8 , void * V_9 )
{
struct V_3 * V_4 = V_9 ;
F_8 ( & V_4 -> V_5 ) ;
return V_4 -> V_7 ? V_10 : V_11 ;
}
static T_2 F_9 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 V_18 ;
int V_19 = 0 ;
F_3 ( & V_6 ) ;
if ( V_20 -> V_7 ) {
F_10 ( V_20 -> V_7 , & V_18 ) ;
V_19 = V_18 . V_21 + 1 ;
}
F_6 ( & V_6 ) ;
return sprintf ( V_16 , L_1 , V_19 ) ;
}
static T_2 F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 ,
T_3 V_22 )
{
struct V_17 V_18 ;
int V_23 ;
V_18 . V_24 = 0 ;
if ( F_12 ( V_16 , 0 , & V_18 . V_21 ) )
return - V_25 ;
F_3 ( & V_6 ) ;
if ( V_20 -> V_7 ) {
F_4 ( V_20 -> V_7 -> V_8 ) ;
F_5 ( V_20 -> V_7 ) ;
V_20 -> V_7 = NULL ;
}
if ( ! V_18 . V_21 ) {
F_6 ( & V_6 ) ;
return V_22 ;
}
V_20 -> V_7 = F_13 ( F_7 ,
V_20 , & V_18 ) ;
if ( ! V_20 -> V_7 ) {
F_6 ( & V_6 ) ;
return - V_25 ;
}
V_23 = F_14 ( V_20 -> V_7 -> V_8 ) ;
if ( V_23 ) {
F_5 ( V_20 -> V_7 ) ;
V_20 -> V_7 = NULL ;
F_6 ( & V_6 ) ;
return V_23 ;
}
F_15 ( V_20 -> V_7 ) ;
F_6 ( & V_6 ) ;
return V_22 ;
}
static int T_4 F_16 ( void )
{
int V_23 ;
V_20 = F_17 ( sizeof( struct V_3 ) , V_26 ) ;
if ( ! V_20 )
return - V_27 ;
F_18 ( & V_20 -> V_5 , F_1 ) ;
V_23 = F_19 ( V_28 . V_29 , & V_30 ) ;
if ( V_23 )
F_20 ( V_20 ) ;
return V_23 ;
}
static void T_5 F_21 ( void )
{
F_22 ( V_28 . V_29 , & V_30 ) ;
F_3 ( & V_6 ) ;
if ( V_20 -> V_7 ) {
F_4 ( V_20 -> V_7 -> V_8 ) ;
F_5 ( V_20 -> V_7 ) ;
}
F_20 ( V_20 ) ;
F_6 ( & V_6 ) ;
}
