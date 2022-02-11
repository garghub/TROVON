static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 -> V_7 ;
return F_2 ( F_3 ( V_5 -> V_8 ) ) ;
}
static int F_4 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
T_1 V_17 , T_1 V_18 ,
T_1 V_19 , T_1 V_20 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
V_21 -> V_22 = true ;
if ( V_3 -> V_12 )
F_6 ( V_3 -> V_12 ) ;
F_7 ( V_12 ) ;
return F_8 ( V_3 , V_10 , V_12 ,
V_13 , V_14 , V_15 , V_16 ,
V_17 , V_18 , V_19 , V_20 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_23 V_24 = V_21 -> V_24 ;
int V_25 ;
F_10 ( L_1 , V_21 -> V_26 ) ;
for ( V_25 = 0 ; V_25 < F_11 ( V_24 ) ; V_25 ++ )
F_12 ( V_1 , F_13 ( V_24 , V_25 ) , 0 ) ;
if ( V_3 -> V_10 )
F_14 ( V_3 -> V_10 , V_3 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
F_9 ( V_3 ) ;
F_16 ( V_3 ) ;
F_17 ( V_21 ) ;
}
void F_18 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
}
int F_19 ( struct V_2 * V_3 ,
struct V_29 * V_30 , T_2 V_31 )
{
return - V_32 ;
}
void F_20 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_23 V_24 = V_21 -> V_24 ;
T_1 V_33 = F_21 ( V_12 -> V_34 ) ;
T_1 V_35 [ 4 ] ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_33 ; V_25 ++ ) {
struct V_36 * V_37 = F_22 ( V_12 , V_25 ) ;
F_23 ( V_37 , V_1 -> V_38 , & V_35 [ V_25 ] ) ;
}
for (; V_25 < 4 ; V_25 ++ )
V_35 [ V_25 ] = 0 ;
F_24 ( V_1 , F_25 ( V_24 ) ,
F_26 ( V_12 -> V_39 [ 0 ] ) |
F_27 ( V_12 -> V_39 [ 1 ] ) ) ;
F_24 ( V_1 , F_28 ( V_24 ) ,
F_29 ( V_12 -> V_39 [ 2 ] ) |
F_30 ( V_12 -> V_39 [ 3 ] ) ) ;
F_24 ( V_1 , F_31 ( V_24 ) , V_35 [ 0 ] ) ;
F_24 ( V_1 , F_32 ( V_24 ) , V_35 [ 1 ] ) ;
F_24 ( V_1 , F_33 ( V_24 ) , V_35 [ 2 ] ) ;
F_24 ( V_1 , F_34 ( V_24 ) , V_35 [ 3 ] ) ;
V_3 -> V_12 = V_12 ;
}
static int F_35 ( struct V_2 * V_3 , T_1 V_40 ,
T_1 V_33 , T_1 V_41 )
{
struct V_42 * V_6 = V_3 -> V_6 ;
struct V_21 * V_21 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_23 V_24 = V_21 -> V_24 ;
int V_25 , V_43 , V_44 , V_45 , V_46 ;
V_43 = F_36 ( V_40 ) ;
V_44 = 2 ;
for ( V_25 = 0 , V_45 = 0 ; V_25 < V_33 ; V_25 ++ ) {
int V_47 , V_48 , V_49 ;
V_49 = F_37 ( V_40 , V_25 ) ;
V_48 = V_41 * V_49 / ( V_25 ? V_43 : 1 ) ;
V_47 = F_38 ( V_48 * V_44 , V_50 ) ;
if ( V_1 -> V_51 == 0 )
V_47 = F_39 ( V_47 ) ;
F_10 ( L_2 , V_21 -> V_26 , V_25 , V_47 ) ;
V_46 = F_12 ( V_1 , F_13 ( V_24 , V_25 ) , V_47 ) ;
if ( V_46 ) {
F_40 ( V_6 -> V_6 , L_3 ,
V_47 , V_46 ) ;
return V_46 ;
}
V_45 += V_47 ;
}
return V_45 ;
}
static void F_41 ( struct V_2 * V_3 , int V_45 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_23 V_24 = V_21 -> V_24 ;
T_1 V_31 ;
V_31 = ( V_45 * V_52 ) / 4 ;
F_24 ( V_1 , F_42 ( V_24 ) , V_31 * 1 ) ;
F_24 ( V_1 , F_43 ( V_24 ) , V_31 * 2 ) ;
F_24 ( V_1 , F_44 ( V_24 ) , V_31 * 3 ) ;
}
int F_8 ( struct V_2 * V_3 ,
struct V_9 * V_10 , struct V_11 * V_12 ,
int V_13 , int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
T_1 V_17 , T_1 V_18 ,
T_1 V_19 , T_1 V_20 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_23 V_24 = V_21 -> V_24 ;
const struct V_53 * V_40 ;
T_1 V_33 , V_54 = 0 ;
T_1 V_55 = 0 , V_56 = 0 ;
T_1 V_57 = 0 , V_58 = 0 ;
int V_25 , V_45 ;
V_33 = F_21 ( V_12 -> V_34 ) ;
if ( F_45 ( V_33 > F_11 ( V_24 ) ) )
return - V_32 ;
V_17 = V_17 >> 16 ;
V_18 = V_18 >> 16 ;
V_19 = V_19 >> 16 ;
V_20 = V_20 >> 16 ;
F_10 ( L_4 , V_21 -> V_26 ,
V_12 -> V_59 . V_38 , V_17 , V_18 , V_19 , V_20 ,
V_10 -> V_59 . V_38 , V_13 , V_14 , V_15 , V_16 ) ;
V_45 = F_35 ( V_3 , V_12 -> V_34 , V_33 , V_19 ) ;
if ( V_45 < 0 )
return V_45 ;
for ( V_25 = 0 ; V_25 < F_11 ( V_24 ) ; V_25 ++ )
F_46 ( V_1 , F_13 ( V_24 , V_25 ) ) ;
if ( V_19 != V_15 ) {
V_54 |= V_60 ;
}
if ( V_20 != V_16 ) {
V_54 |= V_61 ;
}
F_24 ( V_1 , F_47 ( V_24 ) ,
F_48 ( V_19 ) |
F_49 ( V_20 ) ) ;
F_24 ( V_1 , F_50 ( V_24 ) ,
F_51 ( V_19 ) |
F_52 ( V_20 ) ) ;
F_24 ( V_1 , F_53 ( V_24 ) ,
F_54 ( V_17 ) |
F_55 ( V_18 ) ) ;
F_24 ( V_1 , F_56 ( V_24 ) ,
F_57 ( V_15 ) |
F_58 ( V_16 ) ) ;
F_24 ( V_1 , F_59 ( V_24 ) ,
F_60 ( V_13 ) |
F_61 ( V_14 ) ) ;
F_20 ( V_3 , V_12 ) ;
V_40 = F_62 ( F_63 ( V_12 ) ) ;
F_24 ( V_1 , F_64 ( V_24 ) ,
F_65 ( V_40 -> V_62 ) |
F_66 ( V_40 -> V_63 ) |
F_67 ( V_40 -> V_64 ) |
F_68 ( V_40 -> V_65 ) |
F_69 ( V_40 -> V_66 , V_67 ) |
F_70 ( V_40 -> V_49 - 1 ) |
F_71 ( V_40 -> V_68 - 1 ) |
F_69 ( V_40 -> V_69 , V_70 ) |
F_72 ( V_33 - 1 ) |
F_73 ( V_71 ) ) ;
F_24 ( V_1 , F_74 ( V_24 ) ,
F_75 ( V_40 -> V_72 [ 0 ] ) |
F_76 ( V_40 -> V_72 [ 1 ] ) |
F_77 ( V_40 -> V_72 [ 2 ] ) |
F_78 ( V_40 -> V_72 [ 3 ] ) ) ;
F_24 ( V_1 , F_79 ( V_24 ) ,
F_80 ( V_73 ) ) ;
F_24 ( V_1 , F_81 ( V_24 ) , 0 ) ;
F_24 ( V_1 , F_82 ( V_24 ) , V_55 ) ;
F_24 ( V_1 , F_83 ( V_24 ) , V_56 ) ;
F_24 ( V_1 , F_84 ( V_24 ) ,
F_85 ( V_58 ) |
F_86 ( V_57 ) ) ;
F_24 ( V_1 , F_87 ( V_24 ) ,
F_88 ( V_74 ) |
F_89 ( V_74 ) |
F_90 ( V_74 ) |
F_91 ( V_74 ) |
F_92 ( V_74 ) |
F_93 ( V_74 ) ) ;
F_41 ( V_3 , V_45 ) ;
F_94 ( V_10 , V_3 ) ;
return 0 ;
}
void F_95 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
enum V_23 V_24 = F_5 ( V_3 ) -> V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < F_11 ( V_24 ) ; V_25 ++ )
F_96 ( V_1 , F_13 ( V_24 , V_25 ) ) ;
}
enum V_23 F_97 ( struct V_2 * V_3 )
{
struct V_21 * V_21 = F_5 ( V_3 ) ;
return V_21 -> V_24 ;
}
struct V_2 * F_98 ( struct V_42 * V_6 ,
enum V_23 V_24 , bool V_75 )
{
struct V_2 * V_3 = NULL ;
struct V_21 * V_21 ;
int V_46 ;
enum V_76 type ;
V_21 = F_99 ( sizeof( * V_21 ) , V_77 ) ;
if ( ! V_21 ) {
V_46 = - V_78 ;
goto V_79;
}
V_3 = & V_21 -> V_59 ;
V_21 -> V_24 = V_24 ;
V_21 -> V_26 = F_100 ( V_24 ) ;
V_21 -> V_80 = F_101 ( V_24 , V_21 -> V_81 ,
F_102 ( V_21 -> V_81 ) ) ;
type = V_75 ? V_82 : V_83 ;
F_103 ( V_6 , V_3 , 0xff , & V_84 ,
V_21 -> V_81 , V_21 -> V_80 ,
type ) ;
F_18 ( V_3 , & V_3 -> V_59 ) ;
return V_3 ;
V_79:
if ( V_3 )
F_15 ( V_3 ) ;
return F_104 ( V_46 ) ;
}
