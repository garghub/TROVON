void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 * V_4 = NULL ;
T_5 * V_5 ;
char * V_6 ;
V_5 = F_2 ( V_2 , L_1 ) ;
if ( ! V_5 ) {
return;
}
V_6 = F_3 ( F_4 () , V_5 -> V_7 ) ;
if ( ! V_1 -> V_8 -> V_9 . V_10 ) {
V_4 = ( T_4 * ) F_5 ( V_3 -> V_11 , V_6 , V_12 ) ;
if ( V_4 ) {
V_4 -> V_13 = V_1 -> V_8 -> V_14 ;
} else {
char * V_15 = F_3 ( F_6 () , V_6 ) ;
V_4 = F_7 ( F_6 () , T_4 ) ;
V_4 -> V_16 = V_1 -> V_8 -> V_14 ;
V_4 -> V_13 = 0 ;
F_8 ( V_3 -> V_11 , V_15 , ( void * ) V_4 , V_12 ) ;
}
} else {
F_5 ( V_3 -> V_11 , V_6 , V_12 ) ;
}
}
void
F_9 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_2 * V_17 ;
T_6 * V_18 ;
V_18 = F_10 ( V_2 , L_2 ) ;
V_17 = ( T_2 * ) ( V_18 ? V_18 -> V_19 : NULL ) ;
if ( V_17 && ! V_1 -> V_8 -> V_9 . V_10 ) {
T_5 * V_5 ;
T_5 * V_20 ;
char * V_15 ;
char * V_21 ;
V_5 = F_2 ( V_2 , L_1 ) ;
if ( ! V_5 ) {
return;
}
V_20 = F_2 ( V_17 , L_3 ) ;
if ( ! V_20 ) {
return;
}
V_15 = F_3 ( F_6 () , V_5 -> V_7 ) ;
V_21 = F_3 ( F_6 () , V_20 -> V_7 ) ;
F_8 ( V_3 -> V_22 , V_15 , ( void * ) V_21 , V_12 ) ;
}
}
void
F_11 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_2 * V_23 ;
T_6 * V_24 ;
V_24 = F_10 ( V_2 , L_4 ) ;
V_23 = ( T_2 * ) ( V_24 ? V_24 -> V_19 : NULL ) ;
if ( V_23 && ! V_1 -> V_8 -> V_9 . V_10 ) {
T_5 * V_5 ;
T_5 * V_20 ;
char * V_15 ;
char * V_21 ;
T_5 * V_25 = F_2 ( V_23 , L_5 ) ;
if( V_25 && strcmp ( V_25 -> V_7 , L_6 ) != 0 )
return;
V_5 = F_2 ( V_2 , L_1 ) ;
if ( ! V_5 ) {
return;
}
V_20 = F_2 ( V_23 , L_1 ) ;
if ( ! V_20 ) {
return;
}
V_15 = F_3 ( F_6 () , V_5 -> V_7 ) ;
V_21 = F_3 ( F_6 () , V_20 -> V_7 ) ;
F_8 ( V_3 -> V_26 , V_15 , ( void * ) V_21 , V_12 ) ;
}
}
void
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_2 * V_27 = NULL ;
T_6 * V_28 ;
if( strcmp ( V_2 -> V_29 , L_7 ) == 0 )
{
V_28 = F_10 ( V_2 , L_8 ) ;
V_27 = ( T_2 * ) ( V_28 ? V_28 -> V_19 : NULL ) ;
} else if( strcmp ( V_2 -> V_29 , L_9 ) == 0 )
{
V_28 = F_10 ( V_2 , L_10 ) ;
if( ! V_28 )
V_28 = F_10 ( V_2 , L_11 ) ;
if( ! V_28 )
V_28 = F_10 ( V_2 , L_8 ) ;
V_27 = ( T_2 * ) ( V_28 ? V_28 -> V_19 : NULL ) ;
}
if ( V_27 && ! V_1 -> V_8 -> V_9 . V_10 ) {
T_5 * V_5 ;
T_5 * V_20 ;
char * V_15 ;
char * V_21 ;
V_5 = F_2 ( V_2 , L_1 ) ;
V_20 = F_2 ( V_27 , L_3 ) ;
if( V_5 && V_20 )
{
V_15 = F_3 ( F_6 () , V_5 -> V_7 ) ;
V_21 = F_3 ( F_6 () , V_20 -> V_7 ) ;
F_8 ( V_3 -> V_30 , V_15 , ( void * ) V_21 , V_12 ) ;
}
}
}
static void
F_13 ( T_7 * V_31 , T_8 * V_32 , T_1 * V_1 , T_2 * V_33 , T_9 V_34 )
{
T_6 * V_35 = V_33 -> V_36 ;
F_14 ( V_34 < V_37 ) ;
F_15 ( V_31 , V_32 , V_1 , V_33 , TRUE ) ;
if( V_33 -> V_19 )
{
F_16 ( V_31 , V_38 , V_32 , V_33 -> V_19 -> V_39 , V_33 -> V_19 -> V_40 , V_33 -> V_19 -> V_7 ) ;
}
while( V_35 )
{
T_2 * V_41 = ( T_2 * ) V_35 -> V_19 ;
T_10 * V_42 ;
T_7 * V_43 = F_17 ( V_31 , V_32 , V_41 -> V_39 , V_41 -> V_40 ,
V_44 [ V_34 ] , & V_42 , F_18 ( V_41 -> V_29 ) ) ;
if( V_41 -> V_45 )
F_19 ( V_42 , L_12 , V_41 -> V_45 ) ;
F_13 ( V_43 , V_32 , V_1 , V_41 , V_34 + 1 ) ;
V_35 = V_35 -> V_46 ;
}
}
void
F_20 ( T_7 * V_31 , T_8 * V_32 , T_1 * V_1 , T_2 * V_33 )
{
T_6 * V_35 = V_33 -> V_36 ;
while( V_35 )
{
T_2 * V_41 = ( T_2 * ) V_35 -> V_19 ;
if( ! V_41 -> V_47 )
{
T_10 * V_48 ;
T_7 * V_49 ;
V_48 = F_21 ( V_31 ,
V_50 , V_32 , V_41 -> V_39 , V_41 -> V_40 , V_41 -> V_29 ,
L_13 , F_18 ( V_41 -> V_29 ) ) ;
V_49 = F_22 ( V_48 , V_44 [ 0 ] ) ;
if( strcmp ( V_33 -> V_29 , L_9 ) == 0 )
F_23 ( V_1 -> V_51 , V_52 , L_14 , F_18 ( V_41 -> V_29 ) ) ;
if( V_41 -> V_45 )
F_19 ( V_48 , L_12 , V_41 -> V_45 ) ;
F_13 ( V_49 , V_32 , V_1 , V_41 , 1 ) ;
F_19 ( V_48 , L_15 ) ;
F_24 ( V_1 , V_48 , & V_53 , L_16 , V_41 -> V_29 ) ;
}
V_35 = V_35 -> V_46 ;
}
}
void
F_15 ( T_7 * V_31 , T_8 * V_32 , T_1 * V_1 V_54 , T_2 * V_33 , T_11 V_55 )
{
T_10 * V_56 = F_25 ( V_31 ) ;
T_6 * V_57 = F_26 ( V_33 -> V_58 ) ;
T_6 * V_59 = F_27 ( V_33 -> V_58 ) ;
T_6 * V_60 = V_57 , * V_61 = V_59 ;
T_11 V_62 = FALSE ;
while( V_57 && V_59 )
{
T_5 * V_63 = ( T_5 * ) V_59 -> V_19 ;
if ( ! V_63 -> V_47 ) {
if ( V_55 ) {
if ( ! V_62 )
F_19 ( V_56 , L_17 ) ;
else
F_19 ( V_56 , L_18 ) ;
F_19 ( V_56 , L_19 , ( V_64 * ) V_57 -> V_19 , V_63 -> V_7 ) ;
V_62 = TRUE ;
}
if ( strcmp ( ( const char * ) V_57 -> V_19 , L_5 ) == 0 )
F_16 ( V_31 , V_65 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 ) ;
else {
V_64 * V_66 = F_28 ( ( const char * ) V_57 -> V_19 , L_20 ) ;
if ( V_66 && V_66 == V_57 -> V_19 ) {
F_21 ( V_31 , V_65 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 , L_21 , ( V_64 * ) V_57 -> V_19 , V_63 -> V_7 ) ;
} else {
T_10 * V_67 ;
V_67 = F_21 ( V_31 ,
V_68 , V_32 , V_63 -> V_39 , V_63 -> V_40 ,
V_63 -> V_29 , L_21 , V_63 -> V_29 , V_63 -> V_7 ) ;
F_19 ( V_67 , L_22 ) ;
F_24 ( V_1 , V_67 , & V_69 , L_23 , V_63 -> V_29 ) ;
}
}
}
V_57 = V_57 -> V_46 ;
V_59 = V_59 -> V_46 ;
}
if( V_62 && V_55 )
F_19 ( V_56 , L_24 ) ;
F_29 ( V_60 ) ;
F_29 ( V_61 ) ;
}
void
F_30 ( T_7 * V_31 , T_8 * V_32 , T_2 * V_33 , T_12 V_70 )
{
if( V_33 -> V_19 )
{
if ( V_70 == - 1 ) {
F_16 ( V_31 , V_38 , V_32 , V_33 -> V_19 -> V_39 , V_33 -> V_19 -> V_40 , V_33 -> V_19 -> V_7 ) ;
} else {
F_16 ( V_31 , V_70 , V_32 , V_33 -> V_19 -> V_39 , V_33 -> V_19 -> V_40 , V_33 -> V_19 -> V_7 ) ;
}
} else
{
if ( V_70 == - 1 ) {
F_31 ( V_31 , V_38 , V_32 , 0 , 0 , L_25 , L_26 ) ;
} else {
F_16 ( V_31 , V_70 , V_32 , 0 , 0 , L_25 ) ;
}
}
}
void
F_32 ( T_7 * V_31 , T_8 * V_32 , T_1 * V_1 V_54 , T_2 * V_33 )
{
F_21 ( V_31 , V_38 , V_32 , V_33 -> V_39 , V_33 -> V_40 , F_33 ( V_33 ) ,
L_21 , F_18 ( V_33 -> V_29 ) , F_33 ( V_33 ) ) ;
}
T_13 *
F_34 ( const V_64 * * V_71 , T_12 V_72 )
{
T_13 * V_73 ;
V_73 = F_7 ( F_4 () , T_13 ) ;
V_73 -> V_19 = ( V_74 ) V_71 ;
V_73 -> V_40 = V_72 ;
return V_73 ;
}
T_5 *
F_35 ( const V_64 * V_7 , T_12 V_39 , T_12 V_40 )
{
T_5 * V_73 ;
V_73 = F_7 ( F_4 () , T_5 ) ;
V_73 -> V_7 = V_7 ;
V_73 -> V_39 = V_39 ;
V_73 -> V_40 = V_40 ;
V_73 -> V_29 = NULL ;
return V_73 ;
}
V_64 *
F_18 ( const V_64 * string )
{
T_12 V_72 = ( int ) strlen ( string ) ;
T_12 V_75 ;
V_64 * V_73 = ( V_64 * ) F_36 ( F_4 () , V_72 + 1 ) ;
for( V_75 = 0 ; V_75 < V_72 ; V_75 ++ )
{
V_73 [ V_75 ] = string [ V_75 ] ;
if( string [ V_75 ] >= 'a' && string [ V_75 ] <= 'z' )
V_73 [ V_75 ] -= 'a' - 'A' ;
}
return V_73 ;
}
T_12
F_37 ( T_14 V_76 , T_14 V_77 )
{
T_12 V_73 = strcmp ( ( ( const T_2 * ) V_76 ) -> V_29 , ( ( const T_2 * ) V_77 ) -> V_29 ) ;
if( V_73 == 0 && ( ( const T_2 * ) V_76 ) -> V_47 )
V_73 = - 1 ;
return V_73 ;
}
T_6 *
F_10 ( T_2 * V_2 , const V_64 * V_29 )
{
T_6 * V_78 ;
T_2 * V_79 ;
V_79 = F_7 ( F_4 () , T_2 ) ;
V_79 -> V_29 = F_3 ( F_4 () , V_29 ) ;
V_78 = F_38 ( V_2 -> V_36 , V_79 , F_37 ) ;
if( V_78 )
return V_78 ;
else
return NULL ;
}
T_2 *
F_39 ( T_2 * V_2 , const V_64 * V_29 )
{
T_6 * V_80 ;
T_2 * V_33 = NULL ;
V_80 = F_10 ( V_2 , V_29 ) ;
if( V_80 )
{
V_33 = ( T_2 * ) V_80 -> V_19 ;
V_33 -> V_47 = TRUE ;
}
return V_33 ;
}
T_2 *
F_40 ( T_2 * V_2 , const V_64 * * V_81 , T_12 V_82 )
{
T_12 V_75 ;
T_2 * V_83 = NULL ;
for( V_75 = 0 ; V_75 < V_82 ; V_75 ++ )
{
if( ( V_83 = F_39 ( V_2 , V_81 [ V_75 ] ) ) )
break;
}
return V_83 ;
}
T_2 *
F_41 ( T_2 * V_2 , const V_64 * V_84 , const V_64 * V_85 )
{
T_6 * V_35 = V_2 -> V_36 ;
T_2 * V_73 = NULL ;
while ( V_35 ) {
T_2 * V_86 = ( T_2 * ) V_35 -> V_19 ;
T_5 * V_63 = F_2 ( V_86 , V_84 ) ;
if( V_63 )
V_63 -> V_47 = FALSE ;
if ( ! V_86 -> V_47 && V_63 && strcmp ( V_63 -> V_7 , V_85 ) == 0 ) {
V_73 = ( T_2 * ) V_35 -> V_19 ;
V_73 -> V_47 = TRUE ;
break;
} else
V_35 = V_35 -> V_46 ;
}
return V_73 ;
}
T_2 *
F_42 ( T_2 * V_2 , const V_64 * V_29 , const V_64 * V_84 , const V_64 * V_85 )
{
T_6 * V_35 = V_2 -> V_36 ;
T_2 * V_73 = NULL ;
while ( V_35 ) {
T_2 * V_86 = ( T_2 * ) V_35 -> V_19 ;
T_5 * V_63 = F_2 ( V_86 , V_84 ) ;
if( V_63 )
V_63 -> V_47 = FALSE ;
if ( ! V_86 -> V_47 && V_63 && strcmp ( V_86 -> V_29 , V_29 ) == 0 && strcmp ( V_63 -> V_7 , V_85 ) == 0 ) {
V_73 = ( T_2 * ) V_35 -> V_19 ;
V_73 -> V_47 = TRUE ;
break;
} else
V_35 = V_35 -> V_46 ;
}
return V_73 ;
}
T_2 *
F_43 ( T_2 * V_2 )
{
if( V_2 -> V_36 && V_2 -> V_36 -> V_19 )
return ( T_2 * ) V_2 -> V_36 -> V_19 ;
else
return NULL ;
}
T_2 *
F_44 ( T_15 * V_87 , T_2 * V_88 , T_8 * V_32 )
{
T_15 * V_41 ;
T_2 * V_89 = F_45 ( F_4 () , T_2 ) ;
T_16 * V_90 ;
T_17 * V_91 ;
V_89 -> V_58 = F_46 ( V_92 , V_93 ) ;
V_89 -> V_36 = NULL ;
V_89 -> V_19 = NULL ;
V_89 -> V_47 = FALSE ;
V_89 -> V_45 = NULL ;
V_89 -> V_29 = F_3 ( F_4 () , V_87 -> V_94 ) ;
V_89 -> V_39 = 0 ;
V_89 -> V_40 = 0 ;
V_89 -> V_95 = F_46 ( V_92 , V_93 ) ;
if( V_88 )
{
F_47 ( V_88 -> V_95 , V_89 -> V_95 ) ;
} else
{
F_48 ( V_89 -> V_95 , ( V_74 ) L_25 , ( V_74 ) L_27 ) ;
}
if( V_87 -> V_56 != NULL )
{
V_89 -> V_40 = V_87 -> V_56 -> V_96 -> V_40 ;
}
V_89 -> V_39 = V_87 -> V_97 ;
V_90 = F_49 ( V_32 , V_89 -> V_39 , - 1 , NULL , V_98 ) ;
if( ( V_91 = F_50 ( V_90 , V_99 ) ) != NULL )
{
V_89 -> V_45 = F_51 ( F_4 () , V_91 -> V_100 -> V_32 , V_91 -> V_100 -> V_39 , V_91 -> V_100 -> V_72 , V_101 ) ;
}
V_41 = V_87 -> V_102 ;
while( V_41 )
{
if( V_41 -> type != V_103 )
{
if( V_41 -> type == V_104 )
{
T_12 V_105 ;
V_64 * V_7 = NULL ;
V_64 * V_66 = NULL ;
T_5 * V_63 = F_7 ( F_4 () , T_5 ) ;
V_63 -> V_40 = 0 ;
V_63 -> V_39 = 0 ;
V_63 -> V_47 = FALSE ;
if ( V_41 -> V_7 != NULL ) {
V_105 = F_52 ( V_41 -> V_7 ) ;
V_7 = ( V_64 * ) F_36 ( F_4 () , V_105 + 1 ) ;
F_53 ( V_41 -> V_7 , V_7 , 0 , V_105 ) ;
}
if( V_41 -> V_56 )
{
V_63 -> V_40 = V_41 -> V_56 -> V_96 -> V_40 ;
}
V_63 -> V_39 = V_41 -> V_97 ;
V_63 -> V_7 = V_7 ;
V_63 -> V_29 = F_3 ( F_4 () , V_41 -> V_94 ) ;
F_48 ( V_89 -> V_58 , ( V_74 ) V_63 -> V_29 , ( V_74 ) V_63 ) ;
V_66 = F_28 ( V_63 -> V_29 , L_5 ) ;
if( V_66 == V_63 -> V_29 )
{
if( V_63 -> V_29 [ 5 ] == ':' && strlen ( V_63 -> V_29 ) > 6 )
{
F_48 ( V_89 -> V_95 , ( V_74 ) F_3 ( F_4 () , & V_63 -> V_29 [ 6 ] ) , ( V_74 ) F_3 ( F_4 () , V_63 -> V_7 ) ) ;
} else if( V_63 -> V_29 [ 5 ] == '\0' )
{
F_48 ( V_89 -> V_95 , ( V_74 ) L_25 , ( V_74 ) F_3 ( F_4 () , V_63 -> V_7 ) ) ;
}
}
}
else if( V_41 -> type == V_106 )
{
T_18 * V_19 = NULL ;
T_12 V_105 ;
V_64 * V_7 = NULL ;
V_19 = F_7 ( F_4 () , T_18 ) ;
V_19 -> V_40 = 0 ;
V_19 -> V_39 = 0 ;
if ( V_41 -> V_7 != NULL ) {
V_105 = F_52 ( V_41 -> V_7 ) ;
V_7 = ( V_64 * ) F_36 ( F_4 () , V_105 + 1 ) ;
F_53 ( V_41 -> V_7 , V_7 , 0 , V_105 ) ;
}
V_19 -> V_7 = V_7 ;
if( V_41 -> V_56 )
{
V_19 -> V_40 = V_41 -> V_56 -> V_96 -> V_40 ;
}
V_19 -> V_39 = V_41 -> V_97 ;
V_89 -> V_19 = V_19 ;
}
} else
{
V_89 -> V_36 = F_54 ( V_89 -> V_36 , ( V_74 ) F_44 ( V_41 , V_89 , V_32 ) ) ;
}
V_41 = V_41 -> V_107 ;
}
return V_89 ;
}
void
F_55 ( T_2 * V_108 )
{
T_6 * V_35 = V_108 -> V_36 ;
F_56 ( V_108 -> V_58 ) ;
F_56 ( V_108 -> V_95 ) ;
while( V_35 )
{
T_2 * V_41 = ( T_2 * ) V_35 -> V_19 ;
F_55 ( V_41 ) ;
V_35 = V_35 -> V_46 ;
}
F_29 ( V_108 -> V_36 ) ;
}
static T_11
F_57 ( V_74 V_109 , V_74 V_7 V_54 , V_74 V_110 )
{
V_64 * V_84 = ( V_64 * ) V_110 ;
if( strcmp ( V_84 , L_5 ) == 0 )
{
V_64 * V_111 = F_28 ( ( const char * ) V_109 , L_20 ) ;
if( V_111 && V_111 == V_109 )
return TRUE ;
else
return FALSE ;
}
return FALSE ;
}
T_5 *
F_2 ( T_2 * V_33 , const V_64 * V_84 )
{
T_5 * V_73 = ( T_5 * ) F_58 ( V_33 -> V_58 , V_84 ) ;
if( ! V_73 )
{
V_73 = ( T_5 * ) F_59 ( V_33 -> V_58 , F_57 , ( V_74 ) V_84 ) ;
}
if( V_73 )
V_73 -> V_47 = TRUE ;
return V_73 ;
}
static T_5 *
F_60 ( T_2 * V_33 , const V_64 * V_84 , const V_64 * V_112 )
{
V_64 * V_113 ;
T_5 * V_73 ;
if( strcmp ( V_112 , L_25 ) == 0 )
V_113 = F_3 ( F_4 () , V_84 ) ;
else if( strcmp ( V_84 , L_5 ) == 0 )
V_113 = F_61 ( F_4 () , L_28 , V_84 , V_112 ) ;
else
V_113 = F_61 ( F_4 () , L_28 , V_112 , V_84 ) ;
V_73 = ( T_5 * ) F_58 ( V_33 -> V_58 , V_113 ) ;
if( ! V_73 )
{
V_73 = ( T_5 * ) F_59 ( V_33 -> V_58 , F_57 , ( V_74 ) V_84 ) ;
}
if( V_73 )
V_73 -> V_47 = TRUE ;
return V_73 ;
}
V_64 *
F_62 ( T_8 * V_32 , T_2 * V_33 )
{
V_64 * V_114 = NULL ;
if( F_63 ( V_32 , V_33 -> V_39 + V_33 -> V_40 - 1 ) )
{
V_114 = F_51 ( F_4 () , V_32 , V_33 -> V_39 , V_33 -> V_40 , V_101 ) ;
}
return V_114 ;
}
V_64 *
F_64 ( T_8 * V_32 , T_5 * V_63 )
{
V_64 * V_114 = NULL ;
if( F_63 ( V_32 , V_63 -> V_39 + V_63 -> V_40 - 1 ) )
{
V_114 = F_51 ( F_4 () , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_101 ) ;
}
return V_114 ;
}
static void
F_65 ( T_19 * V_89 , V_74 V_19 )
{
int * V_75 = ( int * ) V_19 ;
if( ( * V_75 ) == 0 )
F_66 ( V_89 ) ;
( * V_75 ) ++ ;
}
static void
F_67 ( T_19 * V_89 , V_74 V_19 )
{
int * V_75 = ( int * ) V_19 ;
if( ( * V_75 ) == 0 )
F_68 ( V_89 ) ;
( * V_75 ) ++ ;
}
void
F_69 ( T_7 * V_31 )
{
int V_75 = 0 ;
F_70 ( V_31 , F_65 , & V_75 ) ;
}
void
F_71 ( T_7 * V_31 )
{
int V_75 = 0 ;
F_70 ( V_31 , F_67 , & V_75 ) ;
}
V_64 *
F_72 ( T_10 * V_56 )
{
T_20 * V_115 = NULL ;
V_64 * V_73 ;
if( V_56 == NULL )
return NULL ;
V_115 = F_73 ( V_56 ) ;
if( V_115 == NULL )
return NULL ;
if ( V_115 -> V_116 == NULL )
return NULL ;
V_73 = F_3 ( F_4 () , V_115 -> V_116 -> V_117 ) ;
return V_73 ;
}
void
F_74 ( T_7 * V_31 , T_2 * V_33 , T_1 * V_1 , T_8 * V_32 , const T_21 * V_58 , T_9 V_118 )
{
T_10 * V_56 = F_25 ( V_31 ) ;
T_5 * V_63 ;
T_9 V_75 ;
T_11 V_62 = FALSE ;
if( V_33 -> V_45 )
F_19 ( V_56 , L_12 , V_33 -> V_45 ) ;
F_19 ( V_56 , L_17 ) ;
for( V_75 = 0 ; V_75 < V_118 && V_58 != NULL ; V_75 ++ )
{
V_63 = F_2 ( V_33 , V_58 [ V_75 ] . V_29 ) ;
if( V_63 )
{
if( V_58 [ V_75 ] . V_119 != NULL )
{
if( V_63 -> V_29 )
F_21 ( V_31 , * V_58 [ V_75 ] . V_119 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 , L_21 , V_63 -> V_29 , V_63 -> V_7 ) ;
else
F_16 ( V_31 , * V_58 [ V_75 ] . V_119 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 ) ;
}
else
{
F_21 ( V_31 , V_120 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 ,
L_21 , V_63 -> V_29 ? V_63 -> V_29 : V_58 [ V_75 ] . V_29 , V_63 -> V_7 ) ;
}
if( V_58 [ V_75 ] . V_121 )
{
if( V_62 )
{
F_19 ( V_56 , L_18 ) ;
}
F_19 ( V_56 , L_19 , V_63 -> V_29 ? V_63 -> V_29 : V_58 [ V_75 ] . V_29 , V_63 -> V_7 ) ;
V_62 = TRUE ;
}
} else if( V_58 [ V_75 ] . V_122 )
{
F_24 ( V_1 , V_56 , & V_123 , L_29 , V_58 [ V_75 ] . V_29 , V_33 -> V_29 ) ;
}
if( V_58 [ V_75 ] . V_124 )
{
if( V_63 )
V_58 [ V_75 ] . V_124 ( V_1 , V_56 , V_58 [ V_75 ] . V_29 , V_63 -> V_7 , V_58 [ V_75 ] . V_19 ) ;
else
V_58 [ V_75 ] . V_124 ( V_1 , V_56 , V_58 [ V_75 ] . V_29 , NULL , V_58 [ V_75 ] . V_19 ) ;
}
}
F_19 ( V_56 , L_24 ) ;
F_15 ( V_31 , V_32 , V_1 , V_33 , FALSE ) ;
}
void
F_75 ( T_7 * V_31 , T_2 * V_33 , T_1 * V_1 , T_8 * V_32 , const T_22 * V_58 , T_9 V_118 )
{
T_10 * V_56 = F_25 ( V_31 ) ;
T_5 * V_63 ;
T_9 V_75 ;
T_11 V_62 = FALSE ;
T_6 * V_125 , * V_126 = F_26 ( V_33 -> V_95 ) ;
T_6 * V_127 , * V_128 = F_27 ( V_33 -> V_95 ) ;
V_125 = V_126 ;
V_127 = V_128 ;
if( V_33 -> V_45 )
F_19 ( V_56 , L_12 , V_33 -> V_45 ) ;
F_19 ( V_56 , L_17 ) ;
while( V_126 && V_128 )
{
for ( V_75 = 0 ; V_75 < V_118 && V_58 != NULL ; V_75 ++ ) {
if( strcmp ( ( const char * ) ( V_128 -> V_19 ) , V_58 [ V_75 ] . V_129 ) == 0 )
{
V_63 = F_60 ( V_33 , V_58 [ V_75 ] . V_130 . V_29 , ( const V_64 * ) ( V_126 -> V_19 ) ) ;
if( ! V_63 && V_33 -> V_45 && strcmp ( ( const char * ) V_126 -> V_19 , V_33 -> V_45 ) == 0 )
V_63 = F_60 ( V_33 , V_58 [ V_75 ] . V_130 . V_29 , L_25 ) ;
if ( V_63 ) {
if ( V_58 [ V_75 ] . V_130 . V_119 != NULL ) {
if ( V_63 -> V_29 )
F_21 ( V_31 , * V_58 [ V_75 ] . V_130 . V_119 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 , L_21 , V_63 -> V_29 , V_63 -> V_7 ) ;
else
F_16 ( V_31 , * V_58 [ V_75 ] . V_130 . V_119 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 ) ;
} else {
F_21 ( V_31 , V_120 , V_32 , V_63 -> V_39 , V_63 -> V_40 , V_63 -> V_7 ,
L_21 , V_63 -> V_29 ? V_63 -> V_29 : V_58 [ V_75 ] . V_130 . V_29 , V_63 -> V_7 ) ;
}
if ( V_58 [ V_75 ] . V_130 . V_121 ) {
if ( V_62 ) {
F_19 ( V_56 , L_18 ) ;
}
F_19 ( V_56 , L_19 , V_63 -> V_29 ? V_63 -> V_29 : V_58 [ V_75 ] . V_130 . V_29 , V_63 -> V_7 ) ;
V_62 = TRUE ;
}
} else if ( V_58 [ V_75 ] . V_130 . V_122 ) {
F_24 ( V_1 , V_56 , & V_123 , L_29 , V_58 [ V_75 ] . V_130 . V_29 , V_33 -> V_29 ) ;
}
if ( V_58 [ V_75 ] . V_130 . V_124 ) {
if ( V_63 )
V_58 [ V_75 ] . V_130 . V_124 ( V_1 , V_56 , V_58 [ V_75 ] . V_130 . V_29 , V_63 -> V_7 , V_58 [ V_75 ] . V_130 . V_19 ) ;
else
V_58 [ V_75 ] . V_130 . V_124 ( V_1 , V_56 , V_58 [ V_75 ] . V_130 . V_29 , NULL , V_58 [ V_75 ] . V_130 . V_19 ) ;
}
}
}
V_126 = V_126 -> V_46 ;
V_128 = V_128 -> V_46 ;
}
F_19 ( V_56 , L_24 ) ;
F_15 ( V_31 , V_32 , V_1 , V_33 , FALSE ) ;
F_29 ( V_125 ) ;
F_29 ( V_127 ) ;
}
V_74
F_76 ( const V_64 * V_29 , const V_64 * V_84 , const V_64 * V_85 )
{
T_23 * V_73 ;
V_73 = F_7 ( F_4 () , T_23 ) ;
V_73 -> V_29 = V_29 ;
V_73 -> V_84 = V_84 ;
V_73 -> V_85 = V_85 ;
return V_73 ;
}
void
F_77 ( T_7 * V_31 , T_2 * V_88 , T_1 * V_1 , T_8 * V_32 , T_24 * V_131 , T_9 V_118 )
{
T_9 V_75 ;
for( V_75 = 0 ; V_75 < V_118 && V_131 != NULL ; V_75 ++ )
{
T_2 * V_91 = NULL ;
if( V_131 [ V_75 ] . type == V_132 )
{
T_11 V_133 = TRUE ;
T_23 * V_76 = ( T_23 * ) ( V_131 [ V_75 ] . V_19 ) ;
while( V_133 && ( V_91 = F_42 ( V_88 , V_76 -> V_29 , V_76 -> V_84 , V_76 -> V_85 ) ) != NULL )
{
V_131 [ V_75 ] . F_78 ( V_31 , V_32 , V_1 , V_91 ) ;
if( V_131 [ V_75 ] . V_134 == V_135 )
V_133 = FALSE ;
}
} else if( V_131 [ V_75 ] . type == V_136 )
{
T_11 V_133 = TRUE ;
const V_64 * V_29 = ( const V_64 * ) ( V_131 [ V_75 ] . V_19 ) ;
while( V_133 && ( V_91 = F_39 ( V_88 , V_29 ) ) != NULL )
{
V_131 [ V_75 ] . F_78 ( V_31 , V_32 , V_1 , V_91 ) ;
if( V_131 [ V_75 ] . V_134 == V_135 )
V_133 = FALSE ;
}
}
else if( V_131 [ V_75 ] . type == V_137 )
{
T_11 V_133 = TRUE ;
T_23 * V_63 = ( T_23 * ) ( V_131 [ V_75 ] . V_19 ) ;
while( V_133 && ( V_91 = F_41 ( V_88 , V_63 -> V_84 , V_63 -> V_85 ) ) != NULL )
{
V_131 [ V_75 ] . F_78 ( V_31 , V_32 , V_1 , V_91 ) ;
if( V_131 [ V_75 ] . V_134 == V_135 )
V_133 = FALSE ;
}
} else if( V_131 [ V_75 ] . type == V_138 )
{
T_11 V_133 = TRUE ;
const T_13 * V_81 = ( const T_13 * ) ( V_131 [ V_75 ] . V_19 ) ;
while( V_133 && ( V_91 = F_40 ( V_88 , ( const V_64 * * ) V_81 -> V_19 , V_81 -> V_40 ) ) != NULL )
{
V_131 [ V_75 ] . F_78 ( V_31 , V_32 , V_1 , V_91 ) ;
if( V_131 [ V_75 ] . V_134 == V_135 )
V_133 = FALSE ;
}
}
}
F_20 ( V_31 , V_32 , V_1 , V_88 ) ;
}
void
F_79 ( T_1 * V_1 , T_10 * V_56 , const V_64 * V_29 , const V_64 * V_7 , T_14 V_19 )
{
const T_13 * V_139 = ( const T_13 * ) V_19 ;
T_12 V_75 ;
T_11 V_140 = FALSE ;
V_64 * * V_141 = ( char * * ) V_139 -> V_19 ;
if ( V_7 != NULL ) {
for ( V_75 = 0 ; V_75 < V_139 -> V_40 ; V_75 ++ ) {
if ( strcmp ( V_7 , V_141 [ V_75 ] ) == 0 ) {
V_140 = TRUE ;
break;
}
}
if ( ! V_140 ) {
F_24 ( V_1 , V_56 , & V_142 , L_30 , V_29 , V_7 ) ;
}
}
}
void
F_80 ( const V_64 * V_143 , const V_64 * V_84 , T_2 * V_88 , T_5 * (* F_81)( T_2 * V_33 ) )
{
T_2 * V_33 = NULL ;
T_5 * V_144 = NULL ;
V_33 = F_39 ( V_88 , V_143 ) ;
if( V_33 )
V_144 = F_81 ( V_33 ) ;
if( V_144 )
F_48 ( V_88 -> V_58 , ( V_74 ) V_84 , V_144 ) ;
}
T_5 *
F_82 ( T_2 * V_91 )
{
T_5 * V_73 = F_35 ( V_91 -> V_19 ? V_91 -> V_19 -> V_7 : L_25 , V_91 -> V_39 , V_91 -> V_40 ) ;
return V_73 ;
}
static void
F_83 ( V_74 V_109 , V_74 V_7 , V_74 V_110 )
{
T_25 * V_145 = ( T_25 * ) V_110 ;
F_48 ( V_145 , V_109 , V_7 ) ;
}
void F_47 ( T_25 * V_146 , T_25 * V_145 )
{
F_84 ( V_146 , F_83 , V_145 ) ;
}
