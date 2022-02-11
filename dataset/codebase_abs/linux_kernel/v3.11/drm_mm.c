static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
if ( V_4 )
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
else
V_5 = F_2 ( sizeof( * V_5 ) , V_7 ) ;
if ( F_3 ( V_5 == NULL ) ) {
F_4 ( & V_3 -> V_8 ) ;
if ( F_5 ( & V_3 -> V_9 ) )
V_5 = NULL ;
else {
V_5 =
F_6 ( V_3 -> V_9 . V_10 ,
struct V_1 , V_11 ) ;
F_7 ( & V_5 -> V_11 ) ;
-- V_3 -> V_12 ;
}
F_8 ( & V_3 -> V_8 ) ;
}
return V_5 ;
}
int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_13 ;
F_4 ( & V_3 -> V_8 ) ;
while ( V_3 -> V_12 < V_14 ) {
F_8 ( & V_3 -> V_8 ) ;
V_13 = F_2 ( sizeof( * V_13 ) , V_7 ) ;
F_4 ( & V_3 -> V_8 ) ;
if ( F_3 ( V_13 == NULL ) ) {
int V_15 = ( V_3 -> V_12 < 2 ) ? - V_16 : 0 ;
F_8 ( & V_3 -> V_8 ) ;
return V_15 ;
}
++ V_3 -> V_12 ;
F_10 ( & V_13 -> V_11 , & V_3 -> V_9 ) ;
}
F_8 ( & V_3 -> V_8 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_17 ,
struct V_1 * V_13 ,
unsigned long V_18 , unsigned V_19 ,
unsigned long V_20 )
{
struct V_2 * V_3 = V_17 -> V_3 ;
unsigned long V_21 = F_12 ( V_17 ) ;
unsigned long V_22 = F_13 ( V_17 ) ;
unsigned long V_23 = V_21 ;
unsigned long V_24 = V_22 ;
F_14 ( V_13 -> V_25 ) ;
if ( V_3 -> V_26 )
V_3 -> V_26 ( V_17 , V_20 , & V_23 , & V_24 ) ;
if ( V_19 ) {
unsigned V_27 = V_23 % V_19 ;
if ( V_27 )
V_23 += V_19 - V_27 ;
}
if ( V_23 == V_21 ) {
V_17 -> V_28 = 0 ;
F_7 ( & V_17 -> V_29 ) ;
}
V_13 -> V_30 = V_23 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_20 = V_20 ;
V_13 -> V_25 = 1 ;
F_15 ( & V_13 -> V_29 ) ;
F_16 ( & V_13 -> V_11 , & V_17 -> V_11 ) ;
F_14 ( V_13 -> V_30 + V_13 -> V_18 > V_24 ) ;
V_13 -> V_28 = 0 ;
if ( F_17 ( V_13 ) < V_22 ) {
F_16 ( & V_13 -> V_29 , & V_3 -> V_29 ) ;
V_13 -> V_28 = 1 ;
}
}
struct V_1 * F_18 ( struct V_2 * V_3 ,
unsigned long V_30 ,
unsigned long V_18 ,
bool V_4 )
{
struct V_1 * V_31 , * V_13 ;
unsigned long V_32 = V_30 + V_18 ;
unsigned long V_21 ;
unsigned long V_22 ;
F_19 (hole, mm, hole_start, hole_end) {
if ( V_21 > V_30 || V_22 < V_32 )
continue;
V_13 = F_1 ( V_3 , V_4 ) ;
if ( F_3 ( V_13 == NULL ) )
return NULL ;
V_13 -> V_30 = V_30 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_25 = 1 ;
F_15 ( & V_13 -> V_29 ) ;
F_16 ( & V_13 -> V_11 , & V_31 -> V_11 ) ;
if ( V_30 == V_21 ) {
V_31 -> V_28 = 0 ;
F_20 ( & V_31 -> V_29 ) ;
}
V_13 -> V_28 = 0 ;
if ( V_32 != V_22 ) {
F_16 ( & V_13 -> V_29 , & V_3 -> V_29 ) ;
V_13 -> V_28 = 1 ;
}
return V_13 ;
}
F_21 ( 1 , L_1 , V_30 , V_18 ) ;
return NULL ;
}
struct V_1 * F_22 ( struct V_1 * V_17 ,
unsigned long V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
int V_4 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_17 -> V_3 , V_4 ) ;
if ( F_3 ( V_13 == NULL ) )
return NULL ;
F_11 ( V_17 , V_13 , V_18 , V_19 , V_20 ) ;
return V_13 ;
}
int F_23 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_18 , unsigned V_19 ,
unsigned long V_20 )
{
struct V_1 * V_17 ;
V_17 = F_24 ( V_3 , V_18 , V_19 ,
V_20 , 0 ) ;
if ( ! V_17 )
return - V_33 ;
F_11 ( V_17 , V_13 , V_18 , V_19 , V_20 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_18 , unsigned V_19 )
{
return F_23 ( V_3 , V_13 , V_18 , V_19 , 0 ) ;
}
static void F_26 ( struct V_1 * V_17 ,
struct V_1 * V_13 ,
unsigned long V_18 , unsigned V_19 ,
unsigned long V_20 ,
unsigned long V_30 , unsigned long V_32 )
{
struct V_2 * V_3 = V_17 -> V_3 ;
unsigned long V_21 = F_12 ( V_17 ) ;
unsigned long V_22 = F_13 ( V_17 ) ;
unsigned long V_23 = V_21 ;
unsigned long V_24 = V_22 ;
F_14 ( ! V_17 -> V_28 || V_13 -> V_25 ) ;
if ( V_23 < V_30 )
V_23 = V_30 ;
if ( V_24 > V_32 )
V_24 = V_32 ;
if ( V_3 -> V_26 )
V_3 -> V_26 ( V_17 , V_20 , & V_23 , & V_24 ) ;
if ( V_19 ) {
unsigned V_27 = V_23 % V_19 ;
if ( V_27 )
V_23 += V_19 - V_27 ;
}
if ( V_23 == V_21 ) {
V_17 -> V_28 = 0 ;
F_7 ( & V_17 -> V_29 ) ;
}
V_13 -> V_30 = V_23 ;
V_13 -> V_18 = V_18 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_20 = V_20 ;
V_13 -> V_25 = 1 ;
F_15 ( & V_13 -> V_29 ) ;
F_16 ( & V_13 -> V_11 , & V_17 -> V_11 ) ;
F_14 ( V_13 -> V_30 + V_13 -> V_18 > V_24 ) ;
F_14 ( V_13 -> V_30 + V_13 -> V_18 > V_32 ) ;
V_13 -> V_28 = 0 ;
if ( F_17 ( V_13 ) < V_22 ) {
F_16 ( & V_13 -> V_29 , & V_3 -> V_29 ) ;
V_13 -> V_28 = 1 ;
}
}
struct V_1 * F_27 ( struct V_1 * V_17 ,
unsigned long V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
unsigned long V_30 ,
unsigned long V_32 ,
int V_4 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_17 -> V_3 , V_4 ) ;
if ( F_3 ( V_13 == NULL ) )
return NULL ;
F_26 ( V_17 , V_13 , V_18 , V_19 , V_20 ,
V_30 , V_32 ) ;
return V_13 ;
}
int F_28 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_18 , unsigned V_19 , unsigned long V_20 ,
unsigned long V_30 , unsigned long V_32 )
{
struct V_1 * V_17 ;
V_17 = F_29 ( V_3 ,
V_18 , V_19 , V_20 ,
V_30 , V_32 , 0 ) ;
if ( ! V_17 )
return - V_33 ;
F_26 ( V_17 , V_13 ,
V_18 , V_19 , V_20 ,
V_30 , V_32 ) ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_18 , unsigned V_19 ,
unsigned long V_30 , unsigned long V_32 )
{
return F_28 ( V_3 , V_13 , V_18 , V_19 , 0 , V_30 , V_32 ) ;
}
void F_31 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_34 ;
F_14 ( V_13 -> V_35 || V_13 -> V_36
|| V_13 -> V_37 ) ;
V_34 =
F_6 ( V_13 -> V_11 . V_38 , struct V_1 , V_11 ) ;
if ( V_13 -> V_28 ) {
F_14 ( F_17 ( V_13 ) ==
F_32 ( V_13 ) ) ;
F_7 ( & V_13 -> V_29 ) ;
} else
F_14 ( F_17 ( V_13 ) !=
F_32 ( V_13 ) ) ;
if ( ! V_34 -> V_28 ) {
V_34 -> V_28 = 1 ;
F_16 ( & V_34 -> V_29 , & V_3 -> V_29 ) ;
} else
F_33 ( & V_34 -> V_29 , & V_3 -> V_29 ) ;
F_7 ( & V_13 -> V_11 ) ;
V_13 -> V_25 = 0 ;
}
void F_34 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
F_31 ( V_13 ) ;
F_4 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_12 < V_14 ) {
F_16 ( & V_13 -> V_11 , & V_3 -> V_9 ) ;
++ V_3 -> V_12 ;
} else
F_35 ( V_13 ) ;
F_8 ( & V_3 -> V_8 ) ;
}
static int F_36 ( unsigned long V_30 , unsigned long V_32 ,
unsigned long V_18 , unsigned V_19 )
{
if ( V_32 - V_30 < V_18 )
return 0 ;
if ( V_19 ) {
unsigned V_27 = V_30 % V_19 ;
if ( V_27 )
V_30 += V_19 - V_27 ;
}
return V_32 >= V_30 + V_18 ;
}
struct V_1 * F_24 ( const struct V_2 * V_3 ,
unsigned long V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
bool V_39 )
{
struct V_1 * V_40 ;
struct V_1 * V_41 ;
unsigned long V_23 ;
unsigned long V_24 ;
unsigned long V_42 ;
F_14 ( V_3 -> V_43 ) ;
V_41 = NULL ;
V_42 = ~ 0UL ;
F_19 (entry, mm, adj_start, adj_end) {
if ( V_3 -> V_26 ) {
V_3 -> V_26 ( V_40 , V_20 , & V_23 , & V_24 ) ;
if ( V_24 <= V_23 )
continue;
}
if ( ! F_36 ( V_23 , V_24 , V_18 , V_19 ) )
continue;
if ( ! V_39 )
return V_40 ;
if ( V_40 -> V_18 < V_42 ) {
V_41 = V_40 ;
V_42 = V_40 -> V_18 ;
}
}
return V_41 ;
}
struct V_1 * F_29 ( const struct V_2 * V_3 ,
unsigned long V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
unsigned long V_30 ,
unsigned long V_32 ,
bool V_39 )
{
struct V_1 * V_40 ;
struct V_1 * V_41 ;
unsigned long V_23 ;
unsigned long V_24 ;
unsigned long V_42 ;
F_14 ( V_3 -> V_43 ) ;
V_41 = NULL ;
V_42 = ~ 0UL ;
F_19 (entry, mm, adj_start, adj_end) {
if ( V_23 < V_30 )
V_23 = V_30 ;
if ( V_24 > V_32 )
V_24 = V_32 ;
if ( V_3 -> V_26 ) {
V_3 -> V_26 ( V_40 , V_20 , & V_23 , & V_24 ) ;
if ( V_24 <= V_23 )
continue;
}
if ( ! F_36 ( V_23 , V_24 , V_18 , V_19 ) )
continue;
if ( ! V_39 )
return V_40 ;
if ( V_40 -> V_18 < V_42 ) {
V_41 = V_40 ;
V_42 = V_40 -> V_18 ;
}
}
return V_41 ;
}
void F_37 ( struct V_1 * V_44 , struct V_1 * V_45 )
{
F_38 ( & V_44 -> V_11 , & V_45 -> V_11 ) ;
F_38 ( & V_44 -> V_29 , & V_45 -> V_29 ) ;
V_45 -> V_28 = V_44 -> V_28 ;
V_45 -> V_3 = V_44 -> V_3 ;
V_45 -> V_30 = V_44 -> V_30 ;
V_45 -> V_18 = V_44 -> V_18 ;
V_45 -> V_20 = V_44 -> V_20 ;
V_44 -> V_25 = 0 ;
V_45 -> V_25 = 1 ;
}
void F_39 ( struct V_2 * V_3 ,
unsigned long V_18 ,
unsigned V_19 ,
unsigned long V_20 )
{
V_3 -> V_46 = V_20 ;
V_3 -> V_47 = V_19 ;
V_3 -> V_48 = V_18 ;
V_3 -> V_43 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 0 ;
V_3 -> V_52 = NULL ;
}
void F_40 ( struct V_2 * V_3 ,
unsigned long V_18 ,
unsigned V_19 ,
unsigned long V_20 ,
unsigned long V_30 ,
unsigned long V_32 )
{
V_3 -> V_46 = V_20 ;
V_3 -> V_47 = V_19 ;
V_3 -> V_48 = V_18 ;
V_3 -> V_43 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = 0 ;
V_3 -> V_53 = V_30 ;
V_3 -> V_54 = V_32 ;
V_3 -> V_51 = 1 ;
V_3 -> V_52 = NULL ;
}
int F_41 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_34 ;
unsigned long V_21 , V_22 ;
unsigned long V_23 , V_24 ;
V_3 -> V_43 ++ ;
F_14 ( V_13 -> V_35 ) ;
V_13 -> V_35 = 1 ;
V_34 = F_6 ( V_13 -> V_11 . V_38 , struct V_1 ,
V_11 ) ;
V_13 -> V_55 = V_34 -> V_28 ;
V_34 -> V_28 = 1 ;
F_7 ( & V_13 -> V_11 ) ;
V_13 -> V_11 . V_38 = & V_34 -> V_11 ;
V_13 -> V_11 . V_10 = & V_3 -> V_52 -> V_11 ;
V_3 -> V_52 = V_13 ;
V_23 = V_21 = F_12 ( V_34 ) ;
V_24 = V_22 = F_13 ( V_34 ) ;
if ( V_3 -> V_51 ) {
if ( V_23 < V_3 -> V_53 )
V_23 = V_3 -> V_53 ;
if ( V_24 > V_3 -> V_54 )
V_24 = V_3 -> V_54 ;
}
if ( V_3 -> V_26 )
V_3 -> V_26 ( V_34 , V_3 -> V_46 ,
& V_23 , & V_24 ) ;
if ( F_36 ( V_23 , V_24 ,
V_3 -> V_48 , V_3 -> V_47 ) ) {
V_3 -> V_49 = V_21 ;
V_3 -> V_50 = V_22 ;
return 1 ;
}
return 0 ;
}
int F_42 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_34 ;
V_3 -> V_43 -- ;
F_14 ( ! V_13 -> V_35 ) ;
V_13 -> V_35 = 0 ;
V_34 = F_6 ( V_13 -> V_11 . V_38 , struct V_1 ,
V_11 ) ;
V_34 -> V_28 = V_13 -> V_55 ;
F_16 ( & V_13 -> V_11 , & V_34 -> V_11 ) ;
return ( F_13 ( V_13 ) > V_3 -> V_49 &&
V_13 -> V_30 < V_3 -> V_50 ) ;
}
int F_43 ( struct V_2 * V_3 )
{
struct V_56 * V_57 = & V_3 -> V_58 . V_11 ;
return ( V_57 -> V_10 -> V_10 == V_57 ) ;
}
void F_44 ( struct V_2 * V_3 , unsigned long V_30 , unsigned long V_18 )
{
F_15 ( & V_3 -> V_29 ) ;
F_15 ( & V_3 -> V_9 ) ;
V_3 -> V_12 = 0 ;
V_3 -> V_43 = 0 ;
F_45 ( & V_3 -> V_8 ) ;
F_15 ( & V_3 -> V_58 . V_11 ) ;
F_15 ( & V_3 -> V_58 . V_29 ) ;
V_3 -> V_58 . V_28 = 1 ;
V_3 -> V_58 . V_35 = 0 ;
V_3 -> V_58 . V_36 = 0 ;
V_3 -> V_58 . V_37 = 0 ;
V_3 -> V_58 . V_3 = V_3 ;
V_3 -> V_58 . V_30 = V_30 + V_18 ;
V_3 -> V_58 . V_18 = V_30 - V_3 -> V_58 . V_30 ;
F_10 ( & V_3 -> V_58 . V_29 , & V_3 -> V_29 ) ;
V_3 -> V_26 = NULL ;
}
void F_46 ( struct V_2 * V_3 )
{
struct V_1 * V_40 , * V_10 ;
if ( F_21 ( ! F_5 ( & V_3 -> V_58 . V_11 ) ,
L_2 ) ) {
return;
}
F_4 ( & V_3 -> V_8 ) ;
F_47 (entry, next, &mm->unused_nodes, node_list) {
F_7 ( & V_40 -> V_11 ) ;
F_35 ( V_40 ) ;
-- V_3 -> V_12 ;
}
F_8 ( & V_3 -> V_8 ) ;
F_14 ( V_3 -> V_12 != 0 ) ;
}
static unsigned long F_48 ( struct V_1 * V_40 ,
const char * V_59 )
{
unsigned long V_21 , V_22 , V_60 ;
if ( V_40 -> V_28 ) {
V_21 = F_12 ( V_40 ) ;
V_22 = F_13 ( V_40 ) ;
V_60 = V_22 - V_21 ;
F_49 ( V_61 L_3 ,
V_59 , V_21 , V_22 ,
V_60 ) ;
return V_60 ;
}
return 0 ;
}
void F_50 ( struct V_2 * V_3 , const char * V_59 )
{
struct V_1 * V_40 ;
unsigned long V_62 = 0 , V_63 = 0 , V_64 = 0 ;
V_63 += F_48 ( & V_3 -> V_58 , V_59 ) ;
F_51 (entry, mm) {
F_49 ( V_61 L_4 ,
V_59 , V_40 -> V_30 , V_40 -> V_30 + V_40 -> V_18 ,
V_40 -> V_18 ) ;
V_62 += V_40 -> V_18 ;
V_63 += F_48 ( V_40 , V_59 ) ;
}
V_64 = V_63 + V_62 ;
F_49 ( V_61 L_5 , V_59 , V_64 ,
V_62 , V_63 ) ;
}
static unsigned long F_52 ( struct V_65 * V_66 , struct V_1 * V_40 )
{
unsigned long V_21 , V_22 , V_60 ;
if ( V_40 -> V_28 ) {
V_21 = F_12 ( V_40 ) ;
V_22 = F_13 ( V_40 ) ;
V_60 = V_22 - V_21 ;
F_53 ( V_66 , L_6 ,
V_21 , V_22 , V_60 ) ;
return V_60 ;
}
return 0 ;
}
int F_54 ( struct V_65 * V_66 , struct V_2 * V_3 )
{
struct V_1 * V_40 ;
unsigned long V_62 = 0 , V_63 = 0 , V_64 = 0 ;
V_63 += F_52 ( V_66 , & V_3 -> V_58 ) ;
F_51 (entry, mm) {
F_53 ( V_66 , L_7 ,
V_40 -> V_30 , V_40 -> V_30 + V_40 -> V_18 ,
V_40 -> V_18 ) ;
V_62 += V_40 -> V_18 ;
V_63 += F_52 ( V_66 , V_40 ) ;
}
V_64 = V_63 + V_62 ;
F_53 ( V_66 , L_8 , V_64 , V_62 , V_63 ) ;
return 0 ;
}
