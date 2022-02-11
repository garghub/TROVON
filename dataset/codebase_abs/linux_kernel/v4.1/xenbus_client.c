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
const char * * , unsigned int ) )
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
const char * * , unsigned int ) ,
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
static char * F_19 ( struct V_13 * V_14 )
{
return F_20 ( V_33 , L_18 , V_14 -> V_30 ) ;
}
static void F_21 ( struct V_13 * V_14 , int V_18 ,
const char * V_34 , T_1 V_21 )
{
unsigned int V_35 ;
char * V_36 = NULL ;
char * V_37 = NULL ;
#define F_22 4096
V_36 = F_23 ( F_22 , V_33 ) ;
if ( V_36 == NULL )
goto V_38;
V_35 = sprintf ( V_36 , L_19 , - V_18 ) ;
vsnprintf ( V_36 + V_35 , F_22 - V_35 , V_34 , V_21 ) ;
F_24 ( & V_14 -> V_14 , L_20 , V_36 ) ;
V_37 = F_19 ( V_14 ) ;
if ( V_37 == NULL ) {
F_24 ( & V_14 -> V_14 , L_21 ,
V_14 -> V_30 , V_36 ) ;
goto V_38;
}
if ( F_25 ( V_39 , V_37 , L_22 , V_36 ) != 0 ) {
F_24 ( & V_14 -> V_14 , L_21 ,
V_14 -> V_30 , V_36 ) ;
goto V_38;
}
V_38:
F_9 ( V_36 ) ;
F_9 ( V_37 ) ;
}
void F_26 ( struct V_13 * V_14 , int V_18 , const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
}
void F_6 ( struct V_13 * V_14 , int V_18 , const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
F_16 ( V_14 , V_9 ) ;
}
static void F_12 ( struct V_13 * V_14 , int V_25 , int V_18 ,
const char * V_34 , ... )
{
T_1 V_21 ;
va_start ( V_21 , V_34 ) ;
F_21 ( V_14 , V_18 , V_34 , V_21 ) ;
va_end ( V_21 ) ;
if ( ! V_25 )
F_10 ( V_14 , V_9 , 1 ) ;
}
int F_27 ( struct V_13 * V_14 , void * V_40 ,
unsigned int V_41 , T_2 * V_42 )
{
int V_18 ;
int V_43 , V_44 ;
for ( V_43 = 0 ; V_43 < V_41 ; V_43 ++ ) {
unsigned long V_45 = ( unsigned long ) V_40 +
( V_46 * V_43 ) ;
V_18 = F_28 ( V_14 -> V_47 ,
F_29 ( V_45 ) , 0 ) ;
if ( V_18 < 0 ) {
F_6 ( V_14 , V_18 ,
L_23 ) ;
goto V_38;
}
V_42 [ V_43 ] = V_18 ;
}
return 0 ;
V_38:
for ( V_44 = 0 ; V_44 < V_43 ; V_44 ++ )
F_30 ( V_42 [ V_44 ] , 0 ) ;
return V_18 ;
}
int F_31 ( struct V_13 * V_14 , int * V_48 )
{
struct V_49 V_50 ;
int V_18 ;
V_50 . V_51 = V_52 ;
V_50 . V_53 = V_14 -> V_47 ;
V_18 = F_32 ( V_54 ,
& V_50 ) ;
if ( V_18 )
F_6 ( V_14 , V_18 , L_24 ) ;
else
* V_48 = V_50 . V_48 ;
return V_18 ;
}
int F_33 ( struct V_13 * V_14 , int V_48 )
{
struct V_55 V_56 ;
int V_18 ;
V_56 . V_48 = V_48 ;
V_18 = F_32 ( V_57 , & V_56 ) ;
if ( V_18 )
F_26 ( V_14 , V_18 , L_25 , V_48 ) ;
return V_18 ;
}
int F_34 ( struct V_13 * V_14 , T_2 * V_58 ,
unsigned int V_59 , void * * V_40 )
{
return V_60 -> V_61 ( V_14 , V_58 , V_59 , V_40 ) ;
}
static int F_35 ( struct V_13 * V_14 ,
T_2 * V_58 ,
unsigned int V_59 ,
T_3 * V_62 ,
T_4 * V_63 ,
unsigned int V_64 ,
bool * V_65 )
{
struct V_66 V_61 [ V_67 ] ;
struct V_68 V_69 [ V_67 ] ;
int V_43 , V_44 ;
int V_18 = V_70 ;
if ( V_59 > V_67 )
return - V_71 ;
for ( V_43 = 0 ; V_43 < V_59 ; V_43 ++ ) {
memset ( & V_61 [ V_43 ] , 0 , sizeof( V_61 [ V_43 ] ) ) ;
F_36 ( & V_61 [ V_43 ] , V_63 [ V_43 ] , V_64 , V_58 [ V_43 ] ,
V_14 -> V_47 ) ;
V_62 [ V_43 ] = V_72 ;
}
F_37 ( V_61 , V_43 ) ;
for ( V_43 = 0 ; V_43 < V_59 ; V_43 ++ ) {
if ( V_61 [ V_43 ] . V_73 != V_70 ) {
V_18 = V_61 [ V_43 ] . V_73 ;
F_6 ( V_14 , V_61 [ V_43 ] . V_73 ,
L_26 ,
V_58 [ V_43 ] , V_14 -> V_47 ) ;
goto V_38;
} else
V_62 [ V_43 ] = V_61 [ V_43 ] . V_74 ;
}
return V_70 ;
V_38:
for ( V_43 = V_44 = 0 ; V_43 < V_59 ; V_43 ++ ) {
if ( V_62 [ V_43 ] != V_72 ) {
memset ( & V_69 [ V_44 ] , 0 , sizeof( V_69 [ V_44 ] ) ) ;
F_38 ( & V_69 [ V_44 ] , ( T_4 ) V_63 [ V_43 ] ,
V_75 , V_62 [ V_43 ] ) ;
V_44 ++ ;
}
}
if ( F_39 ( V_76 , V_69 , V_44 ) )
F_40 () ;
* V_65 = false ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
if ( V_69 [ V_43 ] . V_73 != V_70 ) {
* V_65 = true ;
break;
}
}
return V_18 ;
}
static int F_41 ( struct V_13 * V_14 ,
T_2 * V_58 ,
unsigned int V_59 ,
void * * V_40 )
{
struct V_77 * V_19 ;
struct V_78 * V_79 ;
T_5 * V_80 [ V_67 ] ;
T_4 V_81 [ V_67 ] ;
int V_18 = V_70 ;
int V_43 ;
bool V_65 ;
* V_40 = NULL ;
if ( V_59 > V_67 )
return - V_71 ;
V_19 = F_42 ( sizeof( * V_19 ) , V_33 ) ;
if ( ! V_19 )
return - V_24 ;
V_79 = F_43 ( V_46 * V_59 , V_80 ) ;
if ( ! V_79 ) {
F_9 ( V_19 ) ;
return - V_24 ;
}
for ( V_43 = 0 ; V_43 < V_59 ; V_43 ++ )
V_81 [ V_43 ] = F_44 ( V_80 [ V_43 ] ) . V_82 ;
V_18 = F_35 ( V_14 , V_58 , V_59 , V_19 -> V_62 ,
V_81 ,
V_75 | V_83 ,
& V_65 ) ;
if ( V_18 )
goto V_84;
V_19 -> V_85 = V_59 ;
V_19 -> V_86 . V_79 = V_79 ;
F_45 ( & V_87 ) ;
F_46 ( & V_19 -> V_88 , & V_89 ) ;
F_47 ( & V_87 ) ;
* V_40 = V_79 -> V_45 ;
return 0 ;
V_84:
if ( ! V_65 )
F_48 ( V_79 ) ;
else
F_49 ( L_27 , V_79 , V_59 ) ;
F_9 ( V_19 ) ;
return V_18 ;
}
static int F_50 ( struct V_13 * V_14 ,
T_2 * V_90 ,
unsigned int V_59 ,
void * * V_40 )
{
struct V_77 * V_19 ;
int V_43 ;
int V_18 ;
void * V_45 ;
bool V_65 = false ;
T_4 V_81 [ V_67 ] ;
unsigned long V_63 [ V_67 ] ;
if ( V_59 > V_67 )
return - V_71 ;
* V_40 = NULL ;
V_19 = F_42 ( sizeof( * V_19 ) , V_33 ) ;
if ( ! V_19 )
return - V_24 ;
V_18 = F_51 ( V_59 , V_19 -> V_91 . V_92 ,
false ) ;
if ( V_18 )
goto V_93;
for ( V_43 = 0 ; V_43 < V_59 ; V_43 ++ ) {
unsigned long V_94 = F_52 ( V_19 -> V_91 . V_92 [ V_43 ] ) ;
V_81 [ V_43 ] = ( unsigned long ) F_53 ( V_94 ) ;
V_63 [ V_43 ] = ( unsigned long ) F_53 ( V_94 ) ;
}
V_18 = F_35 ( V_14 , V_90 , V_59 , V_19 -> V_62 ,
V_81 , V_75 , & V_65 ) ;
V_19 -> V_85 = V_59 ;
if ( V_18 )
goto V_95;
V_45 = F_54 ( V_19 -> V_91 . V_92 , V_59 , V_96 | V_97 ,
V_98 ) ;
if ( ! V_45 ) {
V_18 = - V_24 ;
goto V_99;
}
V_19 -> V_91 . V_45 = V_45 ;
F_45 ( & V_87 ) ;
F_46 ( & V_19 -> V_88 , & V_89 ) ;
F_47 ( & V_87 ) ;
* V_40 = V_45 ;
return 0 ;
V_99:
if ( ! V_65 )
F_55 ( V_14 , V_19 -> V_62 , V_19 -> V_85 ,
V_63 ) ;
else
F_49 ( L_28 ,
V_45 , V_59 ) ;
V_95:
if ( ! V_65 )
F_56 ( V_59 , V_19 -> V_91 . V_92 ) ;
V_93:
F_9 ( V_19 ) ;
return V_18 ;
}
int F_57 ( struct V_13 * V_14 , T_2 * V_58 ,
unsigned int V_59 , T_3 * V_62 ,
unsigned long * V_100 , bool * V_65 )
{
T_4 V_81 [ V_67 ] ;
int V_43 ;
if ( V_59 > V_67 )
return - V_71 ;
for ( V_43 = 0 ; V_43 < V_59 ; V_43 ++ )
V_81 [ V_43 ] = ( unsigned long ) V_100 [ V_43 ] ;
return F_35 ( V_14 , V_58 , V_59 , V_62 ,
V_81 , V_75 , V_65 ) ;
}
int F_58 ( struct V_13 * V_14 , void * V_40 )
{
return V_60 -> V_69 ( V_14 , V_40 ) ;
}
static int F_59 ( struct V_13 * V_14 , void * V_40 )
{
struct V_77 * V_19 ;
struct V_68 V_69 [ V_67 ] ;
unsigned int V_101 ;
int V_43 ;
bool V_65 = false ;
int V_18 ;
F_45 ( & V_87 ) ;
F_60 (node, &xenbus_valloc_pages, next) {
if ( V_19 -> V_86 . V_79 -> V_45 == V_40 ) {
F_61 ( & V_19 -> V_88 ) ;
goto V_102;
}
}
V_19 = NULL ;
V_102:
F_47 ( & V_87 ) ;
if ( ! V_19 ) {
F_26 ( V_14 , - V_103 ,
L_29 , V_40 ) ;
return V_104 ;
}
for ( V_43 = 0 ; V_43 < V_19 -> V_85 ; V_43 ++ ) {
unsigned long V_45 ;
memset ( & V_69 [ V_43 ] , 0 , sizeof( V_69 [ V_43 ] ) ) ;
V_45 = ( unsigned long ) V_40 + ( V_46 * V_43 ) ;
V_69 [ V_43 ] . V_105 = F_44 (
F_62 ( V_45 , & V_101 ) ) . V_82 ;
V_69 [ V_43 ] . V_106 = 0 ;
V_69 [ V_43 ] . V_74 = V_19 -> V_62 [ V_43 ] ;
}
if ( F_39 ( V_76 , V_69 , V_43 ) )
F_40 () ;
V_18 = V_70 ;
V_65 = false ;
for ( V_43 = 0 ; V_43 < V_19 -> V_85 ; V_43 ++ ) {
if ( V_69 [ V_43 ] . V_73 != V_70 ) {
V_65 = true ;
F_26 ( V_14 , V_69 [ V_43 ] . V_73 ,
L_30 ,
V_19 -> V_62 [ V_43 ] , V_69 [ V_43 ] . V_73 ) ;
V_18 = V_69 [ V_43 ] . V_73 ;
break;
}
}
if ( ! V_65 )
F_48 ( V_19 -> V_86 . V_79 ) ;
else
F_49 ( L_27 ,
V_19 -> V_86 . V_79 , V_19 -> V_85 ) ;
F_9 ( V_19 ) ;
return V_18 ;
}
static int F_63 ( struct V_13 * V_14 , void * V_40 )
{
int V_107 ;
struct V_77 * V_19 ;
void * V_45 ;
unsigned long V_63 [ V_67 ] ;
int V_43 ;
F_45 ( & V_87 ) ;
F_60 (node, &xenbus_valloc_pages, next) {
V_45 = V_19 -> V_91 . V_45 ;
if ( V_45 == V_40 ) {
F_61 ( & V_19 -> V_88 ) ;
goto V_102;
}
}
V_19 = V_45 = NULL ;
V_102:
F_47 ( & V_87 ) ;
if ( ! V_19 ) {
F_26 ( V_14 , - V_103 ,
L_29 , V_40 ) ;
return V_104 ;
}
for ( V_43 = 0 ; V_43 < V_19 -> V_85 ; V_43 ++ )
V_63 [ V_43 ] = ( unsigned long ) F_53 ( F_52 ( V_19 -> V_91 . V_92 [ V_43 ] ) ) ;
V_107 = F_55 ( V_14 , V_19 -> V_62 , V_19 -> V_85 ,
V_63 ) ;
if ( ! V_107 )
F_64 ( V_40 ) ;
else
F_65 ( 1 , L_31 , V_40 ,
V_19 -> V_85 ) ;
F_9 ( V_19 ) ;
return V_107 ;
}
int F_55 ( struct V_13 * V_14 ,
T_3 * V_62 , unsigned int V_85 ,
unsigned long * V_100 )
{
struct V_68 V_69 [ V_67 ] ;
int V_43 ;
int V_18 ;
if ( V_85 > V_67 )
return - V_71 ;
for ( V_43 = 0 ; V_43 < V_85 ; V_43 ++ )
F_38 ( & V_69 [ V_43 ] , V_100 [ V_43 ] ,
V_75 , V_62 [ V_43 ] ) ;
if ( F_39 ( V_76 , V_69 , V_43 ) )
F_40 () ;
V_18 = V_70 ;
for ( V_43 = 0 ; V_43 < V_85 ; V_43 ++ ) {
if ( V_69 [ V_43 ] . V_73 != V_70 ) {
F_26 ( V_14 , V_69 [ V_43 ] . V_73 ,
L_30 ,
V_62 [ V_43 ] , V_69 [ V_43 ] . V_73 ) ;
V_18 = V_69 [ V_43 ] . V_73 ;
break;
}
}
return V_18 ;
}
enum V_1 F_66 ( const char * V_15 )
{
enum V_1 V_108 ;
int V_18 = F_67 ( V_39 , V_15 , L_14 , L_15 , & V_108 , NULL ) ;
if ( V_18 )
V_108 = V_4 ;
return V_108 ;
}
void T_6 F_68 ( void )
{
if ( ! F_69 ( V_109 ) )
V_60 = & V_110 ;
else
V_60 = & V_111 ;
}
