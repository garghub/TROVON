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
const T_10 *
F_22 ( T_7 * V_8 )
{
char * V_18 ;
if ( ( V_8 == NULL ) || ( V_8 -> V_19 == NULL ) || ( V_8 -> V_19 -> V_20 == 0 ) )
return NULL ;
F_23 ( F_24 ( V_8 -> V_19 , V_21 , 0 ) , V_22 , & V_18 ) ;
return V_18 ;
}
V_21
F_25 ( T_7 * V_8 )
{
if ( ( V_8 == NULL ) || ( V_8 -> V_19 == NULL ) || ( V_8 -> V_19 -> V_20 == 0 ) )
return NULL ;
return F_24 ( V_8 -> V_19 , V_21 , 0 ) ;
}
T_11 *
F_26 ( T_7 * V_8 )
{
T_9 V_23 ;
V_21 V_24 , V_25 ;
T_11 * V_19 ;
if ( ( V_8 == NULL ) || ( V_8 -> V_19 == NULL ) || ( V_8 -> V_19 -> V_20 == 0 ) )
return NULL ;
V_19 = F_27 ( FALSE , FALSE , sizeof( V_21 ) ) ;
for ( V_23 = 0 ; V_23 < V_8 -> V_19 -> V_20 ; V_23 ++ ) {
V_24 = F_24 ( V_8 -> V_19 , V_21 , V_23 ) ;
V_25 = F_28 ( V_26 ) ;
F_29 ( V_25 , V_24 ) ;
F_30 ( V_19 , V_25 ) ;
}
return V_19 ;
}
const T_10 *
F_31 ( T_7 * V_8 )
{
char * V_18 ;
F_32 ( V_8 ) ;
if ( ( V_8 == NULL ) || ( V_8 -> V_27 == NULL ) || ( V_8 -> V_27 -> V_20 == 0 ) )
return NULL ;
F_23 ( F_24 ( V_8 -> V_27 , V_21 , 0 ) , V_22 , & V_18 ) ;
return V_18 ;
}
void
F_33 ( T_7 * V_8 , T_10 * V_28 )
{
V_21 V_29 ;
F_32 ( V_8 ) ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_27 == NULL ) {
V_8 -> V_27 = F_27 ( FALSE , FALSE , sizeof( V_21 ) ) ;
V_29 = F_28 ( V_30 ) ;
F_30 ( V_8 -> V_27 , V_29 ) ;
}
F_34 ( F_24 ( V_8 -> V_27 , V_21 , 0 ) , V_22 , V_28 , ( V_31 ) ( V_28 ? strlen ( V_28 ) : 0 ) ) ;
}
void
F_35 ( T_7 * V_8 , T_10 * V_28 )
{
if ( ( V_8 != NULL ) && ( V_8 -> V_19 != NULL ) && ( V_8 -> V_19 -> V_20 > 0 ) ) {
F_34 ( F_24 ( V_8 -> V_19 , V_21 , 0 ) , V_22 , V_28 , ( V_31 ) ( V_28 ? strlen ( V_28 ) : 0 ) ) ;
}
}
T_12 *
F_36 ( T_7 * V_8 )
{
T_12 * V_32 ;
V_32 = F_37 ( T_12 , 1 ) ;
V_32 -> V_33 = V_8 -> V_33 ;
return V_32 ;
}
void
F_38 ( T_12 * V_32 )
{
if ( V_32 == NULL )
return;
F_39 ( V_32 -> V_33 ) ;
F_40 ( V_32 ) ;
}
T_10 *
F_41 ( const V_21 V_34 ,
const int V_35 ,
const char * V_36 )
{
char * V_37 ;
T_13 * V_38 ;
T_14 * V_39 = F_42 ( L_3 ) ;
T_15 V_40 ;
T_16 V_41 ;
T_17 V_42 ;
T_18 * V_43 ;
F_32 ( V_34 ) ;
V_38 = ( T_13 * ) F_43 ( V_34 ) ;
F_23 ( V_34 , V_44 , & V_37 ) ;
F_44 ( V_39 ,
L_4 , V_35 , ' ' ,
V_37 ? V_37 : L_5 ,
V_36 ) ;
F_23 ( V_34 , V_45 , & V_37 ) ;
F_45 ( V_39 ,
L_6 , V_35 , ' ' ,
V_37 ? V_37 : L_7 ,
V_36 ) ;
F_45 ( V_39 ,
L_8 , V_35 , ' ' ,
F_46 ( V_38 -> V_46 ) ,
V_38 -> V_46 ,
V_38 -> V_47 ,
F_47 ( V_38 -> V_46 ) ,
V_36 ) ;
F_48 ( V_34 , V_48 , & V_40 ) ;
F_45 ( V_39 ,
L_9 V_49 L_10 , V_35 , ' ' ,
V_40 ,
V_36 ) ;
F_45 ( V_39 ,
L_11 , V_35 , ' ' ,
V_38 -> V_50 ,
V_36 ) ;
F_49 ( V_34 , V_51 , & V_41 ) ;
F_45 ( V_39 ,
L_12 , V_35 , ' ' ,
V_41 ,
V_36 ) ;
F_45 ( V_39 ,
L_13 , V_35 , ' ' ,
F_50 ( V_38 -> V_52 ) ,
V_38 -> V_52 ,
V_36 ) ;
F_45 ( V_39 ,
L_14 V_49 L_10 , V_35 , ' ' ,
V_38 -> V_53 ,
V_36 ) ;
F_49 ( V_34 , V_54 , & V_42 ) ;
F_45 ( V_39 ,
L_15 , V_35 , ' ' ,
V_42 ,
V_36 ) ;
F_51 ( V_34 , V_55 , ( void * * ) & V_43 ) ;
F_45 ( V_39 ,
L_16 , V_35 , ' ' ,
V_43 -> V_56 ? V_43 -> V_56 : L_7 ,
V_36 ) ;
F_23 ( V_34 , V_57 , & V_37 ) ;
F_45 ( V_39 ,
L_17 , V_35 , ' ' ,
V_37 ? V_37 : L_5 ,
V_36 ) ;
F_23 ( V_34 , V_22 , & V_37 ) ;
F_45 ( V_39 ,
L_18 , V_35 , ' ' ,
V_37 ? V_37 : L_7 ,
V_36 ) ;
F_45 ( V_39 ,
L_19 , V_35 , ' ' ,
V_43 -> V_58 ,
V_36 ) ;
F_45 ( V_39 ,
L_20 , V_35 , ' ' ,
V_38 -> V_59 ,
V_36 ) ;
return F_52 ( V_39 , FALSE ) ;
}
T_11 *
F_53 ( T_7 * V_8 )
{
T_9 V_60 ;
V_21 V_61 , V_62 ;
T_11 * V_27 ;
if ( ( V_8 == NULL || V_8 -> V_27 == NULL ) || ( V_8 -> V_27 -> V_20 == 0 ) )
return NULL ;
V_27 = F_27 ( FALSE , FALSE , sizeof( V_21 ) ) ;
for ( V_60 = 0 ; V_60 < V_8 -> V_27 -> V_20 ; V_60 ++ ) {
V_61 = F_24 ( V_8 -> V_27 , V_21 , V_60 ) ;
V_62 = F_28 ( V_30 ) ;
F_29 ( V_62 , V_61 ) ;
F_30 ( V_27 , V_62 ) ;
}
return V_27 ;
}
static void F_54 ( void ) {
if ( V_63 ) return;
V_63 = F_27 ( FALSE , TRUE , sizeof( struct V_64 ) ) ;
F_55 ( V_63 , V_65 , V_66 ) ;
}
int F_56 ( void ) {
F_54 () ;
return V_66 ;
}
int F_57 ( const char * V_67 , const char * V_68 ) {
struct V_64 V_69 ;
F_54 () ;
V_69 . V_67 = F_58 ( V_67 ) ;
V_69 . V_68 = F_58 ( V_68 ) ;
F_30 ( V_63 , V_69 ) ;
return V_66 ++ ;
}
const char *
F_46 ( int V_70 )
{
if ( V_70 < V_71 || V_70 >= V_72 )
return L_21 ;
else if ( V_70 == V_71 )
return L_22 ;
else
return F_59 ( V_70 ) . V_67 ;
}
const char *
F_47 ( int V_70 )
{
if ( V_70 < V_71 || V_70 >= V_72 )
return L_23 ;
else if ( V_70 == V_71 )
return L_24 ;
else
return F_59 ( V_70 ) . V_68 ;
}
int
F_60 ( const char * V_68 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_72 ; V_70 ++ ) {
if ( F_59 ( V_70 ) . V_68 != NULL &&
strcmp ( V_68 , F_59 ( V_70 ) . V_68 ) == 0 )
return V_70 ;
}
return - 1 ;
}
const char *
F_50 ( int V_73 )
{
const char * V_74 ;
switch ( V_73 ) {
case V_75 :
V_74 = L_24 ;
break;
case V_76 :
V_74 = L_25 ;
break;
case V_77 :
V_74 = L_26 ;
break;
case V_78 :
V_74 = L_27 ;
break;
case V_79 :
V_74 = L_28 ;
break;
case V_80 :
V_74 = L_29 ;
break;
case V_81 :
V_74 = L_30 ;
break;
case V_82 :
default:
V_74 = L_5 ;
break;
}
return V_74 ;
}
const char *
F_61 ( int V_9 )
{
static char V_83 [ 128 ] ;
unsigned int V_84 ;
if ( V_9 < 0 ) {
V_84 = - 1 - V_9 ;
if ( V_84 >= V_85 ) {
F_62 ( V_83 , 128 , L_31 , V_9 ) ;
return V_83 ;
}
if ( V_86 [ V_84 ] == NULL )
return L_32 ;
return V_86 [ V_84 ] ;
} else
return F_63 ( V_9 ) ;
}
void
F_64 ( T_7 * V_8 )
{
if ( V_8 -> V_87 != NULL )
(* V_8 -> V_87 )( V_8 ) ;
if ( V_8 -> V_11 != NULL ) {
F_65 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
}
if ( V_8 -> V_88 ) {
F_66 ( V_8 -> V_88 ) ;
F_40 ( V_8 -> V_88 ) ;
V_8 -> V_88 = NULL ;
}
}
static void
F_67 ( T_3 V_6 , T_3 T_5 V_7 )
{
F_40 ( V_6 ) ;
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
if ( V_8 -> V_89 != NULL )
(* V_8 -> V_89 )( V_8 ) ;
if ( V_8 -> V_12 != NULL )
F_65 ( V_8 -> V_12 ) ;
if ( V_8 -> V_90 != NULL )
F_40 ( V_8 -> V_90 ) ;
if ( V_8 -> V_91 != NULL ) {
F_71 ( V_8 -> V_91 , F_67 , NULL ) ;
F_72 ( V_8 -> V_91 , TRUE ) ;
}
F_39 ( V_8 -> V_19 ) ;
F_39 ( V_8 -> V_27 ) ;
F_39 ( V_8 -> V_33 ) ;
F_40 ( V_8 ) ;
}
void
F_73 ( T_7 * V_8 ) {
F_74 ( V_8 -> V_11 ) ;
}
void F_75 ( T_7 * V_8 , T_19 V_92 ) {
if ( V_8 )
V_8 -> V_92 = V_92 ;
}
void F_76 ( T_7 * V_8 , T_20 V_93 ) {
if ( V_8 )
V_8 -> V_93 = V_93 ;
}
T_1
F_77 ( T_7 * V_8 , int * V_9 , T_10 * * V_94 , T_6 * V_95 )
{
V_8 -> V_96 . V_97 = V_8 -> V_16 ;
V_8 -> V_96 . V_98 = V_8 -> V_17 ;
* V_9 = 0 ;
* V_94 = NULL ;
if ( ! V_8 -> V_99 ( V_8 , V_9 , V_94 , V_95 ) ) {
if ( * V_9 == 0 )
* V_9 = F_78 ( V_8 -> V_11 , V_94 ) ;
return FALSE ;
}
if ( V_8 -> V_96 . V_100 > V_8 -> V_96 . V_20 )
V_8 -> V_96 . V_100 = V_8 -> V_96 . V_20 ;
F_32 ( V_8 -> V_96 . V_97 != V_71 ) ;
return TRUE ;
}
T_1
F_79 ( T_21 V_11 , void * V_101 , unsigned int V_102 , int * V_9 ,
T_10 * * V_94 )
{
int V_103 ;
V_103 = F_80 ( V_101 , V_102 , V_11 ) ;
if ( V_103 < 0 || ( T_9 ) V_103 != V_102 ) {
* V_9 = F_78 ( V_11 , V_94 ) ;
if ( * V_9 == 0 && V_103 > 0 )
* V_9 = V_104 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_81 ( T_21 V_11 , void * V_101 , unsigned int V_102 , int * V_9 ,
T_10 * * V_94 )
{
int V_103 ;
V_103 = F_80 ( V_101 , V_102 , V_11 ) ;
if ( V_103 < 0 || ( T_9 ) V_103 != V_102 ) {
* V_9 = F_78 ( V_11 , V_94 ) ;
if ( * V_9 == 0 )
* V_9 = V_104 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_82 ( T_21 V_11 , T_22 * V_101 , T_9 V_105 , int * V_9 ,
T_10 * * V_94 )
{
F_83 ( V_101 , V_105 ) ;
return F_81 ( V_11 , F_84 ( V_101 ) , V_105 , V_9 ,
V_94 ) ;
}
T_6
F_85 ( T_7 * V_8 )
{
return F_86 ( V_8 -> V_11 ) ;
}
struct V_106 *
F_87 ( T_7 * V_8 )
{
return & V_8 -> V_96 ;
}
T_17 *
F_88 ( T_7 * V_8 )
{
return F_84 ( V_8 -> V_88 ) ;
}
void
F_89 ( struct V_106 * V_96 )
{
memset ( V_96 , 0 , sizeof( struct V_106 ) ) ;
F_90 ( & V_96 -> V_107 , 0 ) ;
}
void
F_91 ( struct V_106 * V_96 )
{
F_66 ( & V_96 -> V_107 ) ;
}
T_1
F_92 ( T_7 * V_8 , T_6 V_108 ,
struct V_106 * V_96 , T_22 * V_101 , int * V_9 , T_10 * * V_94 )
{
V_96 -> V_97 = V_8 -> V_16 ;
V_96 -> V_98 = V_8 -> V_17 ;
if ( ! V_8 -> V_109 ( V_8 , V_108 , V_96 , V_101 , V_9 , V_94 ) )
return FALSE ;
if ( V_96 -> V_100 > V_96 -> V_20 )
V_96 -> V_100 = V_96 -> V_20 ;
F_32 ( V_96 -> V_97 != V_71 ) ;
return TRUE ;
}
