static inline int F_1 ( int V_1 )
{
return ( V_1 - 1 ) >> 1 ;
}
static inline int F_2 ( int V_1 )
{
return ( V_1 << 1 ) + 1 ;
}
static inline int F_3 ( int V_1 )
{
return ( V_1 << 1 ) + 2 ;
}
static void F_4 ( struct V_2 * V_3 , int V_4 )
{
int V_5 , V_6 , V_7 ;
int V_8 = V_3 -> V_9 [ V_4 ] . V_10 ;
T_1 V_11 = V_3 -> V_9 [ V_4 ] . V_12 ;
if ( F_2 ( V_4 ) >= V_3 -> V_13 )
return;
while( 1 ) {
T_1 V_14 ;
V_5 = F_2 ( V_4 ) ;
V_6 = F_3 ( V_4 ) ;
V_7 = V_4 ;
V_14 = V_11 ;
if ( ( V_5 < V_3 -> V_13 ) && F_5 ( V_11 ,
V_3 -> V_9 [ V_5 ] . V_12 ) ) {
V_7 = V_5 ;
V_14 = V_3 -> V_9 [ V_5 ] . V_12 ;
}
if ( ( V_6 < V_3 -> V_13 ) && F_5 ( V_14 ,
V_3 -> V_9 [ V_6 ] . V_12 ) )
V_7 = V_6 ;
if ( V_7 == V_4 )
break;
V_3 -> V_9 [ V_4 ] . V_10 = V_3 -> V_9 [ V_7 ] . V_10 ;
V_3 -> V_9 [ V_4 ] . V_12 = V_3 -> V_9 [ V_7 ] . V_12 ;
V_3 -> V_9 [ V_3 -> V_9 [ V_4 ] . V_10 ] . V_4 = V_4 ;
V_4 = V_7 ;
}
V_3 -> V_9 [ V_4 ] . V_10 = V_8 ;
V_3 -> V_9 [ V_4 ] . V_12 = V_11 ;
V_3 -> V_9 [ V_3 -> V_9 [ V_4 ] . V_10 ] . V_4 = V_4 ;
}
static void F_6 ( struct V_2 * V_3 , int V_4 )
{
int V_15 ;
int V_8 = V_3 -> V_9 [ V_4 ] . V_10 ;
T_1 V_11 = V_3 -> V_9 [ V_4 ] . V_12 ;
if ( V_4 == 0 )
return;
do {
V_15 = F_1 ( V_4 ) ;
if ( F_5 ( V_11 , V_3 -> V_9 [ V_15 ] . V_12 ) )
break;
V_3 -> V_9 [ V_4 ] . V_10 = V_3 -> V_9 [ V_15 ] . V_10 ;
V_3 -> V_9 [ V_4 ] . V_12 = V_3 -> V_9 [ V_15 ] . V_12 ;
V_3 -> V_9 [ V_3 -> V_9 [ V_4 ] . V_10 ] . V_4 = V_4 ;
V_4 = V_15 ;
} while ( V_4 != 0 );
V_3 -> V_9 [ V_4 ] . V_10 = V_8 ;
V_3 -> V_9 [ V_4 ] . V_12 = V_11 ;
V_3 -> V_9 [ V_3 -> V_9 [ V_4 ] . V_10 ] . V_4 = V_4 ;
}
static void F_7 ( struct V_2 * V_3 , int V_4 )
{
if ( V_4 > 0 && F_5 ( V_3 -> V_9 [ F_1 ( V_4 ) ] . V_12 ,
V_3 -> V_9 [ V_4 ] . V_12 ) )
F_6 ( V_3 , V_4 ) ;
else
F_4 ( V_3 , V_4 ) ;
}
static inline int F_8 ( struct V_2 * V_3 )
{
return V_3 -> V_9 [ 0 ] . V_10 ;
}
int F_9 ( struct V_2 * V_3 , struct V_16 * V_15 ,
struct V_17 * V_18 )
{
int V_19 = - 1 ;
const struct V_20 * V_21 = & V_15 -> V_12 ;
if ( V_18 &&
F_10 ( V_18 , V_3 -> V_22 , & V_15 -> V_23 ) ) {
V_19 = F_11 ( V_18 ) ;
goto V_24;
} else if ( F_12 ( F_8 ( V_3 ) , & V_15 -> V_23 ) &&
F_5 ( V_21 -> V_25 , V_3 -> V_9 [ 0 ] . V_12 ) ) {
V_19 = F_8 ( V_3 ) ;
if ( V_18 )
F_13 ( V_19 , V_18 ) ;
}
V_24:
F_14 ( V_19 != - 1 && ! F_15 ( V_19 ) ) ;
return V_19 ;
}
void F_16 ( struct V_2 * V_3 , int V_10 )
{
int V_26 , V_27 ;
unsigned long V_28 ;
F_14 ( ! F_15 ( V_10 ) ) ;
F_17 ( & V_3 -> V_29 , V_28 ) ;
V_26 = V_3 -> V_9 [ V_10 ] . V_4 ;
if ( V_26 == V_30 ) {
} else {
V_27 = V_3 -> V_9 [ V_3 -> V_13 - 1 ] . V_10 ;
V_3 -> V_9 [ V_26 ] . V_12 = V_3 -> V_9 [ V_3 -> V_13 - 1 ] . V_12 ;
V_3 -> V_9 [ V_26 ] . V_10 = V_27 ;
V_3 -> V_13 -- ;
V_3 -> V_9 [ V_27 ] . V_4 = V_26 ;
V_3 -> V_9 [ V_10 ] . V_4 = V_30 ;
F_7 ( V_3 , V_26 ) ;
F_13 ( V_10 , V_3 -> V_22 ) ;
}
F_18 ( & V_3 -> V_29 , V_28 ) ;
}
void F_19 ( struct V_2 * V_3 , int V_10 , T_1 V_12 )
{
int V_26 ;
unsigned long V_28 ;
F_14 ( ! F_15 ( V_10 ) ) ;
F_17 ( & V_3 -> V_29 , V_28 ) ;
V_26 = V_3 -> V_9 [ V_10 ] . V_4 ;
if ( V_26 == V_30 ) {
int V_31 = V_3 -> V_13 ++ ;
V_3 -> V_9 [ V_31 ] . V_12 = V_12 ;
V_3 -> V_9 [ V_31 ] . V_10 = V_10 ;
V_3 -> V_9 [ V_10 ] . V_4 = V_31 ;
F_6 ( V_3 , V_31 ) ;
F_20 ( V_10 , V_3 -> V_22 ) ;
} else {
V_3 -> V_9 [ V_26 ] . V_12 = V_12 ;
F_7 ( V_3 , V_26 ) ;
}
F_18 ( & V_3 -> V_29 , V_28 ) ;
}
void F_21 ( struct V_2 * V_3 , int V_10 )
{
F_13 ( V_10 , V_3 -> V_22 ) ;
}
void F_22 ( struct V_2 * V_3 , int V_10 )
{
F_20 ( V_10 , V_3 -> V_22 ) ;
}
int F_23 ( struct V_2 * V_3 )
{
int V_1 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_24 ( & V_3 -> V_29 ) ;
V_3 -> V_13 = 0 ;
V_3 -> V_9 = F_25 ( V_32 ,
sizeof( struct V_33 ) ,
V_34 ) ;
if ( ! V_3 -> V_9 )
return - V_35 ;
if ( ! F_26 ( & V_3 -> V_22 , V_34 ) ) {
F_27 ( V_3 -> V_9 ) ;
return - V_35 ;
}
F_28 (i)
V_3 -> V_9 [ V_1 ] . V_4 = V_30 ;
return 0 ;
}
void F_29 ( struct V_2 * V_3 )
{
F_30 ( V_3 -> V_22 ) ;
F_27 ( V_3 -> V_9 ) ;
}
