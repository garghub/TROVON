static inline T_1 F_1 ( const void * V_1 , T_1 V_2 , T_1 V_3 )
{
const struct V_4 * V_5 = V_1 ;
return F_2 ( V_5 -> V_6 , V_2 , V_3 ) ;
}
static inline T_1 F_3 ( const void * V_1 , T_1 V_2 , T_1 V_3 )
{
const struct V_7 * V_8 = V_1 ;
return F_2 ( F_4 ( & V_8 -> V_9 ) , V_2 , V_3 ) ;
}
static inline int F_5 ( struct V_10 * V_5 ,
const void * V_11 )
{
const struct V_4 * V_12 = V_5 -> V_6 ;
const struct V_7 * V_8 = V_11 ;
if ( memcmp ( F_4 ( & V_8 -> V_9 ) , V_12 -> V_6 , V_12 -> V_13 -> V_14 ) )
return 1 ;
if ( F_6 ( & V_8 -> V_9 ) )
return 1 ;
if ( ! F_7 ( & V_8 -> V_9 , V_12 -> V_15 ) )
return 1 ;
return 0 ;
}
static bool F_8 ( const struct V_16 * V_16 , const struct V_17 * V_13 ,
const T_1 * V_6 , const struct V_18 * * V_9 )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
const struct V_7 * V_8 ;
struct V_4 V_5 = {
. V_15 = F_10 ( V_16 ) ,
. V_13 = V_13 ,
. V_6 = V_6 ,
} ;
V_8 = F_11 ( & V_20 -> V_21 , & V_5 , V_22 ) ;
if ( V_8 != NULL )
* V_9 = & V_8 -> V_9 ;
return ! ! V_8 ;
}
static bool F_12 ( struct V_17 * V_13 , const T_1 * V_6 ,
void * (* F_13)( struct V_17 * ,
const struct V_23 * ,
struct V_24 * V_25 ) ,
const struct V_23 * V_26 ,
struct V_24 * V_25 ,
const struct V_18 * * V_9 )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
struct V_7 * V_8 , * V_27 ;
struct V_4 V_5 = {
. V_15 = V_28 ,
. V_13 = V_13 ,
. V_6 = V_6 ,
} ;
V_8 = F_11 ( & V_20 -> V_21 , & V_5 , V_22 ) ;
if ( V_8 != NULL )
goto V_29;
V_8 = F_13 ( V_13 , V_26 , V_25 ) ;
if ( V_8 == NULL )
goto V_30;
V_27 = F_14 ( & V_20 -> V_21 , & V_5 , & V_8 -> V_31 ,
V_22 ) ;
if ( F_15 ( V_27 ) )
goto V_32;
if ( V_27 ) {
F_16 ( V_13 , V_8 , true ) ;
V_8 = V_27 ;
}
V_29:
* V_9 = & V_8 -> V_9 ;
return true ;
V_32:
F_16 ( V_13 , V_8 , true ) ;
V_30:
return false ;
}
static int F_17 ( const struct V_16 * V_16 , const struct V_17 * V_13 ,
const struct V_33 * V_34 ,
struct V_18 * * V_9 )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
struct V_7 * V_8 = V_34 -> V_20 ;
struct V_4 V_5 = {
. V_15 = F_18 ( V_16 ) ,
. V_13 = V_13 ,
. V_6 = V_34 -> V_6 . V_35 . V_1 ,
} ;
struct V_7 * V_27 ;
V_27 = F_14 ( & V_20 -> V_21 , & V_5 , & V_8 -> V_31 ,
V_22 ) ;
if ( F_15 ( V_27 ) )
return F_19 ( V_27 ) ;
if ( V_27 ) {
* V_9 = & V_27 -> V_9 ;
return - V_36 ;
}
return 0 ;
}
static void F_20 ( const struct V_16 * V_16 , const struct V_17 * V_13 ,
const struct V_33 * V_34 )
{
struct V_7 * V_8 = V_34 -> V_20 ;
F_21 ( V_16 , V_13 , & V_8 -> V_9 ) ;
F_22 ( & V_8 -> V_9 ) ;
}
static bool F_23 ( const struct V_16 * V_16 ,
const struct V_17 * V_13 , void * V_20 )
{
struct V_7 * V_8 = V_20 ;
if ( ! F_24 ( & V_8 -> V_9 ) ||
! F_25 ( V_16 , & V_8 -> V_9 ) ) {
F_21 ( V_16 , V_13 , & V_8 -> V_9 ) ;
return true ;
}
return false ;
}
static void * F_26 ( const struct V_16 * V_16 ,
const struct V_17 * V_13 ,
const struct V_33 * V_34 )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
struct V_7 * V_8 ;
struct V_4 V_5 = {
. V_15 = F_18 ( V_16 ) ,
. V_13 = V_13 ,
. V_6 = V_34 -> V_6 . V_35 . V_1 ,
} ;
F_27 () ;
V_8 = F_11 ( & V_20 -> V_21 , & V_5 , V_22 ) ;
if ( V_8 != NULL &&
! F_23 ( V_16 , V_13 , V_8 ) )
V_8 = NULL ;
F_28 () ;
return V_8 ;
}
static void F_29 ( const struct V_17 * V_13 ,
const struct V_33 * V_34 )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
struct V_7 * V_8 = V_34 -> V_20 ;
F_30 ( & V_20 -> V_21 , & V_8 -> V_31 , V_22 ) ;
}
static void F_31 ( const struct V_37 * V_38 , struct V_17 * V_13 ,
struct V_39 * V_40 )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
struct V_7 * V_8 ;
struct V_41 V_42 ;
struct V_33 V_34 ;
int V_43 ;
V_43 = F_32 ( & V_20 -> V_21 , & V_42 , V_44 ) ;
V_40 -> V_43 = V_43 ;
if ( V_43 )
return;
V_43 = F_33 ( & V_42 ) ;
if ( V_43 && V_43 != - V_45 ) {
V_40 -> V_43 = V_43 ;
goto V_29;
}
while ( ( V_8 = F_34 ( & V_42 ) ) ) {
if ( F_15 ( V_8 ) ) {
V_43 = F_19 ( V_8 ) ;
if ( V_43 != - V_45 ) {
V_40 -> V_43 = V_43 ;
goto V_29;
}
continue;
}
if ( V_40 -> V_46 < V_40 -> V_47 )
goto V_48;
if ( F_6 ( & V_8 -> V_9 ) )
goto V_48;
if ( ! F_7 ( & V_8 -> V_9 , V_40 -> V_15 ) )
goto V_48;
V_34 . V_20 = V_8 ;
V_40 -> V_43 = V_40 -> V_49 ( V_38 , V_13 , V_40 , & V_34 ) ;
if ( V_40 -> V_43 < 0 )
goto V_29;
V_48:
V_40 -> V_46 ++ ;
}
V_29:
F_35 ( & V_42 ) ;
F_36 ( & V_42 ) ;
}
static void F_37 ( struct V_50 * V_51 )
{
struct V_17 * V_13 ;
struct V_7 * V_8 ;
struct V_19 * V_20 ;
struct V_52 * V_53 = NULL ;
struct V_41 V_42 ;
int V_43 ;
V_20 = F_38 ( V_51 , struct V_19 , V_54 . V_51 ) ;
V_13 = F_39 ( V_20 ) ;
V_43 = F_32 ( & V_20 -> V_21 , & V_42 , V_44 ) ;
if ( V_43 )
goto V_55;
V_43 = F_33 ( & V_42 ) ;
if ( V_43 && V_43 != - V_45 )
goto V_29;
while ( ( V_8 = F_34 ( & V_42 ) ) ) {
if ( F_15 ( V_8 ) ) {
if ( F_19 ( V_8 ) != - V_45 )
goto V_29;
continue;
}
if ( ! F_6 ( & V_8 -> V_9 ) )
continue;
if ( F_24 ( & V_8 -> V_9 ) )
continue;
V_53 = F_40 ( V_13 , V_53 , V_56 ) ;
if ( V_53 == NULL )
goto V_29;
F_30 ( & V_20 -> V_21 , & V_8 -> V_31 , V_22 ) ;
F_41 ( & V_13 -> V_57 ) ;
F_42 ( V_53 , V_8 ) ;
}
V_29:
F_35 ( & V_42 ) ;
F_36 ( & V_42 ) ;
F_43 ( V_53 ) ;
V_55:
F_44 ( V_58 , & V_20 -> V_54 ,
F_45 ( V_13 ) ) ;
}
static unsigned int F_46 ( const struct V_59 * const V_60 [] )
{
return sizeof( struct V_19 ) ;
}
static int F_47 ( const struct V_17 * V_13 ,
const struct V_61 * V_62 ,
const struct V_59 * const V_63 [] )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
struct V_64 V_65 = V_22 ;
int V_43 ;
V_65 . V_66 = V_62 -> V_67 ? : V_68 ;
V_65 . V_69 = V_13 -> V_14 ;
V_43 = F_48 ( & V_20 -> V_21 , & V_65 ) ;
if ( V_43 < 0 )
return V_43 ;
F_49 ( & V_20 -> V_54 , F_37 ) ;
if ( V_13 -> V_70 & V_71 )
F_44 ( V_58 , & V_20 -> V_54 ,
F_45 ( V_13 ) ) ;
return 0 ;
}
static void F_50 ( void * V_11 , void * V_5 )
{
F_16 ( ( const struct V_17 * ) V_5 , V_11 , true ) ;
}
static void F_51 ( const struct V_17 * V_13 )
{
struct V_19 * V_20 = F_9 ( V_13 ) ;
F_52 ( & V_20 -> V_54 ) ;
F_53 ( & V_20 -> V_21 , F_50 ,
( void * ) V_13 ) ;
}
static bool F_54 ( const struct V_61 * V_62 , T_1 V_72 ,
struct V_73 * V_74 )
{
unsigned int V_75 ;
V_75 = sizeof( struct V_7 ) ;
if ( V_62 -> V_67 ) {
V_74 -> V_67 = sizeof( struct V_19 ) +
F_55 ( V_62 -> V_67 * 4 / 3 ) *
sizeof( struct V_7 * ) +
V_62 -> V_67 * V_75 ;
} else {
V_74 -> V_67 = V_75 + 2 * sizeof( struct V_7 * ) ;
}
V_74 -> V_76 = V_77 ;
return true ;
}
static int T_2 F_56 ( void )
{
return F_57 ( & V_78 ) ;
}
static void T_3 F_58 ( void )
{
F_59 ( & V_78 ) ;
}
