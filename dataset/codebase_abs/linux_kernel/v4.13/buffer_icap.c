T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 + V_4 ) ;
}
static inline T_1 F_3 ( void T_2 * V_3 ,
T_1 V_5 )
{
return F_2 ( V_3 + ( V_5 << 2 ) ) ;
}
static inline bool F_4 ( void T_2 * V_3 )
{
T_1 V_6 = F_2 ( V_3 + V_4 ) ;
return ( V_6 & 1 ) == V_7 ;
}
static inline void F_5 ( void T_2 * V_3 ,
T_1 V_8 )
{
F_6 ( V_3 + V_9 , V_8 ) ;
}
static inline void F_7 ( void T_2 * V_3 ,
T_1 V_8 )
{
F_6 ( V_3 + V_10 , V_8 ) ;
}
static inline void F_8 ( void T_2 * V_3 ,
T_1 V_8 )
{
F_6 ( V_3 + V_11 , V_8 ) ;
}
static inline void F_9 ( void T_2 * V_3 ,
T_1 V_5 , T_1 V_8 )
{
F_6 ( V_3 + ( V_5 << 2 ) , V_8 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_12 )
{
T_3 V_13 = 0 ;
void T_2 * V_3 = V_2 -> V_3 ;
if ( F_4 ( V_3 ) )
return - V_14 ;
if ( ( V_5 + V_12 ) > V_15 )
return - V_16 ;
F_5 ( V_3 , ( V_12 << 2 ) ) ;
F_7 ( V_3 , V_5 ) ;
F_8 ( V_3 , V_17 ) ;
while ( F_4 ( V_3 ) ) {
V_13 ++ ;
if ( V_13 > V_18 )
return - V_14 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_12 )
{
T_3 V_13 = 0 ;
void T_2 * V_3 = V_2 -> V_3 ;
if ( F_4 ( V_3 ) )
return - V_14 ;
if ( ( V_5 + V_12 ) > V_15 )
return - V_16 ;
F_5 ( V_3 , V_12 << 2 ) ;
F_7 ( V_3 , V_5 ) ;
F_8 ( V_3 , V_19 ) ;
while ( F_4 ( V_3 ) ) {
V_13 ++ ;
if ( V_13 > V_18 )
return - V_14 ;
}
return 0 ;
}
void F_12 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_3 + V_4 , 0xFEFE ) ;
}
int F_13 ( struct V_1 * V_2 , T_1 * V_8 ,
T_1 V_20 )
{
int V_6 ;
T_3 V_21 = 0 ;
bool V_22 = false ;
T_1 V_23 ;
void T_2 * V_3 = V_2 -> V_3 ;
for ( V_23 = 0 , V_21 = 0 ; V_23 < V_20 ; V_23 ++ ) {
F_9 ( V_3 , V_21 , V_8 [ V_23 ] ) ;
V_22 = true ;
if ( V_21 < V_15 - 1 ) {
V_21 ++ ;
continue;
}
V_6 = F_11 (
V_2 ,
V_24 ,
V_15 ) ;
if ( V_6 != 0 ) {
F_12 ( V_2 ) ;
return V_6 ;
}
V_21 = 0 ;
V_22 = false ;
}
if ( V_22 ) {
V_6 = F_11 ( V_2 , V_24 ,
V_21 ) ;
if ( V_6 != 0 ) {
F_12 ( V_2 ) ;
}
return V_6 ;
}
return 0 ;
}
int F_14 ( struct V_1 * V_2 , T_1 * V_8 ,
T_1 V_20 )
{
int V_6 ;
T_3 V_21 = 0 ;
T_1 V_23 ;
void T_2 * V_3 = V_2 -> V_3 ;
for ( V_23 = 0 , V_21 = V_15 ; V_23 < V_20 ; V_23 ++ ) {
if ( V_21 == V_15 ) {
T_1 V_25 = V_20 - V_23 ;
T_1 V_26 =
V_25 <
V_15 ? V_25 :
V_15 ;
V_6 = F_10 (
V_2 ,
V_24 ,
V_26 ) ;
if ( V_6 != 0 ) {
F_12 ( V_2 ) ;
return V_6 ;
}
V_21 = 0 ;
}
V_8 [ V_23 ] = F_3 ( V_3 , V_21 ) ;
V_21 ++ ;
}
return 0 ;
}
