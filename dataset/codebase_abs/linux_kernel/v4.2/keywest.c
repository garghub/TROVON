static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
V_5 = true ;
if ( ! V_6 -> V_2 )
V_6 -> V_2 = V_2 ;
F_2 ( V_2 , V_6 ) ;
return 0 ;
}
static int F_3 ( struct V_7 * V_8 )
{
struct V_9 V_10 ;
if ( ! V_6 )
return - V_11 ;
if ( strncmp ( V_8 -> V_12 , L_1 , 6 ) )
return - V_11 ;
memset ( & V_10 , 0 , sizeof( struct V_9 ) ) ;
F_4 ( V_10 . type , L_2 , V_13 ) ;
V_10 . V_14 = V_6 -> V_14 ;
V_6 -> V_2 = F_5 ( V_8 , & V_10 ) ;
if ( ! V_6 -> V_2 )
return - V_15 ;
if ( ! V_6 -> V_2 -> V_16 . V_17 ) {
F_6 ( V_6 -> V_2 ) ;
V_6 -> V_2 = NULL ;
return - V_15 ;
}
F_7 ( & V_6 -> V_2 -> V_18 ,
& F_8 ( V_6 -> V_2 -> V_16 . V_17 ) -> V_19 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
if ( ! V_6 )
return 0 ;
if ( V_2 == V_6 -> V_2 )
V_6 -> V_2 = NULL ;
return 0 ;
}
void F_10 ( struct V_20 * V_21 )
{
if ( V_6 && V_6 == V_21 ) {
F_11 ( & V_22 ) ;
V_6 = NULL ;
}
}
int F_12 ( void )
{
int V_23 ;
if ( ! V_6 || ! V_6 -> V_2 )
return - V_24 ;
if ( ( V_23 = V_6 -> V_25 ( V_6 ) ) < 0 ) {
F_13 ( V_26 L_3 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
int F_14 ( struct V_20 * V_21 )
{
struct V_7 * V_27 ;
int V_23 , V_28 = 0 ;
if ( V_6 )
return - V_29 ;
V_27 = F_15 ( 0 ) ;
if ( ! V_27 )
return - V_30 ;
V_6 = V_21 ;
if ( ( V_23 = F_16 ( & V_22 ) ) ) {
F_13 ( V_26 L_4 ) ;
F_17 ( V_27 ) ;
return V_23 ;
}
if ( V_5 )
return 0 ;
while ( V_27 ) {
V_23 = F_3 ( V_27 ) ;
if ( ! V_23 )
return 0 ;
F_17 ( V_27 ) ;
V_27 = F_15 ( ++ V_28 ) ;
}
return - V_15 ;
}
