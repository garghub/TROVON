static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = V_4 -> V_6 ;
T_2 V_7 ;
V_7 = F_2 ( V_5 + V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= F_3 ( 1 ) | F_4 ( 0 ) ;
F_5 ( V_7 , V_5 + V_8 ) ;
V_7 = F_2 ( V_5 + V_10 ) ;
V_7 &= ~ V_11 ;
F_5 ( V_7 , V_5 + V_10 ) ;
if ( ! V_6 ) {
V_7 = F_2 ( V_5 + V_12 ) ;
V_7 &= ~ V_13 ;
F_5 ( V_7 , V_5 + V_12 ) ;
V_7 = F_2 ( V_5 + V_14 ) ;
V_7 |= V_15 ;
F_5 ( V_7 , V_5 + V_14 ) ;
V_7 = F_2 ( V_5 + V_16 ) ;
V_7 &= ~ V_17 ;
F_5 ( V_7 , V_5 + V_16 ) ;
} else {
V_7 = F_2 ( V_5 + V_16 ) ;
V_7 |= V_17 ;
F_5 ( V_7 , V_5 + V_16 ) ;
V_7 = F_2 ( V_5 + V_8 ) ;
V_7 |= V_18 | V_19 ;
F_5 ( V_7 , V_5 + V_8 ) ;
}
V_7 = F_2 ( V_5 + V_20 ) ;
V_7 &= ~ V_21 ;
F_5 ( V_7 , V_5 + V_20 ) ;
V_7 = F_2 ( V_5 + V_22 ) ;
V_7 &= ~ V_23 ;
V_7 |= F_6 ( 2 ) ;
F_5 ( V_7 , V_5 + V_22 ) ;
V_7 = F_2 ( V_5 + V_24 ) ;
V_7 &= ~ V_25 ;
V_7 |= F_7 ( 4 ) ;
F_5 ( V_7 , V_5 + V_24 ) ;
V_7 = F_2 ( V_5 + V_26 ) ;
V_7 &= ~ V_27 ;
V_7 |= F_8 ( 0xe ) ;
F_5 ( V_7 , V_5 + V_26 ) ;
V_7 = F_2 ( V_5 + V_28 ) ;
V_7 &= ~ ( V_29 | V_30 ) ;
V_7 |= F_9 ( 0xc ) | F_10 ( 0x3 ) ;
F_5 ( V_7 , V_5 + V_28 ) ;
F_11 ( V_2 -> V_31 , L_1 , V_32 , V_6 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = V_4 -> V_6 ;
T_2 V_7 ;
if ( ! V_6 ) {
V_7 = F_2 ( V_5 + V_33 ) ;
V_7 |= V_34 ;
F_5 ( V_7 , V_5 + V_33 ) ;
}
V_7 = F_2 ( V_5 + V_8 ) ;
V_7 &= ~ ( V_19 | V_35 ) ;
V_7 &= ~ ( V_36 | V_37 ) ;
F_5 ( V_7 , V_5 + V_8 ) ;
V_7 = F_2 ( V_5 + V_20 ) ;
V_7 |= V_38 ;
F_5 ( V_7 , V_5 + V_20 ) ;
if ( ! V_6 ) {
V_7 = F_2 ( V_2 -> V_39 + V_40 ) ;
V_7 |= V_41 | V_42 ;
F_5 ( V_7 , V_2 -> V_39 + V_40 ) ;
V_7 = F_2 ( V_5 + V_43 ) ;
V_7 &= ~ V_44 ;
F_5 ( V_7 , V_5 + V_43 ) ;
}
V_7 = F_2 ( V_5 + V_10 ) ;
V_7 |= V_45 | V_46 ;
V_7 &= ~ V_47 ;
F_5 ( V_7 , V_5 + V_10 ) ;
V_7 = F_2 ( V_5 + V_43 ) ;
V_7 &= ~ V_48 ;
V_7 |= F_13 ( 4 ) ;
F_5 ( V_7 , V_5 + V_43 ) ;
if ( V_6 ) {
V_7 = F_2 ( V_5 + V_16 ) ;
V_7 |= V_17 ;
F_5 ( V_7 , V_5 + V_16 ) ;
V_7 = F_2 ( V_5 + V_8 ) ;
V_7 |= V_18 | V_19 ;
F_5 ( V_7 , V_5 + V_8 ) ;
}
F_11 ( V_2 -> V_31 , L_1 , V_32 , V_6 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = V_4 -> V_6 ;
T_2 V_7 ;
V_7 = F_2 ( V_5 + V_8 ) ;
V_7 &= ~ ( V_35 | V_36 ) ;
V_7 |= V_19 ;
F_5 ( V_7 , V_5 + V_8 ) ;
V_7 = F_2 ( V_5 + V_20 ) ;
V_7 &= ~ V_38 ;
F_5 ( V_7 , V_5 + V_20 ) ;
if ( ! V_6 ) {
V_7 = F_2 ( V_5 + V_43 ) ;
V_7 &= ~ V_44 ;
F_5 ( V_7 , V_5 + V_43 ) ;
}
V_7 = F_2 ( V_5 + V_8 ) ;
V_7 &= ~ V_18 ;
F_5 ( V_7 , V_5 + V_8 ) ;
F_15 ( 1 ) ;
V_7 = F_2 ( V_5 + V_10 ) ;
V_7 &= ~ ( V_45 | V_46 ) ;
V_7 |= V_47 ;
F_5 ( V_7 , V_5 + V_10 ) ;
if ( ! V_6 ) {
V_7 = F_2 ( V_5 + V_33 ) ;
V_7 &= ~ V_34 ;
F_5 ( V_7 , V_5 + V_33 ) ;
} else {
V_7 = F_2 ( V_5 + V_16 ) ;
V_7 &= ~ V_17 ;
F_5 ( V_7 , V_5 + V_16 ) ;
}
F_11 ( V_2 -> V_31 , L_1 , V_32 , V_6 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_4 -> V_5 ;
T_2 V_6 = V_4 -> V_6 ;
T_2 V_7 ;
if ( V_6 ) {
V_7 = F_2 ( V_5 + V_16 ) ;
V_7 &= ~ V_17 ;
F_5 ( V_7 , V_5 + V_16 ) ;
V_7 = F_2 ( V_5 + V_8 ) ;
V_7 &= ~ V_19 ;
F_5 ( V_7 , V_5 + V_8 ) ;
}
}
static int F_17 ( struct V_49 * V_49 )
{
struct V_3 * V_4 = F_18 ( V_49 ) ;
struct V_1 * V_2 = F_19 ( V_49 -> V_31 . V_50 ) ;
int V_51 ;
V_51 = F_20 ( V_2 -> V_52 ) ;
if ( V_51 ) {
F_21 ( V_2 -> V_31 , L_2 ) ;
return V_51 ;
}
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_22 ( struct V_49 * V_49 )
{
struct V_3 * V_4 = F_18 ( V_49 ) ;
struct V_1 * V_2 = F_19 ( V_49 -> V_31 . V_50 ) ;
F_12 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_49 * V_49 )
{
struct V_3 * V_4 = F_18 ( V_49 ) ;
struct V_1 * V_2 = F_19 ( V_49 -> V_31 . V_50 ) ;
F_14 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_49 * V_49 )
{
struct V_3 * V_4 = F_18 ( V_49 ) ;
struct V_1 * V_2 = F_19 ( V_49 -> V_31 . V_50 ) ;
F_16 ( V_2 , V_4 ) ;
F_25 ( V_2 -> V_52 ) ;
return 0 ;
}
static struct V_49 * F_26 ( struct V_53 * V_31 ,
struct V_54 * args )
{
struct V_1 * V_2 = F_19 ( V_31 ) ;
struct V_3 * V_4 = NULL ;
struct V_55 * V_56 = args -> V_57 ;
int V_6 ;
if ( args -> V_58 != 1 ) {
F_21 ( V_31 , L_3 ) ;
return F_27 ( - V_59 ) ;
}
for ( V_6 = 0 ; V_6 < V_2 -> V_60 ; V_6 ++ )
if ( V_56 == V_2 -> V_61 [ V_6 ] -> V_49 -> V_31 . V_62 ) {
V_4 = V_2 -> V_61 [ V_6 ] ;
break;
}
if ( ! V_4 ) {
F_21 ( V_31 , L_4 ) ;
return F_27 ( - V_59 ) ;
}
V_4 -> type = args -> args [ 0 ] ;
if ( ! ( V_4 -> type == V_63 ||
V_4 -> type == V_64 ) ) {
F_21 ( V_31 , L_5 , V_4 -> type ) ;
return F_27 ( - V_59 ) ;
}
return V_4 -> V_49 ;
}
static int F_28 ( struct V_65 * V_66 )
{
struct V_53 * V_31 = & V_66 -> V_31 ;
struct V_55 * V_57 = V_31 -> V_62 ;
struct V_55 * V_67 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
struct V_1 * V_2 ;
struct V_70 V_72 ;
int V_73 , V_74 ;
V_2 = F_29 ( V_31 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_2 -> V_60 = F_30 ( V_57 ) ;
V_2 -> V_61 = F_31 ( V_31 , V_2 -> V_60 ,
sizeof( * V_2 -> V_61 ) , V_75 ) ;
if ( ! V_2 -> V_61 )
return - V_76 ;
V_2 -> V_31 = V_31 ;
F_32 ( V_66 , V_2 ) ;
V_71 = F_33 ( V_66 , V_77 , 0 ) ;
V_2 -> V_39 = F_34 ( V_31 , V_71 ) ;
if ( F_35 ( V_2 -> V_39 ) ) {
F_21 ( V_31 , L_6 ) ;
return F_36 ( V_2 -> V_39 ) ;
}
V_2 -> V_52 = F_37 ( V_31 , L_7 ) ;
if ( F_35 ( V_2 -> V_52 ) ) {
F_21 ( V_31 , L_8 ) ;
return F_36 ( V_2 -> V_52 ) ;
}
V_73 = 0 ;
F_38 (np, child_np) {
struct V_3 * V_4 ;
struct V_49 * V_49 ;
V_4 = F_29 ( V_31 , sizeof( * V_4 ) , V_75 ) ;
if ( ! V_4 ) {
V_74 = - V_76 ;
goto V_78;
}
V_2 -> V_61 [ V_73 ] = V_4 ;
V_49 = F_39 ( V_31 , V_67 , & V_79 ) ;
if ( F_35 ( V_49 ) ) {
F_21 ( V_31 , L_9 ) ;
V_74 = F_36 ( V_49 ) ;
goto V_78;
}
V_74 = F_40 ( V_67 , 0 , & V_72 ) ;
if ( V_74 ) {
F_21 ( V_31 , L_10 ,
V_73 ) ;
goto V_78;
}
V_4 -> V_5 = F_34 ( & V_49 -> V_31 , & V_72 ) ;
if ( F_35 ( V_4 -> V_5 ) ) {
F_21 ( V_31 , L_11 ) ;
V_74 = F_36 ( V_4 -> V_5 ) ;
goto V_78;
}
V_4 -> V_49 = V_49 ;
V_4 -> V_6 = V_73 ;
F_41 ( V_49 , V_4 ) ;
V_73 ++ ;
}
V_69 = F_42 ( V_31 , F_26 ) ;
return F_43 ( V_69 ) ;
V_78:
F_44 ( V_67 ) ;
return V_74 ;
}
