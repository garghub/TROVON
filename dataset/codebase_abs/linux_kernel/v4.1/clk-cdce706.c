static int F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned * V_4 )
{
int V_5 = F_2 ( V_2 -> V_6 , V_3 | 0x80 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_7 -> V_8 , L_1 , V_3 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
int V_5 = F_5 ( V_2 -> V_6 , V_3 | 0x80 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_7 -> V_8 , L_2 , V_3 ) ;
return V_5 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_9 , unsigned V_4 )
{
int V_5 = F_7 ( V_2 -> V_6 , V_3 | 0x80 , V_9 , V_4 ) ;
if ( V_5 < 0 )
F_3 ( & V_2 -> V_7 -> V_8 , L_3 , V_3 ) ;
return V_5 ;
}
static int F_8 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
V_14 -> V_15 = V_12 ;
return 0 ;
}
static T_1 F_10 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
return V_14 -> V_15 ;
}
static unsigned long F_11 ( struct V_10 * V_11 ,
unsigned long V_16 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_4 ,
V_17 , V_14 -> V_18 , V_14 -> V_19 , V_14 -> V_20 , V_14 -> div ) ;
if ( ! V_14 -> V_19 ) {
if ( V_14 -> div && V_14 -> V_20 ) {
T_2 V_21 = ( T_2 ) V_16 * V_14 -> V_20 ;
F_13 ( V_21 , V_14 -> div ) ;
return V_21 ;
}
} else {
if ( V_14 -> div )
return V_16 / V_14 -> div ;
}
return 0 ;
}
static long F_14 ( struct V_10 * V_11 , unsigned long V_22 ,
unsigned long * V_16 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
unsigned long V_20 , div ;
T_2 V_21 ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_5 ,
V_17 , V_22 , * V_16 ) ;
F_15 ( V_22 , * V_16 ,
V_23 , V_24 ,
& V_20 , & div ) ;
V_14 -> V_20 = V_20 ;
V_14 -> div = div ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_6 ,
V_17 , V_14 -> V_18 , V_20 , div ) ;
V_21 = ( T_2 ) * V_16 * V_14 -> V_20 ;
F_13 ( V_21 , V_14 -> div ) ;
return V_21 ;
}
static int F_16 ( struct V_10 * V_11 , unsigned long V_22 ,
unsigned long V_16 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
unsigned long V_20 = V_14 -> V_20 , div = V_14 -> div ;
int V_25 ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_6 ,
V_17 , V_14 -> V_18 , V_20 , div ) ;
V_25 = F_6 ( V_14 -> V_2 ,
F_17 ( V_14 -> V_18 ) ,
V_26 | V_27 ,
( ( div >> 8 ) & V_26 ) |
( ( V_20 >> ( 8 - V_28 ) ) &
V_27 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_4 ( V_14 -> V_2 ,
F_18 ( V_14 -> V_18 ) ,
div & V_29 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_4 ( V_14 -> V_2 ,
F_19 ( V_14 -> V_18 ) ,
V_20 & V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_6 ( V_14 -> V_2 ,
V_31 ,
F_20 ( V_14 -> V_18 ) ,
V_22 > V_32 ?
F_20 ( V_14 -> V_18 ) : 0 ) ;
return V_25 ;
}
static int F_21 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
if ( V_14 -> V_15 == V_12 )
return 0 ;
V_14 -> V_15 = V_12 ;
return F_6 ( V_14 -> V_2 ,
F_22 ( V_14 -> V_18 ) ,
F_23 ( V_14 -> V_18 ) ,
V_12 << F_24 ( V_14 -> V_18 ) ) ;
}
static T_1 F_25 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
return V_14 -> V_15 ;
}
static unsigned long F_26 ( struct V_10 * V_11 ,
unsigned long V_16 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_7 ,
V_17 , V_14 -> V_18 , V_14 -> div ) ;
if ( V_14 -> div )
return V_16 / V_14 -> div ;
return 0 ;
}
static long F_27 ( struct V_10 * V_11 , unsigned long V_22 ,
unsigned long * V_16 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
struct V_1 * V_33 = V_14 -> V_2 ;
unsigned long V_20 , div ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_5 ,
V_17 , V_22 , * V_16 ) ;
F_15 ( V_22 , * V_16 ,
1 , V_34 ,
& V_20 , & div ) ;
if ( ! V_20 )
div = V_34 ;
if ( F_28 ( V_11 -> V_35 ) & V_36 ) {
unsigned long V_37 = V_22 ;
unsigned long V_38 = 0 ;
struct V_35 * V_39 = V_33 -> V_40 [ V_33 -> V_41 [ 0 ] . V_15 ] ;
unsigned long V_42 = V_39 ? F_29 ( V_39 ) : 0 ;
for ( div = V_43 / V_22 ; V_37 &&
div <= V_44 / V_22 ; ++ div ) {
unsigned long V_45 , V_46 ;
unsigned long V_47 ;
unsigned long V_48 ;
T_2 V_49 ;
if ( V_22 * div < V_43 )
continue;
F_15 ( V_22 * div , V_42 ,
V_23 ,
V_24 ,
& V_45 , & V_46 ) ;
V_49 = ( T_2 ) V_42 * V_45 ;
F_13 ( V_49 , V_46 ) ;
F_13 ( V_49 , div ) ;
V_48 = V_49 ;
V_47 = F_30 ( V_48 , V_22 ) - F_31 ( V_48 , V_22 ) ;
if ( V_47 < V_37 ) {
V_37 = V_47 ;
V_38 = div ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_8 ,
V_17 , V_42 , V_45 , V_46 , div , V_48 ) ;
}
}
div = V_38 ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_9 ,
V_17 , * V_16 , V_22 * div ) ;
* V_16 = V_22 * div ;
}
V_14 -> div = div ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_10 ,
V_17 , V_14 -> V_18 , div ) ;
return * V_16 / div ;
}
static int F_32 ( struct V_10 * V_11 , unsigned long V_22 ,
unsigned long V_16 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
F_12 ( & V_14 -> V_2 -> V_7 -> V_8 ,
L_7 ,
V_17 , V_14 -> V_18 , V_14 -> div ) ;
return F_6 ( V_14 -> V_2 ,
F_33 ( V_14 -> V_18 ) ,
V_50 ,
V_14 -> div ) ;
}
static int F_34 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
return F_6 ( V_14 -> V_2 , F_35 ( V_14 -> V_18 ) ,
V_51 ,
V_51 ) ;
}
static void F_36 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
F_6 ( V_14 -> V_2 , F_35 ( V_14 -> V_18 ) ,
V_51 , 0 ) ;
}
static int F_37 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
if ( V_14 -> V_15 == V_12 )
return 0 ;
V_14 -> V_15 = V_12 ;
return F_6 ( V_14 -> V_2 ,
F_35 ( V_14 -> V_18 ) ,
V_51 , V_12 ) ;
}
static T_1 F_38 ( struct V_10 * V_11 )
{
struct V_13 * V_14 = F_9 ( V_11 ) ;
return V_14 -> V_15 ;
}
static unsigned long F_39 ( struct V_10 * V_11 ,
unsigned long V_16 )
{
return V_16 ;
}
static long F_40 ( struct V_10 * V_11 , unsigned long V_22 ,
unsigned long * V_16 )
{
* V_16 = V_22 ;
return V_22 ;
}
static int F_41 ( struct V_10 * V_11 , unsigned long V_22 ,
unsigned long V_16 )
{
return 0 ;
}
static int F_42 ( struct V_1 * V_33 ,
struct V_13 * V_11 , unsigned V_52 ,
const char * const * V_53 ,
struct V_54 * V_55 )
{
unsigned V_56 ;
for ( V_56 = 0 ; V_56 < V_52 ; ++ V_56 , ++ V_11 ) {
V_55 -> V_57 = V_53 [ V_56 ] ;
V_11 -> V_2 = V_33 ;
V_11 -> V_18 = V_56 ;
V_11 -> V_11 . V_55 = V_55 ;
V_11 -> V_35 = F_43 ( & V_33 -> V_7 -> V_8 ,
& V_11 -> V_11 ) ;
if ( F_44 ( V_11 -> V_35 ) ) {
F_3 ( & V_33 -> V_7 -> V_8 , L_11 ,
V_53 [ V_56 ] ) ;
return F_45 ( V_11 -> V_35 ) ;
}
}
return 0 ;
}
static int F_46 ( struct V_1 * V_33 )
{
struct V_54 V_55 = {
. V_58 = & V_59 ,
. V_60 = V_33 -> V_61 ,
. V_62 = F_47 ( V_33 -> V_61 ) ,
} ;
unsigned V_56 ;
int V_63 ;
unsigned clock , V_64 ;
for ( V_56 = 0 ; V_56 < F_47 ( V_33 -> V_61 ) ; ++ V_56 ) {
struct V_35 * V_15 = F_48 ( & V_33 -> V_7 -> V_8 ,
V_65 [ V_56 ] ) ;
if ( F_44 ( V_15 ) ) {
V_33 -> V_61 [ V_56 ] = V_65 [ V_56 ] ;
} else {
V_33 -> V_61 [ V_56 ] = F_49 ( V_15 ) ;
V_33 -> V_40 [ V_56 ] = V_15 ;
}
}
V_63 = F_1 ( V_33 , V_66 , & V_64 ) ;
if ( V_63 < 0 )
return V_63 ;
if ( ( V_64 & V_67 ) ==
V_68 ) {
V_63 = F_1 ( V_33 , V_69 , & clock ) ;
if ( V_63 < 0 )
return V_63 ;
V_33 -> V_41 [ 0 ] . V_15 = ! ! ( clock & V_70 ) ;
}
V_63 = F_42 ( V_33 , V_33 -> V_41 ,
F_47 ( V_33 -> V_41 ) ,
V_71 , & V_55 ) ;
return V_63 ;
}
static int F_50 ( struct V_1 * V_33 )
{
struct V_54 V_55 = {
. V_58 = & V_72 ,
. V_60 = V_71 ,
. V_62 = F_47 ( V_71 ) ,
} ;
unsigned V_56 ;
int V_63 ;
unsigned V_19 ;
V_63 = F_1 ( V_33 , V_73 , & V_19 ) ;
if ( V_63 < 0 )
return V_63 ;
for ( V_56 = 0 ; V_56 < F_47 ( V_33 -> V_74 ) ; ++ V_56 ) {
unsigned V_46 , V_45 , V_75 ;
V_63 = F_1 ( V_33 , F_18 ( V_56 ) , & V_46 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_1 ( V_33 , F_19 ( V_56 ) , & V_45 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_1 ( V_33 , F_17 ( V_56 ) , & V_75 ) ;
if ( V_63 < 0 )
return V_63 ;
V_33 -> V_74 [ V_56 ] . div = V_46 | ( ( V_75 & V_26 ) << 8 ) ;
V_33 -> V_74 [ V_56 ] . V_20 = V_45 | ( ( V_75 & V_27 ) <<
( 8 - V_28 ) ) ;
V_33 -> V_74 [ V_56 ] . V_19 = V_19 & F_51 ( V_56 ) ;
F_12 ( & V_33 -> V_7 -> V_8 ,
L_12 , V_17 , V_56 ,
V_33 -> V_74 [ V_56 ] . div , V_33 -> V_74 [ V_56 ] . V_20 , V_33 -> V_74 [ V_56 ] . V_19 ) ;
}
V_63 = F_42 ( V_33 , V_33 -> V_74 ,
F_47 ( V_33 -> V_74 ) ,
V_76 , & V_55 ) ;
return V_63 ;
}
static int F_52 ( struct V_1 * V_33 )
{
struct V_54 V_55 = {
. V_58 = & V_77 ,
. V_60 = V_78 ,
. V_62 = F_47 ( V_78 ) ,
. V_79 = V_36 ,
} ;
unsigned V_56 ;
int V_63 ;
for ( V_56 = 0 ; V_56 < F_47 ( V_33 -> V_80 ) ; ++ V_56 ) {
unsigned V_4 ;
V_63 = F_1 ( V_33 , F_22 ( V_56 ) , & V_4 ) ;
if ( V_63 < 0 )
return V_63 ;
V_33 -> V_80 [ V_56 ] . V_15 =
( V_4 & F_23 ( V_56 ) ) >>
F_24 ( V_56 ) ;
V_63 = F_1 ( V_33 , F_33 ( V_56 ) , & V_4 ) ;
if ( V_63 < 0 )
return V_63 ;
V_33 -> V_80 [ V_56 ] . div = V_4 & V_50 ;
F_12 ( & V_33 -> V_7 -> V_8 ,
L_13 , V_17 , V_56 ,
V_33 -> V_80 [ V_56 ] . V_15 , V_33 -> V_80 [ V_56 ] . div ) ;
}
V_63 = F_42 ( V_33 , V_33 -> V_80 ,
F_47 ( V_33 -> V_80 ) ,
V_81 , & V_55 ) ;
return V_63 ;
}
static int F_53 ( struct V_1 * V_33 )
{
struct V_54 V_55 = {
. V_58 = & V_82 ,
. V_60 = V_81 ,
. V_62 = F_47 ( V_81 ) ,
. V_79 = V_36 ,
} ;
unsigned V_56 ;
int V_63 ;
for ( V_56 = 0 ; V_56 < F_47 ( V_33 -> V_83 ) ; ++ V_56 ) {
unsigned V_4 ;
V_63 = F_1 ( V_33 , F_35 ( V_56 ) , & V_4 ) ;
if ( V_63 < 0 )
return V_63 ;
V_33 -> V_83 [ V_56 ] . V_15 = V_4 & V_84 ;
F_12 ( & V_33 -> V_7 -> V_8 ,
L_14 , V_17 , V_56 ,
V_33 -> V_83 [ V_56 ] . V_15 ) ;
}
V_63 = F_42 ( V_33 , V_33 -> V_83 ,
F_47 ( V_33 -> V_83 ) ,
V_85 , & V_55 ) ;
for ( V_56 = 0 ; V_56 < F_47 ( V_33 -> V_83 ) ; ++ V_56 )
V_33 -> V_86 [ V_56 ] = V_33 -> V_83 [ V_56 ] . V_35 ;
return V_63 ;
}
static int F_54 ( struct V_87 * V_7 ,
const struct V_88 * V_89 )
{
struct V_90 * V_91 = F_55 ( V_7 -> V_8 . V_15 ) ;
struct V_1 * V_33 ;
int V_63 ;
if ( ! F_56 ( V_91 , V_92 ) )
return - V_93 ;
V_33 = F_57 ( & V_7 -> V_8 , sizeof( * V_33 ) , V_94 ) ;
if ( ! V_33 )
return - V_95 ;
V_33 -> V_7 = V_7 ;
V_33 -> V_6 = F_58 ( V_7 , & V_96 ) ;
if ( F_44 ( V_33 -> V_6 ) ) {
F_3 ( & V_7 -> V_8 , L_15 ) ;
return - V_97 ;
}
F_59 ( V_7 , V_33 ) ;
V_63 = F_46 ( V_33 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_50 ( V_33 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_52 ( V_33 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_53 ( V_33 ) ;
if ( V_63 < 0 )
return V_63 ;
V_33 -> V_98 . V_86 = V_33 -> V_86 ;
V_33 -> V_98 . V_99 = F_47 ( V_33 -> V_86 ) ;
V_63 = F_60 ( V_7 -> V_8 . V_100 , V_101 ,
& V_33 -> V_98 ) ;
return V_63 ;
}
static int F_61 ( struct V_87 * V_7 )
{
return 0 ;
}
