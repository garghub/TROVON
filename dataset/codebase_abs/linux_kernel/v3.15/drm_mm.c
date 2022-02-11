static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 ,
unsigned long V_6 ,
enum V_7 V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned long V_11 = F_2 ( V_2 ) ;
unsigned long V_12 = F_3 ( V_2 ) ;
unsigned long V_13 = V_11 ;
unsigned long V_14 = V_12 ;
F_4 ( V_3 -> V_15 ) ;
if ( V_10 -> V_16 )
V_10 -> V_16 ( V_2 , V_6 , & V_13 , & V_14 ) ;
if ( V_8 & V_17 )
V_13 = V_14 - V_4 ;
if ( V_5 ) {
unsigned V_18 = V_13 % V_5 ;
if ( V_18 ) {
if ( V_8 & V_17 )
V_13 -= V_18 ;
else
V_13 += V_5 - V_18 ;
}
}
F_4 ( V_13 < V_11 ) ;
F_4 ( V_14 > V_12 ) ;
if ( V_13 == V_11 ) {
V_2 -> V_19 = 0 ;
F_5 ( & V_2 -> V_20 ) ;
}
V_3 -> V_21 = V_13 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_15 = 1 ;
F_6 ( & V_3 -> V_20 ) ;
F_7 ( & V_3 -> V_22 , & V_2 -> V_22 ) ;
F_4 ( V_3 -> V_21 + V_3 -> V_4 > V_14 ) ;
V_3 -> V_19 = 0 ;
if ( F_8 ( V_3 ) < V_12 ) {
F_7 ( & V_3 -> V_20 , & V_10 -> V_20 ) ;
V_3 -> V_19 = 1 ;
}
}
int F_9 ( struct V_9 * V_10 , struct V_1 * V_3 )
{
struct V_1 * V_23 ;
unsigned long V_24 = V_3 -> V_21 + V_3 -> V_4 ;
unsigned long V_11 ;
unsigned long V_12 ;
F_4 ( V_3 == NULL ) ;
F_10 (hole, mm, hole_start, hole_end) {
if ( V_11 > V_3 -> V_21 || V_12 < V_24 )
continue;
V_3 -> V_10 = V_10 ;
V_3 -> V_15 = 1 ;
F_6 ( & V_3 -> V_20 ) ;
F_7 ( & V_3 -> V_22 , & V_23 -> V_22 ) ;
if ( V_3 -> V_21 == V_11 ) {
V_23 -> V_19 = 0 ;
F_11 ( & V_23 -> V_20 ) ;
}
V_3 -> V_19 = 0 ;
if ( V_24 != V_12 ) {
F_7 ( & V_3 -> V_20 , & V_10 -> V_20 ) ;
V_3 -> V_19 = 1 ;
}
return 0 ;
}
return - V_25 ;
}
int F_12 ( struct V_9 * V_10 , struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 ,
unsigned long V_6 ,
enum V_26 V_27 ,
enum V_7 V_28 )
{
struct V_1 * V_2 ;
V_2 = F_13 ( V_10 , V_4 , V_5 ,
V_6 , V_27 ) ;
if ( ! V_2 )
return - V_25 ;
F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_28 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 ,
unsigned long V_6 ,
unsigned long V_21 , unsigned long V_24 ,
enum V_7 V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned long V_11 = F_2 ( V_2 ) ;
unsigned long V_12 = F_3 ( V_2 ) ;
unsigned long V_13 = V_11 ;
unsigned long V_14 = V_12 ;
F_4 ( ! V_2 -> V_19 || V_3 -> V_15 ) ;
if ( V_13 < V_21 )
V_13 = V_21 ;
if ( V_14 > V_24 )
V_14 = V_24 ;
if ( V_8 & V_17 )
V_13 = V_14 - V_4 ;
if ( V_10 -> V_16 )
V_10 -> V_16 ( V_2 , V_6 , & V_13 , & V_14 ) ;
if ( V_5 ) {
unsigned V_18 = V_13 % V_5 ;
if ( V_18 ) {
if ( V_8 & V_17 )
V_13 -= V_18 ;
else
V_13 += V_5 - V_18 ;
}
}
if ( V_13 == V_11 ) {
V_2 -> V_19 = 0 ;
F_5 ( & V_2 -> V_20 ) ;
}
V_3 -> V_21 = V_13 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_15 = 1 ;
F_6 ( & V_3 -> V_20 ) ;
F_7 ( & V_3 -> V_22 , & V_2 -> V_22 ) ;
F_4 ( V_3 -> V_21 < V_21 ) ;
F_4 ( V_3 -> V_21 < V_13 ) ;
F_4 ( V_3 -> V_21 + V_3 -> V_4 > V_14 ) ;
F_4 ( V_3 -> V_21 + V_3 -> V_4 > V_24 ) ;
V_3 -> V_19 = 0 ;
if ( F_8 ( V_3 ) < V_12 ) {
F_7 ( & V_3 -> V_20 , & V_10 -> V_20 ) ;
V_3 -> V_19 = 1 ;
}
}
int F_15 ( struct V_9 * V_10 , struct V_1 * V_3 ,
unsigned long V_4 , unsigned V_5 ,
unsigned long V_6 ,
unsigned long V_21 , unsigned long V_24 ,
enum V_26 V_27 ,
enum V_7 V_28 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_10 ,
V_4 , V_5 , V_6 ,
V_21 , V_24 , V_27 ) ;
if ( ! V_2 )
return - V_25 ;
F_14 ( V_2 , V_3 ,
V_4 , V_5 , V_6 ,
V_21 , V_24 , V_28 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_29 ;
if ( F_18 ( ! V_3 -> V_15 ) )
return;
F_4 ( V_3 -> V_30 || V_3 -> V_31
|| V_3 -> V_32 ) ;
V_29 =
F_19 ( V_3 -> V_22 . V_33 , struct V_1 , V_22 ) ;
if ( V_3 -> V_19 ) {
F_4 ( F_8 ( V_3 ) ==
F_20 ( V_3 ) ) ;
F_5 ( & V_3 -> V_20 ) ;
} else
F_4 ( F_8 ( V_3 ) !=
F_20 ( V_3 ) ) ;
if ( ! V_29 -> V_19 ) {
V_29 -> V_19 = 1 ;
F_7 ( & V_29 -> V_20 , & V_10 -> V_20 ) ;
} else
F_21 ( & V_29 -> V_20 , & V_10 -> V_20 ) ;
F_5 ( & V_3 -> V_22 ) ;
V_3 -> V_15 = 0 ;
}
static int F_22 ( unsigned long V_21 , unsigned long V_24 ,
unsigned long V_4 , unsigned V_5 )
{
if ( V_24 - V_21 < V_4 )
return 0 ;
if ( V_5 ) {
unsigned V_18 = V_21 % V_5 ;
if ( V_18 )
V_21 += V_5 - V_18 ;
}
return V_24 >= V_21 + V_4 ;
}
static struct V_1 * F_13 ( const struct V_9 * V_10 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
enum V_26 V_8 )
{
struct V_1 * V_34 ;
struct V_1 * V_35 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_36 ;
F_4 ( V_10 -> V_37 ) ;
V_35 = NULL ;
V_36 = ~ 0UL ;
F_23 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
unsigned long V_38 = V_14 - V_13 ;
if ( V_10 -> V_16 ) {
V_10 -> V_16 ( V_34 , V_6 , & V_13 , & V_14 ) ;
if ( V_14 <= V_13 )
continue;
}
if ( ! F_22 ( V_13 , V_14 , V_4 , V_5 ) )
continue;
if ( ! ( V_8 & V_39 ) )
return V_34 ;
if ( V_38 < V_36 ) {
V_35 = V_34 ;
V_36 = V_38 ;
}
}
return V_35 ;
}
static struct V_1 * F_16 ( const struct V_9 * V_10 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
unsigned long V_21 ,
unsigned long V_24 ,
enum V_26 V_8 )
{
struct V_1 * V_34 ;
struct V_1 * V_35 ;
unsigned long V_13 ;
unsigned long V_14 ;
unsigned long V_36 ;
F_4 ( V_10 -> V_37 ) ;
V_35 = NULL ;
V_36 = ~ 0UL ;
F_23 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
unsigned long V_38 = V_14 - V_13 ;
if ( V_13 < V_21 )
V_13 = V_21 ;
if ( V_14 > V_24 )
V_14 = V_24 ;
if ( V_10 -> V_16 ) {
V_10 -> V_16 ( V_34 , V_6 , & V_13 , & V_14 ) ;
if ( V_14 <= V_13 )
continue;
}
if ( ! F_22 ( V_13 , V_14 , V_4 , V_5 ) )
continue;
if ( ! ( V_8 & V_39 ) )
return V_34 ;
if ( V_38 < V_36 ) {
V_35 = V_34 ;
V_36 = V_38 ;
}
}
return V_35 ;
}
void F_24 ( struct V_1 * V_40 , struct V_1 * V_41 )
{
F_25 ( & V_40 -> V_22 , & V_41 -> V_22 ) ;
F_25 ( & V_40 -> V_20 , & V_41 -> V_20 ) ;
V_41 -> V_19 = V_40 -> V_19 ;
V_41 -> V_10 = V_40 -> V_10 ;
V_41 -> V_21 = V_40 -> V_21 ;
V_41 -> V_4 = V_40 -> V_4 ;
V_41 -> V_6 = V_40 -> V_6 ;
V_40 -> V_15 = 0 ;
V_41 -> V_15 = 1 ;
}
void F_26 ( struct V_9 * V_10 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 )
{
V_10 -> V_42 = V_6 ;
V_10 -> V_43 = V_5 ;
V_10 -> V_44 = V_4 ;
V_10 -> V_37 = 0 ;
V_10 -> V_45 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_47 = 0 ;
V_10 -> V_48 = NULL ;
}
void F_27 ( struct V_9 * V_10 ,
unsigned long V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
unsigned long V_21 ,
unsigned long V_24 )
{
V_10 -> V_42 = V_6 ;
V_10 -> V_43 = V_5 ;
V_10 -> V_44 = V_4 ;
V_10 -> V_37 = 0 ;
V_10 -> V_45 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_49 = V_21 ;
V_10 -> V_50 = V_24 ;
V_10 -> V_47 = 1 ;
V_10 -> V_48 = NULL ;
}
bool F_28 ( struct V_1 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_29 ;
unsigned long V_11 , V_12 ;
unsigned long V_13 , V_14 ;
V_10 -> V_37 ++ ;
F_4 ( V_3 -> V_30 ) ;
V_3 -> V_30 = 1 ;
V_29 = F_19 ( V_3 -> V_22 . V_33 , struct V_1 ,
V_22 ) ;
V_3 -> V_51 = V_29 -> V_19 ;
V_29 -> V_19 = 1 ;
F_5 ( & V_3 -> V_22 ) ;
V_3 -> V_22 . V_33 = & V_29 -> V_22 ;
V_3 -> V_22 . V_52 = & V_10 -> V_48 -> V_22 ;
V_10 -> V_48 = V_3 ;
V_13 = V_11 = F_2 ( V_29 ) ;
V_14 = V_12 = F_3 ( V_29 ) ;
if ( V_10 -> V_47 ) {
if ( V_13 < V_10 -> V_49 )
V_13 = V_10 -> V_49 ;
if ( V_14 > V_10 -> V_50 )
V_14 = V_10 -> V_50 ;
}
if ( V_10 -> V_16 )
V_10 -> V_16 ( V_29 , V_10 -> V_42 ,
& V_13 , & V_14 ) ;
if ( F_22 ( V_13 , V_14 ,
V_10 -> V_44 , V_10 -> V_43 ) ) {
V_10 -> V_45 = V_11 ;
V_10 -> V_46 = V_12 ;
return true ;
}
return false ;
}
bool F_29 ( struct V_1 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_29 ;
V_10 -> V_37 -- ;
F_4 ( ! V_3 -> V_30 ) ;
V_3 -> V_30 = 0 ;
V_29 = F_19 ( V_3 -> V_22 . V_33 , struct V_1 ,
V_22 ) ;
V_29 -> V_19 = V_3 -> V_51 ;
F_7 ( & V_3 -> V_22 , & V_29 -> V_22 ) ;
return ( F_3 ( V_3 ) > V_10 -> V_45 &&
V_3 -> V_21 < V_10 -> V_46 ) ;
}
bool F_30 ( struct V_9 * V_10 )
{
struct V_53 * V_54 = & V_10 -> V_55 . V_22 ;
return ( V_54 -> V_52 -> V_52 == V_54 ) ;
}
void F_31 ( struct V_9 * V_10 , unsigned long V_21 , unsigned long V_4 )
{
F_6 ( & V_10 -> V_20 ) ;
V_10 -> V_37 = 0 ;
F_6 ( & V_10 -> V_55 . V_22 ) ;
F_6 ( & V_10 -> V_55 . V_20 ) ;
V_10 -> V_55 . V_19 = 1 ;
V_10 -> V_55 . V_30 = 0 ;
V_10 -> V_55 . V_31 = 0 ;
V_10 -> V_55 . V_32 = 0 ;
V_10 -> V_55 . V_10 = V_10 ;
V_10 -> V_55 . V_21 = V_21 + V_4 ;
V_10 -> V_55 . V_4 = V_21 - V_10 -> V_55 . V_21 ;
F_32 ( & V_10 -> V_55 . V_20 , & V_10 -> V_20 ) ;
V_10 -> V_16 = NULL ;
}
void F_33 ( struct V_9 * V_10 )
{
F_34 ( ! F_35 ( & V_10 -> V_55 . V_22 ) ,
L_1 ) ;
}
static unsigned long F_36 ( struct V_1 * V_34 ,
const char * V_56 )
{
unsigned long V_11 , V_12 , V_38 ;
if ( V_34 -> V_19 ) {
V_11 = F_2 ( V_34 ) ;
V_12 = F_3 ( V_34 ) ;
V_38 = V_12 - V_11 ;
F_37 ( V_57 L_2 ,
V_56 , V_11 , V_12 ,
V_38 ) ;
return V_38 ;
}
return 0 ;
}
void F_38 ( struct V_9 * V_10 , const char * V_56 )
{
struct V_1 * V_34 ;
unsigned long V_58 = 0 , V_59 = 0 , V_60 = 0 ;
V_59 += F_36 ( & V_10 -> V_55 , V_56 ) ;
F_39 (entry, mm) {
F_37 ( V_57 L_3 ,
V_56 , V_34 -> V_21 , V_34 -> V_21 + V_34 -> V_4 ,
V_34 -> V_4 ) ;
V_58 += V_34 -> V_4 ;
V_59 += F_36 ( V_34 , V_56 ) ;
}
V_60 = V_59 + V_58 ;
F_37 ( V_57 L_4 , V_56 , V_60 ,
V_58 , V_59 ) ;
}
static unsigned long F_40 ( struct V_61 * V_62 , struct V_1 * V_34 )
{
unsigned long V_11 , V_12 , V_38 ;
if ( V_34 -> V_19 ) {
V_11 = F_2 ( V_34 ) ;
V_12 = F_3 ( V_34 ) ;
V_38 = V_12 - V_11 ;
F_41 ( V_62 , L_5 ,
V_11 , V_12 , V_38 ) ;
return V_38 ;
}
return 0 ;
}
int F_42 ( struct V_61 * V_62 , struct V_9 * V_10 )
{
struct V_1 * V_34 ;
unsigned long V_58 = 0 , V_59 = 0 , V_60 = 0 ;
V_59 += F_40 ( V_62 , & V_10 -> V_55 ) ;
F_39 (entry, mm) {
F_41 ( V_62 , L_6 ,
V_34 -> V_21 , V_34 -> V_21 + V_34 -> V_4 ,
V_34 -> V_4 ) ;
V_58 += V_34 -> V_4 ;
V_59 += F_40 ( V_62 , V_34 ) ;
}
V_60 = V_59 + V_58 ;
F_41 ( V_62 , L_7 , V_60 , V_58 , V_59 ) ;
return 0 ;
}
