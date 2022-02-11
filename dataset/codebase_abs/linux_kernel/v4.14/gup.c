static inline T_1 F_1 ( T_1 * V_1 )
{
#if F_2 ( V_2 ) && F_2 ( V_3 )
T_1 V_4 ;
V_5:
V_4 . V_6 = V_1 -> V_6 ;
F_3 () ;
V_4 . V_7 = V_1 -> V_7 ;
F_3 () ;
if ( F_4 ( V_4 . V_6 != V_1 -> V_6 ) )
goto V_5;
return V_4 ;
#else
return F_5 ( * V_1 ) ;
#endif
}
static int F_6 ( T_2 V_8 , unsigned long V_9 , unsigned long V_10 ,
int V_11 , struct V_12 * * V_13 , int * V_14 )
{
T_1 * V_1 = F_7 ( & V_8 , V_9 ) ;
do {
T_1 V_4 = F_1 ( V_1 ) ;
struct V_12 * V_12 ;
if ( ! F_8 ( V_4 ) ||
F_9 ( V_4 ) || ( V_11 && ! F_10 ( V_4 ) ) ) {
F_11 ( V_1 ) ;
return 0 ;
}
F_12 ( ! F_13 ( F_14 ( V_4 ) ) ) ;
V_12 = F_15 ( V_4 ) ;
F_16 ( V_12 ) ;
F_17 ( V_12 ) ;
V_13 [ * V_14 ] = V_12 ;
( * V_14 ) ++ ;
} while ( V_1 ++ , V_9 += V_15 , V_9 != V_10 );
F_11 ( V_1 - 1 ) ;
return 1 ;
}
static inline void F_18 ( struct V_12 * V_12 , int V_14 )
{
F_12 ( V_12 != F_19 ( V_12 ) ) ;
F_12 ( F_20 ( V_12 ) == 0 ) ;
F_21 ( V_12 , V_14 ) ;
F_17 ( V_12 ) ;
}
static int F_22 ( T_2 V_8 , unsigned long V_9 , unsigned long V_10 ,
int V_11 , struct V_12 * * V_13 , int * V_14 )
{
T_1 V_4 = * ( T_1 * ) & V_8 ;
struct V_12 * V_16 , * V_12 ;
int V_17 ;
if ( V_11 && ! F_10 ( V_4 ) )
return 0 ;
F_12 ( F_9 ( V_4 ) ) ;
F_12 ( ! F_13 ( F_14 ( V_4 ) ) ) ;
V_17 = 0 ;
V_16 = F_15 ( V_4 ) ;
V_12 = V_16 + ( ( V_9 & ~ V_18 ) >> V_19 ) ;
do {
F_12 ( F_19 ( V_12 ) != V_16 ) ;
V_13 [ * V_14 ] = V_12 ;
( * V_14 ) ++ ;
V_12 ++ ;
V_17 ++ ;
} while ( V_9 += V_15 , V_9 != V_10 );
F_18 ( V_16 , V_17 ) ;
return 1 ;
}
static int F_23 ( T_3 V_20 , unsigned long V_9 , unsigned long V_10 ,
int V_11 , struct V_12 * * V_13 , int * V_14 )
{
unsigned long V_21 ;
T_2 * V_22 ;
V_22 = F_24 ( & V_20 , V_9 ) ;
do {
T_2 V_8 = * V_22 ;
V_21 = F_25 ( V_9 , V_10 ) ;
if ( F_26 ( V_8 ) )
return 0 ;
if ( F_4 ( F_27 ( V_8 ) ) ) {
if ( ! F_22 ( V_8 , V_9 , V_21 , V_11 , V_13 , V_14 ) )
return 0 ;
} else {
if ( ! F_6 ( V_8 , V_9 , V_21 , V_11 , V_13 , V_14 ) )
return 0 ;
}
} while ( V_22 ++ , V_9 = V_21 , V_9 != V_10 );
return 1 ;
}
static int F_28 ( T_3 V_20 , unsigned long V_9 , unsigned long V_10 ,
int V_11 , struct V_12 * * V_13 , int * V_14 )
{
T_1 V_4 = * ( T_1 * ) & V_20 ;
struct V_12 * V_16 , * V_12 ;
int V_17 ;
if ( V_11 && ! F_10 ( V_4 ) )
return 0 ;
F_12 ( F_9 ( V_4 ) ) ;
F_12 ( ! F_13 ( F_14 ( V_4 ) ) ) ;
V_17 = 0 ;
V_16 = F_15 ( V_4 ) ;
V_12 = V_16 + ( ( V_9 & ~ V_23 ) >> V_19 ) ;
do {
F_12 ( F_19 ( V_12 ) != V_16 ) ;
V_13 [ * V_14 ] = V_12 ;
( * V_14 ) ++ ;
V_12 ++ ;
V_17 ++ ;
} while ( V_9 += V_15 , V_9 != V_10 );
F_18 ( V_16 , V_17 ) ;
return 1 ;
}
static int F_29 ( T_4 V_24 , unsigned long V_9 , unsigned long V_10 ,
int V_11 , struct V_12 * * V_13 , int * V_14 )
{
unsigned long V_21 ;
T_3 * V_25 ;
V_25 = F_30 ( & V_24 , V_9 ) ;
do {
T_3 V_20 = * V_25 ;
V_21 = F_31 ( V_9 , V_10 ) ;
if ( F_32 ( V_20 ) )
return 0 ;
if ( F_4 ( F_33 ( V_20 ) ) ) {
if ( ! F_28 ( V_20 , V_9 , V_21 , V_11 , V_13 , V_14 ) )
return 0 ;
} else {
if ( ! F_23 ( V_20 , V_9 , V_21 , V_11 , V_13 , V_14 ) )
return 0 ;
}
} while ( V_25 ++ , V_9 = V_21 , V_9 != V_10 );
return 1 ;
}
int F_34 ( unsigned long V_26 , int V_27 , int V_11 ,
struct V_12 * * V_13 )
{
struct V_28 * V_29 = V_30 -> V_29 ;
unsigned long V_9 , V_31 , V_10 ;
unsigned long V_21 ;
unsigned long V_32 ;
T_4 * V_33 ;
int V_14 = 0 ;
V_26 &= V_34 ;
V_9 = V_26 ;
V_31 = ( unsigned long ) V_27 << V_19 ;
V_10 = V_26 + V_31 ;
if ( F_4 ( ! F_35 ( V_11 ? V_35 : V_36 ,
( void V_37 * ) V_26 , V_31 ) ) )
return 0 ;
F_36 ( V_32 ) ;
V_33 = F_37 ( V_29 , V_9 ) ;
do {
T_4 V_24 = * V_33 ;
V_21 = F_38 ( V_9 , V_10 ) ;
if ( F_39 ( V_24 ) )
break;
if ( ! F_29 ( V_24 , V_9 , V_21 , V_11 , V_13 , & V_14 ) )
break;
} while ( V_33 ++ , V_9 = V_21 , V_9 != V_10 );
F_40 ( V_32 ) ;
return V_14 ;
}
int F_41 ( unsigned long V_26 , int V_27 , int V_11 ,
struct V_12 * * V_13 )
{
struct V_28 * V_29 = V_30 -> V_29 ;
unsigned long V_9 , V_31 , V_10 ;
unsigned long V_21 ;
T_4 * V_33 ;
int V_38 , V_14 = 0 ;
V_26 &= V_34 ;
V_9 = V_26 ;
V_31 = ( unsigned long ) V_27 << V_19 ;
V_10 = V_26 + V_31 ;
if ( V_10 < V_26 || V_39 )
goto V_40;
F_42 () ;
V_33 = F_37 ( V_29 , V_9 ) ;
do {
T_4 V_24 = * V_33 ;
V_21 = F_38 ( V_9 , V_10 ) ;
if ( F_39 ( V_24 ) )
goto V_41;
if ( ! F_29 ( V_24 , V_9 , V_21 , V_11 , V_13 , & V_14 ) )
goto V_41;
} while ( V_33 ++ , V_9 = V_21 , V_9 != V_10 );
F_43 () ;
F_12 ( V_14 != ( V_10 - V_26 ) >> V_19 ) ;
return V_14 ;
V_41:
F_43 () ;
V_40:
V_26 += V_14 << V_19 ;
V_13 += V_14 ;
V_38 = F_44 ( V_26 , ( V_10 - V_26 ) >> V_19 ,
V_13 , V_11 ? V_42 : 0 ) ;
if ( V_14 > 0 ) {
if ( V_38 < 0 )
V_38 = V_14 ;
else
V_38 += V_14 ;
}
return V_38 ;
}
