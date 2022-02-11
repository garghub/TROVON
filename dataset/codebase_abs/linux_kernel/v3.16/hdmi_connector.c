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
L_6 , V_6 -> V_14 , V_7 ) ;
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
F_6 ( L_7 ) ;
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
F_6 ( L_8 ) ;
}
return 0 ;
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
static int F_8 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = V_18 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_3 * V_4 = V_18 -> V_19 . V_4 ;
struct V_20 * V_21 = V_1 -> V_21 ;
T_1 V_22 ;
int V_23 , V_7 ;
V_7 = F_1 ( V_1 , true ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_9 , V_7 ) ;
goto V_24;
}
for ( V_23 = 0 ; V_23 < V_6 -> V_25 ; V_23 ++ ) {
if ( V_6 -> V_26 && V_6 -> V_26 [ V_23 ] ) {
V_7 = F_9 ( V_1 -> V_27 [ V_23 ] ,
V_6 -> V_26 [ V_23 ] ) ;
if ( V_7 )
F_10 ( V_4 -> V_4 , L_10 ,
V_6 -> V_28 [ V_23 ] , V_7 ) ;
}
V_7 = F_11 ( V_1 -> V_27 [ V_23 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_11 ,
V_6 -> V_28 [ V_23 ] , V_7 ) ;
goto V_24;
}
}
for ( V_23 = 0 ; V_23 < V_6 -> V_29 ; V_23 ++ ) {
V_7 = F_12 ( V_1 -> V_30 [ V_23 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_12 ,
V_6 -> V_31 [ V_23 ] , V_7 ) ;
goto V_24;
}
}
F_13 ( V_1 , false ) ;
V_21 -> V_32 -> V_33 ( V_21 ) ;
F_13 ( V_1 , true ) ;
F_14 ( V_1 , V_34 , 0x0001001b ) ;
F_14 ( V_1 , V_35 ,
V_36 |
V_37 ) ;
V_22 = F_15 ( V_1 , V_38 ) ;
V_22 |= F_16 ( 0x1fff ) ;
F_14 ( V_1 , V_38 ,
~ V_39 & V_22 ) ;
F_14 ( V_1 , V_38 ,
V_39 | V_22 ) ;
return 0 ;
V_24:
return V_7 ;
}
static int F_17 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = V_18 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_3 * V_4 = V_18 -> V_19 . V_4 ;
int V_23 , V_7 = 0 ;
F_14 ( V_1 , V_35 , 0 ) ;
F_13 ( V_1 , false ) ;
for ( V_23 = 0 ; V_23 < V_6 -> V_29 ; V_23 ++ ) {
V_7 = F_18 ( V_1 -> V_30 [ V_23 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_13 ,
V_6 -> V_31 [ V_23 ] , V_7 ) ;
goto V_24;
}
}
for ( V_23 = 0 ; V_23 < V_6 -> V_25 ; V_23 ++ )
F_19 ( V_1 -> V_27 [ V_23 ] ) ;
V_7 = F_1 ( V_1 , false ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_14 , V_7 ) ;
goto V_24;
}
return 0 ;
V_24:
return V_7 ;
}
static void
F_20 ( struct V_40 * V_41 )
{
struct V_18 * V_18 =
F_21 ( V_41 , struct V_18 , V_42 ) ;
struct V_43 * V_44 = & V_18 -> V_19 ;
F_22 ( V_44 -> V_4 ) ;
}
void F_23 ( struct V_43 * V_44 )
{
struct V_18 * V_18 = F_24 ( V_44 ) ;
struct V_45 * V_46 = V_44 -> V_4 -> V_47 ;
struct V_1 * V_1 = V_18 -> V_1 ;
T_1 V_48 , V_49 ;
V_48 = F_15 ( V_1 , V_50 ) ;
V_49 = F_15 ( V_1 , V_35 ) ;
if ( ( V_49 & V_37 ) &&
( V_48 & V_51 ) ) {
bool V_52 = ! ! ( V_48 & V_53 ) ;
F_6 ( L_15 , V_48 , V_49 ) ;
F_14 ( V_1 , V_35 ,
V_49 | V_54 ) ;
V_49 = V_37 ;
if ( ! V_52 )
V_49 |= V_36 ;
F_14 ( V_1 , V_35 , V_49 ) ;
F_25 ( V_46 -> V_55 , & V_18 -> V_42 ) ;
}
}
static enum V_56 F_26 ( struct V_1 * V_1 )
{
T_1 V_48 = F_15 ( V_1 , V_50 ) ;
return ( V_48 & V_53 ) ?
V_57 : V_58 ;
}
static enum V_56 F_27 ( struct V_1 * V_1 )
{
const struct V_5 * V_6 = V_1 -> V_6 ;
return F_28 ( V_6 -> V_12 ) ?
V_57 :
V_58 ;
}
static enum V_56 F_29 (
struct V_43 * V_44 , bool V_59 )
{
struct V_18 * V_18 = F_24 ( V_44 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
enum V_56 V_60 , V_61 ;
int V_62 = 20 ;
do {
V_60 = F_27 ( V_1 ) ;
V_61 = F_26 ( V_1 ) ;
if ( V_60 == V_61 )
break;
F_30 ( 10 ) ;
} while ( -- V_62 );
if ( V_60 != V_61 ) {
F_6 ( L_16 , V_61 ) ;
F_6 ( L_17 , V_60 ) ;
}
return V_60 ;
}
static void F_31 ( struct V_43 * V_44 )
{
struct V_18 * V_18 = F_24 ( V_44 ) ;
F_17 ( V_18 ) ;
F_32 ( V_44 ) ;
F_33 ( V_44 ) ;
F_34 ( V_18 -> V_1 ) ;
F_35 ( V_18 ) ;
}
static int F_36 ( struct V_43 * V_44 )
{
struct V_18 * V_18 = F_24 ( V_44 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
struct V_63 * V_63 ;
T_1 V_64 ;
int V_7 = 0 ;
V_64 = F_15 ( V_1 , V_65 ) ;
F_14 ( V_1 , V_65 , V_64 | V_66 ) ;
V_63 = F_37 ( V_44 , V_1 -> V_67 ) ;
F_14 ( V_1 , V_65 , V_64 ) ;
F_38 ( V_44 , V_63 ) ;
if ( V_63 ) {
V_7 = F_39 ( V_44 , V_63 ) ;
F_35 ( V_63 ) ;
}
return V_7 ;
}
static int F_40 ( struct V_43 * V_44 ,
struct V_68 * V_69 )
{
struct V_18 * V_18 = F_24 ( V_44 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_45 * V_46 = V_44 -> V_4 -> V_47 ;
struct V_70 * V_71 = V_46 -> V_71 ;
long V_72 , V_73 ;
V_73 = 1000 * V_69 -> clock ;
V_72 = V_71 -> V_32 -> V_74 ( V_71 ,
V_73 , V_18 -> V_1 -> V_75 ) ;
if ( V_6 -> V_76 > 0 )
V_72 = F_41 ( V_1 -> V_77 [ 0 ] , V_72 ) ;
F_6 ( L_18 , V_73 , V_72 ) ;
if ( V_72 != V_73 )
return V_78 ;
return 0 ;
}
static struct V_79 *
F_42 ( struct V_43 * V_44 )
{
struct V_18 * V_18 = F_24 ( V_44 ) ;
return V_18 -> V_1 -> V_75 ;
}
struct V_43 * F_43 ( struct V_1 * V_1 )
{
struct V_43 * V_44 = NULL ;
struct V_18 * V_18 ;
int V_7 ;
V_18 = F_44 ( sizeof( * V_18 ) , V_80 ) ;
if ( ! V_18 ) {
V_7 = - V_81 ;
goto V_24;
}
V_18 -> V_1 = F_45 ( V_1 ) ;
F_46 ( & V_18 -> V_42 , F_20 ) ;
V_44 = & V_18 -> V_19 ;
F_47 ( V_1 -> V_4 , V_44 , & V_82 ,
V_83 ) ;
F_48 ( V_44 , & V_84 ) ;
V_44 -> V_85 = V_86 |
V_87 ;
V_44 -> V_88 = 1 ;
V_44 -> V_89 = 0 ;
F_49 ( V_44 ) ;
V_7 = F_8 ( V_18 ) ;
if ( V_7 ) {
F_3 ( V_1 -> V_4 -> V_4 , L_19 , V_7 ) ;
goto V_24;
}
F_50 ( V_44 , V_1 -> V_75 ) ;
return V_44 ;
V_24:
if ( V_44 )
F_31 ( V_44 ) ;
return F_51 ( V_7 ) ;
}
