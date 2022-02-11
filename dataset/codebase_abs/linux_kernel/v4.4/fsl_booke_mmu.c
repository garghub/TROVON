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
#if F_6 ( V_16 ) || F_6 ( V_17 )
if ( ( V_13 & V_18 ) == 0 )
V_13 |= V_19 ;
#endif
V_20 [ V_10 ] . V_21 = F_7 ( 1 ) | F_8 ( V_10 ) | F_9 ( V_10 + 1 ) ;
V_20 [ V_10 ] . V_22 = V_23 | V_24 | F_10 ( V_15 ) | F_11 ( V_14 ) ;
V_20 [ V_10 ] . V_25 = V_11 & V_26 ;
V_20 [ V_10 ] . V_25 |= ( V_13 & V_27 ) ? V_28 : 0 ;
V_20 [ V_10 ] . V_25 |= ( V_13 & V_18 ) ? V_29 : 0 ;
V_20 [ V_10 ] . V_25 |= ( V_13 & V_19 ) ? V_30 : 0 ;
V_20 [ V_10 ] . V_25 |= ( V_13 & V_31 ) ? V_32 : 0 ;
V_20 [ V_10 ] . V_25 |= ( V_13 & V_33 ) ? V_34 : 0 ;
V_20 [ V_10 ] . V_35 = ( V_8 & V_36 ) | V_37 | V_38 ;
V_20 [ V_10 ] . V_35 |= ( ( V_13 & V_39 ) ? V_40 : 0 ) ;
if ( F_12 ( V_41 ) )
V_20 [ V_10 ] . V_42 = ( V_43 ) V_8 >> 32 ;
if ( F_13 ( V_13 ) ) {
V_20 [ V_10 ] . V_35 |= V_44 | V_45 ;
V_20 [ V_10 ] . V_35 |= ( ( V_13 & V_39 ) ? V_46 : 0 ) ;
}
V_2 [ V_10 ] . V_4 = V_11 ;
V_2 [ V_10 ] . V_3 = V_11 + V_12 - 1 ;
V_2 [ V_10 ] . V_8 = V_8 ;
}
unsigned long F_14 ( unsigned long V_47 , unsigned long V_11 ,
T_1 V_8 )
{
unsigned int V_48 = F_5 ( V_47 ) ;
unsigned int V_49 = F_15 ( V_11 | V_8 ) ;
unsigned long V_50 ;
if ( ( F_16 ( V_51 ) & V_52 ) == V_53 ) {
V_50 = ( ( F_16 ( V_54 ) >> 16 ) & 0xf ) * 2 + 10 ;
V_48 &= ~ 1U ;
V_49 &= ~ 1U ;
} else {
V_50 = F_5 ( F_16 ( V_55 ) ) + 10 ;
}
if ( V_48 > V_49 )
V_48 = V_49 ;
if ( V_48 > V_50 )
V_48 = V_50 ;
return 1UL << V_48 ;
}
static unsigned long F_17 ( T_1 V_8 , unsigned long V_11 ,
unsigned long V_47 , int V_56 ,
bool V_57 )
{
int V_58 ;
unsigned long V_59 = 0 ;
for ( V_58 = 0 ; V_47 && V_58 < V_56 ; V_58 ++ ) {
unsigned long V_60 ;
V_60 = F_14 ( V_47 , V_11 , V_8 ) ;
if ( ! V_57 )
F_4 ( V_58 , V_11 , V_8 , V_60 ,
F_18 ( V_61 ) , 0 ) ;
V_47 -= V_60 ;
V_59 += V_60 ;
V_11 += V_60 ;
V_8 += V_60 ;
}
if ( V_57 )
return V_59 ;
F_19 ( 0 , V_58 , V_56 ) ;
V_7 = V_58 ;
#ifdef F_20
F_21 () -> V_62 . V_63 = V_58 ;
F_21 () -> V_62 . V_64 = F_16 ( V_54 ) & V_65 ;
F_21 () -> V_62 . V_66 = V_58 ;
#endif
return V_59 ;
}
unsigned long F_22 ( unsigned long V_47 , int V_56 , bool V_57 )
{
unsigned long V_11 = V_67 ;
T_1 V_8 = V_68 ;
return F_17 ( V_8 , V_11 , V_47 , V_56 , V_57 ) ;
}
unsigned long T_2 F_23 ( unsigned long V_69 )
{
return V_2 [ V_7 - 1 ] . V_3 - V_67 + 1 ;
}
void T_2 F_24 ( void )
{
F_25 () ;
}
void T_2 F_26 ( void )
{
unsigned long V_47 ;
int V_58 ;
V_47 = F_27 ( ( T_1 ) V_70 , ( T_1 ) V_71 ) ;
V_58 = F_28 () ;
V_70 = F_22 ( V_47 , V_72 , false ) ;
F_29 ( V_58 , 0 , 0 , 1 ) ;
F_30 ( L_1 ) ;
for ( V_58 = 0 ; V_58 < V_7 - 1 ; V_58 ++ )
F_31 ( L_2 , F_1 ( V_58 ) >> 20 ) ;
F_31 ( L_3 , F_1 ( V_7 - 1 ) >> 20 ,
( unsigned int ) ( ( V_71 - V_70 ) >> 20 ) ) ;
F_32 ( V_68 + V_70 ) ;
}
void F_33 ( T_1 V_73 ,
T_1 V_74 )
{
T_1 V_3 = V_73 + V_74 ;
F_32 ( F_34 ( V_43 , V_3 , 0x04000000 ) ) ;
}
T_3 void T_2 F_35 ( V_43 V_75 , T_1 V_4 )
{
unsigned long V_76 = V_77 ;
V_78 = V_4 ;
if ( V_79 ) {
V_80 = V_67 - V_68 ;
return;
}
V_4 &= ~ 0x3ffffff ;
V_76 &= ~ 0x3ffffff ;
V_80 = V_76 - V_4 ;
F_36 ( F_37 ( V_75 ) , NULL ) ;
if ( V_4 != V_68 ) {
int V_81 ;
long V_82 = V_4 - V_68 ;
V_79 = 1 ;
V_81 = F_28 () ;
if ( V_68 > V_4 )
F_22 ( 0x4000000 , V_72 ,
false ) ;
else
F_17 ( V_4 , V_67 + V_82 ,
0x4000000 , V_72 ,
false ) ;
F_29 ( V_81 , V_82 , F_37 ( V_75 ) , 1 ) ;
F_38 ( L_4 ) ;
}
}
