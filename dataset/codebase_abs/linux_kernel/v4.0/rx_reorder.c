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
struct V_6 * F_11 ( struct V_11 * V_12 ,
int V_23 , T_1 V_9 )
{
struct V_6 * V_7 = F_12 ( sizeof( * V_7 ) , V_24 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_18 =
F_13 ( V_23 , sizeof( struct V_16 * ) , V_24 ) ;
V_7 -> V_25 =
F_13 ( V_23 , sizeof( unsigned long ) , V_24 ) ;
if ( ! V_7 -> V_18 || ! V_7 -> V_25 ) {
F_14 ( V_7 -> V_18 ) ;
F_14 ( V_7 -> V_25 ) ;
F_14 ( V_7 ) ;
return NULL ;
}
V_7 -> V_9 = V_9 ;
V_7 -> V_21 = V_9 ;
V_7 -> V_10 = V_23 ;
V_7 -> V_20 = 0 ;
V_7 -> V_26 = true ;
return V_7 ;
}
void F_15 ( struct V_11 * V_12 ,
struct V_6 * V_7 )
{
if ( ! V_7 )
return;
F_8 ( V_12 , V_7 , V_7 -> V_21 + V_7 -> V_10 ) ;
F_14 ( V_7 -> V_18 ) ;
F_14 ( V_7 -> V_25 ) ;
F_14 ( V_7 ) ;
}
static T_1 F_16 ( struct V_11 * V_12 , T_1 V_27 )
{
T_1 V_28 = F_17 ( T_1 , V_29 , V_30 /
( V_31 + V_32 ) ) ;
if ( ! V_27 )
return V_28 ;
return F_18 ( V_28 , V_27 ) ;
}
int F_19 ( struct V_11 * V_12 , T_2 V_33 ,
T_2 V_34 , T_3 V_35 ,
T_3 V_36 , T_3 V_37 )
{
struct V_38 * V_39 = F_12 ( sizeof( * V_39 ) , V_24 ) ;
if ( ! V_39 )
return - V_40 ;
V_39 -> V_33 = V_33 ;
V_39 -> V_34 = V_34 ;
V_39 -> V_35 = F_20 ( V_35 ) ;
V_39 -> V_36 = F_20 ( V_36 ) ;
V_39 -> V_37 = F_20 ( V_37 ) ;
F_21 ( & V_12 -> V_41 ) ;
F_22 ( & V_39 -> V_42 , & V_12 -> V_43 ) ;
F_23 ( & V_12 -> V_41 ) ;
F_24 ( V_12 -> V_44 , & V_12 -> V_45 ) ;
return 0 ;
}
static void F_25 ( struct V_11 * V_12 ,
struct V_38 * V_39 )
__acquires( &sta->tid_rx_lock
void F_26 ( struct V_11 * V_12 )
{
struct V_38 * V_46 , * V_47 ;
F_27 ( V_12 , L_1 , V_48 ) ;
F_21 ( & V_12 -> V_41 ) ;
F_28 (evt, t, &wil->back_rx_pending, list) {
F_29 ( & V_46 -> V_42 ) ;
F_14 ( V_46 ) ;
}
F_23 ( & V_12 -> V_41 ) ;
}
static struct V_49 * F_30 ( struct V_11 * V_12 )
{
struct V_49 * V_50 = NULL ;
F_21 ( & V_12 -> V_41 ) ;
if ( ! F_31 ( & V_12 -> V_43 ) ) {
V_50 = V_12 -> V_43 . V_51 ;
F_29 ( V_50 ) ;
}
F_23 ( & V_12 -> V_41 ) ;
return V_50 ;
}
void F_32 ( struct V_52 * V_53 )
{
struct V_11 * V_12 = F_33 ( V_53 , struct V_11 ,
V_45 ) ;
struct V_38 * V_46 ;
struct V_49 * V_54 ;
while ( ( V_54 = F_30 ( V_12 ) ) != NULL ) {
V_46 = F_34 ( V_54 , struct V_38 , V_42 ) ;
F_25 ( V_12 , V_46 ) ;
F_14 ( V_46 ) ;
}
}
static void F_35 ( struct V_11 * V_12 ,
struct V_55 * V_39 )
{
struct V_56 * V_57 = & V_12 -> V_56 [ V_39 -> V_58 ] ;
int V_59 ;
if ( V_57 -> V_60 ) {
F_27 ( V_12 , L_2 ,
V_39 -> V_58 ) ;
return;
}
if ( V_57 -> V_61 ) {
F_27 ( V_12 ,
L_3 ,
V_39 -> V_58 , V_57 -> V_61 ) ;
return;
}
V_57 -> V_60 = true ;
V_59 = F_36 ( V_12 , V_39 -> V_58 , V_39 -> V_61 , V_39 -> V_62 ) ;
if ( V_59 )
V_57 -> V_60 = false ;
}
static struct V_49 * F_37 ( struct V_11 * V_12 )
{
struct V_49 * V_50 = NULL ;
F_21 ( & V_12 -> V_63 ) ;
if ( ! F_31 ( & V_12 -> V_64 ) ) {
V_50 = V_12 -> V_64 . V_51 ;
F_29 ( V_50 ) ;
}
F_23 ( & V_12 -> V_63 ) ;
return V_50 ;
}
void F_38 ( struct V_52 * V_53 )
{
struct V_11 * V_12 = F_33 ( V_53 , struct V_11 ,
V_65 ) ;
struct V_55 * V_46 ;
struct V_49 * V_54 ;
while ( ( V_54 = F_37 ( V_12 ) ) != NULL ) {
V_46 = F_34 ( V_54 , struct V_55 , V_42 ) ;
F_35 ( V_12 , V_46 ) ;
F_14 ( V_46 ) ;
}
}
void F_39 ( struct V_11 * V_12 )
{
struct V_55 * V_46 , * V_47 ;
F_27 ( V_12 , L_1 , V_48 ) ;
F_21 ( & V_12 -> V_63 ) ;
F_28 (evt, t, &wil->back_tx_pending, list) {
F_29 ( & V_46 -> V_42 ) ;
F_14 ( V_46 ) ;
}
F_23 ( & V_12 -> V_63 ) ;
}
int F_40 ( struct V_11 * V_12 , T_2 V_58 , T_1 V_66 )
{
struct V_55 * V_39 = F_12 ( sizeof( * V_39 ) , V_24 ) ;
if ( ! V_39 )
return - V_40 ;
V_39 -> V_58 = V_58 ;
V_39 -> V_61 = F_16 ( V_12 , V_66 ) ;
V_39 -> V_62 = 0 ;
F_21 ( & V_12 -> V_63 ) ;
F_22 ( & V_39 -> V_42 , & V_12 -> V_64 ) ;
F_23 ( & V_12 -> V_63 ) ;
F_24 ( V_12 -> V_44 , & V_12 -> V_65 ) ;
return 0 ;
}
