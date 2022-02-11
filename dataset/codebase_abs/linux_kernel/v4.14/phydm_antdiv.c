void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_4 &= ~ V_5 ;
F_2 ( V_3 , V_6 , L_1 ) ;
}
void F_3 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_4 |= V_5 ;
F_2 ( V_3 , V_6 ,
L_2 ) ;
F_4 ( V_3 ) ;
}
void F_5 ( void * V_1 , T_1 V_7
)
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 -> V_8 == V_9 ) {
if ( V_7 == 0 )
F_6 ( V_3 , 0x948 , V_10 , 0x00000000 ) ;
else if ( V_7 == 1 )
F_6 ( V_3 , 0x948 , V_10 , 0x00000280 ) ;
} else if ( V_3 -> V_8 == V_11 ) {
if ( V_7 == 0 )
F_6 ( V_3 , 0x948 , V_12 , 0x0000 ) ;
else if ( V_7 == 1 )
F_6 ( V_3 , 0x948 , V_12 , 0x0280 ) ;
}
}
void F_7 ( void * V_1 ) {}
void F_8 ( void * V_1 ) {}
void F_4 ( void * V_1 ) {}
void F_9 ( void * V_1 ) {}
