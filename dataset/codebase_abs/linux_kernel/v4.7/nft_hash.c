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
static bool F_8 ( const struct V_16 * V_13 , const T_1 * V_6 ,
const struct V_17 * * V_9 )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
const struct V_7 * V_8 ;
struct V_4 V_5 = {
. V_15 = F_10 ( F_11 ( & V_13 -> V_20 ) ) ,
. V_13 = V_13 ,
. V_6 = V_6 ,
} ;
V_8 = F_12 ( & V_19 -> V_21 , & V_5 , V_22 ) ;
if ( V_8 != NULL )
* V_9 = & V_8 -> V_9 ;
return ! ! V_8 ;
}
static bool F_13 ( struct V_16 * V_13 , const T_1 * V_6 ,
void * (* F_14)( struct V_16 * ,
const struct V_23 * ,
struct V_24 * V_25 ) ,
const struct V_23 * V_26 ,
struct V_24 * V_25 ,
const struct V_17 * * V_9 )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
struct V_7 * V_8 ;
struct V_4 V_5 = {
. V_15 = V_27 ,
. V_13 = V_13 ,
. V_6 = V_6 ,
} ;
V_8 = F_12 ( & V_19 -> V_21 , & V_5 , V_22 ) ;
if ( V_8 != NULL )
goto V_28;
V_8 = F_14 ( V_13 , V_26 , V_25 ) ;
if ( V_8 == NULL )
goto V_29;
if ( F_15 ( & V_19 -> V_21 , & V_5 , & V_8 -> V_30 ,
V_22 ) )
goto V_31;
V_28:
* V_9 = & V_8 -> V_9 ;
return true ;
V_31:
F_16 ( V_13 , V_8 ) ;
V_29:
return false ;
}
static int F_17 ( const struct V_16 * V_13 ,
const struct V_32 * V_33 )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
struct V_7 * V_8 = V_33 -> V_19 ;
struct V_4 V_5 = {
. V_15 = F_18 ( F_11 ( & V_13 -> V_20 ) ) ,
. V_13 = V_13 ,
. V_6 = V_33 -> V_6 . V_34 . V_1 ,
} ;
return F_15 ( & V_19 -> V_21 , & V_5 , & V_8 -> V_30 ,
V_22 ) ;
}
static void F_19 ( const struct V_16 * V_13 ,
const struct V_32 * V_33 )
{
struct V_7 * V_8 = V_33 -> V_19 ;
F_20 ( V_13 , & V_8 -> V_9 ) ;
F_21 ( & V_8 -> V_9 ) ;
}
static void * F_22 ( const struct V_16 * V_13 ,
const struct V_32 * V_33 )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
struct V_7 * V_8 ;
struct V_4 V_5 = {
. V_15 = F_18 ( F_11 ( & V_13 -> V_20 ) ) ,
. V_13 = V_13 ,
. V_6 = V_33 -> V_6 . V_34 . V_1 ,
} ;
F_23 () ;
V_8 = F_12 ( & V_19 -> V_21 , & V_5 , V_22 ) ;
if ( V_8 != NULL ) {
if ( ! F_24 ( & V_8 -> V_9 ) )
F_20 ( V_13 , & V_8 -> V_9 ) ;
else
V_8 = NULL ;
}
F_25 () ;
return V_8 ;
}
static void F_26 ( const struct V_16 * V_13 ,
const struct V_32 * V_33 )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
struct V_7 * V_8 = V_33 -> V_19 ;
F_27 ( & V_19 -> V_21 , & V_8 -> V_30 , V_22 ) ;
}
static void F_28 ( const struct V_35 * V_36 , const struct V_16 * V_13 ,
struct V_37 * V_38 )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
struct V_7 * V_8 ;
struct V_39 V_40 ;
struct V_32 V_33 ;
int V_41 ;
V_41 = F_29 ( & V_19 -> V_21 , & V_40 , V_42 ) ;
V_38 -> V_41 = V_41 ;
if ( V_41 )
return;
V_41 = F_30 ( & V_40 ) ;
if ( V_41 && V_41 != - V_43 ) {
V_38 -> V_41 = V_41 ;
goto V_28;
}
while ( ( V_8 = F_31 ( & V_40 ) ) ) {
if ( F_32 ( V_8 ) ) {
V_41 = F_33 ( V_8 ) ;
if ( V_41 != - V_43 ) {
V_38 -> V_41 = V_41 ;
goto V_28;
}
continue;
}
if ( V_38 -> V_44 < V_38 -> V_45 )
goto V_46;
if ( F_6 ( & V_8 -> V_9 ) )
goto V_46;
if ( ! F_7 ( & V_8 -> V_9 , V_38 -> V_15 ) )
goto V_46;
V_33 . V_19 = V_8 ;
V_38 -> V_41 = V_38 -> V_47 ( V_36 , V_13 , V_38 , & V_33 ) ;
if ( V_38 -> V_41 < 0 )
goto V_28;
V_46:
V_38 -> V_44 ++ ;
}
V_28:
F_34 ( & V_40 ) ;
F_35 ( & V_40 ) ;
}
static void F_36 ( struct V_48 * V_49 )
{
struct V_16 * V_13 ;
struct V_7 * V_8 ;
struct V_18 * V_19 ;
struct V_50 * V_51 = NULL ;
struct V_39 V_40 ;
int V_41 ;
V_19 = F_37 ( V_49 , struct V_18 , V_52 . V_49 ) ;
V_13 = F_38 ( V_19 ) ;
V_41 = F_29 ( & V_19 -> V_21 , & V_40 , V_42 ) ;
if ( V_41 )
goto V_53;
V_41 = F_30 ( & V_40 ) ;
if ( V_41 && V_41 != - V_43 )
goto V_28;
while ( ( V_8 = F_31 ( & V_40 ) ) ) {
if ( F_32 ( V_8 ) ) {
if ( F_33 ( V_8 ) != - V_43 )
goto V_28;
continue;
}
if ( ! F_6 ( & V_8 -> V_9 ) )
continue;
if ( F_24 ( & V_8 -> V_9 ) )
continue;
V_51 = F_39 ( V_13 , V_51 , V_54 ) ;
if ( V_51 == NULL )
goto V_28;
F_27 ( & V_19 -> V_21 , & V_8 -> V_30 , V_22 ) ;
F_40 ( & V_13 -> V_55 ) ;
F_41 ( V_51 , V_8 ) ;
}
V_28:
F_34 ( & V_40 ) ;
F_35 ( & V_40 ) ;
F_42 ( V_51 ) ;
V_53:
F_43 ( V_56 , & V_19 -> V_52 ,
F_44 ( V_13 ) ) ;
}
static unsigned int F_45 ( const struct V_57 * const V_58 [] )
{
return sizeof( struct V_18 ) ;
}
static int F_46 ( const struct V_16 * V_13 ,
const struct V_59 * V_60 ,
const struct V_57 * const V_61 [] )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
struct V_62 V_63 = V_22 ;
int V_41 ;
V_63 . V_64 = V_60 -> V_65 ? : V_66 ;
V_63 . V_67 = V_13 -> V_14 ;
V_41 = F_47 ( & V_19 -> V_21 , & V_63 ) ;
if ( V_41 < 0 )
return V_41 ;
F_48 ( & V_19 -> V_52 , F_36 ) ;
if ( V_13 -> V_68 & V_69 )
F_43 ( V_56 , & V_19 -> V_52 ,
F_44 ( V_13 ) ) ;
return 0 ;
}
static void F_49 ( void * V_11 , void * V_5 )
{
F_16 ( ( const struct V_16 * ) V_5 , V_11 ) ;
}
static void F_50 ( const struct V_16 * V_13 )
{
struct V_18 * V_19 = F_9 ( V_13 ) ;
F_51 ( & V_19 -> V_52 ) ;
F_52 ( & V_19 -> V_21 , F_49 ,
( void * ) V_13 ) ;
}
static bool F_53 ( const struct V_59 * V_60 , T_1 V_70 ,
struct V_71 * V_72 )
{
unsigned int V_73 ;
V_73 = sizeof( struct V_7 ) ;
if ( V_60 -> V_65 ) {
V_72 -> V_65 = sizeof( struct V_18 ) +
F_54 ( V_60 -> V_65 * 4 / 3 ) *
sizeof( struct V_7 * ) +
V_60 -> V_65 * V_73 ;
} else {
V_72 -> V_65 = V_73 + 2 * sizeof( struct V_7 * ) ;
}
V_72 -> V_74 = V_75 ;
return true ;
}
static int T_2 F_55 ( void )
{
return F_56 ( & V_76 ) ;
}
static void T_3 F_57 ( void )
{
F_58 ( & V_76 ) ;
}
