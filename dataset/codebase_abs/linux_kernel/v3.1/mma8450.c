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
static int F_6 ( struct V_1 * V_2 , int * V_10 , int * V_11 , int * V_12 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_13 [ 6 ] ;
int V_14 ;
V_14 = F_7 ( V_5 , V_15 , 6 , V_13 ) ;
if ( V_14 < 0 ) {
F_3 ( & V_5 -> V_8 ,
L_3 ,
V_15 , V_14 ) ;
return V_14 ;
}
* V_10 = ( ( V_13 [ 1 ] << 4 ) & 0xff0 ) | ( V_13 [ 0 ] & 0xf ) ;
* V_11 = ( ( V_13 [ 3 ] << 4 ) & 0xff0 ) | ( V_13 [ 2 ] & 0xf ) ;
* V_12 = ( ( V_13 [ 5 ] << 4 ) & 0xff0 ) | ( V_13 [ 4 ] & 0xf ) ;
return 0 ;
}
static void F_8 ( struct V_16 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_17 ;
int V_10 , V_11 , V_12 ;
int V_7 ;
int V_14 ;
V_7 = F_1 ( V_2 , V_18 ) ;
if ( V_7 < 0 )
return;
if ( ! ( V_7 & V_19 ) )
return;
V_14 = F_6 ( V_2 , & V_10 , & V_11 , & V_12 ) ;
if ( V_14 )
return;
F_9 ( V_8 -> V_20 , V_21 , V_10 ) ;
F_9 ( V_8 -> V_20 , V_22 , V_11 ) ;
F_9 ( V_8 -> V_20 , V_23 , V_12 ) ;
F_10 ( V_8 -> V_20 ) ;
}
static void F_11 ( struct V_16 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_17 ;
int V_14 ;
V_14 = F_4 ( V_2 , V_24 , 0x07 ) ;
if ( V_14 )
return;
V_14 = F_4 ( V_2 , V_25 , 0x01 ) ;
if ( V_14 < 0 )
return;
F_12 ( V_26 ) ;
}
static void F_13 ( struct V_16 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_17 ;
F_4 ( V_2 , V_25 , 0x00 ) ;
F_4 ( V_2 , V_27 , 0x01 ) ;
}
static int T_2 F_14 ( struct V_4 * V_5 ,
const struct V_28 * V_29 )
{
struct V_16 * V_30 ;
struct V_1 * V_2 ;
int V_14 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_31 ) ;
V_30 = F_16 () ;
if ( ! V_2 || ! V_30 ) {
V_14 = - V_32 ;
goto V_33;
}
V_2 -> V_6 = V_5 ;
V_2 -> V_30 = V_30 ;
V_30 -> V_17 = V_2 ;
V_30 -> V_20 -> V_34 = V_35 ;
V_30 -> V_20 -> V_29 . V_36 = V_37 ;
V_30 -> V_38 = F_8 ;
V_30 -> V_39 = V_40 ;
V_30 -> V_41 = V_42 ;
V_30 -> V_43 = F_11 ;
V_30 -> V_44 = F_13 ;
F_17 ( V_45 , V_30 -> V_20 -> V_46 ) ;
F_18 ( V_30 -> V_20 , V_21 , - 2048 , 2047 , 32 , 32 ) ;
F_18 ( V_30 -> V_20 , V_22 , - 2048 , 2047 , 32 , 32 ) ;
F_18 ( V_30 -> V_20 , V_23 , - 2048 , 2047 , 32 , 32 ) ;
V_14 = F_19 ( V_30 ) ;
if ( V_14 ) {
F_3 ( & V_5 -> V_8 , L_4 ) ;
goto V_33;
}
return 0 ;
V_33:
F_20 ( V_30 ) ;
F_21 ( V_2 ) ;
return V_14 ;
}
static int T_3 F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_23 ( V_5 ) ;
struct V_16 * V_30 = V_2 -> V_30 ;
F_24 ( V_30 ) ;
F_20 ( V_30 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
static int T_4 F_25 ( void )
{
return F_26 ( & V_47 ) ;
}
static void T_5 F_27 ( void )
{
F_28 ( & V_47 ) ;
}
