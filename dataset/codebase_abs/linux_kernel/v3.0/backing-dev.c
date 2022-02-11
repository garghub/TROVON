static void F_1 ( void )
{
V_1 = F_2 ( L_1 , NULL ) ;
}
static int F_3 ( struct V_2 * V_3 , void * V_4 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
struct V_8 * V_9 = & V_6 -> V_9 ;
unsigned long V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
unsigned long V_13 , V_14 , V_15 ;
struct V_16 * V_16 ;
V_13 = V_14 = V_15 = 0 ;
F_4 ( & V_17 ) ;
F_5 (inode, &wb->b_dirty, i_wb_list)
V_13 ++ ;
F_5 (inode, &wb->b_io, i_wb_list)
V_14 ++ ;
F_5 (inode, &wb->b_more_io, i_wb_list)
V_15 ++ ;
F_6 ( & V_17 ) ;
F_7 ( & V_10 , & V_11 ) ;
V_12 = F_8 ( V_6 , V_11 ) ;
#define F_9 ( T_1 ) ((x) << (PAGE_SHIFT - 10))
F_10 ( V_3 ,
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11 ,
( unsigned long ) F_9 ( F_11 ( V_6 , V_18 ) ) ,
( unsigned long ) F_9 ( F_11 ( V_6 , V_19 ) ) ,
F_9 ( V_12 ) , F_9 ( V_11 ) ,
F_9 ( V_10 ) , V_13 , V_14 , V_15 ,
! F_12 ( & V_6 -> V_20 ) , V_6 -> V_21 ) ;
#undef F_9
return 0 ;
}
static int F_13 ( struct V_16 * V_16 , struct V_22 * V_22 )
{
return F_14 ( V_22 , F_3 , V_16 -> V_23 ) ;
}
static void F_15 ( struct V_5 * V_6 , const char * V_24 )
{
V_6 -> V_25 = F_2 ( V_24 , V_1 ) ;
V_6 -> V_26 = F_16 ( L_12 , 0444 , V_6 -> V_25 ,
V_6 , & V_27 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 -> V_26 ) ;
F_18 ( V_6 -> V_25 ) ;
}
static inline void F_1 ( void )
{
}
static inline void F_15 ( struct V_5 * V_6 ,
const char * V_24 )
{
}
static inline void F_17 ( struct V_5 * V_6 )
{
}
static T_2 F_19 ( struct V_28 * V_29 ,
struct V_30 * V_31 ,
const char * V_32 , T_3 V_33 )
{
struct V_5 * V_6 = F_20 ( V_29 ) ;
char * V_34 ;
unsigned long V_35 ;
T_2 V_36 = - V_37 ;
V_35 = F_21 ( V_32 , & V_34 , 10 ) ;
if ( * V_32 && ( V_34 [ 0 ] == '\0' || ( V_34 [ 0 ] == '\n' && V_34 [ 1 ] == '\0' ) ) ) {
V_6 -> V_38 = V_35 >> ( V_39 - 10 ) ;
V_36 = V_33 ;
}
return V_36 ;
}
static T_2 F_22 ( struct V_28 * V_29 ,
struct V_30 * V_31 , const char * V_32 , T_3 V_33 )
{
struct V_5 * V_6 = F_20 ( V_29 ) ;
char * V_34 ;
unsigned int V_40 ;
T_2 V_36 = - V_37 ;
V_40 = F_21 ( V_32 , & V_34 , 10 ) ;
if ( * V_32 && ( V_34 [ 0 ] == '\0' || ( V_34 [ 0 ] == '\n' && V_34 [ 1 ] == '\0' ) ) ) {
V_36 = F_23 ( V_6 , V_40 ) ;
if ( ! V_36 )
V_36 = V_33 ;
}
return V_36 ;
}
static T_2 F_24 ( struct V_28 * V_29 ,
struct V_30 * V_31 , const char * V_32 , T_3 V_33 )
{
struct V_5 * V_6 = F_20 ( V_29 ) ;
char * V_34 ;
unsigned int V_40 ;
T_2 V_36 = - V_37 ;
V_40 = F_21 ( V_32 , & V_34 , 10 ) ;
if ( * V_32 && ( V_34 [ 0 ] == '\0' || ( V_34 [ 0 ] == '\n' && V_34 [ 1 ] == '\0' ) ) ) {
V_36 = F_25 ( V_6 , V_40 ) ;
if ( ! V_36 )
V_36 = V_33 ;
}
return V_36 ;
}
static T_4 int F_26 ( void )
{
V_41 = F_27 ( V_42 , L_1 ) ;
if ( F_28 ( V_41 ) )
return F_29 ( V_41 ) ;
V_41 -> V_43 = V_44 ;
F_1 () ;
return 0 ;
}
static int T_4 F_30 ( void )
{
int V_45 ;
V_46 = F_31 ( V_47 , NULL , L_13 ) ;
F_32 ( F_28 ( V_46 ) ) ;
F_33 ( & V_48 , V_49 , 0 ) ;
F_34 () ;
V_45 = F_35 ( & V_50 ) ;
if ( ! V_45 )
F_36 ( & V_50 , NULL , L_14 ) ;
V_45 = F_35 ( & V_51 ) ;
return V_45 ;
}
int F_37 ( struct V_5 * V_6 )
{
return F_38 ( & V_6 -> V_9 ) ;
}
static void F_39 ( struct V_5 * V_6 )
{
struct V_52 V_53 = {
. V_54 = V_55 ,
. V_56 = NULL ,
. V_57 = 1 ,
. V_58 = 1024 ,
} ;
F_40 ( & V_6 -> V_9 , & V_53 ) ;
}
static int V_47 ( void * V_59 )
{
F_41 ( V_60 , 0 ) ;
while ( ! F_42 () ) {
F_43 ( V_61 ) ;
F_44 () ;
F_45 () ;
}
return 0 ;
}
void F_34 ( void )
{
unsigned long V_62 ;
if ( ! V_63 )
return;
V_62 = F_46 ( V_63 * 10 ) + V_64 ;
F_47 ( & V_48 , F_48 ( V_62 ) ) ;
}
static void V_49 ( unsigned long V_59 )
{
F_49 ( V_46 ) ;
F_34 () ;
}
static void F_50 ( unsigned long V_65 )
{
struct V_5 * V_6 = (struct V_5 * ) V_65 ;
F_51 ( & V_6 -> V_66 ) ;
if ( V_6 -> V_9 . V_67 ) {
F_52 ( V_6 ) ;
F_49 ( V_6 -> V_9 . V_67 ) ;
} else {
F_53 ( V_6 ) ;
F_49 ( V_50 . V_9 . V_67 ) ;
}
F_54 ( & V_6 -> V_66 ) ;
}
void F_55 ( struct V_5 * V_6 )
{
unsigned long V_68 ;
V_68 = F_46 ( V_63 * 10 ) ;
F_47 ( & V_6 -> V_9 . V_69 , V_64 + V_68 ) ;
}
static unsigned long F_56 ( void )
{
unsigned long V_70 ;
V_70 = F_46 ( V_63 * 10 ) ;
return F_57 ( 5UL * 60 * V_71 , V_70 ) ;
}
static int F_58 ( void * V_72 )
{
struct V_8 * V_73 = V_72 ;
V_60 -> V_74 |= V_75 ;
F_59 () ;
F_41 ( V_60 , 0 ) ;
for (; ; ) {
struct V_76 * V_67 = NULL ;
struct V_5 * V_6 ;
enum {
V_77 ,
V_78 ,
V_79 ,
} V_80 = V_77 ;
if ( F_38 ( V_73 ) || ! F_12 ( & V_73 -> V_6 -> V_81 ) ) {
F_60 ( & V_73 -> V_69 ) ;
F_61 ( V_73 , 0 ) ;
}
F_51 ( & V_82 ) ;
F_43 ( V_61 ) ;
F_5 (bdi, &bdi_list, bdi_list) {
bool V_83 ;
if ( ! F_62 ( V_6 ) ||
F_63 ( V_6 ) )
continue;
F_64 ( ! F_65 ( V_84 , & V_6 -> V_21 ) ,
L_15 , V_6 , V_6 -> V_24 ) ;
V_83 = ! F_12 ( & V_6 -> V_81 ) ||
F_38 ( & V_6 -> V_9 ) ;
if ( ! V_6 -> V_9 . V_67 && V_83 ) {
F_66 ( V_85 , & V_6 -> V_21 ) ;
V_80 = V_78 ;
break;
}
F_4 ( & V_6 -> V_66 ) ;
if ( V_6 -> V_9 . V_67 && ! V_83 &&
F_67 ( V_64 , V_6 -> V_9 . V_86 +
F_56 () ) ) {
V_67 = V_6 -> V_9 . V_67 ;
V_6 -> V_9 . V_67 = NULL ;
F_6 ( & V_6 -> V_66 ) ;
F_66 ( V_85 , & V_6 -> V_21 ) ;
V_80 = V_79 ;
break;
}
F_6 ( & V_6 -> V_66 ) ;
}
F_54 ( & V_82 ) ;
if ( ! F_12 ( & V_73 -> V_6 -> V_81 ) )
F_68 ( V_87 ) ;
switch ( V_80 ) {
case V_78 :
F_68 ( V_87 ) ;
V_67 = F_69 ( V_88 , & V_6 -> V_9 ,
L_16 , F_70 ( V_6 -> V_29 ) ) ;
if ( F_28 ( V_67 ) ) {
F_39 ( V_6 ) ;
} else {
F_51 ( & V_6 -> V_66 ) ;
V_6 -> V_9 . V_67 = V_67 ;
F_54 ( & V_6 -> V_66 ) ;
F_49 ( V_67 ) ;
}
break;
case V_79 :
F_68 ( V_87 ) ;
F_71 ( V_67 ) ;
break;
case V_77 :
if ( ! F_38 ( V_73 ) || ! V_63 )
F_72 ( F_56 () ) ;
else
F_72 ( F_46 ( V_63 * 10 ) ) ;
F_73 () ;
continue;
}
F_74 ( V_85 , & V_6 -> V_21 ) ;
F_75 () ;
F_76 ( & V_6 -> V_21 , V_85 ) ;
}
return 0 ;
}
static void F_77 ( struct V_5 * V_6 )
{
F_51 ( & V_82 ) ;
F_78 ( & V_6 -> V_20 ) ;
F_54 ( & V_82 ) ;
F_79 () ;
}
int F_36 ( struct V_5 * V_6 , struct V_28 * V_89 ,
const char * V_90 , ... )
{
T_5 args ;
struct V_28 * V_29 ;
if ( V_6 -> V_29 )
return 0 ;
va_start ( args , V_90 ) ;
V_29 = F_80 ( V_41 , V_89 , F_81 ( 0 , 0 ) , V_6 , V_90 , args ) ;
va_end ( args ) ;
if ( F_28 ( V_29 ) )
return F_29 ( V_29 ) ;
V_6 -> V_29 = V_29 ;
if ( F_63 ( V_6 ) ) {
struct V_8 * V_9 = & V_6 -> V_9 ;
V_9 -> V_67 = F_31 ( F_58 , V_9 , L_17 ,
F_70 ( V_29 ) ) ;
if ( F_28 ( V_9 -> V_67 ) )
return F_29 ( V_9 -> V_67 ) ;
}
F_15 ( V_6 , F_70 ( V_29 ) ) ;
F_66 ( V_84 , & V_6 -> V_21 ) ;
F_51 ( & V_82 ) ;
F_82 ( & V_6 -> V_20 , & V_20 ) ;
F_54 ( & V_82 ) ;
F_83 ( V_6 ) ;
return 0 ;
}
int F_84 ( struct V_5 * V_6 , T_6 V_29 )
{
return F_36 ( V_6 , NULL , L_18 , F_85 ( V_29 ) , F_86 ( V_29 ) ) ;
}
static void F_87 ( struct V_5 * V_6 )
{
if ( ! F_62 ( V_6 ) )
return;
F_77 ( V_6 ) ;
F_88 ( & V_6 -> V_21 , V_85 , V_91 ,
V_92 ) ;
if ( V_6 -> V_9 . V_67 ) {
F_89 ( V_6 -> V_9 . V_67 ) ;
F_71 ( V_6 -> V_9 . V_67 ) ;
}
}
static void F_90 ( struct V_5 * V_6 )
{
struct V_93 * V_94 ;
F_4 ( & V_95 ) ;
F_5 (sb, &super_blocks, s_list) {
if ( V_94 -> V_96 == V_6 )
V_94 -> V_96 = & V_50 ;
}
F_6 ( & V_95 ) ;
}
void F_91 ( struct V_5 * V_6 )
{
if ( V_6 -> V_29 ) {
F_92 ( V_6 ) ;
F_90 ( V_6 ) ;
F_93 ( & V_6 -> V_9 . V_69 ) ;
if ( ! F_63 ( V_6 ) )
F_87 ( V_6 ) ;
F_17 ( V_6 ) ;
F_94 ( V_6 -> V_29 ) ;
V_6 -> V_29 = NULL ;
}
}
static void F_95 ( struct V_8 * V_9 , struct V_5 * V_6 )
{
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_97 = V_64 ;
F_96 ( & V_9 -> V_98 ) ;
F_96 ( & V_9 -> V_99 ) ;
F_96 ( & V_9 -> V_100 ) ;
F_33 ( & V_9 -> V_69 , F_50 , ( unsigned long ) V_6 ) ;
}
int F_35 ( struct V_5 * V_6 )
{
int V_101 , V_45 ;
V_6 -> V_29 = NULL ;
V_6 -> V_102 = 0 ;
V_6 -> V_103 = 100 ;
V_6 -> V_104 = V_105 ;
F_97 ( & V_6 -> V_66 ) ;
F_96 ( & V_6 -> V_20 ) ;
F_96 ( & V_6 -> V_81 ) ;
F_95 ( & V_6 -> V_9 , V_6 ) ;
for ( V_101 = 0 ; V_101 < V_106 ; V_101 ++ ) {
V_45 = F_98 ( & V_6 -> F_11 [ V_101 ] , 0 ) ;
if ( V_45 )
goto V_45;
}
V_6 -> V_107 = 0 ;
V_45 = F_99 ( & V_6 -> V_108 ) ;
if ( V_45 ) {
V_45:
while ( V_101 -- )
F_100 ( & V_6 -> F_11 [ V_101 ] ) ;
}
return V_45 ;
}
void F_101 ( struct V_5 * V_6 )
{
int V_101 ;
if ( F_37 ( V_6 ) ) {
struct V_8 * V_109 = & V_50 . V_9 ;
F_4 ( & V_17 ) ;
F_102 ( & V_6 -> V_9 . V_98 , & V_109 -> V_98 ) ;
F_102 ( & V_6 -> V_9 . V_99 , & V_109 -> V_99 ) ;
F_102 ( & V_6 -> V_9 . V_100 , & V_109 -> V_100 ) ;
F_6 ( & V_17 ) ;
}
F_91 ( V_6 ) ;
for ( V_101 = 0 ; V_101 < V_106 ; V_101 ++ )
F_100 ( & V_6 -> F_11 [ V_101 ] ) ;
F_103 ( & V_6 -> V_108 ) ;
}
int F_104 ( struct V_5 * V_6 , char * V_24 ,
unsigned int V_110 )
{
char V_111 [ 32 ] ;
int V_45 ;
V_6 -> V_24 = V_24 ;
V_6 -> V_112 = V_110 ;
V_45 = F_35 ( V_6 ) ;
if ( V_45 )
return V_45 ;
sprintf ( V_111 , L_19 , V_24 , L_20 ) ;
V_45 = F_36 ( V_6 , NULL , V_111 , F_105 ( & V_113 ) ) ;
if ( V_45 ) {
F_101 ( V_6 ) ;
return V_45 ;
}
return 0 ;
}
void F_106 ( struct V_5 * V_6 , int V_114 )
{
enum V_115 V_116 ;
T_7 * V_117 = & V_118 [ V_114 ] ;
V_116 = V_114 ? V_119 : V_120 ;
if ( F_107 ( V_116 , & V_6 -> V_21 ) )
F_108 ( & V_121 [ V_114 ] ) ;
F_75 () ;
if ( F_109 ( V_117 ) )
F_110 ( V_117 ) ;
}
void F_111 ( struct V_5 * V_6 , int V_114 )
{
enum V_115 V_116 ;
V_116 = V_114 ? V_119 : V_120 ;
if ( ! F_112 ( V_116 , & V_6 -> V_21 ) )
F_113 ( & V_121 [ V_114 ] ) ;
}
long F_114 ( int V_114 , long V_68 )
{
long V_36 ;
unsigned long V_122 = V_64 ;
F_115 ( V_123 ) ;
T_7 * V_117 = & V_118 [ V_114 ] ;
F_116 ( V_117 , & V_123 , V_92 ) ;
V_36 = F_117 ( V_68 ) ;
F_118 ( V_117 , & V_123 ) ;
F_119 ( F_120 ( V_68 ) ,
F_120 ( V_64 - V_122 ) ) ;
return V_36 ;
}
long F_121 ( struct V_124 * V_124 , int V_114 , long V_68 )
{
long V_36 ;
unsigned long V_122 = V_64 ;
F_115 ( V_123 ) ;
T_7 * V_117 = & V_118 [ V_114 ] ;
if ( F_122 ( & V_121 [ V_114 ] ) == 0 ||
! F_123 ( V_124 ) ) {
F_124 () ;
V_36 = V_68 - ( V_64 - V_122 ) ;
if ( V_36 < 0 )
V_36 = 0 ;
goto V_125;
}
F_116 ( V_117 , & V_123 , V_92 ) ;
V_36 = F_117 ( V_68 ) ;
F_118 ( V_117 , & V_123 ) ;
V_125:
F_125 ( F_120 ( V_68 ) ,
F_120 ( V_64 - V_122 ) ) ;
return V_36 ;
}
