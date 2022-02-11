static unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 = F_2 ( V_2 -> V_6 ) ;
unsigned int V_7 ;
unsigned long V_8 = 0 ;
F_3 (sgt->sgl, s, sgt->nents, i) {
if ( F_2 ( V_4 ) != V_5 )
break;
V_5 = F_2 ( V_4 ) + F_4 ( V_4 ) ;
V_8 += F_4 ( V_4 ) ;
}
return V_8 ;
}
static void * F_5 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
return & V_11 -> V_12 ;
}
static void * F_6 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
if ( ! V_11 -> V_13 && V_11 -> V_14 )
V_11 -> V_13 = F_7 ( V_11 -> V_14 -> V_15 ) ;
return V_11 -> V_13 ;
}
static unsigned int F_8 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
return F_9 ( & V_11 -> V_16 ) ;
}
static void F_10 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_1 * V_2 = V_11 -> V_17 ;
if ( ! V_2 || V_11 -> V_14 )
return;
F_11 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_11 -> V_20 ) ;
}
static void F_12 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_1 * V_2 = V_11 -> V_17 ;
if ( ! V_2 || V_11 -> V_14 )
return;
F_13 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 , V_11 -> V_20 ) ;
}
static void F_14 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
if ( ! F_15 ( & V_11 -> V_16 ) )
return;
if ( V_11 -> V_21 ) {
F_16 ( V_11 -> V_21 ) ;
F_17 ( V_11 -> V_21 ) ;
}
F_18 ( V_11 -> V_18 , V_11 -> V_8 , V_11 -> V_22 , V_11 -> V_12 ,
& V_11 -> V_23 ) ;
F_19 ( V_11 -> V_18 ) ;
F_17 ( V_11 ) ;
}
static void * F_20 ( void * V_24 , unsigned long V_8 ,
enum V_25 V_20 , T_2 V_26 )
{
struct V_27 * V_28 = V_24 ;
struct V_29 * V_18 = V_28 -> V_18 ;
struct V_10 * V_11 ;
V_11 = F_21 ( sizeof *V_11 , V_30 ) ;
if ( ! V_11 )
return F_22 ( - V_31 ) ;
V_11 -> V_23 = V_28 -> V_23 ;
V_11 -> V_22 = F_23 ( V_18 , V_8 , & V_11 -> V_12 ,
V_30 | V_26 , & V_11 -> V_23 ) ;
if ( ! V_11 -> V_22 ) {
F_24 ( V_18 , L_1 , V_8 ) ;
F_17 ( V_11 ) ;
return F_22 ( - V_31 ) ;
}
if ( ! F_25 ( V_32 , & V_11 -> V_23 ) )
V_11 -> V_13 = V_11 -> V_22 ;
V_11 -> V_18 = F_26 ( V_18 ) ;
V_11 -> V_8 = V_8 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_33 . V_16 = & V_11 -> V_16 ;
V_11 -> V_33 . V_34 = F_14 ;
V_11 -> V_33 . V_35 = V_11 ;
F_27 ( & V_11 -> V_16 ) ;
return V_11 ;
}
static int F_28 ( void * V_9 , struct V_36 * V_37 )
{
struct V_10 * V_11 = V_9 ;
int V_38 ;
if ( ! V_11 ) {
F_29 ( V_39 L_2 ) ;
return - V_40 ;
}
V_37 -> V_41 = 0 ;
V_38 = F_30 ( V_11 -> V_18 , V_37 , V_11 -> V_22 ,
V_11 -> V_12 , V_11 -> V_8 , & V_11 -> V_23 ) ;
if ( V_38 ) {
F_31 ( L_3 , V_38 ) ;
return V_38 ;
}
V_37 -> V_42 |= V_43 | V_44 ;
V_37 -> V_45 = & V_11 -> V_33 ;
V_37 -> V_46 = & V_47 ;
V_37 -> V_46 -> V_48 ( V_37 ) ;
F_32 ( L_4 ,
V_49 , ( unsigned long ) V_11 -> V_12 , V_37 -> V_50 ,
V_11 -> V_8 ) ;
return 0 ;
}
static int F_33 ( struct V_51 * V_52 , struct V_29 * V_18 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 ;
unsigned int V_7 ;
struct V_3 * V_57 , * V_58 ;
struct V_1 * V_2 ;
struct V_10 * V_11 = V_52 -> V_59 ;
int V_38 ;
V_56 = F_21 ( sizeof( * V_56 ) , V_30 ) ;
if ( ! V_56 )
return - V_31 ;
V_2 = & V_56 -> V_2 ;
V_38 = F_34 ( V_2 , V_11 -> V_21 -> V_19 , V_30 ) ;
if ( V_38 ) {
F_17 ( V_56 ) ;
return - V_31 ;
}
V_57 = V_11 -> V_21 -> V_6 ;
V_58 = V_2 -> V_6 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_19 ; ++ V_7 ) {
F_35 ( V_58 , F_36 ( V_57 ) , V_57 -> V_60 , V_57 -> V_61 ) ;
V_57 = F_37 ( V_57 ) ;
V_58 = F_37 ( V_58 ) ;
}
V_56 -> V_20 = V_62 ;
V_54 -> V_59 = V_56 ;
return 0 ;
}
static void F_38 ( struct V_51 * V_52 ,
struct V_53 * V_14 )
{
struct V_55 * V_56 = V_14 -> V_59 ;
struct V_1 * V_2 ;
if ( ! V_56 )
return;
V_2 = & V_56 -> V_2 ;
if ( V_56 -> V_20 != V_62 )
F_39 ( V_14 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_56 -> V_20 ) ;
F_16 ( V_2 ) ;
F_17 ( V_56 ) ;
V_14 -> V_59 = NULL ;
}
static struct V_1 * F_40 (
struct V_53 * V_14 , enum V_25 V_20 )
{
struct V_55 * V_56 = V_14 -> V_59 ;
struct V_63 * V_64 = & V_14 -> V_15 -> V_64 ;
struct V_1 * V_2 ;
F_41 ( V_64 ) ;
V_2 = & V_56 -> V_2 ;
if ( V_56 -> V_20 == V_20 ) {
F_42 ( V_64 ) ;
return V_2 ;
}
if ( V_56 -> V_20 != V_62 ) {
F_39 ( V_14 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_56 -> V_20 ) ;
V_56 -> V_20 = V_62 ;
}
V_2 -> V_65 = F_43 ( V_14 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_20 ) ;
if ( ! V_2 -> V_65 ) {
F_31 ( L_5 ) ;
F_42 ( V_64 ) ;
return F_22 ( - V_66 ) ;
}
V_56 -> V_20 = V_20 ;
F_42 ( V_64 ) ;
return V_2 ;
}
static void F_44 ( struct V_53 * V_14 ,
struct V_1 * V_2 , enum V_25 V_20 )
{
}
static void F_45 ( struct V_51 * V_52 )
{
F_14 ( V_52 -> V_59 ) ;
}
static void * F_46 ( struct V_51 * V_52 , unsigned long V_67 )
{
struct V_10 * V_11 = V_52 -> V_59 ;
return V_11 -> V_13 ? V_11 -> V_13 + V_67 * V_68 : NULL ;
}
static void * F_47 ( struct V_51 * V_52 )
{
struct V_10 * V_11 = V_52 -> V_59 ;
return V_11 -> V_13 ;
}
static int F_48 ( struct V_51 * V_52 ,
struct V_36 * V_37 )
{
return F_28 ( V_52 -> V_59 , V_37 ) ;
}
static struct V_1 * F_49 ( struct V_10 * V_11 )
{
int V_38 ;
struct V_1 * V_2 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 ) {
F_24 ( V_11 -> V_18 , L_6 ) ;
return NULL ;
}
V_38 = F_51 ( V_11 -> V_18 , V_2 , V_11 -> V_22 , V_11 -> V_12 ,
V_11 -> V_8 , & V_11 -> V_23 ) ;
if ( V_38 < 0 ) {
F_24 ( V_11 -> V_18 , L_7 ) ;
F_17 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_51 * F_52 ( void * V_9 , unsigned long V_69 )
{
struct V_10 * V_11 = V_9 ;
struct V_51 * V_52 ;
F_53 ( V_70 ) ;
V_70 . V_71 = & V_72 ;
V_70 . V_8 = V_11 -> V_8 ;
V_70 . V_69 = V_69 ;
V_70 . V_59 = V_11 ;
if ( ! V_11 -> V_21 )
V_11 -> V_21 = F_49 ( V_11 ) ;
if ( F_54 ( ! V_11 -> V_21 ) )
return NULL ;
V_52 = F_55 ( & V_70 ) ;
if ( F_56 ( V_52 ) )
return NULL ;
F_27 ( & V_11 -> V_16 ) ;
return V_52 ;
}
static void F_57 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_1 * V_2 = V_11 -> V_17 ;
int V_7 ;
struct V_73 * * V_74 ;
if ( V_2 ) {
F_58 ( V_23 ) ;
F_59 ( V_75 , & V_23 ) ;
F_60 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_11 -> V_20 , & V_23 ) ;
V_74 = F_61 ( V_11 -> V_76 ) ;
F_62 ( F_56 ( V_74 ) ) ;
for ( V_7 = 0 ; V_7 < F_63 ( V_11 -> V_76 ) ; V_7 ++ )
F_64 ( V_74 [ V_7 ] ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
}
F_65 ( V_11 -> V_76 ) ;
F_17 ( V_11 ) ;
}
static inline T_1 F_66 ( struct V_29 * V_18 , unsigned long V_77 )
{
return ( T_1 ) F_67 ( V_18 , V_77 ) ;
}
static inline T_1 F_66 ( struct V_29 * V_18 , unsigned long V_77 )
{
return ( T_1 ) F_68 ( V_77 ) ;
}
static inline T_1 F_66 ( struct V_29 * V_18 , unsigned long V_77 )
{
return ( T_1 ) F_69 ( V_77 ) ;
}
static inline T_1 F_66 ( struct V_29 * V_18 , unsigned long V_77 )
{
return ( T_1 ) ( V_77 ) << V_78 ;
}
static void * F_70 ( void * V_24 , unsigned long V_13 ,
unsigned long V_8 , enum V_25 V_20 )
{
struct V_27 * V_28 = V_24 ;
struct V_10 * V_11 ;
struct V_79 * V_76 ;
unsigned long V_61 ;
int V_80 , V_7 ;
int V_38 = 0 ;
struct V_1 * V_2 ;
unsigned long V_81 ;
unsigned long V_82 = F_71 () ;
F_58 ( V_23 ) ;
F_59 ( V_75 , & V_23 ) ;
if ( ! F_72 ( V_13 | V_8 , V_82 ) ) {
F_32 ( L_8 , V_82 ) ;
return F_22 ( - V_40 ) ;
}
if ( ! V_8 ) {
F_32 ( L_9 ) ;
return F_22 ( - V_40 ) ;
}
V_11 = F_21 ( sizeof *V_11 , V_30 ) ;
if ( ! V_11 )
return F_22 ( - V_31 ) ;
V_11 -> V_18 = V_28 -> V_18 ;
V_11 -> V_20 = V_20 ;
V_61 = V_13 & ~ V_83 ;
V_76 = F_73 ( V_13 , V_8 , V_20 == V_84 ) ;
if ( F_56 ( V_76 ) ) {
V_38 = F_74 ( V_76 ) ;
goto V_85;
}
V_11 -> V_76 = V_76 ;
V_80 = F_63 ( V_76 ) ;
V_38 = F_75 ( V_76 ) ;
if ( V_38 < 0 ) {
unsigned long * V_86 = F_76 ( V_76 ) ;
for ( V_7 = 1 ; V_7 < V_80 ; V_7 ++ )
if ( V_86 [ V_7 - 1 ] + 1 != V_86 [ V_7 ] )
goto V_87;
V_11 -> V_12 = F_66 ( V_11 -> V_18 , V_86 [ 0 ] ) ;
goto V_88;
}
V_2 = F_21 ( sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 ) {
F_31 ( L_10 ) ;
V_38 = - V_31 ;
goto V_87;
}
V_38 = F_77 ( V_2 , F_61 ( V_76 ) , V_80 ,
V_61 , V_8 , V_30 ) ;
if ( V_38 ) {
F_31 ( L_11 ) ;
goto V_89;
}
V_2 -> V_65 = F_78 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_11 -> V_20 , & V_23 ) ;
if ( V_2 -> V_65 <= 0 ) {
F_31 ( L_5 ) ;
V_38 = - V_66 ;
goto V_90;
}
V_81 = F_1 ( V_2 ) ;
if ( V_81 < V_8 ) {
F_31 ( L_12 ,
V_81 , V_8 ) ;
V_38 = - V_91 ;
goto V_92;
}
V_11 -> V_12 = F_2 ( V_2 -> V_6 ) ;
V_11 -> V_17 = V_2 ;
V_88:
V_11 -> V_8 = V_8 ;
return V_11 ;
V_92:
F_60 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_11 -> V_20 , & V_23 ) ;
V_90:
F_16 ( V_2 ) ;
V_89:
F_17 ( V_2 ) ;
V_87:
F_65 ( V_76 ) ;
V_85:
F_17 ( V_11 ) ;
return F_22 ( V_38 ) ;
}
static int F_79 ( void * V_93 )
{
struct V_10 * V_11 = V_93 ;
struct V_1 * V_2 ;
unsigned long V_81 ;
if ( F_54 ( ! V_11 -> V_14 ) ) {
F_31 ( L_13 ) ;
return - V_40 ;
}
if ( F_54 ( V_11 -> V_17 ) ) {
F_31 ( L_14 ) ;
return 0 ;
}
V_2 = F_80 ( V_11 -> V_14 , V_11 -> V_20 ) ;
if ( F_56 ( V_2 ) ) {
F_31 ( L_15 ) ;
return - V_40 ;
}
V_81 = F_1 ( V_2 ) ;
if ( V_81 < V_11 -> V_8 ) {
F_31 ( L_16 ,
V_81 , V_11 -> V_8 ) ;
F_81 ( V_11 -> V_14 , V_2 , V_11 -> V_20 ) ;
return - V_91 ;
}
V_11 -> V_12 = F_2 ( V_2 -> V_6 ) ;
V_11 -> V_17 = V_2 ;
V_11 -> V_13 = NULL ;
return 0 ;
}
static void F_82 ( void * V_93 )
{
struct V_10 * V_11 = V_93 ;
struct V_1 * V_2 = V_11 -> V_17 ;
if ( F_54 ( ! V_11 -> V_14 ) ) {
F_31 ( L_17 ) ;
return;
}
if ( F_54 ( ! V_2 ) ) {
F_31 ( L_18 ) ;
return;
}
if ( V_11 -> V_13 ) {
F_83 ( V_11 -> V_14 -> V_15 , V_11 -> V_13 ) ;
V_11 -> V_13 = NULL ;
}
F_81 ( V_11 -> V_14 , V_2 , V_11 -> V_20 ) ;
V_11 -> V_12 = 0 ;
V_11 -> V_17 = NULL ;
}
static void F_84 ( void * V_93 )
{
struct V_10 * V_11 = V_93 ;
if ( F_54 ( V_11 -> V_12 ) )
F_82 ( V_11 ) ;
F_85 ( V_11 -> V_14 -> V_15 , V_11 -> V_14 ) ;
F_17 ( V_11 ) ;
}
static void * F_86 ( void * V_24 , struct V_51 * V_52 ,
unsigned long V_8 , enum V_25 V_20 )
{
struct V_27 * V_28 = V_24 ;
struct V_10 * V_11 ;
struct V_53 * V_94 ;
if ( V_52 -> V_8 < V_8 )
return F_22 ( - V_91 ) ;
V_11 = F_21 ( sizeof( * V_11 ) , V_30 ) ;
if ( ! V_11 )
return F_22 ( - V_31 ) ;
V_11 -> V_18 = V_28 -> V_18 ;
V_94 = F_87 ( V_52 , V_11 -> V_18 ) ;
if ( F_56 ( V_94 ) ) {
F_31 ( L_19 ) ;
F_17 ( V_11 ) ;
return V_94 ;
}
V_11 -> V_20 = V_20 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_14 = V_94 ;
return V_11 ;
}
void * F_88 ( struct V_29 * V_18 ,
struct V_95 * V_23 )
{
struct V_27 * V_28 ;
V_28 = F_21 ( sizeof *V_28 , V_30 ) ;
if ( ! V_28 )
return F_22 ( - V_31 ) ;
V_28 -> V_18 = V_18 ;
if ( V_23 )
V_28 -> V_23 = * V_23 ;
return V_28 ;
}
void F_89 ( void * V_24 )
{
if ( ! F_90 ( V_24 ) )
F_17 ( V_24 ) ;
}
