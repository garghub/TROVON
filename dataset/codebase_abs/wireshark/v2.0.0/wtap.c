static T_1
F_1 ( T_2 * V_1 )
{
T_3 V_2 ;
void (* F_2)( void );
T_4 * V_3 ;
if ( ! F_3 ( V_1 , L_1 , & V_2 ) ) {
return FALSE ;
}
F_2 = ( void ( * ) ( void ) ) V_2 ;
V_3 = ( T_4 * ) F_4 ( sizeof ( T_4 ) ) ;
V_3 -> F_2 = F_2 ;
V_4 = F_5 ( V_4 , V_3 ) ;
return TRUE ;
}
void
F_6 ( void )
{
F_7 ( L_2 , F_1 ) ;
}
static void
F_8 ( T_3 V_5 , T_3 T_5 V_6 )
{
T_4 * V_3 = ( T_4 * ) V_5 ;
( V_3 -> F_2 ) ( ) ;
}
void
F_9 ( void )
{
F_10 ( V_4 , F_8 , NULL ) ;
}
T_6
F_11 ( T_7 * V_7 , int * V_8 )
{
T_8 V_9 ;
if ( F_12 ( ( V_7 -> V_10 == NULL ) ? V_7 -> V_11 : V_7 -> V_10 ,
& V_9 , V_8 ) == - 1 )
return - 1 ;
return V_9 . V_12 ;
}
int
F_13 ( T_7 * V_7 , T_8 * V_9 , int * V_8 )
{
if ( F_12 ( ( V_7 -> V_10 == NULL ) ? V_7 -> V_11 : V_7 -> V_10 ,
V_9 , V_8 ) == - 1 )
return - 1 ;
return 0 ;
}
int
F_14 ( T_7 * V_7 )
{
return V_7 -> V_13 ;
}
T_1
F_15 ( T_7 * V_7 )
{
return F_16 ( ( V_7 -> V_10 == NULL ) ? V_7 -> V_11 : V_7 -> V_10 ) ;
}
T_9
F_17 ( T_7 * V_7 )
{
return V_7 -> V_14 ;
}
int
F_18 ( T_7 * V_7 )
{
return V_7 -> V_15 ;
}
int
F_19 ( T_7 * V_7 )
{
return V_7 -> V_16 ;
}
const T_10 *
F_20 ( T_7 * V_7 )
{
return V_7 ? V_7 -> V_17 . V_18 : NULL ;
}
const T_11 *
F_21 ( T_7 * V_7 )
{
return V_7 ? & ( V_7 -> V_17 ) : NULL ;
}
T_11 *
F_22 ( T_7 * V_7 )
{
T_11 * V_17 ;
if ( V_7 == NULL )
return NULL ;
V_17 = F_23 ( T_11 , 1 ) ;
V_17 -> V_19 = - 1 ;
V_17 -> V_18 = F_24 ( V_7 -> V_17 . V_18 ) ;
return V_17 ;
}
const T_10 *
F_25 ( T_7 * V_7 )
{
F_26 ( V_7 ) ;
if ( V_7 == NULL )
return NULL ;
return V_7 -> V_20 ? V_7 -> V_20 -> V_18 : NULL ;
}
void
F_27 ( T_7 * V_7 , T_10 * V_21 )
{
F_26 ( V_7 ) ;
if ( V_7 == NULL )
return;
if ( V_7 -> V_20 == NULL ) {
V_7 -> V_20 = F_23 ( V_22 , 1 ) ;
} else {
F_28 ( V_7 -> V_20 -> V_18 ) ;
}
V_7 -> V_20 -> V_18 = V_21 ;
}
void
F_29 ( T_11 * V_17 )
{
if ( V_17 == NULL )
return;
F_28 ( V_17 -> V_18 ) ;
F_28 ( V_17 -> V_23 ) ;
F_28 ( V_17 -> V_24 ) ;
F_28 ( V_17 -> V_25 ) ;
F_28 ( V_17 ) ;
}
void
F_30 ( T_7 * V_7 , T_10 * V_21 )
{
F_28 ( V_7 -> V_17 . V_18 ) ;
V_7 -> V_17 . V_18 = V_21 ;
}
T_12 *
F_31 ( T_7 * V_7 )
{
T_12 * V_26 ;
V_26 = F_32 ( T_12 , 1 ) ;
V_26 -> V_27 = V_7 -> V_27 ;
return V_26 ;
}
static void
F_33 ( T_13 * V_28 )
{
if ( V_28 ) {
F_28 ( V_28 -> V_18 ) ;
}
}
static void
F_34 ( T_14 * V_29 )
{
if ( V_29 ) {
F_28 ( V_29 -> V_18 ) ;
F_28 ( V_29 -> V_30 ) ;
F_28 ( V_29 -> V_31 ) ;
F_28 ( V_29 -> V_32 ) ;
F_28 ( V_29 -> V_33 ) ;
F_28 ( V_29 -> V_34 ) ;
if ( V_29 -> V_35 ) {
T_13 * V_28 ;
T_9 V_36 ;
for ( V_36 = 0 ; V_36 < V_29 -> V_35 -> V_37 ; V_36 ++ ) {
V_28 = & F_35 ( V_29 -> V_35 , T_13 , V_36 ) ;
F_33 ( V_28 ) ;
}
F_36 ( V_29 -> V_35 , TRUE ) ;
}
}
}
void
F_37 ( T_12 * V_26 )
{
if ( V_26 == NULL )
return;
if ( V_26 -> V_27 ) {
T_9 V_36 ;
for ( V_36 = 0 ; V_36 < V_26 -> V_27 -> V_37 ; V_36 ++ ) {
T_14 * V_29 = & F_35 ( V_26 -> V_27 , T_14 , V_36 ) ;
F_34 ( V_29 ) ;
}
F_36 ( V_26 -> V_27 , TRUE ) ;
}
F_28 ( V_26 ) ;
}
T_10 *
F_38 ( const T_14 * V_38 ,
const int V_39 ,
const char * V_40 )
{
T_15 * V_41 = F_39 ( L_3 ) ;
F_26 ( V_38 ) ;
F_40 ( V_41 ,
L_4 , V_39 , ' ' ,
V_38 -> V_31 ? V_38 -> V_31 : L_5 ,
V_40 ) ;
F_41 ( V_41 ,
L_6 , V_39 , ' ' ,
V_38 -> V_32 ? V_38 -> V_32 : L_7 ,
V_40 ) ;
F_41 ( V_41 ,
L_8 , V_39 , ' ' ,
F_42 ( V_38 -> V_42 ) ,
V_38 -> V_42 ,
V_38 -> V_43 ,
F_43 ( V_38 -> V_42 ) ,
V_40 ) ;
F_41 ( V_41 ,
L_9 V_44 L_10 , V_39 , ' ' ,
V_38 -> V_45 ,
V_40 ) ;
F_41 ( V_41 ,
L_11 , V_39 , ' ' ,
V_38 -> V_46 ,
V_40 ) ;
F_41 ( V_41 ,
L_12 , V_39 , ' ' ,
V_38 -> V_47 ,
V_40 ) ;
F_41 ( V_41 ,
L_13 , V_39 , ' ' ,
F_44 ( V_38 -> V_48 ) ,
V_38 -> V_48 ,
V_40 ) ;
F_41 ( V_41 ,
L_14 V_44 L_10 , V_39 , ' ' ,
V_38 -> V_49 ,
V_40 ) ;
F_41 ( V_41 ,
L_15 , V_39 , ' ' ,
V_38 -> V_50 ,
V_40 ) ;
F_41 ( V_41 ,
L_16 , V_39 , ' ' ,
V_38 -> V_33 ? V_38 -> V_33 : L_7 ,
V_40 ) ;
F_41 ( V_41 ,
L_17 , V_39 , ' ' ,
V_38 -> V_30 ? V_38 -> V_30 : L_5 ,
V_40 ) ;
F_41 ( V_41 ,
L_18 , V_39 , ' ' ,
V_38 -> V_18 ? V_38 -> V_18 : L_7 ,
V_40 ) ;
F_41 ( V_41 ,
L_19 , V_39 , ' ' ,
V_38 -> V_51 ,
V_40 ) ;
F_41 ( V_41 ,
L_20 , V_39 , ' ' ,
V_38 -> V_52 ,
V_40 ) ;
return F_45 ( V_41 , FALSE ) ;
}
V_22 *
F_46 ( T_7 * V_7 )
{
V_22 * V_20 ;
if ( V_7 == NULL || V_7 -> V_20 == NULL )
return NULL ;
V_20 = F_23 ( V_22 , 1 ) ;
V_20 -> V_18 = F_24 ( V_7 -> V_20 -> V_18 ) ;
return V_20 ;
}
void
F_47 ( V_22 * V_20 )
{
if ( V_20 == NULL )
return;
F_28 ( V_20 -> V_18 ) ;
F_28 ( V_20 ) ;
}
static void F_48 ( void ) {
if ( V_53 ) return;
V_53 = F_49 ( FALSE , TRUE , sizeof( struct V_54 ) ) ;
F_50 ( V_53 , V_55 , V_56 ) ;
}
int F_51 ( void ) {
F_48 () ;
return V_56 ;
}
int F_52 ( const char * V_57 , const char * V_58 ) {
struct V_54 V_59 ;
F_48 () ;
V_59 . V_57 = F_24 ( V_57 ) ;
V_59 . V_58 = F_24 ( V_58 ) ;
F_53 ( V_53 , V_59 ) ;
return V_56 ++ ;
}
const char *
F_42 ( int V_60 )
{
if ( V_60 < V_61 || V_60 >= V_62 )
return L_21 ;
else if ( V_60 == V_61 )
return L_22 ;
else
return F_54 ( V_60 ) . V_57 ;
}
const char *
F_43 ( int V_60 )
{
if ( V_60 < V_61 || V_60 >= V_62 )
return L_23 ;
else if ( V_60 == V_61 )
return L_24 ;
else
return F_54 ( V_60 ) . V_58 ;
}
int
F_55 ( const char * V_58 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_62 ; V_60 ++ ) {
if ( F_54 ( V_60 ) . V_58 != NULL &&
strcmp ( V_58 , F_54 ( V_60 ) . V_58 ) == 0 )
return V_60 ;
}
return - 1 ;
}
const char *
F_44 ( int V_63 )
{
const char * V_64 ;
switch ( V_63 ) {
case V_65 :
V_64 = L_24 ;
break;
case V_66 :
V_64 = L_25 ;
break;
case V_67 :
V_64 = L_26 ;
break;
case V_68 :
V_64 = L_27 ;
break;
case V_69 :
V_64 = L_28 ;
break;
case V_70 :
V_64 = L_29 ;
break;
case V_71 :
V_64 = L_30 ;
break;
case V_72 :
default:
V_64 = L_5 ;
break;
}
return V_64 ;
}
const char *
F_56 ( int V_8 )
{
static char V_73 [ 128 ] ;
unsigned int V_74 ;
if ( V_8 < 0 ) {
V_74 = - 1 - V_8 ;
if ( V_74 >= V_75 ) {
F_57 ( V_73 , 128 , L_31 , V_8 ) ;
return V_73 ;
}
if ( V_76 [ V_74 ] == NULL )
return L_32 ;
return V_76 [ V_74 ] ;
} else
return F_58 ( V_8 ) ;
}
void
F_59 ( T_7 * V_7 )
{
if ( V_7 -> V_77 != NULL )
(* V_7 -> V_77 )( V_7 ) ;
if ( V_7 -> V_10 != NULL ) {
F_60 ( V_7 -> V_10 ) ;
V_7 -> V_10 = NULL ;
}
if ( V_7 -> V_78 ) {
F_61 ( V_7 -> V_78 ) ;
F_28 ( V_7 -> V_78 ) ;
V_7 -> V_78 = NULL ;
}
}
static void
F_62 ( T_3 V_5 , T_3 T_5 V_6 )
{
F_28 ( V_5 ) ;
}
void
F_63 ( T_7 * V_7 )
{
if ( V_7 -> V_10 != NULL )
F_64 ( V_7 -> V_10 ) ;
if ( V_7 -> V_11 != NULL )
F_64 ( V_7 -> V_11 ) ;
}
void
F_65 ( T_7 * V_7 )
{
T_9 V_36 , V_79 ;
T_14 * V_80 ;
T_13 * V_81 ;
F_59 ( V_7 ) ;
if ( V_7 -> V_82 != NULL )
(* V_7 -> V_82 )( V_7 ) ;
if ( V_7 -> V_11 != NULL )
F_60 ( V_7 -> V_11 ) ;
if ( V_7 -> V_83 != NULL )
F_28 ( V_7 -> V_83 ) ;
if ( V_7 -> V_84 != NULL ) {
F_66 ( V_7 -> V_84 , F_62 , NULL ) ;
F_67 ( V_7 -> V_84 , TRUE ) ;
}
F_28 ( V_7 -> V_17 . V_18 ) ;
F_28 ( V_7 -> V_17 . V_23 ) ;
F_28 ( V_7 -> V_17 . V_24 ) ;
F_28 ( V_7 -> V_17 . V_25 ) ;
for( V_36 = 0 ; V_36 < V_7 -> V_27 -> V_37 ; V_36 ++ ) {
V_80 = & F_35 ( V_7 -> V_27 , T_14 , V_36 ) ;
if( V_80 -> V_18 != NULL ) {
F_28 ( V_80 -> V_18 ) ;
}
if( V_80 -> V_31 != NULL ) {
F_28 ( V_80 -> V_31 ) ;
}
if( V_80 -> V_32 != NULL ) {
F_28 ( V_80 -> V_32 ) ;
}
if( V_80 -> V_33 != NULL ) {
F_28 ( V_80 -> V_33 ) ;
}
if( V_80 -> V_34 != NULL ) {
F_28 ( V_80 -> V_34 ) ;
}
if( V_80 -> V_30 != NULL ) {
F_28 ( V_80 -> V_30 ) ;
}
for( V_79 = 0 ; V_79 < V_80 -> V_52 ; V_79 ++ ) {
V_81 = & F_35 ( V_80 -> V_35 , T_13 , V_79 ) ;
if( V_81 -> V_18 != NULL ) {
F_28 ( V_81 -> V_18 ) ;
}
}
if( V_80 -> V_52 != 0 ) {
F_36 ( V_80 -> V_35 , TRUE ) ;
}
}
F_36 ( V_7 -> V_27 , TRUE ) ;
F_28 ( V_7 ) ;
}
void
F_68 ( T_7 * V_7 ) {
F_69 ( V_7 -> V_10 ) ;
}
void F_70 ( T_7 * V_7 , T_16 V_85 ) {
if ( V_7 )
V_7 -> V_85 = V_85 ;
}
void F_71 ( T_7 * V_7 , T_17 V_86 ) {
if ( V_7 )
V_7 -> V_86 = V_86 ;
}
T_1
F_72 ( T_7 * V_7 , int * V_8 , T_10 * * V_87 , T_6 * V_88 )
{
V_7 -> V_89 . V_90 = V_7 -> V_15 ;
V_7 -> V_89 . V_91 = V_7 -> V_16 ;
* V_8 = 0 ;
* V_87 = NULL ;
if ( ! V_7 -> V_92 ( V_7 , V_8 , V_87 , V_88 ) ) {
if ( * V_8 == 0 )
* V_8 = F_73 ( V_7 -> V_10 , V_87 ) ;
return FALSE ;
}
if ( V_7 -> V_89 . V_93 > V_7 -> V_89 . V_37 )
V_7 -> V_89 . V_93 = V_7 -> V_89 . V_37 ;
F_26 ( V_7 -> V_89 . V_90 != V_61 ) ;
return TRUE ;
}
T_1
F_74 ( T_18 V_10 , void * V_94 , unsigned int V_95 , int * V_8 ,
T_10 * * V_87 )
{
int V_96 ;
V_96 = F_75 ( V_94 , V_95 , V_10 ) ;
if ( V_96 < 0 || ( T_9 ) V_96 != V_95 ) {
* V_8 = F_73 ( V_10 , V_87 ) ;
if ( * V_8 == 0 && V_96 > 0 )
* V_8 = V_97 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_76 ( T_18 V_10 , void * V_94 , unsigned int V_95 , int * V_8 ,
T_10 * * V_87 )
{
int V_96 ;
V_96 = F_75 ( V_94 , V_95 , V_10 ) ;
if ( V_96 < 0 || ( T_9 ) V_96 != V_95 ) {
* V_8 = F_73 ( V_10 , V_87 ) ;
if ( * V_8 == 0 )
* V_8 = V_97 ;
return FALSE ;
}
return TRUE ;
}
T_1
F_77 ( T_18 V_10 , T_19 * V_94 , T_9 V_98 , int * V_8 ,
T_10 * * V_87 )
{
F_78 ( V_94 , V_98 ) ;
return F_76 ( V_10 , F_79 ( V_94 ) , V_98 , V_8 ,
V_87 ) ;
}
T_6
F_80 ( T_7 * V_7 )
{
return F_81 ( V_7 -> V_10 ) ;
}
struct V_99 *
F_82 ( T_7 * V_7 )
{
return & V_7 -> V_89 ;
}
T_20 *
F_83 ( T_7 * V_7 )
{
return F_79 ( V_7 -> V_78 ) ;
}
void
F_84 ( struct V_99 * V_89 )
{
memset ( V_89 , 0 , sizeof( struct V_99 ) ) ;
F_85 ( & V_89 -> V_100 , 0 ) ;
}
void
F_86 ( struct V_99 * V_89 )
{
F_61 ( & V_89 -> V_100 ) ;
}
T_1
F_87 ( T_7 * V_7 , T_6 V_101 ,
struct V_99 * V_89 , T_19 * V_94 , int * V_8 , T_10 * * V_87 )
{
if ( ! V_7 -> V_102 ( V_7 , V_101 , V_89 , V_94 , V_8 , V_87 ) )
return FALSE ;
if ( V_89 -> V_93 > V_89 -> V_37 )
V_89 -> V_93 = V_89 -> V_37 ;
F_26 ( V_89 -> V_90 != V_61 ) ;
return TRUE ;
}
