static int F_1 ( T_1 * V_1 )
{
int V_2 = 1 ;
int V_3 = F_2 ( V_1 -> type ) ;
switch ( V_3 ) {
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
if ( ( V_18 = F_6 ( F_7 () ) ) == NULL ) {
F_8 ( V_20 , V_21 ) ;
goto V_22;
}
V_19 = F_9 ( V_17 -> V_23 ) ;
if ( V_19 == NULL ) {
F_8 ( V_20 , V_24 ) ;
goto V_22;
}
F_10 ( V_18 , V_19 ) ;
if ( * V_16 == NULL )
* V_16 = V_18 ;
else if ( ! F_11 ( * V_16 , V_18 ) ) {
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
static int F_13 ( T_6 * V_25 ,
unsigned char * V_26 , int V_27 )
{
T_7 * V_28 = NULL ;
T_8 * V_29 = NULL ;
unsigned char * V_30 = NULL ;
int V_31 = 0 ;
T_9 V_32 ;
V_29 = F_14 ( V_25 -> V_33 ) ;
if ( ! V_29 )
return 0 ;
V_28 = F_15 ( V_29 , NULL ) ;
if ( ! V_28 )
return 0 ;
if ( F_16 ( V_28 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_34 ,
V_35 , 0 , V_25 ) <= 0 ) {
F_8 ( V_36 , V_37 ) ;
goto V_22;
}
if ( F_18 ( V_28 , NULL , & V_32 , V_26 , V_27 ) <= 0 )
goto V_22;
V_30 = F_19 ( V_32 ) ;
if ( V_30 == NULL ) {
F_8 ( V_36 , V_38 ) ;
goto V_22;
}
if ( F_18 ( V_28 , V_30 , & V_32 , V_26 , V_27 ) <= 0 )
goto V_22;
F_20 ( V_25 -> V_39 , V_30 , V_32 ) ;
V_30 = NULL ;
V_31 = 1 ;
V_22:
if ( V_29 )
F_21 ( V_29 ) ;
if ( V_28 )
F_22 ( V_28 ) ;
if ( V_30 )
F_23 ( V_30 ) ;
return V_31 ;
}
static int F_24 ( unsigned char * * V_40 , int * V_41 ,
T_6 * V_25 , T_8 * V_29 )
{
T_7 * V_28 = NULL ;
unsigned char * V_30 = NULL ;
T_9 V_32 ;
int V_31 = - 1 ;
V_28 = F_15 ( V_29 , NULL ) ;
if ( ! V_28 )
return - 1 ;
if ( F_25 ( V_28 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_42 ,
V_43 , 0 , V_25 ) <= 0 ) {
F_8 ( V_44 , V_37 ) ;
goto V_22;
}
if ( F_26 ( V_28 , NULL , & V_32 ,
V_25 -> V_39 -> V_11 , V_25 -> V_39 -> V_45 ) <= 0 )
goto V_22;
V_30 = F_19 ( V_32 ) ;
if ( V_30 == NULL ) {
F_8 ( V_44 , V_38 ) ;
goto V_22;
}
if ( F_26 ( V_28 , V_30 , & V_32 ,
V_25 -> V_39 -> V_11 , V_25 -> V_39 -> V_45 ) <= 0 ) {
V_31 = 0 ;
F_8 ( V_44 , V_46 ) ;
goto V_22;
}
V_31 = 1 ;
if ( * V_40 ) {
F_27 ( * V_40 , * V_41 ) ;
F_23 ( * V_40 ) ;
}
* V_40 = V_30 ;
* V_41 = V_32 ;
V_22:
if ( V_28 )
F_22 ( V_28 ) ;
if ( ! V_31 && V_30 )
F_23 ( V_30 ) ;
return V_31 ;
}
T_3 * F_28 ( T_1 * V_1 , T_3 * V_47 )
{
int V_48 ;
T_3 * V_49 = NULL , * V_18 = NULL ;
T_4 * V_50 = NULL ;
const T_10 * V_51 = NULL ;
F_29 ( T_4 ) * V_52 = NULL ;
F_29 ( T_6 ) * V_53 = NULL ;
T_4 * V_54 = NULL ;
T_6 * V_25 = NULL ;
T_2 * V_55 = NULL ;
V_48 = F_2 ( V_1 -> type ) ;
V_1 -> V_56 = V_57 ;
switch ( V_48 ) {
case V_5 :
V_52 = V_1 -> V_10 . V_58 -> V_59 ;
V_55 = F_3 ( V_1 -> V_10 . V_58 -> V_60 ) ;
break;
case V_7 :
V_53 = V_1 -> V_10 . V_61 -> V_62 ;
V_52 = V_1 -> V_10 . V_61 -> V_59 ;
V_54 = V_1 -> V_10 . V_61 -> V_63 -> V_23 ;
V_51 = V_1 -> V_10 . V_61 -> V_63 -> V_64 ;
if ( V_51 == NULL ) {
F_8 ( V_65 , V_66 ) ;
goto V_22;
}
break;
case V_6 :
V_53 = V_1 -> V_10 . V_67 -> V_62 ;
V_54 = V_1 -> V_10 . V_67 -> V_63 -> V_23 ;
V_51 = V_1 -> V_10 . V_67 -> V_63 -> V_64 ;
if ( V_51 == NULL ) {
F_8 ( V_65 , V_66 ) ;
goto V_22;
}
break;
case V_8 :
V_50 = V_1 -> V_10 . V_68 -> V_19 ;
V_55 = F_3 ( V_1 -> V_10 . V_68 -> V_60 ) ;
break;
case V_4 :
break;
default:
F_8 ( V_65 , V_69 ) ;
goto V_22;
}
for ( V_48 = 0 ; V_48 < F_30 ( V_52 ) ; V_48 ++ )
if ( ! F_5 ( & V_49 , F_31 ( V_52 , V_48 ) ) )
goto V_22;
if ( V_50 && ! F_5 ( & V_49 , V_50 ) )
goto V_22;
if ( V_51 != NULL ) {
unsigned char V_26 [ V_70 ] ;
unsigned char V_71 [ V_72 ] ;
int V_27 , V_73 ;
T_11 * V_74 ;
if ( ( V_18 = F_6 ( F_32 () ) ) == NULL ) {
F_8 ( V_65 , V_21 ) ;
goto V_22;
}
F_33 ( V_18 , & V_74 ) ;
V_27 = F_34 ( V_51 ) ;
V_73 = F_35 ( V_51 ) ;
V_54 -> V_23 = F_36 ( F_37 ( V_51 ) ) ;
if ( V_73 > 0 )
if ( F_38 ( V_71 , V_73 ) <= 0 )
goto V_22;
if ( F_39 ( V_74 , V_51 , NULL , NULL , NULL , 1 ) <= 0 )
goto V_22;
if ( F_40 ( V_74 , V_26 ) <= 0 )
goto V_22;
if ( F_39 ( V_74 , NULL , NULL , V_26 , V_71 , 1 ) <= 0 )
goto V_22;
if ( V_73 > 0 ) {
if ( V_54 -> V_75 == NULL ) {
V_54 -> V_75 = F_41 () ;
if ( V_54 -> V_75 == NULL )
goto V_22;
}
if ( F_42 ( V_74 , V_54 -> V_75 ) < 0 )
goto V_22;
}
for ( V_48 = 0 ; V_48 < F_43 ( V_53 ) ; V_48 ++ ) {
V_25 = F_44 ( V_53 , V_48 ) ;
if ( F_13 ( V_25 , V_26 , V_27 ) <= 0 )
goto V_22;
}
F_27 ( V_26 , V_27 ) ;
if ( V_49 == NULL )
V_49 = V_18 ;
else
F_11 ( V_49 , V_18 ) ;
V_18 = NULL ;
}
if ( V_47 == NULL ) {
if ( F_45 ( V_1 ) )
V_47 = F_6 ( F_46 () ) ;
else if ( V_55 && V_55 -> V_45 > 0 )
V_47 = F_47 ( V_55 -> V_11 , V_55 -> V_45 ) ;
if ( V_47 == NULL ) {
V_47 = F_6 ( F_48 () ) ;
if ( V_47 == NULL )
goto V_22;
F_49 ( V_47 , 0 ) ;
}
}
if ( V_49 )
F_11 ( V_49 , V_47 ) ;
else
V_49 = V_47 ;
V_47 = NULL ;
if ( 0 ) {
V_22:
if ( V_49 != NULL )
F_50 ( V_49 ) ;
if ( V_18 != NULL )
F_50 ( V_18 ) ;
V_49 = NULL ;
}
return ( V_49 ) ;
}
static int F_51 ( T_6 * V_25 , T_12 * V_76 )
{
int V_31 ;
V_31 = F_52 ( V_25 -> V_77 -> V_78 ,
V_76 -> V_79 -> V_78 ) ;
if ( V_31 )
return V_31 ;
return F_53 ( V_76 -> V_79 -> V_80 ,
V_25 -> V_77 -> V_81 ) ;
}
T_3 * F_54 ( T_1 * V_1 , T_8 * V_29 , T_3 * V_82 , T_12 * V_76 )
{
int V_48 , V_83 ;
T_3 * V_49 = NULL , * V_18 = NULL , * V_84 = NULL , * V_47 = NULL ;
T_4 * V_50 ;
T_2 * V_85 = NULL ;
const T_5 * V_86 ;
const T_10 * V_51 = NULL ;
T_11 * V_87 = NULL ;
T_4 * V_88 = NULL ;
F_29 ( T_4 ) * V_52 = NULL ;
F_29 ( T_6 ) * V_53 = NULL ;
T_6 * V_25 = NULL ;
unsigned char * V_30 = NULL , * V_89 = NULL ;
int V_32 = 0 , V_90 = 0 ;
V_48 = F_2 ( V_1 -> type ) ;
V_1 -> V_56 = V_57 ;
switch ( V_48 ) {
case V_5 :
V_85 = F_3 ( V_1 -> V_10 . V_58 -> V_60 ) ;
if ( ! F_45 ( V_1 ) && V_85 == NULL ) {
F_8 ( V_91 ,
V_92 ) ;
goto V_22;
}
V_52 = V_1 -> V_10 . V_58 -> V_59 ;
break;
case V_7 :
V_53 = V_1 -> V_10 . V_61 -> V_62 ;
V_52 = V_1 -> V_10 . V_61 -> V_59 ;
V_85 = V_1 -> V_10 . V_61 -> V_63 -> V_63 ;
V_88 = V_1 -> V_10 . V_61 -> V_63 -> V_23 ;
V_51 = F_55 ( V_88 -> V_23 ) ;
if ( V_51 == NULL ) {
F_8 ( V_91 ,
V_93 ) ;
goto V_22;
}
break;
case V_6 :
V_53 = V_1 -> V_10 . V_67 -> V_62 ;
V_88 = V_1 -> V_10 . V_67 -> V_63 -> V_23 ;
V_85 = V_1 -> V_10 . V_67 -> V_63 -> V_63 ;
V_51 = F_55 ( V_88 -> V_23 ) ;
if ( V_51 == NULL ) {
F_8 ( V_91 ,
V_93 ) ;
goto V_22;
}
break;
default:
F_8 ( V_91 , V_69 ) ;
goto V_22;
}
if ( V_52 != NULL ) {
for ( V_48 = 0 ; V_48 < F_30 ( V_52 ) ; V_48 ++ ) {
V_50 = F_31 ( V_52 , V_48 ) ;
if ( ( V_18 = F_6 ( F_7 () ) ) == NULL ) {
F_8 ( V_91 , V_21 ) ;
goto V_22;
}
V_83 = F_2 ( V_50 -> V_23 ) ;
V_86 = F_56 ( V_83 ) ;
if ( V_86 == NULL ) {
F_8 ( V_91 ,
V_24 ) ;
goto V_22;
}
F_10 ( V_18 , V_86 ) ;
if ( V_49 == NULL )
V_49 = V_18 ;
else
F_11 ( V_49 , V_18 ) ;
V_18 = NULL ;
}
}
if ( V_51 != NULL ) {
#if 0
unsigned char key[EVP_MAX_KEY_LENGTH];
unsigned char iv[EVP_MAX_IV_LENGTH];
unsigned char *p;
int keylen, ivlen;
int max;
X509_OBJECT ret;
#endif
if ( ( V_84 = F_6 ( F_32 () ) ) == NULL ) {
F_8 ( V_91 , V_21 ) ;
goto V_22;
}
if ( V_76 ) {
for ( V_48 = 0 ; V_48 < F_43 ( V_53 ) ; V_48 ++ ) {
V_25 = F_44 ( V_53 , V_48 ) ;
if ( ! F_51 ( V_25 , V_76 ) )
break;
V_25 = NULL ;
}
if ( V_25 == NULL ) {
F_8 ( V_91 ,
V_94 ) ;
goto V_22;
}
}
if ( V_76 == NULL ) {
for ( V_48 = 0 ; V_48 < F_43 ( V_53 ) ; V_48 ++ ) {
V_25 = F_44 ( V_53 , V_48 ) ;
if ( F_24 ( & V_30 , & V_32 , V_25 , V_29 ) < 0 )
goto V_22;
F_57 () ;
}
} else {
if ( F_24 ( & V_30 , & V_32 , V_25 , V_29 ) < 0 )
goto V_22;
F_57 () ;
}
V_87 = NULL ;
F_33 ( V_84 , & V_87 ) ;
if ( F_39 ( V_87 , V_51 , NULL , NULL , NULL , 0 ) <= 0 )
goto V_22;
if ( F_58 ( V_87 , V_88 -> V_75 ) < 0 )
goto V_22;
V_90 = F_59 ( V_87 ) ;
V_89 = F_19 ( V_90 ) ;
if ( ! V_89 )
goto V_22;
if ( F_40 ( V_87 , V_89 ) <= 0 )
goto V_22;
if ( V_30 == NULL ) {
V_30 = V_89 ;
V_32 = V_90 ;
V_89 = NULL ;
}
if ( V_32 != F_59 ( V_87 ) ) {
if ( ! F_60 ( V_87 , V_32 ) ) {
F_27 ( V_30 , V_32 ) ;
F_23 ( V_30 ) ;
V_30 = V_89 ;
V_32 = V_90 ;
V_89 = NULL ;
}
}
F_57 () ;
if ( F_39 ( V_87 , NULL , NULL , V_30 , NULL , 0 ) <= 0 )
goto V_22;
if ( V_30 ) {
F_27 ( V_30 , V_32 ) ;
F_23 ( V_30 ) ;
V_30 = NULL ;
}
if ( V_89 ) {
F_27 ( V_89 , V_90 ) ;
F_23 ( V_89 ) ;
V_89 = NULL ;
}
if ( V_49 == NULL )
V_49 = V_84 ;
else
F_11 ( V_49 , V_84 ) ;
V_84 = NULL ;
}
#if 1
if ( F_45 ( V_1 ) || ( V_82 != NULL ) ) {
V_47 = V_82 ;
} else {
# if 0
bio = BIO_new(BIO_s_mem());
BIO_set_mem_eof_return(bio, 0);
if (data_body->length > 0)
BIO_write(bio, (char *)data_body->data, data_body->length);
# else
if ( V_85 -> V_45 > 0 )
V_47 = F_47 ( V_85 -> V_11 , V_85 -> V_45 ) ;
else {
V_47 = F_6 ( F_48 () ) ;
F_49 ( V_47 , 0 ) ;
}
if ( V_47 == NULL )
goto V_22;
# endif
}
F_11 ( V_49 , V_47 ) ;
V_47 = NULL ;
#endif
if ( 0 ) {
V_22:
if ( V_30 ) {
F_27 ( V_30 , V_32 ) ;
F_23 ( V_30 ) ;
}
if ( V_89 ) {
F_27 ( V_89 , V_90 ) ;
F_23 ( V_89 ) ;
}
if ( V_49 != NULL )
F_50 ( V_49 ) ;
if ( V_18 != NULL )
F_50 ( V_18 ) ;
if ( V_84 != NULL )
F_50 ( V_84 ) ;
if ( V_47 != NULL )
F_50 ( V_47 ) ;
V_49 = NULL ;
}
return ( V_49 ) ;
}
static T_3 * F_61 ( T_13 * * V_95 , T_3 * V_47 , int V_3 )
{
for (; ; ) {
V_47 = F_62 ( V_47 , V_96 ) ;
if ( V_47 == NULL ) {
F_8 ( V_97 ,
V_98 ) ;
return NULL ;
}
F_63 ( V_47 , V_95 ) ;
if ( * V_95 == NULL ) {
F_8 ( V_97 , V_99 ) ;
return NULL ;
}
if ( F_64 ( * V_95 ) == V_3 )
return V_47 ;
V_47 = F_65 ( V_47 ) ;
}
return NULL ;
}
static int F_66 ( T_14 * V_100 , T_13 * V_101 )
{
unsigned char V_102 [ V_103 ] ;
unsigned int V_104 ;
if ( ! F_67 ( V_100 , V_105 ) ) {
if ( ! F_68 ( V_100 , NULL ) ) {
F_8 ( V_106 , V_38 ) ;
return 0 ;
}
}
if ( ! F_69 ( V_101 , V_102 , & V_104 ) ) {
F_8 ( V_106 , V_46 ) ;
return 0 ;
}
if ( ! F_70 ( V_100 , V_102 , V_104 ) ) {
F_8 ( V_106 , V_38 ) ;
return 0 ;
}
if ( ! F_71 ( V_100 ) )
return 0 ;
return 1 ;
}
int F_72 ( T_1 * V_1 , T_3 * V_47 )
{
int V_31 = 0 ;
int V_48 , V_83 ;
T_3 * V_18 ;
T_14 * V_100 ;
T_13 * V_107 , V_108 ;
F_29 ( V_109 ) * V_110 ;
F_29 ( T_14 ) * V_111 = NULL ;
T_2 * V_55 = NULL ;
F_73 ( & V_108 ) ;
V_48 = F_2 ( V_1 -> type ) ;
V_1 -> V_56 = V_57 ;
switch ( V_48 ) {
case V_4 :
V_55 = V_1 -> V_10 . V_11 ;
break;
case V_7 :
V_111 = V_1 -> V_10 . V_61 -> V_112 ;
V_55 = V_1 -> V_10 . V_61 -> V_63 -> V_63 ;
if ( ! V_55 ) {
V_55 = F_74 () ;
if ( ! V_55 ) {
F_8 ( V_113 , V_38 ) ;
goto V_22;
}
V_1 -> V_10 . V_61 -> V_63 -> V_63 = V_55 ;
}
break;
case V_6 :
V_55 = V_1 -> V_10 . V_67 -> V_63 -> V_63 ;
if ( ! V_55 ) {
V_55 = F_74 () ;
if ( ! V_55 ) {
F_8 ( V_113 , V_38 ) ;
goto V_22;
}
V_1 -> V_10 . V_67 -> V_63 -> V_63 = V_55 ;
}
break;
case V_5 :
V_111 = V_1 -> V_10 . V_58 -> V_112 ;
V_55 = F_3 ( V_1 -> V_10 . V_58 -> V_60 ) ;
if ( F_4 ( V_1 -> V_10 . V_58 -> V_60 ) && V_1 -> V_114 ) {
F_75 ( V_55 ) ;
V_1 -> V_10 . V_58 -> V_60 -> V_10 . V_11 = NULL ;
}
break;
case V_8 :
V_55 = F_3 ( V_1 -> V_10 . V_68 -> V_60 ) ;
if ( F_4 ( V_1 -> V_10 . V_68 -> V_60 ) && V_1 -> V_114 ) {
F_75 ( V_55 ) ;
V_1 -> V_10 . V_68 -> V_60 -> V_10 . V_11 = NULL ;
}
break;
default:
F_8 ( V_113 , V_69 ) ;
goto V_22;
}
if ( V_111 != NULL ) {
for ( V_48 = 0 ; V_48 < F_76 ( V_111 ) ; V_48 ++ ) {
V_100 = F_77 ( V_111 , V_48 ) ;
if ( V_100 -> V_29 == NULL )
continue;
V_83 = F_2 ( V_100 -> V_115 -> V_23 ) ;
V_18 = V_47 ;
V_18 = F_61 ( & V_107 , V_18 , V_83 ) ;
if ( V_18 == NULL )
goto V_22;
if ( ! F_78 ( & V_108 , V_107 ) )
goto V_22;
V_110 = V_100 -> V_116 ;
if ( F_79 ( V_110 ) > 0 ) {
if ( ! F_66 ( V_100 , & V_108 ) )
goto V_22;
} else {
unsigned char * V_117 = NULL ;
unsigned int V_118 ;
V_118 = F_80 ( V_100 -> V_29 ) ;
V_117 = F_19 ( V_118 ) ;
if ( ! V_117 )
goto V_22;
if ( ! F_81 ( & V_108 , V_117 , & V_118 , V_100 -> V_29 ) ) {
F_8 ( V_113 , V_46 ) ;
goto V_22;
}
F_20 ( V_100 -> V_119 , V_117 , V_118 ) ;
}
}
} else if ( V_48 == V_8 ) {
unsigned char V_102 [ V_103 ] ;
unsigned int V_104 ;
if ( ! F_61 ( & V_107 , V_47 ,
F_2 ( V_1 -> V_10 . V_68 -> V_19 -> V_23 ) ) )
goto V_22;
if ( ! F_69 ( V_107 , V_102 , & V_104 ) )
goto V_22;
F_82 ( V_1 -> V_10 . V_68 -> V_68 , V_102 , V_104 ) ;
}
if ( ! F_45 ( V_1 ) && ! ( V_55 -> V_120 & V_121 ) ) {
char * V_122 ;
long V_123 ;
V_18 = F_62 ( V_47 , V_124 ) ;
if ( V_18 == NULL ) {
F_8 ( V_113 , V_125 ) ;
goto V_22;
}
V_123 = F_83 ( V_18 , & V_122 ) ;
F_84 ( V_18 , V_126 ) ;
F_49 ( V_18 , 0 ) ;
F_20 ( V_55 , ( unsigned char * ) V_122 , V_123 ) ;
}
V_31 = 1 ;
V_22:
F_85 ( & V_108 ) ;
return ( V_31 ) ;
}
int F_71 ( T_14 * V_100 )
{
T_13 V_101 ;
T_7 * V_28 ;
unsigned char * V_117 = NULL ;
int V_127 ;
T_9 V_128 ;
const T_5 * V_19 = NULL ;
V_19 = F_9 ( V_100 -> V_115 -> V_23 ) ;
if ( V_19 == NULL )
return 0 ;
F_73 ( & V_101 ) ;
if ( F_86 ( & V_101 , & V_28 , V_19 , NULL , V_100 -> V_29 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_129 ,
V_130 , 0 , V_100 ) <= 0 ) {
F_8 ( V_131 , V_37 ) ;
goto V_22;
}
V_127 = F_87 ( ( V_132 * ) V_100 -> V_116 , & V_117 ,
F_88 ( V_133 ) ) ;
if ( ! V_117 )
goto V_22;
if ( F_89 ( & V_101 , V_117 , V_127 ) <= 0 )
goto V_22;
F_23 ( V_117 ) ;
V_117 = NULL ;
if ( F_90 ( & V_101 , NULL , & V_128 ) <= 0 )
goto V_22;
V_117 = F_19 ( V_128 ) ;
if ( ! V_117 )
goto V_22;
if ( F_90 ( & V_101 , V_117 , & V_128 ) <= 0 )
goto V_22;
if ( F_17 ( V_28 , - 1 , V_129 ,
V_130 , 1 , V_100 ) <= 0 ) {
F_8 ( V_131 , V_37 ) ;
goto V_22;
}
F_85 ( & V_101 ) ;
F_20 ( V_100 -> V_119 , V_117 , V_128 ) ;
return 1 ;
V_22:
if ( V_117 )
F_23 ( V_117 ) ;
F_85 ( & V_101 ) ;
return 0 ;
}
int F_91 ( T_15 * V_134 , T_16 * V_74 , T_3 * V_47 ,
T_1 * V_1 , T_14 * V_100 )
{
T_17 * V_135 ;
int V_31 = 0 , V_48 ;
F_29 ( T_12 ) * V_33 ;
T_12 * V_136 ;
if ( F_92 ( V_1 ) ) {
V_33 = V_1 -> V_10 . V_58 -> V_33 ;
} else if ( F_93 ( V_1 ) ) {
V_33 = V_1 -> V_10 . V_61 -> V_33 ;
} else {
F_8 ( V_137 , V_138 ) ;
goto V_22;
}
V_135 = V_100 -> V_77 ;
V_136 = F_94 ( V_33 , V_135 -> V_78 , V_135 -> V_81 ) ;
if ( V_136 == NULL ) {
F_8 ( V_137 ,
V_139 ) ;
goto V_22;
}
if ( ! F_95 ( V_74 , V_134 , V_136 , V_33 ) ) {
F_8 ( V_137 , V_140 ) ;
goto V_22;
}
F_96 ( V_74 , V_141 ) ;
V_48 = F_97 ( V_74 ) ;
if ( V_48 <= 0 ) {
F_8 ( V_137 , V_140 ) ;
F_98 ( V_74 ) ;
goto V_22;
}
F_98 ( V_74 ) ;
return F_99 ( V_47 , V_1 , V_100 , V_136 ) ;
V_22:
return V_31 ;
}
int F_99 ( T_3 * V_47 , T_1 * V_1 , T_14 * V_100 ,
T_12 * V_136 )
{
T_2 * V_55 ;
T_13 V_142 , * V_107 ;
int V_31 = 0 , V_48 ;
int V_143 ;
F_29 ( V_109 ) * V_110 ;
T_3 * V_18 ;
T_8 * V_29 ;
F_73 ( & V_142 ) ;
if ( ! F_92 ( V_1 ) && ! F_93 ( V_1 ) ) {
F_8 ( V_144 , V_138 ) ;
goto V_22;
}
V_143 = F_2 ( V_100 -> V_115 -> V_23 ) ;
V_18 = V_47 ;
for (; ; ) {
if ( ( V_18 == NULL ) ||
( ( V_18 = F_62 ( V_18 , V_96 ) ) == NULL ) ) {
F_8 ( V_144 ,
V_98 ) ;
goto V_22;
}
F_63 ( V_18 , & V_107 ) ;
if ( V_107 == NULL ) {
F_8 ( V_144 , V_99 ) ;
goto V_22;
}
if ( F_64 ( V_107 ) == V_143 )
break;
if ( F_100 ( F_101 ( V_107 ) ) == V_143 )
break;
V_18 = F_65 ( V_18 ) ;
}
if ( ! F_78 ( & V_142 , V_107 ) )
goto V_22;
V_110 = V_100 -> V_116 ;
if ( ( V_110 != NULL ) && ( F_79 ( V_110 ) != 0 ) ) {
unsigned char V_145 [ V_103 ] , * V_117 = NULL ;
unsigned int V_104 ;
int V_127 ;
T_2 * V_146 ;
if ( ! F_69 ( & V_142 , V_145 , & V_104 ) )
goto V_22;
V_146 = F_102 ( V_110 ) ;
if ( ! V_146 ) {
F_8 ( V_144 ,
V_98 ) ;
goto V_22;
}
if ( ( V_146 -> V_45 != ( int ) V_104 ) ||
( memcmp ( V_146 -> V_11 , V_145 , V_104 ) ) ) {
#if 0
{
int ii;
for (ii = 0; ii < message_digest->length; ii++)
printf("%02X", message_digest->data[ii]);
printf(" sent\n");
for (ii = 0; ii < md_len; ii++)
printf("%02X", md_dat[ii]);
printf(" calc\n");
}
#endif
F_8 ( V_144 , V_147 ) ;
V_31 = - 1 ;
goto V_22;
}
if ( ! F_103 ( & V_142 , F_56 ( V_143 ) , NULL ) )
goto V_22;
V_127 = F_87 ( ( V_132 * ) V_110 , & V_117 ,
F_88 ( V_148 ) ) ;
if ( V_127 <= 0 ) {
F_8 ( V_144 , V_149 ) ;
V_31 = - 1 ;
goto V_22;
}
if ( ! F_104 ( & V_142 , V_117 , V_127 ) )
goto V_22;
F_23 ( V_117 ) ;
}
V_55 = V_100 -> V_119 ;
V_29 = F_14 ( V_136 ) ;
if ( ! V_29 ) {
V_31 = - 1 ;
goto V_22;
}
V_48 = F_105 ( & V_142 , V_55 -> V_11 , V_55 -> V_45 , V_29 ) ;
F_21 ( V_29 ) ;
if ( V_48 <= 0 ) {
F_8 ( V_144 , V_150 ) ;
V_31 = - 1 ;
goto V_22;
} else
V_31 = 1 ;
V_22:
F_85 ( & V_142 ) ;
return ( V_31 ) ;
}
T_17 * F_106 ( T_1 * V_1 , int V_151 )
{
F_29 ( T_6 ) * V_53 ;
T_6 * V_25 ;
int V_48 ;
V_48 = F_2 ( V_1 -> type ) ;
if ( V_48 != V_7 )
return NULL ;
if ( V_1 -> V_10 . V_61 == NULL )
return NULL ;
V_53 = V_1 -> V_10 . V_61 -> V_62 ;
if ( V_53 == NULL )
return NULL ;
V_25 = F_44 ( V_53 , 0 ) ;
if ( F_43 ( V_53 ) <= V_151 )
return ( NULL ) ;
V_25 = F_44 ( V_53 , V_151 ) ;
return ( V_25 -> V_77 ) ;
}
T_18 * F_67 ( T_14 * V_100 , int V_3 )
{
return ( F_107 ( V_100 -> V_116 , V_3 ) ) ;
}
T_18 * F_108 ( T_14 * V_100 , int V_3 )
{
return ( F_107 ( V_100 -> V_152 , V_3 ) ) ;
}
int F_109 ( T_14 * V_153 , int V_3 , int V_154 ,
void * V_14 )
{
return ( F_110 ( & ( V_153 -> V_116 ) , V_3 , V_154 , V_14 ) ) ;
}
int F_111 ( T_14 * V_153 , int V_3 , int V_154 ,
void * V_14 )
{
return ( F_110 ( & ( V_153 -> V_152 ) , V_3 , V_154 , V_14 ) ) ;
}
