static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static void F_1 ( struct V_1 * V_2 )
{
}
static void F_5 ( struct V_1 * V_2 )
{
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return ! ! V_2 -> V_6 [ 0 ] . V_7 ;
}
static inline struct V_8 *
F_8 ( struct V_9 * V_10 , int V_11 )
{
F_9 ( & V_10 -> V_12 ) ;
if ( V_10 -> V_7 && V_11 >= 0 )
return V_10 -> V_7 -> V_2 [ V_11 ] ;
return & V_10 -> V_2 ;
}
static inline struct V_8 *
F_10 ( struct V_9 * V_10 , void * V_13 )
{
struct V_14 * V_15 ;
if ( ! V_10 -> V_7 )
return & V_10 -> V_2 ;
V_15 = F_11 ( V_13 ) ;
if ( ! V_15 )
return & V_10 -> V_2 ;
return F_8 ( V_10 , F_12 ( V_15 ) ) ;
}
static inline bool F_7 ( struct V_1 * V_2 )
{
return false ;
}
static inline struct V_8 *
F_8 ( struct V_9 * V_10 , int V_11 )
{
return & V_10 -> V_2 ;
}
static inline struct V_8 *
F_10 ( struct V_9 * V_10 , void * V_13 )
{
return & V_10 -> V_2 ;
}
bool F_13 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 = F_14 ( F_15 ( V_17 ) ) ;
struct V_9 * V_10 = & V_2 -> V_6 [ V_18 ] ;
struct V_8 * V_19 ;
F_16 ( & V_10 -> V_12 ) ;
V_19 = F_10 ( V_10 , V_17 ) ;
if ( F_17 ( V_17 ) ) {
F_18 ( V_17 , & V_19 -> V_4 ) ;
V_19 -> V_20 ++ ;
F_19 ( & V_10 -> V_12 ) ;
return true ;
}
F_19 ( & V_10 -> V_12 ) ;
return false ;
}
bool F_20 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
int V_18 = F_14 ( F_15 ( V_17 ) ) ;
struct V_9 * V_10 = & V_2 -> V_6 [ V_18 ] ;
struct V_8 * V_19 ;
F_16 ( & V_10 -> V_12 ) ;
V_19 = F_10 ( V_10 , V_17 ) ;
if ( ! F_17 ( V_17 ) ) {
F_21 ( V_17 ) ;
V_19 -> V_20 -- ;
F_19 ( & V_10 -> V_12 ) ;
return true ;
}
F_19 ( & V_10 -> V_12 ) ;
return false ;
}
void F_22 ( struct V_8 * V_4 , struct V_16 * V_17 )
{
F_21 ( V_17 ) ;
V_4 -> V_20 -- ;
}
void F_23 ( struct V_8 * V_4 , struct V_16 * V_17 ,
struct V_16 * V_21 )
{
F_24 ( V_17 , V_21 ) ;
V_4 -> V_20 -- ;
}
static unsigned long F_25 ( struct V_1 * V_2 ,
int V_18 , int V_22 )
{
struct V_9 * V_10 = & V_2 -> V_6 [ V_18 ] ;
struct V_8 * V_19 ;
unsigned long V_23 ;
F_16 ( & V_10 -> V_12 ) ;
V_19 = F_8 ( V_10 , V_22 ) ;
V_23 = V_19 -> V_20 ;
F_19 ( & V_10 -> V_12 ) ;
return V_23 ;
}
unsigned long F_26 ( struct V_1 * V_2 ,
int V_18 , struct V_14 * V_15 )
{
return F_25 ( V_2 , V_18 , F_12 ( V_15 ) ) ;
}
unsigned long F_27 ( struct V_1 * V_2 , int V_18 )
{
long V_23 = 0 ;
int V_22 ;
V_23 += F_25 ( V_2 , V_18 , - 1 ) ;
if ( F_7 ( V_2 ) ) {
F_28 (memcg_idx)
V_23 += F_25 ( V_2 , V_18 , V_22 ) ;
}
return V_23 ;
}
static unsigned long
F_29 ( struct V_1 * V_2 , int V_18 , int V_22 ,
T_1 V_24 , void * V_25 ,
unsigned long * V_26 )
{
struct V_9 * V_10 = & V_2 -> V_6 [ V_18 ] ;
struct V_8 * V_19 ;
struct V_16 * V_17 , * V_27 ;
unsigned long V_28 = 0 ;
F_16 ( & V_10 -> V_12 ) ;
V_19 = F_8 ( V_10 , V_22 ) ;
V_29:
F_30 (item, n, &l->list) {
enum V_30 V_31 ;
if ( ! * V_26 )
break;
-- * V_26 ;
V_31 = V_24 ( V_17 , V_19 , & V_10 -> V_12 , V_25 ) ;
switch ( V_31 ) {
case V_32 :
F_31 ( & V_10 -> V_12 ) ;
case V_33 :
V_28 ++ ;
if ( V_31 == V_32 )
goto V_29;
break;
case V_34 :
F_32 ( V_17 , & V_19 -> V_4 ) ;
break;
case V_35 :
break;
case V_36 :
F_31 ( & V_10 -> V_12 ) ;
goto V_29;
default:
F_33 () ;
}
}
F_19 ( & V_10 -> V_12 ) ;
return V_28 ;
}
unsigned long
F_34 ( struct V_1 * V_2 , int V_18 , struct V_14 * V_15 ,
T_1 V_24 , void * V_25 ,
unsigned long * V_26 )
{
return F_29 ( V_2 , V_18 , F_12 ( V_15 ) ,
V_24 , V_25 , V_26 ) ;
}
unsigned long F_35 ( struct V_1 * V_2 , int V_18 ,
T_1 V_24 , void * V_25 ,
unsigned long * V_26 )
{
long V_28 = 0 ;
int V_22 ;
V_28 += F_29 ( V_2 , V_18 , - 1 , V_24 , V_25 ,
V_26 ) ;
if ( * V_26 > 0 && F_7 ( V_2 ) ) {
F_28 (memcg_idx) {
V_28 += F_29 ( V_2 , V_18 , V_22 ,
V_24 , V_25 , V_26 ) ;
if ( * V_26 <= 0 )
break;
}
}
return V_28 ;
}
static void F_36 ( struct V_8 * V_19 )
{
F_37 ( & V_19 -> V_4 ) ;
V_19 -> V_20 = 0 ;
}
static void F_38 ( struct V_37 * V_7 ,
int V_38 , int V_39 )
{
int V_40 ;
for ( V_40 = V_38 ; V_40 < V_39 ; V_40 ++ )
F_39 ( V_7 -> V_2 [ V_40 ] ) ;
}
static int F_40 ( struct V_37 * V_7 ,
int V_38 , int V_39 )
{
int V_40 ;
for ( V_40 = V_38 ; V_40 < V_39 ; V_40 ++ ) {
struct V_8 * V_19 ;
V_19 = F_41 ( sizeof( struct V_8 ) , V_41 ) ;
if ( ! V_19 )
goto V_42;
F_36 ( V_19 ) ;
V_7 -> V_2 [ V_40 ] = V_19 ;
}
return 0 ;
V_42:
F_38 ( V_7 , V_38 , V_40 - 1 ) ;
return - V_43 ;
}
static int F_42 ( struct V_9 * V_10 )
{
int V_44 = V_45 ;
V_10 -> V_7 = F_41 ( V_44 * sizeof( void * ) , V_41 ) ;
if ( ! V_10 -> V_7 )
return - V_43 ;
if ( F_40 ( V_10 -> V_7 , 0 , V_44 ) ) {
F_39 ( V_10 -> V_7 ) ;
return - V_43 ;
}
return 0 ;
}
static void F_43 ( struct V_9 * V_10 )
{
F_38 ( V_10 -> V_7 , 0 , V_45 ) ;
F_39 ( V_10 -> V_7 ) ;
}
static int F_44 ( struct V_9 * V_10 ,
int V_46 , int V_47 )
{
struct V_37 * V_48 , * V_49 ;
F_45 ( V_46 > V_47 ) ;
V_48 = V_10 -> V_7 ;
V_49 = F_41 ( V_47 * sizeof( void * ) , V_41 ) ;
if ( ! V_49 )
return - V_43 ;
if ( F_40 ( V_49 , V_46 , V_47 ) ) {
F_39 ( V_49 ) ;
return - V_43 ;
}
memcpy ( V_49 , V_48 , V_46 * sizeof( void * ) ) ;
F_46 ( & V_10 -> V_12 ) ;
V_10 -> V_7 = V_49 ;
F_47 ( & V_10 -> V_12 ) ;
F_39 ( V_48 ) ;
return 0 ;
}
static void F_48 ( struct V_9 * V_10 ,
int V_46 , int V_47 )
{
F_38 ( V_10 -> V_7 , V_46 , V_47 ) ;
}
static int F_49 ( struct V_1 * V_2 , bool V_50 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ ) {
if ( ! V_50 )
V_2 -> V_6 [ V_40 ] . V_7 = NULL ;
else if ( F_42 ( & V_2 -> V_6 [ V_40 ] ) )
goto V_42;
}
return 0 ;
V_42:
for ( V_40 = V_40 - 1 ; V_40 >= 0 ; V_40 -- )
F_43 ( & V_2 -> V_6 [ V_40 ] ) ;
return - V_43 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_40 ;
if ( ! F_7 ( V_2 ) )
return;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ )
F_43 ( & V_2 -> V_6 [ V_40 ] ) ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_46 , int V_47 )
{
int V_40 ;
if ( ! F_7 ( V_2 ) )
return 0 ;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ ) {
if ( F_44 ( & V_2 -> V_6 [ V_40 ] ,
V_46 , V_47 ) )
goto V_42;
}
return 0 ;
V_42:
for ( V_40 = V_40 - 1 ; V_40 >= 0 ; V_40 -- )
F_48 ( & V_2 -> V_6 [ V_40 ] ,
V_46 , V_47 ) ;
return - V_43 ;
}
static void F_52 ( struct V_1 * V_2 ,
int V_46 , int V_47 )
{
int V_40 ;
if ( ! F_7 ( V_2 ) )
return;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ )
F_48 ( & V_2 -> V_6 [ V_40 ] ,
V_46 , V_47 ) ;
}
int F_53 ( int V_47 )
{
int V_31 = 0 ;
struct V_1 * V_2 ;
int V_46 = V_45 ;
F_2 ( & V_3 ) ;
F_54 (lru, &list_lrus, list) {
V_31 = F_51 ( V_2 , V_46 , V_47 ) ;
if ( V_31 )
goto V_42;
}
V_52:
F_4 ( & V_3 ) ;
return V_31 ;
V_42:
F_55 (lru, &list_lrus, list)
F_52 ( V_2 , V_46 , V_47 ) ;
goto V_52;
}
static void F_56 ( struct V_9 * V_10 ,
int V_53 , int V_54 )
{
struct V_8 * V_55 , * V_56 ;
F_46 ( & V_10 -> V_12 ) ;
V_55 = F_8 ( V_10 , V_53 ) ;
V_56 = F_8 ( V_10 , V_54 ) ;
F_57 ( & V_55 -> V_4 , & V_56 -> V_4 ) ;
V_56 -> V_20 += V_55 -> V_20 ;
V_55 -> V_20 = 0 ;
F_47 ( & V_10 -> V_12 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
int V_53 , int V_54 )
{
int V_40 ;
if ( ! F_7 ( V_2 ) )
return;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ )
F_56 ( & V_2 -> V_6 [ V_40 ] , V_53 , V_54 ) ;
}
void F_59 ( int V_53 , int V_54 )
{
struct V_1 * V_2 ;
F_2 ( & V_3 ) ;
F_54 (lru, &list_lrus, list)
F_58 ( V_2 , V_53 , V_54 ) ;
F_4 ( & V_3 ) ;
}
static int F_49 ( struct V_1 * V_2 , bool V_50 )
{
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
}
int F_60 ( struct V_1 * V_2 , bool V_50 ,
struct V_57 * V_58 )
{
int V_40 ;
T_2 V_44 = sizeof( * V_2 -> V_6 ) * V_51 ;
int V_59 = - V_43 ;
F_61 () ;
V_2 -> V_6 = F_62 ( V_44 , V_41 ) ;
if ( ! V_2 -> V_6 )
goto V_52;
for ( V_40 = 0 ; V_40 < V_51 ; V_40 ++ ) {
F_63 ( & V_2 -> V_6 [ V_40 ] . V_12 ) ;
if ( V_58 )
F_64 ( & V_2 -> V_6 [ V_40 ] . V_12 , V_58 ) ;
F_36 ( & V_2 -> V_6 [ V_40 ] . V_2 ) ;
}
V_59 = F_49 ( V_2 , V_50 ) ;
if ( V_59 ) {
F_39 ( V_2 -> V_6 ) ;
goto V_52;
}
F_1 ( V_2 ) ;
V_52:
F_65 () ;
return V_59 ;
}
void F_66 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_6 )
return;
F_61 () ;
F_5 ( V_2 ) ;
F_50 ( V_2 ) ;
F_39 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
F_65 () ;
}
