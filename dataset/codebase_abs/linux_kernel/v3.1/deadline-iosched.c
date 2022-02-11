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
T_1 V_25 = V_21 -> V_26 + F_16 ( V_21 ) ;
V_22 = F_17 ( & V_3 -> V_6 [ F_18 ( V_21 ) ] , V_25 ) ;
if ( V_22 ) {
F_19 ( V_25 != F_20 ( V_22 ) ) ;
if ( F_21 ( V_22 , V_21 ) ) {
V_23 = V_27 ;
goto V_28;
}
}
}
return V_29 ;
V_28:
* V_20 = V_22 ;
return V_23 ;
}
static void F_22 ( struct V_12 * V_13 ,
struct V_4 * V_20 , int type )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
if ( type == V_27 ) {
F_9 ( F_1 ( V_3 , V_20 ) , V_20 ) ;
F_6 ( V_3 , V_20 ) ;
}
}
static void
F_23 ( struct V_12 * V_13 , struct V_4 * V_20 ,
struct V_4 * V_30 )
{
if ( ! F_24 ( & V_20 -> V_18 ) && ! F_24 ( & V_30 -> V_18 ) ) {
if ( F_25 ( F_26 ( V_30 ) , F_26 ( V_20 ) ) ) {
F_27 ( & V_20 -> V_18 , & V_30 -> V_18 ) ;
F_11 ( V_20 , F_26 ( V_30 ) ) ;
}
}
F_13 ( V_13 , V_30 ) ;
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
V_3 -> V_11 [ V_31 ] = NULL ;
V_3 -> V_11 [ V_32 ] = NULL ;
V_3 -> V_11 [ V_10 ] = F_3 ( V_5 ) ;
V_3 -> V_33 = F_31 ( V_5 ) ;
F_28 ( V_3 , V_5 ) ;
}
static inline int F_32 ( struct V_2 * V_3 , int V_34 )
{
struct V_4 * V_5 = F_33 ( V_3 -> V_19 [ V_34 ] . V_30 ) ;
if ( F_34 ( V_16 , F_26 ( V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_35 ( struct V_12 * V_13 , int V_35 )
{
struct V_2 * V_3 = V_13 -> V_14 -> V_15 ;
const int V_36 = ! F_24 ( & V_3 -> V_19 [ V_31 ] ) ;
const int V_37 = ! F_24 ( & V_3 -> V_19 [ V_32 ] ) ;
struct V_4 * V_5 ;
int V_10 ;
if ( V_3 -> V_11 [ V_32 ] )
V_5 = V_3 -> V_11 [ V_32 ] ;
else
V_5 = V_3 -> V_11 [ V_31 ] ;
if ( V_5 && V_3 -> V_38 < V_3 -> V_39 )
goto V_40;
if ( V_36 ) {
F_19 ( F_36 ( & V_3 -> V_6 [ V_31 ] ) ) ;
if ( V_37 && ( V_3 -> V_41 ++ >= V_3 -> V_42 ) )
goto V_43;
V_10 = V_31 ;
goto V_44;
}
if ( V_37 ) {
V_43:
F_19 ( F_36 ( & V_3 -> V_6 [ V_32 ] ) ) ;
V_3 -> V_41 = 0 ;
V_10 = V_32 ;
goto V_44;
}
return 0 ;
V_44:
if ( F_32 ( V_3 , V_10 ) || ! V_3 -> V_11 [ V_10 ] ) {
V_5 = F_33 ( V_3 -> V_19 [ V_10 ] . V_30 ) ;
} else {
V_5 = V_3 -> V_11 [ V_10 ] ;
}
V_3 -> V_38 = 0 ;
V_40:
V_3 -> V_38 ++ ;
F_30 ( V_3 , V_5 ) ;
return 1 ;
}
static void F_37 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = V_46 -> V_15 ;
F_19 ( ! F_24 ( & V_3 -> V_19 [ V_31 ] ) ) ;
F_19 ( ! F_24 ( & V_3 -> V_19 [ V_32 ] ) ) ;
F_38 ( V_3 ) ;
}
static void * F_39 ( struct V_12 * V_13 )
{
struct V_2 * V_3 ;
V_3 = F_40 ( sizeof( * V_3 ) , V_47 | V_48 , V_13 -> V_8 ) ;
if ( ! V_3 )
return NULL ;
F_41 ( & V_3 -> V_19 [ V_31 ] ) ;
F_41 ( & V_3 -> V_19 [ V_32 ] ) ;
V_3 -> V_6 [ V_31 ] = V_49 ;
V_3 -> V_6 [ V_32 ] = V_49 ;
V_3 -> V_17 [ V_31 ] = V_50 ;
V_3 -> V_17 [ V_32 ] = V_51 ;
V_3 -> V_42 = V_42 ;
V_3 -> V_24 = 1 ;
V_3 -> V_39 = V_39 ;
return V_3 ;
}
static T_2
F_42 ( int V_52 , char * V_53 )
{
return sprintf ( V_53 , L_1 , V_52 ) ;
}
static T_2
F_43 ( int * V_52 , const char * V_53 , T_3 V_54 )
{
char * V_55 = ( char * ) V_53 ;
* V_52 = F_44 ( V_55 , & V_55 , 10 ) ;
return V_54 ;
}
static int T_4 F_45 ( void )
{
F_46 ( & V_56 ) ;
return 0 ;
}
static void T_5 F_47 ( void )
{
F_48 ( & V_56 ) ;
}
