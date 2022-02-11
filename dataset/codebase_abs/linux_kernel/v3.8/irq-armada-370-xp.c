static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ,
V_3 + V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 ) ,
V_3 + V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_6 * V_7 , bool V_8 )
{
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
unsigned int V_11 , T_1 V_12 )
{
F_1 ( F_7 ( V_11 ) ) ;
F_2 ( V_12 , V_13 + V_14 ) ;
F_8 ( V_11 , & V_15 ,
V_16 ) ;
F_9 ( V_11 , V_17 ) ;
F_10 ( V_11 , V_18 | V_19 ) ;
return 0 ;
}
void F_11 ( const struct V_6 * V_20 , unsigned int V_21 )
{
int V_22 ;
unsigned long V_23 = 0 ;
F_12 (cpu, mask)
V_23 |= 1 << F_13 ( V_22 ) ;
F_14 () ;
F_2 ( ( V_23 << 8 ) | V_21 , V_13 +
V_24 ) ;
}
void F_15 ( void )
{
F_2 ( 0 , V_3 + V_25 ) ;
F_2 ( ( 1 << V_26 ) - 1 , V_3 +
V_27 ) ;
F_2 ( 0 , V_3 + V_5 ) ;
}
static int T_2 F_16 ( struct V_28 * V_29 ,
struct V_28 * V_30 )
{
T_3 V_31 ;
V_13 = F_17 ( V_29 , 0 ) ;
V_3 = F_17 ( V_29 , 1 ) ;
F_18 ( ! V_13 ) ;
F_18 ( ! V_3 ) ;
V_31 = F_19 ( V_13 + V_32 ) ;
V_33 =
F_20 ( V_29 , ( V_31 >> 2 ) & 0x3ff ,
& V_34 , NULL ) ;
if ( ! V_33 )
F_21 ( L_1 ) ;
F_22 ( V_33 ) ;
#ifdef F_23
F_15 () ;
#endif
return 0 ;
}
T_4 void T_5 F_24 ( struct V_35
* V_36 )
{
T_3 V_37 , V_38 ;
do {
V_37 = F_25 ( V_3 +
V_39 ) ;
V_38 = V_37 & 0x3FF ;
if ( V_38 > 1022 )
break;
if ( V_38 >= 8 ) {
V_38 = F_26 ( V_33 ,
V_38 ) ;
F_27 ( V_38 , V_36 ) ;
continue;
}
#ifdef F_23
if ( V_38 == 0 ) {
T_3 V_40 , V_41 ;
V_40 = F_25 ( V_3 +
V_25 )
& 0xFF ;
F_2 ( 0x0 , V_3 +
V_25 ) ;
for ( V_41 = 0 ; V_41 < V_26 ; V_41 ++ ) {
if ( V_40 & ( 0x1 << V_41 ) )
F_28 ( V_41 , V_36 ) ;
}
continue;
}
#endif
} while ( 1 );
}
void T_2 F_29 ( void )
{
F_30 ( V_42 ) ;
#ifdef F_31
F_32 ( 0 , ~ 0UL ) ;
#endif
}
