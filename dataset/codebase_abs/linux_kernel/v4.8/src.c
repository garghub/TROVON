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
T_3 V_47 ;
V_39 = 1 ;
V_47 = ( T_3 ) 0x0400000 * V_37 ;
F_25 ( V_47 , V_38 ) ;
V_40 = V_47 ;
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
switch ( F_26 ( V_2 ) ) {
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
F_2 ( V_2 , V_48 , V_43 ) ;
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_49 , V_41 ) ;
F_2 ( V_2 , V_50 , V_39 ) ;
F_2 ( V_2 , V_51 , V_40 ) ;
F_2 ( V_2 , V_52 , V_42 ) ;
F_2 ( V_2 , V_53 , V_44 ) ;
F_2 ( V_2 , V_54 , V_45 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
F_2 ( V_2 , V_55 , 1 ) ;
F_2 ( V_2 , V_56 , 1 ) ;
F_2 ( V_2 , V_57 , F_27 ( V_2 , V_7 ) ) ;
F_28 ( V_2 , V_7 , V_37 , V_38 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_58 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
T_1 V_59 , V_60 , V_61 ;
int V_62 = V_14 -> V_62 ;
int V_63 = F_26 ( V_2 ) ;
V_59 =
V_61 = F_30 ( V_63 ) ;
V_60 = 0x3300 ;
if ( ( V_62 <= 0 ) || ! V_58 ) {
V_59 = 0 ;
V_60 = 0 ;
}
if ( F_12 ( V_2 ) )
V_59 = V_59 & 0xffff ;
F_2 ( V_2 , V_64 , V_60 ) ;
F_31 ( V_2 , V_65 , V_61 , V_59 ) ;
F_31 ( V_2 , V_66 , V_61 , V_59 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_17 = F_30 ( F_26 ( V_2 ) ) ;
F_31 ( V_2 , V_67 , V_17 , V_17 ) ;
F_31 ( V_2 , V_68 , V_17 , V_17 ) ;
}
static bool F_33 ( struct V_1 * V_2 )
{
T_1 V_69 , V_70 ;
bool V_71 = false ;
V_69 = V_70 = F_30 ( F_26 ( V_2 ) ) ;
if ( F_12 ( V_2 ) )
V_69 = V_69 & 0xffff ;
if ( ( F_34 ( V_2 , V_67 ) & V_69 ) ||
( F_34 ( V_2 , V_68 ) & V_70 ) )
V_71 = true ;
return V_71 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_17 ;
V_17 = ( F_36 ( V_7 ) && ! F_12 ( V_2 ) ) ?
0x01 : 0x11 ;
F_2 ( V_2 , V_72 , V_17 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_2 ( V_2 , V_72 , 0 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
F_39 ( V_2 ) ;
F_1 ( V_2 ) ;
F_18 ( V_7 , V_2 ) ;
F_32 ( V_2 ) ;
V_14 -> V_16 . V_17 = 0 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
F_3 ( V_2 ) ;
F_41 ( V_2 ) ;
V_14 -> V_15 = 0 ;
V_14 -> V_16 . V_17 = 0 ;
return 0 ;
}
static void F_42 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
bool V_73 = false ;
F_43 ( & V_9 -> V_74 ) ;
if ( ! F_44 ( V_7 ) )
goto V_75;
if ( F_33 ( V_2 ) )
V_73 = true ;
F_32 ( V_2 ) ;
V_75:
F_45 ( & V_9 -> V_74 ) ;
if ( V_73 )
F_46 ( V_7 -> V_22 ) ;
}
static T_4 F_47 ( int V_62 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
F_48 ( V_2 , F_42 ) ;
return V_77 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
int V_62 = V_14 -> V_62 ;
int V_71 ;
if ( V_62 > 0 ) {
V_71 = F_50 ( V_36 , V_62 ,
F_47 ,
V_78 ,
F_51 ( V_36 ) , V_2 ) ;
if ( V_71 )
return V_71 ;
}
V_71 = F_52 ( V_7 , V_2 , & V_14 -> V_79 , 0 ) ;
return V_71 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_25 * V_80 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
int V_71 ;
if ( F_54 ( V_7 ) && ! F_6 ( V_7 ) )
return 0 ;
V_71 = F_55 ( V_2 , V_7 , V_80 ,
F_6 ( V_7 ) ?
L_4 :
L_5 ,
F_18 ,
& V_14 -> V_81 , 1 ) ;
if ( V_71 < 0 )
return V_71 ;
V_71 = F_55 ( V_2 , V_7 , V_80 ,
F_6 ( V_7 ) ?
L_6 :
L_7 ,
F_18 ,
& V_14 -> V_16 , 192000 ) ;
return V_71 ;
}
struct V_1 * F_56 ( struct V_8 * V_9 , int V_63 )
{
if ( F_57 ( V_63 < 0 || V_63 >= F_58 ( V_9 ) ) )
V_63 = 0 ;
return F_59 ( F_60 ( V_9 , V_63 ) ) ;
}
int F_61 ( struct V_8 * V_9 )
{
struct V_82 * V_83 ;
struct V_82 * V_84 ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
struct V_13 * V_14 ;
struct V_85 * V_85 ;
char V_86 [ V_87 ] ;
int V_88 , V_89 , V_71 ;
if ( F_62 ( V_9 ) )
return 0 ;
V_83 = F_8 ( V_9 ) ;
if ( ! V_83 )
return 0 ;
V_89 = F_63 ( V_83 ) ;
if ( ! V_89 ) {
V_71 = - V_90 ;
goto V_91;
}
V_14 = F_64 ( V_36 , sizeof( * V_14 ) * V_89 , V_92 ) ;
if ( ! V_14 ) {
V_71 = - V_93 ;
goto V_91;
}
V_9 -> V_94 = V_89 ;
V_9 -> V_14 = V_14 ;
V_88 = 0 ;
F_65 (node, np) {
if ( ! F_66 ( V_84 ) )
goto V_95;
V_14 = F_60 ( V_9 , V_88 ) ;
snprintf ( V_86 , V_87 , L_8 ,
V_96 , V_88 ) ;
V_14 -> V_62 = F_67 ( V_84 , 0 ) ;
if ( ! V_14 -> V_62 ) {
V_71 = - V_90 ;
goto V_91;
}
V_85 = F_68 ( V_36 , V_86 ) ;
if ( F_69 ( V_85 ) ) {
V_71 = F_70 ( V_85 ) ;
goto V_91;
}
V_71 = F_71 ( V_9 , F_59 ( V_14 ) ,
& V_97 , V_85 , V_98 ,
V_99 , V_88 ) ;
if ( V_71 )
goto V_91;
V_95:
V_88 ++ ;
}
V_71 = 0 ;
V_91:
F_72 ( V_83 ) ;
return V_71 ;
}
void F_73 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
int V_88 ;
F_74 (src, priv, i) {
F_75 ( F_59 ( V_14 ) ) ;
}
}
