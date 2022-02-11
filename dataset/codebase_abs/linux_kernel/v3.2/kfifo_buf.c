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
F_6 ( & V_2 -> V_12 ) ;
if ( ! V_2 -> V_13 )
goto V_14;
if ( V_2 -> V_15 ) {
V_11 = - V_16 ;
goto V_14;
}
F_7 ( & V_2 -> V_7 ) ;
V_11 = F_1 ( V_2 , V_2 -> V_6 . V_3 ,
V_2 -> V_6 . V_4 ) ;
V_14:
F_8 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
F_6 ( & V_2 -> V_12 ) ;
V_2 -> V_15 ++ ;
F_8 ( & V_2 -> V_12 ) ;
}
static void F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
F_6 ( & V_2 -> V_12 ) ;
V_2 -> V_15 -- ;
F_8 ( & V_2 -> V_12 ) ;
}
static int F_11 ( struct V_9 * V_10 )
{
return V_10 -> V_4 ;
}
static inline void F_12 ( struct V_1 * V_7 )
{
F_13 ( & V_7 -> V_12 ) ;
}
struct V_9 * F_14 ( struct V_17 * V_18 )
{
struct V_1 * V_7 ;
V_7 = F_15 ( sizeof *V_7 , V_8 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_13 = true ;
F_16 ( & V_7 -> V_6 , V_18 ) ;
V_7 -> V_6 . V_19 = & V_20 ;
F_12 ( V_7 ) ;
return & V_7 -> V_6 ;
}
static int F_17 ( struct V_9 * V_10 )
{
return V_10 -> V_3 ;
}
static int F_18 ( struct V_9 * V_10 , T_1 V_21 )
{
if ( V_10 -> V_3 != V_21 ) {
V_10 -> V_3 = V_21 ;
if ( V_10 -> V_22 -> V_23 )
V_10 -> V_22 -> V_23 ( V_10 ) ;
}
return 0 ;
}
static int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_7 = F_5 ( V_10 ) ;
V_7 -> V_13 = true ;
return 0 ;
}
static int F_20 ( struct V_9 * V_10 , int V_4 )
{
if ( V_10 -> V_4 != V_4 ) {
V_10 -> V_4 = V_4 ;
if ( V_10 -> V_22 -> V_23 )
V_10 -> V_22 -> V_23 ( V_10 ) ;
}
return 0 ;
}
void F_21 ( struct V_9 * V_10 )
{
F_22 ( F_5 ( V_10 ) ) ;
}
static int F_23 ( struct V_9 * V_10 ,
T_2 * V_24 ,
T_3 V_25 )
{
int V_11 ;
struct V_1 * V_7 = F_5 ( V_10 ) ;
T_2 * V_26 = F_24 ( V_10 -> V_3 , V_8 ) ;
memcpy ( V_26 , V_24 , V_10 -> V_3 - sizeof( V_25 ) ) ;
memcpy ( V_26 + V_10 -> V_3 - sizeof( V_25 ) ,
& V_25 , sizeof( V_25 ) ) ;
V_11 = F_25 ( & V_7 -> V_7 , V_24 , V_10 -> V_3 ) ;
if ( V_11 != V_10 -> V_3 ) {
F_22 ( V_26 ) ;
return - V_27 ;
}
F_22 ( V_26 ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
T_1 V_28 , char T_4 * V_2 )
{
int V_11 , V_29 ;
struct V_1 * V_7 = F_5 ( V_10 ) ;
V_11 = F_27 ( & V_7 -> V_7 , V_2 , V_10 -> V_3 * V_28 , & V_29 ) ;
return V_29 ;
}
