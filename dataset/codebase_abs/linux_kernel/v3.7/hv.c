static int F_1 ( void )
{
unsigned int V_1 ;
unsigned int V_2 ;
unsigned int V_3 ;
unsigned int V_4 ;
unsigned int V_5 ;
unsigned int V_6 ;
V_1 = 0 ;
V_2 = 0 ;
V_3 = 0 ;
V_4 = 0 ;
V_6 = V_7 ;
F_2 ( V_6 , & V_1 , & V_2 , & V_3 , & V_4 ) ;
V_5 = V_1 ;
if ( V_5 >= V_8 ) {
V_1 = 0 ;
V_2 = 0 ;
V_3 = 0 ;
V_4 = 0 ;
V_6 = V_8 ;
F_2 ( V_6 , & V_1 , & V_2 , & V_3 , & V_4 ) ;
F_3 ( L_1 ,
V_1 ,
V_2 >> 16 ,
V_2 & 0xFFFF ,
V_3 ,
V_4 >> 24 ,
V_4 & 0xFFFFFF ) ;
}
return V_5 ;
}
static T_1 F_4 ( T_1 V_9 , void * V_10 , void * V_11 )
{
#ifdef F_5
T_1 V_12 = 0 ;
T_1 V_13 = ( V_10 ) ? F_6 ( V_10 ) : 0 ;
T_1 V_14 = ( V_11 ) ? F_6 ( V_11 ) : 0 ;
void * V_15 = V_16 . V_15 ;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_page));
return V_12 ;
#else
T_2 V_17 = V_9 >> 32 ;
T_2 V_18 = V_9 & 0xFFFFFFFF ;
T_2 V_19 = 1 ;
T_2 V_20 = 1 ;
T_1 V_13 = ( V_10 ) ? F_6 ( V_10 ) : 0 ;
T_2 V_21 = V_13 >> 32 ;
T_2 V_22 = V_13 & 0xFFFFFFFF ;
T_1 V_14 = ( V_11 ) ? F_6 ( V_11 ) : 0 ;
T_2 V_23 = V_14 >> 32 ;
T_2 V_24 = V_14 & 0xFFFFFFFF ;
void * V_15 = V_16 . V_15 ;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_page));
return V_20 | ( ( T_1 ) V_19 << 32 ) ;
#endif
}
int F_7 ( void )
{
int V_5 ;
union V_25 V_26 ;
void * V_27 = NULL ;
memset ( V_16 . V_28 , 0 , sizeof( void * ) * V_29 ) ;
memset ( V_16 . V_30 , 0 ,
sizeof( void * ) * V_29 ) ;
V_5 = F_1 () ;
V_16 . V_31 = F_8 ( 0 , V_32 , 0 ) ;
F_9 ( V_33 , V_16 . V_31 ) ;
F_10 ( V_34 , V_26 . V_35 ) ;
V_27 = F_11 ( V_36 , V_37 , V_38 ) ;
if ( ! V_27 )
goto V_39;
V_26 . V_40 = 1 ;
V_26 . V_41 = F_12 ( V_27 ) ;
F_9 ( V_34 , V_26 . V_35 ) ;
V_26 . V_35 = 0 ;
F_10 ( V_34 , V_26 . V_35 ) ;
if ( ! V_26 . V_40 )
goto V_39;
V_16 . V_15 = V_27 ;
V_16 . V_42 =
F_13 ( sizeof( struct V_43 ) ,
V_37 ) ;
if ( ! V_16 . V_42 )
goto V_39;
V_16 . V_44 =
(struct V_45 * )
( F_14 ( ( unsigned long )
V_16 . V_42 ,
V_46 ) ) ;
V_16 . V_44 -> V_47 . V_48 = 0 ;
V_16 . V_44 -> V_47 . V_49 . V_50 =
V_51 ;
V_16 . V_44 -> V_52 = 0 ;
V_16 . V_44 -> V_53 = 0 ;
return 0 ;
V_39:
if ( V_27 ) {
if ( V_26 . V_40 ) {
V_26 . V_35 = 0 ;
F_9 ( V_34 , V_26 . V_35 ) ;
}
F_15 ( V_27 ) ;
}
return - V_54 ;
}
void F_16 ( void )
{
union V_25 V_26 ;
F_9 ( V_33 , 0 ) ;
F_17 ( V_16 . V_42 ) ;
V_16 . V_42 = NULL ;
V_16 . V_44 = NULL ;
if ( V_16 . V_15 ) {
V_26 . V_35 = 0 ;
F_9 ( V_34 , V_26 . V_35 ) ;
F_15 ( V_16 . V_15 ) ;
V_16 . V_15 = NULL ;
}
}
int F_18 ( union V_55 V_56 ,
enum V_57 V_58 ,
void * V_59 , T_3 V_60 )
{
struct V_61 {
T_1 V_62 ;
struct V_63 V_64 ;
};
struct V_63 * V_65 ;
T_4 V_66 ;
unsigned long V_67 ;
if ( V_60 > V_68 )
return - V_69 ;
V_67 = ( unsigned long ) F_13 ( sizeof( struct V_61 ) , V_70 ) ;
if ( ! V_67 )
return - V_71 ;
V_65 = (struct V_63 * )
( F_14 ( V_67 , V_46 ) ) ;
V_65 -> V_47 = V_56 ;
V_65 -> V_58 = V_58 ;
V_65 -> V_60 = V_60 ;
memcpy ( ( void * ) V_65 -> V_59 , V_59 , V_60 ) ;
V_66 = F_4 ( V_72 , V_65 , NULL )
& 0xFFFF ;
F_17 ( ( void * ) V_67 ) ;
return V_66 ;
}
T_4 F_19 ( void )
{
T_4 V_66 ;
V_66 = F_4 ( V_73 ,
V_16 . V_44 ,
NULL ) & 0xFFFF ;
return V_66 ;
}
void F_20 ( void * V_74 )
{
T_1 V_75 ;
union V_76 V_77 ;
union V_78 V_79 ;
union V_80 V_81 ;
union V_82 V_83 ;
T_2 V_84 = * ( ( T_2 * ) ( V_74 ) ) ;
int V_85 = F_21 () ;
if ( ! V_16 . V_15 )
return;
F_10 ( V_86 , V_75 ) ;
V_16 . V_30 [ V_85 ] =
( void * ) F_22 ( V_70 ) ;
if ( V_16 . V_30 [ V_85 ] == NULL ) {
F_23 ( L_2 ) ;
goto V_39;
}
V_16 . V_28 [ V_85 ] =
( void * ) F_22 ( V_70 ) ;
if ( V_16 . V_28 [ V_85 ] == NULL ) {
F_23 ( L_3 ) ;
goto V_39;
}
F_10 ( V_87 , V_77 . V_35 ) ;
V_77 . V_88 = 1 ;
V_77 . V_89 = F_6 ( V_16 . V_30 [ V_85 ] )
>> V_90 ;
F_9 ( V_87 , V_77 . V_35 ) ;
F_10 ( V_91 , V_79 . V_35 ) ;
V_79 . V_92 = 1 ;
V_79 . V_93 = F_6 ( V_16 . V_28 [ V_85 ] )
>> V_90 ;
F_9 ( V_91 , V_79 . V_35 ) ;
F_10 ( V_94 + V_95 , V_81 . V_35 ) ;
V_81 . V_35 = 0 ;
V_81 . V_96 = V_84 ;
V_81 . V_97 = false ;
V_81 . V_98 = false ;
F_9 ( V_94 + V_95 , V_81 . V_35 ) ;
F_10 ( V_99 , V_83 . V_35 ) ;
V_83 . V_40 = 1 ;
F_9 ( V_99 , V_83 . V_35 ) ;
V_16 . V_100 = true ;
return;
V_39:
if ( V_16 . V_28 [ V_85 ] )
F_24 ( ( unsigned long ) V_16 . V_28 [ V_85 ] ) ;
if ( V_16 . V_30 [ V_85 ] )
F_24 ( ( unsigned long ) V_16 . V_30 [ V_85 ] ) ;
return;
}
void F_25 ( void * V_101 )
{
union V_80 V_81 ;
union V_76 V_77 ;
union V_78 V_79 ;
int V_85 = F_21 () ;
if ( ! V_16 . V_100 )
return;
F_10 ( V_94 + V_95 , V_81 . V_35 ) ;
V_81 . V_97 = 1 ;
F_9 ( V_94 + V_95 , V_81 . V_35 ) ;
F_10 ( V_87 , V_77 . V_35 ) ;
V_77 . V_88 = 0 ;
V_77 . V_89 = 0 ;
F_9 ( V_87 , V_77 . V_35 ) ;
F_10 ( V_91 , V_79 . V_35 ) ;
V_79 . V_92 = 0 ;
V_79 . V_93 = 0 ;
F_9 ( V_91 , V_79 . V_35 ) ;
F_24 ( ( unsigned long ) V_16 . V_30 [ V_85 ] ) ;
F_24 ( ( unsigned long ) V_16 . V_28 [ V_85 ] ) ;
}
