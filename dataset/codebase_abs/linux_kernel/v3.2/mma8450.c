static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_5 , V_3 ) ;
if ( V_7 < 0 )
F_3 ( & V_5 -> V_8 ,
L_1 ,
V_3 , V_7 ) ;
return V_7 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 , T_1 V_9 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int error ;
error = F_5 ( V_5 , V_3 , V_9 ) ;
if ( error < 0 ) {
F_3 ( & V_5 -> V_8 ,
L_2 ,
V_3 , error ) ;
return error ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 * V_10 , T_2 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_12 ;
V_12 = F_7 ( V_5 , V_3 , V_11 , V_10 ) ;
if ( V_12 < 0 ) {
F_3 ( & V_5 -> V_8 ,
L_3 ,
V_13 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
static void F_8 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_15 ;
int V_16 , V_17 , V_18 ;
int V_7 ;
T_1 V_10 [ 6 ] ;
V_7 = F_1 ( V_2 , V_19 ) ;
if ( V_7 < 0 )
return;
if ( ! ( V_7 & V_20 ) )
return;
V_7 = F_6 ( V_2 , V_13 , V_10 , sizeof( V_10 ) ) ;
if ( V_7 < 0 )
return;
V_16 = ( ( V_10 [ 1 ] << 4 ) & 0xff0 ) | ( V_10 [ 0 ] & 0xf ) ;
V_17 = ( ( V_10 [ 3 ] << 4 ) & 0xff0 ) | ( V_10 [ 2 ] & 0xf ) ;
V_18 = ( ( V_10 [ 5 ] << 4 ) & 0xff0 ) | ( V_10 [ 4 ] & 0xf ) ;
F_9 ( V_8 -> V_21 , V_22 , V_16 ) ;
F_9 ( V_8 -> V_21 , V_23 , V_17 ) ;
F_9 ( V_8 -> V_21 , V_24 , V_18 ) ;
F_10 ( V_8 -> V_21 ) ;
}
static void F_11 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_15 ;
int V_12 ;
V_12 = F_4 ( V_2 , V_25 , 0x07 ) ;
if ( V_12 )
return;
V_12 = F_4 ( V_2 , V_26 , 0x01 ) ;
if ( V_12 < 0 )
return;
F_12 ( V_27 ) ;
}
static void F_13 ( struct V_14 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_15 ;
F_4 ( V_2 , V_26 , 0x00 ) ;
F_4 ( V_2 , V_28 , 0x01 ) ;
}
static int T_3 F_14 ( struct V_4 * V_5 ,
const struct V_29 * V_30 )
{
struct V_14 * V_31 ;
struct V_1 * V_2 ;
int V_12 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_32 ) ;
V_31 = F_16 () ;
if ( ! V_2 || ! V_31 ) {
V_12 = - V_33 ;
goto V_34;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_31 = V_31 ;
V_31 -> V_15 = V_2 ;
V_31 -> V_21 -> V_35 = V_36 ;
V_31 -> V_21 -> V_30 . V_37 = V_38 ;
V_31 -> V_39 = F_8 ;
V_31 -> V_40 = V_41 ;
V_31 -> V_42 = V_43 ;
V_31 -> V_44 = F_11 ;
V_31 -> V_45 = F_13 ;
F_17 ( V_46 , V_31 -> V_21 -> V_47 ) ;
F_18 ( V_31 -> V_21 , V_22 , - 2048 , 2047 , 32 , 32 ) ;
F_18 ( V_31 -> V_21 , V_23 , - 2048 , 2047 , 32 , 32 ) ;
F_18 ( V_31 -> V_21 , V_24 , - 2048 , 2047 , 32 , 32 ) ;
V_12 = F_19 ( V_31 ) ;
if ( V_12 ) {
F_3 ( & V_5 -> V_8 , L_4 ) ;
goto V_34;
}
return 0 ;
V_34:
F_20 ( V_31 ) ;
F_21 ( V_2 ) ;
return V_12 ;
}
static int T_4 F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_23 ( V_5 ) ;
struct V_14 * V_31 = V_2 -> V_31 ;
F_24 ( V_31 ) ;
F_20 ( V_31 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int T_5 F_25 ( void )
{
return F_26 ( & V_48 ) ;
}
static void T_6 F_27 ( void )
{
F_28 ( & V_48 ) ;
}
