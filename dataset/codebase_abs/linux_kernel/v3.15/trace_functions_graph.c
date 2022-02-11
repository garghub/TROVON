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
if ( V_7 -> V_10 < - 1 )
return - V_9 ;
V_5 = F_4 () ;
V_6 = ++ V_7 -> V_10 ;
if ( F_5 ( V_2 ) )
V_7 -> V_10 -= V_13 ;
F_6 () ;
V_7 -> V_8 [ V_6 ] . V_1 = V_1 ;
V_7 -> V_8 [ V_6 ] . V_2 = V_2 ;
V_7 -> V_8 [ V_6 ] . V_5 = V_5 ;
V_7 -> V_8 [ V_6 ] . V_14 = 0 ;
V_7 -> V_8 [ V_6 ] . V_15 = V_4 ;
* V_3 = V_7 -> V_10 ;
return 0 ;
}
static void
F_7 ( struct V_16 * V_17 , unsigned long * V_1 ,
unsigned long V_4 )
{
int V_6 ;
V_6 = V_7 -> V_10 ;
if ( V_6 < 0 )
V_6 += V_13 ;
if ( F_8 ( V_6 < 0 || V_6 >= V_11 ) ) {
F_9 () ;
F_10 ( 1 ) ;
* V_1 = ( unsigned long ) V_18 ;
return;
}
#if F_11 ( V_19 ) && ! F_11 ( V_20 )
if ( F_8 ( V_7 -> V_8 [ V_6 ] . V_15 != V_4 ) ) {
F_9 () ;
F_12 ( 1 , L_1
L_2 ,
V_7 -> V_8 [ V_6 ] . V_15 ,
V_4 ,
( void * ) V_7 -> V_8 [ V_6 ] . V_2 ,
V_7 -> V_8 [ V_6 ] . V_1 ) ;
* V_1 = ( unsigned long ) V_18 ;
return;
}
#endif
* V_1 = V_7 -> V_8 [ V_6 ] . V_1 ;
V_17 -> V_2 = V_7 -> V_8 [ V_6 ] . V_2 ;
V_17 -> V_5 = V_7 -> V_8 [ V_6 ] . V_5 ;
V_17 -> V_21 = F_13 ( & V_7 -> V_12 ) ;
V_17 -> V_3 = V_6 ;
}
unsigned long F_14 ( unsigned long V_4 )
{
struct V_16 V_17 ;
unsigned long V_1 ;
F_7 ( & V_17 , & V_1 , V_4 ) ;
V_17 . V_22 = F_4 () ;
F_6 () ;
V_7 -> V_10 -- ;
if ( V_7 -> V_10 < - 1 ) {
V_7 -> V_10 += V_13 ;
return V_1 ;
}
F_15 ( & V_17 ) ;
if ( F_8 ( ! V_1 ) ) {
F_9 () ;
F_10 ( 1 ) ;
V_1 = ( unsigned long ) V_18 ;
}
return V_1 ;
}
int F_16 ( struct V_23 * V_24 ,
struct V_25 * V_17 ,
unsigned long V_26 ,
int V_27 )
{
struct V_28 * V_29 = & V_30 ;
struct V_31 * V_32 ;
struct V_33 * V_34 = V_24 -> V_35 . V_34 ;
struct V_36 * V_37 ;
if ( F_8 ( F_17 ( V_38 ) ) )
return 0 ;
V_32 = F_18 ( V_34 , V_39 ,
sizeof( * V_37 ) , V_26 , V_27 ) ;
if ( ! V_32 )
return 0 ;
V_37 = F_19 ( V_32 ) ;
V_37 -> V_40 = * V_17 ;
if ( ! F_20 ( V_29 , V_37 , V_34 , V_32 ) )
F_21 ( V_34 , V_32 ) ;
return 1 ;
}
static inline int F_22 ( void )
{
if ( ! V_41 || F_23 ( V_42 ) )
return 0 ;
return F_24 () ;
}
int F_25 ( struct V_25 * V_17 )
{
struct V_23 * V_24 = V_43 ;
struct V_44 * V_45 ;
unsigned long V_26 ;
long V_46 ;
int V_1 ;
int V_47 ;
int V_27 ;
if ( ! F_26 ( V_7 ) )
return 0 ;
if ( ( ! ( V_17 -> V_3 || F_27 ( V_17 -> V_2 ) ) ||
F_22 () ) || ( V_17 -> V_3 < 0 ) ||
( V_48 && V_17 -> V_3 >= V_48 ) )
return 0 ;
if ( F_5 ( V_17 -> V_2 ) )
return 1 ;
F_28 ( V_26 ) ;
V_47 = F_29 () ;
V_45 = F_30 ( V_24 -> V_35 . V_45 , V_47 ) ;
V_46 = F_31 ( & V_45 -> V_46 ) ;
if ( F_32 ( V_46 == 1 ) ) {
V_27 = F_33 () ;
V_1 = F_16 ( V_24 , V_17 , V_26 , V_27 ) ;
} else {
V_1 = 0 ;
}
F_34 ( & V_45 -> V_46 ) ;
F_35 ( V_26 ) ;
return V_1 ;
}
int F_36 ( struct V_25 * V_17 )
{
if ( V_49 )
return 1 ;
else
return F_25 ( V_17 ) ;
}
static void
F_37 ( struct V_23 * V_24 ,
unsigned long V_50 , unsigned long V_26 , int V_27 )
{
T_1 time = F_4 () ;
struct V_25 V_51 = {
. V_2 = V_50 ,
. V_3 = 0 ,
} ;
struct V_16 V_1 = {
. V_2 = V_50 ,
. V_3 = 0 ,
. V_5 = time ,
. V_22 = time ,
} ;
F_16 ( V_24 , & V_51 , V_26 , V_27 ) ;
F_38 ( V_24 , & V_1 , V_26 , V_27 ) ;
}
void
F_39 ( struct V_23 * V_24 ,
unsigned long V_50 , unsigned long V_52 ,
unsigned long V_26 , int V_27 )
{
F_37 ( V_24 , V_50 , V_26 , V_27 ) ;
}
void F_38 ( struct V_23 * V_24 ,
struct V_16 * V_17 ,
unsigned long V_26 ,
int V_27 )
{
struct V_28 * V_29 = & V_53 ;
struct V_31 * V_32 ;
struct V_33 * V_34 = V_24 -> V_35 . V_34 ;
struct V_54 * V_37 ;
if ( F_8 ( F_17 ( V_38 ) ) )
return;
V_32 = F_18 ( V_34 , V_55 ,
sizeof( * V_37 ) , V_26 , V_27 ) ;
if ( ! V_32 )
return;
V_37 = F_19 ( V_32 ) ;
V_37 -> V_1 = * V_17 ;
if ( ! F_20 ( V_29 , V_37 , V_34 , V_32 ) )
F_21 ( V_34 , V_32 ) ;
}
void F_40 ( struct V_16 * V_17 )
{
struct V_23 * V_24 = V_43 ;
struct V_44 * V_45 ;
unsigned long V_26 ;
long V_46 ;
int V_47 ;
int V_27 ;
F_28 ( V_26 ) ;
V_47 = F_29 () ;
V_45 = F_30 ( V_24 -> V_35 . V_45 , V_47 ) ;
V_46 = F_31 ( & V_45 -> V_46 ) ;
if ( F_32 ( V_46 == 1 ) ) {
V_27 = F_33 () ;
F_38 ( V_24 , V_17 , V_26 , V_27 ) ;
}
F_34 ( & V_45 -> V_46 ) ;
F_35 ( V_26 ) ;
}
void F_41 ( struct V_23 * V_24 )
{
V_43 = V_24 ;
F_42 () ;
}
void F_43 ( struct V_16 * V_17 )
{
if ( V_49 &&
( V_17 -> V_22 - V_17 -> V_5 < V_49 ) )
return;
else
F_40 ( V_17 ) ;
}
static int F_44 ( struct V_23 * V_24 )
{
int V_1 ;
F_41 ( V_24 ) ;
if ( V_49 )
V_1 = F_45 ( & F_43 ,
& F_36 ) ;
else
V_1 = F_45 ( & F_40 ,
& F_25 ) ;
if ( V_1 )
return V_1 ;
F_46 () ;
return 0 ;
}
static void F_47 ( struct V_23 * V_24 )
{
F_48 () ;
F_49 () ;
}
static enum V_56
F_50 ( struct V_57 * V_58 , int V_47 )
{
int V_1 ;
V_1 = F_51 ( V_58 , L_3 , V_59 , V_47 ) ;
if ( ! V_1 )
return V_60 ;
return V_61 ;
}
static enum V_56
F_52 ( struct V_57 * V_58 , T_2 V_62 )
{
char V_63 [ V_64 ] ;
char V_65 [ 11 ] ;
int V_66 = 0 ;
int V_1 ;
int V_67 ;
int V_68 ;
F_53 ( V_62 , V_63 ) ;
V_63 [ 7 ] = '\0' ;
sprintf ( V_65 , L_4 , V_62 ) ;
V_67 = strlen ( V_63 ) + strlen ( V_65 ) + 1 ;
if ( V_67 < V_69 )
V_66 = V_69 - V_67 ;
for ( V_68 = 0 ; V_68 < V_66 / 2 ; V_68 ++ ) {
V_1 = F_54 ( V_58 , ' ' ) ;
if ( ! V_1 )
return V_60 ;
}
V_1 = F_51 ( V_58 , L_5 , V_63 , V_65 ) ;
if ( ! V_1 )
return V_60 ;
for ( V_68 = 0 ; V_68 < V_66 - ( V_66 / 2 ) ; V_68 ++ ) {
V_1 = F_54 ( V_58 , ' ' ) ;
if ( ! V_1 )
return V_60 ;
}
return V_61 ;
}
static enum V_56
F_55 ( struct V_57 * V_58 , struct V_70 * V_37 )
{
if ( ! F_54 ( V_58 , ' ' ) )
return 0 ;
return F_56 ( V_58 , V_37 ) ;
}
static enum V_56
F_57 ( struct V_57 * V_58 , T_2 V_62 , int V_47 , struct V_71 * V_45 )
{
T_2 V_72 ;
T_2 * V_73 ;
int V_1 ;
if ( ! V_45 )
return V_61 ;
V_73 = & ( F_30 ( V_45 -> V_74 , V_47 ) -> V_73 ) ;
if ( * V_73 == V_62 )
return V_61 ;
V_72 = * V_73 ;
* V_73 = V_62 ;
if ( V_72 == - 1 )
return V_61 ;
V_1 = F_58 ( V_58 ,
L_6 ) ;
if ( ! V_1 )
return V_60 ;
V_1 = F_50 ( V_58 , V_47 ) ;
if ( V_1 == V_60 )
return V_60 ;
V_1 = F_52 ( V_58 , V_72 ) ;
if ( V_1 == V_60 )
return V_60 ;
V_1 = F_58 ( V_58 , L_7 ) ;
if ( ! V_1 )
return V_60 ;
V_1 = F_52 ( V_58 , V_62 ) ;
if ( V_1 == V_60 )
return V_60 ;
V_1 = F_58 ( V_58 ,
L_8 ) ;
if ( ! V_1 )
return V_60 ;
return V_61 ;
}
static struct V_54 *
F_59 ( struct V_75 * V_76 ,
struct V_36 * V_77 )
{
struct V_71 * V_45 = V_76 -> V_78 ;
struct V_79 * V_80 = NULL ;
struct V_31 * V_32 ;
struct V_54 * V_81 ;
if ( V_45 && V_45 -> V_82 ) {
V_77 = & V_45 -> V_51 ;
V_81 = & V_45 -> V_1 ;
} else {
V_80 = F_60 ( V_76 , V_76 -> V_47 ) ;
if ( V_80 )
V_32 = F_61 ( V_80 , NULL ) ;
else {
F_62 ( V_76 -> V_35 -> V_34 , V_76 -> V_47 ,
NULL , NULL ) ;
V_32 = F_63 ( V_76 -> V_35 -> V_34 , V_76 -> V_47 ,
NULL , NULL ) ;
}
if ( ! V_32 )
return NULL ;
V_81 = F_19 ( V_32 ) ;
if ( V_45 ) {
V_45 -> V_51 = * V_77 ;
if ( V_81 -> V_51 . type == V_55 )
V_45 -> V_1 = * V_81 ;
else
V_45 -> V_1 . V_51 . type = V_81 -> V_51 . type ;
}
}
if ( V_81 -> V_51 . type != V_55 )
return NULL ;
if ( V_77 -> V_51 . V_62 != V_81 -> V_51 . V_62 ||
V_77 -> V_40 . V_2 != V_81 -> V_1 . V_2 )
return NULL ;
if ( V_80 )
F_64 ( V_80 , NULL ) ;
return V_81 ;
}
static int F_65 ( T_1 V_83 , struct V_57 * V_58 )
{
unsigned long V_84 ;
V_84 = F_66 ( V_83 , V_85 ) ;
V_84 /= 1000 ;
return F_51 ( V_58 , L_9 ,
( unsigned long ) V_83 , V_84 ) ;
}
static enum V_56
F_67 ( struct V_75 * V_76 , unsigned long V_86 ,
enum V_87 type , int V_47 , T_2 V_62 , T_3 V_26 )
{
int V_1 ;
struct V_57 * V_58 = & V_76 -> V_88 ;
if ( V_86 < ( unsigned long ) V_89 ||
V_86 >= ( unsigned long ) V_90 )
return V_91 ;
if ( V_92 & V_93 ) {
if ( V_26 & V_94 ) {
V_1 = F_65 ( V_76 -> V_95 , V_58 ) ;
if ( ! V_1 )
return V_60 ;
}
if ( V_26 & V_96 ) {
V_1 = F_50 ( V_58 , V_47 ) ;
if ( V_1 == V_60 )
return V_60 ;
}
if ( V_26 & V_97 ) {
V_1 = F_52 ( V_58 , V_62 ) ;
if ( V_1 == V_60 )
return V_60 ;
V_1 = F_58 ( V_58 , L_10 ) ;
if ( ! V_1 )
return V_60 ;
}
}
V_1 = F_68 ( 0 , V_58 , V_26 | V_98 ) ;
if ( V_1 != V_61 )
return V_1 ;
if ( type == V_39 )
V_1 = F_58 ( V_58 , L_11 ) ;
else
V_1 = F_58 ( V_58 , L_12 ) ;
if ( ! V_1 )
return V_60 ;
V_1 = F_68 ( 0 , V_58 , V_26 | V_99 ) ;
if ( V_1 != V_61 )
return V_1 ;
V_1 = F_54 ( V_58 , '\n' ) ;
if ( ! V_1 )
return V_60 ;
return V_61 ;
}
enum V_56
F_69 ( unsigned long long V_100 , struct V_57 * V_58 )
{
unsigned long V_101 = F_66 ( V_100 , 1000 ) ;
char V_102 [ 21 ] ;
char V_103 [ 5 ] ;
int V_1 , V_67 ;
int V_68 ;
sprintf ( V_102 , L_13 , ( unsigned long ) V_100 ) ;
V_1 = F_51 ( V_58 , L_14 , V_102 ) ;
if ( ! V_1 )
return V_60 ;
V_67 = strlen ( V_102 ) ;
if ( V_67 < 7 ) {
T_4 V_104 = F_70 ( T_4 , sizeof( V_103 ) , 8UL - V_67 ) ;
snprintf ( V_103 , V_104 , L_15 , V_101 ) ;
V_1 = F_51 ( V_58 , L_16 , V_103 ) ;
if ( ! V_1 )
return V_60 ;
V_67 += strlen ( V_103 ) ;
}
V_1 = F_58 ( V_58 , L_17 ) ;
if ( ! V_1 )
return V_60 ;
for ( V_68 = V_67 ; V_68 < 7 ; V_68 ++ ) {
V_1 = F_54 ( V_58 , ' ' ) ;
if ( ! V_1 )
return V_60 ;
}
return V_61 ;
}
static enum V_56
F_68 ( unsigned long long V_100 , struct V_57 * V_58 ,
T_3 V_26 )
{
int V_1 = - 1 ;
if ( ! ( V_26 & V_105 ) ||
! ( V_92 & V_93 ) )
return V_61 ;
switch ( V_26 & V_106 ) {
case V_107 :
V_1 = F_58 ( V_58 , L_18 ) ;
return V_1 ? V_61 : V_60 ;
case V_98 :
V_1 = F_58 ( V_58 , L_19 ) ;
return V_1 ? V_61 : V_60 ;
case V_99 :
V_1 = F_58 ( V_58 , L_20 ) ;
return V_1 ? V_61 : V_60 ;
}
if ( V_26 & V_108 ) {
if ( V_100 > 100000ULL )
V_1 = F_58 ( V_58 , L_21 ) ;
else if ( V_100 > 10000ULL )
V_1 = F_58 ( V_58 , L_22 ) ;
}
if ( V_1 == - 1 )
V_1 = F_58 ( V_58 , L_19 ) ;
if ( ! V_1 )
return V_60 ;
V_1 = F_69 ( V_100 , V_58 ) ;
if ( V_1 != V_61 )
return V_1 ;
V_1 = F_58 ( V_58 , L_23 ) ;
if ( ! V_1 )
return V_60 ;
return V_61 ;
}
static enum V_56
F_71 ( struct V_75 * V_76 ,
struct V_36 * V_37 ,
struct V_54 * V_109 ,
struct V_57 * V_58 , T_3 V_26 )
{
struct V_71 * V_45 = V_76 -> V_78 ;
struct V_16 * V_110 ;
struct V_25 * V_29 ;
unsigned long long V_100 ;
int V_1 ;
int V_68 ;
V_110 = & V_109 -> V_1 ;
V_29 = & V_37 -> V_40 ;
V_100 = V_110 -> V_22 - V_110 -> V_5 ;
if ( V_45 ) {
struct V_111 * V_74 ;
int V_47 = V_76 -> V_47 ;
V_74 = F_30 ( V_45 -> V_74 , V_47 ) ;
V_74 -> V_3 = V_29 -> V_3 - 1 ;
if ( V_29 -> V_3 < V_11 )
V_74 -> V_112 [ V_29 -> V_3 ] = 0 ;
}
V_1 = F_68 ( V_100 , V_58 , V_26 ) ;
if ( V_1 == V_60 )
return V_60 ;
for ( V_68 = 0 ; V_68 < V_29 -> V_3 * V_113 ; V_68 ++ ) {
V_1 = F_54 ( V_58 , ' ' ) ;
if ( ! V_1 )
return V_60 ;
}
V_1 = F_51 ( V_58 , L_24 , ( void * ) V_29 -> V_2 ) ;
if ( ! V_1 )
return V_60 ;
return V_61 ;
}
static enum V_56
F_72 ( struct V_75 * V_76 ,
struct V_36 * V_37 ,
struct V_57 * V_58 , int V_47 , T_3 V_26 )
{
struct V_25 * V_29 = & V_37 -> V_40 ;
struct V_71 * V_45 = V_76 -> V_78 ;
int V_1 ;
int V_68 ;
if ( V_45 ) {
struct V_111 * V_74 ;
int V_47 = V_76 -> V_47 ;
V_74 = F_30 ( V_45 -> V_74 , V_47 ) ;
V_74 -> V_3 = V_29 -> V_3 ;
if ( V_29 -> V_3 < V_11 )
V_74 -> V_112 [ V_29 -> V_3 ] = V_29 -> V_2 ;
}
V_1 = F_68 ( 0 , V_58 , V_26 | V_107 ) ;
if ( V_1 != V_61 )
return V_1 ;
for ( V_68 = 0 ; V_68 < V_29 -> V_3 * V_113 ; V_68 ++ ) {
V_1 = F_54 ( V_58 , ' ' ) ;
if ( ! V_1 )
return V_60 ;
}
V_1 = F_51 ( V_58 , L_25 , ( void * ) V_29 -> V_2 ) ;
if ( ! V_1 )
return V_60 ;
return V_114 ;
}
static enum V_56
F_73 ( struct V_75 * V_76 , struct V_57 * V_58 ,
int type , unsigned long V_86 , T_3 V_26 )
{
struct V_71 * V_45 = V_76 -> V_78 ;
struct V_70 * V_51 = V_76 -> V_51 ;
int V_47 = V_76 -> V_47 ;
int V_1 ;
if ( F_57 ( V_58 , V_51 -> V_62 , V_47 , V_45 ) == V_60 )
return V_60 ;
if ( type ) {
V_1 = F_67 ( V_76 , V_86 , type , V_47 , V_51 -> V_62 , V_26 ) ;
if ( V_1 == V_60 )
return V_60 ;
}
if ( ! ( V_92 & V_93 ) )
return 0 ;
if ( V_26 & V_94 ) {
V_1 = F_65 ( V_76 -> V_95 , V_58 ) ;
if ( ! V_1 )
return V_60 ;
}
if ( V_26 & V_96 ) {
V_1 = F_50 ( V_58 , V_47 ) ;
if ( V_1 == V_60 )
return V_60 ;
}
if ( V_26 & V_97 ) {
V_1 = F_52 ( V_58 , V_51 -> V_62 ) ;
if ( V_1 == V_60 )
return V_60 ;
V_1 = F_58 ( V_58 , L_10 ) ;
if ( ! V_1 )
return V_60 ;
}
if ( V_92 & V_115 ) {
V_1 = F_55 ( V_58 , V_51 ) ;
if ( V_1 == V_60 )
return V_60 ;
}
return 0 ;
}
static int
F_74 ( struct V_75 * V_76 , T_3 V_26 ,
unsigned long V_86 , int V_3 )
{
int V_47 = V_76 -> V_47 ;
int * V_116 ;
struct V_71 * V_45 = V_76 -> V_78 ;
if ( ( V_26 & V_117 ) ||
( ! V_45 ) )
return 0 ;
V_116 = & ( F_30 ( V_45 -> V_74 , V_47 ) -> V_116 ) ;
if ( * V_116 >= 0 )
return 1 ;
if ( ( V_86 < ( unsigned long ) V_89 ) ||
( V_86 >= ( unsigned long ) V_90 ) )
return 0 ;
* V_116 = V_3 ;
return 1 ;
}
static int
F_75 ( struct V_75 * V_76 , T_3 V_26 , int V_3 )
{
int V_47 = V_76 -> V_47 ;
int * V_116 ;
struct V_71 * V_45 = V_76 -> V_78 ;
if ( ( V_26 & V_117 ) ||
( ! V_45 ) )
return 0 ;
V_116 = & ( F_30 ( V_45 -> V_74 , V_47 ) -> V_116 ) ;
if ( * V_116 == - 1 )
return 0 ;
if ( * V_116 >= V_3 ) {
* V_116 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_56
F_76 ( struct V_36 * V_118 , struct V_57 * V_58 ,
struct V_75 * V_76 , T_3 V_26 )
{
struct V_71 * V_45 = V_76 -> V_78 ;
struct V_25 * V_29 = & V_118 -> V_40 ;
struct V_54 * V_119 ;
static enum V_56 V_1 ;
int V_47 = V_76 -> V_47 ;
if ( F_74 ( V_76 , V_26 , V_29 -> V_2 , V_29 -> V_3 ) )
return V_61 ;
if ( F_73 ( V_76 , V_58 , V_39 , V_29 -> V_2 , V_26 ) )
return V_60 ;
V_119 = F_59 ( V_76 , V_118 ) ;
if ( V_119 )
V_1 = F_71 ( V_76 , V_118 , V_119 , V_58 , V_26 ) ;
else
V_1 = F_72 ( V_76 , V_118 , V_58 , V_47 , V_26 ) ;
if ( V_45 ) {
if ( V_58 -> V_120 ) {
V_45 -> V_82 = 1 ;
V_45 -> V_47 = V_47 ;
} else
V_45 -> V_82 = 0 ;
}
return V_1 ;
}
static enum V_56
F_77 ( struct V_16 * V_17 , struct V_57 * V_58 ,
struct V_70 * V_51 , struct V_75 * V_76 ,
T_3 V_26 )
{
unsigned long long V_100 = V_17 -> V_22 - V_17 -> V_5 ;
struct V_71 * V_45 = V_76 -> V_78 ;
T_2 V_62 = V_51 -> V_62 ;
int V_47 = V_76 -> V_47 ;
int V_121 = 1 ;
int V_1 ;
int V_68 ;
if ( F_75 ( V_76 , V_26 , V_17 -> V_3 ) )
return V_61 ;
if ( V_45 ) {
struct V_111 * V_74 ;
int V_47 = V_76 -> V_47 ;
V_74 = F_30 ( V_45 -> V_74 , V_47 ) ;
V_74 -> V_3 = V_17 -> V_3 - 1 ;
if ( V_17 -> V_3 < V_11 ) {
if ( V_74 -> V_112 [ V_17 -> V_3 ] != V_17 -> V_2 )
V_121 = 0 ;
V_74 -> V_112 [ V_17 -> V_3 ] = 0 ;
}
}
if ( F_73 ( V_76 , V_58 , 0 , 0 , V_26 ) )
return V_60 ;
V_1 = F_68 ( V_100 , V_58 , V_26 ) ;
if ( V_1 == V_60 )
return V_60 ;
for ( V_68 = 0 ; V_68 < V_17 -> V_3 * V_113 ; V_68 ++ ) {
V_1 = F_54 ( V_58 , ' ' ) ;
if ( ! V_1 )
return V_60 ;
}
if ( V_121 ) {
V_1 = F_58 ( V_58 , L_26 ) ;
if ( ! V_1 )
return V_60 ;
} else {
V_1 = F_51 ( V_58 , L_27 , ( void * ) V_17 -> V_2 ) ;
if ( ! V_1 )
return V_60 ;
}
if ( V_26 & V_122 ) {
V_1 = F_51 ( V_58 , L_28 ,
V_17 -> V_21 ) ;
if ( ! V_1 )
return V_60 ;
}
V_1 = F_67 ( V_76 , V_17 -> V_2 , V_55 ,
V_47 , V_62 , V_26 ) ;
if ( V_1 == V_60 )
return V_60 ;
return V_61 ;
}
static enum V_56
F_78 ( struct V_57 * V_58 , struct V_70 * V_51 ,
struct V_75 * V_76 , T_3 V_26 )
{
unsigned long V_123 = ( V_92 & V_124 ) ;
struct V_71 * V_45 = V_76 -> V_78 ;
struct V_125 * V_32 ;
int V_3 = 0 ;
int V_1 ;
int V_68 ;
if ( V_45 )
V_3 = F_30 ( V_45 -> V_74 , V_76 -> V_47 ) -> V_3 ;
if ( F_73 ( V_76 , V_58 , 0 , 0 , V_26 ) )
return V_60 ;
V_1 = F_68 ( 0 , V_58 , V_26 | V_107 ) ;
if ( V_1 != V_61 )
return V_1 ;
if ( V_3 > 0 )
for ( V_68 = 0 ; V_68 < ( V_3 + 1 ) * V_113 ; V_68 ++ ) {
V_1 = F_54 ( V_58 , ' ' ) ;
if ( ! V_1 )
return V_60 ;
}
V_1 = F_58 ( V_58 , L_29 ) ;
if ( ! V_1 )
return V_60 ;
switch ( V_76 -> V_51 -> type ) {
case V_126 :
V_1 = F_79 ( V_76 ) ;
if ( V_1 != V_61 )
return V_1 ;
break;
case V_127 :
V_1 = F_80 ( V_76 ) ;
if ( V_1 != V_61 )
return V_1 ;
break;
default:
V_32 = F_81 ( V_51 -> type ) ;
if ( ! V_32 )
return V_91 ;
V_1 = V_32 -> V_128 -> V_17 ( V_76 , V_123 , V_32 ) ;
if ( V_1 != V_61 )
return V_1 ;
}
if ( V_58 -> V_34 [ V_58 -> V_67 - 1 ] == '\n' ) {
V_58 -> V_34 [ V_58 -> V_67 - 1 ] = '\0' ;
V_58 -> V_67 -- ;
}
V_1 = F_58 ( V_58 , L_30 ) ;
if ( ! V_1 )
return V_60 ;
return V_61 ;
}
enum V_56
F_82 ( struct V_75 * V_76 , T_3 V_26 )
{
struct V_36 * V_118 ;
struct V_71 * V_45 = V_76 -> V_78 ;
struct V_70 * V_37 = V_76 -> V_51 ;
struct V_57 * V_58 = & V_76 -> V_88 ;
int V_47 = V_76 -> V_47 ;
int V_1 ;
if ( V_45 && F_30 ( V_45 -> V_74 , V_47 ) -> V_129 ) {
F_30 ( V_45 -> V_74 , V_47 ) -> V_129 = 0 ;
return V_61 ;
}
if ( V_45 && V_45 -> V_82 ) {
V_118 = & V_45 -> V_51 ;
V_76 -> V_47 = V_45 -> V_47 ;
V_1 = F_76 ( V_118 , V_58 , V_76 , V_26 ) ;
if ( V_1 == V_61 && V_76 -> V_47 != V_47 ) {
F_30 ( V_45 -> V_74 , V_76 -> V_47 ) -> V_129 = 1 ;
V_1 = V_114 ;
}
V_76 -> V_47 = V_47 ;
return V_1 ;
}
switch ( V_37 -> type ) {
case V_39 : {
struct V_36 V_130 ;
F_83 ( V_118 , V_37 ) ;
V_130 = * V_118 ;
return F_76 ( & V_130 , V_58 , V_76 , V_26 ) ;
}
case V_55 : {
struct V_54 * V_118 ;
F_83 ( V_118 , V_37 ) ;
return F_77 ( & V_118 -> V_1 , V_58 , V_37 , V_76 , V_26 ) ;
}
case V_131 :
case V_132 :
return V_91 ;
default:
return F_78 ( V_58 , V_37 , V_76 , V_26 ) ;
}
return V_61 ;
}
static enum V_56
F_84 ( struct V_75 * V_76 )
{
return F_82 ( V_76 , V_133 . V_134 ) ;
}
static enum V_56
F_85 ( struct V_75 * V_76 , int V_26 ,
struct V_125 * V_32 )
{
return F_84 ( V_76 ) ;
}
static void F_86 ( struct V_135 * V_58 , T_3 V_26 )
{
static const char V_66 [] = L_31
L_32
L_33 ;
int V_136 = 0 ;
if ( V_26 & V_94 )
V_136 += 16 ;
if ( V_26 & V_96 )
V_136 += 4 ;
if ( V_26 & V_97 )
V_136 += 17 ;
F_87 ( V_58 , L_34 , V_136 , V_66 ) ;
F_87 ( V_58 , L_35 , V_136 , V_66 ) ;
F_87 ( V_58 , L_36 , V_136 , V_66 ) ;
F_87 ( V_58 , L_37 , V_136 , V_66 ) ;
F_87 ( V_58 , L_38 , V_136 , V_66 ) ;
}
static void F_88 ( struct V_135 * V_58 , T_3 V_26 )
{
int V_137 = V_92 & V_115 ;
if ( V_137 )
F_86 ( V_58 , V_26 ) ;
F_87 ( V_58 , L_39 ) ;
if ( V_26 & V_94 )
F_87 ( V_58 , L_40 ) ;
if ( V_26 & V_96 )
F_87 ( V_58 , L_41 ) ;
if ( V_26 & V_97 )
F_87 ( V_58 , L_42 ) ;
if ( V_137 )
F_87 ( V_58 , L_43 ) ;
if ( V_26 & V_105 )
F_87 ( V_58 , L_44 ) ;
F_87 ( V_58 , L_45 ) ;
F_87 ( V_58 , L_39 ) ;
if ( V_26 & V_94 )
F_87 ( V_58 , L_46 ) ;
if ( V_26 & V_96 )
F_87 ( V_58 , L_47 ) ;
if ( V_26 & V_97 )
F_87 ( V_58 , L_48 ) ;
if ( V_137 )
F_87 ( V_58 , L_43 ) ;
if ( V_26 & V_105 )
F_87 ( V_58 , L_49 ) ;
F_87 ( V_58 , L_50 ) ;
}
void F_89 ( struct V_135 * V_58 )
{
F_90 ( V_58 , V_133 . V_134 ) ;
}
void F_90 ( struct V_135 * V_58 , T_3 V_26 )
{
struct V_75 * V_76 = V_58 -> V_78 ;
if ( ! ( V_92 & V_93 ) )
return;
if ( V_92 & V_115 ) {
if ( F_91 ( V_76 ) )
return;
F_92 ( V_58 , V_76 ) ;
}
F_88 ( V_58 , V_26 ) ;
}
void F_93 ( struct V_75 * V_76 )
{
struct V_71 * V_45 ;
int V_47 ;
V_76 -> V_78 = NULL ;
V_45 = F_94 ( sizeof( * V_45 ) , V_138 ) ;
if ( ! V_45 )
goto V_139;
V_45 -> V_74 = F_95 ( struct V_111 ) ;
if ( ! V_45 -> V_74 )
goto V_140;
F_96 (cpu) {
T_2 * V_62 = & ( F_30 ( V_45 -> V_74 , V_47 ) -> V_73 ) ;
int * V_3 = & ( F_30 ( V_45 -> V_74 , V_47 ) -> V_3 ) ;
int * V_129 = & ( F_30 ( V_45 -> V_74 , V_47 ) -> V_129 ) ;
int * V_116 = & ( F_30 ( V_45 -> V_74 , V_47 ) -> V_116 ) ;
* V_62 = - 1 ;
* V_3 = 0 ;
* V_129 = 0 ;
* V_116 = - 1 ;
}
V_76 -> V_78 = V_45 ;
return;
V_140:
F_97 ( V_45 ) ;
V_139:
F_98 ( L_51 ) ;
}
void F_99 ( struct V_75 * V_76 )
{
struct V_71 * V_45 = V_76 -> V_78 ;
if ( V_45 ) {
F_100 ( V_45 -> V_74 ) ;
F_97 ( V_45 ) ;
}
}
static int
F_101 ( struct V_23 * V_24 , T_3 V_141 , T_3 V_142 , int V_143 )
{
if ( V_142 == V_117 )
V_41 = ! V_143 ;
return 0 ;
}
static T_5
F_102 ( struct V_144 * V_145 , const char T_6 * V_146 , T_4 V_147 ,
T_7 * V_148 )
{
unsigned long V_134 ;
int V_1 ;
V_1 = F_103 ( V_146 , V_147 , 10 , & V_134 ) ;
if ( V_1 )
return V_1 ;
V_48 = V_134 ;
* V_148 += V_147 ;
return V_147 ;
}
static T_5
F_104 ( struct V_144 * V_145 , char T_6 * V_146 , T_4 V_147 ,
T_7 * V_148 )
{
char V_149 [ 15 ] ;
int V_150 ;
V_150 = sprintf ( V_149 , L_52 , V_48 ) ;
return F_105 ( V_146 , V_147 , V_148 , V_149 , V_150 ) ;
}
static T_8 int F_106 ( void )
{
struct V_151 * V_152 ;
V_152 = F_107 () ;
if ( ! V_152 )
return 0 ;
F_108 ( L_53 , 0644 , V_152 ,
NULL , & V_153 ) ;
return 0 ;
}
static T_8 int F_109 ( void )
{
V_59 = snprintf ( NULL , 0 , L_4 , V_154 - 1 ) ;
if ( ! F_110 ( & V_155 ) ) {
F_98 ( L_54 ) ;
return 1 ;
}
if ( ! F_110 ( & V_156 ) ) {
F_98 ( L_54 ) ;
return 1 ;
}
return F_111 ( & V_157 ) ;
}
