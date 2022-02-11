static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_1 ) ;
}
static int T_2 F_2 ( void )
{
return F_3 ( V_4 , & V_5 . V_2 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 , char * V_3 )
{
const char * type ;
switch ( V_6 ) {
case V_7 :
type = L_2 ;
break;
case V_8 :
type = L_3 ;
break;
case V_9 :
type = F_5 () ? L_4 : L_5 ;
break;
default:
return - V_10 ;
}
return sprintf ( V_3 , L_6 , type ) ;
}
static int T_2 F_6 ( void )
{
return F_3 ( V_4 , & V_11 . V_2 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_3 )
{
int V_12 = F_8 ( V_13 , NULL ) ;
if ( V_12 )
return sprintf ( V_3 , L_7 , V_12 >> 16 ) ;
return - V_14 ;
}
static T_1 F_9 ( struct V_1 * V_2 , char * V_3 )
{
int V_12 = F_8 ( V_13 , NULL ) ;
if ( V_12 )
return sprintf ( V_3 , L_7 , V_12 & 0xff ) ;
return - V_14 ;
}
static T_1 F_10 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 = - V_16 ;
char * V_17 ;
V_17 = F_11 ( V_18 , V_19 ) ;
if ( V_17 ) {
V_15 = F_8 ( V_20 , V_17 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_6 , V_17 ) ;
F_12 ( V_17 ) ;
}
return V_15 ;
}
static int T_2 F_13 ( void )
{
return F_14 ( V_4 , & V_21 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , char * V_3 )
{
char * V_22 , * V_23 ;
int V_15 ;
extern int V_24 ;
if ( ! V_24 )
return - V_25 ;
V_22 = F_16 ( V_26 , L_8 , L_9 , NULL ) ;
if ( F_17 ( V_22 ) )
return F_18 ( V_22 ) ;
V_23 = F_16 ( V_26 , V_22 , L_10 , NULL ) ;
F_12 ( V_22 ) ;
if ( F_17 ( V_23 ) )
return F_18 ( V_23 ) ;
V_15 = sprintf ( V_3 , L_6 , V_23 ) ;
F_12 ( V_23 ) ;
return V_15 ;
}
static T_1 F_19 ( struct V_1 * V_2 , char * V_3 )
{
T_3 V_27 ;
int V_15 ;
V_15 = F_8 ( V_28 , V_27 ) ;
if ( V_15 )
return F_15 ( V_2 , V_3 ) ;
V_15 = sprintf ( V_3 , L_11 , V_27 ) ;
return V_15 ;
}
static int T_2 F_20 ( void )
{
return F_3 ( V_4 , & V_29 . V_2 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 = - V_16 ;
struct V_30 * V_31 ;
V_31 = F_11 ( sizeof( struct V_30 ) , V_19 ) ;
if ( V_31 ) {
V_15 = F_8 ( V_32 , V_31 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_6 , V_31 -> V_33 ) ;
F_12 ( V_31 ) ;
}
return V_15 ;
}
static T_1 F_22 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 = - V_16 ;
struct V_30 * V_31 ;
V_31 = F_11 ( sizeof( struct V_30 ) , V_19 ) ;
if ( V_31 ) {
V_15 = F_8 ( V_32 , V_31 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_6 , V_31 -> V_34 ) ;
F_12 ( V_31 ) ;
}
return V_15 ;
}
static T_1 F_23 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 = - V_16 ;
struct V_30 * V_31 ;
V_31 = F_11 ( sizeof( struct V_30 ) , V_19 ) ;
if ( V_31 ) {
V_15 = F_8 ( V_32 , V_31 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_6 , V_31 -> V_35 ) ;
F_12 ( V_31 ) ;
}
return V_15 ;
}
static int T_2 F_24 ( void )
{
return F_14 ( V_4 , & V_36 ) ;
}
static T_1 F_25 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 = - V_16 ;
char * V_37 ;
V_37 = F_11 ( V_38 , V_19 ) ;
if ( V_37 ) {
V_15 = F_8 ( V_39 , V_37 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_6 , V_37 ) ;
F_12 ( V_37 ) ;
}
return V_15 ;
}
static T_1 F_26 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 = - V_16 ;
char * V_40 ;
V_40 = F_11 ( V_41 , V_19 ) ;
if ( V_40 ) {
V_15 = F_8 ( V_42 , V_40 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_6 , V_40 ) ;
F_12 ( V_40 ) ;
}
return V_15 ;
}
static T_1 F_27 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 = - V_16 ;
struct V_43 * V_44 ;
V_44 = F_11 ( sizeof( struct V_43 ) , V_19 ) ;
if ( V_44 ) {
V_15 = F_8 ( V_45 ,
V_44 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_12 V_46 L_13 ,
V_44 -> V_47 ) ;
F_12 ( V_44 ) ;
}
return V_15 ;
}
static T_1 F_28 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 ;
V_15 = F_8 ( V_48 , NULL ) ;
if ( V_15 > 0 )
V_15 = sprintf ( V_3 , L_14 , V_15 ) ;
return V_15 ;
}
static T_1 F_29 ( int V_49 , char * V_3 )
{
T_1 V_15 ;
struct V_50 V_31 ;
V_31 . V_51 = V_49 ;
V_15 = F_8 ( V_52 , & V_31 ) ;
if ( ! V_15 )
V_15 = sprintf ( V_3 , L_15 , V_31 . V_53 ) ;
return V_15 ;
}
static T_1 F_30 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_54 ;
int V_55 ;
V_54 = 0 ;
for ( V_55 = V_56 - 1 ; V_55 >= 0 ; V_55 -- ) {
int V_15 = F_29 ( V_55 , V_3 + V_54 ) ;
if ( V_15 < 0 ) {
if ( V_54 == 0 )
V_54 = V_15 ;
break;
}
V_54 += V_15 ;
}
if ( V_54 > 0 )
V_3 [ V_54 ++ ] = '\n' ;
return V_54 ;
}
static T_1 F_31 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_15 ;
struct V_57 * V_58 ;
V_15 = F_8 ( V_59 , NULL ) ;
if ( V_15 < 0 ) {
if ( V_15 == - V_60 )
V_15 = sprintf ( V_3 , L_16 ) ;
return V_15 ;
}
V_58 = F_11 ( sizeof( * V_58 ) + V_15 , V_19 ) ;
if ( ! V_58 )
return - V_16 ;
V_58 -> V_54 = V_15 ;
V_15 = F_8 ( V_59 , V_58 ) ;
if ( V_15 > 0 )
V_15 = sprintf ( V_3 , L_17 , V_58 -> V_61 ) ;
F_12 ( V_58 ) ;
return V_15 ;
}
static int T_2 F_32 ( void )
{
return F_14 ( V_4 , & V_62 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
const char * V_3 , T_4 V_54 )
{
int V_15 ;
struct V_63 V_64 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < F_34 ( V_65 ) ; V_55 ++ ) {
if ( strncmp ( V_3 , V_65 [ V_55 ] . V_66 , V_54 - 1 ) == 0 ) {
V_64 . V_23 = V_65 [ V_55 ] . V_67 ;
break;
}
}
if ( V_55 == F_34 ( V_65 ) )
return - V_10 ;
V_64 . V_12 . V_68 = V_69 ;
V_64 . V_12 . V_70 = V_71 ;
V_15 = F_35 ( V_72 , & V_64 ) ;
if ( V_15 )
return V_15 ;
return V_54 ;
}
static T_1 F_36 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 ;
struct V_63 V_64 ;
int V_55 ;
T_5 V_67 ;
V_64 . V_12 . V_68 = V_69 ;
V_64 . V_12 . V_70 = V_71 ;
V_15 = F_35 ( V_73 , & V_64 ) ;
if ( V_15 )
return V_15 ;
V_67 = ( T_5 ) V_64 . V_23 ;
for ( V_55 = 0 ; V_55 < F_34 ( V_65 ) ; V_55 ++ ) {
if ( V_67 == V_65 [ V_55 ] . V_67 )
return sprintf ( V_3 , L_6 , V_65 [ V_55 ] . V_66 ) ;
}
return - V_10 ;
}
static T_1 F_37 ( struct V_1 * V_2 ,
const char * V_3 , T_4 V_54 )
{
int V_15 ;
T_5 V_74 ;
struct V_63 V_64 ;
V_15 = F_38 ( V_3 , 0 , & V_74 ) ;
if ( V_15 )
return V_15 ;
V_64 . V_23 = V_74 ;
V_64 . V_12 . V_68 = V_69 ;
V_64 . V_12 . V_70 = V_71 ;
V_15 = F_35 ( V_75 , & V_64 ) ;
if ( V_15 )
return V_15 ;
return V_54 ;
}
static T_1 F_39 ( struct V_1 * V_2 , char * V_3 )
{
int V_15 ;
struct V_63 V_64 ;
V_64 . V_12 . V_68 = V_69 ;
V_64 . V_12 . V_70 = V_71 ;
V_15 = F_35 ( V_76 , & V_64 ) ;
if ( V_15 )
return V_15 ;
return sprintf ( V_3 , L_18 , ( T_5 ) V_64 . V_23 ) ;
}
static int T_2 F_40 ( void )
{
return F_14 ( V_4 , & V_77 ) ;
}
static int T_2 F_41 ( void )
{
int V_15 ;
if ( ! F_42 () )
return - V_14 ;
V_15 = F_2 () ;
if ( V_15 )
goto V_78;
V_15 = F_6 () ;
if ( V_15 )
goto V_79;
V_15 = F_13 () ;
if ( V_15 )
goto V_80;
V_15 = F_24 () ;
if ( V_15 )
goto V_81;
V_15 = F_20 () ;
if ( V_15 )
goto V_82;
V_15 = F_32 () ;
if ( V_15 )
goto V_83;
#ifdef F_43
if ( F_44 () ) {
V_15 = F_40 () ;
if ( V_15 ) {
F_45 ( V_4 ,
& V_62 ) ;
goto V_83;
}
}
#endif
goto V_78;
V_83:
F_46 ( V_4 , & V_29 . V_2 ) ;
V_82:
F_45 ( V_4 , & V_36 ) ;
V_81:
F_45 ( V_4 , & V_21 ) ;
V_80:
F_46 ( V_4 , & V_11 . V_2 ) ;
V_79:
F_46 ( V_4 , & V_5 . V_2 ) ;
V_78:
return V_15 ;
}
static T_1 F_47 ( struct V_84 * V_85 ,
struct V_86 * V_2 ,
char * V_3 )
{
struct V_1 * V_87 ;
V_87 = F_48 ( V_2 , struct V_1 , V_2 ) ;
if ( V_87 -> V_88 )
return V_87 -> V_88 ( V_87 , V_3 ) ;
return 0 ;
}
static T_1 F_49 ( struct V_84 * V_85 ,
struct V_86 * V_2 ,
const char * V_3 ,
T_4 V_54 )
{
struct V_1 * V_87 ;
V_87 = F_48 ( V_2 , struct V_1 , V_2 ) ;
if ( V_87 -> V_89 )
return V_87 -> V_89 ( V_87 , V_3 , V_54 ) ;
return 0 ;
}
static int T_2 F_50 ( void )
{
if ( ! F_42 () )
return - V_14 ;
V_4 -> V_90 = & V_91 ;
return 0 ;
}
