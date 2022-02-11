static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
int F_5 ( void * V_7 , unsigned int V_8 )
{
int V_9 ;
struct V_3 * V_4 , * V_10 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_4 -> V_6 = F_7 ( L_1 , 0 , 0 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
V_9 = F_9 ( V_4 -> V_6 ) ;
error: F_4 ( V_4 ) ;
F_10 ( L_2 , V_9 ) ;
return V_9 ;
}
V_9 = F_11 ( V_4 -> V_6 , V_7 , V_8 ) ;
if ( V_9 ) {
F_10 ( L_3 , V_9 ) ;
F_3 ( V_4 -> V_6 ) ;
goto error;
}
memcpy ( V_4 -> V_7 , V_7 , V_8 ) ;
F_12 ( & V_13 ) ;
V_10 = F_13 ( V_14 ,
F_14 ( & V_13 ) ) ;
F_15 ( V_14 , V_4 ) ;
F_16 ( & V_13 ) ;
if ( V_10 )
F_17 ( & V_10 -> V_5 , F_1 ) ;
return V_9 ;
}
void F_18 ( T_1 V_15 , T_1 V_16 ,
struct V_17 * V_18 )
{
T_1 V_19 [ 4 ] = { V_15 , V_16 , 0 , 0 } ;
struct V_3 * V_4 ;
F_19 () ;
V_4 = F_20 ( V_14 ) ;
if ( V_4 ) {
F_21 ( V_4 -> V_6 , V_18 -> V_20 , ( V_21 * ) V_19 ) ;
V_18 -> V_8 = V_22 ;
}
F_22 () ;
}
static int T_2 F_23 ( void )
{
V_21 V_7 [ V_23 ] ;
F_24 ( V_7 , sizeof( V_7 ) ) ;
F_5 ( V_7 , sizeof( V_7 ) ) ;
return 0 ;
}
