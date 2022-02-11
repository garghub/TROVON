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
V_14 -> V_15 = 0 ;
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
int V_10 = F_6 ( V_7 ) ;
int V_37 = 0 ;
T_1 V_38 , V_39 ;
T_1 V_40 , V_41 , V_42 ;
T_1 V_43 , V_44 ;
T_1 V_45 , V_46 ;
T_1 V_47 , V_48 , V_49 ;
T_2 V_50 ;
if ( ! V_12 )
return;
V_38 = F_20 ( V_9 , V_7 ) ;
V_39 = F_21 ( V_9 , V_7 ) ;
if ( V_38 == V_39 )
V_50 = 0 ;
else if ( V_38 > V_39 )
V_50 = 100 * V_38 / V_39 ;
else
V_50 = 100 * V_39 / V_38 ;
if ( V_50 > 600 ) {
F_22 ( V_36 , L_3 ) ;
return;
}
V_37 = ( V_38 != V_39 ) | F_12 ( V_2 ) ;
V_42 = F_23 ( V_2 , V_7 ) |
F_24 ( V_7 ) ;
V_40 = 0 ;
V_41 = 0 ;
if ( V_37 ) {
T_3 V_51 ;
V_40 = 1 ;
V_51 = ( T_3 ) 0x0400000 * V_38 ;
F_25 ( V_51 , V_39 ) ;
V_41 = V_51 ;
}
V_43 = 0x00011110 ;
V_44 = 0x0 ;
if ( V_37 ) {
V_44 = 0x1 ;
if ( F_12 ( V_2 ) ) {
V_43 |= 0x1 ;
V_44 |= F_6 ( V_7 ) ?
( 0x1 << 24 ) : ( 0x1 << 25 ) ;
}
}
switch ( F_26 ( V_2 ) ) {
case 5 :
case 6 :
case 7 :
case 8 :
V_45 = 0x02400000 ;
V_46 = 0x00100060 ;
break;
default:
V_45 = 0x01800000 ;
V_46 = 0x00100060 ;
break;
}
V_49 = F_27 ( V_7 , V_2 ) ;
V_47 = ( V_10 ? V_49 : 0 ) | 1 ;
V_48 = ( ! V_10 ? V_49 : 0 ) | 1 ;
F_2 ( V_2 , V_52 , V_44 ) ;
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_53 , V_42 ) ;
F_2 ( V_2 , V_54 , V_40 ) ;
F_2 ( V_2 , V_55 , V_41 ) ;
F_2 ( V_2 , V_56 , V_43 ) ;
F_2 ( V_2 , V_57 , V_45 ) ;
F_2 ( V_2 , V_58 , V_46 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
F_2 ( V_2 , V_59 , V_47 ) ;
F_2 ( V_2 , V_60 , V_48 ) ;
F_2 ( V_2 , V_61 , F_28 ( V_2 , V_7 ) ) ;
F_29 ( V_2 , V_7 , V_38 , V_39 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_62 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
T_1 V_63 , V_64 , V_65 ;
int V_66 = V_14 -> V_66 ;
int V_67 = F_26 ( V_2 ) ;
V_63 =
V_65 = F_31 ( V_67 ) ;
V_64 = 0x3300 ;
if ( ( V_66 <= 0 ) || ! V_62 ) {
V_63 = 0 ;
V_64 = 0 ;
}
if ( F_12 ( V_2 ) )
V_63 = V_63 & 0xffff ;
F_2 ( V_2 , V_68 , V_64 ) ;
F_32 ( V_2 , V_69 , V_65 , V_63 ) ;
F_32 ( V_2 , V_70 , V_65 , V_63 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_17 = F_31 ( F_26 ( V_2 ) ) ;
F_2 ( V_2 , V_71 , V_17 ) ;
F_2 ( V_2 , V_72 , V_17 ) ;
}
static bool F_34 ( struct V_1 * V_2 )
{
T_1 V_73 , V_74 ;
bool V_75 = false ;
V_73 = V_74 = F_31 ( F_26 ( V_2 ) ) ;
if ( F_12 ( V_2 ) )
V_73 = V_73 & 0xffff ;
if ( ( F_35 ( V_2 , V_71 ) & V_73 ) ||
( F_35 ( V_2 , V_72 ) & V_74 ) )
V_75 = true ;
return V_75 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_17 ;
V_17 = ( F_37 ( V_7 ) && ! F_12 ( V_2 ) ) ?
0x01 : 0x11 ;
F_2 ( V_2 , V_76 , V_17 ) ;
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_2 ( V_2 , V_76 , 0 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
V_14 -> V_16 . V_17 = 0 ;
F_40 ( V_2 ) ;
F_1 ( V_2 ) ;
F_18 ( V_7 , V_2 ) ;
F_33 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
F_3 ( V_2 ) ;
F_42 ( V_2 ) ;
V_14 -> V_16 . V_17 = 0 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
bool V_77 = false ;
F_44 ( & V_9 -> V_78 ) ;
if ( ! F_45 ( V_7 ) )
goto V_79;
if ( F_34 ( V_2 ) )
V_77 = true ;
F_33 ( V_2 ) ;
V_79:
F_46 ( & V_9 -> V_78 ) ;
if ( V_77 )
F_47 ( V_7 -> V_22 ) ;
}
static T_4 F_48 ( int V_66 , void * V_80 )
{
struct V_1 * V_2 = V_80 ;
F_49 ( V_2 , F_43 ) ;
return V_81 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
int V_66 = V_14 -> V_66 ;
int V_75 ;
if ( V_66 > 0 ) {
V_75 = F_51 ( V_36 , V_66 ,
F_48 ,
V_82 ,
F_52 ( V_36 ) , V_2 ) ;
if ( V_75 )
return V_75 ;
}
V_75 = F_53 ( V_7 , V_2 , & V_14 -> V_83 ) ;
return V_75 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_25 * V_84 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
int V_75 ;
if ( F_55 ( V_7 ) && ! F_6 ( V_7 ) )
return 0 ;
V_75 = F_56 ( V_2 , V_7 , V_84 ,
F_6 ( V_7 ) ?
L_4 :
L_5 ,
F_18 ,
& V_14 -> V_85 , 1 ) ;
if ( V_75 < 0 )
return V_75 ;
V_75 = F_56 ( V_2 , V_7 , V_84 ,
F_6 ( V_7 ) ?
L_6 :
L_7 ,
F_18 ,
& V_14 -> V_16 , 192000 ) ;
return V_75 ;
}
struct V_1 * F_57 ( struct V_8 * V_9 , int V_67 )
{
if ( F_58 ( V_67 < 0 || V_67 >= F_59 ( V_9 ) ) )
V_67 = 0 ;
return F_60 ( F_61 ( V_9 , V_67 ) ) ;
}
int F_62 ( struct V_8 * V_9 )
{
struct V_86 * V_87 ;
struct V_86 * V_88 ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
struct V_13 * V_14 ;
struct V_89 * V_89 ;
char V_90 [ V_91 ] ;
int V_92 , V_93 , V_75 ;
if ( F_63 ( V_9 ) )
return 0 ;
V_87 = F_8 ( V_9 ) ;
if ( ! V_87 )
return 0 ;
V_93 = F_64 ( V_87 ) ;
if ( ! V_93 ) {
V_75 = - V_94 ;
goto V_95;
}
V_14 = F_65 ( V_36 , sizeof( * V_14 ) * V_93 , V_96 ) ;
if ( ! V_14 ) {
V_75 = - V_97 ;
goto V_95;
}
V_9 -> V_98 = V_93 ;
V_9 -> V_14 = V_14 ;
V_92 = 0 ;
F_66 (node, np) {
if ( ! F_67 ( V_88 ) )
goto V_99;
V_14 = F_61 ( V_9 , V_92 ) ;
snprintf ( V_90 , V_91 , L_8 ,
V_100 , V_92 ) ;
V_14 -> V_66 = F_68 ( V_88 , 0 ) ;
if ( ! V_14 -> V_66 ) {
V_75 = - V_94 ;
goto V_95;
}
V_89 = F_69 ( V_36 , V_90 ) ;
if ( F_70 ( V_89 ) ) {
V_75 = F_71 ( V_89 ) ;
goto V_95;
}
V_75 = F_72 ( V_9 , F_60 ( V_14 ) ,
& V_101 , V_89 , V_102 ,
V_103 , V_92 ) ;
if ( V_75 )
goto V_95;
V_99:
V_92 ++ ;
}
V_75 = 0 ;
V_95:
F_73 ( V_87 ) ;
return V_75 ;
}
void F_74 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
int V_92 ;
F_75 (src, priv, i) {
F_76 ( F_60 ( V_14 ) ) ;
}
}
