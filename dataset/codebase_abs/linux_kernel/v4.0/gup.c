static inline T_1 F_1 ( T_1 * V_1 )
{
#ifndef F_2
return F_3 ( * V_1 ) ;
#else
T_1 V_2 ;
V_3:
V_2 . V_4 = V_1 -> V_4 ;
F_4 () ;
V_2 . V_5 = V_1 -> V_5 ;
F_4 () ;
if ( F_5 ( V_2 . V_4 != V_1 -> V_4 ) )
goto V_3;
return V_2 ;
#endif
}
static T_2 int F_6 ( T_3 V_6 , unsigned long V_7 ,
unsigned long V_8 , int V_9 , struct V_10 * * V_11 , int * V_12 )
{
unsigned long V_13 ;
T_1 * V_1 ;
V_13 = V_14 | V_15 ;
if ( V_9 )
V_13 |= V_16 ;
V_1 = F_7 ( & V_6 , V_7 ) ;
do {
T_1 V_2 = F_1 ( V_1 ) ;
struct V_10 * V_10 ;
if ( F_8 ( V_2 ) ) {
F_9 ( V_1 ) ;
return 0 ;
}
if ( ( F_10 ( V_2 ) & ( V_13 | V_17 ) ) != V_13 ) {
F_9 ( V_1 ) ;
return 0 ;
}
F_11 ( ! F_12 ( F_13 ( V_2 ) ) ) ;
V_10 = F_14 ( V_2 ) ;
F_15 ( V_10 ) ;
F_16 ( V_10 ) ;
V_11 [ * V_12 ] = V_10 ;
( * V_12 ) ++ ;
} while ( V_1 ++ , V_7 += V_18 , V_7 != V_8 );
F_9 ( V_1 - 1 ) ;
return 1 ;
}
static inline void F_17 ( struct V_10 * V_10 , int V_12 )
{
F_18 ( V_10 != F_19 ( V_10 ) , V_10 ) ;
F_18 ( F_20 ( V_10 ) == 0 , V_10 ) ;
F_21 ( V_12 , & V_10 -> V_19 ) ;
F_16 ( V_10 ) ;
}
static T_2 int F_22 ( T_3 V_6 , unsigned long V_7 ,
unsigned long V_8 , int V_9 , struct V_10 * * V_11 , int * V_12 )
{
unsigned long V_13 ;
T_1 V_2 = * ( T_1 * ) & V_6 ;
struct V_10 * V_20 , * V_10 ;
int V_21 ;
V_13 = V_14 | V_15 ;
if ( V_9 )
V_13 |= V_16 ;
if ( ( F_10 ( V_2 ) & V_13 ) != V_13 )
return 0 ;
F_11 ( F_10 ( V_2 ) & V_17 ) ;
F_11 ( ! F_12 ( F_13 ( V_2 ) ) ) ;
V_21 = 0 ;
V_20 = F_14 ( V_2 ) ;
V_10 = V_20 + ( ( V_7 & ~ V_22 ) >> V_23 ) ;
do {
F_18 ( F_19 ( V_10 ) != V_20 , V_10 ) ;
V_11 [ * V_12 ] = V_10 ;
if ( F_23 ( V_10 ) )
F_24 ( V_10 ) ;
( * V_12 ) ++ ;
V_10 ++ ;
V_21 ++ ;
} while ( V_7 += V_18 , V_7 != V_8 );
F_17 ( V_20 , V_21 ) ;
return 1 ;
}
static int F_25 ( T_4 V_24 , unsigned long V_7 , unsigned long V_8 ,
int V_9 , struct V_10 * * V_11 , int * V_12 )
{
unsigned long V_25 ;
T_3 * V_26 ;
V_26 = F_26 ( & V_24 , V_7 ) ;
do {
T_3 V_6 = * V_26 ;
V_25 = F_27 ( V_7 , V_8 ) ;
if ( F_28 ( V_6 ) || F_29 ( V_6 ) )
return 0 ;
if ( F_5 ( F_30 ( V_6 ) || ! F_31 ( V_6 ) ) ) {
if ( F_32 ( V_6 ) )
return 0 ;
if ( ! F_22 ( V_6 , V_7 , V_25 , V_9 , V_11 , V_12 ) )
return 0 ;
} else {
if ( ! F_6 ( V_6 , V_7 , V_25 , V_9 , V_11 , V_12 ) )
return 0 ;
}
} while ( V_26 ++ , V_7 = V_25 , V_7 != V_8 );
return 1 ;
}
static T_2 int F_33 ( T_4 V_24 , unsigned long V_7 ,
unsigned long V_8 , int V_9 , struct V_10 * * V_11 , int * V_12 )
{
unsigned long V_13 ;
T_1 V_2 = * ( T_1 * ) & V_24 ;
struct V_10 * V_20 , * V_10 ;
int V_21 ;
V_13 = V_14 | V_15 ;
if ( V_9 )
V_13 |= V_16 ;
if ( ( F_10 ( V_2 ) & V_13 ) != V_13 )
return 0 ;
F_11 ( F_10 ( V_2 ) & V_17 ) ;
F_11 ( ! F_12 ( F_13 ( V_2 ) ) ) ;
V_21 = 0 ;
V_20 = F_14 ( V_2 ) ;
V_10 = V_20 + ( ( V_7 & ~ V_27 ) >> V_23 ) ;
do {
F_18 ( F_19 ( V_10 ) != V_20 , V_10 ) ;
V_11 [ * V_12 ] = V_10 ;
if ( F_23 ( V_10 ) )
F_24 ( V_10 ) ;
( * V_12 ) ++ ;
V_10 ++ ;
V_21 ++ ;
} while ( V_7 += V_18 , V_7 != V_8 );
F_17 ( V_20 , V_21 ) ;
return 1 ;
}
static int F_34 ( T_5 V_28 , unsigned long V_7 , unsigned long V_8 ,
int V_9 , struct V_10 * * V_11 , int * V_12 )
{
unsigned long V_25 ;
T_4 * V_29 ;
V_29 = F_35 ( & V_28 , V_7 ) ;
do {
T_4 V_24 = * V_29 ;
V_25 = F_36 ( V_7 , V_8 ) ;
if ( F_37 ( V_24 ) )
return 0 ;
if ( F_5 ( F_38 ( V_24 ) ) ) {
if ( ! F_33 ( V_24 , V_7 , V_25 , V_9 , V_11 , V_12 ) )
return 0 ;
} else {
if ( ! F_25 ( V_24 , V_7 , V_25 , V_9 , V_11 , V_12 ) )
return 0 ;
}
} while ( V_29 ++ , V_7 = V_25 , V_7 != V_8 );
return 1 ;
}
int F_39 ( unsigned long V_30 , int V_31 , int V_9 ,
struct V_10 * * V_11 )
{
struct V_32 * V_33 = V_34 -> V_33 ;
unsigned long V_7 , V_35 , V_8 ;
unsigned long V_25 ;
unsigned long V_36 ;
T_5 * V_37 ;
int V_12 = 0 ;
V_30 &= V_38 ;
V_7 = V_30 ;
V_35 = ( unsigned long ) V_31 << V_23 ;
V_8 = V_30 + V_35 ;
if ( F_5 ( ! F_40 ( V_9 ? V_39 : V_40 ,
( void V_41 * ) V_30 , V_35 ) ) )
return 0 ;
F_41 ( V_36 ) ;
V_37 = F_42 ( V_33 , V_7 ) ;
do {
T_5 V_28 = * V_37 ;
V_25 = F_43 ( V_7 , V_8 ) ;
if ( F_44 ( V_28 ) )
break;
if ( ! F_34 ( V_28 , V_7 , V_25 , V_9 , V_11 , & V_12 ) )
break;
} while ( V_37 ++ , V_7 = V_25 , V_7 != V_8 );
F_45 ( V_36 ) ;
return V_12 ;
}
int F_46 ( unsigned long V_30 , int V_31 , int V_9 ,
struct V_10 * * V_11 )
{
struct V_32 * V_33 = V_34 -> V_33 ;
unsigned long V_7 , V_35 , V_8 ;
unsigned long V_25 ;
T_5 * V_37 ;
int V_12 = 0 ;
V_30 &= V_38 ;
V_7 = V_30 ;
V_35 = ( unsigned long ) V_31 << V_23 ;
V_8 = V_30 + V_35 ;
if ( V_8 < V_30 )
goto V_42;
#ifdef F_47
if ( V_8 >> V_43 )
goto V_42;
#endif
F_48 () ;
V_37 = F_42 ( V_33 , V_7 ) ;
do {
T_5 V_28 = * V_37 ;
V_25 = F_43 ( V_7 , V_8 ) ;
if ( F_44 ( V_28 ) )
goto V_44;
if ( ! F_34 ( V_28 , V_7 , V_25 , V_9 , V_11 , & V_12 ) )
goto V_44;
} while ( V_37 ++ , V_7 = V_25 , V_7 != V_8 );
F_49 () ;
F_11 ( V_12 != ( V_8 - V_30 ) >> V_23 ) ;
return V_12 ;
{
int V_45 ;
V_44:
F_49 () ;
V_42:
V_30 += V_12 << V_23 ;
V_11 += V_12 ;
V_45 = F_50 ( V_34 , V_33 , V_30 ,
( V_8 - V_30 ) >> V_23 ,
V_9 , 0 , V_11 ) ;
if ( V_12 > 0 ) {
if ( V_45 < 0 )
V_45 = V_12 ;
else
V_45 += V_12 ;
}
return V_45 ;
}
}
