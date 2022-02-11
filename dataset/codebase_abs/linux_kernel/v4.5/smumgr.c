int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( ( V_4 == NULL ) || ( V_2 == NULL ) )
return - V_7 ;
V_6 = F_2 ( sizeof( struct V_5 ) , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_6 -> V_10 = V_2 -> V_10 ;
V_6 -> V_11 = V_2 -> V_11 ;
V_6 -> V_12 = V_2 -> V_12 ;
V_6 -> V_13 = V_2 -> V_14 ;
V_6 -> V_15 = V_16 ;
V_6 -> V_17 = 1 ;
V_4 -> V_18 = V_6 ;
switch ( V_6 -> V_11 ) {
case V_19 :
F_3 ( V_6 ) ;
break;
case V_20 :
switch ( V_6 -> V_12 ) {
case V_21 :
F_4 ( V_6 ) ;
break;
case V_22 :
F_5 ( V_6 ) ;
break;
default:
return - V_7 ;
}
break;
default:
F_6 ( V_6 ) ;
return - V_7 ;
}
return 0 ;
}
int F_7 ( struct V_5 * V_6 )
{
F_6 ( V_6 ) ;
return 0 ;
}
int F_8 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_23 -> V_24 )
return V_6 -> V_23 -> V_24 ( V_6 ) ;
return 0 ;
}
int F_9 ( struct V_5 * V_6 ,
void * * V_25 )
{
if ( NULL != V_6 -> V_23 -> V_26 )
return V_6 -> V_23 -> V_26 ( V_6 ,
V_25 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_23 -> V_27 )
return V_6 -> V_23 -> V_27 ( V_6 ) ;
return 0 ;
}
int F_11 ( struct V_5 * V_6 , T_1 V_28 )
{
if ( V_6 == NULL || V_6 -> V_23 -> V_29 == NULL )
return - V_7 ;
return V_6 -> V_23 -> V_29 ( V_6 , V_28 ) ;
}
int F_12 ( struct V_5 * V_6 ,
T_1 V_28 , T_2 V_30 )
{
if ( V_6 == NULL ||
V_6 -> V_23 -> V_31 == NULL )
return - V_7 ;
return V_6 -> V_23 -> V_31 (
V_6 , V_28 , V_30 ) ;
}
int F_13 ( struct V_5 * V_6 ,
T_2 V_32 ,
T_2 V_33 , T_2 V_34 )
{
T_2 V_35 ;
T_2 V_36 ;
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return - V_7 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_15 ; V_35 ++ ) {
V_36 = F_14 ( V_6 -> V_10 , V_32 ) ;
if ( ( V_36 & V_34 ) == ( V_33 & V_34 ) )
break;
F_15 ( 1 ) ;
}
if ( V_35 == V_6 -> V_15 )
return - 1 ;
return 0 ;
}
int F_16 ( struct V_5 * V_6 ,
T_2 V_32 ,
T_2 V_33 , T_2 V_34 )
{
T_2 V_35 ;
T_2 V_36 ;
if ( V_6 == NULL )
return - V_7 ;
for ( V_35 = 0 ; V_35 < V_6 -> V_15 ; V_35 ++ ) {
V_36 = F_14 ( V_6 -> V_10 ,
V_32 ) ;
if ( ( V_36 & V_34 ) != ( V_33 & V_34 ) )
break;
F_15 ( 1 ) ;
}
if ( V_35 == V_6 -> V_15 )
return - 1 ;
return 0 ;
}
int F_17 ( struct V_5 * V_6 ,
T_2 V_37 ,
T_2 V_32 ,
T_2 V_33 ,
T_2 V_34 )
{
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return - V_7 ;
F_18 ( V_6 -> V_10 , V_37 , V_32 ) ;
return F_13 ( V_6 , V_37 + 1 ,
V_34 , V_33 ) ;
}
void F_19 (
struct V_5 * V_6 ,
T_2 V_37 ,
T_2 V_32 ,
T_2 V_33 ,
T_2 V_34 )
{
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return;
F_18 ( V_6 -> V_10 , V_37 , V_32 ) ;
F_16 ( V_6 , V_37 + 1 ,
V_33 , V_34 ) ;
}
int F_20 ( void * V_10 , T_2 V_38 ,
enum V_39 type ,
T_2 V_40 , T_3 * V_41 ,
void * * V_42 , void * V_4 )
{
int V_43 = 0 ;
T_4 V_44 ;
if ( V_10 == NULL || V_4 == NULL ||
V_41 == NULL || V_42 == NULL )
return - V_7 ;
V_43 = F_21 ( V_10 , type , V_38 , V_40 ,
0 , 0 , ( T_4 * ) V_4 ) ;
if ( V_43 )
return - V_9 ;
V_44 = * ( T_4 * ) V_4 ;
V_43 = F_22 ( V_10 , V_44 , V_41 ) ;
if ( V_43 )
goto V_45;
V_43 = F_23 ( V_10 , V_44 , V_42 ) ;
if ( V_43 )
goto V_46;
return 0 ;
V_46:
F_24 ( V_10 , V_44 ) ;
V_45:
F_25 ( V_10 , V_44 ) ;
return V_43 ;
}
int F_26 ( void * V_10 , void * V_4 )
{
T_4 V_44 = ( T_4 ) V_4 ;
if ( V_10 == NULL || V_4 == NULL )
return - V_7 ;
F_27 ( V_10 , V_44 ) ;
F_24 ( V_10 , V_44 ) ;
F_25 ( V_10 , V_44 ) ;
return 0 ;
}
