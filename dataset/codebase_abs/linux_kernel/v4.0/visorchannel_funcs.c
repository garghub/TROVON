static struct V_1 *
F_1 ( T_1 V_2 , T_2 V_3 ,
struct V_1 * V_4 , T_2 V_5 , T_3 V_6 ,
BOOL V_7 )
{
struct V_1 * V_8 = NULL ;
void * V_9 = NULL ;
V_8 = F_2 ( sizeof( * V_8 ) , V_10 | V_11 ) ;
if ( V_8 == NULL ) {
F_3 ( L_1 ) ;
V_9 = NULL ;
goto V_12;
}
V_8 -> V_13 = NULL ;
V_8 -> V_7 = V_7 ;
F_4 ( & V_8 -> V_14 ) ;
F_4 ( & V_8 -> V_15 ) ;
if ( V_4 == NULL )
V_8 -> V_13 =
F_5 ( V_2 ,
sizeof( struct V_16 ) ) ;
else
V_8 -> V_13 =
F_6 ( V_4 -> V_13 ,
V_5 , sizeof( struct V_16 ) ) ;
if ( V_8 -> V_13 == NULL ) {
F_3 ( L_2 ) ;
V_9 = NULL ;
goto V_12;
}
if ( F_7 ( V_8 -> V_13 , 0 , & V_8 -> V_17 ,
sizeof( struct V_16 ) ) < 0 ) {
F_3 ( L_3 ) ;
V_9 = NULL ;
goto V_12;
}
if ( V_3 == 0 )
V_3 = ( T_2 ) V_8 -> V_17 . V_18 ;
if ( F_8 ( V_6 , V_19 ) == 0 )
V_6 = V_8 -> V_17 . V_20 ;
if ( F_9 ( V_8 -> V_13 , V_3 ) < 0 ) {
F_3 ( L_4 ) ;
V_9 = NULL ;
goto V_12;
}
V_8 -> V_18 = V_3 ;
V_8 -> V_6 = V_6 ;
V_9 = V_8 ;
V_12:
if ( V_9 == NULL ) {
if ( V_8 != NULL ) {
F_10 ( V_8 ) ;
V_8 = NULL ;
}
}
return V_9 ;
}
struct V_1 *
F_11 ( T_1 V_2 , T_2 V_3 , T_3 V_6 )
{
return F_1 ( V_2 , V_3 , NULL , 0 , V_6 ,
FALSE ) ;
}
struct V_1 *
F_12 ( T_1 V_2 , T_2 V_3 ,
T_3 V_6 )
{
return F_1 ( V_2 , V_3 , NULL , 0 , V_6 ,
TRUE ) ;
}
struct V_1 *
F_13 ( T_2 V_3 ,
struct V_1 * V_4 , T_2 V_5 ,
T_3 V_6 )
{
return F_1 ( 0 , V_3 , V_4 , V_5 , V_6 ,
FALSE ) ;
}
struct V_1 *
F_14 ( T_2 V_3 ,
struct V_1 * V_4 , T_2 V_5 ,
T_3 V_6 )
{
return F_1 ( 0 , V_3 , V_4 , V_5 , V_6 ,
TRUE ) ;
}
void
F_10 ( struct V_1 * V_21 )
{
if ( V_21 == NULL )
return;
if ( V_21 -> V_13 != NULL ) {
F_15 ( V_21 -> V_13 ) ;
V_21 -> V_13 = NULL ;
}
F_16 ( V_21 ) ;
}
T_1
F_17 ( struct V_1 * V_21 )
{
return F_18 ( V_21 -> V_13 ) ;
}
T_2
F_19 ( struct V_1 * V_21 )
{
return V_21 -> V_18 ;
}
char *
F_20 ( T_3 * V_6 , char * V_22 )
{
sprintf ( V_22 , L_5 , V_6 ) ;
return V_22 ;
}
char *
F_21 ( struct V_1 * V_21 , char * V_22 )
{
return F_20 ( & V_21 -> V_6 , V_22 ) ;
}
char *
F_22 ( struct V_1 * V_21 , char * V_22 )
{
return F_20 ( & V_21 -> V_17 . V_23 , V_22 ) ;
}
T_1
F_23 ( struct V_1 * V_21 )
{
return V_21 -> V_17 . V_24 ;
}
T_3
F_24 ( struct V_1 * V_21 )
{
return V_21 -> V_6 ;
}
struct V_13 *
F_25 ( struct V_1 * V_21 )
{
return V_21 -> V_13 ;
}
int
F_26 ( struct V_1 * V_21 , T_2 V_25 ,
void * V_26 , T_2 V_27 )
{
int V_9 = F_7 ( V_21 -> V_13 , V_25 ,
V_26 , V_27 ) ;
if ( ( V_9 >= 0 ) && ( V_25 == 0 ) &&
( V_27 >= sizeof( struct V_16 ) ) ) {
memcpy ( & V_21 -> V_17 , V_26 ,
sizeof( struct V_16 ) ) ;
}
return V_9 ;
}
int
F_27 ( struct V_1 * V_21 , T_2 V_25 ,
void * V_26 , T_2 V_27 )
{
if ( V_25 == 0 && V_27 >= sizeof( struct V_16 ) )
memcpy ( & V_21 -> V_17 , V_26 ,
sizeof( struct V_16 ) ) ;
return F_28 ( V_21 -> V_13 , V_25 , V_26 , V_27 ) ;
}
int
F_29 ( struct V_1 * V_21 , T_2 V_25 , T_4 V_28 ,
T_2 V_27 )
{
int V_9 = - 1 ;
int V_29 = 65536 ;
int V_30 = 0 ;
T_4 * V_31 = F_30 ( V_29 ) ;
if ( V_31 == NULL ) {
F_3 ( L_6 , V_32 ) ;
goto V_12;
}
memset ( V_31 , V_28 , V_29 ) ;
while ( V_27 > 0 ) {
T_2 V_33 = V_29 ;
int V_34 = - 1 ;
if ( V_27 < V_33 )
V_33 = V_27 ;
V_34 = F_28 ( V_21 -> V_13 , V_25 + V_30 ,
V_31 , V_33 ) ;
if ( V_34 < 0 ) {
V_9 = V_34 ;
goto V_12;
}
V_30 += V_33 ;
V_27 -= V_33 ;
}
V_9 = 0 ;
V_12:
if ( V_31 != NULL ) {
F_31 ( V_31 ) ;
V_31 = NULL ;
}
return V_9 ;
}
void T_5 *
F_32 ( struct V_1 * V_21 )
{
return ( void T_5 * ) & V_21 -> V_17 ;
}
static BOOL
F_33 ( struct V_1 * V_21 , T_6 V_35 ,
struct V_36 * V_37 )
{
BOOL V_9 = FALSE ;
if ( V_21 -> V_17 . V_38 < sizeof( struct V_16 ) ) {
F_3 ( L_7 , V_9 ) ;
goto V_12;
}
if ( F_7 ( V_21 -> V_13 ,
F_34 ( & V_21 -> V_17 , V_35 ) ,
V_37 ,
sizeof( struct V_36 ) ) < 0 ) {
F_3 ( L_8 ,
V_35 , ( int ) F_34 ( & V_21 -> V_17 , V_35 ) ) ;
F_3 ( L_9 ,
V_9 ) ;
goto V_12;
}
V_9 = TRUE ;
V_12:
return V_9 ;
}
static BOOL
F_35 ( struct V_1 * V_21 , T_6 V_35 ,
struct V_36 * V_37 , T_6 V_39 , void * V_40 ,
BOOL V_41 )
{
BOOL V_9 = FALSE ;
int V_42 = F_36 ( & V_21 -> V_17 , V_35 ,
V_37 , V_39 ) ;
if ( V_41 ) {
if ( F_28 ( V_21 -> V_13 ,
V_42 ,
V_40 , V_37 -> V_43 ) < 0 ) {
F_3 ( L_10 ,
V_9 ) ;
goto V_12;
}
} else {
if ( F_7 ( V_21 -> V_13 , V_42 ,
V_40 , V_37 -> V_43 ) < 0 ) {
F_3 ( L_11 ,
V_9 ) ;
goto V_12;
}
}
V_9 = TRUE ;
V_12:
return V_9 ;
}
static inline BOOL
F_37 ( struct V_1 * V_21 , T_6 V_35 ,
struct V_36 * V_37 , T_6 V_39 , void * V_40 )
{
return F_35 ( V_21 , V_35 , V_37 , V_39 , V_40 , FALSE ) ;
}
static inline BOOL
F_38 ( struct V_1 * V_21 , T_6 V_35 ,
struct V_36 * V_37 , T_6 V_39 , void * V_40 )
{
return F_35 ( V_21 , V_35 , V_37 , V_39 , V_40 , TRUE ) ;
}
static inline unsigned char
F_39 ( struct V_36 * V_44 ,
struct V_36 * V_45 ,
T_6 * V_46 , T_6 * V_47 )
{
if ( ( * V_46 >= V_44 -> V_48 ) ||
( * V_47 >= V_44 -> V_48 ) ) {
* V_46 = 0 ;
* V_47 = 0 ;
V_45 -> V_49 = * V_46 ;
V_45 -> V_50 = * V_47 ;
F_3 ( L_12 ,
* V_46 , * V_47 , V_44 -> V_48 ) ;
return 0 ;
}
return 1 ;
}
static BOOL
F_40 ( struct V_1 * V_21 , T_6 V_35 , void * V_51 )
{
struct V_36 V_37 ;
if ( ! F_33 ( V_21 , V_35 , & V_37 ) ) {
return FALSE ;
}
if ( V_37 . V_49 == V_37 . V_50 )
return FALSE ;
V_37 . V_50 = ( V_37 . V_50 + 1 ) % V_37 . V_48 ;
if ( ! F_37 ( V_21 , V_35 , & V_37 , V_37 . V_50 , V_51 ) ) {
F_3 ( L_13 ) ;
return FALSE ;
}
V_37 . V_52 ++ ;
F_41 () ;
if ( ! F_42 ( V_21 , V_35 , & V_37 , V_50 ) ) {
F_3 ( L_14 ) ;
return FALSE ;
}
if ( ! F_42 ( V_21 , V_35 , & V_37 , V_52 ) ) {
F_3 ( L_15 ) ;
return FALSE ;
}
return TRUE ;
}
BOOL
F_43 ( struct V_1 * V_21 , T_6 V_35 , void * V_51 )
{
BOOL V_9 ;
if ( V_21 -> V_7 ) {
F_44 ( & V_21 -> V_15 ) ;
V_9 = F_40 ( V_21 , V_35 , V_51 ) ;
F_45 ( & V_21 -> V_15 ) ;
} else {
V_9 = F_40 ( V_21 , V_35 , V_51 ) ;
}
return V_9 ;
}
static BOOL
F_46 ( struct V_1 * V_21 , T_6 V_35 , void * V_51 )
{
struct V_36 V_37 ;
if ( ! F_33 ( V_21 , V_35 , & V_37 ) ) {
return FALSE ;
}
V_37 . V_49 = ( ( V_37 . V_49 + 1 ) % V_37 . V_48 ) ;
if ( V_37 . V_49 == V_37 . V_50 ) {
V_37 . V_53 ++ ;
if ( ! F_42 ( V_21 , V_35 , & V_37 , V_53 ) )
F_3 ( L_16 ) ;
return FALSE ;
}
if ( ! F_38 ( V_21 , V_35 , & V_37 , V_37 . V_49 , V_51 ) ) {
F_3 ( L_17 ) ;
return FALSE ;
}
V_37 . V_54 ++ ;
F_41 () ;
if ( ! F_42 ( V_21 , V_35 , & V_37 , V_49 ) ) {
F_3 ( L_18 ) ;
return FALSE ;
}
if ( ! F_42 ( V_21 , V_35 , & V_37 , V_54 ) ) {
F_3 ( L_19 ) ;
return FALSE ;
}
return TRUE ;
}
BOOL
F_47 ( struct V_1 * V_21 , T_6 V_35 , void * V_51 )
{
BOOL V_9 ;
if ( V_21 -> V_7 ) {
F_44 ( & V_21 -> V_14 ) ;
V_9 = F_46 ( V_21 , V_35 , V_51 ) ;
F_45 ( & V_21 -> V_14 ) ;
} else {
V_9 = F_46 ( V_21 , V_35 , V_51 ) ;
}
return V_9 ;
}
int
F_48 ( struct V_1 * V_21 , T_6 V_35 )
{
struct V_36 V_37 ;
T_6 V_55 , V_56 ;
T_6 V_49 , V_50 ;
if ( ! F_33 ( V_21 , V_35 , & V_37 ) )
return 0 ;
V_49 = V_37 . V_49 ;
V_50 = V_37 . V_50 ;
if ( V_49 < V_50 )
V_49 = V_49 + V_37 . V_48 ;
V_56 = ( V_49 - V_50 ) ;
V_55 = V_37 . V_57 - V_56 ;
return ( int ) V_55 ;
}
int
F_49 ( struct V_1 * V_21 , T_6 V_35 )
{
struct V_36 V_37 ;
if ( ! F_33 ( V_21 , V_35 , & V_37 ) )
return 0 ;
return ( int ) V_37 . V_57 ;
}
static void
F_50 ( struct V_36 * V_58 , int V_59 , struct V_60 * V_61 )
{
F_51 ( V_61 , L_20 , V_59 ) ;
F_51 ( V_61 , L_21 , ( T_2 ) V_58 -> V_62 ) ;
F_51 ( V_61 , L_22 , ( T_2 ) V_58 -> V_20 ) ;
F_51 ( V_61 , L_23 ,
( long long ) V_58 -> V_63 ) ;
F_51 ( V_61 , L_24 , ( T_2 ) V_58 -> V_43 ) ;
F_51 ( V_61 , L_25 ,
( T_2 ) V_58 -> V_48 ) ;
F_51 ( V_61 , L_26 , ( T_2 ) V_58 -> V_57 ) ;
F_51 ( V_61 , L_27 ,
( long long ) V_58 -> V_64 ) ;
F_51 ( V_61 , L_28 ,
( long long ) V_58 -> V_54 ) ;
F_51 ( V_61 , L_29 ,
( long long ) V_58 -> V_52 ) ;
F_51 ( V_61 , L_30 ,
( long long ) V_58 -> V_53 ) ;
F_51 ( V_61 , L_31 , ( T_2 ) V_58 -> V_49 ) ;
F_51 ( V_61 , L_32 , ( T_2 ) V_58 -> V_50 ) ;
}
void
F_52 ( struct V_1 * V_21 , int V_65 ,
struct V_60 * V_61 , T_6 V_5 )
{
T_1 V_66 = 0 ;
T_2 V_27 = 0 , V_67 = 0 ;
struct V_13 * V_13 = NULL ;
struct V_16 V_68 ;
struct V_16 * V_69 = & V_68 ;
int V_70 = 0 ;
int V_71 = 0 ;
if ( V_21 == NULL ) {
F_3 ( L_33 , V_32 ) ;
return;
}
V_13 = V_21 -> V_13 ;
if ( V_13 == NULL ) {
F_3 ( L_34 , V_32 ) ;
return;
}
V_66 = F_18 ( V_13 ) ;
V_67 = F_53 ( V_13 ) ;
V_71 = F_26 ( V_21 , V_5 ,
V_69 , sizeof( struct V_16 ) ) ;
if ( V_71 < 0 ) {
F_51 ( V_61 ,
L_35 ,
V_71 ) ;
if ( V_5 == 0 ) {
V_69 = & V_21 -> V_17 ;
F_54 ( V_61 , L_36 ) ;
} else {
return;
}
}
V_27 = ( T_2 ) ( V_69 -> V_18 ) ;
F_51 ( V_61 , L_37 ,
V_66 + V_5 , V_27 , V_67 ) ;
F_51 ( V_61 , L_38 , & V_69 -> V_20 ) ;
F_51 ( V_61 , L_39 , & V_69 -> V_23 ) ;
F_51 ( V_61 , L_40 ,
( long long ) V_69 -> V_72 ) ;
F_51 ( V_61 , L_41 , ( T_2 ) V_69 -> V_73 ) ;
F_51 ( V_61 , L_42 , ( T_2 ) V_69 -> V_74 ) ;
F_51 ( V_61 , L_43 , ( T_2 ) V_69 -> V_75 ) ;
F_51 ( V_61 , L_44 , ( T_2 ) V_69 -> V_76 ) ;
F_51 ( V_61 , L_45 , ( T_2 ) V_69 -> V_77 ) ;
F_51 ( V_61 , L_46 , ( long long ) V_69 -> V_18 ) ;
F_51 ( V_61 , L_47 ,
( long long ) V_69 -> V_64 ) ;
F_51 ( V_61 , L_48 ,
( long long ) V_69 -> V_24 ) ;
F_51 ( V_61 , L_49 ,
( long long ) V_69 -> V_78 ) ;
F_51 ( V_61 , L_50 , ( T_2 ) V_69 -> V_79 ) ;
F_51 ( V_61 , L_51 ,
( long long ) V_69 -> V_38 ) ;
if ( ( V_69 -> V_38 == 0 ) || ( V_71 < 0 ) )
;
else
for ( V_70 = 0 ; V_70 < V_65 ; V_70 ++ ) {
struct V_36 V_58 ;
V_71 = F_26 ( V_21 ,
V_5 +
V_69 -> V_38 +
( V_70 * sizeof( V_58 ) ) ,
& V_58 , sizeof( V_58 ) ) ;
if ( V_71 < 0 ) {
F_51 ( V_61 ,
L_52 ,
V_70 , V_66 , V_71 ) ;
continue;
}
F_50 ( & V_58 , V_70 , V_61 ) ;
}
F_51 ( V_61 , L_53 ,
V_66 + V_5 , V_27 ) ;
}
void
F_55 ( struct V_1 * V_80 , char * V_22 ,
int V_5 , int V_81 , struct V_60 * V_61 )
{
char * V_31 , * V_82 , * V_83 ;
int V_84 = 0 ;
int V_70 ;
int V_71 = 0 ;
V_84 = 100 * F_56 ( V_81 , 16 ) ;
V_31 = F_2 ( V_81 , V_10 | V_11 ) ;
if ( ! V_31 )
return;
V_83 = F_2 ( V_84 , V_10 | V_11 ) ;
if ( ! V_83 )
goto V_85;
V_71 = F_26 ( V_80 , V_5 , V_31 , V_81 ) ;
if ( V_71 < 0 ) {
F_3 ( L_54 ,
V_22 , V_32 , V_71 ) ;
goto V_86;
}
F_51 ( V_61 , L_55 , V_22 ) ;
V_82 = V_31 ;
while ( V_81 > 0 ) {
V_70 = ( V_81 < 16 ) ? V_81 : 16 ;
F_57 ( V_82 , V_70 , 16 , 1 , V_83 , V_84 , TRUE ) ;
F_51 ( V_61 , L_56 , V_83 ) ;
V_82 += 16 ;
V_81 -= 16 ;
}
V_86:
F_16 ( V_83 ) ;
V_85:
F_16 ( V_31 ) ;
}
