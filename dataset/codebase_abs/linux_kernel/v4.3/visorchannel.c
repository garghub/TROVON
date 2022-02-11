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
goto V_12;
V_8 -> V_7 = V_7 ;
F_3 ( & V_8 -> V_13 ) ;
F_3 ( & V_8 -> V_14 ) ;
V_8 -> V_15 = F_4 ( V_2 , V_10 , V_16 ) ;
if ( ! V_8 -> V_15 ) {
if ( F_5 ( V_6 , V_17 ) ) {
goto V_12;
}
}
V_8 -> V_18 = F_6 ( V_2 , V_10 , V_19 ) ;
if ( ! V_8 -> V_18 ) {
F_7 ( V_2 , V_10 ) ;
goto V_12;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_20 = V_10 ;
V_9 = F_8 ( V_8 , 0 , & V_8 -> V_21 ,
sizeof( struct V_11 ) ) ;
if ( V_9 )
goto V_12;
if ( V_3 == 0 )
V_3 = ( V_22 ) V_8 -> V_21 . V_10 ;
if ( F_5 ( V_6 , V_23 ) == 0 )
V_6 = V_8 -> V_21 . V_24 ;
F_9 ( V_8 -> V_18 ) ;
if ( V_8 -> V_15 )
F_7 ( V_8 -> V_2 , V_8 -> V_20 ) ;
V_8 -> V_18 = NULL ;
V_8 -> V_15 = F_4 ( V_8 -> V_2 ,
V_3 , V_16 ) ;
if ( ! V_8 -> V_15 ) {
if ( F_5 ( V_6 , V_17 ) ) {
goto V_12;
}
}
V_8 -> V_18 = F_6 ( V_8 -> V_2 , V_3 ,
V_19 ) ;
if ( ! V_8 -> V_18 ) {
F_7 ( V_8 -> V_2 , V_3 ) ;
goto V_12;
}
V_8 -> V_20 = V_3 ;
V_8 -> V_10 = V_3 ;
V_8 -> V_6 = V_6 ;
return V_8 ;
V_12:
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
if ( V_8 -> V_15 )
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
goto V_12;
V_36 += V_40 ;
V_20 -= V_40 ;
}
V_9 = 0 ;
V_12:
F_26 ( ( unsigned long ) V_37 ) ;
return V_9 ;
}
void T_6 *
F_27 ( struct V_1 * V_8 )
{
return ( void T_6 * ) & V_8 -> V_21 ;
}
static bool
F_28 ( struct V_1 * V_8 , T_7 V_41 ,
struct V_42 * V_43 )
{
int V_9 ;
if ( V_8 -> V_21 . V_44 < sizeof( struct V_11 ) )
return false ;
V_9 = F_8 ( V_8 ,
F_29 ( & V_8 -> V_21 , V_41 ) ,
V_43 , sizeof( struct V_42 ) ) ;
if ( V_9 )
return false ;
return true ;
}
static inline bool
F_30 ( struct V_1 * V_8 , T_7 V_41 ,
struct V_42 * V_43 , T_7 V_45 , void * V_46 )
{
int V_9 ;
int V_47 = F_31 ( & V_8 -> V_21 , V_41 ,
V_43 , V_45 ) ;
V_9 = F_8 ( V_8 , V_47 ,
V_46 , V_43 -> V_48 ) ;
if ( V_9 )
return false ;
return true ;
}
static inline bool
F_32 ( struct V_1 * V_8 , T_7 V_41 ,
struct V_42 * V_43 , T_7 V_45 , void * V_46 )
{
int V_9 ;
int V_47 = F_31 ( & V_8 -> V_21 , V_41 ,
V_43 , V_45 ) ;
V_9 = F_22 ( V_8 , V_47 ,
V_46 , V_43 -> V_48 ) ;
if ( V_9 )
return false ;
return true ;
}
static bool
F_33 ( struct V_1 * V_8 , T_7 V_41 , void * V_49 )
{
struct V_42 V_43 ;
if ( ! F_28 ( V_8 , V_41 , & V_43 ) )
return false ;
if ( V_43 . V_50 == V_43 . V_51 )
return false ;
V_43 . V_51 = ( V_43 . V_51 + 1 ) % V_43 . V_52 ;
if ( ! F_30 ( V_8 , V_41 , & V_43 , V_43 . V_51 , V_49 ) )
return false ;
V_43 . V_53 ++ ;
F_34 () ;
if ( ! F_35 ( V_8 , V_41 , & V_43 , V_51 ) )
return false ;
if ( ! F_35 ( V_8 , V_41 , & V_43 , V_53 ) )
return false ;
return true ;
}
bool
F_36 ( struct V_1 * V_8 , T_7 V_41 , void * V_49 )
{
bool V_54 ;
unsigned long V_55 ;
if ( V_8 -> V_7 ) {
F_37 ( & V_8 -> V_14 , V_55 ) ;
V_54 = F_33 ( V_8 , V_41 , V_49 ) ;
F_38 ( & V_8 -> V_14 , V_55 ) ;
} else {
V_54 = F_33 ( V_8 , V_41 , V_49 ) ;
}
return V_54 ;
}
bool
F_39 ( struct V_1 * V_8 , T_7 V_41 )
{
unsigned long V_55 = 0 ;
struct V_42 V_43 ;
bool V_54 = false ;
if ( V_8 -> V_7 )
F_37 ( & V_8 -> V_14 , V_55 ) ;
if ( ! F_28 ( V_8 , V_41 , & V_43 ) )
V_54 = true ;
if ( V_43 . V_50 == V_43 . V_51 )
V_54 = true ;
if ( V_8 -> V_7 )
F_38 ( & V_8 -> V_14 , V_55 ) ;
return V_54 ;
}
static bool
F_40 ( struct V_1 * V_8 , T_7 V_41 , void * V_49 )
{
struct V_42 V_43 ;
if ( ! F_28 ( V_8 , V_41 , & V_43 ) )
return false ;
V_43 . V_50 = ( ( V_43 . V_50 + 1 ) % V_43 . V_52 ) ;
if ( V_43 . V_50 == V_43 . V_51 ) {
V_43 . V_56 ++ ;
F_22 ( V_8 ,
F_29 ( & V_8 -> V_21 , V_41 ) +
F_41 ( struct V_42 ,
V_56 ) ,
& ( V_43 . V_56 ) ,
sizeof( V_43 . V_56 ) ) ;
return false ;
}
if ( ! F_32 ( V_8 , V_41 , & V_43 , V_43 . V_50 , V_49 ) )
return false ;
V_43 . V_57 ++ ;
F_34 () ;
if ( ! F_35 ( V_8 , V_41 , & V_43 , V_50 ) )
return false ;
if ( ! F_35 ( V_8 , V_41 , & V_43 , V_57 ) )
return false ;
return true ;
}
bool
F_42 ( struct V_1 * V_8 , T_7 V_41 , void * V_49 )
{
bool V_54 ;
unsigned long V_55 ;
if ( V_8 -> V_7 ) {
F_37 ( & V_8 -> V_13 , V_55 ) ;
V_54 = F_40 ( V_8 , V_41 , V_49 ) ;
F_38 ( & V_8 -> V_13 , V_55 ) ;
} else {
V_54 = F_40 ( V_8 , V_41 , V_49 ) ;
}
return V_54 ;
}
int
F_43 ( struct V_1 * V_8 , T_7 V_41 )
{
struct V_42 V_43 ;
T_7 V_58 , V_59 ;
T_7 V_50 , V_51 ;
if ( ! F_28 ( V_8 , V_41 , & V_43 ) )
return 0 ;
V_50 = V_43 . V_50 ;
V_51 = V_43 . V_51 ;
if ( V_50 < V_51 )
V_50 = V_50 + V_43 . V_52 ;
V_59 = ( V_50 - V_51 ) ;
V_58 = V_43 . V_60 - V_59 ;
return ( int ) V_58 ;
}
int
F_44 ( struct V_1 * V_8 , T_7 V_41 )
{
struct V_42 V_43 ;
if ( ! F_28 ( V_8 , V_41 , & V_43 ) )
return 0 ;
return ( int ) V_43 . V_60 ;
}
static void
F_45 ( struct V_42 * V_61 , int V_62 , struct V_63 * V_64 )
{
F_46 ( V_64 , L_2 , V_62 ) ;
F_46 ( V_64 , L_3 , ( V_22 ) V_61 -> V_65 ) ;
F_46 ( V_64 , L_4 , ( V_22 ) V_61 -> V_24 ) ;
F_46 ( V_64 , L_5 ,
( long long ) V_61 -> V_66 ) ;
F_46 ( V_64 , L_6 , ( V_22 ) V_61 -> V_48 ) ;
F_46 ( V_64 , L_7 ,
( V_22 ) V_61 -> V_52 ) ;
F_46 ( V_64 , L_8 , ( V_22 ) V_61 -> V_60 ) ;
F_46 ( V_64 , L_9 ,
( long long ) V_61 -> V_67 ) ;
F_46 ( V_64 , L_10 ,
( long long ) V_61 -> V_57 ) ;
F_46 ( V_64 , L_11 ,
( long long ) V_61 -> V_53 ) ;
F_46 ( V_64 , L_12 ,
( long long ) V_61 -> V_56 ) ;
F_46 ( V_64 , L_13 , ( V_22 ) V_61 -> V_50 ) ;
F_46 ( V_64 , L_14 , ( V_22 ) V_61 -> V_51 ) ;
}
void
F_47 ( struct V_1 * V_8 , int V_68 ,
struct V_63 * V_64 , T_7 V_5 )
{
T_1 V_69 = 0 ;
V_22 V_20 = 0 , V_70 = 0 ;
struct V_11 V_71 ;
struct V_11 * V_72 = & V_71 ;
int V_73 = 0 ;
int V_74 = 0 ;
if ( ! V_8 )
return;
V_69 = F_14 ( V_8 ) ;
V_70 = F_15 ( V_8 ) ;
V_74 = F_8 ( V_8 , V_5 ,
V_72 , sizeof( struct V_11 ) ) ;
if ( V_74 < 0 ) {
F_46 ( V_64 ,
L_15 ,
V_74 ) ;
if ( V_5 == 0 ) {
V_72 = & V_8 -> V_21 ;
F_48 ( V_64 , L_16 ) ;
} else {
return;
}
}
V_20 = ( V_22 ) ( V_72 -> V_10 ) ;
F_46 ( V_64 , L_17 ,
V_69 + V_5 , V_20 , V_70 ) ;
F_46 ( V_64 , L_18 , & V_72 -> V_24 ) ;
F_46 ( V_64 , L_19 , & V_72 -> V_26 ) ;
F_46 ( V_64 , L_20 ,
( long long ) V_72 -> V_75 ) ;
F_46 ( V_64 , L_21 , ( V_22 ) V_72 -> V_76 ) ;
F_46 ( V_64 , L_22 , ( V_22 ) V_72 -> V_77 ) ;
F_46 ( V_64 , L_23 , ( V_22 ) V_72 -> V_78 ) ;
F_46 ( V_64 , L_24 , ( V_22 ) V_72 -> V_79 ) ;
F_46 ( V_64 , L_25 , ( V_22 ) V_72 -> V_80 ) ;
F_46 ( V_64 , L_26 , ( long long ) V_72 -> V_10 ) ;
F_46 ( V_64 , L_27 ,
( long long ) V_72 -> V_67 ) ;
F_46 ( V_64 , L_28 ,
( long long ) V_72 -> V_27 ) ;
F_46 ( V_64 , L_29 ,
( long long ) V_72 -> V_81 ) ;
F_46 ( V_64 , L_30 , ( V_22 ) V_72 -> V_82 ) ;
F_46 ( V_64 , L_31 ,
( long long ) V_72 -> V_44 ) ;
if ( ( V_72 -> V_44 == 0 ) || ( V_74 < 0 ) )
;
else
for ( V_73 = 0 ; V_73 < V_68 ; V_73 ++ ) {
struct V_42 V_61 ;
V_74 = F_8 ( V_8 ,
V_5 +
V_72 -> V_44 +
( V_73 * sizeof( V_61 ) ) ,
& V_61 , sizeof( V_61 ) ) ;
if ( V_74 < 0 ) {
F_46 ( V_64 ,
L_32 ,
V_73 , V_69 , V_74 ) ;
continue;
}
F_45 ( & V_61 , V_73 , V_64 ) ;
}
F_46 ( V_64 , L_33 ,
V_69 + V_5 , V_20 ) ;
}
