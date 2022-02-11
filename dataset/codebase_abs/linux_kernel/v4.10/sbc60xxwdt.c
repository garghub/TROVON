static void F_1 ( unsigned long V_1 )
{
if ( F_2 ( V_2 , V_3 ) ) {
F_3 ( V_4 ) ;
F_4 ( & V_5 , V_2 + V_6 ) ;
} else
F_5 ( L_1 ) ;
}
static void F_6 ( void )
{
V_3 = V_2 + ( V_7 * V_8 ) ;
F_4 ( & V_5 , V_2 + V_6 ) ;
F_7 ( L_2 ) ;
}
static void F_8 ( void )
{
F_9 ( & V_5 ) ;
F_3 ( V_9 ) ;
F_7 ( L_3 ) ;
}
static void F_10 ( void )
{
V_3 = V_2 + ( V_7 * V_8 ) ;
}
static T_1 F_11 ( struct V_10 * V_10 , const char T_2 * V_11 ,
T_3 V_12 , T_4 * V_13 )
{
if ( V_12 ) {
if ( ! V_14 ) {
T_3 V_15 ;
V_16 = 0 ;
for ( V_15 = 0 ; V_15 != V_12 ; V_15 ++ ) {
char V_17 ;
if ( F_12 ( V_17 , V_11 + V_15 ) )
return - V_18 ;
if ( V_17 == 'V' )
V_16 = 42 ;
}
}
F_10 () ;
}
return V_12 ;
}
static int F_13 ( struct V_19 * V_19 , struct V_10 * V_10 )
{
if ( F_14 ( 0 , & V_20 ) )
return - V_21 ;
if ( V_14 )
F_15 ( V_22 ) ;
F_6 () ;
return F_16 ( V_19 , V_10 ) ;
}
static int F_17 ( struct V_19 * V_19 , struct V_10 * V_10 )
{
if ( V_16 == 42 )
F_8 () ;
else {
F_9 ( & V_5 ) ;
F_18 ( L_4 ) ;
}
F_19 ( 0 , & V_20 ) ;
V_16 = 0 ;
return 0 ;
}
static long F_20 ( struct V_10 * V_10 , unsigned int V_23 , unsigned long V_24 )
{
void T_2 * V_25 = ( void T_2 * ) V_24 ;
int T_2 * V_26 = V_25 ;
static const struct V_27 V_28 = {
. V_29 = V_30 | V_31 |
V_32 ,
. V_33 = 1 ,
. V_34 = L_5 ,
} ;
switch ( V_23 ) {
case V_35 :
return F_21 ( V_25 , & V_28 , sizeof( V_28 ) ) ? - V_18 : 0 ;
case V_36 :
case V_37 :
return F_22 ( 0 , V_26 ) ;
case V_38 :
{
int V_39 , V_40 = - V_41 ;
if ( F_12 ( V_39 , V_26 ) )
return - V_18 ;
if ( V_39 & V_42 ) {
F_8 () ;
V_40 = 0 ;
}
if ( V_39 & V_43 ) {
F_6 () ;
V_40 = 0 ;
}
return V_40 ;
}
case V_44 :
F_10 () ;
return 0 ;
case V_45 :
{
int V_46 ;
if ( F_12 ( V_46 , V_26 ) )
return - V_18 ;
if ( V_46 < 1 || V_46 > 3600 )
return - V_41 ;
V_7 = V_46 ;
F_10 () ;
}
case V_47 :
return F_22 ( V_7 , V_26 ) ;
default:
return - V_48 ;
}
}
static int F_23 ( struct V_49 * V_50 , unsigned long V_51 ,
void * V_52 )
{
if ( V_51 == V_53 || V_51 == V_54 )
F_8 () ;
return V_55 ;
}
static void T_5 F_24 ( void )
{
F_8 () ;
F_25 ( & V_56 ) ;
F_26 ( & V_57 ) ;
if ( ( V_9 != 0x45 ) && ( V_9 != V_4 ) )
F_27 ( V_9 , 1 ) ;
F_27 ( V_4 , 1 ) ;
}
static int T_6 F_28 ( void )
{
int V_58 = - V_21 ;
if ( V_7 < 1 || V_7 > 3600 ) {
V_7 = V_59 ;
F_7 ( L_6 ,
V_7 ) ;
}
if ( ! F_29 ( V_4 , 1 , L_7 ) ) {
F_30 ( L_8 , V_4 ) ;
V_58 = - V_60 ;
goto V_61;
}
if ( V_9 != 0x45 && V_9 != V_4 ) {
if ( ! F_29 ( V_9 , 1 , L_7 ) ) {
F_30 ( L_8 , V_9 ) ;
V_58 = - V_60 ;
goto V_62;
}
}
V_58 = F_31 ( & V_57 ) ;
if ( V_58 ) {
F_30 ( L_9 , V_58 ) ;
goto V_63;
}
V_58 = F_32 ( & V_56 ) ;
if ( V_58 ) {
F_30 ( L_10 ,
V_56 . V_64 , V_58 ) ;
goto V_65;
}
F_7 ( L_11 ,
V_7 , V_14 ) ;
return 0 ;
V_65:
F_26 ( & V_57 ) ;
V_63:
if ( V_9 != 0x45 && V_9 != V_4 )
F_27 ( V_9 , 1 ) ;
V_62:
F_27 ( V_4 , 1 ) ;
V_61:
return V_58 ;
}
