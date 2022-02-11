static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
if ( ! V_1 -> V_5 ) return;
F_2 ( V_3 , V_6 , ( ( V_4 [ 0 ] & 0x20 ) >> 5 ) ) ;
F_2 ( V_3 , V_7 , ( ( V_4 [ 0 ] & 0x10 ) >> 4 ) ) ;
F_2 ( V_3 , V_8 , ( ( V_4 [ 0 ] & 0x08 ) >> 3 ) ) ;
F_2 ( V_3 , V_9 , ( ( V_4 [ 0 ] & 0x04 ) >> 2 ) ) ;
F_2 ( V_3 , V_10 , ( ( V_4 [ 3 ] & 0x20 ) >> 5 ) ) ;
F_2 ( V_3 , V_11 , ( ( V_4 [ 3 ] & 0x10 ) >> 4 ) ) ;
F_2 ( V_3 , V_12 , ( ( V_4 [ 3 ] & 0x08 ) >> 3 ) ) ;
F_2 ( V_3 , V_13 , ( ( V_4 [ 3 ] & 0x04 ) >> 2 ) ) ;
F_2 ( V_3 , V_14 , ( ( V_4 [ 3 ] & 0x02 ) >> 1 ) ) ;
F_2 ( V_3 , V_15 , ( V_4 [ 3 ] & 0x01 ) ) ;
F_3 ( V_3 , V_16 , ( V_4 [ 1 ] & 0x3F ) - ( ( V_4 [ 0 ] & 0x01 ) << 6 ) ) ;
F_3 ( V_3 , V_17 , ( ( V_4 [ 0 ] & 0x02 ) << 5 ) - ( V_4 [ 2 ] & 0x3F ) ) ;
F_4 ( V_3 ) ;
return;
}
static T_1 F_5 ( struct V_18 * V_18 ,
unsigned char V_4 , unsigned int V_19 )
{
struct V_1 * V_1 = F_6 ( V_18 ) ;
if ( V_1 -> V_5 < V_20 )
V_1 -> V_4 [ V_1 -> V_5 ++ ] = V_4 ;
if ( V_1 -> V_5 == 4 ) {
F_1 ( V_1 ) ;
V_1 -> V_5 = 0 ;
}
return V_21 ;
}
static void F_7 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = F_6 ( V_18 ) ;
F_8 ( V_18 ) ;
F_9 ( V_18 , NULL ) ;
F_10 ( V_1 -> V_3 ) ;
F_11 ( V_1 ) ;
}
static int F_12 ( struct V_18 * V_18 , struct V_22 * V_23 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_24 = - V_25 ;
V_1 = F_13 ( sizeof( struct V_1 ) , V_26 ) ;
V_2 = F_14 () ;
if ( ! V_1 || ! V_2 )
goto V_27;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_28 , sizeof( V_1 -> V_28 ) , L_1 , V_18 -> V_28 ) ;
V_2 -> V_29 = L_2 ;
V_2 -> V_28 = V_1 -> V_28 ;
V_2 -> V_30 . V_31 = V_32 ;
V_2 -> V_30 . V_33 = V_34 ;
V_2 -> V_30 . V_35 = 0x0001 ;
V_2 -> V_30 . V_36 = 0x0100 ;
V_2 -> V_3 . V_37 = & V_18 -> V_3 ;
V_2 -> V_38 [ 0 ] = F_15 ( V_39 ) | F_15 ( V_40 ) ;
V_2 -> V_41 [ F_16 ( V_6 ) ] = F_15 ( V_6 ) | F_15 ( V_7 ) |
F_15 ( V_8 ) | F_15 ( V_9 ) | F_15 ( V_10 ) |
F_15 ( V_11 ) | F_15 ( V_12 ) | F_15 ( V_13 ) |
F_15 ( V_15 ) | F_15 ( V_14 ) ;
F_17 ( V_2 , V_16 , - 64 , 64 , 0 , 4 ) ;
F_17 ( V_2 , V_17 , - 64 , 64 , 0 , 4 ) ;
F_9 ( V_18 , V_1 ) ;
V_24 = F_18 ( V_18 , V_23 ) ;
if ( V_24 )
goto V_42;
V_24 = F_19 ( V_1 -> V_3 ) ;
if ( V_24 )
goto V_43;
return 0 ;
V_43: F_8 ( V_18 ) ;
V_42: F_9 ( V_18 , NULL ) ;
V_27: F_20 ( V_2 ) ;
F_11 ( V_1 ) ;
return V_24 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_44 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_44 ) ;
}
