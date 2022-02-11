static void * F_1 ( char * V_1 , int V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_6 == NULL )
return NULL ;
* V_6 = ( (struct V_5 ) { . V_8 = - 1 ,
. V_9 = - 1 ,
. V_2 = V_2 ,
. V_10 = V_4 -> V_11 ,
. V_12 = V_4 -> V_12 } ) ;
return V_6 ;
}
static int T_1 F_3 ( char * line , int * V_13 )
{
* V_13 = 0 ;
V_14 = line ;
line = strchr ( line , ',' ) ;
if ( line == NULL )
return 0 ;
* line ++ = '\0' ;
if ( * line )
V_15 = line ;
line = strchr ( line , ',' ) ;
if ( line == NULL )
return 0 ;
* line ++ = '\0' ;
if ( * line )
V_16 = line ;
return 0 ;
}
static int F_4 ( int V_17 , int V_18 , int V_19 , void * V_20 ,
char * * V_21 )
{
struct V_5 * V_6 = V_20 ;
int V_8 , V_22 , V_23 , V_24 ;
char V_10 [ 256 ] , V_25 [] = L_1 ;
char * V_26 [] = { V_14 , V_15 , V_10 , V_16 ,
V_27 L_2 , L_3 ,
V_25 , NULL } ;
if ( F_5 ( V_26 [ 4 ] , V_28 ) < 0 )
V_26 [ 4 ] = L_4 ;
if ( getenv ( L_5 ) == NULL ) {
F_6 ( V_29 L_6 ) ;
return - V_30 ;
}
V_22 = F_7 ( V_25 ) ;
if ( V_22 < 0 ) {
V_24 = - V_31 ;
F_6 ( V_29 L_7 ,
V_31 ) ;
return V_24 ;
}
if ( F_8 ( V_25 ) ) {
V_24 = - V_31 ;
F_6 ( V_29 L_8 ,
V_31 ) ;
return V_24 ;
}
F_9 ( V_22 ) ;
V_22 = F_10 ( V_25 , sizeof( V_25 ) , 1 ) ;
if ( V_22 < 0 ) {
F_6 ( V_29 L_9
L_10 , - V_22 ) ;
return V_22 ;
}
sprintf ( V_10 , V_6 -> V_10 , V_6 -> V_2 ) ;
V_8 = F_11 ( NULL , NULL , V_26 ) ;
if ( V_8 < 0 ) {
V_24 = V_8 ;
F_6 ( V_29 L_11
L_10 , - V_24 ) ;
goto V_32;
}
V_24 = F_12 ( V_22 , 0 ) ;
if ( V_24 < 0 ) {
F_6 ( V_29 L_12
L_13 , - V_24 ) ;
goto V_33;
}
V_23 = F_13 ( V_22 , & V_6 -> V_9 ) ;
if ( V_23 < 0 ) {
V_24 = V_23 ;
F_6 ( V_29 L_14 ,
- V_24 ) ;
goto V_33;
}
V_24 = F_12 ( V_23 , 0 ) ;
if ( V_24 ) {
F_6 ( V_29 L_15
L_16 , - V_24 ) ;
goto V_34;
}
F_14 ( V_24 = F_15 ( V_23 , & V_6 -> V_35 ) ) ;
if ( V_24 ) {
V_23 = V_24 ;
goto V_34;
}
if ( V_6 -> V_12 ) {
V_24 = V_12 ( V_23 ) ;
if ( V_24 ) {
V_23 = V_24 ;
goto V_34;
}
}
F_8 ( V_25 ) ;
V_6 -> V_8 = V_8 ;
* V_21 = NULL ;
return V_23 ;
V_34:
F_9 ( V_23 ) ;
V_33:
F_16 ( V_8 , 1 ) ;
V_32:
F_9 ( V_22 ) ;
return V_24 ;
}
static void F_17 ( int V_22 , void * V_20 )
{
struct V_5 * V_6 = V_20 ;
if ( V_6 -> V_8 != - 1 )
F_16 ( V_6 -> V_8 , 1 ) ;
V_6 -> V_8 = - 1 ;
if ( V_6 -> V_9 != - 1 )
F_16 ( V_6 -> V_9 , 0 ) ;
V_6 -> V_9 = - 1 ;
F_18 ( V_22 ) ;
}
