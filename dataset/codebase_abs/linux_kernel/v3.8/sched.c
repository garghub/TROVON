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
static void F_11 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = & V_2 -> V_17 [ V_2 -> V_18 ] ;
struct V_3 * V_4 ;
if ( ! F_4 ( V_16 ) ) {
V_4 = F_12 ( V_16 , struct V_3 , V_7 . V_8 . V_10 ) ;
if ( V_4 -> V_19 == V_2 -> V_20 )
F_13 ( & V_4 -> V_7 . V_8 . V_10 , V_16 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , int V_18 )
{
if ( V_2 -> V_18 != V_18 ) {
F_11 ( V_2 ) ;
V_2 -> V_18 = V_18 ;
}
}
static void F_15 ( struct V_1 * V_2 , T_1 V_21 )
{
V_2 -> V_20 = V_21 ;
V_2 -> V_22 = V_23 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_2 -> V_24 ) ;
F_15 ( V_2 , 0 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_25 )
{
struct V_15 * V_16 ;
struct V_3 * V_26 ;
F_18 ( & V_4 -> V_7 . V_8 . V_27 ) ;
if ( F_19 ( V_25 > V_2 -> V_24 ) )
V_25 = V_2 -> V_24 ;
if ( V_25 > V_2 -> V_18 )
F_14 ( V_2 , V_25 ) ;
V_16 = & V_2 -> V_17 [ V_25 ] ;
F_20 (t, q, u.tk_wait.list) {
if ( V_26 -> V_19 == V_4 -> V_19 ) {
F_21 ( & V_4 -> V_7 . V_8 . V_10 , & V_26 -> V_7 . V_8 . V_27 ) ;
return;
}
}
F_21 ( & V_4 -> V_7 . V_8 . V_10 , V_16 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_25 )
{
F_23 ( F_24 ( V_4 ) ) ;
if ( F_24 ( V_4 ) )
return;
if ( F_25 ( V_2 ) )
F_17 ( V_2 , V_4 , V_25 ) ;
else if ( F_26 ( V_4 ) )
F_10 ( & V_4 -> V_7 . V_8 . V_10 , & V_2 -> V_17 [ 0 ] ) ;
else
F_21 ( & V_4 -> V_7 . V_8 . V_10 , & V_2 -> V_17 [ 0 ] ) ;
V_4 -> V_28 = V_2 ;
V_2 -> V_29 ++ ;
F_27 ( V_4 ) ;
F_2 ( L_3 ,
V_4 -> V_6 , V_2 , F_28 ( V_2 ) ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
struct V_3 * V_26 ;
if ( ! F_4 ( & V_4 -> V_7 . V_8 . V_27 ) ) {
V_26 = F_30 ( V_4 -> V_7 . V_8 . V_27 . V_30 , struct V_3 , V_7 . V_8 . V_10 ) ;
F_31 ( & V_26 -> V_7 . V_8 . V_10 , & V_4 -> V_7 . V_8 . V_10 ) ;
F_32 ( & V_4 -> V_7 . V_8 . V_27 , & V_26 -> V_7 . V_8 . V_27 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( F_25 ( V_2 ) )
F_29 ( V_4 ) ;
F_3 ( & V_4 -> V_7 . V_8 . V_10 ) ;
V_2 -> V_29 -- ;
F_2 ( L_4 ,
V_4 -> V_6 , V_2 , F_28 ( V_2 ) ) ;
}
static void F_34 ( struct V_1 * V_2 , const char * V_31 , unsigned char V_32 )
{
int V_33 ;
F_35 ( & V_2 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < F_36 ( V_2 -> V_17 ) ; V_33 ++ )
F_18 ( & V_2 -> V_17 [ V_33 ] ) ;
V_2 -> V_24 = V_32 - 1 ;
F_16 ( V_2 ) ;
V_2 -> V_29 = 0 ;
F_37 ( & V_2 -> V_9 . V_11 , V_35 , ( unsigned long ) V_2 ) ;
F_18 ( & V_2 -> V_9 . V_10 ) ;
F_38 ( V_2 , V_31 ) ;
}
void F_39 ( struct V_1 * V_2 , const char * V_31 )
{
F_34 ( V_2 , V_31 , V_36 ) ;
}
void F_40 ( struct V_1 * V_2 , const char * V_31 )
{
F_34 ( V_2 , V_31 , 1 ) ;
}
void F_41 ( struct V_1 * V_2 )
{
F_42 ( & V_2 -> V_9 . V_11 ) ;
}
static int F_43 ( void * V_37 )
{
if ( F_44 ( V_38 ) )
return - V_39 ;
F_45 () ;
return 0 ;
}
static void F_46 ( struct V_3 * V_4 )
{
static T_2 V_40 ;
V_4 -> V_6 = F_47 ( & V_40 ) ;
}
static inline void F_46 ( struct V_3 * V_4 )
{
}
static void F_48 ( struct V_3 * V_4 )
{
F_49 ( V_4 -> V_41 , V_4 , NULL ) ;
F_46 ( V_4 ) ;
F_50 ( V_42 , & V_4 -> V_43 ) ;
}
static int F_51 ( struct V_3 * V_4 )
{
void * V_44 = & V_4 -> V_43 ;
T_3 * V_45 = F_52 ( V_44 , V_42 ) ;
struct V_46 V_47 = F_53 ( V_44 , V_42 ) ;
unsigned long V_48 ;
int V_49 ;
F_54 ( V_4 -> V_41 , V_4 , NULL ) ;
F_55 ( & V_45 -> V_34 , V_48 ) ;
F_56 ( V_42 , & V_4 -> V_43 ) ;
V_49 = F_57 ( & V_4 -> V_50 ) ;
if ( F_58 ( V_45 ) )
F_59 ( V_45 , V_51 , & V_47 ) ;
F_60 ( & V_45 -> V_34 , V_48 ) ;
return V_49 ;
}
int F_61 ( struct V_3 * V_4 , int (* F_62)( void * ) )
{
if ( F_62 == NULL )
F_62 = F_43 ;
return F_63 ( & V_4 -> V_43 , V_42 ,
F_62 , V_52 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
F_65 ( V_4 ) ;
if ( F_66 ( V_4 ) )
return;
if ( F_67 ( V_4 ) ) {
F_68 ( & V_4 -> V_7 . V_53 , V_54 ) ;
F_69 ( V_55 , & V_4 -> V_7 . V_53 ) ;
} else
F_70 ( & V_4 -> V_43 , V_56 ) ;
}
static void F_71 ( struct V_1 * V_16 ,
struct V_3 * V_4 ,
T_4 F_62 ,
unsigned char V_25 )
{
F_2 ( L_5 ,
V_4 -> V_6 , F_28 ( V_16 ) , V_14 ) ;
F_72 ( V_4 -> V_41 , V_4 , V_16 ) ;
F_22 ( V_16 , V_4 , V_25 ) ;
F_23 ( V_4 -> V_57 != NULL ) ;
V_4 -> V_57 = F_62 ;
F_8 ( V_16 , V_4 ) ;
}
void F_73 ( struct V_1 * V_16 , struct V_3 * V_4 ,
T_4 F_62 )
{
F_23 ( ! F_74 ( V_4 ) ) ;
if ( ! F_74 ( V_4 ) ) {
V_4 -> V_58 = - V_59 ;
F_75 ( V_4 ) ;
return;
}
F_76 ( & V_16 -> V_34 ) ;
F_71 ( V_16 , V_4 , F_62 , V_4 -> V_60 ) ;
F_77 ( & V_16 -> V_34 ) ;
}
void F_78 ( struct V_1 * V_16 , struct V_3 * V_4 ,
T_4 F_62 , int V_18 )
{
F_23 ( ! F_74 ( V_4 ) ) ;
if ( ! F_74 ( V_4 ) ) {
V_4 -> V_58 = - V_59 ;
F_75 ( V_4 ) ;
return;
}
F_76 ( & V_16 -> V_34 ) ;
F_71 ( V_16 , V_4 , F_62 , V_18 - V_61 ) ;
F_77 ( & V_16 -> V_34 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_6 ,
V_4 -> V_6 , V_14 ) ;
if ( ! F_74 ( V_4 ) ) {
F_80 ( V_62 L_7 , V_4 ) ;
return;
}
F_81 ( V_4 -> V_41 , V_4 , V_2 ) ;
F_33 ( V_2 , V_4 ) ;
F_64 ( V_4 ) ;
F_2 ( L_8 ) ;
}
static void F_82 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_24 ( V_4 ) && V_4 -> V_28 == V_2 )
F_79 ( V_2 , V_4 ) ;
}
int F_83 ( struct V_1 * V_2 )
{
int V_63 ;
F_76 ( & V_2 -> V_34 ) ;
V_63 = V_2 -> V_29 ;
F_77 ( & V_2 -> V_34 ) ;
return V_63 == 0 ;
}
void F_84 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_76 ( & V_2 -> V_34 ) ;
F_82 ( V_2 , V_4 ) ;
F_77 ( & V_2 -> V_34 ) ;
}
static struct V_3 * F_85 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
V_16 = & V_2 -> V_17 [ V_2 -> V_18 ] ;
if ( ! F_4 ( V_16 ) ) {
V_4 = F_30 ( V_16 -> V_30 , struct V_3 , V_7 . V_8 . V_10 ) ;
if ( V_2 -> V_20 == V_4 -> V_19 ) {
if ( -- V_2 -> V_22 )
goto V_64;
F_13 ( & V_4 -> V_7 . V_8 . V_10 , V_16 ) ;
}
goto V_65;
}
do {
if ( V_16 == & V_2 -> V_17 [ 0 ] )
V_16 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
else
V_16 = V_16 - 1 ;
if ( ! F_4 ( V_16 ) ) {
V_4 = F_30 ( V_16 -> V_30 , struct V_3 , V_7 . V_8 . V_10 ) ;
goto V_66;
}
} while ( V_16 != & V_2 -> V_17 [ V_2 -> V_18 ] );
F_16 ( V_2 ) ;
return NULL ;
V_66:
F_14 ( V_2 , ( unsigned int ) ( V_16 - & V_2 -> V_17 [ 0 ] ) ) ;
V_65:
F_15 ( V_2 , V_4 -> V_19 ) ;
V_64:
return V_4 ;
}
static struct V_3 * F_86 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) )
return F_85 ( V_2 ) ;
if ( ! F_4 ( & V_2 -> V_17 [ 0 ] ) )
return F_12 ( & V_2 -> V_17 [ 0 ] , struct V_3 , V_7 . V_8 . V_10 ) ;
return NULL ;
}
struct V_3 * F_87 ( struct V_1 * V_2 ,
bool (* F_88)( struct V_3 * , void * ) , void * V_67 )
{
struct V_3 * V_4 = NULL ;
F_2 ( L_9 ,
V_2 , F_28 ( V_2 ) ) ;
F_76 ( & V_2 -> V_34 ) ;
V_4 = F_86 ( V_2 ) ;
if ( V_4 != NULL ) {
if ( F_88 ( V_4 , V_67 ) )
F_82 ( V_2 , V_4 ) ;
else
V_4 = NULL ;
}
F_77 ( & V_2 -> V_34 ) ;
return V_4 ;
}
static bool F_89 ( struct V_3 * V_4 , void * V_67 )
{
return true ;
}
struct V_3 * F_90 ( struct V_1 * V_2 )
{
return F_87 ( V_2 , F_89 , NULL ) ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_15 * V_68 ;
F_76 ( & V_2 -> V_34 ) ;
V_68 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
for (; ; ) {
while ( ! F_4 ( V_68 ) ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_68 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
F_82 ( V_2 , V_4 ) ;
}
if ( V_68 == & V_2 -> V_17 [ 0 ] )
break;
V_68 -- ;
}
F_77 ( & V_2 -> V_34 ) ;
}
void F_92 ( struct V_1 * V_2 , int V_69 )
{
struct V_15 * V_68 ;
F_76 ( & V_2 -> V_34 ) ;
V_68 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
for (; ; ) {
while ( ! F_4 ( V_68 ) ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_68 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
V_4 -> V_58 = V_69 ;
F_82 ( V_2 , V_4 ) ;
}
if ( V_68 == & V_2 -> V_17 [ 0 ] )
break;
V_68 -- ;
}
F_77 ( & V_2 -> V_34 ) ;
}
static void V_35 ( unsigned long V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
struct V_3 * V_4 , * V_71 ;
unsigned long V_12 , V_72 , V_73 ;
F_93 ( & V_2 -> V_34 ) ;
V_12 = V_72 = V_14 ;
F_94 (task, n, &queue->timer_list.list, u.tk_wait.timer_list) {
V_73 = V_4 -> V_7 . V_8 . V_12 ;
if ( F_95 ( V_72 , V_73 ) ) {
F_2 ( L_10 , V_4 -> V_6 ) ;
V_4 -> V_58 = - V_74 ;
F_82 ( V_2 , V_4 ) ;
continue;
}
if ( V_12 == V_72 || F_96 ( V_12 , V_73 ) )
V_12 = V_73 ;
}
if ( ! F_4 ( & V_2 -> V_9 . V_10 ) )
F_6 ( V_2 , V_12 ) ;
F_97 ( & V_2 -> V_34 ) ;
}
static void F_98 ( struct V_3 * V_4 )
{
V_4 -> V_58 = 0 ;
}
void F_99 ( struct V_3 * V_4 , unsigned long V_75 )
{
V_4 -> V_5 = V_75 ;
F_73 ( & V_76 , V_4 , F_98 ) ;
}
void F_100 ( struct V_3 * V_4 )
{
V_4 -> V_77 -> V_78 ( V_4 , V_4 -> V_79 ) ;
}
static void
F_101 ( struct V_3 * V_4 )
{
V_4 -> V_80 = 2 ;
V_4 -> V_81 = 2 ;
V_4 -> V_82 = 2 ;
V_4 -> V_83 = F_102 () ;
}
static void
F_103 ( struct V_3 * V_4 )
{
V_4 -> V_84 = 0 ;
V_4 -> V_85 &= ~ ( V_86 | V_87 | V_88 ) ;
F_101 ( V_4 ) ;
}
void F_104 ( struct V_3 * V_4 )
{
V_4 -> V_89 = NULL ;
if ( V_4 -> V_77 -> V_90 != NULL ) {
V_4 -> V_77 -> V_90 ( V_4 , V_4 -> V_79 ) ;
if ( V_4 -> V_89 != NULL ) {
F_105 ( F_106 ( V_4 ) ) ;
F_107 ( V_4 ) ;
F_103 ( V_4 ) ;
}
}
}
void F_108 ( struct V_3 * V_4 , int V_69 )
{
V_4 -> V_58 = V_69 ;
V_4 -> V_89 = F_104 ;
if ( F_24 ( V_4 ) )
F_84 ( V_4 -> V_28 , V_4 ) ;
}
void F_109 ( const struct V_91 * V_92 , void * V_93 )
{
if ( V_92 -> V_94 != NULL )
V_92 -> V_94 ( V_93 ) ;
}
static void F_110 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_95 = F_67 ( V_4 ) ;
int V_69 = 0 ;
F_2 ( L_11 ,
V_4 -> V_6 , V_4 -> V_85 ) ;
F_23 ( F_24 ( V_4 ) ) ;
if ( F_24 ( V_4 ) )
return;
for (; ; ) {
void (* F_111)( struct V_3 * );
F_111 = V_4 -> V_57 ;
V_4 -> V_57 = NULL ;
if ( F_111 == NULL ) {
F_111 = V_4 -> V_89 ;
if ( F_111 == NULL )
break;
}
F_112 ( V_4 -> V_41 , V_4 , V_4 -> V_89 ) ;
F_111 ( V_4 ) ;
if ( ! F_24 ( V_4 ) )
continue;
V_2 = V_4 -> V_28 ;
F_76 ( & V_2 -> V_34 ) ;
if ( ! F_24 ( V_4 ) ) {
F_77 ( & V_2 -> V_34 ) ;
continue;
}
F_113 ( V_4 ) ;
F_77 ( & V_2 -> V_34 ) ;
if ( V_95 )
return;
F_2 ( L_12 , V_4 -> V_6 ) ;
V_69 = F_63 ( & V_4 -> V_43 ,
V_56 , F_43 ,
V_52 ) ;
if ( V_69 == - V_39 ) {
F_2 ( L_13 , V_4 -> V_6 ) ;
V_4 -> V_85 |= V_87 ;
F_108 ( V_4 , - V_39 ) ;
}
F_114 ( V_4 ) ;
F_2 ( L_14 , V_4 -> V_6 ) ;
}
F_2 ( L_15 , V_4 -> V_6 , V_69 ,
V_4 -> V_58 ) ;
F_115 ( V_4 ) ;
}
void F_116 ( struct V_3 * V_4 )
{
F_48 ( V_4 ) ;
F_64 ( V_4 ) ;
if ( ! F_67 ( V_4 ) )
F_110 ( V_4 ) ;
}
static void V_54 ( struct V_96 * V_97 )
{
V_38 -> V_48 |= V_98 ;
F_110 ( F_117 ( V_97 , struct V_3 , V_7 . V_53 ) ) ;
V_38 -> V_48 &= ~ V_98 ;
}
void * F_118 ( struct V_3 * V_4 , T_5 V_99 )
{
struct V_100 * V_101 ;
T_6 V_102 = V_103 ;
if ( F_26 ( V_4 ) )
V_102 |= V_104 ;
V_99 += sizeof( struct V_100 ) ;
if ( V_99 <= V_105 )
V_101 = F_119 ( V_106 , V_102 ) ;
else
V_101 = F_120 ( V_99 , V_102 ) ;
if ( ! V_101 )
return NULL ;
V_101 -> V_107 = V_99 ;
F_2 ( L_16 ,
V_4 -> V_6 , V_99 , V_101 ) ;
return & V_101 -> V_67 ;
}
void F_121 ( void * V_108 )
{
T_5 V_99 ;
struct V_100 * V_101 ;
if ( ! V_108 )
return;
V_101 = F_117 ( V_108 , struct V_100 , V_67 ) ;
V_99 = V_101 -> V_107 ;
F_2 ( L_17 ,
V_99 , V_101 ) ;
if ( V_99 <= V_105 )
F_122 ( V_101 , V_106 ) ;
else
F_123 ( V_101 ) ;
}
static void F_124 ( struct V_3 * V_4 , const struct V_109 * V_110 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_125 ( & V_4 -> V_50 , 1 ) ;
V_4 -> V_85 = V_110 -> V_48 ;
V_4 -> V_77 = V_110 -> V_111 ;
V_4 -> V_79 = V_110 -> V_112 ;
F_18 ( & V_4 -> V_113 ) ;
V_4 -> V_60 = V_110 -> V_18 - V_61 ;
V_4 -> V_19 = V_38 -> V_114 ;
V_4 -> V_115 = V_110 -> V_116 ;
if ( V_4 -> V_77 -> V_78 != NULL )
V_4 -> V_89 = F_100 ;
F_101 ( V_4 ) ;
F_2 ( L_18 ,
F_126 ( V_38 ) ) ;
}
static struct V_3 *
F_127 ( void )
{
return (struct V_3 * ) F_119 ( V_117 , V_118 ) ;
}
struct V_3 * F_128 ( const struct V_109 * V_119 )
{
struct V_3 * V_4 = V_119 -> V_4 ;
unsigned short V_48 = 0 ;
if ( V_4 == NULL ) {
V_4 = F_127 () ;
if ( V_4 == NULL ) {
F_109 ( V_119 -> V_111 ,
V_119 -> V_112 ) ;
return F_129 ( - V_120 ) ;
}
V_48 = V_121 ;
}
F_124 ( V_4 , V_119 ) ;
V_4 -> V_85 |= V_48 ;
F_2 ( L_19 , V_4 ) ;
return V_4 ;
}
static void F_130 ( struct V_3 * V_4 )
{
unsigned short V_85 = V_4 -> V_85 ;
F_109 ( V_4 -> V_77 , V_4 -> V_79 ) ;
if ( V_85 & V_121 ) {
F_2 ( L_20 , V_4 -> V_6 ) ;
F_122 ( V_4 , V_117 ) ;
}
}
static void F_131 ( struct V_96 * V_97 )
{
F_130 ( F_117 ( V_97 , struct V_3 , V_7 . V_53 ) ) ;
}
static void F_132 ( struct V_3 * V_4 )
{
F_107 ( V_4 ) ;
if ( V_4 -> V_122 . V_123 ) {
F_133 ( V_4 -> V_122 . V_123 ) ;
V_4 -> V_122 . V_123 = NULL ;
}
F_134 ( V_4 ) ;
}
static void F_135 ( struct V_3 * V_4 ,
struct V_124 * V_16 )
{
if ( V_16 != NULL ) {
F_68 ( & V_4 -> V_7 . V_53 , F_131 ) ;
F_69 ( V_16 , & V_4 -> V_7 . V_53 ) ;
} else
F_130 ( V_4 ) ;
}
static void F_136 ( struct V_3 * V_4 , struct V_124 * V_16 )
{
if ( F_57 ( & V_4 -> V_50 ) ) {
F_132 ( V_4 ) ;
F_135 ( V_4 , V_16 ) ;
}
}
void F_137 ( struct V_3 * V_4 )
{
F_136 ( V_4 , NULL ) ;
}
void F_75 ( struct V_3 * V_4 )
{
F_136 ( V_4 , V_4 -> V_115 ) ;
}
static void F_115 ( struct V_3 * V_4 )
{
F_2 ( L_21 , V_4 -> V_6 ) ;
F_23 ( F_24 ( V_4 ) ) ;
F_132 ( V_4 ) ;
if ( F_138 ( & V_4 -> V_50 ) != 1 + ! F_67 ( V_4 ) ) {
if ( ! F_51 ( V_4 ) )
return;
} else {
if ( ! F_57 ( & V_4 -> V_50 ) )
return;
}
F_135 ( V_4 , V_4 -> V_115 ) ;
}
int F_139 ( void )
{
return F_140 ( V_125 ) ? 0 : - V_126 ;
}
void F_141 ( void )
{
F_142 ( V_125 ) ;
}
static int F_143 ( void )
{
struct V_124 * V_45 ;
F_2 ( L_22 ) ;
V_45 = F_144 ( L_23 , V_127 , 1 ) ;
V_55 = V_45 ;
return V_55 != NULL ;
}
static void F_145 ( void )
{
struct V_124 * V_45 = NULL ;
if ( V_55 == NULL )
return;
F_2 ( L_24 ) ;
V_45 = V_55 ;
V_55 = NULL ;
F_146 ( V_45 ) ;
}
void
F_147 ( void )
{
F_145 () ;
if ( V_106 )
F_148 ( V_106 ) ;
if ( V_117 )
F_148 ( V_117 ) ;
if ( V_128 )
F_149 ( V_128 ) ;
if ( V_129 )
F_149 ( V_129 ) ;
F_41 ( & V_76 ) ;
}
int
F_150 ( void )
{
F_40 ( & V_76 , L_25 ) ;
if ( ! F_143 () )
goto V_130;
V_128 = F_151 ( L_26 ,
sizeof( struct V_3 ) ,
0 , V_131 ,
NULL ) ;
if ( ! V_128 )
goto V_130;
V_129 = F_151 ( L_27 ,
V_105 ,
0 , V_131 ,
NULL ) ;
if ( ! V_129 )
goto V_130;
V_117 = F_152 ( V_132 ,
V_128 ) ;
if ( ! V_117 )
goto V_130;
V_106 = F_152 ( V_133 ,
V_129 ) ;
if ( ! V_106 )
goto V_130;
return 0 ;
V_130:
F_147 () ;
return - V_120 ;
}
