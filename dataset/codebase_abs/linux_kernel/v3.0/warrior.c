static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
if ( ! V_1 -> V_5 ) return;
switch ( ( V_4 [ 0 ] >> 4 ) & 7 ) {
case 1 :
F_2 ( V_3 , V_6 , V_4 [ 3 ] & 1 ) ;
F_2 ( V_3 , V_7 , ( V_4 [ 3 ] >> 1 ) & 1 ) ;
F_2 ( V_3 , V_8 , ( V_4 [ 3 ] >> 2 ) & 1 ) ;
F_2 ( V_3 , V_9 , ( V_4 [ 3 ] >> 3 ) & 1 ) ;
break;
case 3 :
F_3 ( V_3 , V_10 , ( ( V_4 [ 0 ] & 8 ) << 5 ) - ( V_4 [ 2 ] | ( ( V_4 [ 0 ] & 4 ) << 5 ) ) ) ;
F_3 ( V_3 , V_11 , ( V_4 [ 1 ] | ( ( V_4 [ 0 ] & 1 ) << 7 ) ) - ( ( V_4 [ 0 ] & 2 ) << 7 ) ) ;
break;
case 5 :
F_3 ( V_3 , V_12 , ( V_4 [ 1 ] | ( ( V_4 [ 0 ] & 1 ) << 7 ) ) - ( ( V_4 [ 0 ] & 2 ) << 7 ) ) ;
F_3 ( V_3 , V_13 , ( V_4 [ 3 ] & 2 ? 1 : 0 ) - ( V_4 [ 3 ] & 1 ? 1 : 0 ) ) ;
F_3 ( V_3 , V_14 , ( V_4 [ 3 ] & 8 ? 1 : 0 ) - ( V_4 [ 3 ] & 4 ? 1 : 0 ) ) ;
F_4 ( V_3 , V_15 , ( V_4 [ 2 ] | ( ( V_4 [ 0 ] & 4 ) << 5 ) ) - ( ( V_4 [ 0 ] & 8 ) << 5 ) ) ;
break;
}
F_5 ( V_3 ) ;
}
static T_1 F_6 ( struct V_16 * V_16 ,
unsigned char V_4 , unsigned int V_17 )
{
struct V_1 * V_1 = F_7 ( V_16 ) ;
if ( V_4 & 0x80 ) {
if ( V_1 -> V_5 ) F_1 ( V_1 ) ;
V_1 -> V_5 = 0 ;
V_1 -> V_18 = V_19 [ ( V_4 >> 4 ) & 7 ] ;
}
if ( V_1 -> V_5 < V_1 -> V_18 )
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_4 ;
if ( V_1 -> V_5 == V_1 -> V_18 ) {
if ( V_1 -> V_5 ) F_1 ( V_1 ) ;
V_1 -> V_5 = 0 ;
V_1 -> V_18 = 0 ;
}
return V_20 ;
}
static void F_8 ( struct V_16 * V_16 )
{
struct V_1 * V_1 = F_7 ( V_16 ) ;
F_9 ( V_16 ) ;
F_10 ( V_16 , NULL ) ;
F_11 ( V_1 -> V_3 ) ;
F_12 ( V_1 ) ;
}
static int F_13 ( struct V_16 * V_16 , struct V_21 * V_22 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_23 = - V_24 ;
V_1 = F_14 ( sizeof( struct V_1 ) , V_25 ) ;
V_2 = F_15 () ;
if ( ! V_1 || ! V_2 )
goto V_26;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_27 , sizeof( V_1 -> V_27 ) , L_1 , V_16 -> V_27 ) ;
V_2 -> V_28 = L_2 ;
V_2 -> V_27 = V_1 -> V_27 ;
V_2 -> V_29 . V_30 = V_31 ;
V_2 -> V_29 . V_32 = V_33 ;
V_2 -> V_29 . V_34 = 0x0001 ;
V_2 -> V_29 . V_35 = 0x0100 ;
V_2 -> V_3 . V_36 = & V_16 -> V_3 ;
V_2 -> V_37 [ 0 ] = F_16 ( V_38 ) | F_16 ( V_39 ) |
F_16 ( V_40 ) ;
V_2 -> V_41 [ F_17 ( V_6 ) ] = F_16 ( V_6 ) |
F_16 ( V_7 ) | F_16 ( V_8 ) | F_16 ( V_9 ) ;
V_2 -> V_42 [ 0 ] = F_16 ( V_15 ) ;
F_18 ( V_2 , V_10 , - 64 , 64 , 0 , 8 ) ;
F_18 ( V_2 , V_11 , - 64 , 64 , 0 , 8 ) ;
F_18 ( V_2 , V_12 , - 112 , 112 , 0 , 0 ) ;
F_18 ( V_2 , V_13 , - 1 , 1 , 0 , 0 ) ;
F_18 ( V_2 , V_14 , - 1 , 1 , 0 , 0 ) ;
F_10 ( V_16 , V_1 ) ;
V_23 = F_19 ( V_16 , V_22 ) ;
if ( V_23 )
goto V_43;
V_23 = F_20 ( V_1 -> V_3 ) ;
if ( V_23 )
goto V_44;
return 0 ;
V_44: F_9 ( V_16 ) ;
V_43: F_10 ( V_16 , NULL ) ;
V_26: F_21 ( V_2 ) ;
F_12 ( V_1 ) ;
return V_23 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_45 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_45 ) ;
}
