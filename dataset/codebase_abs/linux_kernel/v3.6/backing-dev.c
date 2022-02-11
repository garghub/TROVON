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
V_50 = F_33 ( & V_51 ) ;
if ( ! V_50 )
F_34 ( & V_51 , NULL , L_16 ) ;
V_50 = F_33 ( & V_52 ) ;
return V_50 ;
}
int F_35 ( struct V_9 * V_10 )
{
return F_36 ( & V_10 -> V_12 ) ;
}
static void F_37 ( unsigned long V_53 )
{
struct V_9 * V_10 = (struct V_9 * ) V_53 ;
F_38 ( & V_10 -> V_54 ) ;
if ( V_10 -> V_12 . V_55 ) {
F_39 ( V_10 ) ;
F_40 ( V_10 -> V_12 . V_55 ) ;
} else if ( V_10 -> V_34 ) {
F_41 ( V_10 ) ;
F_40 ( V_51 . V_12 . V_55 ) ;
}
F_42 ( & V_10 -> V_54 ) ;
}
void F_43 ( struct V_9 * V_10 )
{
unsigned long V_56 ;
V_56 = F_44 ( V_57 * 10 ) ;
F_45 ( & V_10 -> V_12 . V_58 , V_59 + V_56 ) ;
}
static unsigned long F_46 ( void )
{
unsigned long V_60 ;
V_60 = F_44 ( V_57 * 10 ) ;
return F_47 ( 5UL * 60 * V_61 , V_60 ) ;
}
static void F_48 ( struct V_9 * V_10 )
{
F_49 ( V_62 , & V_10 -> V_26 ) ;
F_50 () ;
F_51 ( & V_10 -> V_26 , V_62 ) ;
}
static int F_52 ( void * V_63 )
{
struct V_1 * V_64 = V_63 ;
V_65 -> V_66 |= V_67 ;
F_53 () ;
F_54 ( V_65 , 0 ) ;
for (; ; ) {
struct V_68 * V_55 = NULL ;
struct V_9 * V_10 ;
enum {
V_69 ,
V_70 ,
V_71 ,
} V_72 = V_69 ;
if ( F_36 ( V_64 ) || ! F_14 ( & V_64 -> V_10 -> V_73 ) ) {
F_55 ( & V_64 -> V_58 ) ;
F_56 ( V_64 , 0 ) ;
}
F_38 ( & V_74 ) ;
F_57 ( V_75 ) ;
F_7 (bdi, &bdi_list, bdi_list) {
bool V_76 ;
if ( ! F_58 ( V_10 ) ||
F_59 ( V_10 ) )
continue;
F_60 ( ! F_61 ( V_77 , & V_10 -> V_26 ) ,
L_17 , V_10 , V_10 -> V_29 ) ;
V_76 = ! F_14 ( & V_10 -> V_73 ) ||
F_36 ( & V_10 -> V_12 ) ;
if ( ! V_10 -> V_12 . V_55 && V_76 ) {
F_62 ( V_62 , & V_10 -> V_26 ) ;
V_72 = V_70 ;
break;
}
F_2 ( & V_10 -> V_54 ) ;
if ( V_10 -> V_12 . V_55 && ! V_76 &&
F_63 ( V_59 , V_10 -> V_12 . V_78 +
F_46 () ) ) {
V_55 = V_10 -> V_12 . V_55 ;
V_10 -> V_12 . V_55 = NULL ;
F_8 ( & V_10 -> V_54 ) ;
F_62 ( V_62 , & V_10 -> V_26 ) ;
V_72 = V_71 ;
break;
}
F_8 ( & V_10 -> V_54 ) ;
}
F_42 ( & V_74 ) ;
if ( ! F_14 ( & V_64 -> V_10 -> V_73 ) )
F_64 ( V_79 ) ;
switch ( V_72 ) {
case V_70 :
F_64 ( V_79 ) ;
V_55 = F_65 ( V_80 , & V_10 -> V_12 ,
L_18 , F_66 ( V_10 -> V_34 ) ) ;
if ( F_30 ( V_55 ) ) {
F_67 ( & V_10 -> V_12 , 1024 ,
V_81 ) ;
} else {
F_38 ( & V_10 -> V_54 ) ;
V_10 -> V_12 . V_55 = V_55 ;
F_42 ( & V_10 -> V_54 ) ;
F_40 ( V_55 ) ;
}
F_48 ( V_10 ) ;
break;
case V_71 :
F_64 ( V_79 ) ;
F_68 ( V_55 ) ;
F_48 ( V_10 ) ;
break;
case V_69 :
if ( ! F_36 ( V_64 ) || ! V_57 )
F_69 ( F_46 () ) ;
else
F_69 ( F_44 ( V_57 * 10 ) ) ;
F_70 () ;
break;
}
}
return 0 ;
}
static void F_71 ( struct V_9 * V_10 )
{
F_38 ( & V_74 ) ;
F_72 ( & V_10 -> V_25 ) ;
F_42 ( & V_74 ) ;
F_73 () ;
}
int F_34 ( struct V_9 * V_10 , struct V_33 * V_82 ,
const char * V_83 , ... )
{
T_5 args ;
struct V_33 * V_34 ;
if ( V_10 -> V_34 )
return 0 ;
va_start ( args , V_83 ) ;
V_34 = F_74 ( V_46 , V_82 , F_75 ( 0 , 0 ) , V_10 , V_83 , args ) ;
va_end ( args ) ;
if ( F_30 ( V_34 ) )
return F_31 ( V_34 ) ;
V_10 -> V_34 = V_34 ;
if ( F_59 ( V_10 ) ) {
struct V_1 * V_12 = & V_10 -> V_12 ;
V_12 -> V_55 = F_76 ( F_52 , V_12 , L_19 ,
F_66 ( V_34 ) ) ;
if ( F_30 ( V_12 -> V_55 ) )
return F_31 ( V_12 -> V_55 ) ;
}
F_17 ( V_10 , F_66 ( V_34 ) ) ;
F_62 ( V_77 , & V_10 -> V_26 ) ;
F_38 ( & V_74 ) ;
F_77 ( & V_10 -> V_25 , & V_25 ) ;
F_42 ( & V_74 ) ;
F_78 ( V_10 ) ;
return 0 ;
}
int F_79 ( struct V_9 * V_10 , T_6 V_34 )
{
return F_34 ( V_10 , NULL , L_20 , F_80 ( V_34 ) , F_81 ( V_34 ) ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
struct V_68 * V_55 ;
if ( ! F_58 ( V_10 ) )
return;
F_71 ( V_10 ) ;
F_83 ( & V_10 -> V_26 , V_62 , V_84 ,
V_85 ) ;
F_38 ( & V_10 -> V_54 ) ;
V_55 = V_10 -> V_12 . V_55 ;
V_10 -> V_12 . V_55 = NULL ;
F_42 ( & V_10 -> V_54 ) ;
if ( V_55 )
F_68 ( V_55 ) ;
}
static void F_84 ( struct V_9 * V_10 )
{
struct V_86 * V_87 ;
F_2 ( & V_88 ) ;
F_7 (sb, &super_blocks, s_list) {
if ( V_87 -> V_89 == V_10 )
V_87 -> V_89 = & V_51 ;
}
F_8 ( & V_88 ) ;
}
void F_85 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = V_10 -> V_34 ;
if ( V_34 ) {
F_25 ( V_10 , 0 ) ;
F_86 ( V_10 ) ;
F_84 ( V_10 ) ;
F_87 ( & V_10 -> V_12 . V_58 ) ;
if ( ! F_59 ( V_10 ) )
F_82 ( V_10 ) ;
F_19 ( V_10 ) ;
F_38 ( & V_10 -> V_54 ) ;
V_10 -> V_34 = NULL ;
F_42 ( & V_10 -> V_54 ) ;
F_88 ( V_34 ) ;
}
}
static void F_89 ( struct V_1 * V_12 , struct V_9 * V_10 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_90 = V_59 ;
F_90 ( & V_12 -> V_91 ) ;
F_90 ( & V_12 -> V_92 ) ;
F_90 ( & V_12 -> V_93 ) ;
F_91 ( & V_12 -> V_4 ) ;
F_92 ( & V_12 -> V_58 , F_37 , ( unsigned long ) V_10 ) ;
}
int F_33 ( struct V_9 * V_10 )
{
int V_94 , V_50 ;
V_10 -> V_34 = NULL ;
V_10 -> V_95 = 0 ;
V_10 -> V_96 = 100 ;
V_10 -> V_97 = V_98 ;
F_91 ( & V_10 -> V_54 ) ;
F_90 ( & V_10 -> V_25 ) ;
F_90 ( & V_10 -> V_73 ) ;
F_89 ( & V_10 -> V_12 , V_10 ) ;
for ( V_94 = 0 ; V_94 < V_99 ; V_94 ++ ) {
V_50 = F_93 ( & V_10 -> F_13 [ V_94 ] , 0 ) ;
if ( V_50 )
goto V_50;
}
V_10 -> V_100 = 0 ;
V_10 -> V_101 = V_59 ;
V_10 -> V_102 = 0 ;
V_10 -> V_103 = V_104 ;
V_10 -> V_105 = V_104 ;
V_10 -> V_24 = V_104 ;
V_10 -> V_106 = V_104 ;
V_50 = F_94 ( & V_10 -> V_107 ) ;
if ( V_50 ) {
V_50:
while ( V_94 -- )
F_95 ( & V_10 -> F_13 [ V_94 ] ) ;
}
return V_50 ;
}
void F_96 ( struct V_9 * V_10 )
{
int V_94 ;
if ( F_35 ( V_10 ) ) {
struct V_1 * V_108 = & V_51 . V_12 ;
F_1 ( & V_10 -> V_12 , V_108 ) ;
F_97 ( & V_10 -> V_12 . V_91 , & V_108 -> V_91 ) ;
F_97 ( & V_10 -> V_12 . V_92 , & V_108 -> V_92 ) ;
F_97 ( & V_10 -> V_12 . V_93 , & V_108 -> V_93 ) ;
F_8 ( & V_10 -> V_12 . V_4 ) ;
F_8 ( & V_108 -> V_4 ) ;
}
F_85 ( V_10 ) ;
F_87 ( & V_10 -> V_12 . V_58 ) ;
for ( V_94 = 0 ; V_94 < V_99 ; V_94 ++ )
F_95 ( & V_10 -> F_13 [ V_94 ] ) ;
F_98 ( & V_10 -> V_107 ) ;
}
int F_99 ( struct V_9 * V_10 , char * V_29 ,
unsigned int V_109 )
{
char V_110 [ 32 ] ;
int V_50 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_111 = V_109 ;
V_50 = F_33 ( V_10 ) ;
if ( V_50 )
return V_50 ;
sprintf ( V_110 , L_21 , V_29 , L_22 ) ;
V_50 = F_34 ( V_10 , NULL , V_110 , F_100 ( & V_112 ) ) ;
if ( V_50 ) {
F_96 ( V_10 ) ;
return V_50 ;
}
return 0 ;
}
void F_101 ( struct V_9 * V_10 , int V_113 )
{
enum V_114 V_115 ;
T_7 * V_116 = & V_117 [ V_113 ] ;
V_115 = V_113 ? V_118 : V_119 ;
if ( F_102 ( V_115 , & V_10 -> V_26 ) )
F_103 ( & V_120 [ V_113 ] ) ;
F_50 () ;
if ( F_104 ( V_116 ) )
F_105 ( V_116 ) ;
}
void F_106 ( struct V_9 * V_10 , int V_113 )
{
enum V_114 V_115 ;
V_115 = V_113 ? V_118 : V_119 ;
if ( ! F_107 ( V_115 , & V_10 -> V_26 ) )
F_108 ( & V_120 [ V_113 ] ) ;
}
long F_109 ( int V_113 , long V_56 )
{
long V_41 ;
unsigned long V_121 = V_59 ;
F_110 ( V_122 ) ;
T_7 * V_116 = & V_117 [ V_113 ] ;
F_111 ( V_116 , & V_122 , V_85 ) ;
V_41 = F_112 ( V_56 ) ;
F_113 ( V_116 , & V_122 ) ;
F_114 ( F_115 ( V_56 ) ,
F_115 ( V_59 - V_121 ) ) ;
return V_41 ;
}
long F_116 ( struct V_123 * V_123 , int V_113 , long V_56 )
{
long V_41 ;
unsigned long V_121 = V_59 ;
F_110 ( V_122 ) ;
T_7 * V_116 = & V_117 [ V_113 ] ;
if ( F_117 ( & V_120 [ V_113 ] ) == 0 ||
! F_118 ( V_123 ) ) {
F_119 () ;
V_41 = V_56 - ( V_59 - V_121 ) ;
if ( V_41 < 0 )
V_41 = 0 ;
goto V_124;
}
F_111 ( V_116 , & V_122 , V_85 ) ;
V_41 = F_112 ( V_56 ) ;
F_113 ( V_116 , & V_122 ) ;
V_124:
F_120 ( F_115 ( V_56 ) ,
F_115 ( V_59 - V_121 ) ) ;
return V_41 ;
}
int F_121 ( struct V_125 * V_126 , int V_127 ,
void T_8 * V_128 , T_3 * V_129 , T_9 * V_130 )
{
char V_131 [] = L_23 ;
if ( * V_130 ) {
* V_129 = 0 ;
return 0 ;
}
if ( F_122 ( V_128 , V_131 , sizeof( V_131 ) ) )
return - V_132 ;
F_123 ( V_133 L_24 ,
V_126 -> V_134 ) ;
* V_129 = 2 ;
* V_130 += * V_129 ;
return 2 ;
}
