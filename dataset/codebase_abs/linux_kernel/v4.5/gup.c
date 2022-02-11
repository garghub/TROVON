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
static void F_6 ( int * V_6 , int V_7 , struct V_8 * * V_9 )
{
while ( ( * V_6 ) - V_7 ) {
struct V_8 * V_8 = V_9 [ -- ( * V_6 ) ] ;
F_7 ( V_8 ) ;
F_8 ( V_8 ) ;
}
}
static T_2 int F_9 ( T_3 V_10 , unsigned long V_11 ,
unsigned long V_12 , int V_13 , struct V_8 * * V_9 , int * V_6 )
{
struct V_14 * V_15 = NULL ;
unsigned long V_16 ;
int V_7 = * V_6 ;
T_1 * V_1 ;
V_16 = V_17 | V_18 ;
if ( V_13 )
V_16 |= V_19 ;
V_1 = F_10 ( & V_10 , V_11 ) ;
do {
T_1 V_2 = F_1 ( V_1 ) ;
struct V_8 * V_8 ;
if ( F_11 ( V_2 ) ) {
F_12 ( V_1 ) ;
return 0 ;
}
if ( F_13 ( V_2 ) ) {
V_15 = F_14 ( F_15 ( V_2 ) , V_15 ) ;
if ( F_5 ( ! V_15 ) ) {
F_6 ( V_6 , V_7 , V_9 ) ;
F_12 ( V_1 ) ;
return 0 ;
}
} else if ( ( F_16 ( V_2 ) & ( V_16 | V_20 ) ) != V_16 ) {
F_12 ( V_1 ) ;
return 0 ;
}
F_17 ( ! F_18 ( F_15 ( V_2 ) ) ) ;
V_8 = F_19 ( V_2 ) ;
F_20 ( V_8 ) ;
F_21 ( V_15 ) ;
F_22 ( V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
} while ( V_1 ++ , V_11 += V_21 , V_11 != V_12 );
F_12 ( V_1 - 1 ) ;
return 1 ;
}
static inline void F_23 ( struct V_8 * V_8 , int V_6 )
{
F_24 ( V_8 != F_25 ( V_8 ) , V_8 ) ;
F_24 ( F_26 ( V_8 ) == 0 , V_8 ) ;
F_27 ( V_6 , & V_8 -> V_22 ) ;
F_22 ( V_8 ) ;
}
static int F_28 ( T_3 V_10 , unsigned long V_11 ,
unsigned long V_12 , struct V_8 * * V_9 , int * V_6 )
{
int V_7 = * V_6 ;
unsigned long V_23 = F_29 ( V_10 ) ;
struct V_14 * V_15 = NULL ;
V_23 += ( V_11 & ~ V_24 ) >> V_25 ;
do {
struct V_8 * V_8 = F_30 ( V_23 ) ;
V_15 = F_14 ( V_23 , V_15 ) ;
if ( F_5 ( ! V_15 ) ) {
F_6 ( V_6 , V_7 , V_9 ) ;
return 0 ;
}
F_22 ( V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
F_20 ( V_8 ) ;
F_21 ( V_15 ) ;
( * V_6 ) ++ ;
V_23 ++ ;
} while ( V_11 += V_21 , V_11 != V_12 );
return 1 ;
}
static T_2 int F_31 ( T_3 V_10 , unsigned long V_11 ,
unsigned long V_12 , int V_13 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_16 ;
struct V_8 * V_26 , * V_8 ;
int V_27 ;
V_16 = V_17 | V_18 ;
if ( V_13 )
V_16 |= V_19 ;
if ( ( F_32 ( V_10 ) & V_16 ) != V_16 )
return 0 ;
F_17 ( ! F_18 ( F_29 ( V_10 ) ) ) ;
if ( F_33 ( V_10 ) )
return F_28 ( V_10 , V_11 , V_12 , V_9 , V_6 ) ;
F_17 ( F_32 ( V_10 ) & V_20 ) ;
V_27 = 0 ;
V_26 = F_34 ( V_10 ) ;
V_8 = V_26 + ( ( V_11 & ~ V_24 ) >> V_25 ) ;
do {
F_24 ( F_25 ( V_8 ) != V_26 , V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
V_8 ++ ;
V_27 ++ ;
} while ( V_11 += V_21 , V_11 != V_12 );
F_23 ( V_26 , V_27 ) ;
return 1 ;
}
static int F_35 ( T_4 V_28 , unsigned long V_11 , unsigned long V_12 ,
int V_13 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_29 ;
T_3 * V_30 ;
V_30 = F_36 ( & V_28 , V_11 ) ;
do {
T_3 V_10 = * V_30 ;
V_29 = F_37 ( V_11 , V_12 ) ;
if ( F_38 ( V_10 ) )
return 0 ;
if ( F_5 ( F_39 ( V_10 ) || ! F_40 ( V_10 ) ) ) {
if ( F_41 ( V_10 ) )
return 0 ;
if ( ! F_31 ( V_10 , V_11 , V_29 , V_13 , V_9 , V_6 ) )
return 0 ;
} else {
if ( ! F_9 ( V_10 , V_11 , V_29 , V_13 , V_9 , V_6 ) )
return 0 ;
}
} while ( V_30 ++ , V_11 = V_29 , V_11 != V_12 );
return 1 ;
}
static T_2 int F_42 ( T_4 V_28 , unsigned long V_11 ,
unsigned long V_12 , int V_13 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_16 ;
struct V_8 * V_26 , * V_8 ;
int V_27 ;
V_16 = V_17 | V_18 ;
if ( V_13 )
V_16 |= V_19 ;
if ( ( F_43 ( V_28 ) & V_16 ) != V_16 )
return 0 ;
F_17 ( F_43 ( V_28 ) & V_20 ) ;
F_17 ( ! F_18 ( F_44 ( V_28 ) ) ) ;
V_27 = 0 ;
V_26 = F_45 ( V_28 ) ;
V_8 = V_26 + ( ( V_11 & ~ V_31 ) >> V_25 ) ;
do {
F_24 ( F_25 ( V_8 ) != V_26 , V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
V_8 ++ ;
V_27 ++ ;
} while ( V_11 += V_21 , V_11 != V_12 );
F_23 ( V_26 , V_27 ) ;
return 1 ;
}
static int F_46 ( T_5 V_32 , unsigned long V_11 , unsigned long V_12 ,
int V_13 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_29 ;
T_4 * V_33 ;
V_33 = F_47 ( & V_32 , V_11 ) ;
do {
T_4 V_28 = * V_33 ;
V_29 = F_48 ( V_11 , V_12 ) ;
if ( F_49 ( V_28 ) )
return 0 ;
if ( F_5 ( F_50 ( V_28 ) ) ) {
if ( ! F_42 ( V_28 , V_11 , V_29 , V_13 , V_9 , V_6 ) )
return 0 ;
} else {
if ( ! F_35 ( V_28 , V_11 , V_29 , V_13 , V_9 , V_6 ) )
return 0 ;
}
} while ( V_33 ++ , V_11 = V_29 , V_11 != V_12 );
return 1 ;
}
int F_51 ( unsigned long V_34 , int V_35 , int V_13 ,
struct V_8 * * V_9 )
{
struct V_36 * V_37 = V_38 -> V_37 ;
unsigned long V_11 , V_39 , V_12 ;
unsigned long V_29 ;
unsigned long V_40 ;
T_5 * V_41 ;
int V_6 = 0 ;
V_34 &= V_42 ;
V_11 = V_34 ;
V_39 = ( unsigned long ) V_35 << V_25 ;
V_12 = V_34 + V_39 ;
if ( F_5 ( ! F_52 ( V_13 ? V_43 : V_44 ,
( void V_45 * ) V_34 , V_39 ) ) )
return 0 ;
F_53 ( V_40 ) ;
V_41 = F_54 ( V_37 , V_11 ) ;
do {
T_5 V_32 = * V_41 ;
V_29 = F_55 ( V_11 , V_12 ) ;
if ( F_56 ( V_32 ) )
break;
if ( ! F_46 ( V_32 , V_11 , V_29 , V_13 , V_9 , & V_6 ) )
break;
} while ( V_41 ++ , V_11 = V_29 , V_11 != V_12 );
F_57 ( V_40 ) ;
return V_6 ;
}
int F_58 ( unsigned long V_34 , int V_35 , int V_13 ,
struct V_8 * * V_9 )
{
struct V_36 * V_37 = V_38 -> V_37 ;
unsigned long V_11 , V_39 , V_12 ;
unsigned long V_29 ;
T_5 * V_41 ;
int V_6 = 0 ;
V_34 &= V_42 ;
V_11 = V_34 ;
V_39 = ( unsigned long ) V_35 << V_25 ;
V_12 = V_34 + V_39 ;
if ( V_12 < V_34 )
goto V_46;
#ifdef F_59
if ( V_12 >> V_47 )
goto V_46;
#endif
F_60 () ;
V_41 = F_54 ( V_37 , V_11 ) ;
do {
T_5 V_32 = * V_41 ;
V_29 = F_55 ( V_11 , V_12 ) ;
if ( F_56 ( V_32 ) )
goto V_48;
if ( ! F_46 ( V_32 , V_11 , V_29 , V_13 , V_9 , & V_6 ) )
goto V_48;
} while ( V_41 ++ , V_11 = V_29 , V_11 != V_12 );
F_61 () ;
F_17 ( V_6 != ( V_12 - V_34 ) >> V_25 ) ;
return V_6 ;
{
int V_49 ;
V_48:
F_61 () ;
V_46:
V_34 += V_6 << V_25 ;
V_9 += V_6 ;
V_49 = F_62 ( V_38 , V_37 , V_34 ,
( V_12 - V_34 ) >> V_25 ,
V_13 , 0 , V_9 ) ;
if ( V_6 > 0 ) {
if ( V_49 < 0 )
V_49 = V_6 ;
else
V_49 += V_6 ;
}
return V_49 ;
}
}
