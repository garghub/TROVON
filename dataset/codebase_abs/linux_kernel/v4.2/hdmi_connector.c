static int F_1 ( struct V_1 * V_1 , bool V_2 )
{
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
const struct V_6 * V_7 = V_1 -> V_7 ;
int V_8 ;
if ( V_2 ) {
V_8 = F_2 ( V_7 -> V_9 , L_1 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_2 ,
L_1 , V_7 -> V_9 , V_8 ) ;
goto V_10;
}
F_4 ( V_7 -> V_9 , 1 ) ;
V_8 = F_2 ( V_7 -> V_11 , L_3 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_2 ,
L_3 , V_7 -> V_11 , V_8 ) ;
goto V_12;
}
F_4 ( V_7 -> V_11 , 1 ) ;
V_8 = F_2 ( V_7 -> V_13 , L_4 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_2 ,
L_4 , V_7 -> V_13 , V_8 ) ;
goto V_14;
}
F_5 ( V_7 -> V_13 ) ;
F_4 ( V_7 -> V_13 , 1 ) ;
if ( V_7 -> V_15 != - 1 ) {
V_8 = F_2 ( V_7 -> V_15 , L_5 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_2 ,
L_5 , V_7 -> V_15 , V_8 ) ;
goto V_16;
}
F_4 ( V_7 -> V_15 , 1 ) ;
}
if ( V_7 -> V_17 != - 1 ) {
V_8 = F_2 ( V_7 -> V_17 , L_6 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_2 ,
L_6 , V_7 -> V_17 , V_8 ) ;
goto V_18;
}
F_4 ( V_7 -> V_17 , 0 ) ;
}
if ( V_7 -> V_19 != - 1 ) {
V_8 = F_2 ( V_7 -> V_19 ,
L_7 ) ;
if ( V_8 ) {
F_3 ( V_4 ,
L_2 ,
L_7 ,
V_7 -> V_19 , V_8 ) ;
goto V_20;
}
F_4 ( V_7 -> V_19 , 1 ) ;
}
F_6 ( L_8 ) ;
} else {
F_7 ( V_7 -> V_9 ) ;
F_7 ( V_7 -> V_11 ) ;
F_7 ( V_7 -> V_13 ) ;
if ( V_7 -> V_15 != - 1 ) {
F_4 ( V_7 -> V_15 , 0 ) ;
F_7 ( V_7 -> V_15 ) ;
}
if ( V_7 -> V_17 != - 1 ) {
F_4 ( V_7 -> V_17 , 1 ) ;
F_7 ( V_7 -> V_17 ) ;
}
if ( V_7 -> V_19 != - 1 ) {
F_4 ( V_7 -> V_19 , 0 ) ;
F_7 ( V_7 -> V_19 ) ;
}
F_6 ( L_9 ) ;
}
return 0 ;
V_20:
if ( V_7 -> V_17 != - 1 )
F_7 ( V_7 -> V_17 ) ;
V_18:
if ( V_7 -> V_15 != - 1 )
F_7 ( V_7 -> V_15 ) ;
V_16:
F_7 ( V_7 -> V_13 ) ;
V_14:
F_7 ( V_7 -> V_11 ) ;
V_12:
F_7 ( V_7 -> V_9 ) ;
V_10:
return V_8 ;
}
static int F_8 ( struct V_21 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
const struct V_6 * V_7 = V_1 -> V_7 ;
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
struct V_22 * V_23 = V_1 -> V_23 ;
T_1 V_24 ;
int V_25 , V_8 ;
for ( V_25 = 0 ; V_25 < V_7 -> V_26 ; V_25 ++ ) {
V_8 = F_9 ( V_1 -> V_27 [ V_25 ] ) ;
if ( V_8 ) {
F_3 ( V_4 , L_10 ,
V_7 -> V_28 [ V_25 ] , V_8 ) ;
goto V_29;
}
}
V_8 = F_10 ( V_4 ) ;
if ( V_8 ) {
F_3 ( V_4 , L_11 , V_8 ) ;
goto V_29;
}
V_8 = F_1 ( V_1 , true ) ;
if ( V_8 ) {
F_3 ( V_4 , L_12 , V_8 ) ;
goto V_29;
}
for ( V_25 = 0 ; V_25 < V_7 -> V_30 ; V_25 ++ ) {
if ( V_7 -> V_31 && V_7 -> V_31 [ V_25 ] ) {
V_8 = F_11 ( V_1 -> V_32 [ V_25 ] ,
V_7 -> V_31 [ V_25 ] ) ;
if ( V_8 )
F_12 ( V_4 , L_13 ,
V_7 -> V_33 [ V_25 ] , V_8 ) ;
}
V_8 = F_13 ( V_1 -> V_32 [ V_25 ] ) ;
if ( V_8 ) {
F_3 ( V_4 , L_14 ,
V_7 -> V_33 [ V_25 ] , V_8 ) ;
goto V_29;
}
}
F_14 ( V_1 , false ) ;
V_23 -> V_34 -> V_35 ( V_23 ) ;
F_14 ( V_1 , true ) ;
F_15 ( V_1 , V_36 , 0x0001001b ) ;
F_15 ( V_1 , V_37 ,
V_38 |
V_39 ) ;
V_24 = F_16 ( V_1 , V_40 ) ;
V_24 |= F_17 ( 0x1fff ) ;
F_15 ( V_1 , V_40 ,
~ V_41 & V_24 ) ;
F_15 ( V_1 , V_40 ,
V_41 | V_24 ) ;
return 0 ;
V_29:
return V_8 ;
}
static void F_18 ( struct V_21 * V_21 )
{
struct V_1 * V_1 = V_21 -> V_1 ;
const struct V_6 * V_7 = V_1 -> V_7 ;
struct V_3 * V_4 = & V_1 -> V_5 -> V_4 ;
int V_25 , V_8 = 0 ;
F_15 ( V_1 , V_37 , 0 ) ;
F_14 ( V_1 , false ) ;
for ( V_25 = 0 ; V_25 < V_7 -> V_30 ; V_25 ++ )
F_19 ( V_1 -> V_32 [ V_25 ] ) ;
V_8 = F_1 ( V_1 , false ) ;
if ( V_8 )
F_12 ( V_4 , L_15 , V_8 ) ;
V_8 = F_20 ( V_4 ) ;
if ( V_8 )
F_12 ( V_4 , L_11 , V_8 ) ;
for ( V_25 = 0 ; V_25 < V_7 -> V_26 ; V_25 ++ ) {
V_8 = F_21 ( V_1 -> V_27 [ V_25 ] ) ;
if ( V_8 )
F_12 ( V_4 , L_16 ,
V_7 -> V_28 [ V_25 ] , V_8 ) ;
}
}
static void
F_22 ( struct V_42 * V_43 )
{
struct V_21 * V_21 =
F_23 ( V_43 , struct V_21 , V_44 ) ;
struct V_45 * V_46 = & V_21 -> V_47 ;
F_24 ( V_46 -> V_4 ) ;
}
void F_25 ( struct V_45 * V_46 )
{
struct V_21 * V_21 = F_26 ( V_46 ) ;
struct V_48 * V_49 = V_46 -> V_4 -> V_50 ;
struct V_1 * V_1 = V_21 -> V_1 ;
T_1 V_51 , V_52 ;
V_51 = F_16 ( V_1 , V_53 ) ;
V_52 = F_16 ( V_1 , V_37 ) ;
if ( ( V_52 & V_39 ) &&
( V_51 & V_54 ) ) {
bool V_55 = ! ! ( V_51 & V_56 ) ;
F_15 ( V_1 , V_37 ,
V_57 ) ;
F_6 ( L_17 , V_51 , V_52 ) ;
V_52 = V_39 ;
if ( ! V_55 )
V_52 |= V_38 ;
F_15 ( V_1 , V_37 , V_52 ) ;
F_27 ( V_49 -> V_58 , & V_21 -> V_44 ) ;
}
}
static enum V_59 F_28 ( struct V_1 * V_1 )
{
T_1 V_51 = F_16 ( V_1 , V_53 ) ;
return ( V_51 & V_56 ) ?
V_60 : V_61 ;
}
static enum V_59 F_29 ( struct V_1 * V_1 )
{
const struct V_6 * V_7 = V_1 -> V_7 ;
return F_30 ( V_7 -> V_13 ) ?
V_60 :
V_61 ;
}
static enum V_59 F_31 (
struct V_45 * V_46 , bool V_62 )
{
struct V_21 * V_21 = F_26 ( V_46 ) ;
struct V_1 * V_1 = V_21 -> V_1 ;
enum V_59 V_63 , V_64 ;
int V_65 = 20 ;
do {
V_63 = F_29 ( V_1 ) ;
V_64 = F_28 ( V_1 ) ;
if ( V_63 == V_64 )
break;
F_32 ( 10 ) ;
} while ( -- V_65 );
if ( V_63 != V_64 ) {
F_6 ( L_18 , V_64 ) ;
F_6 ( L_19 , V_63 ) ;
}
return V_63 ;
}
static void F_33 ( struct V_45 * V_46 )
{
struct V_21 * V_21 = F_26 ( V_46 ) ;
F_18 ( V_21 ) ;
F_34 ( V_46 ) ;
F_35 ( V_46 ) ;
F_36 ( V_21 ) ;
}
static int F_37 ( struct V_45 * V_46 )
{
struct V_21 * V_21 = F_26 ( V_46 ) ;
struct V_1 * V_1 = V_21 -> V_1 ;
struct V_66 * V_66 ;
T_1 V_67 ;
int V_8 = 0 ;
V_67 = F_16 ( V_1 , V_68 ) ;
F_15 ( V_1 , V_68 , V_67 | V_69 ) ;
V_66 = F_38 ( V_46 , V_1 -> V_70 ) ;
F_15 ( V_1 , V_68 , V_67 ) ;
F_39 ( V_46 , V_66 ) ;
if ( V_66 ) {
V_8 = F_40 ( V_46 , V_66 ) ;
F_36 ( V_66 ) ;
}
return V_8 ;
}
static int F_41 ( struct V_45 * V_46 ,
struct V_71 * V_72 )
{
struct V_21 * V_21 = F_26 ( V_46 ) ;
struct V_1 * V_1 = V_21 -> V_1 ;
const struct V_6 * V_7 = V_1 -> V_7 ;
struct V_48 * V_49 = V_46 -> V_4 -> V_50 ;
struct V_73 * V_74 = V_49 -> V_74 ;
long V_75 , V_76 ;
V_76 = 1000 * V_72 -> clock ;
V_75 = V_74 -> V_34 -> V_77 ( V_74 ,
V_76 , V_21 -> V_1 -> V_78 ) ;
if ( V_7 -> V_79 > 0 )
V_75 = F_42 ( V_1 -> V_80 [ 0 ] , V_75 ) ;
F_6 ( L_20 , V_76 , V_75 ) ;
if ( V_75 != V_76 )
return V_81 ;
return 0 ;
}
static struct V_82 *
F_43 ( struct V_45 * V_46 )
{
struct V_21 * V_21 = F_26 ( V_46 ) ;
return V_21 -> V_1 -> V_78 ;
}
struct V_45 * F_44 ( struct V_1 * V_1 )
{
struct V_45 * V_46 = NULL ;
struct V_21 * V_21 ;
int V_8 ;
V_21 = F_45 ( sizeof( * V_21 ) , V_83 ) ;
if ( ! V_21 ) {
V_8 = - V_84 ;
goto V_29;
}
V_21 -> V_1 = V_1 ;
F_46 ( & V_21 -> V_44 , F_22 ) ;
V_46 = & V_21 -> V_47 ;
F_47 ( V_1 -> V_4 , V_46 , & V_85 ,
V_86 ) ;
F_48 ( V_46 , & V_87 ) ;
V_46 -> V_88 = V_89 |
V_90 ;
V_46 -> V_91 = 0 ;
V_46 -> V_92 = 0 ;
F_49 ( V_46 ) ;
V_8 = F_8 ( V_21 ) ;
if ( V_8 ) {
F_3 ( & V_1 -> V_5 -> V_4 , L_21 , V_8 ) ;
goto V_29;
}
F_50 ( V_46 , V_1 -> V_78 ) ;
return V_46 ;
V_29:
if ( V_46 )
F_33 ( V_46 ) ;
return F_51 ( V_8 ) ;
}
