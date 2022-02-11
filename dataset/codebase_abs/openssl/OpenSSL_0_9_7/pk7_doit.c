static int F_1 ( T_1 * V_1 )
{
int V_2 = 1 ;
int V_3 = F_2 ( V_1 -> type ) ;
switch( V_3 )
{
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
V_2 = 0 ;
break;
default:
V_2 = 1 ;
}
return V_2 ;
}
static int F_3 ( T_1 * V_1 )
{
if ( 0 == F_1 ( V_1 ) )
return 0 ;
return ( V_10 == V_1 -> V_11 . V_12 -> type ) ? 1 : 0 ;
}
T_2 * F_4 ( T_1 * V_1 , T_2 * V_13 )
{
int V_14 , V_15 ;
T_2 * V_16 = NULL , * V_17 = NULL ;
T_3 * V_18 ;
const T_4 * V_19 ;
const T_5 * V_20 = NULL ;
F_5 ( T_3 ) * V_21 = NULL ;
F_5 ( V_22 ) * V_23 = NULL ;
T_3 * V_24 = NULL ;
V_22 * V_25 = NULL ;
T_6 * V_26 ;
V_14 = F_2 ( V_1 -> type ) ;
V_1 -> V_27 = V_28 ;
switch ( V_14 )
{
case V_5 :
V_21 = V_1 -> V_11 . V_29 -> V_30 ;
break;
case V_7 :
V_23 = V_1 -> V_11 . V_31 -> V_32 ;
V_21 = V_1 -> V_11 . V_31 -> V_30 ;
V_24 = V_1 -> V_11 . V_31 -> V_33 -> V_34 ;
V_20 = V_1 -> V_11 . V_31 -> V_33 -> V_35 ;
if ( V_20 == NULL )
{
F_6 ( V_36 ,
V_37 ) ;
goto V_38;
}
break;
case V_6 :
V_23 = V_1 -> V_11 . V_39 -> V_32 ;
V_24 = V_1 -> V_11 . V_39 -> V_33 -> V_34 ;
V_20 = V_1 -> V_11 . V_39 -> V_33 -> V_35 ;
if ( V_20 == NULL )
{
F_6 ( V_36 ,
V_37 ) ;
goto V_38;
}
break;
default:
F_6 ( V_36 , V_40 ) ;
goto V_38;
}
if ( V_21 != NULL )
{
for ( V_14 = 0 ; V_14 < F_7 ( V_21 ) ; V_14 ++ )
{
V_18 = F_8 ( V_21 , V_14 ) ;
if ( ( V_17 = F_9 ( F_10 () ) ) == NULL )
{
F_6 ( V_36 , V_41 ) ;
goto V_38;
}
V_15 = F_2 ( V_18 -> V_34 ) ;
V_19 = F_11 ( F_12 ( V_15 ) ) ;
if ( V_19 == NULL )
{
F_6 ( V_36 , V_42 ) ;
goto V_38;
}
F_13 ( V_17 , V_19 ) ;
if ( V_16 == NULL )
V_16 = V_17 ;
else
F_14 ( V_16 , V_17 ) ;
V_17 = NULL ;
}
}
if ( V_20 != NULL )
{
unsigned char V_43 [ V_44 ] ;
unsigned char V_45 [ V_46 ] ;
int V_47 , V_48 ;
int V_49 , V_50 ;
unsigned char * V_51 ;
T_7 * V_52 ;
if ( ( V_17 = F_9 ( F_15 () ) ) == NULL )
{
F_6 ( V_36 , V_41 ) ;
goto V_38;
}
F_16 ( V_17 , & V_52 ) ;
V_47 = F_17 ( V_20 ) ;
V_48 = F_18 ( V_20 ) ;
if ( F_19 ( V_43 , V_47 ) <= 0 )
goto V_38;
V_24 -> V_34 = F_20 ( F_21 ( V_20 ) ) ;
if ( V_48 > 0 ) F_22 ( V_45 , V_48 ) ;
F_23 ( V_52 , V_20 , NULL , V_43 , V_45 , 1 ) ;
if ( V_48 > 0 ) {
if ( V_24 -> V_53 == NULL )
V_24 -> V_53 = F_24 () ;
if( F_25 ( V_52 , V_24 -> V_53 ) < 0 )
goto V_38;
}
V_50 = 0 ;
for ( V_14 = 0 ; V_14 < F_26 ( V_23 ) ; V_14 ++ )
{
V_25 = F_27 ( V_23 , V_14 ) ;
if ( V_25 -> V_54 == NULL )
{
F_6 ( V_36 , V_55 ) ;
goto V_38;
}
V_26 = F_28 ( V_25 -> V_54 ) ;
V_49 = F_29 ( V_26 ) ;
F_30 ( V_26 ) ;
if ( V_50 < V_49 ) V_50 = V_49 ;
}
if ( ( V_51 = ( unsigned char * ) F_31 ( V_50 ) ) == NULL )
{
F_6 ( V_36 , V_56 ) ;
goto V_38;
}
for ( V_14 = 0 ; V_14 < F_26 ( V_23 ) ; V_14 ++ )
{
V_25 = F_27 ( V_23 , V_14 ) ;
V_26 = F_28 ( V_25 -> V_54 ) ;
V_49 = F_32 ( V_51 , V_43 , V_47 , V_26 ) ;
F_30 ( V_26 ) ;
if ( V_49 <= 0 )
{
F_6 ( V_36 , V_57 ) ;
F_33 ( V_51 ) ;
goto V_38;
}
F_34 ( V_25 -> V_58 , V_51 , V_49 ) ;
}
F_33 ( V_51 ) ;
F_35 ( V_43 , V_47 ) ;
if ( V_16 == NULL )
V_16 = V_17 ;
else
F_14 ( V_16 , V_17 ) ;
V_17 = NULL ;
}
if ( V_13 == NULL ) {
if ( F_36 ( V_1 ) )
V_13 = F_9 ( F_37 () ) ;
else {
if ( F_38 ( V_1 ) ) {
if ( F_39 ( V_1 -> V_11 . V_29 -> V_59 ) ) {
T_8 * V_60 ;
V_60 = V_1 -> V_11 . V_29 -> V_59 -> V_11 . V_61 ;
if ( V_60 -> V_62 > 0 )
V_13 = F_40 ( V_60 -> V_61 , V_60 -> V_62 ) ;
}
else if ( F_3 ( V_1 -> V_11 . V_29 -> V_59 ) ) {
T_8 * V_60 ;
V_60 = V_1 -> V_11 . V_29 -> V_59 -> V_11 . V_12 -> V_63 . V_64 ;
if ( V_60 -> V_62 > 0 )
V_13 = F_40 ( V_60 -> V_61 , V_60 -> V_62 ) ;
}
}
if( V_13 == NULL ) {
V_13 = F_9 ( F_41 () ) ;
F_42 ( V_13 , 0 ) ;
}
}
}
F_14 ( V_16 , V_13 ) ;
V_13 = NULL ;
if ( 0 )
{
V_38:
if ( V_16 != NULL )
F_43 ( V_16 ) ;
if ( V_17 != NULL )
F_43 ( V_17 ) ;
V_16 = NULL ;
}
return ( V_16 ) ;
}
T_2 * F_44 ( T_1 * V_1 , T_6 * V_26 , T_2 * V_65 , T_9 * V_66 )
{
int V_14 , V_15 ;
T_2 * V_16 = NULL , * V_17 = NULL , * V_67 = NULL , * V_13 = NULL ;
unsigned char * V_51 = NULL ;
T_3 * V_18 ;
T_8 * V_68 = NULL ;
const T_4 * V_19 ;
const T_5 * V_20 = NULL ;
T_7 * V_69 = NULL ;
T_3 * V_70 = NULL ;
F_5 ( T_3 ) * V_21 = NULL ;
F_5 ( V_22 ) * V_23 = NULL ;
T_3 * V_24 = NULL ;
V_22 * V_25 = NULL ;
V_14 = F_2 ( V_1 -> type ) ;
V_1 -> V_27 = V_28 ;
switch ( V_14 )
{
case V_5 :
V_68 = V_1 -> V_11 . V_29 -> V_59 -> V_11 . V_61 ;
V_21 = V_1 -> V_11 . V_29 -> V_30 ;
break;
case V_7 :
V_23 = V_1 -> V_11 . V_31 -> V_32 ;
V_21 = V_1 -> V_11 . V_31 -> V_30 ;
V_68 = V_1 -> V_11 . V_31 -> V_33 -> V_33 ;
V_70 = V_1 -> V_11 . V_31 -> V_33 -> V_34 ;
V_20 = F_45 ( F_12 ( F_2 ( V_70 -> V_34 ) ) ) ;
if ( V_20 == NULL )
{
F_6 ( V_71 , V_72 ) ;
goto V_38;
}
V_24 = V_1 -> V_11 . V_31 -> V_33 -> V_34 ;
break;
case V_6 :
V_23 = V_1 -> V_11 . V_39 -> V_32 ;
V_70 = V_1 -> V_11 . V_39 -> V_33 -> V_34 ;
V_68 = V_1 -> V_11 . V_39 -> V_33 -> V_33 ;
V_20 = F_45 ( F_12 ( F_2 ( V_70 -> V_34 ) ) ) ;
if ( V_20 == NULL )
{
F_6 ( V_71 , V_72 ) ;
goto V_38;
}
V_24 = V_1 -> V_11 . V_39 -> V_33 -> V_34 ;
break;
default:
F_6 ( V_71 , V_40 ) ;
goto V_38;
}
if ( V_21 != NULL )
{
for ( V_14 = 0 ; V_14 < F_7 ( V_21 ) ; V_14 ++ )
{
V_18 = F_8 ( V_21 , V_14 ) ;
if ( ( V_17 = F_9 ( F_10 () ) ) == NULL )
{
F_6 ( V_71 , V_41 ) ;
goto V_38;
}
V_15 = F_2 ( V_18 -> V_34 ) ;
V_19 = F_11 ( F_12 ( V_15 ) ) ;
if ( V_19 == NULL )
{
F_6 ( V_71 , V_42 ) ;
goto V_38;
}
F_13 ( V_17 , V_19 ) ;
if ( V_16 == NULL )
V_16 = V_17 ;
else
F_14 ( V_16 , V_17 ) ;
V_17 = NULL ;
}
}
if ( V_20 != NULL )
{
#if 0
unsigned char key[EVP_MAX_KEY_LENGTH];
unsigned char iv[EVP_MAX_IV_LENGTH];
unsigned char *p;
int keylen,ivlen;
int max;
X509_OBJECT ret;
#endif
int V_49 ;
if ( ( V_67 = F_9 ( F_15 () ) ) == NULL )
{
F_6 ( V_71 , V_41 ) ;
goto V_38;
}
for ( V_14 = 0 ; V_14 < F_26 ( V_23 ) ; V_14 ++ ) {
V_25 = F_27 ( V_23 , V_14 ) ;
if( ! F_46 ( V_25 -> V_73 -> V_74 ,
V_66 -> V_75 -> V_74 ) &&
! F_47 ( V_66 -> V_75 -> V_76 ,
V_25 -> V_73 -> V_77 ) ) break;
V_25 = NULL ;
}
if ( V_25 == NULL ) {
F_6 ( V_71 ,
V_78 ) ;
goto V_38;
}
V_49 = F_29 ( V_26 ) ;
V_51 = ( unsigned char * ) F_31 ( V_49 + 10 ) ;
if ( V_51 == NULL )
{
F_6 ( V_71 , V_56 ) ;
goto V_38;
}
V_49 = F_48 ( V_51 , F_49 ( V_25 -> V_58 ) ,
F_50 ( V_25 -> V_58 ) , V_26 ) ;
if ( V_49 <= 0 )
{
F_6 ( V_71 , V_57 ) ;
goto V_38;
}
V_69 = NULL ;
F_16 ( V_67 , & V_69 ) ;
F_23 ( V_69 , V_20 , NULL , NULL , NULL , 0 ) ;
if ( F_51 ( V_69 , V_70 -> V_53 ) < 0 )
goto V_38;
if ( V_49 != F_52 ( V_69 ) ) {
if( ! F_53 ( V_69 , V_49 ) )
{
F_6 ( V_71 ,
V_79 ) ;
goto V_38;
}
}
F_23 ( V_69 , NULL , NULL , V_51 , NULL , 0 ) ;
F_35 ( V_51 , V_49 ) ;
if ( V_16 == NULL )
V_16 = V_67 ;
else
F_14 ( V_16 , V_67 ) ;
V_67 = NULL ;
}
#if 1
if ( F_36 ( V_1 ) || ( V_65 != NULL ) )
{
V_13 = V_65 ;
}
else
{
#if 0
bio=BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(bio,0);
if (data_body->length > 0)
BIO_write(bio,(char *)data_body->data,data_body->length);
#else
if ( V_68 -> V_62 > 0 )
V_13 = F_40 ( V_68 -> V_61 , V_68 -> V_62 ) ;
else {
V_13 = F_9 ( F_41 () ) ;
F_42 ( V_13 , 0 ) ;
}
#endif
}
F_14 ( V_16 , V_13 ) ;
V_13 = NULL ;
#endif
if ( 0 )
{
V_38:
if ( V_16 != NULL ) F_43 ( V_16 ) ;
if ( V_17 != NULL ) F_43 ( V_17 ) ;
if ( V_67 != NULL ) F_43 ( V_67 ) ;
if ( V_13 != NULL ) F_43 ( V_13 ) ;
V_16 = NULL ;
}
if ( V_51 != NULL )
F_33 ( V_51 ) ;
return ( V_16 ) ;
}
int F_54 ( T_1 * V_1 , T_2 * V_13 )
{
int V_80 = 0 ;
int V_14 , V_15 ;
T_2 * V_17 ;
T_10 * V_81 = NULL ;
T_10 * V_82 = NULL ;
T_11 * V_83 ;
T_12 * V_84 , V_85 ;
F_5 ( V_86 ) * V_87 ;
F_5 ( T_11 ) * V_88 = NULL ;
T_8 * V_60 = NULL ;
F_55 ( & V_85 ) ;
V_14 = F_2 ( V_1 -> type ) ;
V_1 -> V_27 = V_28 ;
switch ( V_14 )
{
case V_7 :
V_88 = V_1 -> V_11 . V_31 -> V_89 ;
V_60 = F_56 () ;
V_1 -> V_11 . V_31 -> V_33 -> V_33 = V_60 ;
break;
case V_6 :
V_60 = F_56 () ;
V_1 -> V_11 . V_39 -> V_33 -> V_33 = V_60 ;
break;
case V_5 :
V_88 = V_1 -> V_11 . V_29 -> V_89 ;
V_60 = V_1 -> V_11 . V_29 -> V_59 -> V_11 . V_61 ;
if( V_1 -> V_90 ) {
F_57 ( V_60 ) ;
V_1 -> V_11 . V_29 -> V_59 -> V_11 . V_61 = NULL ;
}
break;
}
if ( V_88 != NULL )
{
if ( ( V_82 = F_58 () ) == NULL )
{
F_6 ( V_91 , V_41 ) ;
goto V_38;
}
for ( V_14 = 0 ; V_14 < F_59 ( V_88 ) ; V_14 ++ )
{
V_83 = F_60 ( V_88 , V_14 ) ;
if ( V_83 -> V_26 == NULL ) continue;
V_15 = F_2 ( V_83 -> V_92 -> V_34 ) ;
V_17 = V_13 ;
for (; ; )
{
if ( ( V_17 = F_61 ( V_17 , V_93 ) )
== NULL )
{
F_6 ( V_91 , V_94 ) ;
goto V_38;
}
F_62 ( V_17 , & V_84 ) ;
if ( V_84 == NULL )
{
F_6 ( V_91 , V_95 ) ;
goto V_38;
}
if ( F_63 ( V_84 ) == V_15 )
break;
else
V_17 = F_64 ( V_17 ) ;
}
F_65 ( & V_85 , V_84 ) ;
if ( ! F_66 ( V_82 , F_29 ( V_83 -> V_26 ) ) )
{
F_6 ( V_91 , V_41 ) ;
goto V_38;
}
V_87 = V_83 -> V_96 ;
if ( ( V_87 != NULL ) && ( F_67 ( V_87 ) != 0 ) )
{
unsigned char V_97 [ V_98 ] , * V_99 = NULL ;
unsigned int V_100 , V_101 ;
T_8 * V_102 ;
T_13 * V_103 ;
const T_4 * V_104 ;
if ( ! F_68 ( V_83 ,
V_105 ) )
{
V_103 = F_69 ( NULL , 0 ) ;
F_70 ( V_83 ,
V_105 ,
V_106 , V_103 ) ;
}
V_104 = F_71 ( & V_85 ) ;
F_72 ( & V_85 , V_97 , & V_100 ) ;
V_102 = F_56 () ;
F_34 ( V_102 , V_97 , V_100 ) ;
F_70 ( V_83 ,
V_107 ,
V_10 , V_102 ) ;
F_73 ( & V_85 , V_104 , NULL ) ;
V_101 = F_74 ( ( V_108 * ) V_87 , & V_99 ,
F_75 ( V_109 ) ) ;
if( ! V_99 ) goto V_38;
F_76 ( & V_85 , V_99 , V_101 ) ;
F_33 ( V_99 ) ;
}
#ifndef F_77
if ( V_83 -> V_26 -> type == V_110 )
V_85 . V_102 = F_78 () ;
#endif
if ( ! F_79 ( & V_85 , ( unsigned char * ) V_82 -> V_61 ,
( unsigned int * ) & V_82 -> V_62 , V_83 -> V_26 ) )
{
F_6 ( V_91 , V_57 ) ;
goto V_38;
}
if ( ! F_80 ( V_83 -> V_111 ,
( unsigned char * ) V_82 -> V_61 , V_82 -> V_62 ) )
{
F_6 ( V_91 , V_112 ) ;
goto V_38;
}
}
}
if ( ! F_36 ( V_1 ) )
{
V_17 = F_61 ( V_13 , V_113 ) ;
if ( V_17 == NULL )
{
F_6 ( V_91 , V_114 ) ;
goto V_38;
}
F_81 ( V_17 , & V_81 ) ;
F_82 ( V_17 , V_115 ) ;
F_42 ( V_17 , 0 ) ;
V_60 -> V_61 = ( unsigned char * ) V_81 -> V_61 ;
V_60 -> V_62 = V_81 -> V_62 ;
#if 0
M_ASN1_OCTET_STRING_set(os,
(unsigned char *)buf_mem->data,buf_mem->length);
#endif
}
V_80 = 1 ;
V_38:
F_83 ( & V_85 ) ;
if ( V_82 != NULL ) F_84 ( V_82 ) ;
return ( V_80 ) ;
}
int F_85 ( T_14 * V_116 , T_15 * V_52 , T_2 * V_13 ,
T_1 * V_1 , T_11 * V_83 )
{
T_16 * V_117 ;
int V_80 = 0 , V_14 ;
F_5 ( T_9 ) * V_54 ;
T_9 * V_118 ;
if ( F_38 ( V_1 ) )
{
V_54 = V_1 -> V_11 . V_29 -> V_54 ;
}
else if ( F_86 ( V_1 ) )
{
V_54 = V_1 -> V_11 . V_31 -> V_54 ;
}
else
{
F_6 ( V_119 , V_120 ) ;
goto V_38;
}
V_117 = V_83 -> V_73 ;
V_118 = F_87 ( V_54 , V_117 -> V_74 , V_117 -> V_77 ) ;
if ( V_118 == NULL )
{
F_6 ( V_119 , V_121 ) ;
goto V_38;
}
if( ! F_88 ( V_52 , V_116 , V_118 , V_54 ) )
{
F_6 ( V_119 , V_122 ) ;
goto V_38;
}
F_89 ( V_52 , V_123 ) ;
V_14 = F_90 ( V_52 ) ;
if ( V_14 <= 0 )
{
F_6 ( V_119 , V_122 ) ;
F_91 ( V_52 ) ;
goto V_38;
}
F_91 ( V_52 ) ;
return F_92 ( V_13 , V_1 , V_83 , V_118 ) ;
V_38:
return V_80 ;
}
int F_92 ( T_2 * V_13 , T_1 * V_1 , T_11 * V_83 ,
T_9 * V_118 )
{
T_8 * V_60 ;
T_12 V_124 , * V_84 ;
int V_80 = 0 , V_14 ;
int V_125 ;
F_5 ( V_86 ) * V_87 ;
T_2 * V_17 ;
T_6 * V_26 ;
F_55 ( & V_124 ) ;
if ( ! F_38 ( V_1 ) &&
! F_86 ( V_1 ) ) {
F_6 ( V_126 ,
V_120 ) ;
goto V_38;
}
V_125 = F_2 ( V_83 -> V_92 -> V_34 ) ;
V_17 = V_13 ;
for (; ; )
{
if ( ( V_17 == NULL ) ||
( ( V_17 = F_61 ( V_17 , V_93 ) ) == NULL ) )
{
F_6 ( V_126 ,
V_94 ) ;
goto V_38;
}
F_62 ( V_17 , & V_84 ) ;
if ( V_84 == NULL )
{
F_6 ( V_126 ,
V_95 ) ;
goto V_38;
}
if ( F_63 ( V_84 ) == V_125 )
break;
V_17 = F_64 ( V_17 ) ;
}
F_65 ( & V_124 , V_84 ) ;
V_87 = V_83 -> V_96 ;
if ( ( V_87 != NULL ) && ( F_67 ( V_87 ) != 0 ) )
{
unsigned char V_127 [ V_98 ] , * V_99 = NULL ;
unsigned int V_100 , V_101 ;
T_8 * V_128 ;
F_72 ( & V_124 , V_127 , & V_100 ) ;
V_128 = F_93 ( V_87 ) ;
if ( ! V_128 )
{
F_6 ( V_126 ,
V_94 ) ;
goto V_38;
}
if ( ( V_128 -> V_62 != ( int ) V_100 ) ||
( memcmp ( V_128 -> V_61 , V_127 , V_100 ) ) )
{
#if 0
{
int ii;
for (ii=0; ii<message_digest->length; ii++)
printf("%02X",message_digest->data[ii]); printf(" sent\n");
for (ii=0; ii<md_len; ii++) printf("%02X",md_dat[ii]); printf(" calc\n");
}
#endif
F_6 ( V_126 ,
V_129 ) ;
V_80 = - 1 ;
goto V_38;
}
F_94 ( & V_124 , F_95 ( V_125 ) , NULL ) ;
V_101 = F_74 ( ( V_108 * ) V_87 , & V_99 ,
F_75 ( V_130 ) ) ;
F_96 ( & V_124 , V_99 , V_101 ) ;
F_33 ( V_99 ) ;
}
V_60 = V_83 -> V_111 ;
V_26 = F_28 ( V_118 ) ;
if ( ! V_26 )
{
V_80 = - 1 ;
goto V_38;
}
#ifndef F_77
if( V_26 -> type == V_110 ) V_124 . V_102 = F_78 () ;
#endif
V_14 = F_97 ( & V_124 , V_60 -> V_61 , V_60 -> V_62 , V_26 ) ;
F_30 ( V_26 ) ;
if ( V_14 <= 0 )
{
F_6 ( V_126 ,
V_131 ) ;
V_80 = - 1 ;
goto V_38;
}
else
V_80 = 1 ;
V_38:
F_83 ( & V_124 ) ;
return ( V_80 ) ;
}
T_16 * F_98 ( T_1 * V_1 , int V_132 )
{
F_5 ( V_22 ) * V_23 ;
V_22 * V_25 ;
int V_14 ;
V_14 = F_2 ( V_1 -> type ) ;
if ( V_14 != V_7 ) return ( NULL ) ;
V_23 = V_1 -> V_11 . V_31 -> V_32 ;
V_25 = F_27 ( V_23 , 0 ) ;
if ( F_26 ( V_23 ) <= V_132 ) return ( NULL ) ;
V_25 = F_27 ( V_23 , V_132 ) ;
return ( V_25 -> V_73 ) ;
}
T_17 * F_68 ( T_11 * V_83 , int V_3 )
{
return ( F_99 ( V_83 -> V_96 , V_3 ) ) ;
}
T_17 * F_100 ( T_11 * V_83 , int V_3 )
{
return ( F_99 ( V_83 -> V_133 , V_3 ) ) ;
}
int F_70 ( T_11 * V_134 , int V_3 , int V_135 ,
void * V_63 )
{
return ( F_101 ( & ( V_134 -> V_96 ) , V_3 , V_135 , V_63 ) ) ;
}
int F_102 ( T_11 * V_134 , int V_3 , int V_135 ,
void * V_63 )
{
return ( F_101 ( & ( V_134 -> V_133 ) , V_3 , V_135 , V_63 ) ) ;
}
