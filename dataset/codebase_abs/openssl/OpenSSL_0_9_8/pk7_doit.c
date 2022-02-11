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
static T_2 * F_3 ( T_1 * V_1 )
{
if ( F_4 ( V_1 ) )
return V_1 -> V_10 . V_11 ;
if ( F_1 ( V_1 ) && V_1 -> V_10 . V_12
&& ( V_1 -> V_10 . V_12 -> type == V_13 ) )
return V_1 -> V_10 . V_12 -> V_14 . V_15 ;
return NULL ;
}
static int F_5 ( T_3 * * V_16 , T_4 * V_17 )
{
T_3 * V_18 ;
const T_5 * V_19 ;
if ( ( V_18 = F_6 ( F_7 () ) ) == NULL )
{
F_8 ( V_20 , V_21 ) ;
goto V_22;
}
V_19 = F_9 ( V_17 -> V_23 ) ;
if ( V_19 == NULL )
{
F_8 ( V_20 , V_24 ) ;
goto V_22;
}
F_10 ( V_18 , V_19 ) ;
if ( * V_16 == NULL )
* V_16 = V_18 ;
else if ( ! F_11 ( * V_16 , V_18 ) )
{
F_8 ( V_20 , V_21 ) ;
goto V_22;
}
V_18 = NULL ;
return 1 ;
V_22:
if ( V_18 )
F_12 ( V_18 ) ;
return 0 ;
}
T_3 * F_13 ( T_1 * V_1 , T_3 * V_25 )
{
int V_26 ;
T_3 * V_27 = NULL , * V_18 = NULL ;
T_4 * V_28 = NULL ;
const T_6 * V_29 = NULL ;
F_14 ( T_4 ) * V_30 = NULL ;
F_14 ( V_31 ) * V_32 = NULL ;
T_4 * V_33 = NULL ;
V_31 * V_34 = NULL ;
T_7 * V_35 ;
T_2 * V_36 = NULL ;
V_26 = F_2 ( V_1 -> type ) ;
V_1 -> V_37 = V_38 ;
switch ( V_26 )
{
case V_5 :
V_30 = V_1 -> V_10 . V_39 -> V_40 ;
V_36 = F_3 ( V_1 -> V_10 . V_39 -> V_41 ) ;
break;
case V_7 :
V_32 = V_1 -> V_10 . V_42 -> V_43 ;
V_30 = V_1 -> V_10 . V_42 -> V_40 ;
V_33 = V_1 -> V_10 . V_42 -> V_44 -> V_23 ;
V_29 = V_1 -> V_10 . V_42 -> V_44 -> V_45 ;
if ( V_29 == NULL )
{
F_8 ( V_46 ,
V_47 ) ;
goto V_22;
}
break;
case V_6 :
V_32 = V_1 -> V_10 . V_48 -> V_43 ;
V_33 = V_1 -> V_10 . V_48 -> V_44 -> V_23 ;
V_29 = V_1 -> V_10 . V_48 -> V_44 -> V_45 ;
if ( V_29 == NULL )
{
F_8 ( V_46 ,
V_47 ) ;
goto V_22;
}
break;
case V_8 :
V_28 = V_1 -> V_10 . V_49 -> V_19 ;
V_36 = F_3 ( V_1 -> V_10 . V_49 -> V_41 ) ;
break;
default:
F_8 ( V_46 , V_50 ) ;
goto V_22;
}
for ( V_26 = 0 ; V_26 < F_15 ( V_30 ) ; V_26 ++ )
if ( ! F_5 ( & V_27 , F_16 ( V_30 , V_26 ) ) )
goto V_22;
if ( V_28 && ! F_5 ( & V_27 , V_28 ) )
goto V_22;
if ( V_29 != NULL )
{
unsigned char V_51 [ V_52 ] ;
unsigned char V_53 [ V_54 ] ;
int V_55 , V_56 ;
int V_57 , V_58 ;
unsigned char * V_59 ;
T_8 * V_60 ;
if ( ( V_18 = F_6 ( F_17 () ) ) == NULL )
{
F_8 ( V_46 , V_21 ) ;
goto V_22;
}
F_18 ( V_18 , & V_60 ) ;
V_55 = F_19 ( V_29 ) ;
V_56 = F_20 ( V_29 ) ;
V_33 -> V_23 = F_21 ( F_22 ( V_29 ) ) ;
if ( V_56 > 0 ) F_23 ( V_53 , V_56 ) ;
if ( F_24 ( V_60 , V_29 , NULL , NULL , NULL , 1 ) <= 0 )
goto V_22;
if ( F_25 ( V_60 , V_51 ) <= 0 )
goto V_22;
if ( F_24 ( V_60 , NULL , NULL , V_51 , V_53 , 1 ) <= 0 )
goto V_22;
if ( V_56 > 0 ) {
if ( V_33 -> V_61 == NULL )
V_33 -> V_61 = F_26 () ;
if( F_27 ( V_60 , V_33 -> V_61 ) < 0 )
goto V_22;
}
V_58 = 0 ;
for ( V_26 = 0 ; V_26 < F_28 ( V_32 ) ; V_26 ++ )
{
V_34 = F_29 ( V_32 , V_26 ) ;
if ( V_34 -> V_62 == NULL )
{
F_8 ( V_46 , V_63 ) ;
goto V_22;
}
V_35 = F_30 ( V_34 -> V_62 ) ;
V_57 = F_31 ( V_35 ) ;
F_32 ( V_35 ) ;
if ( V_58 < V_57 ) V_58 = V_57 ;
}
if ( ( V_59 = ( unsigned char * ) F_33 ( V_58 ) ) == NULL )
{
F_8 ( V_46 , V_64 ) ;
goto V_22;
}
for ( V_26 = 0 ; V_26 < F_28 ( V_32 ) ; V_26 ++ )
{
V_34 = F_29 ( V_32 , V_26 ) ;
V_35 = F_30 ( V_34 -> V_62 ) ;
V_57 = F_34 ( V_59 , V_51 , V_55 , V_35 ) ;
F_32 ( V_35 ) ;
if ( V_57 <= 0 )
{
F_8 ( V_46 , V_65 ) ;
F_35 ( V_59 ) ;
goto V_22;
}
if ( ! F_36 ( V_34 -> V_66 , V_59 , V_57 ) )
{
F_8 ( V_46 ,
V_64 ) ;
F_35 ( V_59 ) ;
goto V_22;
}
}
F_35 ( V_59 ) ;
F_37 ( V_51 , V_55 ) ;
if ( V_27 == NULL )
V_27 = V_18 ;
else
F_11 ( V_27 , V_18 ) ;
V_18 = NULL ;
}
if ( V_25 == NULL )
{
if ( F_38 ( V_1 ) )
V_25 = F_6 ( F_39 () ) ;
else if ( V_36 && V_36 -> V_67 > 0 )
V_25 = F_40 ( V_36 -> V_11 , V_36 -> V_67 ) ;
if( V_25 == NULL )
{
V_25 = F_6 ( F_41 () ) ;
F_42 ( V_25 , 0 ) ;
}
}
F_11 ( V_27 , V_25 ) ;
V_25 = NULL ;
if ( 0 )
{
V_22:
if ( V_27 != NULL )
F_43 ( V_27 ) ;
if ( V_18 != NULL )
F_43 ( V_18 ) ;
V_27 = NULL ;
}
return ( V_27 ) ;
}
T_3 * F_44 ( T_1 * V_1 , T_7 * V_35 , T_3 * V_68 , T_9 * V_69 )
{
int V_26 , V_70 ;
T_3 * V_27 = NULL , * V_18 = NULL , * V_71 = NULL , * V_25 = NULL ;
unsigned char * V_59 = NULL ;
T_4 * V_28 ;
T_2 * V_72 = NULL ;
const T_5 * V_73 ;
const T_6 * V_29 = NULL ;
T_8 * V_74 = NULL ;
T_4 * V_75 = NULL ;
F_14 ( T_4 ) * V_30 = NULL ;
F_14 ( V_31 ) * V_32 = NULL ;
T_4 * V_33 = NULL ;
V_31 * V_34 = NULL ;
V_26 = F_2 ( V_1 -> type ) ;
V_1 -> V_37 = V_38 ;
switch ( V_26 )
{
case V_5 :
V_72 = F_3 ( V_1 -> V_10 . V_39 -> V_41 ) ;
V_30 = V_1 -> V_10 . V_39 -> V_40 ;
break;
case V_7 :
V_32 = V_1 -> V_10 . V_42 -> V_43 ;
V_30 = V_1 -> V_10 . V_42 -> V_40 ;
V_72 = V_1 -> V_10 . V_42 -> V_44 -> V_44 ;
V_75 = V_1 -> V_10 . V_42 -> V_44 -> V_23 ;
V_29 = F_45 ( V_75 -> V_23 ) ;
if ( V_29 == NULL )
{
F_8 ( V_76 , V_77 ) ;
goto V_22;
}
V_33 = V_1 -> V_10 . V_42 -> V_44 -> V_23 ;
break;
case V_6 :
V_32 = V_1 -> V_10 . V_48 -> V_43 ;
V_75 = V_1 -> V_10 . V_48 -> V_44 -> V_23 ;
V_72 = V_1 -> V_10 . V_48 -> V_44 -> V_44 ;
V_29 = F_45 ( V_75 -> V_23 ) ;
if ( V_29 == NULL )
{
F_8 ( V_76 , V_77 ) ;
goto V_22;
}
V_33 = V_1 -> V_10 . V_48 -> V_44 -> V_23 ;
break;
default:
F_8 ( V_76 , V_50 ) ;
goto V_22;
}
if ( V_30 != NULL )
{
for ( V_26 = 0 ; V_26 < F_15 ( V_30 ) ; V_26 ++ )
{
V_28 = F_16 ( V_30 , V_26 ) ;
if ( ( V_18 = F_6 ( F_7 () ) ) == NULL )
{
F_8 ( V_76 , V_21 ) ;
goto V_22;
}
V_70 = F_2 ( V_28 -> V_23 ) ;
V_73 = F_46 ( V_70 ) ;
if ( V_73 == NULL )
{
F_8 ( V_76 , V_24 ) ;
goto V_22;
}
F_10 ( V_18 , V_73 ) ;
if ( V_27 == NULL )
V_27 = V_18 ;
else
F_11 ( V_27 , V_18 ) ;
V_18 = NULL ;
}
}
if ( V_29 != NULL )
{
#if 0
unsigned char key[EVP_MAX_KEY_LENGTH];
unsigned char iv[EVP_MAX_IV_LENGTH];
unsigned char *p;
int keylen,ivlen;
int max;
X509_OBJECT ret;
#endif
int V_57 ;
if ( ( V_71 = F_6 ( F_17 () ) ) == NULL )
{
F_8 ( V_76 , V_21 ) ;
goto V_22;
}
for ( V_26 = 0 ; V_26 < F_28 ( V_32 ) ; V_26 ++ ) {
V_34 = F_29 ( V_32 , V_26 ) ;
if( ! F_47 ( V_34 -> V_78 -> V_79 ,
V_69 -> V_80 -> V_79 ) &&
! F_48 ( V_69 -> V_80 -> V_81 ,
V_34 -> V_78 -> V_82 ) ) break;
V_34 = NULL ;
}
if ( V_34 == NULL ) {
F_8 ( V_76 ,
V_83 ) ;
goto V_22;
}
V_57 = F_31 ( V_35 ) ;
V_59 = ( unsigned char * ) F_33 ( V_57 + 10 ) ;
if ( V_59 == NULL )
{
F_8 ( V_76 , V_64 ) ;
goto V_22;
}
V_57 = F_49 ( V_59 , F_50 ( V_34 -> V_66 ) ,
F_51 ( V_34 -> V_66 ) , V_35 ) ;
if ( V_57 <= 0 )
{
F_8 ( V_76 , V_65 ) ;
goto V_22;
}
V_74 = NULL ;
F_18 ( V_71 , & V_74 ) ;
if ( F_24 ( V_74 , V_29 , NULL , NULL , NULL , 0 ) <= 0 )
goto V_22;
if ( F_52 ( V_74 , V_75 -> V_61 ) < 0 )
goto V_22;
if ( V_57 != F_53 ( V_74 ) ) {
if( ! F_54 ( V_74 , V_57 ) )
{
F_8 ( V_76 ,
V_84 ) ;
goto V_22;
}
}
if ( F_24 ( V_74 , NULL , NULL , V_59 , NULL , 0 ) <= 0 )
goto V_22;
F_37 ( V_59 , V_57 ) ;
if ( V_27 == NULL )
V_27 = V_71 ;
else
F_11 ( V_27 , V_71 ) ;
V_71 = NULL ;
}
#if 1
if ( F_38 ( V_1 ) || ( V_68 != NULL ) )
{
V_25 = V_68 ;
}
else
{
#if 0
bio=BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(bio,0);
if (data_body->length > 0)
BIO_write(bio,(char *)data_body->data,data_body->length);
#else
if ( V_72 -> V_67 > 0 )
V_25 = F_40 ( V_72 -> V_11 , V_72 -> V_67 ) ;
else {
V_25 = F_6 ( F_41 () ) ;
F_42 ( V_25 , 0 ) ;
}
#endif
}
F_11 ( V_27 , V_25 ) ;
V_25 = NULL ;
#endif
if ( 0 )
{
V_22:
if ( V_27 != NULL ) F_43 ( V_27 ) ;
if ( V_18 != NULL ) F_43 ( V_18 ) ;
if ( V_71 != NULL ) F_43 ( V_71 ) ;
if ( V_25 != NULL ) F_43 ( V_25 ) ;
V_27 = NULL ;
}
if ( V_59 != NULL )
F_35 ( V_59 ) ;
return ( V_27 ) ;
}
static T_3 * F_55 ( T_10 * * V_85 , T_3 * V_25 , int V_3 )
{
for (; ; )
{
V_25 = F_56 ( V_25 , V_86 ) ;
if ( V_25 == NULL )
{
F_8 ( V_87 , V_88 ) ;
return NULL ;
}
F_57 ( V_25 , V_85 ) ;
if ( * V_85 == NULL )
{
F_8 ( V_87 , V_89 ) ;
return NULL ;
}
if ( F_58 ( * V_85 ) == V_3 )
return V_25 ;
V_25 = F_59 ( V_25 ) ;
}
return NULL ;
}
int F_60 ( T_1 * V_1 , T_3 * V_25 )
{
int V_90 = 0 ;
int V_26 , V_70 ;
T_3 * V_18 ;
T_11 * V_91 = NULL ;
T_11 * V_92 = NULL ;
T_12 * V_93 ;
T_10 * V_94 , V_95 ;
F_14 ( V_96 ) * V_97 ;
F_14 ( T_12 ) * V_98 = NULL ;
T_2 * V_36 = NULL ;
F_61 ( & V_95 ) ;
V_26 = F_2 ( V_1 -> type ) ;
V_1 -> V_37 = V_38 ;
switch ( V_26 )
{
case V_7 :
V_98 = V_1 -> V_10 . V_42 -> V_99 ;
if ( ! ( V_36 = F_62 () ) )
{
F_8 ( V_100 , V_64 ) ;
goto V_22;
}
V_1 -> V_10 . V_42 -> V_44 -> V_44 = V_36 ;
break;
case V_6 :
if ( ! ( V_36 = F_62 () ) )
{
F_8 ( V_100 , V_64 ) ;
goto V_22;
}
V_1 -> V_10 . V_48 -> V_44 -> V_44 = V_36 ;
break;
case V_5 :
V_98 = V_1 -> V_10 . V_39 -> V_99 ;
V_36 = F_3 ( V_1 -> V_10 . V_39 -> V_41 ) ;
if( F_4 ( V_1 -> V_10 . V_39 -> V_41 ) && V_1 -> V_101 ) {
F_63 ( V_36 ) ;
V_1 -> V_10 . V_39 -> V_41 -> V_10 . V_11 = NULL ;
}
break;
case V_8 :
V_36 = F_3 ( V_1 -> V_10 . V_49 -> V_41 ) ;
if( F_4 ( V_1 -> V_10 . V_49 -> V_41 ) && V_1 -> V_101 )
{
F_63 ( V_36 ) ;
V_1 -> V_10 . V_49 -> V_41 -> V_10 . V_11 = NULL ;
}
break;
}
if ( V_98 != NULL )
{
if ( ( V_92 = F_64 () ) == NULL )
{
F_8 ( V_100 , V_21 ) ;
goto V_22;
}
for ( V_26 = 0 ; V_26 < F_65 ( V_98 ) ; V_26 ++ )
{
V_93 = F_66 ( V_98 , V_26 ) ;
if ( V_93 -> V_35 == NULL ) continue;
V_70 = F_2 ( V_93 -> V_102 -> V_23 ) ;
V_18 = V_25 ;
V_18 = F_55 ( & V_94 , V_18 , V_70 ) ;
if ( V_18 == NULL )
goto V_22;
F_67 ( & V_95 , V_94 ) ;
if ( ! F_68 ( V_92 , F_31 ( V_93 -> V_35 ) ) )
{
F_8 ( V_100 , V_21 ) ;
goto V_22;
}
V_97 = V_93 -> V_103 ;
if ( ( V_97 != NULL ) && ( F_69 ( V_97 ) != 0 ) )
{
unsigned char V_104 [ V_105 ] , * V_106 = NULL ;
unsigned int V_107 , V_108 ;
T_2 * V_49 ;
T_13 * V_109 ;
const T_5 * V_110 ;
if ( ! F_70 ( V_93 ,
V_111 ) )
{
if ( ! ( V_109 = F_71 ( NULL , 0 ) ) )
{
F_8 ( V_100 ,
V_64 ) ;
goto V_22;
}
F_72 ( V_93 ,
V_111 ,
V_112 , V_109 ) ;
}
V_110 = F_73 ( & V_95 ) ;
F_74 ( & V_95 , V_104 , & V_107 ) ;
if ( ! ( V_49 = F_62 () ) )
{
F_8 ( V_100 ,
V_64 ) ;
goto V_22;
}
if ( ! F_36 ( V_49 , V_104 ,
V_107 ) )
{
F_8 ( V_100 ,
V_64 ) ;
goto V_22;
}
F_72 ( V_93 ,
V_113 ,
V_13 , V_49 ) ;
F_75 ( & V_95 , V_110 , NULL ) ;
V_108 = F_76 ( ( V_114 * ) V_97 , & V_106 ,
F_77 ( V_115 ) ) ;
if( ! V_106 ) goto V_22;
F_78 ( & V_95 , V_106 , V_108 ) ;
F_35 ( V_106 ) ;
}
#ifndef F_79
if ( V_93 -> V_35 -> type == V_116 )
V_95 . V_49 = F_80 () ;
#endif
#ifndef F_81
if ( V_93 -> V_35 -> type == V_117 )
V_95 . V_49 = F_82 () ;
#endif
if ( ! F_83 ( & V_95 , ( unsigned char * ) V_92 -> V_11 ,
( unsigned int * ) & V_92 -> V_67 , V_93 -> V_35 ) )
{
F_8 ( V_100 , V_65 ) ;
goto V_22;
}
if ( ! F_84 ( V_93 -> V_118 ,
( unsigned char * ) V_92 -> V_11 , V_92 -> V_67 ) )
{
F_8 ( V_100 , V_119 ) ;
goto V_22;
}
}
}
else if ( V_26 == V_8 )
{
unsigned char V_104 [ V_105 ] ;
unsigned int V_107 ;
if ( ! F_55 ( & V_94 , V_25 ,
F_2 ( V_1 -> V_10 . V_49 -> V_19 -> V_23 ) ) )
goto V_22;
F_74 ( V_94 , V_104 , & V_107 ) ;
F_36 ( V_1 -> V_10 . V_49 -> V_49 , V_104 , V_107 ) ;
}
if ( ! F_38 ( V_1 ) )
{
V_18 = F_56 ( V_25 , V_120 ) ;
if ( V_18 == NULL )
{
F_8 ( V_100 , V_121 ) ;
goto V_22;
}
F_85 ( V_18 , & V_91 ) ;
F_86 ( V_18 , V_122 ) ;
F_42 ( V_18 , 0 ) ;
V_36 -> V_11 = ( unsigned char * ) V_91 -> V_11 ;
V_36 -> V_67 = V_91 -> V_67 ;
#if 0
M_ASN1_OCTET_STRING_set(os,
(unsigned char *)buf_mem->data,buf_mem->length);
#endif
}
V_90 = 1 ;
V_22:
F_87 ( & V_95 ) ;
if ( V_92 != NULL ) F_88 ( V_92 ) ;
return ( V_90 ) ;
}
int F_89 ( T_14 * V_123 , T_15 * V_60 , T_3 * V_25 ,
T_1 * V_1 , T_12 * V_93 )
{
T_16 * V_124 ;
int V_90 = 0 , V_26 ;
F_14 ( T_9 ) * V_62 ;
T_9 * V_125 ;
if ( F_90 ( V_1 ) )
{
V_62 = V_1 -> V_10 . V_39 -> V_62 ;
}
else if ( F_91 ( V_1 ) )
{
V_62 = V_1 -> V_10 . V_42 -> V_62 ;
}
else
{
F_8 ( V_126 , V_127 ) ;
goto V_22;
}
V_124 = V_93 -> V_78 ;
V_125 = F_92 ( V_62 , V_124 -> V_79 , V_124 -> V_82 ) ;
if ( V_125 == NULL )
{
F_8 ( V_126 , V_128 ) ;
goto V_22;
}
if( ! F_93 ( V_60 , V_123 , V_125 , V_62 ) )
{
F_8 ( V_126 , V_129 ) ;
goto V_22;
}
F_94 ( V_60 , V_130 ) ;
V_26 = F_95 ( V_60 ) ;
if ( V_26 <= 0 )
{
F_8 ( V_126 , V_129 ) ;
F_96 ( V_60 ) ;
goto V_22;
}
F_96 ( V_60 ) ;
return F_97 ( V_25 , V_1 , V_93 , V_125 ) ;
V_22:
return V_90 ;
}
int F_97 ( T_3 * V_25 , T_1 * V_1 , T_12 * V_93 ,
T_9 * V_125 )
{
T_2 * V_36 ;
T_10 V_131 , * V_94 ;
int V_90 = 0 , V_26 ;
int V_132 ;
F_14 ( V_96 ) * V_97 ;
T_3 * V_18 ;
T_7 * V_35 ;
F_61 ( & V_131 ) ;
if ( ! F_90 ( V_1 ) &&
! F_91 ( V_1 ) ) {
F_8 ( V_133 ,
V_127 ) ;
goto V_22;
}
V_132 = F_2 ( V_93 -> V_102 -> V_23 ) ;
V_18 = V_25 ;
for (; ; )
{
if ( ( V_18 == NULL ) ||
( ( V_18 = F_56 ( V_18 , V_86 ) ) == NULL ) )
{
F_8 ( V_133 ,
V_88 ) ;
goto V_22;
}
F_57 ( V_18 , & V_94 ) ;
if ( V_94 == NULL )
{
F_8 ( V_133 ,
V_89 ) ;
goto V_22;
}
if ( F_58 ( V_94 ) == V_132 )
break;
if ( F_98 ( F_73 ( V_94 ) ) == V_132 )
break;
V_18 = F_59 ( V_18 ) ;
}
F_67 ( & V_131 , V_94 ) ;
V_97 = V_93 -> V_103 ;
if ( ( V_97 != NULL ) && ( F_69 ( V_97 ) != 0 ) )
{
unsigned char V_134 [ V_105 ] , * V_106 = NULL ;
unsigned int V_107 , V_108 ;
T_2 * V_135 ;
F_74 ( & V_131 , V_134 , & V_107 ) ;
V_135 = F_99 ( V_97 ) ;
if ( ! V_135 )
{
F_8 ( V_133 ,
V_88 ) ;
goto V_22;
}
if ( ( V_135 -> V_67 != ( int ) V_107 ) ||
( memcmp ( V_135 -> V_11 , V_134 , V_107 ) ) )
{
#if 0
{
int ii;
for (ii=0; ii<message_digest->length; ii++)
printf("%02X",message_digest->data[ii]); printf(" sent\n");
for (ii=0; ii<md_len; ii++) printf("%02X",md_dat[ii]); printf(" calc\n");
}
#endif
F_8 ( V_133 ,
V_136 ) ;
V_90 = - 1 ;
goto V_22;
}
F_100 ( & V_131 , F_46 ( V_132 ) , NULL ) ;
V_108 = F_76 ( ( V_114 * ) V_97 , & V_106 ,
F_77 ( V_137 ) ) ;
F_101 ( & V_131 , V_106 , V_108 ) ;
F_35 ( V_106 ) ;
}
V_36 = V_93 -> V_118 ;
V_35 = F_30 ( V_125 ) ;
if ( ! V_35 )
{
V_90 = - 1 ;
goto V_22;
}
#ifndef F_79
if( V_35 -> type == V_116 ) V_131 . V_49 = F_80 () ;
#endif
#ifndef F_81
if ( V_35 -> type == V_117 ) V_131 . V_49 = F_82 () ;
#endif
V_26 = F_102 ( & V_131 , V_36 -> V_11 , V_36 -> V_67 , V_35 ) ;
F_32 ( V_35 ) ;
if ( V_26 <= 0 )
{
F_8 ( V_133 ,
V_138 ) ;
V_90 = - 1 ;
goto V_22;
}
else
V_90 = 1 ;
V_22:
F_87 ( & V_131 ) ;
return ( V_90 ) ;
}
T_16 * F_103 ( T_1 * V_1 , int V_139 )
{
F_14 ( V_31 ) * V_32 ;
V_31 * V_34 ;
int V_26 ;
V_26 = F_2 ( V_1 -> type ) ;
if ( V_26 != V_7 ) return ( NULL ) ;
V_32 = V_1 -> V_10 . V_42 -> V_43 ;
V_34 = F_29 ( V_32 , 0 ) ;
if ( F_28 ( V_32 ) <= V_139 ) return ( NULL ) ;
V_34 = F_29 ( V_32 , V_139 ) ;
return ( V_34 -> V_78 ) ;
}
T_17 * F_70 ( T_12 * V_93 , int V_3 )
{
return ( F_104 ( V_93 -> V_103 , V_3 ) ) ;
}
T_17 * F_105 ( T_12 * V_93 , int V_3 )
{
return ( F_104 ( V_93 -> V_140 , V_3 ) ) ;
}
int F_72 ( T_12 * V_141 , int V_3 , int V_142 ,
void * V_14 )
{
return ( F_106 ( & ( V_141 -> V_103 ) , V_3 , V_142 , V_14 ) ) ;
}
int F_107 ( T_12 * V_141 , int V_3 , int V_142 ,
void * V_14 )
{
return ( F_106 ( & ( V_141 -> V_140 ) , V_3 , V_142 , V_14 ) ) ;
}
