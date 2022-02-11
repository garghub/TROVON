static T_1 *
F_1 ( T_1 * V_1 , const T_2 * V_2 ,
T_1 * V_3 )
{
T_1 * V_4 ;
V_1 = F_2 ( V_1 , F_3 ( V_2 ) ) ;
for ( V_4 = V_3 ;
V_4 != NULL ;
V_4 = F_4 ( V_4 ) ) {
V_1 = F_2 ( V_1 ,
F_5 ( L_1 , V_2 ,
( T_2 * ) V_4 -> V_5 ) ) ;
}
return V_1 ;
}
static void
F_6 ( void )
{
if ( V_6 ) return;
V_6 = F_7 ( FALSE , TRUE , sizeof( struct V_7 ) ) ;
F_8 ( V_6 , V_8 , V_9 ) ;
V_10 = (struct V_7 * ) ( void * ) V_6 -> V_5 ;
}
void
F_9 ( const struct V_7 * V_11 )
{
F_6 () ;
F_10 ( V_6 , * V_11 ) ;
V_10 = ( const struct V_7 * ) ( void * ) V_6 -> V_5 ;
}
int
F_11 ( void )
{
return V_6 -> V_12 ;
}
const char *
F_12 ( int V_13 )
{
return V_10 [ V_13 ] . V_14 ;
}
static T_1 *
F_13 ( int V_13 ,
T_1 * V_1 , T_1 * V_3 )
{
T_2 * * V_15 , * * V_16 , * V_2 ;
V_15 = F_14 ( V_10 [ V_13 ] . V_1 ,
L_2 , 0 ) ;
for ( V_16 = V_15 ; * V_16 != NULL ; V_16 ++ ) {
V_2 = * V_16 ;
V_1 = F_1 ( V_1 , V_2 ,
V_3 ) ;
}
F_15 ( V_15 ) ;
return V_1 ;
}
T_1 *
F_16 ( T_3 V_13 )
{
T_1 * V_3 ;
T_1 * V_1 ;
if ( V_13 >= V_6 -> V_12 )
return NULL ;
V_1 = NULL ;
V_3 = F_17 () ;
V_1 = F_13 ( V_13 ,
V_1 , V_3 ) ;
F_18 ( V_3 ) ;
return V_1 ;
}
T_1 *
F_19 ( void )
{
T_1 * V_3 ;
T_1 * V_1 ;
unsigned int V_17 ;
F_6 () ;
V_1 = NULL ;
V_3 = F_17 () ;
for ( V_17 = 0 ; V_17 < V_6 -> V_12 ; V_17 ++ ) {
V_1 = F_13 ( V_17 ,
V_1 , V_3 ) ;
}
F_18 ( V_3 ) ;
return V_1 ;
}
static void
F_20 ( void )
{
T_3 V_17 ;
F_21 ( V_18 != NULL ) ;
for ( V_17 = 0 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . type == V_20 ) {
V_21 = V_17 ;
break;
}
F_21 ( V_19 [ V_17 ] . type == V_22 ) ;
}
F_21 ( V_21 > 0 ) ;
}
void
F_22 ( void )
{
unsigned int V_17 ;
struct V_23 * V_24 ;
if ( V_18 )
return;
V_18 = F_7 ( TRUE , TRUE , sizeof( struct V_23 ) ) ;
F_8 ( V_18 , V_25 , V_26 ) ;
V_19 = (struct V_23 * ) ( void * ) V_18 -> V_5 ;
for ( V_17 = 0 , V_24 = V_19 ; V_17 < V_18 -> V_12 ; V_17 ++ , V_24 ++ ) {
if ( V_24 -> V_1 != NULL )
V_24 -> V_15 = F_14 ( V_24 -> V_1 , L_2 , 0 ) ;
}
F_20 () ;
}
void
F_23 ( struct V_23 * V_27 , const T_4 V_28 )
{
F_22 () ;
if ( ! V_27 || ! V_27 -> V_14 ) {
F_24 ( L_3 ) ;
return;
}
if ( F_25 ( V_27 -> V_14 ) ) {
F_24 ( L_4 ) ;
return;
}
if ( V_27 -> V_1 != NULL )
V_27 -> V_15 = F_14 ( V_27 -> V_1 , L_2 , 0 ) ;
if ( V_28 && V_27 -> type == V_22 ) {
F_26 ( V_18 , * V_27 ) ;
} else if ( ! V_28 && V_27 -> type == V_20 ) {
F_10 ( V_18 , * V_27 ) ;
} else {
F_27 ( V_18 , V_21 , * V_27 ) ;
}
V_19 = (struct V_23 * ) ( void * ) V_18 -> V_5 ;
F_20 () ;
}
void
F_28 ( const T_2 * V_14 )
{
T_3 V_17 ;
F_22 () ;
if ( ! V_14 ) {
F_24 ( L_5 ) ;
return;
}
for ( V_17 = 0 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_14 && strcmp ( V_19 [ V_17 ] . V_14 , V_14 ) == 0 ) {
if ( V_19 [ V_17 ] . V_15 != NULL )
F_15 ( V_19 [ V_17 ] . V_15 ) ;
V_18 = F_29 ( V_18 , V_17 ) ;
F_20 () ;
return;
}
}
F_24 ( L_6 ) ;
}
T_4
F_25 ( const T_2 * V_14 )
{
T_3 V_17 ;
F_22 () ;
if ( ! V_14 ) {
F_24 ( L_7 ) ;
return FALSE ;
}
for ( V_17 = 0 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_14 && strcmp ( V_19 [ V_17 ] . V_14 , V_14 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
unsigned int
F_30 ( const char * V_14 )
{
unsigned int V_17 ;
F_22 () ;
if ( ! V_14 )
return V_29 ;
for ( V_17 = 0 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_14 != NULL &&
strcmp ( V_14 , V_19 [ V_17 ] . V_14 ) == 0 )
return V_17 + 1 ;
}
return V_29 ;
}
static char *
F_31 ( const char * V_30 )
{
T_2 * V_31 ;
T_2 * * V_32 ;
T_5 V_33 ;
T_1 * V_3 , * V_4 ;
T_2 * V_16 ;
if ( strcmp ( V_30 , L_8 ) == 0 )
return NULL ;
V_31 = F_32 ( V_30 ) ;
if ( strchr ( V_31 , '.' ) == NULL ) {
F_33 ( V_31 ) ;
return NULL ;
}
V_32 = F_14 ( V_31 , L_9 , 0 ) ;
F_33 ( V_31 ) ;
for ( V_33 = 0 ; V_32 [ V_33 ] != NULL ; V_33 ++ )
;
if ( V_33 == 0 ) {
F_15 ( V_32 ) ;
return NULL ;
}
if ( V_33 == 1 ) {
F_15 ( V_32 ) ;
return NULL ;
}
V_3 = F_17 () ;
if ( V_3 == NULL ) {
V_16 = F_3 ( V_32 [ V_33 - 1 ] ) ;
F_15 ( V_32 ) ;
return V_16 ;
}
V_16 = V_32 [ V_33 - 1 ] ;
for ( V_4 = V_3 ;
V_4 != NULL ;
V_4 = F_4 ( V_4 ) ) {
if ( strcmp ( V_16 , ( char * ) V_4 -> V_5 ) == 0 ) {
if ( V_33 == 2 ) {
F_15 ( V_32 ) ;
return NULL ;
}
V_16 = F_3 ( V_32 [ V_33 - 2 ] ) ;
F_15 ( V_32 ) ;
return V_16 ;
}
}
V_16 = F_3 ( V_16 ) ;
F_15 ( V_32 ) ;
return V_16 ;
}
static T_4
F_34 ( unsigned int V_17 , const char * V_2 )
{
T_2 * * V_16 ;
if ( V_19 [ V_17 ] . V_1 == NULL )
return FALSE ;
for ( V_16 = V_19 [ V_17 ] . V_15 ; * V_16 != NULL ;
V_16 ++ ) {
if ( strcmp ( V_2 , * V_16 ) == 0 ) {
return TRUE ;
}
}
return FALSE ;
}
T_6 *
F_35 ( const char * V_31 , unsigned int type , int * V_34 , char * * V_35 ,
T_4 V_36 )
{
int V_37 ;
T_7 V_38 ;
T_6 * V_39 ;
unsigned int V_17 ;
T_4 V_40 = FALSE ;
T_2 * V_2 ;
* V_34 = 0 ;
* V_35 = NULL ;
F_22 () ;
if ( strcmp ( V_31 , L_10 ) == 0 )
V_40 = TRUE ;
if ( V_40 ) {
if ( F_36 ( 0 , & V_38 ) < 0 ) {
* V_34 = V_41 ;
return NULL ;
}
} else {
if ( F_37 ( V_31 , & V_38 ) < 0 ) {
* V_34 = V_41 ;
return NULL ;
}
}
if ( F_38 ( V_38 . V_42 ) ) {
if ( V_36 ) {
* V_34 = V_43 ;
return NULL ;
}
} else if ( F_39 ( V_38 . V_42 ) ) {
* V_34 = V_44 ;
return NULL ;
} else if ( ! F_40 ( V_38 . V_42 ) ) {
* V_34 = V_45 ;
return NULL ;
}
if ( V_40 && V_36 ) {
* V_34 = V_46 ;
return NULL ;
}
V_41 = V_47 ;
V_39 = ( T_6 * ) F_41 ( sizeof( T_6 ) ) ;
V_41 = V_48 ;
if ( V_40 ) {
V_37 = F_42 ( 0 ) ;
if ( V_37 < 0 ) {
* V_34 = V_41 ;
F_33 ( V_39 ) ;
return NULL ;
}
#ifdef F_43
if ( F_44 ( V_37 , V_49 ) == - 1 ) {
* V_34 = V_41 ;
F_33 ( V_39 ) ;
return NULL ;
}
#endif
if ( ! ( V_39 -> V_50 = F_45 ( V_37 ) ) ) {
* V_34 = V_41 ;
F_46 ( V_37 ) ;
F_33 ( V_39 ) ;
return NULL ;
}
} else {
if ( ! ( V_39 -> V_50 = F_47 ( V_31 ) ) ) {
* V_34 = V_41 ;
F_33 ( V_39 ) ;
return NULL ;
}
}
if ( V_36 ) {
if ( ! ( V_39 -> V_51 = F_47 ( V_31 ) ) ) {
* V_34 = V_41 ;
F_48 ( V_39 -> V_50 ) ;
F_33 ( V_39 ) ;
return NULL ;
}
} else
V_39 -> V_51 = NULL ;
V_39 -> V_52 = V_53 ;
V_39 -> V_54 = NULL ;
V_39 -> V_55 = NULL ;
V_39 -> V_56 = V_57 ;
V_39 -> V_58 = NULL ;
V_39 -> V_59 = NULL ;
V_39 -> V_60 = F_7 ( FALSE , FALSE , sizeof( V_61 ) ) ;
if ( V_39 -> V_51 ) {
V_39 -> V_62 = F_49 () ;
F_50 ( V_39 -> V_50 , FALSE , V_39 -> V_62 ) ;
F_50 ( V_39 -> V_51 , TRUE , V_39 -> V_62 ) ;
}
if ( type != V_29 && type <= V_18 -> V_12 ) {
int V_63 ;
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ type - 1 ] . V_59 ;
V_63 = ( * V_19 [ type - 1 ] . V_65 ) ( V_39 , V_34 , V_35 ) ;
switch ( V_63 ) {
case V_66 :
F_52 ( V_39 ) ;
return NULL ;
case V_67 :
goto V_68;
case V_69 :
goto V_70;
}
}
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ V_17 ] . V_59 ;
switch ( ( * V_19 [ V_17 ] . V_65 ) ( V_39 , V_34 , V_35 ) ) {
case V_66 :
F_52 ( V_39 ) ;
return NULL ;
case V_67 :
break;
case V_69 :
goto V_70;
}
}
V_2 = F_31 ( V_31 ) ;
if ( V_2 != NULL ) {
for ( V_17 = V_21 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( F_34 ( V_17 , V_2 ) ) {
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ V_17 ] . V_59 ;
switch ( ( * V_19 [ V_17 ] . V_65 ) ( V_39 ,
V_34 , V_35 ) ) {
case V_66 :
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
case V_67 :
break;
case V_69 :
F_33 ( V_2 ) ;
goto V_70;
}
}
}
for ( V_17 = V_21 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_1 == NULL ) {
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ V_17 ] . V_59 ;
switch ( ( * V_19 [ V_17 ] . V_65 ) ( V_39 ,
V_34 , V_35 ) ) {
case V_66 :
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
case V_67 :
break;
case V_69 :
F_33 ( V_2 ) ;
goto V_70;
}
}
}
for ( V_17 = V_21 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_1 != NULL &&
! F_34 ( V_17 , V_2 ) ) {
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ V_17 ] . V_59 ;
switch ( ( * V_19 [ V_17 ] . V_65 ) ( V_39 ,
V_34 , V_35 ) ) {
case V_66 :
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
case V_67 :
break;
case V_69 :
F_33 ( V_2 ) ;
goto V_70;
}
}
}
F_33 ( V_2 ) ;
} else {
for ( V_17 = V_21 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ V_17 ] . V_59 ;
switch ( ( * V_19 [ V_17 ] . V_65 ) ( V_39 , V_34 , V_35 ) ) {
case V_66 :
F_52 ( V_39 ) ;
return NULL ;
case V_67 :
break;
case V_69 :
goto V_70;
}
}
}
V_68:
F_52 ( V_39 ) ;
* V_34 = V_71 ;
return NULL ;
V_70:
V_39 -> V_72 = (struct V_73 * ) F_53 ( sizeof( struct V_73 ) ) ;
F_54 ( V_39 -> V_72 , 1500 ) ;
if ( ( V_39 -> V_74 == V_75 ) ||
( V_39 -> V_74 == V_76 ) ) {
V_61 V_77 ;
V_77 . V_78 = V_39 -> V_52 ;
if ( V_39 -> V_74 == V_76 ) {
V_77 . V_79 = 1000000000 ;
V_77 . V_80 = 9 ;
V_77 . V_81 = V_82 ;
} else {
V_77 . V_79 = 1000000 ;
V_77 . V_80 = 6 ;
V_77 . V_81 = V_57 ;
}
V_77 . V_83 = F_55 ( V_39 -> V_52 ) ;
V_77 . V_84 = V_39 -> V_85 ;
V_77 . V_86 = NULL ;
V_77 . V_87 = NULL ;
V_77 . V_88 = NULL ;
V_77 . V_89 = 0 ;
V_77 . V_90 = NULL ;
V_77 . V_91 = 0 ;
V_77 . V_92 = NULL ;
V_77 . V_93 = NULL ;
V_77 . V_94 = - 1 ;
V_77 . V_95 = 0 ;
V_77 . V_96 = NULL ;
F_10 ( V_39 -> V_60 , V_77 ) ;
}
return V_39 ;
}
T_4
F_56 ( T_6 * V_39 , const char * V_31 , int * V_34 )
{
T_7 V_38 ;
if ( strcmp ( V_31 , L_10 ) == 0 ) {
* V_34 = V_46 ;
return FALSE ;
}
if ( F_37 ( V_31 , & V_38 ) < 0 ) {
* V_34 = V_41 ;
return FALSE ;
}
if ( F_38 ( V_38 . V_42 ) ) {
* V_34 = V_43 ;
return FALSE ;
} else if ( F_39 ( V_38 . V_42 ) ) {
* V_34 = V_44 ;
return FALSE ;
} else if ( ! F_40 ( V_38 . V_42 ) ) {
* V_34 = V_45 ;
return FALSE ;
}
V_41 = V_48 ;
if ( ! F_57 ( V_39 -> V_51 , V_31 ) ) {
* V_34 = V_41 ;
return FALSE ;
}
return TRUE ;
}
static void
F_58 ( void )
{
if ( V_97 ) return;
V_97 = F_7 ( FALSE , TRUE , sizeof( struct V_98 ) ) ;
F_8 ( V_97 , V_99 , V_100 ) ;
V_101 = ( const struct V_98 * ) ( void * ) V_97 -> V_5 ;
}
int
F_59 ( const struct V_98 * V_102 , const int V_103 )
{
struct V_98 * V_104 ;
F_58 () ;
if ( ! V_102 || ! V_102 -> V_14 || ! V_102 -> V_105 || V_103 > V_100 ) {
F_24 ( L_11 ) ;
return V_103 ;
}
if ( V_103 == V_106 ) {
if ( F_60 ( V_102 -> V_105 ) > - 1 ) {
F_24 ( L_12 ) ;
return V_103 ;
}
F_10 ( V_97 , * V_102 ) ;
V_101 = ( const struct V_98 * ) ( void * ) V_97 -> V_5 ;
return V_100 ++ ;
}
if ( ! V_101 [ V_103 ] . V_105 || strcmp ( V_101 [ V_103 ] . V_105 , V_102 -> V_105 ) != 0 ) {
F_24 ( L_13 ) ;
return V_103 ;
}
V_104 = (struct V_98 * ) ( & V_101 [ V_103 ] ) ;
V_104 -> V_107 = V_102 -> V_107 ;
V_104 -> V_108 = V_102 -> V_108 ;
V_104 -> V_109 = V_102 -> V_109 ;
V_104 -> V_110 = V_102 -> V_110 ;
V_104 -> V_111 = V_102 -> V_111 ;
V_104 -> V_112 = V_102 -> V_112 ;
V_104 -> V_113 = V_102 -> V_113 ;
V_104 -> V_114 = V_102 -> V_114 ;
return V_103 ;
}
void
F_61 ( const int V_103 )
{
struct V_98 * V_104 ;
if ( V_103 < 0 || V_103 >= V_100 ) {
F_24 ( L_14 ) ;
return;
}
V_104 = (struct V_98 * ) ( & V_101 [ V_103 ] ) ;
V_104 -> V_107 = NULL ;
V_104 -> V_108 = NULL ;
V_104 -> V_109 = FALSE ;
V_104 -> V_110 = FALSE ;
V_104 -> V_111 = 0 ;
V_104 -> V_112 = NULL ;
V_104 -> V_113 = NULL ;
V_104 -> V_114 = NULL ;
}
int
F_62 ( void )
{
return V_100 ;
}
int
F_63 ( const T_8 * V_115 )
{
int V_116 ;
V_116 = V_117 ;
if ( V_115 -> V_12 == 1 ) {
V_116 = F_64 ( V_115 , V_118 , 0 ) ;
}
return V_116 ;
}
static T_4
F_65 ( int V_119 , int V_116 )
{
int V_63 = 0 ;
if ( V_119 < 0 || V_119 >= V_100
|| V_101 [ V_119 ] . V_112 == NULL )
return FALSE ;
V_63 = ( * V_101 [ V_119 ] . V_112 ) ( V_116 ) ;
if ( V_63 != 0 ) {
if ( V_63 == V_120
&& V_101 [ V_119 ] . V_114 != NULL
&& V_101 [ V_119 ] . V_114 -> V_121 != NULL ) {
V_63 = ( * V_101 [ V_119 ] . V_114 -> V_121 ) ( V_116 , V_101 [ V_119 ] . V_114 -> V_59 ) ;
}
if ( V_63 != 0 )
return FALSE ;
}
return TRUE ;
}
static T_4
F_66 ( int V_122 , const T_8 * V_115 ,
T_9 V_123 )
{
T_3 V_17 ;
if ( ! F_67 ( V_122 ) ) {
return FALSE ;
}
if ( ! F_68 ( V_122 , V_123 ) ) {
return FALSE ;
}
if ( ! F_65 ( V_122 , F_63 ( V_115 ) ) ) {
return FALSE ;
}
for ( V_17 = 0 ; V_17 < V_115 -> V_12 ; V_17 ++ ) {
if ( ! F_65 ( V_122 ,
F_64 ( V_115 , int , V_17 ) ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_4
F_69 ( const T_8 * V_115 , T_9 V_123 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_124 ; V_122 ++ ) {
if ( F_66 ( V_122 , V_115 , V_123 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_8 *
F_70 ( int V_74 ,
const T_8 * V_115 , T_9 V_123 )
{
T_8 * V_125 ;
int V_122 ;
int V_126 = - 1 ;
int V_127 = - 1 ;
if ( F_66 ( V_74 , V_115 ,
V_123 ) ) {
V_126 = V_74 ;
} else {
V_126 = - 1 ;
for ( V_122 = 0 ; V_122 < V_124 ; V_122 ++ ) {
if ( F_66 ( V_122 , V_115 ,
V_123 ) ) {
V_126 = V_122 ;
}
}
}
if ( V_126 == - 1 ) {
return NULL ;
}
V_125 = F_7 ( FALSE , FALSE , ( T_3 ) sizeof ( int ) ) ;
F_10 ( V_125 , V_126 ) ;
if ( V_126 == V_75 ) {
if ( F_66 ( V_128 , V_115 ,
V_123 ) )
V_127 = V_128 ;
} else if ( V_126 == V_128 ) {
if ( F_66 ( V_75 , V_115 ,
V_123 ) )
V_127 = V_75 ;
}
if ( V_127 != - 1 )
F_10 ( V_125 , V_127 ) ;
for ( V_122 = 0 ; V_122 < V_124 ; V_122 ++ ) {
if ( V_122 == V_106 )
continue;
if ( V_122 == V_126 || V_122 == V_127 )
continue;
if ( F_66 ( V_122 , V_115 ,
V_123 ) ) {
F_10 ( V_125 , V_122 ) ;
}
}
return V_125 ;
}
const char *
F_71 ( int V_74 )
{
if ( V_74 < 0 || V_74 >= V_100 ) {
F_24 ( L_15 , V_74 ) ;
return L_8 ;
} else
return V_101 [ V_74 ] . V_14 ;
}
const char *
F_72 ( int V_74 )
{
if ( V_74 < 0 || V_74 >= V_100 )
return NULL ;
else
return V_101 [ V_74 ] . V_105 ;
}
int
F_60 ( const char * V_105 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_100 ; V_74 ++ ) {
if ( V_101 [ V_74 ] . V_105 != NULL &&
strcmp ( V_105 , V_101 [ V_74 ] . V_105 ) == 0 )
return V_74 ;
}
if ( strcmp ( V_105 , L_16 ) == 0 )
return V_75 ;
return - 1 ;
}
static T_1 *
F_73 ( int V_74 , T_1 * V_1 ,
T_1 * V_3 )
{
T_2 * * V_15 , * * V_16 ;
T_2 * V_2 ;
V_1 = F_1 ( V_1 ,
V_101 [ V_74 ] . V_107 ,
V_3 ) ;
if ( V_101 [ V_74 ] . V_108 != NULL ) {
V_15 = F_14 ( V_101 [ V_74 ] . V_108 ,
L_2 , 0 ) ;
for ( V_16 = V_15 ; * V_16 != NULL ;
V_16 ++ ) {
V_2 = * V_16 ;
V_1 = F_1 ( V_1 , V_2 ,
V_3 ) ;
}
F_15 ( V_15 ) ;
}
return V_1 ;
}
T_1 *
F_74 ( int V_74 , T_4 V_129 )
{
T_1 * V_3 ;
T_1 * V_1 ;
if ( V_74 < 0 || V_74 >= V_100 )
return NULL ;
if ( V_101 [ V_74 ] . V_107 == NULL )
return NULL ;
V_1 = NULL ;
if ( V_129 )
V_3 = F_17 () ;
else
V_3 = NULL ;
V_1 = F_73 ( V_74 , V_1 ,
V_3 ) ;
F_18 ( V_3 ) ;
return V_1 ;
}
void
F_75 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; V_2 != NULL ;
V_2 = F_4 ( V_2 ) ) {
F_33 ( V_2 -> V_5 ) ;
}
F_18 ( V_1 ) ;
}
const char *
F_76 ( int V_74 )
{
if ( V_74 < 0 || V_74 >= V_100 )
return NULL ;
else
return V_101 [ V_74 ] . V_107 ;
}
T_4
F_67 ( int V_74 )
{
if ( V_74 < 0 || V_74 >= V_100
|| V_101 [ V_74 ] . V_113 == NULL )
return FALSE ;
return TRUE ;
}
T_4
F_77 ( int V_74 )
{
if ( V_74 < 0 || V_74 >= V_100
|| V_101 [ V_74 ] . V_109 )
return FALSE ;
return TRUE ;
}
T_4
F_77 ( int V_74 V_130 )
{
return FALSE ;
}
T_4
F_78 ( int V_74 )
{
if ( V_74 < 0 || V_74 >= V_100
|| V_101 [ V_74 ] . V_110 == FALSE )
return FALSE ;
return TRUE ;
}
T_4
F_68 ( int V_74 , T_9 V_131 )
{
T_9 V_111 ;
if ( V_74 < 0 || V_74 >= V_100 )
return FALSE ;
V_111 = V_101 [ V_74 ] . V_111 ;
if ( ( V_131 & V_111 ) == V_131 )
return TRUE ;
return FALSE ;
}
static T_10 *
F_79 ( int V_74 , int V_116 , int V_132 , T_4 V_133 ,
T_11 * V_134 , T_12 * V_135 ,
T_13 * V_136 , int * V_34 )
{
T_10 * V_137 ;
V_61 V_77 , * V_138 ;
if ( ! F_80 ( V_74 , V_116 , V_133 , V_34 ) )
return NULL ;
V_137 = F_81 ( V_74 , V_116 , V_132 , V_133 , V_34 ) ;
if ( V_137 == NULL )
return NULL ;
V_137 -> V_134 = V_134 ;
V_137 -> V_136 = V_136 ;
if ( ( V_135 != NULL ) && ( V_135 -> V_60 -> V_12 > 0 ) ) {
T_3 V_139 ;
V_137 -> V_60 = F_7 ( FALSE , FALSE , sizeof( V_61 ) ) ;
for ( V_139 = 0 ; V_139 < V_135 -> V_60 -> V_12 ; V_139 ++ ) {
V_138 = & F_64 ( V_135 -> V_60 , V_61 , V_139 ) ;
if ( ( V_116 != V_117 ) && ( V_116 != V_138 -> V_78 ) ) {
memcpy ( & V_77 , V_138 , sizeof( V_61 ) ) ;
V_77 . V_78 = V_116 ;
V_77 . V_83 = F_55 ( V_116 ) ;
F_10 ( V_137 -> V_60 , V_77 ) ;
} else {
F_10 ( V_137 -> V_60 , * V_138 ) ;
}
}
} else {
V_77 . V_78 = V_116 ;
V_77 . V_79 = 1000000 ;
V_77 . V_83 = F_55 ( V_116 ) ;
V_77 . V_84 = V_132 ;
V_77 . V_86 = NULL ;
V_77 . V_87 = F_3 ( L_17 ) ;
V_77 . V_88 = NULL ;
V_77 . V_89 = 0 ;
V_77 . V_80 = 6 ;
V_77 . V_90 = NULL ;
V_77 . V_91 = 0 ;
V_77 . V_92 = NULL ;
V_77 . V_93 = NULL ;
V_77 . V_94 = - 1 ;
V_77 . V_95 = 0 ;
V_77 . V_96 = NULL ;
V_137 -> V_60 = F_7 ( FALSE , FALSE , sizeof( V_61 ) ) ;
F_10 ( V_137 -> V_60 , V_77 ) ;
}
return V_137 ;
}
T_10 *
F_82 ( const char * V_31 , int V_74 , int V_116 ,
int V_132 , T_4 V_133 , int * V_34 )
{
return F_83 ( V_31 , V_74 , V_116 , V_132 , V_133 , NULL , NULL , NULL , V_34 ) ;
}
T_10 *
F_83 ( const char * V_31 , int V_74 , int V_116 ,
int V_132 , T_4 V_133 , T_11 * V_134 , T_12 * V_135 ,
T_13 * V_136 , int * V_34 )
{
T_10 * V_137 ;
T_14 V_50 ;
V_137 = F_79 ( V_74 , V_116 , V_132 , V_133 ,
V_134 , V_135 , V_136 , V_34 ) ;
if ( V_137 == NULL )
return NULL ;
V_41 = V_48 ;
V_50 = F_84 ( V_137 , V_31 ) ;
if ( V_50 == NULL ) {
* V_34 = V_41 ;
F_33 ( V_137 ) ;
return NULL ;
}
V_137 -> V_50 = V_50 ;
if ( ! F_85 ( V_137 , V_74 , V_133 , V_34 ) ) {
F_86 ( V_137 ) ;
F_87 ( V_31 ) ;
F_33 ( V_137 ) ;
return NULL ;
}
return V_137 ;
}
T_10 *
F_88 ( char * * V_140 , const char * V_141 ,
int V_74 , int V_116 ,
int V_132 , T_4 V_133 , int * V_34 )
{
return F_89 ( V_140 , V_141 , V_74 , V_116 , V_132 , V_133 , NULL , NULL , NULL , V_34 ) ;
}
T_10 *
F_89 ( char * * V_140 , const char * V_141 ,
int V_74 , int V_116 ,
int V_132 , T_4 V_133 ,
T_11 * V_134 ,
T_12 * V_135 ,
T_13 * V_136 , int * V_34 )
{
int V_37 ;
char * V_142 ;
T_10 * V_137 ;
T_14 V_50 ;
* V_140 = NULL ;
V_137 = F_79 ( V_74 , V_116 , V_132 , V_133 ,
V_134 , V_135 , V_136 , V_34 ) ;
if ( V_137 == NULL )
return NULL ;
V_37 = F_90 ( & V_142 , V_141 ) ;
* V_140 = V_142 ;
V_41 = V_48 ;
V_50 = F_91 ( V_137 , V_37 ) ;
if ( V_50 == NULL ) {
* V_34 = V_41 ;
F_92 ( V_37 ) ;
F_33 ( V_137 ) ;
return NULL ;
}
V_137 -> V_50 = V_50 ;
if ( ! F_85 ( V_137 , V_74 , V_133 , V_34 ) ) {
F_86 ( V_137 ) ;
F_87 ( V_142 ) ;
F_33 ( V_137 ) ;
return NULL ;
}
return V_137 ;
}
T_10 *
F_93 ( int V_37 , int V_74 , int V_116 , int V_132 ,
T_4 V_133 , int * V_34 )
{
return F_94 ( V_37 , V_74 , V_116 , V_132 , V_133 , NULL , NULL , NULL , V_34 ) ;
}
T_10 *
F_94 ( int V_37 , int V_74 , int V_116 , int V_132 ,
T_4 V_133 , T_11 * V_134 , T_12 * V_135 ,
T_13 * V_136 , int * V_34 )
{
T_10 * V_137 ;
T_14 V_50 ;
V_137 = F_79 ( V_74 , V_116 , V_132 , V_133 ,
V_134 , V_135 , V_136 , V_34 ) ;
if ( V_137 == NULL )
return NULL ;
V_41 = V_48 ;
V_50 = F_91 ( V_137 , V_37 ) ;
if ( V_50 == NULL ) {
* V_34 = V_41 ;
F_33 ( V_137 ) ;
return NULL ;
}
V_137 -> V_50 = V_50 ;
if ( ! F_85 ( V_137 , V_74 , V_133 , V_34 ) ) {
F_86 ( V_137 ) ;
F_33 ( V_137 ) ;
return NULL ;
}
return V_137 ;
}
T_10 *
F_95 ( int V_74 , int V_116 , int V_132 ,
T_4 V_133 , int * V_34 )
{
return F_96 ( V_74 , V_116 , V_132 , V_133 , NULL , NULL , NULL , V_34 ) ;
}
T_10 *
F_96 ( int V_74 , int V_116 , int V_132 ,
T_4 V_133 , T_11 * V_134 ,
T_12 * V_135 ,
T_13 * V_136 , int * V_34 )
{
T_10 * V_137 ;
T_14 V_50 ;
V_137 = F_79 ( V_74 , V_116 , V_132 , V_133 ,
V_134 , V_135 , V_136 , V_34 ) ;
if ( V_137 == NULL )
return NULL ;
#ifdef F_43
if ( F_44 ( 1 , V_49 ) == - 1 ) {
* V_34 = V_41 ;
F_33 ( V_137 ) ;
return NULL ;
}
#endif
V_41 = V_48 ;
V_50 = F_91 ( V_137 , 1 ) ;
if ( V_50 == NULL ) {
* V_34 = V_41 ;
F_33 ( V_137 ) ;
return NULL ;
}
V_137 -> V_50 = V_50 ;
V_137 -> V_143 = TRUE ;
if ( ! F_85 ( V_137 , V_74 , V_133 , V_34 ) ) {
F_86 ( V_137 ) ;
F_33 ( V_137 ) ;
return NULL ;
}
return V_137 ;
}
static T_4
F_80 ( int V_74 , int V_116 , T_4 V_133 , int * V_34 )
{
if ( ! F_67 ( V_74 ) ) {
* V_34 = V_144 ;
return FALSE ;
}
* V_34 = ( * V_101 [ V_74 ] . V_112 ) ( V_116 ) ;
if ( * V_34 == V_120
&& V_101 [ V_74 ] . V_114 != NULL
&& V_101 [ V_74 ] . V_114 -> V_121 != NULL ) {
* V_34 = ( * V_101 [ V_74 ] . V_114 -> V_121 ) ( V_116 , V_101 [ V_74 ] . V_114 -> V_59 ) ;
}
if ( * V_34 != 0 )
return FALSE ;
if( V_133 && ! F_77 ( V_74 ) ) {
* V_34 = V_145 ;
return FALSE ;
}
return TRUE ;
}
static T_10 *
F_81 ( int V_74 , int V_116 , int V_132 , T_4 V_133 , int * V_34 )
{
T_10 * V_137 ;
V_137 = ( T_10 * ) F_41 ( sizeof ( T_10 ) ) ;
if ( V_137 == NULL ) {
* V_34 = V_41 ;
return NULL ;
}
V_137 -> V_74 = V_74 ;
V_137 -> V_132 = V_132 ;
V_137 -> V_116 = V_116 ;
V_137 -> V_133 = V_133 ;
V_137 -> V_59 = NULL ;
return V_137 ;
}
static T_4
F_85 ( T_10 * V_137 , int V_74 , T_4 V_133 , int * V_34 )
{
int V_37 ;
T_4 V_146 ;
if( V_133 ) {
V_146 = TRUE ;
} else {
V_37 = fileno ( ( V_147 * ) V_137 -> V_50 ) ;
if ( F_97 ( V_37 , 1 , V_148 ) == ( V_149 ) - 1 )
V_146 = TRUE ;
else {
F_97 ( V_37 , 0 , V_64 ) ;
V_146 = FALSE ;
}
}
if ( V_101 [ V_74 ] . V_109 && V_146 ) {
* V_34 = V_150 ;
return FALSE ;
}
if ( V_101 [ V_74 ] . V_114 )
V_137 -> V_59 = V_101 [ V_74 ] . V_114 -> V_59 ;
if ( ! ( * V_101 [ V_74 ] . V_113 ) ( V_137 , V_34 ) ) {
return FALSE ;
}
return TRUE ;
}
T_4
F_98 ( T_10 * V_137 , const struct V_151 * V_152 ,
const T_15 * V_153 , int * V_34 , T_2 * * V_35 )
{
* V_34 = 0 ;
* V_35 = NULL ;
return ( V_137 -> V_154 ) ( V_137 , V_152 , V_153 , V_34 , V_35 ) ;
}
void
F_99 ( T_10 * V_137 )
{
#ifdef F_100
if( V_137 -> V_133 ) {
F_101 ( ( V_155 ) V_137 -> V_50 ) ;
} else
#endif
{
fflush ( ( V_147 * ) V_137 -> V_50 ) ;
}
}
T_4
F_102 ( T_10 * V_137 , int * V_34 )
{
T_4 V_156 = TRUE ;
if ( V_137 -> V_157 != NULL ) {
if ( ! ( V_137 -> V_157 ) ( V_137 , V_34 ) )
V_156 = FALSE ;
}
V_41 = V_158 ;
if ( F_86 ( V_137 ) == V_159 ) {
if ( V_156 ) {
if ( V_34 != NULL )
* V_34 = V_41 ;
}
V_156 = FALSE ;
}
if ( V_137 -> V_58 != NULL )
F_33 ( V_137 -> V_58 ) ;
F_33 ( V_137 ) ;
return V_156 ;
}
T_16
F_103 ( T_10 * V_137 )
{
return V_137 -> V_160 ;
}
void
F_104 ( T_10 * V_137 , T_16 V_160 )
{
V_137 -> V_160 = V_160 ;
}
T_4
F_105 ( T_10 * V_137 , T_17 * V_161 )
{
if ( ! V_137 || V_137 -> V_74 < 0 || V_137 -> V_74 >= V_100
|| V_101 [ V_137 -> V_74 ] . V_110 == FALSE )
return FALSE ;
V_137 -> V_161 = V_161 ;
return TRUE ;
}
static T_14
F_84 ( T_10 * V_137 , const char * V_31 )
{
if( V_137 -> V_133 ) {
return F_106 ( V_31 ) ;
} else {
return F_107 ( V_31 , L_18 ) ;
}
}
static T_14
F_84 ( T_10 * V_137 V_130 , const char * V_31 )
{
return F_107 ( V_31 , L_18 ) ;
}
static T_14
F_91 ( T_10 * V_137 , int V_37 )
{
if( V_137 -> V_133 ) {
return F_108 ( V_37 ) ;
} else {
return fdopen ( V_37 , L_18 ) ;
}
}
static T_14
F_91 ( T_10 * V_137 V_130 , int V_37 )
{
return fdopen ( V_37 , L_18 ) ;
}
T_4
F_109 ( T_10 * V_137 , const void * V_162 , T_5 V_163 , int * V_34 )
{
T_5 V_164 ;
#ifdef F_100
if ( V_137 -> V_133 ) {
V_164 = F_110 ( ( V_155 ) V_137 -> V_50 , V_162 , ( unsigned int ) V_163 ) ;
if ( V_164 == 0 ) {
* V_34 = F_111 ( ( V_155 ) V_137 -> V_50 ) ;
return FALSE ;
}
} else
#endif
{
V_41 = V_165 ;
V_164 = fwrite ( V_162 , 1 , V_163 , ( V_147 * ) V_137 -> V_50 ) ;
if ( V_164 != V_163 ) {
if ( ferror ( ( V_147 * ) V_137 -> V_50 ) )
* V_34 = V_41 ;
else
* V_34 = V_166 ;
return FALSE ;
}
}
return TRUE ;
}
static int
F_86 ( T_10 * V_137 )
{
#ifdef F_100
if( V_137 -> V_133 ) {
return F_112 ( ( V_155 ) V_137 -> V_50 , V_137 -> V_143 ) ;
} else
#endif
{
return V_137 -> V_143 ? fflush ( ( V_147 * ) V_137 -> V_50 ) : fclose ( ( V_147 * ) V_137 -> V_50 ) ;
}
}
T_16
F_113 ( T_10 * V_137 , T_16 V_167 , int V_168 , int * V_34 )
{
#ifdef F_100
if( V_137 -> V_133 ) {
* V_34 = V_169 ;
return - 1 ;
} else
#endif
{
if ( - 1 == fseek ( ( V_147 * ) V_137 -> V_50 , ( long ) V_167 , V_168 ) ) {
* V_34 = V_41 ;
return - 1 ;
} else
{
return 0 ;
}
}
}
T_16
F_114 ( T_10 * V_137 , int * V_34 )
{
T_16 V_170 ;
#ifdef F_100
if( V_137 -> V_133 ) {
* V_34 = V_169 ;
return - 1 ;
} else
#endif
{
if ( - 1 == ( V_170 = ftell ( ( V_147 * ) V_137 -> V_50 ) ) ) {
* V_34 = V_41 ;
return - 1 ;
} else
{
return V_170 ;
}
}
}
