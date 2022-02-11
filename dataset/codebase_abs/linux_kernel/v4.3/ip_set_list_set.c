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
F_22 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_23 ( V_12 -> V_28 , V_15 -> V_21 ) ;
F_24 ( V_2 , V_15 ) ;
F_25 ( V_15 , V_29 ) ;
}
static inline void
F_26 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
F_27 ( & V_15 -> V_30 ) ;
F_22 ( V_2 , V_15 ) ;
}
static inline void
F_28 ( struct V_1 * V_2 , struct V_14 * V_15 , struct V_14 * V_31 )
{
F_29 ( & V_31 -> V_30 , & V_15 -> V_30 ) ;
F_22 ( V_2 , V_31 ) ;
}
static void
F_30 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_32 ;
F_31 (e, n, &map->members, list)
if ( F_4 ( F_5 ( V_15 , V_2 ) ) )
F_26 ( V_2 , V_15 ) ;
}
static int
F_32 ( struct V_1 * V_2 , void * V_33 , const struct V_9 * V_10 ,
struct V_9 * V_34 , T_1 V_35 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_36 * V_37 = V_33 ;
struct V_14 * V_15 , * V_38 , * V_39 = NULL ;
int V_17 ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_21 != V_37 -> V_21 ) {
V_39 = V_15 ;
continue;
}
if ( V_37 -> V_40 == 0 ) {
V_17 = 1 ;
} else if ( V_37 -> V_40 > 0 ) {
V_38 = F_33 ( V_15 , V_30 ) ;
V_17 = ! F_34 ( & V_15 -> V_30 , & V_12 -> V_41 ) &&
V_38 -> V_21 == V_37 -> V_42 ;
} else {
V_17 = V_39 && V_39 -> V_21 == V_37 -> V_42 ;
}
return V_17 ;
}
return 0 ;
}
static void
F_35 ( struct V_1 * V_2 , const struct V_9 * V_10 ,
struct V_14 * V_15 )
{
if ( F_7 ( V_2 ) )
F_36 ( F_9 ( V_15 , V_2 ) , V_10 ) ;
if ( F_37 ( V_2 ) )
F_38 ( F_39 ( V_15 , V_2 ) , V_10 ) ;
if ( F_10 ( V_2 ) )
F_40 ( F_12 ( V_15 , V_2 ) , V_10 ) ;
if ( F_3 ( V_2 ) )
F_41 ( F_5 ( V_15 , V_2 ) , V_10 -> V_43 ) ;
}
static int
F_42 ( struct V_1 * V_2 , void * V_33 , const struct V_9 * V_10 ,
struct V_9 * V_34 , T_1 V_35 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_36 * V_37 = V_33 ;
struct V_14 * V_15 , * V_32 , * V_39 , * V_38 ;
bool V_44 = V_35 & V_45 ;
if ( F_3 ( V_2 ) )
F_30 ( V_2 ) ;
V_32 = V_39 = V_38 = NULL ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_37 -> V_21 == V_15 -> V_21 )
V_32 = V_15 ;
else if ( V_37 -> V_40 == 0 || V_15 -> V_21 != V_37 -> V_42 )
continue;
else if ( V_37 -> V_40 > 0 )
V_38 = V_15 ;
else
V_39 = V_15 ;
}
if ( V_32 ) {
if ( ( V_37 -> V_40 > 0 && ! V_38 ) ||
( V_37 -> V_40 < 0 && ! V_39 ) )
return - V_46 ;
if ( ! V_44 )
return - V_47 ;
F_24 ( V_2 , V_32 ) ;
F_35 ( V_2 , V_10 , V_32 ) ;
F_23 ( V_12 -> V_28 , V_37 -> V_21 ) ;
return 0 ;
}
if ( V_37 -> V_40 == 0 ) {
V_32 = F_43 ( & V_12 -> V_41 ) ? NULL :
F_44 ( & V_12 -> V_41 , struct V_14 , V_30 ) ;
} else if ( V_37 -> V_40 > 0 ) {
if ( ! F_34 ( & V_38 -> V_30 , & V_12 -> V_41 ) )
V_32 = F_33 ( V_38 , V_30 ) ;
} else {
if ( V_39 -> V_30 . V_39 != & V_12 -> V_41 )
V_32 = F_45 ( V_39 , V_30 ) ;
}
if ( V_32 &&
! ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_32 , V_2 ) ) ) )
V_32 = NULL ;
V_15 = F_46 ( V_2 -> V_48 , V_49 ) ;
if ( ! V_15 )
return - V_50 ;
V_15 -> V_21 = V_37 -> V_21 ;
F_47 ( & V_15 -> V_30 ) ;
F_35 ( V_2 , V_10 , V_15 ) ;
if ( V_32 )
F_28 ( V_2 , V_15 , V_32 ) ;
else if ( V_38 )
F_48 ( & V_15 -> V_30 , & V_38 -> V_30 ) ;
else if ( V_39 )
F_49 ( & V_15 -> V_30 , & V_39 -> V_30 ) ;
else
F_48 ( & V_15 -> V_30 , & V_12 -> V_41 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 , void * V_33 , const struct V_9 * V_10 ,
struct V_9 * V_34 , T_1 V_35 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_36 * V_37 = V_33 ;
struct V_14 * V_15 , * V_38 , * V_39 = NULL ;
F_14 (e, &map->members, list) {
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
else if ( V_15 -> V_21 != V_37 -> V_21 ) {
V_39 = V_15 ;
continue;
}
if ( V_37 -> V_40 > 0 ) {
V_38 = F_33 ( V_15 , V_30 ) ;
if ( F_34 ( & V_15 -> V_30 , & V_12 -> V_41 ) ||
V_38 -> V_21 != V_37 -> V_42 )
return - V_46 ;
} else if ( V_37 -> V_40 < 0 ) {
if ( ! V_39 || V_39 -> V_21 != V_37 -> V_42 )
return - V_46 ;
}
F_26 ( V_2 , V_15 ) ;
return 0 ;
}
return V_37 -> V_40 != 0 ? - V_46 : - V_47 ;
}
static int
F_51 ( struct V_1 * V_2 , struct V_51 * V_52 [] ,
enum V_22 V_23 , T_1 * V_53 , T_1 V_35 , bool V_54 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
T_2 V_55 = V_2 -> V_56 -> V_23 [ V_23 ] ;
struct V_36 V_15 = { . V_42 = V_57 } ;
struct V_9 V_10 = F_52 ( V_2 ) ;
struct V_1 * V_58 ;
int V_17 = 0 ;
if ( V_52 [ V_59 ] )
* V_53 = F_53 ( V_52 [ V_59 ] ) ;
if ( F_54 ( ! V_52 [ V_60 ] ||
! F_55 ( V_52 , V_61 ) ) )
return - V_62 ;
V_17 = F_56 ( V_2 , V_52 , & V_10 ) ;
if ( V_17 )
return V_17 ;
V_15 . V_21 = F_57 ( V_12 -> V_28 , F_58 ( V_52 [ V_60 ] ) , & V_58 ) ;
if ( V_15 . V_21 == V_57 )
return - V_63 ;
if ( V_58 -> type -> V_64 & V_65 ) {
V_17 = - V_66 ;
goto V_67;
}
if ( V_52 [ V_61 ] ) {
T_1 V_68 = F_59 ( V_52 [ V_61 ] ) ;
V_15 . V_40 = V_68 & V_69 ;
}
if ( V_15 . V_40 && ! V_52 [ V_70 ] ) {
V_17 = - V_71 ;
goto V_67;
}
if ( V_52 [ V_70 ] ) {
V_15 . V_42 = F_57 ( V_12 -> V_28 ,
F_58 ( V_52 [ V_70 ] ) ,
& V_58 ) ;
if ( V_15 . V_42 == V_57 ) {
V_17 = - V_72 ;
goto V_67;
}
if ( ! V_15 . V_40 )
V_15 . V_40 = - 1 ;
}
if ( V_23 != V_25 && F_3 ( V_2 ) )
F_30 ( V_2 ) ;
V_17 = V_55 ( V_2 , & V_15 , & V_10 , & V_10 , V_35 ) ;
V_67:
if ( V_15 . V_42 != V_57 )
F_23 ( V_12 -> V_28 , V_15 . V_42 ) ;
if ( V_23 != V_26 || V_17 )
F_23 ( V_12 -> V_28 , V_15 . V_21 ) ;
return F_60 ( V_17 , V_35 ) ? 0 : V_17 ;
}
static void
F_61 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_32 ;
F_31 (e, n, &map->members, list)
F_26 ( V_2 , V_15 ) ;
}
static void
F_62 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_14 * V_15 , * V_32 ;
if ( F_3 ( V_2 ) )
F_63 ( & V_12 -> V_73 ) ;
F_31 (e, n, &map->members, list) {
F_64 ( & V_15 -> V_30 ) ;
F_23 ( V_12 -> V_28 , V_15 -> V_21 ) ;
F_24 ( V_2 , V_15 ) ;
F_65 ( V_15 ) ;
}
F_65 ( V_12 ) ;
V_2 -> V_13 = NULL ;
}
static int
F_66 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_51 * V_74 ;
struct V_14 * V_15 ;
T_1 V_32 = 0 ;
F_14 (e, &map->members, list)
V_32 ++ ;
V_74 = F_67 ( V_4 , V_75 ) ;
if ( ! V_74 )
goto V_76;
if ( F_68 ( V_4 , V_77 , F_69 ( V_12 -> V_78 ) ) ||
F_68 ( V_4 , V_79 , F_69 ( V_2 -> V_80 - 1 ) ) ||
F_68 ( V_4 , V_81 ,
F_69 ( sizeof( * V_12 ) + V_32 * V_2 -> V_48 ) ) )
goto V_76;
if ( F_54 ( F_70 ( V_4 , V_2 ) ) )
goto V_76;
F_71 ( V_4 , V_74 ) ;
return 0 ;
V_76:
return - V_82 ;
}
static int
F_72 ( const struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_83 * V_84 )
{
const struct V_11 * V_12 = V_2 -> V_13 ;
struct V_51 * V_85 , * V_74 ;
T_1 V_86 = 0 , V_87 = V_84 -> args [ V_88 ] ;
struct V_14 * V_15 ;
int V_17 = 0 ;
V_85 = F_67 ( V_4 , V_89 ) ;
if ( ! V_85 )
return - V_82 ;
F_14 (e, &map->members, list) {
if ( V_86 == V_87 )
break;
V_86 ++ ;
}
F_20 () ;
F_73 (e, &map->members, list) {
V_86 ++ ;
if ( F_3 ( V_2 ) &&
F_4 ( F_5 ( V_15 , V_2 ) ) )
continue;
V_74 = F_67 ( V_4 , V_75 ) ;
if ( ! V_74 ) {
if ( V_86 == V_87 ) {
F_74 ( V_4 , V_85 ) ;
V_17 = - V_82 ;
goto V_90;
}
goto V_76;
}
if ( F_75 ( V_4 , V_60 ,
F_76 ( V_12 -> V_28 , V_15 -> V_21 ) ) )
goto V_76;
if ( F_77 ( V_4 , V_2 , V_15 , true ) )
goto V_76;
F_71 ( V_4 , V_74 ) ;
}
F_71 ( V_4 , V_85 ) ;
V_84 -> args [ V_88 ] = 0 ;
goto V_90;
V_76:
F_74 ( V_4 , V_74 ) ;
if ( F_54 ( V_86 == V_87 ) ) {
V_84 -> args [ V_88 ] = 0 ;
V_17 = - V_82 ;
}
V_84 -> args [ V_88 ] = V_86 - 1 ;
F_71 ( V_4 , V_85 ) ;
V_90:
F_21 () ;
return V_17 ;
}
static bool
F_78 ( const struct V_1 * V_91 , const struct V_1 * V_92 )
{
const struct V_11 * V_93 = V_91 -> V_13 ;
const struct V_11 * V_94 = V_92 -> V_13 ;
return V_93 -> V_78 == V_94 -> V_78 &&
V_91 -> V_43 == V_92 -> V_43 &&
V_91 -> V_95 == V_92 -> V_95 ;
}
static void
F_79 ( unsigned long V_96 )
{
struct V_1 * V_2 = (struct V_1 * ) V_96 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_80 ( & V_2 -> V_97 ) ;
F_30 ( V_2 ) ;
F_81 ( & V_2 -> V_97 ) ;
V_12 -> V_73 . V_98 = V_99 + F_82 ( V_2 -> V_43 ) * V_100 ;
F_83 ( & V_12 -> V_73 ) ;
}
static void
F_84 ( struct V_1 * V_2 , void (* V_73)( unsigned long V_96 ) )
{
struct V_11 * V_12 = V_2 -> V_13 ;
F_85 ( & V_12 -> V_73 ) ;
V_12 -> V_73 . V_13 = ( unsigned long ) V_2 ;
V_12 -> V_73 . V_101 = V_73 ;
V_12 -> V_73 . V_98 = V_99 + F_82 ( V_2 -> V_43 ) * V_100 ;
F_83 ( & V_12 -> V_73 ) ;
}
static bool
F_86 ( struct V_28 * V_28 , struct V_1 * V_2 , T_1 V_78 )
{
struct V_11 * V_12 ;
V_12 = F_46 ( sizeof( * V_12 ) , V_102 ) ;
if ( ! V_12 )
return false ;
V_12 -> V_78 = V_78 ;
V_12 -> V_28 = V_28 ;
F_47 ( & V_12 -> V_41 ) ;
V_2 -> V_13 = V_12 ;
return true ;
}
static int
F_87 ( struct V_28 * V_28 , struct V_1 * V_2 , struct V_51 * V_52 [] ,
T_1 V_35 )
{
T_1 V_78 = V_103 ;
if ( F_54 ( ! F_55 ( V_52 , V_77 ) ||
! F_55 ( V_52 , V_104 ) ||
! F_55 ( V_52 , V_61 ) ) )
return - V_62 ;
if ( V_52 [ V_77 ] )
V_78 = F_59 ( V_52 [ V_77 ] ) ;
if ( V_78 < V_105 )
V_78 = V_105 ;
V_2 -> V_56 = & V_106 ;
V_2 -> V_48 = F_88 ( V_2 , V_52 , sizeof( struct V_14 ) ) ;
if ( ! F_86 ( V_28 , V_2 , V_78 ) )
return - V_50 ;
if ( V_52 [ V_104 ] ) {
V_2 -> V_43 = F_89 ( V_52 [ V_104 ] ) ;
F_84 ( V_2 , F_79 ) ;
}
return 0 ;
}
static int T_3
F_90 ( void )
{
return F_91 ( & V_107 ) ;
}
static void T_4
F_92 ( void )
{
F_93 () ;
F_94 ( & V_107 ) ;
}
