static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_1 * * V_5 )
{
if ( F_2 ( V_4 -> V_6 . V_7 + F_3 ( V_2 ) <= V_4 -> V_8 ) )
return F_4 ( V_2 , V_4 ) ;
return F_5 ( V_2 , V_4 , V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_1 * * V_5 )
{
if ( F_2 ( F_7 ( & V_4 -> V_9 ) < V_4 -> V_8 ) )
return F_4 ( V_2 , V_4 ) ;
return F_5 ( V_2 , V_4 , V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_1 * * V_5 )
{
unsigned int V_10 ;
if ( F_2 ( F_7 ( & V_4 -> V_9 ) < V_4 -> V_8 ) )
return F_4 ( V_2 , V_4 ) ;
V_10 = V_4 -> V_6 . V_7 ;
F_9 ( V_4 , & V_4 -> V_9 , V_5 ) ;
F_10 ( V_4 ) ;
F_4 ( V_2 , V_4 ) ;
F_11 ( V_4 , 0 , V_10 - V_4 -> V_6 . V_7 ) ;
return V_11 ;
}
static int F_12 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
bool V_14 ;
bool V_15 = V_4 -> V_16 == & V_17 ;
if ( V_13 == NULL ) {
T_1 V_8 = F_13 ( V_4 ) -> V_18 ;
if ( V_15 )
V_8 *= F_14 ( F_13 ( V_4 ) ) ;
V_4 -> V_8 = V_8 ;
} else {
struct V_19 * V_20 = F_15 ( V_13 ) ;
if ( F_16 ( V_13 ) < sizeof( * V_20 ) )
return - V_21 ;
V_4 -> V_8 = V_20 -> V_8 ;
}
if ( V_15 )
V_14 = V_4 -> V_8 >= F_14 ( F_13 ( V_4 ) ) ;
else
V_14 = V_4 -> V_8 >= 1 ;
if ( V_14 )
V_4 -> V_22 |= V_23 ;
else
V_4 -> V_22 &= ~ V_23 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_19 V_13 = { . V_8 = V_4 -> V_8 } ;
if ( F_18 ( V_2 , V_24 , sizeof( V_13 ) , & V_13 ) )
goto V_25;
return V_2 -> V_26 ;
V_25:
return - 1 ;
}
int F_19 ( struct V_3 * V_9 , unsigned int V_8 )
{
struct V_12 * V_27 ;
int V_28 = - V_29 ;
if ( strncmp ( V_9 -> V_16 -> V_30 + 1 , L_1 , 4 ) != 0 )
return 0 ;
V_27 = F_20 ( F_21 ( sizeof( struct V_19 ) ) , V_31 ) ;
if ( V_27 ) {
V_27 -> V_32 = V_33 ;
V_27 -> F_16 = F_21 ( sizeof( struct V_19 ) ) ;
( (struct V_19 * ) F_15 ( V_27 ) ) -> V_8 = V_8 ;
V_28 = V_9 -> V_16 -> V_34 ( V_9 , V_27 ) ;
F_22 ( V_27 ) ;
}
return V_28 ;
}
struct V_3 * F_23 ( struct V_3 * V_4 , struct V_35 * V_16 ,
unsigned int V_8 )
{
struct V_3 * V_9 ;
int V_36 = - V_29 ;
V_9 = F_24 ( V_4 -> V_37 , V_16 , F_25 ( V_4 -> V_38 , 1 ) ) ;
if ( V_9 ) {
V_36 = F_19 ( V_9 , V_8 ) ;
if ( V_36 < 0 ) {
F_26 ( V_9 ) ;
V_9 = NULL ;
}
}
return V_9 ? : F_27 ( V_36 ) ;
}
