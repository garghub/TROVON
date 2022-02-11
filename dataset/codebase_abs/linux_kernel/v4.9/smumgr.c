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
V_6 -> V_13 = V_14 ;
V_6 -> V_15 = 1 ;
V_4 -> V_16 = V_6 ;
switch ( V_6 -> V_11 ) {
case V_17 :
F_3 ( V_6 ) ;
break;
case V_18 :
switch ( V_6 -> V_12 ) {
case V_19 :
F_4 ( V_6 ) ;
break;
case V_20 :
F_5 ( V_6 ) ;
break;
case V_21 :
F_6 ( V_6 ) ;
break;
case V_22 :
case V_23 :
F_7 ( V_6 ) ;
break;
default:
return - V_7 ;
}
break;
default:
F_8 ( V_6 ) ;
return - V_7 ;
}
return 0 ;
}
int F_9 ( struct V_5 * V_6 )
{
F_8 ( V_6 -> V_10 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
int F_10 ( struct V_24 * V_25 ,
void * V_26 , void * V_27 , void * V_28 , int V_29 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_31 )
return V_25 -> V_6 -> V_30 -> V_31 ( V_25 ) ;
return 0 ;
}
int F_11 ( struct V_24 * V_25 ,
void * V_26 , void * V_27 , void * V_28 , int V_29 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_32 )
return V_25 -> V_6 -> V_30 -> V_32 ( V_25 ) ;
return 0 ;
}
int F_12 ( struct V_24 * V_25 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_33 )
return V_25 -> V_6 -> V_30 -> V_33 ( V_25 ) ;
return 0 ;
}
int F_13 ( struct V_24 * V_25 , T_1 type )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_34 )
return V_25 -> V_6 -> V_30 -> V_34 ( V_25 , type ) ;
return 0 ;
}
T_1 F_14 ( struct V_5 * V_6 , T_1 type , T_1 V_35 )
{
if ( NULL != V_6 -> V_30 -> V_36 )
return V_6 -> V_30 -> V_36 ( type , V_35 ) ;
return 0 ;
}
int F_15 ( struct V_24 * V_25 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_37 )
return V_25 -> V_6 -> V_30 -> V_37 ( V_25 ) ;
return 0 ;
}
int F_16 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_30 -> V_38 )
return V_6 -> V_30 -> V_38 ( V_6 ) ;
return 0 ;
}
T_1 F_17 ( struct V_5 * V_6 , T_1 V_39 )
{
if ( NULL != V_6 -> V_30 -> V_40 )
return V_6 -> V_30 -> V_40 ( V_39 ) ;
return 0 ;
}
int F_18 ( struct V_5 * V_6 ,
void * * V_41 )
{
if ( NULL != V_6 -> V_30 -> V_42 )
return V_6 -> V_30 -> V_42 ( V_6 ,
V_41 ) ;
return 0 ;
}
int F_19 ( struct V_5 * V_6 )
{
if ( NULL != V_6 -> V_30 -> V_43 )
return V_6 -> V_30 -> V_43 ( V_6 ) ;
return 0 ;
}
int F_20 ( struct V_5 * V_6 , T_2 V_44 )
{
if ( V_6 == NULL || V_6 -> V_30 -> V_45 == NULL )
return - V_7 ;
return V_6 -> V_30 -> V_45 ( V_6 , V_44 ) ;
}
int F_21 ( struct V_5 * V_6 ,
T_2 V_44 , T_1 V_46 )
{
if ( V_6 == NULL ||
V_6 -> V_30 -> V_47 == NULL )
return - V_7 ;
return V_6 -> V_30 -> V_47 (
V_6 , V_44 , V_46 ) ;
}
int F_22 ( struct V_5 * V_6 ,
T_1 V_48 ,
T_1 V_39 , T_1 V_49 )
{
T_1 V_50 ;
T_1 V_51 ;
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return - V_7 ;
for ( V_50 = 0 ; V_50 < V_6 -> V_13 ; V_50 ++ ) {
V_51 = F_23 ( V_6 -> V_10 , V_48 ) ;
if ( ( V_51 & V_49 ) == ( V_39 & V_49 ) )
break;
F_24 ( 1 ) ;
}
if ( V_50 == V_6 -> V_13 )
return - 1 ;
return 0 ;
}
int F_25 ( struct V_5 * V_6 ,
T_1 V_48 ,
T_1 V_39 , T_1 V_49 )
{
T_1 V_50 ;
T_1 V_51 ;
if ( V_6 == NULL )
return - V_7 ;
for ( V_50 = 0 ; V_50 < V_6 -> V_13 ; V_50 ++ ) {
V_51 = F_23 ( V_6 -> V_10 ,
V_48 ) ;
if ( ( V_51 & V_49 ) != ( V_39 & V_49 ) )
break;
F_24 ( 1 ) ;
}
if ( V_50 == V_6 -> V_13 )
return - 1 ;
return 0 ;
}
int F_26 ( struct V_5 * V_6 ,
T_1 V_52 ,
T_1 V_48 ,
T_1 V_39 ,
T_1 V_49 )
{
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return - V_7 ;
F_27 ( V_6 -> V_10 , V_52 , V_48 ) ;
return F_22 ( V_6 , V_52 + 1 ,
V_49 , V_39 ) ;
}
void F_28 (
struct V_5 * V_6 ,
T_1 V_52 ,
T_1 V_48 ,
T_1 V_39 ,
T_1 V_49 )
{
if ( V_6 == NULL || V_6 -> V_10 == NULL )
return;
F_27 ( V_6 -> V_10 , V_52 , V_48 ) ;
F_25 ( V_6 , V_52 + 1 ,
V_39 , V_49 ) ;
}
int F_29 ( void * V_10 , T_1 V_53 ,
enum V_54 type ,
T_1 V_55 , T_3 * V_56 ,
void * * V_57 , void * V_4 )
{
int V_58 = 0 ;
T_4 V_59 ;
if ( V_10 == NULL || V_4 == NULL ||
V_56 == NULL || V_57 == NULL )
return - V_7 ;
V_58 = F_30 ( V_10 , type , V_53 , V_55 ,
0 , 0 , ( T_4 * ) V_4 ) ;
if ( V_58 )
return - V_9 ;
V_59 = * ( T_4 * ) V_4 ;
V_58 = F_31 ( V_10 , V_59 , V_56 ) ;
if ( V_58 )
goto V_60;
V_58 = F_32 ( V_10 , V_59 , V_57 ) ;
if ( V_58 )
goto V_61;
return 0 ;
V_61:
F_33 ( V_10 , V_59 ) ;
V_60:
F_34 ( V_10 , V_59 ) ;
return V_58 ;
}
int F_35 ( void * V_10 , void * V_4 )
{
T_4 V_59 = ( T_4 ) V_4 ;
if ( V_10 == NULL || V_4 == NULL )
return - V_7 ;
F_36 ( V_10 , V_59 ) ;
F_33 ( V_10 , V_59 ) ;
F_34 ( V_10 , V_59 ) ;
return 0 ;
}
int F_37 ( struct V_24 * V_25 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_62 )
return V_25 -> V_6 -> V_30 -> V_62 ( V_25 ) ;
return 0 ;
}
int F_38 ( struct V_24 * V_25 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_63 )
return V_25 -> V_6 -> V_30 -> V_63 ( V_25 ) ;
return 0 ;
}
int F_39 ( struct V_24 * V_25 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_64 )
return V_25 -> V_6 -> V_30 -> V_64 ( V_25 ) ;
return 0 ;
}
int F_40 ( struct V_24 * V_25 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_65 )
return V_25 -> V_6 -> V_30 -> V_65 ( V_25 ) ;
return 0 ;
}
bool F_41 ( struct V_24 * V_25 )
{
if ( NULL != V_25 -> V_6 -> V_30 -> V_66 )
return V_25 -> V_6 -> V_30 -> V_66 ( V_25 ) ;
return true ;
}
