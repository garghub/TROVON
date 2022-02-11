static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_2 . V_2 ) ;
unsigned short V_5 , V_6 ;
unsigned char V_7 ;
T_1 V_8 [ 16 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ 0 ] = 0 ;
if ( F_3 ( V_4 -> V_9 , V_8 , 1 ) != 1 ) {
F_4 ( & V_4 -> V_9 -> V_10 , L_1 ) ;
goto V_11;
}
if ( F_5 ( V_4 -> V_9 , V_8 , sizeof( V_8 ) ) != sizeof( V_8 ) ) {
F_4 ( & V_4 -> V_9 -> V_10 , L_2 ) ;
goto V_11;
}
V_6 = ( ( V_8 [ 9 ] & 0x03 ) << 8 | V_8 [ 8 ] ) ;
V_5 = ( ( V_8 [ 11 ] & 0x03 ) << 8 | V_8 [ 10 ] ) ;
V_7 = V_8 [ 12 ] ;
if ( V_7 == V_12 || V_7 == V_13 ) {
F_6 ( V_4 -> V_14 , V_15 , 1 ) ;
F_7 ( V_4 -> V_14 , V_16 , V_6 ) ;
F_7 ( V_4 -> V_14 , V_17 , V_5 ) ;
F_8 ( V_4 -> V_14 ) ;
} else if ( V_7 == V_18 ) {
F_6 ( V_4 -> V_14 , V_15 , 0 ) ;
F_8 ( V_4 -> V_14 ) ;
}
V_11:
F_9 ( V_4 -> V_19 ) ;
}
static T_2 F_10 ( int V_19 , void * V_20 )
{
struct V_3 * V_4 = V_20 ;
F_11 ( V_19 ) ;
F_12 ( & V_4 -> V_2 , V_21 / 20 ) ;
return V_22 ;
}
static int F_13 ( struct V_23 * V_10 )
{
struct V_3 * V_4 = F_14 ( V_10 ) ;
struct V_24 * V_9 = V_4 -> V_9 ;
int V_25 ;
V_25 = F_3 ( V_9 , V_26 ,
sizeof( V_26 ) ) ;
if ( V_25 != sizeof( V_26 ) ) {
F_4 ( & V_9 -> V_10 , L_3 ) ;
return - V_27 ;
}
return 0 ;
}
static void F_15 ( struct V_23 * V_10 )
{
struct V_3 * V_4 = F_14 ( V_10 ) ;
struct V_24 * V_9 = V_4 -> V_9 ;
F_16 ( V_4 -> V_19 ) ;
if ( F_17 ( & V_4 -> V_2 ) ) {
F_9 ( V_4 -> V_19 ) ;
}
F_3 ( V_9 , V_28 , sizeof( V_28 ) ) ;
F_9 ( V_4 -> V_19 ) ;
}
static int F_18 ( struct V_24 * V_9 ,
const struct V_29 * V_30 )
{
struct V_3 * V_4 ;
struct V_23 * V_14 ;
int error ;
V_4 = F_19 ( sizeof( * V_4 ) , V_31 ) ;
if ( ! V_4 ) {
F_4 ( & V_9 -> V_10 , L_4 ) ;
error = - V_32 ;
goto V_33;
}
F_20 ( & V_9 -> V_10 , V_4 ) ;
V_14 = F_21 () ;
if ( ! V_14 ) {
F_4 ( & V_9 -> V_10 , L_5 ) ;
error = - V_32 ;
goto V_34;
}
V_14 -> V_35 [ 0 ] = F_22 ( V_36 ) | F_22 ( V_37 ) ;
V_14 -> V_38 [ F_23 ( V_15 ) ] = F_22 ( V_15 ) ;
F_24 ( V_14 , V_16 , 95 , 955 , 0 , 0 ) ;
F_24 ( V_14 , V_17 , 85 , 935 , 0 , 0 ) ;
V_14 -> V_39 = V_9 -> V_39 ;
V_14 -> V_40 . V_41 = V_42 ;
V_14 -> V_10 . V_43 = & V_9 -> V_10 ;
V_14 -> V_44 = F_13 ;
V_14 -> V_45 = F_15 ;
F_25 ( V_14 , V_4 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_14 = V_14 ;
F_26 ( & V_4 -> V_2 , F_1 ) ;
V_4 -> V_19 = V_9 -> V_19 ;
error = F_27 ( V_14 ) ;
if ( error )
goto V_34;
error = F_28 ( V_4 -> V_19 , F_10 , V_46 ,
V_9 -> V_39 , V_4 ) ;
if ( error ) {
F_4 ( & V_9 -> V_10 , L_6 ) ;
goto V_47;
}
F_29 ( & V_9 -> V_10 , 1 ) ;
return 0 ;
V_47:
F_30 ( V_14 ) ;
V_14 = NULL ;
V_34:
F_31 ( V_14 ) ;
F_32 ( V_4 ) ;
V_33:
F_20 ( & V_9 -> V_10 , NULL ) ;
return error ;
}
static int F_33 ( struct V_24 * V_9 )
{
struct V_3 * V_4 = F_34 ( & V_9 -> V_10 ) ;
F_35 ( V_4 -> V_19 , V_4 ) ;
F_30 ( V_4 -> V_14 ) ;
F_32 ( V_4 ) ;
F_20 ( & V_9 -> V_10 , NULL ) ;
return 0 ;
}
static int F_36 ( struct V_48 * V_10 )
{
struct V_24 * V_9 = F_37 ( V_10 ) ;
struct V_3 * V_4 = F_34 ( & V_9 -> V_10 ) ;
if ( F_38 ( & V_9 -> V_10 ) )
F_39 ( V_4 -> V_19 ) ;
return 0 ;
}
static int F_40 ( struct V_48 * V_10 )
{
struct V_24 * V_9 = F_37 ( V_10 ) ;
struct V_3 * V_4 = F_34 ( & V_9 -> V_10 ) ;
if ( F_38 ( & V_9 -> V_10 ) )
F_41 ( V_4 -> V_19 ) ;
return 0 ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_49 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_49 ) ;
}
