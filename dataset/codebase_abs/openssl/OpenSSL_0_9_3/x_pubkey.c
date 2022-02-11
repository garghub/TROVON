int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_6 () ;
}
T_1 * F_7 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_7 )
{
F_8 ( V_1 , T_1 * , V_8 ) ;
F_9 () ;
F_10 () ;
F_11 ( V_9 -> V_3 , V_10 ) ;
F_11 ( V_9 -> V_5 , V_11 ) ;
if ( V_9 -> V_12 != NULL )
{
F_12 ( V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
}
F_13 ( V_1 , V_13 , V_14 ) ;
}
T_1 * V_8 ( void )
{
T_1 * V_9 = NULL ;
T_2 V_15 ;
F_14 ( V_9 , T_1 ) ;
F_15 ( V_9 -> V_3 , V_16 ) ;
F_15 ( V_9 -> V_5 , V_17 ) ;
V_9 -> V_12 = NULL ;
return ( V_9 ) ;
F_16 ( V_18 ) ;
}
void V_13 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_17 ( V_1 -> V_3 ) ;
F_18 ( V_1 -> V_5 ) ;
if ( V_1 -> V_12 != NULL ) F_12 ( V_1 -> V_12 ) ;
Free ( ( char * ) V_1 ) ;
}
int F_19 ( T_1 * * V_19 , T_3 * V_12 )
{
int V_20 = 0 ;
T_1 * V_21 ;
T_4 * V_1 ;
T_5 * V_22 ;
unsigned char * V_23 , * V_24 ;
int V_25 ;
if ( V_19 == NULL ) return ( 0 ) ;
if ( ( V_21 = V_8 () ) == NULL ) goto V_26;
V_1 = V_21 -> V_3 ;
if ( ( V_22 = F_20 ( V_12 -> type ) ) == NULL ) goto V_26;
F_21 ( V_1 -> V_27 ) ;
V_1 -> V_27 = V_22 ;
if ( ! V_12 -> V_28 || ( V_12 -> type == V_29 ) )
{
if ( ( V_1 -> V_30 == NULL ) ||
( V_1 -> V_30 -> type != V_31 ) )
{
F_22 ( V_1 -> V_30 ) ;
V_1 -> V_30 = F_23 () ;
V_1 -> V_30 -> type = V_31 ;
}
}
else
#ifndef F_24
if ( V_12 -> type == V_32 )
{
unsigned char * V_2 ;
T_6 * V_33 ;
V_33 = V_12 -> V_12 . V_33 ;
V_33 -> V_34 = 0 ;
F_22 ( V_1 -> V_30 ) ;
V_25 = F_25 ( V_33 , NULL ) ;
V_24 = ( unsigned char * ) Malloc ( V_25 ) ;
V_2 = V_24 ;
F_25 ( V_33 , & V_2 ) ;
V_1 -> V_30 = F_23 () ;
V_1 -> V_30 -> type = V_35 ;
V_1 -> V_30 -> V_36 . V_37 = F_26 () ;
F_27 ( V_1 -> V_30 -> V_36 . V_37 , V_24 , V_25 ) ;
Free ( V_24 ) ;
}
else
#endif
{
F_28 ( V_38 , V_39 ) ;
goto V_26;
}
if ( ( V_25 = F_29 ( V_12 , NULL ) ) <= 0 ) goto V_26;
if ( ( V_23 = ( unsigned char * ) Malloc ( V_25 + 1 ) ) == NULL ) goto V_26;
V_24 = V_23 ;
F_29 ( V_12 , & V_24 ) ;
if ( ! F_30 ( V_21 -> V_5 , V_23 , V_25 ) ) goto V_26;
V_21 -> V_5 -> V_40 &= ~ ( V_41 | 0x07 ) ;
V_21 -> V_5 -> V_40 |= V_41 ;
Free ( V_23 ) ;
F_31 ( & V_12 -> V_42 , 1 , V_43 ) ;
V_21 -> V_12 = V_12 ;
if ( * V_19 != NULL )
V_13 ( * V_19 ) ;
* V_19 = V_21 ;
V_21 = NULL ;
V_20 = 1 ;
V_26:
if ( V_21 != NULL ) V_13 ( V_21 ) ;
return ( V_20 ) ;
}
T_3 * F_32 ( T_1 * V_44 )
{
T_3 * V_9 = NULL ;
long V_45 ;
int type ;
unsigned char * V_24 ;
#ifndef F_24
T_4 * V_1 ;
#endif
if ( V_44 == NULL ) goto V_26;
if ( V_44 -> V_12 != NULL )
{
F_31 ( & V_44 -> V_12 -> V_42 , 1 , V_43 ) ;
return ( V_44 -> V_12 ) ;
}
if ( V_44 -> V_5 == NULL ) goto V_26;
type = F_33 ( V_44 -> V_3 -> V_27 ) ;
V_24 = V_44 -> V_5 -> V_46 ;
V_45 = V_44 -> V_5 -> V_7 ;
if ( ( V_9 = F_34 ( type , NULL , & V_24 , ( long ) V_45 ) ) == NULL )
{
F_28 ( V_47 , V_48 ) ;
goto V_26;
}
V_9 -> V_28 = 0 ;
#ifndef F_24
V_1 = V_44 -> V_3 ;
if ( V_9 -> type == V_32 )
{
if ( V_1 -> V_30 -> type == V_35 )
{
V_9 -> V_12 . V_33 -> V_34 = 0 ;
V_24 = V_1 -> V_30 -> V_36 . V_37 -> V_46 ;
V_45 = V_1 -> V_30 -> V_36 . V_37 -> V_7 ;
if ( ! F_35 ( & V_9 -> V_12 . V_33 , & V_24 , ( long ) V_45 ) )
goto V_26;
}
V_9 -> V_28 = 1 ;
}
#endif
V_44 -> V_12 = V_9 ;
F_31 ( & V_9 -> V_42 , 1 , V_43 ) ;
return ( V_9 ) ;
V_26:
if ( V_9 != NULL )
F_12 ( V_9 ) ;
return ( NULL ) ;
}
