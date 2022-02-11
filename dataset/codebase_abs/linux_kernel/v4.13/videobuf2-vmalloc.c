static void * F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , enum V_5 V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 | V_7 ) ;
if ( ! V_9 )
return F_3 ( - V_11 ) ;
V_9 -> V_4 = V_4 ;
V_9 -> V_12 = F_4 ( V_9 -> V_4 ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_13 . V_14 = & V_9 -> V_14 ;
V_9 -> V_13 . V_15 = V_16 ;
V_9 -> V_13 . V_17 = V_9 ;
if ( ! V_9 -> V_12 ) {
F_5 ( L_1 , V_9 -> V_4 ) ;
F_6 ( V_9 ) ;
return F_3 ( - V_11 ) ;
}
F_7 ( & V_9 -> V_14 , 1 ) ;
return V_9 ;
}
static void V_16 ( void * V_18 )
{
struct V_8 * V_9 = V_18 ;
if ( F_8 ( & V_9 -> V_14 ) ) {
F_9 ( V_9 -> V_12 ) ;
F_6 ( V_9 ) ;
}
}
static void * F_10 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_4 ,
enum V_5 V_6 )
{
struct V_8 * V_9 ;
struct V_19 * V_20 ;
int V_21 , V_22 , V_23 ;
int V_24 = - V_11 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return F_3 ( - V_11 ) ;
V_9 -> V_6 = V_6 ;
V_22 = V_12 & ~ V_25 ;
V_9 -> V_4 = V_4 ;
V_20 = F_11 ( V_12 , V_4 , V_6 == V_26 ) ;
if ( F_12 ( V_20 ) ) {
V_24 = F_13 ( V_20 ) ;
goto V_27;
}
V_9 -> V_20 = V_20 ;
V_21 = F_14 ( V_20 ) ;
if ( F_15 ( V_20 ) < 0 ) {
unsigned long * V_28 = F_16 ( V_20 ) ;
for ( V_23 = 1 ; V_23 < V_21 ; V_23 ++ )
if ( V_28 [ V_23 - 1 ] + 1 != V_28 [ V_23 ] )
goto V_29;
V_9 -> V_12 = ( V_30 void * )
F_17 ( V_28 [ 0 ] << V_31 , V_4 ) ;
} else {
V_9 -> V_12 = F_18 ( F_19 ( V_20 ) , V_21 , - 1 ,
V_32 ) ;
}
if ( ! V_9 -> V_12 )
goto V_29;
V_9 -> V_12 += V_22 ;
return V_9 ;
V_29:
F_20 ( V_20 ) ;
V_27:
F_6 ( V_9 ) ;
return F_3 ( V_24 ) ;
}
static void F_21 ( void * V_18 )
{
struct V_8 * V_9 = V_18 ;
unsigned long V_12 = ( unsigned long ) V_9 -> V_12 & V_25 ;
unsigned int V_23 ;
struct V_33 * * V_34 ;
unsigned int V_21 ;
if ( ! V_9 -> V_20 -> V_35 ) {
V_21 = F_14 ( V_9 -> V_20 ) ;
V_34 = F_19 ( V_9 -> V_20 ) ;
if ( V_12 )
F_22 ( ( void * ) V_12 , V_21 ) ;
if ( V_9 -> V_6 == V_26 )
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ )
F_23 ( V_34 [ V_23 ] ) ;
} else {
F_24 ( ( V_30 void V_36 * ) V_9 -> V_12 ) ;
}
F_20 ( V_9 -> V_20 ) ;
F_6 ( V_9 ) ;
}
static void * F_25 ( void * V_18 )
{
struct V_8 * V_9 = V_18 ;
if ( ! V_9 -> V_12 ) {
F_26 ( L_2 ) ;
return NULL ;
}
return V_9 -> V_12 ;
}
static unsigned int F_27 ( void * V_18 )
{
struct V_8 * V_9 = V_18 ;
return F_28 ( & V_9 -> V_14 ) ;
}
static int F_29 ( void * V_18 , struct V_37 * V_38 )
{
struct V_8 * V_9 = V_18 ;
int V_24 ;
if ( ! V_9 ) {
F_26 ( L_3 ) ;
return - V_39 ;
}
V_24 = F_30 ( V_38 , V_9 -> V_12 , 0 ) ;
if ( V_24 ) {
F_26 ( L_4 , V_24 ) ;
return V_24 ;
}
V_38 -> V_40 |= V_41 ;
V_38 -> V_42 = & V_9 -> V_13 ;
V_38 -> V_43 = & V_44 ;
V_38 -> V_43 -> V_45 ( V_38 ) ;
return 0 ;
}
static int F_31 ( struct V_46 * V_47 , struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_8 * V_9 = V_47 -> V_52 ;
int V_53 = F_32 ( V_9 -> V_4 ) / V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
void * V_12 = V_9 -> V_12 ;
int V_24 ;
int V_23 ;
V_51 = F_2 ( sizeof( * V_51 ) , V_10 ) ;
if ( ! V_51 )
return - V_11 ;
V_56 = & V_51 -> V_56 ;
V_24 = F_33 ( V_56 , V_53 , V_10 ) ;
if ( V_24 ) {
F_6 ( V_51 ) ;
return V_24 ;
}
F_34 (sgt->sgl, sg, sgt->nents, i) {
struct V_33 * V_33 = F_35 ( V_12 ) ;
if ( ! V_33 ) {
F_36 ( V_56 ) ;
F_6 ( V_51 ) ;
return - V_11 ;
}
F_37 ( V_58 , V_33 , V_54 , 0 ) ;
V_12 += V_54 ;
}
V_51 -> V_6 = V_59 ;
V_49 -> V_52 = V_51 ;
return 0 ;
}
static void F_38 ( struct V_46 * V_47 ,
struct V_48 * V_60 )
{
struct V_50 * V_51 = V_60 -> V_52 ;
struct V_55 * V_56 ;
if ( ! V_51 )
return;
V_56 = & V_51 -> V_56 ;
if ( V_51 -> V_6 != V_59 )
F_39 ( V_60 -> V_2 , V_56 -> V_61 , V_56 -> V_62 ,
V_51 -> V_6 ) ;
F_36 ( V_56 ) ;
F_6 ( V_51 ) ;
V_60 -> V_52 = NULL ;
}
static struct V_55 * F_40 (
struct V_48 * V_60 , enum V_5 V_6 )
{
struct V_50 * V_51 = V_60 -> V_52 ;
struct V_63 * V_64 = & V_60 -> V_65 -> V_64 ;
struct V_55 * V_56 ;
F_41 ( V_64 ) ;
V_56 = & V_51 -> V_56 ;
if ( V_51 -> V_6 == V_6 ) {
F_42 ( V_64 ) ;
return V_56 ;
}
if ( V_51 -> V_6 != V_59 ) {
F_39 ( V_60 -> V_2 , V_56 -> V_61 , V_56 -> V_62 ,
V_51 -> V_6 ) ;
V_51 -> V_6 = V_59 ;
}
V_56 -> V_66 = F_43 ( V_60 -> V_2 , V_56 -> V_61 , V_56 -> V_62 ,
V_6 ) ;
if ( ! V_56 -> V_66 ) {
F_26 ( L_5 ) ;
F_42 ( V_64 ) ;
return F_3 ( - V_67 ) ;
}
V_51 -> V_6 = V_6 ;
F_42 ( V_64 ) ;
return V_56 ;
}
static void F_44 ( struct V_48 * V_60 ,
struct V_55 * V_56 , enum V_5 V_6 )
{
}
static void F_45 ( struct V_46 * V_47 )
{
V_16 ( V_47 -> V_52 ) ;
}
static void * F_46 ( struct V_46 * V_47 , unsigned long V_68 )
{
struct V_8 * V_9 = V_47 -> V_52 ;
return V_9 -> V_12 + V_68 * V_54 ;
}
static void * F_47 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = V_47 -> V_52 ;
return V_9 -> V_12 ;
}
static int F_48 ( struct V_46 * V_47 ,
struct V_37 * V_38 )
{
return F_29 ( V_47 -> V_52 , V_38 ) ;
}
static struct V_46 * F_49 ( void * V_18 , unsigned long V_69 )
{
struct V_8 * V_9 = V_18 ;
struct V_46 * V_47 ;
F_50 ( V_70 ) ;
V_70 . V_71 = & V_72 ;
V_70 . V_4 = V_9 -> V_4 ;
V_70 . V_69 = V_69 ;
V_70 . V_52 = V_9 ;
if ( F_51 ( ! V_9 -> V_12 ) )
return NULL ;
V_47 = F_52 ( & V_70 ) ;
if ( F_12 ( V_47 ) )
return NULL ;
F_53 ( & V_9 -> V_14 ) ;
return V_47 ;
}
static int F_54 ( void * V_73 )
{
struct V_8 * V_9 = V_73 ;
V_9 -> V_12 = F_55 ( V_9 -> V_47 ) ;
return V_9 -> V_12 ? 0 : - V_74 ;
}
static void F_56 ( void * V_73 )
{
struct V_8 * V_9 = V_73 ;
F_57 ( V_9 -> V_47 , V_9 -> V_12 ) ;
V_9 -> V_12 = NULL ;
}
static void F_58 ( void * V_73 )
{
struct V_8 * V_9 = V_73 ;
if ( V_9 -> V_12 )
F_57 ( V_9 -> V_47 , V_9 -> V_12 ) ;
F_6 ( V_9 ) ;
}
static void * F_59 ( struct V_1 * V_2 , struct V_46 * V_47 ,
unsigned long V_4 , enum V_5 V_6 )
{
struct V_8 * V_9 ;
if ( V_47 -> V_4 < V_4 )
return F_3 ( - V_74 ) ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return F_3 ( - V_11 ) ;
V_9 -> V_47 = V_47 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_4 = V_4 ;
return V_9 ;
}
