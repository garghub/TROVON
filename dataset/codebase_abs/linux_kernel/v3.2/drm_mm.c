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
unsigned long V_19 , unsigned V_21 )
{
struct V_2 * V_3 = V_17 -> V_3 ;
unsigned long V_22 = 0 , V_23 = 0 ;
unsigned long V_24 = F_11 ( V_17 ) ;
unsigned long V_25 = F_12 ( V_17 ) ;
F_14 ( ! V_17 -> V_26 || V_13 -> V_27 ) ;
if ( V_21 )
V_22 = V_24 % V_21 ;
if ( ! V_22 ) {
V_17 -> V_26 = 0 ;
F_15 ( & V_17 -> V_28 ) ;
} else
V_23 = V_21 - V_22 ;
V_13 -> V_18 = V_24 + V_23 ;
V_13 -> V_19 = V_19 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_27 = 1 ;
F_16 ( & V_13 -> V_28 ) ;
F_17 ( & V_13 -> V_11 , & V_17 -> V_11 ) ;
F_14 ( V_13 -> V_18 + V_13 -> V_19 > V_25 ) ;
if ( V_13 -> V_18 + V_13 -> V_19 < V_25 ) {
F_17 ( & V_13 -> V_28 , & V_3 -> V_28 ) ;
V_13 -> V_26 = 1 ;
} else {
V_13 -> V_26 = 0 ;
}
}
struct V_1 * F_18 ( struct V_1 * V_17 ,
unsigned long V_19 ,
unsigned V_21 ,
int V_4 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_17 -> V_3 , V_4 ) ;
if ( F_3 ( V_13 == NULL ) )
return NULL ;
F_13 ( V_17 , V_13 , V_19 , V_21 ) ;
return V_13 ;
}
int F_19 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_19 , unsigned V_21 )
{
struct V_1 * V_17 ;
V_17 = F_20 ( V_3 , V_19 , V_21 , 0 ) ;
if ( ! V_17 )
return - V_29 ;
F_13 ( V_17 , V_13 , V_19 , V_21 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_17 ,
struct V_1 * V_13 ,
unsigned long V_19 , unsigned V_21 ,
unsigned long V_18 , unsigned long V_30 )
{
struct V_2 * V_3 = V_17 -> V_3 ;
unsigned long V_22 = 0 , V_23 = 0 ;
unsigned long V_24 = F_11 ( V_17 ) ;
unsigned long V_25 = F_12 ( V_17 ) ;
F_14 ( ! V_17 -> V_26 || V_13 -> V_27 ) ;
if ( V_24 < V_18 )
V_23 += V_18 - V_24 ;
if ( V_21 )
V_22 = ( V_24 + V_23 ) % V_21 ;
if ( V_22 )
V_23 += V_21 - V_22 ;
if ( ! V_23 ) {
V_17 -> V_26 = 0 ;
F_15 ( & V_17 -> V_28 ) ;
}
V_13 -> V_18 = V_24 + V_23 ;
V_13 -> V_19 = V_19 ;
V_13 -> V_3 = V_3 ;
V_13 -> V_27 = 1 ;
F_16 ( & V_13 -> V_28 ) ;
F_17 ( & V_13 -> V_11 , & V_17 -> V_11 ) ;
F_14 ( V_13 -> V_18 + V_13 -> V_19 > V_25 ) ;
F_14 ( V_13 -> V_18 + V_13 -> V_19 > V_30 ) ;
if ( V_13 -> V_18 + V_13 -> V_19 < V_25 ) {
F_17 ( & V_13 -> V_28 , & V_3 -> V_28 ) ;
V_13 -> V_26 = 1 ;
} else {
V_13 -> V_26 = 0 ;
}
}
struct V_1 * F_22 ( struct V_1 * V_17 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_18 ,
unsigned long V_30 ,
int V_4 )
{
struct V_1 * V_13 ;
V_13 = F_1 ( V_17 -> V_3 , V_4 ) ;
if ( F_3 ( V_13 == NULL ) )
return NULL ;
F_21 ( V_17 , V_13 , V_19 , V_21 ,
V_18 , V_30 ) ;
return V_13 ;
}
int F_23 ( struct V_2 * V_3 , struct V_1 * V_13 ,
unsigned long V_19 , unsigned V_21 ,
unsigned long V_18 , unsigned long V_30 )
{
struct V_1 * V_17 ;
V_17 = F_24 ( V_3 , V_19 , V_21 ,
V_18 , V_30 , 0 ) ;
if ( ! V_17 )
return - V_29 ;
F_21 ( V_17 , V_13 , V_19 , V_21 ,
V_18 , V_30 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_31 ;
F_14 ( V_13 -> V_32 || V_13 -> V_33
|| V_13 -> V_34 ) ;
V_31 =
F_6 ( V_13 -> V_11 . V_35 , struct V_1 , V_11 ) ;
if ( V_13 -> V_26 ) {
F_14 ( F_11 ( V_13 )
== F_12 ( V_13 ) ) ;
F_7 ( & V_13 -> V_28 ) ;
} else
F_14 ( F_11 ( V_13 )
!= F_12 ( V_13 ) ) ;
if ( ! V_31 -> V_26 ) {
V_31 -> V_26 = 1 ;
F_17 ( & V_31 -> V_28 , & V_3 -> V_28 ) ;
} else
F_26 ( & V_31 -> V_28 , & V_3 -> V_28 ) ;
F_7 ( & V_13 -> V_11 ) ;
V_13 -> V_27 = 0 ;
}
void F_27 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
F_25 ( V_13 ) ;
F_4 ( & V_3 -> V_8 ) ;
if ( V_3 -> V_12 < V_14 ) {
F_17 ( & V_13 -> V_11 , & V_3 -> V_9 ) ;
++ V_3 -> V_12 ;
} else
F_28 ( V_13 ) ;
F_8 ( & V_3 -> V_8 ) ;
}
static int F_29 ( unsigned long V_18 , unsigned long V_30 ,
unsigned long V_19 , unsigned V_21 )
{
unsigned V_23 = 0 ;
if ( V_30 - V_18 < V_19 )
return 0 ;
if ( V_21 ) {
unsigned V_22 = V_18 % V_21 ;
if ( V_22 )
V_23 = V_21 - V_22 ;
}
if ( V_30 >= V_18 + V_19 + V_23 ) {
return 1 ;
}
return 0 ;
}
struct V_1 * F_20 ( const struct V_2 * V_3 ,
unsigned long V_19 ,
unsigned V_21 , int V_36 )
{
struct V_1 * V_37 ;
struct V_1 * V_38 ;
unsigned long V_39 ;
F_14 ( V_3 -> V_40 ) ;
V_38 = NULL ;
V_39 = ~ 0UL ;
F_30 (entry, &mm->hole_stack, hole_stack) {
F_14 ( ! V_37 -> V_26 ) ;
if ( ! F_29 ( F_11 ( V_37 ) ,
F_12 ( V_37 ) ,
V_19 , V_21 ) )
continue;
if ( ! V_36 )
return V_37 ;
if ( V_37 -> V_19 < V_39 ) {
V_38 = V_37 ;
V_39 = V_37 -> V_19 ;
}
}
return V_38 ;
}
struct V_1 * F_24 ( const struct V_2 * V_3 ,
unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_18 ,
unsigned long V_30 ,
int V_36 )
{
struct V_1 * V_37 ;
struct V_1 * V_38 ;
unsigned long V_39 ;
F_14 ( V_3 -> V_40 ) ;
V_38 = NULL ;
V_39 = ~ 0UL ;
F_30 (entry, &mm->hole_stack, hole_stack) {
unsigned long V_41 = F_11 ( V_37 ) < V_18 ?
V_18 : F_11 ( V_37 ) ;
unsigned long V_42 = F_12 ( V_37 ) > V_30 ?
V_30 : F_12 ( V_37 ) ;
F_14 ( ! V_37 -> V_26 ) ;
if ( ! F_29 ( V_41 , V_42 , V_19 , V_21 ) )
continue;
if ( ! V_36 )
return V_37 ;
if ( V_37 -> V_19 < V_39 ) {
V_38 = V_37 ;
V_39 = V_37 -> V_19 ;
}
}
return V_38 ;
}
void F_31 ( struct V_1 * V_43 , struct V_1 * V_44 )
{
F_32 ( & V_43 -> V_11 , & V_44 -> V_11 ) ;
F_32 ( & V_43 -> V_28 , & V_44 -> V_28 ) ;
V_44 -> V_26 = V_43 -> V_26 ;
V_44 -> V_3 = V_43 -> V_3 ;
V_44 -> V_18 = V_43 -> V_18 ;
V_44 -> V_19 = V_43 -> V_19 ;
V_43 -> V_27 = 0 ;
V_44 -> V_27 = 1 ;
}
void F_33 ( struct V_2 * V_3 , unsigned long V_19 ,
unsigned V_21 )
{
V_3 -> V_45 = V_21 ;
V_3 -> V_46 = V_19 ;
V_3 -> V_40 = 0 ;
V_3 -> V_47 = 0 ;
V_3 -> V_48 = 0 ;
V_3 -> V_49 = 0 ;
V_3 -> V_50 = NULL ;
}
void F_34 ( struct V_2 * V_3 , unsigned long V_19 ,
unsigned V_21 ,
unsigned long V_18 ,
unsigned long V_30 )
{
V_3 -> V_45 = V_21 ;
V_3 -> V_46 = V_19 ;
V_3 -> V_40 = 0 ;
V_3 -> V_47 = 0 ;
V_3 -> V_48 = 0 ;
V_3 -> V_51 = V_18 ;
V_3 -> V_52 = V_30 ;
V_3 -> V_49 = 1 ;
V_3 -> V_50 = NULL ;
}
int F_35 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_31 ;
unsigned long V_24 , V_25 ;
unsigned long V_41 ;
unsigned long V_42 ;
V_3 -> V_40 ++ ;
F_14 ( V_13 -> V_32 ) ;
V_13 -> V_32 = 1 ;
V_31 = F_6 ( V_13 -> V_11 . V_35 , struct V_1 ,
V_11 ) ;
V_13 -> V_53 = V_31 -> V_26 ;
V_31 -> V_26 = 1 ;
F_7 ( & V_13 -> V_11 ) ;
V_13 -> V_11 . V_35 = & V_31 -> V_11 ;
V_13 -> V_11 . V_10 = & V_3 -> V_50 -> V_11 ;
V_3 -> V_50 = V_13 ;
V_24 = F_11 ( V_31 ) ;
V_25 = F_12 ( V_31 ) ;
if ( V_3 -> V_49 ) {
V_41 = V_24 < V_3 -> V_51 ?
V_3 -> V_51 : V_24 ;
V_42 = V_25 > V_3 -> V_52 ?
V_3 -> V_52 : V_25 ;
} else {
V_41 = V_24 ;
V_42 = V_25 ;
}
if ( F_29 ( V_41 , V_42 ,
V_3 -> V_46 , V_3 -> V_45 ) ) {
V_3 -> V_47 = V_24 ;
V_3 -> V_48 = V_25 ;
return 1 ;
}
return 0 ;
}
int F_36 ( struct V_1 * V_13 )
{
struct V_2 * V_3 = V_13 -> V_3 ;
struct V_1 * V_31 ;
V_3 -> V_40 -- ;
F_14 ( ! V_13 -> V_32 ) ;
V_13 -> V_32 = 0 ;
V_31 = F_6 ( V_13 -> V_11 . V_35 , struct V_1 ,
V_11 ) ;
V_31 -> V_26 = V_13 -> V_53 ;
F_16 ( & V_13 -> V_11 ) ;
F_17 ( & V_13 -> V_11 , & V_31 -> V_11 ) ;
if ( V_13 -> V_18 >= V_3 -> V_47 &&
V_13 -> V_18 + V_13 -> V_19
<= V_3 -> V_47 + V_3 -> V_48 ) {
return 1 ;
}
return 0 ;
}
int F_37 ( struct V_2 * V_3 )
{
struct V_54 * V_55 = & V_3 -> V_56 . V_11 ;
return ( V_55 -> V_10 -> V_10 == V_55 ) ;
}
int F_38 ( struct V_2 * V_3 , unsigned long V_18 , unsigned long V_19 )
{
F_16 ( & V_3 -> V_28 ) ;
F_16 ( & V_3 -> V_9 ) ;
V_3 -> V_12 = 0 ;
V_3 -> V_40 = 0 ;
F_39 ( & V_3 -> V_8 ) ;
F_16 ( & V_3 -> V_56 . V_11 ) ;
F_16 ( & V_3 -> V_56 . V_28 ) ;
V_3 -> V_56 . V_26 = 1 ;
V_3 -> V_56 . V_32 = 0 ;
V_3 -> V_56 . V_33 = 0 ;
V_3 -> V_56 . V_34 = 0 ;
V_3 -> V_56 . V_3 = V_3 ;
V_3 -> V_56 . V_18 = V_18 + V_19 ;
V_3 -> V_56 . V_19 = V_18 - V_3 -> V_56 . V_18 ;
F_10 ( & V_3 -> V_56 . V_28 , & V_3 -> V_28 ) ;
return 0 ;
}
void F_40 ( struct V_2 * V_3 )
{
struct V_1 * V_37 , * V_10 ;
if ( ! F_5 ( & V_3 -> V_56 . V_11 ) ) {
F_41 ( L_1 ) ;
return;
}
F_4 ( & V_3 -> V_8 ) ;
F_42 (entry, next, &mm->unused_nodes, node_list) {
F_7 ( & V_37 -> V_11 ) ;
F_28 ( V_37 ) ;
-- V_3 -> V_12 ;
}
F_8 ( & V_3 -> V_8 ) ;
F_14 ( V_3 -> V_12 != 0 ) ;
}
void F_43 ( struct V_2 * V_3 , const char * V_57 )
{
struct V_1 * V_37 ;
unsigned long V_58 = 0 , V_59 = 0 , V_60 = 0 ;
unsigned long V_24 , V_25 , V_61 ;
V_24 = F_11 ( & V_3 -> V_56 ) ;
V_25 = F_12 ( & V_3 -> V_56 ) ;
V_61 = V_25 - V_24 ;
if ( V_61 )
F_44 ( V_62 L_2 ,
V_57 , V_24 , V_25 ,
V_61 ) ;
V_59 += V_61 ;
F_45 (entry, mm) {
F_44 ( V_62 L_3 ,
V_57 , V_37 -> V_18 , V_37 -> V_18 + V_37 -> V_19 ,
V_37 -> V_19 ) ;
V_58 += V_37 -> V_19 ;
if ( V_37 -> V_26 ) {
V_24 = F_11 ( V_37 ) ;
V_25 = F_12 ( V_37 ) ;
V_61 = V_25 - V_24 ;
F_44 ( V_62 L_2 ,
V_57 , V_24 , V_25 ,
V_61 ) ;
V_59 += V_61 ;
}
}
V_60 = V_59 + V_58 ;
F_44 ( V_62 L_4 , V_57 , V_60 ,
V_58 , V_59 ) ;
}
int F_46 ( struct V_63 * V_64 , struct V_2 * V_3 )
{
struct V_1 * V_37 ;
unsigned long V_58 = 0 , V_59 = 0 , V_60 = 0 ;
unsigned long V_24 , V_25 , V_61 ;
V_24 = F_11 ( & V_3 -> V_56 ) ;
V_25 = F_12 ( & V_3 -> V_56 ) ;
V_61 = V_25 - V_24 ;
if ( V_61 )
F_47 ( V_64 , L_5 ,
V_24 , V_25 , V_61 ) ;
V_59 += V_61 ;
F_45 (entry, mm) {
F_47 ( V_64 , L_6 ,
V_37 -> V_18 , V_37 -> V_18 + V_37 -> V_19 ,
V_37 -> V_19 ) ;
V_58 += V_37 -> V_19 ;
if ( V_37 -> V_26 ) {
V_24 = F_11 ( V_37 ) ;
V_25 = F_12 ( V_37 ) ;
V_61 = V_25 - V_24 ;
F_47 ( V_64 , L_5 ,
V_24 , V_25 , V_61 ) ;
V_59 += V_61 ;
}
}
V_60 = V_59 + V_58 ;
F_47 ( V_64 , L_7 , V_60 , V_58 , V_59 ) ;
return 0 ;
}
