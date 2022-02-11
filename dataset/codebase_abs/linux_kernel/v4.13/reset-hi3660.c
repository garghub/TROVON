static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , bool assert )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 = V_3 >> 8 ;
unsigned int V_7 = F_3 ( V_3 & 0x1f ) ;
if ( assert )
return F_4 ( V_5 -> V_8 , V_6 , V_7 ) ;
else
return F_4 ( V_5 -> V_8 , V_6 + 4 , V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , true ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return F_1 ( V_2 , V_3 , false ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
int V_9 ;
V_9 = F_5 ( V_2 , V_3 ) ;
if ( V_9 )
return V_9 ;
return F_6 ( V_2 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
unsigned int V_6 , V_12 ;
V_6 = V_11 -> args [ 0 ] ;
V_12 = V_11 -> args [ 1 ] ;
return ( V_6 << 8 ) | V_12 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_4 * V_5 ;
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
struct V_19 * V_17 = & V_14 -> V_17 ;
V_5 = F_10 ( V_17 , sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 )
return - V_21 ;
V_5 -> V_8 = F_11 ( V_16 , L_1 ) ;
if ( F_12 ( V_5 -> V_8 ) ) {
F_13 ( V_17 , L_2 ) ;
return F_14 ( V_5 -> V_8 ) ;
}
V_5 -> V_22 . V_23 = & V_24 ,
V_5 -> V_22 . V_18 = V_16 ;
V_5 -> V_22 . V_25 = 2 ;
V_5 -> V_22 . V_26 = F_8 ;
return F_15 ( & V_5 -> V_22 ) ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_27 ) ;
}
