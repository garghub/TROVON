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
V_15 = F_11 ( F_32 ( V_10 , V_9 -> V_13 ) ) ;
if ( F_33 ( V_15 ) >= F_34 ( V_15 ) )
return NULL ;
V_4 = F_33 ( V_15 ) - V_54 -> V_55 ;
}
return V_10 -> V_33 + V_4 ;
}
static T_3 F_35 ( struct V_14 * V_10 )
{
T_3 V_56 = F_11 ( F_32 ( V_10 , 0 ) ) ;
return F_33 ( V_56 ) ;
}
static T_3 F_36 ( struct V_8 * V_9 , T_3 V_13 , T_3 V_55 ,
T_3 V_57 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
void T_1 * V_58 ;
T_3 V_59 , V_60 , V_61 , V_62 ;
V_61 = F_35 ( V_10 ) ;
V_58 = F_32 ( V_10 , V_13 ) ;
V_59 = F_11 ( V_58 ) ;
if ( ! V_57 )
V_57 = F_34 ( V_59 ) - V_55 ;
if ( V_55 + V_57 > V_61 + V_10 -> V_63 ) {
V_57 = V_61 + V_10 -> V_63 - V_55 ;
F_37 ( V_9 -> V_20 . V_18 , L_3 ,
V_13 , V_57 >> 20 ) ;
}
V_62 = V_55 + V_57 ;
V_60 = F_38 ( V_55 , V_62 ) ;
F_13 ( V_60 , V_58 ) ;
if ( V_60 != F_11 ( V_58 ) ) {
F_39 ( V_9 -> V_20 . V_18 , L_4 , V_13 ) ;
F_13 ( V_59 , V_58 ) ;
V_55 = F_33 ( V_59 ) ;
V_62 = F_34 ( V_59 ) ;
V_57 = V_62 - V_55 ;
}
F_40 ( V_9 -> V_20 . V_18 , L_5 ,
V_13 , V_55 , V_62 , V_57 >> 20 ) ;
return V_57 ;
}
static T_3 F_41 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_61 , V_55 ;
T_3 V_57 = V_9 -> V_20 . V_51 . V_57 ;
if ( V_57 > V_10 -> V_11 -> V_64 )
V_57 = V_10 -> V_11 -> V_64 ;
if ( V_10 -> V_11 == & V_65 )
goto V_66;
if ( V_9 -> V_13 == 0 && V_10 -> V_11 == & V_67 &&
V_57 == V_68 ) {
V_57 = 120 << 20 ;
F_40 ( V_9 -> V_20 . V_18 ,
L_6 ,
V_9 -> V_13 , V_57 >> 20 ) ;
}
V_61 = F_35 ( V_10 ) ;
if ( V_9 -> V_13 ) {
T_3 V_69 = F_11 ( F_32 ( V_10 , V_9 -> V_13 - 1 ) ) ;
V_55 = F_34 ( V_69 ) ;
} else {
V_55 = V_61 ;
}
V_57 = F_36 ( V_9 , V_9 -> V_13 , V_55 , V_57 ) ;
V_9 -> V_33 = V_10 -> V_33 + ( V_55 - V_61 ) ;
if ( V_9 -> V_13 < V_10 -> V_11 -> V_49 - 1 )
F_36 ( V_9 , V_9 -> V_13 + 1 , V_55 + V_57 , 0 ) ;
V_66:
if ( V_57 < V_9 -> V_20 . V_51 . V_57 )
F_37 ( V_9 -> V_20 . V_18 ,
L_7 ,
V_9 -> V_13 , ( T_3 ) V_9 -> V_20 . V_51 . V_57 >> 20 ) ;
return V_57 ;
}
static void F_42 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_15 ;
V_15 = F_11 ( V_10 -> V_16 + V_17 ) ;
V_15 |= F_8 ( V_9 ) ;
F_13 ( V_15 , V_10 -> V_16 + V_17 ) ;
}
static void F_43 ( struct V_8 * V_9 , int type )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_15 ;
V_9 -> type = type ;
V_15 = F_11 ( V_10 -> V_16 + V_17 ) ;
V_15 &= ~ ( 3 << ( V_9 -> V_13 * 2 ) ) ;
V_15 |= V_9 -> type << ( V_9 -> V_13 * 2 ) ;
F_13 ( V_15 , V_10 -> V_16 + V_17 ) ;
}
static void F_44 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
T_3 V_15 ;
if ( V_9 -> V_10 -> V_11 == & V_67 ) {
V_15 = F_11 ( V_10 -> V_16 + V_70 ) ;
V_15 |= 1 << V_9 -> V_13 ;
F_13 ( V_15 , V_10 -> V_16 + V_70 ) ;
}
}
static void F_45 ( struct V_8 * V_9 )
{
V_9 -> V_23 [ V_24 ] |= V_71 ;
V_9 -> V_23 [ V_27 ] |= V_71 ;
}
static int F_46 ( struct V_8 * V_9 ,
struct V_53 * V_54 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
const struct V_72 * V_11 = V_10 -> V_11 ;
T_3 V_15 , V_73 ;
F_42 ( V_9 ) ;
if ( V_11 -> V_74 )
F_43 ( V_9 , V_75 ) ;
V_9 -> V_33 = F_31 ( V_9 , V_54 ) ;
if ( ! V_9 -> V_33 ) {
F_37 ( V_9 -> V_20 . V_18 , L_8 , V_9 -> V_13 ) ;
return - V_76 ;
}
V_15 = F_11 ( V_9 -> V_22 ) ;
F_12 ( V_10 -> V_18 , L_9 , V_15 ) ;
V_73 = V_15 & V_77 ;
if ( V_73 != V_15 ) {
F_12 ( V_10 -> V_18 ,
L_10 ,
V_73 ) ;
}
V_9 -> V_23 [ V_24 ] = V_73 ;
if ( ( V_15 & V_78 ) ==
V_79 )
V_9 -> V_23 [ V_27 ] = V_15 ;
else
V_9 -> V_23 [ V_27 ] = V_9 -> V_23 [ V_24 ] |
V_79 ;
F_12 ( V_10 -> V_18 , L_11 ,
V_9 -> V_23 [ V_27 ] ) ;
return 0 ;
}
static int F_47 ( struct V_8 * V_9 )
{
struct V_14 * V_10 = V_9 -> V_10 ;
const struct V_72 * V_11 = V_10 -> V_11 ;
T_3 V_34 ;
if ( V_9 -> V_20 . V_38 == 4 && V_11 -> V_80 )
V_11 -> V_80 ( V_9 ) ;
V_9 -> V_63 = F_41 ( V_9 ) ;
V_9 -> V_23 [ V_81 ] = V_9 -> V_23 [ V_24 ] |
V_9 -> V_20 . V_47 << V_82 |
V_83 ;
F_12 ( V_10 -> V_18 , L_12 ,
V_9 -> V_23 [ V_81 ] ) ;
if ( V_9 -> V_20 . V_84 == V_85 ) {
if ( V_9 -> V_20 . V_44 == 0 )
V_34 = V_79 ;
else
V_34 = V_86 ;
} else {
F_39 ( V_9 -> V_20 . V_18 , L_13 ) ;
return - V_76 ;
}
V_9 -> V_23 [ V_27 ] |= V_34 |
F_48 ( V_9 -> V_20 . V_44 / 8 ) ;
F_12 ( V_10 -> V_18 , L_14 ,
V_9 -> V_23 [ V_27 ] ) ;
return 0 ;
}
static int F_49 ( struct V_14 * V_10 ,
struct V_87 * V_88 , struct V_53 * V_89 )
{
const struct V_90 V_91 = {
. V_92 = V_93 |
V_94 |
V_95 ,
} ;
const struct V_72 * V_11 = V_10 -> V_11 ;
struct V_96 * V_18 = V_10 -> V_18 ;
struct V_87 * V_97 ;
unsigned int V_13 ;
int V_98 = - V_99 ;
F_50 (np, child) {
struct V_8 * V_9 ;
struct V_19 * V_20 ;
struct V_100 * V_51 ;
if ( ! F_51 ( V_97 , L_15 ) )
continue;
V_98 = F_52 ( V_97 , L_16 , & V_13 ) ;
if ( V_98 ) {
F_39 ( V_18 , L_17 ) ;
break;
}
if ( V_13 >= V_11 -> V_49 ) {
F_39 ( V_18 , L_18 ,
V_13 ) ;
V_98 = - V_101 ;
break;
}
if ( V_10 -> V_50 [ V_13 ] ) {
F_39 ( V_18 , L_19 ,
V_13 , F_53 ( V_10 -> V_50 [ V_13 ] -> V_20 . V_18 ) ) ;
V_98 = - V_102 ;
break;
}
V_9 = F_54 ( V_10 -> V_18 , sizeof( * V_9 ) , V_103 ) ;
if ( ! V_9 ) {
V_98 = - V_104 ;
break;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_22 = V_10 -> V_16 + V_11 -> V_105 + V_13 * 4 ;
V_9 -> V_13 = V_13 ;
V_20 = & V_9 -> V_20 ;
V_51 = & V_20 -> V_51 ;
V_20 -> V_18 = V_18 ;
V_20 -> V_21 = V_9 ;
F_55 ( V_20 , V_97 ) ;
V_20 -> V_106 = F_25 ;
V_20 -> V_107 = F_26 ;
V_20 -> V_108 = F_20 ;
V_20 -> V_109 = F_21 ;
V_20 -> V_110 = F_16 ;
V_20 -> V_111 = F_18 ;
V_98 = F_46 ( V_9 , V_89 ) ;
if ( V_98 )
break;
V_98 = F_56 ( V_20 , NULL , & V_91 ) ;
if ( V_98 )
break;
V_98 = F_47 ( V_9 ) ;
if ( V_98 )
break;
V_98 = F_57 ( V_51 , NULL , 0 ) ;
if ( V_98 )
break;
V_10 -> V_50 [ V_13 ] = V_9 ;
}
if ( V_98 )
F_27 ( V_10 ) ;
return V_98 ;
}
static int F_58 ( struct V_52 * V_112 )
{
struct V_87 * V_88 = V_112 -> V_18 . V_113 ;
struct V_96 * V_18 = & V_112 -> V_18 ;
struct V_14 * V_10 ;
const struct V_114 * V_115 ;
const struct V_72 * V_11 ;
struct V_53 * V_54 ;
int V_98 ;
V_115 = F_59 ( V_116 , & V_112 -> V_18 ) ;
if ( ! V_115 || ! V_115 -> V_117 )
return - V_99 ;
V_11 = V_115 -> V_117 ;
V_10 = F_54 ( & V_112 -> V_18 , sizeof( * V_10 ) +
V_11 -> V_49 * sizeof( V_10 -> V_50 [ 0 ] ) , V_103 ) ;
if ( ! V_10 )
return - V_104 ;
V_10 -> V_11 = V_11 ;
V_10 -> V_18 = V_18 ;
F_60 ( & V_10 -> V_31 ) ;
F_61 ( V_112 , V_10 ) ;
V_54 = F_62 ( V_112 , V_118 , 0 ) ;
V_10 -> V_16 = F_63 ( V_18 , V_54 ) ;
if ( F_64 ( V_10 -> V_16 ) )
return F_65 ( V_10 -> V_16 ) ;
V_54 = F_62 ( V_112 , V_118 , 1 ) ;
V_10 -> V_33 = F_63 ( V_18 , V_54 ) ;
if ( F_64 ( V_10 -> V_33 ) )
return F_65 ( V_10 -> V_33 ) ;
V_10 -> V_63 = F_66 ( V_54 ) ;
V_98 = F_49 ( V_10 , V_88 , V_54 ) ;
if ( V_98 )
F_39 ( V_18 , L_20 , V_98 ) ;
return V_98 ;
}
