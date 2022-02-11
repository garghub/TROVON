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
F_14 ( & V_10 -> V_18 , V_19 | V_20 ) ;
return 0 ;
}
static int F_15 ( struct V_9 * V_10 ,
T_1 V_21 , char T_2 * V_2 )
{
int V_11 , V_22 ;
struct V_1 * V_7 = F_4 ( V_10 ) ;
if ( F_16 ( & V_7 -> V_12 ) )
return - V_23 ;
if ( ! F_17 ( & V_7 -> V_7 ) || V_21 < F_18 ( & V_7 -> V_7 ) )
V_11 = - V_5 ;
else
V_11 = F_19 ( & V_7 -> V_7 , V_2 , V_21 , & V_22 ) ;
F_8 ( & V_7 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_22 ;
}
static bool F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_4 ( V_10 ) ;
bool V_24 ;
F_5 ( & V_7 -> V_12 ) ;
V_24 = F_21 ( & V_7 -> V_7 ) ;
F_8 ( & V_7 -> V_12 ) ;
return ! V_24 ;
}
static void F_22 ( struct V_9 * V_14 )
{
struct V_1 * V_7 = F_4 ( V_14 ) ;
F_23 ( & V_7 -> V_12 ) ;
F_6 ( & V_7 -> V_7 ) ;
F_24 ( V_7 ) ;
}
struct V_9 * F_25 ( void )
{
struct V_1 * V_7 ;
V_7 = F_26 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_13 = true ;
F_27 ( & V_7 -> V_14 ) ;
V_7 -> V_14 . V_25 = & V_26 ;
V_7 -> V_14 . V_4 = 2 ;
F_28 ( & V_7 -> V_12 ) ;
return & V_7 -> V_14 ;
}
void F_29 ( struct V_9 * V_10 )
{
F_30 ( V_10 ) ;
}
static void F_31 ( struct V_27 * V_28 , void * V_29 )
{
F_29 ( * (struct V_9 * * ) V_29 ) ;
}
static int F_32 ( struct V_27 * V_28 , void * V_29 , void * V_16 )
{
struct V_9 * * V_10 = V_29 ;
if ( F_33 ( ! V_10 || ! * V_10 ) )
return 0 ;
return * V_10 == V_16 ;
}
struct V_9 * F_34 ( struct V_27 * V_28 )
{
struct V_9 * * V_30 , * V_10 ;
V_30 = F_35 ( F_31 , sizeof( * V_30 ) , V_8 ) ;
if ( ! V_30 )
return NULL ;
V_10 = F_25 () ;
if ( V_10 ) {
* V_30 = V_10 ;
F_36 ( V_28 , V_30 ) ;
} else {
F_37 ( V_30 ) ;
}
return V_10 ;
}
void F_38 ( struct V_27 * V_28 , struct V_9 * V_10 )
{
F_33 ( F_39 ( V_28 , F_31 ,
F_32 , V_10 ) ) ;
}
