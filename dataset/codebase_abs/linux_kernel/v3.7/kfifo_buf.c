static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( ( V_4 == 0 ) || ( V_3 == 0 ) )
return - V_5 ;
F_2 ( & V_2 -> V_6 , V_3 , V_4 ) ;
return F_3 ( (struct V_7 * ) & V_2 -> V_8 , V_4 ,
V_3 , V_9 ) ;
}
static int F_4 ( struct V_10 * V_11 )
{
int V_12 = 0 ;
struct V_1 * V_2 = F_5 ( V_11 ) ;
if ( ! V_2 -> V_13 )
goto V_14;
F_6 ( & V_2 -> V_8 ) ;
V_12 = F_1 ( V_2 , V_2 -> V_6 . V_3 ,
V_2 -> V_6 . V_4 ) ;
V_11 -> V_15 = false ;
V_14:
return V_12 ;
}
static int F_7 ( struct V_10 * V_11 )
{
return V_11 -> V_4 ;
}
static int F_8 ( struct V_10 * V_11 )
{
return V_11 -> V_3 ;
}
static int F_9 ( struct V_10 * V_11 )
{
struct V_1 * V_8 = F_5 ( V_11 ) ;
V_8 -> V_13 = true ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 , T_1 V_16 )
{
if ( V_11 -> V_3 != V_16 ) {
V_11 -> V_3 = V_16 ;
F_9 ( V_11 ) ;
}
return 0 ;
}
static int F_11 ( struct V_10 * V_11 , int V_4 )
{
if ( V_4 < 2 )
V_4 = 2 ;
if ( V_11 -> V_4 != V_4 ) {
V_11 -> V_4 = V_4 ;
F_9 ( V_11 ) ;
}
return 0 ;
}
static int F_12 ( struct V_10 * V_11 ,
T_2 * V_17 )
{
int V_12 ;
struct V_1 * V_8 = F_5 ( V_11 ) ;
V_12 = F_13 ( & V_8 -> V_8 , V_17 , 1 ) ;
if ( V_12 != 1 )
return - V_18 ;
V_11 -> V_15 = true ;
F_14 ( & V_11 -> V_19 ) ;
return 0 ;
}
static int F_15 ( struct V_10 * V_11 ,
T_1 V_20 , char T_3 * V_2 )
{
int V_12 , V_21 ;
struct V_1 * V_8 = F_5 ( V_11 ) ;
if ( V_20 < V_11 -> V_3 || V_11 -> V_3 == 0 )
return - V_5 ;
V_12 = F_16 ( & V_8 -> V_8 , V_2 , V_20 , & V_21 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( F_17 ( & V_8 -> V_8 ) )
V_11 -> V_15 = false ;
if ( ! F_17 ( & V_8 -> V_8 ) )
V_11 -> V_15 = true ;
return V_21 ;
}
struct V_10 * F_18 ( struct V_22 * V_23 )
{
struct V_1 * V_8 ;
V_8 = F_19 ( sizeof *V_8 , V_9 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_13 = true ;
F_20 ( & V_8 -> V_6 ) ;
V_8 -> V_6 . V_24 = & V_25 ;
V_8 -> V_6 . V_26 = & V_27 ;
V_8 -> V_6 . V_4 = 2 ;
return & V_8 -> V_6 ;
}
void F_21 ( struct V_10 * V_11 )
{
F_22 ( F_5 ( V_11 ) ) ;
}
