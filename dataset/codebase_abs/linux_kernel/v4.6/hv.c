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
void F_16 ( void )
{
union V_45 V_46 ;
F_11 ( V_58 , 0 ) ;
if ( V_19 . V_18 ) {
V_46 . V_60 = 0 ;
F_11 ( V_59 , V_46 . V_60 ) ;
F_15 ( V_19 . V_18 ) ;
V_19 . V_18 = NULL ;
}
#ifdef F_5
if ( V_67 . V_68 & V_69 ) {
if ( ! V_77 ) {
F_17 ( & V_74 , 10 ) ;
F_18 ( & V_74 ) ;
}
V_46 . V_60 = 0 ;
F_11 ( V_73 , V_46 . V_60 ) ;
F_15 ( V_19 . V_35 ) ;
V_19 . V_35 = NULL ;
}
#endif
}
int F_19 ( union V_78 V_79 ,
enum V_80 V_81 ,
void * V_82 , T_5 V_83 )
{
struct V_84 * V_85 ;
T_1 V_86 ;
if ( V_83 > V_87 )
return - V_88 ;
V_85 = (struct V_84 * )
V_19 . V_51 [ F_20 () ] ;
V_85 -> V_89 = V_79 ;
V_85 -> V_90 = 0 ;
V_85 -> V_81 = V_81 ;
V_85 -> V_83 = V_83 ;
memcpy ( ( void * ) V_85 -> V_82 , V_82 , V_83 ) ;
V_86 = F_3 ( V_91 , V_85 , NULL ) ;
F_21 () ;
return V_86 & 0xFFFF ;
}
static int F_22 ( unsigned long V_92 ,
struct V_93 * V_94 )
{
T_3 V_32 ;
F_23 ( ! F_24 ( V_94 ) ) ;
F_8 ( V_44 , V_32 ) ;
V_32 += V_92 ;
F_11 ( V_95 , V_32 ) ;
return 0 ;
}
static int F_25 ( struct V_93 * V_94 )
{
F_11 ( V_95 , 0 ) ;
F_11 ( V_96 , 0 ) ;
return 0 ;
}
static int F_26 ( struct V_93 * V_94 )
{
union V_97 V_98 ;
V_98 . V_65 = 1 ;
V_98 . V_99 = 1 ;
V_98 . V_100 = V_101 ;
F_11 ( V_96 , V_98 . V_60 ) ;
return 0 ;
}
static void F_27 ( struct V_93 * V_102 , int V_103 )
{
V_102 -> V_104 = L_1 ;
V_102 -> V_68 = V_105 ;
V_102 -> V_106 = F_28 ( V_103 ) ;
V_102 -> V_107 = 1000 ;
V_102 -> V_108 = F_25 ;
V_102 -> V_109 = F_26 ;
V_102 -> V_110 = F_22 ;
}
int F_29 ( void )
{
T_5 V_111 = sizeof( struct V_112 ) ;
T_5 V_113 = sizeof( struct V_93 ) ;
int V_103 ;
V_19 . V_114 = F_30 ( sizeof( struct V_106 ) * V_115 ,
V_116 ) ;
if ( V_19 . V_114 == NULL ) {
F_31 ( L_2 ) ;
goto V_117;
}
F_32 (cpu) {
V_19 . V_53 [ V_103 ] = F_33 ( V_111 , V_116 ) ;
if ( V_19 . V_53 [ V_103 ] == NULL ) {
F_31 ( L_3 ) ;
goto V_117;
}
F_34 ( V_19 . V_53 [ V_103 ] , V_118 , V_103 ) ;
V_19 . V_54 [ V_103 ] = F_33 ( V_111 , V_116 ) ;
if ( V_19 . V_54 [ V_103 ] == NULL ) {
F_31 ( L_3 ) ;
goto V_117;
}
F_34 ( V_19 . V_54 [ V_103 ] , V_119 , V_103 ) ;
V_19 . V_55 [ V_103 ] = F_30 ( V_113 , V_116 ) ;
if ( V_19 . V_55 [ V_103 ] == NULL ) {
F_31 ( L_4 ) ;
goto V_117;
}
F_27 ( V_19 . V_55 [ V_103 ] , V_103 ) ;
V_19 . V_50 [ V_103 ] =
( void * ) F_35 ( V_116 ) ;
if ( V_19 . V_50 [ V_103 ] == NULL ) {
F_31 ( L_5 ) ;
goto V_117;
}
V_19 . V_48 [ V_103 ] =
( void * ) F_35 ( V_116 ) ;
if ( V_19 . V_48 [ V_103 ] == NULL ) {
F_31 ( L_6 ) ;
goto V_117;
}
V_19 . V_51 [ V_103 ] =
( void * ) F_35 ( V_116 ) ;
if ( V_19 . V_51 [ V_103 ] == NULL ) {
F_31 ( L_7 ) ;
goto V_117;
}
}
return 0 ;
V_117:
return - V_120 ;
}
static void F_36 ( int V_103 )
{
F_37 ( V_19 . V_53 [ V_103 ] ) ;
F_37 ( V_19 . V_54 [ V_103 ] ) ;
F_37 ( V_19 . V_55 [ V_103 ] ) ;
if ( V_19 . V_48 [ V_103 ] )
F_38 ( ( unsigned long ) V_19 . V_48 [ V_103 ] ) ;
if ( V_19 . V_50 [ V_103 ] )
F_38 ( ( unsigned long ) V_19 . V_50 [ V_103 ] ) ;
if ( V_19 . V_51 [ V_103 ] )
F_38 ( ( unsigned long ) V_19 . V_51 [ V_103 ] ) ;
}
void F_39 ( void )
{
int V_103 ;
F_37 ( V_19 . V_114 ) ;
F_32 (cpu)
F_36 ( V_103 ) ;
}
void F_40 ( void * V_31 )
{
T_1 V_121 ;
union V_122 V_123 ;
union V_124 V_125 ;
union V_126 V_127 ;
union V_128 V_129 ;
T_1 V_52 ;
int V_103 = F_41 () ;
if ( ! V_19 . V_18 )
return;
F_8 ( V_130 , V_121 ) ;
F_8 ( V_131 , V_123 . V_60 ) ;
V_123 . V_132 = 1 ;
V_123 . V_133 = F_4 ( V_19 . V_50 [ V_103 ] )
>> V_134 ;
F_11 ( V_131 , V_123 . V_60 ) ;
F_8 ( V_135 , V_125 . V_60 ) ;
V_125 . V_136 = 1 ;
V_125 . V_137 = F_4 ( V_19 . V_48 [ V_103 ] )
>> V_134 ;
F_11 ( V_135 , V_125 . V_60 ) ;
F_8 ( V_138 + V_101 , V_127 . V_60 ) ;
V_127 . V_60 = 0 ;
V_127 . V_139 = V_140 ;
V_127 . V_141 = false ;
V_127 . V_142 = true ;
F_11 ( V_138 + V_101 , V_127 . V_60 ) ;
F_8 ( V_143 , V_129 . V_60 ) ;
V_129 . V_65 = 1 ;
F_11 ( V_143 , V_129 . V_60 ) ;
V_19 . V_144 = true ;
F_8 ( V_145 , V_52 ) ;
V_19 . V_52 [ V_103 ] = ( T_2 ) V_52 ;
F_42 ( & V_19 . V_146 [ V_103 ] ) ;
if ( V_67 . V_68 & V_147 )
F_43 ( V_19 . V_55 [ V_103 ] ,
V_148 ,
V_149 ,
V_150 ) ;
return;
}
void F_44 ( void )
{
int V_103 ;
if ( ! ( V_67 . V_68 & V_147 ) )
return;
F_32 (cpu)
F_45 ( V_19 . V_55 [ V_103 ] , V_103 ) ;
}
void F_46 ( void * V_31 )
{
union V_126 V_127 ;
union V_122 V_123 ;
union V_124 V_125 ;
union V_128 V_129 ;
int V_103 = F_41 () ;
if ( ! V_19 . V_144 )
return;
if ( V_67 . V_68 & V_147 )
F_25 ( V_19 . V_55 [ V_103 ] ) ;
F_8 ( V_138 + V_101 , V_127 . V_60 ) ;
V_127 . V_141 = 1 ;
F_11 ( V_138 + V_101 , V_127 . V_60 ) ;
F_8 ( V_131 , V_123 . V_60 ) ;
V_123 . V_132 = 0 ;
V_123 . V_133 = 0 ;
F_11 ( V_131 , V_123 . V_60 ) ;
F_8 ( V_135 , V_125 . V_60 ) ;
V_125 . V_136 = 0 ;
V_125 . V_137 = 0 ;
F_11 ( V_135 , V_125 . V_60 ) ;
F_8 ( V_143 , V_129 . V_60 ) ;
V_129 . V_65 = 0 ;
F_11 ( V_143 , V_129 . V_60 ) ;
}
