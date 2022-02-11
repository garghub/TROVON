static void * F_1 ( char * V_1 , int V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
void * V_7 ;
char * V_8 ;
int V_9 ;
if ( * V_1 != ':' ) {
F_2 ( V_10 L_1
L_2 ) ;
return NULL ;
}
V_1 ++ ;
V_9 = strtoul ( V_1 , & V_8 , 0 ) ;
if ( ( * V_8 != '\0' ) || ( V_8 == V_1 ) ) {
F_2 ( V_10 L_3 ,
V_1 ) ;
return NULL ;
}
V_7 = F_3 ( V_9 ) ;
if ( V_7 == NULL )
return NULL ;
V_6 = F_4 ( sizeof( * V_6 ) , V_11 ) ;
if ( V_6 == NULL )
goto V_12;
* V_6 = ( (struct V_5 ) { . V_13 = V_4 -> V_13 ,
. V_14 = V_7 } ) ;
sprintf ( V_6 -> V_15 , L_4 , V_9 ) ;
return V_6 ;
V_12:
F_5 ( V_7 ) ;
return NULL ;
}
static void F_6 ( void * V_16 )
{
struct V_5 * V_6 = V_16 ;
F_5 ( V_6 -> V_14 ) ;
F_7 ( V_6 ) ;
}
static int F_8 ( int V_17 , int V_18 , int V_19 , void * V_16 ,
char * * V_20 )
{
struct V_5 * V_6 = V_16 ;
int V_21 , V_12 ;
V_21 = F_9 ( V_6 -> V_14 ) ;
if ( ( V_21 >= 0 ) && V_6 -> V_13 ) {
F_10 ( V_12 = F_11 ( V_21 , & V_6 -> V_22 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = V_13 ( V_21 ) ;
if ( V_12 )
return V_12 ;
}
* V_20 = V_6 -> V_15 ;
return V_21 ;
}
static void F_12 ( int V_21 , void * V_16 )
{
struct V_5 * V_6 = V_16 ;
F_13 ( V_6 -> V_14 ) ;
F_14 ( V_21 ) ;
}
int F_15 ( int V_9 )
{
struct V_23 V_24 ;
int V_21 , V_12 , V_25 ;
V_21 = F_16 ( V_26 , V_27 , 0 ) ;
if ( V_21 == - 1 )
return - V_28 ;
V_25 = 1 ;
if ( F_17 ( V_21 , V_29 , V_30 , & V_25 , sizeof( V_25 ) ) < 0 ) {
V_12 = - V_28 ;
goto V_31;
}
V_24 . V_32 = V_33 ;
V_24 . V_34 = F_18 ( V_9 ) ;
V_24 . V_35 . V_36 = F_19 ( V_37 ) ;
if ( F_20 ( V_21 , (struct V_38 * ) & V_24 , sizeof( V_24 ) ) < 0 ) {
V_12 = - V_28 ;
goto V_31;
}
if ( F_21 ( V_21 , 1 ) < 0 ) {
V_12 = - V_28 ;
goto V_31;
}
V_12 = F_22 ( V_21 , 0 ) ;
if ( V_12 < 0 )
goto V_31;
return V_21 ;
V_31:
F_23 ( V_21 ) ;
return V_12 ;
}
static void F_24 ( void * V_25 )
{
struct V_39 * V_6 = V_25 ;
F_25 ( V_6 -> V_40 , 0 ) ;
F_25 ( V_6 -> V_40 , 1 ) ;
F_25 ( V_6 -> V_40 , 2 ) ;
F_23 ( V_6 -> V_40 ) ;
F_25 ( V_6 -> V_41 , 3 ) ;
F_26 ( 3 , V_42 ) ;
F_23 ( V_6 -> V_41 ) ;
}
int F_27 ( int V_21 , int * F_16 , int * V_43 )
{
int V_44 , V_12 ;
char * V_45 [] = { L_5 , L_6 ,
L_7 , NULL } ;
struct V_39 V_6 ;
V_44 = F_28 ( V_21 , NULL , 0 ) ;
if ( V_44 < 0 )
return - V_28 ;
V_12 = F_29 ( F_16 , 0 , 0 ) ;
if ( V_12 < 0 )
goto V_46;
V_6 = ( (struct V_39 )
{ . V_40 = V_44 ,
. V_41 = F_16 [ 1 ] } ) ;
V_12 = F_30 ( F_24 , & V_6 , V_45 ) ;
if ( V_12 < 0 )
goto V_47;
* V_43 = V_12 ;
return V_44 ;
V_47:
F_26 ( F_16 [ 0 ] , V_48 ) ;
F_23 ( F_16 [ 0 ] ) ;
F_26 ( F_16 [ 1 ] , V_48 ) ;
F_23 ( F_16 [ 1 ] ) ;
V_46:
F_23 ( V_44 ) ;
return V_12 ;
}
