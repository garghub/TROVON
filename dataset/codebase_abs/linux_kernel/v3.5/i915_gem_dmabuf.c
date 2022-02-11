static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_12 . V_11 ;
int V_13 = V_7 -> V_12 . V_14 / V_15 ;
struct V_1 * V_16 = NULL ;
int V_17 ;
int V_18 ;
V_17 = F_2 ( V_11 ) ;
if ( V_17 )
return F_3 ( V_17 ) ;
if ( ! V_7 -> V_19 ) {
V_17 = F_4 ( V_7 , V_20 | V_21 ) ;
if ( V_17 )
goto V_22;
}
V_16 = F_5 ( V_7 -> V_19 , V_13 ) ;
V_18 = F_6 ( V_3 -> V_11 , V_16 -> V_23 , V_16 -> V_18 , V_5 ) ;
V_22:
F_7 ( & V_11 -> V_24 ) ;
return V_16 ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * V_16 , enum V_4 V_5 )
{
F_9 ( V_3 -> V_11 , V_16 -> V_23 , V_16 -> V_18 , V_5 ) ;
F_10 ( V_16 ) ;
F_11 ( V_16 ) ;
}
static void F_12 ( struct V_25 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_9 ;
if ( V_7 -> V_12 . V_26 == V_25 ) {
V_7 -> V_12 . V_26 = NULL ;
F_13 ( & V_7 -> V_12 ) ;
}
}
static void * F_14 ( struct V_25 * V_25 )
{
struct V_6 * V_7 = V_25 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_12 . V_11 ;
int V_17 ;
V_17 = F_2 ( V_11 ) ;
if ( V_17 )
return F_3 ( V_17 ) ;
if ( V_7 -> V_27 ) {
V_7 -> V_28 ++ ;
goto V_29;
}
if ( ! V_7 -> V_19 ) {
V_17 = F_4 ( V_7 , V_20 | V_21 ) ;
if ( V_17 ) {
F_7 ( & V_11 -> V_24 ) ;
return F_3 ( V_17 ) ;
}
}
V_7 -> V_27 = F_15 ( V_7 -> V_19 , V_7 -> V_12 . V_14 / V_15 , 0 , V_30 ) ;
if ( ! V_7 -> V_27 ) {
F_16 ( L_1 ) ;
goto V_29;
}
V_7 -> V_28 = 1 ;
V_29:
F_7 ( & V_11 -> V_24 ) ;
return V_7 -> V_27 ;
}
static void F_17 ( struct V_25 * V_25 , void * V_31 )
{
struct V_6 * V_7 = V_25 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_12 . V_11 ;
int V_17 ;
V_17 = F_2 ( V_11 ) ;
if ( V_17 )
return;
-- V_7 -> V_28 ;
if ( V_7 -> V_28 == 0 ) {
F_18 ( V_7 -> V_27 ) ;
V_7 -> V_27 = NULL ;
}
F_7 ( & V_11 -> V_24 ) ;
}
static void * F_19 ( struct V_25 * V_25 , unsigned long V_32 )
{
return NULL ;
}
static void F_20 ( struct V_25 * V_25 , unsigned long V_32 , void * V_33 )
{
}
static void * F_21 ( struct V_25 * V_25 , unsigned long V_32 )
{
return NULL ;
}
static void F_22 ( struct V_25 * V_25 , unsigned long V_32 , void * V_33 )
{
}
static int F_23 ( struct V_25 * V_25 , struct V_34 * V_35 )
{
return - V_36 ;
}
struct V_25 * F_24 ( struct V_10 * V_11 ,
struct V_37 * V_38 , int V_39 )
{
struct V_6 * V_7 = F_25 ( V_38 ) ;
return F_26 ( V_7 , & V_40 ,
V_7 -> V_12 . V_14 , 0600 ) ;
}
struct V_37 * F_27 ( struct V_10 * V_11 ,
struct V_25 * V_25 )
{
struct V_2 * V_41 ;
struct V_1 * V_16 ;
struct V_6 * V_7 ;
int V_13 ;
int V_14 ;
int V_17 ;
if ( V_25 -> V_42 == & V_40 ) {
V_7 = V_25 -> V_9 ;
if ( V_7 -> V_12 . V_11 == V_11 ) {
F_28 ( & V_7 -> V_12 ) ;
return & V_7 -> V_12 ;
}
}
V_41 = F_29 ( V_25 , V_11 -> V_11 ) ;
if ( F_30 ( V_41 ) )
return F_31 ( V_41 ) ;
V_16 = F_32 ( V_41 , V_43 ) ;
if ( F_30 ( V_16 ) ) {
V_17 = F_33 ( V_16 ) ;
goto V_44;
}
V_14 = V_25 -> V_14 ;
V_13 = V_14 / V_15 ;
V_7 = F_34 ( sizeof( * V_7 ) , V_45 ) ;
if ( V_7 == NULL ) {
V_17 = - V_46 ;
goto V_47;
}
V_17 = F_35 ( V_11 , & V_7 -> V_12 , V_14 ) ;
if ( V_17 ) {
F_11 ( V_7 ) ;
goto V_47;
}
V_7 -> V_1 = V_16 ;
V_7 -> V_12 . V_48 = V_41 ;
return & V_7 -> V_12 ;
V_47:
F_36 ( V_41 , V_16 , V_43 ) ;
V_44:
F_37 ( V_25 , V_41 ) ;
return F_3 ( V_17 ) ;
}
