static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 ,
unsigned int V_8 ,
struct V_9 * V_10 )
{
const struct V_11 * V_12 ;
struct V_11 V_13 ;
V_12 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
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
static int F_5 ( struct V_21 * V_22 ,
const struct V_9 * V_10 )
{
return F_6 ( V_22 , L_1 ,
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
static int F_15 ( struct V_2 * V_2 , struct V_24 * V_36 , struct V_6 * V_7 ,
unsigned int V_8 , enum V_25 * V_26 ,
T_1 V_27 ,
unsigned int V_28 )
{
unsigned int V_37 = V_7 -> V_38 - V_8 ;
const struct V_11 * V_39 ;
struct V_11 V_13 ;
V_39 = F_3 ( V_7 , V_8 , sizeof( V_13 ) , & V_13 ) ;
if ( V_39 == NULL ) {
if ( F_16 ( V_2 , V_40 ) )
F_17 ( V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_2 ) ;
return - V_35 ;
}
if ( F_7 ( V_39 -> V_38 ) > V_37 || F_7 ( V_39 -> V_38 ) < sizeof( * V_39 ) ) {
if ( F_16 ( V_2 , V_40 ) )
F_17 ( V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_3 ) ;
return - V_35 ;
}
if ( ! V_39 -> V_41 )
return V_35 ;
if ( V_2 -> V_3 . V_42 && V_28 == V_43 &&
F_18 ( V_7 , V_28 , V_8 , V_40 , V_27 ) ) {
if ( F_16 ( V_2 , V_40 ) )
F_17 ( V_27 , 0 , V_7 , NULL , NULL , NULL ,
L_4 ) ;
return - V_35 ;
}
return V_35 ;
}
static int F_19 ( struct V_44 * V_45 [] ,
struct V_2 * V_2 , void * V_46 )
{
unsigned int * V_23 = V_46 ;
struct V_1 * V_47 = F_1 ( V_2 ) ;
V_23 [ V_34 ] = V_47 -> V_23 [ V_34 ] ;
V_23 [ V_31 ] = V_47 -> V_23 [ V_31 ] ;
if ( V_45 [ V_48 ] ) {
V_23 [ V_34 ] =
F_20 ( F_21 ( V_45 [ V_48 ] ) ) * V_49 ;
}
if ( V_45 [ V_50 ] ) {
V_23 [ V_31 ] =
F_20 ( F_21 ( V_45 [ V_50 ] ) ) * V_49 ;
}
return 0 ;
}
static int
F_22 ( struct V_6 * V_7 , const void * V_46 )
{
const unsigned int * V_23 = V_46 ;
if ( F_23 ( V_7 , V_48 ,
F_24 ( V_23 [ V_34 ] / V_49 ) ) ||
F_23 ( V_7 , V_50 ,
F_24 ( V_23 [ V_31 ] / V_49 ) ) )
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
V_54 -> V_55 [ 0 ] . V_46 = & V_47 -> V_23 [ V_34 ] ;
V_54 -> V_55 [ 1 ] . V_46 = & V_47 -> V_23 [ V_31 ] ;
#endif
return 0 ;
}
static int F_28 ( struct V_53 * V_54 ,
struct V_1 * V_47 )
{
#ifdef F_26
#ifdef F_29
V_54 -> V_59 = F_27 ( V_60 ,
sizeof( V_60 ) ,
V_57 ) ;
if ( ! V_54 -> V_59 )
return - V_58 ;
V_54 -> V_59 [ 0 ] . V_46 = & V_47 -> V_23 [ V_34 ] ;
V_54 -> V_59 [ 1 ] . V_46 = & V_47 -> V_23 [ V_31 ] ;
#endif
#endif
return 0 ;
}
static int F_30 ( struct V_2 * V_2 , T_2 V_61 )
{
int V_62 ;
struct V_1 * V_47 = F_1 ( V_2 ) ;
struct V_53 * V_54 = & V_47 -> V_54 ;
if ( ! V_54 -> V_63 ) {
int V_64 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ )
V_47 -> V_23 [ V_64 ] = V_66 [ V_64 ] ;
}
if ( V_61 == V_67 ) {
V_62 = F_28 ( V_54 , V_47 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_25 ( V_54 , V_47 ) ;
if ( V_62 < 0 )
F_31 ( V_54 ) ;
} else
V_62 = F_25 ( V_54 , V_47 ) ;
return V_62 ;
}
static struct V_53 * F_32 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_54 ;
}
