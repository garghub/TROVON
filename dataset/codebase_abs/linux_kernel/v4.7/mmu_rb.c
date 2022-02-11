static unsigned long F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
static unsigned long F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_3 + V_2 -> V_5 ) - 1 ;
}
int F_4 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
struct V_10 * V_11 ;
if ( ! V_9 -> V_12 )
return - V_13 ;
V_11 = F_5 ( sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_11 -> V_7 = V_7 ;
V_11 -> V_9 = V_9 ;
F_6 ( & V_11 -> V_16 . V_17 ) ;
F_7 ( & V_11 -> V_18 ) ;
V_11 -> V_16 . V_9 = & V_19 ;
F_8 ( & V_20 ) ;
F_9 ( & V_11 -> V_21 , & V_22 ) ;
F_10 ( & V_20 ) ;
return F_11 ( & V_11 -> V_16 , V_23 -> V_24 ) ;
}
void F_12 ( struct V_6 * V_7 )
{
struct V_10 * V_25 = F_13 ( V_7 ) ;
unsigned long V_26 ;
if ( ! V_25 )
return;
if ( V_23 -> V_24 )
F_14 ( & V_25 -> V_16 , V_23 -> V_24 ) ;
F_8 ( & V_20 ) ;
F_15 ( & V_25 -> V_21 ) ;
F_10 ( & V_20 ) ;
F_16 () ;
F_17 ( & V_25 -> V_18 , V_26 ) ;
if ( ! F_18 ( V_7 ) ) {
struct V_27 * V_2 ;
struct V_1 * V_28 ;
while ( ( V_2 = F_19 ( V_7 ) ) ) {
V_28 = F_20 ( V_2 , struct V_1 , V_2 ) ;
F_21 ( V_2 , V_7 ) ;
if ( V_25 -> V_9 -> remove )
V_25 -> V_9 -> remove ( V_7 , V_28 , NULL ) ;
}
}
F_22 ( & V_25 -> V_18 , V_26 ) ;
F_23 ( V_25 ) ;
}
int F_24 ( struct V_6 * V_7 , struct V_1 * V_29 )
{
struct V_10 * V_25 = F_13 ( V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_26 ;
int V_30 = 0 ;
if ( ! V_25 )
return - V_13 ;
F_17 ( & V_25 -> V_18 , V_26 ) ;
F_25 ( V_31 , L_1 , V_29 -> V_3 ,
V_29 -> V_5 ) ;
V_2 = F_26 ( V_25 , V_29 -> V_3 , V_29 -> V_5 ) ;
if ( V_2 ) {
V_30 = - V_13 ;
goto V_32;
}
F_27 ( V_29 , V_7 ) ;
if ( V_25 -> V_9 -> V_33 ) {
V_30 = V_25 -> V_9 -> V_33 ( V_7 , V_29 ) ;
if ( V_30 )
F_28 ( V_29 , V_7 ) ;
}
V_32:
F_22 ( & V_25 -> V_18 , V_26 ) ;
return V_30 ;
}
static struct V_1 * F_26 ( struct V_10 * V_25 ,
unsigned long V_3 ,
unsigned long V_5 )
{
struct V_1 * V_2 = NULL ;
F_25 ( V_31 , L_2 , V_3 , V_5 ) ;
if ( ! V_25 -> V_9 -> V_34 ) {
V_2 = F_29 ( V_25 -> V_7 , V_3 ,
( V_3 + V_5 ) - 1 ) ;
} else {
for ( V_2 = F_29 ( V_25 -> V_7 , V_3 ,
( V_3 + V_5 ) - 1 ) ;
V_2 ;
V_2 = F_30 ( V_2 , V_3 ,
( V_3 + V_5 ) - 1 ) ) {
if ( V_25 -> V_9 -> V_34 ( V_2 , V_3 , V_5 ) )
return V_2 ;
}
}
return V_2 ;
}
static void F_31 ( struct V_10 * V_25 ,
struct V_1 * V_2 , struct V_35 * V_24 )
{
unsigned long V_26 ;
F_25 ( V_31 , L_3 , V_2 -> V_3 ,
V_2 -> V_5 ) ;
F_17 ( & V_25 -> V_18 , V_26 ) ;
F_28 ( V_2 , V_25 -> V_7 ) ;
F_22 ( & V_25 -> V_18 , V_26 ) ;
if ( V_25 -> V_9 -> remove )
V_25 -> V_9 -> remove ( V_25 -> V_7 , V_2 , V_24 ) ;
}
struct V_1 * F_32 ( struct V_6 * V_7 , unsigned long V_3 ,
unsigned long V_5 )
{
struct V_10 * V_25 = F_13 ( V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_26 ;
if ( ! V_25 )
return F_33 ( - V_13 ) ;
F_17 ( & V_25 -> V_18 , V_26 ) ;
V_2 = F_26 ( V_25 , V_3 , V_5 ) ;
F_22 ( & V_25 -> V_18 , V_26 ) ;
return V_2 ;
}
struct V_1 * F_34 ( struct V_6 * V_7 ,
unsigned long V_3 , unsigned long V_5 )
{
struct V_10 * V_25 = F_13 ( V_7 ) ;
struct V_1 * V_2 ;
unsigned long V_26 ;
if ( ! V_25 )
return F_33 ( - V_13 ) ;
F_17 ( & V_25 -> V_18 , V_26 ) ;
V_2 = F_26 ( V_25 , V_3 , V_5 ) ;
if ( V_2 )
F_28 ( V_2 , V_25 -> V_7 ) ;
F_22 ( & V_25 -> V_18 , V_26 ) ;
return V_2 ;
}
void F_35 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_10 * V_25 = F_13 ( V_7 ) ;
if ( ! V_25 || ! V_2 )
return;
F_31 ( V_25 , V_2 , NULL ) ;
}
static struct V_10 * F_13 ( struct V_6 * V_7 )
{
struct V_10 * V_25 ;
F_36 () ;
F_37 (handler, &mmu_rb_handlers, list) {
if ( V_25 -> V_7 == V_7 )
goto V_32;
}
V_25 = NULL ;
V_32:
F_38 () ;
return V_25 ;
}
static inline void F_39 ( struct V_36 * V_16 ,
struct V_35 * V_24 , unsigned long V_3 )
{
F_40 ( V_16 , V_24 , V_3 , V_3 + V_37 ) ;
}
static inline void F_41 ( struct V_36 * V_16 ,
struct V_35 * V_24 ,
unsigned long V_38 ,
unsigned long V_39 )
{
F_40 ( V_16 , V_24 , V_38 , V_39 ) ;
}
static void F_40 ( struct V_36 * V_16 ,
struct V_35 * V_24 ,
unsigned long V_38 , unsigned long V_39 )
{
struct V_10 * V_25 =
F_42 ( V_16 , struct V_10 , V_16 ) ;
struct V_6 * V_7 = V_25 -> V_7 ;
struct V_1 * V_2 , * V_40 = NULL ;
unsigned long V_26 ;
F_17 ( & V_25 -> V_18 , V_26 ) ;
for ( V_2 = F_29 ( V_7 , V_38 , V_39 - 1 ) ;
V_2 ; V_2 = V_40 ) {
V_40 = F_30 ( V_2 , V_38 , V_39 - 1 ) ;
F_25 ( V_31 , L_4 ,
V_2 -> V_3 , V_2 -> V_5 ) ;
if ( V_25 -> V_9 -> V_12 ( V_7 , V_2 ) ) {
F_28 ( V_2 , V_7 ) ;
if ( V_25 -> V_9 -> remove )
V_25 -> V_9 -> remove ( V_7 , V_2 , V_24 ) ;
}
}
F_22 ( & V_25 -> V_18 , V_26 ) ;
}
