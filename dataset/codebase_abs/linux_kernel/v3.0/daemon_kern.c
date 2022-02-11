static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct F_1 * V_8 = V_3 ;
V_5 = F_2 ( V_2 ) ;
V_7 = (struct V_6 * ) V_5 -> V_9 ;
V_7 -> V_10 = V_8 -> V_10 ;
V_7 -> V_11 = V_8 -> V_11 ;
V_7 -> V_12 = - 1 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_14 = NULL ;
V_7 -> V_15 = NULL ;
V_7 -> V_16 = NULL ;
F_3 ( L_1 ,
V_17 , V_7 -> V_10 , V_7 -> V_11 ) ;
F_3 ( L_2 ) ;
}
static int F_4 ( int V_12 , struct V_18 * V_19 , struct V_4 * V_20 )
{
return F_5 ( V_12 , F_6 ( V_19 ) ,
V_19 -> V_2 -> V_21 + V_22 ) ;
}
static int F_7 ( int V_12 , struct V_18 * V_19 , struct V_4 * V_20 )
{
return F_8 ( V_12 , V_19 -> V_3 , V_19 -> V_23 ,
(struct V_6 * ) & V_20 -> V_9 ) ;
}
static int F_9 ( char * V_24 , char * * V_25 , void * V_3 )
{
struct F_1 * V_8 = V_3 ;
char * V_26 ;
* V_8 = ( (struct F_1 )
{ . V_10 = L_3 ,
. V_11 = L_4 } ) ;
V_26 = F_10 ( V_24 , V_25 , & V_8 -> V_10 , & V_8 -> V_11 ,
NULL ) ;
if ( V_26 != NULL )
F_3 ( V_27 L_5
L_6 ) ;
return 1 ;
}
static int F_11 ( void )
{
F_12 ( & V_28 ) ;
return 0 ;
}
