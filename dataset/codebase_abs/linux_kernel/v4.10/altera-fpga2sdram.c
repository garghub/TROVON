static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
F_2 ( V_4 -> V_6 , V_7 , & V_5 ) ;
return ( V_5 & V_4 -> V_8 ) == V_4 -> V_8 ;
}
static inline int F_3 ( struct V_3 * V_4 ,
bool V_9 )
{
return F_4 ( V_4 -> V_6 , V_7 ,
V_4 -> V_8 , V_9 ? V_4 -> V_8 : 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , bool V_9 )
{
return F_3 ( V_2 -> V_4 , V_9 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = & V_11 -> V_13 ;
struct V_3 * V_4 ;
T_1 V_9 ;
struct V_14 * V_15 ;
int V_16 = 0 ;
V_4 = F_7 ( V_13 , sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_13 = V_13 ;
V_4 -> V_6 = F_8 ( L_1 ) ;
if ( F_9 ( V_4 -> V_6 ) ) {
F_10 ( V_13 , L_2 ) ;
return F_11 ( V_4 -> V_6 ) ;
}
V_15 = F_8 ( L_3 ) ;
if ( F_9 ( V_15 ) ) {
F_10 ( V_13 , L_4 ) ;
return F_11 ( V_15 ) ;
}
F_2 ( V_15 , V_19 , & V_4 -> V_8 ) ;
V_16 = F_12 ( V_13 , V_20 ,
& V_21 , V_4 ) ;
if ( V_16 )
return V_16 ;
F_13 ( V_13 , L_5 , V_4 -> V_8 ) ;
if ( ! F_14 ( V_13 -> V_22 , L_6 , & V_9 ) ) {
if ( V_9 > 1 ) {
F_15 ( V_13 , L_7 , V_9 ) ;
} else {
F_13 ( V_13 , L_8 ,
( V_9 ? L_9 : L_10 ) ) ;
V_16 = F_3 ( V_4 , V_9 ) ;
if ( V_16 ) {
F_16 ( & V_11 -> V_13 ) ;
return V_16 ;
}
}
}
return V_16 ;
}
static int F_17 ( struct V_10 * V_11 )
{
F_16 ( & V_11 -> V_13 ) ;
return 0 ;
}
