static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_2 -> V_4 = F_2 ( V_2 -> V_5 -> V_6 , V_7 ) ;
if ( ! V_2 -> V_4 ) {
F_3 ( & V_2 -> V_5 -> V_8 ,
L_1 ) ;
return - V_9 ;
}
F_4 ( V_2 -> V_4 , V_2 ) ;
V_2 -> V_10 = F_5 ( V_2 -> V_4 ,
& V_11 ) ;
if ( F_6 ( V_2 -> V_10 ) ) {
V_3 = F_7 ( V_2 -> V_10 ) ;
goto V_12;
}
return 0 ;
V_12:
F_8 ( V_2 -> V_4 ) ;
return V_3 ;
}
static int F_9 ( struct V_13 * V_5 ,
const struct V_14 * V_15 )
{
struct V_1 * V_2 ;
unsigned int V_16 ;
int V_3 ;
V_2 = F_10 ( & V_5 -> V_8 , sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
return - V_18 ;
F_4 ( V_5 , V_2 ) ;
V_2 -> V_8 = & V_5 -> V_8 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_19 = V_5 -> V_19 ;
V_2 -> type = V_15 -> V_20 ;
V_2 -> V_21 = F_5 ( V_5 ,
& V_22 ) ;
if ( F_6 ( V_2 -> V_21 ) ) {
F_3 ( & V_5 -> V_8 , L_2 ) ;
return F_7 ( V_2 -> V_21 ) ;
}
V_3 = F_11 ( V_2 -> V_21 , V_2 -> V_19 ,
V_23 | V_24 | V_25 ,
0 , & V_26 , & V_2 -> V_27 ) ;
if ( V_3 ) {
F_3 ( & V_5 -> V_8 , L_3 ) ;
return V_3 ;
}
V_3 = F_12 ( V_2 -> V_21 ,
V_28 , & V_16 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_5 -> V_8 , L_4 ) ;
goto V_29;
}
F_13 ( & V_5 -> V_8 , L_5 , V_16 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 ) {
F_3 ( & V_5 -> V_8 , L_6 ) ;
goto V_29;
}
V_3 = F_14 ( V_2 -> V_21 ,
V_30 ,
V_31 ,
( unsigned int ) ~ V_31 ) ;
if ( V_3 < 0 ) {
F_3 ( & V_5 -> V_8 , L_7 ) ;
goto V_29;
}
V_3 = F_15 ( V_2 -> V_8 , - 1 , V_32 ,
F_16 ( V_32 ) , NULL , 0 , NULL ) ;
if ( V_3 < 0 ) {
F_3 ( & V_5 -> V_8 , L_8 ) ;
goto V_29;
}
F_17 ( V_2 -> V_8 , true ) ;
return 0 ;
V_29:
F_18 ( V_2 -> V_19 , V_2 -> V_27 ) ;
return V_3 ;
}
static int T_1 F_19 ( struct V_33 * V_8 )
{
struct V_13 * V_5 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_21 ( V_5 ) ;
F_22 ( V_2 -> V_19 ) ;
if ( F_23 ( V_8 ) )
F_24 ( V_2 -> V_19 ) ;
return 0 ;
}
static int T_1 F_25 ( struct V_33 * V_8 )
{
struct V_13 * V_5 = F_20 ( V_8 ) ;
struct V_1 * V_2 = F_21 ( V_5 ) ;
if ( F_23 ( V_8 ) )
F_26 ( V_2 -> V_19 ) ;
F_27 ( V_2 -> V_19 ) ;
return 0 ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_34 ) ;
}
