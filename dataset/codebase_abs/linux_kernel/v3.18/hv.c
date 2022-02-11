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
V_9 = V_1 ;
V_10 = V_2 ;
V_11 = V_3 ;
V_12 = V_4 ;
}
return V_5 ;
}
static T_1 F_3 ( T_1 V_13 , void * V_14 , void * V_15 )
{
#ifdef F_4
T_1 V_16 = 0 ;
T_1 V_17 = ( V_14 ) ? F_5 ( V_14 ) : 0 ;
T_1 V_18 = ( V_15 ) ? F_5 ( V_15 ) : 0 ;
void * V_19 = V_20 . V_19 ;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_page));
return V_16 ;
#else
T_2 V_21 = V_13 >> 32 ;
T_2 V_22 = V_13 & 0xFFFFFFFF ;
T_2 V_23 = 1 ;
T_2 V_24 = 1 ;
T_1 V_17 = ( V_14 ) ? F_5 ( V_14 ) : 0 ;
T_2 V_25 = V_17 >> 32 ;
T_2 V_26 = V_17 & 0xFFFFFFFF ;
T_1 V_18 = ( V_15 ) ? F_5 ( V_15 ) : 0 ;
T_2 V_27 = V_18 >> 32 ;
T_2 V_28 = V_18 & 0xFFFFFFFF ;
void * V_19 = V_20 . V_19 ;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_page));
return V_24 | ( ( T_1 ) V_23 << 32 ) ;
#endif
}
int F_6 ( void )
{
int V_5 ;
union V_29 V_30 ;
void * V_31 = NULL ;
memset ( V_20 . V_32 , 0 , sizeof( void * ) * V_33 ) ;
memset ( V_20 . V_34 , 0 ,
sizeof( void * ) * V_33 ) ;
memset ( V_20 . V_35 , 0 ,
sizeof( void * ) * V_33 ) ;
memset ( V_20 . V_36 , 0 ,
sizeof( int ) * V_33 ) ;
memset ( V_20 . V_37 , 0 ,
sizeof( void * ) * V_33 ) ;
V_5 = F_1 () ;
V_20 . V_38 = F_7 ( 0 , V_39 , 0 ) ;
F_8 ( V_40 , V_20 . V_38 ) ;
F_9 ( V_41 , V_30 . V_42 ) ;
V_31 = F_10 ( V_43 , V_44 , V_45 ) ;
if ( ! V_31 )
goto V_46;
V_30 . V_47 = 1 ;
V_30 . V_48 = F_11 ( V_31 ) ;
F_8 ( V_41 , V_30 . V_42 ) ;
V_30 . V_42 = 0 ;
F_9 ( V_41 , V_30 . V_42 ) ;
if ( ! V_30 . V_47 )
goto V_46;
V_20 . V_19 = V_31 ;
return 0 ;
V_46:
if ( V_31 ) {
if ( V_30 . V_47 ) {
V_30 . V_42 = 0 ;
F_8 ( V_41 , V_30 . V_42 ) ;
}
F_12 ( V_31 ) ;
}
return - V_49 ;
}
void F_13 ( void )
{
union V_29 V_30 ;
F_8 ( V_40 , 0 ) ;
if ( V_20 . V_19 ) {
V_30 . V_42 = 0 ;
F_8 ( V_41 , V_30 . V_42 ) ;
F_12 ( V_20 . V_19 ) ;
V_20 . V_19 = NULL ;
}
}
int F_14 ( union V_50 V_51 ,
enum V_52 V_53 ,
void * V_54 , T_3 V_55 )
{
struct V_56 * V_57 ;
T_4 V_58 ;
if ( V_55 > V_59 )
return - V_60 ;
V_57 = (struct V_56 * )
V_20 . V_35 [ F_15 () ] ;
V_57 -> V_61 = V_51 ;
V_57 -> V_62 = 0 ;
V_57 -> V_53 = V_53 ;
V_57 -> V_55 = V_55 ;
memcpy ( ( void * ) V_57 -> V_54 , V_54 , V_55 ) ;
V_58 = F_3 ( V_63 , V_57 , NULL )
& 0xFFFF ;
F_16 () ;
return V_58 ;
}
T_4 F_17 ( void * V_64 )
{
T_4 V_58 ;
V_58 = ( F_3 ( V_65 , V_64 , NULL ) & 0xFFFF ) ;
return V_58 ;
}
int F_18 ( void )
{
T_3 V_66 = sizeof( struct V_67 ) ;
int V_68 ;
F_19 (cpu) {
V_20 . V_37 [ V_68 ] = F_20 ( V_66 , V_69 ) ;
if ( V_20 . V_37 [ V_68 ] == NULL ) {
F_21 ( L_1 ) ;
goto V_70;
}
F_22 ( V_20 . V_37 [ V_68 ] , V_71 , V_68 ) ;
V_20 . V_34 [ V_68 ] =
( void * ) F_23 ( V_69 ) ;
if ( V_20 . V_34 [ V_68 ] == NULL ) {
F_21 ( L_2 ) ;
goto V_70;
}
V_20 . V_32 [ V_68 ] =
( void * ) F_23 ( V_69 ) ;
if ( V_20 . V_32 [ V_68 ] == NULL ) {
F_21 ( L_3 ) ;
goto V_70;
}
V_20 . V_35 [ V_68 ] =
( void * ) F_23 ( V_69 ) ;
if ( V_20 . V_35 [ V_68 ] == NULL ) {
F_21 ( L_4 ) ;
goto V_70;
}
}
return 0 ;
V_70:
return - V_72 ;
}
static void F_24 ( int V_68 )
{
F_25 ( V_20 . V_37 [ V_68 ] ) ;
if ( V_20 . V_32 [ V_68 ] )
F_26 ( ( unsigned long ) V_20 . V_32 [ V_68 ] ) ;
if ( V_20 . V_34 [ V_68 ] )
F_26 ( ( unsigned long ) V_20 . V_34 [ V_68 ] ) ;
if ( V_20 . V_35 [ V_68 ] )
F_26 ( ( unsigned long ) V_20 . V_35 [ V_68 ] ) ;
}
void F_27 ( void )
{
int V_68 ;
F_19 (cpu)
F_24 ( V_68 ) ;
}
void F_28 ( void * V_73 )
{
T_1 V_74 ;
union V_75 V_76 ;
union V_77 V_78 ;
union V_79 V_80 ;
union V_81 V_82 ;
T_1 V_36 ;
int V_68 = F_29 () ;
if ( ! V_20 . V_19 )
return;
F_9 ( V_83 , V_74 ) ;
F_9 ( V_84 , V_76 . V_42 ) ;
V_76 . V_85 = 1 ;
V_76 . V_86 = F_5 ( V_20 . V_34 [ V_68 ] )
>> V_87 ;
F_8 ( V_84 , V_76 . V_42 ) ;
F_9 ( V_88 , V_78 . V_42 ) ;
V_78 . V_89 = 1 ;
V_78 . V_90 = F_5 ( V_20 . V_32 [ V_68 ] )
>> V_87 ;
F_8 ( V_88 , V_78 . V_42 ) ;
F_9 ( V_91 + V_92 , V_80 . V_42 ) ;
V_80 . V_42 = 0 ;
V_80 . V_93 = V_94 ;
V_80 . V_95 = false ;
V_80 . V_96 = true ;
F_8 ( V_91 + V_92 , V_80 . V_42 ) ;
F_9 ( V_97 , V_82 . V_42 ) ;
V_82 . V_47 = 1 ;
F_8 ( V_97 , V_82 . V_42 ) ;
V_20 . V_98 = true ;
F_9 ( V_99 , V_36 ) ;
V_20 . V_36 [ V_68 ] = ( T_2 ) V_36 ;
F_30 ( & V_20 . V_100 [ V_68 ] ) ;
return;
}
void F_31 ( void * V_73 )
{
union V_79 V_80 ;
union V_75 V_76 ;
union V_77 V_78 ;
int V_68 = F_29 () ;
if ( ! V_20 . V_98 )
return;
F_9 ( V_91 + V_92 , V_80 . V_42 ) ;
V_80 . V_95 = 1 ;
F_8 ( V_91 + V_92 , V_80 . V_42 ) ;
F_9 ( V_84 , V_76 . V_42 ) ;
V_76 . V_85 = 0 ;
V_76 . V_86 = 0 ;
F_8 ( V_84 , V_76 . V_42 ) ;
F_9 ( V_88 , V_78 . V_42 ) ;
V_78 . V_89 = 0 ;
V_78 . V_90 = 0 ;
F_8 ( V_88 , V_78 . V_42 ) ;
F_26 ( ( unsigned long ) V_20 . V_34 [ V_68 ] ) ;
F_26 ( ( unsigned long ) V_20 . V_32 [ V_68 ] ) ;
}
