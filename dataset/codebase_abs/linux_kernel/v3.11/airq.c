int F_1 ( struct V_1 * V_2 )
{
char V_3 [ 32 ] ;
if ( ! V_2 -> V_4 || V_2 -> V_5 > V_6 )
return - V_7 ;
if ( ! V_2 -> V_8 ) {
V_2 -> V_8 = F_2 ( 1 , V_9 ) ;
if ( ! V_2 -> V_8 )
return - V_10 ;
V_2 -> V_11 |= V_12 ;
}
if ( ! V_2 -> V_13 )
V_2 -> V_13 = 0xff ;
snprintf ( V_3 , sizeof( V_3 ) , L_1 , V_2 ) ;
F_3 ( 4 , V_3 ) ;
F_4 ( V_2 -> V_5 ) ;
F_5 ( & V_14 ) ;
F_6 ( & V_2 -> V_15 , & V_16 [ V_2 -> V_5 ] ) ;
F_7 ( & V_14 ) ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
char V_3 [ 32 ] ;
if ( F_9 ( & V_2 -> V_15 ) )
return;
snprintf ( V_3 , sizeof( V_3 ) , L_2 , V_2 ) ;
F_3 ( 4 , V_3 ) ;
F_5 ( & V_14 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_7 ( & V_14 ) ;
F_11 () ;
F_12 ( V_2 -> V_5 ) ;
if ( V_2 -> V_11 & V_12 ) {
F_13 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_2 -> V_11 &= ~ V_12 ;
}
}
void F_14 ( T_1 V_5 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
V_18 = & V_16 [ V_5 ] ;
F_15 () ;
F_16 (airq, head, list)
if ( ( * V_2 -> V_8 & V_2 -> V_13 ) != 0 )
V_2 -> V_4 ( V_2 ) ;
F_17 () ;
}
