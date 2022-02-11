static unsigned int F_1 ( unsigned int V_1 )
{
return ( F_2 ( & F_3 ( V_2 , V_1 ) ) + 500 ) / 1000 ;
}
static int F_4 ( struct V_3 * V_4 ,
unsigned int V_5 ,
unsigned int V_6 )
{
unsigned int V_1 = V_4 -> V_1 ;
struct V_7 * V_8 = & F_3 ( V_2 , V_1 ) ;
T_1 V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
long V_14 ;
V_9 = V_15 -> V_9 ;
F_5 ( V_15 , F_6 ( V_1 ) ) ;
F_7 ( F_8 () != V_1 ) ;
V_13 = F_9 ( V_1 ) ;
V_14 = F_10 ( V_8 , V_5 * 1000 ) ;
if ( V_14 < ( V_4 -> V_16 * 1000 ) || V_14 > ( V_4 -> V_17 * 1000 ) )
return - V_18 ;
F_11 ( V_13 , L_1 , V_5 * 1000 ) ;
V_11 . V_19 = F_1 ( V_1 ) ;
V_11 . V_20 = ( V_14 + 500 ) / 1000 ;
V_11 . V_21 = 0 ;
F_12 ( V_4 , & V_11 ) ;
F_5 ( V_15 , & V_9 ) ;
F_13 ( V_8 , V_14 ) ;
F_14 ( V_4 , & V_11 , 0 ) ;
F_11 ( V_13 , L_2 , V_14 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_7 * V_8 = & F_3 ( V_2 , V_4 -> V_1 ) ;
struct V_22 * V_23 ;
V_23 = V_8 -> V_24 ? V_8 -> V_23 : NULL ;
if ( V_23 )
return F_16 ( V_4 , V_23 ) ;
F_17 ( V_4 ) ;
V_4 -> V_16 = ( F_10 ( V_8 , 1 ) + 500 ) / 1000 ;
V_4 -> V_17 = ( F_10 ( V_8 , ~ 0UL ) + 500 ) / 1000 ;
F_17 ( V_4 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
unsigned int V_1 = V_4 -> V_1 ;
struct V_7 * V_8 = & F_3 ( V_2 , V_1 ) ;
struct V_22 * V_23 ;
struct V_12 * V_13 ;
V_13 = F_9 ( V_1 ) ;
V_8 = F_19 ( V_13 , L_3 ) ;
if ( F_20 ( V_8 ) ) {
F_21 ( V_13 , L_4 ) ;
return F_22 ( V_8 ) ;
}
V_23 = V_8 -> V_24 ? V_8 -> V_23 : NULL ;
if ( V_23 ) {
int V_25 ;
V_25 = F_23 ( V_4 , V_23 ) ;
if ( V_25 )
return V_25 ;
} else {
F_24 ( V_13 , L_5
L_6 ) ;
V_4 -> V_16 = V_4 -> V_26 . V_27 =
( F_10 ( V_8 , 1 ) + 500 ) / 1000 ;
V_4 -> V_17 = V_4 -> V_26 . V_28 =
( F_10 ( V_8 , ~ 0UL ) + 500 ) / 1000 ;
}
V_4 -> V_26 . V_29 = V_30 ;
F_25 ( V_13 , L_7
L_8 ,
V_4 -> V_16 / 1000 , V_4 -> V_16 % 1000 ,
V_4 -> V_17 / 1000 , V_4 -> V_17 % 1000 ) ;
return 0 ;
}
static int F_26 ( struct V_3 * V_4 )
{
unsigned int V_1 = V_4 -> V_1 ;
struct V_7 * V_8 = & F_3 ( V_2 , V_1 ) ;
F_27 ( V_8 ) ;
return 0 ;
}
static int T_2 F_28 ( void )
{
F_29 ( L_9 ) ;
return F_30 ( & V_31 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_31 ) ;
}
