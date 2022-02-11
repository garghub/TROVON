static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 -> V_9 , V_10 , & V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_7 & F_4 ( V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_8 -> V_9 , V_10 ,
F_4 ( V_3 ) , 0 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_8 -> V_9 , V_12 ,
F_4 ( V_3 ) , V_11 ? F_4 ( V_3 ) : 0 ) ;
F_6 ( V_5 -> V_8 -> V_9 , V_10 ,
F_4 ( V_3 ) , F_4 ( V_3 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 -> V_9 , V_13 , & V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_7 & F_4 ( V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_8 -> V_9 , V_12 ,
F_4 ( V_3 ) , V_11 ? F_4 ( V_3 ) : 0 ) ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
int V_6 ;
V_5 = F_11 ( & V_15 -> V_16 , sizeof( * V_5 ) , V_17 ) ;
if ( ! V_5 )
return - V_18 ;
F_12 ( V_15 , V_5 ) ;
V_5 -> V_8 = F_13 ( V_15 -> V_16 . V_19 ) ;
V_5 -> V_2 = V_20 ;
V_5 -> V_2 . V_19 = V_5 -> V_8 -> V_16 ;
V_6 = F_14 ( & V_15 -> V_16 , & V_5 -> V_2 , V_5 ) ;
if ( V_6 < 0 ) {
F_15 ( & V_15 -> V_16 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
