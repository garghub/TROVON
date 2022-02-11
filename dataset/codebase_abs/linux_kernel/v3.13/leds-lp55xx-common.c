static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 ) ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 = V_9 -> V_11 . V_10 ;
T_1 V_12 = V_9 -> V_11 . V_12 ;
F_6 ( V_7 , V_10 , V_12 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 = V_9 -> V_13 . V_10 ;
T_1 V_12 = V_9 -> V_13 . V_12 ;
int V_14 ;
V_14 = F_6 ( V_7 , V_10 , V_12 ) ;
if ( V_14 )
return V_14 ;
F_8 ( 1000 , 2000 ) ;
V_14 = F_9 ( V_7 , V_10 , & V_12 ) ;
if ( V_14 )
return V_14 ;
if ( V_12 != V_9 -> V_13 . V_12 )
return - V_15 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( ! V_9 -> V_16 )
return 0 ;
return V_9 -> V_16 ( V_7 ) ;
}
static T_2 F_11 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_1 * V_20 = F_3 ( V_5 ) ;
return F_12 ( V_19 , V_21 , L_1 , V_20 -> V_22 ) ;
}
static T_2 F_13 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_23 )
{
struct V_1 * V_20 = F_3 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_24 ;
if ( F_14 ( V_19 , 0 , & V_24 ) )
return - V_25 ;
if ( V_24 > V_20 -> V_26 )
return - V_25 ;
if ( ! V_7 -> V_9 -> V_27 )
return V_23 ;
F_15 ( & V_7 -> V_28 ) ;
V_7 -> V_9 -> V_27 ( V_20 , ( T_1 ) V_24 ) ;
F_16 ( & V_7 -> V_28 ) ;
return V_23 ;
}
static T_2 F_17 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_1 * V_20 = F_3 ( V_5 ) ;
return F_12 ( V_19 , V_21 , L_1 , V_20 -> V_26 ) ;
}
static void F_18 ( struct V_2 * V_3 ,
enum V_29 V_30 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
V_20 -> V_30 = ( T_1 ) V_30 ;
F_19 ( & V_20 -> V_31 ) ;
}
static int F_20 ( struct V_1 * V_20 ,
struct V_6 * V_7 , int V_32 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;
char V_36 [ 32 ] ;
int V_14 ;
int V_37 = V_9 -> V_37 ;
if ( V_32 >= V_37 ) {
F_21 ( V_5 , L_2 , V_32 , V_37 ) ;
return - V_25 ;
}
if ( V_34 -> V_38 [ V_32 ] . V_22 == 0 )
return 0 ;
V_20 -> V_22 = V_34 -> V_38 [ V_32 ] . V_22 ;
V_20 -> V_26 = V_34 -> V_38 [ V_32 ] . V_26 ;
V_20 -> V_39 = V_34 -> V_38 [ V_32 ] . V_39 ;
V_20 -> V_3 . V_40 = V_34 -> V_38 [ V_32 ] . V_40 ;
if ( V_20 -> V_39 >= V_37 ) {
F_21 ( V_5 , L_3 ,
V_37 - 1 ) ;
return - V_25 ;
}
V_20 -> V_3 . V_41 = F_18 ;
if ( V_34 -> V_38 [ V_32 ] . V_36 ) {
V_20 -> V_3 . V_36 = V_34 -> V_38 [ V_32 ] . V_36 ;
} else {
snprintf ( V_36 , sizeof( V_36 ) , L_4 ,
V_34 -> V_42 ? : V_7 -> V_35 -> V_36 , V_32 ) ;
V_20 -> V_3 . V_36 = V_36 ;
}
V_14 = F_22 ( V_5 , & V_20 -> V_3 ) ;
if ( V_14 ) {
F_21 ( V_5 , L_5 , V_14 ) ;
return V_14 ;
}
V_14 = F_23 ( & V_20 -> V_3 . V_5 -> V_43 , & V_44 ) ;
if ( V_14 ) {
F_21 ( V_5 , L_6 , V_14 ) ;
F_24 ( & V_20 -> V_3 ) ;
return V_14 ;
}
return 0 ;
}
static void F_25 ( const struct V_45 * V_46 , void * V_47 )
{
struct V_6 * V_7 = V_47 ;
struct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;
if ( ! V_46 ) {
F_21 ( V_5 , L_7 ) ;
goto V_48;
}
F_15 ( & V_7 -> V_28 ) ;
V_7 -> V_46 = V_46 ;
if ( V_7 -> V_9 -> V_49 )
V_7 -> V_9 -> V_49 ( V_7 ) ;
F_16 ( & V_7 -> V_28 ) ;
V_48:
F_26 ( V_7 -> V_46 ) ;
}
static int F_27 ( struct V_6 * V_7 )
{
const char * V_36 = V_7 -> V_35 -> V_36 ;
struct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;
return F_28 ( V_50 , true , V_36 , V_5 ,
V_51 , V_7 , F_25 ) ;
}
static T_2 F_29 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_1 * V_20 = F_30 ( F_31 ( V_5 ) ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
return sprintf ( V_19 , L_1 , V_7 -> V_52 ) ;
}
static T_2 F_32 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_23 )
{
struct V_1 * V_20 = F_30 ( F_31 ( V_5 ) ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_12 ;
int V_14 ;
if ( F_14 ( V_19 , 0 , & V_12 ) )
return - V_25 ;
switch ( V_12 ) {
case V_53 :
case V_54 :
case V_55 :
F_15 ( & V_7 -> V_28 ) ;
V_7 -> V_52 = V_12 ;
V_14 = F_27 ( V_7 ) ;
F_16 ( & V_7 -> V_28 ) ;
break;
default:
F_21 ( V_5 , L_8 , V_12 ) ;
return - V_25 ;
}
if ( V_14 ) {
F_21 ( V_5 , L_9 , V_14 ) ;
return V_14 ;
}
return V_23 ;
}
static inline void F_33 ( struct V_6 * V_7 , bool V_56 )
{
if ( V_7 -> V_9 -> V_57 )
V_7 -> V_9 -> V_57 ( V_7 , V_56 ) ;
}
static T_2 F_34 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_23 )
{
struct V_1 * V_20 = F_30 ( F_31 ( V_5 ) ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_12 ;
if ( F_14 ( V_19 , 0 , & V_12 ) )
return - V_25 ;
if ( V_12 <= 0 ) {
F_33 ( V_7 , false ) ;
return V_23 ;
}
F_15 ( & V_7 -> V_28 ) ;
F_33 ( V_7 , true ) ;
F_16 ( & V_7 -> V_28 ) ;
return V_23 ;
}
int F_6 ( struct V_6 * V_7 , T_1 V_58 , T_1 V_12 )
{
return F_35 ( V_7 -> V_35 , V_58 , V_12 ) ;
}
int F_9 ( struct V_6 * V_7 , T_1 V_58 , T_1 * V_12 )
{
T_4 V_14 ;
V_14 = F_36 ( V_7 -> V_35 , V_58 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_12 = V_14 ;
return 0 ;
}
int F_37 ( struct V_6 * V_7 , T_1 V_58 , T_1 V_59 , T_1 V_12 )
{
int V_14 ;
T_1 V_60 ;
V_14 = F_9 ( V_7 , V_58 , & V_60 ) ;
if ( V_14 )
return V_14 ;
V_60 &= ~ V_59 ;
V_60 |= V_12 & V_59 ;
return F_6 ( V_7 , V_58 , V_60 ) ;
}
bool F_38 ( struct V_6 * V_7 )
{
struct V_61 * V_61 ;
int V_62 ;
V_61 = F_39 ( & V_7 -> V_35 -> V_5 , L_10 ) ;
if ( F_40 ( V_61 ) )
goto V_63;
V_62 = F_41 ( V_61 ) ;
if ( V_62 )
goto V_63;
if ( F_42 ( V_61 ) != V_64 ) {
F_43 ( V_61 ) ;
goto V_63;
}
F_44 ( & V_7 -> V_35 -> V_5 , L_11 , V_64 ) ;
V_7 -> V_61 = V_61 ;
return true ;
V_63:
F_44 ( & V_7 -> V_35 -> V_5 , L_12 ) ;
return false ;
}
int F_45 ( struct V_6 * V_7 )
{
struct V_33 * V_34 ;
struct V_8 * V_9 ;
struct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;
int V_14 = 0 ;
F_46 ( ! V_7 ) ;
V_34 = V_7 -> V_34 ;
V_9 = V_7 -> V_9 ;
if ( ! V_34 || ! V_9 )
return - V_25 ;
if ( F_47 ( V_34 -> V_65 ) ) {
V_14 = F_48 ( V_5 , V_34 -> V_65 ,
V_66 , L_13 ) ;
if ( V_14 < 0 ) {
F_21 ( V_5 , L_14 ,
V_14 ) ;
goto V_62;
}
F_49 ( V_34 -> V_65 , 0 ) ;
F_8 ( 1000 , 2000 ) ;
F_49 ( V_34 -> V_65 , 1 ) ;
F_8 ( 1000 , 2000 ) ;
}
F_5 ( V_7 ) ;
F_8 ( 10000 , 20000 ) ;
V_14 = F_7 ( V_7 ) ;
if ( V_14 ) {
F_21 ( V_5 , L_15 , V_14 ) ;
goto V_62;
}
V_14 = F_10 ( V_7 ) ;
if ( V_14 ) {
F_21 ( V_5 , L_16 , V_14 ) ;
goto V_67;
}
return 0 ;
V_67:
F_50 ( V_7 ) ;
V_62:
return V_14 ;
}
void F_50 ( struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
if ( V_7 -> V_61 )
F_43 ( V_7 -> V_61 ) ;
if ( F_47 ( V_34 -> V_65 ) )
F_49 ( V_34 -> V_65 , 0 ) ;
}
int F_51 ( struct V_1 * V_20 , struct V_6 * V_7 )
{
struct V_33 * V_34 = V_7 -> V_34 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_68 = V_34 -> V_68 ;
struct V_1 * V_69 ;
T_1 V_22 ;
int V_14 ;
int V_70 ;
if ( ! V_9 -> V_71 ) {
F_21 ( & V_7 -> V_35 -> V_5 , L_17 ) ;
return - V_25 ;
}
for ( V_70 = 0 ; V_70 < V_68 ; V_70 ++ ) {
if ( V_34 -> V_38 [ V_70 ] . V_22 == 0 )
continue;
V_22 = V_34 -> V_38 [ V_70 ] . V_22 ;
V_69 = V_20 + V_70 ;
V_14 = F_20 ( V_69 , V_7 , V_70 ) ;
if ( V_14 )
goto V_72;
F_52 ( & V_69 -> V_31 , V_9 -> V_71 ) ;
V_7 -> V_73 ++ ;
V_69 -> V_7 = V_7 ;
if ( V_9 -> V_27 )
V_9 -> V_27 ( V_69 , V_22 ) ;
}
return 0 ;
V_72:
F_53 ( V_20 , V_7 ) ;
return V_14 ;
}
void F_53 ( struct V_1 * V_20 , struct V_6 * V_7 )
{
int V_70 ;
struct V_1 * V_69 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_73 ; V_70 ++ ) {
V_69 = V_20 + V_70 ;
F_24 ( & V_69 -> V_3 ) ;
F_54 ( & V_69 -> V_31 ) ;
}
}
int F_55 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_14 ;
if ( ! V_9 -> V_57 || ! V_9 -> V_49 )
goto V_74;
V_14 = F_23 ( & V_5 -> V_43 , & V_75 ) ;
if ( V_14 )
return V_14 ;
V_74:
return V_9 -> V_76 ?
F_23 ( & V_5 -> V_43 , V_9 -> V_76 ) : 0 ;
}
void F_56 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = & V_7 -> V_35 -> V_5 ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_76 )
F_57 ( & V_5 -> V_43 , V_9 -> V_76 ) ;
F_57 ( & V_5 -> V_43 , & V_75 ) ;
}
int F_58 ( struct V_4 * V_5 , struct V_77 * V_78 )
{
struct V_77 * V_79 ;
struct V_33 * V_34 ;
struct V_80 * V_9 ;
int V_68 ;
int V_70 = 0 ;
V_34 = F_59 ( V_5 , sizeof( * V_34 ) , V_51 ) ;
if ( ! V_34 )
return - V_81 ;
V_68 = F_60 ( V_78 ) ;
if ( V_68 == 0 ) {
F_21 ( V_5 , L_18 ) ;
return - V_25 ;
}
V_9 = F_59 ( V_5 , sizeof( * V_9 ) * V_68 , V_51 ) ;
if ( ! V_9 )
return - V_81 ;
V_34 -> V_38 = & V_9 [ 0 ] ;
V_34 -> V_68 = V_68 ;
F_61 (np, child) {
V_9 [ V_70 ] . V_39 = V_70 ;
F_62 ( V_79 , L_19 , & V_9 [ V_70 ] . V_36 ) ;
F_63 ( V_79 , L_20 , & V_9 [ V_70 ] . V_22 ) ;
F_63 ( V_79 , L_21 , & V_9 [ V_70 ] . V_26 ) ;
V_9 [ V_70 ] . V_40 =
F_64 ( V_79 , L_22 , NULL ) ;
V_70 ++ ;
}
F_62 ( V_78 , L_23 , & V_34 -> V_42 ) ;
F_63 ( V_78 , L_24 , & V_34 -> V_82 ) ;
V_34 -> V_65 = F_65 ( V_78 , L_25 , 0 ) ;
F_63 ( V_78 , L_26 , ( T_1 * ) & V_34 -> V_83 ) ;
V_5 -> V_84 = V_34 ;
return 0 ;
}
