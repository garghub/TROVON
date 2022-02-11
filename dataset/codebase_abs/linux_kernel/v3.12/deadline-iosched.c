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
F_11 ( V_5 , V_16 + V_3 -> V_17 [ V_10 ] ) ;
F_12 ( & V_5 -> V_18 , & V_3 -> V_19 [ V_10 ] ) ;
}
static void F_13 ( struct V_12 * V_13 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
F_14 ( V_5 ) ;
F_8 ( V_3 , V_5 ) ;
}
static int
F_15 ( struct V_12 * V_13 , struct V_4 * * V_20 , struct V_21 * V_21 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
struct V_4 * V_22 ;
int V_23 ;
if ( V_3 -> V_24 ) {
T_1 V_25 = F_16 ( V_21 ) ;
V_22 = F_17 ( & V_3 -> V_6 [ F_18 ( V_21 ) ] , V_25 ) ;
if ( V_22 ) {
F_19 ( V_25 != F_20 ( V_22 ) ) ;
if ( F_21 ( V_22 , V_21 ) ) {
V_23 = V_26 ;
goto V_27;
}
}
}
return V_28 ;
V_27:
* V_20 = V_22 ;
return V_23 ;
}
static void F_22 ( struct V_12 * V_13 ,
struct V_4 * V_20 , int type )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
if ( type == V_26 ) {
F_9 ( F_1 ( V_3 , V_20 ) , V_20 ) ;
F_6 ( V_3 , V_20 ) ;
}
}
static void
F_23 ( struct V_12 * V_13 , struct V_4 * V_20 ,
struct V_4 * V_29 )
{
if ( ! F_24 ( & V_20 -> V_18 ) && ! F_24 ( & V_29 -> V_18 ) ) {
if ( F_25 ( F_26 ( V_29 ) , F_26 ( V_20 ) ) ) {
F_27 ( & V_20 -> V_18 , & V_29 -> V_18 ) ;
F_11 ( V_20 , F_26 ( V_29 ) ) ;
}
}
F_13 ( V_13 , V_29 ) ;
}
static inline void
F_28 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_12 * V_13 = V_5 -> V_13 ;
F_13 ( V_13 , V_5 ) ;
F_29 ( V_13 , V_5 ) ;
}
static void
F_30 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
const int V_10 = F_2 ( V_5 ) ;
V_3 -> V_11 [ V_30 ] = NULL ;
V_3 -> V_11 [ V_31 ] = NULL ;
V_3 -> V_11 [ V_10 ] = F_3 ( V_5 ) ;
V_3 -> V_32 = F_31 ( V_5 ) ;
F_28 ( V_3 , V_5 ) ;
}
static inline int F_32 ( struct V_2 * V_3 , int V_33 )
{
struct V_4 * V_5 = F_33 ( V_3 -> V_19 [ V_33 ] . V_29 ) ;
if ( F_34 ( V_16 , F_26 ( V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 , int V_34 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
const int V_35 = ! F_24 ( & V_3 -> V_19 [ V_30 ] ) ;
const int V_36 = ! F_24 ( & V_3 -> V_19 [ V_31 ] ) ;
struct V_4 * V_5 ;
int V_10 ;
if ( V_3 -> V_11 [ V_31 ] )
V_5 = V_3 -> V_11 [ V_31 ] ;
else
V_5 = V_3 -> V_11 [ V_30 ] ;
if ( V_5 && V_3 -> V_37 < V_3 -> V_38 )
goto V_39;
if ( V_35 ) {
F_19 ( F_36 ( & V_3 -> V_6 [ V_30 ] ) ) ;
if ( V_36 && ( V_3 -> V_40 ++ >= V_3 -> V_41 ) )
goto V_42;
V_10 = V_30 ;
goto V_43;
}
if ( V_36 ) {
V_42:
F_19 ( F_36 ( & V_3 -> V_6 [ V_31 ] ) ) ;
V_3 -> V_40 = 0 ;
V_10 = V_31 ;
goto V_43;
}
return 0 ;
V_43:
if ( F_32 ( V_3 , V_10 ) || ! V_3 -> V_11 [ V_10 ] ) {
V_5 = F_33 ( V_3 -> V_19 [ V_10 ] . V_29 ) ;
} else {
V_5 = V_3 -> V_11 [ V_10 ] ;
}
V_3 -> V_37 = 0 ;
V_39:
V_3 -> V_37 ++ ;
F_30 ( V_3 , V_5 ) ;
return 1 ;
}
static void F_37 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = V_45 -> V_15 ;
F_19 ( ! F_24 ( & V_3 -> V_19 [ V_30 ] ) ) ;
F_19 ( ! F_24 ( & V_3 -> V_19 [ V_31 ] ) ) ;
F_38 ( V_3 ) ;
}
static int F_39 ( struct V_12 * V_13 , struct V_46 * V_45 )
{
struct V_2 * V_3 ;
struct V_44 * V_47 ;
V_47 = F_40 ( V_13 , V_45 ) ;
if ( ! V_47 )
return - V_48 ;
V_3 = F_41 ( sizeof( * V_3 ) , V_49 , V_13 -> V_8 ) ;
if ( ! V_3 ) {
F_42 ( & V_47 -> V_50 ) ;
return - V_48 ;
}
V_47 -> V_15 = V_3 ;
F_43 ( & V_3 -> V_19 [ V_30 ] ) ;
F_43 ( & V_3 -> V_19 [ V_31 ] ) ;
V_3 -> V_6 [ V_30 ] = V_51 ;
V_3 -> V_6 [ V_31 ] = V_51 ;
V_3 -> V_17 [ V_30 ] = V_52 ;
V_3 -> V_17 [ V_31 ] = V_53 ;
V_3 -> V_41 = V_41 ;
V_3 -> V_24 = 1 ;
V_3 -> V_38 = V_38 ;
F_44 ( V_13 -> V_54 ) ;
V_13 -> V_14 = V_47 ;
F_45 ( V_13 -> V_54 ) ;
return 0 ;
}
static T_2
F_46 ( int V_55 , char * V_56 )
{
return sprintf ( V_56 , L_1 , V_55 ) ;
}
static T_2
F_47 ( int * V_55 , const char * V_56 , T_3 V_57 )
{
char * V_58 = ( char * ) V_56 ;
* V_55 = F_48 ( V_58 , & V_58 , 10 ) ;
return V_57 ;
}
static int T_4 F_49 ( void )
{
return F_50 ( & V_59 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_59 ) ;
}
