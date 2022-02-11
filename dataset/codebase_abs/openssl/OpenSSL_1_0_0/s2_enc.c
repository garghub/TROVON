int F_1 ( T_1 * V_1 , int V_2 )
{
T_2 * V_3 , * V_4 ;
const T_3 * V_5 ;
const T_4 * V_6 ;
int V_7 ;
if ( ! F_2 ( V_1 -> V_8 , & V_5 , & V_6 , NULL , NULL , NULL ) )
{
F_3 ( V_1 , V_9 ) ;
F_4 ( V_10 , V_11 ) ;
return ( 0 ) ;
}
F_5 ( & V_1 -> V_12 , V_6 ) ;
F_5 ( & V_1 -> V_13 , V_6 ) ;
if ( ( V_1 -> V_14 == NULL ) &&
( ( V_1 -> V_14 = ( T_2 * )
F_6 ( sizeof( T_2 ) ) ) == NULL ) )
goto V_15;
V_3 = V_1 -> V_14 ;
F_7 ( V_3 ) ;
if ( ( V_1 -> V_16 == NULL ) &&
( ( V_1 -> V_16 = ( T_2 * )
F_6 ( sizeof( T_2 ) ) ) == NULL ) )
goto V_15;
V_4 = V_1 -> V_16 ;
F_7 ( V_4 ) ;
V_7 = V_5 -> V_17 ;
V_1 -> V_18 -> V_19 = V_7 * 2 ;
F_8 ( V_1 -> V_18 -> V_19 <= sizeof V_1 -> V_18 -> V_20 ) ;
if ( F_9 ( V_1 ) <= 0 )
return 0 ;
F_8 ( V_5 -> V_21 <= ( int ) sizeof( V_1 -> V_8 -> V_22 ) ) ;
F_10 ( V_4 , V_5 , NULL , & ( V_1 -> V_18 -> V_20 [ ( V_2 ) ? V_7 : 0 ] ) ,
V_1 -> V_8 -> V_22 ) ;
F_11 ( V_3 , V_5 , NULL , & ( V_1 -> V_18 -> V_20 [ ( V_2 ) ? 0 : V_7 ] ) ,
V_1 -> V_8 -> V_22 ) ;
V_1 -> V_18 -> V_23 = & ( V_1 -> V_18 -> V_20 [ ( V_2 ) ? 0 : V_7 ] ) ;
V_1 -> V_18 -> V_24 = & ( V_1 -> V_18 -> V_20 [ ( V_2 ) ? V_7 : 0 ] ) ;
return ( 1 ) ;
V_15:
F_4 ( V_10 , V_25 ) ;
return ( 0 ) ;
}
void F_12 ( T_1 * V_1 , int V_26 )
{
T_2 * V_27 ;
unsigned long V_28 ;
int V_29 ;
if ( V_26 )
{
V_27 = V_1 -> V_16 ;
V_28 = V_1 -> V_18 -> V_30 ;
}
else
{
V_27 = V_1 -> V_14 ;
V_28 = V_1 -> V_18 -> V_31 ;
}
if ( V_27 == NULL ) return;
V_29 = V_27 -> V_32 -> V_33 ;
if ( V_29 == 8 )
V_28 = ( V_28 + 7 ) / 8 * 8 ;
F_13 ( V_27 , V_1 -> V_18 -> V_34 , V_1 -> V_18 -> V_34 , V_28 ) ;
}
void F_14 ( T_1 * V_1 , unsigned char * V_6 , int V_26 )
{
T_5 V_5 ;
unsigned char V_35 [ 4 ] , * V_36 , * V_37 , * V_38 ;
unsigned long V_39 ;
unsigned int V_40 ;
if ( V_26 )
{
V_39 = V_1 -> V_18 -> V_41 ;
V_37 = V_1 -> V_18 -> V_24 ;
V_40 = V_1 -> V_18 -> V_42 ;
V_38 = V_1 -> V_18 -> V_43 ;
}
else
{
V_39 = V_1 -> V_18 -> V_44 ;
V_37 = V_1 -> V_18 -> V_23 ;
V_40 = V_1 -> V_18 -> V_45 ;
V_38 = V_1 -> V_18 -> V_46 ;
}
V_36 = & ( V_35 [ 0 ] ) ;
F_15 ( V_39 , V_36 ) ;
F_16 ( & V_5 ) ;
F_17 ( & V_5 , V_1 -> V_12 ) ;
F_18 ( & V_5 , V_37 ,
F_19 ( V_1 -> V_14 ) ) ;
F_18 ( & V_5 , V_38 , V_40 ) ;
F_18 ( & V_5 , V_35 , 4 ) ;
F_20 ( & V_5 , V_6 , NULL ) ;
F_21 ( & V_5 ) ;
}
