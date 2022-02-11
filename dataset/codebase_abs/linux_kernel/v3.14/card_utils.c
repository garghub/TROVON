int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_5 & V_6 )
return - V_7 ;
if ( V_2 -> V_8 == NULL )
return - V_7 ;
F_2 ( ( V_9 T_1 ) F_3 ( V_4 ) , V_2 -> V_8 + V_3 ) ;
return 0 ;
}
T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_5 & V_6 )
return 0xffffffffffffffffull ;
if ( ( V_2 -> V_5 & V_10 ) &&
( V_3 == V_11 ) )
return 0x000000000000ffffull ;
if ( ( V_2 -> V_5 & V_12 ) &&
( V_3 == V_11 ) )
return 0x00000000ffff0000ull ;
if ( V_2 -> V_8 == NULL )
return 0xffffffffffffffffull ;
return F_5 ( ( V_9 V_13 ) F_6 ( V_2 -> V_8 + V_3 ) ) ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
if ( V_2 -> V_5 & V_6 )
return - V_7 ;
if ( V_2 -> V_8 == NULL )
return - V_7 ;
F_8 ( ( V_9 T_2 ) F_9 ( V_4 ) , V_2 -> V_8 + V_3 ) ;
return 0 ;
}
T_2 F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_5 & V_6 )
return 0xffffffff ;
if ( V_2 -> V_8 == NULL )
return 0xffffffff ;
return F_11 ( ( V_9 V_14 ) F_12 ( V_2 -> V_8 + V_3 ) ) ;
}
int F_13 ( struct V_1 * V_2 , char * V_15 , int V_16 )
{
int V_17 , V_18 ;
T_2 V_19 = ( T_2 ) V_2 -> V_20 ;
memset ( V_15 , 0 , V_16 ) ;
for ( V_17 = 0 , V_18 = 0 ; V_18 < F_14 ( V_16 , 4 ) ; V_18 ++ ) {
char V_21 = ( char ) ( ( V_19 >> ( 24 - V_18 * 8 ) ) & 0xff ) ;
if ( V_21 == ' ' )
continue;
V_15 [ V_17 ++ ] = isprint ( V_21 ) ? V_21 : 'X' ;
}
return V_17 ;
}
void F_15 ( void )
{
int V_17 , V_18 ;
T_2 V_22 ;
for ( V_17 = 0 ; V_17 < 256 ; V_17 ++ ) {
V_22 = V_17 << 24 ;
for ( V_18 = 0 ; V_18 < 8 ; V_18 ++ ) {
if ( V_22 & 0x80000000 )
V_22 = ( V_22 << 1 ) ^ V_23 ;
else
V_22 = ( V_22 << 1 ) ;
}
V_24 [ V_17 ] = V_22 ;
}
}
T_2 F_16 ( T_3 * V_25 , T_4 V_16 , T_2 V_26 )
{
int V_17 ;
T_2 V_22 ;
V_22 = V_26 ;
while ( V_16 -- ) {
V_17 = ( ( V_22 >> 24 ) ^ * V_25 ++ ) & 0xFF ;
V_22 = ( V_22 << 8 ) ^ V_24 [ V_17 ] ;
}
return V_22 ;
}
void * F_17 ( struct V_1 * V_2 , T_4 V_27 ,
T_5 * V_28 )
{
if ( F_18 ( V_27 ) > V_29 )
return NULL ;
return F_19 ( V_2 -> V_30 , V_27 , V_28 ) ;
}
void F_20 ( struct V_1 * V_2 , T_4 V_27 ,
void * V_31 , T_5 V_28 )
{
if ( V_31 == NULL )
return;
F_21 ( V_2 -> V_30 , V_27 , V_31 , V_28 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_5 * V_32 ,
int V_33 )
{
int V_17 ;
struct V_30 * V_30 = V_2 -> V_30 ;
for ( V_17 = 0 ; ( V_17 < V_33 ) && ( V_32 [ V_17 ] != 0x0 ) ; V_17 ++ ) {
F_23 ( V_30 , V_32 [ V_17 ] ,
V_34 , V_35 ) ;
V_32 [ V_17 ] = 0x0 ;
}
}
static int F_24 ( struct V_1 * V_2 ,
struct V_36 * * V_37 , int V_33 ,
T_5 * V_32 )
{
int V_17 ;
struct V_30 * V_30 = V_2 -> V_30 ;
for ( V_17 = 0 ; V_17 < V_33 ; V_17 ++ ) {
T_5 V_38 ;
V_32 [ V_17 ] = 0x0 ;
V_38 = F_25 ( V_30 , V_37 [ V_17 ] ,
0 ,
V_34 ,
V_35 ) ;
if ( F_26 ( V_30 , V_38 ) ) {
F_27 ( & V_30 -> V_39 ,
L_1 ,
V_40 , ( long long ) V_38 ) ;
goto V_41;
}
V_32 [ V_17 ] = V_38 ;
}
return 0 ;
V_41:
F_22 ( V_2 , V_32 , V_33 ) ;
return - V_7 ;
}
static int F_28 ( int V_33 )
{
int V_16 , V_42 = V_33 / 7 ;
V_16 = sizeof( struct V_43 ) * ( V_33 + V_42 + 1 ) ;
return F_29 ( V_16 , V_34 ) ;
}
struct V_43 * F_30 ( struct V_1 * V_2 , int V_33 ,
T_5 * V_44 , T_4 * V_45 )
{
struct V_30 * V_30 = V_2 -> V_30 ;
struct V_43 * V_46 ;
* V_45 = F_28 ( V_33 ) ;
if ( F_18 ( * V_45 ) > V_29 ) {
F_27 ( & V_30 -> V_39 ,
L_2 , V_40 ) ;
return NULL ;
}
V_46 = F_17 ( V_2 , * V_45 , V_44 ) ;
if ( V_46 == NULL ) {
F_27 ( & V_30 -> V_39 ,
L_3 , V_40 ) ;
return NULL ;
}
return V_46 ;
}
int F_31 ( struct V_1 * V_2 ,
unsigned long V_47 ,
unsigned long V_27 ,
struct V_43 * V_46 ,
T_5 V_44 , T_4 V_45 ,
T_5 * V_32 , int V_48 , int V_33 )
{
int V_17 = 0 , V_18 = 0 , V_49 ;
unsigned long V_50 , V_51 ;
struct V_30 * V_30 = V_2 -> V_30 ;
T_5 V_52 = 0 ;
struct V_43 * V_53 , * V_54 = NULL ;
if ( V_47 > V_34 ) {
F_27 ( & V_30 -> V_39 ,
L_4 , V_40 , V_47 ) ;
return - V_55 ;
}
if ( V_45 < F_28 ( V_33 ) ) {
F_27 ( & V_30 -> V_39 ,
L_5 ,
V_40 , V_45 , V_33 ) ;
return - V_55 ;
}
V_50 = 128 ;
V_51 = V_47 ;
V_53 = & V_46 [ 0 ] ;
V_49 = 0 ;
while ( V_49 < V_33 ) {
T_5 V_38 ;
unsigned int V_56 ;
V_18 = 0 ;
V_53 [ V_18 ] . V_57 = F_3 ( V_44 + V_50 ) ;
V_53 [ V_18 ] . V_16 = F_9 ( 128 ) ;
V_53 [ V_18 ] . V_58 = F_9 ( V_59 ) ;
V_18 ++ ;
while ( V_18 < 8 ) {
V_56 = F_14 ( V_27 , V_34 - V_51 ) ;
V_38 = V_32 [ V_48 + V_49 ] + V_51 ;
V_27 -= V_56 ;
V_51 = 0 ;
if ( V_52 == V_38 ) {
T_2 V_60 = F_11 ( V_54 -> V_16 ) ;
V_54 -> V_16 = F_9 ( V_60 +
V_56 ) ;
V_49 ++ ;
if ( V_49 == V_33 )
goto V_61;
V_52 = V_38 + V_56 ;
continue;
}
V_53 [ V_18 ] . V_57 = F_3 ( V_38 ) ;
V_53 [ V_18 ] . V_16 = F_9 ( V_56 ) ;
V_53 [ V_18 ] . V_58 = F_9 ( V_62 ) ;
V_52 = V_38 + V_56 ;
V_54 = & V_53 [ V_18 ] ;
V_18 ++ ;
V_49 ++ ;
if ( V_49 == V_33 )
goto V_61;
}
V_50 += 128 ;
V_53 += 8 ;
}
V_61:
if ( V_18 == 1 ) {
V_53 -= 8 ;
V_18 = 7 ;
}
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
V_53 [ V_17 ] = V_53 [ V_17 + 1 ] ;
V_53 [ V_17 ] . V_57 = F_3 ( 0 ) ;
V_53 [ V_17 ] . V_16 = F_9 ( 0 ) ;
V_53 [ V_17 ] . V_58 = F_9 ( V_63 ) ;
return 0 ;
}
void F_32 ( struct V_1 * V_2 , struct V_43 * V_64 ,
T_5 V_44 , T_4 V_27 )
{
F_20 ( V_2 , V_27 , V_64 , V_44 ) ;
}
static int F_33 ( struct V_36 * * V_37 , unsigned int V_65 ,
int V_66 )
{
unsigned int V_17 ;
for ( V_17 = 0 ; V_17 < V_65 ; V_17 ++ ) {
if ( V_37 [ V_17 ] != NULL ) {
if ( V_66 )
F_34 ( V_37 [ V_17 ] ) ;
F_35 ( V_37 [ V_17 ] ) ;
}
}
return 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_67 * V_68 , void * V_69 ,
unsigned long V_27 , struct V_70 * V_71 )
{
int V_72 = - V_73 ;
unsigned long V_74 , V_47 ;
struct V_30 * V_30 = V_2 -> V_30 ;
if ( ( V_69 == NULL ) || ( V_27 == 0 ) ) {
V_68 -> V_27 = 0 ;
return - V_73 ;
}
V_68 -> V_75 = V_69 ;
V_68 -> V_27 = V_27 ;
V_74 = ( unsigned long ) V_69 ;
V_47 = F_37 ( V_74 ) ;
V_68 -> V_65 = F_38 ( V_47 + V_27 , V_34 ) ;
V_68 -> V_37 = F_39 ( V_68 -> V_65 ,
sizeof( struct V_36 * ) + sizeof( T_5 ) ,
V_76 ) ;
if ( ! V_68 -> V_37 ) {
F_27 ( & V_30 -> V_39 , L_6 ) ;
V_68 -> V_65 = 0 ;
V_68 -> V_75 = NULL ;
V_68 -> V_27 = 0 ;
return - V_77 ;
}
V_68 -> V_32 = ( T_5 * ) ( V_68 -> V_37 + V_68 -> V_65 ) ;
V_72 = F_40 ( V_74 & V_78 ,
V_68 -> V_65 ,
1 ,
V_68 -> V_37 ) ;
if ( V_72 < V_68 -> V_65 ) {
F_33 ( V_68 -> V_37 , V_72 , 0 ) ;
V_72 = - V_55 ;
goto V_79;
}
V_72 = F_24 ( V_2 , V_68 -> V_37 , V_68 -> V_65 , V_68 -> V_32 ) ;
if ( V_72 != 0 )
goto V_80;
return 0 ;
V_80:
F_33 ( V_68 -> V_37 , V_68 -> V_65 , 0 ) ;
V_79:
F_41 ( V_68 -> V_37 ) ;
V_68 -> V_37 = NULL ;
V_68 -> V_32 = NULL ;
V_68 -> V_65 = 0 ;
V_68 -> V_75 = NULL ;
V_68 -> V_27 = 0 ;
return V_72 ;
}
int F_42 ( struct V_1 * V_2 , struct V_67 * V_68 ,
struct V_70 * V_71 )
{
struct V_30 * V_30 = V_2 -> V_30 ;
if ( ! F_43 ( V_68 ) ) {
F_27 ( & V_30 -> V_39 , L_7 ,
V_40 , V_68 ) ;
return - V_73 ;
}
if ( V_68 -> V_32 )
F_22 ( V_2 , V_68 -> V_32 , V_68 -> V_65 ) ;
if ( V_68 -> V_37 ) {
F_33 ( V_68 -> V_37 , V_68 -> V_65 , 1 ) ;
F_41 ( V_68 -> V_37 ) ;
V_68 -> V_37 = NULL ;
V_68 -> V_32 = NULL ;
V_68 -> V_65 = 0 ;
}
V_68 -> V_75 = NULL ;
V_68 -> V_27 = 0 ;
return 0 ;
}
T_3 F_44 ( struct V_1 * V_2 )
{
T_1 V_81 = V_2 -> V_82 ;
return ( T_3 ) ( ( V_81 & V_83 ) >> 20 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
T_1 V_84 ;
struct V_30 * V_30 = V_2 -> V_30 ;
if ( ! F_46 ( V_2 ) )
return - V_85 ;
F_1 ( V_2 , V_86 , 0x1ull ) ;
F_47 ( 1000 ) ;
F_4 ( V_2 , V_87 ) ;
F_4 ( V_2 , V_88 ) ;
F_4 ( V_2 , V_89 ) ;
V_84 = F_4 ( V_2 , V_86 ) & 0x3cull ;
F_1 ( V_2 , V_86 , V_84 | 0x2ull ) ;
F_47 ( 50 ) ;
if ( F_48 ( V_2 ) ) {
F_49 ( & V_30 -> V_39 ,
L_8 , V_40 ) ;
F_1 ( V_2 , V_90 , 0x0aull ) ;
}
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
T_1 V_91 ;
if ( ! F_46 ( V_2 ) )
return - V_85 ;
V_91 = F_4 ( V_2 , V_92 ) & 0x1 ;
V_2 -> V_93 = ( V_91 == 0 ) ? 0x8ull : 0xcull ;
return 0 ;
}
int F_51 ( struct V_1 * V_2 , int V_94 )
{
int V_72 ;
struct V_30 * V_30 = V_2 -> V_30 ;
V_72 = F_52 ( V_30 , V_94 ) ;
if ( V_72 == 0 )
V_2 -> V_58 |= V_95 ;
return V_72 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_30 * V_30 = V_2 -> V_30 ;
if ( V_2 -> V_58 & V_95 ) {
F_54 ( V_30 ) ;
V_2 -> V_58 &= ~ V_95 ;
}
}
static int F_55 ( struct V_1 * V_2 , struct V_96 * V_97 ,
unsigned int * V_17 , unsigned int V_68 , T_2 V_98 , T_2 V_99 ,
T_1 V_4 )
{
if ( F_56 ( * V_17 >= V_68 ) )
return - V_55 ;
V_97 [ * V_17 ] . V_98 = V_98 ;
V_97 [ * V_17 ] . V_99 = V_99 ;
V_97 [ * V_17 ] . V_4 = V_4 ;
++ * V_17 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , struct V_96 * V_97 ,
unsigned int * V_17 , unsigned int V_68 , T_2 V_98 , T_1 V_4 )
{
return F_55 ( V_2 , V_97 , V_17 , V_68 , V_98 , 0 , V_4 ) ;
}
int F_58 ( struct V_1 * V_2 , struct V_96 * V_100 ,
unsigned int V_101 , int V_102 )
{
unsigned int V_17 , V_18 , V_99 = 0 ;
T_2 V_103 , V_104 , V_105 , V_106 ;
T_1 V_107 , V_108 , V_109 , V_110 , V_111 , V_112 , V_113 ;
V_107 = F_4 ( V_2 , V_11 ) ;
F_57 ( V_2 , V_100 , & V_99 , V_101 , V_11 , V_107 ) ;
V_108 = F_4 ( V_2 , V_114 ) ;
F_57 ( V_2 , V_100 , & V_99 , V_101 , V_114 , V_108 ) ;
V_109 = F_4 ( V_2 , V_115 ) ;
F_57 ( V_2 , V_100 , & V_99 , V_101 , V_115 , V_109 ) ;
for ( V_17 = 0 ; V_17 < V_116 ; V_17 ++ ) {
V_103 = ( V_17 << 24 ) | 0x008 ;
V_110 = F_4 ( V_2 , V_103 ) ;
F_57 ( V_2 , V_100 , & V_99 , V_101 , V_103 , V_110 ) ;
V_104 = ( V_17 << 24 ) | 0x018 ;
V_111 = F_4 ( V_2 , V_104 ) ;
F_57 ( V_2 , V_100 , & V_99 , V_101 , V_104 , V_111 ) ;
for ( V_18 = 0 ; V_18 < 64 ; V_18 ++ ) {
if ( ! V_102 && ( ! ( V_110 & ( 1ull << V_18 ) ) ) )
continue;
V_105 = ( V_17 << 24 ) | ( 0x100 + 8 * V_18 ) ;
V_112 = F_4 ( V_2 , V_105 ) ;
F_57 ( V_2 , V_100 , & V_99 , V_101 , V_105 , V_112 ) ;
V_106 = ( V_17 << 24 ) | ( 0x300 + 8 * V_18 ) ;
V_113 = F_4 ( V_2 , V_106 ) ;
F_57 ( V_2 , V_100 , & V_99 , V_101 , V_106 , V_113 ) ;
}
}
for ( V_17 = V_99 ; V_17 < V_101 ; V_17 ++ ) {
V_100 [ V_17 ] . V_98 = 0xffffffff ;
V_100 [ V_17 ] . V_4 = 0xffffffffffffffffull ;
}
return V_99 ;
}
int F_59 ( struct V_1 * V_2 , int V_117 )
{
int V_118 = 0 , V_119 , V_120 , V_121 , V_122 ;
T_2 V_123 , V_124 , V_125 , V_126 ;
T_1 V_127 , V_4 , V_98 ;
V_123 = F_60 ( V_117 ) | V_128 ;
V_127 = F_4 ( V_2 , V_123 ) ;
if ( ( V_127 != 0x0 ) && ( V_127 != - 1ull ) ) {
V_124 = F_60 ( V_117 ) | V_127 ;
while ( 1 ) {
V_4 = F_4 ( V_2 , V_124 ) ;
if ( ( V_4 == 0x0 ) || ( V_4 == - 1ull ) )
break;
V_125 = ( V_4 & 0x0000007fff000000ull ) >> 24 ;
V_126 = ( V_4 & 0x0000008000000000ull ) >> 36 ;
if ( V_126 ) {
V_118 += V_125 ;
} else {
V_118 += V_125 >> 3 ;
}
V_124 += 8 ;
}
}
for ( V_119 = 0 ; V_119 < 8 ; V_119 ++ ) {
V_98 = F_60 ( V_117 ) | F_61 ( V_119 ) ;
V_4 = F_4 ( V_2 , V_98 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_120 = ( V_4 >> 24 ) & 0xff ;
V_121 = ( V_4 >> 16 ) & 0xff ;
V_122 = V_4 & 0xffff ;
V_118 += V_120 + ( V_121 * V_122 ) ;
}
return V_118 ;
}
int F_62 ( struct V_1 * V_2 , int V_117 ,
struct V_96 * V_100 , unsigned int V_101 )
{
int V_17 , V_120 , V_121 , V_129 , V_122 , V_130 , V_119 ;
unsigned int V_99 = 0 ;
T_2 V_123 , V_124 , V_131 , V_125 , V_126 ;
T_1 V_127 , V_132 , V_4 , V_98 ;
V_123 = F_60 ( V_117 ) | V_128 ;
V_127 = F_4 ( V_2 , V_123 ) ;
if ( ( V_127 != 0x0 ) && ( V_127 != 0xffffffffffffffffull ) ) {
V_124 = F_60 ( V_117 ) | V_127 ;
while ( 1 ) {
V_132 = F_4 ( V_2 , V_124 ) ;
if ( ( V_132 == 0x0 ) || ( V_132 == 0xffffffffffffffffull ) )
break;
V_131 = ( V_132 & 0x0000000000ffffffull ) ;
V_125 = ( V_132 & 0x0000007fff000000ull ) >> 24 ;
V_126 = ( V_132 & 0x0000008000000000ull ) >> 36 ;
V_131 |= F_60 ( V_117 ) ;
if ( V_126 ) {
for ( V_17 = 0 ; V_17 < ( int ) V_125 ; V_17 ++ ) {
V_4 = F_4 ( V_2 , V_131 ) ;
F_55 ( V_2 , V_100 , & V_99 , V_101 ,
V_131 , V_17 , V_4 ) ;
}
} else {
V_125 >>= 3 ;
for ( V_17 = 0 ; V_17 < ( int ) V_125 ; V_17 ++ , V_131 += 8 ) {
V_4 = F_4 ( V_2 , V_131 ) ;
F_55 ( V_2 , V_100 , & V_99 , V_101 ,
V_131 , 0 , V_4 ) ;
}
}
V_124 += 8 ;
}
}
for ( V_119 = 0 ; V_119 < 8 ; V_119 ++ ) {
V_98 = F_60 ( V_117 ) | F_61 ( V_119 ) ;
V_4 = F_4 ( V_2 , V_98 ) ;
if ( ( V_4 == 0x0ull ) || ( V_4 == - 1ull ) )
continue;
V_120 = ( V_4 >> 24 ) & 0xff ;
V_121 = ( V_4 >> 16 ) & 0xff ;
V_122 = V_4 & 0xffff ;
for ( V_129 = 0 ; V_129 <= V_121 ; V_129 ++ ) {
T_2 V_133 =
F_63 ( V_119 , V_129 ) ;
V_98 = ( F_60 ( V_117 ) |
V_134 ) ;
F_1 ( V_2 , V_98 , V_133 ) ;
for ( V_130 = 0 ;
V_130 < ( V_129 ? V_122 : V_120 ) ;
V_130 ++ ) {
V_98 = ( F_60 ( V_117 ) |
V_135 ) ;
V_4 = F_4 ( V_2 , V_98 ) ;
F_55 ( V_2 , V_100 , & V_99 , V_101 , V_98 ,
( V_133 << 16 ) | V_130 , V_4 ) ;
}
}
}
return 0 ;
}
int F_64 ( struct V_1 * V_2 , T_2 V_136 , T_1 V_4 , int V_137 )
{
F_1 ( V_2 , V_138 , V_137 & 0xf ) ;
F_1 ( V_2 , V_136 , V_4 ) ;
return 0 ;
}
T_1 F_65 ( struct V_1 * V_2 , T_2 V_136 , int V_137 )
{
F_1 ( V_2 , V_138 , V_137 & 0xf ) ;
return F_4 ( V_2 , V_136 ) ;
}
int F_66 ( struct V_1 * V_2 )
{
T_6 V_139 ;
static const int V_140 [] = { 250 , 200 , 166 , 175 } ;
V_139 = ( T_6 ) ( ( V_2 -> V_82 >> 28 ) & 0x0full ) ;
if ( V_139 >= F_67 ( V_140 ) )
return 0 ;
return V_140 [ V_139 ] ;
}
void F_68 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_141 , 0xcull ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_142 , 0xcull ) ;
if ( F_48 ( V_2 ) )
F_1 ( V_2 , V_90 , 0x0aull ) ;
}
