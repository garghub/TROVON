static void F_1 ( void * V_1 , int V_2 , unsigned char * V_3 )
{
struct V_4 * V_5 = V_1 ;
if ( V_2 == 4 ) {
F_2 ( V_5 -> V_6 , V_7 ,
F_3 ( ( V_8 * ) & V_3 [ 2 ] ) ) ;
F_2 ( V_5 -> V_6 , V_9 ,
F_3 ( ( V_8 * ) & V_3 [ 0 ] ) ) ;
F_4 ( V_5 -> V_6 , V_10 , 1 ) ;
F_5 ( V_5 -> V_6 ) ;
} else if ( V_2 == 0 ) {
F_2 ( V_5 -> V_6 , V_7 , 0 ) ;
F_2 ( V_5 -> V_6 , V_9 , 0 ) ;
F_4 ( V_5 -> V_6 , V_10 , 0 ) ;
F_5 ( V_5 -> V_6 ) ;
}
}
static void F_6 ( struct V_4 * V_5 , bool V_11 )
{
struct V_12 * V_13 = V_5 -> V_13 ;
F_7 ( & V_13 -> V_14 ) ;
if ( V_11 ) {
V_13 -> V_5 = F_1 ;
V_13 -> V_15 = V_5 ;
} else {
V_13 -> V_5 = NULL ;
V_13 -> V_15 = NULL ;
}
F_8 ( & V_5 -> V_13 -> V_14 ) ;
}
static int F_9 ( struct V_16 * V_6 )
{
struct V_4 * V_5 = F_10 ( V_6 ) ;
F_6 ( V_5 , true ) ;
return 0 ;
}
static void F_11 ( struct V_16 * V_6 )
{
struct V_4 * V_5 = F_10 ( V_6 ) ;
F_6 ( V_5 , false ) ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_12 * V_13 = F_13 ( V_18 -> V_19 . V_20 ) ;
struct V_4 * V_5 ;
int error ;
V_5 = F_14 ( & V_18 -> V_19 , sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
V_5 -> V_13 = V_13 ;
V_5 -> V_6 = F_15 ( & V_18 -> V_19 ) ;
if ( ! V_5 -> V_6 ) {
F_16 ( & V_18 -> V_19 , L_1 ) ;
return - V_22 ;
}
V_5 -> V_6 -> V_23 = L_2 ;
V_5 -> V_6 -> V_24 = F_9 ;
V_5 -> V_6 -> V_25 = F_11 ;
F_17 ( V_5 -> V_6 , V_5 ) ;
F_18 ( V_5 -> V_6 , V_26 , V_10 ) ;
F_18 ( V_5 -> V_6 , V_27 , V_7 ) ;
F_18 ( V_5 -> V_6 , V_27 , V_9 ) ;
F_19 ( V_5 -> V_6 , V_7 , 0 , 1023 , 0 , 0 ) ;
F_19 ( V_5 -> V_6 , V_9 , 0 , 1023 , 0 , 0 ) ;
error = F_20 ( V_5 -> V_6 ) ;
if ( error ) {
F_16 ( & V_18 -> V_19 , L_3 ) ;
return error ;
}
F_21 ( V_18 , V_5 ) ;
F_22 ( & V_18 -> V_19 , L_4 ) ;
return 0 ;
}
static int T_1 F_23 ( struct V_28 * V_19 )
{
struct V_4 * V_5 = F_13 ( V_19 ) ;
F_6 ( V_5 , false ) ;
return 0 ;
}
static int T_1 F_24 ( struct V_28 * V_19 )
{
struct V_4 * V_5 = F_13 ( V_19 ) ;
struct V_16 * V_6 = V_5 -> V_6 ;
F_25 ( & V_6 -> V_29 ) ;
if ( V_6 -> V_30 )
F_6 ( V_5 , true ) ;
F_26 ( & V_6 -> V_29 ) ;
return 0 ;
}
