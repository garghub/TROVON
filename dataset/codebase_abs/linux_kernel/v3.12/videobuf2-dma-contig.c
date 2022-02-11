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
static int F_58 ( unsigned long V_75 , int V_8 ,
struct V_38 * V_39 , unsigned long * V_76 )
{
unsigned long V_77 , V_78 , V_79 ;
unsigned int V_7 ;
int V_40 ;
if ( ! F_57 ( V_39 ) )
return - V_80 ;
V_40 = F_59 ( V_39 , V_75 , & V_77 ) ;
if ( V_40 )
return V_40 ;
V_78 = V_77 ;
V_75 += V_71 ;
for ( V_7 = 1 ; V_7 < V_8 ; ++ V_7 , V_75 += V_71 ) {
V_79 = V_77 ;
V_40 = F_59 ( V_39 , V_75 , & V_77 ) ;
if ( V_40 ) {
F_33 ( L_8 , V_75 ) ;
return V_40 ;
}
if ( V_77 != V_79 + 1 )
return - V_42 ;
}
* V_76 = V_78 ;
return 0 ;
}
static int F_60 ( unsigned long V_75 , struct V_3 * * V_81 ,
int V_8 , struct V_38 * V_39 , int V_82 )
{
if ( F_57 ( V_39 ) ) {
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 , V_75 += V_71 ) {
unsigned long V_77 ;
int V_40 = F_59 ( V_39 , V_75 , & V_77 ) ;
if ( ! F_61 ( V_77 ) )
return - V_42 ;
if ( V_40 ) {
F_33 ( L_8 , V_75 ) ;
return V_40 ;
}
V_81 [ V_7 ] = F_62 ( V_77 ) ;
}
} else {
int V_83 ;
V_83 = F_63 ( V_84 , V_84 -> V_85 , V_75 & V_86 ,
V_8 , V_82 , 1 , V_81 , NULL ) ;
V_83 = F_64 ( V_83 , 0 ) ;
if ( V_83 != V_8 ) {
F_33 ( L_9 , V_83 , V_8 ) ;
while ( V_83 )
F_65 ( V_81 [ -- V_83 ] ) ;
return - V_80 ;
}
}
return 0 ;
}
static void F_66 ( struct V_3 * V_3 )
{
F_67 ( V_3 ) ;
F_65 ( V_3 ) ;
}
static void F_68 ( void * V_16 )
{
struct V_17 * V_18 = V_16 ;
struct V_1 * V_2 = V_18 -> V_22 ;
if ( V_2 ) {
F_40 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_62 , V_18 -> V_26 ) ;
if ( ! F_57 ( V_18 -> V_39 ) )
F_1 ( V_2 , F_66 ) ;
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
}
F_69 ( V_18 -> V_39 ) ;
F_20 ( V_18 ) ;
}
static inline T_1 F_70 ( struct V_32 * V_24 , unsigned long V_77 )
{
return ( T_1 ) F_71 ( V_24 , V_77 ) ;
}
static inline T_1 F_70 ( struct V_32 * V_24 , unsigned long V_77 )
{
return ( T_1 ) F_72 ( V_77 ) ;
}
static inline T_1 F_70 ( struct V_32 * V_24 , unsigned long V_77 )
{
return ( T_1 ) F_73 ( V_77 ) ;
}
static inline T_1 F_70 ( struct V_32 * V_24 , unsigned long V_77 )
{
return ( T_1 ) ( V_77 ) << V_11 ;
}
static void * F_74 ( void * V_28 , unsigned long V_20 ,
unsigned long V_15 , int V_82 )
{
struct V_30 * V_31 = V_28 ;
struct V_17 * V_18 ;
unsigned long V_75 ;
unsigned long V_87 ;
unsigned long V_9 ;
struct V_3 * * V_81 ;
int V_8 ;
int V_40 = 0 ;
struct V_38 * V_39 ;
struct V_1 * V_2 ;
unsigned long V_88 ;
unsigned long V_89 = F_75 () ;
if ( ! F_76 ( V_20 | V_15 , V_89 ) ) {
F_34 ( L_10 , V_89 ) ;
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
V_18 -> V_26 = V_82 ? V_90 : V_91 ;
V_75 = V_20 & V_86 ;
V_9 = V_20 & ~ V_86 ;
V_87 = F_5 ( V_20 + V_15 ) ;
V_8 = ( V_87 - V_75 ) >> V_11 ;
V_81 = F_51 ( V_8 * sizeof( V_81 [ 0 ] ) , V_33 ) ;
if ( ! V_81 ) {
V_40 = - V_34 ;
F_33 ( L_12 ) ;
goto V_92;
}
V_39 = F_77 ( V_84 -> V_85 , V_20 ) ;
if ( ! V_39 ) {
F_33 ( L_13 , V_20 ) ;
V_40 = - V_80 ;
goto V_93;
}
if ( V_39 -> V_94 < V_20 + V_15 ) {
F_33 ( L_14 , V_20 , V_15 ) ;
V_40 = - V_80 ;
goto V_93;
}
V_18 -> V_39 = F_78 ( V_39 ) ;
if ( ! V_18 -> V_39 ) {
F_33 ( L_15 ) ;
V_40 = - V_34 ;
goto V_93;
}
V_40 = F_60 ( V_75 , V_81 , V_8 , V_39 , V_82 ) ;
if ( V_40 ) {
unsigned long V_77 ;
if ( F_58 ( V_75 , V_8 , V_39 , & V_77 ) == 0 ) {
V_18 -> V_19 = F_70 ( V_18 -> V_24 , V_77 ) ;
V_18 -> V_15 = V_15 ;
F_20 ( V_81 ) ;
return V_18 ;
}
F_33 ( L_16 ) ;
goto V_95;
}
V_2 = F_24 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 ) {
F_33 ( L_17 ) ;
V_40 = - V_34 ;
goto V_96;
}
V_40 = F_79 ( V_2 , V_81 , V_8 ,
V_9 , V_15 , V_33 ) ;
if ( V_40 ) {
F_33 ( L_18 ) ;
goto V_97;
}
F_20 ( V_81 ) ;
V_81 = NULL ;
V_2 -> V_25 = F_44 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_62 ,
V_18 -> V_26 ) ;
if ( V_2 -> V_25 <= 0 ) {
F_33 ( L_5 ) ;
V_40 = - V_69 ;
goto V_98;
}
V_88 = F_6 ( V_2 ) ;
if ( V_88 < V_15 ) {
F_33 ( L_19 ,
V_88 , V_15 ) ;
V_40 = - V_80 ;
goto V_99;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_15 = V_15 ;
V_18 -> V_22 = V_2 ;
return V_18 ;
V_99:
F_40 ( V_18 -> V_24 , V_2 -> V_14 , V_2 -> V_62 , V_18 -> V_26 ) ;
V_98:
if ( ! F_57 ( V_18 -> V_39 ) )
F_1 ( V_2 , F_65 ) ;
F_19 ( V_2 ) ;
V_97:
F_20 ( V_2 ) ;
V_96:
if ( V_81 && ! F_57 ( V_18 -> V_39 ) )
while ( V_8 )
F_65 ( V_81 [ -- V_8 ] ) ;
V_95:
F_69 ( V_18 -> V_39 ) ;
V_93:
F_20 ( V_81 ) ;
V_92:
F_20 ( V_18 ) ;
return F_25 ( V_40 ) ;
}
static int F_80 ( void * V_100 )
{
struct V_17 * V_18 = V_100 ;
struct V_1 * V_2 ;
unsigned long V_88 ;
if ( F_54 ( ! V_18 -> V_23 ) ) {
F_33 ( L_20 ) ;
return - V_42 ;
}
if ( F_54 ( V_18 -> V_22 ) ) {
F_33 ( L_21 ) ;
return 0 ;
}
V_2 = F_81 ( V_18 -> V_23 , V_18 -> V_26 ) ;
if ( F_82 ( V_2 ) ) {
F_33 ( L_22 ) ;
return - V_42 ;
}
V_88 = F_6 ( V_2 ) ;
if ( V_88 < V_18 -> V_15 ) {
F_33 ( L_23 ,
V_88 , V_18 -> V_15 ) ;
F_83 ( V_18 -> V_23 , V_2 , V_18 -> V_26 ) ;
return - V_80 ;
}
V_18 -> V_19 = F_7 ( V_2 -> V_14 ) ;
V_18 -> V_22 = V_2 ;
return 0 ;
}
static void F_84 ( void * V_100 )
{
struct V_17 * V_18 = V_100 ;
struct V_1 * V_2 = V_18 -> V_22 ;
if ( F_54 ( ! V_18 -> V_23 ) ) {
F_33 ( L_24 ) ;
return;
}
if ( F_54 ( ! V_2 ) ) {
F_33 ( L_25 ) ;
return;
}
F_83 ( V_18 -> V_23 , V_2 , V_18 -> V_26 ) ;
V_18 -> V_19 = 0 ;
V_18 -> V_22 = NULL ;
}
static void F_85 ( void * V_100 )
{
struct V_17 * V_18 = V_100 ;
if ( F_54 ( V_18 -> V_19 ) )
F_84 ( V_18 ) ;
F_86 ( V_18 -> V_23 -> V_68 , V_18 -> V_23 ) ;
F_20 ( V_18 ) ;
}
static void * F_87 ( void * V_28 , struct V_53 * V_54 ,
unsigned long V_15 , int V_82 )
{
struct V_30 * V_31 = V_28 ;
struct V_17 * V_18 ;
struct V_55 * V_101 ;
if ( V_54 -> V_15 < V_15 )
return F_25 ( - V_80 ) ;
V_18 = F_24 ( sizeof( * V_18 ) , V_33 ) ;
if ( ! V_18 )
return F_25 ( - V_34 ) ;
V_18 -> V_24 = V_31 -> V_24 ;
V_101 = F_88 ( V_54 , V_18 -> V_24 ) ;
if ( F_56 ( V_101 ) ) {
F_33 ( L_26 ) ;
F_20 ( V_18 ) ;
return V_101 ;
}
V_18 -> V_26 = V_82 ? V_90 : V_91 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_23 = V_101 ;
return V_18 ;
}
void * F_89 ( struct V_32 * V_24 )
{
struct V_30 * V_31 ;
V_31 = F_24 ( sizeof *V_31 , V_33 ) ;
if ( ! V_31 )
return F_25 ( - V_34 ) ;
V_31 -> V_24 = V_24 ;
return V_31 ;
}
void F_90 ( void * V_28 )
{
F_20 ( V_28 ) ;
}
