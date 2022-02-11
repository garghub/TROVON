static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( V_1 , NULL , 0 , 0 , V_5 ) ;
F_4 ( & V_4 ) ;
if ( F_5 ( V_3 < 0 ) )
return V_3 ;
* V_2 = V_3 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( & V_4 ) ;
F_7 ( V_1 , V_2 ) ;
F_4 ( & V_4 ) ;
}
static int F_8 ( int V_6 )
{
struct V_7 V_8 ;
return ! F_9 ( & V_8 , V_6 ) ;
}
static int F_10 ( unsigned int V_6 , unsigned long V_9 ,
unsigned int * V_10 ,
enum V_11 V_12 )
{
int V_13 ;
unsigned long V_14 = 0 , V_15 = 0 ;
unsigned int V_16 = V_17 ;
int V_18 = - 1 ;
struct V_19 * V_20 , * V_21 =
F_11 ( V_6 ) ;
if ( ! V_10 )
return - V_22 ;
if ( ! V_21 )
return - V_22 ;
F_12 (pos, table) {
if ( V_16 == V_20 -> V_23 )
continue;
if ( V_16 != V_17 && V_18 == - 1 )
V_18 = V_16 > V_20 -> V_23 ;
V_16 = V_20 -> V_23 ;
V_14 ++ ;
}
if ( V_14 == 0 )
return - V_22 ;
V_14 -- ;
if ( V_12 == V_24 ) {
* V_10 = ( unsigned int ) V_14 ;
return 0 ;
}
if ( V_12 == V_25 )
V_15 = V_18 ? V_9 : ( V_14 - V_9 ) ;
V_13 = 0 ;
F_12 (pos, table) {
if ( V_16 == V_20 -> V_23 )
continue;
V_16 = V_20 -> V_23 ;
if ( V_12 == V_26 && ( unsigned int ) V_9 == V_16 ) {
* V_10 = V_18 ? V_13 : ( V_14 - V_13 ) ;
return 0 ;
}
if ( V_12 == V_25 && V_15 == V_13 ) {
* V_10 = V_16 ;
return 0 ;
}
V_13 ++ ;
}
return - V_22 ;
}
unsigned long F_13 ( unsigned int V_6 , unsigned int V_16 )
{
unsigned int V_27 ;
if ( F_10 ( V_6 , ( unsigned long ) V_16 , & V_27 , V_26 ) )
return V_28 ;
return ( unsigned long ) V_27 ;
}
static unsigned int F_14 ( unsigned int V_6 , unsigned long V_15 )
{
int V_3 = 0 ;
unsigned int V_16 ;
V_3 = F_10 ( V_6 , V_15 , & V_16 , V_25 ) ;
if ( V_3 )
return 0 ;
return V_16 ;
}
static int F_15 ( struct V_29 * V_30 ,
unsigned long V_31 )
{
unsigned int V_32 , V_33 ;
struct V_34 * V_35 = & V_30 -> V_36 ;
unsigned int V_6 = F_16 ( V_35 ) ;
if ( V_30 -> V_37 == V_31 )
return 0 ;
V_33 = F_14 ( V_6 , V_31 ) ;
if ( ! V_33 )
return - V_22 ;
V_30 -> V_37 = V_31 ;
V_30 -> V_38 = V_33 ;
F_17 (cpuid, mask) {
if ( F_8 ( V_32 ) )
F_18 ( V_32 ) ;
}
return 0 ;
}
static int F_19 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_42 )
{
struct V_7 * V_8 = V_42 ;
unsigned long V_43 = 0 ;
struct V_29 * V_44 ;
if ( V_41 != V_45 )
return 0 ;
F_2 ( & V_4 ) ;
F_20 (cpufreq_dev, &cpufreq_dev_list, node) {
if ( ! F_21 ( V_8 -> V_6 ,
& V_44 -> V_36 ) )
continue;
if ( ! V_44 -> V_38 )
V_44 -> V_38 = F_14 (
F_16 ( & V_44 -> V_36 ) ,
V_44 -> V_37 ) ;
V_43 = V_44 -> V_38 ;
if ( V_8 -> V_46 != V_43 )
F_22 ( V_8 , 0 , V_43 ) ;
}
F_4 ( & V_4 ) ;
return 0 ;
}
static int F_23 ( struct V_47 * V_48 ,
unsigned long * V_49 )
{
struct V_29 * V_30 = V_48 -> V_50 ;
struct V_34 * V_35 = & V_30 -> V_36 ;
unsigned int V_6 ;
unsigned int V_51 = 0 ;
int V_3 ;
V_6 = F_16 ( V_35 ) ;
V_3 = F_10 ( V_6 , 0 , & V_51 , V_24 ) ;
if ( V_51 > 0 )
* V_49 = V_51 ;
return V_3 ;
}
static int F_24 ( struct V_47 * V_48 ,
unsigned long * V_49 )
{
struct V_29 * V_30 = V_48 -> V_50 ;
* V_49 = V_30 -> V_37 ;
return 0 ;
}
static int F_25 ( struct V_47 * V_48 ,
unsigned long V_49 )
{
struct V_29 * V_30 = V_48 -> V_50 ;
return F_15 ( V_30 , V_49 ) ;
}
static struct V_47 *
F_26 ( struct V_52 * V_53 ,
const struct V_34 * V_54 )
{
struct V_47 * V_55 ;
struct V_29 * V_44 = NULL ;
unsigned int V_56 = 0 , V_46 = 0 ;
char V_57 [ V_58 ] ;
int V_3 = 0 , V_13 ;
struct V_7 V_8 ;
F_17 (i, clip_cpus) {
if ( ! F_9 ( & V_8 , V_13 ) )
continue;
if ( V_56 == 0 && V_46 == 0 ) {
V_56 = V_8 . V_59 . V_60 ;
V_46 = V_8 . V_59 . V_43 ;
} else {
if ( V_56 != V_8 . V_59 . V_60 ||
V_46 != V_8 . V_59 . V_43 )
return F_27 ( - V_22 ) ;
}
}
V_44 = F_28 ( sizeof( struct V_29 ) ,
V_5 ) ;
if ( ! V_44 )
return F_27 ( - V_61 ) ;
F_29 ( & V_44 -> V_36 , V_54 ) ;
V_3 = F_1 ( & V_62 , & V_44 -> V_2 ) ;
if ( V_3 ) {
F_30 ( V_44 ) ;
return F_27 ( - V_22 ) ;
}
snprintf ( V_57 , sizeof( V_57 ) , L_1 ,
V_44 -> V_2 ) ;
V_55 = F_31 ( V_53 , V_57 , V_44 ,
& V_63 ) ;
if ( F_32 ( V_55 ) ) {
F_6 ( & V_62 , V_44 -> V_2 ) ;
F_30 ( V_44 ) ;
return V_55 ;
}
V_44 -> V_55 = V_55 ;
V_44 -> V_37 = 0 ;
F_2 ( & V_4 ) ;
if ( V_64 == 0 )
F_33 ( & V_65 ,
V_66 ) ;
V_64 ++ ;
F_34 ( & V_44 -> V_67 , & V_68 ) ;
F_4 ( & V_4 ) ;
return V_55 ;
}
struct V_47 *
F_35 ( const struct V_34 * V_54 )
{
return F_26 ( NULL , V_54 ) ;
}
struct V_47 *
F_36 ( struct V_52 * V_53 ,
const struct V_34 * V_54 )
{
if ( ! V_53 )
return F_27 ( - V_22 ) ;
return F_26 ( V_53 , V_54 ) ;
}
void F_37 ( struct V_47 * V_48 )
{
struct V_29 * V_44 ;
if ( ! V_48 )
return;
V_44 = V_48 -> V_50 ;
F_2 ( & V_4 ) ;
F_38 ( & V_44 -> V_67 ) ;
V_64 -- ;
if ( V_64 == 0 )
F_39 ( & V_65 ,
V_66 ) ;
F_4 ( & V_4 ) ;
F_40 ( V_44 -> V_55 ) ;
F_6 ( & V_62 , V_44 -> V_2 ) ;
F_30 ( V_44 ) ;
}
