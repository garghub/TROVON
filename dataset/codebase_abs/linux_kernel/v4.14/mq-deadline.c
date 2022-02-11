static inline struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
return & V_3 -> V_6 [ F_2 ( V_5 ) ] ;
}
static inline struct V_4 *
F_3 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = F_4 ( & V_5 -> V_7 ) ;
if ( V_8 )
return F_5 ( V_8 ) ;
return NULL ;
}
static void
F_6 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
F_7 ( V_9 , V_5 ) ;
}
static inline void
F_8 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
const int V_10 = F_2 ( V_5 ) ;
if ( V_3 -> V_11 [ V_10 ] == V_5 )
V_3 -> V_11 [ V_10 ] = F_3 ( V_5 ) ;
F_9 ( F_1 ( V_3 , V_5 ) , V_5 ) ;
}
static void F_10 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
F_11 ( & V_5 -> V_16 ) ;
if ( ! F_12 ( & V_5 -> V_7 ) )
F_8 ( V_3 , V_5 ) ;
F_13 ( V_13 , V_5 ) ;
if ( V_13 -> V_17 == V_5 )
V_13 -> V_17 = NULL ;
}
static void F_14 ( struct V_12 * V_13 , struct V_4 * V_18 ,
enum V_19 type )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
if ( type == V_20 ) {
F_9 ( F_1 ( V_3 , V_18 ) , V_18 ) ;
F_6 ( V_3 , V_18 ) ;
}
}
static void F_15 ( struct V_12 * V_13 , struct V_4 * V_18 ,
struct V_4 * V_21 )
{
if ( ! F_16 ( & V_18 -> V_16 ) && ! F_16 ( & V_21 -> V_16 ) ) {
if ( F_17 ( ( unsigned long ) V_21 -> V_22 ,
( unsigned long ) V_18 -> V_22 ) ) {
F_18 ( & V_18 -> V_16 , & V_21 -> V_16 ) ;
V_18 -> V_22 = V_21 -> V_22 ;
}
}
F_10 ( V_13 , V_21 ) ;
}
static void
F_19 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
const int V_10 = F_2 ( V_5 ) ;
V_3 -> V_11 [ V_23 ] = NULL ;
V_3 -> V_11 [ V_24 ] = NULL ;
V_3 -> V_11 [ V_10 ] = F_3 ( V_5 ) ;
F_10 ( V_5 -> V_13 , V_5 ) ;
}
static inline int F_20 ( struct V_2 * V_3 , int V_25 )
{
struct V_4 * V_5 = F_21 ( V_3 -> V_26 [ V_25 ] . V_21 ) ;
if ( F_22 ( V_27 , ( unsigned long ) V_5 -> V_22 ) )
return 1 ;
return 0 ;
}
static struct V_4 * F_23 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_30 -> V_14 -> V_15 ;
struct V_4 * V_5 ;
bool V_31 , V_32 ;
int V_10 ;
if ( ! F_16 ( & V_3 -> V_33 ) ) {
V_5 = F_24 ( & V_3 -> V_33 , struct V_4 , V_16 ) ;
F_11 ( & V_5 -> V_16 ) ;
goto V_34;
}
V_31 = ! F_16 ( & V_3 -> V_26 [ V_23 ] ) ;
V_32 = ! F_16 ( & V_3 -> V_26 [ V_24 ] ) ;
if ( V_3 -> V_11 [ V_24 ] )
V_5 = V_3 -> V_11 [ V_24 ] ;
else
V_5 = V_3 -> V_11 [ V_23 ] ;
if ( V_5 && V_3 -> V_35 < V_3 -> V_36 )
goto V_37;
if ( V_31 ) {
F_25 ( F_26 ( & V_3 -> V_6 [ V_23 ] ) ) ;
if ( V_32 && ( V_3 -> V_38 ++ >= V_3 -> V_39 ) )
goto V_40;
V_10 = V_23 ;
goto V_41;
}
if ( V_32 ) {
V_40:
F_25 ( F_26 ( & V_3 -> V_6 [ V_24 ] ) ) ;
V_3 -> V_38 = 0 ;
V_10 = V_24 ;
goto V_41;
}
return NULL ;
V_41:
if ( F_20 ( V_3 , V_10 ) || ! V_3 -> V_11 [ V_10 ] ) {
V_5 = F_21 ( V_3 -> V_26 [ V_10 ] . V_21 ) ;
} else {
V_5 = V_3 -> V_11 [ V_10 ] ;
}
V_3 -> V_35 = 0 ;
V_37:
V_3 -> V_35 ++ ;
F_19 ( V_3 , V_5 ) ;
V_34:
V_5 -> V_42 |= V_43 ;
return V_5 ;
}
static struct V_4 * F_27 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_30 -> V_14 -> V_15 ;
struct V_4 * V_5 ;
F_28 ( & V_3 -> V_44 ) ;
V_5 = F_23 ( V_29 ) ;
F_29 ( & V_3 -> V_44 ) ;
return V_5 ;
}
static void F_30 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_15 ;
F_25 ( ! F_16 ( & V_3 -> V_26 [ V_23 ] ) ) ;
F_25 ( ! F_16 ( & V_3 -> V_26 [ V_24 ] ) ) ;
F_31 ( V_3 ) ;
}
static int F_32 ( struct V_12 * V_13 , struct V_47 * V_46 )
{
struct V_2 * V_3 ;
struct V_45 * V_48 ;
V_48 = F_33 ( V_13 , V_46 ) ;
if ( ! V_48 )
return - V_49 ;
V_3 = F_34 ( sizeof( * V_3 ) , V_50 , V_13 -> V_8 ) ;
if ( ! V_3 ) {
F_35 ( & V_48 -> V_51 ) ;
return - V_49 ;
}
V_48 -> V_15 = V_3 ;
F_36 ( & V_3 -> V_26 [ V_23 ] ) ;
F_36 ( & V_3 -> V_26 [ V_24 ] ) ;
V_3 -> V_6 [ V_23 ] = V_52 ;
V_3 -> V_6 [ V_24 ] = V_52 ;
V_3 -> V_53 [ V_23 ] = V_54 ;
V_3 -> V_53 [ V_24 ] = V_55 ;
V_3 -> V_39 = V_39 ;
V_3 -> V_56 = 1 ;
V_3 -> V_36 = V_36 ;
F_37 ( & V_3 -> V_44 ) ;
F_36 ( & V_3 -> V_33 ) ;
V_13 -> V_14 = V_48 ;
return 0 ;
}
static int F_38 ( struct V_12 * V_13 , struct V_4 * * V_5 ,
struct V_57 * V_57 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
T_1 V_58 = F_39 ( V_57 ) ;
struct V_4 * V_59 ;
if ( ! V_3 -> V_56 )
return V_60 ;
V_59 = F_40 ( & V_3 -> V_6 [ F_41 ( V_57 ) ] , V_58 ) ;
if ( V_59 ) {
F_25 ( V_58 != F_42 ( V_59 ) ) ;
if ( F_43 ( V_59 , V_57 ) ) {
* V_5 = V_59 ;
return V_20 ;
}
}
return V_60 ;
}
static bool F_44 ( struct V_28 * V_29 , struct V_57 * V_57 )
{
struct V_12 * V_13 = V_29 -> V_30 ;
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
struct V_4 * free = NULL ;
bool V_61 ;
F_28 ( & V_3 -> V_44 ) ;
V_61 = F_45 ( V_13 , V_57 , & free ) ;
F_29 ( & V_3 -> V_44 ) ;
if ( free )
F_46 ( free ) ;
return V_61 ;
}
static void F_47 ( struct V_28 * V_29 , struct V_4 * V_5 ,
bool V_62 )
{
struct V_12 * V_13 = V_29 -> V_30 ;
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
const int V_10 = F_2 ( V_5 ) ;
if ( F_48 ( V_13 , V_5 ) )
return;
F_49 ( V_5 ) ;
if ( V_62 || F_50 ( V_5 ) ) {
if ( V_62 )
F_51 ( & V_5 -> V_16 , & V_3 -> V_33 ) ;
else
F_52 ( & V_5 -> V_16 , & V_3 -> V_33 ) ;
} else {
F_6 ( V_3 , V_5 ) ;
if ( F_53 ( V_5 ) ) {
F_54 ( V_13 , V_5 ) ;
if ( ! V_13 -> V_17 )
V_13 -> V_17 = V_5 ;
}
V_5 -> V_22 = V_27 + V_3 -> V_53 [ V_10 ] ;
F_52 ( & V_5 -> V_16 , & V_3 -> V_26 [ V_10 ] ) ;
}
}
static void F_55 ( struct V_28 * V_29 ,
struct V_63 * V_64 , bool V_62 )
{
struct V_12 * V_13 = V_29 -> V_30 ;
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
F_28 ( & V_3 -> V_44 ) ;
while ( ! F_16 ( V_64 ) ) {
struct V_4 * V_5 ;
V_5 = F_24 ( V_64 , struct V_4 , V_16 ) ;
F_11 ( & V_5 -> V_16 ) ;
F_47 ( V_29 , V_5 , V_62 ) ;
}
F_29 ( & V_3 -> V_44 ) ;
}
static bool F_56 ( struct V_28 * V_29 )
{
struct V_2 * V_3 = V_29 -> V_30 -> V_14 -> V_15 ;
return ! F_57 ( & V_3 -> V_33 ) ||
! F_57 ( & V_3 -> V_26 [ 0 ] ) ||
! F_57 ( & V_3 -> V_26 [ 1 ] ) ;
}
static T_2
F_58 ( int V_65 , char * V_66 )
{
return sprintf ( V_66 , L_1 , V_65 ) ;
}
static void
F_59 ( int * V_65 , const char * V_66 )
{
char * V_67 = ( char * ) V_66 ;
* V_65 = F_60 ( V_67 , & V_67 , 10 ) ;
}
static int F_61 ( void * V_68 , struct V_69 * V_70 )
{
struct V_12 * V_13 = V_68 ;
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
F_62 ( V_70 , L_2 , V_3 -> V_35 ) ;
return 0 ;
}
static int F_63 ( void * V_68 , struct V_69 * V_70 )
{
struct V_12 * V_13 = V_68 ;
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
F_62 ( V_70 , L_2 , V_3 -> V_38 ) ;
return 0 ;
}
static void * F_64 ( struct V_69 * V_70 , T_3 * V_71 )
__acquires( &dd->lock
static void * F_65 ( struct V_69 * V_70 , void * V_72 , T_3 * V_71 )
{
struct V_12 * V_13 = V_70 -> V_73 ;
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
return F_66 ( V_72 , & V_3 -> V_33 , V_71 ) ;
}
static void F_67 ( struct V_69 * V_70 , void * V_72 )
__releases( &dd->lock
static int T_4 F_68 ( void )
{
return F_69 ( & V_74 ) ;
}
static void T_5 F_70 ( void )
{
F_71 ( & V_74 ) ;
}
