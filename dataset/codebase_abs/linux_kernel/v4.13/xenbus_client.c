const char * F_1 ( enum V_1 V_2 )
{
static const char * const V_3 [] = {
[ V_4 ] = L_1 ,
[ V_5 ] = L_2 ,
[ V_6 ] = L_3 ,
[ V_7 ] = L_4 ,
[ V_8 ] = L_5 ,
[ V_9 ] = L_6 ,
[ V_10 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
} ;
return ( V_2 < F_2 ( V_3 ) ) ? V_3 [ V_2 ] : L_10 ;
}
int F_3 ( struct V_13 * V_14 , const char * V_15 ,
struct V_16 * V_17 ,
void (* F_4)( struct V_16 * ,
const char * , const char * ) )
{
int V_18 ;
V_17 -> V_19 = V_15 ;
V_17 -> F_4 = F_4 ;
V_18 = F_5 ( V_17 ) ;
if ( V_18 ) {
V_17 -> V_19 = NULL ;
V_17 -> F_4 = NULL ;
F_6 ( V_14 , V_18 , L_11 , V_15 ) ;
}
return V_18 ;
}
int F_7 ( struct V_13 * V_14 ,
struct V_16 * V_17 ,
void (* F_4)( struct V_16 * ,
const char * , const char * ) ,
const char * V_20 , ... )
{
int V_18 ;
T_1 V_21 ;
char * V_15 ;
va_start ( V_21 , V_20 ) ;
V_15 = F_8 ( V_22 | V_23 , V_20 , V_21 ) ;
va_end ( V_21 ) ;
if ( ! V_15 ) {
F_6 ( V_14 , - V_24 , L_12 ) ;
return - V_24 ;
}
V_18 = F_3 ( V_14 , V_15 , V_17 , F_4 ) ;
if ( V_18 )
F_9 ( V_15 ) ;
return V_18 ;
}
static int
F_10 ( struct V_13 * V_14 ,
enum V_1 V_2 , int V_25 )
{
struct V_26 V_27 ;
int V_28 ;
int V_18 , abort ;
if ( V_2 == V_14 -> V_2 )
return 0 ;
V_29:
abort = 1 ;
V_18 = F_11 ( & V_27 ) ;
if ( V_18 ) {
F_12 ( V_14 , V_25 , V_18 , L_13 ) ;
return 0 ;
}
V_18 = F_13 ( V_27 , V_14 -> V_30 , L_14 , L_15 , & V_28 ) ;
if ( V_18 != 1 )
goto abort;
V_18 = F_14 ( V_27 , V_14 -> V_30 , L_14 , L_15 , V_2 ) ;
if ( V_18 ) {
F_12 ( V_14 , V_25 , V_18 , L_16 ) ;
goto abort;
}
abort = 0 ;
abort:
V_18 = F_15 ( V_27 , abort ) ;
if ( V_18 ) {
if ( V_18 == - V_31 && ! abort )
goto V_29;
F_12 ( V_14 , V_25 , V_18 , L_17 ) ;
} else
V_14 -> V_2 = V_2 ;
return 0 ;
}
int F_16 ( struct V_13 * V_14 , enum V_1 V_2 )
{
return F_10 ( V_14 , V_2 , 0 ) ;
}
int F_17 ( struct V_13 * V_14 )
{
F_16 ( V_14 , V_10 ) ;
F_18 ( & V_14 -> V_32 ) ;
return 0 ;
}
static void F_19 ( struct V_13 * V_14 , int V_18 ,
const char * V_33 , T_1 V_21 )
{
unsigned int V_34 ;
char * V_35 ;
char * V_36 ;
#define F_20 4096
V_35 = F_21 ( F_20 , V_37 ) ;
if ( ! V_35 )
return;
V_34 = sprintf ( V_35 , L_18 , - V_18 ) ;
vsnprintf ( V_35 + V_34 , F_20 - V_34 , V_33 , V_21 ) ;
F_22 ( & V_14 -> V_14 , L_19 , V_35 ) ;
V_36 = F_23 ( V_37 , L_20 , V_14 -> V_30 ) ;
if ( ! V_36 ||
F_24 ( V_38 , V_36 , L_21 , V_35 ) )
F_22 ( & V_14 -> V_14 , L_22 ,
V_14 -> V_30 , V_35 ) ;
F_9 ( V_35 ) ;
F_9 ( V_36 ) ;
}
void F_25 ( struct V_13 * V_14 , int V_18 , const char * V_33 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_33 ) ;
F_19 ( V_14 , V_18 , V_33 , V_21 ) ;
va_end ( V_21 ) ;
}
void F_6 ( struct V_13 * V_14 , int V_18 , const char * V_33 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_33 ) ;
F_19 ( V_14 , V_18 , V_33 , V_21 ) ;
va_end ( V_21 ) ;
F_16 ( V_14 , V_9 ) ;
}
static void F_12 ( struct V_13 * V_14 , int V_25 , int V_18 ,
const char * V_33 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_33 ) ;
F_19 ( V_14 , V_18 , V_33 , V_21 ) ;
va_end ( V_21 ) ;
if ( ! V_25 )
F_10 ( V_14 , V_9 , 1 ) ;
}
int F_26 ( struct V_13 * V_14 , void * V_39 ,
unsigned int V_40 , T_2 * V_41 )
{
int V_18 ;
int V_42 , V_43 ;
for ( V_42 = 0 ; V_42 < V_40 ; V_42 ++ ) {
V_18 = F_27 ( V_14 -> V_44 ,
F_28 ( V_39 ) , 0 ) ;
if ( V_18 < 0 ) {
F_6 ( V_14 , V_18 ,
L_23 ) ;
goto V_45;
}
V_41 [ V_42 ] = V_18 ;
V_39 = V_39 + V_46 ;
}
return 0 ;
V_45:
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ )
F_29 ( V_41 [ V_43 ] , 0 ) ;
return V_18 ;
}
int F_30 ( struct V_13 * V_14 , int * V_47 )
{
struct V_48 V_49 ;
int V_18 ;
V_49 . V_50 = V_51 ;
V_49 . V_52 = V_14 -> V_44 ;
V_18 = F_31 ( V_53 ,
& V_49 ) ;
if ( V_18 )
F_6 ( V_14 , V_18 , L_24 ) ;
else
* V_47 = V_49 . V_47 ;
return V_18 ;
}
int F_32 ( struct V_13 * V_14 , int V_47 )
{
struct V_54 V_55 ;
int V_18 ;
V_55 . V_47 = V_47 ;
V_18 = F_31 ( V_56 , & V_55 ) ;
if ( V_18 )
F_25 ( V_14 , V_18 , L_25 , V_47 ) ;
return V_18 ;
}
int F_33 ( struct V_13 * V_14 , T_2 * V_57 ,
unsigned int V_58 , void * * V_39 )
{
return V_59 -> V_60 ( V_14 , V_57 , V_58 , V_39 ) ;
}
static int F_34 ( struct V_13 * V_14 ,
T_2 * V_57 ,
unsigned int V_58 ,
T_3 * V_61 ,
T_4 * V_62 ,
unsigned int V_63 ,
bool * V_64 )
{
struct V_65 V_60 [ V_66 ] ;
struct V_67 V_68 [ V_66 ] ;
int V_42 , V_43 ;
int V_18 = V_69 ;
if ( V_58 > V_66 )
return - V_70 ;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ ) {
memset ( & V_60 [ V_42 ] , 0 , sizeof( V_60 [ V_42 ] ) ) ;
F_35 ( & V_60 [ V_42 ] , V_62 [ V_42 ] , V_63 , V_57 [ V_42 ] ,
V_14 -> V_44 ) ;
V_61 [ V_42 ] = V_71 ;
}
F_36 ( V_60 , V_42 ) ;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ ) {
if ( V_60 [ V_42 ] . V_72 != V_69 ) {
V_18 = V_60 [ V_42 ] . V_72 ;
F_6 ( V_14 , V_60 [ V_42 ] . V_72 ,
L_26 ,
V_57 [ V_42 ] , V_14 -> V_44 ) ;
goto V_45;
} else
V_61 [ V_42 ] = V_60 [ V_42 ] . V_73 ;
}
return V_69 ;
V_45:
for ( V_42 = V_43 = 0 ; V_42 < V_58 ; V_42 ++ ) {
if ( V_61 [ V_42 ] != V_71 ) {
memset ( & V_68 [ V_43 ] , 0 , sizeof( V_68 [ V_43 ] ) ) ;
F_37 ( & V_68 [ V_43 ] , ( T_4 ) V_62 [ V_42 ] ,
V_74 , V_61 [ V_42 ] ) ;
V_43 ++ ;
}
}
if ( F_38 ( V_75 , V_68 , V_43 ) )
F_39 () ;
* V_64 = false ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( V_68 [ V_42 ] . V_72 != V_69 ) {
* V_64 = true ;
break;
}
}
return V_18 ;
}
static int F_40 ( struct V_13 * V_14 ,
T_2 * V_57 ,
unsigned int V_58 ,
void * * V_39 )
{
struct V_76 * V_19 ;
struct V_77 * V_78 ;
T_5 * V_79 [ V_66 ] ;
T_4 V_80 [ V_66 ] ;
int V_18 = V_69 ;
int V_42 ;
bool V_64 ;
* V_39 = NULL ;
if ( V_58 > V_66 )
return - V_70 ;
V_19 = F_41 ( sizeof( * V_19 ) , V_37 ) ;
if ( ! V_19 )
return - V_24 ;
V_78 = F_42 ( V_46 * V_58 , V_79 ) ;
if ( ! V_78 ) {
F_9 ( V_19 ) ;
return - V_24 ;
}
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ )
V_80 [ V_42 ] = F_43 ( V_79 [ V_42 ] ) . V_81 ;
V_18 = F_34 ( V_14 , V_57 , V_58 , V_19 -> V_61 ,
V_80 ,
V_74 | V_82 ,
& V_64 ) ;
if ( V_18 )
goto V_83;
V_19 -> V_84 = V_58 ;
V_19 -> V_85 . V_78 = V_78 ;
F_44 ( & V_86 ) ;
F_45 ( & V_19 -> V_87 , & V_88 ) ;
F_46 ( & V_86 ) ;
* V_39 = V_78 -> V_89 ;
return 0 ;
V_83:
if ( ! V_64 )
F_47 ( V_78 ) ;
else
F_48 ( L_27 , V_78 , V_58 ) ;
F_9 ( V_19 ) ;
return V_18 ;
}
static void F_49 ( unsigned long V_90 ,
unsigned int V_91 ,
unsigned int V_34 ,
void * V_92 )
{
struct V_93 * V_94 = V_92 ;
unsigned long V_39 = ( unsigned long ) F_50 ( V_90 ) ;
V_94 -> V_80 [ V_94 -> V_95 ] = V_39 ;
V_94 -> V_62 [ V_94 -> V_95 ] = V_39 ;
V_94 -> V_95 ++ ;
}
static int F_51 ( struct V_13 * V_14 ,
T_2 * V_96 ,
unsigned int V_58 ,
void * * V_39 )
{
struct V_76 * V_19 ;
int V_18 ;
void * V_89 ;
bool V_64 = false ;
struct V_93 V_94 = {
. V_95 = 0 ,
} ;
unsigned int V_40 = F_52 ( V_58 ) ;
if ( V_58 > V_66 )
return - V_70 ;
* V_39 = NULL ;
V_19 = F_41 ( sizeof( * V_19 ) , V_37 ) ;
if ( ! V_19 )
return - V_24 ;
V_18 = F_53 ( V_40 , V_19 -> V_97 . V_98 ) ;
if ( V_18 )
goto V_99;
F_54 ( V_19 -> V_97 . V_98 , V_58 ,
F_49 ,
& V_94 ) ;
V_18 = F_34 ( V_14 , V_96 , V_58 , V_19 -> V_61 ,
V_94 . V_80 , V_74 , & V_64 ) ;
V_19 -> V_84 = V_58 ;
if ( V_18 )
goto V_100;
V_89 = F_55 ( V_19 -> V_97 . V_98 , V_40 , V_101 | V_102 ,
V_103 ) ;
if ( ! V_89 ) {
V_18 = - V_24 ;
goto V_104;
}
V_19 -> V_97 . V_89 = V_89 ;
F_44 ( & V_86 ) ;
F_45 ( & V_19 -> V_87 , & V_88 ) ;
F_46 ( & V_86 ) ;
* V_39 = V_89 ;
return 0 ;
V_104:
if ( ! V_64 )
F_56 ( V_14 , V_19 -> V_61 , V_58 , V_94 . V_62 ) ;
else
F_48 ( L_28 ,
V_89 , V_40 ) ;
V_100:
if ( ! V_64 )
F_57 ( V_40 , V_19 -> V_97 . V_98 ) ;
V_99:
F_9 ( V_19 ) ;
return V_18 ;
}
int F_58 ( struct V_13 * V_14 , T_2 * V_57 ,
unsigned int V_58 , T_3 * V_61 ,
unsigned long * V_105 , bool * V_64 )
{
T_4 V_80 [ V_66 ] ;
int V_42 ;
if ( V_58 > V_66 )
return - V_70 ;
for ( V_42 = 0 ; V_42 < V_58 ; V_42 ++ )
V_80 [ V_42 ] = ( unsigned long ) V_105 [ V_42 ] ;
return F_34 ( V_14 , V_57 , V_58 , V_61 ,
V_80 , V_74 , V_64 ) ;
}
int F_59 ( struct V_13 * V_14 , void * V_39 )
{
return V_59 -> V_68 ( V_14 , V_39 ) ;
}
static int F_60 ( struct V_13 * V_14 , void * V_39 )
{
struct V_76 * V_19 ;
struct V_67 V_68 [ V_66 ] ;
unsigned int V_106 ;
int V_42 ;
bool V_64 = false ;
int V_18 ;
F_44 ( & V_86 ) ;
F_61 (node, &xenbus_valloc_pages, next) {
if ( V_19 -> V_85 . V_78 -> V_89 == V_39 ) {
F_62 ( & V_19 -> V_87 ) ;
goto V_107;
}
}
V_19 = NULL ;
V_107:
F_46 ( & V_86 ) ;
if ( ! V_19 ) {
F_25 ( V_14 , - V_108 ,
L_29 , V_39 ) ;
return V_109 ;
}
for ( V_42 = 0 ; V_42 < V_19 -> V_84 ; V_42 ++ ) {
unsigned long V_89 ;
memset ( & V_68 [ V_42 ] , 0 , sizeof( V_68 [ V_42 ] ) ) ;
V_89 = ( unsigned long ) V_39 + ( V_46 * V_42 ) ;
V_68 [ V_42 ] . V_110 = F_43 (
F_63 ( V_89 , & V_106 ) ) . V_81 ;
V_68 [ V_42 ] . V_111 = 0 ;
V_68 [ V_42 ] . V_73 = V_19 -> V_61 [ V_42 ] ;
}
if ( F_38 ( V_75 , V_68 , V_42 ) )
F_39 () ;
V_18 = V_69 ;
V_64 = false ;
for ( V_42 = 0 ; V_42 < V_19 -> V_84 ; V_42 ++ ) {
if ( V_68 [ V_42 ] . V_72 != V_69 ) {
V_64 = true ;
F_25 ( V_14 , V_68 [ V_42 ] . V_72 ,
L_30 ,
V_19 -> V_61 [ V_42 ] , V_68 [ V_42 ] . V_72 ) ;
V_18 = V_68 [ V_42 ] . V_72 ;
break;
}
}
if ( ! V_64 )
F_47 ( V_19 -> V_85 . V_78 ) ;
else
F_48 ( L_27 ,
V_19 -> V_85 . V_78 , V_19 -> V_84 ) ;
F_9 ( V_19 ) ;
return V_18 ;
}
static void F_64 ( unsigned long V_90 ,
unsigned int V_91 ,
unsigned int V_34 ,
void * V_92 )
{
struct V_112 * V_94 = V_92 ;
V_94 -> V_62 [ V_94 -> V_95 ] = ( unsigned long ) F_50 ( V_90 ) ;
V_94 -> V_95 ++ ;
}
static int F_65 ( struct V_13 * V_14 , void * V_39 )
{
int V_113 ;
struct V_76 * V_19 ;
void * V_89 ;
struct V_112 V_94 = {
. V_95 = 0 ,
} ;
unsigned int V_40 ;
F_44 ( & V_86 ) ;
F_61 (node, &xenbus_valloc_pages, next) {
V_89 = V_19 -> V_97 . V_89 ;
if ( V_89 == V_39 ) {
F_62 ( & V_19 -> V_87 ) ;
goto V_107;
}
}
V_19 = V_89 = NULL ;
V_107:
F_46 ( & V_86 ) ;
if ( ! V_19 ) {
F_25 ( V_14 , - V_108 ,
L_29 , V_39 ) ;
return V_109 ;
}
V_40 = F_52 ( V_19 -> V_84 ) ;
F_54 ( V_19 -> V_97 . V_98 , V_19 -> V_84 ,
F_64 ,
& V_94 ) ;
V_113 = F_56 ( V_14 , V_19 -> V_61 , V_19 -> V_84 ,
V_94 . V_62 ) ;
if ( ! V_113 ) {
F_66 ( V_39 ) ;
F_57 ( V_40 , V_19 -> V_97 . V_98 ) ;
}
else
F_67 ( 1 , L_31 , V_39 , V_40 ) ;
F_9 ( V_19 ) ;
return V_113 ;
}
int F_56 ( struct V_13 * V_14 ,
T_3 * V_61 , unsigned int V_84 ,
unsigned long * V_105 )
{
struct V_67 V_68 [ V_66 ] ;
int V_42 ;
int V_18 ;
if ( V_84 > V_66 )
return - V_70 ;
for ( V_42 = 0 ; V_42 < V_84 ; V_42 ++ )
F_37 ( & V_68 [ V_42 ] , V_105 [ V_42 ] ,
V_74 , V_61 [ V_42 ] ) ;
if ( F_38 ( V_75 , V_68 , V_42 ) )
F_39 () ;
V_18 = V_69 ;
for ( V_42 = 0 ; V_42 < V_84 ; V_42 ++ ) {
if ( V_68 [ V_42 ] . V_72 != V_69 ) {
F_25 ( V_14 , V_68 [ V_42 ] . V_72 ,
L_30 ,
V_61 [ V_42 ] , V_68 [ V_42 ] . V_72 ) ;
V_18 = V_68 [ V_42 ] . V_72 ;
break;
}
}
return V_18 ;
}
enum V_1 F_68 ( const char * V_15 )
{
enum V_1 V_114 ;
int V_18 = F_69 ( V_38 , V_15 , L_14 , L_15 , & V_114 , NULL ) ;
if ( V_18 )
V_114 = V_4 ;
return V_114 ;
}
void T_6 F_70 ( void )
{
if ( ! F_71 ( V_115 ) )
V_59 = & V_116 ;
else
V_59 = & V_117 ;
}
