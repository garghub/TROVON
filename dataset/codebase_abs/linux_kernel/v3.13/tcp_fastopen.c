void F_1 ( bool V_1 )
{
static T_1 V_2 [ V_3 ] ;
if ( F_2 ( V_2 , sizeof( V_2 ) ) && V_1 )
F_3 ( V_2 , sizeof( V_2 ) ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 =
F_5 ( V_5 , struct V_6 , V_8 ) ;
F_6 ( V_7 -> V_9 ) ;
F_7 ( V_7 ) ;
}
int F_3 ( void * V_2 , unsigned int V_10 )
{
int V_11 ;
struct V_6 * V_7 , * V_12 ;
V_7 = F_8 ( sizeof( * V_7 ) , V_13 ) ;
if ( ! V_7 )
return - V_14 ;
V_7 -> V_9 = F_9 ( L_1 , 0 , 0 ) ;
if ( F_10 ( V_7 -> V_9 ) ) {
V_11 = F_11 ( V_7 -> V_9 ) ;
error: F_7 ( V_7 ) ;
F_12 ( L_2 , V_11 ) ;
return V_11 ;
}
V_11 = F_13 ( V_7 -> V_9 , V_2 , V_10 ) ;
if ( V_11 ) {
F_12 ( L_3 , V_11 ) ;
F_6 ( V_7 -> V_9 ) ;
goto error;
}
memcpy ( V_7 -> V_2 , V_2 , V_10 ) ;
F_14 ( & V_15 ) ;
V_12 = F_15 ( V_16 ,
F_16 ( & V_15 ) ) ;
F_17 ( V_16 , V_7 ) ;
F_18 ( & V_15 ) ;
if ( V_12 )
F_19 ( & V_12 -> V_8 , F_4 ) ;
return V_11 ;
}
void F_20 ( T_2 V_17 , T_2 V_18 ,
struct V_19 * V_20 )
{
T_2 V_21 [ 4 ] = { V_17 , V_18 , 0 , 0 } ;
struct V_6 * V_7 ;
F_1 ( true ) ;
F_21 () ;
V_7 = F_22 ( V_16 ) ;
if ( V_7 ) {
F_23 ( V_7 -> V_9 , V_20 -> V_22 , ( V_23 * ) V_21 ) ;
V_20 -> V_10 = V_24 ;
}
F_24 () ;
}
