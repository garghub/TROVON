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
F_35 ( V_2 , V_32 ) ;
}
void F_36 ( struct V_1 * V_2 , const char * V_32 )
{
F_31 ( V_2 , V_32 , V_37 ) ;
}
void F_37 ( struct V_1 * V_2 , const char * V_32 )
{
F_31 ( V_2 , V_32 , 1 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_9 . V_11 ) ;
}
static int F_40 ( void * V_38 )
{
if ( F_41 ( V_39 ) )
return - V_40 ;
F_42 () ;
return 0 ;
}
static void F_43 ( struct V_3 * V_4 )
{
static T_2 V_41 ;
V_4 -> V_6 = F_44 ( & V_41 ) ;
}
static inline void F_43 ( struct V_3 * V_4 )
{
}
static void F_45 ( struct V_3 * V_4 )
{
F_46 ( V_4 -> V_42 , V_4 , NULL ) ;
F_43 ( V_4 ) ;
F_47 ( V_43 , & V_4 -> V_44 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
void * V_45 = & V_4 -> V_44 ;
T_3 * V_46 = F_49 ( V_45 , V_43 ) ;
struct V_47 V_48 = F_50 ( V_45 , V_43 ) ;
unsigned long V_49 ;
int V_50 ;
F_51 ( V_4 -> V_42 , V_4 , NULL ) ;
F_52 ( & V_46 -> V_35 , V_49 ) ;
F_53 ( V_43 , & V_4 -> V_44 ) ;
V_50 = F_54 ( & V_4 -> V_51 ) ;
if ( F_55 ( V_46 ) )
F_56 ( V_46 , V_52 , & V_48 ) ;
F_57 ( & V_46 -> V_35 , V_49 ) ;
return V_50 ;
}
int F_58 ( struct V_3 * V_4 , int (* F_59)( void * ) )
{
if ( F_59 == NULL )
F_59 = F_40 ;
return F_60 ( & V_4 -> V_44 , V_43 ,
F_59 , V_53 ) ;
}
static void F_61 ( struct V_3 * V_4 )
{
F_62 ( V_4 ) ;
if ( F_63 ( V_4 ) )
return;
if ( F_64 ( V_4 ) ) {
F_65 ( & V_4 -> V_7 . V_54 , V_55 ) ;
F_66 ( V_56 , & V_4 -> V_7 . V_54 ) ;
} else
F_67 ( & V_4 -> V_44 , V_57 ) ;
}
static void F_68 ( struct V_1 * V_17 ,
struct V_3 * V_4 ,
T_4 F_59 ,
unsigned char V_15 )
{
F_2 ( L_5 ,
V_4 -> V_6 , F_22 ( V_17 ) , V_14 ) ;
F_69 ( V_4 -> V_42 , V_4 , V_17 ) ;
F_16 ( V_17 , V_4 , V_15 ) ;
F_17 ( V_4 -> V_58 != NULL ) ;
V_4 -> V_58 = F_59 ;
F_8 ( V_17 , V_4 ) ;
}
void F_70 ( struct V_1 * V_17 , struct V_3 * V_4 ,
T_4 F_59 )
{
F_17 ( ! F_71 ( V_4 ) ) ;
F_72 ( & V_17 -> V_35 ) ;
F_68 ( V_17 , V_4 , F_59 , V_4 -> V_59 ) ;
F_73 ( & V_17 -> V_35 ) ;
}
void F_74 ( struct V_1 * V_17 , struct V_3 * V_4 ,
T_4 F_59 , int V_26 )
{
F_17 ( ! F_71 ( V_4 ) ) ;
F_72 ( & V_17 -> V_35 ) ;
F_68 ( V_17 , V_4 , F_59 , V_26 - V_60 ) ;
F_73 ( & V_17 -> V_35 ) ;
}
static void F_75 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_6 ,
V_4 -> V_6 , V_14 ) ;
if ( ! F_71 ( V_4 ) ) {
F_76 ( V_61 L_7 , V_4 ) ;
return;
}
F_77 ( V_4 -> V_42 , V_4 , V_2 ) ;
F_27 ( V_2 , V_4 ) ;
F_61 ( V_4 ) ;
F_2 ( L_8 ) ;
}
static void F_78 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_18 ( V_4 ) && V_4 -> V_23 == V_2 )
F_75 ( V_2 , V_4 ) ;
}
int F_79 ( struct V_1 * V_2 )
{
int V_62 ;
F_72 ( & V_2 -> V_35 ) ;
V_62 = V_2 -> V_24 ;
F_73 ( & V_2 -> V_35 ) ;
return V_62 == 0 ;
}
void F_80 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_72 ( & V_2 -> V_35 ) ;
F_78 ( V_2 , V_4 ) ;
F_73 ( & V_2 -> V_35 ) ;
}
static struct V_3 * F_81 ( struct V_1 * V_2 )
{
struct V_16 * V_17 ;
struct V_3 * V_4 ;
V_17 = & V_2 -> V_20 [ V_2 -> V_26 ] ;
if ( ! F_4 ( V_17 ) ) {
V_4 = F_24 ( V_17 -> V_25 , struct V_3 , V_7 . V_8 . V_10 ) ;
if ( V_2 -> V_29 == V_4 -> V_22 ) {
if ( -- V_2 -> V_30 )
goto V_63;
F_82 ( & V_4 -> V_7 . V_8 . V_10 , V_17 ) ;
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
return V_4 ;
}
static struct V_3 * F_83 ( struct V_1 * V_2 )
{
if ( F_19 ( V_2 ) )
return F_81 ( V_2 ) ;
if ( ! F_4 ( & V_2 -> V_20 [ 0 ] ) )
return F_84 ( & V_2 -> V_20 [ 0 ] , struct V_3 , V_7 . V_8 . V_10 ) ;
return NULL ;
}
struct V_3 * F_85 ( struct V_1 * V_2 ,
bool (* F_86)( struct V_3 * , void * ) , void * V_66 )
{
struct V_3 * V_4 = NULL ;
F_2 ( L_9 ,
V_2 , F_22 ( V_2 ) ) ;
F_72 ( & V_2 -> V_35 ) ;
V_4 = F_83 ( V_2 ) ;
if ( V_4 != NULL ) {
if ( F_86 ( V_4 , V_66 ) )
F_78 ( V_2 , V_4 ) ;
else
V_4 = NULL ;
}
F_73 ( & V_2 -> V_35 ) ;
return V_4 ;
}
static bool F_87 ( struct V_3 * V_4 , void * V_66 )
{
return true ;
}
struct V_3 * F_88 ( struct V_1 * V_2 )
{
return F_85 ( V_2 , F_87 , NULL ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_16 * V_67 ;
F_72 ( & V_2 -> V_35 ) ;
V_67 = & V_2 -> V_20 [ V_2 -> V_21 ] ;
for (; ; ) {
while ( ! F_4 ( V_67 ) ) {
struct V_3 * V_4 ;
V_4 = F_84 ( V_67 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
F_78 ( V_2 , V_4 ) ;
}
if ( V_67 == & V_2 -> V_20 [ 0 ] )
break;
V_67 -- ;
}
F_73 ( & V_2 -> V_35 ) ;
}
void F_90 ( struct V_1 * V_2 , int V_68 )
{
struct V_16 * V_67 ;
F_72 ( & V_2 -> V_35 ) ;
V_67 = & V_2 -> V_20 [ V_2 -> V_21 ] ;
for (; ; ) {
while ( ! F_4 ( V_67 ) ) {
struct V_3 * V_4 ;
V_4 = F_84 ( V_67 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
V_4 -> V_69 = V_68 ;
F_78 ( V_2 , V_4 ) ;
}
if ( V_67 == & V_2 -> V_20 [ 0 ] )
break;
V_67 -- ;
}
F_73 ( & V_2 -> V_35 ) ;
}
static void V_36 ( unsigned long V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
struct V_3 * V_4 , * V_71 ;
unsigned long V_12 , V_72 , V_73 ;
F_91 ( & V_2 -> V_35 ) ;
V_12 = V_72 = V_14 ;
F_92 (task, n, &queue->timer_list.list, u.tk_wait.timer_list) {
V_73 = V_4 -> V_7 . V_8 . V_12 ;
if ( F_93 ( V_72 , V_73 ) ) {
F_2 ( L_10 , V_4 -> V_6 ) ;
V_4 -> V_69 = - V_74 ;
F_78 ( V_2 , V_4 ) ;
continue;
}
if ( V_12 == V_72 || F_94 ( V_12 , V_73 ) )
V_12 = V_73 ;
}
if ( ! F_4 ( & V_2 -> V_9 . V_10 ) )
F_6 ( V_2 , V_12 ) ;
F_95 ( & V_2 -> V_35 ) ;
}
static void F_96 ( struct V_3 * V_4 )
{
V_4 -> V_69 = 0 ;
}
void F_97 ( struct V_3 * V_4 , unsigned long V_75 )
{
V_4 -> V_5 = V_75 ;
F_70 ( & V_76 , V_4 , F_96 ) ;
}
void F_98 ( struct V_3 * V_4 )
{
V_4 -> V_77 -> V_78 ( V_4 , V_4 -> V_79 ) ;
}
static void
F_99 ( struct V_3 * V_4 )
{
V_4 -> V_80 = 2 ;
V_4 -> V_81 = 2 ;
V_4 -> V_82 = 2 ;
V_4 -> V_83 = F_100 () ;
}
static void
F_101 ( struct V_3 * V_4 )
{
V_4 -> V_84 = 0 ;
V_4 -> V_85 &= ~ ( V_86 | V_87 | V_88 ) ;
F_99 ( V_4 ) ;
}
void F_102 ( struct V_3 * V_4 )
{
V_4 -> V_89 = NULL ;
if ( V_4 -> V_77 -> V_90 != NULL ) {
V_4 -> V_77 -> V_90 ( V_4 , V_4 -> V_79 ) ;
if ( V_4 -> V_89 != NULL ) {
F_103 ( F_104 ( V_4 ) ) ;
F_105 ( V_4 ) ;
F_101 ( V_4 ) ;
}
}
}
void F_106 ( struct V_3 * V_4 , int V_68 )
{
V_4 -> V_69 = V_68 ;
V_4 -> V_89 = F_102 ;
if ( F_18 ( V_4 ) )
F_80 ( V_4 -> V_23 , V_4 ) ;
}
void F_107 ( const struct V_91 * V_92 , void * V_93 )
{
if ( V_92 -> V_94 != NULL )
V_92 -> V_94 ( V_93 ) ;
}
static void F_108 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_95 = F_64 ( V_4 ) ;
int V_68 = 0 ;
F_2 ( L_11 ,
V_4 -> V_6 , V_4 -> V_85 ) ;
F_17 ( F_18 ( V_4 ) ) ;
for (; ; ) {
void (* F_109)( struct V_3 * );
F_109 = V_4 -> V_58 ;
V_4 -> V_58 = NULL ;
if ( F_109 == NULL ) {
F_109 = V_4 -> V_89 ;
if ( F_109 == NULL )
break;
}
F_110 ( V_4 -> V_42 , V_4 , V_4 -> V_89 ) ;
F_109 ( V_4 ) ;
if ( ! F_18 ( V_4 ) )
continue;
V_2 = V_4 -> V_23 ;
F_72 ( & V_2 -> V_35 ) ;
if ( ! F_18 ( V_4 ) ) {
F_73 ( & V_2 -> V_35 ) ;
continue;
}
F_111 ( V_4 ) ;
F_73 ( & V_2 -> V_35 ) ;
if ( V_95 )
return;
F_2 ( L_12 , V_4 -> V_6 ) ;
V_68 = F_60 ( & V_4 -> V_44 ,
V_57 , F_40 ,
V_53 ) ;
if ( V_68 == - V_40 ) {
F_2 ( L_13 , V_4 -> V_6 ) ;
V_4 -> V_85 |= V_87 ;
F_106 ( V_4 , - V_40 ) ;
}
F_112 ( V_4 ) ;
F_2 ( L_14 , V_4 -> V_6 ) ;
}
F_2 ( L_15 , V_4 -> V_6 , V_68 ,
V_4 -> V_69 ) ;
F_113 ( V_4 ) ;
}
void F_114 ( struct V_3 * V_4 )
{
F_45 ( V_4 ) ;
F_61 ( V_4 ) ;
if ( ! F_64 ( V_4 ) )
F_108 ( V_4 ) ;
}
static void V_55 ( struct V_96 * V_97 )
{
F_108 ( F_115 ( V_97 , struct V_3 , V_7 . V_54 ) ) ;
}
void * F_116 ( struct V_3 * V_4 , T_5 V_98 )
{
struct V_99 * V_100 ;
T_6 V_101 = F_20 ( V_4 ) ? V_102 : V_103 ;
V_98 += sizeof( struct V_99 ) ;
if ( V_98 <= V_104 )
V_100 = F_117 ( V_105 , V_101 ) ;
else
V_100 = F_118 ( V_98 , V_101 ) ;
if ( ! V_100 )
return NULL ;
V_100 -> V_106 = V_98 ;
F_2 ( L_16 ,
V_4 -> V_6 , V_98 , V_100 ) ;
return & V_100 -> V_66 ;
}
void F_119 ( void * V_107 )
{
T_5 V_98 ;
struct V_99 * V_100 ;
if ( ! V_107 )
return;
V_100 = F_115 ( V_107 , struct V_99 , V_66 ) ;
V_98 = V_100 -> V_106 ;
F_2 ( L_17 ,
V_98 , V_100 ) ;
if ( V_98 <= V_104 )
F_120 ( V_100 , V_105 ) ;
else
F_121 ( V_100 ) ;
}
static void F_122 ( struct V_3 * V_4 , const struct V_108 * V_109 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_123 ( & V_4 -> V_51 , 1 ) ;
V_4 -> V_85 = V_109 -> V_49 ;
V_4 -> V_77 = V_109 -> V_110 ;
V_4 -> V_79 = V_109 -> V_111 ;
F_12 ( & V_4 -> V_112 ) ;
V_4 -> V_59 = V_109 -> V_26 - V_60 ;
V_4 -> V_22 = V_39 -> V_113 ;
V_4 -> V_114 = V_109 -> V_115 ;
if ( V_4 -> V_77 -> V_78 != NULL )
V_4 -> V_89 = F_98 ;
F_99 ( V_4 ) ;
F_2 ( L_18 ,
F_124 ( V_39 ) ) ;
}
static struct V_3 *
F_125 ( void )
{
return (struct V_3 * ) F_117 ( V_116 , V_117 ) ;
}
struct V_3 * F_126 ( const struct V_108 * V_118 )
{
struct V_3 * V_4 = V_118 -> V_4 ;
unsigned short V_49 = 0 ;
if ( V_4 == NULL ) {
V_4 = F_125 () ;
if ( V_4 == NULL ) {
F_107 ( V_118 -> V_110 ,
V_118 -> V_111 ) ;
return F_127 ( - V_119 ) ;
}
V_49 = V_120 ;
}
F_122 ( V_4 , V_118 ) ;
V_4 -> V_85 |= V_49 ;
F_2 ( L_19 , V_4 ) ;
return V_4 ;
}
static void F_128 ( struct V_3 * V_4 )
{
const struct V_91 * V_77 = V_4 -> V_77 ;
void * V_93 = V_4 -> V_79 ;
if ( V_4 -> V_85 & V_120 ) {
F_2 ( L_20 , V_4 -> V_6 ) ;
F_120 ( V_4 , V_116 ) ;
}
F_107 ( V_77 , V_93 ) ;
}
static void F_129 ( struct V_96 * V_97 )
{
F_128 ( F_115 ( V_97 , struct V_3 , V_7 . V_54 ) ) ;
}
static void F_130 ( struct V_3 * V_4 )
{
if ( V_4 -> V_121 )
F_105 ( V_4 ) ;
if ( V_4 -> V_122 . V_123 ) {
F_131 ( V_4 -> V_122 . V_123 ) ;
V_4 -> V_122 . V_123 = NULL ;
}
F_132 ( V_4 ) ;
}
static void F_133 ( struct V_3 * V_4 ,
struct V_124 * V_17 )
{
if ( V_17 != NULL ) {
F_65 ( & V_4 -> V_7 . V_54 , F_129 ) ;
F_66 ( V_17 , & V_4 -> V_7 . V_54 ) ;
} else
F_128 ( V_4 ) ;
}
static void F_134 ( struct V_3 * V_4 , struct V_124 * V_17 )
{
if ( F_54 ( & V_4 -> V_51 ) ) {
F_130 ( V_4 ) ;
F_133 ( V_4 , V_17 ) ;
}
}
void F_135 ( struct V_3 * V_4 )
{
F_134 ( V_4 , NULL ) ;
}
void F_136 ( struct V_3 * V_4 )
{
F_134 ( V_4 , V_4 -> V_114 ) ;
}
static void F_113 ( struct V_3 * V_4 )
{
F_2 ( L_21 , V_4 -> V_6 ) ;
F_17 ( F_18 ( V_4 ) ) ;
F_130 ( V_4 ) ;
if ( F_137 ( & V_4 -> V_51 ) != 1 + ! F_64 ( V_4 ) ) {
if ( ! F_48 ( V_4 ) )
return;
} else {
if ( ! F_54 ( & V_4 -> V_51 ) )
return;
}
F_133 ( V_4 , V_4 -> V_114 ) ;
}
int F_138 ( void )
{
return F_139 ( V_125 ) ? 0 : - V_126 ;
}
void F_140 ( void )
{
F_141 ( V_125 ) ;
}
static int F_142 ( void )
{
struct V_124 * V_46 ;
F_2 ( L_22 ) ;
V_46 = F_143 ( L_23 , V_127 , 0 ) ;
V_56 = V_46 ;
return V_56 != NULL ;
}
static void F_144 ( void )
{
struct V_124 * V_46 = NULL ;
if ( V_56 == NULL )
return;
F_2 ( L_24 ) ;
V_46 = V_56 ;
V_56 = NULL ;
F_145 ( V_46 ) ;
}
void
F_146 ( void )
{
F_144 () ;
if ( V_105 )
F_147 ( V_105 ) ;
if ( V_116 )
F_147 ( V_116 ) ;
if ( V_128 )
F_148 ( V_128 ) ;
if ( V_129 )
F_148 ( V_129 ) ;
F_38 ( & V_76 ) ;
}
int
F_149 ( void )
{
F_37 ( & V_76 , L_25 ) ;
if ( ! F_142 () )
goto V_130;
V_128 = F_150 ( L_26 ,
sizeof( struct V_3 ) ,
0 , V_131 ,
NULL ) ;
if ( ! V_128 )
goto V_130;
V_129 = F_150 ( L_27 ,
V_104 ,
0 , V_131 ,
NULL ) ;
if ( ! V_129 )
goto V_130;
V_116 = F_151 ( V_132 ,
V_128 ) ;
if ( ! V_116 )
goto V_130;
V_105 = F_151 ( V_133 ,
V_129 ) ;
if ( ! V_105 )
goto V_130;
return 0 ;
V_130:
F_146 () ;
return - V_119 ;
}
