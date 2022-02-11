static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned V_6 , V_7 , V_8 , V_9 ;
T_1 V_10 ;
V_10 = F_2 ( F_3 ( V_2 -> V_11 , V_3 ) ) ;
V_7 = V_10 ^ V_2 -> V_12 [ V_3 ] ;
V_2 -> V_12 [ V_3 ] = V_10 ;
for ( V_6 = 0 ; V_7 ; V_6 ++ , V_7 >>= 1 ) {
if ( V_7 & 1 ) {
V_8 = F_4 ( V_6 , V_3 ,
V_2 -> V_13 ) ;
V_9 = V_2 -> V_14 [ V_8 ] ;
F_5 ( V_5 , V_15 , V_16 , V_8 ) ;
F_6 ( V_5 , V_9 , V_10 & ( 1 << V_6 ) ) ;
}
}
}
static T_2 F_7 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_2 -> V_20 ; V_19 ++ )
F_1 ( V_2 , V_19 ) ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_10 ( V_2 -> V_5 ) ;
return V_21 ;
}
static int F_11 ( struct V_4 * V_22 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
int error ;
error = F_13 ( V_2 -> V_23 ) ;
if ( error )
return error ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_22 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_15 ( V_2 -> V_23 ) ;
}
static int F_16 ( struct V_24 * V_22 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = V_22 -> V_27 ;
T_3 V_28 = 0 , V_29 = 0 ;
int V_30 ;
V_30 = F_17 ( V_22 , & V_28 , & V_29 ) ;
if ( V_30 )
return V_30 ;
if ( V_28 != V_29 ) {
F_18 ( V_22 , L_1 ) ;
return - V_31 ;
}
V_2 -> V_20 = V_28 ;
V_2 -> V_13 = F_19 ( V_29 ) ;
F_20 ( V_26 , L_2 , & V_2 -> V_32 ) ;
F_20 ( V_26 , L_3 , & V_2 -> V_33 ) ;
if ( ! V_2 -> V_32 || ! V_2 -> V_33 ) {
F_18 ( V_22 , L_4 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_21 ( struct V_34 * V_35 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_36 * V_37 ;
T_4 V_38 ;
int error ;
int V_17 ;
V_37 = F_22 ( V_35 , V_39 , 0 ) ;
if ( ! V_37 ) {
F_18 ( & V_35 -> V_22 , L_5 ) ;
return - V_31 ;
}
V_17 = F_23 ( V_35 , 0 ) ;
if ( V_17 < 0 ) {
F_18 ( & V_35 -> V_22 , L_6 ) ;
return - V_31 ;
}
V_2 = F_24 ( & V_35 -> V_22 , sizeof( * V_2 ) ,
V_40 ) ;
if ( ! V_2 )
return - V_41 ;
error = F_16 ( & V_35 -> V_22 , V_2 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_7 ) ;
return error ;
}
V_38 = sizeof( V_2 -> V_14 [ 0 ] ) *
( V_2 -> V_20 << V_2 -> V_13 ) ;
V_2 -> V_14 = F_24 ( & V_35 -> V_22 , V_38 , V_40 ) ;
if ( ! V_2 -> V_14 )
return - V_41 ;
V_2 -> V_5 = V_5 = F_25 ( & V_35 -> V_22 ) ;
if ( ! V_5 ) {
F_18 ( & V_35 -> V_22 , L_8 ) ;
return - V_41 ;
}
V_5 -> V_42 = V_35 -> V_42 ;
V_5 -> V_43 = L_9 ;
V_5 -> V_44 . V_45 = 0x0001 ;
V_5 -> V_44 . V_46 = 0x0001 ;
V_5 -> V_44 . V_47 = 0x0100 ;
V_5 -> V_48 = F_11 ;
V_5 -> V_49 = F_14 ;
V_5 -> V_22 . V_50 = & V_35 -> V_22 ;
F_26 ( V_5 , V_15 , V_16 ) ;
error = F_27 ( NULL , NULL ,
V_2 -> V_20 ,
V_2 -> V_20 ,
V_2 -> V_14 , V_2 -> V_5 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_10 ) ;
return error ;
}
F_28 ( V_2 -> V_5 , V_2 ) ;
V_2 -> V_11 = F_29 ( & V_35 -> V_22 , V_37 ) ;
if ( F_30 ( V_2 -> V_11 ) )
return F_31 ( V_2 -> V_11 ) ;
V_2 -> V_23 = F_32 ( & V_35 -> V_22 , NULL ) ;
if ( F_30 ( V_2 -> V_23 ) ) {
F_18 ( & V_35 -> V_22 , L_11 ) ;
return F_31 ( V_2 -> V_23 ) ;
}
error = F_13 ( V_2 -> V_23 ) ;
if ( error )
return error ;
F_8 ( V_2 -> V_32 , F_33 ( V_2 -> V_11 ) ) ;
F_8 ( V_2 -> V_33 , F_34 ( V_2 -> V_11 ) ) ;
F_8 ( V_51 ,
F_35 ( V_2 -> V_11 ) ) ;
F_8 ( V_2 -> V_20 ,
F_36 ( V_2 -> V_11 ) ) ;
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_15 ( V_2 -> V_23 ) ;
error = F_37 ( & V_35 -> V_22 , V_17 , F_7 , 0 ,
V_35 -> V_42 , V_2 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_12 ) ;
return error ;
}
error = F_38 ( V_2 -> V_5 ) ;
if ( error ) {
F_18 ( & V_35 -> V_22 , L_13 ) ;
return error ;
}
F_39 ( V_35 , V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_24 * V_22 )
{
struct V_34 * V_35 = F_41 ( V_22 ) ;
struct V_1 * V_2 = F_42 ( V_35 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
F_43 ( & V_5 -> V_52 ) ;
if ( V_5 -> V_53 ) {
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
F_15 ( V_2 -> V_23 ) ;
}
F_44 ( & V_5 -> V_52 ) ;
return 0 ;
}
static int F_45 ( struct V_24 * V_22 )
{
struct V_34 * V_35 = F_41 ( V_22 ) ;
struct V_1 * V_2 = F_42 ( V_35 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_54 = 0 ;
F_43 ( & V_5 -> V_52 ) ;
if ( V_5 -> V_53 ) {
V_54 = F_13 ( V_2 -> V_23 ) ;
if ( V_54 == 0 )
F_8 ( 1 , F_9 ( V_2 -> V_11 ) ) ;
}
F_44 ( & V_5 -> V_52 ) ;
return V_54 ;
}
