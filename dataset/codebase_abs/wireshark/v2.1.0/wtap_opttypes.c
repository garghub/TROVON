static void F_1 ( int V_1 , T_1 * V_2 )
{
F_2 ( V_1 < V_3 ) ;
F_2 ( V_4 [ V_1 ] == NULL ) ;
F_2 ( V_2 -> V_5 ) ;
F_2 ( V_2 -> V_6 ) ;
F_2 ( V_2 -> V_7 ) ;
V_4 [ V_1 ] = V_2 ;
}
int F_3 ( const char * V_5 , const char * V_6 , T_2 V_7 ,
T_3 V_8 , T_4 V_9 )
{
int V_1 ;
F_2 ( V_5 ) ;
F_2 ( V_6 ) ;
F_2 ( V_7 ) ;
F_2 ( V_10 < V_11 ) ;
V_1 = V_3 + V_10 ;
V_12 [ V_10 ] . V_5 = V_5 ;
V_12 [ V_10 ] . V_6 = V_6 ;
V_12 [ V_10 ] . V_7 = V_7 ;
V_12 [ V_10 ] . V_8 = V_8 ;
V_12 [ V_10 ] . V_9 = V_9 ;
V_4 [ V_1 ] = & V_12 [ V_10 ] ;
V_10 ++ ;
return V_1 ;
}
void * F_4 ( T_5 V_2 )
{
return V_2 -> V_13 ;
}
static T_6 * F_5 ( T_5 V_2 , T_7 V_14 )
{
T_7 V_15 ;
T_6 * V_16 = NULL ;
for ( V_15 = 0 ; V_15 < V_2 -> V_17 -> V_18 ; V_15 ++ )
{
V_16 = F_6 ( V_2 -> V_17 , T_6 * , V_15 ) ;
if ( V_16 -> V_19 -> V_20 == V_14 )
return V_16 ;
}
return NULL ;
}
T_5 F_7 ( int V_1 )
{
T_5 V_2 ;
if ( V_1 >= ( int ) ( V_3 + V_10 ) )
return NULL ;
V_2 = F_8 ( struct V_21 , 1 ) ;
V_2 -> V_19 = V_4 [ V_1 ] ;
V_2 -> V_22 = F_9 ( FALSE , FALSE , sizeof( V_23 * ) ) ;
V_2 -> V_17 = F_9 ( FALSE , FALSE , sizeof( T_6 * ) ) ;
V_2 -> V_19 -> V_7 ( V_2 ) ;
return V_2 ;
}
static void F_10 ( T_5 V_2 )
{
T_7 V_15 ;
T_6 * V_16 = NULL ;
for ( V_15 = 0 ; V_15 < V_2 -> V_17 -> V_18 ; V_15 ++ ) {
V_16 = F_6 ( V_2 -> V_17 , T_6 * , V_15 ) ;
switch( V_16 -> V_19 -> type )
{
case V_24 :
F_11 ( V_16 -> V_25 . V_26 ) ;
break;
case V_27 :
V_16 -> V_25 . V_28 . V_29 ( V_16 -> V_25 . V_28 . V_30 ) ;
F_11 ( V_16 -> V_25 . V_28 . V_30 ) ;
V_16 -> V_31 . V_28 . V_29 ( V_16 -> V_31 . V_28 . V_30 ) ;
F_11 ( V_16 -> V_31 . V_28 . V_30 ) ;
break;
default:
break;
}
F_11 ( V_16 ) ;
}
}
void F_12 ( T_5 V_2 )
{
unsigned V_15 ;
if ( V_2 != NULL )
{
if ( V_2 -> V_19 -> V_8 != NULL )
V_2 -> V_19 -> V_8 ( V_2 ) ;
F_11 ( V_2 -> V_13 ) ;
F_10 ( V_2 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_22 -> V_18 ; V_15 ++ )
F_11 ( F_6 ( V_2 -> V_22 , V_23 * , V_15 ) ) ;
if ( V_2 -> V_22 != NULL )
F_13 ( V_2 -> V_22 , TRUE ) ;
if ( V_2 -> V_17 != NULL )
F_13 ( V_2 -> V_17 , TRUE ) ;
F_11 ( V_2 ) ;
}
}
void F_14 ( T_8 * V_32 )
{
T_7 V_2 ;
if ( V_32 == NULL )
return;
for ( V_2 = 0 ; V_2 < V_32 -> V_18 ; V_2 ++ ) {
F_12 ( F_6 ( V_32 , T_5 , V_2 ) ) ;
}
F_13 ( V_32 , TRUE ) ;
}
void F_15 ( T_5 V_33 , T_5 V_34 )
{
T_7 V_15 ;
V_23 * V_35 ;
T_6 * V_36 , * V_37 ;
if ( V_33 -> V_19 -> V_9 != NULL )
V_33 -> V_19 -> V_9 ( V_33 , V_34 ) ;
for ( V_15 = 0 ; V_15 < V_34 -> V_17 -> V_18 ; V_15 ++ )
{
V_35 = F_6 ( V_34 -> V_22 , V_23 * , V_15 ) ;
V_37 = F_6 ( V_34 -> V_17 , T_6 * , V_15 ) ;
V_36 = F_5 ( V_33 , V_35 -> V_20 ) ;
if ( V_36 == NULL )
{
T_9 V_38 ;
V_38 . V_5 = V_35 -> V_5 ;
V_38 . V_6 = V_35 -> V_6 ;
V_38 . type = V_35 -> type ;
V_38 . V_25 = V_37 -> V_25 ;
V_38 . V_31 = V_37 -> V_31 ;
F_16 ( V_33 , V_35 -> V_20 , & V_38 ) ;
}
else
{
switch( V_35 -> type )
{
case V_39 :
V_36 -> V_25 . V_40 = V_37 -> V_25 . V_40 ;
break;
case V_41 :
V_36 -> V_25 . V_42 = V_37 -> V_25 . V_42 ;
break;
case V_24 :
F_11 ( V_36 -> V_25 . V_26 ) ;
V_36 -> V_25 . V_26 = F_17 ( V_37 -> V_25 . V_26 ) ;
break;
case V_27 :
V_36 -> V_25 . V_28 . V_29 ( V_36 -> V_25 . V_28 . V_30 ) ;
F_11 ( V_36 -> V_25 . V_28 . V_30 ) ;
V_36 -> V_25 . V_28 . V_30 = F_18 ( V_37 -> V_25 . V_28 . V_30 , V_37 -> V_25 . V_28 . V_43 ) ;
break;
}
}
}
}
void F_19 ( T_5 V_2 , T_10 V_44 , void * V_45 )
{
T_7 V_15 ;
V_23 * V_46 ;
T_6 * V_47 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_17 -> V_18 ; V_15 ++ )
{
V_46 = F_6 ( V_2 -> V_22 , V_23 * , V_15 ) ;
V_47 = F_6 ( V_2 -> V_17 , T_6 * , V_15 ) ;
V_44 ( V_2 , V_46 -> V_20 , V_47 -> V_19 -> type , & V_47 -> V_25 , V_45 ) ;
}
}
T_11 F_16 ( T_5 V_2 , T_7 V_14 , T_9 * V_25 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
V_23 * V_49 ;
if ( V_48 != NULL )
return V_50 ;
V_48 = F_20 ( T_6 , 1 ) ;
V_49 = F_8 ( V_23 , 1 ) ;
V_49 -> V_5 = V_25 -> V_5 ;
V_49 -> V_6 = V_25 -> V_6 ;
V_49 -> V_20 = V_14 ;
V_49 -> type = V_25 -> type ;
V_48 -> V_19 = V_49 ;
switch( V_25 -> type )
{
case V_39 :
V_48 -> V_25 . V_40 = V_25 -> V_25 . V_40 ;
V_48 -> V_31 . V_40 = V_25 -> V_31 . V_40 ;
break;
case V_41 :
V_48 -> V_25 . V_42 = V_25 -> V_25 . V_42 ;
V_48 -> V_31 . V_42 = V_25 -> V_31 . V_42 ;
break;
case V_24 :
V_48 -> V_25 . V_26 = F_17 ( V_25 -> V_25 . V_26 ) ;
V_48 -> V_31 . V_26 = V_25 -> V_31 . V_26 ;
break;
case V_27 :
V_48 -> V_25 . V_28 . V_43 = V_25 -> V_25 . V_28 . V_43 ;
V_48 -> V_25 . V_28 . V_30 = F_18 ( V_25 -> V_25 . V_28 . V_30 , V_25 -> V_25 . V_28 . V_43 ) ;
V_48 -> V_25 . V_28 . V_29 = V_25 -> V_25 . V_28 . V_29 ;
V_48 -> V_31 . V_28 . V_43 = V_25 -> V_31 . V_28 . V_43 ;
V_48 -> V_31 . V_28 . V_30 = F_18 ( V_25 -> V_31 . V_28 . V_30 , V_25 -> V_31 . V_28 . V_43 ) ;
V_48 -> V_31 . V_28 . V_29 = V_25 -> V_31 . V_28 . V_29 ;
break;
}
F_21 ( V_2 -> V_22 , V_49 ) ;
F_21 ( V_2 -> V_17 , V_48 ) ;
return V_51 ;
}
T_11 F_22 ( T_5 V_2 , T_7 V_14 , char * V_47 , T_12 V_52 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_24 )
return V_54 ;
F_11 ( V_48 -> V_25 . V_26 ) ;
V_48 -> V_25 . V_26 = F_23 ( V_47 , V_52 ) ;
return V_51 ;
}
T_11 F_24 ( T_5 V_2 , T_7 V_14 , const char * V_55 , ... )
{
T_13 V_56 ;
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_24 )
return V_54 ;
F_11 ( V_48 -> V_25 . V_26 ) ;
va_start ( V_56 , V_55 ) ;
V_48 -> V_25 . V_26 = F_25 ( V_55 , V_56 ) ;
va_end ( V_56 ) ;
return V_51 ;
}
T_11 F_26 ( T_5 V_2 , T_7 V_14 , char * * V_47 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_24 )
return V_54 ;
* V_47 = V_48 -> V_25 . V_26 ;
return V_51 ;
}
T_11 F_27 ( T_5 V_2 , T_7 V_14 , T_8 * * V_47 )
{
T_7 V_57 ;
T_7 V_15 ;
T_6 * V_48 ;
T_8 * V_58 ;
V_57 = 0 ;
for ( V_15 = 0 ; V_15 < V_2 -> V_17 -> V_18 ; V_15 ++ )
{
V_48 = F_6 ( V_2 -> V_17 , T_6 * , V_15 ) ;
if ( V_48 -> V_19 -> V_20 == V_14 ) {
if ( V_48 -> V_19 -> type != V_24 )
return V_54 ;
V_57 ++ ;
}
}
V_58 = F_28 ( FALSE , FALSE , sizeof ( char * ) , V_57 ) ;
for ( V_15 = 0 ; V_15 < V_2 -> V_17 -> V_18 ; V_15 ++ )
{
V_48 = F_6 ( V_2 -> V_17 , T_6 * , V_15 ) ;
if ( V_48 -> V_19 -> V_20 == V_14 )
F_21 ( V_58 , V_48 -> V_25 . V_26 ) ;
}
* V_47 = V_58 ;
return V_51 ;
}
T_11 F_29 ( T_5 V_2 , T_7 V_14 , T_14 V_47 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_41 )
return V_54 ;
V_48 -> V_25 . V_42 = V_47 ;
return V_51 ;
}
T_11 F_30 ( T_5 V_2 , T_7 V_14 , T_14 * V_47 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_41 )
return V_54 ;
* V_47 = V_48 -> V_25 . V_42 ;
return V_51 ;
}
T_11 F_31 ( T_5 V_2 , T_7 V_14 , T_15 V_47 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_39 )
return V_54 ;
V_48 -> V_25 . V_40 = V_47 ;
return V_51 ;
}
T_11 F_32 ( T_5 V_2 , T_7 V_14 , T_15 * V_47 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_39 )
return V_54 ;
* V_47 = V_48 -> V_25 . V_40 ;
return V_51 ;
}
T_11 F_33 ( T_5 V_2 , T_7 V_14 , void * V_47 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
void * V_59 ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_27 )
return V_54 ;
V_59 = V_48 -> V_25 . V_28 . V_30 ;
V_48 -> V_25 . V_28 . V_30 = F_18 ( V_47 , V_48 -> V_25 . V_28 . V_43 ) ;
F_11 ( V_59 ) ;
return V_51 ;
}
T_11 F_34 ( T_5 V_2 , T_7 V_14 , void * * V_47 )
{
T_6 * V_48 = F_5 ( V_2 , V_14 ) ;
if ( V_48 == NULL )
return V_53 ;
if ( V_48 -> V_19 -> type != V_27 )
return V_54 ;
* V_47 = V_48 -> V_25 . V_28 . V_30 ;
return V_51 ;
}
static void F_35 ( T_5 V_2 )
{
static T_9 V_60 = { L_1 , L_2 , V_24 , { 0 } , { 0 } } ;
static T_9 V_61 = { L_3 , L_4 , V_24 , { 0 } , { 0 } } ;
static T_9 V_62 = { L_5 , L_6 , V_24 , { 0 } , { 0 } } ;
static T_9 V_63 = { L_7 , L_8 , V_24 , { 0 } , { 0 } } ;
T_16 * V_64 = F_8 ( T_16 , 1 ) ;
V_60 . V_25 . V_26 = NULL ;
V_60 . V_31 . V_26 = NULL ;
V_61 . V_25 . V_26 = NULL ;
V_61 . V_31 . V_26 = NULL ;
V_62 . V_25 . V_26 = NULL ;
V_62 . V_31 . V_26 = NULL ;
V_63 . V_25 . V_26 = NULL ;
V_63 . V_31 . V_26 = NULL ;
V_64 -> V_65 = - 1 ;
V_2 -> V_13 = V_64 ;
F_16 ( V_2 , V_66 , & V_60 ) ;
F_16 ( V_2 , V_67 , & V_61 ) ;
F_16 ( V_2 , V_68 , & V_62 ) ;
F_16 ( V_2 , V_69 , & V_63 ) ;
}
static void F_36 ( T_5 V_33 , T_5 V_34 )
{
memcpy ( V_33 -> V_13 , V_34 -> V_13 , sizeof( T_16 ) ) ;
}
static void F_37 ( T_5 V_2 )
{
static T_9 V_60 = { L_1 , L_2 , V_24 , { 0 } , { 0 } } ;
V_60 . V_25 . V_26 = NULL ;
V_60 . V_31 . V_26 = NULL ;
V_2 -> V_13 = NULL ;
F_16 ( V_2 , V_66 , & V_60 ) ;
}
static void F_38 ( T_5 V_2 )
{
static T_9 V_60 = { L_1 , L_2 , V_24 , { 0 } , { 0 } } ;
static T_9 V_70 = { L_9 , L_10 , V_41 , { 0 } , { 0 } } ;
static T_9 V_71 = { L_11 , L_12 , V_41 , { 0 } , { 0 } } ;
static T_9 V_72 = { L_13 , L_14 , V_41 , { 0 } , { 0 } } ;
static T_9 V_73 = { L_15 , L_16 , V_41 , { 0 } , { 0 } } ;
static T_9 V_74 = { L_17 , L_18 , V_41 , { 0 } , { 0 } } ;
static T_9 V_75 = { L_19 , L_20 , V_41 , { 0 } , { 0 } } ;
static T_9 V_76 = { L_21 , L_22 , V_41 , { 0 } , { 0 } } ;
V_2 -> V_13 = F_20 ( V_77 , 1 ) ;
V_60 . V_25 . V_26 = NULL ;
V_60 . V_31 . V_26 = NULL ;
V_70 . V_25 . V_42 = 0 ;
V_70 . V_31 . V_42 = 0 ;
V_71 . V_25 . V_42 = 0 ;
V_71 . V_31 . V_42 = 0 ;
V_72 . V_25 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_72 . V_31 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_73 . V_25 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_73 . V_31 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_74 . V_25 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_74 . V_31 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_75 . V_25 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_75 . V_31 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_76 . V_25 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_76 . V_31 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
F_16 ( V_2 , V_66 , & V_60 ) ;
F_16 ( V_2 , V_78 , & V_70 ) ;
F_16 ( V_2 , V_79 , & V_71 ) ;
F_16 ( V_2 , V_80 , & V_72 ) ;
F_16 ( V_2 , V_81 , & V_73 ) ;
F_16 ( V_2 , V_82 , & V_74 ) ;
F_16 ( V_2 , V_83 , & V_75 ) ;
F_16 ( V_2 , V_84 , & V_76 ) ;
}
static void F_40 ( T_5 V_33 , T_5 V_34 )
{
memcpy ( V_33 -> V_13 , V_34 -> V_13 , sizeof( V_77 ) ) ;
}
static void F_41 ( void * V_30 )
{
T_17 * V_85 = ( T_17 * ) V_30 ;
F_11 ( V_85 -> V_86 ) ;
F_11 ( V_85 -> V_87 ) ;
}
static void F_42 ( T_5 V_2 )
{
static T_9 V_60 = { L_1 , L_2 , V_24 , { 0 } , { 0 } } ;
static T_9 V_88 = { L_23 , L_24 , V_24 , { 0 } , { 0 } } ;
static T_9 V_89 = { L_25 , L_26 , V_24 , { 0 } , { 0 } } ;
static T_9 V_90 = { L_27 , L_28 , V_41 , { 0 } , { 0 } } ;
static T_9 V_91 = { L_29 , L_30 , V_39 , { 0 } , { 0 } } ;
static T_9 V_92 = { L_31 , L_32 , V_27 , { 0 } , { 0 } } ;
static T_9 V_62 = { L_5 , L_33 , V_24 , { 0 } , { 0 } } ;
static T_9 V_93 = { L_34 , L_35 , V_39 , { 0 } , { 0 } } ;
T_17 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_2 -> V_13 = F_20 ( V_95 , 1 ) ;
V_60 . V_25 . V_26 = NULL ;
V_60 . V_31 . V_26 = NULL ;
V_88 . V_25 . V_26 = NULL ;
V_88 . V_31 . V_26 = NULL ;
V_89 . V_25 . V_26 = NULL ;
V_89 . V_31 . V_26 = NULL ;
V_90 . V_25 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_90 . V_31 . V_42 = F_39 ( 0xFFFFFFFFFFFFFFFF ) ;
V_91 . V_25 . V_40 = 6 ;
V_91 . V_31 . V_40 = 6 ;
V_92 . V_25 . V_28 . V_43 = sizeof( T_17 ) ;
V_92 . V_25 . V_28 . V_30 = & V_94 ;
V_92 . V_25 . V_28 . V_29 = F_41 ;
V_92 . V_31 . V_28 . V_43 = sizeof( T_17 ) ;
V_92 . V_31 . V_28 . V_30 = & V_94 ;
V_92 . V_31 . V_28 . V_29 = F_41 ;
V_62 . V_25 . V_26 = NULL ;
V_62 . V_31 . V_26 = NULL ;
V_93 . V_25 . V_40 = - 1 ;
V_93 . V_31 . V_40 = - 1 ;
F_16 ( V_2 , V_66 , & V_60 ) ;
F_16 ( V_2 , V_96 , & V_88 ) ;
F_16 ( V_2 , V_97 , & V_89 ) ;
F_16 ( V_2 , V_98 , & V_90 ) ;
F_16 ( V_2 , V_99 , & V_91 ) ;
F_16 ( V_2 , V_100 , & V_92 ) ;
F_16 ( V_2 , V_101 , & V_62 ) ;
F_16 ( V_2 , V_102 , & V_93 ) ;
}
static void F_43 ( T_5 V_2 )
{
T_7 V_103 ;
T_5 V_104 ;
V_95 * V_105 = ( V_95 * ) V_2 -> V_13 ;
for( V_103 = 0 ; V_103 < V_105 -> V_106 ; V_103 ++ ) {
V_104 = F_6 ( V_105 -> V_107 , T_5 , V_103 ) ;
F_12 ( V_104 ) ;
}
if ( V_105 -> V_107 )
F_13 ( V_105 -> V_107 , TRUE ) ;
}
static void F_44 ( T_5 V_33 , T_5 V_34 )
{
T_7 V_103 ;
T_5 V_108 , V_109 ;
V_95 * V_110 = ( V_95 * ) V_34 -> V_13 ,
* V_111 = ( V_95 * ) V_33 -> V_13 ;
if ( V_111 -> V_106 != 0 )
F_13 ( V_111 -> V_107 , TRUE ) ;
memcpy ( V_111 , V_110 , sizeof( V_95 ) ) ;
if ( V_110 -> V_106 != 0 )
{
V_111 -> V_107 = F_9 ( FALSE , FALSE , sizeof( T_5 ) ) ;
for ( V_103 = 0 ; V_103 < V_110 -> V_106 ; V_103 ++ )
{
V_108 = F_6 ( V_110 -> V_107 , T_5 , V_103 ) ;
V_109 = F_7 ( V_112 ) ;
F_15 ( V_109 , V_108 ) ;
V_111 -> V_107 = F_21 ( V_111 -> V_107 , V_109 ) ;
}
}
}
void F_45 ( void )
{
static T_1 V_113 = {
L_36 ,
L_37 ,
F_35 ,
NULL ,
F_36 ,
} ;
static T_1 V_114 = {
L_38 ,
L_39 ,
F_37 ,
NULL ,
NULL ,
} ;
static T_1 V_115 = {
L_40 ,
L_41 ,
F_38 ,
NULL ,
F_40 ,
} ;
static T_1 V_116 = {
L_42 ,
L_43 ,
F_42 ,
F_43 ,
F_44 ,
} ;
memset ( V_4 , 0 , V_117 * sizeof( T_1 * ) ) ;
V_10 = 0 ;
F_1 ( V_118 , & V_113 ) ;
F_1 ( V_119 , & V_114 ) ;
F_1 ( V_112 , & V_115 ) ;
F_1 ( V_120 , & V_116 ) ;
}
