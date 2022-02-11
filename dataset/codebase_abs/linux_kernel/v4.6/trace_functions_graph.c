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
V_33 = F_18 ( V_35 , V_39 ,
sizeof( * V_38 ) , V_27 , V_28 ) ;
if ( ! V_33 )
return 0 ;
V_38 = F_19 ( V_33 ) ;
V_38 -> V_40 = * V_18 ;
if ( ! F_20 ( V_30 , V_38 , V_35 , V_33 ) )
F_21 ( V_35 , V_33 ) ;
return 1 ;
}
static inline int F_22 ( void )
{
if ( ! V_41 || F_23 ( V_42 ) )
return 0 ;
return F_24 () ;
}
int F_25 ( struct V_26 * V_18 )
{
struct V_24 * V_25 = V_43 ;
struct V_44 * V_45 ;
unsigned long V_27 ;
long V_46 ;
int V_2 ;
int V_47 ;
int V_28 ;
if ( ! F_26 ( V_9 ) )
return 0 ;
if ( ( ! ( V_18 -> V_4 || F_27 ( V_18 -> V_3 ) ) ||
F_22 () ) || ( V_18 -> V_4 < 0 ) ||
( V_48 && V_18 -> V_4 >= V_48 ) )
return 0 ;
if ( F_8 ( V_18 -> V_3 ) )
return 1 ;
F_28 ( V_27 ) ;
V_47 = F_29 () ;
V_45 = F_30 ( V_25 -> V_36 . V_45 , V_47 ) ;
V_46 = F_31 ( & V_45 -> V_46 ) ;
if ( F_32 ( V_46 == 1 ) ) {
V_28 = F_33 () ;
V_2 = F_17 ( V_25 , V_18 , V_27 , V_28 ) ;
} else {
V_2 = 0 ;
}
F_34 ( & V_45 -> V_46 ) ;
F_35 ( V_27 ) ;
return V_2 ;
}
static int F_36 ( struct V_26 * V_18 )
{
if ( V_49 )
return 1 ;
else
return F_25 ( V_18 ) ;
}
static void
F_37 ( struct V_24 * V_25 ,
unsigned long V_50 , unsigned long V_27 , int V_28 )
{
T_1 time = F_7 () ;
struct V_26 V_51 = {
. V_3 = V_50 ,
. V_4 = 0 ,
} ;
struct V_17 V_2 = {
. V_3 = V_50 ,
. V_4 = 0 ,
. V_6 = time ,
. V_23 = time ,
} ;
F_17 ( V_25 , & V_51 , V_27 , V_28 ) ;
F_38 ( V_25 , & V_2 , V_27 , V_28 ) ;
}
void
F_39 ( struct V_24 * V_25 ,
unsigned long V_50 , unsigned long V_52 ,
unsigned long V_27 , int V_28 )
{
F_37 ( V_25 , V_50 , V_27 , V_28 ) ;
}
void F_38 ( struct V_24 * V_25 ,
struct V_17 * V_18 ,
unsigned long V_27 ,
int V_28 )
{
struct V_29 * V_30 = & V_53 ;
struct V_32 * V_33 ;
struct V_34 * V_35 = V_25 -> V_36 . V_35 ;
struct V_54 * V_38 ;
V_33 = F_18 ( V_35 , V_55 ,
sizeof( * V_38 ) , V_27 , V_28 ) ;
if ( ! V_33 )
return;
V_38 = F_19 ( V_33 ) ;
V_38 -> V_2 = * V_18 ;
if ( ! F_20 ( V_30 , V_38 , V_35 , V_33 ) )
F_21 ( V_35 , V_33 ) ;
}
void F_40 ( struct V_17 * V_18 )
{
struct V_24 * V_25 = V_43 ;
struct V_44 * V_45 ;
unsigned long V_27 ;
long V_46 ;
int V_47 ;
int V_28 ;
F_28 ( V_27 ) ;
V_47 = F_29 () ;
V_45 = F_30 ( V_25 -> V_36 . V_45 , V_47 ) ;
V_46 = F_31 ( & V_45 -> V_46 ) ;
if ( F_32 ( V_46 == 1 ) ) {
V_28 = F_33 () ;
F_38 ( V_25 , V_18 , V_27 , V_28 ) ;
}
F_34 ( & V_45 -> V_46 ) ;
F_35 ( V_27 ) ;
}
void F_41 ( struct V_24 * V_25 )
{
V_43 = V_25 ;
F_42 () ;
}
static void F_43 ( struct V_17 * V_18 )
{
if ( V_49 &&
( V_18 -> V_23 - V_18 -> V_6 < V_49 ) )
return;
else
F_40 ( V_18 ) ;
}
static int F_44 ( struct V_24 * V_25 )
{
int V_2 ;
F_41 ( V_25 ) ;
if ( V_49 )
V_2 = F_45 ( & F_43 ,
& F_36 ) ;
else
V_2 = F_45 ( & F_40 ,
& F_25 ) ;
if ( V_2 )
return V_2 ;
F_46 () ;
return 0 ;
}
static void F_47 ( struct V_24 * V_25 )
{
F_48 () ;
F_49 () ;
}
static int F_50 ( struct V_24 * V_25 )
{
F_47 ( V_25 ) ;
return F_44 ( V_25 ) ;
}
static void F_51 ( struct V_56 * V_57 , int V_47 )
{
F_52 ( V_57 , L_3 , V_58 , V_47 ) ;
}
static void F_53 ( struct V_56 * V_57 , T_2 V_59 )
{
char V_60 [ V_61 ] ;
char V_62 [ 11 ] ;
int V_63 = 0 ;
int V_64 ;
int V_65 ;
F_54 ( V_59 , V_60 ) ;
V_60 [ 7 ] = '\0' ;
sprintf ( V_62 , L_4 , V_59 ) ;
V_64 = strlen ( V_60 ) + strlen ( V_62 ) + 1 ;
if ( V_64 < V_66 )
V_63 = V_66 - V_64 ;
for ( V_65 = 0 ; V_65 < V_63 / 2 ; V_65 ++ )
F_55 ( V_57 , ' ' ) ;
F_52 ( V_57 , L_5 , V_60 , V_62 ) ;
for ( V_65 = 0 ; V_65 < V_63 - ( V_63 / 2 ) ; V_65 ++ )
F_55 ( V_57 , ' ' ) ;
}
static void F_56 ( struct V_56 * V_57 , struct V_67 * V_38 )
{
F_55 ( V_57 , ' ' ) ;
F_57 ( V_57 , V_38 ) ;
}
static void
F_58 ( struct V_56 * V_57 , T_2 V_59 , int V_47 , struct V_68 * V_45 )
{
T_2 V_69 ;
T_2 * V_70 ;
if ( ! V_45 )
return;
V_70 = & ( F_30 ( V_45 -> V_71 , V_47 ) -> V_70 ) ;
if ( * V_70 == V_59 )
return;
V_69 = * V_70 ;
* V_70 = V_59 ;
if ( V_69 == - 1 )
return;
F_59 ( V_57 , L_6 ) ;
F_51 ( V_57 , V_47 ) ;
F_53 ( V_57 , V_69 ) ;
F_59 ( V_57 , L_7 ) ;
F_53 ( V_57 , V_59 ) ;
F_59 ( V_57 , L_8 ) ;
}
static struct V_54 *
F_60 ( struct V_72 * V_73 ,
struct V_37 * V_74 )
{
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_76 * V_77 = NULL ;
struct V_32 * V_33 ;
struct V_54 * V_78 ;
if ( V_45 && V_45 -> V_79 ) {
V_74 = & V_45 -> V_51 ;
V_78 = & V_45 -> V_2 ;
} else {
V_77 = F_61 ( V_73 , V_73 -> V_47 ) ;
if ( V_77 )
V_33 = F_62 ( V_77 , NULL ) ;
else {
F_63 ( V_73 -> V_36 -> V_35 , V_73 -> V_47 ,
NULL , NULL ) ;
V_33 = F_64 ( V_73 -> V_36 -> V_35 , V_73 -> V_47 ,
NULL , NULL ) ;
}
if ( ! V_33 )
return NULL ;
V_78 = F_19 ( V_33 ) ;
if ( V_45 ) {
V_45 -> V_51 = * V_74 ;
if ( V_78 -> V_51 . type == V_55 )
V_45 -> V_2 = * V_78 ;
else
V_45 -> V_2 . V_51 . type = V_78 -> V_51 . type ;
}
}
if ( V_78 -> V_51 . type != V_55 )
return NULL ;
if ( V_74 -> V_51 . V_59 != V_78 -> V_51 . V_59 ||
V_74 -> V_40 . V_3 != V_78 -> V_2 . V_3 )
return NULL ;
if ( V_77 )
F_65 ( V_77 , NULL ) ;
return V_78 ;
}
static void F_66 ( T_1 V_80 , struct V_56 * V_57 )
{
unsigned long V_81 ;
V_81 = F_67 ( V_80 , V_82 ) ;
V_81 /= 1000 ;
F_52 ( V_57 , L_9 ,
( unsigned long ) V_80 , V_81 ) ;
}
static void
F_68 ( struct V_72 * V_73 , unsigned long V_83 ,
enum V_84 type , int V_47 , T_2 V_59 , T_3 V_27 )
{
struct V_24 * V_25 = V_73 -> V_25 ;
struct V_56 * V_57 = & V_73 -> V_85 ;
struct V_67 * V_51 = V_73 -> V_51 ;
if ( V_83 < ( unsigned long ) V_86 ||
V_83 >= ( unsigned long ) V_87 )
return;
if ( V_25 -> V_88 & V_89 ) {
if ( V_27 & V_90 )
F_66 ( V_73 -> V_91 , V_57 ) ;
if ( V_27 & V_92 )
F_51 ( V_57 , V_47 ) ;
if ( V_27 & V_93 ) {
F_53 ( V_57 , V_59 ) ;
F_59 ( V_57 , L_10 ) ;
}
if ( V_25 -> V_88 & V_94 )
F_56 ( V_57 , V_51 ) ;
}
F_69 ( V_25 , 0 , V_57 , V_27 | V_95 ) ;
if ( type == V_39 )
F_59 ( V_57 , L_11 ) ;
else
F_59 ( V_57 , L_12 ) ;
F_69 ( V_25 , 0 , V_57 , V_27 | V_96 ) ;
F_55 ( V_57 , '\n' ) ;
}
void
F_70 ( unsigned long long V_97 , struct V_56 * V_57 )
{
unsigned long V_98 = F_67 ( V_97 , 1000 ) ;
char V_99 [ 21 ] ;
char V_100 [ 5 ] ;
int V_64 ;
int V_65 ;
sprintf ( V_99 , L_13 , ( unsigned long ) V_97 ) ;
F_52 ( V_57 , L_14 , V_99 ) ;
V_64 = strlen ( V_99 ) ;
if ( V_64 < 7 ) {
T_4 V_101 = F_71 ( T_4 , sizeof( V_100 ) , 8UL - V_64 ) ;
snprintf ( V_100 , V_101 , L_15 , V_98 ) ;
F_52 ( V_57 , L_16 , V_100 ) ;
V_64 += strlen ( V_100 ) + 1 ;
}
F_59 ( V_57 , L_17 ) ;
for ( V_65 = V_64 ; V_65 < 8 ; V_65 ++ )
F_55 ( V_57 , ' ' ) ;
}
static void
F_69 ( struct V_24 * V_25 , unsigned long long V_97 ,
struct V_56 * V_57 , T_3 V_27 )
{
if ( ! ( V_27 & V_102 ) ||
! ( V_25 -> V_88 & V_89 ) )
return;
switch ( V_27 & V_103 ) {
case V_104 :
F_59 ( V_57 , L_18 ) ;
return;
case V_95 :
F_59 ( V_57 , L_19 ) ;
return;
case V_96 :
F_59 ( V_57 , L_20 ) ;
return;
}
if ( V_27 & V_105 )
F_52 ( V_57 , L_21 , F_72 ( V_97 ) ) ;
else
F_59 ( V_57 , L_19 ) ;
F_70 ( V_97 , V_57 ) ;
F_59 ( V_57 , L_22 ) ;
}
static enum V_106
F_73 ( struct V_72 * V_73 ,
struct V_37 * V_38 ,
struct V_54 * V_107 ,
struct V_56 * V_57 , T_3 V_27 )
{
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_24 * V_25 = V_73 -> V_25 ;
struct V_17 * V_108 ;
struct V_26 * V_30 ;
unsigned long long V_97 ;
int V_65 ;
V_108 = & V_107 -> V_2 ;
V_30 = & V_38 -> V_40 ;
V_97 = V_108 -> V_23 - V_108 -> V_6 ;
if ( V_45 ) {
struct V_109 * V_71 ;
int V_47 = V_73 -> V_47 ;
V_71 = F_30 ( V_45 -> V_71 , V_47 ) ;
V_71 -> V_4 = V_30 -> V_4 - 1 ;
if ( V_30 -> V_4 < V_12 )
V_71 -> V_110 [ V_30 -> V_4 ] = 0 ;
}
F_69 ( V_25 , V_97 , V_57 , V_27 ) ;
for ( V_65 = 0 ; V_65 < V_30 -> V_4 * V_111 ; V_65 ++ )
F_55 ( V_57 , ' ' ) ;
F_52 ( V_57 , L_23 , ( void * ) V_30 -> V_3 ) ;
return F_74 ( V_57 ) ;
}
static enum V_106
F_75 ( struct V_72 * V_73 ,
struct V_37 * V_38 ,
struct V_56 * V_57 , int V_47 , T_3 V_27 )
{
struct V_26 * V_30 = & V_38 -> V_40 ;
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_24 * V_25 = V_73 -> V_25 ;
int V_65 ;
if ( V_45 ) {
struct V_109 * V_71 ;
int V_47 = V_73 -> V_47 ;
V_71 = F_30 ( V_45 -> V_71 , V_47 ) ;
V_71 -> V_4 = V_30 -> V_4 ;
if ( V_30 -> V_4 < V_12 )
V_71 -> V_110 [ V_30 -> V_4 ] = V_30 -> V_3 ;
}
F_69 ( V_25 , 0 , V_57 , V_27 | V_104 ) ;
for ( V_65 = 0 ; V_65 < V_30 -> V_4 * V_111 ; V_65 ++ )
F_55 ( V_57 , ' ' ) ;
F_52 ( V_57 , L_24 , ( void * ) V_30 -> V_3 ) ;
if ( F_76 ( V_57 ) )
return V_112 ;
return V_113 ;
}
static void
F_77 ( struct V_72 * V_73 , struct V_56 * V_57 ,
int type , unsigned long V_83 , T_3 V_27 )
{
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_67 * V_51 = V_73 -> V_51 ;
struct V_24 * V_25 = V_73 -> V_25 ;
int V_47 = V_73 -> V_47 ;
F_58 ( V_57 , V_51 -> V_59 , V_47 , V_45 ) ;
if ( type )
F_68 ( V_73 , V_83 , type , V_47 , V_51 -> V_59 , V_27 ) ;
if ( ! ( V_25 -> V_88 & V_89 ) )
return;
if ( V_27 & V_90 )
F_66 ( V_73 -> V_91 , V_57 ) ;
if ( V_27 & V_92 )
F_51 ( V_57 , V_47 ) ;
if ( V_27 & V_93 ) {
F_53 ( V_57 , V_51 -> V_59 ) ;
F_59 ( V_57 , L_10 ) ;
}
if ( V_25 -> V_88 & V_94 )
F_56 ( V_57 , V_51 ) ;
return;
}
static int
F_78 ( struct V_72 * V_73 , T_3 V_27 ,
unsigned long V_83 , int V_4 )
{
int V_47 = V_73 -> V_47 ;
int * V_114 ;
struct V_68 * V_45 = V_73 -> V_75 ;
if ( ( V_27 & V_115 ) ||
( ! V_45 ) )
return 0 ;
V_114 = & ( F_30 ( V_45 -> V_71 , V_47 ) -> V_114 ) ;
if ( * V_114 >= 0 )
return 1 ;
if ( ( V_83 < ( unsigned long ) V_86 ) ||
( V_83 >= ( unsigned long ) V_87 ) )
return 0 ;
* V_114 = V_4 ;
return 1 ;
}
static int
F_79 ( struct V_72 * V_73 , T_3 V_27 , int V_4 )
{
int V_47 = V_73 -> V_47 ;
int * V_114 ;
struct V_68 * V_45 = V_73 -> V_75 ;
if ( ( V_27 & V_115 ) ||
( ! V_45 ) )
return 0 ;
V_114 = & ( F_30 ( V_45 -> V_71 , V_47 ) -> V_114 ) ;
if ( * V_114 == - 1 )
return 0 ;
if ( * V_114 >= V_4 ) {
* V_114 = - 1 ;
return 1 ;
}
return 1 ;
}
static enum V_106
F_80 ( struct V_37 * V_116 , struct V_56 * V_57 ,
struct V_72 * V_73 , T_3 V_27 )
{
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_26 * V_30 = & V_116 -> V_40 ;
struct V_54 * V_117 ;
static enum V_106 V_2 ;
int V_47 = V_73 -> V_47 ;
if ( F_78 ( V_73 , V_27 , V_30 -> V_3 , V_30 -> V_4 ) )
return V_118 ;
F_77 ( V_73 , V_57 , V_39 , V_30 -> V_3 , V_27 ) ;
V_117 = F_60 ( V_73 , V_116 ) ;
if ( V_117 )
V_2 = F_73 ( V_73 , V_116 , V_117 , V_57 , V_27 ) ;
else
V_2 = F_75 ( V_73 , V_116 , V_57 , V_47 , V_27 ) ;
if ( V_45 ) {
if ( V_57 -> V_119 ) {
V_45 -> V_79 = 1 ;
V_45 -> V_47 = V_47 ;
} else
V_45 -> V_79 = 0 ;
}
return V_2 ;
}
static enum V_106
F_81 ( struct V_17 * V_18 , struct V_56 * V_57 ,
struct V_67 * V_51 , struct V_72 * V_73 ,
T_3 V_27 )
{
unsigned long long V_97 = V_18 -> V_23 - V_18 -> V_6 ;
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_24 * V_25 = V_73 -> V_25 ;
T_2 V_59 = V_51 -> V_59 ;
int V_47 = V_73 -> V_47 ;
int V_120 = 1 ;
int V_65 ;
if ( F_79 ( V_73 , V_27 , V_18 -> V_4 ) )
return V_118 ;
if ( V_45 ) {
struct V_109 * V_71 ;
int V_47 = V_73 -> V_47 ;
V_71 = F_30 ( V_45 -> V_71 , V_47 ) ;
V_71 -> V_4 = V_18 -> V_4 - 1 ;
if ( V_18 -> V_4 < V_12 ) {
if ( V_71 -> V_110 [ V_18 -> V_4 ] != V_18 -> V_3 )
V_120 = 0 ;
V_71 -> V_110 [ V_18 -> V_4 ] = 0 ;
}
}
F_77 ( V_73 , V_57 , 0 , 0 , V_27 ) ;
F_69 ( V_25 , V_97 , V_57 , V_27 ) ;
for ( V_65 = 0 ; V_65 < V_18 -> V_4 * V_111 ; V_65 ++ )
F_55 ( V_57 , ' ' ) ;
if ( V_120 && ! ( V_27 & V_121 ) )
F_59 ( V_57 , L_25 ) ;
else
F_52 ( V_57 , L_26 , ( void * ) V_18 -> V_3 ) ;
if ( V_27 & V_122 )
F_52 ( V_57 , L_27 ,
V_18 -> V_22 ) ;
F_68 ( V_73 , V_18 -> V_3 , V_55 ,
V_47 , V_59 , V_27 ) ;
return F_74 ( V_57 ) ;
}
static enum V_106
F_82 ( struct V_56 * V_57 , struct V_67 * V_51 ,
struct V_72 * V_73 , T_3 V_27 )
{
struct V_24 * V_25 = V_73 -> V_25 ;
unsigned long V_123 = ( V_25 -> V_88 & V_124 ) ;
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_125 * V_33 ;
int V_4 = 0 ;
int V_2 ;
int V_65 ;
if ( V_45 )
V_4 = F_30 ( V_45 -> V_71 , V_73 -> V_47 ) -> V_4 ;
F_77 ( V_73 , V_57 , 0 , 0 , V_27 ) ;
F_69 ( V_25 , 0 , V_57 , V_27 | V_104 ) ;
if ( V_4 > 0 )
for ( V_65 = 0 ; V_65 < ( V_4 + 1 ) * V_111 ; V_65 ++ )
F_55 ( V_57 , ' ' ) ;
F_59 ( V_57 , L_28 ) ;
switch ( V_73 -> V_51 -> type ) {
case V_126 :
V_2 = F_83 ( V_73 ) ;
if ( V_2 != V_118 )
return V_2 ;
break;
case V_127 :
V_2 = F_84 ( V_73 ) ;
if ( V_2 != V_118 )
return V_2 ;
break;
default:
V_33 = F_85 ( V_51 -> type ) ;
if ( ! V_33 )
return V_128 ;
V_2 = V_33 -> V_129 -> V_18 ( V_73 , V_123 , V_33 ) ;
if ( V_2 != V_118 )
return V_2 ;
}
if ( F_76 ( V_57 ) )
goto V_130;
if ( V_57 -> V_35 [ V_57 -> V_85 . V_64 - 1 ] == '\n' ) {
V_57 -> V_35 [ V_57 -> V_85 . V_64 - 1 ] = '\0' ;
V_57 -> V_85 . V_64 -- ;
}
F_59 ( V_57 , L_29 ) ;
V_130:
return F_74 ( V_57 ) ;
}
enum V_106
F_86 ( struct V_72 * V_73 , T_3 V_27 )
{
struct V_37 * V_116 ;
struct V_68 * V_45 = V_73 -> V_75 ;
struct V_67 * V_38 = V_73 -> V_51 ;
struct V_56 * V_57 = & V_73 -> V_85 ;
int V_47 = V_73 -> V_47 ;
int V_2 ;
if ( V_45 && F_30 ( V_45 -> V_71 , V_47 ) -> V_131 ) {
F_30 ( V_45 -> V_71 , V_47 ) -> V_131 = 0 ;
return V_118 ;
}
if ( V_45 && V_45 -> V_79 ) {
V_116 = & V_45 -> V_51 ;
V_73 -> V_47 = V_45 -> V_47 ;
V_2 = F_80 ( V_116 , V_57 , V_73 , V_27 ) ;
if ( V_2 == V_118 && V_73 -> V_47 != V_47 ) {
F_30 ( V_45 -> V_71 , V_73 -> V_47 ) -> V_131 = 1 ;
V_2 = V_113 ;
}
V_73 -> V_47 = V_47 ;
return V_2 ;
}
switch ( V_38 -> type ) {
case V_39 : {
struct V_37 V_132 ;
F_87 ( V_116 , V_38 ) ;
V_132 = * V_116 ;
return F_80 ( & V_132 , V_57 , V_73 , V_27 ) ;
}
case V_55 : {
struct V_54 * V_116 ;
F_87 ( V_116 , V_38 ) ;
return F_81 ( & V_116 -> V_2 , V_57 , V_38 , V_73 , V_27 ) ;
}
case V_133 :
case V_134 :
return V_128 ;
default:
return F_82 ( V_57 , V_38 , V_73 , V_27 ) ;
}
return V_118 ;
}
static enum V_106
F_88 ( struct V_72 * V_73 )
{
return F_86 ( V_73 , V_135 . V_136 ) ;
}
static enum V_106
F_89 ( struct V_72 * V_73 , int V_27 ,
struct V_125 * V_33 )
{
return F_88 ( V_73 ) ;
}
static void F_90 ( struct V_137 * V_57 , T_3 V_27 )
{
static const char V_63 [] = L_30
L_31
L_32 ;
int V_138 = 0 ;
if ( V_27 & V_90 )
V_138 += 16 ;
if ( V_27 & V_92 )
V_138 += 4 ;
if ( V_27 & V_93 )
V_138 += 17 ;
F_91 ( V_57 , L_33 , V_138 , V_63 ) ;
F_91 ( V_57 , L_34 , V_138 , V_63 ) ;
F_91 ( V_57 , L_35 , V_138 , V_63 ) ;
F_91 ( V_57 , L_36 , V_138 , V_63 ) ;
F_91 ( V_57 , L_37 , V_138 , V_63 ) ;
}
static void F_92 ( struct V_24 * V_25 ,
struct V_137 * V_57 , T_3 V_27 )
{
int V_139 = V_25 -> V_88 & V_94 ;
if ( V_139 )
F_90 ( V_57 , V_27 ) ;
F_93 ( V_57 , '#' ) ;
if ( V_27 & V_90 )
F_94 ( V_57 , L_38 ) ;
if ( V_27 & V_92 )
F_94 ( V_57 , L_39 ) ;
if ( V_27 & V_93 )
F_94 ( V_57 , L_40 ) ;
if ( V_139 )
F_94 ( V_57 , L_41 ) ;
if ( V_27 & V_102 )
F_94 ( V_57 , L_42 ) ;
F_94 ( V_57 , L_43 ) ;
F_93 ( V_57 , '#' ) ;
if ( V_27 & V_90 )
F_94 ( V_57 , L_44 ) ;
if ( V_27 & V_92 )
F_94 ( V_57 , L_45 ) ;
if ( V_27 & V_93 )
F_94 ( V_57 , L_46 ) ;
if ( V_139 )
F_94 ( V_57 , L_41 ) ;
if ( V_27 & V_102 )
F_94 ( V_57 , L_47 ) ;
F_94 ( V_57 , L_48 ) ;
}
static void F_95 ( struct V_137 * V_57 )
{
F_96 ( V_57 , V_135 . V_136 ) ;
}
void F_96 ( struct V_137 * V_57 , T_3 V_27 )
{
struct V_72 * V_73 = V_57 -> V_75 ;
struct V_24 * V_25 = V_73 -> V_25 ;
if ( ! ( V_25 -> V_88 & V_89 ) )
return;
if ( V_25 -> V_88 & V_94 ) {
if ( F_97 ( V_73 ) )
return;
F_98 ( V_57 , V_73 ) ;
}
F_92 ( V_25 , V_57 , V_27 ) ;
}
void F_99 ( struct V_72 * V_73 )
{
struct V_68 * V_45 ;
T_5 V_140 ;
int V_47 ;
V_73 -> V_75 = NULL ;
V_140 = ( F_100 () || F_101 () ) ? V_141 : V_142 ;
V_45 = F_102 ( sizeof( * V_45 ) , V_140 ) ;
if ( ! V_45 )
goto V_143;
V_45 -> V_71 = F_103 ( struct V_109 , V_140 ) ;
if ( ! V_45 -> V_71 )
goto V_144;
F_104 (cpu) {
T_2 * V_59 = & ( F_30 ( V_45 -> V_71 , V_47 ) -> V_70 ) ;
int * V_4 = & ( F_30 ( V_45 -> V_71 , V_47 ) -> V_4 ) ;
int * V_131 = & ( F_30 ( V_45 -> V_71 , V_47 ) -> V_131 ) ;
int * V_114 = & ( F_30 ( V_45 -> V_71 , V_47 ) -> V_114 ) ;
* V_59 = - 1 ;
* V_4 = 0 ;
* V_131 = 0 ;
* V_114 = - 1 ;
}
V_73 -> V_75 = V_45 ;
return;
V_144:
F_105 ( V_45 ) ;
V_143:
F_106 ( L_49 ) ;
}
void F_107 ( struct V_72 * V_73 )
{
struct V_68 * V_45 = V_73 -> V_75 ;
if ( V_45 ) {
F_108 ( V_45 -> V_71 ) ;
F_105 ( V_45 ) ;
}
}
static int
F_109 ( struct V_24 * V_25 , T_3 V_145 , T_3 V_146 , int V_147 )
{
if ( V_146 == V_115 )
V_41 = ! V_147 ;
if ( V_146 == V_148 )
F_110 ( V_147 ) ;
if ( V_146 == V_149 )
F_111 ( V_147 ) ;
return 0 ;
}
static T_6
F_112 ( struct V_150 * V_151 , const char T_7 * V_152 , T_4 V_153 ,
T_8 * V_154 )
{
unsigned long V_136 ;
int V_2 ;
V_2 = F_113 ( V_152 , V_153 , 10 , & V_136 ) ;
if ( V_2 )
return V_2 ;
V_48 = V_136 ;
* V_154 += V_153 ;
return V_153 ;
}
static T_6
F_114 ( struct V_150 * V_151 , char T_7 * V_152 , T_4 V_153 ,
T_8 * V_154 )
{
char V_155 [ 15 ] ;
int V_156 ;
V_156 = sprintf ( V_155 , L_50 , V_48 ) ;
return F_115 ( V_152 , V_153 , V_154 , V_155 , V_156 ) ;
}
static T_9 int F_116 ( void )
{
struct V_157 * V_158 ;
V_158 = F_117 () ;
if ( F_118 ( V_158 ) )
return 0 ;
F_119 ( L_51 , 0644 , V_158 ,
NULL , & V_159 ) ;
return 0 ;
}
static T_9 int F_120 ( void )
{
V_58 = snprintf ( NULL , 0 , L_4 , V_160 - 1 ) ;
if ( ! F_121 ( & V_161 ) ) {
F_106 ( L_52 ) ;
return 1 ;
}
if ( ! F_121 ( & V_162 ) ) {
F_106 ( L_52 ) ;
return 1 ;
}
return F_122 ( & V_163 ) ;
}
