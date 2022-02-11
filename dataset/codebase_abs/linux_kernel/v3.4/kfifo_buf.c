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
static int F_8 ( struct V_9 * V_10 )
{
return V_10 -> V_3 ;
}
static int F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_5 ( V_10 ) ;
V_7 -> V_12 = true ;
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , T_1 V_14 )
{
if ( V_10 -> V_3 != V_14 ) {
V_10 -> V_3 = V_14 ;
F_9 ( V_10 ) ;
}
return 0 ;
}
static int F_11 ( struct V_9 * V_10 , int V_4 )
{
if ( V_10 -> V_4 != V_4 ) {
V_10 -> V_4 = V_4 ;
F_9 ( V_10 ) ;
}
return 0 ;
}
static int F_12 ( struct V_9 * V_10 ,
T_2 * V_15 ,
T_3 V_16 )
{
int V_11 ;
struct V_1 * V_7 = F_5 ( V_10 ) ;
V_11 = F_13 ( & V_7 -> V_7 , V_15 , V_10 -> V_3 ) ;
if ( V_11 != V_10 -> V_3 )
return - V_17 ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
T_1 V_18 , char T_4 * V_2 )
{
int V_11 , V_19 ;
struct V_1 * V_7 = F_5 ( V_10 ) ;
if ( V_18 < V_10 -> V_3 )
return - V_5 ;
V_18 = F_15 ( V_18 , V_10 -> V_3 ) ;
V_11 = F_16 ( & V_7 -> V_7 , V_2 , V_18 , & V_19 ) ;
return V_19 ;
}
struct V_9 * F_17 ( struct V_20 * V_21 )
{
struct V_1 * V_7 ;
V_7 = F_18 ( sizeof *V_7 , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_12 = true ;
F_19 ( & V_7 -> V_6 ) ;
V_7 -> V_6 . V_22 = & V_23 ;
V_7 -> V_6 . V_24 = & V_25 ;
return & V_7 -> V_6 ;
}
void F_20 ( struct V_9 * V_10 )
{
F_21 ( F_5 ( V_10 ) ) ;
}
