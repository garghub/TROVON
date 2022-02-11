static void
F_1 ( T_1 * T_2 V_1 , T_1 * V_2 )
{
T_1 * V_3 , * V_4 ;
T_3 * V_5 ;
const char * V_6 = L_1 ;
#ifdef F_2
V_4 = F_3 ( L_2 ) ;
#else
V_4 = F_3 ( V_7 ) ;
#endif
F_4 ( F_5 ( V_2 ) , V_4 , TRUE , TRUE , 0 ) ;
V_3 = F_6 ( V_6 ) ;
V_5 = F_7 ( L_3 , V_6 ) ;
F_8 ( F_9 ( V_3 ) , V_5 ) ;
F_10 ( V_5 ) ;
F_4 ( F_5 ( V_2 ) , V_3 , TRUE , TRUE , 0 ) ;
}
static void
F_11 ( T_1 * V_8 , const char * V_5 )
{
T_1 * V_9 ;
if ( V_8 == NULL ) return;
V_9 = ( T_1 * ) F_12 ( F_13 ( V_8 ) , L_4 ) ;
F_14 ( F_9 ( V_9 ) , V_5 ) ;
while ( F_15 () ) F_16 () ;
}
T_1 *
F_17 ( const char * V_5 )
{
T_1 * V_8 ;
T_1 * V_9 ;
T_1 * V_10 ;
T_1 * V_11 ;
T_1 * V_12 ;
T_1 * V_13 ;
V_8 = F_18 () ;
F_19 ( V_8 ) ;
V_10 = F_20 ( V_14 , 6 , FALSE ) ;
F_21 ( F_22 ( V_10 ) , 24 ) ;
F_23 ( F_22 ( V_8 ) , V_10 ) ;
F_1 ( V_8 , V_10 ) ;
V_9 = F_6 ( V_5 ) ;
F_4 ( F_5 ( V_10 ) , V_9 , TRUE , TRUE , 0 ) ;
F_24 ( F_13 ( V_8 ) , L_4 , V_9 ) ;
V_9 = F_6 ( L_5 ) ;
F_4 ( F_5 ( V_10 ) , V_9 , TRUE , TRUE , 0 ) ;
F_24 ( F_13 ( V_8 ) , L_6 , V_9 ) ;
V_11 = F_20 ( V_15 , 1 , FALSE ) ;
F_4 ( F_5 ( V_10 ) , V_11 , TRUE , TRUE , 3 ) ;
V_12 = F_25 () ;
F_4 ( F_5 ( V_11 ) , V_12 , TRUE , TRUE , 3 ) ;
F_24 ( F_13 ( V_8 ) , L_7 , V_12 ) ;
V_13 = F_6 ( L_8 ) ;
F_26 ( F_27 ( V_13 ) , 0.0f , 0.0f ) ;
F_4 ( F_5 ( V_11 ) , V_13 , FALSE , TRUE , 3 ) ;
F_24 ( F_13 ( V_8 ) , L_9 , V_13 ) ;
F_28 ( V_8 ) ;
F_11 ( V_8 , V_5 ) ;
return V_8 ;
}
void
F_29 ( T_4 V_16 , const char * V_5 , T_5 V_17 )
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
F_30 ( & V_26 ) ;
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
V_21 = L_10 ;
break;
case V_32 :
V_21 = L_11 ;
break;
case V_33 :
V_21 = L_12 ;
break;
case V_34 :
V_21 = L_13 ;
break;
case V_35 :
V_21 = L_14 ;
break;
case V_36 :
V_21 = L_15 ;
break;
case V_37 :
V_21 = L_16 ;
break;
case V_38 :
V_21 = L_17 ;
break;
case V_39 :
V_21 = L_18 ;
break;
default:
V_21 = L_19 ;
break;
}
F_11 ( V_8 , V_21 ) ;
V_24 = V_16 ;
}
if( V_23 == 0 ) {
V_23 = F_31 () + 6 ;
#ifdef F_32
V_23 += F_33 () ;
#endif
}
V_9 = ( T_1 * ) F_12 ( F_13 ( V_8 ) , L_6 ) ;
if( V_5 ) {
if( ! strncmp ( V_5 , L_20 , 15 ) )
V_5 += 15 ;
else if( ! strncmp ( V_5 , L_21 , 18 ) )
V_5 += 18 ;
}
F_14 ( F_9 ( V_9 ) , V_5 ? V_5 : L_5 ) ;
V_22 ++ ;
F_34 ( V_22 <= V_23 ) ;
V_18 = ( T_6 ) V_22 / ( T_6 ) V_23 ;
V_19 = ( T_7 ) ( V_18 * 100 ) ;
V_12 = ( T_1 * ) F_12 ( F_13 ( V_8 ) , L_7 ) ;
F_35 ( F_36 ( V_12 ) , V_18 ) ;
V_13 = ( T_1 * ) F_12 ( F_13 ( V_8 ) , L_9 ) ;
F_37 ( V_20 , sizeof( V_20 ) , L_22 , V_19 ) ;
F_14 ( ( V_40 * ) V_13 , V_20 ) ;
while ( F_15 () ) F_16 () ;
}
T_9
F_38 ( T_1 * V_8 )
{
if ( V_8 == NULL )
return FALSE ;
F_39 ( V_8 ) ;
return FALSE ;
}
static T_1 *
F_40 ( void )
{
T_1 * V_10 , * V_3 ;
T_3 * V_5 ;
V_10 = F_20 ( V_14 , 6 , FALSE ) ;
F_21 ( F_22 ( V_10 ) , 12 ) ;
F_41 ( F_42 ( V_10 ) ,
L_23 , FALSE , NULL ) ;
F_1 ( V_41 , V_10 ) ;
V_5 = F_7 (
L_24
L_25
L_26
L_25
L_26
L_25
L_26
L_25
L_27
L_25
L_28 ,
F_43 () , F_44 () , V_42 -> V_43 ,
V_44 -> V_43 ) ;
V_3 = F_6 ( V_5 ) ;
F_10 ( V_5 ) ;
F_45 ( F_9 ( V_3 ) , V_45 ) ;
F_46 ( F_9 ( V_3 ) , TRUE ) ;
F_4 ( F_5 ( V_10 ) , V_3 , TRUE , TRUE , 0 ) ;
return V_10 ;
}
static T_1 *
F_47 ( void )
{
T_1 * V_46 ;
char * V_47 ;
V_47 = F_48 ( L_29 ) ;
V_46 = F_49 ( V_47 ) ;
return V_46 ;
}
static T_9 F_50 ( T_1 * V_48 , T_10 * V_49 , T_11 T_12 V_1 )
{
T_13 * V_50 ;
T_14 * V_51 ;
T_15 V_52 ;
T_3 * V_53 ;
V_50 = F_51 ( F_52 ( V_48 ) ) ;
if( F_53 ( V_50 ) == 0 )
return FALSE ;
if( V_49 -> type != V_54 )
return FALSE ;
if( F_54 ( V_50 , & V_51 , & V_52 ) ) {
F_55 ( V_51 , & V_52 , 1 , & V_53 , - 1 ) ;
F_56 ( V_53 ) ;
F_10 ( V_53 ) ;
}
return TRUE ;
}
static void
F_57 ( T_1 * V_55 , const char * V_56 , const char * V_57 , const char * V_58 )
{
F_58 ( V_55 , 0 , V_56 , 1 , V_57 , 2 , V_58 , - 1 ) ;
}
static T_1 *
F_59 ( void )
{
T_1 * V_55 ;
const char * V_59 ;
char * V_53 ;
static const T_3 * V_60 [] = { L_30 , L_31 , L_32 } ;
T_1 * V_61 ;
#if F_60 ( V_62 ) || F_60 ( V_63 ) || F_60 ( V_64 )
T_11 V_65 ;
T_3 * * V_66 ;
#endif
#if 0
const gchar *const *dirs;
#endif
V_61 = F_61 ( NULL , NULL ) ;
F_62 ( F_63 ( V_61 ) ,
V_67 ) ;
V_55 = F_64 ( 3 , V_60 ) ;
F_65 ( V_55 , L_33 ,
F_66 ( F_50 ) , NULL ) ;
F_67 ( V_55 , 1 ) ;
F_57 ( V_55 , L_34 , F_68 () ,
L_35 ) ;
F_57 ( V_55 , L_36 , F_69 () ,
L_37 ) ;
V_53 = F_70 ( L_5 , FALSE ) ;
F_57 ( V_55 , L_38 , V_53 ,
L_39 ) ;
F_10 ( V_53 ) ;
V_59 = F_71 () ;
if ( V_59 != NULL ) {
F_57 ( V_55 , L_40 , V_59 ,
L_41 ) ;
}
#if 0
dirs = g_get_system_data_dirs ();
for (i = 0; dirs[i]; i++){
g_warning("glibs data path %u %s",i+1,dirs[i]);
}
#endif
V_59 = F_72 () ;
F_57 ( V_55 , L_42 , V_59 ,
L_43 ) ;
V_59 = F_73 () ;
F_57 ( V_55 , L_44 , V_59 ,
L_45 ) ;
#if F_60 ( V_68 ) || F_60 ( F_32 )
V_53 = F_74 () ;
F_57 ( V_55 , L_46 , V_53 ,
L_47 ) ;
F_10 ( V_53 ) ;
F_57 ( V_55 , L_48 , F_75 () ,
L_47 ) ;
#endif
#ifdef V_63
V_53 = F_76 () ;
V_66 = F_77 ( V_53 , V_69 , 10 ) ;
for( V_65 = 0 ; V_66 [ V_65 ] ; V_65 ++ )
F_57 ( V_55 , L_49 , F_78 ( V_66 [ V_65 ] ) ,
L_50 ) ;
F_79 ( V_66 ) ;
F_10 ( V_53 ) ;
#endif
#ifdef V_62
V_53 = F_80 () ;
V_66 = F_77 ( V_53 , V_69 , 10 ) ;
for( V_65 = 0 ; V_66 [ V_65 ] ; V_65 ++ )
F_57 ( V_55 , L_51 , F_78 ( V_66 [ V_65 ] ) ,
L_52 ) ;
F_79 ( V_66 ) ;
F_10 ( V_53 ) ;
#endif
#ifdef V_64
V_59 = F_81 () ;
V_66 = F_77 ( V_59 , V_69 , 10 ) ;
for( V_65 = 0 ; V_66 [ V_65 ] ; V_65 ++ )
F_57 ( V_55 , L_53 , F_78 ( V_66 [ V_65 ] ) ,
L_54 ) ;
F_79 ( V_66 ) ;
#endif
F_23 ( F_22 ( V_61 ) , V_55 ) ;
return V_61 ;
}
static T_1 *
F_82 ( void )
{
T_1 * V_46 ;
char * V_47 ;
#if F_60 ( V_70 )
V_47 = F_48 ( L_55 ) ;
#else
V_47 = F_48 ( L_56 ) ;
#endif
V_46 = F_49 ( V_47 ) ;
return V_46 ;
}
void
F_83 ( T_1 * T_16 V_1 , T_5 T_17 V_1 )
{
T_1 * V_10 , * V_71 , * V_72 , * V_73 ;
T_1 * V_74 , * V_75 , * V_76 ;
#if F_60 ( V_68 ) || F_60 ( F_32 )
T_1 * V_77 ;
#endif
T_1 * V_78 , * V_79 ;
if ( V_80 != NULL ) {
F_84 ( V_80 ) ;
return;
}
V_80 = F_85 ( L_57 ) ;
F_86 ( F_87 ( V_80 ) , V_81 ) ;
F_88 ( F_87 ( V_80 ) , 600 , 400 ) ;
F_21 ( F_22 ( V_80 ) , 6 ) ;
V_10 = F_20 ( V_14 , 12 , FALSE ) ;
F_21 ( F_22 ( V_10 ) , 6 ) ;
F_23 ( F_22 ( V_80 ) , V_10 ) ;
V_71 = F_89 () ;
F_4 ( F_5 ( V_10 ) , V_71 , TRUE , TRUE , 0 ) ;
V_75 = F_40 () ;
V_74 = F_6 ( L_58 ) ;
F_90 ( F_91 ( V_71 ) , V_75 , V_74 ) ;
V_78 = F_47 () ;
V_74 = F_6 ( L_59 ) ;
F_90 ( F_91 ( V_71 ) , V_78 , V_74 ) ;
V_76 = F_59 () ;
V_74 = F_6 ( L_60 ) ;
F_90 ( F_91 ( V_71 ) , V_76 , V_74 ) ;
#if F_60 ( V_68 ) || F_60 ( F_32 )
V_77 = F_92 () ;
V_74 = F_6 ( L_61 ) ;
F_90 ( F_91 ( V_71 ) , V_77 , V_74 ) ;
#endif
V_79 = F_82 () ;
V_74 = F_6 ( L_62 ) ;
F_93 ( V_79 , 600 , - 1 ) ;
F_90 ( F_91 ( V_71 ) , V_79 , V_74 ) ;
V_72 = F_94 ( V_82 , NULL ) ;
F_4 ( F_5 ( V_10 ) , V_72 , FALSE , FALSE , 0 ) ;
V_73 = ( T_1 * ) F_12 ( F_13 ( V_72 ) , V_82 ) ;
F_95 ( V_73 ) ;
F_96 ( V_73 ) ;
F_97 ( V_80 , V_73 , V_83 ) ;
F_65 ( V_80 , L_63 , F_66 ( V_84 ) , NULL ) ;
F_65 ( V_80 , L_64 , F_66 ( V_85 ) , NULL ) ;
F_28 ( V_80 ) ;
F_98 ( V_80 ) ;
}
static void
V_85 ( T_1 * V_8 V_1 , T_5 T_18 V_1 )
{
V_80 = NULL ;
}
