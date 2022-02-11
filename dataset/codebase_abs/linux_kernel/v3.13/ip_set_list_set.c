static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 , const struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 , V_17 = V_8 -> V_17 ;
int V_18 ;
V_8 -> V_17 &= ~ V_19 ;
if ( V_8 -> V_17 & V_20 )
V_8 -> V_17 &= ~ V_21 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
return 0 ;
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_18 = F_6 ( V_15 -> V_23 , V_4 , V_6 , V_8 ) ;
if ( V_18 > 0 ) {
if ( F_7 ( V_2 ) )
F_8 ( F_9 ( V_15 , V_2 ) ,
V_10 , & V_8 -> V_10 ,
V_17 ) ;
return V_18 ;
}
}
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 , const struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 ;
int V_18 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
return 0 ;
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_18 = F_11 ( V_15 -> V_23 , V_4 , V_6 , V_8 ) ;
if ( V_18 == 0 )
return V_18 ;
}
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 , const struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 ;
int V_18 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
return 0 ;
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_18 = F_13 ( V_15 -> V_23 , V_4 , V_6 , V_8 ) ;
if ( V_18 == 0 )
return V_18 ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_25 V_26 , struct V_7 * V_8 )
{
struct V_9 V_10 = F_15 ( V_4 , V_8 , V_2 ) ;
switch ( V_26 ) {
case V_27 :
return F_1 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
case V_28 :
return F_10 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
case V_29 :
return F_12 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
default:
break;
}
return - V_30 ;
}
static bool
F_16 ( const struct V_1 * V_2 , T_1 V_16 , T_2 V_23 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
const struct V_14 * V_15 ;
if ( V_16 >= V_12 -> V_22 )
return 0 ;
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
return ! ! ( V_15 -> V_23 == V_23 &&
! ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) ) ) ;
}
static int
F_17 ( struct V_1 * V_2 , T_1 V_16 , struct V_31 * V_32 ,
const struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 != V_24 ) {
if ( V_16 == V_12 -> V_22 - 1 ) {
F_18 ( V_12 -> V_33 , V_15 -> V_23 ) ;
F_19 ( V_2 , V_15 ) ;
} else {
struct V_14 * V_34 = F_2 ( V_2 , V_12 ,
V_12 -> V_22 - 1 ) ;
if ( V_34 -> V_23 != V_24 ) {
F_18 ( V_12 -> V_33 , V_34 -> V_23 ) ;
F_19 ( V_2 , V_34 ) ;
}
memmove ( F_2 ( V_2 , V_12 , V_16 + 1 ) , V_15 ,
V_2 -> V_35 * ( V_12 -> V_22 - ( V_16 + 1 ) ) ) ;
memset ( V_15 , 0 , V_2 -> V_35 ) ;
}
}
V_15 -> V_23 = V_32 -> V_23 ;
if ( F_3 ( V_2 ) )
F_20 ( F_5 ( V_15 , V_2 ) , V_10 -> V_36 ) ;
if ( F_7 ( V_2 ) )
F_21 ( F_9 ( V_15 , V_2 ) , V_10 ) ;
if ( F_22 ( V_2 ) )
F_23 ( F_24 ( V_15 , V_2 ) , V_10 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
F_18 ( V_12 -> V_33 , V_15 -> V_23 ) ;
F_19 ( V_2 , V_15 ) ;
if ( V_16 < V_12 -> V_22 - 1 )
memmove ( V_15 , F_2 ( V_2 , V_12 , V_16 + 1 ) ,
V_2 -> V_35 * ( V_12 -> V_22 - ( V_16 + 1 ) ) ) ;
V_15 = F_2 ( V_2 , V_12 , V_12 -> V_22 - 1 ) ;
V_15 -> V_23 = V_24 ;
return 0 ;
}
static void
F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 = 0 ;
while ( V_16 < V_12 -> V_22 ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 != V_24 &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
F_25 ( V_2 , V_16 ) ;
else
V_16 ++ ;
}
}
static int
F_27 ( struct V_1 * V_2 , void * V_37 , const struct V_9 * V_10 ,
struct V_9 * V_38 , T_1 V_39 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_31 * V_32 = V_37 ;
struct V_14 * V_15 ;
T_1 V_16 ;
int V_18 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
return 0 ;
else if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_23 != V_32 -> V_23 )
continue;
if ( V_32 -> V_40 == 0 )
return 1 ;
else if ( V_32 -> V_40 > 0 )
V_18 = F_16 ( V_2 , V_16 + 1 , V_32 -> V_41 ) ;
else
V_18 = V_16 > 0 && F_16 ( V_2 , V_16 - 1 , V_32 -> V_41 ) ;
return V_18 ;
}
return 0 ;
}
static int
F_28 ( struct V_1 * V_2 , void * V_37 , const struct V_9 * V_10 ,
struct V_9 * V_38 , T_1 V_39 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_31 * V_32 = V_37 ;
struct V_14 * V_15 ;
bool V_42 = V_39 & V_43 ;
T_1 V_16 , V_18 = 0 ;
if ( F_3 ( V_2 ) )
F_26 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
goto V_44;
else if ( V_15 -> V_23 != V_32 -> V_23 )
continue;
if ( ( V_32 -> V_40 > 1 && ! F_16 ( V_2 , V_16 + 1 , V_32 -> V_41 ) ) ||
( V_32 -> V_40 < 0 &&
( V_16 == 0 || ! F_16 ( V_2 , V_16 - 1 , V_32 -> V_41 ) ) ) )
return - V_45 ;
if ( ! V_42 )
return - V_46 ;
F_19 ( V_2 , V_15 ) ;
if ( F_3 ( V_2 ) )
F_20 ( F_5 ( V_15 , V_2 ) , V_10 -> V_36 ) ;
if ( F_7 ( V_2 ) )
F_21 ( F_9 ( V_15 , V_2 ) , V_10 ) ;
if ( F_22 ( V_2 ) )
F_23 ( F_24 ( V_15 , V_2 ) , V_10 ) ;
F_18 ( V_12 -> V_33 , V_32 -> V_23 ) ;
return 0 ;
}
V_44:
V_18 = - V_47 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 && V_18 == - V_47 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
V_18 = V_32 -> V_40 != 0 ? - V_45
: F_17 ( V_2 , V_16 , V_32 , V_10 ) ;
else if ( V_15 -> V_23 != V_32 -> V_41 )
continue;
else if ( V_32 -> V_40 > 0 )
V_18 = F_17 ( V_2 , V_16 , V_32 , V_10 ) ;
else if ( V_16 + 1 < V_12 -> V_22 )
V_18 = F_17 ( V_2 , V_16 + 1 , V_32 , V_10 ) ;
}
return V_18 ;
}
static int
F_29 ( struct V_1 * V_2 , void * V_37 , const struct V_9 * V_10 ,
struct V_9 * V_38 , T_1 V_39 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_31 * V_32 = V_37 ;
struct V_14 * V_15 ;
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
return V_32 -> V_40 != 0 ? - V_45
: - V_46 ;
else if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_23 != V_32 -> V_23 )
continue;
if ( V_32 -> V_40 == 0 )
return F_25 ( V_2 , V_16 ) ;
else if ( V_32 -> V_40 > 0 ) {
if ( ! F_16 ( V_2 , V_16 + 1 , V_32 -> V_41 ) )
return - V_45 ;
return F_25 ( V_2 , V_16 ) ;
} else if ( V_16 == 0 || ! F_16 ( V_2 , V_16 - 1 , V_32 -> V_41 ) )
return - V_45 ;
else
return F_25 ( V_2 , V_16 ) ;
}
return - V_46 ;
}
static int
F_30 ( struct V_1 * V_2 , struct V_48 * V_49 [] ,
enum V_25 V_26 , T_1 * V_50 , T_1 V_39 , bool V_51 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_3 V_52 = V_2 -> V_53 -> V_26 [ V_26 ] ;
struct V_31 V_15 = { . V_41 = V_24 } ;
struct V_9 V_10 = F_31 ( V_2 ) ;
struct V_1 * V_54 ;
int V_18 = 0 ;
if ( F_32 ( ! V_49 [ V_55 ] ||
! F_33 ( V_49 , V_56 ) ||
! F_33 ( V_49 , V_57 ) ||
! F_33 ( V_49 , V_58 ) ||
! F_33 ( V_49 , V_59 ) ) )
return - V_60 ;
if ( V_49 [ V_61 ] )
* V_50 = F_34 ( V_49 [ V_61 ] ) ;
V_18 = F_35 ( V_2 , V_49 , & V_10 ) ;
if ( V_18 )
return V_18 ;
V_15 . V_23 = F_36 ( V_12 -> V_33 , F_37 ( V_49 [ V_55 ] ) , & V_54 ) ;
if ( V_15 . V_23 == V_24 )
return - V_62 ;
if ( V_54 -> type -> V_63 & V_64 ) {
V_18 = - V_65 ;
goto V_66;
}
if ( V_49 [ V_57 ] ) {
T_1 V_67 = F_38 ( V_49 [ V_57 ] ) ;
V_15 . V_40 = V_67 & V_68 ;
}
if ( V_15 . V_40 && ! V_49 [ V_69 ] ) {
V_18 = - V_70 ;
goto V_66;
}
if ( V_49 [ V_69 ] ) {
V_15 . V_41 = F_36 ( V_12 -> V_33 ,
F_37 ( V_49 [ V_69 ] ) ,
& V_54 ) ;
if ( V_15 . V_41 == V_24 ) {
V_18 = - V_71 ;
goto V_66;
}
if ( ! V_15 . V_40 )
V_15 . V_40 = - 1 ;
}
if ( V_26 != V_27 && F_3 ( V_2 ) )
F_26 ( V_2 ) ;
V_18 = V_52 ( V_2 , & V_15 , & V_10 , & V_10 , V_39 ) ;
V_66:
if ( V_15 . V_41 != V_24 )
F_18 ( V_12 -> V_33 , V_15 . V_41 ) ;
if ( V_26 != V_28 || V_18 )
F_18 ( V_12 -> V_33 , V_15 . V_23 ) ;
return F_39 ( V_18 , V_39 ) ? 0 : V_18 ;
}
static void
F_40 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 != V_24 ) {
F_18 ( V_12 -> V_33 , V_15 -> V_23 ) ;
F_19 ( V_2 , V_15 ) ;
V_15 -> V_23 = V_24 ;
}
}
}
static void
F_41 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( F_3 ( V_2 ) )
F_42 ( & V_12 -> V_72 ) ;
F_40 ( V_2 ) ;
F_43 ( V_12 ) ;
V_2 -> V_13 = NULL ;
}
static int
F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_48 * V_73 ;
V_73 = F_45 ( V_4 , V_74 ) ;
if ( ! V_73 )
goto V_75;
if ( F_46 ( V_4 , V_76 , F_47 ( V_12 -> V_22 ) ) ||
F_46 ( V_4 , V_77 , F_47 ( V_2 -> V_78 - 1 ) ) ||
F_46 ( V_4 , V_79 ,
F_47 ( sizeof( * V_12 ) + V_12 -> V_22 * V_2 -> V_35 ) ) )
goto V_75;
if ( F_32 ( F_48 ( V_4 , V_2 ) ) )
goto V_75;
F_49 ( V_4 , V_73 ) ;
return 0 ;
V_75:
return - V_80 ;
}
static int
F_50 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_81 * V_82 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_48 * V_83 , * V_73 ;
T_1 V_16 , V_84 = V_82 -> args [ V_85 ] ;
const struct V_14 * V_15 ;
V_83 = F_45 ( V_4 , V_86 ) ;
if ( ! V_83 )
return - V_80 ;
for (; V_82 -> args [ V_85 ] < V_12 -> V_22 ;
V_82 -> args [ V_85 ] ++ ) {
V_16 = V_82 -> args [ V_85 ] ;
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
goto V_66;
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_73 = F_45 ( V_4 , V_74 ) ;
if ( ! V_73 ) {
if ( V_16 == V_84 ) {
F_51 ( V_4 , V_83 ) ;
return - V_80 ;
} else
goto V_75;
}
if ( F_52 ( V_4 , V_55 ,
F_53 ( V_12 -> V_33 , V_15 -> V_23 ) ) )
goto V_75;
if ( F_54 ( V_4 , V_2 , V_15 , true ) )
goto V_75;
F_49 ( V_4 , V_73 ) ;
}
V_66:
F_49 ( V_4 , V_83 ) ;
V_82 -> args [ V_85 ] = 0 ;
return 0 ;
V_75:
F_51 ( V_4 , V_73 ) ;
if ( F_32 ( V_16 == V_84 ) ) {
V_82 -> args [ V_85 ] = 0 ;
return - V_80 ;
}
F_49 ( V_4 , V_83 ) ;
return 0 ;
}
static bool
F_55 ( const struct V_1 * V_87 , const struct V_1 * V_88 )
{
const struct V_11 * V_34 = V_87 -> V_13 ;
const struct V_11 * V_89 = V_88 -> V_13 ;
return V_34 -> V_22 == V_89 -> V_22 &&
V_87 -> V_36 == V_88 -> V_36 &&
V_87 -> V_90 == V_88 -> V_90 ;
}
static void
F_56 ( unsigned long V_91 )
{
struct V_1 * V_2 = (struct V_1 * ) V_91 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_57 ( & V_2 -> V_92 ) ;
F_26 ( V_2 ) ;
F_58 ( & V_2 -> V_92 ) ;
V_12 -> V_72 . V_93 = V_94 + F_59 ( V_2 -> V_36 ) * V_95 ;
F_60 ( & V_12 -> V_72 ) ;
}
static void
F_61 ( struct V_1 * V_2 , void (* V_72)( unsigned long V_91 ) )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_62 ( & V_12 -> V_72 ) ;
V_12 -> V_72 . V_13 = ( unsigned long ) V_2 ;
V_12 -> V_72 . V_96 = V_72 ;
V_12 -> V_72 . V_93 = V_94 + F_59 ( V_2 -> V_36 ) * V_95 ;
F_60 ( & V_12 -> V_72 ) ;
}
static bool
F_63 ( struct V_33 * V_33 , struct V_1 * V_2 , T_1 V_22 )
{
struct V_11 * V_12 ;
struct V_14 * V_15 ;
T_1 V_16 ;
V_12 = F_64 ( sizeof( * V_12 ) + V_22 * V_2 -> V_35 , V_97 ) ;
if ( ! V_12 )
return false ;
V_12 -> V_22 = V_22 ;
V_12 -> V_33 = V_33 ;
V_2 -> V_13 = V_12 ;
for ( V_16 = 0 ; V_16 < V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
V_15 -> V_23 = V_24 ;
}
return true ;
}
static int
F_65 ( struct V_33 * V_33 , struct V_1 * V_2 , struct V_48 * V_49 [] ,
T_1 V_39 )
{
T_1 V_22 = V_98 ;
if ( F_32 ( ! F_33 ( V_49 , V_76 ) ||
! F_33 ( V_49 , V_56 ) ||
! F_33 ( V_49 , V_57 ) ) )
return - V_60 ;
if ( V_49 [ V_76 ] )
V_22 = F_38 ( V_49 [ V_76 ] ) ;
if ( V_22 < V_99 )
V_22 = V_99 ;
V_2 -> V_53 = & V_100 ;
V_2 -> V_35 = F_66 ( V_2 , V_49 , sizeof( struct V_14 ) ) ;
if ( ! F_63 ( V_33 , V_2 , V_22 ) )
return - V_101 ;
if ( V_49 [ V_56 ] ) {
V_2 -> V_36 = F_67 ( V_49 [ V_56 ] ) ;
F_61 ( V_2 , F_56 ) ;
}
return 0 ;
}
static int T_4
F_68 ( void )
{
return F_69 ( & V_102 ) ;
}
static void T_5
F_70 ( void )
{
F_71 ( & V_102 ) ;
}
