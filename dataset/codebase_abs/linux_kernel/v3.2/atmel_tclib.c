struct V_1 * F_1 ( unsigned V_2 , const char * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 = NULL ;
struct V_7 * V_8 ;
F_2 ( & V_9 ) ;
F_3 (tc, &tc_list, node) {
if ( V_4 -> V_6 -> V_10 == V_2 ) {
V_6 = V_4 -> V_6 ;
break;
}
}
if ( ! V_6 || V_4 -> V_11 )
goto V_12;
V_8 = F_4 ( V_6 , V_13 , 0 ) ;
V_8 = F_5 ( V_8 -> V_14 , V_15 , V_3 ) ;
if ( ! V_8 )
goto V_12;
V_4 -> V_16 = F_6 ( V_8 -> V_14 , V_15 ) ;
if ( ! V_4 -> V_16 )
goto V_17;
V_4 -> V_11 = V_8 ;
V_18:
F_7 ( & V_9 ) ;
return V_4 ;
V_17:
F_8 ( V_8 -> V_14 , V_15 ) ;
V_12:
V_4 = NULL ;
goto V_18;
}
void F_9 ( struct V_1 * V_4 )
{
F_2 ( & V_9 ) ;
if ( V_4 -> V_16 ) {
F_10 ( V_4 -> V_16 ) ;
F_8 ( V_4 -> V_11 -> V_14 , V_15 ) ;
V_4 -> V_16 = NULL ;
V_4 -> V_11 = NULL ;
}
F_7 ( & V_9 ) ;
}
static int T_1 F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_4 ;
struct V_19 * V_19 ;
int V_20 ;
if ( ! F_4 ( V_6 , V_13 , 0 ) )
return - V_21 ;
V_20 = F_12 ( V_6 , 0 ) ;
if ( V_20 < 0 )
return - V_21 ;
V_4 = F_13 ( sizeof( struct V_1 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_6 = V_6 ;
V_19 = F_14 ( & V_6 -> V_24 , L_1 ) ;
if ( F_15 ( V_19 ) ) {
F_16 ( V_4 ) ;
return - V_21 ;
}
V_4 -> V_19 [ 0 ] = V_19 ;
V_4 -> V_19 [ 1 ] = F_14 ( & V_6 -> V_24 , L_2 ) ;
if ( F_15 ( V_4 -> V_19 [ 1 ] ) )
V_4 -> V_19 [ 1 ] = V_19 ;
V_4 -> V_19 [ 2 ] = F_14 ( & V_6 -> V_24 , L_3 ) ;
if ( F_15 ( V_4 -> V_19 [ 2 ] ) )
V_4 -> V_19 [ 2 ] = V_19 ;
V_4 -> V_20 [ 0 ] = V_20 ;
V_4 -> V_20 [ 1 ] = F_12 ( V_6 , 1 ) ;
if ( V_4 -> V_20 [ 1 ] < 0 )
V_4 -> V_20 [ 1 ] = V_20 ;
V_4 -> V_20 [ 2 ] = F_12 ( V_6 , 2 ) ;
if ( V_4 -> V_20 [ 2 ] < 0 )
V_4 -> V_20 [ 2 ] = V_20 ;
F_2 ( & V_9 ) ;
F_17 ( & V_4 -> V_25 , & V_26 ) ;
F_7 ( & V_9 ) ;
return 0 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_27 , F_11 ) ;
}
