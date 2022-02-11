static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 ,
unsigned long V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_9 = F_2 ( V_2 ) ;
unsigned long V_10 = F_3 ( V_2 ) ;
unsigned long V_11 = V_9 ;
unsigned long V_12 = V_10 ;
F_4 ( V_3 -> V_13 ) ;
if ( V_8 -> V_14 )
V_8 -> V_14 ( V_2 , V_6 , & V_11 , & V_12 ) ;
if ( V_5 ) {
unsigned V_15 = V_11 % V_5 ;
if ( V_15 )
V_11 += V_5 - V_15 ;
}
if ( V_11 == V_9 ) {
V_2 -> V_16 = 0 ;
F_5 ( & V_2 -> V_17 ) ;
}
V_3 -> V_18 = V_11 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_8 = V_8 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_13 = 1 ;
F_6 ( & V_3 -> V_17 ) ;
F_7 ( & V_3 -> V_19 , & V_2 -> V_19 ) ;
F_4 ( V_3 -> V_18 + V_3 -> V_4 > V_12 ) ;
V_3 -> V_16 = 0 ;
if ( F_8 ( V_3 ) < V_10 ) {
F_7 ( & V_3 -> V_17 , & V_8 -> V_17 ) ;
V_3 -> V_16 = 1 ;
}
}
int F_9 ( struct V_7 * V_8 , struct V_1 * V_3 )
{
struct V_1 * V_20 ;
unsigned long V_21 = V_3 -> V_18 + V_3 -> V_4 ;
unsigned long V_9 ;
unsigned long V_10 ;
F_4 ( V_3 == NULL ) ;
F_10 (hole, mm, hole_start, hole_end) {
if ( V_9 > V_3 -> V_18 || V_10 < V_21 )
continue;
V_3 -> V_8 = V_8 ;
V_3 -> V_13 = 1 ;
F_6 ( & V_3 -> V_17 ) ;
F_7 ( & V_3 -> V_19 , & V_20 -> V_19 ) ;
if ( V_3 -> V_18 == V_9 ) {
V_20 -> V_16 = 0 ;
F_11 ( & V_20 -> V_17 ) ;
}
V_3 -> V_16 = 0 ;
if ( V_21 != V_10 ) {
F_7 ( & V_3 -> V_17 , & V_8 -> V_17 ) ;
V_3 -> V_16 = 1 ;
}
return 0 ;
}
F_12 ( 1 , L_1 ,
V_3 -> V_18 , V_3 -> V_4 ) ;
return - V_22 ;
}
int F_13 ( struct V_7 * V_8 , struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 ,
unsigned long V_6 ,
enum V_23 V_24 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_8 , V_4 , V_5 ,
V_6 , V_24 ) ;
if ( ! V_2 )
return - V_22 ;
F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 ,
unsigned long V_6 ,
unsigned long V_18 , unsigned long V_21 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_9 = F_2 ( V_2 ) ;
unsigned long V_10 = F_3 ( V_2 ) ;
unsigned long V_11 = V_9 ;
unsigned long V_12 = V_10 ;
F_4 ( ! V_2 -> V_16 || V_3 -> V_13 ) ;
if ( V_11 < V_18 )
V_11 = V_18 ;
if ( V_12 > V_21 )
V_12 = V_21 ;
if ( V_8 -> V_14 )
V_8 -> V_14 ( V_2 , V_6 , & V_11 , & V_12 ) ;
if ( V_5 ) {
unsigned V_15 = V_11 % V_5 ;
if ( V_15 )
V_11 += V_5 - V_15 ;
}
if ( V_11 == V_9 ) {
V_2 -> V_16 = 0 ;
F_5 ( & V_2 -> V_17 ) ;
}
V_3 -> V_18 = V_11 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_8 = V_8 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_13 = 1 ;
F_6 ( & V_3 -> V_17 ) ;
F_7 ( & V_3 -> V_19 , & V_2 -> V_19 ) ;
F_4 ( V_3 -> V_18 + V_3 -> V_4 > V_12 ) ;
F_4 ( V_3 -> V_18 + V_3 -> V_4 > V_21 ) ;
V_3 -> V_16 = 0 ;
if ( F_8 ( V_3 ) < V_10 ) {
F_7 ( & V_3 -> V_17 , & V_8 -> V_17 ) ;
V_3 -> V_16 = 1 ;
}
}
int F_16 ( struct V_7 * V_8 , struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 , unsigned long V_6 ,
unsigned long V_18 , unsigned long V_21 ,
enum V_23 V_24 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_8 ,
V_4 , V_5 , V_6 ,
V_18 , V_21 , V_24 ) ;
if ( ! V_2 )
return - V_22 ;
F_15 ( V_2 , V_3 ,
V_4 , V_5 , V_6 ,
V_18 , V_21 ) ;
return 0 ;
}
void F_18 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * V_25 ;
if ( F_19 ( ! V_3 -> V_13 ) )
return;
F_4 ( V_3 -> V_26 || V_3 -> V_27
|| V_3 -> V_28 ) ;
V_25 =
F_20 ( V_3 -> V_19 . V_29 , struct V_1 , V_19 ) ;
if ( V_3 -> V_16 ) {
F_4 ( F_8 ( V_3 ) ==
F_21 ( V_3 ) ) ;
F_5 ( & V_3 -> V_17 ) ;
} else
F_4 ( F_8 ( V_3 ) !=
F_21 ( V_3 ) ) ;
if ( ! V_25 -> V_16 ) {
V_25 -> V_16 = 1 ;
F_7 ( & V_25 -> V_17 , & V_8 -> V_17 ) ;
} else
F_22 ( & V_25 -> V_17 , & V_8 -> V_17 ) ;
F_5 ( & V_3 -> V_19 ) ;
V_3 -> V_13 = 0 ;
}
static int F_23 ( unsigned long V_18 , unsigned long V_21 ,
unsigned long V_4 , unsigned V_5 )
{
if ( V_21 - V_18 < V_4 )
return 0 ;
if ( V_5 ) {
unsigned V_15 = V_18 % V_5 ;
if ( V_15 )
V_18 += V_5 - V_15 ;
}
return V_21 >= V_18 + V_4 ;
}
static struct V_1 * F_14 ( const struct V_7 * V_8 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
enum V_23 V_24 )
{
struct V_1 * V_30 ;
struct V_1 * V_31 ;
unsigned long V_11 ;
unsigned long V_12 ;
unsigned long V_32 ;
F_4 ( V_8 -> V_33 ) ;
V_31 = NULL ;
V_32 = ~ 0UL ;
F_10 (entry, mm, adj_start, adj_end) {
if ( V_8 -> V_14 ) {
V_8 -> V_14 ( V_30 , V_6 , & V_11 , & V_12 ) ;
if ( V_12 <= V_11 )
continue;
}
if ( ! F_23 ( V_11 , V_12 , V_4 , V_5 ) )
continue;
if ( ! ( V_24 & V_34 ) )
return V_30 ;
if ( V_30 -> V_4 < V_32 ) {
V_31 = V_30 ;
V_32 = V_30 -> V_4 ;
}
}
return V_31 ;
}
static struct V_1 * F_17 ( const struct V_7 * V_8 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
unsigned long V_18 ,
unsigned long V_21 ,
enum V_23 V_24 )
{
struct V_1 * V_30 ;
struct V_1 * V_31 ;
unsigned long V_11 ;
unsigned long V_12 ;
unsigned long V_32 ;
F_4 ( V_8 -> V_33 ) ;
V_31 = NULL ;
V_32 = ~ 0UL ;
F_10 (entry, mm, adj_start, adj_end) {
if ( V_11 < V_18 )
V_11 = V_18 ;
if ( V_12 > V_21 )
V_12 = V_21 ;
if ( V_8 -> V_14 ) {
V_8 -> V_14 ( V_30 , V_6 , & V_11 , & V_12 ) ;
if ( V_12 <= V_11 )
continue;
}
if ( ! F_23 ( V_11 , V_12 , V_4 , V_5 ) )
continue;
if ( ! ( V_24 & V_34 ) )
return V_30 ;
if ( V_30 -> V_4 < V_32 ) {
V_31 = V_30 ;
V_32 = V_30 -> V_4 ;
}
}
return V_31 ;
}
void F_24 ( struct V_1 * V_35 , struct V_1 * V_36 )
{
F_25 ( & V_35 -> V_19 , & V_36 -> V_19 ) ;
F_25 ( & V_35 -> V_17 , & V_36 -> V_17 ) ;
V_36 -> V_16 = V_35 -> V_16 ;
V_36 -> V_8 = V_35 -> V_8 ;
V_36 -> V_18 = V_35 -> V_18 ;
V_36 -> V_4 = V_35 -> V_4 ;
V_36 -> V_6 = V_35 -> V_6 ;
V_35 -> V_13 = 0 ;
V_36 -> V_13 = 1 ;
}
void F_26 ( struct V_7 * V_8 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 )
{
V_8 -> V_37 = V_6 ;
V_8 -> V_38 = V_5 ;
V_8 -> V_39 = V_4 ;
V_8 -> V_33 = 0 ;
V_8 -> V_40 = 0 ;
V_8 -> V_41 = 0 ;
V_8 -> V_42 = 0 ;
V_8 -> V_43 = NULL ;
}
void F_27 ( struct V_7 * V_8 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
unsigned long V_18 ,
unsigned long V_21 )
{
V_8 -> V_37 = V_6 ;
V_8 -> V_38 = V_5 ;
V_8 -> V_39 = V_4 ;
V_8 -> V_33 = 0 ;
V_8 -> V_40 = 0 ;
V_8 -> V_41 = 0 ;
V_8 -> V_44 = V_18 ;
V_8 -> V_45 = V_21 ;
V_8 -> V_42 = 1 ;
V_8 -> V_43 = NULL ;
}
int F_28 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * V_25 ;
unsigned long V_9 , V_10 ;
unsigned long V_11 , V_12 ;
V_8 -> V_33 ++ ;
F_4 ( V_3 -> V_26 ) ;
V_3 -> V_26 = 1 ;
V_25 = F_20 ( V_3 -> V_19 . V_29 , struct V_1 ,
V_19 ) ;
V_3 -> V_46 = V_25 -> V_16 ;
V_25 -> V_16 = 1 ;
F_5 ( & V_3 -> V_19 ) ;
V_3 -> V_19 . V_29 = & V_25 -> V_19 ;
V_3 -> V_19 . V_47 = & V_8 -> V_43 -> V_19 ;
V_8 -> V_43 = V_3 ;
V_11 = V_9 = F_2 ( V_25 ) ;
V_12 = V_10 = F_3 ( V_25 ) ;
if ( V_8 -> V_42 ) {
if ( V_11 < V_8 -> V_44 )
V_11 = V_8 -> V_44 ;
if ( V_12 > V_8 -> V_45 )
V_12 = V_8 -> V_45 ;
}
if ( V_8 -> V_14 )
V_8 -> V_14 ( V_25 , V_8 -> V_37 ,
& V_11 , & V_12 ) ;
if ( F_23 ( V_11 , V_12 ,
V_8 -> V_39 , V_8 -> V_38 ) ) {
V_8 -> V_40 = V_9 ;
V_8 -> V_41 = V_10 ;
return 1 ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_3 )
{
struct V_7 * V_8 = V_3 -> V_8 ;
struct V_1 * V_25 ;
V_8 -> V_33 -- ;
F_4 ( ! V_3 -> V_26 ) ;
V_3 -> V_26 = 0 ;
V_25 = F_20 ( V_3 -> V_19 . V_29 , struct V_1 ,
V_19 ) ;
V_25 -> V_16 = V_3 -> V_46 ;
F_7 ( & V_3 -> V_19 , & V_25 -> V_19 ) ;
return ( F_3 ( V_3 ) > V_8 -> V_40 &&
V_3 -> V_18 < V_8 -> V_41 ) ;
}
int F_30 ( struct V_7 * V_8 )
{
struct V_48 * V_49 = & V_8 -> V_50 . V_19 ;
return ( V_49 -> V_47 -> V_47 == V_49 ) ;
}
void F_31 ( struct V_7 * V_8 , unsigned long V_18 , unsigned long V_4 )
{
F_6 ( & V_8 -> V_17 ) ;
V_8 -> V_33 = 0 ;
F_6 ( & V_8 -> V_50 . V_19 ) ;
F_6 ( & V_8 -> V_50 . V_17 ) ;
V_8 -> V_50 . V_16 = 1 ;
V_8 -> V_50 . V_26 = 0 ;
V_8 -> V_50 . V_27 = 0 ;
V_8 -> V_50 . V_28 = 0 ;
V_8 -> V_50 . V_8 = V_8 ;
V_8 -> V_50 . V_18 = V_18 + V_4 ;
V_8 -> V_50 . V_4 = V_18 - V_8 -> V_50 . V_18 ;
F_32 ( & V_8 -> V_50 . V_17 , & V_8 -> V_17 ) ;
V_8 -> V_14 = NULL ;
}
void F_33 ( struct V_7 * V_8 )
{
F_12 ( ! F_34 ( & V_8 -> V_50 . V_19 ) ,
L_2 ) ;
}
static unsigned long F_35 ( struct V_1 * V_30 ,
const char * V_51 )
{
unsigned long V_9 , V_10 , V_52 ;
if ( V_30 -> V_16 ) {
V_9 = F_2 ( V_30 ) ;
V_10 = F_3 ( V_30 ) ;
V_52 = V_10 - V_9 ;
F_36 ( V_53 L_3 ,
V_51 , V_9 , V_10 ,
V_52 ) ;
return V_52 ;
}
return 0 ;
}
void F_37 ( struct V_7 * V_8 , const char * V_51 )
{
struct V_1 * V_30 ;
unsigned long V_54 = 0 , V_55 = 0 , V_56 = 0 ;
V_55 += F_35 ( & V_8 -> V_50 , V_51 ) ;
F_38 (entry, mm) {
F_36 ( V_53 L_4 ,
V_51 , V_30 -> V_18 , V_30 -> V_18 + V_30 -> V_4 ,
V_30 -> V_4 ) ;
V_54 += V_30 -> V_4 ;
V_55 += F_35 ( V_30 , V_51 ) ;
}
V_56 = V_55 + V_54 ;
F_36 ( V_53 L_5 , V_51 , V_56 ,
V_54 , V_55 ) ;
}
static unsigned long F_39 ( struct V_57 * V_58 , struct V_1 * V_30 )
{
unsigned long V_9 , V_10 , V_52 ;
if ( V_30 -> V_16 ) {
V_9 = F_2 ( V_30 ) ;
V_10 = F_3 ( V_30 ) ;
V_52 = V_10 - V_9 ;
F_40 ( V_58 , L_6 ,
V_9 , V_10 , V_52 ) ;
return V_52 ;
}
return 0 ;
}
int F_41 ( struct V_57 * V_58 , struct V_7 * V_8 )
{
struct V_1 * V_30 ;
unsigned long V_54 = 0 , V_55 = 0 , V_56 = 0 ;
V_55 += F_39 ( V_58 , & V_8 -> V_50 ) ;
F_38 (entry, mm) {
F_40 ( V_58 , L_7 ,
V_30 -> V_18 , V_30 -> V_18 + V_30 -> V_4 ,
V_30 -> V_4 ) ;
V_54 += V_30 -> V_4 ;
V_55 += F_39 ( V_58 , V_30 ) ;
}
V_56 = V_55 + V_54 ;
F_40 ( V_58 , L_8 , V_56 , V_54 , V_55 ) ;
return 0 ;
}
