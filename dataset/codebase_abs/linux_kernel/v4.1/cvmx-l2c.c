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
char * V_44 ;
V_43 += V_42 & V_45 ;
V_42 &= ~ V_45 ;
V_44 = F_21 ( V_42 ) ;
V_46 ;
while ( V_43 > 0 ) {
F_22 ( * V_44 ) ;
V_43 -= V_47 ;
V_44 += V_47 ;
}
}
int F_23 ( T_2 V_42 )
{
if ( F_3 ( V_3 ) ) {
int V_48 = V_49 ;
T_2 V_50 = F_7 () ;
T_2 V_51 = V_42 >> V_48 ;
T_2 V_52 = F_24 ( V_53 , F_25 ( V_42 ) << V_54 ) ;
T_2 V_55 ;
union V_56 V_57 ;
F_26 ( F_24 ( V_53 , V_42 ) , 0 ) ;
for ( V_55 = 0 ; V_55 < V_50 ; V_55 ++ ) {
F_27 ( V_52 | ( V_55 << V_48 ) , 0 ) ;
V_58 ;
V_57 . V_19 = F_4 ( F_28 ( 0 ) ) ;
if ( V_57 . V_21 . V_59 && V_57 . V_21 . V_51 == V_51 )
break;
}
if ( V_55 >= V_50 ) {
return - 1 ;
}
if ( ! V_57 . V_21 . V_60 ) {
return - 1 ;
}
return V_55 ;
} else {
int V_61 = 0 ;
union V_62 V_63 ;
union V_64 V_65 ;
union V_66 V_67 ;
union V_68 V_69 ;
F_29 ( & V_70 ) ;
V_63 . V_19 = 0 ;
V_65 . V_19 = 0 ;
V_67 . V_19 = 0 ;
V_69 . V_19 = F_4 ( V_71 ) ;
V_69 . V_21 . V_72 = 1 ;
V_69 . V_21 . V_73 = 1 ;
F_8 ( V_71 , V_69 . V_19 ) ;
V_42 &= ~ V_45 ;
V_63 . V_21 . V_74 = F_30 () ;
V_58 ;
F_8 ( V_75 , V_63 . V_19 ) ;
F_4 ( V_75 ) ;
V_67 . V_21 . V_76 = 0 ;
F_8 ( V_77 , V_67 . V_19 ) ;
F_4 ( V_77 ) ;
if ( ( (union V_78 ) ( F_4 ( V_79 ) ) ) . V_21 . V_80 ) {
int V_81 = V_54 + 2 * V_82 - 1 ;
T_2 V_83 = V_42 ^ ( V_42 & ( ( 1 << V_81 ) - 1 ) ) >> V_82 ;
V_65 . V_21 . V_84 = V_83 >> 7 ;
} else {
V_65 . V_21 . V_84 = V_42 >> 7 ;
}
V_65 . V_21 . V_85 = 1 ;
F_8 ( V_86 , V_65 . V_19 ) ;
F_4 ( V_86 ) ;
F_20 ( V_42 , V_47 ) ;
V_65 . V_21 . V_85 = 0 ;
F_8 ( V_86 , V_65 . V_19 ) ;
F_4 ( V_86 ) ;
F_8 ( V_75 , 0 ) ;
F_4 ( V_75 ) ;
V_69 . V_19 = F_4 ( V_71 ) ;
if ( V_69 . V_21 . V_72 || V_69 . V_21 . V_73 )
V_61 = 1 ;
F_31 ( & V_70 ) ;
return V_61 ;
}
}
int F_32 ( T_2 V_87 , T_2 V_43 )
{
int V_61 = 0 ;
V_43 += V_87 & V_45 ;
V_87 &= ~ V_45 ;
V_43 = ( V_43 + V_45 ) & ~ V_45 ;
while ( V_43 ) {
V_61 += F_23 ( V_87 ) ;
V_87 += V_47 ;
V_43 -= V_47 ;
}
return V_61 ;
}
void F_33 ( void )
{
T_2 V_50 , V_88 ;
T_2 V_89 , V_90 ;
V_90 = F_34 () ;
V_89 = F_7 () ;
if ( F_3 ( V_91 ) ) {
T_2 V_92 ;
int V_93 = V_49 ;
int V_94 = V_54 ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ ) {
for ( V_50 = 0 ; V_50 < V_89 ; V_50 ++ ) {
V_92 = F_24 ( V_53 ,
( V_50 << V_93 ) | ( V_88 << V_94 ) ) ;
F_35 ( V_92 , 0 ) ;
}
}
} else {
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ )
for ( V_50 = 0 ; V_50 < V_89 ; V_50 ++ )
F_36 ( V_50 , V_88 ) ;
}
}
int F_37 ( T_2 V_92 )
{
if ( F_3 ( V_3 ) ) {
int V_50 ;
union V_95 V_51 ;
T_1 V_96 ;
T_1 V_52 = F_25 ( V_92 ) ;
V_96 = ( ( V_92 >> V_49 ) & ( ( 1 << V_49 ) - 1 ) ) ;
for ( V_50 = 0 ; V_50 < V_97 ; V_50 ++ ) {
V_51 = F_38 ( V_50 , V_52 ) ;
if ( V_51 . V_21 . V_98 && ( V_51 . V_21 . V_42 == V_96 ) ) {
F_39 ( F_24 ( V_53 , V_92 ) , 0 ) ;
return V_51 . V_21 . V_99 ;
}
}
} else {
int V_50 ;
union V_95 V_51 ;
T_1 V_96 ;
T_1 V_52 = F_25 ( V_92 ) ;
V_96 = ( ( V_92 >> V_49 ) & ( ( 1 << V_49 ) - 1 ) ) ;
for ( V_50 = 0 ; V_50 < V_97 ; V_50 ++ ) {
V_51 = F_38 ( V_50 , V_52 ) ;
if ( V_51 . V_21 . V_98 && ( V_51 . V_21 . V_42 == V_96 ) ) {
F_36 ( V_50 , V_52 ) ;
return V_51 . V_21 . V_99 ;
}
}
}
return 0 ;
}
int F_40 ( T_2 V_87 , T_2 V_43 )
{
int V_100 = 0 ;
V_43 += V_87 & V_45 ;
V_87 &= ~ V_45 ;
V_43 = ( V_43 + V_45 ) & ~ V_45 ;
while ( V_43 > 0 ) {
V_100 += F_37 ( V_87 ) ;
V_87 += V_47 ;
V_43 -= V_47 ;
}
return V_100 ;
}
static union V_101 F_41 ( T_2 V_50 , T_2 V_52 )
{
T_2 V_102 = F_24 ( V_53 , ( V_52 << 7 ) + 96 ) ;
T_2 V_1 = F_30 () ;
union V_101 V_103 ;
T_2 V_104 = V_75 ;
unsigned long V_105 ;
union V_62 V_106 ;
V_106 . V_19 = 0 ;
V_106 . V_21 . V_74 = V_1 ;
V_106 . V_21 . V_107 = 1 ;
V_106 . V_21 . V_88 = V_50 ;
F_42 ( V_105 ) ;
V_58 ;
V_46 ;
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
F_43 ( V_105 ) ;
return V_103 ;
}
union V_95 F_38 ( T_1 V_108 , T_1 V_52 )
{
union V_95 V_51 ;
V_51 . V_19 = 0 ;
if ( ( int ) V_108 >= F_7 () ) {
F_13 ( L_3 ) ;
return V_51 ;
}
if ( ( int ) V_52 >= F_34 () ) {
F_13 ( L_4 ,
( int ) V_52 , F_34 () ) ;
return V_51 ;
}
if ( F_3 ( V_3 ) ) {
union V_56 V_57 ;
T_2 V_92 = F_24 ( V_53 ,
( V_108 << V_49 ) |
( V_52 << V_54 ) ) ;
F_27 ( V_92 , 0 ) ;
V_58 ;
V_57 . V_19 = F_4 ( F_28 ( 0 ) ) ;
V_51 . V_21 . V_98 = V_57 . V_21 . V_59 ;
V_51 . V_21 . V_109 = V_57 . V_21 . V_110 ;
V_51 . V_21 . V_99 = V_57 . V_21 . V_60 ;
V_51 . V_21 . V_111 = V_57 . V_21 . V_112 ;
V_51 . V_21 . V_42 = V_57 . V_21 . V_51 ;
} else {
union V_101 V_113 ;
V_113 = F_41 ( V_108 , V_52 ) ;
if ( F_3 ( V_114 ) || F_3 ( V_115 ) ) {
V_51 . V_21 . V_98 = V_113 . V_116 . V_98 ;
V_51 . V_21 . V_109 = V_113 . V_116 . V_109 ;
V_51 . V_21 . V_99 = V_113 . V_116 . V_99 ;
V_51 . V_21 . V_111 = V_113 . V_116 . V_111 ;
V_51 . V_21 . V_42 = V_113 . V_116 . V_42 ;
} else if ( F_3 ( V_117 ) ) {
V_51 . V_21 . V_98 = V_113 . V_118 . V_98 ;
V_51 . V_21 . V_109 = V_113 . V_118 . V_109 ;
V_51 . V_21 . V_99 = V_113 . V_118 . V_99 ;
V_51 . V_21 . V_111 = V_113 . V_118 . V_111 ;
V_51 . V_21 . V_42 = V_113 . V_118 . V_42 ;
} else if ( F_3 ( V_119 ) || F_3 ( V_120 ) ) {
V_51 . V_21 . V_98 = V_113 . V_121 . V_98 ;
V_51 . V_21 . V_109 = V_113 . V_121 . V_109 ;
V_51 . V_21 . V_99 = V_113 . V_121 . V_99 ;
V_51 . V_21 . V_111 = V_113 . V_121 . V_111 ;
V_51 . V_21 . V_42 = V_113 . V_121 . V_42 ;
} else if ( F_3 ( V_122 ) ) {
V_51 . V_21 . V_98 = V_113 . V_123 . V_98 ;
V_51 . V_21 . V_109 = V_113 . V_123 . V_109 ;
V_51 . V_21 . V_99 = V_113 . V_123 . V_99 ;
V_51 . V_21 . V_111 = V_113 . V_123 . V_111 ;
V_51 . V_21 . V_42 = V_113 . V_123 . V_42 ;
} else if ( F_3 ( V_124 ) ) {
V_51 . V_21 . V_98 = V_113 . V_125 . V_98 ;
V_51 . V_21 . V_109 = V_113 . V_125 . V_109 ;
V_51 . V_21 . V_99 = V_113 . V_125 . V_99 ;
V_51 . V_21 . V_111 = V_113 . V_125 . V_111 ;
V_51 . V_21 . V_42 = V_113 . V_125 . V_42 ;
} else {
F_13 ( L_5 , V_126 ) ;
}
}
return V_51 ;
}
T_1 F_25 ( T_2 V_42 )
{
T_2 V_127 = V_42 >> V_54 ;
int V_128 = 0 ;
if ( F_3 ( V_91 ) ) {
union V_129 V_130 ;
V_130 . V_19 = F_4 ( V_131 ) ;
V_128 = ! V_130 . V_21 . V_132 ;
} else {
union V_78 V_133 ;
V_133 . V_19 = F_4 ( V_79 ) ;
V_128 = V_133 . V_21 . V_80 ;
}
if ( V_128 ) {
if ( F_3 ( V_3 ) ) {
T_1 V_134 = ( V_127 / ( V_135 / ( 1 << V_54 ) ) ) & 0x7 ;
V_127 ^= V_127 / F_34 () ;
V_127 ^= V_134 ;
} else {
V_127 ^= ( ( V_42 & V_136 ) >> V_49 ) ;
}
}
V_127 &= V_137 ;
return V_127 ;
}
int F_44 ( void )
{
return F_34 () * F_7 () *
V_47 ;
}
int F_45 ( void )
{
int V_138 ;
if ( F_3 ( V_115 ) || F_3 ( V_114 ) )
V_138 = 11 ;
else if ( F_3 ( V_117 ) || F_3 ( V_3 ) )
V_138 = 10 ;
else if ( F_3 ( V_119 ) || F_3 ( V_120 ) )
V_138 = 9 ;
else if ( F_3 ( V_122 ) )
V_138 = 8 ;
else if ( F_3 ( V_124 ) )
V_138 = 7 ;
else {
F_13 ( L_5 , V_126 ) ;
V_138 = 11 ;
}
return V_138 ;
}
int F_34 ( void )
{
return 1 << F_45 () ;
}
int F_7 ( void )
{
int V_139 ;
if ( F_3 ( V_115 ) ||
F_3 ( V_120 ) ||
F_3 ( V_114 ) ||
F_3 ( V_124 ) ||
F_3 ( V_117 ) )
V_139 = 8 ;
else if ( F_3 ( V_3 ) )
V_139 = 16 ;
else if ( F_3 ( V_119 ) ||
F_3 ( V_122 ) )
V_139 = 4 ;
else {
F_13 ( L_5 , V_126 ) ;
V_139 = 8 ;
}
if ( F_3 ( V_3 ) ) {
union V_140 V_141 ;
V_141 . V_19 = F_4 ( V_142 ) ;
if ( V_141 . V_21 . V_143 == 3 )
V_139 = 4 ;
else if ( V_141 . V_21 . V_143 == 2 )
V_139 = 8 ;
else if ( V_141 . V_21 . V_143 == 1 )
V_139 = 12 ;
} else {
union V_144 V_145 ;
V_145 . V_19 = F_4 ( V_146 ) ;
if ( ( V_145 . V_19 >> 35 ) & 0x1 )
V_139 = V_139 >> 2 ;
else if ( ( V_145 . V_19 >> 34 ) & 0x1 )
V_139 = V_139 >> 1 ;
}
return V_139 ;
}
void F_36 ( T_1 V_50 , T_1 V_52 )
{
if ( V_52 > ( T_1 ) F_34 () ) {
F_13 ( L_6 ) ;
return;
}
if ( V_50 > ( T_1 ) F_7 () ) {
F_13 ( L_7 ) ;
return;
}
if ( F_3 ( V_3 ) ) {
T_2 V_92 ;
V_92 = F_24 ( V_53 ,
( V_50 << V_49 ) |
( V_52 << V_54 ) ) ;
F_35 ( V_92 , 0 ) ;
} else {
union V_62 V_63 ;
V_63 . V_19 = 0 ;
if ( ! F_3 ( V_122 ) )
V_63 . V_21 . V_74 = F_30 () ;
V_63 . V_21 . V_147 = 1 ;
V_63 . V_21 . V_88 = V_50 ;
F_29 ( & V_70 ) ;
V_58 ;
F_8 ( V_75 , V_63 . V_19 ) ;
F_4 ( V_75 ) ;
F_46 ( F_24 ( V_53 ,
V_52 * V_47 ) ,
0 ) ;
V_58 ;
F_8 ( V_75 , 0 ) ;
F_4 ( V_75 ) ;
F_31 ( & V_70 ) ;
}
}
