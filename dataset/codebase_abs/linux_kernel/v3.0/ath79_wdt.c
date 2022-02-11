static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 * V_3 ) ;
}
static inline void F_3 ( void )
{
F_1 () ;
F_2 ( V_4 , V_5 ) ;
}
static inline void F_4 ( void )
{
F_2 ( V_4 , V_6 ) ;
}
static int F_5 ( int V_7 )
{
if ( V_7 < 1 || V_7 > V_8 )
return - V_9 ;
V_3 = V_7 ;
F_1 () ;
return 0 ;
}
static int F_6 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_7 ( V_12 , & V_13 ) )
return - V_14 ;
F_8 ( V_15 , & V_13 ) ;
F_3 () ;
return F_9 ( V_10 , V_11 ) ;
}
static int F_10 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_11 ( V_15 , & V_13 ) )
F_4 () ;
else {
F_12 ( V_16 L_1
L_2 ) ;
F_1 () ;
}
F_8 ( V_12 , & V_13 ) ;
F_8 ( V_15 , & V_13 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_11 * V_11 , const char * V_17 ,
T_2 V_18 , T_3 * V_19 )
{
if ( V_18 ) {
if ( ! V_20 ) {
T_2 V_21 ;
F_8 ( V_15 , & V_13 ) ;
for ( V_21 = 0 ; V_21 != V_18 ; V_21 ++ ) {
char V_22 ;
if ( F_14 ( V_22 , V_17 + V_21 ) )
return - V_23 ;
if ( V_22 == 'V' )
F_15 ( V_15 ,
& V_13 ) ;
}
}
F_1 () ;
}
return V_18 ;
}
static long F_16 ( struct V_11 * V_11 , unsigned int V_24 ,
unsigned long V_25 )
{
void T_4 * V_26 = ( void T_4 * ) V_25 ;
int T_4 * V_27 = V_26 ;
int V_28 ;
int V_29 ;
switch ( V_24 ) {
case V_30 :
V_28 = F_17 ( V_26 , & V_31 ,
sizeof( V_31 ) ) ? - V_23 : 0 ;
break;
case V_32 :
V_28 = F_18 ( 0 , V_27 ) ;
break;
case V_33 :
V_28 = F_18 ( V_34 , V_27 ) ;
break;
case V_35 :
F_1 () ;
V_28 = 0 ;
break;
case V_36 :
V_28 = F_14 ( V_29 , V_27 ) ;
if ( V_28 )
break;
V_28 = F_5 ( V_29 ) ;
if ( V_28 )
break;
case V_37 :
V_28 = F_18 ( V_3 , V_27 ) ;
break;
default:
V_28 = - V_38 ;
break;
}
return V_28 ;
}
static int T_5 F_19 ( struct V_39 * V_40 )
{
T_6 V_41 ;
int V_28 ;
V_42 = F_20 ( & V_40 -> V_43 , L_3 ) ;
if ( F_21 ( V_42 ) )
return F_22 ( V_42 ) ;
V_28 = F_23 ( V_42 ) ;
if ( V_28 )
goto V_44;
V_2 = F_24 ( V_42 ) ;
if ( ! V_2 ) {
V_28 = - V_9 ;
goto V_45;
}
V_8 = ( 0xfffffffful / V_2 ) ;
if ( V_3 < 1 || V_3 > V_8 ) {
V_3 = V_8 ;
F_25 ( & V_40 -> V_43 ,
L_4 ,
V_8 , V_3 ) ;
}
V_41 = F_26 ( V_4 ) ;
V_34 = ( V_41 & V_46 ) ? V_47 : 0 ;
V_28 = F_27 ( & V_48 ) ;
if ( V_28 ) {
F_28 ( & V_40 -> V_43 ,
L_5 , V_28 ) ;
goto V_45;
}
return 0 ;
V_45:
F_29 ( V_42 ) ;
V_44:
F_30 ( V_42 ) ;
return V_28 ;
}
static int T_7 F_31 ( struct V_39 * V_40 )
{
F_32 ( & V_48 ) ;
F_29 ( V_42 ) ;
F_30 ( V_42 ) ;
return 0 ;
}
static void F_33 ( struct V_39 * V_40 )
{
F_4 () ;
}
static int T_8 F_34 ( void )
{
return F_35 ( & V_49 , F_19 ) ;
}
static void T_9 F_36 ( void )
{
F_37 ( & V_49 ) ;
}
