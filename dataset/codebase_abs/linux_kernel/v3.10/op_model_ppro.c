static void F_1 ( struct V_1 const * const V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_2 -> V_5 [ V_3 ] . V_6 )
continue;
F_2 ( V_7 + V_3 ) ;
F_3 ( V_8 + V_3 ) ;
}
}
static int F_4 ( struct V_1 * const V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( ! F_5 ( V_7 + V_3 ) )
goto V_9;
if ( ! F_6 ( V_8 + V_3 ) ) {
F_2 ( V_7 + V_3 ) ;
goto V_9;
}
V_2 -> V_5 [ V_3 ] . V_6 = V_7 + V_3 ;
V_2 -> V_10 [ V_3 ] . V_6 = V_8 + V_3 ;
continue;
V_9:
if ( ! V_11 [ V_3 ] . V_12 )
continue;
F_7 ( V_3 ) ;
F_1 ( V_2 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_8 ( struct V_14 const * V_15 ,
struct V_1 const * const V_2 )
{
T_1 V_16 ;
int V_3 ;
if ( V_17 ) {
union V_18 V_19 ;
V_19 . V_20 = F_9 ( 0xa ) ;
if ( ! ( V_19 . V_21 . V_22 == 0 &&
F_10 ( V_23 . V_24 ) == 6 &&
F_10 ( V_23 . V_25 ) == 15 ) ) {
if ( V_26 < V_19 . V_21 . V_27 )
V_26 = V_19 . V_21 . V_27 ;
}
}
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_2 -> V_10 [ V_3 ] . V_6 )
continue;
F_11 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
if ( V_16 & V_28 )
F_12 ( V_3 ) ;
V_16 &= V_15 -> V_29 ;
F_13 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
F_13 ( V_2 -> V_5 [ V_3 ] . V_6 , - 1LL ) ;
}
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( V_11 [ V_3 ] . V_12 && V_2 -> V_5 [ V_3 ] . V_6 ) {
V_30 [ V_3 ] = V_11 [ V_3 ] . V_31 ;
F_13 ( V_2 -> V_5 [ V_3 ] . V_6 , - V_30 [ V_3 ] ) ;
F_11 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
V_16 &= V_15 -> V_29 ;
V_16 |= F_14 ( V_15 , & V_11 [ V_3 ] ) ;
F_13 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
} else {
V_30 [ V_3 ] = 0 ;
}
}
}
static int F_15 ( struct V_32 * const V_33 ,
struct V_1 const * const V_2 )
{
T_1 V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_30 [ V_3 ] )
continue;
F_11 ( V_2 -> V_5 [ V_3 ] . V_6 , V_16 ) ;
if ( V_16 & ( 1ULL << ( V_26 - 1 ) ) )
continue;
F_16 ( V_33 , V_3 ) ;
F_13 ( V_2 -> V_5 [ V_3 ] . V_6 , - V_30 [ V_3 ] ) ;
}
F_17 ( V_34 , F_18 ( V_34 ) & ~ V_35 ) ;
return 1 ;
}
static void F_19 ( struct V_1 const * const V_2 )
{
T_1 V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( V_30 [ V_3 ] ) {
F_11 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
V_16 |= V_28 ;
F_13 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
}
}
}
static void F_20 ( struct V_1 const * const V_2 )
{
T_1 V_16 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 ) {
if ( ! V_30 [ V_3 ] )
continue;
F_11 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
V_16 &= ~ V_28 ;
F_13 ( V_2 -> V_10 [ V_3 ] . V_6 , V_16 ) ;
}
}
static void F_21 ( void )
{
union V_18 V_19 ;
V_19 . V_20 = F_9 ( 0xa ) ;
if ( V_19 . V_21 . V_22 == 0 && F_10 ( V_23 . V_24 ) == 6 &&
F_10 ( V_23 . V_25 ) == 15 ) {
V_19 . V_21 . V_22 = 2 ;
V_19 . V_21 . V_4 = 2 ;
V_19 . V_21 . V_27 = 40 ;
}
V_4 = F_22 ( ( int ) V_19 . V_21 . V_4 , V_36 ) ;
V_37 . V_4 = V_4 ;
V_37 . V_38 = V_4 ;
}
static int F_23 ( struct V_39 * V_40 )
{
F_21 () ;
return 0 ;
}
