static void * F_1 ( char * V_1 , int V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
* V_6 = ( (struct V_5 ) { . V_8 = V_4 -> V_8 ,
. V_9 = V_2 ,
. V_10 = V_4 -> V_10 } ) ;
return V_6 ;
}
static int F_3 ( int V_11 , int V_12 , int V_13 , void * V_14 ,
char * * V_15 )
{
struct V_5 * V_6 = V_14 ;
char * V_9 ;
int V_16 , V_17 ;
V_16 = F_4 () ;
if ( V_16 < 0 ) {
V_17 = - V_18 ;
F_5 ( V_19 L_1 ) ;
return V_17 ;
}
if ( V_6 -> V_10 ) {
F_6 ( V_17 = F_7 ( V_16 , & V_6 -> V_20 ) ) ;
if ( V_17 )
goto V_21;
V_17 = V_10 ( V_16 ) ;
if ( V_17 )
goto V_21;
}
V_9 = F_8 ( V_16 ) ;
sprintf ( V_6 -> V_22 , L_2 , V_9 ) ;
* V_15 = V_6 -> V_22 ;
if ( V_6 -> V_8 )
(* V_6 -> V_8 )( V_9 , V_6 -> V_9 ) ;
return V_16 ;
V_21:
F_9 ( V_16 ) ;
return V_17 ;
}
static int F_10 ( char * line )
{
struct V_23 V_24 ;
char * V_25 , * V_26 , * V_27 ;
int V_28 , V_17 ;
V_25 = & line [ strlen ( L_3 ) ] ;
for ( V_26 = L_4 ; * V_26 ; V_26 ++ ) {
line [ strlen ( L_5 ) ] = * V_26 ;
* V_25 = '0' ;
if ( ( V_23 ( line , & V_24 ) < 0 ) && ( V_18 == V_29 ) )
break;
for ( V_27 = L_6 ; * V_27 ; V_27 ++ ) {
* V_25 = * V_27 ;
V_28 = F_11 ( line , V_30 ) ;
if ( V_28 >= 0 ) {
char * V_31 = & line [ strlen ( L_7 ) ] ;
* V_31 = 't' ;
V_17 = F_12 ( line , V_32 | V_33 ) ;
* V_31 = 'p' ;
if ( ! V_17 )
return V_28 ;
F_9 ( V_28 ) ;
}
}
}
F_5 ( V_19 L_8 ) ;
return - V_29 ;
}
static int F_13 ( int V_11 , int V_12 , int V_13 , void * V_14 ,
char * * V_15 )
{
struct V_5 * V_6 = V_14 ;
int V_16 , V_17 ;
char V_9 [ sizeof( L_9 ) ] = L_10 ;
V_16 = F_10 ( V_9 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_6 -> V_10 ) {
V_17 = V_10 ( V_16 ) ;
if ( V_17 ) {
F_9 ( V_16 ) ;
return V_17 ;
}
}
if ( V_6 -> V_8 )
(* V_6 -> V_8 )( V_9 , V_6 -> V_9 ) ;
sprintf ( V_6 -> V_22 , L_2 , V_9 ) ;
* V_15 = V_6 -> V_22 ;
return V_16 ;
}
