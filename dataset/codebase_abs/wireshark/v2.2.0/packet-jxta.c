static const char * F_1 ( T_1 * V_1 , T_2 V_2 )
{
if ( ( V_2 == V_3 ) && ( V_1 -> V_4 . type == V_5 ) )
return L_1 ;
if ( ( V_2 == V_6 ) && ( V_1 -> V_7 . type == V_5 ) )
return L_2 ;
if ( ( V_2 == V_8 ) && ( V_1 -> V_4 . type == V_5 ) )
return L_3 ;
return V_9 ;
}
static int
F_2 ( void * V_10 , T_3 * T_4 V_11 , T_5 * T_6 V_11 , const void * V_12 )
{
T_7 * V_13 = ( T_7 * ) V_10 ;
const T_8 * V_14 = ( const T_8 * ) V_12 ;
F_3 ( V_13 , & V_14 -> V_4 , & V_14 -> V_15 ,
0 , 0 , 1 , V_14 -> V_16 , NULL , NULL , & V_17 , V_18 ) ;
return 1 ;
}
static const char * F_4 ( T_9 * V_19 , T_2 V_2 )
{
if ( ( V_2 == V_8 ) && ( V_19 -> V_20 . type == V_5 ) )
return L_3 ;
return V_9 ;
}
static int
F_5 ( void * V_21 , T_3 * T_4 V_11 , T_5 * T_6 V_11 , const void * V_12 )
{
T_7 * V_13 = ( T_7 * ) V_21 ;
const T_8 * V_14 = ( const T_8 * ) V_12 ;
F_6 ( V_13 , & V_14 -> V_4 , 0 , TRUE , 1 , V_14 -> V_16 , & V_22 , V_18 ) ;
F_6 ( V_13 , & V_14 -> V_15 , 0 , FALSE , 1 , V_14 -> V_16 , & V_22 , V_18 ) ;
return 1 ;
}
static int F_7 ( const T_10 * V_23 , T_11 * V_24 , int V_25 )
{
int V_26 = V_23 -> V_27 < ( V_25 - 1 ) ? V_23 -> V_27 : ( V_25 - 1 ) ;
memcpy ( V_24 , V_23 -> V_28 , V_26 ) ;
V_24 [ V_26 ] = '\0' ;
return V_26 + 1 ;
}
static int F_8 ( const T_10 * V_23 )
{
return V_23 -> V_27 + 1 ;
}
static const char * F_9 ( const T_10 * V_23 V_11 , T_12 V_29 )
{
if ( V_29 )
return L_4 ;
return L_5 ;
}
static T_12 F_10 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , void * V_28 V_11 )
{
int V_32 ;
T_15 V_33 ;
int V_34 ;
if ( F_11 ( V_30 , 0 , V_35 , sizeof ( V_35 ) ) != 0 ) {
return FALSE ;
}
V_32 = T_4 -> V_36 ;
V_33 = T_4 -> V_37 ;
V_34 = F_12 ( V_30 , T_4 , V_31 , NULL ) ;
if ( V_34 < 0 ) {
T_4 -> V_36 = V_32 ;
T_4 -> V_37 = V_33 ;
return FALSE ;
} else if ( V_34 == 0 ) {
T_4 -> V_36 = V_32 ;
T_4 -> V_37 = V_33 ;
return FALSE ;
} else {
return TRUE ;
}
}
static T_12 F_13 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , void * V_28 V_11 )
{
int V_32 ;
T_15 V_33 ;
int V_34 ;
V_32 = T_4 -> V_36 ;
V_33 = T_4 -> V_37 ;
V_34 = F_14 ( V_30 , T_4 , V_31 , NULL ) ;
if ( V_34 < 0 ) {
T_4 -> V_36 = V_32 ;
T_4 -> V_37 = V_33 ;
return FALSE ;
} else if ( V_34 == 0 ) {
T_4 -> V_36 = V_32 ;
T_4 -> V_37 = V_33 ;
return FALSE ;
} else {
return TRUE ;
}
}
static T_12 F_15 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , void * V_28 V_11 )
{
int V_32 ;
T_15 V_33 ;
int V_34 ;
V_32 = T_4 -> V_36 ;
V_33 = T_4 -> V_37 ;
V_34 = F_14 ( V_30 , T_4 , V_31 , NULL ) ;
if ( V_34 < 0 ) {
T_4 -> V_36 = V_32 ;
T_4 -> V_37 = V_33 ;
return FALSE ;
} else if ( V_34 == 0 ) {
T_4 -> V_36 = V_32 ;
T_4 -> V_37 = V_33 ;
return FALSE ;
} else {
return TRUE ;
}
}
static int F_12 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , void * V_28 V_11 )
{
T_16 V_38 = 0 ;
T_16 V_39 ;
T_17 V_40 = 0 ;
T_18 * V_41 = F_16 ( T_4 ) ;
F_17 ( F_18 ( L_6 ) ) ;
F_19 ( V_41 , F_18 ( L_6 ) ) ;
while ( TRUE ) {
T_13 * V_42 ;
T_17 V_43 = 0 ;
T_19 V_44 = - 1 ;
T_11 * V_45 = NULL ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( V_35 ) ) {
V_40 = ( T_17 ) ( sizeof( V_35 ) - V_39 ) ;
break;
}
if ( F_21 ( V_30 , V_38 , V_35 , sizeof( V_35 ) ) != 0 ) {
return 0 ;
}
V_38 += ( int ) sizeof( V_35 ) ;
V_42 = F_22 ( V_30 , V_38 ) ;
V_43 = F_23 ( V_42 , T_4 , NULL , & V_44 , & V_45 ) ;
if ( ( 0 == V_43 ) || ( NULL == V_45 ) || ( V_44 <= 0 ) || ( V_44 > V_46 ) ) {
return 0 ;
}
if ( V_43 < 0 ) {
V_40 = - V_43 ;
break;
}
V_38 += V_43 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_44 ) {
V_40 = ( T_17 ) ( V_44 - V_39 ) ;
break;
}
V_38 += ( T_16 ) V_44 ;
break;
}
if ( ( V_40 > 0 ) && V_47 && T_4 -> V_48 ) {
T_4 -> V_36 = 0 ;
T_4 -> V_37 = V_40 ;
return - V_40 ;
}
F_24 ( T_4 -> V_49 , V_50 , L_7 ) ;
{
T_16 V_51 = 0 ;
T_20 * V_52 =
F_25 ( V_31 , V_53 , V_30 , V_51 , - 1 , L_7 ) ;
T_14 * V_54 = F_26 ( V_52 , V_55 ) ;
T_20 * V_56 =
F_27 ( V_54 , V_57 , V_30 , V_51 , - 1 , L_8 ) ;
T_14 * V_58 = F_26 ( V_56 , V_59 ) ;
T_13 * V_42 ;
T_19 V_44 = - 1 ;
T_11 * V_45 = NULL ;
T_13 * V_60 ;
F_28 ( V_58 , V_61 , V_30 , V_51 , ( int ) sizeof( V_35 ) , V_62 | V_63 ) ;
V_51 += ( int ) sizeof( V_35 ) ;
V_42 = F_22 ( V_30 , V_51 ) ;
V_51 += F_23 ( V_42 , T_4 , V_54 , & V_44 , & V_45 ) ;
V_60 = F_29 ( V_30 , V_51 , ( T_17 ) V_44 ) ;
V_51 += F_30 ( V_45 , V_60 , T_4 , V_31 ) ;
F_31 ( V_56 , V_30 , V_51 ) ;
F_17 ( V_38 == V_51 ) ;
}
return V_38 ;
}
static int F_14 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , void * V_28 V_11 )
{
T_16 V_38 = 0 ;
T_16 V_39 = F_20 ( V_30 , V_38 ) ;
T_17 V_43 = 0 ;
T_17 V_40 = 0 ;
T_21 * V_64 = NULL ;
T_20 * V_52 = NULL ;
T_14 * V_54 = NULL ;
if ( V_39 < sizeof( V_65 ) ) {
V_40 = ( T_17 ) ( sizeof( V_65 ) - V_39 ) ;
goto V_66;
}
if ( 0 == F_21 ( V_30 , 0 , V_65 , sizeof( V_65 ) ) ) {
T_10 * V_67 ;
T_12 V_68 = FALSE ;
V_64 = F_32 ( T_4 ) ;
if ( 0 == V_64 -> V_69 ) {
V_64 -> V_70 = T_4 -> V_71 ;
V_64 -> V_69 = T_4 -> V_72 ;
F_33 ( F_34 () , & V_64 -> V_73 , & T_4 -> V_74 ) ;
V_64 -> V_75 = T_4 -> V_76 ;
V_67 = & V_64 -> V_77 ;
V_68 = TRUE ;
} else {
if ( V_64 -> V_69 >= T_4 -> V_72 ) {
V_64 -> V_78 = V_64 -> V_69 ;
V_64 -> V_79 = V_64 -> V_73 ;
V_64 -> V_80 = V_64 -> V_75 ;
V_64 -> V_81 = V_64 -> V_77 ;
V_64 -> V_69 = T_4 -> V_72 ;
F_33 ( F_34 () , & V_64 -> V_73 , & T_4 -> V_74 ) ;
V_64 -> V_75 = T_4 -> V_76 ;
V_67 = & V_64 -> V_77 ;
V_68 = TRUE ;
} else {
V_64 -> V_70 = T_4 -> V_71 ;
V_64 -> V_78 = T_4 -> V_72 ;
F_33 ( F_34 () , & V_64 -> V_79 , & T_4 -> V_74 ) ;
V_64 -> V_80 = T_4 -> V_76 ;
V_67 = & V_64 -> V_81 ;
V_68 = FALSE ;
}
}
V_43 = F_35 ( V_30 , T_4 , NULL , V_67 , V_68 ) ;
if( V_43 < 0 ) {
V_40 = - V_43 ;
goto V_66;
}
V_52 = F_25 ( V_31 , V_53 , V_30 , V_38 , - 1 , L_7 ) ;
V_54 = F_26 ( V_52 , V_55 ) ;
V_43 = F_35 ( V_30 , T_4 , V_54 , V_67 , V_68 ) ;
} else {
T_22 V_44 = F_36 ( - 1 ) ;
T_11 * V_45 = NULL ;
T_17 V_82 = F_23 ( V_30 , T_4 , NULL , ( T_19 * ) & V_44 , & V_45 ) ;
if ( ( 0 == V_82 ) || ( NULL == V_45 ) || ( V_44 <= 0 ) || ( V_44 > V_46 ) ) {
return 0 ;
}
if ( V_82 < 0 ) {
V_40 = - V_82 ;
goto V_66;
}
V_39 = F_20 ( V_30 , V_38 + V_82 ) ;
if ( V_39 >= V_44 ) {
T_13 * V_60 = F_29 ( V_30 , V_38 + V_82 , ( T_17 ) V_44 ) ;
T_18 * V_83 = NULL ;
V_52 = F_25 ( V_31 , V_53 , V_30 , V_38 , - 1 , L_7 ) ;
V_54 = F_26 ( V_52 , V_55 ) ;
V_82 = F_23 ( V_30 , T_4 , V_54 , & V_44 , & V_45 ) ;
V_64 = F_32 ( T_4 ) ;
V_83 = F_37 ( T_4 , V_64 , TRUE ) ;
if ( NULL != V_83 ) {
if ( F_38 ( & T_4 -> V_74 , & V_64 -> V_73 )
&& V_64 -> V_75 == T_4 -> V_76 ) {
F_39 ( & T_4 -> V_74 , & V_64 -> V_77 ) ;
T_4 -> V_76 = 0 ;
F_39 ( & T_4 -> V_84 , & V_64 -> V_81 ) ;
T_4 -> V_85 = 0 ;
T_4 -> V_71 = V_18 ;
} else if ( F_38 ( & T_4 -> V_74 , & V_64 -> V_79 ) &&
V_64 -> V_80 == T_4 -> V_76 ) {
F_39 ( & T_4 -> V_74 , & V_64 -> V_81 ) ;
T_4 -> V_76 = 0 ;
F_39 ( & T_4 -> V_84 , & V_64 -> V_77 ) ;
T_4 -> V_85 = 0 ;
T_4 -> V_71 = V_18 ;
} else {
}
}
V_43 = V_82 ;
V_43 += F_30 ( V_45 , V_60 , T_4 , V_31 ) ;
} else {
V_40 = ( T_17 ) ( ( T_16 ) V_44 - V_39 ) ;
goto V_66;
}
}
V_38 += V_43 ;
V_66:
if ( ( V_40 > 0 ) && V_47 && T_4 -> V_48 ) {
T_4 -> V_36 = V_38 ;
T_4 -> V_37 = V_40 ;
return - V_40 ;
}
return V_38 ;
}
static T_21 * F_32 ( T_3 * T_4 )
{
T_18 * V_86 =
F_40 ( T_4 -> V_72 , & T_4 -> V_74 , & T_4 -> V_84 , T_4 -> V_71 , T_4 -> V_76 , T_4 -> V_85 , 0 ) ;
T_21 * V_64 ;
if ( V_86 == NULL ) {
V_86 =
F_41 ( T_4 -> V_72 , & T_4 -> V_74 , & T_4 -> V_84 , T_4 -> V_71 , T_4 -> V_76 , T_4 -> V_85 , 0 ) ;
}
F_19 ( V_86 , V_87 ) ;
V_64 = ( T_21 * ) F_42 ( V_86 , V_53 ) ;
if ( NULL == V_64 ) {
V_64 = F_43 ( F_34 () , T_21 ) ;
V_64 -> V_70 = T_4 -> V_71 ;
F_33 ( F_34 () , & V_64 -> V_73 , & T_4 -> V_74 ) ;
V_64 -> V_75 = T_4 -> V_76 ;
V_64 -> V_69 = 0 ;
F_44 ( & V_64 -> V_77 ) ;
F_33 ( F_34 () , & V_64 -> V_79 , & T_4 -> V_84 ) ;
V_64 -> V_80 = T_4 -> V_85 ;
V_64 -> V_78 = 0 ;
F_44 ( & V_64 -> V_81 ) ;
F_45 ( V_86 , V_53 , V_64 ) ;
}
return V_64 ;
}
static T_18 * F_37 ( T_3 * T_4 , T_21 * V_64 , T_12 V_88 )
{
T_18 * V_83 = NULL ;
if ( ( V_89 != V_64 -> V_77 . type ) && ( V_89 != V_64 -> V_81 . type ) ) {
V_83 = F_40 ( T_4 -> V_72 , & V_64 -> V_77 , & V_64 -> V_81 ,
V_18 , 0 , 0 , V_90 ) ;
if ( V_88 && ( NULL == V_83 ) ) {
V_83 = F_41 ( T_4 -> V_72 , & V_64 -> V_77 ,
& V_64 -> V_81 , V_18 , 0 , 0 , V_90 ) ;
F_19 ( V_83 , V_87 ) ;
}
}
return V_83 ;
}
static int F_35 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , T_10 * V_91 , T_12 V_68 )
{
T_16 V_38 = 0 ;
T_17 V_92 ;
T_17 V_93 ;
T_16 V_39 = F_20 ( V_30 , V_38 ) ;
T_11 * * V_94 = NULL ;
if ( V_39 < sizeof( V_65 ) ) {
return ( T_17 ) ( V_39 - sizeof( V_65 ) ) ;
}
if ( 0 != F_21 ( V_30 , 0 , V_65 , sizeof( V_65 ) ) ) {
return 0 ;
}
V_93 = F_46 ( V_30 , V_38 , - 1 , & V_92 , V_47 && T_4 -> V_48 ) ;
if ( - 1 == V_93 ) {
if ( V_39 > 4096 ) {
return 0 ;
} else {
return - V_95 ;
}
}
F_24 ( T_4 -> V_49 , V_50 , L_7 ) ;
F_24 ( T_4 -> V_49 , V_96 , L_9 ) ;
{
T_11 * V_97 = F_47 ( F_48 () , V_30 , V_38 , V_93 , V_62 ) ;
T_11 * * V_98 ;
T_16 V_99 = V_38 ;
T_20 * V_100 = NULL ;
T_14 * V_101 = NULL ;
V_94 = F_49 ( V_97 , L_10 , 255 ) ;
V_98 = V_94 ;
if ( V_31 ) {
V_100 =
F_27 ( V_31 , V_102 , V_30 , V_38 , V_92 ,
L_11 , V_97 ) ;
V_101 = F_26 ( V_100 , V_103 ) ;
}
if ( V_101 ) {
T_20 * V_104 =
F_50 ( V_101 , V_105 , V_30 , 0 , 0 , V_68 ) ;
F_51 ( V_104 ) ;
}
if ( NULL != * V_98 ) {
F_28 ( V_101 , V_106 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
} else {
V_92 = 0 ;
goto V_66;
}
if ( NULL != * V_98 ) {
if ( V_101 ) {
F_28 ( V_101 , V_107 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) ,
V_62 | V_63 ) ;
}
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
} else {
V_92 = 0 ;
goto V_66;
}
if ( NULL != * V_98 ) {
if ( V_101 ) {
F_28 ( V_101 , V_108 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
}
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
} else {
V_92 = 0 ;
goto V_66;
}
if ( NULL != * V_98 ) {
if ( V_101 ) {
F_28 ( V_101 , V_109 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
}
F_52 ( T_4 -> V_49 , V_96 , ( V_68 ? L_12 : L_13 ) ) ;
F_52 ( T_4 -> V_49 , V_96 , * V_98 ) ;
if ( NULL != V_91 ) {
F_53 ( V_91 , V_5 , ( int ) strlen ( * V_98 ) + 1 , F_54 ( F_34 () , * V_98 ) ) ;
}
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
} else {
V_92 = 0 ;
goto V_66;
}
if ( NULL != * V_98 ) {
int V_110 = 0 ;
T_11 * * V_111 = V_98 ;
while( NULL != * V_111 ) {
V_110 ++ ;
V_111 ++ ;
}
if( V_110 < 1 ) {
V_92 = 0 ;
goto V_66;
}
if( ( 2 == V_110 ) && ( 0 == strcmp ( V_112 , V_98 [ V_110 - 1 ] ) ) ) {
if ( V_101 ) {
F_28 ( V_101 , V_113 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
}
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
if ( V_101 ) {
F_28 ( V_101 , V_114 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
}
} else if( ( 3 == V_110 ) && ( 0 == strcmp ( V_115 , V_98 [ V_110 - 1 ] ) ) ) {
if ( V_101 ) {
F_28 ( V_101 , V_113 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
}
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
if ( V_101 ) {
F_28 ( V_101 , V_116 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
}
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
if ( V_101 ) {
F_28 ( V_101 , V_114 , V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
}
} else {
int V_117 ;
for( V_117 = 0 ; V_117 < V_110 ; V_117 ++ ) {
if ( V_101 ) {
V_100 = F_28 ( V_101 ,
( V_117 < ( V_110 - 1 ) ? V_118 : V_114 ) ,
V_30 , V_99 , ( T_17 ) strlen ( * V_98 ) , V_62 | V_63 ) ;
F_55 ( V_100 , L_14 ) ;
}
V_99 += ( T_16 ) strlen ( * V_98 ) + 1 ;
V_98 ++ ;
}
}
} else {
V_92 = 0 ;
goto V_66;
}
}
V_66:
F_56 ( V_94 ) ;
F_57 ( T_4 -> V_49 , - 1 , FALSE ) ;
return V_92 ;
}
static int F_23 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , T_19 * V_44 ,
T_11 * * V_45 )
{
T_16 V_38 = 0 ;
T_16 V_39 ;
T_17 V_40 = 0 ;
do {
T_23 V_119 ;
T_23 V_120 ;
T_24 V_121 ;
T_24 V_122 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_23 ) ) {
V_40 = ( T_17 ) ( sizeof( T_23 ) - V_39 ) ;
break;
} else {
V_119 = F_58 ( V_30 , V_38 ) ;
V_38 += ( int ) sizeof( T_23 ) ;
V_120 = V_38 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_119 ) {
V_40 = ( T_17 ) ( V_119 - V_39 ) ;
break;
}
if ( 0 == V_119 ) {
break;
}
V_38 += V_119 ;
}
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
} else {
V_121 = F_59 ( V_30 , V_38 ) ;
V_38 += 2 ;
V_122 = V_38 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_121 ) {
V_40 = ( T_17 ) ( V_121 - V_39 ) ;
break;
}
V_38 += V_121 ;
}
if ( V_45 && ( sizeof( L_15 ) - 1 ) == V_119 ) {
if ( 0 == F_60 ( V_30 , V_120 , L_15 , sizeof( L_15 ) - 1 ) ) {
* V_45 = F_47 ( F_48 () , V_30 , V_122 , V_121 , V_62 ) ;
}
}
if ( V_44 && ( sizeof( T_19 ) == V_121 ) && ( ( sizeof( L_16 ) - 1 ) == V_119 ) ) {
if ( 0 == F_60 ( V_30 , V_120 , L_16 , sizeof( L_16 ) - 1 ) ) {
* V_44 = F_61 ( V_30 , V_122 ) ;
}
}
} while ( TRUE );
if ( ( V_40 > 0 ) && V_47 && T_4 -> V_48 ) {
T_4 -> V_36 = 0 ;
T_4 -> V_37 = V_40 ;
return - V_40 ;
}
if ( V_31 ) {
T_16 V_51 = 0 ;
T_20 * V_123 ;
T_14 * V_124 ;
V_123 =
F_27 ( V_31 , V_125 , V_30 , V_51 , - 1 , L_17 ) ;
V_124 = F_26 ( V_123 , V_126 ) ;
do {
T_23 V_127 = F_58 ( V_30 , V_51 ) ;
T_20 * V_128 =
F_28 ( V_124 , V_129 , V_30 , V_51 , - 1 , V_63 ) ;
T_14 * V_130 = F_26 ( V_128 , V_131 ) ;
F_28 ( V_130 , V_132 , V_30 , V_51 , ( int ) sizeof( V_133 ) , V_62 | V_134 ) ;
if ( V_127 > 0 ) {
F_55 ( V_128 , L_18 ,
F_62 ( V_30 , V_51 + ( int ) sizeof( T_23 ) , V_127 ) ) ;
}
V_51 += ( int ) sizeof( T_23 ) + V_127 ;
if ( V_127 > 0 ) {
T_24 V_135 = F_59 ( V_30 , V_51 ) ;
if ( V_31 ) {
F_63 ( V_130 , V_136 , V_30 , V_51 ,
2 , V_135 ) ;
F_28 ( V_130 , V_137 , V_30 , V_51 + 2 ,
V_135 , V_63 ) ;
}
V_51 += 2 + V_135 ;
}
F_31 ( V_128 , V_30 , V_51 ) ;
if ( 0 == V_127 ) {
break;
}
} while ( TRUE );
F_31 ( V_123 , V_30 , V_51 ) ;
F_17 ( V_38 == V_51 ) ;
}
return V_38 ;
}
static int F_64 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , void * V_28 V_11 )
{
T_17 V_138 = 0 ;
T_16 V_38 = 0 ;
T_16 V_51 = 0 ;
T_16 V_39 ;
T_17 V_40 = 0 ;
T_25 * V_139 ;
T_25 * V_140 ;
while ( TRUE ) {
T_23 V_141 ;
T_16 V_142 = V_38 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if( ( 0 == V_39 ) && ( 0 != V_138 ) ) {
break;
}
if ( V_39 < sizeof( V_143 ) ) {
V_40 = ( T_17 ) ( sizeof( V_143 ) - V_39 ) ;
break;
}
if ( F_21 ( V_30 , V_38 , V_143 , sizeof( V_143 ) ) != 0 ) {
return 0 ;
}
V_38 += ( int ) sizeof( V_143 ) ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_23 ) ) {
V_40 = ( T_17 ) ( sizeof( T_23 ) - V_39 ) ;
break;
} else {
V_141 = F_58 ( V_30 , V_38 ) ;
V_38 += ( int ) sizeof( T_23 ) ;
if ( ( V_144 != V_141 ) && ( V_145 != V_141 ) ) {
return 0 ;
}
}
if( V_141 > 0 ) {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_23 ) ) {
V_40 = ( T_17 ) ( sizeof( T_23 ) - V_39 ) ;
break;
} else {
V_38 += ( int ) sizeof( T_23 ) ;
}
}
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
} else {
T_24 V_146 = F_59 ( V_30 , V_38 ) ;
T_16 V_147 ;
V_38 += 2 ;
for ( V_147 = 0 ; V_147 < V_146 ; V_147 ++ ) {
T_24 V_148 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( V_148 ) ) {
V_40 = ( T_17 ) ( sizeof( V_148 ) - V_39 ) ;
break;
}
V_148 = F_59 ( V_30 , V_38 ) ;
V_39 = F_20 ( V_30 , V_38 + ( int ) sizeof( V_148 ) ) ;
if ( V_39 < V_148 ) {
V_40 = ( T_17 ) ( V_148 - V_39 ) ;
break;
}
V_38 += ( int ) sizeof( V_148 ) + V_148 ;
}
}
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
} else {
T_24 V_149 = F_59 ( V_30 , V_38 ) ;
T_16 V_150 ;
V_38 += 2 ;
for ( V_150 = 0 ; V_150 < V_149 ; V_150 ++ ) {
T_13 * V_151 = F_22 ( V_30 , V_38 ) ;
int V_43 ;
if( V_144 == V_141 ) {
V_43 = F_65 ( V_151 , T_4 , NULL , 0 , NULL ) ;
} else if( V_145 == V_141 ) {
V_43 = F_66 ( V_151 , T_4 , NULL , 0 , NULL ) ;
} else {
return 0 ;
}
if ( V_43 < 0 ) {
V_40 = - V_43 ;
break;
}
if ( 0 == V_43 ) {
return 0 ;
}
V_38 += V_43 ;
}
}
if ( ( V_5 == T_4 -> V_74 . type ) && ( V_5 == T_4 -> V_84 . type ) ) {
T_8 * V_152 = F_43 ( F_34 () , T_8 ) ;
F_39 ( & V_152 -> V_4 , & T_4 -> V_74 ) ;
F_39 ( & V_152 -> V_15 , & T_4 -> V_84 ) ;
V_152 -> V_16 = V_38 - V_142 ;
F_67 ( V_153 , T_4 , V_152 ) ;
}
V_138 ++ ;
}
if ( ( V_40 > 0 ) && V_47 && T_4 -> V_48 ) {
T_4 -> V_36 = 0 ;
T_4 -> V_37 = V_40 ;
return - V_40 ;
}
V_139 = F_68 ( F_48 () ) ;
F_69 ( V_139 , F_70 ( F_48 () , & T_4 -> V_74 ) ) ;
V_140 = F_68 ( F_48 () ) ;
F_69 ( V_140 , F_70 ( F_48 () , & T_4 -> V_84 ) ) ;
if ( V_18 != T_4 -> V_71 ) {
F_71 ( V_139 , L_19 , T_4 -> V_76 ) ;
F_71 ( V_140 , L_19 , T_4 -> V_85 ) ;
}
F_24 ( T_4 -> V_49 , V_50 , L_7 ) ;
if( V_138 > 1 ) {
F_72 ( T_4 -> V_49 , V_96 , L_20 , V_138 ,
F_73 ( V_139 ) , F_73 ( V_140 ) ) ;
} else {
F_72 ( T_4 -> V_49 , V_96 , L_21 ,
F_73 ( V_139 ) , F_73 ( V_140 ) ) ;
}
F_57 ( T_4 -> V_49 , - 1 , FALSE ) ;
while( V_31 && ( V_138 > 0 ) ) {
T_20 * V_154 = NULL ;
T_14 * V_155 = NULL ;
T_23 V_141 ;
const T_11 * * V_156 = NULL ;
T_24 V_146 ;
T_16 V_147 ;
T_24 V_149 ;
T_16 V_150 ;
T_20 * V_157 ;
V_154 = F_25 ( V_31 , V_158 , V_30 , V_51 , - 1 ,
L_22 , F_73 ( V_139 ) ,
F_73 ( V_140 ) ) ;
V_155 = F_26 ( V_154 , V_159 ) ;
F_28 ( V_155 , V_160 , V_30 , V_51 , ( int ) sizeof( V_143 ) , V_62 | V_63 ) ;
V_51 += ( int ) sizeof( V_143 ) ;
V_157 = F_74 ( V_155 , V_161 , V_30 , 0 , 0 , F_73 ( V_139 ) ) ;
F_51 ( V_157 ) ;
V_157 = F_74 ( V_155 , V_162 , V_30 , 0 , 0 , F_73 ( V_139 ) ) ;
F_75 ( V_157 ) ;
F_51 ( V_157 ) ;
if( V_5 == T_4 -> V_74 . type ) {
V_157 = F_74 ( V_155 , V_163 , V_30 , 0 , 0 , F_73 ( V_139 ) ) ;
F_75 ( V_157 ) ;
F_51 ( V_157 ) ;
V_157 = F_74 ( V_155 , V_164 , V_30 , 0 , 0 , F_73 ( V_139 ) ) ;
F_75 ( V_157 ) ;
F_51 ( V_157 ) ;
}
V_157 = F_74 ( V_155 , V_165 , V_30 , 0 , 0 , F_73 ( V_140 ) ) ;
F_51 ( V_157 ) ;
V_157 = F_74 ( V_155 , V_162 , V_30 , 0 , 0 , F_73 ( V_140 ) ) ;
F_75 ( V_157 ) ;
F_51 ( V_157 ) ;
if( V_5 == T_4 -> V_84 . type ) {
V_157 = F_74 ( V_155 , V_166 , V_30 , 0 , 0 , F_73 ( V_140 ) ) ;
F_75 ( V_157 ) ;
F_51 ( V_157 ) ;
V_157 = F_74 ( V_155 , V_164 , V_30 , 0 , 0 , F_73 ( V_140 ) ) ;
F_75 ( V_157 ) ;
F_51 ( V_157 ) ;
}
V_141 = F_58 ( V_30 , V_51 ) ;
F_63 ( V_155 , V_167 , V_30 , V_51 , 1 , V_141 ) ;
V_51 += 1 ;
if( V_141 > 0 ) {
static const int * V_168 [] = {
& V_169 ,
& V_170 ,
NULL
} ;
F_76 ( V_155 , V_30 , V_51 , V_171 , V_172 , V_168 , V_63 ) ;
V_51 += 1 ;
}
V_146 = F_59 ( V_30 , V_51 ) ;
F_63 ( V_155 , V_173 , V_30 , V_51 , 2 , V_146 ) ;
V_51 += 2 ;
V_156 = ( const T_11 * * ) F_77 ( F_48 () , ( V_146 + 2 ) * sizeof( const T_11 * ) ) ;
V_156 [ 0 ] = L_23 ;
V_156 [ 1 ] = L_24 ;
for ( V_147 = 0 ; V_147 < V_146 ; V_147 ++ ) {
T_24 V_148 = F_59 ( V_30 , V_51 ) ;
V_156 [ 2 + V_147 ] = F_47 ( F_48 () , V_30 , V_51 + 2 , V_148 , V_62 ) ;
F_28 ( V_155 , V_174 , V_30 , V_51 , 2 , V_62 | V_134 ) ;
V_51 += 2 + V_148 ;
}
V_149 = F_59 ( V_30 , V_51 ) ;
F_28 ( V_155 , V_175 , V_30 , V_51 , 2 , V_134 ) ;
V_51 += 2 ;
for ( V_150 = 0 ; V_150 < V_149 ; V_150 ++ ) {
T_13 * V_151 = F_22 ( V_30 , V_51 ) ;
if( V_144 == V_141 ) {
V_51 +=
F_65 ( V_151 , T_4 , V_155 , V_146 + 2 , V_156 ) ;
} else if( V_145 == V_141 ) {
V_51 +=
F_66 ( V_151 , T_4 , V_155 , V_146 + 2 , V_156 ) ;
} else {
return 0 ;
}
}
F_31 ( V_154 , V_30 , V_51 ) ;
V_138 -- ;
}
if( V_31 ) {
F_17 ( V_51 == V_38 ) ;
}
return V_38 ;
}
static int F_65 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , T_16 V_176 ,
const T_11 * * V_156 )
{
T_16 V_38 = 0 ;
T_16 V_39 ;
T_17 V_40 = 0 ;
T_23 V_168 ;
while ( TRUE ) {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( V_177 ) ) {
V_40 = ( T_17 ) ( sizeof( V_177 ) - V_39 ) ;
}
if ( F_21 ( V_30 , V_38 , V_177 , sizeof( V_177 ) ) != 0 ) {
return 0 ;
}
V_38 += ( int ) sizeof( V_177 ) ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_23 ) ) {
V_40 = ( T_17 ) ( sizeof( T_23 ) - V_39 ) ;
break;
}
V_38 += ( int ) sizeof( T_23 ) ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_23 ) ) {
V_40 = ( T_17 ) ( sizeof( T_23 ) - V_39 ) ;
break;
} else {
V_168 = F_58 ( V_30 , V_38 ) ;
V_38 += ( int ) sizeof( T_23 ) ;
}
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
} else {
T_24 V_148 = F_59 ( V_30 , V_38 ) ;
V_38 += 2 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_148 ) {
V_40 = ( T_17 ) ( V_148 - V_39 ) ;
break;
}
V_38 += V_148 ;
}
if ( ( V_168 & V_178 ) != 0 ) {
T_24 V_179 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
}
V_179 = F_59 ( V_30 , V_38 ) ;
V_38 += 2 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_179 ) {
V_40 = ( T_17 ) ( V_179 - V_39 ) ;
break;
}
V_38 += V_179 ;
}
if ( ( V_168 & V_180 ) != 0 ) {
T_24 V_181 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
}
V_181 = F_59 ( V_30 , V_38 ) ;
V_38 += 2 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_181 ) {
V_40 = ( T_17 ) ( V_181 - V_39 ) ;
break;
}
V_38 += V_181 ;
}
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
} else {
T_15 V_182 = F_78 ( V_30 , V_38 ) ;
V_38 += ( int ) sizeof( T_15 ) ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_182 ) {
V_40 = ( T_17 ) ( V_182 - V_39 ) ;
break;
}
V_38 += V_182 ;
}
if ( ( V_168 & V_183 ) != 0 ) {
T_13 * V_184 ;
int V_43 ;
V_184 = F_22 ( V_30 , V_38 ) ;
V_43 = F_65 ( V_184 , T_4 , NULL , 0 , NULL ) ;
if ( V_43 == 0 ) {
return V_38 ;
}
if ( V_43 < 0 ) {
V_40 = - V_43 ;
break;
}
V_38 += V_43 ;
}
break;
}
if ( ( V_40 > 0 ) && V_47 && T_4 -> V_48 ) {
T_4 -> V_36 = 0 ;
T_4 -> V_37 = V_40 ;
return - V_40 ;
}
{
T_16 V_51 = 0 ;
T_20 * V_185 = F_28 ( V_31 , V_186 , V_30 , V_51 , - 1 , V_63 ) ;
T_14 * V_187 = F_26 ( V_185 , V_188 ) ;
T_23 V_189 ;
T_20 * V_190 ;
T_24 V_148 ;
T_15 V_182 ;
T_11 * V_191 = NULL ;
T_13 * V_192 ;
static const int * V_193 [] = {
& V_194 ,
& V_195 ,
& V_196 ,
NULL
} ;
F_28 ( V_187 , V_197 , V_30 , V_51 , ( int ) sizeof( V_177 ) , V_62 | V_63 ) ;
V_51 += ( int ) sizeof( V_177 ) ;
V_189 = F_58 ( V_30 , V_51 ) ;
V_190 =
F_63 ( V_187 , V_198 , V_30 , V_51 , 1 , V_189 ) ;
if ( V_189 < V_176 ) {
F_55 ( V_190 , L_25 , V_156 [ V_189 ] ) ;
} else {
F_55 ( V_190 , L_26 ) ;
}
V_51 += 1 ;
V_168 = F_58 ( V_30 , V_51 ) ;
F_76 ( V_187 , V_30 , V_51 , V_199 , V_200 , V_193 , V_63 ) ;
V_51 += 1 ;
V_148 = F_59 ( V_30 , V_51 ) ;
F_55 ( V_185 , L_18 , F_62 ( V_30 , V_51 + 2 , V_148 ) ) ;
F_28 ( V_187 , V_201 , V_30 , V_51 , 2 , V_62 | V_134 ) ;
V_51 += 2 + V_148 ;
if ( ( V_168 & V_178 ) != 0 ) {
T_24 V_179 = F_59 ( V_30 , V_51 ) ;
F_28 ( V_187 , V_202 , V_30 , V_51 , 2 , V_62 | V_134 ) ;
V_51 += 2 ;
V_191 = F_47 ( F_48 () , V_30 , V_51 , V_179 , V_62 ) ;
V_51 += V_179 ;
}
if ( ( V_168 & V_180 ) != 0 ) {
T_24 V_181 = F_59 ( V_30 , V_51 ) ;
F_28 ( V_187 , V_203 , V_30 , V_51 , 2 , V_62 | V_134 ) ;
V_51 += 2 + V_181 ;
}
V_182 = F_78 ( V_30 , V_51 ) ;
F_28 ( V_187 , V_204 , V_30 , V_51 , 4 , V_134 ) ;
V_51 += 4 ;
V_192 = F_29 ( V_30 , V_51 , V_182 ) ;
V_51 += F_30 ( V_191 , V_192 , T_4 , V_187 ) ;
if ( ( V_168 & V_183 ) != 0 ) {
T_13 * V_151 = F_22 ( V_30 , V_51 ) ;
V_51 += F_65 ( V_151 , T_4 , V_187 , V_176 , V_156 ) ;
}
F_31 ( V_185 , V_30 , V_51 ) ;
F_17 ( V_51 == V_38 ) ;
}
return V_38 ;
}
static int F_66 ( T_13 * V_30 , T_3 * T_4 , T_14 * V_31 , T_16 V_205 ,
const T_11 * * V_156 )
{
T_16 V_38 = 0 ;
T_16 V_39 ;
T_17 V_40 = 0 ;
T_23 V_168 ;
while ( TRUE ) {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( V_177 ) ) {
V_40 = ( T_17 ) ( sizeof( V_177 ) - V_39 ) ;
}
if ( F_21 ( V_30 , V_38 , V_177 , sizeof( V_177 ) ) != 0 ) {
return 0 ;
}
V_38 += ( int ) sizeof( V_177 ) ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_23 ) ) {
V_40 = ( T_17 ) ( sizeof( T_23 ) - V_39 ) ;
break;
} else {
V_168 = F_58 ( V_30 , V_38 ) ;
V_38 += ( int ) sizeof( T_23 ) ;
}
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
}
V_38 += 2 ;
if ( ( V_168 & V_206 ) == 0 ) {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
}
V_38 += 2 ;
} else {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
} else {
T_24 V_148 = F_59 ( V_30 , V_38 ) ;
V_38 += 2 ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_148 ) {
V_40 = ( T_17 ) ( V_148 - V_39 ) ;
break;
}
V_38 += V_148 ;
}
}
if ( ( V_168 & V_207 ) != 0 ) {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
}
V_38 += 2 ;
}
if ( ( V_168 & V_208 ) != 0 ) {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_24 ) ) {
V_40 = ( T_17 ) ( sizeof( T_24 ) - V_39 ) ;
break;
}
V_38 += 2 ;
}
if ( ( V_168 & V_209 ) != 0 ) {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_19 ) ) {
V_40 = ( T_17 ) ( sizeof( T_19 ) - V_39 ) ;
break;
} else {
T_19 V_182 = F_61 ( V_30 , V_38 ) ;
V_38 += ( int ) sizeof( T_19 ) ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_182 ) {
V_40 = ( T_17 ) ( V_182 - V_39 ) ;
break;
}
V_38 += ( T_16 ) V_182 ;
}
} else {
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < sizeof( T_15 ) ) {
V_40 = ( T_17 ) ( sizeof( T_15 ) - V_39 ) ;
break;
} else {
T_19 V_182 = F_78 ( V_30 , V_38 ) ;
V_38 += ( int ) sizeof( T_15 ) ;
V_39 = F_20 ( V_30 , V_38 ) ;
if ( V_39 < V_182 ) {
V_40 = ( T_17 ) ( V_182 - V_39 ) ;
break;
}
V_38 += ( T_16 ) V_182 ;
}
}
if ( ( V_168 & V_210 ) != 0 ) {
T_13 * V_184 ;
int V_43 ;
V_184 = F_22 ( V_30 , V_38 ) ;
V_43 = F_66 ( V_184 , T_4 , NULL , 0 , NULL ) ;
if ( V_43 == 0 ) {
return V_38 ;
}
if ( V_43 < 0 ) {
V_40 = - V_43 ;
break;
}
V_38 += V_43 ;
}
break;
}
if ( ( V_40 > 0 ) && V_47 && T_4 -> V_48 ) {
T_4 -> V_36 = 0 ;
T_4 -> V_37 = V_40 ;
return - V_40 ;
}
{
T_16 V_51 = 0 ;
T_20 * V_185 = F_28 ( V_31 , V_186 , V_30 , V_51 , - 1 , V_63 ) ;
T_14 * V_187 = F_26 ( V_185 , V_188 ) ;
T_24 V_189 ;
T_20 * V_190 ;
T_24 V_211 ;
T_20 * V_212 ;
T_19 V_182 ;
const T_11 * V_191 = NULL ;
T_13 * V_192 ;
static const int * V_193 [] = {
& V_213 ,
& V_214 ,
& V_215 ,
& V_216 ,
& V_217 ,
& V_218 ,
NULL
} ;
F_28 ( V_187 , V_197 , V_30 , V_51 , ( int ) sizeof( V_177 ) , V_62 | V_63 ) ;
V_51 += ( int ) sizeof( V_177 ) ;
V_168 = F_58 ( V_30 , V_51 ) ;
F_76 ( V_187 , V_30 , V_51 , V_199 , V_219 , V_193 , V_63 ) ;
V_51 += 1 ;
V_189 = F_59 ( V_30 , V_51 ) ;
V_190 =
F_63 ( V_187 , V_220 , V_30 , V_51 , 2 , V_189 ) ;
if ( V_189 < V_205 ) {
F_55 ( V_190 , L_25 , V_156 [ V_189 ] ) ;
} else {
F_55 ( V_190 , L_26 ) ;
}
V_51 += 2 ;
if ( ( V_168 & V_206 ) == 0 ) {
V_211 = F_59 ( V_30 , V_51 ) ;
V_212 =
F_63 ( V_187 , V_221 , V_30 , V_51 , 2 , V_211 ) ;
if ( V_211 < V_205 ) {
F_55 ( V_212 , L_25 , V_156 [ V_211 ] ) ;
} else {
F_55 ( V_212 , L_26 ) ;
}
V_51 += 2 ;
} else {
T_24 V_148 = F_59 ( V_30 , V_51 ) ;
F_55 ( V_185 , L_18 , F_62 ( V_30 , V_51 + 2 , V_148 ) ) ;
F_28 ( V_187 , V_201 , V_30 , V_51 , 2 , V_62 | V_134 ) ;
V_51 += 2 + V_148 ;
}
if ( ( V_168 & V_207 ) != 0 ) {
T_24 V_222 = F_59 ( V_30 , V_51 ) ;
T_20 * V_223 =
F_63 ( V_187 , V_224 , V_30 , V_51 , 2 , V_222 ) ;
if ( V_222 < V_205 ) {
F_55 ( V_223 , L_25 , V_156 [ V_222 ] ) ;
V_191 = F_54 ( F_48 () , V_156 [ V_222 ] ) ;
} else {
F_55 ( V_223 , L_26 ) ;
}
V_51 += 2 ;
} else {
V_191 = L_27 ;
}
if ( ( V_168 & V_208 ) != 0 ) {
T_24 V_225 = F_59 ( V_30 , V_51 ) ;
T_20 * V_226 =
F_63 ( V_187 , V_227 , V_30 , V_51 , 2 , V_225 ) ;
if ( V_225 < V_205 ) {
F_55 ( V_226 , L_25 , V_156 [ V_225 ] ) ;
} else {
F_55 ( V_226 , L_26 ) ;
}
V_51 += 2 ;
}
if ( ( V_168 & V_209 ) != 0 ) {
V_182 = F_61 ( V_30 , V_51 ) ;
F_28 ( V_187 , V_228 , V_30 , V_51 , 8 , V_134 ) ;
V_51 += 8 ;
} else {
V_182 = F_78 ( V_30 , V_51 ) ;
F_28 ( V_187 , V_204 , V_30 , V_51 , 4 , V_134 ) ;
V_51 += 4 ;
}
V_192 = F_29 ( V_30 , V_51 , ( T_17 ) V_182 ) ;
V_51 += F_30 ( V_191 , V_192 , T_4 , V_187 ) ;
if ( ( V_168 & V_210 ) != 0 ) {
T_13 * V_151 = F_22 ( V_30 , V_51 ) ;
V_51 += F_65 ( V_151 , T_4 , V_187 , V_205 , V_156 ) ;
}
F_31 ( V_185 , V_30 , V_51 ) ;
F_17 ( V_51 == V_38 ) ;
}
return V_38 ;
}
static int F_30 ( const T_11 * V_229 , T_13 * V_30 , T_3 * T_4 , T_14 * V_31 ) {
int V_230 = 0 ;
if ( V_229 ) {
T_11 * V_191 = F_54 ( F_48 () , V_229 ) ;
T_11 * V_231 = strchr ( V_191 , ';' ) ;
const char * V_232 = T_4 -> V_233 ;
T_26 V_234 = { V_235 , NULL } ;
if ( NULL != V_231 ) {
V_234 . V_236 = F_54 ( F_48 () , V_231 + 1 ) ;
* V_231 = '\0' ;
}
T_4 -> V_233 = F_54 ( F_48 () , V_191 ) ;
F_79 ( V_191 ) ;
if ( 0 == strcmp ( L_28 , V_191 ) ) {
if ( NULL != V_237 ) {
V_230 = F_80 ( V_237 , V_30 , T_4 , V_31 ) ;
}
} else if ( 0 == strcmp ( L_29 , V_191 ) ) {
T_13 * V_238 = F_81 ( V_30 , V_30 , 0 , F_82 ( V_30 ) ) ;
if( NULL != V_238 ) {
F_83 ( T_4 , V_238 , L_30 ) ;
V_230 = F_30 ( L_31 , V_238 , T_4 , V_31 ) ;
if( V_230 > 0 ) {
V_230 = F_82 ( V_30 ) ;
}
}
} else {
V_230 = F_84 ( V_239 , V_191 , V_30 , T_4 , V_31 , & V_234 ) ? F_82 ( V_30 ) : 0 ;
if( V_230 != ( int ) F_82 ( V_30 ) ) {
}
}
if ( 0 == V_230 ) {
V_230 = F_85 ( V_240 , V_30 , T_4 , V_31 , & V_234 ) ;
}
T_4 -> V_233 = V_232 ;
}
if( 0 == V_230 ) {
V_230 = F_86 ( V_30 , T_4 , V_31 ) ;
}
return V_230 ;
}
void F_87 ( void )
{
T_27 * V_241 ;
static T_28 V_242 [] = {
{ & V_164 ,
{ L_32 , L_33 , V_243 , V_244 , NULL , 0x0 ,
L_34 , V_245 }
} ,
{ & V_163 ,
{ L_35 , L_36 , V_243 , V_244 , NULL , 0x0 ,
L_37 , V_245 }
} ,
{ & V_166 ,
{ L_38 , L_39 , V_243 , V_244 , NULL , 0x0 ,
L_40 , V_245 }
} ,
{ & V_57 ,
{ L_41 , L_6 , V_246 , V_244 , NULL , 0x0 ,
NULL , V_245 }
} ,
{ & V_61 ,
{ L_42 , L_43 , V_243 , V_244 , NULL , 0x0 ,
L_44 , V_245 }
} ,
{ & V_102 ,
{ L_9 , L_45 , V_246 , V_244 , NULL , 0x00 ,
L_46 , V_245 }
} ,
{ & V_105 ,
{ L_47 , L_48 , V_247 , V_244 , NULL , 0x00 ,
L_49 , V_245 }
} ,
{ & V_106 ,
{ L_42 , L_50 , V_243 , V_244 , NULL , 0x0 ,
L_51 , V_245 }
} ,
{ & V_107 ,
{ L_52 , L_53 , V_243 , V_244 , NULL , 0x0 ,
L_54 , V_245 }
} ,
{ & V_108 ,
{ L_55 , L_56 , V_243 , V_244 , NULL , 0x0 ,
L_57 , V_245 }
} ,
{ & V_109 ,
{ L_58 , L_59 , V_243 , V_244 , NULL , 0x0 ,
L_60 , V_245 }
} ,
{ & V_113 ,
{ L_61 , L_62 , V_243 , V_244 , NULL , 0x0 ,
L_63 , V_245 }
} ,
{ & V_116 ,
{ L_64 , L_65 , V_243 , V_244 , NULL , 0x0 ,
L_66 , V_245 }
} ,
{ & V_118 ,
{ L_67 , L_68 , V_243 , V_244 , NULL , 0x0 ,
L_69 , V_245 }
} ,
{ & V_114 ,
{ L_70 , L_71 , V_243 , V_244 , NULL , 0x0 ,
L_72 , V_245 }
} ,
{ & V_125 ,
{ L_73 , L_74 , V_246 , V_244 , NULL , 0x0 ,
L_75 , V_245 }
} ,
{ & V_129 ,
{ L_76 , L_77 , V_246 , V_244 , NULL , 0x0 ,
L_78 , V_245 }
} ,
{ & V_132 ,
{ L_79 , L_80 , V_248 , V_244 , NULL , 0x0 ,
L_81 , V_245 }
} ,
{ & V_136 ,
{ L_82 , L_83 , V_249 , V_250 , NULL , 0x0 ,
L_84 , V_245 }
} ,
{ & V_137 ,
{ L_85 , L_86 , V_251 , V_244 , NULL , 0x0 ,
L_87 , V_245 }
} ,
{ & V_162 ,
{ L_32 , L_3 , V_243 , V_244 , NULL , 0x0 ,
L_88 , V_245 }
} ,
{ & V_161 ,
{ L_35 , L_89 , V_243 , V_244 , NULL , 0x0 ,
L_90 , V_245 }
} ,
{ & V_165 ,
{ L_38 , L_91 , V_243 , V_244 , NULL , 0x0 ,
L_92 , V_245 }
} ,
{ & V_160 ,
{ L_42 , L_93 , V_243 , V_244 , NULL , 0x0 ,
L_94 , V_245 }
} ,
{ & V_167 ,
{ L_70 , L_95 , V_252 , V_250 , NULL , 0x0 ,
L_96 , V_245 }
} ,
{ & V_171 ,
{ L_97 , L_98 , V_252 , V_253 , NULL , 0x0 ,
L_99 , V_245 }
} ,
{ & V_169 ,
{ L_100 , L_101 , V_247 , 2 , F_88 ( & V_254 ) , 0x01 ,
L_102 , V_245 }
} ,
{ & V_170 ,
{ L_103 , L_104 , V_247 , 2 , F_88 ( & V_254 ) , 0x02 ,
L_105 , V_245 }
} ,
{ & V_173 ,
{ L_106 , L_107 , V_249 , V_250 , NULL , 0x0 ,
L_108 , V_245 }
} ,
{ & V_174 ,
{ L_109 , L_110 , V_248 , V_244 , NULL , 0x0 ,
L_111 , V_245 }
} ,
{ & V_175 ,
{ L_112 , L_113 , V_249 , V_250 , NULL , 0x0 ,
L_114 , V_245 }
} ,
{ & V_186 ,
{ L_115 , L_116 , V_246 , V_244 , NULL , 0x0 ,
NULL , V_245 }
} ,
{ & V_197 ,
{ L_42 , L_117 , V_243 , V_244 , NULL , 0x0 ,
L_118 , V_245 }
} ,
{ & V_198 ,
{ L_119 , L_120 , V_252 , V_250 , NULL , 0x0 ,
L_121 , V_245 }
} ,
{ & V_220 ,
{ L_119 , L_120 , V_249 , V_250 , NULL , 0x0 ,
L_121 , V_245 }
} ,
{ & V_199 ,
{ L_97 , L_122 , V_252 , V_253 , NULL , 0x0 ,
L_123 , V_245 }
} ,
{ & V_194 ,
{ L_124 , L_125 , V_247 , 3 , F_88 ( & V_254 ) , 0x01 ,
L_126 , V_245 }
} ,
{ & V_195 ,
{ L_127 , L_128 , V_247 , 3 , F_88 ( & V_254 ) , 0x02 ,
L_129 , V_245 }
} ,
{ & V_196 ,
{ L_130 , L_131 , V_247 , 3 , F_88 ( & V_254 ) , 0x04 ,
L_132 , V_245 }
} ,
{ & V_213 ,
{ L_133 , L_134 , V_247 , 6 , F_88 ( & V_254 ) , 0x01 ,
L_135 , V_245 }
} ,
{ & V_214 ,
{ L_136 , L_137 , V_247 , 6 , F_88 ( & V_254 ) , 0x02 ,
L_138 , V_245 }
} ,
{ & V_215 ,
{ L_127 , L_125 , V_247 , 6 , F_88 ( & V_254 ) , 0x04 ,
L_126 , V_245 }
} ,
{ & V_216 ,
{ L_130 , L_131 , V_247 , 6 , F_88 ( & V_254 ) , 0x08 ,
L_132 , V_245 }
} ,
{ & V_217 ,
{ L_130 , L_128 , V_247 , 6 , F_88 ( & V_254 ) , 0x10 ,
L_129 , V_245 }
} ,
{ & V_218 ,
{ L_139 , L_140 , V_247 , 6 , F_88 ( & V_254 ) , 0x20 ,
L_141 , V_245 }
} ,
{ & V_221 ,
{ L_142 , L_143 , V_249 , V_250 , NULL , 0x0 ,
L_144 , V_245 }
} ,
{ & V_201 ,
{ L_145 , L_146 , V_248 , V_244 , NULL , 0x0 ,
L_147 , V_245 }
} ,
{ & V_224 ,
{ L_148 , L_149 , V_249 , V_250 , NULL , 0x0 ,
L_150 , V_245 }
} ,
{ & V_227 ,
{ L_151 , L_152 , V_249 , V_250 , NULL , 0x0 ,
L_153 , V_245 }
} ,
{ & V_202 ,
{ L_154 , L_155 , V_248 , V_244 , NULL , 0x0 ,
L_147 , V_245 }
} ,
{ & V_203 ,
{ L_154 , L_156 , V_248 , V_244 , NULL , 0x0 ,
L_157 , V_245 }
} ,
{ & V_204 ,
{ L_158 , L_159 , V_255 , V_250 , NULL , 0x0 ,
L_160 , V_245 }
} ,
{ & V_228 ,
{ L_158 , L_161 , V_256 , V_250 , NULL , 0x0 ,
L_160 , V_245 }
} ,
#if 0
{&hf_jxta_element_content,
{"Element Content", "jxta.message.element.content", FT_BYTES, BASE_NONE, NULL, 0x0,
"JXTA Message Element Content", HFILL}
},
#endif
} ;
V_53 = F_89 ( L_162 , L_7 , L_24 ) ;
V_153 = F_90 ( L_24 ) ;
V_158 = F_89 ( L_163 , L_163 , L_164 ) ;
F_91 ( L_6 , F_12 , V_53 ) ;
F_91 ( L_165 , F_14 , V_53 ) ;
F_92 ( V_53 , V_242 , F_93 ( V_242 ) ) ;
F_94 ( V_257 , F_93 ( V_257 ) ) ;
V_5 = F_95 ( L_166 , L_167 , F_7 , F_8 , NULL , F_9 , NULL , NULL , NULL ) ;
V_241 = F_96 ( V_53 , V_258 ) ;
F_97 ( V_241 , L_168 , L_169 ,
L_170 , & V_259 ) ;
F_97 ( V_241 , L_171 ,
L_172 ,
L_173
L_174
L_175 ,
& V_47 ) ;
F_98 ( V_241 , L_176 ) ;
F_98 ( V_241 , L_177 ) ;
F_98 ( V_241 , L_178 ) ;
F_99 ( V_53 , TRUE , F_2 , F_5 ) ;
}
void V_258 ( void )
{
static T_12 V_260 = FALSE ;
static T_29 V_261 ;
static T_12 V_262 = FALSE ;
if( ! V_260 ) {
V_261 = F_100 ( F_64 , V_158 ) ;
V_87 = F_18 ( L_165 ) ;
V_239 = F_101 ( L_179 ) ;
V_237 = F_102 ( L_180 , V_53 ) ;
V_240 = F_102 ( L_181 , V_53 ) ;
V_260 = TRUE ;
}
if( V_259 ) {
if( ! V_262 ) {
F_103 ( L_179 , L_182 , V_261 ) ;
V_262 = TRUE ;
}
} else {
if( V_262 ) {
F_104 ( L_179 , L_182 , V_261 ) ;
V_262 = FALSE ;
}
}
F_105 ( L_183 , F_10 , L_184 , L_185 , V_53 , V_263 ) ;
F_105 ( L_186 , F_13 , L_187 , L_188 , V_53 , V_263 ) ;
F_105 ( L_189 , F_15 , L_190 , L_191 , V_53 , V_263 ) ;
}
