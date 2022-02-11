static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( ( V_4 == 0 ) || ( V_3 == 0 ) )
return - V_5 ;
F_2 ( & V_2 -> V_6 , V_3 , V_4 ) ;
return F_3 ( & V_2 -> V_7 , V_3 * V_4 , V_8 ) ;
}
static int F_4 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
if ( ! V_2 -> V_12 )
goto V_13;
F_6 ( & V_2 -> V_7 ) ;
V_11 = F_1 ( V_2 , V_2 -> V_6 . V_3 ,
V_2 -> V_6 . V_4 ) ;
V_13:
return V_11 ;
}
static int F_7 ( struct V_9 * V_10 )
{
return V_10 -> V_4 ;
}
struct V_9 * F_8 ( struct V_14 * V_15 )
{
struct V_1 * V_7 ;
V_7 = F_9 ( sizeof *V_7 , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_12 = true ;
F_10 ( & V_7 -> V_6 ) ;
V_7 -> V_6 . V_16 = & V_17 ;
return & V_7 -> V_6 ;
}
static int F_11 ( struct V_9 * V_10 )
{
return V_10 -> V_3 ;
}
static int F_12 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_5 ( V_10 ) ;
V_7 -> V_12 = true ;
return 0 ;
}
static int F_13 ( struct V_9 * V_10 , T_1 V_18 )
{
if ( V_10 -> V_3 != V_18 ) {
V_10 -> V_3 = V_18 ;
F_12 ( V_10 ) ;
}
return 0 ;
}
static int F_14 ( struct V_9 * V_10 , int V_4 )
{
if ( V_10 -> V_4 != V_4 ) {
V_10 -> V_4 = V_4 ;
F_12 ( V_10 ) ;
}
return 0 ;
}
void F_15 ( struct V_9 * V_10 )
{
F_16 ( F_5 ( V_10 ) ) ;
}
static int F_17 ( struct V_9 * V_10 ,
T_2 * V_19 ,
T_3 V_20 )
{
int V_11 ;
struct V_1 * V_7 = F_5 ( V_10 ) ;
V_11 = F_18 ( & V_7 -> V_7 , V_19 , V_10 -> V_3 ) ;
if ( V_11 != V_10 -> V_3 )
return - V_21 ;
return 0 ;
}
static int F_19 ( struct V_9 * V_10 ,
T_1 V_22 , char T_4 * V_2 )
{
int V_11 , V_23 ;
struct V_1 * V_7 = F_5 ( V_10 ) ;
if ( V_22 < V_10 -> V_3 )
return - V_5 ;
V_22 = F_20 ( V_22 , V_10 -> V_3 ) ;
V_11 = F_21 ( & V_7 -> V_7 , V_2 , V_22 , & V_23 ) ;
return V_23 ;
}
