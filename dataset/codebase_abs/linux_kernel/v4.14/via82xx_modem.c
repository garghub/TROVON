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
F_7 ( & V_6 -> V_2 , L_1 ) ;
return - V_25 ;
}
V_24 = F_8 ( V_4 , V_11 ) ;
( ( V_26 * ) V_2 -> V_15 . V_16 ) [ V_10 << 1 ] = F_9 ( V_24 ) ;
V_22 = V_27 - ( V_11 % V_27 ) ;
if ( V_12 < V_22 )
V_22 = V_12 ;
V_12 -= V_22 ;
if ( ! V_12 ) {
if ( V_9 == V_7 - 1 )
V_23 = V_28 ;
else
V_23 = V_29 ;
} else
V_23 = 0 ;
( ( V_26 * ) V_2 -> V_15 . V_16 ) [ ( V_10 << 1 ) + 1 ] = F_9 ( V_22 | V_23 ) ;
V_2 -> V_20 [ V_10 ] . V_30 = V_11 ;
V_2 -> V_20 [ V_10 ] . V_31 = V_22 ;
V_11 += V_22 ;
V_10 ++ ;
} while ( V_12 > 0 );
}
V_2 -> V_32 = V_10 ;
V_2 -> V_33 = V_7 * V_8 ;
V_2 -> V_34 = V_2 -> V_33 / 2 ;
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
return F_14 ( F_15 ( V_14 , V_35 ) ) ;
}
static inline void F_16 ( struct V_13 * V_14 , unsigned int V_36 )
{
F_17 ( V_36 , F_15 ( V_14 , V_35 ) ) ;
}
static int F_18 ( struct V_13 * V_14 , int V_37 )
{
unsigned int V_38 = 1000 ;
unsigned int V_36 ;
while ( V_38 -- > 0 ) {
F_19 ( 1 ) ;
if ( ! ( ( V_36 = F_13 ( V_14 ) ) & V_39 ) )
return V_36 & 0xffff ;
}
F_7 ( V_14 -> V_40 -> V_2 , L_2 ,
V_37 , F_13 ( V_14 ) ) ;
return - V_41 ;
}
static int F_20 ( struct V_13 * V_14 , int V_37 )
{
unsigned int V_38 = 1000 ;
unsigned int V_36 , V_42 ;
unsigned int V_43 = ! V_37 ? V_44 :
V_45 ;
while ( V_38 -- > 0 ) {
V_36 = F_13 ( V_14 ) ;
V_42 = V_36 & ( V_39 | V_43 ) ;
if ( V_42 == V_43 )
return V_36 & 0xffff ;
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
unsigned short V_36 )
{
struct V_13 * V_14 = V_47 -> V_48 ;
unsigned int V_52 ;
if( V_51 == V_53 ) {
F_17 ( V_36 , F_15 ( V_14 , V_54 ) ) ;
return;
}
V_52 = ! V_47 -> V_50 ? V_55 : V_56 ;
V_52 <<= V_57 ;
V_52 |= V_51 << V_58 ;
V_52 |= V_36 << V_59 ;
F_16 ( V_14 , V_52 ) ;
F_18 ( V_14 , V_47 -> V_50 ) ;
}
static unsigned short F_24 ( struct V_46 * V_47 , unsigned short V_51 )
{
struct V_13 * V_14 = V_47 -> V_48 ;
unsigned int V_52 , V_36 = 0xffff ;
int V_60 = 0 ;
V_52 = V_47 -> V_50 << V_57 ;
V_52 |= V_47 -> V_50 ? V_45 : V_44 ;
V_52 |= V_61 ;
V_52 |= ( V_51 & 0x7f ) << V_58 ;
while ( 1 ) {
if ( V_60 ++ > 3 ) {
F_7 ( V_14 -> V_40 -> V_2 ,
L_3 ,
V_47 -> V_50 , F_13 ( V_14 ) ) ;
return 0xffff ;
}
F_16 ( V_14 , V_52 ) ;
F_19 ( 20 ) ;
if ( F_20 ( V_14 , V_47 -> V_50 ) >= 0 ) {
F_19 ( 25 ) ;
V_36 = F_13 ( V_14 ) ;
break;
}
}
return V_36 & 0xffff ;
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
unsigned char V_36 = 0 ;
switch ( V_84 ) {
case V_86 :
case V_87 :
V_36 |= V_88 ;
V_1 -> V_82 = 1 ;
break;
case V_89 :
V_36 = V_63 ;
V_1 -> V_82 = 0 ;
break;
case V_90 :
V_36 |= V_62 ;
V_1 -> V_82 = 0 ;
break;
case V_91 :
V_1 -> V_82 = 1 ;
break;
default:
return - V_25 ;
}
F_26 ( V_36 , F_27 ( V_1 , V_65 ) ) ;
if ( V_84 == V_89 )
F_25 ( V_14 , V_1 ) ;
return 0 ;
}
static inline unsigned int F_34 ( struct V_13 * V_14 ,
struct V_1 * V_1 ,
unsigned int V_10 ,
unsigned int V_92 )
{
unsigned int V_31 , V_93 ;
V_31 = V_1 -> V_20 [ V_10 ] . V_31 ;
V_93 = V_1 -> V_20 [ V_10 ] . V_30 + V_31 - V_92 ;
if ( V_31 < V_92 ) {
F_7 ( V_14 -> V_40 -> V_2 ,
L_4 ,
( int ) V_31 , ( int ) V_92 ) ;
V_93 = V_1 -> V_68 ;
} else if ( F_35 ( V_1 , V_93 ) ) {
#ifdef F_36
F_37 ( V_14 -> V_40 -> V_2 ,
L_5 ,
V_10 , V_1 -> V_32 , V_1 -> V_68 ,
V_1 -> V_34 , V_1 -> V_20 [ V_10 ] . V_30 ,
V_1 -> V_20 [ V_10 ] . V_31 , V_92 ) ;
#endif
if ( V_92 && V_31 < V_92 ) {
F_37 ( V_14 -> V_40 -> V_2 ,
L_6 ) ;
V_93 = V_1 -> V_68 ;
} else {
if ( ! V_92 )
V_93 = V_1 -> V_20 [ V_10 ] . V_30 ;
else
V_93 = V_1 -> V_20 [ V_10 ] . V_30 + V_31 ;
if ( F_35 ( V_1 , V_93 ) ) {
F_37 ( V_14 -> V_40 -> V_2 ,
L_7 ) ;
V_93 = V_1 -> V_68 ;
}
}
}
V_1 -> V_68 = V_93 ;
if ( V_93 >= V_1 -> V_33 )
V_93 -= V_1 -> V_33 ;
return V_93 ;
}
static T_2 F_38 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
unsigned int V_10 , V_94 , V_92 , V_93 ;
if ( F_39 ( ! V_1 -> V_32 ) )
return 0 ;
if ( ! ( F_28 ( F_27 ( V_1 , V_66 ) ) & V_95 ) )
return 0 ;
F_30 ( & V_14 -> V_75 ) ;
V_92 = F_14 ( F_27 ( V_1 , V_96 ) ) & 0xffffff ;
V_94 = F_14 ( F_27 ( V_1 , V_97 ) ) ;
if ( V_94 <= ( unsigned int ) V_1 -> V_15 . V_24 )
V_10 = 0 ;
else
V_10 = ( ( V_94 - ( unsigned int ) V_1 -> V_15 . V_24 ) / 8 - 1 ) %
V_1 -> V_32 ;
V_93 = F_34 ( V_14 , V_1 , V_10 , V_92 ) ;
F_31 ( & V_14 -> V_75 ) ;
return F_40 ( V_4 -> V_85 , V_93 ) ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_98 * V_99 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
int V_49 ;
V_49 = F_42 ( V_4 , F_43 ( V_99 ) ) ;
if ( V_49 < 0 )
return V_49 ;
V_49 = F_1 ( V_1 , V_4 , V_14 -> V_6 ,
F_44 ( V_99 ) ,
F_45 ( V_99 ) ) ;
if ( V_49 < 0 )
return V_49 ;
F_46 ( V_14 -> V_47 , V_100 , F_47 ( V_99 ) ) ;
F_46 ( V_14 -> V_47 , V_101 , 0 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
F_10 ( V_1 , V_4 , V_14 -> V_6 ) ;
F_49 ( V_4 ) ;
return 0 ;
}
static void F_50 ( struct V_13 * V_14 , struct V_1 * V_1 )
{
F_18 ( V_14 , V_14 -> V_102 ) ;
F_17 ( ( V_26 ) V_1 -> V_15 . V_24 , F_27 ( V_1 , V_103 ) ) ;
F_19 ( 20 ) ;
F_18 ( V_14 , V_14 -> V_102 ) ;
}
static int F_51 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
F_25 ( V_14 , V_1 ) ;
F_50 ( V_14 , V_1 ) ;
F_26 ( V_104 | V_105 | V_106 ,
F_27 ( V_1 , V_67 ) ) ;
return 0 ;
}
static int F_52 ( struct V_13 * V_14 , struct V_1 * V_1 ,
struct V_3 * V_4 )
{
struct V_107 * V_85 = V_4 -> V_85 ;
int V_49 ;
static const unsigned int V_108 [] = { 8000 , 9600 , 12000 , 16000 } ;
static const struct V_109 V_110 = {
. V_92 = F_53 ( V_108 ) ,
. V_111 = V_108 ,
. V_112 = 0 ,
} ;
V_85 -> V_113 = V_114 ;
if ( ( V_49 = V_109 ( V_85 , 0 , V_115 ,
& V_110 ) ) < 0 )
return V_49 ;
if ( ( V_49 = F_54 ( V_85 , V_116 ) ) < 0 )
return V_49 ;
V_85 -> V_48 = V_1 ;
V_1 -> V_4 = V_4 ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_117 + V_4 -> V_118 ] ;
return F_52 ( V_14 , V_1 , V_4 ) ;
}
static int F_56 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = F_2 ( V_4 ) ;
struct V_1 * V_1 = & V_14 -> V_77 [ V_14 -> V_119 + V_4 -> V_120 -> V_121 ] ;
return F_52 ( V_14 , V_1 , V_4 ) ;
}
static int F_57 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = V_4 -> V_85 -> V_48 ;
V_1 -> V_4 = NULL ;
return 0 ;
}
static void F_58 ( struct V_13 * V_14 , int V_10 , unsigned int V_122 ,
int V_123 )
{
V_14 -> V_77 [ V_10 ] . V_122 = V_122 ;
V_14 -> V_77 [ V_10 ] . V_123 = V_123 ;
V_14 -> V_77 [ V_10 ] . V_124 = V_14 -> V_124 + V_122 ;
}
static int F_59 ( struct V_13 * V_14 )
{
struct V_125 * V_120 ;
int V_49 ;
V_14 -> V_117 = 0 ;
V_14 -> V_119 = 1 ;
V_14 -> V_76 = 2 ;
V_14 -> V_73 = 0x330000 ;
V_49 = F_60 ( V_14 -> V_40 , V_14 -> V_40 -> V_126 , 0 , 1 , 1 , & V_120 ) ;
if ( V_49 < 0 )
return V_49 ;
F_61 ( V_120 , V_127 , & V_128 ) ;
F_61 ( V_120 , V_129 , & V_130 ) ;
V_120 -> V_131 = V_132 ;
V_120 -> V_48 = V_14 ;
strcpy ( V_120 -> V_133 , V_14 -> V_40 -> V_126 ) ;
V_14 -> V_134 [ 0 ] = V_120 ;
F_58 ( V_14 , 0 , V_135 , 0 ) ;
F_58 ( V_14 , 1 , V_136 , 1 ) ;
if ( ( V_49 = F_62 ( V_120 , V_137 ,
F_4 ( V_14 -> V_6 ) ,
64 * 1024 , 128 * 1024 ) ) < 0 )
return V_49 ;
return 0 ;
}
static void F_63 ( struct V_138 * V_139 )
{
struct V_13 * V_14 = V_139 -> V_48 ;
V_14 -> V_140 = NULL ;
}
static void F_64 ( struct V_46 * V_47 )
{
struct V_13 * V_14 = V_47 -> V_48 ;
V_14 -> V_47 = NULL ;
}
static int F_65 ( struct V_13 * V_14 )
{
struct V_141 V_47 ;
int V_49 ;
static struct V_142 V_143 = {
. V_144 = F_23 ,
. V_145 = F_24 ,
. V_146 = F_21 ,
} ;
if ( ( V_49 = V_138 ( V_14 -> V_40 , 0 , & V_143 , V_14 , & V_14 -> V_140 ) ) < 0 )
return V_49 ;
V_14 -> V_140 -> V_147 = F_63 ;
V_14 -> V_140 -> clock = V_14 -> V_148 ;
memset ( & V_47 , 0 , sizeof( V_47 ) ) ;
V_47 . V_48 = V_14 ;
V_47 . V_147 = F_64 ;
V_47 . V_6 = V_14 -> V_6 ;
V_47 . V_149 = V_150 | V_151 ;
V_47 . V_50 = V_14 -> V_102 ;
if ( ( V_49 = F_66 ( V_14 -> V_140 , & V_47 , & V_14 -> V_47 ) ) < 0 )
return V_49 ;
return 0 ;
}
static void F_67 ( struct V_152 * V_153 , struct V_154 * V_155 )
{
struct V_13 * V_14 = V_153 -> V_48 ;
int V_9 ;
F_68 ( V_155 , L_8 , V_14 -> V_40 -> V_156 ) ;
for ( V_9 = 0 ; V_9 < 0xa0 ; V_9 += 4 ) {
F_68 ( V_155 , L_9 , V_9 , F_14 ( V_14 -> V_124 + V_9 ) ) ;
}
}
static void F_69 ( struct V_13 * V_14 )
{
struct V_152 * V_153 ;
if ( ! F_70 ( V_14 -> V_40 , L_10 , & V_153 ) )
F_71 ( V_153 , V_14 , F_67 ) ;
}
static int F_72 ( struct V_13 * V_14 )
{
unsigned int V_36 ;
unsigned long V_157 ;
unsigned char V_158 ;
F_73 ( V_14 -> V_6 , V_159 , & V_158 ) ;
if( ( V_158 & V_160 ) != V_160 ) {
F_74 ( V_14 -> V_6 , 0x44 , V_158 | V_160 ) ;
F_19 ( 100 ) ;
}
F_73 ( V_14 -> V_6 , V_161 , & V_158 ) ;
if ( ! ( V_158 & V_162 ) ) {
F_74 ( V_14 -> V_6 , V_163 ,
V_164 |
V_165 |
V_166 ) ;
F_19 ( 100 ) ;
#if 1
F_74 ( V_14 -> V_6 , V_163 , 0x00 ) ;
F_19 ( 100 ) ;
#else
F_74 ( V_14 -> V_6 , V_163 ,
V_165 | V_166 ) ;
F_19 ( 2 ) ;
#endif
F_74 ( V_14 -> V_6 , V_163 , V_167 ) ;
F_19 ( 100 ) ;
}
F_73 ( V_14 -> V_6 , V_163 , & V_158 ) ;
if ( ( V_158 & V_167 ) != V_167 ) {
F_74 ( V_14 -> V_6 , V_163 , V_167 ) ;
F_19 ( 100 ) ;
}
V_157 = V_168 + F_75 ( 750 ) ;
do {
F_73 ( V_14 -> V_6 , V_161 , & V_158 ) ;
if ( V_158 & V_162 )
break;
F_76 ( 1 ) ;
} while ( F_77 ( V_168 , V_157 ) );
if ( ( V_36 = F_13 ( V_14 ) ) & V_39 )
F_7 ( V_14 -> V_40 -> V_2 ,
L_11 , V_36 ) ;
F_16 ( V_14 , V_61 |
V_45 |
( V_56 << V_57 ) ) ;
V_157 = V_168 + F_75 ( 750 ) ;
F_16 ( V_14 , V_61 |
V_45 |
( V_56 << V_57 ) ) ;
do {
if ( ( V_36 = F_13 ( V_14 ) ) & V_45 ) {
V_14 -> V_102 = 1 ;
goto V_169;
}
F_76 ( 1 ) ;
} while ( F_77 ( V_168 , V_157 ) );
V_169:
F_17 ( 0 , F_15 ( V_14 , V_170 ) ) ;
return 0 ;
}
static int F_78 ( struct V_121 * V_2 )
{
struct V_171 * V_40 = F_79 ( V_2 ) ;
struct V_13 * V_14 = V_40 -> V_48 ;
int V_9 ;
F_80 ( V_40 , V_172 ) ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ )
F_81 ( V_14 -> V_134 [ V_9 ] ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_82 ( V_14 -> V_69 ) ;
F_83 ( V_14 -> V_47 ) ;
return 0 ;
}
static int F_84 ( struct V_121 * V_2 )
{
struct V_171 * V_40 = F_79 ( V_2 ) ;
struct V_13 * V_14 = V_40 -> V_48 ;
int V_9 ;
F_72 ( V_14 ) ;
F_85 ( V_14 -> V_47 ) ;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
F_80 ( V_40 , V_173 ) ;
return 0 ;
}
static int F_86 ( struct V_13 * V_14 )
{
unsigned int V_9 ;
if ( V_14 -> V_69 < 0 )
goto V_174;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
V_174:
if ( V_14 -> V_69 >= 0 )
F_87 ( V_14 -> V_69 , V_14 ) ;
F_88 ( V_14 -> V_6 ) ;
F_89 ( V_14 -> V_6 ) ;
F_12 ( V_14 ) ;
return 0 ;
}
static int F_90 ( struct V_175 * V_121 )
{
struct V_13 * V_14 = V_121 -> V_176 ;
return F_86 ( V_14 ) ;
}
static int F_91 ( struct V_171 * V_40 ,
struct V_5 * V_6 ,
int V_177 ,
int V_178 ,
unsigned int V_148 ,
struct V_13 * * V_179 )
{
struct V_13 * V_14 ;
int V_49 ;
static struct V_180 V_143 = {
. V_181 = F_90 ,
} ;
if ( ( V_49 = F_92 ( V_6 ) ) < 0 )
return V_49 ;
if ( ( V_14 = F_93 ( sizeof( * V_14 ) , V_21 ) ) == NULL ) {
F_89 ( V_6 ) ;
return - V_19 ;
}
F_94 ( & V_14 -> V_75 ) ;
V_14 -> V_40 = V_40 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_69 = - 1 ;
if ( ( V_49 = F_95 ( V_6 , V_40 -> V_182 ) ) < 0 ) {
F_12 ( V_14 ) ;
F_89 ( V_6 ) ;
return V_49 ;
}
V_14 -> V_124 = F_96 ( V_6 , 0 ) ;
if ( F_97 ( V_6 -> V_69 , F_29 , V_183 ,
V_184 , V_14 ) ) {
F_7 ( V_40 -> V_2 , L_12 , V_6 -> V_69 ) ;
F_86 ( V_14 ) ;
return - V_185 ;
}
V_14 -> V_69 = V_6 -> V_69 ;
if ( V_148 >= 8000 && V_148 <= 48000 )
V_14 -> V_148 = V_148 ;
F_82 ( V_14 -> V_69 ) ;
if ( ( V_49 = F_72 ( V_14 ) ) < 0 ) {
F_86 ( V_14 ) ;
return V_49 ;
}
if ( ( V_49 = F_98 ( V_40 , V_186 , V_14 , & V_143 ) ) < 0 ) {
F_86 ( V_14 ) ;
return V_49 ;
}
F_99 ( V_6 ) ;
* V_179 = V_14 ;
return 0 ;
}
static int F_100 ( struct V_5 * V_6 ,
const struct V_187 * V_188 )
{
struct V_171 * V_40 ;
struct V_13 * V_14 ;
int V_177 = 0 , V_189 ;
unsigned int V_9 ;
int V_49 ;
V_49 = F_101 ( & V_6 -> V_2 , V_190 , V_191 , V_192 , 0 , & V_40 ) ;
if ( V_49 < 0 )
return V_49 ;
V_189 = V_188 -> V_193 ;
switch ( V_189 ) {
case V_194 :
strcpy ( V_40 -> V_182 , L_13 ) ;
sprintf ( V_40 -> V_126 , L_14 ) ;
break;
default:
F_7 ( V_40 -> V_2 , L_15 , V_189 ) ;
V_49 = - V_25 ;
goto V_195;
}
if ( ( V_49 = F_91 ( V_40 , V_6 , V_177 , V_6 -> V_178 ,
V_148 , & V_14 ) ) < 0 )
goto V_195;
V_40 -> V_48 = V_14 ;
if ( ( V_49 = F_65 ( V_14 ) ) < 0 )
goto V_195;
if ( ( V_49 = F_59 ( V_14 ) ) < 0 )
goto V_195;
for ( V_9 = 0 ; V_9 < V_14 -> V_76 ; V_9 ++ )
F_25 ( V_14 , & V_14 -> V_77 [ V_9 ] ) ;
sprintf ( V_40 -> V_156 , L_16 ,
V_40 -> V_126 , V_14 -> V_124 , V_14 -> V_69 ) ;
F_69 ( V_14 ) ;
if ( ( V_49 = F_102 ( V_40 ) ) < 0 ) {
F_103 ( V_40 ) ;
return V_49 ;
}
F_104 ( V_6 , V_40 ) ;
return 0 ;
V_195:
F_103 ( V_40 ) ;
return V_49 ;
}
static void F_105 ( struct V_5 * V_6 )
{
F_103 ( F_106 ( V_6 ) ) ;
}
