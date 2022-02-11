static int F_1 ( struct V_1 * V_1 , unsigned int V_2 , T_1 * V_3 )
{
int V_4 , V_5 ;
for ( V_5 = 0 ; V_5 < 5 ; V_5 ++ ) {
V_4 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( ! V_4 )
return 0 ;
if ( V_4 != - V_6 )
break;
F_3 ( 500 ) ;
}
return - V_7 ;
}
static int F_4 ( struct V_8 * V_9 , int V_10 )
{
int V_4 ;
T_1 V_11 ;
if ( V_10 > V_12 )
return - V_13 ;
V_4 = F_1 ( V_9 -> V_1 , V_14 + V_10 , & V_11 ) ;
if ( V_4 )
return V_4 ;
return V_11 & 0xffff ;
}
static int F_5 ( struct V_8 * V_9 , int V_10 , T_2 V_11 )
{
if ( V_10 > V_12 )
return - V_13 ;
return F_6 ( V_9 -> V_1 , V_14 + V_10 , V_11 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
int V_4 , V_5 ;
T_1 V_3 ;
for ( V_5 = 0 ; V_5 < 25 ; V_5 ++ ) {
V_4 = F_1 ( V_9 -> V_1 , V_15 , & V_3 ) ;
if ( V_4 ) {
F_8 ( V_9 -> V_16 ,
L_1 , V_4 ) ;
return V_4 ;
}
if ( ! ( V_3 & V_17 ) )
return 0 ;
F_3 ( 1 ) ;
}
return - V_7 ;
}
static int F_9 ( struct V_8 * V_9 , int V_18 , int V_10 )
{
int V_4 ;
T_1 V_11 ;
V_11 = F_10 ( V_18 ) ;
V_11 |= F_11 ( V_10 ) ;
F_12 ( & V_9 -> V_19 ) ;
V_4 = F_7 ( V_9 ) ;
if ( V_4 )
goto V_20;
V_4 = F_6 ( V_9 -> V_1 , V_15 , V_11 ) ;
if ( V_4 )
goto V_20;
V_4 = F_7 ( V_9 ) ;
if ( V_4 )
goto V_20;
V_4 = F_1 ( V_9 -> V_1 , V_21 , & V_11 ) ;
if ( V_4 )
goto V_20;
F_13 ( & V_9 -> V_19 ) ;
return V_11 & 0xffff ;
V_20:
F_13 ( & V_9 -> V_19 ) ;
return V_4 ;
}
static int F_14 ( struct V_8 * V_9 , int V_18 ,
int V_10 , T_2 V_11 )
{
int V_4 ;
T_1 V_3 ;
V_3 = F_10 ( V_18 ) ;
V_3 |= F_11 ( V_10 ) ;
V_3 |= V_22 ;
F_12 ( & V_9 -> V_19 ) ;
V_4 = F_7 ( V_9 ) ;
if ( V_4 )
goto V_20;
V_4 = F_6 ( V_9 -> V_1 , V_21 , V_11 ) ;
if ( V_4 )
goto V_20;
V_4 = F_6 ( V_9 -> V_1 , V_15 , V_3 ) ;
V_20:
F_13 ( & V_9 -> V_19 ) ;
return V_4 ;
}
static int F_15 ( struct V_8 * V_9 )
{
int V_4 , V_5 ;
T_1 V_3 ;
for ( V_5 = 0 ; V_5 < 25 ; V_5 ++ ) {
V_4 = F_1 ( V_9 -> V_1 , V_23 , & V_3 ) ;
if ( V_4 ) {
F_8 ( V_9 -> V_16 ,
L_2 , V_4 ) ;
return V_4 ;
}
if ( ! ( V_3 & V_24 ) )
return 0 ;
F_3 ( 1 ) ;
}
return - V_7 ;
}
static int F_16 ( struct V_8 * V_9 , T_2 V_10 , T_1 V_11 )
{
T_1 V_3 ;
int V_4 ;
V_3 = V_10 ;
V_3 |= V_25 ;
V_3 |= V_24 ;
F_12 ( & V_9 -> V_19 ) ;
V_4 = F_15 ( V_9 ) ;
if ( V_4 )
goto V_20;
V_4 = F_6 ( V_9 -> V_1 , V_26 , V_11 ) ;
if ( V_4 ) {
F_8 ( V_9 -> V_16 , L_3 , V_4 ) ;
goto V_20;
}
V_4 = F_6 ( V_9 -> V_1 , V_23 , V_3 ) ;
if ( V_4 )
F_8 ( V_9 -> V_16 , L_4 ,
V_4 ) ;
V_20:
F_13 ( & V_9 -> V_19 ) ;
return V_4 ;
}
static int F_17 ( struct V_8 * V_9 , T_2 V_10 , T_1 * V_11 )
{
T_1 V_3 ;
int V_4 ;
V_3 = V_10 ;
V_3 |= V_25 ;
V_3 |= V_27 ;
V_3 |= V_24 ;
F_12 ( & V_9 -> V_19 ) ;
V_4 = F_15 ( V_9 ) ;
if ( V_4 )
goto V_20;
V_4 = F_6 ( V_9 -> V_1 , V_23 , V_3 ) ;
if ( V_4 ) {
F_8 ( V_9 -> V_16 , L_4 ,
V_4 ) ;
goto V_20;
}
V_4 = F_15 ( V_9 ) ;
if ( V_4 )
goto V_20;
V_4 = F_1 ( V_9 -> V_1 , V_26 , V_11 ) ;
if ( V_4 )
F_8 ( V_9 -> V_16 , L_5 , V_4 ) ;
V_20:
F_13 ( & V_9 -> V_19 ) ;
return V_4 ;
}
static int F_18 ( struct V_8 * V_9 , int V_28 ,
T_2 V_10 , T_1 V_11 )
{
return F_16 (
V_9 , F_19 ( V_28 , V_10 ) , V_11 ) ;
}
static int F_20 ( struct V_8 * V_9 , int V_28 ,
T_2 V_10 , T_1 * V_11 )
{
return F_17 (
V_9 , F_19 ( V_28 , V_10 ) , V_11 ) ;
}
static int F_21 ( struct V_8 * V_9 )
{
int V_3 ;
V_3 = V_9 -> V_29 -> V_30 ( V_9 , 3 , V_31 ) ;
if ( V_3 < 0 ) {
F_8 ( V_9 -> V_16 , L_6 , V_3 ) ;
return V_3 ;
}
if ( ( V_3 != 0 ) && ( V_3 != 0xffff ) )
V_9 -> V_32 = 1 ;
else
V_9 -> V_32 = 0 ;
F_22 ( V_9 -> V_16 , L_7 ,
V_9 -> V_32 ? L_8 : L_9 ) ;
return 0 ;
}
static int F_23 ( struct V_8 * V_9 ,
unsigned int V_28 )
{
int V_4 ;
V_4 = F_18 ( V_9 , V_28 , V_33 ,
V_34 ) ;
if ( V_4 )
return V_4 ;
return F_18 ( V_9 , V_28 , V_35 ,
V_36 |
V_37 ) ;
}
static int F_24 ( struct V_8 * V_9 ,
unsigned int V_28 )
{
int V_4 ;
V_4 = F_18 ( V_9 , V_28 , V_33 ,
V_34 |
V_38 ) ;
if ( V_4 )
return V_4 ;
return F_18 ( V_9 , V_28 , V_35 ,
V_36 |
V_37 |
V_39 ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
int V_4 ;
V_4 = F_16 ( V_9 , V_40 ,
V_41 |
V_42 |
V_43 |
V_44 |
V_45 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_16 ( V_9 , V_46 ,
0x03 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_16 ( V_9 , V_47 ,
V_48 ) ;
if ( V_4 )
return V_4 ;
return F_16 ( V_9 , V_49 ,
V_50 |
V_51 |
V_52 ) ;
}
static int F_26 ( struct V_8 * V_9 )
{
if ( ! V_9 -> V_53 )
return 0 ;
if ( V_9 -> V_54 != 0 )
F_3 ( V_9 -> V_54 ) ;
F_27 ( V_9 -> V_53 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_8 * V_9 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
int V_4 = F_23 ( V_9 , V_55 ) ;
if ( V_4 )
return V_4 ;
}
return 0 ;
}
static int F_29 ( struct V_8 * V_9 )
{
int V_4 ;
T_1 V_3 ;
V_4 = F_1 ( V_9 -> V_1 , V_57 , & V_3 ) ;
if ( V_4 ) {
F_8 ( V_9 -> V_16 , L_10 ,
V_4 ) ;
if ( ! V_9 -> V_53 ) {
F_22 ( V_9 -> V_16 ,
L_11 ) ;
}
return V_4 ;
}
if ( ( V_3 >> 16 ) != V_58 ) {
F_8 ( V_9 -> V_16 , L_12 ,
V_3 >> 16 ) ;
return V_4 ;
}
V_4 = F_28 ( V_9 ) ;
if ( V_4 )
F_30 ( V_9 -> V_16 , L_13 , V_4 ) ;
F_31 ( V_9 -> V_16 , L_14 , V_3 & 0xffff ) ;
V_4 = F_21 ( V_9 ) ;
if ( V_4 ) {
F_8 ( V_9 -> V_16 ,
L_15 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
static enum V_59 F_32 ( struct V_60 * V_61 )
{
return V_62 ;
}
static int F_33 ( struct V_60 * V_61 )
{
struct V_8 * V_9 = V_61 -> V_63 ;
int V_4 ;
if ( ! F_34 ( V_61 , 0 ) ) {
F_8 ( V_9 -> V_16 , L_16 ) ;
return - V_13 ;
}
V_4 = F_25 ( V_9 ) ;
if ( V_4 )
F_8 ( V_9 -> V_16 , L_17 , V_4 ) ;
V_4 = F_24 ( V_9 , 0 ) ;
if ( V_4 )
F_8 ( V_9 -> V_16 , L_18 , V_4 ) ;
return 0 ;
}
static void F_35 ( struct V_60 * V_61 , int V_28 , T_3 * V_64 )
{
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < F_36 ( V_66 ) ; V_65 ++ ) {
strncpy ( V_64 + V_65 * V_67 , V_66 [ V_65 ] . V_68 ,
V_67 ) ;
}
}
static void F_37 ( struct V_60 * V_61 , int V_28 ,
T_4 * V_64 )
{
struct V_8 * V_9 = V_61 -> V_63 ;
unsigned int V_65 ;
for ( V_65 = 0 ; V_65 < F_36 ( V_66 ) ; V_65 ++ ) {
T_1 V_3 ;
int V_4 ;
V_4 = F_20 (
V_9 , V_28 , V_66 [ V_65 ] . V_2 , & V_3 ) ;
if ( V_4 )
F_30 ( V_9 -> V_16 , L_19 ,
V_28 , V_66 [ V_65 ] . V_2 ) ;
V_64 [ V_65 ] = V_3 ;
}
}
static int F_38 ( struct V_60 * V_61 )
{
return F_36 ( V_66 ) ;
}
static int F_39 ( struct V_60 * V_61 , int V_69 , int V_10 )
{
struct V_8 * V_9 = V_61 -> V_63 ;
int V_70 = V_9 -> V_32 ;
if ( V_69 == V_70 )
return F_4 ( V_9 , V_10 ) ;
if ( V_69 > V_70 + 2 )
return - V_71 ;
return V_9 -> V_29 -> V_30 ( V_9 , V_69 , V_10 ) ;
}
static int F_40 ( struct V_60 * V_61 , int V_69 , int V_10 ,
T_2 V_11 )
{
struct V_8 * V_9 = V_61 -> V_63 ;
int V_70 = V_9 -> V_32 ;
if ( V_69 == V_70 )
return F_5 ( V_9 , V_10 , V_11 ) ;
if ( V_69 > V_70 + 2 )
return - V_71 ;
return V_9 -> V_29 -> V_72 ( V_9 , V_69 , V_10 , V_11 ) ;
}
static int F_41 ( struct V_60 * V_61 , int V_28 ,
struct V_73 * V_69 )
{
struct V_8 * V_9 = V_61 -> V_63 ;
switch ( V_28 ) {
case 1 :
case 2 :
return F_24 ( V_9 , V_28 ) ;
default:
F_22 ( V_9 -> V_16 ,
L_20 , V_28 ) ;
}
return - V_71 ;
}
static void F_42 ( struct V_60 * V_61 , int V_28 ,
struct V_73 * V_69 )
{
struct V_8 * V_9 = V_61 -> V_63 ;
switch ( V_28 ) {
case 1 :
case 2 :
F_23 ( V_9 , V_28 ) ;
F_40 ( V_61 , V_9 -> V_32 + V_28 ,
V_74 , V_75 ) ;
break;
default:
F_22 ( V_9 -> V_16 ,
L_21 , V_28 ) ;
}
}
static int F_43 ( struct V_8 * V_9 )
{
V_9 -> V_61 = F_44 ( V_9 -> V_16 , V_56 ) ;
if ( ! V_9 -> V_61 )
return - V_76 ;
V_9 -> V_61 -> V_63 = V_9 ;
V_9 -> V_61 -> V_29 = & V_77 ;
V_9 -> V_61 -> V_78 = V_9 -> V_32 ? 0xe : 0x7 ;
return F_45 ( V_9 -> V_61 ) ;
}
static void F_46 ( struct V_8 * V_9 ,
struct V_79 * V_80 )
{
V_9 -> V_53 = F_47 ( V_9 -> V_16 , L_22 ,
V_81 ) ;
if ( ! V_9 -> V_53 ) {
F_22 ( V_9 -> V_16 , L_23 ) ;
return;
}
V_9 -> V_54 = 200 ;
if ( V_80 ) {
F_48 ( V_80 , L_24 ,
& V_9 -> V_54 ) ;
} else {
F_22 ( V_9 -> V_16 , L_25 ) ;
}
if ( V_9 -> V_54 > 1000 )
V_9 -> V_54 = 1000 ;
}
int F_49 ( struct V_8 * V_9 , struct V_79 * V_80 )
{
int V_4 ;
F_50 ( & V_9 -> V_19 ) ;
F_46 ( V_9 , V_80 ) ;
V_4 = F_26 ( V_9 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_29 ( V_9 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_43 ( V_9 ) ;
if ( V_4 ) {
F_22 ( V_9 -> V_16 , L_26 , V_4 ) ;
return V_4 ;
}
return 0 ;
}
int F_51 ( struct V_8 * V_9 )
{
int V_82 ;
V_82 = F_28 ( V_9 ) ;
if ( V_82 != 0 )
F_30 ( V_9 -> V_16 , L_27 ) ;
F_52 ( V_9 -> V_61 ) ;
F_27 ( V_9 -> V_53 , 1 ) ;
F_53 ( V_9 -> V_53 ) ;
return 0 ;
}
