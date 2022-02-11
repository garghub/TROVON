static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
unsigned V_5 )
{
int V_6 ;
if ( ( V_3 > V_7 + 7 ) ||
( V_3 + V_5 > V_7 + 8 ) )
return - V_8 ;
V_6 = F_2 ( V_2 , V_3 , V_5 , V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 < V_5 )
return - V_9 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 const V_4 [] ,
unsigned V_5 )
{
if ( ( V_3 > V_7 + 7 ) ||
( V_3 + V_5 > V_7 + 8 ) )
return - V_8 ;
return F_4 ( V_2 , V_3 , V_5 , V_4 ) ;
}
static int
F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 , T_1 V_11 )
{
T_1 V_4 ;
int V_6 ;
V_6 = F_1 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 &= ~ V_10 ;
V_4 |= V_11 & V_10 ;
V_6 = F_3 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_6 = F_1 ( V_2 , V_12 , V_4 , 1 ) ;
if ( V_6 < 0 )
return - V_9 ;
F_7 ( & V_2 -> V_13 , L_1 , V_4 [ 0 ] , V_4 [ 0 ] ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_14 )
{
T_1 V_4 [ 1 ] ;
int V_15 ;
V_4 [ 0 ] = V_14 ;
V_15 = F_3 ( V_2 , V_12 , V_4 , 1 ) ;
F_7 ( & V_2 -> V_13 , L_1 , V_4 [ 0 ] , V_4 [ 0 ] ) ;
if ( V_15 < 0 )
return - V_9 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_16 , V_6 ;
T_1 V_15 ;
for ( V_16 = 100 ; V_16 > 0 ; V_16 -- ) {
V_6 = F_6 ( V_2 , & V_15 ) ;
if ( V_6 < 0 )
break;
if ( ! ( V_15 & V_17 ) )
break;
F_10 ( 1000 , 10000 ) ;
}
if ( V_16 <= 0 ) {
F_11 ( & V_2 -> V_13 , L_2 ) ;
return - V_18 ;
}
return V_6 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return F_5 ( V_2 , V_19 ,
V_20 ,
V_20 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_6 ;
T_1 V_15 ;
V_6 = F_6 ( V_2 , & V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_15 & ( V_21 | V_22 ) ) {
V_15 &= ~ V_21 ;
V_15 &= ~ V_22 ;
V_6 = F_8 ( V_2 , V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
F_10 ( 1000 , 10000 ) ;
V_6 = F_6 ( V_2 , & V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_15 & ( V_21 | V_22 ) ) {
F_11 ( & V_2 -> V_13 ,
L_3 ) ;
return - V_23 ;
}
}
V_6 = F_5 ( V_2 , V_19 ,
V_20 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 < 0 )
F_12 ( V_2 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 [] , T_2 V_5 )
{
int V_6 , V_24 ;
V_24 = F_13 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_6 = F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
V_24 = F_12 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 const V_4 [] , T_2 V_5 )
{
int V_6 , V_24 ;
T_2 V_16 ;
T_1 V_25 ;
V_24 = F_13 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
for ( V_16 = 0 ; V_16 < V_5 ; V_16 ++ , V_3 ++ ) {
V_6 = F_1 ( V_2 , V_3 , & V_25 , 1 ) ;
if ( V_6 < 0 )
break;
if ( V_25 != V_4 [ V_16 ] ) {
V_6 = F_3 ( V_2 , V_3 , & V_4 [ V_16 ] , 1 ) ;
if ( V_6 < 0 )
break;
}
V_6 = F_9 ( V_2 ) ;
if ( V_6 < 0 )
break;
}
V_24 = F_12 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_10 , T_1 V_11 )
{
T_1 V_4 ;
int V_6 ;
V_6 = F_14 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 &= ~ V_10 ;
V_4 |= V_11 & V_10 ;
V_6 = F_15 ( V_2 , V_3 , & V_4 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
T_1 V_4 [ 1 ] ;
int V_6 ;
T_1 V_28 [ V_29 ] = { 0 , } ;
V_6 = F_6 ( V_2 , V_4 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_4 , V_30 ) ;
return - V_9 ;
}
V_6 = F_1 ( V_2 , V_31 , V_28 ,
V_29 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_5 ,
V_30 ) ;
return V_6 ;
}
V_27 -> V_32 = F_18 ( V_28 [ V_31 - V_31 ] ) ;
V_27 -> V_33 = F_18 ( V_28 [ V_34 - V_31 ] ) ;
{
const T_1 V_35 = V_28 [ V_36 - V_31 ] ;
if ( V_35 & V_37 ) {
V_27 -> V_38 = F_18 ( V_35 & 0x1f ) ;
if ( V_35 & V_39 )
V_27 -> V_38 += 12 ;
} else
V_27 -> V_38 = F_18 ( V_35 & 0x3f ) ;
}
V_27 -> V_40 = F_18 ( V_28 [ V_41 - V_31 ] ) ;
V_27 -> V_42 = F_18 ( V_28 [ V_43 - V_31 ] ) - 1 ;
V_27 -> V_44 = F_18 ( V_28 [ V_45 - V_31 ] ) + 100 ;
V_27 -> V_46 = F_18 ( V_28 [ V_47 - V_31 ] ) - 1 ;
return 0 ;
}
static int F_19 ( struct V_48 * V_13 , struct V_26 * V_27 )
{
return F_17 ( F_20 ( V_13 ) , V_27 ) ;
}
static int
F_21 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_26 * const V_27 = & V_50 -> time ;
int V_6 ;
T_1 V_28 [ 8 ] ;
V_6 = F_6 ( V_2 , V_28 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_4 , V_30 ) ;
return - V_9 ;
}
V_6 = F_1 ( V_2 , V_51 , V_28 ,
V_52 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_6 ,
V_30 ) ;
return V_6 ;
}
V_27 -> V_32 = F_18 ( V_28 [ V_51 - V_51 ] & 0x7f ) ;
V_27 -> V_33 = F_18 ( V_28 [ V_53 - V_51 ] & 0x7f ) ;
V_27 -> V_38 = F_18 ( V_28 [ V_54 - V_51 ] & 0x3f ) ;
V_27 -> V_40 = F_18 ( V_28 [ V_55 - V_51 ] & 0x3f ) ;
V_27 -> V_42 = F_18 ( V_28 [ V_56 - V_51 ] & 0x1f ) - 1 ;
V_27 -> V_44 = F_18 ( V_28 [ V_57 - V_51 ] & 0x7f ) + 100 ;
V_27 -> V_46 = F_18 ( V_28 [ V_58 - V_51 ] & 0x07 ) - 1 ;
return 0 ;
}
static int
F_22 ( struct V_48 * V_13 , struct V_49 * V_50 )
{
return F_21 ( F_20 ( V_13 ) , V_50 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
int V_59 )
{
int V_6 ;
V_6 = F_5 ( V_2 , V_60 ,
V_61 ,
( V_59 ? V_61 : 0 ) ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_7 ) ;
return V_6 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_26 * const V_27 = & V_50 -> time ;
int V_6 ;
T_1 V_28 [ 8 ] ;
if ( V_27 -> V_44 < 100 )
return - V_8 ;
V_6 = F_6 ( V_2 , V_28 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_4 , V_30 ) ;
return - V_9 ;
}
V_28 [ V_51 - V_51 ] = F_25 ( V_27 -> V_32 & 0x7f ) ;
V_28 [ V_53 - V_51 ] = F_25 ( V_27 -> V_33 & 0x7f ) ;
V_28 [ V_54 - V_51 ] = F_25 ( V_27 -> V_38 & 0x3f ) ;
V_28 [ V_55 - V_51 ] = F_25 ( V_27 -> V_40 & 0x3f ) ;
V_28 [ V_56 - V_51 ] = F_25 ( ( V_27 -> V_42 & 0x1f ) - 1 ) ;
V_28 [ V_58 - V_51 ] = F_25 ( ( V_27 -> V_46 & 7 ) - 1 ) ;
V_28 [ V_57 - V_51 ] = F_25 ( ( V_27 -> V_44 & 0x7f ) - 100 ) ;
V_6 = F_3 ( V_2 , V_51 , V_28 ,
V_52 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_50 -> V_62 ) {
V_6 = F_5 ( V_2 , V_63 ,
V_64 , 0 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_8 ) ;
return V_6 ;
}
V_6 = F_23 ( V_2 , 1 ) ;
if ( V_6 )
return V_6 ;
F_7 ( & V_2 -> V_13 , L_9 ) ;
} else {
V_6 = F_23 ( V_2 , 0 ) ;
if ( V_6 )
return V_6 ;
F_7 ( & V_2 -> V_13 , L_10 ) ;
}
return 0 ;
}
static int F_26 ( struct V_48 * V_13 , struct V_49 * V_50 )
{
return F_24 ( F_20 ( V_13 ) , V_50 ) ;
}
static int
F_27 ( struct V_1 * V_2 , struct V_26 const * V_27 )
{
T_1 V_28 [ 8 ] ;
int V_6 ;
if ( V_27 -> V_44 < 100 )
return - V_8 ;
V_28 [ V_31 - V_31 ] = F_25 ( V_27 -> V_32 ) ;
V_28 [ V_34 - V_31 ] = F_25 ( V_27 -> V_33 ) ;
V_28 [ V_36 - V_31 ] = F_25 ( V_27 -> V_38 ) ;
V_28 [ V_41 - V_31 ] = F_25 ( V_27 -> V_40 ) ;
V_28 [ V_43 - V_31 ] = F_25 ( V_27 -> V_42 + 1 ) ;
V_28 [ V_47 - V_31 ] = F_25 ( ( V_27 -> V_46 & 7 ) + 1 ) ;
V_28 [ V_45 - V_31 ] = F_25 ( V_27 -> V_44 - 100 ) ;
V_6 = F_3 ( V_2 , V_31 , V_28 ,
V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_6 ( V_2 , V_28 ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_4 , V_30 ) ;
return V_6 ;
}
V_6 = F_8 ( V_2 , ( V_28 [ 0 ] & ~ V_65 ) ) ;
if ( V_6 < 0 ) {
F_11 ( & V_2 -> V_13 , L_4 , V_30 ) ;
return V_6 ;
}
return 0 ;
}
static int F_28 ( struct V_48 * V_13 , struct V_26 * V_27 )
{
return F_27 ( F_20 ( V_13 ) , V_27 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = V_2 -> V_13 . V_67 ;
const struct V_68 * V_69 ;
int V_16 , V_24 ;
T_3 V_70 ;
T_1 V_71 ;
if ( ! V_67 )
return;
V_24 = F_30 ( V_67 , L_11 , & V_70 ) ;
if ( V_24 ) {
V_71 = 0 ;
} else {
for ( V_16 = 0 ; V_16 < F_31 ( V_72 ) ; V_16 ++ ) {
V_69 = & V_72 [ V_16 ] ;
if ( V_69 -> V_73 >= V_70 )
break;
}
V_71 = V_69 -> V_74 ;
F_32 ( & V_2 -> V_13 ,
L_12 ,
V_69 -> V_73 ) ;
}
V_24 = F_16 ( V_2 , V_75 ,
V_76 ,
V_71 ) ;
if ( V_24 < 0 ) {
F_11 ( & V_2 -> V_13 ,
L_13 ) ;
}
}
static int F_33 ( struct V_1 * V_2 , int * V_77 )
{
int V_6 ;
T_1 V_78 ;
V_6 = F_1 ( V_2 , V_79 , & V_78 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_77 = ( ( int ) V_78 - 60 ) * 1000 ;
return 0 ;
}
static T_4 F_34 ( struct V_48 * V_13 ,
struct V_80 * V_81 ,
char * V_4 )
{
struct V_1 * V_2 = F_35 ( V_13 ) ;
int V_6 , V_77 ;
V_6 = F_33 ( V_2 , & V_77 ) ;
if ( V_6 < 0 )
return V_6 ;
return sprintf ( V_4 , L_14 , V_77 ) ;
}
static T_4 F_36 ( struct V_48 * V_13 ,
struct V_80 * V_81 ,
const char * V_4 ,
T_2 V_82 )
{
struct V_1 * V_2 = F_35 ( V_13 ) ;
unsigned long V_83 ;
int V_6 ;
T_1 V_84 = 0 ;
V_6 = F_37 ( V_4 , 10 , & V_83 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_83 != 0 ) {
V_84 |= V_85 ;
if ( V_83 >= 16000 )
V_84 |= V_86 ;
}
V_6 = F_16 ( V_2 , V_75 ,
V_85 | V_86 ,
V_84 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_82 ;
}
static T_4 F_38 ( struct V_48 * V_13 ,
struct V_80 * V_81 ,
char * V_4 )
{
struct V_1 * V_2 = F_35 ( V_13 ) ;
int V_6 , V_83 ;
T_1 V_87 ;
V_6 = F_14 ( V_2 , V_75 ,
& V_87 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_87 & V_85 ) {
if ( V_87 & V_86 )
V_83 = 16000 ;
else
V_83 = 1000 ;
} else {
V_83 = 0 ;
}
return sprintf ( V_4 , L_14 , V_83 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_48 * V_88 ;
V_88 = F_40 (
& V_2 -> V_13 , V_2 -> V_89 , V_2 , V_90 ) ;
if ( F_41 ( V_88 ) ) {
F_42 ( & V_2 -> V_13 ,
L_15 ,
F_43 ( V_88 ) ) ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
}
static int F_44 ( struct V_1 * V_2 ,
const struct V_91 * V_92 )
{
struct V_93 * V_94 ;
int V_95 = 0 ;
T_1 V_4 [ 1 ] ;
if ( ! F_45 ( V_2 -> V_96 , V_97 ) )
return - V_23 ;
V_95 = F_6 ( V_2 , V_4 ) ;
if ( V_95 < 0 ) {
F_11 ( & V_2 -> V_13 , L_16 ) ;
return V_95 ;
}
F_29 ( V_2 ) ;
F_39 ( V_2 ) ;
V_94 = F_46 ( & V_2 -> V_13 , V_2 -> V_89 ,
& V_98 , V_99 ) ;
if ( F_41 ( V_94 ) )
return F_43 ( V_94 ) ;
F_47 ( V_2 , V_94 ) ;
return 0 ;
}
