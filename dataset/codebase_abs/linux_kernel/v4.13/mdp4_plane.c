static inline
enum V_1 F_1 ( struct V_2 * V_3 )
{
bool V_4 = false ;
if ( V_3 -> V_5 == V_6 )
V_4 = true ;
if ( V_3 -> V_7 -> V_7 == V_8 && V_4 )
return V_9 ;
return V_10 ;
}
static struct V_11 * F_2 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_16 -> V_17 ;
return F_3 ( F_4 ( V_15 -> V_18 ) ) ;
}
static void F_5 ( struct V_12 * V_13 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
F_7 ( V_13 ) ;
F_8 ( V_13 ) ;
F_9 ( V_19 ) ;
}
static void F_10 ( struct V_12 * V_13 ,
struct V_20 * V_21 )
{
}
static int F_11 ( struct V_12 * V_13 ,
struct V_22 * V_23 , T_1 V_24 )
{
return - V_25 ;
}
static int F_12 ( struct V_12 * V_13 ,
struct V_26 * V_27 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
struct V_28 * V_18 = & V_11 -> V_29 . V_29 ;
struct V_2 * V_3 = V_27 -> V_3 ;
if ( ! V_3 )
return 0 ;
F_13 ( L_1 , V_19 -> V_30 , V_3 -> V_29 . V_31 ) ;
return F_14 ( V_3 , V_18 -> V_32 ) ;
}
static void F_15 ( struct V_12 * V_13 ,
struct V_26 * V_33 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
struct V_28 * V_18 = & V_11 -> V_29 . V_29 ;
struct V_2 * V_3 = V_33 -> V_3 ;
if ( ! V_3 )
return;
F_13 ( L_2 , V_19 -> V_30 , V_3 -> V_29 . V_31 ) ;
F_16 ( V_3 , V_18 -> V_32 ) ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_26 * V_34 )
{
return 0 ;
}
static void F_18 ( struct V_12 * V_13 ,
struct V_26 * V_33 )
{
struct V_26 * V_34 = V_13 -> V_34 ;
int V_35 ;
V_35 = F_19 ( V_13 ,
V_34 -> V_36 , V_34 -> V_3 ,
V_34 -> V_37 , V_34 -> V_38 ,
V_34 -> V_39 , V_34 -> V_40 ,
V_34 -> V_41 , V_34 -> V_42 ,
V_34 -> V_43 , V_34 -> V_44 ) ;
F_20 ( V_35 < 0 ) ;
}
static void F_21 ( struct V_12 * V_13 ,
struct V_2 * V_3 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
struct V_28 * V_18 = & V_11 -> V_29 . V_29 ;
enum V_45 V_46 = V_19 -> V_46 ;
F_22 ( V_11 , F_23 ( V_46 ) ,
F_24 ( V_3 -> V_47 [ 0 ] ) |
F_25 ( V_3 -> V_47 [ 1 ] ) ) ;
F_22 ( V_11 , F_26 ( V_46 ) ,
F_27 ( V_3 -> V_47 [ 2 ] ) |
F_28 ( V_3 -> V_47 [ 3 ] ) ) ;
F_22 ( V_11 , F_29 ( V_46 ) ,
F_30 ( V_3 , V_18 -> V_32 , 0 ) ) ;
F_22 ( V_11 , F_31 ( V_46 ) ,
F_30 ( V_3 , V_18 -> V_32 , 1 ) ) ;
F_22 ( V_11 , F_32 ( V_46 ) ,
F_30 ( V_3 , V_18 -> V_32 , 2 ) ) ;
F_22 ( V_11 , F_33 ( V_46 ) ,
F_30 ( V_3 , V_18 -> V_32 , 3 ) ) ;
V_13 -> V_3 = V_3 ;
}
static void F_34 ( struct V_11 * V_11 ,
enum V_45 V_46 , struct V_48 * V_49 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < F_35 ( V_49 -> V_51 ) ; V_50 ++ ) {
F_22 ( V_11 , F_36 ( V_46 , V_50 ) ,
V_49 -> V_51 [ V_50 ] ) ;
}
for ( V_50 = 0 ; V_50 < F_35 ( V_49 -> V_52 ) ; V_50 ++ ) {
F_22 ( V_11 , F_37 ( V_46 , V_50 ) ,
V_49 -> V_53 [ V_50 ] ) ;
F_22 ( V_11 , F_38 ( V_46 , V_50 ) ,
V_49 -> V_52 [ V_50 ] ) ;
}
for ( V_50 = 0 ; V_50 < F_35 ( V_49 -> V_54 ) ; V_50 ++ ) {
F_22 ( V_11 , F_39 ( V_46 , V_50 ) ,
V_49 -> V_55 [ V_50 ] ) ;
F_22 ( V_11 , F_40 ( V_46 , V_50 ) ,
V_49 -> V_54 [ V_50 ] ) ;
}
}
static int F_19 ( struct V_12 * V_13 ,
struct V_56 * V_36 , struct V_2 * V_3 ,
int V_37 , int V_38 ,
unsigned int V_39 , unsigned int V_40 ,
T_2 V_41 , T_2 V_42 ,
T_2 V_43 , T_2 V_44 )
{
struct V_57 * V_16 = V_13 -> V_16 ;
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
enum V_45 V_46 = V_19 -> V_46 ;
const struct V_58 * V_7 ;
T_2 V_59 = 0 ;
T_2 V_60 = V_61 ;
T_2 V_62 = V_61 ;
enum V_1 V_63 ;
if ( ! ( V_36 && V_3 ) ) {
F_13 ( L_3 , V_19 -> V_30 ) ;
return 0 ;
}
V_63 = F_1 ( V_3 ) ;
V_41 = V_41 >> 16 ;
V_42 = V_42 >> 16 ;
V_43 = V_43 >> 16 ;
V_44 = V_44 >> 16 ;
F_13 ( L_4 , V_19 -> V_30 ,
V_3 -> V_29 . V_31 , V_41 , V_42 , V_43 , V_44 ,
V_36 -> V_29 . V_31 , V_37 , V_38 , V_39 , V_40 ) ;
V_7 = F_41 ( F_42 ( V_3 ) ) ;
if ( V_43 > ( V_39 * V_64 ) ) {
F_43 ( V_16 -> V_16 , L_5 ) ;
return - V_65 ;
}
if ( V_44 > ( V_40 * V_64 ) ) {
F_43 ( V_16 -> V_16 , L_6 ) ;
return - V_65 ;
}
if ( V_39 > ( V_43 * V_66 ) ) {
F_43 ( V_16 -> V_16 , L_7 ) ;
return - V_65 ;
}
if ( V_40 > ( V_44 * V_66 ) ) {
F_43 ( V_16 -> V_16 , L_8 ) ;
return - V_65 ;
}
if ( V_43 != V_39 ) {
T_2 V_67 = V_68 ;
V_59 |= V_69 ;
if ( F_44 ( V_7 ) ) {
if ( V_39 > V_43 )
V_67 = V_70 ;
else if ( V_39 <= ( V_43 / 4 ) )
V_67 = V_71 ;
V_59 |= F_45 ( V_67 ) ;
V_60 = F_46 ( V_61 ,
V_43 , V_39 ) ;
}
}
if ( V_44 != V_40 ) {
T_2 V_67 = V_68 ;
V_59 |= V_72 ;
if ( F_44 ( V_7 ) ) {
if ( V_40 > V_44 )
V_67 = V_70 ;
else if ( V_40 <= ( V_44 / 4 ) )
V_67 = V_71 ;
V_59 |= F_47 ( V_67 ) ;
V_62 = F_46 ( V_61 ,
V_44 , V_40 ) ;
}
}
F_22 ( V_11 , F_48 ( V_46 ) ,
F_49 ( V_43 ) |
F_50 ( V_44 ) ) ;
F_22 ( V_11 , F_51 ( V_46 ) ,
F_52 ( V_41 ) |
F_53 ( V_42 ) ) ;
F_22 ( V_11 , F_54 ( V_46 ) ,
F_55 ( V_39 ) |
F_56 ( V_40 ) ) ;
F_22 ( V_11 , F_57 ( V_46 ) ,
F_58 ( V_37 ) |
F_59 ( V_38 ) ) ;
F_21 ( V_13 , V_3 ) ;
F_22 ( V_11 , F_60 ( V_46 ) ,
F_61 ( V_7 -> V_73 ) |
F_62 ( V_7 -> V_74 ) |
F_63 ( V_7 -> V_75 ) |
F_64 ( V_7 -> V_76 ) |
F_65 ( V_7 -> V_77 , V_78 ) |
F_66 ( V_7 -> V_79 - 1 ) |
F_67 ( V_7 -> V_80 - 1 ) |
F_68 ( V_7 -> V_81 ) |
F_69 ( V_7 -> V_82 ) |
F_70 ( V_63 ) |
F_65 ( V_7 -> V_83 , V_84 ) ) ;
F_22 ( V_11 , F_71 ( V_46 ) ,
F_72 ( V_7 -> V_85 [ 0 ] ) |
F_73 ( V_7 -> V_85 [ 1 ] ) |
F_74 ( V_7 -> V_85 [ 2 ] ) |
F_75 ( V_7 -> V_85 [ 3 ] ) ) ;
if ( F_44 ( V_7 ) ) {
struct V_48 * V_49 = F_76 ( V_86 ) ;
V_59 |= V_87 ;
V_59 |= V_88 ;
F_34 ( V_11 , V_46 , V_49 ) ;
}
F_22 ( V_11 , F_77 ( V_46 ) , V_59 ) ;
F_22 ( V_11 , F_78 ( V_46 ) , V_60 ) ;
F_22 ( V_11 , F_79 ( V_46 ) , V_62 ) ;
if ( V_63 != V_10 )
F_22 ( V_11 , F_80 ( V_46 ) ,
F_81 ( V_43 ) |
F_82 ( V_44 ) ) ;
return 0 ;
}
enum V_45 F_83 ( struct V_12 * V_13 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
return V_19 -> V_46 ;
}
struct V_12 * F_84 ( struct V_57 * V_16 ,
enum V_45 V_89 , bool V_90 )
{
struct V_12 * V_13 = NULL ;
struct V_19 * V_19 ;
int V_35 ;
enum V_91 type ;
V_19 = F_85 ( sizeof( * V_19 ) , V_92 ) ;
if ( ! V_19 ) {
V_35 = - V_93 ;
goto V_94;
}
V_13 = & V_19 -> V_29 ;
V_19 -> V_46 = V_89 ;
V_19 -> V_30 = V_95 [ V_89 ] ;
V_19 -> V_96 = F_86 ( V_89 ) ;
V_19 -> V_97 = F_87 ( V_19 -> V_98 ,
F_35 ( V_19 -> V_98 ) ,
! F_88 ( V_19 -> V_96 ) ) ;
type = V_90 ? V_99 : V_100 ;
V_35 = F_89 ( V_16 , V_13 , 0xff , & V_101 ,
V_19 -> V_98 , V_19 -> V_97 ,
type , NULL ) ;
if ( V_35 )
goto V_94;
F_90 ( V_13 , & V_102 ) ;
F_10 ( V_13 , & V_13 -> V_29 ) ;
return V_13 ;
V_94:
if ( V_13 )
F_5 ( V_13 ) ;
return F_91 ( V_35 ) ;
}
