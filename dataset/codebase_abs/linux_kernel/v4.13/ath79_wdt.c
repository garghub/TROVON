static inline void F_1 ( unsigned V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_3 + V_1 ) ;
}
static inline T_1 F_3 ( unsigned V_1 )
{
return F_4 ( V_3 + V_1 ) ;
}
static inline void F_5 ( void )
{
F_1 ( V_4 , V_5 * V_6 ) ;
F_3 ( V_4 ) ;
}
static inline void F_6 ( void )
{
F_5 () ;
F_7 ( 2 ) ;
F_1 ( V_7 , V_8 ) ;
F_3 ( V_7 ) ;
}
static inline void F_8 ( void )
{
F_1 ( V_7 , V_9 ) ;
F_3 ( V_7 ) ;
}
static int F_9 ( int V_2 )
{
if ( V_2 < 1 || V_2 > V_10 )
return - V_11 ;
V_6 = V_2 ;
F_5 () ;
return 0 ;
}
static int F_10 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_11 ( V_14 , & V_15 ) )
return - V_16 ;
F_12 ( V_17 , & V_15 ) ;
F_6 () ;
return F_13 ( V_12 , V_13 ) ;
}
static int F_14 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_15 ( V_17 , & V_15 ) )
F_8 () ;
else {
F_16 ( L_1 ) ;
F_5 () ;
}
F_12 ( V_14 , & V_15 ) ;
F_12 ( V_17 , & V_15 ) ;
return 0 ;
}
static T_2 F_17 ( struct V_13 * V_13 , const char * V_18 ,
T_3 V_19 , T_4 * V_20 )
{
if ( V_19 ) {
if ( ! V_21 ) {
T_3 V_22 ;
F_12 ( V_17 , & V_15 ) ;
for ( V_22 = 0 ; V_22 != V_19 ; V_22 ++ ) {
char V_23 ;
if ( F_18 ( V_23 , V_18 + V_22 ) )
return - V_24 ;
if ( V_23 == 'V' )
F_19 ( V_17 ,
& V_15 ) ;
}
}
F_5 () ;
}
return V_19 ;
}
static long F_20 ( struct V_13 * V_13 , unsigned int V_25 ,
unsigned long V_26 )
{
void T_5 * V_27 = ( void T_5 * ) V_26 ;
int T_5 * V_28 = V_27 ;
int V_29 ;
int V_30 ;
switch ( V_25 ) {
case V_31 :
V_29 = F_21 ( V_27 , & V_32 ,
sizeof( V_32 ) ) ? - V_24 : 0 ;
break;
case V_33 :
V_29 = F_22 ( 0 , V_28 ) ;
break;
case V_34 :
V_29 = F_22 ( V_35 , V_28 ) ;
break;
case V_36 :
F_5 () ;
V_29 = 0 ;
break;
case V_37 :
V_29 = F_18 ( V_30 , V_28 ) ;
if ( V_29 )
break;
V_29 = F_9 ( V_30 ) ;
if ( V_29 )
break;
case V_38 :
V_29 = F_22 ( V_6 , V_28 ) ;
break;
default:
V_29 = - V_39 ;
break;
}
return V_29 ;
}
static int F_23 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
T_1 V_44 ;
int V_29 ;
if ( V_3 )
return - V_16 ;
V_43 = F_24 ( V_41 , V_45 , 0 ) ;
V_3 = F_25 ( & V_41 -> V_46 , V_43 ) ;
if ( F_26 ( V_3 ) )
return F_27 ( V_3 ) ;
V_47 = F_28 ( & V_41 -> V_46 , L_2 ) ;
if ( F_26 ( V_47 ) )
return F_27 ( V_47 ) ;
V_29 = F_29 ( V_47 ) ;
if ( V_29 )
return V_29 ;
V_5 = F_30 ( V_47 ) ;
if ( ! V_5 ) {
V_29 = - V_11 ;
goto V_48;
}
V_10 = ( 0xfffffffful / V_5 ) ;
if ( V_6 < 1 || V_6 > V_10 ) {
V_6 = V_10 ;
F_31 ( & V_41 -> V_46 ,
L_3 ,
V_10 , V_6 ) ;
}
V_44 = F_3 ( V_7 ) ;
V_35 = ( V_44 & V_49 ) ? V_50 : 0 ;
V_29 = F_32 ( & V_51 ) ;
if ( V_29 ) {
F_33 ( & V_41 -> V_46 ,
L_4 , V_29 ) ;
goto V_48;
}
return 0 ;
V_48:
F_34 ( V_47 ) ;
return V_29 ;
}
static int F_35 ( struct V_40 * V_41 )
{
F_36 ( & V_51 ) ;
F_34 ( V_47 ) ;
return 0 ;
}
static void F_37 ( struct V_40 * V_41 )
{
F_8 () ;
}
