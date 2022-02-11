static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 -> V_5 , F_3 ( 0 , 0 , 0xa8 ) ) ;
V_4 = F_4 ( V_2 -> V_6 ) ;
V_4 = V_3 ? ( V_4 | V_7 ) :
( V_4 & ~ V_7 ) ;
F_2 ( V_2 -> V_5 , F_3 ( 0 , 0 , 0xa8 ) ) ;
F_5 ( V_2 -> V_6 , V_4 ) ;
( void ) F_4 ( V_2 -> V_6 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 ;
F_2 ( V_2 -> V_5 , F_3 ( 0 , 0 , 0xa8 ) ) ;
V_4 = F_4 ( V_2 -> V_6 ) ;
V_4 = V_3 ? ( V_4 | V_8 ) :
( V_4 & ~ V_8 ) ;
F_2 ( V_2 -> V_5 , F_3 ( 0 , 0 , 0xa8 ) ) ;
F_5 ( V_2 -> V_6 , V_4 ) ;
( void ) F_4 ( V_2 -> V_6 ) ;
}
void T_1 F_7 ( struct V_1 * V_9 )
{
F_8 ( V_9 , 0xfec00000 , 0xfee00000 , 0 ) ;
if ( F_9 ( L_1 ) )
F_10 ( V_10 ) ;
if ( F_9 ( L_2 ) )
F_6 ( V_9 , 1 ) ;
#if 0
grackle_set_stg(hose, 1);
#endif
}
