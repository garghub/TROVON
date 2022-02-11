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
F_5 ( V_1 ,
sizeof( struct V_15 ) ) ;
else
V_7 -> V_12 =
F_6 ( V_3 -> V_12 ,
V_4 , sizeof( struct V_15 ) ) ;
if ( V_7 -> V_12 == NULL ) {
F_3 ( L_2 ) ;
V_8 = NULL ;
goto V_11;
}
if ( F_7 ( V_7 -> V_12 , 0 , & V_7 -> V_16 ,
sizeof( struct V_15 ) ) < 0 ) {
F_3 ( L_3 ) ;
V_8 = NULL ;
goto V_11;
}
if ( V_2 == 0 )
V_2 = ( T_3 ) V_7 -> V_16 . V_17 ;
if ( F_8 ( V_5 , V_18 ) == 0 )
V_5 = V_7 -> V_16 . V_19 ;
if ( F_9 ( V_7 -> V_12 , V_2 ) < 0 ) {
F_3 ( L_4 ) ;
V_8 = NULL ;
goto V_11;
}
V_7 -> V_17 = V_2 ;
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
return V_20 -> V_17 ;
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
struct V_12 *
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
if ( ( V_8 >= 0 ) && ( V_24 == 0 ) &&
( V_26 >= sizeof( struct V_15 ) ) ) {
memcpy ( & V_20 -> V_16 , V_25 ,
sizeof( struct V_15 ) ) ;
}
return V_8 ;
}
int
F_27 ( T_1 * V_20 , T_3 V_24 ,
void * V_25 , T_3 V_26 )
{
if ( V_24 == 0 && V_26 >= sizeof( struct V_15 ) )
memcpy ( & V_20 -> V_16 , V_25 ,
sizeof( struct V_15 ) ) ;
return F_28 ( V_20 -> V_12 , V_24 , V_25 , V_26 ) ;
}
int
F_29 ( T_1 * V_20 , T_3 V_24 , T_5 V_27 , T_3 V_26 )
{
int V_8 = - 1 ;
int V_28 = 65536 ;
int V_29 = 0 ;
T_5 * V_30 = F_30 ( V_28 ) ;
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
void T_6 *
F_32 ( T_1 * V_20 )
{
return ( void T_6 * ) & V_20 -> V_16 ;
}
static BOOL
F_33 ( T_1 * V_20 , T_7 V_34 ,
struct V_35 * V_36 )
{
BOOL V_8 = FALSE ;
if ( V_20 -> V_16 . V_37 < sizeof( struct V_15 ) ) {
F_3 ( L_7 , V_8 ) ;
goto V_11;
}
if ( F_7 ( V_20 -> V_12 ,
F_34 ( & V_20 -> V_16 , V_34 ) ,
V_36 ,
sizeof( struct V_35 ) ) < 0 ) {
F_3 ( L_8 ,
V_34 , ( int ) F_34 ( & V_20 -> V_16 , V_34 ) ) ;
F_3 ( L_9 ,
V_8 ) ;
goto V_11;
}
V_8 = TRUE ;
V_11:
return V_8 ;
}
static BOOL
F_35 ( T_1 * V_20 , T_7 V_34 ,
struct V_35 * V_36 , T_7 V_38 , void * V_39 ,
BOOL V_40 )
{
BOOL V_8 = FALSE ;
int V_41 = F_36 ( & V_20 -> V_16 , V_34 ,
V_36 , V_38 ) ;
if ( V_40 ) {
if ( F_28 ( V_20 -> V_12 ,
V_41 ,
V_39 , V_36 -> V_42 ) < 0 ) {
F_3 ( L_10 ,
V_8 ) ;
goto V_11;
}
} else {
if ( F_7 ( V_20 -> V_12 , V_41 ,
V_39 , V_36 -> V_42 ) < 0 ) {
F_3 ( L_11 ,
V_8 ) ;
goto V_11;
}
}
V_8 = TRUE ;
V_11:
return V_8 ;
}
static inline BOOL
F_37 ( T_1 * V_20 , T_7 V_34 ,
struct V_35 * V_36 , T_7 V_38 , void * V_39 )
{
return F_35 ( V_20 , V_34 , V_36 , V_38 , V_39 , FALSE ) ;
}
static inline BOOL
F_38 ( T_1 * V_20 , T_7 V_34 ,
struct V_35 * V_36 , T_7 V_38 , void * V_39 )
{
return F_35 ( V_20 , V_34 , V_36 , V_38 , V_39 , TRUE ) ;
}
static inline unsigned char
F_39 ( struct V_35 * V_43 ,
struct V_35 * V_44 ,
T_7 * V_45 , T_7 * V_46 )
{
if ( ( * V_45 >= V_43 -> V_47 ) ||
( * V_46 >= V_43 -> V_47 ) ) {
* V_45 = 0 ;
* V_46 = 0 ;
V_44 -> V_48 = * V_45 ;
V_44 -> V_49 = * V_46 ;
F_3 ( L_12 ,
* V_45 , * V_46 , V_43 -> V_47 ) ;
return 0 ;
}
return 1 ;
}
BOOL
F_40 ( T_1 * V_20 , T_7 V_34 , void * V_50 )
{
BOOL V_8 = FALSE ;
struct V_35 V_36 ;
if ( V_20 -> V_6 )
F_41 ( & V_20 -> V_14 ) ;
if ( ! F_33 ( V_20 , V_34 , & V_36 ) ) {
V_8 = FALSE ;
goto V_11;
}
if ( V_36 . V_48 == V_36 . V_49 ) {
V_8 = FALSE ;
goto V_11;
}
V_36 . V_49 = ( V_36 . V_49 + 1 ) % V_36 . V_47 ;
if ( ! F_37 ( V_20 , V_34 , & V_36 , V_36 . V_49 , V_50 ) ) {
F_3 ( L_13 , V_8 ) ;
goto V_11;
}
V_36 . V_51 ++ ;
F_42 () ;
if ( ! F_43 ( V_20 , V_34 , & V_36 , V_49 ) ) {
F_3 ( L_14 ,
V_8 ) ;
goto V_11;
}
if ( ! F_43 ( V_20 , V_34 , & V_36 , V_51 ) ) {
F_3 ( L_15 ,
V_8 ) ;
goto V_11;
}
V_8 = TRUE ;
V_11:
if ( V_20 -> V_6 )
F_44 ( & V_20 -> V_14 ) ;
return V_8 ;
}
BOOL
F_45 ( T_1 * V_20 , T_7 V_34 , void * V_50 )
{
BOOL V_8 = FALSE ;
struct V_35 V_36 ;
if ( V_20 -> V_6 )
F_41 ( & V_20 -> V_13 ) ;
if ( ! F_33 ( V_20 , V_34 , & V_36 ) ) {
V_8 = FALSE ;
goto V_11;
}
V_36 . V_48 = ( ( V_36 . V_48 + 1 ) % V_36 . V_47 ) ;
if ( V_36 . V_48 == V_36 . V_49 ) {
V_36 . V_52 ++ ;
if ( ! F_43 ( V_20 , V_34 , & V_36 , V_52 ) ) {
F_3 ( L_16 ,
V_8 ) ;
goto V_11;
}
V_8 = FALSE ;
goto V_11;
}
if ( ! F_38 ( V_20 , V_34 , & V_36 , V_36 . V_48 , V_50 ) ) {
F_3 ( L_17 , V_8 ) ;
goto V_11;
}
V_36 . V_53 ++ ;
F_42 () ;
if ( ! F_43 ( V_20 , V_34 , & V_36 , V_48 ) ) {
F_3 ( L_18 ,
V_8 ) ;
goto V_11;
}
if ( ! F_43 ( V_20 , V_34 , & V_36 , V_53 ) ) {
F_3 ( L_19 ,
V_8 ) ;
goto V_11;
}
V_8 = TRUE ;
V_11:
if ( V_20 -> V_6 )
F_44 ( & V_20 -> V_13 ) ;
return V_8 ;
}
int
F_46 ( T_1 * V_20 , T_7 V_34 )
{
struct V_35 V_36 ;
T_7 V_54 , V_55 ;
T_7 V_48 , V_49 ;
if ( ! F_33 ( V_20 , V_34 , & V_36 ) )
return 0 ;
V_48 = V_36 . V_48 ;
V_49 = V_36 . V_49 ;
if ( V_48 < V_49 )
V_48 = V_48 + V_36 . V_47 ;
V_55 = ( V_48 - V_49 ) ;
V_54 = V_36 . V_56 - V_55 ;
return ( int ) V_54 ;
}
int
F_47 ( T_1 * V_20 , T_7 V_34 )
{
struct V_35 V_36 ;
if ( ! F_33 ( V_20 , V_34 , & V_36 ) )
return 0 ;
return ( int ) V_36 . V_56 ;
}
static void
F_48 ( struct V_35 * V_57 , int V_58 , struct V_59 * V_60 )
{
F_49 ( V_60 , L_20 , V_58 ) ;
F_49 ( V_60 , L_21 , ( T_3 ) V_57 -> V_61 ) ;
F_49 ( V_60 , L_22 , ( T_3 ) V_57 -> V_19 ) ;
F_49 ( V_60 , L_23 ,
( long long ) V_57 -> V_62 ) ;
F_49 ( V_60 , L_24 , ( T_3 ) V_57 -> V_42 ) ;
F_49 ( V_60 , L_25 ,
( T_3 ) V_57 -> V_47 ) ;
F_49 ( V_60 , L_26 , ( T_3 ) V_57 -> V_56 ) ;
F_49 ( V_60 , L_27 ,
( long long ) V_57 -> V_63 ) ;
F_49 ( V_60 , L_28 ,
( long long ) V_57 -> V_53 ) ;
F_49 ( V_60 , L_29 ,
( long long ) V_57 -> V_51 ) ;
F_49 ( V_60 , L_30 ,
( long long ) V_57 -> V_52 ) ;
F_49 ( V_60 , L_31 , ( T_3 ) V_57 -> V_48 ) ;
F_49 ( V_60 , L_32 , ( T_3 ) V_57 -> V_49 ) ;
}
void
F_50 ( T_1 * V_20 , int V_64 ,
struct V_59 * V_60 , T_7 V_4 )
{
T_2 V_65 = 0 ;
T_3 V_26 = 0 , V_66 = 0 ;
struct V_12 * V_12 = NULL ;
struct V_15 V_67 ;
struct V_15 * V_68 = & V_67 ;
int V_69 = 0 ;
int V_70 = 0 ;
if ( V_20 == NULL ) {
F_3 ( L_33 , V_31 ) ;
return;
}
V_12 = V_20 -> V_12 ;
if ( V_12 == NULL ) {
F_3 ( L_34 , V_31 ) ;
return;
}
V_65 = F_18 ( V_12 ) ;
V_66 = F_51 ( V_12 ) ;
V_70 = F_26 ( V_20 , V_4 ,
V_68 , sizeof( struct V_15 ) ) ;
if ( V_70 < 0 ) {
F_49 ( V_60 ,
L_35 ,
V_70 ) ;
if ( V_4 == 0 ) {
V_68 = & V_20 -> V_16 ;
F_52 ( V_60 , L_36 ) ;
} else {
return;
}
}
V_26 = ( T_3 ) ( V_68 -> V_17 ) ;
F_49 ( V_60 , L_37 ,
V_65 + V_4 , V_26 , V_66 ) ;
F_49 ( V_60 , L_38 , & V_68 -> V_19 ) ;
F_49 ( V_60 , L_39 , & V_68 -> V_22 ) ;
F_49 ( V_60 , L_40 ,
( long long ) V_68 -> V_71 ) ;
F_49 ( V_60 , L_41 , ( T_3 ) V_68 -> V_72 ) ;
F_49 ( V_60 , L_42 , ( T_3 ) V_68 -> V_73 ) ;
F_49 ( V_60 , L_43 , ( T_3 ) V_68 -> V_74 ) ;
F_49 ( V_60 , L_44 , ( T_3 ) V_68 -> V_75 ) ;
F_49 ( V_60 , L_45 , ( T_3 ) V_68 -> V_76 ) ;
F_49 ( V_60 , L_46 , ( long long ) V_68 -> V_17 ) ;
F_49 ( V_60 , L_47 ,
( long long ) V_68 -> V_63 ) ;
F_49 ( V_60 , L_48 ,
( long long ) V_68 -> V_23 ) ;
F_49 ( V_60 , L_49 ,
( long long ) V_68 -> V_77 ) ;
F_49 ( V_60 , L_50 , ( T_3 ) V_68 -> V_78 ) ;
F_49 ( V_60 , L_51 ,
( long long ) V_68 -> V_37 ) ;
if ( ( V_68 -> V_37 == 0 ) || ( V_70 < 0 ) )
;
else
for ( V_69 = 0 ; V_69 < V_64 ; V_69 ++ ) {
struct V_35 V_57 ;
V_70 = F_26 ( V_20 ,
V_4 +
V_68 -> V_37 +
( V_69 * sizeof( V_57 ) ) ,
& V_57 , sizeof( V_57 ) ) ;
if ( V_70 < 0 ) {
F_49 ( V_60 ,
L_52 ,
V_69 , V_65 , V_70 ) ;
continue;
}
F_48 ( & V_57 , V_69 , V_60 ) ;
}
F_49 ( V_60 , L_53 ,
V_65 + V_4 , V_26 ) ;
}
void
F_53 ( T_1 * V_79 , char * V_21 ,
int V_4 , int V_80 , struct V_59 * V_60 )
{
char * V_30 , * V_81 , * V_82 ;
int V_83 = 0 ;
int V_69 ;
int V_70 = 0 ;
V_83 = 100 * F_54 ( V_80 , 16 ) ;
V_30 = F_2 ( V_80 , V_9 | V_10 ) ;
if ( ! V_30 )
return;
V_82 = F_2 ( V_83 , V_9 | V_10 ) ;
if ( ! V_82 )
goto V_84;
V_70 = F_26 ( V_79 , V_4 , V_30 , V_80 ) ;
if ( V_70 < 0 ) {
F_3 ( L_54 ,
V_21 , V_31 , V_70 ) ;
goto V_85;
}
F_49 ( V_60 , L_55 , V_21 ) ;
V_81 = V_30 ;
while ( V_80 > 0 ) {
V_69 = ( V_80 < 16 ) ? V_80 : 16 ;
F_55 ( V_81 , V_69 , 16 , 1 , V_82 , V_83 , TRUE ) ;
F_49 ( V_60 , L_56 , V_82 ) ;
V_81 += 16 ;
V_80 -= 16 ;
}
V_85:
F_16 ( V_82 ) ;
V_84:
F_16 ( V_30 ) ;
}
