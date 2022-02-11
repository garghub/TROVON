static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return sprintf ( V_3 , L_1 ) ;
}
static int T_2 F_2 ( void )
{
return F_3 ( V_4 , & V_5 . V_2 ) ;
}
static void F_4 ( void )
{
F_5 ( V_4 , & V_5 . V_2 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , char * V_3 )
{
int V_6 = F_7 ( V_7 , NULL ) ;
if ( V_6 )
return sprintf ( V_3 , L_2 , V_6 >> 16 ) ;
return - V_8 ;
}
static T_1 F_8 ( struct V_1 * V_2 , char * V_3 )
{
int V_6 = F_7 ( V_7 , NULL ) ;
if ( V_6 )
return sprintf ( V_3 , L_2 , V_6 & 0xff ) ;
return - V_8 ;
}
static T_1 F_9 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_11 ;
V_11 = F_10 ( V_12 , V_13 ) ;
if ( V_11 ) {
V_9 = F_7 ( V_14 , V_11 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_11 ) ;
F_11 ( V_11 ) ;
}
return V_9 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( V_4 , & V_15 ) ;
}
static void F_14 ( void )
{
F_15 ( V_4 , & V_15 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , char * V_3 )
{
char * V_16 , * V_17 ;
int V_9 ;
extern int V_18 ;
if ( ! V_18 )
return - V_19 ;
V_16 = F_17 ( V_20 , L_4 , L_5 , NULL ) ;
if ( F_18 ( V_16 ) )
return F_19 ( V_16 ) ;
V_17 = F_17 ( V_20 , V_16 , L_6 , NULL ) ;
F_11 ( V_16 ) ;
if ( F_18 ( V_17 ) )
return F_19 ( V_17 ) ;
V_9 = sprintf ( V_3 , L_3 , V_17 ) ;
F_11 ( V_17 ) ;
return V_9 ;
}
static T_1 F_20 ( struct V_1 * V_2 , char * V_3 )
{
T_3 V_21 ;
int V_9 ;
V_9 = F_7 ( V_22 , V_21 ) ;
if ( V_9 )
return F_16 ( V_2 , V_3 ) ;
V_9 = sprintf ( V_3 , L_7 , V_21 ) ;
return V_9 ;
}
static int T_2 F_21 ( void )
{
return F_3 ( V_4 , & V_23 . V_2 ) ;
}
static void F_22 ( void )
{
F_5 ( V_4 , & V_23 . V_2 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_24 * V_25 ;
V_25 = F_10 ( sizeof( struct V_24 ) , V_13 ) ;
if ( V_25 ) {
V_9 = F_7 ( V_26 , V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_25 -> V_27 ) ;
F_11 ( V_25 ) ;
}
return V_9 ;
}
static T_1 F_24 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_24 * V_25 ;
V_25 = F_10 ( sizeof( struct V_24 ) , V_13 ) ;
if ( V_25 ) {
V_9 = F_7 ( V_26 , V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_25 -> V_28 ) ;
F_11 ( V_25 ) ;
}
return V_9 ;
}
static T_1 F_25 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_24 * V_25 ;
V_25 = F_10 ( sizeof( struct V_24 ) , V_13 ) ;
if ( V_25 ) {
V_9 = F_7 ( V_26 , V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_25 -> V_29 ) ;
F_11 ( V_25 ) ;
}
return V_9 ;
}
static int T_2 F_26 ( void )
{
return F_13 ( V_4 , & V_30 ) ;
}
static void F_27 ( void )
{
F_15 ( V_4 , & V_30 ) ;
}
static T_1 F_28 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_31 ;
V_31 = F_10 ( V_32 , V_13 ) ;
if ( V_31 ) {
V_9 = F_7 ( V_33 , V_31 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_31 ) ;
F_11 ( V_31 ) ;
}
return V_9 ;
}
static T_1 F_29 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_34 ;
V_34 = F_10 ( V_35 , V_13 ) ;
if ( V_34 ) {
V_9 = F_7 ( V_36 , V_34 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_34 ) ;
F_11 ( V_34 ) ;
}
return V_9 ;
}
static T_1 F_30 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_37 * V_38 ;
V_38 = F_10 ( sizeof( struct V_37 ) , V_13 ) ;
if ( V_38 ) {
V_9 = F_7 ( V_39 ,
V_38 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_8 V_40 L_9 ,
V_38 -> V_41 ) ;
F_11 ( V_38 ) ;
}
return V_9 ;
}
static T_1 F_31 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 ;
V_9 = F_7 ( V_42 , NULL ) ;
if ( V_9 > 0 )
V_9 = sprintf ( V_3 , L_10 , V_9 ) ;
return V_9 ;
}
static T_1 F_32 ( int V_43 , char * V_3 )
{
T_1 V_9 ;
struct V_44 V_25 ;
V_25 . V_45 = V_43 ;
V_9 = F_7 ( V_46 , & V_25 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_11 , V_25 . V_47 ) ;
return V_9 ;
}
static T_1 F_33 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_48 ;
int V_49 ;
V_48 = 0 ;
for ( V_49 = V_50 - 1 ; V_49 >= 0 ; V_49 -- ) {
int V_9 = F_32 ( V_49 , V_3 + V_48 ) ;
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
static int T_2 F_34 ( void )
{
return F_13 ( V_4 , & V_51 ) ;
}
static void F_35 ( void )
{
F_15 ( V_4 , & V_51 ) ;
}
static int T_2 F_36 ( void )
{
int V_9 ;
if ( ! F_37 () )
return - V_8 ;
V_9 = F_2 () ;
if ( V_9 )
goto V_52;
V_9 = F_12 () ;
if ( V_9 )
goto V_53;
V_9 = F_26 () ;
if ( V_9 )
goto V_54;
V_9 = F_21 () ;
if ( V_9 )
goto V_55;
V_9 = F_34 () ;
if ( V_9 )
goto V_56;
goto V_52;
V_56:
F_22 () ;
V_55:
F_27 () ;
V_54:
F_14 () ;
V_53:
F_4 () ;
V_52:
return V_9 ;
}
static void T_4 F_38 ( void )
{
F_35 () ;
F_27 () ;
F_22 () ;
F_14 () ;
F_4 () ;
}
static T_1 F_39 ( struct V_57 * V_58 ,
struct V_59 * V_2 ,
char * V_3 )
{
struct V_1 * V_60 ;
V_60 = F_40 ( V_2 , struct V_1 , V_2 ) ;
if ( V_60 -> V_61 )
return V_60 -> V_61 ( V_60 , V_3 ) ;
return 0 ;
}
static T_1 F_41 ( struct V_57 * V_58 ,
struct V_59 * V_2 ,
const char * V_3 ,
T_5 V_48 )
{
struct V_1 * V_60 ;
V_60 = F_40 ( V_2 , struct V_1 , V_2 ) ;
if ( V_60 -> V_62 )
return V_60 -> V_62 ( V_60 , V_3 , V_48 ) ;
return 0 ;
}
static int T_2 F_42 ( void )
{
if ( ! F_37 () )
return - V_8 ;
V_4 -> V_63 = & V_64 ;
return 0 ;
}
