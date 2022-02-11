static int F_1 ( void * V_1 , void T_1 * V_2 , T_2 V_3 )
{
T_2 V_4 = 0 ;
if ( F_2 ( ( V_5 ) V_2 , sizeof( V_5 ) ) &&
F_2 ( ( V_5 ) V_1 , sizeof( V_5 ) ) ) {
F_3 ( V_2 , V_1 , V_3 >> 2 ) ;
V_4 = V_3 & ~ 0x3 ;
V_3 -= V_4 ;
}
F_4 ( V_2 , ( V_6 * ) V_1 + V_4 , V_3 ) ;
return 0 ;
}
static int F_5 ( void T_1 * V_7 , const void * V_1 ,
T_2 V_3 )
{
T_2 V_4 = 0 ;
if ( F_2 ( ( V_5 ) V_7 , sizeof( V_5 ) ) &&
F_2 ( ( V_5 ) V_1 , sizeof( V_5 ) ) ) {
F_6 ( V_7 , V_1 , V_3 >> 2 ) ;
V_4 = V_3 & ~ 0x3 ;
V_3 -= V_4 ;
}
F_7 ( V_7 , ( const V_6 * ) V_1 + V_4 , V_3 ) ;
return 0 ;
}
static inline T_3 F_8 ( struct V_8 * V_9 )
{
return F_9 ( V_9 -> V_10 -> V_11 -> V_12 + V_9 -> V_13 ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_15 ;
V_15 = F_11 ( V_10 -> V_16 + V_17 ) ;
if ( V_15 & F_8 ( V_9 ) )
return;
F_12 ( V_10 -> V_18 , L_1 ,
V_10 -> V_16 + V_17 , V_15 ) ;
V_15 |= F_8 ( V_9 ) ;
F_13 ( V_15 , V_10 -> V_16 + V_17 ) ;
}
static void F_14 ( struct V_19 * V_20 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
T_3 V_22 = V_9 -> V_23 [ V_24 ] ;
F_10 ( V_9 ) ;
V_22 |= V_25 |
V_26 ;
F_13 ( V_22 , V_9 -> V_22 ) ;
V_22 &= ~ V_26 ;
F_13 ( V_22 , V_9 -> V_22 ) ;
}
static void F_15 ( struct V_19 * V_20 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
T_3 V_22 = V_9 -> V_23 [ V_27 ] ;
T_3 V_28 = V_22 | V_25 |
V_26 ;
F_13 ( V_28 , V_9 -> V_22 ) ;
F_13 ( V_22 , V_9 -> V_22 ) ;
}
static int F_16 ( struct V_19 * V_20 , enum V_29 V_30 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
F_17 ( & V_9 -> V_10 -> V_31 ) ;
return 0 ;
}
static void F_18 ( struct V_19 * V_20 , enum V_29 V_30 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
F_19 ( & V_9 -> V_10 -> V_31 ) ;
}
static int F_20 ( struct V_19 * V_20 , V_6 V_32 , V_6 * V_1 , int V_3 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
F_14 ( V_20 ) ;
F_5 ( V_9 -> V_33 , & V_32 , 1 ) ;
F_1 ( V_1 , V_9 -> V_33 , V_3 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_20 , V_6 V_32 , V_6 * V_1 ,
int V_3 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
F_14 ( V_20 ) ;
F_5 ( V_9 -> V_33 , & V_32 , 1 ) ;
F_5 ( V_9 -> V_33 , V_1 , V_3 ) ;
F_15 ( V_20 ) ;
return 0 ;
}
static void F_22 ( struct V_19 * V_20 , V_6 V_34 , T_3 V_35 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
T_4 V_36 ;
T_3 V_37 ;
switch ( V_20 -> V_38 ) {
default:
F_23 ( 1 , L_2 ,
V_20 -> V_38 ) ;
case 3 :
V_37 = V_35 & 0xFFFFFF ;
V_37 |= V_34 << 24 ;
V_36 = F_24 ( V_37 ) ;
F_5 ( V_9 -> V_33 , & V_36 , 4 ) ;
break;
case 4 :
V_36 = F_24 ( V_35 ) ;
F_5 ( V_9 -> V_33 , & V_34 , 1 ) ;
F_5 ( V_9 -> V_33 , & V_36 , 4 ) ;
break;
}
}
static T_5 F_25 ( struct V_19 * V_20 , T_6 V_39 ,
T_2 V_3 , T_7 * V_40 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
int V_41 ;
V_6 V_42 = 0xFF ;
F_14 ( V_20 ) ;
F_22 ( V_20 , V_20 -> V_43 , V_39 ) ;
for ( V_41 = 0 ; V_41 < V_9 -> V_20 . V_44 / 8 ; V_41 ++ )
F_5 ( V_9 -> V_33 , & V_42 , sizeof( V_42 ) ) ;
F_1 ( V_40 , V_9 -> V_33 , V_3 ) ;
F_15 ( V_20 ) ;
return V_3 ;
}
static T_5 F_26 ( struct V_19 * V_20 , T_6 V_45 ,
T_2 V_3 , const T_7 * V_46 )
{
struct V_8 * V_9 = V_20 -> V_21 ;
F_14 ( V_20 ) ;
F_22 ( V_20 , V_20 -> V_47 , V_45 ) ;
F_5 ( V_9 -> V_33 , V_46 , V_3 ) ;
F_15 ( V_20 ) ;
return V_3 ;
}
static int F_27 ( struct V_14 * V_10 )
{
struct V_8 * V_9 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_10 -> V_11 -> V_49 ; V_48 ++ ) {
V_9 = V_10 -> V_50 [ V_48 ] ;
if ( V_9 )
F_28 ( & V_9 -> V_20 . V_51 ) ;
}
return 0 ;
}
static int F_29 ( struct V_52 * V_18 )
{
return F_27 ( F_30 ( V_18 ) ) ;
}
static void T_1 * F_31 ( struct V_8 * V_9 ,
struct V_53 * V_54 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_4 = 0 ;
T_3 V_15 ;
if ( V_10 -> V_11 -> V_49 > 1 ) {
V_15 = F_11 ( V_10 -> V_16 + V_55 +
V_9 -> V_13 * 4 ) ;
if ( F_32 ( V_15 ) >= F_33 ( V_15 ) )
return NULL ;
V_4 = F_32 ( V_15 ) - V_54 -> V_56 ;
}
return V_10 -> V_33 + V_4 ;
}
static void F_34 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_15 ;
V_15 = F_11 ( V_10 -> V_16 + V_17 ) ;
V_15 |= F_8 ( V_9 ) ;
F_13 ( V_15 , V_10 -> V_16 + V_17 ) ;
}
static void F_35 ( struct V_8 * V_9 , int type )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_15 ;
V_9 -> type = type ;
V_15 = F_11 ( V_10 -> V_16 + V_17 ) ;
V_15 &= ~ ( 3 << ( V_9 -> V_13 * 2 ) ) ;
V_15 |= V_9 -> type << ( V_9 -> V_13 * 2 ) ;
F_13 ( V_15 , V_10 -> V_16 + V_17 ) ;
}
static void F_36 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_15 ;
if ( V_9 -> V_10 -> V_11 == & V_57 ) {
V_15 = F_11 ( V_10 -> V_16 + V_58 ) ;
V_15 |= 1 << V_9 -> V_13 ;
F_13 ( V_15 , V_10 -> V_16 + V_58 ) ;
}
}
static void F_37 ( struct V_8 * V_9 )
{
V_9 -> V_23 [ V_24 ] |= V_59 ;
V_9 -> V_23 [ V_27 ] |= V_59 ;
}
static int F_38 ( struct V_8 * V_9 ,
struct V_53 * V_54 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
const struct V_60 * V_11 = V_10 -> V_11 ;
T_3 V_15 , V_61 ;
F_34 ( V_9 ) ;
if ( V_11 -> V_62 )
F_35 ( V_9 , V_63 ) ;
V_9 -> V_33 = F_31 ( V_9 , V_54 ) ;
if ( ! V_9 -> V_33 ) {
F_39 ( V_9 -> V_20 . V_18 , L_3 ) ;
return - V_64 ;
}
V_15 = F_11 ( V_9 -> V_22 ) ;
F_12 ( V_10 -> V_18 , L_4 , V_15 ) ;
V_61 = V_15 & V_65 ;
if ( V_61 != V_15 ) {
F_12 ( V_10 -> V_18 ,
L_5 ,
V_61 ) ;
}
V_9 -> V_23 [ V_24 ] = V_61 ;
if ( ( V_15 & V_66 ) ==
V_67 )
V_9 -> V_23 [ V_27 ] = V_15 ;
else
V_9 -> V_23 [ V_27 ] = V_9 -> V_23 [ V_24 ] |
V_67 ;
F_12 ( V_10 -> V_18 , L_6 ,
V_9 -> V_23 [ V_27 ] ) ;
return 0 ;
}
static int F_40 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
const struct V_60 * V_11 = V_10 -> V_11 ;
T_3 V_34 ;
if ( V_9 -> V_20 . V_38 == 4 && V_11 -> V_68 )
V_11 -> V_68 ( V_9 ) ;
V_9 -> V_23 [ V_69 ] = V_9 -> V_23 [ V_24 ] |
V_9 -> V_20 . V_47 << V_70 |
V_71 ;
F_12 ( V_10 -> V_18 , L_7 ,
V_9 -> V_23 [ V_69 ] ) ;
switch ( V_9 -> V_20 . V_72 ) {
case V_73 :
V_34 = V_67 ;
break;
case V_74 :
V_34 = V_75 ;
break;
default:
F_41 ( V_9 -> V_20 . V_18 , L_8 ) ;
return - V_64 ;
}
V_9 -> V_23 [ V_27 ] |= V_34 |
F_42 ( V_9 -> V_20 . V_44 / 8 ) ;
F_12 ( V_10 -> V_18 , L_9 ,
V_9 -> V_23 [ V_27 ] ) ;
return 0 ;
}
static int F_43 ( struct V_14 * V_10 ,
struct V_76 * V_77 , struct V_53 * V_78 )
{
const struct V_60 * V_11 = V_10 -> V_11 ;
struct V_79 * V_18 = V_10 -> V_18 ;
struct V_76 * V_80 ;
unsigned int V_13 ;
int V_81 = - V_82 ;
F_44 (np, child) {
struct V_8 * V_9 ;
struct V_19 * V_20 ;
struct V_83 * V_51 ;
if ( ! F_45 ( V_80 , L_10 ) )
continue;
V_81 = F_46 ( V_80 , L_11 , & V_13 ) ;
if ( V_81 ) {
F_41 ( V_18 , L_12 ) ;
break;
}
if ( V_13 >= V_11 -> V_49 ) {
F_41 ( V_18 , L_13 ,
V_13 ) ;
V_81 = - V_84 ;
break;
}
if ( V_10 -> V_50 [ V_13 ] ) {
F_41 ( V_18 , L_14 ,
V_13 , F_47 ( V_10 -> V_50 [ V_13 ] -> V_20 . V_18 ) ) ;
V_81 = - V_85 ;
break;
}
V_9 = F_48 ( V_10 -> V_18 , sizeof( * V_9 ) , V_86 ) ;
if ( ! V_9 ) {
V_81 = - V_87 ;
break;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_22 = V_10 -> V_16 + V_11 -> V_88 + V_13 * 4 ;
V_9 -> V_13 = V_13 ;
V_20 = & V_9 -> V_20 ;
V_51 = & V_20 -> V_51 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_21 = V_9 ;
F_49 ( V_20 , V_80 ) ;
V_20 -> V_89 = F_25 ;
V_20 -> V_90 = F_26 ;
V_20 -> V_91 = F_20 ;
V_20 -> V_92 = F_21 ;
V_20 -> V_93 = F_16 ;
V_20 -> V_94 = F_18 ;
V_81 = F_38 ( V_9 , V_78 ) ;
if ( V_81 )
break;
V_81 = F_50 ( V_20 , NULL , V_73 ) ;
if ( V_81 )
break;
V_81 = F_40 ( V_9 ) ;
if ( V_81 )
break;
V_81 = F_51 ( V_51 , NULL , 0 ) ;
if ( V_81 )
break;
V_10 -> V_50 [ V_13 ] = V_9 ;
}
if ( V_81 )
F_27 ( V_10 ) ;
return V_81 ;
}
static int F_52 ( struct V_52 * V_95 )
{
struct V_76 * V_77 = V_95 -> V_18 . V_96 ;
struct V_79 * V_18 = & V_95 -> V_18 ;
struct V_14 * V_10 ;
const struct V_97 * V_98 ;
const struct V_60 * V_11 ;
struct V_53 * V_54 ;
int V_81 ;
V_98 = F_53 ( V_99 , & V_95 -> V_18 ) ;
if ( ! V_98 || ! V_98 -> V_100 )
return - V_82 ;
V_11 = V_98 -> V_100 ;
V_10 = F_48 ( & V_95 -> V_18 , sizeof( * V_10 ) +
V_11 -> V_49 * sizeof( V_10 -> V_50 [ 0 ] ) , V_86 ) ;
if ( ! V_10 )
return - V_87 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_18 = V_18 ;
F_54 ( & V_10 -> V_31 ) ;
F_55 ( V_95 , V_10 ) ;
V_54 = F_56 ( V_95 , V_101 , 0 ) ;
V_10 -> V_16 = F_57 ( V_18 , V_54 ) ;
if ( F_58 ( V_10 -> V_16 ) )
return F_59 ( V_10 -> V_16 ) ;
V_54 = F_56 ( V_95 , V_101 , 1 ) ;
V_10 -> V_33 = F_57 ( V_18 , V_54 ) ;
if ( F_58 ( V_10 -> V_33 ) )
return F_59 ( V_10 -> V_33 ) ;
V_81 = F_43 ( V_10 , V_77 , V_54 ) ;
if ( V_81 )
F_41 ( V_18 , L_15 , V_81 ) ;
return V_81 ;
}
