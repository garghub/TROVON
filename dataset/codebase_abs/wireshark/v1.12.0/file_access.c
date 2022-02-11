static T_1 * F_1 ( T_1 * V_1 , const T_2 * V_2 ,
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
static void F_6 ( void ) {
if ( V_6 ) return;
V_6 = F_7 ( FALSE , TRUE , sizeof( struct V_7 ) ) ;
F_8 ( V_6 , V_8 , V_9 ) ;
V_10 = (struct V_7 * ) ( void * ) V_6 -> V_5 ;
}
void F_9 ( const struct V_7 * V_11 ) {
F_6 () ;
F_10 ( V_6 , * V_11 ) ;
V_10 = ( const struct V_7 * ) ( void * ) V_6 -> V_5 ;
}
int F_11 ( void )
{
return V_6 -> V_12 ;
}
const char * F_12 ( int V_13 )
{
return V_10 [ V_13 ] . V_14 ;
}
static T_1 * F_13 ( int V_13 ,
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
T_1 * F_16 ( T_3 V_13 )
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
T_1 * F_19 ( void )
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
static void F_20 ( void ) {
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
void F_22 ( void ) {
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
void F_23 ( struct V_23 * V_27 , const T_4 V_28 ) {
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
void F_28 ( const T_2 * V_14 ) {
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
T_4 F_25 ( const T_2 * V_14 ) {
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
unsigned int F_30 ( const char * V_14 )
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
static char * F_31 ( const char * V_30 )
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
static T_4 F_34 ( unsigned int V_17 , const char * V_2 )
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
T_6 * F_35 ( const char * V_31 , unsigned int type , int * V_34 , char * * V_35 ,
T_4 V_36 )
{
int V_37 ;
T_7 V_38 ;
T_6 * V_39 ;
unsigned int V_17 ;
T_4 V_40 = FALSE ;
T_2 * V_2 ;
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
case - 1 :
F_52 ( V_39 ) ;
return NULL ;
case 0 :
goto V_66;
case 1 :
goto V_67;
}
}
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ V_17 ] . V_59 ;
switch ( ( * V_19 [ V_17 ] . V_65 ) ( V_39 , V_34 , V_35 ) ) {
case - 1 :
F_52 ( V_39 ) ;
return NULL ;
case 0 :
break;
case 1 :
goto V_67;
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
case - 1 :
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
case 0 :
break;
case 1 :
F_33 ( V_2 ) ;
goto V_67;
}
}
}
for ( V_17 = V_21 ; V_17 < V_18 -> V_12 ; V_17 ++ ) {
if ( ! F_34 ( V_17 , V_2 ) ) {
if ( F_51 ( V_39 -> V_50 , 0 , V_64 , V_34 ) == - 1 ) {
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
}
V_39 -> V_59 = V_19 [ V_17 ] . V_59 ;
switch ( ( * V_19 [ V_17 ] . V_65 ) ( V_39 ,
V_34 , V_35 ) ) {
case - 1 :
F_33 ( V_2 ) ;
F_52 ( V_39 ) ;
return NULL ;
case 0 :
break;
case 1 :
F_33 ( V_2 ) ;
goto V_67;
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
case - 1 :
F_52 ( V_39 ) ;
return NULL ;
case 0 :
break;
case 1 :
goto V_67;
}
}
}
V_66:
F_52 ( V_39 ) ;
* V_34 = V_68 ;
return NULL ;
V_67:
V_39 -> V_69 = (struct V_70 * ) F_53 ( sizeof( struct V_70 ) ) ;
F_54 ( V_39 -> V_69 , 1500 ) ;
if( V_39 -> V_71 == V_72 ) {
V_61 V_73 ;
V_73 . V_74 = V_39 -> V_52 ;
V_73 . V_75 = 1000000 ;
V_73 . V_76 = F_55 ( V_39 -> V_52 ) ;
V_73 . V_77 = V_39 -> V_78 ;
V_73 . V_79 = NULL ;
V_73 . V_80 = NULL ;
V_73 . V_81 = NULL ;
V_73 . V_82 = 0 ;
V_73 . V_83 = 6 ;
V_73 . V_84 = NULL ;
V_73 . V_85 = 0 ;
V_73 . V_86 = NULL ;
V_73 . V_87 = NULL ;
V_73 . V_88 = - 1 ;
V_73 . V_89 = 0 ;
V_73 . V_90 = NULL ;
F_10 ( V_39 -> V_60 , V_73 ) ;
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
static void F_58 ( void ) {
if ( V_91 ) return;
V_91 = F_7 ( FALSE , TRUE , sizeof( struct V_92 ) ) ;
F_8 ( V_91 , V_93 , V_94 ) ;
V_95 = ( const struct V_92 * ) ( void * ) V_91 -> V_5 ;
}
int F_59 ( const struct V_92 * V_96 , const int V_97 ) {
struct V_92 * V_98 = NULL ;
F_58 () ;
if ( ! V_96 || ! V_96 -> V_14 || ! V_96 -> V_99 || V_97 > V_94 ) {
F_24 ( L_11 ) ;
return V_97 ;
}
if ( V_97 == V_100 ) {
if ( F_60 ( V_96 -> V_99 ) > - 1 ) {
F_24 ( L_12 ) ;
return V_97 ;
}
F_10 ( V_91 , * V_96 ) ;
V_95 = ( const struct V_92 * ) ( void * ) V_91 -> V_5 ;
return V_94 ++ ;
}
if ( ! V_95 [ V_97 ] . V_99 || strcmp ( V_95 [ V_97 ] . V_99 , V_96 -> V_99 ) != 0 ) {
F_24 ( L_13 ) ;
return V_97 ;
}
V_98 = (struct V_92 * ) ( & V_95 [ V_97 ] ) ;
V_98 -> V_101 = V_96 -> V_101 ;
V_98 -> V_102 = V_96 -> V_102 ;
V_98 -> V_103 = V_96 -> V_103 ;
V_98 -> V_104 = V_96 -> V_104 ;
V_98 -> V_105 = V_96 -> V_105 ;
V_98 -> V_106 = V_96 -> V_106 ;
V_98 -> V_107 = V_96 -> V_107 ;
V_98 -> V_108 = V_96 -> V_108 ;
return V_97 ;
}
void F_61 ( const int V_97 ) {
struct V_92 * V_98 = NULL ;
if ( V_97 < 0 || V_97 >= V_94 ) {
F_24 ( L_14 ) ;
return;
}
V_98 = (struct V_92 * ) ( & V_95 [ V_97 ] ) ;
V_98 -> V_101 = NULL ;
V_98 -> V_102 = NULL ;
V_98 -> V_103 = FALSE ;
V_98 -> V_104 = FALSE ;
V_98 -> V_105 = 0 ;
V_98 -> V_106 = NULL ;
V_98 -> V_107 = NULL ;
V_98 -> V_108 = NULL ;
}
int F_62 ( void )
{
return V_94 ;
}
int
F_63 ( const T_8 * V_109 )
{
int V_110 ;
V_110 = V_111 ;
if ( V_109 -> V_12 == 1 ) {
V_110 = F_64 ( V_109 , V_112 , 0 ) ;
}
return V_110 ;
}
static T_4
F_65 ( int V_113 , int V_110 )
{
int V_63 = 0 ;
if ( V_113 < 0 || V_113 >= V_94
|| V_95 [ V_113 ] . V_106 == NULL )
return FALSE ;
V_63 = ( * V_95 [ V_113 ] . V_106 ) ( V_110 ) ;
if ( V_63 != 0 ) {
if ( V_63 == V_114
&& V_95 [ V_113 ] . V_108 != NULL
&& V_95 [ V_113 ] . V_108 -> V_115 != NULL ) {
V_63 = ( * V_95 [ V_113 ] . V_108 -> V_115 ) ( V_110 , V_95 [ V_113 ] . V_108 -> V_59 ) ;
}
if ( V_63 != 0 )
return FALSE ;
}
return TRUE ;
}
static T_4
F_66 ( int V_116 , const T_8 * V_109 ,
T_9 V_117 )
{
T_3 V_17 ;
if ( ! F_67 ( V_116 ) ) {
return FALSE ;
}
if ( ! F_68 ( V_116 , V_117 ) ) {
return FALSE ;
}
if ( ! F_65 ( V_116 , F_63 ( V_109 ) ) ) {
return FALSE ;
}
for ( V_17 = 0 ; V_17 < V_109 -> V_12 ; V_17 ++ ) {
if ( ! F_65 ( V_116 ,
F_64 ( V_109 , int , V_17 ) ) ) {
return FALSE ;
}
}
return TRUE ;
}
T_4
F_69 ( const T_8 * V_109 , T_9 V_117 )
{
int V_116 ;
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ ) {
if ( F_66 ( V_116 , V_109 , V_117 ) ) {
return TRUE ;
}
}
return FALSE ;
}
T_8 *
F_70 ( int V_71 ,
const T_8 * V_109 , T_9 V_117 )
{
T_8 * V_119 ;
int V_116 ;
int V_120 = - 1 ;
int V_121 = - 1 ;
if ( F_66 ( V_71 , V_109 ,
V_117 ) ) {
V_120 = V_71 ;
} else {
V_120 = - 1 ;
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ ) {
if ( F_66 ( V_116 , V_109 ,
V_117 ) ) {
V_120 = V_116 ;
}
}
}
if ( V_120 == - 1 ) {
return NULL ;
}
V_119 = F_7 ( FALSE , FALSE , ( T_3 ) sizeof ( int ) ) ;
F_10 ( V_119 , V_120 ) ;
if ( V_120 == V_72 ) {
if ( F_66 ( V_122 , V_109 ,
V_117 ) )
V_121 = V_122 ;
} else if ( V_120 == V_122 ) {
if ( F_66 ( V_72 , V_109 ,
V_117 ) )
V_121 = V_72 ;
}
if ( V_121 != - 1 )
F_10 ( V_119 , V_121 ) ;
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ ) {
if ( V_116 == V_100 )
continue;
if ( V_116 == V_120 || V_116 == V_121 )
continue;
if ( F_66 ( V_116 , V_109 ,
V_117 ) ) {
F_10 ( V_119 , V_116 ) ;
}
}
return V_119 ;
}
const char * F_71 ( int V_71 )
{
if ( V_71 < 0 || V_71 >= V_94 ) {
F_24 ( L_15 , V_71 ) ;
return L_8 ;
} else
return V_95 [ V_71 ] . V_14 ;
}
const char * F_72 ( int V_71 )
{
if ( V_71 < 0 || V_71 >= V_94 )
return NULL ;
else
return V_95 [ V_71 ] . V_99 ;
}
int F_60 ( const char * V_99 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_94 ; V_71 ++ ) {
if ( V_95 [ V_71 ] . V_99 != NULL &&
strcmp ( V_99 , V_95 [ V_71 ] . V_99 ) == 0 )
return V_71 ;
}
if ( strcmp ( V_99 , L_16 ) == 0 )
return V_72 ;
return - 1 ;
}
static T_1 *
F_73 ( int V_71 , T_1 * V_1 ,
T_1 * V_3 )
{
T_2 * * V_15 , * * V_16 ;
T_2 * V_2 ;
V_1 = F_1 ( V_1 ,
V_95 [ V_71 ] . V_101 ,
V_3 ) ;
if ( V_95 [ V_71 ] . V_102 != NULL ) {
V_15 = F_14 ( V_95 [ V_71 ] . V_102 ,
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
T_1 * F_74 ( int V_71 , T_4 V_123 )
{
T_1 * V_3 ;
T_1 * V_1 ;
if ( V_71 < 0 || V_71 >= V_94 )
return NULL ;
if ( V_95 [ V_71 ] . V_101 == NULL )
return NULL ;
V_1 = NULL ;
if ( V_123 )
V_3 = F_17 () ;
else
V_3 = NULL ;
V_1 = F_73 ( V_71 , V_1 ,
V_3 ) ;
F_18 ( V_3 ) ;
return V_1 ;
}
void F_75 ( T_1 * V_1 )
{
T_1 * V_2 ;
for ( V_2 = V_1 ; V_2 != NULL ;
V_2 = F_4 ( V_2 ) ) {
F_33 ( V_2 -> V_5 ) ;
}
F_18 ( V_1 ) ;
}
const char * F_76 ( int V_71 )
{
if ( V_71 < 0 || V_71 >= V_94 )
return NULL ;
else
return V_95 [ V_71 ] . V_101 ;
}
T_4 F_67 ( int V_71 )
{
if ( V_71 < 0 || V_71 >= V_94
|| V_95 [ V_71 ] . V_107 == NULL )
return FALSE ;
return TRUE ;
}
T_4 F_77 ( int V_71 )
{
if ( V_71 < 0 || V_71 >= V_94
|| V_95 [ V_71 ] . V_103 )
return FALSE ;
return TRUE ;
}
T_4 F_77 ( int V_71 V_124 )
{
return FALSE ;
}
T_4 F_78 ( int V_71 )
{
if ( V_71 < 0 || V_71 >= V_94
|| V_95 [ V_71 ] . V_104 == FALSE )
return FALSE ;
return TRUE ;
}
T_4 F_68 ( int V_71 , T_9 V_125 )
{
T_9 V_105 ;
if ( V_71 < 0 || V_71 >= V_94 )
return FALSE ;
V_105 = V_95 [ V_71 ] . V_105 ;
if ( ( V_125 & V_105 ) == V_125 )
return TRUE ;
return FALSE ;
}
T_10 * F_79 ( const char * V_31 , int V_71 , int V_110 ,
int V_126 , T_4 V_127 , int * V_34 )
{
return F_80 ( V_31 , V_71 , V_110 , V_126 , V_127 , NULL , NULL , V_34 ) ;
}
static T_10 *
F_81 ( int V_71 , int V_110 , int V_126 , T_4 V_127 ,
T_11 * V_128 , T_12 * V_129 , int * V_34 )
{
T_10 * V_130 ;
V_130 = F_82 ( V_71 , V_110 , V_126 , V_127 , V_34 ) ;
if ( V_130 == NULL )
return NULL ;
V_130 -> V_128 = V_128 ;
if ( ( V_129 != NULL ) && ( V_129 -> V_60 -> V_12 > 0 ) ) {
V_130 -> V_60 = V_129 -> V_60 ;
} else {
V_61 V_73 ;
V_73 . V_74 = V_110 ;
V_73 . V_75 = 1000000 ;
V_73 . V_76 = F_55 ( V_110 ) ;
V_73 . V_77 = V_126 ;
V_73 . V_79 = NULL ;
V_73 . V_80 = F_3 ( L_17 ) ;
V_73 . V_81 = NULL ;
V_73 . V_82 = 0 ;
V_73 . V_83 = 6 ;
V_73 . V_84 = NULL ;
V_73 . V_85 = 0 ;
V_73 . V_86 = NULL ;
V_73 . V_87 = NULL ;
V_73 . V_88 = - 1 ;
V_73 . V_89 = 0 ;
V_73 . V_90 = NULL ;
V_130 -> V_60 = F_7 ( FALSE , FALSE , sizeof( V_61 ) ) ;
F_10 ( V_130 -> V_60 , V_73 ) ;
}
return V_130 ;
}
T_10 * F_80 ( const char * V_31 , int V_71 , int V_110 ,
int V_126 , T_4 V_127 , T_11 * V_128 , T_12 * V_129 , int * V_34 )
{
T_10 * V_130 ;
T_13 V_50 ;
if ( ! F_83 ( V_71 , V_110 , V_127 , V_34 ) )
return NULL ;
V_130 = F_81 ( V_71 , V_110 , V_126 , V_127 ,
V_128 , V_129 , V_34 ) ;
if ( V_130 == NULL )
return NULL ;
if ( strcmp ( V_31 , L_10 ) == 0 ) {
if ( V_127 ) {
* V_34 = V_131 ;
F_33 ( V_130 ) ;
return NULL ;
}
#ifdef F_43
if ( F_44 ( fileno ( stdout ) , V_49 ) == - 1 ) {
* V_34 = V_41 ;
F_33 ( V_130 ) ;
return NULL ;
}
#endif
V_130 -> V_50 = stdout ;
} else {
V_41 = V_48 ;
V_50 = F_84 ( V_130 , V_31 ) ;
if ( V_50 == NULL ) {
* V_34 = V_41 ;
F_33 ( V_130 ) ;
return NULL ;
}
V_130 -> V_50 = V_50 ;
}
if ( ! F_85 ( V_130 , V_71 , V_127 , V_34 ) ) {
if ( V_130 -> V_50 != stdout ) {
F_86 ( V_130 ) ;
F_87 ( V_31 ) ;
}
F_33 ( V_130 ) ;
return NULL ;
}
return V_130 ;
}
T_10 * F_88 ( int V_37 , int V_71 , int V_110 , int V_126 ,
T_4 V_127 , int * V_34 )
{
return F_89 ( V_37 , V_71 , V_110 , V_126 , V_127 , NULL , NULL , V_34 ) ;
}
T_10 * F_89 ( int V_37 , int V_71 , int V_110 , int V_126 ,
T_4 V_127 , T_11 * V_128 , T_12 * V_129 , int * V_34 )
{
T_10 * V_130 ;
T_13 V_50 ;
if ( ! F_83 ( V_71 , V_110 , V_127 , V_34 ) )
return NULL ;
V_130 = F_81 ( V_71 , V_110 , V_126 , V_127 ,
V_128 , V_129 , V_34 ) ;
if ( V_130 == NULL )
return NULL ;
#ifdef F_43
if ( V_37 == 1 ) {
if ( F_44 ( fileno ( stdout ) , V_49 ) == - 1 ) {
* V_34 = V_41 ;
F_33 ( V_130 ) ;
return NULL ;
}
}
#endif
V_41 = V_48 ;
V_50 = F_90 ( V_130 , V_37 ) ;
if ( V_50 == NULL ) {
* V_34 = V_41 ;
F_33 ( V_130 ) ;
return NULL ;
}
V_130 -> V_50 = V_50 ;
if ( ! F_85 ( V_130 , V_71 , V_127 , V_34 ) ) {
F_86 ( V_130 ) ;
F_33 ( V_130 ) ;
return NULL ;
}
return V_130 ;
}
static T_4 F_83 ( int V_71 , int V_110 , T_4 V_127 , int * V_34 )
{
if ( ! F_67 ( V_71 ) ) {
* V_34 = V_132 ;
return FALSE ;
}
* V_34 = ( * V_95 [ V_71 ] . V_106 ) ( V_110 ) ;
if ( * V_34 == V_114
&& V_95 [ V_71 ] . V_108 != NULL
&& V_95 [ V_71 ] . V_108 -> V_115 != NULL ) {
* V_34 = ( * V_95 [ V_71 ] . V_108 -> V_115 ) ( V_110 , V_95 [ V_71 ] . V_108 -> V_59 ) ;
}
if ( * V_34 != 0 )
return FALSE ;
if( V_127 && ! F_77 ( V_71 ) ) {
* V_34 = V_133 ;
return FALSE ;
}
return TRUE ;
}
static T_10 * F_82 ( int V_71 , int V_110 , int V_126 ,
T_4 V_127 , int * V_34 )
{
T_10 * V_130 ;
V_130 = ( T_10 * ) F_41 ( sizeof ( T_10 ) ) ;
if ( V_130 == NULL ) {
* V_34 = V_41 ;
return NULL ;
}
V_130 -> V_71 = V_71 ;
V_130 -> V_126 = V_126 ;
V_130 -> V_110 = V_110 ;
V_130 -> V_127 = V_127 ;
V_130 -> V_59 = NULL ;
return V_130 ;
}
static T_4 F_85 ( T_10 * V_130 , int V_71 , T_4 V_127 , int * V_34 )
{
int V_37 ;
T_4 V_134 ;
if( V_127 ) {
V_134 = TRUE ;
} else {
V_37 = fileno ( ( V_135 * ) V_130 -> V_50 ) ;
if ( F_91 ( V_37 , 1 , V_136 ) == - 1 )
V_134 = TRUE ;
else {
F_91 ( V_37 , 0 , V_64 ) ;
V_134 = FALSE ;
}
}
if ( V_95 [ V_71 ] . V_103 && V_134 ) {
* V_34 = V_137 ;
return FALSE ;
}
if ( V_95 [ V_71 ] . V_108 )
V_130 -> V_59 = V_95 [ V_71 ] . V_108 -> V_59 ;
if ( ! ( * V_95 [ V_71 ] . V_107 ) ( V_130 , V_34 ) ) {
return FALSE ;
}
return TRUE ;
}
T_4 F_92 ( T_10 * V_130 , const struct V_138 * V_139 ,
const T_14 * V_140 , int * V_34 )
{
return ( V_130 -> V_141 ) ( V_130 , V_139 , V_140 , V_34 ) ;
}
void F_93 ( T_10 * V_130 )
{
#ifdef F_94
if( V_130 -> V_127 ) {
F_95 ( ( V_142 ) V_130 -> V_50 ) ;
} else
#endif
{
fflush ( ( V_135 * ) V_130 -> V_50 ) ;
}
}
T_4 F_96 ( T_10 * V_130 , int * V_34 )
{
T_4 V_143 = TRUE ;
if ( V_130 -> V_55 != NULL ) {
if ( ! ( V_130 -> V_55 ) ( V_130 , V_34 ) )
V_143 = FALSE ;
}
V_41 = V_144 ;
if ( V_130 -> V_50 != stdout ) {
if ( F_86 ( V_130 ) == V_145 ) {
if ( V_143 ) {
if ( V_34 != NULL )
* V_34 = V_41 ;
}
V_143 = FALSE ;
}
} else {
F_93 ( V_130 ) ;
}
if ( V_130 -> V_58 != NULL )
F_33 ( V_130 -> V_58 ) ;
F_33 ( V_130 ) ;
return V_143 ;
}
T_15 F_97 ( T_10 * V_130 )
{
return V_130 -> V_146 ;
}
void F_98 ( T_10 * V_130 , T_15 V_146 )
{
V_130 -> V_146 = V_146 ;
}
T_4 F_99 ( T_10 * V_130 , T_16 * V_147 )
{
if ( ! V_130 || V_130 -> V_71 < 0 || V_130 -> V_71 >= V_94
|| V_95 [ V_130 -> V_71 ] . V_104 == FALSE )
return FALSE ;
V_130 -> V_147 = V_147 ;
return TRUE ;
}
static T_13 F_84 ( T_10 * V_130 , const char * V_31 )
{
if( V_130 -> V_127 ) {
return F_100 ( V_31 ) ;
} else {
return F_101 ( V_31 , L_18 ) ;
}
}
static T_13 F_84 ( T_10 * V_130 V_124 , const char * V_31 )
{
return F_101 ( V_31 , L_18 ) ;
}
static T_13 F_90 ( T_10 * V_130 , int V_37 )
{
if( V_130 -> V_127 ) {
return F_102 ( V_37 ) ;
} else {
return fdopen ( V_37 , L_18 ) ;
}
}
static T_13 F_90 ( T_10 * V_130 V_124 , int V_37 )
{
return fdopen ( V_37 , L_18 ) ;
}
T_4 F_103 ( T_10 * V_130 , const void * V_148 , T_5 V_149 ,
int * V_34 )
{
T_5 V_150 ;
#ifdef F_94
if ( V_130 -> V_127 ) {
V_150 = F_104 ( ( V_142 ) V_130 -> V_50 , V_148 , ( unsigned ) V_149 ) ;
if ( V_150 == 0 ) {
* V_34 = F_105 ( ( V_142 ) V_130 -> V_50 ) ;
return FALSE ;
}
} else
#endif
{
V_150 = fwrite ( V_148 , 1 , V_149 , ( V_135 * ) V_130 -> V_50 ) ;
if ( V_150 != V_149 ) {
if ( ferror ( ( V_135 * ) V_130 -> V_50 ) )
* V_34 = V_41 ;
else
* V_34 = V_151 ;
return FALSE ;
}
}
return TRUE ;
}
static int F_86 ( T_10 * V_130 )
{
#ifdef F_94
if( V_130 -> V_127 ) {
return F_106 ( ( V_142 ) V_130 -> V_50 ) ;
} else
#endif
{
return fclose ( ( V_135 * ) V_130 -> V_50 ) ;
}
}
T_15 F_107 ( T_10 * V_130 , T_15 V_152 , int V_153 , int * V_34 )
{
#ifdef F_94
if( V_130 -> V_127 ) {
* V_34 = V_154 ;
return - 1 ;
} else
#endif
{
if ( - 1 == fseek ( ( V_135 * ) V_130 -> V_50 , ( long ) V_152 , V_153 ) ) {
* V_34 = V_41 ;
return - 1 ;
} else
{
return 0 ;
}
}
}
T_15 F_108 ( T_10 * V_130 , int * V_34 )
{
T_15 V_155 ;
#ifdef F_94
if( V_130 -> V_127 ) {
* V_34 = V_154 ;
return - 1 ;
} else
#endif
{
if ( - 1 == ( V_155 = ftell ( ( V_135 * ) V_130 -> V_50 ) ) ) {
* V_34 = V_41 ;
return - 1 ;
} else
{
return V_155 ;
}
}
}
