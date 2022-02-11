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
if ( ! V_2 -> V_12 )
goto V_13;
F_5 ( & V_2 -> V_7 ) ;
V_11 = F_1 ( V_2 , V_2 -> V_14 . V_3 ,
V_2 -> V_14 . V_4 ) ;
V_10 -> V_15 = false ;
V_13:
return V_11 ;
}
static int F_6 ( struct V_9 * V_10 )
{
return V_10 -> V_4 ;
}
static int F_7 ( struct V_9 * V_10 )
{
return V_10 -> V_3 ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_4 ( V_10 ) ;
V_7 -> V_12 = true ;
return 0 ;
}
static int F_9 ( struct V_9 * V_10 , T_1 V_16 )
{
if ( V_10 -> V_3 != V_16 ) {
V_10 -> V_3 = V_16 ;
F_8 ( V_10 ) ;
}
return 0 ;
}
static int F_10 ( struct V_9 * V_10 , int V_4 )
{
if ( V_4 < 2 )
V_4 = 2 ;
if ( V_10 -> V_4 != V_4 ) {
V_10 -> V_4 = V_4 ;
F_8 ( V_10 ) ;
}
return 0 ;
}
static int F_11 ( struct V_9 * V_10 ,
T_2 * V_17 )
{
int V_11 ;
struct V_1 * V_7 = F_4 ( V_10 ) ;
V_11 = F_12 ( & V_7 -> V_7 , V_17 , 1 ) ;
if ( V_11 != 1 )
return - V_18 ;
V_10 -> V_15 = true ;
F_13 ( & V_10 -> V_19 ) ;
return 0 ;
}
static int F_14 ( struct V_9 * V_10 ,
T_1 V_20 , char T_3 * V_2 )
{
int V_11 , V_21 ;
struct V_1 * V_7 = F_4 ( V_10 ) ;
if ( V_20 < V_10 -> V_3 || V_10 -> V_3 == 0 )
return - V_5 ;
V_11 = F_15 ( & V_7 -> V_7 , V_2 , V_20 , & V_21 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( F_16 ( & V_7 -> V_7 ) )
V_10 -> V_15 = false ;
if ( ! F_16 ( & V_7 -> V_7 ) )
V_10 -> V_15 = true ;
return V_21 ;
}
struct V_9 * F_17 ( struct V_22 * V_23 )
{
struct V_1 * V_7 ;
V_7 = F_18 ( sizeof *V_7 , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_12 = true ;
F_19 ( & V_7 -> V_14 ) ;
V_7 -> V_14 . V_24 = & V_25 ;
V_7 -> V_14 . V_26 = & V_27 ;
V_7 -> V_14 . V_4 = 2 ;
return & V_7 -> V_14 ;
}
void F_20 ( struct V_9 * V_10 )
{
F_21 ( F_4 ( V_10 ) ) ;
}
