static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct F_1 * V_4 = V_3 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
V_6 = F_2 ( V_2 ) ;
V_8 = (struct V_7 * ) V_6 -> V_9 ;
V_8 -> V_10 = V_4 -> V_10 ;
V_8 -> V_11 = V_4 -> V_11 ? V_4 -> V_11 : L_1 ;
V_8 -> args = NULL ;
V_8 -> V_12 = NULL ;
V_8 -> V_2 = V_2 ;
F_3 ( L_2 , V_8 -> V_10 ?
V_8 -> V_10 : L_3 ) ;
F_4 ( V_8 , V_4 ) ;
F_3 ( L_4 ) ;
}
static int F_5 ( int V_13 , struct V_14 * V_15 , struct V_5 * V_16 )
{
struct V_7 * V_6 = (struct V_7 * ) & V_16 -> V_9 ;
if ( V_6 -> V_12 != NULL )
return F_6 ( V_6 -> V_12 , F_7 ( V_15 ) ,
V_15 -> V_2 -> V_17 + V_18 ) ;
F_3 ( V_19 L_5 ) ;
return - V_20 ;
}
static int F_8 ( int V_13 , struct V_14 * V_15 , struct V_5 * V_16 )
{
struct V_7 * V_6 = (struct V_7 * ) & V_16 -> V_9 ;
if ( V_6 -> V_12 != NULL )
return F_9 ( ( void * ) V_6 -> V_12 , V_15 -> V_3 ,
V_15 -> V_21 ) ;
F_3 ( V_19 L_6 ) ;
return - V_20 ;
}
static int F_10 ( char * V_22 , char * * V_23 , void * V_3 )
{
struct F_1 * V_4 = V_3 ;
char * V_24 , * V_25 = NULL , * V_26 = NULL , * V_27 ;
* V_4 = ( (struct F_1 )
{ . V_10 = NULL ,
. V_11 = NULL ,
. V_28 = 0 ,
. V_29 = NULL ,
. V_30 = 0 } ) ;
V_24 = F_11 ( V_22 , & V_4 -> V_10 , V_23 , & V_25 ,
& V_4 -> V_29 , & V_26 , & V_4 -> V_11 , NULL ) ;
if ( V_24 != NULL )
F_3 ( V_31 L_7
L_8 , V_24 ) ;
if ( V_25 != NULL ) {
V_4 -> V_28 = F_12 ( V_25 , & V_27 , 10 ) ;
if ( ( * V_27 != '\0' ) || ( V_27 == V_25 ) ) {
F_3 ( V_19 L_9 ,
V_25 ) ;
return 0 ;
}
}
if ( V_26 != NULL ) {
V_4 -> V_30 = F_12 ( V_26 , & V_27 , 8 ) ;
if ( ( * V_27 != '\0' ) || ( V_27 == V_26 ) ) {
F_3 ( V_19 L_10 ,
V_26 ) ;
return 0 ;
}
}
F_3 ( V_32 L_11 , V_4 -> V_10 ?
V_4 -> V_10 : L_3 ) ;
return 1 ;
}
static int F_13 ( void )
{
F_14 ( & V_33 ) ;
return 0 ;
}
