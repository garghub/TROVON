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
static inline int F_9 ( unsigned long V_10 , int V_11 )
{
unsigned long V_12 = V_13 | V_14 ;
if ( V_11 )
V_12 |= V_15 ;
if ( ( V_10 & V_12 ) != V_12 )
return 0 ;
if ( ! F_10 ( F_11 ( V_10 ) , V_11 ) )
return 0 ;
return 1 ;
}
static T_2 int F_12 ( T_3 V_16 , unsigned long V_17 ,
unsigned long V_18 , int V_11 , struct V_8 * * V_9 , int * V_6 )
{
struct V_19 * V_20 = NULL ;
int V_7 = * V_6 ;
T_1 * V_1 ;
V_1 = F_13 ( & V_16 , V_17 ) ;
do {
T_1 V_2 = F_1 ( V_1 ) ;
struct V_8 * V_8 ;
if ( F_14 ( V_2 ) ) {
F_15 ( V_1 ) ;
return 0 ;
}
if ( F_16 ( V_2 ) ) {
V_20 = F_17 ( F_18 ( V_2 ) , V_20 ) ;
if ( F_5 ( ! V_20 ) ) {
F_6 ( V_6 , V_7 , V_9 ) ;
F_15 ( V_1 ) ;
return 0 ;
}
} else if ( ! F_9 ( F_19 ( V_2 ) , V_11 ) ||
F_20 ( V_2 ) ) {
F_15 ( V_1 ) ;
return 0 ;
}
F_21 ( ! F_22 ( F_18 ( V_2 ) ) ) ;
V_8 = F_23 ( V_2 ) ;
F_24 ( V_8 ) ;
F_25 ( V_20 ) ;
F_26 ( V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
} while ( V_1 ++ , V_17 += V_21 , V_17 != V_18 );
F_15 ( V_1 - 1 ) ;
return 1 ;
}
static inline void F_27 ( struct V_8 * V_8 , int V_6 )
{
F_28 ( V_8 != F_29 ( V_8 ) , V_8 ) ;
F_28 ( F_30 ( V_8 ) == 0 , V_8 ) ;
F_31 ( V_8 , V_6 ) ;
F_26 ( V_8 ) ;
}
static int F_32 ( T_3 V_16 , unsigned long V_17 ,
unsigned long V_18 , struct V_8 * * V_9 , int * V_6 )
{
int V_7 = * V_6 ;
unsigned long V_22 = F_33 ( V_16 ) ;
struct V_19 * V_20 = NULL ;
V_22 += ( V_17 & ~ V_23 ) >> V_24 ;
do {
struct V_8 * V_8 = F_34 ( V_22 ) ;
V_20 = F_17 ( V_22 , V_20 ) ;
if ( F_5 ( ! V_20 ) ) {
F_6 ( V_6 , V_7 , V_9 ) ;
return 0 ;
}
F_26 ( V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
F_24 ( V_8 ) ;
F_25 ( V_20 ) ;
( * V_6 ) ++ ;
V_22 ++ ;
} while ( V_17 += V_21 , V_17 != V_18 );
return 1 ;
}
static T_2 int F_35 ( T_3 V_16 , unsigned long V_17 ,
unsigned long V_18 , int V_11 , struct V_8 * * V_9 , int * V_6 )
{
struct V_8 * V_25 , * V_8 ;
int V_26 ;
if ( ! F_9 ( F_36 ( V_16 ) , V_11 ) )
return 0 ;
F_21 ( ! F_22 ( F_33 ( V_16 ) ) ) ;
if ( F_37 ( V_16 ) )
return F_32 ( V_16 , V_17 , V_18 , V_9 , V_6 ) ;
F_21 ( F_38 ( V_16 ) & V_27 ) ;
V_26 = 0 ;
V_25 = F_39 ( V_16 ) ;
V_8 = V_25 + ( ( V_17 & ~ V_23 ) >> V_24 ) ;
do {
F_28 ( F_29 ( V_8 ) != V_25 , V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
V_8 ++ ;
V_26 ++ ;
} while ( V_17 += V_21 , V_17 != V_18 );
F_27 ( V_25 , V_26 ) ;
return 1 ;
}
static int F_40 ( T_4 V_28 , unsigned long V_17 , unsigned long V_18 ,
int V_11 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_29 ;
T_3 * V_30 ;
V_30 = F_41 ( & V_28 , V_17 ) ;
do {
T_3 V_16 = * V_30 ;
V_29 = F_42 ( V_17 , V_18 ) ;
if ( F_43 ( V_16 ) )
return 0 ;
if ( F_5 ( F_44 ( V_16 ) || ! F_45 ( V_16 ) ) ) {
if ( F_46 ( V_16 ) )
return 0 ;
if ( ! F_35 ( V_16 , V_17 , V_29 , V_11 , V_9 , V_6 ) )
return 0 ;
} else {
if ( ! F_12 ( V_16 , V_17 , V_29 , V_11 , V_9 , V_6 ) )
return 0 ;
}
} while ( V_30 ++ , V_17 = V_29 , V_17 != V_18 );
return 1 ;
}
static T_2 int F_47 ( T_4 V_28 , unsigned long V_17 ,
unsigned long V_18 , int V_11 , struct V_8 * * V_9 , int * V_6 )
{
struct V_8 * V_25 , * V_8 ;
int V_26 ;
if ( ! F_9 ( F_48 ( V_28 ) , V_11 ) )
return 0 ;
F_21 ( F_49 ( V_28 ) & V_27 ) ;
F_21 ( ! F_22 ( F_50 ( V_28 ) ) ) ;
V_26 = 0 ;
V_25 = F_51 ( V_28 ) ;
V_8 = V_25 + ( ( V_17 & ~ V_31 ) >> V_24 ) ;
do {
F_28 ( F_29 ( V_8 ) != V_25 , V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
V_8 ++ ;
V_26 ++ ;
} while ( V_17 += V_21 , V_17 != V_18 );
F_27 ( V_25 , V_26 ) ;
return 1 ;
}
static int F_52 ( T_5 V_32 , unsigned long V_17 , unsigned long V_18 ,
int V_11 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_29 ;
T_4 * V_33 ;
V_33 = F_53 ( & V_32 , V_17 ) ;
do {
T_4 V_28 = * V_33 ;
V_29 = F_54 ( V_17 , V_18 ) ;
if ( F_55 ( V_28 ) )
return 0 ;
if ( F_5 ( F_56 ( V_28 ) ) ) {
if ( ! F_47 ( V_28 , V_17 , V_29 , V_11 , V_9 , V_6 ) )
return 0 ;
} else {
if ( ! F_40 ( V_28 , V_17 , V_29 , V_11 , V_9 , V_6 ) )
return 0 ;
}
} while ( V_33 ++ , V_17 = V_29 , V_17 != V_18 );
return 1 ;
}
int F_57 ( unsigned long V_34 , int V_35 , int V_11 ,
struct V_8 * * V_9 )
{
struct V_36 * V_37 = V_38 -> V_37 ;
unsigned long V_17 , V_39 , V_18 ;
unsigned long V_29 ;
unsigned long V_40 ;
T_5 * V_41 ;
int V_6 = 0 ;
V_34 &= V_42 ;
V_17 = V_34 ;
V_39 = ( unsigned long ) V_35 << V_24 ;
V_18 = V_34 + V_39 ;
if ( F_5 ( ! F_58 ( V_11 ? V_43 : V_44 ,
( void V_45 * ) V_34 , V_39 ) ) )
return 0 ;
F_59 ( V_40 ) ;
V_41 = F_60 ( V_37 , V_17 ) ;
do {
T_5 V_32 = * V_41 ;
V_29 = F_61 ( V_17 , V_18 ) ;
if ( F_62 ( V_32 ) )
break;
if ( ! F_52 ( V_32 , V_17 , V_29 , V_11 , V_9 , & V_6 ) )
break;
} while ( V_41 ++ , V_17 = V_29 , V_17 != V_18 );
F_63 ( V_40 ) ;
return V_6 ;
}
int F_64 ( unsigned long V_34 , int V_35 , int V_11 ,
struct V_8 * * V_9 )
{
struct V_36 * V_37 = V_38 -> V_37 ;
unsigned long V_17 , V_39 , V_18 ;
unsigned long V_29 ;
T_5 * V_41 ;
int V_6 = 0 ;
V_34 &= V_42 ;
V_17 = V_34 ;
V_39 = ( unsigned long ) V_35 << V_24 ;
V_18 = V_34 + V_39 ;
if ( V_18 < V_34 )
goto V_46;
#ifdef F_65
if ( V_18 >> V_47 )
goto V_46;
#endif
F_66 () ;
V_41 = F_60 ( V_37 , V_17 ) ;
do {
T_5 V_32 = * V_41 ;
V_29 = F_61 ( V_17 , V_18 ) ;
if ( F_62 ( V_32 ) )
goto V_48;
if ( ! F_52 ( V_32 , V_17 , V_29 , V_11 , V_9 , & V_6 ) )
goto V_48;
} while ( V_41 ++ , V_17 = V_29 , V_17 != V_18 );
F_67 () ;
F_21 ( V_6 != ( V_18 - V_34 ) >> V_24 ) ;
return V_6 ;
{
int V_49 ;
V_48:
F_67 () ;
V_46:
V_34 += V_6 << V_24 ;
V_9 += V_6 ;
V_49 = F_68 ( V_34 ,
( V_18 - V_34 ) >> V_24 ,
V_11 , 0 , V_9 ) ;
if ( V_6 > 0 ) {
if ( V_49 < 0 )
V_49 = V_6 ;
else
V_49 += V_6 ;
}
return V_49 ;
}
}
