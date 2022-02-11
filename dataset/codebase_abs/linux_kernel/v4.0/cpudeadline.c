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
static inline int F_4 ( T_1 V_2 , T_1 V_3 )
{
return ( V_4 ) ( V_2 - V_3 ) < 0 ;
}
static void F_5 ( struct V_5 * V_6 , int V_2 , int V_3 )
{
int V_7 = V_6 -> V_8 [ V_2 ] . V_9 , V_10 = V_6 -> V_8 [ V_3 ] . V_9 ;
F_6 ( V_6 -> V_8 [ V_2 ] . V_9 , V_6 -> V_8 [ V_3 ] . V_9 ) ;
F_6 ( V_6 -> V_8 [ V_2 ] . V_11 , V_6 -> V_8 [ V_3 ] . V_11 ) ;
F_6 ( V_6 -> V_8 [ V_7 ] . V_12 , V_6 -> V_8 [ V_10 ] . V_12 ) ;
}
static void F_7 ( struct V_5 * V_6 , int V_12 )
{
int V_13 , V_14 , V_15 ;
while( 1 ) {
V_13 = F_2 ( V_12 ) ;
V_14 = F_3 ( V_12 ) ;
V_15 = V_12 ;
if ( ( V_13 < V_6 -> V_16 ) && F_4 ( V_6 -> V_8 [ V_12 ] . V_11 ,
V_6 -> V_8 [ V_13 ] . V_11 ) )
V_15 = V_13 ;
if ( ( V_14 < V_6 -> V_16 ) && F_4 ( V_6 -> V_8 [ V_15 ] . V_11 ,
V_6 -> V_8 [ V_14 ] . V_11 ) )
V_15 = V_14 ;
if ( V_15 == V_12 )
break;
F_5 ( V_6 , V_15 , V_12 ) ;
V_12 = V_15 ;
}
}
static void F_8 ( struct V_5 * V_6 , int V_12 , T_1 V_17 )
{
F_9 ( V_12 == V_18 || ! F_10 ( V_12 ) ) ;
if ( F_4 ( V_17 , V_6 -> V_8 [ V_12 ] . V_11 ) ) {
V_6 -> V_8 [ V_12 ] . V_11 = V_17 ;
F_7 ( V_6 , V_12 ) ;
} else {
V_6 -> V_8 [ V_12 ] . V_11 = V_17 ;
while ( V_12 > 0 && F_4 ( V_6 -> V_8 [ F_1 ( V_12 ) ] . V_11 ,
V_6 -> V_8 [ V_12 ] . V_11 ) ) {
F_5 ( V_6 , V_12 , F_1 ( V_12 ) ) ;
V_12 = F_1 ( V_12 ) ;
}
}
}
static inline int F_11 ( struct V_5 * V_6 )
{
return V_6 -> V_8 [ 0 ] . V_9 ;
}
int F_12 ( struct V_5 * V_6 , struct V_19 * V_20 ,
struct V_21 * V_22 )
{
int V_23 = - 1 ;
const struct V_24 * V_25 = & V_20 -> V_11 ;
if ( V_22 &&
F_13 ( V_22 , V_6 -> V_26 , & V_20 -> V_27 ) ) {
V_23 = F_14 ( V_22 ) ;
goto V_28;
} else if ( F_15 ( F_11 ( V_6 ) , & V_20 -> V_27 ) &&
F_4 ( V_25 -> V_29 , V_6 -> V_8 [ 0 ] . V_11 ) ) {
V_23 = F_11 ( V_6 ) ;
if ( V_22 )
F_16 ( V_23 , V_22 ) ;
}
V_28:
F_9 ( V_23 != - 1 && ! F_10 ( V_23 ) ) ;
return V_23 ;
}
void F_17 ( struct V_5 * V_6 , int V_9 , T_1 V_11 , int V_30 )
{
int V_31 , V_32 ;
unsigned long V_33 ;
F_9 ( ! F_10 ( V_9 ) ) ;
F_18 ( & V_6 -> V_34 , V_33 ) ;
V_31 = V_6 -> V_8 [ V_9 ] . V_12 ;
if ( ! V_30 ) {
if ( V_31 == V_18 ) {
goto V_28;
}
V_32 = V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_9 ;
V_6 -> V_8 [ V_31 ] . V_11 = V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_11 ;
V_6 -> V_8 [ V_31 ] . V_9 = V_32 ;
V_6 -> V_16 -- ;
V_6 -> V_8 [ V_32 ] . V_12 = V_31 ;
V_6 -> V_8 [ V_9 ] . V_12 = V_18 ;
while ( V_31 > 0 && F_4 (
V_6 -> V_8 [ F_1 ( V_31 ) ] . V_11 ,
V_6 -> V_8 [ V_31 ] . V_11 ) ) {
F_5 ( V_6 , V_31 , F_1 ( V_31 ) ) ;
V_31 = F_1 ( V_31 ) ;
}
F_16 ( V_9 , V_6 -> V_26 ) ;
F_7 ( V_6 , V_31 ) ;
goto V_28;
}
if ( V_31 == V_18 ) {
V_6 -> V_16 ++ ;
V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_11 = 0 ;
V_6 -> V_8 [ V_6 -> V_16 - 1 ] . V_9 = V_9 ;
V_6 -> V_8 [ V_9 ] . V_12 = V_6 -> V_16 - 1 ;
F_8 ( V_6 , V_6 -> V_16 - 1 , V_11 ) ;
F_19 ( V_9 , V_6 -> V_26 ) ;
} else {
F_8 ( V_6 , V_31 , V_11 ) ;
}
V_28:
F_20 ( & V_6 -> V_34 , V_33 ) ;
}
void F_21 ( struct V_5 * V_6 , int V_9 )
{
F_16 ( V_9 , V_6 -> V_26 ) ;
}
void F_22 ( struct V_5 * V_6 , int V_9 )
{
F_19 ( V_9 , V_6 -> V_26 ) ;
}
int F_23 ( struct V_5 * V_6 )
{
int V_1 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_24 ( & V_6 -> V_34 ) ;
V_6 -> V_16 = 0 ;
V_6 -> V_8 = F_25 ( V_35 ,
sizeof( struct V_36 ) ,
V_37 ) ;
if ( ! V_6 -> V_8 )
return - V_38 ;
if ( ! F_26 ( & V_6 -> V_26 , V_37 ) ) {
F_27 ( V_6 -> V_8 ) ;
return - V_38 ;
}
F_28 (i)
V_6 -> V_8 [ V_1 ] . V_12 = V_18 ;
return 0 ;
}
void F_29 ( struct V_5 * V_6 )
{
F_30 ( V_6 -> V_26 ) ;
F_27 ( V_6 -> V_8 ) ;
}
