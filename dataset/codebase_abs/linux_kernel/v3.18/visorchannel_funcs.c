static T_1 *
F_1 ( T_2 V_1 , T_3 V_2 ,
T_1 * V_3 , T_3 V_4 , T_4 V_5 ,
BOOL V_6 )
{
T_1 * V_7 = NULL ;
void * V_8 = NULL ;
V_7 = F_2 ( sizeof( T_1 ) , V_9 | V_10 ) ;
if ( V_7 == NULL ) {
F_3 ( L_1 ) ;
V_8 = NULL ;
goto V_11;
}
V_7 -> V_12 = NULL ;
V_7 -> V_6 = V_6 ;
F_4 ( & V_7 -> V_13 ) ;
F_4 ( & V_7 -> V_14 ) ;
if ( V_3 == NULL )
V_7 -> V_12 =
F_5 ( V_1 , sizeof( V_15 ) ) ;
else
V_7 -> V_12 =
F_6 ( V_3 -> V_12 ,
V_4 ,
sizeof( V_15 ) ) ;
if ( V_7 -> V_12 == NULL ) {
F_3 ( L_2 ) ;
V_8 = NULL ;
goto V_11;
}
if ( F_7 ( V_7 -> V_12 , 0 , & V_7 -> V_16 ,
sizeof( V_15 ) ) < 0 ) {
F_3 ( L_3 ) ;
V_8 = NULL ;
goto V_11;
}
if ( V_2 == 0 )
V_2 = ( T_3 ) V_7 -> V_16 . V_17 ;
if ( F_8 ( V_5 , V_18 ) == 0 )
V_5 = V_7 -> V_16 . Type ;
if ( F_9 ( V_7 -> V_12 , V_2 ) < 0 ) {
F_3 ( L_4 ) ;
V_8 = NULL ;
goto V_11;
}
V_7 -> V_19 = V_2 ;
V_7 -> V_5 = V_5 ;
V_8 = V_7 ;
V_11:
if ( V_8 == NULL ) {
if ( V_7 != NULL ) {
F_10 ( V_7 ) ;
V_7 = NULL ;
}
}
return V_8 ;
}
T_1 *
F_11 ( T_2 V_1 , T_3 V_2 , T_4 V_5 )
{
return F_1 ( V_1 , V_2 , NULL , 0 , V_5 ,
FALSE ) ;
}
T_1 *
F_12 ( T_2 V_1 , T_3 V_2 ,
T_4 V_5 )
{
return F_1 ( V_1 , V_2 , NULL , 0 , V_5 ,
TRUE ) ;
}
T_1 *
F_13 ( T_3 V_2 ,
T_1 * V_3 , T_3 V_4 , T_4 V_5 )
{
return F_1 ( 0 , V_2 , V_3 , V_4 , V_5 ,
FALSE ) ;
}
T_1 *
F_14 ( T_3 V_2 ,
T_1 * V_3 , T_3 V_4 ,
T_4 V_5 )
{
return F_1 ( 0 , V_2 , V_3 , V_4 , V_5 ,
TRUE ) ;
}
void
F_10 ( T_1 * V_20 )
{
if ( V_20 == NULL )
return;
if ( V_20 -> V_12 != NULL ) {
F_15 ( V_20 -> V_12 ) ;
V_20 -> V_12 = NULL ;
}
F_16 ( V_20 ) ;
}
T_2
F_17 ( T_1 * V_20 )
{
return F_18 ( V_20 -> V_12 ) ;
}
T_3
F_19 ( T_1 * V_20 )
{
return V_20 -> V_19 ;
}
char *
F_20 ( T_4 * V_5 , char * V_21 )
{
sprintf ( V_21 , L_5 , V_5 ) ;
return V_21 ;
}
char *
F_21 ( T_1 * V_20 , char * V_21 )
{
return F_20 ( & V_20 -> V_5 , V_21 ) ;
}
char *
F_22 ( T_1 * V_20 , char * V_21 )
{
return F_20 ( & V_20 -> V_16 . V_22 , V_21 ) ;
}
T_2
F_23 ( T_1 * V_20 )
{
return V_20 -> V_16 . V_23 ;
}
T_4
F_24 ( T_1 * V_20 )
{
return V_20 -> V_5 ;
}
T_5 *
F_25 ( T_1 * V_20 )
{
return V_20 -> V_12 ;
}
int
F_26 ( T_1 * V_20 , T_3 V_24 ,
void * V_25 , T_3 V_26 )
{
int V_8 = F_7 ( V_20 -> V_12 , V_24 ,
V_25 , V_26 ) ;
if ( ( V_8 >= 0 ) && ( V_24 == 0 ) && ( V_26 >= sizeof( V_15 ) ) )
memcpy ( & V_20 -> V_16 , V_25 , sizeof( V_15 ) ) ;
return V_8 ;
}
int
F_27 ( T_1 * V_20 , T_3 V_24 ,
void * V_25 , T_3 V_26 )
{
if ( V_24 == 0 && V_26 >= sizeof( V_15 ) )
memcpy ( & V_20 -> V_16 , V_25 , sizeof( V_15 ) ) ;
return F_28 ( V_20 -> V_12 , V_24 , V_25 , V_26 ) ;
}
int
F_29 ( T_1 * V_20 , T_3 V_24 , T_6 V_27 , T_3 V_26 )
{
int V_8 = - 1 ;
int V_28 = 65536 ;
int V_29 = 0 ;
T_6 * V_30 = F_30 ( V_28 ) ;
if ( V_30 == NULL ) {
F_3 ( L_6 , V_31 ) ;
goto V_11;
}
memset ( V_30 , V_27 , V_28 ) ;
while ( V_26 > 0 ) {
T_3 V_32 = V_28 ;
int V_33 = - 1 ;
if ( V_26 < V_32 )
V_32 = V_26 ;
V_33 = F_28 ( V_20 -> V_12 , V_24 + V_29 ,
V_30 , V_32 ) ;
if ( V_33 < 0 ) {
V_8 = V_33 ;
goto V_11;
}
V_29 += V_32 ;
V_26 -= V_32 ;
}
V_8 = 0 ;
V_11:
if ( V_30 != NULL ) {
F_31 ( V_30 ) ;
V_30 = NULL ;
}
return V_8 ;
}
void T_7 *
F_32 ( T_1 * V_20 )
{
return ( void T_7 * ) & ( V_20 -> V_16 ) ;
}
static BOOL
F_33 ( T_1 * V_20 , T_8 V_34 ,
T_9 * V_35 )
{
BOOL V_8 = FALSE ;
if ( V_20 -> V_16 . V_36 < sizeof( V_15 ) ) {
F_3 ( L_7 , V_8 ) ;
goto V_11;
}
if ( F_7 ( V_20 -> V_12 ,
F_34 ( & V_20 -> V_16 , V_34 ) ,
V_35 , sizeof( T_9 ) ) < 0 ) {
F_3 ( L_8 ,
V_34 , ( int ) F_34 ( & V_20 -> V_16 , V_34 ) ) ;
F_3 ( L_9 , V_8 ) ;
goto V_11;
}
V_8 = TRUE ;
V_11:
return V_8 ;
}
static BOOL
F_35 ( T_1 * V_20 , T_8 V_34 ,
T_9 * V_35 , T_8 V_37 , void * V_38 , BOOL V_39 )
{
BOOL V_8 = FALSE ;
int V_40 = F_36 ( & V_20 -> V_16 , V_34 ,
V_35 , V_37 ) ;
if ( V_39 ) {
if ( F_28 ( V_20 -> V_12 ,
V_40 ,
V_38 , V_35 -> V_41 ) < 0 ) {
F_3 ( L_10 , V_8 ) ;
goto V_11;
}
} else {
if ( F_7 ( V_20 -> V_12 , V_40 ,
V_38 , V_35 -> V_41 ) < 0 ) {
F_3 ( L_11 , V_8 ) ;
goto V_11;
}
}
V_8 = TRUE ;
V_11:
return V_8 ;
}
static inline BOOL
F_37 ( T_1 * V_20 , T_8 V_34 ,
T_9 * V_35 , T_8 V_37 , void * V_38 )
{
return F_35 ( V_20 , V_34 , V_35 , V_37 , V_38 , FALSE ) ;
}
static inline BOOL
F_38 ( T_1 * V_20 , T_8 V_34 ,
T_9 * V_35 , T_8 V_37 , void * V_38 )
{
return F_35 ( V_20 , V_34 , V_35 , V_37 , V_38 , TRUE ) ;
}
static inline unsigned char
F_39 ( T_10 V_42 ,
T_10 V_43 ,
T_8 * V_44 , T_8 * V_45 )
{
if ( ( * V_44 >= V_42 -> V_46 )
|| ( * V_45 >= V_42 -> V_46 ) ) {
* V_44 = 0 ;
* V_45 = 0 ;
V_43 -> V_47 = * V_44 ;
V_43 -> V_48 = * V_45 ;
F_3 ( L_12 ,
* V_44 , * V_45 , V_42 -> V_46 ) ;
return 0 ;
}
return 1 ;
}
BOOL
F_40 ( T_1 * V_20 , T_8 V_34 , void * V_49 )
{
BOOL V_8 = FALSE ;
T_9 V_35 ;
if ( V_20 -> V_6 )
F_41 ( & V_20 -> V_14 ) ;
if ( ! F_33 ( V_20 , V_34 , & V_35 ) ) {
V_8 = FALSE ;
goto V_11;
}
if ( V_35 . V_47 == V_35 . V_48 ) {
V_8 = FALSE ;
goto V_11;
}
V_35 . V_48 = ( V_35 . V_48 + 1 ) % V_35 . V_46 ;
if ( ! F_37 ( V_20 , V_34 , & V_35 , V_35 . V_48 , V_49 ) ) {
F_3 ( L_13 , V_8 ) ;
goto V_11;
}
V_35 . V_50 ++ ;
F_42 () ;
if ( ! F_43 ( V_20 , V_34 , & V_35 , V_48 ) ) {
F_3 ( L_14 ,
V_8 ) ;
goto V_11;
}
if ( ! F_43 ( V_20 , V_34 , & V_35 , V_50 ) ) {
F_3 ( L_15 , V_8 ) ;
goto V_11;
}
V_8 = TRUE ;
V_11:
if ( V_20 -> V_6 )
F_44 ( & V_20 -> V_14 ) ;
return V_8 ;
}
BOOL
F_45 ( T_1 * V_20 , T_8 V_34 , void * V_49 )
{
BOOL V_8 = FALSE ;
T_9 V_35 ;
if ( V_20 -> V_6 )
F_41 ( & V_20 -> V_13 ) ;
if ( ! F_33 ( V_20 , V_34 , & V_35 ) ) {
V_8 = FALSE ;
goto V_11;
}
V_35 . V_47 = ( ( V_35 . V_47 + 1 ) % V_35 . V_46 ) ;
if ( V_35 . V_47 == V_35 . V_48 ) {
V_35 . V_51 ++ ;
if ( ! F_43 ( V_20 , V_34 , & V_35 , V_51 ) ) {
F_3 ( L_16 , V_8 ) ;
goto V_11;
}
V_8 = FALSE ;
goto V_11;
}
if ( ! F_38 ( V_20 , V_34 , & V_35 , V_35 . V_47 , V_49 ) ) {
F_3 ( L_17 , V_8 ) ;
goto V_11;
}
V_35 . V_52 ++ ;
F_42 () ;
if ( ! F_43 ( V_20 , V_34 , & V_35 , V_47 ) ) {
F_3 ( L_18 ,
V_8 ) ;
goto V_11;
}
if ( ! F_43 ( V_20 , V_34 , & V_35 , V_52 ) ) {
F_3 ( L_19 , V_8 ) ;
goto V_11;
}
V_8 = TRUE ;
V_11:
if ( V_20 -> V_6 )
F_44 ( & V_20 -> V_13 ) ;
return V_8 ;
}
int
F_46 ( T_1 * V_20 , T_8 V_34 )
{
T_9 V_35 ;
T_8 V_53 , V_54 ;
T_8 V_55 , V_56 ;
if ( ! F_33 ( V_20 , V_34 , & V_35 ) )
return 0 ;
V_55 = V_35 . V_47 ;
V_56 = V_35 . V_48 ;
if ( V_55 < V_56 )
V_55 = V_55 + V_35 . V_46 ;
V_54 = ( V_55 - V_56 ) ;
V_53 = V_35 . V_57 - V_54 ;
return ( int ) V_53 ;
}
int
F_47 ( T_1 * V_20 , T_8 V_34 )
{
T_9 V_35 ;
if ( ! F_33 ( V_20 , V_34 , & V_35 ) )
return 0 ;
return ( int ) V_35 . V_57 ;
}
static void
F_48 ( T_9 * V_58 , int V_59 , struct V_60 * V_61 )
{
F_49 ( V_61 , L_20 , V_59 ) ;
F_49 ( V_61 , L_21 , ( T_3 ) V_58 -> V_62 ) ;
F_49 ( V_61 , L_22 , ( T_3 ) V_58 -> Type ) ;
F_49 ( V_61 , L_23 ,
( long long ) V_58 -> V_63 ) ;
F_49 ( V_61 , L_24 , ( T_3 ) V_58 -> V_41 ) ;
F_49 ( V_61 , L_25 ,
( T_3 ) V_58 -> V_46 ) ;
F_49 ( V_61 , L_26 , ( T_3 ) V_58 -> V_57 ) ;
F_49 ( V_61 , L_27 ,
( long long ) V_58 -> V_64 ) ;
F_49 ( V_61 , L_28 ,
( long long ) V_58 -> V_52 ) ;
F_49 ( V_61 , L_29 ,
( long long ) V_58 -> V_50 ) ;
F_49 ( V_61 , L_30 ,
( long long ) V_58 -> V_51 ) ;
F_49 ( V_61 , L_31 , ( T_3 ) V_58 -> V_47 ) ;
F_49 ( V_61 , L_32 , ( T_3 ) V_58 -> V_48 ) ;
}
void
F_50 ( T_1 * V_20 , int V_65 ,
struct V_60 * V_61 , T_8 V_4 )
{
T_2 V_66 = 0 ;
T_3 V_26 = 0 , V_67 = 0 ;
T_5 * V_12 = NULL ;
V_15 V_68 ;
V_15 * V_69 = & V_68 ;
int V_70 = 0 ;
int V_71 = 0 ;
if ( V_20 == NULL ) {
F_3 ( L_33 , V_31 ) ;
return;
}
V_12 = V_20 -> V_12 ;
if ( V_12 == NULL ) {
F_3 ( L_34 , V_31 ) ;
return;
}
V_66 = F_18 ( V_12 ) ;
V_67 = F_51 ( V_12 ) ;
V_71 = F_26 ( V_20 , V_4 ,
V_69 , sizeof( V_15 ) ) ;
if ( V_71 < 0 ) {
F_49 ( V_61 ,
L_35 ,
V_71 ) ;
if ( V_4 == 0 ) {
V_69 = & V_20 -> V_16 ;
F_52 ( V_61 , L_36 ) ;
} else
return;
}
V_26 = ( T_3 ) ( V_69 -> V_17 ) ;
F_49 ( V_61 , L_37 ,
V_66 + V_4 , V_26 , V_67 ) ;
F_49 ( V_61 , L_38 , & V_69 -> Type ) ;
F_49 ( V_61 , L_39 , & V_69 -> V_22 ) ;
F_49 ( V_61 , L_40 ,
( long long ) V_69 -> V_72 ) ;
F_49 ( V_61 , L_41 , ( T_3 ) V_69 -> V_73 ) ;
F_49 ( V_61 , L_42 , ( T_3 ) V_69 -> V_74 ) ;
F_49 ( V_61 , L_43 , ( T_3 ) V_69 -> V_75 ) ;
F_49 ( V_61 , L_44 , ( T_3 ) V_69 -> V_76 ) ;
F_49 ( V_61 , L_45 , ( T_3 ) V_69 -> V_77 ) ;
F_49 ( V_61 , L_46 , ( long long ) V_69 -> V_17 ) ;
F_49 ( V_61 , L_47 ,
( long long ) V_69 -> V_78 ) ;
F_49 ( V_61 , L_48 ,
( long long ) V_69 -> V_23 ) ;
F_49 ( V_61 , L_49 ,
( long long ) V_69 -> V_79 ) ;
F_49 ( V_61 , L_50 , ( T_3 ) V_69 -> V_62 ) ;
F_49 ( V_61 , L_51 ,
( long long ) V_69 -> V_36 ) ;
if ( ( V_69 -> V_36 == 0 ) || ( V_71 < 0 ) )
;
else
for ( V_70 = 0 ; V_70 < V_65 ; V_70 ++ ) {
T_9 V_58 ;
V_71 = F_26 ( V_20 ,
V_4 + V_69 -> V_36 +
( V_70 * sizeof( V_58 ) ) ,
& V_58 , sizeof( V_58 ) ) ;
if ( V_71 < 0 ) {
F_49 ( V_61 ,
L_52 ,
V_70 , V_66 , V_71 ) ;
continue;
}
F_48 ( & V_58 , V_70 , V_61 ) ;
}
F_49 ( V_61 , L_53 ,
V_66 + V_4 , V_26 ) ;
}
void
F_53 ( T_1 * V_80 , char * V_21 ,
int V_4 , int V_81 , struct V_60 * V_61 )
{
char * V_30 , * V_82 , * V_83 ;
int V_84 = 0 ;
int V_70 ;
int V_71 = 0 ;
V_84 = 100 * F_54 ( V_81 , 16 ) ;
V_30 = F_2 ( V_81 , V_9 | V_10 ) ;
V_83 = F_2 ( V_84 , V_9 | V_10 ) ;
if ( V_30 == NULL || V_83 == NULL )
goto V_11;
V_71 = F_26 ( V_80 , V_4 , V_30 , V_81 ) ;
if ( V_71 < 0 ) {
F_3 ( L_54 ,
V_21 , V_31 , V_71 ) ;
goto V_11;
}
F_49 ( V_61 , L_55 , V_21 ) ;
V_82 = V_30 ;
while ( V_81 > 0 ) {
V_70 = ( V_81 < 16 ) ? V_81 : 16 ;
F_55 ( V_82 , V_70 , 16 , 1 , V_83 , V_84 , TRUE ) ;
F_49 ( V_61 , L_56 , V_83 ) ;
V_82 += 16 ;
V_81 -= 16 ;
}
V_11:
if ( V_30 != NULL ) {
F_16 ( V_30 ) ;
V_30 = NULL ;
}
if ( V_83 != NULL ) {
F_16 ( V_83 ) ;
V_83 = NULL ;
}
}
