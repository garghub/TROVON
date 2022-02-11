static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 | V_3 , & V_4 -> V_5 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_6 * V_7 , & V_4 -> V_8 ) ;
F_3 ( V_9 , & V_4 -> V_10 ) ;
F_3 ( 0 , & V_4 -> V_11 ) ;
F_3 ( V_12 | V_13 | V_14 ,
& V_4 -> V_15 ) ;
F_3 ( V_2 | V_3 , & V_4 -> V_5 ) ;
F_4 ( & V_1 ) ;
}
static void F_6 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_16 , & V_4 -> V_5 ) ;
F_3 ( F_7 ( & V_4 -> V_15 ) & ~ V_12 ,
& V_4 -> V_15 ) ;
F_4 ( & V_1 ) ;
}
static int F_8 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
if ( F_9 ( 0 , & V_19 ) )
return - V_20 ;
if ( F_7 ( & V_4 -> V_15 ) & V_12 ) {
F_10 ( 0 , & V_19 ) ;
return - V_20 ;
}
if ( V_21 )
F_11 ( V_22 ) ;
F_5 () ;
return F_12 ( V_17 , V_18 ) ;
}
static int F_13 ( struct V_17 * V_17 , struct V_18 * V_18 )
{
if ( V_23 )
F_6 () ;
else {
F_14 ( V_24 L_1
L_2 ) ;
F_1 () ;
}
F_10 ( 0 , & V_19 ) ;
V_23 = 0 ;
return 0 ;
}
static T_1 F_15 ( struct V_18 * V_18 , const char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
if ( V_26 ) {
if ( ! V_21 ) {
T_3 V_28 ;
V_23 = 0 ;
for ( V_28 = 0 ; V_28 != V_26 ; V_28 ++ ) {
char V_29 ;
if ( F_16 ( V_29 , V_25 + V_28 ) )
return - V_30 ;
if ( V_29 == 'V' )
V_23 = 1 ;
}
}
F_1 () ;
}
return V_26 ;
}
static long F_17 ( struct V_18 * V_18 , unsigned int V_31 ,
unsigned long V_32 )
{
void T_2 * V_33 = ( void T_2 * ) V_32 ;
int T_2 * V_34 = V_33 ;
int V_35 ;
static const struct V_36 V_37 = {
. V_38 = V_39 |
V_40 |
V_41 ,
. V_42 = 0 ,
. V_43 = L_3 ,
} ;
switch ( V_31 ) {
case V_44 :
return F_18 ( V_33 , & V_37 , sizeof( V_37 ) ) ? - V_30 : 0 ;
case V_45 :
case V_46 :
return F_19 ( 0 , V_34 ) ;
case V_47 :
F_1 () ;
return 0 ;
case V_48 :
if ( F_16 ( V_35 , V_34 ) )
return - V_30 ;
if ( V_35 < 1 || V_35 > V_49 )
return - V_50 ;
V_7 = V_35 ;
F_6 () ;
F_5 () ;
case V_51 :
return F_19 ( V_7 , V_34 ) ;
default:
return - V_52 ;
}
}
static int T_5 F_20 ( struct V_53 * V_54 )
{
struct V_55 * V_56 ;
int V_57 ;
V_58 = F_21 ( NULL , L_4 ) ;
if ( F_22 ( V_58 ) ) {
V_57 = F_23 ( V_58 ) ;
V_58 = NULL ;
goto exit;
}
V_57 = F_24 ( V_58 ) ;
if ( V_57 ) {
F_25 ( V_58 ) ;
V_58 = NULL ;
goto exit;
}
V_56 = F_26 ( V_54 , V_59 , 0 ) ;
if ( ! V_56 )
goto V_60;
if ( ! F_27 ( & V_54 -> V_54 , V_56 -> V_61 , F_28 ( V_56 ) ,
L_5 ) )
goto V_60;
V_4 = F_29 ( & V_54 -> V_54 , V_56 -> V_61 , F_28 ( V_56 ) ) ;
if ( ! V_4 )
goto V_60;
V_57 = F_30 ( & V_62 ) ;
if ( V_57 ) {
goto exit;
}
F_14 ( V_63 L_6
L_7 ,
V_7 , V_49 , V_21 ) ;
return 0 ;
V_60:
V_57 = - V_20 ;
exit:
if ( V_58 ) {
F_31 ( V_58 ) ;
F_25 ( V_58 ) ;
}
return V_57 ;
}
static int T_6 F_32 ( struct V_53 * V_54 )
{
F_33 ( & V_62 ) ;
F_31 ( V_58 ) ;
F_25 ( V_58 ) ;
return 0 ;
}
static void F_34 ( struct V_53 * V_54 )
{
F_6 () ;
}
static int T_5 F_35 ( void )
{
return F_36 ( & V_64 , F_20 ) ;
}
static void T_6 F_37 ( void )
{
F_38 ( & V_64 ) ;
}
