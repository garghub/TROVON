static inline T_1 T_2 F_1 ( int V_1 , int V_2 )
{
T_2 V_3 ;
#ifdef F_2
F_3 ( V_2 > 3 ) ;
#endif
V_3 = ( V_1 + 1 ) << V_4 ;
V_3 |= V_2 << V_5 ;
return V_3 ;
}
static T_3 void F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = ( void * ) V_7 ;
F_5 ( V_9 -> V_10 , V_11 ) ;
}
static T_3 T_2 F_6 ( struct V_6 * V_7 , T_2 V_3 )
{
struct V_8 * V_9 = ( void * ) V_7 ;
return ( T_2 ) F_7 ( & V_9 -> V_3 ,
V_3 >> V_12 ) << V_12 ;
}
static T_3 void F_4 ( struct V_6 * V_7 )
{
F_8 ( - V_13 + V_11 , & V_7 -> V_14 ) ;
}
static T_3 T_2 F_6 ( struct V_6 * V_7 , T_2 V_3 )
{
T_2 V_15 , V_16 , V_14 = F_9 ( & V_7 -> V_14 ) ;
for (; ; ) {
V_16 = ( V_14 & V_17 ) | V_3 ;
V_15 = F_10 ( & V_7 -> V_14 , V_14 , V_16 ) ;
if ( V_15 == V_14 )
break;
V_14 = V_15 ;
}
return V_15 ;
}
static T_3 void F_11 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = ( void * ) V_7 ;
F_5 ( V_9 -> V_18 , V_11 ) ;
}
static T_3 void F_12 ( struct V_19 * V_20 ) { }
static T_3 void F_13 ( struct V_19 * V_20 ,
struct V_19 * V_21 ) { }
static T_3 void F_14 ( struct V_6 * V_7 ,
struct V_19 * V_20 ) { }
static T_3 T_2 F_15 ( struct V_6 * V_7 ,
struct V_19 * V_20 )
{ return 0 ; }
void F_16 ( struct V_6 * V_7 , T_2 V_14 )
{
struct V_19 * V_21 , * V_22 , * V_20 ;
T_2 V_16 , V_15 , V_3 ;
int V_2 ;
F_17 ( V_23 >= ( 1U << V_24 ) ) ;
if ( F_18 () )
goto V_25;
if ( F_19 ( V_7 ) )
return;
if ( V_14 == V_13 ) {
while ( ( V_14 = F_9 ( & V_7 -> V_14 ) ) == V_13 )
F_20 () ;
}
for (; ; ) {
if ( V_14 & ~ V_26 )
goto V_25;
V_16 = V_11 ;
if ( V_14 == V_16 )
V_16 |= V_13 ;
V_15 = F_21 ( & V_7 -> V_14 , V_14 , V_16 ) ;
if ( V_15 == V_14 )
break;
V_14 = V_15 ;
}
if ( V_16 == V_11 )
return;
F_22 ( & V_7 -> V_14 . V_27 , ! ( V_28 & V_26 ) ) ;
F_4 ( V_7 ) ;
return;
V_25:
V_20 = F_23 ( & V_29 [ 0 ] ) ;
V_2 = V_20 -> V_30 ++ ;
V_3 = F_1 ( F_24 () , V_2 ) ;
V_20 += V_2 ;
V_20 -> V_18 = 0 ;
V_20 -> V_22 = NULL ;
F_25 ( V_20 ) ;
if ( F_26 ( V_7 ) )
goto V_31;
V_15 = F_6 ( V_7 , V_3 ) ;
V_22 = NULL ;
if ( V_15 & V_32 ) {
V_21 = F_27 ( V_15 ) ;
F_28 () ;
F_5 ( V_21 -> V_22 , V_20 ) ;
F_29 ( V_20 , V_21 ) ;
F_30 ( & V_20 -> V_18 ) ;
V_22 = F_31 ( V_20 -> V_22 ) ;
if ( V_22 )
F_32 ( V_22 ) ;
}
if ( ( V_14 = F_33 ( V_7 , V_20 ) ) )
goto V_18;
V_14 = F_22 ( & V_7 -> V_14 . V_27 , ! ( V_28 & V_17 ) ) ;
V_18:
for (; ; ) {
if ( ( V_14 & V_32 ) != V_3 ) {
F_11 ( V_7 ) ;
break;
}
V_15 = F_34 ( & V_7 -> V_14 , V_14 , V_11 ) ;
if ( V_15 == V_14 )
goto V_31;
V_14 = V_15 ;
}
if ( ! V_22 ) {
while ( ! ( V_22 = F_31 ( V_20 -> V_22 ) ) )
F_20 () ;
}
F_35 ( & V_22 -> V_18 ) ;
F_36 ( V_7 , V_22 ) ;
V_31:
F_37 ( V_29 [ 0 ] . V_30 ) ;
}
