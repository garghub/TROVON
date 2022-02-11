static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
if ( V_5 -> V_7 == NULL )
return - V_8 ;
V_6 = F_3 ( V_5 -> V_7 , V_9 ) ;
if ( V_6 < 0 )
return V_6 ;
* V_3 = V_6 << 16 ;
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_5 ( V_5 ) ;
}
static int F_6 ( struct V_10 * V_11 ,
const struct V_12 * V_13 )
{
const char * V_14 , * V_15 ;
struct V_4 * V_5 ;
int V_16 ;
V_15 = F_7 ( V_11 -> V_17 . V_18 , L_1 , NULL ) ;
if ( ! V_15 ) {
F_8 ( & V_11 -> V_17 , L_2 ) ;
return - V_19 ;
}
if ( ! strcmp ( V_15 , L_3 ) || ! strcmp ( V_15 , L_4 ) )
V_14 = L_5 ;
else if ( ! strcmp ( V_15 , L_6 ) )
V_14 = L_7 ;
else if ( ! strcmp ( V_15 , L_8 ) )
V_14 = L_9 ;
else
return - V_19 ;
V_5 = F_9 ( sizeof( struct V_4 ) , V_20 ) ;
if ( V_5 == NULL ) {
F_10 ( V_21 L_10
L_11 ) ;
return - V_22 ;
}
V_5 -> V_7 = V_11 ;
V_5 -> V_23 . V_14 = V_14 ;
V_5 -> V_23 . V_24 = & V_25 ;
F_11 ( V_11 , V_5 ) ;
V_16 = F_12 ( & V_5 -> V_23 ) ;
if ( V_16 )
F_5 ( V_5 ) ;
return V_16 ;
}
static int F_13 ( struct V_10 * V_11 )
{
struct V_4 * V_5 = F_14 ( V_11 ) ;
V_5 -> V_7 = NULL ;
F_15 ( & V_5 -> V_23 ) ;
return 0 ;
}
