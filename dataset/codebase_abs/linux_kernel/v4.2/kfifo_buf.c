static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( ( V_4 == 0 ) || ( V_3 == 0 ) )
return - V_5 ;
return F_2 ( (struct V_6 * ) & V_2 -> V_7 , V_4 ,
V_3 , V_8 ) ;
}
static int F_3 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_1 * V_2 = F_4 ( V_10 ) ;
F_5 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_13 ) {
F_6 ( & V_2 -> V_7 ) ;
V_11 = F_1 ( V_2 , V_2 -> V_14 . V_3 ,
V_2 -> V_14 . V_4 ) ;
if ( V_11 >= 0 )
V_2 -> V_13 = false ;
} else {
F_7 ( & V_2 -> V_7 ) ;
}
F_8 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_4 ( V_10 ) ;
V_7 -> V_13 = true ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , T_1 V_15 )
{
if ( V_10 -> V_3 != V_15 ) {
V_10 -> V_3 = V_15 ;
F_9 ( V_10 ) ;
}
return 0 ;
}
static int F_11 ( struct V_9 * V_10 , int V_4 )
{
if ( V_4 < 2 )
V_4 = 2 ;
if ( V_10 -> V_4 != V_4 ) {
V_10 -> V_4 = V_4 ;
F_9 ( V_10 ) ;
}
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
const void * V_16 )
{
int V_11 ;
struct V_1 * V_7 = F_4 ( V_10 ) ;
V_11 = F_13 ( & V_7 -> V_7 , V_16 , 1 ) ;
if ( V_11 != 1 )
return - V_17 ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
T_1 V_18 , char T_2 * V_2 )
{
int V_11 , V_19 ;
struct V_1 * V_7 = F_4 ( V_10 ) ;
if ( F_15 ( & V_7 -> V_12 ) )
return - V_20 ;
if ( ! F_16 ( & V_7 -> V_7 ) || V_18 < F_17 ( & V_7 -> V_7 ) )
V_11 = - V_5 ;
else
V_11 = F_18 ( & V_7 -> V_7 , V_2 , V_18 , & V_19 ) ;
F_8 ( & V_7 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_19 ;
}
static T_1 F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_4 ( V_10 ) ;
T_1 V_21 ;
F_5 ( & V_7 -> V_12 ) ;
V_21 = F_20 ( & V_7 -> V_7 ) ;
F_8 ( & V_7 -> V_12 ) ;
return V_21 ;
}
static void F_21 ( struct V_9 * V_14 )
{
struct V_1 * V_7 = F_4 ( V_14 ) ;
F_22 ( & V_7 -> V_12 ) ;
F_6 ( & V_7 -> V_7 ) ;
F_23 ( V_7 ) ;
}
struct V_9 * F_24 ( void )
{
struct V_1 * V_7 ;
V_7 = F_25 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_13 = true ;
F_26 ( & V_7 -> V_14 ) ;
V_7 -> V_14 . V_22 = & V_23 ;
V_7 -> V_14 . V_4 = 2 ;
F_27 ( & V_7 -> V_12 ) ;
return & V_7 -> V_14 ;
}
void F_28 ( struct V_9 * V_10 )
{
F_29 ( V_10 ) ;
}
static void F_30 ( struct V_24 * V_25 , void * V_26 )
{
F_28 ( * (struct V_9 * * ) V_26 ) ;
}
static int F_31 ( struct V_24 * V_25 , void * V_26 , void * V_16 )
{
struct V_9 * * V_10 = V_26 ;
if ( F_32 ( ! V_10 || ! * V_10 ) )
return 0 ;
return * V_10 == V_16 ;
}
struct V_9 * F_33 ( struct V_24 * V_25 )
{
struct V_9 * * V_27 , * V_10 ;
V_27 = F_34 ( F_30 , sizeof( * V_27 ) , V_8 ) ;
if ( ! V_27 )
return NULL ;
V_10 = F_24 () ;
if ( V_10 ) {
* V_27 = V_10 ;
F_35 ( V_25 , V_27 ) ;
} else {
F_36 ( V_27 ) ;
}
return V_10 ;
}
void F_37 ( struct V_24 * V_25 , struct V_9 * V_10 )
{
F_32 ( F_38 ( V_25 , F_30 ,
F_31 , V_10 ) ) ;
}
