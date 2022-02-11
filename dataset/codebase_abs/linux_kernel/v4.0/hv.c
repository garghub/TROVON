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
memset ( V_20 . V_38 , 0 ,
sizeof( void * ) * V_33 ) ;
V_5 = F_1 () ;
V_20 . V_39 = F_7 ( 0 , V_40 , 0 ) ;
F_8 ( V_41 , V_20 . V_39 ) ;
F_9 ( V_42 , V_30 . V_43 ) ;
V_31 = F_10 ( V_44 , V_45 , V_46 ) ;
if ( ! V_31 )
goto V_47;
V_30 . V_48 = 1 ;
V_30 . V_49 = F_11 ( V_31 ) ;
F_8 ( V_42 , V_30 . V_43 ) ;
V_30 . V_43 = 0 ;
F_9 ( V_42 , V_30 . V_43 ) ;
if ( ! V_30 . V_48 )
goto V_47;
V_20 . V_19 = V_31 ;
return 0 ;
V_47:
if ( V_31 ) {
if ( V_30 . V_48 ) {
V_30 . V_43 = 0 ;
F_8 ( V_42 , V_30 . V_43 ) ;
}
F_12 ( V_31 ) ;
}
return - V_50 ;
}
void F_13 ( void )
{
union V_29 V_30 ;
F_8 ( V_41 , 0 ) ;
if ( V_20 . V_19 ) {
V_30 . V_43 = 0 ;
F_8 ( V_42 , V_30 . V_43 ) ;
F_12 ( V_20 . V_19 ) ;
V_20 . V_19 = NULL ;
}
}
int F_14 ( union V_51 V_52 ,
enum V_53 V_54 ,
void * V_55 , T_3 V_56 )
{
struct V_57 * V_58 ;
T_4 V_59 ;
if ( V_56 > V_60 )
return - V_61 ;
V_58 = (struct V_57 * )
V_20 . V_35 [ F_15 () ] ;
V_58 -> V_62 = V_52 ;
V_58 -> V_63 = 0 ;
V_58 -> V_54 = V_54 ;
V_58 -> V_56 = V_56 ;
memcpy ( ( void * ) V_58 -> V_55 , V_55 , V_56 ) ;
V_59 = F_3 ( V_64 , V_58 , NULL )
& 0xFFFF ;
F_16 () ;
return V_59 ;
}
T_4 F_17 ( void * V_65 )
{
T_4 V_59 ;
V_59 = ( F_3 ( V_66 , V_65 , NULL ) & 0xFFFF ) ;
return V_59 ;
}
static int F_18 ( unsigned long V_67 ,
struct V_68 * V_69 )
{
T_5 V_70 ;
F_19 ( V_69 -> V_71 != V_72 ) ;
F_9 ( V_73 , V_70 ) ;
V_70 += V_67 ;
F_8 ( V_74 , V_70 ) ;
return 0 ;
}
static void F_20 ( enum V_75 V_71 ,
struct V_68 * V_69 )
{
union V_76 V_77 ;
switch ( V_71 ) {
case V_78 :
break;
case V_72 :
V_77 . V_48 = 1 ;
V_77 . V_79 = 1 ;
V_77 . V_80 = V_81 ;
F_8 ( V_82 , V_77 . V_43 ) ;
break;
case V_83 :
case V_84 :
F_8 ( V_74 , 0 ) ;
F_8 ( V_82 , 0 ) ;
break;
case V_85 :
break;
}
}
static void F_21 ( struct V_68 * V_86 , int V_87 )
{
V_86 -> V_88 = L_1 ;
V_86 -> V_89 = V_90 ;
V_86 -> V_91 = F_22 ( V_87 ) ;
V_86 -> V_92 = 1000 ;
V_86 -> V_93 = V_94 ;
V_86 -> V_95 = F_20 ;
V_86 -> V_96 = F_18 ;
}
int F_23 ( void )
{
T_3 V_97 = sizeof( struct V_98 ) ;
T_3 V_99 = sizeof( struct V_68 ) ;
int V_87 ;
F_24 (cpu) {
V_20 . V_37 [ V_87 ] = F_25 ( V_97 , V_100 ) ;
if ( V_20 . V_37 [ V_87 ] == NULL ) {
F_26 ( L_2 ) ;
goto V_101;
}
F_27 ( V_20 . V_37 [ V_87 ] , V_102 , V_87 ) ;
V_20 . V_38 [ V_87 ] = F_28 ( V_99 , V_100 ) ;
if ( V_20 . V_38 [ V_87 ] == NULL ) {
F_26 ( L_3 ) ;
goto V_101;
}
F_21 ( V_20 . V_38 [ V_87 ] , V_87 ) ;
V_20 . V_34 [ V_87 ] =
( void * ) F_29 ( V_100 ) ;
if ( V_20 . V_34 [ V_87 ] == NULL ) {
F_26 ( L_4 ) ;
goto V_101;
}
V_20 . V_32 [ V_87 ] =
( void * ) F_29 ( V_100 ) ;
if ( V_20 . V_32 [ V_87 ] == NULL ) {
F_26 ( L_5 ) ;
goto V_101;
}
V_20 . V_35 [ V_87 ] =
( void * ) F_29 ( V_100 ) ;
if ( V_20 . V_35 [ V_87 ] == NULL ) {
F_26 ( L_6 ) ;
goto V_101;
}
}
return 0 ;
V_101:
return - V_103 ;
}
static void F_30 ( int V_87 )
{
F_31 ( V_20 . V_37 [ V_87 ] ) ;
F_31 ( V_20 . V_38 [ V_87 ] ) ;
if ( V_20 . V_32 [ V_87 ] )
F_32 ( ( unsigned long ) V_20 . V_32 [ V_87 ] ) ;
if ( V_20 . V_34 [ V_87 ] )
F_32 ( ( unsigned long ) V_20 . V_34 [ V_87 ] ) ;
if ( V_20 . V_35 [ V_87 ] )
F_32 ( ( unsigned long ) V_20 . V_35 [ V_87 ] ) ;
}
void F_33 ( void )
{
int V_87 ;
F_24 (cpu)
F_30 ( V_87 ) ;
}
void F_34 ( void * V_104 )
{
T_1 V_105 ;
union V_106 V_107 ;
union V_108 V_109 ;
union V_110 V_111 ;
union V_112 V_113 ;
T_1 V_36 ;
int V_87 = F_35 () ;
if ( ! V_20 . V_19 )
return;
F_9 ( V_114 , V_105 ) ;
F_9 ( V_115 , V_107 . V_43 ) ;
V_107 . V_116 = 1 ;
V_107 . V_117 = F_5 ( V_20 . V_34 [ V_87 ] )
>> V_118 ;
F_8 ( V_115 , V_107 . V_43 ) ;
F_9 ( V_119 , V_109 . V_43 ) ;
V_109 . V_120 = 1 ;
V_109 . V_121 = F_5 ( V_20 . V_32 [ V_87 ] )
>> V_118 ;
F_8 ( V_119 , V_109 . V_43 ) ;
F_9 ( V_122 + V_81 , V_111 . V_43 ) ;
V_111 . V_43 = 0 ;
V_111 . V_123 = V_124 ;
V_111 . V_125 = false ;
V_111 . V_126 = true ;
F_8 ( V_122 + V_81 , V_111 . V_43 ) ;
F_9 ( V_127 , V_113 . V_43 ) ;
V_113 . V_48 = 1 ;
F_8 ( V_127 , V_113 . V_43 ) ;
V_20 . V_128 = true ;
F_9 ( V_129 , V_36 ) ;
V_20 . V_36 [ V_87 ] = ( T_2 ) V_36 ;
F_36 ( & V_20 . V_130 [ V_87 ] ) ;
if ( V_131 . V_89 & V_132 )
F_37 ( V_20 . V_38 [ V_87 ] ,
V_133 ,
V_134 ,
V_135 ) ;
return;
}
void F_38 ( void * V_104 )
{
union V_110 V_111 ;
union V_106 V_107 ;
union V_108 V_109 ;
int V_87 = F_35 () ;
if ( ! V_20 . V_128 )
return;
F_9 ( V_122 + V_81 , V_111 . V_43 ) ;
V_111 . V_125 = 1 ;
F_8 ( V_122 + V_81 , V_111 . V_43 ) ;
F_9 ( V_115 , V_107 . V_43 ) ;
V_107 . V_116 = 0 ;
V_107 . V_117 = 0 ;
F_8 ( V_115 , V_107 . V_43 ) ;
F_9 ( V_119 , V_109 . V_43 ) ;
V_109 . V_120 = 0 ;
V_109 . V_121 = 0 ;
F_8 ( V_119 , V_109 . V_43 ) ;
F_32 ( ( unsigned long ) V_20 . V_34 [ V_87 ] ) ;
F_32 ( ( unsigned long ) V_20 . V_32 [ V_87 ] ) ;
}
