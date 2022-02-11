static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_1 * V_5 ;
struct V_6 * V_7 ;
struct V_6 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = V_4 -> V_12 ;
int V_13 = F_2 ( V_14 + V_15 ) ;
T_1 V_16 ;
if ( ( V_11 -> V_16 & 0xC000 ) && ( ! F_3 ( V_2 , V_17 ) ) )
V_16 = V_18 ;
else
V_16 = V_11 -> V_16 ;
V_5 = F_4 ( V_11 -> V_19 , V_16 ,
F_5 ( V_8 ) + V_14 + V_15 ,
F_6 ( V_8 , V_14 + V_15 ) ,
V_13 ) ;
if ( V_5 ) {
F_7 ( V_5 , V_13 ) ;
V_7 = F_8 ( V_5 ) ;
memcpy ( V_7 , V_8 , V_13 ) ;
V_7 -> V_20 = V_5 -> V_21 ;
F_9 ( & V_22 , V_5 , F_10 ( V_2 ) . V_23 ) ;
}
return 0 ;
}
int F_11 ( void )
{
int V_24 ;
V_24 = F_12 ( & V_25 , V_26 ) ;
if ( V_24 ) {
F_13 ( L_1 ) ;
return V_24 ;
}
return 0 ;
}
void F_14 ( void )
{
F_15 ( & V_25 ) ;
}
