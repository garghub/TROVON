bool F_1 ( void )
{
return V_1 ;
}
void F_2 ( void )
{
V_1 = true ;
}
int
F_3 ( unsigned long V_2 , unsigned long V_3 , int * V_4 ,
unsigned long V_5 )
{
unsigned long long V_6 ;
int V_7 ;
if ( F_4 ( F_1 () ) )
return - V_8 ;
if ( ! V_9 -> V_10 )
return - V_8 ;
F_5 () ;
if ( V_9 -> V_11 == V_12 - 1 ) {
F_6 ( & V_9 -> V_13 ) ;
return - V_8 ;
}
if ( V_9 -> V_11 < - 1 )
return - V_8 ;
V_6 = F_7 () ;
V_7 = ++ V_9 -> V_11 ;
if ( F_8 ( V_3 ) )
V_9 -> V_11 -= V_14 ;
F_9 () ;
V_9 -> V_10 [ V_7 ] . V_2 = V_2 ;
V_9 -> V_10 [ V_7 ] . V_3 = V_3 ;
V_9 -> V_10 [ V_7 ] . V_6 = V_6 ;
V_9 -> V_10 [ V_7 ] . V_15 = 0 ;
V_9 -> V_10 [ V_7 ] . V_16 = V_5 ;
* V_4 = V_9 -> V_11 ;
return 0 ;
}
static void
F_10 ( struct V_17 * V_18 , unsigned long * V_2 ,
unsigned long V_5 )
{
int V_7 ;
V_7 = V_9 -> V_11 ;
if ( V_7 < 0 )
V_7 += V_14 ;
if ( F_4 ( V_7 < 0 || V_7 >= V_12 ) ) {
F_2 () ;
F_11 ( 1 ) ;
* V_2 = ( unsigned long ) V_19 ;
return;
}
#if F_12 ( V_20 ) && ! F_12 ( V_21 )
if ( F_4 ( V_9 -> V_10 [ V_7 ] . V_16 != V_5 ) ) {
F_2 () ;
F_13 ( 1 , L_1
L_2 ,
V_9 -> V_10 [ V_7 ] . V_16 ,
V_5 ,
( void * ) V_9 -> V_10 [ V_7 ] . V_3 ,
V_9 -> V_10 [ V_7 ] . V_2 ) ;
* V_2 = ( unsigned long ) V_19 ;
return;
}
#endif
* V_2 = V_9 -> V_10 [ V_7 ] . V_2 ;
V_18 -> V_3 = V_9 -> V_10 [ V_7 ] . V_3 ;
V_18 -> V_6 = V_9 -> V_10 [ V_7 ] . V_6 ;
V_18 -> V_22 = F_14 ( & V_9 -> V_13 ) ;
V_18 -> V_4 = V_7 ;
}
unsigned long F_15 ( unsigned long V_5 )
{
struct V_17 V_18 ;
unsigned long V_2 ;
F_10 ( & V_18 , & V_2 , V_5 ) ;
V_18 . V_23 = F_7 () ;
F_9 () ;
V_9 -> V_11 -- ;
if ( V_9 -> V_11 < - 1 ) {
V_9 -> V_11 += V_14 ;
return V_2 ;
}
F_16 ( & V_18 ) ;
if ( F_4 ( ! V_2 ) ) {
F_2 () ;
F_11 ( 1 ) ;
V_2 = ( unsigned long ) V_19 ;
}
return V_2 ;
}
int F_17 ( struct V_24 * V_25 ,
struct V_26 * V_18 ,
unsigned long V_27 ,
int V_28 )
{
struct V_29 * V_30 = & V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 = V_25 -> V_36 . V_35 ;
struct V_37 * V_38 ;
if ( F_4 ( F_18 ( V_39 ) ) )
return 0 ;
V_33 = F_19 ( V_35 , V_40 ,
sizeof( * V_38 ) , V_27 , V_28 ) ;
if ( ! V_33 )
return 0 ;
V_38 = F_20 ( V_33 ) ;
V_38 -> V_41 = * V_18 ;
if ( ! F_21 ( V_30 , V_38 , V_35 , V_33 ) )
F_22 ( V_35 , V_33 ) ;
return 1 ;
}
static inline int F_23 ( void )
{
if ( ! V_42 || F_24 ( V_43 ) )
return 0 ;
return F_25 () ;
}
int F_26 ( struct V_26 * V_18 )
{
struct V_24 * V_25 = V_44 ;
struct V_45 * V_46 ;
unsigned long V_27 ;
long V_47 ;
int V_2 ;
int V_48 ;
int V_28 ;
if ( ! F_27 ( V_9 ) )
return 0 ;
if ( ( ! ( V_18 -> V_4 || F_28 ( V_18 -> V_3 ) ) ||
F_23 () ) || ( V_18 -> V_4 < 0 ) ||
( V_49 && V_18 -> V_4 >= V_49 ) )
return 0 ;
if ( F_8 ( V_18 -> V_3 ) )
return 1 ;
F_29 ( V_27 ) ;
V_48 = F_30 () ;
V_46 = F_31 ( V_25 -> V_36 . V_46 , V_48 ) ;
V_47 = F_32 ( & V_46 -> V_47 ) ;
if ( F_33 ( V_47 == 1 ) ) {
V_28 = F_34 () ;
V_2 = F_17 ( V_25 , V_18 , V_27 , V_28 ) ;
} else {
V_2 = 0 ;
}
F_35 ( & V_46 -> V_47 ) ;
F_36 ( V_27 ) ;
return V_2 ;
}
static int F_37 ( struct V_26 * V_18 )
{
if ( V_50 )
return 1 ;
else
return F_26 ( V_18 ) ;
}
static void
F_38 ( struct V_24 * V_25 ,
unsigned long V_51 , unsigned long V_27 , int V_28 )
{
T_1 time = F_7 () ;
struct V_26 V_52 = {
. V_3 = V_51 ,
. V_4 = 0 ,
} ;
struct V_17 V_2 = {
. V_3 = V_51 ,
. V_4 = 0 ,
. V_6 = time ,
. V_23 = time ,
} ;
F_17 ( V_25 , & V_52 , V_27 , V_28 ) ;
F_39 ( V_25 , & V_2 , V_27 , V_28 ) ;
}
void
F_40 ( struct V_24 * V_25 ,
unsigned long V_51 , unsigned long V_53 ,
unsigned long V_27 , int V_28 )
{
F_38 ( V_25 , V_51 , V_27 , V_28 ) ;
}
void F_39 ( struct V_24 * V_25 ,
struct V_17 * V_18 ,
unsigned long V_27 ,
int V_28 )
{
struct V_29 * V_30 = & V_54 ;
struct V_32 * V_33 ;
struct V_34 * V_35 = V_25 -> V_36 . V_35 ;
struct V_55 * V_38 ;
if ( F_4 ( F_18 ( V_39 ) ) )
return;
V_33 = F_19 ( V_35 , V_56 ,
sizeof( * V_38 ) , V_27 , V_28 ) ;
if ( ! V_33 )
return;
V_38 = F_20 ( V_33 ) ;
V_38 -> V_2 = * V_18 ;
if ( ! F_21 ( V_30 , V_38 , V_35 , V_33 ) )
F_22 ( V_35 , V_33 ) ;
}
void F_41 ( struct V_17 * V_18 )
{
struct V_24 * V_25 = V_44 ;
struct V_45 * V_46 ;
unsigned long V_27 ;
long V_47 ;
int V_48 ;
int V_28 ;
F_29 ( V_27 ) ;
V_48 = F_30 () ;
V_46 = F_31 ( V_25 -> V_36 . V_46 , V_48 ) ;
V_47 = F_32 ( & V_46 -> V_47 ) ;
if ( F_33 ( V_47 == 1 ) ) {
V_28 = F_34 () ;
F_39 ( V_25 , V_18 , V_27 , V_28 ) ;
}
F_35 ( & V_46 -> V_47 ) ;
F_36 ( V_27 ) ;
}
void F_42 ( struct V_24 * V_25 )
{
V_44 = V_25 ;
F_43 () ;
}
static void F_44 ( struct V_17 * V_18 )
{
if ( V_50 &&
( V_18 -> V_23 - V_18 -> V_6 < V_50 ) )
return;
else
F_41 ( V_18 ) ;
}
static int F_45 ( struct V_24 * V_25 )
{
int V_2 ;
F_42 ( V_25 ) ;
if ( V_50 )
V_2 = F_46 ( & F_44 ,
& F_37 ) ;
else
V_2 = F_46 ( & F_41 ,
& F_26 ) ;
if ( V_2 )
return V_2 ;
F_47 () ;
return 0 ;
}
static void F_48 ( struct V_24 * V_25 )
{
F_49 () ;
F_50 () ;
}
static int F_51 ( struct V_24 * V_25 )
{
F_48 ( V_25 ) ;
return F_45 ( V_25 ) ;
}
static enum V_57
F_52 ( struct V_58 * V_59 , int V_48 )
{
int V_2 ;
V_2 = F_53 ( V_59 , L_3 , V_60 , V_48 ) ;
if ( ! V_2 )
return V_61 ;
return V_62 ;
}
static enum V_57
F_54 ( struct V_58 * V_59 , T_2 V_63 )
{
char V_64 [ V_65 ] ;
char V_66 [ 11 ] ;
int V_67 = 0 ;
int V_2 ;
int V_68 ;
int V_69 ;
F_55 ( V_63 , V_64 ) ;
V_64 [ 7 ] = '\0' ;
sprintf ( V_66 , L_4 , V_63 ) ;
V_68 = strlen ( V_64 ) + strlen ( V_66 ) + 1 ;
if ( V_68 < V_70 )
V_67 = V_70 - V_68 ;
for ( V_69 = 0 ; V_69 < V_67 / 2 ; V_69 ++ ) {
V_2 = F_56 ( V_59 , ' ' ) ;
if ( ! V_2 )
return V_61 ;
}
V_2 = F_53 ( V_59 , L_5 , V_64 , V_66 ) ;
if ( ! V_2 )
return V_61 ;
for ( V_69 = 0 ; V_69 < V_67 - ( V_67 / 2 ) ; V_69 ++ ) {
V_2 = F_56 ( V_59 , ' ' ) ;
if ( ! V_2 )
return V_61 ;
}
return V_62 ;
}
static enum V_57
F_57 ( struct V_58 * V_59 , struct V_71 * V_38 )
{
if ( ! F_56 ( V_59 , ' ' ) )
return 0 ;
return F_58 ( V_59 , V_38 ) ;
}
static enum V_57
F_59 ( struct V_58 * V_59 , T_2 V_63 , int V_48 , struct V_72 * V_46 )
{
T_2 V_73 ;
T_2 * V_74 ;
int V_2 ;
if ( ! V_46 )
return V_62 ;
V_74 = & ( F_31 ( V_46 -> V_75 , V_48 ) -> V_74 ) ;
if ( * V_74 == V_63 )
return V_62 ;
V_73 = * V_74 ;
* V_74 = V_63 ;
if ( V_73 == - 1 )
return V_62 ;
V_2 = F_60 ( V_59 ,
L_6 ) ;
if ( ! V_2 )
return V_61 ;
V_2 = F_52 ( V_59 , V_48 ) ;
if ( V_2 == V_61 )
return V_61 ;
V_2 = F_54 ( V_59 , V_73 ) ;
if ( V_2 == V_61 )
return V_61 ;
V_2 = F_60 ( V_59 , L_7 ) ;
if ( ! V_2 )
return V_61 ;
V_2 = F_54 ( V_59 , V_63 ) ;
if ( V_2 == V_61 )
return V_61 ;
V_2 = F_60 ( V_59 ,
L_8 ) ;
if ( ! V_2 )
return V_61 ;
return V_62 ;
}
static struct V_55 *
F_61 ( struct V_76 * V_77 ,
struct V_37 * V_78 )
{
struct V_72 * V_46 = V_77 -> V_79 ;
struct V_80 * V_81 = NULL ;
struct V_32 * V_33 ;
struct V_55 * V_82 ;
if ( V_46 && V_46 -> V_83 ) {
V_78 = & V_46 -> V_52 ;
V_82 = & V_46 -> V_2 ;
} else {
V_81 = F_62 ( V_77 , V_77 -> V_48 ) ;
if ( V_81 )
V_33 = F_63 ( V_81 , NULL ) ;
else {
F_64 ( V_77 -> V_36 -> V_35 , V_77 -> V_48 ,
NULL , NULL ) ;
V_33 = F_65 ( V_77 -> V_36 -> V_35 , V_77 -> V_48 ,
NULL , NULL ) ;
}
if ( ! V_33 )
return NULL ;
V_82 = F_20 ( V_33 ) ;
if ( V_46 ) {
V_46 -> V_52 = * V_78 ;
if ( V_82 -> V_52 . type == V_56 )
V_46 -> V_2 = * V_82 ;
else
V_46 -> V_2 . V_52 . type = V_82 -> V_52 . type ;
}
}
if ( V_82 -> V_52 . type != V_56 )
return NULL ;
if ( V_78 -> V_52 . V_63 != V_82 -> V_52 . V_63 ||
V_78 -> V_41 . V_3 != V_82 -> V_2 . V_3 )
return NULL ;
if ( V_81 )
F_66 ( V_81 , NULL ) ;
return V_82 ;
}
static int F_67 ( T_1 V_84 , struct V_58 * V_59 )
{
unsigned long V_85 ;
V_85 = F_68 ( V_84 , V_86 ) ;
V_85 /= 1000 ;
return F_53 ( V_59 , L_9 ,
( unsigned long ) V_84 , V_85 ) ;
}
static enum V_57
F_69 ( struct V_76 * V_77 , unsigned long V_87 ,
enum V_88 type , int V_48 , T_2 V_63 , T_3 V_27 )
{
int V_2 ;
struct V_58 * V_59 = & V_77 -> V_89 ;
if ( V_87 < ( unsigned long ) V_90 ||
V_87 >= ( unsigned long ) V_91 )
return V_92 ;
if ( V_93 & V_94 ) {
if ( V_27 & V_95 ) {
V_2 = F_67 ( V_77 -> V_96 , V_59 ) ;
if ( ! V_2 )
return V_61 ;
}
if ( V_27 & V_97 ) {
V_2 = F_52 ( V_59 , V_48 ) ;
if ( V_2 == V_61 )
return V_61 ;
}
if ( V_27 & V_98 ) {
V_2 = F_54 ( V_59 , V_63 ) ;
if ( V_2 == V_61 )
return V_61 ;
V_2 = F_60 ( V_59 , L_10 ) ;
if ( ! V_2 )
return V_61 ;
}
}
V_2 = F_70 ( 0 , V_59 , V_27 | V_99 ) ;
if ( V_2 != V_62 )
return V_2 ;
if ( type == V_40 )
V_2 = F_60 ( V_59 , L_11 ) ;
else
V_2 = F_60 ( V_59 , L_12 ) ;
if ( ! V_2 )
return V_61 ;
V_2 = F_70 ( 0 , V_59 , V_27 | V_100 ) ;
if ( V_2 != V_62 )
return V_2 ;
V_2 = F_56 ( V_59 , '\n' ) ;
if ( ! V_2 )
return V_61 ;
return V_62 ;
}
enum V_57
F_71 ( unsigned long long V_101 , struct V_58 * V_59 )
{
unsigned long V_102 = F_68 ( V_101 , 1000 ) ;
char V_103 [ 21 ] ;
char V_104 [ 5 ] ;
int V_2 , V_68 ;
int V_69 ;
sprintf ( V_103 , L_13 , ( unsigned long ) V_101 ) ;
V_2 = F_53 ( V_59 , L_14 , V_103 ) ;
if ( ! V_2 )
return V_61 ;
V_68 = strlen ( V_103 ) ;
if ( V_68 < 7 ) {
T_4 V_105 = F_72 ( T_4 , sizeof( V_104 ) , 8UL - V_68 ) ;
snprintf ( V_104 , V_105 , L_15 , V_102 ) ;
V_2 = F_53 ( V_59 , L_16 , V_104 ) ;
if ( ! V_2 )
return V_61 ;
V_68 += strlen ( V_104 ) ;
}
V_2 = F_60 ( V_59 , L_17 ) ;
if ( ! V_2 )
return V_61 ;
for ( V_69 = V_68 ; V_69 < 7 ; V_69 ++ ) {
V_2 = F_56 ( V_59 , ' ' ) ;
if ( ! V_2 )
return V_61 ;
}
return V_62 ;
}
static enum V_57
F_70 ( unsigned long long V_101 , struct V_58 * V_59 ,
T_3 V_27 )
{
int V_2 = - 1 ;
if ( ! ( V_27 & V_106 ) ||
! ( V_93 & V_94 ) )
return V_62 ;
switch ( V_27 & V_107 ) {
case V_108 :
V_2 = F_60 ( V_59 , L_18 ) ;
return V_2 ? V_62 : V_61 ;
case V_99 :
V_2 = F_60 ( V_59 , L_19 ) ;
return V_2 ? V_62 : V_61 ;
case V_100 :
V_2 = F_60 ( V_59 , L_20 ) ;
return V_2 ? V_62 : V_61 ;
}
if ( V_27 & V_109 ) {
if ( V_101 > 100000ULL )
V_2 = F_60 ( V_59 , L_21 ) ;
else if ( V_101 > 10000ULL )
V_2 = F_60 ( V_59 , L_22 ) ;
}
if ( V_2 == - 1 )
V_2 = F_60 ( V_59 , L_19 ) ;
if ( ! V_2 )
return V_61 ;
V_2 = F_71 ( V_101 , V_59 ) ;
if ( V_2 != V_62 )
return V_2 ;
V_2 = F_60 ( V_59 , L_23 ) ;
if ( ! V_2 )
return V_61 ;
return V_62 ;
}
static enum V_57
F_73 ( struct V_76 * V_77 ,
struct V_37 * V_38 ,
struct V_55 * V_110 ,
struct V_58 * V_59 , T_3 V_27 )
{
struct V_72 * V_46 = V_77 -> V_79 ;
struct V_17 * V_111 ;
struct V_26 * V_30 ;
unsigned long long V_101 ;
int V_2 ;
int V_69 ;
V_111 = & V_110 -> V_2 ;
V_30 = & V_38 -> V_41 ;
V_101 = V_111 -> V_23 - V_111 -> V_6 ;
if ( V_46 ) {
struct V_112 * V_75 ;
int V_48 = V_77 -> V_48 ;
V_75 = F_31 ( V_46 -> V_75 , V_48 ) ;
V_75 -> V_4 = V_30 -> V_4 - 1 ;
if ( V_30 -> V_4 < V_12 )
V_75 -> V_113 [ V_30 -> V_4 ] = 0 ;
}
V_2 = F_70 ( V_101 , V_59 , V_27 ) ;
if ( V_2 == V_61 )
return V_61 ;
for ( V_69 = 0 ; V_69 < V_30 -> V_4 * V_114 ; V_69 ++ ) {
V_2 = F_56 ( V_59 , ' ' ) ;
if ( ! V_2 )
return V_61 ;
}
V_2 = F_53 ( V_59 , L_24 , ( void * ) V_30 -> V_3 ) ;
if ( ! V_2 )
return V_61 ;
return V_62 ;
}
static enum V_57
F_74 ( struct V_76 * V_77 ,
struct V_37 * V_38 ,
struct V_58 * V_59 , int V_48 , T_3 V_27 )
{
struct V_26 * V_30 = & V_38 -> V_41 ;
struct V_72 * V_46 = V_77 -> V_79 ;
int V_2 ;
int V_69 ;
if ( V_46 ) {
struct V_112 * V_75 ;
int V_48 = V_77 -> V_48 ;
V_75 = F_31 ( V_46 -> V_75 , V_48 ) ;
V_75 -> V_4 = V_30 -> V_4 ;
if ( V_30 -> V_4 < V_12 )
V_75 -> V_113 [ V_30 -> V_4 ] = V_30 -> V_3 ;
}
V_2 = F_70 ( 0 , V_59 , V_27 | V_108 ) ;
if ( V_2 != V_62 )
return V_2 ;
for ( V_69 = 0 ; V_69 < V_30 -> V_4 * V_114 ; V_69 ++ ) {
V_2 = F_56 ( V_59 , ' ' ) ;
if ( ! V_2 )
return V_61 ;
}
V_2 = F_53 ( V_59 , L_25 , ( void * ) V_30 -> V_3 ) ;
if ( ! V_2 )
return V_61 ;
return V_115 ;
}
static enum V_57
F_75 ( struct V_76 * V_77 , struct V_58 * V_59 ,
int type , unsigned long V_87 , T_3 V_27 )
{
struct V_72 * V_46 = V_77 -> V_79 ;
struct V_71 * V_52 = V_77 -> V_52 ;
int V_48 = V_77 -> V_48 ;
int V_2 ;
if ( F_59 ( V_59 , V_52 -> V_63 , V_48 , V_46 ) == V_61 )
return V_61 ;
if ( type ) {
V_2 = F_69 ( V_77 , V_87 , type , V_48 , V_52 -> V_63 , V_27 ) ;
if ( V_2 == V_61 )
return V_61 ;
}
if ( ! ( V_93 & V_94 ) )
return 0 ;
if ( V_27 & V_95 ) {
V_2 = F_67 ( V_77 -> V_96 , V_59 ) ;
if ( ! V_2 )
return V_61 ;
}
if ( V_27 & V_97 ) {
V_2 = F_52 ( V_59 , V_48 ) ;
if ( V_2 == V_61 )
return V_61 ;
}
if ( V_27 & V_98 ) {
V_2 = F_54 ( V_59 , V_52 -> V_63 ) ;
if ( V_2 == V_61 )
return V_61 ;
V_2 = F_60 ( V_59 , L_10 ) ;
if ( ! V_2 )
return V_61 ;
}
if ( V_93 & V_116 ) {
V_2 = F_57 ( V_59 , V_52 ) ;
if ( V_2 == V_61 )
return V_61 ;
}
return 0 ;
}
static int
F_76 ( struct V_76 * V_77 , T_3 V_27 ,
unsigned long V_87 , int V_4 )
{
int V_48 = V_77 -> V_48 ;
int * V_117 ;
struct V_72 * V_46 = V_77 -> V_79 ;
if ( ( V_27 & V_118 ) ||
( ! V_46 ) )
return 0 ;
V_117 = & ( F_31 ( V_46 -> V_75 , V_48 ) -> V_117 ) ;
if ( * V_117 >= 0 )
return 1 ;
if ( ( V_87 < ( unsigned long ) V_90 ) ||
( V_87 >= ( unsigned long ) V_91 ) )
return 0 ;
* V_117 = V_4 ;
return 1 ;
}
static int
F_77 ( struct V_76 * V_77 , T_3 V_27 , int V_4 )
{
int V_48 = V_77 -> V_48 ;
int * V_117 ;
struct V_72 * V_46 = V_77 -> V_79 ;
if ( ( V_27 & V_118 ) ||
( ! V_46 ) )
return 0 ;
V_117 = & ( F_31 ( V_46 -> V_75 , V_48 ) -> V_117 ) ;
if ( * V_117 == - 1 )
return 0 ;
if ( * V_117 >= V_4 ) {
* V_117 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_57
F_78 ( struct V_37 * V_119 , struct V_58 * V_59 ,
struct V_76 * V_77 , T_3 V_27 )
{
struct V_72 * V_46 = V_77 -> V_79 ;
struct V_26 * V_30 = & V_119 -> V_41 ;
struct V_55 * V_120 ;
static enum V_57 V_2 ;
int V_48 = V_77 -> V_48 ;
if ( F_76 ( V_77 , V_27 , V_30 -> V_3 , V_30 -> V_4 ) )
return V_62 ;
if ( F_75 ( V_77 , V_59 , V_40 , V_30 -> V_3 , V_27 ) )
return V_61 ;
V_120 = F_61 ( V_77 , V_119 ) ;
if ( V_120 )
V_2 = F_73 ( V_77 , V_119 , V_120 , V_59 , V_27 ) ;
else
V_2 = F_74 ( V_77 , V_119 , V_59 , V_48 , V_27 ) ;
if ( V_46 ) {
if ( V_59 -> V_121 ) {
V_46 -> V_83 = 1 ;
V_46 -> V_48 = V_48 ;
} else
V_46 -> V_83 = 0 ;
}
return V_2 ;
}
static enum V_57
F_79 ( struct V_17 * V_18 , struct V_58 * V_59 ,
struct V_71 * V_52 , struct V_76 * V_77 ,
T_3 V_27 )
{
unsigned long long V_101 = V_18 -> V_23 - V_18 -> V_6 ;
struct V_72 * V_46 = V_77 -> V_79 ;
T_2 V_63 = V_52 -> V_63 ;
int V_48 = V_77 -> V_48 ;
int V_122 = 1 ;
int V_2 ;
int V_69 ;
if ( F_77 ( V_77 , V_27 , V_18 -> V_4 ) )
return V_62 ;
if ( V_46 ) {
struct V_112 * V_75 ;
int V_48 = V_77 -> V_48 ;
V_75 = F_31 ( V_46 -> V_75 , V_48 ) ;
V_75 -> V_4 = V_18 -> V_4 - 1 ;
if ( V_18 -> V_4 < V_12 ) {
if ( V_75 -> V_113 [ V_18 -> V_4 ] != V_18 -> V_3 )
V_122 = 0 ;
V_75 -> V_113 [ V_18 -> V_4 ] = 0 ;
}
}
if ( F_75 ( V_77 , V_59 , 0 , 0 , V_27 ) )
return V_61 ;
V_2 = F_70 ( V_101 , V_59 , V_27 ) ;
if ( V_2 == V_61 )
return V_61 ;
for ( V_69 = 0 ; V_69 < V_18 -> V_4 * V_114 ; V_69 ++ ) {
V_2 = F_56 ( V_59 , ' ' ) ;
if ( ! V_2 )
return V_61 ;
}
if ( V_122 && ! ( V_27 & V_123 ) ) {
V_2 = F_60 ( V_59 , L_26 ) ;
if ( ! V_2 )
return V_61 ;
} else {
V_2 = F_53 ( V_59 , L_27 , ( void * ) V_18 -> V_3 ) ;
if ( ! V_2 )
return V_61 ;
}
if ( V_27 & V_124 ) {
V_2 = F_53 ( V_59 , L_28 ,
V_18 -> V_22 ) ;
if ( ! V_2 )
return V_61 ;
}
V_2 = F_69 ( V_77 , V_18 -> V_3 , V_56 ,
V_48 , V_63 , V_27 ) ;
if ( V_2 == V_61 )
return V_61 ;
return V_62 ;
}
static enum V_57
F_80 ( struct V_58 * V_59 , struct V_71 * V_52 ,
struct V_76 * V_77 , T_3 V_27 )
{
unsigned long V_125 = ( V_93 & V_126 ) ;
struct V_72 * V_46 = V_77 -> V_79 ;
struct V_127 * V_33 ;
int V_4 = 0 ;
int V_2 ;
int V_69 ;
if ( V_46 )
V_4 = F_31 ( V_46 -> V_75 , V_77 -> V_48 ) -> V_4 ;
if ( F_75 ( V_77 , V_59 , 0 , 0 , V_27 ) )
return V_61 ;
V_2 = F_70 ( 0 , V_59 , V_27 | V_108 ) ;
if ( V_2 != V_62 )
return V_2 ;
if ( V_4 > 0 )
for ( V_69 = 0 ; V_69 < ( V_4 + 1 ) * V_114 ; V_69 ++ ) {
V_2 = F_56 ( V_59 , ' ' ) ;
if ( ! V_2 )
return V_61 ;
}
V_2 = F_60 ( V_59 , L_29 ) ;
if ( ! V_2 )
return V_61 ;
switch ( V_77 -> V_52 -> type ) {
case V_128 :
V_2 = F_81 ( V_77 ) ;
if ( V_2 != V_62 )
return V_2 ;
break;
case V_129 :
V_2 = F_82 ( V_77 ) ;
if ( V_2 != V_62 )
return V_2 ;
break;
default:
V_33 = F_83 ( V_52 -> type ) ;
if ( ! V_33 )
return V_92 ;
V_2 = V_33 -> V_130 -> V_18 ( V_77 , V_125 , V_33 ) ;
if ( V_2 != V_62 )
return V_2 ;
}
if ( V_59 -> V_35 [ V_59 -> V_68 - 1 ] == '\n' ) {
V_59 -> V_35 [ V_59 -> V_68 - 1 ] = '\0' ;
V_59 -> V_68 -- ;
}
V_2 = F_60 ( V_59 , L_30 ) ;
if ( ! V_2 )
return V_61 ;
return V_62 ;
}
enum V_57
F_84 ( struct V_76 * V_77 , T_3 V_27 )
{
struct V_37 * V_119 ;
struct V_72 * V_46 = V_77 -> V_79 ;
struct V_71 * V_38 = V_77 -> V_52 ;
struct V_58 * V_59 = & V_77 -> V_89 ;
int V_48 = V_77 -> V_48 ;
int V_2 ;
if ( V_46 && F_31 ( V_46 -> V_75 , V_48 ) -> V_131 ) {
F_31 ( V_46 -> V_75 , V_48 ) -> V_131 = 0 ;
return V_62 ;
}
if ( V_46 && V_46 -> V_83 ) {
V_119 = & V_46 -> V_52 ;
V_77 -> V_48 = V_46 -> V_48 ;
V_2 = F_78 ( V_119 , V_59 , V_77 , V_27 ) ;
if ( V_2 == V_62 && V_77 -> V_48 != V_48 ) {
F_31 ( V_46 -> V_75 , V_77 -> V_48 ) -> V_131 = 1 ;
V_2 = V_115 ;
}
V_77 -> V_48 = V_48 ;
return V_2 ;
}
switch ( V_38 -> type ) {
case V_40 : {
struct V_37 V_132 ;
F_85 ( V_119 , V_38 ) ;
V_132 = * V_119 ;
return F_78 ( & V_132 , V_59 , V_77 , V_27 ) ;
}
case V_56 : {
struct V_55 * V_119 ;
F_85 ( V_119 , V_38 ) ;
return F_79 ( & V_119 -> V_2 , V_59 , V_38 , V_77 , V_27 ) ;
}
case V_133 :
case V_134 :
return V_92 ;
default:
return F_80 ( V_59 , V_38 , V_77 , V_27 ) ;
}
return V_62 ;
}
static enum V_57
F_86 ( struct V_76 * V_77 )
{
return F_84 ( V_77 , V_135 . V_136 ) ;
}
static enum V_57
F_87 ( struct V_76 * V_77 , int V_27 ,
struct V_127 * V_33 )
{
return F_86 ( V_77 ) ;
}
static void F_88 ( struct V_137 * V_59 , T_3 V_27 )
{
static const char V_67 [] = L_31
L_32
L_33 ;
int V_138 = 0 ;
if ( V_27 & V_95 )
V_138 += 16 ;
if ( V_27 & V_97 )
V_138 += 4 ;
if ( V_27 & V_98 )
V_138 += 17 ;
F_89 ( V_59 , L_34 , V_138 , V_67 ) ;
F_89 ( V_59 , L_35 , V_138 , V_67 ) ;
F_89 ( V_59 , L_36 , V_138 , V_67 ) ;
F_89 ( V_59 , L_37 , V_138 , V_67 ) ;
F_89 ( V_59 , L_38 , V_138 , V_67 ) ;
}
static void F_90 ( struct V_137 * V_59 , T_3 V_27 )
{
int V_139 = V_93 & V_116 ;
if ( V_139 )
F_88 ( V_59 , V_27 ) ;
F_89 ( V_59 , L_39 ) ;
if ( V_27 & V_95 )
F_89 ( V_59 , L_40 ) ;
if ( V_27 & V_97 )
F_89 ( V_59 , L_41 ) ;
if ( V_27 & V_98 )
F_89 ( V_59 , L_42 ) ;
if ( V_139 )
F_89 ( V_59 , L_43 ) ;
if ( V_27 & V_106 )
F_89 ( V_59 , L_44 ) ;
F_89 ( V_59 , L_45 ) ;
F_89 ( V_59 , L_39 ) ;
if ( V_27 & V_95 )
F_89 ( V_59 , L_46 ) ;
if ( V_27 & V_97 )
F_89 ( V_59 , L_47 ) ;
if ( V_27 & V_98 )
F_89 ( V_59 , L_48 ) ;
if ( V_139 )
F_89 ( V_59 , L_43 ) ;
if ( V_27 & V_106 )
F_89 ( V_59 , L_49 ) ;
F_89 ( V_59 , L_50 ) ;
}
static void F_91 ( struct V_137 * V_59 )
{
F_92 ( V_59 , V_135 . V_136 ) ;
}
void F_92 ( struct V_137 * V_59 , T_3 V_27 )
{
struct V_76 * V_77 = V_59 -> V_79 ;
if ( ! ( V_93 & V_94 ) )
return;
if ( V_93 & V_116 ) {
if ( F_93 ( V_77 ) )
return;
F_94 ( V_59 , V_77 ) ;
}
F_90 ( V_59 , V_27 ) ;
}
void F_95 ( struct V_76 * V_77 )
{
struct V_72 * V_46 ;
int V_48 ;
V_77 -> V_79 = NULL ;
V_46 = F_96 ( sizeof( * V_46 ) , V_140 ) ;
if ( ! V_46 )
goto V_141;
V_46 -> V_75 = F_97 ( struct V_112 ) ;
if ( ! V_46 -> V_75 )
goto V_142;
F_98 (cpu) {
T_2 * V_63 = & ( F_31 ( V_46 -> V_75 , V_48 ) -> V_74 ) ;
int * V_4 = & ( F_31 ( V_46 -> V_75 , V_48 ) -> V_4 ) ;
int * V_131 = & ( F_31 ( V_46 -> V_75 , V_48 ) -> V_131 ) ;
int * V_117 = & ( F_31 ( V_46 -> V_75 , V_48 ) -> V_117 ) ;
* V_63 = - 1 ;
* V_4 = 0 ;
* V_131 = 0 ;
* V_117 = - 1 ;
}
V_77 -> V_79 = V_46 ;
return;
V_142:
F_99 ( V_46 ) ;
V_141:
F_100 ( L_51 ) ;
}
void F_101 ( struct V_76 * V_77 )
{
struct V_72 * V_46 = V_77 -> V_79 ;
if ( V_46 ) {
F_102 ( V_46 -> V_75 ) ;
F_99 ( V_46 ) ;
}
}
static int
F_103 ( struct V_24 * V_25 , T_3 V_143 , T_3 V_144 , int V_145 )
{
if ( V_144 == V_118 )
V_42 = ! V_145 ;
return 0 ;
}
static T_5
F_104 ( struct V_146 * V_147 , const char T_6 * V_148 , T_4 V_149 ,
T_7 * V_150 )
{
unsigned long V_136 ;
int V_2 ;
V_2 = F_105 ( V_148 , V_149 , 10 , & V_136 ) ;
if ( V_2 )
return V_2 ;
V_49 = V_136 ;
* V_150 += V_149 ;
return V_149 ;
}
static T_5
F_106 ( struct V_146 * V_147 , char T_6 * V_148 , T_4 V_149 ,
T_7 * V_150 )
{
char V_151 [ 15 ] ;
int V_152 ;
V_152 = sprintf ( V_151 , L_52 , V_49 ) ;
return F_107 ( V_148 , V_149 , V_150 , V_151 , V_152 ) ;
}
static T_8 int F_108 ( void )
{
struct V_153 * V_154 ;
V_154 = F_109 () ;
if ( ! V_154 )
return 0 ;
F_110 ( L_53 , 0644 , V_154 ,
NULL , & V_155 ) ;
return 0 ;
}
static T_8 int F_111 ( void )
{
V_60 = snprintf ( NULL , 0 , L_4 , V_156 - 1 ) ;
if ( ! F_112 ( & V_157 ) ) {
F_100 ( L_54 ) ;
return 1 ;
}
if ( ! F_112 ( & V_158 ) ) {
F_100 ( L_54 ) ;
return 1 ;
}
return F_113 ( & V_159 ) ;
}
