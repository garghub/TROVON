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
case V_32 :
switch ( V_4 -> V_10 ) {
case V_33 :
V_4 -> V_16 = & V_34 ;
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
int F_4 ( struct V_35 * V_36 ,
void * V_37 , void * V_38 , void * V_39 , int V_40 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_41 )
return V_36 -> V_4 -> V_16 -> V_41 ( V_36 ) ;
return 0 ;
}
int F_5 ( struct V_35 * V_36 ,
void * V_37 , void * V_38 , void * V_39 , int V_40 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_42 )
return V_36 -> V_4 -> V_16 -> V_42 ( V_36 ) ;
return 0 ;
}
int F_6 ( struct V_35 * V_36 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_43 )
return V_36 -> V_4 -> V_16 -> V_43 ( V_36 ) ;
return 0 ;
}
int F_7 ( struct V_35 * V_36 , T_1 type )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_44 )
return V_36 -> V_4 -> V_16 -> V_44 ( V_36 , type ) ;
return 0 ;
}
T_1 F_8 ( struct V_3 * V_4 , T_1 type , T_1 V_45 )
{
if ( NULL != V_4 -> V_16 -> V_46 )
return V_4 -> V_16 -> V_46 ( type , V_45 ) ;
return 0 ;
}
int F_9 ( struct V_35 * V_36 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_47 )
return V_36 -> V_4 -> V_16 -> V_47 ( V_36 ) ;
return 0 ;
}
int F_10 ( struct V_3 * V_4 )
{
if ( NULL != V_4 -> V_16 -> V_48 )
return V_4 -> V_16 -> V_48 ( V_4 ) ;
return 0 ;
}
T_1 F_11 ( struct V_3 * V_4 , T_1 V_49 )
{
if ( NULL != V_4 -> V_16 -> V_50 )
return V_4 -> V_16 -> V_50 ( V_49 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_4 ,
void * * V_51 )
{
if ( NULL != V_4 -> V_16 -> V_52 )
return V_4 -> V_16 -> V_52 ( V_4 ,
V_51 ) ;
return 0 ;
}
int F_13 ( struct V_3 * V_4 )
{
if ( NULL != V_4 -> V_16 -> V_53 )
return V_4 -> V_16 -> V_53 ( V_4 ) ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 , T_2 V_54 )
{
if ( V_4 == NULL || V_4 -> V_16 -> V_55 == NULL )
return - V_5 ;
return V_4 -> V_16 -> V_55 ( V_4 , V_54 ) ;
}
int F_15 ( struct V_3 * V_4 ,
T_2 V_54 , T_1 V_56 )
{
if ( V_4 == NULL ||
V_4 -> V_16 -> V_57 == NULL )
return - V_5 ;
return V_4 -> V_16 -> V_57 (
V_4 , V_54 , V_56 ) ;
}
int F_16 ( struct V_3 * V_4 ,
T_1 V_58 ,
T_1 V_49 , T_1 V_59 )
{
T_1 V_60 ;
T_1 V_61 ;
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return - V_5 ;
for ( V_60 = 0 ; V_60 < V_4 -> V_11 ; V_60 ++ ) {
V_61 = F_17 ( V_4 -> V_8 , V_58 ) ;
if ( ( V_61 & V_59 ) == ( V_49 & V_59 ) )
break;
F_18 ( 1 ) ;
}
if ( V_60 == V_4 -> V_11 )
return - 1 ;
return 0 ;
}
int F_19 ( struct V_3 * V_4 ,
T_1 V_58 ,
T_1 V_49 , T_1 V_59 )
{
T_1 V_60 ;
T_1 V_61 ;
if ( V_4 == NULL )
return - V_5 ;
for ( V_60 = 0 ; V_60 < V_4 -> V_11 ; V_60 ++ ) {
V_61 = F_17 ( V_4 -> V_8 ,
V_58 ) ;
if ( ( V_61 & V_59 ) != ( V_49 & V_59 ) )
break;
F_18 ( 1 ) ;
}
if ( V_60 == V_4 -> V_11 )
return - 1 ;
return 0 ;
}
int F_20 ( struct V_3 * V_4 ,
T_1 V_62 ,
T_1 V_58 ,
T_1 V_49 ,
T_1 V_59 )
{
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return - V_5 ;
F_21 ( V_4 -> V_8 , V_62 , V_58 ) ;
return F_16 ( V_4 , V_62 + 1 ,
V_59 , V_49 ) ;
}
void F_22 (
struct V_3 * V_4 ,
T_1 V_62 ,
T_1 V_58 ,
T_1 V_49 ,
T_1 V_59 )
{
if ( V_4 == NULL || V_4 -> V_8 == NULL )
return;
F_21 ( V_4 -> V_8 , V_62 , V_58 ) ;
F_19 ( V_4 , V_62 + 1 ,
V_49 , V_59 ) ;
}
int F_23 ( void * V_8 , T_1 V_63 ,
enum V_64 type ,
T_1 V_65 , T_3 * V_66 ,
void * * V_67 , void * V_2 )
{
int V_68 = 0 ;
T_4 V_69 ;
if ( V_8 == NULL || V_2 == NULL ||
V_66 == NULL || V_67 == NULL )
return - V_5 ;
V_68 = F_24 ( V_8 , type , V_63 , V_65 ,
0 , 0 , ( T_4 * ) V_2 ) ;
if ( V_68 )
return - V_7 ;
V_69 = * ( T_4 * ) V_2 ;
V_68 = F_25 ( V_8 , V_69 , V_66 ) ;
if ( V_68 )
goto V_70;
V_68 = F_26 ( V_8 , V_69 , V_67 ) ;
if ( V_68 )
goto V_71;
return 0 ;
V_71:
F_27 ( V_8 , V_69 ) ;
V_70:
F_28 ( V_8 , V_69 ) ;
return V_68 ;
}
int F_29 ( void * V_8 , void * V_2 )
{
T_4 V_69 = ( T_4 ) V_2 ;
if ( V_8 == NULL || V_2 == NULL )
return - V_5 ;
F_30 ( V_8 , V_69 ) ;
F_27 ( V_8 , V_69 ) ;
F_28 ( V_8 , V_69 ) ;
return 0 ;
}
int F_31 ( struct V_35 * V_36 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_72 )
return V_36 -> V_4 -> V_16 -> V_72 ( V_36 ) ;
return 0 ;
}
int F_32 ( struct V_35 * V_36 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_73 )
return V_36 -> V_4 -> V_16 -> V_73 ( V_36 ) ;
return 0 ;
}
int F_33 ( struct V_35 * V_36 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_74 )
return V_36 -> V_4 -> V_16 -> V_74 ( V_36 ) ;
return 0 ;
}
int F_34 ( struct V_35 * V_36 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_75 )
return V_36 -> V_4 -> V_16 -> V_75 ( V_36 ) ;
return 0 ;
}
bool F_35 ( struct V_35 * V_36 )
{
if ( NULL != V_36 -> V_4 -> V_16 -> V_76 )
return V_36 -> V_4 -> V_16 -> V_76 ( V_36 ) ;
return true ;
}
int F_36 ( struct V_35 * V_36 ,
struct V_77 * V_78 )
{
if ( V_36 -> V_4 -> V_16 -> V_79 )
return V_36 -> V_4 -> V_16 -> V_79 (
V_36 , V_78 ) ;
return 0 ;
}
