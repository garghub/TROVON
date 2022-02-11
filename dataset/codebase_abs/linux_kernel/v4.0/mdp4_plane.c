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
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_1 , V_9 -> V_18 , V_17 -> V_19 . V_20 ) ;
return F_13 ( V_17 , V_1 -> V_20 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_12 ( L_2 , V_9 -> V_18 , V_17 -> V_19 . V_20 ) ;
F_15 ( V_17 , V_1 -> V_20 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_21 * V_22 )
{
return 0 ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_21 * V_23 )
{
struct V_21 * V_22 = V_3 -> V_22 ;
int V_24 ;
V_24 = F_18 ( V_3 ,
V_22 -> V_25 , V_22 -> V_17 ,
V_22 -> V_26 , V_22 -> V_27 ,
V_22 -> V_28 , V_22 -> V_29 ,
V_22 -> V_30 , V_22 -> V_31 ,
V_22 -> V_32 , V_22 -> V_33 ) ;
F_19 ( V_24 < 0 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_34 V_35 = V_9 -> V_35 ;
F_21 ( V_1 , F_22 ( V_35 ) ,
F_23 ( V_17 -> V_36 [ 0 ] ) |
F_24 ( V_17 -> V_36 [ 1 ] ) ) ;
F_21 ( V_1 , F_25 ( V_35 ) ,
F_26 ( V_17 -> V_36 [ 2 ] ) |
F_27 ( V_17 -> V_36 [ 3 ] ) ) ;
F_21 ( V_1 , F_28 ( V_35 ) ,
F_29 ( V_17 , V_1 -> V_20 , 0 ) ) ;
F_21 ( V_1 , F_30 ( V_35 ) ,
F_29 ( V_17 , V_1 -> V_20 , 1 ) ) ;
F_21 ( V_1 , F_31 ( V_35 ) ,
F_29 ( V_17 , V_1 -> V_20 , 2 ) ) ;
F_21 ( V_1 , F_32 ( V_35 ) ,
F_29 ( V_17 , V_1 -> V_20 , 3 ) ) ;
V_3 -> V_17 = V_17 ;
}
static void F_33 ( struct V_1 * V_1 ,
enum V_34 V_35 , struct V_37 * V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_34 ( V_38 -> V_40 ) ; V_39 ++ ) {
F_21 ( V_1 , F_35 ( V_35 , V_39 ) ,
V_38 -> V_40 [ V_39 ] ) ;
}
for ( V_39 = 0 ; V_39 < F_34 ( V_38 -> V_41 ) ; V_39 ++ ) {
F_21 ( V_1 , F_36 ( V_35 , V_39 ) ,
V_38 -> V_42 [ V_39 ] ) ;
F_21 ( V_1 , F_37 ( V_35 , V_39 ) ,
V_38 -> V_41 [ V_39 ] ) ;
}
for ( V_39 = 0 ; V_39 < F_34 ( V_38 -> V_43 ) ; V_39 ++ ) {
F_21 ( V_1 , F_38 ( V_35 , V_39 ) ,
V_38 -> V_44 [ V_39 ] ) ;
F_21 ( V_1 , F_39 ( V_35 , V_39 ) ,
V_38 -> V_43 [ V_39 ] ) ;
}
}
static int F_18 ( struct V_2 * V_3 ,
struct V_45 * V_25 , struct V_16 * V_17 ,
int V_26 , int V_27 ,
unsigned int V_28 , unsigned int V_29 ,
T_2 V_30 , T_2 V_31 ,
T_2 V_32 , T_2 V_33 )
{
struct V_46 * V_6 = V_3 -> V_6 ;
struct V_9 * V_9 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_34 V_35 = V_9 -> V_35 ;
const struct V_47 * V_48 ;
T_2 V_49 = 0 ;
T_2 V_50 = V_51 ;
T_2 V_52 = V_51 ;
if ( ! ( V_25 && V_17 ) ) {
F_12 ( L_3 , V_9 -> V_18 ) ;
return 0 ;
}
V_30 = V_30 >> 16 ;
V_31 = V_31 >> 16 ;
V_32 = V_32 >> 16 ;
V_33 = V_33 >> 16 ;
F_12 ( L_4 , V_9 -> V_18 ,
V_17 -> V_19 . V_20 , V_30 , V_31 , V_32 , V_33 ,
V_25 -> V_19 . V_20 , V_26 , V_27 , V_28 , V_29 ) ;
V_48 = F_40 ( F_41 ( V_17 ) ) ;
if ( V_32 > ( V_28 * V_53 ) ) {
F_42 ( V_6 -> V_6 , L_5 ) ;
return - V_54 ;
}
if ( V_33 > ( V_29 * V_53 ) ) {
F_42 ( V_6 -> V_6 , L_6 ) ;
return - V_54 ;
}
if ( V_28 > ( V_32 * V_55 ) ) {
F_42 ( V_6 -> V_6 , L_7 ) ;
return - V_54 ;
}
if ( V_29 > ( V_33 * V_55 ) ) {
F_42 ( V_6 -> V_6 , L_8 ) ;
return - V_54 ;
}
if ( V_32 != V_28 ) {
T_2 V_56 = V_57 ;
V_49 |= V_58 ;
if ( F_43 ( V_48 ) ) {
if ( V_28 > V_32 )
V_56 = V_59 ;
else if ( V_28 <= ( V_32 / 4 ) )
V_56 = V_60 ;
V_49 |= F_44 ( V_56 ) ;
V_50 = F_45 ( V_51 ,
V_32 , V_28 ) ;
}
}
if ( V_33 != V_29 ) {
T_2 V_56 = V_57 ;
V_49 |= V_61 ;
if ( F_43 ( V_48 ) ) {
if ( V_29 > V_33 )
V_56 = V_59 ;
else if ( V_29 <= ( V_33 / 4 ) )
V_56 = V_60 ;
V_49 |= F_46 ( V_56 ) ;
V_52 = F_45 ( V_51 ,
V_33 , V_29 ) ;
}
}
F_21 ( V_1 , F_47 ( V_35 ) ,
F_48 ( V_32 ) |
F_49 ( V_33 ) ) ;
F_21 ( V_1 , F_50 ( V_35 ) ,
F_51 ( V_30 ) |
F_52 ( V_31 ) ) ;
F_21 ( V_1 , F_53 ( V_35 ) ,
F_54 ( V_28 ) |
F_55 ( V_29 ) ) ;
F_21 ( V_1 , F_56 ( V_35 ) ,
F_57 ( V_26 ) |
F_58 ( V_27 ) ) ;
F_20 ( V_3 , V_17 ) ;
F_21 ( V_1 , F_59 ( V_35 ) ,
F_60 ( V_48 -> V_62 ) |
F_61 ( V_48 -> V_63 ) |
F_62 ( V_48 -> V_64 ) |
F_63 ( V_48 -> V_65 ) |
F_64 ( V_48 -> V_66 , V_67 ) |
F_65 ( V_48 -> V_68 - 1 ) |
F_66 ( V_48 -> V_69 - 1 ) |
F_67 ( V_48 -> V_70 ) |
F_68 ( V_48 -> V_71 ) |
F_64 ( V_48 -> V_72 , V_73 ) ) ;
F_21 ( V_1 , F_69 ( V_35 ) ,
F_70 ( V_48 -> V_74 [ 0 ] ) |
F_71 ( V_48 -> V_74 [ 1 ] ) |
F_72 ( V_48 -> V_74 [ 2 ] ) |
F_73 ( V_48 -> V_74 [ 3 ] ) ) ;
if ( F_43 ( V_48 ) ) {
struct V_37 * V_38 = F_74 ( V_75 ) ;
V_49 |= V_76 ;
V_49 |= V_77 ;
F_33 ( V_1 , V_35 , V_38 ) ;
}
F_21 ( V_1 , F_75 ( V_35 ) , V_49 ) ;
F_21 ( V_1 , F_76 ( V_35 ) , V_50 ) ;
F_21 ( V_1 , F_77 ( V_35 ) , V_52 ) ;
return 0 ;
}
enum V_34 F_78 ( struct V_2 * V_3 )
{
struct V_9 * V_9 = F_5 ( V_3 ) ;
return V_9 -> V_35 ;
}
struct V_2 * F_79 ( struct V_46 * V_6 ,
enum V_34 V_78 , bool V_79 )
{
struct V_2 * V_3 = NULL ;
struct V_9 * V_9 ;
int V_24 ;
enum V_80 type ;
V_9 = F_80 ( sizeof( * V_9 ) , V_81 ) ;
if ( ! V_9 ) {
V_24 = - V_82 ;
goto V_83;
}
V_3 = & V_9 -> V_19 ;
V_9 -> V_35 = V_78 ;
V_9 -> V_18 = V_84 [ V_78 ] ;
V_9 -> V_85 = F_81 ( V_78 , V_9 -> V_86 ,
F_34 ( V_9 -> V_86 ) ) ;
type = V_79 ? V_87 : V_88 ;
V_24 = F_82 ( V_6 , V_3 , 0xff , & V_89 ,
V_9 -> V_86 , V_9 -> V_85 , type ) ;
if ( V_24 )
goto V_83;
F_83 ( V_3 , & V_90 ) ;
F_9 ( V_3 , & V_3 -> V_19 ) ;
return V_3 ;
V_83:
if ( V_3 )
F_4 ( V_3 ) ;
return F_84 ( V_24 ) ;
}
