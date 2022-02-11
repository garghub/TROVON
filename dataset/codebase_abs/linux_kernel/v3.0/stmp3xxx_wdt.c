static void F_1 ( T_1 V_1 )
{
F_2 ( & V_2 ) ;
F_3 ( V_1 , V_3 + V_4 ) ;
F_4 ( V_5 , V_3 + V_6 ) ;
F_4 ( V_7 ,
V_3 + V_8 ) ;
F_5 ( & V_2 ) ;
}
static void F_6 ( void )
{
F_2 ( & V_2 ) ;
F_7 ( V_7 ,
V_3 + V_8 ) ;
F_7 ( V_5 , V_3 + V_6 ) ;
F_5 ( & V_2 ) ;
}
static void F_8 ( void )
{
F_1 ( V_9 * V_10 ) ;
}
static int F_9 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
if ( F_10 ( V_13 , & V_14 ) )
return - V_15 ;
F_11 ( V_16 , & V_14 ) ;
F_8 () ;
return F_12 ( V_11 , V_12 ) ;
}
static T_2 F_13 ( struct V_12 * V_12 , const char T_3 * V_17 ,
T_4 V_18 , T_5 * V_19 )
{
if ( V_18 ) {
if ( ! V_20 ) {
T_4 V_21 ;
F_11 ( V_16 , & V_14 ) ;
for ( V_21 = 0 ; V_21 != V_18 ; V_21 ++ ) {
char V_22 ;
if ( F_14 ( V_22 , V_17 + V_21 ) )
return - V_23 ;
if ( V_22 == 'V' )
F_15 ( V_16 , & V_14 ) ;
}
}
F_8 () ;
}
return V_18 ;
}
static long F_16 ( struct V_12 * V_12 , unsigned int V_24 ,
unsigned long V_25 )
{
void T_3 * V_26 = ( void T_3 * ) V_25 ;
int T_3 * V_27 = V_26 ;
int V_28 , V_29 ;
int V_30 = - V_31 ;
switch ( V_24 ) {
case V_32 :
V_30 = F_17 ( V_26 , & V_33 , sizeof( V_33 ) ) ? - V_23 : 0 ;
break;
case V_34 :
V_30 = F_18 ( 0 , V_27 ) ;
break;
case V_35 :
V_30 = F_18 ( V_36 , V_27 ) ;
break;
case V_37 :
if ( F_14 ( V_29 , V_27 ) ) {
V_30 = - V_23 ;
break;
}
if ( V_29 & V_38 )
F_6 () ;
else if ( V_29 & V_39 )
F_8 () ;
else {
F_19 ( L_1 , V_40 , V_29 ) ;
V_30 = - V_41 ;
break;
}
V_30 = 0 ;
break;
case V_42 :
F_8 () ;
V_30 = 0 ;
break;
case V_43 :
if ( F_14 ( V_28 , V_27 ) ) {
V_30 = - V_23 ;
break;
}
if ( V_28 <= 0 || V_28 > V_44 ) {
V_30 = - V_41 ;
break;
}
V_9 = V_28 ;
F_8 () ;
case V_45 :
V_30 = F_18 ( V_9 , V_27 ) ;
break;
}
return V_30 ;
}
static int F_20 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
int V_30 = 0 ;
if ( ! V_20 ) {
if ( ! F_21 ( V_16 , & V_14 ) ) {
F_8 () ;
F_19 ( L_2 , V_40 ) ;
V_30 = - V_41 ;
} else {
F_6 () ;
F_11 ( V_16 , & V_14 ) ;
}
}
F_11 ( V_13 , & V_14 ) ;
return V_30 ;
}
static int T_6 F_22 ( struct V_46 * V_47 )
{
int V_30 = 0 ;
if ( V_9 < 1 || V_9 > V_44 )
V_9 = V_48 ;
V_36 = F_23 ( V_3 + V_8 ) &
V_7 ;
V_36 = ! ! V_36 ;
F_7 ( V_7 ,
V_3 + V_8 ) ;
F_6 () ;
V_30 = F_24 ( & V_49 ) ;
if ( V_30 < 0 ) {
F_25 ( & V_47 -> V_50 , L_3 ) ;
return V_30 ;
}
F_26 ( V_51 L_4 ,
V_9 ) ;
return V_30 ;
}
static int T_7 F_27 ( struct V_46 * V_47 )
{
F_28 ( & V_49 ) ;
return 0 ;
}
static int F_29 ( struct V_46 * V_47 ,
T_8 V_52 )
{
if ( F_23 ( V_3 + V_6 ) &
V_5 ) {
V_53 = 1 ;
V_54 = F_23 ( V_3 + V_4 ) ;
F_6 () ;
}
return 0 ;
}
static int F_30 ( struct V_46 * V_47 )
{
if ( V_53 ) {
F_1 ( V_54 ) ;
V_53 = 0 ;
}
return 0 ;
}
static int T_9 F_31 ( void )
{
return F_32 ( & V_55 ) ;
}
static void T_10 F_33 ( void )
{
return F_34 ( & V_55 ) ;
}
