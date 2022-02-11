static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_4 )
return 0 ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_4 ) ;
F_8 ( V_4 ) ;
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , const struct V_6 * V_7 )
{
unsigned int V_8 ;
int V_5 ;
if ( ! V_2 || ! V_7 )
return - V_9 ;
V_5 = F_11 ( V_2 ) ;
if ( V_5 )
return V_5 ;
for ( V_8 = 0 ; V_8 < V_7 -> V_10 ; V_8 ++ ) {
V_5 = F_12 ( V_2 , V_7 -> V_11 [ V_8 ] ) ;
if ( V_5 ) {
F_13 ( V_2 , L_1 ,
V_7 -> V_11 [ V_8 ] ) ;
F_14 ( V_2 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_15 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = & V_13 -> V_2 ;
const struct V_6 * V_7 ;
struct V_3 * V_4 ;
int V_5 , V_14 ;
V_7 = F_16 ( & V_13 -> V_2 ) ;
if ( ! V_7 ) {
F_13 ( & V_13 -> V_2 , L_2 ) ;
return - V_15 ;
}
V_14 = F_17 ( V_2 -> V_16 , 0 ) ;
if ( ! V_14 ) {
F_13 ( V_2 , L_3 ) ;
return - V_9 ;
}
V_5 = F_10 ( V_2 , V_7 ) ;
if ( V_5 )
goto V_17;
F_18 ( V_2 ) ;
V_5 = F_19 ( V_2 ) ;
if ( V_5 < 0 )
goto V_18;
V_5 = F_20 ( V_2 , & V_4 , V_14 ) ;
if ( V_5 )
goto V_19;
F_21 ( V_13 , V_4 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 , L_4 ) ;
return 0 ;
V_19:
F_24 ( V_2 ) ;
V_18:
F_25 ( V_2 ) ;
F_14 ( V_2 ) ;
V_17:
F_26 ( V_14 ) ;
return V_5 ;
}
