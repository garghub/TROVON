static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 ,
unsigned int V_8 ,
struct V_2 * V_2 ,
struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_12 = F_3 ( V_7 , V_8 , 4 , & V_13 ) ;
if ( V_12 == NULL )
return false ;
V_10 -> V_14 . V_15 . V_5 . V_16 = V_12 -> V_17 ;
V_10 -> V_18 . V_15 . V_5 . V_16 = V_12 -> V_19 ;
return true ;
}
static bool F_4 ( struct V_9 * V_10 ,
const struct V_9 * V_20 )
{
V_10 -> V_14 . V_15 . V_5 . V_16 = V_20 -> V_18 . V_15 . V_5 . V_16 ;
V_10 -> V_18 . V_15 . V_5 . V_16 = V_20 -> V_14 . V_15 . V_5 . V_16 ;
return true ;
}
static void F_5 ( struct V_21 * V_22 ,
const struct V_9 * V_10 )
{
F_6 ( V_22 , L_1 ,
F_7 ( V_10 -> V_14 . V_15 . V_5 . V_16 ) ,
F_7 ( V_10 -> V_18 . V_15 . V_5 . V_16 ) ) ;
}
static unsigned int * F_8 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_23 ;
}
static int F_9 ( struct V_24 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_25 V_26 ,
T_1 V_27 ,
unsigned int V_28 ,
unsigned int * V_23 )
{
if ( F_10 ( V_29 , & V_3 -> V_30 ) ) {
F_11 ( V_3 , V_26 , V_7 ,
V_23 [ V_31 ] ) ;
if ( ! F_12 ( V_32 , & V_3 -> V_30 ) )
F_13 ( V_33 , V_3 ) ;
} else {
F_11 ( V_3 , V_26 , V_7 ,
V_23 [ V_34 ] ) ;
}
return V_35 ;
}
static bool F_14 ( struct V_24 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_23 )
{
return true ;
}
static int F_15 ( struct V_2 * V_2 , struct V_24 * V_36 ,
struct V_6 * V_7 ,
unsigned int V_8 ,
T_2 V_27 , unsigned int V_28 )
{
unsigned int V_37 = V_7 -> V_38 - V_8 ;
const struct V_11 * V_39 ;
struct V_11 V_13 ;
unsigned int V_40 ;
V_39 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( ! V_39 ) {
if ( F_16 ( V_2 , V_41 ) )
F_17 ( V_2 , V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_2 ) ;
return - V_35 ;
}
V_40 = F_7 ( V_39 -> V_38 ) ;
if ( V_40 == 0 ) {
V_40 = V_37 ;
} else if ( V_40 < sizeof( * V_39 ) || V_40 > V_37 ) {
if ( F_16 ( V_2 , V_41 ) )
F_17 ( V_2 , V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_3 ) ;
return - V_35 ;
}
if ( ! V_39 -> V_42 ) {
if ( F_16 ( V_2 , V_41 ) )
F_17 ( V_2 , V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_4 ) ;
return - V_35 ;
}
if ( V_2 -> V_3 . V_43 && V_28 == V_44 &&
F_18 ( V_7 , V_28 , V_8 , V_40 , V_45 ,
V_27 ) ) {
if ( F_16 ( V_2 , V_41 ) )
F_17 ( V_2 , V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_5 ) ;
return - V_35 ;
}
return V_35 ;
}
static int F_19 ( struct V_2 * V_2 , struct V_24 * V_36 , struct V_6 * V_7 ,
unsigned int V_8 ,
T_1 V_27 ,
unsigned int V_28 )
{
unsigned int V_37 = V_7 -> V_38 - V_8 ;
const struct V_11 * V_39 ;
struct V_11 V_13 ;
V_39 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( V_39 == NULL ) {
if ( F_16 ( V_2 , V_45 ) )
F_17 ( V_2 , V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_6 ) ;
return - V_35 ;
}
if ( F_7 ( V_39 -> V_38 ) > V_37 || F_7 ( V_39 -> V_38 ) < sizeof( * V_39 ) ) {
if ( F_16 ( V_2 , V_45 ) )
F_17 ( V_2 , V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_7 ) ;
return - V_35 ;
}
if ( ! V_39 -> V_42 )
return V_35 ;
if ( V_2 -> V_3 . V_43 && V_28 == V_44 &&
F_20 ( V_7 , V_28 , V_8 , V_45 , V_27 ) ) {
if ( F_16 ( V_2 , V_45 ) )
F_17 ( V_2 , V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_8 ) ;
return - V_35 ;
}
return V_35 ;
}
static int F_21 ( struct V_46 * V_47 [] ,
struct V_2 * V_2 , void * V_48 )
{
unsigned int * V_23 = V_48 ;
struct V_1 * V_49 = F_1 ( V_2 ) ;
V_23 [ V_34 ] = V_49 -> V_23 [ V_34 ] ;
V_23 [ V_31 ] = V_49 -> V_23 [ V_31 ] ;
if ( V_47 [ V_50 ] ) {
V_23 [ V_34 ] =
F_22 ( F_23 ( V_47 [ V_50 ] ) ) * V_51 ;
}
if ( V_47 [ V_52 ] ) {
V_23 [ V_31 ] =
F_22 ( F_23 ( V_47 [ V_52 ] ) ) * V_51 ;
}
return 0 ;
}
static int
F_24 ( struct V_6 * V_7 , const void * V_48 )
{
const unsigned int * V_23 = V_48 ;
if ( F_25 ( V_7 , V_50 ,
F_26 ( V_23 [ V_34 ] / V_51 ) ) ||
F_25 ( V_7 , V_52 ,
F_26 ( V_23 [ V_31 ] / V_51 ) ) )
goto V_53;
return 0 ;
V_53:
return - V_54 ;
}
static int F_27 ( struct V_55 * V_56 ,
struct V_1 * V_49 )
{
#ifdef F_28
if ( V_56 -> V_57 )
return 0 ;
V_56 -> V_57 = F_29 ( V_58 ,
sizeof( V_58 ) ,
V_59 ) ;
if ( ! V_56 -> V_57 )
return - V_60 ;
V_56 -> V_57 [ 0 ] . V_48 = & V_49 -> V_23 [ V_34 ] ;
V_56 -> V_57 [ 1 ] . V_48 = & V_49 -> V_23 [ V_31 ] ;
#endif
return 0 ;
}
static int F_30 ( struct V_2 * V_2 , T_3 V_61 )
{
struct V_1 * V_49 = F_1 ( V_2 ) ;
struct V_55 * V_56 = & V_49 -> V_56 ;
if ( ! V_56 -> V_62 ) {
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ )
V_49 -> V_23 [ V_63 ] = V_65 [ V_63 ] ;
}
return F_27 ( V_56 , V_49 ) ;
}
static struct V_55 * F_31 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_56 ;
}
