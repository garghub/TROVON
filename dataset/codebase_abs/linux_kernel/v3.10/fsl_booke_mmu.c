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
unsigned int V_15 ;
V_15 = F_5 ( V_12 ) - 10 ;
#ifdef F_6
if ( ( V_13 & V_16 ) == 0 )
V_13 |= V_17 ;
#endif
V_18 [ V_10 ] . V_19 = F_7 ( 1 ) | F_8 ( V_10 ) | F_9 ( V_10 + 1 ) ;
V_18 [ V_10 ] . V_20 = V_21 | V_22 | F_10 ( V_15 ) | F_11 ( V_14 ) ;
V_18 [ V_10 ] . V_23 = V_11 & V_24 ;
V_18 [ V_10 ] . V_23 |= ( V_13 & V_25 ) ? V_26 : 0 ;
V_18 [ V_10 ] . V_23 |= ( V_13 & V_16 ) ? V_27 : 0 ;
V_18 [ V_10 ] . V_23 |= ( V_13 & V_17 ) ? V_28 : 0 ;
V_18 [ V_10 ] . V_23 |= ( V_13 & V_29 ) ? V_30 : 0 ;
V_18 [ V_10 ] . V_23 |= ( V_13 & V_31 ) ? V_32 : 0 ;
V_18 [ V_10 ] . V_33 = ( V_8 & V_34 ) | V_35 | V_36 ;
V_18 [ V_10 ] . V_33 |= ( ( V_13 & V_37 ) ? V_38 : 0 ) ;
if ( F_12 ( V_39 ) )
V_18 [ V_10 ] . V_40 = ( V_41 ) V_8 >> 32 ;
if ( F_13 ( V_13 ) ) {
V_18 [ V_10 ] . V_33 |= V_42 | V_43 ;
V_18 [ V_10 ] . V_33 |= ( ( V_13 & V_37 ) ? V_44 : 0 ) ;
}
V_2 [ V_10 ] . V_4 = V_11 ;
V_2 [ V_10 ] . V_3 = V_11 + V_12 - 1 ;
V_2 [ V_10 ] . V_8 = V_8 ;
F_14 ( V_10 ) ;
}
unsigned long F_15 ( unsigned long V_45 , unsigned long V_11 ,
T_1 V_8 )
{
unsigned int V_46 = F_5 ( V_45 ) ;
unsigned int V_47 = F_16 ( V_11 | V_8 ) ;
unsigned long V_48 ;
if ( ( F_17 ( V_49 ) & V_50 ) == V_51 ) {
V_48 = ( ( F_17 ( V_52 ) >> 16 ) & 0xf ) * 2 + 10 ;
V_46 &= ~ 1U ;
V_47 &= ~ 1U ;
} else {
V_48 = F_5 ( F_17 ( V_53 ) ) + 10 ;
}
if ( V_46 > V_47 )
V_46 = V_47 ;
if ( V_46 > V_48 )
V_46 = V_48 ;
return 1UL << V_46 ;
}
unsigned long F_18 ( unsigned long V_45 , int V_54 )
{
int V_55 ;
unsigned long V_11 = V_56 ;
T_1 V_8 = V_57 ;
unsigned long V_58 = 0 ;
for ( V_55 = 0 ; V_45 && V_55 < V_54 ; V_55 ++ ) {
unsigned long V_59 ;
V_59 = F_15 ( V_45 , V_11 , V_8 ) ;
F_4 ( V_55 , V_11 , V_8 , V_59 , V_60 , 0 ) ;
V_45 -= V_59 ;
V_58 += V_59 ;
V_11 += V_59 ;
V_8 += V_59 ;
}
V_7 = V_55 ;
return V_58 ;
}
unsigned long T_2 F_19 ( unsigned long V_61 )
{
return V_2 [ V_7 - 1 ] . V_3 - V_56 + 1 ;
}
void T_2 F_20 ( void )
{
F_21 () ;
}
void T_2 F_22 ( void )
{
unsigned long V_45 ;
int V_55 ;
V_45 = F_23 ( ( T_1 ) V_62 , ( T_1 ) V_63 ) ;
V_62 = F_18 ( V_45 , V_64 ) ;
F_24 ( L_1 ) ;
for ( V_55 = 0 ; V_55 < V_7 - 1 ; V_55 ++ )
F_25 ( L_2 , F_1 ( V_55 ) >> 20 ) ;
F_25 ( L_3 , F_1 ( V_7 - 1 ) >> 20 ,
( unsigned int ) ( ( V_63 - V_62 ) >> 20 ) ) ;
F_26 ( V_57 + V_62 ) ;
}
void F_27 ( T_1 V_65 ,
T_1 V_66 )
{
T_1 V_3 = V_65 + V_66 ;
F_26 ( F_28 ( V_41 , V_3 , 0x04000000 ) ) ;
}
