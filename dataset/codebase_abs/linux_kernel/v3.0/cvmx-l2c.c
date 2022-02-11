int F_1 ( T_1 V_1 )
{
T_1 V_2 ;
if ( V_1 >= F_2 () )
return - 1 ;
if ( F_3 ( V_3 ) )
return F_4 ( F_5 ( V_1 ) ) & 0xffff ;
V_2 = ( V_1 & 0x3 ) * 8 ;
switch ( V_1 & 0xC ) {
case 0x0 :
return ( F_4 ( V_4 ) & ( 0xFF << V_2 ) ) >> V_2 ;
case 0x4 :
return ( F_4 ( V_5 ) & ( 0xFF << V_2 ) ) >> V_2 ;
case 0x8 :
return ( F_4 ( V_6 ) & ( 0xFF << V_2 ) ) >> V_2 ;
case 0xC :
return ( F_4 ( V_7 ) & ( 0xFF << V_2 ) ) >> V_2 ;
}
return 0 ;
}
int F_6 ( T_1 V_1 , T_1 V_8 )
{
T_1 V_2 ;
T_1 V_9 ;
V_9 = ( 0x1 << F_7 () ) - 1 ;
V_8 &= V_9 ;
if ( V_8 == V_9 && ! F_3 ( V_3 ) )
return - 1 ;
if ( V_1 >= F_2 () )
return - 1 ;
if ( F_3 ( V_3 ) ) {
F_8 ( F_5 ( V_1 ) , V_8 ) ;
return 0 ;
}
V_2 = ( V_1 & 0x3 ) * 8 ;
switch ( V_1 & 0xC ) {
case 0x0 :
F_8 ( V_4 ,
( F_4 ( V_4 ) & ~ ( 0xFF << V_2 ) ) |
V_8 << V_2 ) ;
break;
case 0x4 :
F_8 ( V_5 ,
( F_4 ( V_5 ) & ~ ( 0xFF << V_2 ) ) |
V_8 << V_2 ) ;
break;
case 0x8 :
F_8 ( V_6 ,
( F_4 ( V_6 ) & ~ ( 0xFF << V_2 ) ) |
V_8 << V_2 ) ;
break;
case 0xC :
F_8 ( V_7 ,
( F_4 ( V_7 ) & ~ ( 0xFF << V_2 ) ) |
V_8 << V_2 ) ;
break;
}
return 0 ;
}
int F_9 ( T_1 V_8 )
{
T_1 V_9 ;
V_9 = ( 0x1 << F_7 () ) - 1 ;
V_8 &= V_9 ;
if ( V_8 == V_9 && ! F_3 ( V_3 ) )
return - 1 ;
if ( F_3 ( V_3 ) )
F_8 ( F_10 ( 0 ) , V_8 ) ;
else
F_8 ( V_10 ,
( F_4 ( V_10 ) & ~ 0xFF ) | V_8 ) ;
return 0 ;
}
int F_11 ( void )
{
if ( F_3 ( V_3 ) )
return F_4 ( F_10 ( 0 ) ) & 0xffff ;
else
return F_4 ( V_10 ) & ( 0xFF ) ;
}
void F_12 ( T_1 V_11 , enum V_12 V_13 ,
T_1 V_14 )
{
if ( F_3 ( V_15 ) || F_3 ( V_16 ) ) {
union V_17 V_18 ;
V_18 . V_19 = F_4 ( V_20 ) ;
switch ( V_11 ) {
case 0 :
V_18 . V_21 . V_22 = V_13 ;
V_18 . V_21 . V_23 = 1 ;
V_18 . V_21 . V_24 = V_14 ;
break;
case 1 :
V_18 . V_21 . V_25 = V_13 ;
V_18 . V_21 . V_26 = 1 ;
V_18 . V_21 . V_27 = V_14 ;
break;
case 2 :
V_18 . V_21 . V_28 = V_13 ;
V_18 . V_21 . V_29 = 1 ;
V_18 . V_21 . V_30 = V_14 ;
break;
case 3 :
default:
V_18 . V_21 . V_31 = V_13 ;
V_18 . V_21 . V_32 = 1 ;
V_18 . V_21 . V_33 = V_14 ;
break;
}
F_8 ( V_20 , V_18 . V_19 ) ;
} else {
union V_34 V_35 ;
int V_36 ;
F_13 ( L_1 ) ;
if ( V_14 )
F_13 ( L_2 ) ;
V_35 . V_19 = F_4 ( F_14 ( 0 ) ) ;
switch ( V_11 ) {
case 0 :
V_35 . V_21 . V_22 = V_13 ;
break;
case 1 :
V_35 . V_21 . V_25 = V_13 ;
break;
case 2 :
V_35 . V_21 . V_28 = V_13 ;
break;
default:
case 3 :
V_35 . V_21 . V_31 = V_13 ;
break;
}
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
F_8 ( F_14 ( V_36 ) ,
V_35 . V_19 ) ;
}
}
T_2 F_15 ( T_1 V_11 )
{
switch ( V_11 ) {
case 0 :
if ( F_3 ( V_15 ) || F_3 ( V_16 ) )
return F_4 ( V_38 ) ;
else {
T_2 V_11 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_11 += F_4 ( F_16 ( V_36 ) ) ;
return V_11 ;
}
case 1 :
if ( F_3 ( V_15 ) || F_3 ( V_16 ) )
return F_4 ( V_39 ) ;
else {
T_2 V_11 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_11 += F_4 ( F_17 ( V_36 ) ) ;
return V_11 ;
}
case 2 :
if ( F_3 ( V_15 ) || F_3 ( V_16 ) )
return F_4 ( V_40 ) ;
else {
T_2 V_11 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_11 += F_4 ( F_18 ( V_36 ) ) ;
return V_11 ;
}
case 3 :
default:
if ( F_3 ( V_15 ) || F_3 ( V_16 ) )
return F_4 ( V_41 ) ;
else {
T_2 V_11 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_37 ; V_36 ++ )
V_11 += F_4 ( F_19 ( V_36 ) ) ;
return V_11 ;
}
}
}
static void F_20 ( T_2 V_42 , int V_43 )
{
volatile char * V_44 ;
volatile char V_45 ;
V_43 += V_42 & V_46 ;
V_42 &= ~ V_46 ;
V_44 = ( volatile char * ) F_21 ( V_42 ) ;
V_47 ;
while ( V_43 > 0 ) {
V_45 += * V_44 ;
V_43 -= V_48 ;
V_44 += V_48 ;
}
}
int F_22 ( T_2 V_42 )
{
if ( F_3 ( V_3 ) ) {
int V_49 = V_50 ;
T_2 V_51 = F_7 () ;
T_2 V_52 = V_42 >> V_49 ;
T_2 V_53 = F_23 ( V_54 , F_24 ( V_42 ) << V_55 ) ;
T_2 V_56 ;
union V_57 V_58 ;
F_25 ( F_23 ( V_54 , V_42 ) , 0 ) ;
for ( V_56 = 0 ; V_56 < V_51 ; V_56 ++ ) {
F_26 ( V_53 | ( V_56 << V_49 ) , 0 ) ;
V_59 ;
V_58 . V_19 = F_4 ( F_27 ( 0 ) ) ;
if ( V_58 . V_21 . V_60 && V_58 . V_21 . V_52 == V_52 )
break;
}
if ( V_56 >= V_51 ) {
return - 1 ;
}
if ( ! V_58 . V_21 . V_61 ) {
return - 1 ;
}
return V_56 ;
} else {
int V_62 = 0 ;
union V_63 V_64 ;
union V_65 V_66 ;
union V_67 V_68 ;
union V_69 V_70 ;
F_28 ( & V_71 ) ;
V_64 . V_19 = 0 ;
V_66 . V_19 = 0 ;
V_68 . V_19 = 0 ;
V_70 . V_19 = F_4 ( V_72 ) ;
V_70 . V_21 . V_73 = 1 ;
V_70 . V_21 . V_74 = 1 ;
F_8 ( V_72 , V_70 . V_19 ) ;
V_42 &= ~ V_46 ;
V_64 . V_21 . V_75 = F_29 () ;
V_59 ;
F_8 ( V_76 , V_64 . V_19 ) ;
F_4 ( V_76 ) ;
V_68 . V_21 . V_77 = 0 ;
F_8 ( V_78 , V_68 . V_19 ) ;
F_4 ( V_78 ) ;
if ( ( (union V_79 ) ( F_4 ( V_80 ) ) ) . V_21 . V_81 ) {
int V_82 = V_55 + 2 * V_83 - 1 ;
T_2 V_84 = V_42 ^ ( V_42 & ( ( 1 << V_82 ) - 1 ) ) >> V_83 ;
V_66 . V_21 . V_85 = V_84 >> 7 ;
} else {
V_66 . V_21 . V_85 = V_42 >> 7 ;
}
V_66 . V_21 . V_86 = 1 ;
F_8 ( V_87 , V_66 . V_19 ) ;
F_4 ( V_87 ) ;
F_20 ( V_42 , V_48 ) ;
V_66 . V_21 . V_86 = 0 ;
F_8 ( V_87 , V_66 . V_19 ) ;
F_4 ( V_87 ) ;
F_8 ( V_76 , 0 ) ;
F_4 ( V_76 ) ;
V_70 . V_19 = F_4 ( V_72 ) ;
if ( V_70 . V_21 . V_73 || V_70 . V_21 . V_74 )
V_62 = 1 ;
F_30 ( & V_71 ) ;
return V_62 ;
}
}
int F_31 ( T_2 V_88 , T_2 V_43 )
{
int V_62 = 0 ;
V_43 += V_88 & V_46 ;
V_88 &= ~ V_46 ;
V_43 = ( V_43 + V_46 ) & ~ V_46 ;
while ( V_43 ) {
V_62 += F_22 ( V_88 ) ;
V_88 += V_48 ;
V_43 -= V_48 ;
}
return V_62 ;
}
void F_32 ( void )
{
T_2 V_51 , V_89 ;
T_2 V_90 , V_91 ;
V_91 = F_33 () ;
V_90 = F_7 () ;
if ( F_3 ( V_92 ) ) {
T_2 V_93 ;
int V_94 = V_50 ;
int V_95 = V_55 ;
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ ) {
for ( V_51 = 0 ; V_51 < V_90 ; V_51 ++ ) {
V_93 = F_23 ( V_54 ,
( V_51 << V_94 ) | ( V_89 << V_95 ) ) ;
F_34 ( V_93 , 0 ) ;
}
}
} else {
for ( V_89 = 0 ; V_89 < V_91 ; V_89 ++ )
for ( V_51 = 0 ; V_51 < V_90 ; V_51 ++ )
F_35 ( V_51 , V_89 ) ;
}
}
int F_36 ( T_2 V_93 )
{
if ( F_3 ( V_3 ) ) {
int V_51 ;
union V_96 V_52 ;
T_1 V_97 ;
T_1 V_53 = F_24 ( V_93 ) ;
V_97 = ( ( V_93 >> V_50 ) & ( ( 1 << V_50 ) - 1 ) ) ;
for ( V_51 = 0 ; V_51 < V_98 ; V_51 ++ ) {
V_52 = F_37 ( V_51 , V_53 ) ;
if ( V_52 . V_21 . V_99 && ( V_52 . V_21 . V_42 == V_97 ) ) {
F_38 ( F_23 ( V_54 , V_93 ) , 0 ) ;
return V_52 . V_21 . V_100 ;
}
}
} else {
int V_51 ;
union V_96 V_52 ;
T_1 V_97 ;
T_1 V_53 = F_24 ( V_93 ) ;
V_97 = ( ( V_93 >> V_50 ) & ( ( 1 << V_50 ) - 1 ) ) ;
for ( V_51 = 0 ; V_51 < V_98 ; V_51 ++ ) {
V_52 = F_37 ( V_51 , V_53 ) ;
if ( V_52 . V_21 . V_99 && ( V_52 . V_21 . V_42 == V_97 ) ) {
F_35 ( V_51 , V_53 ) ;
return V_52 . V_21 . V_100 ;
}
}
}
return 0 ;
}
int F_39 ( T_2 V_88 , T_2 V_43 )
{
int V_101 = 0 ;
V_43 += V_88 & V_46 ;
V_88 &= ~ V_46 ;
V_43 = ( V_43 + V_46 ) & ~ V_46 ;
while ( V_43 > 0 ) {
V_101 += F_36 ( V_88 ) ;
V_88 += V_48 ;
V_43 -= V_48 ;
}
return V_101 ;
}
static union V_102 F_40 ( T_2 V_51 , T_2 V_53 )
{
T_2 V_103 = F_23 ( V_54 , ( V_53 << 7 ) + 96 ) ;
T_2 V_1 = F_29 () ;
union V_102 V_104 ;
T_2 V_105 = V_76 ;
unsigned long V_106 ;
union V_63 V_107 ;
V_107 . V_19 = 0 ;
V_107 . V_21 . V_75 = V_1 ;
V_107 . V_21 . V_108 = 1 ;
V_107 . V_21 . V_89 = V_51 ;
F_41 ( V_106 ) ;
V_59 ;
V_47 ;
asm volatile (
".set push\n\t"
".set mips64\n\t"
".set noreorder\n\t"
"sd %[dbg_val], 0(%[dbg_addr])\n\t"
"ld $0, 0(%[dbg_addr])\n\t"
"ld %[tag_val], 0(%[tag_addr])\n\t"
"sd $0, 0(%[dbg_addr])\n\t"
"ld $0, 0(%[dbg_addr])\n\t"
"cache 9, 0($0)\n\t"
".set pop"
: [tag_val] "=r" (tag_val)
: [dbg_addr] "r" (dbg_addr), [dbg_val] "r" (debug_val), [tag_addr] "r" (debug_tag_addr)
: "memory");
F_42 ( V_106 ) ;
return V_104 ;
}
union V_96 F_37 ( T_1 V_109 , T_1 V_53 )
{
union V_96 V_52 ;
V_52 . V_19 = 0 ;
if ( ( int ) V_109 >= F_7 () ) {
F_13 ( L_3 ) ;
return V_52 ;
}
if ( ( int ) V_53 >= F_33 () ) {
F_13 ( L_4 ,
( int ) V_53 , F_33 () ) ;
return V_52 ;
}
if ( F_3 ( V_3 ) ) {
union V_57 V_58 ;
T_2 V_93 = F_23 ( V_54 ,
( V_109 << V_50 ) |
( V_53 << V_55 ) ) ;
F_26 ( V_93 , 0 ) ;
V_59 ;
V_58 . V_19 = F_4 ( F_27 ( 0 ) ) ;
V_52 . V_21 . V_99 = V_58 . V_21 . V_60 ;
V_52 . V_21 . V_110 = V_58 . V_21 . V_111 ;
V_52 . V_21 . V_100 = V_58 . V_21 . V_61 ;
V_52 . V_21 . V_112 = V_58 . V_21 . V_113 ;
V_52 . V_21 . V_42 = V_58 . V_21 . V_52 ;
} else {
union V_102 V_114 ;
V_114 = F_40 ( V_109 , V_53 ) ;
if ( F_3 ( V_115 ) || F_3 ( V_116 ) ) {
V_52 . V_21 . V_99 = V_114 . V_117 . V_99 ;
V_52 . V_21 . V_110 = V_114 . V_117 . V_110 ;
V_52 . V_21 . V_100 = V_114 . V_117 . V_100 ;
V_52 . V_21 . V_112 = V_114 . V_117 . V_112 ;
V_52 . V_21 . V_42 = V_114 . V_117 . V_42 ;
} else if ( F_3 ( V_118 ) ) {
V_52 . V_21 . V_99 = V_114 . V_119 . V_99 ;
V_52 . V_21 . V_110 = V_114 . V_119 . V_110 ;
V_52 . V_21 . V_100 = V_114 . V_119 . V_100 ;
V_52 . V_21 . V_112 = V_114 . V_119 . V_112 ;
V_52 . V_21 . V_42 = V_114 . V_119 . V_42 ;
} else if ( F_3 ( V_120 ) || F_3 ( V_121 ) ) {
V_52 . V_21 . V_99 = V_114 . V_122 . V_99 ;
V_52 . V_21 . V_110 = V_114 . V_122 . V_110 ;
V_52 . V_21 . V_100 = V_114 . V_122 . V_100 ;
V_52 . V_21 . V_112 = V_114 . V_122 . V_112 ;
V_52 . V_21 . V_42 = V_114 . V_122 . V_42 ;
} else if ( F_3 ( V_123 ) ) {
V_52 . V_21 . V_99 = V_114 . V_124 . V_99 ;
V_52 . V_21 . V_110 = V_114 . V_124 . V_110 ;
V_52 . V_21 . V_100 = V_114 . V_124 . V_100 ;
V_52 . V_21 . V_112 = V_114 . V_124 . V_112 ;
V_52 . V_21 . V_42 = V_114 . V_124 . V_42 ;
} else if ( F_3 ( V_125 ) ) {
V_52 . V_21 . V_99 = V_114 . V_126 . V_99 ;
V_52 . V_21 . V_110 = V_114 . V_126 . V_110 ;
V_52 . V_21 . V_100 = V_114 . V_126 . V_100 ;
V_52 . V_21 . V_112 = V_114 . V_126 . V_112 ;
V_52 . V_21 . V_42 = V_114 . V_126 . V_42 ;
} else {
F_13 ( L_5 , V_127 ) ;
}
}
return V_52 ;
}
T_1 F_24 ( T_2 V_42 )
{
T_2 V_128 = V_42 >> V_55 ;
int V_129 = 0 ;
if ( F_3 ( V_92 ) ) {
union V_130 V_131 ;
V_131 . V_19 = F_4 ( V_132 ) ;
V_129 = ! V_131 . V_21 . V_133 ;
} else {
union V_79 V_134 ;
V_134 . V_19 = F_4 ( V_80 ) ;
V_129 = V_134 . V_21 . V_81 ;
}
if ( V_129 ) {
if ( F_3 ( V_3 ) ) {
T_1 V_135 = ( V_128 / ( V_136 / ( 1 << V_55 ) ) ) & 0x7 ;
V_128 ^= V_128 / F_33 () ;
V_128 ^= V_135 ;
} else {
V_128 ^= ( ( V_42 & V_137 ) >> V_50 ) ;
}
}
V_128 &= V_138 ;
return V_128 ;
}
int F_43 ( void )
{
return F_33 () * F_7 () *
V_48 ;
}
int F_44 ( void )
{
int V_139 ;
if ( F_3 ( V_116 ) || F_3 ( V_115 ) )
V_139 = 11 ;
else if ( F_3 ( V_118 ) || F_3 ( V_3 ) )
V_139 = 10 ;
else if ( F_3 ( V_120 ) || F_3 ( V_121 ) )
V_139 = 9 ;
else if ( F_3 ( V_123 ) )
V_139 = 8 ;
else if ( F_3 ( V_125 ) )
V_139 = 7 ;
else {
F_13 ( L_5 , V_127 ) ;
V_139 = 11 ;
}
return V_139 ;
}
int F_33 ( void )
{
return 1 << F_44 () ;
}
int F_7 ( void )
{
int V_140 ;
if ( F_3 ( V_116 ) ||
F_3 ( V_121 ) ||
F_3 ( V_115 ) ||
F_3 ( V_125 ) ||
F_3 ( V_118 ) )
V_140 = 8 ;
else if ( F_3 ( V_3 ) )
V_140 = 16 ;
else if ( F_3 ( V_120 ) ||
F_3 ( V_123 ) )
V_140 = 4 ;
else {
F_13 ( L_5 , V_127 ) ;
V_140 = 8 ;
}
if ( F_3 ( V_3 ) ) {
union V_141 V_142 ;
V_142 . V_19 = F_4 ( V_143 ) ;
if ( V_142 . V_21 . V_144 == 3 )
V_140 = 4 ;
else if ( V_142 . V_21 . V_144 == 2 )
V_140 = 8 ;
else if ( V_142 . V_21 . V_144 == 1 )
V_140 = 12 ;
} else {
union V_145 V_146 ;
V_146 . V_19 = F_4 ( V_147 ) ;
if ( ( V_146 . V_19 >> 35 ) & 0x1 )
V_140 = V_140 >> 2 ;
else if ( ( V_146 . V_19 >> 34 ) & 0x1 )
V_140 = V_140 >> 1 ;
}
return V_140 ;
}
void F_35 ( T_1 V_51 , T_1 V_53 )
{
if ( V_53 > ( T_1 ) F_33 () ) {
F_13 ( L_6 ) ;
return;
}
if ( V_51 > ( T_1 ) F_7 () ) {
F_13 ( L_7 ) ;
return;
}
if ( F_3 ( V_3 ) ) {
T_2 V_93 ;
V_93 = F_23 ( V_54 ,
( V_51 << V_50 ) |
( V_53 << V_55 ) ) ;
F_34 ( V_93 , 0 ) ;
} else {
union V_63 V_64 ;
V_64 . V_19 = 0 ;
if ( ! F_3 ( V_123 ) )
V_64 . V_21 . V_75 = F_29 () ;
V_64 . V_21 . V_148 = 1 ;
V_64 . V_21 . V_89 = V_51 ;
F_28 ( & V_71 ) ;
V_59 ;
F_8 ( V_76 , V_64 . V_19 ) ;
F_4 ( V_76 ) ;
F_45 ( F_23 ( V_54 ,
V_53 * V_48 ) ,
0 ) ;
V_59 ;
F_8 ( V_76 , 0 ) ;
F_4 ( V_76 ) ;
F_30 ( & V_71 ) ;
}
}
