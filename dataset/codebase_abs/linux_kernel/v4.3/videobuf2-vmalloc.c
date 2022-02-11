static void * F_1 ( void * V_1 , unsigned long V_2 ,
enum V_3 V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 | V_5 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_2 = V_2 ;
V_7 -> V_9 = F_3 ( V_7 -> V_2 ) ;
V_7 -> V_4 = V_4 ;
V_7 -> V_10 . V_11 = & V_7 -> V_11 ;
V_7 -> V_10 . V_12 = V_13 ;
V_7 -> V_10 . V_14 = V_7 ;
if ( ! V_7 -> V_9 ) {
F_4 ( L_1 , V_7 -> V_2 ) ;
F_5 ( V_7 ) ;
return NULL ;
}
F_6 ( & V_7 -> V_11 ) ;
return V_7 ;
}
static void V_13 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
if ( F_7 ( & V_7 -> V_11 ) ) {
F_8 ( V_7 -> V_9 ) ;
F_5 ( V_7 ) ;
}
}
static void * F_9 ( void * V_1 , unsigned long V_9 ,
unsigned long V_2 ,
enum V_3 V_4 )
{
struct V_6 * V_7 ;
struct V_16 * V_17 ;
int V_18 , V_19 , V_20 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_4 = V_4 ;
V_19 = V_9 & ~ V_21 ;
V_7 -> V_2 = V_2 ;
V_17 = F_10 ( V_9 , V_2 , V_4 == V_22 ) ;
if ( F_11 ( V_17 ) )
goto V_23;
V_7 -> V_17 = V_17 ;
V_18 = F_12 ( V_17 ) ;
if ( F_13 ( V_17 ) < 0 ) {
unsigned long * V_24 = F_14 ( V_17 ) ;
for ( V_20 = 1 ; V_20 < V_18 ; V_20 ++ )
if ( V_24 [ V_20 - 1 ] + 1 != V_24 [ V_20 ] )
goto V_25;
V_7 -> V_9 = ( V_26 void * )
F_15 ( V_24 [ 0 ] << V_27 , V_2 ) ;
} else {
V_7 -> V_9 = F_16 ( F_17 ( V_17 ) , V_18 , - 1 ,
V_28 ) ;
}
if ( ! V_7 -> V_9 )
goto V_25;
V_7 -> V_9 += V_19 ;
return V_7 ;
V_25:
F_18 ( V_17 ) ;
V_23:
F_5 ( V_7 ) ;
return NULL ;
}
static void F_19 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
unsigned long V_9 = ( unsigned long ) V_7 -> V_9 & V_21 ;
unsigned int V_20 ;
struct V_29 * * V_30 ;
unsigned int V_18 ;
if ( ! V_7 -> V_17 -> V_31 ) {
V_18 = F_12 ( V_7 -> V_17 ) ;
V_30 = F_17 ( V_7 -> V_17 ) ;
if ( V_9 )
F_20 ( ( void * ) V_9 , V_18 ) ;
if ( V_7 -> V_4 == V_22 )
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ )
F_21 ( V_30 [ V_20 ] ) ;
} else {
F_22 ( ( V_26 void V_32 * ) V_7 -> V_9 ) ;
}
F_18 ( V_7 -> V_17 ) ;
F_5 ( V_7 ) ;
}
static void * F_23 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
if ( ! V_7 -> V_9 ) {
F_24 ( L_2
L_3 ) ;
return NULL ;
}
return V_7 -> V_9 ;
}
static unsigned int F_25 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
return F_26 ( & V_7 -> V_11 ) ;
}
static int F_27 ( void * V_15 , struct V_33 * V_34 )
{
struct V_6 * V_7 = V_15 ;
int V_35 ;
if ( ! V_7 ) {
F_24 ( L_4 ) ;
return - V_36 ;
}
V_35 = F_28 ( V_34 , V_7 -> V_9 , 0 ) ;
if ( V_35 ) {
F_24 ( L_5 , V_35 ) ;
return V_35 ;
}
V_34 -> V_37 |= V_38 ;
V_34 -> V_39 = & V_7 -> V_10 ;
V_34 -> V_40 = & V_41 ;
V_34 -> V_40 -> V_42 ( V_34 ) ;
return 0 ;
}
static int F_29 ( struct V_43 * V_44 , struct V_45 * V_46 ,
struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_6 * V_7 = V_44 -> V_51 ;
int V_52 = F_30 ( V_7 -> V_2 ) / V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
void * V_9 = V_7 -> V_9 ;
int V_35 ;
int V_20 ;
V_50 = F_2 ( sizeof( * V_50 ) , V_8 ) ;
if ( ! V_50 )
return - V_58 ;
V_55 = & V_50 -> V_55 ;
V_35 = F_31 ( V_55 , V_52 , V_8 ) ;
if ( V_35 ) {
F_5 ( V_50 ) ;
return V_35 ;
}
F_32 (sgt->sgl, sg, sgt->nents, i) {
struct V_29 * V_29 = F_33 ( V_9 ) ;
if ( ! V_29 ) {
F_34 ( V_55 ) ;
F_5 ( V_50 ) ;
return - V_58 ;
}
F_35 ( V_57 , V_29 , V_53 , 0 ) ;
V_9 += V_53 ;
}
V_50 -> V_4 = V_59 ;
V_48 -> V_51 = V_50 ;
return 0 ;
}
static void F_36 ( struct V_43 * V_44 ,
struct V_47 * V_60 )
{
struct V_49 * V_50 = V_60 -> V_51 ;
struct V_54 * V_55 ;
if ( ! V_50 )
return;
V_55 = & V_50 -> V_55 ;
if ( V_50 -> V_4 != V_59 )
F_37 ( V_60 -> V_46 , V_55 -> V_61 , V_55 -> V_62 ,
V_50 -> V_4 ) ;
F_34 ( V_55 ) ;
F_5 ( V_50 ) ;
V_60 -> V_51 = NULL ;
}
static struct V_54 * F_38 (
struct V_47 * V_60 , enum V_3 V_4 )
{
struct V_49 * V_50 = V_60 -> V_51 ;
struct V_63 * V_64 = & V_60 -> V_65 -> V_64 ;
struct V_54 * V_55 ;
F_39 ( V_64 ) ;
V_55 = & V_50 -> V_55 ;
if ( V_50 -> V_4 == V_4 ) {
F_40 ( V_64 ) ;
return V_55 ;
}
if ( V_50 -> V_4 != V_59 ) {
F_37 ( V_60 -> V_46 , V_55 -> V_61 , V_55 -> V_62 ,
V_50 -> V_4 ) ;
V_50 -> V_4 = V_59 ;
}
V_55 -> V_66 = F_41 ( V_60 -> V_46 , V_55 -> V_61 , V_55 -> V_62 ,
V_4 ) ;
if ( ! V_55 -> V_66 ) {
F_24 ( L_6 ) ;
F_40 ( V_64 ) ;
return F_42 ( - V_67 ) ;
}
V_50 -> V_4 = V_4 ;
F_40 ( V_64 ) ;
return V_55 ;
}
static void F_43 ( struct V_47 * V_60 ,
struct V_54 * V_55 , enum V_3 V_4 )
{
}
static void F_44 ( struct V_43 * V_44 )
{
V_13 ( V_44 -> V_51 ) ;
}
static void * F_45 ( struct V_43 * V_44 , unsigned long V_68 )
{
struct V_6 * V_7 = V_44 -> V_51 ;
return V_7 -> V_9 + V_68 * V_53 ;
}
static void * F_46 ( struct V_43 * V_44 )
{
struct V_6 * V_7 = V_44 -> V_51 ;
return V_7 -> V_9 ;
}
static int F_47 ( struct V_43 * V_44 ,
struct V_33 * V_34 )
{
return F_27 ( V_44 -> V_51 , V_34 ) ;
}
static struct V_43 * F_48 ( void * V_15 , unsigned long V_69 )
{
struct V_6 * V_7 = V_15 ;
struct V_43 * V_44 ;
F_49 ( V_70 ) ;
V_70 . V_71 = & V_72 ;
V_70 . V_2 = V_7 -> V_2 ;
V_70 . V_69 = V_69 ;
V_70 . V_51 = V_7 ;
if ( F_50 ( ! V_7 -> V_9 ) )
return NULL ;
V_44 = F_51 ( & V_70 ) ;
if ( F_11 ( V_44 ) )
return NULL ;
F_6 ( & V_7 -> V_11 ) ;
return V_44 ;
}
static int F_52 ( void * V_73 )
{
struct V_6 * V_7 = V_73 ;
V_7 -> V_9 = F_53 ( V_7 -> V_44 ) ;
return V_7 -> V_9 ? 0 : - V_74 ;
}
static void F_54 ( void * V_73 )
{
struct V_6 * V_7 = V_73 ;
F_55 ( V_7 -> V_44 , V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
static void F_56 ( void * V_73 )
{
struct V_6 * V_7 = V_73 ;
if ( V_7 -> V_9 )
F_55 ( V_7 -> V_44 , V_7 -> V_9 ) ;
F_5 ( V_7 ) ;
}
static void * F_57 ( void * V_1 , struct V_43 * V_44 ,
unsigned long V_2 , enum V_3 V_4 )
{
struct V_6 * V_7 ;
if ( V_44 -> V_2 < V_2 )
return F_42 ( - V_74 ) ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_42 ( - V_58 ) ;
V_7 -> V_44 = V_44 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_2 = V_2 ;
return V_7 ;
}
