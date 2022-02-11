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
static unsigned int * F_5 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_21 ;
}
static int F_6 ( struct V_22 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_23 V_24 ,
T_1 V_25 ,
unsigned int * V_21 )
{
if ( F_7 ( V_26 , & V_3 -> V_27 ) ) {
F_8 ( V_3 , V_24 , V_7 ,
V_21 [ V_28 ] ) ;
if ( ! F_9 ( V_29 , & V_3 -> V_27 ) )
F_10 ( V_30 , V_3 ) ;
} else {
F_8 ( V_3 , V_24 , V_7 ,
V_21 [ V_31 ] ) ;
}
return V_32 ;
}
static bool F_11 ( struct V_22 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_21 )
{
return true ;
}
static int F_12 ( struct V_2 * V_2 , struct V_22 * V_33 ,
struct V_6 * V_7 ,
unsigned int V_8 ,
T_2 V_25 , unsigned int V_34 )
{
unsigned int V_35 = V_7 -> V_36 - V_8 ;
const struct V_11 * V_37 ;
struct V_11 V_13 ;
unsigned int V_38 ;
V_37 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( ! V_37 ) {
if ( F_13 ( V_2 , V_39 ) )
F_14 ( V_2 , V_25 , 0 , V_7 , NULL , NULL , NULL ,
L_1 ) ;
return - V_32 ;
}
V_38 = F_15 ( V_37 -> V_36 ) ;
if ( V_38 == 0 ) {
V_38 = V_35 ;
} else if ( V_38 < sizeof( * V_37 ) || V_38 > V_35 ) {
if ( F_13 ( V_2 , V_39 ) )
F_14 ( V_2 , V_25 , 0 , V_7 , NULL , NULL , NULL ,
L_2 ) ;
return - V_32 ;
}
if ( ! V_37 -> V_40 ) {
if ( F_13 ( V_2 , V_39 ) )
F_14 ( V_2 , V_25 , 0 , V_7 , NULL , NULL , NULL ,
L_3 ) ;
return - V_32 ;
}
if ( V_2 -> V_3 . V_41 && V_34 == V_42 &&
F_16 ( V_7 , V_34 , V_8 , V_38 , V_43 ,
V_25 ) ) {
if ( F_13 ( V_2 , V_39 ) )
F_14 ( V_2 , V_25 , 0 , V_7 , NULL , NULL , NULL ,
L_4 ) ;
return - V_32 ;
}
return V_32 ;
}
static int F_17 ( struct V_2 * V_2 , struct V_22 * V_33 , struct V_6 * V_7 ,
unsigned int V_8 ,
T_1 V_25 ,
unsigned int V_34 )
{
unsigned int V_35 = V_7 -> V_36 - V_8 ;
const struct V_11 * V_37 ;
struct V_11 V_13 ;
V_37 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( V_37 == NULL ) {
if ( F_13 ( V_2 , V_43 ) )
F_14 ( V_2 , V_25 , 0 , V_7 , NULL , NULL , NULL ,
L_5 ) ;
return - V_32 ;
}
if ( F_15 ( V_37 -> V_36 ) > V_35 || F_15 ( V_37 -> V_36 ) < sizeof( * V_37 ) ) {
if ( F_13 ( V_2 , V_43 ) )
F_14 ( V_2 , V_25 , 0 , V_7 , NULL , NULL , NULL ,
L_6 ) ;
return - V_32 ;
}
if ( ! V_37 -> V_40 )
return V_32 ;
if ( V_2 -> V_3 . V_41 && V_34 == V_42 &&
F_18 ( V_7 , V_34 , V_8 , V_43 , V_25 ) ) {
if ( F_13 ( V_2 , V_43 ) )
F_14 ( V_2 , V_25 , 0 , V_7 , NULL , NULL , NULL ,
L_7 ) ;
return - V_32 ;
}
return V_32 ;
}
static int F_19 ( struct V_44 * V_45 [] ,
struct V_2 * V_2 , void * V_46 )
{
unsigned int * V_21 = V_46 ;
struct V_1 * V_47 = F_1 ( V_2 ) ;
V_21 [ V_31 ] = V_47 -> V_21 [ V_31 ] ;
V_21 [ V_28 ] = V_47 -> V_21 [ V_28 ] ;
if ( V_45 [ V_48 ] ) {
V_21 [ V_31 ] =
F_20 ( F_21 ( V_45 [ V_48 ] ) ) * V_49 ;
}
if ( V_45 [ V_50 ] ) {
V_21 [ V_28 ] =
F_20 ( F_21 ( V_45 [ V_50 ] ) ) * V_49 ;
}
return 0 ;
}
static int
F_22 ( struct V_6 * V_7 , const void * V_46 )
{
const unsigned int * V_21 = V_46 ;
if ( F_23 ( V_7 , V_48 ,
F_24 ( V_21 [ V_31 ] / V_49 ) ) ||
F_23 ( V_7 , V_50 ,
F_24 ( V_21 [ V_28 ] / V_49 ) ) )
goto V_51;
return 0 ;
V_51:
return - V_52 ;
}
static int F_25 ( struct V_53 * V_54 ,
struct V_1 * V_47 )
{
#ifdef F_26
if ( V_54 -> V_55 )
return 0 ;
V_54 -> V_55 = F_27 ( V_56 ,
sizeof( V_56 ) ,
V_57 ) ;
if ( ! V_54 -> V_55 )
return - V_58 ;
V_54 -> V_55 [ 0 ] . V_46 = & V_47 -> V_21 [ V_31 ] ;
V_54 -> V_55 [ 1 ] . V_46 = & V_47 -> V_21 [ V_28 ] ;
#endif
return 0 ;
}
static int F_28 ( struct V_2 * V_2 , T_3 V_59 )
{
struct V_1 * V_47 = F_1 ( V_2 ) ;
struct V_53 * V_54 = & V_47 -> V_54 ;
if ( ! V_54 -> V_60 ) {
int V_61 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ )
V_47 -> V_21 [ V_61 ] = V_63 [ V_61 ] ;
}
return F_25 ( V_54 , V_47 ) ;
}
static struct V_53 * F_29 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_54 ;
}
