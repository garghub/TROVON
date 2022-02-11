static int
F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = * ( T_2 * ) V_3 ;
return ! ! F_2 ( V_8 , V_6 -> V_9 ) ;
}
static int
F_3 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = * ( T_2 * ) V_3 ;
if ( F_4 ( V_8 , V_6 -> V_9 ) )
return - V_10 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = * ( T_2 * ) V_3 ;
if ( ! F_6 ( V_8 , V_6 -> V_9 ) )
return - V_10 ;
return 0 ;
}
static int
F_7 ( const struct V_1 * V_2 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_15 * V_16 , * V_17 ;
T_2 V_8 , V_18 = V_14 -> args [ 2 ] ;
T_2 V_19 = V_6 -> V_20 - V_6 -> V_21 ;
V_16 = F_8 ( V_12 , V_22 ) ;
if ( ! V_16 )
return - V_23 ;
for (; V_14 -> args [ 2 ] <= V_19 ; V_14 -> args [ 2 ] ++ ) {
V_8 = V_14 -> args [ 2 ] ;
if ( ! F_2 ( V_8 , V_6 -> V_9 ) )
continue;
V_17 = F_8 ( V_12 , V_24 ) ;
if ( ! V_17 ) {
if ( V_8 == V_18 ) {
F_9 ( V_12 , V_16 ) ;
return - V_23 ;
} else
goto V_25;
}
F_10 ( V_12 , V_26 ,
F_11 ( V_6 -> V_21 + V_8 ) ) ;
F_12 ( V_12 , V_17 ) ;
}
F_12 ( V_12 , V_16 ) ;
V_14 -> args [ 2 ] = 0 ;
return 0 ;
V_25:
F_9 ( V_12 , V_17 ) ;
F_12 ( V_12 , V_16 ) ;
if ( F_13 ( V_8 == V_18 ) ) {
V_14 -> args [ 2 ] = 0 ;
return - V_23 ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
const unsigned long * V_9 = V_6 -> V_9 ;
T_2 V_8 = * ( T_2 * ) V_3 ;
return F_15 ( V_9 [ V_8 ] ) ;
}
static int
F_16 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long * V_9 = V_6 -> V_9 ;
T_2 V_8 = * ( T_2 * ) V_3 ;
if ( F_15 ( V_9 [ V_8 ] ) )
return - V_10 ;
V_9 [ V_8 ] = F_17 ( V_4 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long * V_9 = V_6 -> V_9 ;
T_2 V_8 = * ( T_2 * ) V_3 ;
int V_27 = - V_10 ;
if ( F_15 ( V_9 [ V_8 ] ) )
V_27 = 0 ;
V_9 [ V_8 ] = V_28 ;
return V_27 ;
}
static int
F_19 ( const struct V_1 * V_2 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_15 * V_29 , * V_17 ;
T_2 V_8 , V_18 = V_14 -> args [ 2 ] ;
T_2 V_19 = V_6 -> V_20 - V_6 -> V_21 ;
const unsigned long * V_9 = V_6 -> V_9 ;
V_29 = F_8 ( V_12 , V_22 ) ;
if ( ! V_29 )
return - V_23 ;
for (; V_14 -> args [ 2 ] <= V_19 ; V_14 -> args [ 2 ] ++ ) {
V_8 = V_14 -> args [ 2 ] ;
if ( ! F_15 ( V_9 [ V_8 ] ) )
continue;
V_17 = F_8 ( V_12 , V_24 ) ;
if ( ! V_17 ) {
if ( V_8 == V_18 ) {
F_9 ( V_12 , V_29 ) ;
return - V_23 ;
} else
goto V_25;
}
F_10 ( V_12 , V_26 ,
F_11 ( V_6 -> V_21 + V_8 ) ) ;
F_20 ( V_12 , V_30 ,
F_21 ( F_22 ( V_9 [ V_8 ] ) ) ) ;
F_12 ( V_12 , V_17 ) ;
}
F_12 ( V_12 , V_29 ) ;
V_14 -> args [ 2 ] = 0 ;
return 0 ;
V_25:
F_9 ( V_12 , V_17 ) ;
F_12 ( V_12 , V_29 ) ;
if ( F_13 ( V_8 == V_18 ) ) {
V_14 -> args [ 2 ] = 0 ;
return - V_23 ;
}
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , const struct V_11 * V_12 ,
enum V_31 V_29 , T_3 V_32 , T_3 V_33 , T_3 V_34 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 V_35 = V_2 -> V_36 -> V_29 [ V_29 ] ;
T_5 V_37 ;
T_2 V_38 = 0 ;
if ( ! F_24 ( V_12 , V_32 , V_34 & V_39 , & V_37 ) )
return - V_40 ;
V_38 = F_25 ( V_37 ) ;
if ( V_38 < V_6 -> V_21 || V_38 > V_6 -> V_20 )
return - V_41 ;
V_38 -= V_6 -> V_21 ;
return V_35 ( V_2 , & V_38 , V_6 -> V_4 ) ;
}
static int
F_26 ( struct V_1 * V_2 , struct V_15 * V_42 [] ,
enum V_31 V_29 , T_1 * V_43 , T_1 V_34 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_4 V_35 = V_2 -> V_36 -> V_29 [ V_29 ] ;
T_1 V_4 = V_6 -> V_4 ;
T_1 V_38 ;
T_2 V_8 , V_44 ;
int V_27 = 0 ;
if ( F_13 ( ! F_27 ( V_42 , V_26 ) ||
! F_28 ( V_42 , V_45 ) ||
! F_28 ( V_42 , V_30 ) ) )
return - V_46 ;
if ( V_42 [ V_47 ] )
* V_43 = F_29 ( V_42 [ V_47 ] ) ;
V_38 = F_30 ( V_42 [ V_26 ] ) ;
if ( V_38 < V_6 -> V_21 || V_38 > V_6 -> V_20 )
return - V_41 ;
if ( V_42 [ V_30 ] ) {
if ( ! F_31 ( V_6 -> V_4 ) )
return - V_48 ;
V_4 = F_32 ( V_42 [ V_30 ] ) ;
}
if ( V_29 == V_49 ) {
V_8 = V_38 - V_6 -> V_21 ;
return V_35 ( V_2 , & V_8 , V_4 ) ;
}
if ( V_42 [ V_45 ] ) {
V_44 = F_30 ( V_42 [ V_45 ] ) ;
if ( V_38 > V_44 ) {
F_33 ( V_38 , V_44 ) ;
if ( V_38 < V_6 -> V_21 )
return - V_41 ;
}
} else
V_44 = V_38 ;
if ( V_44 > V_6 -> V_20 )
return - V_41 ;
for (; V_38 <= V_44 ; V_38 ++ ) {
V_8 = V_38 - V_6 -> V_21 ;
V_27 = V_35 ( V_2 , & V_8 , V_4 ) ;
if ( V_27 && ! F_34 ( V_27 , V_34 ) )
return V_27 ;
else
V_27 = 0 ;
}
return V_27 ;
}
static void
F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_31 ( V_6 -> V_4 ) )
F_36 ( & V_6 -> V_50 ) ;
F_37 ( V_6 -> V_9 ) ;
F_38 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
static void
F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
memset ( V_6 -> V_9 , 0 , V_6 -> V_51 ) ;
}
static int
F_40 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
const struct V_5 * V_6 = V_2 -> V_7 ;
struct V_15 * V_17 ;
V_17 = F_8 ( V_12 , V_24 ) ;
if ( ! V_17 )
goto V_25;
F_10 ( V_12 , V_26 , F_11 ( V_6 -> V_21 ) ) ;
F_10 ( V_12 , V_45 , F_11 ( V_6 -> V_20 ) ) ;
F_20 ( V_12 , V_52 , F_21 ( V_2 -> V_53 - 1 ) ) ;
F_20 ( V_12 , V_54 ,
F_21 ( sizeof( * V_6 ) + V_6 -> V_51 ) ) ;
if ( F_31 ( V_6 -> V_4 ) )
F_20 ( V_12 , V_30 , F_21 ( V_6 -> V_4 ) ) ;
F_12 ( V_12 , V_17 ) ;
return 0 ;
V_25:
return - V_23 ;
}
static bool
F_41 ( const struct V_1 * V_55 , const struct V_1 * V_56 )
{
const struct V_5 * V_57 = V_55 -> V_7 ;
const struct V_5 * V_58 = V_56 -> V_7 ;
return V_57 -> V_21 == V_58 -> V_21 &&
V_57 -> V_20 == V_58 -> V_20 &&
V_57 -> V_4 == V_58 -> V_4 ;
}
static void
F_42 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long * V_60 = V_6 -> V_9 ;
T_1 V_8 ;
T_2 V_19 = V_6 -> V_20 - V_6 -> V_21 ;
F_43 ( & V_2 -> V_61 ) ;
for ( V_8 = 0 ; V_8 <= V_19 ; V_8 ++ )
if ( F_44 ( V_60 [ V_8 ] ) )
V_60 [ V_8 ] = V_28 ;
F_45 ( & V_2 -> V_61 ) ;
V_6 -> V_50 . V_62 = V_63 + F_46 ( V_6 -> V_4 ) * V_64 ;
F_47 ( & V_6 -> V_50 ) ;
}
static void
F_48 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_49 ( & V_6 -> V_50 ) ;
V_6 -> V_50 . V_7 = ( unsigned long ) V_2 ;
V_6 -> V_50 . V_65 = F_42 ;
V_6 -> V_50 . V_62 = V_63 + F_46 ( V_6 -> V_4 ) * V_64 ;
F_47 ( & V_6 -> V_50 ) ;
}
static bool
F_50 ( struct V_1 * V_2 , struct V_5 * V_6 ,
T_2 V_21 , T_2 V_20 )
{
V_6 -> V_9 = F_51 ( V_6 -> V_51 ) ;
if ( ! V_6 -> V_9 )
return false ;
V_6 -> V_21 = V_21 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_4 = V_66 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_67 = V_68 ;
return true ;
}
static int
F_52 ( struct V_1 * V_2 , struct V_15 * V_42 [] ,
T_1 V_34 )
{
struct V_5 * V_6 ;
T_2 V_21 , V_20 ;
if ( F_13 ( ! F_27 ( V_42 , V_26 ) ||
! F_27 ( V_42 , V_45 ) ||
! F_28 ( V_42 , V_30 ) ) )
return - V_46 ;
V_21 = F_30 ( V_42 [ V_26 ] ) ;
V_20 = F_30 ( V_42 [ V_45 ] ) ;
if ( V_21 > V_20 ) {
T_2 V_69 = V_21 ;
V_21 = V_20 ;
V_20 = V_69 ;
}
V_6 = F_53 ( sizeof( * V_6 ) , V_70 ) ;
if ( ! V_6 )
return - V_71 ;
if ( V_42 [ V_30 ] ) {
V_6 -> V_51 = ( V_20 - V_21 + 1 )
* sizeof( unsigned long ) ;
if ( ! F_50 ( V_2 , V_6 , V_21 , V_20 ) ) {
F_38 ( V_6 ) ;
return - V_71 ;
}
V_6 -> V_4 = F_32 ( V_42 [ V_30 ] ) ;
V_2 -> V_36 = & V_72 ;
F_48 ( V_2 ) ;
} else {
V_6 -> V_51 = F_54 ( 0 , V_20 - V_21 ) ;
F_55 ( L_1 , V_6 -> V_51 ) ;
if ( ! F_50 ( V_2 , V_6 , V_21 , V_20 ) ) {
F_38 ( V_6 ) ;
return - V_71 ;
}
V_2 -> V_36 = & V_5 ;
}
return 0 ;
}
static int T_6
F_56 ( void )
{
return F_57 ( & V_73 ) ;
}
static void T_7
F_58 ( void )
{
F_59 ( & V_73 ) ;
}
