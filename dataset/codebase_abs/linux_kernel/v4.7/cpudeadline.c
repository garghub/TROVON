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
static void F_4 ( struct V_2 * V_3 , int V_4 , int V_5 )
{
int V_6 = V_3 -> V_7 [ V_4 ] . V_8 , V_9 = V_3 -> V_7 [ V_5 ] . V_8 ;
F_5 ( V_3 -> V_7 [ V_4 ] . V_8 , V_3 -> V_7 [ V_5 ] . V_8 ) ;
F_5 ( V_3 -> V_7 [ V_4 ] . V_10 , V_3 -> V_7 [ V_5 ] . V_10 ) ;
F_5 ( V_3 -> V_7 [ V_6 ] . V_11 , V_3 -> V_7 [ V_9 ] . V_11 ) ;
}
static void F_6 ( struct V_2 * V_3 , int V_11 )
{
int V_12 , V_13 , V_14 ;
while( 1 ) {
V_12 = F_2 ( V_11 ) ;
V_13 = F_3 ( V_11 ) ;
V_14 = V_11 ;
if ( ( V_12 < V_3 -> V_15 ) && F_7 ( V_3 -> V_7 [ V_11 ] . V_10 ,
V_3 -> V_7 [ V_12 ] . V_10 ) )
V_14 = V_12 ;
if ( ( V_13 < V_3 -> V_15 ) && F_7 ( V_3 -> V_7 [ V_14 ] . V_10 ,
V_3 -> V_7 [ V_13 ] . V_10 ) )
V_14 = V_13 ;
if ( V_14 == V_11 )
break;
F_4 ( V_3 , V_14 , V_11 ) ;
V_11 = V_14 ;
}
}
static void F_8 ( struct V_2 * V_3 , int V_11 , T_1 V_16 )
{
F_9 ( V_11 == V_17 || ! F_10 ( V_11 ) ) ;
if ( F_7 ( V_16 , V_3 -> V_7 [ V_11 ] . V_10 ) ) {
V_3 -> V_7 [ V_11 ] . V_10 = V_16 ;
F_6 ( V_3 , V_11 ) ;
} else {
V_3 -> V_7 [ V_11 ] . V_10 = V_16 ;
while ( V_11 > 0 && F_7 ( V_3 -> V_7 [ F_1 ( V_11 ) ] . V_10 ,
V_3 -> V_7 [ V_11 ] . V_10 ) ) {
F_4 ( V_3 , V_11 , F_1 ( V_11 ) ) ;
V_11 = F_1 ( V_11 ) ;
}
}
}
static inline int F_11 ( struct V_2 * V_3 )
{
return V_3 -> V_7 [ 0 ] . V_8 ;
}
int F_12 ( struct V_2 * V_3 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
int V_22 = - 1 ;
const struct V_23 * V_24 = & V_19 -> V_10 ;
if ( V_21 &&
F_13 ( V_21 , V_3 -> V_25 , F_14 ( V_19 ) ) ) {
V_22 = F_15 ( V_21 ) ;
goto V_26;
} else if ( F_16 ( F_11 ( V_3 ) , F_14 ( V_19 ) ) &&
F_7 ( V_24 -> V_27 , V_3 -> V_7 [ 0 ] . V_10 ) ) {
V_22 = F_11 ( V_3 ) ;
if ( V_21 )
F_17 ( V_22 , V_21 ) ;
}
V_26:
F_9 ( V_22 != - 1 && ! F_10 ( V_22 ) ) ;
return V_22 ;
}
void F_18 ( struct V_2 * V_3 , int V_8 , T_1 V_10 , int V_28 )
{
int V_29 , V_30 ;
unsigned long V_31 ;
F_9 ( ! F_10 ( V_8 ) ) ;
F_19 ( & V_3 -> V_32 , V_31 ) ;
V_29 = V_3 -> V_7 [ V_8 ] . V_11 ;
if ( ! V_28 ) {
if ( V_29 == V_17 ) {
goto V_26;
}
V_30 = V_3 -> V_7 [ V_3 -> V_15 - 1 ] . V_8 ;
V_3 -> V_7 [ V_29 ] . V_10 = V_3 -> V_7 [ V_3 -> V_15 - 1 ] . V_10 ;
V_3 -> V_7 [ V_29 ] . V_8 = V_30 ;
V_3 -> V_15 -- ;
V_3 -> V_7 [ V_30 ] . V_11 = V_29 ;
V_3 -> V_7 [ V_8 ] . V_11 = V_17 ;
while ( V_29 > 0 && F_7 (
V_3 -> V_7 [ F_1 ( V_29 ) ] . V_10 ,
V_3 -> V_7 [ V_29 ] . V_10 ) ) {
F_4 ( V_3 , V_29 , F_1 ( V_29 ) ) ;
V_29 = F_1 ( V_29 ) ;
}
F_17 ( V_8 , V_3 -> V_25 ) ;
F_6 ( V_3 , V_29 ) ;
goto V_26;
}
if ( V_29 == V_17 ) {
V_3 -> V_15 ++ ;
V_3 -> V_7 [ V_3 -> V_15 - 1 ] . V_10 = 0 ;
V_3 -> V_7 [ V_3 -> V_15 - 1 ] . V_8 = V_8 ;
V_3 -> V_7 [ V_8 ] . V_11 = V_3 -> V_15 - 1 ;
F_8 ( V_3 , V_3 -> V_15 - 1 , V_10 ) ;
F_20 ( V_8 , V_3 -> V_25 ) ;
} else {
F_8 ( V_3 , V_29 , V_10 ) ;
}
V_26:
F_21 ( & V_3 -> V_32 , V_31 ) ;
}
void F_22 ( struct V_2 * V_3 , int V_8 )
{
F_17 ( V_8 , V_3 -> V_25 ) ;
}
void F_23 ( struct V_2 * V_3 , int V_8 )
{
F_20 ( V_8 , V_3 -> V_25 ) ;
}
int F_24 ( struct V_2 * V_3 )
{
int V_1 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_25 ( & V_3 -> V_32 ) ;
V_3 -> V_15 = 0 ;
V_3 -> V_7 = F_26 ( V_33 ,
sizeof( struct V_34 ) ,
V_35 ) ;
if ( ! V_3 -> V_7 )
return - V_36 ;
if ( ! F_27 ( & V_3 -> V_25 , V_35 ) ) {
F_28 ( V_3 -> V_7 ) ;
return - V_36 ;
}
F_29 (i)
V_3 -> V_7 [ V_1 ] . V_11 = V_17 ;
return 0 ;
}
void F_30 ( struct V_2 * V_3 )
{
F_31 ( V_3 -> V_25 ) ;
F_28 ( V_3 -> V_7 ) ;
}
