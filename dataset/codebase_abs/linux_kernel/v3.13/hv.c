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
sizeof( int ) * V_33 ) ;
memset ( V_20 . V_36 , 0 ,
sizeof( void * ) * V_33 ) ;
V_5 = F_1 () ;
V_20 . V_37 = F_7 ( 0 , V_38 , 0 ) ;
F_8 ( V_39 , V_20 . V_37 ) ;
F_9 ( V_40 , V_30 . V_41 ) ;
V_31 = F_10 ( V_42 , V_43 , V_44 ) ;
if ( ! V_31 )
goto V_45;
V_30 . V_46 = 1 ;
V_30 . V_47 = F_11 ( V_31 ) ;
F_8 ( V_40 , V_30 . V_41 ) ;
V_30 . V_41 = 0 ;
F_9 ( V_40 , V_30 . V_41 ) ;
if ( ! V_30 . V_46 )
goto V_45;
V_20 . V_19 = V_31 ;
return 0 ;
V_45:
if ( V_31 ) {
if ( V_30 . V_46 ) {
V_30 . V_41 = 0 ;
F_8 ( V_40 , V_30 . V_41 ) ;
}
F_12 ( V_31 ) ;
}
return - V_48 ;
}
void F_13 ( void )
{
union V_29 V_30 ;
F_8 ( V_39 , 0 ) ;
if ( V_20 . V_19 ) {
V_30 . V_41 = 0 ;
F_8 ( V_40 , V_30 . V_41 ) ;
F_12 ( V_20 . V_19 ) ;
V_20 . V_19 = NULL ;
}
}
int F_14 ( union V_49 V_50 ,
enum V_51 V_52 ,
void * V_53 , T_3 V_54 )
{
struct V_55 {
T_1 V_56 ;
struct V_57 V_58 ;
};
struct V_57 * V_59 ;
T_4 V_60 ;
unsigned long V_61 ;
if ( V_54 > V_62 )
return - V_63 ;
V_61 = ( unsigned long ) F_15 ( sizeof( struct V_55 ) , V_64 ) ;
if ( ! V_61 )
return - V_65 ;
V_59 = (struct V_57 * )
( F_16 ( V_61 , V_66 ) ) ;
V_59 -> V_67 = V_50 ;
V_59 -> V_52 = V_52 ;
V_59 -> V_54 = V_54 ;
memcpy ( ( void * ) V_59 -> V_53 , V_53 , V_54 ) ;
V_60 = F_3 ( V_68 , V_59 , NULL )
& 0xFFFF ;
F_17 ( ( void * ) V_61 ) ;
return V_60 ;
}
T_4 F_18 ( void * V_69 )
{
T_4 V_60 ;
V_60 = ( F_3 ( V_70 , V_69 , NULL ) & 0xFFFF ) ;
return V_60 ;
}
int F_19 ( void )
{
T_3 V_71 = sizeof( struct V_72 ) ;
int V_73 ;
F_20 (cpu) {
V_20 . V_36 [ V_73 ] = F_15 ( V_71 , V_64 ) ;
if ( V_20 . V_36 [ V_73 ] == NULL ) {
F_21 ( L_1 ) ;
goto V_74;
}
F_22 ( V_20 . V_36 [ V_73 ] , V_75 , V_73 ) ;
V_20 . V_34 [ V_73 ] =
( void * ) F_23 ( V_64 ) ;
if ( V_20 . V_34 [ V_73 ] == NULL ) {
F_21 ( L_2 ) ;
goto V_74;
}
V_20 . V_32 [ V_73 ] =
( void * ) F_23 ( V_64 ) ;
if ( V_20 . V_32 [ V_73 ] == NULL ) {
F_21 ( L_3 ) ;
goto V_74;
}
}
return 0 ;
V_74:
return - V_65 ;
}
void F_24 ( int V_73 )
{
F_17 ( V_20 . V_36 [ V_73 ] ) ;
if ( V_20 . V_32 [ V_73 ] )
F_25 ( ( unsigned long ) V_20 . V_32 [ V_73 ] ) ;
if ( V_20 . V_34 [ V_73 ] )
F_25 ( ( unsigned long ) V_20 . V_34 [ V_73 ] ) ;
}
void F_26 ( void )
{
int V_73 ;
F_20 (cpu)
F_24 ( V_73 ) ;
}
void F_27 ( void * V_76 )
{
T_1 V_77 ;
union V_78 V_79 ;
union V_80 V_81 ;
union V_82 V_83 ;
union V_84 V_85 ;
T_1 V_35 ;
int V_73 = F_28 () ;
if ( ! V_20 . V_19 )
return;
F_9 ( V_86 , V_77 ) ;
F_9 ( V_87 , V_79 . V_41 ) ;
V_79 . V_88 = 1 ;
V_79 . V_89 = F_5 ( V_20 . V_34 [ V_73 ] )
>> V_90 ;
F_8 ( V_87 , V_79 . V_41 ) ;
F_9 ( V_91 , V_81 . V_41 ) ;
V_81 . V_92 = 1 ;
V_81 . V_93 = F_5 ( V_20 . V_32 [ V_73 ] )
>> V_90 ;
F_8 ( V_91 , V_81 . V_41 ) ;
F_9 ( V_94 + V_95 , V_83 . V_41 ) ;
V_83 . V_41 = 0 ;
V_83 . V_96 = V_97 ;
V_83 . V_98 = false ;
V_83 . V_99 = true ;
F_8 ( V_94 + V_95 , V_83 . V_41 ) ;
F_9 ( V_100 , V_85 . V_41 ) ;
V_85 . V_46 = 1 ;
F_8 ( V_100 , V_85 . V_41 ) ;
V_20 . V_101 = true ;
F_9 ( V_102 , V_35 ) ;
V_20 . V_35 [ V_73 ] = ( T_2 ) V_35 ;
return;
}
void F_29 ( void * V_76 )
{
union V_82 V_83 ;
union V_78 V_79 ;
union V_80 V_81 ;
int V_73 = F_28 () ;
if ( ! V_20 . V_101 )
return;
F_9 ( V_94 + V_95 , V_83 . V_41 ) ;
V_83 . V_98 = 1 ;
F_8 ( V_94 + V_95 , V_83 . V_41 ) ;
F_9 ( V_87 , V_79 . V_41 ) ;
V_79 . V_88 = 0 ;
V_79 . V_89 = 0 ;
F_8 ( V_87 , V_79 . V_41 ) ;
F_9 ( V_91 , V_81 . V_41 ) ;
V_81 . V_92 = 0 ;
V_81 . V_93 = 0 ;
F_8 ( V_91 , V_81 . V_41 ) ;
F_25 ( ( unsigned long ) V_20 . V_34 [ V_73 ] ) ;
F_25 ( ( unsigned long ) V_20 . V_32 [ V_73 ] ) ;
}
