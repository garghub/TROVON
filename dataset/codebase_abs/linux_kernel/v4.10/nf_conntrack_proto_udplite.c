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
V_10 -> V_14 . V_15 . V_16 . V_17 = V_12 -> V_18 ;
V_10 -> V_19 . V_15 . V_16 . V_17 = V_12 -> V_20 ;
return true ;
}
static bool F_4 ( struct V_9 * V_10 ,
const struct V_9 * V_21 )
{
V_10 -> V_14 . V_15 . V_16 . V_17 = V_21 -> V_19 . V_15 . V_16 . V_17 ;
V_10 -> V_19 . V_15 . V_16 . V_17 = V_21 -> V_14 . V_15 . V_16 . V_17 ;
return true ;
}
static void F_5 ( struct V_22 * V_23 ,
const struct V_9 * V_10 )
{
F_6 ( V_23 , L_1 ,
F_7 ( V_10 -> V_14 . V_15 . V_16 . V_17 ) ,
F_7 ( V_10 -> V_19 . V_15 . V_16 . V_17 ) ) ;
}
static unsigned int * F_8 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_24 ;
}
static int F_9 ( struct V_25 * V_3 ,
const struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_26 V_27 ,
T_1 V_28 ,
unsigned int V_29 ,
unsigned int * V_24 )
{
if ( F_10 ( V_30 , & V_3 -> V_31 ) ) {
F_11 ( V_3 , V_27 , V_7 ,
V_24 [ V_32 ] ) ;
if ( ! F_12 ( V_33 , & V_3 -> V_31 ) )
F_13 ( V_34 , V_3 ) ;
} else {
F_11 ( V_3 , V_27 , V_7 ,
V_24 [ V_35 ] ) ;
}
return V_36 ;
}
static bool F_14 ( struct V_25 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_24 )
{
return true ;
}
static int F_15 ( struct V_2 * V_2 , struct V_25 * V_37 ,
struct V_6 * V_7 ,
unsigned int V_8 ,
enum V_26 * V_27 ,
T_1 V_28 ,
unsigned int V_29 )
{
unsigned int V_38 = V_7 -> V_39 - V_8 ;
const struct V_11 * V_40 ;
struct V_11 V_13 ;
unsigned int V_41 ;
V_40 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( V_40 == NULL ) {
if ( F_16 ( V_2 , V_42 ) )
F_17 ( V_2 , V_28 , 0 , V_7 , NULL , NULL , NULL ,
L_2 ) ;
return - V_36 ;
}
V_41 = F_7 ( V_40 -> V_39 ) ;
if ( V_41 == 0 )
V_41 = V_38 ;
else if ( V_41 < sizeof( * V_40 ) || V_41 > V_38 ) {
if ( F_16 ( V_2 , V_42 ) )
F_17 ( V_2 , V_28 , 0 , V_7 , NULL , NULL , NULL ,
L_3 ) ;
return - V_36 ;
}
if ( ! V_40 -> V_43 ) {
if ( F_16 ( V_2 , V_42 ) )
F_17 ( V_2 , V_28 , 0 , V_7 , NULL , NULL , NULL ,
L_4 ) ;
return - V_36 ;
}
if ( V_2 -> V_3 . V_44 && V_29 == V_45 &&
F_18 ( V_7 , V_29 , V_8 , V_41 , V_46 ,
V_28 ) ) {
if ( F_16 ( V_2 , V_42 ) )
F_17 ( V_2 , V_28 , 0 , V_7 , NULL , NULL , NULL ,
L_5 ) ;
return - V_36 ;
}
return V_36 ;
}
static int F_19 ( struct V_47 * V_48 [] ,
struct V_2 * V_2 , void * V_49 )
{
unsigned int * V_24 = V_49 ;
struct V_1 * V_50 = F_1 ( V_2 ) ;
V_24 [ V_35 ] = V_50 -> V_24 [ V_35 ] ;
V_24 [ V_32 ] = V_50 -> V_24 [ V_32 ] ;
if ( V_48 [ V_51 ] ) {
V_24 [ V_35 ] =
F_20 ( F_21 ( V_48 [ V_51 ] ) ) * V_52 ;
}
if ( V_48 [ V_53 ] ) {
V_24 [ V_32 ] =
F_20 ( F_21 ( V_48 [ V_53 ] ) ) * V_52 ;
}
return 0 ;
}
static int
F_22 ( struct V_6 * V_7 , const void * V_49 )
{
const unsigned int * V_24 = V_49 ;
if ( F_23 ( V_7 , V_51 ,
F_24 ( V_24 [ V_35 ] / V_52 ) ) ||
F_23 ( V_7 , V_53 ,
F_24 ( V_24 [ V_32 ] / V_52 ) ) )
goto V_54;
return 0 ;
V_54:
return - V_55 ;
}
static int F_25 ( struct V_56 * V_57 ,
struct V_1 * V_50 )
{
#ifdef F_26
if ( V_57 -> V_58 )
return 0 ;
V_57 -> V_58 = F_27 ( V_59 ,
sizeof( V_59 ) ,
V_60 ) ;
if ( ! V_57 -> V_58 )
return - V_61 ;
V_57 -> V_58 [ 0 ] . V_49 = & V_50 -> V_24 [ V_35 ] ;
V_57 -> V_58 [ 1 ] . V_49 = & V_50 -> V_24 [ V_32 ] ;
#endif
return 0 ;
}
static int F_28 ( struct V_2 * V_2 , T_2 V_62 )
{
struct V_1 * V_50 = F_1 ( V_2 ) ;
struct V_56 * V_57 = & V_50 -> V_57 ;
if ( ! V_57 -> V_63 ) {
int V_64 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
V_50 -> V_24 [ V_64 ] = V_66 [ V_64 ] ;
}
return F_25 ( V_57 , V_50 ) ;
}
