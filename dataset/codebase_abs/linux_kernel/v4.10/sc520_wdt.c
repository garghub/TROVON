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
unsigned long V_9 ;
F_9 ( & V_4 , V_9 ) ;
F_10 ( V_5 ) ;
F_4 ( 0xAAAA , V_5 ) ;
F_4 ( 0x5555 , V_5 ) ;
F_4 ( 0x3333 , V_5 ) ;
F_4 ( 0xCCCC , V_5 ) ;
F_4 ( V_8 , V_5 ) ;
F_11 ( & V_4 , V_9 ) ;
}
static int F_12 ( void )
{
V_3 = V_2 + ( V_10 * V_11 ) ;
F_6 ( & V_6 , V_2 + V_7 ) ;
F_8 ( V_12 | V_13 | V_14 ) ;
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
V_3 = V_2 + ( V_10 * V_11 ) ;
return 0 ;
}
static int F_17 ( int V_15 )
{
if ( ( V_15 < 1 ) || ( V_15 > 3600 ) )
return - V_16 ;
V_10 = V_15 ;
return 0 ;
}
static T_1 F_18 ( struct V_17 * V_17 , const char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
if ( V_19 ) {
if ( ! V_21 ) {
T_3 V_22 ;
V_23 = 0 ;
for ( V_22 = 0 ; V_22 != V_19 ; V_22 ++ ) {
char V_24 ;
if ( F_19 ( V_24 , V_18 + V_22 ) )
return - V_25 ;
if ( V_24 == 'V' )
V_23 = 42 ;
}
}
F_16 () ;
}
return V_19 ;
}
static int F_20 ( struct V_26 * V_26 , struct V_17 * V_17 )
{
if ( F_21 ( 0 , & V_27 ) )
return - V_28 ;
if ( V_21 )
F_22 ( V_29 ) ;
F_12 () ;
return F_23 ( V_26 , V_17 ) ;
}
static int F_24 ( struct V_26 * V_26 , struct V_17 * V_17 )
{
if ( V_23 == 42 )
F_14 () ;
else {
F_25 ( L_4 ) ;
F_16 () ;
}
F_26 ( 0 , & V_27 ) ;
V_23 = 0 ;
return 0 ;
}
static long F_27 ( struct V_17 * V_17 , unsigned int V_30 , unsigned long V_31 )
{
void T_2 * V_32 = ( void T_2 * ) V_31 ;
int T_2 * V_33 = V_32 ;
static const struct V_34 V_35 = {
. V_36 = V_37 | V_38
| V_39 ,
. V_40 = 1 ,
. V_41 = L_5 ,
} ;
switch ( V_30 ) {
case V_42 :
return F_28 ( V_32 , & V_35 , sizeof( V_35 ) ) ? - V_25 : 0 ;
case V_43 :
case V_44 :
return F_29 ( 0 , V_33 ) ;
case V_45 :
{
int V_46 , V_47 = - V_16 ;
if ( F_19 ( V_46 , V_33 ) )
return - V_25 ;
if ( V_46 & V_48 ) {
F_14 () ;
V_47 = 0 ;
}
if ( V_46 & V_49 ) {
F_12 () ;
V_47 = 0 ;
}
return V_47 ;
}
case V_50 :
F_16 () ;
return 0 ;
case V_51 :
{
int V_52 ;
if ( F_19 ( V_52 , V_33 ) )
return - V_25 ;
if ( F_17 ( V_52 ) )
return - V_16 ;
F_16 () ;
}
case V_53 :
return F_29 ( V_10 , V_33 ) ;
default:
return - V_54 ;
}
}
static int F_30 ( struct V_55 * V_56 , unsigned long V_57 ,
void * V_58 )
{
if ( V_57 == V_59 || V_57 == V_60 )
F_14 () ;
return V_61 ;
}
static void T_5 F_31 ( void )
{
if ( ! V_21 )
F_14 () ;
F_32 ( & V_62 ) ;
F_33 ( & V_63 ) ;
F_34 ( V_5 ) ;
}
static int T_6 F_35 ( void )
{
int V_64 = - V_28 ;
if ( F_17 ( V_10 ) ) {
F_17 ( V_65 ) ;
F_13 ( L_6 ,
V_65 ) ;
}
V_5 = F_36 ( V_66 + V_67 , 2 ) ;
if ( ! V_5 ) {
F_37 ( L_7 ) ;
V_64 = - V_68 ;
goto V_69;
}
V_64 = F_38 ( & V_63 ) ;
if ( V_64 ) {
F_37 ( L_8 , V_64 ) ;
goto V_70;
}
V_64 = F_39 ( & V_62 ) ;
if ( V_64 ) {
F_37 ( L_9 ,
V_71 , V_64 ) ;
goto V_72;
}
F_13 ( L_10 ,
V_10 , V_21 ) ;
return 0 ;
V_72:
F_33 ( & V_63 ) ;
V_70:
F_34 ( V_5 ) ;
V_69:
return V_64 ;
}
