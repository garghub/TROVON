static int F_1 ( T_1 * V_1 )
{
if ( ! F_2 ( V_1 , V_2 )
|| ! F_3 ( V_1 , V_3 )
|| ! F_4 ( V_1 , V_4 )
#ifndef F_5
# ifndef F_6
|| ! F_7 ( V_1 , F_8 () )
# endif
# ifndef F_9
|| ! F_10 ( V_1 , F_11 () )
# endif
# ifndef F_12
|| ! F_13 ( V_1 , F_14 () )
# endif
# ifndef F_15
|| ! F_16 ( V_1 , F_17 () )
# endif
|| ! F_18 ( V_1 , F_19 () )
# ifdef F_20
|| ! F_21 ( V_1 , V_5 )
# endif
# ifdef F_22
|| ! F_23 ( V_1 , V_6 )
# endif
#endif
#ifdef F_24
|| ! F_25 ( V_1 , V_7 )
#endif
#ifdef F_26
|| ! F_27 ()
|| ! F_28 ( V_1 , V_8 )
#endif
)
return 0 ;
return 1 ;
}
static T_1 * F_29 ( void )
{
T_1 * V_9 = F_30 () ;
if ( V_9 == NULL )
return NULL ;
if ( ! F_1 ( V_9 ) ) {
F_31 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
void F_32 ( void )
{
T_1 * V_10 = F_29 () ;
if ( ! V_10 )
return;
F_33 ( V_10 ) ;
F_31 ( V_10 ) ;
F_34 () ;
}
static int F_35 ( T_1 * V_1 , const char * V_11 )
{
if ( V_11 && ( strcmp ( V_11 , V_2 ) != 0 ) )
return 0 ;
if ( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
static int F_36 ( T_2 * V_12 , const unsigned char * V_13 ,
const unsigned char * V_14 , int V_15 )
{
# ifdef F_37
fprintf ( V_16 , L_1 ) ;
# endif
memcpy ( & F_38 ( V_12 ) -> V_13 [ 0 ] , V_13 , F_39 ( V_12 ) ) ;
F_40 ( & F_38 ( V_12 ) -> V_17 , F_39 ( V_12 ) ,
F_38 ( V_12 ) -> V_13 ) ;
return 1 ;
}
static int F_41 ( T_2 * V_12 , unsigned char * V_18 ,
const unsigned char * V_19 , T_3 V_20 )
{
# ifdef F_42
fprintf ( V_16 , L_2 ) ;
# endif
F_43 ( & F_38 ( V_12 ) -> V_17 , V_20 , V_19 , V_18 ) ;
return 1 ;
}
static const T_4 * F_44 ( void )
{
if ( V_21 == NULL ) {
T_4 * V_22 ;
if ( ( V_22 = F_45 ( V_23 , 1 , V_24 ) ) == NULL
|| ! F_46 ( V_22 , 0 )
|| ! F_47 ( V_22 , V_25 )
|| ! F_48 ( V_22 , F_36 )
|| ! F_49 ( V_22 , F_41 )
|| ! F_50 ( V_22 , sizeof( V_26 ) ) ) {
F_51 ( V_22 ) ;
V_22 = NULL ;
}
V_21 = V_22 ;
}
return V_21 ;
}
static void F_52 ( void )
{
F_51 ( V_21 ) ;
V_21 = NULL ;
}
static const T_4 * F_53 ( void )
{
if ( V_27 == NULL ) {
T_4 * V_22 ;
if ( ( V_22 = F_45 ( V_23 , 1 , 5 ) ) == NULL
|| ! F_46 ( V_22 , 0 )
|| ! F_47 ( V_22 , V_25 )
|| ! F_48 ( V_22 , F_36 )
|| ! F_49 ( V_22 , F_41 )
|| ! F_50 ( V_22 , sizeof( V_26 ) ) ) {
F_51 ( V_22 ) ;
V_22 = NULL ;
}
V_27 = V_22 ;
}
return V_27 ;
}
static void F_54 ( void )
{
F_51 ( V_27 ) ;
V_27 = NULL ;
}
static int F_55 ( const int * * V_28 )
{
static int V_29 [ 4 ] = { 0 , 0 , 0 , 0 } ;
static int V_30 = 0 ;
static int V_31 = 0 ;
if ( ! V_31 ) {
const T_4 * V_22 ;
if ( ( V_22 = F_44 () ) != NULL )
V_29 [ V_30 ++ ] = F_56 ( V_22 ) ;
if ( ( V_22 = F_53 () ) != NULL )
V_29 [ V_30 ++ ] = F_56 ( V_22 ) ;
V_29 [ V_30 ] = 0 ;
V_31 = 1 ;
}
* V_28 = V_29 ;
return V_30 ;
}
static int V_5 ( T_1 * V_1 , const T_4 * * V_22 ,
const int * * V_28 , int V_32 )
{
if ( ! V_22 ) {
return F_55 ( V_28 ) ;
}
if ( V_32 == V_23 )
* V_22 = F_44 () ;
else if ( V_32 == V_33 )
* V_22 = F_53 () ;
else {
# ifdef F_57
fprintf ( V_16 , L_3
L_4 , V_32 ) ;
# endif
* V_22 = NULL ;
return 0 ;
}
return 1 ;
}
static int F_58 ( T_5 * V_12 )
{
# ifdef F_59
fprintf ( V_16 , L_5 ) ;
# endif
return F_60 ( F_61 ( V_12 ) ) ;
}
static int F_62 ( T_5 * V_12 , const void * V_34 , T_3 V_35 )
{
# ifdef F_63
fprintf ( V_16 , L_6 ) ;
# endif
return F_64 ( F_61 ( V_12 ) , V_34 , V_35 ) ;
}
static int F_65 ( T_5 * V_12 , unsigned char * V_36 )
{
# ifdef F_66
fprintf ( V_16 , L_7 ) ;
# endif
return F_67 ( V_36 , F_61 ( V_12 ) ) ;
}
static const T_6 * F_68 ( void )
{
if ( V_37 == NULL ) {
T_6 * V_36 ;
if ( ( V_36 = F_69 ( V_38 , V_39 ) ) == NULL
|| ! F_70 ( V_36 , V_40 )
|| ! F_71 ( V_36 , V_41 )
|| ! F_72 ( V_36 ,
sizeof( T_6 * ) + sizeof( V_42 ) )
|| ! F_73 ( V_36 , 0 )
|| ! F_74 ( V_36 , F_58 )
|| ! F_75 ( V_36 , F_62 )
|| ! F_76 ( V_36 , F_65 ) ) {
F_77 ( V_36 ) ;
V_36 = NULL ;
}
V_37 = V_36 ;
}
return V_37 ;
}
static void F_78 ( void )
{
F_77 ( V_37 ) ;
V_37 = NULL ;
}
static int F_79 ( const int * * V_28 )
{
static int V_43 [ 2 ] = { 0 , 0 } ;
static int V_30 = 0 ;
static int V_31 = 0 ;
if ( ! V_31 ) {
const T_6 * V_36 ;
if ( ( V_36 = F_68 () ) != NULL )
V_43 [ V_30 ++ ] = F_80 ( V_36 ) ;
V_43 [ V_30 ] = 0 ;
V_31 = 1 ;
}
* V_28 = V_43 ;
return V_30 ;
}
static int V_6 ( T_1 * V_1 , const T_6 * * V_44 ,
const int * * V_28 , int V_32 )
{
if ( ! V_44 ) {
return F_79 ( V_28 ) ;
}
if ( V_32 == V_38 )
* V_44 = F_68 () ;
else {
# ifdef F_81
fprintf ( V_16 , L_8
L_4 , V_32 ) ;
# endif
* V_44 = NULL ;
return 0 ;
}
return 1 ;
}
static T_7 * V_7 ( T_1 * V_45 , const char * V_46 ,
T_8 * V_47 ,
void * V_48 )
{
T_9 * V_19 ;
T_7 * V_13 ;
fprintf ( V_16 , L_9 ,
V_46 ) ;
V_19 = F_82 ( V_46 , L_10 ) ;
if ( ! V_19 )
return NULL ;
V_13 = F_83 ( V_19 , NULL , 0 , NULL ) ;
F_84 ( V_19 ) ;
return V_13 ;
}
static int F_85 ( T_10 * V_12 )
{
T_11 * V_49 ;
V_49 = F_86 ( sizeof( * V_49 ) ) ;
if ( V_49 == NULL )
return 0 ;
V_49 -> V_50 . type = V_51 ;
V_49 -> V_12 = F_87 () ;
if ( V_49 -> V_12 == NULL ) {
F_88 ( V_49 ) ;
return 0 ;
}
F_89 ( V_12 , V_49 ) ;
F_90 ( V_12 , NULL , 0 ) ;
# ifdef F_91
fprintf ( V_16 , L_11 ) ;
# endif
return 1 ;
}
static int F_92 ( T_10 * V_52 , T_10 * V_53 )
{
T_11 * V_54 , * V_55 ;
if ( ! F_85 ( V_52 ) )
return 0 ;
V_54 = F_93 ( V_53 ) ;
V_55 = F_93 ( V_52 ) ;
V_55 -> V_36 = V_54 -> V_36 ;
if ( ! F_94 ( V_55 -> V_12 , V_54 -> V_12 ) )
goto V_56;
if ( V_54 -> V_50 . V_34 ) {
if ( ! F_95 ( & V_55 -> V_50 ,
V_54 -> V_50 . V_34 , V_54 -> V_50 . V_57 ) )
goto V_56;
}
return 1 ;
V_56:
F_96 ( V_52 ) ;
return 0 ;
}
static void F_96 ( T_10 * V_12 )
{
T_11 * V_49 = F_93 ( V_12 ) ;
if ( V_49 ) {
F_97 ( V_49 -> V_12 ) ;
F_98 ( V_49 -> V_50 . V_34 , V_49 -> V_50 . V_57 ) ;
F_88 ( V_49 ) ;
F_89 ( V_12 , NULL ) ;
}
}
static int F_99 ( T_10 * V_12 , T_7 * V_58 )
{
T_12 * V_59 = NULL ;
T_11 * V_49 = F_93 ( V_12 ) ;
if ( ! V_49 -> V_50 . V_34 )
return 0 ;
V_59 = F_100 ( & V_49 -> V_50 ) ;
if ( ! V_59 )
return 0 ;
F_101 ( V_58 , V_60 , V_59 ) ;
return 1 ;
}
static int F_102 ( T_5 * V_12 , const void * V_34 , T_3 V_35 )
{
T_11 * V_49 = F_93 ( F_103 ( V_12 ) ) ;
if ( ! F_104 ( V_49 -> V_12 , V_34 , V_35 ) )
return 0 ;
return 1 ;
}
static int F_105 ( T_10 * V_12 , T_5 * V_61 )
{
F_106 ( V_61 , V_62 ) ;
F_107 ( V_61 , F_102 ) ;
return 1 ;
}
static int F_108 ( T_10 * V_12 , unsigned char * V_63 ,
T_3 * V_64 , T_5 * V_61 )
{
unsigned int V_65 ;
T_11 * V_49 = F_93 ( V_12 ) ;
int V_66 = F_109 ( V_61 ) ;
if ( V_66 < 0 )
return 0 ;
* V_64 = V_66 ;
if ( ! V_63 )
return 1 ;
if ( ! F_110 ( V_49 -> V_12 , V_63 , & V_65 ) )
return 0 ;
* V_64 = ( T_3 ) V_65 ;
return 1 ;
}
static int F_111 ( T_10 * V_12 , int type , int V_67 , void * V_68 )
{
T_11 * V_49 = F_93 ( V_12 ) ;
T_7 * V_69 ;
T_12 * V_13 ;
switch ( type ) {
case V_70 :
if ( ( ! V_68 && V_67 > 0 ) || ( V_67 < - 1 ) )
return 0 ;
if ( ! F_95 ( & V_49 -> V_50 , V_68 , V_67 ) )
return 0 ;
break;
case V_71 :
V_49 -> V_36 = V_68 ;
break;
case V_72 :
V_69 = F_112 ( V_12 ) ;
V_13 = F_113 ( V_69 ) ;
if ( ! F_114 ( V_49 -> V_12 , V_13 -> V_34 , V_13 -> V_57 , V_49 -> V_36 , NULL ) )
return 0 ;
break;
default:
return - 2 ;
}
return 1 ;
}
static int F_115 ( T_10 * V_12 ,
const char * type , const char * V_73 )
{
if ( ! V_73 ) {
return 0 ;
}
if ( strcmp ( type , L_12 ) == 0 ) {
void * V_74 = ( void * ) V_73 ;
return F_111 ( V_12 , V_70 , - 1 , V_74 ) ;
}
if ( strcmp ( type , L_13 ) == 0 ) {
unsigned char * V_13 ;
int V_75 ;
long V_76 ;
V_13 = F_116 ( V_73 , & V_76 ) ;
if ( ! V_13 )
return 0 ;
V_75 = F_111 ( V_12 , V_70 , V_76 , V_13 ) ;
F_88 ( V_13 ) ;
return V_75 ;
}
return - 2 ;
}
static int F_27 ( void )
{
T_13 * V_77 ;
V_77 = F_117 ( V_60 , 0 ) ;
if ( V_77 == NULL )
return 0 ;
F_118 ( V_77 , F_85 ) ;
F_119 ( V_77 , F_92 ) ;
F_120 ( V_77 , F_96 ) ;
F_121 ( V_77 , 0 , F_99 ) ;
F_122 ( V_77 , F_105 ,
F_108 ) ;
F_123 ( V_77 , F_111 , F_115 ) ;
V_78 = V_77 ;
return 1 ;
}
static int V_8 ( T_1 * V_1 , T_13 * * V_79 ,
const int * * V_28 , int V_32 )
{
static int V_80 [] = {
V_60 ,
0
} ;
if ( ! V_79 ) {
* V_28 = V_80 ;
return 1 ;
}
if ( V_32 == V_60 ) {
* V_79 = V_78 ;
return 1 ;
}
* V_79 = NULL ;
return 0 ;
}
int V_4 ( T_1 * V_1 )
{
F_78 () ;
#ifdef F_20
F_52 () ;
F_54 () ;
#endif
return 1 ;
}
