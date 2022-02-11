int F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 ,
T_1 * V_4 , unsigned long V_5 , unsigned long V_6 ,
int V_7 , unsigned int V_8 )
{
unsigned int V_9 , V_10 ;
unsigned char * V_11 ;
unsigned long V_12 , V_13 , V_14 ;
unsigned long V_15 , V_16 ;
int V_17 , V_18 = V_19 ;
unsigned long V_20 , V_21 , V_22 , V_23 ;
do {
T_1 V_24 = F_2 ( * V_4 ) ;
V_15 = F_3 ( V_24 ) ;
if ( F_4 ( V_15 & V_25 ) )
return 0 ;
if ( F_4 ( V_15 & V_26 ) )
return 0 ;
if ( F_4 ( V_2 & ~ V_15 ) )
return 1 ;
V_16 = V_15 | V_25 | V_27 ;
if ( V_2 & V_28 )
V_16 |= V_29 ;
} while ( V_15 != F_5 ( ( unsigned long * ) V_4 ,
V_15 , V_16 ) );
V_12 = V_16 & V_30 ;
if ( ( V_16 & V_30 ) && ! ( ( V_16 & V_28 ) &&
( V_16 & V_29 ) ) )
V_12 |= 0x1 ;
V_12 |= ( ( V_16 & V_31 ) ? 0 : V_32 ) ;
#if 0
if (!cpu_has_feature(CPU_FTR_COHERENT_ICACHE)) {
rflags = hash_page_do_lazy_icache(rflags, __pte(old_pte), trap);
}
#endif
V_22 = V_33 [ V_8 ] . V_22 ;
V_9 = ( V_1 & ~ V_34 ) >> V_22 ;
F_6 ( V_9 >= 4096 ) ;
V_20 = F_7 ( V_1 , V_3 , V_7 ) ;
V_11 = F_8 ( V_4 ) ;
if ( V_8 == V_35 ) {
if ( ( V_15 & V_36 ) && ! ( V_15 & V_37 ) )
F_9 ( V_3 , V_1 , V_4 , V_38 ,
V_7 , V_6 ) ;
}
V_10 = F_10 ( V_11 , V_9 ) ;
if ( V_10 ) {
V_21 = F_11 ( V_20 , V_22 , V_7 ) ;
V_14 = F_12 ( V_11 , V_9 ) ;
if ( V_14 & V_39 )
V_21 = ~ V_21 ;
V_23 = ( V_21 & V_40 ) * V_41 ;
V_23 += V_14 & V_42 ;
V_17 = V_43 . V_44 ( V_23 , V_12 , V_20 ,
V_8 , V_18 , V_7 , V_6 ) ;
if ( V_17 == - 1 ) {
V_10 = 0 ;
V_11 [ V_9 ] = 0 ;
}
}
if ( ! V_10 ) {
unsigned long V_45 ;
V_21 = F_11 ( V_20 , V_22 , V_7 ) ;
V_13 = F_13 ( F_14 ( V_15 ) ) << V_46 ;
V_16 |= V_36 ;
V_12 |= ( V_16 & ( V_47 | V_48 |
V_49 ) ) ;
V_12 |= V_50 ;
V_51:
V_45 = ( ( V_21 & V_40 ) * V_41 ) & ~ 0x7UL ;
V_23 = V_43 . V_52 ( V_45 , V_20 , V_13 , V_12 , 0 ,
V_8 , V_18 , V_7 ) ;
if ( F_4 ( V_23 == - 1 ) ) {
V_45 = ( ( ~ V_21 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_23 = V_43 . V_52 ( V_45 , V_20 , V_13 ,
V_12 , V_53 ,
V_8 , V_18 , V_7 ) ;
if ( V_23 == - 1 ) {
if ( F_15 () & 0x1 )
V_45 = ( ( V_21 & V_40 ) *
V_41 ) & ~ 0x7UL ;
V_43 . V_54 ( V_45 ) ;
goto V_51;
}
}
if ( F_4 ( V_23 == - 2 ) ) {
* V_4 = F_14 ( V_15 ) ;
F_16 ( V_1 , V_2 , V_3 , V_5 , V_7 ,
V_8 , V_18 , V_15 ) ;
return - 1 ;
}
F_17 ( V_11 , V_9 , V_23 ) ;
}
if ( V_8 == V_35 )
V_16 |= V_37 ;
F_18 () ;
* V_4 = F_14 ( V_16 & ~ V_25 ) ;
return 0 ;
}
