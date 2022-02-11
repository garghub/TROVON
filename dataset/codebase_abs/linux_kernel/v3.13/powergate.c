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
return 0 ;
}
F_3 ( V_10 | V_4 , V_11 ) ;
F_7 ( & V_8 , V_7 ) ;
return 0 ;
}
int F_8 ( int V_4 )
{
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
return F_5 ( V_4 , true ) ;
}
int F_9 ( int V_4 )
{
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
return F_5 ( V_4 , false ) ;
}
int F_10 ( int V_4 )
{
T_1 V_6 ;
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
V_6 = F_1 ( V_9 ) & ( 1 << V_4 ) ;
return ! ! V_6 ;
}
int F_11 ( int V_4 )
{
T_1 V_14 ;
if ( V_4 < 0 || V_4 >= V_12 )
return - V_13 ;
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
return - V_13 ;
}
int T_2 F_19 ( void )
{
switch ( V_26 ) {
case V_27 :
V_12 = 7 ;
break;
case V_28 :
V_12 = 14 ;
V_24 = 4 ;
V_25 = V_29 ;
break;
case V_30 :
V_12 = 23 ;
V_24 = 4 ;
V_25 = V_31 ;
break;
default:
V_12 = 0 ;
break;
}
return 0 ;
}
static int F_20 ( struct V_32 * V_33 , void * V_34 )
{
int V_35 ;
F_21 ( V_33 , L_1 ) ;
F_21 ( V_33 , L_2 ) ;
for ( V_35 = 0 ; V_35 < V_12 ; V_35 ++ ) {
if ( ! V_36 [ V_35 ] )
continue;
F_21 ( V_33 , L_3 , V_36 [ V_35 ] ,
F_10 ( V_35 ) ? L_4 : L_5 ) ;
}
return 0 ;
}
static int F_22 ( struct V_37 * V_37 , struct V_38 * V_38 )
{
return F_23 ( V_38 , F_20 , V_37 -> V_39 ) ;
}
int T_2 F_24 ( void )
{
struct V_40 * V_41 ;
switch ( V_26 ) {
case V_27 :
V_36 = V_42 ;
break;
case V_28 :
V_36 = V_43 ;
break;
case V_30 :
V_36 = V_44 ;
break;
}
if ( V_36 ) {
V_41 = F_25 ( L_6 , V_45 , NULL , NULL ,
& V_46 ) ;
if ( ! V_41 )
return - V_47 ;
}
return 0 ;
}
