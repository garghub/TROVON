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
F_10 ( V_4 ) ;
F_4 ( V_2 , V_4 ) ;
return V_9 ;
}
static int F_11 ( struct V_3 * V_4 , struct V_10 * V_11 )
{
bool V_12 ;
bool V_13 = V_4 -> V_14 == & V_15 ;
if ( V_11 == NULL ) {
T_1 V_7 = F_12 ( V_4 ) -> V_16 ? : 1 ;
if ( V_13 )
V_7 *= F_13 ( F_12 ( V_4 ) ) ;
V_4 -> V_7 = V_7 ;
} else {
struct V_17 * V_18 = F_14 ( V_11 ) ;
if ( F_15 ( V_11 ) < sizeof( * V_18 ) )
return - V_19 ;
V_4 -> V_7 = V_18 -> V_7 ;
}
if ( V_13 )
V_12 = V_4 -> V_7 >= F_13 ( F_12 ( V_4 ) ) ;
else
V_12 = V_4 -> V_7 >= 1 ;
if ( V_12 )
V_4 -> V_20 |= V_21 ;
else
V_4 -> V_20 &= ~ V_21 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_17 V_11 = { . V_7 = V_4 -> V_7 } ;
if ( F_17 ( V_2 , V_22 , sizeof( V_11 ) , & V_11 ) )
goto V_23;
return V_2 -> V_24 ;
V_23:
return - 1 ;
}
int F_18 ( struct V_3 * V_8 , unsigned int V_7 )
{
struct V_10 * V_25 ;
int V_26 = - V_27 ;
if ( strncmp ( V_8 -> V_14 -> V_28 + 1 , L_1 , 4 ) != 0 )
return 0 ;
V_25 = F_19 ( F_20 ( sizeof( struct V_17 ) ) , V_29 ) ;
if ( V_25 ) {
V_25 -> V_30 = V_31 ;
V_25 -> F_15 = F_20 ( sizeof( struct V_17 ) ) ;
( (struct V_17 * ) F_14 ( V_25 ) ) -> V_7 = V_7 ;
V_26 = V_8 -> V_14 -> V_32 ( V_8 , V_25 ) ;
F_21 ( V_25 ) ;
}
return V_26 ;
}
struct V_3 * F_22 ( struct V_3 * V_4 , struct V_33 * V_14 ,
unsigned int V_7 )
{
struct V_3 * V_8 ;
int V_34 = - V_27 ;
V_8 = F_23 ( V_4 -> V_35 , V_14 , F_24 ( V_4 -> V_36 , 1 ) ) ;
if ( V_8 ) {
V_34 = F_18 ( V_8 , V_7 ) ;
if ( V_34 < 0 ) {
F_25 ( V_8 ) ;
V_8 = NULL ;
}
}
return V_8 ? : F_26 ( V_34 ) ;
}
