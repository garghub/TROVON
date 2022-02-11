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
case V_29 :
switch ( V_4 -> V_10 ) {
case V_30 :
V_4 -> V_16 = & V_31 ;
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
int F_4 ( struct V_32 * V_33 ,
void * V_34 , void * V_35 , void * V_36 , int V_37 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_38 )
return V_33 -> V_4 -> V_16 -> V_38 ( V_33 ) ;
return 0 ;
}
int F_5 ( struct V_32 * V_33 ,
void * V_34 , void * V_35 , void * V_36 , int V_37 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_39 )
return V_33 -> V_4 -> V_16 -> V_39 ( V_33 ) ;
return 0 ;
}
int F_6 ( struct V_32 * V_33 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_40 )
return V_33 -> V_4 -> V_16 -> V_40 ( V_33 ) ;
return 0 ;
}
int F_7 ( struct V_32 * V_33 , T_1 type )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_41 )
return V_33 -> V_4 -> V_16 -> V_41 ( V_33 , type ) ;
return 0 ;
}
T_1 F_8 ( struct V_3 * V_4 , T_1 type , T_1 V_42 )
{
if ( NULL != V_4 -> V_16 -> V_43 )
return V_4 -> V_16 -> V_43 ( type , V_42 ) ;
return 0 ;
}
int F_9 ( struct V_32 * V_33 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_44 )
return V_33 -> V_4 -> V_16 -> V_44 ( V_33 ) ;
return 0 ;
}
int F_10 ( struct V_3 * V_4 )
{
if ( NULL != V_4 -> V_16 -> V_45 )
return V_4 -> V_16 -> V_45 ( V_4 ) ;
return 0 ;
}
T_1 F_11 ( struct V_3 * V_4 , T_1 V_46 )
{
if ( NULL != V_4 -> V_16 -> V_47 )
return V_4 -> V_16 -> V_47 ( V_46 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 ,
void * * V_48 )
{
if ( NULL != V_4 -> V_16 -> V_49 )
return V_4 -> V_16 -> V_49 ( V_4 ,
V_48 ) ;
return 0 ;
}
int F_13 ( struct V_3 * V_4 )
{
if ( NULL != V_4 -> V_16 -> V_50 )
return V_4 -> V_16 -> V_50 ( V_4 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 , T_2 V_51 )
{
if ( V_4 == NULL || V_4 -> V_16 -> V_52 == NULL )
return - V_5 ;
return V_4 -> V_16 -> V_52 ( V_4 , V_51 ) ;
}
int F_15 ( struct V_3 * V_4 ,
T_2 V_51 , T_1 V_53 )
{
if ( V_4 == NULL ||
V_4 -> V_16 -> V_54 == NULL )
return - V_5 ;
return V_4 -> V_16 -> V_54 (
V_4 , V_51 , V_53 ) ;
}
int F_16 ( struct V_3 * V_4 ,
T_1 V_55 ,
T_1 V_46 , T_1 V_56 )
{
T_1 V_57 ;
T_1 V_58 ;
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return - V_5 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_11 ; V_57 ++ ) {
V_58 = F_17 ( V_4 -> V_8 , V_55 ) ;
if ( ( V_58 & V_56 ) == ( V_46 & V_56 ) )
break;
F_18 ( 1 ) ;
}
if ( V_57 == V_4 -> V_11 )
return - 1 ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 ,
T_1 V_55 ,
T_1 V_46 , T_1 V_56 )
{
T_1 V_57 ;
T_1 V_58 ;
if ( V_4 == NULL )
return - V_5 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_11 ; V_57 ++ ) {
V_58 = F_17 ( V_4 -> V_8 ,
V_55 ) ;
if ( ( V_58 & V_56 ) != ( V_46 & V_56 ) )
break;
F_18 ( 1 ) ;
}
if ( V_57 == V_4 -> V_11 )
return - 1 ;
return 0 ;
}
int F_20 ( struct V_3 * V_4 ,
T_1 V_59 ,
T_1 V_55 ,
T_1 V_46 ,
T_1 V_56 )
{
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return - V_5 ;
F_21 ( V_4 -> V_8 , V_59 , V_55 ) ;
return F_16 ( V_4 , V_59 + 1 ,
V_56 , V_46 ) ;
}
void F_22 (
struct V_3 * V_4 ,
T_1 V_59 ,
T_1 V_55 ,
T_1 V_46 ,
T_1 V_56 )
{
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return;
F_21 ( V_4 -> V_8 , V_59 , V_55 ) ;
F_19 ( V_4 , V_59 + 1 ,
V_46 , V_56 ) ;
}
int F_23 ( void * V_8 , T_1 V_60 ,
enum V_61 type ,
T_1 V_62 , T_3 * V_63 ,
void * * V_64 , void * V_2 )
{
int V_65 = 0 ;
T_4 V_66 ;
if ( V_8 == NULL || V_2 == NULL ||
V_63 == NULL || V_64 == NULL )
return - V_5 ;
V_65 = F_24 ( V_8 , type , V_60 , V_62 ,
0 , 0 , ( T_4 * ) V_2 ) ;
if ( V_65 )
return - V_7 ;
V_66 = * ( T_4 * ) V_2 ;
V_65 = F_25 ( V_8 , V_66 , V_63 ) ;
if ( V_65 )
goto V_67;
V_65 = F_26 ( V_8 , V_66 , V_64 ) ;
if ( V_65 )
goto V_68;
return 0 ;
V_68:
F_27 ( V_8 , V_66 ) ;
V_67:
F_28 ( V_8 , V_66 ) ;
return V_65 ;
}
int F_29 ( void * V_8 , void * V_2 )
{
T_4 V_66 = ( T_4 ) V_2 ;
if ( V_8 == NULL || V_2 == NULL )
return - V_5 ;
F_30 ( V_8 , V_66 ) ;
F_27 ( V_8 , V_66 ) ;
F_28 ( V_8 , V_66 ) ;
return 0 ;
}
int F_31 ( struct V_32 * V_33 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_69 )
return V_33 -> V_4 -> V_16 -> V_69 ( V_33 ) ;
return 0 ;
}
int F_32 ( struct V_32 * V_33 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_70 )
return V_33 -> V_4 -> V_16 -> V_70 ( V_33 ) ;
return 0 ;
}
int F_33 ( struct V_32 * V_33 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_71 )
return V_33 -> V_4 -> V_16 -> V_71 ( V_33 ) ;
return 0 ;
}
int F_34 ( struct V_32 * V_33 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_72 )
return V_33 -> V_4 -> V_16 -> V_72 ( V_33 ) ;
return 0 ;
}
bool F_35 ( struct V_32 * V_33 )
{
if ( NULL != V_33 -> V_4 -> V_16 -> V_73 )
return V_33 -> V_4 -> V_16 -> V_73 ( V_33 ) ;
return true ;
}
int F_36 ( struct V_32 * V_33 ,
struct V_74 * V_75 )
{
if ( V_33 -> V_4 -> V_16 -> V_76 )
return V_33 -> V_4 -> V_16 -> V_76 (
V_33 , V_75 ) ;
return 0 ;
}
