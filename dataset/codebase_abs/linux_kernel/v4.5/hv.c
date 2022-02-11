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
T_1 F_3 ( T_1 V_13 , void * V_14 , void * V_15 )
{
T_1 V_16 = ( V_14 ) ? F_4 ( V_14 ) : 0 ;
T_1 V_17 = ( V_15 ) ? F_4 ( V_15 ) : 0 ;
void * V_18 = V_19 . V_18 ;
#ifdef F_5
T_1 V_20 = 0 ;
if ( ! V_18 )
return ( T_1 ) V_21 ;
__asm__ __volatile__("mov %0, %%r8" : : "r" (output_address) : "r8");
__asm__ __volatile__("call *%3" : "=a" (hv_status) :
"c" (control), "d" (input_address),
"m" (hypercall_page));
return V_20 ;
#else
T_2 V_22 = V_13 >> 32 ;
T_2 V_23 = V_13 & 0xFFFFFFFF ;
T_2 V_24 = 1 ;
T_2 V_25 = 1 ;
T_2 V_26 = V_16 >> 32 ;
T_2 V_27 = V_16 & 0xFFFFFFFF ;
T_2 V_28 = V_17 >> 32 ;
T_2 V_29 = V_17 & 0xFFFFFFFF ;
if ( ! V_18 )
return ( T_1 ) V_21 ;
__asm__ __volatile__ ("call *%8" : "=d"(hv_status_hi),
"=a"(hv_status_lo) : "d" (control_hi),
"a" (control_lo), "b" (input_address_hi),
"c" (input_address_lo), "D"(output_address_hi),
"S"(output_address_lo), "m" (hypercall_page));
return V_25 | ( ( T_1 ) V_24 << 32 ) ;
#endif
}
static T_3 F_6 ( struct V_30 * V_31 )
{
T_3 V_32 ;
struct V_33 * V_34 = V_19 . V_35 ;
if ( V_34 -> V_36 != 0 ) {
while ( 1 ) {
T_3 V_37 ;
T_2 V_38 = V_34 -> V_36 ;
T_1 V_39 ;
T_1 V_40 = V_34 -> V_41 ;
T_4 V_42 = V_34 -> V_43 ;
F_7 ( V_39 ) ;
asm("mulq %3"
: "=d" (current_tick), "=a" (tmp)
: "a" (cur_tsc), "r" (scale));
V_32 += V_42 ;
if ( V_34 -> V_36 == V_38 )
return V_32 ;
if ( V_34 -> V_36 != 0 )
continue;
break;
}
}
F_8 ( V_44 , V_32 ) ;
return V_32 ;
}
int F_9 ( void )
{
int V_5 ;
union V_45 V_46 ;
void * V_47 = NULL ;
memset ( V_19 . V_48 , 0 , sizeof( void * ) * V_49 ) ;
memset ( V_19 . V_50 , 0 ,
sizeof( void * ) * V_49 ) ;
memset ( V_19 . V_51 , 0 ,
sizeof( void * ) * V_49 ) ;
memset ( V_19 . V_52 , 0 ,
sizeof( int ) * V_49 ) ;
memset ( V_19 . V_53 , 0 ,
sizeof( void * ) * V_49 ) ;
memset ( V_19 . V_54 , 0 ,
sizeof( void * ) * V_49 ) ;
V_5 = F_1 () ;
V_19 . V_55 = F_10 ( 0 , V_56 , 0 ) ;
F_11 ( V_57 , V_19 . V_55 ) ;
F_8 ( V_58 , V_46 . V_59 ) ;
V_47 = F_12 ( V_60 , V_61 , V_62 ) ;
if ( ! V_47 )
goto V_63;
V_46 . V_64 = 1 ;
V_46 . V_65 = F_13 ( V_47 ) ;
F_11 ( V_58 , V_46 . V_59 ) ;
V_46 . V_59 = 0 ;
F_8 ( V_58 , V_46 . V_59 ) ;
if ( ! V_46 . V_64 )
goto V_63;
V_19 . V_18 = V_47 ;
#ifdef F_5
if ( V_66 . V_67 & V_68 ) {
union V_45 V_69 ;
void * V_70 ;
V_70 = F_12 ( V_60 , V_61 , V_71 ) ;
if ( ! V_70 )
goto V_63;
V_19 . V_35 = V_70 ;
F_8 ( V_72 , V_69 . V_59 ) ;
V_69 . V_64 = 1 ;
V_69 . V_65 = F_13 ( V_70 ) ;
F_11 ( V_72 , V_69 . V_59 ) ;
F_14 ( & V_73 , V_74 / 100 ) ;
}
#endif
return 0 ;
V_63:
if ( V_47 ) {
if ( V_46 . V_64 ) {
V_46 . V_59 = 0 ;
F_11 ( V_58 , V_46 . V_59 ) ;
}
F_15 ( V_47 ) ;
}
return - V_75 ;
}
void F_16 ( void )
{
union V_45 V_46 ;
F_11 ( V_57 , 0 ) ;
if ( V_19 . V_18 ) {
V_46 . V_59 = 0 ;
F_11 ( V_58 , V_46 . V_59 ) ;
F_15 ( V_19 . V_18 ) ;
V_19 . V_18 = NULL ;
}
#ifdef F_5
if ( V_66 . V_67 & V_68 ) {
F_17 ( & V_73 , 10 ) ;
F_18 ( & V_73 ) ;
V_46 . V_59 = 0 ;
F_11 ( V_72 , V_46 . V_59 ) ;
F_15 ( V_19 . V_35 ) ;
V_19 . V_35 = NULL ;
}
#endif
}
int F_19 ( union V_76 V_77 ,
enum V_78 V_79 ,
void * V_80 , T_5 V_81 )
{
struct V_82 * V_83 ;
T_1 V_84 ;
if ( V_81 > V_85 )
return - V_86 ;
V_83 = (struct V_82 * )
V_19 . V_51 [ F_20 () ] ;
V_83 -> V_87 = V_77 ;
V_83 -> V_88 = 0 ;
V_83 -> V_79 = V_79 ;
V_83 -> V_81 = V_81 ;
memcpy ( ( void * ) V_83 -> V_80 , V_80 , V_81 ) ;
V_84 = F_3 ( V_89 , V_83 , NULL ) ;
F_21 () ;
return V_84 & 0xFFFF ;
}
int F_22 ( void * V_90 )
{
T_1 V_84 ;
V_84 = F_3 ( V_91 , V_90 , NULL ) ;
return V_84 & 0xFFFF ;
}
static int F_23 ( unsigned long V_92 ,
struct V_93 * V_94 )
{
T_3 V_32 ;
F_24 ( ! F_25 ( V_94 ) ) ;
F_8 ( V_44 , V_32 ) ;
V_32 += V_92 ;
F_11 ( V_95 , V_32 ) ;
return 0 ;
}
static int F_26 ( struct V_93 * V_94 )
{
F_11 ( V_95 , 0 ) ;
F_11 ( V_96 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_93 * V_94 )
{
union V_97 V_98 ;
V_98 . V_64 = 1 ;
V_98 . V_99 = 1 ;
V_98 . V_100 = V_101 ;
F_11 ( V_96 , V_98 . V_59 ) ;
return 0 ;
}
static void F_28 ( struct V_93 * V_102 , int V_103 )
{
V_102 -> V_104 = L_1 ;
V_102 -> V_67 = V_105 ;
V_102 -> V_106 = F_29 ( V_103 ) ;
V_102 -> V_107 = 1000 ;
V_102 -> V_108 = F_26 ;
V_102 -> V_109 = F_27 ;
V_102 -> V_110 = F_23 ;
}
int F_30 ( void )
{
T_5 V_111 = sizeof( struct V_112 ) ;
T_5 V_113 = sizeof( struct V_93 ) ;
int V_103 ;
V_19 . V_114 = F_31 ( sizeof( struct V_106 ) * V_115 ,
V_116 ) ;
if ( V_19 . V_114 == NULL ) {
F_32 ( L_2 ) ;
goto V_117;
}
F_33 (cpu) {
V_19 . V_53 [ V_103 ] = F_34 ( V_111 , V_116 ) ;
if ( V_19 . V_53 [ V_103 ] == NULL ) {
F_32 ( L_3 ) ;
goto V_117;
}
F_35 ( V_19 . V_53 [ V_103 ] , V_118 , V_103 ) ;
V_19 . V_54 [ V_103 ] = F_31 ( V_113 , V_116 ) ;
if ( V_19 . V_54 [ V_103 ] == NULL ) {
F_32 ( L_4 ) ;
goto V_117;
}
F_28 ( V_19 . V_54 [ V_103 ] , V_103 ) ;
V_19 . V_50 [ V_103 ] =
( void * ) F_36 ( V_116 ) ;
if ( V_19 . V_50 [ V_103 ] == NULL ) {
F_32 ( L_5 ) ;
goto V_117;
}
V_19 . V_48 [ V_103 ] =
( void * ) F_36 ( V_116 ) ;
if ( V_19 . V_48 [ V_103 ] == NULL ) {
F_32 ( L_6 ) ;
goto V_117;
}
V_19 . V_51 [ V_103 ] =
( void * ) F_36 ( V_116 ) ;
if ( V_19 . V_51 [ V_103 ] == NULL ) {
F_32 ( L_7 ) ;
goto V_117;
}
}
return 0 ;
V_117:
return - V_119 ;
}
static void F_37 ( int V_103 )
{
F_38 ( V_19 . V_53 [ V_103 ] ) ;
F_38 ( V_19 . V_54 [ V_103 ] ) ;
if ( V_19 . V_48 [ V_103 ] )
F_39 ( ( unsigned long ) V_19 . V_48 [ V_103 ] ) ;
if ( V_19 . V_50 [ V_103 ] )
F_39 ( ( unsigned long ) V_19 . V_50 [ V_103 ] ) ;
if ( V_19 . V_51 [ V_103 ] )
F_39 ( ( unsigned long ) V_19 . V_51 [ V_103 ] ) ;
}
void F_40 ( void )
{
int V_103 ;
F_38 ( V_19 . V_114 ) ;
F_33 (cpu)
F_37 ( V_103 ) ;
}
void F_41 ( void * V_31 )
{
T_1 V_120 ;
union V_121 V_122 ;
union V_123 V_124 ;
union V_125 V_126 ;
union V_127 V_128 ;
T_1 V_52 ;
int V_103 = F_42 () ;
if ( ! V_19 . V_18 )
return;
F_8 ( V_129 , V_120 ) ;
F_8 ( V_130 , V_122 . V_59 ) ;
V_122 . V_131 = 1 ;
V_122 . V_132 = F_4 ( V_19 . V_50 [ V_103 ] )
>> V_133 ;
F_11 ( V_130 , V_122 . V_59 ) ;
F_8 ( V_134 , V_124 . V_59 ) ;
V_124 . V_135 = 1 ;
V_124 . V_136 = F_4 ( V_19 . V_48 [ V_103 ] )
>> V_133 ;
F_11 ( V_134 , V_124 . V_59 ) ;
F_8 ( V_137 + V_101 , V_126 . V_59 ) ;
V_126 . V_59 = 0 ;
V_126 . V_138 = V_139 ;
V_126 . V_140 = false ;
V_126 . V_141 = true ;
F_11 ( V_137 + V_101 , V_126 . V_59 ) ;
F_8 ( V_142 , V_128 . V_59 ) ;
V_128 . V_64 = 1 ;
F_11 ( V_142 , V_128 . V_59 ) ;
V_19 . V_143 = true ;
F_8 ( V_144 , V_52 ) ;
V_19 . V_52 [ V_103 ] = ( T_2 ) V_52 ;
F_43 ( & V_19 . V_145 [ V_103 ] ) ;
if ( V_66 . V_67 & V_146 )
F_44 ( V_19 . V_54 [ V_103 ] ,
V_147 ,
V_148 ,
V_149 ) ;
return;
}
void F_45 ( void )
{
int V_103 ;
if ( ! ( V_66 . V_67 & V_146 ) )
return;
F_33 (cpu)
F_46 ( V_19 . V_54 [ V_103 ] , V_103 ) ;
}
void F_47 ( void * V_31 )
{
union V_125 V_126 ;
union V_121 V_122 ;
union V_123 V_124 ;
union V_127 V_128 ;
int V_103 = F_42 () ;
if ( ! V_19 . V_143 )
return;
if ( V_66 . V_67 & V_146 )
F_26 ( V_19 . V_54 [ V_103 ] ) ;
F_8 ( V_137 + V_101 , V_126 . V_59 ) ;
V_126 . V_140 = 1 ;
F_11 ( V_137 + V_101 , V_126 . V_59 ) ;
F_8 ( V_130 , V_122 . V_59 ) ;
V_122 . V_131 = 0 ;
V_122 . V_132 = 0 ;
F_11 ( V_130 , V_122 . V_59 ) ;
F_8 ( V_134 , V_124 . V_59 ) ;
V_124 . V_135 = 0 ;
V_124 . V_136 = 0 ;
F_11 ( V_134 , V_124 . V_59 ) ;
F_8 ( V_142 , V_128 . V_59 ) ;
V_128 . V_64 = 0 ;
F_11 ( V_142 , V_128 . V_59 ) ;
}
