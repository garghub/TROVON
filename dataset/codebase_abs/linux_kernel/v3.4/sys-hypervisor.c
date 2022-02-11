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
static int T_2 F_20 ( void )
{
return F_3 ( V_4 , & V_21 . V_2 ) ;
}
static void F_21 ( void )
{
F_5 ( V_4 , & V_21 . V_2 ) ;
}
static T_1 F_22 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_22 * V_23 ;
V_23 = F_10 ( sizeof( struct V_22 ) , V_13 ) ;
if ( V_23 ) {
V_9 = F_7 ( V_24 , V_23 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_23 -> V_25 ) ;
F_11 ( V_23 ) ;
}
return V_9 ;
}
static T_1 F_23 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_22 * V_23 ;
V_23 = F_10 ( sizeof( struct V_22 ) , V_13 ) ;
if ( V_23 ) {
V_9 = F_7 ( V_24 , V_23 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_23 -> V_26 ) ;
F_11 ( V_23 ) ;
}
return V_9 ;
}
static T_1 F_24 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_22 * V_23 ;
V_23 = F_10 ( sizeof( struct V_22 ) , V_13 ) ;
if ( V_23 ) {
V_9 = F_7 ( V_24 , V_23 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_23 -> V_27 ) ;
F_11 ( V_23 ) ;
}
return V_9 ;
}
static int T_2 F_25 ( void )
{
return F_13 ( V_4 , & V_28 ) ;
}
static void F_26 ( void )
{
F_15 ( V_4 , & V_28 ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_29 ;
V_29 = F_10 ( V_30 , V_13 ) ;
if ( V_29 ) {
V_9 = F_7 ( V_31 , V_29 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_29 ) ;
F_11 ( V_29 ) ;
}
return V_9 ;
}
static T_1 F_28 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
char * V_32 ;
V_32 = F_10 ( V_33 , V_13 ) ;
if ( V_32 ) {
V_9 = F_7 ( V_34 , V_32 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_3 , V_32 ) ;
F_11 ( V_32 ) ;
}
return V_9 ;
}
static T_1 F_29 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 = - V_10 ;
struct V_35 * V_36 ;
V_36 = F_10 ( sizeof( struct V_35 ) , V_13 ) ;
if ( V_36 ) {
V_9 = F_7 ( V_37 ,
V_36 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_7 , V_36 -> V_38 ) ;
F_11 ( V_36 ) ;
}
return V_9 ;
}
static T_1 F_30 ( struct V_1 * V_2 , char * V_3 )
{
int V_9 ;
V_9 = F_7 ( V_39 , NULL ) ;
if ( V_9 > 0 )
V_9 = sprintf ( V_3 , L_8 , V_9 ) ;
return V_9 ;
}
static T_1 F_31 ( int V_40 , char * V_3 )
{
T_1 V_9 ;
struct V_41 V_23 ;
V_23 . V_42 = V_40 ;
V_9 = F_7 ( V_43 , & V_23 ) ;
if ( ! V_9 )
V_9 = sprintf ( V_3 , L_9 , V_23 . V_44 ) ;
return V_9 ;
}
static T_1 F_32 ( struct V_1 * V_2 , char * V_3 )
{
T_1 V_45 ;
int V_46 ;
V_45 = 0 ;
for ( V_46 = V_47 - 1 ; V_46 >= 0 ; V_46 -- ) {
int V_9 = F_31 ( V_46 , V_3 + V_45 ) ;
if ( V_9 < 0 ) {
if ( V_45 == 0 )
V_45 = V_9 ;
break;
}
V_45 += V_9 ;
}
if ( V_45 > 0 )
V_3 [ V_45 ++ ] = '\n' ;
return V_45 ;
}
static int T_2 F_33 ( void )
{
return F_13 ( V_4 , & V_48 ) ;
}
static void F_34 ( void )
{
F_15 ( V_4 , & V_48 ) ;
}
static int T_2 F_35 ( void )
{
int V_9 ;
if ( ! F_36 () )
return - V_8 ;
V_9 = F_2 () ;
if ( V_9 )
goto V_49;
V_9 = F_12 () ;
if ( V_9 )
goto V_50;
V_9 = F_25 () ;
if ( V_9 )
goto V_51;
V_9 = F_20 () ;
if ( V_9 )
goto V_52;
V_9 = F_33 () ;
if ( V_9 )
goto V_53;
goto V_49;
V_53:
F_21 () ;
V_52:
F_26 () ;
V_51:
F_14 () ;
V_50:
F_4 () ;
V_49:
return V_9 ;
}
static void T_3 F_37 ( void )
{
F_34 () ;
F_26 () ;
F_21 () ;
F_14 () ;
F_4 () ;
}
static T_1 F_38 ( struct V_54 * V_55 ,
struct V_56 * V_2 ,
char * V_3 )
{
struct V_1 * V_57 ;
V_57 = F_39 ( V_2 , struct V_1 , V_2 ) ;
if ( V_57 -> V_58 )
return V_57 -> V_58 ( V_57 , V_3 ) ;
return 0 ;
}
static T_1 F_40 ( struct V_54 * V_55 ,
struct V_56 * V_2 ,
const char * V_3 ,
T_4 V_45 )
{
struct V_1 * V_57 ;
V_57 = F_39 ( V_2 , struct V_1 , V_2 ) ;
if ( V_57 -> V_59 )
return V_57 -> V_59 ( V_57 , V_3 , V_45 ) ;
return 0 ;
}
static int T_2 F_41 ( void )
{
if ( ! F_36 () )
return - V_8 ;
V_4 -> V_60 = & V_61 ;
return 0 ;
}
