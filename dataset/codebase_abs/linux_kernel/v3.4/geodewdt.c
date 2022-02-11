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
F_12 ( L_1 ) ;
F_1 () ;
F_13 ( V_16 , & V_14 ) ;
}
F_14 ( V_13 , & V_14 ) ;
V_18 = 0 ;
return 0 ;
}
static T_1 F_15 ( struct V_12 * V_12 , const char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
if ( V_20 ) {
if ( ! V_22 ) {
T_3 V_23 ;
V_18 = 0 ;
for ( V_23 = 0 ; V_23 != V_20 ; V_23 ++ ) {
char V_24 ;
if ( F_16 ( V_24 , V_19 + V_23 ) )
return - V_25 ;
if ( V_24 == 'V' )
V_18 = 1 ;
}
}
F_1 () ;
}
return V_20 ;
}
static long F_17 ( struct V_12 * V_12 , unsigned int V_26 ,
unsigned long V_27 )
{
void T_2 * V_28 = ( void T_2 * ) V_27 ;
int T_2 * V_29 = V_28 ;
int V_30 ;
static const struct V_31 V_32 = {
. V_33 = V_34 | V_35
| V_36 ,
. V_37 = 1 ,
. V_38 = V_39 ,
} ;
switch ( V_26 ) {
case V_40 :
return F_18 ( V_28 , & V_32 ,
sizeof( V_32 ) ) ? - V_25 : 0 ;
break;
case V_41 :
case V_42 :
return F_19 ( 0 , V_29 ) ;
case V_43 :
{
int V_33 , V_44 = - V_7 ;
if ( F_16 ( V_33 , V_29 ) )
return - V_25 ;
if ( V_33 & V_45 ) {
F_3 () ;
V_44 = 0 ;
}
if ( V_33 & V_46 ) {
F_1 () ;
V_44 = 0 ;
}
return V_44 ;
}
case V_47 :
F_1 () ;
return 0 ;
case V_48 :
if ( F_16 ( V_30 , V_29 ) )
return - V_25 ;
if ( F_4 ( V_30 ) )
return - V_7 ;
case V_49 :
return F_19 ( V_10 , V_29 ) ;
default:
return - V_50 ;
}
return 0 ;
}
static int T_5 F_20 ( struct V_51 * V_52 )
{
int V_44 ;
V_1 = F_21 ( V_53 , V_54 ) ;
if ( ! V_1 ) {
F_22 ( L_2 ) ;
return - V_55 ;
}
F_2 ( V_1 , V_2 ,
V_56 | ( 3 << 8 ) ) ;
F_23 ( V_1 , V_57 , V_58 , 1 ) ;
F_2 ( V_1 , V_8 ,
V_10 * V_9 ) ;
V_44 = F_24 ( & V_59 ) ;
return V_44 ;
}
static int T_6 F_25 ( struct V_51 * V_52 )
{
F_26 ( & V_59 ) ;
return 0 ;
}
static void F_27 ( struct V_51 * V_52 )
{
F_3 () ;
}
static int T_7 F_28 ( void )
{
int V_44 ;
V_44 = F_29 ( & V_60 ) ;
if ( V_44 )
return V_44 ;
V_61 = F_30 ( V_62 ,
- 1 , NULL , 0 ) ;
if ( F_31 ( V_61 ) ) {
V_44 = F_32 ( V_61 ) ;
goto V_63;
}
return 0 ;
V_63:
F_33 ( & V_60 ) ;
return V_44 ;
}
static void T_8 F_34 ( void )
{
F_35 ( V_61 ) ;
F_33 ( & V_60 ) ;
}
