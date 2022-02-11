struct V_1 * F_1 ( unsigned V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 = NULL ;
F_2 ( & V_6 ) ;
F_3 (tc, &tc_list, node) {
if ( V_3 -> V_7 )
continue;
if ( ( V_3 -> V_5 -> V_8 . V_9 && V_3 -> V_10 == V_2 ) ||
( V_3 -> V_5 -> V_10 == V_2 ) ) {
V_5 = V_3 -> V_5 ;
V_3 -> V_7 = true ;
break;
}
}
F_4 ( & V_6 ) ;
return V_5 ? V_3 : NULL ;
}
void F_5 ( struct V_1 * V_3 )
{
F_2 ( & V_6 ) ;
if ( V_3 -> V_7 )
V_3 -> V_7 = false ;
F_4 ( & V_6 ) ;
}
static int T_1 F_6 ( struct V_4 * V_5 )
{
struct V_1 * V_3 ;
struct V_11 * V_11 ;
int V_12 ;
struct V_13 * V_14 ;
unsigned int V_15 ;
V_12 = F_7 ( V_5 , 0 ) ;
if ( V_12 < 0 )
return - V_16 ;
V_3 = F_8 ( & V_5 -> V_8 , sizeof( struct V_1 ) , V_17 ) ;
if ( ! V_3 )
return - V_18 ;
V_3 -> V_5 = V_5 ;
V_11 = F_9 ( & V_5 -> V_8 , L_1 ) ;
if ( F_10 ( V_11 ) )
return F_11 ( V_11 ) ;
V_14 = F_12 ( V_5 , V_19 , 0 ) ;
V_3 -> V_20 = F_13 ( & V_5 -> V_8 , V_14 ) ;
if ( F_10 ( V_3 -> V_20 ) )
return F_11 ( V_3 -> V_20 ) ;
if ( V_5 -> V_8 . V_9 ) {
const struct V_21 * V_22 ;
V_22 = F_14 ( V_23 , V_5 -> V_8 . V_9 ) ;
if ( V_22 )
V_3 -> V_24 = V_22 -> V_25 ;
V_3 -> V_10 = F_15 ( V_3 -> V_5 -> V_8 . V_9 , L_2 ) ;
} else {
V_3 -> V_10 = V_5 -> V_10 ;
}
V_3 -> V_11 [ 0 ] = V_11 ;
V_3 -> V_11 [ 1 ] = F_9 ( & V_5 -> V_8 , L_3 ) ;
if ( F_10 ( V_3 -> V_11 [ 1 ] ) )
V_3 -> V_11 [ 1 ] = V_11 ;
V_3 -> V_11 [ 2 ] = F_9 ( & V_5 -> V_8 , L_4 ) ;
if ( F_10 ( V_3 -> V_11 [ 2 ] ) )
V_3 -> V_11 [ 2 ] = V_11 ;
V_3 -> V_12 [ 0 ] = V_12 ;
V_3 -> V_12 [ 1 ] = F_7 ( V_5 , 1 ) ;
if ( V_3 -> V_12 [ 1 ] < 0 )
V_3 -> V_12 [ 1 ] = V_12 ;
V_3 -> V_12 [ 2 ] = F_7 ( V_5 , 2 ) ;
if ( V_3 -> V_12 [ 2 ] < 0 )
V_3 -> V_12 [ 2 ] = V_12 ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ )
F_16 ( V_26 , V_3 -> V_20 + F_17 ( V_15 , V_27 ) ) ;
F_2 ( & V_6 ) ;
F_18 ( & V_3 -> V_28 , & V_29 ) ;
F_4 ( & V_6 ) ;
F_19 ( V_5 , V_3 ) ;
return 0 ;
}
static void F_20 ( struct V_4 * V_5 )
{
int V_15 ;
struct V_1 * V_3 = F_21 ( V_5 ) ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ )
F_16 ( V_26 , V_3 -> V_20 + F_17 ( V_15 , V_27 ) ) ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_30 , F_6 ) ;
}
