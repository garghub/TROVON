static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 , V_3 + F_3 ( struct V_4 , V_5 ) )
& ( V_6 | V_7 ) ;
}
int F_4 ( struct V_1 * V_8 )
{
T_1 V_9 = V_10 + sizeof( struct V_4 ) ;
if ( F_2 ( V_8 , F_3 ( struct V_11 , V_12 ) ) != V_13 )
return 0 ;
if ( F_5 ( V_8 , V_10 + F_3 ( struct V_4 , V_14 ) ) != V_15 ||
F_5 ( V_8 , V_10 ) != 0x45 )
return 0 ;
if ( F_1 ( V_8 , V_10 ) )
return 0 ;
if ( F_2 ( V_8 , V_9 + F_3 ( struct V_16 , V_17 ) ) == V_18 )
return V_19 ;
return 0 ;
}
