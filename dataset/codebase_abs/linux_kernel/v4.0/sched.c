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
static int F_44 ( struct V_37 * V_38 )
{
if ( F_45 ( V_39 ) )
return - V_40 ;
F_46 () ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 )
{
static T_2 V_41 ;
V_4 -> V_6 = F_48 ( & V_41 ) ;
}
static inline void F_47 ( struct V_3 * V_4 )
{
}
static void F_49 ( struct V_3 * V_4 )
{
F_50 ( V_4 -> V_42 , V_4 , NULL ) ;
F_47 ( V_4 ) ;
F_51 ( V_43 , & V_4 -> V_44 ) ;
}
static int F_52 ( struct V_3 * V_4 )
{
void * V_45 = & V_4 -> V_44 ;
T_3 * V_46 = F_53 ( V_45 , V_43 ) ;
struct V_37 V_47 = F_54 ( V_45 , V_43 ) ;
unsigned long V_48 ;
int V_49 ;
F_55 ( V_4 -> V_42 , V_4 , NULL ) ;
F_56 ( & V_46 -> V_34 , V_48 ) ;
F_57 ( V_43 , & V_4 -> V_44 ) ;
V_49 = F_58 ( & V_4 -> V_50 ) ;
if ( F_59 ( V_46 ) )
F_60 ( V_46 , V_51 , & V_47 ) ;
F_61 ( & V_46 -> V_34 , V_48 ) ;
return V_49 ;
}
int F_62 ( struct V_3 * V_4 , T_4 * V_52 )
{
if ( V_52 == NULL )
V_52 = F_44 ;
return F_63 ( & V_4 -> V_44 , V_43 ,
V_52 , V_53 ) ;
}
static void F_64 ( struct V_3 * V_4 )
{
bool V_54 = ! F_65 ( V_4 ) ;
F_66 ( V_4 ) ;
if ( ! V_54 )
return;
if ( F_67 ( V_4 ) ) {
F_68 ( & V_4 -> V_7 . V_55 , V_56 ) ;
F_69 ( V_57 , & V_4 -> V_7 . V_55 ) ;
} else
F_70 ( & V_4 -> V_44 , V_58 ) ;
}
static void F_71 ( struct V_1 * V_16 ,
struct V_3 * V_4 ,
T_5 V_52 ,
unsigned char V_25 )
{
F_2 ( L_5 ,
V_4 -> V_6 , F_29 ( V_16 ) , V_14 ) ;
F_72 ( V_4 -> V_42 , V_4 , V_16 ) ;
F_22 ( V_16 , V_4 , V_25 ) ;
F_23 ( V_4 -> V_59 != NULL ) ;
V_4 -> V_59 = V_52 ;
F_8 ( V_16 , V_4 ) ;
}
void F_73 ( struct V_1 * V_16 , struct V_3 * V_4 ,
T_5 V_52 )
{
F_23 ( ! F_74 ( V_4 ) ) ;
if ( ! F_74 ( V_4 ) ) {
V_4 -> V_60 = - V_61 ;
F_75 ( V_4 ) ;
return;
}
F_76 ( & V_16 -> V_34 ) ;
F_71 ( V_16 , V_4 , V_52 , V_4 -> V_62 ) ;
F_77 ( & V_16 -> V_34 ) ;
}
void F_78 ( struct V_1 * V_16 , struct V_3 * V_4 ,
T_5 V_52 , int V_18 )
{
F_23 ( ! F_74 ( V_4 ) ) ;
if ( ! F_74 ( V_4 ) ) {
V_4 -> V_60 = - V_61 ;
F_75 ( V_4 ) ;
return;
}
F_76 ( & V_16 -> V_34 ) ;
F_71 ( V_16 , V_4 , V_52 , V_18 - V_63 ) ;
F_77 ( & V_16 -> V_34 ) ;
}
static void F_79 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_6 ,
V_4 -> V_6 , V_14 ) ;
if ( ! F_74 ( V_4 ) ) {
F_80 ( V_64 L_7 , V_4 ) ;
return;
}
F_81 ( V_4 -> V_42 , V_4 , V_2 ) ;
F_34 ( V_2 , V_4 ) ;
F_64 ( V_4 ) ;
F_2 ( L_8 ) ;
}
static void F_82 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_24 ( V_4 ) ) {
F_83 () ;
if ( V_4 -> V_28 == V_2 )
F_79 ( V_2 , V_4 ) ;
}
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
static struct V_3 * F_86 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) )
return F_85 ( V_2 ) ;
if ( ! F_4 ( & V_2 -> V_17 [ 0 ] ) )
return F_12 ( & V_2 -> V_17 [ 0 ] , struct V_3 , V_7 . V_8 . V_10 ) ;
return NULL ;
}
struct V_3 * F_87 ( struct V_1 * V_2 ,
bool (* F_88)( struct V_3 * , void * ) , void * V_68 )
{
struct V_3 * V_4 = NULL ;
F_2 ( L_9 ,
V_2 , F_29 ( V_2 ) ) ;
F_76 ( & V_2 -> V_34 ) ;
V_4 = F_86 ( V_2 ) ;
if ( V_4 != NULL ) {
if ( F_88 ( V_4 , V_68 ) )
F_82 ( V_2 , V_4 ) ;
else
V_4 = NULL ;
}
F_77 ( & V_2 -> V_34 ) ;
return V_4 ;
}
static bool F_89 ( struct V_3 * V_4 , void * V_68 )
{
return true ;
}
struct V_3 * F_90 ( struct V_1 * V_2 )
{
return F_87 ( V_2 , F_89 , NULL ) ;
}
void F_91 ( struct V_1 * V_2 )
{
struct V_15 * V_69 ;
F_76 ( & V_2 -> V_34 ) ;
V_69 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
for (; ; ) {
while ( ! F_4 ( V_69 ) ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_69 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
F_82 ( V_2 , V_4 ) ;
}
if ( V_69 == & V_2 -> V_17 [ 0 ] )
break;
V_69 -- ;
}
F_77 ( & V_2 -> V_34 ) ;
}
void F_92 ( struct V_1 * V_2 , int V_70 )
{
struct V_15 * V_69 ;
F_76 ( & V_2 -> V_34 ) ;
V_69 = & V_2 -> V_17 [ V_2 -> V_24 ] ;
for (; ; ) {
while ( ! F_4 ( V_69 ) ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_69 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
V_4 -> V_60 = V_70 ;
F_82 ( V_2 , V_4 ) ;
}
if ( V_69 == & V_2 -> V_17 [ 0 ] )
break;
V_69 -- ;
}
F_77 ( & V_2 -> V_34 ) ;
}
static void V_35 ( unsigned long V_71 )
{
struct V_1 * V_2 = (struct V_1 * ) V_71 ;
struct V_3 * V_4 , * V_72 ;
unsigned long V_12 , V_73 , V_74 ;
F_93 ( & V_2 -> V_34 ) ;
V_12 = V_73 = V_14 ;
F_94 (task, n, &queue->timer_list.list, u.tk_wait.timer_list) {
V_74 = V_4 -> V_7 . V_8 . V_12 ;
if ( F_95 ( V_73 , V_74 ) ) {
F_2 ( L_10 , V_4 -> V_6 ) ;
V_4 -> V_60 = - V_75 ;
F_82 ( V_2 , V_4 ) ;
continue;
}
if ( V_12 == V_73 || F_96 ( V_12 , V_74 ) )
V_12 = V_74 ;
}
if ( ! F_4 ( & V_2 -> V_9 . V_10 ) )
F_6 ( V_2 , V_12 ) ;
F_97 ( & V_2 -> V_34 ) ;
}
static void F_98 ( struct V_3 * V_4 )
{
if ( V_4 -> V_60 == - V_75 )
V_4 -> V_60 = 0 ;
}
void F_99 ( struct V_3 * V_4 , unsigned long V_76 )
{
V_4 -> V_5 = V_76 ;
F_73 ( & V_77 , V_4 , F_98 ) ;
}
void F_100 ( struct V_3 * V_4 )
{
V_4 -> V_78 -> V_79 ( V_4 , V_4 -> V_80 ) ;
}
static void
F_101 ( struct V_3 * V_4 )
{
V_4 -> V_81 = 2 ;
V_4 -> V_82 = 2 ;
V_4 -> V_83 = 2 ;
V_4 -> V_84 = F_102 () ;
}
static void
F_103 ( struct V_3 * V_4 )
{
V_4 -> V_85 = 0 ;
V_4 -> V_86 &= ~ ( V_87 | V_88 | V_89 ) ;
F_101 ( V_4 ) ;
}
void F_104 ( struct V_3 * V_4 )
{
V_4 -> V_90 = NULL ;
if ( V_4 -> V_78 -> V_91 != NULL ) {
V_4 -> V_78 -> V_91 ( V_4 , V_4 -> V_80 ) ;
if ( V_4 -> V_90 != NULL ) {
F_105 ( F_106 ( V_4 ) ) ;
F_107 ( V_4 ) ;
F_103 ( V_4 ) ;
}
}
}
void F_108 ( struct V_3 * V_4 , int V_70 )
{
V_4 -> V_60 = V_70 ;
V_4 -> V_90 = F_104 ;
if ( F_24 ( V_4 ) )
F_84 ( V_4 -> V_28 , V_4 ) ;
}
void F_109 ( const struct V_92 * V_93 , void * V_94 )
{
if ( V_93 -> V_95 != NULL )
V_93 -> V_95 ( V_94 ) ;
}
static void F_110 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_96 = F_67 ( V_4 ) ;
int V_70 = 0 ;
F_2 ( L_11 ,
V_4 -> V_6 , V_4 -> V_86 ) ;
F_23 ( F_24 ( V_4 ) ) ;
if ( F_24 ( V_4 ) )
return;
for (; ; ) {
void (* F_111)( struct V_3 * );
F_111 = V_4 -> V_59 ;
V_4 -> V_59 = NULL ;
if ( F_111 == NULL ) {
F_111 = V_4 -> V_90 ;
if ( F_111 == NULL )
break;
}
F_112 ( V_4 -> V_42 , V_4 , V_4 -> V_90 ) ;
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
if ( V_96 )
return;
F_2 ( L_12 , V_4 -> V_6 ) ;
V_70 = F_63 ( & V_4 -> V_44 ,
V_58 , F_44 ,
V_53 ) ;
if ( V_70 == - V_40 ) {
F_2 ( L_13 , V_4 -> V_6 ) ;
V_4 -> V_86 |= V_88 ;
F_108 ( V_4 , - V_40 ) ;
}
F_2 ( L_14 , V_4 -> V_6 ) ;
}
F_2 ( L_15 , V_4 -> V_6 , V_70 ,
V_4 -> V_60 ) ;
F_114 ( V_4 ) ;
}
void F_115 ( struct V_3 * V_4 )
{
bool V_97 = F_67 ( V_4 ) ;
F_49 ( V_4 ) ;
F_64 ( V_4 ) ;
if ( ! V_97 )
F_110 ( V_4 ) ;
}
static void V_56 ( struct V_98 * V_99 )
{
F_110 ( F_116 ( V_99 , struct V_3 , V_7 . V_55 ) ) ;
}
void * F_117 ( struct V_3 * V_4 , T_6 V_100 )
{
struct V_101 * V_102 ;
T_7 V_103 = V_104 | V_105 ;
if ( F_26 ( V_4 ) )
V_103 = V_106 | V_107 | V_105 ;
V_100 += sizeof( struct V_101 ) ;
if ( V_100 <= V_108 )
V_102 = F_118 ( V_109 , V_103 ) ;
else
V_102 = F_119 ( V_100 , V_103 ) ;
if ( ! V_102 )
return NULL ;
V_102 -> V_110 = V_100 ;
F_2 ( L_16 ,
V_4 -> V_6 , V_100 , V_102 ) ;
return & V_102 -> V_68 ;
}
void F_120 ( void * V_111 )
{
T_6 V_100 ;
struct V_101 * V_102 ;
if ( ! V_111 )
return;
V_102 = F_116 ( V_111 , struct V_101 , V_68 ) ;
V_100 = V_102 -> V_110 ;
F_2 ( L_17 ,
V_100 , V_102 ) ;
if ( V_100 <= V_108 )
F_121 ( V_102 , V_109 ) ;
else
F_122 ( V_102 ) ;
}
static void F_123 ( struct V_3 * V_4 , const struct V_112 * V_113 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_124 ( & V_4 -> V_50 , 1 ) ;
V_4 -> V_86 = V_113 -> V_48 ;
V_4 -> V_78 = V_113 -> V_114 ;
V_4 -> V_80 = V_113 -> V_115 ;
F_18 ( & V_4 -> V_116 ) ;
V_4 -> V_62 = V_113 -> V_18 - V_63 ;
V_4 -> V_19 = V_39 -> V_117 ;
V_4 -> V_118 = V_113 -> V_119 ;
if ( V_4 -> V_78 -> V_79 != NULL )
V_4 -> V_90 = F_100 ;
F_101 ( V_4 ) ;
F_2 ( L_18 ,
F_125 ( V_39 ) ) ;
}
static struct V_3 *
F_126 ( void )
{
return (struct V_3 * ) F_118 ( V_120 , V_104 ) ;
}
struct V_3 * F_127 ( const struct V_112 * V_121 )
{
struct V_3 * V_4 = V_121 -> V_4 ;
unsigned short V_48 = 0 ;
if ( V_4 == NULL ) {
V_4 = F_126 () ;
if ( V_4 == NULL ) {
F_109 ( V_121 -> V_114 ,
V_121 -> V_115 ) ;
return F_128 ( - V_122 ) ;
}
V_48 = V_123 ;
}
F_123 ( V_4 , V_121 ) ;
V_4 -> V_86 |= V_48 ;
F_2 ( L_19 , V_4 ) ;
return V_4 ;
}
static void F_129 ( struct V_3 * V_4 )
{
unsigned short V_86 = V_4 -> V_86 ;
F_109 ( V_4 -> V_78 , V_4 -> V_80 ) ;
if ( V_86 & V_123 ) {
F_2 ( L_20 , V_4 -> V_6 ) ;
F_121 ( V_4 , V_120 ) ;
}
}
static void F_130 ( struct V_98 * V_99 )
{
F_129 ( F_116 ( V_99 , struct V_3 , V_7 . V_55 ) ) ;
}
static void F_131 ( struct V_3 * V_4 )
{
F_107 ( V_4 ) ;
if ( V_4 -> V_124 . V_125 ) {
F_132 ( V_4 -> V_124 . V_125 ) ;
V_4 -> V_124 . V_125 = NULL ;
}
F_133 ( V_4 ) ;
}
static void F_134 ( struct V_3 * V_4 ,
struct V_126 * V_16 )
{
if ( V_16 != NULL ) {
F_68 ( & V_4 -> V_7 . V_55 , F_130 ) ;
F_69 ( V_16 , & V_4 -> V_7 . V_55 ) ;
} else
F_129 ( V_4 ) ;
}
static void F_135 ( struct V_3 * V_4 , struct V_126 * V_16 )
{
if ( F_58 ( & V_4 -> V_50 ) ) {
F_131 ( V_4 ) ;
F_134 ( V_4 , V_16 ) ;
}
}
void F_136 ( struct V_3 * V_4 )
{
F_135 ( V_4 , NULL ) ;
}
void F_75 ( struct V_3 * V_4 )
{
F_135 ( V_4 , V_4 -> V_118 ) ;
}
static void F_114 ( struct V_3 * V_4 )
{
F_2 ( L_21 , V_4 -> V_6 ) ;
F_23 ( F_24 ( V_4 ) ) ;
F_131 ( V_4 ) ;
if ( F_137 ( & V_4 -> V_50 ) != 1 + ! F_67 ( V_4 ) ) {
if ( ! F_52 ( V_4 ) )
return;
} else {
if ( ! F_58 ( & V_4 -> V_50 ) )
return;
}
F_134 ( V_4 , V_4 -> V_118 ) ;
}
int F_138 ( void )
{
return F_139 ( V_127 ) ? 0 : - V_128 ;
}
void F_140 ( void )
{
F_141 ( V_127 ) ;
}
static int F_142 ( void )
{
struct V_126 * V_46 ;
F_2 ( L_22 ) ;
V_46 = F_143 ( L_23 , V_129 | V_130 , 0 ) ;
V_57 = V_46 ;
return V_57 != NULL ;
}
static void F_144 ( void )
{
struct V_126 * V_46 = NULL ;
if ( V_57 == NULL )
return;
F_2 ( L_24 ) ;
V_46 = V_57 ;
V_57 = NULL ;
F_145 ( V_46 ) ;
}
void
F_146 ( void )
{
F_144 () ;
if ( V_109 )
F_147 ( V_109 ) ;
if ( V_120 )
F_147 ( V_120 ) ;
if ( V_131 )
F_148 ( V_131 ) ;
if ( V_132 )
F_148 ( V_132 ) ;
F_42 ( & V_77 ) ;
}
int
F_149 ( void )
{
F_41 ( & V_77 , L_25 ) ;
if ( ! F_142 () )
goto V_133;
V_131 = F_150 ( L_26 ,
sizeof( struct V_3 ) ,
0 , V_134 ,
NULL ) ;
if ( ! V_131 )
goto V_133;
V_132 = F_150 ( L_27 ,
V_108 ,
0 , V_134 ,
NULL ) ;
if ( ! V_132 )
goto V_133;
V_120 = F_151 ( V_135 ,
V_131 ) ;
if ( ! V_120 )
goto V_133;
V_109 = F_151 ( V_136 ,
V_132 ) ;
if ( ! V_109 )
goto V_133;
return 0 ;
V_133:
F_146 () ;
return - V_122 ;
}
