unsigned long F_1 ( int V_1 )
{
return V_2 [ V_1 ] . V_3 - V_2 [ V_1 ] . V_4 + 1 ;
}
T_1 F_2 ( unsigned long V_5 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; ++ V_6 )
if ( V_5 >= V_2 [ V_6 ] . V_4 && V_5 < V_2 [ V_6 ] . V_3 )
return V_2 [ V_6 ] . V_8 + ( V_5 - V_2 [ V_6 ] . V_4 ) ;
return 0 ;
}
unsigned long F_3 ( T_1 V_9 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; ++ V_6 )
if ( V_9 >= V_2 [ V_6 ] . V_8
&& V_9 < ( V_2 [ V_6 ] . V_3 - V_2 [ V_6 ] . V_4 )
+ V_2 [ V_6 ] . V_8 )
return V_2 [ V_6 ] . V_4 + ( V_9 - V_2 [ V_6 ] . V_8 ) ;
return 0 ;
}
static void F_4 ( int V_10 , unsigned long V_11 , T_1 V_8 ,
unsigned long V_12 , unsigned long V_13 , unsigned int V_14 )
{
unsigned int V_15 , V_16 ;
asm (PPC_CNTLZL "%0,%1" : "=r" (lz) : "r" (size));
V_15 = 21 - V_16 ;
#ifdef F_5
if ( ( V_13 & V_17 ) == 0 )
V_13 |= V_18 ;
#endif
V_19 [ V_10 ] . V_20 = F_6 ( 1 ) | F_7 ( V_10 ) | F_8 ( V_10 + 1 ) ;
V_19 [ V_10 ] . V_21 = V_22 | V_23 | F_9 ( V_15 ) | F_10 ( V_14 ) ;
V_19 [ V_10 ] . V_24 = V_11 & V_25 ;
V_19 [ V_10 ] . V_24 |= ( V_13 & V_26 ) ? V_27 : 0 ;
V_19 [ V_10 ] . V_24 |= ( V_13 & V_17 ) ? V_28 : 0 ;
V_19 [ V_10 ] . V_24 |= ( V_13 & V_18 ) ? V_29 : 0 ;
V_19 [ V_10 ] . V_24 |= ( V_13 & V_30 ) ? V_31 : 0 ;
V_19 [ V_10 ] . V_24 |= ( V_13 & V_32 ) ? V_33 : 0 ;
V_19 [ V_10 ] . V_34 = ( V_8 & V_35 ) | V_36 | V_37 ;
V_19 [ V_10 ] . V_34 |= ( ( V_13 & V_38 ) ? V_39 : 0 ) ;
if ( F_11 ( V_40 ) )
V_19 [ V_10 ] . V_41 = ( V_42 ) V_8 >> 32 ;
if ( F_12 ( V_13 ) ) {
V_19 [ V_10 ] . V_34 |= V_43 | V_44 ;
V_19 [ V_10 ] . V_34 |= ( ( V_13 & V_38 ) ? V_45 : 0 ) ;
}
V_2 [ V_10 ] . V_4 = V_11 ;
V_2 [ V_10 ] . V_3 = V_11 + V_12 - 1 ;
V_2 [ V_10 ] . V_8 = V_8 ;
F_13 ( V_10 ) ;
}
unsigned long F_14 ( unsigned long V_46 , int V_47 )
{
int V_48 ;
unsigned long V_11 = V_49 ;
T_1 V_8 = V_50 ;
unsigned long V_51 = 0 ;
unsigned long V_52 = ( F_15 ( V_53 ) >> 16 ) & 0xf ;
V_52 = V_52 * 2 + 10 ;
for ( V_48 = 0 ; V_46 && V_48 < V_47 ; V_48 ++ ) {
unsigned int V_54 = F_16 ( V_46 ) & ~ 1U ;
unsigned int V_55 = F_17 ( V_11 | V_8 ) & ~ 1U ;
unsigned long V_56 ;
if ( V_54 > V_55 )
V_54 = V_55 ;
if ( V_54 > V_52 )
V_54 = V_52 ;
V_56 = 1UL << V_54 ;
F_4 ( V_48 , V_11 , V_8 , V_56 , V_57 , 0 ) ;
V_46 -= V_56 ;
V_51 += V_56 ;
V_11 += V_56 ;
V_8 += V_56 ;
}
V_7 = V_48 ;
return V_51 ;
}
unsigned long T_2 F_18 ( unsigned long V_58 )
{
return V_2 [ V_7 - 1 ] . V_3 - V_49 + 1 ;
}
void T_2 F_19 ( void )
{
F_20 () ;
}
void T_2 F_21 ( void )
{
unsigned long V_46 ;
int V_48 ;
V_46 = F_22 ( ( T_1 ) V_59 , ( T_1 ) V_60 ) ;
V_59 = F_14 ( V_46 , V_61 ) ;
F_23 ( L_1 ) ;
for ( V_48 = 0 ; V_48 < V_7 - 1 ; V_48 ++ )
F_24 ( L_2 , F_1 ( V_48 ) >> 20 ) ;
F_24 ( L_3 , F_1 ( V_7 - 1 ) >> 20 ,
( unsigned int ) ( ( V_60 - V_59 ) >> 20 ) ) ;
F_25 ( V_50 + V_59 ) ;
}
void F_26 ( T_1 V_62 ,
T_1 V_63 )
{
T_1 V_3 = V_62 + V_63 ;
F_25 ( F_27 ( V_42 , V_3 , 0x04000000 ) ) ;
}
