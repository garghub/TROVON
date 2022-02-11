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
const char * V_11 = 0 ;
int V_12 = 0 ;
struct V_13 * V_14 = 0 ;
void T_2 * V_15 ;
if ( ! F_4 () )
return - V_16 ;
V_15 = F_5 ( 0x08000000 , 0x1000 ) ;
if ( ! V_15 ) {
F_6 ( L_1 ) ;
return - V_17 ;
}
V_18 = F_7 ( sizeof( struct V_1 ) + sizeof( struct V_5 ) , V_19 ) ;
if ( ! V_18 ) {
F_6 ( L_2 ) ;
F_8 ( ( void * ) V_15 ) ;
return - V_17 ;
}
V_10 = (struct V_5 * ) ( & V_18 [ 1 ] ) ;
memset ( V_18 , 0 , sizeof( struct V_1 ) ) ;
memset ( V_10 , 0 , sizeof( struct V_5 ) ) ;
V_18 -> V_7 = V_10 ;
V_18 -> V_20 = V_21 ;
F_9 ( 37 ) = F_10 ( 37 ) ;
V_10 -> V_22 = V_15 ;
V_10 -> V_9 = V_15 ;
V_10 -> V_23 = F_1 ;
V_10 -> V_24 = NULL ;
V_10 -> V_25 = 50 ;
V_10 -> V_26 . V_27 = V_28 ;
V_10 -> V_29 = V_30 ;
if ( F_11 ( V_18 , 1 ) ) {
F_6 ( V_31 L_3 ) ;
F_12 ( V_18 ) ;
F_8 ( ( void * ) V_15 ) ;
return - V_32 ;
}
#ifdef F_13
V_12 = F_14 ( V_18 , & V_14 , L_4 ) ;
if ( V_12 > 0 )
V_11 = L_5 ;
else
V_12 = 0 ;
#endif
if ( V_12 == 0 ) {
V_14 = V_33 ;
V_12 = V_34 ;
V_11 = L_6 ;
}
F_6 ( V_31 L_7 , V_11 ) ;
F_15 ( V_18 , V_14 , V_12 ) ;
return 0 ;
}
static void T_3 F_16 ( void )
{
struct V_5 * V_10 = (struct V_5 * ) & V_18 [ 1 ] ;
F_17 ( V_18 ) ;
F_8 ( ( void * ) V_10 -> V_9 ) ;
F_12 ( V_18 ) ;
}
