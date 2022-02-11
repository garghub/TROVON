static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 -> V_12 ) ;
int V_13 ;
if ( V_3 != 0 )
return V_14 ;
F_3 ( 1 , V_11 -> V_15 + V_16 ) ;
V_13 = F_4 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( 0 , V_11 -> V_15 + V_16 ) ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_5 , T_1 V_6 )
{
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = F_2 ( V_8 -> V_12 ) ;
int V_13 ;
F_3 ( 1 , V_11 -> V_15 + V_16 ) ;
V_13 = F_6 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
F_3 ( 0 , V_11 -> V_15 + V_16 ) ;
return V_13 ;
}
static int F_7 ( struct V_10 * V_11 )
{
void T_2 * V_17 = V_11 -> V_15 + V_18 ;
int V_19 ;
F_3 ( 16 , V_17 ) ;
for ( V_19 = 0 ; V_19 < 10 ; ++ V_19 ) {
T_1 V_20 = F_8 ( V_17 ) >> 8 ;
if ( ( V_20 & 0x1f ) == 0xf )
return 1 ;
F_9 ( 3000 , 4000 ) ;
}
return 0 ;
}
static int F_10 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = & V_22 -> V_24 ;
struct V_10 * V_11 ;
struct V_25 * V_26 ;
int V_13 ;
F_11 ( V_24 , L_1 ) ;
F_12 ( V_27 , V_28 ) ;
V_11 = F_13 ( V_24 , sizeof( * V_11 ) , V_29 ) ;
if ( ! V_11 )
return - V_30 ;
V_26 = F_14 ( V_22 , V_31 , 1 ) ;
V_11 -> V_15 = F_15 ( V_24 , V_26 ) ;
if ( F_16 ( V_11 -> V_15 ) )
return F_17 ( V_11 -> V_15 ) ;
F_18 ( V_22 , V_11 ) ;
if ( ! F_7 ( V_11 ) )
return - V_32 ;
return F_19 ( V_22 , & V_33 ) ;
}
static void F_20 ( struct V_34 * V_24 )
{
V_24 -> V_35 = V_36 << 8 ;
}
static void F_21 ( struct V_34 * V_24 )
{
V_24 -> V_37 = true ;
F_22 ( V_24 , V_38 , 0x80000000 ) ;
}
