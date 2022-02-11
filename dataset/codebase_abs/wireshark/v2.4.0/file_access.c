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
if ( V_9 [ V_18 ] . V_19 ) {
V_1 = F_12 ( V_18 ,
V_1 , V_17 ) ;
}
}
return V_1 ;
}
static void
F_17 ( void )
{
T_3 V_18 ;
F_18 ( V_20 != NULL ) ;
for ( V_18 = 0 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( V_21 [ V_18 ] . type == V_22 ) {
V_23 = V_18 ;
break;
}
F_18 ( V_21 [ V_18 ] . type == V_24 ) ;
}
F_18 ( V_23 > 0 ) ;
}
void
F_19 ( void )
{
unsigned int V_18 ;
struct V_25 * V_26 ;
if ( V_20 )
return;
V_20 = F_6 ( TRUE , TRUE , sizeof( struct V_25 ) ) ;
F_7 ( V_20 , V_27 , V_28 ) ;
V_21 = (struct V_25 * ) ( void * ) V_20 -> V_10 ;
for ( V_18 = 0 , V_26 = V_21 ; V_18 < V_20 -> V_12 ; V_18 ++ , V_26 ++ ) {
if ( V_26 -> V_1 != NULL )
V_26 -> V_15 = F_13 ( V_26 -> V_1 , L_2 , 0 ) ;
}
F_17 () ;
}
void
F_20 ( struct V_25 * V_29 , const T_4 V_30 )
{
if ( ! V_29 || ! V_29 -> V_14 ) {
F_21 ( L_3 ) ;
return;
}
if ( F_22 ( V_29 -> V_14 ) ) {
F_21 ( L_4 ) ;
return;
}
if ( V_29 -> V_1 != NULL )
V_29 -> V_15 = F_13 ( V_29 -> V_1 , L_2 , 0 ) ;
if ( V_30 && V_29 -> type == V_24 ) {
F_23 ( V_20 , * V_29 ) ;
} else if ( ! V_30 && V_29 -> type == V_22 ) {
F_9 ( V_20 , * V_29 ) ;
} else {
F_24 ( V_20 , V_23 , * V_29 ) ;
}
V_21 = (struct V_25 * ) ( void * ) V_20 -> V_10 ;
F_17 () ;
}
void
F_25 ( const T_2 * V_14 )
{
T_3 V_18 ;
if ( ! V_14 ) {
F_21 ( L_5 ) ;
return;
}
for ( V_18 = 0 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( V_21 [ V_18 ] . V_14 && strcmp ( V_21 [ V_18 ] . V_14 , V_14 ) == 0 ) {
if ( V_21 [ V_18 ] . V_15 != NULL )
F_14 ( V_21 [ V_18 ] . V_15 ) ;
V_20 = F_26 ( V_20 , V_18 ) ;
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
if ( ! V_14 ) {
F_21 ( L_7 ) ;
return FALSE ;
}
for ( V_18 = 0 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( V_21 [ V_18 ] . V_14 && strcmp ( V_21 [ V_18 ] . V_14 , V_14 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
unsigned int
F_27 ( const char * V_14 )
{
unsigned int V_18 ;
if ( ! V_14 )
return V_31 ;
for ( V_18 = 0 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( V_21 [ V_18 ] . V_14 != NULL &&
strcmp ( V_14 , V_21 [ V_18 ] . V_14 ) == 0 )
return V_18 + 1 ;
}
return V_31 ;
}
static char *
F_28 ( const char * V_32 )
{
T_2 * V_33 ;
T_2 * * V_34 ;
T_5 V_35 ;
const char * * V_4 ;
T_2 * V_16 ;
if ( strcmp ( V_32 , L_8 ) == 0 )
return NULL ;
V_33 = F_29 ( V_32 ) ;
if ( strchr ( V_33 , '.' ) == NULL ) {
F_30 ( V_33 ) ;
return NULL ;
}
V_34 = F_13 ( V_33 , L_9 , 0 ) ;
F_30 ( V_33 ) ;
for ( V_35 = 0 ; V_34 [ V_35 ] != NULL ; V_35 ++ )
;
if ( V_35 == 0 ) {
F_14 ( V_34 ) ;
return NULL ;
}
if ( V_35 == 1 ) {
F_14 ( V_34 ) ;
return NULL ;
}
V_16 = V_34 [ V_35 - 1 ] ;
for ( V_4 = V_17 ;
* V_4 != NULL ;
V_4 ++ ) {
if ( strcmp ( V_16 , * V_4 ) == 0 ) {
if ( V_35 == 2 ) {
F_14 ( V_34 ) ;
return NULL ;
}
V_16 = F_3 ( V_34 [ V_35 - 2 ] ) ;
F_14 ( V_34 ) ;
return V_16 ;
}
}
V_16 = F_3 ( V_16 ) ;
F_14 ( V_34 ) ;
return V_16 ;
}
static T_4
F_31 ( unsigned int V_18 , const char * V_2 )
{
T_2 * * V_16 ;
if ( V_21 [ V_18 ] . V_1 == NULL )
return FALSE ;
for ( V_16 = V_21 [ V_18 ] . V_15 ; * V_16 != NULL ;
V_16 ++ ) {
if ( strcmp ( V_2 , * V_16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
T_6 *
F_32 ( const char * V_33 , unsigned int type , int * V_36 , char * * V_37 ,
T_4 V_38 )
{
int V_39 ;
T_7 V_40 ;
T_6 * V_41 ;
unsigned int V_18 ;
T_4 V_42 = FALSE ;
T_2 * V_2 ;
T_8 V_43 ;
* V_36 = 0 ;
* V_37 = NULL ;
if ( strcmp ( V_33 , L_10 ) == 0 )
V_42 = TRUE ;
if ( V_42 ) {
if ( F_33 ( 0 , & V_40 ) < 0 ) {
* V_36 = V_44 ;
return NULL ;
}
} else {
if ( F_34 ( V_33 , & V_40 ) < 0 ) {
* V_36 = V_44 ;
return NULL ;
}
}
if ( F_35 ( V_40 . V_45 ) ) {
if ( V_38 ) {
* V_36 = V_46 ;
return NULL ;
}
} else if ( F_36 ( V_40 . V_45 ) ) {
* V_36 = V_47 ;
return NULL ;
} else if ( ! F_37 ( V_40 . V_45 ) ) {
* V_36 = V_48 ;
return NULL ;
}
if ( V_42 && V_38 ) {
* V_36 = V_49 ;
return NULL ;
}
V_44 = V_50 ;
V_41 = ( T_6 * ) F_38 ( sizeof( T_6 ) ) ;
V_44 = V_51 ;
if ( V_42 ) {
V_39 = F_39 ( 0 ) ;
if ( V_39 < 0 ) {
* V_36 = V_44 ;
F_30 ( V_41 ) ;
return NULL ;
}
#ifdef F_40
if ( F_41 ( V_39 , V_52 ) == - 1 ) {
* V_36 = V_44 ;
F_30 ( V_41 ) ;
return NULL ;
}
#endif
if ( ! ( V_41 -> V_53 = F_42 ( V_39 ) ) ) {
* V_36 = V_44 ;
F_43 ( V_39 ) ;
F_30 ( V_41 ) ;
return NULL ;
}
} else {
if ( ! ( V_41 -> V_53 = F_44 ( V_33 ) ) ) {
* V_36 = V_44 ;
F_30 ( V_41 ) ;
return NULL ;
}
}
if ( V_38 ) {
if ( ! ( V_41 -> V_54 = F_44 ( V_33 ) ) ) {
* V_36 = V_44 ;
F_45 ( V_41 -> V_53 ) ;
F_30 ( V_41 ) ;
return NULL ;
}
} else
V_41 -> V_54 = NULL ;
V_41 -> V_55 = V_56 ;
V_41 -> V_57 = NULL ;
V_41 -> V_58 = NULL ;
V_41 -> V_59 = V_60 ;
V_41 -> V_61 = NULL ;
V_41 -> V_62 = NULL ;
V_41 -> V_63 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
V_43 = F_46 ( V_64 ) ;
if ( V_43 )
F_9 ( V_41 -> V_63 , V_43 ) ;
V_41 -> V_65 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
if ( V_41 -> V_54 ) {
V_41 -> V_66 = F_47 () ;
F_48 ( V_41 -> V_53 , FALSE , V_41 -> V_66 ) ;
F_48 ( V_41 -> V_54 , TRUE , V_41 -> V_66 ) ;
}
if ( type != V_31 && type <= V_20 -> V_12 ) {
int V_67 ;
if ( F_49 ( V_41 -> V_53 , 0 , V_68 , V_36 ) == - 1 ) {
F_50 ( V_41 ) ;
return NULL ;
}
V_41 -> V_62 = V_21 [ type - 1 ] . V_62 ;
V_67 = ( * V_21 [ type - 1 ] . V_69 ) ( V_41 , V_36 , V_37 ) ;
switch ( V_67 ) {
case V_70 :
F_50 ( V_41 ) ;
return NULL ;
case V_71 :
goto V_72;
case V_73 :
goto V_74;
}
}
for ( V_18 = 0 ; V_18 < V_23 ; V_18 ++ ) {
if ( F_49 ( V_41 -> V_53 , 0 , V_68 , V_36 ) == - 1 ) {
F_50 ( V_41 ) ;
return NULL ;
}
V_41 -> V_62 = V_21 [ V_18 ] . V_62 ;
switch ( ( * V_21 [ V_18 ] . V_69 ) ( V_41 , V_36 , V_37 ) ) {
case V_70 :
F_50 ( V_41 ) ;
return NULL ;
case V_71 :
break;
case V_73 :
goto V_74;
}
}
V_2 = F_28 ( V_33 ) ;
if ( V_2 != NULL ) {
for ( V_18 = V_23 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( F_31 ( V_18 , V_2 ) ) {
if ( F_49 ( V_41 -> V_53 , 0 , V_68 , V_36 ) == - 1 ) {
F_30 ( V_2 ) ;
F_50 ( V_41 ) ;
return NULL ;
}
V_41 -> V_62 = V_21 [ V_18 ] . V_62 ;
switch ( ( * V_21 [ V_18 ] . V_69 ) ( V_41 ,
V_36 , V_37 ) ) {
case V_70 :
F_30 ( V_2 ) ;
F_50 ( V_41 ) ;
return NULL ;
case V_71 :
break;
case V_73 :
F_30 ( V_2 ) ;
goto V_74;
}
}
}
for ( V_18 = V_23 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( V_21 [ V_18 ] . V_1 == NULL ) {
if ( F_49 ( V_41 -> V_53 , 0 , V_68 , V_36 ) == - 1 ) {
F_30 ( V_2 ) ;
F_50 ( V_41 ) ;
return NULL ;
}
V_41 -> V_62 = V_21 [ V_18 ] . V_62 ;
switch ( ( * V_21 [ V_18 ] . V_69 ) ( V_41 ,
V_36 , V_37 ) ) {
case V_70 :
F_30 ( V_2 ) ;
F_50 ( V_41 ) ;
return NULL ;
case V_71 :
break;
case V_73 :
F_30 ( V_2 ) ;
goto V_74;
}
}
}
for ( V_18 = V_23 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( V_21 [ V_18 ] . V_1 != NULL &&
! F_31 ( V_18 , V_2 ) ) {
if ( F_49 ( V_41 -> V_53 , 0 , V_68 , V_36 ) == - 1 ) {
F_30 ( V_2 ) ;
F_50 ( V_41 ) ;
return NULL ;
}
V_41 -> V_62 = V_21 [ V_18 ] . V_62 ;
switch ( ( * V_21 [ V_18 ] . V_69 ) ( V_41 ,
V_36 , V_37 ) ) {
case V_70 :
F_30 ( V_2 ) ;
F_50 ( V_41 ) ;
return NULL ;
case V_71 :
break;
case V_73 :
F_30 ( V_2 ) ;
goto V_74;
}
}
}
F_30 ( V_2 ) ;
} else {
for ( V_18 = V_23 ; V_18 < V_20 -> V_12 ; V_18 ++ ) {
if ( F_49 ( V_41 -> V_53 , 0 , V_68 , V_36 ) == - 1 ) {
F_50 ( V_41 ) ;
return NULL ;
}
V_41 -> V_62 = V_21 [ V_18 ] . V_62 ;
switch ( ( * V_21 [ V_18 ] . V_69 ) ( V_41 , V_36 , V_37 ) ) {
case V_70 :
F_50 ( V_41 ) ;
return NULL ;
case V_71 :
break;
case V_73 :
goto V_74;
}
}
}
V_72:
F_50 ( V_41 ) ;
* V_36 = V_75 ;
return NULL ;
V_74:
V_41 -> V_76 = (struct V_77 * ) F_51 ( sizeof( struct V_77 ) ) ;
F_52 ( V_41 -> V_76 , 1500 ) ;
if ( ( V_41 -> V_78 == V_79 ) ||
( V_41 -> V_78 == V_80 ) ) {
T_8 V_81 = F_46 ( V_82 ) ;
T_9 * V_83 = ( T_9 * ) F_53 ( V_81 ) ;
V_83 -> V_84 = V_41 -> V_55 ;
if ( V_41 -> V_78 == V_80 ) {
V_83 -> V_85 = 1000000000 ;
F_54 ( V_81 , V_86 , 9 ) ;
V_83 -> V_87 = V_88 ;
} else {
V_83 -> V_85 = 1000000 ;
V_83 -> V_87 = V_60 ;
}
V_83 -> V_89 = V_41 -> V_90 ;
V_83 -> V_91 = 0 ;
V_83 -> V_92 = NULL ;
F_9 ( V_41 -> V_65 , V_81 ) ;
}
return V_41 ;
}
T_4
F_55 ( T_6 * V_41 , const char * V_33 , int * V_36 )
{
T_7 V_40 ;
if ( strcmp ( V_33 , L_10 ) == 0 ) {
* V_36 = V_49 ;
return FALSE ;
}
if ( F_34 ( V_33 , & V_40 ) < 0 ) {
* V_36 = V_44 ;
return FALSE ;
}
if ( F_35 ( V_40 . V_45 ) ) {
* V_36 = V_46 ;
return FALSE ;
} else if ( F_36 ( V_40 . V_45 ) ) {
* V_36 = V_47 ;
return FALSE ;
} else if ( ! F_37 ( V_40 . V_45 ) ) {
* V_36 = V_48 ;
return FALSE ;
}
V_44 = V_51 ;
if ( ! F_56 ( V_41 -> V_54 , V_33 ) ) {
* V_36 = V_44 ;
return FALSE ;
}
return TRUE ;
}
static void
F_57 ( void )
{
if ( V_93 ) return;
V_93 = F_6 ( FALSE , TRUE , sizeof( struct V_94 ) ) ;
F_7 ( V_93 , V_95 , V_96 ) ;
V_97 = ( const struct V_94 * ) ( void * ) V_93 -> V_10 ;
}
int
F_58 ( const struct V_94 * V_98 , const int V_99 )
{
struct V_94 * V_100 ;
if ( ! V_98 || ! V_98 -> V_14 || ! V_98 -> V_101 || V_99 > V_96 ) {
F_21 ( L_11 ) ;
return V_99 ;
}
if ( V_99 == V_102 ) {
if ( F_59 ( V_98 -> V_101 ) > - 1 ) {
F_21 ( L_12 ) ;
return V_99 ;
}
F_57 () ;
F_9 ( V_93 , * V_98 ) ;
V_97 = ( const struct V_94 * ) ( void * ) V_93 -> V_10 ;
return V_96 ++ ;
}
if ( ! V_97 [ V_99 ] . V_101 || strcmp ( V_97 [ V_99 ] . V_101 , V_98 -> V_101 ) != 0 ) {
F_21 ( L_13 ) ;
return V_99 ;
}
F_57 () ;
V_100 = & F_60 ( V_93 , struct V_94 , V_99 ) ;
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
F_61 ( const int V_99 )
{
struct V_94 * V_100 ;
if ( V_99 < 0 || V_99 >= V_96 ) {
F_21 ( L_14 ) ;
return;
}
F_57 () ;
V_100 = & F_60 ( V_93 , struct V_94 , V_99 ) ;
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
F_62 ( void )
{
return V_96 ;
}
int
F_63 ( const T_10 * V_111 )
{
int V_112 ;
V_112 = V_113 ;
if ( V_111 -> V_12 == 1 ) {
V_112 = F_60 ( V_111 , V_114 , 0 ) ;
}
return V_112 ;
}
static T_4
F_64 ( int V_115 , int V_112 )
{
int V_67 = 0 ;
if ( V_115 < 0 || V_115 >= V_96
|| V_97 [ V_115 ] . V_108 == NULL )
return FALSE ;
V_67 = ( * V_97 [ V_115 ] . V_108 ) ( V_112 ) ;
if ( V_67 != 0 ) {
if ( V_67 == V_116
&& V_97 [ V_115 ] . V_110 != NULL
&& V_97 [ V_115 ] . V_110 -> V_117 != NULL ) {
V_67 = ( * V_97 [ V_115 ] . V_110 -> V_117 ) ( V_112 , V_97 [ V_115 ] . V_110 -> V_62 ) ;
}
if ( V_67 != 0 )
return FALSE ;
}
return TRUE ;
}
static T_4
F_65 ( int V_118 , const T_10 * V_111 ,
T_11 V_119 )
{
T_3 V_18 ;
if ( ! F_66 ( V_118 ) ) {
return FALSE ;
}
if ( ! F_67 ( V_118 , V_119 ) ) {
return FALSE ;
}
if ( ! F_64 ( V_118 , F_63 ( V_111 ) ) ) {
return FALSE ;
}
for ( V_18 = 0 ; V_18 < V_111 -> V_12 ; V_18 ++ ) {
if ( ! F_64 ( V_118 ,
F_60 ( V_111 , int , V_18 ) ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_4
F_68 ( const T_10 * V_111 , T_11 V_119 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
if ( F_65 ( V_118 , V_111 , V_119 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_10 *
F_69 ( int V_78 ,
const T_10 * V_111 , T_11 V_119 )
{
T_10 * V_121 ;
int V_118 ;
int V_122 = - 1 ;
int V_123 = - 1 ;
if ( F_65 ( V_78 , V_111 ,
V_119 ) ) {
V_122 = V_78 ;
} else {
V_122 = - 1 ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
if ( F_65 ( V_118 , V_111 ,
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
if ( V_122 == V_79 ) {
if ( F_65 ( V_124 , V_111 ,
V_119 ) )
V_123 = V_124 ;
} else if ( V_122 == V_124 ) {
if ( F_65 ( V_79 , V_111 ,
V_119 ) )
V_123 = V_79 ;
}
if ( V_123 != - 1 )
F_9 ( V_121 , V_123 ) ;
for ( V_118 = 0 ; V_118 < V_120 ; V_118 ++ ) {
if ( V_118 == V_102 )
continue;
if ( V_118 == V_122 || V_118 == V_123 )
continue;
if ( F_65 ( V_118 , V_111 ,
V_119 ) ) {
F_9 ( V_121 , V_118 ) ;
}
}
return V_121 ;
}
const char *
F_70 ( int V_78 )
{
if ( V_78 < 0 || V_78 >= V_96 ) {
F_21 ( L_15 , V_78 ) ;
return L_8 ;
} else
return V_97 [ V_78 ] . V_14 ;
}
const char *
F_71 ( int V_78 )
{
if ( V_78 < 0 || V_78 >= V_96 )
return NULL ;
else
return V_97 [ V_78 ] . V_101 ;
}
int
F_59 ( const char * V_101 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_96 ; V_78 ++ ) {
if ( V_97 [ V_78 ] . V_101 != NULL &&
strcmp ( V_101 , V_97 [ V_78 ] . V_101 ) == 0 )
return V_78 ;
}
if ( strcmp ( V_101 , L_16 ) == 0 )
return V_79 ;
else if ( strcmp ( V_101 , L_17 ) == 0 )
return V_80 ;
else if ( strcmp ( V_101 , L_18 ) == 0 )
return V_125 ;
else if ( strcmp ( V_101 , L_19 ) == 0 )
return V_126 ;
else if ( strcmp ( V_101 , L_20 ) == 0 )
return V_127 ;
else if ( strcmp ( V_101 , L_21 ) == 0 )
return V_128 ;
else if ( strcmp ( V_101 , L_22 ) == 0 )
return V_129 ;
return - 1 ;
}
static T_1 *
F_72 ( int V_78 , T_1 * V_1 ,
const char * * V_3 )
{
T_2 * * V_15 , * * V_16 ;
T_2 * V_2 ;
V_1 = F_1 ( V_1 ,
V_97 [ V_78 ] . V_103 ,
V_3 ) ;
if ( V_97 [ V_78 ] . V_104 != NULL ) {
V_15 = F_13 ( V_97 [ V_78 ] . V_104 ,
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
F_73 ( int V_78 , T_4 V_130 )
{
T_1 * V_1 ;
static const char * V_131 [] = {
NULL
} ;
if ( V_78 < 0 || V_78 >= V_96 )
return NULL ;
if ( V_97 [ V_78 ] . V_103 == NULL )
return NULL ;
V_1 = NULL ;
V_1 = F_72 ( V_78 , V_1 ,
V_130 ? V_17 : V_131 ) ;
return V_1 ;
}
void
F_74 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; V_2 != NULL ;
V_2 = F_75 ( V_2 ) ) {
F_30 ( V_2 -> V_10 ) ;
}
F_76 ( V_1 ) ;
}
const char *
F_77 ( int V_78 )
{
if ( V_78 < 0 || V_78 >= V_96 )
return NULL ;
else
return V_97 [ V_78 ] . V_103 ;
}
T_4
F_66 ( int V_78 )
{
if ( V_78 < 0 || V_78 >= V_96
|| V_97 [ V_78 ] . V_109 == NULL )
return FALSE ;
return TRUE ;
}
T_4
F_78 ( int V_78 )
{
if ( V_78 < 0 || V_78 >= V_96
|| V_97 [ V_78 ] . V_105 )
return FALSE ;
return TRUE ;
}
T_4
F_78 ( int V_78 V_132 )
{
return FALSE ;
}
T_4
F_79 ( int V_78 )
{
if ( V_78 < 0 || V_78 >= V_96
|| V_97 [ V_78 ] . V_106 == FALSE )
return FALSE ;
return TRUE ;
}
T_4
F_67 ( int V_78 , T_11 V_133 )
{
T_11 V_107 ;
if ( V_78 < 0 || V_78 >= V_96 )
return FALSE ;
V_107 = V_97 [ V_78 ] . V_107 ;
if ( ( V_133 & V_107 ) == V_133 )
return TRUE ;
return FALSE ;
}
static T_12 *
F_80 ( int V_78 , int V_112 , int V_134 , T_4 V_135 ,
T_10 * V_63 , T_13 * V_136 ,
T_10 * V_137 , int * V_36 )
{
T_12 * V_138 ;
T_8 V_81 , V_139 ;
T_9 * V_83 , * V_140 ;
if ( ! F_81 ( V_78 , V_112 , V_135 , V_36 ) )
return NULL ;
V_138 = F_82 ( V_78 , V_112 , V_134 , V_135 , V_36 ) ;
if ( V_138 == NULL )
return NULL ;
V_138 -> V_63 = V_63 ;
V_138 -> V_137 = V_137 ;
if ( ( V_136 != NULL ) && ( V_136 -> V_65 -> V_12 > 0 ) ) {
T_3 V_141 ;
V_138 -> V_65 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
for ( V_141 = 0 ; V_141 < V_136 -> V_65 -> V_12 ; V_141 ++ ) {
V_139 = F_60 ( V_136 -> V_65 , T_8 , V_141 ) ;
V_140 = ( T_9 * ) F_53 ( V_139 ) ;
V_81 = F_46 ( V_82 ) ;
F_83 ( V_81 , V_139 ) ;
if ( ( V_112 != V_113 ) && ( V_112 != V_140 -> V_84 ) ) {
V_83 = ( T_9 * ) F_53 ( V_81 ) ;
V_83 -> V_84 = V_112 ;
}
F_9 ( V_138 -> V_65 , V_81 ) ;
}
} else {
V_81 = F_46 ( V_82 ) ;
V_83 = ( T_9 * ) F_53 ( V_81 ) ;
V_83 -> V_84 = V_112 ;
V_83 -> V_85 = 1000000 ;
if ( V_134 == 0 ) {
if ( V_112 == V_142 )
V_134 = 128 * 1024 * 1024 ;
else
V_134 = V_143 ;
}
V_83 -> V_89 = V_134 ;
V_83 -> V_91 = 0 ;
V_83 -> V_92 = NULL ;
V_138 -> V_65 = F_6 ( FALSE , FALSE , sizeof( T_8 ) ) ;
F_9 ( V_138 -> V_65 , V_81 ) ;
}
return V_138 ;
}
T_12 *
F_84 ( const char * V_33 , int V_78 , int V_112 ,
int V_134 , T_4 V_135 , int * V_36 )
{
return F_85 ( V_33 , V_78 , V_112 , V_134 , V_135 , NULL , NULL , NULL , V_36 ) ;
}
T_12 *
F_85 ( const char * V_33 , int V_78 , int V_112 ,
int V_134 , T_4 V_135 , T_10 * V_63 , T_13 * V_136 ,
T_10 * V_137 , int * V_36 )
{
T_12 * V_138 ;
T_14 V_53 ;
V_138 = F_80 ( V_78 , V_112 , V_134 , V_135 ,
V_63 , V_136 , V_137 , V_36 ) ;
if ( V_138 == NULL )
return NULL ;
V_44 = V_51 ;
V_53 = F_86 ( V_138 , V_33 ) ;
if ( V_53 == NULL ) {
* V_36 = V_44 ;
F_30 ( V_138 ) ;
return NULL ;
}
V_138 -> V_53 = V_53 ;
if ( ! F_87 ( V_138 , V_78 , V_135 , V_36 ) ) {
F_88 ( V_138 ) ;
F_89 ( V_33 ) ;
F_30 ( V_138 ) ;
return NULL ;
}
return V_138 ;
}
T_12 *
F_90 ( char * * V_144 , const char * V_145 ,
int V_78 , int V_112 ,
int V_134 , T_4 V_135 , int * V_36 )
{
return F_91 ( V_144 , V_145 , V_78 , V_112 , V_134 , V_135 , NULL , NULL , NULL , V_36 ) ;
}
T_12 *
F_91 ( char * * V_144 , const char * V_145 ,
int V_78 , int V_112 ,
int V_134 , T_4 V_135 ,
T_10 * V_63 ,
T_13 * V_136 ,
T_10 * V_137 , int * V_36 )
{
int V_39 ;
char * V_146 ;
T_12 * V_138 ;
T_14 V_53 ;
* V_144 = NULL ;
V_138 = F_80 ( V_78 , V_112 , V_134 , V_135 ,
V_63 , V_136 , V_137 , V_36 ) ;
if ( V_138 == NULL )
return NULL ;
V_39 = F_92 ( & V_146 , V_145 , L_23 ) ;
if ( V_39 == - 1 ) {
* V_36 = V_44 ;
F_30 ( V_138 ) ;
return NULL ;
}
* V_144 = V_146 ;
V_44 = V_51 ;
V_53 = F_93 ( V_138 , V_39 ) ;
if ( V_53 == NULL ) {
* V_36 = V_44 ;
F_43 ( V_39 ) ;
F_30 ( V_138 ) ;
return NULL ;
}
V_138 -> V_53 = V_53 ;
if ( ! F_87 ( V_138 , V_78 , V_135 , V_36 ) ) {
F_88 ( V_138 ) ;
F_89 ( V_146 ) ;
F_30 ( V_138 ) ;
return NULL ;
}
return V_138 ;
}
T_12 *
F_94 ( int V_39 , int V_78 , int V_112 , int V_134 ,
T_4 V_135 , int * V_36 )
{
return F_95 ( V_39 , V_78 , V_112 , V_134 , V_135 , NULL , NULL , NULL , V_36 ) ;
}
T_12 *
F_95 ( int V_39 , int V_78 , int V_112 , int V_134 ,
T_4 V_135 , T_10 * V_63 , T_13 * V_136 ,
T_10 * V_137 , int * V_36 )
{
T_12 * V_138 ;
T_14 V_53 ;
V_138 = F_80 ( V_78 , V_112 , V_134 , V_135 ,
V_63 , V_136 , V_137 , V_36 ) ;
if ( V_138 == NULL )
return NULL ;
V_44 = V_51 ;
V_53 = F_93 ( V_138 , V_39 ) ;
if ( V_53 == NULL ) {
* V_36 = V_44 ;
F_30 ( V_138 ) ;
return NULL ;
}
V_138 -> V_53 = V_53 ;
if ( ! F_87 ( V_138 , V_78 , V_135 , V_36 ) ) {
F_88 ( V_138 ) ;
F_30 ( V_138 ) ;
return NULL ;
}
return V_138 ;
}
T_12 *
F_96 ( int V_78 , int V_112 , int V_134 ,
T_4 V_135 , int * V_36 )
{
return F_97 ( V_78 , V_112 , V_134 , V_135 , NULL , NULL , NULL , V_36 ) ;
}
T_12 *
F_97 ( int V_78 , int V_112 , int V_134 ,
T_4 V_135 , T_10 * V_63 ,
T_13 * V_136 ,
T_10 * V_137 , int * V_36 )
{
int V_147 ;
T_12 * V_138 ;
V_147 = F_39 ( 1 ) ;
if ( V_147 == - 1 ) {
* V_36 = V_44 ;
return NULL ;
}
#ifdef F_40
if ( F_41 ( V_147 , V_52 ) == - 1 ) {
* V_36 = V_44 ;
F_43 ( V_147 ) ;
return NULL ;
}
#endif
V_138 = F_95 ( V_147 , V_78 , V_112 , V_134 ,
V_135 , V_63 , V_136 , V_137 , V_36 ) ;
if ( V_138 == NULL ) {
F_43 ( V_147 ) ;
return NULL ;
}
return V_138 ;
}
static T_4
F_81 ( int V_78 , int V_112 , T_4 V_135 , int * V_36 )
{
if ( ! F_66 ( V_78 ) ) {
* V_36 = V_148 ;
return FALSE ;
}
* V_36 = ( * V_97 [ V_78 ] . V_108 ) ( V_112 ) ;
if ( * V_36 == V_116
&& V_97 [ V_78 ] . V_110 != NULL
&& V_97 [ V_78 ] . V_110 -> V_117 != NULL ) {
* V_36 = ( * V_97 [ V_78 ] . V_110 -> V_117 ) ( V_112 , V_97 [ V_78 ] . V_110 -> V_62 ) ;
}
if ( * V_36 != 0 )
return FALSE ;
if( V_135 && ! F_78 ( V_78 ) ) {
* V_36 = V_149 ;
return FALSE ;
}
return TRUE ;
}
static T_12 *
F_82 ( int V_78 , int V_112 , int V_134 , T_4 V_135 , int * V_36 )
{
T_12 * V_138 ;
V_138 = ( T_12 * ) F_38 ( sizeof ( T_12 ) ) ;
if ( V_138 == NULL ) {
* V_36 = V_44 ;
return NULL ;
}
V_138 -> V_78 = V_78 ;
V_138 -> V_134 = V_134 ;
V_138 -> V_112 = V_112 ;
V_138 -> V_135 = V_135 ;
V_138 -> V_62 = NULL ;
return V_138 ;
}
static T_4
F_87 ( T_12 * V_138 , int V_78 , T_4 V_135 , int * V_36 )
{
int V_39 ;
T_4 V_150 ;
if( V_135 ) {
V_150 = TRUE ;
} else {
V_39 = F_98 ( ( V_151 * ) V_138 -> V_53 ) ;
if ( F_99 ( V_39 , 1 , V_152 ) == ( V_153 ) - 1 )
V_150 = TRUE ;
else {
F_99 ( V_39 , 0 , V_68 ) ;
V_150 = FALSE ;
}
}
if ( V_97 [ V_78 ] . V_105 && V_150 ) {
* V_36 = V_154 ;
return FALSE ;
}
if ( V_97 [ V_78 ] . V_110 )
V_138 -> V_62 = V_97 [ V_78 ] . V_110 -> V_62 ;
if ( ! ( * V_97 [ V_78 ] . V_109 ) ( V_138 , V_36 ) ) {
return FALSE ;
}
return TRUE ;
}
T_4
F_100 ( T_12 * V_138 , const struct V_155 * V_156 ,
const T_15 * V_157 , int * V_36 , T_2 * * V_37 )
{
* V_36 = 0 ;
* V_37 = NULL ;
return ( V_138 -> V_158 ) ( V_138 , V_156 , V_157 , V_36 , V_37 ) ;
}
void
F_101 ( T_12 * V_138 )
{
#ifdef F_102
if( V_138 -> V_135 ) {
F_103 ( ( V_159 ) V_138 -> V_53 ) ;
} else
#endif
{
fflush ( ( V_151 * ) V_138 -> V_53 ) ;
}
}
T_4
F_104 ( T_12 * V_138 , int * V_36 )
{
T_4 V_160 = TRUE ;
if ( V_138 -> V_161 != NULL ) {
if ( ! ( V_138 -> V_161 ) ( V_138 , V_36 ) )
V_160 = FALSE ;
}
V_44 = V_162 ;
if ( F_88 ( V_138 ) == V_163 ) {
if ( V_160 ) {
if ( V_36 != NULL )
* V_36 = V_44 ;
}
V_160 = FALSE ;
}
if ( V_138 -> V_61 != NULL )
F_30 ( V_138 -> V_61 ) ;
F_105 ( V_138 -> V_65 ) ;
F_30 ( V_138 ) ;
return V_160 ;
}
T_16
F_106 ( T_12 * V_138 )
{
return V_138 -> V_164 ;
}
void
F_107 ( T_12 * V_138 , T_16 V_164 )
{
V_138 -> V_164 = V_164 ;
}
T_4
F_108 ( T_12 * V_138 , T_17 * V_165 )
{
if ( ! V_138 || V_138 -> V_78 < 0 || V_138 -> V_78 >= V_96
|| V_97 [ V_138 -> V_78 ] . V_106 == FALSE )
return FALSE ;
V_138 -> V_165 = V_165 ;
return TRUE ;
}
T_4 F_109 ( T_12 * V_138 ) {
return V_138 -> V_166 ;
}
static T_14
F_86 ( T_12 * V_138 , const char * V_33 )
{
if( V_138 -> V_135 ) {
return F_110 ( V_33 ) ;
} else {
return F_111 ( V_33 , L_24 ) ;
}
}
static T_14
F_86 ( T_12 * V_138 V_132 , const char * V_33 )
{
return F_111 ( V_33 , L_24 ) ;
}
static T_14
F_93 ( T_12 * V_138 , int V_39 )
{
if( V_138 -> V_135 ) {
return F_112 ( V_39 ) ;
} else {
return F_113 ( V_39 , L_24 ) ;
}
}
static T_14
F_93 ( T_12 * V_138 V_132 , int V_39 )
{
return F_113 ( V_39 , L_24 ) ;
}
T_4
F_114 ( T_12 * V_138 , const void * V_167 , T_5 V_168 , int * V_36 )
{
T_5 V_169 ;
#ifdef F_102
if ( V_138 -> V_135 ) {
V_169 = F_115 ( ( V_159 ) V_138 -> V_53 , V_167 , ( unsigned int ) V_168 ) ;
if ( V_169 == 0 ) {
* V_36 = F_116 ( ( V_159 ) V_138 -> V_53 ) ;
return FALSE ;
}
} else
#endif
{
V_44 = V_170 ;
V_169 = fwrite ( V_167 , 1 , V_168 , ( V_151 * ) V_138 -> V_53 ) ;
if ( V_169 != V_168 ) {
if ( ferror ( ( V_151 * ) V_138 -> V_53 ) )
* V_36 = V_44 ;
else
* V_36 = V_171 ;
return FALSE ;
}
}
return TRUE ;
}
static int
F_88 ( T_12 * V_138 )
{
#ifdef F_102
if( V_138 -> V_135 )
return F_117 ( ( V_159 ) V_138 -> V_53 ) ;
else
#endif
return fclose ( ( V_151 * ) V_138 -> V_53 ) ;
}
T_16
F_118 ( T_12 * V_138 , T_16 V_172 , int V_173 , int * V_36 )
{
#ifdef F_102
if( V_138 -> V_135 ) {
* V_36 = V_174 ;
return - 1 ;
} else
#endif
{
if ( - 1 == fseek ( ( V_151 * ) V_138 -> V_53 , ( long ) V_172 , V_173 ) ) {
* V_36 = V_44 ;
return - 1 ;
} else
{
return 0 ;
}
}
}
T_16
F_119 ( T_12 * V_138 , int * V_36 )
{
T_16 V_175 ;
#ifdef F_102
if( V_138 -> V_135 ) {
* V_36 = V_174 ;
return - 1 ;
} else
#endif
{
if ( - 1 == ( V_175 = ftell ( ( V_151 * ) V_138 -> V_53 ) ) ) {
* V_36 = V_44 ;
return - 1 ;
} else
{
return V_175 ;
}
}
}
void
F_120 ( void )
{
T_3 V_18 ;
struct V_25 * V_26 ;
if ( V_21 != NULL && V_20 ) {
for ( V_18 = 0 , V_26 = V_21 ; V_18 < V_20 -> V_12 ; V_18 ++ , V_26 ++ ) {
if ( V_26 -> V_1 != NULL )
F_14 ( V_26 -> V_15 ) ;
}
F_121 ( V_20 , TRUE ) ;
V_20 = NULL ;
}
}
