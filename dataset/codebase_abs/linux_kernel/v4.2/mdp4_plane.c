static inline
enum V_1 F_1 ( struct V_2 * V_3 )
{
bool V_4 = false ;
if ( V_3 -> V_5 [ 1 ] == V_6 )
V_4 = true ;
if ( V_3 -> V_7 == V_8 && V_4 )
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
void F_10 ( struct V_12 * V_13 ,
struct V_20 * V_21 )
{
}
int F_11 ( struct V_12 * V_13 ,
struct V_22 * V_23 , T_1 V_24 )
{
return - V_25 ;
}
static int F_12 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
const struct V_26 * V_27 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
F_13 ( L_1 , V_19 -> V_28 , V_3 -> V_29 . V_30 ) ;
return F_14 ( V_3 , V_11 -> V_30 ) ;
}
static void F_15 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
const struct V_26 * V_31 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
F_13 ( L_2 , V_19 -> V_28 , V_3 -> V_29 . V_30 ) ;
F_16 ( V_3 , V_11 -> V_30 ) ;
}
static int F_17 ( struct V_12 * V_13 ,
struct V_26 * V_32 )
{
return 0 ;
}
static void F_18 ( struct V_12 * V_13 ,
struct V_26 * V_31 )
{
struct V_26 * V_32 = V_13 -> V_32 ;
int V_33 ;
V_33 = F_19 ( V_13 ,
V_32 -> V_34 , V_32 -> V_3 ,
V_32 -> V_35 , V_32 -> V_36 ,
V_32 -> V_37 , V_32 -> V_38 ,
V_32 -> V_39 , V_32 -> V_40 ,
V_32 -> V_41 , V_32 -> V_42 ) ;
F_20 ( V_33 < 0 ) ;
}
static void F_21 ( struct V_12 * V_13 ,
struct V_2 * V_3 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
enum V_43 V_44 = V_19 -> V_44 ;
F_22 ( V_11 , F_23 ( V_44 ) ,
F_24 ( V_3 -> V_45 [ 0 ] ) |
F_25 ( V_3 -> V_45 [ 1 ] ) ) ;
F_22 ( V_11 , F_26 ( V_44 ) ,
F_27 ( V_3 -> V_45 [ 2 ] ) |
F_28 ( V_3 -> V_45 [ 3 ] ) ) ;
F_22 ( V_11 , F_29 ( V_44 ) ,
F_30 ( V_3 , V_11 -> V_30 , 0 ) ) ;
F_22 ( V_11 , F_31 ( V_44 ) ,
F_30 ( V_3 , V_11 -> V_30 , 1 ) ) ;
F_22 ( V_11 , F_32 ( V_44 ) ,
F_30 ( V_3 , V_11 -> V_30 , 2 ) ) ;
F_22 ( V_11 , F_33 ( V_44 ) ,
F_30 ( V_3 , V_11 -> V_30 , 3 ) ) ;
V_13 -> V_3 = V_3 ;
}
static void F_34 ( struct V_11 * V_11 ,
enum V_43 V_44 , struct V_46 * V_47 )
{
int V_48 ;
for ( V_48 = 0 ; V_48 < F_35 ( V_47 -> V_49 ) ; V_48 ++ ) {
F_22 ( V_11 , F_36 ( V_44 , V_48 ) ,
V_47 -> V_49 [ V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < F_35 ( V_47 -> V_50 ) ; V_48 ++ ) {
F_22 ( V_11 , F_37 ( V_44 , V_48 ) ,
V_47 -> V_51 [ V_48 ] ) ;
F_22 ( V_11 , F_38 ( V_44 , V_48 ) ,
V_47 -> V_50 [ V_48 ] ) ;
}
for ( V_48 = 0 ; V_48 < F_35 ( V_47 -> V_52 ) ; V_48 ++ ) {
F_22 ( V_11 , F_39 ( V_44 , V_48 ) ,
V_47 -> V_53 [ V_48 ] ) ;
F_22 ( V_11 , F_40 ( V_44 , V_48 ) ,
V_47 -> V_52 [ V_48 ] ) ;
}
}
static int F_19 ( struct V_12 * V_13 ,
struct V_54 * V_34 , struct V_2 * V_3 ,
int V_35 , int V_36 ,
unsigned int V_37 , unsigned int V_38 ,
T_2 V_39 , T_2 V_40 ,
T_2 V_41 , T_2 V_42 )
{
struct V_55 * V_16 = V_13 -> V_16 ;
struct V_19 * V_19 = F_6 ( V_13 ) ;
struct V_11 * V_11 = F_2 ( V_13 ) ;
enum V_43 V_44 = V_19 -> V_44 ;
const struct V_56 * V_57 ;
T_2 V_58 = 0 ;
T_2 V_59 = V_60 ;
T_2 V_61 = V_60 ;
enum V_1 V_62 ;
if ( ! ( V_34 && V_3 ) ) {
F_13 ( L_3 , V_19 -> V_28 ) ;
return 0 ;
}
V_62 = F_1 ( V_3 ) ;
V_39 = V_39 >> 16 ;
V_40 = V_40 >> 16 ;
V_41 = V_41 >> 16 ;
V_42 = V_42 >> 16 ;
F_13 ( L_4 , V_19 -> V_28 ,
V_3 -> V_29 . V_30 , V_39 , V_40 , V_41 , V_42 ,
V_34 -> V_29 . V_30 , V_35 , V_36 , V_37 , V_38 ) ;
V_57 = F_41 ( F_42 ( V_3 ) ) ;
if ( V_41 > ( V_37 * V_63 ) ) {
F_43 ( V_16 -> V_16 , L_5 ) ;
return - V_64 ;
}
if ( V_42 > ( V_38 * V_63 ) ) {
F_43 ( V_16 -> V_16 , L_6 ) ;
return - V_64 ;
}
if ( V_37 > ( V_41 * V_65 ) ) {
F_43 ( V_16 -> V_16 , L_7 ) ;
return - V_64 ;
}
if ( V_38 > ( V_42 * V_65 ) ) {
F_43 ( V_16 -> V_16 , L_8 ) ;
return - V_64 ;
}
if ( V_41 != V_37 ) {
T_2 V_66 = V_67 ;
V_58 |= V_68 ;
if ( F_44 ( V_57 ) ) {
if ( V_37 > V_41 )
V_66 = V_69 ;
else if ( V_37 <= ( V_41 / 4 ) )
V_66 = V_70 ;
V_58 |= F_45 ( V_66 ) ;
V_59 = F_46 ( V_60 ,
V_41 , V_37 ) ;
}
}
if ( V_42 != V_38 ) {
T_2 V_66 = V_67 ;
V_58 |= V_71 ;
if ( F_44 ( V_57 ) ) {
if ( V_38 > V_42 )
V_66 = V_69 ;
else if ( V_38 <= ( V_42 / 4 ) )
V_66 = V_70 ;
V_58 |= F_47 ( V_66 ) ;
V_61 = F_46 ( V_60 ,
V_42 , V_38 ) ;
}
}
F_22 ( V_11 , F_48 ( V_44 ) ,
F_49 ( V_41 ) |
F_50 ( V_42 ) ) ;
F_22 ( V_11 , F_51 ( V_44 ) ,
F_52 ( V_39 ) |
F_53 ( V_40 ) ) ;
F_22 ( V_11 , F_54 ( V_44 ) ,
F_55 ( V_37 ) |
F_56 ( V_38 ) ) ;
F_22 ( V_11 , F_57 ( V_44 ) ,
F_58 ( V_35 ) |
F_59 ( V_36 ) ) ;
F_21 ( V_13 , V_3 ) ;
F_22 ( V_11 , F_60 ( V_44 ) ,
F_61 ( V_57 -> V_72 ) |
F_62 ( V_57 -> V_73 ) |
F_63 ( V_57 -> V_74 ) |
F_64 ( V_57 -> V_75 ) |
F_65 ( V_57 -> V_76 , V_77 ) |
F_66 ( V_57 -> V_78 - 1 ) |
F_67 ( V_57 -> V_79 - 1 ) |
F_68 ( V_57 -> V_80 ) |
F_69 ( V_57 -> V_81 ) |
F_70 ( V_62 ) |
F_65 ( V_57 -> V_82 , V_83 ) ) ;
F_22 ( V_11 , F_71 ( V_44 ) ,
F_72 ( V_57 -> V_84 [ 0 ] ) |
F_73 ( V_57 -> V_84 [ 1 ] ) |
F_74 ( V_57 -> V_84 [ 2 ] ) |
F_75 ( V_57 -> V_84 [ 3 ] ) ) ;
if ( F_44 ( V_57 ) ) {
struct V_46 * V_47 = F_76 ( V_85 ) ;
V_58 |= V_86 ;
V_58 |= V_87 ;
F_34 ( V_11 , V_44 , V_47 ) ;
}
F_22 ( V_11 , F_77 ( V_44 ) , V_58 ) ;
F_22 ( V_11 , F_78 ( V_44 ) , V_59 ) ;
F_22 ( V_11 , F_79 ( V_44 ) , V_61 ) ;
if ( V_62 != V_10 )
F_22 ( V_11 , F_80 ( V_44 ) ,
F_81 ( V_41 ) |
F_82 ( V_42 ) ) ;
return 0 ;
}
enum V_43 F_83 ( struct V_12 * V_13 )
{
struct V_19 * V_19 = F_6 ( V_13 ) ;
return V_19 -> V_44 ;
}
struct V_12 * F_84 ( struct V_55 * V_16 ,
enum V_43 V_88 , bool V_89 )
{
struct V_12 * V_13 = NULL ;
struct V_19 * V_19 ;
int V_33 ;
enum V_90 type ;
V_19 = F_85 ( sizeof( * V_19 ) , V_91 ) ;
if ( ! V_19 ) {
V_33 = - V_92 ;
goto V_93;
}
V_13 = & V_19 -> V_29 ;
V_19 -> V_44 = V_88 ;
V_19 -> V_28 = V_94 [ V_88 ] ;
V_19 -> V_95 = F_86 ( V_88 , V_19 -> V_96 ,
F_35 ( V_19 -> V_96 ) ) ;
type = V_89 ? V_97 : V_98 ;
V_33 = F_87 ( V_16 , V_13 , 0xff , & V_99 ,
V_19 -> V_96 , V_19 -> V_95 , type ) ;
if ( V_33 )
goto V_93;
F_88 ( V_13 , & V_100 ) ;
F_10 ( V_13 , & V_13 -> V_29 ) ;
return V_13 ;
V_93:
if ( V_13 )
F_5 ( V_13 ) ;
return F_89 ( V_33 ) ;
}
