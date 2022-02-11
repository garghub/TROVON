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
struct V_30 * V_4 ,
const char * V_18 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_31 * V_32 ;
int V_33 ;
V_32 = F_15 ( V_4 -> V_4 . V_15 ) ;
if ( F_16 ( ! V_32 ) )
return - V_34 ;
V_33 = F_17 ( V_11 , V_32 -> V_35 , ( char * ) V_18 ) ;
if ( ! V_33 )
V_33 = V_19 ;
return V_33 ;
}
static T_1 F_18 ( struct V_28 * V_29 ,
struct V_30 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
struct V_38 * V_38 ;
int V_9 = 0 ;
if ( ! F_19 () )
return F_20 () ;
F_21 (bond, slave, iter) {
if ( V_9 > ( V_12 - V_13 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_2 , V_38 -> V_14 -> V_15 ) ;
}
F_5 () ;
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_22 ( struct V_28 * V_29 ,
struct V_30 * V_4 , char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_41 , F_24 ( V_11 ) ) ;
return sprintf ( V_5 , L_10 , V_40 -> string , F_24 ( V_11 ) ) ;
}
static T_1 F_25 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_42 , V_11 -> V_43 . V_44 ) ;
return sprintf ( V_5 , L_10 , V_40 -> string , V_11 -> V_43 . V_44 ) ;
}
static T_1 F_26 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_45 ,
V_11 -> V_43 . V_46 ) ;
return sprintf ( V_5 , L_10 , V_40 -> string , V_11 -> V_43 . V_46 ) ;
}
static T_1 F_27 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_47 ,
V_11 -> V_43 . V_48 ) ;
return sprintf ( V_5 , L_10 ,
V_40 -> string , V_11 -> V_43 . V_48 ) ;
}
static T_1 F_28 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_49 ,
V_11 -> V_43 . V_50 ) ;
return sprintf ( V_5 , L_10 , V_40 -> string , V_11 -> V_43 . V_50 ) ;
}
static T_1 F_29 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_51 ) ;
}
static T_1 F_30 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_52 , V_9 = 0 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
if ( V_11 -> V_43 . V_54 [ V_52 ] )
V_9 += sprintf ( V_5 + V_9 , L_12 ,
& V_11 -> V_43 . V_54 [ V_52 ] ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
return V_9 ;
}
static T_1 F_31 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_55 * V_11 -> V_43 . V_56 ) ;
}
static T_1 F_32 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_57 * V_11 -> V_43 . V_56 ) ;
}
static T_1 F_33 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_58 , V_11 -> V_43 . V_59 ) ;
return sprintf ( V_5 , L_10 , V_40 -> string , V_11 -> V_43 . V_59 ) ;
}
static T_1 F_34 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_13 , V_11 -> V_43 . V_60 ) ;
}
static T_1 F_35 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_61 , V_11 -> V_43 . V_62 ) ;
return sprintf ( V_5 , L_10 , V_40 -> string , V_11 -> V_43 . V_62 ) ;
}
static T_1 F_36 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_63 ) ;
}
static T_1 F_37 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
const char * V_5 , T_2 V_19 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
int V_33 ;
V_33 = F_17 ( V_11 , V_64 , ( char * ) V_5 ) ;
if ( ! V_33 )
V_33 = V_19 ;
return V_33 ;
}
static T_1 F_38 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_56 ) ;
}
static T_1 F_39 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_38 * V_65 ;
int V_19 = 0 ;
F_40 () ;
V_65 = F_41 ( V_11 -> V_66 ) ;
if ( V_65 )
V_19 = sprintf ( V_5 , L_14 , V_65 -> V_14 -> V_15 ) ;
F_42 () ;
return V_19 ;
}
static T_1 F_43 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
const struct V_39 * V_40 ;
V_40 = F_23 ( V_67 ,
V_11 -> V_43 . V_68 ) ;
return sprintf ( V_5 , L_10 ,
V_40 -> string , V_11 -> V_43 . V_68 ) ;
}
static T_1 F_44 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_69 ) ;
}
static T_1 F_45 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_16 * V_70 ;
int V_19 = 0 ;
F_40 () ;
V_70 = F_46 ( V_11 ) ;
if ( V_70 )
V_19 = sprintf ( V_5 , L_14 , V_70 -> V_15 ) ;
F_42 () ;
return V_19 ;
}
static T_1 F_47 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
bool V_71 = ! ! F_48 ( V_11 -> V_72 ) ;
return sprintf ( V_5 , L_14 , V_71 ? L_15 : L_16 ) ;
}
static T_1 F_49 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( F_24 ( V_11 ) == V_73 ) {
struct V_74 V_74 ;
V_19 = sprintf ( V_5 , L_11 ,
F_50 ( V_11 , & V_74 )
? 0 : V_74 . V_75 ) ;
}
return V_19 ;
}
static T_1 F_51 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( F_24 ( V_11 ) == V_73 ) {
struct V_74 V_74 ;
V_19 = sprintf ( V_5 , L_11 ,
F_50 ( V_11 , & V_74 )
? 0 : V_74 . V_76 ) ;
}
return V_19 ;
}
static T_1 F_52 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( F_24 ( V_11 ) == V_73 ) {
struct V_74 V_74 ;
V_19 = sprintf ( V_5 , L_11 ,
F_50 ( V_11 , & V_74 )
? 0 : V_74 . V_77 ) ;
}
return V_19 ;
}
static T_1 F_53 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( F_24 ( V_11 ) == V_73 ) {
struct V_74 V_74 ;
V_19 = sprintf ( V_5 , L_11 ,
F_50 ( V_11 , & V_74 )
? 0 : V_74 . V_78 ) ;
}
return V_19 ;
}
static T_1 F_54 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
int V_19 = 0 ;
struct V_10 * V_11 = F_14 ( V_29 ) ;
if ( F_24 ( V_11 ) == V_73 ) {
struct V_74 V_74 ;
if ( ! F_50 ( V_11 , & V_74 ) )
V_19 = sprintf ( V_5 , L_17 , V_74 . V_79 ) ;
}
return V_19 ;
}
static T_1 F_55 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
struct V_36 * V_37 ;
struct V_38 * V_38 ;
int V_9 = 0 ;
if ( ! F_19 () )
return F_20 () ;
F_21 (bond, slave, iter) {
if ( V_9 > ( V_12 - V_13 - 6 ) ) {
if ( ( V_12 - V_9 ) > 10 )
V_9 = V_12 - 10 ;
V_9 += sprintf ( V_5 + V_9 , L_1 ) ;
break;
}
V_9 += sprintf ( V_5 + V_9 , L_18 ,
V_38 -> V_14 -> V_15 , V_38 -> V_80 ) ;
}
if ( V_9 )
V_5 [ V_9 - 1 ] = '\n' ;
F_5 () ;
return V_9 ;
}
static T_1 F_56 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_81 ) ;
}
static T_1 F_57 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_82 ) ;
}
static T_1 F_58 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_83 ) ;
}
static T_1 F_59 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
return sprintf ( V_5 , L_11 , V_11 -> V_43 . V_84 ) ;
}
static T_1 F_60 ( struct V_28 * V_29 ,
struct V_30 * V_4 ,
char * V_5 )
{
struct V_10 * V_11 = F_14 ( V_29 ) ;
unsigned int V_85 = V_11 -> V_43 . V_85 ;
return sprintf ( V_5 , L_13 , V_85 ) ;
}
int F_61 ( struct V_6 * V_7 )
{
int V_33 ;
V_7 -> V_8 = V_8 ;
F_62 ( & V_7 -> V_8 . V_4 ) ;
V_33 = F_63 ( & V_7 -> V_8 ,
V_7 -> V_23 ) ;
if ( V_33 == - V_24 ) {
if ( F_64 ( V_7 -> V_23 ,
V_8 . V_4 . V_15 ) )
F_12 ( L_19 ,
V_8 . V_4 . V_15 ) ;
V_33 = 0 ;
}
return V_33 ;
}
void F_65 ( struct V_6 * V_7 )
{
F_66 ( & V_7 -> V_8 , V_7 -> V_23 ) ;
}
void F_67 ( struct V_10 * V_11 )
{
V_11 -> V_14 -> V_86 [ 0 ] = & V_87 ;
}
