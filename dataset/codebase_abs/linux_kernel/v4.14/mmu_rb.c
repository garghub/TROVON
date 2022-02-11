static unsigned long F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 & V_4 ;
}
static unsigned long F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 -> V_3 + V_2 -> V_5 ) - 1 ;
}
int F_4 ( void * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
struct V_13 * * V_14 )
{
struct V_13 * V_15 ;
int V_16 ;
V_15 = F_5 ( sizeof( * V_15 ) , V_17 ) ;
if ( ! V_15 )
return - V_18 ;
V_15 -> V_19 = V_20 ;
V_15 -> V_10 = V_10 ;
V_15 -> V_6 = V_6 ;
F_6 ( & V_15 -> V_21 . V_22 ) ;
F_7 ( & V_15 -> V_23 ) ;
V_15 -> V_21 . V_10 = & V_24 ;
V_15 -> V_8 = V_8 ;
F_8 ( & V_15 -> V_25 , V_26 ) ;
F_9 ( & V_15 -> V_27 ) ;
F_9 ( & V_15 -> V_28 ) ;
V_15 -> V_12 = V_12 ;
V_16 = F_10 ( & V_15 -> V_21 , V_15 -> V_8 ) ;
if ( V_16 ) {
F_11 ( V_15 ) ;
return V_16 ;
}
* V_14 = V_15 ;
return 0 ;
}
void F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_29 ;
struct V_30 * V_2 ;
unsigned long V_31 ;
struct V_32 V_27 ;
F_13 ( & V_14 -> V_21 , V_14 -> V_8 ) ;
F_14 ( & V_14 -> V_25 ) ;
F_9 ( & V_27 ) ;
F_15 ( & V_14 -> V_23 , V_31 ) ;
while ( ( V_2 = F_16 ( & V_14 -> V_19 ) ) ) {
V_29 = F_17 ( V_2 , struct V_1 , V_2 ) ;
F_18 ( V_2 , & V_14 -> V_19 ) ;
F_19 ( & V_29 -> V_33 , & V_27 ) ;
}
F_20 ( & V_14 -> V_23 , V_31 ) ;
F_21 ( V_14 , & V_27 ) ;
F_11 ( V_14 ) ;
}
int F_22 ( struct V_13 * V_14 ,
struct V_1 * V_34 )
{
struct V_1 * V_2 ;
unsigned long V_31 ;
int V_16 = 0 ;
F_23 ( V_34 -> V_3 , V_34 -> V_5 ) ;
F_15 ( & V_14 -> V_23 , V_31 ) ;
V_2 = F_24 ( V_14 , V_34 -> V_3 , V_34 -> V_5 ) ;
if ( V_2 ) {
V_16 = - V_35 ;
goto V_36;
}
F_25 ( V_34 , & V_14 -> V_19 ) ;
F_26 ( & V_34 -> V_33 , & V_14 -> V_28 ) ;
V_16 = V_14 -> V_10 -> V_37 ( V_14 -> V_6 , V_34 ) ;
if ( V_16 ) {
F_27 ( V_34 , & V_14 -> V_19 ) ;
F_28 ( & V_34 -> V_33 ) ;
}
V_36:
F_20 ( & V_14 -> V_23 , V_31 ) ;
return V_16 ;
}
static struct V_1 * F_24 ( struct V_13 * V_14 ,
unsigned long V_3 ,
unsigned long V_5 )
{
struct V_1 * V_2 = NULL ;
F_29 ( V_3 , V_5 ) ;
if ( ! V_14 -> V_10 -> V_38 ) {
V_2 = F_30 ( & V_14 -> V_19 , V_3 ,
( V_3 + V_5 ) - 1 ) ;
} else {
for ( V_2 = F_30 ( & V_14 -> V_19 , V_3 ,
( V_3 + V_5 ) - 1 ) ;
V_2 ;
V_2 = F_31 ( V_2 , V_3 ,
( V_3 + V_5 ) - 1 ) ) {
if ( V_14 -> V_10 -> V_38 ( V_2 , V_3 , V_5 ) )
return V_2 ;
}
}
return V_2 ;
}
bool F_32 ( struct V_13 * V_14 ,
unsigned long V_3 , unsigned long V_5 ,
struct V_1 * * V_30 )
{
struct V_1 * V_2 ;
unsigned long V_31 ;
bool V_16 = false ;
F_15 ( & V_14 -> V_23 , V_31 ) ;
V_2 = F_24 ( V_14 , V_3 , V_5 ) ;
if ( V_2 ) {
if ( V_2 -> V_3 == V_3 && V_2 -> V_5 == V_5 )
goto V_36;
F_27 ( V_2 , & V_14 -> V_19 ) ;
F_28 ( & V_2 -> V_33 ) ;
V_16 = true ;
}
V_36:
F_20 ( & V_14 -> V_23 , V_31 ) ;
* V_30 = V_2 ;
return V_16 ;
}
void F_33 ( struct V_13 * V_14 , void * V_39 )
{
struct V_1 * V_29 , * V_40 ;
struct V_32 V_27 ;
unsigned long V_31 ;
bool V_41 = false ;
F_9 ( & V_27 ) ;
F_15 ( & V_14 -> V_23 , V_31 ) ;
F_34 (rbnode, ptr, &handler->lru_list,
list) {
if ( V_14 -> V_10 -> V_42 ( V_14 -> V_6 , V_29 , V_39 ,
& V_41 ) ) {
F_27 ( V_29 , & V_14 -> V_19 ) ;
F_19 ( & V_29 -> V_33 , & V_27 ) ;
}
if ( V_41 )
break;
}
F_20 ( & V_14 -> V_23 , V_31 ) ;
while ( ! F_35 ( & V_27 ) ) {
V_29 = F_36 ( & V_27 , struct V_1 , V_33 ) ;
F_28 ( & V_29 -> V_33 ) ;
V_14 -> V_10 -> remove ( V_14 -> V_6 , V_29 ) ;
}
}
void F_37 ( struct V_13 * V_14 ,
struct V_1 * V_2 )
{
unsigned long V_31 ;
F_38 ( V_2 -> V_3 , V_2 -> V_5 ) ;
F_15 ( & V_14 -> V_23 , V_31 ) ;
F_27 ( V_2 , & V_14 -> V_19 ) ;
F_28 ( & V_2 -> V_33 ) ;
F_20 ( & V_14 -> V_23 , V_31 ) ;
V_14 -> V_10 -> remove ( V_14 -> V_6 , V_2 ) ;
}
static inline void F_39 ( struct V_43 * V_21 ,
struct V_7 * V_8 ,
unsigned long V_44 ,
unsigned long V_45 )
{
F_40 ( V_21 , V_8 , V_44 , V_45 ) ;
}
static void F_40 ( struct V_43 * V_21 ,
struct V_7 * V_8 ,
unsigned long V_44 , unsigned long V_45 )
{
struct V_13 * V_14 =
F_41 ( V_21 , struct V_13 , V_21 ) ;
struct V_46 * V_19 = & V_14 -> V_19 ;
struct V_1 * V_2 , * V_40 = NULL ;
unsigned long V_31 ;
bool V_47 = false ;
F_15 ( & V_14 -> V_23 , V_31 ) ;
for ( V_2 = F_30 ( V_19 , V_44 , V_45 - 1 ) ;
V_2 ; V_2 = V_40 ) {
V_40 = F_31 ( V_2 , V_44 , V_45 - 1 ) ;
F_42 ( V_2 -> V_3 , V_2 -> V_5 ) ;
if ( V_14 -> V_10 -> V_48 ( V_14 -> V_6 , V_2 ) ) {
F_27 ( V_2 , V_19 ) ;
F_19 ( & V_2 -> V_33 , & V_14 -> V_27 ) ;
V_47 = true ;
}
}
F_20 ( & V_14 -> V_23 , V_31 ) ;
if ( V_47 )
F_43 ( V_14 -> V_12 , & V_14 -> V_25 ) ;
}
static void F_21 ( struct V_13 * V_14 ,
struct V_32 * V_27 )
{
struct V_1 * V_2 ;
while ( ! F_35 ( V_27 ) ) {
V_2 = F_36 ( V_27 , struct V_1 , V_33 ) ;
F_28 ( & V_2 -> V_33 ) ;
V_14 -> V_10 -> remove ( V_14 -> V_6 , V_2 ) ;
}
}
static void V_26 ( struct V_49 * V_50 )
{
struct V_13 * V_14 = F_41 ( V_50 ,
struct V_13 ,
V_25 ) ;
struct V_32 V_27 ;
unsigned long V_31 ;
F_15 ( & V_14 -> V_23 , V_31 ) ;
F_44 ( & V_14 -> V_27 , & V_27 ) ;
F_20 ( & V_14 -> V_23 , V_31 ) ;
F_21 ( V_14 , & V_27 ) ;
}
