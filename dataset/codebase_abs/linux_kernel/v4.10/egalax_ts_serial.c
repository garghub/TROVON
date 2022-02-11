static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
T_1 * V_5 = V_1 -> V_5 ;
T_2 V_6 , V_7 ;
T_1 V_8 ;
T_1 V_9 ;
V_8 = 3 - ( ( V_5 [ 0 ] & V_10 ) >> 1 ) ;
V_9 = 0xff >> ( V_8 + 1 ) ;
V_6 = ( ( ( T_2 ) ( V_5 [ 1 ] & V_9 ) << 7 ) | ( V_5 [ 2 ] & 0x7f ) ) << V_8 ;
V_7 = ( ( ( T_2 ) ( V_5 [ 3 ] & V_9 ) << 7 ) | ( V_5 [ 4 ] & 0x7f ) ) << V_8 ;
F_2 ( V_3 , V_11 , V_5 [ 0 ] & V_12 ) ;
F_3 ( V_3 , V_13 , V_6 ) ;
F_3 ( V_3 , V_14 , V_7 ) ;
F_4 ( V_3 ) ;
}
static T_3 F_5 ( struct V_15 * V_15 ,
unsigned char V_5 , unsigned int V_16 )
{
struct V_1 * V_1 = F_6 ( V_15 ) ;
int V_17 ;
V_1 -> V_5 [ V_1 -> V_18 ++ ] = V_5 ;
if ( F_7 ( V_1 -> V_5 [ 0 ] & V_19 ) ) {
V_17 = V_1 -> V_5 [ 0 ] & V_20 ? 6 : 5 ;
if ( V_17 == V_1 -> V_18 ) {
F_1 ( V_1 ) ;
V_1 -> V_18 = 0 ;
}
} else {
F_8 ( & V_15 -> V_3 , L_1 ,
V_1 -> V_5 [ 0 ] ) ;
V_1 -> V_18 = 0 ;
}
return V_21 ;
}
static int F_9 ( struct V_15 * V_15 , struct V_22 * V_23 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int error ;
V_1 = F_10 ( sizeof( struct V_1 ) , V_24 ) ;
V_2 = F_11 () ;
if ( ! V_1 || ! V_2 ) {
error = - V_25 ;
goto V_26;
}
V_1 -> V_15 = V_15 ;
V_1 -> V_4 = V_2 ;
snprintf ( V_1 -> V_27 , sizeof( V_1 -> V_27 ) ,
L_2 , V_15 -> V_27 ) ;
V_2 -> V_28 = L_3 ;
V_2 -> V_27 = V_1 -> V_27 ;
V_2 -> V_29 . V_30 = V_31 ;
V_2 -> V_29 . V_32 = V_33 ;
V_2 -> V_29 . V_34 = 0 ;
V_2 -> V_29 . V_35 = 0x0001 ;
V_2 -> V_3 . V_36 = & V_15 -> V_3 ;
F_12 ( V_2 , V_37 , V_11 ) ;
F_13 ( V_2 , V_13 ,
V_38 , V_39 , 0 , 0 ) ;
F_13 ( V_2 , V_14 ,
V_40 , V_41 , 0 , 0 ) ;
F_14 ( V_15 , V_1 ) ;
error = F_15 ( V_15 , V_23 ) ;
if ( error )
goto V_42;
error = F_16 ( V_2 ) ;
if ( error )
goto V_43;
return 0 ;
V_43:
F_17 ( V_15 ) ;
V_42:
F_14 ( V_15 , NULL ) ;
V_26:
F_18 ( V_2 ) ;
F_19 ( V_1 ) ;
return error ;
}
static void F_20 ( struct V_15 * V_15 )
{
struct V_1 * V_1 = F_6 ( V_15 ) ;
F_17 ( V_15 ) ;
F_14 ( V_15 , NULL ) ;
F_21 ( V_1 -> V_4 ) ;
F_19 ( V_1 ) ;
}
