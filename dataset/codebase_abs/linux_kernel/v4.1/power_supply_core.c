static bool F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
int V_4 ;
if ( ! V_3 -> V_5 && ! V_2 -> V_6 )
return false ;
if ( V_3 -> V_5 ) {
if ( ! V_2 -> V_7 -> V_8 )
return false ;
for ( V_4 = 0 ; V_4 < V_3 -> V_9 ; V_4 ++ )
if ( ! strcmp ( V_2 -> V_7 -> V_8 , V_3 -> V_5 [ V_4 ] ) )
return true ;
} else {
if ( ! V_3 -> V_7 -> V_8 )
return false ;
for ( V_4 = 0 ; V_4 < V_2 -> V_10 ; V_4 ++ )
if ( ! strcmp ( V_2 -> V_6 [ V_4 ] , V_3 -> V_7 -> V_8 ) )
return true ;
}
return false ;
}
static int F_2 ( struct V_11 * V_12 , void * V_13 )
{
struct V_1 * V_14 = V_13 ;
struct V_1 * V_15 = F_3 ( V_12 ) ;
if ( F_1 ( V_14 , V_15 ) ) {
if ( V_15 -> V_7 -> V_16 )
V_15 -> V_7 -> V_16 ( V_15 ) ;
}
return 0 ;
}
static void F_4 ( struct V_17 * V_18 )
{
unsigned long V_19 ;
struct V_1 * V_14 = F_5 ( V_18 , struct V_1 ,
V_20 ) ;
F_6 ( & V_14 -> V_12 , L_1 , V_21 ) ;
F_7 ( & V_14 -> V_22 , V_19 ) ;
if ( F_8 ( V_14 -> V_23 ) ) {
V_14 -> V_23 = false ;
F_9 ( & V_14 -> V_22 , V_19 ) ;
F_10 ( V_24 , NULL , V_14 ,
F_2 ) ;
F_11 ( V_14 ) ;
F_12 ( & V_25 ,
V_26 , V_14 ) ;
F_13 ( & V_14 -> V_12 . V_27 , V_28 ) ;
F_7 ( & V_14 -> V_22 , V_19 ) ;
}
if ( F_8 ( ! V_14 -> V_23 ) )
F_14 ( & V_14 -> V_12 ) ;
F_9 ( & V_14 -> V_22 , V_19 ) ;
}
void F_15 ( struct V_1 * V_14 )
{
unsigned long V_19 ;
F_6 ( & V_14 -> V_12 , L_1 , V_21 ) ;
F_7 ( & V_14 -> V_22 , V_19 ) ;
V_14 -> V_23 = true ;
F_16 ( & V_14 -> V_12 ) ;
F_9 ( & V_14 -> V_22 , V_19 ) ;
F_17 ( & V_14 -> V_20 ) ;
}
static int F_18 ( struct V_11 * V_12 ,
void * V_13 )
{
struct V_1 * V_14 = V_13 ;
struct V_1 * V_29 = F_3 ( V_12 ) ;
struct V_30 * V_31 ;
int V_4 = 0 ;
do {
V_31 = F_19 ( V_14 -> V_32 , L_2 , V_4 ++ ) ;
if ( ! V_31 )
break;
if ( V_31 == V_29 -> V_32 ) {
F_20 ( & V_14 -> V_12 , L_3 ,
V_14 -> V_7 -> V_8 , V_29 -> V_7 -> V_8 ) ;
V_14 -> V_5 [ V_4 - 1 ] = ( char * ) V_29 -> V_7 -> V_8 ;
V_14 -> V_9 ++ ;
F_21 ( V_31 ) ;
break;
}
F_21 ( V_31 ) ;
} while ( V_31 );
return 0 ;
}
static int F_22 ( struct V_1 * V_14 )
{
int error ;
error = F_10 ( V_24 , NULL , V_14 ,
F_18 ) ;
F_6 ( & V_14 -> V_12 , L_4 , V_21 , error ) ;
return error ;
}
static int F_23 ( struct V_11 * V_12 ,
void * V_13 )
{
struct V_30 * V_31 = V_13 ;
struct V_1 * V_29 = F_3 ( V_12 ) ;
if ( V_29 -> V_32 == V_31 )
return 1 ;
return 0 ;
}
static int F_24 ( struct V_30 * V_33 )
{
int error ;
error = F_10 ( V_24 , NULL , V_33 ,
F_23 ) ;
return error ? ( error == 1 ? 0 : error ) : - V_34 ;
}
static int F_25 ( struct V_1 * V_14 )
{
struct V_30 * V_31 ;
int V_35 = 0 ;
if ( V_14 -> V_5 && V_14 -> V_9 > 0 )
return 0 ;
if ( ! V_14 -> V_32 )
return 0 ;
do {
int V_36 ;
V_31 = F_19 ( V_14 -> V_32 , L_2 , V_35 ++ ) ;
if ( ! V_31 )
break;
V_36 = F_24 ( V_31 ) ;
F_21 ( V_31 ) ;
if ( V_36 ) {
F_6 ( & V_14 -> V_12 , L_5 ) ;
return V_36 ;
}
} while ( V_31 );
if ( V_35 == 1 )
return 0 ;
V_14 -> V_5 = F_26 ( & V_14 -> V_12 , sizeof( V_14 -> V_5 ) ,
V_37 ) ;
if ( ! V_14 -> V_5 ) {
F_27 ( & V_14 -> V_12 , L_6 ) ;
return - V_38 ;
}
* V_14 -> V_5 = F_26 ( & V_14 -> V_12 ,
sizeof( char * ) * ( V_35 - 1 ) ,
V_37 ) ;
if ( ! * V_14 -> V_5 ) {
F_27 ( & V_14 -> V_12 , L_6 ) ;
return - V_38 ;
}
return F_22 ( V_14 ) ;
}
static inline int F_25 ( struct V_1 * V_14 )
{
return 0 ;
}
static int F_28 ( struct V_11 * V_12 , void * V_13 )
{
union V_39 V_36 = { 0 ,} ;
struct V_1 * V_14 = V_13 ;
struct V_1 * V_29 = F_3 ( V_12 ) ;
if ( F_1 ( V_29 , V_14 ) )
if ( ! V_29 -> V_7 -> V_40 ( V_29 , V_41 ,
& V_36 ) )
return V_36 . V_42 ;
return 0 ;
}
int F_29 ( struct V_1 * V_14 )
{
int error ;
error = F_10 ( V_24 , NULL , V_14 ,
F_28 ) ;
F_6 ( & V_14 -> V_12 , L_4 , V_21 , error ) ;
return error ;
}
static int F_30 ( struct V_11 * V_12 , void * V_13 )
{
union V_39 V_36 = { 0 ,} ;
struct V_1 * V_14 = F_3 ( V_12 ) ;
unsigned int * V_43 = V_13 ;
( * V_43 ) ++ ;
if ( V_14 -> V_7 -> type != V_44 )
if ( ! V_14 -> V_7 -> V_40 ( V_14 , V_41 ,
& V_36 ) )
return V_36 . V_42 ;
return 0 ;
}
int F_31 ( void )
{
int error ;
unsigned int V_43 = 0 ;
error = F_10 ( V_24 , NULL , & V_43 ,
F_30 ) ;
if ( V_43 == 0 )
return 1 ;
return error ;
}
int F_32 ( struct V_1 * V_14 )
{
if ( F_33 ( & V_14 -> V_45 ) >= 0 &&
V_14 -> V_7 -> type == V_44 &&
V_14 -> V_7 -> V_46 ) {
V_14 -> V_7 -> V_46 ( V_14 ) ;
return 0 ;
}
return - V_47 ;
}
static int F_34 ( struct V_11 * V_12 , const void * V_13 )
{
const char * V_8 = V_13 ;
struct V_1 * V_14 = F_3 ( V_12 ) ;
return strcmp ( V_14 -> V_7 -> V_8 , V_8 ) == 0 ;
}
struct V_1 * F_35 ( const char * V_8 )
{
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 = F_36 ( V_24 , NULL , V_8 ,
F_34 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_37 ( & V_14 -> V_45 ) ;
}
return V_14 ;
}
void F_38 ( struct V_1 * V_14 )
{
F_39 () ;
F_40 ( & V_14 -> V_45 ) ;
F_41 ( & V_14 -> V_12 ) ;
}
static int F_42 ( struct V_11 * V_12 , const void * V_13 )
{
return V_12 -> V_48 && V_12 -> V_48 -> V_32 == V_13 ;
}
struct V_1 * F_43 ( struct V_30 * V_31 ,
const char * V_49 )
{
struct V_30 * V_50 ;
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 ;
V_50 = F_19 ( V_31 , V_49 , 0 ) ;
if ( ! V_50 )
return F_44 ( - V_51 ) ;
V_12 = F_36 ( V_24 , NULL , V_50 ,
F_42 ) ;
F_21 ( V_50 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_37 ( & V_14 -> V_45 ) ;
}
return V_14 ;
}
int F_45 ( struct V_1 * V_14 ,
enum V_52 V_53 ,
union V_39 * V_54 )
{
if ( F_33 ( & V_14 -> V_45 ) <= 0 )
return - V_51 ;
return V_14 -> V_7 -> V_40 ( V_14 , V_53 , V_54 ) ;
}
int F_46 ( struct V_1 * V_14 ,
enum V_52 V_53 ,
const union V_39 * V_54 )
{
if ( F_33 ( & V_14 -> V_45 ) <= 0 || ! V_14 -> V_7 -> V_55 )
return - V_51 ;
return V_14 -> V_7 -> V_55 ( V_14 , V_53 , V_54 ) ;
}
int F_47 ( struct V_1 * V_14 ,
enum V_52 V_53 )
{
if ( F_33 ( & V_14 -> V_45 ) <= 0 ||
! V_14 -> V_7 -> V_56 )
return - V_51 ;
return V_14 -> V_7 -> V_56 ( V_14 , V_53 ) ;
}
void F_48 ( struct V_1 * V_14 )
{
if ( F_33 ( & V_14 -> V_45 ) <= 0 ||
! V_14 -> V_7 -> V_16 )
return;
V_14 -> V_7 -> V_16 ( V_14 ) ;
}
int F_49 ( struct V_1 * V_14 , struct V_11 * V_12 )
{
return F_50 ( & V_14 -> V_12 . V_27 , & V_12 -> V_27 , L_7 ) ;
}
static void F_51 ( struct V_11 * V_12 )
{
struct V_1 * V_14 = F_5 ( V_12 , struct V_1 , V_12 ) ;
F_52 ( L_8 , F_53 ( V_12 ) , V_21 ) ;
F_54 ( V_14 ) ;
}
int F_55 ( struct V_57 * V_58 )
{
return F_56 ( & V_25 , V_58 ) ;
}
void F_57 ( struct V_57 * V_58 )
{
F_58 ( & V_25 , V_58 ) ;
}
static int F_59 ( struct V_59 * V_60 ,
unsigned long * V_61 )
{
struct V_1 * V_14 ;
union V_39 V_54 ;
int V_36 ;
F_60 ( V_60 == NULL ) ;
V_14 = V_60 -> V_62 ;
V_36 = V_14 -> V_7 -> V_40 ( V_14 , V_63 , & V_54 ) ;
if ( ! V_36 )
* V_61 = V_54 . V_42 * 100 ;
return V_36 ;
}
static int F_61 ( struct V_1 * V_14 )
{
int V_4 ;
if ( V_14 -> V_7 -> V_64 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_65 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_66 [ V_4 ] == V_63 ) {
V_14 -> V_60 = F_62 ( V_14 -> V_7 -> V_8 ,
0 , 0 , V_14 , & V_67 , NULL , 0 , 0 ) ;
return F_63 ( V_14 -> V_60 ) ;
}
}
return 0 ;
}
static void F_64 ( struct V_1 * V_14 )
{
if ( F_65 ( V_14 -> V_60 ) )
return;
F_66 ( V_14 -> V_60 ) ;
}
static int F_67 ( struct V_68 * V_69 ,
unsigned long * V_70 )
{
struct V_1 * V_14 ;
union V_39 V_54 ;
int V_36 ;
V_14 = V_69 -> V_62 ;
V_36 = V_14 -> V_7 -> V_40 ( V_14 ,
V_71 , & V_54 ) ;
if ( ! V_36 )
* V_70 = V_54 . V_42 ;
return V_36 ;
}
static int F_68 ( struct V_68 * V_69 ,
unsigned long * V_70 )
{
struct V_1 * V_14 ;
union V_39 V_54 ;
int V_36 ;
V_14 = V_69 -> V_62 ;
V_36 = V_14 -> V_7 -> V_40 ( V_14 ,
V_72 , & V_54 ) ;
if ( ! V_36 )
* V_70 = V_54 . V_42 ;
return V_36 ;
}
static int F_69 ( struct V_68 * V_69 ,
unsigned long V_70 )
{
struct V_1 * V_14 ;
union V_39 V_54 ;
int V_36 ;
V_14 = V_69 -> V_62 ;
V_54 . V_42 = V_70 ;
V_36 = V_14 -> V_7 -> V_55 ( V_14 ,
V_72 , & V_54 ) ;
return V_36 ;
}
static int F_70 ( struct V_1 * V_14 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_65 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_66 [ V_4 ] ==
V_72 ) {
V_14 -> V_69 = F_71 (
( char * ) V_14 -> V_7 -> V_8 ,
V_14 , & V_73 ) ;
return F_63 ( V_14 -> V_69 ) ;
}
}
return 0 ;
}
static void F_72 ( struct V_1 * V_14 )
{
if ( F_65 ( V_14 -> V_69 ) )
return;
F_73 ( V_14 -> V_69 ) ;
}
static int F_61 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_64 ( struct V_1 * V_14 )
{
}
static int F_70 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_72 ( struct V_1 * V_14 )
{
}
static struct V_1 * T_1
F_74 ( struct V_11 * V_48 ,
const struct V_74 * V_7 ,
const struct V_75 * V_76 ,
bool V_77 )
{
struct V_11 * V_12 ;
struct V_1 * V_14 ;
int V_78 ;
V_14 = F_75 ( sizeof( * V_14 ) , V_37 ) ;
if ( ! V_14 )
return F_44 ( - V_38 ) ;
V_12 = & V_14 -> V_12 ;
F_76 ( V_12 ) ;
V_12 -> V_79 = V_24 ;
V_12 -> type = & V_80 ;
V_12 -> V_48 = V_48 ;
V_12 -> V_81 = F_51 ;
F_77 ( V_12 , V_14 ) ;
V_14 -> V_7 = V_7 ;
F_37 ( & V_14 -> V_45 ) ;
if ( V_76 ) {
V_14 -> V_82 = V_76 -> V_82 ;
V_14 -> V_32 = V_76 -> V_32 ;
V_14 -> V_6 = V_76 -> V_6 ;
V_14 -> V_10 = V_76 -> V_10 ;
}
V_78 = F_78 ( V_12 , L_9 , V_7 -> V_8 ) ;
if ( V_78 )
goto V_83;
F_79 ( & V_14 -> V_20 , F_4 ) ;
V_78 = F_25 ( V_14 ) ;
if ( V_78 ) {
F_20 ( V_12 , L_10 ) ;
goto V_84;
}
F_80 ( & V_14 -> V_22 ) ;
V_78 = F_81 ( V_12 , V_77 ) ;
if ( V_78 )
goto V_85;
V_78 = F_82 ( V_12 ) ;
if ( V_78 )
goto V_86;
V_78 = F_61 ( V_14 ) ;
if ( V_78 )
goto V_87;
V_78 = F_70 ( V_14 ) ;
if ( V_78 )
goto V_88;
V_78 = F_83 ( V_14 ) ;
if ( V_78 )
goto V_89;
F_15 ( V_14 ) ;
return V_14 ;
V_89:
F_72 ( V_14 ) ;
V_88:
F_64 ( V_14 ) ;
V_87:
F_84 ( V_12 ) ;
V_86:
V_85:
V_84:
V_83:
F_41 ( V_12 ) ;
return F_44 ( V_78 ) ;
}
struct V_1 * T_1 F_85 ( struct V_11 * V_48 ,
const struct V_74 * V_7 ,
const struct V_75 * V_76 )
{
return F_74 ( V_48 , V_7 , V_76 , true ) ;
}
struct V_1 * T_1
F_86 ( struct V_11 * V_48 ,
const struct V_74 * V_7 ,
const struct V_75 * V_76 )
{
return F_74 ( V_48 , V_7 , V_76 , false ) ;
}
static void F_87 ( struct V_11 * V_12 , void * V_90 )
{
struct V_1 * * V_14 = V_90 ;
F_88 ( * V_14 ) ;
}
struct V_1 * T_1
F_89 ( struct V_11 * V_48 ,
const struct V_74 * V_7 ,
const struct V_75 * V_76 )
{
struct V_1 * * V_91 , * V_14 ;
V_91 = F_90 ( F_87 , sizeof( * V_91 ) , V_37 ) ;
if ( ! V_91 )
return F_44 ( - V_38 ) ;
V_14 = F_74 ( V_48 , V_7 , V_76 , true ) ;
if ( F_91 ( V_14 ) ) {
F_92 ( V_91 ) ;
} else {
* V_91 = V_14 ;
F_93 ( V_48 , V_91 ) ;
}
return V_14 ;
}
struct V_1 * T_1
F_94 ( struct V_11 * V_48 ,
const struct V_74 * V_7 ,
const struct V_75 * V_76 )
{
struct V_1 * * V_91 , * V_14 ;
V_91 = F_90 ( F_87 , sizeof( * V_91 ) , V_37 ) ;
if ( ! V_91 )
return F_44 ( - V_38 ) ;
V_14 = F_74 ( V_48 , V_7 , V_76 , false ) ;
if ( F_91 ( V_14 ) ) {
F_92 ( V_91 ) ;
} else {
* V_91 = V_14 ;
F_93 ( V_48 , V_91 ) ;
}
return V_14 ;
}
void F_88 ( struct V_1 * V_14 )
{
F_60 ( F_95 ( & V_14 -> V_45 ) ) ;
F_96 ( & V_14 -> V_20 ) ;
F_97 ( & V_14 -> V_12 . V_27 , L_7 ) ;
F_98 ( V_14 ) ;
F_72 ( V_14 ) ;
F_64 ( V_14 ) ;
F_81 ( & V_14 -> V_12 , false ) ;
F_99 ( & V_14 -> V_12 ) ;
}
void * F_100 ( struct V_1 * V_14 )
{
return V_14 -> V_82 ;
}
static int T_2 F_101 ( void )
{
V_24 = F_102 ( V_92 , L_11 ) ;
if ( F_91 ( V_24 ) )
return F_103 ( V_24 ) ;
V_24 -> V_93 = V_94 ;
F_104 ( & V_80 ) ;
return 0 ;
}
static void T_3 F_105 ( void )
{
F_106 ( V_24 ) ;
}
