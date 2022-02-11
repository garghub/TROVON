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
V_4 -> V_6 , F_9 ( V_4 -> V_5 ) ) ;
V_4 -> V_7 . V_8 . V_12 = V_13 + V_4 -> V_5 ;
if ( F_4 ( & V_2 -> V_9 . V_10 ) || F_10 ( V_4 -> V_7 . V_8 . V_12 , V_2 -> V_9 . V_12 ) )
F_6 ( V_2 , V_4 -> V_7 . V_8 . V_12 ) ;
F_11 ( & V_4 -> V_7 . V_8 . V_9 , & V_2 -> V_9 . V_10 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 [ V_2 -> V_17 ] ;
struct V_3 * V_4 ;
if ( ! F_4 ( V_15 ) ) {
V_4 = F_13 ( V_15 , struct V_3 , V_7 . V_8 . V_10 ) ;
if ( V_4 -> V_18 == V_2 -> V_19 )
F_14 ( & V_4 -> V_7 . V_8 . V_10 , V_15 ) ;
}
}
static void F_15 ( struct V_1 * V_2 , int V_17 )
{
if ( V_2 -> V_17 != V_17 ) {
F_12 ( V_2 ) ;
V_2 -> V_17 = V_17 ;
}
}
static void F_16 ( struct V_1 * V_2 , T_1 V_20 )
{
V_2 -> V_19 = V_20 ;
V_2 -> V_21 = V_22 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_2 -> V_23 ) ;
F_16 ( V_2 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_24 )
{
struct V_14 * V_15 ;
struct V_3 * V_25 ;
F_19 ( & V_4 -> V_7 . V_8 . V_26 ) ;
if ( F_20 ( V_24 > V_2 -> V_23 ) )
V_24 = V_2 -> V_23 ;
if ( V_24 > V_2 -> V_17 )
F_15 ( V_2 , V_24 ) ;
V_15 = & V_2 -> V_16 [ V_24 ] ;
F_21 (t, q, u.tk_wait.list) {
if ( V_25 -> V_18 == V_4 -> V_18 ) {
F_22 ( & V_4 -> V_7 . V_8 . V_10 , & V_25 -> V_7 . V_8 . V_26 ) ;
return;
}
}
F_22 ( & V_4 -> V_7 . V_8 . V_10 , V_15 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned char V_24 )
{
F_24 ( F_25 ( V_4 ) ) ;
if ( F_25 ( V_4 ) )
return;
if ( F_26 ( V_2 ) )
F_18 ( V_2 , V_4 , V_24 ) ;
else if ( F_27 ( V_4 ) )
F_11 ( & V_4 -> V_7 . V_8 . V_10 , & V_2 -> V_16 [ 0 ] ) ;
else
F_22 ( & V_4 -> V_7 . V_8 . V_10 , & V_2 -> V_16 [ 0 ] ) ;
V_4 -> V_27 = V_2 ;
V_2 -> V_28 ++ ;
F_28 () ;
F_29 ( V_4 ) ;
F_2 ( L_3 ,
V_4 -> V_6 , V_2 , F_30 ( V_2 ) ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_3 * V_25 ;
if ( ! F_4 ( & V_4 -> V_7 . V_8 . V_26 ) ) {
V_25 = F_32 ( V_4 -> V_7 . V_8 . V_26 . V_29 , struct V_3 , V_7 . V_8 . V_10 ) ;
F_33 ( & V_25 -> V_7 . V_8 . V_10 , & V_4 -> V_7 . V_8 . V_10 ) ;
F_34 ( & V_4 -> V_7 . V_8 . V_26 , & V_25 -> V_7 . V_8 . V_26 ) ;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_1 ( V_2 , V_4 ) ;
if ( F_26 ( V_2 ) )
F_31 ( V_4 ) ;
F_3 ( & V_4 -> V_7 . V_8 . V_10 ) ;
V_2 -> V_28 -- ;
F_2 ( L_4 ,
V_4 -> V_6 , V_2 , F_30 ( V_2 ) ) ;
}
static void F_36 ( struct V_1 * V_2 , const char * V_30 , unsigned char V_31 )
{
int V_32 ;
F_37 ( & V_2 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < F_38 ( V_2 -> V_16 ) ; V_32 ++ )
F_19 ( & V_2 -> V_16 [ V_32 ] ) ;
V_2 -> V_23 = V_31 - 1 ;
F_17 ( V_2 ) ;
V_2 -> V_28 = 0 ;
F_39 ( & V_2 -> V_9 . V_11 , V_34 , ( unsigned long ) V_2 ) ;
F_19 ( & V_2 -> V_9 . V_10 ) ;
F_40 ( V_2 , V_30 ) ;
}
void F_41 ( struct V_1 * V_2 , const char * V_30 )
{
F_36 ( V_2 , V_30 , V_35 ) ;
}
void F_42 ( struct V_1 * V_2 , const char * V_30 )
{
F_36 ( V_2 , V_30 , 1 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
F_44 ( & V_2 -> V_9 . V_11 ) ;
}
static int F_45 ( struct V_36 * V_37 )
{
if ( F_46 ( V_38 ) )
return - V_39 ;
F_47 () ;
return 0 ;
}
static void F_48 ( struct V_3 * V_4 )
{
static T_2 V_40 ;
V_4 -> V_6 = F_49 ( & V_40 ) ;
}
static inline void F_48 ( struct V_3 * V_4 )
{
}
static void F_50 ( struct V_3 * V_4 )
{
F_51 ( V_4 -> V_41 , V_4 , NULL ) ;
F_48 ( V_4 ) ;
F_52 ( V_42 , & V_4 -> V_43 ) ;
}
static int F_53 ( struct V_3 * V_4 )
{
void * V_44 = & V_4 -> V_43 ;
T_3 * V_45 = F_54 ( V_44 , V_42 ) ;
struct V_36 V_46 = F_55 ( V_44 , V_42 ) ;
unsigned long V_47 ;
int V_48 ;
F_56 ( V_4 -> V_41 , V_4 , NULL ) ;
F_57 ( & V_45 -> V_33 , V_47 ) ;
F_58 ( V_42 , & V_4 -> V_43 ) ;
V_48 = F_59 ( & V_4 -> V_49 ) ;
if ( F_60 ( V_45 ) )
F_61 ( V_45 , V_50 , & V_46 ) ;
F_62 ( & V_45 -> V_33 , V_47 ) ;
return V_48 ;
}
int F_63 ( struct V_3 * V_4 , T_4 * V_51 )
{
if ( V_51 == NULL )
V_51 = F_45 ;
return F_64 ( & V_4 -> V_43 , V_42 ,
V_51 , V_52 ) ;
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
static void F_72 ( struct V_1 * V_15 ,
struct V_3 * V_4 ,
T_5 V_51 ,
unsigned char V_24 )
{
F_2 ( L_5 ,
V_4 -> V_6 , F_30 ( V_15 ) , V_13 ) ;
F_73 ( V_4 -> V_41 , V_4 , V_15 ) ;
F_23 ( V_15 , V_4 , V_24 ) ;
F_24 ( V_4 -> V_58 != NULL ) ;
V_4 -> V_58 = V_51 ;
F_8 ( V_15 , V_4 ) ;
}
void F_74 ( struct V_1 * V_15 , struct V_3 * V_4 ,
T_5 V_51 )
{
F_24 ( ! F_75 ( V_4 ) ) ;
if ( ! F_75 ( V_4 ) ) {
V_4 -> V_59 = - V_60 ;
F_76 ( V_4 ) ;
return;
}
F_77 ( & V_15 -> V_33 ) ;
F_72 ( V_15 , V_4 , V_51 , V_4 -> V_61 ) ;
F_78 ( & V_15 -> V_33 ) ;
}
void F_79 ( struct V_1 * V_15 , struct V_3 * V_4 ,
T_5 V_51 , int V_17 )
{
F_24 ( ! F_75 ( V_4 ) ) ;
if ( ! F_75 ( V_4 ) ) {
V_4 -> V_59 = - V_60 ;
F_76 ( V_4 ) ;
return;
}
F_77 ( & V_15 -> V_33 ) ;
F_72 ( V_15 , V_4 , V_51 , V_17 - V_62 ) ;
F_78 ( & V_15 -> V_33 ) ;
}
static void F_80 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( L_6 ,
V_4 -> V_6 , V_13 ) ;
if ( ! F_75 ( V_4 ) ) {
F_81 ( V_63 L_7 , V_4 ) ;
return;
}
F_82 ( V_4 -> V_41 , V_4 , V_2 ) ;
F_35 ( V_2 , V_4 ) ;
F_65 ( V_4 ) ;
F_2 ( L_8 ) ;
}
static void F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_25 ( V_4 ) ) {
F_84 () ;
if ( V_4 -> V_27 == V_2 )
F_80 ( V_2 , V_4 ) ;
}
}
void F_85 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_77 ( & V_2 -> V_33 ) ;
F_83 ( V_2 , V_4 ) ;
F_78 ( & V_2 -> V_33 ) ;
}
static struct V_3 * F_86 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_3 * V_4 ;
V_15 = & V_2 -> V_16 [ V_2 -> V_17 ] ;
if ( ! F_4 ( V_15 ) ) {
V_4 = F_32 ( V_15 -> V_29 , struct V_3 , V_7 . V_8 . V_10 ) ;
if ( V_2 -> V_19 == V_4 -> V_18 ) {
if ( -- V_2 -> V_21 )
goto V_64;
F_14 ( & V_4 -> V_7 . V_8 . V_10 , V_15 ) ;
}
goto V_65;
}
do {
if ( V_15 == & V_2 -> V_16 [ 0 ] )
V_15 = & V_2 -> V_16 [ V_2 -> V_23 ] ;
else
V_15 = V_15 - 1 ;
if ( ! F_4 ( V_15 ) ) {
V_4 = F_32 ( V_15 -> V_29 , struct V_3 , V_7 . V_8 . V_10 ) ;
goto V_66;
}
} while ( V_15 != & V_2 -> V_16 [ V_2 -> V_17 ] );
F_17 ( V_2 ) ;
return NULL ;
V_66:
F_15 ( V_2 , ( unsigned int ) ( V_15 - & V_2 -> V_16 [ 0 ] ) ) ;
V_65:
F_16 ( V_2 , V_4 -> V_18 ) ;
V_64:
return V_4 ;
}
static struct V_3 * F_87 ( struct V_1 * V_2 )
{
if ( F_26 ( V_2 ) )
return F_86 ( V_2 ) ;
if ( ! F_4 ( & V_2 -> V_16 [ 0 ] ) )
return F_13 ( & V_2 -> V_16 [ 0 ] , struct V_3 , V_7 . V_8 . V_10 ) ;
return NULL ;
}
struct V_3 * F_88 ( struct V_1 * V_2 ,
bool (* F_89)( struct V_3 * , void * ) , void * V_67 )
{
struct V_3 * V_4 = NULL ;
F_2 ( L_9 ,
V_2 , F_30 ( V_2 ) ) ;
F_77 ( & V_2 -> V_33 ) ;
V_4 = F_87 ( V_2 ) ;
if ( V_4 != NULL ) {
if ( F_89 ( V_4 , V_67 ) )
F_83 ( V_2 , V_4 ) ;
else
V_4 = NULL ;
}
F_78 ( & V_2 -> V_33 ) ;
return V_4 ;
}
static bool F_90 ( struct V_3 * V_4 , void * V_67 )
{
return true ;
}
struct V_3 * F_91 ( struct V_1 * V_2 )
{
return F_88 ( V_2 , F_90 , NULL ) ;
}
void F_92 ( struct V_1 * V_2 )
{
struct V_14 * V_68 ;
F_77 ( & V_2 -> V_33 ) ;
V_68 = & V_2 -> V_16 [ V_2 -> V_23 ] ;
for (; ; ) {
while ( ! F_4 ( V_68 ) ) {
struct V_3 * V_4 ;
V_4 = F_13 ( V_68 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
F_83 ( V_2 , V_4 ) ;
}
if ( V_68 == & V_2 -> V_16 [ 0 ] )
break;
V_68 -- ;
}
F_78 ( & V_2 -> V_33 ) ;
}
void F_93 ( struct V_1 * V_2 , int V_69 )
{
struct V_14 * V_68 ;
F_77 ( & V_2 -> V_33 ) ;
V_68 = & V_2 -> V_16 [ V_2 -> V_23 ] ;
for (; ; ) {
while ( ! F_4 ( V_68 ) ) {
struct V_3 * V_4 ;
V_4 = F_13 ( V_68 ,
struct V_3 ,
V_7 . V_8 . V_10 ) ;
V_4 -> V_59 = V_69 ;
F_83 ( V_2 , V_4 ) ;
}
if ( V_68 == & V_2 -> V_16 [ 0 ] )
break;
V_68 -- ;
}
F_78 ( & V_2 -> V_33 ) ;
}
static void V_34 ( unsigned long V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
struct V_3 * V_4 , * V_71 ;
unsigned long V_12 , V_72 , V_73 ;
F_94 ( & V_2 -> V_33 ) ;
V_12 = V_72 = V_13 ;
F_95 (task, n, &queue->timer_list.list, u.tk_wait.timer_list) {
V_73 = V_4 -> V_7 . V_8 . V_12 ;
if ( F_96 ( V_72 , V_73 ) ) {
F_2 ( L_10 , V_4 -> V_6 ) ;
V_4 -> V_59 = - V_74 ;
F_83 ( V_2 , V_4 ) ;
continue;
}
if ( V_12 == V_72 || F_97 ( V_12 , V_73 ) )
V_12 = V_73 ;
}
if ( ! F_4 ( & V_2 -> V_9 . V_10 ) )
F_6 ( V_2 , V_12 ) ;
F_98 ( & V_2 -> V_33 ) ;
}
static void F_99 ( struct V_3 * V_4 )
{
if ( V_4 -> V_59 == - V_74 )
V_4 -> V_59 = 0 ;
}
void F_100 ( struct V_3 * V_4 , unsigned long V_75 )
{
V_4 -> V_5 = V_75 ;
F_74 ( & V_76 , V_4 , F_99 ) ;
}
void F_101 ( struct V_3 * V_4 )
{
V_4 -> V_77 -> V_78 ( V_4 , V_4 -> V_79 ) ;
}
static void
F_102 ( struct V_3 * V_4 )
{
V_4 -> V_80 = 2 ;
V_4 -> V_81 = 2 ;
V_4 -> V_82 = 2 ;
V_4 -> V_83 = F_103 () ;
}
static void
F_104 ( struct V_3 * V_4 )
{
V_4 -> V_84 = 0 ;
V_4 -> V_85 &= ~ ( V_86 | V_87 | V_88 ) ;
F_102 ( V_4 ) ;
}
void F_105 ( struct V_3 * V_4 )
{
V_4 -> V_89 = NULL ;
if ( V_4 -> V_77 -> V_90 != NULL ) {
V_4 -> V_77 -> V_90 ( V_4 , V_4 -> V_79 ) ;
if ( V_4 -> V_89 != NULL ) {
F_106 ( F_107 ( V_4 ) ) ;
F_108 ( V_4 ) ;
F_104 ( V_4 ) ;
}
}
}
void F_109 ( struct V_3 * V_4 , int V_69 )
{
V_4 -> V_59 = V_69 ;
V_4 -> V_89 = F_105 ;
if ( F_25 ( V_4 ) )
F_85 ( V_4 -> V_27 , V_4 ) ;
}
void F_110 ( const struct V_91 * V_92 , void * V_93 )
{
if ( V_92 -> V_94 != NULL )
V_92 -> V_94 ( V_93 ) ;
}
static void F_111 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_95 = F_68 ( V_4 ) ;
int V_69 = 0 ;
F_2 ( L_11 ,
V_4 -> V_6 , V_4 -> V_85 ) ;
F_24 ( F_25 ( V_4 ) ) ;
if ( F_25 ( V_4 ) )
return;
for (; ; ) {
void (* F_112)( struct V_3 * );
F_112 = V_4 -> V_58 ;
V_4 -> V_58 = NULL ;
if ( F_112 == NULL ) {
F_112 = V_4 -> V_89 ;
if ( F_112 == NULL )
break;
}
F_113 ( V_4 -> V_41 , V_4 , V_4 -> V_89 ) ;
F_112 ( V_4 ) ;
if ( ! F_25 ( V_4 ) )
continue;
V_2 = V_4 -> V_27 ;
F_77 ( & V_2 -> V_33 ) ;
if ( ! F_25 ( V_4 ) ) {
F_78 ( & V_2 -> V_33 ) ;
continue;
}
F_114 ( V_4 ) ;
F_78 ( & V_2 -> V_33 ) ;
if ( V_95 )
return;
F_2 ( L_12 , V_4 -> V_6 ) ;
V_69 = F_64 ( & V_4 -> V_43 ,
V_57 , F_45 ,
V_52 ) ;
if ( V_69 == - V_39 ) {
F_2 ( L_13 , V_4 -> V_6 ) ;
V_4 -> V_85 |= V_87 ;
F_109 ( V_4 , - V_39 ) ;
}
F_2 ( L_14 , V_4 -> V_6 ) ;
}
F_2 ( L_15 , V_4 -> V_6 , V_69 ,
V_4 -> V_59 ) ;
F_115 ( V_4 ) ;
}
void F_116 ( struct V_3 * V_4 )
{
bool V_96 = F_68 ( V_4 ) ;
F_50 ( V_4 ) ;
F_65 ( V_4 ) ;
if ( ! V_96 )
F_111 ( V_4 ) ;
}
static void V_55 ( struct V_97 * V_98 )
{
F_111 ( F_117 ( V_98 , struct V_3 , V_7 . V_54 ) ) ;
}
void * F_118 ( struct V_3 * V_4 , T_6 V_99 )
{
struct V_100 * V_101 ;
T_7 V_102 = V_103 | V_104 ;
if ( F_27 ( V_4 ) )
V_102 = V_105 | V_106 | V_104 ;
V_99 += sizeof( struct V_100 ) ;
if ( V_99 <= V_107 )
V_101 = F_119 ( V_108 , V_102 ) ;
else
V_101 = F_120 ( V_99 , V_102 ) ;
if ( ! V_101 )
return NULL ;
V_101 -> V_109 = V_99 ;
F_2 ( L_16 ,
V_4 -> V_6 , V_99 , V_101 ) ;
return & V_101 -> V_67 ;
}
void F_121 ( void * V_110 )
{
T_6 V_99 ;
struct V_100 * V_101 ;
if ( ! V_110 )
return;
V_101 = F_117 ( V_110 , struct V_100 , V_67 ) ;
V_99 = V_101 -> V_109 ;
F_2 ( L_17 ,
V_99 , V_101 ) ;
if ( V_99 <= V_107 )
F_122 ( V_101 , V_108 ) ;
else
F_123 ( V_101 ) ;
}
static void F_124 ( struct V_3 * V_4 , const struct V_111 * V_112 )
{
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
F_125 ( & V_4 -> V_49 , 1 ) ;
V_4 -> V_85 = V_112 -> V_47 ;
V_4 -> V_77 = V_112 -> V_113 ;
V_4 -> V_79 = V_112 -> V_114 ;
F_19 ( & V_4 -> V_115 ) ;
V_4 -> V_61 = V_112 -> V_17 - V_62 ;
V_4 -> V_18 = V_38 -> V_116 ;
V_4 -> V_117 = V_112 -> V_118 ;
if ( V_4 -> V_77 -> V_78 != NULL )
V_4 -> V_89 = F_101 ;
F_102 ( V_4 ) ;
F_2 ( L_18 ,
F_126 ( V_38 ) ) ;
}
static struct V_3 *
F_127 ( void )
{
return (struct V_3 * ) F_119 ( V_119 , V_103 ) ;
}
struct V_3 * F_128 ( const struct V_111 * V_120 )
{
struct V_3 * V_4 = V_120 -> V_4 ;
unsigned short V_47 = 0 ;
if ( V_4 == NULL ) {
V_4 = F_127 () ;
if ( V_4 == NULL ) {
F_110 ( V_120 -> V_113 ,
V_120 -> V_114 ) ;
return F_129 ( - V_121 ) ;
}
V_47 = V_122 ;
}
F_124 ( V_4 , V_120 ) ;
V_4 -> V_85 |= V_47 ;
F_2 ( L_19 , V_4 ) ;
return V_4 ;
}
static void F_130 ( struct V_3 * V_4 )
{
unsigned short V_85 = V_4 -> V_85 ;
F_110 ( V_4 -> V_77 , V_4 -> V_79 ) ;
if ( V_85 & V_122 ) {
F_2 ( L_20 , V_4 -> V_6 ) ;
F_122 ( V_4 , V_119 ) ;
}
}
static void F_131 ( struct V_97 * V_98 )
{
F_130 ( F_117 ( V_98 , struct V_3 , V_7 . V_54 ) ) ;
}
static void F_132 ( struct V_3 * V_4 )
{
F_108 ( V_4 ) ;
if ( V_4 -> V_123 . V_124 ) {
F_133 ( V_4 -> V_123 . V_124 ) ;
V_4 -> V_123 . V_124 = NULL ;
}
F_134 ( V_4 ) ;
}
static void F_135 ( struct V_3 * V_4 ,
struct V_125 * V_15 )
{
if ( V_15 != NULL ) {
F_69 ( & V_4 -> V_7 . V_54 , F_131 ) ;
F_70 ( V_15 , & V_4 -> V_7 . V_54 ) ;
} else
F_130 ( V_4 ) ;
}
static void F_136 ( struct V_3 * V_4 , struct V_125 * V_15 )
{
if ( F_59 ( & V_4 -> V_49 ) ) {
F_132 ( V_4 ) ;
F_135 ( V_4 , V_15 ) ;
}
}
void F_137 ( struct V_3 * V_4 )
{
F_136 ( V_4 , NULL ) ;
}
void F_76 ( struct V_3 * V_4 )
{
F_136 ( V_4 , V_4 -> V_117 ) ;
}
static void F_115 ( struct V_3 * V_4 )
{
F_2 ( L_21 , V_4 -> V_6 ) ;
F_24 ( F_25 ( V_4 ) ) ;
F_132 ( V_4 ) ;
if ( F_138 ( & V_4 -> V_49 ) != 1 + ! F_68 ( V_4 ) ) {
if ( ! F_53 ( V_4 ) )
return;
} else {
if ( ! F_59 ( & V_4 -> V_49 ) )
return;
}
F_135 ( V_4 , V_4 -> V_117 ) ;
}
int F_139 ( void )
{
return F_140 ( V_126 ) ? 0 : - V_127 ;
}
void F_141 ( void )
{
F_142 ( V_126 ) ;
}
static int F_143 ( void )
{
struct V_125 * V_45 ;
F_2 ( L_22 ) ;
V_45 = F_144 ( L_23 , V_128 | V_129 , 0 ) ;
V_56 = V_45 ;
return V_56 != NULL ;
}
static void F_145 ( void )
{
struct V_125 * V_45 = NULL ;
if ( V_56 == NULL )
return;
F_2 ( L_24 ) ;
V_45 = V_56 ;
V_56 = NULL ;
F_146 ( V_45 ) ;
}
void
F_147 ( void )
{
F_145 () ;
F_148 ( V_108 ) ;
F_148 ( V_119 ) ;
F_149 ( V_130 ) ;
F_149 ( V_131 ) ;
F_43 ( & V_76 ) ;
}
int
F_150 ( void )
{
F_42 ( & V_76 , L_25 ) ;
if ( ! F_143 () )
goto V_132;
V_130 = F_151 ( L_26 ,
sizeof( struct V_3 ) ,
0 , V_133 ,
NULL ) ;
if ( ! V_130 )
goto V_132;
V_131 = F_151 ( L_27 ,
V_107 ,
0 , V_133 ,
NULL ) ;
if ( ! V_131 )
goto V_132;
V_119 = F_152 ( V_134 ,
V_130 ) ;
if ( ! V_119 )
goto V_132;
V_108 = F_152 ( V_135 ,
V_131 ) ;
if ( ! V_108 )
goto V_132;
return 0 ;
V_132:
F_147 () ;
return - V_121 ;
}
