static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int error ;
if ( V_2 -> V_4 != V_3 ) {
error = V_3 ? F_2 ( V_2 -> V_5 ) :
F_3 ( V_2 -> V_5 ) ;
if ( error ) {
F_4 ( V_2 -> V_6 ,
L_1 ,
V_3 ? L_2 : L_3 , error ) ;
return error ;
}
V_2 -> V_4 = V_3 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
T_1 V_8 ;
unsigned int V_9 ;
int error ;
V_8 = ( T_1 ) ( V_2 -> V_10 - V_2 -> V_11 ) * V_7 ;
V_9 = ( unsigned int ) ( V_8 >> V_12 ) ;
error = F_6 ( V_2 -> V_5 ,
V_9 + V_2 -> V_11 ,
V_2 -> V_10 ) ;
if ( error ) {
F_4 ( V_2 -> V_6 , L_4 ,
V_9 + V_2 -> V_11 , error ) ;
return error ;
}
F_1 ( V_2 , ! ! V_7 ) ;
return 0 ;
}
static void F_7 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = F_8 ( V_14 ,
struct V_1 , V_14 ) ;
F_9 ( & V_2 -> V_15 ) ;
if ( ! V_2 -> V_16 )
F_5 ( V_2 , V_2 -> V_7 ) ;
F_10 ( & V_2 -> V_15 ) ;
}
static int F_11 ( struct V_17 * V_18 , void * V_19 ,
struct V_20 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
V_2 -> V_7 = V_21 -> V_22 . V_23 . V_24 ;
if ( ! V_2 -> V_7 )
V_2 -> V_7 = V_21 -> V_22 . V_23 . V_25 ;
F_13 ( & V_2 -> V_14 ) ;
return 0 ;
}
static void F_14 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
F_15 ( & V_2 -> V_14 ) ;
F_5 ( V_2 , 0 ) ;
}
static int T_2
F_16 ( struct V_26 * V_6 , struct V_1 * V_2 )
{
struct V_27 * V_28 ;
int error ;
V_28 = V_6 -> V_29 ;
if( ! V_28 ) {
F_4 ( V_6 , L_5 ) ;
return - V_30 ;
}
error = F_17 ( V_28 , L_6 , & V_2 -> V_10 ) ;
if ( error ) {
F_4 ( V_6 , L_7 ) ;
return error ;
}
error = F_17 ( V_28 , L_8 , & V_2 -> V_11 ) ;
if ( error ) {
F_4 ( V_6 , L_9 ) ;
return error ;
}
return 0 ;
}
static int F_18 ( struct V_31 * V_32 )
{
const struct V_33 * V_34 = F_19 ( & V_32 -> V_6 ) ;
struct V_1 * V_2 ;
struct V_17 * V_17 ;
int error ;
V_2 = F_20 ( & V_32 -> V_6 , sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
F_21 ( V_32 , V_2 ) ;
V_2 -> V_6 = & V_32 -> V_6 ;
F_22 ( & V_2 -> V_15 ) ;
F_23 ( & V_2 -> V_14 , F_7 ) ;
if ( V_34 ) {
V_2 -> V_10 = V_34 -> V_10 ;
V_2 -> V_11 = V_34 -> V_11 ;
} else if ( F_24 ( V_37 ) ) {
error = F_16 ( & V_32 -> V_6 , V_2 ) ;
if ( error )
return error ;
} else {
F_4 ( & V_32 -> V_6 , L_10 ) ;
return - V_30 ;
}
V_2 -> V_5 = F_25 ( & V_32 -> V_6 , L_11 ) ;
if ( F_26 ( V_2 -> V_5 ) ) {
F_4 ( & V_32 -> V_6 , L_12 ) ;
return F_27 ( V_2 -> V_5 ) ;
}
V_17 = F_28 ( & V_32 -> V_6 ) ;
if ( ! V_17 )
return - V_36 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_17 -> V_38 = L_13 ;
V_2 -> V_17 -> V_6 . V_39 = & V_32 -> V_6 ;
V_2 -> V_17 -> V_40 = F_14 ;
F_29 ( V_2 -> V_17 , V_2 ) ;
F_30 ( V_2 -> V_17 , V_41 , V_42 ) ;
error = F_31 ( V_17 , NULL ,
F_11 ) ;
if ( error ) {
F_4 ( & V_32 -> V_6 , L_14 ) ;
return error ;
}
error = F_32 ( V_2 -> V_17 ) ;
if ( error ) {
F_4 ( & V_32 -> V_6 , L_15 ) ;
return error ;
}
return 0 ;
}
static int T_2 F_33 ( struct V_26 * V_6 )
{
struct V_31 * V_32 = F_34 ( V_6 ) ;
struct V_1 * V_2 = F_35 ( V_32 ) ;
int error ;
error = F_36 ( & V_2 -> V_15 ) ;
if ( error )
return error ;
F_5 ( V_2 , 0 ) ;
V_2 -> V_16 = true ;
F_10 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int T_2 F_37 ( struct V_26 * V_6 )
{
struct V_31 * V_32 = F_34 ( V_6 ) ;
struct V_1 * V_2 = F_35 ( V_32 ) ;
unsigned int V_7 ;
F_9 ( & V_2 -> V_15 ) ;
V_2 -> V_16 = false ;
V_7 = F_38 ( V_2 -> V_7 ) ;
if ( V_7 )
F_5 ( V_2 , V_7 ) ;
F_10 ( & V_2 -> V_15 ) ;
return 0 ;
}
