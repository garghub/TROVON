static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 ;
F_2 ( V_5 != NULL ) ;
F_3 ( & V_5 -> V_9 ) ;
F_4 (target,
&fld->lcf_targets, ft_chain)
F_5 ( V_2 , L_1 , F_6 ( V_8 ) ) ;
F_7 ( & V_5 -> V_9 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
F_2 ( V_5 != NULL ) ;
F_3 ( & V_5 -> V_9 ) ;
F_5 ( V_2 , L_1 , V_5 -> V_10 -> V_11 ) ;
F_7 ( & V_5 -> V_9 ) ;
return 0 ;
}
static T_1
F_9 ( struct V_12 * V_12 ,
const char T_2 * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
struct V_4 * V_5 ;
struct V_16 * V_17 = NULL ;
char V_11 [ 8 ] ;
int V_18 ;
if ( V_14 > sizeof( V_11 ) )
return - V_19 ;
if ( F_10 ( V_11 , V_13 , V_14 ) != 0 )
return - V_20 ;
V_5 = ( (struct V_1 * ) V_12 -> V_21 ) -> V_6 ;
F_2 ( V_5 != NULL ) ;
for ( V_18 = 0 ; V_22 [ V_18 ] . V_11 != NULL ; V_18 ++ ) {
if ( V_14 != strlen ( V_22 [ V_18 ] . V_11 ) )
continue;
if ( ! strncmp ( V_22 [ V_18 ] . V_11 , V_11 , V_14 ) ) {
V_17 = & V_22 [ V_18 ] ;
break;
}
}
if ( V_17 != NULL ) {
F_3 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = V_17 ;
F_7 ( & V_5 -> V_9 ) ;
F_11 ( V_23 , L_2 ,
V_5 -> V_24 , V_17 -> V_11 ) ;
}
return V_14 ;
}
static T_1
F_12 ( struct V_12 * V_12 , const char T_2 * V_13 ,
T_3 V_14 , T_4 * V_25 )
{
struct V_4 * V_5 = V_12 -> V_21 ;
F_2 ( V_5 != NULL ) ;
F_13 ( V_5 -> V_26 ) ;
F_11 ( V_23 , L_3 , V_5 -> V_24 ) ;
return V_14 ;
}
static int
F_14 ( struct V_27 * V_27 , struct V_12 * V_12 )
{
V_12 -> V_21 = NULL ;
return 0 ;
}
