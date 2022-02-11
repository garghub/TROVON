static void F_1 ( struct V_1 * V_2 ,
void (* F_2)( struct V_3 * V_4 ) )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
F_3 (sgt->sgl, s, sgt->orig_nents, i) {
struct V_3 * V_3 = F_4 ( V_6 ) ;
unsigned int V_8 = F_5 ( V_6 -> V_9 + V_6 -> V_10 )
>> V_11 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_8 ; ++ V_12 , ++ V_3 )
F_2 ( V_3 ) ;
}
}
static unsigned long F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
T_1 V_13 = F_7 ( V_2 -> V_14 ) ;
unsigned int V_7 ;
unsigned long V_15 = 0 ;
F_3 (sgt->sgl, s, sgt->nents, i) {
if ( F_7 ( V_6 ) != V_13 )
break;
V_13 = F_7 ( V_6 ) + F_8 ( V_6 ) ;
V_15 += F_8 ( V_6 ) ;
}
return V_15 ;
}
static void * F_9 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
return & V_18 -> V_19 ;
}
static void * F_10 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
return V_18 -> V_20 ;
}
static unsigned int F_11 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
return F_12 ( & V_18 -> V_21 ) ;
}
static void F_13 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_22 ;
if ( ! V_2 || V_18 -> V_23 )
return;
F_14 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_25 , V_18 -> V_26 ) ;
}
static void F_15 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_22 ;
if ( ! V_2 || V_18 -> V_23 )
return;
F_16 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_25 , V_18 -> V_26 ) ;
}
static void F_17 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
if ( ! F_18 ( & V_18 -> V_21 ) )
return;
if ( V_18 -> V_27 ) {
F_19 ( V_18 -> V_27 ) ;
F_20 ( V_18 -> V_27 ) ;
}
F_21 ( V_18 -> V_24 , V_18 -> V_15 , V_18 -> V_20 , V_18 -> V_19 ) ;
F_22 ( V_18 -> V_24 ) ;
F_20 ( V_18 ) ;
}
static void * F_23 ( void * V_28 , unsigned long V_15 )
{
struct V_29 * V_30 = V_28 ;
struct V_31 * V_24 = V_30 -> V_24 ;
struct V_17 * V_18 ;
V_18 = F_24 ( sizeof *V_18 , V_32 ) ;
if ( ! V_18 )
return F_25 ( - V_33 ) ;
V_15 = F_5 ( V_15 ) ;
V_18 -> V_20 = F_26 ( V_24 , V_15 , & V_18 -> V_19 , V_32 ) ;
if ( ! V_18 -> V_20 ) {
F_27 ( V_24 , L_1 , V_15 ) ;
F_20 ( V_18 ) ;
return F_25 ( - V_33 ) ;
}
V_18 -> V_24 = F_28 ( V_24 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_34 . V_21 = & V_18 -> V_21 ;
V_18 -> V_34 . V_35 = F_17 ;
V_18 -> V_34 . V_36 = V_18 ;
F_29 ( & V_18 -> V_21 ) ;
return V_18 ;
}
static int F_30 ( void * V_16 , struct V_37 * V_38 )
{
struct V_17 * V_18 = V_16 ;
int V_39 ;
if ( ! V_18 ) {
F_31 ( V_40 L_2 ) ;
return - V_41 ;
}
V_38 -> V_42 = 0 ;
V_39 = F_32 ( V_18 -> V_24 , V_38 , V_18 -> V_20 ,
V_18 -> V_19 , V_18 -> V_15 ) ;
if ( V_39 ) {
F_33 ( L_3 , V_39 ) ;
return V_39 ;
}
V_38 -> V_43 |= V_44 | V_45 ;
V_38 -> V_46 = & V_18 -> V_34 ;
V_38 -> V_47 = & V_48 ;
V_38 -> V_47 -> V_49 ( V_38 ) ;
F_34 ( L_4 ,
V_50 , ( unsigned long ) V_18 -> V_19 , V_38 -> V_51 ,
V_18 -> V_15 ) ;
return 0 ;
}
static int F_35 ( struct V_52 * V_53 , struct V_31 * V_24 ,
struct V_54 * V_55 )
{
struct V_56 * V_57 ;
unsigned int V_7 ;
struct V_5 * V_58 , * V_59 ;
struct V_1 * V_2 ;
struct V_17 * V_18 = V_53 -> V_60 ;
int V_39 ;
V_57 = F_24 ( sizeof( * V_57 ) , V_32 ) ;
if ( ! V_57 )
return - V_33 ;
V_2 = & V_57 -> V_2 ;
V_39 = F_36 ( V_2 , V_18 -> V_27 -> V_61 , V_32 ) ;
if ( V_39 ) {
F_20 ( V_57 ) ;
return - V_33 ;
}
V_58 = V_18 -> V_27 -> V_14 ;
V_59 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_61 ; ++ V_7 ) {
F_37 ( V_59 , F_4 ( V_58 ) , V_58 -> V_10 , V_58 -> V_9 ) ;
V_58 = F_38 ( V_58 ) ;
V_59 = F_38 ( V_59 ) ;
}
V_57 -> V_62 = V_63 ;
V_55 -> V_60 = V_57 ;
return 0 ;
}
static void F_39 ( struct V_52 * V_53 ,
struct V_54 * V_23 )
{
struct V_56 * V_57 = V_23 -> V_60 ;
struct V_1 * V_2 ;
if ( ! V_57 )
return;
V_2 = & V_57 -> V_2 ;
if ( V_57 -> V_62 != V_63 )
F_40 ( V_23 -> V_24 , V_2 -> V_14 , V_2 -> V_61 ,
V_57 -> V_62 ) ;
F_19 ( V_2 ) ;
F_20 ( V_57 ) ;
V_23 -> V_60 = NULL ;
}
static struct V_1 * F_41 (
struct V_54 * V_23 , enum V_64 V_62 )
{
struct V_56 * V_57 = V_23 -> V_60 ;
struct V_65 * V_66 = & V_23 -> V_67 -> V_66 ;
struct V_1 * V_2 ;
int V_39 ;
F_42 ( V_66 ) ;
V_2 = & V_57 -> V_2 ;
if ( V_57 -> V_62 == V_62 ) {
F_43 ( V_66 ) ;
return V_2 ;
}
if ( V_57 -> V_62 != V_63 ) {
F_40 ( V_23 -> V_24 , V_2 -> V_14 , V_2 -> V_61 ,
V_57 -> V_62 ) ;
V_57 -> V_62 = V_63 ;
}
V_39 = F_44 ( V_23 -> V_24 , V_2 -> V_14 , V_2 -> V_61 , V_62 ) ;
if ( V_39 <= 0 ) {
F_33 ( L_5 ) ;
F_43 ( V_66 ) ;
return F_25 ( - V_68 ) ;
}
V_57 -> V_62 = V_62 ;
F_43 ( V_66 ) ;
return V_2 ;
}
static void F_45 ( struct V_54 * V_23 ,
struct V_1 * V_2 , enum V_64 V_62 )
{
}
static void F_46 ( struct V_52 * V_53 )
{
F_17 ( V_53 -> V_60 ) ;
}
static void * F_47 ( struct V_52 * V_53 , unsigned long V_69 )
{
struct V_17 * V_18 = V_53 -> V_60 ;
return V_18 -> V_20 + V_69 * V_70 ;
}
static void * F_48 ( struct V_52 * V_53 )
{
struct V_17 * V_18 = V_53 -> V_60 ;
return V_18 -> V_20 ;
}
static int F_49 ( struct V_52 * V_53 ,
struct V_37 * V_38 )
{
return F_30 ( V_53 -> V_60 , V_38 ) ;
}
static struct V_1 * F_50 ( struct V_17 * V_18 )
{
int V_39 ;
struct V_1 * V_2 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
F_27 ( V_18 -> V_24 , L_6 ) ;
return NULL ;
}
V_39 = F_52 ( V_18 -> V_24 , V_2 , V_18 -> V_20 , V_18 -> V_19 ,
V_18 -> V_15 ) ;
if ( V_39 < 0 ) {
F_27 ( V_18 -> V_24 , L_7 ) ;
F_20 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_52 * F_53 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_52 * V_53 ;
if ( ! V_18 -> V_27 )
V_18 -> V_27 = F_50 ( V_18 ) ;
if ( F_54 ( ! V_18 -> V_27 ) )
return NULL ;
V_53 = F_55 ( V_18 , & V_71 , V_18 -> V_15 , 0 ) ;
if ( F_56 ( V_53 ) )
return NULL ;
F_29 ( & V_18 -> V_21 ) ;
return V_53 ;
}
static inline int F_57 ( struct V_37 * V_38 )
{
return ! ! ( V_38 -> V_43 & ( V_72 | V_73 ) ) ;
}
static int F_58 ( unsigned long V_74 , struct V_3 * * V_75 ,
int V_8 , struct V_37 * V_38 , int V_76 )
{
if ( F_57 ( V_38 ) ) {
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 , V_74 += V_70 ) {
unsigned long V_77 ;
int V_39 = F_59 ( V_38 , V_74 , & V_77 ) ;
if ( V_39 ) {
F_33 ( L_8 , V_74 ) ;
return V_39 ;
}
V_75 [ V_7 ] = F_60 ( V_77 ) ;
}
} else {
int V_78 ;
V_78 = F_61 ( V_79 , V_79 -> V_80 , V_74 & V_81 ,
V_8 , V_76 , 1 , V_75 , NULL ) ;
V_78 = F_62 ( V_78 , 0 ) ;
if ( V_78 != V_8 ) {
F_33 ( L_9 , V_78 , V_8 ) ;
while ( V_78 )
F_63 ( V_75 [ -- V_78 ] ) ;
return - V_82 ;
}
}
return 0 ;
}
static void F_64 ( struct V_3 * V_3 )
{
F_65 ( V_3 ) ;
F_63 ( V_3 ) ;
}
static void F_66 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_22 ;
F_40 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_61 , V_18 -> V_26 ) ;
if ( ! F_57 ( V_18 -> V_38 ) )
F_1 ( V_2 , F_64 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_67 ( V_18 -> V_38 ) ;
F_20 ( V_18 ) ;
}
static void * F_68 ( void * V_28 , unsigned long V_20 ,
unsigned long V_15 , int V_76 )
{
struct V_29 * V_30 = V_28 ;
struct V_17 * V_18 ;
unsigned long V_74 ;
unsigned long V_83 ;
unsigned long V_9 ;
struct V_3 * * V_75 ;
int V_8 ;
int V_39 = 0 ;
struct V_37 * V_38 ;
struct V_1 * V_2 ;
unsigned long V_84 ;
unsigned long V_85 = F_69 () ;
if ( ! F_70 ( V_20 | V_15 , V_85 ) ) {
F_34 ( L_10 , V_85 ) ;
return F_25 ( - V_41 ) ;
}
if ( ! V_15 ) {
F_34 ( L_11 ) ;
return F_25 ( - V_41 ) ;
}
V_18 = F_24 ( sizeof *V_18 , V_32 ) ;
if ( ! V_18 )
return F_25 ( - V_33 ) ;
V_18 -> V_24 = V_30 -> V_24 ;
V_18 -> V_26 = V_76 ? V_86 : V_87 ;
V_74 = V_20 & V_81 ;
V_9 = V_20 & ~ V_81 ;
V_83 = F_5 ( V_20 + V_15 ) ;
V_8 = ( V_83 - V_74 ) >> V_11 ;
V_75 = F_51 ( V_8 * sizeof( V_75 [ 0 ] ) , V_32 ) ;
if ( ! V_75 ) {
V_39 = - V_33 ;
F_33 ( L_12 ) ;
goto V_88;
}
V_38 = F_71 ( V_79 -> V_80 , V_20 ) ;
if ( ! V_38 ) {
F_33 ( L_13 , V_20 ) ;
V_39 = - V_82 ;
goto V_89;
}
if ( V_38 -> V_90 < V_20 + V_15 ) {
F_33 ( L_14 , V_20 , V_15 ) ;
V_39 = - V_82 ;
goto V_89;
}
V_18 -> V_38 = F_72 ( V_38 ) ;
if ( ! V_18 -> V_38 ) {
F_33 ( L_15 ) ;
V_39 = - V_33 ;
goto V_89;
}
V_39 = F_58 ( V_74 , V_75 , V_8 , V_38 , V_76 ) ;
if ( V_39 ) {
F_33 ( L_16 ) ;
goto V_91;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 ) {
F_33 ( L_17 ) ;
V_39 = - V_33 ;
goto V_92;
}
V_39 = F_73 ( V_2 , V_75 , V_8 ,
V_9 , V_15 , V_32 ) ;
if ( V_39 ) {
F_33 ( L_18 ) ;
goto V_93;
}
F_20 ( V_75 ) ;
V_75 = NULL ;
V_2 -> V_25 = F_44 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_61 ,
V_18 -> V_26 ) ;
if ( V_2 -> V_25 <= 0 ) {
F_33 ( L_5 ) ;
V_39 = - V_68 ;
goto V_94;
}
V_84 = F_6 ( V_2 ) ;
if ( V_84 < V_15 ) {
F_33 ( L_19 ,
V_84 , V_15 ) ;
V_39 = - V_82 ;
goto V_95;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_22 = V_2 ;
return V_18 ;
V_95:
F_40 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_61 , V_18 -> V_26 ) ;
V_94:
if ( ! F_57 ( V_18 -> V_38 ) )
F_1 ( V_2 , F_63 ) ;
F_19 ( V_2 ) ;
V_93:
F_20 ( V_2 ) ;
V_92:
if ( V_75 && ! F_57 ( V_18 -> V_38 ) )
while ( V_8 )
F_63 ( V_75 [ -- V_8 ] ) ;
V_91:
F_67 ( V_18 -> V_38 ) ;
V_89:
F_20 ( V_75 ) ;
V_88:
F_20 ( V_18 ) ;
return F_25 ( V_39 ) ;
}
static int F_74 ( void * V_96 )
{
struct V_17 * V_18 = V_96 ;
struct V_1 * V_2 ;
unsigned long V_84 ;
if ( F_54 ( ! V_18 -> V_23 ) ) {
F_33 ( L_20 ) ;
return - V_41 ;
}
if ( F_54 ( V_18 -> V_22 ) ) {
F_33 ( L_21 ) ;
return 0 ;
}
V_2 = F_75 ( V_18 -> V_23 , V_18 -> V_26 ) ;
if ( F_76 ( V_2 ) ) {
F_33 ( L_22 ) ;
return - V_41 ;
}
V_84 = F_6 ( V_2 ) ;
if ( V_84 < V_18 -> V_15 ) {
F_33 ( L_23 ,
V_84 , V_18 -> V_15 ) ;
F_77 ( V_18 -> V_23 , V_2 , V_18 -> V_26 ) ;
return - V_82 ;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_22 = V_2 ;
return 0 ;
}
static void F_78 ( void * V_96 )
{
struct V_17 * V_18 = V_96 ;
struct V_1 * V_2 = V_18 -> V_22 ;
if ( F_54 ( ! V_18 -> V_23 ) ) {
F_33 ( L_24 ) ;
return;
}
if ( F_54 ( ! V_2 ) ) {
F_33 ( L_25 ) ;
return;
}
F_77 ( V_18 -> V_23 , V_2 , V_18 -> V_26 ) ;
V_18 -> V_19 = 0 ;
V_18 -> V_22 = NULL ;
}
static void F_79 ( void * V_96 )
{
struct V_17 * V_18 = V_96 ;
if ( F_54 ( V_18 -> V_19 ) )
F_78 ( V_18 ) ;
F_80 ( V_18 -> V_23 -> V_67 , V_18 -> V_23 ) ;
F_20 ( V_18 ) ;
}
static void * F_81 ( void * V_28 , struct V_52 * V_53 ,
unsigned long V_15 , int V_76 )
{
struct V_29 * V_30 = V_28 ;
struct V_17 * V_18 ;
struct V_54 * V_97 ;
if ( V_53 -> V_15 < V_15 )
return F_25 ( - V_82 ) ;
V_18 = F_24 ( sizeof( * V_18 ) , V_32 ) ;
if ( ! V_18 )
return F_25 ( - V_33 ) ;
V_18 -> V_24 = V_30 -> V_24 ;
V_97 = F_82 ( V_53 , V_18 -> V_24 ) ;
if ( F_56 ( V_97 ) ) {
F_33 ( L_26 ) ;
F_20 ( V_18 ) ;
return V_97 ;
}
V_18 -> V_26 = V_76 ? V_86 : V_87 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_23 = V_97 ;
return V_18 ;
}
void * F_83 ( struct V_31 * V_24 )
{
struct V_29 * V_30 ;
V_30 = F_24 ( sizeof *V_30 , V_32 ) ;
if ( ! V_30 )
return F_25 ( - V_33 ) ;
V_30 -> V_24 = V_24 ;
return V_30 ;
}
void F_84 ( void * V_28 )
{
F_20 ( V_28 ) ;
}
