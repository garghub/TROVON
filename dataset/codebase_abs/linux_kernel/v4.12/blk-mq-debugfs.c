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
} else {
F_9 ( L_7 , V_20 , V_18 ) ;
V_21:
F_9 ( L_8 , V_20 ) ;
return - V_23 ;
}
return V_15 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
if ( V_25 -> V_26 ) {
F_4 ( V_2 , L_9 ,
V_25 -> V_26 , V_25 -> V_27 , V_25 -> V_28 , V_25 -> V_29 ) ;
} else {
F_3 ( V_2 , L_10 ) ;
}
}
static int F_15 ( void * V_9 , struct V_1 * V_2 )
{
struct V_10 * V_11 = V_9 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 / 2 ; V_30 ++ ) {
F_4 ( V_2 , L_11 , 1 << ( 9 + V_30 ) ) ;
F_14 ( V_2 , & V_11 -> V_32 [ 2 * V_30 ] ) ;
F_3 ( V_2 , L_3 ) ;
F_4 ( V_2 , L_12 , 1 << ( 9 + V_30 ) ) ;
F_14 ( V_2 , & V_11 -> V_32 [ 2 * V_30 + 1 ] ) ;
F_3 ( V_2 , L_3 ) ;
}
return 0 ;
}
static int F_16 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
F_1 ( V_2 , V_34 -> V_35 , V_36 ,
F_6 ( V_36 ) ) ;
F_3 ( V_2 , L_3 ) ;
return 0 ;
}
static int F_17 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
const int V_37 = F_18 ( V_34 -> V_3 ) ;
F_3 ( V_2 , L_13 ) ;
if ( V_37 < F_6 ( V_38 ) &&
V_38 [ V_37 ] )
F_3 ( V_2 , V_38 [ V_37 ] ) ;
else
F_4 ( V_2 , L_2 , V_37 ) ;
F_3 ( V_2 , L_14 ) ;
F_1 ( V_2 ,
V_34 -> V_3 ^ F_19 ( V_37 ) ,
V_39 , F_6 ( V_39 ) ) ;
F_3 ( V_2 , L_3 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
const struct V_42 * const V_43 = V_41 -> V_11 -> V_43 ;
const unsigned int V_18 = V_41 -> V_44 & V_45 ;
F_4 ( V_2 , L_15 , V_41 ) ;
if ( V_18 < F_6 ( V_46 ) && V_46 [ V_18 ] )
F_4 ( V_2 , L_16 , V_46 [ V_18 ] ) ;
else
F_4 ( V_2 , L_2 , V_18 ) ;
F_3 ( V_2 , L_17 ) ;
F_1 ( V_2 , V_41 -> V_44 & ~ V_45 , V_47 ,
F_6 ( V_47 ) ) ;
F_3 ( V_2 , L_18 ) ;
F_1 ( V_2 , ( V_48 unsigned int ) V_41 -> V_49 , V_50 ,
F_6 ( V_50 ) ) ;
F_4 ( V_2 , L_19 , V_41 -> V_51 ,
V_41 -> V_52 ) ;
if ( V_43 -> V_53 )
V_43 -> V_53 ( V_2 , V_41 ) ;
F_3 ( V_2 , L_20 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , void * V_54 )
{
return F_20 ( V_2 , F_22 ( V_54 ) ) ;
}
static void * F_23 ( struct V_1 * V_2 , T_4 * V_55 )
__acquires( &hctx->lock
static void * F_24 ( struct V_1 * V_2 , void * V_54 , T_4 * V_55 )
{
struct V_33 * V_34 = V_2 -> V_56 ;
return F_25 ( V_54 , & V_34 -> V_57 , V_55 ) ;
}
static void F_26 ( struct V_1 * V_2 , void * V_54 )
__releases( &hctx->lock
static int F_27 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
F_28 ( & V_34 -> V_58 , V_2 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
F_4 ( V_2 , L_21 , V_60 -> V_61 ) ;
F_4 ( V_2 , L_22 , V_60 -> V_62 ) ;
F_4 ( V_2 , L_23 ,
F_30 ( & V_60 -> V_63 ) ) ;
F_3 ( V_2 , L_24 ) ;
F_31 ( & V_60 -> V_64 , V_2 ) ;
if ( V_60 -> V_62 ) {
F_3 ( V_2 , L_25 ) ;
F_31 ( & V_60 -> V_65 , V_2 ) ;
}
}
static int F_32 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
struct V_10 * V_11 = V_34 -> V_66 ;
int V_67 ;
V_67 = F_33 ( & V_11 -> V_68 ) ;
if ( V_67 )
goto V_69;
if ( V_34 -> V_60 )
F_29 ( V_2 , V_34 -> V_60 ) ;
F_34 ( & V_11 -> V_68 ) ;
V_69:
return V_67 ;
}
static int F_35 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
struct V_10 * V_11 = V_34 -> V_66 ;
int V_67 ;
V_67 = F_33 ( & V_11 -> V_68 ) ;
if ( V_67 )
goto V_69;
if ( V_34 -> V_60 )
F_28 ( & V_34 -> V_60 -> V_64 . V_70 , V_2 ) ;
F_34 ( & V_11 -> V_68 ) ;
V_69:
return V_67 ;
}
static int F_36 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
struct V_10 * V_11 = V_34 -> V_66 ;
int V_67 ;
V_67 = F_33 ( & V_11 -> V_68 ) ;
if ( V_67 )
goto V_69;
if ( V_34 -> V_71 )
F_29 ( V_2 , V_34 -> V_71 ) ;
F_34 ( & V_11 -> V_68 ) ;
V_69:
return V_67 ;
}
static int F_37 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
struct V_10 * V_11 = V_34 -> V_66 ;
int V_67 ;
V_67 = F_33 ( & V_11 -> V_68 ) ;
if ( V_67 )
goto V_69;
if ( V_34 -> V_71 )
F_28 ( & V_34 -> V_71 -> V_64 . V_70 , V_2 ) ;
F_34 ( & V_11 -> V_68 ) ;
V_69:
return V_67 ;
}
static int F_38 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
F_4 ( V_2 , L_26 , V_34 -> V_72 ) ;
F_4 ( V_2 , L_27 , V_34 -> V_73 ) ;
F_4 ( V_2 , L_28 , V_34 -> V_74 ) ;
return 0 ;
}
static T_1 F_39 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_33 * V_34 = V_9 ;
V_34 -> V_72 = V_34 -> V_73 = V_34 -> V_74 = 0 ;
return V_15 ;
}
static int F_40 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
int V_7 ;
F_4 ( V_2 , L_29 , 0U , V_34 -> V_75 [ 0 ] ) ;
for ( V_7 = 1 ; V_7 < V_76 - 1 ; V_7 ++ ) {
unsigned int V_77 = 1U << ( V_7 - 1 ) ;
F_4 ( V_2 , L_29 , V_77 , V_34 -> V_75 [ V_7 ] ) ;
}
F_4 ( V_2 , L_30 , 1U << ( V_7 - 1 ) , V_34 -> V_75 [ V_7 ] ) ;
return 0 ;
}
static T_1 F_41 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_33 * V_34 = V_9 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_76 ; V_7 ++ )
V_34 -> V_75 [ V_7 ] = 0 ;
return V_15 ;
}
static int F_42 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
F_4 ( V_2 , L_31 , V_34 -> V_78 ) ;
return 0 ;
}
static T_1 F_43 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_33 * V_34 = V_9 ;
V_34 -> V_78 = 0 ;
return V_15 ;
}
static int F_44 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
F_4 ( V_2 , L_31 , V_34 -> V_79 ) ;
return 0 ;
}
static T_1 F_45 ( void * V_9 , const char T_2 * V_14 , T_3 V_15 ,
T_4 * V_16 )
{
struct V_33 * V_34 = V_9 ;
V_34 -> V_79 = 0 ;
return V_15 ;
}
static int F_46 ( void * V_9 , struct V_1 * V_2 )
{
struct V_33 * V_34 = V_9 ;
F_4 ( V_2 , L_32 , F_30 ( & V_34 -> V_80 ) ) ;
return 0 ;
}
static void * F_47 ( struct V_1 * V_2 , T_4 * V_55 )
__acquires( &ctx->lock
static void * F_48 ( struct V_1 * V_2 , void * V_54 , T_4 * V_55 )
{
struct V_81 * V_82 = V_2 -> V_56 ;
return F_25 ( V_54 , & V_82 -> V_83 , V_55 ) ;
}
static void F_49 ( struct V_1 * V_2 , void * V_54 )
__releases( &ctx->lock
static int F_50 ( void * V_9 , struct V_1 * V_2 )
{
struct V_81 * V_82 = V_9 ;
F_4 ( V_2 , L_33 , V_82 -> V_84 [ 1 ] , V_82 -> V_84 [ 0 ] ) ;
return 0 ;
}
static T_1 F_51 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_81 * V_82 = V_9 ;
V_82 -> V_84 [ 0 ] = V_82 -> V_84 [ 1 ] = 0 ;
return V_15 ;
}
static int F_52 ( void * V_9 , struct V_1 * V_2 )
{
struct V_81 * V_82 = V_9 ;
F_4 ( V_2 , L_31 , V_82 -> V_85 ) ;
return 0 ;
}
static T_1 F_53 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_81 * V_82 = V_9 ;
V_82 -> V_85 = 0 ;
return V_15 ;
}
static int F_54 ( void * V_9 , struct V_1 * V_2 )
{
struct V_81 * V_82 = V_9 ;
F_4 ( V_2 , L_33 , V_82 -> V_86 [ 1 ] , V_82 -> V_86 [ 0 ] ) ;
return 0 ;
}
static T_1 F_55 ( void * V_9 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_81 * V_82 = V_9 ;
V_82 -> V_86 [ 0 ] = V_82 -> V_86 [ 1 ] = 0 ;
return V_15 ;
}
static int F_56 ( struct V_1 * V_2 , void * V_54 )
{
const struct V_87 * V_88 = V_2 -> V_56 ;
void * V_9 = F_57 ( V_2 -> V_89 -> V_90 . V_91 -> V_92 ) -> V_93 ;
return V_88 -> V_94 ( V_9 , V_2 ) ;
}
static T_1 F_58 ( struct V_89 * V_89 , const char T_2 * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
struct V_1 * V_2 = V_89 -> V_95 ;
const struct V_87 * V_88 = V_2 -> V_56 ;
void * V_9 = F_57 ( V_89 -> V_90 . V_91 -> V_92 ) -> V_93 ;
if ( ! V_88 -> V_96 )
return - V_97 ;
return V_88 -> V_96 ( V_9 , V_14 , V_15 , V_16 ) ;
}
static int F_59 ( struct V_98 * V_98 , struct V_89 * V_89 )
{
const struct V_87 * V_88 = V_98 -> V_93 ;
void * V_9 = F_57 ( V_89 -> V_90 . V_91 -> V_92 ) -> V_93 ;
struct V_1 * V_2 ;
int V_99 ;
if ( V_88 -> V_100 ) {
V_99 = F_60 ( V_89 , V_88 -> V_100 ) ;
if ( ! V_99 ) {
V_2 = V_89 -> V_95 ;
V_2 -> V_56 = V_9 ;
}
return V_99 ;
}
if ( F_61 ( ! V_88 -> V_94 ) )
return - V_97 ;
return F_62 ( V_89 , F_56 , V_98 -> V_93 ) ;
}
static int F_63 ( struct V_98 * V_98 , struct V_89 * V_89 )
{
const struct V_87 * V_88 = V_98 -> V_93 ;
if ( V_88 -> V_94 )
return F_64 ( V_98 , V_89 ) ;
else
return F_65 ( V_98 , V_89 ) ;
}
static bool F_66 ( struct V_91 * V_101 , void * V_9 ,
const struct V_87 * V_88 )
{
F_57 ( V_101 ) -> V_93 = V_9 ;
for (; V_88 -> V_102 ; V_88 ++ ) {
if ( ! F_67 ( V_88 -> V_102 , V_88 -> V_103 , V_101 ,
( void * ) V_88 , & V_104 ) )
return false ;
}
return true ;
}
int F_68 ( struct V_10 * V_11 )
{
struct V_33 * V_34 ;
int V_7 ;
if ( ! V_105 )
return - V_19 ;
V_11 -> V_106 = F_69 ( F_70 ( V_11 -> V_107 . V_101 ) ,
V_105 ) ;
if ( ! V_11 -> V_106 )
return - V_108 ;
if ( ! F_66 ( V_11 -> V_106 , V_11 ,
V_109 ) )
goto V_110;
F_71 (q, hctx, i) {
if ( ! V_34 -> V_106 && F_72 ( V_11 , V_34 ) )
goto V_110;
if ( V_11 -> V_111 && ! V_34 -> V_112 &&
F_73 ( V_11 , V_34 ) )
goto V_110;
}
return 0 ;
V_110:
F_74 ( V_11 ) ;
return - V_108 ;
}
void F_74 ( struct V_10 * V_11 )
{
F_75 ( V_11 -> V_106 ) ;
V_11 -> V_112 = NULL ;
V_11 -> V_106 = NULL ;
}
static int F_76 ( struct V_33 * V_34 ,
struct V_81 * V_82 )
{
struct V_91 * V_113 ;
char V_102 [ 20 ] ;
snprintf ( V_102 , sizeof( V_102 ) , L_34 , V_82 -> V_114 ) ;
V_113 = F_69 ( V_102 , V_34 -> V_106 ) ;
if ( ! V_113 )
return - V_108 ;
if ( ! F_66 ( V_113 , V_82 , V_115 ) )
return - V_108 ;
return 0 ;
}
int F_72 ( struct V_10 * V_11 ,
struct V_33 * V_34 )
{
struct V_81 * V_82 ;
char V_102 [ 20 ] ;
int V_7 ;
if ( ! V_11 -> V_106 )
return - V_19 ;
snprintf ( V_102 , sizeof( V_102 ) , L_35 , V_34 -> V_116 ) ;
V_34 -> V_106 = F_69 ( V_102 , V_11 -> V_106 ) ;
if ( ! V_34 -> V_106 )
return - V_108 ;
if ( ! F_66 ( V_34 -> V_106 , V_34 ,
V_117 ) )
goto V_110;
F_77 (hctx, ctx, i) {
if ( F_76 ( V_34 , V_82 ) )
goto V_110;
}
return 0 ;
V_110:
F_78 ( V_34 ) ;
return - V_108 ;
}
void F_78 ( struct V_33 * V_34 )
{
F_75 ( V_34 -> V_106 ) ;
V_34 -> V_112 = NULL ;
V_34 -> V_106 = NULL ;
}
int F_79 ( struct V_10 * V_11 )
{
struct V_33 * V_34 ;
int V_7 ;
F_71 (q, hctx, i) {
if ( F_72 ( V_11 , V_34 ) )
return - V_108 ;
}
return 0 ;
}
void F_80 ( struct V_10 * V_11 )
{
struct V_33 * V_34 ;
int V_7 ;
F_71 (q, hctx, i)
F_78 ( V_34 ) ;
}
int F_81 ( struct V_10 * V_11 )
{
struct V_118 * V_119 = V_11 -> V_111 -> type ;
if ( ! V_11 -> V_106 )
return - V_19 ;
if ( ! V_119 -> V_120 )
return 0 ;
V_11 -> V_112 = F_69 ( L_36 , V_11 -> V_106 ) ;
if ( ! V_11 -> V_112 )
return - V_108 ;
if ( ! F_66 ( V_11 -> V_112 , V_11 ,
V_119 -> V_120 ) )
goto V_110;
return 0 ;
V_110:
F_82 ( V_11 ) ;
return - V_108 ;
}
void F_82 ( struct V_10 * V_11 )
{
F_75 ( V_11 -> V_112 ) ;
V_11 -> V_112 = NULL ;
}
int F_73 ( struct V_10 * V_11 ,
struct V_33 * V_34 )
{
struct V_118 * V_119 = V_11 -> V_111 -> type ;
if ( ! V_34 -> V_106 )
return - V_19 ;
if ( ! V_119 -> V_121 )
return 0 ;
V_34 -> V_112 = F_69 ( L_36 ,
V_34 -> V_106 ) ;
if ( ! V_34 -> V_112 )
return - V_108 ;
if ( ! F_66 ( V_34 -> V_112 , V_34 ,
V_119 -> V_121 ) )
return - V_108 ;
return 0 ;
}
void F_83 ( struct V_33 * V_34 )
{
F_75 ( V_34 -> V_112 ) ;
V_34 -> V_112 = NULL ;
}
