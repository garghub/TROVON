T_1 F_1 ( T_2 * V_1 , T_3 V_2 )
{
T_1 V_3 ;
if ( V_2 )
{
F_2 ( V_1 -> V_4 , V_5 , L_1 ) ;
}
if ( V_1 == NULL )
{
V_3 = V_6 ;
}
else
{
V_1 -> V_7 = V_2 ? 1 : 0 ;
V_3 = V_8 ;
}
return V_3 ;
}
T_1 F_3 ( T_2 * V_1 )
{
T_1 V_3 = V_8 ;
if ( V_1 == NULL )
{
V_3 = V_6 ;
}
else
{
if ( V_1 -> V_7 == 1 )
{
V_1 -> V_7 = 0 ;
V_3 = F_4 ( V_1 , NULL ) ;
}
}
return V_3 ;
}
T_1 F_4 ( T_2 * V_1 , struct V_9 * V_10 )
{
T_1 V_3 = V_8 ;
static T_4 V_11 = 1 ;
T_5 V_12 ;
if ( V_1 -> V_13 == NULL )
{
V_3 = V_8 ;
goto V_14;
}
if ( V_1 -> V_15 == NULL )
{
V_3 = V_6 ;
goto V_14;
}
V_12 = F_5 ( NULL ) ;
F_6 ( V_1 -> V_4 , L_2 , V_12 ) ;
V_3 = F_7 ( V_1 , V_16 ) ;
if ( V_3 != V_8 )
{
F_8 ( V_1 -> V_4 , L_3 ) ;
goto V_14;
}
F_9 ( 20 ) ;
F_2 ( V_1 -> V_4 , V_17 , L_4 ) ;
V_3 = F_10 ( V_1 , V_18 ) ;
if ( V_3 != V_8 )
{
F_8 ( V_1 -> V_4 , L_5 ) ;
goto V_14;
}
V_3 = F_11 ( V_1 , V_1 -> V_13 ) ;
if ( V_3 == V_8 )
{
V_1 -> V_13 -> V_19 = ( V_10 ? 1 : 0 ) ;
V_1 -> V_13 -> V_20 = V_12 ;
V_1 -> V_13 -> V_21 = V_11 ++ ;
V_1 -> V_22 = V_1 -> V_13 ;
V_1 -> V_13 = V_1 -> V_13 -> V_23 ;
if ( V_11 == 0 )
{
V_11 = 1 ;
}
F_2 ( V_1 -> V_4 , V_24 ,
L_6 ,
V_10 ,
V_1 -> V_22 -> V_21 ,
V_1 -> V_22 , V_1 -> V_13 ) ;
}
F_2 ( V_1 -> V_4 , V_17 , L_7 ) ;
V_3 = F_12 ( V_1 , V_18 ) ;
if ( V_3 != V_8 )
{
F_8 ( V_1 -> V_4 , L_8 ) ;
goto V_14;
}
V_14:
return V_3 ;
}
static T_6 F_13 ( const T_7 * V_25 ,
const T_8 V_26 ,
const T_4 V_27 )
{
T_6 V_3 = - 1 ;
T_4 V_28 ;
T_5 V_29 ;
T_6 V_30 ;
const struct V_31 * V_32 = & V_33 [ 0 ] ;
for ( V_30 = 0 ; V_30 < V_34 ; V_30 ++ , V_32 ++ )
{
if ( V_26 == V_32 -> V_26 )
{
V_29 = V_32 -> V_35 + V_32 -> V_36 ;
if ( V_27 < V_29 &&
V_27 >= V_32 -> V_35 )
{
V_28 = V_27 - V_32 -> V_35 ;
V_3 = ( T_6 ) * ( V_25 -> V_37 [ V_30 ] + V_28 ) ;
F_2 ( NULL , V_38 ,
L_9 ,
V_26 , V_27 , V_3 ,
V_30 , V_32 -> V_35 , V_29 - 1 ) ;
break;
}
}
}
return V_3 ;
}
T_1 F_14 ( T_2 * V_1 , struct V_9 * V_10 )
{
T_1 V_3 ;
T_6 V_30 = 0 ;
T_7 * V_39 = NULL ;
if ( V_10 == NULL || V_1 == NULL )
{
V_3 = V_6 ;
goto V_14;
}
V_10 -> V_40 = - 1 ;
if ( V_1 -> V_41 == NULL )
{
F_2 ( V_1 -> V_4 , V_5 , L_10 ) ;
V_3 = V_42 ;
goto V_14;
}
if ( V_1 -> V_22 == NULL )
{
F_2 ( V_1 -> V_4 , V_17 , L_11 ) ;
V_3 = V_42 ;
goto V_14;
}
switch ( V_10 -> V_43 )
{
case 0 :
V_39 = V_1 -> V_22 ;
break;
case - 1 :
for ( V_39 = V_1 -> V_22 -> V_23 ;
( V_39 -> V_21 == 0 ) && ( V_39 != V_1 -> V_22 ) ;
V_39 = V_1 -> V_22 -> V_23 )
{
}
break;
default:
for ( V_30 = 0 , V_39 = V_1 -> V_22 ;
V_30 < V_10 -> V_43 ;
V_30 ++ , V_39 = V_39 -> V_44 )
{
F_2 ( V_1 -> V_4 , V_38 ,
L_12 ,
V_30 , V_39 -> V_21 , V_39 , V_39 -> V_44 ,
V_39 -> V_23 , V_1 -> V_22 , V_1 -> V_41 ) ;
if ( V_39 -> V_44 == V_1 -> V_22 )
{
if ( V_30 != V_10 -> V_43 )
{
F_2 ( V_1 -> V_4 , V_38 ,
L_13 , V_10 -> V_43 , V_30 ) ;
V_3 = V_42 ;
goto V_14;
}
break;
}
}
break;
}
if ( V_39 -> V_21 == 0 )
{
F_2 ( V_1 -> V_4 , V_17 , L_14 , V_10 -> V_43 ) ;
V_3 = V_42 ;
goto V_14;
}
F_2 ( V_1 -> V_4 , V_38 , L_15 ,
V_10 -> V_43 , V_39 -> V_21 , V_30 ) ;
V_10 -> V_40 = F_13 ( V_39 , V_10 -> V_26 , ( T_4 ) V_10 -> V_35 ) ;
if ( V_10 -> V_40 < 0 )
{
V_3 = V_45 ;
F_2 ( V_1 -> V_4 , V_17 ,
L_16 ,
V_10 -> V_26 , V_10 -> V_35 , V_10 -> V_43 ) ;
}
else
{
V_3 = V_8 ;
}
V_10 -> V_46 = V_39 -> V_46 ;
V_10 -> V_47 = V_39 -> V_47 ;
V_10 -> V_20 = V_39 -> V_20 ;
V_10 -> V_19 = V_39 -> V_19 ;
V_10 -> V_48 = V_39 -> V_21 ;
V_14:
return V_3 ;
}
static T_1 F_15 ( T_2 * V_1 , T_4 * V_49 , const struct V_31 * V_32 )
{
T_1 V_3 ;
if ( V_49 == NULL || V_32 == NULL )
{
V_3 = V_6 ;
goto V_14;
}
if ( V_32 -> V_50 != V_51 )
{
if ( V_32 -> V_50 != V_52 && V_32 -> V_50 != V_53 )
{
V_3 = V_6 ;
goto V_14;
}
V_3 = F_16 ( V_1 , V_32 -> V_50 ) ;
if ( V_3 != V_8 )
{
goto V_14;
}
}
F_2 ( V_1 -> V_4 , V_17 ,
L_17 ,
V_32 -> V_26 , V_32 -> V_35 , V_32 -> V_36 , V_32 -> V_54 , V_32 -> V_50 ) ;
V_3 = F_17 ( V_1 , V_32 -> V_54 , V_49 , ( T_4 ) ( V_32 -> V_36 * 2 ) ) ;
if ( V_3 == V_55 )
{
goto V_14;
}
if ( V_3 != V_8 )
{
F_8 ( V_1 -> V_4 , L_18 ) ;
goto V_14;
}
V_14:
return V_3 ;
}
static T_1 F_18 ( T_2 * V_1 , T_7 * V_41 )
{
T_1 V_3 = V_8 ;
T_6 V_30 ;
for ( V_30 = 0 ;
( V_30 < V_34 ) && ( V_3 == 0 ) ;
V_30 ++ )
{
V_3 = F_15 ( V_1 , V_41 -> V_37 [ V_30 ] , & V_33 [ V_30 ] ) ;
}
return V_3 ;
}
static T_1 F_11 ( T_2 * V_1 , T_7 * V_41 )
{
T_4 V_56 ;
T_1 V_3 ;
T_5 V_57 ;
if ( V_41 == NULL )
{
V_3 = V_6 ;
goto V_14;
}
F_2 ( V_1 -> V_4 , V_17 , L_19 ) ;
V_57 = 2 * F_19 ( V_1 -> V_15 ) ;
if ( V_57 != 0 )
{
V_3 = F_20 ( V_1 , V_57 , & V_56 ) ;
if ( V_3 == V_55 )
{
goto V_14;
}
if ( V_3 != V_8 )
{
F_8 ( V_1 -> V_4 , L_20 ) ;
goto V_14;
}
}
V_41 -> V_46 = V_56 ;
V_41 -> V_47 = V_1 -> V_58 ;
F_2 ( V_1 -> V_4 , V_17 , L_21 ,
V_41 -> V_46 , V_41 -> V_47 ) ;
V_3 = F_18 ( V_1 , V_41 ) ;
if ( V_3 == V_55 )
{
goto V_14;
}
if ( V_3 != V_8 )
{
F_8 ( V_1 -> V_4 , L_22 ) ;
goto V_14;
}
V_14:
return V_3 ;
}
static
T_7 * F_21 ( void * V_4 , T_7 * V_59 )
{
T_7 * V_60 = NULL ;
T_4 * V_61 = NULL ;
T_6 V_30 ;
T_5 V_62 ;
V_60 = F_22 ( sizeof( T_7 ) , V_63 ) ;
if ( V_60 == NULL )
{
return NULL ;
}
for ( V_30 = 0 ; V_30 < V_34 ; V_30 ++ )
{
V_62 = sizeof( T_4 ) * V_33 [ V_30 ] . V_36 ;
V_61 = F_22 ( V_62 , V_63 ) ;
V_60 -> V_37 [ V_30 ] = V_61 ;
if ( V_61 == NULL )
{
F_8 ( V_4 , L_23 ,
V_30 , V_33 [ V_30 ] . V_36 ) ;
break;
}
}
if ( V_61 == NULL )
{
for ( V_30 = 0 ; V_60 -> V_37 [ V_30 ] != NULL ; V_30 ++ )
{
F_23 ( V_60 -> V_37 [ V_30 ] ) ;
V_60 -> V_37 [ V_30 ] = NULL ;
}
}
V_60 -> V_44 = V_59 ;
if ( V_59 )
{
V_59 -> V_23 = V_60 ;
}
V_60 -> V_23 = NULL ;
return V_60 ;
}
T_1 F_24 ( T_2 * V_1 , T_4 V_64 )
{
#ifndef F_25
void * V_4 = V_1 -> V_4 ;
T_7 * V_44 = NULL ;
T_7 * V_60 = NULL ;
T_5 V_30 = 0 ;
#endif
V_1 -> V_7 = 0 ;
V_1 -> V_13 = NULL ;
V_1 -> V_22 = NULL ;
V_1 -> V_41 = NULL ;
#ifndef F_25
F_2 ( V_4 , V_65 ,
L_24 , V_64 ) ;
if ( V_64 == 0 )
{
goto V_14;
}
V_1 -> V_41 = F_21 ( V_4 , NULL ) ;
if ( V_1 -> V_41 == NULL )
{
goto V_66;
}
V_44 = V_1 -> V_41 ;
V_60 = V_1 -> V_41 ;
for ( V_30 = 1 ; V_30 < V_64 ; V_30 ++ )
{
V_60 = F_21 ( V_4 , V_44 ) ;
if ( V_60 == NULL )
{
goto V_66;
}
V_44 = V_60 ;
}
V_1 -> V_41 -> V_44 = V_60 ;
V_60 -> V_23 = V_1 -> V_41 ;
V_1 -> V_13 = V_1 -> V_41 ;
V_1 -> V_22 = NULL ;
F_2 ( V_4 , V_5 , L_25 , V_30 ) ;
V_14:
#endif
return V_8 ;
#ifndef F_25
V_66:
F_8 ( V_4 , L_26 , V_30 ) ;
F_26 ( V_1 ) ;
return V_67 ;
#endif
}
void F_26 ( T_2 * V_1 )
{
void * V_4 = V_1 -> V_4 ;
T_7 * V_68 , * V_69 ;
T_9 V_30 = 0 ;
T_9 V_70 ;
F_2 ( V_4 , V_5 , L_27 ) ;
if ( V_1 -> V_41 == NULL )
{
return;
}
V_68 = V_1 -> V_41 ;
do
{
for ( V_70 = 0 ; V_70 < V_34 ; V_70 ++ )
{
F_23 ( V_68 -> V_37 [ V_70 ] ) ;
V_68 -> V_37 [ V_70 ] = NULL ;
}
V_69 = V_68 ;
V_68 = V_68 -> V_23 ;
F_23 ( V_69 ) ;
V_30 ++ ;
} while ( ( V_68 != NULL ) && ( V_68 != V_1 -> V_41 ) );
F_2 ( V_4 , V_24 , L_28 , V_30 ) ;
V_1 -> V_41 = NULL ;
V_1 -> V_13 = NULL ;
V_1 -> V_22 = NULL ;
}
