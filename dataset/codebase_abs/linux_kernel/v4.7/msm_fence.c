struct V_1 *
F_1 ( struct V_2 * V_3 , const char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( ! V_5 )
return F_3 ( - V_7 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_4 = V_4 ;
V_5 -> V_8 = F_4 ( 1 ) ;
F_5 ( & V_5 -> V_9 ) ;
F_6 ( & V_5 -> V_10 ) ;
return V_5 ;
}
void F_7 ( struct V_1 * V_5 )
{
F_8 ( V_5 ) ;
}
static inline bool F_9 ( struct V_1 * V_5 , T_1 V_11 )
{
return ( V_12 ) ( V_5 -> V_13 - V_11 ) >= 0 ;
}
int F_10 ( struct V_1 * V_5 , T_1 V_11 ,
T_2 * V_14 , bool V_15 )
{
int V_16 ;
if ( V_11 > V_5 -> V_17 ) {
F_11 ( L_1 ,
V_5 -> V_4 , V_11 , V_5 -> V_17 ) ;
return - V_18 ;
}
if ( ! V_14 ) {
V_16 = F_9 ( V_5 , V_11 ) ? 0 : - V_19 ;
} else {
unsigned long V_20 = F_12 ( V_14 ) ;
if ( V_15 )
V_16 = F_13 ( V_5 -> V_9 ,
F_9 ( V_5 , V_11 ) ,
V_20 ) ;
else
V_16 = F_14 ( V_5 -> V_9 ,
F_9 ( V_5 , V_11 ) ,
V_20 ) ;
if ( V_16 == 0 ) {
F_15 ( L_2 ,
V_11 , V_5 -> V_13 ) ;
V_16 = - V_21 ;
} else if ( V_16 != - V_22 ) {
V_16 = 0 ;
}
}
return V_16 ;
}
void F_16 ( struct V_1 * V_5 , T_1 V_11 )
{
F_17 ( & V_5 -> V_10 ) ;
V_5 -> V_13 = F_18 ( V_11 , V_5 -> V_13 ) ;
F_19 ( & V_5 -> V_10 ) ;
F_20 ( & V_5 -> V_9 ) ;
}
static inline struct V_23 * F_21 ( struct V_11 * V_11 )
{
return F_22 ( V_11 , struct V_23 , V_24 ) ;
}
static const char * F_23 ( struct V_11 * V_11 )
{
return L_3 ;
}
static const char * F_24 ( struct V_11 * V_11 )
{
struct V_23 * V_25 = F_21 ( V_11 ) ;
return V_25 -> V_5 -> V_4 ;
}
static bool F_25 ( struct V_11 * V_11 )
{
return true ;
}
static bool F_26 ( struct V_11 * V_11 )
{
struct V_23 * V_25 = F_21 ( V_11 ) ;
return F_9 ( V_25 -> V_5 , V_25 -> V_24 . V_26 ) ;
}
static void F_27 ( struct V_11 * V_11 )
{
struct V_23 * V_25 = F_21 ( V_11 ) ;
F_28 ( V_25 , V_24 . V_27 ) ;
}
struct V_11 *
F_29 ( struct V_1 * V_5 )
{
struct V_23 * V_25 ;
V_25 = F_2 ( sizeof( * V_25 ) , V_6 ) ;
if ( ! V_25 )
return F_3 ( - V_7 ) ;
V_25 -> V_5 = V_5 ;
F_30 ( & V_25 -> V_24 , & V_28 , & V_5 -> V_10 ,
V_5 -> V_8 , ++ V_5 -> V_17 ) ;
return & V_25 -> V_24 ;
}
