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
memset ( V_19 . V_55 , 0 ,
sizeof( void * ) * V_49 ) ;
V_5 = F_1 () ;
V_19 . V_56 = F_10 ( 0 , V_57 , 0 ) ;
F_11 ( V_58 , V_19 . V_56 ) ;
F_8 ( V_59 , V_46 . V_60 ) ;
V_47 = F_12 ( V_61 , V_62 , V_63 ) ;
if ( ! V_47 )
goto V_64;
V_46 . V_65 = 1 ;
V_46 . V_66 = F_13 ( V_47 ) ;
F_11 ( V_59 , V_46 . V_60 ) ;
V_46 . V_60 = 0 ;
F_8 ( V_59 , V_46 . V_60 ) ;
if ( ! V_46 . V_65 )
goto V_64;
V_19 . V_18 = V_47 ;
#ifdef F_5
if ( V_67 . V_68 & V_69 ) {
union V_45 V_70 ;
void * V_71 ;
V_71 = F_12 ( V_61 , V_62 , V_72 ) ;
if ( ! V_71 )
goto V_64;
V_19 . V_35 = V_71 ;
F_8 ( V_73 , V_70 . V_60 ) ;
V_70 . V_65 = 1 ;
V_70 . V_66 = F_13 ( V_71 ) ;
F_11 ( V_73 , V_70 . V_60 ) ;
F_14 ( & V_74 , V_75 / 100 ) ;
}
#endif
return 0 ;
V_64:
if ( V_47 ) {
if ( V_46 . V_65 ) {
V_46 . V_60 = 0 ;
F_11 ( V_59 , V_46 . V_60 ) ;
}
F_15 ( V_47 ) ;
}
return - V_76 ;
}
void F_16 ( bool V_77 )
{
union V_45 V_46 ;
F_11 ( V_58 , 0 ) ;
if ( V_19 . V_18 ) {
V_46 . V_60 = 0 ;
F_11 ( V_59 , V_46 . V_60 ) ;
if ( ! V_77 )
F_15 ( V_19 . V_18 ) ;
V_19 . V_18 = NULL ;
}
#ifdef F_5
if ( V_67 . V_68 & V_69 ) {
if ( ! V_78 ) {
F_17 ( & V_74 , 10 ) ;
F_18 ( & V_74 ) ;
}
V_46 . V_60 = 0 ;
F_11 ( V_73 , V_46 . V_60 ) ;
if ( ! V_77 )
F_15 ( V_19 . V_35 ) ;
V_19 . V_35 = NULL ;
}
#endif
}
int F_19 ( union V_79 V_80 ,
enum V_81 V_82 ,
void * V_83 , T_5 V_84 )
{
struct V_85 * V_86 ;
T_1 V_87 ;
if ( V_84 > V_88 )
return - V_89 ;
V_86 = (struct V_85 * )
V_19 . V_51 [ F_20 () ] ;
V_86 -> V_90 = V_80 ;
V_86 -> V_91 = 0 ;
V_86 -> V_82 = V_82 ;
V_86 -> V_84 = V_84 ;
memcpy ( ( void * ) V_86 -> V_83 , V_83 , V_84 ) ;
V_87 = F_3 ( V_92 , V_86 , NULL ) ;
F_21 () ;
return V_87 & 0xFFFF ;
}
static int F_22 ( unsigned long V_93 ,
struct V_94 * V_95 )
{
T_3 V_32 ;
F_23 ( ! F_24 ( V_95 ) ) ;
F_8 ( V_44 , V_32 ) ;
V_32 += V_93 ;
F_11 ( V_96 , V_32 ) ;
return 0 ;
}
static int F_25 ( struct V_94 * V_95 )
{
F_11 ( V_96 , 0 ) ;
F_11 ( V_97 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_94 * V_95 )
{
union V_98 V_99 ;
V_99 . V_65 = 1 ;
V_99 . V_100 = 1 ;
V_99 . V_101 = V_102 ;
F_11 ( V_97 , V_99 . V_60 ) ;
return 0 ;
}
static void F_27 ( struct V_94 * V_103 , int V_104 )
{
V_103 -> V_105 = L_1 ;
V_103 -> V_68 = V_106 ;
V_103 -> V_107 = F_28 ( V_104 ) ;
V_103 -> V_108 = 1000 ;
V_103 -> V_109 = F_25 ;
V_103 -> V_110 = F_26 ;
V_103 -> V_111 = F_22 ;
}
int F_29 ( void )
{
T_5 V_112 = sizeof( struct V_113 ) ;
T_5 V_114 = sizeof( struct V_94 ) ;
int V_104 ;
V_19 . V_115 = F_30 ( sizeof( struct V_107 ) * V_116 ,
V_117 ) ;
if ( V_19 . V_115 == NULL ) {
F_31 ( L_2 ) ;
goto V_118;
}
F_32 (cpu) {
V_19 . V_53 [ V_104 ] = F_33 ( V_112 , V_117 ) ;
if ( V_19 . V_53 [ V_104 ] == NULL ) {
F_31 ( L_3 ) ;
goto V_118;
}
F_34 ( V_19 . V_53 [ V_104 ] , V_119 , V_104 ) ;
V_19 . V_54 [ V_104 ] = F_33 ( V_112 , V_117 ) ;
if ( V_19 . V_54 [ V_104 ] == NULL ) {
F_31 ( L_3 ) ;
goto V_118;
}
F_34 ( V_19 . V_54 [ V_104 ] , V_120 , V_104 ) ;
V_19 . V_55 [ V_104 ] = F_30 ( V_114 , V_117 ) ;
if ( V_19 . V_55 [ V_104 ] == NULL ) {
F_31 ( L_4 ) ;
goto V_118;
}
F_27 ( V_19 . V_55 [ V_104 ] , V_104 ) ;
V_19 . V_50 [ V_104 ] =
( void * ) F_35 ( V_117 ) ;
if ( V_19 . V_50 [ V_104 ] == NULL ) {
F_31 ( L_5 ) ;
goto V_118;
}
V_19 . V_48 [ V_104 ] =
( void * ) F_35 ( V_117 ) ;
if ( V_19 . V_48 [ V_104 ] == NULL ) {
F_31 ( L_6 ) ;
goto V_118;
}
V_19 . V_51 [ V_104 ] =
( void * ) F_35 ( V_117 ) ;
if ( V_19 . V_51 [ V_104 ] == NULL ) {
F_31 ( L_7 ) ;
goto V_118;
}
}
return 0 ;
V_118:
return - V_121 ;
}
static void F_36 ( int V_104 )
{
F_37 ( V_19 . V_53 [ V_104 ] ) ;
F_37 ( V_19 . V_54 [ V_104 ] ) ;
F_37 ( V_19 . V_55 [ V_104 ] ) ;
if ( V_19 . V_48 [ V_104 ] )
F_38 ( ( unsigned long ) V_19 . V_48 [ V_104 ] ) ;
if ( V_19 . V_50 [ V_104 ] )
F_38 ( ( unsigned long ) V_19 . V_50 [ V_104 ] ) ;
if ( V_19 . V_51 [ V_104 ] )
F_38 ( ( unsigned long ) V_19 . V_51 [ V_104 ] ) ;
}
void F_39 ( void )
{
int V_104 ;
F_37 ( V_19 . V_115 ) ;
F_32 (cpu)
F_36 ( V_104 ) ;
}
void F_40 ( void * V_31 )
{
T_1 V_122 ;
union V_123 V_124 ;
union V_125 V_126 ;
union V_127 V_128 ;
union V_129 V_130 ;
T_1 V_52 ;
int V_104 = F_41 () ;
if ( ! V_19 . V_18 )
return;
F_8 ( V_131 , V_122 ) ;
F_8 ( V_132 , V_124 . V_60 ) ;
V_124 . V_133 = 1 ;
V_124 . V_134 = F_4 ( V_19 . V_50 [ V_104 ] )
>> V_135 ;
F_11 ( V_132 , V_124 . V_60 ) ;
F_8 ( V_136 , V_126 . V_60 ) ;
V_126 . V_137 = 1 ;
V_126 . V_138 = F_4 ( V_19 . V_48 [ V_104 ] )
>> V_135 ;
F_11 ( V_136 , V_126 . V_60 ) ;
F_8 ( V_139 + V_102 , V_128 . V_60 ) ;
V_128 . V_60 = 0 ;
V_128 . V_140 = V_141 ;
V_128 . V_142 = false ;
V_128 . V_143 = true ;
F_11 ( V_139 + V_102 , V_128 . V_60 ) ;
F_8 ( V_144 , V_130 . V_60 ) ;
V_130 . V_65 = 1 ;
F_11 ( V_144 , V_130 . V_60 ) ;
V_19 . V_145 = true ;
F_8 ( V_146 , V_52 ) ;
V_19 . V_52 [ V_104 ] = ( T_2 ) V_52 ;
F_42 ( & V_19 . V_147 [ V_104 ] ) ;
if ( V_67 . V_68 & V_148 )
F_43 ( V_19 . V_55 [ V_104 ] ,
V_149 ,
V_150 ,
V_151 ) ;
return;
}
void F_44 ( void )
{
int V_104 ;
if ( ! ( V_67 . V_68 & V_148 ) )
return;
F_32 (cpu)
F_45 ( V_19 . V_55 [ V_104 ] , V_104 ) ;
}
void F_46 ( void * V_31 )
{
union V_127 V_128 ;
union V_123 V_124 ;
union V_125 V_126 ;
union V_129 V_130 ;
int V_104 = F_41 () ;
if ( ! V_19 . V_145 )
return;
if ( V_67 . V_68 & V_148 )
F_25 ( V_19 . V_55 [ V_104 ] ) ;
F_8 ( V_139 + V_102 , V_128 . V_60 ) ;
V_128 . V_142 = 1 ;
F_11 ( V_139 + V_102 , V_128 . V_60 ) ;
F_8 ( V_132 , V_124 . V_60 ) ;
V_124 . V_133 = 0 ;
V_124 . V_134 = 0 ;
F_11 ( V_132 , V_124 . V_60 ) ;
F_8 ( V_136 , V_126 . V_60 ) ;
V_126 . V_137 = 0 ;
V_126 . V_138 = 0 ;
F_11 ( V_136 , V_126 . V_60 ) ;
F_8 ( V_144 , V_130 . V_60 ) ;
V_130 . V_65 = 0 ;
F_11 ( V_144 , V_130 . V_60 ) ;
}
