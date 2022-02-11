static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
void T_1 * V_6 = V_2 -> V_7 + V_3 ;
unsigned int V_8 , V_9 ;
V_9 = V_8 = F_2 ( V_6 ) ;
V_8 &= ~ V_4 ;
V_8 |= V_5 ;
if ( V_9 == V_8 )
return 0 ;
F_3 ( V_8 , V_6 ) ;
return 1 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int V_14 ,
unsigned int V_15 )
{
unsigned int V_16 ;
T_2 V_6 , V_17 ;
unsigned long V_18 ;
if ( V_14 > V_19 )
return - V_20 ;
if ( V_11 -> V_21 . V_22 == NULL ) {
if ( F_5 ( V_23 , F_6 ( V_2 -> V_24 ) ,
V_25 , & V_11 -> V_21 ) < 0 )
return - V_20 ;
V_11 -> V_15 = V_11 -> V_14 = 0 ;
}
if ( V_11 -> V_14 == V_14 && V_11 -> V_15 == V_15 )
return 0 ;
F_7 ( & V_2 -> V_26 , V_18 ) ;
F_3 ( 0 , V_2 -> V_7 + V_11 -> V_27 -> V_28 ) ;
V_11 -> V_27 -> V_29 ( V_2 , 0 ) ;
V_11 -> V_27 -> V_29 ( V_2 , 1 ) ;
F_8 ( & V_2 -> V_26 , V_18 ) ;
V_6 = ( T_2 ) V_13 -> V_30 -> V_31 ;
V_17 = ( T_2 ) V_11 -> V_21 . V_6 ;
for ( V_16 = 0 ; V_16 < V_14 ; V_16 ++ ) {
struct V_32 * V_33 ;
V_33 = & ( (struct V_32 * ) V_11 -> V_21 . V_22 ) [ V_16 ] ;
V_33 -> V_6 = F_9 ( V_6 ) ;
V_33 -> V_34 = 0 ;
V_33 -> V_35 = V_15 >> 2 ;
V_17 += sizeof( struct V_32 ) ;
if ( V_16 == V_14 - 1 )
V_33 -> V_36 = F_9 ( ( T_2 ) V_11 -> V_21 . V_6 ) ;
else
V_33 -> V_36 = F_9 ( V_17 ) ;
V_6 += V_15 ;
}
F_3 ( ( T_2 ) V_11 -> V_21 . V_6 | V_37 ,
V_2 -> V_7 + V_11 -> V_27 -> V_28 ) ;
V_11 -> V_15 = V_15 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
if ( V_11 -> V_21 . V_22 ) {
F_3 ( 0 , V_2 -> V_7 + V_11 -> V_27 -> V_28 ) ;
F_11 ( & V_11 -> V_21 ) ;
V_11 -> V_21 . V_22 = NULL ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
int V_38 = 1000 ;
while ( F_13 ( V_2 , V_39 ) & V_40 ) {
if ( ! V_38 -- ) {
F_14 ( V_41 L_1 ) ;
return - V_42 ;
}
F_15 ( 1 ) ;
}
return 0 ;
}
static unsigned short F_16 ( struct V_1 * V_2 ,
unsigned short V_43 ,
unsigned short V_3 )
{
unsigned int V_8 ;
int V_38 ;
if ( F_12 ( V_2 ) < 0 )
return 0xffff ;
V_8 = ( V_3 << V_44 ) |
V_40 |
V_45 |
V_43 ;
F_17 ( V_2 , V_39 , V_8 ) ;
if ( F_12 ( V_2 ) < 0 )
return 0xffff ;
V_38 = 1000 ;
do {
V_8 = F_13 ( V_2 , V_46 ) ;
if ( V_8 & V_47 )
return V_8 >> V_48 ;
F_15 ( 1 ) ;
} while ( -- V_38 );
if ( V_3 < 0x7c )
F_14 ( V_41 L_2 , V_3 ) ;
return 0xffff ;
}
static void F_18 ( struct V_1 * V_2 ,
unsigned short V_43 ,
unsigned short V_3 , unsigned short V_49 )
{
unsigned int V_8 ;
if ( F_12 ( V_2 ) < 0 )
return;
V_8 = ( ( unsigned int ) V_49 << V_50 ) |
( ( unsigned int ) V_3 << V_44 ) |
V_40 | V_43 ;
F_17 ( V_2 , V_39 , V_8 ) ;
}
static unsigned short F_19 ( struct V_51 * V_52 ,
unsigned short V_3 )
{
struct V_1 * V_2 = V_52 -> V_53 ;
return F_16 ( V_2 , V_52 -> V_54 , V_3 ) ;
}
static void F_20 ( struct V_51 * V_52 , unsigned short V_3 ,
unsigned short V_49 )
{
struct V_1 * V_2 = V_52 -> V_53 ;
if ( V_3 == V_55 ) {
F_17 ( V_2 , V_56 ,
( V_49 << V_57 ) | V_58 ) ;
return;
}
F_18 ( V_2 , V_52 -> V_54 , V_3 , V_49 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_38 ;
if ( F_22 ( V_2 , V_59 , V_60 , 0 ) )
F_15 ( 10 ) ;
F_22 ( V_2 , V_59 , V_61 , V_61 ) ;
F_13 ( V_2 , V_59 ) ;
F_15 ( 10 ) ;
F_22 ( V_2 , V_59 , V_61 , 0 ) ;
V_38 = 10 ;
while ( ! ( F_13 ( V_2 , V_59 ) & V_62 ) ) {
F_22 ( V_2 , V_59 , V_63 | V_64 ,
V_63 ) ;
F_13 ( V_2 , V_59 ) ;
F_23 ( 1 ) ;
F_22 ( V_2 , V_59 , V_64 , V_64 ) ;
if ( ! -- V_38 ) {
F_14 ( V_65 L_3 ) ;
break;
}
}
F_22 ( V_2 , V_59 , V_63 | V_64 ,
V_63 | V_64 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_59 ,
V_60 | V_64 ,
V_60 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_38 ;
V_2 -> V_66 = 0 ;
F_17 ( V_2 , V_67 , V_68 ) ;
V_38 = 50 ;
while ( V_38 -- > 0 ) {
F_23 ( 1 ) ;
if ( V_2 -> V_66 )
break;
}
F_17 ( V_2 , V_67 , 0 ) ;
if ( ( V_2 -> V_66 & V_69 ) == V_69 ) {
F_14 ( V_65 L_4 ) ;
return - V_70 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_13 ( V_2 , V_59 ) ;
V_3 |= V_71 ;
if( ! ( V_3 & V_72 ) )
V_3 |= V_72 ;
F_17 ( V_2 , V_59 , V_3 ) ;
F_17 ( V_2 , V_73 , 0xffffffff ) ;
F_17 ( V_2 , V_67 ,
V_74 |
V_75 |
V_76 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_73 , F_13 ( V_2 , V_73 ) ) ;
F_17 ( V_2 , V_67 , 0 ) ;
return 0 ;
}
static T_3 F_28 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
struct V_77 * V_30 = V_13 -> V_30 ;
struct V_10 * V_11 = V_30 -> V_53 ;
unsigned int V_78 ;
int V_38 = 1000 ;
while ( V_38 -- ) {
V_78 = F_2 ( V_2 -> V_7 + V_11 -> V_27 -> V_79 ) ;
if ( V_78 < V_11 -> V_80 )
continue;
V_78 -= V_11 -> V_80 ;
if ( V_78 >= V_11 -> V_81 )
continue;
return F_30 ( V_30 , V_78 ) ;
}
F_31 ( L_5 ,
F_2 ( V_2 -> V_7 + V_11 -> V_27 -> V_79 ) , V_11 -> V_80 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( ! V_11 -> V_13 || ! V_11 -> V_82 )
return;
F_33 ( L_6 , V_11 -> V_27 -> type ) ;
F_34 ( V_11 -> V_13 , V_83 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
if ( ! V_11 -> V_13 || ! V_11 -> V_82 )
return;
F_36 ( V_11 -> V_13 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
unsigned int V_84 ;
if ( F_13 ( V_2 , V_59 ) & ( V_85 |
V_86 ) )
V_84 = V_87 ;
else
V_84 = 0 ;
F_22 ( V_2 , V_67 , V_87 , V_84 ) ;
}
static int F_38 ( struct V_12 * V_13 , int V_88 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
struct V_10 * V_11 = V_13 -> V_30 -> V_53 ;
int V_89 = 0 ;
if ( F_39 ( ! V_11 -> V_27 -> V_90 ||
! V_11 -> V_27 -> V_91 ) )
return - V_92 ;
F_40 ( & V_2 -> V_26 ) ;
switch( V_88 ) {
case V_93 :
V_11 -> V_27 -> V_90 ( V_2 , 1 ) ;
V_11 -> V_82 = 1 ;
break;
case V_94 :
V_11 -> V_27 -> V_90 ( V_2 , 0 ) ;
V_11 -> V_82 = 0 ;
break;
default:
V_89 = - V_92 ;
break;
}
if ( ! V_89 ) {
F_37 ( V_2 ) ;
if ( V_88 == V_94 ) {
V_11 -> V_27 -> V_91 ( V_2 ) ;
F_37 ( V_2 ) ;
}
}
F_41 ( & V_2 -> V_26 ) ;
return V_89 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_95 , V_96 ) ;
}
static void F_43 ( struct V_1 * V_2 , int V_97 )
{
unsigned int V_8 ;
V_8 = F_13 ( V_2 , V_59 ) ;
if ( V_97 ) {
if ( V_8 & V_98 )
return;
F_42 ( V_2 ) ;
V_8 |= V_98 ;
} else
V_8 &= ~ V_98 ;
F_17 ( V_2 , V_59 , V_8 ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_97 )
{
F_22 ( V_2 , V_59 , V_85 ,
V_97 ? V_85 : 0 ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_97 )
{
F_22 ( V_2 , V_59 , V_99 ,
V_97 ? V_99 : 0 ) ;
}
static void F_46 ( struct V_1 * V_2 , int V_97 )
{
if ( V_97 ) {
unsigned int V_8 = F_13 ( V_2 , V_59 ) ;
if ( ! ( V_8 & V_86 ) ) {
V_8 |= V_86 ;
F_17 ( V_2 , V_59 , V_8 ) ;
}
} else
F_22 ( V_2 , V_59 , V_86 , 0 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_95 , V_100 ) ;
}
static int F_48 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
unsigned int V_8 ;
F_49 ( & V_2 -> V_26 ) ;
V_8 = F_13 ( V_2 , V_101 ) ;
V_8 &= ~ V_102 ;
V_8 |= 0x04 << V_103 ;
F_17 ( V_2 , V_101 , V_8 ) ;
F_50 ( & V_2 -> V_26 ) ;
return 0 ;
}
static int F_51 ( struct V_12 * V_13 )
{
return 0 ;
}
static int F_52 ( struct V_12 * V_13 ,
struct V_104 * V_105 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
struct V_10 * V_11 = V_13 -> V_30 -> V_53 ;
int V_89 ;
int V_16 ;
V_89 = F_53 ( V_13 , F_54 ( V_105 ) ) ;
if ( V_89 < 0 )
return V_89 ;
V_11 -> V_80 = V_13 -> V_30 -> V_31 ;
V_11 -> V_81 = F_54 ( V_105 ) ;
V_89 = F_4 ( V_2 , V_11 , V_13 ,
F_55 ( V_105 ) ,
F_56 ( V_105 ) ) ;
if ( V_89 < 0 )
return V_89 ;
for ( V_16 = 0 ; V_16 < V_106 ; V_16 ++ ) {
if ( ! V_2 -> V_52 [ V_16 ] )
continue;
F_57 ( V_2 -> V_52 [ V_16 ] , V_107 , F_58 ( V_105 ) ) ;
F_57 ( V_2 -> V_52 [ V_16 ] , V_108 , 0 ) ;
}
return V_89 ;
}
static int F_59 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
struct V_10 * V_11 = V_13 -> V_30 -> V_53 ;
F_10 ( V_2 , V_11 , V_13 ) ;
F_60 ( V_13 ) ;
return 0 ;
}
static int F_61 ( struct V_12 * V_13 ,
struct V_10 * V_11 , int V_109 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
struct V_77 * V_30 = V_13 -> V_30 ;
int V_89 ;
static unsigned int V_110 [] = { 8000 , 9600 , 12000 , 16000 } ;
static struct V_111 V_112 = {
. V_113 = F_62 ( V_110 ) ,
. V_114 = V_110 ,
. V_4 = 0 ,
} ;
if ( F_39 ( ! V_11 -> V_27 || ! V_11 -> V_27 -> V_29 ) )
return - V_92 ;
if ( V_11 -> V_115 )
return - V_42 ;
V_11 -> V_13 = V_13 ;
V_30 -> V_116 = V_117 ;
V_11 -> V_118 = V_109 ;
if ( ( V_89 = V_111 ( V_30 , 0 ,
V_119 ,
& V_112 ) ) < 0 )
return V_89 ;
if ( ( V_89 = F_63 ( V_30 ,
V_120 ) ) < 0 )
return V_89 ;
V_30 -> V_53 = V_11 ;
F_49 ( & V_2 -> V_26 ) ;
V_11 -> V_27 -> V_29 ( V_2 , 1 ) ;
F_50 ( & V_2 -> V_26 ) ;
V_11 -> V_115 = 1 ;
return 0 ;
}
static int F_64 ( struct V_12 * V_13 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
if ( F_39 ( ! V_11 -> V_27 || ! V_11 -> V_27 -> V_29 ) )
return - V_92 ;
F_49 ( & V_2 -> V_26 ) ;
V_11 -> V_27 -> V_29 ( V_2 , 0 ) ;
F_50 ( & V_2 -> V_26 ) ;
V_11 -> V_13 = NULL ;
V_11 -> V_115 = 0 ;
return 0 ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
int V_89 ;
F_66 ( & V_2 -> V_121 ) ;
V_89 = F_61 ( V_13 , & V_2 -> V_122 [ V_123 ] , 0 ) ;
F_67 ( & V_2 -> V_121 ) ;
if ( V_89 < 0 )
return V_89 ;
return 0 ;
}
static int F_68 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
int V_89 ;
F_66 ( & V_2 -> V_121 ) ;
V_89 = F_64 ( V_13 , & V_2 -> V_122 [ V_123 ] ) ;
F_67 ( & V_2 -> V_121 ) ;
return V_89 ;
}
static int F_69 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
return F_61 ( V_13 , & V_2 -> V_122 [ V_124 ] , 1 ) ;
}
static int F_70 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_29 ( V_13 ) ;
return F_64 ( V_13 , & V_2 -> V_122 [ V_124 ] ) ;
}
static int T_4 F_71 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
int V_89 ;
V_2 -> V_122 [ V_123 ] . V_27 = & V_127 ;
V_2 -> V_122 [ V_124 ] . V_27 = & V_128 ;
V_89 = F_72 ( V_2 -> V_129 , L_7 , V_130 , 1 , 1 , & V_126 ) ;
if ( V_89 < 0 )
return V_89 ;
F_73 ( V_126 , V_131 , & V_132 ) ;
F_73 ( V_126 , V_133 , & V_134 ) ;
V_126 -> V_135 = V_136 ;
V_126 -> V_53 = V_2 ;
strcpy ( V_126 -> V_137 , L_7 ) ;
V_2 -> V_138 [ V_130 ] = V_126 ;
F_74 ( V_126 , V_23 ,
F_6 ( V_2 -> V_24 ) ,
64 * 1024 , 128 * 1024 ) ;
return 0 ;
}
static T_5 F_75 ( int V_139 , void * V_140 )
{
struct V_1 * V_2 = V_140 ;
unsigned int V_34 ;
V_34 = F_13 ( V_2 , V_73 ) ;
if ( ! V_34 )
return V_141 ;
if ( V_34 & V_142 )
F_32 ( V_2 , & V_2 -> V_122 [ V_123 ] ) ;
else if ( V_34 & V_143 )
F_35 ( V_2 , & V_2 -> V_122 [ V_123 ] ) ;
if ( V_34 & V_144 )
F_32 ( V_2 , & V_2 -> V_122 [ V_124 ] ) ;
else if ( V_34 & V_145 )
F_35 ( V_2 , & V_2 -> V_122 [ V_124 ] ) ;
if ( V_34 & V_68 ) {
unsigned int V_146 ;
V_146 = V_34 & V_68 ;
F_40 ( & V_2 -> V_26 ) ;
V_2 -> V_66 |= V_146 ;
F_22 ( V_2 , V_67 , V_146 , 0 ) ;
F_41 ( & V_2 -> V_26 ) ;
}
F_17 ( V_2 , V_73 , V_34 ) ;
return V_147 ;
}
static int T_4 F_76 ( struct V_1 * V_2 , int clock )
{
struct V_148 * V_149 ;
struct V_150 V_52 ;
int V_16 , V_89 ;
int V_151 ;
static struct V_152 V_27 = {
. V_153 = F_20 ,
. V_154 = F_19 ,
} ;
static unsigned int V_155 [ V_106 ] = {
V_156 ,
V_157 ,
V_158 ,
} ;
if ( F_25 ( V_2 ) < 0 )
return - V_70 ;
if ( ( V_89 = V_148 ( V_2 -> V_129 , 0 , & V_27 , V_2 , & V_149 ) ) < 0 )
return V_89 ;
V_149 -> clock = clock ;
V_2 -> V_159 = V_149 ;
V_151 = 0 ;
for ( V_16 = 0 ; V_16 < V_106 ; V_16 ++ ) {
if ( V_2 -> V_66 & V_155 [ V_16 ] )
continue;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_53 = V_2 ;
V_52 . V_24 = V_2 -> V_24 ;
V_52 . V_54 = V_16 ;
V_52 . V_160 = V_161 | V_162 ;
if ( ( V_89 = F_77 ( V_149 , & V_52 , & V_2 -> V_52 [ V_16 ] ) ) < 0 ) {
V_2 -> V_52 [ V_16 ] = NULL ;
F_33 ( L_8 , V_16 ) ;
continue;
}
V_151 ++ ;
}
if ( ! V_151 ) {
F_14 ( V_65 L_9 ) ;
return - V_163 ;
}
return 0 ;
}
static int F_78 ( struct V_164 * V_24 , T_6 V_165 )
{
struct V_166 * V_129 = F_79 ( V_24 ) ;
struct V_1 * V_2 = V_129 -> V_53 ;
int V_16 ;
F_80 ( V_129 , V_167 ) ;
for ( V_16 = 0 ; V_16 < V_168 ; V_16 ++ )
F_81 ( V_2 -> V_138 [ V_16 ] ) ;
for ( V_16 = 0 ; V_16 < V_106 ; V_16 ++ )
F_82 ( V_2 -> V_52 [ V_16 ] ) ;
F_24 ( V_2 ) ;
F_27 ( V_2 ) ;
F_83 ( V_24 ) ;
F_84 ( V_24 ) ;
F_85 ( V_24 , F_86 ( V_24 , V_165 ) ) ;
return 0 ;
}
static int F_87 ( struct V_164 * V_24 )
{
struct V_166 * V_129 = F_79 ( V_24 ) ;
struct V_1 * V_2 = V_129 -> V_53 ;
int V_16 ;
F_85 ( V_24 , V_169 ) ;
F_88 ( V_24 ) ;
if ( F_89 ( V_24 ) < 0 ) {
F_90 ( V_65 L_10
L_11 ) ;
F_91 ( V_129 ) ;
return - V_170 ;
}
F_92 ( V_24 ) ;
F_21 ( V_2 ) ;
F_26 ( V_2 ) ;
for ( V_16 = 0 ; V_16 < V_106 ; V_16 ++ )
F_93 ( V_2 -> V_52 [ V_16 ] ) ;
F_80 ( V_129 , V_171 ) ;
return 0 ;
}
static void F_94 ( struct V_172 * V_173 ,
struct V_174 * V_175 )
{
struct V_1 * V_2 = V_173 -> V_53 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 256 ; V_16 += 4 )
F_95 ( V_175 , L_12 , V_16 , F_2 ( V_2 -> V_7 + V_16 ) ) ;
}
static void T_4 F_96 ( struct V_1 * V_2 )
{
struct V_172 * V_173 ;
if ( ! F_97 ( V_2 -> V_129 , L_13 , & V_173 ) )
F_98 ( V_173 , V_2 , F_94 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_139 < 0 )
goto V_176;
F_27 ( V_2 ) ;
V_176:
if ( V_2 -> V_139 >= 0 )
F_100 ( V_2 -> V_139 , V_2 ) ;
if ( V_2 -> V_7 )
F_101 ( V_2 -> V_7 ) ;
F_102 ( V_2 -> V_24 ) ;
F_83 ( V_2 -> V_24 ) ;
F_103 ( V_2 ) ;
return 0 ;
}
static int F_104 ( struct V_177 * V_178 )
{
struct V_1 * V_2 = V_178 -> V_179 ;
return F_99 ( V_2 ) ;
}
static int T_4 F_105 ( struct V_166 * V_129 ,
struct V_164 * V_24 ,
struct V_1 * * V_180 )
{
static struct V_181 V_27 = {
. V_182 = F_104 ,
} ;
struct V_1 * V_2 ;
int V_89 ;
if ( ( V_89 = F_89 ( V_24 ) ) < 0 )
return V_89 ;
V_2 = F_106 ( sizeof( * V_2 ) , V_183 ) ;
if ( V_2 == NULL ) {
F_83 ( V_24 ) ;
return - V_20 ;
}
F_107 ( & V_2 -> V_26 ) ;
F_108 ( & V_2 -> V_121 ) ;
V_2 -> V_129 = V_129 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_139 = - 1 ;
if ( ( V_89 = F_109 ( V_24 , L_7 ) ) < 0 ) {
F_103 ( V_2 ) ;
F_83 ( V_24 ) ;
return V_89 ;
}
V_2 -> V_6 = F_110 ( V_24 , 0 ) ;
V_2 -> V_7 = F_111 ( V_24 , 0 ) ;
if ( V_2 -> V_7 == NULL ) {
F_14 ( V_65 L_14 ) ;
F_99 ( V_2 ) ;
return - V_170 ;
}
if ( F_112 ( V_24 -> V_139 , F_75 , V_184 ,
V_185 , V_2 ) ) {
F_14 ( V_65 L_15 , V_24 -> V_139 ) ;
F_99 ( V_2 ) ;
return - V_42 ;
}
V_2 -> V_139 = V_24 -> V_139 ;
F_92 ( V_24 ) ;
F_113 ( V_2 -> V_139 ) ;
if ( ( V_89 = F_114 ( V_129 , V_186 , V_2 , & V_27 ) ) < 0 ) {
F_99 ( V_2 ) ;
return V_89 ;
}
F_115 ( V_129 , & V_24 -> V_187 ) ;
* V_180 = V_2 ;
return 0 ;
}
static int T_4 F_116 ( struct V_164 * V_24 ,
const struct V_188 * V_189 )
{
struct V_166 * V_129 ;
struct V_1 * V_2 ;
int V_89 ;
V_89 = F_117 ( V_190 , V_191 , V_192 , 0 , & V_129 ) ;
if ( V_89 < 0 )
return V_89 ;
strcpy ( V_129 -> V_193 , L_16 ) ;
strcpy ( V_129 -> V_194 , L_17 ) ;
if ( ( V_89 = F_105 ( V_129 , V_24 , & V_2 ) ) < 0 )
goto V_195;
V_129 -> V_53 = V_2 ;
if ( ( V_89 = F_21 ( V_2 ) ) < 0 )
goto V_195;
if ( ( V_89 = F_76 ( V_2 , V_196 ) ) < 0 )
goto V_195;
if ( ( V_89 = F_71 ( V_2 ) ) < 0 )
goto V_195;
F_96 ( V_2 ) ;
F_26 ( V_2 ) ;
sprintf ( V_129 -> V_197 , L_18 ,
V_129 -> V_194 , V_24 -> V_198 , V_2 -> V_6 , V_2 -> V_139 ) ;
if ( ( V_89 = F_118 ( V_129 ) ) < 0 )
goto V_195;
F_119 ( V_24 , V_129 ) ;
return 0 ;
V_195:
F_120 ( V_129 ) ;
return V_89 ;
}
static void T_7 F_121 ( struct V_164 * V_24 )
{
F_120 ( F_79 ( V_24 ) ) ;
F_119 ( V_24 , NULL ) ;
}
static int T_8 F_122 ( void )
{
return F_123 ( & V_193 ) ;
}
static void T_9 F_124 ( void )
{
F_125 ( & V_193 ) ;
}
