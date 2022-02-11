void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct F_1 * V_8 = V_3 ;
V_5 = F_2 ( V_2 ) ;
V_7 = (struct V_6 * ) V_5 -> V_9 ;
V_7 -> V_10 = V_8 -> V_10 ;
V_7 -> V_11 = V_8 -> V_11 ;
V_7 -> V_12 = V_8 -> V_12 ;
V_7 -> V_13 = V_8 -> V_13 ;
F_3 ( L_1 , V_7 -> V_10 ) ;
}
static int F_4 ( int V_14 , struct V_15 * V_16 , struct V_4 * V_17 )
{
return F_5 ( V_14 , F_6 ( V_16 ) ,
V_16 -> V_2 -> V_18 + V_19 ,
(struct V_6 * ) & V_17 -> V_9 ) ;
}
static int F_7 ( int V_14 , struct V_15 * V_16 , struct V_4 * V_17 )
{
return - V_20 ;
}
int F_8 ( char * V_21 , char * * V_22 , void * V_3 )
{
struct F_1 * V_8 = V_3 ;
char * V_23 , * V_10 = NULL , * V_24 [ 2 ] = { NULL , NULL } ;
int V_25 ;
* V_8 = ( (struct F_1 )
{ . V_10 = L_2 ,
. V_11 = 1 ,
. V_12 = 0 ,
. V_13 = NULL } ) ;
V_23 = F_9 ( V_21 , & V_10 , & V_8 -> V_13 ,
& V_24 [ 0 ] , & V_24 [ 1 ] , V_22 , NULL ) ;
if ( V_23 != NULL ) {
F_3 ( V_26 L_3
L_4 , V_23 ) ;
return 0 ;
}
if ( V_10 != NULL )
V_8 -> V_10 = V_10 ;
for ( V_25 = 0 ; V_25 < F_10 ( V_24 ) ; V_25 ++ ) {
if ( V_24 [ V_25 ] == NULL )
continue;
if ( ! strcmp ( V_24 [ V_25 ] , L_5 ) )
V_8 -> V_11 = 1 ;
else if ( ! strcmp ( V_24 [ V_25 ] , L_6 ) )
V_8 -> V_11 = 0 ;
else if ( ! strcmp ( V_24 [ V_25 ] , L_7 ) )
V_8 -> V_12 = 1 ;
else if ( ! strcmp ( V_24 [ V_25 ] , L_8 ) )
V_8 -> V_12 = 0 ;
else {
F_3 ( V_26 L_9 ,
V_24 [ V_25 ] ) ;
return 0 ;
}
}
return 1 ;
}
static int F_11 ( void )
{
F_12 ( & V_27 ) ;
return 0 ;
}
