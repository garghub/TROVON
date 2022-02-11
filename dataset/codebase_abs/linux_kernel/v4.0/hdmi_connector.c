static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
int V_7 ;
if ( V_2 ) {
V_7 = F_2 ( V_6 -> V_8 , L_1 ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_1 , V_6 -> V_8 , V_7 ) ;
goto V_9;
}
F_4 ( V_6 -> V_8 , 1 ) ;
V_7 = F_2 ( V_6 -> V_10 , L_3 ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_3 , V_6 -> V_10 , V_7 ) ;
goto V_11;
}
F_4 ( V_6 -> V_10 , 1 ) ;
V_7 = F_2 ( V_6 -> V_12 , L_4 ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_4 , V_6 -> V_12 , V_7 ) ;
goto V_13;
}
F_5 ( V_6 -> V_12 ) ;
F_4 ( V_6 -> V_12 , 1 ) ;
if ( V_6 -> V_14 != - 1 ) {
V_7 = F_2 ( V_6 -> V_14 , L_5 ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_5 , V_6 -> V_14 , V_7 ) ;
goto V_15;
}
F_4 ( V_6 -> V_14 , 1 ) ;
}
if ( V_6 -> V_16 != - 1 ) {
V_7 = F_2 ( V_6 -> V_16 , L_6 ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_2 ,
L_6 , V_6 -> V_16 , V_7 ) ;
goto V_17;
}
F_4 ( V_6 -> V_16 , 0 ) ;
}
if ( V_6 -> V_18 != - 1 ) {
V_7 = F_2 ( V_6 -> V_18 ,
L_7 ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 ,
L_2 ,
L_7 ,
V_6 -> V_18 , V_7 ) ;
goto V_19;
}
F_4 ( V_6 -> V_18 , 1 ) ;
}
F_6 ( L_8 ) ;
} else {
F_7 ( V_6 -> V_8 ) ;
F_7 ( V_6 -> V_10 ) ;
F_7 ( V_6 -> V_12 ) ;
if ( V_6 -> V_14 != - 1 ) {
F_4 ( V_6 -> V_14 , 0 ) ;
F_7 ( V_6 -> V_14 ) ;
}
if ( V_6 -> V_16 != - 1 ) {
F_4 ( V_6 -> V_16 , 1 ) ;
F_7 ( V_6 -> V_16 ) ;
}
if ( V_6 -> V_18 != - 1 ) {
F_4 ( V_6 -> V_18 , 0 ) ;
F_7 ( V_6 -> V_18 ) ;
}
F_6 ( L_9 ) ;
}
return 0 ;
V_19:
if ( V_6 -> V_16 != - 1 )
F_7 ( V_6 -> V_16 ) ;
V_17:
if ( V_6 -> V_14 != - 1 )
F_7 ( V_6 -> V_14 ) ;
V_15:
F_7 ( V_6 -> V_12 ) ;
V_13:
F_7 ( V_6 -> V_10 ) ;
V_11:
F_7 ( V_6 -> V_8 ) ;
V_9:
return V_7 ;
}
static int F_8 ( struct V_20 * V_20 )
{
struct V_1 * V_1 = V_20 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_3 * V_4 = V_20 -> V_21 . V_4 ;
struct V_22 * V_23 = V_1 -> V_23 ;
T_1 V_24 ;
int V_25 , V_7 ;
for ( V_25 = 0 ; V_25 < V_6 -> V_26 ; V_25 ++ ) {
V_7 = F_9 ( V_1 -> V_27 [ V_25 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_10 ,
V_6 -> V_28 [ V_25 ] , V_7 ) ;
goto V_29;
}
}
V_7 = F_1 ( V_1 , true ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_11 , V_7 ) ;
goto V_29;
}
for ( V_25 = 0 ; V_25 < V_6 -> V_30 ; V_25 ++ ) {
if ( V_6 -> V_31 && V_6 -> V_31 [ V_25 ] ) {
V_7 = F_10 ( V_1 -> V_32 [ V_25 ] ,
V_6 -> V_31 [ V_25 ] ) ;
if ( V_7 )
F_11 ( V_4 -> V_4 , L_12 ,
V_6 -> V_33 [ V_25 ] , V_7 ) ;
}
V_7 = F_12 ( V_1 -> V_32 [ V_25 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_13 ,
V_6 -> V_33 [ V_25 ] , V_7 ) ;
goto V_29;
}
}
F_13 ( V_1 , false ) ;
V_23 -> V_34 -> V_35 ( V_23 ) ;
F_13 ( V_1 , true ) ;
F_14 ( V_1 , V_36 , 0x0001001b ) ;
F_14 ( V_1 , V_37 ,
V_38 |
V_39 ) ;
V_24 = F_15 ( V_1 , V_40 ) ;
V_24 |= F_16 ( 0x1fff ) ;
F_14 ( V_1 , V_40 ,
~ V_41 & V_24 ) ;
F_14 ( V_1 , V_40 ,
V_41 | V_24 ) ;
return 0 ;
V_29:
return V_7 ;
}
static void F_17 ( struct V_20 * V_20 )
{
struct V_1 * V_1 = V_20 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_3 * V_4 = V_20 -> V_21 . V_4 ;
int V_25 , V_7 = 0 ;
F_14 ( V_1 , V_37 , 0 ) ;
F_13 ( V_1 , false ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_30 ; V_25 ++ )
F_18 ( V_1 -> V_32 [ V_25 ] ) ;
V_7 = F_1 ( V_1 , false ) ;
if ( V_7 )
F_11 ( V_4 -> V_4 , L_14 , V_7 ) ;
for ( V_25 = 0 ; V_25 < V_6 -> V_26 ; V_25 ++ ) {
V_7 = F_19 ( V_1 -> V_27 [ V_25 ] ) ;
if ( V_7 )
F_11 ( V_4 -> V_4 , L_15 ,
V_6 -> V_28 [ V_25 ] , V_7 ) ;
}
}
static void
F_20 ( struct V_42 * V_43 )
{
struct V_20 * V_20 =
F_21 ( V_43 , struct V_20 , V_44 ) ;
struct V_45 * V_46 = & V_20 -> V_21 ;
F_22 ( V_46 -> V_4 ) ;
}
void F_23 ( struct V_45 * V_46 )
{
struct V_20 * V_20 = F_24 ( V_46 ) ;
struct V_47 * V_48 = V_46 -> V_4 -> V_49 ;
struct V_1 * V_1 = V_20 -> V_1 ;
T_1 V_50 , V_51 ;
V_50 = F_15 ( V_1 , V_52 ) ;
V_51 = F_15 ( V_1 , V_37 ) ;
if ( ( V_51 & V_39 ) &&
( V_50 & V_53 ) ) {
bool V_54 = ! ! ( V_50 & V_55 ) ;
F_14 ( V_1 , V_37 ,
V_56 ) ;
F_6 ( L_16 , V_50 , V_51 ) ;
V_51 = V_39 ;
if ( ! V_54 )
V_51 |= V_38 ;
F_14 ( V_1 , V_37 , V_51 ) ;
F_25 ( V_48 -> V_57 , & V_20 -> V_44 ) ;
}
}
static enum V_58 F_26 ( struct V_1 * V_1 )
{
T_1 V_50 = F_15 ( V_1 , V_52 ) ;
return ( V_50 & V_55 ) ?
V_59 : V_60 ;
}
static enum V_58 F_27 ( struct V_1 * V_1 )
{
const struct V_5 * V_6 = V_1 -> V_6 ;
return F_28 ( V_6 -> V_12 ) ?
V_59 :
V_60 ;
}
static enum V_58 F_29 (
struct V_45 * V_46 , bool V_61 )
{
struct V_20 * V_20 = F_24 ( V_46 ) ;
struct V_1 * V_1 = V_20 -> V_1 ;
enum V_58 V_62 , V_63 ;
int V_64 = 20 ;
do {
V_62 = F_27 ( V_1 ) ;
V_63 = F_26 ( V_1 ) ;
if ( V_62 == V_63 )
break;
F_30 ( 10 ) ;
} while ( -- V_64 );
if ( V_62 != V_63 ) {
F_6 ( L_17 , V_63 ) ;
F_6 ( L_18 , V_62 ) ;
}
return V_62 ;
}
static void F_31 ( struct V_45 * V_46 )
{
struct V_20 * V_20 = F_24 ( V_46 ) ;
F_17 ( V_20 ) ;
F_32 ( V_46 ) ;
F_33 ( V_46 ) ;
F_34 ( V_20 ) ;
}
static int F_35 ( struct V_45 * V_46 )
{
struct V_20 * V_20 = F_24 ( V_46 ) ;
struct V_1 * V_1 = V_20 -> V_1 ;
struct V_65 * V_65 ;
T_1 V_66 ;
int V_7 = 0 ;
V_66 = F_15 ( V_1 , V_67 ) ;
F_14 ( V_1 , V_67 , V_66 | V_68 ) ;
V_65 = F_36 ( V_46 , V_1 -> V_69 ) ;
F_14 ( V_1 , V_67 , V_66 ) ;
F_37 ( V_46 , V_65 ) ;
if ( V_65 ) {
V_7 = F_38 ( V_46 , V_65 ) ;
F_34 ( V_65 ) ;
}
return V_7 ;
}
static int F_39 ( struct V_45 * V_46 ,
struct V_70 * V_71 )
{
struct V_20 * V_20 = F_24 ( V_46 ) ;
struct V_1 * V_1 = V_20 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_47 * V_48 = V_46 -> V_4 -> V_49 ;
struct V_72 * V_73 = V_48 -> V_73 ;
long V_74 , V_75 ;
V_75 = 1000 * V_71 -> clock ;
V_74 = V_73 -> V_34 -> V_76 ( V_73 ,
V_75 , V_20 -> V_1 -> V_77 ) ;
if ( V_6 -> V_78 > 0 )
V_74 = F_40 ( V_1 -> V_79 [ 0 ] , V_74 ) ;
F_6 ( L_19 , V_75 , V_74 ) ;
if ( V_74 != V_75 )
return V_80 ;
return 0 ;
}
static struct V_81 *
F_41 ( struct V_45 * V_46 )
{
struct V_20 * V_20 = F_24 ( V_46 ) ;
return V_20 -> V_1 -> V_77 ;
}
struct V_45 * F_42 ( struct V_1 * V_1 )
{
struct V_45 * V_46 = NULL ;
struct V_20 * V_20 ;
int V_7 ;
V_20 = F_43 ( sizeof( * V_20 ) , V_82 ) ;
if ( ! V_20 ) {
V_7 = - V_83 ;
goto V_29;
}
V_20 -> V_1 = V_1 ;
F_44 ( & V_20 -> V_44 , F_20 ) ;
V_46 = & V_20 -> V_21 ;
F_45 ( V_1 -> V_4 , V_46 , & V_84 ,
V_85 ) ;
F_46 ( V_46 , & V_86 ) ;
V_46 -> V_87 = V_88 |
V_89 ;
V_46 -> V_90 = 0 ;
V_46 -> V_91 = 0 ;
F_47 ( V_46 ) ;
V_7 = F_8 ( V_20 ) ;
if ( V_7 ) {
F_3 ( V_1 -> V_4 -> V_4 , L_20 , V_7 ) ;
goto V_29;
}
F_48 ( V_46 , V_1 -> V_77 ) ;
return V_46 ;
V_29:
if ( V_46 )
F_31 ( V_46 ) ;
return F_49 ( V_7 ) ;
}
