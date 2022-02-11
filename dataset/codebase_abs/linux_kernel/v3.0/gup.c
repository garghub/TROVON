static inline void F_1 ( struct V_1 * V_1 )
{
F_2 ( F_3 ( & V_1 -> V_2 ) < 0 ) ;
F_4 ( & V_1 -> V_2 ) ;
}
static T_1 int F_5 ( T_2 V_3 , unsigned long V_4 ,
unsigned long V_5 , int V_6 , struct V_1 * * V_7 , int * V_8 )
{
unsigned long V_9 , V_10 ;
T_3 * V_11 ;
V_10 = V_12 | V_13 ;
if ( V_6 )
V_10 |= V_14 ;
V_9 = V_10 | V_15 ;
V_11 = F_6 ( & V_3 , V_4 ) ;
do {
T_3 V_16 = * V_11 ;
struct V_1 * V_1 ;
if ( ( F_7 ( V_16 ) & V_9 ) != V_10 )
return 0 ;
F_2 ( ! F_8 ( F_9 ( V_16 ) ) ) ;
V_1 = F_10 ( V_16 ) ;
if ( ! F_11 ( V_1 ) )
return 0 ;
if ( F_12 ( F_7 ( V_16 ) != F_7 ( * V_11 ) ) ) {
F_13 ( V_1 ) ;
return 0 ;
}
if ( F_14 ( V_1 ) )
F_1 ( V_1 ) ;
V_7 [ * V_8 ] = V_1 ;
( * V_8 ) ++ ;
} while ( V_11 ++ , V_4 += V_17 , V_4 != V_5 );
return 1 ;
}
static int F_15 ( T_4 V_18 , unsigned long V_4 , unsigned long V_5 ,
int V_6 , struct V_1 * * V_7 , int * V_8 )
{
unsigned long V_19 ;
T_2 * V_20 ;
V_20 = F_16 ( & V_18 , V_4 ) ;
do {
T_2 V_3 = * V_20 ;
V_19 = F_17 ( V_4 , V_5 ) ;
if ( F_18 ( V_3 ) )
return 0 ;
if ( F_19 ( V_20 ) ) {
if ( ! F_20 ( ( V_21 * ) V_20 , V_22 ,
V_4 , V_19 , V_6 , V_7 , V_8 ) )
return 0 ;
} else if ( ! F_5 ( V_3 , V_4 , V_19 , V_6 , V_7 , V_8 ) )
return 0 ;
} while ( V_20 ++ , V_4 = V_19 , V_4 != V_5 );
return 1 ;
}
static int F_21 ( T_5 V_23 , unsigned long V_4 , unsigned long V_5 ,
int V_6 , struct V_1 * * V_7 , int * V_8 )
{
unsigned long V_19 ;
T_4 * V_24 ;
V_24 = F_22 ( & V_23 , V_4 ) ;
do {
T_4 V_18 = * V_24 ;
V_19 = F_23 ( V_4 , V_5 ) ;
if ( F_24 ( V_18 ) )
return 0 ;
if ( F_19 ( V_24 ) ) {
if ( ! F_20 ( ( V_21 * ) V_24 , V_25 ,
V_4 , V_19 , V_6 , V_7 , V_8 ) )
return 0 ;
} else if ( ! F_15 ( V_18 , V_4 , V_19 , V_6 , V_7 , V_8 ) )
return 0 ;
} while ( V_24 ++ , V_4 = V_19 , V_4 != V_5 );
return 1 ;
}
int F_25 ( unsigned long V_26 , int V_27 , int V_6 ,
struct V_1 * * V_7 )
{
struct V_28 * V_29 = V_30 -> V_29 ;
unsigned long V_4 , V_31 , V_5 ;
unsigned long V_19 ;
T_5 * V_32 ;
int V_8 = 0 ;
F_26 ( L_1 , V_33 , V_26 , V_27 , V_6 ? L_2 : L_3 ) ;
V_26 &= V_34 ;
V_4 = V_26 ;
V_31 = ( unsigned long ) V_27 << V_35 ;
V_5 = V_26 + V_31 ;
if ( F_12 ( ! F_27 ( V_6 ? V_36 : V_37 ,
V_26 , V_31 ) ) )
goto V_38;
F_26 ( L_4 , V_26 , V_5 ) ;
F_28 () ;
V_32 = F_29 ( V_29 , V_4 ) ;
do {
T_5 V_23 = * V_32 ;
F_26 ( L_5 , V_4 ,
( void * ) F_30 ( V_23 ) ) ;
V_19 = F_31 ( V_4 , V_5 ) ;
if ( F_32 ( V_23 ) )
goto V_39;
if ( F_19 ( V_32 ) ) {
if ( ! F_20 ( ( V_21 * ) V_32 , V_40 ,
V_4 , V_19 , V_6 , V_7 , & V_8 ) )
goto V_39;
} else if ( ! F_21 ( V_23 , V_4 , V_19 , V_6 , V_7 , & V_8 ) )
goto V_39;
} while ( V_32 ++ , V_4 = V_19 , V_4 != V_5 );
F_33 () ;
F_2 ( V_8 != ( V_5 - V_26 ) >> V_35 ) ;
return V_8 ;
{
int V_41 ;
V_39:
F_33 () ;
V_38:
F_26 ( L_6 , V_8 ) ;
V_26 += V_8 << V_35 ;
V_7 += V_8 ;
F_34 ( & V_29 -> V_42 ) ;
V_41 = F_35 ( V_30 , V_29 , V_26 ,
( V_5 - V_26 ) >> V_35 , V_6 , 0 , V_7 , NULL ) ;
F_36 ( & V_29 -> V_42 ) ;
if ( V_8 > 0 ) {
if ( V_41 < 0 )
V_41 = V_8 ;
else
V_41 += V_8 ;
}
return V_41 ;
}
}
