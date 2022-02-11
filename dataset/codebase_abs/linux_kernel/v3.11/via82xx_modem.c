static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int V_7 , unsigned int V_8 )
{
unsigned int V_9 , V_10 , V_11 , V_12 ;
struct V_13 * V_14 = F_2 ( V_4 ) ;
if ( V_2 -> V_15 . V_16 == NULL ) {
if ( F_3 ( V_17 , F_4 ( V_14 -> V_6 ) ,
F_5 ( V_18 * 2 * 8 ) ,
& V_2 -> V_15 ) < 0 )
return - V_19 ;
}
if ( ! V_2 -> V_20 ) {
V_2 -> V_20 = F_6 ( sizeof( * V_2 -> V_20 ) * V_18 , V_21 ) ;
if ( ! V_2 -> V_20 )
return - V_19 ;
}
V_10 = 0 ;
V_11 = 0 ;
for ( V_9 = 0 ; V_9 < V_7 ; V_9 ++ ) {
V_12 = V_8 ;
do {
unsigned int V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
if ( V_10 >= V_18 ) {
F_7 ( V_25 L_1 ) ;
return - V_26 ;
}
V_24 = F_8 ( V_4 , V_11 ) ;
( ( V_27 * ) V_2 -> V_15 . V_16 ) [ V_10 << 1 ] = F_9 ( V_24 ) ;
V_22 = V_28 - ( V_11 % V_28 ) ;
if ( V_12 < V_22 )
V_22 = V_12 ;
V_12 -= V_22 ;
if ( ! V_12 ) {
if ( V_9 == V_7 - 1 )
V_23 = V_29 ;
else
V_23 = V_30 ;
} else
V_23 = 0 ;
( ( V_27 * ) V_2 -> V_15 . V_16 ) [ ( V_10 << 1 ) + 1 ] = F_9 ( V_22 | V_23 ) ;
V_2 -> V_20 [ V_10 ] . V_31 = V_11 ;
V_2 -> V_20 [ V_10 ] . V_32 = V_22 ;
V_11 += V_22 ;
V_10 ++ ;
} while ( V_12 > 0 );
}
V_2 -> V_33 = V_10 ;
V_2 -> V_34 = V_7 * V_8 ;
V_2 -> V_35 = V_2 -> V_34 / 2 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_2 -> V_15 . V_16 ) {
F_11 ( & V_2 -> V_15 ) ;
V_2 -> V_15 . V_16 = NULL ;
}
F_12 ( V_2 -> V_20 ) ;
V_2 -> V_20 = NULL ;
return 0 ;
}
static inline unsigned int F_13 ( struct V_13 * V_14 )
{
return F_14 ( F_15 ( V_14 , V_36 ) ) ;
}
static inline void F_16 ( struct V_13 * V_14 , unsigned int V_37 )
{
F_17 ( V_37 , F_15 ( V_14 , V_36 ) ) ;
}
static int F_18 ( struct V_13 * V_14 , int V_38 )
{
unsigned int V_39 = 1000 ;
unsigned int V_37 ;
while ( V_39 -- > 0 ) {
F_19 ( 1 ) ;
if ( ! ( ( V_37 = F_13 ( V_14 ) ) & V_40 ) )
return V_37 & 0xffff ;
}
F_7 ( V_25 L_2 ,
V_38 , F_13 ( V_14 ) ) ;
return - V_41 ;
}
static int F_20 ( struct V_13 * V_14 , int V_38 )
{
unsigned int V_39 = 1000 ;
unsigned int V_37 , V_42 ;
unsigned int V_43 = ! V_38 ? V_44 :
V_45 ;
while ( V_39 -- > 0 ) {
V_37 = F_13 ( V_14 ) ;
V_42 = V_37 & ( V_40 | V_43 ) ;
if ( V_42 == V_43 )
return V_37 & 0xffff ;
F_19 ( 1 ) ;
}
return - V_41 ;
}
static void F_21 ( struct V_46 * V_47 )
{
struct V_13 * V_14 = V_47 -> V_48 ;
int V_49 ;
V_49 = F_18 ( V_14 , V_47 -> V_50 ) ;
F_22 ( 500 ) ;
}
static void F_23 ( struct V_46 * V_47 ,
unsigned short V_51 ,
unsigned short V_37 )
{
struct V_13 * V_14 = V_47 -> V_48 ;
unsigned int V_52 ;
if( V_51 == V_53 ) {
F_17 ( V_37 , F_15 ( V_14 , V_54 ) ) ;
return;
}
V_52 = ! V_47 -> V_50 ? V_55 : V_56 ;
V_52 <<= V_57 ;
V_52 |= V_51 << V_58 ;
V_52 |= V_37 << V_59 ;
F_16 ( V_14 , V_52 ) ;
F_18 ( V_14 , V_47 -> V_50 ) ;
}
static unsigned short F_24 ( struct V_46 * V_47 , unsigned short V_51 )
{
struct V_13 * V_14 = V_47 -> V_48 ;
unsigned int V_52 , V_37 = 0xffff ;
int V_60 = 0 ;
V_52 = V_47 -> V_50 << V_57 ;
V_52 |= V_47 -> V_50 ? V_45 : V_44 ;
V_52 |= V_61 ;
V_52 |= ( V_51 & 0x7f ) << V_58 ;
while ( 1 ) {
if ( V_60 ++ > 3 ) {
F_7 ( V_25 L_3 ,
V_47 -> V_50 , F_13 ( V_14 ) ) ;
return 0xffff ;
}
F_16 ( V_14 , V_52 ) ;
F_19 ( 20 ) ;
if ( F_20 ( V_14 , V_47 -> V_50 ) >= 0 ) {
F_19 ( 25 ) ;
V_37 = F_13 ( V_14 ) ;
break;
}
}
return V_37 & 0xffff ;
}
static void F_25 ( struct V_13 * V_14 , struct V_1 * V_1 )
{
F_26 ( V_62 | V_63 | V_64 ,
F_27 ( V_1 , V_65 ) ) ;
F_28 ( F_27 ( V_1 , V_65 ) ) ;
F_19 ( 50 ) ;
F_26 ( 0x00 , F_27 ( V_1 , V_65 ) ) ;
F_26 ( 0x03 , F_27 ( V_1 , V_66 ) ) ;
F_26 ( 0x00 , F_27 ( V_1 , V_67 ) ) ;
V_1 -> V_68 = 0 ;
}
static T_1 F_29 ( int V_69 , void * V_70 )
{
struct V_13 * V_14 = V_70 ;
unsigned int V_71 ;
unsigned int V_9 ;
V_71 = F_14 ( F_15 ( V_14 , V_72 ) ) ;
if ( ! ( V_71 & V_14 -> V_73 ) ) {
return V_74 ;
}
F_30 ( & V_14 -> V_75 ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ ) {
struct V_1 * V_1 = & V_14 -> V_77 [ V_9 ] ;
unsigned char V_78 = F_28 ( F_27 ( V_1 , V_66 ) ) ;
V_78 &= ( V_79 | V_80 | V_81 ) ;
if ( ! V_78 )
continue;
if ( V_1 -> V_4 && V_1 -> V_82 ) {
F_31 ( & V_14 -> V_75 ) ;
F_32 ( V_1 -> V_4 ) ;
F_30 ( & V_14 -> V_75 ) ;
}
F_26 ( V_78 , F_27 ( V_1 , V_66 ) ) ;
}
F_31 ( & V_14 -> V_75 ) ;
return V_83 ;
}
static int F_33 ( struct V_3 * V_4 , int V_84 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
unsigned char V_37 = 0 ;
switch ( V_84 ) {
case V_86 :
case V_87 :
V_37 |= V_88 ;
V_1 -> V_82 = 1 ;
break;
case V_89 :
V_37 = V_63 ;
V_1 -> V_82 = 0 ;
break;
case V_90 :
V_37 |= V_62 ;
V_1 -> V_82 = 0 ;
break;
case V_91 :
V_1 -> V_82 = 1 ;
break;
default:
return - V_26 ;
}
F_26 ( V_37 , F_27 ( V_1 , V_65 ) ) ;
if ( V_84 == V_89 )
F_25 ( V_14 , V_1 ) ;
return 0 ;
}
static inline unsigned int F_34 ( struct V_1 * V_1 , unsigned int V_10 ,
unsigned int V_92 )
{
unsigned int V_32 , V_93 ;
V_32 = V_1 -> V_20 [ V_10 ] . V_32 ;
V_93 = V_1 -> V_20 [ V_10 ] . V_31 + V_32 - V_92 ;
if ( V_32 < V_92 ) {
F_35 ( V_25 L_4 ,
( int ) V_32 , ( int ) V_92 ) ;
V_93 = V_1 -> V_68 ;
} else if ( F_36 ( V_1 , V_93 ) ) {
#ifdef F_37
F_38 ( V_94 L_5
L_6
L_7 , V_10 , V_1 -> V_33 , V_1 -> V_68 ,
V_1 -> V_35 , V_1 -> V_20 [ V_10 ] . V_31 ,
V_1 -> V_20 [ V_10 ] . V_32 , V_92 ) ;
#endif
if ( V_92 && V_32 < V_92 ) {
F_35 ( V_25 L_8
L_9 ) ;
V_93 = V_1 -> V_68 ;
} else {
if ( ! V_92 )
V_93 = V_1 -> V_20 [ V_10 ] . V_31 ;
else
V_93 = V_1 -> V_20 [ V_10 ] . V_31 + V_32 ;
if ( F_36 ( V_1 , V_93 ) ) {
F_35 ( V_25 L_10
L_9 ) ;
V_93 = V_1 -> V_68 ;
}
}
}
V_1 -> V_68 = V_93 ;
if ( V_93 >= V_1 -> V_34 )
V_93 -= V_1 -> V_34 ;
return V_93 ;
}
static T_2 F_39 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
unsigned int V_10 , V_95 , V_92 , V_93 ;
if ( F_40 ( ! V_1 -> V_33 ) )
return 0 ;
if ( ! ( F_28 ( F_27 ( V_1 , V_66 ) ) & V_96 ) )
return 0 ;
F_30 ( & V_14 -> V_75 ) ;
V_92 = F_14 ( F_27 ( V_1 , V_97 ) ) & 0xffffff ;
V_95 = F_14 ( F_27 ( V_1 , V_98 ) ) ;
if ( V_95 <= ( unsigned int ) V_1 -> V_15 . V_24 )
V_10 = 0 ;
else
V_10 = ( ( V_95 - ( unsigned int ) V_1 -> V_15 . V_24 ) / 8 - 1 ) %
V_1 -> V_33 ;
V_93 = F_34 ( V_1 , V_10 , V_92 ) ;
F_31 ( & V_14 -> V_75 ) ;
return F_41 ( V_4 -> V_85 , V_93 ) ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_99 * V_100 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
int V_49 ;
V_49 = F_43 ( V_4 , F_44 ( V_100 ) ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_1 ( V_1 , V_4 , V_14 -> V_6 ,
F_45 ( V_100 ) ,
F_46 ( V_100 ) ) ;
if ( V_49 < 0 )
return V_49 ;
F_47 ( V_14 -> V_47 , V_101 , F_48 ( V_100 ) ) ;
F_47 ( V_14 -> V_47 , V_102 , 0 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
F_10 ( V_1 , V_4 , V_14 -> V_6 ) ;
F_50 ( V_4 ) ;
return 0 ;
}
static void F_51 ( struct V_13 * V_14 , struct V_1 * V_1 )
{
F_18 ( V_14 , V_14 -> V_103 ) ;
F_17 ( ( V_27 ) V_1 -> V_15 . V_24 , F_27 ( V_1 , V_104 ) ) ;
F_19 ( 20 ) ;
F_18 ( V_14 , V_14 -> V_103 ) ;
}
static int F_52 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
F_25 ( V_14 , V_1 ) ;
F_51 ( V_14 , V_1 ) ;
F_26 ( V_105 | V_106 | V_107 ,
F_27 ( V_1 , V_67 ) ) ;
return 0 ;
}
static int F_53 ( struct V_13 * V_14 , struct V_1 * V_1 ,
struct V_3 * V_4 )
{
struct V_108 * V_85 = V_4 -> V_85 ;
int V_49 ;
static unsigned int V_109 [] = { 8000 , 9600 , 12000 , 16000 } ;
static struct V_110 V_111 = {
. V_92 = F_54 ( V_109 ) ,
. V_112 = V_109 ,
. V_113 = 0 ,
} ;
V_85 -> V_114 = V_115 ;
if ( ( V_49 = V_110 ( V_85 , 0 , V_116 ,
& V_111 ) ) < 0 )
return V_49 ;
if ( ( V_49 = F_55 ( V_85 , V_117 ) ) < 0 )
return V_49 ;
V_85 -> V_48 = V_1 ;
V_1 -> V_4 = V_4 ;
return 0 ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_118 + V_4 -> V_119 ] ;
return F_53 ( V_14 , V_1 , V_4 ) ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_120 + V_4 -> V_121 -> V_122 ] ;
return F_53 ( V_14 , V_1 , V_4 ) ;
}
static int F_58 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
V_1 -> V_4 = NULL ;
return 0 ;
}
static void F_59 ( struct V_13 * V_14 , int V_10 , unsigned int V_123 ,
int V_124 )
{
V_14 -> V_77 [ V_10 ] . V_123 = V_123 ;
V_14 -> V_77 [ V_10 ] . V_124 = V_124 ;
V_14 -> V_77 [ V_10 ] . V_125 = V_14 -> V_125 + V_123 ;
}
static int F_60 ( struct V_13 * V_14 )
{
struct V_126 * V_121 ;
int V_49 ;
V_14 -> V_118 = 0 ;
V_14 -> V_120 = 1 ;
V_14 -> V_76 = 2 ;
V_14 -> V_73 = 0x330000 ;
V_49 = F_61 ( V_14 -> V_127 , V_14 -> V_127 -> V_128 , 0 , 1 , 1 , & V_121 ) ;
if ( V_49 < 0 )
return V_49 ;
F_62 ( V_121 , V_129 , & V_130 ) ;
F_62 ( V_121 , V_131 , & V_132 ) ;
V_121 -> V_133 = V_134 ;
V_121 -> V_48 = V_14 ;
strcpy ( V_121 -> V_135 , V_14 -> V_127 -> V_128 ) ;
V_14 -> V_136 [ 0 ] = V_121 ;
F_59 ( V_14 , 0 , V_137 , 0 ) ;
F_59 ( V_14 , 1 , V_138 , 1 ) ;
if ( ( V_49 = F_63 ( V_121 , V_139 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , 128 * 1024 ) ) < 0 )
return V_49 ;
return 0 ;
}
static void F_64 ( struct V_140 * V_141 )
{
struct V_13 * V_14 = V_141 -> V_48 ;
V_14 -> V_142 = NULL ;
}
static void F_65 ( struct V_46 * V_47 )
{
struct V_13 * V_14 = V_47 -> V_48 ;
V_14 -> V_47 = NULL ;
}
static int F_66 ( struct V_13 * V_14 )
{
struct V_143 V_47 ;
int V_49 ;
static struct V_144 V_145 = {
. V_146 = F_23 ,
. V_147 = F_24 ,
. V_148 = F_21 ,
} ;
if ( ( V_49 = V_140 ( V_14 -> V_127 , 0 , & V_145 , V_14 , & V_14 -> V_142 ) ) < 0 )
return V_49 ;
V_14 -> V_142 -> V_149 = F_64 ;
V_14 -> V_142 -> clock = V_14 -> V_150 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_48 = V_14 ;
V_47 . V_149 = F_65 ;
V_47 . V_6 = V_14 -> V_6 ;
V_47 . V_151 = V_152 | V_153 ;
V_47 . V_50 = V_14 -> V_103 ;
if ( ( V_49 = F_67 ( V_14 -> V_142 , & V_47 , & V_14 -> V_47 ) ) < 0 )
return V_49 ;
return 0 ;
}
static void F_68 ( struct V_154 * V_155 , struct V_156 * V_157 )
{
struct V_13 * V_14 = V_155 -> V_48 ;
int V_9 ;
F_69 ( V_157 , L_11 , V_14 -> V_127 -> V_158 ) ;
for ( V_9 = 0 ; V_9 < 0xa0 ; V_9 += 4 ) {
F_69 ( V_157 , L_12 , V_9 , F_14 ( V_14 -> V_125 + V_9 ) ) ;
}
}
static void F_70 ( struct V_13 * V_14 )
{
struct V_154 * V_155 ;
if ( ! F_71 ( V_14 -> V_127 , L_13 , & V_155 ) )
F_72 ( V_155 , V_14 , F_68 ) ;
}
static int F_73 ( struct V_13 * V_14 )
{
unsigned int V_37 ;
unsigned long V_159 ;
unsigned char V_160 ;
F_74 ( V_14 -> V_6 , V_161 , & V_160 ) ;
if( ( V_160 & V_162 ) != V_162 ) {
F_75 ( V_14 -> V_6 , 0x44 , V_160 | V_162 ) ;
F_19 ( 100 ) ;
}
F_74 ( V_14 -> V_6 , V_163 , & V_160 ) ;
if ( ! ( V_160 & V_164 ) ) {
F_75 ( V_14 -> V_6 , V_165 ,
V_166 |
V_167 |
V_168 ) ;
F_19 ( 100 ) ;
#if 1
F_75 ( V_14 -> V_6 , V_165 , 0x00 ) ;
F_19 ( 100 ) ;
#else
F_75 ( V_14 -> V_6 , V_165 ,
V_167 | V_168 ) ;
F_19 ( 2 ) ;
#endif
F_75 ( V_14 -> V_6 , V_165 , V_169 ) ;
F_19 ( 100 ) ;
}
F_74 ( V_14 -> V_6 , V_165 , & V_160 ) ;
if ( ( V_160 & V_169 ) != V_169 ) {
F_75 ( V_14 -> V_6 , V_165 , V_169 ) ;
F_19 ( 100 ) ;
}
V_159 = V_170 + F_76 ( 750 ) ;
do {
F_74 ( V_14 -> V_6 , V_163 , & V_160 ) ;
if ( V_160 & V_164 )
break;
F_77 ( 1 ) ;
} while ( F_78 ( V_170 , V_159 ) );
if ( ( V_37 = F_13 ( V_14 ) ) & V_40 )
F_7 ( V_25 L_14 , V_37 ) ;
F_16 ( V_14 , V_61 |
V_45 |
( V_56 << V_57 ) ) ;
V_159 = V_170 + F_76 ( 750 ) ;
F_16 ( V_14 , V_61 |
V_45 |
( V_56 << V_57 ) ) ;
do {
if ( ( V_37 = F_13 ( V_14 ) ) & V_45 ) {
V_14 -> V_103 = 1 ;
goto V_171;
}
F_77 ( 1 ) ;
} while ( F_78 ( V_170 , V_159 ) );
V_171:
F_17 ( 0 , F_15 ( V_14 , V_172 ) ) ;
return 0 ;
}
static int F_79 ( struct V_122 * V_2 )
{
struct V_5 * V_6 = F_80 ( V_2 ) ;
struct V_173 * V_127 = F_81 ( V_2 ) ;
struct V_13 * V_14 = V_127 -> V_48 ;
int V_9 ;
F_82 ( V_127 , V_174 ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ )
F_83 ( V_14 -> V_136 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_84 ( V_14 -> V_69 ) ;
F_85 ( V_14 -> V_47 ) ;
F_86 ( V_6 ) ;
F_87 ( V_6 ) ;
F_88 ( V_6 , V_175 ) ;
return 0 ;
}
static int F_89 ( struct V_122 * V_2 )
{
struct V_5 * V_6 = F_80 ( V_2 ) ;
struct V_173 * V_127 = F_81 ( V_2 ) ;
struct V_13 * V_14 = V_127 -> V_48 ;
int V_9 ;
F_88 ( V_6 , V_176 ) ;
F_90 ( V_6 ) ;
if ( F_91 ( V_6 ) < 0 ) {
F_38 ( V_25 L_15
L_16 ) ;
F_92 ( V_127 ) ;
return - V_41 ;
}
F_93 ( V_6 ) ;
F_73 ( V_14 ) ;
F_94 ( V_14 -> V_47 ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_82 ( V_127 , V_177 ) ;
return 0 ;
}
static int F_95 ( struct V_13 * V_14 )
{
unsigned int V_9 ;
if ( V_14 -> V_69 < 0 )
goto V_178;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
V_178:
if ( V_14 -> V_69 >= 0 )
F_96 ( V_14 -> V_69 , V_14 ) ;
F_97 ( V_14 -> V_6 ) ;
F_86 ( V_14 -> V_6 ) ;
F_12 ( V_14 ) ;
return 0 ;
}
static int F_98 ( struct V_179 * V_122 )
{
struct V_13 * V_14 = V_122 -> V_180 ;
return F_95 ( V_14 ) ;
}
static int F_99 ( struct V_173 * V_127 ,
struct V_5 * V_6 ,
int V_181 ,
int V_182 ,
unsigned int V_150 ,
struct V_13 * * V_183 )
{
struct V_13 * V_14 ;
int V_49 ;
static struct V_184 V_145 = {
. V_185 = F_98 ,
} ;
if ( ( V_49 = F_91 ( V_6 ) ) < 0 )
return V_49 ;
if ( ( V_14 = F_100 ( sizeof( * V_14 ) , V_21 ) ) == NULL ) {
F_86 ( V_6 ) ;
return - V_19 ;
}
F_101 ( & V_14 -> V_75 ) ;
V_14 -> V_127 = V_127 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_69 = - 1 ;
if ( ( V_49 = F_102 ( V_6 , V_127 -> V_186 ) ) < 0 ) {
F_12 ( V_14 ) ;
F_86 ( V_6 ) ;
return V_49 ;
}
V_14 -> V_125 = F_103 ( V_6 , 0 ) ;
if ( F_104 ( V_6 -> V_69 , F_29 , V_187 ,
V_188 , V_14 ) ) {
F_7 ( V_25 L_17 , V_6 -> V_69 ) ;
F_95 ( V_14 ) ;
return - V_189 ;
}
V_14 -> V_69 = V_6 -> V_69 ;
if ( V_150 >= 8000 && V_150 <= 48000 )
V_14 -> V_150 = V_150 ;
F_84 ( V_14 -> V_69 ) ;
if ( ( V_49 = F_73 ( V_14 ) ) < 0 ) {
F_95 ( V_14 ) ;
return V_49 ;
}
if ( ( V_49 = F_105 ( V_127 , V_190 , V_14 , & V_145 ) ) < 0 ) {
F_95 ( V_14 ) ;
return V_49 ;
}
F_93 ( V_6 ) ;
F_106 ( V_127 , & V_6 -> V_2 ) ;
* V_183 = V_14 ;
return 0 ;
}
static int F_107 ( struct V_5 * V_6 ,
const struct V_191 * V_192 )
{
struct V_173 * V_127 ;
struct V_13 * V_14 ;
int V_181 = 0 , V_193 ;
unsigned int V_9 ;
int V_49 ;
V_49 = F_108 ( V_194 , V_195 , V_196 , 0 , & V_127 ) ;
if ( V_49 < 0 )
return V_49 ;
V_193 = V_192 -> V_197 ;
switch ( V_193 ) {
case V_198 :
strcpy ( V_127 -> V_186 , L_18 ) ;
sprintf ( V_127 -> V_128 , L_19 ) ;
break;
default:
F_7 ( V_25 L_20 , V_193 ) ;
V_49 = - V_26 ;
goto V_199;
}
if ( ( V_49 = F_99 ( V_127 , V_6 , V_181 , V_6 -> V_182 ,
V_150 , & V_14 ) ) < 0 )
goto V_199;
V_127 -> V_48 = V_14 ;
if ( ( V_49 = F_66 ( V_14 ) ) < 0 )
goto V_199;
if ( ( V_49 = F_60 ( V_14 ) ) < 0 )
goto V_199;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
sprintf ( V_127 -> V_158 , L_21 ,
V_127 -> V_128 , V_14 -> V_125 , V_14 -> V_69 ) ;
F_70 ( V_14 ) ;
if ( ( V_49 = F_109 ( V_127 ) ) < 0 ) {
F_110 ( V_127 ) ;
return V_49 ;
}
F_111 ( V_6 , V_127 ) ;
return 0 ;
V_199:
F_110 ( V_127 ) ;
return V_49 ;
}
static void F_112 ( struct V_5 * V_6 )
{
F_110 ( F_113 ( V_6 ) ) ;
}
