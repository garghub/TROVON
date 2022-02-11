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
L_13
L_14 ,
( unsigned long ) F_11 ( F_13 ( V_10 , V_20 ) ) ,
( unsigned long ) F_11 ( F_13 ( V_10 , V_21 ) ) ,
F_11 ( V_15 ) ,
F_11 ( V_14 ) ,
F_11 ( V_13 ) ,
( unsigned long ) F_11 ( F_13 ( V_10 , V_22 ) ) ,
( unsigned long ) F_11 ( F_13 ( V_10 , V_23 ) ) ,
( unsigned long ) F_11 ( V_10 -> V_24 ) ,
V_16 ,
V_17 ,
V_18 ,
! F_14 ( & V_10 -> V_25 ) , V_10 -> V_26 ) ;
#undef F_11
return 0 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_27 * V_27 )
{
return F_16 ( V_27 , F_6 , V_19 -> V_28 ) ;
}
static void F_17 ( struct V_9 * V_10 , const char * V_29 )
{
V_10 -> V_30 = F_5 ( V_29 , V_5 ) ;
V_10 -> V_31 = F_18 ( L_15 , 0444 , V_10 -> V_30 ,
V_10 , & V_32 ) ;
}
static void F_19 ( struct V_9 * V_10 )
{
F_20 ( V_10 -> V_31 ) ;
F_20 ( V_10 -> V_30 ) ;
}
static inline void F_4 ( void )
{
}
static inline void F_17 ( struct V_9 * V_10 ,
const char * V_29 )
{
}
static inline void F_19 ( struct V_9 * V_10 )
{
}
static T_2 F_21 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
const char * V_37 , T_3 V_38 )
{
struct V_9 * V_10 = F_22 ( V_34 ) ;
char * V_39 ;
unsigned long V_40 ;
T_2 V_41 = - V_42 ;
V_40 = F_23 ( V_37 , & V_39 , 10 ) ;
if ( * V_37 && ( V_39 [ 0 ] == '\0' || ( V_39 [ 0 ] == '\n' && V_39 [ 1 ] == '\0' ) ) ) {
V_10 -> V_43 = V_40 >> ( V_44 - 10 ) ;
V_41 = V_38 ;
}
return V_41 ;
}
static T_2 F_24 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_3 V_38 )
{
struct V_9 * V_10 = F_22 ( V_34 ) ;
char * V_39 ;
unsigned int V_45 ;
T_2 V_41 = - V_42 ;
V_45 = F_23 ( V_37 , & V_39 , 10 ) ;
if ( * V_37 && ( V_39 [ 0 ] == '\0' || ( V_39 [ 0 ] == '\n' && V_39 [ 1 ] == '\0' ) ) ) {
V_41 = F_25 ( V_10 , V_45 ) ;
if ( ! V_41 )
V_41 = V_38 ;
}
return V_41 ;
}
static T_2 F_26 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_3 V_38 )
{
struct V_9 * V_10 = F_22 ( V_34 ) ;
char * V_39 ;
unsigned int V_45 ;
T_2 V_41 = - V_42 ;
V_45 = F_23 ( V_37 , & V_39 , 10 ) ;
if ( * V_37 && ( V_39 [ 0 ] == '\0' || ( V_39 [ 0 ] == '\n' && V_39 [ 1 ] == '\0' ) ) ) {
V_41 = F_27 ( V_10 , V_45 ) ;
if ( ! V_41 )
V_41 = V_38 ;
}
return V_41 ;
}
static T_4 int F_28 ( void )
{
V_46 = F_29 ( V_47 , L_1 ) ;
if ( F_30 ( V_46 ) )
return F_31 ( V_46 ) ;
V_46 -> V_48 = V_49 ;
F_4 () ;
return 0 ;
}
static int T_4 F_32 ( void )
{
int V_50 ;
V_51 = F_33 ( V_52 , NULL , L_16 ) ;
F_34 ( F_30 ( V_51 ) ) ;
F_35 ( & V_53 , V_54 , 0 ) ;
F_36 () ;
V_50 = F_37 ( & V_55 ) ;
if ( ! V_50 )
F_38 ( & V_55 , NULL , L_17 ) ;
V_50 = F_37 ( & V_56 ) ;
return V_50 ;
}
int F_39 ( struct V_9 * V_10 )
{
return F_40 ( & V_10 -> V_12 ) ;
}
static int V_52 ( void * V_57 )
{
F_41 ( V_58 , 0 ) ;
while ( ! F_42 () ) {
F_43 ( V_59 ) ;
F_44 () ;
F_45 () ;
}
return 0 ;
}
void F_36 ( void )
{
unsigned long V_60 ;
if ( ! V_61 )
return;
V_60 = F_46 ( V_61 * 10 ) + V_62 ;
F_47 ( & V_53 , F_48 ( V_60 ) ) ;
}
static void V_54 ( unsigned long V_57 )
{
F_49 ( V_51 ) ;
F_36 () ;
}
static void F_50 ( unsigned long V_63 )
{
struct V_9 * V_10 = (struct V_9 * ) V_63 ;
F_51 ( & V_10 -> V_64 ) ;
if ( V_10 -> V_12 . V_65 ) {
F_52 ( V_10 ) ;
F_49 ( V_10 -> V_12 . V_65 ) ;
} else {
F_53 ( V_10 ) ;
F_49 ( V_55 . V_12 . V_65 ) ;
}
F_54 ( & V_10 -> V_64 ) ;
}
void F_55 ( struct V_9 * V_10 )
{
unsigned long V_66 ;
V_66 = F_46 ( V_61 * 10 ) ;
F_47 ( & V_10 -> V_12 . V_67 , V_62 + V_66 ) ;
}
static unsigned long F_56 ( void )
{
unsigned long V_68 ;
V_68 = F_46 ( V_61 * 10 ) ;
return F_57 ( 5UL * 60 * V_69 , V_68 ) ;
}
static void F_58 ( struct V_9 * V_10 )
{
F_59 ( V_70 , & V_10 -> V_26 ) ;
F_60 () ;
F_61 ( & V_10 -> V_26 , V_70 ) ;
}
static int F_62 ( void * V_71 )
{
struct V_1 * V_72 = V_71 ;
V_58 -> V_73 |= V_74 ;
F_63 () ;
F_41 ( V_58 , 0 ) ;
for (; ; ) {
struct V_75 * V_65 = NULL ;
struct V_9 * V_10 ;
enum {
V_76 ,
V_77 ,
V_78 ,
} V_79 = V_76 ;
if ( F_40 ( V_72 ) || ! F_14 ( & V_72 -> V_10 -> V_80 ) ) {
F_64 ( & V_72 -> V_67 ) ;
F_65 ( V_72 , 0 ) ;
}
F_51 ( & V_81 ) ;
F_43 ( V_59 ) ;
F_7 (bdi, &bdi_list, bdi_list) {
bool V_82 ;
if ( ! F_66 ( V_10 ) ||
F_67 ( V_10 ) )
continue;
F_68 ( ! F_69 ( V_83 , & V_10 -> V_26 ) ,
L_18 , V_10 , V_10 -> V_29 ) ;
V_82 = ! F_14 ( & V_10 -> V_80 ) ||
F_40 ( & V_10 -> V_12 ) ;
if ( ! V_10 -> V_12 . V_65 && V_82 ) {
F_70 ( V_70 , & V_10 -> V_26 ) ;
V_79 = V_77 ;
break;
}
F_2 ( & V_10 -> V_64 ) ;
if ( V_10 -> V_12 . V_65 && ! V_82 &&
F_71 ( V_62 , V_10 -> V_12 . V_84 +
F_56 () ) ) {
V_65 = V_10 -> V_12 . V_65 ;
V_10 -> V_12 . V_65 = NULL ;
F_8 ( & V_10 -> V_64 ) ;
F_70 ( V_70 , & V_10 -> V_26 ) ;
V_79 = V_78 ;
break;
}
F_8 ( & V_10 -> V_64 ) ;
}
F_54 ( & V_81 ) ;
if ( ! F_14 ( & V_72 -> V_10 -> V_80 ) )
F_72 ( V_85 ) ;
switch ( V_79 ) {
case V_77 :
F_72 ( V_85 ) ;
V_65 = F_73 ( V_86 , & V_10 -> V_12 ,
L_19 , F_74 ( V_10 -> V_34 ) ) ;
if ( F_30 ( V_65 ) ) {
F_75 ( & V_10 -> V_12 , 1024 ,
V_87 ) ;
} else {
F_51 ( & V_10 -> V_64 ) ;
V_10 -> V_12 . V_65 = V_65 ;
F_54 ( & V_10 -> V_64 ) ;
F_49 ( V_65 ) ;
}
F_58 ( V_10 ) ;
break;
case V_78 :
F_72 ( V_85 ) ;
F_76 ( V_65 ) ;
F_58 ( V_10 ) ;
break;
case V_76 :
if ( ! F_40 ( V_72 ) || ! V_61 )
F_77 ( F_56 () ) ;
else
F_77 ( F_46 ( V_61 * 10 ) ) ;
F_78 () ;
break;
}
}
return 0 ;
}
static void F_79 ( struct V_9 * V_10 )
{
F_51 ( & V_81 ) ;
F_80 ( & V_10 -> V_25 ) ;
F_54 ( & V_81 ) ;
F_81 () ;
}
int F_38 ( struct V_9 * V_10 , struct V_33 * V_88 ,
const char * V_89 , ... )
{
T_5 args ;
struct V_33 * V_34 ;
if ( V_10 -> V_34 )
return 0 ;
va_start ( args , V_89 ) ;
V_34 = F_82 ( V_46 , V_88 , F_83 ( 0 , 0 ) , V_10 , V_89 , args ) ;
va_end ( args ) ;
if ( F_30 ( V_34 ) )
return F_31 ( V_34 ) ;
V_10 -> V_34 = V_34 ;
if ( F_67 ( V_10 ) ) {
struct V_1 * V_12 = & V_10 -> V_12 ;
V_12 -> V_65 = F_33 ( F_62 , V_12 , L_20 ,
F_74 ( V_34 ) ) ;
if ( F_30 ( V_12 -> V_65 ) )
return F_31 ( V_12 -> V_65 ) ;
}
F_17 ( V_10 , F_74 ( V_34 ) ) ;
F_70 ( V_83 , & V_10 -> V_26 ) ;
F_51 ( & V_81 ) ;
F_84 ( & V_10 -> V_25 , & V_25 ) ;
F_54 ( & V_81 ) ;
F_85 ( V_10 ) ;
return 0 ;
}
int F_86 ( struct V_9 * V_10 , T_6 V_34 )
{
return F_38 ( V_10 , NULL , L_21 , F_87 ( V_34 ) , F_88 ( V_34 ) ) ;
}
static void F_89 ( struct V_9 * V_10 )
{
if ( ! F_66 ( V_10 ) )
return;
F_79 ( V_10 ) ;
F_90 ( & V_10 -> V_26 , V_70 , V_90 ,
V_91 ) ;
if ( V_10 -> V_12 . V_65 ) {
F_91 ( V_10 -> V_12 . V_65 ) ;
F_76 ( V_10 -> V_12 . V_65 ) ;
}
}
static void F_92 ( struct V_9 * V_10 )
{
struct V_92 * V_93 ;
F_2 ( & V_94 ) ;
F_7 (sb, &super_blocks, s_list) {
if ( V_93 -> V_95 == V_10 )
V_93 -> V_95 = & V_55 ;
}
F_8 ( & V_94 ) ;
}
void F_93 ( struct V_9 * V_10 )
{
if ( V_10 -> V_34 ) {
F_25 ( V_10 , 0 ) ;
F_94 ( V_10 ) ;
F_92 ( V_10 ) ;
F_95 ( & V_10 -> V_12 . V_67 ) ;
if ( ! F_67 ( V_10 ) )
F_89 ( V_10 ) ;
F_19 ( V_10 ) ;
F_96 ( V_10 -> V_34 ) ;
V_10 -> V_34 = NULL ;
}
}
static void F_97 ( struct V_1 * V_12 , struct V_9 * V_10 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_96 = V_62 ;
F_98 ( & V_12 -> V_97 ) ;
F_98 ( & V_12 -> V_98 ) ;
F_98 ( & V_12 -> V_99 ) ;
F_99 ( & V_12 -> V_4 ) ;
F_35 ( & V_12 -> V_67 , F_50 , ( unsigned long ) V_10 ) ;
}
int F_37 ( struct V_9 * V_10 )
{
int V_100 , V_50 ;
V_10 -> V_34 = NULL ;
V_10 -> V_101 = 0 ;
V_10 -> V_102 = 100 ;
V_10 -> V_103 = V_104 ;
F_99 ( & V_10 -> V_64 ) ;
F_98 ( & V_10 -> V_25 ) ;
F_98 ( & V_10 -> V_80 ) ;
F_97 ( & V_10 -> V_12 , V_10 ) ;
for ( V_100 = 0 ; V_100 < V_105 ; V_100 ++ ) {
V_50 = F_100 ( & V_10 -> F_13 [ V_100 ] , 0 ) ;
if ( V_50 )
goto V_50;
}
V_10 -> V_106 = 0 ;
V_10 -> V_107 = V_62 ;
V_10 -> V_108 = 0 ;
V_10 -> V_109 = V_110 ;
V_10 -> V_111 = V_110 ;
V_10 -> V_24 = V_110 ;
V_10 -> V_112 = V_110 ;
V_50 = F_101 ( & V_10 -> V_113 ) ;
if ( V_50 ) {
V_50:
while ( V_100 -- )
F_102 ( & V_10 -> F_13 [ V_100 ] ) ;
}
return V_50 ;
}
void F_103 ( struct V_9 * V_10 )
{
int V_100 ;
if ( F_39 ( V_10 ) ) {
struct V_1 * V_114 = & V_55 . V_12 ;
F_1 ( & V_10 -> V_12 , V_114 ) ;
F_104 ( & V_10 -> V_12 . V_97 , & V_114 -> V_97 ) ;
F_104 ( & V_10 -> V_12 . V_98 , & V_114 -> V_98 ) ;
F_104 ( & V_10 -> V_12 . V_99 , & V_114 -> V_99 ) ;
F_8 ( & V_10 -> V_12 . V_4 ) ;
F_8 ( & V_114 -> V_4 ) ;
}
F_93 ( V_10 ) ;
F_95 ( & V_10 -> V_12 . V_67 ) ;
for ( V_100 = 0 ; V_100 < V_105 ; V_100 ++ )
F_102 ( & V_10 -> F_13 [ V_100 ] ) ;
F_105 ( & V_10 -> V_113 ) ;
}
int F_106 ( struct V_9 * V_10 , char * V_29 ,
unsigned int V_115 )
{
char V_116 [ 32 ] ;
int V_50 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_117 = V_115 ;
V_50 = F_37 ( V_10 ) ;
if ( V_50 )
return V_50 ;
sprintf ( V_116 , L_22 , V_29 , L_23 ) ;
V_50 = F_38 ( V_10 , NULL , V_116 , F_107 ( & V_118 ) ) ;
if ( V_50 ) {
F_103 ( V_10 ) ;
return V_50 ;
}
return 0 ;
}
void F_108 ( struct V_9 * V_10 , int V_119 )
{
enum V_120 V_121 ;
T_7 * V_122 = & V_123 [ V_119 ] ;
V_121 = V_119 ? V_124 : V_125 ;
if ( F_109 ( V_121 , & V_10 -> V_26 ) )
F_110 ( & V_126 [ V_119 ] ) ;
F_60 () ;
if ( F_111 ( V_122 ) )
F_112 ( V_122 ) ;
}
void F_113 ( struct V_9 * V_10 , int V_119 )
{
enum V_120 V_121 ;
V_121 = V_119 ? V_124 : V_125 ;
if ( ! F_114 ( V_121 , & V_10 -> V_26 ) )
F_115 ( & V_126 [ V_119 ] ) ;
}
long F_116 ( int V_119 , long V_66 )
{
long V_41 ;
unsigned long V_127 = V_62 ;
F_117 ( V_128 ) ;
T_7 * V_122 = & V_123 [ V_119 ] ;
F_118 ( V_122 , & V_128 , V_91 ) ;
V_41 = F_119 ( V_66 ) ;
F_120 ( V_122 , & V_128 ) ;
F_121 ( F_122 ( V_66 ) ,
F_122 ( V_62 - V_127 ) ) ;
return V_41 ;
}
long F_123 ( struct V_129 * V_129 , int V_119 , long V_66 )
{
long V_41 ;
unsigned long V_127 = V_62 ;
F_117 ( V_128 ) ;
T_7 * V_122 = & V_123 [ V_119 ] ;
if ( F_124 ( & V_126 [ V_119 ] ) == 0 ||
! F_125 ( V_129 ) ) {
F_126 () ;
V_41 = V_66 - ( V_62 - V_127 ) ;
if ( V_41 < 0 )
V_41 = 0 ;
goto V_130;
}
F_118 ( V_122 , & V_128 , V_91 ) ;
V_41 = F_119 ( V_66 ) ;
F_120 ( V_122 , & V_128 ) ;
V_130:
F_127 ( F_122 ( V_66 ) ,
F_122 ( V_62 - V_127 ) ) ;
return V_41 ;
}
