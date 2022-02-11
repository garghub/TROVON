int F_1 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
int V_8 = 0 ;
F_2 ( & V_2 -> V_9 ) ;
if ( ! V_5 -> V_10 ) {
V_8 = F_3 ( & V_5 -> V_11 -> V_12 , V_5 ,
1 , 0 , V_13 ) ;
if ( V_8 >= 0 )
V_5 -> V_10 = V_8 ;
}
V_7 -> V_10 = V_5 -> V_10 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( L_1 , V_7 -> V_10 ) ;
return V_8 < 0 ? V_8 : 0 ;
}
int F_6 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_4 * V_14 ;
F_5 ( L_1 , V_7 -> V_10 ) ;
F_2 ( & V_2 -> V_9 ) ;
V_14 = F_7 ( & V_5 -> V_11 -> V_12 , V_7 -> V_10 ) ;
if ( V_14 ) {
V_14 -> V_15 = 1 ;
F_8 ( & V_5 -> V_11 -> V_12 , NULL , V_7 -> V_10 ) ;
}
F_4 ( & V_2 -> V_9 ) ;
return V_14 ? 0 : - V_16 ;
}
static struct V_17 * F_9 ( struct V_1 * V_2 )
{
struct V_17 * V_11 ;
V_11 = F_10 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
return NULL ;
F_11 ( & V_11 -> V_18 ) ;
F_12 ( & V_11 -> V_19 . V_20 ) ;
F_13 ( & V_11 -> V_19 . V_21 ) ;
F_14 ( & V_11 -> V_12 ) ;
V_11 -> V_2 = V_2 ;
return V_11 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_4 * V_22 ,
bool V_23 )
{
int V_8 = 0 ;
V_2 -> V_11 = F_16 ( V_22 -> V_11 ) ;
if ( V_2 -> V_24 -> V_25 ) {
V_8 = V_2 -> V_24 -> V_25 ( V_2 , V_22 , V_23 ) ;
if ( F_17 ( V_8 != 0 ) ) {
F_18 ( & V_2 -> V_11 ) ;
}
}
return V_8 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_4 * V_22 )
{
struct V_17 * V_26 ;
int V_8 ;
F_20 ( & V_2 -> V_9 ) ;
V_26 = V_22 -> V_11 ;
V_22 -> V_11 = F_9 ( V_2 ) ;
if ( ! V_22 -> V_11 ) {
V_22 -> V_11 = V_26 ;
return - V_27 ;
}
if ( V_2 -> V_24 -> V_28 ) {
V_8 = V_2 -> V_24 -> V_28 ( V_2 , V_22 -> V_11 ) ;
if ( V_8 )
goto V_29;
}
V_22 -> V_30 = 1 ;
V_22 -> V_15 = 1 ;
V_8 = F_15 ( V_2 , V_22 , true ) ;
if ( V_8 )
goto V_29;
if ( V_26 )
F_18 ( & V_26 ) ;
return 0 ;
V_29:
F_18 ( & V_22 -> V_11 ) ;
V_22 -> V_11 = V_26 ;
return V_8 ;
}
int F_21 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
int V_8 = 0 ;
F_2 ( & V_2 -> V_9 ) ;
if ( F_22 ( V_5 ) )
goto V_31;
if ( V_2 -> V_11 ) {
V_8 = - V_16 ;
goto V_31;
}
if ( ! V_5 -> V_11 ) {
V_8 = - V_16 ;
goto V_31;
}
if ( ! V_5 -> V_30 ) {
V_8 = F_19 ( V_2 , V_5 ) ;
goto V_31;
}
V_8 = F_15 ( V_2 , V_5 , false ) ;
V_31:
F_4 ( & V_2 -> V_9 ) ;
return V_8 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_4 * V_22 )
{
if ( V_2 -> V_24 -> V_32 )
V_2 -> V_24 -> V_32 ( V_2 , V_22 ) ;
F_18 ( & V_2 -> V_11 ) ;
}
int F_24 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
int V_8 = - V_16 ;
F_2 ( & V_2 -> V_9 ) ;
if ( ! F_22 ( V_5 ) )
goto V_31;
if ( ! V_2 -> V_11 )
goto V_31;
V_8 = 0 ;
F_23 ( V_2 , V_5 ) ;
V_31:
F_4 ( & V_2 -> V_9 ) ;
return V_8 ;
}
int F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_33 -> V_2 ;
int V_8 = 0 ;
F_2 ( & V_2 -> V_9 ) ;
if ( ! V_2 -> V_11 )
V_8 = F_19 ( V_2 , V_5 ) ;
else
V_5 -> V_11 = F_16 ( V_2 -> V_11 ) ;
F_4 ( & V_2 -> V_9 ) ;
return V_8 ;
}
void F_26 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_33 -> V_2 ;
struct V_17 * V_11 = V_5 -> V_11 ;
F_2 ( & V_2 -> V_9 ) ;
if ( V_5 -> V_10 )
F_27 ( & V_5 -> V_11 -> V_12 , V_5 -> V_10 ) ;
if ( ! F_22 ( V_5 ) )
goto V_34;
if ( ! F_28 ( V_2 , V_35 ) ) {
F_2 ( & V_2 -> V_36 ) ;
if ( V_11 -> V_19 . V_37 ) {
if ( V_2 -> V_38 . V_19 == V_11 -> V_19 . V_37 )
V_2 -> V_38 . V_19 = NULL ;
V_11 -> V_19 . V_37 = NULL ;
V_11 -> V_19 . V_5 = NULL ;
F_29 ( & V_11 -> V_19 . V_21 ) ;
}
F_4 ( & V_2 -> V_36 ) ;
}
if ( V_2 -> V_11 == V_5 -> V_11 )
F_23 ( V_2 , V_5 ) ;
V_34:
if ( V_5 -> V_11 )
F_18 ( & V_5 -> V_11 ) ;
F_4 ( & V_2 -> V_9 ) ;
}
bool F_22 ( struct V_4 * V_22 )
{
return V_22 -> V_30 && V_22 -> V_11 == V_22 -> V_33 -> V_2 -> V_11 ;
}
struct V_17 * F_16 ( struct V_17 * V_11 )
{
F_30 ( & V_11 -> V_18 ) ;
return V_11 ;
}
static void F_31 ( struct V_39 * V_39 )
{
struct V_17 * V_11 = F_32 ( V_39 , struct V_17 , V_18 ) ;
struct V_1 * V_2 = V_11 -> V_2 ;
if ( V_2 -> V_24 -> V_40 )
V_2 -> V_24 -> V_40 ( V_2 , V_11 ) ;
F_33 ( V_2 , V_11 ) ;
F_34 ( & V_11 -> V_12 ) ;
F_35 ( V_11 -> V_41 ) ;
F_35 ( V_11 ) ;
}
void F_18 ( struct V_17 * * V_11 )
{
F_36 ( & ( * V_11 ) -> V_18 , F_31 ) ;
* V_11 = NULL ;
}
