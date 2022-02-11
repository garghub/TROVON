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
static void
F_10 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
const int V_10 = F_2 ( V_5 ) ;
F_6 ( V_3 , V_5 ) ;
V_5 -> V_16 = V_17 + V_3 -> V_18 [ V_10 ] ;
F_11 ( & V_5 -> V_19 , & V_3 -> V_20 [ V_10 ] ) ;
}
static void F_12 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
F_13 ( V_5 ) ;
F_8 ( V_3 , V_5 ) ;
}
static int
F_14 ( struct V_12 * V_13 , struct V_4 * * V_21 , struct V_22 * V_22 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
struct V_4 * V_23 ;
int V_24 ;
if ( V_3 -> V_25 ) {
T_1 V_26 = F_15 ( V_22 ) ;
V_23 = F_16 ( & V_3 -> V_6 [ F_17 ( V_22 ) ] , V_26 ) ;
if ( V_23 ) {
F_18 ( V_26 != F_19 ( V_23 ) ) ;
if ( F_20 ( V_23 , V_22 ) ) {
V_24 = V_27 ;
goto V_28;
}
}
}
return V_29 ;
V_28:
* V_21 = V_23 ;
return V_24 ;
}
static void F_21 ( struct V_12 * V_13 ,
struct V_4 * V_21 , int type )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
if ( type == V_27 ) {
F_9 ( F_1 ( V_3 , V_21 ) , V_21 ) ;
F_6 ( V_3 , V_21 ) ;
}
}
static void
F_22 ( struct V_12 * V_13 , struct V_4 * V_21 ,
struct V_4 * V_30 )
{
if ( ! F_23 ( & V_21 -> V_19 ) && ! F_23 ( & V_30 -> V_19 ) ) {
if ( F_24 ( V_30 -> V_16 , V_21 -> V_16 ) ) {
F_25 ( & V_21 -> V_19 , & V_30 -> V_19 ) ;
V_21 -> V_16 = V_30 -> V_16 ;
}
}
F_12 ( V_13 , V_30 ) ;
}
static inline void
F_26 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_12 * V_13 = V_5 -> V_13 ;
F_12 ( V_13 , V_5 ) ;
F_27 ( V_13 , V_5 ) ;
}
static void
F_28 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
const int V_10 = F_2 ( V_5 ) ;
V_3 -> V_11 [ V_31 ] = NULL ;
V_3 -> V_11 [ V_32 ] = NULL ;
V_3 -> V_11 [ V_10 ] = F_3 ( V_5 ) ;
V_3 -> V_33 = F_29 ( V_5 ) ;
F_26 ( V_3 , V_5 ) ;
}
static inline int F_30 ( struct V_2 * V_3 , int V_34 )
{
struct V_4 * V_5 = F_31 ( V_3 -> V_20 [ V_34 ] . V_30 ) ;
if ( F_32 ( V_17 , V_5 -> V_16 ) )
return 1 ;
return 0 ;
}
static int F_33 ( struct V_12 * V_13 , int V_35 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
const int V_36 = ! F_23 ( & V_3 -> V_20 [ V_31 ] ) ;
const int V_37 = ! F_23 ( & V_3 -> V_20 [ V_32 ] ) ;
struct V_4 * V_5 ;
int V_10 ;
if ( V_3 -> V_11 [ V_32 ] )
V_5 = V_3 -> V_11 [ V_32 ] ;
else
V_5 = V_3 -> V_11 [ V_31 ] ;
if ( V_5 && V_3 -> V_38 < V_3 -> V_39 )
goto V_40;
if ( V_36 ) {
F_18 ( F_34 ( & V_3 -> V_6 [ V_31 ] ) ) ;
if ( V_37 && ( V_3 -> V_41 ++ >= V_3 -> V_42 ) )
goto V_43;
V_10 = V_31 ;
goto V_44;
}
if ( V_37 ) {
V_43:
F_18 ( F_34 ( & V_3 -> V_6 [ V_32 ] ) ) ;
V_3 -> V_41 = 0 ;
V_10 = V_32 ;
goto V_44;
}
return 0 ;
V_44:
if ( F_30 ( V_3 , V_10 ) || ! V_3 -> V_11 [ V_10 ] ) {
V_5 = F_31 ( V_3 -> V_20 [ V_10 ] . V_30 ) ;
} else {
V_5 = V_3 -> V_11 [ V_10 ] ;
}
V_3 -> V_38 = 0 ;
V_40:
V_3 -> V_38 ++ ;
F_28 ( V_3 , V_5 ) ;
return 1 ;
}
static void F_35 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_15 ;
F_18 ( ! F_23 ( & V_3 -> V_20 [ V_31 ] ) ) ;
F_18 ( ! F_23 ( & V_3 -> V_20 [ V_32 ] ) ) ;
F_36 ( V_3 ) ;
}
static int F_37 ( struct V_12 * V_13 , struct V_47 * V_46 )
{
struct V_2 * V_3 ;
struct V_45 * V_48 ;
V_48 = F_38 ( V_13 , V_46 ) ;
if ( ! V_48 )
return - V_49 ;
V_3 = F_39 ( sizeof( * V_3 ) , V_50 , V_13 -> V_8 ) ;
if ( ! V_3 ) {
F_40 ( & V_48 -> V_51 ) ;
return - V_49 ;
}
V_48 -> V_15 = V_3 ;
F_41 ( & V_3 -> V_20 [ V_31 ] ) ;
F_41 ( & V_3 -> V_20 [ V_32 ] ) ;
V_3 -> V_6 [ V_31 ] = V_52 ;
V_3 -> V_6 [ V_32 ] = V_52 ;
V_3 -> V_18 [ V_31 ] = V_53 ;
V_3 -> V_18 [ V_32 ] = V_54 ;
V_3 -> V_42 = V_42 ;
V_3 -> V_25 = 1 ;
V_3 -> V_39 = V_39 ;
F_42 ( V_13 -> V_55 ) ;
V_13 -> V_14 = V_48 ;
F_43 ( V_13 -> V_55 ) ;
return 0 ;
}
static T_2
F_44 ( int V_56 , char * V_57 )
{
return sprintf ( V_57 , L_1 , V_56 ) ;
}
static T_2
F_45 ( int * V_56 , const char * V_57 , T_3 V_58 )
{
char * V_59 = ( char * ) V_57 ;
* V_56 = F_46 ( V_59 , & V_59 , 10 ) ;
return V_58 ;
}
static int T_4 F_47 ( void )
{
return F_48 ( & V_60 ) ;
}
static void T_5 F_49 ( void )
{
F_50 ( & V_60 ) ;
}
