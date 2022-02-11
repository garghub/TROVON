static struct V_1 *
F_1 ( T_1 V_2 , T_2 V_3 ,
struct V_1 * V_4 , T_2 V_5 , T_3 V_6 ,
BOOL V_7 )
{
struct V_1 * V_8 = NULL ;
void * V_9 = NULL ;
V_8 = F_2 ( sizeof( * V_8 ) , V_10 | V_11 ) ;
if ( ! V_8 ) {
V_9 = NULL ;
goto V_12;
}
V_8 -> V_13 = NULL ;
V_8 -> V_7 = V_7 ;
F_3 ( & V_8 -> V_14 ) ;
F_3 ( & V_8 -> V_15 ) ;
if ( ! V_4 )
V_8 -> V_13 =
F_4 ( V_2 ,
sizeof( struct V_16 ) ) ;
else
V_8 -> V_13 =
F_5 ( V_4 -> V_13 ,
V_5 , sizeof( struct V_16 ) ) ;
if ( ! V_8 -> V_13 ) {
V_9 = NULL ;
goto V_12;
}
if ( F_6 ( V_8 -> V_13 , 0 , & V_8 -> V_17 ,
sizeof( struct V_16 ) ) < 0 ) {
V_9 = NULL ;
goto V_12;
}
if ( V_3 == 0 )
V_3 = ( T_2 ) V_8 -> V_17 . V_18 ;
if ( F_7 ( V_6 , V_19 ) == 0 )
V_6 = V_8 -> V_17 . V_20 ;
if ( F_8 ( V_8 -> V_13 , V_3 ) < 0 ) {
V_9 = NULL ;
goto V_12;
}
V_8 -> V_18 = V_3 ;
V_8 -> V_6 = V_6 ;
V_9 = V_8 ;
V_12:
if ( ! V_9 ) {
if ( ! V_8 ) {
F_9 ( V_8 ) ;
V_8 = NULL ;
}
}
return V_9 ;
}
struct V_1 *
F_10 ( T_1 V_2 , T_2 V_3 , T_3 V_6 )
{
return F_1 ( V_2 , V_3 , NULL , 0 , V_6 ,
FALSE ) ;
}
struct V_1 *
F_11 ( T_1 V_2 , T_2 V_3 ,
T_3 V_6 )
{
return F_1 ( V_2 , V_3 , NULL , 0 , V_6 ,
TRUE ) ;
}
struct V_1 *
F_12 ( T_2 V_3 ,
struct V_1 * V_4 , T_2 V_5 ,
T_3 V_6 )
{
return F_1 ( 0 , V_3 , V_4 , V_5 , V_6 ,
FALSE ) ;
}
struct V_1 *
F_13 ( T_2 V_3 ,
struct V_1 * V_4 , T_2 V_5 ,
T_3 V_6 )
{
return F_1 ( 0 , V_3 , V_4 , V_5 , V_6 ,
TRUE ) ;
}
void
F_9 ( struct V_1 * V_21 )
{
if ( ! V_21 )
return;
if ( V_21 -> V_13 ) {
F_14 ( V_21 -> V_13 ) ;
V_21 -> V_13 = NULL ;
}
F_15 ( V_21 ) ;
}
T_1
F_16 ( struct V_1 * V_21 )
{
return F_17 ( V_21 -> V_13 ) ;
}
T_2
F_18 ( struct V_1 * V_21 )
{
return V_21 -> V_18 ;
}
char *
F_19 ( T_3 * V_6 , char * V_22 )
{
sprintf ( V_22 , L_1 , V_6 ) ;
return V_22 ;
}
char *
F_20 ( struct V_1 * V_21 , char * V_22 )
{
return F_19 ( & V_21 -> V_6 , V_22 ) ;
}
char *
F_21 ( struct V_1 * V_21 , char * V_22 )
{
return F_19 ( & V_21 -> V_17 . V_23 , V_22 ) ;
}
T_1
F_22 ( struct V_1 * V_21 )
{
return V_21 -> V_17 . V_24 ;
}
T_3
F_23 ( struct V_1 * V_21 )
{
return V_21 -> V_6 ;
}
struct V_13 *
F_24 ( struct V_1 * V_21 )
{
return V_21 -> V_13 ;
}
int
F_25 ( struct V_1 * V_21 , T_2 V_25 ,
void * V_26 , T_2 V_27 )
{
int V_9 = F_6 ( V_21 -> V_13 , V_25 ,
V_26 , V_27 ) ;
if ( ( V_9 >= 0 ) && ( V_25 == 0 ) &&
( V_27 >= sizeof( struct V_16 ) ) ) {
memcpy ( & V_21 -> V_17 , V_26 ,
sizeof( struct V_16 ) ) ;
}
return V_9 ;
}
int
F_26 ( struct V_1 * V_21 , T_2 V_25 ,
void * V_26 , T_2 V_27 )
{
if ( V_25 == 0 && V_27 >= sizeof( struct V_16 ) )
memcpy ( & V_21 -> V_17 , V_26 ,
sizeof( struct V_16 ) ) ;
return F_27 ( V_21 -> V_13 , V_25 , V_26 , V_27 ) ;
}
int
F_28 ( struct V_1 * V_21 , T_2 V_25 , T_4 V_28 ,
T_2 V_27 )
{
int V_9 = - 1 ;
int V_29 = 65536 ;
int V_30 = 0 ;
T_4 * V_31 = F_29 ( V_29 ) ;
if ( ! V_31 )
goto V_12;
memset ( V_31 , V_28 , V_29 ) ;
while ( V_27 > 0 ) {
T_2 V_32 = V_29 ;
int V_33 = - 1 ;
if ( V_27 < V_32 )
V_32 = V_27 ;
V_33 = F_27 ( V_21 -> V_13 , V_25 + V_30 ,
V_31 , V_32 ) ;
if ( V_33 < 0 ) {
V_9 = V_33 ;
goto V_12;
}
V_30 += V_32 ;
V_27 -= V_32 ;
}
V_9 = 0 ;
V_12:
if ( V_31 ) {
F_30 ( V_31 ) ;
V_31 = NULL ;
}
return V_9 ;
}
void T_5 *
F_31 ( struct V_1 * V_21 )
{
return ( void T_5 * ) & V_21 -> V_17 ;
}
static BOOL
F_32 ( struct V_1 * V_21 , T_6 V_34 ,
struct V_35 * V_36 )
{
BOOL V_9 = FALSE ;
if ( V_21 -> V_17 . V_37 < sizeof( struct V_16 ) )
goto V_12;
if ( F_6 ( V_21 -> V_13 ,
F_33 ( & V_21 -> V_17 , V_34 ) ,
V_36 ,
sizeof( struct V_35 ) ) < 0 ) {
goto V_12;
}
V_9 = TRUE ;
V_12:
return V_9 ;
}
static BOOL
F_34 ( struct V_1 * V_21 , T_6 V_34 ,
struct V_35 * V_36 , T_6 V_38 , void * V_39 ,
BOOL V_40 )
{
BOOL V_9 = FALSE ;
int V_41 = F_35 ( & V_21 -> V_17 , V_34 ,
V_36 , V_38 ) ;
if ( V_40 ) {
if ( F_27 ( V_21 -> V_13 ,
V_41 ,
V_39 , V_36 -> V_42 ) < 0 ) {
goto V_12;
}
} else {
if ( F_6 ( V_21 -> V_13 , V_41 ,
V_39 , V_36 -> V_42 ) < 0 ) {
goto V_12;
}
}
V_9 = TRUE ;
V_12:
return V_9 ;
}
static inline BOOL
F_36 ( struct V_1 * V_21 , T_6 V_34 ,
struct V_35 * V_36 , T_6 V_38 , void * V_39 )
{
return F_34 ( V_21 , V_34 , V_36 , V_38 , V_39 , FALSE ) ;
}
static inline BOOL
F_37 ( struct V_1 * V_21 , T_6 V_34 ,
struct V_35 * V_36 , T_6 V_38 , void * V_39 )
{
return F_34 ( V_21 , V_34 , V_36 , V_38 , V_39 , TRUE ) ;
}
static inline unsigned char
F_38 ( struct V_35 * V_43 ,
struct V_35 * V_44 ,
T_6 * V_45 , T_6 * V_46 )
{
if ( ( * V_45 >= V_43 -> V_47 ) ||
( * V_46 >= V_43 -> V_47 ) ) {
* V_45 = 0 ;
* V_46 = 0 ;
V_44 -> V_48 = * V_45 ;
V_44 -> V_49 = * V_46 ;
return 0 ;
}
return 1 ;
}
static BOOL
F_39 ( struct V_1 * V_21 , T_6 V_34 , void * V_50 )
{
struct V_35 V_36 ;
if ( ! F_32 ( V_21 , V_34 , & V_36 ) )
return FALSE ;
if ( V_36 . V_48 == V_36 . V_49 )
return FALSE ;
V_36 . V_49 = ( V_36 . V_49 + 1 ) % V_36 . V_47 ;
if ( ! F_36 ( V_21 , V_34 , & V_36 , V_36 . V_49 , V_50 ) ) {
return FALSE ;
}
V_36 . V_51 ++ ;
F_40 () ;
if ( ! F_41 ( V_21 , V_34 , & V_36 , V_49 ) )
return FALSE ;
if ( ! F_41 ( V_21 , V_34 , & V_36 , V_51 ) )
return FALSE ;
return TRUE ;
}
BOOL
F_42 ( struct V_1 * V_21 , T_6 V_34 , void * V_50 )
{
BOOL V_9 ;
if ( V_21 -> V_7 ) {
F_43 ( & V_21 -> V_15 ) ;
V_9 = F_39 ( V_21 , V_34 , V_50 ) ;
F_44 ( & V_21 -> V_15 ) ;
} else {
V_9 = F_39 ( V_21 , V_34 , V_50 ) ;
}
return V_9 ;
}
static BOOL
F_45 ( struct V_1 * V_21 , T_6 V_34 , void * V_50 )
{
struct V_35 V_36 ;
if ( ! F_32 ( V_21 , V_34 , & V_36 ) )
return FALSE ;
V_36 . V_48 = ( ( V_36 . V_48 + 1 ) % V_36 . V_47 ) ;
if ( V_36 . V_48 == V_36 . V_49 ) {
V_36 . V_52 ++ ;
F_27 ( V_21 -> V_13 ,
F_33 ( & V_21 -> V_17 ,
V_34 ) +
F_46 ( struct V_35 ,
V_52 ) ,
& ( V_36 . V_52 ) ,
sizeof( V_36 . V_52 ) ) ;
return FALSE ;
}
if ( ! F_37 ( V_21 , V_34 , & V_36 , V_36 . V_48 , V_50 ) )
return FALSE ;
V_36 . V_53 ++ ;
F_40 () ;
if ( ! F_41 ( V_21 , V_34 , & V_36 , V_48 ) )
return FALSE ;
if ( ! F_41 ( V_21 , V_34 , & V_36 , V_53 ) ) {
return FALSE ;
}
return TRUE ;
}
BOOL
F_47 ( struct V_1 * V_21 , T_6 V_34 , void * V_50 )
{
BOOL V_9 ;
if ( V_21 -> V_7 ) {
F_43 ( & V_21 -> V_14 ) ;
V_9 = F_45 ( V_21 , V_34 , V_50 ) ;
F_44 ( & V_21 -> V_14 ) ;
} else {
V_9 = F_45 ( V_21 , V_34 , V_50 ) ;
}
return V_9 ;
}
int
F_48 ( struct V_1 * V_21 , T_6 V_34 )
{
struct V_35 V_36 ;
T_6 V_54 , V_55 ;
T_6 V_48 , V_49 ;
if ( ! F_32 ( V_21 , V_34 , & V_36 ) )
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
F_49 ( struct V_1 * V_21 , T_6 V_34 )
{
struct V_35 V_36 ;
if ( ! F_32 ( V_21 , V_34 , & V_36 ) )
return 0 ;
return ( int ) V_36 . V_56 ;
}
static void
F_50 ( struct V_35 * V_57 , int V_58 , struct V_59 * V_60 )
{
F_51 ( V_60 , L_2 , V_58 ) ;
F_51 ( V_60 , L_3 , ( T_2 ) V_57 -> V_61 ) ;
F_51 ( V_60 , L_4 , ( T_2 ) V_57 -> V_20 ) ;
F_51 ( V_60 , L_5 ,
( long long ) V_57 -> V_62 ) ;
F_51 ( V_60 , L_6 , ( T_2 ) V_57 -> V_42 ) ;
F_51 ( V_60 , L_7 ,
( T_2 ) V_57 -> V_47 ) ;
F_51 ( V_60 , L_8 , ( T_2 ) V_57 -> V_56 ) ;
F_51 ( V_60 , L_9 ,
( long long ) V_57 -> V_63 ) ;
F_51 ( V_60 , L_10 ,
( long long ) V_57 -> V_53 ) ;
F_51 ( V_60 , L_11 ,
( long long ) V_57 -> V_51 ) ;
F_51 ( V_60 , L_12 ,
( long long ) V_57 -> V_52 ) ;
F_51 ( V_60 , L_13 , ( T_2 ) V_57 -> V_48 ) ;
F_51 ( V_60 , L_14 , ( T_2 ) V_57 -> V_49 ) ;
}
void
F_52 ( struct V_1 * V_21 , int V_64 ,
struct V_59 * V_60 , T_6 V_5 )
{
T_1 V_65 = 0 ;
T_2 V_27 = 0 , V_66 = 0 ;
struct V_13 * V_13 = NULL ;
struct V_16 V_67 ;
struct V_16 * V_68 = & V_67 ;
int V_69 = 0 ;
int V_70 = 0 ;
if ( ! V_21 )
return;
V_13 = V_21 -> V_13 ;
if ( ! V_13 )
return;
V_65 = F_17 ( V_13 ) ;
V_66 = F_53 ( V_13 ) ;
V_70 = F_25 ( V_21 , V_5 ,
V_68 , sizeof( struct V_16 ) ) ;
if ( V_70 < 0 ) {
F_51 ( V_60 ,
L_15 ,
V_70 ) ;
if ( V_5 == 0 ) {
V_68 = & V_21 -> V_17 ;
F_54 ( V_60 , L_16 ) ;
} else {
return;
}
}
V_27 = ( T_2 ) ( V_68 -> V_18 ) ;
F_51 ( V_60 , L_17 ,
V_65 + V_5 , V_27 , V_66 ) ;
F_51 ( V_60 , L_18 , & V_68 -> V_20 ) ;
F_51 ( V_60 , L_19 , & V_68 -> V_23 ) ;
F_51 ( V_60 , L_20 ,
( long long ) V_68 -> V_71 ) ;
F_51 ( V_60 , L_21 , ( T_2 ) V_68 -> V_72 ) ;
F_51 ( V_60 , L_22 , ( T_2 ) V_68 -> V_73 ) ;
F_51 ( V_60 , L_23 , ( T_2 ) V_68 -> V_74 ) ;
F_51 ( V_60 , L_24 , ( T_2 ) V_68 -> V_75 ) ;
F_51 ( V_60 , L_25 , ( T_2 ) V_68 -> V_76 ) ;
F_51 ( V_60 , L_26 , ( long long ) V_68 -> V_18 ) ;
F_51 ( V_60 , L_27 ,
( long long ) V_68 -> V_63 ) ;
F_51 ( V_60 , L_28 ,
( long long ) V_68 -> V_24 ) ;
F_51 ( V_60 , L_29 ,
( long long ) V_68 -> V_77 ) ;
F_51 ( V_60 , L_30 , ( T_2 ) V_68 -> V_78 ) ;
F_51 ( V_60 , L_31 ,
( long long ) V_68 -> V_37 ) ;
if ( ( V_68 -> V_37 == 0 ) || ( V_70 < 0 ) )
;
else
for ( V_69 = 0 ; V_69 < V_64 ; V_69 ++ ) {
struct V_35 V_57 ;
V_70 = F_25 ( V_21 ,
V_5 +
V_68 -> V_37 +
( V_69 * sizeof( V_57 ) ) ,
& V_57 , sizeof( V_57 ) ) ;
if ( V_70 < 0 ) {
F_51 ( V_60 ,
L_32 ,
V_69 , V_65 , V_70 ) ;
continue;
}
F_50 ( & V_57 , V_69 , V_60 ) ;
}
F_51 ( V_60 , L_33 ,
V_65 + V_5 , V_27 ) ;
}
void
F_55 ( struct V_1 * V_79 , char * V_22 ,
int V_5 , int V_80 , struct V_59 * V_60 )
{
char * V_31 , * V_81 , * V_82 ;
int V_83 = 0 ;
int V_69 ;
int V_70 = 0 ;
V_83 = 100 * F_56 ( V_80 , 16 ) ;
V_31 = F_2 ( V_80 , V_10 | V_11 ) ;
if ( ! V_31 )
return;
V_82 = F_2 ( V_83 , V_10 | V_11 ) ;
if ( ! V_82 )
goto V_84;
V_70 = F_25 ( V_79 , V_5 , V_31 , V_80 ) ;
if ( V_70 < 0 )
goto V_85;
F_51 ( V_60 , L_34 , V_22 ) ;
V_81 = V_31 ;
while ( V_80 > 0 ) {
V_69 = ( V_80 < 16 ) ? V_80 : 16 ;
F_57 ( V_81 , V_69 , 16 , 1 , V_82 , V_83 , TRUE ) ;
F_51 ( V_60 , L_35 , V_82 ) ;
V_81 += 16 ;
V_80 -= 16 ;
}
V_85:
F_15 ( V_82 ) ;
V_84:
F_15 ( V_31 ) ;
}
