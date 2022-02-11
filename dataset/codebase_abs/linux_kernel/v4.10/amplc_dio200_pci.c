static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
void T_1 * V_5 ;
if ( F_3 ( V_4 , 0 ) < 0x4000 ) {
F_4 ( V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
V_5 = F_5 ( V_4 , 0 ) ;
if ( ! V_5 ) {
F_4 ( V_2 -> V_6 , L_2 ) ;
return - V_8 ;
}
F_6 ( 0x80 , V_5 + 0x50 ) ;
F_7 ( V_5 ) ;
F_8 ( V_2 , 1 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = NULL ;
unsigned int V_12 ;
int V_13 ;
if ( V_9 < F_10 ( V_14 ) )
V_11 = & V_14 [ V_9 ] ;
if ( ! V_11 )
return - V_7 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_16 = V_11 -> V_17 ;
F_11 ( V_2 -> V_6 , L_3 ,
V_2 -> V_18 -> V_19 , F_12 ( V_3 ) , V_2 -> V_16 ) ;
V_13 = F_13 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_12 = V_11 -> V_20 ;
if ( F_14 ( V_3 , V_12 ) & V_21 ) {
V_2 -> V_22 = F_5 ( V_3 , V_12 ) ;
if ( ! V_2 -> V_22 ) {
F_4 ( V_2 -> V_6 ,
L_4 ) ;
return - V_8 ;
}
} else {
V_2 -> V_23 = F_15 ( V_3 , V_12 ) ;
}
if ( V_11 -> V_24 ) {
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
}
return F_16 ( V_2 , V_3 -> V_25 , V_26 ) ;
}
static int F_17 ( struct V_3 * V_2 , const struct V_27 * V_28 )
{
return F_18 ( V_2 , & V_29 ,
V_28 -> V_30 ) ;
}
