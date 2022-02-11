static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
if ( V_3 != V_4 )
F_3 ( V_3 , V_5 +
V_6 ) ;
else
F_3 ( V_3 , V_7 +
V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
if ( V_3 != V_4 )
F_3 ( V_3 , V_5 +
V_9 ) ;
else
F_3 ( V_3 , V_7 +
V_10 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_11 * V_12 , bool V_13 )
{
unsigned long V_14 ;
unsigned long V_15 = 0 ;
unsigned long V_16 = 0 ;
unsigned long V_17 = 0 ;
T_1 V_3 = F_2 ( V_2 ) ;
int V_18 ;
F_6 (cpu, mask_val) {
V_15 |= 1 << F_7 ( V_18 ) ;
V_17 ++ ;
}
if ( V_17 > 1 )
return - V_19 ;
F_6 (cpu, cpu_online_mask)
V_16 |= 1 << F_7 ( V_18 ) ;
F_8 ( & V_20 ) ;
V_14 = F_9 ( V_5 + F_10 ( V_3 ) ) ;
V_14 = ( V_14 & ( ~ V_16 ) ) | V_15 ;
F_3 ( V_14 , V_5 + F_10 ( V_3 ) ) ;
F_11 ( & V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 ,
unsigned int V_23 , T_1 V_24 )
{
F_1 ( F_13 ( V_23 ) ) ;
if ( V_24 != V_4 )
F_3 ( V_24 , V_7 +
V_10 ) ;
else
F_3 ( V_24 , V_5 + V_9 ) ;
F_14 ( V_23 , V_25 ) ;
if ( V_24 == V_4 ) {
F_15 ( V_23 ) ;
F_16 ( V_23 , & V_26 ,
V_27 ) ;
} else {
F_16 ( V_23 , & V_26 ,
V_28 ) ;
}
F_17 ( V_23 , V_29 | V_30 ) ;
return 0 ;
}
void F_18 ( const struct V_11 * V_31 , unsigned int V_32 )
{
int V_18 ;
unsigned long V_33 = 0 ;
F_6 (cpu, mask)
V_33 |= 1 << F_7 ( V_18 ) ;
F_19 () ;
F_3 ( ( V_33 << 8 ) | V_32 , V_5 +
V_34 ) ;
}
void F_20 ( void )
{
F_3 ( 0 , V_7 + V_35 ) ;
F_3 ( V_36 , V_7 +
V_37 ) ;
F_3 ( 0 , V_7 + V_10 ) ;
}
static T_2 void T_3
F_21 ( struct V_38 * V_39 )
{
T_4 V_40 , V_41 ;
do {
V_40 = F_22 ( V_7 +
V_42 ) ;
V_41 = V_40 & 0x3FF ;
if ( V_41 > 1022 )
break;
if ( V_41 > 0 ) {
V_41 = F_23 ( V_43 ,
V_41 ) ;
F_24 ( V_41 , V_39 ) ;
continue;
}
#ifdef F_25
if ( V_41 == 0 ) {
T_4 V_44 , V_45 ;
V_44 = F_22 ( V_7 +
V_35 )
& V_36 ;
F_3 ( ~ V_36 , V_7 +
V_35 ) ;
for ( V_45 = V_46 ;
V_45 < V_47 ; V_45 ++ ) {
if ( V_44 & ( 0x1 << V_45 ) )
F_26 ( V_45 , V_39 ) ;
}
continue;
}
#endif
} while ( 1 );
}
static int T_5 F_27 ( struct V_48 * V_49 ,
struct V_48 * V_50 )
{
T_4 V_51 ;
V_5 = F_28 ( V_49 , 0 ) ;
V_7 = F_28 ( V_49 , 1 ) ;
F_29 ( ! V_5 ) ;
F_29 ( ! V_7 ) ;
V_51 = F_9 ( V_5 + V_52 ) ;
V_43 =
F_30 ( V_49 , ( V_51 >> 2 ) & 0x3ff ,
& V_53 , NULL ) ;
if ( ! V_43 )
F_31 ( L_1 ) ;
F_32 ( V_43 ) ;
#ifdef F_25
F_20 () ;
F_33 ( V_54 ) ;
F_34 ( F_35 () , V_54 ) ;
#endif
F_36 ( F_21 ) ;
return 0 ;
}
