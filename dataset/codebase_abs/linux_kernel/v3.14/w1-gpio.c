static T_1 F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 ) {
V_4 -> V_5 = V_2 ;
} else {
if ( V_4 -> V_5 ) {
F_2 ( V_4 -> V_6 , 1 ) ;
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_4 -> V_6 ) ;
}
V_4 -> V_5 = 0 ;
}
return 0 ;
}
static void F_5 ( void * V_1 , T_1 V_7 )
{
struct V_3 * V_4 = V_1 ;
if ( V_7 )
F_4 ( V_4 -> V_6 ) ;
else
F_2 ( V_4 -> V_6 , 0 ) ;
}
static void F_6 ( void * V_1 , T_1 V_7 )
{
struct V_3 * V_4 = V_1 ;
F_7 ( V_4 -> V_6 , V_7 ) ;
}
static T_1 F_8 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
return F_9 ( V_4 -> V_6 ) ? 1 : 0 ;
}
static int F_10 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_11 ( & V_9 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_10 . V_13 ;
int V_14 ;
V_4 = F_12 ( & V_9 -> V_10 , sizeof( * V_4 ) , V_15 ) ;
if ( ! V_4 )
return - V_16 ;
if ( F_13 ( V_12 , L_1 , NULL ) )
V_4 -> V_17 = 1 ;
V_14 = F_14 ( V_12 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_4 -> V_6 = V_14 ;
V_4 -> V_18 = F_14 ( V_12 , 1 ) ;
V_9 -> V_10 . V_19 = V_4 ;
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_20 * V_21 ;
struct V_3 * V_4 ;
int V_22 ;
if ( F_16 () ) {
V_22 = F_10 ( V_9 ) ;
if ( V_22 < 0 ) {
F_17 ( & V_9 -> V_10 , L_2 ) ;
return V_22 ;
}
}
V_4 = F_11 ( & V_9 -> V_10 ) ;
if ( ! V_4 ) {
F_17 ( & V_9 -> V_10 , L_3 ) ;
return - V_23 ;
}
V_21 = F_12 ( & V_9 -> V_10 , sizeof( struct V_20 ) ,
V_15 ) ;
if ( ! V_21 ) {
F_17 ( & V_9 -> V_10 , L_4 ) ;
return - V_16 ;
}
V_22 = F_18 ( & V_9 -> V_10 , V_4 -> V_6 , L_5 ) ;
if ( V_22 ) {
F_17 ( & V_9 -> V_10 , L_6 ) ;
return V_22 ;
}
if ( F_19 ( V_4 -> V_18 ) ) {
V_22 = F_20 ( & V_9 -> V_10 ,
V_4 -> V_18 , V_24 ,
L_7 ) ;
if ( V_22 < 0 ) {
F_17 ( & V_9 -> V_10 , L_8
L_9 ) ;
return V_22 ;
}
}
V_21 -> V_1 = V_4 ;
V_21 -> V_25 = F_8 ;
if ( V_4 -> V_17 ) {
F_2 ( V_4 -> V_6 , 1 ) ;
V_21 -> V_26 = F_6 ;
} else {
F_4 ( V_4 -> V_6 ) ;
V_21 -> V_26 = F_5 ;
V_21 -> V_27 = F_1 ;
}
V_22 = F_21 ( V_21 ) ;
if ( V_22 ) {
F_17 ( & V_9 -> V_10 , L_10 ) ;
return V_22 ;
}
if ( V_4 -> V_28 )
V_4 -> V_28 ( 1 ) ;
if ( F_19 ( V_4 -> V_18 ) )
F_7 ( V_4 -> V_18 , 1 ) ;
F_22 ( V_9 , V_21 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 )
{
struct V_20 * V_21 = F_24 ( V_9 ) ;
struct V_3 * V_4 = F_11 ( & V_9 -> V_10 ) ;
if ( V_4 -> V_28 )
V_4 -> V_28 ( 0 ) ;
if ( F_19 ( V_4 -> V_18 ) )
F_7 ( V_4 -> V_18 , 0 ) ;
F_25 ( V_21 ) ;
return 0 ;
}
static int F_26 ( struct V_8 * V_9 , T_2 V_29 )
{
struct V_3 * V_4 = F_11 ( & V_9 -> V_10 ) ;
if ( V_4 -> V_28 )
V_4 -> V_28 ( 0 ) ;
return 0 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_3 * V_4 = F_11 ( & V_9 -> V_10 ) ;
if ( V_4 -> V_28 )
V_4 -> V_28 ( 1 ) ;
return 0 ;
}
