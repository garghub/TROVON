static void F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 != V_8 )
F_2 ( V_3 , V_6 -> V_9 | ( ( V_4 & 0x6 ) << 1 ) ) ;
}
static int T_1 F_3 ( void )
{
struct V_5 * V_10 ;
void T_2 * V_11 ;
if ( ! F_4 () )
return - V_12 ;
V_11 = F_5 ( 0x08000000 , 0x1000 ) ;
if ( ! V_11 ) {
F_6 ( L_1 ) ;
return - V_13 ;
}
V_14 = F_7 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_15 ) ;
if ( ! V_14 ) {
F_6 ( L_2 ) ;
F_8 ( ( void * ) V_11 ) ;
return - V_13 ;
}
V_10 = (struct V_5 * ) ( & V_14 [ 1 ] ) ;
memset ( V_14 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_5 ) ) ;
V_14 -> V_7 = V_10 ;
V_14 -> V_16 = V_17 ;
F_9 ( 37 ) = F_10 ( 37 ) ;
V_10 -> V_18 = V_11 ;
V_10 -> V_9 = V_11 ;
V_10 -> V_19 = F_1 ;
V_10 -> V_20 = NULL ;
V_10 -> V_21 = 50 ;
V_10 -> V_22 . V_23 = V_24 ;
if ( F_11 ( V_14 , 1 ) ) {
F_6 ( V_25 L_3 ) ;
F_12 ( V_14 ) ;
F_8 ( ( void * ) V_11 ) ;
return - V_26 ;
}
F_13 ( V_14 , NULL , NULL , V_27 ,
V_28 ) ;
return 0 ;
}
static void T_3 F_14 ( void )
{
struct V_5 * V_10 = (struct V_5 * ) & V_14 [ 1 ] ;
F_15 ( V_14 ) ;
F_8 ( ( void * ) V_10 -> V_9 ) ;
F_12 ( V_14 ) ;
}
