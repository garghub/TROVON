static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
F_2 ( V_4 -> V_6 ) ;
F_3 ( V_2 ) ;
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
V_2 -> V_7 = 0 ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_12 * V_13 = V_10 -> V_2 . V_14 ;
struct V_3 * V_4 ;
struct V_15 * V_16 ;
int V_17 ;
if ( V_13 == NULL ) {
F_7 ( V_2 -> V_2 , L_1 ) ;
return - V_18 ;
}
V_4 = F_8 ( & V_10 -> V_2 , sizeof( * V_4 ) , V_19 ) ;
if ( V_4 == NULL ) {
F_7 ( V_2 -> V_2 , L_2 ) ;
return - V_20 ;
}
F_9 ( & V_4 -> V_21 . V_22 ) ;
V_4 -> V_2 = & V_10 -> V_2 ;
V_4 -> V_23 = F_10 ( V_24 , V_4 -> V_2 ) -> V_25 ;
V_4 -> V_26 = V_2 ;
V_2 -> V_5 = V_4 ;
V_16 = F_11 ( V_10 , V_27 , 0 ) ;
V_4 -> V_28 = F_12 ( & V_10 -> V_2 , V_16 ) ;
if ( F_13 ( V_4 -> V_28 ) )
return F_14 ( V_4 -> V_28 ) ;
V_17 = F_15 ( V_2 , ( 1 << V_4 -> V_23 -> V_29 ) - 1 ) ;
if ( V_17 < 0 ) {
F_7 ( & V_10 -> V_2 , L_3 ) ;
goto V_30;
}
V_17 = F_16 ( V_4 ) ;
if ( V_17 < 0 ) {
F_7 ( & V_10 -> V_2 , L_4 , V_17 ) ;
goto V_30;
}
V_2 -> V_7 = 1 ;
F_17 ( V_10 , V_4 ) ;
V_30:
if ( V_17 )
F_1 ( V_2 ) ;
return V_17 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_33 ;
for ( V_33 = 0 ; V_33 < V_4 -> V_29 ; ++ V_33 )
F_19 ( & V_4 -> V_34 [ V_33 ] , V_32 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_21 ( V_4 -> V_6 ) ;
}
static int F_22 ( struct V_1 * V_2 , unsigned int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( & V_4 -> V_34 [ V_35 ] , true ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_23 ( & V_4 -> V_34 [ V_35 ] , false ) ;
}
static int F_25 ( struct V_36 * V_2 )
{
struct V_3 * V_4 = F_26 ( V_2 ) ;
F_27 ( V_4 -> V_26 ) ;
return 0 ;
}
static int F_28 ( struct V_36 * V_2 )
{
struct V_3 * V_4 = F_26 ( V_2 ) ;
F_29 ( V_4 -> V_26 ) ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
return F_31 ( & V_37 , V_10 ) ;
}
static int F_32 ( struct V_9 * V_10 )
{
struct V_3 * V_4 = F_33 ( V_10 ) ;
F_34 ( V_4 -> V_26 ) ;
return 0 ;
}
