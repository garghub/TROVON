static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
F_2 ( V_2 , V_5 ) ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_8 V_9 ;
if ( ! V_5 )
return - V_10 ;
if ( strncmp ( V_7 -> V_11 , L_1 , 6 ) )
return 0 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
F_4 ( V_9 . type , L_2 , V_12 ) ;
V_9 . V_13 = V_5 -> V_13 ;
V_5 -> V_2 = F_5 ( V_7 , & V_9 ) ;
if ( ! V_5 -> V_2 )
return - V_14 ;
if ( ! V_5 -> V_2 -> V_15 . V_16 ) {
F_6 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
return - V_14 ;
}
F_7 ( & V_5 -> V_2 -> V_17 ,
& F_8 ( V_5 -> V_2 -> V_15 . V_16 ) -> V_18 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( ! V_5 )
return 0 ;
if ( V_2 == V_5 -> V_2 )
V_5 -> V_2 = NULL ;
return 0 ;
}
void F_10 ( struct V_19 * V_20 )
{
if ( V_5 && V_5 == V_20 ) {
F_11 ( & V_21 ) ;
V_5 = NULL ;
}
}
int F_12 ( void )
{
int V_22 ;
if ( ! V_5 || ! V_5 -> V_2 )
return - V_23 ;
if ( ( V_22 = V_5 -> V_24 ( V_5 ) ) < 0 ) {
F_13 ( V_25 L_3 , V_22 ) ;
return V_22 ;
}
return 0 ;
}
int F_14 ( struct V_19 * V_20 )
{
int V_22 ;
if ( V_5 )
return - V_26 ;
V_5 = V_20 ;
if ( ( V_22 = F_15 ( & V_21 ) ) ) {
F_13 ( V_25 L_4 ) ;
return V_22 ;
}
return 0 ;
}
