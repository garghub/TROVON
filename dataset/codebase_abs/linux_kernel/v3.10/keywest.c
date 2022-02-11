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
if ( ! V_5 -> V_2 -> V_15 ) {
F_6 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
return - V_14 ;
}
F_7 ( & V_5 -> V_2 -> V_16 ,
& V_5 -> V_2 -> V_15 -> V_17 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
if ( ! V_5 )
return 0 ;
if ( V_2 == V_5 -> V_2 )
V_5 -> V_2 = NULL ;
return 0 ;
}
void F_9 ( struct V_18 * V_19 )
{
if ( V_5 && V_5 == V_19 ) {
F_10 ( & V_20 ) ;
V_5 = NULL ;
}
}
int F_11 ( void )
{
int V_21 ;
if ( ! V_5 || ! V_5 -> V_2 )
return - V_22 ;
if ( ( V_21 = V_5 -> V_23 ( V_5 ) ) < 0 ) {
F_12 ( V_24 L_3 , V_21 ) ;
return V_21 ;
}
return 0 ;
}
int F_13 ( struct V_18 * V_19 )
{
int V_21 ;
if ( V_5 )
return - V_25 ;
V_5 = V_19 ;
if ( ( V_21 = F_14 ( & V_20 ) ) ) {
F_12 ( V_24 L_4 ) ;
return V_21 ;
}
return 0 ;
}
