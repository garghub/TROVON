static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 -> V_6 ) ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_5 -> V_6 ) ;
}
static T_1 F_6 ( int V_6 , void * V_7 )
{
struct V_3 * V_4 = V_7 ;
T_2 V_8 ;
T_3 V_9 = 3 + 4 * V_4 -> V_10 ;
T_3 V_11 [ V_12 ] ;
int V_13 ;
int V_14 ;
int error ;
V_14 = F_7 ( V_4 -> V_5 , V_11 , V_9 ) ;
if ( V_14 != V_9 ) {
error = V_14 < 0 ? V_14 : - V_15 ;
F_8 ( & V_4 -> V_5 -> V_2 ,
L_1 , error ) ;
return V_16 ;
}
if ( V_11 [ 0 ] != V_17 )
return V_16 ;
V_8 = F_9 ( V_11 + 1 ) ;
for ( V_13 = 0 ; V_13 < V_4 -> V_10 ; V_13 ++ ) {
if ( ! ( V_8 & F_10 ( 15 - V_13 ) ) )
continue;
F_11 ( V_4 -> V_18 , V_13 ) ;
F_12 ( V_4 -> V_18 , V_19 , true ) ;
F_13 ( V_4 -> V_18 , V_20 , V_21 ,
( ( V_11 [ V_13 + 3 ] >> 4 ) << 8 ) + V_11 [ V_13 + 4 ] ) ;
F_13 ( V_4 -> V_18 , V_20 , V_22 ,
( ( V_11 [ V_13 + 3 ] & 0xF ) << 8 ) + V_11 [ V_13 + 5 ] ) ;
}
F_14 ( V_4 -> V_18 ) ;
F_15 ( V_4 -> V_18 ) ;
return V_16 ;
}
static void F_16 ( void * V_23 )
{
struct V_3 * V_4 = V_23 ;
F_17 ( F_18 ( V_4 -> V_24 ) , V_4 -> V_24 ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
struct V_25 * V_2 = & V_4 -> V_5 -> V_2 ;
int error ;
V_4 -> V_24 [ 0 ] . V_26 = L_2 ;
V_4 -> V_24 [ 1 ] . V_26 = L_3 ;
error = F_20 ( V_2 , F_18 ( V_4 -> V_24 ) ,
V_4 -> V_24 ) ;
if ( error )
return error ;
error = F_21 ( F_18 ( V_4 -> V_24 ) , V_4 -> V_24 ) ;
if ( error )
return error ;
F_22 ( V_27 ) ;
error = F_23 ( V_2 , F_16 , V_4 ) ;
if ( error ) {
F_24 ( V_2 , L_4 , error ) ;
return error ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 )
{
T_3 V_11 [ V_28 ] ;
T_3 V_29 = V_30 ;
int V_14 ;
int error ;
V_14 = F_26 ( V_4 -> V_5 , & V_29 , sizeof( V_29 ) ) ;
if ( V_14 != sizeof( V_29 ) ) {
error = V_14 < 0 ? V_14 : - V_15 ;
F_24 ( & V_4 -> V_5 -> V_2 ,
L_5 , error ) ;
return error ;
}
V_14 = F_7 ( V_4 -> V_5 , V_11 , sizeof( V_11 ) ) ;
if ( V_14 != sizeof( V_11 ) ) {
error = V_14 < 0 ? V_14 : - V_15 ;
F_24 ( & V_4 -> V_5 -> V_2 ,
L_6 , error ) ;
return error ;
}
V_4 -> V_10 = V_11 [ 15 ] & 0x7F ;
if ( V_4 -> V_10 > V_31 ) {
F_27 ( & V_4 -> V_5 -> V_2 ,
L_7 ,
V_4 -> V_10 , V_31 ) ;
V_4 -> V_10 = V_31 ;
}
V_4 -> V_32 = F_28 ( & V_11 [ 8 ] ) ;
V_4 -> V_33 = F_28 ( & V_11 [ 10 ] ) ;
return 0 ;
}
static int F_29 ( struct V_34 * V_5 ,
const struct V_35 * V_36 )
{
struct V_25 * V_2 = & V_5 -> V_2 ;
struct V_3 * V_4 ;
struct V_1 * V_18 ;
int error ;
if ( ! V_5 -> V_6 ) {
F_24 ( V_2 , L_8 ) ;
return - V_37 ;
}
V_4 = F_30 ( V_2 , sizeof( * V_4 ) , V_38 ) ;
if ( ! V_4 )
return - V_39 ;
V_4 -> V_5 = V_5 ;
error = F_19 ( V_4 ) ;
if ( error )
return error ;
error = F_25 ( V_4 ) ;
if ( error )
return error ;
V_4 -> V_18 = V_18 = F_31 ( V_2 ) ;
if ( ! V_18 )
return - V_39 ;
F_32 ( V_18 , V_4 ) ;
V_18 -> V_40 = V_5 -> V_40 ;
V_18 -> V_36 . V_41 = V_42 ;
V_18 -> V_43 = F_1 ;
V_18 -> V_44 = F_4 ;
F_33 ( V_18 , V_21 , 0 , V_4 -> V_32 , 0 , 0 ) ;
F_33 ( V_18 , V_22 , 0 , V_4 -> V_33 , 0 , 0 ) ;
F_34 ( V_18 , true , & V_4 -> V_45 ) ;
error = F_35 ( V_18 , V_4 -> V_10 ,
V_46 | V_47 ) ;
if ( error )
return error ;
error = F_36 ( V_2 , V_5 -> V_6 , NULL , F_6 ,
V_48 , V_5 -> V_40 , V_4 ) ;
if ( error ) {
F_24 ( V_2 , L_9 ,
V_5 -> V_6 , error ) ;
return error ;
}
F_4 ( V_18 ) ;
error = F_37 ( V_18 ) ;
if ( error )
return error ;
return 0 ;
}
