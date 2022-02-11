static int F_1 ( void )
{
unsigned int V_1 ;
unsigned int V_2 ;
unsigned int V_3 ;
unsigned int V_4 ;
unsigned int V_5 ;
V_1 = 0 ;
V_2 = 0 ;
V_3 = 0 ;
V_4 = 0 ;
V_5 = V_6 ;
F_2 ( V_5 , & V_1 , & V_2 , & V_3 , & V_4 ) ;
return V_3 & V_7 ;
}
static int F_3 ( void )
{
unsigned int V_1 ;
unsigned int V_2 ;
unsigned int V_3 ;
unsigned int V_4 ;
unsigned int V_8 ;
unsigned int V_5 ;
V_1 = 0 ;
V_2 = 0 ;
V_3 = 0 ;
V_4 = 0 ;
V_5 = V_9 ;
F_2 ( V_5 , & V_1 , & V_2 , & V_3 , & V_4 ) ;
V_8 = V_1 ;
if ( V_8 >= V_10 ) {
V_1 = 0 ;
V_2 = 0 ;
V_3 = 0 ;
V_4 = 0 ;
V_5 = V_10 ;
F_2 ( V_5 , & V_1 , & V_2 , & V_3 , & V_4 ) ;
F_4 ( L_1 ,
V_1 ,
V_2 >> 16 ,
V_2 & 0xFFFF ,
V_3 ,
V_4 >> 24 ,
V_4 & 0xFFFFFF ) ;
}
return V_8 ;
}
static T_1 F_5 ( T_1 V_11 , void * V_12 , void * V_13 )
{
#ifdef F_6
T_1 V_14 = 0 ;
T_1 V_15 = ( V_12 ) ? F_7 ( V_12 ) : 0 ;
T_1 V_16 = ( V_13 ) ? F_7 ( V_13 ) : 0 ;
volatile void * V_17 = V_18 . V_17 ;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_page));
return V_14 ;
#else
T_2 V_19 = V_11 >> 32 ;
T_2 V_20 = V_11 & 0xFFFFFFFF ;
T_2 V_21 = 1 ;
T_2 V_22 = 1 ;
T_1 V_15 = ( V_12 ) ? F_7 ( V_12 ) : 0 ;
T_2 V_23 = V_15 >> 32 ;
T_2 V_24 = V_15 & 0xFFFFFFFF ;
T_1 V_16 = ( V_13 ) ? F_7 ( V_13 ) : 0 ;
T_2 V_25 = V_16 >> 32 ;
T_2 V_26 = V_16 & 0xFFFFFFFF ;
volatile void * V_17 = V_18 . V_17 ;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_page));
return V_22 | ( ( T_1 ) V_21 << 32 ) ;
#endif
}
int F_8 ( void )
{
int V_27 = 0 ;
int V_8 ;
union V_28 V_29 ;
void * V_30 = NULL ;
memset ( V_18 . V_31 , 0 , sizeof( void * ) * V_32 ) ;
memset ( V_18 . V_33 , 0 ,
sizeof( void * ) * V_32 ) ;
if ( ! F_1 () )
goto V_34;
V_8 = F_3 () ;
F_9 ( V_35 , V_18 . V_36 ) ;
if ( V_18 . V_36 != 0 )
goto V_34;
F_10 ( V_35 , V_37 ) ;
V_18 . V_36 = V_37 ;
F_9 ( V_38 , V_29 . V_39 ) ;
V_30 = F_11 ( V_40 , V_41 , V_42 ) ;
if ( ! V_30 )
goto V_34;
V_29 . V_43 = 1 ;
V_29 . V_44 = F_12 ( V_30 ) ;
F_10 ( V_38 , V_29 . V_39 ) ;
V_29 . V_39 = 0 ;
F_9 ( V_38 , V_29 . V_39 ) ;
if ( ! V_29 . V_43 )
goto V_34;
V_18 . V_17 = V_30 ;
V_18 . V_45 =
F_13 ( sizeof( struct V_46 ) ,
V_41 ) ;
if ( ! V_18 . V_45 )
goto V_34;
V_18 . V_47 =
(struct V_48 * )
( F_14 ( ( unsigned long )
V_18 . V_45 ,
V_49 ) ) ;
V_18 . V_47 -> V_50 . V_51 = 0 ;
V_18 . V_47 -> V_50 . V_52 . V_53 =
V_54 ;
V_18 . V_47 -> V_55 = 0 ;
V_18 . V_47 -> V_56 = 0 ;
return V_27 ;
V_34:
if ( V_30 ) {
if ( V_29 . V_43 ) {
V_29 . V_39 = 0 ;
F_10 ( V_38 , V_29 . V_39 ) ;
}
F_15 ( V_30 ) ;
}
V_27 = - 1 ;
return V_27 ;
}
void F_16 ( void )
{
union V_28 V_29 ;
F_17 ( V_18 . V_45 ) ;
V_18 . V_45 = NULL ;
V_18 . V_47 = NULL ;
if ( V_18 . V_17 ) {
V_29 . V_39 = 0 ;
F_10 ( V_38 , V_29 . V_39 ) ;
F_15 ( V_18 . V_17 ) ;
V_18 . V_17 = NULL ;
}
}
T_3 F_18 ( union V_57 V_58 ,
enum V_59 V_60 ,
void * V_61 , T_4 V_62 )
{
struct V_63 {
T_1 V_64 ;
struct V_65 V_66 ;
};
struct V_65 * V_67 ;
T_3 V_68 ;
unsigned long V_69 ;
if ( V_62 > V_70 )
return - V_71 ;
V_69 = ( unsigned long ) F_13 ( sizeof( struct V_63 ) , V_72 ) ;
if ( ! V_69 )
return - V_73 ;
V_67 = (struct V_65 * )
( F_14 ( V_69 , V_49 ) ) ;
V_67 -> V_50 = V_58 ;
V_67 -> V_60 = V_60 ;
V_67 -> V_62 = V_62 ;
memcpy ( ( void * ) V_67 -> V_61 , V_61 , V_62 ) ;
V_68 = F_5 ( V_74 , V_67 , NULL )
& 0xFFFF ;
F_17 ( ( void * ) V_69 ) ;
return V_68 ;
}
T_3 F_19 ( void )
{
T_3 V_68 ;
V_68 = F_5 ( V_75 ,
V_18 . V_47 ,
NULL ) & 0xFFFF ;
return V_68 ;
}
void F_20 ( void * V_76 )
{
T_1 V_77 ;
union V_78 V_79 ;
union V_80 V_81 ;
union V_82 V_83 ;
union V_84 V_85 ;
T_2 V_86 = * ( ( T_2 * ) ( V_76 ) ) ;
int V_87 = F_21 () ;
if ( ! V_18 . V_17 )
return;
F_9 ( V_88 , V_77 ) ;
V_18 . V_33 [ V_87 ] =
( void * ) F_22 ( V_72 ) ;
if ( V_18 . V_33 [ V_87 ] == NULL ) {
F_23 ( L_2 ) ;
goto V_34;
}
V_18 . V_31 [ V_87 ] =
( void * ) F_22 ( V_72 ) ;
if ( V_18 . V_31 [ V_87 ] == NULL ) {
F_23 ( L_3 ) ;
goto V_34;
}
F_9 ( V_89 , V_79 . V_39 ) ;
V_79 . V_90 = 1 ;
V_79 . V_91 = F_7 ( V_18 . V_33 [ V_87 ] )
>> V_92 ;
F_10 ( V_89 , V_79 . V_39 ) ;
F_9 ( V_93 , V_81 . V_39 ) ;
V_81 . V_94 = 1 ;
V_81 . V_95 = F_7 ( V_18 . V_31 [ V_87 ] )
>> V_92 ;
F_10 ( V_93 , V_81 . V_39 ) ;
F_9 ( V_96 + V_97 , V_83 . V_39 ) ;
V_83 . V_39 = 0 ;
V_83 . V_98 = V_86 ;
V_83 . V_99 = false ;
V_83 . V_100 = true ;
F_10 ( V_96 + V_97 , V_83 . V_39 ) ;
F_9 ( V_101 , V_85 . V_39 ) ;
V_85 . V_43 = 1 ;
F_10 ( V_101 , V_85 . V_39 ) ;
V_18 . V_102 = true ;
return;
V_34:
if ( V_18 . V_31 [ V_87 ] )
F_24 ( ( unsigned long ) V_18 . V_31 [ V_87 ] ) ;
if ( V_18 . V_33 [ V_87 ] )
F_24 ( ( unsigned long ) V_18 . V_33 [ V_87 ] ) ;
return;
}
void F_25 ( void * V_103 )
{
union V_82 V_83 ;
union V_78 V_79 ;
union V_80 V_81 ;
int V_87 = F_21 () ;
if ( ! V_18 . V_102 )
return;
F_9 ( V_96 + V_97 , V_83 . V_39 ) ;
V_83 . V_99 = 1 ;
F_10 ( V_96 + V_97 , V_83 . V_39 ) ;
F_9 ( V_89 , V_79 . V_39 ) ;
V_79 . V_90 = 0 ;
V_79 . V_91 = 0 ;
F_10 ( V_89 , V_79 . V_39 ) ;
F_9 ( V_93 , V_81 . V_39 ) ;
V_81 . V_94 = 0 ;
V_81 . V_95 = 0 ;
F_10 ( V_93 , V_81 . V_39 ) ;
F_24 ( ( unsigned long ) V_18 . V_33 [ V_87 ] ) ;
F_24 ( ( unsigned long ) V_18 . V_31 [ V_87 ] ) ;
}
