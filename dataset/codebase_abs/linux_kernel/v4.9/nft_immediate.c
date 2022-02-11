static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_9 [ V_8 -> V_10 ] , & V_8 -> V_9 , V_8 -> V_11 ) ;
}
static int F_4 ( const struct V_12 * V_13 ,
const struct V_1 * V_2 ,
const struct V_14 * const V_15 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_16 V_17 ;
int V_18 ;
if ( V_15 [ V_19 ] == NULL ||
V_15 [ V_20 ] == NULL )
return - V_21 ;
V_18 = F_5 ( V_13 , & V_8 -> V_9 , sizeof( V_8 -> V_9 ) , & V_17 ,
V_15 [ V_20 ] ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_17 . V_22 > V_23 )
return - V_24 ;
V_8 -> V_11 = V_17 . V_22 ;
V_8 -> V_10 = F_6 ( V_15 [ V_19 ] ) ;
V_18 = F_7 ( V_13 , V_8 -> V_10 , & V_8 -> V_9 ,
V_17 . type , V_17 . V_22 ) ;
if ( V_18 < 0 )
goto V_25;
return 0 ;
V_25:
F_8 ( & V_8 -> V_9 , V_17 . type ) ;
return V_18 ;
}
static void F_9 ( const struct V_12 * V_13 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
return F_8 ( & V_8 -> V_9 , F_10 ( V_8 -> V_10 ) ) ;
}
static int F_11 ( struct V_26 * V_27 , const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_12 ( V_27 , V_19 , V_8 -> V_10 ) )
goto V_28;
return F_13 ( V_27 , V_20 , & V_8 -> V_9 ,
F_10 ( V_8 -> V_10 ) , V_8 -> V_11 ) ;
V_28:
return - 1 ;
}
static int F_14 ( const struct V_12 * V_13 ,
const struct V_1 * V_2 ,
const struct V_29 * * V_9 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_10 == V_30 )
* V_9 = & V_8 -> V_9 ;
return 0 ;
}
int T_1 F_15 ( void )
{
return F_16 ( & V_31 ) ;
}
void F_17 ( void )
{
F_18 ( & V_31 ) ;
}
