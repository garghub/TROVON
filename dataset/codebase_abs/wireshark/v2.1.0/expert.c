static T_1 F_1 ( void * V_1 , char * * V_2 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
if ( F_2 ( V_3 -> V_4 ) == NULL ) {
* V_2 = F_3 ( L_1 ) ;
return FALSE ;
}
return TRUE ;
}
static void * F_4 ( void * V_5 , const void * V_6 , T_3 T_4 V_7 )
{
T_2 * V_8 = ( T_2 * ) V_5 ;
const T_2 * V_9 = ( const T_2 * ) V_6 ;
if ( V_9 -> V_4 ) {
V_8 -> V_4 = F_5 ( V_9 -> V_4 ) ;
} else {
V_8 -> V_4 = NULL ;
}
V_8 -> V_10 = V_9 -> V_10 ;
return V_8 ;
}
static void F_6 ( void * V_1 )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
if ( V_3 -> V_4 )
F_7 ( V_3 -> V_4 ) ;
}
static void F_8 ( void )
{
T_5 V_11 ;
T_6 * V_4 ;
for ( V_11 = 0 ; V_11 < V_12 -> V_13 ; V_11 ++ ) {
V_4 = F_9 ( V_12 , T_6 * , V_11 ) ;
if ( V_4 != NULL ) {
V_4 -> V_10 = V_4 -> V_14 ;
}
}
F_10 ( V_12 , 0 ) ;
for ( V_11 = 0 ; V_11 < V_15 ; V_11 ++ )
{
V_4 = F_2 ( V_16 [ V_11 ] . V_4 ) ;
if ( V_4 != NULL )
{
V_4 -> V_10 = V_16 [ V_11 ] . V_10 ;
F_11 ( V_12 , V_4 ) ;
}
}
}
void
F_12 ( void )
{
T_7 * V_17 ;
T_8 * V_18 ;
static T_9 V_19 [] = {
{ & V_20 ,
{ L_2 , L_3 , V_21 , V_22 , NULL , 0 , L_4 , V_23 }
} ,
{ & V_24 ,
{ L_5 , L_6 , V_25 , V_26 , F_13 ( V_27 ) , 0 , L_7 , V_23 }
} ,
{ & V_28 ,
{ L_8 , L_9 , V_25 , V_26 , F_13 ( V_29 ) , 0 , L_10 , V_23 }
}
} ;
static T_10 * V_30 [] = {
& V_31 ,
& V_32
} ;
static T_11 V_33 [] = {
F_14 ( V_16 , V_4 , L_11 , L_12 ) ,
F_15 ( V_16 , V_10 , L_13 , V_29 , L_14 ) ,
V_34
} ;
if ( V_35 == - 1 ) {
V_35 = F_16 ( L_15 ) ;
}
if ( V_36 == - 1 ) {
V_36 = F_17 ( L_16 , L_17 , L_18 ) ;
F_18 ( V_36 , V_19 , F_19 ( V_19 ) ) ;
F_20 ( V_30 , F_19 ( V_30 ) ) ;
F_21 ( V_36 ) ;
V_17 = F_22 ( V_36 , NULL ) ;
V_18 = F_23 ( L_19 ,
sizeof( T_2 ) ,
L_20 ,
TRUE ,
( void * * ) & V_16 ,
& V_15 ,
V_37 ,
NULL ,
F_4 ,
F_1 ,
F_6 ,
F_8 ,
V_33 ) ;
F_24 ( V_17 ,
L_21 ,
L_22 ,
L_23 ,
V_18 ) ;
}
V_38 = 0 ;
V_39 = F_25 ( L_24 ) ;
}
void
F_26 ( void )
{
V_40 . V_13 = 0 ;
V_40 . V_41 = 0 ;
V_40 . V_42 = NULL ;
V_43 = F_27 ( V_44 , V_45 , NULL , NULL ) ;
V_12 = F_28 ( FALSE , FALSE , sizeof( T_6 * ) ) ;
V_46 = F_29 () ;
}
void
F_30 ( void )
{
}
void
F_31 ( void )
{
if ( V_40 . V_41 ) {
V_40 . V_13 = 0 ;
V_40 . V_41 = 0 ;
F_7 ( V_40 . V_42 ) ;
V_40 . V_42 = NULL ;
}
if ( V_43 ) {
F_32 ( V_43 ) ;
V_43 = NULL ;
}
if ( V_12 ) {
F_33 ( V_12 , TRUE ) ;
V_12 = NULL ;
}
if ( V_46 ) {
F_34 ( V_46 , FALSE ) ;
V_46 = NULL ;
}
}
int
F_35 ( void )
{
return V_38 ;
}
void
F_36 ( T_12 V_47 )
{
if ( V_47 == 0 && V_38 == V_48 )
V_38 = 0 ;
}
T_13 * F_37 ( int V_49 )
{
T_13 * V_50 ;
T_14 * V_51 ;
V_51 = F_38 ( V_49 ) ;
V_50 = F_39 ( F_40 () , T_13 ) ;
V_50 -> V_52 = V_49 ;
V_50 -> V_53 = F_41 ( V_51 ) ;
return V_50 ;
}
void
F_42 ( const char * V_54 )
{
T_6 * V_55 = ( T_6 * ) F_43 ( V_43 , V_54 ) ;
if ( V_55 ) {
F_44 ( V_46 , V_40 . V_42 [ V_55 -> V_49 ] ) ;
F_45 ( V_43 , V_54 ) ;
}
}
void
F_46 ( T_13 * V_50 )
{
F_47 ( F_40 () , V_50 ) ;
}
static void
F_48 ( T_15 V_56 , T_15 T_16 V_7 )
{
T_6 * V_55 = ( T_6 * ) V_56 ;
V_40 . V_42 [ V_55 -> V_49 ] = NULL ;
}
void
F_49 ( void )
{
F_50 ( V_46 , F_48 , NULL ) ;
F_34 ( V_46 , TRUE ) ;
V_46 = F_29 () ;
}
static int
F_51 ( T_6 * V_55 , T_13 * V_50 )
{
V_55 -> V_51 = V_50 -> V_53 ;
if ( V_40 . V_13 >= V_40 . V_41 ) {
if ( ! V_40 . V_42 ) {
V_40 . V_41 = V_57 ;
V_40 . V_42 = ( T_6 * * ) F_52 ( sizeof( T_6 * ) * V_57 ) ;
} else {
V_40 . V_41 += 1000 ;
V_40 . V_42 = ( T_6 * * ) F_53 ( V_40 . V_42 ,
sizeof( T_6 * ) * V_40 . V_41 ) ;
}
}
V_40 . V_42 [ V_40 . V_13 ] = V_55 ;
V_40 . V_13 ++ ;
V_55 -> V_49 = V_40 . V_13 - 1 ;
V_55 -> V_14 = V_55 -> V_10 ;
F_54 ( V_43 , ( T_15 ) ( V_55 -> V_58 ) , V_55 ) ;
return V_55 -> V_49 ;
}
void
F_55 ( T_13 * V_50 , T_17 * exp , const int V_59 )
{
int V_11 ;
T_17 * V_60 = exp ;
for ( V_11 = 0 ; V_11 < V_59 ; V_11 ++ , V_60 ++ ) {
if ( V_60 -> V_61 -> V_42 != - 1 && V_60 -> V_61 -> V_42 != 0 ) {
fprintf ( V_62 ,
L_25 ,
V_60 -> V_63 . V_64 , V_60 -> V_63 . V_58 ) ;
return;
}
V_60 -> V_61 -> V_42 = F_51 ( & V_60 -> V_63 , V_50 ) ;
V_60 -> V_63 . V_65 . V_66 = & V_60 -> V_61 -> V_19 ;
V_60 -> V_63 . V_65 . V_67 . V_54 = V_60 -> V_63 . V_58 ;
V_60 -> V_63 . V_65 . V_67 . V_68 = V_60 -> V_63 . V_64 ;
F_18 ( V_50 -> V_52 , & V_60 -> V_63 . V_65 , 1 ) ;
}
}
static T_6 *
F_2 ( const char * V_69 )
{
T_6 * V_67 ;
if ( ! V_69 )
return NULL ;
V_67 = ( T_6 * ) F_43 ( V_43 , V_69 ) ;
return V_67 ;
}
const T_18 * F_56 ( T_19 * V_70 )
{
T_6 * V_63 ;
F_57 ( V_70 -> V_42 , V_63 ) ;
return V_63 -> V_64 ;
}
static void
F_58 ( T_20 * V_71 , const int V_72 , const T_5 V_10 )
{
if ( V_71 != NULL && F_59 ( V_71 ) != NULL && ( V_10 >= F_60 ( F_59 ( V_71 ) , V_73 ) ) ) {
F_61 ( F_59 ( V_71 ) , V_74 , V_72 ) ;
F_61 ( F_59 ( V_71 ) , V_73 , V_10 ) ;
V_71 = F_62 ( V_71 ) ;
F_58 ( V_71 , V_72 , V_10 ) ;
}
}
static T_21 *
F_63 ( T_20 * V_71 , int V_72 , int V_10 , const char * V_75 )
{
T_21 * V_76 ;
T_20 * V_77 ;
V_76 = F_64 ( V_71 , V_31 ) ;
V_77 = F_65 ( V_76 , V_36 , NULL , 0 , 0 , L_26 ,
F_66 ( V_10 , V_29 , L_27 ) ,
F_66 ( V_72 , V_27 , L_27 ) ,
V_75 ) ;
F_67 ( V_77 ) ;
if ( V_72 == V_78 ) {
T_20 * V_79 = F_68 ( V_76 , V_39 , NULL , 0 , 0 , V_80 ) ;
F_69 ( V_79 ) ;
}
return F_64 ( V_77 , V_32 ) ;
}
static void
F_70 ( T_22 * V_81 , T_20 * V_71 , int V_72 , int V_10 , int V_82 , T_1 V_83 ,
const char * V_84 , T_23 V_85 )
{
char V_86 [ V_87 ] ;
int V_88 ;
T_24 * V_42 ;
T_21 * V_76 ;
T_20 * V_77 ;
if ( V_81 == NULL && V_71 && V_71 -> V_89 ) {
V_81 = F_71 ( V_71 ) -> V_81 ;
}
if ( V_81 == NULL || V_81 -> V_90 == 0 ) {
return;
}
if ( V_10 > V_38 ) {
V_38 = V_10 ;
}
if ( V_71 != NULL && F_59 ( V_71 ) != NULL ) {
F_58 ( V_71 , V_72 , V_10 ) ;
}
if ( ( V_71 == NULL ) || ( F_59 ( V_71 ) == NULL ) ||
( ( T_5 ) V_10 >= F_60 ( F_59 ( V_71 ) , V_73 ) ) ) {
F_72 ( V_81 -> V_91 , V_92 , F_66 ( V_10 , V_29 , L_27 ) ) ;
}
if ( V_83 ) {
F_73 ( V_86 , V_87 , V_84 , V_85 ) ;
} else {
F_74 ( V_86 , V_84 , V_87 ) ;
}
V_76 = F_63 ( V_71 , V_72 , V_10 , V_86 ) ;
if ( V_82 == - 1 ) {
V_77 = F_75 ( V_76 , V_20 , NULL , 0 , 0 , V_86 ) ;
F_67 ( V_77 ) ;
} else {
V_77 = F_76 ( V_76 , V_82 , NULL , 0 , 0 , L_28 , V_86 ) ;
F_67 ( V_77 ) ;
V_77 = F_75 ( V_76 , V_20 , NULL , 0 , 0 , V_86 ) ;
F_69 ( V_77 ) ;
}
V_77 = F_77 ( V_76 , V_28 , NULL , 0 , 0 , V_10 ,
L_28 , F_78 ( V_10 , V_29 , L_29 ) ) ;
F_67 ( V_77 ) ;
V_77 = F_77 ( V_76 , V_24 , NULL , 0 , 0 , V_72 ,
L_28 , F_78 ( V_72 , V_27 , L_29 ) ) ;
F_67 ( V_77 ) ;
V_88 = F_79 ( V_35 ) ;
if ( ! V_88 )
return;
V_42 = F_39 ( F_80 () , T_24 ) ;
V_42 -> V_93 = V_81 -> V_90 ;
V_42 -> V_72 = V_72 ;
V_42 -> V_10 = V_10 ;
V_42 -> V_82 = V_82 ;
V_42 -> V_51 = V_81 -> V_94 ;
V_42 -> V_64 = F_81 ( F_80 () , V_86 ) ;
if ( V_71 != NULL && F_59 ( V_71 ) != NULL ) {
V_42 -> V_95 = V_71 ;
}
else {
V_42 -> V_95 = NULL ;
}
F_82 ( V_35 , V_81 , V_42 ) ;
}
static inline void
F_83 ( T_22 * V_81 , T_20 * V_71 , T_19 * V_96 , ... )
{
T_23 V_97 ;
T_6 * V_63 ;
F_57 ( V_96 -> V_42 , V_63 ) ;
va_start ( V_97 , V_96 ) ;
F_70 ( V_81 , V_71 , V_63 -> V_72 , V_63 -> V_10 , * V_63 -> V_65 . V_66 , FALSE , V_63 -> V_64 , V_97 ) ;
va_end ( V_97 ) ;
}
void
F_84 ( T_22 * V_81 , T_20 * V_71 , T_19 * V_96 )
{
F_83 ( V_81 , V_71 , V_96 ) ;
}
void
F_85 ( T_22 * V_81 , T_20 * V_71 , T_19 * V_96 , const char * V_84 , ... )
{
T_23 V_85 ;
T_6 * V_63 ;
F_57 ( V_96 -> V_42 , V_63 ) ;
va_start ( V_85 , V_84 ) ;
F_70 ( V_81 , V_71 , V_63 -> V_72 , V_63 -> V_10 , * V_63 -> V_65 . V_66 , TRUE , V_84 , V_85 ) ;
va_end ( V_85 ) ;
}
static inline T_20 *
F_86 ( T_21 * V_76 , T_22 * V_81 , T_19 * V_96 ,
T_25 * V_98 , T_10 V_99 , T_10 V_100 , ... )
{
T_6 * V_63 ;
T_20 * V_77 ;
T_23 V_97 ;
F_57 ( V_96 -> V_42 , V_63 ) ;
V_77 = F_87 ( V_76 , V_98 , V_99 , V_100 , L_28 , V_63 -> V_64 ) ;
va_start ( V_97 , V_100 ) ;
F_70 ( V_81 , V_77 , V_63 -> V_72 , V_63 -> V_10 , * V_63 -> V_65 . V_66 , FALSE , V_63 -> V_64 , V_97 ) ;
va_end ( V_97 ) ;
return V_77 ;
}
T_20 *
F_88 ( T_21 * V_76 , T_22 * V_81 , T_19 * V_96 ,
T_25 * V_98 , T_10 V_99 , T_10 V_100 )
{
return F_86 ( V_76 , V_81 , V_96 , V_98 , V_99 , V_100 ) ;
}
T_20 *
F_89 ( T_21 * V_76 , T_22 * V_81 , T_19 * V_96 ,
T_25 * V_98 , T_10 V_99 , T_10 V_100 , const char * V_84 , ... )
{
T_23 V_85 ;
T_6 * V_63 ;
T_20 * V_77 ;
F_57 ( V_96 -> V_42 , V_63 ) ;
va_start ( V_85 , V_84 ) ;
V_77 = F_90 ( V_76 , V_98 , V_99 , V_100 , V_84 , V_85 ) ;
va_end ( V_85 ) ;
va_start ( V_85 , V_84 ) ;
F_70 ( V_81 , V_77 , V_63 -> V_72 , V_63 -> V_10 , * V_63 -> V_65 . V_66 , TRUE , V_84 , V_85 ) ;
va_end ( V_85 ) ;
return V_77 ;
}
