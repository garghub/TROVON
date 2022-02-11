struct V_1 * F_1 ( unsigned V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
T_1 V_9 ;
F_2 ( & V_10 ) ;
F_3 (tc, &tc_list, node) {
if ( V_4 -> V_6 -> V_11 . V_12 ) {
if ( F_4 ( V_4 -> V_6 -> V_11 . V_12 , L_1 )
== V_2 ) {
V_6 = V_4 -> V_6 ;
break;
}
} else if ( V_4 -> V_6 -> V_13 == V_2 ) {
V_6 = V_4 -> V_6 ;
break;
}
}
if ( ! V_6 || V_4 -> V_14 )
goto V_15;
V_8 = F_5 ( V_6 , V_16 , 0 ) ;
if ( ! V_8 )
goto V_15;
V_9 = F_6 ( V_8 ) ;
V_8 = F_7 ( V_8 -> V_17 , V_9 , V_3 ) ;
if ( ! V_8 )
goto V_15;
V_4 -> V_18 = F_8 ( V_8 -> V_17 , V_9 ) ;
if ( ! V_4 -> V_18 )
goto V_19;
V_4 -> V_14 = V_8 ;
V_20:
F_9 ( & V_10 ) ;
return V_4 ;
V_19:
F_10 ( V_8 -> V_17 , V_9 ) ;
V_15:
V_4 = NULL ;
goto V_20;
}
void F_11 ( struct V_1 * V_4 )
{
F_2 ( & V_10 ) ;
if ( V_4 -> V_18 ) {
F_12 ( V_4 -> V_18 ) ;
F_10 ( V_4 -> V_14 -> V_17 , F_6 ( V_4 -> V_14 ) ) ;
V_4 -> V_18 = NULL ;
V_4 -> V_14 = NULL ;
}
F_9 ( & V_10 ) ;
}
static int T_2 F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
struct V_21 * V_21 ;
int V_22 ;
if ( ! F_5 ( V_6 , V_16 , 0 ) )
return - V_23 ;
V_22 = F_14 ( V_6 , 0 ) ;
if ( V_22 < 0 )
return - V_23 ;
V_4 = F_15 ( sizeof( struct V_1 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_4 -> V_6 = V_6 ;
V_21 = F_16 ( & V_6 -> V_11 , L_2 ) ;
if ( F_17 ( V_21 ) ) {
F_18 ( V_4 ) ;
return - V_23 ;
}
if ( V_6 -> V_11 . V_12 ) {
const struct V_26 * V_27 ;
V_27 = F_19 ( V_28 , V_6 -> V_11 . V_12 ) ;
if ( V_27 )
V_4 -> V_29 = V_27 -> V_30 ;
}
V_4 -> V_21 [ 0 ] = V_21 ;
V_4 -> V_21 [ 1 ] = F_16 ( & V_6 -> V_11 , L_3 ) ;
if ( F_17 ( V_4 -> V_21 [ 1 ] ) )
V_4 -> V_21 [ 1 ] = V_21 ;
V_4 -> V_21 [ 2 ] = F_16 ( & V_6 -> V_11 , L_4 ) ;
if ( F_17 ( V_4 -> V_21 [ 2 ] ) )
V_4 -> V_21 [ 2 ] = V_21 ;
V_4 -> V_22 [ 0 ] = V_22 ;
V_4 -> V_22 [ 1 ] = F_14 ( V_6 , 1 ) ;
if ( V_4 -> V_22 [ 1 ] < 0 )
V_4 -> V_22 [ 1 ] = V_22 ;
V_4 -> V_22 [ 2 ] = F_14 ( V_6 , 2 ) ;
if ( V_4 -> V_22 [ 2 ] < 0 )
V_4 -> V_22 [ 2 ] = V_22 ;
F_2 ( & V_10 ) ;
F_20 ( & V_4 -> V_31 , & V_32 ) ;
F_9 ( & V_10 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_33 , F_13 ) ;
}
