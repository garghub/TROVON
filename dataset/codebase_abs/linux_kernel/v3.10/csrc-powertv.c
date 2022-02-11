unsigned int T_1 F_1 ( void )
{
unsigned int V_1 , V_2 , V_3 , V_4 ;
unsigned int V_5 = 54000 ;
unsigned int V_6 ;
V_1 = F_2 ( V_7 ) ;
V_2 = F_3 ( V_1 ) ;
V_3 = F_4 ( V_1 ) ;
V_4 = F_5 ( V_1 ) ;
F_6 ( L_1 , V_1 , V_2 , V_3 , V_4 ) ;
V_6 = ( ( 2 * V_3 * V_5 ) / ( V_2 * ( 0x01 << V_4 ) ) ) ;
F_6 ( L_2 , V_6 ) ;
return V_6 ;
}
static T_2 F_7 ( struct V_8 * V_9 )
{
return F_8 () ;
}
static void T_1 F_9 ( void )
{
unsigned int V_10 = F_1 () ;
F_6 ( L_3 , V_10 / 1000 ,
( V_10 % 1000 ) * 100 / 1000 ) ;
V_11 = V_10 / 2 * 1000 ;
V_12 . V_13 = 200 + V_11 / 10000000 ;
F_10 ( & V_12 , V_11 ) ;
}
static T_2 F_11 ( struct V_8 * V_9 )
{
unsigned int V_14 ;
unsigned int V_15 ;
unsigned int V_16 ;
V_14 = F_12 ( & V_17 -> V_14 ) ;
for (; ; ) {
V_16 = F_12 ( & V_17 -> V_16 ) ;
V_15 = F_12 ( & V_17 -> V_14 ) ;
if ( V_15 == V_14 )
break;
V_14 = V_15 ;
}
F_13 ( L_4 , V_18 , ( ( V_19 ) V_14 << 32 ) | V_16 ) ;
return ( ( V_19 ) V_14 << 32 ) | V_16 ;
}
static void T_1 F_14 ( void )
{
const unsigned long V_20 = 27000000 / 8 ;
V_21 . V_13 = 200 ;
F_10 ( & V_21 , V_20 ) ;
V_17 = (struct V_17 * ) F_15 ( V_22 ) ;
}
void T_1 F_16 ( void )
{
F_9 () ;
F_14 () ;
}
