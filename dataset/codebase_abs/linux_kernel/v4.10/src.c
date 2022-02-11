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
int V_37 = 0 ;
T_1 V_38 , V_39 ;
T_1 V_40 , V_41 , V_42 ;
T_1 V_43 , V_44 ;
T_1 V_45 , V_46 ;
T_2 V_47 ;
if ( ! V_12 )
return;
V_38 = F_20 ( V_9 , V_7 ) ;
V_39 = F_21 ( V_9 , V_7 ) ;
if ( V_38 == V_39 )
V_47 = 0 ;
else if ( V_38 > V_39 )
V_47 = 100 * V_38 / V_39 ;
else
V_47 = 100 * V_39 / V_38 ;
if ( V_47 > 600 ) {
F_22 ( V_36 , L_3 ) ;
return;
}
V_37 = ( V_38 != V_39 ) | F_12 ( V_2 ) ;
V_42 = F_23 ( V_2 , V_7 ) |
F_24 ( V_7 ) ;
V_40 = 0 ;
V_41 = 0 ;
if ( V_37 ) {
T_3 V_48 ;
V_40 = 1 ;
V_48 = ( T_3 ) 0x0400000 * V_38 ;
F_25 ( V_48 , V_39 ) ;
V_41 = V_48 ;
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
F_2 ( V_2 , V_49 , V_44 ) ;
F_2 ( V_2 , V_4 , 1 ) ;
F_2 ( V_2 , V_50 , V_42 ) ;
F_2 ( V_2 , V_51 , V_40 ) ;
F_2 ( V_2 , V_52 , V_41 ) ;
F_2 ( V_2 , V_53 , V_43 ) ;
F_2 ( V_2 , V_54 , V_45 ) ;
F_2 ( V_2 , V_55 , V_46 ) ;
F_2 ( V_2 , V_4 , 0 ) ;
F_2 ( V_2 , V_56 , 1 ) ;
F_2 ( V_2 , V_57 , 1 ) ;
F_2 ( V_2 , V_58 , F_27 ( V_2 , V_7 ) ) ;
F_28 ( V_2 , V_7 , V_38 , V_39 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
int V_59 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
T_1 V_60 , V_61 , V_62 ;
int V_63 = V_14 -> V_63 ;
int V_64 = F_26 ( V_2 ) ;
V_60 =
V_62 = F_30 ( V_64 ) ;
V_61 = 0x3300 ;
if ( ( V_63 <= 0 ) || ! V_59 ) {
V_60 = 0 ;
V_61 = 0 ;
}
if ( F_12 ( V_2 ) )
V_60 = V_60 & 0xffff ;
F_2 ( V_2 , V_65 , V_61 ) ;
F_31 ( V_2 , V_66 , V_62 , V_60 ) ;
F_31 ( V_2 , V_67 , V_62 , V_60 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_1 V_17 = F_30 ( F_26 ( V_2 ) ) ;
F_2 ( V_2 , V_68 , V_17 ) ;
F_2 ( V_2 , V_69 , V_17 ) ;
}
static bool F_33 ( struct V_1 * V_2 )
{
T_1 V_70 , V_71 ;
bool V_72 = false ;
V_70 = V_71 = F_30 ( F_26 ( V_2 ) ) ;
if ( F_12 ( V_2 ) )
V_70 = V_70 & 0xffff ;
if ( ( F_34 ( V_2 , V_68 ) & V_70 ) ||
( F_34 ( V_2 , V_69 ) & V_71 ) )
V_72 = true ;
return V_72 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_17 ;
V_17 = ( F_36 ( V_7 ) && ! F_12 ( V_2 ) ) ?
0x01 : 0x11 ;
F_2 ( V_2 , V_73 , V_17 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
F_2 ( V_2 , V_73 , 0 ) ;
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
bool V_74 = false ;
F_43 ( & V_9 -> V_75 ) ;
if ( ! F_44 ( V_7 ) )
goto V_76;
if ( F_33 ( V_2 ) )
V_74 = true ;
F_32 ( V_2 ) ;
V_76:
F_45 ( & V_9 -> V_75 ) ;
if ( V_74 )
F_46 ( V_7 -> V_22 ) ;
}
static T_4 F_47 ( int V_63 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
F_48 ( V_2 , F_42 ) ;
return V_78 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
int V_63 = V_14 -> V_63 ;
int V_72 ;
if ( V_63 > 0 ) {
V_72 = F_50 ( V_36 , V_63 ,
F_47 ,
V_79 ,
F_51 ( V_36 ) , V_2 ) ;
if ( V_72 )
return V_72 ;
}
V_72 = F_52 ( V_7 , V_2 , & V_14 -> V_80 ) ;
return V_72 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_25 * V_81 )
{
struct V_13 * V_14 = F_11 ( V_2 ) ;
int V_72 ;
if ( F_54 ( V_7 ) && ! F_6 ( V_7 ) )
return 0 ;
V_72 = F_55 ( V_2 , V_7 , V_81 ,
F_6 ( V_7 ) ?
L_4 :
L_5 ,
F_18 ,
& V_14 -> V_82 , 1 ) ;
if ( V_72 < 0 )
return V_72 ;
V_72 = F_55 ( V_2 , V_7 , V_81 ,
F_6 ( V_7 ) ?
L_6 :
L_7 ,
F_18 ,
& V_14 -> V_16 , 192000 ) ;
return V_72 ;
}
struct V_1 * F_56 ( struct V_8 * V_9 , int V_64 )
{
if ( F_57 ( V_64 < 0 || V_64 >= F_58 ( V_9 ) ) )
V_64 = 0 ;
return F_59 ( F_60 ( V_9 , V_64 ) ) ;
}
int F_61 ( struct V_8 * V_9 )
{
struct V_83 * V_84 ;
struct V_83 * V_85 ;
struct V_35 * V_36 = F_19 ( V_9 ) ;
struct V_13 * V_14 ;
struct V_86 * V_86 ;
char V_87 [ V_88 ] ;
int V_89 , V_90 , V_72 ;
if ( F_62 ( V_9 ) )
return 0 ;
V_84 = F_8 ( V_9 ) ;
if ( ! V_84 )
return 0 ;
V_90 = F_63 ( V_84 ) ;
if ( ! V_90 ) {
V_72 = - V_91 ;
goto V_92;
}
V_14 = F_64 ( V_36 , sizeof( * V_14 ) * V_90 , V_93 ) ;
if ( ! V_14 ) {
V_72 = - V_94 ;
goto V_92;
}
V_9 -> V_95 = V_90 ;
V_9 -> V_14 = V_14 ;
V_89 = 0 ;
F_65 (node, np) {
if ( ! F_66 ( V_85 ) )
goto V_96;
V_14 = F_60 ( V_9 , V_89 ) ;
snprintf ( V_87 , V_88 , L_8 ,
V_97 , V_89 ) ;
V_14 -> V_63 = F_67 ( V_85 , 0 ) ;
if ( ! V_14 -> V_63 ) {
V_72 = - V_91 ;
goto V_92;
}
V_86 = F_68 ( V_36 , V_87 ) ;
if ( F_69 ( V_86 ) ) {
V_72 = F_70 ( V_86 ) ;
goto V_92;
}
V_72 = F_71 ( V_9 , F_59 ( V_14 ) ,
& V_98 , V_86 , V_99 ,
V_100 , V_89 ) ;
if ( V_72 )
goto V_92;
V_96:
V_89 ++ ;
}
V_72 = 0 ;
V_92:
F_72 ( V_84 ) ;
return V_72 ;
}
void F_73 ( struct V_8 * V_9 )
{
struct V_13 * V_14 ;
int V_89 ;
F_74 (src, priv, i) {
F_75 ( F_59 ( V_14 ) ) ;
}
}
