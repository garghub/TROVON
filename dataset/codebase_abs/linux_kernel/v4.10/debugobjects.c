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
V_10 ++ ;
F_9 ( & V_13 , V_9 ) ;
}
}
static struct V_7 * F_10 ( void * V_16 , struct V_17 * V_18 )
{
struct V_7 * V_19 ;
int V_20 = 0 ;
F_11 (obj, &b->list, node) {
V_20 ++ ;
if ( V_19 -> V_21 == V_16 )
return V_19 ;
}
if ( V_20 > V_22 )
V_22 = V_20 ;
return NULL ;
}
static struct V_7 *
F_12 ( void * V_16 , struct V_17 * V_18 , struct V_23 * V_24 )
{
struct V_7 * V_19 = NULL ;
F_13 ( & V_13 ) ;
if ( V_15 . V_25 ) {
V_19 = F_14 ( V_15 . V_25 , F_15 ( * V_19 ) , V_14 ) ;
V_19 -> V_21 = V_16 ;
V_19 -> V_24 = V_24 ;
V_19 -> V_26 = V_27 ;
V_19 -> V_28 = 0 ;
F_16 ( & V_19 -> V_14 ) ;
F_8 ( & V_19 -> V_14 , & V_18 -> V_29 ) ;
V_30 ++ ;
if ( V_30 > V_31 )
V_31 = V_30 ;
V_10 -- ;
if ( V_10 < V_32 )
V_32 = V_10 ;
}
F_17 ( & V_13 ) ;
return V_19 ;
}
static void F_18 ( struct V_33 * V_34 )
{
struct V_7 * V_19 ;
unsigned long V_9 ;
F_7 ( & V_13 , V_9 ) ;
while ( V_10 > V_35 ) {
V_19 = F_14 ( V_15 . V_25 , F_15 ( * V_19 ) , V_14 ) ;
F_16 ( & V_19 -> V_14 ) ;
V_10 -- ;
F_9 ( & V_13 , V_9 ) ;
F_19 ( V_12 , V_19 ) ;
F_7 ( & V_13 , V_9 ) ;
}
F_9 ( & V_13 , V_9 ) ;
}
static void F_20 ( struct V_7 * V_19 )
{
unsigned long V_9 ;
int V_36 = 0 ;
F_7 ( & V_13 , V_9 ) ;
if ( V_10 > V_35 && V_12 )
V_36 = 1 ;
F_8 ( & V_19 -> V_14 , & V_15 ) ;
V_10 ++ ;
V_30 -- ;
F_9 ( & V_13 , V_9 ) ;
if ( V_36 )
F_21 ( & V_37 ) ;
}
static void F_22 ( void )
{
struct V_17 * V_38 = V_39 ;
struct V_40 * V_41 ;
F_23 ( V_42 ) ;
struct V_7 * V_19 ;
unsigned long V_9 ;
int V_43 ;
F_24 ( L_1 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ , V_38 ++ ) {
F_7 ( & V_38 -> V_45 , V_9 ) ;
F_25 ( & V_38 -> V_29 , & V_42 ) ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_26 (obj, tmp, &freelist, node) {
F_16 ( & V_19 -> V_14 ) ;
F_20 ( V_19 ) ;
}
}
}
static struct V_17 * F_27 ( unsigned long V_16 )
{
unsigned long V_46 ;
V_46 = F_28 ( ( V_16 >> V_47 ) , V_48 ) ;
return & V_39 [ V_46 ] ;
}
static void F_29 ( struct V_7 * V_19 , char * V_49 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
static int V_50 ;
if ( V_50 < 5 && V_24 != V_51 ) {
void * V_52 = V_24 -> V_53 ?
V_24 -> V_53 ( V_19 -> V_21 ) : NULL ;
V_50 ++ ;
F_30 ( 1 , V_54 L_2
L_3 ,
V_49 , V_55 [ V_19 -> V_26 ] , V_19 -> V_28 ,
V_24 -> V_56 , V_52 ) ;
}
V_57 ++ ;
}
static bool
F_31 ( bool (* F_32)( void * V_16 , enum V_58 V_26 ) ,
void * V_16 , enum V_58 V_26 )
{
if ( F_32 && F_32 ( V_16 , V_26 ) ) {
V_59 ++ ;
return true ;
}
return false ;
}
static void F_33 ( void * V_16 , int V_60 )
{
int V_61 ;
static int V_50 ;
if ( V_50 > 4 )
return;
V_61 = F_34 ( V_16 ) ;
if ( V_61 == V_60 )
return;
V_50 ++ ;
if ( V_61 )
F_24 ( L_4 ) ;
else
F_24 ( L_5 ) ;
F_35 ( 1 ) ;
}
static void
F_36 ( void * V_16 , struct V_23 * V_24 , int V_60 )
{
enum V_58 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
F_3 () ;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 ) {
V_19 = F_12 ( V_16 , V_38 , V_24 ) ;
if ( ! V_19 ) {
V_2 = 0 ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_22 () ;
return;
}
F_33 ( V_16 , V_60 ) ;
}
switch ( V_19 -> V_26 ) {
case V_27 :
case V_62 :
case V_63 :
V_19 -> V_26 = V_62 ;
break;
case V_64 :
F_29 ( V_19 , L_6 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_31 ( V_24 -> V_65 , V_16 , V_26 ) ;
return;
case V_66 :
F_29 ( V_19 , L_6 ) ;
break;
default:
break;
}
F_9 ( & V_38 -> V_45 , V_9 ) ;
}
void F_37 ( void * V_16 , struct V_23 * V_24 )
{
if ( ! V_2 )
return;
F_36 ( V_16 , V_24 , 0 ) ;
}
void F_38 ( void * V_16 , struct V_23 * V_24 )
{
if ( ! V_2 )
return;
F_36 ( V_16 , V_24 , 1 ) ;
}
int F_39 ( void * V_16 , struct V_23 * V_24 )
{
enum V_58 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
int V_67 ;
struct V_7 V_68 = { . V_21 = V_16 ,
. V_26 = V_69 ,
. V_24 = V_24 } ;
if ( ! V_2 )
return 0 ;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( V_19 ) {
switch ( V_19 -> V_26 ) {
case V_62 :
case V_63 :
V_19 -> V_26 = V_64 ;
V_67 = 0 ;
break;
case V_64 :
F_29 ( V_19 , L_7 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
V_67 = F_31 ( V_24 -> V_70 , V_16 , V_26 ) ;
return V_67 ? 0 : - V_71 ;
case V_66 :
F_29 ( V_19 , L_7 ) ;
V_67 = - V_71 ;
break;
default:
V_67 = 0 ;
break;
}
F_9 ( & V_38 -> V_45 , V_9 ) ;
return V_67 ;
}
F_9 ( & V_38 -> V_45 , V_9 ) ;
if ( V_24 -> V_72 && V_24 -> V_72 ( V_16 ) ) {
F_37 ( V_16 , V_24 ) ;
F_39 ( V_16 , V_24 ) ;
} else {
F_29 ( & V_68 , L_7 ) ;
V_67 = F_31 ( V_24 -> V_70 , V_16 ,
V_69 ) ;
return V_67 ? 0 : - V_71 ;
}
return 0 ;
}
void F_40 ( void * V_16 , struct V_23 * V_24 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( V_19 ) {
switch ( V_19 -> V_26 ) {
case V_62 :
case V_63 :
case V_64 :
if ( ! V_19 -> V_28 )
V_19 -> V_26 = V_63 ;
else
F_29 ( V_19 , L_8 ) ;
break;
case V_66 :
F_29 ( V_19 , L_8 ) ;
break;
default:
break;
}
} else {
struct V_7 V_68 = { . V_21 = V_16 ,
. V_26 = V_69 ,
. V_24 = V_24 } ;
F_29 ( & V_68 , L_8 ) ;
}
F_9 ( & V_38 -> V_45 , V_9 ) ;
}
void F_41 ( void * V_16 , struct V_23 * V_24 )
{
enum V_58 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 )
goto V_73;
switch ( V_19 -> V_26 ) {
case V_27 :
case V_62 :
case V_63 :
V_19 -> V_26 = V_66 ;
break;
case V_64 :
F_29 ( V_19 , L_9 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_31 ( V_24 -> V_74 , V_16 , V_26 ) ;
return;
case V_66 :
F_29 ( V_19 , L_9 ) ;
break;
default:
break;
}
V_73:
F_9 ( & V_38 -> V_45 , V_9 ) ;
}
void F_42 ( void * V_16 , struct V_23 * V_24 )
{
enum V_58 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 )
goto V_73;
switch ( V_19 -> V_26 ) {
case V_64 :
F_29 ( V_19 , L_10 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_31 ( V_24 -> V_75 , V_16 , V_26 ) ;
return;
default:
F_16 ( & V_19 -> V_14 ) ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_20 ( V_19 ) ;
return;
}
V_73:
F_9 ( & V_38 -> V_45 , V_9 ) ;
}
void F_43 ( void * V_16 , struct V_23 * V_24 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 ) {
struct V_7 V_68 = { . V_21 = V_16 ,
. V_26 = V_69 ,
. V_24 = V_24 } ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
if ( V_24 -> V_72 && V_24 -> V_72 ( V_16 ) ) {
F_37 ( V_16 , V_24 ) ;
} else {
F_29 ( & V_68 , L_11 ) ;
F_31 ( V_24 -> V_76 , V_16 ,
V_69 ) ;
}
return;
}
F_9 ( & V_38 -> V_45 , V_9 ) ;
}
void
F_44 ( void * V_16 , struct V_23 * V_24 ,
unsigned int V_77 , unsigned int V_78 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( V_19 ) {
switch ( V_19 -> V_26 ) {
case V_64 :
if ( V_19 -> V_28 == V_77 )
V_19 -> V_28 = V_78 ;
else
F_29 ( V_19 , L_12 ) ;
break;
default:
F_29 ( V_19 , L_12 ) ;
break;
}
} else {
struct V_7 V_68 = { . V_21 = V_16 ,
. V_26 = V_69 ,
. V_24 = V_24 } ;
F_29 ( & V_68 , L_12 ) ;
}
F_9 ( & V_38 -> V_45 , V_9 ) ;
}
static void F_45 ( const void * V_79 , unsigned long V_80 )
{
unsigned long V_9 , V_81 , V_82 , V_83 , V_84 , V_85 ;
struct V_40 * V_41 ;
F_23 ( V_42 ) ;
struct V_23 * V_24 ;
enum V_58 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
int V_20 ;
V_82 = ( unsigned long ) V_79 ;
V_83 = V_82 + V_80 ;
V_84 = V_82 & V_86 ;
V_85 = ( ( V_83 - V_84 ) + ( V_87 - 1 ) ) ;
V_85 >>= V_47 ;
for (; V_85 > 0 ; V_85 -- , V_84 += V_87 ) {
V_38 = F_27 ( V_84 ) ;
V_88:
V_20 = 0 ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
F_26 (obj, tmp, &db->list, node) {
V_20 ++ ;
V_81 = ( unsigned long ) V_19 -> V_21 ;
if ( V_81 < V_82 || V_81 >= V_83 )
continue;
switch ( V_19 -> V_26 ) {
case V_64 :
F_29 ( V_19 , L_10 ) ;
V_24 = V_19 -> V_24 ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_31 ( V_24 -> V_75 ,
( void * ) V_81 , V_26 ) ;
goto V_88;
default:
F_16 ( & V_19 -> V_14 ) ;
F_8 ( & V_19 -> V_14 , & V_42 ) ;
break;
}
}
F_9 ( & V_38 -> V_45 , V_9 ) ;
F_26 (obj, tmp, &freelist, node) {
F_16 ( & V_19 -> V_14 ) ;
F_20 ( V_19 ) ;
}
if ( V_20 > V_22 )
V_22 = V_20 ;
}
}
void F_46 ( const void * V_79 , unsigned long V_80 )
{
if ( V_2 )
F_45 ( V_79 , V_80 ) ;
}
static int F_47 ( struct V_89 * V_90 , void * V_91 )
{
F_48 ( V_90 , L_13 , V_22 ) ;
F_48 ( V_90 , L_14 , V_57 ) ;
F_48 ( V_90 , L_15 , V_59 ) ;
F_48 ( V_90 , L_16 , V_10 ) ;
F_48 ( V_90 , L_17 , V_32 ) ;
F_48 ( V_90 , L_18 , V_30 ) ;
F_48 ( V_90 , L_19 , V_31 ) ;
return 0 ;
}
static int F_49 ( struct V_92 * V_92 , struct V_93 * V_94 )
{
return F_50 ( V_94 , F_47 , NULL ) ;
}
static int T_1 F_51 ( void )
{
struct V_95 * V_96 , * V_97 ;
if ( ! V_2 )
return 0 ;
V_96 = F_52 ( L_20 , NULL ) ;
if ( ! V_96 )
return - V_98 ;
V_97 = F_53 ( L_21 , 0444 , V_96 , NULL ,
& V_99 ) ;
if ( ! V_97 )
goto V_100;
return 0 ;
V_100:
F_54 ( V_96 ) ;
return - V_98 ;
}
static inline void F_51 ( void ) { }
static bool T_1 V_72 ( void * V_16 )
{
struct V_101 * V_19 = V_16 ;
return V_19 -> V_102 ;
}
static bool T_1 V_65 ( void * V_16 , enum V_58 V_26 )
{
struct V_101 * V_19 = V_16 ;
switch ( V_26 ) {
case V_64 :
F_40 ( V_19 , & V_103 ) ;
F_37 ( V_19 , & V_103 ) ;
return true ;
default:
return false ;
}
}
static bool T_1 V_70 ( void * V_16 , enum V_58 V_26 )
{
struct V_101 * V_19 = V_16 ;
switch ( V_26 ) {
case V_69 :
return true ;
case V_64 :
F_40 ( V_19 , & V_103 ) ;
F_39 ( V_19 , & V_103 ) ;
return true ;
default:
return false ;
}
}
static bool T_1 V_74 ( void * V_16 , enum V_58 V_26 )
{
struct V_101 * V_19 = V_16 ;
switch ( V_26 ) {
case V_64 :
F_40 ( V_19 , & V_103 ) ;
F_41 ( V_19 , & V_103 ) ;
return true ;
default:
return false ;
}
}
static bool T_1 V_75 ( void * V_16 , enum V_58 V_26 )
{
struct V_101 * V_19 = V_16 ;
switch ( V_26 ) {
case V_64 :
F_40 ( V_19 , & V_103 ) ;
F_42 ( V_19 , & V_103 ) ;
return true ;
default:
return false ;
}
}
static int T_1
F_55 ( void * V_16 , enum V_58 V_26 , int V_104 , int V_105 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
int V_106 = - V_71 ;
V_38 = F_27 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_45 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 && V_26 != V_27 ) {
F_30 ( 1 , V_54 L_22 ) ;
goto V_107;
}
if ( V_19 && V_19 -> V_26 != V_26 ) {
F_30 ( 1 , V_54 L_23 ,
V_19 -> V_26 , V_26 ) ;
goto V_107;
}
if ( V_104 != V_59 ) {
F_30 ( 1 , V_54 L_24 ,
V_104 , V_59 ) ;
goto V_107;
}
if ( V_105 != V_57 ) {
F_30 ( 1 , V_54 L_25 ,
V_105 , V_57 ) ;
goto V_107;
}
V_106 = 0 ;
V_107:
F_9 ( & V_38 -> V_45 , V_9 ) ;
if ( V_106 )
V_2 = 0 ;
return V_106 ;
}
static void T_1 F_56 ( void )
{
int V_104 , V_108 , V_105 , V_109 ;
unsigned long V_9 ;
F_57 ( V_9 ) ;
V_104 = V_108 = V_59 ;
V_105 = V_109 = V_57 ;
V_51 = & V_103 ;
F_37 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_62 , V_104 , V_105 ) )
goto V_107;
F_39 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_64 , V_104 , V_105 ) )
goto V_107;
F_39 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_64 , ++ V_104 , ++ V_105 ) )
goto V_107;
F_40 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_63 , V_104 , V_105 ) )
goto V_107;
F_41 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_66 , V_104 , V_105 ) )
goto V_107;
F_37 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_66 , V_104 , ++ V_105 ) )
goto V_107;
F_39 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_66 , V_104 , ++ V_105 ) )
goto V_107;
F_40 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_66 , V_104 , ++ V_105 ) )
goto V_107;
F_42 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_27 , V_104 , V_105 ) )
goto V_107;
V_19 . V_102 = 1 ;
F_39 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_64 , V_104 , V_105 ) )
goto V_107;
F_37 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_62 , ++ V_104 , ++ V_105 ) )
goto V_107;
F_42 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_27 , V_104 , V_105 ) )
goto V_107;
#ifdef F_58
F_37 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_62 , V_104 , V_105 ) )
goto V_107;
F_39 ( & V_19 , & V_103 ) ;
if ( F_55 ( & V_19 , V_64 , V_104 , V_105 ) )
goto V_107;
F_45 ( & V_19 , sizeof( V_19 ) ) ;
if ( F_55 ( & V_19 , V_27 , ++ V_104 , ++ V_105 ) )
goto V_107;
#endif
F_59 ( L_26 ) ;
V_107:
V_59 = V_108 ;
V_57 = V_109 ;
V_51 = NULL ;
F_60 ( V_9 ) ;
}
static inline void F_56 ( void ) { }
void T_1 F_61 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ )
F_62 ( & V_39 [ V_43 ] . V_45 ) ;
for ( V_43 = 0 ; V_43 < V_35 ; V_43 ++ )
F_8 ( & V_110 [ V_43 ] . V_14 , & V_15 ) ;
}
static int T_1 F_63 ( void )
{
struct V_17 * V_38 = V_39 ;
struct V_40 * V_41 ;
struct V_7 * V_19 , * V_8 ;
F_23 ( V_111 ) ;
int V_43 , V_20 = 0 ;
for ( V_43 = 0 ; V_43 < V_35 ; V_43 ++ ) {
V_19 = F_6 ( V_12 , V_112 ) ;
if ( ! V_19 )
goto free;
F_8 ( & V_19 -> V_14 , & V_111 ) ;
}
F_64 () ;
F_26 (obj, tmp, &obj_pool, node)
F_16 ( & V_19 -> V_14 ) ;
F_25 ( & V_111 , & V_15 ) ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ , V_38 ++ ) {
F_25 ( & V_38 -> V_29 , & V_111 ) ;
F_11 (obj, &objects, node) {
V_8 = F_14 ( V_15 . V_25 , F_15 ( * V_19 ) , V_14 ) ;
F_16 ( & V_8 -> V_14 ) ;
* V_8 = * V_19 ;
F_8 ( & V_8 -> V_14 , & V_38 -> V_29 ) ;
V_20 ++ ;
}
}
F_65 () ;
F_66 ( L_27 ,
V_20 , V_30 ) ;
return 0 ;
free:
F_26 (obj, tmp, &objects, node) {
F_16 ( & V_19 -> V_14 ) ;
F_19 ( V_12 , V_19 ) ;
}
return - V_98 ;
}
void T_1 F_67 ( void )
{
if ( ! V_2 )
return;
V_12 = F_68 ( L_28 ,
sizeof ( struct V_7 ) , 0 ,
V_113 , NULL ) ;
if ( ! V_12 || F_63 () ) {
V_2 = 0 ;
if ( V_12 )
F_69 ( V_12 ) ;
F_24 ( L_29 ) ;
} else
F_56 () ;
}
