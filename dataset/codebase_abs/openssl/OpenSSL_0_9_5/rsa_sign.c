int F_1 ( int type , unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_3 , unsigned int * V_4 , T_1 * V_5 )
{
T_2 V_6 ;
T_3 V_7 ;
int V_8 , V_9 , V_10 = 1 ;
unsigned char * V_11 , * V_12 = NULL ;
T_4 V_13 ;
T_5 V_14 ;
if( V_5 -> V_15 & V_16 )
return V_5 -> V_17 -> V_18 ( type , V_1 , V_2 , V_3 , V_4 , V_5 ) ;
if( type == V_19 ) {
if( V_2 != V_20 ) {
F_2 ( V_21 , V_22 ) ;
return ( 0 ) ;
}
V_8 = V_20 ;
V_12 = V_1 ;
} else {
V_6 . V_13 = & V_13 ;
V_6 . V_13 -> V_23 = F_3 ( type ) ;
if ( V_6 . V_13 -> V_23 == NULL )
{
F_2 ( V_21 , V_24 ) ;
return ( 0 ) ;
}
if ( V_6 . V_13 -> V_23 -> V_25 == 0 )
{
F_2 ( V_21 , V_26 ) ;
return ( 0 ) ;
}
V_7 . type = V_27 ;
V_7 . V_28 . V_29 = NULL ;
V_6 . V_13 -> V_7 = & V_7 ;
V_6 . V_14 = & V_14 ;
V_6 . V_14 -> V_30 = V_1 ;
V_6 . V_14 -> V_25 = V_2 ;
V_8 = F_4 ( & V_6 , NULL ) ;
}
V_9 = F_5 ( V_5 ) ;
if ( ( V_8 - V_31 ) > V_9 )
{
F_2 ( V_21 , V_32 ) ;
return ( 0 ) ;
}
if( type != V_19 ) {
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_9 + 1 ) ;
if ( V_12 == NULL )
{
F_2 ( V_21 , V_33 ) ;
return ( 0 ) ;
}
V_11 = V_12 ;
F_4 ( & V_6 , & V_11 ) ;
}
V_8 = F_6 ( V_8 , V_12 , V_3 , V_5 , V_31 ) ;
if ( V_8 <= 0 )
V_10 = 0 ;
else
* V_4 = V_8 ;
if( type != V_19 ) {
memset ( V_12 , 0 , ( unsigned int ) V_9 + 1 ) ;
Free ( V_12 ) ;
}
return ( V_10 ) ;
}
int F_7 ( int V_34 , unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_35 , unsigned int V_4 , T_1 * V_5 )
{
int V_8 , V_10 = 0 , V_36 ;
unsigned char * V_11 , * V_12 ;
T_2 * V_6 = NULL ;
if ( V_4 != ( unsigned int ) F_5 ( V_5 ) )
{
F_2 ( V_37 , V_38 ) ;
return ( 0 ) ;
}
if( V_5 -> V_15 & V_16 )
return V_5 -> V_17 -> V_39 ( V_34 , V_1 , V_2 , V_35 , V_4 , V_5 ) ;
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_4 ) ;
if ( V_12 == NULL )
{
F_2 ( V_37 , V_33 ) ;
goto V_40;
}
if( ( V_34 == V_19 ) && ( V_2 != V_20 ) ) {
F_2 ( V_37 , V_22 ) ;
return ( 0 ) ;
}
V_8 = F_8 ( ( int ) V_4 , V_35 , V_12 , V_5 , V_31 ) ;
if ( V_8 <= 0 ) goto V_40;
if( V_34 == V_19 ) {
if( ( V_8 != V_20 ) || memcmp ( V_12 , V_1 , V_20 ) )
F_2 ( V_37 , V_41 ) ;
else V_10 = 1 ;
} else {
V_11 = V_12 ;
V_6 = F_9 ( NULL , & V_11 , ( long ) V_8 ) ;
if ( V_6 == NULL ) goto V_40;
V_36 = F_10 ( V_6 -> V_13 -> V_23 ) ;
#ifdef F_11
fprintf ( V_42 , L_1 , F_12 ( V_36 ) ,
F_12 ( V_34 ) ) ;
#endif
if ( V_36 != V_34 )
{
if ( ( ( V_34 == V_43 ) &&
( V_36 == V_44 ) ) ||
( ( V_34 == V_45 ) &&
( V_36 == V_46 ) ) )
{
#if ! F_13 ( V_47 ) && ! F_13 ( V_48 )
fprintf ( V_42 , L_2 ) ;
#endif
}
else
{
F_2 ( V_37 ,
V_49 ) ;
goto V_40;
}
}
if ( ( ( unsigned int ) V_6 -> V_14 -> V_25 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_14 -> V_30 , V_2 ) != 0 ) )
{
F_2 ( V_37 , V_41 ) ;
}
else
V_10 = 1 ;
}
V_40:
if ( V_6 != NULL ) F_14 ( V_6 ) ;
memset ( V_12 , 0 , ( unsigned int ) V_4 ) ;
Free ( V_12 ) ;
return ( V_10 ) ;
}
