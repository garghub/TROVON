static T_1 F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 , V_4 , V_5 ;
do {
F_2 ( F_3 ( V_6 , V_7 ) , V_3 ) ;
F_2 ( F_3 ( V_6 , V_8 ) , V_5 ) ;
F_2 ( F_3 ( V_6 , V_7 ) , V_4 ) ;
} while ( V_4 != V_3 );
return ( ( ( T_1 ) V_3 ) << 32 ) + V_5 ;
}
void T_2 F_4 ( unsigned int V_9 )
{
unsigned int V_10 , V_11 ;
F_2 ( F_3 ( V_6 , V_12 ) , V_10 ) ;
V_11 = 32 + ( ( V_10 & V_13 ) >>
( V_14 - 2 ) ) ;
V_15 . V_16 = F_5 ( V_11 ) ;
V_15 . V_17 = 200 + V_9 / 10000000 ;
F_6 ( & V_15 , V_9 ) ;
}
