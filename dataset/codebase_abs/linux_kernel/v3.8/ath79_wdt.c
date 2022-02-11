static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 * V_3 ) ;
F_3 ( V_1 ) ;
}
static inline void F_4 ( void )
{
F_1 () ;
F_2 ( V_4 , V_5 ) ;
F_3 ( V_4 ) ;
}
static inline void F_5 ( void )
{
F_2 ( V_4 , V_6 ) ;
F_3 ( V_4 ) ;
}
static int F_6 ( int V_7 )
{
if ( V_7 < 1 || V_7 > V_8 )
return - V_9 ;
V_3 = V_7 ;
F_1 () ;
return 0 ;
}
static int F_7 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_8 ( V_12 , & V_13 ) )
return - V_14 ;
F_9 ( V_15 , & V_13 ) ;
F_4 () ;
return F_10 ( V_10 , V_11 ) ;
}
static int F_11 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_12 ( V_15 , & V_13 ) )
F_5 () ;
else {
F_13 ( L_1 ) ;
F_1 () ;
}
F_9 ( V_12 , & V_13 ) ;
F_9 ( V_15 , & V_13 ) ;
return 0 ;
}
static T_1 F_14 ( struct V_11 * V_11 , const char * V_16 ,
T_2 V_17 , T_3 * V_18 )
{
if ( V_17 ) {
if ( ! V_19 ) {
T_2 V_20 ;
F_9 ( V_15 , & V_13 ) ;
for ( V_20 = 0 ; V_20 != V_17 ; V_20 ++ ) {
char V_21 ;
if ( F_15 ( V_21 , V_16 + V_20 ) )
return - V_22 ;
if ( V_21 == 'V' )
F_16 ( V_15 ,
& V_13 ) ;
}
}
F_1 () ;
}
return V_17 ;
}
static long F_17 ( struct V_11 * V_11 , unsigned int V_23 ,
unsigned long V_24 )
{
void T_4 * V_25 = ( void T_4 * ) V_24 ;
int T_4 * V_26 = V_25 ;
int V_27 ;
int V_28 ;
switch ( V_23 ) {
case V_29 :
V_27 = F_18 ( V_25 , & V_30 ,
sizeof( V_30 ) ) ? - V_22 : 0 ;
break;
case V_31 :
V_27 = F_19 ( 0 , V_26 ) ;
break;
case V_32 :
V_27 = F_19 ( V_33 , V_26 ) ;
break;
case V_34 :
F_1 () ;
V_27 = 0 ;
break;
case V_35 :
V_27 = F_15 ( V_28 , V_26 ) ;
if ( V_27 )
break;
V_27 = F_6 ( V_28 ) ;
if ( V_27 )
break;
case V_36 :
V_27 = F_19 ( V_3 , V_26 ) ;
break;
default:
V_27 = - V_37 ;
break;
}
return V_27 ;
}
static int F_20 ( struct V_38 * V_39 )
{
T_5 V_40 ;
int V_27 ;
V_41 = F_21 ( & V_39 -> V_42 , L_2 ) ;
if ( F_22 ( V_41 ) )
return F_23 ( V_41 ) ;
V_27 = F_24 ( V_41 ) ;
if ( V_27 )
goto V_43;
V_2 = F_25 ( V_41 ) ;
if ( ! V_2 ) {
V_27 = - V_9 ;
goto V_44;
}
V_8 = ( 0xfffffffful / V_2 ) ;
if ( V_3 < 1 || V_3 > V_8 ) {
V_3 = V_8 ;
F_26 ( & V_39 -> V_42 ,
L_3 ,
V_8 , V_3 ) ;
}
V_40 = F_3 ( V_4 ) ;
V_33 = ( V_40 & V_45 ) ? V_46 : 0 ;
V_27 = F_27 ( & V_47 ) ;
if ( V_27 ) {
F_28 ( & V_39 -> V_42 ,
L_4 , V_27 ) ;
goto V_44;
}
return 0 ;
V_44:
F_29 ( V_41 ) ;
V_43:
F_30 ( V_41 ) ;
return V_27 ;
}
static int F_31 ( struct V_38 * V_39 )
{
F_32 ( & V_47 ) ;
F_29 ( V_41 ) ;
F_30 ( V_41 ) ;
return 0 ;
}
static void F_33 ( struct V_38 * V_39 )
{
F_5 () ;
}
