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
case V_23 :
case V_24 :
F_6 ( V_6 ) ;
break;
default:
return - V_7 ;
}
break;
default:
F_7 ( V_6 ) ;
return - V_7 ;
}
return 0 ;
}
int F_8 ( struct V_5 * V_6 )
{
F_7 ( V_6 -> V_10 ) ;
F_7 ( V_6 ) ;
return 0 ;
}
int F_9 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_25 -> V_26 )
return V_6 -> V_25 -> V_26 ( V_6 ) ;
return 0 ;
}
int F_10 ( struct V_5 * V_6 ,
void * * V_27 )
{
if ( NULL != V_6 -> V_25 -> V_28 )
return V_6 -> V_25 -> V_28 ( V_6 ,
V_27 ) ;
return 0 ;
}
int F_11 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_25 -> V_29 )
return V_6 -> V_25 -> V_29 ( V_6 ) ;
return 0 ;
}
int F_12 ( struct V_5 * V_6 , T_1 V_30 )
{
if ( V_6 == NULL || V_6 -> V_25 -> V_31 == NULL )
return - V_7 ;
return V_6 -> V_25 -> V_31 ( V_6 , V_30 ) ;
}
int F_13 ( struct V_5 * V_6 ,
T_1 V_30 , T_2 V_32 )
{
if ( V_6 == NULL ||
V_6 -> V_25 -> V_33 == NULL )
return - V_7 ;
return V_6 -> V_25 -> V_33 (
V_6 , V_30 , V_32 ) ;
}
int F_14 ( struct V_5 * V_6 ,
T_2 V_34 ,
T_2 V_35 , T_2 V_36 )
{
T_2 V_37 ;
T_2 V_38 ;
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return - V_7 ;
for ( V_37 = 0 ; V_37 < V_6 -> V_15 ; V_37 ++ ) {
V_38 = F_15 ( V_6 -> V_10 , V_34 ) ;
if ( ( V_38 & V_36 ) == ( V_35 & V_36 ) )
break;
F_16 ( 1 ) ;
}
if ( V_37 == V_6 -> V_15 )
return - 1 ;
return 0 ;
}
int F_17 ( struct V_5 * V_6 ,
T_2 V_34 ,
T_2 V_35 , T_2 V_36 )
{
T_2 V_37 ;
T_2 V_38 ;
if ( V_6 == NULL )
return - V_7 ;
for ( V_37 = 0 ; V_37 < V_6 -> V_15 ; V_37 ++ ) {
V_38 = F_15 ( V_6 -> V_10 ,
V_34 ) ;
if ( ( V_38 & V_36 ) != ( V_35 & V_36 ) )
break;
F_16 ( 1 ) ;
}
if ( V_37 == V_6 -> V_15 )
return - 1 ;
return 0 ;
}
int F_18 ( struct V_5 * V_6 ,
T_2 V_39 ,
T_2 V_34 ,
T_2 V_35 ,
T_2 V_36 )
{
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return - V_7 ;
F_19 ( V_6 -> V_10 , V_39 , V_34 ) ;
return F_14 ( V_6 , V_39 + 1 ,
V_36 , V_35 ) ;
}
void F_20 (
struct V_5 * V_6 ,
T_2 V_39 ,
T_2 V_34 ,
T_2 V_35 ,
T_2 V_36 )
{
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return;
F_19 ( V_6 -> V_10 , V_39 , V_34 ) ;
F_17 ( V_6 , V_39 + 1 ,
V_35 , V_36 ) ;
}
int F_21 ( void * V_10 , T_2 V_40 ,
enum V_41 type ,
T_2 V_42 , T_3 * V_43 ,
void * * V_44 , void * V_4 )
{
int V_45 = 0 ;
T_4 V_46 ;
if ( V_10 == NULL || V_4 == NULL ||
V_43 == NULL || V_44 == NULL )
return - V_7 ;
V_45 = F_22 ( V_10 , type , V_40 , V_42 ,
0 , 0 , ( T_4 * ) V_4 ) ;
if ( V_45 )
return - V_9 ;
V_46 = * ( T_4 * ) V_4 ;
V_45 = F_23 ( V_10 , V_46 , V_43 ) ;
if ( V_45 )
goto V_47;
V_45 = F_24 ( V_10 , V_46 , V_44 ) ;
if ( V_45 )
goto V_48;
return 0 ;
V_48:
F_25 ( V_10 , V_46 ) ;
V_47:
F_26 ( V_10 , V_46 ) ;
return V_45 ;
}
int F_27 ( void * V_10 , void * V_4 )
{
T_4 V_46 = ( T_4 ) V_4 ;
if ( V_10 == NULL || V_4 == NULL )
return - V_7 ;
F_28 ( V_10 , V_46 ) ;
F_25 ( V_10 , V_46 ) ;
F_26 ( V_10 , V_46 ) ;
return 0 ;
}
