int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 ,
T_1 * V_4 , int V_5 ,
int * V_6 , T_2 V_7 ,
unsigned V_8 ,
struct V_9 * * V_10 )
{
return F_2 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_10 ) ;
}
int F_3 ( struct V_1 * V_2 ,
unsigned long V_3 ,
T_1 V_4 , int V_5 ,
T_2 V_7 , unsigned V_8 ,
struct V_9 * * V_10 )
{
return - V_11 ;
}
int F_4 ( struct V_1 * V_2 ,
int V_5 , struct V_9 * * V_10 )
{
return F_5 ( V_2 , V_5 , V_10 ) ;
}
static void F_6 ( struct V_12 * V_13 )
{
T_3 V_14 ;
struct V_12 V_15 , V_16 ;
struct V_17 * V_18 = V_19 ;
struct V_20 * V_21 = & ( V_18 -> V_22 ) ;
do {
V_14 = V_21 -> V_14 ;
F_7 () ;
V_15 . V_23 = ( ( V_24 ) V_21 -> V_25 << 32 ) | V_21 -> V_26 ;
V_15 . V_27 = V_21 -> V_28 ;
F_7 () ;
} while ( ( V_21 -> V_14 & 1 ) || ( V_14 != V_21 -> V_14 ) );
F_8 ( & V_16 ) ;
* V_13 = F_9 ( V_15 , V_16 ) ;
}
static int F_10 ( struct V_29 * V_30 ,
unsigned long V_31 , void * V_32 )
{
static struct V_12 V_33 ;
struct V_34 V_35 ;
struct V_12 V_15 , V_36 ;
struct V_37 * V_38 = V_32 ;
V_15 . V_23 = V_38 -> V_39 ;
V_15 . V_27 = ( long ) ( V_38 -> V_40 . V_41 >> V_38 -> V_40 . V_42 ) ;
V_36 = F_9 ( V_15 , V_38 -> V_43 ) ;
if ( ! V_31 && F_11 ( & V_15 , & V_33 ) < 0 )
return V_44 ;
V_35 . V_45 = V_46 ;
V_35 . V_47 . V_48 . V_49 = 0 ;
V_35 . V_47 . V_48 . V_50 = V_15 . V_23 ;
V_35 . V_47 . V_48 . V_51 = V_15 . V_27 ;
V_35 . V_47 . V_48 . V_36 = F_12 ( & V_36 ) ;
( void ) F_13 ( & V_35 ) ;
V_33 = V_15 ;
V_33 . V_23 += 11 * 60 ;
return V_44 ;
}
static int F_14 ( unsigned int V_52 )
{
struct V_53 V_54 ;
struct V_55 * V_56 ;
int V_57 ;
if ( F_15 ( V_58 , V_52 ) != NULL )
goto V_59;
F_16 ( L_1 , V_52 ) ;
V_56 = F_17 ( V_60 , V_52 ) ;
V_54 . V_61 = F_18 ( V_56 ) ;
V_54 . V_62 = F_19 ( V_56 ) ;
V_57 = F_20 ( V_63 , F_21 ( V_52 ) ,
& V_54 ) ;
F_22 ( V_57 ) ;
F_15 ( V_58 , V_52 ) = V_56 ;
F_23 ( V_52 ) ;
V_59:
F_24 ( V_64 , 0 ) ;
return 0 ;
}
static int F_25 ( unsigned int V_52 )
{
F_26 ( V_64 ) ;
return 0 ;
}
static void F_27 ( enum V_65 V_65 , const char * V_45 )
{
struct V_66 V_67 = { . V_68 = V_69 } ;
int V_70 ;
V_70 = F_28 ( V_71 , & V_67 ) ;
F_22 ( V_70 ) ;
}
static void F_29 ( void )
{
struct V_66 V_67 = { . V_68 = V_72 } ;
int V_70 ;
V_70 = F_28 ( V_71 , & V_67 ) ;
F_22 ( V_70 ) ;
}
static T_4 F_30 ( int V_73 , void * V_74 )
{
F_31 () ;
return V_75 ;
}
static int T_5 F_32 ( unsigned long V_76 , const char * V_77 ,
int V_78 , void * V_79 )
{
const void * V_18 = NULL ;
int V_80 ;
if ( V_78 != 1 || strcmp ( V_77 , L_2 ) != 0 )
return 0 ;
if ( F_33 ( V_76 , V_81 . V_82 ) )
V_81 . V_83 = true ;
V_18 = F_34 ( V_76 , L_3 , & V_80 ) ;
if ( strlen ( V_81 . V_84 ) + 3 < V_80 &&
! strncmp ( V_81 . V_84 , V_18 , strlen ( V_81 . V_84 ) ) )
V_81 . V_14 = V_18 + strlen ( V_81 . V_84 ) ;
if ( F_35 ( V_85 ) ) {
if ( ( F_36 ( V_76 , L_4 ) > 0 ) &&
! F_37 () )
F_38 ( V_86 , & V_87 . V_88 ) ;
}
return 0 ;
}
void T_5 F_39 ( void )
{
F_40 ( F_32 , NULL ) ;
if ( ! V_81 . V_83 ) {
F_41 ( L_5 ) ;
return;
}
if ( V_81 . V_14 == NULL ) {
F_41 ( L_6 ) ;
return;
}
F_16 ( L_7 , V_81 . V_14 ) ;
V_89 = V_90 ;
F_42 () ;
if ( F_43 ( V_91 ) )
V_92 -> V_88 |= V_93 | V_94 ;
else
V_92 -> V_88 &= ~ ( V_93 | V_94 ) ;
if ( ! V_95 && ! F_44 () )
F_45 ( L_8 , 0 , NULL ) ;
}
static void T_5 F_46 ( void )
{
#ifdef F_47
struct V_96 V_97 ;
int V_98 , V_99 , V_100 ;
V_97 . V_8 = V_101 ;
V_97 . V_102 = V_103 ;
if ( F_48 ( V_104 , & V_97 )
|| ( V_97 . V_105 >> 56 ) != V_106 ) {
V_64 = 0 ;
return;
}
V_98 = V_97 . V_105 & 0xff ;
V_99 = ( ( V_97 . V_105 >> 8 ) & 0x1 ) ? V_107
: V_108 ;
V_100 = ( ( V_97 . V_105 >> 8 ) & 0x2 ) ? V_109
: V_110 ;
V_64 = F_49 ( NULL , V_98 , V_99 , V_100 ) ;
#endif
}
static void T_5 F_50 ( void )
{
struct V_111 * V_112 ;
V_112 = F_51 ( NULL , NULL , L_9 ) ;
if ( ! V_112 ) {
F_52 ( L_10 ) ;
return;
}
V_64 = F_53 ( V_112 , 0 ) ;
}
static int T_5 F_54 ( void )
{
struct V_113 V_114 ;
struct V_17 * V_115 = NULL ;
int V_52 ;
if ( ! F_55 () )
return 0 ;
if ( ! V_116 )
F_46 () ;
else
F_50 () ;
if ( ! V_64 ) {
F_52 ( L_11 ) ;
return - V_117 ;
}
if ( F_56 ( V_86 ) )
F_57 () ;
V_115 = (struct V_17 * ) F_58 ( V_118 ) ;
if ( ! V_115 ) {
F_52 ( L_12 ) ;
return - V_119 ;
}
V_114 . V_8 = V_101 ;
V_114 . V_120 = 0 ;
V_114 . V_121 = V_122 ;
V_114 . V_123 = F_18 ( V_115 ) ;
if ( F_59 ( V_124 , & V_114 ) )
F_60 () ;
V_19 = (struct V_17 * ) V_115 ;
V_60 = F_61 ( struct V_55 ) ;
if ( V_60 == NULL )
return - V_119 ;
F_62 (cpu)
F_15 ( V_125 , V_52 ) = V_52 ;
V_126 . V_127 = F_63 () ;
if ( F_64 ( & V_126 . V_128 ,
& V_126 . V_129 ,
V_126 . V_127 ) ) {
F_65 ( V_60 ) ;
return - V_119 ;
}
F_66 () ;
if ( ! F_44 () )
F_67 ( NULL ) ;
F_68 () ;
F_69 () ;
F_70 () ;
if ( F_71 ( V_64 , F_30 ,
L_13 , & V_58 ) ) {
F_52 ( L_14 , V_64 ) ;
return - V_130 ;
}
F_72 () ;
if ( F_44 () )
F_73 ( & V_131 ) ;
return F_74 ( V_132 ,
L_15 , F_14 ,
F_25 ) ;
}
static int T_5 F_75 ( void )
{
if ( ! F_55 () )
return - V_117 ;
V_133 = F_29 ;
V_134 = F_27 ;
if ( ! F_44 () ) {
struct V_12 V_13 ;
F_6 ( & V_13 ) ;
F_76 ( & V_13 ) ;
}
return 0 ;
}
void F_77 ( void ) { }
void F_78 ( int V_135 ) { }
void F_79 ( void ) { }
void F_80 ( void ) { }
void F_81 ( void ) { }
