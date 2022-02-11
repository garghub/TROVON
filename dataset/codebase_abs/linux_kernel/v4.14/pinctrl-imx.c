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
static T_1 F_20 ( struct V_17 * V_18 ,
unsigned long * V_39 ,
unsigned int V_41 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_67 * V_68 ;
enum V_69 V_70 ;
T_1 V_71 = 0 ;
T_1 V_72 ;
int V_6 , V_24 ;
F_21 ( V_41 > V_20 -> V_73 ) ;
for ( V_6 = 0 ; V_6 < V_41 ; V_6 ++ ) {
V_70 = F_22 ( V_39 [ V_6 ] ) ;
V_72 = F_23 ( V_39 [ V_6 ] ) ;
V_68 = V_20 -> V_74 ;
for ( V_24 = 0 ; V_24 < V_20 -> V_73 ; V_24 ++ ) {
if ( V_70 == V_68 -> V_70 ) {
if ( V_68 -> V_75 )
V_72 = ! V_72 ;
V_71 |= ( V_72 << V_68 -> V_63 )
& V_68 -> V_64 ;
break;
}
V_68 ++ ;
}
}
if ( V_20 -> V_76 )
V_20 -> V_76 ( V_39 , V_41 , & V_71 ) ;
return V_71 ;
}
static T_1 F_24 ( struct V_12 * V_13 ,
struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_2 * V_77 = V_18 -> V_77 ;
unsigned int V_41 ;
unsigned long * V_39 ;
int V_78 ;
if ( ! V_20 -> V_79 )
return 0 ;
V_78 = F_25 ( V_13 , V_77 , & V_39 ,
& V_41 ) ;
if ( V_78 )
return 0 ;
return F_20 ( V_18 , V_39 , V_41 ) ;
}
static int F_26 ( struct V_2 * V_3 ,
unsigned V_46 , unsigned long * V_30 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 = & V_20 -> V_49 [ V_46 ] ;
if ( V_44 -> V_80 == - 1 ) {
F_8 ( V_20 -> V_11 , L_8 ,
V_20 -> V_51 [ V_46 ] . V_4 ) ;
return - V_25 ;
}
* V_30 = F_18 ( V_18 -> V_55 + V_44 -> V_80 ) ;
if ( V_20 -> V_52 & V_53 )
* V_30 &= ~ V_20 -> V_56 ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 ,
unsigned V_46 , unsigned long * V_39 ,
unsigned V_41 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 = & V_20 -> V_49 [ V_46 ] ;
int V_6 ;
if ( V_44 -> V_80 == - 1 ) {
F_8 ( V_20 -> V_11 , L_8 ,
V_20 -> V_51 [ V_46 ] . V_4 ) ;
return - V_25 ;
}
F_14 ( V_18 -> V_11 , L_9 ,
V_20 -> V_51 [ V_46 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_41 ; V_6 ++ ) {
if ( V_20 -> V_52 & V_53 ) {
T_1 V_54 ;
V_54 = F_18 ( V_18 -> V_55 + V_44 -> V_80 ) ;
V_54 &= V_20 -> V_56 ;
V_54 |= V_39 [ V_6 ] ;
F_19 ( V_54 , V_18 -> V_55 + V_44 -> V_80 ) ;
F_14 ( V_18 -> V_11 , L_6 ,
V_44 -> V_80 , V_54 ) ;
} else {
F_19 ( V_39 [ V_6 ] , V_18 -> V_55 + V_44 -> V_80 ) ;
F_14 ( V_18 -> V_11 , L_10 ,
V_44 -> V_80 , V_39 [ V_6 ] ) ;
}
}
return 0 ;
}
static void F_28 ( struct V_2 * V_3 ,
struct V_8 * V_9 , unsigned V_46 )
{
struct V_17 * V_18 = F_7 ( V_3 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
const struct V_43 * V_44 = & V_20 -> V_49 [ V_46 ] ;
unsigned long V_30 ;
if ( ! V_44 || V_44 -> V_80 == - 1 ) {
F_4 ( V_9 , L_11 ) ;
return;
}
V_30 = F_18 ( V_18 -> V_55 + V_44 -> V_80 ) ;
F_4 ( V_9 , L_12 , V_30 ) ;
}
static void F_29 ( struct V_2 * V_3 ,
struct V_8 * V_9 , unsigned V_37 )
{
struct V_1 * V_5 ;
unsigned long V_30 ;
const char * V_4 ;
int V_6 , V_78 ;
if ( V_37 > V_3 -> V_7 )
return;
F_4 ( V_9 , L_13 ) ;
V_5 = F_2 ( V_3 , V_37 ) ;
if ( ! V_5 )
return;
for ( V_6 = 0 ; V_6 < V_5 -> V_26 ; V_6 ++ ) {
struct V_27 * V_28 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_6 ] ;
V_4 = F_13 ( V_3 , V_28 -> V_28 ) ;
V_78 = F_26 ( V_3 , V_28 -> V_28 , & V_30 ) ;
if ( V_78 )
return;
F_4 ( V_9 , L_14 , V_4 , V_30 ) ;
}
}
static int F_30 ( struct V_12 * V_13 ,
struct V_1 * V_5 ,
struct V_17 * V_18 ,
T_1 V_81 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
int V_82 , V_83 ;
const T_3 * V_84 ;
int V_6 ;
T_1 V_30 ;
F_14 ( V_20 -> V_11 , L_15 , V_81 , V_13 -> V_4 ) ;
if ( V_20 -> V_52 & V_53 )
V_83 = V_85 ;
else
V_83 = V_86 ;
if ( V_20 -> V_79 )
V_83 -= 4 ;
V_5 -> V_4 = V_13 -> V_4 ;
V_84 = F_31 ( V_13 , L_16 , & V_82 ) ;
if ( ! V_84 ) {
V_84 = F_31 ( V_13 , L_17 , & V_82 ) ;
if ( ! V_84 ) {
F_8 ( V_20 -> V_11 ,
L_18 , V_13 ) ;
return - V_25 ;
}
}
if ( ! V_82 || V_82 % V_83 ) {
F_8 ( V_20 -> V_11 , L_19 , V_13 ) ;
return - V_25 ;
}
V_30 = F_24 ( V_13 , V_18 ) ;
V_5 -> V_26 = V_82 / V_83 ;
V_5 -> V_29 = F_32 ( V_20 -> V_11 , V_5 -> V_26 *
sizeof( struct V_27 ) , V_32 ) ;
V_5 -> V_51 = F_32 ( V_20 -> V_11 , V_5 -> V_26 *
sizeof( unsigned int ) , V_32 ) ;
if ( ! V_5 -> V_51 || ! V_5 -> V_29 )
return - V_33 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_26 ; V_6 ++ ) {
T_1 V_50 = F_33 ( * V_84 ++ ) ;
T_1 V_80 ;
unsigned int V_46 ;
struct V_43 * V_44 ;
struct V_27 * V_28 = & ( (struct V_27 * ) ( V_5 -> V_29 ) ) [ V_6 ] ;
if ( ! ( V_20 -> V_52 & V_87 ) && ! V_50 )
V_50 = - 1 ;
if ( V_20 -> V_52 & V_53 ) {
V_80 = V_50 ;
} else {
V_80 = F_33 ( * V_84 ++ ) ;
if ( ! V_80 )
V_80 = - 1 ;
}
V_46 = ( V_50 != - 1 ) ? V_50 / 4 : V_80 / 4 ;
V_44 = & V_20 -> V_49 [ V_46 ] ;
V_28 -> V_28 = V_46 ;
V_5 -> V_51 [ V_6 ] = V_46 ;
V_44 -> V_50 = V_50 ;
V_44 -> V_80 = V_80 ;
V_28 -> V_65 = F_33 ( * V_84 ++ ) ;
V_28 -> V_57 = F_33 ( * V_84 ++ ) ;
V_28 -> V_59 = F_33 ( * V_84 ++ ) ;
if ( V_20 -> V_79 ) {
V_28 -> V_30 = V_30 ;
} else {
V_30 = F_33 ( * V_84 ++ ) ;
if ( V_30 & V_88 )
V_28 -> V_57 |= V_89 ;
V_28 -> V_30 = V_30 & ~ V_88 ;
}
F_14 ( V_20 -> V_11 , L_20 , V_20 -> V_51 [ V_46 ] . V_4 ,
V_28 -> V_57 , V_28 -> V_30 ) ;
}
return 0 ;
}
static int F_34 ( struct V_12 * V_13 ,
struct V_17 * V_18 ,
T_1 V_81 )
{
struct V_2 * V_77 = V_18 -> V_77 ;
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_12 * V_90 ;
struct V_47 * V_48 ;
struct V_1 * V_5 ;
T_1 V_6 = 0 ;
F_14 ( V_20 -> V_11 , L_21 , V_81 , V_13 -> V_4 ) ;
V_48 = F_17 ( V_77 , V_81 ) ;
if ( ! V_48 )
return - V_25 ;
V_48 -> V_4 = V_13 -> V_4 ;
V_48 -> V_91 = F_35 ( V_13 ) ;
if ( V_48 -> V_91 == 0 ) {
F_8 ( V_20 -> V_11 , L_22 , V_13 ) ;
return - V_25 ;
}
V_48 -> V_92 = F_36 ( V_20 -> V_11 , V_48 -> V_91 ,
sizeof( char * ) , V_32 ) ;
if ( ! V_48 -> V_92 )
return - V_33 ;
F_37 (np, child) {
V_48 -> V_92 [ V_6 ] = V_90 -> V_4 ;
V_5 = F_32 ( V_20 -> V_11 , sizeof( struct V_1 ) ,
V_32 ) ;
if ( ! V_5 )
return - V_33 ;
F_38 ( & V_20 -> V_93 ) ;
F_39 ( & V_77 -> V_94 ,
V_20 -> V_95 ++ , V_5 ) ;
F_40 ( & V_20 -> V_93 ) ;
F_30 ( V_90 , V_5 , V_18 , V_6 ++ ) ;
}
return 0 ;
}
static bool F_41 ( struct V_12 * V_13 )
{
struct V_12 * V_96 ;
struct V_12 * V_97 ;
F_37 (np, function_np) {
if ( F_42 ( V_96 , L_16 ) )
return true ;
F_37 (function_np, pinctrl_np) {
if ( F_42 ( V_97 , L_16 ) )
return false ;
}
}
return true ;
}
static int F_43 ( struct V_98 * V_99 ,
struct V_17 * V_18 )
{
struct V_12 * V_13 = V_99 -> V_11 . V_100 ;
struct V_12 * V_90 ;
struct V_2 * V_77 = V_18 -> V_77 ;
struct V_19 * V_20 = V_18 -> V_20 ;
T_1 V_101 = 0 ;
T_1 V_6 = 0 ;
bool V_102 ;
if ( ! V_13 )
return - V_103 ;
V_102 = F_41 ( V_13 ) ;
if ( V_102 ) {
V_101 = 1 ;
} else {
V_101 = F_35 ( V_13 ) ;
if ( V_101 <= 0 ) {
F_8 ( & V_99 -> V_11 , L_23 ) ;
return - V_25 ;
}
}
for ( V_6 = 0 ; V_6 < V_101 ; V_6 ++ ) {
struct V_47 * V_36 ;
V_36 = F_32 ( & V_99 -> V_11 , sizeof( * V_36 ) ,
V_32 ) ;
if ( ! V_36 )
return - V_33 ;
F_38 ( & V_20 -> V_93 ) ;
F_39 ( & V_77 -> V_104 , V_6 , V_36 ) ;
F_40 ( & V_20 -> V_93 ) ;
}
V_77 -> V_105 = V_101 ;
V_20 -> V_95 = 0 ;
if ( V_102 ) {
V_77 -> V_7 = F_35 ( V_13 ) ;
} else {
V_77 -> V_7 = 0 ;
F_37 (np, child)
V_77 -> V_7 += F_35 ( V_90 ) ;
}
if ( V_102 ) {
F_34 ( V_13 , V_18 , 0 ) ;
} else {
V_6 = 0 ;
F_37 (np, child)
F_34 ( V_90 , V_18 , V_6 ++ ) ;
}
return 0 ;
}
static void F_44 ( struct V_17 * V_18 )
{
if ( V_18 -> V_77 )
F_45 ( V_18 -> V_77 ) ;
}
int F_46 ( struct V_98 * V_99 ,
struct V_19 * V_20 )
{
struct V_106 V_30 = { . V_4 = L_24 } ;
struct V_12 * V_107 = V_99 -> V_11 . V_100 ;
struct V_108 * V_109 ;
struct V_12 * V_13 ;
struct V_17 * V_18 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
int V_78 , V_6 ;
if ( ! V_20 || ! V_20 -> V_51 || ! V_20 -> V_45 ) {
F_8 ( & V_99 -> V_11 , L_25 ) ;
return - V_25 ;
}
V_20 -> V_11 = & V_99 -> V_11 ;
if ( V_20 -> V_114 ) {
V_113 = F_47 ( V_20 -> V_114 ) ;
if ( ! F_48 ( V_113 ) )
F_49 ( & V_99 -> V_11 , V_113 , & V_30 ) ;
}
V_18 = F_32 ( & V_99 -> V_11 , sizeof( * V_18 ) , V_32 ) ;
if ( ! V_18 )
return - V_33 ;
V_20 -> V_49 = F_50 ( & V_99 -> V_11 , sizeof( * V_20 -> V_49 ) *
V_20 -> V_45 , V_32 ) ;
if ( ! V_20 -> V_49 )
return - V_33 ;
for ( V_6 = 0 ; V_6 < V_20 -> V_45 ; V_6 ++ ) {
V_20 -> V_49 [ V_6 ] . V_50 = - 1 ;
V_20 -> V_49 [ V_6 ] . V_80 = - 1 ;
}
V_111 = F_51 ( V_99 , V_115 , 0 ) ;
V_18 -> V_55 = F_52 ( & V_99 -> V_11 , V_111 ) ;
if ( F_48 ( V_18 -> V_55 ) )
return F_53 ( V_18 -> V_55 ) ;
if ( F_42 ( V_107 , L_26 ) ) {
V_13 = F_54 ( V_107 , L_26 , 0 ) ;
if ( ! V_13 ) {
F_8 ( & V_99 -> V_11 , L_27 ) ;
return - V_25 ;
}
V_18 -> V_66 = F_55 ( V_13 , 0 ) ;
F_12 ( V_13 ) ;
if ( ! V_18 -> V_66 ) {
F_8 ( & V_99 -> V_11 ,
L_28 ) ;
return - V_33 ;
}
}
V_109 = F_32 ( & V_99 -> V_11 , sizeof( * V_109 ) ,
V_32 ) ;
if ( ! V_109 )
return - V_33 ;
V_109 -> V_4 = F_5 ( & V_99 -> V_11 ) ;
V_109 -> V_51 = V_20 -> V_51 ;
V_109 -> V_45 = V_20 -> V_45 ;
V_109 -> V_116 = & V_117 ;
V_109 -> V_118 = & V_119 ;
V_109 -> V_120 = & V_121 ;
V_109 -> V_122 = V_123 ;
V_109 -> V_124 = V_20 -> V_124 ;
V_109 -> V_125 = V_20 -> V_125 ;
V_119 . V_126 = V_20 -> V_126 ;
F_56 ( & V_20 -> V_93 ) ;
V_18 -> V_20 = V_20 ;
V_18 -> V_11 = V_20 -> V_11 ;
F_57 ( V_99 , V_18 ) ;
V_78 = F_58 ( & V_99 -> V_11 ,
V_109 , V_18 ,
& V_18 -> V_77 ) ;
if ( V_78 ) {
F_8 ( & V_99 -> V_11 , L_29 ) ;
goto free;
}
V_78 = F_43 ( V_99 , V_18 ) ;
if ( V_78 ) {
F_8 ( & V_99 -> V_11 , L_30 ) ;
goto free;
}
F_59 ( & V_99 -> V_11 , L_31 ) ;
return F_60 ( V_18 -> V_77 ) ;
free:
F_44 ( V_18 ) ;
return V_78 ;
}
