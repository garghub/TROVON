static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static void F_4 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
F_7 ( V_3 ) ;
F_8 ( V_9 ) ;
}
void F_9 ( struct V_2 * V_3 ,
struct V_10 * V_11 )
{
}
int F_10 ( struct V_2 * V_3 ,
struct V_12 * V_13 , T_1 V_14 )
{
return - V_15 ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_1 , V_9 -> V_20 , V_17 -> V_21 . V_22 ) ;
return F_13 ( V_17 , V_1 -> V_22 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_16 * V_17 ,
const struct V_18 * V_23 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_2 , V_9 -> V_20 , V_17 -> V_21 . V_22 ) ;
F_15 ( V_17 , V_1 -> V_22 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_18 * V_24 )
{
return 0 ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_18 * V_23 )
{
struct V_18 * V_24 = V_3 -> V_24 ;
int V_25 ;
V_25 = F_18 ( V_3 ,
V_24 -> V_26 , V_24 -> V_17 ,
V_24 -> V_27 , V_24 -> V_28 ,
V_24 -> V_29 , V_24 -> V_30 ,
V_24 -> V_31 , V_24 -> V_32 ,
V_24 -> V_33 , V_24 -> V_34 ) ;
F_19 ( V_25 < 0 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_35 V_36 = V_9 -> V_36 ;
F_21 ( V_1 , F_22 ( V_36 ) ,
F_23 ( V_17 -> V_37 [ 0 ] ) |
F_24 ( V_17 -> V_37 [ 1 ] ) ) ;
F_21 ( V_1 , F_25 ( V_36 ) ,
F_26 ( V_17 -> V_37 [ 2 ] ) |
F_27 ( V_17 -> V_37 [ 3 ] ) ) ;
F_21 ( V_1 , F_28 ( V_36 ) ,
F_29 ( V_17 , V_1 -> V_22 , 0 ) ) ;
F_21 ( V_1 , F_30 ( V_36 ) ,
F_29 ( V_17 , V_1 -> V_22 , 1 ) ) ;
F_21 ( V_1 , F_31 ( V_36 ) ,
F_29 ( V_17 , V_1 -> V_22 , 2 ) ) ;
F_21 ( V_1 , F_32 ( V_36 ) ,
F_29 ( V_17 , V_1 -> V_22 , 3 ) ) ;
V_3 -> V_17 = V_17 ;
}
static void F_33 ( struct V_1 * V_1 ,
enum V_35 V_36 , struct V_38 * V_39 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < F_34 ( V_39 -> V_41 ) ; V_40 ++ ) {
F_21 ( V_1 , F_35 ( V_36 , V_40 ) ,
V_39 -> V_41 [ V_40 ] ) ;
}
for ( V_40 = 0 ; V_40 < F_34 ( V_39 -> V_42 ) ; V_40 ++ ) {
F_21 ( V_1 , F_36 ( V_36 , V_40 ) ,
V_39 -> V_43 [ V_40 ] ) ;
F_21 ( V_1 , F_37 ( V_36 , V_40 ) ,
V_39 -> V_42 [ V_40 ] ) ;
}
for ( V_40 = 0 ; V_40 < F_34 ( V_39 -> V_44 ) ; V_40 ++ ) {
F_21 ( V_1 , F_38 ( V_36 , V_40 ) ,
V_39 -> V_45 [ V_40 ] ) ;
F_21 ( V_1 , F_39 ( V_36 , V_40 ) ,
V_39 -> V_44 [ V_40 ] ) ;
}
}
static int F_18 ( struct V_2 * V_3 ,
struct V_46 * V_26 , struct V_16 * V_17 ,
int V_27 , int V_28 ,
unsigned int V_29 , unsigned int V_30 ,
T_2 V_31 , T_2 V_32 ,
T_2 V_33 , T_2 V_34 )
{
struct V_47 * V_6 = V_3 -> V_6 ;
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_35 V_36 = V_9 -> V_36 ;
const struct V_48 * V_49 ;
T_2 V_50 = 0 ;
T_2 V_51 = V_52 ;
T_2 V_53 = V_52 ;
if ( ! ( V_26 && V_17 ) ) {
F_12 ( L_3 , V_9 -> V_20 ) ;
return 0 ;
}
V_31 = V_31 >> 16 ;
V_32 = V_32 >> 16 ;
V_33 = V_33 >> 16 ;
V_34 = V_34 >> 16 ;
F_12 ( L_4 , V_9 -> V_20 ,
V_17 -> V_21 . V_22 , V_31 , V_32 , V_33 , V_34 ,
V_26 -> V_21 . V_22 , V_27 , V_28 , V_29 , V_30 ) ;
V_49 = F_40 ( F_41 ( V_17 ) ) ;
if ( V_33 > ( V_29 * V_54 ) ) {
F_42 ( V_6 -> V_6 , L_5 ) ;
return - V_55 ;
}
if ( V_34 > ( V_30 * V_54 ) ) {
F_42 ( V_6 -> V_6 , L_6 ) ;
return - V_55 ;
}
if ( V_29 > ( V_33 * V_56 ) ) {
F_42 ( V_6 -> V_6 , L_7 ) ;
return - V_55 ;
}
if ( V_30 > ( V_34 * V_56 ) ) {
F_42 ( V_6 -> V_6 , L_8 ) ;
return - V_55 ;
}
if ( V_33 != V_29 ) {
T_2 V_57 = V_58 ;
V_50 |= V_59 ;
if ( F_43 ( V_49 ) ) {
if ( V_29 > V_33 )
V_57 = V_60 ;
else if ( V_29 <= ( V_33 / 4 ) )
V_57 = V_61 ;
V_50 |= F_44 ( V_57 ) ;
V_51 = F_45 ( V_52 ,
V_33 , V_29 ) ;
}
}
if ( V_34 != V_30 ) {
T_2 V_57 = V_58 ;
V_50 |= V_62 ;
if ( F_43 ( V_49 ) ) {
if ( V_30 > V_34 )
V_57 = V_60 ;
else if ( V_30 <= ( V_34 / 4 ) )
V_57 = V_61 ;
V_50 |= F_46 ( V_57 ) ;
V_53 = F_45 ( V_52 ,
V_34 , V_30 ) ;
}
}
F_21 ( V_1 , F_47 ( V_36 ) ,
F_48 ( V_33 ) |
F_49 ( V_34 ) ) ;
F_21 ( V_1 , F_50 ( V_36 ) ,
F_51 ( V_31 ) |
F_52 ( V_32 ) ) ;
F_21 ( V_1 , F_53 ( V_36 ) ,
F_54 ( V_29 ) |
F_55 ( V_30 ) ) ;
F_21 ( V_1 , F_56 ( V_36 ) ,
F_57 ( V_27 ) |
F_58 ( V_28 ) ) ;
F_20 ( V_3 , V_17 ) ;
F_21 ( V_1 , F_59 ( V_36 ) ,
F_60 ( V_49 -> V_63 ) |
F_61 ( V_49 -> V_64 ) |
F_62 ( V_49 -> V_65 ) |
F_63 ( V_49 -> V_66 ) |
F_64 ( V_49 -> V_67 , V_68 ) |
F_65 ( V_49 -> V_69 - 1 ) |
F_66 ( V_49 -> V_70 - 1 ) |
F_67 ( V_49 -> V_71 ) |
F_68 ( V_49 -> V_72 ) |
F_64 ( V_49 -> V_73 , V_74 ) ) ;
F_21 ( V_1 , F_69 ( V_36 ) ,
F_70 ( V_49 -> V_75 [ 0 ] ) |
F_71 ( V_49 -> V_75 [ 1 ] ) |
F_72 ( V_49 -> V_75 [ 2 ] ) |
F_73 ( V_49 -> V_75 [ 3 ] ) ) ;
if ( F_43 ( V_49 ) ) {
struct V_38 * V_39 = F_74 ( V_76 ) ;
V_50 |= V_77 ;
V_50 |= V_78 ;
F_33 ( V_1 , V_36 , V_39 ) ;
}
F_21 ( V_1 , F_75 ( V_36 ) , V_50 ) ;
F_21 ( V_1 , F_76 ( V_36 ) , V_51 ) ;
F_21 ( V_1 , F_77 ( V_36 ) , V_53 ) ;
return 0 ;
}
enum V_35 F_78 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
return V_9 -> V_36 ;
}
struct V_2 * F_79 ( struct V_47 * V_6 ,
enum V_35 V_79 , bool V_80 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_25 ;
enum V_81 type ;
V_9 = F_80 ( sizeof( * V_9 ) , V_82 ) ;
if ( ! V_9 ) {
V_25 = - V_83 ;
goto V_84;
}
V_3 = & V_9 -> V_21 ;
V_9 -> V_36 = V_79 ;
V_9 -> V_20 = V_85 [ V_79 ] ;
V_9 -> V_86 = F_81 ( V_79 , V_9 -> V_87 ,
F_34 ( V_9 -> V_87 ) ) ;
type = V_80 ? V_88 : V_89 ;
V_25 = F_82 ( V_6 , V_3 , 0xff , & V_90 ,
V_9 -> V_87 , V_9 -> V_86 , type ) ;
if ( V_25 )
goto V_84;
F_83 ( V_3 , & V_91 ) ;
F_9 ( V_3 , & V_3 -> V_21 ) ;
return V_3 ;
V_84:
if ( V_3 )
F_4 ( V_3 ) ;
return F_84 ( V_25 ) ;
}
