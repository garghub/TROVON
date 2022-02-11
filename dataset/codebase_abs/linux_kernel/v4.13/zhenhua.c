static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
unsigned char * V_4 = V_1 -> V_4 ;
F_2 ( V_3 , V_5 , V_4 [ 1 ] ) ;
F_2 ( V_3 , V_6 , V_4 [ 2 ] ) ;
F_2 ( V_3 , V_7 , V_4 [ 3 ] ) ;
F_2 ( V_3 , V_8 , V_4 [ 4 ] ) ;
F_3 ( V_3 ) ;
}
static T_1 F_4 ( struct V_9 * V_9 , unsigned char V_4 , unsigned int V_10 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
if ( V_4 == 0xef )
V_1 -> V_11 = 0 ;
else if ( V_1 -> V_11 == 0 )
return V_12 ;
if ( V_1 -> V_11 < V_13 )
V_1 -> V_4 [ V_1 -> V_11 ++ ] = F_6 ( V_4 ) ;
if ( V_1 -> V_11 == V_13 ) {
F_1 ( V_1 ) ;
V_1 -> V_11 = 0 ;
}
return V_12 ;
}
static void F_7 ( struct V_9 * V_9 )
{
struct V_1 * V_1 = F_5 ( V_9 ) ;
F_8 ( V_9 ) ;
F_9 ( V_9 , NULL ) ;
F_10 ( V_1 -> V_3 ) ;
F_11 ( V_1 ) ;
}
static int F_12 ( struct V_9 * V_9 , struct V_14 * V_15 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_16 = - V_17 ;
V_1 = F_13 ( sizeof( struct V_1 ) , V_18 ) ;
V_2 = F_14 () ;
if ( ! V_1 || ! V_2 )
goto V_19;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_20 , sizeof( V_1 -> V_20 ) , L_1 , V_9 -> V_20 ) ;
V_2 -> V_21 = L_2 ;
V_2 -> V_20 = V_1 -> V_20 ;
V_2 -> V_22 . V_23 = V_24 ;
V_2 -> V_22 . V_25 = V_26 ;
V_2 -> V_22 . V_27 = 0x0001 ;
V_2 -> V_22 . V_28 = 0x0100 ;
V_2 -> V_3 . V_29 = & V_9 -> V_3 ;
V_2 -> V_30 [ 0 ] = F_15 ( V_31 ) ;
F_16 ( V_2 , V_6 , 50 , 200 , 0 , 0 ) ;
F_16 ( V_2 , V_5 , 50 , 200 , 0 , 0 ) ;
F_16 ( V_2 , V_8 , 50 , 200 , 0 , 0 ) ;
F_16 ( V_2 , V_7 , 50 , 200 , 0 , 0 ) ;
F_9 ( V_9 , V_1 ) ;
V_16 = F_17 ( V_9 , V_15 ) ;
if ( V_16 )
goto V_32;
V_16 = F_18 ( V_1 -> V_3 ) ;
if ( V_16 )
goto V_33;
return 0 ;
V_33: F_8 ( V_9 ) ;
V_32: F_9 ( V_9 , NULL ) ;
V_19: F_19 ( V_2 ) ;
F_11 ( V_1 ) ;
return V_16 ;
}
