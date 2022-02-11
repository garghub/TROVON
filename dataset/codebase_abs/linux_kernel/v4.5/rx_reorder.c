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
{
struct V_46 * V_47 = F_17 ( sizeof( * V_47 ) , V_31 ) ;
if ( ! V_47 )
return - V_48 ;
V_47 -> V_41 = V_41 ;
V_47 -> V_42 = V_42 ;
V_47 -> V_43 = F_26 ( V_43 ) ;
V_47 -> V_44 = F_26 ( V_44 ) ;
V_47 -> V_45 = F_26 ( V_45 ) ;
F_27 ( & V_12 -> V_49 ) ;
F_28 ( & V_47 -> V_50 , & V_12 -> V_51 ) ;
F_29 ( & V_12 -> V_49 ) ;
F_30 ( V_12 -> V_52 , & V_12 -> V_53 ) ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 ,
struct V_46 * V_47 )
__acquires( &sta->tid_rx_lock
void F_32 ( struct V_11 * V_12 )
{
struct V_46 * V_54 , * V_55 ;
F_33 ( V_12 , L_4 , V_56 ) ;
F_27 ( & V_12 -> V_49 ) ;
F_34 (evt, t, &wil->back_rx_pending, list) {
F_35 ( & V_54 -> V_50 ) ;
F_19 ( V_54 ) ;
}
F_29 ( & V_12 -> V_49 ) ;
}
static struct V_57 * F_36 ( struct V_11 * V_12 )
{
struct V_57 * V_58 = NULL ;
F_27 ( & V_12 -> V_49 ) ;
if ( ! F_37 ( & V_12 -> V_51 ) ) {
V_58 = V_12 -> V_51 . V_59 ;
F_35 ( V_58 ) ;
}
F_29 ( & V_12 -> V_49 ) ;
return V_58 ;
}
void F_38 ( struct V_60 * V_61 )
{
struct V_11 * V_12 = F_39 ( V_61 , struct V_11 ,
V_53 ) ;
struct V_46 * V_54 ;
struct V_57 * V_62 ;
while ( ( V_62 = F_36 ( V_12 ) ) != NULL ) {
V_54 = F_40 ( V_62 , struct V_46 , V_50 ) ;
F_31 ( V_12 , V_54 ) ;
F_19 ( V_54 ) ;
}
}
static void F_41 ( struct V_11 * V_12 ,
struct V_63 * V_47 )
{
struct V_64 * V_65 = & V_12 -> V_64 [ V_47 -> V_66 ] ;
int V_67 ;
if ( V_65 -> V_68 ) {
F_33 ( V_12 , L_5 ,
V_47 -> V_66 ) ;
return;
}
if ( V_65 -> V_69 ) {
F_33 ( V_12 ,
L_6 ,
V_47 -> V_66 , V_65 -> V_69 ) ;
return;
}
V_65 -> V_68 = true ;
V_67 = F_42 ( V_12 , V_47 -> V_66 , V_47 -> V_69 , V_47 -> V_70 ) ;
if ( V_67 )
V_65 -> V_68 = false ;
}
static struct V_57 * F_43 ( struct V_11 * V_12 )
{
struct V_57 * V_58 = NULL ;
F_27 ( & V_12 -> V_71 ) ;
if ( ! F_37 ( & V_12 -> V_72 ) ) {
V_58 = V_12 -> V_72 . V_59 ;
F_35 ( V_58 ) ;
}
F_29 ( & V_12 -> V_71 ) ;
return V_58 ;
}
void F_44 ( struct V_60 * V_61 )
{
struct V_11 * V_12 = F_39 ( V_61 , struct V_11 ,
V_73 ) ;
struct V_63 * V_54 ;
struct V_57 * V_62 ;
while ( ( V_62 = F_43 ( V_12 ) ) != NULL ) {
V_54 = F_40 ( V_62 , struct V_63 , V_50 ) ;
F_41 ( V_12 , V_54 ) ;
F_19 ( V_54 ) ;
}
}
void F_45 ( struct V_11 * V_12 )
{
struct V_63 * V_54 , * V_55 ;
F_33 ( V_12 , L_4 , V_56 ) ;
F_27 ( & V_12 -> V_71 ) ;
F_34 (evt, t, &wil->back_tx_pending, list) {
F_35 ( & V_54 -> V_50 ) ;
F_19 ( V_54 ) ;
}
F_29 ( & V_12 -> V_71 ) ;
}
int F_46 ( struct V_11 * V_12 , T_2 V_66 , T_1 V_74 )
{
struct V_63 * V_47 = F_17 ( sizeof( * V_47 ) , V_31 ) ;
if ( ! V_47 )
return - V_48 ;
V_47 -> V_66 = V_66 ;
V_47 -> V_69 = F_22 ( V_12 , V_74 ) ;
V_47 -> V_70 = 0 ;
F_27 ( & V_12 -> V_71 ) ;
F_28 ( & V_47 -> V_50 , & V_12 -> V_72 ) ;
F_29 ( & V_12 -> V_71 ) ;
F_30 ( V_12 -> V_52 , & V_12 -> V_73 ) ;
return 0 ;
}
