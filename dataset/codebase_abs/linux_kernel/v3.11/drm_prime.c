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
static int F_5 ( struct V_3 * V_3 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 = V_3 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
V_16 = F_6 ( sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 )
return - V_8 ;
V_16 -> V_22 = V_23 ;
V_14 -> V_19 = V_16 ;
if ( ! V_21 -> V_24 -> V_25 )
return 0 ;
return V_21 -> V_24 -> V_25 ( V_18 ) ;
}
static void F_7 ( struct V_3 * V_3 ,
struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_19 ;
struct V_17 * V_18 = V_3 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
struct V_26 * V_27 ;
if ( V_21 -> V_24 -> V_28 )
V_21 -> V_24 -> V_28 ( V_18 ) ;
if ( ! V_16 )
return;
V_27 = V_16 -> V_27 ;
if ( V_27 ) {
if ( V_16 -> V_22 != V_23 )
F_8 ( V_14 -> V_21 , V_27 -> V_29 , V_27 -> V_30 ,
V_16 -> V_22 ) ;
F_9 ( V_27 ) ;
}
F_10 ( V_27 ) ;
F_10 ( V_16 ) ;
V_14 -> V_19 = NULL ;
}
static void F_11 (
struct V_1 * V_2 ,
struct V_3 * V_3 )
{
struct V_5 * V_6 , * V_31 ;
F_12 (member, safe, &prime_fpriv->head, entry) {
if ( V_6 -> V_3 == V_3 ) {
F_13 ( V_3 ) ;
F_14 ( & V_6 -> V_9 ) ;
F_10 ( V_6 ) ;
}
}
}
static struct V_26 * F_15 ( struct V_13 * V_14 ,
enum V_32 V_22 )
{
struct V_15 * V_16 = V_14 -> V_19 ;
struct V_17 * V_18 = V_14 -> V_33 -> V_19 ;
struct V_26 * V_27 ;
if ( F_16 ( V_22 == V_23 || ! V_16 ) )
return F_17 ( - V_34 ) ;
if ( V_16 -> V_22 == V_22 )
return V_16 -> V_27 ;
if ( F_16 ( V_16 -> V_22 != V_23 ) )
return F_17 ( - V_35 ) ;
F_18 ( & V_18 -> V_21 -> V_36 ) ;
V_27 = V_18 -> V_21 -> V_24 -> V_37 ( V_18 ) ;
if ( ! F_19 ( V_27 ) ) {
if ( ! F_20 ( V_14 -> V_21 , V_27 -> V_29 , V_27 -> V_30 , V_22 ) ) {
F_9 ( V_27 ) ;
F_10 ( V_27 ) ;
V_27 = F_17 ( - V_8 ) ;
} else {
V_16 -> V_27 = V_27 ;
V_16 -> V_22 = V_22 ;
}
}
F_21 ( & V_18 -> V_21 -> V_36 ) ;
return V_27 ;
}
static void F_22 ( struct V_13 * V_14 ,
struct V_26 * V_27 , enum V_32 V_22 )
{
}
static void F_23 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_19 ;
if ( V_18 -> V_38 == V_3 ) {
V_18 -> V_38 = NULL ;
F_24 ( V_18 ) ;
}
}
static void * F_25 ( struct V_3 * V_3 )
{
struct V_17 * V_18 = V_3 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
return V_21 -> V_24 -> V_39 ( V_18 ) ;
}
static void F_26 ( struct V_3 * V_3 , void * V_40 )
{
struct V_17 * V_18 = V_3 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
V_21 -> V_24 -> V_41 ( V_18 , V_40 ) ;
}
static void * F_27 ( struct V_3 * V_3 ,
unsigned long V_42 )
{
return NULL ;
}
static void F_28 ( struct V_3 * V_3 ,
unsigned long V_42 , void * V_43 )
{
}
static void * F_29 ( struct V_3 * V_3 ,
unsigned long V_42 )
{
return NULL ;
}
static void F_30 ( struct V_3 * V_3 ,
unsigned long V_42 , void * V_43 )
{
}
static int F_31 ( struct V_3 * V_3 ,
struct V_44 * V_45 )
{
struct V_17 * V_18 = V_3 -> V_19 ;
struct V_20 * V_21 = V_18 -> V_21 ;
if ( ! V_21 -> V_24 -> V_46 )
return - V_47 ;
return V_21 -> V_24 -> V_46 ( V_18 , V_45 ) ;
}
struct V_3 * F_32 ( struct V_20 * V_21 ,
struct V_17 * V_18 , int V_48 )
{
return F_33 ( V_18 , & V_49 , V_18 -> V_50 , V_48 ) ;
}
int F_34 ( struct V_20 * V_21 ,
struct V_51 * V_52 , T_1 V_4 , T_1 V_48 ,
int * V_53 )
{
struct V_17 * V_18 ;
void * V_54 ;
int V_55 = 0 ;
struct V_3 * V_33 ;
V_18 = F_35 ( V_21 , V_52 , V_4 ) ;
if ( ! V_18 )
return - V_56 ;
F_18 ( & V_52 -> V_57 . V_58 ) ;
if ( V_18 -> V_59 ) {
V_33 = V_18 -> V_59 -> V_33 ;
goto V_60;
}
if ( V_18 -> V_38 ) {
V_33 = V_18 -> V_38 ;
goto V_60;
}
V_54 = V_21 -> V_24 -> V_61 ( V_21 , V_18 , V_48 ) ;
if ( F_19 ( V_54 ) ) {
V_55 = F_36 ( V_54 ) ;
goto V_62;
}
V_18 -> V_38 = V_54 ;
V_55 = F_1 ( & V_52 -> V_57 ,
V_18 -> V_38 , V_4 ) ;
if ( V_55 )
goto V_63;
V_55 = F_37 ( V_54 , V_48 ) ;
if ( V_55 < 0 )
goto V_64;
* V_53 = V_55 ;
F_21 ( & V_52 -> V_57 . V_58 ) ;
return 0 ;
V_60:
F_3 ( V_33 ) ;
V_55 = F_37 ( V_33 , V_48 ) ;
if ( V_55 < 0 ) {
F_13 ( V_33 ) ;
} else {
* V_53 = V_55 ;
V_55 = 0 ;
}
goto V_62;
V_64:
F_11 ( & V_52 -> V_57 , V_54 ) ;
V_63:
V_18 -> V_38 = NULL ;
F_13 ( V_54 ) ;
V_62:
F_24 ( V_18 ) ;
F_21 ( & V_52 -> V_57 . V_58 ) ;
return V_55 ;
}
struct V_17 * F_38 ( struct V_20 * V_21 ,
struct V_3 * V_3 )
{
struct V_13 * V_14 ;
struct V_26 * V_27 ;
struct V_17 * V_18 ;
int V_55 ;
if ( ! V_21 -> V_24 -> V_65 )
return F_17 ( - V_34 ) ;
if ( V_3 -> V_66 == & V_49 ) {
V_18 = V_3 -> V_19 ;
if ( V_18 -> V_21 == V_21 ) {
F_39 ( V_18 ) ;
return V_18 ;
}
}
V_14 = F_40 ( V_3 , V_21 -> V_21 ) ;
if ( F_19 ( V_14 ) )
return F_41 ( V_14 ) ;
F_3 ( V_3 ) ;
V_27 = F_42 ( V_14 , V_67 ) ;
if ( F_43 ( V_27 ) ) {
V_55 = F_36 ( V_27 ) ;
goto V_68;
}
V_18 = V_21 -> V_24 -> V_65 ( V_21 , V_3 -> V_50 , V_27 ) ;
if ( F_19 ( V_18 ) ) {
V_55 = F_36 ( V_18 ) ;
goto V_69;
}
V_18 -> V_59 = V_14 ;
return V_18 ;
V_69:
F_44 ( V_14 , V_27 , V_67 ) ;
V_68:
F_45 ( V_3 , V_14 ) ;
F_13 ( V_3 ) ;
return F_17 ( V_55 ) ;
}
int F_46 ( struct V_20 * V_21 ,
struct V_51 * V_52 , int V_53 , T_1 * V_4 )
{
struct V_3 * V_3 ;
struct V_17 * V_18 ;
int V_55 ;
V_3 = F_47 ( V_53 ) ;
if ( F_19 ( V_3 ) )
return F_36 ( V_3 ) ;
F_18 ( & V_52 -> V_57 . V_58 ) ;
V_55 = F_48 ( & V_52 -> V_57 ,
V_3 , V_4 ) ;
if ( ! V_55 ) {
V_55 = 0 ;
goto V_70;
}
V_18 = V_21 -> V_24 -> V_71 ( V_21 , V_3 ) ;
if ( F_19 ( V_18 ) ) {
V_55 = F_36 ( V_18 ) ;
goto V_70;
}
V_55 = F_49 ( V_52 , V_18 , V_4 ) ;
F_24 ( V_18 ) ;
if ( V_55 )
goto V_70;
V_55 = F_1 ( & V_52 -> V_57 ,
V_3 , * V_4 ) ;
if ( V_55 )
goto V_72;
F_21 ( & V_52 -> V_57 . V_58 ) ;
F_13 ( V_3 ) ;
return 0 ;
V_72:
F_50 ( V_18 ) ;
V_70:
F_13 ( V_3 ) ;
F_21 ( & V_52 -> V_57 . V_58 ) ;
return V_55 ;
}
int F_51 ( struct V_20 * V_21 , void * V_73 ,
struct V_51 * V_52 )
{
struct V_74 * args = V_73 ;
T_1 V_48 ;
if ( ! F_52 ( V_21 , V_75 ) )
return - V_34 ;
if ( ! V_21 -> V_24 -> V_76 )
return - V_47 ;
if ( args -> V_48 & ~ V_77 )
return - V_34 ;
V_48 = args -> V_48 & V_77 ;
return V_21 -> V_24 -> V_76 ( V_21 , V_52 ,
args -> V_4 , V_48 , & args -> V_78 ) ;
}
int F_53 ( struct V_20 * V_21 , void * V_73 ,
struct V_51 * V_52 )
{
struct V_74 * args = V_73 ;
if ( ! F_52 ( V_21 , V_75 ) )
return - V_34 ;
if ( ! V_21 -> V_24 -> V_79 )
return - V_47 ;
return V_21 -> V_24 -> V_79 ( V_21 , V_52 ,
args -> V_78 , & args -> V_4 ) ;
}
struct V_26 * F_54 ( struct V_80 * * V_81 , int V_82 )
{
struct V_26 * V_83 = NULL ;
int V_55 ;
V_83 = F_2 ( sizeof( struct V_26 ) , V_7 ) ;
if ( ! V_83 ) {
V_55 = - V_8 ;
goto V_62;
}
V_55 = F_55 ( V_83 , V_81 , V_82 , 0 ,
V_82 << V_84 , V_7 ) ;
if ( V_55 )
goto V_62;
return V_83 ;
V_62:
F_10 ( V_83 ) ;
return F_17 ( V_55 ) ;
}
int F_56 ( struct V_26 * V_27 , struct V_80 * * V_81 ,
T_2 * V_85 , int V_86 )
{
unsigned V_87 ;
struct V_88 * V_83 ;
struct V_80 * V_80 ;
T_3 V_89 , V_90 ;
int V_91 ;
T_2 V_43 ;
V_91 = 0 ;
F_57 (sgt->sgl, sg, sgt->nents, count) {
V_89 = V_83 -> V_92 ;
V_90 = V_83 -> V_90 ;
V_80 = F_58 ( V_83 ) ;
V_43 = F_59 ( V_83 ) ;
while ( V_89 > 0 ) {
if ( F_16 ( V_91 >= V_86 ) )
return - 1 ;
V_81 [ V_91 ] = V_80 ;
if ( V_85 )
V_85 [ V_91 ] = V_43 ;
V_80 ++ ;
V_43 += V_93 ;
V_89 -= V_93 ;
V_91 ++ ;
}
}
return 0 ;
}
void F_60 ( struct V_17 * V_18 , struct V_26 * V_83 )
{
struct V_13 * V_14 ;
struct V_3 * V_3 ;
V_14 = V_18 -> V_59 ;
if ( V_83 )
F_44 ( V_14 , V_83 , V_67 ) ;
V_3 = V_14 -> V_33 ;
F_45 ( V_14 -> V_33 , V_14 ) ;
F_13 ( V_3 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
F_62 ( & V_2 -> V_10 ) ;
F_63 ( & V_2 -> V_58 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
F_16 ( ! F_65 ( & V_2 -> V_10 ) ) ;
}
int F_48 ( struct V_1 * V_2 , struct V_3 * V_3 , T_1 * V_4 )
{
struct V_5 * V_6 ;
F_66 (member, &prime_fpriv->head, entry) {
if ( V_6 -> V_3 == V_3 ) {
* V_4 = V_6 -> V_4 ;
return 0 ;
}
}
return - V_56 ;
}
void F_67 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
F_18 ( & V_2 -> V_58 ) ;
F_11 ( V_2 , V_3 ) ;
F_21 ( & V_2 -> V_58 ) ;
}
