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
V_36 = F_21 () && ! F_22 ( & V_37 ) ;
F_8 ( & V_19 -> V_14 , & V_15 ) ;
V_10 ++ ;
V_30 -- ;
F_9 ( & V_13 , V_9 ) ;
if ( V_36 )
F_23 ( & V_37 ) ;
}
static void F_24 ( void )
{
struct V_17 * V_38 = V_39 ;
struct V_40 * V_41 ;
F_25 ( V_42 ) ;
struct V_7 * V_19 ;
unsigned long V_9 ;
int V_43 ;
F_26 ( V_44 L_1 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ , V_38 ++ ) {
F_7 ( & V_38 -> V_46 , V_9 ) ;
F_27 ( & V_38 -> V_29 , & V_42 ) ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_28 (obj, tmp, &freelist, node) {
F_16 ( & V_19 -> V_14 ) ;
F_20 ( V_19 ) ;
}
}
}
static struct V_17 * F_29 ( unsigned long V_16 )
{
unsigned long V_47 ;
V_47 = F_30 ( ( V_16 >> V_48 ) , V_49 ) ;
return & V_39 [ V_47 ] ;
}
static void F_31 ( struct V_7 * V_19 , char * V_50 )
{
struct V_23 * V_24 = V_19 -> V_24 ;
static int V_51 ;
if ( V_51 < 5 && V_24 != V_52 ) {
void * V_53 = V_24 -> V_54 ?
V_24 -> V_54 ( V_19 -> V_21 ) : NULL ;
V_51 ++ ;
F_32 ( 1 , V_55 L_2
L_3 ,
V_50 , V_56 [ V_19 -> V_26 ] , V_19 -> V_28 ,
V_24 -> V_57 , V_53 ) ;
}
V_58 ++ ;
}
static int
F_33 ( int (* F_34)( void * V_16 , enum V_59 V_26 ) ,
void * V_16 , enum V_59 V_26 )
{
int V_60 = 0 ;
if ( F_34 )
V_60 = F_34 ( V_16 , V_26 ) ;
V_61 += V_60 ;
return V_60 ;
}
static void F_35 ( void * V_16 , int V_62 )
{
int V_63 ;
static int V_51 ;
if ( V_51 > 4 )
return;
V_63 = F_36 ( V_16 ) ;
if ( V_63 == V_62 )
return;
V_51 ++ ;
if ( V_63 )
F_26 ( V_44
L_4 ) ;
else
F_26 ( V_44
L_5 ) ;
F_37 ( 1 ) ;
}
static void
F_38 ( void * V_16 , struct V_23 * V_24 , int V_62 )
{
enum V_59 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
F_3 () ;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 ) {
V_19 = F_12 ( V_16 , V_38 , V_24 ) ;
if ( ! V_19 ) {
V_2 = 0 ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_24 () ;
return;
}
F_35 ( V_16 , V_62 ) ;
}
switch ( V_19 -> V_26 ) {
case V_27 :
case V_64 :
case V_65 :
V_19 -> V_26 = V_64 ;
break;
case V_66 :
F_31 ( V_19 , L_6 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_33 ( V_24 -> V_67 , V_16 , V_26 ) ;
return;
case V_68 :
F_31 ( V_19 , L_6 ) ;
break;
default:
break;
}
F_9 ( & V_38 -> V_46 , V_9 ) ;
}
void F_39 ( void * V_16 , struct V_23 * V_24 )
{
if ( ! V_2 )
return;
F_38 ( V_16 , V_24 , 0 ) ;
}
void F_40 ( void * V_16 , struct V_23 * V_24 )
{
if ( ! V_2 )
return;
F_38 ( V_16 , V_24 , 1 ) ;
}
void F_41 ( void * V_16 , struct V_23 * V_24 )
{
enum V_59 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
struct V_7 V_69 = { . V_21 = V_16 ,
. V_26 = V_70 ,
. V_24 = V_24 } ;
if ( ! V_2 )
return;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( V_19 ) {
switch ( V_19 -> V_26 ) {
case V_64 :
case V_65 :
V_19 -> V_26 = V_66 ;
break;
case V_66 :
F_31 ( V_19 , L_7 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_33 ( V_24 -> V_71 , V_16 , V_26 ) ;
return;
case V_68 :
F_31 ( V_19 , L_7 ) ;
break;
default:
break;
}
F_9 ( & V_38 -> V_46 , V_9 ) ;
return;
}
F_9 ( & V_38 -> V_46 , V_9 ) ;
if ( F_33 ( V_24 -> V_71 , V_16 ,
V_70 ) )
F_31 ( & V_69 , L_7 ) ;
}
void F_42 ( void * V_16 , struct V_23 * V_24 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( V_19 ) {
switch ( V_19 -> V_26 ) {
case V_64 :
case V_65 :
case V_66 :
if ( ! V_19 -> V_28 )
V_19 -> V_26 = V_65 ;
else
F_31 ( V_19 , L_8 ) ;
break;
case V_68 :
F_31 ( V_19 , L_8 ) ;
break;
default:
break;
}
} else {
struct V_7 V_69 = { . V_21 = V_16 ,
. V_26 = V_70 ,
. V_24 = V_24 } ;
F_31 ( & V_69 , L_8 ) ;
}
F_9 ( & V_38 -> V_46 , V_9 ) ;
}
void F_43 ( void * V_16 , struct V_23 * V_24 )
{
enum V_59 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 )
goto V_72;
switch ( V_19 -> V_26 ) {
case V_27 :
case V_64 :
case V_65 :
V_19 -> V_26 = V_68 ;
break;
case V_66 :
F_31 ( V_19 , L_9 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_33 ( V_24 -> V_73 , V_16 , V_26 ) ;
return;
case V_68 :
F_31 ( V_19 , L_9 ) ;
break;
default:
break;
}
V_72:
F_9 ( & V_38 -> V_46 , V_9 ) ;
}
void F_44 ( void * V_16 , struct V_23 * V_24 )
{
enum V_59 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 )
goto V_72;
switch ( V_19 -> V_26 ) {
case V_66 :
F_31 ( V_19 , L_10 ) ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_33 ( V_24 -> V_74 , V_16 , V_26 ) ;
return;
default:
F_16 ( & V_19 -> V_14 ) ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_20 ( V_19 ) ;
return;
}
V_72:
F_9 ( & V_38 -> V_46 , V_9 ) ;
}
void F_45 ( void * V_16 , struct V_23 * V_24 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 ) {
struct V_7 V_69 = { . V_21 = V_16 ,
. V_26 = V_70 ,
. V_24 = V_24 } ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
if ( F_33 ( V_24 -> V_75 , V_16 ,
V_70 ) )
F_31 ( & V_69 , L_11 ) ;
return;
}
F_9 ( & V_38 -> V_46 , V_9 ) ;
}
void
F_46 ( void * V_16 , struct V_23 * V_24 ,
unsigned int V_76 , unsigned int V_77 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
if ( ! V_2 )
return;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( V_19 ) {
switch ( V_19 -> V_26 ) {
case V_66 :
if ( V_19 -> V_28 == V_76 )
V_19 -> V_28 = V_77 ;
else
F_31 ( V_19 , L_12 ) ;
break;
default:
F_31 ( V_19 , L_12 ) ;
break;
}
} else {
struct V_7 V_69 = { . V_21 = V_16 ,
. V_26 = V_70 ,
. V_24 = V_24 } ;
F_31 ( & V_69 , L_12 ) ;
}
F_9 ( & V_38 -> V_46 , V_9 ) ;
}
static void F_47 ( const void * V_78 , unsigned long V_79 )
{
unsigned long V_9 , V_80 , V_81 , V_82 , V_83 , V_84 ;
struct V_40 * V_41 ;
F_25 ( V_42 ) ;
struct V_23 * V_24 ;
enum V_59 V_26 ;
struct V_17 * V_38 ;
struct V_7 * V_19 ;
int V_20 ;
V_81 = ( unsigned long ) V_78 ;
V_82 = V_81 + V_79 ;
V_83 = V_81 & V_85 ;
V_84 = ( ( V_82 - V_83 ) + ( V_86 - 1 ) ) ;
V_84 >>= V_48 ;
for (; V_84 > 0 ; V_84 -- , V_83 += V_86 ) {
V_38 = F_29 ( V_83 ) ;
V_87:
V_20 = 0 ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
F_28 (obj, tmp, &db->list, node) {
V_20 ++ ;
V_80 = ( unsigned long ) V_19 -> V_21 ;
if ( V_80 < V_81 || V_80 >= V_82 )
continue;
switch ( V_19 -> V_26 ) {
case V_66 :
F_31 ( V_19 , L_10 ) ;
V_24 = V_19 -> V_24 ;
V_26 = V_19 -> V_26 ;
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_33 ( V_24 -> V_74 ,
( void * ) V_80 , V_26 ) ;
goto V_87;
default:
F_16 ( & V_19 -> V_14 ) ;
F_8 ( & V_19 -> V_14 , & V_42 ) ;
break;
}
}
F_9 ( & V_38 -> V_46 , V_9 ) ;
F_28 (obj, tmp, &freelist, node) {
F_16 ( & V_19 -> V_14 ) ;
F_20 ( V_19 ) ;
}
if ( V_20 > V_22 )
V_22 = V_20 ;
}
}
void F_48 ( const void * V_78 , unsigned long V_79 )
{
if ( V_2 )
F_47 ( V_78 , V_79 ) ;
}
static int F_49 ( struct V_88 * V_89 , void * V_90 )
{
F_50 ( V_89 , L_13 , V_22 ) ;
F_50 ( V_89 , L_14 , V_58 ) ;
F_50 ( V_89 , L_15 , V_61 ) ;
F_50 ( V_89 , L_16 , V_10 ) ;
F_50 ( V_89 , L_17 , V_32 ) ;
F_50 ( V_89 , L_18 , V_30 ) ;
F_50 ( V_89 , L_19 , V_31 ) ;
return 0 ;
}
static int F_51 ( struct V_91 * V_91 , struct V_92 * V_93 )
{
return F_52 ( V_93 , F_49 , NULL ) ;
}
static int T_1 F_53 ( void )
{
struct V_94 * V_95 , * V_96 ;
if ( ! V_2 )
return 0 ;
V_95 = F_54 ( L_20 , NULL ) ;
if ( ! V_95 )
return - V_97 ;
V_96 = F_55 ( L_21 , 0444 , V_95 , NULL ,
& V_98 ) ;
if ( ! V_96 )
goto V_99;
return 0 ;
V_99:
F_56 ( V_95 ) ;
return - V_97 ;
}
static inline void F_53 ( void ) { }
static int T_1 V_67 ( void * V_16 , enum V_59 V_26 )
{
struct V_100 * V_19 = V_16 ;
switch ( V_26 ) {
case V_66 :
F_42 ( V_19 , & V_101 ) ;
F_39 ( V_19 , & V_101 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1 V_71 ( void * V_16 , enum V_59 V_26 )
{
struct V_100 * V_19 = V_16 ;
switch ( V_26 ) {
case V_70 :
if ( V_19 -> V_102 == 1 ) {
F_39 ( V_19 , & V_101 ) ;
F_41 ( V_19 , & V_101 ) ;
return 0 ;
}
return 1 ;
case V_66 :
F_42 ( V_19 , & V_101 ) ;
F_41 ( V_19 , & V_101 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1 V_73 ( void * V_16 , enum V_59 V_26 )
{
struct V_100 * V_19 = V_16 ;
switch ( V_26 ) {
case V_66 :
F_42 ( V_19 , & V_101 ) ;
F_43 ( V_19 , & V_101 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1 V_74 ( void * V_16 , enum V_59 V_26 )
{
struct V_100 * V_19 = V_16 ;
switch ( V_26 ) {
case V_66 :
F_42 ( V_19 , & V_101 ) ;
F_44 ( V_19 , & V_101 ) ;
return 1 ;
default:
return 0 ;
}
}
static int T_1
F_57 ( void * V_16 , enum V_59 V_26 , int V_103 , int V_104 )
{
struct V_17 * V_38 ;
struct V_7 * V_19 ;
unsigned long V_9 ;
int V_105 = - V_106 ;
V_38 = F_29 ( ( unsigned long ) V_16 ) ;
F_7 ( & V_38 -> V_46 , V_9 ) ;
V_19 = F_10 ( V_16 , V_38 ) ;
if ( ! V_19 && V_26 != V_27 ) {
F_32 ( 1 , V_55 L_22 ) ;
goto V_107;
}
if ( V_19 && V_19 -> V_26 != V_26 ) {
F_32 ( 1 , V_55 L_23 ,
V_19 -> V_26 , V_26 ) ;
goto V_107;
}
if ( V_103 != V_61 ) {
F_32 ( 1 , V_55 L_24 ,
V_103 , V_61 ) ;
goto V_107;
}
if ( V_104 != V_58 ) {
F_32 ( 1 , V_55 L_25 ,
V_104 , V_58 ) ;
goto V_107;
}
V_105 = 0 ;
V_107:
F_9 ( & V_38 -> V_46 , V_9 ) ;
if ( V_105 )
V_2 = 0 ;
return V_105 ;
}
static void T_1 F_58 ( void )
{
int V_103 , V_108 , V_104 , V_109 ;
unsigned long V_9 ;
F_59 ( V_9 ) ;
V_103 = V_108 = V_61 ;
V_104 = V_109 = V_58 ;
V_52 = & V_101 ;
F_39 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_64 , V_103 , V_104 ) )
goto V_107;
F_41 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_66 , V_103 , V_104 ) )
goto V_107;
F_41 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_66 , ++ V_103 , ++ V_104 ) )
goto V_107;
F_42 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_65 , V_103 , V_104 ) )
goto V_107;
F_43 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_68 , V_103 , V_104 ) )
goto V_107;
F_39 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_68 , V_103 , ++ V_104 ) )
goto V_107;
F_41 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_68 , V_103 , ++ V_104 ) )
goto V_107;
F_42 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_68 , V_103 , ++ V_104 ) )
goto V_107;
F_44 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_27 , V_103 , V_104 ) )
goto V_107;
V_19 . V_102 = 1 ;
F_41 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_66 , V_103 , V_104 ) )
goto V_107;
F_39 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_64 , ++ V_103 , ++ V_104 ) )
goto V_107;
F_44 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_27 , V_103 , V_104 ) )
goto V_107;
#ifdef F_60
F_39 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_64 , V_103 , V_104 ) )
goto V_107;
F_41 ( & V_19 , & V_101 ) ;
if ( F_57 ( & V_19 , V_66 , V_103 , V_104 ) )
goto V_107;
F_47 ( & V_19 , sizeof( V_19 ) ) ;
if ( F_57 ( & V_19 , V_27 , ++ V_103 , ++ V_104 ) )
goto V_107;
#endif
F_26 ( V_110 L_26 ) ;
V_107:
V_61 = V_108 ;
V_58 = V_109 ;
V_52 = NULL ;
F_61 ( V_9 ) ;
}
static inline void F_58 ( void ) { }
void T_1 F_62 ( void )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
F_63 ( & V_39 [ V_43 ] . V_46 ) ;
for ( V_43 = 0 ; V_43 < V_35 ; V_43 ++ )
F_8 ( & V_111 [ V_43 ] . V_14 , & V_15 ) ;
}
static int T_1 F_64 ( void )
{
struct V_17 * V_38 = V_39 ;
struct V_40 * V_41 ;
struct V_7 * V_19 , * V_8 ;
F_25 ( V_112 ) ;
int V_43 , V_20 = 0 ;
for ( V_43 = 0 ; V_43 < V_35 ; V_43 ++ ) {
V_19 = F_6 ( V_12 , V_113 ) ;
if ( ! V_19 )
goto free;
F_8 ( & V_19 -> V_14 , & V_112 ) ;
}
F_65 () ;
F_28 (obj, tmp, &obj_pool, node)
F_16 ( & V_19 -> V_14 ) ;
F_27 ( & V_112 , & V_15 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ , V_38 ++ ) {
F_27 ( & V_38 -> V_29 , & V_112 ) ;
F_11 (obj, &objects, node) {
V_8 = F_14 ( V_15 . V_25 , F_15 ( * V_19 ) , V_14 ) ;
F_16 ( & V_8 -> V_14 ) ;
* V_8 = * V_19 ;
F_8 ( & V_8 -> V_14 , & V_38 -> V_29 ) ;
V_20 ++ ;
}
}
F_66 () ;
F_26 ( V_114 L_27 , V_20 ,
V_30 ) ;
return 0 ;
free:
F_28 (obj, tmp, &objects, node) {
F_16 ( & V_19 -> V_14 ) ;
F_19 ( V_12 , V_19 ) ;
}
return - V_97 ;
}
void T_1 F_67 ( void )
{
if ( ! V_2 )
return;
V_12 = F_68 ( L_28 ,
sizeof ( struct V_7 ) , 0 ,
V_115 , NULL ) ;
if ( ! V_12 || F_64 () ) {
V_2 = 0 ;
if ( V_12 )
F_69 ( V_12 ) ;
F_26 ( V_44 L_29 ) ;
} else
F_58 () ;
}
