static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
char * * V_4 = V_3 -> V_4 ;
int V_5 , V_6 ;
if ( V_3 -> V_7 != NULL )
(* V_3 -> V_7 )( V_3 -> V_8 ) ;
V_5 = F_2 ( V_3 -> V_9 , V_4 [ 0 ] , V_4 ) ;
F_3 ( V_6 = F_4 ( V_3 -> V_10 , & V_5 , sizeof( V_5 ) ) ) ;
return 0 ;
}
int F_5 ( void (* V_7)( void * ) , void * V_8 , char * * V_4 )
{
struct V_2 V_3 ;
unsigned long V_11 , V_12 ;
int V_13 , V_14 [ 2 ] , V_6 , V_15 ;
V_11 = F_6 ( 0 , F_7 () ) ;
if ( V_11 == 0 )
return - V_16 ;
V_6 = F_8 ( V_17 , V_18 , 0 , V_14 ) ;
if ( V_6 < 0 ) {
V_6 = - V_19 ;
F_9 ( V_20 L_1 ,
V_19 ) ;
goto V_21;
}
V_6 = F_10 ( V_14 [ 1 ] ) ;
if ( V_6 < 0 ) {
F_9 ( V_20 L_2
L_3 , - V_6 ) ;
goto V_22;
}
V_12 = V_11 + V_23 - sizeof( void * ) ;
V_3 . V_7 = V_7 ;
V_3 . V_8 = V_8 ;
V_3 . V_4 = V_4 ;
V_3 . V_10 = V_14 [ 1 ] ;
V_3 . V_9 = F_7 () ? F_11 ( V_24 , V_25 ) :
F_11 ( V_24 , V_26 ) ;
V_13 = F_12 ( F_1 , ( void * ) V_12 , V_27 , & V_3 ) ;
if ( V_13 < 0 ) {
V_6 = - V_19 ;
F_9 ( V_20 L_4 ,
V_19 ) ;
goto V_28;
}
F_13 ( V_14 [ 1 ] ) ;
V_14 [ 1 ] = - 1 ;
V_15 = F_14 ( V_14 [ 0 ] , & V_6 , sizeof( V_6 ) ) ;
if ( V_15 == 0 ) {
V_6 = V_13 ;
} else {
if ( V_15 < 0 ) {
V_15 = - V_19 ;
F_9 ( V_20 L_5
L_3 , - V_15 ) ;
V_6 = V_15 ;
}
F_3 ( F_15 ( V_13 , NULL , V_29 ) ) ;
}
V_28:
F_16 ( V_3 . V_9 ) ;
V_22:
if ( V_14 [ 1 ] != - 1 )
F_13 ( V_14 [ 1 ] ) ;
F_13 ( V_14 [ 0 ] ) ;
V_21:
F_17 ( V_11 , 0 ) ;
return V_6 ;
}
int F_18 ( int (* F_19)( void * ) , void * V_1 , unsigned int V_30 ,
unsigned long * V_31 )
{
unsigned long V_11 , V_12 ;
int V_13 , V_32 , V_5 ;
V_11 = F_6 ( 0 , F_7 () ) ;
if ( V_11 == 0 )
return - V_16 ;
V_12 = V_11 + V_23 - sizeof( void * ) ;
V_13 = F_12 ( F_19 , ( void * ) V_12 , V_30 , V_1 ) ;
if ( V_13 < 0 ) {
V_5 = - V_19 ;
F_9 ( V_20 L_6
L_7 , V_19 ) ;
return V_5 ;
}
if ( V_31 == NULL ) {
F_3 ( V_13 = F_15 ( V_13 , & V_32 , V_29 ) ) ;
if ( V_13 < 0 ) {
V_5 = - V_19 ;
F_9 ( V_20 L_8
L_7 , V_19 ) ;
V_13 = V_5 ;
}
if ( ! F_20 ( V_32 ) || ( F_21 ( V_32 ) != 0 ) )
F_9 ( V_20 L_9
L_10 , V_32 ) ;
F_17 ( V_11 , 0 ) ;
} else
* V_31 = V_11 ;
return V_13 ;
}
int F_22 ( int V_13 )
{
int V_6 , V_32 ;
int V_33 = V_29 ;
F_3 ( V_6 = F_15 ( V_13 , & V_32 , V_33 ) ) ;
if ( V_6 < 0 ) {
F_9 ( V_20 L_11
L_7 , V_13 , V_19 ) ;
return - V_19 ;
} else if ( ! F_20 ( V_32 ) || F_21 ( V_32 ) != 0 ) {
F_9 ( V_20 L_12
L_13 , V_13 , V_32 ) ;
return - V_34 ;
} else
return 0 ;
}
