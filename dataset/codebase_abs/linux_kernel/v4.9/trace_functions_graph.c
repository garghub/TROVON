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
unsigned long V_5 , unsigned long * V_6 )
{
unsigned long long V_7 ;
int V_8 ;
if ( F_4 ( F_1 () ) )
return - V_9 ;
if ( ! V_10 -> V_11 )
return - V_9 ;
F_5 () ;
if ( V_10 -> V_12 == V_13 - 1 ) {
F_6 ( & V_10 -> V_14 ) ;
return - V_9 ;
}
if ( V_10 -> V_12 < - 1 )
return - V_9 ;
V_7 = F_7 () ;
V_8 = ++ V_10 -> V_12 ;
if ( F_8 ( V_3 ) )
V_10 -> V_12 -= V_15 ;
F_9 () ;
V_10 -> V_11 [ V_8 ] . V_2 = V_2 ;
V_10 -> V_11 [ V_8 ] . V_3 = V_3 ;
V_10 -> V_11 [ V_8 ] . V_7 = V_7 ;
#ifdef F_10
V_10 -> V_11 [ V_8 ] . V_16 = V_5 ;
#endif
#ifdef F_11
V_10 -> V_11 [ V_8 ] . V_6 = V_6 ;
#endif
* V_4 = V_10 -> V_12 ;
return 0 ;
}
static void
F_12 ( struct V_17 * V_18 , unsigned long * V_2 ,
unsigned long V_5 )
{
int V_8 ;
V_8 = V_10 -> V_12 ;
if ( V_8 < 0 )
V_8 += V_15 ;
if ( F_4 ( V_8 < 0 || V_8 >= V_13 ) ) {
F_2 () ;
F_13 ( 1 ) ;
* V_2 = ( unsigned long ) V_19 ;
return;
}
#ifdef F_10
if ( F_4 ( V_10 -> V_11 [ V_8 ] . V_16 != V_5 ) ) {
F_2 () ;
F_14 ( 1 , L_1
L_2 ,
V_10 -> V_11 [ V_8 ] . V_16 ,
V_5 ,
( void * ) V_10 -> V_11 [ V_8 ] . V_3 ,
V_10 -> V_11 [ V_8 ] . V_2 ) ;
* V_2 = ( unsigned long ) V_19 ;
return;
}
#endif
* V_2 = V_10 -> V_11 [ V_8 ] . V_2 ;
V_18 -> V_3 = V_10 -> V_11 [ V_8 ] . V_3 ;
V_18 -> V_7 = V_10 -> V_11 [ V_8 ] . V_7 ;
V_18 -> V_20 = F_15 ( & V_10 -> V_14 ) ;
V_18 -> V_4 = V_8 ;
}
unsigned long F_16 ( unsigned long V_5 )
{
struct V_17 V_18 ;
unsigned long V_2 ;
F_12 ( & V_18 , & V_2 , V_5 ) ;
V_18 . V_21 = F_7 () ;
F_9 () ;
V_10 -> V_12 -- ;
if ( V_10 -> V_12 < - 1 ) {
V_10 -> V_12 += V_15 ;
return V_2 ;
}
F_17 ( & V_18 ) ;
if ( F_4 ( ! V_2 ) ) {
F_2 () ;
F_13 ( 1 ) ;
V_2 = ( unsigned long ) V_19 ;
}
return V_2 ;
}
unsigned long F_18 ( struct V_22 * V_23 , int * V_24 ,
unsigned long V_2 , unsigned long * V_6 )
{
int V_8 = V_23 -> V_12 ;
int V_25 ;
if ( V_2 != ( unsigned long ) V_26 )
return V_2 ;
if ( V_8 < - 1 )
V_8 += V_15 ;
if ( V_8 < 0 )
return V_2 ;
for ( V_25 = 0 ; V_25 <= V_8 ; V_25 ++ )
if ( V_23 -> V_11 [ V_25 ] . V_6 == V_6 )
return V_23 -> V_11 [ V_25 ] . V_2 ;
return V_2 ;
}
unsigned long F_18 ( struct V_22 * V_23 , int * V_24 ,
unsigned long V_2 , unsigned long * V_6 )
{
int V_27 ;
if ( V_2 != ( unsigned long ) V_26 )
return V_2 ;
V_27 = V_23 -> V_12 ;
if ( ! V_23 -> V_11 || V_27 < * V_24 )
return V_2 ;
V_27 -= * V_24 ;
( * V_24 ) ++ ;
return V_23 -> V_11 [ V_27 ] . V_2 ;
}
int F_19 ( struct V_28 * V_29 ,
struct V_30 * V_18 ,
unsigned long V_31 ,
int V_32 )
{
struct V_33 * V_34 = & V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_29 -> V_40 . V_39 ;
struct V_41 * V_42 ;
V_37 = F_20 ( V_39 , V_43 ,
sizeof( * V_42 ) , V_31 , V_32 ) ;
if ( ! V_37 )
return 0 ;
V_42 = F_21 ( V_37 ) ;
V_42 -> V_44 = * V_18 ;
if ( ! F_22 ( V_34 , V_42 , V_39 , V_37 ) )
F_23 ( V_39 , V_37 ) ;
return 1 ;
}
static inline int F_24 ( void )
{
if ( ! V_45 || F_25 ( V_46 ) )
return 0 ;
return F_26 () ;
}
int F_27 ( struct V_30 * V_18 )
{
struct V_28 * V_29 = V_47 ;
struct V_48 * V_49 ;
unsigned long V_31 ;
long V_50 ;
int V_2 ;
int V_51 ;
int V_32 ;
if ( ! F_28 ( V_29 ) )
return 0 ;
if ( ( ! ( V_18 -> V_4 || F_29 ( V_18 -> V_3 ) ) ||
F_24 () ) || ( V_18 -> V_4 < 0 ) ||
( V_52 && V_18 -> V_4 >= V_52 ) )
return 0 ;
if ( F_8 ( V_18 -> V_3 ) )
return 1 ;
if ( V_53 )
return 1 ;
F_30 ( V_31 ) ;
V_51 = F_31 () ;
V_49 = F_32 ( V_29 -> V_40 . V_49 , V_51 ) ;
V_50 = F_33 ( & V_49 -> V_50 ) ;
if ( F_34 ( V_50 == 1 ) ) {
V_32 = F_35 () ;
V_2 = F_19 ( V_29 , V_18 , V_31 , V_32 ) ;
} else {
V_2 = 0 ;
}
F_36 ( & V_49 -> V_50 ) ;
F_37 ( V_31 ) ;
return V_2 ;
}
static void
F_38 ( struct V_28 * V_29 ,
unsigned long V_54 , unsigned long V_31 , int V_32 )
{
T_1 time = F_7 () ;
struct V_30 V_55 = {
. V_3 = V_54 ,
. V_4 = 0 ,
} ;
struct V_17 V_2 = {
. V_3 = V_54 ,
. V_4 = 0 ,
. V_7 = time ,
. V_21 = time ,
} ;
F_19 ( V_29 , & V_55 , V_31 , V_32 ) ;
F_39 ( V_29 , & V_2 , V_31 , V_32 ) ;
}
void
F_40 ( struct V_28 * V_29 ,
unsigned long V_54 , unsigned long V_56 ,
unsigned long V_31 , int V_32 )
{
F_38 ( V_29 , V_54 , V_31 , V_32 ) ;
}
void F_39 ( struct V_28 * V_29 ,
struct V_17 * V_18 ,
unsigned long V_31 ,
int V_32 )
{
struct V_33 * V_34 = & V_57 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_29 -> V_40 . V_39 ;
struct V_58 * V_42 ;
V_37 = F_20 ( V_39 , V_59 ,
sizeof( * V_42 ) , V_31 , V_32 ) ;
if ( ! V_37 )
return;
V_42 = F_21 ( V_37 ) ;
V_42 -> V_2 = * V_18 ;
if ( ! F_22 ( V_34 , V_42 , V_39 , V_37 ) )
F_23 ( V_39 , V_37 ) ;
}
void F_41 ( struct V_17 * V_18 )
{
struct V_28 * V_29 = V_47 ;
struct V_48 * V_49 ;
unsigned long V_31 ;
long V_50 ;
int V_51 ;
int V_32 ;
F_30 ( V_31 ) ;
V_51 = F_31 () ;
V_49 = F_32 ( V_29 -> V_40 . V_49 , V_51 ) ;
V_50 = F_33 ( & V_49 -> V_50 ) ;
if ( F_34 ( V_50 == 1 ) ) {
V_32 = F_35 () ;
F_39 ( V_29 , V_18 , V_31 , V_32 ) ;
}
F_36 ( & V_49 -> V_50 ) ;
F_37 ( V_31 ) ;
}
void F_42 ( struct V_28 * V_29 )
{
V_47 = V_29 ;
F_43 () ;
}
static void F_44 ( struct V_17 * V_18 )
{
if ( V_53 &&
( V_18 -> V_21 - V_18 -> V_7 < V_53 ) )
return;
else
F_41 ( V_18 ) ;
}
static int F_45 ( struct V_28 * V_29 )
{
int V_2 ;
F_42 ( V_29 ) ;
if ( V_53 )
V_2 = F_46 ( & F_44 ,
& F_27 ) ;
else
V_2 = F_46 ( & F_41 ,
& F_27 ) ;
if ( V_2 )
return V_2 ;
F_47 () ;
return 0 ;
}
static void F_48 ( struct V_28 * V_29 )
{
F_49 () ;
F_50 () ;
}
static int F_51 ( struct V_28 * V_29 )
{
F_48 ( V_29 ) ;
return F_45 ( V_29 ) ;
}
static void F_52 ( struct V_60 * V_61 , int V_51 )
{
F_53 ( V_61 , L_3 , V_62 , V_51 ) ;
}
static void F_54 ( struct V_60 * V_61 , T_2 V_63 )
{
char V_64 [ V_65 ] ;
char V_66 [ 11 ] ;
int V_67 = 0 ;
int V_68 ;
int V_25 ;
F_55 ( V_63 , V_64 ) ;
V_64 [ 7 ] = '\0' ;
sprintf ( V_66 , L_4 , V_63 ) ;
V_68 = strlen ( V_64 ) + strlen ( V_66 ) + 1 ;
if ( V_68 < V_69 )
V_67 = V_69 - V_68 ;
for ( V_25 = 0 ; V_25 < V_67 / 2 ; V_25 ++ )
F_56 ( V_61 , ' ' ) ;
F_53 ( V_61 , L_5 , V_64 , V_66 ) ;
for ( V_25 = 0 ; V_25 < V_67 - ( V_67 / 2 ) ; V_25 ++ )
F_56 ( V_61 , ' ' ) ;
}
static void F_57 ( struct V_60 * V_61 , struct V_70 * V_42 )
{
F_56 ( V_61 , ' ' ) ;
F_58 ( V_61 , V_42 ) ;
}
static void
F_59 ( struct V_60 * V_61 , T_2 V_63 , int V_51 , struct V_71 * V_49 )
{
T_2 V_72 ;
T_2 * V_73 ;
if ( ! V_49 )
return;
V_73 = & ( F_32 ( V_49 -> V_74 , V_51 ) -> V_73 ) ;
if ( * V_73 == V_63 )
return;
V_72 = * V_73 ;
* V_73 = V_63 ;
if ( V_72 == - 1 )
return;
F_60 ( V_61 , L_6 ) ;
F_52 ( V_61 , V_51 ) ;
F_54 ( V_61 , V_72 ) ;
F_60 ( V_61 , L_7 ) ;
F_54 ( V_61 , V_63 ) ;
F_60 ( V_61 , L_8 ) ;
}
static struct V_58 *
F_61 ( struct V_75 * V_76 ,
struct V_41 * V_77 )
{
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_79 * V_80 = NULL ;
struct V_36 * V_37 ;
struct V_58 * V_81 ;
if ( V_49 && V_49 -> V_82 ) {
V_77 = & V_49 -> V_55 ;
V_81 = & V_49 -> V_2 ;
} else {
V_80 = F_62 ( V_76 , V_76 -> V_51 ) ;
if ( V_80 )
V_37 = F_63 ( V_80 , NULL ) ;
else {
F_64 ( V_76 -> V_40 -> V_39 , V_76 -> V_51 ,
NULL , NULL ) ;
V_37 = F_65 ( V_76 -> V_40 -> V_39 , V_76 -> V_51 ,
NULL , NULL ) ;
}
if ( ! V_37 )
return NULL ;
V_81 = F_21 ( V_37 ) ;
if ( V_49 ) {
V_49 -> V_55 = * V_77 ;
if ( V_81 -> V_55 . type == V_59 )
V_49 -> V_2 = * V_81 ;
else
V_49 -> V_2 . V_55 . type = V_81 -> V_55 . type ;
}
}
if ( V_81 -> V_55 . type != V_59 )
return NULL ;
if ( V_77 -> V_55 . V_63 != V_81 -> V_55 . V_63 ||
V_77 -> V_44 . V_3 != V_81 -> V_2 . V_3 )
return NULL ;
if ( V_80 )
F_66 ( V_80 , NULL ) ;
return V_81 ;
}
static void F_67 ( T_1 V_83 , struct V_60 * V_61 )
{
unsigned long V_84 ;
V_84 = F_68 ( V_83 , V_85 ) ;
V_84 /= 1000 ;
F_53 ( V_61 , L_9 ,
( unsigned long ) V_83 , V_84 ) ;
}
static void
F_69 ( struct V_75 * V_76 , unsigned long V_86 ,
enum V_87 type , int V_51 , T_2 V_63 , T_3 V_31 )
{
struct V_28 * V_29 = V_76 -> V_29 ;
struct V_60 * V_61 = & V_76 -> V_88 ;
struct V_70 * V_55 = V_76 -> V_55 ;
if ( V_86 < ( unsigned long ) V_89 ||
V_86 >= ( unsigned long ) V_90 )
return;
if ( V_29 -> V_91 & V_92 ) {
if ( V_31 & V_93 )
F_67 ( V_76 -> V_94 , V_61 ) ;
if ( V_31 & V_95 )
F_52 ( V_61 , V_51 ) ;
if ( V_31 & V_96 ) {
F_54 ( V_61 , V_63 ) ;
F_60 ( V_61 , L_10 ) ;
}
if ( V_29 -> V_91 & V_97 )
F_57 ( V_61 , V_55 ) ;
}
F_70 ( V_29 , 0 , V_61 , V_31 | V_98 ) ;
if ( type == V_43 )
F_60 ( V_61 , L_11 ) ;
else
F_60 ( V_61 , L_12 ) ;
F_70 ( V_29 , 0 , V_61 , V_31 | V_99 ) ;
F_56 ( V_61 , '\n' ) ;
}
void
F_71 ( unsigned long long V_100 , struct V_60 * V_61 )
{
unsigned long V_101 = F_68 ( V_100 , 1000 ) ;
char V_102 [ 21 ] ;
char V_103 [ 5 ] ;
int V_68 ;
int V_25 ;
sprintf ( V_102 , L_13 , ( unsigned long ) V_100 ) ;
F_53 ( V_61 , L_14 , V_102 ) ;
V_68 = strlen ( V_102 ) ;
if ( V_68 < 7 ) {
T_4 V_104 = F_72 ( T_4 , sizeof( V_103 ) , 8UL - V_68 ) ;
snprintf ( V_103 , V_104 , L_15 , V_101 ) ;
F_53 ( V_61 , L_16 , V_103 ) ;
V_68 += strlen ( V_103 ) + 1 ;
}
F_60 ( V_61 , L_17 ) ;
for ( V_25 = V_68 ; V_25 < 8 ; V_25 ++ )
F_56 ( V_61 , ' ' ) ;
}
static void
F_70 ( struct V_28 * V_29 , unsigned long long V_100 ,
struct V_60 * V_61 , T_3 V_31 )
{
if ( ! ( V_31 & V_105 ) ||
! ( V_29 -> V_91 & V_92 ) )
return;
switch ( V_31 & V_106 ) {
case V_107 :
F_60 ( V_61 , L_18 ) ;
return;
case V_98 :
F_60 ( V_61 , L_19 ) ;
return;
case V_99 :
F_60 ( V_61 , L_20 ) ;
return;
}
if ( V_31 & V_108 )
F_53 ( V_61 , L_21 , F_73 ( V_100 ) ) ;
else
F_60 ( V_61 , L_19 ) ;
F_71 ( V_100 , V_61 ) ;
F_60 ( V_61 , L_22 ) ;
}
static enum V_109
F_74 ( struct V_75 * V_76 ,
struct V_41 * V_42 ,
struct V_58 * V_110 ,
struct V_60 * V_61 , T_3 V_31 )
{
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_28 * V_29 = V_76 -> V_29 ;
struct V_17 * V_111 ;
struct V_30 * V_34 ;
unsigned long long V_100 ;
int V_25 ;
V_111 = & V_110 -> V_2 ;
V_34 = & V_42 -> V_44 ;
V_100 = V_111 -> V_21 - V_111 -> V_7 ;
if ( V_49 ) {
struct V_112 * V_74 ;
int V_51 = V_76 -> V_51 ;
V_74 = F_32 ( V_49 -> V_74 , V_51 ) ;
V_74 -> V_4 = V_34 -> V_4 - 1 ;
if ( V_34 -> V_4 < V_13 )
V_74 -> V_113 [ V_34 -> V_4 ] = 0 ;
}
F_70 ( V_29 , V_100 , V_61 , V_31 ) ;
for ( V_25 = 0 ; V_25 < V_34 -> V_4 * V_114 ; V_25 ++ )
F_56 ( V_61 , ' ' ) ;
F_53 ( V_61 , L_23 , ( void * ) V_34 -> V_3 ) ;
return F_75 ( V_61 ) ;
}
static enum V_109
F_76 ( struct V_75 * V_76 ,
struct V_41 * V_42 ,
struct V_60 * V_61 , int V_51 , T_3 V_31 )
{
struct V_30 * V_34 = & V_42 -> V_44 ;
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_28 * V_29 = V_76 -> V_29 ;
int V_25 ;
if ( V_49 ) {
struct V_112 * V_74 ;
int V_51 = V_76 -> V_51 ;
V_74 = F_32 ( V_49 -> V_74 , V_51 ) ;
V_74 -> V_4 = V_34 -> V_4 ;
if ( V_34 -> V_4 < V_13 )
V_74 -> V_113 [ V_34 -> V_4 ] = V_34 -> V_3 ;
}
F_70 ( V_29 , 0 , V_61 , V_31 | V_107 ) ;
for ( V_25 = 0 ; V_25 < V_34 -> V_4 * V_114 ; V_25 ++ )
F_56 ( V_61 , ' ' ) ;
F_53 ( V_61 , L_24 , ( void * ) V_34 -> V_3 ) ;
if ( F_77 ( V_61 ) )
return V_115 ;
return V_116 ;
}
static void
F_78 ( struct V_75 * V_76 , struct V_60 * V_61 ,
int type , unsigned long V_86 , T_3 V_31 )
{
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_70 * V_55 = V_76 -> V_55 ;
struct V_28 * V_29 = V_76 -> V_29 ;
int V_51 = V_76 -> V_51 ;
F_59 ( V_61 , V_55 -> V_63 , V_51 , V_49 ) ;
if ( type )
F_69 ( V_76 , V_86 , type , V_51 , V_55 -> V_63 , V_31 ) ;
if ( ! ( V_29 -> V_91 & V_92 ) )
return;
if ( V_31 & V_93 )
F_67 ( V_76 -> V_94 , V_61 ) ;
if ( V_31 & V_95 )
F_52 ( V_61 , V_51 ) ;
if ( V_31 & V_96 ) {
F_54 ( V_61 , V_55 -> V_63 ) ;
F_60 ( V_61 , L_10 ) ;
}
if ( V_29 -> V_91 & V_97 )
F_57 ( V_61 , V_55 ) ;
return;
}
static int
F_79 ( struct V_75 * V_76 , T_3 V_31 ,
unsigned long V_86 , int V_4 )
{
int V_51 = V_76 -> V_51 ;
int * V_117 ;
struct V_71 * V_49 = V_76 -> V_78 ;
if ( ( V_31 & V_118 ) ||
( ! V_49 ) )
return 0 ;
V_117 = & ( F_32 ( V_49 -> V_74 , V_51 ) -> V_117 ) ;
if ( * V_117 >= 0 )
return 1 ;
if ( ( V_86 < ( unsigned long ) V_89 ) ||
( V_86 >= ( unsigned long ) V_90 ) )
return 0 ;
* V_117 = V_4 ;
return 1 ;
}
static int
F_80 ( struct V_75 * V_76 , T_3 V_31 , int V_4 )
{
int V_51 = V_76 -> V_51 ;
int * V_117 ;
struct V_71 * V_49 = V_76 -> V_78 ;
if ( ( V_31 & V_118 ) ||
( ! V_49 ) )
return 0 ;
V_117 = & ( F_32 ( V_49 -> V_74 , V_51 ) -> V_117 ) ;
if ( * V_117 == - 1 )
return 0 ;
if ( * V_117 >= V_4 ) {
* V_117 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_109
F_81 ( struct V_41 * V_119 , struct V_60 * V_61 ,
struct V_75 * V_76 , T_3 V_31 )
{
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_30 * V_34 = & V_119 -> V_44 ;
struct V_58 * V_120 ;
static enum V_109 V_2 ;
int V_51 = V_76 -> V_51 ;
if ( F_79 ( V_76 , V_31 , V_34 -> V_3 , V_34 -> V_4 ) )
return V_121 ;
F_78 ( V_76 , V_61 , V_43 , V_34 -> V_3 , V_31 ) ;
V_120 = F_61 ( V_76 , V_119 ) ;
if ( V_120 )
V_2 = F_74 ( V_76 , V_119 , V_120 , V_61 , V_31 ) ;
else
V_2 = F_76 ( V_76 , V_119 , V_61 , V_51 , V_31 ) ;
if ( V_49 ) {
if ( V_61 -> V_122 ) {
V_49 -> V_82 = 1 ;
V_49 -> V_51 = V_51 ;
} else
V_49 -> V_82 = 0 ;
}
return V_2 ;
}
static enum V_109
F_82 ( struct V_17 * V_18 , struct V_60 * V_61 ,
struct V_70 * V_55 , struct V_75 * V_76 ,
T_3 V_31 )
{
unsigned long long V_100 = V_18 -> V_21 - V_18 -> V_7 ;
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_28 * V_29 = V_76 -> V_29 ;
T_2 V_63 = V_55 -> V_63 ;
int V_51 = V_76 -> V_51 ;
int V_123 = 1 ;
int V_25 ;
if ( F_80 ( V_76 , V_31 , V_18 -> V_4 ) )
return V_121 ;
if ( V_49 ) {
struct V_112 * V_74 ;
int V_51 = V_76 -> V_51 ;
V_74 = F_32 ( V_49 -> V_74 , V_51 ) ;
V_74 -> V_4 = V_18 -> V_4 - 1 ;
if ( V_18 -> V_4 < V_13 ) {
if ( V_74 -> V_113 [ V_18 -> V_4 ] != V_18 -> V_3 )
V_123 = 0 ;
V_74 -> V_113 [ V_18 -> V_4 ] = 0 ;
}
}
F_78 ( V_76 , V_61 , 0 , 0 , V_31 ) ;
F_70 ( V_29 , V_100 , V_61 , V_31 ) ;
for ( V_25 = 0 ; V_25 < V_18 -> V_4 * V_114 ; V_25 ++ )
F_56 ( V_61 , ' ' ) ;
if ( V_123 && ! ( V_31 & V_124 ) )
F_60 ( V_61 , L_25 ) ;
else
F_53 ( V_61 , L_26 , ( void * ) V_18 -> V_3 ) ;
if ( V_31 & V_125 )
F_53 ( V_61 , L_27 ,
V_18 -> V_20 ) ;
F_69 ( V_76 , V_18 -> V_3 , V_59 ,
V_51 , V_63 , V_31 ) ;
return F_75 ( V_61 ) ;
}
static enum V_109
F_83 ( struct V_60 * V_61 , struct V_70 * V_55 ,
struct V_75 * V_76 , T_3 V_31 )
{
struct V_28 * V_29 = V_76 -> V_29 ;
unsigned long V_126 = ( V_29 -> V_91 & V_127 ) ;
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_128 * V_37 ;
int V_4 = 0 ;
int V_2 ;
int V_25 ;
if ( V_49 )
V_4 = F_32 ( V_49 -> V_74 , V_76 -> V_51 ) -> V_4 ;
F_78 ( V_76 , V_61 , 0 , 0 , V_31 ) ;
F_70 ( V_29 , 0 , V_61 , V_31 | V_107 ) ;
if ( V_4 > 0 )
for ( V_25 = 0 ; V_25 < ( V_4 + 1 ) * V_114 ; V_25 ++ )
F_56 ( V_61 , ' ' ) ;
F_60 ( V_61 , L_28 ) ;
switch ( V_76 -> V_55 -> type ) {
case V_129 :
V_2 = F_84 ( V_76 ) ;
if ( V_2 != V_121 )
return V_2 ;
break;
case V_130 :
V_2 = F_85 ( V_76 ) ;
if ( V_2 != V_121 )
return V_2 ;
break;
case V_131 :
V_2 = F_86 ( V_76 ) ;
if ( V_2 != V_121 )
return V_2 ;
break;
default:
V_37 = F_87 ( V_55 -> type ) ;
if ( ! V_37 )
return V_132 ;
V_2 = V_37 -> V_133 -> V_18 ( V_76 , V_126 , V_37 ) ;
if ( V_2 != V_121 )
return V_2 ;
}
if ( F_77 ( V_61 ) )
goto V_134;
if ( V_61 -> V_39 [ V_61 -> V_88 . V_68 - 1 ] == '\n' ) {
V_61 -> V_39 [ V_61 -> V_88 . V_68 - 1 ] = '\0' ;
V_61 -> V_88 . V_68 -- ;
}
F_60 ( V_61 , L_29 ) ;
V_134:
return F_75 ( V_61 ) ;
}
enum V_109
F_88 ( struct V_75 * V_76 , T_3 V_31 )
{
struct V_41 * V_119 ;
struct V_71 * V_49 = V_76 -> V_78 ;
struct V_70 * V_42 = V_76 -> V_55 ;
struct V_60 * V_61 = & V_76 -> V_88 ;
int V_51 = V_76 -> V_51 ;
int V_2 ;
if ( V_49 && F_32 ( V_49 -> V_74 , V_51 ) -> V_135 ) {
F_32 ( V_49 -> V_74 , V_51 ) -> V_135 = 0 ;
return V_121 ;
}
if ( V_49 && V_49 -> V_82 ) {
V_119 = & V_49 -> V_55 ;
V_76 -> V_51 = V_49 -> V_51 ;
V_2 = F_81 ( V_119 , V_61 , V_76 , V_31 ) ;
if ( V_2 == V_121 && V_76 -> V_51 != V_51 ) {
F_32 ( V_49 -> V_74 , V_76 -> V_51 ) -> V_135 = 1 ;
V_2 = V_116 ;
}
V_76 -> V_51 = V_51 ;
return V_2 ;
}
switch ( V_42 -> type ) {
case V_43 : {
struct V_41 V_136 ;
F_89 ( V_119 , V_42 ) ;
V_136 = * V_119 ;
return F_81 ( & V_136 , V_61 , V_76 , V_31 ) ;
}
case V_59 : {
struct V_58 * V_119 ;
F_89 ( V_119 , V_42 ) ;
return F_82 ( & V_119 -> V_2 , V_61 , V_42 , V_76 , V_31 ) ;
}
case V_137 :
case V_138 :
return V_132 ;
default:
return F_83 ( V_61 , V_42 , V_76 , V_31 ) ;
}
return V_121 ;
}
static enum V_109
F_90 ( struct V_75 * V_76 )
{
return F_88 ( V_76 , V_139 . V_140 ) ;
}
static enum V_109
F_91 ( struct V_75 * V_76 , int V_31 ,
struct V_128 * V_37 )
{
return F_90 ( V_76 ) ;
}
static void F_92 ( struct V_141 * V_61 , T_3 V_31 )
{
static const char V_67 [] = L_30
L_31
L_32 ;
int V_142 = 0 ;
if ( V_31 & V_93 )
V_142 += 16 ;
if ( V_31 & V_95 )
V_142 += 4 ;
if ( V_31 & V_96 )
V_142 += 17 ;
F_93 ( V_61 , L_33 , V_142 , V_67 ) ;
F_93 ( V_61 , L_34 , V_142 , V_67 ) ;
F_93 ( V_61 , L_35 , V_142 , V_67 ) ;
F_93 ( V_61 , L_36 , V_142 , V_67 ) ;
F_93 ( V_61 , L_37 , V_142 , V_67 ) ;
}
static void F_94 ( struct V_28 * V_29 ,
struct V_141 * V_61 , T_3 V_31 )
{
int V_143 = V_29 -> V_91 & V_97 ;
if ( V_143 )
F_92 ( V_61 , V_31 ) ;
F_95 ( V_61 , '#' ) ;
if ( V_31 & V_93 )
F_96 ( V_61 , L_38 ) ;
if ( V_31 & V_95 )
F_96 ( V_61 , L_39 ) ;
if ( V_31 & V_96 )
F_96 ( V_61 , L_40 ) ;
if ( V_143 )
F_96 ( V_61 , L_41 ) ;
if ( V_31 & V_105 )
F_96 ( V_61 , L_42 ) ;
F_96 ( V_61 , L_43 ) ;
F_95 ( V_61 , '#' ) ;
if ( V_31 & V_93 )
F_96 ( V_61 , L_44 ) ;
if ( V_31 & V_95 )
F_96 ( V_61 , L_45 ) ;
if ( V_31 & V_96 )
F_96 ( V_61 , L_46 ) ;
if ( V_143 )
F_96 ( V_61 , L_41 ) ;
if ( V_31 & V_105 )
F_96 ( V_61 , L_47 ) ;
F_96 ( V_61 , L_48 ) ;
}
static void F_97 ( struct V_141 * V_61 )
{
F_98 ( V_61 , V_139 . V_140 ) ;
}
void F_98 ( struct V_141 * V_61 , T_3 V_31 )
{
struct V_75 * V_76 = V_61 -> V_78 ;
struct V_28 * V_29 = V_76 -> V_29 ;
if ( ! ( V_29 -> V_91 & V_92 ) )
return;
if ( V_29 -> V_91 & V_97 ) {
if ( F_99 ( V_76 ) )
return;
F_100 ( V_61 , V_76 ) ;
}
F_94 ( V_29 , V_61 , V_31 ) ;
}
void F_101 ( struct V_75 * V_76 )
{
struct V_71 * V_49 ;
T_5 V_144 ;
int V_51 ;
V_76 -> V_78 = NULL ;
V_144 = ( F_102 () || F_103 () ) ? V_145 : V_146 ;
V_49 = F_104 ( sizeof( * V_49 ) , V_144 ) ;
if ( ! V_49 )
goto V_147;
V_49 -> V_74 = F_105 ( struct V_112 , V_144 ) ;
if ( ! V_49 -> V_74 )
goto V_148;
F_106 (cpu) {
T_2 * V_63 = & ( F_32 ( V_49 -> V_74 , V_51 ) -> V_73 ) ;
int * V_4 = & ( F_32 ( V_49 -> V_74 , V_51 ) -> V_4 ) ;
int * V_135 = & ( F_32 ( V_49 -> V_74 , V_51 ) -> V_135 ) ;
int * V_117 = & ( F_32 ( V_49 -> V_74 , V_51 ) -> V_117 ) ;
* V_63 = - 1 ;
* V_4 = 0 ;
* V_135 = 0 ;
* V_117 = - 1 ;
}
V_76 -> V_78 = V_49 ;
return;
V_148:
F_107 ( V_49 ) ;
V_147:
F_108 ( L_49 ) ;
}
void F_109 ( struct V_75 * V_76 )
{
struct V_71 * V_49 = V_76 -> V_78 ;
if ( V_49 ) {
F_110 ( V_49 -> V_74 ) ;
F_107 ( V_49 ) ;
}
}
static int
F_111 ( struct V_28 * V_29 , T_3 V_149 , T_3 V_150 , int V_151 )
{
if ( V_150 == V_118 )
V_45 = ! V_151 ;
if ( V_150 == V_152 )
F_112 ( V_151 ) ;
if ( V_150 == V_153 )
F_113 ( V_151 ) ;
return 0 ;
}
static T_6
F_114 ( struct V_154 * V_155 , const char T_7 * V_156 , T_4 V_157 ,
T_8 * V_158 )
{
unsigned long V_140 ;
int V_2 ;
V_2 = F_115 ( V_156 , V_157 , 10 , & V_140 ) ;
if ( V_2 )
return V_2 ;
V_52 = V_140 ;
* V_158 += V_157 ;
return V_157 ;
}
static T_6
F_116 ( struct V_154 * V_155 , char T_7 * V_156 , T_4 V_157 ,
T_8 * V_158 )
{
char V_159 [ 15 ] ;
int V_160 ;
V_160 = sprintf ( V_159 , L_50 , V_52 ) ;
return F_117 ( V_156 , V_157 , V_158 , V_159 , V_160 ) ;
}
static T_9 int F_118 ( void )
{
struct V_161 * V_162 ;
V_162 = F_119 () ;
if ( F_120 ( V_162 ) )
return 0 ;
F_121 ( L_51 , 0644 , V_162 ,
NULL , & V_163 ) ;
return 0 ;
}
static T_9 int F_122 ( void )
{
V_62 = snprintf ( NULL , 0 , L_4 , V_164 - 1 ) ;
if ( ! F_123 ( & V_165 ) ) {
F_108 ( L_52 ) ;
return 1 ;
}
if ( ! F_123 ( & V_166 ) ) {
F_108 ( L_52 ) ;
return 1 ;
}
return F_124 ( & V_167 ) ;
}
