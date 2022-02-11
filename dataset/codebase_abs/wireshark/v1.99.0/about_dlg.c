static void
F_1 ( T_1 * T_2 V_1 , T_1 * V_2 )
{
T_1 * V_3 , * V_4 ;
T_3 * V_5 ;
const char * V_6 = L_1 ;
V_4 = F_2 ( V_7 ) ;
F_3 ( F_4 ( V_2 ) , V_4 , TRUE , TRUE , 0 ) ;
V_3 = F_5 ( V_6 ) ;
V_5 = F_6 ( L_2 , V_6 ) ;
F_7 ( F_8 ( V_3 ) , V_5 ) ;
F_9 ( V_5 ) ;
F_3 ( F_4 ( V_2 ) , V_3 , TRUE , TRUE , 0 ) ;
}
static void
F_10 ( T_1 * V_8 , const char * V_5 )
{
T_1 * V_9 ;
if ( V_8 == NULL ) return;
V_9 = ( T_1 * ) F_11 ( F_12 ( V_8 ) , L_3 ) ;
F_13 ( F_8 ( V_9 ) , V_5 ) ;
while ( F_14 () ) F_15 () ;
}
T_1 *
F_16 ( const char * V_5 )
{
T_1 * V_8 ;
T_1 * V_9 ;
T_1 * V_10 ;
T_1 * V_11 ;
T_1 * V_12 ;
T_1 * V_13 ;
V_8 = F_17 () ;
F_18 ( V_8 ) ;
V_10 = F_19 ( V_14 , 6 , FALSE ) ;
F_20 ( F_21 ( V_10 ) , 24 ) ;
F_22 ( F_21 ( V_8 ) , V_10 ) ;
F_1 ( V_8 , V_10 ) ;
V_9 = F_5 ( V_5 ) ;
F_3 ( F_4 ( V_10 ) , V_9 , TRUE , TRUE , 0 ) ;
F_23 ( F_12 ( V_8 ) , L_3 , V_9 ) ;
V_9 = F_5 ( L_4 ) ;
F_3 ( F_4 ( V_10 ) , V_9 , TRUE , TRUE , 0 ) ;
F_23 ( F_12 ( V_8 ) , L_5 , V_9 ) ;
V_11 = F_19 ( V_15 , 1 , FALSE ) ;
F_3 ( F_4 ( V_10 ) , V_11 , TRUE , TRUE , 3 ) ;
V_12 = F_24 () ;
F_3 ( F_4 ( V_11 ) , V_12 , TRUE , TRUE , 3 ) ;
F_23 ( F_12 ( V_8 ) , L_6 , V_12 ) ;
V_13 = F_5 ( L_7 ) ;
F_25 ( F_26 ( V_13 ) , 0.0f , 0.0f ) ;
F_3 ( F_4 ( V_11 ) , V_13 , FALSE , TRUE , 3 ) ;
F_23 ( F_12 ( V_8 ) , L_8 , V_13 ) ;
F_27 ( V_8 ) ;
F_10 ( V_8 , V_5 ) ;
return V_8 ;
}
void
F_28 ( T_4 V_16 , const char * V_5 , T_5 V_17 )
{
T_1 * V_8 ;
T_1 * V_9 ;
T_1 * V_12 ;
T_1 * V_13 ;
T_6 V_18 ;
T_7 V_19 ;
T_3 V_20 [ 100 ] ;
const char * V_21 ;
static T_7 V_22 = 0 ;
static T_7 V_23 = 0 ;
static T_4 V_24 = V_25 ;
static T_8 V_26 ;
static T_8 V_27 = { 0 , 0 } ;
V_8 = ( T_1 * ) V_17 ;
if ( V_8 == NULL ) return;
F_29 ( & V_26 ) ;
if ( V_24 == V_16 && V_26 . V_28 <= V_27 . V_28 && V_26 . V_29 <= V_27 . V_29 && V_22 < V_23 - 1 ) {
V_22 ++ ;
return;
}
memcpy ( & V_27 , & V_26 , sizeof( V_27 ) ) ;
V_27 . V_29 += V_30 * 1000 ;
if ( V_27 . V_29 >= 1000000 ) {
V_27 . V_28 ++ ;
V_27 . V_29 -= 1000000 ;
}
if( V_24 != V_16 ) {
switch( V_16 ) {
case V_31 :
V_21 = L_9 ;
break;
case V_32 :
V_21 = L_10 ;
break;
case V_33 :
V_21 = L_11 ;
break;
case V_34 :
V_21 = L_12 ;
break;
case V_35 :
V_21 = L_13 ;
break;
case V_36 :
V_21 = L_14 ;
break;
case V_37 :
V_21 = L_15 ;
break;
case V_38 :
V_21 = L_16 ;
break;
case V_39 :
V_21 = L_17 ;
break;
case V_40 :
V_21 = L_18 ;
break;
case V_41 :
V_21 = L_19 ;
break;
default:
V_21 = L_20 ;
break;
}
F_10 ( V_8 , V_21 ) ;
V_24 = V_16 ;
}
if( V_23 == 0 ) {
V_23 = F_30 () + 6 ;
#ifdef F_31
V_23 += F_32 () ;
#endif
}
V_9 = ( T_1 * ) F_11 ( F_12 ( V_8 ) , L_5 ) ;
if( V_5 ) {
if( ! strncmp ( V_5 , L_21 , 15 ) )
V_5 += 15 ;
else if( ! strncmp ( V_5 , L_22 , 18 ) )
V_5 += 18 ;
}
F_13 ( F_8 ( V_9 ) , V_5 ? V_5 : L_4 ) ;
V_22 ++ ;
F_33 ( V_22 <= V_23 ) ;
V_18 = ( T_6 ) V_22 / ( T_6 ) V_23 ;
V_19 = ( T_7 ) ( V_18 * 100 ) ;
V_12 = ( T_1 * ) F_11 ( F_12 ( V_8 ) , L_6 ) ;
F_34 ( F_35 ( V_12 ) , V_18 ) ;
V_13 = ( T_1 * ) F_11 ( F_12 ( V_8 ) , L_8 ) ;
F_36 ( V_20 , sizeof( V_20 ) , L_23 , V_19 ) ;
F_13 ( ( V_42 * ) V_13 , V_20 ) ;
while ( F_14 () ) F_15 () ;
}
T_9
F_37 ( T_1 * V_8 )
{
if ( V_8 == NULL )
return FALSE ;
F_38 ( V_8 ) ;
return FALSE ;
}
static T_1 *
F_39 ( void )
{
T_1 * V_10 , * V_3 ;
T_3 * V_5 ;
V_10 = F_19 ( V_14 , 6 , FALSE ) ;
F_20 ( F_21 ( V_10 ) , 12 ) ;
F_40 ( F_41 ( V_10 ) ,
L_24 , FALSE , NULL ) ;
F_1 ( V_43 , V_10 ) ;
V_5 = F_6 (
L_25
L_26
L_27
L_26
L_27
L_26
L_27
L_26
L_28
L_26
L_29 ,
F_42 () , F_43 () , V_44 -> V_45 ,
V_46 -> V_45 ) ;
V_3 = F_5 ( V_5 ) ;
F_9 ( V_5 ) ;
F_44 ( F_8 ( V_3 ) , V_47 ) ;
F_45 ( F_8 ( V_3 ) , TRUE ) ;
F_3 ( F_4 ( V_10 ) , V_3 , TRUE , TRUE , 0 ) ;
return V_10 ;
}
static T_1 *
F_46 ( void )
{
T_1 * V_48 ;
char * V_49 ;
V_49 = F_47 ( L_30 ) ;
V_48 = F_48 ( V_49 ) ;
return V_48 ;
}
static T_9 F_49 ( T_1 * V_50 , T_10 * V_51 , T_11 T_12 V_1 )
{
T_13 * V_52 ;
T_14 * V_53 ;
T_15 V_54 ;
T_3 * V_55 ;
V_52 = F_50 ( F_51 ( V_50 ) ) ;
if( F_52 ( V_52 ) == 0 )
return FALSE ;
if( V_51 -> type != V_56 )
return FALSE ;
if( F_53 ( V_52 , & V_53 , & V_54 ) ) {
F_54 ( V_53 , & V_54 , 1 , & V_55 , - 1 ) ;
F_55 ( V_55 ) ;
F_9 ( V_55 ) ;
}
return TRUE ;
}
static void
F_56 ( T_1 * V_57 , const char * V_58 , const char * V_59 , const char * V_60 )
{
F_57 ( V_57 , 0 , V_58 , 1 , V_59 , 2 , V_60 , - 1 ) ;
}
static T_1 *
F_58 ( void )
{
T_1 * V_57 ;
const char * V_61 ;
char * V_55 ;
static const T_3 * V_62 [] = { L_31 , L_32 , L_33 } ;
T_1 * V_63 ;
#if F_59 ( V_64 ) || F_59 ( V_65 ) || F_59 ( V_66 )
T_11 V_67 ;
T_3 * * V_68 ;
#endif
#if 0
const gchar * const *dirs;
#endif
V_63 = F_60 ( NULL , NULL ) ;
F_61 ( F_62 ( V_63 ) ,
V_69 ) ;
V_57 = F_63 ( 3 , V_62 ) ;
F_64 ( V_57 , L_34 ,
F_65 ( F_49 ) , NULL ) ;
F_66 ( V_57 , 1 ) ;
F_56 ( V_57 , L_35 , F_67 () ,
L_36 ) ;
F_56 ( V_57 , L_37 , F_68 () ,
L_38 ) ;
V_55 = F_69 ( L_4 , FALSE ) ;
F_56 ( V_57 , L_39 , V_55 ,
L_40 ) ;
F_9 ( V_55 ) ;
V_61 = F_70 () ;
if ( V_61 != NULL ) {
F_56 ( V_57 , L_41 , V_61 ,
L_42 ) ;
}
#if 0
dirs = g_get_system_data_dirs ();
for (i = 0; dirs[i]; i++){
g_warning("glibs data path %u %s",i+1,dirs[i]);
}
#endif
V_61 = F_71 () ;
F_56 ( V_57 , L_43 , V_61 ,
L_44 ) ;
V_61 = F_72 () ;
F_56 ( V_57 , L_45 , V_61 ,
L_46 ) ;
#if F_59 ( V_70 ) || F_59 ( F_31 )
V_55 = F_73 () ;
F_56 ( V_57 , L_47 , V_55 ,
L_48 ) ;
F_9 ( V_55 ) ;
F_56 ( V_57 , L_49 , F_74 () ,
L_48 ) ;
#endif
#ifdef V_65
V_55 = F_75 () ;
V_68 = F_76 ( V_55 , V_71 , 10 ) ;
for( V_67 = 0 ; V_68 [ V_67 ] ; V_67 ++ )
F_56 ( V_57 , L_50 , F_77 ( V_68 [ V_67 ] ) ,
L_51 ) ;
F_78 ( V_68 ) ;
F_9 ( V_55 ) ;
#endif
#ifdef V_64
V_55 = F_79 () ;
V_68 = F_76 ( V_55 , V_71 , 10 ) ;
for( V_67 = 0 ; V_68 [ V_67 ] ; V_67 ++ )
F_56 ( V_57 , L_52 , F_77 ( V_68 [ V_67 ] ) ,
L_53 ) ;
F_78 ( V_68 ) ;
F_9 ( V_55 ) ;
#endif
#ifdef V_66
V_61 = F_80 () ;
V_68 = F_76 ( V_61 , V_71 , 10 ) ;
for( V_67 = 0 ; V_68 [ V_67 ] ; V_67 ++ )
F_56 ( V_57 , L_54 , F_77 ( V_68 [ V_67 ] ) ,
L_55 ) ;
F_78 ( V_68 ) ;
#endif
F_22 ( F_21 ( V_63 ) , V_57 ) ;
return V_63 ;
}
static T_1 *
F_81 ( void )
{
T_1 * V_48 ;
char * V_49 ;
#if F_59 ( V_72 )
V_49 = F_47 ( L_56 ) ;
#else
V_49 = F_47 ( L_57 ) ;
#endif
V_48 = F_48 ( V_49 ) ;
return V_48 ;
}
void
F_82 ( T_1 * T_16 V_1 , T_5 T_17 V_1 )
{
T_1 * V_10 , * V_73 , * V_74 , * V_75 ;
T_1 * V_76 , * V_77 , * V_78 ;
#if F_59 ( V_70 ) || F_59 ( F_31 )
T_1 * V_79 ;
#endif
T_1 * V_80 , * V_81 ;
if ( V_82 != NULL ) {
F_83 ( V_82 ) ;
return;
}
V_82 = F_84 ( L_58 ) ;
F_85 ( F_86 ( V_82 ) , V_83 ) ;
F_87 ( F_86 ( V_82 ) , 600 , 400 ) ;
F_20 ( F_21 ( V_82 ) , 6 ) ;
V_10 = F_19 ( V_14 , 12 , FALSE ) ;
F_20 ( F_21 ( V_10 ) , 6 ) ;
F_22 ( F_21 ( V_82 ) , V_10 ) ;
V_73 = F_88 () ;
F_3 ( F_4 ( V_10 ) , V_73 , TRUE , TRUE , 0 ) ;
V_77 = F_39 () ;
V_76 = F_5 ( L_59 ) ;
F_89 ( F_90 ( V_73 ) , V_77 , V_76 ) ;
V_80 = F_46 () ;
V_76 = F_5 ( L_60 ) ;
F_89 ( F_90 ( V_73 ) , V_80 , V_76 ) ;
V_78 = F_58 () ;
V_76 = F_5 ( L_61 ) ;
F_89 ( F_90 ( V_73 ) , V_78 , V_76 ) ;
#if F_59 ( V_70 ) || F_59 ( F_31 )
V_79 = F_91 () ;
V_76 = F_5 ( L_62 ) ;
F_89 ( F_90 ( V_73 ) , V_79 , V_76 ) ;
#endif
V_81 = F_81 () ;
V_76 = F_5 ( L_63 ) ;
F_92 ( V_81 , 600 , - 1 ) ;
F_89 ( F_90 ( V_73 ) , V_81 , V_76 ) ;
V_74 = F_93 ( V_84 , NULL ) ;
F_3 ( F_4 ( V_10 ) , V_74 , FALSE , FALSE , 0 ) ;
V_75 = ( T_1 * ) F_11 ( F_12 ( V_74 ) , V_84 ) ;
F_94 ( V_75 ) ;
F_95 ( V_75 ) ;
F_96 ( V_82 , V_75 , V_85 ) ;
F_64 ( V_82 , L_64 , F_65 ( V_86 ) , NULL ) ;
F_64 ( V_82 , L_65 , F_65 ( V_87 ) , NULL ) ;
F_27 ( V_82 ) ;
F_97 ( V_82 ) ;
}
static void
V_87 ( T_1 * V_8 V_1 , T_5 T_18 V_1 )
{
V_82 = NULL ;
}
