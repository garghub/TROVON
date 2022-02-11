int F_1 ( void * V_1 , const unsigned char V_2 [ 16 ] )
{
T_1 * V_3 = ( T_1 * ) V_1 ;
T_2 V_4 , V_5 , V_6 , V_7 ;
#if 0
st->h[0].d = TWO(52)*TWO0;
st->h[1].d = TWO(52)*TWO32;
st->h[2].d = TWO(52)*TWO64;
st->h[3].d = TWO(52)*TWO96;
#else
V_3 -> V_8 [ 0 ] . V_9 = EXP ( 52 + 0 ) ;
V_3 -> V_8 [ 1 ] . V_9 = EXP ( 52 + 32 ) ;
V_3 -> V_8 [ 2 ] . V_9 = EXP ( 52 + 64 ) ;
V_3 -> V_8 [ 3 ] . V_9 = EXP ( 52 + 96 ) ;
#endif
if ( V_2 ) {
#if F_2 ( V_10 )
T_3 V_11 ;
asm volatile ("stmxcsr %0":"=m"(mxcsr_orig));
asm volatile ("ldmxcsr %0"::"m"(mxcsr));
#elif F_2 ( V_12 )
double V_13 , V_14 = * ( double * ) & V_15 ;
asm volatile ("mffs %0":"=f"(fpscr_orig));
asm volatile ("mtfsf 255,%0"::"f"(fpscr));
#elif F_2 ( V_16 )
T_3 V_17 ;
asm volatile ("stfpc %0":"=m"(fpc_orig));
asm volatile ("lfpc %0"::"m"(fpc));
#elif F_2 ( V_18 )
T_4 V_19 ;
asm volatile ("stx %%fsr,%0":"=m"(fsr_orig));
asm volatile ("ldx %0,%%fsr"::"m"(fsr));
#endif
V_4 . V_9 = EXP ( 52 + 0 ) | ( F_3 ( & V_2 [ 0 ] ) & 0x0fffffff ) ;
V_5 . V_9 = EXP ( 52 + 32 ) | ( F_3 ( & V_2 [ 4 ] ) & 0x0ffffffc ) ;
V_6 . V_9 = EXP ( 52 + 64 ) | ( F_3 ( & V_2 [ 8 ] ) & 0x0ffffffc ) ;
V_7 . V_9 = EXP ( 52 + 96 ) | ( F_3 ( & V_2 [ 12 ] ) & 0x0ffffffc ) ;
V_3 -> V_20 [ 0 ] = V_4 . V_21 - F_4 ( 52 ) * V_22 ;
V_3 -> V_20 [ 2 ] = V_5 . V_21 - F_4 ( 52 ) * V_23 ;
V_3 -> V_20 [ 4 ] = V_6 . V_21 - F_4 ( 52 ) * V_24 ;
V_3 -> V_20 [ 6 ] = V_7 . V_21 - F_4 ( 52 ) * V_25 ;
V_3 -> V_26 [ 0 ] = V_3 -> V_20 [ 2 ] * ( 5.0 / V_27 ) ;
V_3 -> V_26 [ 2 ] = V_3 -> V_20 [ 4 ] * ( 5.0 / V_27 ) ;
V_3 -> V_26 [ 4 ] = V_3 -> V_20 [ 6 ] * ( 5.0 / V_27 ) ;
V_3 -> V_20 [ 1 ] = ( V_3 -> V_20 [ 0 ] + F_4 ( 52 ) * F_4 ( 16 ) * V_22 ) -
F_4 ( 52 ) * F_4 ( 16 ) * V_22 ;
V_3 -> V_20 [ 0 ] -= V_3 -> V_20 [ 1 ] ;
V_3 -> V_20 [ 3 ] = ( V_3 -> V_20 [ 2 ] + F_4 ( 52 ) * F_4 ( 16 ) * V_23 ) -
F_4 ( 52 ) * F_4 ( 16 ) * V_23 ;
V_3 -> V_20 [ 2 ] -= V_3 -> V_20 [ 3 ] ;
V_3 -> V_20 [ 5 ] = ( V_3 -> V_20 [ 4 ] + F_4 ( 52 ) * F_4 ( 16 ) * V_24 ) -
F_4 ( 52 ) * F_4 ( 16 ) * V_24 ;
V_3 -> V_20 [ 4 ] -= V_3 -> V_20 [ 5 ] ;
V_3 -> V_20 [ 7 ] = ( V_3 -> V_20 [ 6 ] + F_4 ( 52 ) * F_4 ( 16 ) * V_25 ) -
F_4 ( 52 ) * F_4 ( 16 ) * V_25 ;
V_3 -> V_20 [ 6 ] -= V_3 -> V_20 [ 7 ] ;
V_3 -> V_26 [ 1 ] = ( V_3 -> V_26 [ 0 ] + F_4 ( 52 ) * F_4 ( 16 ) * V_22 / V_25 ) -
F_4 ( 52 ) * F_4 ( 16 ) * V_22 / V_25 ;
V_3 -> V_26 [ 0 ] -= V_3 -> V_26 [ 1 ] ;
V_3 -> V_26 [ 3 ] = ( V_3 -> V_26 [ 2 ] + F_4 ( 52 ) * F_4 ( 16 ) * V_23 / V_25 ) -
F_4 ( 52 ) * F_4 ( 16 ) * V_23 / V_25 ;
V_3 -> V_26 [ 2 ] -= V_3 -> V_26 [ 3 ] ;
V_3 -> V_26 [ 5 ] = ( V_3 -> V_26 [ 4 ] + F_4 ( 52 ) * F_4 ( 16 ) * V_24 / V_25 ) -
F_4 ( 52 ) * F_4 ( 16 ) * V_24 / V_25 ;
V_3 -> V_26 [ 4 ] -= V_3 -> V_26 [ 5 ] ;
#if F_2 ( V_10 )
asm volatile ("ldmxcsr %0"::"m"(mxcsr_orig));
#elif F_2 ( V_12 )
asm volatile ("mtfsf 255,%0"::"f"(fpscr_orig));
#elif F_2 ( V_16 )
asm volatile ("lfpc %0"::"m"(fpc_orig));
#elif F_2 ( V_18 )
asm volatile ("ldx %0,%%fsr"::"m"(fsr_orig));
#endif
}
return 0 ;
}
void F_5 ( void * V_1 , const unsigned char * V_28 , T_5 V_29 ,
int V_30 )
{
T_1 * V_3 = ( T_1 * ) V_1 ;
T_2 V_31 , V_32 , V_33 , V_34 ;
T_4 V_35 = ( T_4 ) V_30 << 32 ;
double V_36 , V_37 , V_38 , V_39 ;
double V_40 , V_41 , V_42 , V_43 , V_44 , V_45 , V_46 , V_47 ;
double V_48 , V_49 , V_50 , V_51 , V_52 , V_53 , V_54 , V_55 ;
const double V_56 = V_3 -> V_20 [ 0 ] ;
const double V_57 = V_3 -> V_20 [ 1 ] ;
const double V_58 = V_3 -> V_20 [ 2 ] ;
const double V_59 = V_3 -> V_20 [ 3 ] ;
const double V_60 = V_3 -> V_20 [ 4 ] ;
const double V_61 = V_3 -> V_20 [ 5 ] ;
const double V_62 = V_3 -> V_20 [ 6 ] ;
const double V_63 = V_3 -> V_20 [ 7 ] ;
const double V_64 = V_3 -> V_26 [ 0 ] ;
const double V_65 = V_3 -> V_26 [ 1 ] ;
const double V_66 = V_3 -> V_26 [ 2 ] ;
const double V_67 = V_3 -> V_26 [ 3 ] ;
const double V_68 = V_3 -> V_26 [ 4 ] ;
const double V_69 = V_3 -> V_26 [ 5 ] ;
#if F_2 ( V_10 )
T_3 V_11 ;
asm volatile ("stmxcsr %0":"=m"(mxcsr_orig));
asm volatile ("ldmxcsr %0"::"m"(mxcsr));
#elif F_2 ( V_12 )
double V_13 , V_14 = * ( double * ) & V_15 ;
asm volatile ("mffs %0":"=f"(fpscr_orig));
asm volatile ("mtfsf 255,%0"::"f"(fpscr));
#elif F_2 ( V_16 )
T_3 V_17 ;
asm volatile ("stfpc %0":"=m"(fpc_orig));
asm volatile ("lfpc %0"::"m"(fpc));
#elif F_2 ( V_18 )
T_4 V_19 ;
asm volatile ("stx %%fsr,%0":"=m"(fsr_orig));
asm volatile ("ldx %0,%%fsr"::"m"(fsr));
#endif
V_40 = V_3 -> V_8 [ 0 ] . V_21 - F_4 ( 52 ) * V_22 ;
V_42 = V_3 -> V_8 [ 1 ] . V_21 - F_4 ( 52 ) * V_23 ;
V_44 = V_3 -> V_8 [ 2 ] . V_21 - F_4 ( 52 ) * V_24 ;
V_46 = V_3 -> V_8 [ 3 ] . V_21 - F_4 ( 52 ) * V_25 ;
#ifdef F_6
V_41 = 0 ;
V_43 = 0 ;
V_45 = 0 ;
V_47 = 0 ;
#else
V_31 . V_9 = EXP ( 52 + 0 ) | F_3 ( & V_28 [ 0 ] ) ;
V_32 . V_9 = EXP ( 52 + 32 ) | F_3 ( & V_28 [ 4 ] ) ;
V_33 . V_9 = EXP ( 52 + 64 ) | F_3 ( & V_28 [ 8 ] ) ;
V_34 . V_9 = EXP ( 52 + 96 ) | F_3 ( & V_28 [ 12 ] ) | V_35 ;
V_36 = V_31 . V_21 - F_4 ( 52 ) * V_22 ;
V_37 = V_32 . V_21 - F_4 ( 52 ) * V_23 ;
V_38 = V_33 . V_21 - F_4 ( 52 ) * V_24 ;
V_39 = V_34 . V_21 - F_4 ( 52 ) * V_25 ;
V_36 += V_40 ;
V_37 += V_42 ;
V_38 += V_44 ;
V_39 += V_46 ;
goto V_70;
#endif
do {
V_31 . V_9 = EXP ( 52 + 0 ) | F_3 ( & V_28 [ 0 ] ) ;
V_32 . V_9 = EXP ( 52 + 32 ) | F_3 ( & V_28 [ 4 ] ) ;
V_33 . V_9 = EXP ( 52 + 64 ) | F_3 ( & V_28 [ 8 ] ) ;
V_34 . V_9 = EXP ( 52 + 96 ) | F_3 ( & V_28 [ 12 ] ) | V_35 ;
V_36 = V_31 . V_21 - F_4 ( 52 ) * V_22 ;
V_37 = V_32 . V_21 - F_4 ( 52 ) * V_23 ;
V_38 = V_33 . V_21 - F_4 ( 52 ) * V_24 ;
V_39 = V_34 . V_21 - F_4 ( 52 ) * V_25 ;
V_40 += V_36 ;
V_41 += V_37 ;
V_44 += V_38 ;
V_45 += V_39 ;
V_48 = ( V_40 + F_4 ( 52 ) * V_23 ) - F_4 ( 52 ) * V_23 ;
V_50 = ( V_42 + F_4 ( 52 ) * V_24 ) - F_4 ( 52 ) * V_24 ;
V_52 = ( V_44 + F_4 ( 52 ) * V_25 ) - F_4 ( 52 ) * V_25 ;
V_54 = ( V_46 + F_4 ( 52 ) * V_27 ) - F_4 ( 52 ) * V_27 ;
V_49 = ( V_41 + F_4 ( 52 ) * V_23 ) - F_4 ( 52 ) * V_23 ;
V_51 = ( V_43 + F_4 ( 52 ) * V_24 ) - F_4 ( 52 ) * V_24 ;
V_53 = ( V_45 + F_4 ( 52 ) * V_25 ) - F_4 ( 52 ) * V_25 ;
V_55 = ( V_47 + F_4 ( 52 ) * V_27 ) - F_4 ( 52 ) * V_27 ;
V_37 = ( V_42 - V_50 ) + V_48 ;
V_38 = ( V_44 - V_52 ) + V_50 ;
V_39 = ( V_46 - V_54 ) + V_52 ;
V_36 = ( V_40 - V_48 ) + V_54 * ( 5.0 / V_27 ) ;
V_37 += ( V_43 - V_51 ) + V_49 ;
V_38 += ( V_45 - V_53 ) + V_51 ;
V_39 += ( V_47 - V_55 ) + V_53 ;
V_36 += ( V_41 - V_49 ) + V_55 * ( 5.0 / V_27 ) ;
#ifndef F_6
V_70:
#endif
V_40 = V_68 * V_37 + V_66 * V_38 + V_64 * V_39 + V_56 * V_36 ;
V_42 = V_56 * V_37 + V_68 * V_38 + V_66 * V_39 + V_58 * V_36 ;
V_44 = V_58 * V_37 + V_56 * V_38 + V_68 * V_39 + V_60 * V_36 ;
V_46 = V_60 * V_37 + V_58 * V_38 + V_56 * V_39 + V_62 * V_36 ;
V_41 = V_69 * V_37 + V_67 * V_38 + V_65 * V_39 + V_57 * V_36 ;
V_43 = V_57 * V_37 + V_69 * V_38 + V_67 * V_39 + V_59 * V_36 ;
V_45 = V_59 * V_37 + V_57 * V_38 + V_69 * V_39 + V_61 * V_36 ;
V_47 = V_61 * V_37 + V_59 * V_38 + V_57 * V_39 + V_63 * V_36 ;
V_28 += 16 ;
V_29 -= 16 ;
} while ( V_29 >= 16 );
V_48 = ( V_40 + F_4 ( 52 ) * V_23 ) - F_4 ( 52 ) * V_23 ;
V_50 = ( V_42 + F_4 ( 52 ) * V_24 ) - F_4 ( 52 ) * V_24 ;
V_52 = ( V_44 + F_4 ( 52 ) * V_25 ) - F_4 ( 52 ) * V_25 ;
V_54 = ( V_46 + F_4 ( 52 ) * V_27 ) - F_4 ( 52 ) * V_27 ;
V_49 = ( V_41 + F_4 ( 52 ) * V_23 ) - F_4 ( 52 ) * V_23 ;
V_51 = ( V_43 + F_4 ( 52 ) * V_24 ) - F_4 ( 52 ) * V_24 ;
V_53 = ( V_45 + F_4 ( 52 ) * V_25 ) - F_4 ( 52 ) * V_25 ;
V_55 = ( V_47 + F_4 ( 52 ) * V_27 ) - F_4 ( 52 ) * V_27 ;
V_37 = ( V_42 - V_50 ) + V_48 ;
V_38 = ( V_44 - V_52 ) + V_50 ;
V_39 = ( V_46 - V_54 ) + V_52 ;
V_36 = ( V_40 - V_48 ) + V_54 * ( 5.0 / V_27 ) ;
V_37 += ( V_43 - V_51 ) + V_49 ;
V_38 += ( V_45 - V_53 ) + V_51 ;
V_39 += ( V_47 - V_55 ) + V_53 ;
V_36 += ( V_41 - V_49 ) + V_55 * ( 5.0 / V_27 ) ;
V_3 -> V_8 [ 1 ] . V_21 = V_37 + F_4 ( 52 ) * V_23 ;
V_3 -> V_8 [ 2 ] . V_21 = V_38 + F_4 ( 52 ) * V_24 ;
V_3 -> V_8 [ 3 ] . V_21 = V_39 + F_4 ( 52 ) * V_25 ;
V_3 -> V_8 [ 0 ] . V_21 = V_36 + F_4 ( 52 ) * V_22 ;
#if F_2 ( V_10 )
asm volatile ("ldmxcsr %0"::"m"(mxcsr_orig));
#elif F_2 ( V_12 )
asm volatile ("mtfsf 255,%0"::"f"(fpscr_orig));
#elif F_2 ( V_16 )
asm volatile ("lfpc %0"::"m"(fpc_orig));
#elif F_2 ( V_18 )
asm volatile ("ldx %0,%%fsr"::"m"(fsr_orig));
#endif
}
void F_7 ( void * V_1 , unsigned char V_71 [ 16 ] , const T_3 V_72 [ 4 ] )
{
T_1 * V_3 = ( T_1 * ) V_1 ;
T_4 V_73 , V_74 , V_75 , V_76 , V_77 ;
T_3 V_78 , V_79 , V_80 , V_81 , V_82 ;
T_4 V_83 ;
T_3 V_84 ;
V_73 = V_3 -> V_8 [ 0 ] . V_9 & 0x000fffffffffffffULL ;
V_74 = V_3 -> V_8 [ 1 ] . V_9 & 0x000fffffffffffffULL ;
V_75 = V_3 -> V_8 [ 2 ] . V_9 & 0x000fffffffffffffULL ;
V_76 = V_3 -> V_8 [ 3 ] . V_9 & 0x000fffffffffffffULL ;
V_77 = V_76 >> 32 ; V_76 &= 0xffffffffU ;
V_82 = V_77 & - 4 ;
V_77 &= 3 ;
V_82 += V_82 >> 2 ;
V_73 += V_82 ;
V_74 += V_73 >> 32 ; V_73 &= 0xffffffffU ;
V_75 += V_74 >> 32 ; V_74 &= 0xffffffffU ;
V_76 += V_75 >> 32 ; V_75 &= 0xffffffffU ;
V_78 = ( T_3 ) ( V_83 = V_73 + 5 ) ;
V_79 = ( T_3 ) ( V_83 = V_74 + ( V_83 >> 32 ) ) ;
V_80 = ( T_3 ) ( V_83 = V_75 + ( V_83 >> 32 ) ) ;
V_81 = ( T_3 ) ( V_83 = V_76 + ( V_83 >> 32 ) ) ;
V_82 = V_77 + ( T_3 ) ( V_83 >> 32 ) ;
V_84 = 0 - ( V_82 >> 2 ) ;
V_78 &= V_84 ;
V_79 &= V_84 ;
V_80 &= V_84 ;
V_81 &= V_84 ;
V_84 = ~ V_84 ;
V_78 |= ( V_73 & V_84 ) ;
V_79 |= ( V_74 & V_84 ) ;
V_80 |= ( V_75 & V_84 ) ;
V_81 |= ( V_76 & V_84 ) ;
V_78 = ( T_3 ) ( V_83 = ( T_4 ) V_78 + V_72 [ 0 ] ) ;
V_79 = ( T_3 ) ( V_83 = ( T_4 ) V_79 + ( V_83 >> 32 ) + V_72 [ 1 ] ) ;
V_80 = ( T_3 ) ( V_83 = ( T_4 ) V_80 + ( V_83 >> 32 ) + V_72 [ 2 ] ) ;
V_81 = ( T_3 ) ( V_83 = ( T_4 ) V_81 + ( V_83 >> 32 ) + V_72 [ 3 ] ) ;
F_8 ( V_71 + 0 , V_78 ) ;
F_8 ( V_71 + 4 , V_79 ) ;
F_8 ( V_71 + 8 , V_80 ) ;
F_8 ( V_71 + 12 , V_81 ) ;
}
