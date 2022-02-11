static void F_1 ( void )
{
F_2 ( V_1 , V_2 , 0 ) ;
F_2 ( V_1 , V_3 , 0 ) ;
F_2 ( V_1 , V_2 , V_4 ) ;
}
static void F_3 ( void )
{
F_2 ( V_1 , V_2 , 0 ) ;
F_2 ( V_1 , V_3 , 0 ) ;
}
static int F_4 ( int V_5 )
{
if ( V_5 < 1 || V_5 > V_6 )
return - V_7 ;
F_2 ( V_1 , V_2 , 0 ) ;
F_2 ( V_1 , V_8 , V_5 * V_9 ) ;
F_2 ( V_1 , V_3 , 0 ) ;
F_2 ( V_1 , V_2 , V_4 ) ;
V_10 = V_5 ;
return 0 ;
}
static int F_5 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
if ( F_6 ( V_13 , & V_14 ) )
return - V_15 ;
if ( ! F_7 ( V_16 , & V_14 ) )
F_8 ( V_17 ) ;
F_1 () ;
return F_9 ( V_11 , V_12 ) ;
}
static int F_10 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
if ( V_18 ) {
F_3 () ;
F_11 ( V_17 ) ;
} else {
F_12 ( V_19 L_1 ) ;
F_1 () ;
F_13 ( V_16 , & V_14 ) ;
}
F_14 ( V_13 , & V_14 ) ;
V_18 = 0 ;
return 0 ;
}
static T_1 F_15 ( struct V_12 * V_12 , const char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
if ( V_21 ) {
if ( ! V_23 ) {
T_3 V_24 ;
V_18 = 0 ;
for ( V_24 = 0 ; V_24 != V_21 ; V_24 ++ ) {
char V_25 ;
if ( F_16 ( V_25 , V_20 + V_24 ) )
return - V_26 ;
if ( V_25 == 'V' )
V_18 = 1 ;
}
}
F_1 () ;
}
return V_21 ;
}
static long F_17 ( struct V_12 * V_12 , unsigned int V_27 ,
unsigned long V_28 )
{
void T_2 * V_29 = ( void T_2 * ) V_28 ;
int T_2 * V_30 = V_29 ;
int V_31 ;
static const struct V_32 V_33 = {
. V_34 = V_35 | V_36
| V_37 ,
. V_38 = 1 ,
. V_39 = V_40 ,
} ;
switch ( V_27 ) {
case V_41 :
return F_18 ( V_29 , & V_33 ,
sizeof( V_33 ) ) ? - V_26 : 0 ;
break;
case V_42 :
case V_43 :
return F_19 ( 0 , V_30 ) ;
case V_44 :
{
int V_34 , V_45 = - V_7 ;
if ( F_16 ( V_34 , V_30 ) )
return - V_26 ;
if ( V_34 & V_46 ) {
F_3 () ;
V_45 = 0 ;
}
if ( V_34 & V_47 ) {
F_1 () ;
V_45 = 0 ;
}
return V_45 ;
}
case V_48 :
F_1 () ;
return 0 ;
case V_49 :
if ( F_16 ( V_31 , V_30 ) )
return - V_26 ;
if ( F_4 ( V_31 ) )
return - V_7 ;
case V_50 :
return F_19 ( V_10 , V_30 ) ;
default:
return - V_51 ;
}
return 0 ;
}
static int T_5 F_20 ( struct V_52 * V_53 )
{
int V_45 ;
V_1 = F_21 ( V_54 , V_55 ) ;
if ( ! V_1 ) {
F_12 ( V_56 L_2 ) ;
return - V_57 ;
}
F_2 ( V_1 , V_2 ,
V_58 | ( 3 << 8 ) ) ;
F_22 ( V_1 , V_59 , V_60 , 1 ) ;
F_2 ( V_1 , V_8 ,
V_10 * V_9 ) ;
V_45 = F_23 ( & V_61 ) ;
return V_45 ;
}
static int T_6 F_24 ( struct V_52 * V_53 )
{
F_25 ( & V_61 ) ;
return 0 ;
}
static void F_26 ( struct V_52 * V_53 )
{
F_3 () ;
}
static int T_7 F_27 ( void )
{
int V_45 ;
V_45 = F_28 ( & V_62 ) ;
if ( V_45 )
return V_45 ;
V_63 = F_29 ( V_64 ,
- 1 , NULL , 0 ) ;
if ( F_30 ( V_63 ) ) {
V_45 = F_31 ( V_63 ) ;
goto V_65;
}
return 0 ;
V_65:
F_32 ( & V_62 ) ;
return V_45 ;
}
static void T_8 F_33 ( void )
{
F_34 ( V_63 ) ;
F_32 ( & V_62 ) ;
}
