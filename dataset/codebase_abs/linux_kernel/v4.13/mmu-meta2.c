unsigned long F_1 ( unsigned long V_1 )
{
unsigned int V_2 = F_2 () ;
unsigned long V_3 , V_4 , V_5 ;
unsigned int V_6 ;
T_1 * V_7 , V_8 ;
if ( F_3 ( V_1 ) )
V_1 &= ~ 0x80000000 ;
V_3 = V_1 >> V_9 ;
V_6 = F_4 ( F_5 ( V_2 ) ) ;
V_4 = ( V_6 >> V_9 ) & 0x1ff ;
V_5 = 1 << ( ( V_6 >> 8 ) & 0xf ) ;
V_5 += V_4 ;
if ( V_3 < V_4 || V_3 > V_5 )
return 0 ;
V_3 -= V_4 ;
V_7 = ( T_1 * ) F_6 () ;
V_8 = V_7 [ V_3 ] ;
return F_7 ( V_8 ) ;
}
unsigned long F_8 ( unsigned long V_1 )
{
return F_9 ( ( void * ) ( V_1 & V_10 ) ) ;
}
unsigned long F_6 ( void )
{
unsigned int V_2 = F_2 () ;
unsigned long V_11 ;
V_11 = V_2 * V_12 ;
V_11 += ( F_4 ( F_10 ( V_2 ) ) & 0x7fffc ) ;
if ( F_3 ( V_13 ) )
V_11 += V_14 ;
return V_15 + V_11 ;
}
static void F_11 ( void )
{
unsigned long V_16 ;
unsigned int V_17 ;
V_16 = V_18 ;
for ( V_17 = 0 ; V_17 < 2 ; ++ V_17 ) {
unsigned int V_19 , V_6 ;
unsigned long V_20 ;
for ( V_19 = 0 ; V_19 < 4 ; ++ V_19 ) {
F_12 ( V_20 ) ;
V_6 = F_4 ( V_16 ) ;
if ( ( V_6 & V_21 ) && ! ( V_6 & V_22 ) ) {
F_13 ( L_1 ,
V_19 ,
V_17 ? L_2 : L_3 ) ;
V_6 |= V_22 ;
F_14 ( V_6 , V_16 ) ;
}
F_15 ( V_20 ) ;
V_16 += V_23 ;
}
V_16 += V_24
- 4 * V_23 ;
}
}
static void F_16 ( void )
{
F_11 () ;
}
void T_2 F_17 ( unsigned long V_25 )
{
unsigned long V_8 , V_26 ;
T_1 * V_27 ;
#ifdef F_18
unsigned long V_28 = V_25 - V_13 ;
unsigned int V_29 = F_19 ( V_28 , 1 << 22 ) ;
unsigned int V_30 = 0 ;
unsigned long * V_31 ;
#endif
V_26 = V_32 ;
V_8 = F_20 ( V_32 ) ;
V_27 = F_21 ( 0 ) + V_8 ;
while ( V_8 < ( V_33 - F_20 ( V_32 ) ) ) {
unsigned long V_34 ;
V_34 = F_1 ( V_26 ) ;
F_7 ( * V_27 ) = V_34 ;
V_27 ++ ;
V_26 += V_35 ;
V_8 ++ ;
}
#ifdef F_18
V_31 = F_22 ( V_36 * V_29 ) ;
V_26 = V_13 ;
V_8 = F_20 ( V_13 ) ;
V_27 = F_21 ( 0 ) + V_8 ;
while ( V_29 > 0 ) {
unsigned long V_37 , V_38 ;
T_3 * V_39 = ( T_3 * ) & V_31 [ V_30 ] ;
V_37 = F_23 ( V_26 ) ;
V_38 = F_23 ( V_39 ) ;
F_7 ( * V_27 ) = ( ( V_38 &
V_40 ) |
V_41 |
V_21 ) ;
F_24 ( * V_39 ) = ( ( V_37 & V_42 ) |
V_21 | V_43 |
V_44 | V_45 |
V_46 | V_47 ) ;
V_27 ++ ;
V_26 += V_35 ;
V_30 += ( V_36 /
sizeof( unsigned long ) ) ;
V_29 -- ;
}
F_25 ( V_48 , F_2 () ) ;
F_26 () ;
#endif
F_11 () ;
F_27 ( & V_49 ) ;
}
