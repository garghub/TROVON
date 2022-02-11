static struct V_1 * F_1 ( struct V_2 * V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_12 -> V_11 ;
int V_13 = V_7 -> V_14 . V_15 ;
struct V_1 * V_16 ;
int V_17 ;
F_2 ( & V_11 -> V_18 ) ;
V_16 = F_3 ( V_7 -> V_14 . V_19 -> V_20 , V_13 ) ;
V_17 = F_4 ( V_3 -> V_11 , V_16 -> V_21 , V_16 -> V_17 , V_5 ) ;
F_5 ( & V_11 -> V_18 ) ;
return V_16 ;
}
static void F_6 ( struct V_2 * V_3 ,
struct V_1 * V_16 , enum V_4 V_5 )
{
F_7 ( V_3 -> V_11 , V_16 -> V_21 , V_16 -> V_17 , V_5 ) ;
F_8 ( V_16 ) ;
F_9 ( V_16 ) ;
}
static void F_10 ( struct V_22 * V_22 )
{
struct V_6 * V_7 = V_22 -> V_9 ;
if ( V_7 -> V_12 -> V_23 == V_22 ) {
V_7 -> V_12 -> V_23 = NULL ;
F_11 ( V_7 -> V_12 ) ;
}
}
static void * F_12 ( struct V_22 * V_22 , unsigned long V_24 )
{
return NULL ;
}
static void F_13 ( struct V_22 * V_22 , unsigned long V_24 , void * V_25 )
{
}
static void * F_14 ( struct V_22 * V_22 , unsigned long V_24 )
{
return NULL ;
}
static void F_15 ( struct V_22 * V_22 , unsigned long V_24 , void * V_25 )
{
}
static int F_16 ( struct V_22 * V_22 , struct V_26 * V_27 )
{
return - V_28 ;
}
static void * F_17 ( struct V_22 * V_22 )
{
struct V_6 * V_7 = V_22 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_12 -> V_11 ;
int V_29 ;
F_2 ( & V_11 -> V_18 ) ;
if ( V_7 -> V_30 ) {
V_7 -> V_30 ++ ;
goto V_31;
}
V_29 = F_18 ( & V_7 -> V_14 , 0 , V_7 -> V_14 . V_15 ,
& V_7 -> V_32 ) ;
if ( V_29 ) {
F_5 ( & V_11 -> V_18 ) ;
return F_19 ( V_29 ) ;
}
V_7 -> V_30 = 1 ;
V_31:
F_5 ( & V_11 -> V_18 ) ;
return V_7 -> V_32 . V_33 ;
}
static void F_20 ( struct V_22 * V_22 , void * V_34 )
{
struct V_6 * V_7 = V_22 -> V_9 ;
struct V_10 * V_11 = V_7 -> V_12 -> V_11 ;
F_2 ( & V_11 -> V_18 ) ;
V_7 -> V_30 -- ;
if ( V_7 -> V_30 == 0 ) {
F_21 ( & V_7 -> V_32 ) ;
}
F_5 ( & V_11 -> V_18 ) ;
}
static int
F_22 ( struct V_10 * V_11 ,
T_1 V_35 ,
struct V_1 * V_16 ,
struct V_6 * * V_36 )
{
struct V_6 * V_7 ;
T_2 V_37 = 0 ;
int V_29 ;
V_37 = V_38 ;
V_29 = F_23 ( V_11 , V_35 , 0 , V_37 , 0 , 0 ,
V_16 , V_36 ) ;
if ( V_29 )
return V_29 ;
V_7 = * V_36 ;
V_7 -> V_39 = V_40 ;
V_7 -> V_12 = F_24 ( V_11 , V_7 -> V_14 . V_41 . V_35 ) ;
if ( ! V_7 -> V_12 ) {
F_25 ( NULL , V_36 ) ;
return - V_42 ;
}
V_7 -> V_12 -> V_43 = V_7 ;
return 0 ;
}
struct V_22 * F_26 ( struct V_10 * V_11 ,
struct V_44 * V_45 , int V_37 )
{
struct V_6 * V_7 = F_27 ( V_45 ) ;
int V_29 = 0 ;
V_29 = F_28 ( V_7 , V_38 ) ;
if ( V_29 )
return F_19 ( - V_28 ) ;
return F_29 ( V_7 , & V_46 , V_45 -> V_35 , V_37 ) ;
}
struct V_44 * F_30 ( struct V_10 * V_11 ,
struct V_22 * V_22 )
{
struct V_2 * V_47 ;
struct V_1 * V_16 ;
struct V_6 * V_7 ;
int V_29 ;
if ( V_22 -> V_48 == & V_46 ) {
V_7 = V_22 -> V_9 ;
if ( V_7 -> V_12 ) {
if ( V_7 -> V_12 -> V_11 == V_11 ) {
F_31 ( V_7 -> V_12 ) ;
return V_7 -> V_12 ;
}
}
}
V_47 = F_32 ( V_22 , V_11 -> V_11 ) ;
if ( F_33 ( V_47 ) )
return F_19 ( F_34 ( V_47 ) ) ;
V_16 = F_35 ( V_47 , V_49 ) ;
if ( F_33 ( V_16 ) ) {
V_29 = F_34 ( V_16 ) ;
goto V_50;
}
V_29 = F_22 ( V_11 , V_22 -> V_35 , V_16 , & V_7 ) ;
if ( V_29 )
goto V_51;
V_7 -> V_12 -> V_52 = V_47 ;
return V_7 -> V_12 ;
V_51:
F_36 ( V_47 , V_16 , V_49 ) ;
V_50:
F_37 ( V_22 , V_47 ) ;
return F_19 ( V_29 ) ;
}
