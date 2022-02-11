int F_1 ( void )
{
if ( ! F_2 ( & V_1 , V_2 ) )
return - 1 ;
return V_3 ;
}
T_1 * F_3 ( void )
{
T_1 * V_4 = F_4 ( sizeof( * V_4 ) ) ;
if ( V_4 == NULL ) {
F_5 ( V_5 , V_6 ) ;
return NULL ;
}
V_4 -> V_7 = & ( V_4 -> V_8 [ V_9 ] ) ;
V_4 -> V_10 = 1 ;
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = NULL ;
V_4 -> V_16 = F_6 () ;
if ( V_4 -> V_16 == NULL ) {
F_5 ( V_5 , V_6 ) ;
F_7 ( V_4 ) ;
return NULL ;
}
return V_4 ;
}
T_1 * F_8 ( T_1 * V_17 )
{
T_1 * V_4 = F_4 ( sizeof( * V_4 ) ) ;
int V_18 ;
if ( V_4 == NULL ) {
F_5 ( V_19 , V_6 ) ;
return NULL ;
}
V_4 -> V_10 = 1 ;
V_4 -> V_7 = & V_4 -> V_8 [ V_17 -> V_7 - V_17 -> V_8 ] ;
V_4 -> V_16 = F_6 () ;
if ( V_4 -> V_16 == NULL ) {
F_5 ( V_19 , V_6 ) ;
F_7 ( V_4 ) ;
return NULL ;
}
#ifndef F_9
if ( V_17 -> V_20 != NULL ) {
V_4 -> V_20 = V_17 -> V_20 ;
F_10 ( V_4 -> V_20 ) ;
}
V_4 -> V_21 = V_17 -> V_21 ;
V_4 -> V_22 = V_17 -> V_22 ;
#endif
for ( V_18 = 0 ; V_18 < V_23 ; V_18 ++ ) {
T_2 * V_24 = V_17 -> V_8 + V_18 ;
T_2 * V_25 = V_4 -> V_8 + V_18 ;
if ( V_24 -> V_26 != NULL ) {
V_25 -> V_26 = V_24 -> V_26 ;
F_11 ( V_25 -> V_26 ) ;
}
if ( V_24 -> V_27 != NULL ) {
V_25 -> V_27 = V_24 -> V_27 ;
F_10 ( V_24 -> V_27 ) ;
}
if ( V_24 -> V_28 ) {
V_25 -> V_28 = F_12 ( V_24 -> V_28 ) ;
if ( ! V_25 -> V_28 ) {
F_5 ( V_19 , V_6 ) ;
goto V_29;
}
}
if ( V_17 -> V_8 [ V_18 ] . V_30 != NULL ) {
V_4 -> V_8 [ V_18 ] . V_30 =
F_13 ( V_17 -> V_8 [ V_18 ] . V_31 ) ;
if ( V_4 -> V_8 [ V_18 ] . V_30 == NULL ) {
F_5 ( V_19 , V_6 ) ;
goto V_29;
}
V_4 -> V_8 [ V_18 ] . V_31 = V_17 -> V_8 [ V_18 ] . V_31 ;
memcpy ( V_4 -> V_8 [ V_18 ] . V_30 ,
V_17 -> V_8 [ V_18 ] . V_30 , V_17 -> V_8 [ V_18 ] . V_31 ) ;
}
}
if ( V_17 -> V_32 ) {
V_4 -> V_32 = F_13 ( V_17 -> V_33 ) ;
if ( V_4 -> V_32 == NULL )
goto V_29;
memcpy ( V_4 -> V_32 , V_17 -> V_32 , V_17 -> V_33 ) ;
V_4 -> V_33 = V_17 -> V_33 ;
} else
V_4 -> V_32 = NULL ;
if ( V_17 -> V_34 ) {
V_4 -> V_34 = F_13 ( V_17 -> V_35 ) ;
if ( V_4 -> V_34 == NULL )
goto V_29;
memcpy ( V_4 -> V_34 , V_17 -> V_34 ,
V_17 -> V_35 ) ;
V_4 -> V_35 = V_17 -> V_35 ;
} else
V_4 -> V_34 = NULL ;
V_4 -> V_36 = NULL ;
if ( V_17 -> V_37 ) {
V_4 -> V_37 = F_13 ( V_17 -> V_38 ) ;
if ( V_4 -> V_37 == NULL )
goto V_29;
memcpy ( V_4 -> V_37 , V_17 -> V_37 , V_17 -> V_38 ) ;
V_4 -> V_38 = V_17 -> V_38 ;
}
V_4 -> V_39 = V_17 -> V_39 ;
V_4 -> V_40 = V_17 -> V_40 ;
V_4 -> V_41 = V_17 -> V_41 ;
if ( V_17 -> V_42 ) {
F_14 ( V_17 -> V_42 ) ;
V_4 -> V_42 = V_17 -> V_42 ;
}
if ( V_17 -> V_43 ) {
F_14 ( V_17 -> V_43 ) ;
V_4 -> V_43 = V_17 -> V_43 ;
}
V_4 -> V_11 = V_17 -> V_11 ;
V_4 -> V_13 = V_17 -> V_13 ;
V_4 -> V_15 = V_17 -> V_15 ;
if ( ! F_15 ( & V_4 -> V_44 , & V_17 -> V_44 ) )
goto V_29;
if ( ! F_15 ( & V_4 -> V_45 , & V_17 -> V_45 ) )
goto V_29;
#ifndef F_16
if ( V_17 -> V_46 ) {
V_4 -> V_46 = F_17 ( V_17 -> V_46 ) ;
if ( V_4 -> V_46 == NULL )
goto V_29;
}
#endif
return V_4 ;
V_29:
F_18 ( V_4 ) ;
return NULL ;
}
void F_19 ( T_1 * V_47 )
{
int V_18 ;
if ( V_47 == NULL )
return;
for ( V_18 = 0 ; V_18 < V_23 ; V_18 ++ ) {
T_2 * V_24 = V_47 -> V_8 + V_18 ;
F_20 ( V_24 -> V_26 ) ;
V_24 -> V_26 = NULL ;
F_21 ( V_24 -> V_27 ) ;
V_24 -> V_27 = NULL ;
F_22 ( V_24 -> V_28 , F_20 ) ;
V_24 -> V_28 = NULL ;
F_7 ( V_24 -> V_30 ) ;
V_24 -> V_30 = NULL ;
V_24 -> V_31 = 0 ;
}
}
void F_18 ( T_1 * V_47 )
{
int V_18 ;
if ( V_47 == NULL )
return;
F_23 ( & V_47 -> V_10 , - 1 , & V_18 , V_47 -> V_16 ) ;
F_24 ( L_1 , V_47 ) ;
if ( V_18 > 0 )
return;
F_25 ( V_18 < 0 ) ;
#ifndef F_9
F_21 ( V_47 -> V_20 ) ;
#endif
F_19 ( V_47 ) ;
F_7 ( V_47 -> V_32 ) ;
F_7 ( V_47 -> V_34 ) ;
F_7 ( V_47 -> V_36 ) ;
F_7 ( V_47 -> V_37 ) ;
F_26 ( V_47 -> V_42 ) ;
F_26 ( V_47 -> V_43 ) ;
F_27 ( & V_47 -> V_44 ) ;
F_27 ( & V_47 -> V_45 ) ;
#ifndef F_16
F_7 ( V_47 -> V_46 ) ;
#endif
F_28 ( V_47 -> V_16 ) ;
F_7 ( V_47 ) ;
}
int F_29 ( T_3 * V_48 , T_4 * V_49 , T_5 * V_50 )
{
int V_51 ;
T_2 * V_24 = V_48 ? V_48 -> V_17 -> V_7 : V_49 -> V_17 -> V_7 ;
if ( ! V_24 )
return 0 ;
V_51 = F_30 ( V_48 , V_49 , V_50 , 0 , 0 ) ;
if ( V_51 != 1 ) {
F_5 ( V_52 , V_51 ) ;
return 0 ;
}
if ( ! V_24 -> V_28 )
V_24 -> V_28 = F_31 () ;
if ( ! V_24 -> V_28 || ! F_32 ( V_24 -> V_28 , V_50 ) )
return 0 ;
return 1 ;
}
int F_33 ( T_3 * V_48 , T_4 * V_49 , T_5 * V_50 )
{
if ( ! F_29 ( V_48 , V_49 , V_50 ) )
return 0 ;
F_11 ( V_50 ) ;
return 1 ;
}
int F_34 ( T_1 * V_47 , T_5 * V_50 )
{
int V_18 ;
if ( V_50 == NULL )
return 0 ;
for ( V_18 = 0 ; V_18 < V_23 ; V_18 ++ ) {
T_2 * V_24 = V_47 -> V_8 + V_18 ;
if ( V_24 -> V_26 == V_50 && V_24 -> V_27 ) {
V_47 -> V_7 = V_24 ;
return 1 ;
}
}
for ( V_18 = 0 ; V_18 < V_23 ; V_18 ++ ) {
T_2 * V_24 = V_47 -> V_8 + V_18 ;
if ( V_24 -> V_27 && V_24 -> V_26 && ! F_35 ( V_24 -> V_26 , V_50 ) ) {
V_47 -> V_7 = V_24 ;
return 1 ;
}
}
return 0 ;
}
int F_36 ( T_1 * V_47 , long V_53 )
{
int V_18 , V_54 ;
if ( ! V_47 )
return 0 ;
if ( V_53 == V_55 )
V_54 = 0 ;
else if ( V_53 == V_56 ) {
V_54 = ( int ) ( V_47 -> V_7 - V_47 -> V_8 + 1 ) ;
if ( V_54 >= V_23 )
return 0 ;
} else
return 0 ;
for ( V_18 = V_54 ; V_18 < V_23 ; V_18 ++ ) {
T_2 * V_24 = V_47 -> V_8 + V_18 ;
if ( V_24 -> V_26 && V_24 -> V_27 ) {
V_47 -> V_7 = V_24 ;
return 1 ;
}
}
return 0 ;
}
void F_37 ( T_1 * V_47 , int (* F_38) ( T_3 * V_57 , void * V_58 ) , void * V_58 )
{
V_47 -> V_40 = F_38 ;
V_47 -> V_41 = V_58 ;
}
int F_39 ( T_3 * V_57 , T_5 * V_50 )
{
return ( F_40 ( & ( V_57 -> V_59 ) , V_50 ) ) ;
}
int F_41 ( T_4 * V_49 , T_5 * V_50 )
{
return ( F_40 ( & ( V_49 -> V_59 ) , V_50 ) ) ;
}
static int F_42 ( const T_6 * const * V_60 , const T_6 * const * V_61 )
{
return ( F_43 ( * V_60 , * V_61 ) ) ;
}
static int F_44 ( const T_6 * V_60 , const T_6 * V_61 )
{
return F_43 ( V_60 , V_61 ) ;
}
static unsigned long F_45 ( const T_6 * V_60 )
{
return F_46 ( ( T_6 * ) V_60 ) ;
}
static int F_47 ( T_7 * V_62 , unsigned long * V_63 , T_5 * V_50 )
{
int V_64 ;
unsigned char * V_65 ;
V_64 = F_48 ( V_50 , NULL ) ;
if ( V_64 < 0 || ! F_49 ( V_62 , ( int ) ( V_64 + ( * V_63 ) + 3 ) ) ) {
F_5 ( V_66 , V_67 ) ;
return 0 ;
}
V_65 = ( unsigned char * ) & ( V_62 -> V_68 [ * V_63 ] ) ;
F_50 ( V_64 , V_65 ) ;
V_64 = F_48 ( V_50 , & V_65 ) ;
if ( V_64 < 0 ) {
F_5 ( V_66 , V_67 ) ;
return 0 ;
}
* V_63 += V_64 + 3 ;
return 1 ;
}
int F_51 ( T_3 * V_48 , T_2 * V_24 , unsigned long * V_63 )
{
T_7 * V_62 = V_48 -> V_69 ;
int V_18 , V_70 ;
T_5 * V_50 ;
F_52 ( T_5 ) * V_71 ;
F_52 ( T_5 ) * V_28 = NULL ;
T_8 * V_43 ;
if ( ! F_49 ( V_62 , 10 ) ) {
F_5 ( V_72 , V_67 ) ;
return 0 ;
}
if ( ! V_24 || ! V_24 -> V_26 )
return 1 ;
V_50 = V_24 -> V_26 ;
if ( V_24 -> V_28 )
V_71 = V_24 -> V_28 ;
else
V_71 = V_48 -> V_49 -> V_71 ;
if ( ( V_48 -> V_73 & V_74 ) || V_71 )
V_43 = NULL ;
else if ( V_48 -> V_17 -> V_43 )
V_43 = V_48 -> V_17 -> V_43 ;
else
V_43 = V_48 -> V_49 -> V_75 ;
if ( V_43 ) {
T_9 * V_76 = F_53 () ;
if ( V_76 == NULL ) {
F_5 ( V_72 , V_6 ) ;
return ( 0 ) ;
}
if ( ! F_54 ( V_76 , V_43 , V_50 , NULL ) ) {
F_55 ( V_76 ) ;
F_5 ( V_72 , V_77 ) ;
return ( 0 ) ;
}
( void ) F_56 ( V_76 ) ;
F_57 () ;
V_28 = F_58 ( V_76 ) ;
V_18 = F_59 ( V_48 , V_28 , NULL , 0 ) ;
if ( V_18 != 1 ) {
#if 0
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, SSL_R_EE_KEY_TOO_SMALL);
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, SSL_R_CA_KEY_TOO_SMALL);
SSLerr(SSL_F_SSL_ADD_CERT_CHAIN, SSL_R_CA_MD_TOO_WEAK);
#endif
F_55 ( V_76 ) ;
F_5 ( V_72 , V_18 ) ;
return 0 ;
}
V_70 = F_60 ( V_28 ) ;
for ( V_18 = 0 ; V_18 < V_70 ; V_18 ++ ) {
V_50 = F_61 ( V_28 , V_18 ) ;
if ( ! F_47 ( V_62 , V_63 , V_50 ) ) {
F_55 ( V_76 ) ;
return 0 ;
}
}
F_55 ( V_76 ) ;
} else {
V_18 = F_59 ( V_48 , V_71 , V_50 , 0 ) ;
if ( V_18 != 1 ) {
F_5 ( V_72 , V_18 ) ;
return 0 ;
}
if ( ! F_47 ( V_62 , V_63 , V_50 ) )
return 0 ;
for ( V_18 = 0 ; V_18 < F_60 ( V_71 ) ; V_18 ++ ) {
V_50 = F_61 ( V_71 , V_18 ) ;
if ( ! F_47 ( V_62 , V_63 , V_50 ) )
return 0 ;
}
}
return 1 ;
}
int F_62 ( T_3 * V_48 , T_4 * V_49 , int V_78 )
{
T_1 * V_47 = V_48 ? V_48 -> V_17 : V_49 -> V_17 ;
T_2 * V_24 = V_47 -> V_7 ;
T_8 * V_43 = NULL ;
T_9 * V_76 = NULL ;
F_52 ( T_5 ) * V_28 = NULL , * V_79 = NULL ;
T_5 * V_50 ;
int V_18 , V_80 = 0 ;
unsigned long error ;
if ( ! V_24 -> V_26 ) {
F_5 ( V_81 , V_82 ) ;
goto V_29;
}
if ( V_78 & V_83 ) {
V_43 = F_63 () ;
if ( V_43 == NULL )
goto V_29;
for ( V_18 = 0 ; V_18 < F_60 ( V_24 -> V_28 ) ; V_18 ++ ) {
V_50 = F_61 ( V_24 -> V_28 , V_18 ) ;
if ( ! F_64 ( V_43 , V_50 ) ) {
error = F_65 () ;
if ( F_66 ( error ) != V_84 ||
F_67 ( error ) != V_85 )
goto V_29;
F_57 () ;
}
}
if ( ! F_64 ( V_43 , V_24 -> V_26 ) ) {
error = F_65 () ;
if ( F_66 ( error ) != V_84 ||
F_67 ( error ) != V_85 )
goto V_29;
F_57 () ;
}
} else {
if ( V_47 -> V_43 )
V_43 = V_47 -> V_43 ;
else if ( V_48 )
V_43 = V_48 -> V_49 -> V_75 ;
else
V_43 = V_49 -> V_75 ;
if ( V_78 & V_86 )
V_79 = V_24 -> V_28 ;
}
V_76 = F_53 () ;
if ( V_76 == NULL ) {
F_5 ( V_81 , V_6 ) ;
goto V_29;
}
if ( ! F_54 ( V_76 , V_43 , V_24 -> V_26 , V_79 ) ) {
F_5 ( V_81 , V_77 ) ;
goto V_29;
}
F_68 ( V_76 ,
V_47 -> V_39 & V_87 ) ;
V_18 = F_56 ( V_76 ) ;
if ( V_18 <= 0 && V_78 & V_88 ) {
if ( V_78 & V_89 )
F_57 () ;
V_18 = 1 ;
V_80 = 2 ;
}
if ( V_18 > 0 )
V_28 = F_69 ( V_76 ) ;
if ( V_18 <= 0 ) {
F_5 ( V_81 , V_90 ) ;
V_18 = F_70 ( V_76 ) ;
F_71 ( 2 , L_2 ,
F_72 ( V_18 ) ) ;
goto V_29;
}
V_50 = F_73 ( V_28 ) ;
F_20 ( V_50 ) ;
if ( V_78 & V_91 ) {
if ( F_60 ( V_28 ) > 0 ) {
V_50 = F_61 ( V_28 , F_60 ( V_28 ) - 1 ) ;
if ( F_74 ( V_50 ) & V_92 ) {
V_50 = F_75 ( V_28 ) ;
F_20 ( V_50 ) ;
}
}
}
for ( V_18 = 0 ; V_18 < F_60 ( V_28 ) ; V_18 ++ ) {
V_50 = F_61 ( V_28 , V_18 ) ;
V_80 = F_30 ( V_48 , V_49 , V_50 , 0 , 0 ) ;
if ( V_80 != 1 ) {
F_5 ( V_81 , V_80 ) ;
F_22 ( V_28 , F_20 ) ;
V_80 = 0 ;
goto V_29;
}
}
F_22 ( V_24 -> V_28 , F_20 ) ;
V_24 -> V_28 = V_28 ;
if ( V_80 == 0 )
V_80 = 1 ;
V_29:
if ( V_78 & V_83 )
F_26 ( V_43 ) ;
F_55 ( V_76 ) ;
return V_80 ;
}
int F_76 ( T_1 * V_47 , T_8 * V_93 , int V_28 , int V_94 )
{
T_8 * * V_95 ;
if ( V_28 )
V_95 = & V_47 -> V_43 ;
else
V_95 = & V_47 -> V_42 ;
F_26 ( * V_95 ) ;
* V_95 = V_93 ;
if ( V_94 && V_93 )
F_14 ( V_93 ) ;
return 1 ;
}
static int V_12 ( const T_3 * V_48 , const T_4 * V_49 ,
int V_53 , int V_96 , int V_97 , void * V_98 ,
void * V_99 )
{
int V_100 , V_101 ;
static const int V_102 [ 5 ] = { 80 , 112 , 128 , 192 , 256 } ;
if ( V_49 )
V_100 = F_77 ( V_49 ) ;
else
V_100 = F_78 ( V_48 ) ;
if ( V_100 <= 0 ) {
if ( V_53 == V_103 && V_96 < 80 )
return 0 ;
return 1 ;
}
if ( V_100 > 5 )
V_100 = 5 ;
V_101 = V_102 [ V_100 - 1 ] ;
switch ( V_53 ) {
case V_104 :
case V_105 :
case V_106 :
{
const T_10 * V_47 = V_98 ;
if ( V_96 < V_101 )
return 0 ;
if ( V_47 -> V_107 & V_108 )
return 0 ;
if ( V_47 -> V_109 & V_110 )
return 0 ;
if ( V_101 > 160 && V_47 -> V_109 & V_111 )
return 0 ;
if ( V_100 >= 2 && V_47 -> V_112 == V_113 )
return 0 ;
if ( V_100 >= 3 && ! ( V_47 -> V_114 & ( V_115 | V_116 ) ) )
return 0 ;
break;
}
case V_117 :
if ( ! F_79 ( V_48 ) ) {
if ( V_97 <= V_118 && V_100 >= 2 )
return 0 ;
if ( V_97 <= V_119 && V_100 >= 3 )
return 0 ;
if ( V_97 <= V_120 && V_100 >= 4 )
return 0 ;
} else {
if ( F_80 ( V_97 , V_121 ) && V_100 >= 4 )
return 0 ;
}
break;
case V_122 :
if ( V_100 >= 2 )
return 0 ;
break;
case V_123 :
if ( V_100 >= 3 )
return 0 ;
break;
default:
if ( V_96 < V_101 )
return 0 ;
}
return 1 ;
}
int F_81 ( const T_3 * V_48 , int V_53 , int V_96 , int V_97 , void * V_98 )
{
return V_48 -> V_17 -> V_11 ( V_48 , NULL , V_53 , V_96 , V_97 , V_98 , V_48 -> V_17 -> V_15 ) ;
}
int F_82 ( const T_4 * V_49 , int V_53 , int V_96 , int V_97 , void * V_98 )
{
return V_49 -> V_17 -> V_11 ( NULL , V_49 , V_53 , V_96 , V_97 , V_98 ,
V_49 -> V_17 -> V_15 ) ;
}
