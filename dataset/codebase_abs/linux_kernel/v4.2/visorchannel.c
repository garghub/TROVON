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
V_8 -> V_18 = F_6 ( V_2 , V_10 ) ;
if ( ! V_8 -> V_18 ) {
F_7 ( V_2 , V_10 ) ;
goto V_12;
}
V_8 -> V_2 = V_2 ;
V_8 -> V_19 = V_10 ;
V_9 = F_8 ( V_8 , 0 , & V_8 -> V_20 ,
sizeof( struct V_11 ) ) ;
if ( V_9 )
goto V_12;
if ( V_3 == 0 )
V_3 = ( V_21 ) V_8 -> V_20 . V_10 ;
if ( F_5 ( V_6 , V_22 ) == 0 )
V_6 = V_8 -> V_20 . V_23 ;
F_9 ( V_8 -> V_18 ) ;
if ( V_8 -> V_15 )
F_7 ( V_8 -> V_2 , V_8 -> V_19 ) ;
V_8 -> V_18 = NULL ;
V_8 -> V_15 = F_4 ( V_8 -> V_2 ,
V_3 , V_16 ) ;
if ( ! V_8 -> V_15 ) {
if ( F_5 ( V_6 , V_17 ) ) {
goto V_12;
}
}
V_8 -> V_18 = F_6 ( V_8 -> V_2 , V_3 ) ;
if ( ! V_8 -> V_18 ) {
F_7 ( V_8 -> V_2 , V_3 ) ;
goto V_12;
}
V_8 -> V_19 = V_3 ;
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
F_7 ( V_8 -> V_2 , V_8 -> V_19 ) ;
}
F_13 ( V_8 ) ;
}
T_1
F_14 ( struct V_1 * V_8 )
{
return V_8 -> V_2 ;
}
V_21
F_15 ( struct V_1 * V_8 )
{
return V_8 -> V_10 ;
}
char *
F_16 ( T_3 * V_6 , char * V_24 )
{
sprintf ( V_24 , L_1 , V_6 ) ;
return V_24 ;
}
char *
F_17 ( struct V_1 * V_8 , char * V_24 )
{
return F_16 ( & V_8 -> V_6 , V_24 ) ;
}
char *
F_18 ( struct V_1 * V_8 , char * V_24 )
{
return F_16 ( & V_8 -> V_20 . V_25 , V_24 ) ;
}
T_1
F_19 ( struct V_1 * V_8 )
{
return V_8 -> V_20 . V_26 ;
}
int
F_20 ( struct V_1 * V_8 ,
T_1 V_26 )
{
V_8 -> V_20 . V_26 = V_26 ;
return 0 ;
}
T_3
F_21 ( struct V_1 * V_8 )
{
return V_8 -> V_6 ;
}
int
F_8 ( struct V_1 * V_8 , V_21 V_27 ,
void * V_28 , V_21 V_19 )
{
if ( V_27 + V_19 > V_8 -> V_19 )
return - V_29 ;
F_22 ( V_28 , V_8 -> V_18 + V_27 , V_19 ) ;
return 0 ;
}
int
F_23 ( struct V_1 * V_8 , V_21 V_27 ,
void * V_28 , V_21 V_19 )
{
T_4 V_30 = sizeof( struct V_11 ) ;
T_4 V_31 ;
if ( V_27 + V_19 > V_8 -> V_19 )
return - V_29 ;
if ( V_27 < V_30 ) {
V_31 = F_24 ( V_30 - V_27 , V_19 ) ;
memcpy ( & V_8 -> V_20 + V_27 , V_28 , V_31 ) ;
}
F_25 ( V_8 -> V_18 + V_27 , V_28 , V_19 ) ;
return 0 ;
}
int
F_26 ( struct V_1 * V_8 , V_21 V_27 , T_5 V_32 ,
V_21 V_19 )
{
int V_9 ;
int V_33 = V_34 ;
int V_35 = 0 ;
T_5 * V_36 ;
V_36 = ( T_5 * ) F_27 ( V_37 ) ;
if ( ! V_36 )
return - V_38 ;
memset ( V_36 , V_32 , V_33 ) ;
while ( V_19 > 0 ) {
int V_39 = V_33 ;
if ( V_19 < V_39 )
V_39 = V_19 ;
V_9 = F_23 ( V_8 , V_27 + V_35 ,
V_36 , V_39 ) ;
if ( V_9 )
goto V_12;
V_35 += V_39 ;
V_19 -= V_39 ;
}
V_9 = 0 ;
V_12:
F_28 ( ( unsigned long ) V_36 ) ;
return V_9 ;
}
void T_6 *
F_29 ( struct V_1 * V_8 )
{
return ( void T_6 * ) & V_8 -> V_20 ;
}
static bool
F_30 ( struct V_1 * V_8 , T_7 V_40 ,
struct V_41 * V_42 )
{
int V_9 ;
if ( V_8 -> V_20 . V_43 < sizeof( struct V_11 ) )
return false ;
V_9 = F_8 ( V_8 ,
F_31 ( & V_8 -> V_20 , V_40 ) ,
V_42 , sizeof( struct V_41 ) ) ;
if ( V_9 )
return false ;
return true ;
}
static inline bool
F_32 ( struct V_1 * V_8 , T_7 V_40 ,
struct V_41 * V_42 , T_7 V_44 , void * V_45 )
{
int V_9 ;
int V_46 = F_33 ( & V_8 -> V_20 , V_40 ,
V_42 , V_44 ) ;
V_9 = F_8 ( V_8 , V_46 ,
V_45 , V_42 -> V_47 ) ;
if ( V_9 )
return false ;
return true ;
}
static inline bool
F_34 ( struct V_1 * V_8 , T_7 V_40 ,
struct V_41 * V_42 , T_7 V_44 , void * V_45 )
{
int V_9 ;
int V_46 = F_33 ( & V_8 -> V_20 , V_40 ,
V_42 , V_44 ) ;
V_9 = F_23 ( V_8 , V_46 ,
V_45 , V_42 -> V_47 ) ;
if ( V_9 )
return false ;
return true ;
}
static bool
F_35 ( struct V_1 * V_8 , T_7 V_40 , void * V_48 )
{
struct V_41 V_42 ;
if ( ! F_30 ( V_8 , V_40 , & V_42 ) )
return false ;
if ( V_42 . V_49 == V_42 . V_50 )
return false ;
V_42 . V_50 = ( V_42 . V_50 + 1 ) % V_42 . V_51 ;
if ( ! F_32 ( V_8 , V_40 , & V_42 , V_42 . V_50 , V_48 ) )
return false ;
V_42 . V_52 ++ ;
F_36 () ;
if ( ! F_37 ( V_8 , V_40 , & V_42 , V_50 ) )
return false ;
if ( ! F_37 ( V_8 , V_40 , & V_42 , V_52 ) )
return false ;
return true ;
}
bool
F_38 ( struct V_1 * V_8 , T_7 V_40 , void * V_48 )
{
bool V_53 ;
if ( V_8 -> V_7 ) {
F_39 ( & V_8 -> V_14 ) ;
V_53 = F_35 ( V_8 , V_40 , V_48 ) ;
F_40 ( & V_8 -> V_14 ) ;
} else {
V_53 = F_35 ( V_8 , V_40 , V_48 ) ;
}
return V_53 ;
}
static bool
F_41 ( struct V_1 * V_8 , T_7 V_40 , void * V_48 )
{
struct V_41 V_42 ;
if ( ! F_30 ( V_8 , V_40 , & V_42 ) )
return false ;
V_42 . V_49 = ( ( V_42 . V_49 + 1 ) % V_42 . V_51 ) ;
if ( V_42 . V_49 == V_42 . V_50 ) {
V_42 . V_54 ++ ;
F_23 ( V_8 ,
F_31 ( & V_8 -> V_20 , V_40 ) +
F_42 ( struct V_41 ,
V_54 ) ,
& ( V_42 . V_54 ) ,
sizeof( V_42 . V_54 ) ) ;
return false ;
}
if ( ! F_34 ( V_8 , V_40 , & V_42 , V_42 . V_49 , V_48 ) )
return false ;
V_42 . V_55 ++ ;
F_36 () ;
if ( ! F_37 ( V_8 , V_40 , & V_42 , V_49 ) )
return false ;
if ( ! F_37 ( V_8 , V_40 , & V_42 , V_55 ) )
return false ;
return true ;
}
bool
F_43 ( struct V_1 * V_8 , T_7 V_40 , void * V_48 )
{
bool V_53 ;
if ( V_8 -> V_7 ) {
F_39 ( & V_8 -> V_13 ) ;
V_53 = F_41 ( V_8 , V_40 , V_48 ) ;
F_40 ( & V_8 -> V_13 ) ;
} else {
V_53 = F_41 ( V_8 , V_40 , V_48 ) ;
}
return V_53 ;
}
int
F_44 ( struct V_1 * V_8 , T_7 V_40 )
{
struct V_41 V_42 ;
T_7 V_56 , V_57 ;
T_7 V_49 , V_50 ;
if ( ! F_30 ( V_8 , V_40 , & V_42 ) )
return 0 ;
V_49 = V_42 . V_49 ;
V_50 = V_42 . V_50 ;
if ( V_49 < V_50 )
V_49 = V_49 + V_42 . V_51 ;
V_57 = ( V_49 - V_50 ) ;
V_56 = V_42 . V_58 - V_57 ;
return ( int ) V_56 ;
}
int
F_45 ( struct V_1 * V_8 , T_7 V_40 )
{
struct V_41 V_42 ;
if ( ! F_30 ( V_8 , V_40 , & V_42 ) )
return 0 ;
return ( int ) V_42 . V_58 ;
}
static void
F_46 ( struct V_41 * V_59 , int V_60 , struct V_61 * V_62 )
{
F_47 ( V_62 , L_2 , V_60 ) ;
F_47 ( V_62 , L_3 , ( V_21 ) V_59 -> V_63 ) ;
F_47 ( V_62 , L_4 , ( V_21 ) V_59 -> V_23 ) ;
F_47 ( V_62 , L_5 ,
( long long ) V_59 -> V_64 ) ;
F_47 ( V_62 , L_6 , ( V_21 ) V_59 -> V_47 ) ;
F_47 ( V_62 , L_7 ,
( V_21 ) V_59 -> V_51 ) ;
F_47 ( V_62 , L_8 , ( V_21 ) V_59 -> V_58 ) ;
F_47 ( V_62 , L_9 ,
( long long ) V_59 -> V_65 ) ;
F_47 ( V_62 , L_10 ,
( long long ) V_59 -> V_55 ) ;
F_47 ( V_62 , L_11 ,
( long long ) V_59 -> V_52 ) ;
F_47 ( V_62 , L_12 ,
( long long ) V_59 -> V_54 ) ;
F_47 ( V_62 , L_13 , ( V_21 ) V_59 -> V_49 ) ;
F_47 ( V_62 , L_14 , ( V_21 ) V_59 -> V_50 ) ;
}
void
F_48 ( struct V_1 * V_8 , int V_66 ,
struct V_61 * V_62 , T_7 V_5 )
{
T_1 V_67 = 0 ;
V_21 V_19 = 0 , V_68 = 0 ;
struct V_11 V_69 ;
struct V_11 * V_70 = & V_69 ;
int V_71 = 0 ;
int V_72 = 0 ;
if ( ! V_8 )
return;
V_67 = F_14 ( V_8 ) ;
V_68 = F_15 ( V_8 ) ;
V_72 = F_8 ( V_8 , V_5 ,
V_70 , sizeof( struct V_11 ) ) ;
if ( V_72 < 0 ) {
F_47 ( V_62 ,
L_15 ,
V_72 ) ;
if ( V_5 == 0 ) {
V_70 = & V_8 -> V_20 ;
F_49 ( V_62 , L_16 ) ;
} else {
return;
}
}
V_19 = ( V_21 ) ( V_70 -> V_10 ) ;
F_47 ( V_62 , L_17 ,
V_67 + V_5 , V_19 , V_68 ) ;
F_47 ( V_62 , L_18 , & V_70 -> V_23 ) ;
F_47 ( V_62 , L_19 , & V_70 -> V_25 ) ;
F_47 ( V_62 , L_20 ,
( long long ) V_70 -> V_73 ) ;
F_47 ( V_62 , L_21 , ( V_21 ) V_70 -> V_74 ) ;
F_47 ( V_62 , L_22 , ( V_21 ) V_70 -> V_75 ) ;
F_47 ( V_62 , L_23 , ( V_21 ) V_70 -> V_76 ) ;
F_47 ( V_62 , L_24 , ( V_21 ) V_70 -> V_77 ) ;
F_47 ( V_62 , L_25 , ( V_21 ) V_70 -> V_78 ) ;
F_47 ( V_62 , L_26 , ( long long ) V_70 -> V_10 ) ;
F_47 ( V_62 , L_27 ,
( long long ) V_70 -> V_65 ) ;
F_47 ( V_62 , L_28 ,
( long long ) V_70 -> V_26 ) ;
F_47 ( V_62 , L_29 ,
( long long ) V_70 -> V_79 ) ;
F_47 ( V_62 , L_30 , ( V_21 ) V_70 -> V_80 ) ;
F_47 ( V_62 , L_31 ,
( long long ) V_70 -> V_43 ) ;
if ( ( V_70 -> V_43 == 0 ) || ( V_72 < 0 ) )
;
else
for ( V_71 = 0 ; V_71 < V_66 ; V_71 ++ ) {
struct V_41 V_59 ;
V_72 = F_8 ( V_8 ,
V_5 +
V_70 -> V_43 +
( V_71 * sizeof( V_59 ) ) ,
& V_59 , sizeof( V_59 ) ) ;
if ( V_72 < 0 ) {
F_47 ( V_62 ,
L_32 ,
V_71 , V_67 , V_72 ) ;
continue;
}
F_46 ( & V_59 , V_71 , V_62 ) ;
}
F_47 ( V_62 , L_33 ,
V_67 + V_5 , V_19 ) ;
}
