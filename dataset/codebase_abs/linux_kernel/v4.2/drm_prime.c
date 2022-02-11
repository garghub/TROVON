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
F_34 ( V_48 ) ;
V_48 . V_49 = & V_50 ;
V_48 . V_51 = V_19 -> V_51 ;
V_48 . V_47 = V_47 ;
V_48 . V_20 = V_19 ;
if ( V_22 -> V_25 -> V_52 )
V_48 . V_53 = V_22 -> V_25 -> V_52 ( V_19 ) ;
return F_35 ( & V_48 ) ;
}
static struct V_3 * F_36 ( struct V_21 * V_22 ,
struct V_18 * V_19 ,
T_1 V_47 )
{
struct V_3 * V_34 ;
if ( V_19 -> V_54 == 0 ) {
V_34 = F_20 ( - V_11 ) ;
return V_34 ;
}
V_34 = V_22 -> V_25 -> V_55 ( V_22 , V_19 , V_47 ) ;
if ( F_21 ( V_34 ) ) {
return V_34 ;
}
V_19 -> V_3 = V_34 ;
F_3 ( V_19 -> V_3 ) ;
F_37 ( V_19 ) ;
return V_34 ;
}
int F_38 ( struct V_21 * V_22 ,
struct V_56 * V_57 , T_1 V_4 ,
T_1 V_47 ,
int * V_58 )
{
struct V_18 * V_19 ;
int V_59 = 0 ;
struct V_3 * V_34 ;
F_39 ( & V_57 -> V_60 . V_61 ) ;
V_19 = F_40 ( V_22 , V_57 , V_4 ) ;
if ( ! V_19 ) {
V_59 = - V_11 ;
goto V_62;
}
V_34 = F_5 ( & V_57 -> V_60 , V_4 ) ;
if ( V_34 ) {
F_3 ( V_34 ) ;
goto V_63;
}
F_39 ( & V_22 -> V_64 ) ;
if ( V_19 -> V_65 ) {
V_34 = V_19 -> V_65 -> V_34 ;
F_3 ( V_34 ) ;
goto V_66;
}
if ( V_19 -> V_3 ) {
F_3 ( V_19 -> V_3 ) ;
V_34 = V_19 -> V_3 ;
goto V_66;
}
V_34 = F_36 ( V_22 , V_19 , V_47 ) ;
if ( F_21 ( V_34 ) ) {
V_59 = F_41 ( V_34 ) ;
F_42 ( & V_22 -> V_64 ) ;
goto V_67;
}
V_66:
V_59 = F_1 ( & V_57 -> V_60 ,
V_34 , V_4 ) ;
F_42 ( & V_22 -> V_64 ) ;
if ( V_59 )
goto V_68;
V_63:
V_59 = F_43 ( V_34 , V_47 ) ;
if ( V_59 < 0 ) {
goto V_68;
} else {
* V_58 = V_59 ;
V_59 = 0 ;
}
goto V_67;
V_68:
F_16 ( V_34 ) ;
V_67:
F_25 ( V_19 ) ;
V_62:
F_42 ( & V_57 -> V_60 . V_61 ) ;
return V_59 ;
}
struct V_18 * F_44 ( struct V_21 * V_22 ,
struct V_3 * V_3 )
{
struct V_14 * V_15 ;
struct V_27 * V_28 ;
struct V_18 * V_19 ;
int V_59 ;
if ( V_3 -> V_49 == & V_50 ) {
V_19 = V_3 -> V_20 ;
if ( V_19 -> V_22 == V_22 ) {
F_37 ( V_19 ) ;
return V_19 ;
}
}
if ( ! V_22 -> V_25 -> V_69 )
return F_20 ( - V_35 ) ;
V_15 = F_45 ( V_3 , V_22 -> V_22 ) ;
if ( F_21 ( V_15 ) )
return F_46 ( V_15 ) ;
F_3 ( V_3 ) ;
V_28 = F_47 ( V_15 , V_70 ) ;
if ( F_21 ( V_28 ) ) {
V_59 = F_41 ( V_28 ) ;
goto V_71;
}
V_19 = V_22 -> V_25 -> V_69 ( V_22 , V_15 , V_28 ) ;
if ( F_21 ( V_19 ) ) {
V_59 = F_41 ( V_19 ) ;
goto V_72;
}
V_19 -> V_65 = V_15 ;
return V_19 ;
V_72:
F_48 ( V_15 , V_28 , V_70 ) ;
V_71:
F_49 ( V_3 , V_15 ) ;
F_16 ( V_3 ) ;
return F_20 ( V_59 ) ;
}
int F_50 ( struct V_21 * V_22 ,
struct V_56 * V_57 , int V_58 ,
T_1 * V_4 )
{
struct V_3 * V_3 ;
struct V_18 * V_19 ;
int V_59 ;
V_3 = F_51 ( V_58 ) ;
if ( F_21 ( V_3 ) )
return F_41 ( V_3 ) ;
F_39 ( & V_57 -> V_60 . V_61 ) ;
V_59 = F_7 ( & V_57 -> V_60 ,
V_3 , V_4 ) ;
if ( V_59 == 0 )
goto V_73;
F_39 ( & V_22 -> V_64 ) ;
V_19 = V_22 -> V_25 -> V_74 ( V_22 , V_3 ) ;
if ( F_21 ( V_19 ) ) {
V_59 = F_41 ( V_19 ) ;
goto V_62;
}
if ( V_19 -> V_3 ) {
F_19 ( V_19 -> V_3 != V_3 ) ;
} else {
V_19 -> V_3 = V_3 ;
F_3 ( V_3 ) ;
}
V_59 = F_52 ( V_57 , V_19 , V_4 ) ;
F_25 ( V_19 ) ;
if ( V_59 )
goto V_73;
V_59 = F_1 ( & V_57 -> V_60 ,
V_3 , * V_4 ) ;
if ( V_59 )
goto V_75;
F_42 ( & V_57 -> V_60 . V_61 ) ;
F_16 ( V_3 ) ;
return 0 ;
V_75:
F_53 ( V_57 , * V_4 ) ;
V_62:
F_42 ( & V_22 -> V_64 ) ;
V_73:
F_16 ( V_3 ) ;
F_42 ( & V_57 -> V_60 . V_61 ) ;
return V_59 ;
}
int F_54 ( struct V_21 * V_22 , void * V_76 ,
struct V_56 * V_57 )
{
struct V_77 * args = V_76 ;
T_1 V_47 ;
if ( ! F_55 ( V_22 , V_78 ) )
return - V_35 ;
if ( ! V_22 -> V_25 -> V_79 )
return - V_46 ;
if ( args -> V_47 & ~ V_80 )
return - V_35 ;
V_47 = args -> V_47 & V_80 ;
return V_22 -> V_25 -> V_79 ( V_22 , V_57 ,
args -> V_4 , V_47 , & args -> V_81 ) ;
}
int F_56 ( struct V_21 * V_22 , void * V_76 ,
struct V_56 * V_57 )
{
struct V_77 * args = V_76 ;
if ( ! F_55 ( V_22 , V_78 ) )
return - V_35 ;
if ( ! V_22 -> V_25 -> V_82 )
return - V_46 ;
return V_22 -> V_25 -> V_82 ( V_22 , V_57 ,
args -> V_81 , & args -> V_4 ) ;
}
struct V_27 * F_57 ( struct V_83 * * V_84 , unsigned int V_85 )
{
struct V_27 * V_86 = NULL ;
int V_59 ;
V_86 = F_2 ( sizeof( struct V_27 ) , V_7 ) ;
if ( ! V_86 ) {
V_59 = - V_8 ;
goto V_67;
}
V_59 = F_58 ( V_86 , V_84 , V_85 , 0 ,
V_85 << V_87 , V_7 ) ;
if ( V_59 )
goto V_67;
return V_86 ;
V_67:
F_13 ( V_86 ) ;
return F_20 ( V_59 ) ;
}
int F_59 ( struct V_27 * V_28 , struct V_83 * * V_84 ,
T_2 * V_88 , int V_89 )
{
unsigned V_90 ;
struct V_91 * V_86 ;
struct V_83 * V_83 ;
T_3 V_92 ;
int V_93 ;
T_2 V_42 ;
V_93 = 0 ;
F_60 (sgt->sgl, sg, sgt->nents, count) {
V_92 = V_86 -> V_94 ;
V_83 = F_61 ( V_86 ) ;
V_42 = F_62 ( V_86 ) ;
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
void F_63 ( struct V_18 * V_19 , struct V_27 * V_86 )
{
struct V_14 * V_15 ;
struct V_3 * V_3 ;
V_15 = V_19 -> V_65 ;
if ( V_86 )
F_48 ( V_15 , V_86 , V_70 ) ;
V_3 = V_15 -> V_34 ;
F_49 ( V_15 -> V_34 , V_15 ) ;
F_16 ( V_3 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( & V_2 -> V_10 ) ;
F_66 ( & V_2 -> V_61 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_19 ( ! F_68 ( & V_2 -> V_10 ) ) ;
}
