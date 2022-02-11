void F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
if ( V_2 < V_3 ) {
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_3 -> V_4 , 1 ) ;
} else {
F_2 ( & V_3 -> V_4 ) ;
F_3 ( & V_2 -> V_4 , 1 ) ;
}
}
static void F_4 ( void )
{
V_5 = F_5 ( L_1 , NULL ) ;
}
static int F_6 ( struct V_6 * V_7 , void * V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
struct V_1 * V_12 = & V_10 -> V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_15 ;
unsigned long V_16 , V_17 , V_18 ;
struct V_19 * V_19 ;
V_16 = V_17 = V_18 = 0 ;
F_2 ( & V_12 -> V_4 ) ;
F_7 (inode, &wb->b_dirty, i_wb_list)
V_16 ++ ;
F_7 (inode, &wb->b_io, i_wb_list)
V_17 ++ ;
F_7 (inode, &wb->b_more_io, i_wb_list)
V_18 ++ ;
F_8 ( & V_12 -> V_4 ) ;
F_9 ( & V_13 , & V_14 ) ;
V_15 = F_10 ( V_10 , V_14 ) ;
#define F_11 ( T_1 ) ((x) << (PAGE_SHIFT - 10))
F_12 ( V_7 ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11
L_12
L_13 ,
( unsigned long ) F_11 ( F_13 ( V_10 , V_20 ) ) ,
( unsigned long ) F_11 ( F_13 ( V_10 , V_21 ) ) ,
F_11 ( V_15 ) ,
F_11 ( V_14 ) ,
F_11 ( V_13 ) ,
( unsigned long ) F_11 ( F_13 ( V_10 , V_22 ) ) ,
( unsigned long ) F_11 ( V_10 -> V_23 ) ,
V_16 ,
V_17 ,
V_18 ,
! F_14 ( & V_10 -> V_24 ) , V_10 -> V_25 ) ;
#undef F_11
return 0 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_26 * V_26 )
{
return F_16 ( V_26 , F_6 , V_19 -> V_27 ) ;
}
static void F_17 ( struct V_9 * V_10 , const char * V_28 )
{
V_10 -> V_29 = F_5 ( V_28 , V_5 ) ;
V_10 -> V_30 = F_18 ( L_14 , 0444 , V_10 -> V_29 ,
V_10 , & V_31 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
F_20 ( V_10 -> V_30 ) ;
F_20 ( V_10 -> V_29 ) ;
}
static inline void F_4 ( void )
{
}
static inline void F_17 ( struct V_9 * V_10 ,
const char * V_28 )
{
}
static inline void F_19 ( struct V_9 * V_10 )
{
}
static T_2 F_21 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_3 V_37 )
{
struct V_9 * V_10 = F_22 ( V_33 ) ;
char * V_38 ;
unsigned long V_39 ;
T_2 V_40 = - V_41 ;
V_39 = F_23 ( V_36 , & V_38 , 10 ) ;
if ( * V_36 && ( V_38 [ 0 ] == '\0' || ( V_38 [ 0 ] == '\n' && V_38 [ 1 ] == '\0' ) ) ) {
V_10 -> V_42 = V_39 >> ( V_43 - 10 ) ;
V_40 = V_37 ;
}
return V_40 ;
}
static T_2 F_24 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_3 V_37 )
{
struct V_9 * V_10 = F_22 ( V_33 ) ;
char * V_38 ;
unsigned int V_44 ;
T_2 V_40 = - V_41 ;
V_44 = F_23 ( V_36 , & V_38 , 10 ) ;
if ( * V_36 && ( V_38 [ 0 ] == '\0' || ( V_38 [ 0 ] == '\n' && V_38 [ 1 ] == '\0' ) ) ) {
V_40 = F_25 ( V_10 , V_44 ) ;
if ( ! V_40 )
V_40 = V_37 ;
}
return V_40 ;
}
static T_2 F_26 ( struct V_32 * V_33 ,
struct V_34 * V_35 , const char * V_36 , T_3 V_37 )
{
struct V_9 * V_10 = F_22 ( V_33 ) ;
char * V_38 ;
unsigned int V_44 ;
T_2 V_40 = - V_41 ;
V_44 = F_23 ( V_36 , & V_38 , 10 ) ;
if ( * V_36 && ( V_38 [ 0 ] == '\0' || ( V_38 [ 0 ] == '\n' && V_38 [ 1 ] == '\0' ) ) ) {
V_40 = F_27 ( V_10 , V_44 ) ;
if ( ! V_40 )
V_40 = V_37 ;
}
return V_40 ;
}
static T_4 int F_28 ( void )
{
V_45 = F_29 ( V_46 , L_1 ) ;
if ( F_30 ( V_45 ) )
return F_31 ( V_45 ) ;
V_45 -> V_47 = V_48 ;
F_4 () ;
return 0 ;
}
static int T_4 F_32 ( void )
{
int V_49 ;
V_50 = F_33 ( V_51 , NULL , L_15 ) ;
F_34 ( F_30 ( V_50 ) ) ;
F_35 ( & V_52 , V_53 , 0 ) ;
F_36 () ;
V_49 = F_37 ( & V_54 ) ;
if ( ! V_49 )
F_38 ( & V_54 , NULL , L_16 ) ;
V_49 = F_37 ( & V_55 ) ;
return V_49 ;
}
int F_39 ( struct V_9 * V_10 )
{
return F_40 ( & V_10 -> V_12 ) ;
}
static int V_51 ( void * V_56 )
{
F_41 ( V_57 , 0 ) ;
while ( ! F_42 () ) {
F_43 ( V_58 ) ;
F_44 () ;
F_45 () ;
}
return 0 ;
}
void F_36 ( void )
{
unsigned long V_59 ;
if ( ! V_60 )
return;
V_59 = F_46 ( V_60 * 10 ) + V_61 ;
F_47 ( & V_52 , F_48 ( V_59 ) ) ;
}
static void V_53 ( unsigned long V_56 )
{
F_49 ( V_50 ) ;
F_36 () ;
}
static void F_50 ( unsigned long V_62 )
{
struct V_9 * V_10 = (struct V_9 * ) V_62 ;
F_51 ( & V_10 -> V_63 ) ;
if ( V_10 -> V_12 . V_64 ) {
F_52 ( V_10 ) ;
F_49 ( V_10 -> V_12 . V_64 ) ;
} else {
F_53 ( V_10 ) ;
F_49 ( V_54 . V_12 . V_64 ) ;
}
F_54 ( & V_10 -> V_63 ) ;
}
void F_55 ( struct V_9 * V_10 )
{
unsigned long V_65 ;
V_65 = F_46 ( V_60 * 10 ) ;
F_47 ( & V_10 -> V_12 . V_66 , V_61 + V_65 ) ;
}
static unsigned long F_56 ( void )
{
unsigned long V_67 ;
V_67 = F_46 ( V_60 * 10 ) ;
return F_57 ( 5UL * 60 * V_68 , V_67 ) ;
}
static void F_58 ( struct V_9 * V_10 )
{
F_59 ( V_69 , & V_10 -> V_25 ) ;
F_60 () ;
F_61 ( & V_10 -> V_25 , V_69 ) ;
}
static int F_62 ( void * V_70 )
{
struct V_1 * V_71 = V_70 ;
V_57 -> V_72 |= V_73 ;
F_63 () ;
F_41 ( V_57 , 0 ) ;
for (; ; ) {
struct V_74 * V_64 = NULL ;
struct V_9 * V_10 ;
enum {
V_75 ,
V_76 ,
V_77 ,
} V_78 = V_75 ;
if ( F_40 ( V_71 ) || ! F_14 ( & V_71 -> V_10 -> V_79 ) ) {
F_64 ( & V_71 -> V_66 ) ;
F_65 ( V_71 , 0 ) ;
}
F_51 ( & V_80 ) ;
F_43 ( V_58 ) ;
F_7 (bdi, &bdi_list, bdi_list) {
bool V_81 ;
if ( ! F_66 ( V_10 ) ||
F_67 ( V_10 ) )
continue;
F_68 ( ! F_69 ( V_82 , & V_10 -> V_25 ) ,
L_17 , V_10 , V_10 -> V_28 ) ;
V_81 = ! F_14 ( & V_10 -> V_79 ) ||
F_40 ( & V_10 -> V_12 ) ;
if ( ! V_10 -> V_12 . V_64 && V_81 ) {
F_70 ( V_69 , & V_10 -> V_25 ) ;
V_78 = V_76 ;
break;
}
F_2 ( & V_10 -> V_63 ) ;
if ( V_10 -> V_12 . V_64 && ! V_81 &&
F_71 ( V_61 , V_10 -> V_12 . V_83 +
F_56 () ) ) {
V_64 = V_10 -> V_12 . V_64 ;
V_10 -> V_12 . V_64 = NULL ;
F_8 ( & V_10 -> V_63 ) ;
F_70 ( V_69 , & V_10 -> V_25 ) ;
V_78 = V_77 ;
break;
}
F_8 ( & V_10 -> V_63 ) ;
}
F_54 ( & V_80 ) ;
if ( ! F_14 ( & V_71 -> V_10 -> V_79 ) )
F_72 ( V_84 ) ;
switch ( V_78 ) {
case V_76 :
F_72 ( V_84 ) ;
V_64 = F_73 ( V_85 , & V_10 -> V_12 ,
L_18 , F_74 ( V_10 -> V_33 ) ) ;
if ( F_30 ( V_64 ) ) {
F_75 ( & V_10 -> V_12 , 1024 ) ;
} else {
F_51 ( & V_10 -> V_63 ) ;
V_10 -> V_12 . V_64 = V_64 ;
F_54 ( & V_10 -> V_63 ) ;
F_49 ( V_64 ) ;
}
F_58 ( V_10 ) ;
break;
case V_77 :
F_72 ( V_84 ) ;
F_76 ( V_64 ) ;
F_58 ( V_10 ) ;
break;
case V_75 :
if ( ! F_40 ( V_71 ) || ! V_60 )
F_77 ( F_56 () ) ;
else
F_77 ( F_46 ( V_60 * 10 ) ) ;
F_78 () ;
break;
}
}
return 0 ;
}
static void F_79 ( struct V_9 * V_10 )
{
F_51 ( & V_80 ) ;
F_80 ( & V_10 -> V_24 ) ;
F_54 ( & V_80 ) ;
F_81 () ;
}
int F_38 ( struct V_9 * V_10 , struct V_32 * V_86 ,
const char * V_87 , ... )
{
T_5 args ;
struct V_32 * V_33 ;
if ( V_10 -> V_33 )
return 0 ;
va_start ( args , V_87 ) ;
V_33 = F_82 ( V_45 , V_86 , F_83 ( 0 , 0 ) , V_10 , V_87 , args ) ;
va_end ( args ) ;
if ( F_30 ( V_33 ) )
return F_31 ( V_33 ) ;
V_10 -> V_33 = V_33 ;
if ( F_67 ( V_10 ) ) {
struct V_1 * V_12 = & V_10 -> V_12 ;
V_12 -> V_64 = F_33 ( F_62 , V_12 , L_19 ,
F_74 ( V_33 ) ) ;
if ( F_30 ( V_12 -> V_64 ) )
return F_31 ( V_12 -> V_64 ) ;
}
F_17 ( V_10 , F_74 ( V_33 ) ) ;
F_70 ( V_82 , & V_10 -> V_25 ) ;
F_51 ( & V_80 ) ;
F_84 ( & V_10 -> V_24 , & V_24 ) ;
F_54 ( & V_80 ) ;
F_85 ( V_10 ) ;
return 0 ;
}
int F_86 ( struct V_9 * V_10 , T_6 V_33 )
{
return F_38 ( V_10 , NULL , L_20 , F_87 ( V_33 ) , F_88 ( V_33 ) ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
if ( ! F_66 ( V_10 ) )
return;
F_79 ( V_10 ) ;
F_90 ( & V_10 -> V_25 , V_69 , V_88 ,
V_89 ) ;
if ( V_10 -> V_12 . V_64 ) {
F_91 ( V_10 -> V_12 . V_64 ) ;
F_76 ( V_10 -> V_12 . V_64 ) ;
}
}
static void F_92 ( struct V_9 * V_10 )
{
struct V_90 * V_91 ;
F_2 ( & V_92 ) ;
F_7 (sb, &super_blocks, s_list) {
if ( V_91 -> V_93 == V_10 )
V_91 -> V_93 = & V_54 ;
}
F_8 ( & V_92 ) ;
}
void F_93 ( struct V_9 * V_10 )
{
if ( V_10 -> V_33 ) {
F_25 ( V_10 , 0 ) ;
F_94 ( V_10 ) ;
F_92 ( V_10 ) ;
F_95 ( & V_10 -> V_12 . V_66 ) ;
if ( ! F_67 ( V_10 ) )
F_89 ( V_10 ) ;
F_19 ( V_10 ) ;
F_96 ( V_10 -> V_33 ) ;
V_10 -> V_33 = NULL ;
}
}
static void F_97 ( struct V_1 * V_12 , struct V_9 * V_10 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_94 = V_61 ;
F_98 ( & V_12 -> V_95 ) ;
F_98 ( & V_12 -> V_96 ) ;
F_98 ( & V_12 -> V_97 ) ;
F_99 ( & V_12 -> V_4 ) ;
F_35 ( & V_12 -> V_66 , F_50 , ( unsigned long ) V_10 ) ;
}
int F_37 ( struct V_9 * V_10 )
{
int V_98 , V_49 ;
V_10 -> V_33 = NULL ;
V_10 -> V_99 = 0 ;
V_10 -> V_100 = 100 ;
V_10 -> V_101 = V_102 ;
F_99 ( & V_10 -> V_63 ) ;
F_98 ( & V_10 -> V_24 ) ;
F_98 ( & V_10 -> V_79 ) ;
F_97 ( & V_10 -> V_12 , V_10 ) ;
for ( V_98 = 0 ; V_98 < V_103 ; V_98 ++ ) {
V_49 = F_100 ( & V_10 -> F_13 [ V_98 ] , 0 ) ;
if ( V_49 )
goto V_49;
}
V_10 -> V_104 = 0 ;
V_10 -> V_105 = V_61 ;
V_10 -> V_106 = 0 ;
V_10 -> V_23 = V_107 ;
V_10 -> V_108 = V_107 ;
V_49 = F_101 ( & V_10 -> V_109 ) ;
if ( V_49 ) {
V_49:
while ( V_98 -- )
F_102 ( & V_10 -> F_13 [ V_98 ] ) ;
}
return V_49 ;
}
void F_103 ( struct V_9 * V_10 )
{
int V_98 ;
if ( F_39 ( V_10 ) ) {
struct V_1 * V_110 = & V_54 . V_12 ;
F_1 ( & V_10 -> V_12 , V_110 ) ;
F_104 ( & V_10 -> V_12 . V_95 , & V_110 -> V_95 ) ;
F_104 ( & V_10 -> V_12 . V_96 , & V_110 -> V_96 ) ;
F_104 ( & V_10 -> V_12 . V_97 , & V_110 -> V_97 ) ;
F_8 ( & V_10 -> V_12 . V_4 ) ;
F_8 ( & V_110 -> V_4 ) ;
}
F_93 ( V_10 ) ;
for ( V_98 = 0 ; V_98 < V_103 ; V_98 ++ )
F_102 ( & V_10 -> F_13 [ V_98 ] ) ;
F_105 ( & V_10 -> V_109 ) ;
}
int F_106 ( struct V_9 * V_10 , char * V_28 ,
unsigned int V_111 )
{
char V_112 [ 32 ] ;
int V_49 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_113 = V_111 ;
V_49 = F_37 ( V_10 ) ;
if ( V_49 )
return V_49 ;
sprintf ( V_112 , L_21 , V_28 , L_22 ) ;
V_49 = F_38 ( V_10 , NULL , V_112 , F_107 ( & V_114 ) ) ;
if ( V_49 ) {
F_103 ( V_10 ) ;
return V_49 ;
}
return 0 ;
}
void F_108 ( struct V_9 * V_10 , int V_115 )
{
enum V_116 V_117 ;
T_7 * V_118 = & V_119 [ V_115 ] ;
V_117 = V_115 ? V_120 : V_121 ;
if ( F_109 ( V_117 , & V_10 -> V_25 ) )
F_110 ( & V_122 [ V_115 ] ) ;
F_60 () ;
if ( F_111 ( V_118 ) )
F_112 ( V_118 ) ;
}
void F_113 ( struct V_9 * V_10 , int V_115 )
{
enum V_116 V_117 ;
V_117 = V_115 ? V_120 : V_121 ;
if ( ! F_114 ( V_117 , & V_10 -> V_25 ) )
F_115 ( & V_122 [ V_115 ] ) ;
}
long F_116 ( int V_115 , long V_65 )
{
long V_40 ;
unsigned long V_123 = V_61 ;
F_117 ( V_124 ) ;
T_7 * V_118 = & V_119 [ V_115 ] ;
F_118 ( V_118 , & V_124 , V_89 ) ;
V_40 = F_119 ( V_65 ) ;
F_120 ( V_118 , & V_124 ) ;
F_121 ( F_122 ( V_65 ) ,
F_122 ( V_61 - V_123 ) ) ;
return V_40 ;
}
long F_123 ( struct V_125 * V_125 , int V_115 , long V_65 )
{
long V_40 ;
unsigned long V_123 = V_61 ;
F_117 ( V_124 ) ;
T_7 * V_118 = & V_119 [ V_115 ] ;
if ( F_124 ( & V_122 [ V_115 ] ) == 0 ||
! F_125 ( V_125 ) ) {
F_126 () ;
V_40 = V_65 - ( V_61 - V_123 ) ;
if ( V_40 < 0 )
V_40 = 0 ;
goto V_126;
}
F_118 ( V_118 , & V_124 , V_89 ) ;
V_40 = F_119 ( V_65 ) ;
F_120 ( V_118 , & V_124 ) ;
V_126:
F_127 ( F_122 ( V_65 ) ,
F_122 ( V_61 - V_123 ) ) ;
return V_40 ;
}
