static T_1 F_1 ( unsigned long V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static void F_3 ( T_1 V_3 , unsigned long V_1 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( int V_4 , bool V_5 )
{
bool V_6 ;
unsigned long V_7 ;
F_6 ( & V_8 , V_7 ) ;
V_6 = F_1 ( V_9 ) & ( 1 << V_4 ) ;
if ( V_6 == V_5 ) {
F_7 ( & V_8 , V_7 ) ;
return - V_10 ;
}
F_3 ( V_11 | V_4 , V_12 ) ;
F_7 ( & V_8 , V_7 ) ;
return 0 ;
}
int F_8 ( int V_4 )
{
if ( V_4 < 0 || V_4 >= V_13 )
return - V_10 ;
return F_5 ( V_4 , true ) ;
}
int F_9 ( int V_4 )
{
if ( V_4 < 0 || V_4 >= V_13 )
return - V_10 ;
return F_5 ( V_4 , false ) ;
}
int F_10 ( int V_4 )
{
T_1 V_6 ;
if ( V_4 < 0 || V_4 >= V_13 )
return - V_10 ;
V_6 = F_1 ( V_9 ) & ( 1 << V_4 ) ;
return ! ! V_6 ;
}
int F_11 ( int V_4 )
{
T_1 V_14 ;
if ( V_4 < 0 || V_4 >= V_13 )
return - V_10 ;
if ( V_4 == V_15 )
V_14 = ( 1 << V_16 ) ;
else if ( V_4 == V_16 )
V_14 = ( 1 << V_15 ) ;
else
V_14 = ( 1 << V_4 ) ;
F_3 ( V_14 , V_17 ) ;
return 0 ;
}
int F_12 ( int V_4 , struct V_18 * V_18 )
{
int V_19 ;
F_13 ( V_18 ) ;
V_19 = F_8 ( V_4 ) ;
if ( V_19 )
goto V_20;
V_19 = F_14 ( V_18 ) ;
if ( V_19 )
goto V_21;
F_15 ( 10 ) ;
V_19 = F_11 ( V_4 ) ;
if ( V_19 )
goto V_22;
F_15 ( 10 ) ;
F_16 ( V_18 ) ;
return 0 ;
V_22:
F_17 ( V_18 ) ;
V_21:
F_9 ( V_4 ) ;
V_20:
return V_19 ;
}
int F_18 ( int V_23 )
{
if ( V_23 > 0 && V_23 < V_24 )
return V_25 [ V_23 ] ;
return - V_10 ;
}
int T_2 F_19 ( void )
{
switch ( V_26 ) {
case V_27 :
V_13 = 7 ;
break;
case V_28 :
V_13 = 14 ;
V_24 = 4 ;
V_25 = V_29 ;
break;
default:
V_13 = 0 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_30 * V_31 , void * V_32 )
{
int V_33 ;
F_21 ( V_31 , L_1 ) ;
F_21 ( V_31 , L_2 ) ;
for ( V_33 = 0 ; V_33 < V_13 ; V_33 ++ )
F_21 ( V_31 , L_3 , V_34 [ V_33 ] ,
F_10 ( V_33 ) ? L_4 : L_5 ) ;
return 0 ;
}
static int F_22 ( struct V_35 * V_35 , struct V_36 * V_36 )
{
return F_23 ( V_36 , F_20 , V_35 -> V_37 ) ;
}
int T_2 F_24 ( void )
{
struct V_38 * V_39 ;
switch ( V_26 ) {
case V_27 :
V_34 = V_40 ;
break;
case V_28 :
V_34 = V_41 ;
break;
}
if ( V_34 ) {
V_39 = F_25 ( L_6 , V_42 , NULL , NULL ,
& V_43 ) ;
if ( ! V_39 )
return - V_44 ;
}
return 0 ;
}
