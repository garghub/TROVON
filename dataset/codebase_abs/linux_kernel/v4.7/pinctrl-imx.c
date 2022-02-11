static const inline struct V_1 * F_1 (
const struct V_2 * V_3 ,
const char * V_4 )
{
const struct V_1 * V_5 = NULL ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
if ( ! strcmp ( V_3 -> V_8 [ V_6 ] . V_4 , V_4 ) ) {
V_5 = & V_3 -> V_8 [ V_6 ] ;
break;
}
}
return V_5 ;
}
static int F_2 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_7 ;
}
static const char * F_4 ( struct V_9 * V_10 ,
unsigned V_13 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_8 [ V_13 ] . V_4 ;
}
static int F_5 ( struct V_9 * V_10 , unsigned V_13 ,
const unsigned * * V_14 ,
unsigned * V_15 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
if ( V_13 >= V_3 -> V_7 )
return - V_16 ;
* V_14 = V_3 -> V_8 [ V_13 ] . V_17 ;
* V_15 = V_3 -> V_8 [ V_13 ] . V_15 ;
return 0 ;
}
static void F_6 ( struct V_9 * V_10 , struct V_18 * V_19 ,
unsigned V_20 )
{
F_7 ( V_19 , L_1 , F_8 ( V_10 -> V_21 ) ) ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_22 * V_23 ,
struct V_24 * * V_25 , unsigned * V_26 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_1 * V_5 ;
struct V_24 * V_27 ;
struct V_22 * V_28 ;
int V_29 = 1 ;
int V_6 , V_30 ;
V_5 = F_1 ( V_3 , V_23 -> V_4 ) ;
if ( ! V_5 ) {
F_10 ( V_3 -> V_21 , L_2 ,
V_23 -> V_4 ) ;
return - V_16 ;
}
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
if ( ! ( V_5 -> V_14 [ V_6 ] . V_31 & V_32 ) )
V_29 ++ ;
}
V_27 = F_11 ( sizeof( struct V_24 ) * V_29 , V_33 ) ;
if ( ! V_27 )
return - V_34 ;
* V_25 = V_27 ;
* V_26 = V_29 ;
V_28 = F_12 ( V_23 ) ;
if ( ! V_28 ) {
F_13 ( V_27 ) ;
return - V_16 ;
}
V_27 [ 0 ] . type = V_35 ;
V_27 [ 0 ] . V_36 . V_37 . V_38 = V_28 -> V_4 ;
V_27 [ 0 ] . V_36 . V_37 . V_39 = V_23 -> V_4 ;
F_14 ( V_28 ) ;
V_27 ++ ;
for ( V_6 = V_30 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
if ( ! ( V_5 -> V_14 [ V_6 ] . V_31 & V_32 ) ) {
V_27 [ V_30 ] . type = V_40 ;
V_27 [ V_30 ] . V_36 . V_41 . V_42 =
F_15 ( V_10 , V_5 -> V_14 [ V_6 ] . V_43 ) ;
V_27 [ V_30 ] . V_36 . V_41 . V_41 = & V_5 -> V_14 [ V_6 ] . V_31 ;
V_27 [ V_30 ] . V_36 . V_41 . V_44 = 1 ;
V_30 ++ ;
}
}
F_16 ( V_10 -> V_21 , L_3 ,
( * V_25 ) -> V_36 . V_37 . V_38 , ( * V_25 ) -> V_36 . V_37 . V_39 , V_29 ) ;
return 0 ;
}
static void F_17 ( struct V_9 * V_10 ,
struct V_24 * V_25 , unsigned V_26 )
{
F_13 ( V_25 ) ;
}
static int F_18 ( struct V_9 * V_10 , unsigned V_13 ,
unsigned V_39 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_45 * V_46 ;
unsigned int V_15 , V_47 ;
int V_6 ;
struct V_1 * V_5 ;
V_5 = & V_3 -> V_8 [ V_39 ] ;
V_15 = V_5 -> V_15 ;
F_16 ( V_12 -> V_21 , L_4 ,
V_3 -> V_48 [ V_13 ] . V_4 , V_5 -> V_4 ) ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
struct V_49 * V_43 = & V_5 -> V_14 [ V_6 ] ;
V_47 = V_43 -> V_43 ;
V_46 = & V_3 -> V_50 [ V_47 ] ;
if ( V_46 -> V_51 == - 1 ) {
F_16 ( V_12 -> V_21 , L_5 ,
V_3 -> V_14 [ V_47 ] . V_4 ) ;
continue;
}
if ( V_3 -> V_52 & V_53 ) {
T_1 V_54 ;
V_54 = F_19 ( V_12 -> V_55 + V_46 -> V_51 ) ;
V_54 &= ~ ( 0x7 << 20 ) ;
V_54 |= ( V_43 -> V_56 << 20 ) ;
F_20 ( V_54 , V_12 -> V_55 + V_46 -> V_51 ) ;
} else {
F_20 ( V_43 -> V_56 , V_12 -> V_55 + V_46 -> V_51 ) ;
}
F_16 ( V_12 -> V_21 , L_6 ,
V_46 -> V_51 , V_43 -> V_56 ) ;
if ( V_43 -> V_57 >> 24 == 0xff ) {
T_1 V_58 = V_43 -> V_57 ;
T_2 V_59 = V_58 & 0xff ;
T_2 V_60 = ( V_58 >> 8 ) & 0xff ;
T_2 V_61 = ( V_58 >> 16 ) & 0xff ;
T_1 V_62 = ( ( 1 << V_60 ) - 1 ) << V_61 ;
V_58 = F_19 ( V_12 -> V_55 + V_43 -> V_63 ) ;
V_58 &= ~ V_62 ;
V_58 |= V_59 << V_61 ;
F_20 ( V_58 , V_12 -> V_55 + V_43 -> V_63 ) ;
} else if ( V_43 -> V_63 ) {
if ( V_12 -> V_64 )
F_20 ( V_43 -> V_57 , V_12 -> V_64 +
V_43 -> V_63 ) ;
else
F_20 ( V_43 -> V_57 , V_12 -> V_55 +
V_43 -> V_63 ) ;
F_16 ( V_12 -> V_21 ,
L_7 ,
V_43 -> V_63 , V_43 -> V_57 ) ;
}
}
return 0 ;
}
static int F_21 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_65 ;
}
static const char * F_22 ( struct V_9 * V_10 ,
unsigned V_13 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
return V_3 -> V_48 [ V_13 ] . V_4 ;
}
static int F_23 ( struct V_9 * V_10 , unsigned V_13 ,
const char * const * * V_8 ,
unsigned * const V_66 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
* V_8 = V_3 -> V_48 [ V_13 ] . V_8 ;
* V_66 = V_3 -> V_48 [ V_13 ] . V_66 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 ,
struct V_67 * V_68 , unsigned V_20 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_45 * V_46 ;
struct V_1 * V_5 ;
struct V_49 * V_49 ;
unsigned int V_43 , V_39 ;
T_1 V_54 ;
if ( ! ( V_3 -> V_52 & V_53 ) )
return - V_16 ;
V_46 = & V_3 -> V_50 [ V_20 ] ;
if ( V_46 -> V_51 == - 1 )
return - V_16 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_7 ; V_39 ++ ) {
V_5 = & V_3 -> V_8 [ V_39 ] ;
for ( V_43 = 0 ; V_43 < V_5 -> V_15 ; V_43 ++ ) {
V_49 = & V_5 -> V_14 [ V_43 ] ;
if ( V_49 -> V_43 == V_20 && ! V_49 -> V_56 )
goto V_69;
}
}
return - V_16 ;
V_69:
V_54 = F_19 ( V_12 -> V_55 + V_46 -> V_51 ) ;
V_54 &= ~ ( 0x7 << 20 ) ;
V_54 |= V_49 -> V_31 ;
F_20 ( V_54 , V_12 -> V_55 + V_46 -> V_51 ) ;
return 0 ;
}
static void F_25 ( struct V_9 * V_10 ,
struct V_67 * V_68 , unsigned V_20 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_45 * V_46 ;
T_1 V_54 ;
if ( ! ( V_3 -> V_52 & V_53 ) )
return;
V_46 = & V_3 -> V_50 [ V_20 ] ;
if ( V_46 -> V_51 == - 1 )
return;
V_54 = F_19 ( V_12 -> V_55 + V_46 -> V_51 ) ;
V_54 &= ~ 0x7 ;
F_20 ( V_54 , V_12 -> V_55 + V_46 -> V_51 ) ;
}
static int F_26 ( struct V_9 * V_10 ,
struct V_67 * V_68 , unsigned V_20 , bool V_70 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_45 * V_46 ;
T_1 V_54 ;
if ( ! ( V_3 -> V_52 & V_53 ) )
return - V_16 ;
V_46 = & V_3 -> V_50 [ V_20 ] ;
if ( V_46 -> V_51 == - 1 )
return - V_16 ;
V_54 = F_19 ( V_12 -> V_55 + V_46 -> V_51 ) ;
if ( V_70 )
V_54 &= ~ 0x2 ;
else
V_54 |= 0x2 ;
F_20 ( V_54 , V_12 -> V_55 + V_46 -> V_51 ) ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 ,
unsigned V_47 , unsigned long * V_31 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_45 * V_46 = & V_3 -> V_50 [ V_47 ] ;
if ( V_46 -> V_71 == - 1 ) {
F_10 ( V_3 -> V_21 , L_8 ,
V_3 -> V_14 [ V_47 ] . V_4 ) ;
return - V_16 ;
}
* V_31 = F_19 ( V_12 -> V_55 + V_46 -> V_71 ) ;
if ( V_3 -> V_52 & V_53 )
* V_31 &= 0xffff ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 ,
unsigned V_47 , unsigned long * V_41 ,
unsigned V_44 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_45 * V_46 = & V_3 -> V_50 [ V_47 ] ;
int V_6 ;
if ( V_46 -> V_71 == - 1 ) {
F_10 ( V_3 -> V_21 , L_8 ,
V_3 -> V_14 [ V_47 ] . V_4 ) ;
return - V_16 ;
}
F_16 ( V_12 -> V_21 , L_9 ,
V_3 -> V_14 [ V_47 ] . V_4 ) ;
for ( V_6 = 0 ; V_6 < V_44 ; V_6 ++ ) {
if ( V_3 -> V_52 & V_53 ) {
T_1 V_54 ;
V_54 = F_19 ( V_12 -> V_55 + V_46 -> V_71 ) ;
V_54 &= ~ 0xffff ;
V_54 |= V_41 [ V_6 ] ;
F_20 ( V_54 , V_12 -> V_55 + V_46 -> V_71 ) ;
} else {
F_20 ( V_41 [ V_6 ] , V_12 -> V_55 + V_46 -> V_71 ) ;
}
F_16 ( V_12 -> V_21 , L_10 ,
V_46 -> V_71 , V_41 [ V_6 ] ) ;
}
return 0 ;
}
static void F_29 ( struct V_9 * V_10 ,
struct V_18 * V_19 , unsigned V_47 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
const struct V_45 * V_46 = & V_3 -> V_50 [ V_47 ] ;
unsigned long V_31 ;
if ( ! V_46 || V_46 -> V_71 == - 1 ) {
F_7 ( V_19 , L_11 ) ;
return;
}
V_31 = F_19 ( V_12 -> V_55 + V_46 -> V_71 ) ;
F_7 ( V_19 , L_12 , V_31 ) ;
}
static void F_30 ( struct V_9 * V_10 ,
struct V_18 * V_19 , unsigned V_39 )
{
struct V_11 * V_12 = F_3 ( V_10 ) ;
const struct V_2 * V_3 = V_12 -> V_3 ;
struct V_1 * V_5 ;
unsigned long V_31 ;
const char * V_4 ;
int V_6 , V_72 ;
if ( V_39 > V_3 -> V_7 )
return;
F_7 ( V_19 , L_13 ) ;
V_5 = & V_3 -> V_8 [ V_39 ] ;
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
struct V_49 * V_43 = & V_5 -> V_14 [ V_6 ] ;
V_4 = F_15 ( V_10 , V_43 -> V_43 ) ;
V_72 = F_27 ( V_10 , V_43 -> V_43 , & V_31 ) ;
if ( V_72 )
return;
F_7 ( V_19 , L_14 , V_4 , V_31 ) ;
}
}
static int F_31 ( struct V_22 * V_23 ,
struct V_1 * V_5 ,
struct V_2 * V_3 ,
T_1 V_73 )
{
int V_74 , V_75 ;
const T_3 * V_76 ;
int V_6 ;
T_1 V_31 ;
F_16 ( V_3 -> V_21 , L_15 , V_73 , V_23 -> V_4 ) ;
if ( V_3 -> V_52 & V_53 )
V_75 = V_77 ;
else
V_75 = V_78 ;
V_5 -> V_4 = V_23 -> V_4 ;
V_76 = F_32 ( V_23 , L_16 , & V_74 ) ;
if ( ! V_76 ) {
F_10 ( V_3 -> V_21 , L_17 , V_23 -> V_79 ) ;
return - V_16 ;
}
if ( ! V_74 || V_74 % V_75 ) {
F_10 ( V_3 -> V_21 , L_18 , V_23 -> V_79 ) ;
return - V_16 ;
}
V_5 -> V_15 = V_74 / V_75 ;
V_5 -> V_14 = F_33 ( V_3 -> V_21 , V_5 -> V_15 * sizeof( struct V_49 ) ,
V_33 ) ;
V_5 -> V_17 = F_33 ( V_3 -> V_21 , V_5 -> V_15 * sizeof( unsigned int ) ,
V_33 ) ;
if ( ! V_5 -> V_14 || ! V_5 -> V_17 )
return - V_34 ;
for ( V_6 = 0 ; V_6 < V_5 -> V_15 ; V_6 ++ ) {
T_1 V_51 = F_34 ( * V_76 ++ ) ;
T_1 V_71 ;
unsigned int V_47 ;
struct V_45 * V_46 ;
struct V_49 * V_43 = & V_5 -> V_14 [ V_6 ] ;
if ( ! ( V_3 -> V_52 & V_80 ) && ! V_51 )
V_51 = - 1 ;
if ( V_3 -> V_52 & V_53 ) {
V_71 = V_51 ;
} else {
V_71 = F_34 ( * V_76 ++ ) ;
if ( ! V_71 )
V_71 = - 1 ;
}
V_47 = ( V_51 != - 1 ) ? V_51 / 4 : V_71 / 4 ;
V_46 = & V_3 -> V_50 [ V_47 ] ;
V_43 -> V_43 = V_47 ;
V_5 -> V_17 [ V_6 ] = V_47 ;
V_46 -> V_51 = V_51 ;
V_46 -> V_71 = V_71 ;
V_43 -> V_63 = F_34 ( * V_76 ++ ) ;
V_43 -> V_56 = F_34 ( * V_76 ++ ) ;
V_43 -> V_57 = F_34 ( * V_76 ++ ) ;
V_31 = F_34 ( * V_76 ++ ) ;
if ( V_31 & V_81 )
V_43 -> V_56 |= V_82 ;
V_43 -> V_31 = V_31 & ~ V_81 ;
F_16 ( V_3 -> V_21 , L_19 , V_3 -> V_14 [ V_47 ] . V_4 ,
V_43 -> V_56 , V_43 -> V_31 ) ;
}
return 0 ;
}
static int F_35 ( struct V_22 * V_23 ,
struct V_2 * V_3 ,
T_1 V_73 )
{
struct V_22 * V_83 ;
struct V_84 * V_85 ;
struct V_1 * V_5 ;
T_1 V_6 = 0 ;
F_16 ( V_3 -> V_21 , L_20 , V_73 , V_23 -> V_4 ) ;
V_85 = & V_3 -> V_48 [ V_73 ] ;
V_85 -> V_4 = V_23 -> V_4 ;
V_85 -> V_66 = F_36 ( V_23 ) ;
if ( V_85 -> V_66 == 0 ) {
F_10 ( V_3 -> V_21 , L_21 , V_23 -> V_79 ) ;
return - V_16 ;
}
V_85 -> V_8 = F_33 ( V_3 -> V_21 ,
V_85 -> V_66 * sizeof( char * ) , V_33 ) ;
F_37 (np, child) {
V_85 -> V_8 [ V_6 ] = V_83 -> V_4 ;
V_5 = & V_3 -> V_8 [ V_3 -> V_86 ++ ] ;
F_31 ( V_83 , V_5 , V_3 , V_6 ++ ) ;
}
return 0 ;
}
static bool F_38 ( struct V_22 * V_23 )
{
struct V_22 * V_87 ;
struct V_22 * V_88 ;
F_37 (np, function_np) {
if ( F_39 ( V_87 , L_16 ) )
return true ;
F_37 (function_np, pinctrl_np) {
if ( F_39 ( V_88 , L_16 ) )
return false ;
}
}
return true ;
}
static int F_40 ( struct V_89 * V_90 ,
struct V_2 * V_3 )
{
struct V_22 * V_23 = V_90 -> V_21 . V_91 ;
struct V_22 * V_83 ;
T_1 V_92 = 0 ;
T_1 V_6 = 0 ;
bool V_93 ;
if ( ! V_23 )
return - V_94 ;
V_93 = F_38 ( V_23 ) ;
if ( V_93 ) {
V_92 = 1 ;
} else {
V_92 = F_36 ( V_23 ) ;
if ( V_92 <= 0 ) {
F_10 ( & V_90 -> V_21 , L_22 ) ;
return - V_16 ;
}
}
V_3 -> V_65 = V_92 ;
V_3 -> V_48 = F_33 ( & V_90 -> V_21 , V_92 * sizeof( struct V_84 ) ,
V_33 ) ;
if ( ! V_3 -> V_48 )
return - V_34 ;
if ( V_93 ) {
V_3 -> V_7 = F_36 ( V_23 ) ;
} else {
V_3 -> V_7 = 0 ;
F_37 (np, child)
V_3 -> V_7 += F_36 ( V_83 ) ;
}
V_3 -> V_8 = F_33 ( & V_90 -> V_21 , V_3 -> V_7 * sizeof( struct V_1 ) ,
V_33 ) ;
if ( ! V_3 -> V_8 )
return - V_34 ;
if ( V_93 ) {
F_35 ( V_23 , V_3 , 0 ) ;
} else {
F_37 (np, child)
F_35 ( V_83 , V_3 , V_6 ++ ) ;
}
return 0 ;
}
int F_41 ( struct V_89 * V_90 ,
struct V_2 * V_3 )
{
struct V_95 V_31 = { . V_4 = L_23 } ;
struct V_22 * V_96 = V_90 -> V_21 . V_91 ;
struct V_22 * V_23 ;
struct V_11 * V_12 ;
struct V_97 * V_98 ;
struct V_99 * V_100 ;
int V_72 , V_6 ;
if ( ! V_3 || ! V_3 -> V_14 || ! V_3 -> V_15 ) {
F_10 ( & V_90 -> V_21 , L_24 ) ;
return - V_16 ;
}
V_3 -> V_21 = & V_90 -> V_21 ;
if ( V_3 -> V_101 ) {
V_100 = F_42 ( V_3 -> V_101 ) ;
if ( ! F_43 ( V_100 ) )
F_44 ( & V_90 -> V_21 , V_100 , & V_31 ) ;
}
V_12 = F_33 ( & V_90 -> V_21 , sizeof( * V_12 ) , V_33 ) ;
if ( ! V_12 )
return - V_34 ;
V_3 -> V_50 = F_45 ( & V_90 -> V_21 , sizeof( * V_3 -> V_50 ) *
V_3 -> V_15 , V_33 ) ;
if ( ! V_3 -> V_50 )
return - V_34 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_15 ; V_6 ++ ) {
V_3 -> V_50 [ V_6 ] . V_51 = - 1 ;
V_3 -> V_50 [ V_6 ] . V_71 = - 1 ;
}
V_98 = F_46 ( V_90 , V_102 , 0 ) ;
V_12 -> V_55 = F_47 ( & V_90 -> V_21 , V_98 ) ;
if ( F_43 ( V_12 -> V_55 ) )
return F_48 ( V_12 -> V_55 ) ;
if ( F_39 ( V_96 , L_25 ) ) {
V_23 = F_49 ( V_96 , L_25 , 0 ) ;
if ( ! V_23 ) {
F_10 ( & V_90 -> V_21 , L_26 ) ;
return - V_16 ;
}
V_12 -> V_64 = F_50 ( V_23 , 0 ) ;
F_14 ( V_23 ) ;
if ( ! V_12 -> V_64 ) {
F_10 ( & V_90 -> V_21 ,
L_27 ) ;
return - V_34 ;
}
}
V_103 . V_4 = F_8 ( & V_90 -> V_21 ) ;
V_103 . V_14 = V_3 -> V_14 ;
V_103 . V_15 = V_3 -> V_15 ;
V_72 = F_40 ( V_90 , V_3 ) ;
if ( V_72 ) {
F_10 ( & V_90 -> V_21 , L_28 ) ;
return V_72 ;
}
V_12 -> V_3 = V_3 ;
V_12 -> V_21 = V_3 -> V_21 ;
F_51 ( V_90 , V_12 ) ;
V_12 -> V_104 = F_52 ( & V_90 -> V_21 , & V_103 , V_12 ) ;
if ( F_43 ( V_12 -> V_104 ) ) {
F_10 ( & V_90 -> V_21 , L_29 ) ;
return F_48 ( V_12 -> V_104 ) ;
}
F_53 ( & V_90 -> V_21 , L_30 ) ;
return 0 ;
}
