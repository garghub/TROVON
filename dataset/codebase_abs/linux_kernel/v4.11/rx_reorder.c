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
__acquires( &sta->tid_rx_lock
void F_11 ( struct V_11 * V_12 , T_2 V_23 , T_2 V_24 , T_1 V_8 )
{
struct V_25 * V_26 = & V_12 -> V_26 [ V_23 ] ;
struct V_6 * V_7 ;
F_12 ( & V_26 -> V_27 ) ;
V_7 = V_26 -> V_28 [ V_24 ] ;
if ( ! V_7 ) {
F_13 ( V_12 , L_1 , V_23 , V_24 ) ;
goto V_29;
}
if ( F_1 ( V_8 , V_7 -> V_21 ) ) {
F_13 ( V_12 , L_2 ,
V_8 , V_7 -> V_21 ) ;
goto V_29;
}
F_14 ( V_12 , L_3 ,
V_23 , V_24 , V_8 , V_7 -> V_21 ) ;
F_8 ( V_12 , V_7 , V_8 ) ;
V_29:
F_15 ( & V_26 -> V_27 ) ;
}
struct V_6 * F_16 ( struct V_11 * V_12 ,
int V_30 , T_1 V_9 )
{
struct V_6 * V_7 = F_17 ( sizeof( * V_7 ) , V_31 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 =
F_18 ( V_30 , sizeof( struct V_16 * ) , V_31 ) ;
V_7 -> V_32 =
F_18 ( V_30 , sizeof( unsigned long ) , V_31 ) ;
if ( ! V_7 -> V_18 || ! V_7 -> V_32 ) {
F_19 ( V_7 -> V_18 ) ;
F_19 ( V_7 -> V_32 ) ;
F_19 ( V_7 ) ;
return NULL ;
}
V_7 -> V_9 = V_9 ;
V_7 -> V_21 = V_9 ;
V_7 -> V_10 = V_30 ;
V_7 -> V_20 = 0 ;
V_7 -> V_33 = true ;
return V_7 ;
}
void F_20 ( struct V_11 * V_12 ,
struct V_6 * V_7 )
{
int V_34 ;
if ( ! V_7 )
return;
for ( V_34 = 0 ; V_34 < V_7 -> V_10 ; V_34 ++ )
F_21 ( V_7 -> V_18 [ V_34 ] ) ;
F_19 ( V_7 -> V_18 ) ;
F_19 ( V_7 -> V_32 ) ;
F_19 ( V_7 ) ;
}
static T_1 F_22 ( struct V_11 * V_12 , T_1 V_35 )
{
T_1 V_36 = F_23 ( T_1 , V_37 , V_38 /
( V_39 + V_40 ) ) ;
if ( ! V_35 )
return V_36 ;
return F_24 ( V_36 , V_35 ) ;
}
int F_25 ( struct V_11 * V_12 , T_2 V_41 ,
T_2 V_42 , T_3 V_43 ,
T_3 V_44 , T_3 V_45 )
__acquires( &sta->tid_rx_lock
int F_26 ( struct V_11 * V_12 , T_2 V_46 , T_1 V_47 )
{
T_2 V_48 = F_22 ( V_12 , V_47 ) ;
T_1 V_49 = 0 ;
struct V_50 * V_51 = & V_12 -> V_50 [ V_46 ] ;
int V_52 = 0 ;
if ( V_51 -> V_53 ) {
F_27 ( V_12 , L_4 ,
V_46 ) ;
goto V_29;
}
if ( V_51 -> V_48 ) {
F_27 ( V_12 ,
L_5 ,
V_46 , V_51 -> V_48 ) ;
goto V_29;
}
V_51 -> V_53 = true ;
V_52 = F_28 ( V_12 , V_46 , V_48 , V_49 ) ;
if ( V_52 ) {
F_13 ( V_12 , L_6 , V_52 ) ;
V_51 -> V_53 = false ;
}
V_29:
return V_52 ;
}
