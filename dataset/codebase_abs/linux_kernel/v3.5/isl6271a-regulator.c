static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
F_3 ( & V_4 -> V_6 ) ;
V_5 = F_4 ( V_4 -> V_7 ) ;
if ( V_5 < 0 )
F_5 ( & V_4 -> V_7 -> V_2 , L_1 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_9 ;
F_3 ( & V_4 -> V_6 ) ;
V_9 = F_8 ( V_4 -> V_7 , V_8 ) ;
if ( V_9 < 0 )
F_5 ( & V_4 -> V_7 -> V_2 , L_2 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_2 )
{
int V_10 = F_10 ( V_2 ) ;
return ( V_10 == 1 ) ? 1100000 : 1300000 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_8 )
{
int V_10 = F_10 ( V_2 ) ;
return ( V_10 == 1 ) ? 1100000 : 1300000 ;
}
static int T_1 F_12 ( struct V_11 * V_12 ,
const struct V_13 * V_10 )
{
struct V_14 V_15 = { } ;
struct V_16 * V_17 = V_12 -> V_2 . V_18 ;
struct V_3 * V_4 ;
int V_9 , V_19 ;
if ( ! F_13 ( V_12 -> V_20 , V_21 ) )
return - V_22 ;
V_4 = F_14 ( & V_12 -> V_2 , sizeof( struct V_3 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_7 = V_12 ;
F_15 ( & V_4 -> V_6 ) ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
V_15 . V_2 = & V_12 -> V_2 ;
if ( V_19 == 0 )
V_15 . V_17 = V_17 ;
else
V_15 . V_17 = 0 ;
V_15 . V_25 = V_4 ;
V_4 -> V_26 [ V_19 ] = F_16 ( & V_27 [ V_19 ] , & V_15 ) ;
if ( F_17 ( V_4 -> V_26 [ V_19 ] ) ) {
F_5 ( & V_12 -> V_2 , L_3 , V_10 -> V_28 ) ;
V_9 = F_18 ( V_4 -> V_26 [ V_19 ] ) ;
goto error;
}
}
F_19 ( V_12 , V_4 ) ;
return 0 ;
error:
while ( -- V_19 >= 0 )
F_20 ( V_4 -> V_26 [ V_19 ] ) ;
return V_9 ;
}
static int T_2 F_21 ( struct V_11 * V_12 )
{
struct V_3 * V_4 = F_22 ( V_12 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
F_20 ( V_4 -> V_26 [ V_19 ] ) ;
return 0 ;
}
static int T_3 F_23 ( void )
{
return F_24 ( & V_29 ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( & V_29 ) ;
}
