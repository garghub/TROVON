static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned long long V_9 ;
int V_10 , V_11 ;
V_9 = F_3 ( V_8 -> V_12 ) / 256 ;
V_9 = V_9 * V_6 ;
F_4 ( V_9 , V_13 ) ;
if ( V_9 == 0 )
V_9 = 1 ;
if ( V_9 > 255 )
V_9 = 0 ;
V_10 = V_9 ;
V_9 = 256 * V_5 ;
F_4 ( V_9 , V_6 ) ;
if ( V_9 > 255 )
V_9 = 255 ;
V_11 = 256 - V_9 ;
F_5 ( V_14 | F_6 ( V_10 ) | F_7 ( V_11 ) ,
V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_9 ( V_8 -> V_12 ) ;
}
static void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_5 ( 0 , V_8 -> V_15 + ( V_4 -> V_16 << 2 ) ) ;
F_11 ( V_8 -> V_12 ) ;
}
static int F_12 ( struct V_17 * V_18 )
{
struct V_7 * V_8 ;
struct V_19 * V_20 ;
int V_21 ;
V_8 = F_13 ( & V_18 -> V_22 , sizeof( * V_8 ) , V_23 ) ;
if ( ! V_8 )
return - V_24 ;
V_20 = F_14 ( V_18 , V_25 , 0 ) ;
if ( ! V_20 )
return - V_26 ;
V_8 -> V_15 = F_15 ( & V_18 -> V_22 , V_20 ) ;
if ( F_16 ( V_8 -> V_15 ) )
return F_17 ( V_8 -> V_15 ) ;
V_8 -> V_12 = F_18 ( & V_18 -> V_22 , NULL ) ;
if ( F_16 ( V_8 -> V_12 ) )
return F_17 ( V_8 -> V_12 ) ;
V_8 -> V_2 . V_22 = & V_18 -> V_22 ;
V_8 -> V_2 . V_27 = & V_28 ;
V_8 -> V_2 . V_29 = 2 ;
V_8 -> V_2 . V_15 = - 1 ;
V_21 = F_19 ( & V_8 -> V_2 ) ;
if ( V_21 < 0 ) {
F_20 ( & V_18 -> V_22 , L_1 , V_21 ) ;
return V_21 ;
}
F_21 ( V_18 , V_8 ) ;
return 0 ;
}
static int F_22 ( struct V_17 * V_18 )
{
struct V_7 * V_8 = F_23 ( V_18 ) ;
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < V_8 -> V_2 . V_29 ; V_30 ++ )
F_24 ( & V_8 -> V_2 . V_31 [ V_30 ] ) ;
return F_25 ( & V_8 -> V_2 ) ;
}
