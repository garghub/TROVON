static int F_1 ( struct V_1 * V_2 [] , struct V_1 * V_3 [] )
{
if ( V_2 [ V_4 ] ) {
if ( F_2 ( V_2 [ V_4 ] ) != V_5 )
return - V_6 ;
if ( ! F_3 ( F_4 ( V_2 [ V_4 ] ) ) )
return - V_7 ;
}
return 0 ;
}
static int F_5 ( struct V_8 * V_9 ,
struct V_1 * V_2 [] , struct V_1 * V_3 [] )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
int V_12 ;
if ( V_3 && V_3 [ V_13 ] ) {
int V_14 = F_7 ( V_3 [ V_13 ] ) ;
V_12 = F_8 ( V_11 , V_14 ) ;
if ( V_12 )
return V_12 ;
}
if ( V_3 && V_3 [ V_15 ] ) {
int V_16 = F_9 ( V_3 [ V_15 ] ) ;
struct V_8 * V_17 ;
if ( V_16 == 0 ) {
V_17 = NULL ;
} else {
V_17 = F_10 ( F_11 ( V_9 ) ,
V_16 ) ;
if ( ! V_17 )
return - V_18 ;
}
V_12 = F_12 ( V_11 , V_17 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
static int F_13 ( struct V_19 * V_20 , struct V_8 * V_9 ,
struct V_1 * V_2 [] , struct V_1 * V_3 [] )
{
int V_12 ;
V_12 = F_5 ( V_9 , V_2 , V_3 ) ;
if ( V_12 < 0 )
return V_12 ;
return F_14 ( V_9 ) ;
}
static T_1 F_15 ( const struct V_8 * V_9 )
{
return F_16 ( sizeof( V_21 ) ) +
F_16 ( sizeof( V_22 ) ) ;
}
static int F_17 ( struct V_23 * V_24 ,
const struct V_8 * V_9 )
{
struct V_10 * V_11 = F_6 ( V_9 ) ;
struct V_8 * V_17 = F_18 ( V_11 ) ;
if ( F_19 ( V_24 , V_13 , V_11 -> V_25 . V_14 ) ||
( V_17 &&
F_20 ( V_24 , V_15 , V_17 -> V_16 ) ) )
goto V_26;
return 0 ;
V_26:
return - V_27 ;
}
int T_2 F_21 ( void )
{
return F_22 ( & V_28 ) ;
}
void F_23 ( void )
{
F_24 ( & V_28 ) ;
}
