static unsigned long F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
static unsigned long F_2 ( struct V_1 * V_2 )
{
return F_3 ( ( V_2 -> V_3 & V_4 ) + V_2 -> V_5 ) - 1 ;
}
int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
unsigned long V_12 ;
if ( ! V_9 -> V_13 )
return - V_14 ;
V_11 = F_5 ( sizeof( * V_11 ) , V_15 ) ;
if ( ! V_11 )
return - V_16 ;
V_11 -> V_7 = V_7 ;
V_11 -> V_9 = V_9 ;
F_6 ( & V_11 -> V_17 . V_18 ) ;
F_7 ( & V_11 -> V_19 ) ;
V_11 -> V_17 . V_9 = & V_20 ;
F_8 ( & V_21 , V_12 ) ;
F_9 ( & V_11 -> V_22 , & V_23 ) ;
F_10 ( & V_21 , V_12 ) ;
return F_11 ( & V_11 -> V_17 , V_24 -> V_25 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
struct V_10 * V_26 = F_13 ( V_7 ) ;
unsigned long V_12 ;
if ( ! V_26 )
return;
F_8 ( & V_21 , V_12 ) ;
F_14 ( & V_26 -> V_22 ) ;
F_10 ( & V_21 , V_12 ) ;
if ( ! F_15 ( V_7 ) ) {
struct V_27 * V_2 ;
struct V_1 * V_28 ;
while ( ( V_2 = F_16 ( V_7 ) ) ) {
V_28 = F_17 ( V_2 , struct V_1 , V_2 ) ;
F_18 ( V_2 , V_7 ) ;
if ( V_26 -> V_9 -> remove )
V_26 -> V_9 -> remove ( V_7 , V_28 , NULL ) ;
}
}
if ( V_24 -> V_25 )
F_19 ( & V_26 -> V_17 , V_24 -> V_25 ) ;
F_20 ( V_26 ) ;
}
int F_21 ( struct V_6 * V_7 , struct V_1 * V_29 )
{
struct V_10 * V_26 = F_13 ( V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_12 ;
int V_30 = 0 ;
if ( ! V_26 )
return - V_14 ;
F_8 ( & V_26 -> V_19 , V_12 ) ;
F_22 ( V_31 , L_1 , V_29 -> V_3 ,
V_29 -> V_5 ) ;
V_2 = F_23 ( V_26 , V_29 -> V_3 , V_29 -> V_5 ) ;
if ( V_2 ) {
V_30 = - V_14 ;
goto V_32;
}
F_24 ( V_29 , V_7 ) ;
if ( V_26 -> V_9 -> V_33 ) {
V_30 = V_26 -> V_9 -> V_33 ( V_7 , V_29 ) ;
if ( V_30 )
F_25 ( V_29 , V_7 ) ;
}
V_32:
F_10 ( & V_26 -> V_19 , V_12 ) ;
return V_30 ;
}
static struct V_1 * F_23 ( struct V_10 * V_26 ,
unsigned long V_3 ,
unsigned long V_5 )
{
struct V_1 * V_2 = NULL ;
F_22 ( V_31 , L_2 , V_3 , V_5 ) ;
if ( ! V_26 -> V_9 -> V_34 ) {
V_2 = F_26 ( V_26 -> V_7 , V_3 ,
( V_3 + V_5 ) - 1 ) ;
} else {
for ( V_2 = F_26 ( V_26 -> V_7 , V_3 ,
( V_3 + V_5 ) - 1 ) ;
V_2 ;
V_2 = F_27 ( V_2 , V_3 ,
( V_3 + V_5 ) - 1 ) ) {
if ( V_26 -> V_9 -> V_34 ( V_2 , V_3 , V_5 ) )
return V_2 ;
}
}
return V_2 ;
}
static void F_28 ( struct V_10 * V_26 ,
struct V_1 * V_2 , struct V_35 * V_25 )
{
unsigned long V_12 ;
F_22 ( V_31 , L_3 , V_2 -> V_3 ,
V_2 -> V_5 ) ;
F_8 ( & V_26 -> V_19 , V_12 ) ;
F_25 ( V_2 , V_26 -> V_7 ) ;
F_10 ( & V_26 -> V_19 , V_12 ) ;
if ( V_26 -> V_9 -> remove )
V_26 -> V_9 -> remove ( V_26 -> V_7 , V_2 , V_25 ) ;
}
struct V_1 * F_29 ( struct V_6 * V_7 , unsigned long V_3 ,
unsigned long V_5 )
{
struct V_10 * V_26 = F_13 ( V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_12 ;
if ( ! V_26 )
return F_30 ( - V_14 ) ;
F_8 ( & V_26 -> V_19 , V_12 ) ;
V_2 = F_23 ( V_26 , V_3 , V_5 ) ;
F_10 ( & V_26 -> V_19 , V_12 ) ;
return V_2 ;
}
void F_31 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_10 * V_26 = F_13 ( V_7 ) ;
if ( ! V_26 || ! V_2 )
return;
F_28 ( V_26 , V_2 , NULL ) ;
}
static struct V_10 * F_13 ( struct V_6 * V_7 )
{
struct V_10 * V_26 ;
unsigned long V_12 ;
F_8 ( & V_21 , V_12 ) ;
F_32 (handler, &mmu_rb_handlers, list) {
if ( V_26 -> V_7 == V_7 )
goto V_32;
}
V_26 = NULL ;
V_32:
F_10 ( & V_21 , V_12 ) ;
return V_26 ;
}
static inline void F_33 ( struct V_36 * V_17 ,
struct V_35 * V_25 , unsigned long V_3 )
{
F_34 ( V_17 , V_25 , V_3 , V_3 + V_37 ) ;
}
static inline void F_35 ( struct V_36 * V_17 ,
struct V_35 * V_25 ,
unsigned long V_38 ,
unsigned long V_39 )
{
F_34 ( V_17 , V_25 , V_38 , V_39 ) ;
}
static void F_34 ( struct V_36 * V_17 ,
struct V_35 * V_25 ,
unsigned long V_38 , unsigned long V_39 )
{
struct V_10 * V_26 =
F_36 ( V_17 , struct V_10 , V_17 ) ;
struct V_6 * V_7 = V_26 -> V_7 ;
struct V_1 * V_2 , * V_40 = NULL ;
unsigned long V_12 ;
F_8 ( & V_26 -> V_19 , V_12 ) ;
for ( V_2 = F_26 ( V_7 , V_38 , V_39 - 1 ) ;
V_2 ; V_2 = V_40 ) {
V_40 = F_27 ( V_2 , V_38 , V_39 - 1 ) ;
F_22 ( V_31 , L_4 ,
V_2 -> V_3 , V_2 -> V_5 ) ;
if ( V_26 -> V_9 -> V_13 ( V_7 , V_2 ) ) {
F_10 ( & V_26 -> V_19 , V_12 ) ;
F_28 ( V_26 , V_2 , V_25 ) ;
F_8 ( & V_26 -> V_19 , V_12 ) ;
}
}
F_10 ( & V_26 -> V_19 , V_12 ) ;
}
