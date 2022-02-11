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
return V_2 -> V_10 -> V_11 ;
}
static int T_1 F_10 ( struct V_12 * V_13 ,
const struct V_14 * V_15 )
{
struct V_16 V_17 = { } ;
struct V_18 * V_19 = V_13 -> V_2 . V_20 ;
struct V_3 * V_4 ;
int V_9 , V_21 ;
if ( ! F_11 ( V_13 -> V_22 , V_23 ) )
return - V_24 ;
V_4 = F_12 ( & V_13 -> V_2 , sizeof( struct V_3 ) , V_25 ) ;
if ( ! V_4 )
return - V_26 ;
V_4 -> V_7 = V_13 ;
F_13 ( & V_4 -> V_6 ) ;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ ) {
V_17 . V_2 = & V_13 -> V_2 ;
if ( V_21 == 0 )
V_17 . V_19 = V_19 ;
else
V_17 . V_19 = 0 ;
V_17 . V_27 = V_4 ;
V_4 -> V_28 [ V_21 ] = F_14 ( & V_29 [ V_21 ] , & V_17 ) ;
if ( F_15 ( V_4 -> V_28 [ V_21 ] ) ) {
F_5 ( & V_13 -> V_2 , L_3 , V_15 -> V_30 ) ;
V_9 = F_16 ( V_4 -> V_28 [ V_21 ] ) ;
goto error;
}
}
F_17 ( V_13 , V_4 ) ;
return 0 ;
error:
while ( -- V_21 >= 0 )
F_18 ( V_4 -> V_28 [ V_21 ] ) ;
return V_9 ;
}
static int T_2 F_19 ( struct V_12 * V_13 )
{
struct V_3 * V_4 = F_20 ( V_13 ) ;
int V_21 ;
for ( V_21 = 0 ; V_21 < 3 ; V_21 ++ )
F_18 ( V_4 -> V_28 [ V_21 ] ) ;
return 0 ;
}
static int T_3 F_21 ( void )
{
return F_22 ( & V_31 ) ;
}
static void T_4 F_23 ( void )
{
F_24 ( & V_31 ) ;
}
