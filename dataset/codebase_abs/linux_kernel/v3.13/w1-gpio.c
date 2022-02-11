static void F_1 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 )
F_2 ( V_4 -> V_5 ) ;
else
F_3 ( V_4 -> V_5 , 0 ) ;
}
static void F_4 ( void * V_1 , T_1 V_2 )
{
struct V_3 * V_4 = V_1 ;
F_5 ( V_4 -> V_5 , V_2 ) ;
}
static T_1 F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return F_7 ( V_4 -> V_5 ) ? 1 : 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_9 ( & V_7 -> V_8 ) ;
struct V_9 * V_10 = V_7 -> V_8 . V_11 ;
int V_12 ;
V_4 = F_10 ( & V_7 -> V_8 , sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
if ( F_11 ( V_10 , L_1 , NULL ) )
V_4 -> V_15 = 1 ;
V_12 = F_12 ( V_10 , 0 ) ;
if ( V_12 < 0 )
return V_12 ;
V_4 -> V_5 = V_12 ;
V_4 -> V_16 = F_12 ( V_10 , 1 ) ;
V_7 -> V_8 . V_17 = V_4 ;
return 0 ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_18 * V_19 ;
struct V_3 * V_4 ;
int V_20 ;
if ( F_14 () ) {
V_20 = F_8 ( V_7 ) ;
if ( V_20 < 0 ) {
F_15 ( & V_7 -> V_8 , L_2 ) ;
return V_20 ;
}
}
V_4 = F_9 ( & V_7 -> V_8 ) ;
if ( ! V_4 ) {
F_15 ( & V_7 -> V_8 , L_3 ) ;
return - V_21 ;
}
V_19 = F_10 ( & V_7 -> V_8 , sizeof( struct V_18 ) ,
V_13 ) ;
if ( ! V_19 ) {
F_15 ( & V_7 -> V_8 , L_4 ) ;
return - V_14 ;
}
V_20 = F_16 ( & V_7 -> V_8 , V_4 -> V_5 , L_5 ) ;
if ( V_20 ) {
F_15 ( & V_7 -> V_8 , L_6 ) ;
return V_20 ;
}
if ( F_17 ( V_4 -> V_16 ) ) {
V_20 = F_18 ( & V_7 -> V_8 ,
V_4 -> V_16 , V_22 ,
L_7 ) ;
if ( V_20 < 0 ) {
F_15 ( & V_7 -> V_8 , L_8
L_9 ) ;
return V_20 ;
}
}
V_19 -> V_1 = V_4 ;
V_19 -> V_23 = F_6 ;
if ( V_4 -> V_15 ) {
F_3 ( V_4 -> V_5 , 1 ) ;
V_19 -> V_24 = F_4 ;
} else {
F_2 ( V_4 -> V_5 ) ;
V_19 -> V_24 = F_1 ;
}
V_20 = F_19 ( V_19 ) ;
if ( V_20 ) {
F_15 ( & V_7 -> V_8 , L_10 ) ;
return V_20 ;
}
if ( V_4 -> V_25 )
V_4 -> V_25 ( 1 ) ;
if ( F_17 ( V_4 -> V_16 ) )
F_5 ( V_4 -> V_16 , 1 ) ;
F_20 ( V_7 , V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 )
{
struct V_18 * V_19 = F_22 ( V_7 ) ;
struct V_3 * V_4 = F_9 ( & V_7 -> V_8 ) ;
if ( V_4 -> V_25 )
V_4 -> V_25 ( 0 ) ;
if ( F_17 ( V_4 -> V_16 ) )
F_5 ( V_4 -> V_16 , 0 ) ;
F_23 ( V_19 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , T_2 V_26 )
{
struct V_3 * V_4 = F_9 ( & V_7 -> V_8 ) ;
if ( V_4 -> V_25 )
V_4 -> V_25 ( 0 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
struct V_3 * V_4 = F_9 ( & V_7 -> V_8 ) ;
if ( V_4 -> V_25 )
V_4 -> V_25 ( 1 ) ;
return 0 ;
}
