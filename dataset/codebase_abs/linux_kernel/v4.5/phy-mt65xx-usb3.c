static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_5 = V_2 -> V_5 ;
int V_6 ;
int V_7 ;
T_2 V_8 ;
V_8 = F_2 ( V_4 -> V_9 + V_10 ) ;
V_8 |= V_11 ;
F_3 ( V_8 , V_4 -> V_9 + V_10 ) ;
F_4 ( 1 ) ;
V_8 = F_2 ( V_5 + V_12 ) ;
V_8 |= V_13 ;
F_3 ( V_8 , V_5 + V_12 ) ;
V_8 = F_2 ( V_5 + V_14 ) ;
V_8 &= ~ ( V_15 | V_16 ) ;
V_8 |= F_5 ( V_17 ) ;
V_8 |= F_6 ( V_4 -> V_18 ) ;
F_3 ( V_8 , V_5 + V_14 ) ;
V_8 = F_2 ( V_5 + V_14 ) ;
V_8 |= V_19 ;
F_3 ( V_8 , V_5 + V_14 ) ;
F_7 ( V_5 + V_12 , V_8 ,
( V_8 & V_20 ) , 10 , 200 ) ;
V_7 = F_2 ( V_5 + V_21 ) ;
V_8 = F_2 ( V_5 + V_14 ) ;
V_8 &= ~ V_19 ;
F_3 ( V_8 , V_5 + V_14 ) ;
V_8 = F_2 ( V_5 + V_12 ) ;
V_8 &= ~ V_13 ;
F_3 ( V_8 , V_5 + V_12 ) ;
if ( V_7 ) {
V_8 = V_17 * V_22 * V_23 ;
V_8 /= V_7 ;
V_6 = F_8 ( V_8 , V_24 ) ;
} else {
V_6 = 4 ;
}
F_9 ( V_2 -> V_25 , L_1 ,
V_4 -> V_18 , V_7 , V_6 ) ;
V_8 = F_2 ( V_4 -> V_9 + V_10 ) ;
V_8 &= ~ V_26 ;
V_8 |= F_10 ( V_6 ) ;
F_3 ( V_8 , V_4 -> V_9 + V_10 ) ;
V_8 = F_2 ( V_4 -> V_9 + V_10 ) ;
V_8 &= ~ V_11 ;
F_3 ( V_8 , V_4 -> V_9 + V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_9 = V_4 -> V_9 ;
T_2 V_18 = V_4 -> V_18 ;
T_2 V_8 ;
V_8 = F_2 ( V_9 + V_27 ) ;
V_8 &= ~ V_28 ;
V_8 |= F_12 ( 1 ) | F_13 ( 0 ) ;
F_3 ( V_8 , V_9 + V_27 ) ;
V_8 = F_2 ( V_9 + V_29 ) ;
V_8 &= ~ V_30 ;
F_3 ( V_8 , V_9 + V_29 ) ;
if ( ! V_18 ) {
V_8 = F_2 ( V_9 + V_31 ) ;
V_8 &= ~ V_32 ;
F_3 ( V_8 , V_9 + V_31 ) ;
V_8 = F_2 ( V_9 + V_33 ) ;
V_8 |= V_34 ;
F_3 ( V_8 , V_9 + V_33 ) ;
V_8 = F_2 ( V_9 + V_35 ) ;
V_8 &= ~ V_36 ;
F_3 ( V_8 , V_9 + V_35 ) ;
} else {
V_8 = F_2 ( V_9 + V_35 ) ;
V_8 |= V_36 ;
F_3 ( V_8 , V_9 + V_35 ) ;
V_8 = F_2 ( V_9 + V_27 ) ;
V_8 |= V_37 | V_38 ;
F_3 ( V_8 , V_9 + V_27 ) ;
}
V_8 = F_2 ( V_9 + V_39 ) ;
V_8 &= ~ V_40 ;
V_8 &= ~ V_41 ;
V_8 |= F_14 ( 2 ) ;
F_3 ( V_8 , V_9 + V_39 ) ;
V_8 = F_2 ( V_9 + V_42 ) ;
V_8 &= ~ V_43 ;
V_8 |= F_15 ( 2 ) ;
F_3 ( V_8 , V_9 + V_42 ) ;
V_8 = F_2 ( V_9 + V_44 ) ;
V_8 &= ~ V_45 ;
V_8 |= F_16 ( 4 ) ;
F_3 ( V_8 , V_9 + V_44 ) ;
V_8 = F_2 ( V_9 + V_46 ) ;
V_8 &= ~ V_47 ;
V_8 |= F_17 ( 0xe ) ;
F_3 ( V_8 , V_9 + V_46 ) ;
V_8 = F_2 ( V_9 + V_48 ) ;
V_8 &= ~ ( V_49 | V_50 ) ;
V_8 |= F_18 ( 0xc ) | F_19 ( 0x3 ) ;
F_3 ( V_8 , V_9 + V_48 ) ;
F_9 ( V_2 -> V_25 , L_2 , V_51 , V_18 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_9 = V_4 -> V_9 ;
T_2 V_18 = V_4 -> V_18 ;
T_2 V_8 ;
if ( ! V_18 ) {
V_8 = F_2 ( V_9 + V_52 ) ;
V_8 |= V_53 ;
F_3 ( V_8 , V_9 + V_52 ) ;
}
V_8 = F_2 ( V_9 + V_27 ) ;
V_8 &= ~ ( V_38 | V_54 ) ;
V_8 &= ~ ( V_55 | V_56 ) ;
F_3 ( V_8 , V_9 + V_27 ) ;
V_8 = F_2 ( V_9 + V_39 ) ;
V_8 |= V_57 ;
F_3 ( V_8 , V_9 + V_39 ) ;
if ( ! V_18 ) {
V_8 = F_2 ( V_2 -> V_5 + V_58 ) ;
V_8 |= V_59 | V_60 ;
F_3 ( V_8 , V_2 -> V_5 + V_58 ) ;
V_8 = F_2 ( V_9 + V_10 ) ;
V_8 |= V_61 ;
F_3 ( V_8 , V_9 + V_10 ) ;
}
V_8 = F_2 ( V_9 + V_29 ) ;
V_8 |= V_62 | V_63 ;
V_8 &= ~ V_64 ;
F_3 ( V_8 , V_9 + V_29 ) ;
V_8 = F_2 ( V_9 + V_10 ) ;
V_8 &= ~ V_26 ;
V_8 |= F_10 ( 4 ) ;
F_3 ( V_8 , V_9 + V_10 ) ;
if ( V_18 ) {
V_8 = F_2 ( V_9 + V_35 ) ;
V_8 |= V_36 ;
F_3 ( V_8 , V_9 + V_35 ) ;
V_8 = F_2 ( V_9 + V_27 ) ;
V_8 |= V_37 | V_38 ;
F_3 ( V_8 , V_9 + V_27 ) ;
}
F_9 ( V_2 -> V_25 , L_2 , V_51 , V_18 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_9 = V_4 -> V_9 ;
T_2 V_18 = V_4 -> V_18 ;
T_2 V_8 ;
V_8 = F_2 ( V_9 + V_27 ) ;
V_8 &= ~ ( V_54 | V_55 ) ;
V_8 |= V_38 ;
F_3 ( V_8 , V_9 + V_27 ) ;
V_8 = F_2 ( V_9 + V_39 ) ;
V_8 &= ~ V_57 ;
F_3 ( V_8 , V_9 + V_39 ) ;
if ( ! V_18 ) {
V_8 = F_2 ( V_9 + V_10 ) ;
V_8 &= ~ V_61 ;
F_3 ( V_8 , V_9 + V_10 ) ;
}
V_8 = F_2 ( V_9 + V_27 ) ;
V_8 &= ~ V_37 ;
F_3 ( V_8 , V_9 + V_27 ) ;
F_4 ( 1 ) ;
V_8 = F_2 ( V_9 + V_29 ) ;
V_8 &= ~ ( V_62 | V_63 ) ;
V_8 |= V_64 ;
F_3 ( V_8 , V_9 + V_29 ) ;
if ( ! V_18 ) {
V_8 = F_2 ( V_9 + V_52 ) ;
V_8 &= ~ V_53 ;
F_3 ( V_8 , V_9 + V_52 ) ;
} else {
V_8 = F_2 ( V_9 + V_35 ) ;
V_8 &= ~ V_36 ;
F_3 ( V_8 , V_9 + V_35 ) ;
}
F_9 ( V_2 -> V_25 , L_2 , V_51 , V_18 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
void T_1 * V_9 = V_4 -> V_9 ;
T_2 V_18 = V_4 -> V_18 ;
T_2 V_8 ;
if ( V_18 ) {
V_8 = F_2 ( V_9 + V_35 ) ;
V_8 &= ~ V_36 ;
F_3 ( V_8 , V_9 + V_35 ) ;
V_8 = F_2 ( V_9 + V_27 ) ;
V_8 &= ~ V_38 ;
F_3 ( V_8 , V_9 + V_27 ) ;
}
}
static int F_23 ( struct V_65 * V_65 )
{
struct V_3 * V_4 = F_24 ( V_65 ) ;
struct V_1 * V_2 = F_25 ( V_65 -> V_25 . V_66 ) ;
int V_67 ;
V_67 = F_26 ( V_2 -> V_68 ) ;
if ( V_67 ) {
F_27 ( V_2 -> V_25 , L_3 ) ;
return V_67 ;
}
F_11 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_28 ( struct V_65 * V_65 )
{
struct V_3 * V_4 = F_24 ( V_65 ) ;
struct V_1 * V_2 = F_25 ( V_65 -> V_25 . V_66 ) ;
F_20 ( V_2 , V_4 ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_29 ( struct V_65 * V_65 )
{
struct V_3 * V_4 = F_24 ( V_65 ) ;
struct V_1 * V_2 = F_25 ( V_65 -> V_25 . V_66 ) ;
F_21 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_30 ( struct V_65 * V_65 )
{
struct V_3 * V_4 = F_24 ( V_65 ) ;
struct V_1 * V_2 = F_25 ( V_65 -> V_25 . V_66 ) ;
F_22 ( V_2 , V_4 ) ;
F_31 ( V_2 -> V_68 ) ;
return 0 ;
}
static struct V_65 * F_32 ( struct V_69 * V_25 ,
struct V_70 * args )
{
struct V_1 * V_2 = F_25 ( V_25 ) ;
struct V_3 * V_4 = NULL ;
struct V_71 * V_72 = args -> V_73 ;
int V_18 ;
if ( args -> V_74 != 1 ) {
F_27 ( V_25 , L_4 ) ;
return F_33 ( - V_75 ) ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_76 ; V_18 ++ )
if ( V_72 == V_2 -> V_77 [ V_18 ] -> V_65 -> V_25 . V_78 ) {
V_4 = V_2 -> V_77 [ V_18 ] ;
break;
}
if ( ! V_4 ) {
F_27 ( V_25 , L_5 ) ;
return F_33 ( - V_75 ) ;
}
V_4 -> type = args -> args [ 0 ] ;
if ( ! ( V_4 -> type == V_79 ||
V_4 -> type == V_80 ) ) {
F_27 ( V_25 , L_6 , V_4 -> type ) ;
return F_33 ( - V_75 ) ;
}
return V_4 -> V_65 ;
}
static int F_34 ( struct V_81 * V_82 )
{
struct V_69 * V_25 = & V_82 -> V_25 ;
struct V_71 * V_73 = V_25 -> V_78 ;
struct V_71 * V_83 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
struct V_1 * V_2 ;
struct V_86 V_88 ;
int V_89 , V_90 ;
V_2 = F_35 ( V_25 , sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 )
return - V_92 ;
V_2 -> V_76 = F_36 ( V_73 ) ;
V_2 -> V_77 = F_37 ( V_25 , V_2 -> V_76 ,
sizeof( * V_2 -> V_77 ) , V_91 ) ;
if ( ! V_2 -> V_77 )
return - V_92 ;
V_2 -> V_25 = V_25 ;
F_38 ( V_82 , V_2 ) ;
V_87 = F_39 ( V_82 , V_93 , 0 ) ;
V_2 -> V_5 = F_40 ( V_25 , V_87 ) ;
if ( F_41 ( V_2 -> V_5 ) ) {
F_27 ( V_25 , L_7 ) ;
return F_42 ( V_2 -> V_5 ) ;
}
V_2 -> V_68 = F_43 ( V_25 , L_8 ) ;
if ( F_41 ( V_2 -> V_68 ) ) {
F_27 ( V_25 , L_9 ) ;
return F_42 ( V_2 -> V_68 ) ;
}
V_89 = 0 ;
F_44 (np, child_np) {
struct V_3 * V_4 ;
struct V_65 * V_65 ;
V_4 = F_35 ( V_25 , sizeof( * V_4 ) , V_91 ) ;
if ( ! V_4 ) {
V_90 = - V_92 ;
goto V_94;
}
V_2 -> V_77 [ V_89 ] = V_4 ;
V_65 = F_45 ( V_25 , V_83 , & V_95 ) ;
if ( F_41 ( V_65 ) ) {
F_27 ( V_25 , L_10 ) ;
V_90 = F_42 ( V_65 ) ;
goto V_94;
}
V_90 = F_46 ( V_83 , 0 , & V_88 ) ;
if ( V_90 ) {
F_27 ( V_25 , L_11 ,
V_89 ) ;
goto V_94;
}
V_4 -> V_9 = F_40 ( & V_65 -> V_25 , & V_88 ) ;
if ( F_41 ( V_4 -> V_9 ) ) {
F_27 ( V_25 , L_12 ) ;
V_90 = F_42 ( V_4 -> V_9 ) ;
goto V_94;
}
V_4 -> V_65 = V_65 ;
V_4 -> V_18 = V_89 ;
F_47 ( V_65 , V_4 ) ;
V_89 ++ ;
}
V_85 = F_48 ( V_25 , F_32 ) ;
return F_49 ( V_85 ) ;
V_94:
F_50 ( V_83 ) ;
return V_90 ;
}
