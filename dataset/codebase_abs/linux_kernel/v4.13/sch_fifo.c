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
if ( F_2 ( V_4 -> V_9 . V_10 < V_4 -> V_8 ) )
return F_4 ( V_2 , V_4 ) ;
return F_5 ( V_2 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_1 * * V_5 )
{
unsigned int V_11 ;
if ( F_2 ( V_4 -> V_9 . V_10 < V_4 -> V_8 ) )
return F_4 ( V_2 , V_4 ) ;
V_11 = V_4 -> V_6 . V_7 ;
F_8 ( V_4 , & V_4 -> V_9 , V_5 ) ;
F_9 ( V_4 ) ;
F_4 ( V_2 , V_4 ) ;
F_10 ( V_4 , 0 , V_11 - V_4 -> V_6 . V_7 ) ;
return V_12 ;
}
static int F_11 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
bool V_15 ;
bool V_16 = V_4 -> V_17 == & V_18 ;
if ( V_14 == NULL ) {
T_1 V_8 = F_12 ( V_4 ) -> V_19 ;
if ( V_16 )
V_8 *= F_13 ( F_12 ( V_4 ) ) ;
V_4 -> V_8 = V_8 ;
} else {
struct V_20 * V_21 = F_14 ( V_14 ) ;
if ( F_15 ( V_14 ) < sizeof( * V_21 ) )
return - V_22 ;
V_4 -> V_8 = V_21 -> V_8 ;
}
if ( V_16 )
V_15 = V_4 -> V_8 >= F_13 ( F_12 ( V_4 ) ) ;
else
V_15 = V_4 -> V_8 >= 1 ;
if ( V_15 )
V_4 -> V_23 |= V_24 ;
else
V_4 -> V_23 &= ~ V_24 ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_20 V_14 = { . V_8 = V_4 -> V_8 } ;
if ( F_17 ( V_2 , V_25 , sizeof( V_14 ) , & V_14 ) )
goto V_26;
return V_2 -> V_27 ;
V_26:
return - 1 ;
}
int F_18 ( struct V_3 * V_9 , unsigned int V_8 )
{
struct V_13 * V_28 ;
int V_29 = - V_30 ;
if ( strncmp ( V_9 -> V_17 -> V_31 + 1 , L_1 , 4 ) != 0 )
return 0 ;
V_28 = F_19 ( F_20 ( sizeof( struct V_20 ) ) , V_32 ) ;
if ( V_28 ) {
V_28 -> V_33 = V_34 ;
V_28 -> F_15 = F_20 ( sizeof( struct V_20 ) ) ;
( (struct V_20 * ) F_14 ( V_28 ) ) -> V_8 = V_8 ;
V_29 = V_9 -> V_17 -> V_35 ( V_9 , V_28 ) ;
F_21 ( V_28 ) ;
}
return V_29 ;
}
struct V_3 * F_22 ( struct V_3 * V_4 , struct V_36 * V_17 ,
unsigned int V_8 )
{
struct V_3 * V_9 ;
int V_37 = - V_30 ;
V_9 = F_23 ( V_4 -> V_38 , V_17 , F_24 ( V_4 -> V_39 , 1 ) ) ;
if ( V_9 ) {
V_37 = F_18 ( V_9 , V_8 ) ;
if ( V_37 < 0 ) {
F_25 ( V_9 ) ;
V_9 = NULL ;
}
}
return V_9 ? : F_26 ( V_37 ) ;
}
