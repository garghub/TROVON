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
static T_2 F_29 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
char * V_44 )
{
struct V_9 * V_10 = F_22 ( V_34 ) ;
return snprintf ( V_44 , V_45 - 1 , L_16 ,
F_30 ( V_10 ) ? 1 : 0 ) ;
}
static T_4 int F_31 ( void )
{
V_46 = F_32 ( V_47 , L_1 ) ;
if ( F_33 ( V_46 ) )
return F_34 ( V_46 ) ;
V_46 -> V_48 = V_49 ;
F_4 () ;
return 0 ;
}
static int T_4 F_35 ( void )
{
int V_50 ;
V_51 = F_36 ( L_17 , V_52 | V_53 |
V_54 | V_55 , 0 ) ;
if ( ! V_51 )
return - V_56 ;
V_50 = F_37 ( & V_57 ) ;
if ( ! V_50 )
F_38 ( & V_57 , NULL , L_18 ) ;
V_50 = F_37 ( & V_58 ) ;
return V_50 ;
}
int F_39 ( struct V_9 * V_10 )
{
return F_40 ( & V_10 -> V_12 ) ;
}
void F_41 ( struct V_9 * V_10 )
{
unsigned long V_59 ;
V_59 = F_42 ( V_60 * 10 ) ;
F_43 ( V_51 , & V_10 -> V_12 . V_61 , V_59 ) ;
}
static void F_44 ( struct V_9 * V_10 )
{
F_45 ( & V_62 ) ;
F_46 ( & V_10 -> V_25 ) ;
F_47 ( & V_62 ) ;
F_48 () ;
F_49 ( & V_10 -> V_25 ) ;
}
int F_38 ( struct V_9 * V_10 , struct V_33 * V_63 ,
const char * V_64 , ... )
{
T_5 args ;
struct V_33 * V_34 ;
if ( V_10 -> V_34 )
return 0 ;
va_start ( args , V_64 ) ;
V_34 = F_50 ( V_46 , V_63 , F_51 ( 0 , 0 ) , V_10 , V_64 , args ) ;
va_end ( args ) ;
if ( F_33 ( V_34 ) )
return F_34 ( V_34 ) ;
V_10 -> V_34 = V_34 ;
F_17 ( V_10 , F_52 ( V_34 ) ) ;
F_53 ( V_65 , & V_10 -> V_26 ) ;
F_45 ( & V_62 ) ;
F_54 ( & V_10 -> V_25 , & V_25 ) ;
F_47 ( & V_62 ) ;
F_55 ( V_10 ) ;
return 0 ;
}
int F_56 ( struct V_9 * V_10 , T_6 V_34 )
{
return F_38 ( V_10 , NULL , L_19 , F_57 ( V_34 ) , F_58 ( V_34 ) ) ;
}
static void F_59 ( struct V_9 * V_10 )
{
if ( ! F_60 ( V_10 ) )
return;
F_44 ( V_10 ) ;
F_43 ( V_51 , & V_10 -> V_12 . V_61 , 0 ) ;
F_61 ( & V_10 -> V_12 . V_61 ) ;
F_62 ( ! F_14 ( & V_10 -> V_66 ) ) ;
F_63 ( & V_10 -> V_12 . V_61 ) ;
}
static void F_64 ( struct V_9 * V_10 )
{
struct V_67 * V_68 ;
F_2 ( & V_69 ) ;
F_7 (sb, &super_blocks, s_list) {
if ( V_68 -> V_70 == V_10 )
V_68 -> V_70 = & V_57 ;
}
F_8 ( & V_69 ) ;
}
void F_65 ( struct V_9 * V_10 )
{
struct V_33 * V_34 = V_10 -> V_34 ;
if ( V_34 ) {
F_26 ( V_10 , 0 ) ;
F_66 ( V_10 ) ;
F_64 ( V_10 ) ;
F_59 ( V_10 ) ;
F_19 ( V_10 ) ;
F_45 ( & V_10 -> V_71 ) ;
V_10 -> V_34 = NULL ;
F_47 ( & V_10 -> V_71 ) ;
F_67 ( V_34 ) ;
}
}
static void F_68 ( struct V_1 * V_12 , struct V_9 * V_10 )
{
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_10 = V_10 ;
V_12 -> V_72 = V_73 ;
F_49 ( & V_12 -> V_74 ) ;
F_49 ( & V_12 -> V_75 ) ;
F_49 ( & V_12 -> V_76 ) ;
F_69 ( & V_12 -> V_4 ) ;
F_70 ( & V_12 -> V_61 , V_77 ) ;
}
int F_37 ( struct V_9 * V_10 )
{
int V_78 , V_50 ;
V_10 -> V_34 = NULL ;
V_10 -> V_79 = 0 ;
V_10 -> V_80 = 100 ;
V_10 -> V_81 = V_82 ;
F_69 ( & V_10 -> V_71 ) ;
F_49 ( & V_10 -> V_25 ) ;
F_49 ( & V_10 -> V_66 ) ;
F_68 ( & V_10 -> V_12 , V_10 ) ;
for ( V_78 = 0 ; V_78 < V_83 ; V_78 ++ ) {
V_50 = F_71 ( & V_10 -> F_13 [ V_78 ] , 0 ) ;
if ( V_50 )
goto V_50;
}
V_10 -> V_84 = 0 ;
V_10 -> V_85 = V_73 ;
V_10 -> V_86 = 0 ;
V_10 -> V_87 = V_88 ;
V_10 -> V_89 = V_88 ;
V_10 -> V_24 = V_88 ;
V_10 -> V_90 = V_88 ;
V_50 = F_72 ( & V_10 -> V_91 ) ;
if ( V_50 ) {
V_50:
while ( V_78 -- )
F_73 ( & V_10 -> F_13 [ V_78 ] ) ;
}
return V_50 ;
}
void F_74 ( struct V_9 * V_10 )
{
int V_78 ;
if ( F_39 ( V_10 ) ) {
struct V_1 * V_92 = & V_57 . V_12 ;
F_1 ( & V_10 -> V_12 , V_92 ) ;
F_75 ( & V_10 -> V_12 . V_74 , & V_92 -> V_74 ) ;
F_75 ( & V_10 -> V_12 . V_75 , & V_92 -> V_75 ) ;
F_75 ( & V_10 -> V_12 . V_76 , & V_92 -> V_76 ) ;
F_8 ( & V_10 -> V_12 . V_4 ) ;
F_8 ( & V_92 -> V_4 ) ;
}
F_65 ( V_10 ) ;
F_63 ( & V_10 -> V_12 . V_61 ) ;
for ( V_78 = 0 ; V_78 < V_83 ; V_78 ++ )
F_73 ( & V_10 -> F_13 [ V_78 ] ) ;
F_76 ( & V_10 -> V_91 ) ;
}
int F_77 ( struct V_9 * V_10 , char * V_29 ,
unsigned int V_93 )
{
char V_94 [ 32 ] ;
int V_50 ;
V_10 -> V_29 = V_29 ;
V_10 -> V_95 = V_93 ;
V_50 = F_37 ( V_10 ) ;
if ( V_50 )
return V_50 ;
sprintf ( V_94 , L_20 , V_29 , L_21 ) ;
V_50 = F_38 ( V_10 , NULL , V_94 , F_78 ( & V_96 ) ) ;
if ( V_50 ) {
F_74 ( V_10 ) ;
return V_50 ;
}
return 0 ;
}
void F_79 ( struct V_9 * V_10 , int V_97 )
{
enum V_98 V_99 ;
T_7 * V_100 = & V_101 [ V_97 ] ;
V_99 = V_97 ? V_102 : V_103 ;
if ( F_80 ( V_99 , & V_10 -> V_26 ) )
F_81 ( & V_104 [ V_97 ] ) ;
F_82 () ;
if ( F_83 ( V_100 ) )
F_84 ( V_100 ) ;
}
void F_85 ( struct V_9 * V_10 , int V_97 )
{
enum V_98 V_99 ;
V_99 = V_97 ? V_102 : V_103 ;
if ( ! F_86 ( V_99 , & V_10 -> V_26 ) )
F_87 ( & V_104 [ V_97 ] ) ;
}
long F_88 ( int V_97 , long V_59 )
{
long V_40 ;
unsigned long V_105 = V_73 ;
F_89 ( V_106 ) ;
T_7 * V_100 = & V_101 [ V_97 ] ;
F_90 ( V_100 , & V_106 , V_107 ) ;
V_40 = F_91 ( V_59 ) ;
F_92 ( V_100 , & V_106 ) ;
F_93 ( F_94 ( V_59 ) ,
F_94 ( V_73 - V_105 ) ) ;
return V_40 ;
}
long F_95 ( struct V_108 * V_108 , int V_97 , long V_59 )
{
long V_40 ;
unsigned long V_105 = V_73 ;
F_89 ( V_106 ) ;
T_7 * V_100 = & V_101 [ V_97 ] ;
if ( F_96 ( & V_104 [ V_97 ] ) == 0 ||
! F_97 ( V_108 ) ) {
F_98 () ;
V_40 = V_59 - ( V_73 - V_105 ) ;
if ( V_40 < 0 )
V_40 = 0 ;
goto V_109;
}
F_90 ( V_100 , & V_106 , V_107 ) ;
V_40 = F_91 ( V_59 ) ;
F_92 ( V_100 , & V_106 ) ;
V_109:
F_99 ( F_94 ( V_59 ) ,
F_94 ( V_73 - V_105 ) ) ;
return V_40 ;
}
int F_100 ( struct V_110 * V_111 , int V_112 ,
void T_8 * V_113 , T_3 * V_114 , T_9 * V_115 )
{
char V_116 [] = L_22 ;
if ( * V_115 ) {
* V_114 = 0 ;
return 0 ;
}
if ( F_101 ( V_113 , V_116 , sizeof( V_116 ) ) )
return - V_117 ;
F_102 ( V_118 L_23 ,
V_111 -> V_119 ) ;
* V_114 = 2 ;
* V_115 += * V_114 ;
return 2 ;
}
