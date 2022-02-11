static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
T_2 * V_7 = V_4 -> V_7 ;
unsigned int V_8 , V_9 , V_10 ;
int V_11 ;
V_11 = F_2 ( V_4 -> V_12 ,
V_4 -> V_7 , sizeof( V_4 -> V_7 ) ) ;
if ( V_11 != sizeof( V_4 -> V_7 ) )
goto V_13;
if ( ( V_7 [ 0 ] & 0x80 ) == 0 )
goto V_13;
V_10 = V_7 [ 0 ] & F_3 ( 0 ) ;
V_8 = ( ( V_7 [ 2 ] & 0x1f ) << 7 ) | ( V_7 [ 1 ] & 0x7f ) ;
V_9 = ( ( V_7 [ 4 ] & 0x1f ) << 7 ) | ( V_7 [ 3 ] & 0x7f ) ;
F_4 ( V_6 , V_14 , V_8 ) ;
F_4 ( V_6 , V_15 , V_9 ) ;
F_5 ( V_6 , V_16 , V_10 ) ;
F_6 ( V_6 ) ;
V_13:
return V_17 ;
}
static int F_7 ( struct V_5 * V_18 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_19 * V_12 = V_4 -> V_12 ;
F_9 ( V_12 -> V_1 ) ;
return 0 ;
}
static void F_10 ( struct V_5 * V_18 )
{
struct V_3 * V_4 = F_8 ( V_18 ) ;
struct V_19 * V_12 = V_4 -> V_12 ;
F_11 ( V_12 -> V_1 ) ;
}
static int F_12 ( struct V_19 * V_12 ,
const struct V_20 * V_21 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int error ;
if ( ! F_13 ( V_12 -> V_22 , V_23 ) ) {
F_14 ( & V_12 -> V_18 , L_1 ) ;
return - V_24 ;
}
V_4 = F_15 ( & V_12 -> V_18 , sizeof( * V_4 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
V_6 = F_16 ( & V_12 -> V_18 ) ;
if ( ! V_6 )
return - V_26 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_6 = V_6 ;
V_6 -> V_27 = L_2 ;
V_6 -> V_21 . V_28 = V_29 ;
V_6 -> V_18 . V_30 = & V_12 -> V_18 ;
V_6 -> V_31 = F_7 ;
V_6 -> V_32 = F_10 ;
F_17 ( V_6 , V_33 , V_16 ) ;
F_18 ( V_6 , V_14 , 0 , V_34 , 0 , 0 ) ;
F_18 ( V_6 , V_15 , 0 , V_35 , 0 , 0 ) ;
F_19 ( V_6 , V_4 ) ;
error = F_20 ( & V_12 -> V_18 , V_12 -> V_1 ,
NULL , F_1 ,
V_36 | V_37 ,
L_3 , V_4 ) ;
if ( error ) {
F_14 ( & V_12 -> V_18 ,
L_4 , error ) ;
return error ;
}
F_11 ( V_12 -> V_1 ) ;
error = F_21 ( V_4 -> V_6 ) ;
if ( error ) {
F_14 ( & V_12 -> V_18 ,
L_5 , error ) ;
return error ;
}
return 0 ;
}
static int T_3 F_22 ( struct V_38 * V_18 )
{
struct V_19 * V_12 = F_23 ( V_18 ) ;
F_11 ( V_12 -> V_1 ) ;
return 0 ;
}
static int T_3 F_24 ( struct V_38 * V_18 )
{
struct V_19 * V_12 = F_23 ( V_18 ) ;
F_9 ( V_12 -> V_1 ) ;
return 0 ;
}
