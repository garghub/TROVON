static void F_1 ( unsigned long V_1 )
{
if ( F_2 ( V_2 , V_3 ) ) {
F_3 ( & V_4 ) ;
F_4 ( 0xAAAA , V_5 ) ;
F_4 ( 0x5555 , V_5 ) ;
F_5 ( & V_4 ) ;
F_6 ( & V_6 , V_2 + V_7 ) ;
} else
F_7 ( L_1 ) ;
}
static void F_8 ( int V_8 )
{
T_1 V_9 ;
unsigned long V_10 ;
F_9 ( & V_4 , V_10 ) ;
V_9 = F_10 ( V_5 ) ;
F_4 ( 0xAAAA , V_5 ) ;
F_4 ( 0x5555 , V_5 ) ;
F_4 ( 0x3333 , V_5 ) ;
F_4 ( 0xCCCC , V_5 ) ;
F_4 ( V_8 , V_5 ) ;
F_11 ( & V_4 , V_10 ) ;
}
static int F_12 ( void )
{
V_3 = V_2 + ( V_11 * V_12 ) ;
F_6 ( & V_6 , V_2 + V_7 ) ;
F_8 ( V_13 | V_14 | V_15 ) ;
F_13 ( L_2 ) ;
return 0 ;
}
static int F_14 ( void )
{
F_15 ( & V_6 ) ;
F_8 ( 0 ) ;
F_13 ( L_3 ) ;
return 0 ;
}
static int F_16 ( void )
{
V_3 = V_2 + ( V_11 * V_12 ) ;
return 0 ;
}
static int F_17 ( int V_16 )
{
if ( ( V_16 < 1 ) || ( V_16 > 3600 ) )
return - V_17 ;
V_11 = V_16 ;
return 0 ;
}
static T_2 F_18 ( struct V_18 * V_18 , const char T_3 * V_19 ,
T_4 V_20 , T_5 * V_21 )
{
if ( V_20 ) {
if ( ! V_22 ) {
T_4 V_23 ;
V_24 = 0 ;
for ( V_23 = 0 ; V_23 != V_20 ; V_23 ++ ) {
char V_25 ;
if ( F_19 ( V_25 , V_19 + V_23 ) )
return - V_26 ;
if ( V_25 == 'V' )
V_24 = 42 ;
}
}
F_16 () ;
}
return V_20 ;
}
static int F_20 ( struct V_27 * V_27 , struct V_18 * V_18 )
{
if ( F_21 ( 0 , & V_28 ) )
return - V_29 ;
if ( V_22 )
F_22 ( V_30 ) ;
F_12 () ;
return F_23 ( V_27 , V_18 ) ;
}
static int F_24 ( struct V_27 * V_27 , struct V_18 * V_18 )
{
if ( V_24 == 42 )
F_14 () ;
else {
F_25 ( L_4 ) ;
F_16 () ;
}
F_26 ( 0 , & V_28 ) ;
V_24 = 0 ;
return 0 ;
}
static long F_27 ( struct V_18 * V_18 , unsigned int V_31 , unsigned long V_32 )
{
void T_3 * V_33 = ( void T_3 * ) V_32 ;
int T_3 * V_34 = V_33 ;
static const struct V_35 V_36 = {
. V_37 = V_38 | V_39
| V_40 ,
. V_41 = 1 ,
. V_42 = L_5 ,
} ;
switch ( V_31 ) {
case V_43 :
return F_28 ( V_33 , & V_36 , sizeof( V_36 ) ) ? - V_26 : 0 ;
case V_44 :
case V_45 :
return F_29 ( 0 , V_34 ) ;
case V_46 :
{
int V_47 , V_48 = - V_17 ;
if ( F_19 ( V_47 , V_34 ) )
return - V_26 ;
if ( V_47 & V_49 ) {
F_14 () ;
V_48 = 0 ;
}
if ( V_47 & V_50 ) {
F_12 () ;
V_48 = 0 ;
}
return V_48 ;
}
case V_51 :
F_16 () ;
return 0 ;
case V_52 :
{
int V_53 ;
if ( F_19 ( V_53 , V_34 ) )
return - V_26 ;
if ( F_17 ( V_53 ) )
return - V_17 ;
F_16 () ;
}
case V_54 :
return F_29 ( V_11 , V_34 ) ;
default:
return - V_55 ;
}
}
static int F_30 ( struct V_56 * V_57 , unsigned long V_58 ,
void * V_59 )
{
if ( V_58 == V_60 || V_58 == V_61 )
F_14 () ;
return V_62 ;
}
static void T_6 F_31 ( void )
{
if ( ! V_22 )
F_14 () ;
F_32 ( & V_63 ) ;
F_33 ( & V_64 ) ;
F_34 ( V_5 ) ;
}
static int T_7 F_35 ( void )
{
int V_65 = - V_29 ;
if ( F_17 ( V_11 ) ) {
F_17 ( V_66 ) ;
F_13 ( L_6 ,
V_66 ) ;
}
V_5 = F_36 ( V_67 + V_68 , 2 ) ;
if ( ! V_5 ) {
F_37 ( L_7 ) ;
V_65 = - V_69 ;
goto V_70;
}
V_65 = F_38 ( & V_64 ) ;
if ( V_65 ) {
F_37 ( L_8 , V_65 ) ;
goto V_71;
}
V_65 = F_39 ( & V_63 ) ;
if ( V_65 ) {
F_37 ( L_9 ,
V_72 , V_65 ) ;
goto V_73;
}
F_13 ( L_10 ,
V_11 , V_22 ) ;
return 0 ;
V_73:
F_33 ( & V_64 ) ;
V_71:
F_34 ( V_5 ) ;
V_70:
return V_65 ;
}
