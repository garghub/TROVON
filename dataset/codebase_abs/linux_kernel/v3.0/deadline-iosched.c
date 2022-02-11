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
struct V_4 * V_10 ;
while ( F_7 ( V_10 = F_8 ( V_9 , V_5 ) ) )
F_9 ( V_3 , V_10 ) ;
}
static inline void
F_10 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
const int V_11 = F_2 ( V_5 ) ;
if ( V_3 -> V_12 [ V_11 ] == V_5 )
V_3 -> V_12 [ V_11 ] = F_3 ( V_5 ) ;
F_11 ( F_1 ( V_3 , V_5 ) , V_5 ) ;
}
static void
F_12 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_14 -> V_15 -> V_16 ;
const int V_11 = F_2 ( V_5 ) ;
F_6 ( V_3 , V_5 ) ;
F_13 ( V_5 , V_17 + V_3 -> V_18 [ V_11 ] ) ;
F_14 ( & V_5 -> V_19 , & V_3 -> V_20 [ V_11 ] ) ;
}
static void F_15 ( struct V_13 * V_14 , struct V_4 * V_5 )
{
struct V_2 * V_3 = V_14 -> V_15 -> V_16 ;
F_16 ( V_5 ) ;
F_10 ( V_3 , V_5 ) ;
}
static int
F_17 ( struct V_13 * V_14 , struct V_4 * * V_21 , struct V_22 * V_22 )
{
struct V_2 * V_3 = V_14 -> V_15 -> V_16 ;
struct V_4 * V_23 ;
int V_24 ;
if ( V_3 -> V_25 ) {
T_1 V_26 = V_22 -> V_27 + F_18 ( V_22 ) ;
V_23 = F_19 ( & V_3 -> V_6 [ F_20 ( V_22 ) ] , V_26 ) ;
if ( V_23 ) {
F_21 ( V_26 != F_22 ( V_23 ) ) ;
if ( F_23 ( V_23 , V_22 ) ) {
V_24 = V_28 ;
goto V_29;
}
}
}
return V_30 ;
V_29:
* V_21 = V_23 ;
return V_24 ;
}
static void F_24 ( struct V_13 * V_14 ,
struct V_4 * V_21 , int type )
{
struct V_2 * V_3 = V_14 -> V_15 -> V_16 ;
if ( type == V_28 ) {
F_11 ( F_1 ( V_3 , V_21 ) , V_21 ) ;
F_6 ( V_3 , V_21 ) ;
}
}
static void
F_25 ( struct V_13 * V_14 , struct V_4 * V_21 ,
struct V_4 * V_31 )
{
if ( ! F_26 ( & V_21 -> V_19 ) && ! F_26 ( & V_31 -> V_19 ) ) {
if ( F_27 ( F_28 ( V_31 ) , F_28 ( V_21 ) ) ) {
F_29 ( & V_21 -> V_19 , & V_31 -> V_19 ) ;
F_13 ( V_21 , F_28 ( V_31 ) ) ;
}
}
F_15 ( V_14 , V_31 ) ;
}
static inline void
F_30 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_13 * V_14 = V_5 -> V_14 ;
F_15 ( V_14 , V_5 ) ;
F_31 ( V_14 , V_5 ) ;
}
static void
F_9 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
const int V_11 = F_2 ( V_5 ) ;
V_3 -> V_12 [ V_32 ] = NULL ;
V_3 -> V_12 [ V_33 ] = NULL ;
V_3 -> V_12 [ V_11 ] = F_3 ( V_5 ) ;
V_3 -> V_34 = F_32 ( V_5 ) ;
F_30 ( V_3 , V_5 ) ;
}
static inline int F_33 ( struct V_2 * V_3 , int V_35 )
{
struct V_4 * V_5 = F_34 ( V_3 -> V_20 [ V_35 ] . V_31 ) ;
if ( F_35 ( V_17 , F_28 ( V_5 ) ) )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_13 * V_14 , int V_36 )
{
struct V_2 * V_3 = V_14 -> V_15 -> V_16 ;
const int V_37 = ! F_26 ( & V_3 -> V_20 [ V_32 ] ) ;
const int V_38 = ! F_26 ( & V_3 -> V_20 [ V_33 ] ) ;
struct V_4 * V_5 ;
int V_11 ;
if ( V_3 -> V_12 [ V_33 ] )
V_5 = V_3 -> V_12 [ V_33 ] ;
else
V_5 = V_3 -> V_12 [ V_32 ] ;
if ( V_5 && V_3 -> V_39 < V_3 -> V_40 )
goto V_41;
if ( V_37 ) {
F_21 ( F_37 ( & V_3 -> V_6 [ V_32 ] ) ) ;
if ( V_38 && ( V_3 -> V_42 ++ >= V_3 -> V_43 ) )
goto V_44;
V_11 = V_32 ;
goto V_45;
}
if ( V_38 ) {
V_44:
F_21 ( F_37 ( & V_3 -> V_6 [ V_33 ] ) ) ;
V_3 -> V_42 = 0 ;
V_11 = V_33 ;
goto V_45;
}
return 0 ;
V_45:
if ( F_33 ( V_3 , V_11 ) || ! V_3 -> V_12 [ V_11 ] ) {
V_5 = F_34 ( V_3 -> V_20 [ V_11 ] . V_31 ) ;
} else {
V_5 = V_3 -> V_12 [ V_11 ] ;
}
V_3 -> V_39 = 0 ;
V_41:
V_3 -> V_39 ++ ;
F_9 ( V_3 , V_5 ) ;
return 1 ;
}
static void F_38 ( struct V_46 * V_47 )
{
struct V_2 * V_3 = V_47 -> V_16 ;
F_21 ( ! F_26 ( & V_3 -> V_20 [ V_32 ] ) ) ;
F_21 ( ! F_26 ( & V_3 -> V_20 [ V_33 ] ) ) ;
F_39 ( V_3 ) ;
}
static void * F_40 ( struct V_13 * V_14 )
{
struct V_2 * V_3 ;
V_3 = F_41 ( sizeof( * V_3 ) , V_48 | V_49 , V_14 -> V_8 ) ;
if ( ! V_3 )
return NULL ;
F_42 ( & V_3 -> V_20 [ V_32 ] ) ;
F_42 ( & V_3 -> V_20 [ V_33 ] ) ;
V_3 -> V_6 [ V_32 ] = V_50 ;
V_3 -> V_6 [ V_33 ] = V_50 ;
V_3 -> V_18 [ V_32 ] = V_51 ;
V_3 -> V_18 [ V_33 ] = V_52 ;
V_3 -> V_43 = V_43 ;
V_3 -> V_25 = 1 ;
V_3 -> V_40 = V_40 ;
return V_3 ;
}
static T_2
F_43 ( int V_53 , char * V_54 )
{
return sprintf ( V_54 , L_1 , V_53 ) ;
}
static T_2
F_44 ( int * V_53 , const char * V_54 , T_3 V_55 )
{
char * V_56 = ( char * ) V_54 ;
* V_53 = F_45 ( V_56 , & V_56 , 10 ) ;
return V_55 ;
}
static int T_4 F_46 ( void )
{
F_47 ( & V_57 ) ;
return 0 ;
}
static void T_5 F_48 ( void )
{
F_49 ( & V_57 ) ;
}
