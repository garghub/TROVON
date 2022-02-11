static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 , V_6 ;
F_3 ( & V_4 -> V_7 ) ;
V_5 = F_4 ( V_4 -> V_8 ) ;
if ( V_5 < 0 ) {
F_5 ( & V_4 -> V_8 -> V_2 , L_1 ) ;
V_6 = V_5 ;
goto V_9;
}
V_6 = V_10 + ( V_11 * ( V_5 & 0xf ) ) ;
V_9:
F_6 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
int V_12 , int V_13 ,
unsigned * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_15 , V_6 ;
if ( V_12 < V_10 || V_12 > V_16 )
return - V_17 ;
if ( V_13 < V_10 || V_13 > V_16 )
return - V_17 ;
V_6 = F_8 ( V_12 - V_10 ,
V_11 ) ;
* V_14 = V_6 ;
F_3 ( & V_4 -> V_7 ) ;
V_15 = F_9 ( V_4 -> V_8 , V_6 ) ;
if ( V_15 < 0 )
F_5 ( & V_4 -> V_8 -> V_2 , L_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return V_15 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_14 )
{
return V_10 + ( V_11 * V_14 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_18 = F_12 ( V_2 ) ;
return ( V_18 == 1 ) ? 1100000 : 1300000 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_14 )
{
int V_18 = F_12 ( V_2 ) ;
return ( V_18 == 1 ) ? 1100000 : 1300000 ;
}
static int T_1 F_14 ( struct V_19 * V_20 ,
const struct V_21 * V_18 )
{
struct V_22 * V_23 = V_20 -> V_2 . V_24 ;
struct V_3 * V_4 ;
int V_15 , V_25 ;
if ( ! F_15 ( V_20 -> V_26 , V_27 ) )
return - V_28 ;
if ( ! V_23 ) {
F_5 ( & V_20 -> V_2 , L_3 ) ;
return - V_28 ;
}
V_4 = F_16 ( sizeof( struct V_3 ) , V_29 ) ;
if ( ! V_4 )
return - V_30 ;
V_4 -> V_8 = V_20 ;
F_17 ( & V_4 -> V_7 ) ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ ) {
V_4 -> V_31 [ V_25 ] = F_18 ( & V_32 [ V_25 ] , & V_20 -> V_2 ,
V_23 , V_4 , NULL ) ;
if ( F_19 ( V_4 -> V_31 [ V_25 ] ) ) {
F_5 ( & V_20 -> V_2 , L_4 , V_18 -> V_33 ) ;
V_15 = F_20 ( V_4 -> V_31 [ V_25 ] ) ;
goto error;
}
}
F_21 ( V_20 , V_4 ) ;
return 0 ;
error:
while ( -- V_25 >= 0 )
F_22 ( V_4 -> V_31 [ V_25 ] ) ;
F_23 ( V_4 ) ;
return V_15 ;
}
static int T_2 F_24 ( struct V_19 * V_20 )
{
struct V_3 * V_4 = F_25 ( V_20 ) ;
int V_25 ;
for ( V_25 = 0 ; V_25 < 3 ; V_25 ++ )
F_22 ( V_4 -> V_31 [ V_25 ] ) ;
F_23 ( V_4 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_34 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_34 ) ;
}
