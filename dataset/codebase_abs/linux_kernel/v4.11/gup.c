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
int V_7 = * V_6 , V_21 = 0 ;
T_1 * V_1 , * V_22 ;
V_22 = V_1 = F_13 ( & V_16 , V_17 ) ;
do {
T_1 V_2 = F_1 ( V_1 ) ;
struct V_8 * V_8 ;
if ( F_14 ( V_2 ) )
break;
if ( ! F_9 ( F_15 ( V_2 ) , V_11 ) )
break;
if ( F_16 ( V_2 ) ) {
V_20 = F_17 ( F_18 ( V_2 ) , V_20 ) ;
if ( F_5 ( ! V_20 ) ) {
F_6 ( V_6 , V_7 , V_9 ) ;
break;
}
} else if ( F_19 ( V_2 ) )
break;
F_20 ( ! F_21 ( F_18 ( V_2 ) ) ) ;
V_8 = F_22 ( V_2 ) ;
F_23 ( V_8 ) ;
F_24 ( V_20 ) ;
F_25 ( V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
} while ( V_1 ++ , V_17 += V_23 , V_17 != V_18 );
if ( V_17 == V_18 )
V_21 = 1 ;
F_26 ( V_22 ) ;
return V_21 ;
}
static inline void F_27 ( struct V_8 * V_8 , int V_6 )
{
F_28 ( V_8 != F_29 ( V_8 ) , V_8 ) ;
F_28 ( F_30 ( V_8 ) == 0 , V_8 ) ;
F_31 ( V_8 , V_6 ) ;
F_25 ( V_8 ) ;
}
static int F_32 ( unsigned long V_24 , unsigned long V_17 ,
unsigned long V_18 , struct V_8 * * V_9 , int * V_6 )
{
int V_7 = * V_6 ;
struct V_19 * V_20 = NULL ;
do {
struct V_8 * V_8 = F_33 ( V_24 ) ;
V_20 = F_17 ( V_24 , V_20 ) ;
if ( F_5 ( ! V_20 ) ) {
F_6 ( V_6 , V_7 , V_9 ) ;
return 0 ;
}
F_25 ( V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
F_23 ( V_8 ) ;
F_24 ( V_20 ) ;
( * V_6 ) ++ ;
V_24 ++ ;
} while ( V_17 += V_23 , V_17 != V_18 );
return 1 ;
}
static int F_34 ( T_3 V_16 , unsigned long V_17 ,
unsigned long V_18 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_25 ;
V_25 = F_35 ( V_16 ) + ( ( V_17 & ~ V_26 ) >> V_27 ) ;
return F_32 ( V_25 , V_17 , V_18 , V_9 , V_6 ) ;
}
static int F_36 ( T_4 V_28 , unsigned long V_17 ,
unsigned long V_18 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_25 ;
V_25 = F_37 ( V_28 ) + ( ( V_17 & ~ V_29 ) >> V_27 ) ;
return F_32 ( V_25 , V_17 , V_18 , V_9 , V_6 ) ;
}
static T_2 int F_38 ( T_3 V_16 , unsigned long V_17 ,
unsigned long V_18 , int V_11 , struct V_8 * * V_9 , int * V_6 )
{
struct V_8 * V_30 , * V_8 ;
int V_31 ;
if ( ! F_9 ( F_39 ( V_16 ) , V_11 ) )
return 0 ;
F_20 ( ! F_21 ( F_35 ( V_16 ) ) ) ;
if ( F_40 ( V_16 ) )
return F_34 ( V_16 , V_17 , V_18 , V_9 , V_6 ) ;
F_20 ( F_41 ( V_16 ) & V_32 ) ;
V_31 = 0 ;
V_30 = F_42 ( V_16 ) ;
V_8 = V_30 + ( ( V_17 & ~ V_26 ) >> V_27 ) ;
do {
F_28 ( F_29 ( V_8 ) != V_30 , V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
V_8 ++ ;
V_31 ++ ;
} while ( V_17 += V_23 , V_17 != V_18 );
F_27 ( V_30 , V_31 ) ;
return 1 ;
}
static int F_43 ( T_4 V_28 , unsigned long V_17 , unsigned long V_18 ,
int V_11 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_33 ;
T_3 * V_34 ;
V_34 = F_44 ( & V_28 , V_17 ) ;
do {
T_3 V_16 = * V_34 ;
V_33 = F_45 ( V_17 , V_18 ) ;
if ( F_46 ( V_16 ) )
return 0 ;
if ( F_5 ( F_47 ( V_16 ) || ! F_48 ( V_16 ) ) ) {
if ( F_49 ( V_16 ) )
return 0 ;
if ( ! F_38 ( V_16 , V_17 , V_33 , V_11 , V_9 , V_6 ) )
return 0 ;
} else {
if ( ! F_12 ( V_16 , V_17 , V_33 , V_11 , V_9 , V_6 ) )
return 0 ;
}
} while ( V_34 ++ , V_17 = V_33 , V_17 != V_18 );
return 1 ;
}
static T_2 int F_50 ( T_4 V_28 , unsigned long V_17 ,
unsigned long V_18 , int V_11 , struct V_8 * * V_9 , int * V_6 )
{
struct V_8 * V_30 , * V_8 ;
int V_31 ;
if ( ! F_9 ( F_51 ( V_28 ) , V_11 ) )
return 0 ;
F_20 ( ! F_21 ( F_37 ( V_28 ) ) ) ;
if ( F_52 ( V_28 ) )
return F_36 ( V_28 , V_17 , V_18 , V_9 , V_6 ) ;
F_20 ( F_53 ( V_28 ) & V_32 ) ;
V_31 = 0 ;
V_30 = F_54 ( V_28 ) ;
V_8 = V_30 + ( ( V_17 & ~ V_29 ) >> V_27 ) ;
do {
F_28 ( F_29 ( V_8 ) != V_30 , V_8 ) ;
V_9 [ * V_6 ] = V_8 ;
( * V_6 ) ++ ;
V_8 ++ ;
V_31 ++ ;
} while ( V_17 += V_23 , V_17 != V_18 );
F_27 ( V_30 , V_31 ) ;
return 1 ;
}
static int F_55 ( T_5 V_35 , unsigned long V_17 , unsigned long V_18 ,
int V_11 , struct V_8 * * V_9 , int * V_6 )
{
unsigned long V_33 ;
T_4 * V_36 ;
V_36 = F_56 ( & V_35 , V_17 ) ;
do {
T_4 V_28 = * V_36 ;
V_33 = F_57 ( V_17 , V_18 ) ;
if ( F_58 ( V_28 ) )
return 0 ;
if ( F_5 ( F_59 ( V_28 ) ) ) {
if ( ! F_50 ( V_28 , V_17 , V_33 , V_11 , V_9 , V_6 ) )
return 0 ;
} else {
if ( ! F_43 ( V_28 , V_17 , V_33 , V_11 , V_9 , V_6 ) )
return 0 ;
}
} while ( V_36 ++ , V_17 = V_33 , V_17 != V_18 );
return 1 ;
}
int F_60 ( unsigned long V_37 , int V_38 , int V_11 ,
struct V_8 * * V_9 )
{
struct V_39 * V_40 = V_41 -> V_40 ;
unsigned long V_17 , V_42 , V_18 ;
unsigned long V_33 ;
unsigned long V_43 ;
T_5 * V_44 ;
int V_6 = 0 ;
V_37 &= V_45 ;
V_17 = V_37 ;
V_42 = ( unsigned long ) V_38 << V_27 ;
V_18 = V_37 + V_42 ;
if ( F_5 ( ! F_61 ( V_11 ? V_46 : V_47 ,
( void V_48 * ) V_37 , V_42 ) ) )
return 0 ;
F_62 ( V_43 ) ;
V_44 = F_63 ( V_40 , V_17 ) ;
do {
T_5 V_35 = * V_44 ;
V_33 = F_64 ( V_17 , V_18 ) ;
if ( F_65 ( V_35 ) )
break;
if ( ! F_55 ( V_35 , V_17 , V_33 , V_11 , V_9 , & V_6 ) )
break;
} while ( V_44 ++ , V_17 = V_33 , V_17 != V_18 );
F_66 ( V_43 ) ;
return V_6 ;
}
int F_67 ( unsigned long V_37 , int V_38 , int V_11 ,
struct V_8 * * V_9 )
{
struct V_39 * V_40 = V_41 -> V_40 ;
unsigned long V_17 , V_42 , V_18 ;
unsigned long V_33 ;
T_5 * V_44 ;
int V_6 = 0 ;
V_37 &= V_45 ;
V_17 = V_37 ;
V_42 = ( unsigned long ) V_38 << V_27 ;
V_18 = V_37 + V_42 ;
if ( V_18 < V_37 )
goto V_49;
#ifdef F_68
if ( V_18 >> V_50 )
goto V_49;
#endif
F_69 () ;
V_44 = F_63 ( V_40 , V_17 ) ;
do {
T_5 V_35 = * V_44 ;
V_33 = F_64 ( V_17 , V_18 ) ;
if ( F_65 ( V_35 ) )
goto V_51;
if ( ! F_55 ( V_35 , V_17 , V_33 , V_11 , V_9 , & V_6 ) )
goto V_51;
} while ( V_44 ++ , V_17 = V_33 , V_17 != V_18 );
F_70 () ;
F_20 ( V_6 != ( V_18 - V_37 ) >> V_27 ) ;
return V_6 ;
{
int V_21 ;
V_51:
F_70 () ;
V_49:
V_37 += V_6 << V_27 ;
V_9 += V_6 ;
V_21 = F_71 ( V_37 ,
( V_18 - V_37 ) >> V_27 ,
V_9 , V_11 ? V_52 : 0 ) ;
if ( V_6 > 0 ) {
if ( V_21 < 0 )
V_21 = V_6 ;
else
V_21 += V_6 ;
}
return V_21 ;
}
}
