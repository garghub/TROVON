static int F_1 ( struct V_1 * V_2 , int * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 ;
T_1 V_7 ;
V_6 = F_2 ( V_2 -> V_8 , & V_7 ) ;
if ( V_6 )
return V_6 ;
F_3 ( V_5 -> V_9 . V_10 , L_1 , V_7 ) ;
* V_3 = ! ( V_7 & V_2 -> V_11 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( V_2 -> V_12 , 0 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_5 ( V_14 , 0 , V_13 ) ;
F_5 ( V_15 , 0 , V_13 ) ;
return 0 ;
}
static T_2 F_7 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_3 = 0 ;
int V_6 ;
V_6 = F_1 ( V_2 , & V_3 ) ;
if ( V_6 < 0 ) {
F_8 ( V_5 -> V_9 . V_10 ,
L_2 , V_6 ) ;
} else {
F_9 ( V_5 , V_18 , V_19 , V_3 ) ;
F_10 ( V_5 ) ;
}
F_4 ( V_2 ) ;
return V_20 ;
}
static int F_11 ( struct V_21 * V_22 )
{
const struct V_23 * V_24 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
int V_16 = F_12 ( V_22 , 0 ) ;
int error ;
V_24 = F_13 ( V_25 ) ;
if ( ! V_24 )
return - V_26 ;
if ( V_16 < 0 )
return - V_27 ;
V_5 = F_14 ( & V_22 -> V_9 ) ;
if ( ! V_5 )
return - V_28 ;
V_5 -> V_29 = V_22 -> V_29 ;
V_5 -> V_30 = L_3 ;
V_5 -> V_24 . V_31 = V_32 ;
V_5 -> V_9 . V_10 = & V_22 -> V_9 ;
F_15 ( V_5 , V_18 , V_19 ) ;
V_2 = (struct V_1 * ) V_24 -> V_33 ;
if ( ! V_2 )
return - V_34 ;
V_2 -> V_9 = & V_22 -> V_9 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_5 = V_5 ;
if ( V_2 -> V_35 ) {
error = V_2 -> V_35 ( V_2 ) ;
if ( error )
return error ;
}
error = F_16 ( & V_22 -> V_9 , V_16 , NULL , F_7 ,
V_36 , V_37 , V_2 ) ;
if ( error ) {
F_8 ( & V_22 -> V_9 ,
L_4 , V_16 ) ;
return error ;
}
error = F_17 ( V_5 ) ;
if ( error ) {
F_8 ( & V_22 -> V_9 ,
L_5 , error ) ;
return error ;
}
F_18 ( V_22 , V_2 ) ;
error = F_4 ( V_2 ) ;
if ( error ) {
F_8 ( & V_22 -> V_9 ,
L_6 ,
error ) ;
return error ;
}
F_19 ( & V_22 -> V_9 , true ) ;
F_20 ( & V_22 -> V_9 , V_16 ) ;
return 0 ;
}
static int F_21 ( struct V_21 * V_22 )
{
F_22 ( & V_22 -> V_9 ) ;
F_19 ( & V_22 -> V_9 , false ) ;
return 0 ;
}
