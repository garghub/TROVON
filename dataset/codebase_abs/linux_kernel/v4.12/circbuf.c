void
F_1 ( T_1 * V_1 ,
T_2 * V_2 ,
T_3 * V_3 )
{
T_4 V_4 ;
F_2 ( V_3 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_3 -> V_5 = 0 ;
V_1 -> V_3 -> V_6 = 0 ;
V_1 -> V_3 -> V_7 = 0 ;
for ( V_4 = 0 ; V_4 < V_1 -> V_3 -> V_8 ; V_4 ++ )
F_3 ( & V_2 [ V_4 ] ) ;
V_1 -> V_2 = V_2 ;
}
void F_4 ( T_1 * V_1 )
{
V_1 -> V_3 = NULL ;
V_1 -> V_2 = NULL ;
}
T_4 F_5 ( T_1 * V_1 )
{
T_4 V_9 ;
T_2 V_10 ;
assert ( ! F_6 ( V_1 ) ) ;
V_10 = F_7 ( V_1 ) ;
V_9 = F_8 ( & V_10 ) ;
return V_9 ;
}
T_4 F_9 ( T_1 * V_1 , int V_11 )
{
int V_12 ;
T_4 V_13 ;
T_4 V_14 ;
T_4 V_15 ;
T_4 V_16 ;
V_12 = F_10 ( V_1 , V_1 -> V_3 -> V_5 , V_1 -> V_3 -> V_6 ) ;
V_12 -- ;
if ( V_11 == 0 ) {
V_13 = F_5 ( V_1 ) ;
return V_13 ;
}
if ( V_11 > V_12 ) {
V_13 = 0 ;
return V_13 ;
}
V_14 = F_11 ( V_1 , V_1 -> V_3 -> V_5 , V_11 ) ;
V_13 = F_8 ( & V_1 -> V_2 [ V_14 ] ) ;
V_15 = F_11 ( V_1 , V_14 , - 1 ) ;
V_16 = V_14 ;
F_12 ( V_1 , V_15 , V_16 ) ;
return V_13 ;
}
T_4 F_13 ( T_1 * V_1 , int V_11 )
{
int V_14 ;
V_14 = F_11 ( V_1 , V_1 -> V_3 -> V_6 , V_11 ) ;
return V_1 -> V_2 [ V_14 ] . V_13 ;
}
T_4 F_14 ( T_1 * V_1 , int V_11 )
{
int V_14 ;
V_14 = F_11 ( V_1 , V_1 -> V_3 -> V_5 , V_11 ) ;
return V_1 -> V_2 [ V_14 ] . V_13 ;
}
bool F_15 (
T_1 * V_1 ,
unsigned int V_17 ,
T_2 * V_2 )
{
T_5 V_18 ;
T_5 V_19 ;
unsigned int V_4 = 0 ;
if ( ! V_1 || V_17 == 0 )
return false ;
V_18 = V_1 -> V_3 -> V_8 ;
V_19 = V_1 -> V_3 -> V_6 ;
if ( ( ( T_5 ) ( V_1 -> V_3 -> V_8 + ( T_5 ) V_17 ) > V_1 -> V_3 -> V_8 ) && ( ( T_5 ) V_17 == V_17 ) )
V_1 -> V_3 -> V_8 += ( T_5 ) V_17 ;
else
return false ;
if ( V_2 ) {
for ( V_4 = V_18 ; V_4 < V_1 -> V_3 -> V_8 ; V_4 ++ )
V_1 -> V_2 [ V_4 ] = V_2 [ V_4 - V_18 ] ;
}
if ( V_19 < V_1 -> V_3 -> V_5 ) {
if ( V_19 == 0 ) {
V_1 -> V_3 -> V_6 = V_18 ;
} else {
F_12 ( V_1 ,
V_18 - 1 ,
V_18 + V_17 - 1 ) ;
}
}
return true ;
}
static inline T_4
F_8 ( T_2 * V_10 )
{
return V_10 -> V_13 ;
}
static inline T_2
F_7 ( T_1 * V_1 )
{
T_2 V_10 ;
V_10 = V_1 -> V_2 [ V_1 -> V_3 -> V_5 ] ;
F_3 ( & V_1 -> V_2 [ V_1 -> V_3 -> V_5 ] ) ;
V_1 -> V_3 -> V_5 = F_11 ( V_1 , V_1 -> V_3 -> V_5 , 1 ) ;
return V_10 ;
}
static inline void
F_12 ( T_1 * V_1 ,
T_4 V_20 , T_4 V_21 )
{
int V_22 ;
int V_23 ;
int V_4 ;
V_22 = F_10 ( V_1 ,
V_20 , V_21 ) ;
V_23 = F_10 ( V_1 , V_1 -> V_3 -> V_5 , V_20 ) + 1 ;
for ( V_4 = 0 ; V_4 < V_23 ; V_4 ++ ) {
F_16 ( & V_1 -> V_2 [ V_20 ] ,
& V_1 -> V_2 [ V_21 ] ) ;
F_3 ( & V_1 -> V_2 [ V_20 ] ) ;
V_20 = F_11 ( V_1 , V_20 , - 1 ) ;
V_21 = F_11 ( V_1 , V_21 , - 1 ) ;
}
V_1 -> V_3 -> V_5 = F_11 ( V_1 , V_1 -> V_3 -> V_5 , V_22 ) ;
}
