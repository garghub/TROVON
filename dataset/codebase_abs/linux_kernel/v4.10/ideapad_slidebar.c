static T_1 F_1 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_3 ( 0xf4 , 0xff29 ) ;
F_3 ( 0xbf , 0xff2a ) ;
V_1 = F_4 ( 0xff2b ) ;
F_5 ( & V_3 , V_2 ) ;
return V_1 ;
}
static T_1 F_6 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_3 ( 0xf7 , 0xff29 ) ;
F_3 ( 0x8b , 0xff2a ) ;
V_1 = F_4 ( 0xff2b ) ;
F_5 ( & V_3 , V_2 ) ;
return V_1 ;
}
static void F_7 ( T_1 V_4 )
{
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
F_3 ( 0xf7 , 0xff29 ) ;
F_3 ( 0x8b , 0xff2a ) ;
F_3 ( V_4 , 0xff2b ) ;
F_5 ( & V_3 , V_2 ) ;
}
static bool F_8 ( unsigned char V_5 , unsigned char V_6 ,
struct V_7 * V_8 )
{
static bool V_9 = false ;
if ( V_6 & V_10 )
return false ;
if ( V_5 == 0xe0 ) {
V_9 = true ;
return true ;
}
if ( ! V_9 )
return false ;
V_9 = false ;
if ( F_9 ( ( V_5 & 0x7f ) != 0x3b ) ) {
F_10 ( V_8 , 0xe0 , 0 ) ;
return false ;
}
if ( V_5 & 0x80 ) {
F_11 ( V_11 , V_12 , 0 ) ;
} else {
F_11 ( V_11 , V_12 , 1 ) ;
F_12 ( V_11 , V_13 , F_1 () ) ;
}
F_13 ( V_11 ) ;
return true ;
}
static T_2 F_14 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
return sprintf ( V_18 , L_1 , F_6 () ) ;
}
static T_2 F_15 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_3 V_19 )
{
T_1 V_4 ;
int error ;
error = F_16 ( V_18 , 0 , & V_4 ) ;
if ( error )
return error ;
F_7 ( V_4 ) ;
return V_19 ;
}
static int T_4 F_17 ( struct V_20 * V_21 )
{
int V_22 ;
if ( ! F_18 ( V_23 , 3 , L_2 ) ) {
F_19 ( & V_21 -> V_15 , L_3 ) ;
return - V_24 ;
}
V_11 = F_20 () ;
if ( ! V_11 ) {
F_19 ( & V_21 -> V_15 , L_4 ) ;
V_22 = - V_25 ;
goto V_26;
}
V_11 -> V_27 = L_5 ;
V_11 -> V_28 . V_29 = V_30 ;
V_11 -> V_15 . V_31 = & V_21 -> V_15 ;
F_21 ( V_11 , V_32 , V_12 ) ;
F_21 ( V_11 , V_33 , V_13 ) ;
F_22 ( V_11 , V_13 , 0 , 0xff , 0 , 0 ) ;
V_22 = F_23 ( F_8 ) ;
if ( V_22 ) {
F_19 ( & V_21 -> V_15 ,
L_6 , V_22 ) ;
goto V_34;
}
V_22 = F_24 ( V_11 ) ;
if ( V_22 ) {
F_19 ( & V_21 -> V_15 ,
L_7 , V_22 ) ;
goto V_35;
}
return 0 ;
V_35:
F_25 ( F_8 ) ;
V_34:
F_26 ( V_11 ) ;
V_26:
F_27 ( V_23 , 3 ) ;
return V_22 ;
}
static int F_28 ( struct V_20 * V_21 )
{
F_25 ( F_8 ) ;
F_29 ( V_11 ) ;
F_27 ( V_23 , 3 ) ;
return 0 ;
}
static int T_4 F_30 ( const struct V_36 * V_28 )
{
F_31 ( L_8 , V_28 -> V_37 ) ;
return 1 ;
}
static int T_4 F_32 ( void )
{
int V_22 ;
if ( ! V_38 && ! F_33 ( V_39 ) ) {
F_34 ( L_9 ) ;
return - V_40 ;
}
V_41 = F_35 ( L_2 , - 1 ) ;
if ( ! V_41 ) {
F_34 ( L_10 ) ;
return - V_25 ;
}
V_41 -> V_15 . V_42 = V_43 ;
V_22 = F_36 ( V_41 ) ;
if ( V_22 ) {
F_34 ( L_11 ) ;
goto V_34;
}
V_22 = F_37 ( & V_44 , F_17 ) ;
if ( V_22 ) {
F_34 ( L_12 ) ;
goto V_45;
}
return 0 ;
V_45:
F_38 ( V_41 ) ;
V_34:
F_39 ( V_41 ) ;
return V_22 ;
}
static void T_5 F_40 ( void )
{
F_41 ( V_41 ) ;
F_42 ( & V_44 ) ;
}
