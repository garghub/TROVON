static void F_1 ( void )
{
int V_1 = 15 - ( ( V_2 + 1 ) / 2 ) ;
F_2 ( & V_3 ) ;
F_3 ( V_1 , V_4 ) ;
F_4 ( & V_3 ) ;
}
static void F_5 ( void )
{
F_2 ( & V_3 ) ;
F_3 ( 0 , V_5 ) ;
F_4 ( & V_3 ) ;
}
static int F_6 ( int V_6 )
{
if ( V_6 < 0 || V_6 > 30 )
return - V_7 ;
V_2 = V_6 ;
return 0 ;
}
static T_1 F_7 ( struct V_8 * V_8 , const char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
if ( V_10 ) {
if ( ! V_12 ) {
T_3 V_13 ;
V_14 = 0 ;
for ( V_13 = 0 ; V_13 != V_10 ; V_13 ++ ) {
char V_15 ;
if ( F_8 ( V_15 , V_9 + V_13 ) )
return - V_16 ;
if ( V_15 == 'V' )
V_14 = 42 ;
}
}
F_1 () ;
}
return V_10 ;
}
static long F_9 ( struct V_8 * V_8 , unsigned int V_17 , unsigned long V_18 )
{
int V_19 ;
void T_2 * V_20 = ( void T_2 * ) V_18 ;
int T_2 * V_21 = V_20 ;
static const struct V_22 V_23 = {
. V_24 = V_25 | V_26
| V_27 ,
. V_28 = 1 ,
. V_29 = L_1 ,
} ;
switch ( V_17 ) {
case V_30 :
if ( F_10 ( V_20 , & V_23 , sizeof( V_23 ) ) )
return - V_16 ;
break;
case V_31 :
case V_32 :
return F_11 ( 0 , V_21 ) ;
case V_33 :
{
int V_24 , V_34 = - V_7 ;
if ( F_8 ( V_24 , V_21 ) )
return - V_16 ;
if ( V_24 & V_35 ) {
F_5 () ;
V_34 = 0 ;
}
if ( V_24 & V_36 ) {
F_1 () ;
V_34 = 0 ;
}
return V_34 ;
}
case V_37 :
F_1 () ;
break;
case V_38 :
if ( F_8 ( V_19 , V_21 ) )
return - V_16 ;
if ( F_6 ( V_19 ) )
return - V_7 ;
F_1 () ;
case V_39 :
return F_11 ( V_2 , V_21 ) ;
default:
return - V_40 ;
}
return 0 ;
}
static int F_12 ( struct V_41 * V_41 , struct V_8 * V_8 )
{
if ( F_13 ( 0 , & V_42 ) )
return - V_43 ;
if ( V_12 )
F_14 ( V_44 ) ;
F_1 () ;
return F_15 ( V_41 , V_8 ) ;
}
static int F_16 ( struct V_41 * V_41 , struct V_8 * V_8 )
{
if ( V_14 == 42 ) {
F_5 () ;
} else {
F_17 ( L_2 ) ;
F_1 () ;
}
F_18 ( 0 , & V_42 ) ;
V_14 = 0 ;
return 0 ;
}
static int T_5 F_19 ( struct V_45 * V_46 )
{
int V_47 ;
#if V_4 != V_5
if ( ! F_20 ( V_5 , 1 , L_1 ) ) {
F_21 ( L_3 , V_5 ) ;
V_47 = - V_48 ;
goto V_49;
}
#endif
if ( ! F_20 ( V_4 , 1 , L_1 ) ) {
F_21 ( L_4 , V_4 ) ;
V_47 = - V_48 ;
goto V_50;
}
if ( F_6 ( V_2 ) ) {
F_6 ( V_51 ) ;
F_22 ( L_5 , V_2 ) ;
}
V_47 = F_23 ( & V_52 ) ;
if ( V_47 ) {
F_21 ( L_6 ) ;
goto V_53;
}
return 0 ;
V_53:
F_24 ( V_4 , 1 ) ;
V_50:
#if V_4 != V_5
F_24 ( V_5 , 1 ) ;
#endif
V_49:
return V_47 ;
}
static int T_6 F_25 ( struct V_45 * V_46 )
{
F_26 ( & V_52 ) ;
F_24 ( V_4 , 1 ) ;
#if V_4 != V_5
F_24 ( V_5 , 1 ) ;
#endif
return 0 ;
}
static void F_27 ( struct V_45 * V_46 )
{
F_5 () ;
}
static int T_7 F_28 ( void )
{
int V_54 ;
F_22 ( L_7 ) ;
V_54 = F_29 ( & V_55 ) ;
if ( V_54 )
return V_54 ;
V_56 = F_30 ( V_57 ,
- 1 , NULL , 0 ) ;
if ( F_31 ( V_56 ) ) {
V_54 = F_32 ( V_56 ) ;
goto V_58;
}
return 0 ;
V_58:
F_33 ( & V_55 ) ;
return V_54 ;
}
static void T_8 F_34 ( void )
{
F_35 ( V_56 ) ;
F_33 ( & V_55 ) ;
F_22 ( L_8 ) ;
}
