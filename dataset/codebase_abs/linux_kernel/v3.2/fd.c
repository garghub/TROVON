static void * F_1 ( char * V_1 , int V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
char * V_7 ;
int V_8 ;
if ( * V_1 != ':' ) {
F_2 ( V_9 L_1
L_2 ) ;
return NULL ;
}
V_1 ++ ;
V_8 = strtoul ( V_1 , & V_7 , 0 ) ;
if ( ( * V_7 != '\0' ) || ( V_7 == V_1 ) ) {
F_2 ( V_9 L_3
L_4 , V_1 ) ;
return NULL ;
}
V_6 = F_3 ( sizeof( * V_6 ) , V_10 ) ;
if ( V_6 == NULL )
return NULL ;
* V_6 = ( (struct V_5 ) { . V_11 = V_8 ,
. V_12 = V_4 -> V_12 } ) ;
return V_6 ;
}
static int F_4 ( int V_13 , int V_14 , int V_15 , void * V_16 , char * * V_17 )
{
struct V_5 * V_6 = V_16 ;
int V_18 ;
if ( V_6 -> V_12 && F_5 ( V_6 -> V_11 ) ) {
F_6 ( V_18 = F_7 ( V_6 -> V_11 , & V_6 -> V_19 ) ) ;
if ( V_18 )
return V_18 ;
V_18 = V_12 ( V_6 -> V_11 ) ;
if ( V_18 )
return V_18 ;
}
sprintf ( V_6 -> V_1 , L_5 , V_6 -> V_11 ) ;
* V_17 = V_6 -> V_1 ;
return V_6 -> V_11 ;
}
static void F_8 ( int V_11 , void * V_16 )
{
struct V_5 * V_6 = V_16 ;
int V_18 ;
if ( ! V_6 -> V_12 || ! F_5 ( V_11 ) )
return;
F_6 ( V_18 = F_9 ( V_11 , V_20 , & V_6 -> V_19 ) ) ;
if ( V_18 )
F_2 ( V_9 L_6
L_7 , - V_18 ) ;
V_6 -> V_12 = 0 ;
}
