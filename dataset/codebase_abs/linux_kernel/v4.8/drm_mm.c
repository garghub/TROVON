static void F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
T_1 V_4 , unsigned V_5 ,
unsigned long V_6 ,
enum V_7 V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
T_1 V_11 = F_2 ( V_2 ) ;
T_1 V_12 = F_3 ( V_2 ) ;
T_1 V_13 = V_11 ;
T_1 V_14 = V_12 ;
F_4 ( V_3 -> V_15 ) ;
if ( V_10 -> V_16 )
V_10 -> V_16 ( V_2 , V_6 , & V_13 , & V_14 ) ;
if ( V_8 & V_17 )
V_13 = V_14 - V_4 ;
if ( V_5 ) {
T_1 V_18 = V_13 ;
unsigned V_19 ;
V_19 = F_5 ( V_18 , V_5 ) ;
if ( V_19 ) {
if ( V_8 & V_17 )
V_13 -= V_19 ;
else
V_13 += V_5 - V_19 ;
}
}
F_4 ( V_13 < V_11 ) ;
F_4 ( V_14 > V_12 ) ;
if ( V_13 == V_11 ) {
V_2 -> V_20 = 0 ;
F_6 ( & V_2 -> V_21 ) ;
}
V_3 -> V_22 = V_13 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_15 = 1 ;
F_7 ( & V_3 -> V_21 ) ;
F_8 ( & V_3 -> V_23 , & V_2 -> V_23 ) ;
F_4 ( V_3 -> V_22 + V_3 -> V_4 > V_14 ) ;
V_3 -> V_20 = 0 ;
if ( F_9 ( V_3 ) < V_12 ) {
F_8 ( & V_3 -> V_21 , & V_10 -> V_21 ) ;
V_3 -> V_20 = 1 ;
}
}
int F_10 ( struct V_9 * V_10 , struct V_1 * V_3 )
{
struct V_1 * V_24 ;
T_1 V_25 ;
T_1 V_11 ;
T_1 V_12 ;
F_4 ( V_3 == NULL ) ;
V_25 = V_3 -> V_22 + V_3 -> V_4 ;
F_11 (hole, mm, hole_start, hole_end) {
if ( V_11 > V_3 -> V_22 || V_12 < V_25 )
continue;
V_3 -> V_10 = V_10 ;
V_3 -> V_15 = 1 ;
F_7 ( & V_3 -> V_21 ) ;
F_8 ( & V_3 -> V_23 , & V_24 -> V_23 ) ;
if ( V_3 -> V_22 == V_11 ) {
V_24 -> V_20 = 0 ;
F_12 ( & V_24 -> V_21 ) ;
}
V_3 -> V_20 = 0 ;
if ( V_25 != V_12 ) {
F_8 ( & V_3 -> V_21 , & V_10 -> V_21 ) ;
V_3 -> V_20 = 1 ;
}
return 0 ;
}
return - V_26 ;
}
int F_13 ( struct V_9 * V_10 , struct V_1 * V_3 ,
T_1 V_4 , unsigned V_5 ,
unsigned long V_6 ,
enum V_27 V_28 ,
enum V_7 V_29 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_10 , V_4 , V_5 ,
V_6 , V_28 ) ;
if ( ! V_2 )
return - V_26 ;
F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_29 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_1 * V_3 ,
T_1 V_4 , unsigned V_5 ,
unsigned long V_6 ,
T_1 V_22 , T_1 V_25 ,
enum V_7 V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
T_1 V_11 = F_2 ( V_2 ) ;
T_1 V_12 = F_3 ( V_2 ) ;
T_1 V_13 = V_11 ;
T_1 V_14 = V_12 ;
F_4 ( ! V_2 -> V_20 || V_3 -> V_15 ) ;
if ( V_13 < V_22 )
V_13 = V_22 ;
if ( V_14 > V_25 )
V_14 = V_25 ;
if ( V_10 -> V_16 )
V_10 -> V_16 ( V_2 , V_6 , & V_13 , & V_14 ) ;
if ( V_8 & V_17 )
V_13 = V_14 - V_4 ;
if ( V_5 ) {
T_1 V_18 = V_13 ;
unsigned V_19 ;
V_19 = F_5 ( V_18 , V_5 ) ;
if ( V_19 ) {
if ( V_8 & V_17 )
V_13 -= V_19 ;
else
V_13 += V_5 - V_19 ;
}
}
if ( V_13 == V_11 ) {
V_2 -> V_20 = 0 ;
F_6 ( & V_2 -> V_21 ) ;
}
V_3 -> V_22 = V_13 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_10 = V_10 ;
V_3 -> V_6 = V_6 ;
V_3 -> V_15 = 1 ;
F_7 ( & V_3 -> V_21 ) ;
F_8 ( & V_3 -> V_23 , & V_2 -> V_23 ) ;
F_4 ( V_3 -> V_22 < V_22 ) ;
F_4 ( V_3 -> V_22 < V_13 ) ;
F_4 ( V_3 -> V_22 + V_3 -> V_4 > V_14 ) ;
F_4 ( V_3 -> V_22 + V_3 -> V_4 > V_25 ) ;
V_3 -> V_20 = 0 ;
if ( F_9 ( V_3 ) < V_12 ) {
F_8 ( & V_3 -> V_21 , & V_10 -> V_21 ) ;
V_3 -> V_20 = 1 ;
}
}
int F_16 ( struct V_9 * V_10 , struct V_1 * V_3 ,
T_1 V_4 , unsigned V_5 ,
unsigned long V_6 ,
T_1 V_22 , T_1 V_25 ,
enum V_27 V_28 ,
enum V_7 V_29 )
{
struct V_1 * V_2 ;
V_2 = F_17 ( V_10 ,
V_4 , V_5 , V_6 ,
V_22 , V_25 , V_28 ) ;
if ( ! V_2 )
return - V_26 ;
F_15 ( V_2 , V_3 ,
V_4 , V_5 , V_6 ,
V_22 , V_25 , V_29 ) ;
return 0 ;
}
void F_18 ( struct V_1 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_30 ;
if ( F_19 ( ! V_3 -> V_15 ) )
return;
F_4 ( V_3 -> V_31 || V_3 -> V_32
|| V_3 -> V_33 ) ;
V_30 =
F_20 ( V_3 -> V_23 . V_34 , struct V_1 , V_23 ) ;
if ( V_3 -> V_20 ) {
F_4 ( F_9 ( V_3 ) ==
F_21 ( V_3 ) ) ;
F_6 ( & V_3 -> V_21 ) ;
} else
F_4 ( F_9 ( V_3 ) !=
F_21 ( V_3 ) ) ;
if ( ! V_30 -> V_20 ) {
V_30 -> V_20 = 1 ;
F_8 ( & V_30 -> V_21 , & V_10 -> V_21 ) ;
} else
F_22 ( & V_30 -> V_21 , & V_10 -> V_21 ) ;
F_6 ( & V_3 -> V_23 ) ;
V_3 -> V_15 = 0 ;
}
static int F_23 ( T_1 V_22 , T_1 V_25 , T_1 V_4 , unsigned V_5 )
{
if ( V_25 - V_22 < V_4 )
return 0 ;
if ( V_5 ) {
T_1 V_18 = V_22 ;
unsigned V_19 ;
V_19 = F_5 ( V_18 , V_5 ) ;
if ( V_19 )
V_22 += V_5 - V_19 ;
}
return V_25 >= V_22 + V_4 ;
}
static struct V_1 * F_14 ( const struct V_9 * V_10 ,
T_1 V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
enum V_27 V_8 )
{
struct V_1 * V_35 ;
struct V_1 * V_36 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_37 ;
F_4 ( V_10 -> V_38 ) ;
V_36 = NULL ;
V_37 = ~ 0UL ;
F_24 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
T_1 V_39 = V_14 - V_13 ;
if ( V_10 -> V_16 ) {
V_10 -> V_16 ( V_35 , V_6 , & V_13 , & V_14 ) ;
if ( V_14 <= V_13 )
continue;
}
if ( ! F_23 ( V_13 , V_14 , V_4 , V_5 ) )
continue;
if ( ! ( V_8 & V_40 ) )
return V_35 ;
if ( V_39 < V_37 ) {
V_36 = V_35 ;
V_37 = V_39 ;
}
}
return V_36 ;
}
static struct V_1 * F_17 ( const struct V_9 * V_10 ,
T_1 V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
T_1 V_22 ,
T_1 V_25 ,
enum V_27 V_8 )
{
struct V_1 * V_35 ;
struct V_1 * V_36 ;
T_1 V_13 ;
T_1 V_14 ;
T_1 V_37 ;
F_4 ( V_10 -> V_38 ) ;
V_36 = NULL ;
V_37 = ~ 0UL ;
F_24 (entry, mm, adj_start, adj_end,
flags & DRM_MM_SEARCH_BELOW) {
T_1 V_39 = V_14 - V_13 ;
if ( V_13 < V_22 )
V_13 = V_22 ;
if ( V_14 > V_25 )
V_14 = V_25 ;
if ( V_10 -> V_16 ) {
V_10 -> V_16 ( V_35 , V_6 , & V_13 , & V_14 ) ;
if ( V_14 <= V_13 )
continue;
}
if ( ! F_23 ( V_13 , V_14 , V_4 , V_5 ) )
continue;
if ( ! ( V_8 & V_40 ) )
return V_35 ;
if ( V_39 < V_37 ) {
V_36 = V_35 ;
V_37 = V_39 ;
}
}
return V_36 ;
}
void F_25 ( struct V_1 * V_41 , struct V_1 * V_42 )
{
F_26 ( & V_41 -> V_23 , & V_42 -> V_23 ) ;
F_26 ( & V_41 -> V_21 , & V_42 -> V_21 ) ;
V_42 -> V_20 = V_41 -> V_20 ;
V_42 -> V_10 = V_41 -> V_10 ;
V_42 -> V_22 = V_41 -> V_22 ;
V_42 -> V_4 = V_41 -> V_4 ;
V_42 -> V_6 = V_41 -> V_6 ;
V_41 -> V_15 = 0 ;
V_42 -> V_15 = 1 ;
}
void F_27 ( struct V_9 * V_10 ,
T_1 V_4 ,
unsigned V_5 ,
unsigned long V_6 )
{
V_10 -> V_43 = V_6 ;
V_10 -> V_44 = V_5 ;
V_10 -> V_45 = V_4 ;
V_10 -> V_38 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_47 = 0 ;
V_10 -> V_48 = 0 ;
V_10 -> V_49 = NULL ;
}
void F_28 ( struct V_9 * V_10 ,
T_1 V_4 ,
unsigned V_5 ,
unsigned long V_6 ,
T_1 V_22 ,
T_1 V_25 )
{
V_10 -> V_43 = V_6 ;
V_10 -> V_44 = V_5 ;
V_10 -> V_45 = V_4 ;
V_10 -> V_38 = 0 ;
V_10 -> V_46 = 0 ;
V_10 -> V_47 = 0 ;
V_10 -> V_50 = V_22 ;
V_10 -> V_51 = V_25 ;
V_10 -> V_48 = 1 ;
V_10 -> V_49 = NULL ;
}
bool F_29 ( struct V_1 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_30 ;
T_1 V_11 , V_12 ;
T_1 V_13 , V_14 ;
V_10 -> V_38 ++ ;
F_4 ( V_3 -> V_31 ) ;
V_3 -> V_31 = 1 ;
V_30 = F_20 ( V_3 -> V_23 . V_34 , struct V_1 ,
V_23 ) ;
V_3 -> V_52 = V_30 -> V_20 ;
V_30 -> V_20 = 1 ;
F_6 ( & V_3 -> V_23 ) ;
V_3 -> V_23 . V_34 = & V_30 -> V_23 ;
V_3 -> V_23 . V_53 = & V_10 -> V_49 -> V_23 ;
V_10 -> V_49 = V_3 ;
V_13 = V_11 = F_2 ( V_30 ) ;
V_14 = V_12 = F_3 ( V_30 ) ;
if ( V_10 -> V_48 ) {
if ( V_13 < V_10 -> V_50 )
V_13 = V_10 -> V_50 ;
if ( V_14 > V_10 -> V_51 )
V_14 = V_10 -> V_51 ;
}
if ( V_10 -> V_16 )
V_10 -> V_16 ( V_30 , V_10 -> V_43 ,
& V_13 , & V_14 ) ;
if ( F_23 ( V_13 , V_14 ,
V_10 -> V_45 , V_10 -> V_44 ) ) {
V_10 -> V_46 = V_11 ;
V_10 -> V_47 = V_12 ;
return true ;
}
return false ;
}
bool F_30 ( struct V_1 * V_3 )
{
struct V_9 * V_10 = V_3 -> V_10 ;
struct V_1 * V_30 ;
V_10 -> V_38 -- ;
F_4 ( ! V_3 -> V_31 ) ;
V_3 -> V_31 = 0 ;
V_30 = F_20 ( V_3 -> V_23 . V_34 , struct V_1 ,
V_23 ) ;
V_30 -> V_20 = V_3 -> V_52 ;
F_8 ( & V_3 -> V_23 , & V_30 -> V_23 ) ;
return ( F_3 ( V_3 ) > V_10 -> V_46 &&
V_3 -> V_22 < V_10 -> V_47 ) ;
}
bool F_31 ( struct V_9 * V_10 )
{
struct V_54 * V_55 = & V_10 -> V_56 . V_23 ;
return ( V_55 -> V_53 -> V_53 == V_55 ) ;
}
void F_32 ( struct V_9 * V_10 , T_1 V_22 , T_1 V_4 )
{
F_7 ( & V_10 -> V_21 ) ;
V_10 -> V_38 = 0 ;
F_7 ( & V_10 -> V_56 . V_23 ) ;
F_7 ( & V_10 -> V_56 . V_21 ) ;
V_10 -> V_56 . V_20 = 1 ;
V_10 -> V_56 . V_31 = 0 ;
V_10 -> V_56 . V_32 = 0 ;
V_10 -> V_56 . V_33 = 0 ;
V_10 -> V_56 . V_10 = V_10 ;
V_10 -> V_56 . V_22 = V_22 + V_4 ;
V_10 -> V_56 . V_4 = V_22 - V_10 -> V_56 . V_22 ;
F_33 ( & V_10 -> V_56 . V_21 , & V_10 -> V_21 ) ;
V_10 -> V_16 = NULL ;
}
void F_34 ( struct V_9 * V_10 )
{
F_35 ( ! F_36 ( & V_10 -> V_56 . V_23 ) ,
L_1 ) ;
}
static T_1 F_37 ( struct V_1 * V_35 ,
const char * V_57 )
{
T_1 V_11 , V_12 , V_39 ;
if ( V_35 -> V_20 ) {
V_11 = F_2 ( V_35 ) ;
V_12 = F_3 ( V_35 ) ;
V_39 = V_12 - V_11 ;
F_38 ( L_2 , V_57 , V_11 ,
V_12 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
void F_39 ( struct V_9 * V_10 , const char * V_57 )
{
struct V_1 * V_35 ;
T_1 V_58 = 0 , V_59 = 0 , V_60 = 0 ;
V_59 += F_37 ( & V_10 -> V_56 , V_57 ) ;
F_40 (entry, mm) {
F_38 ( L_3 , V_57 , V_35 -> V_22 ,
V_35 -> V_22 + V_35 -> V_4 , V_35 -> V_4 ) ;
V_58 += V_35 -> V_4 ;
V_59 += F_37 ( V_35 , V_57 ) ;
}
V_60 = V_59 + V_58 ;
F_38 ( L_4 , V_57 , V_60 ,
V_58 , V_59 ) ;
}
static T_1 F_41 ( struct V_61 * V_62 , struct V_1 * V_35 )
{
T_1 V_11 , V_12 , V_39 ;
if ( V_35 -> V_20 ) {
V_11 = F_2 ( V_35 ) ;
V_12 = F_3 ( V_35 ) ;
V_39 = V_12 - V_11 ;
F_42 ( V_62 , L_5 , V_11 ,
V_12 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
int F_43 ( struct V_61 * V_62 , struct V_9 * V_10 )
{
struct V_1 * V_35 ;
T_1 V_58 = 0 , V_59 = 0 , V_60 = 0 ;
V_59 += F_41 ( V_62 , & V_10 -> V_56 ) ;
F_40 (entry, mm) {
F_42 ( V_62 , L_6 , V_35 -> V_22 ,
V_35 -> V_22 + V_35 -> V_4 , V_35 -> V_4 ) ;
V_58 += V_35 -> V_4 ;
V_59 += F_41 ( V_62 , V_35 ) ;
}
V_60 = V_59 + V_58 ;
F_42 ( V_62 , L_7 , V_60 ,
V_58 , V_59 ) ;
return 0 ;
}
