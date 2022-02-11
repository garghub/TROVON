int F_1 ( void )
{
static volatile int V_1 = - 1 ;
int V_2 = 0 ;
if ( ( ( V_3 ) & V_1 &
( sizeof( V_1 ) - 1 ) )
== 0 ) {
int V_4 ;
if ( ( V_4 = V_1 ) < 0 ) {
F_2 ( V_5 ) ;
if ( ( V_4 = V_1 ) < 0 ) {
V_4 = V_1 =
F_3 ( 0 ,
L_1 ,
NULL , NULL , NULL ) ;
}
F_4 ( V_5 ) ;
}
return V_4 ;
} else {
F_5 ( V_5 ) ;
if ( V_1 < 0 ) {
F_6 ( V_5 ) ;
F_2 ( V_5 ) ;
V_2 = 1 ;
if ( V_1 < 0 ) {
V_1 =
F_3 ( 0 ,
L_1 ,
NULL , NULL , NULL ) ;
}
}
if ( V_2 )
F_4 ( V_5 ) ;
else
F_6 ( V_5 ) ;
return V_1 ;
}
}
void F_7 ( T_1 * V_6 )
{
#ifndef F_8
V_6 -> V_7 [ V_8 ] . V_9 = F_9 () ;
#endif
#ifndef F_10
V_6 -> V_7 [ V_10 ] . V_9 = F_9 () ;
V_6 -> V_7 [ V_11 ] . V_9 = F_9 () ;
#endif
#ifndef F_11
V_6 -> V_7 [ V_12 ] . V_9 = F_9 () ;
#endif
}
T_1 * F_12 ( void )
{
T_1 * V_4 ;
V_4 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ;
if ( V_4 == NULL ) {
F_14 ( V_13 , V_14 ) ;
return ( NULL ) ;
}
memset ( V_4 , 0 , sizeof( T_1 ) ) ;
V_4 -> V_15 = & ( V_4 -> V_7 [ V_11 ] ) ;
V_4 -> V_16 = 1 ;
F_7 ( V_4 ) ;
return ( V_4 ) ;
}
T_1 * F_15 ( T_1 * V_6 )
{
T_1 * V_4 ;
int V_17 ;
V_4 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ;
if ( V_4 == NULL ) {
F_14 ( V_18 , V_14 ) ;
return ( NULL ) ;
}
memset ( V_4 , 0 , sizeof( T_1 ) ) ;
V_4 -> V_15 = & V_4 -> V_7 [ V_6 -> V_15 - & V_6 -> V_7 [ 0 ] ] ;
V_4 -> V_19 = V_6 -> V_19 ;
V_4 -> V_20 = V_6 -> V_20 ;
V_4 -> V_21 = V_6 -> V_21 ;
V_4 -> V_22 = V_6 -> V_22 ;
V_4 -> V_23 = V_6 -> V_23 ;
#ifndef F_10
if ( V_6 -> V_24 != NULL ) {
F_16 ( V_6 -> V_24 ) ;
V_4 -> V_24 = V_6 -> V_24 ;
}
V_4 -> V_25 = V_6 -> V_25 ;
#endif
#ifndef F_17
if ( V_6 -> V_26 != NULL ) {
V_4 -> V_26 = F_18 ( V_6 -> V_26 ) ;
if ( V_4 -> V_26 == NULL ) {
F_14 ( V_18 , V_27 ) ;
goto V_28;
}
if ( V_6 -> V_26 -> V_29 ) {
T_2 * V_30 = F_19 ( V_6 -> V_26 -> V_29 ) ;
if ( ! V_30 ) {
F_14 ( V_18 , V_31 ) ;
goto V_28;
}
V_4 -> V_26 -> V_29 = V_30 ;
}
if ( V_6 -> V_26 -> V_32 ) {
T_2 * V_30 = F_19 ( V_6 -> V_26 -> V_32 ) ;
if ( ! V_30 ) {
F_14 ( V_18 , V_31 ) ;
goto V_28;
}
V_4 -> V_26 -> V_32 = V_30 ;
}
}
V_4 -> V_33 = V_6 -> V_33 ;
#endif
#ifndef F_20
if ( V_6 -> V_34 ) {
V_4 -> V_34 = F_21 ( V_6 -> V_34 ) ;
if ( V_4 -> V_34 == NULL ) {
F_14 ( V_18 , V_35 ) ;
goto V_28;
}
}
V_4 -> V_36 = V_6 -> V_36 ;
V_4 -> V_37 = V_6 -> V_37 ;
#endif
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
T_3 * V_39 = V_6 -> V_7 + V_17 ;
T_3 * V_40 = V_4 -> V_7 + V_17 ;
if ( V_39 -> V_41 != NULL ) {
V_40 -> V_41 = V_39 -> V_41 ;
F_22 ( & V_40 -> V_41 -> V_16 , 1 , V_42 ) ;
}
if ( V_39 -> V_43 != NULL ) {
V_40 -> V_43 = V_39 -> V_43 ;
F_22 ( & V_39 -> V_43 -> V_16 , 1 , V_44 ) ;
}
if ( V_39 -> V_45 ) {
V_40 -> V_45 = F_23 ( V_39 -> V_45 ) ;
if ( ! V_40 -> V_45 ) {
F_14 ( V_18 , V_14 ) ;
goto V_28;
}
}
V_40 -> V_46 = 0 ;
#ifndef F_24
if ( V_6 -> V_7 [ V_17 ] . V_47 != NULL ) {
V_4 -> V_7 [ V_17 ] . V_47 =
F_13 ( V_6 -> V_7 [ V_17 ] . V_48 ) ;
if ( V_4 -> V_7 [ V_17 ] . V_47 == NULL ) {
F_14 ( V_18 , V_14 ) ;
return NULL ;
}
V_4 -> V_7 [ V_17 ] . V_48 =
V_6 -> V_7 [ V_17 ] . V_48 ;
memcpy ( V_4 -> V_7 [ V_17 ] . V_47 ,
V_6 -> V_7 [ V_17 ] . V_47 ,
V_6 -> V_7 [ V_17 ] . V_48 ) ;
}
#endif
}
V_4 -> V_16 = 1 ;
F_7 ( V_4 ) ;
V_4 -> V_49 = NULL ;
V_4 -> V_50 = 0 ;
if ( V_6 -> V_51 ) {
V_4 -> V_51 = F_13 ( V_6 -> V_52 ) ;
if ( ! V_4 -> V_51 )
goto V_28;
memcpy ( V_4 -> V_51 , V_6 -> V_51 , V_6 -> V_52 ) ;
V_4 -> V_52 = V_6 -> V_52 ;
} else
V_4 -> V_51 = NULL ;
if ( V_6 -> V_53 ) {
V_4 -> V_53 = F_13 ( V_6 -> V_54 ) ;
if ( ! V_4 -> V_53 )
goto V_28;
memcpy ( V_4 -> V_53 , V_6 -> V_53 ,
V_6 -> V_54 ) ;
V_4 -> V_54 = V_6 -> V_54 ;
} else
V_4 -> V_53 = NULL ;
V_4 -> V_55 = NULL ;
if ( V_6 -> V_56 ) {
V_4 -> V_56 = F_13 ( V_6 -> V_57 ) ;
if ( ! V_4 -> V_56 )
goto V_28;
memcpy ( V_4 -> V_56 , V_6 -> V_56 , V_6 -> V_57 ) ;
V_4 -> V_57 = V_6 -> V_57 ;
}
V_4 -> V_58 = V_6 -> V_58 ;
V_4 -> V_59 = V_6 -> V_59 ;
V_4 -> V_60 = V_6 -> V_60 ;
if ( V_6 -> V_61 ) {
F_22 ( & V_6 -> V_61 -> V_16 , 1 ,
V_62 ) ;
V_4 -> V_61 = V_6 -> V_61 ;
}
if ( V_6 -> V_63 ) {
F_22 ( & V_6 -> V_63 -> V_16 , 1 , V_62 ) ;
V_4 -> V_63 = V_6 -> V_63 ;
}
V_4 -> V_64 = NULL ;
#ifndef F_24
if ( ! F_25 ( & V_4 -> V_65 , & V_6 -> V_65 ) )
goto V_28;
if ( ! F_25 ( & V_4 -> V_66 , & V_6 -> V_66 ) )
goto V_28;
#endif
return ( V_4 ) ;
#if ! F_26 ( F_17 ) || ! F_26 ( F_20 )
V_28:
#endif
#ifndef F_10
if ( V_4 -> V_24 != NULL )
F_27 ( V_4 -> V_24 ) ;
#endif
#ifndef F_17
if ( V_4 -> V_26 != NULL )
F_28 ( V_4 -> V_26 ) ;
#endif
#ifndef F_20
if ( V_4 -> V_34 != NULL )
F_29 ( V_4 -> V_34 ) ;
#endif
#ifndef F_24
F_30 ( & V_4 -> V_65 ) ;
F_30 ( & V_4 -> V_66 ) ;
#endif
F_31 ( V_4 ) ;
return NULL ;
}
void F_31 ( T_1 * V_67 )
{
int V_17 ;
if ( V_67 == NULL )
return;
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
T_3 * V_39 = V_67 -> V_7 + V_17 ;
if ( V_39 -> V_41 ) {
F_32 ( V_39 -> V_41 ) ;
V_39 -> V_41 = NULL ;
}
if ( V_39 -> V_43 ) {
F_33 ( V_39 -> V_43 ) ;
V_39 -> V_43 = NULL ;
}
if ( V_39 -> V_45 ) {
F_34 ( V_39 -> V_45 , F_32 ) ;
V_39 -> V_45 = NULL ;
}
#ifndef F_24
if ( V_39 -> V_47 ) {
F_35 ( V_39 -> V_47 ) ;
V_39 -> V_47 = NULL ;
V_39 -> V_48 = 0 ;
}
#endif
V_39 -> V_46 &= V_68 ;
}
}
void F_36 ( T_1 * V_67 )
{
int V_17 ;
if ( V_67 == NULL )
return;
V_17 = F_22 ( & V_67 -> V_16 , - 1 , V_69 ) ;
#ifdef F_37
F_37 ( L_2 , V_67 ) ;
#endif
if ( V_17 > 0 )
return;
#ifdef F_38
if ( V_17 < 0 ) {
fprintf ( V_70 , L_3 ) ;
abort () ;
}
#endif
#ifndef F_10
if ( V_67 -> V_24 )
F_27 ( V_67 -> V_24 ) ;
#endif
#ifndef F_17
if ( V_67 -> V_26 )
F_28 ( V_67 -> V_26 ) ;
#endif
#ifndef F_20
if ( V_67 -> V_34 )
F_29 ( V_67 -> V_34 ) ;
#endif
F_31 ( V_67 ) ;
if ( V_67 -> V_49 )
F_35 ( V_67 -> V_49 ) ;
if ( V_67 -> V_51 )
F_35 ( V_67 -> V_51 ) ;
if ( V_67 -> V_53 )
F_35 ( V_67 -> V_53 ) ;
if ( V_67 -> V_55 )
F_35 ( V_67 -> V_55 ) ;
if ( V_67 -> V_56 )
F_35 ( V_67 -> V_56 ) ;
if ( V_67 -> V_61 )
F_39 ( V_67 -> V_61 ) ;
if ( V_67 -> V_63 )
F_39 ( V_67 -> V_63 ) ;
if ( V_67 -> V_64 )
F_35 ( V_67 -> V_64 ) ;
#ifndef F_24
F_30 ( & V_67 -> V_65 ) ;
F_30 ( & V_67 -> V_66 ) ;
#endif
F_35 ( V_67 ) ;
}
int F_40 ( T_1 * * V_71 )
{
if ( V_71 == NULL ) {
F_14 ( V_72 , V_73 ) ;
return ( 0 ) ;
}
if ( * V_71 == NULL ) {
if ( ( * V_71 = F_12 () ) == NULL ) {
F_14 ( V_72 , V_14 ) ;
return ( 0 ) ;
}
}
return ( 1 ) ;
}
int F_41 ( T_1 * V_67 , T_4 * V_74 )
{
T_3 * V_39 = V_67 -> V_15 ;
if ( ! V_39 )
return 0 ;
if ( ! V_39 -> V_45 )
V_39 -> V_45 = F_42 () ;
if ( ! V_39 -> V_45 || ! F_43 ( V_39 -> V_45 , V_74 ) )
return 0 ;
return 1 ;
}
int F_44 ( T_1 * V_67 , T_4 * V_74 )
{
if ( ! F_41 ( V_67 , V_74 ) )
return 0 ;
F_22 ( & V_74 -> V_16 , 1 , V_42 ) ;
return 1 ;
}
int F_45 ( T_1 * V_67 , T_4 * V_74 )
{
int V_17 ;
if ( V_74 == NULL )
return 0 ;
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
T_3 * V_39 = V_67 -> V_7 + V_17 ;
if ( V_39 -> V_41 == V_74 && V_39 -> V_43 ) {
V_67 -> V_15 = V_39 ;
return 1 ;
}
}
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
T_3 * V_39 = V_67 -> V_7 + V_17 ;
if ( V_39 -> V_43 && V_39 -> V_41 && ! F_46 ( V_39 -> V_41 , V_74 ) ) {
V_67 -> V_15 = V_39 ;
return 1 ;
}
}
return 0 ;
}
int F_47 ( T_1 * V_67 , long V_75 )
{
int V_17 , V_76 ;
if ( ! V_67 )
return 0 ;
if ( V_75 == V_77 )
V_76 = 0 ;
else if ( V_75 == V_78 ) {
V_76 = ( int ) ( V_67 -> V_15 - V_67 -> V_7 + 1 ) ;
if ( V_76 >= V_38 )
return 0 ;
} else
return 0 ;
for ( V_17 = V_76 ; V_17 < V_38 ; V_17 ++ ) {
T_3 * V_39 = V_67 -> V_7 + V_17 ;
if ( V_39 -> V_41 && V_39 -> V_43 ) {
V_67 -> V_15 = V_39 ;
return 1 ;
}
}
return 0 ;
}
void F_48 ( T_1 * V_67 , int (* F_49) ( T_5 * V_79 , void * V_80 ) , void * V_80 )
{
V_67 -> V_59 = F_49 ;
V_67 -> V_60 = V_80 ;
}
T_6 * F_50 ( void )
{
T_6 * V_4 ;
V_4 = F_13 ( sizeof *V_4 ) ;
if ( V_4 == NULL ) {
F_14 ( V_81 , V_14 ) ;
return NULL ;
}
memset ( V_4 , 0 , sizeof *V_4 ) ;
V_4 -> V_82 = & ( V_4 -> V_83 [ V_11 ] ) ;
V_4 -> V_16 = 1 ;
return V_4 ;
}
void F_51 ( T_6 * V_84 )
{
int V_17 ;
if ( V_84 == NULL )
return;
V_17 = F_22 ( & V_84 -> V_16 , - 1 , V_85 ) ;
#ifdef F_37
F_37 ( L_4 , V_84 ) ;
#endif
if ( V_17 > 0 )
return;
#ifdef F_38
if ( V_17 < 0 ) {
fprintf ( V_70 , L_5 ) ;
abort () ;
}
#endif
if ( V_84 -> V_86 != NULL )
F_34 ( V_84 -> V_86 , F_32 ) ;
for ( V_17 = 0 ; V_17 < V_38 ; V_17 ++ ) {
if ( V_84 -> V_83 [ V_17 ] . V_41 != NULL )
F_32 ( V_84 -> V_83 [ V_17 ] . V_41 ) ;
#if 0
if (sc->peer_pkeys[i].privatekey != NULL)
EVP_PKEY_free(sc->peer_pkeys[i].privatekey);
#endif
}
#ifndef F_10
if ( V_84 -> V_87 != NULL )
F_27 ( V_84 -> V_87 ) ;
#endif
#ifndef F_17
if ( V_84 -> V_88 != NULL )
F_28 ( V_84 -> V_88 ) ;
#endif
#ifndef F_20
if ( V_84 -> V_89 != NULL )
F_29 ( V_84 -> V_89 ) ;
#endif
F_35 ( V_84 ) ;
}
int F_52 ( T_6 * V_84 , int type )
{
V_84 -> V_90 = type ;
return ( 1 ) ;
}
int F_53 ( T_5 * V_79 , T_4 * V_74 )
{
return ( F_54 ( & ( V_79 -> V_91 ) , V_74 ) ) ;
}
int F_55 ( T_7 * V_92 , T_4 * V_74 )
{
return ( F_54 ( & ( V_92 -> V_91 ) , V_74 ) ) ;
}
static int F_56 ( const T_8 * const * V_93 , const T_8 * const * V_30 )
{
return ( F_57 ( * V_93 , * V_30 ) ) ;
}
static int F_58 ( T_9 * V_94 , unsigned long * V_95 , T_4 * V_74 )
{
int V_96 ;
unsigned char * V_97 ;
V_96 = F_59 ( V_74 , NULL ) ;
if ( ! F_60 ( V_94 , ( int ) ( V_96 + ( * V_95 ) + 3 ) ) ) {
F_14 ( V_98 , V_99 ) ;
return 0 ;
}
V_97 = ( unsigned char * ) & ( V_94 -> V_100 [ * V_95 ] ) ;
F_61 ( V_96 , V_97 ) ;
F_59 ( V_74 , & V_97 ) ;
* V_95 += V_96 + 3 ;
return 1 ;
}
int F_62 ( T_5 * V_101 , T_3 * V_39 , unsigned long * V_95 )
{
T_9 * V_94 = V_101 -> V_102 ;
int V_103 ;
int V_17 ;
T_4 * V_74 ;
F_63 ( T_4 ) * V_104 ;
T_10 * V_63 ;
if ( V_39 )
V_74 = V_39 -> V_41 ;
else
V_74 = NULL ;
if ( V_101 -> V_6 -> V_63 )
V_63 = V_101 -> V_6 -> V_63 ;
else
V_63 = V_101 -> V_92 -> V_105 ;
if ( V_39 && V_39 -> V_45 )
V_104 = V_39 -> V_45 ;
else
V_104 = V_101 -> V_92 -> V_104 ;
if ( ( V_101 -> V_106 & V_107 ) || V_104 )
V_103 = 1 ;
else
V_103 = 0 ;
if ( ! F_60 ( V_94 , 10 ) ) {
F_14 ( V_108 , V_99 ) ;
return 0 ;
}
if ( V_74 != NULL ) {
if ( V_103 ) {
if ( ! F_58 ( V_94 , V_95 , V_74 ) )
return 0 ;
} else {
T_11 V_109 ;
if ( ! F_64 ( & V_109 , V_63 , V_74 , NULL ) ) {
F_14 ( V_108 , V_110 ) ;
return ( 0 ) ;
}
F_65 ( & V_109 ) ;
F_66 () ;
for ( V_17 = 0 ; V_17 < F_67 ( V_109 . V_45 ) ; V_17 ++ ) {
V_74 = F_68 ( V_109 . V_45 , V_17 ) ;
if ( ! F_58 ( V_94 , V_95 , V_74 ) ) {
F_69 ( & V_109 ) ;
return 0 ;
}
}
F_69 ( & V_109 ) ;
}
}
for ( V_17 = 0 ; V_17 < F_67 ( V_104 ) ; V_17 ++ ) {
V_74 = F_68 ( V_104 , V_17 ) ;
if ( ! F_58 ( V_94 , V_95 , V_74 ) )
return 0 ;
}
return 1 ;
}
int F_70 ( T_1 * V_67 , T_10 * V_63 , int V_111 )
{
T_3 * V_39 = V_67 -> V_15 ;
T_11 V_109 ;
F_63 ( T_4 ) * V_45 = NULL , * V_112 = NULL ;
T_4 * V_74 ;
int V_17 , V_113 = 0 ;
unsigned long error ;
if ( ! V_39 -> V_41 ) {
F_14 ( V_114 , V_115 ) ;
goto V_28;
}
if ( V_111 & V_116 ) {
V_63 = F_71 () ;
if ( ! V_63 )
goto V_28;
for ( V_17 = 0 ; V_17 < F_67 ( V_39 -> V_45 ) ; V_17 ++ ) {
V_74 = F_68 ( V_39 -> V_45 , V_17 ) ;
if ( ! F_72 ( V_63 , V_74 ) ) {
error = F_73 () ;
if ( F_74 ( error ) != V_117 ||
F_75 ( error ) !=
V_118 )
goto V_28;
F_66 () ;
}
}
if ( ! F_72 ( V_63 , V_39 -> V_41 ) ) {
error = F_73 () ;
if ( F_74 ( error ) != V_117 ||
F_75 ( error ) != V_118 )
goto V_28;
F_66 () ;
}
} else {
if ( V_67 -> V_63 )
V_63 = V_67 -> V_63 ;
if ( V_111 & V_119 )
V_112 = V_39 -> V_45 ;
}
if ( ! F_64 ( & V_109 , V_63 , V_39 -> V_41 , V_112 ) ) {
F_14 ( V_114 , V_110 ) ;
goto V_28;
}
F_76 ( & V_109 ,
V_67 -> V_58 & V_120 ) ;
V_17 = F_65 ( & V_109 ) ;
if ( V_17 <= 0 && V_111 & V_121 ) {
if ( V_111 & V_122 )
F_66 () ;
V_17 = 1 ;
V_113 = 2 ;
}
if ( V_17 > 0 )
V_45 = F_77 ( & V_109 ) ;
if ( V_17 <= 0 ) {
F_14 ( V_114 , V_123 ) ;
V_17 = F_78 ( & V_109 ) ;
F_79 ( 2 , L_6 ,
F_80 ( V_17 ) ) ;
F_69 ( & V_109 ) ;
goto V_28;
}
F_69 ( & V_109 ) ;
if ( V_39 -> V_45 )
F_34 ( V_39 -> V_45 , F_32 ) ;
V_74 = F_81 ( V_45 ) ;
F_32 ( V_74 ) ;
if ( V_111 & V_124 ) {
if ( F_67 ( V_45 ) > 0 ) {
V_74 = F_68 ( V_45 , F_67 ( V_45 ) - 1 ) ;
F_82 ( V_74 , - 1 , 0 ) ;
if ( V_74 -> V_125 & V_126 ) {
V_74 = F_83 ( V_45 ) ;
F_32 ( V_74 ) ;
}
}
}
V_39 -> V_45 = V_45 ;
if ( V_113 == 0 )
V_113 = 1 ;
V_28:
if ( V_111 & V_116 )
F_39 ( V_63 ) ;
return V_113 ;
}
int F_84 ( T_1 * V_67 , T_10 * V_127 , int V_45 , int V_128 )
{
T_10 * * V_129 ;
if ( V_45 )
V_129 = & V_67 -> V_63 ;
else
V_129 = & V_67 -> V_61 ;
if ( * V_129 )
F_39 ( * V_129 ) ;
* V_129 = V_127 ;
if ( V_128 && V_127 )
F_22 ( & V_127 -> V_16 , 1 , V_62 ) ;
return 1 ;
}
