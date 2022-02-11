void T_1 F_1 ( unsigned long V_1 , unsigned long V_2 )
{
int V_3 ;
V_1 = F_2 ( F_3 ( V_1 ) ) ;
V_2 = F_2 ( F_3 ( V_2 ) ) ;
V_4 = ( void V_5 * ) V_1 ;
for ( V_3 = 0 ; V_3 < V_6 ; V_3 ++ ) {
if ( V_3 >= V_7 )
V_8 [ V_3 ] . V_9 = ( void V_5 * ) V_2 +
( 0x04 * ( V_3 - V_7 ) ) ;
else
V_8 [ V_3 ] . V_9 = ( void V_5 * ) V_1 +
( 0x04 * V_3 ) ;
F_4 ( & V_8 [ V_3 ] . V_10 ) ;
}
}
unsigned short F_5 ( enum V_11 V_12 )
{
unsigned short V_13 ;
unsigned long V_14 ;
F_6 ( & V_8 [ V_12 ] . V_10 , V_14 ) ;
V_13 = F_7 ( V_8 [ V_12 ] . V_9 ) ;
F_8 ( & V_8 [ V_12 ] . V_10 , V_14 ) ;
return V_13 ;
}
void F_9 ( enum V_11 V_12 , unsigned short V_15 )
{
unsigned long V_14 ;
F_6 ( & V_8 [ V_12 ] . V_10 , V_14 ) ;
F_10 ( V_15 , V_8 [ V_12 ] . V_9 ) ;
F_11 () ;
F_8 ( & V_8 [ V_12 ] . V_10 , V_14 ) ;
}
void F_12 ( enum V_11 V_12 , unsigned short V_16 , unsigned short V_17 )
{
unsigned short V_13 ;
unsigned long V_14 ;
F_6 ( & V_8 [ V_12 ] . V_10 , V_14 ) ;
V_13 = F_7 ( V_8 [ V_12 ] . V_9 ) ;
V_13 &= ~ V_16 ;
V_13 |= V_17 ;
F_10 ( V_13 , V_8 [ V_12 ] . V_9 ) ;
F_11 () ;
F_8 ( & V_8 [ V_12 ] . V_10 , V_14 ) ;
}
static void F_13 ( struct V_18 * V_19 )
{
unsigned short V_20 = F_7 ( V_4 + V_21 ) ;
struct V_22 * V_23 = F_14 ( V_19 ) ;
F_15 ( V_23 , V_19 ) ;
F_16 ( V_24 + F_17 ( V_20 ) ) ;
F_18 ( V_23 , V_19 ) ;
}
static void F_19 ( struct V_25 * V_19 )
{
unsigned short V_26 = 1 << ( V_19 -> V_27 - V_24 ) ;
F_10 ( V_26 , V_4 + V_28 ) ;
F_11 () ;
}
static void F_20 ( struct V_25 * V_19 )
{
unsigned short V_26 = 1 << ( V_19 -> V_27 - V_24 ) ;
F_10 ( V_26 , V_4 + V_28 ) ;
F_10 ( V_26 , V_4 + V_21 ) ;
F_11 () ;
}
static void F_21 ( struct V_25 * V_19 )
{
unsigned short V_26 = 1 << ( V_19 -> V_27 - V_24 ) ;
F_10 ( V_26 , V_4 + V_29 ) ;
F_11 () ;
}
void T_1 F_22 ( int V_30 , int V_31 , int V_32 )
{
unsigned int V_27 ;
F_10 ( 0xffff , V_4 + V_28 ) ;
F_10 ( 0xffff , V_4 + V_33 ) ;
F_10 ( 0xffff , V_4 + V_21 ) ;
F_11 () ;
V_24 = V_30 ;
for ( V_27 = V_30 ; V_27 <= V_31 ; V_27 ++ )
F_23 ( V_27 , & V_34 ,
V_35 , L_1 ) ;
F_24 ( V_32 , F_13 ) ;
}
