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
V_39 = V_30 ;
F_17 (cpuid, mask) {
if ( F_8 ( V_32 ) )
F_18 ( V_32 ) ;
}
V_39 = V_40 ;
return 0 ;
}
static int F_19 ( struct V_41 * V_42 ,
unsigned long V_43 , void * V_44 )
{
struct V_7 * V_8 = V_44 ;
unsigned long V_45 = 0 ;
if ( V_43 != V_46 || V_39 == V_40 )
return 0 ;
if ( F_20 ( V_8 -> V_6 , & V_39 -> V_36 ) )
V_45 = V_39 -> V_38 ;
else
return 0 ;
if ( V_45 > V_8 -> V_47 . V_48 )
V_45 = V_8 -> V_47 . V_48 ;
if ( V_8 -> V_48 != V_45 )
F_21 ( V_8 , 0 , V_45 ) ;
return 0 ;
}
static int F_22 ( struct V_49 * V_50 ,
unsigned long * V_51 )
{
struct V_29 * V_30 = V_50 -> V_52 ;
struct V_34 * V_35 = & V_30 -> V_36 ;
unsigned int V_6 ;
unsigned int V_53 = 0 ;
int V_3 ;
V_6 = F_16 ( V_35 ) ;
V_3 = F_10 ( V_6 , 0 , & V_53 , V_24 ) ;
if ( V_53 > 0 )
* V_51 = V_53 ;
return V_3 ;
}
static int F_23 ( struct V_49 * V_50 ,
unsigned long * V_51 )
{
struct V_29 * V_30 = V_50 -> V_52 ;
* V_51 = V_30 -> V_37 ;
return 0 ;
}
static int F_24 ( struct V_49 * V_50 ,
unsigned long V_51 )
{
struct V_29 * V_30 = V_50 -> V_52 ;
return F_15 ( V_30 , V_51 ) ;
}
static struct V_49 *
F_25 ( struct V_54 * V_55 ,
const struct V_34 * V_56 )
{
struct V_49 * V_57 ;
struct V_29 * V_58 = NULL ;
unsigned int V_59 = 0 , V_48 = 0 ;
char V_60 [ V_61 ] ;
int V_3 = 0 , V_13 ;
struct V_7 V_8 ;
F_17 (i, clip_cpus) {
if ( ! F_9 ( & V_8 , V_13 ) )
continue;
if ( V_59 == 0 && V_48 == 0 ) {
V_59 = V_8 . V_62 . V_63 ;
V_48 = V_8 . V_62 . V_45 ;
} else {
if ( V_59 != V_8 . V_62 . V_63 ||
V_48 != V_8 . V_62 . V_45 )
return F_26 ( - V_22 ) ;
}
}
V_58 = F_27 ( sizeof( struct V_29 ) ,
V_5 ) ;
if ( ! V_58 )
return F_26 ( - V_64 ) ;
F_28 ( & V_58 -> V_36 , V_56 ) ;
V_3 = F_1 ( & V_65 , & V_58 -> V_2 ) ;
if ( V_3 ) {
F_29 ( V_58 ) ;
return F_26 ( - V_22 ) ;
}
snprintf ( V_60 , sizeof( V_60 ) , L_1 ,
V_58 -> V_2 ) ;
V_57 = F_30 ( V_55 , V_60 , V_58 ,
& V_66 ) ;
if ( F_31 ( V_57 ) ) {
F_6 ( & V_65 , V_58 -> V_2 ) ;
F_29 ( V_58 ) ;
return V_57 ;
}
V_58 -> V_57 = V_57 ;
V_58 -> V_37 = 0 ;
F_2 ( & V_4 ) ;
if ( V_67 == 0 )
F_32 ( & V_68 ,
V_69 ) ;
V_67 ++ ;
F_4 ( & V_4 ) ;
return V_57 ;
}
struct V_49 *
F_33 ( const struct V_34 * V_56 )
{
return F_25 ( NULL , V_56 ) ;
}
struct V_49 *
F_34 ( struct V_54 * V_55 ,
const struct V_34 * V_56 )
{
if ( ! V_55 )
return F_26 ( - V_22 ) ;
return F_25 ( V_55 , V_56 ) ;
}
void F_35 ( struct V_49 * V_50 )
{
struct V_29 * V_58 ;
if ( ! V_50 )
return;
V_58 = V_50 -> V_52 ;
F_2 ( & V_4 ) ;
V_67 -- ;
if ( V_67 == 0 )
F_36 ( & V_68 ,
V_69 ) ;
F_4 ( & V_4 ) ;
F_37 ( V_58 -> V_57 ) ;
F_6 ( & V_65 , V_58 -> V_2 ) ;
F_29 ( V_58 ) ;
}
