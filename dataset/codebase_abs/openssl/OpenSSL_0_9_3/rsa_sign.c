int F_1 ( int type , unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_3 , unsigned int * V_4 , T_1 * V_5 )
{
T_2 V_6 ;
T_3 V_7 ;
int V_8 , V_9 , V_10 = 1 ;
unsigned char * V_11 , * V_12 ;
T_4 V_13 ;
T_5 V_14 ;
V_6 . V_13 = & V_13 ;
V_6 . V_13 -> V_15 = F_2 ( type ) ;
if ( V_6 . V_13 -> V_15 == NULL )
{
F_3 ( V_16 , V_17 ) ;
return ( 0 ) ;
}
if ( V_6 . V_13 -> V_15 -> V_18 == 0 )
{
F_3 ( V_16 , V_19 ) ;
return ( 0 ) ;
}
V_7 . type = V_20 ;
V_7 . V_21 . V_22 = NULL ;
V_6 . V_13 -> V_7 = & V_7 ;
V_6 . V_14 = & V_14 ;
V_6 . V_14 -> V_23 = V_1 ;
V_6 . V_14 -> V_18 = V_2 ;
V_8 = F_4 ( & V_6 , NULL ) ;
V_9 = F_5 ( V_5 ) ;
if ( ( V_8 - V_24 ) > V_9 )
{
F_3 ( V_16 , V_25 ) ;
return ( 0 ) ;
}
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_9 + 1 ) ;
if ( V_12 == NULL )
{
F_3 ( V_16 , V_26 ) ;
return ( 0 ) ;
}
V_11 = V_12 ;
F_4 ( & V_6 , & V_11 ) ;
V_8 = F_6 ( V_8 , V_12 , V_3 , V_5 , V_24 ) ;
if ( V_8 <= 0 )
V_10 = 0 ;
else
* V_4 = V_8 ;
memset ( V_12 , 0 , ( unsigned int ) V_9 + 1 ) ;
Free ( V_12 ) ;
return ( V_10 ) ;
}
int F_7 ( int V_27 , unsigned char * V_1 , unsigned int V_2 ,
unsigned char * V_28 , unsigned int V_4 , T_1 * V_5 )
{
int V_8 , V_10 = 0 , V_29 ;
unsigned char * V_11 , * V_12 ;
T_2 * V_6 = NULL ;
if ( V_4 != ( unsigned int ) F_5 ( V_5 ) )
{
F_3 ( V_30 , V_31 ) ;
return ( 0 ) ;
}
V_12 = ( unsigned char * ) Malloc ( ( unsigned int ) V_4 ) ;
if ( V_12 == NULL )
{
F_3 ( V_30 , V_26 ) ;
goto V_32;
}
V_8 = F_8 ( ( int ) V_4 , V_28 , V_12 , V_5 , V_24 ) ;
if ( V_8 <= 0 ) goto V_32;
V_11 = V_12 ;
V_6 = F_9 ( NULL , & V_11 , ( long ) V_8 ) ;
if ( V_6 == NULL ) goto V_32;
V_29 = F_10 ( V_6 -> V_13 -> V_15 ) ;
#ifdef F_11
fprintf ( V_33 , L_1 , F_12 ( V_29 ) ,
F_12 ( V_27 ) ) ;
#endif
if ( V_29 != V_27 )
{
if ( ( ( V_27 == V_34 ) &&
( V_29 == V_35 ) ) ||
( ( V_27 == V_36 ) &&
( V_29 == V_37 ) ) )
{
#if ! F_13 ( V_38 ) && ! F_13 ( V_39 )
fprintf ( V_33 , L_2 ) ;
#endif
}
else
{
F_3 ( V_30 , V_40 ) ;
goto V_32;
}
}
if ( ( ( unsigned int ) V_6 -> V_14 -> V_18 != V_2 ) ||
( memcmp ( V_1 , V_6 -> V_14 -> V_23 , V_2 ) != 0 ) )
{
F_3 ( V_30 , V_41 ) ;
}
else
V_10 = 1 ;
V_32:
if ( V_6 != NULL ) F_14 ( V_6 ) ;
memset ( V_12 , 0 , ( unsigned int ) V_4 ) ;
Free ( V_12 ) ;
return ( V_10 ) ;
}
