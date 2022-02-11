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
if ( ! V_14 -> V_5 )
return - V_41 ;
* V_14 -> V_5 = F_29 ( & V_14 -> V_12 ,
sizeof( char * ) * ( V_38 - 1 ) ,
V_40 ) ;
if ( ! * V_14 -> V_5 )
return - V_41 ;
return F_25 ( V_14 ) ;
}
static int F_28 ( struct V_1 * V_14 )
{
int V_42 , V_39 ;
if ( ! V_14 -> V_12 . V_30 )
return 0 ;
V_42 = F_30 ( V_14 -> V_12 . V_30 ,
L_6 , NULL , 0 ) ;
if ( V_42 <= 0 )
return 0 ;
V_14 -> V_5 = F_31 ( & V_14 -> V_12 , V_42 ,
sizeof( char * ) , V_40 ) ;
if ( ! V_14 -> V_5 )
return - V_41 ;
V_39 = F_30 ( V_14 -> V_12 . V_30 ,
L_6 , ( const char * * ) V_14 -> V_5 , V_42 ) ;
if ( V_39 < 0 )
return V_39 ;
V_14 -> V_9 = V_42 ;
return 0 ;
}
static int F_32 ( struct V_11 * V_12 , void * V_43 )
{
union V_44 V_39 = { 0 ,} ;
struct V_1 * V_32 = F_3 ( V_12 ) ;
struct V_45 * V_13 = V_43 ;
if ( F_1 ( V_32 , V_13 -> V_14 ) ) {
V_13 -> V_46 ++ ;
if ( ! V_32 -> V_7 -> V_47 ( V_32 , V_48 ,
& V_39 ) )
return V_39 . V_49 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_14 )
{
struct V_45 V_13 = { V_14 , 0 } ;
int error ;
error = F_10 ( V_24 , NULL , & V_13 ,
F_32 ) ;
F_6 ( & V_14 -> V_12 , L_7 , V_21 , V_13 . V_46 , error ) ;
if ( V_13 . V_46 == 0 )
return - V_50 ;
return error ;
}
static int F_34 ( struct V_11 * V_12 , void * V_13 )
{
union V_44 V_39 = { 0 ,} ;
struct V_1 * V_14 = F_3 ( V_12 ) ;
unsigned int * V_46 = V_13 ;
( * V_46 ) ++ ;
if ( V_14 -> V_7 -> type != V_51 )
if ( ! V_14 -> V_7 -> V_47 ( V_14 , V_48 ,
& V_39 ) )
return V_39 . V_49 ;
return 0 ;
}
int F_35 ( void )
{
int error ;
unsigned int V_46 = 0 ;
error = F_10 ( V_24 , NULL , & V_46 ,
F_34 ) ;
if ( V_46 == 0 )
return 1 ;
return error ;
}
static int F_36 ( struct V_11 * V_12 ,
void * V_13 )
{
union V_44 V_39 = { 0 ,} ;
struct V_1 * V_32 = F_3 ( V_12 ) ;
struct V_1 * V_14 = V_13 ;
if ( F_1 ( V_32 , V_14 ) )
if ( ! V_32 -> V_7 -> V_47 ( V_32 ,
V_52 ,
& V_39 ) )
return V_39 . V_49 ;
return 0 ;
}
int F_37 ( struct V_1 * V_14 )
{
union V_44 V_53 = { 0 ,} ;
int V_54 ;
if ( ! V_14 -> V_7 -> V_55 )
return - V_56 ;
V_54 = F_10 ( V_24 , NULL , V_14 ,
F_36 ) ;
if ( V_54 <= 0 )
return ( V_54 == 0 ) ? - V_50 : V_54 ;
V_53 . V_49 = V_54 ;
return V_14 -> V_7 -> V_55 ( V_14 ,
V_57 , & V_53 ) ;
}
int F_38 ( struct V_1 * V_14 )
{
if ( F_39 ( & V_14 -> V_58 ) >= 0 &&
V_14 -> V_7 -> type == V_51 &&
V_14 -> V_7 -> V_59 ) {
V_14 -> V_7 -> V_59 ( V_14 ) ;
return 0 ;
}
return - V_56 ;
}
static int F_40 ( struct V_11 * V_12 , const void * V_13 )
{
const char * V_8 = V_13 ;
struct V_1 * V_14 = F_3 ( V_12 ) ;
return strcmp ( V_14 -> V_7 -> V_8 , V_8 ) == 0 ;
}
struct V_1 * F_41 ( const char * V_8 )
{
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 = F_42 ( V_24 , NULL , V_8 ,
F_40 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_43 ( & V_14 -> V_58 ) ;
}
return V_14 ;
}
void F_44 ( struct V_1 * V_14 )
{
F_45 () ;
F_46 ( & V_14 -> V_58 ) ;
F_47 ( & V_14 -> V_12 ) ;
}
static int F_48 ( struct V_11 * V_12 , const void * V_13 )
{
return V_12 -> V_30 && V_12 -> V_30 -> V_35 == V_13 ;
}
struct V_1 * F_49 ( struct V_33 * V_34 ,
const char * V_60 )
{
struct V_33 * V_61 ;
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 ;
V_61 = F_22 ( V_34 , V_60 , 0 ) ;
if ( ! V_61 )
return F_50 ( - V_50 ) ;
V_12 = F_42 ( V_24 , NULL , V_61 ,
F_48 ) ;
F_24 ( V_61 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_43 ( & V_14 -> V_58 ) ;
}
return V_14 ;
}
static void F_51 ( struct V_11 * V_12 , void * V_62 )
{
struct V_1 * * V_14 = V_62 ;
F_44 ( * V_14 ) ;
}
struct V_1 * F_52 ( struct V_11 * V_12 ,
const char * V_60 )
{
struct V_1 * * V_63 , * V_14 ;
if ( ! V_12 -> V_35 )
return F_50 ( - V_50 ) ;
V_63 = F_53 ( F_51 , sizeof( * V_63 ) , V_40 ) ;
if ( ! V_63 )
return F_50 ( - V_41 ) ;
V_14 = F_49 ( V_12 -> V_35 , V_60 ) ;
if ( F_54 ( V_14 ) ) {
F_55 ( V_63 ) ;
} else {
* V_63 = V_14 ;
F_56 ( V_12 , V_63 ) ;
}
return V_14 ;
}
int F_57 ( struct V_1 * V_14 ,
struct V_64 * V_65 )
{
struct V_33 * V_66 ;
const char * V_67 ;
int V_68 ;
V_65 -> V_69 = - V_56 ;
V_65 -> V_70 = - V_56 ;
V_65 -> V_71 = - V_56 ;
V_65 -> V_72 = - V_56 ;
V_65 -> V_73 = - V_56 ;
V_65 -> V_74 = - V_56 ;
V_65 -> V_75 = - V_56 ;
if ( ! V_14 -> V_35 ) {
F_58 ( & V_14 -> V_12 , L_8 ,
V_21 ) ;
return - V_76 ;
}
V_66 = F_22 ( V_14 -> V_35 , L_9 , 0 ) ;
if ( ! V_66 )
return - V_50 ;
V_68 = F_59 ( V_66 , L_10 , & V_67 ) ;
if ( V_68 )
return V_68 ;
if ( strcmp ( L_11 , V_67 ) )
return - V_50 ;
F_60 ( V_66 , L_12 ,
& V_65 -> V_69 ) ;
F_60 ( V_66 , L_13 ,
& V_65 -> V_70 ) ;
F_60 ( V_66 , L_14 ,
& V_65 -> V_71 ) ;
F_60 ( V_66 , L_15 ,
& V_65 -> V_72 ) ;
F_60 ( V_66 , L_16 ,
& V_65 -> V_73 ) ;
F_60 ( V_66 , L_17 ,
& V_65 -> V_74 ) ;
F_60 ( V_66 , L_18 ,
& V_65 -> V_75 ) ;
return 0 ;
}
int F_61 ( struct V_1 * V_14 ,
enum V_77 V_78 ,
union V_44 * V_53 )
{
if ( F_39 ( & V_14 -> V_58 ) <= 0 ) {
if ( ! V_14 -> V_79 )
return - V_80 ;
return - V_50 ;
}
return V_14 -> V_7 -> V_47 ( V_14 , V_78 , V_53 ) ;
}
int F_62 ( struct V_1 * V_14 ,
enum V_77 V_78 ,
const union V_44 * V_53 )
{
if ( F_39 ( & V_14 -> V_58 ) <= 0 || ! V_14 -> V_7 -> V_55 )
return - V_50 ;
return V_14 -> V_7 -> V_55 ( V_14 , V_78 , V_53 ) ;
}
int F_63 ( struct V_1 * V_14 ,
enum V_77 V_78 )
{
if ( F_39 ( & V_14 -> V_58 ) <= 0 ||
! V_14 -> V_7 -> V_81 )
return - V_50 ;
return V_14 -> V_7 -> V_81 ( V_14 , V_78 ) ;
}
void F_64 ( struct V_1 * V_14 )
{
if ( F_39 ( & V_14 -> V_58 ) <= 0 ||
! V_14 -> V_7 -> V_16 )
return;
V_14 -> V_7 -> V_16 ( V_14 ) ;
}
int F_65 ( struct V_1 * V_14 , struct V_11 * V_12 )
{
return F_66 ( & V_14 -> V_12 . V_27 , & V_12 -> V_27 , L_19 ) ;
}
static void F_67 ( struct V_11 * V_12 )
{
struct V_1 * V_14 = F_5 ( V_12 , struct V_1 , V_12 ) ;
F_68 ( L_20 , F_69 ( V_12 ) , V_21 ) ;
F_70 ( V_14 ) ;
}
int F_71 ( struct V_82 * V_83 )
{
return F_72 ( & V_25 , V_83 ) ;
}
void F_73 ( struct V_82 * V_83 )
{
F_74 ( & V_25 , V_83 ) ;
}
static int F_75 ( struct V_84 * V_85 ,
int * V_86 )
{
struct V_1 * V_14 ;
union V_44 V_53 ;
int V_39 ;
F_76 ( V_85 == NULL ) ;
V_14 = V_85 -> V_87 ;
V_39 = F_61 ( V_14 , V_88 , & V_53 ) ;
if ( V_39 )
return V_39 ;
* V_86 = V_53 . V_49 * 100 ;
return V_39 ;
}
static int F_77 ( struct V_1 * V_14 )
{
int V_4 ;
if ( V_14 -> V_7 -> V_89 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_90 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_91 [ V_4 ] == V_88 ) {
V_14 -> V_85 = F_78 ( V_14 -> V_7 -> V_8 ,
0 , 0 , V_14 , & V_92 , NULL , 0 , 0 ) ;
return F_79 ( V_14 -> V_85 ) ;
}
}
return 0 ;
}
static void F_80 ( struct V_1 * V_14 )
{
if ( F_54 ( V_14 -> V_85 ) )
return;
F_81 ( V_14 -> V_85 ) ;
}
static int F_82 ( struct V_93 * V_94 ,
unsigned long * V_95 )
{
struct V_1 * V_14 ;
union V_44 V_53 ;
int V_39 ;
V_14 = V_94 -> V_87 ;
V_39 = F_61 ( V_14 ,
V_96 , & V_53 ) ;
if ( V_39 )
return V_39 ;
* V_95 = V_53 . V_49 ;
return V_39 ;
}
static int F_83 ( struct V_93 * V_94 ,
unsigned long * V_95 )
{
struct V_1 * V_14 ;
union V_44 V_53 ;
int V_39 ;
V_14 = V_94 -> V_87 ;
V_39 = F_61 ( V_14 ,
V_97 , & V_53 ) ;
if ( V_39 )
return V_39 ;
* V_95 = V_53 . V_49 ;
return V_39 ;
}
static int F_84 ( struct V_93 * V_94 ,
unsigned long V_95 )
{
struct V_1 * V_14 ;
union V_44 V_53 ;
int V_39 ;
V_14 = V_94 -> V_87 ;
V_53 . V_49 = V_95 ;
V_39 = V_14 -> V_7 -> V_55 ( V_14 ,
V_97 , & V_53 ) ;
return V_39 ;
}
static int F_85 ( struct V_1 * V_14 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_90 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_91 [ V_4 ] ==
V_97 ) {
V_14 -> V_94 = F_86 (
( char * ) V_14 -> V_7 -> V_8 ,
V_14 , & V_98 ) ;
return F_79 ( V_14 -> V_94 ) ;
}
}
return 0 ;
}
static void F_87 ( struct V_1 * V_14 )
{
if ( F_54 ( V_14 -> V_94 ) )
return;
F_88 ( V_14 -> V_94 ) ;
}
static int F_77 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_80 ( struct V_1 * V_14 )
{
}
static int F_85 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_87 ( struct V_1 * V_14 )
{
}
static struct V_1 * T_1
F_89 ( struct V_11 * V_30 ,
const struct V_99 * V_7 ,
const struct V_100 * V_101 ,
bool V_102 )
{
struct V_11 * V_12 ;
struct V_1 * V_14 ;
int V_103 ;
if ( ! V_30 )
F_90 ( L_21 ,
V_21 , V_7 -> V_8 ) ;
V_14 = F_91 ( sizeof( * V_14 ) , V_40 ) ;
if ( ! V_14 )
return F_50 ( - V_41 ) ;
V_12 = & V_14 -> V_12 ;
F_92 ( V_12 ) ;
V_12 -> V_104 = V_24 ;
V_12 -> type = & V_105 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_106 = F_67 ;
F_93 ( V_12 , V_14 ) ;
V_14 -> V_7 = V_7 ;
if ( V_101 ) {
V_14 -> V_107 = V_101 -> V_107 ;
V_14 -> V_35 = V_101 -> V_35 ;
V_14 -> V_6 = V_101 -> V_6 ;
V_14 -> V_10 = V_101 -> V_10 ;
}
V_103 = F_94 ( V_12 , L_22 , V_7 -> V_8 ) ;
if ( V_103 )
goto V_108;
F_95 ( & V_14 -> V_20 , F_4 ) ;
F_96 ( & V_14 -> V_29 ,
F_18 ) ;
V_103 = F_28 ( V_14 ) ;
if ( V_103 ) {
F_23 ( V_12 , L_23 ) ;
goto V_109;
}
F_97 ( & V_14 -> V_22 ) ;
V_103 = F_98 ( V_12 , V_102 ) ;
if ( V_103 )
goto V_110;
V_103 = F_99 ( V_12 ) ;
if ( V_103 )
goto V_111;
V_103 = F_77 ( V_14 ) ;
if ( V_103 )
goto V_112;
V_103 = F_85 ( V_14 ) ;
if ( V_103 )
goto V_113;
V_103 = F_100 ( V_14 ) ;
if ( V_103 )
goto V_114;
F_43 ( & V_14 -> V_58 ) ;
V_14 -> V_79 = true ;
F_101 ( V_115 ,
& V_14 -> V_29 ,
V_116 ) ;
return V_14 ;
V_114:
F_87 ( V_14 ) ;
V_113:
F_80 ( V_14 ) ;
V_112:
F_102 ( V_12 ) ;
V_111:
V_110:
V_109:
V_108:
F_47 ( V_12 ) ;
return F_50 ( V_103 ) ;
}
struct V_1 * T_1 F_103 ( struct V_11 * V_30 ,
const struct V_99 * V_7 ,
const struct V_100 * V_101 )
{
return F_89 ( V_30 , V_7 , V_101 , true ) ;
}
struct V_1 * T_1
F_104 ( struct V_11 * V_30 ,
const struct V_99 * V_7 ,
const struct V_100 * V_101 )
{
return F_89 ( V_30 , V_7 , V_101 , false ) ;
}
static void F_105 ( struct V_11 * V_12 , void * V_62 )
{
struct V_1 * * V_14 = V_62 ;
F_106 ( * V_14 ) ;
}
struct V_1 * T_1
F_107 ( struct V_11 * V_30 ,
const struct V_99 * V_7 ,
const struct V_100 * V_101 )
{
struct V_1 * * V_63 , * V_14 ;
V_63 = F_53 ( F_105 , sizeof( * V_63 ) , V_40 ) ;
if ( ! V_63 )
return F_50 ( - V_41 ) ;
V_14 = F_89 ( V_30 , V_7 , V_101 , true ) ;
if ( F_108 ( V_14 ) ) {
F_55 ( V_63 ) ;
} else {
* V_63 = V_14 ;
F_56 ( V_30 , V_63 ) ;
}
return V_14 ;
}
struct V_1 * T_1
F_109 ( struct V_11 * V_30 ,
const struct V_99 * V_7 ,
const struct V_100 * V_101 )
{
struct V_1 * * V_63 , * V_14 ;
V_63 = F_53 ( F_105 , sizeof( * V_63 ) , V_40 ) ;
if ( ! V_63 )
return F_50 ( - V_41 ) ;
V_14 = F_89 ( V_30 , V_7 , V_101 , false ) ;
if ( F_108 ( V_14 ) ) {
F_55 ( V_63 ) ;
} else {
* V_63 = V_14 ;
F_56 ( V_30 , V_63 ) ;
}
return V_14 ;
}
void F_106 ( struct V_1 * V_14 )
{
F_76 ( F_110 ( & V_14 -> V_58 ) ) ;
F_111 ( & V_14 -> V_20 ) ;
F_112 ( & V_14 -> V_29 ) ;
F_113 ( & V_14 -> V_12 . V_27 , L_19 ) ;
F_114 ( V_14 ) ;
F_87 ( V_14 ) ;
F_80 ( V_14 ) ;
F_98 ( & V_14 -> V_12 , false ) ;
F_115 ( & V_14 -> V_12 ) ;
}
void * F_116 ( struct V_1 * V_14 )
{
return V_14 -> V_107 ;
}
static int T_2 F_117 ( void )
{
V_24 = F_118 ( V_117 , L_24 ) ;
if ( F_108 ( V_24 ) )
return F_119 ( V_24 ) ;
V_24 -> V_118 = V_119 ;
F_120 ( & V_105 ) ;
return 0 ;
}
static void T_3 F_121 ( void )
{
F_122 ( V_24 ) ;
}
