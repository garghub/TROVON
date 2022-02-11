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
struct V_16 * V_17 = V_11 -> V_2 . V_18 ;
struct V_3 * V_4 ;
int V_9 , V_19 ;
if ( ! F_10 ( V_11 -> V_20 , V_21 ) )
return - V_22 ;
V_4 = F_11 ( & V_11 -> V_2 , sizeof( struct V_3 ) , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
V_4 -> V_7 = V_11 ;
F_12 ( & V_4 -> V_6 ) ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ ) {
V_15 . V_2 = & V_11 -> V_2 ;
if ( V_19 == 0 )
V_15 . V_17 = V_17 ;
else
V_15 . V_17 = 0 ;
V_15 . V_25 = V_4 ;
V_4 -> V_26 [ V_19 ] = F_13 ( & V_27 [ V_19 ] , & V_15 ) ;
if ( F_14 ( V_4 -> V_26 [ V_19 ] ) ) {
F_5 ( & V_11 -> V_2 , L_3 , V_13 -> V_28 ) ;
V_9 = F_15 ( V_4 -> V_26 [ V_19 ] ) ;
goto error;
}
}
F_16 ( V_11 , V_4 ) ;
return 0 ;
error:
while ( -- V_19 >= 0 )
F_17 ( V_4 -> V_26 [ V_19 ] ) ;
return V_9 ;
}
static int F_18 ( struct V_10 * V_11 )
{
struct V_3 * V_4 = F_19 ( V_11 ) ;
int V_19 ;
for ( V_19 = 0 ; V_19 < 3 ; V_19 ++ )
F_17 ( V_4 -> V_26 [ V_19 ] ) ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_29 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_29 ) ;
}
