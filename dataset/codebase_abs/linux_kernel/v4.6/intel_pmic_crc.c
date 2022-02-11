static int F_1 ( struct V_1 * V_1 , int V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
* V_4 = ( V_5 & V_7 ) && ( V_5 & F_3 ( V_3 ) ) ? 1 : 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int V_2 ,
int V_3 , bool V_8 )
{
int V_5 ;
if ( F_2 ( V_1 , V_2 , & V_5 ) )
return - V_6 ;
if ( V_8 ) {
V_5 |= V_7 | F_3 ( V_3 ) ;
} else {
V_5 &= ~ F_3 ( V_3 ) ;
V_5 |= V_7 ;
}
if ( F_5 ( V_1 , V_2 , V_5 ) )
return - V_6 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , int V_2 )
{
int V_9 , V_10 ;
if ( F_2 ( V_1 , V_2 , & V_9 ) ||
F_2 ( V_1 , V_2 - 1 , & V_10 ) )
return - V_6 ;
return V_9 | ( V_10 & 0x3 ) << 8 ;
}
static int F_7 ( struct V_1 * V_1 , int V_2 , int V_11 )
{
return F_5 ( V_1 , V_2 , V_11 ) ||
F_8 ( V_1 , V_2 - 1 , 0x3 , V_11 >> 8 ) ? - V_6 : 0 ;
}
static int F_9 ( struct V_1 * V_1 , int V_2 , T_1 * V_4 )
{
int V_12 ;
if ( F_2 ( V_1 , V_2 , & V_12 ) )
return - V_6 ;
* V_4 = V_12 >> 7 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 ,
int V_2 , int V_13 )
{
int V_14 ;
if ( F_2 ( V_1 , V_15 , & V_14 ) )
return - V_6 ;
if ( F_8 ( V_1 , V_15 , 0x01 , 0 ) )
return - V_6 ;
if ( F_8 ( V_1 , V_2 , 0x80 , V_13 << 7 ) )
return - V_6 ;
if ( F_5 ( V_1 , V_15 , V_14 ) )
return - V_6 ;
return 0 ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_12 ( V_17 -> V_20 . V_21 ) ;
return F_13 ( & V_17 -> V_20 ,
F_14 ( V_17 -> V_20 . V_21 ) , V_19 -> V_1 ,
& V_22 ) ;
}
static int T_2 F_15 ( void )
{
return F_16 ( & V_23 ) ;
}
