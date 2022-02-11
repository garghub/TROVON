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
if ( F_10 ( V_2 ) )
F_11 ( F_12 ( V_15 , V_2 ) ,
V_10 , & V_8 -> V_10 ,
V_17 ) ;
return V_18 ;
}
}
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
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
V_18 = F_14 ( V_15 -> V_23 , V_4 , V_6 , V_8 ) ;
if ( V_18 == 0 )
return V_18 ;
}
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
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
V_18 = F_16 ( V_15 -> V_23 , V_4 , V_6 , V_8 ) ;
if ( V_18 == 0 )
return V_18 ;
}
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_25 V_26 , struct V_7 * V_8 )
{
struct V_9 V_10 = F_18 ( V_4 , V_8 , V_2 ) ;
switch ( V_26 ) {
case V_27 :
return F_1 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
case V_28 :
return F_13 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
case V_29 :
return F_15 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
default:
break;
}
return - V_30 ;
}
static bool
F_19 ( const struct V_1 * V_2 , T_1 V_16 , T_2 V_23 )
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
F_20 ( struct V_1 * V_2 , T_1 V_16 , struct V_31 * V_32 ,
const struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 != V_24 ) {
if ( V_16 == V_12 -> V_22 - 1 ) {
F_21 ( V_12 -> V_33 , V_15 -> V_23 ) ;
F_22 ( V_2 , V_15 ) ;
} else {
struct V_14 * V_34 = F_2 ( V_2 , V_12 ,
V_12 -> V_22 - 1 ) ;
if ( V_34 -> V_23 != V_24 ) {
F_21 ( V_12 -> V_33 , V_34 -> V_23 ) ;
F_22 ( V_2 , V_34 ) ;
}
memmove ( F_2 ( V_2 , V_12 , V_16 + 1 ) , V_15 ,
V_2 -> V_35 * ( V_12 -> V_22 - ( V_16 + 1 ) ) ) ;
memset ( V_15 , 0 , V_2 -> V_35 ) ;
}
}
V_15 -> V_23 = V_32 -> V_23 ;
if ( F_3 ( V_2 ) )
F_23 ( F_5 ( V_15 , V_2 ) , V_10 -> V_36 ) ;
if ( F_7 ( V_2 ) )
F_24 ( F_9 ( V_15 , V_2 ) , V_10 ) ;
if ( F_25 ( V_2 ) )
F_26 ( F_27 ( V_15 , V_2 ) , V_10 ) ;
if ( F_10 ( V_2 ) )
F_28 ( F_12 ( V_15 , V_2 ) , V_10 ) ;
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
F_21 ( V_12 -> V_33 , V_15 -> V_23 ) ;
F_22 ( V_2 , V_15 ) ;
if ( V_16 < V_12 -> V_22 - 1 )
memmove ( V_15 , F_2 ( V_2 , V_12 , V_16 + 1 ) ,
V_2 -> V_35 * ( V_12 -> V_22 - ( V_16 + 1 ) ) ) ;
V_15 = F_2 ( V_2 , V_12 , V_12 -> V_22 - 1 ) ;
V_15 -> V_23 = V_24 ;
return 0 ;
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 = 0 ;
while ( V_16 < V_12 -> V_22 ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 != V_24 &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
F_29 ( V_2 , V_16 ) ;
else
V_16 ++ ;
}
}
static int
F_31 ( struct V_1 * V_2 , void * V_37 , const struct V_9 * V_10 ,
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
V_18 = F_19 ( V_2 , V_16 + 1 , V_32 -> V_41 ) ;
else
V_18 = V_16 > 0 && F_19 ( V_2 , V_16 - 1 , V_32 -> V_41 ) ;
return V_18 ;
}
return 0 ;
}
static int
F_32 ( struct V_1 * V_2 , void * V_37 , const struct V_9 * V_10 ,
struct V_9 * V_38 , T_1 V_39 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_31 * V_32 = V_37 ;
struct V_14 * V_15 ;
bool V_42 = V_39 & V_43 ;
T_1 V_16 , V_18 = 0 ;
if ( F_3 ( V_2 ) )
F_30 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
goto V_44;
else if ( V_15 -> V_23 != V_32 -> V_23 )
continue;
if ( ( V_32 -> V_40 > 1 && ! F_19 ( V_2 , V_16 + 1 , V_32 -> V_41 ) ) ||
( V_32 -> V_40 < 0 &&
( V_16 == 0 || ! F_19 ( V_2 , V_16 - 1 , V_32 -> V_41 ) ) ) )
return - V_45 ;
if ( ! V_42 )
return - V_46 ;
F_22 ( V_2 , V_15 ) ;
if ( F_3 ( V_2 ) )
F_23 ( F_5 ( V_15 , V_2 ) , V_10 -> V_36 ) ;
if ( F_7 ( V_2 ) )
F_24 ( F_9 ( V_15 , V_2 ) , V_10 ) ;
if ( F_25 ( V_2 ) )
F_26 ( F_27 ( V_15 , V_2 ) , V_10 ) ;
if ( F_10 ( V_2 ) )
F_28 ( F_12 ( V_15 , V_2 ) , V_10 ) ;
F_21 ( V_12 -> V_33 , V_32 -> V_23 ) ;
return 0 ;
}
V_44:
V_18 = - V_47 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 && V_18 == - V_47 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
V_18 = V_32 -> V_40 != 0 ? - V_45
: F_20 ( V_2 , V_16 , V_32 , V_10 ) ;
else if ( V_15 -> V_23 != V_32 -> V_41 )
continue;
else if ( V_32 -> V_40 > 0 )
V_18 = F_20 ( V_2 , V_16 , V_32 , V_10 ) ;
else if ( V_16 + 1 < V_12 -> V_22 )
V_18 = F_20 ( V_2 , V_16 + 1 , V_32 , V_10 ) ;
}
return V_18 ;
}
static int
F_33 ( struct V_1 * V_2 , void * V_37 , const struct V_9 * V_10 ,
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
return F_29 ( V_2 , V_16 ) ;
else if ( V_32 -> V_40 > 0 ) {
if ( ! F_19 ( V_2 , V_16 + 1 , V_32 -> V_41 ) )
return - V_45 ;
return F_29 ( V_2 , V_16 ) ;
} else if ( V_16 == 0 || ! F_19 ( V_2 , V_16 - 1 , V_32 -> V_41 ) )
return - V_45 ;
else
return F_29 ( V_2 , V_16 ) ;
}
return - V_46 ;
}
static int
F_34 ( struct V_1 * V_2 , struct V_48 * V_49 [] ,
enum V_25 V_26 , T_1 * V_50 , T_1 V_39 , bool V_51 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_3 V_52 = V_2 -> V_53 -> V_26 [ V_26 ] ;
struct V_31 V_15 = { . V_41 = V_24 } ;
struct V_9 V_10 = F_35 ( V_2 ) ;
struct V_1 * V_54 ;
int V_18 = 0 ;
if ( F_36 ( ! V_49 [ V_55 ] ||
! F_37 ( V_49 , V_56 ) ||
! F_37 ( V_49 , V_57 ) ||
! F_37 ( V_49 , V_58 ) ||
! F_37 ( V_49 , V_59 ) ||
! F_37 ( V_49 , V_60 ) ||
! F_37 ( V_49 , V_61 ) ||
! F_37 ( V_49 , V_62 ) ) )
return - V_63 ;
if ( V_49 [ V_64 ] )
* V_50 = F_38 ( V_49 [ V_64 ] ) ;
V_18 = F_39 ( V_2 , V_49 , & V_10 ) ;
if ( V_18 )
return V_18 ;
V_15 . V_23 = F_40 ( V_12 -> V_33 , F_41 ( V_49 [ V_55 ] ) , & V_54 ) ;
if ( V_15 . V_23 == V_24 )
return - V_65 ;
if ( V_54 -> type -> V_66 & V_67 ) {
V_18 = - V_68 ;
goto V_69;
}
if ( V_49 [ V_57 ] ) {
T_1 V_70 = F_42 ( V_49 [ V_57 ] ) ;
V_15 . V_40 = V_70 & V_71 ;
}
if ( V_15 . V_40 && ! V_49 [ V_72 ] ) {
V_18 = - V_73 ;
goto V_69;
}
if ( V_49 [ V_72 ] ) {
V_15 . V_41 = F_40 ( V_12 -> V_33 ,
F_41 ( V_49 [ V_72 ] ) ,
& V_54 ) ;
if ( V_15 . V_41 == V_24 ) {
V_18 = - V_74 ;
goto V_69;
}
if ( ! V_15 . V_40 )
V_15 . V_40 = - 1 ;
}
if ( V_26 != V_27 && F_3 ( V_2 ) )
F_30 ( V_2 ) ;
V_18 = V_52 ( V_2 , & V_15 , & V_10 , & V_10 , V_39 ) ;
V_69:
if ( V_15 . V_41 != V_24 )
F_21 ( V_12 -> V_33 , V_15 . V_41 ) ;
if ( V_26 != V_28 || V_18 )
F_21 ( V_12 -> V_33 , V_15 . V_23 ) ;
return F_43 ( V_18 , V_39 ) ? 0 : V_18 ;
}
static void
F_44 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 ;
for ( V_16 = 0 ; V_16 < V_12 -> V_22 ; V_16 ++ ) {
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 != V_24 ) {
F_21 ( V_12 -> V_33 , V_15 -> V_23 ) ;
F_22 ( V_2 , V_15 ) ;
V_15 -> V_23 = V_24 ;
}
}
}
static void
F_45 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
if ( F_3 ( V_2 ) )
F_46 ( & V_12 -> V_75 ) ;
F_44 ( V_2 ) ;
F_47 ( V_12 ) ;
V_2 -> V_13 = NULL ;
}
static int
F_48 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_48 * V_76 ;
V_76 = F_49 ( V_4 , V_77 ) ;
if ( ! V_76 )
goto V_78;
if ( F_50 ( V_4 , V_79 , F_51 ( V_12 -> V_22 ) ) ||
F_50 ( V_4 , V_80 , F_51 ( V_2 -> V_81 - 1 ) ) ||
F_50 ( V_4 , V_82 ,
F_51 ( sizeof( * V_12 ) + V_12 -> V_22 * V_2 -> V_35 ) ) )
goto V_78;
if ( F_36 ( F_52 ( V_4 , V_2 ) ) )
goto V_78;
F_53 ( V_4 , V_76 ) ;
return 0 ;
V_78:
return - V_83 ;
}
static int
F_54 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_85 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_48 * V_86 , * V_76 ;
T_1 V_16 , V_87 = V_85 -> args [ V_88 ] ;
const struct V_14 * V_15 ;
V_86 = F_49 ( V_4 , V_89 ) ;
if ( ! V_86 )
return - V_83 ;
for (; V_85 -> args [ V_88 ] < V_12 -> V_22 ;
V_85 -> args [ V_88 ] ++ ) {
V_16 = V_85 -> args [ V_88 ] ;
V_15 = F_2 ( V_2 , V_12 , V_16 ) ;
if ( V_15 -> V_23 == V_24 )
goto V_69;
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_76 = F_49 ( V_4 , V_77 ) ;
if ( ! V_76 ) {
if ( V_16 == V_87 ) {
F_55 ( V_4 , V_86 ) ;
return - V_83 ;
} else
goto V_78;
}
if ( F_56 ( V_4 , V_55 ,
F_57 ( V_12 -> V_33 , V_15 -> V_23 ) ) )
goto V_78;
if ( F_58 ( V_4 , V_2 , V_15 , true ) )
goto V_78;
F_53 ( V_4 , V_76 ) ;
}
V_69:
F_53 ( V_4 , V_86 ) ;
V_85 -> args [ V_88 ] = 0 ;
return 0 ;
V_78:
F_55 ( V_4 , V_76 ) ;
if ( F_36 ( V_16 == V_87 ) ) {
V_85 -> args [ V_88 ] = 0 ;
return - V_83 ;
}
F_53 ( V_4 , V_86 ) ;
return 0 ;
}
static bool
F_59 ( const struct V_1 * V_90 , const struct V_1 * V_91 )
{
const struct V_11 * V_34 = V_90 -> V_13 ;
const struct V_11 * V_92 = V_91 -> V_13 ;
return V_34 -> V_22 == V_92 -> V_22 &&
V_90 -> V_36 == V_91 -> V_36 &&
V_90 -> V_93 == V_91 -> V_93 ;
}
static void
F_60 ( unsigned long V_94 )
{
struct V_1 * V_2 = (struct V_1 * ) V_94 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_61 ( & V_2 -> V_95 ) ;
F_30 ( V_2 ) ;
F_62 ( & V_2 -> V_95 ) ;
V_12 -> V_75 . V_96 = V_97 + F_63 ( V_2 -> V_36 ) * V_98 ;
F_64 ( & V_12 -> V_75 ) ;
}
static void
F_65 ( struct V_1 * V_2 , void (* V_75)( unsigned long V_94 ) )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_66 ( & V_12 -> V_75 ) ;
V_12 -> V_75 . V_13 = ( unsigned long ) V_2 ;
V_12 -> V_75 . V_99 = V_75 ;
V_12 -> V_75 . V_96 = V_97 + F_63 ( V_2 -> V_36 ) * V_98 ;
F_64 ( & V_12 -> V_75 ) ;
}
static bool
F_67 ( struct V_33 * V_33 , struct V_1 * V_2 , T_1 V_22 )
{
struct V_11 * V_12 ;
struct V_14 * V_15 ;
T_1 V_16 ;
V_12 = F_68 ( sizeof( * V_12 ) +
F_69 ( T_1 , V_22 , V_100 ) * V_2 -> V_35 ,
V_101 ) ;
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
F_70 ( struct V_33 * V_33 , struct V_1 * V_2 , struct V_48 * V_49 [] ,
T_1 V_39 )
{
T_1 V_22 = V_102 ;
if ( F_36 ( ! F_37 ( V_49 , V_79 ) ||
! F_37 ( V_49 , V_56 ) ||
! F_37 ( V_49 , V_57 ) ) )
return - V_63 ;
if ( V_49 [ V_79 ] )
V_22 = F_42 ( V_49 [ V_79 ] ) ;
if ( V_22 < V_103 )
V_22 = V_103 ;
V_2 -> V_53 = & V_104 ;
V_2 -> V_35 = F_71 ( V_2 , V_49 , sizeof( struct V_14 ) ) ;
if ( ! F_67 ( V_33 , V_2 , V_22 ) )
return - V_105 ;
if ( V_49 [ V_56 ] ) {
V_2 -> V_36 = F_72 ( V_49 [ V_56 ] ) ;
F_65 ( V_2 , F_60 ) ;
}
return 0 ;
}
static int T_4
F_73 ( void )
{
return F_74 ( & V_106 ) ;
}
static void T_5
F_75 ( void )
{
F_76 ( & V_106 ) ;
}
