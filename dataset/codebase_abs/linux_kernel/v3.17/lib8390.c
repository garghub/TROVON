static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_2 -> V_6 <= 0 )
V_2 -> V_6 = V_7 ;
F_3 ( & V_5 -> V_8 , V_3 ) ;
F_4 ( V_2 , 1 ) ;
F_5 ( V_2 ) ;
F_6 ( & V_5 -> V_8 , V_3 ) ;
V_5 -> V_9 = 0 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_3 ;
F_3 ( & V_5 -> V_8 , V_3 ) ;
F_4 ( V_2 , 0 ) ;
F_6 ( & V_5 -> V_8 , V_3 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_10 = V_2 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_12 , V_13 , V_14 = V_15 - F_10 ( V_2 ) ;
unsigned long V_3 ;
V_2 -> V_16 . V_17 ++ ;
F_3 ( & V_5 -> V_8 , V_3 ) ;
V_12 = F_11 ( V_10 + V_18 ) ;
V_13 = F_11 ( V_10 + V_19 ) ;
F_6 ( & V_5 -> V_8 , V_3 ) ;
F_12 ( V_2 , L_1 ,
( V_12 & V_20 ) ? L_2 :
( V_13 ) ? L_3 : L_4 ,
V_12 , V_13 , V_14 ) ;
if ( ! V_13 && ! V_2 -> V_16 . V_21 ) {
V_5 -> V_22 ^= 1 ;
}
F_13 ( V_2 -> V_23 ) ;
F_14 ( & V_5 -> V_8 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 , 1 ) ;
F_16 ( & V_5 -> V_8 ) ;
F_17 ( V_2 -> V_23 ) ;
F_18 ( V_2 ) ;
}
static T_1 F_19 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
unsigned long V_10 = V_2 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_26 = V_25 -> V_27 , V_28 ;
unsigned long V_3 ;
char V_29 [ V_30 ] ;
char * V_31 = V_25 -> V_31 ;
if ( V_25 -> V_27 < V_30 ) {
memset ( V_29 , 0 , V_30 ) ;
memcpy ( V_29 , V_31 , V_25 -> V_27 ) ;
V_26 = V_30 ;
V_31 = V_29 ;
}
F_3 ( & V_5 -> V_8 , V_3 ) ;
F_20 ( 0x00 , V_10 + V_32 ) ;
F_6 ( & V_5 -> V_8 , V_3 ) ;
F_21 ( V_2 -> V_23 , & V_3 ) ;
F_14 ( & V_5 -> V_8 ) ;
V_5 -> V_9 = 1 ;
if ( V_5 -> V_33 == 0 ) {
V_28 = V_5 -> V_34 ;
V_5 -> V_33 = V_26 ;
if ( ( F_22 ( V_5 ) ) &&
V_5 -> V_35 > 0 )
F_12 ( V_2 ,
L_5 ,
V_5 -> V_35 , V_5 -> V_36 , V_5 -> V_37 ) ;
} else if ( V_5 -> V_35 == 0 ) {
V_28 = V_5 -> V_34 + V_38 / 2 ;
V_5 -> V_35 = V_26 ;
if ( ( F_22 ( V_5 ) ) &&
V_5 -> V_33 > 0 )
F_12 ( V_2 ,
L_6 ,
V_5 -> V_33 , V_5 -> V_36 , V_5 -> V_37 ) ;
} else {
F_23 ( V_5 , V_39 , V_2 ,
L_7 ,
V_5 -> V_33 , V_5 -> V_35 , V_5 -> V_36 ) ;
V_5 -> V_9 = 0 ;
F_8 ( V_2 ) ;
F_20 ( V_40 , V_10 + V_32 ) ;
F_16 ( & V_5 -> V_8 ) ;
F_24 ( V_2 -> V_23 , & V_3 ) ;
V_2 -> V_16 . V_17 ++ ;
return V_41 ;
}
F_25 ( V_2 , V_26 , V_31 , V_28 ) ;
if ( ! V_5 -> V_37 ) {
V_5 -> V_37 = 1 ;
F_26 ( V_2 , V_26 , V_28 ) ;
if ( V_28 == V_5 -> V_34 ) {
V_5 -> V_33 = - 1 ;
V_5 -> V_36 = - 1 ;
} else {
V_5 -> V_35 = - 1 ;
V_5 -> V_36 = - 2 ;
}
} else
V_5 -> V_42 ++ ;
if ( V_5 -> V_33 && V_5 -> V_35 )
F_8 ( V_2 ) ;
else
F_5 ( V_2 ) ;
V_5 -> V_9 = 0 ;
F_20 ( V_40 , V_10 + V_32 ) ;
F_16 ( & V_5 -> V_8 ) ;
F_24 ( V_2 -> V_23 , & V_3 ) ;
F_27 ( V_25 ) ;
F_28 ( V_25 ) ;
V_2 -> V_16 . V_43 += V_26 ;
return V_44 ;
}
static T_2 F_29 ( int V_23 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
unsigned long V_10 = V_2 -> V_11 ;
int V_46 , V_47 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_14 ( & V_5 -> V_8 ) ;
if ( V_5 -> V_9 ) {
F_30 ( V_2 , L_8 ,
F_31 ( V_10 + V_19 ) ,
F_31 ( V_10 + V_32 ) ) ;
F_16 ( & V_5 -> V_8 ) ;
return V_48 ;
}
F_20 ( V_49 + V_50 , V_10 + V_51 ) ;
F_23 ( V_5 , V_52 , V_2 , L_9 ,
F_31 ( V_10 + V_19 ) ) ;
while ( ( V_46 = F_31 ( V_10 + V_19 ) ) != 0 &&
++ V_47 < V_53 ) {
if ( ! F_32 ( V_2 ) ) {
F_33 ( V_2 , L_10 ) ;
F_20 ( V_46 , V_10 + V_19 ) ;
V_46 = 0 ;
break;
}
if ( V_46 & V_54 )
F_34 ( V_2 ) ;
else if ( V_46 & ( V_55 + V_56 ) ) {
F_35 ( V_2 ) ;
}
if ( V_46 & V_57 )
F_36 ( V_2 ) ;
else if ( V_46 & V_58 )
F_37 ( V_2 ) ;
if ( V_46 & V_59 ) {
V_2 -> V_16 . V_60 += F_31 ( V_10 + V_61 ) ;
V_2 -> V_16 . V_62 += F_31 ( V_10 + V_63 ) ;
V_2 -> V_16 . V_64 += F_31 ( V_10 + V_65 ) ;
F_20 ( V_59 , V_10 + V_19 ) ;
}
if ( V_46 & V_66 )
F_20 ( V_66 , V_10 + V_19 ) ;
F_20 ( V_49 + V_50 + V_67 , V_10 + V_51 ) ;
}
if ( V_46 && ( F_38 ( V_5 ) ) ) {
F_20 ( V_49 + V_50 + V_67 , V_10 + V_51 ) ;
if ( V_47 >= V_53 ) {
if ( V_46 != 0xFF )
F_33 ( V_2 , L_11 ,
V_46 ) ;
F_20 ( V_40 , V_10 + V_19 ) ;
} else {
F_33 ( V_2 , L_12 , V_46 ) ;
F_20 ( 0xff , V_10 + V_19 ) ;
}
}
F_16 ( & V_5 -> V_8 ) ;
return F_39 ( V_47 > 0 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 -> V_23 ) ;
F_29 ( V_2 -> V_23 , V_2 ) ;
F_42 ( V_2 -> V_23 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned long V_10 = V_2 -> V_11 ;
struct V_4 * V_5 V_68 = F_2 ( V_2 ) ;
unsigned char V_12 = F_31 ( V_10 + V_18 ) ;
unsigned char V_69 = V_12 & ( V_20 + V_70 ) ;
#ifdef F_43
F_12 ( V_2 , L_13 , V_12 ) ;
if ( V_12 & V_20 )
F_44 ( L_14 ) ;
if ( V_12 & V_71 )
F_44 ( L_15 ) ;
if ( V_12 & V_72 )
F_44 ( L_16 ) ;
if ( V_12 & V_70 )
F_44 ( L_17 ) ;
if ( V_12 & V_73 )
F_44 ( L_18 ) ;
F_44 ( L_19 ) ;
#endif
F_20 ( V_58 , V_10 + V_19 ) ;
if ( V_69 )
F_36 ( V_2 ) ;
else {
V_2 -> V_16 . V_17 ++ ;
if ( V_12 & V_72 )
V_2 -> V_16 . V_74 ++ ;
if ( V_12 & V_73 )
V_2 -> V_16 . V_75 ++ ;
if ( V_12 & V_76 )
V_2 -> V_16 . V_77 ++ ;
}
}
static void F_36 ( struct V_1 * V_2 )
{
unsigned long V_10 = V_2 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_78 = F_11 ( V_10 + V_18 ) ;
F_20 ( V_57 , V_10 + V_19 ) ;
V_5 -> V_42 -- ;
if ( V_5 -> V_33 < 0 ) {
if ( V_5 -> V_36 != 1 && V_5 -> V_36 != - 1 )
F_45 ( L_20 ,
V_5 -> V_79 , V_5 -> V_36 , V_5 -> V_33 ) ;
V_5 -> V_33 = 0 ;
if ( V_5 -> V_35 > 0 ) {
V_5 -> V_37 = 1 ;
F_26 ( V_2 , V_5 -> V_35 , V_5 -> V_34 + 6 ) ;
V_2 -> V_80 = V_15 ;
V_5 -> V_35 = - 1 ,
V_5 -> V_36 = 2 ;
} else
V_5 -> V_36 = 20 , V_5 -> V_37 = 0 ;
} else if ( V_5 -> V_35 < 0 ) {
if ( V_5 -> V_36 != 2 && V_5 -> V_36 != - 2 )
F_45 ( L_21 ,
V_5 -> V_79 , V_5 -> V_36 , V_5 -> V_35 ) ;
V_5 -> V_35 = 0 ;
if ( V_5 -> V_33 > 0 ) {
V_5 -> V_37 = 1 ;
F_26 ( V_2 , V_5 -> V_33 , V_5 -> V_34 ) ;
V_2 -> V_80 = V_15 ;
V_5 -> V_33 = - 1 ;
V_5 -> V_36 = 1 ;
} else
V_5 -> V_36 = 10 , V_5 -> V_37 = 0 ;
}
if ( V_78 & V_81 )
V_2 -> V_16 . V_82 ++ ;
if ( V_78 & V_83 )
V_2 -> V_16 . V_21 ++ ;
else {
V_2 -> V_16 . V_17 ++ ;
if ( V_78 & V_20 ) {
V_2 -> V_16 . V_84 ++ ;
V_2 -> V_16 . V_82 += 16 ;
}
if ( V_78 & V_72 )
V_2 -> V_16 . V_74 ++ ;
if ( V_78 & V_70 )
V_2 -> V_16 . V_85 ++ ;
if ( V_78 & V_73 )
V_2 -> V_16 . V_75 ++ ;
if ( V_78 & V_76 )
V_2 -> V_16 . V_77 ++ ;
}
F_18 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
unsigned long V_10 = V_2 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_86 , V_87 , V_88 ;
unsigned short V_89 ;
int V_90 = 0 ;
struct V_91 V_92 ;
int V_93 = V_5 -> V_94 - V_5 -> V_95 ;
while ( ++ V_90 < 10 ) {
int V_96 , V_97 ;
F_20 ( V_49 + V_98 , V_10 + V_51 ) ;
V_86 = F_31 ( V_10 + V_99 ) ;
F_20 ( V_49 + V_50 , V_10 + V_51 ) ;
V_87 = F_31 ( V_10 + V_100 ) + 1 ;
if ( V_87 >= V_5 -> V_94 )
V_87 = V_5 -> V_95 ;
if ( ( F_46 ( V_5 ) ) &&
V_87 != V_5 -> V_101 &&
( V_87 != 0x0 || V_86 != 0xFF ) )
F_30 ( V_2 ,
L_22 ,
V_87 , V_5 -> V_101 ) ;
if ( V_87 == V_86 )
break;
V_89 = V_87 << 8 ;
F_47 ( V_2 , & V_92 , V_87 ) ;
V_96 = V_92 . V_102 - sizeof( struct V_91 ) ;
V_97 = V_92 . V_78 ;
V_88 = V_87 + 1 + ( ( V_96 + 4 ) >> 8 ) ;
if ( V_92 . V_103 != V_88 &&
V_92 . V_103 != V_88 + 1 &&
V_92 . V_103 != V_88 - V_93 &&
V_92 . V_103 != V_88 + 1 - V_93 ) {
V_5 -> V_101 = V_86 ;
F_48 ( V_5 -> V_101 - 1 , V_10 + V_100 ) ;
V_2 -> V_16 . V_104 ++ ;
continue;
}
if ( V_96 < 60 || V_96 > 1518 ) {
F_23 ( V_5 , V_105 , V_2 ,
L_23 ,
V_92 . V_102 , V_92 . V_78 ,
V_92 . V_103 ) ;
V_2 -> V_16 . V_104 ++ ;
V_2 -> V_16 . V_106 ++ ;
} else if ( ( V_97 & 0x0F ) == V_107 ) {
struct V_24 * V_25 ;
V_25 = F_49 ( V_2 , V_96 + 2 ) ;
if ( V_25 == NULL ) {
F_50 ( V_5 , V_108 , V_2 ,
L_24 ,
V_96 ) ;
V_2 -> V_16 . V_109 ++ ;
break;
} else {
F_51 ( V_25 , 2 ) ;
F_52 ( V_25 , V_96 ) ;
F_53 ( V_2 , V_96 , V_25 , V_89 + sizeof( V_92 ) ) ;
V_25 -> V_110 = F_54 ( V_25 , V_2 ) ;
if ( ! F_55 ( V_25 ) )
F_56 ( V_25 ) ;
V_2 -> V_16 . V_111 ++ ;
V_2 -> V_16 . V_112 += V_96 ;
if ( V_97 & V_113 )
V_2 -> V_16 . V_114 ++ ;
}
} else {
F_50 ( V_5 , V_108 , V_2 ,
L_25 ,
V_92 . V_78 , V_92 . V_103 ,
V_92 . V_102 ) ;
V_2 -> V_16 . V_104 ++ ;
if ( V_97 & V_115 )
V_2 -> V_16 . V_116 ++ ;
}
V_88 = V_92 . V_103 ;
if ( V_88 >= V_5 -> V_94 ) {
F_57 ( V_2 , L_26 ,
V_88 ) ;
V_88 = V_5 -> V_95 ;
}
V_5 -> V_101 = V_88 ;
F_20 ( V_88 - 1 , V_10 + V_100 ) ;
}
F_20 ( V_55 + V_56 , V_10 + V_19 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
unsigned long V_10 = V_2 -> V_11 ;
unsigned char V_117 , V_118 = 0 ;
struct V_4 * V_5 V_68 = F_2 ( V_2 ) ;
V_117 = F_31 ( V_10 + V_51 ) & V_119 ;
F_20 ( V_49 + V_50 + V_120 , V_10 + V_51 ) ;
F_23 ( V_5 , V_108 , V_2 , L_27 ) ;
V_2 -> V_16 . V_121 ++ ;
F_58 ( 10 ) ;
F_20 ( 0x00 , V_10 + V_122 ) ;
F_20 ( 0x00 , V_10 + V_123 ) ;
if ( V_117 ) {
unsigned char V_124 = F_31 ( V_10 + V_19 ) & ( V_57 + V_58 ) ;
if ( ! V_124 )
V_118 = 1 ;
}
F_20 ( V_125 , V_10 + V_126 ) ;
F_20 ( V_49 + V_50 + V_67 , V_10 + V_51 ) ;
F_35 ( V_2 ) ;
F_20 ( V_54 , V_10 + V_19 ) ;
F_20 ( V_127 , V_10 + V_126 ) ;
if ( V_118 )
F_20 ( V_49 + V_50 + V_67 + V_119 , V_10 + V_51 ) ;
}
static struct V_128 * F_59 ( struct V_1 * V_2 )
{
unsigned long V_129 = V_2 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_3 ;
if ( ! F_32 ( V_2 ) )
return & V_2 -> V_16 ;
F_3 ( & V_5 -> V_8 , V_3 ) ;
V_2 -> V_16 . V_60 += F_31 ( V_129 + V_61 ) ;
V_2 -> V_16 . V_62 += F_31 ( V_129 + V_63 ) ;
V_2 -> V_16 . V_64 += F_31 ( V_129 + V_65 ) ;
F_6 ( & V_5 -> V_8 , V_3 ) ;
return & V_2 -> V_16 ;
}
static inline void F_60 ( T_3 * V_130 , struct V_1 * V_2 )
{
struct V_131 * V_132 ;
F_61 (ha, dev) {
T_4 V_133 = F_62 ( V_134 , V_132 -> V_135 ) ;
V_130 [ V_133 >> 29 ] |= ( 1 << ( ( V_133 >> 26 ) & 7 ) ) ;
}
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned long V_10 = V_2 -> V_11 ;
int V_136 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! ( V_2 -> V_3 & ( V_137 | V_138 ) ) ) {
memset ( V_5 -> V_139 , 0 , 8 ) ;
if ( ! F_64 ( V_2 ) )
F_60 ( V_5 -> V_139 , V_2 ) ;
} else
memset ( V_5 -> V_139 , 0xFF , 8 ) ;
if ( F_32 ( V_2 ) )
F_20 ( V_140 , V_10 + V_141 ) ;
F_20 ( V_49 + V_98 , V_10 + V_51 ) ;
for ( V_136 = 0 ; V_136 < 8 ; V_136 ++ ) {
F_20 ( V_5 -> V_139 [ V_136 ] , V_10 + F_65 ( V_136 ) ) ;
#ifndef F_66
if ( F_31 ( V_10 + F_65 ( V_136 ) ) != V_5 -> V_139 [ V_136 ] )
F_30 ( V_2 , L_28 ,
V_136 ) ;
#endif
}
F_20 ( V_49 + V_50 , V_10 + V_51 ) ;
if ( V_2 -> V_3 & V_137 )
F_20 ( V_140 | 0x18 , V_10 + V_141 ) ;
else if ( V_2 -> V_3 & V_138 || ! F_64 ( V_2 ) )
F_20 ( V_140 | 0x08 , V_10 + V_141 ) ;
else
F_20 ( V_140 , V_10 + V_141 ) ;
}
static void F_67 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( & V_5 -> V_8 , V_3 ) ;
F_63 ( V_2 ) ;
F_6 ( & V_5 -> V_8 , V_3 ) ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ( V_142 & V_143 ) && ( V_144 ++ == 0 ) )
F_69 ( L_29 , V_145 ) ;
F_70 ( V_2 ) ;
F_71 ( & V_5 -> V_8 ) ;
}
static struct V_1 * F_72 ( int V_146 )
{
return F_73 ( sizeof( struct V_4 ) + V_146 , L_30 ,
V_147 , F_68 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_148 )
{
unsigned long V_10 = V_2 -> V_11 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_136 ;
int V_149 = V_5 -> V_150
? ( 0x48 | V_151 | ( V_5 -> V_152 ? V_153 : 0 ) )
: 0x48 ;
if ( sizeof( struct V_91 ) != 4 )
F_74 ( L_31 ) ;
F_20 ( V_49 + V_50 + V_120 , V_10 + V_51 ) ;
F_20 ( V_149 , V_10 + V_154 ) ;
F_20 ( 0x00 , V_10 + V_122 ) ;
F_20 ( 0x00 , V_10 + V_123 ) ;
F_20 ( V_155 , V_10 + V_141 ) ;
F_20 ( V_125 , V_10 + V_126 ) ;
F_20 ( V_5 -> V_34 , V_10 + V_156 ) ;
V_5 -> V_33 = V_5 -> V_35 = 0 ;
F_20 ( V_5 -> V_95 , V_10 + V_157 ) ;
F_20 ( V_5 -> V_94 - 1 , V_10 + V_100 ) ;
V_5 -> V_101 = V_5 -> V_95 ;
F_20 ( V_5 -> V_94 , V_10 + V_158 ) ;
F_20 ( 0xFF , V_10 + V_19 ) ;
F_20 ( 0x00 , V_10 + V_32 ) ;
F_20 ( V_49 + V_98 + V_120 , V_10 + V_51 ) ;
for ( V_136 = 0 ; V_136 < 6 ; V_136 ++ ) {
F_20 ( V_2 -> V_159 [ V_136 ] , V_10 + F_75 ( V_136 ) ) ;
if ( ( F_76 ( V_5 ) ) &&
F_31 ( V_10 + F_75 ( V_136 ) ) != V_2 -> V_159 [ V_136 ] )
F_30 ( V_2 ,
L_32 , V_136 ) ;
}
F_20 ( V_5 -> V_95 , V_10 + V_99 ) ;
F_20 ( V_49 + V_50 + V_120 , V_10 + V_51 ) ;
V_5 -> V_33 = V_5 -> V_35 = 0 ;
V_5 -> V_37 = 0 ;
if ( V_148 ) {
F_20 ( 0xff , V_10 + V_19 ) ;
F_20 ( V_40 , V_10 + V_32 ) ;
F_20 ( V_49 + V_50 + V_67 , V_10 + V_51 ) ;
F_20 ( V_127 , V_10 + V_126 ) ;
F_20 ( V_140 , V_10 + V_141 ) ;
F_63 ( V_2 ) ;
}
}
static void F_26 ( struct V_1 * V_2 , unsigned int V_160 ,
int V_161 )
{
unsigned long V_10 = V_2 -> V_11 ;
struct V_4 * V_5 V_162 ( ( V_163 ) ) = F_2 ( V_2 ) ;
F_20 ( V_49 + V_50 , V_10 + V_51 ) ;
if ( F_31 ( V_10 + V_51 ) & V_119 ) {
F_33 ( V_2 , L_33 ) ;
return;
}
F_20 ( V_160 & 0xff , V_10 + V_164 ) ;
F_20 ( V_160 >> 8 , V_10 + V_165 ) ;
F_20 ( V_161 , V_10 + V_156 ) ;
F_20 ( V_49 + V_119 + V_67 , V_10 + V_51 ) ;
}
