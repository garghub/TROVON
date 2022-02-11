void F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 ,
void * V_5 , T_2 V_6 )
{
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = ( 1 << V_6 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_7 = * V_3 ;
V_2 -> V_8 = * V_4 ;
}
static void F_2 ( struct V_1 * V_2 , void * V_9 ,
void * V_10 , T_1 V_6 )
{
T_1 V_11 , V_12 ;
if ( V_9 + V_6 >= V_2 -> V_5 + V_2 -> V_6 ) {
V_11 = ( T_1 ) ( V_2 -> V_5 + V_2 -> V_6 - V_9 ) ;
V_12 = V_6 - V_11 ;
F_3 ( ( void V_13 V_14 * ) V_9 , V_10 , V_11 ) ;
F_3 ( ( void V_13 V_14 * ) V_2 -> V_5 ,
V_10 + V_11 , V_12 ) ;
} else {
F_3 ( ( void V_13 V_14 * ) V_9 , V_10 , V_6 ) ;
}
}
static void F_4 ( struct V_1 * V_2 , void * V_9 ,
void * V_10 , T_1 V_6 )
{
T_1 V_11 , V_12 ;
if ( V_9 + V_6 >= V_2 -> V_5 + V_2 -> V_6 ) {
V_11 = ( T_1 ) ( V_2 -> V_5 + V_2 -> V_6 - V_9 ) ;
V_12 = V_6 - V_11 ;
F_5 ( V_10 , ( void V_13 V_14 * ) V_9 , V_11 ) ;
F_5 ( V_10 + V_11 ,
( void V_13 V_14 * ) V_2 -> V_5 , V_12 ) ;
} else {
F_5 ( V_10 , ( void V_13 V_14 * ) V_9 , V_6 ) ;
}
}
T_1 F_6 ( struct V_1 * V_2 )
{
V_2 -> V_7 = * V_2 -> V_3 ;
F_7 () ;
return F_8 ( V_2 -> V_8 ,
V_2 -> V_7 , V_2 -> V_6 ) ;
}
int F_9 ( struct V_1 * V_2 , void * V_10 , T_1 V_6 )
{
void * V_9 ;
if ( F_6 ( V_2 ) < V_6 )
return - V_15 ;
V_9 = V_2 -> V_5 + V_2 -> V_8 ;
F_2 ( V_2 , V_9 , V_10 , V_6 ) ;
V_2 -> V_8 =
( V_2 -> V_8 + V_6 ) & ( V_2 -> V_6 - 1 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 () ;
F_12 ( * V_2 -> V_4 ) = V_2 -> V_8 ;
#ifdef F_13
F_12 ( * V_2 -> V_4 ) = V_2 -> V_8 ;
#endif
}
static void * F_14 ( struct V_1 * V_2 , T_1 V_6 )
{
void * V_9 = NULL ;
if ( F_15 ( V_2 , V_6 ) >= V_6 )
V_9 = V_2 -> V_5 + V_2 -> V_7 ;
return V_9 ;
}
T_1 F_16 ( struct V_1 * V_2 , void * V_10 , T_1 V_6 )
{
void * V_9 = NULL ;
int V_16 = 0 ;
V_9 = F_14 ( V_2 , V_6 ) ;
if ( V_9 ) {
T_1 V_17 =
( V_2 -> V_7 + V_6 ) & ( V_2 -> V_6 - 1 ) ;
V_16 = V_6 ;
V_2 -> V_7 = V_17 ;
F_4 ( V_2 , V_9 , V_10 , V_6 ) ;
}
return V_16 ;
}
void F_17 ( struct V_1 * V_2 )
{
T_1 V_18 ;
V_18 = V_2 -> V_7 ;
F_7 () ;
F_12 ( * V_2 -> V_3 ) = V_18 ;
#ifdef F_13
F_12 ( * V_2 -> V_3 ) = V_18 ;
#endif
}
T_1 F_15 ( struct V_1 * V_2 , T_1 V_6 )
{
if ( F_18 ( V_2 -> V_8 ,
V_2 -> V_7 ,
V_2 -> V_6 ) < V_6 ) {
V_2 -> V_8 = * V_2 -> V_4 ;
F_19 () ;
}
return F_18 ( V_2 -> V_8 ,
V_2 -> V_7 ,
V_2 -> V_6 ) ;
}
