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
void F_16 ( struct V_6 * V_7 )
{
T_2 V_14 ;
for (; ; ) {
V_14 = F_9 ( & V_7 -> V_14 ) ;
if ( ! V_14 )
goto V_22;
if ( V_14 & V_23 )
break;
F_17 () ;
}
while ( F_9 ( & V_7 -> V_14 ) & V_23 )
F_17 () ;
V_22:
F_18 () ;
}
void F_19 ( struct V_6 * V_7 , T_2 V_14 )
{
struct V_19 * V_21 , * V_24 , * V_20 ;
T_2 V_16 , V_15 , V_3 ;
int V_2 ;
F_20 ( V_25 >= ( 1U << V_26 ) ) ;
if ( F_21 () )
goto V_27;
if ( F_22 ( V_7 ) )
return;
if ( V_14 == V_13 ) {
while ( ( V_14 = F_9 ( & V_7 -> V_14 ) ) == V_13 )
F_17 () ;
}
for (; ; ) {
if ( V_14 & ~ V_23 )
goto V_27;
V_16 = V_11 ;
if ( V_14 == V_16 )
V_16 |= V_13 ;
V_15 = F_23 ( & V_7 -> V_14 , V_14 , V_16 ) ;
if ( V_15 == V_14 )
break;
V_14 = V_15 ;
}
if ( V_16 == V_11 )
return;
F_24 ( & V_7 -> V_14 . V_28 , ! ( V_29 & V_23 ) ) ;
F_4 ( V_7 ) ;
return;
V_27:
V_20 = F_25 ( & V_30 [ 0 ] ) ;
V_2 = V_20 -> V_31 ++ ;
V_3 = F_1 ( F_26 () , V_2 ) ;
V_20 += V_2 ;
V_20 -> V_18 = 0 ;
V_20 -> V_24 = NULL ;
F_27 ( V_20 ) ;
if ( F_28 ( V_7 ) )
goto V_32;
V_15 = F_6 ( V_7 , V_3 ) ;
V_24 = NULL ;
if ( V_15 & V_33 ) {
V_21 = F_29 ( V_15 ) ;
F_30 () ;
F_5 ( V_21 -> V_24 , V_20 ) ;
F_31 ( V_20 , V_21 ) ;
F_32 ( & V_20 -> V_18 ) ;
V_24 = F_33 ( V_20 -> V_24 ) ;
if ( V_24 )
F_34 ( V_24 ) ;
}
if ( ( V_14 = F_35 ( V_7 , V_20 ) ) )
goto V_18;
V_14 = F_24 ( & V_7 -> V_14 . V_28 , ! ( V_29 & V_17 ) ) ;
V_18:
for (; ; ) {
if ( ( V_14 & V_33 ) != V_3 ) {
F_11 ( V_7 ) ;
break;
}
V_15 = F_36 ( & V_7 -> V_14 , V_14 , V_11 ) ;
if ( V_15 == V_14 )
goto V_32;
V_14 = V_15 ;
}
if ( ! V_24 ) {
while ( ! ( V_24 = F_33 ( V_20 -> V_24 ) ) )
F_17 () ;
}
F_37 ( & V_24 -> V_18 ) ;
F_38 ( V_7 , V_24 ) ;
V_32:
F_39 ( V_30 [ 0 ] . V_31 ) ;
}
