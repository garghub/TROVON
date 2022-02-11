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
static int F_9 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
struct V_14 V_15 = { } ;
struct V_16 * V_17 = F_10 ( & V_11 -> V_2 ) ;
struct V_3 * V_4 ;
int V_9 , V_18 ;
if ( ! F_11 ( V_11 -> V_19 , V_20 ) )
return - V_21 ;
V_4 = F_12 ( & V_11 -> V_2 , sizeof( struct V_3 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_7 = V_11 ;
F_13 ( & V_4 -> V_6 ) ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ ) {
V_15 . V_2 = & V_11 -> V_2 ;
if ( V_18 == 0 )
V_15 . V_17 = V_17 ;
else
V_15 . V_17 = NULL ;
V_15 . V_24 = V_4 ;
V_4 -> V_25 [ V_18 ] = F_14 ( & V_26 [ V_18 ] , & V_15 ) ;
if ( F_15 ( V_4 -> V_25 [ V_18 ] ) ) {
F_5 ( & V_11 -> V_2 , L_3 , V_13 -> V_27 ) ;
V_9 = F_16 ( V_4 -> V_25 [ V_18 ] ) ;
goto error;
}
}
F_17 ( V_11 , V_4 ) ;
return 0 ;
error:
while ( -- V_18 >= 0 )
F_18 ( V_4 -> V_25 [ V_18 ] ) ;
return V_9 ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_20 ( V_11 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 3 ; V_18 ++ )
F_18 ( V_4 -> V_25 [ V_18 ] ) ;
return 0 ;
}
static int T_1 F_21 ( void )
{
return F_22 ( & V_28 ) ;
}
static void T_2 F_23 ( void )
{
F_24 ( & V_28 ) ;
}
