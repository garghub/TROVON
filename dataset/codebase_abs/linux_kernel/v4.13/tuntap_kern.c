static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct F_1 * V_8 = V_3 ;
V_5 = F_2 ( V_2 ) ;
V_7 = (struct V_6 * ) V_5 -> V_9 ;
V_7 -> V_10 = V_8 -> V_10 ;
V_7 -> V_11 = ( V_8 -> V_10 != NULL ) ;
V_7 -> V_12 = V_8 -> V_12 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_2 = V_2 ;
F_3 ( V_14 L_1 ) ;
if ( V_7 -> V_12 != NULL )
F_3 ( V_15 L_2 , V_7 -> V_12 ) ;
F_3 ( V_15 L_3 ) ;
}
static int F_4 ( int V_13 , struct V_16 * V_17 , struct V_4 * V_18 )
{
return F_5 ( V_13 , F_6 ( V_17 ) ,
V_17 -> V_2 -> V_19 + V_20 ) ;
}
static int F_7 ( int V_13 , struct V_16 * V_17 , struct V_4 * V_18 )
{
return F_8 ( V_13 , V_17 -> V_3 , V_17 -> V_21 ) ;
}
int F_9 ( char * V_22 , char * * V_23 , void * V_3 )
{
struct F_1 * V_8 = V_3 ;
* V_8 = ( (struct F_1 )
{ . V_10 = NULL ,
. V_12 = NULL } ) ;
if ( F_10 ( V_22 , L_4 , & V_8 -> V_10 , V_23 ,
& V_8 -> V_12 ) )
return 0 ;
return 1 ;
}
static int F_11 ( void )
{
F_12 ( & V_24 ) ;
return 0 ;
}
