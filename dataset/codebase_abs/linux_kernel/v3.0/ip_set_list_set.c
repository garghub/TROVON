static inline struct V_1 *
F_1 ( const struct V_2 * V_3 , T_1 V_4 )
{
return (struct V_1 * ) ( ( void * ) V_3 -> V_5 + V_4 * V_3 -> V_6 ) ;
}
static inline struct V_7 *
F_2 ( const struct V_2 * V_3 , T_1 V_4 )
{
return (struct V_7 * ) ( ( void * ) V_3 -> V_5 + V_4 * V_3 -> V_6 ) ;
}
static inline bool
F_3 ( const struct V_2 * V_3 , T_1 V_4 )
{
const struct V_7 * V_8 = F_2 ( V_3 , V_4 ) ;
return F_4 ( V_8 -> V_9 ) ;
}
static inline bool
F_5 ( const struct V_2 * V_3 , T_1 V_4 )
{
const struct V_7 * V_8 = F_2 ( V_3 , V_4 ) ;
return F_6 ( V_8 -> V_9 ) ;
}
static int
F_7 ( struct V_10 * V_11 , const struct V_12 * V_13 ,
enum V_14 V_15 , T_2 V_16 , T_2 V_17 , T_2 V_18 )
{
struct V_2 * V_3 = V_11 -> V_19 ;
struct V_1 * V_8 ;
T_1 V_20 ;
int V_21 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_22 ; V_20 ++ ) {
V_8 = F_1 ( V_3 , V_20 ) ;
if ( V_8 -> V_4 == V_23 )
return 0 ;
if ( F_8 ( V_3 -> V_9 ) && F_5 ( V_3 , V_20 ) )
continue;
switch ( V_15 ) {
case V_24 :
V_21 = F_9 ( V_8 -> V_4 , V_13 , V_16 , V_17 , V_18 ) ;
if ( V_21 > 0 )
return V_21 ;
break;
case V_25 :
V_21 = F_10 ( V_8 -> V_4 , V_13 , V_16 , V_17 , V_18 ) ;
if ( V_21 == 0 )
return V_21 ;
break;
case V_26 :
V_21 = F_11 ( V_8 -> V_4 , V_13 , V_16 , V_17 , V_18 ) ;
if ( V_21 == 0 )
return V_21 ;
break;
default:
break;
}
}
return - V_27 ;
}
static bool
F_12 ( const struct V_2 * V_3 , T_1 V_20 , T_3 V_4 )
{
const struct V_1 * V_8 ;
if ( V_20 + 1 < V_3 -> V_22 ) {
V_8 = F_1 ( V_3 , V_20 + 1 ) ;
return ! ! ( V_8 -> V_4 == V_4 &&
! ( F_8 ( V_3 -> V_9 ) &&
F_5 ( V_3 , V_20 + 1 ) ) ) ;
}
return 0 ;
}
static void
F_13 ( struct V_2 * V_3 , T_1 V_20 , T_3 V_4 )
{
struct V_1 * V_28 ;
for (; V_20 < V_3 -> V_22 ; V_20 ++ ) {
V_28 = F_1 ( V_3 , V_20 ) ;
F_14 ( V_28 -> V_4 , V_4 ) ;
if ( V_28 -> V_4 == V_23 )
break;
}
}
static void
F_15 ( struct V_2 * V_3 , T_1 V_20 , T_3 V_4 ,
unsigned long V_9 )
{
struct V_7 * V_28 ;
for (; V_20 < V_3 -> V_22 ; V_20 ++ ) {
V_28 = F_2 ( V_3 , V_20 ) ;
F_14 ( V_28 -> V_4 , V_4 ) ;
F_14 ( V_28 -> V_9 , V_9 ) ;
if ( V_28 -> V_4 == V_23 )
break;
}
}
static int
F_16 ( struct V_2 * V_3 , T_1 V_20 , T_3 V_4 ,
unsigned long V_9 )
{
const struct V_1 * V_28 = F_1 ( V_3 , V_20 ) ;
if ( V_20 == V_3 -> V_22 - 1 && V_28 -> V_4 != V_23 )
F_17 ( V_28 -> V_4 ) ;
if ( F_8 ( V_3 -> V_9 ) )
F_15 ( V_3 , V_20 , V_4 , F_18 ( V_9 ) ) ;
else
F_13 ( V_3 , V_20 , V_4 ) ;
return 0 ;
}
static int
F_19 ( struct V_2 * V_3 , T_1 V_20 )
{
struct V_1 * V_29 = F_1 ( V_3 , V_20 ) , * V_30 ;
F_17 ( V_29 -> V_4 ) ;
for (; V_20 < V_3 -> V_22 - 1 ; V_20 ++ ) {
V_30 = F_1 ( V_3 , V_20 + 1 ) ;
V_29 -> V_4 = V_30 -> V_4 ;
if ( F_8 ( V_3 -> V_9 ) )
( (struct V_7 * ) V_29 ) -> V_9 =
( (struct V_7 * ) V_30 ) -> V_9 ;
V_29 = V_30 ;
if ( V_29 -> V_4 == V_23 )
break;
}
V_29 -> V_4 = V_23 ;
return 0 ;
}
static int
F_20 ( struct V_10 * V_11 , struct V_31 * V_32 [] ,
enum V_14 V_15 , T_1 * V_33 , T_1 V_18 )
{
struct V_2 * V_3 = V_11 -> V_19 ;
bool F_8 = F_8 ( V_3 -> V_9 ) ;
int V_34 = 0 ;
T_1 V_9 = V_3 -> V_9 ;
T_3 V_4 , V_35 = V_23 ;
const struct V_1 * V_8 ;
struct V_10 * V_36 ;
T_1 V_20 ;
int V_21 = 0 ;
if ( F_21 ( ! V_32 [ V_37 ] ||
! F_22 ( V_32 , V_38 ) ||
! F_22 ( V_32 , V_39 ) ) )
return - V_40 ;
if ( V_32 [ V_41 ] )
* V_33 = F_23 ( V_32 [ V_41 ] ) ;
V_4 = F_24 ( F_25 ( V_32 [ V_37 ] ) , & V_36 ) ;
if ( V_4 == V_23 )
return - V_42 ;
if ( V_36 -> type -> V_43 & V_44 ) {
V_21 = - V_45 ;
goto V_46;
}
if ( V_32 [ V_39 ] ) {
T_1 V_47 = F_26 ( V_32 [ V_39 ] ) ;
V_34 = V_47 & V_48 ;
}
if ( V_34 && ! V_32 [ V_49 ] ) {
V_21 = - V_50 ;
goto V_46;
}
if ( V_32 [ V_49 ] ) {
V_35 = F_24 ( F_25 ( V_32 [ V_49 ] ) ,
& V_36 ) ;
if ( V_35 == V_23 ) {
V_21 = - V_51 ;
goto V_46;
}
if ( ! V_34 )
V_34 = - 1 ;
}
if ( V_32 [ V_38 ] ) {
if ( ! F_8 ) {
V_21 = - V_52 ;
goto V_46;
}
V_9 = F_27 ( V_32 [ V_38 ] ) ;
}
switch ( V_15 ) {
case V_24 :
for ( V_20 = 0 ; V_20 < V_3 -> V_22 && ! V_21 ; V_20 ++ ) {
V_8 = F_1 ( V_3 , V_20 ) ;
if ( V_8 -> V_4 == V_23 ||
( V_34 != 0 && V_20 + 1 >= V_3 -> V_22 ) )
break;
else if ( F_8 && F_5 ( V_3 , V_20 ) )
continue;
else if ( V_34 > 0 && V_8 -> V_4 == V_4 )
V_21 = F_12 ( V_3 , V_20 , V_35 ) ;
else if ( V_34 < 0 && V_8 -> V_4 == V_35 )
V_21 = F_12 ( V_3 , V_20 , V_4 ) ;
else if ( V_34 == 0 && V_8 -> V_4 == V_4 )
V_21 = 1 ;
}
break;
case V_25 :
for ( V_20 = 0 ; V_20 < V_3 -> V_22 && ! V_21 ; V_20 ++ ) {
V_8 = F_1 ( V_3 , V_20 ) ;
if ( V_8 -> V_4 == V_4 &&
! ( F_8 && F_5 ( V_3 , V_20 ) ) )
V_21 = - V_53 ;
}
if ( V_21 == - V_53 )
break;
V_21 = - V_54 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_22 && V_21 == - V_54 ; V_20 ++ ) {
V_8 = F_1 ( V_3 , V_20 ) ;
if ( V_8 -> V_4 == V_23 )
V_21 = V_34 != 0 ? - V_55
: F_16 ( V_3 , V_20 , V_4 , V_9 ) ;
else if ( V_8 -> V_4 != V_35 )
continue;
else if ( F_8 && F_5 ( V_3 , V_20 ) )
V_21 = - V_55 ;
else if ( V_34 )
V_21 = F_16 ( V_3 , V_20 , V_4 , V_9 ) ;
else if ( V_20 + 1 < V_3 -> V_22 )
V_21 = F_16 ( V_3 , V_20 + 1 , V_4 , V_9 ) ;
}
break;
case V_26 :
V_21 = - V_53 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_22 && V_21 == - V_53 ; V_20 ++ ) {
V_8 = F_1 ( V_3 , V_20 ) ;
if ( V_8 -> V_4 == V_23 ) {
V_21 = V_34 != 0 ? - V_55
: - V_53 ;
break;
} else if ( F_8 && F_5 ( V_3 , V_20 ) )
continue;
else if ( V_8 -> V_4 == V_4 &&
( V_34 == 0 ||
( V_34 > 0 &&
F_12 ( V_3 , V_20 , V_35 ) ) ) )
V_21 = F_19 ( V_3 , V_20 ) ;
else if ( V_34 < 0 &&
V_8 -> V_4 == V_35 &&
F_12 ( V_3 , V_20 , V_4 ) )
V_21 = F_19 ( V_3 , V_20 + 1 ) ;
}
break;
default:
break;
}
V_46:
if ( V_35 != V_23 )
F_17 ( V_35 ) ;
if ( V_15 != V_25 || V_21 )
F_17 ( V_4 ) ;
return F_28 ( V_21 , V_18 ) ? 0 : V_21 ;
}
static void
F_29 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_19 ;
struct V_1 * V_8 ;
T_1 V_20 ;
for ( V_20 = 0 ; V_20 < V_3 -> V_22 ; V_20 ++ ) {
V_8 = F_1 ( V_3 , V_20 ) ;
if ( V_8 -> V_4 != V_23 ) {
F_17 ( V_8 -> V_4 ) ;
V_8 -> V_4 = V_23 ;
}
}
}
static void
F_30 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_19 ;
if ( F_8 ( V_3 -> V_9 ) )
F_31 ( & V_3 -> V_56 ) ;
F_29 ( V_11 ) ;
F_32 ( V_3 ) ;
V_11 -> V_19 = NULL ;
}
static int
F_33 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
const struct V_2 * V_3 = V_11 -> V_19 ;
struct V_31 * V_57 ;
V_57 = F_34 ( V_13 , V_58 ) ;
if ( ! V_57 )
goto V_59;
F_35 ( V_13 , V_60 , F_36 ( V_3 -> V_22 ) ) ;
if ( F_8 ( V_3 -> V_9 ) )
F_35 ( V_13 , V_38 , F_36 ( V_3 -> V_9 ) ) ;
F_35 ( V_13 , V_61 , F_36 ( V_11 -> V_62 - 1 ) ) ;
F_35 ( V_13 , V_63 ,
F_36 ( sizeof( * V_3 ) + V_3 -> V_22 * V_3 -> V_6 ) ) ;
F_37 ( V_13 , V_57 ) ;
return 0 ;
V_59:
return - V_64 ;
}
static int
F_38 ( const struct V_10 * V_11 ,
struct V_12 * V_13 , struct V_65 * V_66 )
{
const struct V_2 * V_3 = V_11 -> V_19 ;
struct V_31 * V_67 , * V_57 ;
T_1 V_20 , V_68 = V_66 -> args [ 2 ] ;
const struct V_1 * V_28 ;
V_67 = F_34 ( V_13 , V_69 ) ;
if ( ! V_67 )
return - V_64 ;
for (; V_66 -> args [ 2 ] < V_3 -> V_22 ; V_66 -> args [ 2 ] ++ ) {
V_20 = V_66 -> args [ 2 ] ;
V_28 = F_1 ( V_3 , V_20 ) ;
if ( V_28 -> V_4 == V_23 )
goto V_46;
if ( F_8 ( V_3 -> V_9 ) && F_5 ( V_3 , V_20 ) )
continue;
V_57 = F_34 ( V_13 , V_58 ) ;
if ( ! V_57 ) {
if ( V_20 == V_68 ) {
F_39 ( V_13 , V_67 ) ;
return - V_64 ;
} else
goto V_59;
}
F_40 ( V_13 , V_37 ,
F_41 ( V_28 -> V_4 ) ) ;
if ( F_8 ( V_3 -> V_9 ) ) {
const struct V_7 * V_70 =
( const struct V_7 * ) V_28 ;
F_35 ( V_13 , V_38 ,
F_36 ( F_42 ( V_70 -> V_9 ) ) ) ;
}
F_37 ( V_13 , V_57 ) ;
}
V_46:
F_37 ( V_13 , V_67 ) ;
V_66 -> args [ 2 ] = 0 ;
return 0 ;
V_59:
F_39 ( V_13 , V_57 ) ;
F_37 ( V_13 , V_67 ) ;
if ( F_21 ( V_20 == V_68 ) ) {
V_66 -> args [ 2 ] = 0 ;
return - V_64 ;
}
return 0 ;
}
static bool
F_43 ( const struct V_10 * V_29 , const struct V_10 * V_30 )
{
const struct V_2 * V_71 = V_29 -> V_19 ;
const struct V_2 * V_72 = V_30 -> V_19 ;
return V_71 -> V_22 == V_72 -> V_22 &&
V_71 -> V_9 == V_72 -> V_9 ;
}
static void
F_44 ( unsigned long V_73 )
{
struct V_10 * V_11 = (struct V_10 * ) V_73 ;
struct V_2 * V_3 = V_11 -> V_19 ;
struct V_7 * V_28 ;
T_1 V_20 ;
F_45 ( & V_11 -> V_74 ) ;
for ( V_20 = 0 ; V_20 < V_3 -> V_22 ; V_20 ++ ) {
V_28 = F_2 ( V_3 , V_20 ) ;
if ( V_28 -> V_4 != V_23 && F_5 ( V_3 , V_20 ) )
F_19 ( V_3 , V_20 ) ;
}
F_46 ( & V_11 -> V_74 ) ;
V_3 -> V_56 . V_75 = V_76 + F_47 ( V_3 -> V_9 ) * V_77 ;
F_48 ( & V_3 -> V_56 ) ;
}
static void
F_49 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_19 ;
F_50 ( & V_3 -> V_56 ) ;
V_3 -> V_56 . V_19 = ( unsigned long ) V_11 ;
V_3 -> V_56 . V_78 = F_44 ;
V_3 -> V_56 . V_75 = V_76 + F_47 ( V_3 -> V_9 ) * V_77 ;
F_48 ( & V_3 -> V_56 ) ;
}
static bool
F_51 ( struct V_10 * V_11 , T_1 V_22 , T_4 V_6 ,
unsigned long V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_28 ;
T_1 V_20 ;
V_3 = F_52 ( sizeof( * V_3 ) + V_22 * V_6 , V_79 ) ;
if ( ! V_3 )
return false ;
V_3 -> V_22 = V_22 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_9 = V_9 ;
V_11 -> V_19 = V_3 ;
for ( V_20 = 0 ; V_20 < V_22 ; V_20 ++ ) {
V_28 = F_1 ( V_3 , V_20 ) ;
V_28 -> V_4 = V_23 ;
}
return true ;
}
static int
F_53 ( struct V_10 * V_11 , struct V_31 * V_32 [] , T_1 V_18 )
{
T_1 V_22 = V_80 ;
if ( F_21 ( ! F_22 ( V_32 , V_60 ) ||
! F_22 ( V_32 , V_38 ) ) )
return - V_40 ;
if ( V_32 [ V_60 ] )
V_22 = F_26 ( V_32 [ V_60 ] ) ;
if ( V_22 < V_81 )
V_22 = V_81 ;
if ( V_32 [ V_38 ] ) {
if ( ! F_51 ( V_11 , V_22 , sizeof( struct V_7 ) ,
F_27 ( V_32 [ V_38 ] ) ) )
return - V_82 ;
F_49 ( V_11 ) ;
} else {
if ( ! F_51 ( V_11 , V_22 , sizeof( struct V_1 ) ,
V_83 ) )
return - V_82 ;
}
V_11 -> V_84 = & V_2 ;
return 0 ;
}
static int T_5
F_54 ( void )
{
return F_55 ( & V_85 ) ;
}
static void T_6
F_56 ( void )
{
F_57 ( & V_85 ) ;
}
