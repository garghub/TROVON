static unsigned int F_1 ( unsigned int V_1 )
{
return ( F_2 ( & F_3 ( V_2 , V_1 ) ) + 500 ) / 1000 ;
}
static long F_4 ( void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_1 = V_7 -> V_1 ;
struct V_8 * V_9 = & F_3 ( V_2 , V_1 ) ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
long V_14 ;
if ( F_5 () != V_1 )
return - V_15 ;
V_13 = F_6 ( V_1 ) ;
V_14 = F_7 ( V_9 , V_5 -> V_14 * 1000 ) ;
if ( V_14 < ( V_7 -> V_16 * 1000 ) || V_14 > ( V_7 -> V_17 * 1000 ) )
return - V_18 ;
F_8 ( V_13 , L_1 , V_5 -> V_14 * 1000 ) ;
V_11 . V_19 = F_1 ( V_1 ) ;
V_11 . V_20 = ( V_14 + 500 ) / 1000 ;
V_11 . V_21 = 0 ;
F_9 ( V_5 -> V_7 , & V_11 ) ;
F_10 ( V_9 , V_14 ) ;
F_11 ( V_5 -> V_7 , & V_11 , 0 ) ;
F_8 ( V_13 , L_2 , V_14 ) ;
return 0 ;
}
static int F_12 ( struct V_6 * V_7 ,
unsigned int V_22 ,
unsigned int V_23 )
{
struct V_4 V_24 = { . V_7 = V_7 , . V_14 = V_22 } ;
return F_13 ( V_7 -> V_1 , F_4 , & V_24 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & F_3 ( V_2 , V_7 -> V_1 ) ;
struct V_25 * V_26 ;
V_26 = V_9 -> V_27 ? V_9 -> V_26 : NULL ;
if ( V_26 )
return F_15 ( V_7 , V_26 ) ;
F_16 ( V_7 ) ;
V_7 -> V_16 = ( F_7 ( V_9 , 1 ) + 500 ) / 1000 ;
V_7 -> V_17 = ( F_7 ( V_9 , ~ 0UL ) + 500 ) / 1000 ;
F_16 ( V_7 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 )
{
unsigned int V_1 = V_7 -> V_1 ;
struct V_8 * V_9 = & F_3 ( V_2 , V_1 ) ;
struct V_25 * V_26 ;
struct V_12 * V_13 ;
V_13 = F_6 ( V_1 ) ;
V_9 = F_18 ( V_13 , L_3 ) ;
if ( F_19 ( V_9 ) ) {
F_20 ( V_13 , L_4 ) ;
return F_21 ( V_9 ) ;
}
V_26 = V_9 -> V_27 ? V_9 -> V_26 : NULL ;
if ( V_26 ) {
int V_28 ;
V_28 = F_22 ( V_7 , V_26 ) ;
if ( V_28 )
return V_28 ;
} else {
F_23 ( V_13 , L_5
L_6 ) ;
V_7 -> V_16 = V_7 -> V_29 . V_30 =
( F_7 ( V_9 , 1 ) + 500 ) / 1000 ;
V_7 -> V_17 = V_7 -> V_29 . V_31 =
( F_7 ( V_9 , ~ 0UL ) + 500 ) / 1000 ;
}
F_24 ( V_13 , L_7
L_8 ,
V_7 -> V_16 / 1000 , V_7 -> V_16 % 1000 ,
V_7 -> V_17 / 1000 , V_7 -> V_17 % 1000 ) ;
return 0 ;
}
static int F_25 ( struct V_6 * V_7 )
{
unsigned int V_1 = V_7 -> V_1 ;
struct V_8 * V_9 = & F_3 ( V_2 , V_1 ) ;
F_26 ( V_9 ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
F_28 ( L_9 ) ;
return F_29 ( & V_32 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_32 ) ;
}
