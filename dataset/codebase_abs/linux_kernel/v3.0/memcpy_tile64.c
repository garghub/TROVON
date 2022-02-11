static void F_1 ( void * V_1 , const void * V_2 ,
T_1 V_3 , T_1 V_4 , int V_5 )
{
int V_6 ;
unsigned long V_7 , V_8 , V_9 ;
T_2 * V_10 ;
T_1 * V_11 ;
int V_12 , V_13 ;
int V_14 = F_2 () ;
F_3 ( V_7 ) ;
F_4 ( 1 ) ;
V_12 = F_5 () ;
V_6 = V_15 + ( V_16 * V_14 ) + V_12 ;
V_9 = F_6 ( V_6 ) + ( ( unsigned long ) V_1 & ( V_17 - 1 ) ) ;
V_10 = F_7 ( F_8 ( F_9 ( V_9 ) , V_9 ) , V_9 ) ;
V_11 = F_10 ( V_10 , V_9 ) ;
if ( F_11 ( * V_11 ) != F_11 ( V_3 ) ) {
F_12 ( V_11 , V_3 ) ;
F_13 ( NULL , V_9 , V_17 ) ;
}
V_13 = F_5 () ;
V_6 += ( V_12 - V_13 ) ;
V_4 = F_14 ( V_4 ) ;
V_4 = F_15 ( V_4 ) ;
V_8 = F_6 ( V_6 ) + ( ( unsigned long ) V_2 & ( V_17 - 1 ) ) ;
V_10 = F_7 ( F_8 ( F_9 ( V_8 ) , V_8 ) , V_8 ) ;
V_11 = F_10 ( V_10 , V_8 ) ;
F_16 ( V_11 , V_4 ) ;
F_13 ( NULL , V_8 , V_17 ) ;
F_17 ( ( void * ) V_9 , ( const void * ) V_8 , V_5 ) ;
V_4 = F_18 ( V_4 , V_18 ) ;
V_4 = F_19 ( V_4 ) ;
F_16 ( V_11 , V_4 ) ;
F_13 ( NULL , V_8 , V_17 ) ;
F_20 ( ( void * ) V_8 , V_5 ) ;
F_21 () ;
F_21 () ;
F_4 ( 0 ) ;
F_22 ( V_7 ) ;
F_23 () ;
}
static unsigned long F_24 ( void * V_1 , const void * V_2 , int V_5 ,
T_3 V_19 )
{
while ( V_5 >= V_20 ) {
int V_21 , V_22 ;
T_1 * V_23 , * V_24 ;
T_1 V_4 , V_3 ;
struct V_25 * V_26 , * V_27 ;
V_28:
V_23 = F_25 ( V_29 -> V_30 , ( unsigned long ) V_2 ) ;
if ( V_23 == NULL )
break;
V_4 = * V_23 ;
if ( ! F_26 ( V_4 ) ||
! F_27 ( V_4 ) ||
F_28 ( V_4 ) != V_31 )
break;
if ( F_29 ( V_4 ) == F_30 () )
break;
V_26 = F_31 ( F_32 ( V_4 ) ) ;
F_33 ( V_26 ) ;
if ( F_11 ( V_4 ) != F_11 ( * V_23 ) ) {
F_34 ( V_26 ) ;
goto V_28;
}
if ( F_35 ( V_4 ) ) {
int V_32 = F_32 ( V_4 ) ;
V_32 += ( ( ( unsigned long ) V_2 & ( V_33 - 1 ) )
>> V_34 ) ;
V_4 = F_36 ( V_32 , V_4 ) ;
V_4 = F_37 ( V_4 ) ;
}
V_35:
V_24 = F_25 ( V_29 -> V_30 , ( unsigned long ) V_1 ) ;
if ( V_24 == NULL ) {
F_34 ( V_26 ) ;
break;
}
V_3 = * V_24 ;
if ( ! F_26 ( V_3 ) ||
! F_38 ( V_3 ) ) {
F_34 ( V_26 ) ;
break;
}
V_27 = F_31 ( F_32 ( V_3 ) ) ;
if ( V_27 == V_26 ) {
F_34 ( V_26 ) ;
break;
}
F_33 ( V_27 ) ;
if ( F_11 ( V_3 ) != F_11 ( * V_24 ) ) {
F_34 ( V_27 ) ;
goto V_35;
}
if ( F_35 ( V_3 ) ) {
int V_32 = F_32 ( V_3 ) ;
V_32 += ( ( ( unsigned long ) V_1 & ( V_33 - 1 ) )
>> V_34 ) ;
V_3 = F_36 ( V_32 , V_3 ) ;
V_3 = F_37 ( V_3 ) ;
}
V_21 = V_5 ;
V_22 =
V_17 - ( ( ( int ) V_2 ) & ( V_17 - 1 ) ) ;
if ( V_21 > V_22 )
V_21 = V_22 ;
V_22 =
V_17 - ( ( ( int ) V_1 ) & ( V_17 - 1 ) ) ;
if ( V_21 > V_22 )
V_21 = V_22 ;
F_1 ( V_1 , V_2 , V_3 , V_4 , V_21 ) ;
F_34 ( V_27 ) ;
F_34 ( V_26 ) ;
V_1 += V_21 ;
V_2 += V_21 ;
V_5 -= V_21 ;
}
return V_19 ( V_1 , V_2 , V_5 ) ;
}
void * memcpy ( void * V_36 , const void * V_37 , T_4 V_38 )
{
if ( V_38 < V_20 )
return ( void * ) F_17 ( V_36 , V_37 , V_38 ) ;
else
return ( void * ) F_24 ( V_36 , V_37 , V_38 , F_17 ) ;
}
unsigned long F_39 ( void T_5 * V_36 , const void * V_37 ,
unsigned long V_38 )
{
if ( V_38 < V_20 )
return F_40 ( V_36 , V_37 , V_38 ) ;
else
return F_24 ( V_36 , V_37 , V_38 , F_40 ) ;
}
unsigned long F_41 ( void * V_36 , const void T_5 * V_37 ,
unsigned long V_38 )
{
if ( V_38 < V_20 )
return F_42 ( V_36 , V_37 , V_38 ) ;
else
return F_24 ( V_36 , V_37 , V_38 , F_42 ) ;
}
unsigned long F_43 ( void * V_36 , const void T_5 * V_37 ,
unsigned long V_38 )
{
if ( V_38 < V_20 )
return F_44 ( V_36 , V_37 , V_38 ) ;
else
return F_24 ( V_36 , V_37 , V_38 , F_44 ) ;
}
