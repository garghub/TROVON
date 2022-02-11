static int F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_1 -> V_3 = F_2 ( V_1 -> V_4 -> V_5 , V_6 ) ;
if ( ! V_1 -> V_3 ) {
F_3 ( & V_1 -> V_4 -> V_7 ,
L_1 ) ;
return F_4 ( V_1 -> V_3 ) ;
}
F_5 ( V_1 -> V_3 , V_1 ) ;
V_1 -> V_8 = F_6 ( V_1 -> V_3 ,
& V_9 ) ;
if ( F_7 ( V_1 -> V_8 ) ) {
V_2 = F_4 ( V_1 -> V_8 ) ;
goto V_10;
}
return 0 ;
V_10:
F_8 ( V_1 -> V_3 ) ;
return V_2 ;
}
static int F_9 ( struct V_11 * V_4 ,
const struct V_12 * V_13 )
{
struct V_1 * V_1 ;
unsigned int V_14 ;
int V_2 ;
V_1 = F_10 ( & V_4 -> V_7 , sizeof( * V_1 ) , V_15 ) ;
if ( ! V_1 )
return - V_16 ;
F_5 ( V_4 , V_1 ) ;
V_1 -> V_7 = & V_4 -> V_7 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_17 = V_4 -> V_17 ;
V_1 -> V_18 = F_6 ( V_4 ,
& V_19 ) ;
if ( F_7 ( V_1 -> V_18 ) ) {
F_3 ( & V_4 -> V_7 , L_2 ) ;
return F_4 ( V_1 -> V_18 ) ;
}
V_2 = F_11 ( V_1 -> V_18 , V_1 -> V_17 ,
V_20 | V_21 | V_22 ,
0 , & V_23 , & V_1 -> V_24 ) ;
if ( V_2 ) {
F_3 ( & V_4 -> V_7 , L_3 ) ;
return V_2 ;
}
V_2 = F_12 ( V_1 -> V_18 ,
V_25 , & V_14 ) ;
if ( V_2 < 0 ) {
F_3 ( & V_4 -> V_7 , L_4 ) ;
goto V_26;
}
F_13 ( & V_4 -> V_7 , L_5 , V_14 ) ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 ) {
F_3 ( & V_4 -> V_7 , L_6 ) ;
goto V_26;
}
V_2 = F_14 ( V_1 -> V_18 ,
V_27 ,
V_28 ,
( unsigned int ) ~ V_28 ) ;
if ( V_2 < 0 ) {
F_3 ( & V_4 -> V_7 , L_7 ) ;
goto V_26;
}
V_2 = F_15 ( V_1 -> V_7 , - 1 , V_29 ,
F_16 ( V_29 ) , NULL , 0 , NULL ) ;
if ( V_2 < 0 ) {
F_3 ( & V_4 -> V_7 , L_8 ) ;
goto V_26;
}
F_17 ( V_1 -> V_7 , true ) ;
return 0 ;
V_26:
F_18 ( V_1 -> V_17 , V_1 -> V_24 ) ;
return V_2 ;
}
static int F_19 ( struct V_11 * V_4 )
{
struct V_1 * V_1 = F_20 ( V_4 ) ;
F_21 ( V_1 -> V_7 ) ;
F_18 ( V_1 -> V_17 , V_1 -> V_24 ) ;
F_8 ( V_1 -> V_3 ) ;
return 0 ;
}
static int T_1 F_22 ( struct V_30 * V_7 )
{
struct V_11 * V_4 = F_23 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_1 = F_20 ( V_4 ) ;
F_24 ( V_1 -> V_17 ) ;
if ( F_25 ( V_7 ) )
F_26 ( V_1 -> V_17 ) ;
return 0 ;
}
static int T_1 F_27 ( struct V_30 * V_7 )
{
struct V_11 * V_4 = F_23 ( V_7 , struct V_11 , V_7 ) ;
struct V_1 * V_1 = F_20 ( V_4 ) ;
if ( F_25 ( V_7 ) )
F_28 ( V_1 -> V_17 ) ;
F_29 ( V_1 -> V_17 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_31 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_31 ) ;
}
