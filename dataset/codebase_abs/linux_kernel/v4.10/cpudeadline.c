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
F_10 ( V_18 , V_3 -> V_22 , F_11 ( V_15 ) ) ) {
V_19 = F_12 ( V_18 ) ;
goto V_23;
} else if ( F_13 ( F_8 ( V_3 ) , F_11 ( V_15 ) ) &&
F_5 ( V_21 -> V_24 , V_3 -> V_9 [ 0 ] . V_12 ) ) {
V_19 = F_8 ( V_3 ) ;
if ( V_18 )
F_14 ( V_19 , V_18 ) ;
}
V_23:
F_15 ( V_19 != - 1 && ! F_16 ( V_19 ) ) ;
return V_19 ;
}
void F_17 ( struct V_2 * V_3 , int V_10 )
{
int V_25 , V_26 ;
unsigned long V_27 ;
F_15 ( ! F_16 ( V_10 ) ) ;
F_18 ( & V_3 -> V_28 , V_27 ) ;
V_25 = V_3 -> V_9 [ V_10 ] . V_4 ;
if ( V_25 == V_29 ) {
} else {
V_26 = V_3 -> V_9 [ V_3 -> V_13 - 1 ] . V_10 ;
V_3 -> V_9 [ V_25 ] . V_12 = V_3 -> V_9 [ V_3 -> V_13 - 1 ] . V_12 ;
V_3 -> V_9 [ V_25 ] . V_10 = V_26 ;
V_3 -> V_13 -- ;
V_3 -> V_9 [ V_26 ] . V_4 = V_25 ;
V_3 -> V_9 [ V_10 ] . V_4 = V_29 ;
F_7 ( V_3 , V_25 ) ;
F_14 ( V_10 , V_3 -> V_22 ) ;
}
F_19 ( & V_3 -> V_28 , V_27 ) ;
}
void F_20 ( struct V_2 * V_3 , int V_10 , T_1 V_12 )
{
int V_25 ;
unsigned long V_27 ;
F_15 ( ! F_16 ( V_10 ) ) ;
F_18 ( & V_3 -> V_28 , V_27 ) ;
V_25 = V_3 -> V_9 [ V_10 ] . V_4 ;
if ( V_25 == V_29 ) {
int V_30 = V_3 -> V_13 ++ ;
V_3 -> V_9 [ V_30 ] . V_12 = V_12 ;
V_3 -> V_9 [ V_30 ] . V_10 = V_10 ;
V_3 -> V_9 [ V_10 ] . V_4 = V_30 ;
F_6 ( V_3 , V_30 ) ;
F_21 ( V_10 , V_3 -> V_22 ) ;
} else {
V_3 -> V_9 [ V_25 ] . V_12 = V_12 ;
F_7 ( V_3 , V_25 ) ;
}
F_19 ( & V_3 -> V_28 , V_27 ) ;
}
void F_22 ( struct V_2 * V_3 , int V_10 )
{
F_14 ( V_10 , V_3 -> V_22 ) ;
}
void F_23 ( struct V_2 * V_3 , int V_10 )
{
F_21 ( V_10 , V_3 -> V_22 ) ;
}
int F_24 ( struct V_2 * V_3 )
{
int V_1 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_25 ( & V_3 -> V_28 ) ;
V_3 -> V_13 = 0 ;
V_3 -> V_9 = F_26 ( V_31 ,
sizeof( struct V_32 ) ,
V_33 ) ;
if ( ! V_3 -> V_9 )
return - V_34 ;
if ( ! F_27 ( & V_3 -> V_22 , V_33 ) ) {
F_28 ( V_3 -> V_9 ) ;
return - V_34 ;
}
F_29 (i)
V_3 -> V_9 [ V_1 ] . V_4 = V_29 ;
return 0 ;
}
void F_30 ( struct V_2 * V_3 )
{
F_31 ( V_3 -> V_22 ) ;
F_28 ( V_3 -> V_9 ) ;
}
