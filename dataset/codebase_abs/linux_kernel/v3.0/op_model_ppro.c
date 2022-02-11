static void F_1 ( struct V_1 const * const V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_2 -> V_5 [ V_3 ] . V_6 )
continue;
F_2 ( V_7 + V_3 ) ;
F_3 ( V_8 + V_3 ) ;
}
if ( V_9 ) {
F_4 ( V_9 ) ;
V_9 = NULL ;
}
}
static int F_5 ( struct V_1 * const V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( ! F_6 ( V_7 + V_3 ) )
goto V_10;
if ( ! F_7 ( V_8 + V_3 ) ) {
F_2 ( V_7 + V_3 ) ;
goto V_10;
}
V_2 -> V_5 [ V_3 ] . V_6 = V_7 + V_3 ;
V_2 -> V_11 [ V_3 ] . V_6 = V_8 + V_3 ;
continue;
V_10:
if ( ! V_12 [ V_3 ] . V_13 )
continue;
F_8 ( V_3 ) ;
F_1 ( V_2 ) ;
return - V_14 ;
}
return 0 ;
}
static void F_9 ( struct V_15 const * V_16 ,
struct V_1 const * const V_2 )
{
T_1 V_17 ;
int V_3 ;
if ( ! V_9 ) {
V_9 = F_10 ( sizeof( V_9 [ 0 ] ) * V_4 ,
V_18 ) ;
if ( ! V_9 )
return;
}
if ( V_19 ) {
union V_20 V_21 ;
V_21 . V_22 = F_11 ( 0xa ) ;
if ( ! ( V_21 . V_23 . V_24 == 0 &&
F_12 ( V_25 . V_26 ) == 6 &&
F_12 ( V_25 . V_27 ) == 15 ) ) {
if ( V_28 < V_21 . V_23 . V_29 )
V_28 = V_21 . V_23 . V_29 ;
}
}
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_2 -> V_11 [ V_3 ] . V_6 )
continue;
F_13 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
if ( V_17 & V_30 )
F_14 ( V_3 ) ;
V_17 &= V_16 -> V_31 ;
F_15 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
F_15 ( V_2 -> V_5 [ V_3 ] . V_6 , - 1LL ) ;
}
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( V_12 [ V_3 ] . V_13 && V_2 -> V_5 [ V_3 ] . V_6 ) {
V_9 [ V_3 ] = V_12 [ V_3 ] . V_32 ;
F_15 ( V_2 -> V_5 [ V_3 ] . V_6 , - V_9 [ V_3 ] ) ;
F_13 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
V_17 &= V_16 -> V_31 ;
V_17 |= F_16 ( V_16 , & V_12 [ V_3 ] ) ;
F_15 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
} else {
V_9 [ V_3 ] = 0 ;
}
}
}
static int F_17 ( struct V_33 * const V_34 ,
struct V_1 const * const V_2 )
{
T_1 V_17 ;
int V_3 ;
if ( F_18 ( ! V_9 ) )
goto V_35;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_9 [ V_3 ] )
continue;
F_13 ( V_2 -> V_5 [ V_3 ] . V_6 , V_17 ) ;
if ( V_17 & ( 1ULL << ( V_28 - 1 ) ) )
continue;
F_19 ( V_34 , V_3 ) ;
F_15 ( V_2 -> V_5 [ V_3 ] . V_6 , - V_9 [ V_3 ] ) ;
}
V_35:
F_20 ( V_36 , F_21 ( V_36 ) & ~ V_37 ) ;
return 1 ;
}
static void F_22 ( struct V_1 const * const V_2 )
{
T_1 V_17 ;
int V_3 ;
if ( ! V_9 )
return;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( V_9 [ V_3 ] ) {
F_13 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
V_17 |= V_30 ;
F_15 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
}
}
}
static void F_23 ( struct V_1 const * const V_2 )
{
T_1 V_17 ;
int V_3 ;
if ( ! V_9 )
return;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_9 [ V_3 ] )
continue;
F_13 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
V_17 &= ~ V_30 ;
F_15 ( V_2 -> V_11 [ V_3 ] . V_6 , V_17 ) ;
}
}
static void F_24 ( void )
{
union V_20 V_21 ;
V_21 . V_22 = F_11 ( 0xa ) ;
if ( V_21 . V_23 . V_24 == 0 && F_12 ( V_25 . V_26 ) == 6 &&
F_12 ( V_25 . V_27 ) == 15 ) {
V_21 . V_23 . V_24 = 2 ;
V_21 . V_23 . V_4 = 2 ;
V_21 . V_23 . V_29 = 40 ;
}
V_4 = V_21 . V_23 . V_4 ;
V_38 . V_4 = V_4 ;
V_38 . V_39 = V_4 ;
}
static int F_25 ( struct V_40 * V_41 )
{
F_24 () ;
return 0 ;
}
