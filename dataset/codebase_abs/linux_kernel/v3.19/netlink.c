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
int F_11 ( const struct V_6 * V_24 , struct V_25 * * * V_26 )
{
T_2 V_27 = V_28 . V_27 ;
* V_26 = V_28 . V_29 ;
if ( ! * V_26 )
return - V_30 ;
return F_12 ( V_24 , V_14 , * V_26 , V_27 , V_31 ) ;
}
int F_13 ( void )
{
int V_32 ;
V_32 = F_14 ( & V_33 , V_34 ) ;
if ( V_32 ) {
F_15 ( L_1 ) ;
return V_32 ;
}
V_32 = F_14 ( & V_28 ,
V_35 ) ;
if ( V_32 ) {
F_15 ( L_2 ) ;
return V_32 ;
}
return 0 ;
}
void F_16 ( void )
{
F_17 ( & V_33 ) ;
F_17 ( & V_28 ) ;
}
