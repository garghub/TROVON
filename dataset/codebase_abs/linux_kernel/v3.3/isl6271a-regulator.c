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
int V_15 , V_16 , V_6 ;
if ( V_12 < V_10 || V_12 > V_17 )
return - V_18 ;
if ( V_13 < V_10 || V_13 > V_17 )
return - V_18 ;
V_15 = V_12 - ( V_12 % V_11 ) ;
if ( V_15 < V_12 )
V_15 += V_11 ;
V_6 = ( V_15 - V_10 ) / V_11 ;
* V_14 = V_6 ;
F_3 ( & V_4 -> V_7 ) ;
V_16 = F_8 ( V_4 -> V_8 , V_6 ) ;
if ( V_16 < 0 )
F_5 ( & V_4 -> V_8 -> V_2 , L_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return V_16 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_14 )
{
return V_10 + ( V_11 * V_14 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_19 = F_11 ( V_2 ) ;
return ( V_19 == 1 ) ? 1100000 : 1300000 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_14 )
{
int V_19 = F_11 ( V_2 ) ;
return ( V_19 == 1 ) ? 1100000 : 1300000 ;
}
static int T_1 F_13 ( struct V_20 * V_21 ,
const struct V_22 * V_19 )
{
struct V_23 * V_24 = V_21 -> V_2 . V_25 ;
struct V_3 * V_4 ;
int V_16 , V_26 ;
if ( ! F_14 ( V_21 -> V_27 , V_28 ) )
return - V_29 ;
if ( ! V_24 ) {
F_5 ( & V_21 -> V_2 , L_3 ) ;
return - V_29 ;
}
V_4 = F_15 ( sizeof( struct V_3 ) , V_30 ) ;
if ( ! V_4 )
return - V_31 ;
V_4 -> V_8 = V_21 ;
F_16 ( & V_4 -> V_7 ) ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ ) {
V_4 -> V_32 [ V_26 ] = F_17 ( & V_33 [ V_26 ] , & V_21 -> V_2 ,
V_24 , V_4 , NULL ) ;
if ( F_18 ( V_4 -> V_32 [ V_26 ] ) ) {
F_5 ( & V_21 -> V_2 , L_4 , V_19 -> V_34 ) ;
V_16 = F_19 ( V_4 -> V_32 [ V_26 ] ) ;
goto error;
}
}
F_20 ( V_21 , V_4 ) ;
return 0 ;
error:
while ( -- V_26 >= 0 )
F_21 ( V_4 -> V_32 [ V_26 ] ) ;
F_22 ( V_4 ) ;
return V_16 ;
}
static int T_2 F_23 ( struct V_20 * V_21 )
{
struct V_3 * V_4 = F_24 ( V_21 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 3 ; V_26 ++ )
F_21 ( V_4 -> V_32 [ V_26 ] ) ;
F_22 ( V_4 ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_35 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_35 ) ;
}
