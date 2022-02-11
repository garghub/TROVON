static void
F_1 ( void ) {
T_1 * V_1 , * V_2 ;
if ( F_2 () ) {
V_1 = F_3 () ;
V_2 = F_4 () ;
fprintf ( V_3 , L_1 ,
V_1 , V_2 ) ;
F_5 ( V_1 ) ;
F_5 ( V_2 ) ;
if ( F_6 () ) {
fprintf ( V_3 , L_2 ) ;
}
fprintf ( V_3 , L_3 ) ;
}
}
int
main ( int V_4 , char * V_5 [] )
{
T_2 * V_6 ;
T_2 * V_7 ;
char * V_8 ;
char * V_9 = NULL ;
T_3 * V_10 ;
int V_11 = V_12 ;
F_7 ( V_13 , V_14 ) ;
F_8 () ;
F_9 () ;
F_1 () ;
V_8 = F_10 ( V_5 [ 0 ] , main ) ;
if ( V_8 != NULL ) {
fprintf ( V_3 , L_4 ,
V_8 ) ;
}
V_6 = F_11 ( NULL , V_15 ) ;
V_7 = F_12 ( V_16 ) ;
F_13 ( L_5
L_3
L_6
L_3
L_6 ,
F_14 () , V_6 -> V_17 , V_7 -> V_17 ) ;
F_15 ( V_6 , TRUE ) ;
F_15 ( V_7 , TRUE ) ;
if ( F_16 ( V_4 , V_5 ) < 0 )
{
printf ( L_7 ) ;
V_11 = V_18 ;
goto V_19;
}
F_17 ( V_13 , V_13 ,
V_20 , V_21 ,
V_22 ) ;
F_18 ( V_23 ) ;
F_19 ( V_24 ) ;
F_20 ( V_25 ) ;
F_21 () ;
#ifdef F_22
F_23 () ;
F_24 ( V_26 ) ;
F_25 () ;
#endif
F_26 () ;
if ( ! F_27 ( V_27 , V_28 , NULL ,
NULL ) ) {
V_11 = V_29 ;
goto V_19;
}
V_10 = F_28 () ;
F_29 ( V_30 ) ;
if ( ! F_30 ( & V_9 , NULL ) ) {
fprintf ( V_3 , L_8 , V_9 ) ;
F_5 ( V_9 ) ;
}
F_31 ( & V_31 ) ;
F_32 () ;
F_33 ( & V_31 . V_32 , V_10 -> V_33 , TRUE ) ;
V_11 = F_34 () ;
V_19:
F_35 ( & V_31 . V_32 ) ;
F_36 () ;
F_37 () ;
F_38 () ;
#ifdef F_22
F_39 () ;
#endif
return V_11 ;
}
static const T_4 *
F_40 ( void * V_34 , T_5 V_35 )
{
T_6 * V_36 = ( T_6 * ) V_34 ;
if ( V_37 && V_37 -> V_38 == V_35 )
return & V_37 -> V_39 ;
if ( V_40 && V_40 -> V_38 == V_35 )
return & V_40 -> V_39 ;
if ( V_41 && V_41 -> V_38 == V_35 )
return & V_41 -> V_39 ;
if ( V_36 -> V_42 ) {
T_7 * V_43 = F_41 ( V_36 -> V_42 , V_35 ) ;
return ( V_43 ) ? & V_43 -> V_39 : NULL ;
}
return NULL ;
}
static T_8 *
F_42 ( T_6 * V_36 )
{
T_8 * V_44 = F_43 () ;
V_44 -> V_34 = V_36 ;
V_44 -> V_45 = F_40 ;
V_44 -> V_46 = V_47 ;
V_44 -> V_48 = V_49 ;
V_44 -> V_50 = NULL ;
return V_44 ;
}
static T_9
F_44 ( T_6 * V_36 , T_10 * V_51 ,
T_11 V_52 , struct V_53 * V_54 ,
const T_12 * V_55 )
{
T_7 V_56 ;
T_5 V_57 ;
T_9 V_58 ;
V_57 = V_36 -> V_59 + 1 ;
V_58 = TRUE ;
F_45 ( & V_56 , V_57 , V_54 , V_52 , V_60 ) ;
if ( V_51 ) {
if ( V_61 . V_62 || V_61 . V_63 ||
V_61 . V_64 )
F_46 () ;
if ( V_36 -> V_65 )
F_47 ( V_51 , V_36 -> V_65 ) ;
if ( V_36 -> V_66 )
F_47 ( V_51 , V_36 -> V_66 ) ;
F_48 ( V_51 ) ;
F_49 ( & V_56 , & V_36 -> V_67 ,
& V_37 , V_40 ) ;
if ( V_37 == & V_56 ) {
V_68 = V_56 ;
V_37 = & V_68 ;
}
F_50 ( V_51 , V_36 -> V_69 , V_54 , F_51 ( & V_56 , V_55 ) , & V_56 , NULL ) ;
if ( V_36 -> V_65 )
V_58 = F_52 ( V_36 -> V_65 , V_51 ) ;
}
if ( V_58 ) {
F_53 ( & V_56 , & V_60 ) ;
V_41 = V_40 = F_54 ( V_36 -> V_42 , & V_56 ) ;
if ( V_51 && V_36 -> V_66 ) {
if ( F_52 ( V_36 -> V_66 , V_51 ) ) {
F_55 ( V_51 -> V_70 . V_71 , V_72 , V_36 -> V_42 ) ;
}
}
V_36 -> V_59 ++ ;
} else {
F_56 ( & V_56 ) ;
}
if ( V_51 )
F_57 ( V_51 ) ;
return V_58 ;
}
static int
F_58 ( T_6 * V_36 , int V_73 , T_11 V_74 )
{
int V_75 ;
T_1 * V_76 = NULL ;
T_11 V_77 ;
T_10 * V_51 = NULL ;
{
V_36 -> V_42 = F_59 () ;
{
T_9 V_78 ;
V_78 =
( V_36 -> V_65 != NULL || V_36 -> V_66 != NULL || F_60 () ) ;
V_51 = F_61 ( V_36 -> V_44 , V_78 , FALSE ) ;
}
while ( F_62 ( V_36 -> V_79 , & V_75 , & V_76 , & V_77 ) ) {
if ( F_44 ( V_36 , V_51 , V_77 , F_63 ( V_36 -> V_79 ) ,
F_64 ( V_36 -> V_79 ) ) ) {
if ( ( -- V_73 == 0 ) || ( V_74 != 0 && V_77 >= V_74 ) ) {
V_75 = 0 ;
break;
}
}
}
if ( V_51 ) {
F_65 ( V_51 ) ;
V_51 = NULL ;
}
F_66 ( V_36 -> V_79 ) ;
F_67 () ;
V_40 = NULL ;
V_41 = NULL ;
}
if ( V_75 != 0 ) {
F_68 ( L_9 , V_36 -> V_80 , V_75 , V_76 ) ;
}
return V_75 ;
}
T_13
F_69 ( T_6 * V_36 , const char * V_81 , unsigned int type , T_9 V_82 , int * V_75 )
{
T_14 * V_79 ;
T_1 * V_76 ;
V_79 = F_70 ( V_81 , type , V_75 , & V_76 , TRUE ) ;
if ( V_79 == NULL )
goto V_83;
F_71 ( V_36 -> V_44 ) ;
V_36 -> V_44 = F_42 ( V_36 ) ;
V_36 -> V_79 = V_79 ;
V_36 -> V_84 = 0 ;
V_36 -> V_80 = F_72 ( V_81 ) ;
V_36 -> V_82 = V_82 ;
V_36 -> V_85 = FALSE ;
V_36 -> V_69 = F_73 ( V_36 -> V_79 ) ;
V_36 -> V_86 = type ;
V_36 -> V_59 = 0 ;
V_36 -> V_87 = FALSE ;
V_36 -> V_88 = 0 ;
V_36 -> V_89 = F_74 ( V_36 -> V_79 ) ;
F_75 ( & V_36 -> V_67 ) ;
V_37 = NULL ;
V_40 = NULL ;
V_41 = NULL ;
V_36 -> V_90 = V_91 ;
F_76 ( V_36 -> V_79 , V_92 ) ;
F_77 ( V_36 -> V_79 , ( V_93 ) V_94 ) ;
return V_95 ;
V_83:
F_78 ( L_9 , V_81 , * V_75 , V_76 ) ;
return V_96 ;
}
static void
V_13 ( const char * V_97 , T_15 V_98 )
{
fprintf ( V_3 , L_10 ) ;
vfprintf ( V_3 , V_97 , V_98 ) ;
fprintf ( V_3 , L_3 ) ;
}
static void
V_20 ( const char * V_80 , int V_75 , T_9 V_99 )
{
fprintf ( V_3 , L_10 ) ;
fprintf ( V_3 , F_79 ( V_75 , V_99 ) , V_80 ) ;
fprintf ( V_3 , L_3 ) ;
}
static void
V_21 ( const char * V_80 , int V_75 )
{
F_80 ( L_11 ,
V_80 , F_81 ( V_75 ) ) ;
}
static void
V_22 ( const char * V_80 , int V_75 )
{
F_80 ( L_12 ,
V_80 , F_81 ( V_75 ) ) ;
}
static void
V_14 ( const char * V_97 , T_15 V_98 )
{
vfprintf ( V_3 , V_97 , V_98 ) ;
fprintf ( V_3 , L_3 ) ;
}
T_13
F_82 ( const char * V_81 , unsigned int type , T_9 V_82 , int * V_75 )
{
return F_69 ( & V_31 , V_81 , type , V_82 , V_75 ) ;
}
int
F_83 ( void )
{
return F_58 ( & V_31 , 0 , 0 ) ;
}
int
F_84 ( unsigned int V_57 , void (* F_85)( T_16 * , T_17 * , struct V_100 * , const T_18 * , void * ) , int V_101 , int V_102 , int V_103 , void * V_34 )
{
T_7 * V_104 ;
T_19 * V_32 = ( V_102 ) ? & V_31 . V_32 : NULL ;
T_10 V_51 ;
T_9 V_78 ;
struct V_53 V_105 ;
T_20 V_106 ;
int V_75 ;
char * V_76 = NULL ;
V_104 = F_41 ( V_31 . V_42 , V_57 ) ;
if ( V_104 == NULL )
return - 1 ;
F_86 ( & V_105 ) ;
F_87 ( & V_106 , 1500 ) ;
if ( ! F_88 ( V_31 . V_79 , V_104 -> V_107 , & V_105 , & V_106 , & V_75 , & V_76 ) ) {
F_89 ( & V_106 ) ;
return - 1 ;
}
V_78 = ( V_103 ) || ( V_32 && F_90 ( V_32 ) ) ;
F_91 ( & V_51 , V_31 . V_44 , V_78 , V_103 ) ;
if ( V_32 )
F_92 ( & V_51 , V_32 ) ;
F_50 ( & V_51 , V_31 . V_69 , & V_105 , F_93 ( V_104 , & V_106 ) , V_104 , V_32 ) ;
if ( V_32 ) {
F_94 ( & V_51 , FALSE , TRUE ) ;
}
F_85 ( & V_51 . V_70 , V_103 ? V_51 . V_108 : NULL , V_32 , V_101 ? V_51 . V_70 . V_109 : NULL , V_34 ) ;
F_95 ( & V_51 ) ;
F_96 ( & V_105 ) ;
F_89 ( & V_106 ) ;
return 0 ;
}
int
F_97 ( int V_57 , T_19 * V_32 , T_9 V_110 )
{
T_7 * V_104 ;
T_10 V_51 ;
T_9 V_78 ;
struct V_53 V_105 ;
T_20 V_106 ;
int V_75 ;
char * V_76 = NULL ;
V_104 = F_41 ( V_31 . V_42 , V_57 ) ;
if ( V_104 == NULL ) {
F_98 ( V_32 , V_104 , FALSE , TRUE ) ;
return - 1 ;
}
F_86 ( & V_105 ) ;
F_87 ( & V_106 , 1500 ) ;
if ( ! F_88 ( V_31 . V_79 , V_104 -> V_107 , & V_105 , & V_106 , & V_75 , & V_76 ) ) {
F_98 ( V_32 , V_104 , FALSE , FALSE ) ;
F_89 ( & V_106 ) ;
return - 1 ;
}
V_78 = ( V_110 && F_99 () ) || ( V_32 && F_90 ( V_32 ) ) ;
F_91 ( & V_51 , V_31 . V_44 , V_78 , FALSE ) ;
if ( V_110 ) {
F_100 ( & V_51 ) ;
V_104 -> V_111 . V_112 = 1 ;
}
if ( V_32 )
F_92 ( & V_51 , V_32 ) ;
F_50 ( & V_51 , V_31 . V_69 , & V_105 , F_93 ( V_104 , & V_106 ) , V_104 , V_32 ) ;
if ( V_32 ) {
F_94 ( & V_51 , FALSE , TRUE ) ;
}
F_95 ( & V_51 ) ;
F_96 ( & V_105 ) ;
F_89 ( & V_106 ) ;
return 0 ;
}
int
F_101 ( void )
{
T_5 V_57 ;
T_7 * V_104 ;
T_20 V_106 ;
struct V_53 V_105 ;
int V_75 ;
char * V_76 = NULL ;
T_21 V_113 ;
T_9 V_78 ;
T_10 V_51 ;
T_19 * V_32 ;
V_113 = F_102 () ;
V_32 = ( V_113 & V_114 ) ? & V_31 . V_32 : NULL ;
V_78 =
( F_103 () || ( V_113 & V_115 ) ) ;
F_86 ( & V_105 ) ;
F_87 ( & V_106 , 1500 ) ;
F_91 ( & V_51 , V_31 . V_44 , V_78 , FALSE ) ;
F_104 () ;
for ( V_57 = 1 ; V_57 <= V_31 . V_59 ; V_57 ++ ) {
V_104 = F_41 ( V_31 . V_42 , V_57 ) ;
if ( ! F_88 ( V_31 . V_79 , V_104 -> V_107 , & V_105 , & V_106 , & V_75 , & V_76 ) )
break;
F_105 ( & V_51 , V_31 . V_69 , & V_105 , F_51 ( V_104 , F_106 ( & V_106 ) ) , V_104 , V_32 ) ;
F_57 ( & V_51 ) ;
}
F_96 ( & V_105 ) ;
F_89 ( & V_106 ) ;
F_95 ( & V_51 ) ;
F_107 ( TRUE ) ;
return 0 ;
}
int
F_108 ( const char * V_116 , T_22 * * V_117 )
{
T_23 * V_66 = NULL ;
T_5 V_57 ;
T_5 V_118 ;
T_20 V_106 ;
struct V_53 V_105 ;
int V_75 ;
char * V_76 = NULL ;
T_22 * V_119 ;
T_22 V_120 ;
T_10 V_51 ;
if ( ! F_109 ( V_116 , & V_66 , & V_76 ) ) {
F_5 ( V_76 ) ;
return - 1 ;
}
V_118 = V_31 . V_59 ;
F_86 ( & V_105 ) ;
F_87 ( & V_106 , 1500 ) ;
F_91 ( & V_51 , V_31 . V_44 , TRUE , FALSE ) ;
V_120 = 0 ;
V_119 = ( T_22 * ) F_110 ( 2 + ( V_118 / 8 ) ) ;
for ( V_57 = 1 ; V_57 <= V_118 ; V_57 ++ ) {
T_7 * V_104 = F_41 ( V_31 . V_42 , V_57 ) ;
if ( ( V_57 & 7 ) == 0 ) {
V_119 [ ( V_57 / 8 ) - 1 ] = V_120 ;
V_120 = 0 ;
}
if ( ! F_88 ( V_31 . V_79 , V_104 -> V_107 , & V_105 , & V_106 , & V_75 , & V_76 ) )
break;
F_47 ( & V_51 , V_66 ) ;
F_50 ( & V_51 , V_31 . V_69 , & V_105 , F_93 ( V_104 , & V_106 ) , V_104 , NULL ) ;
if ( F_52 ( V_66 , & V_51 ) )
V_120 |= ( 1 << ( V_57 % 8 ) ) ;
F_57 ( & V_51 ) ;
}
if ( ( V_57 & 7 ) == 0 )
V_57 -- ;
V_119 [ V_57 / 8 ] = V_120 ;
F_96 ( & V_105 ) ;
F_89 ( & V_106 ) ;
F_95 ( & V_51 ) ;
F_111 ( V_66 ) ;
* V_117 = V_119 ;
return V_57 ;
}
const char * F_112 ( void )
{
#ifdef F_113
return F_113 ;
#else
return V_121 ;
#endif
}
