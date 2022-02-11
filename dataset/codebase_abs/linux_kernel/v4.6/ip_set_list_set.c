static int
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 , const struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
T_1 V_16 = V_8 -> V_16 ;
int V_17 ;
V_8 -> V_16 &= ~ V_18 ;
if ( V_8 -> V_16 & V_19 )
V_8 -> V_16 &= ~ V_20 ;
F_2 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_17 = F_6 ( V_15 -> V_21 , V_4 , V_6 , V_8 ) ;
if ( V_17 > 0 ) {
if ( F_7 ( V_2 ) )
F_8 ( F_9 ( V_15 , V_2 ) ,
V_10 , & V_8 -> V_10 ,
V_16 ) ;
if ( F_10 ( V_2 ) )
F_11 ( F_12 ( V_15 , V_2 ) ,
V_10 , & V_8 -> V_10 ,
V_16 ) ;
return V_17 ;
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
int V_17 ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_17 = F_15 ( V_15 -> V_21 , V_4 , V_6 , V_8 ) ;
if ( V_17 == 0 )
return V_17 ;
}
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 , const struct V_9 * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 ;
int V_17 ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_17 = F_17 ( V_15 -> V_21 , V_4 , V_6 , V_8 ) ;
if ( V_17 == 0 )
return V_17 ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
enum V_22 V_23 , struct V_7 * V_8 )
{
struct V_9 V_10 = F_19 ( V_4 , V_8 , V_2 ) ;
int V_17 = - V_24 ;
F_20 () ;
switch ( V_23 ) {
case V_25 :
V_17 = F_1 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
break;
case V_26 :
V_17 = F_13 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
break;
case V_27 :
V_17 = F_16 ( V_2 , V_4 , V_6 , V_8 , & V_10 ) ;
break;
default:
break;
}
F_21 () ;
return V_17 ;
}
static void
F_22 ( struct V_28 * V_29 )
{
struct V_14 * V_15 = F_23 ( V_29 , struct V_14 , V_29 ) ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_24 ( V_12 -> V_30 , V_15 -> V_21 ) ;
F_25 ( V_2 , V_15 ) ;
F_26 ( V_15 ) ;
}
static inline void
F_27 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
F_28 ( & V_15 -> V_31 ) ;
F_29 ( & V_15 -> V_29 , F_22 ) ;
}
static inline void
F_30 ( struct V_14 * V_15 , struct V_14 * V_32 )
{
F_31 ( & V_32 -> V_31 , & V_15 -> V_31 ) ;
F_29 ( & V_32 -> V_29 , F_22 ) ;
}
static void
F_32 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_33 ;
F_33 (e, n, &map->members, list)
if ( F_4 ( F_5 ( V_15 , V_2 ) ) )
F_27 ( V_2 , V_15 ) ;
}
static int
F_34 ( struct V_1 * V_2 , void * V_34 , const struct V_9 * V_10 ,
struct V_9 * V_35 , T_1 V_36 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_37 * V_38 = V_34 ;
struct V_14 * V_15 , * V_39 , * V_40 = NULL ;
int V_17 ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_21 != V_38 -> V_21 ) {
V_40 = V_15 ;
continue;
}
if ( V_38 -> V_41 == 0 ) {
V_17 = 1 ;
} else if ( V_38 -> V_41 > 0 ) {
V_39 = F_35 ( V_15 , V_31 ) ;
V_17 = ! F_36 ( & V_15 -> V_31 , & V_12 -> V_42 ) &&
V_39 -> V_21 == V_38 -> V_43 ;
} else {
V_17 = V_40 && V_40 -> V_21 == V_38 -> V_43 ;
}
return V_17 ;
}
return 0 ;
}
static void
F_37 ( struct V_1 * V_2 , const struct V_9 * V_10 ,
struct V_14 * V_15 )
{
if ( F_7 ( V_2 ) )
F_38 ( F_9 ( V_15 , V_2 ) , V_10 ) ;
if ( F_39 ( V_2 ) )
F_40 ( F_41 ( V_15 , V_2 ) , V_10 ) ;
if ( F_10 ( V_2 ) )
F_42 ( F_12 ( V_15 , V_2 ) , V_10 ) ;
if ( F_3 ( V_2 ) )
F_43 ( F_5 ( V_15 , V_2 ) , V_10 -> V_44 ) ;
}
static int
F_44 ( struct V_1 * V_2 , void * V_34 , const struct V_9 * V_10 ,
struct V_9 * V_35 , T_1 V_36 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_37 * V_38 = V_34 ;
struct V_14 * V_15 , * V_33 , * V_40 , * V_39 ;
bool V_45 = V_36 & V_46 ;
V_33 = V_40 = V_39 = NULL ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_38 -> V_21 == V_15 -> V_21 )
V_33 = V_15 ;
else if ( V_38 -> V_41 == 0 || V_15 -> V_21 != V_38 -> V_43 )
continue;
else if ( V_38 -> V_41 > 0 )
V_39 = V_15 ;
else
V_40 = V_15 ;
}
if ( V_33 ) {
if ( ( V_38 -> V_41 > 0 && ! V_39 ) ||
( V_38 -> V_41 < 0 && ! V_40 ) )
return - V_47 ;
if ( ! V_45 )
return - V_48 ;
F_25 ( V_2 , V_33 ) ;
F_37 ( V_2 , V_10 , V_33 ) ;
F_24 ( V_12 -> V_30 , V_38 -> V_21 ) ;
return 0 ;
}
if ( V_38 -> V_41 == 0 ) {
V_33 = F_45 ( & V_12 -> V_42 ) ? NULL :
F_46 ( & V_12 -> V_42 , struct V_14 , V_31 ) ;
} else if ( V_38 -> V_41 > 0 ) {
if ( ! F_36 ( & V_39 -> V_31 , & V_12 -> V_42 ) )
V_33 = F_35 ( V_39 , V_31 ) ;
} else {
if ( V_40 -> V_31 . V_40 != & V_12 -> V_42 )
V_33 = F_47 ( V_40 , V_31 ) ;
}
if ( V_33 &&
! ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_33 , V_2 ) ) ) )
V_33 = NULL ;
V_15 = F_48 ( V_2 -> V_49 , V_50 ) ;
if ( ! V_15 )
return - V_51 ;
V_15 -> V_21 = V_38 -> V_21 ;
V_15 -> V_2 = V_2 ;
F_49 ( & V_15 -> V_31 ) ;
F_37 ( V_2 , V_10 , V_15 ) ;
if ( V_33 )
F_30 ( V_15 , V_33 ) ;
else if ( V_39 )
F_50 ( & V_15 -> V_31 , & V_39 -> V_31 ) ;
else if ( V_40 )
F_51 ( & V_15 -> V_31 , & V_40 -> V_31 ) ;
else
F_50 ( & V_15 -> V_31 , & V_12 -> V_42 ) ;
return 0 ;
}
static int
F_52 ( struct V_1 * V_2 , void * V_34 , const struct V_9 * V_10 ,
struct V_9 * V_35 , T_1 V_36 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_37 * V_38 = V_34 ;
struct V_14 * V_15 , * V_39 , * V_40 = NULL ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_21 != V_38 -> V_21 ) {
V_40 = V_15 ;
continue;
}
if ( V_38 -> V_41 > 0 ) {
V_39 = F_35 ( V_15 , V_31 ) ;
if ( F_36 ( & V_15 -> V_31 , & V_12 -> V_42 ) ||
V_39 -> V_21 != V_38 -> V_43 )
return - V_47 ;
} else if ( V_38 -> V_41 < 0 ) {
if ( ! V_40 || V_40 -> V_21 != V_38 -> V_43 )
return - V_47 ;
}
F_27 ( V_2 , V_15 ) ;
return 0 ;
}
return V_38 -> V_41 != 0 ? - V_47 : - V_48 ;
}
static int
F_53 ( struct V_1 * V_2 , struct V_52 * V_53 [] ,
enum V_22 V_23 , T_1 * V_54 , T_1 V_36 , bool V_55 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_56 = V_2 -> V_57 -> V_23 [ V_23 ] ;
struct V_37 V_15 = { . V_43 = V_58 } ;
struct V_9 V_10 = F_54 ( V_2 ) ;
struct V_1 * V_59 ;
int V_17 = 0 ;
if ( V_53 [ V_60 ] )
* V_54 = F_55 ( V_53 [ V_60 ] ) ;
if ( F_56 ( ! V_53 [ V_61 ] ||
! F_57 ( V_53 , V_62 ) ) )
return - V_63 ;
V_17 = F_58 ( V_2 , V_53 , & V_10 ) ;
if ( V_17 )
return V_17 ;
V_15 . V_21 = F_59 ( V_12 -> V_30 , F_60 ( V_53 [ V_61 ] ) , & V_59 ) ;
if ( V_15 . V_21 == V_58 )
return - V_64 ;
if ( V_59 -> type -> V_65 & V_66 ) {
V_17 = - V_67 ;
goto V_68;
}
if ( V_53 [ V_62 ] ) {
T_1 V_69 = F_61 ( V_53 [ V_62 ] ) ;
V_15 . V_41 = V_69 & V_70 ;
}
if ( V_15 . V_41 && ! V_53 [ V_71 ] ) {
V_17 = - V_72 ;
goto V_68;
}
if ( V_53 [ V_71 ] ) {
V_15 . V_43 = F_59 ( V_12 -> V_30 ,
F_60 ( V_53 [ V_71 ] ) ,
& V_59 ) ;
if ( V_15 . V_43 == V_58 ) {
V_17 = - V_73 ;
goto V_68;
}
if ( ! V_15 . V_41 )
V_15 . V_41 = - 1 ;
}
if ( V_23 != V_25 && F_3 ( V_2 ) )
F_32 ( V_2 ) ;
V_17 = V_56 ( V_2 , & V_15 , & V_10 , & V_10 , V_36 ) ;
V_68:
if ( V_15 . V_43 != V_58 )
F_24 ( V_12 -> V_30 , V_15 . V_43 ) ;
if ( V_23 != V_26 || V_17 )
F_24 ( V_12 -> V_30 , V_15 . V_21 ) ;
return F_62 ( V_17 , V_36 ) ? 0 : V_17 ;
}
static void
F_63 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_33 ;
F_33 (e, n, &map->members, list)
F_27 ( V_2 , V_15 ) ;
}
static void
F_64 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_33 ;
if ( F_3 ( V_2 ) )
F_65 ( & V_12 -> V_74 ) ;
F_33 (e, n, &map->members, list) {
F_66 ( & V_15 -> V_31 ) ;
F_24 ( V_12 -> V_30 , V_15 -> V_21 ) ;
F_25 ( V_2 , V_15 ) ;
F_26 ( V_15 ) ;
}
F_26 ( V_12 ) ;
V_2 -> V_13 = NULL ;
}
static int
F_67 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_52 * V_75 ;
struct V_14 * V_15 ;
T_1 V_33 = 0 ;
F_20 () ;
F_2 (e, &map->members, list)
V_33 ++ ;
F_21 () ;
V_75 = F_68 ( V_4 , V_76 ) ;
if ( ! V_75 )
goto V_77;
if ( F_69 ( V_4 , V_78 , F_70 ( V_12 -> V_79 ) ) ||
F_69 ( V_4 , V_80 , F_70 ( V_2 -> V_81 ) ) ||
F_69 ( V_4 , V_82 ,
F_70 ( sizeof( * V_12 ) + V_33 * V_2 -> V_49 ) ) )
goto V_77;
if ( F_56 ( F_71 ( V_4 , V_2 ) ) )
goto V_77;
F_72 ( V_4 , V_75 ) ;
return 0 ;
V_77:
return - V_83 ;
}
static int
F_73 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_84 * V_85 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_52 * V_86 , * V_75 ;
T_1 V_87 = 0 , V_88 = V_85 -> args [ V_89 ] ;
struct V_14 * V_15 ;
int V_17 = 0 ;
V_86 = F_68 ( V_4 , V_90 ) ;
if ( ! V_86 )
return - V_83 ;
F_20 () ;
F_2 (e, &map->members, list) {
if ( V_87 < V_88 ||
( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) ) ) {
V_87 ++ ;
continue;
}
V_75 = F_68 ( V_4 , V_76 ) ;
if ( ! V_75 )
goto V_77;
if ( F_74 ( V_4 , V_61 ,
F_75 ( V_12 -> V_30 , V_15 -> V_21 ) ) )
goto V_77;
if ( F_76 ( V_4 , V_2 , V_15 , true ) )
goto V_77;
F_72 ( V_4 , V_75 ) ;
V_87 ++ ;
}
F_72 ( V_4 , V_86 ) ;
V_85 -> args [ V_89 ] = 0 ;
goto V_91;
V_77:
F_77 ( V_4 , V_75 ) ;
if ( F_56 ( V_87 == V_88 ) ) {
F_77 ( V_4 , V_86 ) ;
V_85 -> args [ V_89 ] = 0 ;
V_17 = - V_83 ;
} else {
V_85 -> args [ V_89 ] = V_87 ;
}
F_72 ( V_4 , V_86 ) ;
V_91:
F_21 () ;
return V_17 ;
}
static bool
F_78 ( const struct V_1 * V_92 , const struct V_1 * V_93 )
{
const struct V_11 * V_94 = V_92 -> V_13 ;
const struct V_11 * V_95 = V_93 -> V_13 ;
return V_94 -> V_79 == V_95 -> V_79 &&
V_92 -> V_44 == V_93 -> V_44 &&
V_92 -> V_96 == V_93 -> V_96 ;
}
static void
F_79 ( unsigned long V_97 )
{
struct V_1 * V_2 = (struct V_1 * ) V_97 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_80 ( & V_2 -> V_98 ) ;
F_32 ( V_2 ) ;
F_81 ( & V_2 -> V_98 ) ;
V_12 -> V_74 . V_99 = V_100 + F_82 ( V_2 -> V_44 ) * V_101 ;
F_83 ( & V_12 -> V_74 ) ;
}
static void
F_84 ( struct V_1 * V_2 , void (* V_74)( unsigned long V_97 ) )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_85 ( & V_12 -> V_74 ) ;
V_12 -> V_74 . V_13 = ( unsigned long ) V_2 ;
V_12 -> V_74 . V_102 = V_74 ;
V_12 -> V_74 . V_99 = V_100 + F_82 ( V_2 -> V_44 ) * V_101 ;
F_83 ( & V_12 -> V_74 ) ;
}
static bool
F_86 ( struct V_30 * V_30 , struct V_1 * V_2 , T_1 V_79 )
{
struct V_11 * V_12 ;
V_12 = F_48 ( sizeof( * V_12 ) , V_103 ) ;
if ( ! V_12 )
return false ;
V_12 -> V_79 = V_79 ;
V_12 -> V_30 = V_30 ;
F_49 ( & V_12 -> V_42 ) ;
V_2 -> V_13 = V_12 ;
return true ;
}
static int
F_87 ( struct V_30 * V_30 , struct V_1 * V_2 , struct V_52 * V_53 [] ,
T_1 V_36 )
{
T_1 V_79 = V_104 ;
if ( F_56 ( ! F_57 ( V_53 , V_78 ) ||
! F_57 ( V_53 , V_105 ) ||
! F_57 ( V_53 , V_62 ) ) )
return - V_63 ;
if ( V_53 [ V_78 ] )
V_79 = F_61 ( V_53 [ V_78 ] ) ;
if ( V_79 < V_106 )
V_79 = V_106 ;
V_2 -> V_57 = & V_107 ;
V_2 -> V_49 = F_88 ( V_2 , V_53 , sizeof( struct V_14 ) ,
F_89 ( struct V_14 ) ) ;
if ( ! F_86 ( V_30 , V_2 , V_79 ) )
return - V_51 ;
if ( V_53 [ V_105 ] ) {
V_2 -> V_44 = F_90 ( V_53 [ V_105 ] ) ;
F_84 ( V_2 , F_79 ) ;
}
return 0 ;
}
static int T_3
F_91 ( void )
{
return F_92 ( & V_108 ) ;
}
static void T_4
F_93 ( void )
{
F_94 () ;
F_95 ( & V_108 ) ;
}
