static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 , V_5 = V_2 -> V_6 . V_5 ;
V_3 = F_2 () ;
if ( V_5 && V_3 > V_5 )
V_3 = V_5 ;
V_3 += F_3 ( V_2 ) ;
V_4 = 1ULL << ( F_4 ( V_3 ) - 1 ) ;
V_4 += V_4 - 1 ;
return V_4 ;
}
void F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_10 = F_6 ( V_8 -> V_13 ) ;
V_12 = & V_8 -> V_2 . V_6 ;
V_12 -> V_5 =
V_10 -> V_14 + V_10 -> V_15 ;
}
static int F_7 ( struct V_16 * V_17 ,
unsigned long V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_11 * V_12 ;
if ( V_18 != V_20 )
return 0 ;
V_12 = & V_2 -> V_6 ;
V_12 -> V_5 = 0 ;
if ( ( F_8 ( V_2 ) + 1 ) < F_2 () )
F_9 ( V_2 , & V_21 ) ;
return V_22 ;
}
int T_2 F_10 ( void )
{
F_11 ( & V_23 ,
& V_24 ) ;
return 0 ;
}
void T_2 F_12 ( void )
{
if ( ( F_2 () - 1 ) > 0xffffffff ) {
V_25 = 1 ;
#ifdef F_13
F_14 ( V_26 , ( 1ULL << 32 ) >> V_27 ) ;
#endif
}
}
static int T_2 F_15 ( void )
{
if ( V_25 )
F_16 () ;
else
F_17 () ;
return 0 ;
}
