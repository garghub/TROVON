static int F_1 ( struct V_1 * V_2 , const unsigned long V_3 ,
const char * const * V_4 , int V_5 )
{
bool V_6 = false ;
int V_7 ;
for ( V_7 = 0 ; V_7 < sizeof( V_3 ) * V_8 ; V_7 ++ ) {
if ( ! ( V_3 & F_2 ( V_7 ) ) )
continue;
if ( V_6 )
F_3 ( V_2 , L_1 ) ;
V_6 = true ;
if ( V_7 < V_5 && V_4 [ V_7 ] )
F_3 ( V_2 , V_4 [ V_7 ] ) ;
else
F_4 ( V_2 , L_2 , V_7 ) ;
}
return 0 ;
}
static int F_5 ( void * V_9 , struct V_1 * V_2 )
{
struct V_10 * V_11 = V_9 ;
F_1 ( V_2 , V_11 -> V_12 , V_13 ,
F_6 ( V_13 ) ) ;
F_3 ( V_2 , L_3 ) ;
return 0 ;
}
static T_1 F_7 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_10 * V_11 = V_9 ;
char V_17 [ 16 ] = { } , * V_18 ;
if ( F_8 ( V_11 ) )
return - V_19 ;
if ( V_15 >= sizeof( V_17 ) ) {
F_9 ( L_4 , V_20 ) ;
goto V_21;
}
if ( F_10 ( V_17 , V_14 , V_15 ) )
return - V_22 ;
V_18 = F_11 ( V_17 ) ;
if ( strcmp ( V_18 , L_5 ) == 0 ) {
F_12 ( V_11 , true ) ;
} else if ( strcmp ( V_18 , L_6 ) == 0 ) {
F_13 ( V_11 , true ) ;
} else if ( strcmp ( V_18 , L_7 ) == 0 ) {
F_14 ( V_11 ) ;
} else {
F_9 ( L_8 , V_20 , V_18 ) ;
V_21:
F_9 ( L_9 , V_20 ) ;
return - V_23 ;
}
return V_15 ;
}
static void F_15 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
if ( V_25 -> V_26 ) {
F_4 ( V_2 , L_10 ,
V_25 -> V_26 , V_25 -> V_27 , V_25 -> V_28 , V_25 -> V_29 ) ;
} else {
F_3 ( V_2 , L_11 ) ;
}
}
static int F_16 ( void * V_9 , struct V_1 * V_2 )
{
struct V_10 * V_11 = V_9 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_30 ; V_7 ++ )
F_4 ( V_2 , L_12 , V_7 , V_11 -> V_31 [ V_7 ] ) ;
return 0 ;
}
static T_1 F_17 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_10 * V_11 = V_9 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_30 ; V_7 ++ )
V_11 -> V_31 [ V_7 ] = 0 ;
return V_15 ;
}
static int F_18 ( void * V_9 , struct V_1 * V_2 )
{
struct V_10 * V_11 = V_9 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 / 2 ; V_32 ++ ) {
F_4 ( V_2 , L_13 , 1 << ( 9 + V_32 ) ) ;
F_15 ( V_2 , & V_11 -> V_34 [ 2 * V_32 ] ) ;
F_3 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_14 , 1 << ( 9 + V_32 ) ) ;
F_15 ( V_2 , & V_11 -> V_34 [ 2 * V_32 + 1 ] ) ;
F_3 ( V_2 , L_3 ) ;
}
return 0 ;
}
static int F_19 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
F_1 ( V_2 , V_36 -> V_37 , V_38 ,
F_6 ( V_38 ) ) ;
F_3 ( V_2 , L_3 ) ;
return 0 ;
}
static int F_20 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
const int V_39 = F_21 ( V_36 -> V_3 ) ;
F_3 ( V_2 , L_15 ) ;
if ( V_39 < F_6 ( V_40 ) &&
V_40 [ V_39 ] )
F_3 ( V_2 , V_40 [ V_39 ] ) ;
else
F_4 ( V_2 , L_2 , V_39 ) ;
F_3 ( V_2 , L_16 ) ;
F_1 ( V_2 ,
V_36 -> V_3 ^ F_22 ( V_39 ) ,
V_41 , F_6 ( V_41 ) ) ;
F_3 ( V_2 , L_3 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , struct V_42 * V_43 )
{
const struct V_44 * const V_45 = V_43 -> V_11 -> V_45 ;
const unsigned int V_18 = V_43 -> V_46 & V_47 ;
F_4 ( V_2 , L_17 , V_43 ) ;
if ( V_18 < F_6 ( V_48 ) && V_48 [ V_18 ] )
F_4 ( V_2 , L_18 , V_48 [ V_18 ] ) ;
else
F_4 ( V_2 , L_2 , V_18 ) ;
F_3 ( V_2 , L_19 ) ;
F_1 ( V_2 , V_43 -> V_46 & ~ V_47 , V_49 ,
F_6 ( V_49 ) ) ;
F_3 ( V_2 , L_20 ) ;
F_1 ( V_2 , ( V_50 unsigned int ) V_43 -> V_51 , V_52 ,
F_6 ( V_52 ) ) ;
F_3 ( V_2 , L_21 ) ;
F_1 ( V_2 , V_43 -> V_53 , V_54 , F_6 ( V_54 ) ) ;
F_4 ( V_2 , L_22 , V_43 -> V_55 ,
V_43 -> V_56 ) ;
if ( V_45 -> V_57 )
V_45 -> V_57 ( V_2 , V_43 ) ;
F_3 ( V_2 , L_23 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , void * V_58 )
{
return F_23 ( V_2 , F_25 ( V_58 ) ) ;
}
static void * F_26 ( struct V_1 * V_2 , T_4 * V_59 )
__acquires( &q->requeue_lock
static void * F_27 ( struct V_1 * V_2 , void * V_58 , T_4 * V_59 )
{
struct V_10 * V_11 = V_2 -> V_60 ;
return F_28 ( V_58 , & V_11 -> V_61 , V_59 ) ;
}
static void F_29 ( struct V_1 * V_2 , void * V_58 )
__releases( &q->requeue_lock
static void * F_30 ( struct V_1 * V_2 , T_4 * V_59 )
__acquires( &hctx->lock
static void * F_31 ( struct V_1 * V_2 , void * V_58 , T_4 * V_59 )
{
struct V_35 * V_36 = V_2 -> V_60 ;
return F_28 ( V_58 , & V_36 -> V_62 , V_59 ) ;
}
static void F_32 ( struct V_1 * V_2 , void * V_58 )
__releases( &hctx->lock
static void F_33 ( struct V_42 * V_43 , void * V_9 , bool V_63 )
{
const struct V_64 * V_65 = V_9 ;
if ( F_34 ( V_43 -> V_11 , V_43 -> V_66 -> V_67 ) == V_65 -> V_36 &&
F_35 ( V_68 , & V_43 -> V_53 ) )
F_23 ( V_65 -> V_2 ,
F_25 ( & V_43 -> V_69 ) ) ;
}
static int F_36 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
struct V_64 V_65 = { . V_2 = V_2 , . V_36 = V_36 } ;
F_37 ( V_36 -> V_70 -> V_71 , F_33 ,
& V_65 ) ;
return 0 ;
}
static int F_38 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
F_39 ( & V_36 -> V_72 , V_2 ) ;
return 0 ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
F_4 ( V_2 , L_24 , V_74 -> V_75 ) ;
F_4 ( V_2 , L_25 , V_74 -> V_76 ) ;
F_4 ( V_2 , L_26 ,
F_41 ( & V_74 -> V_77 ) ) ;
F_3 ( V_2 , L_27 ) ;
F_42 ( & V_74 -> V_78 , V_2 ) ;
if ( V_74 -> V_76 ) {
F_3 ( V_2 , L_28 ) ;
F_42 ( & V_74 -> V_79 , V_2 ) ;
}
}
static int F_43 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
struct V_10 * V_11 = V_36 -> V_70 ;
int V_80 ;
V_80 = F_44 ( & V_11 -> V_81 ) ;
if ( V_80 )
goto V_82;
if ( V_36 -> V_74 )
F_40 ( V_2 , V_36 -> V_74 ) ;
F_45 ( & V_11 -> V_81 ) ;
V_82:
return V_80 ;
}
static int F_46 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
struct V_10 * V_11 = V_36 -> V_70 ;
int V_80 ;
V_80 = F_44 ( & V_11 -> V_81 ) ;
if ( V_80 )
goto V_82;
if ( V_36 -> V_74 )
F_39 ( & V_36 -> V_74 -> V_78 . V_83 , V_2 ) ;
F_45 ( & V_11 -> V_81 ) ;
V_82:
return V_80 ;
}
static int F_47 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
struct V_10 * V_11 = V_36 -> V_70 ;
int V_80 ;
V_80 = F_44 ( & V_11 -> V_81 ) ;
if ( V_80 )
goto V_82;
if ( V_36 -> V_84 )
F_40 ( V_2 , V_36 -> V_84 ) ;
F_45 ( & V_11 -> V_81 ) ;
V_82:
return V_80 ;
}
static int F_48 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
struct V_10 * V_11 = V_36 -> V_70 ;
int V_80 ;
V_80 = F_44 ( & V_11 -> V_81 ) ;
if ( V_80 )
goto V_82;
if ( V_36 -> V_84 )
F_39 ( & V_36 -> V_84 -> V_78 . V_83 , V_2 ) ;
F_45 ( & V_11 -> V_81 ) ;
V_82:
return V_80 ;
}
static int F_49 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
F_4 ( V_2 , L_29 , V_36 -> V_85 ) ;
F_4 ( V_2 , L_30 , V_36 -> V_86 ) ;
F_4 ( V_2 , L_31 , V_36 -> V_87 ) ;
return 0 ;
}
static T_1 F_50 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_35 * V_36 = V_9 ;
V_36 -> V_85 = V_36 -> V_86 = V_36 -> V_87 = 0 ;
return V_15 ;
}
static int F_51 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
int V_7 ;
F_4 ( V_2 , L_32 , 0U , V_36 -> V_88 [ 0 ] ) ;
for ( V_7 = 1 ; V_7 < V_89 - 1 ; V_7 ++ ) {
unsigned int V_90 = 1U << ( V_7 - 1 ) ;
F_4 ( V_2 , L_32 , V_90 , V_36 -> V_88 [ V_7 ] ) ;
}
F_4 ( V_2 , L_33 , 1U << ( V_7 - 1 ) , V_36 -> V_88 [ V_7 ] ) ;
return 0 ;
}
static T_1 F_52 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_35 * V_36 = V_9 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_89 ; V_7 ++ )
V_36 -> V_88 [ V_7 ] = 0 ;
return V_15 ;
}
static int F_53 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
F_4 ( V_2 , L_34 , V_36 -> V_91 ) ;
return 0 ;
}
static T_1 F_54 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_35 * V_36 = V_9 ;
V_36 -> V_91 = 0 ;
return V_15 ;
}
static int F_55 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
F_4 ( V_2 , L_34 , V_36 -> V_92 ) ;
return 0 ;
}
static T_1 F_56 ( void * V_9 , const char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
struct V_35 * V_36 = V_9 ;
V_36 -> V_92 = 0 ;
return V_15 ;
}
static int F_57 ( void * V_9 , struct V_1 * V_2 )
{
struct V_35 * V_36 = V_9 ;
F_4 ( V_2 , L_35 , F_41 ( & V_36 -> V_93 ) ) ;
return 0 ;
}
static void * F_58 ( struct V_1 * V_2 , T_4 * V_59 )
__acquires( &ctx->lock
static void * F_59 ( struct V_1 * V_2 , void * V_58 , T_4 * V_59 )
{
struct V_94 * V_95 = V_2 -> V_60 ;
return F_28 ( V_58 , & V_95 -> V_96 , V_59 ) ;
}
static void F_60 ( struct V_1 * V_2 , void * V_58 )
__releases( &ctx->lock
static int F_61 ( void * V_9 , struct V_1 * V_2 )
{
struct V_94 * V_95 = V_9 ;
F_4 ( V_2 , L_36 , V_95 -> V_97 [ 1 ] , V_95 -> V_97 [ 0 ] ) ;
return 0 ;
}
static T_1 F_62 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_94 * V_95 = V_9 ;
V_95 -> V_97 [ 0 ] = V_95 -> V_97 [ 1 ] = 0 ;
return V_15 ;
}
static int F_63 ( void * V_9 , struct V_1 * V_2 )
{
struct V_94 * V_95 = V_9 ;
F_4 ( V_2 , L_34 , V_95 -> V_98 ) ;
return 0 ;
}
static T_1 F_64 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_94 * V_95 = V_9 ;
V_95 -> V_98 = 0 ;
return V_15 ;
}
static int F_65 ( void * V_9 , struct V_1 * V_2 )
{
struct V_94 * V_95 = V_9 ;
F_4 ( V_2 , L_36 , V_95 -> V_99 [ 1 ] , V_95 -> V_99 [ 0 ] ) ;
return 0 ;
}
static T_1 F_66 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_94 * V_95 = V_9 ;
V_95 -> V_99 [ 0 ] = V_95 -> V_99 [ 1 ] = 0 ;
return V_15 ;
}
static int F_67 ( struct V_1 * V_2 , void * V_58 )
{
const struct V_100 * V_101 = V_2 -> V_60 ;
void * V_9 = F_68 ( V_2 -> V_102 -> V_103 . V_104 -> V_105 ) -> V_106 ;
return V_101 -> V_107 ( V_9 , V_2 ) ;
}
static T_1 F_69 ( struct V_102 * V_102 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_1 * V_2 = V_102 -> V_108 ;
const struct V_100 * V_101 = V_2 -> V_60 ;
void * V_9 = F_68 ( V_102 -> V_103 . V_104 -> V_105 ) -> V_106 ;
if ( ! V_101 -> V_109 )
return - V_110 ;
return V_101 -> V_109 ( V_9 , V_14 , V_15 , V_16 ) ;
}
static int F_70 ( struct V_111 * V_111 , struct V_102 * V_102 )
{
const struct V_100 * V_101 = V_111 -> V_106 ;
void * V_9 = F_68 ( V_102 -> V_103 . V_104 -> V_105 ) -> V_106 ;
struct V_1 * V_2 ;
int V_112 ;
if ( V_101 -> V_113 ) {
V_112 = F_71 ( V_102 , V_101 -> V_113 ) ;
if ( ! V_112 ) {
V_2 = V_102 -> V_108 ;
V_2 -> V_60 = V_9 ;
}
return V_112 ;
}
if ( F_72 ( ! V_101 -> V_107 ) )
return - V_110 ;
return F_73 ( V_102 , F_67 , V_111 -> V_106 ) ;
}
static int F_74 ( struct V_111 * V_111 , struct V_102 * V_102 )
{
const struct V_100 * V_101 = V_111 -> V_106 ;
if ( V_101 -> V_107 )
return F_75 ( V_111 , V_102 ) ;
else
return F_76 ( V_111 , V_102 ) ;
}
static bool F_77 ( struct V_104 * V_114 , void * V_9 ,
const struct V_100 * V_101 )
{
F_68 ( V_114 ) -> V_106 = V_9 ;
for (; V_101 -> V_115 ; V_101 ++ ) {
if ( ! F_78 ( V_101 -> V_115 , V_101 -> V_116 , V_114 ,
( void * ) V_101 , & V_117 ) )
return false ;
}
return true ;
}
int F_79 ( struct V_10 * V_11 )
{
struct V_35 * V_36 ;
int V_7 ;
if ( ! V_118 )
return - V_19 ;
V_11 -> V_119 = F_80 ( F_81 ( V_11 -> V_120 . V_114 ) ,
V_118 ) ;
if ( ! V_11 -> V_119 )
return - V_121 ;
if ( ! F_77 ( V_11 -> V_119 , V_11 ,
V_122 ) )
goto V_123;
F_82 (q, hctx, i) {
if ( ! V_36 -> V_119 && F_83 ( V_11 , V_36 ) )
goto V_123;
if ( V_11 -> V_124 && ! V_36 -> V_125 &&
F_84 ( V_11 , V_36 ) )
goto V_123;
}
return 0 ;
V_123:
F_85 ( V_11 ) ;
return - V_121 ;
}
void F_85 ( struct V_10 * V_11 )
{
F_86 ( V_11 -> V_119 ) ;
V_11 -> V_125 = NULL ;
V_11 -> V_119 = NULL ;
}
static int F_87 ( struct V_35 * V_36 ,
struct V_94 * V_95 )
{
struct V_104 * V_126 ;
char V_115 [ 20 ] ;
snprintf ( V_115 , sizeof( V_115 ) , L_37 , V_95 -> V_67 ) ;
V_126 = F_80 ( V_115 , V_36 -> V_119 ) ;
if ( ! V_126 )
return - V_121 ;
if ( ! F_77 ( V_126 , V_95 , V_127 ) )
return - V_121 ;
return 0 ;
}
int F_83 ( struct V_10 * V_11 ,
struct V_35 * V_36 )
{
struct V_94 * V_95 ;
char V_115 [ 20 ] ;
int V_7 ;
if ( ! V_11 -> V_119 )
return - V_19 ;
snprintf ( V_115 , sizeof( V_115 ) , L_38 , V_36 -> V_128 ) ;
V_36 -> V_119 = F_80 ( V_115 , V_11 -> V_119 ) ;
if ( ! V_36 -> V_119 )
return - V_121 ;
if ( ! F_77 ( V_36 -> V_119 , V_36 ,
V_129 ) )
goto V_123;
F_88 (hctx, ctx, i) {
if ( F_87 ( V_36 , V_95 ) )
goto V_123;
}
return 0 ;
V_123:
F_89 ( V_36 ) ;
return - V_121 ;
}
void F_89 ( struct V_35 * V_36 )
{
F_86 ( V_36 -> V_119 ) ;
V_36 -> V_125 = NULL ;
V_36 -> V_119 = NULL ;
}
int F_90 ( struct V_10 * V_11 )
{
struct V_35 * V_36 ;
int V_7 ;
F_82 (q, hctx, i) {
if ( F_83 ( V_11 , V_36 ) )
return - V_121 ;
}
return 0 ;
}
void F_91 ( struct V_10 * V_11 )
{
struct V_35 * V_36 ;
int V_7 ;
F_82 (q, hctx, i)
F_89 ( V_36 ) ;
}
int F_92 ( struct V_10 * V_11 )
{
struct V_130 * V_131 = V_11 -> V_124 -> type ;
if ( ! V_11 -> V_119 )
return - V_19 ;
if ( ! V_131 -> V_132 )
return 0 ;
V_11 -> V_125 = F_80 ( L_39 , V_11 -> V_119 ) ;
if ( ! V_11 -> V_125 )
return - V_121 ;
if ( ! F_77 ( V_11 -> V_125 , V_11 ,
V_131 -> V_132 ) )
goto V_123;
return 0 ;
V_123:
F_93 ( V_11 ) ;
return - V_121 ;
}
void F_93 ( struct V_10 * V_11 )
{
F_86 ( V_11 -> V_125 ) ;
V_11 -> V_125 = NULL ;
}
int F_84 ( struct V_10 * V_11 ,
struct V_35 * V_36 )
{
struct V_130 * V_131 = V_11 -> V_124 -> type ;
if ( ! V_36 -> V_119 )
return - V_19 ;
if ( ! V_131 -> V_133 )
return 0 ;
V_36 -> V_125 = F_80 ( L_39 ,
V_36 -> V_119 ) ;
if ( ! V_36 -> V_125 )
return - V_121 ;
if ( ! F_77 ( V_36 -> V_125 , V_36 ,
V_131 -> V_133 ) )
return - V_121 ;
return 0 ;
}
void F_94 ( struct V_35 * V_36 )
{
F_86 ( V_36 -> V_125 ) ;
V_36 -> V_125 = NULL ;
}
