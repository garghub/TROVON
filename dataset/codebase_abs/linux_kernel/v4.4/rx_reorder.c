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
if ( ! V_7 )
return;
F_8 ( V_12 , V_7 , V_7 -> V_21 + V_7 -> V_10 ) ;
F_19 ( V_7 -> V_18 ) ;
F_19 ( V_7 -> V_32 ) ;
F_19 ( V_7 ) ;
}
static T_1 F_21 ( struct V_11 * V_12 , T_1 V_34 )
{
T_1 V_35 = F_22 ( T_1 , V_36 , V_37 /
( V_38 + V_39 ) ) ;
if ( ! V_34 )
return V_35 ;
return F_23 ( V_35 , V_34 ) ;
}
int F_24 ( struct V_11 * V_12 , T_2 V_40 ,
T_2 V_41 , T_3 V_42 ,
T_3 V_43 , T_3 V_44 )
{
struct V_45 * V_46 = F_17 ( sizeof( * V_46 ) , V_31 ) ;
if ( ! V_46 )
return - V_47 ;
V_46 -> V_40 = V_40 ;
V_46 -> V_41 = V_41 ;
V_46 -> V_42 = F_25 ( V_42 ) ;
V_46 -> V_43 = F_25 ( V_43 ) ;
V_46 -> V_44 = F_25 ( V_44 ) ;
F_26 ( & V_12 -> V_48 ) ;
F_27 ( & V_46 -> V_49 , & V_12 -> V_50 ) ;
F_28 ( & V_12 -> V_48 ) ;
F_29 ( V_12 -> V_51 , & V_12 -> V_52 ) ;
return 0 ;
}
static void F_30 ( struct V_11 * V_12 ,
struct V_45 * V_46 )
__acquires( &sta->tid_rx_lock
void F_31 ( struct V_11 * V_12 )
{
struct V_45 * V_53 , * V_54 ;
F_32 ( V_12 , L_4 , V_55 ) ;
F_26 ( & V_12 -> V_48 ) ;
F_33 (evt, t, &wil->back_rx_pending, list) {
F_34 ( & V_53 -> V_49 ) ;
F_19 ( V_53 ) ;
}
F_28 ( & V_12 -> V_48 ) ;
}
static struct V_56 * F_35 ( struct V_11 * V_12 )
{
struct V_56 * V_57 = NULL ;
F_26 ( & V_12 -> V_48 ) ;
if ( ! F_36 ( & V_12 -> V_50 ) ) {
V_57 = V_12 -> V_50 . V_58 ;
F_34 ( V_57 ) ;
}
F_28 ( & V_12 -> V_48 ) ;
return V_57 ;
}
void F_37 ( struct V_59 * V_60 )
{
struct V_11 * V_12 = F_38 ( V_60 , struct V_11 ,
V_52 ) ;
struct V_45 * V_53 ;
struct V_56 * V_61 ;
while ( ( V_61 = F_35 ( V_12 ) ) != NULL ) {
V_53 = F_39 ( V_61 , struct V_45 , V_49 ) ;
F_30 ( V_12 , V_53 ) ;
F_19 ( V_53 ) ;
}
}
static void F_40 ( struct V_11 * V_12 ,
struct V_62 * V_46 )
{
struct V_63 * V_64 = & V_12 -> V_63 [ V_46 -> V_65 ] ;
int V_66 ;
if ( V_64 -> V_67 ) {
F_32 ( V_12 , L_5 ,
V_46 -> V_65 ) ;
return;
}
if ( V_64 -> V_68 ) {
F_32 ( V_12 ,
L_6 ,
V_46 -> V_65 , V_64 -> V_68 ) ;
return;
}
V_64 -> V_67 = true ;
V_66 = F_41 ( V_12 , V_46 -> V_65 , V_46 -> V_68 , V_46 -> V_69 ) ;
if ( V_66 )
V_64 -> V_67 = false ;
}
static struct V_56 * F_42 ( struct V_11 * V_12 )
{
struct V_56 * V_57 = NULL ;
F_26 ( & V_12 -> V_70 ) ;
if ( ! F_36 ( & V_12 -> V_71 ) ) {
V_57 = V_12 -> V_71 . V_58 ;
F_34 ( V_57 ) ;
}
F_28 ( & V_12 -> V_70 ) ;
return V_57 ;
}
void F_43 ( struct V_59 * V_60 )
{
struct V_11 * V_12 = F_38 ( V_60 , struct V_11 ,
V_72 ) ;
struct V_62 * V_53 ;
struct V_56 * V_61 ;
while ( ( V_61 = F_42 ( V_12 ) ) != NULL ) {
V_53 = F_39 ( V_61 , struct V_62 , V_49 ) ;
F_40 ( V_12 , V_53 ) ;
F_19 ( V_53 ) ;
}
}
void F_44 ( struct V_11 * V_12 )
{
struct V_62 * V_53 , * V_54 ;
F_32 ( V_12 , L_4 , V_55 ) ;
F_26 ( & V_12 -> V_70 ) ;
F_33 (evt, t, &wil->back_tx_pending, list) {
F_34 ( & V_53 -> V_49 ) ;
F_19 ( V_53 ) ;
}
F_28 ( & V_12 -> V_70 ) ;
}
int F_45 ( struct V_11 * V_12 , T_2 V_65 , T_1 V_73 )
{
struct V_62 * V_46 = F_17 ( sizeof( * V_46 ) , V_31 ) ;
if ( ! V_46 )
return - V_47 ;
V_46 -> V_65 = V_65 ;
V_46 -> V_68 = F_21 ( V_12 , V_73 ) ;
V_46 -> V_69 = 0 ;
F_26 ( & V_12 -> V_70 ) ;
F_27 ( & V_46 -> V_49 , & V_12 -> V_71 ) ;
F_28 ( & V_12 -> V_70 ) ;
F_29 ( V_12 -> V_51 , & V_12 -> V_72 ) ;
return 0 ;
}
