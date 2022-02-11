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
unsigned long V_39 ;
T_2 V_40 ;
V_40 = F_23 ( V_37 , 10 , & V_39 ) ;
if ( V_40 < 0 )
return V_40 ;
V_10 -> V_41 = V_39 >> ( V_42 - 10 ) ;
return V_38 ;
}
static T_2 F_24 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_3 V_38 )
{
struct V_9 * V_10 = F_22 ( V_34 ) ;
unsigned int V_43 ;
T_2 V_40 ;
V_40 = F_25 ( V_37 , 10 , & V_43 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_26 ( V_10 , V_43 ) ;
if ( ! V_40 )
V_40 = V_38 ;
return V_40 ;
}
static T_2 F_27 ( struct V_33 * V_34 ,
struct V_35 * V_36 , const char * V_37 , T_3 V_38 )
{
struct V_9 * V_10 = F_22 ( V_34 ) ;
unsigned int V_43 ;
T_2 V_40 ;
V_40 = F_25 ( V_37 , 10 , & V_43 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_28 ( V_10 , V_43 ) ;
if ( ! V_40 )
V_40 = V_38 ;
return V_40 ;
}
static T_4 int F_29 ( void )
{
V_44 = F_30 ( V_45 , L_1 ) ;
if ( F_31 ( V_44 ) )
return F_32 ( V_44 ) ;
V_44 -> V_46 = V_47 ;
F_4 () ;
return 0 ;
}
static int T_4 F_33 ( void )
{
int V_48 ;
V_48 = F_34 ( & V_49 ) ;
if ( ! V_48 )
F_35 ( & V_49 , NULL , L_16 ) ;
V_48 = F_34 ( & V_50 ) ;
return V_48 ;
}
int F_36 ( struct V_9 * V_10 )
{
return F_37 ( & V_10 -> V_12 ) ;
}
static void F_38 ( unsigned long V_51 )
{
struct V_9 * V_10 = (struct V_9 * ) V_51 ;
F_39 ( & V_10 -> V_52 ) ;
if ( V_10 -> V_12 . V_53 ) {
F_40 ( V_10 ) ;
F_41 ( V_10 -> V_12 . V_53 ) ;
} else if ( V_10 -> V_34 ) {
F_42 ( V_10 ) ;
F_41 ( V_49 . V_12 . V_53 ) ;
}
F_43 ( & V_10 -> V_52 ) ;
}
void F_44 ( struct V_9 * V_10 )
{
unsigned long V_54 ;
V_54 = F_45 ( V_55 * 10 ) ;
F_46 ( & V_10 -> V_12 . V_56 , V_57 + V_54 ) ;
}
static unsigned long F_47 ( void )
{
unsigned long V_58 ;
V_58 = F_45 ( V_55 * 10 ) ;
return F_48 ( 5UL * 60 * V_59 , V_58 ) ;
}
static void F_49 ( struct V_9 * V_10 )
{
F_50 ( V_60 , & V_10 -> V_26 ) ;
F_51 () ;
F_52 ( & V_10 -> V_26 , V_60 ) ;
}
static int F_53 ( void * V_61 )
{
struct V_1 * V_62 = V_61 ;
V_63 -> V_64 |= V_65 ;
F_54 () ;
F_55 ( V_63 , 0 ) ;
for (; ; ) {
struct V_66 * V_53 = NULL ;
struct V_9 * V_10 ;
enum {
V_67 ,
V_68 ,
V_69 ,
} V_70 = V_67 ;
if ( F_37 ( V_62 ) || ! F_14 ( & V_62 -> V_10 -> V_71 ) ) {
F_56 ( & V_62 -> V_56 ) ;
F_57 ( V_62 , 0 ) ;
}
F_39 ( & V_72 ) ;
F_58 ( V_73 ) ;
F_7 (bdi, &bdi_list, bdi_list) {
bool V_74 ;
if ( ! F_59 ( V_10 ) ||
F_60 ( V_10 ) )
continue;
F_61 ( ! F_62 ( V_75 , & V_10 -> V_26 ) ,
L_17 , V_10 , V_10 -> V_29 ) ;
V_74 = ! F_14 ( & V_10 -> V_71 ) ||
F_37 ( & V_10 -> V_12 ) ;
if ( ! V_10 -> V_12 . V_53 && V_74 ) {
F_63 ( V_60 , & V_10 -> V_26 ) ;
V_70 = V_68 ;
break;
}
F_2 ( & V_10 -> V_52 ) ;
if ( V_10 -> V_12 . V_53 && ! V_74 &&
F_64 ( V_57 , V_10 -> V_12 . V_76 +
F_47 () ) ) {
V_53 = V_10 -> V_12 . V_53 ;
V_10 -> V_12 . V_53 = NULL ;
F_8 ( & V_10 -> V_52 ) ;
F_63 ( V_60 , & V_10 -> V_26 ) ;
V_70 = V_69 ;
break;
}
F_8 ( & V_10 -> V_52 ) ;
}
F_43 ( & V_72 ) ;
if ( ! F_14 ( & V_62 -> V_10 -> V_71 ) )
F_65 ( V_77 ) ;
switch ( V_70 ) {
case V_68 :
F_65 ( V_77 ) ;
V_53 = F_66 ( V_78 , & V_10 -> V_12 ,
L_18 , F_67 ( V_10 -> V_34 ) ) ;
if ( F_31 ( V_53 ) ) {
F_68 ( & V_10 -> V_12 , 1024 ,
V_79 ) ;
} else {
F_39 ( & V_10 -> V_52 ) ;
V_10 -> V_12 . V_53 = V_53 ;
F_43 ( & V_10 -> V_52 ) ;
F_41 ( V_53 ) ;
}
F_49 ( V_10 ) ;
break;
case V_69 :
F_65 ( V_77 ) ;
F_69 ( V_53 ) ;
F_49 ( V_10 ) ;
break;
case V_67 :
if ( ! F_37 ( V_62 ) || ! V_55 )
F_70 ( F_47 () ) ;
else
F_70 ( F_45 ( V_55 * 10 ) ) ;
F_71 () ;
break;
}
}
return 0 ;
}
static void F_72 ( struct V_9 * V_10 )
{
F_39 ( & V_72 ) ;
F_73 ( & V_10 -> V_25 ) ;
F_43 ( & V_72 ) ;
F_74 () ;
}
int F_35 ( struct V_9 * V_10 , struct V_33 * V_80 ,
const char * V_81 , ... )
{
T_5 args ;
struct V_33 * V_34 ;
if ( V_10 -> V_34 )
return 0 ;
va_start ( args , V_81 ) ;
V_34 = F_75 ( V_44 , V_80 , F_76 ( 0 , 0 ) , V_10 , V_81 , args ) ;
va_end ( args ) ;
if ( F_31 ( V_34 ) )
return F_32 ( V_34 ) ;
V_10 -> V_34 = V_34 ;
if ( F_60 ( V_10 ) ) {
struct V_1 * V_12 = & V_10 -> V_12 ;
V_12 -> V_53 = F_77 ( F_53 , V_12 , L_19 ,
F_67 ( V_34 ) ) ;
if ( F_31 ( V_12 -> V_53 ) )
return F_32 ( V_12 -> V_53 ) ;
}
F_17 ( V_10 , F_67 ( V_34 ) ) ;
F_63 ( V_75 , & V_10 -> V_26 ) ;
F_39 ( & V_72 ) ;
F_78 ( & V_10 -> V_25 , & V_25 ) ;
F_43 ( & V_72 ) ;
F_79 ( V_10 ) ;
return 0 ;
}
int F_80 ( struct V_9 * V_10 , T_6 V_34 )
{
return F_35 ( V_10 , NULL , L_20 , F_81 ( V_34 ) , F_82 ( V_34 ) ) ;
}
static void F_83 ( struct V_9 * V_10 )
{
struct V_66 * V_53 ;
if ( ! F_59 ( V_10 ) )
return;
F_72 ( V_10 ) ;
F_84 ( & V_10 -> V_26 , V_60 , V_82 ,
V_83 ) ;
F_39 ( & V_10 -> V_52 ) ;
V_53 = V_10 -> V_12 . V_53 ;
V_10 -> V_12 . V_53 = NULL ;
F_43 ( & V_10 -> V_52 ) ;
if ( V_53 )
F_69 ( V_53 ) ;
}
static void F_85 ( struct V_9 * V_10 )
{
struct V_84 * V_85 ;
F_2 ( & V_86 ) ;
F_7 (sb, &super_blocks, s_list) {
if ( V_85 -> V_87 == V_10 )
V_85 -> V_87 = & V_49 ;
}
F_8 ( & V_86 ) ;
}
void F_86 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = V_10 -> V_34 ;
if ( V_34 ) {
F_26 ( V_10 , 0 ) ;
F_87 ( V_10 ) ;
F_85 ( V_10 ) ;
F_88 ( & V_10 -> V_12 . V_56 ) ;
if ( ! F_60 ( V_10 ) )
F_83 ( V_10 ) ;
F_19 ( V_10 ) ;
F_39 ( & V_10 -> V_52 ) ;
V_10 -> V_34 = NULL ;
F_43 ( & V_10 -> V_52 ) ;
F_89 ( V_34 ) ;
}
}
static void F_90 ( struct V_1 * V_12 , struct V_9 * V_10 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_88 = V_57 ;
F_91 ( & V_12 -> V_89 ) ;
F_91 ( & V_12 -> V_90 ) ;
F_91 ( & V_12 -> V_91 ) ;
F_92 ( & V_12 -> V_4 ) ;
F_93 ( & V_12 -> V_56 , F_38 , ( unsigned long ) V_10 ) ;
}
int F_34 ( struct V_9 * V_10 )
{
int V_92 , V_48 ;
V_10 -> V_34 = NULL ;
V_10 -> V_93 = 0 ;
V_10 -> V_94 = 100 ;
V_10 -> V_95 = V_96 ;
F_92 ( & V_10 -> V_52 ) ;
F_91 ( & V_10 -> V_25 ) ;
F_91 ( & V_10 -> V_71 ) ;
F_90 ( & V_10 -> V_12 , V_10 ) ;
for ( V_92 = 0 ; V_92 < V_97 ; V_92 ++ ) {
V_48 = F_94 ( & V_10 -> F_13 [ V_92 ] , 0 ) ;
if ( V_48 )
goto V_48;
}
V_10 -> V_98 = 0 ;
V_10 -> V_99 = V_57 ;
V_10 -> V_100 = 0 ;
V_10 -> V_101 = V_102 ;
V_10 -> V_103 = V_102 ;
V_10 -> V_24 = V_102 ;
V_10 -> V_104 = V_102 ;
V_48 = F_95 ( & V_10 -> V_105 ) ;
if ( V_48 ) {
V_48:
while ( V_92 -- )
F_96 ( & V_10 -> F_13 [ V_92 ] ) ;
}
return V_48 ;
}
void F_97 ( struct V_9 * V_10 )
{
int V_92 ;
if ( F_36 ( V_10 ) ) {
struct V_1 * V_106 = & V_49 . V_12 ;
F_1 ( & V_10 -> V_12 , V_106 ) ;
F_98 ( & V_10 -> V_12 . V_89 , & V_106 -> V_89 ) ;
F_98 ( & V_10 -> V_12 . V_90 , & V_106 -> V_90 ) ;
F_98 ( & V_10 -> V_12 . V_91 , & V_106 -> V_91 ) ;
F_8 ( & V_10 -> V_12 . V_4 ) ;
F_8 ( & V_106 -> V_4 ) ;
}
F_86 ( V_10 ) ;
F_88 ( & V_10 -> V_12 . V_56 ) ;
for ( V_92 = 0 ; V_92 < V_97 ; V_92 ++ )
F_96 ( & V_10 -> F_13 [ V_92 ] ) ;
F_99 ( & V_10 -> V_105 ) ;
}
int F_100 ( struct V_9 * V_10 , char * V_29 ,
unsigned int V_107 )
{
char V_108 [ 32 ] ;
int V_48 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_109 = V_107 ;
V_48 = F_34 ( V_10 ) ;
if ( V_48 )
return V_48 ;
sprintf ( V_108 , L_21 , V_29 , L_22 ) ;
V_48 = F_35 ( V_10 , NULL , V_108 , F_101 ( & V_110 ) ) ;
if ( V_48 ) {
F_97 ( V_10 ) ;
return V_48 ;
}
return 0 ;
}
void F_102 ( struct V_9 * V_10 , int V_111 )
{
enum V_112 V_113 ;
T_7 * V_114 = & V_115 [ V_111 ] ;
V_113 = V_111 ? V_116 : V_117 ;
if ( F_103 ( V_113 , & V_10 -> V_26 ) )
F_104 ( & V_118 [ V_111 ] ) ;
F_51 () ;
if ( F_105 ( V_114 ) )
F_106 ( V_114 ) ;
}
void F_107 ( struct V_9 * V_10 , int V_111 )
{
enum V_112 V_113 ;
V_113 = V_111 ? V_116 : V_117 ;
if ( ! F_108 ( V_113 , & V_10 -> V_26 ) )
F_109 ( & V_118 [ V_111 ] ) ;
}
long F_110 ( int V_111 , long V_54 )
{
long V_40 ;
unsigned long V_119 = V_57 ;
F_111 ( V_120 ) ;
T_7 * V_114 = & V_115 [ V_111 ] ;
F_112 ( V_114 , & V_120 , V_83 ) ;
V_40 = F_113 ( V_54 ) ;
F_114 ( V_114 , & V_120 ) ;
F_115 ( F_116 ( V_54 ) ,
F_116 ( V_57 - V_119 ) ) ;
return V_40 ;
}
long F_117 ( struct V_121 * V_121 , int V_111 , long V_54 )
{
long V_40 ;
unsigned long V_119 = V_57 ;
F_111 ( V_120 ) ;
T_7 * V_114 = & V_115 [ V_111 ] ;
if ( F_118 ( & V_118 [ V_111 ] ) == 0 ||
! F_119 ( V_121 ) ) {
F_120 () ;
V_40 = V_54 - ( V_57 - V_119 ) ;
if ( V_40 < 0 )
V_40 = 0 ;
goto V_122;
}
F_112 ( V_114 , & V_120 , V_83 ) ;
V_40 = F_113 ( V_54 ) ;
F_114 ( V_114 , & V_120 ) ;
V_122:
F_121 ( F_116 ( V_54 ) ,
F_116 ( V_57 - V_119 ) ) ;
return V_40 ;
}
int F_122 ( struct V_123 * V_124 , int V_125 ,
void T_8 * V_126 , T_3 * V_127 , T_9 * V_128 )
{
char V_129 [] = L_23 ;
if ( * V_128 ) {
* V_127 = 0 ;
return 0 ;
}
if ( F_123 ( V_126 , V_129 , sizeof( V_129 ) ) )
return - V_130 ;
F_124 ( V_131 L_24 ,
V_124 -> V_132 ) ;
* V_127 = 2 ;
* V_128 += * V_127 ;
return 2 ;
}
