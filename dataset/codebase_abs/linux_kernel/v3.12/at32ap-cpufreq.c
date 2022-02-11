static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != 0 )
return - V_4 ;
F_2 ( V_2 , V_2 -> V_5 . V_6 ,
V_2 -> V_5 . V_7 ) ;
return 0 ;
}
static unsigned int F_3 ( unsigned int V_3 )
{
if ( V_3 )
return 0 ;
return ( unsigned int ) ( ( F_4 ( V_8 ) + 500 ) / 1000 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_9 ,
unsigned int V_10 )
{
struct V_11 V_12 ;
long V_13 ;
V_13 = F_6 ( V_8 , V_9 * 1000 ) ;
if( V_13 < ( V_2 -> V_14 * 1000 ) || V_13 > ( V_2 -> V_15 * 1000 ) )
return - V_4 ;
F_7 ( L_1 , V_9 * 1000 ) ;
V_12 . V_16 = F_3 ( 0 ) ;
V_12 . V_17 = ( V_13 + 500 ) / 1000 ;
V_12 . V_18 = 0 ;
if ( ! V_19 ) {
V_19 = V_12 . V_16 ;
V_20 = V_21 . V_22 ;
}
F_8 ( V_2 , & V_12 , V_23 ) ;
if ( V_12 . V_16 < V_12 . V_17 )
V_21 . V_22 = F_9 (
V_20 , V_19 , V_12 . V_17 ) ;
F_10 ( V_8 , V_13 ) ;
if ( V_12 . V_17 < V_12 . V_16 )
V_21 . V_22 = F_9 (
V_20 , V_19 , V_12 . V_17 ) ;
F_8 ( V_2 , & V_12 , V_24 ) ;
F_7 ( L_2 , V_13 ) ;
return 0 ;
}
static int T_1 F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 != 0 )
return - V_4 ;
V_8 = F_12 ( NULL , L_3 ) ;
if ( F_13 ( V_8 ) ) {
F_7 ( L_4 ) ;
return F_14 ( V_8 ) ;
}
V_2 -> V_5 . V_6 = ( F_6 ( V_8 , 1 ) + 500 ) / 1000 ;
V_2 -> V_5 . V_7 = ( F_6 ( V_8 , ~ 0UL ) + 500 ) / 1000 ;
V_2 -> V_5 . V_25 = 0 ;
V_2 -> V_26 = F_3 ( 0 ) ;
V_2 -> V_14 = V_2 -> V_5 . V_6 ;
V_2 -> V_15 = V_2 -> V_5 . V_7 ;
F_15 ( L_5 ) ;
return 0 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_27 ) ;
}
