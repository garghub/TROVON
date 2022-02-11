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
static void F_52 ( struct V_57 * V_58 , int V_48 )
{
F_53 ( V_58 , L_3 , V_59 , V_48 ) ;
}
static void F_54 ( struct V_57 * V_58 , T_2 V_60 )
{
char V_61 [ V_62 ] ;
char V_63 [ 11 ] ;
int V_64 = 0 ;
int V_65 ;
int V_66 ;
F_55 ( V_60 , V_61 ) ;
V_61 [ 7 ] = '\0' ;
sprintf ( V_63 , L_4 , V_60 ) ;
V_65 = strlen ( V_61 ) + strlen ( V_63 ) + 1 ;
if ( V_65 < V_67 )
V_64 = V_67 - V_65 ;
for ( V_66 = 0 ; V_66 < V_64 / 2 ; V_66 ++ )
F_56 ( V_58 , ' ' ) ;
F_53 ( V_58 , L_5 , V_61 , V_63 ) ;
for ( V_66 = 0 ; V_66 < V_64 - ( V_64 / 2 ) ; V_66 ++ )
F_56 ( V_58 , ' ' ) ;
}
static void F_57 ( struct V_57 * V_58 , struct V_68 * V_38 )
{
F_56 ( V_58 , ' ' ) ;
F_58 ( V_58 , V_38 ) ;
}
static void
F_59 ( struct V_57 * V_58 , T_2 V_60 , int V_48 , struct V_69 * V_46 )
{
T_2 V_70 ;
T_2 * V_71 ;
if ( ! V_46 )
return;
V_71 = & ( F_31 ( V_46 -> V_72 , V_48 ) -> V_71 ) ;
if ( * V_71 == V_60 )
return;
V_70 = * V_71 ;
* V_71 = V_60 ;
if ( V_70 == - 1 )
return;
F_60 ( V_58 , L_6 ) ;
F_52 ( V_58 , V_48 ) ;
F_54 ( V_58 , V_70 ) ;
F_60 ( V_58 , L_7 ) ;
F_54 ( V_58 , V_60 ) ;
F_60 ( V_58 , L_8 ) ;
}
static struct V_55 *
F_61 ( struct V_73 * V_74 ,
struct V_37 * V_75 )
{
struct V_69 * V_46 = V_74 -> V_76 ;
struct V_77 * V_78 = NULL ;
struct V_32 * V_33 ;
struct V_55 * V_79 ;
if ( V_46 && V_46 -> V_80 ) {
V_75 = & V_46 -> V_52 ;
V_79 = & V_46 -> V_2 ;
} else {
V_78 = F_62 ( V_74 , V_74 -> V_48 ) ;
if ( V_78 )
V_33 = F_63 ( V_78 , NULL ) ;
else {
F_64 ( V_74 -> V_36 -> V_35 , V_74 -> V_48 ,
NULL , NULL ) ;
V_33 = F_65 ( V_74 -> V_36 -> V_35 , V_74 -> V_48 ,
NULL , NULL ) ;
}
if ( ! V_33 )
return NULL ;
V_79 = F_20 ( V_33 ) ;
if ( V_46 ) {
V_46 -> V_52 = * V_75 ;
if ( V_79 -> V_52 . type == V_56 )
V_46 -> V_2 = * V_79 ;
else
V_46 -> V_2 . V_52 . type = V_79 -> V_52 . type ;
}
}
if ( V_79 -> V_52 . type != V_56 )
return NULL ;
if ( V_75 -> V_52 . V_60 != V_79 -> V_52 . V_60 ||
V_75 -> V_41 . V_3 != V_79 -> V_2 . V_3 )
return NULL ;
if ( V_78 )
F_66 ( V_78 , NULL ) ;
return V_79 ;
}
static void F_67 ( T_1 V_81 , struct V_57 * V_58 )
{
unsigned long V_82 ;
V_82 = F_68 ( V_81 , V_83 ) ;
V_82 /= 1000 ;
F_53 ( V_58 , L_9 ,
( unsigned long ) V_81 , V_82 ) ;
}
static void
F_69 ( struct V_73 * V_74 , unsigned long V_84 ,
enum V_85 type , int V_48 , T_2 V_60 , T_3 V_27 )
{
struct V_57 * V_58 = & V_74 -> V_86 ;
struct V_68 * V_52 = V_74 -> V_52 ;
if ( V_84 < ( unsigned long ) V_87 ||
V_84 >= ( unsigned long ) V_88 )
return;
if ( V_89 & V_90 ) {
if ( V_27 & V_91 )
F_67 ( V_74 -> V_92 , V_58 ) ;
if ( V_27 & V_93 )
F_52 ( V_58 , V_48 ) ;
if ( V_27 & V_94 ) {
F_54 ( V_58 , V_60 ) ;
F_60 ( V_58 , L_10 ) ;
}
if ( V_89 & V_95 )
F_57 ( V_58 , V_52 ) ;
}
F_70 ( 0 , V_58 , V_27 | V_96 ) ;
if ( type == V_40 )
F_60 ( V_58 , L_11 ) ;
else
F_60 ( V_58 , L_12 ) ;
F_70 ( 0 , V_58 , V_27 | V_97 ) ;
F_56 ( V_58 , '\n' ) ;
}
void
F_71 ( unsigned long long V_98 , struct V_57 * V_58 )
{
unsigned long V_99 = F_68 ( V_98 , 1000 ) ;
char V_100 [ 21 ] ;
char V_101 [ 5 ] ;
int V_65 ;
int V_66 ;
sprintf ( V_100 , L_13 , ( unsigned long ) V_98 ) ;
F_53 ( V_58 , L_14 , V_100 ) ;
V_65 = strlen ( V_100 ) ;
if ( V_65 < 7 ) {
T_4 V_102 = F_72 ( T_4 , sizeof( V_101 ) , 8UL - V_65 ) ;
snprintf ( V_101 , V_102 , L_15 , V_99 ) ;
F_53 ( V_58 , L_16 , V_101 ) ;
V_65 += strlen ( V_101 ) ;
}
F_60 ( V_58 , L_17 ) ;
for ( V_66 = V_65 ; V_66 < 7 ; V_66 ++ )
F_56 ( V_58 , ' ' ) ;
}
static void
F_70 ( unsigned long long V_98 , struct V_57 * V_58 ,
T_3 V_27 )
{
if ( ! ( V_27 & V_103 ) ||
! ( V_89 & V_90 ) )
return;
switch ( V_27 & V_104 ) {
case V_105 :
F_60 ( V_58 , L_18 ) ;
return;
case V_96 :
F_60 ( V_58 , L_19 ) ;
return;
case V_97 :
F_60 ( V_58 , L_20 ) ;
return;
}
if ( V_27 & V_106 )
F_53 ( V_58 , L_21 , F_73 ( V_98 ) ) ;
else
F_60 ( V_58 , L_19 ) ;
F_71 ( V_98 , V_58 ) ;
F_60 ( V_58 , L_22 ) ;
}
static enum V_107
F_74 ( struct V_73 * V_74 ,
struct V_37 * V_38 ,
struct V_55 * V_108 ,
struct V_57 * V_58 , T_3 V_27 )
{
struct V_69 * V_46 = V_74 -> V_76 ;
struct V_17 * V_109 ;
struct V_26 * V_30 ;
unsigned long long V_98 ;
int V_66 ;
V_109 = & V_108 -> V_2 ;
V_30 = & V_38 -> V_41 ;
V_98 = V_109 -> V_23 - V_109 -> V_6 ;
if ( V_46 ) {
struct V_110 * V_72 ;
int V_48 = V_74 -> V_48 ;
V_72 = F_31 ( V_46 -> V_72 , V_48 ) ;
V_72 -> V_4 = V_30 -> V_4 - 1 ;
if ( V_30 -> V_4 < V_12 )
V_72 -> V_111 [ V_30 -> V_4 ] = 0 ;
}
F_70 ( V_98 , V_58 , V_27 ) ;
for ( V_66 = 0 ; V_66 < V_30 -> V_4 * V_112 ; V_66 ++ )
F_56 ( V_58 , ' ' ) ;
F_53 ( V_58 , L_23 , ( void * ) V_30 -> V_3 ) ;
return F_75 ( V_58 ) ;
}
static enum V_107
F_76 ( struct V_73 * V_74 ,
struct V_37 * V_38 ,
struct V_57 * V_58 , int V_48 , T_3 V_27 )
{
struct V_26 * V_30 = & V_38 -> V_41 ;
struct V_69 * V_46 = V_74 -> V_76 ;
int V_66 ;
if ( V_46 ) {
struct V_110 * V_72 ;
int V_48 = V_74 -> V_48 ;
V_72 = F_31 ( V_46 -> V_72 , V_48 ) ;
V_72 -> V_4 = V_30 -> V_4 ;
if ( V_30 -> V_4 < V_12 )
V_72 -> V_111 [ V_30 -> V_4 ] = V_30 -> V_3 ;
}
F_70 ( 0 , V_58 , V_27 | V_105 ) ;
for ( V_66 = 0 ; V_66 < V_30 -> V_4 * V_112 ; V_66 ++ )
F_56 ( V_58 , ' ' ) ;
F_53 ( V_58 , L_24 , ( void * ) V_30 -> V_3 ) ;
if ( F_77 ( V_58 ) )
return V_113 ;
return V_114 ;
}
static void
F_78 ( struct V_73 * V_74 , struct V_57 * V_58 ,
int type , unsigned long V_84 , T_3 V_27 )
{
struct V_69 * V_46 = V_74 -> V_76 ;
struct V_68 * V_52 = V_74 -> V_52 ;
int V_48 = V_74 -> V_48 ;
F_59 ( V_58 , V_52 -> V_60 , V_48 , V_46 ) ;
if ( type )
F_69 ( V_74 , V_84 , type , V_48 , V_52 -> V_60 , V_27 ) ;
if ( ! ( V_89 & V_90 ) )
return;
if ( V_27 & V_91 )
F_67 ( V_74 -> V_92 , V_58 ) ;
if ( V_27 & V_93 )
F_52 ( V_58 , V_48 ) ;
if ( V_27 & V_94 ) {
F_54 ( V_58 , V_52 -> V_60 ) ;
F_60 ( V_58 , L_10 ) ;
}
if ( V_89 & V_95 )
F_57 ( V_58 , V_52 ) ;
return;
}
static int
F_79 ( struct V_73 * V_74 , T_3 V_27 ,
unsigned long V_84 , int V_4 )
{
int V_48 = V_74 -> V_48 ;
int * V_115 ;
struct V_69 * V_46 = V_74 -> V_76 ;
if ( ( V_27 & V_116 ) ||
( ! V_46 ) )
return 0 ;
V_115 = & ( F_31 ( V_46 -> V_72 , V_48 ) -> V_115 ) ;
if ( * V_115 >= 0 )
return 1 ;
if ( ( V_84 < ( unsigned long ) V_87 ) ||
( V_84 >= ( unsigned long ) V_88 ) )
return 0 ;
* V_115 = V_4 ;
return 1 ;
}
static int
F_80 ( struct V_73 * V_74 , T_3 V_27 , int V_4 )
{
int V_48 = V_74 -> V_48 ;
int * V_115 ;
struct V_69 * V_46 = V_74 -> V_76 ;
if ( ( V_27 & V_116 ) ||
( ! V_46 ) )
return 0 ;
V_115 = & ( F_31 ( V_46 -> V_72 , V_48 ) -> V_115 ) ;
if ( * V_115 == - 1 )
return 0 ;
if ( * V_115 >= V_4 ) {
* V_115 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_107
F_81 ( struct V_37 * V_117 , struct V_57 * V_58 ,
struct V_73 * V_74 , T_3 V_27 )
{
struct V_69 * V_46 = V_74 -> V_76 ;
struct V_26 * V_30 = & V_117 -> V_41 ;
struct V_55 * V_118 ;
static enum V_107 V_2 ;
int V_48 = V_74 -> V_48 ;
if ( F_79 ( V_74 , V_27 , V_30 -> V_3 , V_30 -> V_4 ) )
return V_119 ;
F_78 ( V_74 , V_58 , V_40 , V_30 -> V_3 , V_27 ) ;
V_118 = F_61 ( V_74 , V_117 ) ;
if ( V_118 )
V_2 = F_74 ( V_74 , V_117 , V_118 , V_58 , V_27 ) ;
else
V_2 = F_76 ( V_74 , V_117 , V_58 , V_48 , V_27 ) ;
if ( V_46 ) {
if ( V_58 -> V_120 ) {
V_46 -> V_80 = 1 ;
V_46 -> V_48 = V_48 ;
} else
V_46 -> V_80 = 0 ;
}
return V_2 ;
}
static enum V_107
F_82 ( struct V_17 * V_18 , struct V_57 * V_58 ,
struct V_68 * V_52 , struct V_73 * V_74 ,
T_3 V_27 )
{
unsigned long long V_98 = V_18 -> V_23 - V_18 -> V_6 ;
struct V_69 * V_46 = V_74 -> V_76 ;
T_2 V_60 = V_52 -> V_60 ;
int V_48 = V_74 -> V_48 ;
int V_121 = 1 ;
int V_66 ;
if ( F_80 ( V_74 , V_27 , V_18 -> V_4 ) )
return V_119 ;
if ( V_46 ) {
struct V_110 * V_72 ;
int V_48 = V_74 -> V_48 ;
V_72 = F_31 ( V_46 -> V_72 , V_48 ) ;
V_72 -> V_4 = V_18 -> V_4 - 1 ;
if ( V_18 -> V_4 < V_12 ) {
if ( V_72 -> V_111 [ V_18 -> V_4 ] != V_18 -> V_3 )
V_121 = 0 ;
V_72 -> V_111 [ V_18 -> V_4 ] = 0 ;
}
}
F_78 ( V_74 , V_58 , 0 , 0 , V_27 ) ;
F_70 ( V_98 , V_58 , V_27 ) ;
for ( V_66 = 0 ; V_66 < V_18 -> V_4 * V_112 ; V_66 ++ )
F_56 ( V_58 , ' ' ) ;
if ( V_121 && ! ( V_27 & V_122 ) )
F_60 ( V_58 , L_25 ) ;
else
F_53 ( V_58 , L_26 , ( void * ) V_18 -> V_3 ) ;
if ( V_27 & V_123 )
F_53 ( V_58 , L_27 ,
V_18 -> V_22 ) ;
F_69 ( V_74 , V_18 -> V_3 , V_56 ,
V_48 , V_60 , V_27 ) ;
return F_75 ( V_58 ) ;
}
static enum V_107
F_83 ( struct V_57 * V_58 , struct V_68 * V_52 ,
struct V_73 * V_74 , T_3 V_27 )
{
unsigned long V_124 = ( V_89 & V_125 ) ;
struct V_69 * V_46 = V_74 -> V_76 ;
struct V_126 * V_33 ;
int V_4 = 0 ;
int V_2 ;
int V_66 ;
if ( V_46 )
V_4 = F_31 ( V_46 -> V_72 , V_74 -> V_48 ) -> V_4 ;
F_78 ( V_74 , V_58 , 0 , 0 , V_27 ) ;
F_70 ( 0 , V_58 , V_27 | V_105 ) ;
if ( V_4 > 0 )
for ( V_66 = 0 ; V_66 < ( V_4 + 1 ) * V_112 ; V_66 ++ )
F_56 ( V_58 , ' ' ) ;
F_60 ( V_58 , L_28 ) ;
switch ( V_74 -> V_52 -> type ) {
case V_127 :
V_2 = F_84 ( V_74 ) ;
if ( V_2 != V_119 )
return V_2 ;
break;
case V_128 :
V_2 = F_85 ( V_74 ) ;
if ( V_2 != V_119 )
return V_2 ;
break;
default:
V_33 = F_86 ( V_52 -> type ) ;
if ( ! V_33 )
return V_129 ;
V_2 = V_33 -> V_130 -> V_18 ( V_74 , V_124 , V_33 ) ;
if ( V_2 != V_119 )
return V_2 ;
}
if ( F_77 ( V_58 ) )
goto V_131;
if ( V_58 -> V_35 [ V_58 -> V_86 . V_65 - 1 ] == '\n' ) {
V_58 -> V_35 [ V_58 -> V_86 . V_65 - 1 ] = '\0' ;
V_58 -> V_86 . V_65 -- ;
}
F_60 ( V_58 , L_29 ) ;
V_131:
return F_75 ( V_58 ) ;
}
enum V_107
F_87 ( struct V_73 * V_74 , T_3 V_27 )
{
struct V_37 * V_117 ;
struct V_69 * V_46 = V_74 -> V_76 ;
struct V_68 * V_38 = V_74 -> V_52 ;
struct V_57 * V_58 = & V_74 -> V_86 ;
int V_48 = V_74 -> V_48 ;
int V_2 ;
if ( V_46 && F_31 ( V_46 -> V_72 , V_48 ) -> V_132 ) {
F_31 ( V_46 -> V_72 , V_48 ) -> V_132 = 0 ;
return V_119 ;
}
if ( V_46 && V_46 -> V_80 ) {
V_117 = & V_46 -> V_52 ;
V_74 -> V_48 = V_46 -> V_48 ;
V_2 = F_81 ( V_117 , V_58 , V_74 , V_27 ) ;
if ( V_2 == V_119 && V_74 -> V_48 != V_48 ) {
F_31 ( V_46 -> V_72 , V_74 -> V_48 ) -> V_132 = 1 ;
V_2 = V_114 ;
}
V_74 -> V_48 = V_48 ;
return V_2 ;
}
switch ( V_38 -> type ) {
case V_40 : {
struct V_37 V_133 ;
F_88 ( V_117 , V_38 ) ;
V_133 = * V_117 ;
return F_81 ( & V_133 , V_58 , V_74 , V_27 ) ;
}
case V_56 : {
struct V_55 * V_117 ;
F_88 ( V_117 , V_38 ) ;
return F_82 ( & V_117 -> V_2 , V_58 , V_38 , V_74 , V_27 ) ;
}
case V_134 :
case V_135 :
return V_129 ;
default:
return F_83 ( V_58 , V_38 , V_74 , V_27 ) ;
}
return V_119 ;
}
static enum V_107
F_89 ( struct V_73 * V_74 )
{
return F_87 ( V_74 , V_136 . V_137 ) ;
}
static enum V_107
F_90 ( struct V_73 * V_74 , int V_27 ,
struct V_126 * V_33 )
{
return F_89 ( V_74 ) ;
}
static void F_91 ( struct V_138 * V_58 , T_3 V_27 )
{
static const char V_64 [] = L_30
L_31
L_32 ;
int V_139 = 0 ;
if ( V_27 & V_91 )
V_139 += 16 ;
if ( V_27 & V_93 )
V_139 += 4 ;
if ( V_27 & V_94 )
V_139 += 17 ;
F_92 ( V_58 , L_33 , V_139 , V_64 ) ;
F_92 ( V_58 , L_34 , V_139 , V_64 ) ;
F_92 ( V_58 , L_35 , V_139 , V_64 ) ;
F_92 ( V_58 , L_36 , V_139 , V_64 ) ;
F_92 ( V_58 , L_37 , V_139 , V_64 ) ;
}
static void F_93 ( struct V_138 * V_58 , T_3 V_27 )
{
int V_140 = V_89 & V_95 ;
if ( V_140 )
F_91 ( V_58 , V_27 ) ;
F_94 ( V_58 , '#' ) ;
if ( V_27 & V_91 )
F_95 ( V_58 , L_38 ) ;
if ( V_27 & V_93 )
F_95 ( V_58 , L_39 ) ;
if ( V_27 & V_94 )
F_95 ( V_58 , L_40 ) ;
if ( V_140 )
F_95 ( V_58 , L_41 ) ;
if ( V_27 & V_103 )
F_95 ( V_58 , L_42 ) ;
F_95 ( V_58 , L_43 ) ;
F_94 ( V_58 , '#' ) ;
if ( V_27 & V_91 )
F_95 ( V_58 , L_44 ) ;
if ( V_27 & V_93 )
F_95 ( V_58 , L_45 ) ;
if ( V_27 & V_94 )
F_95 ( V_58 , L_46 ) ;
if ( V_140 )
F_95 ( V_58 , L_41 ) ;
if ( V_27 & V_103 )
F_95 ( V_58 , L_47 ) ;
F_95 ( V_58 , L_48 ) ;
}
static void F_96 ( struct V_138 * V_58 )
{
F_97 ( V_58 , V_136 . V_137 ) ;
}
void F_97 ( struct V_138 * V_58 , T_3 V_27 )
{
struct V_73 * V_74 = V_58 -> V_76 ;
if ( ! ( V_89 & V_90 ) )
return;
if ( V_89 & V_95 ) {
if ( F_98 ( V_74 ) )
return;
F_99 ( V_58 , V_74 ) ;
}
F_93 ( V_58 , V_27 ) ;
}
void F_100 ( struct V_73 * V_74 )
{
struct V_69 * V_46 ;
int V_48 ;
V_74 -> V_76 = NULL ;
V_46 = F_101 ( sizeof( * V_46 ) , V_141 ) ;
if ( ! V_46 )
goto V_142;
V_46 -> V_72 = F_102 ( struct V_110 ) ;
if ( ! V_46 -> V_72 )
goto V_143;
F_103 (cpu) {
T_2 * V_60 = & ( F_31 ( V_46 -> V_72 , V_48 ) -> V_71 ) ;
int * V_4 = & ( F_31 ( V_46 -> V_72 , V_48 ) -> V_4 ) ;
int * V_132 = & ( F_31 ( V_46 -> V_72 , V_48 ) -> V_132 ) ;
int * V_115 = & ( F_31 ( V_46 -> V_72 , V_48 ) -> V_115 ) ;
* V_60 = - 1 ;
* V_4 = 0 ;
* V_132 = 0 ;
* V_115 = - 1 ;
}
V_74 -> V_76 = V_46 ;
return;
V_143:
F_104 ( V_46 ) ;
V_142:
F_105 ( L_49 ) ;
}
void F_106 ( struct V_73 * V_74 )
{
struct V_69 * V_46 = V_74 -> V_76 ;
if ( V_46 ) {
F_107 ( V_46 -> V_72 ) ;
F_104 ( V_46 ) ;
}
}
static int
F_108 ( struct V_24 * V_25 , T_3 V_144 , T_3 V_145 , int V_146 )
{
if ( V_145 == V_116 )
V_42 = ! V_146 ;
return 0 ;
}
static T_5
F_109 ( struct V_147 * V_148 , const char T_6 * V_149 , T_4 V_150 ,
T_7 * V_151 )
{
unsigned long V_137 ;
int V_2 ;
V_2 = F_110 ( V_149 , V_150 , 10 , & V_137 ) ;
if ( V_2 )
return V_2 ;
V_49 = V_137 ;
* V_151 += V_150 ;
return V_150 ;
}
static T_5
F_111 ( struct V_147 * V_148 , char T_6 * V_149 , T_4 V_150 ,
T_7 * V_151 )
{
char V_152 [ 15 ] ;
int V_153 ;
V_153 = sprintf ( V_152 , L_50 , V_49 ) ;
return F_112 ( V_149 , V_150 , V_151 , V_152 , V_153 ) ;
}
static T_8 int F_113 ( void )
{
struct V_154 * V_155 ;
V_155 = F_114 () ;
if ( F_115 ( V_155 ) )
return 0 ;
F_116 ( L_51 , 0644 , V_155 ,
NULL , & V_156 ) ;
return 0 ;
}
static T_8 int F_117 ( void )
{
V_59 = snprintf ( NULL , 0 , L_4 , V_157 - 1 ) ;
if ( ! F_118 ( & V_158 ) ) {
F_105 ( L_52 ) ;
return 1 ;
}
if ( ! F_118 ( & V_159 ) ) {
F_105 ( L_52 ) ;
return 1 ;
}
return F_119 ( & V_160 ) ;
}
