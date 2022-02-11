static T_1 *
F_1 ( T_1 * V_1 , const T_2 * V_2 ,
const char * * V_3 )
{
const char * * V_4 ;
V_1 = F_2 ( V_1 , F_3 ( V_2 ) ) ;
for ( V_4 = V_3 ;
* V_4 != NULL ;
V_4 ++ ) {
V_1 = F_2 ( V_1 ,
F_4 ( L_1 , V_2 ,
* V_4 ) ) ;
}
return V_1 ;
}
static void
F_5 ( void )
{
if ( V_5 ) return;
V_5 = F_6 ( FALSE , TRUE , sizeof( struct V_6 ) ) ;
F_7 ( V_5 , V_7 , V_8 ) ;
V_9 = (struct V_6 * ) ( void * ) V_5 -> V_10 ;
}
void
F_8 ( const struct V_6 * V_11 )
{
F_5 () ;
F_9 ( V_5 , * V_11 ) ;
V_9 = ( const struct V_6 * ) ( void * ) V_5 -> V_10 ;
}
int
F_10 ( void )
{
return V_5 -> V_12 ;
}
const char *
F_11 ( int V_13 )
{
return V_9 [ V_13 ] . V_14 ;
}
static T_1 *
F_12 ( int V_13 ,
T_1 * V_1 , const char * * V_3 )
{
T_2 * * V_15 , * * V_16 , * V_2 ;
V_15 = F_13 ( V_9 [ V_13 ] . V_1 ,
L_2 , 0 ) ;
for ( V_16 = V_15 ; * V_16 != NULL ; V_16 ++ ) {
V_2 = * V_16 ;
V_1 = F_1 ( V_1 , V_2 ,
V_3 ) ;
}
F_14 ( V_15 ) ;
return V_1 ;
}
T_1 *
F_15 ( T_3 V_13 )
{
T_1 * V_1 ;
if ( V_13 >= V_5 -> V_12 )
return NULL ;
V_1 = NULL ;
V_1 = F_12 ( V_13 ,
V_1 , V_17 ) ;
return V_1 ;
}
T_1 *
F_16 ( void )
{
T_1 * V_1 ;
unsigned int V_18 ;
F_5 () ;
V_1 = NULL ;
for ( V_18 = 0 ; V_18 < V_5 -> V_12 ; V_18 ++ ) {
V_1 = F_12 ( V_18 ,
V_1 , V_17 ) ;
}
return V_1 ;
}
static void
F_17 ( void )
{
T_3 V_18 ;
F_18 ( V_19 != NULL ) ;
for ( V_18 = 0 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( V_20 [ V_18 ] . type == V_21 ) {
V_22 = V_18 ;
break;
}
F_18 ( V_20 [ V_18 ] . type == V_23 ) ;
}
F_18 ( V_22 > 0 ) ;
}
void
F_19 ( void )
{
unsigned int V_18 ;
struct V_24 * V_25 ;
if ( V_19 )
return;
V_19 = F_6 ( TRUE , TRUE , sizeof( struct V_24 ) ) ;
F_7 ( V_19 , V_26 , V_27 ) ;
V_20 = (struct V_24 * ) ( void * ) V_19 -> V_10 ;
for ( V_18 = 0 , V_25 = V_20 ; V_18 < V_19 -> V_12 ; V_18 ++ , V_25 ++ ) {
if ( V_25 -> V_1 != NULL )
V_25 -> V_15 = F_13 ( V_25 -> V_1 , L_2 , 0 ) ;
}
F_17 () ;
}
void
F_20 ( struct V_24 * V_28 , const T_4 V_29 )
{
F_19 () ;
if ( ! V_28 || ! V_28 -> V_14 ) {
F_21 ( L_3 ) ;
return;
}
if ( F_22 ( V_28 -> V_14 ) ) {
F_21 ( L_4 ) ;
return;
}
if ( V_28 -> V_1 != NULL )
V_28 -> V_15 = F_13 ( V_28 -> V_1 , L_2 , 0 ) ;
if ( V_29 && V_28 -> type == V_23 ) {
F_23 ( V_19 , * V_28 ) ;
} else if ( ! V_29 && V_28 -> type == V_21 ) {
F_9 ( V_19 , * V_28 ) ;
} else {
F_24 ( V_19 , V_22 , * V_28 ) ;
}
V_20 = (struct V_24 * ) ( void * ) V_19 -> V_10 ;
F_17 () ;
}
void
F_25 ( const T_2 * V_14 )
{
T_3 V_18 ;
F_19 () ;
if ( ! V_14 ) {
F_21 ( L_5 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( V_20 [ V_18 ] . V_14 && strcmp ( V_20 [ V_18 ] . V_14 , V_14 ) == 0 ) {
if ( V_20 [ V_18 ] . V_15 != NULL )
F_14 ( V_20 [ V_18 ] . V_15 ) ;
V_19 = F_26 ( V_19 , V_18 ) ;
F_17 () ;
return;
}
}
F_21 ( L_6 ) ;
}
T_4
F_22 ( const T_2 * V_14 )
{
T_3 V_18 ;
F_19 () ;
if ( ! V_14 ) {
F_21 ( L_7 ) ;
return FALSE ;
}
for ( V_18 = 0 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( V_20 [ V_18 ] . V_14 && strcmp ( V_20 [ V_18 ] . V_14 , V_14 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
unsigned int
F_27 ( const char * V_14 )
{
unsigned int V_18 ;
F_19 () ;
if ( ! V_14 )
return V_30 ;
for ( V_18 = 0 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( V_20 [ V_18 ] . V_14 != NULL &&
strcmp ( V_14 , V_20 [ V_18 ] . V_14 ) == 0 )
return V_18 + 1 ;
}
return V_30 ;
}
static char *
F_28 ( const char * V_31 )
{
T_2 * V_32 ;
T_2 * * V_33 ;
T_5 V_34 ;
const char * * V_4 ;
T_2 * V_16 ;
if ( strcmp ( V_31 , L_8 ) == 0 )
return NULL ;
V_32 = F_29 ( V_31 ) ;
if ( strchr ( V_32 , '.' ) == NULL ) {
F_30 ( V_32 ) ;
return NULL ;
}
V_33 = F_13 ( V_32 , L_9 , 0 ) ;
F_30 ( V_32 ) ;
for ( V_34 = 0 ; V_33 [ V_34 ] != NULL ; V_34 ++ )
;
if ( V_34 == 0 ) {
F_14 ( V_33 ) ;
return NULL ;
}
if ( V_34 == 1 ) {
F_14 ( V_33 ) ;
return NULL ;
}
V_16 = V_33 [ V_34 - 1 ] ;
for ( V_4 = V_17 ;
* V_4 != NULL ;
V_4 ++ ) {
if ( strcmp ( V_16 , * V_4 ) == 0 ) {
if ( V_34 == 2 ) {
F_14 ( V_33 ) ;
return NULL ;
}
V_16 = F_3 ( V_33 [ V_34 - 2 ] ) ;
F_14 ( V_33 ) ;
return V_16 ;
}
}
V_16 = F_3 ( V_16 ) ;
F_14 ( V_33 ) ;
return V_16 ;
}
static T_4
F_31 ( unsigned int V_18 , const char * V_2 )
{
T_2 * * V_16 ;
if ( V_20 [ V_18 ] . V_1 == NULL )
return FALSE ;
for ( V_16 = V_20 [ V_18 ] . V_15 ; * V_16 != NULL ;
V_16 ++ ) {
if ( strcmp ( V_2 , * V_16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
T_6 *
F_32 ( const char * V_32 , unsigned int type , int * V_35 , char * * V_36 ,
T_4 V_37 )
{
int V_38 ;
T_7 V_39 ;
T_6 * V_40 ;
unsigned int V_18 ;
T_4 V_41 = FALSE ;
T_2 * V_2 ;
T_8 V_42 ;
* V_35 = 0 ;
* V_36 = NULL ;
F_19 () ;
if ( strcmp ( V_32 , L_10 ) == 0 )
V_41 = TRUE ;
if ( V_41 ) {
if ( F_33 ( 0 , & V_39 ) < 0 ) {
* V_35 = V_43 ;
return NULL ;
}
} else {
if ( F_34 ( V_32 , & V_39 ) < 0 ) {
* V_35 = V_43 ;
return NULL ;
}
}
if ( F_35 ( V_39 . V_44 ) ) {
if ( V_37 ) {
* V_35 = V_45 ;
return NULL ;
}
} else if ( F_36 ( V_39 . V_44 ) ) {
* V_35 = V_46 ;
return NULL ;
} else if ( ! F_37 ( V_39 . V_44 ) ) {
* V_35 = V_47 ;
return NULL ;
}
if ( V_41 && V_37 ) {
* V_35 = V_48 ;
return NULL ;
}
V_43 = V_49 ;
V_40 = ( T_6 * ) F_38 ( sizeof( T_6 ) ) ;
V_43 = V_50 ;
if ( V_41 ) {
V_38 = F_39 ( 0 ) ;
if ( V_38 < 0 ) {
* V_35 = V_43 ;
F_30 ( V_40 ) ;
return NULL ;
}
#ifdef F_40
if ( F_41 ( V_38 , V_51 ) == - 1 ) {
* V_35 = V_43 ;
F_30 ( V_40 ) ;
return NULL ;
}
#endif
if ( ! ( V_40 -> V_52 = F_42 ( V_38 ) ) ) {
* V_35 = V_43 ;
F_43 ( V_38 ) ;
F_30 ( V_40 ) ;
return NULL ;
}
} else {
if ( ! ( V_40 -> V_52 = F_44 ( V_32 ) ) ) {
* V_35 = V_43 ;
F_30 ( V_40 ) ;
return NULL ;
}
}
if ( V_37 ) {
if ( ! ( V_40 -> V_53 = F_44 ( V_32 ) ) ) {
* V_35 = V_43 ;
F_45 ( V_40 -> V_52 ) ;
F_30 ( V_40 ) ;
return NULL ;
}
} else
V_40 -> V_53 = NULL ;
V_40 -> V_54 = V_55 ;
V_40 -> V_56 = NULL ;
V_40 -> V_57 = NULL ;
V_40 -> V_58 = V_59 ;
V_40 -> V_60 = NULL ;
V_40 -> V_61 = NULL ;
V_40 -> V_62 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
V_42 = F_46 ( V_63 ) ;
if ( V_42 )
F_9 ( V_40 -> V_62 , V_42 ) ;
V_40 -> V_64 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
if ( V_40 -> V_53 ) {
V_40 -> V_65 = F_47 () ;
F_48 ( V_40 -> V_52 , FALSE , V_40 -> V_65 ) ;
F_48 ( V_40 -> V_53 , TRUE , V_40 -> V_65 ) ;
}
if ( type != V_30 && type <= V_19 -> V_12 ) {
int V_66 ;
if ( F_49 ( V_40 -> V_52 , 0 , V_67 , V_35 ) == - 1 ) {
F_50 ( V_40 ) ;
return NULL ;
}
V_40 -> V_61 = V_20 [ type - 1 ] . V_61 ;
V_66 = ( * V_20 [ type - 1 ] . V_68 ) ( V_40 , V_35 , V_36 ) ;
switch ( V_66 ) {
case V_69 :
F_50 ( V_40 ) ;
return NULL ;
case V_70 :
goto V_71;
case V_72 :
goto V_73;
}
}
for ( V_18 = 0 ; V_18 < V_22 ; V_18 ++ ) {
if ( F_49 ( V_40 -> V_52 , 0 , V_67 , V_35 ) == - 1 ) {
F_50 ( V_40 ) ;
return NULL ;
}
V_40 -> V_61 = V_20 [ V_18 ] . V_61 ;
switch ( ( * V_20 [ V_18 ] . V_68 ) ( V_40 , V_35 , V_36 ) ) {
case V_69 :
F_50 ( V_40 ) ;
return NULL ;
case V_70 :
break;
case V_72 :
goto V_73;
}
}
V_2 = F_28 ( V_32 ) ;
if ( V_2 != NULL ) {
for ( V_18 = V_22 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( F_31 ( V_18 , V_2 ) ) {
if ( F_49 ( V_40 -> V_52 , 0 , V_67 , V_35 ) == - 1 ) {
F_30 ( V_2 ) ;
F_50 ( V_40 ) ;
return NULL ;
}
V_40 -> V_61 = V_20 [ V_18 ] . V_61 ;
switch ( ( * V_20 [ V_18 ] . V_68 ) ( V_40 ,
V_35 , V_36 ) ) {
case V_69 :
F_30 ( V_2 ) ;
F_50 ( V_40 ) ;
return NULL ;
case V_70 :
break;
case V_72 :
F_30 ( V_2 ) ;
goto V_73;
}
}
}
for ( V_18 = V_22 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( V_20 [ V_18 ] . V_1 == NULL ) {
if ( F_49 ( V_40 -> V_52 , 0 , V_67 , V_35 ) == - 1 ) {
F_30 ( V_2 ) ;
F_50 ( V_40 ) ;
return NULL ;
}
V_40 -> V_61 = V_20 [ V_18 ] . V_61 ;
switch ( ( * V_20 [ V_18 ] . V_68 ) ( V_40 ,
V_35 , V_36 ) ) {
case V_69 :
F_30 ( V_2 ) ;
F_50 ( V_40 ) ;
return NULL ;
case V_70 :
break;
case V_72 :
F_30 ( V_2 ) ;
goto V_73;
}
}
}
for ( V_18 = V_22 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( V_20 [ V_18 ] . V_1 != NULL &&
! F_31 ( V_18 , V_2 ) ) {
if ( F_49 ( V_40 -> V_52 , 0 , V_67 , V_35 ) == - 1 ) {
F_30 ( V_2 ) ;
F_50 ( V_40 ) ;
return NULL ;
}
V_40 -> V_61 = V_20 [ V_18 ] . V_61 ;
switch ( ( * V_20 [ V_18 ] . V_68 ) ( V_40 ,
V_35 , V_36 ) ) {
case V_69 :
F_30 ( V_2 ) ;
F_50 ( V_40 ) ;
return NULL ;
case V_70 :
break;
case V_72 :
F_30 ( V_2 ) ;
goto V_73;
}
}
}
F_30 ( V_2 ) ;
} else {
for ( V_18 = V_22 ; V_18 < V_19 -> V_12 ; V_18 ++ ) {
if ( F_49 ( V_40 -> V_52 , 0 , V_67 , V_35 ) == - 1 ) {
F_50 ( V_40 ) ;
return NULL ;
}
V_40 -> V_61 = V_20 [ V_18 ] . V_61 ;
switch ( ( * V_20 [ V_18 ] . V_68 ) ( V_40 , V_35 , V_36 ) ) {
case V_69 :
F_50 ( V_40 ) ;
return NULL ;
case V_70 :
break;
case V_72 :
goto V_73;
}
}
}
V_71:
F_50 ( V_40 ) ;
* V_35 = V_74 ;
return NULL ;
V_73:
V_40 -> V_75 = (struct V_76 * ) F_51 ( sizeof( struct V_76 ) ) ;
F_52 ( V_40 -> V_75 , 1500 ) ;
if ( ( V_40 -> V_77 == V_78 ) ||
( V_40 -> V_77 == V_79 ) ) {
T_8 V_80 = F_46 ( V_81 ) ;
T_9 * V_82 = ( T_9 * ) F_53 ( V_80 ) ;
V_82 -> V_83 = V_40 -> V_54 ;
if ( V_40 -> V_77 == V_79 ) {
V_82 -> V_84 = 1000000000 ;
F_54 ( V_80 , V_85 , 9 ) ;
V_82 -> V_86 = V_87 ;
} else {
V_82 -> V_84 = 1000000 ;
F_54 ( V_80 , V_85 , 6 ) ;
V_82 -> V_86 = V_59 ;
}
V_82 -> V_88 = F_55 ( V_40 -> V_54 ) ;
V_82 -> V_89 = V_40 -> V_90 ;
V_82 -> V_91 = 0 ;
V_82 -> V_92 = NULL ;
F_9 ( V_40 -> V_64 , V_80 ) ;
}
return V_40 ;
}
T_4
F_56 ( T_6 * V_40 , const char * V_32 , int * V_35 )
{
T_7 V_39 ;
if ( strcmp ( V_32 , L_10 ) == 0 ) {
* V_35 = V_48 ;
return FALSE ;
}
if ( F_34 ( V_32 , & V_39 ) < 0 ) {
* V_35 = V_43 ;
return FALSE ;
}
if ( F_35 ( V_39 . V_44 ) ) {
* V_35 = V_45 ;
return FALSE ;
} else if ( F_36 ( V_39 . V_44 ) ) {
* V_35 = V_46 ;
return FALSE ;
} else if ( ! F_37 ( V_39 . V_44 ) ) {
* V_35 = V_47 ;
return FALSE ;
}
V_43 = V_50 ;
if ( ! F_57 ( V_40 -> V_53 , V_32 ) ) {
* V_35 = V_43 ;
return FALSE ;
}
return TRUE ;
}
static void
F_58 ( void )
{
if ( V_93 ) return;
V_93 = F_6 ( FALSE , TRUE , sizeof( struct V_94 ) ) ;
F_7 ( V_93 , V_95 , V_96 ) ;
V_97 = ( const struct V_94 * ) ( void * ) V_93 -> V_10 ;
}
int
F_59 ( const struct V_94 * V_98 , const int V_99 )
{
struct V_94 * V_100 ;
if ( ! V_98 || ! V_98 -> V_14 || ! V_98 -> V_101 || V_99 > V_96 ) {
F_21 ( L_11 ) ;
return V_99 ;
}
if ( V_99 == V_102 ) {
if ( F_60 ( V_98 -> V_101 ) > - 1 ) {
F_21 ( L_12 ) ;
return V_99 ;
}
F_58 () ;
F_9 ( V_93 , * V_98 ) ;
V_97 = ( const struct V_94 * ) ( void * ) V_93 -> V_10 ;
return V_96 ++ ;
}
if ( ! V_97 [ V_99 ] . V_101 || strcmp ( V_97 [ V_99 ] . V_101 , V_98 -> V_101 ) != 0 ) {
F_21 ( L_13 ) ;
return V_99 ;
}
F_58 () ;
V_100 = & F_61 ( V_93 , struct V_94 , V_99 ) ;
V_100 -> V_103 = V_98 -> V_103 ;
V_100 -> V_104 = V_98 -> V_104 ;
V_100 -> V_105 = V_98 -> V_105 ;
V_100 -> V_106 = V_98 -> V_106 ;
V_100 -> V_107 = V_98 -> V_107 ;
V_100 -> V_108 = V_98 -> V_108 ;
V_100 -> V_109 = V_98 -> V_109 ;
V_100 -> V_110 = V_98 -> V_110 ;
return V_99 ;
}
void
F_62 ( const int V_99 )
{
struct V_94 * V_100 ;
if ( V_99 < 0 || V_99 >= V_96 ) {
F_21 ( L_14 ) ;
return;
}
F_58 () ;
V_100 = & F_61 ( V_93 , struct V_94 , V_99 ) ;
V_100 -> V_103 = NULL ;
V_100 -> V_104 = NULL ;
V_100 -> V_105 = FALSE ;
V_100 -> V_106 = FALSE ;
V_100 -> V_107 = 0 ;
V_100 -> V_108 = NULL ;
V_100 -> V_109 = NULL ;
V_100 -> V_110 = NULL ;
}
int
F_63 ( void )
{
return V_96 ;
}
int
F_64 ( const T_10 * V_111 )
{
int V_112 ;
V_112 = V_113 ;
if ( V_111 -> V_12 == 1 ) {
V_112 = F_61 ( V_111 , V_114 , 0 ) ;
}
return V_112 ;
}
static T_4
F_65 ( int V_115 , int V_112 )
{
int V_66 = 0 ;
if ( V_115 < 0 || V_115 >= V_96
|| V_97 [ V_115 ] . V_108 == NULL )
return FALSE ;
V_66 = ( * V_97 [ V_115 ] . V_108 ) ( V_112 ) ;
if ( V_66 != 0 ) {
if ( V_66 == V_116
&& V_97 [ V_115 ] . V_110 != NULL
&& V_97 [ V_115 ] . V_110 -> V_117 != NULL ) {
V_66 = ( * V_97 [ V_115 ] . V_110 -> V_117 ) ( V_112 , V_97 [ V_115 ] . V_110 -> V_61 ) ;
}
if ( V_66 != 0 )
return FALSE ;
}
return TRUE ;
}
static T_4
F_66 ( int V_118 , const T_10 * V_111 ,
T_11 V_119 )
{
T_3 V_18 ;
if ( ! F_67 ( V_118 ) ) {
return FALSE ;
}
if ( ! F_68 ( V_118 , V_119 ) ) {
return FALSE ;
}
if ( ! F_65 ( V_118 , F_64 ( V_111 ) ) ) {
return FALSE ;
}
for ( V_18 = 0 ; V_18 < V_111 -> V_12 ; V_18 ++ ) {
if ( ! F_65 ( V_118 ,
F_61 ( V_111 , int , V_18 ) ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_4
F_69 ( const T_10 * V_111 , T_11 V_119 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
if ( F_66 ( V_118 , V_111 , V_119 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_10 *
F_70 ( int V_77 ,
const T_10 * V_111 , T_11 V_119 )
{
T_10 * V_121 ;
int V_118 ;
int V_122 = - 1 ;
int V_123 = - 1 ;
if ( F_66 ( V_77 , V_111 ,
V_119 ) ) {
V_122 = V_77 ;
} else {
V_122 = - 1 ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
if ( F_66 ( V_118 , V_111 ,
V_119 ) ) {
V_122 = V_118 ;
}
}
}
if ( V_122 == - 1 ) {
return NULL ;
}
V_121 = F_6 ( FALSE , FALSE , ( T_3 ) sizeof ( int ) ) ;
F_9 ( V_121 , V_122 ) ;
if ( V_122 == V_78 ) {
if ( F_66 ( V_124 , V_111 ,
V_119 ) )
V_123 = V_124 ;
} else if ( V_122 == V_124 ) {
if ( F_66 ( V_78 , V_111 ,
V_119 ) )
V_123 = V_78 ;
}
if ( V_123 != - 1 )
F_9 ( V_121 , V_123 ) ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
if ( V_118 == V_102 )
continue;
if ( V_118 == V_122 || V_118 == V_123 )
continue;
if ( F_66 ( V_118 , V_111 ,
V_119 ) ) {
F_9 ( V_121 , V_118 ) ;
}
}
return V_121 ;
}
const char *
F_71 ( int V_77 )
{
if ( V_77 < 0 || V_77 >= V_96 ) {
F_21 ( L_15 , V_77 ) ;
return L_8 ;
} else
return V_97 [ V_77 ] . V_14 ;
}
const char *
F_72 ( int V_77 )
{
if ( V_77 < 0 || V_77 >= V_96 )
return NULL ;
else
return V_97 [ V_77 ] . V_101 ;
}
int
F_60 ( const char * V_101 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_96 ; V_77 ++ ) {
if ( V_97 [ V_77 ] . V_101 != NULL &&
strcmp ( V_101 , V_97 [ V_77 ] . V_101 ) == 0 )
return V_77 ;
}
if ( strcmp ( V_101 , L_16 ) == 0 )
return V_78 ;
return - 1 ;
}
static T_1 *
F_73 ( int V_77 , T_1 * V_1 ,
const char * * V_3 )
{
T_2 * * V_15 , * * V_16 ;
T_2 * V_2 ;
V_1 = F_1 ( V_1 ,
V_97 [ V_77 ] . V_103 ,
V_3 ) ;
if ( V_97 [ V_77 ] . V_104 != NULL ) {
V_15 = F_13 ( V_97 [ V_77 ] . V_104 ,
L_2 , 0 ) ;
for ( V_16 = V_15 ; * V_16 != NULL ;
V_16 ++ ) {
V_2 = * V_16 ;
V_1 = F_1 ( V_1 , V_2 ,
V_3 ) ;
}
F_14 ( V_15 ) ;
}
return V_1 ;
}
T_1 *
F_74 ( int V_77 , T_4 V_125 )
{
T_1 * V_1 ;
static const char * V_126 [] = {
NULL
} ;
if ( V_77 < 0 || V_77 >= V_96 )
return NULL ;
if ( V_97 [ V_77 ] . V_103 == NULL )
return NULL ;
V_1 = NULL ;
V_1 = F_73 ( V_77 , V_1 ,
V_125 ? V_17 : V_126 ) ;
return V_1 ;
}
void
F_75 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; V_2 != NULL ;
V_2 = F_76 ( V_2 ) ) {
F_30 ( V_2 -> V_10 ) ;
}
F_77 ( V_1 ) ;
}
const char *
F_78 ( int V_77 )
{
if ( V_77 < 0 || V_77 >= V_96 )
return NULL ;
else
return V_97 [ V_77 ] . V_103 ;
}
T_4
F_67 ( int V_77 )
{
if ( V_77 < 0 || V_77 >= V_96
|| V_97 [ V_77 ] . V_109 == NULL )
return FALSE ;
return TRUE ;
}
T_4
F_79 ( int V_77 )
{
if ( V_77 < 0 || V_77 >= V_96
|| V_97 [ V_77 ] . V_105 )
return FALSE ;
return TRUE ;
}
T_4
F_79 ( int V_77 V_127 )
{
return FALSE ;
}
T_4
F_80 ( int V_77 )
{
if ( V_77 < 0 || V_77 >= V_96
|| V_97 [ V_77 ] . V_106 == FALSE )
return FALSE ;
return TRUE ;
}
T_4
F_68 ( int V_77 , T_11 V_128 )
{
T_11 V_107 ;
if ( V_77 < 0 || V_77 >= V_96 )
return FALSE ;
V_107 = V_97 [ V_77 ] . V_107 ;
if ( ( V_128 & V_107 ) == V_128 )
return TRUE ;
return FALSE ;
}
static T_12 *
F_81 ( int V_77 , int V_112 , int V_129 , T_4 V_130 ,
T_10 * V_62 , T_13 * V_131 ,
T_10 * V_132 , int * V_35 )
{
T_12 * V_133 ;
T_8 V_80 , V_134 ;
T_9 * V_82 , * V_135 ;
if ( ! F_82 ( V_77 , V_112 , V_130 , V_35 ) )
return NULL ;
V_133 = F_83 ( V_77 , V_112 , V_129 , V_130 , V_35 ) ;
if ( V_133 == NULL )
return NULL ;
V_133 -> V_62 = V_62 ;
V_133 -> V_132 = V_132 ;
if ( ( V_131 != NULL ) && ( V_131 -> V_64 -> V_12 > 0 ) ) {
T_3 V_136 ;
V_133 -> V_64 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
for ( V_136 = 0 ; V_136 < V_131 -> V_64 -> V_12 ; V_136 ++ ) {
V_134 = F_61 ( V_131 -> V_64 , T_8 , V_136 ) ;
V_135 = ( T_9 * ) F_53 ( V_134 ) ;
V_80 = F_46 ( V_81 ) ;
F_84 ( V_80 , V_134 ) ;
if ( ( V_112 != V_113 ) && ( V_112 != V_135 -> V_83 ) ) {
V_82 = ( T_9 * ) F_53 ( V_80 ) ;
V_82 -> V_83 = V_112 ;
V_82 -> V_88 = F_55 ( V_112 ) ;
}
F_9 ( V_133 -> V_64 , V_80 ) ;
}
} else {
V_80 = F_46 ( V_81 ) ;
V_82 = ( T_9 * ) F_53 ( V_80 ) ;
V_82 -> V_83 = V_112 ;
V_82 -> V_84 = 1000000 ;
V_82 -> V_88 = F_55 ( V_112 ) ;
V_82 -> V_89 = V_129 ;
F_85 ( V_80 , V_137 , L_17 ,
strlen ( L_17 ) ) ;
V_82 -> V_91 = 0 ;
V_82 -> V_92 = NULL ;
V_133 -> V_64 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
F_9 ( V_133 -> V_64 , V_80 ) ;
}
return V_133 ;
}
T_12 *
F_86 ( const char * V_32 , int V_77 , int V_112 ,
int V_129 , T_4 V_130 , int * V_35 )
{
return F_87 ( V_32 , V_77 , V_112 , V_129 , V_130 , NULL , NULL , NULL , V_35 ) ;
}
T_12 *
F_87 ( const char * V_32 , int V_77 , int V_112 ,
int V_129 , T_4 V_130 , T_10 * V_62 , T_13 * V_131 ,
T_10 * V_132 , int * V_35 )
{
T_12 * V_133 ;
T_14 V_52 ;
V_133 = F_81 ( V_77 , V_112 , V_129 , V_130 ,
V_62 , V_131 , V_132 , V_35 ) ;
if ( V_133 == NULL )
return NULL ;
V_43 = V_50 ;
V_52 = F_88 ( V_133 , V_32 ) ;
if ( V_52 == NULL ) {
* V_35 = V_43 ;
F_30 ( V_133 ) ;
return NULL ;
}
V_133 -> V_52 = V_52 ;
if ( ! F_89 ( V_133 , V_77 , V_130 , V_35 ) ) {
F_90 ( V_133 ) ;
F_91 ( V_32 ) ;
F_30 ( V_133 ) ;
return NULL ;
}
return V_133 ;
}
T_12 *
F_92 ( char * * V_138 , const char * V_139 ,
int V_77 , int V_112 ,
int V_129 , T_4 V_130 , int * V_35 )
{
return F_93 ( V_138 , V_139 , V_77 , V_112 , V_129 , V_130 , NULL , NULL , NULL , V_35 ) ;
}
T_12 *
F_93 ( char * * V_138 , const char * V_139 ,
int V_77 , int V_112 ,
int V_129 , T_4 V_130 ,
T_10 * V_62 ,
T_13 * V_131 ,
T_10 * V_132 , int * V_35 )
{
int V_38 ;
char * V_140 ;
T_12 * V_133 ;
T_14 V_52 ;
* V_138 = NULL ;
V_133 = F_81 ( V_77 , V_112 , V_129 , V_130 ,
V_62 , V_131 , V_132 , V_35 ) ;
if ( V_133 == NULL )
return NULL ;
V_38 = F_94 ( & V_140 , V_139 , L_18 ) ;
if ( V_38 == - 1 ) {
* V_35 = V_43 ;
F_30 ( V_133 ) ;
return NULL ;
}
* V_138 = V_140 ;
V_43 = V_50 ;
V_52 = F_95 ( V_133 , V_38 ) ;
if ( V_52 == NULL ) {
* V_35 = V_43 ;
F_43 ( V_38 ) ;
F_30 ( V_133 ) ;
return NULL ;
}
V_133 -> V_52 = V_52 ;
if ( ! F_89 ( V_133 , V_77 , V_130 , V_35 ) ) {
F_90 ( V_133 ) ;
F_91 ( V_140 ) ;
F_30 ( V_133 ) ;
return NULL ;
}
return V_133 ;
}
T_12 *
F_96 ( int V_38 , int V_77 , int V_112 , int V_129 ,
T_4 V_130 , int * V_35 )
{
return F_97 ( V_38 , V_77 , V_112 , V_129 , V_130 , NULL , NULL , NULL , V_35 ) ;
}
T_12 *
F_97 ( int V_38 , int V_77 , int V_112 , int V_129 ,
T_4 V_130 , T_10 * V_62 , T_13 * V_131 ,
T_10 * V_132 , int * V_35 )
{
T_12 * V_133 ;
T_14 V_52 ;
V_133 = F_81 ( V_77 , V_112 , V_129 , V_130 ,
V_62 , V_131 , V_132 , V_35 ) ;
if ( V_133 == NULL )
return NULL ;
V_43 = V_50 ;
V_52 = F_95 ( V_133 , V_38 ) ;
if ( V_52 == NULL ) {
* V_35 = V_43 ;
F_30 ( V_133 ) ;
return NULL ;
}
V_133 -> V_52 = V_52 ;
if ( ! F_89 ( V_133 , V_77 , V_130 , V_35 ) ) {
F_90 ( V_133 ) ;
F_30 ( V_133 ) ;
return NULL ;
}
return V_133 ;
}
T_12 *
F_98 ( int V_77 , int V_112 , int V_129 ,
T_4 V_130 , int * V_35 )
{
return F_99 ( V_77 , V_112 , V_129 , V_130 , NULL , NULL , NULL , V_35 ) ;
}
T_12 *
F_99 ( int V_77 , int V_112 , int V_129 ,
T_4 V_130 , T_10 * V_62 ,
T_13 * V_131 ,
T_10 * V_132 , int * V_35 )
{
T_12 * V_133 ;
T_14 V_52 ;
V_133 = F_81 ( V_77 , V_112 , V_129 , V_130 ,
V_62 , V_131 , V_132 , V_35 ) ;
if ( V_133 == NULL )
return NULL ;
#ifdef F_40
if ( F_41 ( 1 , V_51 ) == - 1 ) {
* V_35 = V_43 ;
F_30 ( V_133 ) ;
return NULL ;
}
#endif
V_43 = V_50 ;
V_52 = F_95 ( V_133 , 1 ) ;
if ( V_52 == NULL ) {
* V_35 = V_43 ;
F_30 ( V_133 ) ;
return NULL ;
}
V_133 -> V_52 = V_52 ;
V_133 -> V_141 = TRUE ;
if ( ! F_89 ( V_133 , V_77 , V_130 , V_35 ) ) {
F_90 ( V_133 ) ;
F_30 ( V_133 ) ;
return NULL ;
}
return V_133 ;
}
static T_4
F_82 ( int V_77 , int V_112 , T_4 V_130 , int * V_35 )
{
if ( ! F_67 ( V_77 ) ) {
* V_35 = V_142 ;
return FALSE ;
}
* V_35 = ( * V_97 [ V_77 ] . V_108 ) ( V_112 ) ;
if ( * V_35 == V_116
&& V_97 [ V_77 ] . V_110 != NULL
&& V_97 [ V_77 ] . V_110 -> V_117 != NULL ) {
* V_35 = ( * V_97 [ V_77 ] . V_110 -> V_117 ) ( V_112 , V_97 [ V_77 ] . V_110 -> V_61 ) ;
}
if ( * V_35 != 0 )
return FALSE ;
if( V_130 && ! F_79 ( V_77 ) ) {
* V_35 = V_143 ;
return FALSE ;
}
return TRUE ;
}
static T_12 *
F_83 ( int V_77 , int V_112 , int V_129 , T_4 V_130 , int * V_35 )
{
T_12 * V_133 ;
V_133 = ( T_12 * ) F_38 ( sizeof ( T_12 ) ) ;
if ( V_133 == NULL ) {
* V_35 = V_43 ;
return NULL ;
}
V_133 -> V_77 = V_77 ;
V_133 -> V_129 = V_129 ;
V_133 -> V_112 = V_112 ;
V_133 -> V_130 = V_130 ;
V_133 -> V_61 = NULL ;
return V_133 ;
}
static T_4
F_89 ( T_12 * V_133 , int V_77 , T_4 V_130 , int * V_35 )
{
int V_38 ;
T_4 V_144 ;
if( V_130 ) {
V_144 = TRUE ;
} else {
V_38 = F_100 ( ( V_145 * ) V_133 -> V_52 ) ;
if ( F_101 ( V_38 , 1 , V_146 ) == ( V_147 ) - 1 )
V_144 = TRUE ;
else {
F_101 ( V_38 , 0 , V_67 ) ;
V_144 = FALSE ;
}
}
if ( V_97 [ V_77 ] . V_105 && V_144 ) {
* V_35 = V_148 ;
return FALSE ;
}
if ( V_97 [ V_77 ] . V_110 )
V_133 -> V_61 = V_97 [ V_77 ] . V_110 -> V_61 ;
if ( ! ( * V_97 [ V_77 ] . V_109 ) ( V_133 , V_35 ) ) {
return FALSE ;
}
return TRUE ;
}
T_4
F_102 ( T_12 * V_133 , const struct V_149 * V_150 ,
const T_15 * V_151 , int * V_35 , T_2 * * V_36 )
{
* V_35 = 0 ;
* V_36 = NULL ;
return ( V_133 -> V_152 ) ( V_133 , V_150 , V_151 , V_35 , V_36 ) ;
}
void
F_103 ( T_12 * V_133 )
{
#ifdef F_104
if( V_133 -> V_130 ) {
F_105 ( ( V_153 ) V_133 -> V_52 ) ;
} else
#endif
{
fflush ( ( V_145 * ) V_133 -> V_52 ) ;
}
}
T_4
F_106 ( T_12 * V_133 , int * V_35 )
{
T_4 V_154 = TRUE ;
if ( V_133 -> V_155 != NULL ) {
if ( ! ( V_133 -> V_155 ) ( V_133 , V_35 ) )
V_154 = FALSE ;
}
V_43 = V_156 ;
if ( F_90 ( V_133 ) == V_157 ) {
if ( V_154 ) {
if ( V_35 != NULL )
* V_35 = V_43 ;
}
V_154 = FALSE ;
}
if ( V_133 -> V_60 != NULL )
F_30 ( V_133 -> V_60 ) ;
F_30 ( V_133 ) ;
return V_154 ;
}
T_16
F_107 ( T_12 * V_133 )
{
return V_133 -> V_158 ;
}
void
F_108 ( T_12 * V_133 , T_16 V_158 )
{
V_133 -> V_158 = V_158 ;
}
T_4
F_109 ( T_12 * V_133 , T_17 * V_159 )
{
if ( ! V_133 || V_133 -> V_77 < 0 || V_133 -> V_77 >= V_96
|| V_97 [ V_133 -> V_77 ] . V_106 == FALSE )
return FALSE ;
V_133 -> V_159 = V_159 ;
return TRUE ;
}
static T_14
F_88 ( T_12 * V_133 , const char * V_32 )
{
if( V_133 -> V_130 ) {
return F_110 ( V_32 ) ;
} else {
return F_111 ( V_32 , L_19 ) ;
}
}
static T_14
F_88 ( T_12 * V_133 V_127 , const char * V_32 )
{
return F_111 ( V_32 , L_19 ) ;
}
static T_14
F_95 ( T_12 * V_133 , int V_38 )
{
if( V_133 -> V_130 ) {
return F_112 ( V_38 ) ;
} else {
return F_113 ( V_38 , L_19 ) ;
}
}
static T_14
F_95 ( T_12 * V_133 V_127 , int V_38 )
{
return F_113 ( V_38 , L_19 ) ;
}
T_4
F_114 ( T_12 * V_133 , const void * V_160 , T_5 V_161 , int * V_35 )
{
T_5 V_162 ;
#ifdef F_104
if ( V_133 -> V_130 ) {
V_162 = F_115 ( ( V_153 ) V_133 -> V_52 , V_160 , ( unsigned int ) V_161 ) ;
if ( V_162 == 0 ) {
* V_35 = F_116 ( ( V_153 ) V_133 -> V_52 ) ;
return FALSE ;
}
} else
#endif
{
V_43 = V_163 ;
V_162 = fwrite ( V_160 , 1 , V_161 , ( V_145 * ) V_133 -> V_52 ) ;
if ( V_162 != V_161 ) {
if ( ferror ( ( V_145 * ) V_133 -> V_52 ) )
* V_35 = V_43 ;
else
* V_35 = V_164 ;
return FALSE ;
}
}
return TRUE ;
}
static int
F_90 ( T_12 * V_133 )
{
#ifdef F_104
if( V_133 -> V_130 ) {
return F_117 ( ( V_153 ) V_133 -> V_52 , V_133 -> V_141 ) ;
} else
#endif
{
return V_133 -> V_141 ? fflush ( ( V_145 * ) V_133 -> V_52 ) : fclose ( ( V_145 * ) V_133 -> V_52 ) ;
}
}
T_16
F_118 ( T_12 * V_133 , T_16 V_165 , int V_166 , int * V_35 )
{
#ifdef F_104
if( V_133 -> V_130 ) {
* V_35 = V_167 ;
return - 1 ;
} else
#endif
{
if ( - 1 == fseek ( ( V_145 * ) V_133 -> V_52 , ( long ) V_165 , V_166 ) ) {
* V_35 = V_43 ;
return - 1 ;
} else
{
return 0 ;
}
}
}
T_16
F_119 ( T_12 * V_133 , int * V_35 )
{
T_16 V_168 ;
#ifdef F_104
if( V_133 -> V_130 ) {
* V_35 = V_167 ;
return - 1 ;
} else
#endif
{
if ( - 1 == ( V_168 = ftell ( ( V_145 * ) V_133 -> V_52 ) ) ) {
* V_35 = V_43 ;
return - 1 ;
} else
{
return V_168 ;
}
}
}
