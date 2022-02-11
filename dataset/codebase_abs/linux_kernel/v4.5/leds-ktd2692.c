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
static int F_11 ( struct V_17 * V_18 ,
enum V_19 V_20 )
{
struct V_2 * V_3 = F_12 ( V_18 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_13 ( & V_4 -> V_21 ) ;
if ( V_20 == V_22 ) {
V_4 -> V_23 = V_24 ;
F_4 ( V_4 -> V_25 , V_8 ) ;
} else {
F_9 ( V_4 , V_20 |
V_26 ) ;
V_4 -> V_23 = V_27 ;
}
F_9 ( V_4 , V_4 -> V_23 | V_28 ) ;
F_14 ( & V_4 -> V_21 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
bool V_29 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_30 * V_31 = & V_3 -> V_31 ;
T_2 V_32 ;
F_13 ( & V_4 -> V_21 ) ;
if ( V_29 ) {
V_32 = F_16 ( V_31 -> V_33 , V_31 -> V_34 ) ;
F_9 ( V_4 , V_32
| V_35 ) ;
V_4 -> V_23 = V_36 ;
F_4 ( V_4 -> V_25 , V_6 ) ;
} else {
V_4 -> V_23 = V_24 ;
F_4 ( V_4 -> V_25 , V_8 ) ;
}
F_9 ( V_4 , V_4 -> V_23 | V_28 ) ;
V_3 -> V_18 . V_20 = V_22 ;
V_4 -> V_23 = V_24 ;
F_14 ( & V_4 -> V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 ,
T_2 V_31 )
{
return 0 ;
}
static void F_18 ( struct V_37 * V_38 )
{
T_2 V_39 , V_34 ;
T_2 V_40 ;
V_39 = V_41 ;
V_34 = F_19 ( V_38 -> V_42 )
/ V_41 ;
do {
V_40 = V_34 * V_39 ;
V_39 -- ;
} while ( ( V_40 > V_38 -> V_43 ) &&
( V_39 > 0 ) );
V_38 -> V_44 = V_39 ;
}
static void F_20 ( struct V_2 * V_3 ,
struct V_37 * V_38 )
{
struct V_30 * V_45 ;
V_45 = & V_3 -> V_31 ;
V_45 -> V_46 = V_47 ;
V_45 -> V_48 = V_38 -> V_49 ;
V_45 -> V_34 = V_38 -> V_49
/ ( V_50 - 1 ) ;
V_45 -> V_33 = V_38 -> V_49 ;
}
static void F_21 ( struct V_1 * V_4 )
{
V_4 -> V_23 = V_24 ;
F_6 ( V_4 ) ;
F_4 ( V_4 -> V_25 , V_8 ) ;
F_9 ( V_4 , ( V_51 - 1 )
| V_52 ) ;
F_9 ( V_4 , F_22 ( 45 )
| V_53 ) ;
}
static int F_23 ( struct V_1 * V_4 , struct V_54 * V_55 ,
struct V_37 * V_38 )
{
struct V_56 * V_57 = V_55 -> V_58 ;
struct V_56 * V_59 ;
int V_60 ;
if ( ! V_55 -> V_58 )
return - V_61 ;
V_4 -> V_5 = F_24 ( V_55 , L_1 , V_62 ) ;
if ( F_25 ( V_4 -> V_5 ) ) {
V_60 = F_26 ( V_4 -> V_5 ) ;
F_27 ( V_55 , L_2 , V_60 ) ;
return V_60 ;
}
V_4 -> V_25 = F_24 ( V_55 , L_3 , V_62 ) ;
if ( F_25 ( V_4 -> V_25 ) ) {
V_60 = F_26 ( V_4 -> V_25 ) ;
F_27 ( V_55 , L_4 , V_60 ) ;
return V_60 ;
}
V_4 -> V_63 = F_28 ( V_55 , L_5 ) ;
if ( F_25 ( V_4 -> V_63 ) )
V_4 -> V_63 = NULL ;
if ( V_4 -> V_63 ) {
V_60 = F_29 ( V_4 -> V_63 ) ;
if ( V_60 )
F_27 ( V_55 , L_6 , V_60 ) ;
}
V_59 = F_30 ( V_57 , NULL ) ;
if ( ! V_59 ) {
F_27 ( V_55 , L_7 ) ;
return - V_64 ;
}
V_4 -> V_3 . V_18 . V_65 =
F_31 ( V_59 , L_8 , NULL ) ? : V_59 -> V_65 ;
V_60 = F_32 ( V_59 , L_9 ,
& V_38 -> V_43 ) ;
if ( V_60 ) {
F_27 ( V_55 , L_10 ) ;
goto V_66;
}
V_60 = F_32 ( V_59 , L_11 ,
& V_38 -> V_42 ) ;
if ( V_60 ) {
F_27 ( V_55 , L_12 ) ;
goto V_66;
}
V_60 = F_32 ( V_59 , L_13 ,
& V_38 -> V_49 ) ;
if ( V_60 ) {
F_27 ( V_55 , L_14 ) ;
goto V_66;
}
V_66:
F_33 ( V_59 ) ;
return V_60 ;
}
static int F_34 ( struct V_67 * V_68 )
{
struct V_1 * V_4 ;
struct V_17 * V_18 ;
struct V_2 * V_3 ;
struct V_37 V_69 ;
int V_60 ;
V_4 = F_35 ( & V_68 -> V_55 , sizeof( * V_4 ) , V_70 ) ;
if ( ! V_4 )
return - V_71 ;
V_3 = & V_4 -> V_3 ;
V_18 = & V_3 -> V_18 ;
V_60 = F_23 ( V_4 , & V_68 -> V_55 , & V_69 ) ;
if ( V_60 )
return V_60 ;
F_20 ( V_3 , & V_69 ) ;
F_18 ( & V_69 ) ;
V_3 -> V_72 = & V_73 ;
V_18 -> V_44 = V_69 . V_44 ;
V_18 -> V_74 = F_11 ;
V_18 -> V_75 |= V_76 | V_77 ;
F_36 ( & V_4 -> V_21 ) ;
F_37 ( V_68 , V_4 ) ;
V_60 = F_38 ( & V_68 -> V_55 , V_3 ) ;
if ( V_60 ) {
F_27 ( & V_68 -> V_55 , L_15 , V_18 -> V_65 ) ;
F_39 ( & V_4 -> V_21 ) ;
return V_60 ;
}
F_21 ( V_4 ) ;
return 0 ;
}
static int F_40 ( struct V_67 * V_68 )
{
struct V_1 * V_4 = F_41 ( V_68 ) ;
int V_60 ;
F_42 ( & V_4 -> V_3 ) ;
if ( V_4 -> V_63 ) {
V_60 = F_43 ( V_4 -> V_63 ) ;
if ( V_60 )
F_27 ( & V_68 -> V_55 ,
L_16 , V_60 ) ;
}
F_39 ( & V_4 -> V_21 ) ;
return 0 ;
}
