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
int V_6 = F_5 ( V_7 , NULL ) ;
if ( V_6 )
return sprintf ( V_3 , L_2 , V_6 >> 16 ) ;
return - V_8 ;
}
static T_1 F_6 ( struct V_1 * V_2 , char * V_3 )
{
int V_6 = F_5 ( V_7 , NULL ) ;
if ( V_6 )
return sprintf ( V_3 , L_2 , V_6 & 0xff ) ;
return - V_8 ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_11 ;
V_11 = F_8 ( V_12 , V_13 ) ;
if ( V_11 ) {
V_9 = F_5 ( V_14 , V_11 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_11 ) ;
F_9 ( V_11 ) ;
}
return V_9 ;
}
static int T_2 F_10 ( void )
{
return F_11 ( V_4 , & V_15 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , char * V_3 )
{
char * V_16 , * V_17 ;
int V_9 ;
extern int V_18 ;
if ( ! V_18 )
return - V_19 ;
V_16 = F_13 ( V_20 , L_4 , L_5 , NULL ) ;
if ( F_14 ( V_16 ) )
return F_15 ( V_16 ) ;
V_17 = F_13 ( V_20 , V_16 , L_6 , NULL ) ;
F_9 ( V_16 ) ;
if ( F_14 ( V_17 ) )
return F_15 ( V_17 ) ;
V_9 = sprintf ( V_3 , L_3 , V_17 ) ;
F_9 ( V_17 ) ;
return V_9 ;
}
static T_1 F_16 ( struct V_1 * V_2 , char * V_3 )
{
T_3 V_21 ;
int V_9 ;
V_9 = F_5 ( V_22 , V_21 ) ;
if ( V_9 )
return F_12 ( V_2 , V_3 ) ;
V_9 = sprintf ( V_3 , L_7 , V_21 ) ;
return V_9 ;
}
static int T_2 F_17 ( void )
{
return F_3 ( V_4 , & V_23 . V_2 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_24 * V_25 ;
V_25 = F_8 ( sizeof( struct V_24 ) , V_13 ) ;
if ( V_25 ) {
V_9 = F_5 ( V_26 , V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_25 -> V_27 ) ;
F_9 ( V_25 ) ;
}
return V_9 ;
}
static T_1 F_19 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_24 * V_25 ;
V_25 = F_8 ( sizeof( struct V_24 ) , V_13 ) ;
if ( V_25 ) {
V_9 = F_5 ( V_26 , V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_25 -> V_28 ) ;
F_9 ( V_25 ) ;
}
return V_9 ;
}
static T_1 F_20 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_24 * V_25 ;
V_25 = F_8 ( sizeof( struct V_24 ) , V_13 ) ;
if ( V_25 ) {
V_9 = F_5 ( V_26 , V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_25 -> V_29 ) ;
F_9 ( V_25 ) ;
}
return V_9 ;
}
static int T_2 F_21 ( void )
{
return F_11 ( V_4 , & V_30 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_31 ;
V_31 = F_8 ( V_32 , V_13 ) ;
if ( V_31 ) {
V_9 = F_5 ( V_33 , V_31 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_31 ) ;
F_9 ( V_31 ) ;
}
return V_9 ;
}
static T_1 F_23 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_34 ;
V_34 = F_8 ( V_35 , V_13 ) ;
if ( V_34 ) {
V_9 = F_5 ( V_36 , V_34 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_34 ) ;
F_9 ( V_34 ) ;
}
return V_9 ;
}
static T_1 F_24 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_37 * V_38 ;
V_38 = F_8 ( sizeof( struct V_37 ) , V_13 ) ;
if ( V_38 ) {
V_9 = F_5 ( V_39 ,
V_38 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_8 V_40 L_9 ,
V_38 -> V_41 ) ;
F_9 ( V_38 ) ;
}
return V_9 ;
}
static T_1 F_25 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 ;
V_9 = F_5 ( V_42 , NULL ) ;
if ( V_9 > 0 )
V_9 = sprintf ( V_3 , L_10 , V_9 ) ;
return V_9 ;
}
static T_1 F_26 ( int V_43 , char * V_3 )
{
T_1 V_9 ;
struct V_44 V_25 ;
V_25 . V_45 = V_43 ;
V_9 = F_5 ( V_46 , & V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_11 , V_25 . V_47 ) ;
return V_9 ;
}
static T_1 F_27 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_48 ;
int V_49 ;
V_48 = 0 ;
for ( V_49 = V_50 - 1 ; V_49 >= 0 ; V_49 -- ) {
int V_9 = F_26 ( V_49 , V_3 + V_48 ) ;
if ( V_9 < 0 ) {
if ( V_48 == 0 )
V_48 = V_9 ;
break;
}
V_48 += V_9 ;
}
if ( V_48 > 0 )
V_3 [ V_48 ++ ] = '\n' ;
return V_48 ;
}
static int T_2 F_28 ( void )
{
return F_11 ( V_4 , & V_51 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 ,
const char * V_3 , T_4 V_48 )
{
int V_9 ;
struct V_52 V_53 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < F_30 ( V_54 ) ; V_49 ++ ) {
if ( strncmp ( V_3 , V_54 [ V_49 ] . V_55 , V_48 - 1 ) == 0 ) {
V_53 . V_17 = V_54 [ V_49 ] . V_56 ;
break;
}
}
if ( V_49 == F_30 ( V_54 ) )
return - V_57 ;
V_53 . V_6 . V_58 = V_59 ;
V_53 . V_6 . V_60 = V_61 ;
V_9 = F_31 ( V_62 , & V_53 ) ;
if ( V_9 )
return V_9 ;
return V_48 ;
}
static T_1 F_32 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 ;
struct V_52 V_53 ;
int V_49 ;
T_5 V_56 ;
V_53 . V_6 . V_58 = V_59 ;
V_53 . V_6 . V_60 = V_61 ;
V_9 = F_31 ( V_63 , & V_53 ) ;
if ( V_9 )
return V_9 ;
V_56 = ( T_5 ) V_53 . V_17 ;
for ( V_49 = 0 ; V_49 < F_30 ( V_54 ) ; V_49 ++ ) {
if ( V_56 == V_54 [ V_49 ] . V_56 )
return sprintf ( V_3 , L_3 , V_54 [ V_49 ] . V_55 ) ;
}
return - V_57 ;
}
static T_1 F_33 ( struct V_1 * V_2 ,
const char * V_3 , T_4 V_48 )
{
int V_9 ;
T_5 V_64 ;
struct V_52 V_53 ;
V_9 = F_34 ( V_3 , 0 , & V_64 ) ;
if ( V_9 )
return V_9 ;
V_53 . V_17 = V_64 ;
V_53 . V_6 . V_58 = V_59 ;
V_53 . V_6 . V_60 = V_61 ;
V_9 = F_31 ( V_65 , & V_53 ) ;
if ( V_9 )
return V_9 ;
return V_48 ;
}
static T_1 F_35 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 ;
struct V_52 V_53 ;
V_53 . V_6 . V_58 = V_59 ;
V_53 . V_6 . V_60 = V_61 ;
V_9 = F_31 ( V_66 , & V_53 ) ;
if ( V_9 )
return V_9 ;
return sprintf ( V_3 , L_12 , ( T_5 ) V_53 . V_17 ) ;
}
static int T_2 F_36 ( void )
{
return F_11 ( V_4 , & V_67 ) ;
}
static int T_2 F_37 ( void )
{
int V_9 ;
if ( ! F_38 () )
return - V_8 ;
V_9 = F_2 () ;
if ( V_9 )
goto V_68;
V_9 = F_10 () ;
if ( V_9 )
goto V_69;
V_9 = F_21 () ;
if ( V_9 )
goto V_70;
V_9 = F_17 () ;
if ( V_9 )
goto V_71;
V_9 = F_28 () ;
if ( V_9 )
goto V_72;
#ifdef F_39
if ( F_40 () ) {
V_9 = F_36 () ;
if ( V_9 ) {
F_41 ( V_4 ,
& V_51 ) ;
goto V_72;
}
}
#endif
goto V_68;
V_72:
F_42 ( V_4 , & V_23 . V_2 ) ;
V_71:
F_41 ( V_4 , & V_30 ) ;
V_70:
F_41 ( V_4 , & V_15 ) ;
V_69:
F_42 ( V_4 , & V_5 . V_2 ) ;
V_68:
return V_9 ;
}
static T_1 F_43 ( struct V_73 * V_74 ,
struct V_75 * V_2 ,
char * V_3 )
{
struct V_1 * V_76 ;
V_76 = F_44 ( V_2 , struct V_1 , V_2 ) ;
if ( V_76 -> V_77 )
return V_76 -> V_77 ( V_76 , V_3 ) ;
return 0 ;
}
static T_1 F_45 ( struct V_73 * V_74 ,
struct V_75 * V_2 ,
const char * V_3 ,
T_4 V_48 )
{
struct V_1 * V_76 ;
V_76 = F_44 ( V_2 , struct V_1 , V_2 ) ;
if ( V_76 -> V_78 )
return V_76 -> V_78 ( V_76 , V_3 , V_48 ) ;
return 0 ;
}
static int T_2 F_46 ( void )
{
if ( ! F_38 () )
return - V_8 ;
V_4 -> V_79 = & V_80 ;
return 0 ;
}
