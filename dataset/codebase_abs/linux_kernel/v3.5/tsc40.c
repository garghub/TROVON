static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 * V_5 = V_2 -> V_5 ;
T_2 V_6 ;
T_2 V_7 ;
V_6 = ( ( V_5 [ 1 ] & 0x03 ) << 8 ) | V_5 [ 2 ] ;
V_7 = ( ( V_5 [ 3 ] & 0x03 ) << 8 ) | V_5 [ 4 ] ;
F_2 ( V_4 , V_8 , V_6 ) ;
F_2 ( V_4 , V_9 , V_7 ) ;
F_3 ( V_4 , V_10 , 1 ) ;
F_4 ( V_4 ) ;
}
static T_3 F_5 ( struct V_11 * V_11 ,
unsigned char V_5 , unsigned int V_12 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_5 [ V_2 -> V_13 ] = V_5 ;
switch ( V_2 -> V_13 ++ ) {
case 0 :
if ( F_7 ( ( V_5 & 0x3e ) != 0x10 ) ) {
F_8 ( & V_11 -> V_4 ,
L_1 , V_5 ) ;
V_2 -> V_13 = 0 ;
} else if ( ! ( V_5 & 0x01 ) ) {
F_3 ( V_4 , V_10 , 0 ) ;
F_4 ( V_4 ) ;
V_2 -> V_13 = 0 ;
}
break;
case 1 :
case 3 :
if ( F_7 ( V_5 & 0xfc ) ) {
F_8 ( & V_11 -> V_4 ,
L_2 ,
V_5 , V_2 -> V_13 - 1 ) ;
V_2 -> V_13 = 0 ;
}
break;
case 4 :
F_1 ( V_2 ) ;
V_2 -> V_13 = 0 ;
break;
}
return V_14 ;
}
static int F_9 ( struct V_11 * V_11 , struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
int error ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_17 ) ;
V_3 = F_11 () ;
if ( ! V_2 || ! V_3 ) {
error = - V_18 ;
goto V_19;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_4 = V_3 ;
snprintf ( V_2 -> V_20 , sizeof( V_2 -> V_20 ) , L_3 , V_11 -> V_20 ) ;
V_3 -> V_21 = L_4 ;
V_3 -> V_20 = V_2 -> V_20 ;
V_3 -> V_22 . V_23 = V_24 ;
V_3 -> V_22 . V_25 = V_26 ;
V_3 -> V_22 . V_27 = 40 ;
V_3 -> V_22 . V_28 = 0x0001 ;
V_3 -> V_4 . V_29 = & V_11 -> V_4 ;
V_3 -> V_30 [ 0 ] = F_12 ( V_31 ) | F_12 ( V_32 ) ;
F_13 ( V_10 , V_3 -> V_33 ) ;
F_14 ( V_2 -> V_4 , V_8 , 0 , 0x3ff , 0 , 0 ) ;
F_14 ( V_2 -> V_4 , V_9 , 0 , 0x3ff , 0 , 0 ) ;
F_14 ( V_2 -> V_4 , V_34 , 0 , 0 , 0 , 0 ) ;
F_15 ( V_11 , V_2 ) ;
error = F_16 ( V_11 , V_16 ) ;
if ( error )
goto V_35;
error = F_17 ( V_2 -> V_4 ) ;
if ( error )
goto V_36;
return 0 ;
V_36:
F_18 ( V_11 ) ;
V_35:
F_15 ( V_11 , NULL ) ;
V_19:
F_19 ( V_3 ) ;
F_20 ( V_2 ) ;
return error ;
}
static void F_21 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_11 ) ;
F_18 ( V_11 ) ;
F_22 ( V_2 -> V_4 ) ;
F_20 ( V_2 ) ;
F_15 ( V_11 , NULL ) ;
}
