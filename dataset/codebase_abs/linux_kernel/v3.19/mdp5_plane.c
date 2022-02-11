static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static bool F_4 ( struct V_9 * V_10 )
{
return V_10 -> V_11 && V_10 -> V_12 ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
F_7 ( L_1 , V_13 -> V_16 ) ;
if ( V_1 ) {
F_8 ( V_1 -> V_17 , V_15 ) ;
}
return 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
F_10 ( V_3 ) ;
F_11 ( V_3 ) ;
F_12 ( V_13 ) ;
}
void F_13 ( struct V_2 * V_3 ,
struct V_18 * V_19 )
{
}
int F_14 ( struct V_2 * V_3 ,
struct V_20 * V_21 , T_1 V_22 )
{
return - V_23 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
if ( V_3 -> V_10 && V_3 -> V_10 -> V_11 )
F_16 ( V_3 -> V_10 -> V_11 ) ;
F_12 ( F_17 ( V_3 -> V_10 ) ) ;
V_25 = F_18 ( sizeof( * V_25 ) , V_26 ) ;
if ( V_3 -> type == V_27 ) {
V_25 -> V_28 = 0 ;
} else {
V_25 -> V_28 = 1 + F_19 ( V_3 ) ;
}
V_3 -> V_10 = & V_25 -> V_29 ;
}
static struct V_9 *
F_20 ( struct V_2 * V_3 )
{
struct V_24 * V_25 ;
if ( F_21 ( ! V_3 -> V_10 ) )
return NULL ;
V_25 = F_22 ( F_17 ( V_3 -> V_10 ) ,
sizeof( * V_25 ) , V_26 ) ;
if ( V_25 && V_25 -> V_29 . V_11 )
F_23 ( V_25 -> V_29 . V_11 ) ;
V_25 -> V_30 = false ;
V_25 -> V_31 = false ;
return & V_25 -> V_29 ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 )
F_16 ( V_10 -> V_11 ) ;
F_12 ( F_17 ( V_10 ) ) ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_32 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_7 ( L_2 , V_13 -> V_16 , V_11 -> V_29 . V_33 ) ;
return F_26 ( V_11 , V_1 -> V_33 ) ;
}
static void F_27 ( struct V_2 * V_3 ,
struct V_32 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_7 ( L_3 , V_13 -> V_16 , V_11 -> V_29 . V_33 ) ;
F_28 ( V_11 , V_1 -> V_33 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_34 = V_3 -> V_10 ;
F_7 ( L_4 , V_13 -> V_16 ,
F_4 ( V_34 ) , F_4 ( V_10 ) ) ;
if ( F_4 ( V_10 ) && F_4 ( V_34 ) ) {
bool V_35 = false ;
if ( V_10 -> V_11 -> V_36 != V_34 -> V_11 -> V_36 ) {
F_7 ( L_5 , V_13 -> V_16 ) ;
V_35 = true ;
}
if ( V_10 -> V_37 != V_34 -> V_37 ) {
F_7 ( L_6 , V_13 -> V_16 ) ;
V_35 = true ;
}
if ( F_17 ( V_34 ) -> V_31 ) {
F_7 ( L_7 , V_13 -> V_16 ) ;
V_35 = true ;
}
if ( V_35 ) {
struct V_38 * V_39 =
F_30 ( V_10 -> V_10 , V_10 -> V_12 ) ;
V_39 -> V_30 = true ;
F_17 ( V_10 ) -> V_30 = true ;
}
} else {
F_17 ( V_10 ) -> V_30 = true ;
}
return 0 ;
}
static void F_31 ( struct V_2 * V_3 ,
struct V_9 * V_34 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_9 * V_10 = V_3 -> V_10 ;
F_7 ( L_8 , V_13 -> V_16 ) ;
if ( ! F_4 ( V_10 ) ) {
F_17 ( V_10 ) -> V_31 = true ;
F_5 ( V_3 ) ;
} else if ( F_17 ( V_10 ) -> V_30 ) {
int V_40 ;
F_17 ( V_10 ) -> V_31 = true ;
V_40 = F_32 ( V_3 ,
V_10 -> V_12 , V_10 -> V_11 ,
V_10 -> V_41 , V_10 -> V_42 ,
V_10 -> V_43 , V_10 -> V_44 ,
V_10 -> V_45 , V_10 -> V_46 ,
V_10 -> V_37 , V_10 -> V_47 ) ;
F_21 ( V_40 < 0 ) ;
} else {
unsigned long V_48 ;
F_33 ( & V_13 -> V_49 , V_48 ) ;
F_34 ( V_3 , V_10 -> V_11 ) ;
F_35 ( & V_13 -> V_49 , V_48 ) ;
}
}
static void F_34 ( struct V_2 * V_3 ,
struct V_32 * V_11 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
F_36 ( V_1 , F_37 ( V_15 ) ,
F_38 ( V_11 -> V_50 [ 0 ] ) |
F_39 ( V_11 -> V_50 [ 1 ] ) ) ;
F_36 ( V_1 , F_40 ( V_15 ) ,
F_41 ( V_11 -> V_50 [ 2 ] ) |
F_42 ( V_11 -> V_50 [ 3 ] ) ) ;
F_36 ( V_1 , F_43 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 0 ) ) ;
F_36 ( V_1 , F_45 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 1 ) ) ;
F_36 ( V_1 , F_46 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 2 ) ) ;
F_36 ( V_1 , F_47 ( V_15 ) ,
F_44 ( V_11 , V_1 -> V_33 , 4 ) ) ;
V_3 -> V_11 = V_11 ;
}
static int F_32 ( struct V_2 * V_3 ,
struct V_51 * V_12 , struct V_32 * V_11 ,
int V_41 , int V_42 ,
unsigned int V_43 , unsigned int V_44 ,
T_2 V_45 , T_2 V_46 ,
T_2 V_37 , T_2 V_47 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
const struct V_52 * V_53 ;
T_2 V_54 , V_55 = 0 ;
T_2 V_56 = 0 , V_57 = 0 ;
T_2 V_58 = 0 , V_59 = 0 ;
unsigned long V_48 ;
int V_40 ;
V_54 = F_48 ( V_11 -> V_36 ) ;
if ( F_21 ( V_54 > F_49 ( V_15 ) ) )
return - V_23 ;
V_45 = V_45 >> 16 ;
V_46 = V_46 >> 16 ;
V_37 = V_37 >> 16 ;
V_47 = V_47 >> 16 ;
F_7 ( L_9 , V_13 -> V_16 ,
V_11 -> V_29 . V_33 , V_45 , V_46 , V_37 , V_47 ,
V_12 -> V_29 . V_33 , V_41 , V_42 , V_43 , V_44 ) ;
V_40 = F_50 ( V_1 -> V_17 ,
V_13 -> V_15 , V_11 -> V_36 , V_37 ) ;
if ( V_40 )
return V_40 ;
F_51 ( V_1 -> V_17 , V_15 ) ;
if ( V_37 != V_43 ) {
V_55 |= V_60 ;
}
if ( V_47 != V_44 ) {
V_55 |= V_61 ;
}
F_33 ( & V_13 -> V_49 , V_48 ) ;
F_36 ( V_1 , F_52 ( V_15 ) ,
F_53 ( V_37 ) |
F_54 ( V_47 ) ) ;
F_36 ( V_1 , F_55 ( V_15 ) ,
F_56 ( V_37 ) |
F_57 ( V_47 ) ) ;
F_36 ( V_1 , F_58 ( V_15 ) ,
F_59 ( V_45 ) |
F_60 ( V_46 ) ) ;
F_36 ( V_1 , F_61 ( V_15 ) ,
F_62 ( V_43 ) |
F_63 ( V_44 ) ) ;
F_36 ( V_1 , F_64 ( V_15 ) ,
F_65 ( V_41 ) |
F_66 ( V_42 ) ) ;
V_53 = F_67 ( F_68 ( V_11 ) ) ;
F_36 ( V_1 , F_69 ( V_15 ) ,
F_70 ( V_53 -> V_62 ) |
F_71 ( V_53 -> V_63 ) |
F_72 ( V_53 -> V_64 ) |
F_73 ( V_53 -> V_65 ) |
F_74 ( V_53 -> V_66 , V_67 ) |
F_75 ( V_53 -> V_68 - 1 ) |
F_76 ( V_53 -> V_69 - 1 ) |
F_74 ( V_53 -> V_70 , V_71 ) |
F_77 ( V_54 - 1 ) |
F_78 ( V_72 ) ) ;
F_36 ( V_1 , F_79 ( V_15 ) ,
F_80 ( V_53 -> V_73 [ 0 ] ) |
F_81 ( V_53 -> V_73 [ 1 ] ) |
F_82 ( V_53 -> V_73 [ 2 ] ) |
F_83 ( V_53 -> V_73 [ 3 ] ) ) ;
F_36 ( V_1 , F_84 ( V_15 ) ,
F_85 ( V_74 ) ) ;
F_36 ( V_1 , F_86 ( V_15 ) , 0 ) ;
F_36 ( V_1 , F_87 ( V_15 ) , V_56 ) ;
F_36 ( V_1 , F_88 ( V_15 ) , V_57 ) ;
F_36 ( V_1 , F_89 ( V_15 ) ,
F_90 ( V_59 ) |
F_91 ( V_58 ) ) ;
F_36 ( V_1 , F_92 ( V_15 ) ,
F_93 ( V_75 ) |
F_94 ( V_75 ) |
F_95 ( V_75 ) |
F_96 ( V_75 ) |
F_97 ( V_75 ) |
F_98 ( V_75 ) ) ;
F_34 ( V_3 , V_11 ) ;
F_35 ( & V_13 -> V_49 , V_48 ) ;
return V_40 ;
}
void F_99 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_13 * V_13 = F_6 ( V_3 ) ;
enum V_14 V_15 = V_13 -> V_15 ;
F_7 ( L_10 , V_13 -> V_16 ) ;
F_100 ( V_1 -> V_17 , V_15 ) ;
F_17 ( V_3 -> V_10 ) -> V_31 = false ;
}
enum V_14 F_101 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_15 ;
}
T_2 F_102 ( struct V_2 * V_3 )
{
struct V_13 * V_13 = F_6 ( V_3 ) ;
return V_13 -> V_76 ;
}
struct V_2 * F_103 ( struct V_77 * V_6 ,
enum V_14 V_15 , bool V_78 , T_2 V_79 )
{
struct V_2 * V_3 = NULL ;
struct V_13 * V_13 ;
int V_40 ;
enum V_80 type ;
V_13 = F_18 ( sizeof( * V_13 ) , V_26 ) ;
if ( ! V_13 ) {
V_40 = - V_81 ;
goto V_82;
}
V_3 = & V_13 -> V_29 ;
V_13 -> V_15 = V_15 ;
V_13 -> V_16 = F_104 ( V_15 ) ;
V_13 -> V_83 = F_105 ( V_15 , V_13 -> V_84 ,
F_106 ( V_13 -> V_84 ) ) ;
V_13 -> V_76 = F_107 ( V_15 ) ;
V_13 -> V_79 = V_79 ;
F_108 ( & V_13 -> V_49 ) ;
type = V_78 ? V_27 : V_85 ;
V_40 = F_109 ( V_6 , V_3 , 0xff , & V_86 ,
V_13 -> V_84 , V_13 -> V_83 ,
type ) ;
if ( V_40 )
goto V_82;
F_110 ( V_3 , & V_87 ) ;
F_13 ( V_3 , & V_3 -> V_29 ) ;
return V_3 ;
V_82:
if ( V_3 )
F_9 ( V_3 ) ;
return F_111 ( V_40 ) ;
}
