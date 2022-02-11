static inline const struct V_1 * F_1 (
struct V_2 * V_3 ,
const char * V_4 )
{
const struct V_1 * V_5 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = F_2 ( V_3 , V_6 ) ;
if ( V_5 && ! strcmp ( V_5 -> V_4 , V_4 ) )
break;
}
return V_5 ;
}
static void F_3 ( struct V_2 * V_3 , struct V_8 * V_9 ,
unsigned V_10 )
{
F_4 ( V_9 , L_1 , F_5 ( V_3 -> V_11 ) ) ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_12 * V_13 ,
struct V_14 * * V_15 , unsigned * V_16 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_1 * V_5 ;
struct V_14 * V_21 ;
struct V_12 * V_22 ;
int V_23 = 1 ;
int V_6 , V_24 ;
V_5 = F_1 ( V_3 , V_13 -> V_4 ) ;
if ( ! V_5 ) {
F_8 ( V_20 -> V_11 , L_2 ,
V_13 -> V_4 ) ;
return - V_25 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_26 ; V_6 ++ ) {
struct V_27 * V_28 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_6 ] ;
if ( ! ( V_28 -> V_30 & V_31 ) )
V_23 ++ ;
}
V_21 = F_9 ( sizeof( struct V_14 ) * V_23 , V_32 ) ;
if ( ! V_21 )
return - V_33 ;
* V_15 = V_21 ;
* V_16 = V_23 ;
V_22 = F_10 ( V_13 ) ;
if ( ! V_22 ) {
F_11 ( V_21 ) ;
return - V_25 ;
}
V_21 [ 0 ] . type = V_34 ;
V_21 [ 0 ] . V_29 . V_35 . V_36 = V_22 -> V_4 ;
V_21 [ 0 ] . V_29 . V_35 . V_37 = V_13 -> V_4 ;
F_12 ( V_22 ) ;
V_21 ++ ;
for ( V_6 = V_24 = 0 ; V_6 < V_5 -> V_26 ; V_6 ++ ) {
struct V_27 * V_28 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_6 ] ;
if ( ! ( V_28 -> V_30 & V_31 ) ) {
V_21 [ V_24 ] . type = V_38 ;
V_21 [ V_24 ] . V_29 . V_39 . V_40 =
F_13 ( V_3 , V_28 -> V_28 ) ;
V_21 [ V_24 ] . V_29 . V_39 . V_39 = & V_28 -> V_30 ;
V_21 [ V_24 ] . V_29 . V_39 . V_41 = 1 ;
V_24 ++ ;
}
}
F_14 ( V_3 -> V_11 , L_3 ,
( * V_15 ) -> V_29 . V_35 . V_36 , ( * V_15 ) -> V_29 . V_35 . V_37 , V_23 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_14 * V_15 , unsigned V_16 )
{
F_11 ( V_15 ) ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_42 ,
unsigned V_37 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 ;
unsigned int V_45 , V_46 ;
int V_6 ;
struct V_1 * V_5 = NULL ;
struct V_47 * V_48 = NULL ;
V_5 = F_2 ( V_3 , V_37 ) ;
if ( ! V_5 )
return - V_25 ;
V_48 = F_17 ( V_3 , V_42 ) ;
if ( ! V_48 )
return - V_25 ;
V_45 = V_5 -> V_26 ;
F_14 ( V_18 -> V_11 , L_4 ,
V_48 -> V_4 , V_5 -> V_4 ) ;
for ( V_6 = 0 ; V_6 < V_45 ; V_6 ++ ) {
struct V_27 * V_28 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_6 ] ;
V_46 = V_28 -> V_28 ;
V_44 = & V_20 -> V_49 [ V_46 ] ;
if ( V_44 -> V_50 == - 1 ) {
F_14 ( V_18 -> V_11 , L_5 ,
V_20 -> V_51 [ V_46 ] . V_4 ) ;
continue;
}
if ( V_20 -> V_52 & V_53 ) {
T_1 V_54 ;
V_54 = F_18 ( V_18 -> V_55 + V_44 -> V_50 ) ;
V_54 &= ~ V_20 -> V_56 ;
V_54 |= ( V_28 -> V_57 << V_20 -> V_58 ) ;
F_19 ( V_54 , V_18 -> V_55 + V_44 -> V_50 ) ;
F_14 ( V_18 -> V_11 , L_6 ,
V_44 -> V_50 , V_54 ) ;
} else {
F_19 ( V_28 -> V_57 , V_18 -> V_55 + V_44 -> V_50 ) ;
F_14 ( V_18 -> V_11 , L_6 ,
V_44 -> V_50 , V_28 -> V_57 ) ;
}
if ( V_28 -> V_59 >> 24 == 0xff ) {
T_1 V_60 = V_28 -> V_59 ;
T_2 V_61 = V_60 & 0xff ;
T_2 V_62 = ( V_60 >> 8 ) & 0xff ;
T_2 V_63 = ( V_60 >> 16 ) & 0xff ;
T_1 V_64 = ( ( 1 << V_62 ) - 1 ) << V_63 ;
V_60 = F_18 ( V_18 -> V_55 + V_28 -> V_65 ) ;
V_60 &= ~ V_64 ;
V_60 |= V_61 << V_63 ;
F_19 ( V_60 , V_18 -> V_55 + V_28 -> V_65 ) ;
} else if ( V_28 -> V_65 ) {
if ( V_18 -> V_66 )
F_19 ( V_28 -> V_59 , V_18 -> V_66 +
V_28 -> V_65 ) ;
else
F_19 ( V_28 -> V_59 , V_18 -> V_55 +
V_28 -> V_65 ) ;
F_14 ( V_18 -> V_11 ,
L_7 ,
V_28 -> V_65 , V_28 -> V_59 ) ;
}
}
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_67 * V_68 , unsigned V_10 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 ;
struct V_1 * V_5 ;
struct V_27 * V_27 ;
unsigned int V_28 , V_37 ;
T_1 V_54 ;
if ( ! ( V_20 -> V_52 & V_53 ) )
return 0 ;
V_44 = & V_20 -> V_49 [ V_10 ] ;
if ( V_44 -> V_50 == - 1 )
return - V_25 ;
for ( V_37 = 0 ; V_37 < V_3 -> V_7 ; V_37 ++ ) {
V_5 = F_2 ( V_3 , V_37 ) ;
if ( ! V_5 )
continue;
for ( V_28 = 0 ; V_28 < V_5 -> V_26 ; V_28 ++ ) {
V_27 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_28 ] ;
if ( V_27 -> V_28 == V_10 && ! V_27 -> V_57 )
goto V_69;
}
}
return - V_25 ;
V_69:
V_54 = F_18 ( V_18 -> V_55 + V_44 -> V_50 ) ;
V_54 &= ~ V_20 -> V_56 ;
V_54 |= V_27 -> V_30 ;
F_19 ( V_54 , V_18 -> V_55 + V_44 -> V_50 ) ;
return 0 ;
}
static void F_21 ( struct V_2 * V_3 ,
struct V_67 * V_68 , unsigned V_10 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 ;
T_1 V_54 ;
if ( ! ( V_20 -> V_52 & V_53 ) )
return;
V_44 = & V_20 -> V_49 [ V_10 ] ;
if ( V_44 -> V_50 == - 1 )
return;
V_54 = F_18 ( V_18 -> V_55 + V_44 -> V_50 ) ;
V_54 &= ~ 0x7 ;
F_19 ( V_54 , V_18 -> V_55 + V_44 -> V_50 ) ;
}
static int F_22 ( struct V_2 * V_3 ,
struct V_67 * V_68 , unsigned V_10 , bool V_70 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 ;
T_1 V_54 ;
if ( ! ( V_20 -> V_52 & V_53 ) )
return 0 ;
V_44 = & V_20 -> V_49 [ V_10 ] ;
if ( V_44 -> V_50 == - 1 )
return - V_25 ;
V_54 = F_18 ( V_18 -> V_55 + V_44 -> V_50 ) ;
if ( V_70 )
V_54 &= ~ 0x2 ;
else
V_54 |= 0x2 ;
F_19 ( V_54 , V_18 -> V_55 + V_44 -> V_50 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_17 * V_18 ,
unsigned long * V_39 ,
unsigned int V_41 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_71 * V_72 ;
enum V_73 V_74 ;
T_1 V_75 = 0 ;
T_1 V_76 ;
int V_6 , V_24 ;
F_24 ( V_41 > V_20 -> V_77 ) ;
for ( V_6 = 0 ; V_6 < V_41 ; V_6 ++ ) {
V_74 = F_25 ( V_39 [ V_6 ] ) ;
V_76 = F_26 ( V_39 [ V_6 ] ) ;
V_72 = V_20 -> V_78 ;
for ( V_24 = 0 ; V_24 < V_20 -> V_77 ; V_24 ++ ) {
if ( V_74 == V_72 -> V_74 ) {
if ( V_72 -> V_79 )
V_76 = ! V_76 ;
V_75 |= ( V_76 << V_72 -> V_63 )
& V_72 -> V_64 ;
break;
}
V_72 ++ ;
}
}
if ( V_20 -> V_80 )
V_20 -> V_80 ( V_39 , V_41 , & V_75 ) ;
return V_75 ;
}
static T_1 F_27 ( struct V_12 * V_13 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_2 * V_81 = V_18 -> V_81 ;
unsigned int V_41 ;
unsigned long * V_39 ;
int V_82 ;
if ( ! V_20 -> V_83 )
return 0 ;
V_82 = F_28 ( V_13 , V_81 , & V_39 ,
& V_41 ) ;
if ( V_82 )
return 0 ;
return F_23 ( V_18 , V_39 , V_41 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
unsigned V_46 , unsigned long * V_30 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 = & V_20 -> V_49 [ V_46 ] ;
if ( V_44 -> V_84 == - 1 ) {
F_8 ( V_20 -> V_11 , L_8 ,
V_20 -> V_51 [ V_46 ] . V_4 ) ;
return - V_25 ;
}
* V_30 = F_18 ( V_18 -> V_55 + V_44 -> V_84 ) ;
if ( V_20 -> V_52 & V_53 )
* V_30 &= ~ V_20 -> V_56 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
unsigned V_46 , unsigned long * V_39 ,
unsigned V_41 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 = & V_20 -> V_49 [ V_46 ] ;
int V_6 ;
if ( V_44 -> V_84 == - 1 ) {
F_8 ( V_20 -> V_11 , L_8 ,
V_20 -> V_51 [ V_46 ] . V_4 ) ;
return - V_25 ;
}
F_14 ( V_18 -> V_11 , L_9 ,
V_20 -> V_51 [ V_46 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_41 ; V_6 ++ ) {
if ( V_20 -> V_52 & V_53 ) {
T_1 V_54 ;
V_54 = F_18 ( V_18 -> V_55 + V_44 -> V_84 ) ;
V_54 &= V_20 -> V_56 ;
V_54 |= V_39 [ V_6 ] ;
F_19 ( V_54 , V_18 -> V_55 + V_44 -> V_84 ) ;
F_14 ( V_18 -> V_11 , L_6 ,
V_44 -> V_84 , V_54 ) ;
} else {
F_19 ( V_39 [ V_6 ] , V_18 -> V_55 + V_44 -> V_84 ) ;
F_14 ( V_18 -> V_11 , L_10 ,
V_44 -> V_84 , V_39 [ V_6 ] ) ;
}
}
return 0 ;
}
static void F_31 ( struct V_2 * V_3 ,
struct V_8 * V_9 , unsigned V_46 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 = & V_20 -> V_49 [ V_46 ] ;
unsigned long V_30 ;
if ( ! V_44 || V_44 -> V_84 == - 1 ) {
F_4 ( V_9 , L_11 ) ;
return;
}
V_30 = F_18 ( V_18 -> V_55 + V_44 -> V_84 ) ;
F_4 ( V_9 , L_12 , V_30 ) ;
}
static void F_32 ( struct V_2 * V_3 ,
struct V_8 * V_9 , unsigned V_37 )
{
struct V_1 * V_5 ;
unsigned long V_30 ;
const char * V_4 ;
int V_6 , V_82 ;
if ( V_37 > V_3 -> V_7 )
return;
F_4 ( V_9 , L_13 ) ;
V_5 = F_2 ( V_3 , V_37 ) ;
if ( ! V_5 )
return;
for ( V_6 = 0 ; V_6 < V_5 -> V_26 ; V_6 ++ ) {
struct V_27 * V_28 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_6 ] ;
V_4 = F_13 ( V_3 , V_28 -> V_28 ) ;
V_82 = F_29 ( V_3 , V_28 -> V_28 , & V_30 ) ;
if ( V_82 )
return;
F_4 ( V_9 , L_14 , V_4 , V_30 ) ;
}
}
static int F_33 ( struct V_12 * V_13 ,
struct V_1 * V_5 ,
struct V_17 * V_18 ,
T_1 V_85 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
int V_86 , V_87 ;
const T_3 * V_88 ;
int V_6 ;
T_1 V_30 ;
F_14 ( V_20 -> V_11 , L_15 , V_85 , V_13 -> V_4 ) ;
if ( V_20 -> V_52 & V_53 )
V_87 = V_89 ;
else
V_87 = V_90 ;
if ( V_20 -> V_83 )
V_87 -= 4 ;
V_5 -> V_4 = V_13 -> V_4 ;
V_88 = F_34 ( V_13 , L_16 , & V_86 ) ;
if ( ! V_88 ) {
V_88 = F_34 ( V_13 , L_17 , & V_86 ) ;
if ( ! V_88 ) {
F_8 ( V_20 -> V_11 ,
L_18 ,
V_13 -> V_91 ) ;
return - V_25 ;
}
}
if ( ! V_86 || V_86 % V_87 ) {
F_8 ( V_20 -> V_11 , L_19 ,
V_13 -> V_91 ) ;
return - V_25 ;
}
V_30 = F_27 ( V_13 , V_18 ) ;
V_5 -> V_26 = V_86 / V_87 ;
V_5 -> V_29 = F_35 ( V_20 -> V_11 , V_5 -> V_26 *
sizeof( struct V_27 ) , V_32 ) ;
V_5 -> V_51 = F_35 ( V_20 -> V_11 , V_5 -> V_26 *
sizeof( unsigned int ) , V_32 ) ;
if ( ! V_5 -> V_51 || ! V_5 -> V_29 )
return - V_33 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_26 ; V_6 ++ ) {
T_1 V_50 = F_36 ( * V_88 ++ ) ;
T_1 V_84 ;
unsigned int V_46 ;
struct V_43 * V_44 ;
struct V_27 * V_28 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_6 ] ;
if ( ! ( V_20 -> V_52 & V_92 ) && ! V_50 )
V_50 = - 1 ;
if ( V_20 -> V_52 & V_53 ) {
V_84 = V_50 ;
} else {
V_84 = F_36 ( * V_88 ++ ) ;
if ( ! V_84 )
V_84 = - 1 ;
}
V_46 = ( V_50 != - 1 ) ? V_50 / 4 : V_84 / 4 ;
V_44 = & V_20 -> V_49 [ V_46 ] ;
V_28 -> V_28 = V_46 ;
V_5 -> V_51 [ V_6 ] = V_46 ;
V_44 -> V_50 = V_50 ;
V_44 -> V_84 = V_84 ;
V_28 -> V_65 = F_36 ( * V_88 ++ ) ;
V_28 -> V_57 = F_36 ( * V_88 ++ ) ;
V_28 -> V_59 = F_36 ( * V_88 ++ ) ;
if ( V_20 -> V_83 ) {
V_28 -> V_30 = V_30 ;
} else {
V_30 = F_36 ( * V_88 ++ ) ;
if ( V_30 & V_93 )
V_28 -> V_57 |= V_94 ;
V_28 -> V_30 = V_30 & ~ V_93 ;
}
F_14 ( V_20 -> V_11 , L_20 , V_20 -> V_51 [ V_46 ] . V_4 ,
V_28 -> V_57 , V_28 -> V_30 ) ;
}
return 0 ;
}
static int F_37 ( struct V_12 * V_13 ,
struct V_17 * V_18 ,
T_1 V_85 )
{
struct V_2 * V_81 = V_18 -> V_81 ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_12 * V_95 ;
struct V_47 * V_48 ;
struct V_1 * V_5 ;
T_1 V_6 = 0 ;
F_14 ( V_20 -> V_11 , L_21 , V_85 , V_13 -> V_4 ) ;
V_48 = F_17 ( V_81 , V_85 ) ;
if ( ! V_48 )
return - V_25 ;
V_48 -> V_4 = V_13 -> V_4 ;
V_48 -> V_96 = F_38 ( V_13 ) ;
if ( V_48 -> V_96 == 0 ) {
F_8 ( V_20 -> V_11 , L_22 , V_13 -> V_91 ) ;
return - V_25 ;
}
V_48 -> V_97 = F_39 ( V_20 -> V_11 , V_48 -> V_96 ,
sizeof( char * ) , V_32 ) ;
if ( ! V_48 -> V_97 )
return - V_33 ;
F_40 (np, child) {
V_48 -> V_97 [ V_6 ] = V_95 -> V_4 ;
V_5 = F_35 ( V_20 -> V_11 , sizeof( struct V_1 ) ,
V_32 ) ;
if ( ! V_5 )
return - V_33 ;
F_41 ( & V_20 -> V_98 ) ;
F_42 ( & V_81 -> V_99 ,
V_20 -> V_100 ++ , V_5 ) ;
F_43 ( & V_20 -> V_98 ) ;
F_33 ( V_95 , V_5 , V_18 , V_6 ++ ) ;
}
return 0 ;
}
static bool F_44 ( struct V_12 * V_13 )
{
struct V_12 * V_101 ;
struct V_12 * V_102 ;
F_40 (np, function_np) {
if ( F_45 ( V_101 , L_16 ) )
return true ;
F_40 (function_np, pinctrl_np) {
if ( F_45 ( V_102 , L_16 ) )
return false ;
}
}
return true ;
}
static int F_46 ( struct V_103 * V_104 ,
struct V_17 * V_18 )
{
struct V_12 * V_13 = V_104 -> V_11 . V_105 ;
struct V_12 * V_95 ;
struct V_2 * V_81 = V_18 -> V_81 ;
struct V_19 * V_20 = V_18 -> V_20 ;
T_1 V_106 = 0 ;
T_1 V_6 = 0 ;
bool V_107 ;
if ( ! V_13 )
return - V_108 ;
V_107 = F_44 ( V_13 ) ;
if ( V_107 ) {
V_106 = 1 ;
} else {
V_106 = F_38 ( V_13 ) ;
if ( V_106 <= 0 ) {
F_8 ( & V_104 -> V_11 , L_23 ) ;
return - V_25 ;
}
}
for ( V_6 = 0 ; V_6 < V_106 ; V_6 ++ ) {
struct V_47 * V_36 ;
V_36 = F_35 ( & V_104 -> V_11 , sizeof( * V_36 ) ,
V_32 ) ;
if ( ! V_36 )
return - V_33 ;
F_41 ( & V_20 -> V_98 ) ;
F_42 ( & V_81 -> V_109 , V_6 , V_36 ) ;
F_43 ( & V_20 -> V_98 ) ;
}
V_81 -> V_110 = V_106 ;
V_20 -> V_100 = 0 ;
if ( V_107 ) {
V_81 -> V_7 = F_38 ( V_13 ) ;
} else {
V_81 -> V_7 = 0 ;
F_40 (np, child)
V_81 -> V_7 += F_38 ( V_95 ) ;
}
if ( V_107 ) {
F_37 ( V_13 , V_18 , 0 ) ;
} else {
V_6 = 0 ;
F_40 (np, child)
F_37 ( V_95 , V_18 , V_6 ++ ) ;
}
return 0 ;
}
static void F_47 ( struct V_17 * V_18 )
{
if ( V_18 -> V_81 )
F_48 ( V_18 -> V_81 ) ;
}
int F_49 ( struct V_103 * V_104 ,
struct V_19 * V_20 )
{
struct V_111 V_30 = { . V_4 = L_24 } ;
struct V_12 * V_112 = V_104 -> V_11 . V_105 ;
struct V_113 * V_114 ;
struct V_12 * V_13 ;
struct V_17 * V_18 ;
struct V_115 * V_116 ;
struct V_117 * V_118 ;
int V_82 , V_6 ;
if ( ! V_20 || ! V_20 -> V_51 || ! V_20 -> V_45 ) {
F_8 ( & V_104 -> V_11 , L_25 ) ;
return - V_25 ;
}
V_20 -> V_11 = & V_104 -> V_11 ;
if ( V_20 -> V_119 ) {
V_118 = F_50 ( V_20 -> V_119 ) ;
if ( ! F_51 ( V_118 ) )
F_52 ( & V_104 -> V_11 , V_118 , & V_30 ) ;
}
V_18 = F_35 ( & V_104 -> V_11 , sizeof( * V_18 ) , V_32 ) ;
if ( ! V_18 )
return - V_33 ;
V_20 -> V_49 = F_53 ( & V_104 -> V_11 , sizeof( * V_20 -> V_49 ) *
V_20 -> V_45 , V_32 ) ;
if ( ! V_20 -> V_49 )
return - V_33 ;
for ( V_6 = 0 ; V_6 < V_20 -> V_45 ; V_6 ++ ) {
V_20 -> V_49 [ V_6 ] . V_50 = - 1 ;
V_20 -> V_49 [ V_6 ] . V_84 = - 1 ;
}
V_116 = F_54 ( V_104 , V_120 , 0 ) ;
V_18 -> V_55 = F_55 ( & V_104 -> V_11 , V_116 ) ;
if ( F_51 ( V_18 -> V_55 ) )
return F_56 ( V_18 -> V_55 ) ;
if ( F_45 ( V_112 , L_26 ) ) {
V_13 = F_57 ( V_112 , L_26 , 0 ) ;
if ( ! V_13 ) {
F_8 ( & V_104 -> V_11 , L_27 ) ;
return - V_25 ;
}
V_18 -> V_66 = F_58 ( V_13 , 0 ) ;
F_12 ( V_13 ) ;
if ( ! V_18 -> V_66 ) {
F_8 ( & V_104 -> V_11 ,
L_28 ) ;
return - V_33 ;
}
}
V_114 = F_35 ( & V_104 -> V_11 , sizeof( * V_114 ) ,
V_32 ) ;
if ( ! V_114 )
return - V_33 ;
V_114 -> V_4 = F_5 ( & V_104 -> V_11 ) ;
V_114 -> V_51 = V_20 -> V_51 ;
V_114 -> V_45 = V_20 -> V_45 ;
V_114 -> V_121 = & V_122 ;
V_114 -> V_123 = & V_124 ;
V_114 -> V_125 = & V_126 ;
V_114 -> V_127 = V_128 ;
V_114 -> V_129 = V_20 -> V_129 ;
V_114 -> V_130 = V_20 -> V_130 ;
F_59 ( & V_20 -> V_98 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_11 = V_20 -> V_11 ;
F_60 ( V_104 , V_18 ) ;
V_82 = F_61 ( & V_104 -> V_11 ,
V_114 , V_18 ,
& V_18 -> V_81 ) ;
if ( V_82 ) {
F_8 ( & V_104 -> V_11 , L_29 ) ;
goto free;
}
V_82 = F_46 ( V_104 , V_18 ) ;
if ( V_82 ) {
F_8 ( & V_104 -> V_11 , L_30 ) ;
goto free;
}
F_62 ( & V_104 -> V_11 , L_31 ) ;
return F_63 ( V_18 -> V_81 ) ;
free:
F_47 ( V_18 ) ;
return V_82 ;
}
