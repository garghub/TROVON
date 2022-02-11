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
F_10 ( V_54 , V_2 , V_55 , V_56 , true ) ;
}
static void F_11 ( struct V_1 * V_2 ,
T_5 V_57 , void * V_49 , T_3 * V_54 ,
int V_58 , int V_59 )
{
if ( V_2 -> V_60 != V_61 ) {
const struct V_46 * V_47 = F_12 ( V_2 ) ;
V_2 -> V_60 = V_61 ;
V_2 -> V_62 = F_13 ( V_2 ) + F_14 ( V_2 ) +
F_15 ( V_2 ) ;
V_2 -> V_63 = ( void * ) V_54 - V_49 ;
* V_54 = ~ F_16 ( V_47 -> V_32 , V_47 -> V_19 , V_58 ,
V_57 , 0 ) ;
} else
F_17 ( V_54 , V_2 ,
F_18 ( V_59 ) , F_18 ( V_58 ) , true ) ;
}
static int F_19 ( struct V_64 * V_65 [] ,
struct V_35 * V_36 )
{
if ( V_65 [ V_66 ] ) {
V_36 -> V_37 . V_22 = F_20 ( V_65 [ V_66 ] ) ;
V_36 -> V_67 |= V_68 ;
}
if ( V_65 [ V_69 ] )
V_36 -> V_38 . V_22 = F_20 ( V_65 [ V_69 ] ) ;
else
V_36 -> V_38 . V_22 = V_36 -> V_37 . V_22 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_70 V_71 ,
unsigned int V_72 )
{
struct {
struct V_73 V_74 ;
struct V_46 V_22 ;
} * V_75 ;
enum V_5 V_6 = F_22 ( V_71 ) ;
enum V_44 V_76 = F_23 ( V_72 ) ;
unsigned int V_77 = F_15 ( V_2 ) ;
const struct V_41 * V_42 ;
struct V_10 V_43 ;
unsigned long V_7 ;
F_24 ( V_71 != V_78 && V_71 != V_79 ) ;
if ( ! F_7 ( V_2 , V_77 + sizeof( * V_75 ) ) )
return 0 ;
if ( F_25 ( V_2 , V_72 , V_77 , 0 ) )
return 0 ;
V_75 = ( void * ) V_2 -> V_49 + V_77 ;
if ( V_75 -> V_74 . type == V_80 ) {
if ( ( V_4 -> V_18 & V_81 ) != V_81 )
return 0 ;
if ( V_4 -> V_18 & V_31 )
return 0 ;
}
if ( V_76 == V_53 )
V_7 = V_82 ;
else
V_7 = V_83 ;
if ( V_6 == V_84 )
V_7 ^= V_31 ;
if ( ! ( V_4 -> V_18 & V_7 ) )
return 1 ;
V_42 = F_26 ( V_85 , V_75 -> V_22 . V_86 ) ;
if ( ! F_6 ( V_2 , V_77 + sizeof( V_75 -> V_74 ) ,
V_42 , & V_4 -> V_12 [ ! V_6 ] . V_13 , ! V_76 ) )
return 0 ;
if ( V_2 -> V_60 != V_61 ) {
V_75 = ( void * ) V_2 -> V_49 + V_77 ;
V_75 -> V_74 . V_87 = 0 ;
V_75 -> V_74 . V_87 =
F_27 ( F_28 ( V_2 , V_77 ,
V_2 -> V_88 - V_77 , 0 ) ) ;
}
F_29 ( & V_43 , & V_4 -> V_12 [ ! V_6 ] . V_13 ) ;
V_42 = F_26 ( V_85 , 0 ) ;
if ( ! F_6 ( V_2 , 0 , V_42 , & V_43 , V_76 ) )
return 0 ;
return 1 ;
}
static int T_6 F_30 ( void )
{
int V_89 ;
V_89 = F_31 ( V_85 , & V_90 ) ;
if ( V_89 < 0 )
goto V_91;
V_89 = F_32 ( & V_52 ) ;
if ( V_89 < 0 )
goto V_92;
return V_89 ;
V_92:
F_33 ( V_85 , & V_90 ) ;
V_91:
return V_89 ;
}
static void T_7 F_34 ( void )
{
F_35 ( & V_52 ) ;
F_33 ( V_85 , & V_90 ) ;
}
