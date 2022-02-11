T_1 * F_1 ( T_2 * V_1 , T_1 * V_2 )
{
int V_3 , V_4 ;
T_1 * V_5 = NULL , * V_6 = NULL ;
T_3 * V_7 ;
const T_4 * V_8 ;
const T_5 * V_9 = NULL ;
T_6 * V_10 = NULL , * V_11 = NULL ;
T_3 * V_12 = NULL ;
T_7 * V_13 = NULL ;
T_8 * V_14 ;
V_3 = F_2 ( V_1 -> type ) ;
V_1 -> V_15 = V_16 ;
switch ( V_3 )
{
case V_17 :
V_10 = V_1 -> V_18 . V_19 -> V_20 ;
break;
case V_21 :
V_11 = V_1 -> V_18 . V_22 -> V_23 ;
V_10 = V_1 -> V_18 . V_22 -> V_20 ;
V_12 = V_1 -> V_18 . V_22 -> V_24 -> V_25 ;
V_9 = V_1 -> V_18 . V_22 -> V_24 -> V_26 ;
if ( V_9 == NULL )
{
F_3 ( V_27 ,
V_28 ) ;
goto V_29;
}
break;
case V_30 :
V_11 = V_1 -> V_18 . V_31 -> V_23 ;
V_12 = V_1 -> V_18 . V_31 -> V_24 -> V_25 ;
V_9 = V_1 -> V_18 . V_31 -> V_24 -> V_26 ;
if ( V_9 == NULL )
{
F_3 ( V_27 ,
V_28 ) ;
goto V_29;
}
break;
default:
F_3 ( V_27 , V_32 ) ;
goto V_29;
}
if ( V_10 != NULL )
{
for ( V_3 = 0 ; V_3 < F_4 ( V_10 ) ; V_3 ++ )
{
V_7 = ( T_3 * ) F_5 ( V_10 , V_3 ) ;
if ( ( V_6 = F_6 ( F_7 () ) ) == NULL )
{
F_3 ( V_27 , V_33 ) ;
goto V_29;
}
V_4 = F_2 ( V_7 -> V_25 ) ;
V_8 = F_8 ( F_9 ( V_4 ) ) ;
if ( V_8 == NULL )
{
F_3 ( V_27 , V_34 ) ;
goto V_29;
}
F_10 ( V_6 , V_8 ) ;
if ( V_5 == NULL )
V_5 = V_6 ;
else
F_11 ( V_5 , V_6 ) ;
V_6 = NULL ;
}
}
if ( V_9 != NULL )
{
unsigned char V_35 [ V_36 ] ;
unsigned char V_37 [ V_38 ] ;
int V_39 , V_40 ;
int V_41 , V_42 ;
unsigned char * V_43 ;
T_9 * V_44 ;
if ( ( V_6 = F_6 ( F_12 () ) ) == NULL )
{
F_3 ( V_27 , V_33 ) ;
goto V_29;
}
F_13 ( V_6 , & V_44 ) ;
V_39 = F_14 ( V_9 ) ;
V_40 = F_15 ( V_9 ) ;
F_16 ( V_35 , V_39 ) ;
V_12 -> V_25 = F_17 ( F_18 ( V_9 ) ) ;
if ( V_40 > 0 ) F_16 ( V_37 , V_40 ) ;
F_19 ( V_44 , V_9 , V_35 , V_37 , 1 ) ;
if ( V_40 > 0 ) {
if ( V_12 -> V_45 == NULL )
V_12 -> V_45 = F_20 () ;
if( F_21 ( V_44 , V_12 -> V_45 ) < 0 )
goto V_29;
}
V_42 = 0 ;
for ( V_3 = 0 ; V_3 < F_4 ( V_11 ) ; V_3 ++ )
{
V_13 = ( T_7 * ) F_5 ( V_11 , V_3 ) ;
if ( V_13 -> V_46 == NULL )
{
F_3 ( V_27 , V_47 ) ;
goto V_29;
}
V_14 = F_22 ( V_13 -> V_46 ) ;
V_41 = F_23 ( V_14 ) ;
F_24 ( V_14 ) ;
if ( V_42 < V_41 ) V_42 = V_41 ;
}
if ( ( V_43 = ( unsigned char * ) Malloc ( V_42 ) ) == NULL )
{
F_3 ( V_27 , V_48 ) ;
goto V_29;
}
for ( V_3 = 0 ; V_3 < F_4 ( V_11 ) ; V_3 ++ )
{
V_13 = ( T_7 * ) F_5 ( V_11 , V_3 ) ;
V_14 = F_22 ( V_13 -> V_46 ) ;
V_41 = F_25 ( V_43 , V_35 , V_39 , V_14 ) ;
F_24 ( V_14 ) ;
if ( V_41 <= 0 )
{
F_3 ( V_27 , V_49 ) ;
Free ( V_43 ) ;
goto V_29;
}
F_26 ( V_13 -> V_50 , V_43 , V_41 ) ;
}
Free ( V_43 ) ;
memset ( V_35 , 0 , V_39 ) ;
if ( V_5 == NULL )
V_5 = V_6 ;
else
F_11 ( V_5 , V_6 ) ;
V_6 = NULL ;
}
if ( V_2 == NULL )
{
if ( V_1 -> V_51 )
V_2 = F_6 ( F_27 () ) ;
else
{
V_2 = F_6 ( F_28 () ) ;
F_29 ( V_2 , 0 ) ;
if ( F_30 ( V_1 ) &&
F_31 ( V_1 -> V_18 . V_19 -> V_52 ) )
{
T_10 * V_53 ;
V_53 = V_1 -> V_18 . V_19 -> V_52 -> V_18 . V_54 ;
if ( V_53 -> V_55 > 0 )
F_32 ( V_2 , ( char * ) V_53 -> V_54 ,
V_53 -> V_55 ) ;
}
}
}
F_11 ( V_5 , V_2 ) ;
V_2 = NULL ;
if ( 0 )
{
V_29:
if ( V_5 != NULL )
F_33 ( V_5 ) ;
if ( V_6 != NULL )
F_33 ( V_6 ) ;
V_5 = NULL ;
}
return ( V_5 ) ;
}
T_1 * F_34 ( T_2 * V_1 , T_8 * V_14 , T_1 * V_56 , T_11 * V_57 )
{
int V_3 , V_4 ;
T_1 * V_5 = NULL , * V_6 = NULL , * V_58 = NULL , * V_2 = NULL ;
char * V_43 = NULL ;
T_3 * V_7 ;
T_10 * V_59 = NULL ;
const T_4 * V_8 ;
const T_5 * V_9 = NULL ;
T_9 * V_60 = NULL ;
T_3 * V_61 = NULL ;
T_6 * V_10 = NULL , * V_11 = NULL ;
T_3 * V_12 = NULL ;
T_7 * V_13 = NULL ;
#if 0
X509_STORE_CTX s_ctx;
#endif
V_3 = F_2 ( V_1 -> type ) ;
V_1 -> V_15 = V_16 ;
switch ( V_3 )
{
case V_17 :
V_59 = V_1 -> V_18 . V_19 -> V_52 -> V_18 . V_54 ;
V_10 = V_1 -> V_18 . V_19 -> V_20 ;
break;
case V_21 :
V_11 = V_1 -> V_18 . V_22 -> V_23 ;
V_10 = V_1 -> V_18 . V_22 -> V_20 ;
V_59 = V_1 -> V_18 . V_22 -> V_24 -> V_24 ;
V_61 = V_1 -> V_18 . V_22 -> V_24 -> V_25 ;
V_9 = F_35 ( F_9 ( F_2 ( V_61 -> V_25 ) ) ) ;
if ( V_9 == NULL )
{
F_3 ( V_62 , V_63 ) ;
goto V_29;
}
V_12 = V_1 -> V_18 . V_22 -> V_24 -> V_25 ;
break;
case V_30 :
V_11 = V_1 -> V_18 . V_31 -> V_23 ;
V_61 = V_1 -> V_18 . V_31 -> V_24 -> V_25 ;
V_59 = V_1 -> V_18 . V_31 -> V_24 -> V_24 ;
V_9 = F_35 ( F_9 ( F_2 ( V_61 -> V_25 ) ) ) ;
if ( V_9 == NULL )
{
F_3 ( V_62 , V_63 ) ;
goto V_29;
}
V_12 = V_1 -> V_18 . V_31 -> V_24 -> V_25 ;
break;
default:
F_3 ( V_62 , V_32 ) ;
goto V_29;
}
if ( V_10 != NULL )
{
for ( V_3 = 0 ; V_3 < F_4 ( V_10 ) ; V_3 ++ )
{
V_7 = ( T_3 * ) F_5 ( V_10 , V_3 ) ;
if ( ( V_6 = F_6 ( F_7 () ) ) == NULL )
{
F_3 ( V_62 , V_33 ) ;
goto V_29;
}
V_4 = F_2 ( V_7 -> V_25 ) ;
V_8 = F_8 ( F_9 ( V_4 ) ) ;
if ( V_8 == NULL )
{
F_3 ( V_62 , V_34 ) ;
goto V_29;
}
F_10 ( V_6 , V_8 ) ;
if ( V_5 == NULL )
V_5 = V_6 ;
else
F_11 ( V_5 , V_6 ) ;
V_6 = NULL ;
}
}
if ( V_9 != NULL )
{
#if 0
unsigned char key[EVP_MAX_KEY_LENGTH];
unsigned char iv[EVP_MAX_IV_LENGTH];
unsigned char *p;
int keylen,ivlen;
int max;
X509_OBJECT ret;
#endif
int V_41 ;
if ( ( V_58 = F_6 ( F_12 () ) ) == NULL )
{
F_3 ( V_62 , V_33 ) ;
goto V_29;
}
for ( V_3 = 0 ; V_3 < F_4 ( V_11 ) ; V_3 ++ ) {
V_13 = ( T_7 * ) F_5 ( V_11 , V_3 ) ;
if( ! F_36 ( V_13 -> V_64 -> V_65 ,
V_57 -> V_66 -> V_65 ) &&
! F_37 ( V_57 -> V_66 -> V_67 ,
V_13 -> V_64 -> V_68 ) ) break;
V_13 = NULL ;
}
if ( V_13 == NULL ) {
F_3 ( V_62 ,
V_69 ) ;
return ( NULL ) ;
}
V_41 = F_23 ( V_14 ) ;
V_43 = Malloc ( V_41 + 10 ) ;
if ( V_43 == NULL )
{
F_3 ( V_62 , V_48 ) ;
goto V_29;
}
V_41 = F_38 ( ( unsigned char * ) V_43 ,
F_39 ( V_13 -> V_50 ) ,
F_40 ( V_13 -> V_50 ) ,
V_14 ) ;
if ( V_41 <= 0 )
{
F_3 ( V_62 , V_49 ) ;
goto V_29;
}
V_60 = NULL ;
F_13 ( V_58 , & V_60 ) ;
F_19 ( V_60 , V_9 , NULL , NULL , 0 ) ;
if ( F_41 ( V_60 , V_61 -> V_45 ) < 0 )
return ( NULL ) ;
if ( V_41 != F_42 ( V_60 ) )
{
F_3 ( V_62 ,
V_70 ) ;
goto V_29;
}
F_19 ( V_60 , NULL , ( unsigned char * ) V_43 , NULL , 0 ) ;
memset ( V_43 , 0 , V_41 ) ;
if ( V_5 == NULL )
V_5 = V_58 ;
else
F_11 ( V_5 , V_58 ) ;
V_58 = NULL ;
}
#if 1
if ( V_1 -> V_51 || ( V_56 != NULL ) )
{
V_2 = V_56 ;
}
else
{
V_2 = F_6 ( F_28 () ) ;
F_29 ( V_2 , 0 ) ;
if ( V_59 -> V_55 > 0 )
F_32 ( V_2 , ( char * ) V_59 -> V_54 , V_59 -> V_55 ) ;
}
F_11 ( V_5 , V_2 ) ;
V_2 = NULL ;
#endif
if ( 0 )
{
V_29:
if ( V_5 != NULL ) F_33 ( V_5 ) ;
if ( V_6 != NULL ) F_33 ( V_6 ) ;
if ( V_58 != NULL ) F_33 ( V_58 ) ;
if ( V_2 != NULL ) F_33 ( V_2 ) ;
V_5 = NULL ;
}
if ( V_43 != NULL )
Free ( V_43 ) ;
return ( V_5 ) ;
}
int F_43 ( T_2 * V_1 , T_1 * V_2 )
{
int V_71 = 0 ;
int V_3 , V_4 ;
T_1 * V_6 ;
T_12 * V_72 = NULL ;
T_12 * V_73 = NULL ;
T_13 * V_74 ;
T_14 * V_75 , V_76 ;
T_6 * V_77 , * V_78 = NULL ;
unsigned char * V_79 , * V_80 = NULL ;
int V_81 ;
T_10 * V_53 = NULL ;
V_3 = F_2 ( V_1 -> type ) ;
V_1 -> V_15 = V_16 ;
switch ( V_3 )
{
case V_21 :
V_78 = V_1 -> V_18 . V_22 -> V_82 ;
V_53 = F_44 () ;
V_1 -> V_18 . V_22 -> V_24 -> V_24 = V_53 ;
break;
case V_30 :
V_53 = F_44 () ;
V_1 -> V_18 . V_31 -> V_24 -> V_24 = V_53 ;
break;
case V_17 :
V_78 = V_1 -> V_18 . V_19 -> V_82 ;
V_53 = V_1 -> V_18 . V_19 -> V_52 -> V_18 . V_54 ;
if( V_1 -> V_51 ) {
F_45 ( V_53 ) ;
V_1 -> V_18 . V_19 -> V_52 -> V_18 . V_54 = NULL ;
}
break;
}
if ( V_78 != NULL )
{
if ( ( V_73 = F_46 () ) == NULL )
{
F_3 ( V_83 , V_33 ) ;
goto V_29;
}
for ( V_3 = 0 ; V_3 < F_4 ( V_78 ) ; V_3 ++ )
{
V_74 = ( T_13 * )
F_5 ( V_78 , V_3 ) ;
if ( V_74 -> V_14 == NULL ) continue;
V_4 = F_2 ( V_74 -> V_84 -> V_25 ) ;
V_6 = V_2 ;
for (; ; )
{
if ( ( V_6 = F_47 ( V_6 , V_85 ) )
== NULL )
{
F_3 ( V_83 , V_86 ) ;
goto V_29;
}
F_48 ( V_6 , & V_75 ) ;
if ( V_75 == NULL )
{
F_3 ( V_83 , V_87 ) ;
goto V_29;
}
if ( F_49 ( F_50 ( V_75 ) ) == V_4 )
break;
else
V_6 = V_6 -> V_88 ;
}
memcpy ( & V_76 , V_75 , sizeof( V_76 ) ) ;
if ( ! F_51 ( V_73 , F_23 ( V_74 -> V_14 ) ) )
{
F_3 ( V_83 , V_33 ) ;
goto V_29;
}
V_77 = V_74 -> V_89 ;
if ( ( V_77 != NULL ) && ( F_4 ( V_77 ) != 0 ) )
{
unsigned char V_90 [ V_91 ] ;
unsigned int V_92 ;
T_10 * V_93 ;
T_15 * V_94 ;
const T_4 * V_95 ;
V_94 = F_52 ( NULL , 0 ) ;
F_53 ( V_74 ,
V_96 ,
V_97 , V_94 ) ;
V_95 = F_50 ( & V_76 ) ;
F_54 ( & V_76 , V_90 , & V_92 ) ;
V_93 = F_44 () ;
F_26 ( V_93 , V_90 , V_92 ) ;
F_53 ( V_74 ,
V_98 ,
V_99 , V_93 ) ;
F_55 ( & V_76 , V_95 ) ;
V_81 = F_56 ( V_77 , NULL , V_100 ,
V_101 , V_102 , V_103 ) ;
V_80 = ( unsigned char * ) Malloc ( V_81 ) ;
V_79 = V_80 ;
F_56 ( V_77 , & V_79 , V_100 ,
V_101 , V_102 , V_103 ) ;
F_57 ( & V_76 , V_80 , V_81 ) ;
Free ( V_80 ) ;
V_80 = NULL ;
}
if ( V_74 -> V_14 -> type == V_104 )
V_76 . V_93 = F_58 () ;
if ( ! F_59 ( & V_76 , ( unsigned char * ) V_73 -> V_54 ,
( unsigned int * ) & V_73 -> V_55 , V_74 -> V_14 ) )
{
F_3 ( V_83 , V_49 ) ;
goto V_29;
}
if ( ! F_60 ( V_74 -> V_105 ,
( unsigned char * ) V_73 -> V_54 , V_73 -> V_55 ) )
{
F_3 ( V_83 , V_106 ) ;
goto V_29;
}
}
}
if ( ! V_1 -> V_51 )
{
V_6 = F_47 ( V_2 , V_107 ) ;
if ( V_6 == NULL )
{
F_3 ( V_83 , V_108 ) ;
goto V_29;
}
F_61 ( V_6 , & V_72 ) ;
F_26 ( V_53 ,
( unsigned char * ) V_72 -> V_54 , V_72 -> V_55 ) ;
}
if ( V_80 != NULL ) Free ( V_80 ) ;
V_80 = NULL ;
V_71 = 1 ;
V_29:
if ( V_73 != NULL ) F_62 ( V_73 ) ;
return ( V_71 ) ;
}
int F_63 ( T_16 * V_109 , T_17 * V_44 , T_1 * V_2 ,
T_2 * V_1 , T_13 * V_74 )
{
T_10 * V_53 ;
T_14 V_110 , * V_75 ;
unsigned char * V_80 , * V_79 ;
T_18 * V_111 ;
int V_71 = 0 , V_3 ;
int V_112 ;
T_6 * V_77 ;
F_64 ( T_11 ) * V_46 ;
T_1 * V_6 ;
T_11 * V_113 ;
T_8 * V_14 ;
if ( F_30 ( V_1 ) )
{
V_46 = V_1 -> V_18 . V_19 -> V_46 ;
}
else if ( F_65 ( V_1 ) )
{
V_46 = V_1 -> V_18 . V_22 -> V_46 ;
}
else
{
F_3 ( V_114 , V_115 ) ;
goto V_29;
}
V_111 = V_74 -> V_64 ;
V_113 = F_66 ( V_46 , V_111 -> V_65 , V_111 -> V_68 ) ;
if ( V_113 == NULL )
{
F_3 ( V_114 , V_116 ) ;
goto V_29;
}
F_67 ( V_44 , V_109 , V_113 , V_46 ) ;
V_3 = F_68 ( V_44 ) ;
if ( V_3 <= 0 )
{
F_3 ( V_114 , V_117 ) ;
goto V_29;
}
F_69 ( V_44 ) ;
V_112 = F_2 ( V_74 -> V_84 -> V_25 ) ;
V_6 = V_2 ;
for (; ; )
{
if ( ( V_6 == NULL ) ||
( ( V_6 = F_47 ( V_6 , V_85 ) ) == NULL ) )
{
F_3 ( V_114 , V_86 ) ;
goto V_29;
}
F_48 ( V_6 , & V_75 ) ;
if ( V_75 == NULL )
{
F_3 ( V_114 , V_87 ) ;
goto V_29;
}
if ( F_49 ( F_50 ( V_75 ) ) == V_112 )
break;
V_6 = V_6 -> V_88 ;
}
memcpy ( & V_110 , V_75 , sizeof( V_110 ) ) ;
V_77 = V_74 -> V_89 ;
if ( ( V_77 != NULL ) && ( F_4 ( V_77 ) != 0 ) )
{
unsigned char V_118 [ V_91 ] ;
unsigned int V_92 ;
T_10 * V_119 ;
F_54 ( & V_110 , V_118 , & V_92 ) ;
V_119 = F_70 ( V_77 ) ;
if ( ! V_119 )
{
F_3 ( V_114 , V_86 ) ;
goto V_29;
}
if ( ( V_119 -> V_55 != ( int ) V_92 ) ||
( memcmp ( V_119 -> V_54 , V_118 , V_92 ) ) )
{
#if 0
{
int ii;
for (ii=0; ii<message_digest->length; ii++)
printf("%02X",message_digest->data[ii]); printf(" sent\n");
for (ii=0; ii<md_len; ii++) printf("%02X",md_dat[ii]); printf(" calc\n");
}
#endif
F_3 ( V_114 , V_120 ) ;
V_71 = - 1 ;
goto V_29;
}
F_71 ( & V_110 , F_72 ( V_112 ) ) ;
V_3 = F_56 ( V_77 , NULL , V_100 ,
V_101 , V_102 , V_121 ) ;
V_80 = ( unsigned char * ) Malloc ( V_3 ) ;
V_79 = V_80 ;
F_56 ( V_77 , & V_79 , V_100 ,
V_101 , V_102 , V_121 ) ;
F_73 ( & V_110 , V_80 , V_3 ) ;
Free ( V_80 ) ;
}
V_53 = V_74 -> V_105 ;
V_14 = F_22 ( V_113 ) ;
if( V_14 -> type == V_104 ) V_110 . V_93 = F_58 () ;
V_3 = F_74 ( & V_110 , V_53 -> V_54 , V_53 -> V_55 , V_14 ) ;
F_24 ( V_14 ) ;
if ( V_3 <= 0 )
{
F_3 ( V_114 , V_122 ) ;
V_71 = - 1 ;
goto V_29;
}
else
V_71 = 1 ;
V_29:
return ( V_71 ) ;
}
T_18 * F_75 ( T_2 * V_1 , int V_123 )
{
T_6 * V_11 ;
T_7 * V_13 ;
int V_3 ;
V_3 = F_2 ( V_1 -> type ) ;
if ( V_3 != V_21 ) return ( NULL ) ;
V_11 = V_1 -> V_18 . V_22 -> V_23 ;
V_13 = ( T_7 * ) F_5 ( V_11 , 0 ) ;
if ( F_4 ( V_11 ) <= V_123 ) return ( NULL ) ;
V_13 = ( T_7 * ) F_5 ( V_11 , V_123 ) ;
return ( V_13 -> V_64 ) ;
}
T_19 * F_76 ( T_13 * V_74 , int V_124 )
{
return ( F_77 ( V_74 -> V_89 , V_124 ) ) ;
}
T_19 * F_78 ( T_13 * V_74 , int V_124 )
{
return ( F_77 ( V_74 -> V_125 , V_124 ) ) ;
}
static T_19 * F_77 ( T_6 * V_77 , int V_124 )
{
int V_3 ;
T_20 * V_7 ;
T_21 * V_126 ;
V_126 = F_17 ( V_124 ) ;
if ( ! V_126 || ! V_77 ) return ( NULL ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_77 ) ; V_3 ++ )
{
V_7 = ( T_20 * ) F_5 ( V_77 , V_3 ) ;
if ( F_79 ( V_7 -> V_127 , V_126 ) == 0 )
{
if ( V_7 -> V_128 && F_80 ( V_7 -> V_129 . V_128 ) )
return ( F_81 ( V_7 -> V_129 . V_128 , 0 ) ) ;
else
return ( NULL ) ;
}
}
return ( NULL ) ;
}
T_10 * F_70 ( T_6 * V_77 )
{
T_19 * V_130 ;
if( ! ( V_130 = F_77 ( V_77 , V_98 ) ) ) return NULL ;
return V_130 -> V_129 . V_131 ;
}
int F_82 ( T_13 * V_132 , T_6 * V_77 )
{
int V_3 ;
if ( V_132 -> V_89 != NULL )
F_83 ( V_132 -> V_89 , V_133 ) ;
V_132 -> V_89 = F_84 ( V_77 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_77 ) ; V_3 ++ )
{
if ( ( F_85 ( V_132 -> V_89 , V_3 , ( char * ) F_86 (
( T_20 * ) F_5 ( V_77 , V_3 ) ) ) ) == NULL )
return ( 0 ) ;
}
return ( 1 ) ;
}
int F_87 ( T_13 * V_132 , T_6 * V_77 )
{
int V_3 ;
if ( V_132 -> V_125 != NULL )
F_83 ( V_132 -> V_125 , V_133 ) ;
V_132 -> V_125 = F_84 ( V_77 ) ;
for ( V_3 = 0 ; V_3 < F_4 ( V_77 ) ; V_3 ++ )
{
if ( ( F_85 ( V_132 -> V_125 , V_3 , ( char * ) F_86 (
( T_20 * ) F_5 ( V_77 , V_3 ) ) ) ) == NULL )
return ( 0 ) ;
}
return ( 1 ) ;
}
int F_53 ( T_13 * V_132 , int V_124 , int V_134 ,
void * V_129 )
{
return ( F_88 ( & ( V_132 -> V_89 ) , V_124 , V_134 , V_129 ) ) ;
}
int F_89 ( T_13 * V_132 , int V_124 , int V_134 ,
void * V_129 )
{
return ( F_88 ( & ( V_132 -> V_125 ) , V_124 , V_134 , V_129 ) ) ;
}
static int F_88 ( T_6 * * V_77 , int V_124 , int V_134 , void * V_129 )
{
T_20 * V_135 = NULL ;
if ( * V_77 == NULL )
{
* V_77 = F_90 ( NULL ) ;
V_136:
V_135 = F_91 ( V_124 , V_134 , V_129 ) ;
F_92 ( * V_77 , ( char * ) V_135 ) ;
}
else
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_4 ( * V_77 ) ; V_3 ++ )
{
V_135 = ( T_20 * ) F_5 ( * V_77 , V_3 ) ;
if ( F_2 ( V_135 -> V_127 ) == V_124 )
{
V_133 ( V_135 ) ;
V_135 = F_91 ( V_124 , V_134 , V_129 ) ;
F_85 ( * V_77 , V_3 , ( char * ) V_135 ) ;
goto V_137;
}
}
goto V_136;
}
V_137:
return ( 1 ) ;
}
