static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_4 ( & V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
V_2 -> V_8 = NULL ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
F_8 ( V_4 -> V_9 ) ;
V_2 -> V_8 = NULL ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_2 , V_2 , V_11 ) ;
memcpy ( F_11 ( V_11 , 1 ) , & F_12 ( V_11 ) -> V_12 , 1 ) ;
F_13 ( & V_4 -> V_7 , V_11 ) ;
return 0 ;
}
static inline int F_14 ( struct V_3 * V_4 , int V_13 )
{
int V_14 = F_15 ( V_4 -> V_9 ) ;
F_2 ( L_3 , V_13 , V_14 ) ;
if ( ! V_13 ) {
F_16 ( V_4 -> V_9 ) ;
} else if ( V_13 > V_14 ) {
F_17 ( L_4 ) ;
F_8 ( V_4 -> V_9 ) ;
} else {
V_4 -> V_15 = V_16 ;
V_4 -> V_17 = V_13 ;
return V_13 ;
}
V_4 -> V_15 = V_18 ;
V_4 -> V_9 = NULL ;
V_4 -> V_17 = 0 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_19 , int V_20 )
{
int V_21 ;
if ( ! F_19 ( V_22 , & V_2 -> V_23 ) )
return - V_24 ;
V_21 = F_20 ( V_2 -> V_25 , V_19 , V_20 ) ;
if ( V_21 < 0 ) {
F_17 ( L_5 ) ;
return V_21 ;
}
return V_20 ;
}
static struct V_10 * F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
return F_22 ( & V_4 -> V_7 ) ;
}
int T_1 F_23 ( void )
{
int V_26 = F_24 ( & V_27 ) ;
if ( ! V_26 )
F_25 ( L_6 ) ;
else
F_17 ( L_7 ) ;
return V_26 ;
}
int T_2 F_26 ( void )
{
return F_27 ( & V_27 ) ;
}
