int
F_1 ( unsigned long V_1 , unsigned long V_2 , int * V_3 ,
unsigned long V_4 )
{
unsigned long long V_5 ;
int V_6 ;
if ( ! V_7 -> V_8 )
return - V_9 ;
F_2 () ;
if ( V_7 -> V_10 == V_11 - 1 ) {
F_3 ( & V_7 -> V_12 ) ;
return - V_9 ;
}
V_5 = F_4 () ;
V_6 = ++ V_7 -> V_10 ;
F_5 () ;
V_7 -> V_8 [ V_6 ] . V_1 = V_1 ;
V_7 -> V_8 [ V_6 ] . V_2 = V_2 ;
V_7 -> V_8 [ V_6 ] . V_5 = V_5 ;
V_7 -> V_8 [ V_6 ] . V_13 = 0 ;
V_7 -> V_8 [ V_6 ] . V_14 = V_4 ;
* V_3 = V_6 ;
return 0 ;
}
static void
F_6 ( struct V_15 * V_16 , unsigned long * V_1 ,
unsigned long V_4 )
{
int V_6 ;
V_6 = V_7 -> V_10 ;
if ( F_7 ( V_6 < 0 ) ) {
F_8 () ;
F_9 ( 1 ) ;
* V_1 = ( unsigned long ) V_17 ;
return;
}
#ifdef F_10
if ( F_7 ( V_7 -> V_8 [ V_6 ] . V_14 != V_4 ) ) {
F_8 () ;
F_11 ( 1 , L_1
L_2 ,
V_7 -> V_8 [ V_6 ] . V_14 ,
V_4 ,
( void * ) V_7 -> V_8 [ V_6 ] . V_2 ,
V_7 -> V_8 [ V_6 ] . V_1 ) ;
* V_1 = ( unsigned long ) V_17 ;
return;
}
#endif
* V_1 = V_7 -> V_8 [ V_6 ] . V_1 ;
V_16 -> V_2 = V_7 -> V_8 [ V_6 ] . V_2 ;
V_16 -> V_5 = V_7 -> V_8 [ V_6 ] . V_5 ;
V_16 -> V_18 = F_12 ( & V_7 -> V_12 ) ;
V_16 -> V_3 = V_6 ;
}
unsigned long F_13 ( unsigned long V_4 )
{
struct V_15 V_16 ;
unsigned long V_1 ;
F_6 ( & V_16 , & V_1 , V_4 ) ;
V_16 . V_19 = F_4 () ;
F_14 ( & V_16 ) ;
F_5 () ;
V_7 -> V_10 -- ;
if ( F_7 ( ! V_1 ) ) {
F_8 () ;
F_9 ( 1 ) ;
V_1 = ( unsigned long ) V_17 ;
}
return V_1 ;
}
int F_15 ( struct V_20 * V_21 ,
struct V_22 * V_16 ,
unsigned long V_23 ,
int V_24 )
{
struct V_25 * V_26 = & V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 = V_21 -> V_31 ;
struct V_32 * V_33 ;
if ( F_7 ( F_16 ( V_34 ) ) )
return 0 ;
V_29 = F_17 ( V_31 , V_35 ,
sizeof( * V_33 ) , V_23 , V_24 ) ;
if ( ! V_29 )
return 0 ;
V_33 = F_18 ( V_29 ) ;
V_33 -> V_36 = * V_16 ;
if ( ! F_19 ( V_31 , V_26 , V_33 , V_29 ) )
F_20 ( V_31 , V_29 ) ;
return 1 ;
}
static inline int F_21 ( void )
{
if ( ! V_37 )
return 0 ;
return F_22 () ;
}
int F_23 ( struct V_22 * V_16 )
{
struct V_20 * V_21 = V_38 ;
struct V_39 * V_40 ;
unsigned long V_23 ;
long V_41 ;
int V_1 ;
int V_42 ;
int V_24 ;
if ( ! F_24 ( V_7 ) )
return 0 ;
if ( ! ( V_16 -> V_3 || F_25 ( V_16 -> V_2 ) ) ||
F_21 () )
return 0 ;
F_26 ( V_23 ) ;
V_42 = F_27 () ;
V_40 = V_21 -> V_40 [ V_42 ] ;
V_41 = F_28 ( & V_40 -> V_41 ) ;
if ( F_29 ( V_41 == 1 ) ) {
V_24 = F_30 () ;
V_1 = F_15 ( V_21 , V_16 , V_23 , V_24 ) ;
} else {
V_1 = 0 ;
}
F_31 ( & V_40 -> V_41 ) ;
F_32 ( V_23 ) ;
return V_1 ;
}
int F_33 ( struct V_22 * V_16 )
{
if ( V_43 )
return 1 ;
else
return F_23 ( V_16 ) ;
}
static void
F_34 ( struct V_20 * V_21 ,
unsigned long V_44 , unsigned long V_23 , int V_24 )
{
T_1 time = F_4 () ;
struct V_22 V_45 = {
. V_2 = V_44 ,
. V_3 = 0 ,
} ;
struct V_15 V_1 = {
. V_2 = V_44 ,
. V_3 = 0 ,
. V_5 = time ,
. V_19 = time ,
} ;
F_15 ( V_21 , & V_45 , V_23 , V_24 ) ;
F_35 ( V_21 , & V_1 , V_23 , V_24 ) ;
}
void
F_36 ( struct V_20 * V_21 ,
unsigned long V_44 , unsigned long V_46 ,
unsigned long V_23 , int V_24 )
{
F_34 ( V_21 , V_44 , V_23 , V_24 ) ;
}
void F_35 ( struct V_20 * V_21 ,
struct V_15 * V_16 ,
unsigned long V_23 ,
int V_24 )
{
struct V_25 * V_26 = & V_47 ;
struct V_28 * V_29 ;
struct V_30 * V_31 = V_21 -> V_31 ;
struct V_48 * V_33 ;
if ( F_7 ( F_16 ( V_34 ) ) )
return;
V_29 = F_17 ( V_31 , V_49 ,
sizeof( * V_33 ) , V_23 , V_24 ) ;
if ( ! V_29 )
return;
V_33 = F_18 ( V_29 ) ;
V_33 -> V_1 = * V_16 ;
if ( ! F_19 ( V_31 , V_26 , V_33 , V_29 ) )
F_20 ( V_31 , V_29 ) ;
}
void F_37 ( struct V_15 * V_16 )
{
struct V_20 * V_21 = V_38 ;
struct V_39 * V_40 ;
unsigned long V_23 ;
long V_41 ;
int V_42 ;
int V_24 ;
F_26 ( V_23 ) ;
V_42 = F_27 () ;
V_40 = V_21 -> V_40 [ V_42 ] ;
V_41 = F_28 ( & V_40 -> V_41 ) ;
if ( F_29 ( V_41 == 1 ) ) {
V_24 = F_30 () ;
F_35 ( V_21 , V_16 , V_23 , V_24 ) ;
}
F_31 ( & V_40 -> V_41 ) ;
F_32 ( V_23 ) ;
}
void F_38 ( struct V_20 * V_21 )
{
V_38 = V_21 ;
F_39 () ;
}
void F_40 ( struct V_15 * V_16 )
{
if ( V_43 &&
( V_16 -> V_19 - V_16 -> V_5 < V_43 ) )
return;
else
F_37 ( V_16 ) ;
}
static int F_41 ( struct V_20 * V_21 )
{
int V_1 ;
F_38 ( V_21 ) ;
if ( V_43 )
V_1 = F_42 ( & F_40 ,
& F_33 ) ;
else
V_1 = F_42 ( & F_37 ,
& F_23 ) ;
if ( V_1 )
return V_1 ;
F_43 () ;
return 0 ;
}
static void F_44 ( struct V_20 * V_21 )
{
F_45 () ;
F_46 () ;
}
static enum V_50
F_47 ( struct V_51 * V_52 , int V_42 )
{
int V_1 ;
V_1 = F_48 ( V_52 , L_3 , V_53 , V_42 ) ;
if ( ! V_1 )
return V_54 ;
return V_55 ;
}
static enum V_50
F_49 ( struct V_51 * V_52 , T_2 V_56 )
{
char V_57 [ V_58 ] ;
char V_59 [ 11 ] ;
int V_60 = 0 ;
int V_1 ;
int V_61 ;
int V_62 ;
F_50 ( V_56 , V_57 ) ;
V_57 [ 7 ] = '\0' ;
sprintf ( V_59 , L_4 , V_56 ) ;
V_61 = strlen ( V_57 ) + strlen ( V_59 ) + 1 ;
if ( V_61 < V_63 )
V_60 = V_63 - V_61 ;
for ( V_62 = 0 ; V_62 < V_60 / 2 ; V_62 ++ ) {
V_1 = F_48 ( V_52 , L_5 ) ;
if ( ! V_1 )
return V_54 ;
}
V_1 = F_48 ( V_52 , L_6 , V_57 , V_59 ) ;
if ( ! V_1 )
return V_54 ;
for ( V_62 = 0 ; V_62 < V_60 - ( V_60 / 2 ) ; V_62 ++ ) {
V_1 = F_48 ( V_52 , L_5 ) ;
if ( ! V_1 )
return V_54 ;
}
return V_55 ;
}
static enum V_50
F_51 ( struct V_51 * V_52 , struct V_64 * V_33 )
{
if ( ! F_52 ( V_52 , ' ' ) )
return 0 ;
return F_53 ( V_52 , V_33 ) ;
}
static enum V_50
F_54 ( struct V_51 * V_52 , T_2 V_56 , int V_42 , struct V_65 * V_40 )
{
T_2 V_66 ;
T_2 * V_67 ;
int V_1 ;
if ( ! V_40 )
return V_55 ;
V_67 = & ( F_55 ( V_40 -> V_68 , V_42 ) -> V_67 ) ;
if ( * V_67 == V_56 )
return V_55 ;
V_66 = * V_67 ;
* V_67 = V_56 ;
if ( V_66 == - 1 )
return V_55 ;
V_1 = F_48 ( V_52 ,
L_7 ) ;
if ( ! V_1 )
return V_54 ;
V_1 = F_47 ( V_52 , V_42 ) ;
if ( V_1 == V_54 )
return V_54 ;
V_1 = F_49 ( V_52 , V_66 ) ;
if ( V_1 == V_54 )
return V_54 ;
V_1 = F_48 ( V_52 , L_8 ) ;
if ( ! V_1 )
return V_54 ;
V_1 = F_49 ( V_52 , V_56 ) ;
if ( V_1 == V_54 )
return V_54 ;
V_1 = F_48 ( V_52 ,
L_9 ) ;
if ( ! V_1 )
return V_54 ;
return V_55 ;
}
static struct V_48 *
F_56 ( struct V_69 * V_70 ,
struct V_32 * V_71 )
{
struct V_65 * V_40 = V_70 -> V_72 ;
struct V_73 * V_74 = NULL ;
struct V_28 * V_29 ;
struct V_48 * V_75 ;
if ( V_40 && V_40 -> V_76 ) {
V_71 = & V_40 -> V_45 ;
V_75 = & V_40 -> V_1 ;
} else {
V_74 = V_70 -> V_77 [ V_70 -> V_42 ] ;
if ( V_74 )
V_29 = F_57 ( V_74 , NULL ) ;
else {
F_58 ( V_70 -> V_21 -> V_31 , V_70 -> V_42 ,
NULL , NULL ) ;
V_29 = F_59 ( V_70 -> V_21 -> V_31 , V_70 -> V_42 ,
NULL , NULL ) ;
}
if ( ! V_29 )
return NULL ;
V_75 = F_18 ( V_29 ) ;
if ( V_40 ) {
V_40 -> V_45 = * V_71 ;
if ( V_75 -> V_45 . type == V_49 )
V_40 -> V_1 = * V_75 ;
else
V_40 -> V_1 . V_45 . type = V_75 -> V_45 . type ;
}
}
if ( V_75 -> V_45 . type != V_49 )
return NULL ;
if ( V_71 -> V_45 . V_56 != V_75 -> V_45 . V_56 ||
V_71 -> V_36 . V_2 != V_75 -> V_1 . V_2 )
return NULL ;
if ( V_74 )
F_60 ( V_74 , NULL ) ;
return V_75 ;
}
static int
F_61 ( unsigned long long V_78 , struct V_51 * V_52 ,
T_3 V_23 )
{
if ( ! ( V_23 & V_79 ) )
return 1 ;
if ( V_78 == - 1 )
return F_48 ( V_52 , L_10 ) ;
if ( V_23 & V_80 ) {
if ( V_78 > 100000ULL )
return F_48 ( V_52 , L_11 ) ;
if ( V_78 > 10000ULL )
return F_48 ( V_52 , L_12 ) ;
}
return F_48 ( V_52 , L_10 ) ;
}
static int F_62 ( T_1 V_81 , struct V_51 * V_52 )
{
unsigned long V_82 ;
V_82 = F_63 ( V_81 , V_83 ) ;
V_82 /= 1000 ;
return F_48 ( V_52 , L_13 ,
( unsigned long ) V_81 , V_82 ) ;
}
static enum V_50
F_64 ( struct V_69 * V_70 , unsigned long V_84 ,
enum V_85 type , int V_42 , T_2 V_56 , T_3 V_23 )
{
int V_1 ;
struct V_51 * V_52 = & V_70 -> V_86 ;
if ( V_84 < ( unsigned long ) V_87 ||
V_84 >= ( unsigned long ) V_88 )
return V_89 ;
if ( V_23 & V_90 ) {
V_1 = F_62 ( V_70 -> V_91 , V_52 ) ;
if ( ! V_1 )
return V_54 ;
}
if ( V_23 & V_92 ) {
V_1 = F_47 ( V_52 , V_42 ) ;
if ( V_1 == V_54 )
return V_54 ;
}
if ( V_23 & V_93 ) {
V_1 = F_49 ( V_52 , V_56 ) ;
if ( V_1 == V_54 )
return V_54 ;
V_1 = F_48 ( V_52 , L_14 ) ;
if ( ! V_1 )
return V_54 ;
}
V_1 = F_61 ( - 1 , V_52 , V_23 ) ;
if ( ! V_1 )
return V_54 ;
if ( type == V_35 )
V_1 = F_48 ( V_52 , L_15 ) ;
else
V_1 = F_48 ( V_52 , L_16 ) ;
if ( ! V_1 )
return V_54 ;
if ( V_23 & V_79 )
F_48 ( V_52 , L_17 ) ;
V_1 = F_48 ( V_52 , L_18 ) ;
if ( ! V_1 )
return V_54 ;
return V_55 ;
}
enum V_50
F_65 ( unsigned long long V_78 , struct V_51 * V_52 )
{
unsigned long V_94 = F_63 ( V_78 , 1000 ) ;
char V_95 [ 21 ] ;
char V_96 [ 5 ] ;
int V_1 , V_61 ;
int V_62 ;
sprintf ( V_95 , L_19 , ( unsigned long ) V_78 ) ;
V_1 = F_48 ( V_52 , L_20 , V_95 ) ;
if ( ! V_1 )
return V_54 ;
V_61 = strlen ( V_95 ) ;
if ( V_61 < 7 ) {
T_4 V_97 = F_66 ( T_4 , sizeof( V_96 ) , 8UL - V_61 ) ;
snprintf ( V_96 , V_97 , L_21 , V_94 ) ;
V_1 = F_48 ( V_52 , L_22 , V_96 ) ;
if ( ! V_1 )
return V_54 ;
V_61 += strlen ( V_96 ) ;
}
V_1 = F_48 ( V_52 , L_23 ) ;
if ( ! V_1 )
return V_54 ;
for ( V_62 = V_61 ; V_62 < 7 ; V_62 ++ ) {
V_1 = F_48 ( V_52 , L_5 ) ;
if ( ! V_1 )
return V_54 ;
}
return V_55 ;
}
static enum V_50
F_67 ( unsigned long long V_78 , struct V_51 * V_52 )
{
int V_1 ;
V_1 = F_65 ( V_78 , V_52 ) ;
if ( V_1 != V_55 )
return V_1 ;
V_1 = F_48 ( V_52 , L_24 ) ;
if ( ! V_1 )
return V_54 ;
return V_55 ;
}
static enum V_50
F_68 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
struct V_48 * V_98 ,
struct V_51 * V_52 , T_3 V_23 )
{
struct V_65 * V_40 = V_70 -> V_72 ;
struct V_15 * V_99 ;
struct V_22 * V_26 ;
unsigned long long V_78 ;
int V_1 ;
int V_62 ;
V_99 = & V_98 -> V_1 ;
V_26 = & V_33 -> V_36 ;
V_78 = V_99 -> V_19 - V_99 -> V_5 ;
if ( V_40 ) {
struct V_100 * V_68 ;
int V_42 = V_70 -> V_42 ;
V_68 = F_55 ( V_40 -> V_68 , V_42 ) ;
V_68 -> V_3 = V_26 -> V_3 - 1 ;
if ( V_26 -> V_3 < V_11 )
V_68 -> V_101 [ V_26 -> V_3 ] = 0 ;
}
V_1 = F_61 ( V_78 , V_52 , V_23 ) ;
if ( ! V_1 )
return V_54 ;
if ( V_23 & V_79 ) {
V_1 = F_67 ( V_78 , V_52 ) ;
if ( V_1 == V_54 )
return V_54 ;
}
for ( V_62 = 0 ; V_62 < V_26 -> V_3 * V_102 ; V_62 ++ ) {
V_1 = F_48 ( V_52 , L_5 ) ;
if ( ! V_1 )
return V_54 ;
}
V_1 = F_48 ( V_52 , L_25 , ( void * ) V_26 -> V_2 ) ;
if ( ! V_1 )
return V_54 ;
return V_55 ;
}
static enum V_50
F_69 ( struct V_69 * V_70 ,
struct V_32 * V_33 ,
struct V_51 * V_52 , int V_42 , T_3 V_23 )
{
struct V_22 * V_26 = & V_33 -> V_36 ;
struct V_65 * V_40 = V_70 -> V_72 ;
int V_1 ;
int V_62 ;
if ( V_40 ) {
struct V_100 * V_68 ;
int V_42 = V_70 -> V_42 ;
V_68 = F_55 ( V_40 -> V_68 , V_42 ) ;
V_68 -> V_3 = V_26 -> V_3 ;
if ( V_26 -> V_3 < V_11 )
V_68 -> V_101 [ V_26 -> V_3 ] = V_26 -> V_2 ;
}
V_1 = F_61 ( - 1 , V_52 , V_23 ) ;
if ( ! V_1 )
return V_54 ;
if ( V_23 & V_79 ) {
V_1 = F_48 ( V_52 , L_26 ) ;
if ( ! V_1 )
return V_54 ;
}
for ( V_62 = 0 ; V_62 < V_26 -> V_3 * V_102 ; V_62 ++ ) {
V_1 = F_48 ( V_52 , L_5 ) ;
if ( ! V_1 )
return V_54 ;
}
V_1 = F_48 ( V_52 , L_27 , ( void * ) V_26 -> V_2 ) ;
if ( ! V_1 )
return V_54 ;
return V_103 ;
}
static enum V_50
F_70 ( struct V_69 * V_70 , struct V_51 * V_52 ,
int type , unsigned long V_84 , T_3 V_23 )
{
struct V_65 * V_40 = V_70 -> V_72 ;
struct V_64 * V_45 = V_70 -> V_45 ;
int V_42 = V_70 -> V_42 ;
int V_1 ;
if ( F_54 ( V_52 , V_45 -> V_56 , V_42 , V_40 ) == V_54 )
return V_54 ;
if ( type ) {
V_1 = F_64 ( V_70 , V_84 , type , V_42 , V_45 -> V_56 , V_23 ) ;
if ( V_1 == V_54 )
return V_54 ;
}
if ( V_23 & V_90 ) {
V_1 = F_62 ( V_70 -> V_91 , V_52 ) ;
if ( ! V_1 )
return V_54 ;
}
if ( V_23 & V_92 ) {
V_1 = F_47 ( V_52 , V_42 ) ;
if ( V_1 == V_54 )
return V_54 ;
}
if ( V_23 & V_93 ) {
V_1 = F_49 ( V_52 , V_45 -> V_56 ) ;
if ( V_1 == V_54 )
return V_54 ;
V_1 = F_48 ( V_52 , L_14 ) ;
if ( ! V_1 )
return V_54 ;
}
if ( V_104 & V_105 ) {
V_1 = F_51 ( V_52 , V_45 ) ;
if ( V_1 == V_54 )
return V_54 ;
}
return 0 ;
}
static int
F_71 ( struct V_69 * V_70 , T_3 V_23 ,
unsigned long V_84 , int V_3 )
{
int V_42 = V_70 -> V_42 ;
int * V_106 ;
struct V_65 * V_40 = V_70 -> V_72 ;
if ( ( V_23 & V_107 ) ||
( ! V_40 ) )
return 0 ;
V_106 = & ( F_55 ( V_40 -> V_68 , V_42 ) -> V_106 ) ;
if ( * V_106 >= 0 )
return 1 ;
if ( ( V_84 < ( unsigned long ) V_87 ) ||
( V_84 >= ( unsigned long ) V_88 ) )
return 0 ;
* V_106 = V_3 ;
return 1 ;
}
static int
F_72 ( struct V_69 * V_70 , T_3 V_23 , int V_3 )
{
int V_42 = V_70 -> V_42 ;
int * V_106 ;
struct V_65 * V_40 = V_70 -> V_72 ;
if ( ( V_23 & V_107 ) ||
( ! V_40 ) )
return 0 ;
V_106 = & ( F_55 ( V_40 -> V_68 , V_42 ) -> V_106 ) ;
if ( * V_106 == - 1 )
return 0 ;
if ( * V_106 >= V_3 ) {
* V_106 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_50
F_73 ( struct V_32 * V_108 , struct V_51 * V_52 ,
struct V_69 * V_70 , T_3 V_23 )
{
struct V_65 * V_40 = V_70 -> V_72 ;
struct V_22 * V_26 = & V_108 -> V_36 ;
struct V_48 * V_109 ;
static enum V_50 V_1 ;
int V_42 = V_70 -> V_42 ;
if ( F_71 ( V_70 , V_23 , V_26 -> V_2 , V_26 -> V_3 ) )
return V_55 ;
if ( F_70 ( V_70 , V_52 , V_35 , V_26 -> V_2 , V_23 ) )
return V_54 ;
V_109 = F_56 ( V_70 , V_108 ) ;
if ( V_109 )
V_1 = F_68 ( V_70 , V_108 , V_109 , V_52 , V_23 ) ;
else
V_1 = F_69 ( V_70 , V_108 , V_52 , V_42 , V_23 ) ;
if ( V_40 ) {
if ( V_52 -> V_110 ) {
V_40 -> V_76 = 1 ;
V_40 -> V_42 = V_42 ;
} else
V_40 -> V_76 = 0 ;
}
return V_1 ;
}
static enum V_50
F_74 ( struct V_15 * V_16 , struct V_51 * V_52 ,
struct V_64 * V_45 , struct V_69 * V_70 ,
T_3 V_23 )
{
unsigned long long V_78 = V_16 -> V_19 - V_16 -> V_5 ;
struct V_65 * V_40 = V_70 -> V_72 ;
T_2 V_56 = V_45 -> V_56 ;
int V_42 = V_70 -> V_42 ;
int V_111 = 1 ;
int V_1 ;
int V_62 ;
if ( F_72 ( V_70 , V_23 , V_16 -> V_3 ) )
return V_55 ;
if ( V_40 ) {
struct V_100 * V_68 ;
int V_42 = V_70 -> V_42 ;
V_68 = F_55 ( V_40 -> V_68 , V_42 ) ;
V_68 -> V_3 = V_16 -> V_3 - 1 ;
if ( V_16 -> V_3 < V_11 ) {
if ( V_68 -> V_101 [ V_16 -> V_3 ] != V_16 -> V_2 )
V_111 = 0 ;
V_68 -> V_101 [ V_16 -> V_3 ] = 0 ;
}
}
if ( F_70 ( V_70 , V_52 , 0 , 0 , V_23 ) )
return V_54 ;
V_1 = F_61 ( V_78 , V_52 , V_23 ) ;
if ( ! V_1 )
return V_54 ;
if ( V_23 & V_79 ) {
V_1 = F_67 ( V_78 , V_52 ) ;
if ( V_1 == V_54 )
return V_54 ;
}
for ( V_62 = 0 ; V_62 < V_16 -> V_3 * V_102 ; V_62 ++ ) {
V_1 = F_48 ( V_52 , L_5 ) ;
if ( ! V_1 )
return V_54 ;
}
if ( V_111 ) {
V_1 = F_48 ( V_52 , L_28 ) ;
if ( ! V_1 )
return V_54 ;
} else {
V_1 = F_48 ( V_52 , L_29 , ( void * ) V_16 -> V_2 ) ;
if ( ! V_1 )
return V_54 ;
}
if ( V_23 & V_112 ) {
V_1 = F_48 ( V_52 , L_30 ,
V_16 -> V_18 ) ;
if ( ! V_1 )
return V_54 ;
}
V_1 = F_64 ( V_70 , V_16 -> V_2 , V_49 ,
V_42 , V_56 , V_23 ) ;
if ( V_1 == V_54 )
return V_54 ;
return V_55 ;
}
static enum V_50
F_75 ( struct V_51 * V_52 , struct V_64 * V_45 ,
struct V_69 * V_70 , T_3 V_23 )
{
unsigned long V_113 = ( V_104 & V_114 ) ;
struct V_65 * V_40 = V_70 -> V_72 ;
struct V_115 * V_29 ;
int V_3 = 0 ;
int V_1 ;
int V_62 ;
if ( V_40 )
V_3 = F_55 ( V_40 -> V_68 , V_70 -> V_42 ) -> V_3 ;
if ( F_70 ( V_70 , V_52 , 0 , 0 , V_23 ) )
return V_54 ;
V_1 = F_61 ( - 1 , V_52 , V_23 ) ;
if ( ! V_1 )
return V_54 ;
if ( V_23 & V_79 ) {
V_1 = F_48 ( V_52 , L_26 ) ;
if ( ! V_1 )
return V_54 ;
}
if ( V_3 > 0 )
for ( V_62 = 0 ; V_62 < ( V_3 + 1 ) * V_102 ; V_62 ++ ) {
V_1 = F_48 ( V_52 , L_5 ) ;
if ( ! V_1 )
return V_54 ;
}
V_1 = F_48 ( V_52 , L_31 ) ;
if ( ! V_1 )
return V_54 ;
switch ( V_70 -> V_45 -> type ) {
case V_116 :
V_1 = F_76 ( V_70 ) ;
if ( V_1 != V_55 )
return V_1 ;
break;
case V_117 :
V_1 = F_77 ( V_70 ) ;
if ( V_1 != V_55 )
return V_1 ;
break;
default:
V_29 = F_78 ( V_45 -> type ) ;
if ( ! V_29 )
return V_89 ;
V_1 = V_29 -> V_118 -> V_16 ( V_70 , V_113 , V_29 ) ;
if ( V_1 != V_55 )
return V_1 ;
}
if ( V_52 -> V_31 [ V_52 -> V_61 - 1 ] == '\n' ) {
V_52 -> V_31 [ V_52 -> V_61 - 1 ] = '\0' ;
V_52 -> V_61 -- ;
}
V_1 = F_48 ( V_52 , L_32 ) ;
if ( ! V_1 )
return V_54 ;
return V_55 ;
}
enum V_50
F_79 ( struct V_69 * V_70 , T_3 V_23 )
{
struct V_32 * V_108 ;
struct V_65 * V_40 = V_70 -> V_72 ;
struct V_64 * V_33 = V_70 -> V_45 ;
struct V_51 * V_52 = & V_70 -> V_86 ;
int V_42 = V_70 -> V_42 ;
int V_1 ;
if ( V_40 && F_55 ( V_40 -> V_68 , V_42 ) -> V_119 ) {
F_55 ( V_40 -> V_68 , V_42 ) -> V_119 = 0 ;
return V_55 ;
}
if ( V_40 && V_40 -> V_76 ) {
V_108 = & V_40 -> V_45 ;
V_70 -> V_42 = V_40 -> V_42 ;
V_1 = F_73 ( V_108 , V_52 , V_70 , V_23 ) ;
if ( V_1 == V_55 && V_70 -> V_42 != V_42 ) {
F_55 ( V_40 -> V_68 , V_70 -> V_42 ) -> V_119 = 1 ;
V_1 = V_103 ;
}
V_70 -> V_42 = V_42 ;
return V_1 ;
}
switch ( V_33 -> type ) {
case V_35 : {
struct V_32 V_120 ;
F_80 ( V_108 , V_33 ) ;
V_120 = * V_108 ;
return F_73 ( & V_120 , V_52 , V_70 , V_23 ) ;
}
case V_49 : {
struct V_48 * V_108 ;
F_80 ( V_108 , V_33 ) ;
return F_74 ( & V_108 -> V_1 , V_52 , V_33 , V_70 , V_23 ) ;
}
case V_121 :
case V_122 :
return V_89 ;
default:
return F_75 ( V_52 , V_33 , V_70 , V_23 ) ;
}
return V_55 ;
}
static enum V_50
F_81 ( struct V_69 * V_70 )
{
return F_79 ( V_70 , V_123 . V_124 ) ;
}
enum V_50 F_82 ( struct V_69 * V_70 ,
T_3 V_23 )
{
if ( V_104 & V_105 )
V_23 |= V_79 ;
else
V_23 |= V_90 ;
return F_79 ( V_70 , V_23 ) ;
}
static enum V_50
F_83 ( struct V_69 * V_70 , int V_23 ,
struct V_115 * V_29 )
{
return F_81 ( V_70 ) ;
}
static void F_84 ( struct V_125 * V_52 , T_3 V_23 )
{
static const char V_60 [] = L_33
L_34
L_35 ;
int V_126 = 0 ;
if ( V_23 & V_90 )
V_126 += 16 ;
if ( V_23 & V_92 )
V_126 += 4 ;
if ( V_23 & V_93 )
V_126 += 17 ;
F_85 ( V_52 , L_36 , V_126 , V_60 ) ;
F_85 ( V_52 , L_37 , V_126 , V_60 ) ;
F_85 ( V_52 , L_38 , V_126 , V_60 ) ;
F_85 ( V_52 , L_39 , V_126 , V_60 ) ;
F_85 ( V_52 , L_40 , V_126 , V_60 ) ;
F_85 ( V_52 , L_41 , V_126 , V_60 ) ;
}
static void F_86 ( struct V_125 * V_52 , T_3 V_23 )
{
int V_127 = V_104 & V_105 ;
if ( V_127 )
F_84 ( V_52 , V_23 ) ;
F_85 ( V_52 , L_42 ) ;
if ( V_23 & V_90 )
F_85 ( V_52 , L_43 ) ;
if ( V_23 & V_92 )
F_85 ( V_52 , L_44 ) ;
if ( V_23 & V_93 )
F_85 ( V_52 , L_45 ) ;
if ( V_127 )
F_85 ( V_52 , L_46 ) ;
if ( V_23 & V_79 )
F_85 ( V_52 , L_47 ) ;
F_85 ( V_52 , L_48 ) ;
F_85 ( V_52 , L_42 ) ;
if ( V_23 & V_90 )
F_85 ( V_52 , L_49 ) ;
if ( V_23 & V_92 )
F_85 ( V_52 , L_50 ) ;
if ( V_23 & V_93 )
F_85 ( V_52 , L_51 ) ;
if ( V_127 )
F_85 ( V_52 , L_46 ) ;
if ( V_23 & V_79 )
F_85 ( V_52 , L_52 ) ;
F_85 ( V_52 , L_53 ) ;
}
void F_87 ( struct V_125 * V_52 )
{
F_88 ( V_52 , V_123 . V_124 ) ;
}
void F_88 ( struct V_125 * V_52 , T_3 V_23 )
{
struct V_69 * V_70 = V_52 -> V_72 ;
if ( V_104 & V_105 ) {
if ( F_89 ( V_70 ) )
return;
F_90 ( V_52 , V_70 ) ;
V_23 |= V_79 ;
} else
V_23 |= V_90 ;
F_86 ( V_52 , V_23 ) ;
}
void F_91 ( struct V_69 * V_70 )
{
struct V_65 * V_40 ;
int V_42 ;
V_70 -> V_72 = NULL ;
V_40 = F_92 ( sizeof( * V_40 ) , V_128 ) ;
if ( ! V_40 )
goto V_129;
V_40 -> V_68 = F_93 ( struct V_100 ) ;
if ( ! V_40 -> V_68 )
goto V_130;
F_94 (cpu) {
T_2 * V_56 = & ( F_55 ( V_40 -> V_68 , V_42 ) -> V_67 ) ;
int * V_3 = & ( F_55 ( V_40 -> V_68 , V_42 ) -> V_3 ) ;
int * V_119 = & ( F_55 ( V_40 -> V_68 , V_42 ) -> V_119 ) ;
int * V_106 = & ( F_55 ( V_40 -> V_68 , V_42 ) -> V_106 ) ;
* V_56 = - 1 ;
* V_3 = 0 ;
* V_119 = 0 ;
* V_106 = - 1 ;
}
V_70 -> V_72 = V_40 ;
return;
V_130:
F_95 ( V_40 ) ;
V_129:
F_96 ( L_54 ) ;
}
void F_97 ( struct V_69 * V_70 )
{
struct V_65 * V_40 = V_70 -> V_72 ;
if ( V_40 ) {
F_98 ( V_40 -> V_68 ) ;
F_95 ( V_40 ) ;
}
}
static int F_99 ( T_3 V_131 , T_3 V_132 , int V_133 )
{
if ( V_132 == V_107 )
V_37 = ! V_133 ;
return 0 ;
}
static T_5 int F_100 ( void )
{
V_53 = snprintf ( NULL , 0 , L_4 , V_134 - 1 ) ;
if ( ! F_101 ( & V_135 ) ) {
F_96 ( L_55 ) ;
return 1 ;
}
if ( ! F_101 ( & V_136 ) ) {
F_96 ( L_55 ) ;
return 1 ;
}
return F_102 ( & V_137 ) ;
}
