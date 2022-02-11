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
if ( F_29 ( V_18 ) )
return 0 ;
if ( F_24 () )
return 0 ;
if ( F_8 ( V_18 -> V_3 ) )
return 1 ;
if ( V_52 )
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
unsigned long V_53 , unsigned long V_31 , int V_32 )
{
T_1 time = F_7 () ;
struct V_30 V_54 = {
. V_3 = V_53 ,
. V_4 = 0 ,
} ;
struct V_17 V_2 = {
. V_3 = V_53 ,
. V_4 = 0 ,
. V_7 = time ,
. V_21 = time ,
} ;
F_19 ( V_29 , & V_54 , V_31 , V_32 ) ;
F_39 ( V_29 , & V_2 , V_31 , V_32 ) ;
}
void
F_40 ( struct V_28 * V_29 ,
unsigned long V_53 , unsigned long V_55 ,
unsigned long V_31 , int V_32 )
{
F_38 ( V_29 , V_53 , V_31 , V_32 ) ;
}
void F_39 ( struct V_28 * V_29 ,
struct V_17 * V_18 ,
unsigned long V_31 ,
int V_32 )
{
struct V_33 * V_34 = & V_56 ;
struct V_36 * V_37 ;
struct V_38 * V_39 = V_29 -> V_40 . V_39 ;
struct V_57 * V_42 ;
V_37 = F_20 ( V_39 , V_58 ,
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
if ( V_52 &&
( V_18 -> V_21 - V_18 -> V_7 < V_52 ) )
return;
else
F_41 ( V_18 ) ;
}
static int F_45 ( struct V_28 * V_29 )
{
int V_2 ;
F_42 ( V_29 ) ;
if ( V_52 )
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
static void F_52 ( struct V_59 * V_60 , int V_51 )
{
F_53 ( V_60 , L_3 , V_61 , V_51 ) ;
}
static void F_54 ( struct V_59 * V_60 , T_2 V_62 )
{
char V_63 [ V_64 ] ;
char V_65 [ 11 ] ;
int V_66 = 0 ;
int V_67 ;
int V_25 ;
F_55 ( V_62 , V_63 ) ;
V_63 [ 7 ] = '\0' ;
sprintf ( V_65 , L_4 , V_62 ) ;
V_67 = strlen ( V_63 ) + strlen ( V_65 ) + 1 ;
if ( V_67 < V_68 )
V_66 = V_68 - V_67 ;
for ( V_25 = 0 ; V_25 < V_66 / 2 ; V_25 ++ )
F_56 ( V_60 , ' ' ) ;
F_53 ( V_60 , L_5 , V_63 , V_65 ) ;
for ( V_25 = 0 ; V_25 < V_66 - ( V_66 / 2 ) ; V_25 ++ )
F_56 ( V_60 , ' ' ) ;
}
static void F_57 ( struct V_59 * V_60 , struct V_69 * V_42 )
{
F_56 ( V_60 , ' ' ) ;
F_58 ( V_60 , V_42 ) ;
}
static void
F_59 ( struct V_59 * V_60 , T_2 V_62 , int V_51 , struct V_70 * V_49 )
{
T_2 V_71 ;
T_2 * V_72 ;
if ( ! V_49 )
return;
V_72 = & ( F_32 ( V_49 -> V_73 , V_51 ) -> V_72 ) ;
if ( * V_72 == V_62 )
return;
V_71 = * V_72 ;
* V_72 = V_62 ;
if ( V_71 == - 1 )
return;
F_60 ( V_60 , L_6 ) ;
F_52 ( V_60 , V_51 ) ;
F_54 ( V_60 , V_71 ) ;
F_60 ( V_60 , L_7 ) ;
F_54 ( V_60 , V_62 ) ;
F_60 ( V_60 , L_8 ) ;
}
static struct V_57 *
F_61 ( struct V_74 * V_75 ,
struct V_41 * V_76 )
{
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_78 * V_79 = NULL ;
struct V_36 * V_37 ;
struct V_57 * V_80 ;
if ( V_49 && V_49 -> V_81 ) {
V_76 = & V_49 -> V_54 ;
V_80 = & V_49 -> V_2 ;
} else {
V_79 = F_62 ( V_75 , V_75 -> V_51 ) ;
if ( V_79 )
V_37 = F_63 ( V_79 , NULL ) ;
else {
F_64 ( V_75 -> V_40 -> V_39 , V_75 -> V_51 ,
NULL , NULL ) ;
V_37 = F_65 ( V_75 -> V_40 -> V_39 , V_75 -> V_51 ,
NULL , NULL ) ;
}
if ( ! V_37 )
return NULL ;
V_80 = F_21 ( V_37 ) ;
if ( V_49 ) {
V_49 -> V_54 = * V_76 ;
if ( V_80 -> V_54 . type == V_58 )
V_49 -> V_2 = * V_80 ;
else
V_49 -> V_2 . V_54 . type = V_80 -> V_54 . type ;
}
}
if ( V_80 -> V_54 . type != V_58 )
return NULL ;
if ( V_76 -> V_54 . V_62 != V_80 -> V_54 . V_62 ||
V_76 -> V_44 . V_3 != V_80 -> V_2 . V_3 )
return NULL ;
if ( V_79 )
F_66 ( V_79 , NULL ) ;
return V_80 ;
}
static void F_67 ( T_1 V_82 , struct V_59 * V_60 )
{
unsigned long V_83 ;
V_83 = F_68 ( V_82 , V_84 ) ;
V_83 /= 1000 ;
F_53 ( V_60 , L_9 ,
( unsigned long ) V_82 , V_83 ) ;
}
static void
F_69 ( struct V_74 * V_75 , unsigned long V_85 ,
enum V_86 type , int V_51 , T_2 V_62 , T_3 V_31 )
{
struct V_28 * V_29 = V_75 -> V_29 ;
struct V_59 * V_60 = & V_75 -> V_87 ;
struct V_69 * V_54 = V_75 -> V_54 ;
if ( V_85 < ( unsigned long ) V_88 ||
V_85 >= ( unsigned long ) V_89 )
return;
if ( V_29 -> V_90 & V_91 ) {
if ( V_31 & V_92 )
F_67 ( V_75 -> V_93 , V_60 ) ;
if ( V_31 & V_94 )
F_52 ( V_60 , V_51 ) ;
if ( V_31 & V_95 ) {
F_54 ( V_60 , V_62 ) ;
F_60 ( V_60 , L_10 ) ;
}
if ( V_29 -> V_90 & V_96 )
F_57 ( V_60 , V_54 ) ;
}
F_70 ( V_29 , 0 , V_60 , V_31 | V_97 ) ;
if ( type == V_43 )
F_60 ( V_60 , L_11 ) ;
else
F_60 ( V_60 , L_12 ) ;
F_70 ( V_29 , 0 , V_60 , V_31 | V_98 ) ;
F_56 ( V_60 , '\n' ) ;
}
void
F_71 ( unsigned long long V_99 , struct V_59 * V_60 )
{
unsigned long V_100 = F_68 ( V_99 , 1000 ) ;
char V_101 [ 21 ] ;
char V_102 [ 5 ] ;
int V_67 ;
int V_25 ;
sprintf ( V_101 , L_13 , ( unsigned long ) V_99 ) ;
F_53 ( V_60 , L_14 , V_101 ) ;
V_67 = strlen ( V_101 ) ;
if ( V_67 < 7 ) {
T_4 V_103 = F_72 ( T_4 , sizeof( V_102 ) , 8UL - V_67 ) ;
snprintf ( V_102 , V_103 , L_15 , V_100 ) ;
F_53 ( V_60 , L_16 , V_102 ) ;
V_67 += strlen ( V_102 ) + 1 ;
}
F_60 ( V_60 , L_17 ) ;
for ( V_25 = V_67 ; V_25 < 8 ; V_25 ++ )
F_56 ( V_60 , ' ' ) ;
}
static void
F_70 ( struct V_28 * V_29 , unsigned long long V_99 ,
struct V_59 * V_60 , T_3 V_31 )
{
if ( ! ( V_31 & V_104 ) ||
! ( V_29 -> V_90 & V_91 ) )
return;
switch ( V_31 & V_105 ) {
case V_106 :
F_60 ( V_60 , L_18 ) ;
return;
case V_97 :
F_60 ( V_60 , L_19 ) ;
return;
case V_98 :
F_60 ( V_60 , L_20 ) ;
return;
}
if ( V_31 & V_107 )
F_53 ( V_60 , L_21 , F_73 ( V_99 ) ) ;
else
F_60 ( V_60 , L_19 ) ;
F_71 ( V_99 , V_60 ) ;
F_60 ( V_60 , L_22 ) ;
}
static enum V_108
F_74 ( struct V_74 * V_75 ,
struct V_41 * V_42 ,
struct V_57 * V_109 ,
struct V_59 * V_60 , T_3 V_31 )
{
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_28 * V_29 = V_75 -> V_29 ;
struct V_17 * V_110 ;
struct V_30 * V_34 ;
unsigned long long V_99 ;
int V_25 ;
V_110 = & V_109 -> V_2 ;
V_34 = & V_42 -> V_44 ;
V_99 = V_110 -> V_21 - V_110 -> V_7 ;
if ( V_49 ) {
struct V_111 * V_73 ;
int V_51 = V_75 -> V_51 ;
V_73 = F_32 ( V_49 -> V_73 , V_51 ) ;
if ( V_34 -> V_4 < - 1 )
V_34 -> V_4 += V_15 ;
V_73 -> V_4 = V_34 -> V_4 - 1 ;
if ( V_34 -> V_4 < V_13 &&
! F_75 ( V_34 -> V_4 < 0 ) )
V_73 -> V_112 [ V_34 -> V_4 ] = 0 ;
}
F_70 ( V_29 , V_99 , V_60 , V_31 ) ;
for ( V_25 = 0 ; V_25 < V_34 -> V_4 * V_113 ; V_25 ++ )
F_56 ( V_60 , ' ' ) ;
F_53 ( V_60 , L_23 , ( void * ) V_34 -> V_3 ) ;
return F_76 ( V_60 ) ;
}
static enum V_108
F_77 ( struct V_74 * V_75 ,
struct V_41 * V_42 ,
struct V_59 * V_60 , int V_51 , T_3 V_31 )
{
struct V_30 * V_34 = & V_42 -> V_44 ;
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_28 * V_29 = V_75 -> V_29 ;
int V_25 ;
if ( V_49 ) {
struct V_111 * V_73 ;
int V_51 = V_75 -> V_51 ;
if ( V_34 -> V_4 < - 1 )
V_34 -> V_4 += V_15 ;
V_73 = F_32 ( V_49 -> V_73 , V_51 ) ;
V_73 -> V_4 = V_34 -> V_4 ;
if ( V_34 -> V_4 < V_13 &&
! F_75 ( V_34 -> V_4 < 0 ) )
V_73 -> V_112 [ V_34 -> V_4 ] = V_34 -> V_3 ;
}
F_70 ( V_29 , 0 , V_60 , V_31 | V_106 ) ;
for ( V_25 = 0 ; V_25 < V_34 -> V_4 * V_113 ; V_25 ++ )
F_56 ( V_60 , ' ' ) ;
F_53 ( V_60 , L_24 , ( void * ) V_34 -> V_3 ) ;
if ( F_78 ( V_60 ) )
return V_114 ;
return V_115 ;
}
static void
F_79 ( struct V_74 * V_75 , struct V_59 * V_60 ,
int type , unsigned long V_85 , T_3 V_31 )
{
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_69 * V_54 = V_75 -> V_54 ;
struct V_28 * V_29 = V_75 -> V_29 ;
int V_51 = V_75 -> V_51 ;
F_59 ( V_60 , V_54 -> V_62 , V_51 , V_49 ) ;
if ( type )
F_69 ( V_75 , V_85 , type , V_51 , V_54 -> V_62 , V_31 ) ;
if ( ! ( V_29 -> V_90 & V_91 ) )
return;
if ( V_31 & V_92 )
F_67 ( V_75 -> V_93 , V_60 ) ;
if ( V_31 & V_94 )
F_52 ( V_60 , V_51 ) ;
if ( V_31 & V_95 ) {
F_54 ( V_60 , V_54 -> V_62 ) ;
F_60 ( V_60 , L_10 ) ;
}
if ( V_29 -> V_90 & V_96 )
F_57 ( V_60 , V_54 ) ;
return;
}
static int
F_80 ( struct V_74 * V_75 , T_3 V_31 ,
unsigned long V_85 , int V_4 )
{
int V_51 = V_75 -> V_51 ;
int * V_116 ;
struct V_70 * V_49 = V_75 -> V_77 ;
if ( ( V_31 & V_117 ) ||
( ! V_49 ) )
return 0 ;
V_116 = & ( F_32 ( V_49 -> V_73 , V_51 ) -> V_116 ) ;
if ( * V_116 >= 0 )
return 1 ;
if ( ( V_85 < ( unsigned long ) V_88 ) ||
( V_85 >= ( unsigned long ) V_89 ) )
return 0 ;
* V_116 = V_4 ;
return 1 ;
}
static int
F_81 ( struct V_74 * V_75 , T_3 V_31 , int V_4 )
{
int V_51 = V_75 -> V_51 ;
int * V_116 ;
struct V_70 * V_49 = V_75 -> V_77 ;
if ( ( V_31 & V_117 ) ||
( ! V_49 ) )
return 0 ;
V_116 = & ( F_32 ( V_49 -> V_73 , V_51 ) -> V_116 ) ;
if ( * V_116 == - 1 )
return 0 ;
if ( * V_116 >= V_4 ) {
* V_116 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_108
F_82 ( struct V_41 * V_118 , struct V_59 * V_60 ,
struct V_74 * V_75 , T_3 V_31 )
{
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_30 * V_34 = & V_118 -> V_44 ;
struct V_57 * V_119 ;
static enum V_108 V_2 ;
int V_51 = V_75 -> V_51 ;
if ( F_80 ( V_75 , V_31 , V_34 -> V_3 , V_34 -> V_4 ) )
return V_120 ;
F_79 ( V_75 , V_60 , V_43 , V_34 -> V_3 , V_31 ) ;
V_119 = F_61 ( V_75 , V_118 ) ;
if ( V_119 )
V_2 = F_74 ( V_75 , V_118 , V_119 , V_60 , V_31 ) ;
else
V_2 = F_77 ( V_75 , V_118 , V_60 , V_51 , V_31 ) ;
if ( V_49 ) {
if ( V_60 -> V_121 ) {
V_49 -> V_81 = 1 ;
V_49 -> V_51 = V_51 ;
} else
V_49 -> V_81 = 0 ;
}
return V_2 ;
}
static enum V_108
F_83 ( struct V_17 * V_18 , struct V_59 * V_60 ,
struct V_69 * V_54 , struct V_74 * V_75 ,
T_3 V_31 )
{
unsigned long long V_99 = V_18 -> V_21 - V_18 -> V_7 ;
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_28 * V_29 = V_75 -> V_29 ;
T_2 V_62 = V_54 -> V_62 ;
int V_51 = V_75 -> V_51 ;
int V_122 = 1 ;
int V_25 ;
if ( F_81 ( V_75 , V_31 , V_18 -> V_4 ) )
return V_120 ;
if ( V_49 ) {
struct V_111 * V_73 ;
int V_51 = V_75 -> V_51 ;
V_73 = F_32 ( V_49 -> V_73 , V_51 ) ;
V_73 -> V_4 = V_18 -> V_4 - 1 ;
if ( V_18 -> V_4 < V_13 &&
! F_75 ( V_18 -> V_4 < 0 ) ) {
if ( V_73 -> V_112 [ V_18 -> V_4 ] != V_18 -> V_3 )
V_122 = 0 ;
V_73 -> V_112 [ V_18 -> V_4 ] = 0 ;
}
}
F_79 ( V_75 , V_60 , 0 , 0 , V_31 ) ;
F_70 ( V_29 , V_99 , V_60 , V_31 ) ;
for ( V_25 = 0 ; V_25 < V_18 -> V_4 * V_113 ; V_25 ++ )
F_56 ( V_60 , ' ' ) ;
if ( V_122 && ! ( V_31 & V_123 ) )
F_60 ( V_60 , L_25 ) ;
else
F_53 ( V_60 , L_26 , ( void * ) V_18 -> V_3 ) ;
if ( V_31 & V_124 )
F_53 ( V_60 , L_27 ,
V_18 -> V_20 ) ;
F_69 ( V_75 , V_18 -> V_3 , V_58 ,
V_51 , V_62 , V_31 ) ;
return F_76 ( V_60 ) ;
}
static enum V_108
F_84 ( struct V_59 * V_60 , struct V_69 * V_54 ,
struct V_74 * V_75 , T_3 V_31 )
{
struct V_28 * V_29 = V_75 -> V_29 ;
unsigned long V_125 = ( V_29 -> V_90 & V_126 ) ;
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_127 * V_37 ;
int V_4 = 0 ;
int V_2 ;
int V_25 ;
if ( V_49 )
V_4 = F_32 ( V_49 -> V_73 , V_75 -> V_51 ) -> V_4 ;
F_79 ( V_75 , V_60 , 0 , 0 , V_31 ) ;
F_70 ( V_29 , 0 , V_60 , V_31 | V_106 ) ;
if ( V_4 > 0 )
for ( V_25 = 0 ; V_25 < ( V_4 + 1 ) * V_113 ; V_25 ++ )
F_56 ( V_60 , ' ' ) ;
F_60 ( V_60 , L_28 ) ;
switch ( V_75 -> V_54 -> type ) {
case V_128 :
V_2 = F_85 ( V_75 ) ;
if ( V_2 != V_120 )
return V_2 ;
break;
case V_129 :
V_2 = F_86 ( V_75 ) ;
if ( V_2 != V_120 )
return V_2 ;
break;
case V_130 :
V_2 = F_87 ( V_75 ) ;
if ( V_2 != V_120 )
return V_2 ;
break;
default:
V_37 = F_88 ( V_54 -> type ) ;
if ( ! V_37 )
return V_131 ;
V_2 = V_37 -> V_132 -> V_18 ( V_75 , V_125 , V_37 ) ;
if ( V_2 != V_120 )
return V_2 ;
}
if ( F_78 ( V_60 ) )
goto V_133;
if ( V_60 -> V_39 [ V_60 -> V_87 . V_67 - 1 ] == '\n' ) {
V_60 -> V_39 [ V_60 -> V_87 . V_67 - 1 ] = '\0' ;
V_60 -> V_87 . V_67 -- ;
}
F_60 ( V_60 , L_29 ) ;
V_133:
return F_76 ( V_60 ) ;
}
enum V_108
F_89 ( struct V_74 * V_75 , T_3 V_31 )
{
struct V_41 * V_118 ;
struct V_70 * V_49 = V_75 -> V_77 ;
struct V_69 * V_42 = V_75 -> V_54 ;
struct V_59 * V_60 = & V_75 -> V_87 ;
int V_51 = V_75 -> V_51 ;
int V_2 ;
if ( V_49 && F_32 ( V_49 -> V_73 , V_51 ) -> V_134 ) {
F_32 ( V_49 -> V_73 , V_51 ) -> V_134 = 0 ;
return V_120 ;
}
if ( V_49 && V_49 -> V_81 ) {
V_118 = & V_49 -> V_54 ;
V_75 -> V_51 = V_49 -> V_51 ;
V_2 = F_82 ( V_118 , V_60 , V_75 , V_31 ) ;
if ( V_2 == V_120 && V_75 -> V_51 != V_51 ) {
F_32 ( V_49 -> V_73 , V_75 -> V_51 ) -> V_134 = 1 ;
V_2 = V_115 ;
}
V_75 -> V_51 = V_51 ;
return V_2 ;
}
switch ( V_42 -> type ) {
case V_43 : {
struct V_41 V_135 ;
F_90 ( V_118 , V_42 ) ;
V_135 = * V_118 ;
return F_82 ( & V_135 , V_60 , V_75 , V_31 ) ;
}
case V_58 : {
struct V_57 * V_118 ;
F_90 ( V_118 , V_42 ) ;
return F_83 ( & V_118 -> V_2 , V_60 , V_42 , V_75 , V_31 ) ;
}
case V_136 :
case V_137 :
return V_131 ;
default:
return F_84 ( V_60 , V_42 , V_75 , V_31 ) ;
}
return V_120 ;
}
static enum V_108
F_91 ( struct V_74 * V_75 )
{
return F_89 ( V_75 , V_138 . V_139 ) ;
}
static enum V_108
F_92 ( struct V_74 * V_75 , int V_31 ,
struct V_127 * V_37 )
{
return F_91 ( V_75 ) ;
}
static void F_93 ( struct V_140 * V_60 , T_3 V_31 )
{
static const char V_66 [] = L_30
L_31
L_32 ;
int V_141 = 0 ;
if ( V_31 & V_92 )
V_141 += 16 ;
if ( V_31 & V_94 )
V_141 += 4 ;
if ( V_31 & V_95 )
V_141 += 17 ;
F_94 ( V_60 , L_33 , V_141 , V_66 ) ;
F_94 ( V_60 , L_34 , V_141 , V_66 ) ;
F_94 ( V_60 , L_35 , V_141 , V_66 ) ;
F_94 ( V_60 , L_36 , V_141 , V_66 ) ;
F_94 ( V_60 , L_37 , V_141 , V_66 ) ;
}
static void F_95 ( struct V_28 * V_29 ,
struct V_140 * V_60 , T_3 V_31 )
{
int V_142 = V_29 -> V_90 & V_96 ;
if ( V_142 )
F_93 ( V_60 , V_31 ) ;
F_96 ( V_60 , '#' ) ;
if ( V_31 & V_92 )
F_97 ( V_60 , L_38 ) ;
if ( V_31 & V_94 )
F_97 ( V_60 , L_39 ) ;
if ( V_31 & V_95 )
F_97 ( V_60 , L_40 ) ;
if ( V_142 )
F_97 ( V_60 , L_41 ) ;
if ( V_31 & V_104 )
F_97 ( V_60 , L_42 ) ;
F_97 ( V_60 , L_43 ) ;
F_96 ( V_60 , '#' ) ;
if ( V_31 & V_92 )
F_97 ( V_60 , L_44 ) ;
if ( V_31 & V_94 )
F_97 ( V_60 , L_45 ) ;
if ( V_31 & V_95 )
F_97 ( V_60 , L_46 ) ;
if ( V_142 )
F_97 ( V_60 , L_41 ) ;
if ( V_31 & V_104 )
F_97 ( V_60 , L_47 ) ;
F_97 ( V_60 , L_48 ) ;
}
static void F_98 ( struct V_140 * V_60 )
{
F_99 ( V_60 , V_138 . V_139 ) ;
}
void F_99 ( struct V_140 * V_60 , T_3 V_31 )
{
struct V_74 * V_75 = V_60 -> V_77 ;
struct V_28 * V_29 = V_75 -> V_29 ;
if ( ! ( V_29 -> V_90 & V_91 ) )
return;
if ( V_29 -> V_90 & V_96 ) {
if ( F_100 ( V_75 ) )
return;
F_101 ( V_60 , V_75 ) ;
}
F_95 ( V_29 , V_60 , V_31 ) ;
}
void F_102 ( struct V_74 * V_75 )
{
struct V_70 * V_49 ;
T_5 V_143 ;
int V_51 ;
V_75 -> V_77 = NULL ;
V_143 = ( F_103 () || F_104 () ) ? V_144 : V_145 ;
V_49 = F_105 ( sizeof( * V_49 ) , V_143 ) ;
if ( ! V_49 )
goto V_146;
V_49 -> V_73 = F_106 ( struct V_111 , V_143 ) ;
if ( ! V_49 -> V_73 )
goto V_147;
F_107 (cpu) {
T_2 * V_62 = & ( F_32 ( V_49 -> V_73 , V_51 ) -> V_72 ) ;
int * V_4 = & ( F_32 ( V_49 -> V_73 , V_51 ) -> V_4 ) ;
int * V_134 = & ( F_32 ( V_49 -> V_73 , V_51 ) -> V_134 ) ;
int * V_116 = & ( F_32 ( V_49 -> V_73 , V_51 ) -> V_116 ) ;
* V_62 = - 1 ;
* V_4 = 0 ;
* V_134 = 0 ;
* V_116 = - 1 ;
}
V_75 -> V_77 = V_49 ;
return;
V_147:
F_108 ( V_49 ) ;
V_146:
F_109 ( L_49 ) ;
}
void F_110 ( struct V_74 * V_75 )
{
struct V_70 * V_49 = V_75 -> V_77 ;
if ( V_49 ) {
F_111 ( V_49 -> V_73 ) ;
F_108 ( V_49 ) ;
}
}
static int
F_112 ( struct V_28 * V_29 , T_3 V_148 , T_3 V_149 , int V_150 )
{
if ( V_149 == V_117 )
V_45 = ! V_150 ;
if ( V_149 == V_151 )
F_113 ( V_150 ) ;
if ( V_149 == V_152 )
F_114 ( V_150 ) ;
return 0 ;
}
static T_6
F_115 ( struct V_153 * V_154 , const char T_7 * V_155 , T_4 V_156 ,
T_8 * V_157 )
{
unsigned long V_139 ;
int V_2 ;
V_2 = F_116 ( V_155 , V_156 , 10 , & V_139 ) ;
if ( V_2 )
return V_2 ;
V_158 = V_139 ;
* V_157 += V_156 ;
return V_156 ;
}
static T_6
F_117 ( struct V_153 * V_154 , char T_7 * V_155 , T_4 V_156 ,
T_8 * V_157 )
{
char V_159 [ 15 ] ;
int V_160 ;
V_160 = sprintf ( V_159 , L_50 , V_158 ) ;
return F_118 ( V_155 , V_156 , V_157 , V_159 , V_160 ) ;
}
static T_9 int F_119 ( void )
{
struct V_161 * V_162 ;
V_162 = F_120 () ;
if ( F_121 ( V_162 ) )
return 0 ;
F_122 ( L_51 , 0644 , V_162 ,
NULL , & V_163 ) ;
return 0 ;
}
static T_9 int F_123 ( void )
{
V_61 = snprintf ( NULL , 0 , L_52 , V_164 - 1 ) ;
if ( ! F_124 ( & V_165 ) ) {
F_109 ( L_53 ) ;
return 1 ;
}
if ( ! F_124 ( & V_166 ) ) {
F_109 ( L_53 ) ;
return 1 ;
}
return F_125 ( & V_167 ) ;
}
