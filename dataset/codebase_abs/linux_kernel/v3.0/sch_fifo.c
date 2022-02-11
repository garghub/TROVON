static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_2 ( V_4 -> V_5 . V_6 + F_3 ( V_2 ) <= V_4 -> V_7 ) )
return F_4 ( V_2 , V_4 ) ;
return F_5 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_2 ( F_7 ( & V_4 -> V_8 ) < V_4 -> V_7 ) )
return F_4 ( V_2 , V_4 ) ;
return F_5 ( V_2 , V_4 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_2 ( F_7 ( & V_4 -> V_8 ) < V_4 -> V_7 ) )
return F_4 ( V_2 , V_4 ) ;
F_9 ( V_4 , & V_4 -> V_8 ) ;
V_4 -> V_5 . V_9 ++ ;
F_4 ( V_2 , V_4 ) ;
return V_10 ;
}
static int F_10 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
bool V_13 ;
bool V_14 = V_4 -> V_15 == & V_16 ;
if ( V_12 == NULL ) {
T_1 V_7 = F_11 ( V_4 ) -> V_17 ? : 1 ;
if ( V_14 )
V_7 *= F_12 ( F_11 ( V_4 ) ) ;
V_4 -> V_7 = V_7 ;
} else {
struct V_18 * V_19 = F_13 ( V_12 ) ;
if ( F_14 ( V_12 ) < sizeof( * V_19 ) )
return - V_20 ;
V_4 -> V_7 = V_19 -> V_7 ;
}
if ( V_14 )
V_13 = V_4 -> V_7 >= F_12 ( F_11 ( V_4 ) ) ;
else
V_13 = V_4 -> V_7 >= 1 ;
if ( V_13 )
V_4 -> V_21 |= V_22 ;
else
V_4 -> V_21 &= ~ V_22 ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_18 V_12 = { . V_7 = V_4 -> V_7 } ;
F_16 ( V_2 , V_23 , sizeof( V_12 ) , & V_12 ) ;
return V_2 -> V_24 ;
V_25:
return - 1 ;
}
int F_17 ( struct V_3 * V_8 , unsigned int V_7 )
{
struct V_11 * V_26 ;
int V_27 = - V_28 ;
if ( strncmp ( V_8 -> V_15 -> V_29 + 1 , L_1 , 4 ) != 0 )
return 0 ;
V_26 = F_18 ( F_19 ( sizeof( struct V_18 ) ) , V_30 ) ;
if ( V_26 ) {
V_26 -> V_31 = V_32 ;
V_26 -> F_14 = F_19 ( sizeof( struct V_18 ) ) ;
( (struct V_18 * ) F_13 ( V_26 ) ) -> V_7 = V_7 ;
V_27 = V_8 -> V_15 -> V_33 ( V_8 , V_26 ) ;
F_20 ( V_26 ) ;
}
return V_27 ;
}
struct V_3 * F_21 ( struct V_3 * V_4 , struct V_34 * V_15 ,
unsigned int V_7 )
{
struct V_3 * V_8 ;
int V_35 = - V_28 ;
V_8 = F_22 ( V_4 -> V_36 , V_15 , F_23 ( V_4 -> V_37 , 1 ) ) ;
if ( V_8 ) {
V_35 = F_17 ( V_8 , V_7 ) ;
if ( V_35 < 0 ) {
F_24 ( V_8 ) ;
V_8 = NULL ;
}
}
return V_8 ? : F_25 ( V_35 ) ;
}
