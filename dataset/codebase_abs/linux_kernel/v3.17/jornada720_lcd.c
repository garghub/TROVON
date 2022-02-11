static int F_1 ( struct V_1 * V_2 )
{
if ( V_3 & V_4 )
return V_5 ;
else
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_7 ;
if ( F_1 ( V_2 ) != V_5 )
return 0 ;
F_3 () ;
if ( F_4 ( V_8 ) == V_9 ) {
V_7 = F_4 ( V_9 ) ;
goto V_10;
}
F_5 ( & V_2 -> V_11 , L_1 ) ;
V_7 = - V_12 ;
V_10:
F_6 () ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , int V_13 )
{
int V_7 = 0 ;
F_3 () ;
if ( F_4 ( V_14 ) == V_9 ) {
if ( F_4 ( V_13 ) == V_9 )
goto V_10;
}
F_5 ( & V_2 -> V_11 , L_1 ) ;
V_7 = - V_12 ;
V_10:
F_6 () ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 , int V_15 )
{
if ( V_15 != V_5 ) {
V_3 &= ~ V_4 ;
V_16 |= V_4 ;
} else {
V_3 |= V_4 ;
}
return 0 ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_1 * V_1 ;
int V_7 ;
V_1 = F_10 ( & V_18 -> V_11 , V_19 ,
& V_18 -> V_11 , NULL , & V_20 ) ;
if ( F_11 ( V_1 ) ) {
V_7 = F_12 ( V_1 ) ;
F_5 ( & V_18 -> V_11 , L_2 ) ;
return V_7 ;
}
F_13 ( V_18 , V_1 ) ;
F_7 ( V_1 , V_21 ) ;
F_8 ( V_1 , V_5 ) ;
F_14 ( 100 ) ;
return 0 ;
}
