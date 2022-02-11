static inline T_1 F_1 ( int V_1 , int V_2 )
{
T_1 V_3 ;
#ifdef F_2
F_3 ( V_2 > 3 ) ;
#endif
V_3 = ( V_1 + 1 ) << V_4 ;
V_3 |= V_2 << V_5 ;
return V_3 ;
}
static inline struct V_6 * F_4 ( T_1 V_3 )
{
int V_1 = ( V_3 >> V_4 ) - 1 ;
int V_2 = ( V_3 & V_7 ) >> V_5 ;
return F_5 ( & V_8 [ V_2 ] , V_1 ) ;
}
static T_2 void F_6 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) V_10 ;
F_7 ( V_12 -> V_13 , V_14 ) ;
}
static T_2 T_1 F_8 ( struct V_9 * V_10 , T_1 V_3 )
{
struct V_11 * V_12 = ( void * ) V_10 ;
return ( T_1 ) F_9 ( & V_12 -> V_3 , V_3 >> V_15 ) << V_15 ;
}
static T_2 void F_6 ( struct V_9 * V_10 )
{
F_10 ( - V_16 + V_14 , & V_10 -> V_17 ) ;
}
static T_2 T_1 F_8 ( struct V_9 * V_10 , T_1 V_3 )
{
T_1 V_18 , V_19 , V_17 = F_11 ( & V_10 -> V_17 ) ;
for (; ; ) {
V_19 = ( V_17 & V_20 ) | V_3 ;
V_18 = F_12 ( & V_10 -> V_17 , V_17 , V_19 ) ;
if ( V_18 == V_17 )
break;
V_17 = V_18 ;
}
return V_18 ;
}
static T_2 void F_13 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = ( void * ) V_10 ;
F_7 ( V_12 -> V_21 , V_14 ) ;
}
static T_2 void F_14 ( struct V_6 * V_22 ) { }
static T_2 void F_15 ( struct V_6 * V_22 ) { }
static T_2 void F_16 ( struct V_9 * V_10 ,
struct V_6 * V_22 ) { }
static T_2 void F_17 ( struct V_9 * V_10 ,
struct V_6 * V_22 ) { }
void F_18 ( struct V_9 * V_10 , T_1 V_17 )
{
struct V_6 * V_23 , * V_24 , * V_22 ;
T_1 V_19 , V_18 , V_3 ;
int V_2 ;
F_19 ( V_25 >= ( 1U << V_26 ) ) ;
if ( F_20 () )
goto V_27;
if ( F_21 ( V_10 ) )
return;
if ( V_17 == V_16 ) {
while ( ( V_17 = F_11 ( & V_10 -> V_17 ) ) == V_16 )
F_22 () ;
}
for (; ; ) {
if ( V_17 & ~ V_28 )
goto V_27;
V_19 = V_14 ;
if ( V_17 == V_19 )
V_19 |= V_16 ;
V_18 = F_12 ( & V_10 -> V_17 , V_17 , V_19 ) ;
if ( V_18 == V_17 )
break;
V_17 = V_18 ;
}
if ( V_19 == V_14 )
return;
while ( ( V_17 = F_23 ( & V_10 -> V_17 . V_29 ) ) & V_28 )
F_22 () ;
F_6 ( V_10 ) ;
return;
V_27:
V_22 = F_24 ( & V_8 [ 0 ] ) ;
V_2 = V_22 -> V_30 ++ ;
V_3 = F_1 ( F_25 () , V_2 ) ;
V_22 += V_2 ;
V_22 -> V_21 = 0 ;
V_22 -> V_24 = NULL ;
F_26 ( V_22 ) ;
if ( F_27 ( V_10 ) )
goto V_31;
V_18 = F_8 ( V_10 , V_3 ) ;
if ( V_18 & V_32 ) {
V_23 = F_4 ( V_18 ) ;
F_7 ( V_23 -> V_24 , V_22 ) ;
F_28 ( V_22 ) ;
F_29 ( & V_22 -> V_21 ) ;
}
F_30 ( V_10 , V_22 ) ;
while ( ( V_17 = F_23 ( & V_10 -> V_17 . V_29 ) ) & V_20 )
F_22 () ;
for (; ; ) {
if ( V_17 != V_3 ) {
F_13 ( V_10 ) ;
break;
}
V_18 = F_12 ( & V_10 -> V_17 , V_17 , V_14 ) ;
if ( V_18 == V_17 )
goto V_31;
V_17 = V_18 ;
}
while ( ! ( V_24 = F_31 ( V_22 -> V_24 ) ) )
F_22 () ;
F_32 ( & V_24 -> V_21 ) ;
F_33 ( V_10 , V_24 ) ;
V_31:
F_34 ( V_8 [ 0 ] . V_30 ) ;
}
