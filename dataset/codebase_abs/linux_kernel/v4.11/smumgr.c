int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 == NULL )
return - V_5 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_6 ) ;
if ( V_4 == NULL )
return - V_7 ;
V_4 -> V_8 = V_2 -> V_8 ;
V_4 -> V_9 = V_2 -> V_9 ;
V_4 -> V_10 = V_2 -> V_10 ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = 1 ;
V_2 -> V_14 = V_4 ;
switch ( V_4 -> V_9 ) {
case V_15 :
V_4 -> V_16 = & V_17 ;
break;
case V_18 :
switch ( V_4 -> V_10 ) {
case V_19 :
V_4 -> V_16 = & V_20 ;
break;
case V_21 :
V_4 -> V_16 = & V_22 ;
break;
case V_23 :
V_4 -> V_16 = & V_24 ;
break;
case V_25 :
case V_26 :
case V_27 :
V_4 -> V_16 = & V_28 ;
break;
default:
return - V_5 ;
}
break;
default:
F_3 ( V_4 ) ;
return - V_5 ;
}
return 0 ;
}
int F_4 ( struct V_29 * V_30 ,
void * V_31 , void * V_32 , void * V_33 , int V_34 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_35 )
return V_30 -> V_4 -> V_16 -> V_35 ( V_30 ) ;
return 0 ;
}
int F_5 ( struct V_29 * V_30 ,
void * V_31 , void * V_32 , void * V_33 , int V_34 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_36 )
return V_30 -> V_4 -> V_16 -> V_36 ( V_30 ) ;
return 0 ;
}
int F_6 ( struct V_29 * V_30 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_37 )
return V_30 -> V_4 -> V_16 -> V_37 ( V_30 ) ;
return 0 ;
}
int F_7 ( struct V_29 * V_30 , T_1 type )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_38 )
return V_30 -> V_4 -> V_16 -> V_38 ( V_30 , type ) ;
return 0 ;
}
T_1 F_8 ( struct V_3 * V_4 , T_1 type , T_1 V_39 )
{
if ( NULL != V_4 -> V_16 -> V_40 )
return V_4 -> V_16 -> V_40 ( type , V_39 ) ;
return 0 ;
}
int F_9 ( struct V_29 * V_30 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_41 )
return V_30 -> V_4 -> V_16 -> V_41 ( V_30 ) ;
return 0 ;
}
int F_10 ( struct V_3 * V_4 )
{
if ( NULL != V_4 -> V_16 -> V_42 )
return V_4 -> V_16 -> V_42 ( V_4 ) ;
return 0 ;
}
T_1 F_11 ( struct V_3 * V_4 , T_1 V_43 )
{
if ( NULL != V_4 -> V_16 -> V_44 )
return V_4 -> V_16 -> V_44 ( V_43 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 ,
void * * V_45 )
{
if ( NULL != V_4 -> V_16 -> V_46 )
return V_4 -> V_16 -> V_46 ( V_4 ,
V_45 ) ;
return 0 ;
}
int F_13 ( struct V_3 * V_4 )
{
if ( NULL != V_4 -> V_16 -> V_47 )
return V_4 -> V_16 -> V_47 ( V_4 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 , T_2 V_48 )
{
if ( V_4 == NULL || V_4 -> V_16 -> V_49 == NULL )
return - V_5 ;
return V_4 -> V_16 -> V_49 ( V_4 , V_48 ) ;
}
int F_15 ( struct V_3 * V_4 ,
T_2 V_48 , T_1 V_50 )
{
if ( V_4 == NULL ||
V_4 -> V_16 -> V_51 == NULL )
return - V_5 ;
return V_4 -> V_16 -> V_51 (
V_4 , V_48 , V_50 ) ;
}
int F_16 ( struct V_3 * V_4 ,
T_1 V_52 ,
T_1 V_43 , T_1 V_53 )
{
T_1 V_54 ;
T_1 V_55 ;
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return - V_5 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_11 ; V_54 ++ ) {
V_55 = F_17 ( V_4 -> V_8 , V_52 ) ;
if ( ( V_55 & V_53 ) == ( V_43 & V_53 ) )
break;
F_18 ( 1 ) ;
}
if ( V_54 == V_4 -> V_11 )
return - 1 ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 ,
T_1 V_52 ,
T_1 V_43 , T_1 V_53 )
{
T_1 V_54 ;
T_1 V_55 ;
if ( V_4 == NULL )
return - V_5 ;
for ( V_54 = 0 ; V_54 < V_4 -> V_11 ; V_54 ++ ) {
V_55 = F_17 ( V_4 -> V_8 ,
V_52 ) ;
if ( ( V_55 & V_53 ) != ( V_43 & V_53 ) )
break;
F_18 ( 1 ) ;
}
if ( V_54 == V_4 -> V_11 )
return - 1 ;
return 0 ;
}
int F_20 ( struct V_3 * V_4 ,
T_1 V_56 ,
T_1 V_52 ,
T_1 V_43 ,
T_1 V_53 )
{
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return - V_5 ;
F_21 ( V_4 -> V_8 , V_56 , V_52 ) ;
return F_16 ( V_4 , V_56 + 1 ,
V_53 , V_43 ) ;
}
void F_22 (
struct V_3 * V_4 ,
T_1 V_56 ,
T_1 V_52 ,
T_1 V_43 ,
T_1 V_53 )
{
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return;
F_21 ( V_4 -> V_8 , V_56 , V_52 ) ;
F_19 ( V_4 , V_56 + 1 ,
V_43 , V_53 ) ;
}
int F_23 ( void * V_8 , T_1 V_57 ,
enum V_58 type ,
T_1 V_59 , T_3 * V_60 ,
void * * V_61 , void * V_2 )
{
int V_62 = 0 ;
T_4 V_63 ;
if ( V_8 == NULL || V_2 == NULL ||
V_60 == NULL || V_61 == NULL )
return - V_5 ;
V_62 = F_24 ( V_8 , type , V_57 , V_59 ,
0 , 0 , ( T_4 * ) V_2 ) ;
if ( V_62 )
return - V_7 ;
V_63 = * ( T_4 * ) V_2 ;
V_62 = F_25 ( V_8 , V_63 , V_60 ) ;
if ( V_62 )
goto V_64;
V_62 = F_26 ( V_8 , V_63 , V_61 ) ;
if ( V_62 )
goto V_65;
return 0 ;
V_65:
F_27 ( V_8 , V_63 ) ;
V_64:
F_28 ( V_8 , V_63 ) ;
return V_62 ;
}
int F_29 ( void * V_8 , void * V_2 )
{
T_4 V_63 = ( T_4 ) V_2 ;
if ( V_8 == NULL || V_2 == NULL )
return - V_5 ;
F_30 ( V_8 , V_63 ) ;
F_27 ( V_8 , V_63 ) ;
F_28 ( V_8 , V_63 ) ;
return 0 ;
}
int F_31 ( struct V_29 * V_30 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_66 )
return V_30 -> V_4 -> V_16 -> V_66 ( V_30 ) ;
return 0 ;
}
int F_32 ( struct V_29 * V_30 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_67 )
return V_30 -> V_4 -> V_16 -> V_67 ( V_30 ) ;
return 0 ;
}
int F_33 ( struct V_29 * V_30 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_68 )
return V_30 -> V_4 -> V_16 -> V_68 ( V_30 ) ;
return 0 ;
}
int F_34 ( struct V_29 * V_30 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_69 )
return V_30 -> V_4 -> V_16 -> V_69 ( V_30 ) ;
return 0 ;
}
bool F_35 ( struct V_29 * V_30 )
{
if ( NULL != V_30 -> V_4 -> V_16 -> V_70 )
return V_30 -> V_4 -> V_16 -> V_70 ( V_30 ) ;
return true ;
}
