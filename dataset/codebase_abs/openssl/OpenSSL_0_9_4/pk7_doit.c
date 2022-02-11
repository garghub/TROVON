T_1 * F_1 ( T_2 * V_1 , T_1 * V_2 )
{
int V_3 , V_4 ;
T_1 * V_5 = NULL , * V_6 = NULL ;
T_3 * V_7 ;
const T_4 * V_8 ;
const T_5 * V_9 = NULL ;
F_2 ( T_3 ) * V_10 = NULL ;
F_2 ( V_11 ) * V_12 = NULL ;
T_3 * V_13 = NULL ;
V_11 * V_14 = NULL ;
T_6 * V_15 ;
V_3 = F_3 ( V_1 -> type ) ;
V_1 -> V_16 = V_17 ;
switch ( V_3 )
{
case V_18 :
V_10 = V_1 -> V_19 . V_20 -> V_21 ;
break;
case V_22 :
V_12 = V_1 -> V_19 . V_23 -> V_24 ;
V_10 = V_1 -> V_19 . V_23 -> V_21 ;
V_13 = V_1 -> V_19 . V_23 -> V_25 -> V_26 ;
V_9 = V_1 -> V_19 . V_23 -> V_25 -> V_27 ;
if ( V_9 == NULL )
{
F_4 ( V_28 ,
V_29 ) ;
goto V_30;
}
break;
case V_31 :
V_12 = V_1 -> V_19 . V_32 -> V_24 ;
V_13 = V_1 -> V_19 . V_32 -> V_25 -> V_26 ;
V_9 = V_1 -> V_19 . V_32 -> V_25 -> V_27 ;
if ( V_9 == NULL )
{
F_4 ( V_28 ,
V_29 ) ;
goto V_30;
}
break;
default:
F_4 ( V_28 , V_33 ) ;
goto V_30;
}
if ( V_10 != NULL )
{
for ( V_3 = 0 ; V_3 < F_5 ( V_10 ) ; V_3 ++ )
{
V_7 = F_6 ( V_10 , V_3 ) ;
if ( ( V_6 = F_7 ( F_8 () ) ) == NULL )
{
F_4 ( V_28 , V_34 ) ;
goto V_30;
}
V_4 = F_3 ( V_7 -> V_26 ) ;
V_8 = F_9 ( F_10 ( V_4 ) ) ;
if ( V_8 == NULL )
{
F_4 ( V_28 , V_35 ) ;
goto V_30;
}
F_11 ( V_6 , V_8 ) ;
if ( V_5 == NULL )
V_5 = V_6 ;
else
F_12 ( V_5 , V_6 ) ;
V_6 = NULL ;
}
}
if ( V_9 != NULL )
{
unsigned char V_36 [ V_37 ] ;
unsigned char V_38 [ V_39 ] ;
int V_40 , V_41 ;
int V_42 , V_43 ;
unsigned char * V_44 ;
T_7 * V_45 ;
if ( ( V_6 = F_7 ( F_13 () ) ) == NULL )
{
F_4 ( V_28 , V_34 ) ;
goto V_30;
}
F_14 ( V_6 , & V_45 ) ;
V_40 = F_15 ( V_9 ) ;
V_41 = F_16 ( V_9 ) ;
F_17 ( V_36 , V_40 ) ;
V_13 -> V_26 = F_18 ( F_19 ( V_9 ) ) ;
if ( V_41 > 0 ) F_17 ( V_38 , V_41 ) ;
F_20 ( V_45 , V_9 , V_36 , V_38 , 1 ) ;
if ( V_41 > 0 ) {
if ( V_13 -> V_46 == NULL )
V_13 -> V_46 = F_21 () ;
if( F_22 ( V_45 , V_13 -> V_46 ) < 0 )
goto V_30;
}
V_43 = 0 ;
for ( V_3 = 0 ; V_3 < F_23 ( V_12 ) ; V_3 ++ )
{
V_14 = F_24 ( V_12 , V_3 ) ;
if ( V_14 -> V_47 == NULL )
{
F_4 ( V_28 , V_48 ) ;
goto V_30;
}
V_15 = F_25 ( V_14 -> V_47 ) ;
V_42 = F_26 ( V_15 ) ;
F_27 ( V_15 ) ;
if ( V_43 < V_42 ) V_43 = V_42 ;
}
if ( ( V_44 = ( unsigned char * ) Malloc ( V_43 ) ) == NULL )
{
F_4 ( V_28 , V_49 ) ;
goto V_30;
}
for ( V_3 = 0 ; V_3 < F_23 ( V_12 ) ; V_3 ++ )
{
V_14 = F_24 ( V_12 , V_3 ) ;
V_15 = F_25 ( V_14 -> V_47 ) ;
V_42 = F_28 ( V_44 , V_36 , V_40 , V_15 ) ;
F_27 ( V_15 ) ;
if ( V_42 <= 0 )
{
F_4 ( V_28 , V_50 ) ;
Free ( V_44 ) ;
goto V_30;
}
F_29 ( V_14 -> V_51 , V_44 , V_42 ) ;
}
Free ( V_44 ) ;
memset ( V_36 , 0 , V_40 ) ;
if ( V_5 == NULL )
V_5 = V_6 ;
else
F_12 ( V_5 , V_6 ) ;
V_6 = NULL ;
}
if ( V_2 == NULL )
{
if ( V_1 -> V_52 )
V_2 = F_7 ( F_30 () ) ;
else
{
V_2 = F_7 ( F_31 () ) ;
F_32 ( V_2 , 0 ) ;
if ( F_33 ( V_1 ) &&
F_34 ( V_1 -> V_19 . V_20 -> V_53 ) )
{
T_8 * V_54 ;
V_54 = V_1 -> V_19 . V_20 -> V_53 -> V_19 . V_55 ;
if ( V_54 -> V_56 > 0 )
F_35 ( V_2 , ( char * ) V_54 -> V_55 ,
V_54 -> V_56 ) ;
}
}
}
F_12 ( V_5 , V_2 ) ;
V_2 = NULL ;
if ( 0 )
{
V_30:
if ( V_5 != NULL )
F_36 ( V_5 ) ;
if ( V_6 != NULL )
F_36 ( V_6 ) ;
V_5 = NULL ;
}
return ( V_5 ) ;
}
T_1 * F_37 ( T_2 * V_1 , T_6 * V_15 , T_1 * V_57 , T_9 * V_58 )
{
int V_3 , V_4 ;
T_1 * V_5 = NULL , * V_6 = NULL , * V_59 = NULL , * V_2 = NULL ;
char * V_44 = NULL ;
T_3 * V_7 ;
T_8 * V_60 = NULL ;
const T_4 * V_8 ;
const T_5 * V_9 = NULL ;
T_7 * V_61 = NULL ;
T_3 * V_62 = NULL ;
F_2 ( T_3 ) * V_10 = NULL ;
F_2 ( V_11 ) * V_12 = NULL ;
T_3 * V_13 = NULL ;
V_11 * V_14 = NULL ;
#if 0
X509_STORE_CTX s_ctx;
#endif
V_3 = F_3 ( V_1 -> type ) ;
V_1 -> V_16 = V_17 ;
switch ( V_3 )
{
case V_18 :
V_60 = V_1 -> V_19 . V_20 -> V_53 -> V_19 . V_55 ;
V_10 = V_1 -> V_19 . V_20 -> V_21 ;
break;
case V_22 :
V_12 = V_1 -> V_19 . V_23 -> V_24 ;
V_10 = V_1 -> V_19 . V_23 -> V_21 ;
V_60 = V_1 -> V_19 . V_23 -> V_25 -> V_25 ;
V_62 = V_1 -> V_19 . V_23 -> V_25 -> V_26 ;
V_9 = F_38 ( F_10 ( F_3 ( V_62 -> V_26 ) ) ) ;
if ( V_9 == NULL )
{
F_4 ( V_63 , V_64 ) ;
goto V_30;
}
V_13 = V_1 -> V_19 . V_23 -> V_25 -> V_26 ;
break;
case V_31 :
V_12 = V_1 -> V_19 . V_32 -> V_24 ;
V_62 = V_1 -> V_19 . V_32 -> V_25 -> V_26 ;
V_60 = V_1 -> V_19 . V_32 -> V_25 -> V_25 ;
V_9 = F_38 ( F_10 ( F_3 ( V_62 -> V_26 ) ) ) ;
if ( V_9 == NULL )
{
F_4 ( V_63 , V_64 ) ;
goto V_30;
}
V_13 = V_1 -> V_19 . V_32 -> V_25 -> V_26 ;
break;
default:
F_4 ( V_63 , V_33 ) ;
goto V_30;
}
if ( V_10 != NULL )
{
for ( V_3 = 0 ; V_3 < F_5 ( V_10 ) ; V_3 ++ )
{
V_7 = F_6 ( V_10 , V_3 ) ;
if ( ( V_6 = F_7 ( F_8 () ) ) == NULL )
{
F_4 ( V_63 , V_34 ) ;
goto V_30;
}
V_4 = F_3 ( V_7 -> V_26 ) ;
V_8 = F_9 ( F_10 ( V_4 ) ) ;
if ( V_8 == NULL )
{
F_4 ( V_63 , V_35 ) ;
goto V_30;
}
F_11 ( V_6 , V_8 ) ;
if ( V_5 == NULL )
V_5 = V_6 ;
else
F_12 ( V_5 , V_6 ) ;
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
int V_42 ;
if ( ( V_59 = F_7 ( F_13 () ) ) == NULL )
{
F_4 ( V_63 , V_34 ) ;
goto V_30;
}
for ( V_3 = 0 ; V_3 < F_23 ( V_12 ) ; V_3 ++ ) {
V_14 = F_24 ( V_12 , V_3 ) ;
if( ! F_39 ( V_14 -> V_65 -> V_66 ,
V_58 -> V_67 -> V_66 ) &&
! F_40 ( V_58 -> V_67 -> V_68 ,
V_14 -> V_65 -> V_69 ) ) break;
V_14 = NULL ;
}
if ( V_14 == NULL ) {
F_4 ( V_63 ,
V_70 ) ;
return ( NULL ) ;
}
V_42 = F_26 ( V_15 ) ;
V_44 = Malloc ( V_42 + 10 ) ;
if ( V_44 == NULL )
{
F_4 ( V_63 , V_49 ) ;
goto V_30;
}
V_42 = F_41 ( ( unsigned char * ) V_44 ,
F_42 ( V_14 -> V_51 ) ,
F_43 ( V_14 -> V_51 ) ,
V_15 ) ;
if ( V_42 <= 0 )
{
F_4 ( V_63 , V_50 ) ;
goto V_30;
}
V_61 = NULL ;
F_14 ( V_59 , & V_61 ) ;
F_20 ( V_61 , V_9 , NULL , NULL , 0 ) ;
if ( F_44 ( V_61 , V_62 -> V_46 ) < 0 )
return ( NULL ) ;
if ( V_42 != F_45 ( V_61 ) )
{
F_4 ( V_63 ,
V_71 ) ;
goto V_30;
}
F_20 ( V_61 , NULL , ( unsigned char * ) V_44 , NULL , 0 ) ;
memset ( V_44 , 0 , V_42 ) ;
if ( V_5 == NULL )
V_5 = V_59 ;
else
F_12 ( V_5 , V_59 ) ;
V_59 = NULL ;
}
#if 1
if ( V_1 -> V_52 || ( V_57 != NULL ) )
{
V_2 = V_57 ;
}
else
{
V_2 = F_7 ( F_31 () ) ;
F_32 ( V_2 , 0 ) ;
if ( V_60 -> V_56 > 0 )
F_35 ( V_2 , ( char * ) V_60 -> V_55 , V_60 -> V_56 ) ;
}
F_12 ( V_5 , V_2 ) ;
V_2 = NULL ;
#endif
if ( 0 )
{
V_30:
if ( V_5 != NULL ) F_36 ( V_5 ) ;
if ( V_6 != NULL ) F_36 ( V_6 ) ;
if ( V_59 != NULL ) F_36 ( V_59 ) ;
if ( V_2 != NULL ) F_36 ( V_2 ) ;
V_5 = NULL ;
}
if ( V_44 != NULL )
Free ( V_44 ) ;
return ( V_5 ) ;
}
int F_46 ( T_2 * V_1 , T_1 * V_2 )
{
int V_72 = 0 ;
int V_3 , V_4 ;
T_1 * V_6 ;
T_10 * V_73 = NULL ;
T_10 * V_74 = NULL ;
T_11 * V_75 ;
T_12 * V_76 , V_77 ;
F_2 ( V_78 ) * V_79 ;
F_2 ( T_11 ) * V_80 = NULL ;
unsigned char * V_81 , * V_82 = NULL ;
int V_83 ;
T_8 * V_54 = NULL ;
V_3 = F_3 ( V_1 -> type ) ;
V_1 -> V_16 = V_17 ;
switch ( V_3 )
{
case V_22 :
V_80 = V_1 -> V_19 . V_23 -> V_84 ;
V_54 = F_47 () ;
V_1 -> V_19 . V_23 -> V_25 -> V_25 = V_54 ;
break;
case V_31 :
V_54 = F_47 () ;
V_1 -> V_19 . V_32 -> V_25 -> V_25 = V_54 ;
break;
case V_18 :
V_80 = V_1 -> V_19 . V_20 -> V_84 ;
V_54 = V_1 -> V_19 . V_20 -> V_53 -> V_19 . V_55 ;
if( V_1 -> V_52 ) {
F_48 ( V_54 ) ;
V_1 -> V_19 . V_20 -> V_53 -> V_19 . V_55 = NULL ;
}
break;
}
if ( V_80 != NULL )
{
if ( ( V_74 = F_49 () ) == NULL )
{
F_4 ( V_85 , V_34 ) ;
goto V_30;
}
for ( V_3 = 0 ; V_3 < F_50 ( V_80 ) ; V_3 ++ )
{
V_75 = F_51 ( V_80 , V_3 ) ;
if ( V_75 -> V_15 == NULL ) continue;
V_4 = F_3 ( V_75 -> V_86 -> V_26 ) ;
V_6 = V_2 ;
for (; ; )
{
if ( ( V_6 = F_52 ( V_6 , V_87 ) )
== NULL )
{
F_4 ( V_85 , V_88 ) ;
goto V_30;
}
F_53 ( V_6 , & V_76 ) ;
if ( V_76 == NULL )
{
F_4 ( V_85 , V_89 ) ;
goto V_30;
}
if ( F_54 ( F_55 ( V_76 ) ) == V_4 )
break;
else
V_6 = V_6 -> V_90 ;
}
memcpy ( & V_77 , V_76 , sizeof( V_77 ) ) ;
if ( ! F_56 ( V_74 , F_26 ( V_75 -> V_15 ) ) )
{
F_4 ( V_85 , V_34 ) ;
goto V_30;
}
V_79 = V_75 -> V_91 ;
if ( ( V_79 != NULL ) && ( F_57 ( V_79 ) != 0 ) )
{
unsigned char V_92 [ V_93 ] ;
unsigned int V_94 ;
T_8 * V_95 ;
T_13 * V_96 ;
const T_4 * V_97 ;
V_96 = F_58 ( NULL , 0 ) ;
F_59 ( V_75 ,
V_98 ,
V_99 , V_96 ) ;
V_97 = F_55 ( & V_77 ) ;
F_60 ( & V_77 , V_92 , & V_94 ) ;
V_95 = F_47 () ;
F_29 ( V_95 , V_92 , V_94 ) ;
F_59 ( V_75 ,
V_100 ,
V_101 , V_95 ) ;
F_61 ( & V_77 , V_97 ) ;
V_83 = F_62 ( V_79 , NULL ,
V_102 ,
V_103 , V_104 , V_105 ) ;
V_82 = ( unsigned char * ) Malloc ( V_83 ) ;
V_81 = V_82 ;
F_62 ( V_79 , & V_81 ,
V_102 ,
V_103 , V_104 , V_105 ) ;
F_63 ( & V_77 , V_82 , V_83 ) ;
Free ( V_82 ) ;
V_82 = NULL ;
}
if ( V_75 -> V_15 -> type == V_106 )
V_77 . V_95 = F_64 () ;
if ( ! F_65 ( & V_77 , ( unsigned char * ) V_74 -> V_55 ,
( unsigned int * ) & V_74 -> V_56 , V_75 -> V_15 ) )
{
F_4 ( V_85 , V_50 ) ;
goto V_30;
}
if ( ! F_66 ( V_75 -> V_107 ,
( unsigned char * ) V_74 -> V_55 , V_74 -> V_56 ) )
{
F_4 ( V_85 , V_108 ) ;
goto V_30;
}
}
}
if ( ! V_1 -> V_52 )
{
V_6 = F_52 ( V_2 , V_109 ) ;
if ( V_6 == NULL )
{
F_4 ( V_85 , V_110 ) ;
goto V_30;
}
F_67 ( V_6 , & V_73 ) ;
F_29 ( V_54 ,
( unsigned char * ) V_73 -> V_55 , V_73 -> V_56 ) ;
}
if ( V_82 != NULL ) Free ( V_82 ) ;
V_82 = NULL ;
V_72 = 1 ;
V_30:
if ( V_74 != NULL ) F_68 ( V_74 ) ;
return ( V_72 ) ;
}
int F_69 ( T_14 * V_111 , T_15 * V_45 , T_1 * V_2 ,
T_2 * V_1 , T_11 * V_75 )
{
T_16 * V_112 ;
int V_72 = 0 , V_3 ;
F_2 ( T_9 ) * V_47 ;
T_9 * V_113 ;
if ( F_33 ( V_1 ) )
{
V_47 = V_1 -> V_19 . V_20 -> V_47 ;
}
else if ( F_70 ( V_1 ) )
{
V_47 = V_1 -> V_19 . V_23 -> V_47 ;
}
else
{
F_4 ( V_114 , V_115 ) ;
goto V_30;
}
V_112 = V_75 -> V_65 ;
V_113 = F_71 ( V_47 , V_112 -> V_66 , V_112 -> V_69 ) ;
if ( V_113 == NULL )
{
F_4 ( V_114 , V_116 ) ;
goto V_30;
}
F_72 ( V_45 , V_111 , V_113 , V_47 ) ;
V_3 = F_73 ( V_45 ) ;
if ( V_3 <= 0 )
{
F_4 ( V_114 , V_117 ) ;
goto V_30;
}
F_74 ( V_45 ) ;
return F_75 ( V_2 , V_1 , V_75 , V_113 ) ;
V_30:
return V_72 ;
}
int F_75 ( T_1 * V_2 , T_2 * V_1 , T_11 * V_75 ,
T_9 * V_113 )
{
T_8 * V_54 ;
T_12 V_118 , * V_76 ;
unsigned char * V_82 , * V_81 ;
int V_72 = 0 , V_3 ;
int V_119 ;
F_2 ( V_78 ) * V_79 ;
T_1 * V_6 ;
T_6 * V_15 ;
if ( ! F_33 ( V_1 ) &&
! F_70 ( V_1 ) ) {
F_4 ( V_120 ,
V_115 ) ;
goto V_30;
}
V_119 = F_3 ( V_75 -> V_86 -> V_26 ) ;
V_6 = V_2 ;
for (; ; )
{
if ( ( V_6 == NULL ) ||
( ( V_6 = F_52 ( V_6 , V_87 ) ) == NULL ) )
{
F_4 ( V_120 ,
V_88 ) ;
goto V_30;
}
F_53 ( V_6 , & V_76 ) ;
if ( V_76 == NULL )
{
F_4 ( V_120 ,
V_89 ) ;
goto V_30;
}
if ( F_54 ( F_55 ( V_76 ) ) == V_119 )
break;
V_6 = V_6 -> V_90 ;
}
memcpy ( & V_118 , V_76 , sizeof( V_118 ) ) ;
V_79 = V_75 -> V_91 ;
if ( ( V_79 != NULL ) && ( F_57 ( V_79 ) != 0 ) )
{
unsigned char V_121 [ V_93 ] ;
unsigned int V_94 ;
T_8 * V_122 ;
F_60 ( & V_118 , V_121 , & V_94 ) ;
V_122 = F_76 ( V_79 ) ;
if ( ! V_122 )
{
F_4 ( V_120 ,
V_88 ) ;
goto V_30;
}
if ( ( V_122 -> V_56 != ( int ) V_94 ) ||
( memcmp ( V_122 -> V_55 , V_121 , V_94 ) ) )
{
#if 0
{
int ii;
for (ii=0; ii<message_digest->length; ii++)
printf("%02X",message_digest->data[ii]); printf(" sent\n");
for (ii=0; ii<md_len; ii++) printf("%02X",md_dat[ii]); printf(" calc\n");
}
#endif
F_4 ( V_120 ,
V_123 ) ;
V_72 = - 1 ;
goto V_30;
}
F_77 ( & V_118 , F_78 ( V_119 ) ) ;
V_3 = F_62 ( V_79 , NULL , V_102 ,
V_103 , V_104 , V_124 ) ;
V_82 = Malloc ( V_3 ) ;
V_81 = V_82 ;
F_62 ( V_79 , & V_81 , V_102 ,
V_103 , V_104 , V_124 ) ;
F_79 ( & V_118 , V_82 , V_3 ) ;
Free ( V_82 ) ;
}
V_54 = V_75 -> V_107 ;
V_15 = F_25 ( V_113 ) ;
if( V_15 -> type == V_106 ) V_118 . V_95 = F_64 () ;
V_3 = F_80 ( & V_118 , V_54 -> V_55 , V_54 -> V_56 , V_15 ) ;
F_27 ( V_15 ) ;
if ( V_3 <= 0 )
{
F_4 ( V_120 ,
V_125 ) ;
V_72 = - 1 ;
goto V_30;
}
else
V_72 = 1 ;
V_30:
return ( V_72 ) ;
}
T_16 * F_81 ( T_2 * V_1 , int V_126 )
{
F_2 ( V_11 ) * V_12 ;
V_11 * V_14 ;
int V_3 ;
V_3 = F_3 ( V_1 -> type ) ;
if ( V_3 != V_22 ) return ( NULL ) ;
V_12 = V_1 -> V_19 . V_23 -> V_24 ;
V_14 = F_24 ( V_12 , 0 ) ;
if ( F_23 ( V_12 ) <= V_126 ) return ( NULL ) ;
V_14 = F_24 ( V_12 , V_126 ) ;
return ( V_14 -> V_65 ) ;
}
T_17 * F_82 ( T_11 * V_75 , int V_127 )
{
return ( F_83 ( V_75 -> V_91 , V_127 ) ) ;
}
T_17 * F_84 ( T_11 * V_75 , int V_127 )
{
return ( F_83 ( V_75 -> V_128 , V_127 ) ) ;
}
int F_59 ( T_11 * V_129 , int V_127 , int V_130 ,
void * V_131 )
{
return ( F_85 ( & ( V_129 -> V_91 ) , V_127 , V_130 , V_131 ) ) ;
}
int F_86 ( T_11 * V_129 , int V_127 , int V_130 ,
void * V_131 )
{
return ( F_85 ( & ( V_129 -> V_128 ) , V_127 , V_130 , V_131 ) ) ;
}
