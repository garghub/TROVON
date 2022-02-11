static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = V_2 ;
int V_4 ;
T_2 V_5 [ 4 ] ;
unsigned int V_6 , V_7 ;
int V_8 ;
V_4 = F_2 ( V_3 -> V_9 ,
V_10 | V_11 ) ;
F_3 ( & V_3 -> V_9 -> V_12 , L_1 , V_4 ) ;
if ( V_4 < 0 )
goto V_13;
if ( V_4 & V_14 ) {
F_3 ( & V_3 -> V_9 -> V_12 , L_2 ) ;
F_4 ( V_3 -> V_15 , V_16 , 0 ) ;
F_5 ( V_3 -> V_15 ) ;
}
if ( V_4 & V_17 ) {
F_3 ( & V_3 -> V_9 -> V_12 , L_3 ) ;
V_8 = F_6 ( V_3 -> V_9 , V_5 , sizeof( V_5 ) ) ;
if ( V_8 != sizeof( V_5 ) )
goto V_13;
if ( F_7 ( V_5 [ 0 ] & 0x80 || V_5 [ 2 ] & 0x80 ) )
goto V_13;
V_6 = ( ( V_5 [ 0 ] & 0xf ) << 8 ) | ( V_5 [ 1 ] ) ;
V_7 = ( ( V_5 [ 2 ] & 0xf ) << 8 ) | ( V_5 [ 3 ] ) ;
F_8 ( V_3 -> V_15 , V_18 , V_6 ) ;
F_8 ( V_3 -> V_15 , V_19 , V_7 ) ;
F_4 ( V_3 -> V_15 , V_16 , 1 ) ;
F_5 ( V_3 -> V_15 ) ;
F_3 ( & V_3 -> V_9 -> V_12 , L_4 , V_6 , V_7 ) ;
}
V_13:
return V_20 ;
}
static int F_9 ( struct V_21 * V_12 )
{
struct V_3 * V_3 = F_10 ( V_12 ) ;
struct V_22 * V_9 = V_3 -> V_9 ;
int error ;
error = F_11 ( V_9 , V_23 ,
V_24 | V_25 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_5 ) ;
return error ;
}
error = F_13 ( V_9 , V_26 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_6 ) ;
return error ;
}
F_14 ( V_9 -> V_1 ) ;
return 0 ;
}
static void F_15 ( struct V_21 * V_12 )
{
struct V_3 * V_3 = F_10 ( V_12 ) ;
struct V_22 * V_9 = V_3 -> V_9 ;
int error ;
F_16 ( V_9 -> V_1 ) ;
error = F_13 ( V_9 , V_27 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_7 ) ;
return;
}
error = F_11 ( V_9 , V_23 , 0 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_5 ) ;
return;
}
}
static int F_17 ( struct V_22 * V_9 ,
const struct V_28 * V_29 )
{
struct V_3 * V_3 ;
struct V_21 * V_15 ;
int error ;
if ( ! F_18 ( V_9 -> V_30 ,
V_31 ) )
return - V_32 ;
V_3 = F_19 ( & V_9 -> V_12 , sizeof( * V_3 ) , V_33 ) ;
if ( ! V_3 )
return - V_34 ;
V_15 = F_20 ( & V_9 -> V_12 ) ;
if ( ! V_15 )
return - V_34 ;
V_15 -> V_35 = L_8 ;
V_15 -> V_29 . V_36 = V_37 ;
V_15 -> V_12 . V_38 = & V_9 -> V_12 ;
V_15 -> V_39 = F_9 ;
V_15 -> V_40 = F_15 ;
F_21 ( V_41 , V_15 -> V_42 ) ;
F_22 ( V_15 , V_43 , V_16 ) ;
F_23 ( V_15 , V_18 , 0 , V_44 , 0 , 0 ) ;
F_23 ( V_15 , V_19 , 0 , V_44 , 0 , 0 ) ;
V_3 -> V_9 = V_9 ;
V_3 -> V_15 = V_15 ;
F_24 ( V_3 -> V_15 , V_3 ) ;
error = F_11 ( V_9 , V_45 ,
V_46 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_9 ) ;
return error ;
}
error = F_11 ( V_9 , V_47 ,
V_48 | V_49 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_10 ) ;
return error ;
}
error = F_11 ( V_9 , V_50 ,
V_17 |
V_14 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_11 ) ;
return error ;
}
error = F_11 ( V_9 , V_51 ,
V_52 | V_53 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 , L_12 ) ;
return error ;
}
error = F_25 ( & V_9 -> V_12 , V_9 -> V_1 ,
NULL , F_1 ,
V_54 | V_55 ,
V_9 -> V_35 , V_3 ) ;
if ( error ) {
F_12 ( & V_9 -> V_12 ,
L_13 ,
V_9 -> V_1 , error ) ;
return error ;
}
F_16 ( V_9 -> V_1 ) ;
error = F_26 ( V_3 -> V_15 ) ;
if ( error )
return error ;
F_27 ( V_9 , V_3 ) ;
return 0 ;
}
