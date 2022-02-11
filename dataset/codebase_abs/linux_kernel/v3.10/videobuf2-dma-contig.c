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
static void * F_23 ( void * V_28 , unsigned long V_15 , T_2 V_29 )
{
struct V_30 * V_31 = V_28 ;
struct V_32 * V_24 = V_31 -> V_24 ;
struct V_17 * V_18 ;
V_18 = F_24 ( sizeof *V_18 , V_33 ) ;
if ( ! V_18 )
return F_25 ( - V_34 ) ;
V_18 -> V_20 = F_26 ( V_24 , V_15 , & V_18 -> V_19 ,
V_33 | V_29 ) ;
if ( ! V_18 -> V_20 ) {
F_27 ( V_24 , L_1 , V_15 ) ;
F_20 ( V_18 ) ;
return F_25 ( - V_34 ) ;
}
V_18 -> V_24 = F_28 ( V_24 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_35 . V_21 = & V_18 -> V_21 ;
V_18 -> V_35 . V_36 = F_17 ;
V_18 -> V_35 . V_37 = V_18 ;
F_29 ( & V_18 -> V_21 ) ;
return V_18 ;
}
static int F_30 ( void * V_16 , struct V_38 * V_39 )
{
struct V_17 * V_18 = V_16 ;
int V_40 ;
if ( ! V_18 ) {
F_31 ( V_41 L_2 ) ;
return - V_42 ;
}
V_39 -> V_43 = 0 ;
V_40 = F_32 ( V_18 -> V_24 , V_39 , V_18 -> V_20 ,
V_18 -> V_19 , V_18 -> V_15 ) ;
if ( V_40 ) {
F_33 ( L_3 , V_40 ) ;
return V_40 ;
}
V_39 -> V_44 |= V_45 | V_46 ;
V_39 -> V_47 = & V_18 -> V_35 ;
V_39 -> V_48 = & V_49 ;
V_39 -> V_48 -> V_50 ( V_39 ) ;
F_34 ( L_4 ,
V_51 , ( unsigned long ) V_18 -> V_19 , V_39 -> V_52 ,
V_18 -> V_15 ) ;
return 0 ;
}
static int F_35 ( struct V_53 * V_54 , struct V_32 * V_24 ,
struct V_55 * V_56 )
{
struct V_57 * V_58 ;
unsigned int V_7 ;
struct V_5 * V_59 , * V_60 ;
struct V_1 * V_2 ;
struct V_17 * V_18 = V_54 -> V_61 ;
int V_40 ;
V_58 = F_24 ( sizeof( * V_58 ) , V_33 ) ;
if ( ! V_58 )
return - V_34 ;
V_2 = & V_58 -> V_2 ;
V_40 = F_36 ( V_2 , V_18 -> V_27 -> V_62 , V_33 ) ;
if ( V_40 ) {
F_20 ( V_58 ) ;
return - V_34 ;
}
V_59 = V_18 -> V_27 -> V_14 ;
V_60 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_62 ; ++ V_7 ) {
F_37 ( V_60 , F_4 ( V_59 ) , V_59 -> V_10 , V_59 -> V_9 ) ;
V_59 = F_38 ( V_59 ) ;
V_60 = F_38 ( V_60 ) ;
}
V_58 -> V_63 = V_64 ;
V_56 -> V_61 = V_58 ;
return 0 ;
}
static void F_39 ( struct V_53 * V_54 ,
struct V_55 * V_23 )
{
struct V_57 * V_58 = V_23 -> V_61 ;
struct V_1 * V_2 ;
if ( ! V_58 )
return;
V_2 = & V_58 -> V_2 ;
if ( V_58 -> V_63 != V_64 )
F_40 ( V_23 -> V_24 , V_2 -> V_14 , V_2 -> V_62 ,
V_58 -> V_63 ) ;
F_19 ( V_2 ) ;
F_20 ( V_58 ) ;
V_23 -> V_61 = NULL ;
}
static struct V_1 * F_41 (
struct V_55 * V_23 , enum V_65 V_63 )
{
struct V_57 * V_58 = V_23 -> V_61 ;
struct V_66 * V_67 = & V_23 -> V_68 -> V_67 ;
struct V_1 * V_2 ;
int V_40 ;
F_42 ( V_67 ) ;
V_2 = & V_58 -> V_2 ;
if ( V_58 -> V_63 == V_63 ) {
F_43 ( V_67 ) ;
return V_2 ;
}
if ( V_58 -> V_63 != V_64 ) {
F_40 ( V_23 -> V_24 , V_2 -> V_14 , V_2 -> V_62 ,
V_58 -> V_63 ) ;
V_58 -> V_63 = V_64 ;
}
V_40 = F_44 ( V_23 -> V_24 , V_2 -> V_14 , V_2 -> V_62 , V_63 ) ;
if ( V_40 <= 0 ) {
F_33 ( L_5 ) ;
F_43 ( V_67 ) ;
return F_25 ( - V_69 ) ;
}
V_58 -> V_63 = V_63 ;
F_43 ( V_67 ) ;
return V_2 ;
}
static void F_45 ( struct V_55 * V_23 ,
struct V_1 * V_2 , enum V_65 V_63 )
{
}
static void F_46 ( struct V_53 * V_54 )
{
F_17 ( V_54 -> V_61 ) ;
}
static void * F_47 ( struct V_53 * V_54 , unsigned long V_70 )
{
struct V_17 * V_18 = V_54 -> V_61 ;
return V_18 -> V_20 + V_70 * V_71 ;
}
static void * F_48 ( struct V_53 * V_54 )
{
struct V_17 * V_18 = V_54 -> V_61 ;
return V_18 -> V_20 ;
}
static int F_49 ( struct V_53 * V_54 ,
struct V_38 * V_39 )
{
return F_30 ( V_54 -> V_61 , V_39 ) ;
}
static struct V_1 * F_50 ( struct V_17 * V_18 )
{
int V_40 ;
struct V_1 * V_2 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 ) {
F_27 ( V_18 -> V_24 , L_6 ) ;
return NULL ;
}
V_40 = F_52 ( V_18 -> V_24 , V_2 , V_18 -> V_20 , V_18 -> V_19 ,
V_18 -> V_15 ) ;
if ( V_40 < 0 ) {
F_27 ( V_18 -> V_24 , L_7 ) ;
F_20 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_53 * F_53 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_53 * V_54 ;
if ( ! V_18 -> V_27 )
V_18 -> V_27 = F_50 ( V_18 ) ;
if ( F_54 ( ! V_18 -> V_27 ) )
return NULL ;
V_54 = F_55 ( V_18 , & V_72 , V_18 -> V_15 , 0 ) ;
if ( F_56 ( V_54 ) )
return NULL ;
F_29 ( & V_18 -> V_21 ) ;
return V_54 ;
}
static inline int F_57 ( struct V_38 * V_39 )
{
return ! ! ( V_39 -> V_44 & ( V_73 | V_74 ) ) ;
}
static int F_58 ( unsigned long V_75 , struct V_3 * * V_76 ,
int V_8 , struct V_38 * V_39 , int V_77 )
{
if ( F_57 ( V_39 ) ) {
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 , V_75 += V_71 ) {
unsigned long V_78 ;
int V_40 = F_59 ( V_39 , V_75 , & V_78 ) ;
if ( V_40 ) {
F_33 ( L_8 , V_75 ) ;
return V_40 ;
}
V_76 [ V_7 ] = F_60 ( V_78 ) ;
}
} else {
int V_79 ;
V_79 = F_61 ( V_80 , V_80 -> V_81 , V_75 & V_82 ,
V_8 , V_77 , 1 , V_76 , NULL ) ;
V_79 = F_62 ( V_79 , 0 ) ;
if ( V_79 != V_8 ) {
F_33 ( L_9 , V_79 , V_8 ) ;
while ( V_79 )
F_63 ( V_76 [ -- V_79 ] ) ;
return - V_83 ;
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
F_40 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_62 , V_18 -> V_26 ) ;
if ( ! F_57 ( V_18 -> V_39 ) )
F_1 ( V_2 , F_64 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_67 ( V_18 -> V_39 ) ;
F_20 ( V_18 ) ;
}
static void * F_68 ( void * V_28 , unsigned long V_20 ,
unsigned long V_15 , int V_77 )
{
struct V_30 * V_31 = V_28 ;
struct V_17 * V_18 ;
unsigned long V_75 ;
unsigned long V_84 ;
unsigned long V_9 ;
struct V_3 * * V_76 ;
int V_8 ;
int V_40 = 0 ;
struct V_38 * V_39 ;
struct V_1 * V_2 ;
unsigned long V_85 ;
unsigned long V_86 = F_69 () ;
if ( ! F_70 ( V_20 | V_15 , V_86 ) ) {
F_34 ( L_10 , V_86 ) ;
return F_25 ( - V_42 ) ;
}
if ( ! V_15 ) {
F_34 ( L_11 ) ;
return F_25 ( - V_42 ) ;
}
V_18 = F_24 ( sizeof *V_18 , V_33 ) ;
if ( ! V_18 )
return F_25 ( - V_34 ) ;
V_18 -> V_24 = V_31 -> V_24 ;
V_18 -> V_26 = V_77 ? V_87 : V_88 ;
V_75 = V_20 & V_82 ;
V_9 = V_20 & ~ V_82 ;
V_84 = F_5 ( V_20 + V_15 ) ;
V_8 = ( V_84 - V_75 ) >> V_11 ;
V_76 = F_51 ( V_8 * sizeof( V_76 [ 0 ] ) , V_33 ) ;
if ( ! V_76 ) {
V_40 = - V_34 ;
F_33 ( L_12 ) ;
goto V_89;
}
V_39 = F_71 ( V_80 -> V_81 , V_20 ) ;
if ( ! V_39 ) {
F_33 ( L_13 , V_20 ) ;
V_40 = - V_83 ;
goto V_90;
}
if ( V_39 -> V_91 < V_20 + V_15 ) {
F_33 ( L_14 , V_20 , V_15 ) ;
V_40 = - V_83 ;
goto V_90;
}
V_18 -> V_39 = F_72 ( V_39 ) ;
if ( ! V_18 -> V_39 ) {
F_33 ( L_15 ) ;
V_40 = - V_34 ;
goto V_90;
}
V_40 = F_58 ( V_75 , V_76 , V_8 , V_39 , V_77 ) ;
if ( V_40 ) {
F_33 ( L_16 ) ;
goto V_92;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 ) {
F_33 ( L_17 ) ;
V_40 = - V_34 ;
goto V_93;
}
V_40 = F_73 ( V_2 , V_76 , V_8 ,
V_9 , V_15 , V_33 ) ;
if ( V_40 ) {
F_33 ( L_18 ) ;
goto V_94;
}
F_20 ( V_76 ) ;
V_76 = NULL ;
V_2 -> V_25 = F_44 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_62 ,
V_18 -> V_26 ) ;
if ( V_2 -> V_25 <= 0 ) {
F_33 ( L_5 ) ;
V_40 = - V_69 ;
goto V_95;
}
V_85 = F_6 ( V_2 ) ;
if ( V_85 < V_15 ) {
F_33 ( L_19 ,
V_85 , V_15 ) ;
V_40 = - V_83 ;
goto V_96;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_22 = V_2 ;
return V_18 ;
V_96:
F_40 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_62 , V_18 -> V_26 ) ;
V_95:
if ( ! F_57 ( V_18 -> V_39 ) )
F_1 ( V_2 , F_63 ) ;
F_19 ( V_2 ) ;
V_94:
F_20 ( V_2 ) ;
V_93:
if ( V_76 && ! F_57 ( V_18 -> V_39 ) )
while ( V_8 )
F_63 ( V_76 [ -- V_8 ] ) ;
V_92:
F_67 ( V_18 -> V_39 ) ;
V_90:
F_20 ( V_76 ) ;
V_89:
F_20 ( V_18 ) ;
return F_25 ( V_40 ) ;
}
static int F_74 ( void * V_97 )
{
struct V_17 * V_18 = V_97 ;
struct V_1 * V_2 ;
unsigned long V_85 ;
if ( F_54 ( ! V_18 -> V_23 ) ) {
F_33 ( L_20 ) ;
return - V_42 ;
}
if ( F_54 ( V_18 -> V_22 ) ) {
F_33 ( L_21 ) ;
return 0 ;
}
V_2 = F_75 ( V_18 -> V_23 , V_18 -> V_26 ) ;
if ( F_76 ( V_2 ) ) {
F_33 ( L_22 ) ;
return - V_42 ;
}
V_85 = F_6 ( V_2 ) ;
if ( V_85 < V_18 -> V_15 ) {
F_33 ( L_23 ,
V_85 , V_18 -> V_15 ) ;
F_77 ( V_18 -> V_23 , V_2 , V_18 -> V_26 ) ;
return - V_83 ;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_22 = V_2 ;
return 0 ;
}
static void F_78 ( void * V_97 )
{
struct V_17 * V_18 = V_97 ;
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
static void F_79 ( void * V_97 )
{
struct V_17 * V_18 = V_97 ;
if ( F_54 ( V_18 -> V_19 ) )
F_78 ( V_18 ) ;
F_80 ( V_18 -> V_23 -> V_68 , V_18 -> V_23 ) ;
F_20 ( V_18 ) ;
}
static void * F_81 ( void * V_28 , struct V_53 * V_54 ,
unsigned long V_15 , int V_77 )
{
struct V_30 * V_31 = V_28 ;
struct V_17 * V_18 ;
struct V_55 * V_98 ;
if ( V_54 -> V_15 < V_15 )
return F_25 ( - V_83 ) ;
V_18 = F_24 ( sizeof( * V_18 ) , V_33 ) ;
if ( ! V_18 )
return F_25 ( - V_34 ) ;
V_18 -> V_24 = V_31 -> V_24 ;
V_98 = F_82 ( V_54 , V_18 -> V_24 ) ;
if ( F_56 ( V_98 ) ) {
F_33 ( L_26 ) ;
F_20 ( V_18 ) ;
return V_98 ;
}
V_18 -> V_26 = V_77 ? V_87 : V_88 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_23 = V_98 ;
return V_18 ;
}
void * F_83 ( struct V_32 * V_24 )
{
struct V_30 * V_31 ;
V_31 = F_24 ( sizeof *V_31 , V_33 ) ;
if ( ! V_31 )
return F_25 ( - V_34 ) ;
V_31 -> V_24 = V_24 ;
return V_31 ;
}
void F_84 ( void * V_28 )
{
F_20 ( V_28 ) ;
}
