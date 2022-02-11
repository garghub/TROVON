static int
F_1 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_9 = * ( T_2 * ) V_3 ;
return ! ! F_2 ( V_9 , V_7 -> V_10 ) ;
}
static int
F_3 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_9 = * ( T_2 * ) V_3 ;
if ( F_4 ( V_9 , V_7 -> V_10 ) )
return - V_11 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_2 V_9 = * ( T_2 * ) V_3 ;
if ( ! F_6 ( V_9 , V_7 -> V_10 ) )
return - V_11 ;
return 0 ;
}
static int
F_7 ( const struct V_1 * V_2 ,
struct V_12 * V_13 , struct V_14 * V_15 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_16 * V_17 , * V_18 ;
T_2 V_9 , V_19 = V_15 -> args [ 2 ] ;
T_2 V_20 = V_7 -> V_21 - V_7 -> V_22 ;
V_17 = F_8 ( V_13 , V_23 ) ;
if ( ! V_17 )
return - V_24 ;
for (; V_15 -> args [ 2 ] <= V_20 ; V_15 -> args [ 2 ] ++ ) {
V_9 = V_15 -> args [ 2 ] ;
if ( ! F_2 ( V_9 , V_7 -> V_10 ) )
continue;
V_18 = F_8 ( V_13 , V_25 ) ;
if ( ! V_18 ) {
if ( V_9 == V_19 ) {
F_9 ( V_13 , V_17 ) ;
return - V_24 ;
} else
goto V_26;
}
F_10 ( V_13 , V_27 ,
F_11 ( V_7 -> V_22 + V_9 ) ) ;
F_12 ( V_13 , V_18 ) ;
}
F_12 ( V_13 , V_17 ) ;
V_15 -> args [ 2 ] = 0 ;
return 0 ;
V_26:
F_9 ( V_13 , V_18 ) ;
F_12 ( V_13 , V_17 ) ;
if ( F_13 ( V_9 == V_19 ) ) {
V_15 -> args [ 2 ] = 0 ;
return - V_24 ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
const unsigned long * V_10 = V_7 -> V_10 ;
T_2 V_9 = * ( T_2 * ) V_3 ;
return F_15 ( V_10 [ V_9 ] ) ;
}
static int
F_16 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long * V_10 = V_7 -> V_10 ;
T_2 V_9 = * ( T_2 * ) V_3 ;
if ( F_15 ( V_10 [ V_9 ] ) && ! ( V_5 & V_28 ) )
return - V_11 ;
V_10 [ V_9 ] = F_17 ( V_4 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , void * V_3 , T_1 V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long * V_10 = V_7 -> V_10 ;
T_2 V_9 = * ( T_2 * ) V_3 ;
int V_29 = - V_11 ;
if ( F_15 ( V_10 [ V_9 ] ) )
V_29 = 0 ;
V_10 [ V_9 ] = V_30 ;
return V_29 ;
}
static int
F_19 ( const struct V_1 * V_2 ,
struct V_12 * V_13 , struct V_14 * V_15 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_16 * V_31 , * V_18 ;
T_2 V_9 , V_19 = V_15 -> args [ 2 ] ;
T_2 V_20 = V_7 -> V_21 - V_7 -> V_22 ;
const unsigned long * V_10 = V_7 -> V_10 ;
V_31 = F_8 ( V_13 , V_23 ) ;
if ( ! V_31 )
return - V_24 ;
for (; V_15 -> args [ 2 ] <= V_20 ; V_15 -> args [ 2 ] ++ ) {
V_9 = V_15 -> args [ 2 ] ;
if ( ! F_15 ( V_10 [ V_9 ] ) )
continue;
V_18 = F_8 ( V_13 , V_25 ) ;
if ( ! V_18 ) {
if ( V_9 == V_19 ) {
F_9 ( V_13 , V_31 ) ;
return - V_24 ;
} else
goto V_26;
}
F_10 ( V_13 , V_27 ,
F_11 ( V_7 -> V_22 + V_9 ) ) ;
F_20 ( V_13 , V_32 ,
F_21 ( F_22 ( V_10 [ V_9 ] ) ) ) ;
F_12 ( V_13 , V_18 ) ;
}
F_12 ( V_13 , V_31 ) ;
V_15 -> args [ 2 ] = 0 ;
return 0 ;
V_26:
F_9 ( V_13 , V_18 ) ;
F_12 ( V_13 , V_31 ) ;
if ( F_13 ( V_9 == V_19 ) ) {
V_15 -> args [ 2 ] = 0 ;
return - V_24 ;
}
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , const struct V_12 * V_13 ,
const struct V_33 * V_34 ,
enum V_35 V_31 , const struct V_36 * V_37 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_3 V_38 = V_2 -> V_39 -> V_31 [ V_31 ] ;
T_4 V_40 ;
T_2 V_41 = 0 ;
if ( ! F_24 ( V_13 , V_37 -> V_42 ,
V_37 -> V_5 & V_43 , & V_40 ) )
return - V_44 ;
V_41 = F_25 ( V_40 ) ;
if ( V_41 < V_7 -> V_22 || V_41 > V_7 -> V_21 )
return - V_45 ;
V_41 -= V_7 -> V_22 ;
return V_38 ( V_2 , & V_41 , F_26 ( V_37 , V_7 ) , V_37 -> V_46 ) ;
}
static int
F_27 ( struct V_1 * V_2 , struct V_16 * V_47 [] ,
enum V_35 V_31 , T_1 * V_48 , T_1 V_5 , bool V_49 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
T_3 V_38 = V_2 -> V_39 -> V_31 [ V_31 ] ;
T_1 V_4 = V_7 -> V_4 ;
T_1 V_41 ;
T_2 V_9 , V_50 ;
int V_29 = 0 ;
if ( F_13 ( ! F_28 ( V_47 , V_27 ) ||
! F_29 ( V_47 , V_51 ) ||
! F_29 ( V_47 , V_32 ) ) )
return - V_52 ;
if ( V_47 [ V_53 ] )
* V_48 = F_30 ( V_47 [ V_53 ] ) ;
V_41 = F_31 ( V_47 [ V_27 ] ) ;
if ( V_41 < V_7 -> V_22 || V_41 > V_7 -> V_21 )
return - V_45 ;
if ( V_47 [ V_32 ] ) {
if ( ! F_32 ( V_7 -> V_4 ) )
return - V_54 ;
V_4 = F_33 ( V_47 [ V_32 ] ) ;
}
if ( V_31 == V_55 ) {
V_9 = V_41 - V_7 -> V_22 ;
return V_38 ( V_2 , & V_9 , V_4 , V_5 ) ;
}
if ( V_47 [ V_51 ] ) {
V_50 = F_31 ( V_47 [ V_51 ] ) ;
if ( V_41 > V_50 ) {
F_34 ( V_41 , V_50 ) ;
if ( V_41 < V_7 -> V_22 )
return - V_45 ;
}
} else
V_50 = V_41 ;
if ( V_50 > V_7 -> V_21 )
return - V_45 ;
for (; V_41 <= V_50 ; V_41 ++ ) {
V_9 = V_41 - V_7 -> V_22 ;
V_29 = V_38 ( V_2 , & V_9 , V_4 , V_5 ) ;
if ( V_29 && ! F_35 ( V_29 , V_5 ) )
return V_29 ;
else
V_29 = 0 ;
}
return V_29 ;
}
static void
F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
if ( F_32 ( V_7 -> V_4 ) )
F_37 ( & V_7 -> V_56 ) ;
F_38 ( V_7 -> V_10 ) ;
F_39 ( V_7 ) ;
V_2 -> V_8 = NULL ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
memset ( V_7 -> V_10 , 0 , V_7 -> V_57 ) ;
}
static int
F_41 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_16 * V_18 ;
V_18 = F_8 ( V_13 , V_25 ) ;
if ( ! V_18 )
goto V_26;
F_10 ( V_13 , V_27 , F_11 ( V_7 -> V_22 ) ) ;
F_10 ( V_13 , V_51 , F_11 ( V_7 -> V_21 ) ) ;
F_20 ( V_13 , V_58 , F_21 ( V_2 -> V_59 - 1 ) ) ;
F_20 ( V_13 , V_60 ,
F_21 ( sizeof( * V_7 ) + V_7 -> V_57 ) ) ;
if ( F_32 ( V_7 -> V_4 ) )
F_20 ( V_13 , V_32 , F_21 ( V_7 -> V_4 ) ) ;
F_12 ( V_13 , V_18 ) ;
return 0 ;
V_26:
return - V_24 ;
}
static bool
F_42 ( const struct V_1 * V_61 , const struct V_1 * V_62 )
{
const struct V_6 * V_63 = V_61 -> V_8 ;
const struct V_6 * V_64 = V_62 -> V_8 ;
return V_63 -> V_22 == V_64 -> V_22 &&
V_63 -> V_21 == V_64 -> V_21 &&
V_63 -> V_4 == V_64 -> V_4 ;
}
static void
F_43 ( unsigned long V_65 )
{
struct V_1 * V_2 = (struct V_1 * ) V_65 ;
struct V_6 * V_7 = V_2 -> V_8 ;
unsigned long * V_66 = V_7 -> V_10 ;
T_1 V_9 ;
T_2 V_20 = V_7 -> V_21 - V_7 -> V_22 ;
F_44 ( & V_2 -> V_67 ) ;
for ( V_9 = 0 ; V_9 <= V_20 ; V_9 ++ )
if ( F_45 ( V_66 [ V_9 ] ) )
V_66 [ V_9 ] = V_30 ;
F_46 ( & V_2 -> V_67 ) ;
V_7 -> V_56 . V_68 = V_69 + F_47 ( V_7 -> V_4 ) * V_70 ;
F_48 ( & V_7 -> V_56 ) ;
}
static void
F_49 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
F_50 ( & V_7 -> V_56 ) ;
V_7 -> V_56 . V_8 = ( unsigned long ) V_2 ;
V_7 -> V_56 . V_71 = F_43 ;
V_7 -> V_56 . V_68 = V_69 + F_47 ( V_7 -> V_4 ) * V_70 ;
F_48 ( & V_7 -> V_56 ) ;
}
static bool
F_51 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_2 V_22 , T_2 V_21 )
{
V_7 -> V_10 = F_52 ( V_7 -> V_57 ) ;
if ( ! V_7 -> V_10 )
return false ;
V_7 -> V_22 = V_22 ;
V_7 -> V_21 = V_21 ;
V_7 -> V_4 = V_72 ;
V_2 -> V_8 = V_7 ;
V_2 -> V_42 = V_73 ;
return true ;
}
static int
F_53 ( struct V_1 * V_2 , struct V_16 * V_47 [] ,
T_1 V_5 )
{
struct V_6 * V_7 ;
T_2 V_22 , V_21 ;
if ( F_13 ( ! F_28 ( V_47 , V_27 ) ||
! F_28 ( V_47 , V_51 ) ||
! F_29 ( V_47 , V_32 ) ) )
return - V_52 ;
V_22 = F_31 ( V_47 [ V_27 ] ) ;
V_21 = F_31 ( V_47 [ V_51 ] ) ;
if ( V_22 > V_21 ) {
T_2 V_74 = V_22 ;
V_22 = V_21 ;
V_21 = V_74 ;
}
V_7 = F_54 ( sizeof( * V_7 ) , V_75 ) ;
if ( ! V_7 )
return - V_76 ;
if ( V_47 [ V_32 ] ) {
V_7 -> V_57 = ( V_21 - V_22 + 1 )
* sizeof( unsigned long ) ;
if ( ! F_51 ( V_2 , V_7 , V_22 , V_21 ) ) {
F_39 ( V_7 ) ;
return - V_76 ;
}
V_7 -> V_4 = F_33 ( V_47 [ V_32 ] ) ;
V_2 -> V_39 = & V_77 ;
F_49 ( V_2 ) ;
} else {
V_7 -> V_57 = F_55 ( 0 , V_21 - V_22 ) ;
F_56 ( L_1 , V_7 -> V_57 ) ;
if ( ! F_51 ( V_2 , V_7 , V_22 , V_21 ) ) {
F_39 ( V_7 ) ;
return - V_76 ;
}
V_2 -> V_39 = & V_6 ;
}
return 0 ;
}
static int T_5
F_57 ( void )
{
return F_58 ( & V_78 ) ;
}
static void T_6
F_59 ( void )
{
F_60 ( & V_78 ) ;
}
