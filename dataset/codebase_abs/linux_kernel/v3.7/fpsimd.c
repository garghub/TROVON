void F_1 ( unsigned int V_1 , struct V_2 * V_3 )
{
F_2 ( 1 ) ;
}
void F_3 ( unsigned int V_1 , struct V_2 * V_3 )
{
T_1 V_4 ;
unsigned int V_5 = 0 ;
if ( V_1 & V_6 )
V_5 = V_7 ;
else if ( V_1 & V_8 )
V_5 = V_9 ;
else if ( V_1 & V_10 )
V_5 = V_11 ;
else if ( V_1 & V_12 )
V_5 = V_13 ;
else if ( V_1 & V_14 )
V_5 = V_15 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_16 = V_17 ;
V_4 . V_5 = V_5 ;
V_4 . V_18 = ( void V_19 * ) F_4 ( V_3 ) ;
F_5 ( V_17 , & V_4 , V_20 ) ;
}
void F_6 ( struct V_21 * V_22 )
{
if ( V_20 -> V_23 )
F_7 ( & V_20 -> V_24 . V_25 ) ;
if ( V_22 -> V_23 )
F_8 ( & V_22 -> V_24 . V_25 ) ;
}
void F_9 ( void )
{
memset ( & V_20 -> V_24 . V_25 , 0 , sizeof( struct V_25 ) ) ;
F_8 ( & V_20 -> V_24 . V_25 ) ;
}
static int T_2 F_10 ( void )
{
T_3 V_26 = F_11 ( V_27 ) ;
if ( V_26 & ( 0xf << 16 ) ) {
F_12 ( L_1 ) ;
return 0 ;
}
V_28 |= V_29 ;
if ( V_26 & ( 0xf << 20 ) )
F_12 ( L_2 ) ;
else
V_28 |= V_30 ;
return 0 ;
}
