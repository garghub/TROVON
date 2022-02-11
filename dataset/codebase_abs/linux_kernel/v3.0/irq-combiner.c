static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
T_2 V_6 = 1 << ( V_2 -> V_7 % 32 ) ;
F_4 ( V_6 , F_1 ( V_2 ) + V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_2 V_6 = 1 << ( V_2 -> V_7 % 32 ) ;
F_4 ( V_6 , F_1 ( V_2 ) + V_9 ) ;
}
static void F_6 ( unsigned int V_7 , struct V_10 * V_11 )
{
struct V_3 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_7 ) ;
unsigned int V_15 , V_16 ;
unsigned long V_17 ;
F_9 ( V_14 , V_11 ) ;
F_10 ( & V_18 ) ;
V_17 = F_11 ( V_12 -> V_5 + V_19 ) ;
F_12 ( & V_18 ) ;
V_17 &= V_12 -> V_20 ;
if ( V_17 == 0 )
goto V_21;
V_16 = F_13 ( V_17 ) ;
V_15 = V_16 + ( V_12 -> V_22 & ~ 31 ) ;
if ( F_14 ( V_15 >= V_23 ) )
F_15 ( V_15 , V_11 ) ;
else
F_16 ( V_15 ) ;
V_21:
F_17 ( V_14 , V_11 ) ;
}
void T_3 F_18 ( unsigned int V_24 , unsigned int V_7 )
{
if ( V_24 >= V_25 )
F_19 () ;
if ( F_20 ( V_7 , & V_4 [ V_24 ] ) != 0 )
F_19 () ;
F_21 ( V_7 , F_6 ) ;
}
void T_3 F_22 ( unsigned int V_24 , void T_1 * V_5 ,
unsigned int V_26 )
{
unsigned int V_27 ;
if ( V_24 >= V_25 )
F_19 () ;
V_4 [ V_24 ] . V_5 = V_5 ;
V_4 [ V_24 ] . V_22 = V_26 ;
V_4 [ V_24 ] . V_20 = 0xff << ( ( V_24 % 4 ) << 3 ) ;
F_4 ( V_4 [ V_24 ] . V_20 ,
V_5 + V_8 ) ;
for ( V_27 = V_26 ; V_27 < V_4 [ V_24 ] . V_22
+ V_28 ; V_27 ++ ) {
F_23 ( V_27 , & V_29 , V_30 ) ;
F_24 ( V_27 , & V_4 [ V_24 ] ) ;
F_25 ( V_27 , V_31 | V_32 ) ;
}
}
