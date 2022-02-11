struct V_1 * F_1 ( void )
{
return V_2 ;
}
static T_1 F_2 ( struct V_3 * V_4 )
{
T_1 V_5 = F_3 ( V_2 ) ;
if ( V_5 == V_6 )
F_4 ( V_7 , V_5 ) ;
return V_5 ;
}
static T_1 F_5 ( struct V_3 * V_4 )
{
T_1 V_5 ;
F_4 ( V_7 , V_5 ) ;
return V_5 ;
}
void F_6 ( void )
{
T_1 V_8 ;
union V_9 V_10 ;
if ( V_11 != & V_12 )
return;
V_8 = F_7 ( 0 , V_13 , 0 ) ;
F_8 ( V_14 , V_8 ) ;
V_15 = F_9 ( V_16 , V_17 , V_18 ) ;
if ( V_15 == NULL ) {
F_8 ( V_14 , 0 ) ;
return;
}
F_4 ( V_19 , V_10 . V_20 ) ;
V_10 . V_21 = 1 ;
V_10 . V_22 = F_10 ( V_15 ) ;
F_8 ( V_19 , V_10 . V_20 ) ;
#ifdef F_11
if ( V_23 . V_24 & V_25 ) {
union V_9 V_26 ;
V_2 = F_9 ( V_16 , V_17 , V_27 ) ;
if ( ! V_2 )
goto V_28;
V_29 = & V_30 ;
F_4 ( V_31 , V_26 . V_20 ) ;
V_26 . V_21 = 1 ;
V_26 . V_22 = F_10 ( V_2 ) ;
F_8 ( V_31 , V_26 . V_20 ) ;
V_30 . V_32 . V_33 = V_34 ;
F_12 ( & V_30 , V_35 / 100 ) ;
return;
}
V_28:
#endif
V_29 = & V_36 ;
if ( V_23 . V_24 & V_37 )
F_12 ( & V_36 , V_35 / 100 ) ;
}
void F_13 ( void )
{
union V_9 V_10 ;
F_8 ( V_14 , 0 ) ;
V_10 . V_20 = 0 ;
F_8 ( V_19 , V_10 . V_20 ) ;
V_10 . V_20 = 0 ;
F_8 ( V_31 , V_10 . V_20 ) ;
}
T_1 F_14 ( T_1 V_38 , void * V_39 , void * V_40 )
{
T_1 V_41 = ( V_39 ) ? F_15 ( V_39 ) : 0 ;
T_1 V_42 = ( V_40 ) ? F_15 ( V_40 ) : 0 ;
#ifdef F_16
T_1 V_43 = 0 ;
if ( ! V_15 )
return ( T_1 ) V_44 ;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_pg));
return V_43 ;
#else
T_2 V_45 = V_38 >> 32 ;
T_2 V_46 = V_38 & 0xFFFFFFFF ;
T_2 V_47 = 1 ;
T_2 V_48 = 1 ;
T_2 V_49 = V_41 >> 32 ;
T_2 V_50 = V_41 & 0xFFFFFFFF ;
T_2 V_51 = V_42 >> 32 ;
T_2 V_52 = V_42 & 0xFFFFFFFF ;
if ( ! V_15 )
return ( T_1 ) V_44 ;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_pg));
return V_48 | ( ( T_1 ) V_47 << 32 ) ;
#endif
}
void F_17 ( struct V_53 * V_54 )
{
static bool V_55 ;
if ( V_55 )
return;
V_55 = true ;
F_8 ( V_56 , V_54 -> V_57 ) ;
F_8 ( V_58 , V_54 -> V_59 ) ;
F_8 ( V_60 , V_54 -> V_61 ) ;
F_8 ( V_62 , V_54 -> V_63 ) ;
F_8 ( V_64 , V_54 -> V_65 ) ;
F_8 ( V_66 , V_67 ) ;
}
bool F_18 ( void )
{
union V_9 V_10 ;
V_10 . V_20 = 0 ;
F_4 ( V_19 , V_10 . V_20 ) ;
if ( ! V_10 . V_21 )
return false ;
return true ;
}
