static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_5 == 0 )
return;
F_2 ( L_1 , V_4 -> V_6 ) ;
V_4 -> V_5 = 0 ;
F_3 ( & V_4 -> V_7 . V_8 . V_9 ) ;
if ( F_4 ( & V_2 -> V_9 . V_10 ) )
F_5 ( & V_2 -> V_9 . V_11 ) ;
}
static void
F_6 ( struct V_1 * V_2 , unsigned long V_12 )
{
V_2 -> V_9 . V_12 = V_12 ;
F_7 ( & V_2 -> V_9 . V_11 , V_12 ) ;
}
static void
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_4 -> V_5 )
return;
F_2 ( L_2 ,
V_4 -> V_6 , V_4 -> V_5 * 1000 / V_13 ) ;
V_4 -> V_7 . V_8 . V_12 = V_14 + V_4 -> V_5 ;
if ( F_4 ( & V_2 -> V_9 . V_10 ) || F_9 ( V_4 -> V_7 . V_8 . V_12 , V_2 -> V_9 . V_12 ) )
F_6 ( V_2 , V_4 -> V_7 . V_8 . V_12 ) ;
F_10 ( & V_4 -> V_7 . V_8 . V_9 , & V_2 -> V_9 . V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_15 )
{
struct V_16 * V_17 ;
struct V_3 * V_18 ;
F_12 ( & V_4 -> V_7 . V_8 . V_19 ) ;
V_17 = & V_2 -> V_20 [ V_15 ] ;
if ( F_13 ( V_15 > V_2 -> V_21 ) )
V_17 = & V_2 -> V_20 [ V_2 -> V_21 ] ;
F_14 (t, q, u.tk_wait.list) {
if ( V_18 -> V_22 == V_4 -> V_22 ) {
F_15 ( & V_4 -> V_7 . V_8 . V_10 , & V_18 -> V_7 . V_8 . V_19 ) ;
return;
}
}
F_15 ( & V_4 -> V_7 . V_8 . V_10 , V_17 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_15 )
{
F_17 ( F_18 ( V_4 ) ) ;
if ( F_19 ( V_2 ) )
F_11 ( V_2 , V_4 , V_15 ) ;
else if ( F_20 ( V_4 ) )
F_10 ( & V_4 -> V_7 . V_8 . V_10 , & V_2 -> V_20 [ 0 ] ) ;
else
F_15 ( & V_4 -> V_7 . V_8 . V_10 , & V_2 -> V_20 [ 0 ] ) ;
V_4 -> V_23 = V_2 ;
V_2 -> V_24 ++ ;
F_21 ( V_4 ) ;
F_2 ( L_3 ,
V_4 -> V_6 , V_2 , F_22 ( V_2 ) ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_3 * V_18 ;
if ( ! F_4 ( & V_4 -> V_7 . V_8 . V_19 ) ) {
V_18 = F_24 ( V_4 -> V_7 . V_8 . V_19 . V_25 , struct V_3 , V_7 . V_8 . V_10 ) ;
F_25 ( & V_18 -> V_7 . V_8 . V_10 , & V_4 -> V_7 . V_8 . V_10 ) ;
F_26 ( & V_4 -> V_7 . V_8 . V_19 , & V_18 -> V_7 . V_8 . V_19 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( F_19 ( V_2 ) )
F_23 ( V_4 ) ;
F_3 ( & V_4 -> V_7 . V_8 . V_10 ) ;
V_2 -> V_24 -- ;
F_2 ( L_4 ,
V_4 -> V_6 , V_2 , F_22 ( V_2 ) ) ;
}
static inline void F_28 ( struct V_1 * V_2 , int V_26 )
{
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = 1 << ( V_26 * 2 ) ;
}
static inline void F_29 ( struct V_1 * V_2 , T_1 V_28 )
{
V_2 -> V_29 = V_28 ;
V_2 -> V_30 = V_31 ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
F_28 ( V_2 , V_2 -> V_21 ) ;
F_29 ( V_2 , 0 ) ;
}
static void F_31 ( struct V_1 * V_2 , const char * V_32 , unsigned char V_33 )
{
int V_34 ;
F_32 ( & V_2 -> V_35 ) ;
for ( V_34 = 0 ; V_34 < F_33 ( V_2 -> V_20 ) ; V_34 ++ )
F_12 ( & V_2 -> V_20 [ V_34 ] ) ;
V_2 -> V_21 = V_33 - 1 ;
F_30 ( V_2 ) ;
V_2 -> V_24 = 0 ;
F_34 ( & V_2 -> V_9 . V_11 , V_36 , ( unsigned long ) V_2 ) ;
F_12 ( & V_2 -> V_9 . V_10 ) ;
#ifdef F_35
V_2 -> V_37 = V_32 ;
#endif
}
void F_36 ( struct V_1 * V_2 , const char * V_32 )
{
F_31 ( V_2 , V_32 , V_38 ) ;
}
void F_37 ( struct V_1 * V_2 , const char * V_32 )
{
F_31 ( V_2 , V_32 , 1 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_9 . V_11 ) ;
}
static int F_40 ( void * V_39 )
{
if ( F_41 ( V_40 ) )
return - V_41 ;
F_42 () ;
return 0 ;
}
static void F_43 ( struct V_3 * V_4 )
{
static T_2 V_42 ;
V_4 -> V_6 = F_44 ( & V_42 ) ;
}
static inline void F_43 ( struct V_3 * V_4 )
{
}
static void F_45 ( struct V_3 * V_4 )
{
F_43 ( V_4 ) ;
F_46 ( V_43 , & V_4 -> V_44 ) ;
}
static int F_47 ( struct V_3 * V_4 )
{
void * V_45 = & V_4 -> V_44 ;
T_3 * V_46 = F_48 ( V_45 , V_43 ) ;
struct V_47 V_48 = F_49 ( V_45 , V_43 ) ;
unsigned long V_49 ;
int V_50 ;
F_50 ( & V_46 -> V_35 , V_49 ) ;
F_51 ( V_43 , & V_4 -> V_44 ) ;
V_50 = F_52 ( & V_4 -> V_51 ) ;
if ( F_53 ( V_46 ) )
F_54 ( V_46 , V_52 , & V_48 ) ;
F_55 ( & V_46 -> V_35 , V_49 ) ;
return V_50 ;
}
int F_56 ( struct V_3 * V_4 , int (* F_57)( void * ) )
{
if ( F_57 == NULL )
F_57 = F_40 ;
return F_58 ( & V_4 -> V_44 , V_43 ,
F_57 , V_53 ) ;
}
static void F_59 ( struct V_3 * V_4 )
{
F_60 ( V_4 ) ;
if ( F_61 ( V_4 ) )
return;
if ( F_62 ( V_4 ) ) {
F_63 ( & V_4 -> V_7 . V_54 , V_55 ) ;
F_64 ( V_56 , & V_4 -> V_7 . V_54 ) ;
} else
F_65 ( & V_4 -> V_44 , V_57 ) ;
}
static void F_66 ( struct V_1 * V_17 ,
struct V_3 * V_4 ,
T_4 F_57 ,
unsigned char V_15 )
{
F_2 ( L_5 ,
V_4 -> V_6 , F_22 ( V_17 ) , V_14 ) ;
F_16 ( V_17 , V_4 , V_15 ) ;
F_17 ( V_4 -> V_58 != NULL ) ;
V_4 -> V_58 = F_57 ;
F_8 ( V_17 , V_4 ) ;
}
void F_67 ( struct V_1 * V_17 , struct V_3 * V_4 ,
T_4 F_57 )
{
F_17 ( ! F_68 ( V_4 ) ) ;
F_69 ( & V_17 -> V_35 ) ;
F_66 ( V_17 , V_4 , F_57 , V_4 -> V_59 ) ;
F_70 ( & V_17 -> V_35 ) ;
}
void F_71 ( struct V_1 * V_17 , struct V_3 * V_4 ,
T_4 F_57 , int V_26 )
{
F_17 ( ! F_68 ( V_4 ) ) ;
F_69 ( & V_17 -> V_35 ) ;
F_66 ( V_17 , V_4 , F_57 , V_26 - V_60 ) ;
F_70 ( & V_17 -> V_35 ) ;
}
static void F_72 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_6 ,
V_4 -> V_6 , V_14 ) ;
if ( ! F_68 ( V_4 ) ) {
F_73 ( V_61 L_7 , V_4 ) ;
return;
}
F_27 ( V_2 , V_4 ) ;
F_59 ( V_4 ) ;
F_2 ( L_8 ) ;
}
static void F_74 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_18 ( V_4 ) && V_4 -> V_23 == V_2 )
F_72 ( V_2 , V_4 ) ;
}
int F_75 ( struct V_1 * V_2 )
{
int V_62 ;
F_69 ( & V_2 -> V_35 ) ;
V_62 = V_2 -> V_24 ;
F_70 ( & V_2 -> V_35 ) ;
return V_62 == 0 ;
}
void F_76 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_69 ( & V_2 -> V_35 ) ;
F_74 ( V_2 , V_4 ) ;
F_70 ( & V_2 -> V_35 ) ;
}
static struct V_3 * F_77 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 ;
V_17 = & V_2 -> V_20 [ V_2 -> V_26 ] ;
if ( ! F_4 ( V_17 ) ) {
V_4 = F_24 ( V_17 -> V_25 , struct V_3 , V_7 . V_8 . V_10 ) ;
if ( V_2 -> V_29 == V_4 -> V_22 ) {
if ( -- V_2 -> V_30 )
goto V_63;
F_78 ( & V_4 -> V_7 . V_8 . V_10 , V_17 ) ;
}
if ( -- V_2 -> V_27 )
goto V_64;
}
do {
if ( V_17 == & V_2 -> V_20 [ 0 ] )
V_17 = & V_2 -> V_20 [ V_2 -> V_21 ] ;
else
V_17 = V_17 - 1 ;
if ( ! F_4 ( V_17 ) ) {
V_4 = F_24 ( V_17 -> V_25 , struct V_3 , V_7 . V_8 . V_10 ) ;
goto V_65;
}
} while ( V_17 != & V_2 -> V_20 [ V_2 -> V_26 ] );
F_30 ( V_2 ) ;
return NULL ;
V_65:
F_28 ( V_2 , ( unsigned int ) ( V_17 - & V_2 -> V_20 [ 0 ] ) ) ;
V_64:
F_29 ( V_2 , V_4 -> V_22 ) ;
V_63:
F_74 ( V_2 , V_4 ) ;
return V_4 ;
}
struct V_3 * F_79 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
F_2 ( L_9 ,
V_2 , F_22 ( V_2 ) ) ;
F_69 ( & V_2 -> V_35 ) ;
if ( F_19 ( V_2 ) )
V_4 = F_77 ( V_2 ) ;
else {
F_80 (task, &queue->tasks[0])
F_74 ( V_2 , V_4 ) ;
}
F_70 ( & V_2 -> V_35 ) ;
return V_4 ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_25 ;
struct V_16 * V_66 ;
F_69 ( & V_2 -> V_35 ) ;
V_66 = & V_2 -> V_20 [ V_2 -> V_21 ] ;
for (; ; ) {
F_82 (task, next, head, u.tk_wait.list)
F_74 ( V_2 , V_4 ) ;
if ( V_66 == & V_2 -> V_20 [ 0 ] )
break;
V_66 -- ;
}
F_70 ( & V_2 -> V_35 ) ;
}
void F_83 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 , * V_25 ;
struct V_16 * V_66 ;
F_69 ( & V_2 -> V_35 ) ;
V_66 = & V_2 -> V_20 [ V_2 -> V_21 ] ;
for (; ; ) {
F_82 (task, next, head, u.tk_wait.list) {
V_4 -> V_68 = V_67 ;
F_74 ( V_2 , V_4 ) ;
}
if ( V_66 == & V_2 -> V_20 [ 0 ] )
break;
V_66 -- ;
}
F_70 ( & V_2 -> V_35 ) ;
}
static void V_36 ( unsigned long V_69 )
{
struct V_1 * V_2 = (struct V_1 * ) V_69 ;
struct V_3 * V_4 , * V_70 ;
unsigned long V_12 , V_71 , V_72 ;
F_84 ( & V_2 -> V_35 ) ;
V_12 = V_71 = V_14 ;
F_82 (task, n, &queue->timer_list.list, u.tk_wait.timer_list) {
V_72 = V_4 -> V_7 . V_8 . V_12 ;
if ( F_85 ( V_71 , V_72 ) ) {
F_2 ( L_10 , V_4 -> V_6 ) ;
V_4 -> V_68 = - V_73 ;
F_74 ( V_2 , V_4 ) ;
continue;
}
if ( V_12 == V_71 || F_86 ( V_12 , V_72 ) )
V_12 = V_72 ;
}
if ( ! F_4 ( & V_2 -> V_9 . V_10 ) )
F_6 ( V_2 , V_12 ) ;
F_87 ( & V_2 -> V_35 ) ;
}
static void F_88 ( struct V_3 * V_4 )
{
V_4 -> V_68 = 0 ;
}
void F_89 ( struct V_3 * V_4 , unsigned long V_74 )
{
V_4 -> V_5 = V_74 ;
F_67 ( & V_75 , V_4 , F_88 ) ;
}
void F_90 ( struct V_3 * V_4 )
{
V_4 -> V_76 -> V_77 ( V_4 , V_4 -> V_78 ) ;
}
static void
F_91 ( struct V_3 * V_4 )
{
V_4 -> V_79 = 2 ;
V_4 -> V_80 = 2 ;
V_4 -> V_81 = 2 ;
V_4 -> V_82 = F_92 () ;
}
static void
F_93 ( struct V_3 * V_4 )
{
V_4 -> V_83 = 0 ;
V_4 -> V_84 &= ~ ( V_85 | V_86 | V_87 ) ;
F_91 ( V_4 ) ;
}
void F_94 ( struct V_3 * V_4 )
{
V_4 -> V_88 = NULL ;
if ( V_4 -> V_76 -> V_89 != NULL ) {
V_4 -> V_76 -> V_89 ( V_4 , V_4 -> V_78 ) ;
if ( V_4 -> V_88 != NULL ) {
F_95 ( F_96 ( V_4 ) ) ;
F_97 ( V_4 ) ;
F_93 ( V_4 ) ;
}
}
}
void F_98 ( struct V_3 * V_4 , int V_67 )
{
V_4 -> V_68 = V_67 ;
V_4 -> V_88 = F_94 ;
if ( F_18 ( V_4 ) )
F_76 ( V_4 -> V_23 , V_4 ) ;
}
void F_99 ( const struct V_90 * V_91 , void * V_92 )
{
if ( V_91 -> V_93 != NULL )
V_91 -> V_93 ( V_92 ) ;
}
static void F_100 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_94 = F_62 ( V_4 ) ;
int V_67 = 0 ;
F_2 ( L_11 ,
V_4 -> V_6 , V_4 -> V_84 ) ;
F_17 ( F_18 ( V_4 ) ) ;
for (; ; ) {
void (* F_101)( struct V_3 * );
F_101 = V_4 -> V_58 ;
V_4 -> V_58 = NULL ;
if ( F_101 == NULL ) {
F_101 = V_4 -> V_88 ;
if ( F_101 == NULL )
break;
}
F_101 ( V_4 ) ;
if ( ! F_18 ( V_4 ) )
continue;
V_2 = V_4 -> V_23 ;
F_69 ( & V_2 -> V_35 ) ;
if ( ! F_18 ( V_4 ) ) {
F_70 ( & V_2 -> V_35 ) ;
continue;
}
F_102 ( V_4 ) ;
F_70 ( & V_2 -> V_35 ) ;
if ( V_94 )
return;
F_2 ( L_12 , V_4 -> V_6 ) ;
V_67 = F_58 ( & V_4 -> V_44 ,
V_57 , F_40 ,
V_53 ) ;
if ( V_67 == - V_41 ) {
F_2 ( L_13 , V_4 -> V_6 ) ;
V_4 -> V_84 |= V_86 ;
F_98 ( V_4 , - V_41 ) ;
}
F_103 ( V_4 ) ;
F_2 ( L_14 , V_4 -> V_6 ) ;
}
F_2 ( L_15 , V_4 -> V_6 , V_67 ,
V_4 -> V_68 ) ;
F_104 ( V_4 ) ;
}
void F_105 ( struct V_3 * V_4 )
{
F_45 ( V_4 ) ;
F_59 ( V_4 ) ;
if ( ! F_62 ( V_4 ) )
F_100 ( V_4 ) ;
}
static void V_55 ( struct V_95 * V_96 )
{
F_100 ( F_106 ( V_96 , struct V_3 , V_7 . V_54 ) ) ;
}
void * F_107 ( struct V_3 * V_4 , T_5 V_97 )
{
struct V_98 * V_99 ;
T_6 V_100 = F_20 ( V_4 ) ? V_101 : V_102 ;
V_97 += sizeof( struct V_98 ) ;
if ( V_97 <= V_103 )
V_99 = F_108 ( V_104 , V_100 ) ;
else
V_99 = F_109 ( V_97 , V_100 ) ;
if ( ! V_99 )
return NULL ;
V_99 -> V_105 = V_97 ;
F_2 ( L_16 ,
V_4 -> V_6 , V_97 , V_99 ) ;
return & V_99 -> V_106 ;
}
void F_110 ( void * V_107 )
{
T_5 V_97 ;
struct V_98 * V_99 ;
if ( ! V_107 )
return;
V_99 = F_106 ( V_107 , struct V_98 , V_106 ) ;
V_97 = V_99 -> V_105 ;
F_2 ( L_17 ,
V_97 , V_99 ) ;
if ( V_97 <= V_103 )
F_111 ( V_99 , V_104 ) ;
else
F_112 ( V_99 ) ;
}
static void F_113 ( struct V_3 * V_4 , const struct V_108 * V_109 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_114 ( & V_4 -> V_51 , 1 ) ;
V_4 -> V_84 = V_109 -> V_49 ;
V_4 -> V_76 = V_109 -> V_110 ;
V_4 -> V_78 = V_109 -> V_111 ;
F_12 ( & V_4 -> V_112 ) ;
V_4 -> V_59 = V_109 -> V_26 - V_60 ;
V_4 -> V_22 = V_40 -> V_113 ;
V_4 -> V_114 = V_109 -> V_115 ;
if ( V_4 -> V_76 -> V_77 != NULL )
V_4 -> V_88 = F_90 ;
F_91 ( V_4 ) ;
F_2 ( L_18 ,
F_115 ( V_40 ) ) ;
}
static struct V_3 *
F_116 ( void )
{
return (struct V_3 * ) F_108 ( V_116 , V_117 ) ;
}
struct V_3 * F_117 ( const struct V_108 * V_118 )
{
struct V_3 * V_4 = V_118 -> V_4 ;
unsigned short V_49 = 0 ;
if ( V_4 == NULL ) {
V_4 = F_116 () ;
if ( V_4 == NULL ) {
F_99 ( V_118 -> V_110 ,
V_118 -> V_111 ) ;
return F_118 ( - V_119 ) ;
}
V_49 = V_120 ;
}
F_113 ( V_4 , V_118 ) ;
V_4 -> V_84 |= V_49 ;
F_2 ( L_19 , V_4 ) ;
return V_4 ;
}
static void F_119 ( struct V_3 * V_4 )
{
const struct V_90 * V_76 = V_4 -> V_76 ;
void * V_92 = V_4 -> V_78 ;
if ( V_4 -> V_84 & V_120 ) {
F_2 ( L_20 , V_4 -> V_6 ) ;
F_111 ( V_4 , V_116 ) ;
}
F_99 ( V_76 , V_92 ) ;
}
static void F_120 ( struct V_95 * V_96 )
{
F_119 ( F_106 ( V_96 , struct V_3 , V_7 . V_54 ) ) ;
}
static void F_121 ( struct V_3 * V_4 )
{
if ( V_4 -> V_121 )
F_97 ( V_4 ) ;
if ( V_4 -> V_122 . V_123 ) {
F_122 ( V_4 -> V_122 . V_123 ) ;
V_4 -> V_122 . V_123 = NULL ;
}
F_123 ( V_4 ) ;
}
static void F_124 ( struct V_3 * V_4 ,
struct V_124 * V_17 )
{
if ( V_17 != NULL ) {
F_63 ( & V_4 -> V_7 . V_54 , F_120 ) ;
F_64 ( V_17 , & V_4 -> V_7 . V_54 ) ;
} else
F_119 ( V_4 ) ;
}
static void F_125 ( struct V_3 * V_4 , struct V_124 * V_17 )
{
if ( F_52 ( & V_4 -> V_51 ) ) {
F_121 ( V_4 ) ;
F_124 ( V_4 , V_17 ) ;
}
}
void F_126 ( struct V_3 * V_4 )
{
F_125 ( V_4 , NULL ) ;
}
void F_127 ( struct V_3 * V_4 )
{
F_125 ( V_4 , V_4 -> V_114 ) ;
}
static void F_104 ( struct V_3 * V_4 )
{
F_2 ( L_21 , V_4 -> V_6 ) ;
F_17 ( F_18 ( V_4 ) ) ;
F_121 ( V_4 ) ;
if ( F_128 ( & V_4 -> V_51 ) != 1 + ! F_62 ( V_4 ) ) {
if ( ! F_47 ( V_4 ) )
return;
} else {
if ( ! F_52 ( & V_4 -> V_51 ) )
return;
}
F_124 ( V_4 , V_4 -> V_114 ) ;
}
int F_129 ( void )
{
return F_130 ( V_125 ) ? 0 : - V_126 ;
}
void F_131 ( void )
{
F_132 ( V_125 ) ;
}
static int F_133 ( void )
{
struct V_124 * V_46 ;
F_2 ( L_22 ) ;
V_46 = F_134 ( L_23 , V_127 , 0 ) ;
V_56 = V_46 ;
return V_56 != NULL ;
}
static void F_135 ( void )
{
struct V_124 * V_46 = NULL ;
if ( V_56 == NULL )
return;
F_2 ( L_24 ) ;
V_46 = V_56 ;
V_56 = NULL ;
F_136 ( V_46 ) ;
}
void
F_137 ( void )
{
F_135 () ;
if ( V_104 )
F_138 ( V_104 ) ;
if ( V_116 )
F_138 ( V_116 ) ;
if ( V_128 )
F_139 ( V_128 ) ;
if ( V_129 )
F_139 ( V_129 ) ;
F_38 ( & V_75 ) ;
}
int
F_140 ( void )
{
F_37 ( & V_75 , L_25 ) ;
if ( ! F_133 () )
goto V_130;
V_128 = F_141 ( L_26 ,
sizeof( struct V_3 ) ,
0 , V_131 ,
NULL ) ;
if ( ! V_128 )
goto V_130;
V_129 = F_141 ( L_27 ,
V_103 ,
0 , V_131 ,
NULL ) ;
if ( ! V_129 )
goto V_130;
V_116 = F_142 ( V_132 ,
V_128 ) ;
if ( ! V_116 )
goto V_130;
V_104 = F_142 ( V_133 ,
V_129 ) ;
if ( ! V_104 )
goto V_130;
return 0 ;
V_130:
F_137 () ;
return - V_119 ;
}
