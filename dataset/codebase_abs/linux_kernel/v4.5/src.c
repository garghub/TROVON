static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , 0 ) ;
F_2 ( V_2 , V_3 , 1 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_3 , 0 ) ;
}
static struct V_5 * F_4 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
int V_10 = F_6 ( V_7 ) ;
return F_7 ( F_8 ( V_9 ) ,
V_2 ,
V_10 ? L_1 : L_2 ) ;
}
static T_1 F_9 ( struct V_6 * V_7 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_10 ( V_7 ) ;
T_1 V_15 ;
if ( ! V_14 )
return 0 ;
if ( ! F_11 ( V_12 ) )
return V_12 -> V_15 ;
V_15 = V_12 -> V_16 . V_17 ;
if ( ! V_15 )
V_15 = V_12 -> V_15 ;
if ( ! V_15 )
V_15 = V_14 -> V_18 ;
return V_15 ;
}
unsigned int F_12 ( struct V_8 * V_9 ,
struct V_6 * V_7 ,
struct V_13 * V_14 )
{
struct V_1 * V_19 = F_13 ( V_7 ) ;
struct V_11 * V_12 ;
unsigned int V_18 = 0 ;
if ( V_19 ) {
V_12 = F_14 ( V_19 ) ;
V_18 = F_9 ( V_7 , V_12 ) ;
}
if ( ! V_18 )
V_18 = V_14 -> V_18 ;
return V_18 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
struct V_24 * V_25 = V_21 -> V_26 ;
if ( V_25 -> V_27 -> V_28 ) {
int V_29 = V_21 -> V_29 ;
struct V_30 * V_31 ;
struct V_22 * V_32 ;
F_16 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_32 = & V_31 -> V_33 ;
if ( F_17 ( V_23 ) != F_17 ( V_32 ) )
V_12 -> V_15 = F_17 ( V_32 ) ;
}
}
return 0 ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_34 * V_35 = F_19 ( V_9 ) ;
struct V_13 * V_14 = F_10 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_2 ) ;
T_1 V_15 = F_9 ( V_7 , V_12 ) ;
T_1 V_36 , V_37 , V_38 ;
T_1 V_39 , V_40 ;
T_1 V_41 , V_42 ;
T_2 V_43 ;
if ( ! V_14 )
return;
if ( ! V_15 )
V_43 = 0 ;
else if ( V_15 > V_14 -> V_18 )
V_43 = 100 * V_15 / V_14 -> V_18 ;
else
V_43 = 100 * V_14 -> V_18 / V_15 ;
if ( V_43 > 600 ) {
F_20 ( V_35 , L_3 ) ;
return;
}
V_38 = F_21 ( V_2 , V_7 ) |
F_22 ( V_2 , V_7 ) ;
V_36 = 0 ;
V_37 = 0 ;
if ( V_15 ) {
V_36 = 1 ;
V_37 = 0x0400000 / V_15 * V_14 -> V_18 ;
}
V_39 = 0x00011110 ;
V_40 = 0x0 ;
if ( V_15 ) {
V_40 = 0x1 ;
if ( F_11 ( V_12 ) ) {
V_39 |= 0x1 ;
V_40 |= F_6 ( V_7 ) ?
( 0x1 << 24 ) : ( 0x1 << 25 ) ;
}
}
switch ( F_23 ( V_2 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
V_41 = 0x02400000 ;
V_42 = 0x00100060 ;
break;
default:
V_41 = 0x01800000 ;
V_42 = 0x00100060 ;
break;
}
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_44 , V_38 ) ;
F_2 ( V_2 , V_45 , V_36 ) ;
F_2 ( V_2 , V_46 , V_37 ) ;
F_2 ( V_2 , V_47 , V_39 ) ;
F_2 ( V_2 , V_48 , V_41 ) ;
F_2 ( V_2 , V_49 , V_42 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
F_2 ( V_2 , V_50 , V_40 ) ;
F_2 ( V_2 , V_51 , 1 ) ;
F_2 ( V_2 , V_52 , 1 ) ;
F_2 ( V_2 , V_53 , F_24 ( V_2 , V_7 ) ) ;
if ( V_15 )
F_25 ( V_2 , V_7 ,
V_14 -> V_18 ,
V_15 ) ;
else
F_26 ( V_2 , V_7 ) ;
}
static void F_27 ( struct V_1 * V_2 , int V_54 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
T_1 V_55 , V_56 , V_57 ;
int V_58 = V_12 -> V_58 ;
int V_59 = F_23 ( V_2 ) ;
V_55 =
V_57 = F_28 ( V_59 ) ;
V_56 = 0x3300 ;
if ( ( V_58 <= 0 ) || ! V_54 ) {
V_55 = 0 ;
V_56 = 0 ;
}
if ( F_11 ( V_12 ) )
V_55 = V_55 & 0xffff ;
F_2 ( V_2 , V_60 , V_56 ) ;
F_29 ( V_2 , V_61 , V_57 , V_55 ) ;
F_29 ( V_2 , V_62 , V_57 , V_55 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
T_1 V_17 = F_28 ( F_23 ( V_2 ) ) ;
F_29 ( V_2 , V_63 , V_17 , V_17 ) ;
F_29 ( V_2 , V_64 , V_17 , V_17 ) ;
}
static bool F_31 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
T_1 V_65 , V_66 ;
bool V_67 = false ;
V_65 = V_66 = F_28 ( F_23 ( V_2 ) ) ;
if ( F_11 ( V_12 ) )
V_65 = V_65 & 0xffff ;
if ( ( F_32 ( V_2 , V_63 ) & V_65 ) ||
( F_32 ( V_2 , V_64 ) & V_66 ) ) {
struct V_11 * V_12 = F_14 ( V_2 ) ;
V_12 -> V_68 ++ ;
V_67 = true ;
}
return V_67 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
T_1 V_17 ;
V_17 = ( F_34 ( V_7 ) && ! F_11 ( V_12 ) ) ?
0x01 : 0x11 ;
F_2 ( V_2 , V_69 , V_17 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_2 ( V_2 , V_69 , 0x01 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
F_37 ( V_2 ) ;
F_1 ( V_2 ) ;
F_18 ( V_7 , V_2 ) ;
F_30 ( V_2 ) ;
F_38 ( V_2 ) ;
V_12 -> V_68 = 0 ;
V_12 -> V_16 . V_17 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
struct V_34 * V_35 = F_19 ( V_9 ) ;
F_40 ( V_2 ) ;
F_2 ( V_2 , V_69 , 0 ) ;
F_3 ( V_2 ) ;
F_41 ( V_2 ) ;
if ( V_12 -> V_68 )
F_42 ( V_35 , L_4 ,
F_43 ( V_2 ) , F_23 ( V_2 ) , V_12 -> V_68 ) ;
V_12 -> V_15 = 0 ;
V_12 -> V_16 . V_17 = 0 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_11 * V_12 = F_14 ( V_2 ) ;
struct V_34 * V_35 = F_19 ( V_9 ) ;
F_45 ( & V_9 -> V_70 ) ;
if ( ! F_46 ( V_7 ) )
goto V_71;
if ( F_31 ( V_2 ) ) {
F_47 ( V_35 , L_5 ,
F_43 ( V_2 ) , F_23 ( V_2 ) ) ;
F_35 ( V_2 , V_7 , V_9 ) ;
F_33 ( V_2 , V_7 , V_9 ) ;
}
if ( V_12 -> V_68 > 1024 ) {
F_40 ( V_2 ) ;
F_42 ( V_35 , L_6 ,
F_43 ( V_2 ) , F_23 ( V_2 ) ) ;
}
F_30 ( V_2 ) ;
V_71:
F_48 ( & V_9 -> V_70 ) ;
}
static T_3 F_49 ( int V_58 , void * V_72 )
{
struct V_1 * V_2 = V_72 ;
F_50 ( V_2 , F_44 ) ;
return V_73 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_11 * V_12 = F_14 ( V_2 ) ;
struct V_34 * V_35 = F_19 ( V_9 ) ;
int V_58 = V_12 -> V_58 ;
int V_67 ;
if ( V_58 > 0 ) {
V_67 = F_52 ( V_35 , V_58 ,
F_49 ,
V_74 ,
F_53 ( V_35 ) , V_2 ) ;
if ( V_67 )
return V_67 ;
}
V_12 -> V_75 = F_54 ( V_7 , V_2 , 0 ) ;
if ( F_55 ( V_12 -> V_75 ) )
return F_56 ( V_12 -> V_75 ) ;
return V_67 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_24 * V_76 )
{
struct V_77 * V_78 = F_58 ( V_7 ) ;
struct V_1 * V_79 = F_34 ( V_7 ) ;
struct V_11 * V_12 = F_14 ( V_2 ) ;
int V_67 ;
if ( ! F_59 ( V_78 ) )
return 0 ;
if ( V_79 && ! F_6 ( V_7 ) )
return 0 ;
V_67 = F_60 ( V_2 , V_7 , V_76 ,
F_6 ( V_7 ) ?
L_7 :
L_8 ,
F_18 ,
& V_12 -> V_80 , 1 ) ;
if ( V_67 < 0 )
return V_67 ;
V_67 = F_60 ( V_2 , V_7 , V_76 ,
F_6 ( V_7 ) ?
L_9 :
L_10 ,
F_18 ,
& V_12 -> V_16 , 192000 ) ;
return V_67 ;
}
struct V_1 * F_61 ( struct V_8 * V_9 , int V_59 )
{
if ( F_62 ( V_59 < 0 || V_59 >= F_63 ( V_9 ) ) )
V_59 = 0 ;
return F_64 ( F_65 ( V_9 , V_59 ) ) ;
}
int F_66 ( struct V_8 * V_9 )
{
struct V_81 * V_82 ;
struct V_81 * V_83 ;
struct V_34 * V_35 = F_19 ( V_9 ) ;
struct V_11 * V_12 ;
struct V_84 * V_84 ;
char V_85 [ V_86 ] ;
int V_87 , V_88 , V_67 ;
if ( F_67 ( V_9 ) )
return 0 ;
V_82 = F_8 ( V_9 ) ;
if ( ! V_82 )
return 0 ;
V_88 = F_68 ( V_82 ) ;
if ( ! V_88 ) {
V_67 = - V_89 ;
goto V_90;
}
V_12 = F_69 ( V_35 , sizeof( * V_12 ) * V_88 , V_91 ) ;
if ( ! V_12 ) {
V_67 = - V_92 ;
goto V_90;
}
V_9 -> V_93 = V_88 ;
V_9 -> V_12 = V_12 ;
V_87 = 0 ;
F_70 (node, np) {
V_12 = F_65 ( V_9 , V_87 ) ;
snprintf ( V_85 , V_86 , L_11 ,
V_94 , V_87 ) ;
V_12 -> V_58 = F_71 ( V_83 , 0 ) ;
if ( ! V_12 -> V_58 ) {
V_67 = - V_89 ;
goto V_90;
}
V_84 = F_72 ( V_35 , V_85 ) ;
if ( F_55 ( V_84 ) ) {
V_67 = F_56 ( V_84 ) ;
goto V_90;
}
V_67 = F_73 ( V_9 , F_64 ( V_12 ) ,
& V_95 , V_84 , V_96 , V_87 ) ;
if ( V_67 )
goto V_90;
V_87 ++ ;
}
V_67 = 0 ;
V_90:
F_74 ( V_82 ) ;
return V_67 ;
}
void F_75 ( struct V_8 * V_9 )
{
struct V_11 * V_12 ;
int V_87 ;
F_76 (src, priv, i) {
F_77 ( F_64 ( V_12 ) ) ;
}
}
