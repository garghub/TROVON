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
int V_13 , V_14 ;
unsigned long V_15 = 0 , V_16 = 0 ;
unsigned int V_17 = V_18 ;
int V_19 = - 1 ;
struct V_20 * V_21 =
F_11 ( V_6 ) ;
if ( ! V_10 )
return - V_22 ;
if ( ! V_21 )
return - V_22 ;
for ( V_13 = 0 ; V_21 [ V_13 ] . V_23 != V_24 ; V_13 ++ ) {
if ( V_21 [ V_13 ] . V_23 == V_18 )
continue;
if ( V_17 == V_21 [ V_13 ] . V_23 )
continue;
if ( V_17 != V_18 && V_19 == - 1 )
V_19 = ! ! ( V_17 > V_21 [ V_13 ] . V_23 ) ;
V_17 = V_21 [ V_13 ] . V_23 ;
V_15 ++ ;
}
if ( V_12 == V_25 ) {
* V_10 = ( unsigned int ) V_15 ;
return 0 ;
}
if ( V_12 == V_26 )
V_16 = V_19 ? V_9 : ( V_15 - V_9 - 1 ) ;
for ( V_13 = 0 , V_14 = 0 ; V_21 [ V_13 ] . V_23 != V_24 ; V_13 ++ ) {
if ( V_21 [ V_13 ] . V_23 == V_18 )
continue;
if ( V_17 == V_21 [ V_13 ] . V_23 )
continue;
V_17 = V_21 [ V_13 ] . V_23 ;
if ( V_12 == V_27 && ( unsigned int ) V_9 == V_17 ) {
* V_10 = V_19 ? V_14 : ( V_15 - V_14 - 1 ) ;
return 0 ;
}
if ( V_12 == V_26 && V_16 == V_14 ) {
* V_10 = V_17 ;
return 0 ;
}
V_14 ++ ;
}
return - V_22 ;
}
unsigned long F_12 ( unsigned int V_6 , unsigned int V_17 )
{
unsigned int V_28 ;
if ( F_10 ( V_6 , ( unsigned long ) V_17 , & V_28 , V_27 ) )
return V_29 ;
return ( unsigned long ) V_28 ;
}
static unsigned int F_13 ( unsigned int V_6 , unsigned long V_16 )
{
int V_3 = 0 ;
unsigned int V_17 ;
V_3 = F_10 ( V_6 , V_16 , & V_17 , V_26 ) ;
if ( V_3 )
return 0 ;
return V_17 ;
}
static int F_14 ( struct V_30 * V_31 ,
unsigned long V_32 )
{
unsigned int V_33 , V_34 ;
struct V_35 * V_36 = & V_31 -> V_37 ;
unsigned int V_6 = F_15 ( V_36 ) ;
if ( V_31 -> V_38 == V_32 )
return 0 ;
V_34 = F_13 ( V_6 , V_32 ) ;
if ( ! V_34 )
return - V_22 ;
V_31 -> V_38 = V_32 ;
V_31 -> V_39 = V_34 ;
V_40 = V_31 ;
F_16 (cpuid, mask) {
if ( F_8 ( V_33 ) )
F_17 ( V_33 ) ;
}
V_40 = V_41 ;
return 0 ;
}
static int F_18 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_7 * V_8 = V_45 ;
unsigned long V_46 = 0 ;
if ( V_44 != V_47 || V_40 == V_41 )
return 0 ;
if ( F_19 ( V_8 -> V_6 , & V_40 -> V_37 ) )
V_46 = V_40 -> V_39 ;
else
return 0 ;
if ( V_46 > V_8 -> V_48 . V_49 )
V_46 = V_8 -> V_48 . V_49 ;
if ( V_8 -> V_49 != V_46 )
F_20 ( V_8 , 0 , V_46 ) ;
return 0 ;
}
static int F_21 ( struct V_50 * V_51 ,
unsigned long * V_52 )
{
struct V_30 * V_31 = V_51 -> V_53 ;
struct V_35 * V_36 = & V_31 -> V_37 ;
unsigned int V_6 ;
unsigned int V_54 = 0 ;
int V_3 ;
V_6 = F_15 ( V_36 ) ;
V_3 = F_10 ( V_6 , 0 , & V_54 , V_25 ) ;
if ( V_54 > 0 )
* V_52 = V_54 ;
return V_3 ;
}
static int F_22 ( struct V_50 * V_51 ,
unsigned long * V_52 )
{
struct V_30 * V_31 = V_51 -> V_53 ;
* V_52 = V_31 -> V_38 ;
return 0 ;
}
static int F_23 ( struct V_50 * V_51 ,
unsigned long V_52 )
{
struct V_30 * V_31 = V_51 -> V_53 ;
return F_14 ( V_31 , V_52 ) ;
}
struct V_50 *
F_24 ( const struct V_35 * V_55 )
{
struct V_50 * V_56 ;
struct V_30 * V_57 = NULL ;
unsigned int V_58 = 0 , V_49 = 0 ;
char V_59 [ V_60 ] ;
int V_3 = 0 , V_13 ;
struct V_7 V_8 ;
F_16 (i, clip_cpus) {
if ( ! F_9 ( & V_8 , V_13 ) )
continue;
if ( V_58 == 0 && V_49 == 0 ) {
V_58 = V_8 . V_61 . V_62 ;
V_49 = V_8 . V_61 . V_46 ;
} else {
if ( V_58 != V_8 . V_61 . V_62 ||
V_49 != V_8 . V_61 . V_46 )
return F_25 ( - V_22 ) ;
}
}
V_57 = F_26 ( sizeof( struct V_30 ) ,
V_5 ) ;
if ( ! V_57 )
return F_25 ( - V_63 ) ;
F_27 ( & V_57 -> V_37 , V_55 ) ;
V_3 = F_1 ( & V_64 , & V_57 -> V_2 ) ;
if ( V_3 ) {
F_28 ( V_57 ) ;
return F_25 ( - V_22 ) ;
}
snprintf ( V_59 , sizeof( V_59 ) , L_1 ,
V_57 -> V_2 ) ;
V_56 = F_29 ( V_59 , V_57 ,
& V_65 ) ;
if ( ! V_56 ) {
F_6 ( & V_64 , V_57 -> V_2 ) ;
F_28 ( V_57 ) ;
return F_25 ( - V_22 ) ;
}
V_57 -> V_56 = V_56 ;
V_57 -> V_38 = 0 ;
F_2 ( & V_4 ) ;
if ( V_66 == 0 )
F_30 ( & V_67 ,
V_68 ) ;
V_66 ++ ;
F_4 ( & V_4 ) ;
return V_56 ;
}
void F_31 ( struct V_50 * V_51 )
{
struct V_30 * V_57 ;
if ( ! V_51 )
return;
V_57 = V_51 -> V_53 ;
F_2 ( & V_4 ) ;
V_66 -- ;
if ( V_66 == 0 )
F_32 ( & V_67 ,
V_68 ) ;
F_4 ( & V_4 ) ;
F_33 ( V_57 -> V_56 ) ;
F_6 ( & V_64 , V_57 -> V_2 ) ;
F_28 ( V_57 ) ;
}
