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
T_3 V_15 = F_3 ( * V_10 ) ;
struct V_5 * V_5 ;
if ( ( F_4 ( V_15 ) & V_8 ) != V_9 )
return 0 ;
F_5 ( ! F_6 ( F_7 ( V_15 ) ) ) ;
V_5 = F_8 ( V_15 ) ;
if ( ! F_9 ( V_5 ) )
return 0 ;
if ( F_10 ( F_4 ( V_15 ) != F_4 ( * V_10 ) ) ) {
F_11 ( V_5 ) ;
return 0 ;
}
V_6 [ * V_7 ] = V_5 ;
( * V_7 ) ++ ;
} while ( V_10 ++ , V_2 += V_16 , V_2 != V_3 );
return 1 ;
}
static int F_12 ( T_4 V_17 , unsigned long V_2 , unsigned long V_3 ,
int V_4 , struct V_5 * * V_6 , int * V_7 )
{
unsigned long V_18 ;
T_2 * V_19 ;
V_19 = F_13 ( & V_17 , V_2 ) ;
do {
T_2 V_1 = F_3 ( * V_19 ) ;
V_18 = F_14 ( V_2 , V_3 ) ;
if ( F_15 ( V_1 ) || F_16 ( V_1 ) )
return 0 ;
if ( F_17 ( V_1 ) || F_18 ( V_1 ) ) {
if ( ! F_19 ( ( T_3 * ) V_19 , V_20 , V_2 , V_18 ,
V_4 , V_6 , V_7 ) )
return 0 ;
} else if ( F_20 ( V_19 ) ) {
if ( ! F_21 ( ( V_21 * ) V_19 , V_22 ,
V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} else if ( ! F_1 ( V_1 , V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} while ( V_19 ++ , V_2 = V_18 , V_2 != V_3 );
return 1 ;
}
static int F_22 ( T_5 V_23 , unsigned long V_2 , unsigned long V_3 ,
int V_4 , struct V_5 * * V_6 , int * V_7 )
{
unsigned long V_18 ;
T_4 * V_24 ;
V_24 = F_23 ( & V_23 , V_2 ) ;
do {
T_4 V_17 = F_3 ( * V_24 ) ;
V_18 = F_24 ( V_2 , V_3 ) ;
if ( F_25 ( V_17 ) )
return 0 ;
if ( F_26 ( V_17 ) ) {
if ( ! F_19 ( ( T_3 * ) V_24 , V_25 , V_2 , V_18 ,
V_4 , V_6 , V_7 ) )
return 0 ;
} else if ( F_20 ( V_24 ) ) {
if ( ! F_21 ( ( V_21 * ) V_24 , V_26 ,
V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} else if ( ! F_12 ( V_17 , V_2 , V_18 , V_4 , V_6 , V_7 ) )
return 0 ;
} while ( V_24 ++ , V_2 = V_18 , V_2 != V_3 );
return 1 ;
}
int F_27 ( unsigned long V_27 , int V_28 , int V_4 ,
struct V_5 * * V_6 )
{
struct V_29 * V_30 = V_31 -> V_30 ;
unsigned long V_2 , V_32 , V_3 ;
unsigned long V_18 ;
unsigned long V_33 ;
T_5 * V_34 ;
int V_7 = 0 ;
F_28 ( L_1 , V_35 , V_27 , V_28 , V_4 ? L_2 : L_3 ) ;
V_27 &= V_36 ;
V_2 = V_27 ;
V_32 = ( unsigned long ) V_28 << V_37 ;
V_3 = V_27 + V_32 ;
if ( F_10 ( ! F_29 ( V_4 ? V_38 : V_39 ,
V_27 , V_32 ) ) )
return 0 ;
F_28 ( L_4 , V_27 , V_3 ) ;
F_30 ( V_33 ) ;
V_34 = F_31 ( V_30 , V_2 ) ;
do {
T_5 V_23 = F_3 ( * V_34 ) ;
F_28 ( L_5 , V_2 ,
( void * ) F_32 ( V_23 ) ) ;
V_18 = F_33 ( V_2 , V_3 ) ;
if ( F_34 ( V_23 ) )
break;
if ( F_35 ( V_23 ) ) {
if ( ! F_19 ( ( T_3 * ) V_34 , V_40 , V_2 , V_18 ,
V_4 , V_6 , & V_7 ) )
break;
} else if ( F_20 ( V_34 ) ) {
if ( ! F_21 ( ( V_21 * ) V_34 , V_41 ,
V_2 , V_18 , V_4 , V_6 , & V_7 ) )
break;
} else if ( ! F_22 ( V_23 , V_2 , V_18 , V_4 , V_6 , & V_7 ) )
break;
} while ( V_34 ++ , V_2 = V_18 , V_2 != V_3 );
F_36 ( V_33 ) ;
return V_7 ;
}
int F_37 ( unsigned long V_27 , int V_28 , int V_4 ,
struct V_5 * * V_6 )
{
struct V_29 * V_30 = V_31 -> V_30 ;
int V_7 , V_42 ;
V_27 &= V_36 ;
V_7 = F_27 ( V_27 , V_28 , V_4 , V_6 ) ;
V_42 = V_7 ;
if ( V_7 < V_28 ) {
F_28 ( L_6 , V_7 ) ;
V_27 += V_7 << V_37 ;
V_6 += V_7 ;
F_38 ( & V_30 -> V_43 ) ;
V_42 = F_39 ( V_31 , V_30 , V_27 ,
V_28 - V_7 , V_4 , 0 , V_6 , NULL ) ;
F_40 ( & V_30 -> V_43 ) ;
if ( V_7 > 0 ) {
if ( V_42 < 0 )
V_42 = V_7 ;
else
V_42 += V_7 ;
}
}
return V_42 ;
}
