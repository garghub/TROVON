static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 , T_1 V_4 )
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
struct V_27 * V_28 , enum V_33 V_23 )
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
return F_34 ( V_19 , & V_48 , V_19 -> V_49 , V_47 ) ;
}
static struct V_3 * F_35 ( struct V_21 * V_22 ,
struct V_18 * V_19 ,
T_1 V_47 )
{
struct V_3 * V_34 ;
if ( V_19 -> V_50 == 0 ) {
V_34 = F_20 ( - V_11 ) ;
return V_34 ;
}
V_34 = V_22 -> V_25 -> V_51 ( V_22 , V_19 , V_47 ) ;
if ( F_21 ( V_34 ) ) {
return V_34 ;
}
V_19 -> V_3 = V_34 ;
F_3 ( V_19 -> V_3 ) ;
F_36 ( V_19 ) ;
return V_34 ;
}
int F_37 ( struct V_21 * V_22 ,
struct V_52 * V_53 , T_1 V_4 , T_1 V_47 ,
int * V_54 )
{
struct V_18 * V_19 ;
int V_55 = 0 ;
struct V_3 * V_34 ;
F_38 ( & V_53 -> V_56 . V_57 ) ;
V_19 = F_39 ( V_22 , V_53 , V_4 ) ;
if ( ! V_19 ) {
V_55 = - V_11 ;
goto V_58;
}
V_34 = F_5 ( & V_53 -> V_56 , V_4 ) ;
if ( V_34 ) {
F_3 ( V_34 ) ;
goto V_59;
}
F_38 ( & V_22 -> V_60 ) ;
if ( V_19 -> V_61 ) {
V_34 = V_19 -> V_61 -> V_34 ;
F_3 ( V_34 ) ;
goto V_62;
}
if ( V_19 -> V_3 ) {
F_3 ( V_19 -> V_3 ) ;
V_34 = V_19 -> V_3 ;
goto V_62;
}
V_34 = F_35 ( V_22 , V_19 , V_47 ) ;
if ( F_21 ( V_34 ) ) {
V_55 = F_40 ( V_34 ) ;
F_41 ( & V_22 -> V_60 ) ;
goto V_63;
}
V_62:
V_55 = F_1 ( & V_53 -> V_56 ,
V_34 , V_4 ) ;
F_41 ( & V_22 -> V_60 ) ;
if ( V_55 )
goto V_64;
V_59:
V_55 = F_42 ( V_34 , V_47 ) ;
if ( V_55 < 0 ) {
goto V_64;
} else {
* V_54 = V_55 ;
V_55 = 0 ;
}
goto V_63;
V_64:
F_16 ( V_34 ) ;
V_63:
F_25 ( V_19 ) ;
V_58:
F_41 ( & V_53 -> V_56 . V_57 ) ;
return V_55 ;
}
struct V_18 * F_43 ( struct V_21 * V_22 ,
struct V_3 * V_3 )
{
struct V_14 * V_15 ;
struct V_27 * V_28 ;
struct V_18 * V_19 ;
int V_55 ;
if ( ! V_22 -> V_25 -> V_65 )
return F_20 ( - V_35 ) ;
if ( V_3 -> V_66 == & V_48 ) {
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
V_28 = F_46 ( V_15 , V_67 ) ;
if ( F_47 ( V_28 ) ) {
V_55 = F_40 ( V_28 ) ;
goto V_68;
}
V_19 = V_22 -> V_25 -> V_65 ( V_22 , V_3 -> V_49 , V_28 ) ;
if ( F_21 ( V_19 ) ) {
V_55 = F_40 ( V_19 ) ;
goto V_69;
}
V_19 -> V_61 = V_15 ;
return V_19 ;
V_69:
F_48 ( V_15 , V_28 , V_67 ) ;
V_68:
F_49 ( V_3 , V_15 ) ;
F_16 ( V_3 ) ;
return F_20 ( V_55 ) ;
}
int F_50 ( struct V_21 * V_22 ,
struct V_52 * V_53 , int V_54 , T_1 * V_4 )
{
struct V_3 * V_3 ;
struct V_18 * V_19 ;
int V_55 ;
V_3 = F_51 ( V_54 ) ;
if ( F_21 ( V_3 ) )
return F_40 ( V_3 ) ;
F_38 ( & V_53 -> V_56 . V_57 ) ;
V_55 = F_7 ( & V_53 -> V_56 ,
V_3 , V_4 ) ;
if ( V_55 == 0 )
goto V_70;
F_38 ( & V_22 -> V_60 ) ;
V_19 = V_22 -> V_25 -> V_71 ( V_22 , V_3 ) ;
if ( F_21 ( V_19 ) ) {
V_55 = F_40 ( V_19 ) ;
goto V_58;
}
if ( V_19 -> V_3 ) {
F_19 ( V_19 -> V_3 != V_3 ) ;
} else {
V_19 -> V_3 = V_3 ;
F_3 ( V_3 ) ;
}
V_55 = F_52 ( V_53 , V_19 , V_4 ) ;
F_25 ( V_19 ) ;
if ( V_55 )
goto V_70;
V_55 = F_1 ( & V_53 -> V_56 ,
V_3 , * V_4 ) ;
if ( V_55 )
goto V_72;
F_41 ( & V_53 -> V_56 . V_57 ) ;
F_16 ( V_3 ) ;
return 0 ;
V_72:
F_53 ( V_53 , * V_4 ) ;
V_58:
F_41 ( & V_22 -> V_60 ) ;
V_70:
F_16 ( V_3 ) ;
F_41 ( & V_53 -> V_56 . V_57 ) ;
return V_55 ;
}
int F_54 ( struct V_21 * V_22 , void * V_73 ,
struct V_52 * V_53 )
{
struct V_74 * args = V_73 ;
T_1 V_47 ;
if ( ! F_55 ( V_22 , V_75 ) )
return - V_35 ;
if ( ! V_22 -> V_25 -> V_76 )
return - V_46 ;
if ( args -> V_47 & ~ V_77 )
return - V_35 ;
V_47 = args -> V_47 & V_77 ;
return V_22 -> V_25 -> V_76 ( V_22 , V_53 ,
args -> V_4 , V_47 , & args -> V_78 ) ;
}
int F_56 ( struct V_21 * V_22 , void * V_73 ,
struct V_52 * V_53 )
{
struct V_74 * args = V_73 ;
if ( ! F_55 ( V_22 , V_75 ) )
return - V_35 ;
if ( ! V_22 -> V_25 -> V_79 )
return - V_46 ;
return V_22 -> V_25 -> V_79 ( V_22 , V_53 ,
args -> V_78 , & args -> V_4 ) ;
}
struct V_27 * F_57 ( struct V_80 * * V_81 , int V_82 )
{
struct V_27 * V_83 = NULL ;
int V_55 ;
V_83 = F_2 ( sizeof( struct V_27 ) , V_7 ) ;
if ( ! V_83 ) {
V_55 = - V_8 ;
goto V_63;
}
V_55 = F_58 ( V_83 , V_81 , V_82 , 0 ,
V_82 << V_84 , V_7 ) ;
if ( V_55 )
goto V_63;
return V_83 ;
V_63:
F_13 ( V_83 ) ;
return F_20 ( V_55 ) ;
}
int F_59 ( struct V_27 * V_28 , struct V_80 * * V_81 ,
T_2 * V_85 , int V_86 )
{
unsigned V_87 ;
struct V_88 * V_83 ;
struct V_80 * V_80 ;
T_3 V_89 , V_90 ;
int V_91 ;
T_2 V_42 ;
V_91 = 0 ;
F_60 (sgt->sgl, sg, sgt->nents, count) {
V_89 = V_83 -> V_92 ;
V_90 = V_83 -> V_90 ;
V_80 = F_61 ( V_83 ) ;
V_42 = F_62 ( V_83 ) ;
while ( V_89 > 0 ) {
if ( F_19 ( V_91 >= V_86 ) )
return - 1 ;
V_81 [ V_91 ] = V_80 ;
if ( V_85 )
V_85 [ V_91 ] = V_42 ;
V_80 ++ ;
V_42 += V_93 ;
V_89 -= V_93 ;
V_91 ++ ;
}
}
return 0 ;
}
void F_63 ( struct V_18 * V_19 , struct V_27 * V_83 )
{
struct V_14 * V_15 ;
struct V_3 * V_3 ;
V_15 = V_19 -> V_61 ;
if ( V_83 )
F_48 ( V_15 , V_83 , V_67 ) ;
V_3 = V_15 -> V_34 ;
F_49 ( V_15 -> V_34 , V_15 ) ;
F_16 ( V_3 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_65 ( & V_2 -> V_10 ) ;
F_66 ( & V_2 -> V_57 ) ;
}
void F_67 ( struct V_1 * V_2 )
{
F_19 ( ! F_68 ( & V_2 -> V_10 ) ) ;
}
