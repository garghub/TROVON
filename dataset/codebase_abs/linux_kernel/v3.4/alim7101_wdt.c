static void F_1 ( unsigned long V_1 )
{
char V_2 ;
if ( F_2 ( V_3 , V_4 ) ) {
F_3 ( V_5 , 0x92 , & V_2 ) ;
F_4 ( V_5 ,
V_6 , ( V_2 & ~ V_7 ) ) ;
F_4 ( V_5 ,
V_6 , ( V_2 | V_7 ) ) ;
if ( V_8 ) {
F_3 ( V_5 ,
V_9 , & V_2 ) ;
F_4 ( V_5 ,
V_9 , V_2 | 0x20 ) ;
F_4 ( V_5 ,
V_9 , V_2 & ~ 0x20 ) ;
}
} else {
F_5 ( L_1 ) ;
}
F_6 ( & V_10 , V_3 + V_11 ) ;
}
static void F_7 ( int V_12 )
{
char V_2 ;
F_3 ( V_5 , V_6 , & V_2 ) ;
if ( V_12 == V_13 ) {
F_4 ( V_5 ,
V_6 , ( V_2 | V_7 ) ) ;
if ( V_8 ) {
F_3 ( V_5 ,
V_9 , & V_2 ) ;
F_4 ( V_5 ,
V_9 , V_2 & ~ 0x20 ) ;
}
} else {
F_4 ( V_5 ,
V_6 , ( V_2 & ~ V_7 ) ) ;
if ( V_8 ) {
F_3 ( V_5 ,
V_9 , & V_2 ) ;
F_4 ( V_5 ,
V_9 , V_2 | 0x20 ) ;
}
}
}
static void F_8 ( void )
{
V_4 = V_3 + ( V_14 * V_15 ) ;
F_7 ( V_13 ) ;
F_6 ( & V_10 , V_3 + V_11 ) ;
F_9 ( L_2 ) ;
}
static void F_10 ( void )
{
F_11 ( & V_10 ) ;
F_7 ( V_16 ) ;
F_9 ( L_3 ) ;
}
static void F_12 ( void )
{
V_4 = V_3 + ( V_14 * V_15 ) ;
}
static T_1 F_13 ( struct V_17 * V_17 , const char T_2 * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
if ( V_19 ) {
if ( ! V_21 ) {
T_3 V_22 ;
V_23 = 0 ;
for ( V_22 = 0 ; V_22 != V_19 ; V_22 ++ ) {
char V_24 ;
if ( F_14 ( V_24 , V_18 + V_22 ) )
return - V_25 ;
if ( V_24 == 'V' )
V_23 = 42 ;
}
}
F_12 () ;
}
return V_19 ;
}
static int F_15 ( struct V_26 * V_26 , struct V_17 * V_17 )
{
if ( F_16 ( 0 , & V_27 ) )
return - V_28 ;
F_8 () ;
return F_17 ( V_26 , V_17 ) ;
}
static int F_18 ( struct V_26 * V_26 , struct V_17 * V_17 )
{
if ( V_23 == 42 )
F_10 () ;
else {
F_19 ( L_4 ) ;
}
F_20 ( 0 , & V_27 ) ;
V_23 = 0 ;
return 0 ;
}
static long F_21 ( struct V_17 * V_17 , unsigned int V_29 , unsigned long V_30 )
{
void T_2 * V_31 = ( void T_2 * ) V_30 ;
int T_2 * V_32 = V_31 ;
static const struct V_33 V_34 = {
. V_35 = V_36 | V_37
| V_38 ,
. V_39 = 1 ,
. V_40 = L_5 ,
} ;
switch ( V_29 ) {
case V_41 :
return F_22 ( V_31 , & V_34 , sizeof( V_34 ) ) ? - V_25 : 0 ;
case V_42 :
case V_43 :
return F_23 ( 0 , V_32 ) ;
case V_44 :
{
int V_45 , V_46 = - V_47 ;
if ( F_14 ( V_45 , V_32 ) )
return - V_25 ;
if ( V_45 & V_48 ) {
F_10 () ;
V_46 = 0 ;
}
if ( V_45 & V_49 ) {
F_8 () ;
V_46 = 0 ;
}
return V_46 ;
}
case V_50 :
F_12 () ;
return 0 ;
case V_51 :
{
int V_52 ;
if ( F_14 ( V_52 , V_32 ) )
return - V_25 ;
if ( V_52 < 1 || V_52 > 3600 )
return - V_47 ;
V_14 = V_52 ;
F_12 () ;
}
case V_53 :
return F_23 ( V_14 , V_32 ) ;
default:
return - V_54 ;
}
}
static int F_24 ( struct V_55 * V_56 ,
unsigned long V_57 , void * V_58 )
{
if ( V_57 == V_59 || V_57 == V_60 )
F_10 () ;
if ( V_57 == V_61 ) {
F_7 ( V_13 ) ;
F_9 ( L_6 ) ;
}
return V_62 ;
}
static void T_5 F_25 ( void )
{
F_10 () ;
F_26 ( & V_63 ) ;
F_27 ( & V_64 ) ;
F_28 ( V_5 ) ;
}
static int T_6 F_29 ( void )
{
int V_65 = - V_28 ;
struct V_66 * V_67 ;
char V_2 ;
F_9 ( L_7 ) ;
V_5 = F_30 ( V_68 , V_69 ,
NULL ) ;
if ( ! V_5 ) {
F_9 ( L_8 ) ;
return - V_28 ;
}
F_4 ( V_5 , V_6 , 0x02 ) ;
V_67 = F_30 ( V_68 , V_70 ,
NULL ) ;
if ( ! V_67 ) {
F_9 ( L_9 ) ;
goto V_71;
}
F_3 ( V_67 , 0x5e , & V_2 ) ;
F_28 ( V_67 ) ;
if ( ( V_2 & 0x1e ) == 0x00 ) {
if ( ! V_8 ) {
F_9 ( L_10 ) ;
goto V_71;
}
V_21 = 1 ;
} else if ( ( V_2 & 0x1e ) != 0x12 && ( V_2 & 0x1e ) != 0x00 ) {
F_9 ( L_11 ) ;
goto V_71;
}
if ( V_14 < 1 || V_14 > 3600 ) {
V_14 = V_72 ;
F_9 ( L_12 ,
V_14 ) ;
}
V_65 = F_31 ( & V_64 ) ;
if ( V_65 ) {
F_32 ( L_13 , V_65 ) ;
goto V_71;
}
V_65 = F_33 ( & V_63 ) ;
if ( V_65 ) {
F_32 ( L_14 ,
V_63 . V_73 , V_65 ) ;
goto V_74;
}
if ( V_21 )
F_34 ( V_75 ) ;
F_9 ( L_15 ,
V_14 , V_21 ) ;
return 0 ;
V_74:
F_27 ( & V_64 ) ;
V_71:
F_28 ( V_5 ) ;
return V_65 ;
}
