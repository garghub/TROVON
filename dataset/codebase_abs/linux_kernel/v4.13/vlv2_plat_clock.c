int F_1 ( int V_1 , int V_2 )
{
void T_1 * V_3 ;
if ( V_1 < 0 || V_1 >= V_4 ) {
F_2 ( L_1 , V_1 ) ;
return - V_5 ;
}
if ( V_2 != V_6 &&
V_2 != V_7 ) {
F_2 ( L_2 ) ;
return - V_5 ;
}
if ( ! V_8 ) {
F_2 ( L_3 ) ;
return - V_5 ;
}
V_3 = V_8 + F_3 ( V_1 ) ;
F_4 ( & V_9 ) ;
F_5 ( F_6 ( F_7 ( V_3 ) , V_10 , V_2 ) , V_3 ) ;
F_8 ( & V_9 ) ;
return 0 ;
}
int F_9 ( int V_1 )
{
T_2 V_11 ;
if ( V_1 < 0 || V_1 >= V_4 ) {
F_2 ( L_1 , V_1 ) ;
return - V_5 ;
}
if ( ! V_8 ) {
F_2 ( L_3 ) ;
return - V_5 ;
}
F_4 ( & V_9 ) ;
V_11 = F_10 ( F_7 ( V_8 + F_3 ( V_1 ) ) ,
V_10 ) ;
F_8 ( & V_9 ) ;
return V_11 ;
}
int F_11 ( int V_1 , T_2 V_12 )
{
void T_1 * V_3 ;
if ( V_1 < 0 || V_1 >= V_4 ) {
F_2 ( L_1 , V_1 ) ;
return - V_5 ;
}
if ( V_12 != V_13 &&
V_12 != V_14 &&
V_12 != V_15 ) {
F_2 ( L_4 ) ;
return - V_5 ;
}
if ( ! V_8 ) {
F_2 ( L_3 ) ;
return - V_5 ;
}
V_3 = V_8 + F_3 ( V_1 ) ;
F_4 ( & V_9 ) ;
F_5 ( F_6 ( F_7 ( V_3 ) , V_16 , V_12 ) , V_3 ) ;
F_8 ( & V_9 ) ;
return 0 ;
}
int F_12 ( int V_1 )
{
int V_11 ;
if ( V_1 < 0 || V_1 >= V_4 ) {
F_2 ( L_1 , V_1 ) ;
return - V_5 ;
}
if ( ! V_8 ) {
F_2 ( L_3 ) ;
return - V_5 ;
}
F_4 ( & V_9 ) ;
V_11 = ( int ) F_10 ( F_7 ( V_8 + F_3 ( V_1 ) ) ,
V_16 ) ;
F_8 ( & V_9 ) ;
return V_11 ;
}
static int F_13 ( struct V_17 * V_18 )
{
int V_19 = 0 ;
V_8 = F_14 ( V_20 , V_21 ) ;
if ( ! V_8 ) {
F_15 ( & V_18 -> V_22 , L_5 ) ;
return - V_23 ;
}
for ( V_19 = 0 ; V_19 < V_4 ; V_19 ++ )
F_11 ( V_19 , V_15 ) ;
F_16 ( & V_18 -> V_22 , L_6 ) ;
return 0 ;
}
static int F_17 ( struct V_24 * V_24 )
{
int V_19 ;
for ( V_19 = 0 ; V_19 < V_4 ; V_19 ++ )
F_11 ( V_19 , V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_24 * V_24 )
{
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_25 ) ;
}
