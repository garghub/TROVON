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
const struct V_14 * V_15 ,
enum V_16 V_17 , const struct V_18 * V_19 )
{
struct V_2 * V_3 = V_11 -> V_20 ;
struct V_1 * V_8 ;
T_1 V_21 ;
int V_22 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_23 ; V_21 ++ ) {
V_8 = F_1 ( V_3 , V_21 ) ;
if ( V_8 -> V_4 == V_24 )
return 0 ;
if ( F_8 ( V_3 -> V_9 ) && F_5 ( V_3 , V_21 ) )
continue;
switch ( V_17 ) {
case V_25 :
V_22 = F_9 ( V_8 -> V_4 , V_13 , V_15 , V_19 ) ;
if ( V_22 > 0 )
return V_22 ;
break;
case V_26 :
V_22 = F_10 ( V_8 -> V_4 , V_13 , V_15 , V_19 ) ;
if ( V_22 == 0 )
return V_22 ;
break;
case V_27 :
V_22 = F_11 ( V_8 -> V_4 , V_13 , V_15 , V_19 ) ;
if ( V_22 == 0 )
return V_22 ;
break;
default:
break;
}
}
return - V_28 ;
}
static bool
F_12 ( const struct V_2 * V_3 , T_1 V_21 , T_2 V_4 )
{
const struct V_1 * V_8 ;
if ( V_21 < V_3 -> V_23 ) {
V_8 = F_1 ( V_3 , V_21 ) ;
return V_8 -> V_4 == V_4 ;
}
return 0 ;
}
static bool
F_13 ( const struct V_2 * V_3 , T_1 V_21 , T_2 V_4 )
{
const struct V_1 * V_8 ;
if ( V_21 < V_3 -> V_23 ) {
V_8 = F_1 ( V_3 , V_21 ) ;
return ! ! ( V_8 -> V_4 == V_4 &&
! ( F_8 ( V_3 -> V_9 ) &&
F_5 ( V_3 , V_21 ) ) ) ;
}
return 0 ;
}
static void
F_14 ( struct V_2 * V_3 , T_1 V_21 , T_2 V_4 )
{
struct V_1 * V_29 ;
for (; V_21 < V_3 -> V_23 ; V_21 ++ ) {
V_29 = F_1 ( V_3 , V_21 ) ;
F_15 ( V_29 -> V_4 , V_4 ) ;
if ( V_29 -> V_4 == V_24 )
break;
}
}
static void
F_16 ( struct V_2 * V_3 , T_1 V_21 , T_2 V_4 ,
unsigned long V_9 )
{
struct V_7 * V_29 ;
for (; V_21 < V_3 -> V_23 ; V_21 ++ ) {
V_29 = F_2 ( V_3 , V_21 ) ;
F_15 ( V_29 -> V_4 , V_4 ) ;
F_15 ( V_29 -> V_9 , V_9 ) ;
if ( V_29 -> V_4 == V_24 )
break;
}
}
static int
F_17 ( struct V_2 * V_3 , T_1 V_21 , T_2 V_4 ,
unsigned long V_9 )
{
const struct V_1 * V_29 = F_1 ( V_3 , V_21 ) ;
if ( V_29 -> V_4 != V_24 ) {
const struct V_1 * V_30 = F_1 ( V_3 , V_3 -> V_23 - 1 ) ;
if ( V_30 -> V_4 != V_24 )
F_18 ( V_30 -> V_4 ) ;
}
if ( F_8 ( V_3 -> V_9 ) )
F_16 ( V_3 , V_21 , V_4 , F_19 ( V_9 ) ) ;
else
F_14 ( V_3 , V_21 , V_4 ) ;
return 0 ;
}
static int
F_20 ( struct V_2 * V_3 , T_1 V_21 )
{
struct V_1 * V_31 = F_1 ( V_3 , V_21 ) , * V_32 ;
F_18 ( V_31 -> V_4 ) ;
for (; V_21 < V_3 -> V_23 - 1 ; V_21 ++ ) {
V_32 = F_1 ( V_3 , V_21 + 1 ) ;
V_31 -> V_4 = V_32 -> V_4 ;
if ( F_8 ( V_3 -> V_9 ) )
( (struct V_7 * ) V_31 ) -> V_9 =
( (struct V_7 * ) V_32 ) -> V_9 ;
V_31 = V_32 ;
if ( V_31 -> V_4 == V_24 )
break;
}
V_31 -> V_4 = V_24 ;
return 0 ;
}
static void
F_21 ( struct V_2 * V_3 )
{
struct V_7 * V_29 ;
T_1 V_21 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_23 ; V_21 ++ ) {
V_29 = F_2 ( V_3 , V_21 ) ;
if ( V_29 -> V_4 != V_24 && F_5 ( V_3 , V_21 ) )
F_20 ( V_3 , V_21 ) ;
}
}
static int
F_22 ( struct V_10 * V_11 , struct V_33 * V_34 [] ,
enum V_16 V_17 , T_1 * V_35 , T_1 V_36 , bool V_37 )
{
struct V_2 * V_3 = V_11 -> V_20 ;
bool F_8 = F_8 ( V_3 -> V_9 ) ;
bool V_38 = V_36 & V_39 ;
int V_40 = 0 ;
T_1 V_9 = V_3 -> V_9 ;
T_2 V_4 , V_41 = V_24 ;
const struct V_1 * V_8 ;
struct V_10 * V_42 ;
T_1 V_21 ;
int V_22 = 0 ;
if ( F_23 ( ! V_34 [ V_43 ] ||
! F_24 ( V_34 , V_44 ) ||
! F_24 ( V_34 , V_45 ) ) )
return - V_46 ;
if ( V_34 [ V_47 ] )
* V_35 = F_25 ( V_34 [ V_47 ] ) ;
V_4 = F_26 ( F_27 ( V_34 [ V_43 ] ) , & V_42 ) ;
if ( V_4 == V_24 )
return - V_48 ;
if ( V_42 -> type -> V_49 & V_50 ) {
V_22 = - V_51 ;
goto V_52;
}
if ( V_34 [ V_45 ] ) {
T_1 V_53 = F_28 ( V_34 [ V_45 ] ) ;
V_40 = V_53 & V_54 ;
}
if ( V_40 && ! V_34 [ V_55 ] ) {
V_22 = - V_56 ;
goto V_52;
}
if ( V_34 [ V_55 ] ) {
V_41 = F_26 ( F_27 ( V_34 [ V_55 ] ) ,
& V_42 ) ;
if ( V_41 == V_24 ) {
V_22 = - V_57 ;
goto V_52;
}
if ( ! V_40 )
V_40 = - 1 ;
}
if ( V_34 [ V_44 ] ) {
if ( ! F_8 ) {
V_22 = - V_58 ;
goto V_52;
}
V_9 = F_29 ( V_34 [ V_44 ] ) ;
}
if ( F_8 && V_17 != V_25 )
F_21 ( V_3 ) ;
switch ( V_17 ) {
case V_25 :
for ( V_21 = 0 ; V_21 < V_3 -> V_23 && ! V_22 ; V_21 ++ ) {
V_8 = F_1 ( V_3 , V_21 ) ;
if ( V_8 -> V_4 == V_24 ||
( V_40 != 0 && V_21 + 1 >= V_3 -> V_23 ) )
break;
else if ( F_8 && F_5 ( V_3 , V_21 ) )
continue;
else if ( V_40 > 0 && V_8 -> V_4 == V_4 )
V_22 = F_13 ( V_3 , V_21 + 1 , V_41 ) ;
else if ( V_40 < 0 && V_8 -> V_4 == V_41 )
V_22 = F_13 ( V_3 , V_21 + 1 , V_4 ) ;
else if ( V_40 == 0 && V_8 -> V_4 == V_4 )
V_22 = 1 ;
}
break;
case V_26 :
for ( V_21 = 0 ; V_21 < V_3 -> V_23 ; V_21 ++ ) {
V_8 = F_1 ( V_3 , V_21 ) ;
if ( V_8 -> V_4 != V_4 )
continue;
if ( ! ( F_8 && V_38 ) ) {
V_22 = - V_59 ;
goto V_52;
} else {
struct V_7 * V_29 = F_2 ( V_3 , V_21 ) ;
if ( ( V_40 > 1 &&
! F_12 ( V_3 , V_21 + 1 , V_41 ) ) ||
( V_40 < 0 &&
( V_21 == 0 || ! F_12 ( V_3 , V_21 - 1 , V_41 ) ) ) ) {
V_22 = - V_59 ;
goto V_52;
}
V_29 -> V_9 = F_19 ( V_9 ) ;
F_18 ( V_4 ) ;
V_22 = 0 ;
goto V_52;
}
}
V_22 = - V_60 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_23 && V_22 == - V_60 ; V_21 ++ ) {
V_8 = F_1 ( V_3 , V_21 ) ;
if ( V_8 -> V_4 == V_24 )
V_22 = V_40 != 0 ? - V_61
: F_17 ( V_3 , V_21 , V_4 , V_9 ) ;
else if ( V_8 -> V_4 != V_41 )
continue;
else if ( V_40 > 0 )
V_22 = F_17 ( V_3 , V_21 , V_4 , V_9 ) ;
else if ( V_21 + 1 < V_3 -> V_23 )
V_22 = F_17 ( V_3 , V_21 + 1 , V_4 , V_9 ) ;
}
break;
case V_27 :
V_22 = - V_59 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_23 && V_22 == - V_59 ; V_21 ++ ) {
V_8 = F_1 ( V_3 , V_21 ) ;
if ( V_8 -> V_4 == V_24 ) {
V_22 = V_40 != 0 ? - V_61
: - V_59 ;
break;
} else if ( V_8 -> V_4 == V_4 &&
( V_40 == 0 ||
( V_40 > 0 && F_12 ( V_3 , V_21 + 1 , V_41 ) ) ) )
V_22 = F_20 ( V_3 , V_21 ) ;
else if ( V_8 -> V_4 == V_41 &&
V_40 < 0 && F_12 ( V_3 , V_21 + 1 , V_4 ) )
V_22 = F_20 ( V_3 , V_21 + 1 ) ;
}
break;
default:
break;
}
V_52:
if ( V_41 != V_24 )
F_18 ( V_41 ) ;
if ( V_17 != V_26 || V_22 )
F_18 ( V_4 ) ;
return F_30 ( V_22 , V_36 ) ? 0 : V_22 ;
}
static void
F_31 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_20 ;
struct V_1 * V_8 ;
T_1 V_21 ;
for ( V_21 = 0 ; V_21 < V_3 -> V_23 ; V_21 ++ ) {
V_8 = F_1 ( V_3 , V_21 ) ;
if ( V_8 -> V_4 != V_24 ) {
F_18 ( V_8 -> V_4 ) ;
V_8 -> V_4 = V_24 ;
}
}
}
static void
F_32 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_20 ;
if ( F_8 ( V_3 -> V_9 ) )
F_33 ( & V_3 -> V_62 ) ;
F_31 ( V_11 ) ;
F_34 ( V_3 ) ;
V_11 -> V_20 = NULL ;
}
static int
F_35 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
const struct V_2 * V_3 = V_11 -> V_20 ;
struct V_33 * V_63 ;
V_63 = F_36 ( V_13 , V_64 ) ;
if ( ! V_63 )
goto V_65;
if ( F_37 ( V_13 , V_66 , F_38 ( V_3 -> V_23 ) ) ||
( F_8 ( V_3 -> V_9 ) &&
F_37 ( V_13 , V_44 , F_38 ( V_3 -> V_9 ) ) ) ||
F_37 ( V_13 , V_67 , F_38 ( V_11 -> V_68 - 1 ) ) ||
F_37 ( V_13 , V_69 ,
F_38 ( sizeof( * V_3 ) + V_3 -> V_23 * V_3 -> V_6 ) ) )
goto V_65;
F_39 ( V_13 , V_63 ) ;
return 0 ;
V_65:
return - V_70 ;
}
static int
F_40 ( const struct V_10 * V_11 ,
struct V_12 * V_13 , struct V_71 * V_72 )
{
const struct V_2 * V_3 = V_11 -> V_20 ;
struct V_33 * V_73 , * V_63 ;
T_1 V_21 , V_74 = V_72 -> args [ 2 ] ;
const struct V_1 * V_29 ;
V_73 = F_36 ( V_13 , V_75 ) ;
if ( ! V_73 )
return - V_70 ;
for (; V_72 -> args [ 2 ] < V_3 -> V_23 ; V_72 -> args [ 2 ] ++ ) {
V_21 = V_72 -> args [ 2 ] ;
V_29 = F_1 ( V_3 , V_21 ) ;
if ( V_29 -> V_4 == V_24 )
goto V_52;
if ( F_8 ( V_3 -> V_9 ) && F_5 ( V_3 , V_21 ) )
continue;
V_63 = F_36 ( V_13 , V_64 ) ;
if ( ! V_63 ) {
if ( V_21 == V_74 ) {
F_41 ( V_13 , V_73 ) ;
return - V_70 ;
} else
goto V_65;
}
if ( F_42 ( V_13 , V_43 ,
F_43 ( V_29 -> V_4 ) ) )
goto V_65;
if ( F_8 ( V_3 -> V_9 ) ) {
const struct V_7 * V_76 =
( const struct V_7 * ) V_29 ;
T_3 V_77 = F_38 ( F_44 ( V_76 -> V_9 ) ) ;
if ( F_37 ( V_13 , V_44 , V_77 ) )
goto V_65;
}
F_39 ( V_13 , V_63 ) ;
}
V_52:
F_39 ( V_13 , V_73 ) ;
V_72 -> args [ 2 ] = 0 ;
return 0 ;
V_65:
F_41 ( V_13 , V_63 ) ;
F_39 ( V_13 , V_73 ) ;
if ( F_23 ( V_21 == V_74 ) ) {
V_72 -> args [ 2 ] = 0 ;
return - V_70 ;
}
return 0 ;
}
static bool
F_45 ( const struct V_10 * V_31 , const struct V_10 * V_32 )
{
const struct V_2 * V_30 = V_31 -> V_20 ;
const struct V_2 * V_78 = V_32 -> V_20 ;
return V_30 -> V_23 == V_78 -> V_23 &&
V_30 -> V_9 == V_78 -> V_9 ;
}
static void
F_46 ( unsigned long V_79 )
{
struct V_10 * V_11 = (struct V_10 * ) V_79 ;
struct V_2 * V_3 = V_11 -> V_20 ;
F_47 ( & V_11 -> V_80 ) ;
F_21 ( V_3 ) ;
F_48 ( & V_11 -> V_80 ) ;
V_3 -> V_62 . V_81 = V_82 + F_49 ( V_3 -> V_9 ) * V_83 ;
F_50 ( & V_3 -> V_62 ) ;
}
static void
F_51 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = V_11 -> V_20 ;
F_52 ( & V_3 -> V_62 ) ;
V_3 -> V_62 . V_20 = ( unsigned long ) V_11 ;
V_3 -> V_62 . V_84 = F_46 ;
V_3 -> V_62 . V_81 = V_82 + F_49 ( V_3 -> V_9 ) * V_83 ;
F_50 ( & V_3 -> V_62 ) ;
}
static bool
F_53 ( struct V_10 * V_11 , T_1 V_23 , T_4 V_6 ,
unsigned long V_9 )
{
struct V_2 * V_3 ;
struct V_1 * V_29 ;
T_1 V_21 ;
V_3 = F_54 ( sizeof( * V_3 ) + V_23 * V_6 , V_85 ) ;
if ( ! V_3 )
return false ;
V_3 -> V_23 = V_23 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_9 = V_9 ;
V_11 -> V_20 = V_3 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ ) {
V_29 = F_1 ( V_3 , V_21 ) ;
V_29 -> V_4 = V_24 ;
}
return true ;
}
static int
F_55 ( struct V_10 * V_11 , struct V_33 * V_34 [] , T_1 V_36 )
{
T_1 V_23 = V_86 ;
if ( F_23 ( ! F_24 ( V_34 , V_66 ) ||
! F_24 ( V_34 , V_44 ) ) )
return - V_46 ;
if ( V_34 [ V_66 ] )
V_23 = F_28 ( V_34 [ V_66 ] ) ;
if ( V_23 < V_87 )
V_23 = V_87 ;
if ( V_34 [ V_44 ] ) {
if ( ! F_53 ( V_11 , V_23 , sizeof( struct V_7 ) ,
F_29 ( V_34 [ V_44 ] ) ) )
return - V_88 ;
F_51 ( V_11 ) ;
} else {
if ( ! F_53 ( V_11 , V_23 , sizeof( struct V_1 ) ,
V_89 ) )
return - V_88 ;
}
V_11 -> V_90 = & V_2 ;
return 0 ;
}
static int T_5
F_56 ( void )
{
return F_57 ( & V_91 ) ;
}
static void T_6
F_58 ( void )
{
F_59 ( & V_91 ) ;
}
