static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 +
V_5 ) ;
return ! ( V_3 & V_6 ) ;
}
static void F_3 ( struct V_7 * V_8 )
{
struct V_1 * V_2 =
F_4 ( V_8 , struct V_1 , V_8 . V_8 ) ;
if ( F_1 ( V_2 ) ) {
F_5 ( & V_2 -> V_8 ,
F_6 ( V_9 ) ) ;
} else {
F_7 ( V_2 -> V_10 , V_11 , V_12 , 0 ) ;
F_8 ( V_2 -> V_10 ) ;
}
}
static T_2 F_9 ( int V_13 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
T_1 V_15 ;
V_15 = F_2 ( V_2 -> V_4 +
V_16 ) ;
F_10 ( V_15 & ~ V_6 ,
V_2 -> V_4 + V_16 ) ;
F_7 ( V_2 -> V_10 , V_11 , V_12 , 1 ) ;
F_8 ( V_2 -> V_10 ) ;
F_5 ( & V_2 -> V_8 ,
F_6 ( V_9 ) ) ;
return V_17 ;
}
static void F_11 ( struct V_1 * V_2 ,
bool V_18 )
{
T_1 V_19 ;
V_19 = F_2 ( V_2 -> V_4 + V_20 ) ;
if ( V_18 )
V_19 |= V_6 ;
else
V_19 &= ~ V_6 ;
F_10 ( V_19 , V_2 -> V_4 + V_20 ) ;
}
static int F_12 ( struct V_21 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
F_11 ( V_2 , true ) ;
return 0 ;
}
static void F_14 ( struct V_21 * V_10 )
{
struct V_1 * V_2 = F_13 ( V_10 ) ;
F_11 ( V_2 , false ) ;
F_15 ( & V_2 -> V_8 ) ;
}
static int F_16 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = V_23 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_13 ;
int error ;
V_2 = F_17 ( & V_23 -> V_26 , sizeof( struct V_1 ) ,
V_28 ) ;
if ( ! V_2 ) {
F_18 ( & V_23 -> V_26 , L_1 ) ;
return - V_29 ;
}
error = F_19 ( V_25 , L_2 , & V_2 -> V_4 ) ;
if ( error ) {
F_20 ( & V_23 -> V_26 ,
L_3 ) ;
return error ;
}
V_2 -> V_10 = F_21 ( & V_23 -> V_26 ) ;
if ( ! V_2 -> V_10 )
return - V_29 ;
V_2 -> V_10 -> V_30 = L_4 ;
V_2 -> V_10 -> V_31 = L_5 ;
V_2 -> V_10 -> V_32 [ 0 ] = F_22 ( V_11 ) ;
F_23 ( V_2 -> V_10 , V_11 , V_12 ) ;
F_24 ( & V_2 -> V_8 , F_3 ) ;
V_2 -> V_10 -> V_33 = F_12 ;
V_2 -> V_10 -> V_34 = F_14 ;
F_25 ( V_2 -> V_10 , V_2 ) ;
F_11 ( V_2 , false ) ;
V_13 = F_26 ( V_23 , 0 ) ;
error = F_27 ( & V_23 -> V_26 , V_13 ,
F_9 , 0 ,
L_6 , V_2 ) ;
if ( error ) {
F_20 ( & V_23 -> V_26 , L_7 ,
V_13 , error ) ;
return error ;
}
error = F_28 ( V_2 -> V_10 ) ;
if ( error ) {
F_20 ( & V_23 -> V_26 ,
L_8 ,
error ) ;
return error ;
}
F_29 ( & V_23 -> V_26 , V_2 ) ;
F_30 ( & V_23 -> V_26 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_22 * V_23 )
{
F_30 ( & V_23 -> V_26 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_35 * V_26 )
{
struct V_1 * V_2 = F_33 ( V_26 ) ;
struct V_21 * V_10 = V_2 -> V_10 ;
F_34 ( & V_10 -> V_36 ) ;
if ( V_10 -> V_37 )
F_11 ( V_2 , true ) ;
F_35 ( & V_10 -> V_36 ) ;
return 0 ;
}
