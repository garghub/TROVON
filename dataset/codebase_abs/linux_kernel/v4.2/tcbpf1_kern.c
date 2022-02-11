static inline void F_1 ( struct V_1 * V_2 , char * V_3 )
{
F_2 ( V_2 , 0 , V_3 , V_4 , 1 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
T_1 V_6 = F_4 ( V_2 , V_7 ) ;
F_5 ( V_2 , V_8 , F_6 ( V_6 ) , F_6 ( V_5 ) , 2 ) ;
F_2 ( V_2 , V_7 , & V_5 , sizeof( V_5 ) , 0 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_2 V_9 )
{
T_2 V_10 = F_8 ( F_9 ( V_2 , V_11 ) ) ;
F_10 ( V_2 , V_12 , V_10 , V_9 , V_13 | sizeof( V_9 ) ) ;
F_5 ( V_2 , V_8 , V_10 , V_9 , sizeof( V_9 ) ) ;
F_2 ( V_2 , V_11 , & V_9 , sizeof( V_9 ) , 0 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_3 V_14 )
{
T_3 V_15 = F_6 ( F_12 ( V_2 , V_16 ) ) ;
F_10 ( V_2 , V_12 , V_15 , V_14 , sizeof( V_14 ) ) ;
F_2 ( V_2 , V_16 , & V_14 , sizeof( V_14 ) , 0 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
T_1 V_17 = F_4 ( V_2 , V_18 + F_14 ( struct V_19 , V_20 ) ) ;
long * V_21 ;
if ( V_17 == V_22 ) {
F_3 ( V_2 , 8 ) ;
F_7 ( V_2 , 0xA010101 ) ;
F_11 ( V_2 , 5001 ) ;
}
return 0 ;
}
