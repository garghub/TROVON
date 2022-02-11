static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
F_3 ( & V_4 [ V_9 -> V_10 ] , & V_9 -> V_4 ) ;
}
static int F_4 ( const struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_13 * const V_14 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_15 V_16 ;
int V_17 ;
if ( V_14 [ V_18 ] == NULL ||
V_14 [ V_19 ] == NULL )
return - V_20 ;
V_9 -> V_10 = F_5 ( F_6 ( V_14 [ V_18 ] ) ) ;
V_17 = F_7 ( V_9 -> V_10 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_8 ( V_12 , & V_9 -> V_4 , & V_16 , V_14 [ V_19 ] ) ;
if ( V_17 < 0 )
return V_17 ;
V_9 -> V_21 = V_16 . V_22 ;
V_17 = F_9 ( V_12 , V_9 -> V_10 , & V_9 -> V_4 , V_16 . type ) ;
if ( V_17 < 0 )
goto V_23;
return 0 ;
V_23:
F_10 ( & V_9 -> V_4 , V_16 . type ) ;
return V_17 ;
}
static void F_11 ( const struct V_11 * V_12 ,
const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
return F_10 ( & V_9 -> V_4 , F_12 ( V_9 -> V_10 ) ) ;
}
static int F_13 ( struct V_24 * V_25 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_14 ( V_25 , V_18 , F_15 ( V_9 -> V_10 ) ) )
goto V_26;
return F_16 ( V_25 , V_19 , & V_9 -> V_4 ,
F_12 ( V_9 -> V_10 ) , V_9 -> V_21 ) ;
V_26:
return - 1 ;
}
static int F_17 ( const struct V_11 * V_12 ,
const struct V_1 * V_2 ,
const struct V_3 * * V_4 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( V_9 -> V_10 == V_27 )
* V_4 = & V_9 -> V_4 ;
return 0 ;
}
int T_1 F_18 ( void )
{
return F_19 ( & V_28 ) ;
}
void F_20 ( void )
{
F_21 ( & V_28 ) ;
}
