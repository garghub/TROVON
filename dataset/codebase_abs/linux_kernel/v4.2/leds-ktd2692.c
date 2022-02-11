static struct V_1 * F_1 (
struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
F_4 ( V_4 -> V_5 , V_6 ) ;
F_5 ( V_7 ) ;
}
static void F_6 ( struct V_1 * V_4 )
{
F_4 ( V_4 -> V_5 , V_8 ) ;
F_5 ( V_9 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
F_4 ( V_4 -> V_5 , V_8 ) ;
F_5 ( V_10 ) ;
F_4 ( V_4 -> V_5 , V_6 ) ;
F_5 ( V_11 ) ;
}
static void F_8 ( struct V_1 * V_4 , bool V_12 )
{
if ( V_12 ) {
F_4 ( V_4 -> V_5 , V_8 ) ;
F_5 ( V_13 ) ;
F_4 ( V_4 -> V_5 , V_6 ) ;
F_5 ( V_14 ) ;
} else {
F_4 ( V_4 -> V_5 , V_8 ) ;
F_5 ( V_14 ) ;
F_4 ( V_4 -> V_5 , V_6 ) ;
F_5 ( V_13 ) ;
}
}
static void F_9 ( struct V_1 * V_4 , T_1 V_15 )
{
int V_16 ;
F_3 ( V_4 ) ;
for ( V_16 = 7 ; V_16 >= 0 ; V_16 -- )
F_8 ( V_4 , V_15 & F_10 ( V_16 ) ) ;
F_7 ( V_4 ) ;
}
static void F_11 ( struct V_1 * V_4 ,
enum V_17 V_18 )
{
F_12 ( & V_4 -> V_19 ) ;
if ( V_18 == V_20 ) {
V_4 -> V_21 = V_22 ;
F_4 ( V_4 -> V_23 , V_8 ) ;
} else {
F_9 ( V_4 , V_18 |
V_24 ) ;
V_4 -> V_21 = V_25 ;
}
F_9 ( V_4 , V_4 -> V_21 | V_26 ) ;
F_13 ( & V_4 -> V_19 ) ;
}
static void F_14 ( struct V_27 * V_28 )
{
struct V_1 * V_4 =
F_2 ( V_28 , struct V_1 , V_29 ) ;
F_11 ( V_4 , V_4 -> V_30 ) ;
}
static void F_15 ( struct V_31 * V_32 ,
enum V_17 V_18 )
{
struct V_2 * V_3 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
V_4 -> V_30 = V_18 ;
F_17 ( & V_4 -> V_29 ) ;
}
static int F_18 ( struct V_31 * V_32 ,
enum V_17 V_18 )
{
struct V_2 * V_3 = F_16 ( V_32 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_11 ( V_4 , V_18 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 ,
bool V_33 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_34 * V_35 = & V_3 -> V_35 ;
T_2 V_36 ;
F_12 ( & V_4 -> V_19 ) ;
if ( V_33 ) {
V_36 = F_20 ( V_35 -> V_37 , V_35 -> V_38 ) ;
F_9 ( V_4 , V_36
| V_39 ) ;
V_4 -> V_21 = V_40 ;
F_4 ( V_4 -> V_23 , V_6 ) ;
} else {
V_4 -> V_21 = V_22 ;
F_4 ( V_4 -> V_23 , V_8 ) ;
}
F_9 ( V_4 , V_4 -> V_21 | V_26 ) ;
V_3 -> V_32 . V_18 = V_20 ;
V_4 -> V_21 = V_22 ;
F_13 ( & V_4 -> V_19 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
T_2 V_35 )
{
return 0 ;
}
static void F_22 ( struct V_41 * V_42 )
{
T_2 V_43 , V_38 ;
T_2 V_44 ;
V_43 = V_45 ;
V_38 = F_23 ( V_42 -> V_46 )
/ V_45 ;
do {
V_44 = V_38 * V_43 ;
V_43 -- ;
} while ( ( V_44 > V_42 -> V_47 ) &&
( V_43 > 0 ) );
V_42 -> V_48 = V_43 ;
}
static void F_24 ( struct V_2 * V_3 ,
struct V_41 * V_42 )
{
struct V_34 * V_49 ;
V_49 = & V_3 -> V_35 ;
V_49 -> V_50 = V_51 ;
V_49 -> V_52 = V_42 -> V_53 ;
V_49 -> V_38 = V_42 -> V_53
/ ( V_54 - 1 ) ;
V_49 -> V_37 = V_42 -> V_53 ;
}
static void F_25 ( struct V_1 * V_4 )
{
V_4 -> V_21 = V_22 ;
F_6 ( V_4 ) ;
F_4 ( V_4 -> V_23 , V_8 ) ;
F_9 ( V_4 , ( V_55 - 1 )
| V_56 ) ;
F_9 ( V_4 , F_26 ( 45 )
| V_57 ) ;
}
static int F_27 ( struct V_1 * V_4 , struct V_58 * V_59 ,
struct V_41 * V_42 )
{
struct V_60 * V_61 = V_59 -> V_62 ;
struct V_60 * V_63 ;
int V_64 ;
if ( ! V_59 -> V_62 )
return - V_65 ;
V_4 -> V_5 = F_28 ( V_59 , L_1 , V_66 ) ;
if ( F_29 ( V_4 -> V_5 ) ) {
V_64 = F_30 ( V_4 -> V_5 ) ;
F_31 ( V_59 , L_2 , V_64 ) ;
return V_64 ;
}
V_4 -> V_23 = F_28 ( V_59 , L_3 , V_66 ) ;
if ( F_29 ( V_4 -> V_23 ) ) {
V_64 = F_30 ( V_4 -> V_23 ) ;
F_31 ( V_59 , L_4 , V_64 ) ;
return V_64 ;
}
V_4 -> V_67 = F_32 ( V_59 , L_5 ) ;
if ( F_29 ( V_4 -> V_67 ) )
V_4 -> V_67 = NULL ;
if ( V_4 -> V_67 ) {
V_64 = F_33 ( V_4 -> V_67 ) ;
if ( V_64 )
F_31 ( V_59 , L_6 , V_64 ) ;
}
V_63 = F_34 ( V_61 , NULL ) ;
if ( ! V_63 ) {
F_31 ( V_59 , L_7 ) ;
return - V_68 ;
}
V_4 -> V_3 . V_32 . V_69 =
F_35 ( V_63 , L_8 , NULL ) ? : V_63 -> V_69 ;
V_64 = F_36 ( V_63 , L_9 ,
& V_42 -> V_47 ) ;
if ( V_64 ) {
F_31 ( V_59 , L_10 ) ;
return V_64 ;
}
V_64 = F_36 ( V_63 , L_11 ,
& V_42 -> V_46 ) ;
if ( V_64 ) {
F_31 ( V_59 , L_12 ) ;
return V_64 ;
}
V_64 = F_36 ( V_63 , L_13 ,
& V_42 -> V_53 ) ;
if ( V_64 )
F_31 ( V_59 , L_14 ) ;
F_37 ( V_63 ) ;
return V_64 ;
}
static int F_38 ( struct V_70 * V_71 )
{
struct V_1 * V_4 ;
struct V_31 * V_32 ;
struct V_2 * V_3 ;
struct V_41 V_72 ;
int V_64 ;
V_4 = F_39 ( & V_71 -> V_59 , sizeof( * V_4 ) , V_73 ) ;
if ( ! V_4 )
return - V_74 ;
V_3 = & V_4 -> V_3 ;
V_32 = & V_3 -> V_32 ;
V_64 = F_27 ( V_4 , & V_71 -> V_59 , & V_72 ) ;
if ( V_64 )
return V_64 ;
F_24 ( V_3 , & V_72 ) ;
F_22 ( & V_72 ) ;
V_3 -> V_75 = & V_76 ;
V_32 -> V_48 = V_72 . V_48 ;
V_32 -> V_77 = F_15 ;
V_32 -> V_78 = F_18 ;
V_32 -> V_79 |= V_80 | V_81 ;
F_40 ( & V_4 -> V_19 ) ;
F_41 ( & V_4 -> V_29 , F_14 ) ;
F_42 ( V_71 , V_4 ) ;
V_64 = F_43 ( & V_71 -> V_59 , V_3 ) ;
if ( V_64 ) {
F_31 ( & V_71 -> V_59 , L_15 , V_32 -> V_69 ) ;
F_44 ( & V_4 -> V_19 ) ;
return V_64 ;
}
F_25 ( V_4 ) ;
return 0 ;
}
static int F_45 ( struct V_70 * V_71 )
{
struct V_1 * V_4 = F_46 ( V_71 ) ;
int V_64 ;
F_47 ( & V_4 -> V_3 ) ;
F_48 ( & V_4 -> V_29 ) ;
if ( V_4 -> V_67 ) {
V_64 = F_49 ( V_4 -> V_67 ) ;
if ( V_64 )
F_31 ( & V_71 -> V_59 ,
L_16 , V_64 ) ;
}
F_44 ( & V_4 -> V_19 ) ;
return 0 ;
}
