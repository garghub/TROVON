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
static int F_28 ( struct V_1 * V_14 )
{
int V_42 , V_39 ;
if ( ! V_14 -> V_12 . V_30 )
return 0 ;
V_42 = F_31 ( V_14 -> V_12 . V_30 ,
L_7 , NULL , 0 ) ;
if ( V_42 <= 0 )
return 0 ;
V_14 -> V_5 = F_32 ( & V_14 -> V_12 , V_42 ,
sizeof( char * ) , V_40 ) ;
if ( ! V_14 -> V_5 )
return - V_41 ;
V_39 = F_31 ( V_14 -> V_12 . V_30 ,
L_7 , ( const char * * ) V_14 -> V_5 , V_42 ) ;
if ( V_39 < 0 )
return V_39 ;
V_14 -> V_9 = V_42 ;
return 0 ;
}
static int F_33 ( struct V_11 * V_12 , void * V_43 )
{
union V_44 V_39 = { 0 ,} ;
struct V_1 * V_32 = F_3 ( V_12 ) ;
struct V_45 * V_13 = V_43 ;
V_13 -> V_46 ++ ;
if ( F_1 ( V_32 , V_13 -> V_14 ) )
if ( ! V_32 -> V_7 -> V_47 ( V_32 , V_48 ,
& V_39 ) )
return V_39 . V_49 ;
return 0 ;
}
int F_34 ( struct V_1 * V_14 )
{
struct V_45 V_13 = { V_14 , 0 } ;
int error ;
error = F_10 ( V_24 , NULL , & V_13 ,
F_33 ) ;
F_6 ( & V_14 -> V_12 , L_8 , V_21 , V_13 . V_46 , error ) ;
if ( V_13 . V_46 == 0 )
return - V_50 ;
return error ;
}
static int F_35 ( struct V_11 * V_12 , void * V_13 )
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
int F_36 ( void )
{
int error ;
unsigned int V_46 = 0 ;
error = F_10 ( V_24 , NULL , & V_46 ,
F_35 ) ;
if ( V_46 == 0 )
return 1 ;
return error ;
}
int F_37 ( struct V_1 * V_14 )
{
if ( F_38 ( & V_14 -> V_52 ) >= 0 &&
V_14 -> V_7 -> type == V_51 &&
V_14 -> V_7 -> V_53 ) {
V_14 -> V_7 -> V_53 ( V_14 ) ;
return 0 ;
}
return - V_54 ;
}
static int F_39 ( struct V_11 * V_12 , const void * V_13 )
{
const char * V_8 = V_13 ;
struct V_1 * V_14 = F_3 ( V_12 ) ;
return strcmp ( V_14 -> V_7 -> V_8 , V_8 ) == 0 ;
}
struct V_1 * F_40 ( const char * V_8 )
{
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 = F_41 ( V_24 , NULL , V_8 ,
F_39 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_42 ( & V_14 -> V_52 ) ;
}
return V_14 ;
}
void F_43 ( struct V_1 * V_14 )
{
F_44 () ;
F_45 ( & V_14 -> V_52 ) ;
F_46 ( & V_14 -> V_12 ) ;
}
static int F_47 ( struct V_11 * V_12 , const void * V_13 )
{
return V_12 -> V_30 && V_12 -> V_30 -> V_35 == V_13 ;
}
struct V_1 * F_48 ( struct V_33 * V_34 ,
const char * V_55 )
{
struct V_33 * V_56 ;
struct V_1 * V_14 = NULL ;
struct V_11 * V_12 ;
V_56 = F_22 ( V_34 , V_55 , 0 ) ;
if ( ! V_56 )
return F_49 ( - V_50 ) ;
V_12 = F_41 ( V_24 , NULL , V_56 ,
F_47 ) ;
F_24 ( V_56 ) ;
if ( V_12 ) {
V_14 = F_3 ( V_12 ) ;
F_42 ( & V_14 -> V_52 ) ;
}
return V_14 ;
}
static void F_50 ( struct V_11 * V_12 , void * V_57 )
{
struct V_1 * * V_14 = V_57 ;
F_43 ( * V_14 ) ;
}
struct V_1 * F_51 ( struct V_11 * V_12 ,
const char * V_55 )
{
struct V_1 * * V_58 , * V_14 ;
if ( ! V_12 -> V_35 )
return F_49 ( - V_50 ) ;
V_58 = F_52 ( F_50 , sizeof( * V_58 ) , V_40 ) ;
if ( ! V_58 )
return F_49 ( - V_41 ) ;
V_14 = F_48 ( V_12 -> V_35 , V_55 ) ;
if ( F_53 ( V_14 ) ) {
F_54 ( V_58 ) ;
} else {
* V_58 = V_14 ;
F_55 ( V_12 , V_58 ) ;
}
return V_14 ;
}
int F_56 ( struct V_1 * V_14 ,
struct V_59 * V_60 )
{
struct V_33 * V_61 ;
const char * V_62 ;
int V_63 ;
V_60 -> V_64 = - V_54 ;
V_60 -> V_65 = - V_54 ;
V_60 -> V_66 = - V_54 ;
V_60 -> V_67 = - V_54 ;
V_60 -> V_68 = - V_54 ;
V_60 -> V_69 = - V_54 ;
V_60 -> V_70 = - V_54 ;
if ( ! V_14 -> V_35 ) {
F_57 ( & V_14 -> V_12 , L_9 ,
V_21 ) ;
return - V_71 ;
}
V_61 = F_22 ( V_14 -> V_35 , L_10 , 0 ) ;
if ( ! V_61 )
return - V_50 ;
V_63 = F_58 ( V_61 , L_11 , & V_62 ) ;
if ( V_63 )
return V_63 ;
if ( strcmp ( L_12 , V_62 ) )
return - V_50 ;
F_59 ( V_61 , L_13 ,
& V_60 -> V_64 ) ;
F_59 ( V_61 , L_14 ,
& V_60 -> V_65 ) ;
F_59 ( V_61 , L_15 ,
& V_60 -> V_66 ) ;
F_59 ( V_61 , L_16 ,
& V_60 -> V_67 ) ;
F_59 ( V_61 , L_17 ,
& V_60 -> V_68 ) ;
F_59 ( V_61 , L_18 ,
& V_60 -> V_69 ) ;
F_59 ( V_61 , L_19 ,
& V_60 -> V_70 ) ;
return 0 ;
}
int F_60 ( struct V_1 * V_14 ,
enum V_72 V_73 ,
union V_44 * V_74 )
{
if ( F_38 ( & V_14 -> V_52 ) <= 0 ) {
if ( ! V_14 -> V_75 )
return - V_76 ;
return - V_50 ;
}
return V_14 -> V_7 -> V_47 ( V_14 , V_73 , V_74 ) ;
}
int F_61 ( struct V_1 * V_14 ,
enum V_72 V_73 ,
const union V_44 * V_74 )
{
if ( F_38 ( & V_14 -> V_52 ) <= 0 || ! V_14 -> V_7 -> V_77 )
return - V_50 ;
return V_14 -> V_7 -> V_77 ( V_14 , V_73 , V_74 ) ;
}
int F_62 ( struct V_1 * V_14 ,
enum V_72 V_73 )
{
if ( F_38 ( & V_14 -> V_52 ) <= 0 ||
! V_14 -> V_7 -> V_78 )
return - V_50 ;
return V_14 -> V_7 -> V_78 ( V_14 , V_73 ) ;
}
void F_63 ( struct V_1 * V_14 )
{
if ( F_38 ( & V_14 -> V_52 ) <= 0 ||
! V_14 -> V_7 -> V_16 )
return;
V_14 -> V_7 -> V_16 ( V_14 ) ;
}
int F_64 ( struct V_1 * V_14 , struct V_11 * V_12 )
{
return F_65 ( & V_14 -> V_12 . V_27 , & V_12 -> V_27 , L_20 ) ;
}
static void F_66 ( struct V_11 * V_12 )
{
struct V_1 * V_14 = F_5 ( V_12 , struct V_1 , V_12 ) ;
F_67 ( L_21 , F_68 ( V_12 ) , V_21 ) ;
F_69 ( V_14 ) ;
}
int F_70 ( struct V_79 * V_80 )
{
return F_71 ( & V_25 , V_80 ) ;
}
void F_72 ( struct V_79 * V_80 )
{
F_73 ( & V_25 , V_80 ) ;
}
static int F_74 ( struct V_81 * V_82 ,
int * V_83 )
{
struct V_1 * V_14 ;
union V_44 V_74 ;
int V_39 ;
F_75 ( V_82 == NULL ) ;
V_14 = V_82 -> V_84 ;
V_39 = F_60 ( V_14 , V_85 , & V_74 ) ;
if ( V_39 )
return V_39 ;
* V_83 = V_74 . V_49 * 100 ;
return V_39 ;
}
static int F_76 ( struct V_1 * V_14 )
{
int V_4 ;
if ( V_14 -> V_7 -> V_86 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_87 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_88 [ V_4 ] == V_85 ) {
V_14 -> V_82 = F_77 ( V_14 -> V_7 -> V_8 ,
0 , 0 , V_14 , & V_89 , NULL , 0 , 0 ) ;
return F_78 ( V_14 -> V_82 ) ;
}
}
return 0 ;
}
static void F_79 ( struct V_1 * V_14 )
{
if ( F_53 ( V_14 -> V_82 ) )
return;
F_80 ( V_14 -> V_82 ) ;
}
static int F_81 ( struct V_90 * V_91 ,
unsigned long * V_92 )
{
struct V_1 * V_14 ;
union V_44 V_74 ;
int V_39 ;
V_14 = V_91 -> V_84 ;
V_39 = F_60 ( V_14 ,
V_93 , & V_74 ) ;
if ( V_39 )
return V_39 ;
* V_92 = V_74 . V_49 ;
return V_39 ;
}
static int F_82 ( struct V_90 * V_91 ,
unsigned long * V_92 )
{
struct V_1 * V_14 ;
union V_44 V_74 ;
int V_39 ;
V_14 = V_91 -> V_84 ;
V_39 = F_60 ( V_14 ,
V_94 , & V_74 ) ;
if ( V_39 )
return V_39 ;
* V_92 = V_74 . V_49 ;
return V_39 ;
}
static int F_83 ( struct V_90 * V_91 ,
unsigned long V_92 )
{
struct V_1 * V_14 ;
union V_44 V_74 ;
int V_39 ;
V_14 = V_91 -> V_84 ;
V_74 . V_49 = V_92 ;
V_39 = V_14 -> V_7 -> V_77 ( V_14 ,
V_94 , & V_74 ) ;
return V_39 ;
}
static int F_84 ( struct V_1 * V_14 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_14 -> V_7 -> V_87 ; V_4 ++ ) {
if ( V_14 -> V_7 -> V_88 [ V_4 ] ==
V_94 ) {
V_14 -> V_91 = F_85 (
( char * ) V_14 -> V_7 -> V_8 ,
V_14 , & V_95 ) ;
return F_78 ( V_14 -> V_91 ) ;
}
}
return 0 ;
}
static void F_86 ( struct V_1 * V_14 )
{
if ( F_53 ( V_14 -> V_91 ) )
return;
F_87 ( V_14 -> V_91 ) ;
}
static int F_76 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_79 ( struct V_1 * V_14 )
{
}
static int F_84 ( struct V_1 * V_14 )
{
return 0 ;
}
static void F_86 ( struct V_1 * V_14 )
{
}
static struct V_1 * T_1
F_88 ( struct V_11 * V_30 ,
const struct V_96 * V_7 ,
const struct V_97 * V_98 ,
bool V_99 )
{
struct V_11 * V_12 ;
struct V_1 * V_14 ;
int V_100 ;
if ( ! V_30 )
F_89 ( L_22 ,
V_21 , V_7 -> V_8 ) ;
V_14 = F_90 ( sizeof( * V_14 ) , V_40 ) ;
if ( ! V_14 )
return F_49 ( - V_41 ) ;
V_12 = & V_14 -> V_12 ;
F_91 ( V_12 ) ;
V_12 -> V_101 = V_24 ;
V_12 -> type = & V_102 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_103 = F_66 ;
F_92 ( V_12 , V_14 ) ;
V_14 -> V_7 = V_7 ;
if ( V_98 ) {
V_14 -> V_104 = V_98 -> V_104 ;
V_14 -> V_35 = V_98 -> V_35 ;
V_14 -> V_6 = V_98 -> V_6 ;
V_14 -> V_10 = V_98 -> V_10 ;
}
V_100 = F_93 ( V_12 , L_23 , V_7 -> V_8 ) ;
if ( V_100 )
goto V_105;
F_94 ( & V_14 -> V_20 , F_4 ) ;
F_95 ( & V_14 -> V_29 ,
F_18 ) ;
V_100 = F_28 ( V_14 ) ;
if ( V_100 ) {
F_23 ( V_12 , L_24 ) ;
goto V_106;
}
F_96 ( & V_14 -> V_22 ) ;
V_100 = F_97 ( V_12 , V_99 ) ;
if ( V_100 )
goto V_107;
V_100 = F_98 ( V_12 ) ;
if ( V_100 )
goto V_108;
V_100 = F_76 ( V_14 ) ;
if ( V_100 )
goto V_109;
V_100 = F_84 ( V_14 ) ;
if ( V_100 )
goto V_110;
V_100 = F_99 ( V_14 ) ;
if ( V_100 )
goto V_111;
F_42 ( & V_14 -> V_52 ) ;
V_14 -> V_75 = true ;
F_100 ( V_112 ,
& V_14 -> V_29 ,
V_113 ) ;
return V_14 ;
V_111:
F_86 ( V_14 ) ;
V_110:
F_79 ( V_14 ) ;
V_109:
F_101 ( V_12 ) ;
V_108:
V_107:
V_106:
V_105:
F_46 ( V_12 ) ;
return F_49 ( V_100 ) ;
}
struct V_1 * T_1 F_102 ( struct V_11 * V_30 ,
const struct V_96 * V_7 ,
const struct V_97 * V_98 )
{
return F_88 ( V_30 , V_7 , V_98 , true ) ;
}
struct V_1 * T_1
F_103 ( struct V_11 * V_30 ,
const struct V_96 * V_7 ,
const struct V_97 * V_98 )
{
return F_88 ( V_30 , V_7 , V_98 , false ) ;
}
static void F_104 ( struct V_11 * V_12 , void * V_57 )
{
struct V_1 * * V_14 = V_57 ;
F_105 ( * V_14 ) ;
}
struct V_1 * T_1
F_106 ( struct V_11 * V_30 ,
const struct V_96 * V_7 ,
const struct V_97 * V_98 )
{
struct V_1 * * V_58 , * V_14 ;
V_58 = F_52 ( F_104 , sizeof( * V_58 ) , V_40 ) ;
if ( ! V_58 )
return F_49 ( - V_41 ) ;
V_14 = F_88 ( V_30 , V_7 , V_98 , true ) ;
if ( F_107 ( V_14 ) ) {
F_54 ( V_58 ) ;
} else {
* V_58 = V_14 ;
F_55 ( V_30 , V_58 ) ;
}
return V_14 ;
}
struct V_1 * T_1
F_108 ( struct V_11 * V_30 ,
const struct V_96 * V_7 ,
const struct V_97 * V_98 )
{
struct V_1 * * V_58 , * V_14 ;
V_58 = F_52 ( F_104 , sizeof( * V_58 ) , V_40 ) ;
if ( ! V_58 )
return F_49 ( - V_41 ) ;
V_14 = F_88 ( V_30 , V_7 , V_98 , false ) ;
if ( F_107 ( V_14 ) ) {
F_54 ( V_58 ) ;
} else {
* V_58 = V_14 ;
F_55 ( V_30 , V_58 ) ;
}
return V_14 ;
}
void F_105 ( struct V_1 * V_14 )
{
F_75 ( F_109 ( & V_14 -> V_52 ) ) ;
F_110 ( & V_14 -> V_20 ) ;
F_111 ( & V_14 -> V_29 ) ;
F_112 ( & V_14 -> V_12 . V_27 , L_20 ) ;
F_113 ( V_14 ) ;
F_86 ( V_14 ) ;
F_79 ( V_14 ) ;
F_97 ( & V_14 -> V_12 , false ) ;
F_114 ( & V_14 -> V_12 ) ;
}
void * F_115 ( struct V_1 * V_14 )
{
return V_14 -> V_104 ;
}
static int T_2 F_116 ( void )
{
V_24 = F_117 ( V_114 , L_25 ) ;
if ( F_107 ( V_24 ) )
return F_118 ( V_24 ) ;
V_24 -> V_115 = V_116 ;
F_119 ( & V_102 ) ;
return 0 ;
}
static void T_3 F_120 ( void )
{
F_121 ( V_24 ) ;
}
