static T_1 F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_4 -> V_5 != 0 ) {
while ( 1 ) {
T_1 V_6 ;
T_2 V_7 = V_4 -> V_5 ;
T_1 V_8 ;
T_1 V_9 = V_4 -> V_10 ;
T_3 V_11 = V_4 -> V_12 ;
F_2 ( V_8 ) ;
asm("mulq %3"
: "=d" (current_tick), "=a" (tmp)
: "a" (cur_tsc), "r" (scale));
V_3 += V_11 ;
if ( V_4 -> V_5 == V_7 )
return V_3 ;
if ( V_4 -> V_5 != 0 )
continue;
break;
}
}
F_3 ( V_13 , V_3 ) ;
return V_3 ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_3 ( V_13 , V_3 ) ;
return V_3 ;
}
void F_5 ( void )
{
T_1 V_14 ;
union V_15 V_16 ;
if ( V_17 != & V_18 )
return;
V_14 = F_6 ( 0 , V_19 , 0 ) ;
F_7 ( V_20 , V_14 ) ;
V_21 = F_8 ( V_22 , V_23 , V_24 ) ;
if ( V_21 == NULL ) {
F_7 ( V_20 , 0 ) ;
return;
}
F_3 ( V_25 , V_16 . V_26 ) ;
V_16 . V_27 = 1 ;
V_16 . V_28 = F_9 ( V_21 ) ;
F_7 ( V_25 , V_16 . V_26 ) ;
#ifdef F_10
if ( V_29 . V_30 & V_31 ) {
union V_15 V_32 ;
V_4 = F_8 ( V_22 , V_23 , V_33 ) ;
if ( ! V_4 )
goto V_34;
V_35 = & V_36 ;
F_3 ( V_37 , V_32 . V_26 ) ;
V_32 . V_27 = 1 ;
V_32 . V_28 = F_9 ( V_4 ) ;
F_7 ( V_37 , V_32 . V_26 ) ;
F_11 ( & V_36 , V_38 / 100 ) ;
return;
}
V_34:
#endif
V_35 = & V_39 ;
if ( V_29 . V_30 & V_40 )
F_11 ( & V_39 , V_38 / 100 ) ;
}
void F_12 ( void )
{
union V_15 V_16 ;
F_7 ( V_20 , 0 ) ;
V_16 . V_26 = 0 ;
F_7 ( V_25 , V_16 . V_26 ) ;
V_16 . V_26 = 0 ;
F_7 ( V_37 , V_16 . V_26 ) ;
}
T_1 F_13 ( T_1 V_41 , void * V_42 , void * V_43 )
{
T_1 V_44 = ( V_42 ) ? F_14 ( V_42 ) : 0 ;
T_1 V_45 = ( V_43 ) ? F_14 ( V_43 ) : 0 ;
#ifdef F_10
T_1 V_46 = 0 ;
if ( ! V_21 )
return ( T_1 ) V_47 ;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_pg));
return V_46 ;
#else
T_2 V_48 = V_41 >> 32 ;
T_2 V_49 = V_41 & 0xFFFFFFFF ;
T_2 V_50 = 1 ;
T_2 V_51 = 1 ;
T_2 V_52 = V_44 >> 32 ;
T_2 V_53 = V_44 & 0xFFFFFFFF ;
T_2 V_54 = V_45 >> 32 ;
T_2 V_55 = V_45 & 0xFFFFFFFF ;
if ( ! V_21 )
return ( T_1 ) V_47 ;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_pg));
return V_51 | ( ( T_1 ) V_50 << 32 ) ;
#endif
}
void F_15 ( struct V_56 * V_57 )
{
static bool V_58 ;
if ( V_58 )
return;
V_58 = true ;
F_7 ( V_59 , V_57 -> V_60 ) ;
F_7 ( V_61 , V_57 -> V_62 ) ;
F_7 ( V_63 , V_57 -> V_64 ) ;
F_7 ( V_65 , V_57 -> V_66 ) ;
F_7 ( V_67 , V_57 -> V_68 ) ;
F_7 ( V_69 , V_70 ) ;
}
bool F_16 ( void )
{
union V_15 V_16 ;
V_16 . V_26 = 0 ;
F_3 ( V_25 , V_16 . V_26 ) ;
if ( ! V_16 . V_27 )
return false ;
return true ;
}
