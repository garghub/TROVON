static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 , char T_3 * V_6 , T_4 V_7 ,
T_1 * V_8 )
{
return F_4 ( V_6 , V_7 , V_8 , V_9 ,
V_5 ) ;
}
static int F_5 ( void )
{
struct V_10 V_11 ;
int V_12 , V_13 ;
V_13 = F_6 () ;
if ( V_13 < 0 ) {
if ( V_13 != - V_14 )
F_7 ( L_1 ,
V_13 ) ;
return V_13 ;
}
V_12 = F_8 ( V_13 , V_15 , V_16 ) ;
switch ( V_12 ) {
case V_17 :
V_12 = F_9 ( V_13 , & V_11 ) ;
if ( V_12 ) {
F_7 ( L_2 ,
V_12 ) ;
break;
}
V_12 = F_10 ( V_11 ) ;
if ( V_12 != V_18 ) {
F_7 ( L_3 ,
V_12 ) ;
break;
}
case V_18 :
break;
default:
F_7 ( L_4 , V_12 ) ;
}
F_11 ( V_13 ) ;
return V_12 ;
}
static T_2 F_12 ( struct V_1 * V_2 , const char T_3 * V_6 ,
T_4 V_7 , T_1 * V_8 )
{
T_1 V_19 = * V_8 ;
T_2 V_20 ;
int V_12 ;
if ( ! * V_8 )
memset ( V_9 , ' ' , V_5 ) ;
else if ( * V_8 >= V_5 )
return - V_21 ;
V_20 = F_13 ( V_9 , V_5 , V_8 , V_6 ,
V_7 ) ;
if ( V_20 > 0 ) {
V_12 = F_5 () ;
if ( V_12 != V_18 ) {
F_14 ( L_5 ,
V_12 ) ;
* V_8 = V_19 ;
return - V_22 ;
}
}
return V_20 ;
}
static int F_15 ( struct V_23 * V_23 , struct V_1 * V_2 )
{
if ( ! F_16 ( & V_24 ) ) {
F_7 ( L_6 ) ;
return - V_25 ;
}
return 0 ;
}
static int F_17 ( struct V_23 * V_23 , struct V_1 * V_2 )
{
F_18 ( & V_24 ) ;
return 0 ;
}
static int F_19 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = V_27 -> V_30 . V_31 ;
T_5 V_32 ;
int V_12 , V_33 ;
V_12 = F_20 ( V_29 , L_7 , & V_32 ) ;
if ( V_12 ) {
F_14 ( L_8 ) ;
return V_12 ;
}
V_12 = F_20 ( V_29 , L_9 , & V_16 ) ;
if ( V_12 ) {
F_14 ( L_10 ) ;
return V_12 ;
}
V_5 = V_32 * V_16 ;
F_21 ( L_11 ,
V_5 , V_16 , V_32 ) ;
V_9 = F_22 ( V_5 , sizeof( * V_9 ) , V_34 ) ;
if ( ! V_9 )
return - V_35 ;
V_15 = F_22 ( V_16 , sizeof( V_36 ) , V_34 ) ;
if ( ! V_15 ) {
V_12 = - V_35 ;
goto V_37;
}
memset ( V_9 , ' ' , V_5 ) ;
for ( V_33 = 0 ; V_33 < V_16 ; V_33 ++ ) {
V_15 [ V_33 ] . V_32 = F_23 ( V_32 ) ;
V_15 [ V_33 ] . line = F_23 ( F_24 ( & V_9 [ V_33 *
V_32 ] ) ) ;
}
V_12 = F_25 ( & V_38 ) ;
if ( V_12 ) {
F_14 ( L_12 ) ;
goto V_39;
}
return 0 ;
V_39:
F_26 ( V_15 ) ;
V_37:
F_26 ( V_9 ) ;
return V_12 ;
}
static int F_27 ( struct V_26 * V_27 )
{
F_28 ( & V_38 ) ;
F_26 ( V_15 ) ;
F_26 ( V_9 ) ;
return 0 ;
}
