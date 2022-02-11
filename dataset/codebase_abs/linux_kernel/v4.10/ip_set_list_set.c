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
V_2 -> V_31 -- ;
F_28 ( & V_15 -> V_32 ) ;
F_29 ( & V_15 -> V_29 , F_22 ) ;
}
static inline void
F_30 ( struct V_14 * V_15 , struct V_14 * V_33 )
{
F_31 ( & V_33 -> V_32 , & V_15 -> V_32 ) ;
F_29 ( & V_33 -> V_29 , F_22 ) ;
}
static void
F_32 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_34 ;
F_33 (e, n, &map->members, list)
if ( F_4 ( F_5 ( V_15 , V_2 ) ) )
F_27 ( V_2 , V_15 ) ;
}
static int
F_34 ( struct V_1 * V_2 , void * V_35 , const struct V_9 * V_10 ,
struct V_9 * V_36 , T_1 V_37 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_38 * V_39 = V_35 ;
struct V_14 * V_15 , * V_40 , * V_41 = NULL ;
int V_17 ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_21 != V_39 -> V_21 ) {
V_41 = V_15 ;
continue;
}
if ( V_39 -> V_42 == 0 ) {
V_17 = 1 ;
} else if ( V_39 -> V_42 > 0 ) {
V_40 = F_35 ( V_15 , V_32 ) ;
V_17 = ! F_36 ( & V_15 -> V_32 , & V_12 -> V_43 ) &&
V_40 -> V_21 == V_39 -> V_44 ;
} else {
V_17 = V_41 && V_41 -> V_21 == V_39 -> V_44 ;
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
F_40 ( V_2 , F_41 ( V_15 , V_2 ) , V_10 ) ;
if ( F_10 ( V_2 ) )
F_42 ( F_12 ( V_15 , V_2 ) , V_10 ) ;
if ( F_3 ( V_2 ) )
F_43 ( F_5 ( V_15 , V_2 ) , V_10 -> V_45 ) ;
}
static int
F_44 ( struct V_1 * V_2 , void * V_35 , const struct V_9 * V_10 ,
struct V_9 * V_36 , T_1 V_37 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_38 * V_39 = V_35 ;
struct V_14 * V_15 , * V_34 , * V_41 , * V_40 ;
bool V_46 = V_37 & V_47 ;
V_34 = V_41 = V_40 = NULL ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_39 -> V_21 == V_15 -> V_21 )
V_34 = V_15 ;
else if ( V_39 -> V_42 == 0 || V_15 -> V_21 != V_39 -> V_44 )
continue;
else if ( V_39 -> V_42 > 0 )
V_40 = V_15 ;
else
V_41 = V_15 ;
}
if ( V_34 ) {
if ( ( V_39 -> V_42 > 0 && ! V_40 ) ||
( V_39 -> V_42 < 0 && ! V_41 ) )
return - V_48 ;
if ( ! V_46 )
return - V_49 ;
F_25 ( V_2 , V_34 ) ;
F_37 ( V_2 , V_10 , V_34 ) ;
F_24 ( V_12 -> V_30 , V_39 -> V_21 ) ;
return 0 ;
}
if ( V_39 -> V_42 == 0 ) {
V_34 = F_45 ( & V_12 -> V_43 ) ? NULL :
F_46 ( & V_12 -> V_43 , struct V_14 , V_32 ) ;
} else if ( V_39 -> V_42 > 0 ) {
if ( ! F_36 ( & V_40 -> V_32 , & V_12 -> V_43 ) )
V_34 = F_35 ( V_40 , V_32 ) ;
} else {
if ( V_41 -> V_32 . V_41 != & V_12 -> V_43 )
V_34 = F_47 ( V_41 , V_32 ) ;
}
if ( V_34 &&
! ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_34 , V_2 ) ) ) )
V_34 = NULL ;
V_15 = F_48 ( V_2 -> V_50 , V_51 ) ;
if ( ! V_15 )
return - V_52 ;
V_15 -> V_21 = V_39 -> V_21 ;
V_15 -> V_2 = V_2 ;
F_49 ( & V_15 -> V_32 ) ;
F_37 ( V_2 , V_10 , V_15 ) ;
if ( V_34 )
F_30 ( V_15 , V_34 ) ;
else if ( V_40 )
F_50 ( & V_15 -> V_32 , & V_40 -> V_32 ) ;
else if ( V_41 )
F_51 ( & V_15 -> V_32 , & V_41 -> V_32 ) ;
else
F_50 ( & V_15 -> V_32 , & V_12 -> V_43 ) ;
V_2 -> V_31 ++ ;
return 0 ;
}
static int
F_52 ( struct V_1 * V_2 , void * V_35 , const struct V_9 * V_10 ,
struct V_9 * V_36 , T_1 V_37 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_38 * V_39 = V_35 ;
struct V_14 * V_15 , * V_40 , * V_41 = NULL ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_21 != V_39 -> V_21 ) {
V_41 = V_15 ;
continue;
}
if ( V_39 -> V_42 > 0 ) {
V_40 = F_35 ( V_15 , V_32 ) ;
if ( F_36 ( & V_15 -> V_32 , & V_12 -> V_43 ) ||
V_40 -> V_21 != V_39 -> V_44 )
return - V_48 ;
} else if ( V_39 -> V_42 < 0 ) {
if ( ! V_41 || V_41 -> V_21 != V_39 -> V_44 )
return - V_48 ;
}
F_27 ( V_2 , V_15 ) ;
return 0 ;
}
return V_39 -> V_42 != 0 ? - V_48 : - V_49 ;
}
static int
F_53 ( struct V_1 * V_2 , struct V_53 * V_54 [] ,
enum V_22 V_23 , T_1 * V_55 , T_1 V_37 , bool V_56 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_57 = V_2 -> V_58 -> V_23 [ V_23 ] ;
struct V_38 V_15 = { . V_44 = V_59 } ;
struct V_9 V_10 = F_54 ( V_2 ) ;
struct V_1 * V_60 ;
int V_17 = 0 ;
if ( V_54 [ V_61 ] )
* V_55 = F_55 ( V_54 [ V_61 ] ) ;
if ( F_56 ( ! V_54 [ V_62 ] ||
! F_57 ( V_54 , V_63 ) ) )
return - V_64 ;
V_17 = F_58 ( V_2 , V_54 , & V_10 ) ;
if ( V_17 )
return V_17 ;
V_15 . V_21 = F_59 ( V_12 -> V_30 , F_60 ( V_54 [ V_62 ] ) , & V_60 ) ;
if ( V_15 . V_21 == V_59 )
return - V_65 ;
if ( V_60 -> type -> V_66 & V_67 ) {
V_17 = - V_68 ;
goto V_69;
}
if ( V_54 [ V_63 ] ) {
T_1 V_70 = F_61 ( V_54 [ V_63 ] ) ;
V_15 . V_42 = V_70 & V_71 ;
}
if ( V_15 . V_42 && ! V_54 [ V_72 ] ) {
V_17 = - V_73 ;
goto V_69;
}
if ( V_54 [ V_72 ] ) {
V_15 . V_44 = F_59 ( V_12 -> V_30 ,
F_60 ( V_54 [ V_72 ] ) ,
& V_60 ) ;
if ( V_15 . V_44 == V_59 ) {
V_17 = - V_74 ;
goto V_69;
}
if ( ! V_15 . V_42 )
V_15 . V_42 = - 1 ;
}
if ( V_23 != V_25 && F_3 ( V_2 ) )
F_32 ( V_2 ) ;
V_17 = V_57 ( V_2 , & V_15 , & V_10 , & V_10 , V_37 ) ;
V_69:
if ( V_15 . V_44 != V_59 )
F_24 ( V_12 -> V_30 , V_15 . V_44 ) ;
if ( V_23 != V_26 || V_17 )
F_24 ( V_12 -> V_30 , V_15 . V_21 ) ;
return F_62 ( V_17 , V_37 ) ? 0 : V_17 ;
}
static void
F_63 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_34 ;
F_33 (e, n, &map->members, list)
F_27 ( V_2 , V_15 ) ;
V_2 -> V_31 = 0 ;
V_2 -> V_75 = 0 ;
}
static void
F_64 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_34 ;
if ( F_3 ( V_2 ) )
F_65 ( & V_12 -> V_76 ) ;
F_33 (e, n, &map->members, list) {
F_66 ( & V_15 -> V_32 ) ;
F_24 ( V_12 -> V_30 , V_15 -> V_21 ) ;
F_25 ( V_2 , V_15 ) ;
F_26 ( V_15 ) ;
}
F_26 ( V_12 ) ;
V_2 -> V_13 = NULL ;
}
static T_3
F_67 ( const struct V_11 * V_12 , T_3 V_50 )
{
struct V_14 * V_15 ;
T_3 V_77 ;
T_1 V_34 = 0 ;
F_20 () ;
F_2 (e, &map->members, list)
V_34 ++ ;
F_21 () ;
V_77 = sizeof( * V_12 ) + V_34 * V_50 ;
return V_77 ;
}
static int
F_68 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_53 * V_78 ;
T_3 V_77 = F_67 ( V_12 , V_2 -> V_50 ) + V_2 -> V_75 ;
V_78 = F_69 ( V_4 , V_79 ) ;
if ( ! V_78 )
goto V_80;
if ( F_70 ( V_4 , V_81 , F_71 ( V_12 -> V_82 ) ) ||
F_70 ( V_4 , V_83 , F_71 ( V_2 -> V_84 ) ) ||
F_70 ( V_4 , V_85 , F_71 ( V_77 ) ) ||
F_70 ( V_4 , V_86 , F_71 ( V_2 -> V_31 ) ) )
goto V_80;
if ( F_56 ( F_72 ( V_4 , V_2 ) ) )
goto V_80;
F_73 ( V_4 , V_78 ) ;
return 0 ;
V_80:
return - V_87 ;
}
static int
F_74 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_88 * V_89 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_53 * V_90 , * V_78 ;
T_1 V_91 = 0 , V_92 = V_89 -> args [ V_93 ] ;
struct V_14 * V_15 ;
int V_17 = 0 ;
V_90 = F_69 ( V_4 , V_94 ) ;
if ( ! V_90 )
return - V_87 ;
F_20 () ;
F_2 (e, &map->members, list) {
if ( V_91 < V_92 ||
( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) ) ) {
V_91 ++ ;
continue;
}
V_78 = F_69 ( V_4 , V_79 ) ;
if ( ! V_78 )
goto V_80;
if ( F_75 ( V_4 , V_62 ,
F_76 ( V_12 -> V_30 , V_15 -> V_21 ) ) )
goto V_80;
if ( F_77 ( V_4 , V_2 , V_15 , true ) )
goto V_80;
F_73 ( V_4 , V_78 ) ;
V_91 ++ ;
}
F_73 ( V_4 , V_90 ) ;
V_89 -> args [ V_93 ] = 0 ;
goto V_95;
V_80:
F_78 ( V_4 , V_78 ) ;
if ( F_56 ( V_91 == V_92 ) ) {
F_78 ( V_4 , V_90 ) ;
V_89 -> args [ V_93 ] = 0 ;
V_17 = - V_87 ;
} else {
V_89 -> args [ V_93 ] = V_91 ;
}
F_73 ( V_4 , V_90 ) ;
V_95:
F_21 () ;
return V_17 ;
}
static bool
F_79 ( const struct V_1 * V_96 , const struct V_1 * V_97 )
{
const struct V_11 * V_98 = V_96 -> V_13 ;
const struct V_11 * V_99 = V_97 -> V_13 ;
return V_98 -> V_82 == V_99 -> V_82 &&
V_96 -> V_45 == V_97 -> V_45 &&
V_96 -> V_100 == V_97 -> V_100 ;
}
static void
F_80 ( unsigned long V_101 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_81 ( & V_2 -> V_102 ) ;
F_32 ( V_2 ) ;
F_82 ( & V_2 -> V_102 ) ;
V_12 -> V_76 . V_103 = V_104 + F_83 ( V_2 -> V_45 ) * V_105 ;
F_84 ( & V_12 -> V_76 ) ;
}
static void
F_85 ( struct V_1 * V_2 , void (* V_76)( unsigned long V_101 ) )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_86 ( & V_12 -> V_76 , V_76 , ( unsigned long ) V_2 ) ;
F_87 ( & V_12 -> V_76 , V_104 + F_83 ( V_2 -> V_45 ) * V_105 ) ;
}
static bool
F_88 ( struct V_30 * V_30 , struct V_1 * V_2 , T_1 V_82 )
{
struct V_11 * V_12 ;
V_12 = F_48 ( sizeof( * V_12 ) , V_106 ) ;
if ( ! V_12 )
return false ;
V_12 -> V_82 = V_82 ;
V_12 -> V_30 = V_30 ;
F_49 ( & V_12 -> V_43 ) ;
V_2 -> V_13 = V_12 ;
return true ;
}
static int
F_89 ( struct V_30 * V_30 , struct V_1 * V_2 , struct V_53 * V_54 [] ,
T_1 V_37 )
{
T_1 V_82 = V_107 ;
if ( F_56 ( ! F_57 ( V_54 , V_81 ) ||
! F_57 ( V_54 , V_108 ) ||
! F_57 ( V_54 , V_63 ) ) )
return - V_64 ;
if ( V_54 [ V_81 ] )
V_82 = F_61 ( V_54 [ V_81 ] ) ;
if ( V_82 < V_109 )
V_82 = V_109 ;
V_2 -> V_58 = & V_110 ;
V_2 -> V_50 = F_90 ( V_2 , V_54 , sizeof( struct V_14 ) ,
F_91 ( struct V_14 ) ) ;
if ( ! F_88 ( V_30 , V_2 , V_82 ) )
return - V_52 ;
if ( V_54 [ V_108 ] ) {
V_2 -> V_45 = F_92 ( V_54 [ V_108 ] ) ;
F_85 ( V_2 , F_80 ) ;
}
return 0 ;
}
static int T_4
F_93 ( void )
{
return F_94 ( & V_111 ) ;
}
static void T_5
F_95 ( void )
{
F_96 () ;
F_97 ( & V_111 ) ;
}
