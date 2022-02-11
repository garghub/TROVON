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
V_10 -> V_15 = false ;
F_8 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_9 ( struct V_9 * V_10 )
{
return V_10 -> V_4 ;
}
static int F_10 ( struct V_9 * V_10 )
{
return V_10 -> V_3 ;
}
static int F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_4 ( V_10 ) ;
V_7 -> V_13 = true ;
return 0 ;
}
static int F_12 ( struct V_9 * V_10 , T_1 V_16 )
{
if ( V_10 -> V_3 != V_16 ) {
V_10 -> V_3 = V_16 ;
F_11 ( V_10 ) ;
}
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , int V_4 )
{
if ( V_4 < 2 )
V_4 = 2 ;
if ( V_10 -> V_4 != V_4 ) {
V_10 -> V_4 = V_4 ;
F_11 ( V_10 ) ;
}
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
const void * V_17 )
{
int V_11 ;
struct V_1 * V_7 = F_4 ( V_10 ) ;
V_11 = F_15 ( & V_7 -> V_7 , V_17 , 1 ) ;
if ( V_11 != 1 )
return - V_18 ;
V_10 -> V_15 = true ;
F_16 ( & V_10 -> V_19 , V_20 | V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_9 * V_10 ,
T_1 V_22 , char T_2 * V_2 )
{
int V_11 , V_23 ;
struct V_1 * V_7 = F_4 ( V_10 ) ;
if ( F_18 ( & V_7 -> V_12 ) )
return - V_24 ;
if ( ! F_19 ( & V_7 -> V_7 ) || V_22 < F_20 ( & V_7 -> V_7 ) )
V_11 = - V_5 ;
else
V_11 = F_21 ( & V_7 -> V_7 , V_2 , V_22 , & V_23 ) ;
if ( F_22 ( & V_7 -> V_7 ) )
V_10 -> V_15 = false ;
if ( ! F_22 ( & V_7 -> V_7 ) )
V_10 -> V_15 = true ;
F_8 ( & V_7 -> V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_23 ;
}
static void F_23 ( struct V_9 * V_14 )
{
struct V_1 * V_7 = F_4 ( V_14 ) ;
F_24 ( & V_7 -> V_12 ) ;
F_6 ( & V_7 -> V_7 ) ;
F_25 ( V_7 ) ;
}
struct V_9 * F_26 ( struct V_25 * V_26 )
{
struct V_1 * V_7 ;
V_7 = F_27 ( sizeof *V_7 , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_13 = true ;
F_28 ( & V_7 -> V_14 ) ;
V_7 -> V_14 . V_27 = & V_28 ;
V_7 -> V_14 . V_29 = & V_30 ;
V_7 -> V_14 . V_4 = 2 ;
F_29 ( & V_7 -> V_12 ) ;
return & V_7 -> V_14 ;
}
void F_30 ( struct V_9 * V_10 )
{
F_31 ( V_10 ) ;
}
