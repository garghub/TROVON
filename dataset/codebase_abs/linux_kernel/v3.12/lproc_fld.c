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
F_9 ( struct V_12 * V_12 , const char * V_13 ,
T_2 V_14 , T_3 * V_15 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_12 -> V_16 ) -> V_6 ;
struct V_17 * V_18 = NULL ;
int V_19 ;
F_2 ( V_5 != NULL ) ;
for ( V_19 = 0 ; V_20 [ V_19 ] . V_11 != NULL ; V_19 ++ ) {
if ( V_14 != strlen ( V_20 [ V_19 ] . V_11 ) )
continue;
if ( ! strncmp ( V_20 [ V_19 ] . V_11 , V_13 , V_14 ) ) {
V_18 = & V_20 [ V_19 ] ;
break;
}
}
if ( V_18 != NULL ) {
F_3 ( & V_5 -> V_9 ) ;
V_5 -> V_10 = V_18 ;
F_7 ( & V_5 -> V_9 ) ;
F_10 ( V_21 , L_2 ,
V_5 -> V_22 , V_18 -> V_11 ) ;
}
return V_14 ;
}
static T_1
F_11 ( struct V_12 * V_12 , const char T_4 * V_13 ,
T_2 V_14 , T_3 * V_23 )
{
struct V_4 * V_5 = V_12 -> V_16 ;
F_2 ( V_5 != NULL ) ;
F_12 ( V_5 -> V_24 ) ;
F_10 ( V_21 , L_3 , V_5 -> V_22 ) ;
return V_14 ;
}
static int F_13 ( struct V_25 * V_25 , struct V_12 * V_12 )
{
V_12 -> V_16 = F_14 ( V_25 ) ;
return 0 ;
}
static int F_15 ( struct V_25 * V_25 , struct V_12 * V_12 )
{
V_12 -> V_16 = NULL ;
return 0 ;
}
