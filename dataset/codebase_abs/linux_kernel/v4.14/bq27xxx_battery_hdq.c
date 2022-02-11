static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_4 ;
F_2 ( & V_2 -> V_5 -> V_6 ) ;
F_3 ( V_2 -> V_5 , V_7 | V_3 ) ;
V_4 = F_4 ( V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_5 -> V_6 ) ;
return V_4 ;
}
static int F_6 ( struct V_8 * V_9 , T_1 V_3 ,
bool V_10 )
{
struct V_1 * V_2 = F_7 ( V_9 -> V_11 ) ;
unsigned int V_12 = 3 ;
int V_13 , V_14 ;
int V_15 ;
if ( ! V_10 ) {
V_13 = F_1 ( V_2 , V_3 + 1 ) ;
do {
V_15 = V_13 ;
if ( V_13 < 0 )
return V_13 ;
V_14 = F_1 ( V_2 , V_3 ) ;
if ( V_14 < 0 )
return V_14 ;
V_13 = F_1 ( V_2 , V_3 + 1 ) ;
} while ( V_15 != V_13 && -- V_12 );
if ( V_12 == 0 )
return - V_16 ;
return ( V_13 << 8 ) | V_14 ;
}
return F_1 ( V_2 , V_3 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_9 ( & V_2 -> V_11 , sizeof( * V_9 ) , V_17 ) ;
if ( ! V_9 )
return - V_18 ;
F_10 ( & V_2 -> V_11 , V_9 ) ;
V_9 -> V_11 = & V_2 -> V_11 ;
V_9 -> V_19 = V_20 ;
V_9 -> V_21 = L_1 ;
V_9 -> V_22 . V_23 = F_6 ;
return F_11 ( V_9 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_13 ( & V_2 -> V_11 ) ;
F_14 ( V_9 ) ;
}
static int T_2 F_15 ( void )
{
if ( V_24 )
V_25 . V_26 = V_24 ;
return F_16 ( & V_25 ) ;
}
static void T_3 F_17 ( void )
{
F_18 ( & V_25 ) ;
}
