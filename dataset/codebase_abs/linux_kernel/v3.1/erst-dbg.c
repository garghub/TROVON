static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_3 , * V_4 ;
if ( V_5 )
return - V_6 ;
V_4 = ( int * ) & V_2 -> V_7 ;
V_3 = F_2 ( V_4 ) ;
if ( V_3 )
return V_3 ;
return F_3 ( V_1 , V_2 ) ;
}
static int F_4 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
F_5 () ;
return 0 ;
}
static long F_6 ( struct V_2 * V_8 , unsigned int V_9 , unsigned long V_10 )
{
int V_3 ;
T_1 V_11 ;
T_2 V_12 ;
switch ( V_9 ) {
case V_13 :
V_3 = F_7 ( & V_11 , ( void V_14 * ) V_10 ,
sizeof( V_11 ) ) ;
if ( V_3 )
return - V_15 ;
return F_8 ( V_11 ) ;
case V_16 :
V_3 = F_9 () ;
if ( V_3 < 0 )
return V_3 ;
V_12 = V_3 ;
V_3 = F_10 ( V_12 , ( T_2 V_14 * ) V_10 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
default:
return - V_17 ;
}
}
static T_3 F_11 ( struct V_2 * V_18 , char V_14 * V_19 ,
T_4 V_20 , T_5 * V_21 )
{
int V_3 , * V_4 ;
T_3 V_22 = 0 ;
T_1 V_23 ;
if ( * V_21 )
return - V_24 ;
if ( F_12 ( & V_25 ) != 0 )
return - V_26 ;
V_4 = ( int * ) & V_18 -> V_7 ;
V_27:
V_3 = F_13 ( V_4 , & V_23 ) ;
if ( V_3 )
goto V_28;
if ( V_23 == V_29 )
goto V_28;
V_30:
V_3 = V_22 = F_14 ( V_23 , V_31 , V_32 ) ;
if ( V_3 == - V_33 )
goto V_27;
if ( V_3 < 0 )
goto V_28;
if ( V_22 > V_34 ) {
F_15 ( V_35
L_1 ,
V_23 , V_22 ) ;
V_3 = - V_36 ;
goto V_28;
}
if ( V_22 > V_32 ) {
void * V_37 ;
V_3 = - V_38 ;
V_37 = F_16 ( V_22 , V_39 ) ;
if ( ! V_37 )
goto V_28;
F_17 ( V_31 ) ;
V_31 = V_37 ;
V_32 = V_22 ;
goto V_30;
}
V_3 = - V_24 ;
if ( V_22 > V_20 )
goto V_28;
V_3 = - V_15 ;
if ( F_18 ( V_19 , V_31 , V_22 ) )
goto V_28;
V_3 = 0 ;
V_28:
F_19 ( & V_25 ) ;
return V_3 ? V_3 : V_22 ;
}
static T_3 F_20 ( struct V_2 * V_18 , const char V_14 * V_19 ,
T_4 V_20 , T_5 * V_21 )
{
int V_3 ;
struct V_40 * V_41 ;
if ( ! F_21 ( V_42 ) )
return - V_43 ;
if ( V_20 > V_34 ) {
F_22 ( V_35 L_2 ) ;
return - V_24 ;
}
if ( F_12 ( & V_25 ) )
return - V_26 ;
if ( V_20 > V_32 ) {
void * V_37 ;
V_3 = - V_38 ;
V_37 = F_16 ( V_20 , V_39 ) ;
if ( ! V_37 )
goto V_28;
F_17 ( V_31 ) ;
V_31 = V_37 ;
V_32 = V_20 ;
}
V_3 = F_7 ( V_31 , V_19 , V_20 ) ;
if ( V_3 ) {
V_3 = - V_15 ;
goto V_28;
}
V_41 = V_31 ;
V_3 = - V_24 ;
if ( V_41 -> V_44 != V_20 )
goto V_28;
V_3 = F_23 ( V_31 ) ;
V_28:
F_19 ( & V_25 ) ;
return V_3 < 0 ? V_3 : V_20 ;
}
static T_6 int F_24 ( void )
{
if ( V_5 ) {
F_25 ( V_35 L_3 ) ;
return - V_6 ;
}
return F_26 ( & V_45 ) ;
}
static T_7 void F_27 ( void )
{
F_28 ( & V_45 ) ;
F_17 ( V_31 ) ;
}
