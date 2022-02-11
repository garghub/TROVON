int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 * V_3 )
{
int V_4 ;
int V_5 ;
V_5 = F_2 ( V_1 -> V_6 , V_2 , & V_4 ) ;
if ( V_5 < 0 ) {
F_3 ( V_1 -> V_7 , L_1 ,
V_2 , V_5 ) ;
return V_5 ;
}
* V_3 = V_4 ;
F_4 ( V_1 -> V_7 , L_2 , V_2 , * V_3 ) ;
return V_5 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
int V_5 ;
F_4 ( V_1 -> V_7 , L_3 , V_2 , V_3 ) ;
V_5 = F_6 ( V_1 -> V_6 , V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( V_1 -> V_7 , L_4 ,
V_2 , V_5 ) ;
}
return V_5 ;
}
int F_7 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 , T_1 V_8 )
{
int V_5 ;
F_4 ( V_1 -> V_7 , L_5 , V_2 , V_3 , V_8 ) ;
V_5 = F_8 ( V_1 -> V_6 , V_2 , V_8 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( V_1 -> V_7 , L_6 ,
V_2 , V_5 ) ;
}
return V_5 ;
}
static int F_9 ( struct V_1 * V_1 ,
enum V_9 V_10 )
{
int V_5 ;
V_5 = F_7 ( V_1 , V_11 ,
V_10 << V_12 ,
V_13 ) ;
if ( V_5 )
F_3 ( V_1 -> V_7 , L_7 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_1 ,
enum V_14 V_15 )
{
int V_5 ;
V_5 = F_7 ( V_1 , V_11 ,
V_15 << V_16 ,
V_17 ) ;
if ( V_5 )
F_3 ( V_1 -> V_7 , L_8 ) ;
return V_5 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_18 , T_1 V_19 )
{
T_1 V_3 ;
T_1 V_8 ;
int V_20 ;
int V_5 ;
if ( V_18 == 0 || V_18 > V_21 )
return - V_22 ;
if ( V_19 > V_23 )
return - V_22 ;
V_20 = V_18 - 1 ;
V_8 = V_24 << V_20 ;
V_3 = V_19 << V_20 ;
V_5 = F_7 ( V_1 , V_25 , V_3 , V_8 ) ;
if ( V_5 )
F_3 ( V_1 -> V_7 , L_9 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_1 , T_1 V_26 , T_1 V_27 )
{
T_1 V_2 ;
T_1 V_3 ;
T_1 V_8 ;
int V_20 ;
int V_5 ;
if ( V_26 == 0 || V_26 > V_28 )
return - V_22 ;
if ( V_27 > V_29 )
return - V_22 ;
if ( V_26 < 4 ) {
V_2 = V_25 ;
V_20 = 2 * V_26 ;
} else {
V_2 = V_30 ;
V_20 = 2 * ( V_26 - 4 ) ;
}
V_8 = V_31 << V_20 ;
V_3 = V_27 << V_20 ;
V_5 = F_7 ( V_1 , V_2 , V_3 , V_8 ) ;
if ( V_5 )
F_3 ( V_1 -> V_7 , L_10 ) ;
return V_5 ;
}
static void F_13 ( struct V_1 * V_1 )
{
if ( F_14 ( V_1 -> V_32 ) )
F_15 ( V_1 -> V_32 , 1 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
if ( F_14 ( V_1 -> V_32 ) )
F_15 ( V_1 -> V_32 , 0 ) ;
}
static T_2 F_17 ( struct V_33 * V_7 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_1 * V_1 = F_18 ( V_7 ) ;
struct V_37 * V_38 = F_19 ( V_35 ) ;
int V_39 = V_38 -> V_40 . V_41 . V_39 ;
T_1 V_2 ;
T_1 V_3 ;
T_1 V_8 ;
int V_20 ;
int V_5 ;
if ( V_38 -> type == V_42 ) {
V_2 = V_25 ;
V_20 = V_39 - 1 ;
V_8 = V_24 << V_20 ;
} else {
if ( V_39 < 4 ) {
V_2 = V_25 ;
V_20 = 2 * V_39 ;
} else {
V_2 = V_30 ;
V_20 = 2 * ( V_39 - 4 ) ;
}
V_8 = V_31 << V_20 ;
}
V_5 = F_1 ( V_1 , V_2 , & V_3 ) ;
if ( V_5 )
return V_5 ;
V_3 = ( V_3 & V_8 ) >> V_20 ;
return F_20 ( V_36 , V_43 , L_11 , V_3 ) ;
}
static T_2 F_21 ( struct V_33 * V_7 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_44 )
{
struct V_1 * V_1 = F_18 ( V_7 ) ;
struct V_37 * V_38 = F_19 ( V_35 ) ;
int V_39 = V_38 -> V_40 . V_41 . V_39 ;
T_1 V_3 ;
int V_5 ;
if ( F_22 ( V_36 , 0 , & V_3 ) )
return - V_22 ;
if ( V_38 -> type == V_42 )
V_5 = F_11 ( V_1 , V_39 , V_3 ) ;
else
V_5 = F_12 ( V_1 , V_39 , V_3 ) ;
if ( V_5 )
return V_5 ;
return V_44 ;
}
static T_4 F_23 ( struct V_45 * V_46 ,
struct V_47 * V_35 , int V_48 )
{
struct V_33 * V_7 = F_24 ( V_46 , struct V_33 , V_46 ) ;
struct V_1 * V_1 = F_18 ( V_7 ) ;
struct V_34 * V_49 = F_25 ( V_35 ) ;
struct V_37 * V_38 = F_19 ( V_49 ) ;
enum V_50 type = V_38 -> type ;
T_4 V_51 = V_35 -> V_51 ;
if ( ! V_1 -> V_52 && type == V_42 )
V_51 = 0 ;
else if ( ! V_1 -> V_53 && type == V_54 )
V_51 = 0 ;
return V_51 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_55 * V_56 = F_27 ( V_1 -> V_7 ) ;
int V_5 ;
if ( ! V_56 -> V_57 )
return 0 ;
V_58 [ 0 ] . V_59 = V_56 -> V_57 ;
V_58 [ 0 ] . V_60 = sizeof( * V_56 -> V_57 ) ;
V_5 = F_28 ( V_1 -> V_7 , 0 , V_58 , 1 , NULL ,
0 , NULL ) ;
if ( V_5 ) {
F_3 ( V_1 -> V_7 , L_12 ) ;
return V_5 ;
}
V_1 -> V_61 = 1 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_55 * V_56 = F_27 ( V_1 -> V_7 ) ;
int V_62 ;
int V_5 ;
if ( ! V_56 -> V_63 || V_56 -> V_64 == 0 )
return 0 ;
if ( V_56 -> V_64 > F_30 ( V_65 ) )
V_56 -> V_64 = F_30 ( V_65 ) ;
for ( V_62 = 0 ; V_62 < V_56 -> V_64 ; ++ V_62 ) {
V_65 [ V_62 ] . V_59 = & V_56 -> V_63 [ V_62 ] ;
V_65 [ V_62 ] . V_60 = sizeof( V_56 -> V_63 [ V_62 ] ) ;
}
V_5 = F_28 ( V_1 -> V_7 , 0 , V_65 ,
V_56 -> V_64 , NULL , 0 , NULL ) ;
if ( V_5 ) {
F_3 ( V_1 -> V_7 , L_13 ) ;
return V_5 ;
}
V_1 -> V_52 = 1 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_55 * V_56 = F_27 ( V_1 -> V_7 ) ;
int V_62 ;
int V_5 ;
if ( ! V_56 -> V_66 || V_56 -> V_67 == 0 )
return 0 ;
if ( V_56 -> V_67 > F_30 ( V_68 ) )
V_56 -> V_67 = F_30 ( V_68 ) ;
for ( V_62 = 0 ; V_62 < V_56 -> V_67 ; ++ V_62 ) {
V_68 [ V_62 ] . V_59 = & V_56 -> V_66 [ V_62 ] ;
V_68 [ V_62 ] . V_60 = sizeof( V_56 -> V_66 [ V_62 ] ) ;
}
V_5 = F_28 ( V_1 -> V_7 , 0 , V_68 ,
V_56 -> V_67 , NULL , 0 , NULL ) ;
if ( V_5 ) {
F_3 ( V_1 -> V_7 , L_14 ) ;
return V_5 ;
}
V_1 -> V_53 = 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 ,
struct V_55 * V_56 )
{
int V_5 ;
V_5 = F_9 ( V_1 , V_56 -> V_69 ) ;
if ( V_5 )
return V_5 ;
return F_10 ( V_1 , V_56 -> V_70 ) ;
}
static int F_33 ( struct V_1 * V_1 )
{
struct V_55 * V_56 = F_27 ( V_1 -> V_7 ) ;
int V_5 ;
F_4 ( V_1 -> V_7 , L_15 , V_71 ) ;
if ( ! V_56 ) {
F_3 ( V_1 -> V_7 , L_16 ) ;
return - V_22 ;
}
V_1 -> V_32 = V_56 -> V_32 ;
F_34 ( V_1 -> V_7 , V_1 ) ;
if ( F_14 ( V_1 -> V_32 ) ) {
V_5 = F_35 ( V_1 -> V_7 , V_1 -> V_32 ,
V_72 , L_17 ) ;
if ( V_5 < 0 ) {
F_3 ( V_1 -> V_7 ,
L_18 ,
V_1 -> V_32 ) ;
return V_5 ;
}
}
F_13 ( V_1 ) ;
V_5 = F_32 ( V_1 , V_56 ) ;
if ( V_5 )
goto V_73;
F_26 ( V_1 ) ;
F_29 ( V_1 ) ;
F_31 ( V_1 ) ;
V_5 = F_36 ( & V_1 -> V_7 -> V_46 , & V_74 ) ;
if ( V_5 < 0 ) {
F_3 ( V_1 -> V_7 , L_19 ) ;
goto V_75;
}
return 0 ;
V_75:
F_37 ( V_1 -> V_7 ) ;
V_73:
F_16 ( V_1 ) ;
return V_5 ;
}
static void F_38 ( struct V_1 * V_1 )
{
F_4 ( V_1 -> V_7 , L_15 , V_71 ) ;
F_39 ( & V_1 -> V_7 -> V_46 , & V_74 ) ;
F_37 ( V_1 -> V_7 ) ;
F_16 ( V_1 ) ;
}
static bool F_40 ( struct V_33 * V_7 , unsigned int V_2 )
{
switch ( V_2 ) {
case 0x10 ... 0x2c :
case 0x30 ... 0x38 :
case 0x40 ... 0x45 :
case 0x50 ... 0x57 :
case 0x60 ... 0x6e :
case 0x70 ... 0x75 :
case 0x80 ... 0x85 :
case 0x90 ... 0x95 :
case 0xa0 ... 0xa5 :
case 0xb0 ... 0xb2 :
return true ;
default:
return false ;
}
}
static bool F_41 ( struct V_33 * V_7 , unsigned int V_2 )
{
switch ( V_2 ) {
case 0x34 ... 0x36 :
case 0x37 ... 0x38 :
case 0xb0 ... 0xb1 :
return true ;
default:
return false ;
}
}
static bool F_42 ( struct V_33 * V_7 , unsigned int V_2 )
{
switch ( V_2 ) {
case 0x34 :
return true ;
default:
return false ;
}
}
static int F_43 ( struct V_76 * V_77 ,
const struct V_78 * V_39 )
{
struct V_1 * V_1 ;
F_4 ( & V_77 -> V_7 , L_15 , V_71 ) ;
V_1 = F_44 ( & V_77 -> V_7 , sizeof( * V_1 ) , V_79 ) ;
if ( ! V_1 )
return - V_80 ;
F_45 ( V_77 , V_1 ) ;
V_1 -> V_6 = F_46 ( V_77 , & V_81 ) ;
if ( F_47 ( V_1 -> V_6 ) )
return F_48 ( V_1 -> V_6 ) ;
V_1 -> V_7 = & V_77 -> V_7 ;
V_1 -> V_82 = V_77 -> V_82 ;
return F_33 ( V_1 ) ;
}
static int F_49 ( struct V_76 * V_77 )
{
struct V_1 * V_1 = F_50 ( V_77 ) ;
F_4 ( & V_77 -> V_7 , L_15 , V_71 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_83 ) ;
}
static void T_6 F_53 ( void )
{
F_54 ( & V_83 ) ;
}
