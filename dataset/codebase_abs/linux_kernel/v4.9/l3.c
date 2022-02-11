static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 8 ; V_4 ++ ) {
V_2 -> V_5 ( V_2 , 0 ) ;
F_2 ( V_2 -> V_6 ) ;
V_2 -> V_7 ( V_2 , V_3 & 1 ) ;
F_2 ( V_2 -> V_8 ) ;
V_2 -> V_5 ( V_2 , 1 ) ;
F_2 ( V_2 -> V_9 ) ;
V_3 >>= 1 ;
}
}
static void F_3 ( struct V_1 * V_2 , const T_1 * V_10 ,
int V_11 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
if ( V_4 ) {
F_2 ( V_2 -> V_12 ) ;
V_2 -> V_13 ( V_2 , 0 ) ;
F_2 ( V_2 -> V_14 ) ;
}
V_2 -> V_13 ( V_2 , 1 ) ;
F_2 ( V_2 -> V_15 ) ;
F_1 ( V_2 , V_10 [ V_4 ] ) ;
}
}
int F_4 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 , int V_11 )
{
V_2 -> V_5 ( V_2 , 1 ) ;
V_2 -> V_7 ( V_2 , 1 ) ;
V_2 -> V_13 ( V_2 , 1 ) ;
F_2 ( V_2 -> V_14 ) ;
V_2 -> V_13 ( V_2 , 0 ) ;
F_2 ( V_2 -> V_15 ) ;
F_1 ( V_2 , V_16 ) ;
F_2 ( V_2 -> V_12 ) ;
F_3 ( V_2 , V_17 , V_11 ) ;
V_2 -> V_5 ( V_2 , 1 ) ;
V_2 -> V_7 ( V_2 , 1 ) ;
V_2 -> V_13 ( V_2 , 0 ) ;
return V_11 ;
}
static void F_5 ( struct V_1 * V_2 , int V_18 )
{
F_6 ( V_2 -> V_19 , V_18 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_18 )
{
F_6 ( V_2 -> V_20 , V_18 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_18 )
{
F_6 ( V_2 -> V_21 , V_18 ) ;
}
int F_9 ( struct V_22 * V_23 , struct V_1 * V_2 )
{
int V_24 ;
if ( ! V_2 -> V_25 )
return - V_26 ;
V_24 = F_10 ( V_23 , V_2 -> V_20 ,
V_27 , L_1 ) ;
if ( V_24 < 0 )
return V_24 ;
V_2 -> V_7 = F_7 ;
V_24 = F_10 ( V_23 , V_2 -> V_19 ,
V_27 , L_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_2 -> V_5 = F_5 ;
V_24 = F_10 ( V_23 , V_2 -> V_21 ,
V_27 , L_3 ) ;
if ( V_24 < 0 )
return V_24 ;
V_2 -> V_13 = F_8 ;
return 0 ;
}
