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
static int F_3 ( void )
{
T_2 V_3 = V_4 | V_5 | V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
if ( F_4 ( V_10 >= V_11 ) )
return V_10 ;
if ( F_5 ( ! V_12 ) )
return V_10 ;
while ( V_10 < V_11 ) {
V_8 = F_6 ( V_12 , V_3 ) ;
if ( ! V_8 )
return V_10 ;
F_7 ( & V_13 , V_9 ) ;
F_8 ( & V_8 -> V_14 , & V_15 ) ;
V_10 ++ ;
F_9 ( & V_13 , V_9 ) ;
}
return V_10 ;
}
static struct V_7 * F_10 ( void * V_16 , struct V_17 * V_18 )
{
struct V_19 * V_14 ;
struct V_7 * V_20 ;
int V_21 = 0 ;
F_11 (obj, node, &b->list, node) {
V_21 ++ ;
if ( V_20 -> V_22 == V_16 )
return V_20 ;
}
if ( V_21 > V_23 )
V_23 = V_21 ;
return NULL ;
}
static struct V_7 *
F_12 ( void * V_16 , struct V_17 * V_18 , struct V_24 * V_25 )
{
struct V_7 * V_20 = NULL ;
F_13 ( & V_13 ) ;
if ( V_15 . V_26 ) {
V_20 = F_14 ( V_15 . V_26 , F_15 ( * V_20 ) , V_14 ) ;
V_20 -> V_22 = V_16 ;
V_20 -> V_25 = V_25 ;
V_20 -> V_27 = V_28 ;
V_20 -> V_29 = 0 ;
F_16 ( & V_20 -> V_14 ) ;
F_8 ( & V_20 -> V_14 , & V_18 -> V_30 ) ;
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
struct V_7 * V_20 ;
unsigned long V_9 ;
F_7 ( & V_13 , V_9 ) ;
while ( V_10 > V_36 ) {
V_20 = F_14 ( V_15 . V_26 , F_15 ( * V_20 ) , V_14 ) ;
F_16 ( & V_20 -> V_14 ) ;
V_10 -- ;
F_9 ( & V_13 , V_9 ) ;
F_19 ( V_12 , V_20 ) ;
F_7 ( & V_13 , V_9 ) ;
}
F_9 ( & V_13 , V_9 ) ;
}
static void F_20 ( struct V_7 * V_20 )
{
unsigned long V_9 ;
int V_37 = 0 ;
F_7 ( & V_13 , V_9 ) ;
if ( V_10 > V_36 && V_12 )
V_37 = F_21 () && ! F_22 ( & V_38 ) ;
F_8 ( & V_20 -> V_14 , & V_15 ) ;
V_10 ++ ;
V_31 -- ;
F_9 ( & V_13 , V_9 ) ;
if ( V_37 )
F_23 ( & V_38 ) ;
}
static void F_24 ( void )
{
struct V_17 * V_39 = V_40 ;
struct V_19 * V_14 , * V_41 ;
F_25 ( V_42 ) ;
struct V_7 * V_20 ;
unsigned long V_9 ;
int V_43 ;
F_26 ( V_44 L_1 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ , V_39 ++ ) {
F_7 ( & V_39 -> V_46 , V_9 ) ;
F_27 ( & V_39 -> V_30 , & V_42 ) ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_28 (obj, node, tmp, &freelist, node) {
F_16 ( & V_20 -> V_14 ) ;
F_20 ( V_20 ) ;
}
}
}
static struct V_17 * F_29 ( unsigned long V_16 )
{
unsigned long V_47 ;
V_47 = F_30 ( ( V_16 >> V_48 ) , V_49 ) ;
return & V_40 [ V_47 ] ;
}
static void F_31 ( struct V_7 * V_20 , char * V_50 )
{
struct V_24 * V_25 = V_20 -> V_25 ;
static int V_51 ;
if ( V_51 < 5 && V_25 != V_52 ) {
void * V_53 = V_25 -> V_54 ?
V_25 -> V_54 ( V_20 -> V_22 ) : NULL ;
V_51 ++ ;
F_32 ( 1 , V_55 L_2
L_3 ,
V_50 , V_56 [ V_20 -> V_27 ] , V_20 -> V_29 ,
V_25 -> V_57 , V_53 ) ;
}
V_58 ++ ;
}
static void
F_33 ( int (* F_34)( void * V_16 , enum V_59 V_27 ) ,
void * V_16 , enum V_59 V_27 )
{
if ( F_34 )
V_60 += F_34 ( V_16 , V_27 ) ;
}
static void F_35 ( void * V_16 , int V_61 )
{
int V_62 ;
static int V_51 ;
if ( V_51 > 4 )
return;
V_62 = F_36 ( V_16 ) ;
if ( V_62 == V_61 )
return;
V_51 ++ ;
if ( V_62 )
F_26 ( V_44
L_4 ) ;
else
F_26 ( V_44
L_5 ) ;
F_37 ( 1 ) ;
}
static void
F_38 ( void * V_16 , struct V_24 * V_25 , int V_61 )
{
enum V_59 V_27 ;
struct V_17 * V_39 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
F_3 () ;
V_39 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
V_20 = F_10 ( V_16 , V_39 ) ;
if ( ! V_20 ) {
V_20 = F_12 ( V_16 , V_39 , V_25 ) ;
if ( ! V_20 ) {
V_2 = 0 ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_24 () ;
return;
}
F_35 ( V_16 , V_61 ) ;
}
switch ( V_20 -> V_27 ) {
case V_28 :
case V_63 :
case V_64 :
V_20 -> V_27 = V_63 ;
break;
case V_65 :
F_31 ( V_20 , L_6 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_33 ( V_25 -> V_66 , V_16 , V_27 ) ;
return;
case V_67 :
F_31 ( V_20 , L_6 ) ;
break;
default:
break;
}
F_9 ( & V_39 -> V_46 , V_9 ) ;
}
void F_39 ( void * V_16 , struct V_24 * V_25 )
{
if ( ! V_2 )
return;
F_38 ( V_16 , V_25 , 0 ) ;
}
void F_40 ( void * V_16 , struct V_24 * V_25 )
{
if ( ! V_2 )
return;
F_38 ( V_16 , V_25 , 1 ) ;
}
void F_41 ( void * V_16 , struct V_24 * V_25 )
{
enum V_59 V_27 ;
struct V_17 * V_39 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_39 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
V_20 = F_10 ( V_16 , V_39 ) ;
if ( V_20 ) {
switch ( V_20 -> V_27 ) {
case V_63 :
case V_64 :
V_20 -> V_27 = V_65 ;
break;
case V_65 :
F_31 ( V_20 , L_7 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_33 ( V_25 -> V_68 , V_16 , V_27 ) ;
return;
case V_67 :
F_31 ( V_20 , L_7 ) ;
break;
default:
break;
}
F_9 ( & V_39 -> V_46 , V_9 ) ;
return;
}
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_33 ( V_25 -> V_68 , V_16 ,
V_69 ) ;
}
void F_42 ( void * V_16 , struct V_24 * V_25 )
{
struct V_17 * V_39 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_39 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
V_20 = F_10 ( V_16 , V_39 ) ;
if ( V_20 ) {
switch ( V_20 -> V_27 ) {
case V_63 :
case V_64 :
case V_65 :
if ( ! V_20 -> V_29 )
V_20 -> V_27 = V_64 ;
else
F_31 ( V_20 , L_8 ) ;
break;
case V_67 :
F_31 ( V_20 , L_8 ) ;
break;
default:
break;
}
} else {
struct V_7 V_70 = { . V_22 = V_16 ,
. V_27 = V_69 ,
. V_25 = V_25 } ;
F_31 ( & V_70 , L_8 ) ;
}
F_9 ( & V_39 -> V_46 , V_9 ) ;
}
void F_43 ( void * V_16 , struct V_24 * V_25 )
{
enum V_59 V_27 ;
struct V_17 * V_39 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_39 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
V_20 = F_10 ( V_16 , V_39 ) ;
if ( ! V_20 )
goto V_71;
switch ( V_20 -> V_27 ) {
case V_28 :
case V_63 :
case V_64 :
V_20 -> V_27 = V_67 ;
break;
case V_65 :
F_31 ( V_20 , L_9 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_33 ( V_25 -> V_72 , V_16 , V_27 ) ;
return;
case V_67 :
F_31 ( V_20 , L_9 ) ;
break;
default:
break;
}
V_71:
F_9 ( & V_39 -> V_46 , V_9 ) ;
}
void F_44 ( void * V_16 , struct V_24 * V_25 )
{
enum V_59 V_27 ;
struct V_17 * V_39 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_39 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
V_20 = F_10 ( V_16 , V_39 ) ;
if ( ! V_20 )
goto V_71;
switch ( V_20 -> V_27 ) {
case V_65 :
F_31 ( V_20 , L_10 ) ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_33 ( V_25 -> V_73 , V_16 , V_27 ) ;
return;
default:
F_16 ( & V_20 -> V_14 ) ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_20 ( V_20 ) ;
return;
}
V_71:
F_9 ( & V_39 -> V_46 , V_9 ) ;
}
void
F_45 ( void * V_16 , struct V_24 * V_25 ,
unsigned int V_74 , unsigned int V_75 )
{
struct V_17 * V_39 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_39 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
V_20 = F_10 ( V_16 , V_39 ) ;
if ( V_20 ) {
switch ( V_20 -> V_27 ) {
case V_65 :
if ( V_20 -> V_29 == V_74 )
V_20 -> V_29 = V_75 ;
else
F_31 ( V_20 , L_11 ) ;
break;
default:
F_31 ( V_20 , L_11 ) ;
break;
}
} else {
struct V_7 V_70 = { . V_22 = V_16 ,
. V_27 = V_69 ,
. V_25 = V_25 } ;
F_31 ( & V_70 , L_11 ) ;
}
F_9 ( & V_39 -> V_46 , V_9 ) ;
}
static void F_46 ( const void * V_76 , unsigned long V_77 )
{
unsigned long V_9 , V_78 , V_79 , V_80 , V_81 , V_82 ;
struct V_19 * V_14 , * V_41 ;
F_25 ( V_42 ) ;
struct V_24 * V_25 ;
enum V_59 V_27 ;
struct V_17 * V_39 ;
struct V_7 * V_20 ;
int V_21 ;
V_79 = ( unsigned long ) V_76 ;
V_80 = V_79 + V_77 ;
V_81 = V_79 & V_83 ;
V_82 = ( ( V_80 - V_81 ) + ( V_84 - 1 ) ) ;
V_82 >>= V_48 ;
for (; V_82 > 0 ; V_82 -- , V_81 += V_84 ) {
V_39 = F_29 ( V_81 ) ;
V_85:
V_21 = 0 ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
F_28 (obj, node, tmp, &db->list, node) {
V_21 ++ ;
V_78 = ( unsigned long ) V_20 -> V_22 ;
if ( V_78 < V_79 || V_78 >= V_80 )
continue;
switch ( V_20 -> V_27 ) {
case V_65 :
F_31 ( V_20 , L_10 ) ;
V_25 = V_20 -> V_25 ;
V_27 = V_20 -> V_27 ;
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_33 ( V_25 -> V_73 ,
( void * ) V_78 , V_27 ) ;
goto V_85;
default:
F_16 ( & V_20 -> V_14 ) ;
F_8 ( & V_20 -> V_14 , & V_42 ) ;
break;
}
}
F_9 ( & V_39 -> V_46 , V_9 ) ;
F_28 (obj, node, tmp, &freelist, node) {
F_16 ( & V_20 -> V_14 ) ;
F_20 ( V_20 ) ;
}
if ( V_21 > V_23 )
V_23 = V_21 ;
}
}
void F_47 ( const void * V_76 , unsigned long V_77 )
{
if ( V_2 )
F_46 ( V_76 , V_77 ) ;
}
static int F_48 ( struct V_86 * V_87 , void * V_88 )
{
F_49 ( V_87 , L_12 , V_23 ) ;
F_49 ( V_87 , L_13 , V_58 ) ;
F_49 ( V_87 , L_14 , V_60 ) ;
F_49 ( V_87 , L_15 , V_10 ) ;
F_49 ( V_87 , L_16 , V_33 ) ;
F_49 ( V_87 , L_17 , V_31 ) ;
F_49 ( V_87 , L_18 , V_32 ) ;
return 0 ;
}
static int F_50 ( struct V_89 * V_89 , struct V_90 * V_91 )
{
return F_51 ( V_91 , F_48 , NULL ) ;
}
static int T_1 F_52 ( void )
{
struct V_92 * V_93 , * V_94 ;
if ( ! V_2 )
return 0 ;
V_93 = F_53 ( L_19 , NULL ) ;
if ( ! V_93 )
return - V_95 ;
V_94 = F_54 ( L_20 , 0444 , V_93 , NULL ,
& V_96 ) ;
if ( ! V_94 )
goto V_97;
return 0 ;
V_97:
F_55 ( V_93 ) ;
return - V_95 ;
}
static inline void F_52 ( void ) { }
static int T_1 V_66 ( void * V_16 , enum V_59 V_27 )
{
struct V_98 * V_20 = V_16 ;
switch ( V_27 ) {
case V_65 :
F_42 ( V_20 , & V_99 ) ;
F_39 ( V_20 , & V_99 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1 V_68 ( void * V_16 , enum V_59 V_27 )
{
struct V_98 * V_20 = V_16 ;
switch ( V_27 ) {
case V_69 :
if ( V_20 -> V_100 == 1 ) {
F_39 ( V_20 , & V_99 ) ;
F_41 ( V_20 , & V_99 ) ;
return 1 ;
} else {
}
return 0 ;
case V_65 :
F_42 ( V_20 , & V_99 ) ;
F_41 ( V_20 , & V_99 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1 V_72 ( void * V_16 , enum V_59 V_27 )
{
struct V_98 * V_20 = V_16 ;
switch ( V_27 ) {
case V_65 :
F_42 ( V_20 , & V_99 ) ;
F_43 ( V_20 , & V_99 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1 V_73 ( void * V_16 , enum V_59 V_27 )
{
struct V_98 * V_20 = V_16 ;
switch ( V_27 ) {
case V_65 :
F_42 ( V_20 , & V_99 ) ;
F_44 ( V_20 , & V_99 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1
F_56 ( void * V_16 , enum V_59 V_27 , int V_101 , int V_102 )
{
struct V_17 * V_39 ;
struct V_7 * V_20 ;
unsigned long V_9 ;
int V_103 = - V_104 ;
V_39 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_39 -> V_46 , V_9 ) ;
V_20 = F_10 ( V_16 , V_39 ) ;
if ( ! V_20 && V_27 != V_28 ) {
F_32 ( 1 , V_55 L_21 ) ;
goto V_105;
}
if ( V_20 && V_20 -> V_27 != V_27 ) {
F_32 ( 1 , V_55 L_22 ,
V_20 -> V_27 , V_27 ) ;
goto V_105;
}
if ( V_101 != V_60 ) {
F_32 ( 1 , V_55 L_23 ,
V_101 , V_60 ) ;
goto V_105;
}
if ( V_102 != V_58 ) {
F_32 ( 1 , V_55 L_24 ,
V_102 , V_58 ) ;
goto V_105;
}
V_103 = 0 ;
V_105:
F_9 ( & V_39 -> V_46 , V_9 ) ;
if ( V_103 )
V_2 = 0 ;
return V_103 ;
}
static void T_1 F_57 ( void )
{
int V_101 , V_106 , V_102 , V_107 ;
unsigned long V_9 ;
F_58 ( V_9 ) ;
V_101 = V_106 = V_60 ;
V_102 = V_107 = V_58 ;
V_52 = & V_99 ;
F_39 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_63 , V_101 , V_102 ) )
goto V_105;
F_41 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_65 , V_101 , V_102 ) )
goto V_105;
F_41 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_65 , ++ V_101 , ++ V_102 ) )
goto V_105;
F_42 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_64 , V_101 , V_102 ) )
goto V_105;
F_43 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_67 , V_101 , V_102 ) )
goto V_105;
F_39 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_67 , V_101 , ++ V_102 ) )
goto V_105;
F_41 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_67 , V_101 , ++ V_102 ) )
goto V_105;
F_42 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_67 , V_101 , ++ V_102 ) )
goto V_105;
F_44 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_28 , V_101 , V_102 ) )
goto V_105;
V_20 . V_100 = 1 ;
F_41 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_65 , ++ V_101 , V_102 ) )
goto V_105;
F_39 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_63 , ++ V_101 , ++ V_102 ) )
goto V_105;
F_44 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_28 , V_101 , V_102 ) )
goto V_105;
#ifdef F_59
F_39 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_63 , V_101 , V_102 ) )
goto V_105;
F_41 ( & V_20 , & V_99 ) ;
if ( F_56 ( & V_20 , V_65 , V_101 , V_102 ) )
goto V_105;
F_46 ( & V_20 , sizeof( V_20 ) ) ;
if ( F_56 ( & V_20 , V_28 , ++ V_101 , ++ V_102 ) )
goto V_105;
#endif
F_26 ( V_108 L_25 ) ;
V_105:
V_60 = V_106 ;
V_58 = V_107 ;
V_52 = NULL ;
F_60 ( V_9 ) ;
}
static inline void F_57 ( void ) { }
void T_1 F_61 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
F_62 ( & V_40 [ V_43 ] . V_46 ) ;
for ( V_43 = 0 ; V_43 < V_36 ; V_43 ++ )
F_8 ( & V_109 [ V_43 ] . V_14 , & V_15 ) ;
}
static int T_1 F_63 ( void )
{
struct V_17 * V_39 = V_40 ;
struct V_19 * V_14 , * V_41 ;
struct V_7 * V_20 , * V_8 ;
F_25 ( V_110 ) ;
int V_43 , V_21 = 0 ;
for ( V_43 = 0 ; V_43 < V_36 ; V_43 ++ ) {
V_20 = F_6 ( V_12 , V_111 ) ;
if ( ! V_20 )
goto free;
F_8 ( & V_20 -> V_14 , & V_110 ) ;
}
F_64 () ;
F_28 (obj, node, tmp, &obj_pool, node)
F_16 ( & V_20 -> V_14 ) ;
F_27 ( & V_110 , & V_15 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ , V_39 ++ ) {
F_27 ( & V_39 -> V_30 , & V_110 ) ;
F_11 (obj, node, &objects, node) {
V_8 = F_14 ( V_15 . V_26 , F_15 ( * V_20 ) , V_14 ) ;
F_16 ( & V_8 -> V_14 ) ;
* V_8 = * V_20 ;
F_8 ( & V_8 -> V_14 , & V_39 -> V_30 ) ;
V_21 ++ ;
}
}
F_26 ( V_112 L_26 , V_21 ,
V_31 ) ;
F_65 () ;
return 0 ;
free:
F_28 (obj, node, tmp, &objects, node) {
F_16 ( & V_20 -> V_14 ) ;
F_19 ( V_12 , V_20 ) ;
}
return - V_95 ;
}
void T_1 F_66 ( void )
{
if ( ! V_2 )
return;
V_12 = F_67 ( L_27 ,
sizeof ( struct V_7 ) , 0 ,
V_113 , NULL ) ;
if ( ! V_12 || F_63 () ) {
V_2 = 0 ;
if ( V_12 )
F_68 ( V_12 ) ;
F_26 ( V_44 L_28 ) ;
} else
F_57 () ;
}
