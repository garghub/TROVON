static inline struct V_1 *
F_1 ( const struct V_2 * V_3 , T_1 V_4 )
{
return (struct V_1 * ) ( ( void * ) V_3 -> V_5 + V_4 * V_3 -> V_6 ) ;
}
static int
F_2 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_13 * V_14 , const struct V_15 * V_16 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_1 * V_18 ;
T_1 V_19 , V_20 = V_14 -> V_20 ;
int V_21 ;
V_14 -> V_20 &= ~ V_22 ;
if ( V_14 -> V_20 & V_23 )
V_14 -> V_20 &= ~ V_24 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
return 0 ;
if ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
continue;
V_21 = F_6 ( V_18 -> V_4 , V_10 , V_12 , V_14 ) ;
if ( V_21 > 0 ) {
if ( F_7 ( V_8 ) )
F_8 ( F_9 ( V_18 , V_3 ) ,
V_16 , & V_14 -> V_16 ,
V_20 ) ;
return V_21 ;
}
}
return 0 ;
}
static int
F_10 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_13 * V_14 , const struct V_15 * V_16 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_1 * V_18 ;
T_1 V_19 ;
int V_21 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
return 0 ;
if ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
continue;
V_21 = F_11 ( V_18 -> V_4 , V_10 , V_12 , V_14 ) ;
if ( V_21 == 0 )
return V_21 ;
}
return 0 ;
}
static int
F_12 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
struct V_13 * V_14 , const struct V_15 * V_16 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_1 * V_18 ;
T_1 V_19 ;
int V_21 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
return 0 ;
if ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
continue;
V_21 = F_13 ( V_18 -> V_4 , V_10 , V_12 , V_14 ) ;
if ( V_21 == 0 )
return V_21 ;
}
return 0 ;
}
static int
F_14 ( struct V_7 * V_8 , const struct V_9 * V_10 ,
const struct V_11 * V_12 ,
enum V_27 V_28 , struct V_13 * V_14 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_15 V_16 = F_15 ( V_10 , V_14 , V_3 ) ;
switch ( V_28 ) {
case V_29 :
return F_2 ( V_8 , V_10 , V_12 , V_14 , & V_16 ) ;
case V_30 :
return F_10 ( V_8 , V_10 , V_12 , V_14 , & V_16 ) ;
case V_31 :
return F_12 ( V_8 , V_10 , V_12 , V_14 , & V_16 ) ;
default:
break;
}
return - V_32 ;
}
static bool
F_16 ( const struct V_7 * V_8 , T_1 V_19 , T_2 V_4 )
{
const struct V_2 * V_3 = V_8 -> V_17 ;
const struct V_1 * V_18 ;
if ( V_19 >= V_3 -> V_25 )
return 0 ;
V_18 = F_1 ( V_3 , V_19 ) ;
return ! ! ( V_18 -> V_4 == V_4 &&
! ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) ) ) ;
}
static int
F_17 ( struct V_7 * V_8 , T_1 V_19 , struct V_33 * V_34 ,
const struct V_15 * V_16 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_1 * V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 != V_26 ) {
if ( V_19 == V_3 -> V_25 - 1 )
F_18 ( V_18 -> V_4 ) ;
else {
struct V_1 * V_35 = F_1 ( V_3 , V_3 -> V_25 - 1 ) ;
if ( V_35 -> V_4 != V_26 )
F_18 ( V_35 -> V_4 ) ;
memmove ( F_1 ( V_3 , V_19 + 1 ) , V_18 ,
V_3 -> V_6 * ( V_3 -> V_25 - ( V_19 + 1 ) ) ) ;
}
}
V_18 -> V_4 = V_34 -> V_4 ;
if ( F_3 ( V_8 ) )
F_19 ( F_5 ( V_18 , V_3 ) , V_16 -> V_36 ) ;
if ( F_7 ( V_8 ) )
F_20 ( F_9 ( V_18 , V_3 ) , V_16 ) ;
return 0 ;
}
static int
F_21 ( struct V_7 * V_8 , T_1 V_19 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_1 * V_18 = F_1 ( V_3 , V_19 ) ;
F_18 ( V_18 -> V_4 ) ;
if ( V_19 < V_3 -> V_25 - 1 )
memmove ( V_18 , F_1 ( V_3 , V_19 + 1 ) ,
V_3 -> V_6 * ( V_3 -> V_25 - ( V_19 + 1 ) ) ) ;
V_18 = F_1 ( V_3 , V_3 -> V_25 - 1 ) ;
V_18 -> V_4 = V_26 ;
return 0 ;
}
static void
F_22 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_1 * V_18 ;
T_1 V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 != V_26 &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
F_21 ( V_8 , V_19 ) ;
}
}
static int
F_23 ( struct V_7 * V_8 , void * V_37 , const struct V_15 * V_16 ,
struct V_15 * V_38 , T_1 V_39 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_33 * V_34 = V_37 ;
struct V_1 * V_18 ;
T_1 V_19 ;
int V_21 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
return 0 ;
else if ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
continue;
else if ( V_18 -> V_4 != V_34 -> V_4 )
continue;
if ( V_34 -> V_40 == 0 )
return 1 ;
else if ( V_34 -> V_40 > 0 )
V_21 = F_16 ( V_8 , V_19 + 1 , V_34 -> V_41 ) ;
else
V_21 = V_19 > 0 && F_16 ( V_8 , V_19 - 1 , V_34 -> V_41 ) ;
return V_21 ;
}
return 0 ;
}
static int
F_24 ( struct V_7 * V_8 , void * V_37 , const struct V_15 * V_16 ,
struct V_15 * V_38 , T_1 V_39 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_33 * V_34 = V_37 ;
struct V_1 * V_18 ;
bool V_42 = V_39 & V_43 ;
T_1 V_19 , V_21 = 0 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
goto V_44;
else if ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
continue;
else if ( V_18 -> V_4 != V_34 -> V_4 )
continue;
if ( ( V_34 -> V_40 > 1 && ! F_16 ( V_8 , V_19 + 1 , V_34 -> V_41 ) ) ||
( V_34 -> V_40 < 0 &&
( V_19 == 0 || ! F_16 ( V_8 , V_19 - 1 , V_34 -> V_41 ) ) ) )
return - V_45 ;
if ( ! V_42 )
return - V_46 ;
if ( F_3 ( V_8 ) )
F_19 ( F_5 ( V_18 , V_3 ) , V_16 -> V_36 ) ;
if ( F_7 ( V_8 ) )
F_20 ( F_9 ( V_18 , V_3 ) , V_16 ) ;
F_18 ( V_34 -> V_4 ) ;
return 0 ;
}
V_44:
V_21 = - V_47 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 && V_21 == - V_47 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
V_21 = V_34 -> V_40 != 0 ? - V_45
: F_17 ( V_8 , V_19 , V_34 , V_16 ) ;
else if ( V_18 -> V_4 != V_34 -> V_41 )
continue;
else if ( V_34 -> V_40 > 0 )
V_21 = F_17 ( V_8 , V_19 , V_34 , V_16 ) ;
else if ( V_19 + 1 < V_3 -> V_25 )
V_21 = F_17 ( V_8 , V_19 + 1 , V_34 , V_16 ) ;
}
return V_21 ;
}
static int
F_25 ( struct V_7 * V_8 , void * V_37 , const struct V_15 * V_16 ,
struct V_15 * V_38 , T_1 V_39 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_33 * V_34 = V_37 ;
struct V_1 * V_18 ;
T_1 V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
return V_34 -> V_40 != 0 ? - V_45
: - V_46 ;
else if ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
continue;
else if ( V_18 -> V_4 != V_34 -> V_4 )
continue;
if ( V_34 -> V_40 == 0 )
return F_21 ( V_8 , V_19 ) ;
else if ( V_34 -> V_40 > 0 ) {
if ( ! F_16 ( V_8 , V_19 + 1 , V_34 -> V_41 ) )
return - V_45 ;
return F_21 ( V_8 , V_19 ) ;
} else if ( V_19 == 0 || ! F_16 ( V_8 , V_19 - 1 , V_34 -> V_41 ) )
return - V_45 ;
else
return F_21 ( V_8 , V_19 ) ;
}
return - V_46 ;
}
static int
F_26 ( struct V_7 * V_8 , struct V_48 * V_49 [] ,
enum V_27 V_28 , T_1 * V_50 , T_1 V_39 , bool V_51 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
T_3 V_52 = V_8 -> V_53 -> V_28 [ V_28 ] ;
struct V_33 V_18 = { . V_41 = V_26 } ;
struct V_15 V_16 = F_27 ( V_3 ) ;
struct V_7 * V_54 ;
int V_21 = 0 ;
if ( F_28 ( ! V_49 [ V_55 ] ||
! F_29 ( V_49 , V_56 ) ||
! F_29 ( V_49 , V_57 ) ||
! F_29 ( V_49 , V_58 ) ||
! F_29 ( V_49 , V_59 ) ) )
return - V_60 ;
if ( V_49 [ V_61 ] )
* V_50 = F_30 ( V_49 [ V_61 ] ) ;
V_21 = F_31 ( V_8 , V_49 , & V_16 ) ;
if ( V_21 )
return V_21 ;
V_18 . V_4 = F_32 ( F_33 ( V_49 [ V_55 ] ) , & V_54 ) ;
if ( V_18 . V_4 == V_26 )
return - V_62 ;
if ( V_54 -> type -> V_63 & V_64 ) {
V_21 = - V_65 ;
goto V_66;
}
if ( V_49 [ V_57 ] ) {
T_1 V_67 = F_34 ( V_49 [ V_57 ] ) ;
V_18 . V_40 = V_67 & V_68 ;
}
if ( V_18 . V_40 && ! V_49 [ V_69 ] ) {
V_21 = - V_70 ;
goto V_66;
}
if ( V_49 [ V_69 ] ) {
V_18 . V_41 = F_32 ( F_33 ( V_49 [ V_69 ] ) ,
& V_54 ) ;
if ( V_18 . V_41 == V_26 ) {
V_21 = - V_71 ;
goto V_66;
}
if ( ! V_18 . V_40 )
V_18 . V_40 = - 1 ;
}
if ( V_28 != V_29 && F_3 ( V_8 ) )
F_22 ( V_8 ) ;
V_21 = V_52 ( V_8 , & V_18 , & V_16 , & V_16 , V_39 ) ;
V_66:
if ( V_18 . V_41 != V_26 )
F_18 ( V_18 . V_41 ) ;
if ( V_28 != V_30 || V_21 )
F_18 ( V_18 . V_4 ) ;
return F_35 ( V_21 , V_39 ) ? 0 : V_21 ;
}
static void
F_36 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
struct V_1 * V_18 ;
T_1 V_19 ;
for ( V_19 = 0 ; V_19 < V_3 -> V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 != V_26 ) {
F_18 ( V_18 -> V_4 ) ;
V_18 -> V_4 = V_26 ;
}
}
}
static void
F_37 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_17 ;
if ( F_3 ( V_8 ) )
F_38 ( & V_3 -> V_72 ) ;
F_36 ( V_8 ) ;
F_39 ( V_3 ) ;
V_8 -> V_17 = NULL ;
}
static int
F_40 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
const struct V_2 * V_3 = V_8 -> V_17 ;
struct V_48 * V_73 ;
V_73 = F_41 ( V_10 , V_74 ) ;
if ( ! V_73 )
goto V_75;
if ( F_42 ( V_10 , V_76 , F_43 ( V_3 -> V_25 ) ) ||
( F_3 ( V_8 ) &&
F_42 ( V_10 , V_56 , F_43 ( V_3 -> V_36 ) ) ) ||
( F_7 ( V_8 ) &&
F_42 ( V_10 , V_57 ,
F_43 ( V_77 ) ) ) ||
F_42 ( V_10 , V_78 , F_43 ( V_8 -> V_79 - 1 ) ) ||
F_42 ( V_10 , V_80 ,
F_43 ( sizeof( * V_3 ) + V_3 -> V_25 * V_3 -> V_6 ) ) )
goto V_75;
F_44 ( V_10 , V_73 ) ;
return 0 ;
V_75:
return - V_81 ;
}
static int
F_45 ( const struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_82 * V_83 )
{
const struct V_2 * V_3 = V_8 -> V_17 ;
struct V_48 * V_84 , * V_73 ;
T_1 V_19 , V_85 = V_83 -> args [ 2 ] ;
const struct V_1 * V_18 ;
V_84 = F_41 ( V_10 , V_86 ) ;
if ( ! V_84 )
return - V_81 ;
for (; V_83 -> args [ 2 ] < V_3 -> V_25 ; V_83 -> args [ 2 ] ++ ) {
V_19 = V_83 -> args [ 2 ] ;
V_18 = F_1 ( V_3 , V_19 ) ;
if ( V_18 -> V_4 == V_26 )
goto V_66;
if ( F_3 ( V_8 ) &&
F_4 ( F_5 ( V_18 , V_3 ) ) )
continue;
V_73 = F_41 ( V_10 , V_74 ) ;
if ( ! V_73 ) {
if ( V_19 == V_85 ) {
F_46 ( V_10 , V_84 ) ;
return - V_81 ;
} else
goto V_75;
}
if ( F_47 ( V_10 , V_55 ,
F_48 ( V_18 -> V_4 ) ) )
goto V_75;
if ( F_3 ( V_8 ) &&
F_42 ( V_10 , V_56 ,
F_43 ( F_49 (
F_5 ( V_18 , V_3 ) ) ) ) )
goto V_75;
if ( F_7 ( V_8 ) &&
F_50 ( V_10 , F_9 ( V_18 , V_3 ) ) )
goto V_75;
F_44 ( V_10 , V_73 ) ;
}
V_66:
F_44 ( V_10 , V_84 ) ;
V_83 -> args [ 2 ] = 0 ;
return 0 ;
V_75:
F_46 ( V_10 , V_73 ) ;
F_44 ( V_10 , V_84 ) ;
if ( F_28 ( V_19 == V_85 ) ) {
V_83 -> args [ 2 ] = 0 ;
return - V_81 ;
}
return 0 ;
}
static bool
F_51 ( const struct V_7 * V_87 , const struct V_7 * V_88 )
{
const struct V_2 * V_35 = V_87 -> V_17 ;
const struct V_2 * V_89 = V_88 -> V_17 ;
return V_35 -> V_25 == V_89 -> V_25 &&
V_35 -> V_36 == V_89 -> V_36 &&
V_87 -> V_90 == V_88 -> V_90 ;
}
static void
F_52 ( unsigned long V_91 )
{
struct V_7 * V_8 = (struct V_7 * ) V_91 ;
struct V_2 * V_3 = V_8 -> V_17 ;
F_53 ( & V_8 -> V_92 ) ;
F_22 ( V_8 ) ;
F_54 ( & V_8 -> V_92 ) ;
V_3 -> V_72 . V_93 = V_94 + F_55 ( V_3 -> V_36 ) * V_95 ;
F_56 ( & V_3 -> V_72 ) ;
}
static void
F_57 ( struct V_7 * V_8 , void (* V_72)( unsigned long V_91 ) )
{
struct V_2 * V_3 = V_8 -> V_17 ;
F_58 ( & V_3 -> V_72 ) ;
V_3 -> V_72 . V_17 = ( unsigned long ) V_8 ;
V_3 -> V_72 . V_96 = V_72 ;
V_3 -> V_72 . V_93 = V_94 + F_55 ( V_3 -> V_36 ) * V_95 ;
F_56 ( & V_3 -> V_72 ) ;
}
static struct V_2 *
F_59 ( struct V_7 * V_8 , T_1 V_25 , T_4 V_6 ,
unsigned long V_36 )
{
struct V_2 * V_3 ;
struct V_1 * V_18 ;
T_1 V_19 ;
V_3 = F_60 ( sizeof( * V_3 ) + V_25 * V_6 , V_97 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_25 = V_25 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_36 = V_36 ;
V_8 -> V_17 = V_3 ;
for ( V_19 = 0 ; V_19 < V_25 ; V_19 ++ ) {
V_18 = F_1 ( V_3 , V_19 ) ;
V_18 -> V_4 = V_26 ;
}
return V_3 ;
}
static int
F_61 ( struct V_7 * V_8 , struct V_48 * V_49 [] , T_1 V_39 )
{
struct V_2 * V_3 ;
T_1 V_25 = V_98 , V_99 = 0 ;
unsigned long V_36 = 0 ;
if ( F_28 ( ! F_29 ( V_49 , V_76 ) ||
! F_29 ( V_49 , V_56 ) ||
! F_29 ( V_49 , V_57 ) ) )
return - V_60 ;
if ( V_49 [ V_76 ] )
V_25 = F_34 ( V_49 [ V_76 ] ) ;
if ( V_25 < V_100 )
V_25 = V_100 ;
if ( V_49 [ V_57 ] )
V_99 = F_34 ( V_49 [ V_57 ] ) ;
if ( V_49 [ V_56 ] )
V_36 = F_62 ( V_49 [ V_56 ] ) ;
V_8 -> V_53 = & V_101 ;
if ( V_99 & V_77 ) {
V_8 -> V_90 |= V_102 ;
if ( V_49 [ V_56 ] ) {
V_3 = F_59 ( V_8 , V_25 ,
sizeof( struct V_103 ) , V_36 ) ;
if ( ! V_3 )
return - V_104 ;
V_8 -> V_90 |= V_105 ;
V_3 -> V_106 [ V_107 ] =
F_63 ( struct V_103 , V_36 ) ;
V_3 -> V_106 [ V_108 ] =
F_63 ( struct V_103 , V_109 ) ;
F_57 ( V_8 , F_52 ) ;
} else {
V_3 = F_59 ( V_8 , V_25 ,
sizeof( struct V_110 ) , 0 ) ;
if ( ! V_3 )
return - V_104 ;
V_3 -> V_106 [ V_108 ] =
F_63 ( struct V_110 , V_109 ) ;
}
} else if ( V_49 [ V_56 ] ) {
V_3 = F_59 ( V_8 , V_25 ,
sizeof( struct V_111 ) , V_36 ) ;
if ( ! V_3 )
return - V_104 ;
V_8 -> V_90 |= V_105 ;
V_3 -> V_106 [ V_107 ] =
F_63 ( struct V_111 , V_36 ) ;
F_57 ( V_8 , F_52 ) ;
} else {
V_3 = F_59 ( V_8 , V_25 , sizeof( struct V_1 ) , 0 ) ;
if ( ! V_3 )
return - V_104 ;
}
return 0 ;
}
static int T_5
F_64 ( void )
{
return F_65 ( & V_112 ) ;
}
static void T_6
F_66 ( void )
{
F_67 ( & V_112 ) ;
}
