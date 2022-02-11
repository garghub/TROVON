static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static bool F_3 ( const struct V_4 * V_5 ,
unsigned int V_6 ,
struct V_2 * V_2 ,
struct V_7 * V_8 )
{
const struct V_9 * V_10 ;
struct V_9 V_11 ;
V_10 = F_4 ( V_5 , V_6 , 4 , & V_11 ) ;
if ( V_10 == NULL )
return false ;
V_8 -> V_12 . V_13 . V_14 . V_15 = V_10 -> V_16 ;
V_8 -> V_17 . V_13 . V_14 . V_15 = V_10 -> V_18 ;
return true ;
}
static bool F_5 ( struct V_7 * V_8 ,
const struct V_7 * V_19 )
{
V_8 -> V_12 . V_13 . V_14 . V_15 = V_19 -> V_17 . V_13 . V_14 . V_15 ;
V_8 -> V_17 . V_13 . V_14 . V_15 = V_19 -> V_12 . V_13 . V_14 . V_15 ;
return true ;
}
static void F_6 ( struct V_20 * V_21 ,
const struct V_7 * V_8 )
{
F_7 ( V_21 , L_1 ,
F_8 ( V_8 -> V_12 . V_13 . V_14 . V_15 ) ,
F_8 ( V_8 -> V_17 . V_13 . V_14 . V_15 ) ) ;
}
static unsigned int * F_9 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_22 ;
}
static int F_10 ( struct V_23 * V_24 ,
const struct V_4 * V_5 ,
unsigned int V_6 ,
enum V_25 V_26 ,
T_1 V_27 ,
unsigned int V_28 ,
unsigned int * V_22 )
{
if ( F_11 ( V_29 , & V_24 -> V_30 ) ) {
F_12 ( V_24 , V_26 , V_5 ,
V_22 [ V_31 ] ) ;
if ( ! F_13 ( V_32 , & V_24 -> V_30 ) )
F_14 ( V_33 , V_24 ) ;
} else {
F_12 ( V_24 , V_26 , V_5 ,
V_22 [ V_34 ] ) ;
}
return V_35 ;
}
static bool F_15 ( struct V_23 * V_24 , const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int * V_22 )
{
return true ;
}
static int F_16 ( struct V_2 * V_2 , struct V_23 * V_36 ,
struct V_4 * V_5 ,
unsigned int V_6 ,
enum V_25 * V_26 ,
T_1 V_27 ,
unsigned int V_28 )
{
unsigned int V_37 = V_5 -> V_38 - V_6 ;
const struct V_9 * V_39 ;
struct V_9 V_11 ;
unsigned int V_40 ;
V_39 = F_4 ( V_5 , V_6 , sizeof( V_11 ) , & V_11 ) ;
if ( V_39 == NULL ) {
if ( F_17 ( V_2 , V_41 ) )
F_18 ( V_2 , V_27 , 0 , V_5 , NULL , NULL , NULL ,
L_2 ) ;
return - V_35 ;
}
V_40 = F_8 ( V_39 -> V_38 ) ;
if ( V_40 == 0 )
V_40 = V_37 ;
else if ( V_40 < sizeof( * V_39 ) || V_40 > V_37 ) {
if ( F_17 ( V_2 , V_41 ) )
F_18 ( V_2 , V_27 , 0 , V_5 , NULL , NULL , NULL ,
L_3 ) ;
return - V_35 ;
}
if ( ! V_39 -> V_42 ) {
if ( F_17 ( V_2 , V_41 ) )
F_18 ( V_2 , V_27 , 0 , V_5 , NULL , NULL , NULL ,
L_4 ) ;
return - V_35 ;
}
if ( V_2 -> V_24 . V_43 && V_28 == V_44 &&
F_19 ( V_5 , V_28 , V_6 , V_40 , V_45 ,
V_27 ) ) {
if ( F_17 ( V_2 , V_41 ) )
F_18 ( V_2 , V_27 , 0 , V_5 , NULL , NULL , NULL ,
L_5 ) ;
return - V_35 ;
}
return V_35 ;
}
static int F_20 ( struct V_46 * V_47 [] ,
struct V_2 * V_2 , void * V_48 )
{
unsigned int * V_22 = V_48 ;
struct V_1 * V_49 = F_1 ( V_2 ) ;
V_22 [ V_34 ] = V_49 -> V_22 [ V_34 ] ;
V_22 [ V_31 ] = V_49 -> V_22 [ V_31 ] ;
if ( V_47 [ V_50 ] ) {
V_22 [ V_34 ] =
F_21 ( F_22 ( V_47 [ V_50 ] ) ) * V_51 ;
}
if ( V_47 [ V_52 ] ) {
V_22 [ V_31 ] =
F_21 ( F_22 ( V_47 [ V_52 ] ) ) * V_51 ;
}
return 0 ;
}
static int
F_23 ( struct V_4 * V_5 , const void * V_48 )
{
const unsigned int * V_22 = V_48 ;
if ( F_24 ( V_5 , V_50 ,
F_25 ( V_22 [ V_34 ] / V_51 ) ) ||
F_24 ( V_5 , V_52 ,
F_25 ( V_22 [ V_31 ] / V_51 ) ) )
goto V_53;
return 0 ;
V_53:
return - V_54 ;
}
static int F_26 ( struct V_55 * V_56 ,
struct V_1 * V_49 )
{
#ifdef F_27
if ( V_56 -> V_57 )
return 0 ;
V_56 -> V_57 = F_28 ( V_58 ,
sizeof( V_58 ) ,
V_59 ) ;
if ( ! V_56 -> V_57 )
return - V_60 ;
V_56 -> V_57 [ 0 ] . V_48 = & V_49 -> V_22 [ V_34 ] ;
V_56 -> V_57 [ 1 ] . V_48 = & V_49 -> V_22 [ V_31 ] ;
#endif
return 0 ;
}
static int F_29 ( struct V_2 * V_2 , T_2 V_61 )
{
struct V_1 * V_49 = F_1 ( V_2 ) ;
struct V_55 * V_56 = & V_49 -> V_56 ;
if ( ! V_56 -> V_62 ) {
int V_63 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ )
V_49 -> V_22 [ V_63 ] = V_65 [ V_63 ] ;
}
return F_26 ( V_56 , V_49 ) ;
}
static int F_30 ( struct V_2 * V_2 )
{
int V_66 = 0 ;
V_66 = F_31 ( V_2 , & V_67 ) ;
if ( V_66 < 0 ) {
F_32 ( L_6 ) ;
goto V_68;
}
V_66 = F_31 ( V_2 , & V_69 ) ;
if ( V_66 < 0 ) {
F_32 ( L_7 ) ;
goto V_70;
}
return 0 ;
V_70:
F_33 ( V_2 , & V_67 ) ;
V_68:
return V_66 ;
}
static void F_34 ( struct V_2 * V_2 )
{
F_33 ( V_2 , & V_69 ) ;
F_33 ( V_2 , & V_67 ) ;
}
static int T_3 F_35 ( void )
{
int V_66 ;
V_66 = F_36 ( & V_71 ) ;
if ( V_66 < 0 )
goto V_72;
V_66 = F_37 ( & V_67 ) ;
if ( V_66 < 0 )
goto V_73;
V_66 = F_37 ( & V_69 ) ;
if ( V_66 < 0 )
goto V_74;
return 0 ;
V_74:
F_38 ( & V_67 ) ;
V_73:
F_39 ( & V_71 ) ;
V_72:
return V_66 ;
}
static void T_4 F_40 ( void )
{
F_38 ( & V_69 ) ;
F_38 ( & V_67 ) ;
F_39 ( & V_71 ) ;
}
