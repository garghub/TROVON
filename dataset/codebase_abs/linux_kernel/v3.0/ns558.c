static int F_1 ( int V_1 )
{
int V_2 , V_3 , V_4 ;
unsigned char V_5 , V_6 , V_7 ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
if ( ! F_2 ( V_1 , 1 , L_1 ) )
return - V_11 ;
V_5 = F_3 ( V_1 ) ;
F_4 ( ~ V_5 & ~ 3 , V_1 ) ;
if ( ~ ( V_6 = V_7 = F_3 ( V_1 ) ) & 3 ) {
F_4 ( V_5 , V_1 ) ;
F_5 ( V_1 , 1 ) ;
return - V_12 ;
}
for ( V_2 = 0 ; V_2 < 1000 ; V_2 ++ ) V_7 &= F_3 ( V_1 ) ;
if ( V_6 == V_7 ) {
F_4 ( V_5 , V_1 ) ;
F_5 ( V_1 , 1 ) ;
return - V_12 ;
}
F_6 ( 3 ) ;
V_6 = F_3 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < 1000 ; V_2 ++ )
if ( ( V_6 ^ F_3 ( V_1 ) ) & 0xf ) {
F_4 ( V_5 , V_1 ) ;
F_5 ( V_1 , 1 ) ;
return - V_12 ;
}
for ( V_2 = 1 ; V_2 < 5 ; V_2 ++ ) {
F_5 ( V_1 & ( - 1 << ( V_2 - 1 ) ) , ( 1 << ( V_2 - 1 ) ) ) ;
if ( ! F_2 ( V_1 & ( - 1 << V_2 ) , ( 1 << V_2 ) , L_1 ) )
break;
F_4 ( 0xff , V_1 & ( - 1 << V_2 ) ) ;
for ( V_3 = V_4 = 0 ; V_3 < 1000 ; V_3 ++ )
if ( F_3 ( V_1 & ( - 1 << V_2 ) ) != F_3 ( ( V_1 & ( - 1 << V_2 ) ) + ( 1 << V_2 ) - 1 ) ) V_4 ++ ;
F_6 ( 3 ) ;
if ( V_4 > 300 ) {
F_5 ( V_1 & ( - 1 << V_2 ) , ( 1 << V_2 ) ) ;
break;
}
}
V_2 -- ;
if ( V_2 != 4 ) {
if ( ! F_2 ( V_1 & ( - 1 << V_2 ) , ( 1 << V_2 ) , L_1 ) )
return - V_11 ;
}
V_8 = F_7 ( sizeof( struct V_8 ) , V_13 ) ;
V_10 = F_8 () ;
if ( ! V_8 || ! V_10 ) {
F_9 ( V_14 L_2 ) ;
F_5 ( V_1 & ( - 1 << V_2 ) , ( 1 << V_2 ) ) ;
F_10 ( V_8 ) ;
F_11 ( V_10 ) ;
return - V_15 ;
}
V_8 -> V_1 = V_1 ;
V_8 -> V_16 = 1 << V_2 ;
V_8 -> V_9 = V_10 ;
V_10 -> V_1 = V_1 ;
F_12 ( V_10 , L_3 ) ;
F_13 ( V_10 , L_4 , V_1 & ( - 1 << V_2 ) ) ;
F_14 ( V_10 ) ;
F_15 ( & V_8 -> V_17 , & V_18 ) ;
return 0 ;
}
static int F_16 ( struct V_19 * V_20 , const struct V_21 * V_22 )
{
int V_23 , V_24 ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
if ( ! F_17 ( V_20 , 0 ) ) {
F_9 ( V_25 L_5 ) ;
return - V_12 ;
}
V_23 = F_18 ( V_20 , 0 ) ;
V_24 = F_19 ( V_20 , 0 ) ;
if ( ! F_2 ( V_23 , V_24 , L_6 ) )
return - V_11 ;
V_8 = F_7 ( sizeof( struct V_8 ) , V_13 ) ;
V_10 = F_8 () ;
if ( ! V_8 || ! V_10 ) {
F_9 ( V_14 L_7 ) ;
F_10 ( V_8 ) ;
F_11 ( V_10 ) ;
return - V_15 ;
}
V_8 -> V_1 = V_23 ;
V_8 -> V_16 = V_24 ;
V_8 -> V_20 = V_20 ;
V_8 -> V_9 = V_10 ;
F_12 ( V_10 , L_8 ) ;
F_13 ( V_10 , L_9 , F_20 ( & V_20 -> V_20 ) ) ;
V_10 -> V_20 . V_26 = & V_20 -> V_20 ;
V_10 -> V_1 = V_23 ;
F_14 ( V_10 ) ;
F_21 ( & V_8 -> V_17 , & V_18 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
int V_2 = 0 ;
int error ;
error = F_23 ( & V_27 ) ;
if ( error && error != - V_12 )
return error ;
while ( V_28 [ V_2 ] )
F_1 ( V_28 [ V_2 ++ ] ) ;
return F_24 ( & V_18 ) && error ? - V_12 : 0 ;
}
static void T_2 F_25 ( void )
{
struct V_8 * V_8 , * V_29 ;
F_26 (ns558, safe, &ns558_list, node) {
F_27 ( V_8 -> V_9 ) ;
F_5 ( V_8 -> V_1 & ~ ( V_8 -> V_16 - 1 ) , V_8 -> V_16 ) ;
F_10 ( V_8 ) ;
}
F_28 ( & V_27 ) ;
}
