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
static void F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_14 = F_5 ( V_18 , struct V_1 ,
V_29 . V_18 ) ;
if ( V_14 -> V_12 . V_30 )
F_19 ( & V_14 -> V_12 . V_30 -> V_31 ) ;
F_15 ( V_14 ) ;
if ( V_14 -> V_12 . V_30 )
F_20 ( & V_14 -> V_12 . V_30 -> V_31 ) ;
}
static int F_21 ( struct V_11 * V_12 ,
void * V_13 )
{
struct V_1 * V_14 = V_13 ;
struct V_1 * V_32 = F_3 ( V_12 ) ;
struct V_33 * V_34 ;
int V_4 = 0 ;
do {
V_34 = F_22 ( V_14 -> V_35 , L_2 , V_4 ++ ) ;
if ( ! V_34 )
break;
if ( V_34 == V_32 -> V_35 ) {
F_23 ( & V_14 -> V_12 , L_3 ,
V_14 -> V_7 -> V_8 , V_32 -> V_7 -> V_8 ) ;
V_14 -> V_5 [ V_4 - 1 ] = ( char * ) V_32 -> V_7 -> V_8 ;
V_14 -> V_9 ++ ;
F_24 ( V_34 ) ;
break;
}
F_24 ( V_34 ) ;
} while ( V_34 );
return 0 ;
}
static int F_25 ( struct V_1 * V_14 )
{
int error ;
error = F_10 ( V_24 , NULL , V_14 ,
F_21 ) ;
F_6 ( & V_14 -> V_12 , L_4 , V_21 , error ) ;
return error ;
}
static int F_26 ( struct V_11 * V_12 ,
void * V_13 )
{
struct V_33 * V_34 = V_13 ;
struct V_1 * V_32 = F_3 ( V_12 ) ;
if ( V_32 -> V_35 == V_34 )
return 1 ;
return 0 ;
}
static int F_27 ( struct V_33 * V_36 )
{
int error ;
error = F_10 ( V_24 , NULL , V_36 ,
F_26 ) ;
return error ? ( error == 1 ? 0 : error ) : - V_37 ;
}
static int F_28 ( struct V_1 * V_14 )
{
struct V_33 * V_34 ;
int V_38 = 0 ;
if ( V_14 -> V_5 && V_14 -> V_9 > 0 )
return 0 ;
if ( ! V_14 -> V_35 )
return 0 ;
do {
int V_39 ;
V_34 = F_22 ( V_14 -> V_35 , L_2 , V_38 ++ ) ;
if ( ! V_34 )
break;
V_39 = F_27 ( V_34 ) ;
F_24 ( V_34 ) ;
if ( V_39 ) {
F_6 ( & V_14 -> V_12 , L_5 ) ;
return V_39 ;
}
} while ( V_34 );
if ( V_38 == 1 )
return 0 ;
V_14 -> V_5 = F_29 ( & V_14 -> V_12 , sizeof( V_14 -> V_5 ) ,
V_40 ) ;
if ( ! V_14 -> V_5 ) {
F_30 ( & V_14 -> V_12 , L_6 ) ;
return - V_41 ;
}
* V_14 -> V_5 = F_29 ( & V_14 -> V_12 ,
sizeof( char * ) * ( V_38 - 1 ) ,
V_40 ) ;
if ( ! * V_14 -> V_5 ) {
F_30 ( & V_14 -> V_12 , L_6 ) ;
return - V_41 ;
}
return F_25 ( V_14 ) ;
}
static inline int F_28 ( struct V_1 * V_14 )
{
return 0 ;
}
static int F_31 ( struct V_11 * V_12 , void * V_42 )
{
union V_43 V_39 = { 0 ,} ;
struct V_1 * V_32 = F_3 ( V_12 ) ;
struct V_44 * V_13 = V_42 ;
V_13 -> V_45 ++ ;
if ( F_1 ( V_32 , V_13 -> V_14 ) )
if ( ! V_32 -> V_7 -> V_46 ( V_32 , V_47 ,
& V_39 ) )
return V_39 . V_48 ;
return 0 ;
}
int F_32 ( struct V_1 * V_14 )
{
struct V_44 V_13 = { V_14 , 0 } ;
int error ;
error = F_10 ( V_24 , NULL , & V_13 ,
F_31 ) ;
F_6 ( & V_14 -> V_12 , L_7 , V_21 , V_13 . V_45 , error ) ;
if ( V_13 . V_45 == 0 )
return - V_49 ;
return error ;
}
static int F_33 ( struct V_11 * V_12 , void * V_13 )
{
union V_43 V_39 = { 0 ,} ;
struct V_1 * V_14 = F_3 ( V_12 ) ;
unsigned int * V_45 = V_13 ;
( * V_45 ) ++ ;
if ( V_14 -> V_7 -> type != V_50 )
if ( ! V_14 -> V_7 -> V_46 ( V_14 , V_47 ,
& V_39 ) )
return V_39 . V_48 ;
return 0 ;
}
int F_34 ( void )
{
int error ;
unsigned int V_45 = 0 ;
error = F_10 ( V_24 , NULL , & V_45 ,
F_33 ) ;
if ( V_45 == 0 )
return 1 ;
return error ;
}
int F_35 ( struct V_1 * V_14 )
{
if ( F_36 ( & V_14 -> V_51 ) >= 0 &&
V_14 -> V_7 -> type == V_50 &&
V_14 -> V_7 -> V_52 ) {
V_14 -> V_7 -> V_52 ( V_14 ) ;
return 0 ;
}
return - V_53 ;
}
static int F_37 ( struct V_11 * V_12 , const void * V_13 )
{
const char * V_8 = V_13 ;
struct V_1 * V_14 = F_3 ( V_12 ) ;
return strcmp ( V_14 -> V_7 -> V_8 , V_8 ) == 0 ;
}
struct V_1 * F_38 ( const char * V_8 )
{
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 = F_39 ( V_24 , NULL , V_8 ,
F_37 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_40 ( & V_14 -> V_51 ) ;
}
return V_14 ;
}
void F_41 ( struct V_1 * V_14 )
{
F_42 () ;
F_43 ( & V_14 -> V_51 ) ;
F_44 ( & V_14 -> V_12 ) ;
}
static int F_45 ( struct V_11 * V_12 , const void * V_13 )
{
return V_12 -> V_30 && V_12 -> V_30 -> V_35 == V_13 ;
}
struct V_1 * F_46 ( struct V_33 * V_34 ,
const char * V_54 )
{
struct V_33 * V_55 ;
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 ;
V_55 = F_22 ( V_34 , V_54 , 0 ) ;
if ( ! V_55 )
return F_47 ( - V_49 ) ;
V_12 = F_39 ( V_24 , NULL , V_55 ,
F_45 ) ;
F_24 ( V_55 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_40 ( & V_14 -> V_51 ) ;
}
return V_14 ;
}
static void F_48 ( struct V_11 * V_12 , void * V_56 )
{
struct V_1 * * V_14 = V_56 ;
F_41 ( * V_14 ) ;
}
struct V_1 * F_49 ( struct V_11 * V_12 ,
const char * V_54 )
{
struct V_1 * * V_57 , * V_14 ;
if ( ! V_12 -> V_35 )
return F_47 ( - V_49 ) ;
V_57 = F_50 ( F_48 , sizeof( * V_57 ) , V_40 ) ;
if ( ! V_57 )
return F_47 ( - V_41 ) ;
V_14 = F_46 ( V_12 -> V_35 , V_54 ) ;
if ( F_51 ( V_14 ) ) {
F_52 ( V_57 ) ;
} else {
* V_57 = V_14 ;
F_53 ( V_12 , V_57 ) ;
}
return V_14 ;
}
int F_54 ( struct V_1 * V_14 ,
enum V_58 V_59 ,
union V_43 * V_60 )
{
if ( F_36 ( & V_14 -> V_51 ) <= 0 ) {
if ( ! V_14 -> V_61 )
return - V_62 ;
return - V_49 ;
}
return V_14 -> V_7 -> V_46 ( V_14 , V_59 , V_60 ) ;
}
int F_55 ( struct V_1 * V_14 ,
enum V_58 V_59 ,
const union V_43 * V_60 )
{
if ( F_36 ( & V_14 -> V_51 ) <= 0 || ! V_14 -> V_7 -> V_63 )
return - V_49 ;
return V_14 -> V_7 -> V_63 ( V_14 , V_59 , V_60 ) ;
}
int F_56 ( struct V_1 * V_14 ,
enum V_58 V_59 )
{
if ( F_36 ( & V_14 -> V_51 ) <= 0 ||
! V_14 -> V_7 -> V_64 )
return - V_49 ;
return V_14 -> V_7 -> V_64 ( V_14 , V_59 ) ;
}
void F_57 ( struct V_1 * V_14 )
{
if ( F_36 ( & V_14 -> V_51 ) <= 0 ||
! V_14 -> V_7 -> V_16 )
return;
V_14 -> V_7 -> V_16 ( V_14 ) ;
}
int F_58 ( struct V_1 * V_14 , struct V_11 * V_12 )
{
return F_59 ( & V_14 -> V_12 . V_27 , & V_12 -> V_27 , L_8 ) ;
}
static void F_60 ( struct V_11 * V_12 )
{
struct V_1 * V_14 = F_5 ( V_12 , struct V_1 , V_12 ) ;
F_61 ( L_9 , F_62 ( V_12 ) , V_21 ) ;
F_63 ( V_14 ) ;
}
int F_64 ( struct V_65 * V_66 )
{
return F_65 ( & V_25 , V_66 ) ;
}
void F_66 ( struct V_65 * V_66 )
{
F_67 ( & V_25 , V_66 ) ;
}
static int F_68 ( struct V_67 * V_68 ,
int * V_69 )
{
struct V_1 * V_14 ;
union V_43 V_60 ;
int V_39 ;
F_69 ( V_68 == NULL ) ;
V_14 = V_68 -> V_70 ;
V_39 = F_54 ( V_14 , V_71 , & V_60 ) ;
if ( V_39 )
return V_39 ;
* V_69 = V_60 . V_48 * 100 ;
return V_39 ;
}
static int F_70 ( struct V_1 * V_14 )
{
int V_4 ;
if ( V_14 -> V_7 -> V_72 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_73 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_74 [ V_4 ] == V_71 ) {
V_14 -> V_68 = F_71 ( V_14 -> V_7 -> V_8 ,
0 , 0 , V_14 , & V_75 , NULL , 0 , 0 ) ;
return F_72 ( V_14 -> V_68 ) ;
}
}
return 0 ;
}
static void F_73 ( struct V_1 * V_14 )
{
if ( F_51 ( V_14 -> V_68 ) )
return;
F_74 ( V_14 -> V_68 ) ;
}
static int F_75 ( struct V_76 * V_77 ,
unsigned long * V_78 )
{
struct V_1 * V_14 ;
union V_43 V_60 ;
int V_39 ;
V_14 = V_77 -> V_70 ;
V_39 = F_54 ( V_14 ,
V_79 , & V_60 ) ;
if ( V_39 )
return V_39 ;
* V_78 = V_60 . V_48 ;
return V_39 ;
}
static int F_76 ( struct V_76 * V_77 ,
unsigned long * V_78 )
{
struct V_1 * V_14 ;
union V_43 V_60 ;
int V_39 ;
V_14 = V_77 -> V_70 ;
V_39 = F_54 ( V_14 ,
V_80 , & V_60 ) ;
if ( V_39 )
return V_39 ;
* V_78 = V_60 . V_48 ;
return V_39 ;
}
static int F_77 ( struct V_76 * V_77 ,
unsigned long V_78 )
{
struct V_1 * V_14 ;
union V_43 V_60 ;
int V_39 ;
V_14 = V_77 -> V_70 ;
V_60 . V_48 = V_78 ;
V_39 = V_14 -> V_7 -> V_63 ( V_14 ,
V_80 , & V_60 ) ;
return V_39 ;
}
static int F_78 ( struct V_1 * V_14 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_73 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_74 [ V_4 ] ==
V_80 ) {
V_14 -> V_77 = F_79 (
( char * ) V_14 -> V_7 -> V_8 ,
V_14 , & V_81 ) ;
return F_72 ( V_14 -> V_77 ) ;
}
}
return 0 ;
}
static void F_80 ( struct V_1 * V_14 )
{
if ( F_51 ( V_14 -> V_77 ) )
return;
F_81 ( V_14 -> V_77 ) ;
}
static int F_70 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_73 ( struct V_1 * V_14 )
{
}
static int F_78 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_80 ( struct V_1 * V_14 )
{
}
static struct V_1 * T_1
F_82 ( struct V_11 * V_30 ,
const struct V_82 * V_7 ,
const struct V_83 * V_84 ,
bool V_85 )
{
struct V_11 * V_12 ;
struct V_1 * V_14 ;
int V_86 ;
if ( ! V_30 )
F_83 ( L_10 ,
V_21 , V_7 -> V_8 ) ;
V_14 = F_84 ( sizeof( * V_14 ) , V_40 ) ;
if ( ! V_14 )
return F_47 ( - V_41 ) ;
V_12 = & V_14 -> V_12 ;
F_85 ( V_12 ) ;
V_12 -> V_87 = V_24 ;
V_12 -> type = & V_88 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_89 = F_60 ;
F_86 ( V_12 , V_14 ) ;
V_14 -> V_7 = V_7 ;
if ( V_84 ) {
V_14 -> V_90 = V_84 -> V_90 ;
V_14 -> V_35 = V_84 -> V_35 ;
V_14 -> V_6 = V_84 -> V_6 ;
V_14 -> V_10 = V_84 -> V_10 ;
}
V_86 = F_87 ( V_12 , L_11 , V_7 -> V_8 ) ;
if ( V_86 )
goto V_91;
F_88 ( & V_14 -> V_20 , F_4 ) ;
F_89 ( & V_14 -> V_29 ,
F_18 ) ;
V_86 = F_28 ( V_14 ) ;
if ( V_86 ) {
F_23 ( V_12 , L_12 ) ;
goto V_92;
}
F_90 ( & V_14 -> V_22 ) ;
V_86 = F_91 ( V_12 , V_85 ) ;
if ( V_86 )
goto V_93;
V_86 = F_92 ( V_12 ) ;
if ( V_86 )
goto V_94;
V_86 = F_70 ( V_14 ) ;
if ( V_86 )
goto V_95;
V_86 = F_78 ( V_14 ) ;
if ( V_86 )
goto V_96;
V_86 = F_93 ( V_14 ) ;
if ( V_86 )
goto V_97;
F_40 ( & V_14 -> V_51 ) ;
V_14 -> V_61 = true ;
F_94 ( V_98 ,
& V_14 -> V_29 ,
V_99 ) ;
return V_14 ;
V_97:
F_80 ( V_14 ) ;
V_96:
F_73 ( V_14 ) ;
V_95:
F_95 ( V_12 ) ;
V_94:
V_93:
V_92:
V_91:
F_44 ( V_12 ) ;
return F_47 ( V_86 ) ;
}
struct V_1 * T_1 F_96 ( struct V_11 * V_30 ,
const struct V_82 * V_7 ,
const struct V_83 * V_84 )
{
return F_82 ( V_30 , V_7 , V_84 , true ) ;
}
struct V_1 * T_1
F_97 ( struct V_11 * V_30 ,
const struct V_82 * V_7 ,
const struct V_83 * V_84 )
{
return F_82 ( V_30 , V_7 , V_84 , false ) ;
}
static void F_98 ( struct V_11 * V_12 , void * V_56 )
{
struct V_1 * * V_14 = V_56 ;
F_99 ( * V_14 ) ;
}
struct V_1 * T_1
F_100 ( struct V_11 * V_30 ,
const struct V_82 * V_7 ,
const struct V_83 * V_84 )
{
struct V_1 * * V_57 , * V_14 ;
V_57 = F_50 ( F_98 , sizeof( * V_57 ) , V_40 ) ;
if ( ! V_57 )
return F_47 ( - V_41 ) ;
V_14 = F_82 ( V_30 , V_7 , V_84 , true ) ;
if ( F_101 ( V_14 ) ) {
F_52 ( V_57 ) ;
} else {
* V_57 = V_14 ;
F_53 ( V_30 , V_57 ) ;
}
return V_14 ;
}
struct V_1 * T_1
F_102 ( struct V_11 * V_30 ,
const struct V_82 * V_7 ,
const struct V_83 * V_84 )
{
struct V_1 * * V_57 , * V_14 ;
V_57 = F_50 ( F_98 , sizeof( * V_57 ) , V_40 ) ;
if ( ! V_57 )
return F_47 ( - V_41 ) ;
V_14 = F_82 ( V_30 , V_7 , V_84 , false ) ;
if ( F_101 ( V_14 ) ) {
F_52 ( V_57 ) ;
} else {
* V_57 = V_14 ;
F_53 ( V_30 , V_57 ) ;
}
return V_14 ;
}
void F_99 ( struct V_1 * V_14 )
{
F_69 ( F_103 ( & V_14 -> V_51 ) ) ;
F_104 ( & V_14 -> V_20 ) ;
F_105 ( & V_14 -> V_29 ) ;
F_106 ( & V_14 -> V_12 . V_27 , L_8 ) ;
F_107 ( V_14 ) ;
F_80 ( V_14 ) ;
F_73 ( V_14 ) ;
F_91 ( & V_14 -> V_12 , false ) ;
F_108 ( & V_14 -> V_12 ) ;
}
void * F_109 ( struct V_1 * V_14 )
{
return V_14 -> V_90 ;
}
static int T_2 F_110 ( void )
{
V_24 = F_111 ( V_100 , L_13 ) ;
if ( F_101 ( V_24 ) )
return F_112 ( V_24 ) ;
V_24 -> V_101 = V_102 ;
F_113 ( & V_88 ) ;
return 0 ;
}
static void T_3 F_114 ( void )
{
F_115 ( V_24 ) ;
}
