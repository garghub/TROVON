static int F_1 ( unsigned V_1 , unsigned V_2 , unsigned V_3 ,
unsigned V_4 , unsigned V_5 ,
struct V_6 * V_7 )
{
if ( V_1 > 255 )
return 1 ;
V_2 >>= 11 ;
V_3 >>= 11 ;
V_4 >>= 10 ;
if ( V_1 < 16 ) {
( ( V_8 * ) V_7 -> V_9 ) [ V_1 ] = ( ( V_2 & 31 ) << 6 ) |
( ( V_3 & 31 ) << 11 ) |
( V_4 & 63 ) ;
}
return 0 ;
}
static int F_2 ( struct V_10 * V_11 )
{
struct V_6 * V_7 ;
if ( ! V_12 )
return - V_13 ;
V_14 . V_15 = V_16 ;
V_7 = F_3 ( sizeof( V_8 ) * 16 , & V_11 -> V_11 ) ;
if ( ! V_7 )
return - V_17 ;
V_7 -> V_18 = V_19 ;
V_7 -> V_20 = V_14 ;
V_7 -> V_21 = & V_22 ;
V_7 -> V_23 = V_24 ;
V_7 -> V_9 = V_7 -> V_25 ;
V_7 -> V_25 = NULL ;
V_7 -> V_26 = ( char * ) V_14 . V_15 ;
if ( F_4 ( & V_7 -> V_27 , 256 , 0 ) < 0 ) {
F_5 ( V_7 ) ;
return - V_17 ;
}
F_6 ( 3 , V_28 ) ;
if ( F_7 ( V_7 ) < 0 ) {
F_8 ( V_29 L_1 ) ;
F_9 ( & V_7 -> V_27 ) ;
F_5 ( V_7 ) ;
return - V_30 ;
}
V_6 ( V_7 , L_2 ) ;
return 0 ;
}
int T_1 F_10 ( void )
{
int V_31 = 0 ;
if ( F_11 ( L_3 , NULL ) )
return - V_32 ;
V_31 = F_12 ( & V_33 ) ;
if ( ! V_31 ) {
V_31 = F_13 ( & V_34 ) ;
if ( V_31 )
F_14 ( & V_33 ) ;
}
return V_31 ;
}
