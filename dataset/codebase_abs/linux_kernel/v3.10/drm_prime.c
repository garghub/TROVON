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
return F_21 ( V_7 , & V_31 , V_7 -> V_32 , V_28 ) ;
}
int F_22 ( struct V_19 * V_11 ,
struct V_33 * V_34 , T_1 V_35 , T_1 V_28 ,
int * V_36 )
{
struct V_6 * V_7 ;
void * V_37 ;
int V_30 = 0 ;
struct V_17 * V_8 ;
V_7 = F_23 ( V_11 , V_34 , V_35 ) ;
if ( ! V_7 )
return - V_38 ;
F_2 ( & V_34 -> V_39 . V_40 ) ;
if ( V_7 -> V_41 ) {
V_8 = V_7 -> V_41 -> V_8 ;
goto V_42;
}
if ( V_7 -> V_18 ) {
V_8 = V_7 -> V_18 ;
goto V_42;
}
V_37 = V_11 -> V_13 -> V_43 ( V_11 , V_7 , V_28 ) ;
if ( F_24 ( V_37 ) ) {
V_30 = F_25 ( V_37 ) ;
goto V_44;
}
V_7 -> V_18 = V_37 ;
V_30 = F_26 ( & V_34 -> V_39 ,
V_7 -> V_18 , V_35 ) ;
if ( V_30 )
goto V_44;
* V_36 = F_27 ( V_37 , V_28 ) ;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return 0 ;
V_42:
F_28 ( V_8 ) ;
* V_36 = F_27 ( V_8 , V_28 ) ;
V_44:
F_11 ( V_7 ) ;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return V_30 ;
}
struct V_6 * F_29 ( struct V_19 * V_11 ,
struct V_17 * V_17 )
{
struct V_2 * V_3 ;
struct V_1 * V_10 ;
struct V_6 * V_7 ;
int V_30 ;
if ( ! V_11 -> V_13 -> V_45 )
return F_20 ( - V_27 ) ;
if ( V_17 -> V_46 == & V_31 ) {
V_7 = V_17 -> V_9 ;
if ( V_7 -> V_11 == V_11 ) {
F_30 ( V_7 ) ;
return V_7 ;
}
}
V_3 = F_31 ( V_17 , V_11 -> V_11 ) ;
if ( F_24 ( V_3 ) )
return F_20 ( F_25 ( V_3 ) ) ;
F_28 ( V_17 ) ;
V_10 = F_32 ( V_3 , V_47 ) ;
if ( F_3 ( V_10 ) ) {
V_30 = F_25 ( V_10 ) ;
goto V_48;
}
V_7 = V_11 -> V_13 -> V_45 ( V_11 , V_17 -> V_32 , V_10 ) ;
if ( F_24 ( V_7 ) ) {
V_30 = F_25 ( V_7 ) ;
goto V_49;
}
V_7 -> V_41 = V_3 ;
return V_7 ;
V_49:
F_33 ( V_3 , V_10 , V_47 ) ;
V_48:
F_34 ( V_17 , V_3 ) ;
F_35 ( V_17 ) ;
return F_20 ( V_30 ) ;
}
int F_36 ( struct V_19 * V_11 ,
struct V_33 * V_34 , int V_36 , T_1 * V_35 )
{
struct V_17 * V_17 ;
struct V_6 * V_7 ;
int V_30 ;
V_17 = F_37 ( V_36 ) ;
if ( F_24 ( V_17 ) )
return F_25 ( V_17 ) ;
F_2 ( & V_34 -> V_39 . V_40 ) ;
V_30 = F_38 ( & V_34 -> V_39 ,
V_17 , V_35 ) ;
if ( ! V_30 ) {
V_30 = 0 ;
goto V_50;
}
V_7 = V_11 -> V_13 -> V_51 ( V_11 , V_17 ) ;
if ( F_24 ( V_7 ) ) {
V_30 = F_25 ( V_7 ) ;
goto V_50;
}
V_30 = F_39 ( V_34 , V_7 , V_35 ) ;
F_11 ( V_7 ) ;
if ( V_30 )
goto V_50;
V_30 = F_26 ( & V_34 -> V_39 ,
V_17 , * V_35 ) ;
if ( V_30 )
goto V_52;
F_5 ( & V_34 -> V_39 . V_40 ) ;
F_35 ( V_17 ) ;
return 0 ;
V_52:
F_40 ( V_7 ) ;
V_50:
F_35 ( V_17 ) ;
F_5 ( & V_34 -> V_39 . V_40 ) ;
return V_30 ;
}
int F_41 ( struct V_19 * V_11 , void * V_53 ,
struct V_33 * V_34 )
{
struct V_54 * args = V_53 ;
T_1 V_28 ;
if ( ! F_42 ( V_11 , V_55 ) )
return - V_27 ;
if ( ! V_11 -> V_13 -> V_56 )
return - V_57 ;
if ( args -> V_28 & ~ V_58 )
return - V_27 ;
V_28 = args -> V_28 & V_58 ;
return V_11 -> V_13 -> V_56 ( V_11 , V_34 ,
args -> V_35 , V_28 , & args -> V_59 ) ;
}
int F_43 ( struct V_19 * V_11 , void * V_53 ,
struct V_33 * V_34 )
{
struct V_54 * args = V_53 ;
if ( ! F_42 ( V_11 , V_55 ) )
return - V_27 ;
if ( ! V_11 -> V_13 -> V_60 )
return - V_57 ;
return V_11 -> V_13 -> V_60 ( V_11 , V_34 ,
args -> V_59 , & args -> V_35 ) ;
}
struct V_1 * F_44 ( struct V_61 * * V_62 , int V_63 )
{
struct V_1 * V_64 = NULL ;
int V_30 ;
V_64 = F_45 ( sizeof( struct V_1 ) , V_65 ) ;
if ( ! V_64 )
goto V_44;
V_30 = F_46 ( V_64 , V_62 , V_63 , 0 ,
V_63 << V_66 , V_65 ) ;
if ( V_30 )
goto V_44;
return V_64 ;
V_44:
F_9 ( V_64 ) ;
return NULL ;
}
int F_47 ( struct V_1 * V_10 , struct V_61 * * V_62 ,
T_2 * V_67 , int V_68 )
{
unsigned V_69 ;
struct V_70 * V_64 ;
struct V_61 * V_61 ;
T_3 V_71 , V_72 ;
int V_73 ;
T_2 V_24 ;
V_73 = 0 ;
F_48 (sgt->sgl, sg, sgt->nents, count) {
V_71 = V_64 -> V_74 ;
V_72 = V_64 -> V_72 ;
V_61 = F_49 ( V_64 ) ;
V_24 = F_50 ( V_64 ) ;
while ( V_71 > 0 ) {
if ( F_51 ( V_73 >= V_68 ) )
return - 1 ;
V_62 [ V_73 ] = V_61 ;
if ( V_67 )
V_67 [ V_73 ] = V_24 ;
V_61 ++ ;
V_24 += V_75 ;
V_71 -= V_75 ;
V_73 ++ ;
}
}
return 0 ;
}
void F_52 ( struct V_6 * V_7 , struct V_1 * V_64 )
{
struct V_2 * V_3 ;
struct V_17 * V_17 ;
V_3 = V_7 -> V_41 ;
if ( V_64 )
F_33 ( V_3 , V_64 , V_47 ) ;
V_17 = V_3 -> V_8 ;
F_34 ( V_3 -> V_8 , V_3 ) ;
F_35 ( V_17 ) ;
}
void F_53 ( struct V_76 * V_77 )
{
F_54 ( & V_77 -> V_78 ) ;
F_55 ( & V_77 -> V_40 ) ;
}
void F_56 ( struct V_76 * V_77 )
{
F_51 ( ! F_57 ( & V_77 -> V_78 ) ) ;
}
static int F_26 ( struct V_76 * V_77 , struct V_17 * V_17 , T_1 V_35 )
{
struct V_79 * V_80 ;
V_80 = F_45 ( sizeof( * V_80 ) , V_65 ) ;
if ( ! V_80 )
return - V_81 ;
F_28 ( V_17 ) ;
V_80 -> V_17 = V_17 ;
V_80 -> V_35 = V_35 ;
F_58 ( & V_80 -> V_82 , & V_77 -> V_78 ) ;
return 0 ;
}
int F_38 ( struct V_76 * V_77 , struct V_17 * V_17 , T_1 * V_35 )
{
struct V_79 * V_80 ;
F_59 (member, &prime_fpriv->head, entry) {
if ( V_80 -> V_17 == V_17 ) {
* V_35 = V_80 -> V_35 ;
return 0 ;
}
}
return - V_38 ;
}
void F_60 ( struct V_76 * V_77 , struct V_17 * V_17 )
{
struct V_79 * V_80 , * V_83 ;
F_2 ( & V_77 -> V_40 ) ;
F_61 (member, safe, &prime_fpriv->head, entry) {
if ( V_80 -> V_17 == V_17 ) {
F_35 ( V_17 ) ;
F_62 ( & V_80 -> V_82 ) ;
F_9 ( V_80 ) ;
}
}
F_5 ( & V_77 -> V_40 ) ;
}
