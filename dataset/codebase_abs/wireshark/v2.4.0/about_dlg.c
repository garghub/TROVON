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
case V_40 :
V_21 = L_19 ;
break;
default:
V_21 = L_20 ;
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
#ifdef F_34
V_23 += F_35 () + 1 ;
#endif
}
V_9 = ( T_1 * ) F_12 ( F_13 ( V_8 ) , L_6 ) ;
if( V_5 ) {
if( ! strncmp ( V_5 , L_21 , 15 ) )
V_5 += 15 ;
else if( ! strncmp ( V_5 , L_22 , 18 ) )
V_5 += 18 ;
}
F_14 ( F_9 ( V_9 ) , V_5 ? V_5 : L_5 ) ;
V_22 ++ ;
F_36 ( V_22 <= V_23 ) ;
V_18 = ( T_6 ) V_22 / ( T_6 ) V_23 ;
V_19 = ( T_7 ) ( V_18 * 100 ) ;
V_12 = ( T_1 * ) F_12 ( F_13 ( V_8 ) , L_7 ) ;
F_37 ( F_38 ( V_12 ) , V_18 ) ;
V_13 = ( T_1 * ) F_12 ( F_13 ( V_8 ) , L_9 ) ;
F_39 ( V_20 , sizeof( V_20 ) , L_23 , V_19 ) ;
F_14 ( ( V_41 * ) V_13 , V_20 ) ;
while ( F_15 () ) F_16 () ;
}
T_9
F_40 ( T_1 * V_8 )
{
if ( V_8 == NULL )
return FALSE ;
F_41 ( V_8 ) ;
return FALSE ;
}
static T_1 *
F_42 ( void )
{
T_1 * V_10 , * V_3 ;
T_3 * V_5 ;
T_10 * V_42 , * V_43 ;
V_10 = F_20 ( V_14 , 6 , FALSE ) ;
F_21 ( F_22 ( V_10 ) , 12 ) ;
F_43 ( F_44 ( V_10 ) ,
L_24 , FALSE , NULL ) ;
F_1 ( V_44 , V_10 ) ;
V_42 = F_45 ( V_45 ,
V_46 ) ;
V_43 = F_46 ( V_47 ) ;
V_5 = F_7 (
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
F_47 () , F_48 () , V_42 -> V_48 ,
V_43 -> V_48 ) ;
V_3 = F_6 ( V_5 ) ;
F_10 ( V_5 ) ;
F_49 ( F_9 ( V_3 ) , V_49 ) ;
F_50 ( F_9 ( V_3 ) , TRUE ) ;
F_4 ( F_5 ( V_10 ) , V_3 , TRUE , TRUE , 0 ) ;
return V_10 ;
}
static T_1 *
F_51 ( void )
{
T_1 * V_50 ;
char * V_51 ;
V_51 = F_52 ( L_30 ) ;
V_50 = F_53 ( V_51 ) ;
return V_50 ;
}
static T_9 F_54 ( T_1 * V_52 , T_11 * V_53 , T_12 T_13 V_1 )
{
T_14 * V_54 ;
T_15 * V_55 ;
T_16 V_56 ;
T_3 * V_57 ;
V_54 = F_55 ( F_56 ( V_52 ) ) ;
if( F_57 ( V_54 ) == 0 )
return FALSE ;
if( V_53 -> type != V_58 )
return FALSE ;
if( F_58 ( V_54 , & V_55 , & V_56 ) ) {
F_59 ( V_55 , & V_56 , 1 , & V_57 , - 1 ) ;
F_60 ( V_57 ) ;
F_10 ( V_57 ) ;
}
return TRUE ;
}
static void
F_61 ( T_1 * V_59 , const char * V_60 , const char * V_61 , const char * V_62 )
{
F_62 ( V_59 , 0 , V_60 , 1 , V_61 , 2 , V_62 , - 1 ) ;
}
static T_1 *
F_63 ( void )
{
T_1 * V_59 ;
const char * V_63 ;
char * V_57 ;
static const T_3 * V_64 [] = { L_31 , L_32 , L_33 } ;
T_1 * V_65 ;
#if F_64 ( V_66 ) || F_64 ( V_67 ) || F_64 ( F_34 )
T_12 V_68 ;
T_3 * * V_69 ;
#endif
#if 0
const gchar *const *dirs;
#endif
V_65 = F_65 ( NULL , NULL ) ;
F_66 ( F_67 ( V_65 ) ,
V_70 ) ;
V_59 = F_68 ( 3 , V_64 ) ;
F_69 ( V_59 , L_34 ,
F_70 ( F_54 ) , NULL ) ;
F_71 ( V_59 , 1 ) ;
F_61 ( V_59 , L_35 , F_72 () ,
L_36 ) ;
F_61 ( V_59 , L_37 , F_73 () ,
L_38 ) ;
V_57 = F_74 ( L_5 , FALSE ) ;
F_61 ( V_59 , L_39 , V_57 ,
L_40 ) ;
F_10 ( V_57 ) ;
V_63 = F_75 () ;
if ( V_63 != NULL ) {
F_61 ( V_59 , L_41 , V_63 ,
L_42 ) ;
}
#if 0
dirs = g_get_system_data_dirs ();
for (i = 0; dirs[i]; i++){
g_warning("glibs data path %u %s",i+1,dirs[i]);
}
#endif
V_63 = F_76 () ;
F_61 ( V_59 , L_43 , V_63 ,
L_44 ) ;
V_63 = F_77 () ;
F_61 ( V_59 , L_45 , V_63 ,
L_46 ) ;
#if F_64 ( V_71 ) || F_64 ( F_32 )
V_57 = F_78 () ;
F_61 ( V_59 , L_47 , V_57 ,
L_48 ) ;
F_10 ( V_57 ) ;
F_61 ( V_59 , L_49 , F_79 () ,
L_48 ) ;
#endif
#ifdef V_67
V_57 = F_80 () ;
V_69 = F_81 ( V_57 , V_72 , 10 ) ;
for( V_68 = 0 ; V_69 [ V_68 ] ; V_68 ++ )
F_61 ( V_59 , L_50 , F_82 ( V_69 [ V_68 ] ) ,
L_51 ) ;
F_83 ( V_69 ) ;
F_10 ( V_57 ) ;
#endif
#ifdef V_66
V_57 = F_84 () ;
V_69 = F_81 ( V_57 , V_72 , 10 ) ;
for( V_68 = 0 ; V_69 [ V_68 ] ; V_68 ++ )
F_61 ( V_59 , L_52 , F_82 ( V_69 [ V_68 ] ) ,
L_53 ) ;
F_83 ( V_69 ) ;
F_10 ( V_57 ) ;
#endif
#ifdef F_34
V_63 = F_85 () ;
V_69 = F_81 ( V_63 , V_72 , 10 ) ;
for( V_68 = 0 ; V_69 [ V_68 ] ; V_68 ++ )
F_61 ( V_59 , L_54 , F_82 ( V_69 [ V_68 ] ) ,
L_55 ) ;
F_83 ( V_69 ) ;
#endif
F_23 ( F_22 ( V_65 ) , V_59 ) ;
return V_65 ;
}
static T_1 *
F_86 ( void )
{
T_1 * V_50 ;
char * V_51 ;
#if F_64 ( V_73 )
V_51 = F_52 ( L_56 ) ;
#else
V_51 = F_52 ( L_57 ) ;
#endif
V_50 = F_53 ( V_51 ) ;
return V_50 ;
}
void
F_87 ( T_1 * T_17 V_1 , T_5 T_18 V_1 )
{
T_1 * V_10 , * V_74 , * V_75 , * V_76 ;
T_1 * V_77 , * V_78 , * V_79 ;
#if F_64 ( V_71 ) || F_64 ( F_32 )
T_1 * V_80 ;
#endif
T_1 * V_81 , * V_82 ;
if ( V_83 != NULL ) {
F_88 ( V_83 ) ;
return;
}
V_83 = F_89 ( L_58 ) ;
F_90 ( F_91 ( V_83 ) , V_84 ) ;
F_92 ( F_91 ( V_83 ) , 600 , 400 ) ;
F_21 ( F_22 ( V_83 ) , 6 ) ;
V_10 = F_20 ( V_14 , 12 , FALSE ) ;
F_21 ( F_22 ( V_10 ) , 6 ) ;
F_23 ( F_22 ( V_83 ) , V_10 ) ;
V_74 = F_93 () ;
F_4 ( F_5 ( V_10 ) , V_74 , TRUE , TRUE , 0 ) ;
V_78 = F_42 () ;
V_77 = F_6 ( L_59 ) ;
F_94 ( F_95 ( V_74 ) , V_78 , V_77 ) ;
V_81 = F_51 () ;
V_77 = F_6 ( L_60 ) ;
F_94 ( F_95 ( V_74 ) , V_81 , V_77 ) ;
V_79 = F_63 () ;
V_77 = F_6 ( L_61 ) ;
F_94 ( F_95 ( V_74 ) , V_79 , V_77 ) ;
#if F_64 ( V_71 ) || F_64 ( F_32 )
V_80 = F_96 () ;
V_77 = F_6 ( L_62 ) ;
F_94 ( F_95 ( V_74 ) , V_80 , V_77 ) ;
#endif
V_82 = F_86 () ;
V_77 = F_6 ( L_63 ) ;
F_97 ( V_82 , 600 , - 1 ) ;
F_94 ( F_95 ( V_74 ) , V_82 , V_77 ) ;
V_75 = F_98 ( V_85 , NULL ) ;
F_4 ( F_5 ( V_10 ) , V_75 , FALSE , FALSE , 0 ) ;
V_76 = ( T_1 * ) F_12 ( F_13 ( V_75 ) , V_85 ) ;
F_99 ( V_76 ) ;
F_100 ( V_76 ) ;
F_101 ( V_83 , V_76 , V_86 ) ;
F_69 ( V_83 , L_64 , F_70 ( V_87 ) , NULL ) ;
F_69 ( V_83 , L_65 , F_70 ( V_88 ) , NULL ) ;
F_28 ( V_83 ) ;
F_102 ( V_83 ) ;
}
static void
V_88 ( T_1 * V_8 V_1 , T_5 T_19 V_1 )
{
V_83 = NULL ;
}
