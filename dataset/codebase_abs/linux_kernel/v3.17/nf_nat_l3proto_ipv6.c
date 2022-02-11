static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned long V_7 ,
struct V_8 * V_9 )
{
const struct V_10 * V_11 = & V_4 -> V_12 [ V_6 ] . V_13 ;
struct V_14 * V_15 = & V_9 -> V_16 . V_17 ;
if ( V_4 -> V_18 & V_7 ) {
V_15 -> V_19 = V_11 -> V_20 . V_21 . V_22 ;
if ( V_11 -> V_20 . V_23 == V_24 ||
V_11 -> V_20 . V_23 == V_25 ||
V_11 -> V_20 . V_23 == V_26 ||
V_11 -> V_20 . V_23 == V_27 ||
V_11 -> V_20 . V_23 == V_28 )
V_15 -> V_29 = V_11 -> V_20 . V_16 . V_30 ;
}
V_7 ^= V_31 ;
if ( V_4 -> V_18 & V_7 ) {
V_15 -> V_32 = V_11 -> V_33 . V_21 . V_22 ;
if ( V_11 -> V_20 . V_23 == V_24 ||
V_11 -> V_20 . V_23 == V_25 ||
V_11 -> V_20 . V_23 == V_26 ||
V_11 -> V_20 . V_23 == V_27 ||
V_11 -> V_20 . V_23 == V_28 )
V_15 -> V_34 = V_11 -> V_33 . V_16 . V_30 ;
}
}
static bool F_2 ( const struct V_10 * V_11 ,
const struct V_35 * V_36 )
{
return F_3 ( & V_11 -> V_33 . V_21 . V_22 , & V_36 -> V_37 . V_22 ) >= 0 &&
F_3 ( & V_11 -> V_33 . V_21 . V_22 , & V_36 -> V_38 . V_22 ) <= 0 ;
}
static T_1 F_4 ( const struct V_10 * V_11 ,
T_2 V_39 )
{
return F_5 ( V_11 -> V_33 . V_21 . V_17 , V_11 -> V_20 . V_21 . V_17 , V_39 ) ;
}
static bool F_6 ( struct V_1 * V_2 ,
unsigned int V_40 ,
const struct V_41 * V_42 ,
const struct V_10 * V_43 ,
enum V_44 V_45 )
{
struct V_46 * V_47 ;
T_2 V_48 ;
int V_49 ;
T_3 V_50 ;
if ( ! F_7 ( V_2 , V_40 + sizeof( * V_47 ) ) )
return false ;
V_47 = ( void * ) V_2 -> V_51 + V_40 ;
V_50 = V_47 -> V_50 ;
V_49 = F_8 ( V_2 , V_40 + sizeof( * V_47 ) ,
& V_50 , & V_48 ) ;
if ( V_49 < 0 )
goto V_52;
if ( ( V_48 & F_9 ( ~ 0x7 ) ) == 0 &&
! V_42 -> V_53 ( V_2 , & V_54 , V_40 , V_49 ,
V_43 , V_45 ) )
return false ;
V_52:
if ( V_45 == V_55 )
V_47 -> V_32 = V_43 -> V_33 . V_21 . V_22 ;
else
V_47 -> V_19 = V_43 -> V_20 . V_21 . V_22 ;
return true ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned int V_40 , T_4 * V_56 ,
const struct V_10 * V_11 ,
enum V_44 V_45 )
{
const struct V_46 * V_47 = (struct V_46 * ) ( V_2 -> V_51 + V_40 ) ;
const struct V_57 * V_58 , * V_59 ;
if ( V_45 == V_55 ) {
V_58 = & V_47 -> V_32 ;
V_59 = & V_11 -> V_33 . V_21 . V_22 ;
} else {
V_58 = & V_47 -> V_19 ;
V_59 = & V_11 -> V_20 . V_21 . V_22 ;
}
F_11 ( V_56 , V_2 , V_58 -> V_60 ,
V_59 -> V_60 , 1 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_3 V_61 , void * V_51 , T_4 * V_56 ,
int V_62 , int V_63 )
{
const struct V_46 * V_47 = F_13 ( V_2 ) ;
struct V_64 * V_65 = (struct V_64 * ) F_14 ( V_2 ) ;
if ( V_2 -> V_66 != V_67 ) {
if ( ! ( V_65 -> V_68 & V_69 ) &&
( ! V_2 -> V_70 || V_2 -> V_70 -> V_71 & V_72 ) ) {
V_2 -> V_66 = V_67 ;
V_2 -> V_73 = F_15 ( V_2 ) +
F_16 ( V_2 ) +
( V_51 - ( void * ) V_2 -> V_51 ) ;
V_2 -> V_74 = ( void * ) V_56 - V_51 ;
* V_56 = ~ F_17 ( & V_47 -> V_32 , & V_47 -> V_19 ,
V_62 , V_61 , 0 ) ;
} else {
* V_56 = 0 ;
* V_56 = F_17 ( & V_47 -> V_32 , & V_47 -> V_19 ,
V_62 , V_61 ,
F_18 ( V_51 , V_62 ,
0 ) ) ;
if ( V_61 == V_25 && ! * V_56 )
* V_56 = V_75 ;
}
} else
F_19 ( V_56 , V_2 ,
F_9 ( V_63 ) , F_9 ( V_62 ) , 1 ) ;
}
static int F_20 ( struct V_76 * V_77 [] ,
struct V_35 * V_36 )
{
if ( V_77 [ V_78 ] ) {
F_21 ( & V_36 -> V_37 . V_17 , V_77 [ V_78 ] ,
sizeof( struct V_57 ) ) ;
V_36 -> V_79 |= V_80 ;
}
if ( V_77 [ V_81 ] )
F_21 ( & V_36 -> V_38 . V_17 , V_77 [ V_81 ] ,
sizeof( struct V_57 ) ) ;
else
V_36 -> V_38 = V_36 -> V_37 ;
return 0 ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_82 V_83 ,
unsigned int V_84 ,
unsigned int V_85 )
{
struct {
struct V_86 V_87 ;
struct V_46 V_17 ;
} * V_88 ;
enum V_5 V_6 = F_23 ( V_83 ) ;
enum V_44 V_89 = F_24 ( V_84 ) ;
const struct V_41 * V_42 ;
struct V_10 V_43 ;
unsigned long V_7 ;
F_25 ( V_83 == V_90 || V_83 == V_91 ) ;
if ( ! F_7 ( V_2 , V_85 + sizeof( * V_88 ) ) )
return 0 ;
if ( F_26 ( V_2 , V_84 , V_85 , V_92 ) )
return 0 ;
V_88 = ( void * ) V_2 -> V_51 + V_85 ;
if ( V_88 -> V_87 . V_93 == V_94 ) {
if ( ( V_4 -> V_18 & V_95 ) != V_95 )
return 0 ;
if ( V_4 -> V_18 & V_31 )
return 0 ;
}
if ( V_89 == V_55 )
V_7 = V_96 ;
else
V_7 = V_97 ;
if ( V_6 == V_98 )
V_7 ^= V_31 ;
if ( ! ( V_4 -> V_18 & V_7 ) )
return 1 ;
V_42 = F_27 ( V_99 , V_88 -> V_17 . V_50 ) ;
if ( ! F_6 ( V_2 , V_85 + sizeof( V_88 -> V_87 ) ,
V_42 , & V_4 -> V_12 [ ! V_6 ] . V_13 , ! V_89 ) )
return 0 ;
if ( V_2 -> V_66 != V_67 ) {
struct V_46 * V_47 = F_13 ( V_2 ) ;
V_88 = ( void * ) V_2 -> V_51 + V_85 ;
V_88 -> V_87 . V_100 = 0 ;
V_88 -> V_87 . V_100 =
F_17 ( & V_47 -> V_32 , & V_47 -> V_19 ,
V_2 -> V_101 - V_85 , V_92 ,
F_18 ( & V_88 -> V_87 ,
V_2 -> V_101 - V_85 , 0 ) ) ;
}
F_28 ( & V_43 , & V_4 -> V_12 [ ! V_6 ] . V_13 ) ;
V_42 = F_27 ( V_99 , V_92 ) ;
if ( ! F_6 ( V_2 , 0 , V_42 , & V_43 , V_89 ) )
return 0 ;
return 1 ;
}
static int T_5 F_29 ( void )
{
int V_102 ;
V_102 = F_30 ( V_99 , & V_103 ) ;
if ( V_102 < 0 )
goto V_104;
V_102 = F_31 ( & V_54 ) ;
if ( V_102 < 0 )
goto V_105;
return V_102 ;
V_105:
F_32 ( V_99 , & V_103 ) ;
V_104:
return V_102 ;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_54 ) ;
F_32 ( V_99 , & V_103 ) ;
}
