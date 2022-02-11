static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , V_4 ) ;
if ( ! V_7 ) {
V_6 = V_2 -> V_8 ;
V_6 -> V_9 = V_1 -> V_10 ;
}
return V_7 ;
}
static int F_3 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
F_4 ( V_6 , L_1 , V_13 -> V_14 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_3 , V_1 -> V_10 ) ;
}
static int F_7 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
F_4 ( V_6 , L_1 , V_13 -> V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_7 , V_1 -> V_10 ) ;
}
static int F_9 ( struct V_5 * V_6 , void * V_11 )
{
struct V_16 * V_17 = F_10 ( V_11 ) ;
F_4 ( V_6 , L_2 ,
V_17 , V_17 -> V_18 , ( V_19 unsigned int ) V_17 -> V_20 ,
V_17 -> V_21 , V_17 -> V_22 ) ;
return 0 ;
}
static void * F_11 ( struct V_5 * V_6 , T_1 * V_23 )
__acquires( &hctx->lock
static void * F_12 ( struct V_5 * V_6 , void * V_11 , T_1 * V_23 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
return F_13 ( V_11 , & V_13 -> V_24 , V_23 ) ;
}
static void F_14 ( struct V_5 * V_6 , void * V_11 )
__releases( &hctx->lock
static int F_15 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_1 ( V_1 , V_2 , & V_25 ) ;
}
static int F_16 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
F_17 ( & V_13 -> V_26 , V_6 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_16 , V_1 -> V_10 ) ;
}
static void F_19 ( struct V_5 * V_6 ,
struct V_27 * V_28 )
{
F_4 ( V_6 , L_3 , V_28 -> V_29 ) ;
F_4 ( V_6 , L_4 , V_28 -> V_30 ) ;
F_4 ( V_6 , L_5 ,
F_20 ( & V_28 -> V_31 ) ) ;
F_21 ( V_6 , L_6 ) ;
F_22 ( & V_28 -> V_32 , V_6 ) ;
if ( V_28 -> V_30 ) {
F_21 ( V_6 , L_7 ) ;
F_22 ( & V_28 -> V_33 , V_6 ) ;
}
}
static int F_23 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
struct V_34 * V_35 = V_13 -> V_36 ;
int V_37 ;
V_37 = F_24 ( & V_35 -> V_38 ) ;
if ( V_37 )
goto V_39;
if ( V_13 -> V_28 )
F_19 ( V_6 , V_13 -> V_28 ) ;
F_25 ( & V_35 -> V_38 ) ;
V_39:
return V_37 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_23 , V_1 -> V_10 ) ;
}
static int F_27 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
struct V_34 * V_35 = V_13 -> V_36 ;
int V_37 ;
V_37 = F_24 ( & V_35 -> V_38 ) ;
if ( V_37 )
goto V_39;
if ( V_13 -> V_28 )
F_17 ( & V_13 -> V_28 -> V_32 . V_40 , V_6 ) ;
F_25 ( & V_35 -> V_38 ) ;
V_39:
return V_37 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_27 , V_1 -> V_10 ) ;
}
static int F_29 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
struct V_34 * V_35 = V_13 -> V_36 ;
int V_37 ;
V_37 = F_24 ( & V_35 -> V_38 ) ;
if ( V_37 )
goto V_39;
if ( V_13 -> V_41 )
F_19 ( V_6 , V_13 -> V_41 ) ;
F_25 ( & V_35 -> V_38 ) ;
V_39:
return V_37 ;
}
static int F_30 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_29 , V_1 -> V_10 ) ;
}
static int F_31 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
struct V_34 * V_35 = V_13 -> V_36 ;
int V_37 ;
V_37 = F_24 ( & V_35 -> V_38 ) ;
if ( V_37 )
goto V_39;
if ( V_13 -> V_41 )
F_17 ( & V_13 -> V_41 -> V_32 . V_40 , V_6 ) ;
F_25 ( & V_35 -> V_38 ) ;
V_39:
return V_37 ;
}
static int F_32 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_31 , V_1 -> V_10 ) ;
}
static int F_33 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
F_4 ( V_6 , L_8 , V_13 -> V_42 ) ;
F_4 ( V_6 , L_9 , V_13 -> V_43 ) ;
F_4 ( V_6 , L_10 , V_13 -> V_44 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_33 , V_1 -> V_10 ) ;
}
static T_2 F_35 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_12 * V_13 = V_6 -> V_9 ;
V_13 -> V_42 = V_13 -> V_43 = V_13 -> V_44 = 0 ;
return V_46 ;
}
static void F_36 ( struct V_5 * V_6 , struct V_48 * V_49 )
{
F_4 ( V_6 , L_11 ,
V_49 -> V_50 , V_49 -> V_51 , V_49 -> V_52 , V_49 -> V_53 ) ;
}
static int F_37 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
struct V_48 V_49 [ 2 ] ;
F_38 ( & V_49 [ V_54 ] ) ;
F_38 ( & V_49 [ V_55 ] ) ;
F_39 ( V_13 , V_49 ) ;
F_21 ( V_6 , L_12 ) ;
F_36 ( V_6 , & V_49 [ V_54 ] ) ;
F_21 ( V_6 , L_13 ) ;
F_21 ( V_6 , L_14 ) ;
F_36 ( V_6 , & V_49 [ V_55 ] ) ;
F_21 ( V_6 , L_13 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_37 , V_1 -> V_10 ) ;
}
static T_2 F_41 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_12 * V_13 = V_6 -> V_9 ;
struct V_56 * V_57 ;
int V_58 ;
F_42 (hctx, ctx, i) {
F_38 ( & V_57 -> V_49 [ V_54 ] ) ;
F_38 ( & V_57 -> V_49 [ V_55 ] ) ;
}
return V_46 ;
}
static int F_43 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
int V_58 ;
F_4 ( V_6 , L_15 , 0U , V_13 -> V_59 [ 0 ] ) ;
for ( V_58 = 1 ; V_58 < V_60 - 1 ; V_58 ++ ) {
unsigned int V_61 = 1U << ( V_58 - 1 ) ;
F_4 ( V_6 , L_15 , V_61 , V_13 -> V_59 [ V_58 ] ) ;
}
F_4 ( V_6 , L_16 , 1U << ( V_58 - 1 ) , V_13 -> V_59 [ V_58 ] ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_43 , V_1 -> V_10 ) ;
}
static T_2 F_45 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_12 * V_13 = V_6 -> V_9 ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_60 ; V_58 ++ )
V_13 -> V_59 [ V_58 ] = 0 ;
return V_46 ;
}
static int F_46 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
F_4 ( V_6 , L_17 , V_13 -> V_62 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_46 , V_1 -> V_10 ) ;
}
static T_2 F_48 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_12 * V_13 = V_6 -> V_9 ;
V_13 -> V_62 = 0 ;
return V_46 ;
}
static int F_49 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
F_4 ( V_6 , L_17 , V_13 -> V_63 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_49 , V_1 -> V_10 ) ;
}
static T_2 F_51 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_12 * V_13 = V_6 -> V_9 ;
V_13 -> V_63 = 0 ;
return V_46 ;
}
static int F_52 ( struct V_5 * V_6 , void * V_11 )
{
struct V_12 * V_13 = V_6 -> V_9 ;
F_4 ( V_6 , L_18 , F_20 ( & V_13 -> V_64 ) ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_52 , V_1 -> V_10 ) ;
}
static void * F_54 ( struct V_5 * V_6 , T_1 * V_23 )
__acquires( &ctx->lock
static void * F_55 ( struct V_5 * V_6 , void * V_11 , T_1 * V_23 )
{
struct V_56 * V_57 = V_6 -> V_9 ;
return F_13 ( V_11 , & V_57 -> V_65 , V_23 ) ;
}
static void F_56 ( struct V_5 * V_6 , void * V_11 )
__releases( &ctx->lock
static int F_57 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_1 ( V_1 , V_2 , & V_66 ) ;
}
static int F_58 ( struct V_5 * V_6 , void * V_11 )
{
struct V_56 * V_57 = V_6 -> V_9 ;
F_4 ( V_6 , L_19 , V_57 -> V_67 [ 1 ] , V_57 -> V_67 [ 0 ] ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_58 , V_1 -> V_10 ) ;
}
static T_2 F_60 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_56 * V_57 = V_6 -> V_9 ;
V_57 -> V_67 [ 0 ] = V_57 -> V_67 [ 1 ] = 0 ;
return V_46 ;
}
static int F_61 ( struct V_5 * V_6 , void * V_11 )
{
struct V_56 * V_57 = V_6 -> V_9 ;
F_4 ( V_6 , L_17 , V_57 -> V_68 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_61 , V_1 -> V_10 ) ;
}
static T_2 F_63 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_56 * V_57 = V_6 -> V_9 ;
V_57 -> V_68 = 0 ;
return V_46 ;
}
static int F_64 ( struct V_5 * V_6 , void * V_11 )
{
struct V_56 * V_57 = V_6 -> V_9 ;
F_4 ( V_6 , L_19 , V_57 -> V_69 [ 1 ] , V_57 -> V_69 [ 0 ] ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_6 ( V_2 , F_64 , V_1 -> V_10 ) ;
}
static T_2 F_66 ( struct V_2 * V_2 , const char T_3 * V_45 ,
T_4 V_46 , T_1 * V_47 )
{
struct V_5 * V_6 = V_2 -> V_8 ;
struct V_56 * V_57 = V_6 -> V_9 ;
V_57 -> V_69 [ 0 ] = V_57 -> V_69 [ 1 ] = 0 ;
return V_46 ;
}
int F_67 ( struct V_34 * V_35 , const char * V_70 )
{
if ( ! V_71 )
return - V_72 ;
V_35 -> V_73 = F_68 ( V_70 , V_71 ) ;
if ( ! V_35 -> V_73 )
goto V_74;
if ( F_69 ( V_35 ) )
goto V_74;
return 0 ;
V_74:
F_70 ( V_35 ) ;
return - V_75 ;
}
void F_70 ( struct V_34 * V_35 )
{
F_71 ( V_35 -> V_73 ) ;
V_35 -> V_76 = NULL ;
V_35 -> V_73 = NULL ;
}
static bool F_72 ( struct V_77 * V_78 , void * V_79 ,
const struct V_80 * V_81 )
{
for (; V_81 -> V_70 ; V_81 ++ ) {
if ( ! F_73 ( V_81 -> V_70 , V_81 -> V_82 , V_78 ,
V_79 , V_81 -> V_83 ) )
return false ;
}
return true ;
}
static int F_74 ( struct V_34 * V_35 ,
struct V_56 * V_57 ,
struct V_77 * V_84 )
{
struct V_77 * V_85 ;
char V_70 [ 20 ] ;
snprintf ( V_70 , sizeof( V_70 ) , L_20 , V_57 -> V_86 ) ;
V_85 = F_68 ( V_70 , V_84 ) ;
if ( ! V_85 )
return - V_75 ;
if ( ! F_72 ( V_85 , V_57 , V_87 ) )
return - V_75 ;
return 0 ;
}
static int F_75 ( struct V_34 * V_35 ,
struct V_12 * V_13 )
{
struct V_56 * V_57 ;
struct V_77 * V_84 ;
char V_70 [ 20 ] ;
int V_58 ;
snprintf ( V_70 , sizeof( V_70 ) , L_21 , V_13 -> V_88 ) ;
V_84 = F_68 ( V_70 , V_35 -> V_76 ) ;
if ( ! V_84 )
return - V_75 ;
if ( ! F_72 ( V_84 , V_13 , V_89 ) )
return - V_75 ;
F_42 (hctx, ctx, i) {
if ( F_74 ( V_35 , V_57 , V_84 ) )
return - V_75 ;
}
return 0 ;
}
int F_69 ( struct V_34 * V_35 )
{
struct V_12 * V_13 ;
int V_58 ;
if ( ! V_35 -> V_73 )
return - V_72 ;
V_35 -> V_76 = F_68 ( L_22 , V_35 -> V_73 ) ;
if ( ! V_35 -> V_76 )
goto V_74;
F_76 (q, hctx, i) {
if ( F_75 ( V_35 , V_13 ) )
goto V_74;
}
return 0 ;
V_74:
F_77 ( V_35 ) ;
return - V_75 ;
}
void F_77 ( struct V_34 * V_35 )
{
F_71 ( V_35 -> V_76 ) ;
V_35 -> V_76 = NULL ;
}
