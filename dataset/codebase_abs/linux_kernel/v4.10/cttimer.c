static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_9 = V_3 -> V_9 ;
unsigned int V_10 = V_7 -> V_10 ;
unsigned int V_11 = V_7 -> V_11 ;
unsigned long V_12 ;
unsigned int V_13 , V_14 , V_15 ;
V_13 = V_5 -> V_16 -> V_17 ( V_5 ) ;
V_14 = ( V_13 + V_11 - V_3 -> V_13 ) % V_11 ;
if ( V_14 >= V_10 ||
V_13 / V_10 != V_3 -> V_13 / V_10 ) {
V_9 -> V_18 ( V_9 ) ;
V_3 -> V_13 = V_13 ;
}
V_15 = ( ( V_10 - ( V_13 % V_10 ) )
* V_19 + ( V_7 -> V_20 - 1 ) ) / V_7 -> V_20 + V_19 * 5 / 1000 ;
F_2 ( & V_3 -> V_21 , V_12 ) ;
if ( V_3 -> V_22 )
F_3 ( & V_3 -> V_23 , V_24 + V_15 ) ;
F_4 ( & V_3 -> V_21 , V_12 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
F_6 ( & V_3 -> V_23 , F_1 ,
( unsigned long ) V_3 ) ;
}
static void F_7 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_5 -> V_7 ;
unsigned long V_12 ;
F_2 ( & V_3 -> V_21 , V_12 ) ;
V_3 -> V_22 = 1 ;
F_3 ( & V_3 -> V_23 ,
V_24 + ( V_7 -> V_10 * V_19 +
( V_7 -> V_20 - 1 ) ) / V_7 -> V_20 ) ;
F_4 ( & V_3 -> V_21 , V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
unsigned long V_12 ;
F_2 ( & V_3 -> V_21 , V_12 ) ;
V_3 -> V_22 = 0 ;
F_9 ( & V_3 -> V_23 ) ;
F_4 ( & V_3 -> V_21 , V_12 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_8 ( V_3 ) ;
F_11 ( & V_3 -> V_23 ) ;
}
static void F_12 ( struct V_25 * V_26 , int V_27 )
{
struct V_28 * V_28 = V_26 -> V_29 -> V_28 ;
if ( V_27 > V_30 )
V_27 = V_30 ;
V_28 -> V_31 ( V_28 , V_27 ) ;
if ( ! V_26 -> V_22 )
V_28 -> V_32 ( V_28 , 1 ) ;
V_26 -> V_22 = 1 ;
}
static void F_13 ( struct V_25 * V_26 )
{
if ( V_26 -> V_22 ) {
struct V_28 * V_28 = V_26 -> V_29 -> V_28 ;
V_28 -> V_32 ( V_28 , 0 ) ;
V_28 -> V_31 ( V_28 , 0 ) ;
V_26 -> V_22 = 0 ;
}
}
static inline unsigned int F_14 ( struct V_25 * V_26 )
{
struct V_28 * V_28 = V_26 -> V_29 -> V_28 ;
return V_28 -> V_33 ( V_28 ) ;
}
static int F_15 ( struct V_25 * V_26 , int V_34 )
{
struct V_2 * V_3 ;
unsigned int V_35 = ( unsigned int ) - 1 ;
int V_36 = 0 ;
unsigned int V_37 , V_38 ;
if ( F_16 ( & V_26 -> V_39 ) ) {
F_13 ( V_26 ) ;
V_26 -> V_40 = 0 ;
return 0 ;
}
V_37 = F_14 ( V_26 ) ;
V_38 = V_37 - V_26 -> V_37 ;
V_26 -> V_37 = V_37 ;
F_17 (ti, &atimer->running_head, running_list) {
if ( V_3 -> V_41 > V_38 )
V_3 -> V_41 -= V_38 ;
else {
unsigned int V_42 ;
unsigned int V_10 , V_20 ;
V_10 = V_3 -> V_5 -> V_7 -> V_10 ;
V_20 = V_3 -> V_5 -> V_7 -> V_20 ;
V_42 = V_3 -> V_5 -> V_16 -> V_17 ( V_3 -> V_5 ) ;
if ( V_42 / V_10 != V_3 -> V_13 / V_10 ) {
V_3 -> V_43 = 1 ;
V_3 -> V_13 = V_42 ;
V_36 ++ ;
}
V_42 %= V_10 ;
V_42 = V_10 - V_42 ;
V_3 -> V_41 = F_18 ( ( V_44 ) V_42 * V_45 +
V_20 - 1 , V_20 ) ;
}
if ( V_3 -> V_43 && ! V_34 )
V_35 = 0 ;
if ( V_3 -> V_41 < V_35 )
V_35 = V_3 -> V_41 ;
}
if ( V_35 < V_46 )
V_35 = V_46 ;
F_12 ( V_26 , V_35 ) ;
V_26 -> V_40 = 0 ;
return V_36 ;
}
static void F_19 ( struct V_25 * V_26 )
{
struct V_2 * V_3 ;
unsigned long V_12 ;
F_2 ( & V_26 -> V_47 , V_12 ) ;
F_17 (ti, &atimer->instance_head, instance_list) {
if ( V_3 -> V_22 && V_3 -> V_43 ) {
V_3 -> V_43 = 0 ;
V_3 -> V_9 -> V_18 ( V_3 -> V_9 ) ;
}
}
F_4 ( & V_26 -> V_47 , V_12 ) ;
}
static void F_20 ( struct V_25 * V_26 )
{
int V_48 ;
unsigned long V_12 ;
F_2 ( & V_26 -> V_21 , V_12 ) ;
V_26 -> V_49 = 1 ;
do {
V_48 = F_15 ( V_26 , 1 ) ;
F_21 ( & V_26 -> V_21 ) ;
if ( V_48 )
F_19 ( V_26 ) ;
F_22 ( & V_26 -> V_21 ) ;
} while ( V_26 -> V_40 );
V_26 -> V_49 = 0 ;
F_4 ( & V_26 -> V_21 , V_12 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
V_3 -> V_41 = V_3 -> V_5 -> V_7 -> V_10 ;
V_3 -> V_22 = 0 ;
V_3 -> V_43 = 0 ;
}
static void F_24 ( struct V_25 * V_26 )
{
unsigned long V_12 ;
F_2 ( & V_26 -> V_21 , V_12 ) ;
if ( V_26 -> V_49 ) {
V_26 -> V_40 = 1 ;
F_4 ( & V_26 -> V_21 , V_12 ) ;
return;
}
F_13 ( V_26 ) ;
F_15 ( V_26 , 0 ) ;
F_4 ( & V_26 -> V_21 , V_12 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_50 ;
unsigned long V_12 ;
F_2 ( & V_26 -> V_21 , V_12 ) ;
if ( F_16 ( & V_3 -> V_51 ) )
V_26 -> V_37 = F_14 ( V_26 ) ;
V_3 -> V_22 = 1 ;
V_3 -> V_43 = 0 ;
F_26 ( & V_3 -> V_51 , & V_26 -> V_39 ) ;
F_4 ( & V_26 -> V_21 , V_12 ) ;
F_24 ( V_26 ) ;
}
static void F_27 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_50 ;
unsigned long V_12 ;
F_2 ( & V_26 -> V_21 , V_12 ) ;
F_28 ( & V_3 -> V_51 ) ;
V_3 -> V_22 = 0 ;
F_4 ( & V_26 -> V_21 , V_12 ) ;
F_24 ( V_26 ) ;
}
static void F_29 ( struct V_25 * V_26 )
{
F_13 ( V_26 ) ;
}
struct V_2 *
F_30 ( struct V_25 * V_26 , struct V_8 * V_9 )
{
struct V_2 * V_3 ;
V_3 = F_31 ( sizeof( * V_3 ) , V_52 ) ;
if ( ! V_3 )
return NULL ;
F_32 ( & V_3 -> V_21 ) ;
F_33 ( & V_3 -> V_53 ) ;
F_33 ( & V_3 -> V_51 ) ;
V_3 -> V_50 = V_26 ;
V_3 -> V_9 = V_9 ;
V_3 -> V_5 = V_9 -> V_5 ;
if ( V_26 -> V_16 -> V_54 )
V_26 -> V_16 -> V_54 ( V_3 ) ;
F_34 ( & V_26 -> V_47 ) ;
F_26 ( & V_3 -> V_53 , & V_26 -> V_55 ) ;
F_35 ( & V_26 -> V_47 ) ;
return V_3 ;
}
void F_36 ( struct V_2 * V_3 )
{
if ( V_3 -> V_50 -> V_16 -> V_56 )
V_3 -> V_50 -> V_16 -> V_56 ( V_3 ) ;
V_3 -> V_13 = 0 ;
V_3 -> V_22 = 0 ;
}
void F_37 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_50 ;
V_26 -> V_16 -> V_57 ( V_3 ) ;
}
void F_38 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_50 ;
V_26 -> V_16 -> V_58 ( V_3 ) ;
}
void F_39 ( struct V_2 * V_3 )
{
struct V_25 * V_26 = V_3 -> V_50 ;
V_26 -> V_16 -> V_58 ( V_3 ) ;
if ( V_26 -> V_16 -> V_59 )
V_26 -> V_16 -> V_59 ( V_3 ) ;
F_34 ( & V_26 -> V_47 ) ;
F_40 ( & V_3 -> V_53 ) ;
F_35 ( & V_26 -> V_47 ) ;
F_41 ( V_3 ) ;
}
static void F_42 ( void * V_1 , unsigned int V_60 )
{
struct V_25 * V_23 = V_1 ;
if ( ( V_60 & V_61 ) && V_23 -> V_16 -> V_18 )
V_23 -> V_16 -> V_18 ( V_23 ) ;
}
struct V_25 * F_43 ( struct V_62 * V_29 )
{
struct V_25 * V_26 ;
struct V_28 * V_28 ;
V_26 = F_31 ( sizeof( * V_26 ) , V_52 ) ;
if ( ! V_26 )
return NULL ;
F_32 ( & V_26 -> V_21 ) ;
F_32 ( & V_26 -> V_47 ) ;
F_33 ( & V_26 -> V_55 ) ;
F_33 ( & V_26 -> V_39 ) ;
V_26 -> V_29 = V_29 ;
V_28 = V_29 -> V_28 ;
if ( ! V_63 && V_28 -> V_32 ) {
F_44 ( V_29 -> V_64 -> V_65 , L_1 ) ;
V_26 -> V_16 = & V_66 ;
V_28 -> V_67 = V_26 ;
V_28 -> V_68 = F_42 ;
} else {
F_44 ( V_29 -> V_64 -> V_65 , L_2 ) ;
V_26 -> V_16 = & V_69 ;
}
return V_26 ;
}
void F_45 ( struct V_25 * V_26 )
{
struct V_28 * V_28 = V_26 -> V_29 -> V_28 ;
V_28 -> V_68 = NULL ;
if ( V_26 -> V_16 -> V_70 )
V_26 -> V_16 -> V_70 ( V_26 ) ;
F_41 ( V_26 ) ;
}
