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
F_27 () ;
F_28 ( V_4 ) ;
F_2 ( L_3 ,
V_4 -> V_6 , V_2 , F_29 ( V_2 ) ) ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_3 * V_26 ;
if ( ! F_4 ( & V_4 -> V_7 . V_8 . V_27 ) ) {
V_26 = F_31 ( V_4 -> V_7 . V_8 . V_27 . V_30 , struct V_3 , V_7 . V_8 . V_10 ) ;
F_32 ( & V_26 -> V_7 . V_8 . V_10 , & V_4 -> V_7 . V_8 . V_10 ) ;
F_33 ( & V_4 -> V_7 . V_8 . V_27 , & V_26 -> V_7 . V_8 . V_27 ) ;
}
}
static void F_34 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( F_25 ( V_2 ) )
F_30 ( V_4 ) ;
F_3 ( & V_4 -> V_7 . V_8 . V_10 ) ;
V_2 -> V_29 -- ;
F_2 ( L_4 ,
V_4 -> V_6 , V_2 , F_29 ( V_2 ) ) ;
}
static void F_35 ( struct V_1 * V_2 , const char * V_31 , unsigned char V_32 )
{
int V_33 ;
F_36 ( & V_2 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < F_37 ( V_2 -> V_17 ) ; V_33 ++ )
F_18 ( & V_2 -> V_17 [ V_33 ] ) ;
V_2 -> V_24 = V_32 - 1 ;
F_16 ( V_2 ) ;
V_2 -> V_29 = 0 ;
F_38 ( & V_2 -> V_9 . V_11 , V_35 , ( unsigned long ) V_2 ) ;
F_18 ( & V_2 -> V_9 . V_10 ) ;
F_39 ( V_2 , V_31 ) ;
}
void F_40 ( struct V_1 * V_2 , const char * V_31 )
{
F_35 ( V_2 , V_31 , V_36 ) ;
}
void F_41 ( struct V_1 * V_2 , const char * V_31 )
{
F_35 ( V_2 , V_31 , 1 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_9 . V_11 ) ;
}
static int F_44 ( void * V_37 )
{
if ( F_45 ( V_38 ) )
return - V_39 ;
F_46 () ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 )
{
static T_2 V_40 ;
V_4 -> V_6 = F_48 ( & V_40 ) ;
}
static inline void F_47 ( struct V_3 * V_4 )
{
}
static void F_49 ( struct V_3 * V_4 )
{
F_50 ( V_4 -> V_41 , V_4 , NULL ) ;
F_47 ( V_4 ) ;
F_51 ( V_42 , & V_4 -> V_43 ) ;
}
static int F_52 ( struct V_3 * V_4 )
{
void * V_44 = & V_4 -> V_43 ;
T_3 * V_45 = F_53 ( V_44 , V_42 ) ;
struct V_46 V_47 = F_54 ( V_44 , V_42 ) ;
unsigned long V_48 ;
int V_49 ;
F_55 ( V_4 -> V_41 , V_4 , NULL ) ;
F_56 ( & V_45 -> V_34 , V_48 ) ;
F_57 ( V_42 , & V_4 -> V_43 ) ;
V_49 = F_58 ( & V_4 -> V_50 ) ;
if ( F_59 ( V_45 ) )
F_60 ( V_45 , V_51 , & V_47 ) ;
F_61 ( & V_45 -> V_34 , V_48 ) ;
return V_49 ;
}
int F_62 ( struct V_3 * V_4 , int (* F_63)( void * ) )
{
if ( F_63 == NULL )
F_63 = F_44 ;
return F_64 ( & V_4 -> V_43 , V_42 ,
F_63 , V_52 ) ;
}
static void F_65 ( struct V_3 * V_4 )
{
bool V_53 = ! F_66 ( V_4 ) ;
F_67 ( V_4 ) ;
if ( ! V_53 )
return;
if ( F_68 ( V_4 ) ) {
F_69 ( & V_4 -> V_7 . V_54 , V_55 ) ;
F_70 ( V_56 , & V_4 -> V_7 . V_54 ) ;
} else
F_71 ( & V_4 -> V_43 , V_57 ) ;
}
static void F_72 ( struct V_1 * V_16 ,
struct V_3 * V_4 ,
T_4 F_63 ,
unsigned char V_25 )
{
F_2 ( L_5 ,
V_4 -> V_6 , F_29 ( V_16 ) , V_14 ) ;
F_73 ( V_4 -> V_41 , V_4 , V_16 ) ;
F_22 ( V_16 , V_4 , V_25 ) ;
F_23 ( V_4 -> V_58 != NULL ) ;
V_4 -> V_58 = F_63 ;
F_8 ( V_16 , V_4 ) ;
}
void F_74 ( struct V_1 * V_16 , struct V_3 * V_4 ,
T_4 F_63 )
{
F_23 ( ! F_75 ( V_4 ) ) ;
if ( ! F_75 ( V_4 ) ) {
V_4 -> V_59 = - V_60 ;
F_76 ( V_4 ) ;
return;
}
F_77 ( & V_16 -> V_34 ) ;
F_72 ( V_16 , V_4 , F_63 , V_4 -> V_61 ) ;
F_78 ( & V_16 -> V_34 ) ;
}
void F_79 ( struct V_1 * V_16 , struct V_3 * V_4 ,
T_4 F_63 , int V_18 )
{
F_23 ( ! F_75 ( V_4 ) ) ;
if ( ! F_75 ( V_4 ) ) {
V_4 -> V_59 = - V_60 ;
F_76 ( V_4 ) ;
return;
}
F_77 ( & V_16 -> V_34 ) ;
F_72 ( V_16 , V_4 , F_63 , V_18 - V_62 ) ;
F_78 ( & V_16 -> V_34 ) ;
}
static void F_80 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_6 ,
V_4 -> V_6 , V_14 ) ;
if ( ! F_75 ( V_4 ) ) {
F_81 ( V_63 L_7 , V_4 ) ;
return;
}
F_82 ( V_4 -> V_41 , V_4 , V_2 ) ;
F_34 ( V_2 , V_4 ) ;
F_65 ( V_4 ) ;
F_2 ( L_8 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_24 ( V_4 ) ) {
F_84 () ;
if ( V_4 -> V_28 == V_2 )
F_80 ( V_2 , V_4 ) ;
}
}
int F_85 ( struct V_1 * V_2 )
{
int V_64 ;
F_77 ( & V_2 -> V_34 ) ;
V_64 = V_2 -> V_29 ;
F_78 ( & V_2 -> V_34 ) ;
return V_64 == 0 ;
}
void F_86 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_77 ( & V_2 -> V_34 ) ;
F_83 ( V_2 , V_4 ) ;
F_78 ( & V_2 -> V_34 ) ;
}
static struct V_3 * F_87 ( struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_3 * V_4 ;
V_16 = & V_2 -> V_17 [ V_2 -> V_18 ] ;
if ( ! F_4 ( V_16 ) ) {
V_4 = F_31 ( V_16 -> V_30 , struct V_3 , V_7 . V_8 . V_10 ) ;
if ( V_2 -> V_20 == V_4 -> V_19 ) {
if ( -- V_2 -> V_22 )
goto V_65;
F_13 ( & V_4 -> V_7 . V_8 . V_10 , V_16 ) ;
}
goto V_66;
}
do {
if ( V_16 == & V_2 -> V_17 [ 0 ] )
V_16 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
else
V_16 = V_16 - 1 ;
if ( ! F_4 ( V_16 ) ) {
V_4 = F_31 ( V_16 -> V_30 , struct V_3 , V_7 . V_8 . V_10 ) ;
goto V_67;
}
} while ( V_16 != & V_2 -> V_17 [ V_2 -> V_18 ] );
F_16 ( V_2 ) ;
return NULL ;
V_67:
F_14 ( V_2 , ( unsigned int ) ( V_16 - & V_2 -> V_17 [ 0 ] ) ) ;
V_66:
F_15 ( V_2 , V_4 -> V_19 ) ;
V_65:
return V_4 ;
}
static struct V_3 * F_88 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) )
return F_87 ( V_2 ) ;
if ( ! F_4 ( & V_2 -> V_17 [ 0 ] ) )
return F_12 ( & V_2 -> V_17 [ 0 ] , struct V_3 , V_7 . V_8 . V_10 ) ;
return NULL ;
}
struct V_3 * F_89 ( struct V_1 * V_2 ,
bool (* F_90)( struct V_3 * , void * ) , void * V_68 )
{
struct V_3 * V_4 = NULL ;
F_2 ( L_9 ,
V_2 , F_29 ( V_2 ) ) ;
F_77 ( & V_2 -> V_34 ) ;
V_4 = F_88 ( V_2 ) ;
if ( V_4 != NULL ) {
if ( F_90 ( V_4 , V_68 ) )
F_83 ( V_2 , V_4 ) ;
else
V_4 = NULL ;
}
F_78 ( & V_2 -> V_34 ) ;
return V_4 ;
}
static bool F_91 ( struct V_3 * V_4 , void * V_68 )
{
return true ;
}
struct V_3 * F_92 ( struct V_1 * V_2 )
{
return F_89 ( V_2 , F_91 , NULL ) ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_15 * V_69 ;
F_77 ( & V_2 -> V_34 ) ;
V_69 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
for (; ; ) {
while ( ! F_4 ( V_69 ) ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_69 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
F_83 ( V_2 , V_4 ) ;
}
if ( V_69 == & V_2 -> V_17 [ 0 ] )
break;
V_69 -- ;
}
F_78 ( & V_2 -> V_34 ) ;
}
void F_94 ( struct V_1 * V_2 , int V_70 )
{
struct V_15 * V_69 ;
F_77 ( & V_2 -> V_34 ) ;
V_69 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
for (; ; ) {
while ( ! F_4 ( V_69 ) ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_69 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
V_4 -> V_59 = V_70 ;
F_83 ( V_2 , V_4 ) ;
}
if ( V_69 == & V_2 -> V_17 [ 0 ] )
break;
V_69 -- ;
}
F_78 ( & V_2 -> V_34 ) ;
}
static void V_35 ( unsigned long V_71 )
{
struct V_1 * V_2 = (struct V_1 * ) V_71 ;
struct V_3 * V_4 , * V_72 ;
unsigned long V_12 , V_73 , V_74 ;
F_95 ( & V_2 -> V_34 ) ;
V_12 = V_73 = V_14 ;
F_96 (task, n, &queue->timer_list.list, u.tk_wait.timer_list) {
V_74 = V_4 -> V_7 . V_8 . V_12 ;
if ( F_97 ( V_73 , V_74 ) ) {
F_2 ( L_10 , V_4 -> V_6 ) ;
V_4 -> V_59 = - V_75 ;
F_83 ( V_2 , V_4 ) ;
continue;
}
if ( V_12 == V_73 || F_98 ( V_12 , V_74 ) )
V_12 = V_74 ;
}
if ( ! F_4 ( & V_2 -> V_9 . V_10 ) )
F_6 ( V_2 , V_12 ) ;
F_99 ( & V_2 -> V_34 ) ;
}
static void F_100 ( struct V_3 * V_4 )
{
V_4 -> V_59 = 0 ;
}
void F_101 ( struct V_3 * V_4 , unsigned long V_76 )
{
V_4 -> V_5 = V_76 ;
F_74 ( & V_77 , V_4 , F_100 ) ;
}
void F_102 ( struct V_3 * V_4 )
{
V_4 -> V_78 -> V_79 ( V_4 , V_4 -> V_80 ) ;
}
static void
F_103 ( struct V_3 * V_4 )
{
V_4 -> V_81 = 2 ;
V_4 -> V_82 = 2 ;
V_4 -> V_83 = 2 ;
V_4 -> V_84 = F_104 () ;
}
static void
F_105 ( struct V_3 * V_4 )
{
V_4 -> V_85 = 0 ;
V_4 -> V_86 &= ~ ( V_87 | V_88 | V_89 ) ;
F_103 ( V_4 ) ;
}
void F_106 ( struct V_3 * V_4 )
{
V_4 -> V_90 = NULL ;
if ( V_4 -> V_78 -> V_91 != NULL ) {
V_4 -> V_78 -> V_91 ( V_4 , V_4 -> V_80 ) ;
if ( V_4 -> V_90 != NULL ) {
F_107 ( F_108 ( V_4 ) ) ;
F_109 ( V_4 ) ;
F_105 ( V_4 ) ;
}
}
}
void F_110 ( struct V_3 * V_4 , int V_70 )
{
V_4 -> V_59 = V_70 ;
V_4 -> V_90 = F_106 ;
if ( F_24 ( V_4 ) )
F_86 ( V_4 -> V_28 , V_4 ) ;
}
void F_111 ( const struct V_92 * V_93 , void * V_94 )
{
if ( V_93 -> V_95 != NULL )
V_93 -> V_95 ( V_94 ) ;
}
static void F_112 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_96 = F_68 ( V_4 ) ;
int V_70 = 0 ;
F_2 ( L_11 ,
V_4 -> V_6 , V_4 -> V_86 ) ;
F_23 ( F_24 ( V_4 ) ) ;
if ( F_24 ( V_4 ) )
return;
for (; ; ) {
void (* F_113)( struct V_3 * );
F_113 = V_4 -> V_58 ;
V_4 -> V_58 = NULL ;
if ( F_113 == NULL ) {
F_113 = V_4 -> V_90 ;
if ( F_113 == NULL )
break;
}
F_114 ( V_4 -> V_41 , V_4 , V_4 -> V_90 ) ;
F_113 ( V_4 ) ;
if ( ! F_24 ( V_4 ) )
continue;
V_2 = V_4 -> V_28 ;
F_77 ( & V_2 -> V_34 ) ;
if ( ! F_24 ( V_4 ) ) {
F_78 ( & V_2 -> V_34 ) ;
continue;
}
F_115 ( V_4 ) ;
F_78 ( & V_2 -> V_34 ) ;
if ( V_96 )
return;
F_2 ( L_12 , V_4 -> V_6 ) ;
V_70 = F_64 ( & V_4 -> V_43 ,
V_57 , F_44 ,
V_52 ) ;
if ( V_70 == - V_39 ) {
F_2 ( L_13 , V_4 -> V_6 ) ;
V_4 -> V_86 |= V_88 ;
F_110 ( V_4 , - V_39 ) ;
}
F_116 ( V_4 ) ;
F_2 ( L_14 , V_4 -> V_6 ) ;
}
F_2 ( L_15 , V_4 -> V_6 , V_70 ,
V_4 -> V_59 ) ;
F_117 ( V_4 ) ;
}
void F_118 ( struct V_3 * V_4 )
{
F_49 ( V_4 ) ;
F_65 ( V_4 ) ;
if ( ! F_68 ( V_4 ) )
F_112 ( V_4 ) ;
}
static void V_55 ( struct V_97 * V_98 )
{
V_38 -> V_48 |= V_99 ;
F_112 ( F_119 ( V_98 , struct V_3 , V_7 . V_54 ) ) ;
V_38 -> V_48 &= ~ V_99 ;
}
void * F_120 ( struct V_3 * V_4 , T_5 V_100 )
{
struct V_101 * V_102 ;
T_6 V_103 = V_104 ;
if ( F_26 ( V_4 ) )
V_103 |= V_105 ;
V_100 += sizeof( struct V_101 ) ;
if ( V_100 <= V_106 )
V_102 = F_121 ( V_107 , V_103 ) ;
else
V_102 = F_122 ( V_100 , V_103 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_108 = V_100 ;
F_2 ( L_16 ,
V_4 -> V_6 , V_100 , V_102 ) ;
return & V_102 -> V_68 ;
}
void F_123 ( void * V_109 )
{
T_5 V_100 ;
struct V_101 * V_102 ;
if ( ! V_109 )
return;
V_102 = F_119 ( V_109 , struct V_101 , V_68 ) ;
V_100 = V_102 -> V_108 ;
F_2 ( L_17 ,
V_100 , V_102 ) ;
if ( V_100 <= V_106 )
F_124 ( V_102 , V_107 ) ;
else
F_125 ( V_102 ) ;
}
static void F_126 ( struct V_3 * V_4 , const struct V_110 * V_111 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_127 ( & V_4 -> V_50 , 1 ) ;
V_4 -> V_86 = V_111 -> V_48 ;
V_4 -> V_78 = V_111 -> V_112 ;
V_4 -> V_80 = V_111 -> V_113 ;
F_18 ( & V_4 -> V_114 ) ;
V_4 -> V_61 = V_111 -> V_18 - V_62 ;
V_4 -> V_19 = V_38 -> V_115 ;
V_4 -> V_116 = V_111 -> V_117 ;
if ( V_4 -> V_78 -> V_79 != NULL )
V_4 -> V_90 = F_102 ;
F_103 ( V_4 ) ;
F_2 ( L_18 ,
F_128 ( V_38 ) ) ;
}
static struct V_3 *
F_129 ( void )
{
return (struct V_3 * ) F_121 ( V_118 , V_119 ) ;
}
struct V_3 * F_130 ( const struct V_110 * V_120 )
{
struct V_3 * V_4 = V_120 -> V_4 ;
unsigned short V_48 = 0 ;
if ( V_4 == NULL ) {
V_4 = F_129 () ;
if ( V_4 == NULL ) {
F_111 ( V_120 -> V_112 ,
V_120 -> V_113 ) ;
return F_131 ( - V_121 ) ;
}
V_48 = V_122 ;
}
F_126 ( V_4 , V_120 ) ;
V_4 -> V_86 |= V_48 ;
F_2 ( L_19 , V_4 ) ;
return V_4 ;
}
static void F_132 ( struct V_3 * V_4 )
{
unsigned short V_86 = V_4 -> V_86 ;
F_111 ( V_4 -> V_78 , V_4 -> V_80 ) ;
if ( V_86 & V_122 ) {
F_2 ( L_20 , V_4 -> V_6 ) ;
F_124 ( V_4 , V_118 ) ;
}
}
static void F_133 ( struct V_97 * V_98 )
{
F_132 ( F_119 ( V_98 , struct V_3 , V_7 . V_54 ) ) ;
}
static void F_134 ( struct V_3 * V_4 )
{
F_109 ( V_4 ) ;
if ( V_4 -> V_123 . V_124 ) {
F_135 ( V_4 -> V_123 . V_124 ) ;
V_4 -> V_123 . V_124 = NULL ;
}
F_136 ( V_4 ) ;
}
static void F_137 ( struct V_3 * V_4 ,
struct V_125 * V_16 )
{
if ( V_16 != NULL ) {
F_69 ( & V_4 -> V_7 . V_54 , F_133 ) ;
F_70 ( V_16 , & V_4 -> V_7 . V_54 ) ;
} else
F_132 ( V_4 ) ;
}
static void F_138 ( struct V_3 * V_4 , struct V_125 * V_16 )
{
if ( F_58 ( & V_4 -> V_50 ) ) {
F_134 ( V_4 ) ;
F_137 ( V_4 , V_16 ) ;
}
}
void F_139 ( struct V_3 * V_4 )
{
F_138 ( V_4 , NULL ) ;
}
void F_76 ( struct V_3 * V_4 )
{
F_138 ( V_4 , V_4 -> V_116 ) ;
}
static void F_117 ( struct V_3 * V_4 )
{
F_2 ( L_21 , V_4 -> V_6 ) ;
F_23 ( F_24 ( V_4 ) ) ;
F_134 ( V_4 ) ;
if ( F_140 ( & V_4 -> V_50 ) != 1 + ! F_68 ( V_4 ) ) {
if ( ! F_52 ( V_4 ) )
return;
} else {
if ( ! F_58 ( & V_4 -> V_50 ) )
return;
}
F_137 ( V_4 , V_4 -> V_116 ) ;
}
int F_141 ( void )
{
return F_142 ( V_126 ) ? 0 : - V_127 ;
}
void F_143 ( void )
{
F_144 ( V_126 ) ;
}
static int F_145 ( void )
{
struct V_125 * V_45 ;
F_2 ( L_22 ) ;
V_45 = F_146 ( L_23 , V_128 , 1 ) ;
V_56 = V_45 ;
return V_56 != NULL ;
}
static void F_147 ( void )
{
struct V_125 * V_45 = NULL ;
if ( V_56 == NULL )
return;
F_2 ( L_24 ) ;
V_45 = V_56 ;
V_56 = NULL ;
F_148 ( V_45 ) ;
}
void
F_149 ( void )
{
F_147 () ;
if ( V_107 )
F_150 ( V_107 ) ;
if ( V_118 )
F_150 ( V_118 ) ;
if ( V_129 )
F_151 ( V_129 ) ;
if ( V_130 )
F_151 ( V_130 ) ;
F_42 ( & V_77 ) ;
}
int
F_152 ( void )
{
F_41 ( & V_77 , L_25 ) ;
if ( ! F_145 () )
goto V_131;
V_129 = F_153 ( L_26 ,
sizeof( struct V_3 ) ,
0 , V_132 ,
NULL ) ;
if ( ! V_129 )
goto V_131;
V_130 = F_153 ( L_27 ,
V_106 ,
0 , V_132 ,
NULL ) ;
if ( ! V_130 )
goto V_131;
V_118 = F_154 ( V_133 ,
V_129 ) ;
if ( ! V_118 )
goto V_131;
V_107 = F_154 ( V_134 ,
V_130 ) ;
if ( ! V_107 )
goto V_131;
return 0 ;
V_131:
F_149 () ;
return - V_121 ;
}
