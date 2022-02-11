static int F_1 ( void )
{
unsigned char V_1 ;
unsigned char V_2 ;
F_2 ( 0x87 , V_3 ) ;
F_2 ( 0x87 , V_3 ) ;
F_3 ( 0x20 , V_3 ) ;
V_2 = F_4 ( V_4 ) ;
if ( V_2 == 0x68 ) {
F_5 ( L_1 ,
V_2 , V_5 ) ;
F_2 ( 0x2b , V_3 ) ;
V_1 = F_6 ( V_4 ) ;
V_1 &= ~ 0x04 ;
F_2 ( 0x2b , V_3 ) ;
F_2 ( V_1 , V_4 ) ;
} else {
F_7 ( L_2 ) ;
return - V_6 ;
}
F_2 ( 0x07 , V_3 ) ;
F_2 ( 0x08 , V_4 ) ;
F_2 ( 0x30 , V_3 ) ;
V_1 = F_6 ( V_4 ) ;
F_2 ( V_1 | 0x01 , V_4 ) ;
return 0 ;
}
static void F_8 ( void )
{
F_2 ( 0xAA , V_3 ) ;
}
static int F_9 ( void )
{
int V_7 ;
unsigned char V_8 ;
V_7 = F_1 () ;
if ( V_7 != 0 )
return V_7 ;
F_2 ( 0xF6 , V_3 ) ;
V_8 = F_6 ( V_4 ) ;
if ( V_8 != 0 ) {
F_5 ( L_3 ,
V_9 ) ;
F_2 ( V_9 , V_4 ) ;
}
F_2 ( 0xF5 , V_3 ) ;
V_8 = F_6 ( V_4 ) ;
V_8 &= ~ 0x0C ;
F_2 ( V_8 , V_4 ) ;
F_8 () ;
return 0 ;
}
static void F_10 ( int V_9 )
{
F_11 ( & V_10 ) ;
if ( F_1 () < 0 ) {
F_12 ( & V_10 ) ;
return;
}
F_2 ( 0xF4 , V_3 ) ;
F_2 ( V_9 , V_4 ) ;
F_8 () ;
F_12 ( & V_10 ) ;
}
static int F_13 ( void )
{
F_10 ( V_9 ) ;
return 0 ;
}
static int F_14 ( void )
{
F_10 ( 0 ) ;
return 0 ;
}
static int F_15 ( int V_8 )
{
if ( V_8 < 1 || V_8 > 255 )
return - V_11 ;
V_9 = V_8 ;
return 0 ;
}
static T_1 F_16 ( struct V_12 * V_12 , const char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
if ( V_14 ) {
if ( ! V_16 ) {
T_3 V_17 ;
V_18 = 0 ;
for ( V_17 = 0 ; V_17 != V_14 ; V_17 ++ ) {
char V_1 ;
if ( F_17 ( V_1 , V_13 + V_17 ) )
return - V_19 ;
if ( V_1 == 'V' )
V_18 = 42 ;
}
}
F_13 () ;
}
return V_14 ;
}
static long F_18 ( struct V_12 * V_12 , unsigned int V_20 , unsigned long V_21 )
{
void T_2 * V_22 = ( void T_2 * ) V_21 ;
int T_2 * V_23 = V_22 ;
int V_24 ;
static const struct V_25 V_26 = {
. V_27 = V_28 |
V_29 |
V_30 ,
. V_31 = 1 ,
. V_32 = L_4 ,
} ;
switch ( V_20 ) {
case V_33 :
if ( F_19 ( V_22 , & V_26 , sizeof( V_26 ) ) )
return - V_19 ;
break;
case V_34 :
case V_35 :
return F_20 ( 0 , V_23 ) ;
case V_36 :
{
int V_27 , V_37 = - V_11 ;
if ( F_17 ( V_27 , V_23 ) )
return - V_19 ;
if ( V_27 & V_38 ) {
F_14 () ;
V_37 = 0 ;
}
if ( V_27 & V_39 ) {
F_13 () ;
V_37 = 0 ;
}
return V_37 ;
}
case V_40 :
F_13 () ;
break;
case V_41 :
if ( F_17 ( V_24 , V_23 ) )
return - V_19 ;
if ( F_15 ( V_24 ) )
return - V_11 ;
F_13 () ;
case V_42 :
return F_20 ( V_9 , V_23 ) ;
default:
return - V_43 ;
}
return 0 ;
}
static int F_21 ( struct V_44 * V_44 , struct V_12 * V_12 )
{
if ( F_22 ( 0 , & V_45 ) )
return - V_46 ;
F_13 () ;
return F_23 ( V_44 , V_12 ) ;
}
static int F_24 ( struct V_44 * V_44 , struct V_12 * V_12 )
{
if ( V_18 == 42 )
F_14 () ;
else {
F_25 ( L_5 ) ;
F_13 () ;
}
V_18 = 0 ;
F_26 ( 0 , & V_45 ) ;
return 0 ;
}
static int F_27 ( struct V_47 * V_48 , unsigned long V_49 ,
void * V_50 )
{
if ( V_49 == V_51 || V_49 == V_52 )
F_14 () ;
return V_53 ;
}
static int T_5 F_28 ( void )
{
int V_7 ;
F_5 ( L_6 ) ;
if ( F_15 ( V_9 ) ) {
F_15 ( V_54 ) ;
F_5 ( L_7 ,
V_54 ) ;
}
if ( ! F_29 ( V_5 , 1 , V_55 ) ) {
F_7 ( L_8 , V_5 ) ;
V_7 = - V_56 ;
goto V_57;
}
V_7 = F_9 () ;
if ( V_7 != 0 )
goto V_58;
V_7 = F_30 ( & V_59 ) ;
if ( V_7 != 0 ) {
F_7 ( L_9 , V_7 ) ;
goto V_58;
}
V_7 = F_31 ( & V_60 ) ;
if ( V_7 != 0 ) {
F_7 ( L_10 ,
V_61 , V_7 ) ;
goto V_62;
}
F_5 ( L_11 ,
V_9 , V_16 ) ;
V_57:
return V_7 ;
V_62:
F_32 ( & V_59 ) ;
V_58:
F_33 ( V_5 , 1 ) ;
goto V_57;
}
static void T_6 F_34 ( void )
{
F_35 ( & V_60 ) ;
F_32 ( & V_59 ) ;
F_33 ( V_5 , 1 ) ;
}
