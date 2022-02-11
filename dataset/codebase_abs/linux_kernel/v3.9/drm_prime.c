static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 -> V_9 ;
struct V_1 * V_10 ;
F_2 ( & V_7 -> V_11 -> V_12 ) ;
V_10 = V_7 -> V_11 -> V_13 -> V_14 ( V_7 ) ;
if ( ! F_3 ( V_10 ) )
F_4 ( V_3 -> V_11 , V_10 -> V_15 , V_10 -> V_16 , V_5 ) ;
F_5 ( & V_7 -> V_11 -> V_12 ) ;
return V_10 ;
}
static void F_6 ( struct V_2 * V_3 ,
struct V_1 * V_10 , enum V_4 V_5 )
{
F_7 ( V_3 -> V_11 , V_10 -> V_15 , V_10 -> V_16 , V_5 ) ;
F_8 ( V_10 ) ;
F_9 ( V_10 ) ;
}
static void F_10 ( struct V_17 * V_17 )
{
struct V_6 * V_7 = V_17 -> V_9 ;
if ( V_7 -> V_18 == V_17 ) {
V_7 -> V_18 = NULL ;
F_11 ( V_7 ) ;
}
}
static void * F_12 ( struct V_17 * V_17 )
{
struct V_6 * V_7 = V_17 -> V_9 ;
struct V_19 * V_11 = V_7 -> V_11 ;
return V_11 -> V_13 -> V_20 ( V_7 ) ;
}
static void F_13 ( struct V_17 * V_17 , void * V_21 )
{
struct V_6 * V_7 = V_17 -> V_9 ;
struct V_19 * V_11 = V_7 -> V_11 ;
V_11 -> V_13 -> V_22 ( V_7 , V_21 ) ;
}
static void * F_14 ( struct V_17 * V_17 ,
unsigned long V_23 )
{
return NULL ;
}
static void F_15 ( struct V_17 * V_17 ,
unsigned long V_23 , void * V_24 )
{
}
static void * F_16 ( struct V_17 * V_17 ,
unsigned long V_23 )
{
return NULL ;
}
static void F_17 ( struct V_17 * V_17 ,
unsigned long V_23 , void * V_24 )
{
}
static int F_18 ( struct V_17 * V_17 ,
struct V_25 * V_26 )
{
return - V_27 ;
}
struct V_17 * F_19 ( struct V_19 * V_11 ,
struct V_6 * V_7 , int V_28 )
{
if ( V_11 -> V_13 -> V_29 ) {
int V_30 = V_11 -> V_13 -> V_29 ( V_7 ) ;
if ( V_30 )
return F_20 ( V_30 ) ;
}
return F_21 ( V_7 , & V_31 , V_7 -> V_32 ,
0600 ) ;
}
int F_22 ( struct V_19 * V_11 ,
struct V_33 * V_34 , T_1 V_35 , T_1 V_28 ,
int * V_36 )
{
struct V_6 * V_7 ;
void * V_37 ;
int V_30 ;
V_7 = F_23 ( V_11 , V_34 , V_35 ) ;
if ( ! V_7 )
return - V_38 ;
F_2 ( & V_34 -> V_39 . V_40 ) ;
if ( V_7 -> V_41 ) {
F_24 ( V_7 -> V_41 -> V_8 ) ;
* V_36 = F_25 ( V_7 -> V_41 -> V_8 , V_28 ) ;
F_11 ( V_7 ) ;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return 0 ;
}
if ( V_7 -> V_18 ) {
F_24 ( V_7 -> V_18 ) ;
* V_36 = F_25 ( V_7 -> V_18 , V_28 ) ;
F_11 ( V_7 ) ;
} else {
V_37 = V_11 -> V_13 -> V_42 ( V_11 , V_7 , V_28 ) ;
if ( F_26 ( V_37 ) ) {
F_11 ( V_7 ) ;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return F_27 ( V_37 ) ;
}
V_7 -> V_18 = V_37 ;
* V_36 = F_25 ( V_37 , V_28 ) ;
}
V_30 = F_28 ( & V_34 -> V_39 ,
V_7 -> V_18 , V_35 ) ;
if ( V_30 ) {
F_11 ( V_7 ) ;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return V_30 ;
}
F_5 ( & V_34 -> V_39 . V_40 ) ;
return 0 ;
}
struct V_6 * F_29 ( struct V_19 * V_11 ,
struct V_17 * V_17 )
{
struct V_2 * V_3 ;
struct V_1 * V_10 ;
struct V_6 * V_7 ;
int V_30 ;
if ( ! V_11 -> V_13 -> V_43 )
return F_20 ( - V_27 ) ;
if ( V_17 -> V_44 == & V_31 ) {
V_7 = V_17 -> V_9 ;
if ( V_7 -> V_11 == V_11 ) {
F_30 ( V_7 ) ;
F_31 ( V_17 ) ;
return V_7 ;
}
}
V_3 = F_32 ( V_17 , V_11 -> V_11 ) ;
if ( F_26 ( V_3 ) )
return F_20 ( F_27 ( V_3 ) ) ;
V_10 = F_33 ( V_3 , V_45 ) ;
if ( F_3 ( V_10 ) ) {
V_30 = F_27 ( V_10 ) ;
goto V_46;
}
V_7 = V_11 -> V_13 -> V_43 ( V_11 , V_17 -> V_32 , V_10 ) ;
if ( F_26 ( V_7 ) ) {
V_30 = F_27 ( V_7 ) ;
goto V_47;
}
V_7 -> V_41 = V_3 ;
return V_7 ;
V_47:
F_34 ( V_3 , V_10 , V_45 ) ;
V_46:
F_35 ( V_17 , V_3 ) ;
return F_20 ( V_30 ) ;
}
int F_36 ( struct V_19 * V_11 ,
struct V_33 * V_34 , int V_36 , T_1 * V_35 )
{
struct V_17 * V_17 ;
struct V_6 * V_7 ;
int V_30 ;
V_17 = F_37 ( V_36 ) ;
if ( F_26 ( V_17 ) )
return F_27 ( V_17 ) ;
F_2 ( & V_34 -> V_39 . V_40 ) ;
V_30 = F_38 ( & V_34 -> V_39 ,
V_17 , V_35 ) ;
if ( ! V_30 ) {
V_30 = 0 ;
goto V_48;
}
V_7 = V_11 -> V_13 -> V_49 ( V_11 , V_17 ) ;
if ( F_26 ( V_7 ) ) {
V_30 = F_27 ( V_7 ) ;
goto V_48;
}
V_30 = F_39 ( V_34 , V_7 , V_35 ) ;
F_11 ( V_7 ) ;
if ( V_30 )
goto V_48;
V_30 = F_28 ( & V_34 -> V_39 ,
V_17 , * V_35 ) ;
if ( V_30 )
goto V_50;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return 0 ;
V_50:
F_40 ( V_7 ) ;
V_48:
F_31 ( V_17 ) ;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return V_30 ;
}
int F_41 ( struct V_19 * V_11 , void * V_51 ,
struct V_33 * V_34 )
{
struct V_52 * args = V_51 ;
T_1 V_28 ;
if ( ! F_42 ( V_11 , V_53 ) )
return - V_27 ;
if ( ! V_11 -> V_13 -> V_54 )
return - V_55 ;
if ( args -> V_28 & ~ V_56 )
return - V_27 ;
V_28 = args -> V_28 & V_56 ;
return V_11 -> V_13 -> V_54 ( V_11 , V_34 ,
args -> V_35 , V_28 , & args -> V_57 ) ;
}
int F_43 ( struct V_19 * V_11 , void * V_51 ,
struct V_33 * V_34 )
{
struct V_52 * args = V_51 ;
if ( ! F_42 ( V_11 , V_53 ) )
return - V_27 ;
if ( ! V_11 -> V_13 -> V_58 )
return - V_55 ;
return V_11 -> V_13 -> V_58 ( V_11 , V_34 ,
args -> V_57 , & args -> V_35 ) ;
}
struct V_1 * F_44 ( struct V_59 * * V_60 , int V_61 )
{
struct V_1 * V_62 = NULL ;
struct V_63 * V_64 ;
int V_65 ;
int V_30 ;
V_62 = F_45 ( sizeof( struct V_1 ) , V_66 ) ;
if ( ! V_62 )
goto V_67;
V_30 = F_46 ( V_62 , V_61 , V_66 ) ;
if ( V_30 )
goto V_67;
F_47 (sg->sgl, iter, nr_pages, i)
F_48 ( V_64 , V_60 [ V_65 ] , V_68 , 0 ) ;
return V_62 ;
V_67:
F_9 ( V_62 ) ;
return NULL ;
}
int F_49 ( struct V_1 * V_10 , struct V_59 * * V_60 ,
T_2 * V_69 , int V_70 )
{
unsigned V_71 ;
struct V_63 * V_62 ;
struct V_59 * V_59 ;
T_3 V_72 , V_73 ;
int V_74 ;
T_2 V_24 ;
V_74 = 0 ;
F_47 (sgt->sgl, sg, sgt->nents, count) {
V_72 = V_62 -> V_75 ;
V_73 = V_62 -> V_73 ;
V_59 = F_50 ( V_62 ) ;
V_24 = F_51 ( V_62 ) ;
while ( V_72 > 0 ) {
if ( F_52 ( V_74 >= V_70 ) )
return - 1 ;
V_60 [ V_74 ] = V_59 ;
if ( V_69 )
V_69 [ V_74 ] = V_24 ;
V_59 ++ ;
V_24 += V_68 ;
V_72 -= V_68 ;
V_74 ++ ;
}
}
return 0 ;
}
void F_53 ( struct V_6 * V_7 , struct V_1 * V_62 )
{
struct V_2 * V_3 ;
struct V_17 * V_17 ;
V_3 = V_7 -> V_41 ;
if ( V_62 )
F_34 ( V_3 , V_62 , V_45 ) ;
V_17 = V_3 -> V_8 ;
F_35 ( V_3 -> V_8 , V_3 ) ;
F_31 ( V_17 ) ;
}
void F_54 ( struct V_76 * V_77 )
{
F_55 ( & V_77 -> V_78 ) ;
F_56 ( & V_77 -> V_40 ) ;
}
void F_57 ( struct V_76 * V_77 )
{
struct V_79 * V_80 , * V_81 ;
F_58 (member, safe, &prime_fpriv->head, entry) {
F_59 ( & V_80 -> V_82 ) ;
F_9 ( V_80 ) ;
}
}
int F_28 ( struct V_76 * V_77 , struct V_17 * V_17 , T_1 V_35 )
{
struct V_79 * V_80 ;
V_80 = F_45 ( sizeof( * V_80 ) , V_66 ) ;
if ( ! V_80 )
return - V_83 ;
V_80 -> V_17 = V_17 ;
V_80 -> V_35 = V_35 ;
F_60 ( & V_80 -> V_82 , & V_77 -> V_78 ) ;
return 0 ;
}
int F_38 ( struct V_76 * V_77 , struct V_17 * V_17 , T_1 * V_35 )
{
struct V_79 * V_80 ;
F_61 (member, &prime_fpriv->head, entry) {
if ( V_80 -> V_17 == V_17 ) {
* V_35 = V_80 -> V_35 ;
return 0 ;
}
}
return - V_38 ;
}
void F_62 ( struct V_76 * V_77 , struct V_17 * V_17 )
{
struct V_79 * V_80 , * V_81 ;
F_2 ( & V_77 -> V_40 ) ;
F_58 (member, safe, &prime_fpriv->head, entry) {
if ( V_80 -> V_17 == V_17 ) {
F_59 ( & V_80 -> V_82 ) ;
F_9 ( V_80 ) ;
}
}
F_5 ( & V_77 -> V_40 ) ;
}
