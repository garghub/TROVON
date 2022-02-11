static void F_1 ( unsigned long V_1 )
{
F_2 ( & V_2 , F_3 ( V_3 + V_1 ) ) ;
F_4 () ;
}
void T_1 F_5 ( struct V_4 * V_5 , void (* F_6)( void ) ,
unsigned int V_6 , unsigned long V_7 )
{
unsigned long V_8 , V_9 ;
T_2 V_10 , V_11 ;
char V_12 ;
F_4 = F_6 ;
F_7 ( & V_5 -> V_13 , & V_5 -> V_14 , V_7 , V_15 , 0 ) ;
V_8 = V_7 ;
if ( V_8 >= 4000000 ) {
V_8 /= 1000000 ;
V_12 = 'M' ;
} else {
V_8 /= 1000 ;
V_12 = 'k' ;
}
V_11 = F_8 ( ( 1ULL << V_6 ) - 1 , V_5 -> V_13 , V_5 -> V_14 ) ;
F_9 ( V_11 , V_16 ) ;
V_9 = V_11 ;
V_10 = F_8 ( 1ULL , V_5 -> V_13 , V_5 -> V_14 ) ;
F_10 ( L_1 ,
V_6 , V_8 , V_12 , V_10 , V_9 ) ;
V_2 . V_17 = F_11 ( V_9 - ( V_9 / 10 ) ) ;
F_6 () ;
V_5 -> V_18 = 0 ;
}
void T_1 F_12 ( void )
{
F_1 ( V_2 . V_17 ) ;
}
