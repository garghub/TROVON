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
return F_3 ( V_11 -> V_33 . V_21 . V_22 ) >= F_3 ( V_36 -> V_37 . V_22 ) &&
F_3 ( V_11 -> V_33 . V_21 . V_22 ) <= F_3 ( V_36 -> V_38 . V_22 ) ;
}
static T_1 F_4 ( const struct V_10 * V_11 ,
T_2 V_39 )
{
return F_5 ( V_11 -> V_33 . V_21 . V_22 , V_11 -> V_20 . V_21 . V_22 , V_39 ) ;
}
static bool F_6 ( struct V_1 * V_2 ,
unsigned int V_40 ,
const struct V_41 * V_42 ,
const struct V_10 * V_43 ,
enum V_44 V_45 )
{
struct V_46 * V_47 ;
unsigned int V_48 ;
if ( ! F_7 ( V_2 , V_40 + sizeof( * V_47 ) ) )
return false ;
V_47 = ( void * ) V_2 -> V_49 + V_40 ;
V_48 = V_40 + V_47 -> V_50 * 4 ;
if ( ! V_42 -> V_51 ( V_2 , & V_52 , V_40 , V_48 ,
V_43 , V_45 ) )
return false ;
V_47 = ( void * ) V_2 -> V_49 + V_40 ;
if ( V_45 == V_53 ) {
F_8 ( & V_47 -> V_54 , V_47 -> V_32 , V_43 -> V_33 . V_21 . V_22 ) ;
V_47 -> V_32 = V_43 -> V_33 . V_21 . V_22 ;
} else {
F_8 ( & V_47 -> V_54 , V_47 -> V_19 , V_43 -> V_20 . V_21 . V_22 ) ;
V_47 -> V_19 = V_43 -> V_20 . V_21 . V_22 ;
}
return true ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_40 , T_3 * V_54 ,
const struct V_10 * V_11 ,
enum V_44 V_45 )
{
struct V_46 * V_47 = (struct V_46 * ) ( V_2 -> V_49 + V_40 ) ;
T_4 V_55 , V_56 ;
if ( V_45 == V_53 ) {
V_55 = V_47 -> V_32 ;
V_56 = V_11 -> V_33 . V_21 . V_22 ;
} else {
V_55 = V_47 -> V_19 ;
V_56 = V_11 -> V_20 . V_21 . V_22 ;
}
F_10 ( V_54 , V_2 , V_55 , V_56 , 1 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_5 V_57 , void * V_49 , T_3 * V_54 ,
int V_58 , int V_59 )
{
const struct V_46 * V_47 = F_12 ( V_2 ) ;
struct V_60 * V_61 = F_13 ( V_2 ) ;
if ( V_2 -> V_62 != V_63 ) {
if ( ! ( V_61 -> V_64 & V_65 ) &&
( ! V_2 -> V_66 || V_2 -> V_66 -> V_67 & V_68 ) ) {
V_2 -> V_62 = V_63 ;
V_2 -> V_69 = F_14 ( V_2 ) +
F_15 ( V_2 ) +
F_16 ( V_2 ) ;
V_2 -> V_70 = ( void * ) V_54 - V_49 ;
* V_54 = ~ F_17 ( V_47 -> V_32 , V_47 -> V_19 ,
V_58 , V_57 , 0 ) ;
} else {
* V_54 = 0 ;
* V_54 = F_17 ( V_47 -> V_32 , V_47 -> V_19 ,
V_58 , V_57 ,
F_18 ( V_49 , V_58 ,
0 ) ) ;
if ( V_57 == V_25 && ! * V_54 )
* V_54 = V_71 ;
}
} else
F_19 ( V_54 , V_2 ,
F_20 ( V_59 ) , F_20 ( V_58 ) , 1 ) ;
}
static int F_21 ( struct V_72 * V_73 [] ,
struct V_35 * V_36 )
{
if ( V_73 [ V_74 ] ) {
V_36 -> V_37 . V_22 = F_22 ( V_73 [ V_74 ] ) ;
V_36 -> V_75 |= V_76 ;
}
if ( V_73 [ V_77 ] )
V_36 -> V_38 . V_22 = F_22 ( V_73 [ V_77 ] ) ;
else
V_36 -> V_38 . V_22 = V_36 -> V_37 . V_22 ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_78 V_79 ,
unsigned int V_80 )
{
struct {
struct V_81 V_82 ;
struct V_46 V_22 ;
} * V_83 ;
enum V_5 V_6 = F_24 ( V_79 ) ;
enum V_44 V_84 = F_25 ( V_80 ) ;
unsigned int V_85 = F_16 ( V_2 ) ;
const struct V_41 * V_42 ;
struct V_10 V_43 ;
unsigned long V_7 ;
F_26 ( V_79 == V_86 || V_79 == V_87 ) ;
if ( ! F_7 ( V_2 , V_85 + sizeof( * V_83 ) ) )
return 0 ;
if ( F_27 ( V_2 , V_80 , V_85 , 0 ) )
return 0 ;
V_83 = ( void * ) V_2 -> V_49 + V_85 ;
if ( V_83 -> V_82 . type == V_88 ) {
if ( ( V_4 -> V_18 & V_89 ) != V_89 )
return 0 ;
if ( V_4 -> V_18 & V_31 )
return 0 ;
}
if ( V_84 == V_53 )
V_7 = V_90 ;
else
V_7 = V_91 ;
if ( V_6 == V_92 )
V_7 ^= V_31 ;
if ( ! ( V_4 -> V_18 & V_7 ) )
return 1 ;
V_42 = F_28 ( V_93 , V_83 -> V_22 . V_94 ) ;
if ( ! F_6 ( V_2 , V_85 + sizeof( V_83 -> V_82 ) ,
V_42 , & V_4 -> V_12 [ ! V_6 ] . V_13 , ! V_84 ) )
return 0 ;
if ( V_2 -> V_62 != V_63 ) {
V_83 = ( void * ) V_2 -> V_49 + V_85 ;
V_83 -> V_82 . V_95 = 0 ;
V_83 -> V_82 . V_95 =
F_29 ( F_30 ( V_2 , V_85 ,
V_2 -> V_96 - V_85 , 0 ) ) ;
}
F_31 ( & V_43 , & V_4 -> V_12 [ ! V_6 ] . V_13 ) ;
V_42 = F_28 ( V_93 , 0 ) ;
if ( ! F_6 ( V_2 , 0 , V_42 , & V_43 , V_84 ) )
return 0 ;
return 1 ;
}
static int T_6 F_32 ( void )
{
int V_97 ;
V_97 = F_33 ( V_93 , & V_98 ) ;
if ( V_97 < 0 )
goto V_99;
V_97 = F_34 ( & V_52 ) ;
if ( V_97 < 0 )
goto V_100;
return V_97 ;
V_100:
F_35 ( V_93 , & V_98 ) ;
V_99:
return V_97 ;
}
static void T_7 F_36 ( void )
{
F_37 ( & V_52 ) ;
F_35 ( V_93 , & V_98 ) ;
}
