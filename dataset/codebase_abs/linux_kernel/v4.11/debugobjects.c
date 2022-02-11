static int T_1 F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static int T_1 F_2 ( char * V_1 )
{
V_2 = 0 ;
return 0 ;
}
static void F_3 ( void )
{
T_2 V_3 = V_4 | V_5 | V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
if ( F_4 ( V_10 >= V_11 ) )
return;
if ( F_5 ( ! V_12 ) )
return;
while ( V_10 < V_11 ) {
V_8 = F_6 ( V_12 , V_3 ) ;
if ( ! V_8 )
return;
F_7 ( & V_13 , V_9 ) ;
F_8 ( & V_8 -> V_14 , & V_15 ) ;
V_16 ++ ;
V_10 ++ ;
F_9 ( & V_13 , V_9 ) ;
}
}
static struct V_7 * F_10 ( void * V_17 , struct V_18 * V_19 )
{
struct V_7 * V_20 ;
int V_21 = 0 ;
F_11 (obj, &b->list, node) {
V_21 ++ ;
if ( V_20 -> V_22 == V_17 )
return V_20 ;
}
if ( V_21 > V_23 )
V_23 = V_21 ;
return NULL ;
}
static struct V_7 *
F_12 ( void * V_17 , struct V_18 * V_19 , struct V_24 * V_25 )
{
struct V_7 * V_20 = NULL ;
F_13 ( & V_13 ) ;
if ( V_15 . V_26 ) {
V_20 = F_14 ( V_15 . V_26 , F_15 ( * V_20 ) , V_14 ) ;
V_20 -> V_22 = V_17 ;
V_20 -> V_25 = V_25 ;
V_20 -> V_27 = V_28 ;
V_20 -> V_29 = 0 ;
F_16 ( & V_20 -> V_14 ) ;
F_8 ( & V_20 -> V_14 , & V_19 -> V_30 ) ;
V_31 ++ ;
if ( V_31 > V_32 )
V_32 = V_31 ;
V_10 -- ;
if ( V_10 < V_33 )
V_33 = V_10 ;
}
F_17 ( & V_13 ) ;
return V_20 ;
}
static void F_18 ( struct V_34 * V_35 )
{
struct V_7 * V_36 [ V_37 ] ;
unsigned long V_9 ;
int V_38 ;
if ( ! F_19 ( & V_13 , V_9 ) )
return;
while ( V_10 >= V_39 + V_37 ) {
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
V_36 [ V_38 ] = F_14 ( V_15 . V_26 ,
F_15 ( * V_36 [ 0 ] ) , V_14 ) ;
F_16 ( & V_36 [ V_38 ] -> V_14 ) ;
}
V_10 -= V_37 ;
V_40 += V_37 ;
F_9 ( & V_13 , V_9 ) ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ )
F_20 ( V_12 , V_36 [ V_38 ] ) ;
if ( ! F_19 ( & V_13 , V_9 ) )
return;
}
F_9 ( & V_13 , V_9 ) ;
}
static void F_21 ( struct V_7 * V_20 )
{
unsigned long V_9 ;
int V_41 = 0 ;
F_7 ( & V_13 , V_9 ) ;
if ( V_10 > V_39 && V_12 )
V_41 = 1 ;
F_8 ( & V_20 -> V_14 , & V_15 ) ;
V_10 ++ ;
V_31 -- ;
F_9 ( & V_13 , V_9 ) ;
if ( V_41 )
F_22 ( & V_42 ) ;
}
static void F_23 ( void )
{
struct V_18 * V_43 = V_44 ;
struct V_45 * V_46 ;
F_24 ( V_47 ) ;
struct V_7 * V_20 ;
unsigned long V_9 ;
int V_38 ;
F_25 ( L_1 ) ;
for ( V_38 = 0 ; V_38 < V_48 ; V_38 ++ , V_43 ++ ) {
F_7 ( & V_43 -> V_49 , V_9 ) ;
F_26 ( & V_43 -> V_30 , & V_47 ) ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_27 (obj, tmp, &freelist, node) {
F_16 ( & V_20 -> V_14 ) ;
F_21 ( V_20 ) ;
}
}
}
static struct V_18 * F_28 ( unsigned long V_17 )
{
unsigned long V_50 ;
V_50 = F_29 ( ( V_17 >> V_51 ) , V_52 ) ;
return & V_44 [ V_50 ] ;
}
static void F_30 ( struct V_7 * V_20 , char * V_53 )
{
struct V_24 * V_25 = V_20 -> V_25 ;
static int V_54 ;
if ( V_54 < 5 && V_25 != V_55 ) {
void * V_56 = V_25 -> V_57 ?
V_25 -> V_57 ( V_20 -> V_22 ) : NULL ;
V_54 ++ ;
F_31 ( 1 , V_58 L_2
L_3 ,
V_53 , V_59 [ V_20 -> V_27 ] , V_20 -> V_29 ,
V_25 -> V_60 , V_56 ) ;
}
V_61 ++ ;
}
static bool
F_32 ( bool (* F_33)( void * V_17 , enum V_62 V_27 ) ,
void * V_17 , enum V_62 V_27 )
{
if ( F_33 && F_33 ( V_17 , V_27 ) ) {
V_63 ++ ;
return true ;
}
return false ;
}
static void F_34 ( void * V_17 , int V_64 )
{
int V_65 ;
static int V_54 ;
if ( V_54 > 4 )
return;
V_65 = F_35 ( V_17 ) ;
if ( V_65 == V_64 )
return;
V_54 ++ ;
if ( V_65 )
F_25 ( L_4 ) ;
else
F_25 ( L_5 ) ;
F_36 ( 1 ) ;
}
static void
F_37 ( void * V_17 , struct V_24 * V_25 , int V_64 )
{
enum V_62 V_27 ;
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
F_3 () ;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( ! V_20 ) {
V_20 = F_12 ( V_17 , V_43 , V_25 ) ;
if ( ! V_20 ) {
V_2 = 0 ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_23 () ;
return;
}
F_34 ( V_17 , V_64 ) ;
}
switch ( V_20 -> V_27 ) {
case V_28 :
case V_66 :
case V_67 :
V_20 -> V_27 = V_66 ;
break;
case V_68 :
F_30 ( V_20 , L_6 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_32 ( V_25 -> V_69 , V_17 , V_27 ) ;
return;
case V_70 :
F_30 ( V_20 , L_6 ) ;
break;
default:
break;
}
F_9 ( & V_43 -> V_49 , V_9 ) ;
}
void F_38 ( void * V_17 , struct V_24 * V_25 )
{
if ( ! V_2 )
return;
F_37 ( V_17 , V_25 , 0 ) ;
}
void F_39 ( void * V_17 , struct V_24 * V_25 )
{
if ( ! V_2 )
return;
F_37 ( V_17 , V_25 , 1 ) ;
}
int F_40 ( void * V_17 , struct V_24 * V_25 )
{
enum V_62 V_27 ;
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
int V_71 ;
struct V_7 V_72 = { . V_22 = V_17 ,
. V_27 = V_73 ,
. V_25 = V_25 } ;
if ( ! V_2 )
return 0 ;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( V_20 ) {
switch ( V_20 -> V_27 ) {
case V_66 :
case V_67 :
V_20 -> V_27 = V_68 ;
V_71 = 0 ;
break;
case V_68 :
F_30 ( V_20 , L_7 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
V_71 = F_32 ( V_25 -> V_74 , V_17 , V_27 ) ;
return V_71 ? 0 : - V_75 ;
case V_70 :
F_30 ( V_20 , L_7 ) ;
V_71 = - V_75 ;
break;
default:
V_71 = 0 ;
break;
}
F_9 ( & V_43 -> V_49 , V_9 ) ;
return V_71 ;
}
F_9 ( & V_43 -> V_49 , V_9 ) ;
if ( V_25 -> V_76 && V_25 -> V_76 ( V_17 ) ) {
F_38 ( V_17 , V_25 ) ;
F_40 ( V_17 , V_25 ) ;
} else {
F_30 ( & V_72 , L_7 ) ;
V_71 = F_32 ( V_25 -> V_74 , V_17 ,
V_73 ) ;
return V_71 ? 0 : - V_75 ;
}
return 0 ;
}
void F_41 ( void * V_17 , struct V_24 * V_25 )
{
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( V_20 ) {
switch ( V_20 -> V_27 ) {
case V_66 :
case V_67 :
case V_68 :
if ( ! V_20 -> V_29 )
V_20 -> V_27 = V_67 ;
else
F_30 ( V_20 , L_8 ) ;
break;
case V_70 :
F_30 ( V_20 , L_8 ) ;
break;
default:
break;
}
} else {
struct V_7 V_72 = { . V_22 = V_17 ,
. V_27 = V_73 ,
. V_25 = V_25 } ;
F_30 ( & V_72 , L_8 ) ;
}
F_9 ( & V_43 -> V_49 , V_9 ) ;
}
void F_42 ( void * V_17 , struct V_24 * V_25 )
{
enum V_62 V_27 ;
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( ! V_20 )
goto V_77;
switch ( V_20 -> V_27 ) {
case V_28 :
case V_66 :
case V_67 :
V_20 -> V_27 = V_70 ;
break;
case V_68 :
F_30 ( V_20 , L_9 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_32 ( V_25 -> V_78 , V_17 , V_27 ) ;
return;
case V_70 :
F_30 ( V_20 , L_9 ) ;
break;
default:
break;
}
V_77:
F_9 ( & V_43 -> V_49 , V_9 ) ;
}
void F_43 ( void * V_17 , struct V_24 * V_25 )
{
enum V_62 V_27 ;
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( ! V_20 )
goto V_77;
switch ( V_20 -> V_27 ) {
case V_68 :
F_30 ( V_20 , L_10 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_32 ( V_25 -> V_79 , V_17 , V_27 ) ;
return;
default:
F_16 ( & V_20 -> V_14 ) ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_21 ( V_20 ) ;
return;
}
V_77:
F_9 ( & V_43 -> V_49 , V_9 ) ;
}
void F_44 ( void * V_17 , struct V_24 * V_25 )
{
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( ! V_20 ) {
struct V_7 V_72 = { . V_22 = V_17 ,
. V_27 = V_73 ,
. V_25 = V_25 } ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
if ( V_25 -> V_76 && V_25 -> V_76 ( V_17 ) ) {
F_38 ( V_17 , V_25 ) ;
} else {
F_30 ( & V_72 , L_11 ) ;
F_32 ( V_25 -> V_80 , V_17 ,
V_73 ) ;
}
return;
}
F_9 ( & V_43 -> V_49 , V_9 ) ;
}
void
F_45 ( void * V_17 , struct V_24 * V_25 ,
unsigned int V_81 , unsigned int V_82 )
{
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( V_20 ) {
switch ( V_20 -> V_27 ) {
case V_68 :
if ( V_20 -> V_29 == V_81 )
V_20 -> V_29 = V_82 ;
else
F_30 ( V_20 , L_12 ) ;
break;
default:
F_30 ( V_20 , L_12 ) ;
break;
}
} else {
struct V_7 V_72 = { . V_22 = V_17 ,
. V_27 = V_73 ,
. V_25 = V_25 } ;
F_30 ( & V_72 , L_12 ) ;
}
F_9 ( & V_43 -> V_49 , V_9 ) ;
}
static void F_46 ( const void * V_83 , unsigned long V_84 )
{
unsigned long V_9 , V_85 , V_86 , V_87 , V_88 , V_89 ;
struct V_45 * V_46 ;
F_24 ( V_47 ) ;
struct V_24 * V_25 ;
enum V_62 V_27 ;
struct V_18 * V_43 ;
struct V_7 * V_20 ;
int V_21 ;
V_86 = ( unsigned long ) V_83 ;
V_87 = V_86 + V_84 ;
V_88 = V_86 & V_90 ;
V_89 = ( ( V_87 - V_88 ) + ( V_91 - 1 ) ) ;
V_89 >>= V_51 ;
for (; V_89 > 0 ; V_89 -- , V_88 += V_91 ) {
V_43 = F_28 ( V_88 ) ;
V_92:
V_21 = 0 ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
F_27 (obj, tmp, &db->list, node) {
V_21 ++ ;
V_85 = ( unsigned long ) V_20 -> V_22 ;
if ( V_85 < V_86 || V_85 >= V_87 )
continue;
switch ( V_20 -> V_27 ) {
case V_68 :
F_30 ( V_20 , L_10 ) ;
V_25 = V_20 -> V_25 ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_32 ( V_25 -> V_79 ,
( void * ) V_85 , V_27 ) ;
goto V_92;
default:
F_16 ( & V_20 -> V_14 ) ;
F_8 ( & V_20 -> V_14 , & V_47 ) ;
break;
}
}
F_9 ( & V_43 -> V_49 , V_9 ) ;
F_27 (obj, tmp, &freelist, node) {
F_16 ( & V_20 -> V_14 ) ;
F_21 ( V_20 ) ;
}
if ( V_21 > V_23 )
V_23 = V_21 ;
}
}
void F_47 ( const void * V_83 , unsigned long V_84 )
{
if ( V_2 )
F_46 ( V_83 , V_84 ) ;
}
static int F_48 ( struct V_93 * V_94 , void * V_95 )
{
F_49 ( V_94 , L_13 , V_23 ) ;
F_49 ( V_94 , L_14 , V_61 ) ;
F_49 ( V_94 , L_15 , V_63 ) ;
F_49 ( V_94 , L_16 , V_10 ) ;
F_49 ( V_94 , L_17 , V_33 ) ;
F_49 ( V_94 , L_18 , V_31 ) ;
F_49 ( V_94 , L_19 , V_32 ) ;
F_49 ( V_94 , L_20 , V_16 ) ;
F_49 ( V_94 , L_21 , V_40 ) ;
return 0 ;
}
static int F_50 ( struct V_96 * V_96 , struct V_97 * V_98 )
{
return F_51 ( V_98 , F_48 , NULL ) ;
}
static int T_1 F_52 ( void )
{
struct V_99 * V_100 , * V_101 ;
if ( ! V_2 )
return 0 ;
V_100 = F_53 ( L_22 , NULL ) ;
if ( ! V_100 )
return - V_102 ;
V_101 = F_54 ( L_23 , 0444 , V_100 , NULL ,
& V_103 ) ;
if ( ! V_101 )
goto V_104;
return 0 ;
V_104:
F_55 ( V_100 ) ;
return - V_102 ;
}
static inline void F_52 ( void ) { }
static bool T_1 V_76 ( void * V_17 )
{
struct V_105 * V_20 = V_17 ;
return V_20 -> V_106 ;
}
static bool T_1 V_69 ( void * V_17 , enum V_62 V_27 )
{
struct V_105 * V_20 = V_17 ;
switch ( V_27 ) {
case V_68 :
F_41 ( V_20 , & V_107 ) ;
F_38 ( V_20 , & V_107 ) ;
return true ;
default:
return false ;
}
}
static bool T_1 V_74 ( void * V_17 , enum V_62 V_27 )
{
struct V_105 * V_20 = V_17 ;
switch ( V_27 ) {
case V_73 :
return true ;
case V_68 :
F_41 ( V_20 , & V_107 ) ;
F_40 ( V_20 , & V_107 ) ;
return true ;
default:
return false ;
}
}
static bool T_1 V_78 ( void * V_17 , enum V_62 V_27 )
{
struct V_105 * V_20 = V_17 ;
switch ( V_27 ) {
case V_68 :
F_41 ( V_20 , & V_107 ) ;
F_42 ( V_20 , & V_107 ) ;
return true ;
default:
return false ;
}
}
static bool T_1 V_79 ( void * V_17 , enum V_62 V_27 )
{
struct V_105 * V_20 = V_17 ;
switch ( V_27 ) {
case V_68 :
F_41 ( V_20 , & V_107 ) ;
F_43 ( V_20 , & V_107 ) ;
return true ;
default:
return false ;
}
}
static int T_1
F_56 ( void * V_17 , enum V_62 V_27 , int V_108 , int V_109 )
{
struct V_18 * V_43 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
int V_110 = - V_75 ;
V_43 = F_28 ( ( unsigned long ) V_17 ) ;
F_7 ( & V_43 -> V_49 , V_9 ) ;
V_20 = F_10 ( V_17 , V_43 ) ;
if ( ! V_20 && V_27 != V_28 ) {
F_31 ( 1 , V_58 L_24 ) ;
goto V_111;
}
if ( V_20 && V_20 -> V_27 != V_27 ) {
F_31 ( 1 , V_58 L_25 ,
V_20 -> V_27 , V_27 ) ;
goto V_111;
}
if ( V_108 != V_63 ) {
F_31 ( 1 , V_58 L_26 ,
V_108 , V_63 ) ;
goto V_111;
}
if ( V_109 != V_61 ) {
F_31 ( 1 , V_58 L_27 ,
V_109 , V_61 ) ;
goto V_111;
}
V_110 = 0 ;
V_111:
F_9 ( & V_43 -> V_49 , V_9 ) ;
if ( V_110 )
V_2 = 0 ;
return V_110 ;
}
static void T_1 F_57 ( void )
{
int V_108 , V_112 , V_109 , V_113 ;
unsigned long V_9 ;
F_58 ( V_9 ) ;
V_108 = V_112 = V_63 ;
V_109 = V_113 = V_61 ;
V_55 = & V_107 ;
F_38 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_66 , V_108 , V_109 ) )
goto V_111;
F_40 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_68 , V_108 , V_109 ) )
goto V_111;
F_40 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_68 , ++ V_108 , ++ V_109 ) )
goto V_111;
F_41 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_67 , V_108 , V_109 ) )
goto V_111;
F_42 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_70 , V_108 , V_109 ) )
goto V_111;
F_38 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_70 , V_108 , ++ V_109 ) )
goto V_111;
F_40 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_70 , V_108 , ++ V_109 ) )
goto V_111;
F_41 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_70 , V_108 , ++ V_109 ) )
goto V_111;
F_43 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_28 , V_108 , V_109 ) )
goto V_111;
V_20 . V_106 = 1 ;
F_40 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_68 , V_108 , V_109 ) )
goto V_111;
F_38 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_66 , ++ V_108 , ++ V_109 ) )
goto V_111;
F_43 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_28 , V_108 , V_109 ) )
goto V_111;
#ifdef F_59
F_38 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_66 , V_108 , V_109 ) )
goto V_111;
F_40 ( & V_20 , & V_107 ) ;
if ( F_56 ( & V_20 , V_68 , V_108 , V_109 ) )
goto V_111;
F_46 ( & V_20 , sizeof( V_20 ) ) ;
if ( F_56 ( & V_20 , V_28 , ++ V_108 , ++ V_109 ) )
goto V_111;
#endif
F_60 ( L_28 ) ;
V_111:
V_63 = V_112 ;
V_61 = V_113 ;
V_55 = NULL ;
F_61 ( V_9 ) ;
}
static inline void F_57 ( void ) { }
void T_1 F_62 ( void )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_48 ; V_38 ++ )
F_63 ( & V_44 [ V_38 ] . V_49 ) ;
for ( V_38 = 0 ; V_38 < V_114 ; V_38 ++ )
F_8 ( & V_115 [ V_38 ] . V_14 , & V_15 ) ;
}
static int T_1 F_64 ( void )
{
struct V_18 * V_43 = V_44 ;
struct V_45 * V_46 ;
struct V_7 * V_20 , * V_8 ;
F_24 ( V_116 ) ;
int V_38 , V_21 = 0 ;
for ( V_38 = 0 ; V_38 < V_114 ; V_38 ++ ) {
V_20 = F_6 ( V_12 , V_117 ) ;
if ( ! V_20 )
goto free;
F_8 ( & V_20 -> V_14 , & V_116 ) ;
}
F_65 () ;
F_27 (obj, tmp, &obj_pool, node)
F_16 ( & V_20 -> V_14 ) ;
F_26 ( & V_116 , & V_15 ) ;
for ( V_38 = 0 ; V_38 < V_48 ; V_38 ++ , V_43 ++ ) {
F_26 ( & V_43 -> V_30 , & V_116 ) ;
F_11 (obj, &objects, node) {
V_8 = F_14 ( V_15 . V_26 , F_15 ( * V_20 ) , V_14 ) ;
F_16 ( & V_8 -> V_14 ) ;
* V_8 = * V_20 ;
F_8 ( & V_8 -> V_14 , & V_43 -> V_30 ) ;
V_21 ++ ;
}
}
F_66 () ;
F_67 ( L_29 ,
V_21 , V_31 ) ;
return 0 ;
free:
F_27 (obj, tmp, &objects, node) {
F_16 ( & V_20 -> V_14 ) ;
F_20 ( V_12 , V_20 ) ;
}
return - V_102 ;
}
void T_1 F_68 ( void )
{
if ( ! V_2 )
return;
V_12 = F_69 ( L_30 ,
sizeof ( struct V_7 ) , 0 ,
V_118 , NULL ) ;
if ( ! V_12 || F_64 () ) {
V_2 = 0 ;
if ( V_12 )
F_70 ( V_12 ) ;
F_25 ( L_31 ) ;
} else
F_57 () ;
V_39 += F_71 () * 32 ;
V_11 += F_71 () * 4 ;
}
