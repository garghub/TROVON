static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
int V_9 = 0 ;
struct V_10 * V_11 ;
F_3 () ;
F_4 (bond, &bn->dev_list, bond_list) {
if ( V_9 > ( V_12 - V_13 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_2 , V_11 -> V_14 -> V_15 ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static struct V_16 * F_6 ( struct V_6 * V_7 , const char * V_17 )
{
struct V_10 * V_11 ;
F_4 (bond, &bn->dev_list, bond_list) {
if ( strncmp ( V_11 -> V_14 -> V_15 , V_17 , V_13 ) == 0 )
return V_11 -> V_14 ;
}
return NULL ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
char V_20 [ V_13 + 1 ] = { 0 , } ;
char * V_17 ;
int V_21 , V_9 = V_19 ;
sscanf ( V_18 , L_3 , V_20 ) ;
V_17 = V_20 + 1 ;
if ( ( strlen ( V_20 ) <= 1 ) ||
! F_8 ( V_17 ) )
goto V_22;
if ( V_20 [ 0 ] == '+' ) {
F_9 ( L_4 , V_17 ) ;
V_21 = F_10 ( V_7 -> V_23 , V_17 ) ;
if ( V_21 ) {
if ( V_21 == - V_24 )
F_9 ( L_5 , V_17 ) ;
else
F_9 ( L_6 , V_17 ) ;
V_9 = V_21 ;
}
} else if ( V_20 [ 0 ] == '-' ) {
struct V_16 * V_25 ;
F_3 () ;
V_25 = F_6 ( V_7 , V_17 ) ;
if ( V_25 ) {
F_9 ( L_7 , V_17 ) ;
F_11 ( V_25 ) ;
} else {
F_12 ( L_8 , V_17 ) ;
V_9 = - V_26 ;
}
F_5 () ;
} else
goto V_22;
return V_9 ;
V_22:
F_12 ( L_9 ) ;
return - V_27 ;
}
static T_1 F_13 ( struct V_28 * V_29 ,
struct V_30 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
int V_9 = 0 ;
if ( ! F_15 () )
return F_16 () ;
F_17 (bond, slave, iter) {
if ( V_9 > ( V_12 - V_13 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_2 , V_33 -> V_14 -> V_15 ) ;
}
F_5 () ;
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_18 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_35 , ( char * ) V_18 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_20 ( struct V_28 * V_29 ,
struct V_30 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_38 , V_11 -> V_39 . V_40 ) ;
return sprintf ( V_5 , L_10 , V_37 -> string , V_11 -> V_39 . V_40 ) ;
}
static T_1 F_22 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_38 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_23 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_41 , V_11 -> V_39 . V_42 ) ;
return sprintf ( V_5 , L_10 , V_37 -> string , V_11 -> V_39 . V_42 ) ;
}
static T_1 F_24 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_41 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_25 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_43 ,
V_11 -> V_39 . V_44 ) ;
return sprintf ( V_5 , L_10 , V_37 -> string , V_11 -> V_39 . V_44 ) ;
}
static T_1 F_26 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_43 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_27 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_45 ,
V_11 -> V_39 . V_46 ) ;
return sprintf ( V_5 , L_10 ,
V_37 -> string , V_11 -> V_39 . V_46 ) ;
}
static T_1 F_28 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_45 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_29 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_47 ,
V_11 -> V_39 . V_48 ) ;
return sprintf ( V_5 , L_10 , V_37 -> string , V_11 -> V_39 . V_48 ) ;
}
static T_1 F_30 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_47 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_31 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_49 ) ;
}
static T_1 F_32 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_50 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_33 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_51 , V_9 = 0 ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
if ( V_11 -> V_39 . V_53 [ V_51 ] )
V_9 += sprintf ( V_5 + V_9 , L_12 ,
& V_11 -> V_39 . V_53 [ V_51 ] ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_34 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_54 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_35 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_55 * V_11 -> V_39 . V_56 ) ;
}
static T_1 F_36 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_57 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_37 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_58 * V_11 -> V_39 . V_56 ) ;
}
static T_1 F_38 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_59 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_39 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_60 , V_11 -> V_39 . V_61 ) ;
return sprintf ( V_5 , L_10 , V_37 -> string , V_11 -> V_39 . V_61 ) ;
}
static T_1 F_40 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_60 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_41 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_62 ) ;
}
static T_1 F_42 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_63 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_43 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_64 , V_11 -> V_39 . V_65 ) ;
return sprintf ( V_5 , L_10 , V_37 -> string , V_11 -> V_39 . V_65 ) ;
}
static T_1 F_44 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_64 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_45 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_66 ) ;
}
static T_1 F_46 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_67 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_47 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_56 ) ;
}
static T_1 F_48 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_68 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_49 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_69 )
V_19 = sprintf ( V_5 , L_13 , V_11 -> V_69 -> V_14 -> V_15 ) ;
return V_19 ;
}
static T_1 F_50 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_70 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_51 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
V_37 = F_21 ( V_71 ,
V_11 -> V_39 . V_72 ) ;
return sprintf ( V_5 , L_10 ,
V_37 -> string , V_11 -> V_39 . V_72 ) ;
}
static T_1 F_52 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_71 ,
( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_53 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_73 ) ;
}
static T_1 F_54 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_74 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_55 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_16 * V_75 ;
int V_19 = 0 ;
F_56 () ;
V_75 = F_57 ( V_11 ) ;
if ( V_75 )
V_19 = sprintf ( V_5 , L_13 , V_75 -> V_15 ) ;
F_58 () ;
return V_19 ;
}
static T_1 F_59 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_76 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_60 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_13 , V_11 -> V_77 ? L_14 : L_15 ) ;
}
static T_1 F_61 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_39 . V_40 == V_78 ) {
struct V_79 V_79 ;
V_19 = sprintf ( V_5 , L_11 ,
F_62 ( V_11 , & V_79 )
? 0 : V_79 . V_80 ) ;
}
return V_19 ;
}
static T_1 F_63 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_39 . V_40 == V_78 ) {
struct V_79 V_79 ;
V_19 = sprintf ( V_5 , L_11 ,
F_62 ( V_11 , & V_79 )
? 0 : V_79 . V_81 ) ;
}
return V_19 ;
}
static T_1 F_64 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_39 . V_40 == V_78 ) {
struct V_79 V_79 ;
V_19 = sprintf ( V_5 , L_11 ,
F_62 ( V_11 , & V_79 )
? 0 : V_79 . V_82 ) ;
}
return V_19 ;
}
static T_1 F_65 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_39 . V_40 == V_78 ) {
struct V_79 V_79 ;
V_19 = sprintf ( V_5 , L_11 ,
F_62 ( V_11 , & V_79 )
? 0 : V_79 . V_83 ) ;
}
return V_19 ;
}
static T_1 F_66 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( V_11 -> V_39 . V_40 == V_78 ) {
struct V_79 V_79 ;
if ( ! F_62 ( V_11 , & V_79 ) )
V_19 = sprintf ( V_5 , L_16 , V_79 . V_84 ) ;
}
return V_19 ;
}
static T_1 F_67 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_31 * V_32 ;
struct V_33 * V_33 ;
int V_9 = 0 ;
if ( ! F_15 () )
return F_16 () ;
F_17 (bond, slave, iter) {
if ( V_9 > ( V_12 - V_13 - 6 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_17 ,
V_33 -> V_14 -> V_15 , V_33 -> V_85 ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static T_1 F_68 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_86 , ( char * ) V_18 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_69 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_87 ) ;
}
static T_1 F_70 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_88 ,
( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_71 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_89 ) ;
}
static T_1 F_72 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_90 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_73 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_39 . V_91 ) ;
}
static T_1 F_74 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_92 , ( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
static T_1 F_75 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
unsigned int V_93 = V_11 -> V_39 . V_93 ;
return sprintf ( V_5 , L_18 , V_93 ) ;
}
static T_1 F_76 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_34 ;
V_34 = F_19 ( V_11 , V_94 ,
( char * ) V_5 ) ;
if ( ! V_34 )
V_34 = V_19 ;
return V_34 ;
}
int F_77 ( struct V_6 * V_7 )
{
int V_34 ;
V_7 -> V_8 = V_8 ;
F_78 ( & V_7 -> V_8 . V_4 ) ;
V_34 = F_79 ( & V_7 -> V_8 ,
V_7 -> V_23 ) ;
if ( V_34 == - V_24 ) {
if ( F_80 ( V_7 -> V_23 ,
V_8 . V_4 . V_15 ) )
F_12 ( L_19 ,
V_8 . V_4 . V_15 ) ;
V_34 = 0 ;
}
return V_34 ;
}
void F_81 ( struct V_6 * V_7 )
{
F_82 ( & V_7 -> V_8 , V_7 -> V_23 ) ;
}
void F_83 ( struct V_10 * V_11 )
{
V_11 -> V_14 -> V_95 [ 0 ] = & V_96 ;
}
