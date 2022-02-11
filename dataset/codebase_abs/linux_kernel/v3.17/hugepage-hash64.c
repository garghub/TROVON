static void F_1 ( unsigned long V_1 , unsigned long V_2 ,
T_1 * V_3 , unsigned int V_4 , int V_5 )
{
int V_6 , V_7 , V_8 ;
unsigned long V_9 ;
unsigned char * V_10 ;
unsigned long V_11 , V_12 , V_13 , V_14 , V_15 ;
V_9 = V_2 & V_16 ;
V_10 = F_2 ( V_3 ) ;
if ( ! V_10 )
return;
if ( V_17 . V_18 )
return V_17 . V_18 ( V_1 , V_9 , V_10 ,
V_4 , V_5 ) ;
V_12 = V_19 [ V_4 ] . V_12 ;
V_7 = V_20 >> V_12 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_8 = F_3 ( V_10 , V_6 ) ;
if ( ! V_8 )
continue;
V_11 = F_4 ( V_10 , V_6 ) ;
V_2 = V_9 + ( V_6 * ( 1ul << V_12 ) ) ;
V_13 = F_5 ( V_2 , V_1 , V_5 ) ;
V_14 = F_6 ( V_13 , V_12 , V_5 ) ;
if ( V_11 & V_21 )
V_14 = ~ V_14 ;
V_15 = ( V_14 & V_22 ) * V_23 ;
V_15 += V_11 & V_24 ;
V_17 . V_25 ( V_15 , V_13 , V_4 ,
V_26 , V_5 , 0 ) ;
}
}
int F_7 ( unsigned long V_27 , unsigned long V_28 , unsigned long V_1 ,
T_1 * V_3 , unsigned long V_29 , int V_30 , int V_5 ,
unsigned int V_4 )
{
unsigned int V_31 , V_8 ;
unsigned char * V_10 ;
unsigned long V_32 , V_33 , V_11 ;
unsigned long V_34 , V_35 ;
int V_36 , V_37 = V_26 ;
unsigned long V_13 , V_14 , V_12 , V_15 ;
do {
T_1 V_38 = F_8 ( * V_3 ) ;
V_34 = F_9 ( V_38 ) ;
if ( F_10 ( V_34 & V_39 ) )
return 0 ;
if ( F_10 ( V_34 & V_40 ) )
return 0 ;
if ( F_10 ( V_28 & ~ V_34 ) )
return 1 ;
V_35 = V_34 | V_39 | V_41 ;
if ( V_28 & V_42 )
V_35 |= V_43 ;
} while ( V_34 != F_11 ( ( unsigned long * ) V_3 ,
V_34 , V_35 ) );
V_32 = V_35 & V_44 ;
if ( ( V_35 & V_44 ) && ! ( ( V_35 & V_42 ) &&
( V_35 & V_43 ) ) )
V_32 |= 0x1 ;
V_32 |= ( ( V_35 & V_45 ) ? 0 : V_46 ) ;
#if 0
if (!cpu_has_feature(CPU_FTR_COHERENT_ICACHE)) {
rflags = hash_page_do_lazy_icache(rflags, __pte(old_pte), trap);
}
#endif
V_12 = V_19 [ V_4 ] . V_12 ;
V_31 = ( V_27 & ~ V_16 ) >> V_12 ;
F_12 ( V_31 >= 4096 ) ;
V_13 = F_5 ( V_27 , V_1 , V_5 ) ;
V_14 = F_6 ( V_13 , V_12 , V_5 ) ;
V_10 = F_2 ( V_3 ) ;
if ( V_4 == V_47 ) {
if ( ( V_34 & V_48 ) && ! ( V_34 & V_49 ) )
F_1 ( V_1 , V_27 , V_3 , V_50 , V_5 ) ;
}
V_8 = F_3 ( V_10 , V_31 ) ;
if ( V_8 ) {
V_11 = F_4 ( V_10 , V_31 ) ;
if ( V_11 & V_21 )
V_14 = ~ V_14 ;
V_15 = ( V_14 & V_22 ) * V_23 ;
V_15 += V_11 & V_24 ;
V_36 = V_17 . V_51 ( V_15 , V_32 , V_13 ,
V_4 , V_37 , V_5 , V_30 ) ;
if ( V_36 == - 1 ) {
V_8 = 0 ;
V_10 [ V_31 ] = 0 ;
}
}
if ( ! V_8 ) {
unsigned long V_52 ;
V_33 = F_13 ( F_14 ( V_34 ) ) << V_53 ;
V_35 |= V_48 ;
V_32 |= ( V_35 & ( V_54 | V_55 |
V_56 ) ) ;
V_32 |= V_57 ;
V_58:
V_52 = ( ( V_14 & V_22 ) * V_23 ) & ~ 0x7UL ;
V_15 = V_17 . V_59 ( V_52 , V_13 , V_33 , V_32 , 0 ,
V_4 , V_37 , V_5 ) ;
if ( F_10 ( V_15 == - 1 ) ) {
V_52 = ( ( ~ V_14 & V_22 ) *
V_23 ) & ~ 0x7UL ;
V_15 = V_17 . V_59 ( V_52 , V_13 , V_33 ,
V_32 , V_60 ,
V_4 , V_37 , V_5 ) ;
if ( V_15 == - 1 ) {
if ( F_15 () & 0x1 )
V_52 = ( ( V_14 & V_22 ) *
V_23 ) & ~ 0x7UL ;
V_17 . V_61 ( V_52 ) ;
goto V_58;
}
}
if ( F_10 ( V_15 == - 2 ) ) {
* V_3 = F_14 ( V_34 ) ;
F_16 ( V_27 , V_28 , V_1 , V_29 , V_5 ,
V_4 , V_37 , V_34 ) ;
return - 1 ;
}
F_17 ( V_10 , V_31 , V_15 ) ;
}
if ( V_4 == V_47 )
V_35 |= V_49 ;
F_18 () ;
* V_3 = F_14 ( V_35 & ~ V_39 ) ;
return 0 ;
}
