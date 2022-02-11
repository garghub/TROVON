static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
F_3 ( V_3 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_4 = V_4 ;
F_4 ( & V_6 -> V_9 , & V_2 -> V_10 ) ;
return 0 ;
}
static struct V_3 * F_5 ( struct V_1 * V_2 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
F_6 (member, &prime_fpriv->head, entry) {
if ( V_6 -> V_4 == V_4 )
return V_6 -> V_3 ;
}
return NULL ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_3 ,
T_1 * V_4 )
{
struct V_5 * V_6 ;
F_6 (member, &prime_fpriv->head, entry) {
if ( V_6 -> V_3 == V_3 ) {
* V_4 = V_6 -> V_4 ;
return 0 ;
}
}
return - V_11 ;
}
static int F_8 ( struct V_3 * V_3 ,
struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_18 * V_19 = V_3 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_22 ;
V_17 = F_9 ( sizeof( * V_17 ) , V_7 ) ;
if ( ! V_17 )
return - V_8 ;
V_17 -> V_23 = V_24 ;
V_15 -> V_20 = V_17 ;
if ( ! V_22 -> V_25 -> V_26 )
return 0 ;
return V_22 -> V_25 -> V_26 ( V_19 ) ;
}
static void F_10 ( struct V_3 * V_3 ,
struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_20 ;
struct V_18 * V_19 = V_3 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_22 ;
struct V_27 * V_28 ;
if ( V_22 -> V_25 -> V_29 )
V_22 -> V_25 -> V_29 ( V_19 ) ;
if ( ! V_17 )
return;
V_28 = V_17 -> V_28 ;
if ( V_28 ) {
if ( V_17 -> V_23 != V_24 )
F_11 ( V_15 -> V_22 , V_28 -> V_30 , V_28 -> V_31 ,
V_17 -> V_23 ) ;
F_12 ( V_28 ) ;
}
F_13 ( V_28 ) ;
F_13 ( V_17 ) ;
V_15 -> V_20 = NULL ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_5 * V_6 , * V_32 ;
F_15 (member, safe, &prime_fpriv->head, entry) {
if ( V_6 -> V_3 == V_3 ) {
F_16 ( V_3 ) ;
F_17 ( & V_6 -> V_9 ) ;
F_13 ( V_6 ) ;
}
}
}
static struct V_27 * F_18 ( struct V_14 * V_15 ,
enum V_33 V_23 )
{
struct V_16 * V_17 = V_15 -> V_20 ;
struct V_18 * V_19 = V_15 -> V_34 -> V_20 ;
struct V_27 * V_28 ;
if ( F_19 ( V_23 == V_24 || ! V_17 ) )
return F_20 ( - V_35 ) ;
if ( V_17 -> V_23 == V_23 )
return V_17 -> V_28 ;
if ( F_19 ( V_17 -> V_23 != V_24 ) )
return F_20 ( - V_36 ) ;
V_28 = V_19 -> V_22 -> V_25 -> V_37 ( V_19 ) ;
if ( ! F_21 ( V_28 ) ) {
if ( ! F_22 ( V_15 -> V_22 , V_28 -> V_30 , V_28 -> V_31 , V_23 ) ) {
F_12 ( V_28 ) ;
F_13 ( V_28 ) ;
V_28 = F_20 ( - V_8 ) ;
} else {
V_17 -> V_28 = V_28 ;
V_17 -> V_23 = V_23 ;
}
}
return V_28 ;
}
static void F_23 ( struct V_14 * V_15 ,
struct V_27 * V_28 ,
enum V_33 V_23 )
{
}
void F_24 ( struct V_3 * V_3 )
{
struct V_18 * V_19 = V_3 -> V_20 ;
F_25 ( V_19 ) ;
}
static void * F_26 ( struct V_3 * V_3 )
{
struct V_18 * V_19 = V_3 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_22 ;
return V_22 -> V_25 -> V_38 ( V_19 ) ;
}
static void F_27 ( struct V_3 * V_3 , void * V_39 )
{
struct V_18 * V_19 = V_3 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_22 ;
V_22 -> V_25 -> V_40 ( V_19 , V_39 ) ;
}
static void * F_28 ( struct V_3 * V_3 ,
unsigned long V_41 )
{
return NULL ;
}
static void F_29 ( struct V_3 * V_3 ,
unsigned long V_41 , void * V_42 )
{
}
static void * F_30 ( struct V_3 * V_3 ,
unsigned long V_41 )
{
return NULL ;
}
static void F_31 ( struct V_3 * V_3 ,
unsigned long V_41 , void * V_42 )
{
}
static int F_32 ( struct V_3 * V_3 ,
struct V_43 * V_44 )
{
struct V_18 * V_19 = V_3 -> V_20 ;
struct V_21 * V_22 = V_19 -> V_22 ;
if ( ! V_22 -> V_25 -> V_45 )
return - V_46 ;
return V_22 -> V_25 -> V_45 ( V_19 , V_44 ) ;
}
struct V_3 * F_33 ( struct V_21 * V_22 ,
struct V_18 * V_19 , int V_47 )
{
struct V_48 * V_49 = NULL ;
if ( V_22 -> V_25 -> V_50 )
V_49 = V_22 -> V_25 -> V_50 ( V_19 ) ;
return F_34 ( V_19 , & V_51 , V_19 -> V_52 ,
V_47 , V_49 ) ;
}
static struct V_3 * F_35 ( struct V_21 * V_22 ,
struct V_18 * V_19 ,
T_1 V_47 )
{
struct V_3 * V_34 ;
if ( V_19 -> V_53 == 0 ) {
V_34 = F_20 ( - V_11 ) ;
return V_34 ;
}
V_34 = V_22 -> V_25 -> V_54 ( V_22 , V_19 , V_47 ) ;
if ( F_21 ( V_34 ) ) {
return V_34 ;
}
V_19 -> V_3 = V_34 ;
F_3 ( V_19 -> V_3 ) ;
F_36 ( V_19 ) ;
return V_34 ;
}
int F_37 ( struct V_21 * V_22 ,
struct V_55 * V_56 , T_1 V_4 ,
T_1 V_47 ,
int * V_57 )
{
struct V_18 * V_19 ;
int V_58 = 0 ;
struct V_3 * V_34 ;
F_38 ( & V_56 -> V_59 . V_60 ) ;
V_19 = F_39 ( V_22 , V_56 , V_4 ) ;
if ( ! V_19 ) {
V_58 = - V_11 ;
goto V_61;
}
V_34 = F_5 ( & V_56 -> V_59 , V_4 ) ;
if ( V_34 ) {
F_3 ( V_34 ) ;
goto V_62;
}
F_38 ( & V_22 -> V_63 ) ;
if ( V_19 -> V_64 ) {
V_34 = V_19 -> V_64 -> V_34 ;
F_3 ( V_34 ) ;
goto V_65;
}
if ( V_19 -> V_3 ) {
F_3 ( V_19 -> V_3 ) ;
V_34 = V_19 -> V_3 ;
goto V_65;
}
V_34 = F_35 ( V_22 , V_19 , V_47 ) ;
if ( F_21 ( V_34 ) ) {
V_58 = F_40 ( V_34 ) ;
F_41 ( & V_22 -> V_63 ) ;
goto V_66;
}
V_65:
V_58 = F_1 ( & V_56 -> V_59 ,
V_34 , V_4 ) ;
F_41 ( & V_22 -> V_63 ) ;
if ( V_58 )
goto V_67;
V_62:
V_58 = F_42 ( V_34 , V_47 ) ;
if ( V_58 < 0 ) {
goto V_67;
} else {
* V_57 = V_58 ;
V_58 = 0 ;
}
goto V_66;
V_67:
F_16 ( V_34 ) ;
V_66:
F_25 ( V_19 ) ;
V_61:
F_41 ( & V_56 -> V_59 . V_60 ) ;
return V_58 ;
}
struct V_18 * F_43 ( struct V_21 * V_22 ,
struct V_3 * V_3 )
{
struct V_14 * V_15 ;
struct V_27 * V_28 ;
struct V_18 * V_19 ;
int V_58 ;
if ( ! V_22 -> V_25 -> V_68 )
return F_20 ( - V_35 ) ;
if ( V_3 -> V_69 == & V_51 ) {
V_19 = V_3 -> V_20 ;
if ( V_19 -> V_22 == V_22 ) {
F_36 ( V_19 ) ;
return V_19 ;
}
}
V_15 = F_44 ( V_3 , V_22 -> V_22 ) ;
if ( F_21 ( V_15 ) )
return F_45 ( V_15 ) ;
F_3 ( V_3 ) ;
V_28 = F_46 ( V_15 , V_70 ) ;
if ( F_21 ( V_28 ) ) {
V_58 = F_40 ( V_28 ) ;
goto V_71;
}
V_19 = V_22 -> V_25 -> V_68 ( V_22 , V_3 -> V_52 , V_28 ) ;
if ( F_21 ( V_19 ) ) {
V_58 = F_40 ( V_19 ) ;
goto V_72;
}
V_19 -> V_64 = V_15 ;
return V_19 ;
V_72:
F_47 ( V_15 , V_28 , V_70 ) ;
V_71:
F_48 ( V_3 , V_15 ) ;
F_16 ( V_3 ) ;
return F_20 ( V_58 ) ;
}
int F_49 ( struct V_21 * V_22 ,
struct V_55 * V_56 , int V_57 ,
T_1 * V_4 )
{
struct V_3 * V_3 ;
struct V_18 * V_19 ;
int V_58 ;
V_3 = F_50 ( V_57 ) ;
if ( F_21 ( V_3 ) )
return F_40 ( V_3 ) ;
F_38 ( & V_56 -> V_59 . V_60 ) ;
V_58 = F_7 ( & V_56 -> V_59 ,
V_3 , V_4 ) ;
if ( V_58 == 0 )
goto V_73;
F_38 ( & V_22 -> V_63 ) ;
V_19 = V_22 -> V_25 -> V_74 ( V_22 , V_3 ) ;
if ( F_21 ( V_19 ) ) {
V_58 = F_40 ( V_19 ) ;
goto V_61;
}
if ( V_19 -> V_3 ) {
F_19 ( V_19 -> V_3 != V_3 ) ;
} else {
V_19 -> V_3 = V_3 ;
F_3 ( V_3 ) ;
}
V_58 = F_51 ( V_56 , V_19 , V_4 ) ;
F_25 ( V_19 ) ;
if ( V_58 )
goto V_73;
V_58 = F_1 ( & V_56 -> V_59 ,
V_3 , * V_4 ) ;
if ( V_58 )
goto V_75;
F_41 ( & V_56 -> V_59 . V_60 ) ;
F_16 ( V_3 ) ;
return 0 ;
V_75:
F_52 ( V_56 , * V_4 ) ;
V_61:
F_41 ( & V_22 -> V_63 ) ;
V_73:
F_16 ( V_3 ) ;
F_41 ( & V_56 -> V_59 . V_60 ) ;
return V_58 ;
}
int F_53 ( struct V_21 * V_22 , void * V_76 ,
struct V_55 * V_56 )
{
struct V_77 * args = V_76 ;
T_1 V_47 ;
if ( ! F_54 ( V_22 , V_78 ) )
return - V_35 ;
if ( ! V_22 -> V_25 -> V_79 )
return - V_46 ;
if ( args -> V_47 & ~ V_80 )
return - V_35 ;
V_47 = args -> V_47 & V_80 ;
return V_22 -> V_25 -> V_79 ( V_22 , V_56 ,
args -> V_4 , V_47 , & args -> V_81 ) ;
}
int F_55 ( struct V_21 * V_22 , void * V_76 ,
struct V_55 * V_56 )
{
struct V_77 * args = V_76 ;
if ( ! F_54 ( V_22 , V_78 ) )
return - V_35 ;
if ( ! V_22 -> V_25 -> V_82 )
return - V_46 ;
return V_22 -> V_25 -> V_82 ( V_22 , V_56 ,
args -> V_81 , & args -> V_4 ) ;
}
struct V_27 * F_56 ( struct V_83 * * V_84 , int V_85 )
{
struct V_27 * V_86 = NULL ;
int V_58 ;
V_86 = F_2 ( sizeof( struct V_27 ) , V_7 ) ;
if ( ! V_86 ) {
V_58 = - V_8 ;
goto V_66;
}
V_58 = F_57 ( V_86 , V_84 , V_85 , 0 ,
V_85 << V_87 , V_7 ) ;
if ( V_58 )
goto V_66;
return V_86 ;
V_66:
F_13 ( V_86 ) ;
return F_20 ( V_58 ) ;
}
int F_58 ( struct V_27 * V_28 , struct V_83 * * V_84 ,
T_2 * V_88 , int V_89 )
{
unsigned V_90 ;
struct V_91 * V_86 ;
struct V_83 * V_83 ;
T_3 V_92 ;
int V_93 ;
T_2 V_42 ;
V_93 = 0 ;
F_59 (sgt->sgl, sg, sgt->nents, count) {
V_92 = V_86 -> V_94 ;
V_83 = F_60 ( V_86 ) ;
V_42 = F_61 ( V_86 ) ;
while ( V_92 > 0 ) {
if ( F_19 ( V_93 >= V_89 ) )
return - 1 ;
V_84 [ V_93 ] = V_83 ;
if ( V_88 )
V_88 [ V_93 ] = V_42 ;
V_83 ++ ;
V_42 += V_95 ;
V_92 -= V_95 ;
V_93 ++ ;
}
}
return 0 ;
}
void F_62 ( struct V_18 * V_19 , struct V_27 * V_86 )
{
struct V_14 * V_15 ;
struct V_3 * V_3 ;
V_15 = V_19 -> V_64 ;
if ( V_86 )
F_47 ( V_15 , V_86 , V_70 ) ;
V_3 = V_15 -> V_34 ;
F_48 ( V_15 -> V_34 , V_15 ) ;
F_16 ( V_3 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
F_64 ( & V_2 -> V_10 ) ;
F_65 ( & V_2 -> V_60 ) ;
}
void F_66 ( struct V_1 * V_2 )
{
F_19 ( ! F_67 ( & V_2 -> V_10 ) ) ;
}
