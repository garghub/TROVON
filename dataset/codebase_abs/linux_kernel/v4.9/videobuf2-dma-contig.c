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
V_11 -> V_23 ) ;
F_19 ( V_11 -> V_18 ) ;
F_17 ( V_11 ) ;
}
static void * F_20 ( struct V_24 * V_18 , unsigned long V_23 ,
unsigned long V_8 , enum V_25 V_20 ,
T_2 V_26 )
{
struct V_10 * V_11 ;
if ( F_21 ( ! V_18 ) )
return F_22 ( - V_27 ) ;
V_11 = F_23 ( sizeof *V_11 , V_28 ) ;
if ( ! V_11 )
return F_22 ( - V_29 ) ;
if ( V_23 )
V_11 -> V_23 = V_23 ;
V_11 -> V_22 = F_24 ( V_18 , V_8 , & V_11 -> V_12 ,
V_28 | V_26 , V_11 -> V_23 ) ;
if ( ! V_11 -> V_22 ) {
F_25 ( V_18 , L_1 , V_8 ) ;
F_17 ( V_11 ) ;
return F_22 ( - V_29 ) ;
}
if ( ( V_11 -> V_23 & V_30 ) == 0 )
V_11 -> V_13 = V_11 -> V_22 ;
V_11 -> V_18 = F_26 ( V_18 ) ;
V_11 -> V_8 = V_8 ;
V_11 -> V_20 = V_20 ;
V_11 -> V_31 . V_16 = & V_11 -> V_16 ;
V_11 -> V_31 . V_32 = F_14 ;
V_11 -> V_31 . V_33 = V_11 ;
F_27 ( & V_11 -> V_16 ) ;
return V_11 ;
}
static int F_28 ( void * V_9 , struct V_34 * V_35 )
{
struct V_10 * V_11 = V_9 ;
int V_36 ;
if ( ! V_11 ) {
F_29 ( V_37 L_2 ) ;
return - V_27 ;
}
V_35 -> V_38 = 0 ;
V_36 = F_30 ( V_11 -> V_18 , V_35 , V_11 -> V_22 ,
V_11 -> V_12 , V_11 -> V_8 , V_11 -> V_23 ) ;
if ( V_36 ) {
F_31 ( L_3 , V_36 ) ;
return V_36 ;
}
V_35 -> V_39 |= V_40 | V_41 ;
V_35 -> V_42 = & V_11 -> V_31 ;
V_35 -> V_43 = & V_44 ;
V_35 -> V_43 -> V_45 ( V_35 ) ;
F_32 ( L_4 ,
V_46 , ( unsigned long ) V_11 -> V_12 , V_35 -> V_47 ,
V_11 -> V_8 ) ;
return 0 ;
}
static int F_33 ( struct V_48 * V_49 , struct V_24 * V_18 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 ;
unsigned int V_7 ;
struct V_3 * V_54 , * V_55 ;
struct V_1 * V_2 ;
struct V_10 * V_11 = V_49 -> V_56 ;
int V_36 ;
V_53 = F_23 ( sizeof( * V_53 ) , V_28 ) ;
if ( ! V_53 )
return - V_29 ;
V_2 = & V_53 -> V_2 ;
V_36 = F_34 ( V_2 , V_11 -> V_21 -> V_19 , V_28 ) ;
if ( V_36 ) {
F_17 ( V_53 ) ;
return - V_29 ;
}
V_54 = V_11 -> V_21 -> V_6 ;
V_55 = V_2 -> V_6 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_19 ; ++ V_7 ) {
F_35 ( V_55 , F_36 ( V_54 ) , V_54 -> V_57 , V_54 -> V_58 ) ;
V_54 = F_37 ( V_54 ) ;
V_55 = F_37 ( V_55 ) ;
}
V_53 -> V_20 = V_59 ;
V_51 -> V_56 = V_53 ;
return 0 ;
}
static void F_38 ( struct V_48 * V_49 ,
struct V_50 * V_14 )
{
struct V_52 * V_53 = V_14 -> V_56 ;
struct V_1 * V_2 ;
if ( ! V_53 )
return;
V_2 = & V_53 -> V_2 ;
if ( V_53 -> V_20 != V_59 )
F_39 ( V_14 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_53 -> V_20 ) ;
F_16 ( V_2 ) ;
F_17 ( V_53 ) ;
V_14 -> V_56 = NULL ;
}
static struct V_1 * F_40 (
struct V_50 * V_14 , enum V_25 V_20 )
{
struct V_52 * V_53 = V_14 -> V_56 ;
struct V_60 * V_61 = & V_14 -> V_15 -> V_61 ;
struct V_1 * V_2 ;
F_41 ( V_61 ) ;
V_2 = & V_53 -> V_2 ;
if ( V_53 -> V_20 == V_20 ) {
F_42 ( V_61 ) ;
return V_2 ;
}
if ( V_53 -> V_20 != V_59 ) {
F_39 ( V_14 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_53 -> V_20 ) ;
V_53 -> V_20 = V_59 ;
}
V_2 -> V_62 = F_43 ( V_14 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_20 ) ;
if ( ! V_2 -> V_62 ) {
F_31 ( L_5 ) ;
F_42 ( V_61 ) ;
return F_22 ( - V_63 ) ;
}
V_53 -> V_20 = V_20 ;
F_42 ( V_61 ) ;
return V_2 ;
}
static void F_44 ( struct V_50 * V_14 ,
struct V_1 * V_2 , enum V_25 V_20 )
{
}
static void F_45 ( struct V_48 * V_49 )
{
F_14 ( V_49 -> V_56 ) ;
}
static void * F_46 ( struct V_48 * V_49 , unsigned long V_64 )
{
struct V_10 * V_11 = V_49 -> V_56 ;
return V_11 -> V_13 ? V_11 -> V_13 + V_64 * V_65 : NULL ;
}
static void * F_47 ( struct V_48 * V_49 )
{
struct V_10 * V_11 = V_49 -> V_56 ;
return V_11 -> V_13 ;
}
static int F_48 ( struct V_48 * V_49 ,
struct V_34 * V_35 )
{
return F_28 ( V_49 -> V_56 , V_35 ) ;
}
static struct V_1 * F_49 ( struct V_10 * V_11 )
{
int V_36 ;
struct V_1 * V_2 ;
V_2 = F_50 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 ) {
F_25 ( V_11 -> V_18 , L_6 ) ;
return NULL ;
}
V_36 = F_51 ( V_11 -> V_18 , V_2 , V_11 -> V_22 , V_11 -> V_12 ,
V_11 -> V_8 , V_11 -> V_23 ) ;
if ( V_36 < 0 ) {
F_25 ( V_11 -> V_18 , L_7 ) ;
F_17 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_48 * F_52 ( void * V_9 , unsigned long V_66 )
{
struct V_10 * V_11 = V_9 ;
struct V_48 * V_49 ;
F_53 ( V_67 ) ;
V_67 . V_68 = & V_69 ;
V_67 . V_8 = V_11 -> V_8 ;
V_67 . V_66 = V_66 ;
V_67 . V_56 = V_11 ;
if ( ! V_11 -> V_21 )
V_11 -> V_21 = F_49 ( V_11 ) ;
if ( F_21 ( ! V_11 -> V_21 ) )
return NULL ;
V_49 = F_54 ( & V_67 ) ;
if ( F_55 ( V_49 ) )
return NULL ;
F_27 ( & V_11 -> V_16 ) ;
return V_49 ;
}
static void F_56 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_1 * V_2 = V_11 -> V_17 ;
int V_7 ;
struct V_70 * * V_71 ;
if ( V_2 ) {
F_57 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_11 -> V_20 , V_72 ) ;
V_71 = F_58 ( V_11 -> V_73 ) ;
F_59 ( F_55 ( V_71 ) ) ;
for ( V_7 = 0 ; V_7 < F_60 ( V_11 -> V_73 ) ; V_7 ++ )
F_61 ( V_71 [ V_7 ] ) ;
F_16 ( V_2 ) ;
F_17 ( V_2 ) ;
}
F_62 ( V_11 -> V_73 ) ;
F_17 ( V_11 ) ;
}
static inline T_1 F_63 ( struct V_24 * V_18 , unsigned long V_74 )
{
return ( T_1 ) F_64 ( V_18 , V_74 ) ;
}
static inline T_1 F_63 ( struct V_24 * V_18 , unsigned long V_74 )
{
return ( T_1 ) F_65 ( V_74 ) ;
}
static inline T_1 F_63 ( struct V_24 * V_18 , unsigned long V_74 )
{
return ( T_1 ) F_66 ( V_74 ) ;
}
static inline T_1 F_63 ( struct V_24 * V_18 , unsigned long V_74 )
{
return ( T_1 ) ( V_74 ) << V_75 ;
}
static void * F_67 ( struct V_24 * V_18 , unsigned long V_13 ,
unsigned long V_8 , enum V_25 V_20 )
{
struct V_10 * V_11 ;
struct V_76 * V_73 ;
unsigned long V_58 ;
int V_77 , V_7 ;
int V_36 = 0 ;
struct V_1 * V_2 ;
unsigned long V_78 ;
unsigned long V_79 = F_68 () ;
if ( ! F_69 ( V_13 | V_8 , V_79 ) ) {
F_32 ( L_8 , V_79 ) ;
return F_22 ( - V_27 ) ;
}
if ( ! V_8 ) {
F_32 ( L_9 ) ;
return F_22 ( - V_27 ) ;
}
if ( F_21 ( ! V_18 ) )
return F_22 ( - V_27 ) ;
V_11 = F_23 ( sizeof *V_11 , V_28 ) ;
if ( ! V_11 )
return F_22 ( - V_29 ) ;
V_11 -> V_18 = V_18 ;
V_11 -> V_20 = V_20 ;
V_58 = V_13 & ~ V_80 ;
V_73 = F_70 ( V_13 , V_8 , V_20 == V_81 ) ;
if ( F_55 ( V_73 ) ) {
V_36 = F_71 ( V_73 ) ;
goto V_82;
}
V_11 -> V_73 = V_73 ;
V_77 = F_60 ( V_73 ) ;
V_36 = F_72 ( V_73 ) ;
if ( V_36 < 0 ) {
unsigned long * V_83 = F_73 ( V_73 ) ;
for ( V_7 = 1 ; V_7 < V_77 ; V_7 ++ )
if ( V_83 [ V_7 - 1 ] + 1 != V_83 [ V_7 ] )
goto V_84;
V_11 -> V_12 = F_63 ( V_11 -> V_18 , V_83 [ 0 ] ) ;
goto V_85;
}
V_2 = F_23 ( sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 ) {
F_31 ( L_10 ) ;
V_36 = - V_29 ;
goto V_84;
}
V_36 = F_74 ( V_2 , F_58 ( V_73 ) , V_77 ,
V_58 , V_8 , V_28 ) ;
if ( V_36 ) {
F_31 ( L_11 ) ;
goto V_86;
}
V_2 -> V_62 = F_75 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_11 -> V_20 , V_72 ) ;
if ( V_2 -> V_62 <= 0 ) {
F_31 ( L_5 ) ;
V_36 = - V_63 ;
goto V_87;
}
V_78 = F_1 ( V_2 ) ;
if ( V_78 < V_8 ) {
F_31 ( L_12 ,
V_78 , V_8 ) ;
V_36 = - V_88 ;
goto V_89;
}
V_11 -> V_12 = F_2 ( V_2 -> V_6 ) ;
V_11 -> V_17 = V_2 ;
V_85:
V_11 -> V_8 = V_8 ;
return V_11 ;
V_89:
F_57 ( V_11 -> V_18 , V_2 -> V_6 , V_2 -> V_19 ,
V_11 -> V_20 , V_72 ) ;
V_87:
F_16 ( V_2 ) ;
V_86:
F_17 ( V_2 ) ;
V_84:
F_62 ( V_73 ) ;
V_82:
F_17 ( V_11 ) ;
return F_22 ( V_36 ) ;
}
static int F_76 ( void * V_90 )
{
struct V_10 * V_11 = V_90 ;
struct V_1 * V_2 ;
unsigned long V_78 ;
if ( F_21 ( ! V_11 -> V_14 ) ) {
F_31 ( L_13 ) ;
return - V_27 ;
}
if ( F_21 ( V_11 -> V_17 ) ) {
F_31 ( L_14 ) ;
return 0 ;
}
V_2 = F_77 ( V_11 -> V_14 , V_11 -> V_20 ) ;
if ( F_55 ( V_2 ) ) {
F_31 ( L_15 ) ;
return - V_27 ;
}
V_78 = F_1 ( V_2 ) ;
if ( V_78 < V_11 -> V_8 ) {
F_31 ( L_16 ,
V_78 , V_11 -> V_8 ) ;
F_78 ( V_11 -> V_14 , V_2 , V_11 -> V_20 ) ;
return - V_88 ;
}
V_11 -> V_12 = F_2 ( V_2 -> V_6 ) ;
V_11 -> V_17 = V_2 ;
V_11 -> V_13 = NULL ;
return 0 ;
}
static void F_79 ( void * V_90 )
{
struct V_10 * V_11 = V_90 ;
struct V_1 * V_2 = V_11 -> V_17 ;
if ( F_21 ( ! V_11 -> V_14 ) ) {
F_31 ( L_17 ) ;
return;
}
if ( F_21 ( ! V_2 ) ) {
F_31 ( L_18 ) ;
return;
}
if ( V_11 -> V_13 ) {
F_80 ( V_11 -> V_14 -> V_15 , V_11 -> V_13 ) ;
V_11 -> V_13 = NULL ;
}
F_78 ( V_11 -> V_14 , V_2 , V_11 -> V_20 ) ;
V_11 -> V_12 = 0 ;
V_11 -> V_17 = NULL ;
}
static void F_81 ( void * V_90 )
{
struct V_10 * V_11 = V_90 ;
if ( F_21 ( V_11 -> V_12 ) )
F_79 ( V_11 ) ;
F_82 ( V_11 -> V_14 -> V_15 , V_11 -> V_14 ) ;
F_17 ( V_11 ) ;
}
static void * F_83 ( struct V_24 * V_18 , struct V_48 * V_49 ,
unsigned long V_8 , enum V_25 V_20 )
{
struct V_10 * V_11 ;
struct V_50 * V_91 ;
if ( V_49 -> V_8 < V_8 )
return F_22 ( - V_88 ) ;
if ( F_21 ( ! V_18 ) )
return F_22 ( - V_27 ) ;
V_11 = F_23 ( sizeof( * V_11 ) , V_28 ) ;
if ( ! V_11 )
return F_22 ( - V_29 ) ;
V_11 -> V_18 = V_18 ;
V_91 = F_84 ( V_49 , V_11 -> V_18 ) ;
if ( F_55 ( V_91 ) ) {
F_31 ( L_19 ) ;
F_17 ( V_11 ) ;
return V_91 ;
}
V_11 -> V_20 = V_20 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_14 = V_91 ;
return V_11 ;
}
int F_85 ( struct V_24 * V_18 , unsigned int V_8 )
{
if ( ! V_18 -> V_92 ) {
V_18 -> V_92 = F_23 ( sizeof( * V_18 -> V_92 ) , V_28 ) ;
if ( ! V_18 -> V_92 )
return - V_29 ;
}
if ( F_86 ( V_18 ) < V_8 )
return F_87 ( V_18 , V_8 ) ;
return 0 ;
}
void F_88 ( struct V_24 * V_18 )
{
F_17 ( V_18 -> V_92 ) ;
V_18 -> V_92 = NULL ;
}
