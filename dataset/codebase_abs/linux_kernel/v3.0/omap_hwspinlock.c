static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ( V_5 == F_3 ( V_4 -> V_6 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_5 , V_4 -> V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( 50 ) ;
}
static int T_1 F_8 ( struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
void T_2 * V_13 ;
int V_14 , V_15 ;
V_12 = F_9 ( V_8 , V_16 , 0 ) ;
if ( ! V_12 )
return - V_17 ;
V_10 = F_10 ( sizeof( * V_10 ) , V_18 ) ;
if ( ! V_10 )
return - V_19 ;
V_13 = F_11 ( V_12 -> V_20 , F_12 ( V_12 ) ) ;
if ( ! V_13 ) {
V_15 = - V_19 ;
goto V_21;
}
V_14 = F_3 ( V_13 + V_22 ) ;
V_14 >>= V_23 ;
if ( F_13 ( V_14 & 0xf ) != 1 || V_14 > 8 ) {
V_15 = - V_24 ;
goto V_25;
}
V_10 -> V_26 = V_14 * 32 ;
V_10 -> V_13 = V_13 ;
F_14 ( V_8 , V_10 ) ;
F_15 ( & V_8 -> V_27 ) ;
for ( V_14 = 0 ; V_14 < V_10 -> V_26 ; V_14 ++ ) {
V_4 = F_10 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 ) {
V_15 = - V_19 ;
goto V_28;
}
V_4 -> V_2 . V_27 = & V_8 -> V_27 ;
V_4 -> V_2 . V_29 = V_30 ;
V_4 -> V_2 . V_31 = V_14 ;
V_4 -> V_2 . V_32 = & V_33 ;
V_4 -> V_6 = V_13 + V_34 + sizeof( V_35 ) * V_14 ;
V_15 = F_16 ( & V_4 -> V_2 ) ;
if ( V_15 ) {
F_17 ( V_4 ) ;
goto V_28;
}
}
return 0 ;
V_28:
while ( -- V_14 >= 0 ) {
V_2 = F_18 ( V_14 ) ;
if ( ! V_2 ) {
F_19 ( & V_8 -> V_27 , L_1 , V_36 ) ;
continue;
}
V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 ) ;
}
F_20 ( & V_8 -> V_27 ) ;
V_25:
F_21 ( V_13 ) ;
V_21:
F_17 ( V_10 ) ;
return V_15 ;
}
static int F_22 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_23 ( V_8 ) ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_10 -> V_26 ; V_14 ++ ) {
V_2 = F_18 ( V_14 ) ;
if ( ! V_2 ) {
F_19 ( & V_8 -> V_27 , L_2 , V_36 , V_14 ) ;
return - V_37 ;
}
V_4 = F_2 ( V_2 ) ;
F_17 ( V_4 ) ;
}
F_20 ( & V_8 -> V_27 ) ;
F_21 ( V_10 -> V_13 ) ;
F_17 ( V_10 ) ;
return 0 ;
}
static int T_3 F_24 ( void )
{
return F_25 ( & V_38 ) ;
}
static void T_4 F_26 ( void )
{
F_27 ( & V_38 ) ;
}
