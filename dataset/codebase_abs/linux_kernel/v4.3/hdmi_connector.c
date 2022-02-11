static void F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
V_2 = F_2 ( V_1 , V_3 ) ;
if ( V_2 & V_4 ) {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_5 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 | V_5 ) ;
}
if ( V_2 & V_6 ) {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_7 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 | V_7 ) ;
}
F_4 ( 100 ) ;
if ( V_2 & V_4 ) {
F_3 ( V_1 , V_3 ,
V_2 | V_5 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_5 ) ;
}
if ( V_2 & V_6 ) {
F_3 ( V_1 , V_3 ,
V_2 | V_7 ) ;
} else {
F_3 ( V_1 , V_3 ,
V_2 & ~ V_7 ) ;
}
}
static int F_5 ( struct V_1 * V_1 , bool V_8 )
{
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
int V_14 ;
if ( V_8 ) {
if ( V_13 -> V_15 != - 1 ) {
V_14 = F_6 ( V_13 -> V_15 , L_1 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_2 ,
L_1 , V_13 -> V_15 , V_14 ) ;
goto V_16;
}
F_8 ( V_13 -> V_15 , 1 ) ;
}
if ( V_13 -> V_17 != - 1 ) {
V_14 = F_6 ( V_13 -> V_17 , L_3 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_2 ,
L_3 , V_13 -> V_17 , V_14 ) ;
goto V_18;
}
F_8 ( V_13 -> V_17 , 1 ) ;
}
V_14 = F_6 ( V_13 -> V_19 , L_4 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_2 ,
L_4 , V_13 -> V_19 , V_14 ) ;
goto V_20;
}
F_9 ( V_13 -> V_19 ) ;
F_8 ( V_13 -> V_19 , 1 ) ;
if ( V_13 -> V_21 != - 1 ) {
V_14 = F_6 ( V_13 -> V_21 , L_5 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_2 ,
L_5 , V_13 -> V_21 , V_14 ) ;
goto V_22;
}
F_8 ( V_13 -> V_21 , 1 ) ;
}
if ( V_13 -> V_23 != - 1 ) {
V_14 = F_6 ( V_13 -> V_23 , L_6 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_2 ,
L_6 , V_13 -> V_23 , V_14 ) ;
goto V_24;
}
F_8 ( V_13 -> V_23 , 0 ) ;
}
if ( V_13 -> V_25 != - 1 ) {
V_14 = F_6 ( V_13 -> V_25 ,
L_7 ) ;
if ( V_14 ) {
F_7 ( V_10 ,
L_2 ,
L_7 ,
V_13 -> V_25 , V_14 ) ;
goto V_26;
}
F_8 ( V_13 -> V_25 , 1 ) ;
}
F_10 ( L_8 ) ;
} else {
if ( V_13 -> V_15 != - 1 )
F_11 ( V_13 -> V_15 ) ;
if ( V_13 -> V_17 != - 1 )
F_11 ( V_13 -> V_17 ) ;
F_11 ( V_13 -> V_19 ) ;
if ( V_13 -> V_21 != - 1 ) {
F_8 ( V_13 -> V_21 , 0 ) ;
F_11 ( V_13 -> V_21 ) ;
}
if ( V_13 -> V_23 != - 1 ) {
F_8 ( V_13 -> V_23 , 1 ) ;
F_11 ( V_13 -> V_23 ) ;
}
if ( V_13 -> V_25 != - 1 ) {
F_8 ( V_13 -> V_25 , 0 ) ;
F_11 ( V_13 -> V_25 ) ;
}
F_10 ( L_9 ) ;
}
return 0 ;
V_26:
if ( V_13 -> V_23 != - 1 )
F_11 ( V_13 -> V_23 ) ;
V_24:
if ( V_13 -> V_21 != - 1 )
F_11 ( V_13 -> V_21 ) ;
V_22:
F_11 ( V_13 -> V_19 ) ;
V_20:
if ( V_13 -> V_17 != - 1 )
F_11 ( V_13 -> V_17 ) ;
V_18:
if ( V_13 -> V_15 != - 1 )
F_11 ( V_13 -> V_15 ) ;
V_16:
return V_14 ;
}
static int F_12 ( struct V_27 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
T_1 V_28 ;
int V_29 , V_14 ;
unsigned long V_30 ;
for ( V_29 = 0 ; V_29 < V_13 -> V_31 ; V_29 ++ ) {
V_14 = F_13 ( V_1 -> V_32 [ V_29 ] ) ;
if ( V_14 ) {
F_7 ( V_10 , L_10 ,
V_13 -> V_33 [ V_29 ] , V_14 ) ;
goto V_34;
}
}
V_14 = F_14 ( V_10 ) ;
if ( V_14 ) {
F_7 ( V_10 , L_11 , V_14 ) ;
goto V_34;
}
V_14 = F_5 ( V_1 , true ) ;
if ( V_14 ) {
F_7 ( V_10 , L_12 , V_14 ) ;
goto V_34;
}
for ( V_29 = 0 ; V_29 < V_13 -> V_35 ; V_29 ++ ) {
if ( V_13 -> V_36 && V_13 -> V_36 [ V_29 ] ) {
V_14 = F_15 ( V_1 -> V_37 [ V_29 ] ,
V_13 -> V_36 [ V_29 ] ) ;
if ( V_14 )
F_16 ( V_10 , L_13 ,
V_13 -> V_38 [ V_29 ] , V_14 ) ;
}
V_14 = F_17 ( V_1 -> V_37 [ V_29 ] ) ;
if ( V_14 ) {
F_7 ( V_10 , L_14 ,
V_13 -> V_38 [ V_29 ] , V_14 ) ;
goto V_34;
}
}
F_18 ( V_1 , false ) ;
F_1 ( V_1 ) ;
F_18 ( V_1 , true ) ;
F_3 ( V_1 , V_39 , 0x0001001b ) ;
F_3 ( V_1 , V_40 ,
V_41 |
V_42 ) ;
F_19 ( & V_1 -> V_43 , V_30 ) ;
V_28 = F_2 ( V_1 , V_44 ) ;
V_28 |= F_20 ( 0x1fff ) ;
F_3 ( V_1 , V_44 ,
~ V_45 & V_28 ) ;
F_3 ( V_1 , V_44 ,
V_45 | V_28 ) ;
F_21 ( & V_1 -> V_43 , V_30 ) ;
return 0 ;
V_34:
return V_14 ;
}
static void F_22 ( struct V_27 * V_27 )
{
struct V_1 * V_1 = V_27 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_9 * V_10 = & V_1 -> V_11 -> V_10 ;
int V_29 , V_14 = 0 ;
F_3 ( V_1 , V_40 , 0 ) ;
F_18 ( V_1 , false ) ;
for ( V_29 = 0 ; V_29 < V_13 -> V_35 ; V_29 ++ )
F_23 ( V_1 -> V_37 [ V_29 ] ) ;
V_14 = F_5 ( V_1 , false ) ;
if ( V_14 )
F_16 ( V_10 , L_15 , V_14 ) ;
V_14 = F_24 ( V_10 ) ;
if ( V_14 )
F_16 ( V_10 , L_11 , V_14 ) ;
for ( V_29 = 0 ; V_29 < V_13 -> V_31 ; V_29 ++ ) {
V_14 = F_25 ( V_1 -> V_32 [ V_29 ] ) ;
if ( V_14 )
F_16 ( V_10 , L_16 ,
V_13 -> V_33 [ V_29 ] , V_14 ) ;
}
}
static void
F_26 ( struct V_46 * V_47 )
{
struct V_27 * V_27 =
F_27 ( V_47 , struct V_27 , V_48 ) ;
struct V_49 * V_50 = & V_27 -> V_51 ;
F_28 ( V_50 -> V_10 ) ;
}
void F_29 ( struct V_49 * V_50 )
{
struct V_27 * V_27 = F_30 ( V_50 ) ;
struct V_1 * V_1 = V_27 -> V_1 ;
T_1 V_52 , V_53 ;
V_52 = F_2 ( V_1 , V_54 ) ;
V_53 = F_2 ( V_1 , V_40 ) ;
if ( ( V_53 & V_42 ) &&
( V_52 & V_55 ) ) {
bool V_56 = ! ! ( V_52 & V_57 ) ;
F_3 ( V_1 , V_40 ,
V_58 ) ;
F_10 ( L_17 , V_52 , V_53 ) ;
V_53 = V_42 ;
if ( ! V_56 )
V_53 |= V_41 ;
F_3 ( V_1 , V_40 , V_53 ) ;
F_31 ( V_1 -> V_59 , & V_27 -> V_48 ) ;
}
}
static enum V_60 F_32 ( struct V_1 * V_1 )
{
T_1 V_52 = F_2 ( V_1 , V_54 ) ;
return ( V_52 & V_57 ) ?
V_61 : V_62 ;
}
static enum V_60 F_33 ( struct V_1 * V_1 )
{
const struct V_12 * V_13 = V_1 -> V_13 ;
return F_34 ( V_13 -> V_19 ) ?
V_61 :
V_62 ;
}
static enum V_60 F_35 (
struct V_49 * V_50 , bool V_63 )
{
struct V_27 * V_27 = F_30 ( V_50 ) ;
struct V_1 * V_1 = V_27 -> V_1 ;
enum V_60 V_64 , V_65 ;
int V_66 = 20 ;
do {
V_64 = F_33 ( V_1 ) ;
V_65 = F_32 ( V_1 ) ;
if ( V_64 == V_65 )
break;
F_36 ( 10 ) ;
} while ( -- V_66 );
if ( V_64 != V_65 ) {
F_10 ( L_18 , V_65 ) ;
F_10 ( L_19 , V_64 ) ;
}
return V_64 ;
}
static void F_37 ( struct V_49 * V_50 )
{
struct V_27 * V_27 = F_30 ( V_50 ) ;
F_22 ( V_27 ) ;
F_38 ( V_50 ) ;
F_39 ( V_50 ) ;
F_40 ( V_27 ) ;
}
static int F_41 ( struct V_49 * V_50 )
{
struct V_27 * V_27 = F_30 ( V_50 ) ;
struct V_1 * V_1 = V_27 -> V_1 ;
struct V_67 * V_67 ;
T_1 V_68 ;
int V_14 = 0 ;
V_68 = F_2 ( V_1 , V_69 ) ;
F_3 ( V_1 , V_69 , V_68 | V_70 ) ;
V_67 = F_42 ( V_50 , V_1 -> V_71 ) ;
F_3 ( V_1 , V_69 , V_68 ) ;
V_1 -> V_72 = F_43 ( V_67 ) ;
F_44 ( V_50 , V_67 ) ;
if ( V_67 ) {
V_14 = F_45 ( V_50 , V_67 ) ;
F_40 ( V_67 ) ;
}
return V_14 ;
}
static int F_46 ( struct V_49 * V_50 ,
struct V_73 * V_74 )
{
struct V_27 * V_27 = F_30 ( V_50 ) ;
struct V_1 * V_1 = V_27 -> V_1 ;
const struct V_12 * V_13 = V_1 -> V_13 ;
struct V_75 * V_76 = V_50 -> V_10 -> V_77 ;
struct V_78 * V_79 = V_76 -> V_79 ;
long V_80 , V_81 ;
V_81 = 1000 * V_74 -> clock ;
V_80 = V_79 -> V_82 -> V_83 ( V_79 ,
V_81 , V_27 -> V_1 -> V_84 ) ;
if ( V_13 -> V_85 > 0 )
V_80 = F_47 ( V_1 -> V_86 [ 0 ] , V_80 ) ;
F_10 ( L_20 , V_81 , V_80 ) ;
if ( V_80 != V_81 )
return V_87 ;
return 0 ;
}
static struct V_88 *
F_48 ( struct V_49 * V_50 )
{
struct V_27 * V_27 = F_30 ( V_50 ) ;
return V_27 -> V_1 -> V_84 ;
}
struct V_49 * F_49 ( struct V_1 * V_1 )
{
struct V_49 * V_50 = NULL ;
struct V_27 * V_27 ;
int V_14 ;
V_27 = F_50 ( sizeof( * V_27 ) , V_89 ) ;
if ( ! V_27 ) {
V_14 = - V_90 ;
goto V_34;
}
V_27 -> V_1 = V_1 ;
F_51 ( & V_27 -> V_48 , F_26 ) ;
V_50 = & V_27 -> V_51 ;
F_52 ( V_1 -> V_10 , V_50 , & V_91 ,
V_92 ) ;
F_53 ( V_50 , & V_93 ) ;
V_50 -> V_94 = V_95 |
V_96 ;
V_50 -> V_97 = 0 ;
V_50 -> V_98 = 0 ;
F_54 ( V_50 ) ;
V_14 = F_12 ( V_27 ) ;
if ( V_14 ) {
F_7 ( & V_1 -> V_11 -> V_10 , L_21 , V_14 ) ;
goto V_34;
}
F_55 ( V_50 , V_1 -> V_84 ) ;
return V_50 ;
V_34:
if ( V_50 )
F_37 ( V_50 ) ;
return F_56 ( V_14 ) ;
}
