int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
V_2 -> V_4 = F_2 ( V_3 , sizeof( struct V_5 ) ,
V_6 ) ;
if ( ! V_2 -> V_4 )
return - V_7 ;
V_2 -> V_8 =
F_2 ( F_3 ( V_3 ) , sizeof( unsigned long ) ,
V_6 ) ;
if ( ! V_2 -> V_8 ) {
F_4 ( V_2 -> V_4 ) ;
return - V_7 ;
}
F_5 ( V_2 -> V_8 , V_3 ) ;
return 0 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_8 ) ;
F_4 ( V_2 -> V_4 ) ;
}
int F_7 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_8 ( V_10 -> V_13 -> V_14 -> V_15 ) ;
return F_9 ( V_12 , V_10 ) ;
}
struct V_5 * F_10 ( struct V_5 * V_13 )
{
F_11 ( & V_13 -> V_16 ) ;
return V_13 ;
}
struct V_5 * F_12 ( struct V_11 * V_12 ,
unsigned int V_17 )
{
struct V_5 * V_18 = & V_12 -> V_19 . V_4 [ V_17 ] ;
if ( ! F_13 ( & V_18 -> V_16 ) )
return NULL ;
return V_18 ;
}
static void F_14 ( struct V_20 * V_20 )
{
struct V_5 * V_13 =
F_15 ( V_20 , struct V_5 , V_16 ) ;
struct V_11 * V_12 = F_8 ( V_13 -> V_14 -> V_15 ) ;
struct V_1 * V_2 = & V_12 -> V_19 ;
F_16 ( V_12 , & V_13 -> V_21 ) ;
F_17 ( & V_13 -> V_21 ) ;
F_18 ( V_13 -> V_22 , V_2 -> V_8 ) ;
}
void F_19 ( struct V_5 * V_13 )
{
F_20 ( & V_13 -> V_16 , F_14 ) ;
}
static struct V_5 * F_21 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_19 ;
unsigned int V_23 = V_12 -> V_24 -> V_25 ;
unsigned int V_17 ;
V_17 = F_22 ( V_2 -> V_8 , V_23 ) ;
if ( V_17 >= V_23 ) {
F_23 ( V_12 -> V_14 , L_1 ) ;
return NULL ;
}
V_2 -> V_4 [ V_17 ] . V_22 = V_17 ;
F_24 ( V_17 , V_2 -> V_8 ) ;
return & V_2 -> V_4 [ V_17 ] ;
}
struct V_5 * F_25 ( struct V_26 * V_14 )
{
struct V_11 * V_12 = F_8 ( V_14 -> V_15 ) ;
struct V_1 * V_2 = & V_12 -> V_19 ;
struct V_5 * V_13 ;
int V_27 ;
V_13 = F_21 ( V_12 ) ;
if ( ! V_13 )
return NULL ;
F_26 ( & V_13 -> V_16 ) ;
F_27 ( & V_13 -> V_28 ) ;
V_13 -> V_14 = V_14 ;
V_27 = F_28 ( V_12 , V_13 , V_13 -> V_22 ) ;
if ( V_27 < 0 )
goto V_29;
V_27 = F_29 ( & V_13 -> V_21 ) ;
if ( V_27 < 0 )
goto V_29;
return V_13 ;
V_29:
F_18 ( V_13 -> V_22 , V_2 -> V_8 ) ;
F_23 ( V_14 , L_2 ) ;
return NULL ;
}
