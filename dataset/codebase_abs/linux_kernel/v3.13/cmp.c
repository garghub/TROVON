void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_6 )
{
V_6 &= ~ F_6 ( V_7 |
V_8 |
V_9 ) ;
V_6 |= F_6 ( 1 << V_10 ) ;
V_6 |= F_6 ( V_2 -> V_5 . V_11 << V_12 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_6 )
{
if ( V_6 & F_6 ( V_7 |
V_8 ) ) {
F_8 ( V_2 , L_1 ) ;
return - V_13 ;
}
if ( ! ( V_6 & F_6 ( V_14 ) ) ) {
F_8 ( V_2 , L_2 ) ;
return - V_15 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
unsigned int V_16 )
{
int V_17 ;
if ( F_2 ( V_2 -> V_3 ) )
return - V_18 ;
V_2 -> V_19 = F_10 ( V_2 -> V_20 ,
F_11 ( V_2 -> V_5 . V_21 ) -> V_20 ) ;
F_12 ( & V_2 -> V_4 ) ;
V_22:
V_17 = F_13 ( & V_2 -> V_5 ,
V_16 , V_2 -> V_19 ) ;
if ( V_17 < 0 )
goto V_23;
V_17 = F_14 ( V_2 , F_5 , F_7 ,
V_24 ) ;
if ( V_17 == - V_25 ) {
F_15 ( & V_2 -> V_5 ) ;
goto V_22;
}
if ( V_17 < 0 )
goto V_26;
V_2 -> V_3 = true ;
F_16 ( & V_2 -> V_4 ) ;
return 0 ;
V_26:
F_15 ( & V_2 -> V_5 ) ;
V_23:
F_16 ( & V_2 -> V_4 ) ;
return V_17 ;
}
int F_17 ( struct V_1 * V_2 )
{
int V_17 ;
F_12 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_3 ) {
F_16 ( & V_2 -> V_4 ) ;
return 0 ;
}
V_17 = F_18 ( & V_2 -> V_5 ) ;
if ( V_17 < 0 )
goto V_27;
V_17 = F_14 ( V_2 , F_5 , F_7 ,
V_28 ) ;
if ( V_17 < 0 )
goto V_26;
F_16 ( & V_2 -> V_4 ) ;
return 0 ;
V_26:
F_15 ( & V_2 -> V_5 ) ;
V_27:
V_2 -> V_3 = false ;
F_16 ( & V_2 -> V_4 ) ;
return V_17 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_1 V_6 )
{
return V_6 & ~ F_6 ( V_7 | V_8 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
int V_17 ;
F_12 ( & V_2 -> V_4 ) ;
if ( ! V_2 -> V_3 ) {
F_16 ( & V_2 -> V_4 ) ;
return;
}
V_17 = F_14 ( V_2 , F_19 , NULL , V_28 ) ;
if ( V_17 < 0 )
F_8 ( V_2 , L_3 ) ;
F_15 ( & V_2 -> V_5 ) ;
V_2 -> V_3 = false ;
F_16 ( & V_2 -> V_4 ) ;
}
