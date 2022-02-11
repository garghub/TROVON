static T_1 F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_4 * V_5 ;
for ( V_5 = V_6 ; V_5 && V_5 -> V_7 ; V_5 ++ ) {
if ( V_3 >= V_5 -> V_8 &&
V_3 < ( V_5 -> V_8 + V_5 -> V_7 ) )
return V_3 - V_5 -> V_8 + V_5 -> V_9 ;
}
return V_3 ;
}
T_1 F_2 ( struct V_1 * V_2 , void * V_10 , T_3 V_7 )
{
return F_1 ( V_2 , F_3 ( V_10 ) ) ;
}
T_1 F_4 ( struct V_1 * V_2 , struct V_11 * V_11 )
{
return F_1 ( V_2 , F_5 ( V_11 ) ) ;
}
unsigned long F_6 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_4 * V_5 ;
for ( V_5 = V_6 ; V_5 && V_5 -> V_7 ; V_5 ++ ) {
if ( V_12 >= V_5 -> V_9 &&
V_12 < ( V_5 -> V_9 + V_5 -> V_7 ) )
return V_12 - V_5 -> V_9 + V_5 -> V_8 ;
}
return V_12 ;
}
static int T_4 F_7 ( void )
{
struct V_13 * V_14 =
F_8 ( NULL , NULL , L_1 ) ;
const T_5 * V_15 ;
struct V_4 * V_5 ;
int V_16 ;
if ( ! V_14 )
return 0 ;
V_15 = F_9 ( V_14 , L_2 , & V_16 ) ;
if ( ! V_15 )
goto V_17;
V_16 /= sizeof( * V_15 ) * 3 ;
if ( ! V_16 )
goto V_18;
V_6 = F_10 ( sizeof( struct V_4 ) * ( V_16 + 1 ) ,
V_19 ) ;
if ( ! V_6 )
goto V_18;
for ( V_5 = V_6 ; V_16 ; V_16 -- , V_5 ++ ) {
V_5 -> V_8 = F_11 ( V_15 ++ ) ;
V_5 -> V_9 = F_11 ( V_15 ++ ) ;
V_5 -> V_7 = F_11 ( V_15 ++ ) ;
}
V_17:
F_12 ( V_14 ) ;
return 0 ;
V_18:
F_13 ( L_3 ) ;
F_12 ( V_14 ) ;
return - V_20 ;
}
