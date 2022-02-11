static bool F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_3 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 ;
V_9 = F_3 ( V_7 , V_4 ) ;
if ( V_9 && V_2 -> V_10 & V_11 )
F_4 ( V_5 , V_9 -> V_5 ) ;
return ! ! V_9 ;
}
static int F_5 ( const struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 ;
unsigned int V_14 ;
if ( V_13 -> V_10 != 0 )
return - V_15 ;
V_14 = sizeof( * V_9 ) ;
if ( V_2 -> V_10 & V_11 )
V_14 += sizeof( V_9 -> V_5 [ 0 ] ) ;
V_9 = F_6 ( V_14 , V_16 ) ;
if ( V_9 == NULL )
return - V_17 ;
F_4 ( & V_9 -> V_4 , & V_13 -> V_4 ) ;
if ( V_2 -> V_10 & V_11 )
F_4 ( V_9 -> V_5 , & V_13 -> V_5 ) ;
F_7 ( V_7 , & V_9 -> V_18 ) ;
return 0 ;
}
static void F_8 ( const struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_9 ( & V_9 -> V_4 , V_19 ) ;
if ( V_2 -> V_10 & V_11 )
F_9 ( V_9 -> V_5 , V_2 -> V_20 ) ;
F_10 ( V_9 ) ;
}
static void F_11 ( const struct V_1 * V_2 ,
const struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( V_7 , V_13 -> V_21 ) ;
F_13 () ;
F_10 ( V_13 -> V_21 ) ;
}
static bool F_14 ( void * V_22 , void * V_23 )
{
struct V_8 * V_9 = V_22 ;
struct V_24 * V_25 = V_23 ;
if ( ! F_15 ( & V_9 -> V_4 , & V_25 -> V_13 -> V_4 , V_25 -> V_2 -> V_26 ) ) {
V_25 -> V_13 -> V_21 = V_9 ;
V_25 -> V_13 -> V_10 = 0 ;
if ( V_25 -> V_2 -> V_10 & V_11 )
F_4 ( & V_25 -> V_13 -> V_5 , V_9 -> V_5 ) ;
return true ;
}
return false ;
}
static int F_16 ( const struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_24 V_23 = {
. V_2 = V_2 ,
. V_13 = V_13 ,
} ;
if ( F_17 ( V_7 , & V_13 -> V_4 ,
& F_14 , & V_23 ) )
return 0 ;
return - V_27 ;
}
static void F_18 ( const struct V_28 * V_29 , const struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_8 * V_9 ;
struct V_32 V_33 ;
struct V_12 V_13 ;
int V_34 ;
V_34 = F_19 ( V_7 , & V_33 ) ;
V_31 -> V_34 = V_34 ;
if ( V_34 )
return;
V_34 = F_20 ( & V_33 ) ;
if ( V_34 && V_34 != - V_35 ) {
V_31 -> V_34 = V_34 ;
goto V_36;
}
while ( ( V_9 = F_21 ( & V_33 ) ) ) {
if ( F_22 ( V_9 ) ) {
V_34 = F_23 ( V_9 ) ;
if ( V_34 != - V_35 ) {
V_31 -> V_34 = V_34 ;
goto V_36;
}
continue;
}
if ( V_31 -> V_37 < V_31 -> V_38 )
goto V_39;
memcpy ( & V_13 . V_4 , & V_9 -> V_4 , sizeof( V_13 . V_4 ) ) ;
if ( V_2 -> V_10 & V_11 )
memcpy ( & V_13 . V_5 , V_9 -> V_5 , sizeof( V_13 . V_5 ) ) ;
V_13 . V_10 = 0 ;
V_31 -> V_34 = V_31 -> V_40 ( V_29 , V_2 , V_31 , & V_13 ) ;
if ( V_31 -> V_34 < 0 )
goto V_36;
V_39:
V_31 -> V_37 ++ ;
}
V_36:
F_24 ( & V_33 ) ;
F_25 ( & V_33 ) ;
}
static unsigned int F_26 ( const struct V_41 * const V_42 [] )
{
return sizeof( struct V_6 ) ;
}
static int F_27 ( const struct V_1 * V_2 ,
const struct V_43 * V_44 ,
const struct V_41 * const V_45 [] )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_46 V_47 = {
. V_48 = V_44 -> V_14 ? : V_49 ,
. V_50 = F_28 ( struct V_8 , V_18 ) ,
. V_51 = F_28 ( struct V_8 , V_4 ) ,
. V_52 = V_2 -> V_26 ,
. V_53 = V_54 ,
} ;
return F_29 ( V_7 , & V_47 ) ;
}
static void F_30 ( const struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_55 * V_56 ;
struct V_8 * V_9 ;
struct V_57 * V_58 , * V_59 ;
unsigned int V_60 ;
V_7 -> V_61 = true ;
F_31 ( & V_7 -> V_62 ) ;
V_56 = F_32 ( V_7 -> V_56 , V_7 ) ;
for ( V_60 = 0 ; V_60 < V_56 -> V_14 ; V_60 ++ ) {
F_33 (he, pos, next, tbl, i, node)
F_8 ( V_2 , V_9 ) ;
}
F_34 ( & V_7 -> V_62 ) ;
F_35 ( V_7 ) ;
}
static bool F_36 ( const struct V_43 * V_44 , T_1 V_63 ,
struct V_64 * V_65 )
{
unsigned int V_66 ;
V_66 = sizeof( struct V_8 ) ;
if ( V_63 & V_11 )
V_66 += F_37 ( struct V_8 , V_5 [ 0 ] ) ;
if ( V_44 -> V_14 ) {
V_65 -> V_14 = sizeof( struct V_6 ) +
F_38 ( V_44 -> V_14 * 4 / 3 ) *
sizeof( struct V_8 * ) +
V_44 -> V_14 * V_66 ;
} else {
V_65 -> V_14 = V_66 + 2 * sizeof( struct V_8 * ) ;
}
V_65 -> V_67 = V_68 ;
return true ;
}
static int T_2 F_39 ( void )
{
return F_40 ( & V_69 ) ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_69 ) ;
}
