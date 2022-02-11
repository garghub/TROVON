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
struct V_1 * V_2 )
{
struct V_11 * V_12 = F_10 ( V_7 ) ;
struct V_13 * V_14 = F_11 ( V_2 ) ;
T_1 V_15 ;
if ( ! V_12 )
return 0 ;
if ( ! F_12 ( V_2 ) )
return V_14 -> V_15 ;
V_15 = V_14 -> V_16 . V_17 ;
if ( ! V_15 )
V_15 = V_14 -> V_15 ;
if ( ! V_15 )
V_15 = V_12 -> V_18 ;
return V_15 ;
}
unsigned int F_13 ( struct V_8 * V_9 ,
struct V_6 * V_7 ,
int V_19 )
{
struct V_1 * V_20 = F_14 ( V_7 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
unsigned int V_18 = 0 ;
int V_10 = F_6 ( V_7 ) ;
if ( V_10 == V_19 )
return V_12 -> V_18 ;
if ( V_20 )
V_18 = F_9 ( V_7 , V_20 ) ;
if ( ! V_18 )
V_18 = V_12 -> V_18 ;
return V_18 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_25 * V_26 = V_22 -> V_27 ;
if ( V_26 -> V_28 -> V_29 ) {
int V_30 = V_22 -> V_30 ;
struct V_31 * V_32 ;
struct V_23 * V_33 ;
F_16 (dpcm, &fe->dpcm[stream].be_clients, list_be) {
V_33 = & V_32 -> V_34 ;
if ( F_17 ( V_24 ) != F_17 ( V_33 ) )
V_14 -> V_15 = F_17 ( V_33 ) ;
}
}
return 0 ;
}
static void F_18 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
struct V_11 * V_12 = F_10 ( V_7 ) ;
T_1 V_37 , V_38 ;
T_1 V_39 , V_40 , V_41 ;
T_1 V_42 , V_43 ;
T_1 V_44 , V_45 ;
T_2 V_46 ;
if ( ! V_12 )
return;
V_37 = F_20 ( V_9 , V_7 ) ;
V_38 = F_21 ( V_9 , V_7 ) ;
if ( V_37 == V_38 )
V_46 = 0 ;
else if ( V_37 > V_38 )
V_46 = 100 * V_37 / V_38 ;
else
V_46 = 100 * V_38 / V_37 ;
if ( V_46 > 600 ) {
F_22 ( V_36 , L_3 ) ;
return;
}
V_41 = F_23 ( V_2 , V_7 ) |
F_24 ( V_7 ) ;
V_39 = 0 ;
V_40 = 0 ;
if ( V_37 != V_38 ) {
V_39 = 1 ;
V_40 = 0x0400000 / V_38 * V_37 ;
}
V_42 = 0x00011110 ;
V_43 = 0x0 ;
if ( V_37 != V_38 ) {
V_43 = 0x1 ;
if ( F_12 ( V_2 ) ) {
V_42 |= 0x1 ;
V_43 |= F_6 ( V_7 ) ?
( 0x1 << 24 ) : ( 0x1 << 25 ) ;
}
}
switch ( F_25 ( V_2 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
V_44 = 0x02400000 ;
V_45 = 0x00100060 ;
break;
default:
V_44 = 0x01800000 ;
V_45 = 0x00100060 ;
break;
}
F_2 ( V_2 , V_47 , V_43 ) ;
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_48 , V_41 ) ;
F_2 ( V_2 , V_49 , V_39 ) ;
F_2 ( V_2 , V_50 , V_40 ) ;
F_2 ( V_2 , V_51 , V_42 ) ;
F_2 ( V_2 , V_52 , V_44 ) ;
F_2 ( V_2 , V_53 , V_45 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
F_2 ( V_2 , V_54 , 1 ) ;
F_2 ( V_2 , V_55 , 1 ) ;
F_2 ( V_2 , V_56 , F_26 ( V_2 , V_7 ) ) ;
F_27 ( V_2 , V_7 , V_37 , V_38 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_57 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
T_1 V_58 , V_59 , V_60 ;
int V_61 = V_14 -> V_61 ;
int V_62 = F_25 ( V_2 ) ;
V_58 =
V_60 = F_29 ( V_62 ) ;
V_59 = 0x3300 ;
if ( ( V_61 <= 0 ) || ! V_57 ) {
V_58 = 0 ;
V_59 = 0 ;
}
if ( F_12 ( V_2 ) )
V_58 = V_58 & 0xffff ;
F_2 ( V_2 , V_63 , V_59 ) ;
F_30 ( V_2 , V_64 , V_60 , V_58 ) ;
F_30 ( V_2 , V_65 , V_60 , V_58 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 V_17 = F_29 ( F_25 ( V_2 ) ) ;
F_30 ( V_2 , V_66 , V_17 , V_17 ) ;
F_30 ( V_2 , V_67 , V_17 , V_17 ) ;
}
static bool F_32 ( struct V_1 * V_2 )
{
T_1 V_68 , V_69 ;
bool V_70 = false ;
V_68 = V_69 = F_29 ( F_25 ( V_2 ) ) ;
if ( F_12 ( V_2 ) )
V_68 = V_68 & 0xffff ;
if ( ( F_33 ( V_2 , V_66 ) & V_68 ) ||
( F_33 ( V_2 , V_67 ) & V_69 ) )
V_70 = true ;
return V_70 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_17 ;
V_17 = ( F_35 ( V_7 ) && ! F_12 ( V_2 ) ) ?
0x01 : 0x11 ;
F_2 ( V_2 , V_71 , V_17 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_2 ( V_2 , V_71 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
F_38 ( V_2 ) ;
F_1 ( V_2 ) ;
F_18 ( V_7 , V_2 ) ;
F_31 ( V_2 ) ;
V_14 -> V_16 . V_17 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
F_3 ( V_2 ) ;
F_40 ( V_2 ) ;
V_14 -> V_15 = 0 ;
V_14 -> V_16 . V_17 = 0 ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
bool V_72 = false ;
F_42 ( & V_9 -> V_73 ) ;
if ( ! F_43 ( V_7 ) )
goto V_74;
if ( F_32 ( V_2 ) )
V_72 = true ;
F_31 ( V_2 ) ;
V_74:
F_44 ( & V_9 -> V_73 ) ;
if ( V_72 )
F_45 ( V_7 -> V_22 ) ;
}
static T_3 F_46 ( int V_61 , void * V_75 )
{
struct V_1 * V_2 = V_75 ;
F_47 ( V_2 , F_41 ) ;
return V_76 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
int V_61 = V_14 -> V_61 ;
int V_70 ;
if ( V_61 > 0 ) {
V_70 = F_49 ( V_36 , V_61 ,
F_46 ,
V_77 ,
F_50 ( V_36 ) , V_2 ) ;
if ( V_70 )
return V_70 ;
}
V_70 = F_51 ( V_7 , V_2 , & V_14 -> V_78 , 0 ) ;
return V_70 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_25 * V_79 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
int V_70 ;
if ( F_53 ( V_7 ) && ! F_6 ( V_7 ) )
return 0 ;
V_70 = F_54 ( V_2 , V_7 , V_79 ,
F_6 ( V_7 ) ?
L_4 :
L_5 ,
F_18 ,
& V_14 -> V_80 , 1 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_54 ( V_2 , V_7 , V_79 ,
F_6 ( V_7 ) ?
L_6 :
L_7 ,
F_18 ,
& V_14 -> V_16 , 192000 ) ;
return V_70 ;
}
struct V_1 * F_55 ( struct V_8 * V_9 , int V_62 )
{
if ( F_56 ( V_62 < 0 || V_62 >= F_57 ( V_9 ) ) )
V_62 = 0 ;
return F_58 ( F_59 ( V_9 , V_62 ) ) ;
}
int F_60 ( struct V_8 * V_9 )
{
struct V_81 * V_82 ;
struct V_81 * V_83 ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
struct V_13 * V_14 ;
struct V_84 * V_84 ;
char V_85 [ V_86 ] ;
int V_87 , V_88 , V_70 ;
if ( F_61 ( V_9 ) )
return 0 ;
V_82 = F_8 ( V_9 ) ;
if ( ! V_82 )
return 0 ;
V_88 = F_62 ( V_82 ) ;
if ( ! V_88 ) {
V_70 = - V_89 ;
goto V_90;
}
V_14 = F_63 ( V_36 , sizeof( * V_14 ) * V_88 , V_91 ) ;
if ( ! V_14 ) {
V_70 = - V_92 ;
goto V_90;
}
V_9 -> V_93 = V_88 ;
V_9 -> V_14 = V_14 ;
V_87 = 0 ;
F_64 (node, np) {
V_14 = F_59 ( V_9 , V_87 ) ;
snprintf ( V_85 , V_86 , L_8 ,
V_94 , V_87 ) ;
V_14 -> V_61 = F_65 ( V_83 , 0 ) ;
if ( ! V_14 -> V_61 ) {
V_70 = - V_89 ;
goto V_90;
}
V_84 = F_66 ( V_36 , V_85 ) ;
if ( F_67 ( V_84 ) ) {
V_70 = F_68 ( V_84 ) ;
goto V_90;
}
V_70 = F_69 ( V_9 , F_58 ( V_14 ) ,
& V_95 , V_84 , V_96 ,
V_97 , V_87 ) ;
if ( V_70 )
goto V_90;
V_87 ++ ;
}
V_70 = 0 ;
V_90:
F_70 ( V_82 ) ;
return V_70 ;
}
void F_71 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
int V_87 ;
F_72 (src, priv, i) {
F_73 ( F_58 ( V_14 ) ) ;
}
}
