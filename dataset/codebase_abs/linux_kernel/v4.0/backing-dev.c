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
unsigned long V_13 , V_14 , V_15 , V_16 ;
struct V_17 * V_17 ;
V_13 = V_14 = V_15 = V_16 = 0 ;
F_4 ( & V_9 -> V_18 ) ;
F_5 (inode, &wb->b_dirty, i_wb_list)
V_13 ++ ;
F_5 (inode, &wb->b_io, i_wb_list)
V_14 ++ ;
F_5 (inode, &wb->b_more_io, i_wb_list)
V_15 ++ ;
F_5 (inode, &wb->b_dirty_time, i_wb_list)
if ( V_17 -> V_19 & V_20 )
V_16 ++ ;
F_6 ( & V_9 -> V_18 ) ;
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
L_11
L_12
L_13
L_14
L_15 ,
( unsigned long ) F_9 ( F_11 ( V_6 , V_21 ) ) ,
( unsigned long ) F_9 ( F_11 ( V_6 , V_22 ) ) ,
F_9 ( V_12 ) ,
F_9 ( V_11 ) ,
F_9 ( V_10 ) ,
( unsigned long ) F_9 ( F_11 ( V_6 , V_23 ) ) ,
( unsigned long ) F_9 ( F_11 ( V_6 , V_24 ) ) ,
( unsigned long ) F_9 ( V_6 -> V_25 ) ,
V_13 ,
V_14 ,
V_15 ,
V_16 ,
! F_12 ( & V_6 -> V_26 ) , V_6 -> V_27 ) ;
#undef F_9
return 0 ;
}
static int F_13 ( struct V_17 * V_17 , struct V_28 * V_28 )
{
return F_14 ( V_28 , F_3 , V_17 -> V_29 ) ;
}
static void F_15 ( struct V_5 * V_6 , const char * V_30 )
{
V_6 -> V_31 = F_2 ( V_30 , V_1 ) ;
V_6 -> V_32 = F_16 ( L_16 , 0444 , V_6 -> V_31 ,
V_6 , & V_33 ) ;
}
static void F_17 ( struct V_5 * V_6 )
{
F_18 ( V_6 -> V_32 ) ;
F_18 ( V_6 -> V_31 ) ;
}
static inline void F_1 ( void )
{
}
static inline void F_15 ( struct V_5 * V_6 ,
const char * V_30 )
{
}
static inline void F_17 ( struct V_5 * V_6 )
{
}
static T_2 F_19 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
const char * V_38 , T_3 V_39 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
unsigned long V_40 ;
T_2 V_41 ;
V_41 = F_21 ( V_38 , 10 , & V_40 ) ;
if ( V_41 < 0 )
return V_41 ;
V_6 -> V_42 = V_40 >> ( V_43 - 10 ) ;
return V_39 ;
}
static T_2 F_22 ( struct V_34 * V_35 ,
struct V_36 * V_37 , const char * V_38 , T_3 V_39 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
unsigned int V_44 ;
T_2 V_41 ;
V_41 = F_23 ( V_38 , 10 , & V_44 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_24 ( V_6 , V_44 ) ;
if ( ! V_41 )
V_41 = V_39 ;
return V_41 ;
}
static T_2 F_25 ( struct V_34 * V_35 ,
struct V_36 * V_37 , const char * V_38 , T_3 V_39 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
unsigned int V_44 ;
T_2 V_41 ;
V_41 = F_23 ( V_38 , 10 , & V_44 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_26 ( V_6 , V_44 ) ;
if ( ! V_41 )
V_41 = V_39 ;
return V_41 ;
}
static T_2 F_27 ( struct V_34 * V_35 ,
struct V_36 * V_37 ,
char * V_45 )
{
struct V_5 * V_6 = F_20 ( V_35 ) ;
return snprintf ( V_45 , V_46 - 1 , L_17 ,
F_28 ( V_6 ) ? 1 : 0 ) ;
}
static T_4 int F_29 ( void )
{
V_47 = F_30 ( V_48 , L_1 ) ;
if ( F_31 ( V_47 ) )
return F_32 ( V_47 ) ;
V_47 -> V_49 = V_50 ;
F_1 () ;
return 0 ;
}
static int T_4 F_33 ( void )
{
int V_51 ;
V_52 = F_34 ( L_18 , V_53 | V_54 |
V_55 | V_56 , 0 ) ;
if ( ! V_52 )
return - V_57 ;
V_51 = F_35 ( & V_58 ) ;
return V_51 ;
}
int F_36 ( struct V_5 * V_6 )
{
return F_37 ( & V_6 -> V_9 ) ;
}
void F_38 ( struct V_5 * V_6 )
{
unsigned long V_59 ;
V_59 = F_39 ( V_60 * 10 ) ;
F_40 ( & V_6 -> V_61 ) ;
if ( F_41 ( V_62 , & V_6 -> V_27 ) )
F_42 ( V_52 , & V_6 -> V_9 . V_63 , V_59 ) ;
F_43 ( & V_6 -> V_61 ) ;
}
static void F_44 ( struct V_5 * V_6 )
{
F_40 ( & V_64 ) ;
F_45 ( & V_6 -> V_26 ) ;
F_43 ( & V_64 ) ;
F_46 () ;
}
int F_47 ( struct V_5 * V_6 , struct V_34 * V_65 ,
const char * V_66 , ... )
{
T_5 args ;
struct V_34 * V_35 ;
if ( V_6 -> V_35 )
return 0 ;
va_start ( args , V_66 ) ;
V_35 = F_48 ( V_47 , V_65 , F_49 ( 0 , 0 ) , V_6 , V_66 , args ) ;
va_end ( args ) ;
if ( F_31 ( V_35 ) )
return F_32 ( V_35 ) ;
V_6 -> V_35 = V_35 ;
F_15 ( V_6 , F_50 ( V_35 ) ) ;
F_51 ( V_62 , & V_6 -> V_27 ) ;
F_40 ( & V_64 ) ;
F_52 ( & V_6 -> V_26 , & V_26 ) ;
F_43 ( & V_64 ) ;
F_53 ( V_6 ) ;
return 0 ;
}
int F_54 ( struct V_5 * V_6 , T_6 V_35 )
{
return F_47 ( V_6 , NULL , L_19 , F_55 ( V_35 ) , F_56 ( V_35 ) ) ;
}
static void F_57 ( struct V_5 * V_6 )
{
F_40 ( & V_6 -> V_61 ) ;
if ( ! F_58 ( V_62 , & V_6 -> V_27 ) ) {
F_43 ( & V_6 -> V_61 ) ;
return;
}
F_43 ( & V_6 -> V_61 ) ;
F_44 ( V_6 ) ;
F_59 ( V_52 , & V_6 -> V_9 . V_63 , 0 ) ;
F_60 ( & V_6 -> V_9 . V_63 ) ;
}
void F_61 ( struct V_5 * V_6 )
{
if ( F_62 ( ! V_6 -> V_35 ) )
return;
F_24 ( V_6 , 0 ) ;
}
static void F_63 ( struct V_8 * V_9 , struct V_5 * V_6 )
{
memset ( V_9 , 0 , sizeof( * V_9 ) ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_67 = V_68 ;
F_64 ( & V_9 -> V_69 ) ;
F_64 ( & V_9 -> V_70 ) ;
F_64 ( & V_9 -> V_71 ) ;
F_64 ( & V_9 -> V_72 ) ;
F_65 ( & V_9 -> V_18 ) ;
F_66 ( & V_9 -> V_63 , V_73 ) ;
}
int F_35 ( struct V_5 * V_6 )
{
int V_74 , V_51 ;
V_6 -> V_35 = NULL ;
V_6 -> V_75 = 0 ;
V_6 -> V_76 = 100 ;
V_6 -> V_77 = V_78 ;
F_65 ( & V_6 -> V_61 ) ;
F_64 ( & V_6 -> V_26 ) ;
F_64 ( & V_6 -> V_79 ) ;
F_63 ( & V_6 -> V_9 , V_6 ) ;
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ ) {
V_51 = F_67 ( & V_6 -> F_11 [ V_74 ] , 0 , V_81 ) ;
if ( V_51 )
goto V_51;
}
V_6 -> V_82 = 0 ;
V_6 -> V_83 = V_68 ;
V_6 -> V_84 = 0 ;
V_6 -> V_85 = V_86 ;
V_6 -> V_87 = V_86 ;
V_6 -> V_25 = V_86 ;
V_6 -> V_88 = V_86 ;
V_51 = F_68 ( & V_6 -> V_89 , V_81 ) ;
if ( V_51 ) {
V_51:
while ( V_74 -- )
F_69 ( & V_6 -> F_11 [ V_74 ] ) ;
}
return V_51 ;
}
void F_70 ( struct V_5 * V_6 )
{
int V_74 ;
F_57 ( V_6 ) ;
F_71 ( ! F_12 ( & V_6 -> V_79 ) ) ;
F_71 ( F_72 ( & V_6 -> V_9 . V_63 ) ) ;
if ( V_6 -> V_35 ) {
F_17 ( V_6 ) ;
F_73 ( V_6 -> V_35 ) ;
V_6 -> V_35 = NULL ;
}
for ( V_74 = 0 ; V_74 < V_80 ; V_74 ++ )
F_69 ( & V_6 -> F_11 [ V_74 ] ) ;
F_74 ( & V_6 -> V_89 ) ;
}
int F_75 ( struct V_5 * V_6 , char * V_30 )
{
int V_51 ;
V_6 -> V_30 = V_30 ;
V_6 -> V_90 = 0 ;
V_51 = F_35 ( V_6 ) ;
if ( V_51 )
return V_51 ;
V_51 = F_47 ( V_6 , NULL , L_20 , V_30 ,
F_76 ( & V_91 ) ) ;
if ( V_51 ) {
F_70 ( V_6 ) ;
return V_51 ;
}
return 0 ;
}
void F_77 ( struct V_5 * V_6 , int V_92 )
{
enum V_93 V_94 ;
T_7 * V_95 = & V_96 [ V_92 ] ;
V_94 = V_92 ? V_97 : V_98 ;
if ( F_58 ( V_94 , & V_6 -> V_27 ) )
F_78 ( & V_99 [ V_92 ] ) ;
F_79 () ;
if ( F_80 ( V_95 ) )
F_81 ( V_95 ) ;
}
void F_82 ( struct V_5 * V_6 , int V_92 )
{
enum V_93 V_94 ;
V_94 = V_92 ? V_97 : V_98 ;
if ( ! F_83 ( V_94 , & V_6 -> V_27 ) )
F_84 ( & V_99 [ V_92 ] ) ;
}
long F_85 ( int V_92 , long V_59 )
{
long V_41 ;
unsigned long V_100 = V_68 ;
F_86 ( V_101 ) ;
T_7 * V_95 = & V_96 [ V_92 ] ;
F_87 ( V_95 , & V_101 , V_102 ) ;
V_41 = F_88 ( V_59 ) ;
F_89 ( V_95 , & V_101 ) ;
F_90 ( F_91 ( V_59 ) ,
F_91 ( V_68 - V_100 ) ) ;
return V_41 ;
}
long F_92 ( struct V_103 * V_103 , int V_92 , long V_59 )
{
long V_41 ;
unsigned long V_100 = V_68 ;
F_86 ( V_101 ) ;
T_7 * V_95 = & V_96 [ V_92 ] ;
if ( F_93 ( & V_99 [ V_92 ] ) == 0 ||
! F_41 ( V_104 , & V_103 -> V_105 ) ) {
F_94 () ;
V_41 = V_59 - ( V_68 - V_100 ) ;
if ( V_41 < 0 )
V_41 = 0 ;
goto V_106;
}
F_87 ( V_95 , & V_101 , V_102 ) ;
V_41 = F_88 ( V_59 ) ;
F_89 ( V_95 , & V_101 ) ;
V_106:
F_95 ( F_91 ( V_59 ) ,
F_91 ( V_68 - V_100 ) ) ;
return V_41 ;
}
int F_96 ( struct V_107 * V_108 , int V_109 ,
void T_8 * V_110 , T_3 * V_111 , T_9 * V_112 )
{
char V_113 [] = L_21 ;
if ( * V_112 || * V_111 < sizeof( V_113 ) ) {
* V_111 = 0 ;
return 0 ;
}
if ( F_97 ( V_110 , V_113 , sizeof( V_113 ) ) )
return - V_114 ;
F_98 ( V_115 L_22 ,
V_108 -> V_116 ) ;
* V_111 = 2 ;
* V_112 += * V_111 ;
return 2 ;
}
