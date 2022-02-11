int F_1 ( T_1 * V_1 , const char * V_2 , int V_3 ,
T_2 * V_4 , T_3 * V_5 , int V_6 )
{
const T_4 * V_7 ;
const T_5 * V_8 ;
int V_9 , V_10 ;
T_6 * V_11 ;
if ( ! F_2 ( V_12 , F_3 ( V_1 ) ,
& V_9 , & V_10 , & V_11 ) ) {
char V_13 [ 80 ] ;
F_4 ( V_14 , V_15 ) ;
if ( ! V_1 )
F_5 ( V_13 , L_1 , sizeof V_13 ) ;
else
F_6 ( V_13 , sizeof V_13 , V_1 ) ;
F_7 ( 2 , L_2 , V_13 ) ;
return 0 ;
}
if ( ! V_2 )
V_3 = 0 ;
else if ( V_3 == - 1 )
V_3 = strlen ( V_2 ) ;
if ( V_9 == - 1 )
V_7 = NULL ;
else {
V_7 = F_8 ( V_9 ) ;
if ( ! V_7 ) {
F_4 ( V_14 , V_16 ) ;
return 0 ;
}
}
if ( V_10 == - 1 )
V_8 = NULL ;
else {
V_8 = F_9 ( V_10 ) ;
if ( ! V_8 ) {
F_4 ( V_14 , V_17 ) ;
return 0 ;
}
}
if ( ! V_11 ( V_5 , V_2 , V_3 , V_4 , V_7 , V_8 , V_6 ) ) {
F_4 ( V_14 , V_18 ) ;
return 0 ;
}
return 1 ;
}
static int F_10 ( const T_7 * V_19 , const T_7 * V_20 )
{
int V_21 = V_19 -> V_22 - V_20 -> V_22 ;
if ( V_21 )
return V_21 ;
else
return V_19 -> V_23 - V_20 -> V_23 ;
}
static int F_11 ( const T_7 * const * V_24 , const T_7 * const * V_25 )
{
int V_21 = ( * V_24 ) -> V_22 - ( * V_25 ) -> V_22 ;
if ( V_21 )
return V_21 ;
else
return ( * V_24 ) -> V_23 - ( * V_25 ) -> V_23 ;
}
int F_12 ( int V_22 , int V_23 , int V_9 ,
int V_10 , T_6 * V_11 )
{
T_7 * V_26 ;
if ( V_27 == NULL ) {
V_27 = F_13 ( F_11 ) ;
if ( V_27 == NULL )
goto V_28;
}
if ( ( V_26 = F_14 ( sizeof( * V_26 ) ) ) == NULL )
goto V_28;
V_26 -> V_22 = V_22 ;
V_26 -> V_23 = V_23 ;
V_26 -> V_9 = V_9 ;
V_26 -> V_10 = V_10 ;
V_26 -> V_11 = V_11 ;
if ( ! F_15 ( V_27 , V_26 ) ) {
F_16 ( V_26 ) ;
goto V_28;
}
return 1 ;
V_28:
F_4 ( V_29 , V_30 ) ;
return 0 ;
}
int F_17 ( int V_31 , const T_4 * V_7 , const T_5 * V_8 ,
T_6 * V_11 )
{
int V_9 , V_10 ;
if ( V_7 )
V_9 = F_18 ( V_7 ) ;
else
V_9 = - 1 ;
if ( V_8 )
V_10 = F_19 ( V_8 ) ;
else
V_10 = - 1 ;
return F_12 ( V_12 , V_31 ,
V_9 , V_10 , V_11 ) ;
}
int F_2 ( int type , int V_23 ,
int * V_32 , int * V_33 , T_6 * * V_34 )
{
T_7 * V_35 = NULL , V_36 ;
int V_37 ;
if ( V_23 == V_38 )
return 0 ;
V_36 . V_22 = type ;
V_36 . V_23 = V_23 ;
if ( V_27 ) {
V_37 = F_20 ( V_27 , & V_36 ) ;
if ( V_37 != - 1 )
V_35 = F_21 ( V_27 , V_37 ) ;
}
if ( V_35 == NULL ) {
V_35 = F_22 ( & V_36 , V_39 , F_23 ( V_39 ) ) ;
}
if ( V_35 == NULL )
return 0 ;
if ( V_32 )
* V_32 = V_35 -> V_9 ;
if ( V_33 )
* V_33 = V_35 -> V_10 ;
if ( V_34 )
* V_34 = V_35 -> V_11 ;
return 1 ;
}
static void F_24 ( T_7 * V_40 )
{
F_16 ( V_40 ) ;
}
void F_25 ( void )
{
F_26 ( V_27 , F_24 ) ;
V_27 = NULL ;
}
int F_27 ( int * V_41 , int * V_42 , T_8 V_43 )
{
const T_7 * V_44 ;
if ( V_43 >= F_23 ( V_39 ) )
return 0 ;
V_44 = V_39 + V_43 ;
if ( V_41 )
* V_41 = V_44 -> V_22 ;
if ( V_42 )
* V_42 = V_44 -> V_23 ;
return 1 ;
}
