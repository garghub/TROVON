static inline int F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( ( V_1 - V_2 ) & V_3 ) > ( V_4 >> 1 ) ;
}
static inline T_1 F_2 ( T_1 V_5 )
{
return ( V_5 + 1 ) & V_3 ;
}
static inline T_1 F_3 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 - V_2 ) & V_3 ;
}
static inline int F_4 ( struct V_6 * V_7 , T_1 V_8 )
{
return F_3 ( V_8 , V_7 -> V_9 ) % V_7 -> V_10 ;
}
static void F_5 ( struct V_11 * V_12 ,
struct V_6 * V_7 ,
int V_13 )
{
struct V_14 * V_15 = F_6 ( V_12 ) ;
struct V_16 * V_17 = V_7 -> V_18 [ V_13 ] ;
if ( ! V_17 )
goto V_19;
V_7 -> V_20 -- ;
V_7 -> V_18 [ V_13 ] = NULL ;
F_7 ( V_17 , V_15 ) ;
V_19:
V_7 -> V_21 = F_2 ( V_7 -> V_21 ) ;
}
static void F_8 ( struct V_11 * V_12 ,
struct V_6 * V_7 ,
T_1 V_22 )
{
int V_13 ;
while ( F_1 ( V_7 -> V_21 , V_22 ) && V_7 -> V_20 ) {
V_13 = F_4 ( V_7 , V_7 -> V_21 ) ;
F_5 ( V_12 , V_7 , V_13 ) ;
}
V_7 -> V_21 = V_22 ;
}
static void F_9 ( struct V_11 * V_12 ,
struct V_6 * V_7 )
{
int V_13 = F_4 ( V_7 , V_7 -> V_21 ) ;
while ( V_7 -> V_18 [ V_13 ] ) {
F_5 ( V_12 , V_7 , V_13 ) ;
V_13 = F_4 ( V_7 , V_7 -> V_21 ) ;
}
}
void F_10 ( struct V_11 * V_12 , struct V_16 * V_17 )
{
struct V_14 * V_15 = F_6 ( V_12 ) ;
struct V_23 * V_24 = F_11 ( V_17 ) ;
int V_25 = F_12 ( V_24 ) ;
int V_26 = F_13 ( V_24 ) ;
int V_27 = F_14 ( V_24 ) ;
T_1 V_8 = F_15 ( V_24 ) ;
struct V_28 * V_29 = & V_12 -> V_29 [ V_26 ] ;
struct V_6 * V_7 = V_29 -> V_30 [ V_25 ] ;
T_1 V_22 ;
int V_13 ;
F_16 ( V_12 , L_1 ,
V_27 , V_26 , V_25 , V_8 ) ;
if ( ! V_7 ) {
F_7 ( V_17 , V_15 ) ;
return;
}
V_22 = V_7 -> V_21 ;
F_17 ( & V_7 -> V_31 ) ;
if ( V_7 -> V_32 ) {
V_7 -> V_32 = false ;
if ( V_8 != V_7 -> V_21 ) {
F_18 ( V_12 , L_2
L_3 , V_8 ,
V_7 -> V_21 ) ;
V_7 -> V_21 = V_8 ;
V_7 -> V_9 = V_8 ;
}
}
if ( F_1 ( V_8 , V_7 -> V_21 ) ) {
F_19 ( V_17 ) ;
goto V_33;
}
if ( ! F_1 ( V_8 , V_7 -> V_21 + V_7 -> V_10 ) ) {
V_22 = F_2 ( F_3 ( V_8 , V_7 -> V_10 ) ) ;
F_8 ( V_12 , V_7 , V_22 ) ;
}
V_13 = F_4 ( V_7 , V_8 ) ;
if ( V_7 -> V_18 [ V_13 ] ) {
F_19 ( V_17 ) ;
goto V_33;
}
if ( V_8 == V_7 -> V_21 && V_7 -> V_20 == 0 ) {
V_7 -> V_21 = F_2 ( V_7 -> V_21 ) ;
F_7 ( V_17 , V_15 ) ;
goto V_33;
}
V_7 -> V_18 [ V_13 ] = V_17 ;
V_7 -> V_34 [ V_13 ] = V_35 ;
V_7 -> V_20 ++ ;
F_9 ( V_12 , V_7 ) ;
V_33:
F_20 ( & V_7 -> V_31 ) ;
}
struct V_6 * F_21 ( struct V_11 * V_12 ,
int V_36 , T_1 V_9 )
{
struct V_6 * V_7 = F_22 ( sizeof( * V_7 ) , V_37 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 =
F_23 ( V_36 , sizeof( struct V_16 * ) , V_37 ) ;
V_7 -> V_34 =
F_23 ( V_36 , sizeof( unsigned long ) , V_37 ) ;
if ( ! V_7 -> V_18 || ! V_7 -> V_34 ) {
F_24 ( V_7 -> V_18 ) ;
F_24 ( V_7 -> V_34 ) ;
F_24 ( V_7 ) ;
return NULL ;
}
F_25 ( & V_7 -> V_31 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_21 = V_9 ;
V_7 -> V_10 = V_36 ;
V_7 -> V_20 = 0 ;
V_7 -> V_32 = true ;
return V_7 ;
}
void F_26 ( struct V_11 * V_12 ,
struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_8 ( V_12 , V_7 , V_7 -> V_21 + V_7 -> V_10 ) ;
F_24 ( V_7 -> V_18 ) ;
F_24 ( V_7 -> V_34 ) ;
F_24 ( V_7 ) ;
}
