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
V_7 = F_9 ( V_1 -> V_26 [ V_23 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_10 ,
V_6 -> V_27 [ V_23 ] , V_7 ) ;
goto V_24;
}
}
for ( V_23 = 0 ; V_23 < V_6 -> V_28 ; V_23 ++ ) {
V_7 = F_10 ( V_1 -> V_29 [ V_23 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_11 ,
V_6 -> V_30 [ V_23 ] , V_7 ) ;
goto V_24;
}
}
F_11 ( V_1 , false ) ;
V_21 -> V_31 -> V_32 ( V_21 ) ;
F_11 ( V_1 , true ) ;
F_12 ( V_1 , V_33 , 0x0001001b ) ;
F_12 ( V_1 , V_34 ,
V_35 |
V_36 ) ;
V_22 = F_13 ( V_1 , V_37 ) ;
V_22 |= F_14 ( 0x1fff ) ;
F_12 ( V_1 , V_37 ,
~ V_38 & V_22 ) ;
F_12 ( V_1 , V_37 ,
V_38 | V_22 ) ;
return 0 ;
V_24:
return V_7 ;
}
static int F_15 ( struct V_18 * V_18 )
{
struct V_1 * V_1 = V_18 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_3 * V_4 = V_18 -> V_19 . V_4 ;
int V_23 , V_7 = 0 ;
F_12 ( V_1 , V_34 , 0 ) ;
F_11 ( V_1 , false ) ;
for ( V_23 = 0 ; V_23 < V_6 -> V_28 ; V_23 ++ ) {
V_7 = F_16 ( V_1 -> V_29 [ V_23 ] ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_12 ,
V_6 -> V_30 [ V_23 ] , V_7 ) ;
goto V_24;
}
}
for ( V_23 = 0 ; V_23 < V_6 -> V_25 ; V_23 ++ )
F_17 ( V_1 -> V_26 [ V_23 ] ) ;
V_7 = F_1 ( V_1 , false ) ;
if ( V_7 ) {
F_3 ( V_4 -> V_4 , L_13 , V_7 ) ;
goto V_24;
}
return 0 ;
V_24:
return V_7 ;
}
static void
F_18 ( struct V_39 * V_40 )
{
struct V_18 * V_18 =
F_19 ( V_40 , struct V_18 , V_41 ) ;
struct V_42 * V_43 = & V_18 -> V_19 ;
F_20 ( V_43 -> V_4 ) ;
}
void F_21 ( struct V_42 * V_43 )
{
struct V_18 * V_18 = F_22 ( V_43 ) ;
struct V_44 * V_45 = V_43 -> V_4 -> V_46 ;
struct V_1 * V_1 = V_18 -> V_1 ;
T_1 V_47 , V_48 ;
V_47 = F_13 ( V_1 , V_49 ) ;
V_48 = F_13 ( V_1 , V_34 ) ;
if ( ( V_48 & V_36 ) &&
( V_47 & V_50 ) ) {
bool V_51 = ! ! ( V_47 & V_52 ) ;
F_6 ( L_14 , V_47 , V_48 ) ;
F_12 ( V_1 , V_34 ,
V_48 | V_53 ) ;
V_48 = V_36 ;
if ( ! V_51 )
V_48 |= V_35 ;
F_12 ( V_1 , V_34 , V_48 ) ;
F_23 ( V_45 -> V_54 , & V_18 -> V_41 ) ;
}
}
static enum V_55 F_24 (
struct V_42 * V_43 , bool V_56 )
{
struct V_18 * V_18 = F_22 ( V_43 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
T_1 V_47 ;
int V_57 = 20 ;
V_47 = F_13 ( V_1 , V_49 ) ;
while ( V_57 -- && ! ( V_47 & V_52 ) ) {
if ( F_25 ( V_6 -> V_12 ) ) {
F_6 ( L_15 ) ;
V_47 |= V_52 ;
break;
}
F_26 ( 10 ) ;
V_47 = F_13 ( V_1 , V_49 ) ;
F_6 ( L_16 , V_47 ) ;
}
return ( V_47 & V_52 ) ?
V_58 : V_59 ;
}
static void F_27 ( struct V_42 * V_43 )
{
struct V_18 * V_18 = F_22 ( V_43 ) ;
F_15 ( V_18 ) ;
F_28 ( V_43 ) ;
F_29 ( V_43 ) ;
F_30 ( V_18 -> V_1 ) ;
F_31 ( V_18 ) ;
}
static int F_32 ( struct V_42 * V_43 )
{
struct V_18 * V_18 = F_22 ( V_43 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
struct V_60 * V_60 ;
T_1 V_61 ;
int V_7 = 0 ;
V_61 = F_13 ( V_1 , V_62 ) ;
F_12 ( V_1 , V_62 , V_61 | V_63 ) ;
V_60 = F_33 ( V_43 , V_1 -> V_64 ) ;
F_12 ( V_1 , V_62 , V_61 ) ;
F_34 ( V_43 , V_60 ) ;
if ( V_60 ) {
V_7 = F_35 ( V_43 , V_60 ) ;
F_31 ( V_60 ) ;
}
return V_7 ;
}
static int F_36 ( struct V_42 * V_43 ,
struct V_65 * V_66 )
{
struct V_18 * V_18 = F_22 ( V_43 ) ;
struct V_1 * V_1 = V_18 -> V_1 ;
const struct V_5 * V_6 = V_1 -> V_6 ;
struct V_44 * V_45 = V_43 -> V_4 -> V_46 ;
struct V_67 * V_68 = V_45 -> V_68 ;
long V_69 , V_70 ;
V_70 = 1000 * V_66 -> clock ;
V_69 = V_68 -> V_31 -> V_71 ( V_68 ,
V_70 , V_18 -> V_1 -> V_72 ) ;
if ( V_6 -> V_73 > 0 )
V_69 = F_37 ( V_1 -> V_74 [ 0 ] , V_69 ) ;
F_6 ( L_17 , V_70 , V_69 ) ;
if ( V_69 != V_70 )
return V_75 ;
return 0 ;
}
static struct V_76 *
F_38 ( struct V_42 * V_43 )
{
struct V_18 * V_18 = F_22 ( V_43 ) ;
return V_18 -> V_1 -> V_72 ;
}
struct V_42 * F_39 ( struct V_1 * V_1 )
{
struct V_42 * V_43 = NULL ;
struct V_18 * V_18 ;
int V_7 ;
V_18 = F_40 ( sizeof( * V_18 ) , V_77 ) ;
if ( ! V_18 ) {
V_7 = - V_78 ;
goto V_24;
}
V_18 -> V_1 = F_41 ( V_1 ) ;
F_42 ( & V_18 -> V_41 , F_18 ) ;
V_43 = & V_18 -> V_19 ;
F_43 ( V_1 -> V_4 , V_43 , & V_79 ,
V_80 ) ;
F_44 ( V_43 , & V_81 ) ;
V_43 -> V_82 = V_83 ;
V_43 -> V_84 = 1 ;
V_43 -> V_85 = 0 ;
F_45 ( V_43 ) ;
V_7 = F_8 ( V_18 ) ;
if ( V_7 ) {
F_3 ( V_1 -> V_4 -> V_4 , L_18 , V_7 ) ;
goto V_24;
}
F_46 ( V_43 , V_1 -> V_72 ) ;
return V_43 ;
V_24:
if ( V_43 )
F_27 ( V_43 ) ;
return F_47 ( V_7 ) ;
}
