static T_1 int F_1 ( T_2 V_1 , unsigned long V_2 ,
unsigned long V_3 , int V_4 , struct V_5 * * V_6 , int * V_7 )
{
unsigned long V_8 , V_9 ;
T_3 * V_10 ;
V_9 = V_11 | V_12 ;
if ( V_4 )
V_9 |= V_13 ;
V_8 = V_9 | V_14 ;
V_10 = F_2 ( & V_1 , V_2 ) ;
do {
T_3 V_15 = * V_10 ;
struct V_5 * V_5 ;
if ( ( F_3 ( V_15 ) & V_8 ) != V_9 )
return 0 ;
F_4 ( ! F_5 ( F_6 ( V_15 ) ) ) ;
V_5 = F_7 ( V_15 ) ;
if ( ! F_8 ( V_5 ) )
return 0 ;
if ( F_9 ( F_3 ( V_15 ) != F_3 ( * V_10 ) ) ) {
F_10 ( V_5 ) ;
return 0 ;
}
V_6 [ * V_7 ] = V_5 ;
( * V_7 ) ++ ;
} while ( V_10 ++ , V_2 += V_16 , V_2 != V_3 );
return 1 ;
}
static int F_11 ( T_4 V_17 , unsigned long V_2 , unsigned long V_3 ,
int V_4 , struct V_5 * * V_6 , int * V_7 )
{
unsigned long V_18 ;
T_2 * V_19 ;
V_19 = F_12 ( & V_17 , V_2 ) ;
do {
T_2 V_1 = * V_19 ;
V_18 = F_13 ( V_2 , V_3 ) ;
if ( F_14 ( V_1 ) )
return 0 ;
if ( F_15 ( V_19 ) ) {
if ( ! F_16 ( ( V_20 * ) V_19 , V_21 ,
V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} else if ( ! F_1 ( V_1 , V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} while ( V_19 ++ , V_2 = V_18 , V_2 != V_3 );
return 1 ;
}
static int F_17 ( T_5 V_22 , unsigned long V_2 , unsigned long V_3 ,
int V_4 , struct V_5 * * V_6 , int * V_7 )
{
unsigned long V_18 ;
T_4 * V_23 ;
V_23 = F_18 ( & V_22 , V_2 ) ;
do {
T_4 V_17 = * V_23 ;
V_18 = F_19 ( V_2 , V_3 ) ;
if ( F_20 ( V_17 ) )
return 0 ;
if ( F_15 ( V_23 ) ) {
if ( ! F_16 ( ( V_20 * ) V_23 , V_24 ,
V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} else if ( ! F_11 ( V_17 , V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} while ( V_23 ++ , V_2 = V_18 , V_2 != V_3 );
return 1 ;
}
int F_21 ( unsigned long V_25 , int V_26 , int V_4 ,
struct V_5 * * V_6 )
{
struct V_27 * V_28 = V_29 -> V_28 ;
unsigned long V_2 , V_30 , V_3 ;
unsigned long V_18 ;
T_5 * V_31 ;
int V_7 = 0 ;
F_22 ( L_1 , V_32 , V_25 , V_26 , V_4 ? L_2 : L_3 ) ;
V_25 &= V_33 ;
V_2 = V_25 ;
V_30 = ( unsigned long ) V_26 << V_34 ;
V_3 = V_25 + V_30 ;
if ( F_9 ( ! F_23 ( V_4 ? V_35 : V_36 ,
V_25 , V_30 ) ) )
goto V_37;
F_22 ( L_4 , V_25 , V_3 ) ;
F_24 () ;
V_31 = F_25 ( V_28 , V_2 ) ;
do {
T_5 V_22 = * V_31 ;
F_22 ( L_5 , V_2 ,
( void * ) F_26 ( V_22 ) ) ;
V_18 = F_27 ( V_2 , V_3 ) ;
if ( F_28 ( V_22 ) )
goto V_38;
if ( F_15 ( V_31 ) ) {
if ( ! F_16 ( ( V_20 * ) V_31 , V_39 ,
V_2 , V_18 , V_4 , V_6 , & V_7 ) )
goto V_38;
} else if ( ! F_17 ( V_22 , V_2 , V_18 , V_4 , V_6 , & V_7 ) )
goto V_38;
} while ( V_31 ++ , V_2 = V_18 , V_2 != V_3 );
F_29 () ;
F_4 ( V_7 != ( V_3 - V_25 ) >> V_34 ) ;
return V_7 ;
{
int V_40 ;
V_38:
F_29 () ;
V_37:
F_22 ( L_6 , V_7 ) ;
V_25 += V_7 << V_34 ;
V_6 += V_7 ;
F_30 ( & V_28 -> V_41 ) ;
V_40 = F_31 ( V_29 , V_28 , V_25 ,
( V_3 - V_25 ) >> V_34 , V_4 , 0 , V_6 , NULL ) ;
F_32 ( & V_28 -> V_41 ) ;
if ( V_7 > 0 ) {
if ( V_40 < 0 )
V_40 = V_7 ;
else
V_40 += V_7 ;
}
return V_40 ;
}
}
