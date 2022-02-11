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
V_7 -> V_9 = ( V_30 void * ) F_12 ( V_22 , V_2 ) ;
if ( ! V_7 -> V_9 )
goto V_29;
} else {
V_16 = V_9 >> V_31 ;
V_17 = ( V_9 + V_2 - 1 ) >> V_31 ;
V_7 -> V_18 = V_17 - V_16 + 1 ;
V_7 -> V_32 = F_2 ( V_7 -> V_18 * sizeof( struct V_33 * ) ,
V_8 ) ;
if ( ! V_7 -> V_32 )
goto V_29;
V_18 = F_13 ( V_24 , V_24 -> V_25 ,
V_9 & V_23 , V_7 -> V_18 ,
V_4 == V_34 ,
1 ,
V_7 -> V_32 , NULL ) ;
if ( V_18 != V_7 -> V_18 )
goto V_35;
V_7 -> V_9 = F_14 ( V_7 -> V_32 , V_7 -> V_18 , - 1 ,
V_36 ) ;
if ( ! V_7 -> V_9 )
goto V_35;
}
V_7 -> V_9 += V_19 ;
return V_7 ;
V_35:
F_4 ( L_2 , V_18 ,
V_7 -> V_18 ) ;
while ( -- V_18 >= 0 )
F_15 ( V_7 -> V_32 [ V_18 ] ) ;
F_5 ( V_7 -> V_32 ) ;
V_29:
F_5 ( V_7 ) ;
return NULL ;
}
static void F_16 ( void * V_15 )
{
struct V_6 * V_7 = V_15 ;
unsigned long V_9 = ( unsigned long ) V_7 -> V_9 & V_23 ;
unsigned int V_37 ;
if ( V_7 -> V_32 ) {
if ( V_9 )
F_17 ( ( void * ) V_9 , V_7 -> V_18 ) ;
for ( V_37 = 0 ; V_37 < V_7 -> V_18 ; ++ V_37 ) {
if ( V_7 -> V_4 == V_34 )
F_18 ( V_7 -> V_32 [ V_37 ] ) ;
F_15 ( V_7 -> V_32 [ V_37 ] ) ;
}
F_5 ( V_7 -> V_32 ) ;
} else {
F_19 ( V_7 -> V_21 ) ;
F_20 ( ( V_30 void V_38 * ) V_7 -> V_9 ) ;
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
int V_39 ;
if ( ! V_7 ) {
F_22 ( L_5 ) ;
return - V_40 ;
}
V_39 = F_26 ( V_21 , V_7 -> V_9 , 0 ) ;
if ( V_39 ) {
F_22 ( L_6 , V_39 ) ;
return V_39 ;
}
V_21 -> V_26 |= V_41 ;
V_21 -> V_42 = & V_7 -> V_10 ;
V_21 -> V_43 = & V_44 ;
V_21 -> V_43 -> V_45 ( V_21 ) ;
return 0 ;
}
static int F_27 ( struct V_46 * V_47 , struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_6 * V_7 = V_47 -> V_54 ;
int V_55 = F_28 ( V_7 -> V_2 ) / V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
void * V_9 = V_7 -> V_9 ;
int V_39 ;
int V_37 ;
V_53 = F_2 ( sizeof( * V_53 ) , V_8 ) ;
if ( ! V_53 )
return - V_61 ;
V_58 = & V_53 -> V_58 ;
V_39 = F_29 ( V_58 , V_55 , V_8 ) ;
if ( V_39 ) {
F_5 ( V_53 ) ;
return V_39 ;
}
F_30 (sgt->sgl, sg, sgt->nents, i) {
struct V_33 * V_33 = F_31 ( V_9 ) ;
if ( ! V_33 ) {
F_32 ( V_58 ) ;
F_5 ( V_53 ) ;
return - V_61 ;
}
F_33 ( V_60 , V_33 , V_56 , 0 ) ;
V_9 += V_56 ;
}
V_53 -> V_4 = V_62 ;
V_51 -> V_54 = V_53 ;
return 0 ;
}
static void F_34 ( struct V_46 * V_47 ,
struct V_50 * V_63 )
{
struct V_52 * V_53 = V_63 -> V_54 ;
struct V_57 * V_58 ;
if ( ! V_53 )
return;
V_58 = & V_53 -> V_58 ;
if ( V_53 -> V_4 != V_62 )
F_35 ( V_63 -> V_49 , V_58 -> V_64 , V_58 -> V_65 ,
V_53 -> V_4 ) ;
F_32 ( V_58 ) ;
F_5 ( V_53 ) ;
V_63 -> V_54 = NULL ;
}
static struct V_57 * F_36 (
struct V_50 * V_63 , enum V_3 V_4 )
{
struct V_52 * V_53 = V_63 -> V_54 ;
struct V_66 * V_67 = & V_63 -> V_68 -> V_67 ;
struct V_57 * V_58 ;
F_37 ( V_67 ) ;
V_58 = & V_53 -> V_58 ;
if ( V_53 -> V_4 == V_4 ) {
F_38 ( V_67 ) ;
return V_58 ;
}
if ( V_53 -> V_4 != V_62 ) {
F_35 ( V_63 -> V_49 , V_58 -> V_64 , V_58 -> V_65 ,
V_53 -> V_4 ) ;
V_53 -> V_4 = V_62 ;
}
V_58 -> V_69 = F_39 ( V_63 -> V_49 , V_58 -> V_64 , V_58 -> V_65 ,
V_4 ) ;
if ( ! V_58 -> V_69 ) {
F_22 ( L_7 ) ;
F_38 ( V_67 ) ;
return F_40 ( - V_70 ) ;
}
V_53 -> V_4 = V_4 ;
F_38 ( V_67 ) ;
return V_58 ;
}
static void F_41 ( struct V_50 * V_63 ,
struct V_57 * V_58 , enum V_3 V_4 )
{
}
static void F_42 ( struct V_46 * V_47 )
{
V_13 ( V_47 -> V_54 ) ;
}
static void * F_43 ( struct V_46 * V_47 , unsigned long V_71 )
{
struct V_6 * V_7 = V_47 -> V_54 ;
return V_7 -> V_9 + V_71 * V_56 ;
}
static void * F_44 ( struct V_46 * V_47 )
{
struct V_6 * V_7 = V_47 -> V_54 ;
return V_7 -> V_9 ;
}
static int F_45 ( struct V_46 * V_47 ,
struct V_20 * V_21 )
{
return F_25 ( V_47 -> V_54 , V_21 ) ;
}
static struct V_46 * F_46 ( void * V_15 , unsigned long V_72 )
{
struct V_6 * V_7 = V_15 ;
struct V_46 * V_47 ;
F_47 ( V_73 ) ;
V_73 . V_74 = & V_75 ;
V_73 . V_2 = V_7 -> V_2 ;
V_73 . V_72 = V_72 ;
V_73 . V_54 = V_7 ;
if ( F_48 ( ! V_7 -> V_9 ) )
return NULL ;
V_47 = F_49 ( & V_73 ) ;
if ( F_50 ( V_47 ) )
return NULL ;
F_6 ( & V_7 -> V_11 ) ;
return V_47 ;
}
static int F_51 ( void * V_76 )
{
struct V_6 * V_7 = V_76 ;
V_7 -> V_9 = F_52 ( V_7 -> V_47 ) ;
return V_7 -> V_9 ? 0 : - V_77 ;
}
static void F_53 ( void * V_76 )
{
struct V_6 * V_7 = V_76 ;
F_54 ( V_7 -> V_47 , V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
static void F_55 ( void * V_76 )
{
struct V_6 * V_7 = V_76 ;
if ( V_7 -> V_9 )
F_54 ( V_7 -> V_47 , V_7 -> V_9 ) ;
F_5 ( V_7 ) ;
}
static void * F_56 ( void * V_1 , struct V_46 * V_47 ,
unsigned long V_2 , enum V_3 V_4 )
{
struct V_6 * V_7 ;
if ( V_47 -> V_2 < V_2 )
return F_40 ( - V_77 ) ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return F_40 ( - V_61 ) ;
V_7 -> V_47 = V_47 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_2 = V_2 ;
return V_7 ;
}
