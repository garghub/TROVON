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
if ( F_17 ( V_36 , V_40 ) <= 0 )
goto V_30;
V_13 -> V_26 = F_18 ( F_19 ( V_9 ) ) ;
if ( V_41 > 0 ) F_20 ( V_38 , V_41 ) ;
F_21 ( V_45 , V_9 , V_36 , V_38 , 1 ) ;
if ( V_41 > 0 ) {
if ( V_13 -> V_46 == NULL )
V_13 -> V_46 = F_22 () ;
if( F_23 ( V_45 , V_13 -> V_46 ) < 0 )
goto V_30;
}
V_43 = 0 ;
for ( V_3 = 0 ; V_3 < F_24 ( V_12 ) ; V_3 ++ )
{
V_14 = F_25 ( V_12 , V_3 ) ;
if ( V_14 -> V_47 == NULL )
{
F_4 ( V_28 , V_48 ) ;
goto V_30;
}
V_15 = F_26 ( V_14 -> V_47 ) ;
V_42 = F_27 ( V_15 ) ;
F_28 ( V_15 ) ;
if ( V_43 < V_42 ) V_43 = V_42 ;
}
if ( ( V_44 = ( unsigned char * ) F_29 ( V_43 ) ) == NULL )
{
F_4 ( V_28 , V_49 ) ;
goto V_30;
}
for ( V_3 = 0 ; V_3 < F_24 ( V_12 ) ; V_3 ++ )
{
V_14 = F_25 ( V_12 , V_3 ) ;
V_15 = F_26 ( V_14 -> V_47 ) ;
V_42 = F_30 ( V_44 , V_36 , V_40 , V_15 ) ;
F_28 ( V_15 ) ;
if ( V_42 <= 0 )
{
F_4 ( V_28 , V_50 ) ;
F_31 ( V_44 ) ;
goto V_30;
}
F_32 ( V_14 -> V_51 , V_44 , V_42 ) ;
}
F_31 ( V_44 ) ;
memset ( V_36 , 0 , V_40 ) ;
if ( V_5 == NULL )
V_5 = V_6 ;
else
F_12 ( V_5 , V_6 ) ;
V_6 = NULL ;
}
if ( V_2 == NULL ) {
if ( V_1 -> V_52 )
V_2 = F_7 ( F_33 () ) ;
else {
if ( F_34 ( V_1 ) &&
F_35 ( V_1 -> V_19 . V_20 -> V_53 ) ) {
T_8 * V_54 ;
V_54 = V_1 -> V_19 . V_20 -> V_53 -> V_19 . V_55 ;
if ( V_54 -> V_56 > 0 ) V_2 =
F_36 ( V_54 -> V_55 , V_54 -> V_56 ) ;
}
if( V_2 == NULL ) {
V_2 = F_7 ( F_37 () ) ;
F_38 ( V_2 , 0 ) ;
}
}
}
F_12 ( V_5 , V_2 ) ;
V_2 = NULL ;
if ( 0 )
{
V_30:
if ( V_5 != NULL )
F_39 ( V_5 ) ;
if ( V_6 != NULL )
F_39 ( V_6 ) ;
V_5 = NULL ;
}
return ( V_5 ) ;
}
T_1 * F_40 ( T_2 * V_1 , T_6 * V_15 , T_1 * V_57 , T_9 * V_58 )
{
int V_3 , V_4 ;
T_1 * V_5 = NULL , * V_6 = NULL , * V_59 = NULL , * V_2 = NULL ;
unsigned char * V_44 = NULL ;
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
V_9 = F_41 ( F_10 ( F_3 ( V_62 -> V_26 ) ) ) ;
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
V_9 = F_41 ( F_10 ( F_3 ( V_62 -> V_26 ) ) ) ;
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
for ( V_3 = 0 ; V_3 < F_24 ( V_12 ) ; V_3 ++ ) {
V_14 = F_25 ( V_12 , V_3 ) ;
if( ! F_42 ( V_14 -> V_65 -> V_66 ,
V_58 -> V_67 -> V_66 ) &&
! F_43 ( V_58 -> V_67 -> V_68 ,
V_14 -> V_65 -> V_69 ) ) break;
V_14 = NULL ;
}
if ( V_14 == NULL ) {
F_4 ( V_63 ,
V_70 ) ;
return ( NULL ) ;
}
V_42 = F_27 ( V_15 ) ;
V_44 = ( unsigned char * ) F_29 ( V_42 + 10 ) ;
if ( V_44 == NULL )
{
F_4 ( V_63 , V_49 ) ;
goto V_30;
}
V_42 = F_44 ( V_44 , F_45 ( V_14 -> V_51 ) ,
F_46 ( V_14 -> V_51 ) , V_15 ) ;
if ( V_42 <= 0 )
{
F_4 ( V_63 , V_50 ) ;
goto V_30;
}
V_61 = NULL ;
F_14 ( V_59 , & V_61 ) ;
F_21 ( V_61 , V_9 , NULL , NULL , 0 ) ;
if ( F_47 ( V_61 , V_62 -> V_46 ) < 0 )
return ( NULL ) ;
if ( V_42 != F_48 ( V_61 ) ) {
if( ! F_49 ( V_61 , V_42 ) )
{
F_4 ( V_63 ,
V_71 ) ;
goto V_30;
}
}
F_21 ( V_61 , NULL , V_44 , NULL , 0 ) ;
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
#if 0
bio=BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(bio,0);
if (data_body->length > 0)
BIO_write(bio,(char *)data_body->data,data_body->length);
#else
if ( V_60 -> V_56 > 0 )
V_2 = F_36 ( V_60 -> V_55 , V_60 -> V_56 ) ;
else {
V_2 = F_7 ( F_37 () ) ;
F_38 ( V_2 , 0 ) ;
}
#endif
}
F_12 ( V_5 , V_2 ) ;
V_2 = NULL ;
#endif
if ( 0 )
{
V_30:
if ( V_5 != NULL ) F_39 ( V_5 ) ;
if ( V_6 != NULL ) F_39 ( V_6 ) ;
if ( V_59 != NULL ) F_39 ( V_59 ) ;
if ( V_2 != NULL ) F_39 ( V_2 ) ;
V_5 = NULL ;
}
if ( V_44 != NULL )
F_31 ( V_44 ) ;
return ( V_5 ) ;
}
int F_50 ( T_2 * V_1 , T_1 * V_2 )
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
V_54 = F_51 () ;
V_1 -> V_19 . V_23 -> V_25 -> V_25 = V_54 ;
break;
case V_31 :
V_54 = F_51 () ;
V_1 -> V_19 . V_32 -> V_25 -> V_25 = V_54 ;
break;
case V_18 :
V_80 = V_1 -> V_19 . V_20 -> V_84 ;
V_54 = V_1 -> V_19 . V_20 -> V_53 -> V_19 . V_55 ;
if( V_1 -> V_52 ) {
F_52 ( V_54 ) ;
V_1 -> V_19 . V_20 -> V_53 -> V_19 . V_55 = NULL ;
}
break;
}
if ( V_80 != NULL )
{
if ( ( V_74 = F_53 () ) == NULL )
{
F_4 ( V_85 , V_34 ) ;
goto V_30;
}
for ( V_3 = 0 ; V_3 < F_54 ( V_80 ) ; V_3 ++ )
{
V_75 = F_55 ( V_80 , V_3 ) ;
if ( V_75 -> V_15 == NULL ) continue;
V_4 = F_3 ( V_75 -> V_86 -> V_26 ) ;
V_6 = V_2 ;
for (; ; )
{
if ( ( V_6 = F_56 ( V_6 , V_87 ) )
== NULL )
{
F_4 ( V_85 , V_88 ) ;
goto V_30;
}
F_57 ( V_6 , & V_76 ) ;
if ( V_76 == NULL )
{
F_4 ( V_85 , V_89 ) ;
goto V_30;
}
if ( F_58 ( V_76 ) == V_4 )
break;
else
V_6 = F_59 ( V_6 ) ;
}
memcpy ( & V_77 , V_76 , sizeof( V_77 ) ) ;
if ( ! F_60 ( V_74 , F_27 ( V_75 -> V_15 ) ) )
{
F_4 ( V_85 , V_34 ) ;
goto V_30;
}
V_79 = V_75 -> V_90 ;
if ( ( V_79 != NULL ) && ( F_61 ( V_79 ) != 0 ) )
{
unsigned char V_91 [ V_92 ] ;
unsigned int V_93 ;
T_8 * V_94 ;
T_13 * V_95 ;
const T_4 * V_96 ;
V_95 = F_62 ( NULL , 0 ) ;
F_63 ( V_75 ,
V_97 ,
V_98 , V_95 ) ;
V_96 = F_64 ( & V_77 ) ;
F_65 ( & V_77 , V_91 , & V_93 ) ;
V_94 = F_51 () ;
F_32 ( V_94 , V_91 , V_93 ) ;
F_63 ( V_75 ,
V_99 ,
V_100 , V_94 ) ;
F_66 ( & V_77 , V_96 ) ;
V_83 = F_67 ( V_79 , NULL ,
V_101 ,
V_102 , V_103 , V_104 ) ;
V_82 = ( unsigned char * ) F_29 ( V_83 ) ;
V_81 = V_82 ;
F_67 ( V_79 , & V_81 ,
V_101 ,
V_102 , V_103 , V_104 ) ;
F_68 ( & V_77 , V_82 , V_83 ) ;
F_31 ( V_82 ) ;
V_82 = NULL ;
}
if ( V_75 -> V_15 -> type == V_105 )
V_77 . V_94 = F_69 () ;
if ( ! F_70 ( & V_77 , ( unsigned char * ) V_74 -> V_55 ,
( unsigned int * ) & V_74 -> V_56 , V_75 -> V_15 ) )
{
F_4 ( V_85 , V_50 ) ;
goto V_30;
}
if ( ! F_71 ( V_75 -> V_106 ,
( unsigned char * ) V_74 -> V_55 , V_74 -> V_56 ) )
{
F_4 ( V_85 , V_107 ) ;
goto V_30;
}
}
}
if ( ! V_1 -> V_52 )
{
V_6 = F_56 ( V_2 , V_108 ) ;
if ( V_6 == NULL )
{
F_4 ( V_85 , V_109 ) ;
goto V_30;
}
F_72 ( V_6 , & V_73 ) ;
F_73 ( V_6 , V_110 ) ;
F_38 ( V_6 , 0 ) ;
V_54 -> V_55 = ( unsigned char * ) V_73 -> V_55 ;
V_54 -> V_56 = V_73 -> V_56 ;
#if 0
M_ASN1_OCTET_STRING_set(os,
(unsigned char *)buf_mem->data,buf_mem->length);
#endif
}
if ( V_82 != NULL ) F_31 ( V_82 ) ;
V_82 = NULL ;
V_72 = 1 ;
V_30:
if ( V_74 != NULL ) F_74 ( V_74 ) ;
return ( V_72 ) ;
}
int F_75 ( T_14 * V_111 , T_15 * V_45 , T_1 * V_2 ,
T_2 * V_1 , T_11 * V_75 )
{
T_16 * V_112 ;
int V_72 = 0 , V_3 ;
F_2 ( T_9 ) * V_47 ;
T_9 * V_113 ;
if ( F_34 ( V_1 ) )
{
V_47 = V_1 -> V_19 . V_20 -> V_47 ;
}
else if ( F_76 ( V_1 ) )
{
V_47 = V_1 -> V_19 . V_23 -> V_47 ;
}
else
{
F_4 ( V_114 , V_115 ) ;
goto V_30;
}
V_112 = V_75 -> V_65 ;
V_113 = F_77 ( V_47 , V_112 -> V_66 , V_112 -> V_69 ) ;
if ( V_113 == NULL )
{
F_4 ( V_114 , V_116 ) ;
goto V_30;
}
F_78 ( V_45 , V_111 , V_113 , V_47 ) ;
F_79 ( V_45 , V_117 ) ;
V_3 = F_80 ( V_45 ) ;
if ( V_3 <= 0 )
{
F_4 ( V_114 , V_118 ) ;
F_81 ( V_45 ) ;
goto V_30;
}
F_81 ( V_45 ) ;
return F_82 ( V_2 , V_1 , V_75 , V_113 ) ;
V_30:
return V_72 ;
}
int F_82 ( T_1 * V_2 , T_2 * V_1 , T_11 * V_75 ,
T_9 * V_113 )
{
T_8 * V_54 ;
T_12 V_119 , * V_76 ;
unsigned char * V_82 , * V_81 ;
int V_72 = 0 , V_3 ;
int V_120 ;
F_2 ( V_78 ) * V_79 ;
T_1 * V_6 ;
T_6 * V_15 ;
if ( ! F_34 ( V_1 ) &&
! F_76 ( V_1 ) ) {
F_4 ( V_121 ,
V_115 ) ;
goto V_30;
}
V_120 = F_3 ( V_75 -> V_86 -> V_26 ) ;
V_6 = V_2 ;
for (; ; )
{
if ( ( V_6 == NULL ) ||
( ( V_6 = F_56 ( V_6 , V_87 ) ) == NULL ) )
{
F_4 ( V_121 ,
V_88 ) ;
goto V_30;
}
F_57 ( V_6 , & V_76 ) ;
if ( V_76 == NULL )
{
F_4 ( V_121 ,
V_89 ) ;
goto V_30;
}
if ( F_58 ( V_76 ) == V_120 )
break;
V_6 = F_59 ( V_6 ) ;
}
memcpy ( & V_119 , V_76 , sizeof( V_119 ) ) ;
V_79 = V_75 -> V_90 ;
if ( ( V_79 != NULL ) && ( F_61 ( V_79 ) != 0 ) )
{
unsigned char V_122 [ V_92 ] ;
unsigned int V_93 ;
T_8 * V_123 ;
F_65 ( & V_119 , V_122 , & V_93 ) ;
V_123 = F_83 ( V_79 ) ;
if ( ! V_123 )
{
F_4 ( V_121 ,
V_88 ) ;
goto V_30;
}
if ( ( V_123 -> V_56 != ( int ) V_93 ) ||
( memcmp ( V_123 -> V_55 , V_122 , V_93 ) ) )
{
#if 0
{
int ii;
for (ii=0; ii<message_digest->length; ii++)
printf("%02X",message_digest->data[ii]); printf(" sent\n");
for (ii=0; ii<md_len; ii++) printf("%02X",md_dat[ii]); printf(" calc\n");
}
#endif
F_4 ( V_121 ,
V_124 ) ;
V_72 = - 1 ;
goto V_30;
}
F_84 ( & V_119 , F_85 ( V_120 ) ) ;
V_3 = F_67 ( V_79 , NULL , V_101 ,
V_102 , V_103 , V_125 ) ;
V_82 = F_29 ( V_3 ) ;
V_81 = V_82 ;
F_67 ( V_79 , & V_81 , V_101 ,
V_102 , V_103 , V_125 ) ;
F_86 ( & V_119 , V_82 , V_3 ) ;
F_31 ( V_82 ) ;
}
V_54 = V_75 -> V_106 ;
V_15 = F_26 ( V_113 ) ;
if( V_15 -> type == V_105 ) V_119 . V_94 = F_69 () ;
V_3 = F_87 ( & V_119 , V_54 -> V_55 , V_54 -> V_56 , V_15 ) ;
F_28 ( V_15 ) ;
if ( V_3 <= 0 )
{
F_4 ( V_121 ,
V_126 ) ;
V_72 = - 1 ;
goto V_30;
}
else
V_72 = 1 ;
V_30:
return ( V_72 ) ;
}
T_16 * F_88 ( T_2 * V_1 , int V_127 )
{
F_2 ( V_11 ) * V_12 ;
V_11 * V_14 ;
int V_3 ;
V_3 = F_3 ( V_1 -> type ) ;
if ( V_3 != V_22 ) return ( NULL ) ;
V_12 = V_1 -> V_19 . V_23 -> V_24 ;
V_14 = F_25 ( V_12 , 0 ) ;
if ( F_24 ( V_12 ) <= V_127 ) return ( NULL ) ;
V_14 = F_25 ( V_12 , V_127 ) ;
return ( V_14 -> V_65 ) ;
}
T_17 * F_89 ( T_11 * V_75 , int V_128 )
{
return ( F_90 ( V_75 -> V_90 , V_128 ) ) ;
}
T_17 * F_91 ( T_11 * V_75 , int V_128 )
{
return ( F_90 ( V_75 -> V_129 , V_128 ) ) ;
}
int F_63 ( T_11 * V_130 , int V_128 , int V_131 ,
void * V_132 )
{
return ( F_92 ( & ( V_130 -> V_90 ) , V_128 , V_131 , V_132 ) ) ;
}
int F_93 ( T_11 * V_130 , int V_128 , int V_131 ,
void * V_132 )
{
return ( F_92 ( & ( V_130 -> V_129 ) , V_128 , V_131 , V_132 ) ) ;
}
