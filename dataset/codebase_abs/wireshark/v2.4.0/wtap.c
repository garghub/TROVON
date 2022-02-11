static T_1
F_1 ( T_2 * V_1 )
{
T_3 V_2 ;
T_4 * V_3 ;
if ( ! F_2 ( V_1 , L_1 , & V_2 ) ) {
return FALSE ;
}
V_3 = ( T_4 * ) F_3 ( sizeof ( T_4 ) ) ;
F_4 (pedantic)
V_3 -> V_4 = ( void ( * ) ( void ) ) V_2 ;
F_5 (pedantic)
V_5 = F_6 ( V_5 , V_3 ) ;
return TRUE ;
}
static void
F_7 ( void )
{
F_8 ( L_2 , F_1 ) ;
}
static void
F_9 ( T_3 V_6 , T_3 T_5 V_7 )
{
T_4 * V_3 = ( T_4 * ) V_6 ;
( V_3 -> V_4 ) ( ) ;
}
void
F_10 ( void )
{
F_11 ( V_5 , F_9 , NULL ) ;
}
T_6
F_12 ( T_7 * V_8 , int * V_9 )
{
T_8 V_10 ;
if ( F_13 ( ( V_8 -> V_11 == NULL ) ? V_8 -> V_12 : V_8 -> V_11 ,
& V_10 , V_9 ) == - 1 )
return - 1 ;
return V_10 . V_13 ;
}
int
F_14 ( T_7 * V_8 , T_8 * V_10 , int * V_9 )
{
if ( F_13 ( ( V_8 -> V_11 == NULL ) ? V_8 -> V_12 : V_8 -> V_11 ,
V_10 , V_9 ) == - 1 )
return - 1 ;
return 0 ;
}
int
F_15 ( T_7 * V_8 )
{
return V_8 -> V_14 ;
}
T_1
F_16 ( T_7 * V_8 )
{
return F_17 ( ( V_8 -> V_11 == NULL ) ? V_8 -> V_12 : V_8 -> V_11 ) ;
}
T_9
F_18 ( T_7 * V_8 )
{
return V_8 -> V_15 ;
}
int
F_19 ( T_7 * V_8 )
{
return V_8 -> V_16 ;
}
int
F_20 ( T_7 * V_8 )
{
return V_8 -> V_17 ;
}
T_10
F_21 ( T_7 * V_8 )
{
if ( ( V_8 == NULL ) || ( V_8 -> V_18 == NULL ) || ( V_8 -> V_18 -> V_19 == 0 ) )
return NULL ;
return F_22 ( V_8 -> V_18 , T_10 , 0 ) ;
}
T_11 *
F_23 ( T_7 * V_8 )
{
T_9 V_20 ;
T_10 V_21 , V_22 ;
T_11 * V_18 ;
if ( ( V_8 == NULL ) || ( V_8 -> V_18 == NULL ) || ( V_8 -> V_18 -> V_19 == 0 ) )
return NULL ;
V_18 = F_24 ( FALSE , FALSE , sizeof( T_10 ) ) ;
for ( V_20 = 0 ; V_20 < V_8 -> V_18 -> V_19 ; V_20 ++ ) {
V_21 = F_22 ( V_8 -> V_18 , T_10 , V_20 ) ;
V_22 = F_25 ( V_23 ) ;
F_26 ( V_22 , V_21 ) ;
F_27 ( V_18 , V_22 ) ;
}
return V_18 ;
}
void
F_28 ( T_7 * V_8 , T_12 * V_24 )
{
if ( ( V_8 != NULL ) && ( V_8 -> V_18 != NULL ) && ( V_8 -> V_18 -> V_19 > 0 ) ) {
F_29 ( F_22 ( V_8 -> V_18 , T_10 , 0 ) , V_25 , 0 , V_24 , ( V_26 ) ( V_24 ? strlen ( V_24 ) : 0 ) ) ;
}
}
T_13 *
F_30 ( T_7 * V_8 )
{
T_13 * V_27 ;
V_27 = F_31 ( T_13 , 1 ) ;
V_27 -> V_28 = V_8 -> V_28 ;
return V_27 ;
}
void
F_32 ( T_13 * V_27 )
{
if ( V_27 == NULL )
return;
F_33 ( V_27 -> V_28 ) ;
F_34 ( V_27 ) ;
}
T_12 *
F_35 ( const T_10 V_29 ,
const int V_30 ,
const char * V_31 )
{
char * V_32 ;
T_14 * V_33 ;
T_15 * V_34 = F_36 ( L_3 ) ;
T_16 V_35 ;
T_17 V_36 ;
T_18 V_37 ;
T_19 * V_38 ;
F_37 ( V_29 ) ;
V_33 = ( T_14 * ) F_38 ( V_29 ) ;
if ( F_39 ( V_29 , V_39 , & V_32 ) == V_40 ) {
F_40 ( V_34 ,
L_4 , V_30 , ' ' ,
V_32 ? V_32 : L_5 ,
V_31 ) ;
}
if ( F_39 ( V_29 , V_41 , & V_32 ) == V_40 ) {
F_41 ( V_34 ,
L_6 , V_30 , ' ' ,
V_32 ? V_32 : L_7 ,
V_31 ) ;
}
F_41 ( V_34 ,
L_8 , V_30 , ' ' ,
F_42 ( V_33 -> V_42 ) ,
V_33 -> V_42 ,
F_43 ( V_33 -> V_42 ) ,
V_31 ) ;
if ( F_44 ( V_29 , V_43 , & V_35 ) == V_40 ) {
F_41 ( V_34 ,
L_9 V_44 L_10 , V_30 , ' ' ,
V_35 ,
V_31 ) ;
}
F_41 ( V_34 ,
L_11 , V_30 , ' ' ,
V_33 -> V_45 ,
V_31 ) ;
if ( F_45 ( V_29 , V_46 , & V_36 ) == V_40 ) {
F_41 ( V_34 ,
L_12 , V_30 , ' ' ,
V_36 ,
V_31 ) ;
}
F_41 ( V_34 ,
L_13 , V_30 , ' ' ,
F_46 ( V_33 -> V_47 ) ,
V_33 -> V_47 ,
V_31 ) ;
F_41 ( V_34 ,
L_14 V_44 L_10 , V_30 , ' ' ,
V_33 -> V_48 ,
V_31 ) ;
if ( F_45 ( V_29 , V_49 , & V_37 ) == V_40 ) {
F_41 ( V_34 ,
L_15 , V_30 , ' ' ,
V_37 ,
V_31 ) ;
}
if ( F_47 ( V_29 , V_50 , ( void * * ) & V_38 ) == V_40 ) {
F_41 ( V_34 ,
L_16 , V_30 , ' ' ,
V_38 -> V_51 ? V_38 -> V_51 : L_7 ,
V_31 ) ;
F_41 ( V_34 ,
L_17 , V_30 , ' ' ,
V_38 -> V_52 ,
V_31 ) ;
}
if ( F_39 ( V_29 , V_53 , & V_32 ) == V_40 ) {
F_41 ( V_34 ,
L_18 , V_30 , ' ' ,
V_32 ? V_32 : L_5 ,
V_31 ) ;
}
if ( F_48 ( V_29 , V_25 , 0 , & V_32 ) == V_40 ) {
F_41 ( V_34 ,
L_19 , V_30 , ' ' ,
V_32 ? V_32 : L_7 ,
V_31 ) ;
}
F_41 ( V_34 ,
L_20 , V_30 , ' ' ,
V_33 -> V_54 ,
V_31 ) ;
return F_49 ( V_34 , FALSE ) ;
}
T_10
F_50 ( T_7 * V_8 )
{
if ( ( V_8 == NULL ) || ( V_8 -> V_55 == NULL ) || ( V_8 -> V_55 -> V_19 == 0 ) )
return NULL ;
return F_22 ( V_8 -> V_55 , T_10 , 0 ) ;
}
T_11 *
F_51 ( T_7 * V_8 )
{
T_9 V_56 ;
T_10 V_57 , V_58 ;
T_11 * V_55 ;
if ( ( V_8 == NULL || V_8 -> V_55 == NULL ) || ( V_8 -> V_55 -> V_19 == 0 ) )
return NULL ;
V_55 = F_24 ( FALSE , FALSE , sizeof( T_10 ) ) ;
for ( V_56 = 0 ; V_56 < V_8 -> V_55 -> V_19 ; V_56 ++ ) {
V_57 = F_22 ( V_8 -> V_55 , T_10 , V_56 ) ;
V_58 = F_25 ( V_59 ) ;
F_26 ( V_58 , V_57 ) ;
F_27 ( V_55 , V_58 ) ;
}
return V_55 ;
}
static void F_52 ( void ) {
if ( V_60 ) return;
V_60 = F_24 ( FALSE , TRUE , sizeof( struct V_61 ) ) ;
F_53 ( V_60 , V_62 , V_63 ) ;
}
static void F_54 ( void ) {
if ( V_60 ) {
F_55 ( V_60 , TRUE ) ;
V_60 = NULL ;
}
}
int F_56 ( void ) {
return V_63 ;
}
int F_57 ( const char * V_64 , const char * V_65 ) {
struct V_61 V_66 ;
V_66 . V_64 = F_58 ( V_64 ) ;
V_66 . V_65 = F_58 ( V_65 ) ;
F_27 ( V_60 , V_66 ) ;
return V_63 ++ ;
}
const char *
F_42 ( int V_67 )
{
if ( V_67 < V_68 || V_67 >= V_69 )
return L_21 ;
else if ( V_67 == V_68 )
return L_22 ;
else
return F_59 ( V_67 ) . V_64 ;
}
const char *
F_43 ( int V_67 )
{
if ( V_67 < V_68 || V_67 >= V_69 )
return L_23 ;
else if ( V_67 == V_68 )
return L_24 ;
else
return F_59 ( V_67 ) . V_65 ;
}
int
F_60 ( const char * V_65 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_69 ; V_67 ++ ) {
if ( F_59 ( V_67 ) . V_65 != NULL &&
strcmp ( V_65 , F_59 ( V_67 ) . V_65 ) == 0 )
return V_67 ;
}
return - 1 ;
}
const char *
F_46 ( int V_70 )
{
const char * V_71 ;
switch ( V_70 ) {
case V_72 :
V_71 = L_24 ;
break;
case V_73 :
V_71 = L_25 ;
break;
case V_74 :
V_71 = L_26 ;
break;
case V_75 :
V_71 = L_27 ;
break;
case V_76 :
V_71 = L_28 ;
break;
case V_77 :
V_71 = L_29 ;
break;
case V_78 :
V_71 = L_30 ;
break;
case V_79 :
default:
V_71 = L_5 ;
break;
}
return V_71 ;
}
const char *
F_61 ( int V_9 )
{
static char V_80 [ 128 ] ;
unsigned int V_81 ;
if ( V_9 < 0 ) {
V_81 = - 1 - V_9 ;
if ( V_81 >= V_82 ) {
F_62 ( V_80 , 128 , L_31 , V_9 ) ;
return V_80 ;
}
if ( V_83 [ V_81 ] == NULL )
return L_32 ;
return V_83 [ V_81 ] ;
} else
return F_63 ( V_9 ) ;
}
void
F_64 ( T_7 * V_8 )
{
if ( V_8 -> V_84 != NULL )
(* V_8 -> V_84 )( V_8 ) ;
if ( V_8 -> V_11 != NULL ) {
F_65 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
}
if ( V_8 -> V_85 ) {
F_66 ( V_8 -> V_85 ) ;
F_34 ( V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
}
}
static void
F_67 ( T_3 V_6 , T_3 T_5 V_7 )
{
F_34 ( V_6 ) ;
}
void
F_68 ( T_7 * V_8 )
{
if ( V_8 -> V_11 != NULL )
F_69 ( V_8 -> V_11 ) ;
if ( V_8 -> V_12 != NULL )
F_69 ( V_8 -> V_12 ) ;
}
void
F_70 ( T_7 * V_8 )
{
F_64 ( V_8 ) ;
if ( V_8 -> V_86 != NULL )
(* V_8 -> V_86 )( V_8 ) ;
if ( V_8 -> V_12 != NULL )
F_65 ( V_8 -> V_12 ) ;
if ( V_8 -> V_87 != NULL )
F_34 ( V_8 -> V_87 ) ;
if ( V_8 -> V_88 != NULL ) {
F_71 ( V_8 -> V_88 , F_67 , NULL ) ;
F_72 ( V_8 -> V_88 , TRUE ) ;
}
F_33 ( V_8 -> V_18 ) ;
F_33 ( V_8 -> V_55 ) ;
F_33 ( V_8 -> V_28 ) ;
F_34 ( V_8 ) ;
}
void
F_73 ( T_7 * V_8 ) {
F_74 ( V_8 -> V_11 ) ;
}
void F_75 ( T_7 * V_8 , T_20 V_89 ) {
if ( V_8 )
V_8 -> V_89 = V_89 ;
}
void F_76 ( T_7 * V_8 , T_21 V_90 ) {
if ( V_8 )
V_8 -> V_90 = V_90 ;
}
T_1
F_77 ( T_7 * V_8 , int * V_9 , T_12 * * V_91 , T_6 * V_92 )
{
V_8 -> V_93 . V_94 = V_8 -> V_16 ;
V_8 -> V_93 . V_95 = V_8 -> V_17 ;
* V_9 = 0 ;
* V_91 = NULL ;
if ( ! V_8 -> V_96 ( V_8 , V_9 , V_91 , V_92 ) ) {
if ( * V_9 == 0 )
* V_9 = F_78 ( V_8 -> V_11 , V_91 ) ;
return FALSE ;
}
if ( V_8 -> V_93 . V_97 > V_8 -> V_93 . V_19 )
V_8 -> V_93 . V_97 = V_8 -> V_93 . V_19 ;
F_37 ( V_8 -> V_93 . V_94 != V_68 ) ;
return TRUE ;
}
T_1
F_79 ( T_22 V_11 , void * V_98 , unsigned int V_99 , int * V_9 ,
T_12 * * V_91 )
{
int V_100 ;
V_100 = F_80 ( V_98 , V_99 , V_11 ) ;
if ( V_100 < 0 || ( T_9 ) V_100 != V_99 ) {
* V_9 = F_78 ( V_11 , V_91 ) ;
if ( * V_9 == 0 && V_100 > 0 )
* V_9 = V_101 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_81 ( T_22 V_11 , void * V_98 , unsigned int V_99 , int * V_9 ,
T_12 * * V_91 )
{
int V_100 ;
V_100 = F_80 ( V_98 , V_99 , V_11 ) ;
if ( V_100 < 0 || ( T_9 ) V_100 != V_99 ) {
* V_9 = F_78 ( V_11 , V_91 ) ;
if ( * V_9 == 0 )
* V_9 = V_101 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_82 ( T_22 V_11 , T_23 * V_98 , T_9 V_102 , int * V_9 ,
T_12 * * V_91 )
{
F_83 ( V_98 , V_102 ) ;
return F_81 ( V_11 , F_84 ( V_98 ) , V_102 , V_9 ,
V_91 ) ;
}
T_6
F_85 ( T_7 * V_8 )
{
return F_86 ( V_8 -> V_11 ) ;
}
struct V_103 *
F_87 ( T_7 * V_8 )
{
return & V_8 -> V_93 ;
}
T_18 *
F_88 ( T_7 * V_8 )
{
return F_84 ( V_8 -> V_85 ) ;
}
void
F_89 ( struct V_103 * V_93 )
{
memset ( V_93 , 0 , sizeof( struct V_103 ) ) ;
F_90 ( & V_93 -> V_104 , 0 ) ;
}
void
F_91 ( struct V_103 * V_93 )
{
F_66 ( & V_93 -> V_104 ) ;
}
T_1
F_92 ( T_7 * V_8 , T_6 V_105 ,
struct V_103 * V_93 , T_23 * V_98 , int * V_9 , T_12 * * V_91 )
{
V_93 -> V_94 = V_8 -> V_16 ;
V_93 -> V_95 = V_8 -> V_17 ;
* V_9 = 0 ;
* V_91 = NULL ;
if ( ! V_8 -> V_106 ( V_8 , V_105 , V_93 , V_98 , V_9 , V_91 ) )
return FALSE ;
if ( V_93 -> V_97 > V_93 -> V_19 )
V_93 -> V_97 = V_93 -> V_19 ;
F_37 ( V_93 -> V_94 != V_68 ) ;
return TRUE ;
}
void
F_93 ( void )
{
F_94 () ;
F_95 () ;
F_52 () ;
#ifdef F_96
F_7 () ;
#endif
}
void
F_97 ( void )
{
F_54 () ;
F_98 () ;
F_99 () ;
F_100 () ;
}
