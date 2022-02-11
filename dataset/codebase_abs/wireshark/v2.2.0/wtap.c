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
void
F_7 ( void )
{
F_8 () ;
F_9 ( L_2 , F_1 ) ;
}
static void
F_10 ( T_3 V_6 , T_3 T_5 V_7 )
{
T_4 * V_3 = ( T_4 * ) V_6 ;
( V_3 -> V_4 ) ( ) ;
}
void
F_11 ( void )
{
F_12 ( V_5 , F_10 , NULL ) ;
}
T_6
F_13 ( T_7 * V_8 , int * V_9 )
{
T_8 V_10 ;
if ( F_14 ( ( V_8 -> V_11 == NULL ) ? V_8 -> V_12 : V_8 -> V_11 ,
& V_10 , V_9 ) == - 1 )
return - 1 ;
return V_10 . V_13 ;
}
int
F_15 ( T_7 * V_8 , T_8 * V_10 , int * V_9 )
{
if ( F_14 ( ( V_8 -> V_11 == NULL ) ? V_8 -> V_12 : V_8 -> V_11 ,
V_10 , V_9 ) == - 1 )
return - 1 ;
return 0 ;
}
int
F_16 ( T_7 * V_8 )
{
return V_8 -> V_14 ;
}
T_1
F_17 ( T_7 * V_8 )
{
return F_18 ( ( V_8 -> V_11 == NULL ) ? V_8 -> V_12 : V_8 -> V_11 ) ;
}
T_9
F_19 ( T_7 * V_8 )
{
return V_8 -> V_15 ;
}
int
F_20 ( T_7 * V_8 )
{
return V_8 -> V_16 ;
}
int
F_21 ( T_7 * V_8 )
{
return V_8 -> V_17 ;
}
T_10
F_22 ( T_7 * V_8 )
{
if ( ( V_8 == NULL ) || ( V_8 -> V_18 == NULL ) || ( V_8 -> V_18 -> V_19 == 0 ) )
return NULL ;
return F_23 ( V_8 -> V_18 , T_10 , 0 ) ;
}
T_11 *
F_24 ( T_7 * V_8 )
{
T_9 V_20 ;
T_10 V_21 , V_22 ;
T_11 * V_18 ;
if ( ( V_8 == NULL ) || ( V_8 -> V_18 == NULL ) || ( V_8 -> V_18 -> V_19 == 0 ) )
return NULL ;
V_18 = F_25 ( FALSE , FALSE , sizeof( T_10 ) ) ;
for ( V_20 = 0 ; V_20 < V_8 -> V_18 -> V_19 ; V_20 ++ ) {
V_21 = F_23 ( V_8 -> V_18 , T_10 , V_20 ) ;
V_22 = F_26 ( V_23 ) ;
F_27 ( V_22 , V_21 ) ;
F_28 ( V_18 , V_22 ) ;
}
return V_18 ;
}
void
F_29 ( T_7 * V_8 , T_12 * V_24 )
{
if ( ( V_8 != NULL ) && ( V_8 -> V_18 != NULL ) && ( V_8 -> V_18 -> V_19 > 0 ) ) {
F_30 ( F_23 ( V_8 -> V_18 , T_10 , 0 ) , V_25 , 0 , V_24 , ( V_26 ) ( V_24 ? strlen ( V_24 ) : 0 ) ) ;
}
}
T_13 *
F_31 ( T_7 * V_8 )
{
T_13 * V_27 ;
V_27 = F_32 ( T_13 , 1 ) ;
V_27 -> V_28 = V_8 -> V_28 ;
return V_27 ;
}
void
F_33 ( T_13 * V_27 )
{
if ( V_27 == NULL )
return;
F_34 ( V_27 -> V_28 ) ;
F_35 ( V_27 ) ;
}
T_12 *
F_36 ( const T_10 V_29 ,
const int V_30 ,
const char * V_31 )
{
char * V_32 ;
T_14 * V_33 ;
T_15 * V_34 = F_37 ( L_3 ) ;
T_16 V_35 ;
T_17 V_36 ;
T_18 V_37 ;
T_19 * V_38 ;
F_38 ( V_29 ) ;
V_33 = ( T_14 * ) F_39 ( V_29 ) ;
if ( F_40 ( V_29 , V_39 , & V_32 ) == V_40 ) {
F_41 ( V_34 ,
L_4 , V_30 , ' ' ,
V_32 ? V_32 : L_5 ,
V_31 ) ;
}
if ( F_40 ( V_29 , V_41 , & V_32 ) == V_40 ) {
F_42 ( V_34 ,
L_6 , V_30 , ' ' ,
V_32 ? V_32 : L_7 ,
V_31 ) ;
}
F_42 ( V_34 ,
L_8 , V_30 , ' ' ,
F_43 ( V_33 -> V_42 ) ,
V_33 -> V_42 ,
V_33 -> V_43 ,
F_44 ( V_33 -> V_42 ) ,
V_31 ) ;
if ( F_45 ( V_29 , V_44 , & V_35 ) == V_40 ) {
F_42 ( V_34 ,
L_9 V_45 L_10 , V_30 , ' ' ,
V_35 ,
V_31 ) ;
}
F_42 ( V_34 ,
L_11 , V_30 , ' ' ,
V_33 -> V_46 ,
V_31 ) ;
if ( F_46 ( V_29 , V_47 , & V_36 ) == V_40 ) {
F_42 ( V_34 ,
L_12 , V_30 , ' ' ,
V_36 ,
V_31 ) ;
}
F_42 ( V_34 ,
L_13 , V_30 , ' ' ,
F_47 ( V_33 -> V_48 ) ,
V_33 -> V_48 ,
V_31 ) ;
F_42 ( V_34 ,
L_14 V_45 L_10 , V_30 , ' ' ,
V_33 -> V_49 ,
V_31 ) ;
if ( F_46 ( V_29 , V_50 , & V_37 ) == V_40 ) {
F_42 ( V_34 ,
L_15 , V_30 , ' ' ,
V_37 ,
V_31 ) ;
}
if ( F_48 ( V_29 , V_51 , ( void * * ) & V_38 ) == V_40 ) {
F_42 ( V_34 ,
L_16 , V_30 , ' ' ,
V_38 -> V_52 ? V_38 -> V_52 : L_7 ,
V_31 ) ;
F_42 ( V_34 ,
L_17 , V_30 , ' ' ,
V_38 -> V_53 ,
V_31 ) ;
}
if ( F_40 ( V_29 , V_54 , & V_32 ) == V_40 ) {
F_42 ( V_34 ,
L_18 , V_30 , ' ' ,
V_32 ? V_32 : L_5 ,
V_31 ) ;
}
if ( F_49 ( V_29 , V_25 , 0 , & V_32 ) == V_40 ) {
F_42 ( V_34 ,
L_19 , V_30 , ' ' ,
V_32 ? V_32 : L_7 ,
V_31 ) ;
}
F_42 ( V_34 ,
L_20 , V_30 , ' ' ,
V_33 -> V_55 ,
V_31 ) ;
return F_50 ( V_34 , FALSE ) ;
}
T_10
F_51 ( T_7 * V_8 )
{
if ( ( V_8 == NULL ) || ( V_8 -> V_56 == NULL ) || ( V_8 -> V_56 -> V_19 == 0 ) )
return NULL ;
return F_23 ( V_8 -> V_56 , T_10 , 0 ) ;
}
T_11 *
F_52 ( T_7 * V_8 )
{
T_9 V_57 ;
T_10 V_58 , V_59 ;
T_11 * V_56 ;
if ( ( V_8 == NULL || V_8 -> V_56 == NULL ) || ( V_8 -> V_56 -> V_19 == 0 ) )
return NULL ;
V_56 = F_25 ( FALSE , FALSE , sizeof( T_10 ) ) ;
for ( V_57 = 0 ; V_57 < V_8 -> V_56 -> V_19 ; V_57 ++ ) {
V_58 = F_23 ( V_8 -> V_56 , T_10 , V_57 ) ;
V_59 = F_26 ( V_60 ) ;
F_27 ( V_59 , V_58 ) ;
F_28 ( V_56 , V_59 ) ;
}
return V_56 ;
}
static void F_53 ( void ) {
if ( V_61 ) return;
V_61 = F_25 ( FALSE , TRUE , sizeof( struct V_62 ) ) ;
F_54 ( V_61 , V_63 , V_64 ) ;
}
int F_55 ( void ) {
F_53 () ;
return V_64 ;
}
int F_56 ( const char * V_65 , const char * V_66 ) {
struct V_62 V_67 ;
F_53 () ;
V_67 . V_65 = F_57 ( V_65 ) ;
V_67 . V_66 = F_57 ( V_66 ) ;
F_28 ( V_61 , V_67 ) ;
return V_64 ++ ;
}
const char *
F_43 ( int V_68 )
{
if ( V_68 < V_69 || V_68 >= V_70 )
return L_21 ;
else if ( V_68 == V_69 )
return L_22 ;
else
return F_58 ( V_68 ) . V_65 ;
}
const char *
F_44 ( int V_68 )
{
if ( V_68 < V_69 || V_68 >= V_70 )
return L_23 ;
else if ( V_68 == V_69 )
return L_24 ;
else
return F_58 ( V_68 ) . V_66 ;
}
int
F_59 ( const char * V_66 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_70 ; V_68 ++ ) {
if ( F_58 ( V_68 ) . V_66 != NULL &&
strcmp ( V_66 , F_58 ( V_68 ) . V_66 ) == 0 )
return V_68 ;
}
return - 1 ;
}
const char *
F_47 ( int V_71 )
{
const char * V_72 ;
switch ( V_71 ) {
case V_73 :
V_72 = L_24 ;
break;
case V_74 :
V_72 = L_25 ;
break;
case V_75 :
V_72 = L_26 ;
break;
case V_76 :
V_72 = L_27 ;
break;
case V_77 :
V_72 = L_28 ;
break;
case V_78 :
V_72 = L_29 ;
break;
case V_79 :
V_72 = L_30 ;
break;
case V_80 :
default:
V_72 = L_5 ;
break;
}
return V_72 ;
}
const char *
F_60 ( int V_9 )
{
static char V_81 [ 128 ] ;
unsigned int V_82 ;
if ( V_9 < 0 ) {
V_82 = - 1 - V_9 ;
if ( V_82 >= V_83 ) {
F_61 ( V_81 , 128 , L_31 , V_9 ) ;
return V_81 ;
}
if ( V_84 [ V_82 ] == NULL )
return L_32 ;
return V_84 [ V_82 ] ;
} else
return F_62 ( V_9 ) ;
}
void
F_63 ( T_7 * V_8 )
{
if ( V_8 -> V_85 != NULL )
(* V_8 -> V_85 )( V_8 ) ;
if ( V_8 -> V_11 != NULL ) {
F_64 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
}
if ( V_8 -> V_86 ) {
F_65 ( V_8 -> V_86 ) ;
F_35 ( V_8 -> V_86 ) ;
V_8 -> V_86 = NULL ;
}
}
static void
F_66 ( T_3 V_6 , T_3 T_5 V_7 )
{
F_35 ( V_6 ) ;
}
void
F_67 ( T_7 * V_8 )
{
if ( V_8 -> V_11 != NULL )
F_68 ( V_8 -> V_11 ) ;
if ( V_8 -> V_12 != NULL )
F_68 ( V_8 -> V_12 ) ;
}
void
F_69 ( T_7 * V_8 )
{
F_63 ( V_8 ) ;
if ( V_8 -> V_87 != NULL )
(* V_8 -> V_87 )( V_8 ) ;
if ( V_8 -> V_12 != NULL )
F_64 ( V_8 -> V_12 ) ;
if ( V_8 -> V_88 != NULL )
F_35 ( V_8 -> V_88 ) ;
if ( V_8 -> V_89 != NULL ) {
F_70 ( V_8 -> V_89 , F_66 , NULL ) ;
F_71 ( V_8 -> V_89 , TRUE ) ;
}
F_34 ( V_8 -> V_18 ) ;
F_34 ( V_8 -> V_56 ) ;
F_34 ( V_8 -> V_28 ) ;
F_35 ( V_8 ) ;
}
void
F_72 ( T_7 * V_8 ) {
F_73 ( V_8 -> V_11 ) ;
}
void F_74 ( T_7 * V_8 , T_20 V_90 ) {
if ( V_8 )
V_8 -> V_90 = V_90 ;
}
void F_75 ( T_7 * V_8 , T_21 V_91 ) {
if ( V_8 )
V_8 -> V_91 = V_91 ;
}
T_1
F_76 ( T_7 * V_8 , int * V_9 , T_12 * * V_92 , T_6 * V_93 )
{
V_8 -> V_94 . V_95 = V_8 -> V_16 ;
V_8 -> V_94 . V_96 = V_8 -> V_17 ;
* V_9 = 0 ;
* V_92 = NULL ;
if ( ! V_8 -> V_97 ( V_8 , V_9 , V_92 , V_93 ) ) {
if ( * V_9 == 0 )
* V_9 = F_77 ( V_8 -> V_11 , V_92 ) ;
return FALSE ;
}
if ( V_8 -> V_94 . V_98 > V_8 -> V_94 . V_19 )
V_8 -> V_94 . V_98 = V_8 -> V_94 . V_19 ;
F_38 ( V_8 -> V_94 . V_95 != V_69 ) ;
return TRUE ;
}
T_1
F_78 ( T_22 V_11 , void * V_99 , unsigned int V_100 , int * V_9 ,
T_12 * * V_92 )
{
int V_101 ;
V_101 = F_79 ( V_99 , V_100 , V_11 ) ;
if ( V_101 < 0 || ( T_9 ) V_101 != V_100 ) {
* V_9 = F_77 ( V_11 , V_92 ) ;
if ( * V_9 == 0 && V_101 > 0 )
* V_9 = V_102 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_80 ( T_22 V_11 , void * V_99 , unsigned int V_100 , int * V_9 ,
T_12 * * V_92 )
{
int V_101 ;
V_101 = F_79 ( V_99 , V_100 , V_11 ) ;
if ( V_101 < 0 || ( T_9 ) V_101 != V_100 ) {
* V_9 = F_77 ( V_11 , V_92 ) ;
if ( * V_9 == 0 )
* V_9 = V_102 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_81 ( T_22 V_11 , T_23 * V_99 , T_9 V_103 , int * V_9 ,
T_12 * * V_92 )
{
F_82 ( V_99 , V_103 ) ;
return F_80 ( V_11 , F_83 ( V_99 ) , V_103 , V_9 ,
V_92 ) ;
}
T_6
F_84 ( T_7 * V_8 )
{
return F_85 ( V_8 -> V_11 ) ;
}
struct V_104 *
F_86 ( T_7 * V_8 )
{
return & V_8 -> V_94 ;
}
T_18 *
F_87 ( T_7 * V_8 )
{
return F_83 ( V_8 -> V_86 ) ;
}
void
F_88 ( struct V_104 * V_94 )
{
memset ( V_94 , 0 , sizeof( struct V_104 ) ) ;
F_89 ( & V_94 -> V_105 , 0 ) ;
}
void
F_90 ( struct V_104 * V_94 )
{
F_65 ( & V_94 -> V_105 ) ;
}
T_1
F_91 ( T_7 * V_8 , T_6 V_106 ,
struct V_104 * V_94 , T_23 * V_99 , int * V_9 , T_12 * * V_92 )
{
V_94 -> V_95 = V_8 -> V_16 ;
V_94 -> V_96 = V_8 -> V_17 ;
if ( ! V_8 -> V_107 ( V_8 , V_106 , V_94 , V_99 , V_9 , V_92 ) )
return FALSE ;
if ( V_94 -> V_98 > V_94 -> V_19 )
V_94 -> V_98 = V_94 -> V_19 ;
F_38 ( V_94 -> V_95 != V_69 ) ;
return TRUE ;
}
