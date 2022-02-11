static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_7 ;
if ( ( V_3 && F_2 ( 1 , & V_5 -> V_8 ) == 1 ) ||
( ! V_3 && F_3 ( & V_5 -> V_8 ) ) ) {
V_7 = F_4 ( V_2 -> V_9 ) ;
V_2 -> V_9 -> V_10 = V_3 ;
if ( ! V_7 )
F_5 ( V_2 -> V_9 ) ;
}
return 0 ;
}
static int F_6 ( struct V_11 * V_9 ,
int V_12 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
if ( ! V_2 )
return 0 ;
return F_1 ( V_2 , V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_11 * V_9 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 = F_9 ( - V_17 ) ;
int V_18 = - V_17 ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_19 = 0 ;
V_19 |= V_20 ;
V_18 = F_10 ( V_2 , V_9 , 1 , V_19 ) ;
if ( V_18 )
goto V_21;
V_14 = V_5 -> V_14 ;
if ( V_2 -> V_12 )
V_16 = F_11 ( V_14 -> V_22 ,
& V_2 -> V_12 -> V_23 ,
1024 ,
F_6 ) ;
if ( F_12 ( V_16 ) ) {
V_18 = F_13 ( V_16 ) ;
F_14 ( V_2 , V_9 ) ;
goto V_21;
}
V_2 -> V_12 = NULL ;
V_5 -> V_16 = V_16 ;
V_21:
return V_18 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_11 * V_9 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_13 * V_14 = V_5 -> V_14 ;
if ( V_5 -> V_16 && V_5 -> V_16 -> V_24 )
V_5 -> V_16 -> V_24 ( V_14 -> V_22 ) ;
V_5 -> V_16 = NULL ;
F_14 ( V_2 , V_9 ) ;
}
static int F_16 ( struct V_11 * V_9 ,
T_1 V_25 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_13 * V_14 = V_5 -> V_14 ;
if ( V_14 == NULL ) {
V_18 = - V_17 ;
goto error;
}
V_18 = F_17 ( V_9 , V_25 ) ;
if ( V_18 < 0 )
goto error;
if ( V_9 == V_14 -> V_22 &&
V_5 -> V_16 &&
V_5 -> V_16 -> V_26 )
V_18 = V_5 -> V_16 -> V_26 ( V_9 , V_25 ) ;
if ( V_18 < 0 )
F_18 ( V_9 ) ;
error:
return V_18 ;
}
static int F_19 ( struct V_11 * V_9 )
{
int V_18 = 0 ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
bool V_27 ;
struct V_13 * V_14 = V_5 -> V_14 ;
V_27 =
( V_9 == V_14 -> V_22 &&
V_5 -> V_16 &&
V_5 -> V_16 -> V_28 ) ;
if ( V_27 )
V_18 = V_5 -> V_16 -> V_28 ( V_9 ) ;
if ( V_18 < 0 )
goto V_21;
V_18 = F_18 ( V_9 ) ;
if ( V_18 < 0 && V_27 )
V_5 -> V_16 -> V_26 ( V_9 , V_29 ) ;
V_21:
return V_18 ;
}
