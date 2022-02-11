static void T_1 * F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 = V_3 / 32 ;
return V_2 -> V_5 + V_4 * V_6 ;
}
static void F_2 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_7 , T_2 V_8 )
{
void T_1 * V_9 = F_1 ( V_2 , V_3 ) + V_8 ;
int V_10 = ( V_3 % 16 ) * 2 ;
int V_11 = ~ ( 0x3 << V_10 ) ;
T_2 V_12 ;
T_2 V_13 ;
if ( V_3 % 32 >= 16 )
V_9 += 0x04 ;
F_3 ( V_2 -> V_14 , L_1 ,
V_9 , V_10 , V_7 ) ;
V_12 = F_4 ( V_9 ) ;
V_12 &= V_11 ;
V_13 = V_7 & 0x3 ;
V_13 <<= V_10 ;
V_13 |= V_12 ;
F_5 ( V_13 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_7 , T_2 V_8 )
{
void T_1 * V_9 = F_1 ( V_2 , V_3 ) + V_8 ;
int V_10 = V_3 % 32 ;
int V_11 = ~ F_7 ( V_10 ) ;
T_2 V_12 ;
T_2 V_13 ;
V_12 = F_4 ( V_9 ) ;
V_12 &= V_11 ;
V_13 = V_7 & 0x1 ;
V_13 <<= V_10 ;
V_13 |= V_12 ;
F_5 ( V_13 , V_9 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_8 )
{
void T_1 * V_9 = F_1 ( V_2 , V_3 ) + V_8 ;
int V_10 = ( V_3 % 16 ) * 2 ;
if ( V_3 % 32 >= 16 )
V_9 += 0x04 ;
return ( F_4 ( V_9 ) & ( F_9 ( V_10 ) | F_9 ( V_10 + 1 ) ) ) >> V_10 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
T_2 V_8 )
{
void T_1 * V_9 = F_1 ( V_2 , V_3 ) + V_8 ;
int V_10 = V_3 % 32 ;
return ! ! ( F_4 ( V_9 ) & F_9 ( V_10 ) ) ;
}
static const inline struct V_15 * F_11 (
const struct V_16 * V_17 ,
const char * V_18 )
{
const struct V_15 * V_19 = NULL ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_17 -> V_21 ; V_20 ++ ) {
if ( ! strcmp ( V_17 -> V_22 [ V_20 ] . V_18 , V_18 ) ) {
V_19 = & V_17 -> V_22 [ V_20 ] ;
break;
}
}
return V_19 ;
}
static int F_12 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
return V_17 -> V_21 ;
}
static const char * F_14 ( struct V_23 * V_24 ,
unsigned V_25 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
return V_17 -> V_22 [ V_25 ] . V_18 ;
}
static int F_15 ( struct V_23 * V_24 , unsigned V_25 ,
const unsigned int * * V_26 ,
unsigned * V_27 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
if ( V_25 >= V_17 -> V_21 )
return - V_28 ;
* V_26 = V_17 -> V_22 [ V_25 ] . V_29 ;
* V_27 = V_17 -> V_22 [ V_25 ] . V_27 ;
return 0 ;
}
static void F_16 ( struct V_23 * V_24 , struct V_30 * V_31 ,
unsigned V_10 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
F_17 ( V_31 , L_2 ,
F_10 ( V_2 , V_10 , V_32 ) ,
F_10 ( V_2 , V_10 , V_33 ) ,
F_10 ( V_2 , V_10 , V_34 ) ,
F_8 ( V_2 , V_10 , V_35 ) ,
F_8 ( V_2 , V_10 , V_36 ) ,
F_8 ( V_2 , V_10 , V_37 ) ) ;
}
static int F_18 ( struct V_23 * V_24 ,
struct V_38 * V_39 ,
struct V_40 * * V_41 , unsigned * V_42 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
const struct V_15 * V_19 ;
struct V_40 * V_43 ;
struct V_38 * V_44 ;
int V_45 = 1 ;
int V_20 , V_46 ;
V_19 = F_11 ( V_17 , V_39 -> V_18 ) ;
if ( ! V_19 ) {
F_19 ( V_17 -> V_14 , L_3 ,
V_39 -> V_18 ) ;
return - V_28 ;
}
for ( V_20 = 0 ; V_20 < V_19 -> V_27 ; V_20 ++ )
V_45 ++ ;
V_43 = F_20 ( sizeof( struct V_40 ) * V_45 , V_47 ) ;
if ( ! V_43 )
return - V_48 ;
* V_41 = V_43 ;
* V_42 = V_45 ;
V_44 = F_21 ( V_39 ) ;
if ( ! V_44 ) {
F_22 ( V_43 ) ;
return - V_28 ;
}
V_43 [ 0 ] . type = V_49 ;
V_43 [ 0 ] . V_50 . V_51 . V_52 = V_44 -> V_18 ;
V_43 [ 0 ] . V_50 . V_51 . V_53 = V_39 -> V_18 ;
F_23 ( V_44 ) ;
V_43 ++ ;
for ( V_20 = V_46 = 0 ; V_20 < V_19 -> V_27 ; V_20 ++ ) {
V_43 [ V_46 ] . type = V_54 ;
V_43 [ V_46 ] . V_50 . V_55 . V_56 =
F_24 ( V_24 , V_19 -> V_26 [ V_20 ] . V_3 ) ;
V_43 [ V_46 ] . V_50 . V_55 . V_55 = & V_19 -> V_26 [ V_20 ] . V_57 ;
V_43 [ V_46 ] . V_50 . V_55 . V_58 = 1 ;
V_46 ++ ;
}
F_3 ( V_24 -> V_14 , L_4 ,
( * V_41 ) -> V_50 . V_51 . V_52 , ( * V_41 ) -> V_50 . V_51 . V_53 , V_45 ) ;
return 0 ;
}
static void F_25 ( struct V_23 * V_24 ,
struct V_40 * V_41 , unsigned V_42 )
{
F_22 ( V_41 ) ;
}
static int F_26 ( struct V_23 * V_24 , unsigned V_25 ,
unsigned V_53 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
const struct V_59 * V_26 ;
unsigned int V_27 ;
int V_20 ;
V_26 = V_17 -> V_22 [ V_53 ] . V_26 ;
V_27 = V_17 -> V_22 [ V_53 ] . V_27 ;
F_27 ( ! V_26 || ! V_27 ) ;
F_3 ( V_2 -> V_14 , L_5 ,
V_17 -> V_60 [ V_25 ] . V_18 , V_17 -> V_22 [ V_53 ] . V_18 ) ;
for ( V_20 = 0 ; V_20 < V_27 ; V_20 ++ ) {
unsigned int V_51 = V_26 [ V_20 ] . V_61 ;
unsigned int V_3 = V_26 [ V_20 ] . V_3 ;
unsigned int V_62 = F_28 ( V_51 ) ;
unsigned int V_63 = F_29 ( V_51 ) ;
unsigned int V_64 = F_30 ( V_51 ) ;
unsigned int V_65 = F_31 ( V_51 ) ;
unsigned int V_66 = F_32 ( V_51 ) ;
unsigned int V_67 = F_33 ( V_51 ) ;
F_3 ( V_24 -> V_14 , L_6 ,
V_68 , V_3 , V_62 , V_63 ,
V_64 , V_65 , V_66 ,
V_67 ) ;
F_6 ( V_2 , V_3 , V_63 , V_32 ) ;
F_6 ( V_2 , V_3 , V_64 , V_34 ) ;
if ( V_63 ) {
F_2 ( V_2 , V_3 , V_65 , V_35 ) ;
F_2 ( V_2 , V_3 , V_66 ,
V_36 ) ;
F_2 ( V_2 , V_3 , V_67 ,
V_37 ) ;
} else {
F_6 ( V_2 , V_3 , V_62 , V_33 ) ;
}
}
return 0 ;
}
static int F_34 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
return V_17 -> V_69 ;
}
static const char * F_35 ( struct V_23 * V_24 ,
unsigned V_25 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
return V_17 -> V_60 [ V_25 ] . V_18 ;
}
static int F_36 ( struct V_23 * V_24 , unsigned V_25 ,
const char * const * * V_22 ,
unsigned * const V_70 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
* V_22 = V_17 -> V_60 [ V_25 ] . V_22 ;
* V_70 = V_17 -> V_60 [ V_25 ] . V_70 ;
return 0 ;
}
static int F_37 ( struct V_23 * V_24 ,
unsigned V_3 , unsigned long * V_57 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
* V_57 = F_10 ( V_2 , V_3 , V_71 ) ;
return 0 ;
}
static int F_38 ( struct V_23 * V_24 ,
unsigned V_3 , unsigned long * V_55 ,
unsigned V_58 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
int V_20 ;
for ( V_20 = 0 ; V_20 != V_58 ; ++ V_20 ) {
F_6 ( V_2 , V_3 , V_55 [ V_20 ] & 0x01 , V_71 ) ;
F_3 ( V_2 -> V_14 , L_7 ,
F_39 ( V_24 , V_3 ) -> V_18 ) ;
}
return 0 ;
}
static void F_40 ( struct V_23 * V_24 ,
struct V_30 * V_31 , unsigned V_3 )
{
unsigned long V_57 ;
F_37 ( V_24 , V_3 , & V_57 ) ;
F_17 ( V_31 , L_8 , V_57 ) ;
}
static void F_41 ( struct V_23 * V_24 ,
struct V_30 * V_31 , unsigned V_53 )
{
struct V_1 * V_2 = F_13 ( V_24 ) ;
const struct V_16 * V_17 = V_2 -> V_17 ;
struct V_15 * V_19 ;
unsigned long V_57 ;
const char * V_18 ;
int V_20 , V_72 ;
if ( V_53 > V_17 -> V_21 )
return;
F_42 ( V_31 , L_9 ) ;
V_19 = & V_17 -> V_22 [ V_53 ] ;
for ( V_20 = 0 ; V_20 < V_19 -> V_27 ; V_20 ++ ) {
V_18 = F_24 ( V_24 , V_19 -> V_26 [ V_20 ] . V_3 ) ;
V_72 = F_37 ( V_24 , V_19 -> V_26 [ V_20 ] . V_3 , & V_57 ) ;
if ( V_72 )
return;
F_17 ( V_31 , L_10 , V_18 , V_57 ) ;
}
}
static int F_43 ( struct V_38 * V_39 ,
struct V_15 * V_19 ,
struct V_16 * V_17 ,
T_2 V_73 )
{
int V_74 ;
const T_3 * V_75 ;
int V_20 ;
F_3 ( V_17 -> V_14 , L_11 , V_73 , V_39 -> V_18 ) ;
V_19 -> V_18 = V_39 -> V_18 ;
V_75 = F_44 ( V_39 , L_12 , & V_74 ) ;
if ( ! V_74 || V_74 % 12 ) {
F_45 ( V_17 -> V_14 , L_13 ,
V_39 -> V_18 ) ;
return - V_28 ;
}
V_19 -> V_27 = V_74 / 12 ;
V_19 -> V_26 = F_46 ( V_17 -> V_14 ,
V_19 -> V_27 * sizeof( struct V_59 ) , V_47 ) ;
V_19 -> V_29 = F_46 ( V_17 -> V_14 ,
V_19 -> V_27 * sizeof( unsigned int ) , V_47 ) ;
if ( ! V_19 -> V_26 || ! V_19 -> V_29 )
return - V_48 ;
for ( V_20 = 0 ; V_20 < V_19 -> V_27 ; V_20 ++ ) {
V_19 -> V_26 [ V_20 ] . V_3 = F_47 ( * V_75 ++ ) ;
V_19 -> V_26 [ V_20 ] . V_61 = F_47 ( * V_75 ++ ) ;
V_19 -> V_26 [ V_20 ] . V_57 = F_47 ( * V_75 ++ ) ;
V_19 -> V_29 [ V_20 ] = V_19 -> V_26 [ V_20 ] . V_3 ;
}
return 0 ;
}
static int F_48 ( struct V_38 * V_39 ,
struct V_16 * V_17 ,
T_2 V_73 )
{
struct V_38 * V_76 ;
struct V_77 * V_78 ;
struct V_15 * V_19 ;
int V_72 ;
static T_2 V_79 ;
T_2 V_20 = 0 ;
F_3 ( V_17 -> V_14 , L_14 , V_73 , V_39 -> V_18 ) ;
V_78 = & V_17 -> V_60 [ V_73 ] ;
V_78 -> V_18 = V_39 -> V_18 ;
V_78 -> V_70 = F_49 ( V_39 ) ;
if ( V_78 -> V_70 == 0 )
return - V_28 ;
V_78 -> V_22 = F_46 ( V_17 -> V_14 ,
V_78 -> V_70 * sizeof( char * ) , V_47 ) ;
if ( ! V_78 -> V_22 )
return - V_48 ;
F_50 (np, child) {
V_78 -> V_22 [ V_20 ] = V_76 -> V_18 ;
V_19 = & V_17 -> V_22 [ V_79 ++ ] ;
V_72 = F_43 ( V_76 , V_19 , V_17 , V_20 ++ ) ;
if ( V_72 == - V_48 ) {
F_23 ( V_76 ) ;
return V_72 ;
}
}
return 0 ;
}
static int F_51 ( struct V_80 * V_81 ,
struct V_1 * V_82 , struct V_16 * V_17 )
{
struct V_38 * V_39 = V_81 -> V_14 . V_83 ;
struct V_38 * V_76 ;
int V_72 ;
T_2 V_84 = 0 ;
T_2 V_21 = 0 ;
T_2 V_85 = 0 ;
if ( ! V_39 )
return - V_86 ;
F_50 (np, child) {
++ V_84 ;
V_21 += F_49 ( V_76 ) ;
}
if ( ! V_84 ) {
F_19 ( & V_81 -> V_14 , L_15 ) ;
return - V_28 ;
}
V_17 -> V_69 = V_84 ;
V_17 -> V_60 = F_46 ( & V_81 -> V_14 ,
V_84 * sizeof( struct V_77 ) , V_47 ) ;
V_17 -> V_21 = V_21 ;
V_17 -> V_22 = F_46 ( & V_81 -> V_14 ,
V_21 * sizeof( struct V_15 ) , V_47 ) ;
if ( ! V_17 -> V_60 || ! V_17 -> V_22 )
return - V_48 ;
F_50 (np, child) {
V_72 = F_48 ( V_76 , V_17 , V_85 ++ ) ;
if ( V_72 == - V_48 ) {
F_23 ( V_76 ) ;
return - V_48 ;
}
}
return 0 ;
}
int F_52 ( struct V_80 * V_81 ,
struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_87 * V_88 ;
struct V_89 * V_90 ;
int V_72 ;
if ( ! V_17 || ! V_17 -> V_26 || ! V_17 -> V_27 ) {
F_19 ( & V_81 -> V_14 , L_16 ) ;
return - V_28 ;
}
V_17 -> V_14 = & V_81 -> V_14 ;
V_2 = F_46 ( & V_81 -> V_14 , sizeof( * V_2 ) , V_47 ) ;
if ( ! V_2 )
return - V_48 ;
V_88 = F_53 ( V_81 , V_91 , 0 ) ;
if ( ! V_88 )
return - V_92 ;
V_2 -> V_5 = F_54 ( & V_81 -> V_14 , V_88 -> V_93 ,
F_55 ( V_88 ) ) ;
if ( ! V_2 -> V_5 )
return - V_48 ;
V_90 = & V_94 ;
V_90 -> V_18 = F_56 ( & V_81 -> V_14 ) ;
V_90 -> V_26 = V_17 -> V_26 ;
V_90 -> V_27 = V_17 -> V_27 ;
V_72 = F_51 ( V_81 , V_2 , V_17 ) ;
if ( V_72 ) {
F_19 ( & V_81 -> V_14 , L_17 ) ;
return V_72 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_14 = V_17 -> V_14 ;
F_57 ( V_81 , V_2 ) ;
V_2 -> V_82 = F_58 ( V_90 , & V_81 -> V_14 , V_2 ) ;
if ( F_59 ( V_2 -> V_82 ) ) {
F_19 ( & V_81 -> V_14 , L_18 ) ;
return F_60 ( V_2 -> V_82 ) ;
}
V_72 = F_61 ( V_81 -> V_14 . V_83 , NULL , NULL , & V_81 -> V_14 ) ;
if ( V_72 ) {
F_62 ( V_2 -> V_82 ) ;
F_19 ( & V_81 -> V_14 , L_19 ) ;
return V_72 ;
}
F_63 ( & V_81 -> V_14 , L_20 ) ;
return 0 ;
}
int F_64 ( struct V_80 * V_81 )
{
struct V_1 * V_2 = F_65 ( V_81 ) ;
F_62 ( V_2 -> V_82 ) ;
return 0 ;
}
