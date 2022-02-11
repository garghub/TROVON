static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 = V_3 ;
V_5 = F_2 ( V_2 ) ;
V_7 = (struct V_6 * ) V_5 -> V_10 ;
V_7 -> V_11 = V_9 -> V_11 ;
V_7 -> V_12 = V_9 -> V_12 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_14 = - 1 ;
V_7 -> V_2 = V_2 ;
F_3 ( V_15 L_1 , V_7 -> V_11 ) ;
if ( V_7 -> V_12 != NULL )
F_3 ( V_16 L_2 , V_7 -> V_12 ) ;
F_3 ( V_16 L_3 ) ;
}
static int F_4 ( int V_17 , struct V_18 * V_19 , struct V_4 * V_20 )
{
int V_21 ;
V_21 = F_5 ( V_17 , F_6 ( V_19 ) ,
V_19 -> V_2 -> V_22 + 2 + V_23 ) ;
if ( V_21 <= 0 )
return ( V_21 ) ;
F_7 ( V_19 , 2 ) ;
V_21 -= 2 ;
return V_21 ;
}
static int F_8 ( int V_17 , struct V_18 * V_19 , struct V_4 * V_20 )
{
F_9 ( V_19 , 2 ) ;
return F_10 ( V_17 , V_19 -> V_3 , V_19 -> V_21 ) ;
}
int F_11 ( char * V_24 , char * * V_25 , void * V_3 )
{
struct V_8 * V_9 = V_3 ;
* V_9 = ( (struct V_8 )
{ . V_11 = NULL ,
. V_12 = NULL } ) ;
if ( F_12 ( V_24 , L_4 , & V_9 -> V_11 , V_25 ,
& V_9 -> V_12 ) )
return 0 ;
if ( V_9 -> V_11 == NULL ) {
F_3 ( V_26 L_5 ) ;
return 0 ;
}
return 1 ;
}
static int F_13 ( void )
{
F_14 ( & V_27 ) ;
return 0 ;
}
