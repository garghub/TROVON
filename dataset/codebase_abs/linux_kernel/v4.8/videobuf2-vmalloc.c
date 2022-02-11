static void * F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 , enum V_5 V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 | V_7 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_4 = V_4 ;
V_9 -> V_11 = F_3 ( V_9 -> V_4 ) ;
V_9 -> V_6 = V_6 ;
V_9 -> V_12 . V_13 = & V_9 -> V_13 ;
V_9 -> V_12 . V_14 = V_15 ;
V_9 -> V_12 . V_16 = V_9 ;
if ( ! V_9 -> V_11 ) {
F_4 ( L_1 , V_9 -> V_4 ) ;
F_5 ( V_9 ) ;
return NULL ;
}
F_6 ( & V_9 -> V_13 ) ;
return V_9 ;
}
static void V_15 ( void * V_17 )
{
struct V_8 * V_9 = V_17 ;
if ( F_7 ( & V_9 -> V_13 ) ) {
F_8 ( V_9 -> V_11 ) ;
F_5 ( V_9 ) ;
}
}
static void * F_9 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_4 ,
enum V_5 V_6 )
{
struct V_8 * V_9 ;
struct V_18 * V_19 ;
int V_20 , V_21 , V_22 ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_6 = V_6 ;
V_21 = V_11 & ~ V_23 ;
V_9 -> V_4 = V_4 ;
V_19 = F_10 ( V_11 , V_4 , V_6 == V_24 ) ;
if ( F_11 ( V_19 ) )
goto V_25;
V_9 -> V_19 = V_19 ;
V_20 = F_12 ( V_19 ) ;
if ( F_13 ( V_19 ) < 0 ) {
unsigned long * V_26 = F_14 ( V_19 ) ;
for ( V_22 = 1 ; V_22 < V_20 ; V_22 ++ )
if ( V_26 [ V_22 - 1 ] + 1 != V_26 [ V_22 ] )
goto V_27;
V_9 -> V_11 = ( V_28 void * )
F_15 ( V_26 [ 0 ] << V_29 , V_4 ) ;
} else {
V_9 -> V_11 = F_16 ( F_17 ( V_19 ) , V_20 , - 1 ,
V_30 ) ;
}
if ( ! V_9 -> V_11 )
goto V_27;
V_9 -> V_11 += V_21 ;
return V_9 ;
V_27:
F_18 ( V_19 ) ;
V_25:
F_5 ( V_9 ) ;
return NULL ;
}
static void F_19 ( void * V_17 )
{
struct V_8 * V_9 = V_17 ;
unsigned long V_11 = ( unsigned long ) V_9 -> V_11 & V_23 ;
unsigned int V_22 ;
struct V_31 * * V_32 ;
unsigned int V_20 ;
if ( ! V_9 -> V_19 -> V_33 ) {
V_20 = F_12 ( V_9 -> V_19 ) ;
V_32 = F_17 ( V_9 -> V_19 ) ;
if ( V_11 )
F_20 ( ( void * ) V_11 , V_20 ) ;
if ( V_9 -> V_6 == V_24 )
for ( V_22 = 0 ; V_22 < V_20 ; V_22 ++ )
F_21 ( V_32 [ V_22 ] ) ;
} else {
F_22 ( ( V_28 void V_34 * ) V_9 -> V_11 ) ;
}
F_18 ( V_9 -> V_19 ) ;
F_5 ( V_9 ) ;
}
static void * F_23 ( void * V_17 )
{
struct V_8 * V_9 = V_17 ;
if ( ! V_9 -> V_11 ) {
F_24 ( L_2
L_3 ) ;
return NULL ;
}
return V_9 -> V_11 ;
}
static unsigned int F_25 ( void * V_17 )
{
struct V_8 * V_9 = V_17 ;
return F_26 ( & V_9 -> V_13 ) ;
}
static int F_27 ( void * V_17 , struct V_35 * V_36 )
{
struct V_8 * V_9 = V_17 ;
int V_37 ;
if ( ! V_9 ) {
F_24 ( L_4 ) ;
return - V_38 ;
}
V_37 = F_28 ( V_36 , V_9 -> V_11 , 0 ) ;
if ( V_37 ) {
F_24 ( L_5 , V_37 ) ;
return V_37 ;
}
V_36 -> V_39 |= V_40 ;
V_36 -> V_41 = & V_9 -> V_12 ;
V_36 -> V_42 = & V_43 ;
V_36 -> V_42 -> V_44 ( V_36 ) ;
return 0 ;
}
static int F_29 ( struct V_45 * V_46 , struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_8 * V_9 = V_46 -> V_51 ;
int V_52 = F_30 ( V_9 -> V_4 ) / V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
void * V_11 = V_9 -> V_11 ;
int V_37 ;
int V_22 ;
V_50 = F_2 ( sizeof( * V_50 ) , V_10 ) ;
if ( ! V_50 )
return - V_58 ;
V_55 = & V_50 -> V_55 ;
V_37 = F_31 ( V_55 , V_52 , V_10 ) ;
if ( V_37 ) {
F_5 ( V_50 ) ;
return V_37 ;
}
F_32 (sgt->sgl, sg, sgt->nents, i) {
struct V_31 * V_31 = F_33 ( V_11 ) ;
if ( ! V_31 ) {
F_34 ( V_55 ) ;
F_5 ( V_50 ) ;
return - V_58 ;
}
F_35 ( V_57 , V_31 , V_53 , 0 ) ;
V_11 += V_53 ;
}
V_50 -> V_6 = V_59 ;
V_48 -> V_51 = V_50 ;
return 0 ;
}
static void F_36 ( struct V_45 * V_46 ,
struct V_47 * V_60 )
{
struct V_49 * V_50 = V_60 -> V_51 ;
struct V_54 * V_55 ;
if ( ! V_50 )
return;
V_55 = & V_50 -> V_55 ;
if ( V_50 -> V_6 != V_59 )
F_37 ( V_60 -> V_2 , V_55 -> V_61 , V_55 -> V_62 ,
V_50 -> V_6 ) ;
F_34 ( V_55 ) ;
F_5 ( V_50 ) ;
V_60 -> V_51 = NULL ;
}
static struct V_54 * F_38 (
struct V_47 * V_60 , enum V_5 V_6 )
{
struct V_49 * V_50 = V_60 -> V_51 ;
struct V_63 * V_64 = & V_60 -> V_65 -> V_64 ;
struct V_54 * V_55 ;
F_39 ( V_64 ) ;
V_55 = & V_50 -> V_55 ;
if ( V_50 -> V_6 == V_6 ) {
F_40 ( V_64 ) ;
return V_55 ;
}
if ( V_50 -> V_6 != V_59 ) {
F_37 ( V_60 -> V_2 , V_55 -> V_61 , V_55 -> V_62 ,
V_50 -> V_6 ) ;
V_50 -> V_6 = V_59 ;
}
V_55 -> V_66 = F_41 ( V_60 -> V_2 , V_55 -> V_61 , V_55 -> V_62 ,
V_6 ) ;
if ( ! V_55 -> V_66 ) {
F_24 ( L_6 ) ;
F_40 ( V_64 ) ;
return F_42 ( - V_67 ) ;
}
V_50 -> V_6 = V_6 ;
F_40 ( V_64 ) ;
return V_55 ;
}
static void F_43 ( struct V_47 * V_60 ,
struct V_54 * V_55 , enum V_5 V_6 )
{
}
static void F_44 ( struct V_45 * V_46 )
{
V_15 ( V_46 -> V_51 ) ;
}
static void * F_45 ( struct V_45 * V_46 , unsigned long V_68 )
{
struct V_8 * V_9 = V_46 -> V_51 ;
return V_9 -> V_11 + V_68 * V_53 ;
}
static void * F_46 ( struct V_45 * V_46 )
{
struct V_8 * V_9 = V_46 -> V_51 ;
return V_9 -> V_11 ;
}
static int F_47 ( struct V_45 * V_46 ,
struct V_35 * V_36 )
{
return F_27 ( V_46 -> V_51 , V_36 ) ;
}
static struct V_45 * F_48 ( void * V_17 , unsigned long V_69 )
{
struct V_8 * V_9 = V_17 ;
struct V_45 * V_46 ;
F_49 ( V_70 ) ;
V_70 . V_71 = & V_72 ;
V_70 . V_4 = V_9 -> V_4 ;
V_70 . V_69 = V_69 ;
V_70 . V_51 = V_9 ;
if ( F_50 ( ! V_9 -> V_11 ) )
return NULL ;
V_46 = F_51 ( & V_70 ) ;
if ( F_11 ( V_46 ) )
return NULL ;
F_6 ( & V_9 -> V_13 ) ;
return V_46 ;
}
static int F_52 ( void * V_73 )
{
struct V_8 * V_9 = V_73 ;
V_9 -> V_11 = F_53 ( V_9 -> V_46 ) ;
return V_9 -> V_11 ? 0 : - V_74 ;
}
static void F_54 ( void * V_73 )
{
struct V_8 * V_9 = V_73 ;
F_55 ( V_9 -> V_46 , V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
}
static void F_56 ( void * V_73 )
{
struct V_8 * V_9 = V_73 ;
if ( V_9 -> V_11 )
F_55 ( V_9 -> V_46 , V_9 -> V_11 ) ;
F_5 ( V_9 ) ;
}
static void * F_57 ( struct V_1 * V_2 , struct V_45 * V_46 ,
unsigned long V_4 , enum V_5 V_6 )
{
struct V_8 * V_9 ;
if ( V_46 -> V_4 < V_4 )
return F_42 ( - V_74 ) ;
V_9 = F_2 ( sizeof( * V_9 ) , V_10 ) ;
if ( ! V_9 )
return F_42 ( - V_58 ) ;
V_9 -> V_46 = V_46 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_4 = V_4 ;
return V_9 ;
}
