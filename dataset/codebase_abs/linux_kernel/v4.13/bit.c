static inline void
F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 -> V_5 ( V_2 , V_3 ) ;
}
static inline void
F_2 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 -> V_6 ( V_2 , V_3 ) ;
}
static inline int
F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_7 ( V_2 ) ;
}
static inline int
F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_4 -> V_8 ( V_2 ) ;
}
static void
F_5 ( struct V_1 * V_2 , T_1 V_9 )
{
F_6 ( ( V_9 + 500 ) / 1000 ) ;
}
static bool
F_7 ( struct V_1 * V_2 )
{
T_1 V_10 = V_11 / V_12 ;
F_1 ( V_2 , 1 ) ;
do {
F_5 ( V_2 , V_12 ) ;
} while ( ! F_3 ( V_2 ) && -- V_10 );
return V_10 != 0 ;
}
static int
F_8 ( struct V_1 * V_2 )
{
int V_13 = 0 ;
if ( ! F_3 ( V_2 ) ||
! F_4 ( V_2 ) ) {
F_1 ( V_2 , 0 ) ;
F_2 ( V_2 , 1 ) ;
if ( ! F_7 ( V_2 ) )
V_13 = - V_14 ;
}
F_2 ( V_2 , 0 ) ;
F_5 ( V_2 , V_15 ) ;
F_1 ( V_2 , 0 ) ;
F_5 ( V_2 , V_15 ) ;
return V_13 ;
}
static void
F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
F_2 ( V_2 , 0 ) ;
F_5 ( V_2 , V_12 ) ;
F_1 ( V_2 , 1 ) ;
F_5 ( V_2 , V_15 ) ;
F_2 ( V_2 , 1 ) ;
F_5 ( V_2 , V_15 ) ;
}
static int
F_10 ( struct V_1 * V_2 , int V_16 )
{
F_2 ( V_2 , V_16 ) ;
F_5 ( V_2 , V_12 ) ;
if ( ! F_7 ( V_2 ) )
return - V_17 ;
F_5 ( V_2 , V_15 ) ;
F_1 ( V_2 , 0 ) ;
F_5 ( V_2 , V_15 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
int V_16 ;
F_2 ( V_2 , 1 ) ;
F_5 ( V_2 , V_12 ) ;
if ( ! F_7 ( V_2 ) )
return - V_17 ;
F_5 ( V_2 , V_15 ) ;
V_16 = F_4 ( V_2 ) ;
F_1 ( V_2 , 0 ) ;
F_5 ( V_2 , V_15 ) ;
return V_16 ;
}
static int
F_12 ( struct V_1 * V_2 , T_2 * V_18 , bool V_19 )
{
int V_20 , V_21 ;
* V_18 = 0 ;
for ( V_20 = 7 ; V_20 >= 0 ; V_20 -- ) {
V_21 = F_11 ( V_2 ) ;
if ( V_21 < 0 )
return V_21 ;
* V_18 |= V_21 << V_20 ;
}
return F_10 ( V_2 , V_19 ? 1 : 0 ) ;
}
static int
F_13 ( struct V_1 * V_2 , T_2 V_18 )
{
int V_20 , V_13 ;
for ( V_20 = 7 ; V_20 >= 0 ; V_20 -- ) {
V_13 = F_10 ( V_2 , ! ! ( V_18 & ( 1 << V_20 ) ) ) ;
if ( V_13 < 0 )
return V_13 ;
}
V_13 = F_11 ( V_2 ) ;
if ( V_13 == 1 )
V_13 = - V_22 ;
return V_13 ;
}
static int
F_14 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
T_1 V_25 = V_24 -> V_25 << 1 ;
if ( V_24 -> V_26 & V_27 )
V_25 |= 1 ;
return F_13 ( V_2 , V_25 ) ;
}
int
F_15 ( struct V_1 * V_2 , struct V_23 * V_28 , int V_29 )
{
struct V_23 * V_24 = V_28 ;
int V_13 = 0 , V_30 = V_29 ;
while ( ! V_13 && V_30 -- ) {
T_2 V_31 = V_24 -> V_32 ;
T_2 * V_33 = V_24 -> V_34 ;
V_13 = F_8 ( V_2 ) ;
if ( V_13 == 0 )
V_13 = F_14 ( V_2 , V_24 ) ;
if ( V_24 -> V_26 & V_27 ) {
while ( ! V_13 && V_31 -- )
V_13 = F_12 ( V_2 , V_33 ++ , ! V_31 ) ;
} else {
while ( ! V_13 && V_31 -- )
V_13 = F_13 ( V_2 , * V_33 ++ ) ;
}
V_24 ++ ;
}
F_9 ( V_2 ) ;
return ( V_13 < 0 ) ? V_13 : V_29 ;
}
int
F_15 ( struct V_1 * V_2 , struct V_23 * V_28 , int V_29 )
{
return - V_35 ;
}
