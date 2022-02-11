static int F_1 ( int V_1 )
{
V_1 = ( ( V_1 & 0xaa ) >> 1 ) | ( ( V_1 & 0x55 ) << 1 ) ;
V_1 = ( ( V_1 & 0xcc ) >> 2 ) | ( ( V_1 & 0x33 ) << 2 ) ;
V_1 = ( ( V_1 & 0xf0 ) >> 4 ) | ( ( V_1 & 0x0f ) << 4 ) ;
return V_1 ;
}
static void F_2 ( struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned char * V_5 = V_2 -> V_5 ;
F_3 ( V_4 , V_6 , V_5 [ 1 ] ) ;
F_3 ( V_4 , V_7 , V_5 [ 2 ] ) ;
F_3 ( V_4 , V_8 , V_5 [ 3 ] ) ;
F_3 ( V_4 , V_9 , V_5 [ 4 ] ) ;
F_4 ( V_4 ) ;
}
static T_1 F_5 ( struct V_10 * V_10 , unsigned char V_5 , unsigned int V_11 )
{
struct V_2 * V_2 = F_6 ( V_10 ) ;
if ( V_5 == 0xef )
V_2 -> V_12 = 0 ;
else if ( V_2 -> V_12 == 0 )
return V_13 ;
if ( V_2 -> V_12 < V_14 )
V_2 -> V_5 [ V_2 -> V_12 ++ ] = F_1 ( V_5 ) ;
if ( V_2 -> V_12 == V_14 ) {
F_2 ( V_2 ) ;
V_2 -> V_12 = 0 ;
}
return V_13 ;
}
static void F_7 ( struct V_10 * V_10 )
{
struct V_2 * V_2 = F_6 ( V_10 ) ;
F_8 ( V_10 ) ;
F_9 ( V_10 , NULL ) ;
F_10 ( V_2 -> V_4 ) ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_10 * V_10 , struct V_15 * V_16 )
{
struct V_2 * V_2 ;
struct V_3 * V_3 ;
int V_17 = - V_18 ;
V_2 = F_13 ( sizeof( struct V_2 ) , V_19 ) ;
V_3 = F_14 () ;
if ( ! V_2 || ! V_3 )
goto V_20;
V_2 -> V_4 = V_3 ;
snprintf ( V_2 -> V_21 , sizeof( V_2 -> V_21 ) , L_1 , V_10 -> V_21 ) ;
V_3 -> V_22 = L_2 ;
V_3 -> V_21 = V_2 -> V_21 ;
V_3 -> V_23 . V_24 = V_25 ;
V_3 -> V_23 . V_26 = V_27 ;
V_3 -> V_23 . V_28 = 0x0001 ;
V_3 -> V_23 . V_29 = 0x0100 ;
V_3 -> V_4 . V_30 = & V_10 -> V_4 ;
V_3 -> V_31 [ 0 ] = F_15 ( V_32 ) ;
F_16 ( V_3 , V_7 , 50 , 200 , 0 , 0 ) ;
F_16 ( V_3 , V_6 , 50 , 200 , 0 , 0 ) ;
F_16 ( V_3 , V_9 , 50 , 200 , 0 , 0 ) ;
F_16 ( V_3 , V_8 , 50 , 200 , 0 , 0 ) ;
F_9 ( V_10 , V_2 ) ;
V_17 = F_17 ( V_10 , V_16 ) ;
if ( V_17 )
goto V_33;
V_17 = F_18 ( V_2 -> V_4 ) ;
if ( V_17 )
goto V_34;
return 0 ;
V_34: F_8 ( V_10 ) ;
V_33: F_9 ( V_10 , NULL ) ;
V_20: F_19 ( V_3 ) ;
F_11 ( V_2 ) ;
return V_17 ;
}
