static inline bool F_1 ( struct V_1 * V_2 )
{
return ! ! ( F_2 ( V_2 -> V_3 + V_4 ) & V_5 ) ;
}
static void F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
F_4 ( V_7 -> V_10 ) ;
if ( V_9 -> V_11 ) {
F_5 ( V_9 ) ;
F_6 ( V_9 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_8 ( V_9 , V_2 -> V_3 ) ;
F_9 ( & V_2 -> V_12 ) ;
F_10 ( V_9 , V_2 ) ;
}
static void F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 , * V_13 ;
F_12 (port, tmp, &pcie->ports, list) {
F_13 ( V_2 -> V_14 ) ;
F_4 ( V_2 -> V_15 ) ;
F_7 ( V_2 ) ;
}
F_3 ( V_7 ) ;
}
static void T_1 * F_14 ( struct V_16 * V_17 ,
unsigned int V_18 , int V_19 )
{
struct V_20 * V_21 = F_15 ( V_17 ) ;
struct V_6 * V_7 = F_16 ( V_21 ) ;
F_17 ( F_18 ( V_19 , F_19 ( V_18 ) , F_20 ( V_18 ) ,
V_17 -> V_22 ) , V_7 -> V_3 + V_23 ) ;
return V_7 -> V_3 + V_24 + ( V_19 & 3 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 V_25 = F_19 ( V_2 -> V_26 << 3 ) ;
T_2 V_27 = F_20 ( V_2 -> V_26 << 3 ) ;
T_2 V_28 ;
V_28 = F_2 ( V_7 -> V_3 + V_29 ) ;
V_28 |= F_22 ( V_2 -> V_26 ) ;
F_17 ( V_28 , V_7 -> V_3 + V_29 ) ;
F_17 ( V_30 | V_31 ,
V_2 -> V_3 + V_32 ) ;
F_17 ( V_33 | V_34 , V_2 -> V_3 + V_35 ) ;
F_17 ( F_18 ( V_36 , V_25 , V_27 , 0 ) ,
V_7 -> V_3 + V_23 ) ;
V_28 = F_2 ( V_7 -> V_3 + V_24 ) ;
V_28 &= ~ V_37 ;
V_28 |= F_23 ( 0x806c ) ;
F_17 ( F_18 ( V_36 , V_25 , V_27 , 0 ) ,
V_7 -> V_3 + V_23 ) ;
F_17 ( V_28 , V_7 -> V_3 + V_24 ) ;
F_17 ( F_18 ( V_38 , V_25 , V_27 , 0 ) ,
V_7 -> V_3 + V_23 ) ;
V_28 = F_2 ( V_7 -> V_3 + V_24 ) ;
V_28 &= ~ V_39 ;
V_28 |= F_24 ( 0x50 ) ;
F_17 ( F_18 ( V_38 , V_25 , V_27 , 0 ) ,
V_7 -> V_3 + V_23 ) ;
F_17 ( V_28 , V_7 -> V_3 + V_24 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
T_2 V_28 ;
V_28 = F_2 ( V_7 -> V_3 + V_40 ) ;
V_28 |= F_26 ( V_2 -> V_26 ) ;
F_17 ( V_28 , V_7 -> V_3 + V_40 ) ;
V_28 = F_2 ( V_7 -> V_3 + V_40 ) ;
V_28 &= ~ F_26 ( V_2 -> V_26 ) ;
F_17 ( V_28 , V_7 -> V_3 + V_40 ) ;
F_27 ( 100 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_7 -> V_9 ;
int V_41 ;
V_41 = F_29 ( V_2 -> V_15 ) ;
if ( V_41 ) {
F_30 ( V_9 , L_1 , V_2 -> V_26 ) ;
goto V_42;
}
F_31 ( V_2 -> V_43 ) ;
F_32 ( V_2 -> V_43 ) ;
V_41 = F_33 ( V_2 -> V_14 ) ;
if ( V_41 ) {
F_30 ( V_9 , L_2 , V_2 -> V_26 ) ;
goto V_44;
}
F_25 ( V_2 ) ;
if ( F_1 ( V_2 ) ) {
F_21 ( V_2 ) ;
return;
}
F_34 ( V_9 , L_3 , V_2 -> V_26 ) ;
F_13 ( V_2 -> V_14 ) ;
V_44:
F_4 ( V_2 -> V_15 ) ;
V_42:
F_7 ( V_2 ) ;
}
static int F_35 ( struct V_6 * V_7 ,
struct V_45 * V_46 ,
int V_26 )
{
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_49 * V_50 = F_36 ( V_9 ) ;
char V_51 [ 10 ] ;
int V_41 ;
V_2 = F_37 ( V_9 , sizeof( * V_2 ) , V_52 ) ;
if ( ! V_2 )
return - V_53 ;
V_41 = F_38 ( V_46 , L_4 , & V_2 -> V_54 ) ;
if ( V_41 ) {
F_30 ( V_9 , L_5 ) ;
return V_41 ;
}
V_48 = F_39 ( V_50 , V_55 , V_26 + 1 ) ;
V_2 -> V_3 = F_40 ( V_9 , V_48 ) ;
if ( F_41 ( V_2 -> V_3 ) ) {
F_30 ( V_9 , L_6 , V_26 ) ;
return F_42 ( V_2 -> V_3 ) ;
}
snprintf ( V_51 , sizeof( V_51 ) , L_7 , V_26 ) ;
V_2 -> V_15 = F_43 ( V_9 , V_51 ) ;
if ( F_41 ( V_2 -> V_15 ) ) {
F_30 ( V_9 , L_8 , V_26 ) ;
return F_42 ( V_2 -> V_15 ) ;
}
snprintf ( V_51 , sizeof( V_51 ) , L_9 , V_26 ) ;
V_2 -> V_43 = F_44 ( V_9 , V_51 ) ;
if ( F_42 ( V_2 -> V_43 ) == - V_56 )
return F_42 ( V_2 -> V_43 ) ;
snprintf ( V_51 , sizeof( V_51 ) , L_10 , V_26 ) ;
V_2 -> V_14 = F_45 ( V_9 , V_51 ) ;
if ( F_41 ( V_2 -> V_14 ) )
return F_42 ( V_2 -> V_14 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_7 = V_7 ;
F_46 ( & V_2 -> V_12 ) ;
F_47 ( & V_2 -> V_12 , & V_7 -> V_57 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_49 * V_50 = F_36 ( V_9 ) ;
struct V_47 * V_48 ;
int V_41 ;
V_48 = F_39 ( V_50 , V_55 , 0 ) ;
V_7 -> V_3 = F_40 ( V_9 , V_48 ) ;
if ( F_41 ( V_7 -> V_3 ) ) {
F_30 ( V_9 , L_11 ) ;
return F_42 ( V_7 -> V_3 ) ;
}
V_7 -> V_10 = F_43 ( V_9 , L_12 ) ;
if ( F_41 ( V_7 -> V_10 ) ) {
if ( F_42 ( V_7 -> V_10 ) == - V_56 )
return - V_56 ;
V_7 -> V_10 = NULL ;
}
if ( V_9 -> V_11 ) {
F_49 ( V_9 ) ;
F_50 ( V_9 ) ;
}
V_41 = F_29 ( V_7 -> V_10 ) ;
if ( V_41 ) {
F_30 ( V_9 , L_13 ) ;
goto V_58;
}
return 0 ;
V_58:
if ( V_9 -> V_11 ) {
F_5 ( V_9 ) ;
F_6 ( V_9 ) ;
}
return V_41 ;
}
static int F_51 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_45 * V_46 = V_9 -> V_59 , * V_60 ;
struct V_61 V_62 ;
struct V_63 V_64 ;
struct V_47 V_65 ;
struct V_1 * V_2 , * V_13 ;
int V_41 ;
if ( F_52 ( & V_62 , V_46 ) ) {
F_30 ( V_9 , L_14 ) ;
return - V_66 ;
}
F_53 (&parser, &range) {
V_41 = F_54 ( & V_64 , V_46 , & V_65 ) ;
if ( V_41 < 0 )
return V_41 ;
switch ( V_65 . V_67 & V_68 ) {
case V_69 :
V_7 -> V_70 . V_71 = V_65 . V_72 - V_64 . V_73 ;
memcpy ( & V_7 -> V_74 , & V_65 , sizeof( V_65 ) ) ;
V_7 -> V_74 . V_51 = V_46 -> V_75 ;
V_7 -> V_71 . V_72 = V_64 . V_76 ;
V_7 -> V_71 . V_77 = V_64 . V_76 + V_64 . V_78 - 1 ;
V_7 -> V_71 . V_67 = V_55 ;
V_7 -> V_71 . V_51 = L_15 ;
memcpy ( & V_65 , & V_7 -> V_71 , sizeof( V_65 ) ) ;
break;
case V_55 :
V_7 -> V_70 . V_79 = V_65 . V_72 - V_64 . V_73 ;
memcpy ( & V_7 -> V_79 , & V_65 , sizeof( V_65 ) ) ;
V_7 -> V_79 . V_51 = L_16 ;
break;
}
}
V_41 = F_55 ( V_46 , & V_7 -> V_80 ) ;
if ( V_41 < 0 ) {
F_30 ( V_9 , L_17 , V_41 ) ;
V_7 -> V_80 . V_51 = V_46 -> V_51 ;
V_7 -> V_80 . V_72 = 0 ;
V_7 -> V_80 . V_77 = 0xff ;
V_7 -> V_80 . V_67 = V_81 ;
}
F_56 (node, child) {
int V_26 ;
V_41 = F_57 ( V_60 ) ;
if ( V_41 < 0 ) {
F_30 ( V_9 , L_18 , V_41 ) ;
return V_41 ;
}
V_26 = F_20 ( V_41 ) ;
V_41 = F_35 ( V_7 , V_60 , V_26 ) ;
if ( V_41 )
return V_41 ;
}
V_41 = F_48 ( V_7 ) ;
if ( V_41 )
return V_41 ;
F_12 (port, tmp, &pcie->ports, list)
F_28 ( V_2 ) ;
if ( F_58 ( & V_7 -> V_57 ) )
F_3 ( V_7 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
struct V_20 * V_21 = F_60 ( V_7 ) ;
struct V_82 * V_83 = & V_21 -> V_83 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_41 ;
F_61 ( V_83 , & V_7 -> V_74 , V_7 -> V_70 . V_71 ) ;
F_61 ( V_83 , & V_7 -> V_79 , V_7 -> V_70 . V_79 ) ;
F_62 ( V_83 , & V_7 -> V_80 ) ;
V_41 = F_63 ( V_9 , V_83 ) ;
if ( V_41 < 0 )
return V_41 ;
F_64 ( & V_7 -> V_74 , V_7 -> V_71 . V_72 ) ;
return 0 ;
}
static int F_65 ( struct V_20 * V_21 )
{
struct V_6 * V_7 = F_16 ( V_21 ) ;
struct V_16 * V_60 ;
int V_41 ;
V_21 -> V_84 = V_7 -> V_80 . V_72 ;
V_21 -> V_9 . V_85 = V_7 -> V_9 ;
V_21 -> V_86 = & V_87 ;
V_21 -> V_88 = V_89 ;
V_21 -> V_90 = V_91 ;
V_41 = F_66 ( V_21 ) ;
if ( V_41 < 0 )
return V_41 ;
F_67 ( V_21 -> V_17 ) ;
F_68 ( V_21 -> V_17 ) ;
F_69 (child, &host->bus->children, node)
F_70 ( V_60 ) ;
F_71 ( V_21 -> V_17 ) ;
return 0 ;
}
static int F_72 ( struct V_49 * V_50 )
{
struct V_8 * V_9 = & V_50 -> V_9 ;
struct V_6 * V_7 ;
struct V_20 * V_21 ;
int V_41 ;
V_21 = F_73 ( V_9 , sizeof( * V_7 ) ) ;
if ( ! V_21 )
return - V_53 ;
V_7 = F_16 ( V_21 ) ;
V_7 -> V_9 = V_9 ;
F_74 ( V_50 , V_7 ) ;
F_46 ( & V_7 -> V_57 ) ;
V_41 = F_51 ( V_7 ) ;
if ( V_41 )
return V_41 ;
V_41 = F_59 ( V_7 ) ;
if ( V_41 )
goto V_92;
V_41 = F_65 ( V_21 ) ;
if ( V_41 )
goto V_92;
return 0 ;
V_92:
if ( ! F_58 ( & V_7 -> V_57 ) )
F_11 ( V_7 ) ;
return V_41 ;
}
