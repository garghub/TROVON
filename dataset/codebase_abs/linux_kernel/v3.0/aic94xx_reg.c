static void F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 V_4 )
{
if ( F_2 ( V_2 -> V_5 ) )
F_3 ( V_4 ,
( unsigned long ) V_2 -> V_6 [ 0 ] . V_7 + ( V_3 & 0xFF ) ) ;
else
F_4 ( V_4 , V_2 -> V_6 [ 0 ] . V_7 + V_3 ) ;
F_5 () ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned long V_3 , T_2 V_4 )
{
if ( F_2 ( V_2 -> V_5 ) )
F_7 ( V_4 ,
( unsigned long ) V_2 -> V_6 [ 0 ] . V_7 + ( V_3 & 0xFF ) ) ;
else
F_8 ( V_4 , V_2 -> V_6 [ 0 ] . V_7 + V_3 ) ;
F_5 () ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned long V_3 , T_3 V_4 )
{
if ( F_2 ( V_2 -> V_5 ) )
F_10 ( V_4 ,
( unsigned long ) V_2 -> V_6 [ 0 ] . V_7 + ( V_3 & 0xFF ) ) ;
else
F_11 ( V_4 , V_2 -> V_6 [ 0 ] . V_7 + V_3 ) ;
F_5 () ;
}
static T_1 F_12 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 ;
if ( F_2 ( V_2 -> V_5 ) )
V_4 = F_13 ( ( unsigned long ) V_2 -> V_6 [ 0 ] . V_7
+ ( V_3 & 0xFF ) ) ;
else
V_4 = F_14 ( V_2 -> V_6 [ 0 ] . V_7 + V_3 ) ;
F_15 () ;
return V_4 ;
}
static T_2 F_16 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_2 V_4 ;
if ( F_2 ( V_2 -> V_5 ) )
V_4 = F_17 ( ( unsigned long ) V_2 -> V_6 [ 0 ] . V_7
+ ( V_3 & 0xFF ) ) ;
else
V_4 = F_18 ( V_2 -> V_6 [ 0 ] . V_7 + V_3 ) ;
F_15 () ;
return V_4 ;
}
static T_3 F_19 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_3 V_4 ;
if ( F_2 ( V_2 -> V_5 ) )
V_4 = F_20 ( ( unsigned long ) V_2 -> V_6 [ 0 ] . V_7
+ ( V_3 & 0xFF ) ) ;
else
V_4 = F_21 ( V_2 -> V_6 [ 0 ] . V_7 + V_3 ) ;
F_15 () ;
return V_4 ;
}
static inline T_3 F_22 ( void )
{
return 0 ;
}
static inline T_3 F_23 ( void )
{
return F_22 () + V_8 ;
}
static inline T_3 F_24 ( void )
{
return F_23 () + V_9 + 0x20 ;
}
static void F_25 ( struct V_1 * V_2 , T_3 V_10 )
{
T_3 V_11 = V_10 & ~ ( V_12 - 1 ) ;
F_26 ( V_2 -> V_13 , V_14 , V_11 ) ;
V_2 -> V_6 [ 0 ] . V_15 = V_11 ;
}
static void F_27 ( struct V_1 * V_2 , T_3 V_10 , T_1 V_4 )
{
struct V_16 * V_6 = & V_2 -> V_6 [ 0 ] ;
F_28 ( V_10 >= 0xC0000000 || V_10 < V_17 ) ;
if ( V_6 -> V_18 <= V_10
&& V_10 < V_6 -> V_18 + V_8 )
F_29 ( V_2 , V_10 , V_4 ) ;
else if ( V_6 -> V_15 <= V_10
&& V_10 < V_6 -> V_15 + V_12 )
F_30 ( V_2 , V_10 , V_4 ) ;
else if ( V_6 -> V_19 <= V_10
&& V_10 < V_6 -> V_19 + V_9 )
F_31 ( V_2 , V_10 , V_4 ) ;
else {
F_25 ( V_2 , V_10 ) ;
F_30 ( V_2 , V_10 , V_4 ) ;
}
}
static T_1 F_32 ( struct V_1 * V_2 , T_3 V_10 )
{
struct V_16 * V_6 = & V_2 -> V_6 [ 0 ] ;
T_1 V_4 ;
F_28 ( V_10 >= 0xC0000000 || V_10 < V_17 ) ;
if ( V_6 -> V_18 <= V_10
&& V_10 < V_6 -> V_18 + V_8 )
V_4 = F_33 ( V_2 , V_10 ) ;
else if ( V_6 -> V_15 <= V_10
&& V_10 < V_6 -> V_15 + V_12 )
V_4 = F_34 ( V_2 , V_10 ) ;
else if ( V_6 -> V_19 <= V_10
&& V_10 < V_6 -> V_19 + V_9 )
V_4 = F_35 ( V_2 , V_10 ) ;
else {
F_25 ( V_2 , V_10 ) ;
V_4 = F_34 ( V_2 , V_10 ) ;
}
return V_4 ;
}
void F_36 ( struct V_1 * V_2 , void * V_20 ,
T_3 V_3 , int V_21 )
{
T_1 * V_22 = V_20 ;
unsigned long V_23 ;
F_37 ( & V_2 -> V_24 , V_23 ) ;
for ( ; V_21 > 0 ; V_21 -- , V_3 ++ , V_22 ++ )
* V_22 = F_32 ( V_2 , V_3 ) ;
F_38 ( & V_2 -> V_24 , V_23 ) ;
}
void F_39 ( struct V_1 * V_2 , void * V_25 ,
T_3 V_3 , int V_21 )
{
T_1 * V_22 = V_25 ;
unsigned long V_23 ;
F_37 ( & V_2 -> V_24 , V_23 ) ;
for ( ; V_21 > 0 ; V_21 -- , V_3 ++ , V_22 ++ )
F_27 ( V_2 , V_3 , * V_22 ) ;
F_38 ( & V_2 -> V_24 , V_23 ) ;
}
