static struct V_1 *
F_1 ( T_1 V_2 , unsigned long V_3 ,
T_2 V_4 , unsigned long V_5 ,
T_3 V_6 , bool V_7 )
{
struct V_1 * V_8 ;
int V_9 ;
T_4 V_10 = sizeof( struct V_11 ) ;
if ( V_2 == 0 )
return NULL ;
V_8 = F_2 ( sizeof( * V_8 ) , V_4 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_7 = V_7 ;
F_3 ( & V_8 -> V_12 ) ;
F_3 ( & V_8 -> V_13 ) ;
V_8 -> V_14 = F_4 ( V_2 , V_10 , V_15 ) ;
if ( ! V_8 -> V_14 ) {
if ( F_5 ( V_6 , V_16 ) ) {
goto V_17;
}
}
V_8 -> V_18 = F_6 ( V_2 , V_10 , V_19 ) ;
if ( ! V_8 -> V_18 ) {
F_7 ( V_2 , V_10 ) ;
goto V_17;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_20 = V_10 ;
V_9 = F_8 ( V_8 , 0 , & V_8 -> V_21 ,
sizeof( struct V_11 ) ) ;
if ( V_9 )
goto V_17;
if ( V_3 == 0 )
V_3 = ( V_22 ) V_8 -> V_21 . V_10 ;
if ( F_5 ( V_6 , V_23 ) == 0 )
V_6 = V_8 -> V_21 . V_24 ;
F_9 ( V_8 -> V_18 ) ;
if ( V_8 -> V_14 )
F_7 ( V_8 -> V_2 , V_8 -> V_20 ) ;
V_8 -> V_18 = NULL ;
V_8 -> V_14 = F_4 ( V_8 -> V_2 ,
V_3 , V_15 ) ;
if ( ! V_8 -> V_14 ) {
if ( F_5 ( V_6 , V_16 ) ) {
goto V_17;
}
}
V_8 -> V_18 = F_6 ( V_8 -> V_2 , V_3 ,
V_19 ) ;
if ( ! V_8 -> V_18 ) {
F_7 ( V_8 -> V_2 , V_3 ) ;
goto V_17;
}
V_8 -> V_20 = V_3 ;
V_8 -> V_10 = V_3 ;
V_8 -> V_6 = V_6 ;
return V_8 ;
V_17:
F_10 ( V_8 ) ;
return NULL ;
}
struct V_1 *
F_11 ( T_1 V_2 , unsigned long V_3 ,
T_2 V_4 , T_3 V_6 )
{
return F_1 ( V_2 , V_3 , V_4 , 0 , V_6 ,
false ) ;
}
struct V_1 *
F_12 ( T_1 V_2 , unsigned long V_3 ,
T_2 V_4 , T_3 V_6 )
{
return F_1 ( V_2 , V_3 , V_4 , 0 , V_6 ,
true ) ;
}
void
F_10 ( struct V_1 * V_8 )
{
if ( ! V_8 )
return;
if ( V_8 -> V_18 ) {
F_9 ( V_8 -> V_18 ) ;
if ( V_8 -> V_14 )
F_7 ( V_8 -> V_2 , V_8 -> V_20 ) ;
}
F_13 ( V_8 ) ;
}
T_1
F_14 ( struct V_1 * V_8 )
{
return V_8 -> V_2 ;
}
V_22
F_15 ( struct V_1 * V_8 )
{
return V_8 -> V_10 ;
}
char *
F_16 ( T_3 * V_6 , char * V_25 )
{
sprintf ( V_25 , L_1 , V_6 ) ;
return V_25 ;
}
char *
F_17 ( struct V_1 * V_8 , char * V_25 )
{
return F_16 ( & V_8 -> V_6 , V_25 ) ;
}
char *
F_18 ( struct V_1 * V_8 , char * V_25 )
{
return F_16 ( & V_8 -> V_21 . V_26 , V_25 ) ;
}
T_1
F_19 ( struct V_1 * V_8 )
{
return V_8 -> V_21 . V_27 ;
}
int
F_20 ( struct V_1 * V_8 ,
T_1 V_27 )
{
V_8 -> V_21 . V_27 = V_27 ;
return 0 ;
}
T_3
F_21 ( struct V_1 * V_8 )
{
return V_8 -> V_6 ;
}
int
F_8 ( struct V_1 * V_8 , V_22 V_28 ,
void * V_29 , V_22 V_20 )
{
if ( V_28 + V_20 > V_8 -> V_20 )
return - V_30 ;
memcpy ( V_29 , V_8 -> V_18 + V_28 , V_20 ) ;
return 0 ;
}
int
F_22 ( struct V_1 * V_8 , V_22 V_28 ,
void * V_29 , V_22 V_20 )
{
T_4 V_31 = sizeof( struct V_11 ) ;
T_4 V_32 ;
if ( V_28 + V_20 > V_8 -> V_20 )
return - V_30 ;
if ( V_28 < V_31 ) {
V_32 = F_23 ( V_31 - V_28 , V_20 ) ;
memcpy ( ( ( char * ) ( & V_8 -> V_21 ) ) + V_28 ,
V_29 , V_32 ) ;
}
memcpy ( V_8 -> V_18 + V_28 , V_29 , V_20 ) ;
return 0 ;
}
int
F_24 ( struct V_1 * V_8 , V_22 V_28 , T_5 V_33 ,
V_22 V_20 )
{
int V_9 ;
int V_34 = V_35 ;
int V_36 = 0 ;
T_5 * V_37 ;
V_37 = ( T_5 * ) F_25 ( V_38 ) ;
if ( ! V_37 )
return - V_39 ;
memset ( V_37 , V_33 , V_34 ) ;
while ( V_20 > 0 ) {
int V_40 = V_34 ;
if ( V_20 < V_40 )
V_40 = V_20 ;
V_9 = F_22 ( V_8 , V_28 + V_36 ,
V_37 , V_40 ) ;
if ( V_9 )
goto V_41;
V_36 += V_40 ;
V_20 -= V_40 ;
}
V_9 = 0 ;
V_41:
F_26 ( ( unsigned long ) V_37 ) ;
return V_9 ;
}
void T_6 *
F_27 ( struct V_1 * V_8 )
{
return ( void T_6 * ) & V_8 -> V_21 ;
}
static bool
F_28 ( struct V_1 * V_8 , T_7 V_42 ,
struct V_43 * V_44 )
{
int V_9 ;
if ( V_8 -> V_21 . V_45 < sizeof( struct V_11 ) )
return false ;
V_9 = F_8 ( V_8 ,
F_29 ( & V_8 -> V_21 , V_42 ) ,
V_44 , sizeof( struct V_43 ) ) ;
if ( V_9 )
return false ;
return true ;
}
static inline bool
F_30 ( struct V_1 * V_8 , T_7 V_42 ,
struct V_43 * V_44 , T_7 V_46 , void * V_47 )
{
int V_9 ;
int V_48 = F_31 ( & V_8 -> V_21 , V_42 ,
V_44 , V_46 ) ;
V_9 = F_8 ( V_8 , V_48 ,
V_47 , V_44 -> V_49 ) ;
if ( V_9 )
return false ;
return true ;
}
static inline bool
F_32 ( struct V_1 * V_8 , T_7 V_42 ,
struct V_43 * V_44 , T_7 V_46 , void * V_47 )
{
int V_9 ;
int V_48 = F_31 ( & V_8 -> V_21 , V_42 ,
V_44 , V_46 ) ;
V_9 = F_22 ( V_8 , V_48 ,
V_47 , V_44 -> V_49 ) ;
if ( V_9 )
return false ;
return true ;
}
static bool
F_33 ( struct V_1 * V_8 , T_7 V_42 , void * V_50 )
{
struct V_43 V_44 ;
if ( ! F_28 ( V_8 , V_42 , & V_44 ) )
return false ;
if ( V_44 . V_51 == V_44 . V_52 )
return false ;
V_44 . V_52 = ( V_44 . V_52 + 1 ) % V_44 . V_53 ;
if ( ! F_30 ( V_8 , V_42 , & V_44 , V_44 . V_52 , V_50 ) )
return false ;
V_44 . V_54 ++ ;
F_34 () ;
if ( ! F_35 ( V_8 , V_42 , & V_44 , V_52 ) )
return false ;
if ( ! F_35 ( V_8 , V_42 , & V_44 , V_54 ) )
return false ;
return true ;
}
bool
F_36 ( struct V_1 * V_8 , T_7 V_42 , void * V_50 )
{
bool V_55 ;
unsigned long V_56 ;
if ( V_8 -> V_7 ) {
F_37 ( & V_8 -> V_13 , V_56 ) ;
V_55 = F_33 ( V_8 , V_42 , V_50 ) ;
F_38 ( & V_8 -> V_13 , V_56 ) ;
} else {
V_55 = F_33 ( V_8 , V_42 , V_50 ) ;
}
return V_55 ;
}
bool
F_39 ( struct V_1 * V_8 , T_7 V_42 )
{
unsigned long V_56 = 0 ;
struct V_43 V_44 ;
bool V_55 = false ;
if ( V_8 -> V_7 )
F_37 ( & V_8 -> V_13 , V_56 ) ;
if ( ! F_28 ( V_8 , V_42 , & V_44 ) )
V_55 = true ;
if ( V_44 . V_51 == V_44 . V_52 )
V_55 = true ;
if ( V_8 -> V_7 )
F_38 ( & V_8 -> V_13 , V_56 ) ;
return V_55 ;
}
static bool
F_40 ( struct V_1 * V_8 , T_7 V_42 , void * V_50 )
{
struct V_43 V_44 ;
if ( ! F_28 ( V_8 , V_42 , & V_44 ) )
return false ;
V_44 . V_51 = ( V_44 . V_51 + 1 ) % V_44 . V_53 ;
if ( V_44 . V_51 == V_44 . V_52 ) {
V_44 . V_57 ++ ;
F_22 ( V_8 ,
F_29 ( & V_8 -> V_21 , V_42 ) +
F_41 ( struct V_43 ,
V_57 ) ,
& V_44 . V_57 ,
sizeof( V_44 . V_57 ) ) ;
return false ;
}
if ( ! F_32 ( V_8 , V_42 , & V_44 , V_44 . V_51 , V_50 ) )
return false ;
V_44 . V_58 ++ ;
F_34 () ;
if ( ! F_35 ( V_8 , V_42 , & V_44 , V_51 ) )
return false ;
if ( ! F_35 ( V_8 , V_42 , & V_44 , V_58 ) )
return false ;
return true ;
}
bool
F_42 ( struct V_1 * V_8 , T_7 V_42 , void * V_50 )
{
bool V_55 ;
unsigned long V_56 ;
if ( V_8 -> V_7 ) {
F_37 ( & V_8 -> V_12 , V_56 ) ;
V_55 = F_40 ( V_8 , V_42 , V_50 ) ;
F_38 ( & V_8 -> V_12 , V_56 ) ;
} else {
V_55 = F_40 ( V_8 , V_42 , V_50 ) ;
}
return V_55 ;
}
int
F_43 ( struct V_1 * V_8 , T_7 V_42 )
{
struct V_43 V_44 ;
T_7 V_59 , V_60 ;
T_7 V_51 , V_52 ;
if ( ! F_28 ( V_8 , V_42 , & V_44 ) )
return 0 ;
V_51 = V_44 . V_51 ;
V_52 = V_44 . V_52 ;
if ( V_51 < V_52 )
V_51 = V_51 + V_44 . V_53 ;
V_60 = V_51 - V_52 ;
V_59 = V_44 . V_61 - V_60 ;
return ( int ) V_59 ;
}
int
F_44 ( struct V_1 * V_8 , T_7 V_42 )
{
struct V_43 V_44 ;
if ( ! F_28 ( V_8 , V_42 , & V_44 ) )
return 0 ;
return ( int ) V_44 . V_61 ;
}
static void
F_45 ( struct V_43 * V_62 , int V_63 , struct V_64 * V_65 )
{
F_46 ( V_65 , L_2 , V_63 ) ;
F_46 ( V_65 , L_3 , ( V_22 ) V_62 -> V_66 ) ;
F_46 ( V_65 , L_4 , ( V_22 ) V_62 -> V_24 ) ;
F_46 ( V_65 , L_5 ,
( long long ) V_62 -> V_67 ) ;
F_46 ( V_65 , L_6 , ( V_22 ) V_62 -> V_49 ) ;
F_46 ( V_65 , L_7 ,
( V_22 ) V_62 -> V_53 ) ;
F_46 ( V_65 , L_8 , ( V_22 ) V_62 -> V_61 ) ;
F_46 ( V_65 , L_9 ,
( long long ) V_62 -> V_68 ) ;
F_46 ( V_65 , L_10 ,
( long long ) V_62 -> V_58 ) ;
F_46 ( V_65 , L_11 ,
( long long ) V_62 -> V_54 ) ;
F_46 ( V_65 , L_12 ,
( long long ) V_62 -> V_57 ) ;
F_46 ( V_65 , L_13 , ( V_22 ) V_62 -> V_51 ) ;
F_46 ( V_65 , L_14 , ( V_22 ) V_62 -> V_52 ) ;
}
void
F_47 ( struct V_1 * V_8 , int V_69 ,
struct V_64 * V_65 , T_7 V_5 )
{
T_1 V_70 = 0 ;
V_22 V_20 = 0 , V_71 = 0 ;
struct V_11 V_72 ;
struct V_11 * V_73 = & V_72 ;
int V_74 = 0 ;
int V_75 = 0 ;
if ( ! V_8 )
return;
V_70 = F_14 ( V_8 ) ;
V_71 = F_15 ( V_8 ) ;
V_75 = F_8 ( V_8 , V_5 ,
V_73 , sizeof( struct V_11 ) ) ;
if ( V_75 < 0 ) {
F_46 ( V_65 ,
L_15 ,
V_75 ) ;
if ( V_5 == 0 ) {
V_73 = & V_8 -> V_21 ;
F_48 ( V_65 , L_16 ) ;
} else {
return;
}
}
V_20 = ( V_22 ) ( V_73 -> V_10 ) ;
F_46 ( V_65 , L_17 ,
V_70 + V_5 , V_20 , V_71 ) ;
F_46 ( V_65 , L_18 , & V_73 -> V_24 ) ;
F_46 ( V_65 , L_19 , & V_73 -> V_26 ) ;
F_46 ( V_65 , L_20 ,
( long long ) V_73 -> V_76 ) ;
F_46 ( V_65 , L_21 , ( V_22 ) V_73 -> V_77 ) ;
F_46 ( V_65 , L_22 , ( V_22 ) V_73 -> V_78 ) ;
F_46 ( V_65 , L_23 , ( V_22 ) V_73 -> V_79 ) ;
F_46 ( V_65 , L_24 , ( V_22 ) V_73 -> V_80 ) ;
F_46 ( V_65 , L_25 , ( V_22 ) V_73 -> V_81 ) ;
F_46 ( V_65 , L_26 , ( long long ) V_73 -> V_10 ) ;
F_46 ( V_65 , L_27 ,
( long long ) V_73 -> V_68 ) ;
F_46 ( V_65 , L_28 ,
( long long ) V_73 -> V_27 ) ;
F_46 ( V_65 , L_29 ,
( long long ) V_73 -> V_82 ) ;
F_46 ( V_65 , L_30 , ( V_22 ) V_73 -> V_83 ) ;
F_46 ( V_65 , L_31 ,
( long long ) V_73 -> V_45 ) ;
if ( ( V_73 -> V_45 == 0 ) || ( V_75 < 0 ) )
;
else
for ( V_74 = 0 ; V_74 < V_69 ; V_74 ++ ) {
struct V_43 V_62 ;
V_75 = F_8 ( V_8 ,
V_5 +
V_73 -> V_45 +
( V_74 * sizeof( V_62 ) ) ,
& V_62 , sizeof( V_62 ) ) ;
if ( V_75 < 0 ) {
F_46 ( V_65 ,
L_32 ,
V_74 , V_70 , V_75 ) ;
continue;
}
F_45 ( & V_62 , V_74 , V_65 ) ;
}
F_46 ( V_65 , L_33 ,
V_70 + V_5 , V_20 ) ;
}
