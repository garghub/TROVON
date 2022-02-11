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
unsigned long V_16 , V_17 ;
int V_18 , V_19 ;
struct V_20 * V_21 ;
T_2 V_22 ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_4 = V_4 ;
V_19 = V_9 & ~ V_23 ;
V_7 -> V_2 = V_2 ;
V_21 = F_10 ( V_24 -> V_25 , V_9 ) ;
if ( V_21 && ( V_21 -> V_26 & V_27 ) && ( V_21 -> V_28 ) ) {
if ( F_11 ( V_9 , V_2 , & V_21 , & V_22 ) )
goto V_29;
V_7 -> V_21 = V_21 ;
V_7 -> V_9 = F_12 ( V_22 , V_2 ) ;
if ( ! V_7 -> V_9 )
goto V_29;
} else {
V_16 = V_9 >> V_30 ;
V_17 = ( V_9 + V_2 - 1 ) >> V_30 ;
V_7 -> V_18 = V_17 - V_16 + 1 ;
V_7 -> V_31 = F_2 ( V_7 -> V_18 * sizeof( struct V_32 * ) ,
V_8 ) ;
if ( ! V_7 -> V_31 )
goto V_29;
V_18 = F_13 ( V_24 , V_24 -> V_25 ,
V_9 & V_23 , V_7 -> V_18 ,
V_4 == V_33 ,
1 ,
V_7 -> V_31 , NULL ) ;
if ( V_18 != V_7 -> V_18 )
goto V_34;
V_7 -> V_9 = F_14 ( V_7 -> V_31 , V_7 -> V_18 , - 1 ,
V_35 ) ;
if ( ! V_7 -> V_9 )
goto V_34;
}
V_7 -> V_9 += V_19 ;
return V_7 ;
V_34:
F_4 ( L_2 , V_18 ,
V_7 -> V_18 ) ;
while ( -- V_18 >= 0 )
F_15 ( V_7 -> V_31 [ V_18 ] ) ;
F_5 ( V_7 -> V_31 ) ;
V_29:
F_5 ( V_7 ) ;
return NULL ;
}
static void F_16 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
unsigned long V_9 = ( unsigned long ) V_7 -> V_9 & V_23 ;
unsigned int V_36 ;
if ( V_7 -> V_31 ) {
if ( V_9 )
F_17 ( ( void * ) V_9 , V_7 -> V_18 ) ;
for ( V_36 = 0 ; V_36 < V_7 -> V_18 ; ++ V_36 ) {
if ( V_7 -> V_4 == V_33 )
F_18 ( V_7 -> V_31 [ V_36 ] ) ;
F_15 ( V_7 -> V_31 [ V_36 ] ) ;
}
F_5 ( V_7 -> V_31 ) ;
} else {
F_19 ( V_7 -> V_21 ) ;
F_20 ( V_7 -> V_9 ) ;
}
F_5 ( V_7 ) ;
}
static void * F_21 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
if ( ! V_7 -> V_9 ) {
F_22 ( L_3
L_4 ) ;
return NULL ;
}
return V_7 -> V_9 ;
}
static unsigned int F_23 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
return F_24 ( & V_7 -> V_11 ) ;
}
static int F_25 ( void * V_15 , struct V_20 * V_21 )
{
struct V_6 * V_7 = V_15 ;
int V_37 ;
if ( ! V_7 ) {
F_22 ( L_5 ) ;
return - V_38 ;
}
V_37 = F_26 ( V_21 , V_7 -> V_9 , 0 ) ;
if ( V_37 ) {
F_22 ( L_6 , V_37 ) ;
return V_37 ;
}
V_21 -> V_26 |= V_39 ;
V_21 -> V_40 = & V_7 -> V_10 ;
V_21 -> V_41 = & V_42 ;
V_21 -> V_41 -> V_43 ( V_21 ) ;
return 0 ;
}
static int F_27 ( struct V_44 * V_45 , struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_6 * V_7 = V_45 -> V_52 ;
int V_53 = F_28 ( V_7 -> V_2 ) / V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
void * V_9 = V_7 -> V_9 ;
int V_37 ;
int V_36 ;
V_51 = F_2 ( sizeof( * V_51 ) , V_8 ) ;
if ( ! V_51 )
return - V_59 ;
V_56 = & V_51 -> V_56 ;
V_37 = F_29 ( V_56 , V_53 , V_8 ) ;
if ( V_37 ) {
F_5 ( V_51 ) ;
return V_37 ;
}
F_30 (sgt->sgl, sg, sgt->nents, i) {
struct V_32 * V_32 = F_31 ( V_9 ) ;
if ( ! V_32 ) {
F_32 ( V_56 ) ;
F_5 ( V_51 ) ;
return - V_59 ;
}
F_33 ( V_58 , V_32 , V_54 , 0 ) ;
V_9 += V_54 ;
}
V_51 -> V_4 = V_60 ;
V_49 -> V_52 = V_51 ;
return 0 ;
}
static void F_34 ( struct V_44 * V_45 ,
struct V_48 * V_61 )
{
struct V_50 * V_51 = V_61 -> V_52 ;
struct V_55 * V_56 ;
if ( ! V_51 )
return;
V_56 = & V_51 -> V_56 ;
if ( V_51 -> V_4 != V_60 )
F_35 ( V_61 -> V_47 , V_56 -> V_62 , V_56 -> V_63 ,
V_51 -> V_4 ) ;
F_32 ( V_56 ) ;
F_5 ( V_51 ) ;
V_61 -> V_52 = NULL ;
}
static struct V_55 * F_36 (
struct V_48 * V_61 , enum V_3 V_4 )
{
struct V_50 * V_51 = V_61 -> V_52 ;
struct V_64 * V_65 = & V_61 -> V_66 -> V_65 ;
struct V_55 * V_56 ;
int V_37 ;
F_37 ( V_65 ) ;
V_56 = & V_51 -> V_56 ;
if ( V_51 -> V_4 == V_4 ) {
F_38 ( V_65 ) ;
return V_56 ;
}
if ( V_51 -> V_4 != V_60 ) {
F_35 ( V_61 -> V_47 , V_56 -> V_62 , V_56 -> V_63 ,
V_51 -> V_4 ) ;
V_51 -> V_4 = V_60 ;
}
V_37 = F_39 ( V_61 -> V_47 , V_56 -> V_62 , V_56 -> V_63 , V_4 ) ;
if ( V_37 <= 0 ) {
F_22 ( L_7 ) ;
F_38 ( V_65 ) ;
return F_40 ( - V_67 ) ;
}
V_51 -> V_4 = V_4 ;
F_38 ( V_65 ) ;
return V_56 ;
}
static void F_41 ( struct V_48 * V_61 ,
struct V_55 * V_56 , enum V_3 V_4 )
{
}
static void F_42 ( struct V_44 * V_45 )
{
V_13 ( V_45 -> V_52 ) ;
}
static void * F_43 ( struct V_44 * V_45 , unsigned long V_68 )
{
struct V_6 * V_7 = V_45 -> V_52 ;
return V_7 -> V_9 + V_68 * V_54 ;
}
static void * F_44 ( struct V_44 * V_45 )
{
struct V_6 * V_7 = V_45 -> V_52 ;
return V_7 -> V_9 ;
}
static int F_45 ( struct V_44 * V_45 ,
struct V_20 * V_21 )
{
return F_25 ( V_45 -> V_52 , V_21 ) ;
}
static struct V_44 * F_46 ( void * V_15 , unsigned long V_69 )
{
struct V_6 * V_7 = V_15 ;
struct V_44 * V_45 ;
if ( F_47 ( ! V_7 -> V_9 ) )
return NULL ;
V_45 = F_48 ( V_7 , & V_70 , V_7 -> V_2 , V_69 , NULL ) ;
if ( F_49 ( V_45 ) )
return NULL ;
F_6 ( & V_7 -> V_11 ) ;
return V_45 ;
}
static int F_50 ( void * V_71 )
{
struct V_6 * V_7 = V_71 ;
V_7 -> V_9 = F_51 ( V_7 -> V_45 ) ;
return V_7 -> V_9 ? 0 : - V_72 ;
}
static void F_52 ( void * V_71 )
{
struct V_6 * V_7 = V_71 ;
F_53 ( V_7 -> V_45 , V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
static void F_54 ( void * V_71 )
{
struct V_6 * V_7 = V_71 ;
if ( V_7 -> V_9 )
F_53 ( V_7 -> V_45 , V_7 -> V_9 ) ;
F_5 ( V_7 ) ;
}
static void * F_55 ( void * V_1 , struct V_44 * V_45 ,
unsigned long V_2 , enum V_3 V_4 )
{
struct V_6 * V_7 ;
if ( V_45 -> V_2 < V_2 )
return F_40 ( - V_72 ) ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_40 ( - V_59 ) ;
V_7 -> V_45 = V_45 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_2 = V_2 ;
return V_7 ;
}
