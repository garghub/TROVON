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
static inline unsigned long F_11 ( struct V_1 * V_17 )
{
return V_17 -> V_18 + V_17 -> V_19 ;
}
static inline unsigned long F_12 ( struct V_1 * V_17 )
{
struct V_1 * V_20 =
F_6 ( V_17 -> V_11 . V_10 , struct V_1 ,
V_11 ) ;
return V_20 -> V_18 ;
}
static void F_13 ( struct V_1 * V_17 ,
struct V_1 * V_13 ,
unsigned long V_19 , unsigned V_21 ,
unsigned long V_22 )
{
struct V_2 * V_3 = V_17 -> V_3 ;
unsigned long V_23 = F_11 ( V_17 ) ;
unsigned long V_24 = F_12 ( V_17 ) ;
unsigned long V_25 = V_23 ;
unsigned long V_26 = V_24 ;
F_14 ( ! V_17 -> V_27 || V_13 -> V_28 ) ;
if ( V_3 -> V_29 )
V_3 -> V_29 ( V_17 , V_22 , & V_25 , & V_26 ) ;
if ( V_21 ) {
unsigned V_30 = V_25 % V_21 ;
if ( V_30 )
V_25 += V_21 - V_30 ;
}
if ( V_25 == V_23 ) {
V_17 -> V_27 = 0 ;
F_7 ( & V_17 -> V_31 ) ;
}
V_13 -> V_18 = V_25 ;
V_13 -> V_19 = V_19 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_22 = V_22 ;
V_13 -> V_28 = 1 ;
F_15 ( & V_13 -> V_31 ) ;
F_16 ( & V_13 -> V_11 , & V_17 -> V_11 ) ;
F_14 ( V_13 -> V_18 + V_13 -> V_19 > V_26 ) ;
V_13 -> V_27 = 0 ;
if ( V_13 -> V_18 + V_13 -> V_19 < V_24 ) {
F_16 ( & V_13 -> V_31 , & V_3 -> V_31 ) ;
V_13 -> V_27 = 1 ;
}
}
struct V_1 * F_17 ( struct V_1 * V_17 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_22 ,
int V_4 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_17 -> V_3 , V_4 ) ;
if ( F_3 ( V_13 == NULL ) )
return NULL ;
F_13 ( V_17 , V_13 , V_19 , V_21 , V_22 ) ;
return V_13 ;
}
int F_18 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_19 , unsigned V_21 )
{
struct V_1 * V_17 ;
V_17 = F_19 ( V_3 , V_19 , V_21 , false ) ;
if ( ! V_17 )
return - V_32 ;
F_13 ( V_17 , V_13 , V_19 , V_21 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_17 ,
struct V_1 * V_13 ,
unsigned long V_19 , unsigned V_21 ,
unsigned long V_22 ,
unsigned long V_18 , unsigned long V_33 )
{
struct V_2 * V_3 = V_17 -> V_3 ;
unsigned long V_23 = F_11 ( V_17 ) ;
unsigned long V_24 = F_12 ( V_17 ) ;
unsigned long V_25 = V_23 ;
unsigned long V_26 = V_24 ;
F_14 ( ! V_17 -> V_27 || V_13 -> V_28 ) ;
if ( V_3 -> V_29 )
V_3 -> V_29 ( V_17 , V_22 , & V_25 , & V_26 ) ;
if ( V_25 < V_18 )
V_25 = V_18 ;
if ( V_21 ) {
unsigned V_30 = V_25 % V_21 ;
if ( V_30 )
V_25 += V_21 - V_30 ;
}
if ( V_25 == V_23 ) {
V_17 -> V_27 = 0 ;
F_7 ( & V_17 -> V_31 ) ;
}
V_13 -> V_18 = V_25 ;
V_13 -> V_19 = V_19 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_22 = V_22 ;
V_13 -> V_28 = 1 ;
F_15 ( & V_13 -> V_31 ) ;
F_16 ( & V_13 -> V_11 , & V_17 -> V_11 ) ;
F_14 ( V_13 -> V_18 + V_13 -> V_19 > V_26 ) ;
F_14 ( V_13 -> V_18 + V_13 -> V_19 > V_33 ) ;
V_13 -> V_27 = 0 ;
if ( V_13 -> V_18 + V_13 -> V_19 < V_24 ) {
F_16 ( & V_13 -> V_31 , & V_3 -> V_31 ) ;
V_13 -> V_27 = 1 ;
}
}
struct V_1 * F_21 ( struct V_1 * V_17 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_22 ,
unsigned long V_18 ,
unsigned long V_33 ,
int V_4 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_17 -> V_3 , V_4 ) ;
if ( F_3 ( V_13 == NULL ) )
return NULL ;
F_20 ( V_17 , V_13 , V_19 , V_21 , V_22 ,
V_18 , V_33 ) ;
return V_13 ;
}
int F_22 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_19 , unsigned V_21 ,
unsigned long V_18 , unsigned long V_33 )
{
struct V_1 * V_17 ;
V_17 = F_23 ( V_3 , V_19 , V_21 ,
V_18 , V_33 , false ) ;
if ( ! V_17 )
return - V_32 ;
F_20 ( V_17 , V_13 , V_19 , V_21 , 0 ,
V_18 , V_33 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_34 ;
F_14 ( V_13 -> V_35 || V_13 -> V_36
|| V_13 -> V_37 ) ;
V_34 =
F_6 ( V_13 -> V_11 . V_38 , struct V_1 , V_11 ) ;
if ( V_13 -> V_27 ) {
F_14 ( F_11 ( V_13 )
== F_12 ( V_13 ) ) ;
F_7 ( & V_13 -> V_31 ) ;
} else
F_14 ( F_11 ( V_13 )
!= F_12 ( V_13 ) ) ;
if ( ! V_34 -> V_27 ) {
V_34 -> V_27 = 1 ;
F_16 ( & V_34 -> V_31 , & V_3 -> V_31 ) ;
} else
F_25 ( & V_34 -> V_31 , & V_3 -> V_31 ) ;
F_7 ( & V_13 -> V_11 ) ;
V_13 -> V_28 = 0 ;
}
void F_26 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
F_24 ( V_13 ) ;
F_4 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_12 < V_14 ) {
F_16 ( & V_13 -> V_11 , & V_3 -> V_9 ) ;
++ V_3 -> V_12 ;
} else
F_27 ( V_13 ) ;
F_8 ( & V_3 -> V_8 ) ;
}
static int F_28 ( unsigned long V_18 , unsigned long V_33 ,
unsigned long V_19 , unsigned V_21 )
{
if ( V_33 - V_18 < V_19 )
return 0 ;
if ( V_21 ) {
unsigned V_30 = V_18 % V_21 ;
if ( V_30 )
V_18 += V_21 - V_30 ;
}
return V_33 >= V_18 + V_19 ;
}
struct V_1 * F_29 ( const struct V_2 * V_3 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_22 ,
bool V_39 )
{
struct V_1 * V_40 ;
struct V_1 * V_41 ;
unsigned long V_42 ;
F_14 ( V_3 -> V_43 ) ;
V_41 = NULL ;
V_42 = ~ 0UL ;
F_30 (entry, &mm->hole_stack, hole_stack) {
unsigned long V_25 = F_11 ( V_40 ) ;
unsigned long V_26 = F_12 ( V_40 ) ;
if ( V_3 -> V_29 ) {
V_3 -> V_29 ( V_40 , V_22 , & V_25 , & V_26 ) ;
if ( V_26 <= V_25 )
continue;
}
F_14 ( ! V_40 -> V_27 ) ;
if ( ! F_28 ( V_25 , V_26 , V_19 , V_21 ) )
continue;
if ( ! V_39 )
return V_40 ;
if ( V_40 -> V_19 < V_42 ) {
V_41 = V_40 ;
V_42 = V_40 -> V_19 ;
}
}
return V_41 ;
}
struct V_1 * F_31 ( const struct V_2 * V_3 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_22 ,
unsigned long V_18 ,
unsigned long V_33 ,
bool V_39 )
{
struct V_1 * V_40 ;
struct V_1 * V_41 ;
unsigned long V_42 ;
F_14 ( V_3 -> V_43 ) ;
V_41 = NULL ;
V_42 = ~ 0UL ;
F_30 (entry, &mm->hole_stack, hole_stack) {
unsigned long V_25 = F_11 ( V_40 ) < V_18 ?
V_18 : F_11 ( V_40 ) ;
unsigned long V_26 = F_12 ( V_40 ) > V_33 ?
V_33 : F_12 ( V_40 ) ;
F_14 ( ! V_40 -> V_27 ) ;
if ( V_3 -> V_29 ) {
V_3 -> V_29 ( V_40 , V_22 , & V_25 , & V_26 ) ;
if ( V_26 <= V_25 )
continue;
}
if ( ! F_28 ( V_25 , V_26 , V_19 , V_21 ) )
continue;
if ( ! V_39 )
return V_40 ;
if ( V_40 -> V_19 < V_42 ) {
V_41 = V_40 ;
V_42 = V_40 -> V_19 ;
}
}
return V_41 ;
}
void F_32 ( struct V_1 * V_44 , struct V_1 * V_45 )
{
F_33 ( & V_44 -> V_11 , & V_45 -> V_11 ) ;
F_33 ( & V_44 -> V_31 , & V_45 -> V_31 ) ;
V_45 -> V_27 = V_44 -> V_27 ;
V_45 -> V_3 = V_44 -> V_3 ;
V_45 -> V_18 = V_44 -> V_18 ;
V_45 -> V_19 = V_44 -> V_19 ;
V_45 -> V_22 = V_44 -> V_22 ;
V_44 -> V_28 = 0 ;
V_45 -> V_28 = 1 ;
}
void F_34 ( struct V_2 * V_3 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_22 )
{
V_3 -> V_46 = V_22 ;
V_3 -> V_47 = V_21 ;
V_3 -> V_48 = V_19 ;
V_3 -> V_43 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = 0 ;
V_3 -> V_51 = 0 ;
V_3 -> V_52 = NULL ;
}
void F_35 ( struct V_2 * V_3 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_22 ,
unsigned long V_18 ,
unsigned long V_33 )
{
V_3 -> V_46 = V_22 ;
V_3 -> V_47 = V_21 ;
V_3 -> V_48 = V_19 ;
V_3 -> V_43 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = 0 ;
V_3 -> V_53 = V_18 ;
V_3 -> V_54 = V_33 ;
V_3 -> V_51 = 1 ;
V_3 -> V_52 = NULL ;
}
int F_36 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_34 ;
unsigned long V_23 , V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
V_3 -> V_43 ++ ;
F_14 ( V_13 -> V_35 ) ;
V_13 -> V_35 = 1 ;
V_34 = F_6 ( V_13 -> V_11 . V_38 , struct V_1 ,
V_11 ) ;
V_13 -> V_55 = V_34 -> V_27 ;
V_34 -> V_27 = 1 ;
F_7 ( & V_13 -> V_11 ) ;
V_13 -> V_11 . V_38 = & V_34 -> V_11 ;
V_13 -> V_11 . V_10 = & V_3 -> V_52 -> V_11 ;
V_3 -> V_52 = V_13 ;
V_23 = F_11 ( V_34 ) ;
V_24 = F_12 ( V_34 ) ;
V_25 = V_23 ;
V_26 = V_24 ;
if ( V_3 -> V_29 )
V_3 -> V_29 ( V_34 , V_3 -> V_46 , & V_25 , & V_26 ) ;
if ( V_3 -> V_51 ) {
if ( V_25 < V_3 -> V_53 )
V_25 = V_3 -> V_53 ;
if ( V_26 > V_3 -> V_54 )
V_26 = V_3 -> V_54 ;
}
if ( F_28 ( V_25 , V_26 ,
V_3 -> V_48 , V_3 -> V_47 ) ) {
V_3 -> V_49 = V_23 ;
V_3 -> V_50 = V_24 ;
return 1 ;
}
return 0 ;
}
int F_37 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_34 ;
V_3 -> V_43 -- ;
F_14 ( ! V_13 -> V_35 ) ;
V_13 -> V_35 = 0 ;
V_34 = F_6 ( V_13 -> V_11 . V_38 , struct V_1 ,
V_11 ) ;
V_34 -> V_27 = V_13 -> V_55 ;
F_15 ( & V_13 -> V_11 ) ;
F_16 ( & V_13 -> V_11 , & V_34 -> V_11 ) ;
if ( V_13 -> V_18 >= V_3 -> V_49 &&
V_13 -> V_18 + V_13 -> V_19
<= V_3 -> V_49 + V_3 -> V_50 ) {
return 1 ;
}
return 0 ;
}
int F_38 ( struct V_2 * V_3 )
{
struct V_56 * V_57 = & V_3 -> V_58 . V_11 ;
return ( V_57 -> V_10 -> V_10 == V_57 ) ;
}
int F_39 ( struct V_2 * V_3 , unsigned long V_18 , unsigned long V_19 )
{
F_15 ( & V_3 -> V_31 ) ;
F_15 ( & V_3 -> V_9 ) ;
V_3 -> V_12 = 0 ;
V_3 -> V_43 = 0 ;
F_40 ( & V_3 -> V_8 ) ;
F_15 ( & V_3 -> V_58 . V_11 ) ;
F_15 ( & V_3 -> V_58 . V_31 ) ;
V_3 -> V_58 . V_27 = 1 ;
V_3 -> V_58 . V_35 = 0 ;
V_3 -> V_58 . V_36 = 0 ;
V_3 -> V_58 . V_37 = 0 ;
V_3 -> V_58 . V_3 = V_3 ;
V_3 -> V_58 . V_18 = V_18 + V_19 ;
V_3 -> V_58 . V_19 = V_18 - V_3 -> V_58 . V_18 ;
F_10 ( & V_3 -> V_58 . V_31 , & V_3 -> V_31 ) ;
V_3 -> V_29 = NULL ;
return 0 ;
}
void F_41 ( struct V_2 * V_3 )
{
struct V_1 * V_40 , * V_10 ;
if ( ! F_5 ( & V_3 -> V_58 . V_11 ) ) {
F_42 ( L_1 ) ;
return;
}
F_4 ( & V_3 -> V_8 ) ;
F_43 (entry, next, &mm->unused_nodes, node_list) {
F_7 ( & V_40 -> V_11 ) ;
F_27 ( V_40 ) ;
-- V_3 -> V_12 ;
}
F_8 ( & V_3 -> V_8 ) ;
F_14 ( V_3 -> V_12 != 0 ) ;
}
void F_44 ( struct V_2 * V_3 , const char * V_59 )
{
struct V_1 * V_40 ;
unsigned long V_60 = 0 , V_61 = 0 , V_62 = 0 ;
unsigned long V_23 , V_24 , V_63 ;
V_23 = F_11 ( & V_3 -> V_58 ) ;
V_24 = F_12 ( & V_3 -> V_58 ) ;
V_63 = V_24 - V_23 ;
if ( V_63 )
F_45 ( V_64 L_2 ,
V_59 , V_23 , V_24 ,
V_63 ) ;
V_61 += V_63 ;
F_46 (entry, mm) {
F_45 ( V_64 L_3 ,
V_59 , V_40 -> V_18 , V_40 -> V_18 + V_40 -> V_19 ,
V_40 -> V_19 ) ;
V_60 += V_40 -> V_19 ;
if ( V_40 -> V_27 ) {
V_23 = F_11 ( V_40 ) ;
V_24 = F_12 ( V_40 ) ;
V_63 = V_24 - V_23 ;
F_45 ( V_64 L_2 ,
V_59 , V_23 , V_24 ,
V_63 ) ;
V_61 += V_63 ;
}
}
V_62 = V_61 + V_60 ;
F_45 ( V_64 L_4 , V_59 , V_62 ,
V_60 , V_61 ) ;
}
int F_47 ( struct V_65 * V_66 , struct V_2 * V_3 )
{
struct V_1 * V_40 ;
unsigned long V_60 = 0 , V_61 = 0 , V_62 = 0 ;
unsigned long V_23 , V_24 , V_63 ;
V_23 = F_11 ( & V_3 -> V_58 ) ;
V_24 = F_12 ( & V_3 -> V_58 ) ;
V_63 = V_24 - V_23 ;
if ( V_63 )
F_48 ( V_66 , L_5 ,
V_23 , V_24 , V_63 ) ;
V_61 += V_63 ;
F_46 (entry, mm) {
F_48 ( V_66 , L_6 ,
V_40 -> V_18 , V_40 -> V_18 + V_40 -> V_19 ,
V_40 -> V_19 ) ;
V_60 += V_40 -> V_19 ;
if ( V_40 -> V_27 ) {
V_23 = F_11 ( V_40 ) ;
V_24 = F_12 ( V_40 ) ;
V_63 = V_24 - V_23 ;
F_48 ( V_66 , L_5 ,
V_23 , V_24 , V_63 ) ;
V_61 += V_63 ;
}
}
V_62 = V_61 + V_60 ;
F_48 ( V_66 , L_7 , V_62 , V_60 , V_61 ) ;
return 0 ;
}
