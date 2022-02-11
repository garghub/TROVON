int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
int V_3 = 0 ;
int V_4 = 0 , V_5 = 0 ;
unsigned char * * V_6 = NULL ;
if ( V_1 == NULL ) return ( 0 ) ;
V_6 = NULL ;
for (; ; )
{
if ( V_3 )
{
V_4 = F_2 ( 1 , V_5 , V_7 ) ;
if ( V_2 == NULL ) return ( V_4 ) ;
V_6 = V_2 ;
F_3 ( V_6 , 1 , V_5 , V_7 ,
V_8 ) ;
}
V_5 += F_4 ( V_1 -> V_9 , V_6 ) ;
if ( V_1 -> V_10 )
V_5 += F_5 ( V_1 -> V_11 . V_10 , V_6 , V_12 ,
V_13 , V_8 , V_14 ) ;
else
V_5 += V_12 ( V_1 -> V_11 . V_15 , V_6 ) ;
if ( V_3 ++ ) return ( V_4 ) ;
}
}
T_1 * F_6 ( T_1 * * V_1 , unsigned char * * V_2 ,
long V_16 )
{
F_7 ( V_1 , T_1 * , V_17 ) ;
F_8 () ;
F_9 () ;
F_10 ( V_5 -> V_9 , V_18 ) ;
if ( ( V_19 . V_20 != 0 ) &&
( V_21 == ( V_22 | V_8 | V_13 ) ) )
{
V_5 -> V_10 = 1 ;
F_11 ( V_23 , V_5 -> V_11 . V_10 , V_24 ,
V_25 ) ;
}
else
{
V_5 -> V_10 = 0 ;
F_10 ( V_5 -> V_11 . V_15 , V_24 ) ;
}
F_12 ( V_1 , V_26 , V_27 ) ;
}
T_1 * F_13 ( int V_28 , int V_29 , void * V_11 )
{
T_1 * V_5 = NULL ;
V_23 * V_30 = NULL ;
if ( ( V_5 = V_17 () ) == NULL )
return ( NULL ) ;
V_5 -> V_9 = F_14 ( V_28 ) ;
V_5 -> V_10 = 1 ;
if ( ( V_5 -> V_11 . V_10 = F_15 () ) == NULL ) goto V_31;
if ( ( V_30 = F_16 () ) == NULL ) goto V_31;
if ( ! F_17 ( V_5 -> V_11 . V_10 , V_30 ) ) goto V_31;
F_18 ( V_30 , V_29 , V_11 ) ;
return ( V_5 ) ;
V_31:
if ( V_5 != NULL ) V_26 ( V_5 ) ;
if ( V_30 != NULL ) V_25 ( V_30 ) ;
return ( NULL ) ;
}
T_1 * V_17 ( void )
{
T_1 * V_5 = NULL ;
T_2 V_19 ;
F_19 ( V_5 , T_1 ) ;
V_5 -> V_9 = F_14 ( V_32 ) ;
V_5 -> V_10 = 0 ;
V_5 -> V_11 . V_33 = NULL ;
return ( V_5 ) ;
F_20 ( V_34 ) ;
}
void V_26 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_21 ( V_1 -> V_9 ) ;
if ( V_1 -> V_10 )
F_22 ( V_1 -> V_11 . V_10 , V_25 ) ;
else
V_25 ( V_1 -> V_11 . V_15 ) ;
Free ( ( char * ) V_1 ) ;
}
