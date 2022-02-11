static inline void F_1 ( void T_1 * V_1 , unsigned long V_2 )
{
while ( F_2 ( V_1 ) & V_2 )
F_3 () ;
}
static inline void F_4 ( void )
{
F_5 ( 0 , V_3 + V_4 ) ;
F_1 ( V_3 + V_4 , 1 ) ;
}
static void F_6 ( void )
{
}
static void F_7 ( void )
{
T_2 V_5 = ( 1 << 16 ) - 1 ;
F_5 ( V_5 , V_3 + V_6 ) ;
F_1 ( V_3 + V_6 , V_5 ) ;
F_4 () ;
}
static int T_3 F_8 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < 8 ; V_7 ++ ) {
F_5 ( 0x0 , V_3 + V_8 +
V_7 * V_9 ) ;
F_5 ( 0x0 , V_3 + V_10 +
V_7 * V_9 ) ;
}
return 0 ;
}
static int T_3 F_9 ( void )
{
if ( F_10 () )
V_3 = F_11 ( V_11 ) ;
else if ( F_12 () )
V_3 = F_11 ( V_12 ) ;
else
F_13 () ;
F_8 () ;
F_14 ( V_3 , 0x3e060000 , 0xc0000fff ) ;
V_13 . V_14 = F_6 ;
V_13 . V_15 = F_7 ;
return 0 ;
}
