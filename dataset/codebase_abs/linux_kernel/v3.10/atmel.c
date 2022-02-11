static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 -> V_4 + V_3 ;
}
static inline T_1 F_2 ( struct V_1 * V_2 , T_1 V_3 )
{
return V_2 -> V_5 . V_6 + V_3 ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
return V_2 -> V_5 . V_8 + ( sizeof( struct V_9 ) * V_7 ) + V_3 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_7 )
{
return V_2 -> V_5 . V_10 + ( sizeof( struct V_11 ) * V_7 ) + V_3 ;
}
static inline T_2 F_5 ( struct V_12 * V_13 , T_1 V_3 )
{
return F_6 ( V_13 -> V_14 + V_3 ) ;
}
static inline void F_7 ( struct V_12 * V_13 , T_1 V_3 , T_2 V_15 )
{
F_8 ( V_15 , V_13 -> V_14 + V_3 ) ;
}
static inline T_1 F_9 ( struct V_12 * V_13 , T_1 V_3 )
{
return F_10 ( V_13 -> V_14 + V_3 ) ;
}
static inline void F_11 ( struct V_12 * V_13 , T_1 V_3 , T_1 V_15 )
{
F_12 ( V_15 , V_13 -> V_14 + V_3 ) ;
}
static inline T_2 F_13 ( struct V_1 * V_2 , T_1 V_16 )
{
F_14 ( V_2 -> V_13 , V_16 ) ;
return F_5 ( V_2 -> V_13 , V_17 ) ;
}
static inline void F_15 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_15 )
{
F_14 ( V_2 -> V_13 , V_16 ) ;
F_7 ( V_2 -> V_13 , V_17 , V_15 ) ;
}
static inline T_1 F_16 ( struct V_1 * V_2 , T_1 V_16 )
{
F_14 ( V_2 -> V_13 , V_16 ) ;
return F_9 ( V_2 -> V_13 , V_17 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_15 )
{
F_14 ( V_2 -> V_13 , V_16 ) ;
F_11 ( V_2 -> V_13 , V_17 , V_15 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
int V_18 ;
for ( V_18 = 0 ;
F_13 ( V_2 , F_4 ( V_2 , V_19 , V_2 -> V_20 ) ) == V_21 &&
V_18 < V_2 -> V_5 . V_22 ;
V_18 ++ ) {
T_2 V_23 = F_13 ( V_2 , F_4 ( V_2 , V_24 , V_2 -> V_20 ) ) ;
T_1 V_25 = F_16 ( V_2 , F_4 ( V_2 , V_26 , V_2 -> V_20 ) ) ;
T_2 type = F_13 ( V_2 , F_4 ( V_2 , V_27 , V_2 -> V_20 ) ) ;
F_15 ( V_2 , F_4 ( V_2 , V_19 , V_2 -> V_20 ) , 0 ) ;
V_2 -> V_28 += V_25 ;
V_2 -> V_29 ++ ;
if ( V_2 -> V_30 + V_25 > ( V_2 -> V_5 . V_31 + V_2 -> V_5 . V_32 ) )
V_2 -> V_30 = 0 ;
else
V_2 -> V_30 += V_25 ;
if ( V_2 -> V_20 < ( V_2 -> V_5 . V_22 - 1 ) )
V_2 -> V_20 ++ ;
else
V_2 -> V_20 = 0 ;
if ( type == V_33 ) {
if ( V_23 == V_34 )
V_2 -> V_13 -> V_35 . V_36 ++ ;
else
V_2 -> V_13 -> V_35 . V_37 ++ ;
F_19 ( V_2 -> V_13 ) ;
}
}
}
static T_1 F_20 ( struct V_1 * V_2 , T_1 V_38 )
{
T_1 V_39 = V_2 -> V_5 . V_32 - V_2 -> V_40 ;
if ( V_2 -> V_29 == 3 || V_2 -> V_28 < V_38 )
return 0 ;
if ( V_39 >= V_38 )
return V_2 -> V_5 . V_31 + V_2 -> V_40 ;
if ( V_2 -> V_28 - V_39 >= V_38 ) {
V_2 -> V_40 = 0 ;
return V_2 -> V_5 . V_31 ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 , int V_41 ,
T_1 V_38 , T_1 V_42 , T_2 type )
{
F_17 ( V_2 , F_4 ( V_2 , V_43 , V_2 -> V_44 ) , V_42 ) ;
F_17 ( V_2 , F_4 ( V_2 , V_26 , V_2 -> V_44 ) , V_38 ) ;
if ( ! V_2 -> V_45 )
F_17 ( V_2 , F_4 ( V_2 , V_46 , V_2 -> V_44 ) , V_38 ) ;
F_15 ( V_2 , F_4 ( V_2 , V_27 , V_2 -> V_44 ) , type ) ;
F_15 ( V_2 , F_4 ( V_2 , V_47 , V_2 -> V_44 ) , V_2 -> V_48 ) ;
F_15 ( V_2 , F_4 ( V_2 , V_49 , V_2 -> V_44 ) , 0 ) ;
if ( V_2 -> V_45 ) {
int V_50 , V_51 ;
if ( V_41 ) {
V_50 = V_2 -> V_52 ;
if ( V_50 == V_53 ||
V_50 == V_54 )
V_51 = 8 ;
else if ( V_50 == V_55 )
V_51 = 12 ;
else if ( V_2 -> V_56 == V_53 ||
V_2 -> V_56 == V_54 ) {
V_50 = V_2 -> V_56 ;
V_51 = 8 ;
} else {
V_50 = V_57 ;
V_51 = 0 ;
}
} else {
V_50 = V_2 -> V_56 ;
if ( V_50 == V_53 ||
V_50 == V_54 )
V_51 = 8 ;
else if ( V_50 == V_55 )
V_51 = 12 ;
else if ( V_2 -> V_52 == V_53 ||
V_2 -> V_52 == V_54 ) {
V_50 = V_2 -> V_52 ;
V_51 = 8 ;
} else {
V_50 = V_57 ;
V_51 = 0 ;
}
}
F_15 ( V_2 , F_4 ( V_2 , V_58 , V_2 -> V_44 ) ,
V_50 ) ;
F_15 ( V_2 , F_4 ( V_2 , V_59 , V_2 -> V_44 ) ,
V_51 ) ;
}
F_22 ( V_2 , F_4 ( V_2 , V_60 , V_2 -> V_44 ) , 0x80000000L ) ;
F_15 ( V_2 , F_4 ( V_2 , V_19 , V_2 -> V_44 ) , V_61 ) ;
if ( V_2 -> V_62 != V_2 -> V_44 )
F_22 ( V_2 , F_4 ( V_2 , V_60 , V_2 -> V_62 ) , 0 ) ;
V_2 -> V_62 = V_2 -> V_44 ;
if ( V_2 -> V_44 < ( V_2 -> V_5 . V_22 - 1 ) )
V_2 -> V_44 ++ ;
else
V_2 -> V_44 = 0 ;
V_2 -> V_29 -- ;
V_2 -> V_28 -= V_38 ;
}
static T_3 F_23 ( struct V_63 * V_64 , struct V_12 * V_13 )
{
static const T_2 V_65 [ 6 ] = { 0xaa , 0xaa , 0x03 , 0x00 , 0x00 , 0x00 } ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_66 V_67 ;
unsigned long V_68 ;
T_1 V_42 , V_69 , V_38 = ( V_70 < V_64 -> V_38 ) ? V_64 -> V_38 : V_70 ;
if ( V_2 -> V_71 && V_2 -> V_72 &&
! (* V_2 -> V_72 )( V_2 -> V_71 ) ) {
V_13 -> V_35 . V_37 ++ ;
F_25 ( V_64 ) ;
return V_73 ;
}
if ( V_2 -> V_74 != V_75 ) {
V_13 -> V_35 . V_37 ++ ;
F_25 ( V_64 ) ;
return V_73 ;
}
F_26 ( & V_2 -> V_76 ) ;
F_27 ( & V_2 -> V_77 , V_68 ) ;
if ( ! ( V_42 = F_20 ( V_2 , V_38 + 18 ) ) ) {
V_13 -> V_35 . V_78 ++ ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
F_29 ( & V_2 -> V_76 ) ;
F_30 ( V_13 ) ;
return V_79 ;
}
V_69 = V_80 ;
V_67 . V_81 = 0 ;
V_67 . V_82 = 0 ;
if ( V_2 -> V_83 )
V_69 |= V_84 ;
if ( V_2 -> V_85 == V_86 ) {
F_31 ( V_64 , & V_67 . V_87 , 6 ) ;
memcpy ( & V_67 . V_88 , V_13 -> V_89 , 6 ) ;
memcpy ( & V_67 . V_90 , V_2 -> V_91 , 6 ) ;
} else {
V_69 |= V_92 ;
memcpy ( & V_67 . V_87 , V_2 -> V_93 , 6 ) ;
memcpy ( & V_67 . V_88 , V_13 -> V_89 , 6 ) ;
F_31 ( V_64 , & V_67 . V_90 , 6 ) ;
}
if ( V_2 -> V_45 )
memcpy ( & V_67 . V_94 , V_65 , 6 ) ;
V_67 . V_95 = F_32 ( V_69 ) ;
F_33 ( V_13 , V_42 , ( unsigned char * ) & V_67 , V_96 ) ;
F_33 ( V_13 , V_42 + V_96 , V_64 -> V_15 + 12 , V_38 - 12 ) ;
V_2 -> V_40 += V_38 - 12 + V_96 ;
F_21 ( V_2 , * ( V_64 -> V_15 ) & 0x01 , V_38 + 18 , V_42 , V_33 ) ;
V_13 -> V_35 . V_97 += V_38 ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
F_29 ( & V_2 -> V_76 ) ;
F_25 ( V_64 ) ;
return V_73 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
T_2 * V_98 , int V_99 )
{
T_1 V_42 ;
int V_38 = V_100 + V_99 ;
if ( ! ( V_42 = F_20 ( V_2 , V_38 ) ) )
return;
F_33 ( V_2 -> V_13 , V_42 , ( T_2 * ) V_67 , V_100 ) ;
F_33 ( V_2 -> V_13 , V_42 + V_100 , V_98 , V_99 ) ;
V_2 -> V_40 += V_38 ;
F_21 ( V_2 , V_67 -> V_87 [ 0 ] & 0x01 , V_38 , V_42 , V_101 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
T_1 V_25 , T_1 V_102 , T_4 V_103 )
{
T_2 V_104 [ 6 ] ;
struct V_63 * V_64 ;
unsigned char * V_105 ;
F_36 ( V_2 -> V_13 , V_104 , V_102 + 24 , 6 ) ;
V_25 -= 6 ;
if ( V_2 -> V_106 ) {
V_103 = F_37 ( V_103 , V_104 , 6 ) ;
V_25 -= 4 ;
}
if ( ! ( V_64 = F_38 ( V_25 + 14 ) ) ) {
V_2 -> V_13 -> V_35 . V_107 ++ ;
return;
}
F_39 ( V_64 , 2 ) ;
V_105 = F_40 ( V_64 , V_25 + 12 ) ;
F_36 ( V_2 -> V_13 , V_105 + 12 , V_102 + 30 , V_25 ) ;
if ( V_2 -> V_106 ) {
T_4 V_108 ;
V_103 = F_37 ( V_103 , V_105 + 12 , V_25 ) ;
F_36 ( V_2 -> V_13 , ( void * ) & V_108 , V_102 + 30 + V_25 , 4 ) ;
if ( ( V_103 ^ 0xffffffff ) != V_108 ) {
V_2 -> V_13 -> V_35 . V_109 ++ ;
F_25 ( V_64 ) ;
return;
}
}
memcpy ( V_105 , V_67 -> V_87 , 6 ) ;
if ( F_41 ( V_67 -> V_95 ) & V_110 )
memcpy ( & V_105 [ 6 ] , V_67 -> V_90 , 6 ) ;
else
memcpy ( & V_105 [ 6 ] , V_67 -> V_88 , 6 ) ;
V_64 -> V_111 = F_42 ( V_64 , V_2 -> V_13 ) ;
V_64 -> V_112 = V_113 ;
F_43 ( V_64 ) ;
V_2 -> V_13 -> V_35 . V_114 += 12 + V_25 ;
V_2 -> V_13 -> V_35 . V_115 ++ ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_116 , T_1 V_25 )
{
int V_18 = V_25 - 4 ;
T_4 V_108 , V_103 = 0xffffffff ;
if ( V_25 < 4 )
return 0 ;
F_36 ( V_2 -> V_13 , ( void * ) & V_108 , V_116 + V_18 , 4 ) ;
F_14 ( V_2 -> V_13 , V_116 ) ;
while ( V_18 -- ) {
T_2 V_117 = F_5 ( V_2 -> V_13 , V_17 ) ;
V_103 = F_37 ( V_103 , & V_117 , 1 ) ;
}
return ( V_103 ^ 0xffffffff ) == V_108 ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
T_1 V_25 , T_1 V_102 , T_4 V_103 , T_1 V_118 ,
T_2 V_119 , int V_120 )
{
T_2 V_104 [ 6 ] ;
T_2 V_121 [ 6 ] ;
struct V_63 * V_64 ;
if ( F_41 ( V_67 -> V_95 ) & V_110 )
memcpy ( V_121 , V_67 -> V_90 , 6 ) ;
else
memcpy ( V_121 , V_67 -> V_88 , 6 ) ;
V_102 += 24 ;
if ( V_2 -> V_106 )
V_25 -= 4 ;
if ( V_119 == 0 ) {
F_36 ( V_2 -> V_13 , V_104 , V_102 , 6 ) ;
V_25 -= 6 ;
V_102 += 6 ;
if ( V_2 -> V_106 )
V_103 = F_37 ( V_103 , V_104 , 6 ) ;
V_2 -> V_122 = V_118 ;
V_2 -> V_119 = 1 ;
V_2 -> V_123 = V_25 ;
memcpy ( V_2 -> V_124 , V_121 , 6 ) ;
memcpy ( & V_2 -> V_125 [ 6 ] , V_121 , 6 ) ;
memcpy ( V_2 -> V_125 , V_67 -> V_87 , 6 ) ;
F_36 ( V_2 -> V_13 , & V_2 -> V_125 [ 12 ] , V_102 , V_25 ) ;
if ( V_2 -> V_106 ) {
T_4 V_108 ;
V_103 = F_37 ( V_103 , & V_2 -> V_125 [ 12 ] , V_25 ) ;
F_36 ( V_2 -> V_13 , ( void * ) & V_108 , V_102 + V_25 , 4 ) ;
if ( ( V_103 ^ 0xffffffff ) != V_108 ) {
V_2 -> V_13 -> V_35 . V_109 ++ ;
memset ( V_2 -> V_124 , 0xff , 6 ) ;
}
}
} else if ( V_2 -> V_119 == V_119 &&
V_2 -> V_122 == V_118 &&
memcmp ( V_2 -> V_124 , V_121 , 6 ) == 0 ) {
F_36 ( V_2 -> V_13 , & V_2 -> V_125 [ 12 + V_2 -> V_123 ] ,
V_102 , V_25 ) ;
if ( V_2 -> V_106 ) {
T_4 V_108 ;
V_103 = F_37 ( V_103 ,
& V_2 -> V_125 [ 12 + V_2 -> V_123 ] ,
V_25 ) ;
F_36 ( V_2 -> V_13 , ( void * ) & V_108 , V_102 + V_25 , 4 ) ;
if ( ( V_103 ^ 0xffffffff ) != V_108 ) {
V_2 -> V_13 -> V_35 . V_109 ++ ;
memset ( V_2 -> V_124 , 0xff , 6 ) ;
V_120 = 1 ;
}
}
V_2 -> V_123 += V_25 ;
V_2 -> V_119 ++ ;
if ( ! V_120 ) {
memset ( V_2 -> V_124 , 0xff , 6 ) ;
if ( ! ( V_64 = F_38 ( V_2 -> V_123 + 14 ) ) ) {
V_2 -> V_13 -> V_35 . V_107 ++ ;
} else {
F_39 ( V_64 , 2 ) ;
memcpy ( F_40 ( V_64 , V_2 -> V_123 + 12 ) ,
V_2 -> V_125 ,
V_2 -> V_123 + 12 ) ;
V_64 -> V_111 = F_42 ( V_64 , V_2 -> V_13 ) ;
V_64 -> V_112 = V_113 ;
F_43 ( V_64 ) ;
V_2 -> V_13 -> V_35 . V_114 += V_2 -> V_123 + 12 ;
V_2 -> V_13 -> V_35 . V_115 ++ ;
}
}
} else
V_2 -> V_126 . V_127 . V_128 ++ ;
}
static void F_46 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_66 V_67 ;
for ( V_18 = 0 ;
F_13 ( V_2 , F_3 ( V_2 , V_129 , V_2 -> V_130 ) ) == V_131 &&
V_18 < V_2 -> V_5 . V_132 ;
V_18 ++ ) {
T_1 V_25 , V_102 , V_69 , V_133 ;
T_2 V_23 = F_13 ( V_2 , F_3 ( V_2 , V_134 , V_2 -> V_130 ) ) ;
T_4 V_103 = 0xffffffff ;
if ( V_23 != V_135 ) {
if ( V_23 == 0xc1 )
V_2 -> V_126 . V_127 . V_136 ++ ;
else
V_2 -> V_13 -> V_35 . V_137 ++ ;
goto V_138;
}
V_25 = F_16 ( V_2 , F_3 ( V_2 , V_139 , V_2 -> V_130 ) ) ;
V_102 = F_16 ( V_2 , F_3 ( V_2 , V_140 , V_2 -> V_130 ) ) ;
if ( V_25 < 30 ) {
V_2 -> V_13 -> V_35 . V_137 ++ ;
goto V_138;
}
F_36 ( V_2 -> V_13 , ( char * ) & V_67 , V_102 , 24 ) ;
V_69 = F_41 ( V_67 . V_95 ) ;
V_133 = F_41 ( V_67 . V_82 ) ;
if ( V_2 -> F_44 ) {
if ( ! V_2 -> V_83 || ! ( V_69 & V_84 ) ) {
V_2 -> V_106 = F_44 ( V_2 , V_102 , V_25 ) ;
} else {
V_2 -> V_106 = F_44 ( V_2 , V_102 + 24 , V_25 - 24 ) ;
}
if ( V_2 -> V_106 ) {
if ( V_2 -> V_141 ++ > 5 )
V_2 -> F_44 = 0 ;
} else {
if ( V_2 -> V_142 ++ > 5 )
V_2 -> F_44 = 0 ;
}
}
if ( V_2 -> V_106 && ( ! V_2 -> V_83 || ! ( V_69 & V_84 ) ) ) {
V_103 = F_37 ( 0xffffffff , ( unsigned char * ) & V_67 , 24 ) ;
}
V_25 -= 24 ;
if ( ( V_69 & V_143 ) == V_80 ) {
int V_144 = V_69 & V_145 ;
T_2 V_146 = V_133 & V_147 ;
T_1 V_148 = ( V_133 & V_149 ) >> 4 ;
if ( ! V_144 && V_146 == 0 ) {
F_35 ( V_2 , & V_67 , V_25 , V_102 , V_103 ) ;
} else {
F_45 ( V_2 , & V_67 , V_25 , V_102 , V_103 ,
V_148 , V_146 , V_144 ) ;
}
}
if ( ( V_69 & V_143 ) == V_150 ) {
F_36 ( V_2 -> V_13 , ( unsigned char * ) & V_2 -> V_125 , V_102 + 24 , V_25 ) ;
memset ( V_2 -> V_124 , 0xff , 6 ) ;
if ( V_2 -> V_106 ) {
V_25 -= 4 ;
V_103 = F_37 ( V_103 , ( unsigned char * ) & V_2 -> V_125 , V_25 ) ;
if ( ( V_103 ^ 0xffffffff ) != ( * ( ( T_4 * ) & V_2 -> V_125 [ V_25 ] ) ) ) {
V_2 -> V_13 -> V_35 . V_109 ++ ;
goto V_138;
}
}
F_47 ( V_2 , & V_67 , V_25 ,
F_13 ( V_2 , F_3 ( V_2 , V_151 , V_2 -> V_130 ) ) ) ;
}
V_138:
F_15 ( V_2 , F_3 ( V_2 , V_129 , V_2 -> V_130 ) , V_152 ) ;
if ( V_2 -> V_130 < ( V_2 -> V_5 . V_132 - 1 ) )
V_2 -> V_130 ++ ;
else
V_2 -> V_130 = 0 ;
}
}
static T_5 F_48 ( int V_153 , void * V_154 )
{
struct V_12 * V_13 = (struct V_12 * ) V_154 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
T_2 V_155 ;
int V_18 = - 1 ;
static const T_2 V_156 [] = {
V_157 ,
V_158 ,
V_159 ,
V_160 ,
V_161 ,
V_162 ,
V_163 ,
V_164
} ;
if ( V_2 -> V_71 && V_2 -> V_72 &&
! (* V_2 -> V_72 )( V_2 -> V_71 ) )
return V_165 ;
if ( V_2 -> V_74 == V_166 )
return V_167 ;
F_49 ( V_13 , V_168 ) ;
while ( 1 ) {
if ( ! F_50 ( V_2 ) ) {
F_51 ( V_169 L_1 , V_13 -> V_170 ) ;
return V_165 ;
}
V_155 = F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) ;
F_15 ( V_2 , F_1 ( V_2 , V_172 ) , 0 ) ;
if ( ! V_155 ) {
F_52 ( V_13 , V_168 ) ;
return V_18 == - 1 ? V_167 : V_165 ;
}
F_52 ( V_13 , V_173 ) ;
for ( V_18 = 0 ; V_18 < F_53 ( V_156 ) ; V_18 ++ )
if ( V_155 & V_156 [ V_18 ] )
break;
if ( ! F_50 ( V_2 ) ) {
F_51 ( V_169 L_1 , V_13 -> V_170 ) ;
return V_165 ;
}
V_155 = F_13 ( V_2 , F_1 ( V_2 , V_171 ) ) ;
V_155 ^= V_156 [ V_18 ] ;
F_15 ( V_2 , F_1 ( V_2 , V_171 ) , V_155 ) ;
F_15 ( V_2 , F_1 ( V_2 , V_172 ) , 0 ) ;
switch ( V_156 [ V_18 ] ) {
case V_157 :
if ( V_2 -> V_85 == V_174 &&
V_2 -> V_74 == V_75 ) {
V_2 -> V_175 = 0 ;
F_54 ( V_2 , 1 ) ;
}
break;
case V_160 :
V_2 -> V_126 . V_127 . V_176 ++ ;
case V_158 :
F_46 ( V_2 ) ;
break;
case V_159 :
F_18 ( V_2 ) ;
break;
case V_161 :
F_51 ( V_169 L_2 , V_13 -> V_170 ) ;
F_55 ( V_2 , V_177 ) ;
break;
case V_162 :
F_56 ( V_2 ) ;
break;
case V_163 :
F_57 ( V_2 , V_178 , V_179 ,
V_2 -> V_93 , 6 ) ;
if ( V_2 -> V_45 )
F_58 ( V_2 ) ;
break;
case V_164 :
F_51 ( V_180 L_3 , V_13 -> V_170 ) ;
break;
}
}
}
static struct V_181 * F_59 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
F_60 ( V_2 ) ;
V_2 -> V_126 . V_23 = V_2 -> V_74 ;
if ( V_2 -> V_85 == V_174 ) {
if ( V_2 -> V_74 != V_75 ) {
V_2 -> V_126 . V_182 . V_182 = 0 ;
V_2 -> V_126 . V_182 . V_183 = 0 ;
V_2 -> V_126 . V_182 . V_184 = ( V_185
| V_186 ) ;
}
V_2 -> V_126 . V_182 . V_187 = 0 ;
V_2 -> V_126 . V_182 . V_184 |= V_188 ;
} else {
V_2 -> V_126 . V_182 . V_182 = 0 ;
V_2 -> V_126 . V_182 . V_183 = 0 ;
V_2 -> V_126 . V_182 . V_187 = 0 ;
V_2 -> V_126 . V_182 . V_184 = V_185
| V_186
| V_188 ;
V_2 -> V_126 . V_189 . V_190 = 0 ;
}
return & V_2 -> V_126 ;
}
static int F_61 ( struct V_12 * V_13 , int V_191 )
{
if ( ( V_191 < 68 ) || ( V_191 > 2312 ) )
return - V_192 ;
V_13 -> V_193 = V_191 ;
return 0 ;
}
static int F_62 ( struct V_12 * V_13 , void * V_194 )
{
struct V_195 * V_196 = V_194 ;
memcpy ( V_13 -> V_89 , V_196 -> V_197 , V_13 -> V_198 ) ;
return F_63 ( V_13 ) ;
}
int F_63 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_18 , V_199 , V_200 ;
F_64 ( & V_2 -> V_201 ) ;
V_2 -> V_74 = V_166 ;
if ( V_2 -> V_202 ) {
memcpy ( V_2 -> V_203 , V_2 -> V_204 , V_2 -> V_202 ) ;
V_2 -> V_205 = V_2 -> V_202 ;
V_2 -> V_202 = 0 ;
}
V_2 -> V_206 = 0 ;
V_2 -> V_207 = 0 ;
V_2 -> V_208 = 0 ;
V_2 -> V_209 = 0 ;
V_2 -> V_210 = 0x0001 ;
V_2 -> V_211 = 0x0002 ;
V_2 -> V_212 = V_213 ;
V_2 -> V_175 = 0 ;
V_200 = F_65 ( V_13 ) ;
if ( V_200 )
return V_200 ;
if ( V_2 -> V_214 ) {
V_2 -> V_215 = V_2 -> V_214 ;
F_66 ( V_2 , V_216 , V_217 , V_2 -> V_215 ) ;
} else {
V_2 -> V_215 = F_67 ( V_2 , V_216 , V_217 ) ;
for ( V_18 = 0 ; V_18 < F_53 ( V_218 ) ; V_18 ++ )
if ( V_2 -> V_215 == V_218 [ V_18 ] . V_215 )
break;
if ( V_18 == F_53 ( V_218 ) ) {
V_2 -> V_215 = V_219 ;
F_51 ( V_169 L_4 , V_13 -> V_170 ) ;
}
}
if ( ( V_199 = F_68 ( V_2 , V_2 -> V_199 ) ) )
V_2 -> V_199 = V_199 ;
F_54 ( V_2 , 1 ) ;
F_52 ( V_2 -> V_13 , V_168 ) ;
return 0 ;
}
static int F_69 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_74 == V_75 ) {
union V_220 V_221 ;
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
V_221 . V_223 . V_224 = V_225 ;
memset ( V_221 . V_223 . V_197 , 0 , V_226 ) ;
F_70 ( V_2 -> V_13 , V_227 , & V_221 , NULL ) ;
}
F_55 ( V_2 , V_166 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_199 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_53 ( V_218 ) ; V_18 ++ )
if ( V_2 -> V_215 == V_218 [ V_18 ] . V_215 ) {
if ( V_199 >= V_218 [ V_18 ] . V_231 &&
V_199 <= V_218 [ V_18 ] . V_232 )
return 0 ;
else
return V_218 [ V_18 ] . V_231 ;
}
return 0 ;
}
static int F_71 ( struct V_233 * V_234 , void * V_235 )
{
struct V_1 * V_2 = V_234 -> V_236 ;
int V_18 ;
char * V_237 , * V_238 , * V_239 ;
F_72 ( V_234 , L_5 , V_240 , V_241 ) ;
if ( V_2 -> V_74 != V_166 ) {
F_72 ( V_234 ,
L_6
L_7 ,
V_2 -> V_5 . V_242 ,
V_2 -> V_5 . V_243 ,
V_2 -> V_5 . V_244 ) ;
if ( V_2 -> V_245 != V_246 )
F_73 ( V_234 , L_8 ) ;
else if ( V_2 -> V_247 )
F_72 ( V_234 , L_9 , V_2 -> V_248 ) ;
else
F_72 ( V_234 , L_10 , V_2 -> V_248 ) ;
switch ( V_2 -> V_245 ) {
case V_249 :
V_239 = L_11 ;
break;
case V_250 :
V_239 = L_12 ;
break;
case V_246 :
V_239 = L_13 ;
break;
default:
V_239 = L_14 ;
}
V_238 = L_14 ;
for ( V_18 = 0 ; V_18 < F_53 ( V_218 ) ; V_18 ++ )
if ( V_2 -> V_215 == V_218 [ V_18 ] . V_215 )
V_238 = V_218 [ V_18 ] . V_170 ;
F_72 ( V_234 , L_15 , V_239 ) ;
F_72 ( V_234 , L_16 , V_238 ) ;
F_72 ( V_234 , L_17 ,
V_2 -> V_106 ? L_18 : L_19 ) ;
F_72 ( V_234 , L_20 ,
V_2 -> V_45 ? L_21 : L_22 ) ;
}
switch ( V_2 -> V_74 ) {
case V_251 :
V_237 = L_23 ;
break;
case V_252 :
V_237 = L_24 ;
break;
case V_253 :
V_237 = L_25 ;
break;
case V_254 :
V_237 = L_26 ;
break;
case V_75 :
V_237 = L_27 ;
break;
case V_255 :
V_237 = L_28 ;
break;
case V_177 :
V_237 = L_29 ;
break;
case V_166 :
V_237 = L_30 ;
break;
default:
V_237 = L_14 ;
}
F_72 ( V_234 , L_31 , V_237 ) ;
return 0 ;
}
static int F_74 ( struct V_256 * V_256 , struct V_257 * V_257 )
{
return F_75 ( V_257 , F_71 , F_76 ( V_256 ) ) ;
}
struct V_12 * F_77 ( unsigned short V_153 , unsigned long V_258 ,
const T_6 V_259 ,
struct V_260 * V_261 ,
int (* F_78)( void * ) , void * V_71 )
{
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_262 ;
V_13 = F_79 ( sizeof( * V_2 ) ) ;
if ( ! V_13 )
return NULL ;
if ( F_80 ( V_13 , V_13 -> V_170 ) < 0 ) {
F_51 ( V_263 L_32 ) ;
goto V_264;
}
V_2 = F_24 ( V_13 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_261 = V_261 ;
V_2 -> V_72 = F_78 ;
V_2 -> V_71 = V_71 ;
V_2 -> V_247 = NULL ;
V_2 -> V_248 [ 0 ] = '\0' ;
V_2 -> V_265 = V_259 ;
if ( V_247 )
strcpy ( V_2 -> V_248 , V_247 ) ;
V_2 -> V_228 = F_78 ? V_229 : V_266 ;
V_2 -> V_74 = V_166 ;
V_2 -> V_106 = 0 ;
if ( V_2 -> V_228 == V_229 ) {
V_2 -> F_44 = 1 ;
V_2 -> V_141 = V_2 -> V_142 = 0 ;
} else
V_2 -> F_44 = 0 ;
V_2 -> V_267 = V_268 ;
V_2 -> V_269 = 0 ;
memset ( V_2 -> V_124 , 0xff , sizeof( V_2 -> V_124 ) ) ;
memset ( V_2 -> V_91 , 0 , 6 ) ;
V_2 -> V_93 [ 0 ] = 0xFF ;
V_2 -> V_270 = 0 ;
V_2 -> V_271 = V_268 ;
V_2 -> V_272 = V_273 ;
V_2 -> V_85 = V_174 ;
V_2 -> V_274 = 0 ;
V_2 -> V_214 = 0 ;
V_2 -> V_215 = 0 ;
V_2 -> V_48 = 3 ;
V_2 -> V_275 = 1 ;
V_2 -> V_199 = 4 ;
V_2 -> V_276 = 0 ;
V_2 -> V_203 [ 0 ] = '\0' ;
V_2 -> V_205 = 0 ;
V_2 -> V_202 = 0 ;
V_2 -> V_277 = 2346 ;
V_2 -> V_278 = 2347 ;
V_2 -> V_279 = 7 ;
V_2 -> V_280 = 4 ;
V_2 -> V_83 = 0 ;
V_2 -> V_281 = 0 ;
V_2 -> V_282 = 0 ;
V_2 -> V_283 = 0 ;
V_2 -> V_52 = V_2 -> V_56 = V_57 ;
V_2 -> V_45 = 0 ;
memset ( V_2 -> V_284 , 0 , sizeof( V_2 -> V_284 ) ) ;
memset ( V_2 -> V_285 , 0 , sizeof( V_2 -> V_285 ) ) ;
V_2 -> V_286 = V_2 -> V_287 = 100 ;
V_2 -> V_288 = 1 ;
F_81 ( & V_2 -> V_201 ) ;
F_82 ( & V_2 -> V_77 ) ;
F_82 ( & V_2 -> V_76 ) ;
V_2 -> V_201 . V_289 = V_290 ;
V_2 -> V_201 . V_15 = ( unsigned long ) V_13 ;
V_13 -> V_291 = & V_292 ;
V_13 -> V_293 = & V_294 ;
V_13 -> V_153 = V_153 ;
V_13 -> V_14 = V_258 ;
F_83 ( V_13 , V_261 ) ;
if ( ( V_262 = F_84 ( V_13 -> V_153 , F_48 , V_295 , V_13 -> V_170 , V_13 ) ) ) {
F_51 ( V_263 L_33 , V_13 -> V_170 , V_153 , V_262 ) ;
goto V_264;
}
if ( ! F_85 ( V_13 -> V_14 , 32 ,
V_2 -> V_228 == V_229 ? L_34 : L_35 ) ) {
goto V_296;
}
if ( F_86 ( V_13 ) )
goto V_297;
if ( ! F_87 ( V_13 ) ) {
F_88 ( V_13 ) ;
goto V_297;
}
F_89 ( V_13 ) ;
if ( ! F_90 ( L_36 , 0 , NULL , & V_298 , V_2 ) )
F_51 ( V_299 L_37 ) ;
F_51 ( V_180 L_38 ,
V_13 -> V_170 , V_240 , V_241 , V_13 -> V_89 ) ;
return V_13 ;
V_297:
F_91 ( V_13 -> V_14 , 32 ) ;
V_296:
F_92 ( V_13 -> V_153 , V_13 ) ;
V_264:
F_93 ( V_13 ) ;
return NULL ;
}
void F_94 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
F_64 ( & V_2 -> V_201 ) ;
F_88 ( V_13 ) ;
F_95 ( L_36 , NULL ) ;
F_92 ( V_13 -> V_153 , V_13 ) ;
F_96 ( V_2 -> V_247 ) ;
F_91 ( V_13 -> V_14 , 32 ) ;
F_93 ( V_13 ) ;
}
static int F_97 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_302 * V_303 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_303 -> V_68 == 0 ) {
V_2 -> V_274 = 1 ;
} else {
int V_305 = ( V_303 -> V_68 & V_306 ) - 1 ;
V_2 -> V_274 = 0 ;
if ( V_303 -> V_222 > V_307 )
return - V_308 ;
if ( V_305 != 0 )
return - V_192 ;
memcpy ( V_2 -> V_204 , V_304 , V_303 -> V_222 ) ;
V_2 -> V_202 = V_303 -> V_222 ;
}
return - V_309 ;
}
static int F_98 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_302 * V_303 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_202 != 0 ) {
memcpy ( V_304 , V_2 -> V_204 , V_2 -> V_202 ) ;
V_303 -> V_222 = V_2 -> V_202 ;
} else {
memcpy ( V_304 , V_2 -> V_203 , V_2 -> V_205 ) ;
V_303 -> V_222 = V_2 -> V_205 ;
}
V_303 -> V_68 = ! V_2 -> V_274 ;
return 0 ;
}
static int F_99 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_195 * V_310 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
memcpy ( V_310 -> V_197 , V_2 -> V_93 , 6 ) ;
V_310 -> V_224 = V_225 ;
return 0 ;
}
static int F_100 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_302 * V_303 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_303 -> V_222 > 0 ) {
int V_305 = ( V_303 -> V_68 & V_306 ) - 1 ;
int V_311 = V_2 -> V_281 ;
if ( V_303 -> V_222 > 13 ) {
return - V_192 ;
}
if ( V_305 < 0 || V_305 >= 4 )
V_305 = V_311 ;
else
V_2 -> V_281 = V_305 ;
if ( V_303 -> V_222 > 5 )
V_2 -> V_285 [ V_305 ] = 13 ;
else
if ( V_303 -> V_222 > 0 )
V_2 -> V_285 [ V_305 ] = 5 ;
else
V_2 -> V_285 [ V_305 ] = 0 ;
if ( ! ( V_303 -> V_68 & V_312 ) ) {
memset ( V_2 -> V_284 [ V_305 ] , 0 , 13 ) ;
memcpy ( V_2 -> V_284 [ V_305 ] , V_304 , V_303 -> V_222 ) ;
}
if ( V_305 == V_311 &&
V_2 -> V_285 [ V_305 ] > 0 ) {
V_2 -> V_83 = 1 ;
V_2 -> V_283 = 1 ;
if ( V_2 -> V_285 [ V_305 ] > 5 ) {
V_2 -> V_56 = V_54 ;
V_2 -> V_282 = 2 ;
} else {
V_2 -> V_56 = V_53 ;
V_2 -> V_282 = 1 ;
}
}
} else {
int V_305 = ( V_303 -> V_68 & V_306 ) - 1 ;
if ( V_305 >= 0 && V_305 < 4 ) {
V_2 -> V_281 = V_305 ;
} else
if ( ! ( V_303 -> V_68 & V_313 ) )
return - V_192 ;
}
if ( V_303 -> V_68 & V_314 ) {
V_2 -> V_83 = 0 ;
V_2 -> V_282 = 0 ;
V_2 -> V_56 = V_57 ;
} else {
V_2 -> V_83 = 1 ;
if ( V_2 -> V_285 [ V_2 -> V_281 ] > 5 ) {
V_2 -> V_56 = V_54 ;
V_2 -> V_282 = 2 ;
} else {
V_2 -> V_56 = V_53 ;
V_2 -> V_282 = 1 ;
}
}
if ( V_303 -> V_68 & V_315 )
V_2 -> V_283 = 1 ;
if ( V_303 -> V_68 & V_316 )
V_2 -> V_283 = 0 ;
return - V_309 ;
}
static int F_101 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_302 * V_303 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_305 = ( V_303 -> V_68 & V_306 ) - 1 ;
if ( ! V_2 -> V_83 )
V_303 -> V_68 = V_314 ;
else {
if ( V_2 -> V_283 )
V_303 -> V_68 = V_315 ;
else
V_303 -> V_68 = V_316 ;
}
if ( V_305 < 0 || V_305 >= 4 )
V_305 = V_2 -> V_281 ;
V_303 -> V_68 |= V_305 + 1 ;
V_303 -> V_222 = V_2 -> V_285 [ V_305 ] ;
if ( V_303 -> V_222 > 16 ) {
V_303 -> V_222 = 0 ;
} else {
memset ( V_304 , 0 , 16 ) ;
memcpy ( V_304 , V_2 -> V_284 [ V_305 ] , V_303 -> V_222 ) ;
}
return 0 ;
}
static int F_102 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
union V_220 * V_221 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_302 * V_317 = & V_221 -> V_317 ;
struct V_318 * V_319 = (struct V_318 * ) V_304 ;
int V_320 , V_321 , V_322 = V_319 -> V_322 , V_323 = 1 ;
V_320 = V_317 -> V_68 & V_306 ;
if ( V_320 ) {
if ( V_320 < 1 || V_320 > 4 )
return - V_192 ;
V_320 -- ;
} else
V_320 = V_2 -> V_281 ;
if ( V_317 -> V_68 & V_314 )
V_322 = V_324 ;
if ( V_319 -> V_325 & V_326 ) {
V_2 -> V_281 = V_320 ;
V_323 = V_319 -> V_321 > 0 ? 1 : 0 ;
}
if ( V_323 ) {
switch ( V_322 ) {
case V_324 :
V_2 -> V_83 = 0 ;
V_2 -> V_282 = 0 ;
V_2 -> V_56 = V_57 ;
break;
case V_327 :
if ( V_319 -> V_321 > 5 ) {
V_2 -> V_285 [ V_320 ] = 13 ;
V_2 -> V_56 = V_54 ;
V_2 -> V_282 = 2 ;
} else if ( V_319 -> V_321 > 0 ) {
V_2 -> V_285 [ V_320 ] = 5 ;
V_2 -> V_56 = V_53 ;
V_2 -> V_282 = 1 ;
} else {
return - V_192 ;
}
V_2 -> V_83 = 1 ;
memset ( V_2 -> V_284 [ V_320 ] , 0 , 13 ) ;
V_321 = V_231 ( ( int ) V_319 -> V_321 , V_2 -> V_285 [ V_320 ] ) ;
memcpy ( V_2 -> V_284 [ V_320 ] , V_319 -> V_328 , V_321 ) ;
break;
default:
return - V_192 ;
}
}
return - V_309 ;
}
static int F_103 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
union V_220 * V_221 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_302 * V_317 = & V_221 -> V_317 ;
struct V_318 * V_319 = (struct V_318 * ) V_304 ;
int V_320 , V_329 ;
V_329 = V_317 -> V_222 - sizeof( * V_319 ) ;
if ( V_329 < 0 )
return - V_192 ;
V_320 = V_317 -> V_68 & V_306 ;
if ( V_320 ) {
if ( V_320 < 1 || V_320 > 4 )
return - V_192 ;
V_320 -- ;
} else
V_320 = V_2 -> V_281 ;
V_317 -> V_68 = V_320 + 1 ;
memset ( V_319 , 0 , sizeof( * V_319 ) ) ;
if ( ! V_2 -> V_83 ) {
V_319 -> V_322 = V_324 ;
V_319 -> V_321 = 0 ;
V_317 -> V_68 |= V_314 ;
} else {
if ( V_2 -> V_282 > 0 )
V_319 -> V_322 = V_327 ;
else
return - V_192 ;
V_319 -> V_321 = V_2 -> V_285 [ V_320 ] ;
memcpy ( V_319 -> V_328 , V_2 -> V_284 [ V_320 ] , V_319 -> V_321 ) ;
V_317 -> V_68 |= V_330 ;
}
return 0 ;
}
static int F_104 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
union V_220 * V_221 , char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_331 * V_332 = & V_221 -> V_332 ;
switch ( V_332 -> V_68 & V_333 ) {
case V_334 :
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
break;
case V_340 :
V_2 -> V_283 = V_332 -> V_341 ? 1 : 0 ;
break;
case V_342 : {
if ( V_332 -> V_341 & V_343 ) {
V_2 -> V_283 = 1 ;
} else if ( V_332 -> V_341 & V_344 ) {
V_2 -> V_283 = 0 ;
} else
return - V_192 ;
break;
}
case V_345 :
if ( V_332 -> V_341 > 0 )
return - V_346 ;
break;
default:
return - V_346 ;
}
return - V_309 ;
}
static int F_105 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
union V_220 * V_221 , char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_331 * V_332 = & V_221 -> V_332 ;
switch ( V_332 -> V_68 & V_333 ) {
case V_340 :
V_332 -> V_341 = V_2 -> V_283 ;
break;
case V_342 :
if ( V_2 -> V_283 == 1 )
V_332 -> V_341 = V_343 ;
else
V_332 -> V_341 = V_344 ;
break;
case V_345 :
V_332 -> V_341 = 0 ;
break;
default:
return - V_346 ;
}
return 0 ;
}
static int F_106 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
char * V_347 ,
char * V_304 )
{
strcpy ( V_347 , L_39 ) ;
return 0 ;
}
static int F_107 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_348 -> V_349 == 0 ) {
V_2 -> V_48 = 3 ;
V_2 -> V_275 = 1 ;
} else {
V_2 -> V_275 = 0 ;
if ( ( V_348 -> V_341 < 4 ) && ( V_348 -> V_341 >= 0 ) ) {
V_2 -> V_48 = V_348 -> V_341 ;
} else {
switch ( V_348 -> V_341 ) {
case 1000000 :
V_2 -> V_48 = 0 ;
break;
case 2000000 :
V_2 -> V_48 = 1 ;
break;
case 5500000 :
V_2 -> V_48 = 2 ;
break;
case 11000000 :
V_2 -> V_48 = 3 ;
break;
default:
return - V_192 ;
}
}
}
return - V_309 ;
}
static int F_108 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
T_7 * V_350 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( * V_350 != V_86 && * V_350 != V_174 )
return - V_192 ;
V_2 -> V_85 = * V_350 ;
return - V_309 ;
}
static int F_109 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
T_7 * V_350 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
* V_350 = V_2 -> V_85 ;
return 0 ;
}
static int F_110 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_275 ) {
V_348 -> V_349 = 0 ;
V_348 -> V_341 = 11000000 ;
} else {
V_348 -> V_349 = 1 ;
switch ( V_2 -> V_48 ) {
case 0 :
V_348 -> V_341 = 1000000 ;
break;
case 1 :
V_348 -> V_341 = 2000000 ;
break;
case 2 :
V_348 -> V_341 = 5500000 ;
break;
case 3 :
V_348 -> V_341 = 11000000 ;
break;
}
}
return 0 ;
}
static int F_111 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_2 -> V_276 = V_348 -> V_351 ? 0 : 1 ;
return - V_309 ;
}
static int F_112 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_348 -> V_351 = V_2 -> V_276 ? 0 : 1 ;
V_348 -> V_68 = V_352 ;
return 0 ;
}
static int F_113 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( ! V_348 -> V_351 && ( V_348 -> V_68 & V_353 ) ) {
if ( V_348 -> V_68 & V_354 )
V_2 -> V_280 = V_348 -> V_341 ;
else if ( V_348 -> V_68 & V_355 )
V_2 -> V_279 = V_348 -> V_341 ;
else {
V_2 -> V_280 = V_348 -> V_341 ;
V_2 -> V_279 = V_348 -> V_341 ;
}
return - V_309 ;
}
return - V_192 ;
}
static int F_114 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_348 -> V_351 = 0 ;
if ( V_348 -> V_68 & V_354 ) {
V_348 -> V_68 = V_353 | V_354 ;
V_348 -> V_341 = V_2 -> V_280 ;
} else {
V_348 -> V_68 = V_353 ;
V_348 -> V_341 = V_2 -> V_279 ;
if ( V_2 -> V_280 != V_2 -> V_279 )
V_348 -> V_68 |= V_355 ;
}
return 0 ;
}
static int F_115 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_356 = V_348 -> V_341 ;
if ( V_348 -> V_351 )
V_356 = 2347 ;
if ( ( V_356 < 0 ) || ( V_356 > 2347 ) ) {
return - V_192 ;
}
V_2 -> V_278 = V_356 ;
return - V_309 ;
}
static int F_116 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_348 -> V_341 = V_2 -> V_278 ;
V_348 -> V_351 = ( V_348 -> V_341 >= 2347 ) ;
V_348 -> V_349 = 1 ;
return 0 ;
}
static int F_117 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_357 = V_348 -> V_341 ;
if ( V_348 -> V_351 )
V_357 = 2346 ;
if ( ( V_357 < 256 ) || ( V_357 > 2346 ) ) {
return - V_192 ;
}
V_357 &= ~ 0x1 ;
V_2 -> V_277 = V_357 ;
return - V_309 ;
}
static int F_118 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_331 * V_348 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_348 -> V_341 = V_2 -> V_277 ;
V_348 -> V_351 = ( V_348 -> V_341 >= 2346 ) ;
V_348 -> V_349 = 1 ;
return 0 ;
}
static int F_119 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_358 * V_359 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_262 = - V_309 ;
if ( V_359 -> V_360 == 1 ) {
int V_361 = V_359 -> V_234 / 100000 ;
V_359 -> V_360 = 0 ;
V_359 -> V_234 = F_120 ( V_361 ) ;
}
if ( ( V_359 -> V_234 > 1000 ) || ( V_359 -> V_360 > 0 ) )
V_262 = - V_346 ;
else {
int V_199 = V_359 -> V_234 ;
if ( F_68 ( V_2 , V_199 ) == 0 ) {
V_2 -> V_199 = V_199 ;
} else {
V_262 = - V_192 ;
}
}
return V_262 ;
}
static int F_121 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_358 * V_359 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_359 -> V_234 = V_2 -> V_199 ;
V_359 -> V_360 = 0 ;
return 0 ;
}
static int F_122 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_302 * V_303 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
unsigned long V_68 ;
if ( V_2 -> V_74 == V_166 )
return - V_362 ;
if ( F_123 ( V_268 , V_2 -> V_271 + 20 * V_363 ) )
V_2 -> V_212 = V_213 ;
V_2 -> V_271 = V_268 ;
if ( V_2 -> V_212 == V_364 )
return - V_365 ;
F_64 ( & V_2 -> V_201 ) ;
F_27 ( & V_2 -> V_77 , V_68 ) ;
V_2 -> V_212 = V_364 ;
V_2 -> V_366 = 0 ;
F_54 ( V_2 , 0 ) ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
return 0 ;
}
static int F_124 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_302 * V_303 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_18 ;
char * V_367 = V_304 ;
struct V_368 V_369 ;
if ( V_2 -> V_212 != V_370 )
return - V_362 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
V_369 . V_371 = V_227 ;
V_369 . V_372 . V_223 . V_224 = V_225 ;
memcpy ( V_369 . V_372 . V_223 . V_197 , V_2 -> V_373 [ V_18 ] . V_91 , 6 ) ;
V_367 = F_125 ( V_301 , V_367 ,
V_304 + V_374 ,
& V_369 , V_375 ) ;
V_369 . V_372 . V_15 . V_222 = V_2 -> V_373 [ V_18 ] . V_376 ;
if ( V_369 . V_372 . V_15 . V_222 > 32 )
V_369 . V_372 . V_15 . V_222 = 32 ;
V_369 . V_371 = V_377 ;
V_369 . V_372 . V_15 . V_68 = 1 ;
V_367 = F_126 ( V_301 , V_367 ,
V_304 + V_374 ,
& V_369 , V_2 -> V_373 [ V_18 ] . V_203 ) ;
V_369 . V_371 = V_378 ;
V_369 . V_372 . V_379 = V_2 -> V_373 [ V_18 ] . V_380 ;
V_367 = F_125 ( V_301 , V_367 ,
V_304 + V_374 ,
& V_369 , V_381 ) ;
V_369 . V_371 = V_382 ;
V_369 . V_372 . V_383 . V_234 = V_2 -> V_373 [ V_18 ] . V_199 ;
V_369 . V_372 . V_383 . V_360 = 0 ;
V_367 = F_125 ( V_301 , V_367 ,
V_304 + V_374 ,
& V_369 , V_384 ) ;
V_369 . V_371 = V_385 ;
V_369 . V_372 . V_182 . V_183 = V_2 -> V_373 [ V_18 ] . V_386 ;
V_369 . V_372 . V_182 . V_182 = V_369 . V_372 . V_182 . V_183 ;
V_367 = F_125 ( V_301 , V_367 ,
V_304 + V_374 ,
& V_369 , V_387 ) ;
V_369 . V_371 = V_388 ;
if ( V_2 -> V_373 [ V_18 ] . V_389 )
V_369 . V_372 . V_15 . V_68 = V_330 | V_312 ;
else
V_369 . V_372 . V_15 . V_68 = V_314 ;
V_369 . V_372 . V_15 . V_222 = 0 ;
V_367 = F_126 ( V_301 , V_367 ,
V_304 + V_374 ,
& V_369 , NULL ) ;
}
V_303 -> V_222 = ( V_367 - V_304 ) ;
V_303 -> V_68 = 0 ;
return 0 ;
}
static int F_127 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_302 * V_303 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_390 * V_391 = (struct V_390 * ) V_304 ;
int V_392 , V_18 , V_393 ;
V_303 -> V_222 = sizeof( struct V_390 ) ;
memset ( V_391 , 0 , sizeof( struct V_390 ) ) ;
V_391 -> V_394 = 0x0000 ;
V_391 -> V_395 = 0x0000 ;
V_391 -> V_396 = 0 ;
for ( V_393 = 0 ; V_393 < F_53 ( V_218 ) ; V_393 ++ )
if ( V_2 -> V_215 == V_218 [ V_393 ] . V_215 ) {
V_391 -> V_396 = V_218 [ V_393 ] . V_232 - V_218 [ V_393 ] . V_231 + 1 ;
break;
}
if ( V_391 -> V_396 != 0 ) {
for ( V_392 = 0 , V_18 = V_218 [ V_393 ] . V_231 ; V_18 <= V_218 [ V_393 ] . V_232 ; V_18 ++ ) {
V_391 -> V_383 [ V_392 ] . V_18 = V_18 ;
V_391 -> V_383 [ V_392 ] . V_234 = ( F_128 ( V_18 ) *
100000 ) ;
V_391 -> V_383 [ V_392 ++ ] . V_360 = 1 ;
}
V_391 -> V_397 = V_392 ;
}
V_391 -> V_398 . V_182 = 100 ;
V_391 -> V_398 . V_183 = 100 ;
V_391 -> V_398 . V_187 = 0 ;
V_391 -> V_398 . V_184 = V_188 ;
V_391 -> V_399 . V_182 = 50 ;
V_391 -> V_399 . V_183 = 50 ;
V_391 -> V_399 . V_187 = 0 ;
V_391 -> V_399 . V_184 = V_188 ;
V_391 -> V_400 = 0 ;
V_391 -> V_401 [ 0 ] = 1000000 ;
V_391 -> V_401 [ 1 ] = 2000000 ;
V_391 -> V_401 [ 2 ] = 5500000 ;
V_391 -> V_401 [ 3 ] = 11000000 ;
V_391 -> V_402 = 4 ;
V_391 -> V_403 = 0 ;
V_391 -> V_404 = 2347 ;
V_391 -> V_405 = 256 ;
V_391 -> V_406 = 2346 ;
V_391 -> V_407 [ 0 ] = 5 ;
V_391 -> V_407 [ 1 ] = 13 ;
V_391 -> V_408 = 2 ;
V_391 -> V_409 = 4 ;
V_391 -> V_410 = V_352 ;
V_391 -> V_411 = V_352 ;
V_391 -> V_412 = 0 ;
V_391 -> V_413 = V_414 ;
V_391 -> V_415 = V_414 ;
V_391 -> V_416 = V_353 ;
V_391 -> V_417 = V_353 ;
V_391 -> V_418 = 0 ;
V_391 -> V_419 = 1 ;
V_391 -> V_420 = 65535 ;
return 0 ;
}
static int F_129 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
struct V_195 * V_310 ,
char * V_304 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_18 ;
static const T_2 V_421 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
static const T_2 V_422 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned long V_68 ;
if ( V_310 -> V_224 != V_225 )
return - V_192 ;
if ( ! memcmp ( V_421 , V_310 -> V_197 , 6 ) ||
! memcmp ( V_422 , V_310 -> V_197 , 6 ) ) {
F_64 ( & V_2 -> V_201 ) ;
F_27 ( & V_2 -> V_77 , V_68 ) ;
F_54 ( V_2 , 1 ) ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
if ( memcmp ( V_2 -> V_373 [ V_18 ] . V_91 , V_310 -> V_197 , 6 ) == 0 ) {
if ( ! V_2 -> V_83 && V_2 -> V_373 [ V_18 ] . V_389 ) {
return - V_192 ;
} else if ( V_2 -> V_83 && ! V_2 -> V_373 [ V_18 ] . V_389 ) {
return - V_192 ;
} else {
F_64 ( & V_2 -> V_201 ) ;
F_27 ( & V_2 -> V_77 , V_68 ) ;
F_130 ( V_2 , V_18 ) ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
return 0 ;
}
}
}
return - V_192 ;
}
static int F_131 ( struct V_12 * V_13 ,
struct V_300 * V_301 ,
void * V_423 ,
char * V_304 )
{
return F_63 ( V_13 ) ;
}
static int F_132 ( struct V_12 * V_13 , struct V_424 * V_425 , int V_371 )
{
int V_18 , V_262 = 0 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
T_8 V_426 ;
struct V_427 * V_428 = (struct V_427 * ) V_425 ;
unsigned char * V_429 ;
char V_430 [ V_431 + 1 ] ;
switch ( V_371 ) {
case V_432 :
V_428 -> V_372 . V_332 . V_341 = V_433 ;
break;
case V_434 :
if ( F_133 ( & V_426 , V_425 -> V_435 , sizeof( V_426 ) ) ) {
V_262 = - V_436 ;
break;
}
if ( ! F_134 ( V_437 ) ) {
V_262 = - V_438 ;
break;
}
if ( ! ( V_429 = F_135 ( V_426 . V_38 , V_439 ) ) ) {
V_262 = - V_440 ;
break;
}
if ( F_133 ( V_429 , V_426 . V_15 , V_426 . V_38 ) ) {
F_96 ( V_429 ) ;
V_262 = - V_436 ;
break;
}
F_96 ( V_2 -> V_247 ) ;
V_2 -> V_247 = V_429 ;
V_2 -> V_441 = V_426 . V_38 ;
strncpy ( V_2 -> V_248 , V_426 . V_442 , 31 ) ;
V_2 -> V_248 [ 31 ] = '\0' ;
break;
case V_443 :
if ( F_133 ( V_430 , V_425 -> V_435 , V_431 ) ) {
V_262 = - V_436 ;
break;
}
if ( ! F_134 ( V_437 ) ) {
V_262 = - V_438 ;
break;
}
V_430 [ V_431 ] = 0 ;
V_262 = - V_192 ;
for ( V_18 = 0 ; V_18 < F_53 ( V_218 ) ; V_18 ++ ) {
char * V_444 = V_218 [ V_18 ] . V_170 ;
char * V_445 = V_430 ;
while ( * V_444 ) {
char V_446 = * V_444 ++ ;
char V_447 = * V_445 ++ ;
if ( tolower ( V_446 ) != tolower ( V_447 ) )
break;
}
if ( ! * V_444 && ! * V_445 ) {
V_2 -> V_214 = V_218 [ V_18 ] . V_215 ;
V_262 = 0 ;
}
}
if ( V_262 == 0 && V_2 -> V_74 != V_166 )
V_262 = F_63 ( V_13 ) ;
break;
default:
V_262 = - V_346 ;
}
return V_262 ;
}
static void F_55 ( struct V_1 * V_2 , int V_448 )
{
int V_449 = V_2 -> V_74 ;
if ( V_448 == V_449 )
return;
V_2 -> V_74 = V_448 ;
if ( V_448 == V_75 ) {
F_136 ( V_2 -> V_13 ) ;
F_137 ( V_2 -> V_13 ) ;
}
if ( V_449 == V_75 ) {
F_89 ( V_2 -> V_13 ) ;
if ( F_138 ( V_2 -> V_13 ) )
F_30 ( V_2 -> V_13 ) ;
V_2 -> V_269 = 0 ;
}
}
static void F_54 ( struct V_1 * V_2 , int V_450 )
{
struct {
T_2 V_91 [ 6 ] ;
T_2 V_203 [ V_307 ] ;
T_2 V_451 ;
T_2 V_199 ;
T_9 V_452 ;
T_9 V_453 ;
T_9 V_454 ;
T_2 V_455 ;
T_2 V_205 ;
} V_371 ;
memset ( V_371 . V_91 , 0xff , 6 ) ;
if ( V_2 -> V_366 ) {
V_371 . V_205 = V_2 -> V_205 ;
memcpy ( V_371 . V_203 , V_2 -> V_203 , V_2 -> V_205 ) ;
V_371 . V_453 = F_32 ( 10 ) ;
V_371 . V_454 = F_32 ( 50 ) ;
} else {
V_2 -> V_206 = 0 ;
V_371 . V_205 = 0 ;
V_371 . V_453 = F_32 ( 10 ) ;
V_371 . V_454 = F_32 ( 120 ) ;
}
V_371 . V_455 = 0 ;
if ( ! V_450 )
V_371 . V_455 |= V_456 ;
V_371 . V_199 = ( V_2 -> V_199 & 0x7f ) ;
V_371 . V_451 = V_457 ;
V_371 . V_452 = F_32 ( V_2 -> V_85 == V_86 ?
V_458 : V_459 ) ;
F_139 ( V_2 , V_460 , & V_371 , sizeof( V_371 ) ) ;
F_55 ( V_2 , V_251 ) ;
}
static void F_140 ( struct V_1 * V_2 , int type )
{
struct {
T_2 V_91 [ 6 ] ;
T_2 V_203 [ V_307 ] ;
T_2 V_452 ;
T_2 V_199 ;
T_9 V_461 ;
T_2 V_205 ;
T_2 V_462 ;
} V_371 ;
V_371 . V_205 = V_2 -> V_205 ;
memcpy ( V_371 . V_203 , V_2 -> V_203 , V_2 -> V_205 ) ;
memcpy ( V_371 . V_91 , V_2 -> V_93 , 6 ) ;
V_371 . V_199 = ( V_2 -> V_199 & 0x7f ) ;
V_371 . V_452 = type ;
V_371 . V_461 = F_32 ( 2000 ) ;
F_139 ( V_2 , V_463 , & V_371 , sizeof( V_371 ) ) ;
}
static void F_141 ( struct V_1 * V_2 , int type )
{
struct {
T_2 V_91 [ 6 ] ;
T_2 V_203 [ V_307 ] ;
T_2 V_452 ;
T_2 V_199 ;
T_2 V_205 ;
T_2 V_462 [ 3 ] ;
} V_371 ;
V_371 . V_205 = V_2 -> V_205 ;
memcpy ( V_371 . V_203 , V_2 -> V_203 , V_2 -> V_205 ) ;
memcpy ( V_371 . V_91 , V_2 -> V_91 , 6 ) ;
V_371 . V_452 = type ;
V_371 . V_199 = ( V_2 -> V_199 & 0x7f ) ;
F_139 ( V_2 , V_464 , & V_371 , sizeof( V_371 ) ) ;
}
static void F_142 ( struct V_1 * V_2 , T_1 V_465 ,
T_2 V_199 )
{
int V_466 = 0 ;
int V_467 = V_465 & V_468 ?
V_469 : V_273 ;
if ( V_2 -> V_272 != V_467 ) {
V_2 -> V_272 = V_467 ;
V_466 = 1 ;
F_66 ( V_2 , V_470 , V_471 , V_467 ) ;
}
if ( V_2 -> V_199 != V_199 ) {
V_2 -> V_199 = V_199 ;
V_466 = 1 ;
F_66 ( V_2 , V_216 , V_472 , V_199 ) ;
}
if ( V_466 ) {
V_2 -> V_175 = 0 ;
F_55 ( V_2 , V_252 ) ;
if ( V_2 -> V_85 == V_174 )
F_140 ( V_2 , V_459 ) ;
else
F_140 ( V_2 , V_458 ) ;
}
}
static void F_143 ( struct V_1 * V_2 , T_1 system ,
T_2 * V_473 , int V_474 )
{
struct V_66 V_67 ;
struct V_475 V_476 ;
V_67 . V_95 = F_32 ( V_150 | V_477 ) ;
V_67 . V_81 = F_32 ( 0x8000 ) ;
V_67 . V_82 = 0 ;
memcpy ( V_67 . V_87 , V_2 -> V_93 , 6 ) ;
memcpy ( V_67 . V_88 , V_2 -> V_13 -> V_89 , 6 ) ;
memcpy ( V_67 . V_90 , V_2 -> V_93 , 6 ) ;
if ( V_2 -> V_83 && V_2 -> V_210 != 1 )
V_67 . V_95 |= F_32 ( V_84 ) ;
V_476 . V_322 = F_32 ( system ) ;
V_476 . V_23 = 0 ;
V_476 . V_478 = F_32 ( V_2 -> V_210 ) ;
V_2 -> V_211 = V_2 -> V_210 + 1 ;
V_2 -> V_210 += 2 ;
if ( V_474 != 0 ) {
V_476 . V_479 = 16 ;
V_476 . V_480 = V_474 ;
memcpy ( V_476 . V_481 , V_473 , V_474 ) ;
F_34 ( V_2 , & V_67 , ( T_2 * ) & V_476 , 8 + V_474 ) ;
} else {
F_34 ( V_2 , & V_67 , ( T_2 * ) & V_476 , 6 ) ;
}
}
static void F_144 ( struct V_1 * V_2 , int V_482 )
{
T_2 * V_483 ;
int V_484 ;
struct V_66 V_67 ;
struct V_485 {
T_9 V_465 ;
T_9 V_288 ;
T_2 V_486 [ 6 ] ;
T_2 V_487 ;
T_2 V_488 ;
T_2 V_489 [ V_307 ] ;
T_2 V_490 ;
T_2 V_491 ;
T_2 V_492 [ 4 ] ;
} V_98 ;
V_67 . V_95 = F_32 ( V_150 |
( V_482 ? V_493 : V_494 ) ) ;
V_67 . V_81 = F_32 ( 0x8000 ) ;
V_67 . V_82 = 0 ;
memcpy ( V_67 . V_87 , V_2 -> V_93 , 6 ) ;
memcpy ( V_67 . V_88 , V_2 -> V_13 -> V_89 , 6 ) ;
memcpy ( V_67 . V_90 , V_2 -> V_93 , 6 ) ;
V_98 . V_465 = F_32 ( V_495 ) ;
if ( V_2 -> V_83 )
V_98 . V_465 |= F_32 ( V_496 ) ;
if ( V_2 -> V_272 == V_469 )
V_98 . V_465 |= F_32 ( V_468 ) ;
V_98 . V_288 = F_32 ( V_2 -> V_288 * V_2 -> V_287 ) ;
if ( V_482 ) {
memcpy ( V_98 . V_486 , V_2 -> V_93 , 6 ) ;
V_483 = & V_98 . V_487 ;
V_484 = 18 + V_2 -> V_205 ;
} else {
V_483 = & V_98 . V_486 [ 0 ] ;
V_484 = 12 + V_2 -> V_205 ;
}
V_483 [ 0 ] = V_497 ;
V_483 [ 1 ] = V_2 -> V_205 ;
memcpy ( V_483 + 2 , V_2 -> V_203 , V_2 -> V_205 ) ;
V_483 [ 2 + V_2 -> V_205 ] = V_498 ;
V_483 [ 3 + V_2 -> V_205 ] = 4 ;
memcpy ( V_483 + 4 + V_2 -> V_205 , V_499 , 4 ) ;
F_34 ( V_2 , & V_67 , ( void * ) & V_98 , V_484 ) ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
if ( F_41 ( V_67 -> V_95 ) & V_110 )
return memcmp ( V_67 -> V_90 , V_2 -> V_93 , 6 ) == 0 ;
else
return memcmp ( V_67 -> V_88 , V_2 -> V_93 , 6 ) == 0 ;
}
static int F_146 ( struct V_1 * V_2 )
{
int V_18 ;
int V_500 = - 128 ;
int V_501 = - 1 ;
if ( V_2 -> V_206 == 0 )
return - 1 ;
if ( V_2 -> V_274 ) {
V_2 -> V_502 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
if ( V_2 -> V_85 == V_2 -> V_373 [ V_18 ] . V_380 &&
( ( ! V_2 -> V_83 && ! V_2 -> V_373 [ V_18 ] . V_389 ) ||
( V_2 -> V_83 && V_2 -> V_373 [ V_18 ] . V_389 ) ) &&
! ( V_2 -> V_373 [ V_18 ] . V_199 & 0x80 ) ) {
V_500 = V_2 -> V_373 [ V_18 ] . V_386 ;
V_2 -> V_502 = V_501 = V_18 ;
}
}
return V_501 ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
if ( V_2 -> V_205 == V_2 -> V_373 [ V_18 ] . V_376 &&
memcmp ( V_2 -> V_203 , V_2 -> V_373 [ V_18 ] . V_203 , V_2 -> V_205 ) == 0 &&
V_2 -> V_85 == V_2 -> V_373 [ V_18 ] . V_380 &&
F_68 ( V_2 , V_2 -> V_373 [ V_18 ] . V_199 ) == 0 ) {
if ( V_2 -> V_373 [ V_18 ] . V_386 >= V_500 ) {
V_500 = V_2 -> V_373 [ V_18 ] . V_386 ;
V_501 = V_18 ;
}
}
}
return V_501 ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_66 * V_67 , T_1 V_465 ,
T_1 V_287 , T_2 V_199 , T_2 V_503 , T_2 V_488 ,
T_2 * V_489 , int V_504 )
{
T_2 * V_505 = V_465 & V_495 ? V_67 -> V_88 : V_67 -> V_90 ;
int V_18 , V_305 ;
for ( V_305 = - 1 , V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ )
if ( memcmp ( V_505 , V_2 -> V_373 [ V_18 ] . V_91 , 6 ) == 0 )
V_305 = V_18 ;
if ( V_305 == - 1 ) {
if ( V_2 -> V_206 == V_506 )
return;
V_305 = V_2 -> V_206 ++ ;
memcpy ( V_2 -> V_373 [ V_305 ] . V_91 , V_505 , 6 ) ;
V_2 -> V_373 [ V_305 ] . V_386 = V_503 ;
} else {
if ( V_503 > V_2 -> V_373 [ V_305 ] . V_386 )
V_2 -> V_373 [ V_305 ] . V_386 = V_503 ;
if ( V_504 )
return;
}
V_2 -> V_373 [ V_305 ] . V_199 = V_199 ;
V_2 -> V_373 [ V_305 ] . V_287 = V_287 ;
V_2 -> V_373 [ V_305 ] . V_389 = V_465 & V_496 ;
memcpy ( V_2 -> V_373 [ V_305 ] . V_203 , V_489 , V_488 ) ;
V_2 -> V_373 [ V_305 ] . V_376 = V_488 ;
if ( V_465 & V_507 )
V_2 -> V_373 [ V_305 ] . V_380 = V_86 ;
else if ( V_465 & V_495 )
V_2 -> V_373 [ V_305 ] . V_380 = V_174 ;
V_2 -> V_373 [ V_305 ] . V_272 = V_465 & V_468 ?
V_469 : V_273 ;
}
static void F_148 ( struct V_1 * V_2 , T_1 V_508 )
{
struct V_475 * V_476 = (struct V_475 * ) V_2 -> V_125 ;
T_1 V_23 = F_41 ( V_476 -> V_23 ) ;
T_1 V_509 = F_41 ( V_476 -> V_478 ) ;
T_1 system = F_41 ( V_476 -> V_322 ) ;
if ( V_23 == V_510 && ! V_2 -> V_83 ) {
if ( V_2 -> V_270 ) {
F_55 ( V_2 , V_255 ) ;
F_144 ( V_2 , 1 ) ;
return;
} else {
F_55 ( V_2 , V_254 ) ;
F_144 ( V_2 , 0 ) ;
return;
}
}
if ( V_23 == V_510 && V_2 -> V_83 ) {
int V_511 = 0 ;
if ( V_509 != V_2 -> V_211 )
return;
if ( system == V_512 ) {
if ( V_509 == 0x0002 ) {
V_511 = 1 ;
}
} else if ( system == V_513 ) {
if ( V_509 == 0x0002 &&
V_476 -> V_479 == V_514 ) {
F_143 ( V_2 , system , V_476 -> V_481 , V_476 -> V_480 ) ;
return;
} else if ( V_509 == 0x0004 ) {
V_511 = 1 ;
}
}
if ( V_511 ) {
if ( V_2 -> V_270 ) {
F_55 ( V_2 , V_255 ) ;
F_144 ( V_2 , 1 ) ;
return;
} else {
F_55 ( V_2 , V_254 ) ;
F_144 ( V_2 , 0 ) ;
return;
}
}
}
if ( V_23 == V_515 ) {
if ( system == V_512 ) {
V_2 -> V_210 = 0x001 ;
V_2 -> V_283 = 1 ;
F_143 ( V_2 , V_513 , NULL , 0 ) ;
return;
} else if ( system == V_513
&& V_2 -> V_83 ) {
V_2 -> V_210 = 0x001 ;
V_2 -> V_283 = 0 ;
F_143 ( V_2 , V_512 , NULL , 0 ) ;
return;
} else if ( V_2 -> V_274 ) {
int V_516 ;
V_2 -> V_373 [ ( int ) ( V_2 -> V_502 ) ] . V_199 |= 0x80 ;
if ( ( V_516 = F_146 ( V_2 ) ) != - 1 ) {
F_130 ( V_2 , V_516 ) ;
return;
}
}
}
V_2 -> V_207 = 0 ;
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
}
static void F_149 ( struct V_1 * V_2 , T_1 V_508 , T_1 V_517 )
{
struct V_518 {
T_9 V_465 ;
T_9 V_23 ;
T_9 V_519 ;
T_2 V_479 ;
T_2 V_222 ;
T_2 V_492 [ 4 ] ;
} * V_520 = (struct V_518 * ) V_2 -> V_125 ;
T_1 V_23 = F_41 ( V_520 -> V_23 ) ;
T_1 V_519 = F_41 ( V_520 -> V_519 ) ;
T_1 V_521 = V_520 -> V_222 > 4 ? 4 : V_520 -> V_222 ;
union V_220 V_221 ;
if ( V_508 < 8 + V_521 )
return;
if ( V_23 == V_510 ) {
if ( V_517 == V_522 )
V_2 -> V_208 = 0 ;
else
V_2 -> V_209 = 0 ;
F_150 ( V_2 , V_178 ,
V_523 , V_519 & 0x3fff ) ;
F_151 ( V_2 , V_216 ,
V_524 , V_520 -> V_492 , V_521 ) ;
if ( V_2 -> V_276 == 0 ) {
V_2 -> V_288 = 1 ;
F_66 ( V_2 , V_178 ,
V_525 , V_526 ) ;
F_150 ( V_2 , V_178 ,
V_527 , 1 ) ;
} else {
V_2 -> V_288 = 2 ;
F_66 ( V_2 , V_178 ,
V_525 , V_528 ) ;
F_150 ( V_2 , V_178 ,
V_527 , 2 ) ;
}
V_2 -> V_175 = 1 ;
V_2 -> V_270 = 1 ;
F_55 ( V_2 , V_75 ) ;
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
memcpy ( V_221 . V_223 . V_197 , V_2 -> V_93 , V_226 ) ;
V_221 . V_223 . V_224 = V_225 ;
F_70 ( V_2 -> V_13 , V_227 , & V_221 , NULL ) ;
return;
}
if ( V_517 == V_522 &&
V_23 != V_529 &&
V_23 != V_530 &&
V_2 -> V_208 < V_531 ) {
F_152 ( & V_2 -> V_201 , V_268 + V_532 ) ;
V_2 -> V_208 ++ ;
F_144 ( V_2 , 0 ) ;
return;
}
if ( V_517 == V_533 &&
V_23 != V_529 &&
V_23 != V_530 &&
V_2 -> V_208 < V_531 ) {
F_152 ( & V_2 -> V_201 , V_268 + V_532 ) ;
V_2 -> V_209 ++ ;
F_144 ( V_2 , 1 ) ;
return;
}
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
if ( V_2 -> V_274 ) {
int V_516 ;
V_2 -> V_373 [ ( int ) ( V_2 -> V_502 ) ] . V_199 |= 0x80 ;
if ( ( V_516 = F_146 ( V_2 ) ) != - 1 )
F_130 ( V_2 , V_516 ) ;
}
}
static void F_130 ( struct V_1 * V_2 , int V_516 )
{
struct V_534 * V_505 = & V_2 -> V_373 [ V_516 ] ;
memcpy ( V_2 -> V_93 , V_505 -> V_91 , 6 ) ;
memcpy ( V_2 -> V_203 , V_505 -> V_203 , V_2 -> V_205 = V_505 -> V_376 ) ;
if ( V_2 -> V_45 )
F_58 ( V_2 ) ;
if ( V_505 -> V_380 == V_86 &&
V_2 -> V_85 != V_86 &&
V_2 -> V_276 ) {
V_2 -> V_276 = 0 ;
V_2 -> V_288 = 1 ;
F_66 ( V_2 , V_178 ,
V_525 , V_526 ) ;
F_150 ( V_2 , V_178 ,
V_527 , 1 ) ;
}
V_2 -> V_85 = V_505 -> V_380 ;
V_2 -> V_199 = V_505 -> V_199 & 0x7f ;
V_2 -> V_287 = V_505 -> V_287 ;
if ( V_2 -> V_272 != V_505 -> V_272 ) {
V_2 -> V_272 = V_505 -> V_272 ;
F_66 ( V_2 , V_470 ,
V_471 , V_505 -> V_272 ) ;
}
if ( ! V_2 -> V_83 && V_505 -> V_389 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
return;
}
if ( V_2 -> V_83 && ! V_505 -> V_389 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
return;
}
F_55 ( V_2 , V_252 ) ;
if ( V_2 -> V_85 == V_174 )
F_140 ( V_2 , V_459 ) ;
else
F_140 ( V_2 , V_458 ) ;
}
static void F_153 ( struct V_1 * V_2 )
{
int V_516 ;
if ( ! V_2 -> V_274 ) {
F_54 ( V_2 , 1 ) ;
} else {
V_2 -> V_373 [ ( int ) ( V_2 -> V_502 ) ] . V_199 |= 0x80 ;
if ( ( V_516 = F_146 ( V_2 ) ) != - 1 )
F_130 ( V_2 , V_516 ) ;
else
F_54 ( V_2 , 0 ) ;
}
}
static void F_154 ( struct V_1 * V_2 , T_2 V_503 )
{
T_2 V_535 = V_2 -> V_126 . V_182 . V_183 ;
T_2 V_500 = 42 ;
switch ( V_2 -> V_265 ) {
case V_536 :
V_500 = 63 ;
break;
default:
break;
}
V_503 = V_503 * 100 / V_500 ;
if ( ( V_503 + V_535 ) % 2 )
V_2 -> V_126 . V_182 . V_183 = ( V_503 + V_535 ) / 2 + 1 ;
else
V_2 -> V_126 . V_182 . V_183 = ( V_503 + V_535 ) / 2 ;
V_2 -> V_126 . V_182 . V_184 |= V_537 ;
V_2 -> V_126 . V_182 . V_184 &= ~ V_186 ;
}
static void F_60 ( struct V_1 * V_2 )
{
unsigned long V_538 = ( V_268 - V_2 -> V_267 ) / V_363 ;
while ( V_538 -- ) {
V_2 -> V_267 += V_363 ;
V_2 -> V_126 . V_182 . V_182 = V_2 -> V_126 . V_182 . V_182 / 2 ;
V_2 -> V_126 . V_182 . V_182 +=
V_2 -> V_539 * V_2 -> V_287 * ( V_2 -> V_126 . V_182 . V_183 + 100 ) / 4000 ;
V_2 -> V_539 = 0 ;
}
V_2 -> V_126 . V_182 . V_184 |= V_540 ;
V_2 -> V_126 . V_182 . V_184 &= ~ V_185 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
T_1 V_508 , T_2 V_503 )
{
T_1 V_517 ;
V_517 = F_41 ( V_67 -> V_95 ) & V_541 ;
switch ( V_517 ) {
case V_542 :
case V_543 :
{
struct V_544 {
T_10 V_545 ;
T_9 V_546 ;
T_9 V_465 ;
T_2 V_487 ;
T_2 V_547 ;
T_2 V_548 ;
T_2 V_549 ;
T_2 V_550 ;
T_2 V_551 ;
} * V_190 = (struct V_544 * ) V_2 -> V_125 ;
T_2 V_199 , V_549 , V_547 ;
T_11 V_545 = F_155 ( V_190 -> V_545 ) ;
T_1 V_552 = F_41 ( V_190 -> V_546 ) ;
T_1 V_465 = F_41 ( V_190 -> V_465 ) ;
T_2 * V_553 = V_2 -> V_125 ;
V_547 = V_190 -> V_547 ;
if ( V_508 < 14 || V_508 < V_547 + 15 )
return;
V_549 = V_553 [ V_190 -> V_547 + 15 ] ;
if ( V_508 < V_547 + V_549 + 18 )
return;
if ( V_547 > V_307 )
return;
V_199 = V_553 [ V_547 + V_549 + 18 ] ;
if ( V_2 -> V_74 == V_75 ) {
F_154 ( V_2 , V_503 ) ;
if ( F_145 ( V_2 , V_67 ) ) {
V_2 -> V_539 ++ ;
F_60 ( V_2 ) ;
if ( V_2 -> V_269 ) {
T_4 V_554 = V_545 - V_2 -> V_269 ;
int V_555 = V_554 / ( V_552 * 1000 ) ;
if ( V_555 > 1 )
V_2 -> V_126 . V_189 . V_190 += V_555 - 1 ;
}
V_2 -> V_269 = V_545 ;
F_142 ( V_2 , V_465 , V_199 ) ;
}
}
if ( V_2 -> V_74 == V_251 )
F_147 ( V_2 , V_67 , V_465 ,
V_552 , V_199 , V_503 ,
V_547 ,
& V_190 -> V_548 ,
V_517 == V_542 ) ;
}
break;
case V_477 :
if ( V_2 -> V_74 == V_253 )
F_148 ( V_2 , V_508 ) ;
break;
case V_522 :
case V_533 :
if ( V_2 -> V_74 == V_254 ||
V_2 -> V_74 == V_255 )
F_149 ( V_2 , V_508 , V_517 ) ;
break;
case V_556 :
if ( V_2 -> V_175 &&
V_2 -> V_85 == V_174 &&
F_145 ( V_2 , V_67 ) ) {
V_2 -> V_270 = 0 ;
V_2 -> V_175 = 0 ;
F_55 ( V_2 , V_252 ) ;
F_140 ( V_2 , V_459 ) ;
}
break;
case V_557 :
if ( V_2 -> V_85 == V_174 &&
F_145 ( V_2 , V_67 ) ) {
V_2 -> V_270 = 0 ;
F_55 ( V_2 , V_252 ) ;
F_140 ( V_2 , V_459 ) ;
}
break;
}
}
static void V_290 ( T_12 V_444 )
{
struct V_12 * V_13 = (struct V_12 * ) V_444 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
unsigned long V_68 ;
if ( V_2 -> V_71 && V_2 -> V_72 &&
! (* V_2 -> V_72 )( V_2 -> V_71 ) )
return;
F_27 ( & V_2 -> V_77 , V_68 ) ;
switch ( V_2 -> V_74 ) {
case V_253 :
if ( V_2 -> V_207 >= V_558 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
V_2 -> V_207 = 0 ;
F_153 ( V_2 ) ;
} else {
int V_476 = V_512 ;
V_2 -> V_207 ++ ;
V_2 -> V_210 = 0x0001 ;
F_152 ( & V_2 -> V_201 , V_268 + V_532 ) ;
if ( V_2 -> V_83 && V_2 -> V_283 )
V_476 = V_513 ;
F_143 ( V_2 , V_476 , NULL , 0 ) ;
}
break;
case V_254 :
if ( V_2 -> V_208 == V_531 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
V_2 -> V_208 = 0 ;
F_153 ( V_2 ) ;
} else {
V_2 -> V_208 ++ ;
F_152 ( & V_2 -> V_201 , V_268 + V_532 ) ;
F_144 ( V_2 , 0 ) ;
}
break;
case V_255 :
if ( V_2 -> V_209 == V_531 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
V_2 -> V_209 = 0 ;
F_153 ( V_2 ) ;
} else {
V_2 -> V_209 ++ ;
F_152 ( & V_2 -> V_201 , V_268 + V_532 ) ;
F_144 ( V_2 , 1 ) ;
}
break;
default:
break;
}
F_28 ( & V_2 -> V_77 , V_68 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_2 V_23 = F_13 ( V_2 , F_2 ( V_2 , V_559 ) ) ;
T_2 V_560 = F_13 ( V_2 , F_2 ( V_2 , V_561 ) ) ;
int V_366 ;
union V_220 V_221 ;
if ( V_23 == V_562 ||
V_23 == V_563 )
return;
switch ( V_560 ) {
case V_464 :
if ( V_23 == V_564 ) {
V_2 -> V_270 = V_2 -> V_175 ;
F_57 ( V_2 , V_178 , V_179 ,
( T_2 * ) V_2 -> V_93 , 6 ) ;
F_55 ( V_2 , V_75 ) ;
}
break;
case V_460 :
V_366 = V_2 -> V_366 ;
V_2 -> V_366 = 0 ;
if ( V_23 != V_564 ) {
F_54 ( V_2 , 1 ) ;
} else {
int V_516 = F_146 ( V_2 ) ;
int V_565 = 1 ;
if ( V_516 != - 1 ) {
F_130 ( V_2 , V_516 ) ;
} else if ( V_2 -> V_85 == V_86 &&
V_2 -> V_205 != 0 ) {
F_141 ( V_2 , V_458 ) ;
} else {
V_2 -> V_366 = ! V_366 ;
F_54 ( V_2 , 1 ) ;
V_565 = 0 ;
}
V_2 -> V_212 = V_370 ;
if ( V_565 ) {
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
F_70 ( V_2 -> V_13 , V_566 , & V_221 , NULL ) ;
}
}
break;
case V_567 :
V_2 -> V_366 = 0 ;
if ( V_23 != V_564 )
return;
V_2 -> V_212 = V_370 ;
if ( V_2 -> V_175 ) {
F_55 ( V_2 , V_75 ) ;
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
F_70 ( V_2 -> V_13 , V_566 , & V_221 , NULL ) ;
} else {
F_54 ( V_2 , 1 ) ;
}
break;
case V_463 :
if ( V_23 == V_564 ) {
if ( V_2 -> V_85 == V_86 ) {
V_2 -> V_270 = V_2 -> V_175 ;
F_55 ( V_2 , V_75 ) ;
} else {
int V_476 = V_512 ;
V_2 -> V_207 = 0 ;
F_55 ( V_2 , V_253 ) ;
F_152 ( & V_2 -> V_201 , V_268 + V_532 ) ;
V_2 -> V_210 = 0x0001 ;
if ( V_2 -> V_83 && V_2 -> V_283 )
V_476 = V_513 ;
F_143 ( V_2 , V_476 , NULL , 0 ) ;
}
return;
}
F_54 ( V_2 , 1 ) ;
}
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_568 * V_569 = & V_2 -> V_5 ;
T_1 V_570 , V_571 ;
int V_18 ;
if ( V_2 -> V_245 == V_250 )
F_52 ( V_2 -> V_13 , V_572 ) ;
F_49 ( V_2 -> V_13 , 0x0040 ) ;
F_11 ( V_2 -> V_13 , V_573 , V_574 ) ;
if ( V_2 -> V_245 == V_250 )
F_157 ( 100 ) ;
for ( V_18 = V_575 ; V_18 ; V_18 -- ) {
V_570 = F_9 ( V_2 -> V_13 , V_576 ) ;
V_571 = F_9 ( V_2 -> V_13 , V_577 ) ;
if ( V_571 & V_578 )
break;
if ( V_570 & V_578 &&
V_2 -> V_228 == V_229 )
break;
}
if ( V_18 == 0 ) {
F_51 ( V_169 L_40 , V_2 -> V_13 -> V_170 ) ;
return - V_579 ;
}
if ( ( V_2 -> V_4 = F_9 ( V_2 -> V_13 , V_580 ) ) == 0xffff ) {
F_51 ( V_169 L_41 , V_2 -> V_13 -> V_170 ) ;
return - V_581 ;
}
F_15 ( V_2 , F_1 ( V_2 , V_582 ) , V_583 ) ;
for ( V_18 = V_575 ; V_18 ; V_18 -- ) {
V_570 = F_9 ( V_2 -> V_13 , V_576 ) ;
V_571 = F_9 ( V_2 -> V_13 , V_577 ) ;
if ( V_571 & V_584 )
break;
if ( V_570 & V_584 &&
V_2 -> V_228 == V_229 )
break;
}
if ( V_18 == 0 ) {
F_51 ( V_169 L_42 ,
V_2 -> V_13 -> V_170 ) ;
return - V_579 ;
}
if ( ( V_571 & V_584 ) &&
! ( F_9 ( V_2 -> V_13 , V_577 ) & V_585 ) ) {
F_51 ( V_169 L_43 , V_2 -> V_13 -> V_170 ) ;
return - V_579 ;
}
if ( ( V_570 & V_584 ) &&
! ( F_9 ( V_2 -> V_13 , V_576 ) & V_585 ) ) {
F_51 ( V_169 L_44 , V_2 -> V_13 -> V_170 ) ;
return - V_579 ;
}
F_36 ( V_2 -> V_13 , ( unsigned char * ) V_569 ,
V_2 -> V_4 , sizeof( * V_569 ) ) ;
V_569 -> V_31 = F_41 ( V_569 -> V_31 ) ;
V_569 -> V_32 = F_41 ( V_569 -> V_32 ) ;
V_569 -> V_10 = F_41 ( V_569 -> V_10 ) ;
V_569 -> V_22 = F_41 ( V_569 -> V_22 ) ;
V_569 -> V_586 = F_41 ( V_569 -> V_586 ) ;
V_569 -> V_587 = F_41 ( V_569 -> V_587 ) ;
V_569 -> V_8 = F_41 ( V_569 -> V_8 ) ;
V_569 -> V_132 = F_41 ( V_569 -> V_132 ) ;
V_569 -> V_244 = F_41 ( V_569 -> V_244 ) ;
V_569 -> V_6 = F_41 ( V_569 -> V_6 ) ;
V_569 -> V_242 = F_41 ( V_569 -> V_242 ) ;
V_569 -> V_243 = F_41 ( V_569 -> V_243 ) ;
V_569 -> V_588 = F_41 ( V_569 -> V_588 ) ;
V_569 -> V_589 = F_41 ( V_569 -> V_589 ) ;
return 0 ;
}
static int F_87 ( struct V_12 * V_13 )
{
int V_262 = 0 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
F_157 ( 500 ) ;
if ( F_9 ( V_13 , V_580 ) == 0 ) {
int V_18 ;
V_2 -> V_245 = V_246 ;
F_11 ( V_13 , V_573 , V_590 ) ;
F_33 ( V_13 , 0 , V_591 , sizeof( V_591 ) ) ;
F_52 ( V_13 , V_572 ) ;
F_49 ( V_2 -> V_13 , 0x0040 ) ;
F_11 ( V_13 , V_573 , V_574 ) ;
for ( V_18 = V_575 ; V_18 ; V_18 -- )
if ( F_9 ( V_13 , V_577 ) & V_578 )
break;
if ( V_18 == 0 ) {
F_51 ( V_169 L_45 , V_13 -> V_170 ) ;
} else {
F_36 ( V_13 , V_13 -> V_89 , F_9 ( V_13 , V_580 ) , 6 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
V_262 = 1 ;
}
} else if ( F_9 ( V_13 , V_592 ) == 0 ) {
V_2 -> V_245 = V_249 ;
F_11 ( V_13 , V_573 , 1 ) ;
F_36 ( V_13 , V_13 -> V_89 , 0xc000 , 6 ) ;
F_11 ( V_13 , V_573 , 0x200 ) ;
V_262 = 1 ;
} else {
V_2 -> V_245 = V_250 ;
if ( F_156 ( V_2 ) == 0 ) {
F_57 ( V_2 , V_593 , 0 , V_13 -> V_89 , 6 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
V_262 = 1 ;
}
}
if ( V_262 ) {
if ( V_13 -> V_89 [ 0 ] == 0xFF ) {
static const T_2 V_594 [] = {
0x00 , 0x04 , 0x25 , 0x00 , 0x00 , 0x00
} ;
F_51 ( V_169 L_46 , V_13 -> V_170 ) ;
memcpy ( V_13 -> V_89 , V_594 , 6 ) ;
}
}
return V_262 ;
}
static void F_158 ( struct V_1 * V_2 )
{
struct {
T_2 V_83 ;
T_2 V_281 ;
T_2 V_462 ;
T_2 V_283 ;
T_4 V_595 ;
T_4 V_596 ;
T_2 V_284 [ V_597 ] [ 13 ] ;
T_2 V_282 ;
T_2 V_598 [ 3 ] ;
} V_599 ;
int V_18 ;
V_599 . V_83 = V_2 -> V_83 ;
if ( V_2 -> V_83 ) {
if ( V_2 -> V_285 [ V_2 -> V_281 ] > 5 )
V_599 . V_282 = 2 ;
else
V_599 . V_282 = 1 ;
} else {
V_599 . V_282 = 0 ;
}
V_599 . V_281 = V_2 -> V_281 ;
V_599 . V_283 = V_2 -> V_283 ;
for ( V_18 = 0 ; V_18 < V_597 ; V_18 ++ )
memcpy ( V_599 . V_284 [ V_18 ] , V_2 -> V_284 [ V_18 ] , 13 ) ;
F_151 ( V_2 , V_600 , 0 , ( T_2 * ) & V_599 , sizeof( V_599 ) ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct {
T_2 V_601 [ V_597 ] [ V_602 ] ;
T_2 V_603 [ 6 ] ;
T_2 V_83 ;
T_2 V_281 ;
T_2 V_604 ;
T_2 V_283 ;
T_2 V_605 ;
T_2 V_462 ;
T_4 V_595 ;
T_4 V_596 ;
T_2 V_606 [ 4 ] [ 8 ] ;
} V_599 ;
int V_18 ;
V_599 . V_83 = V_2 -> V_83 ;
V_599 . V_283 = V_2 -> V_283 ;
memcpy ( V_599 . V_603 , V_2 -> V_93 , 6 ) ;
memset ( V_599 . V_601 , 0 , sizeof( V_599 . V_601 ) ) ;
if ( V_2 -> V_83 ) {
memset ( V_599 . V_606 , 0 , sizeof( V_599 . V_606 ) ) ;
V_599 . V_281 = V_599 . V_604 = 255 ;
for ( V_18 = 0 ; V_18 < V_597 ; V_18 ++ ) {
if ( V_2 -> V_285 [ V_18 ] > 0 ) {
memcpy ( V_599 . V_601 [ V_18 ] , V_2 -> V_284 [ V_18 ] , V_602 ) ;
if ( V_18 == V_2 -> V_281 ) {
V_599 . V_281 = V_18 ;
V_599 . V_601 [ V_18 ] [ V_602 - 1 ] = 7 ;
V_599 . V_601 [ V_18 ] [ V_602 - 2 ] = V_2 -> V_56 ;
} else {
V_599 . V_604 = V_18 ;
V_2 -> V_52 = V_2 -> V_56 ;
V_599 . V_601 [ V_18 ] [ V_602 - 1 ] = 1 ;
V_599 . V_601 [ V_18 ] [ V_602 - 2 ] = V_2 -> V_52 ;
}
}
}
if ( V_599 . V_281 == 255 )
V_599 . V_281 = V_599 . V_604 != 255 ? V_599 . V_604 : 0 ;
if ( V_599 . V_604 == 255 )
V_599 . V_604 = V_599 . V_281 ;
}
F_151 ( V_2 , V_600 , 0 , ( T_2 * ) & V_599 , sizeof( V_599 ) ) ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
T_2 V_607 ;
int V_449 = V_2 -> V_74 ;
int V_200 = 0 ;
static char * V_608 [] = {
L_47 ,
L_48 ,
NULL
} ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_2 -> V_13 , V_230 , 0x0060 ) ;
F_11 ( V_2 -> V_13 , V_230 , 0x0040 ) ;
if ( V_2 -> V_245 == V_246 ) {
const struct V_247 * V_609 = NULL ;
const unsigned char * V_610 ;
int V_38 = V_2 -> V_441 ;
if ( ! ( V_610 = V_2 -> V_247 ) ) {
if ( V_2 -> V_265 == V_611 ) {
if ( strlen ( V_2 -> V_248 ) == 0 ) {
F_51 ( V_180
L_49 ,
V_13 -> V_170 ) ;
F_51 ( V_180
L_50 ,
V_13 -> V_170 ) ;
strcpy ( V_2 -> V_248 , L_51 ) ;
}
V_200 = F_159 ( & V_609 , V_2 -> V_248 , V_2 -> V_261 ) ;
if ( V_200 != 0 ) {
F_51 ( V_169
L_52 ,
V_13 -> V_170 , V_2 -> V_248 ) ;
return V_200 ;
}
} else {
int V_612 = 0 ;
int V_613 = 0 ;
while ( V_614 [ V_612 ] . V_259 != V_2 -> V_265
&& V_614 [ V_612 ] . V_259 != V_611 )
V_612 ++ ;
if ( V_614 [ V_612 ] . V_259 != V_611 ) {
int V_18 ;
for ( V_18 = 0 ; V_608 [ V_18 ] ; V_18 ++ ) {
snprintf ( V_2 -> V_248 , 32 , L_53 , V_614 [ V_612 ] . V_615 ,
V_608 [ V_18 ] , V_614 [ V_612 ] . V_616 ) ;
V_2 -> V_248 [ 31 ] = '\0' ;
if ( F_159 ( & V_609 , V_2 -> V_248 , V_2 -> V_261 ) == 0 ) {
V_613 = 1 ;
break;
}
}
}
if ( ! V_613 ) {
F_51 ( V_169
L_54 ,
V_13 -> V_170 , V_2 -> V_248 ) ;
V_2 -> V_248 [ 0 ] = '\0' ;
return - V_617 ;
}
}
V_610 = V_609 -> V_15 ;
V_38 = V_609 -> V_618 ;
}
if ( V_38 <= 0x6000 ) {
F_11 ( V_2 -> V_13 , V_573 , V_590 ) ;
F_33 ( V_2 -> V_13 , 0 , V_610 , V_38 ) ;
F_52 ( V_2 -> V_13 , V_572 ) ;
} else {
F_52 ( V_2 -> V_13 , V_572 ) ;
F_11 ( V_2 -> V_13 , V_573 , V_590 ) ;
F_33 ( V_2 -> V_13 , 0 , V_610 , 0x6000 ) ;
F_11 ( V_2 -> V_13 , V_573 , 0x2ff ) ;
F_33 ( V_2 -> V_13 , 0x8000 , & V_610 [ 0x6000 ] , V_38 - 0x6000 ) ;
}
F_160 ( V_609 ) ;
}
V_200 = F_156 ( V_2 ) ;
if ( V_200 != 0 )
return V_200 ;
V_2 -> V_45 = ( V_2 -> V_5 . V_242 == 4 ) ;
V_2 -> V_619 = ( V_2 -> V_5 . V_242 == 5 ) ;
F_15 ( V_2 , F_1 ( V_2 , V_620 ) , 0xff ) ;
F_15 ( V_2 , F_4 ( V_2 , V_19 , 0 ) , 0 ) ;
F_22 ( V_2 , F_4 ( V_2 , V_60 , 0 ) , 0x80000000L ) ;
F_17 ( V_2 , F_4 ( V_2 , V_43 , 0 ) , 0 ) ;
F_17 ( V_2 , F_4 ( V_2 , V_26 , 0 ) , 0 ) ;
V_2 -> V_29 = V_2 -> V_5 . V_22 ;
V_2 -> V_20 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_62 = 0 ;
V_2 -> V_28 = V_2 -> V_5 . V_32 ;
V_2 -> V_30 = 0 ;
V_2 -> V_40 = 0 ;
V_607 = F_13 ( V_2 , F_1 ( V_2 , V_582 ) ) ;
F_15 ( V_2 , F_1 ( V_2 , V_582 ) ,
V_607 | V_621 ) ;
V_2 -> V_130 = 0 ;
V_607 = F_13 ( V_2 , F_1 ( V_2 , V_582 ) ) ;
F_15 ( V_2 , F_1 ( V_2 , V_582 ) ,
V_607 | V_622 ) ;
if ( ! V_2 -> V_619 ) {
if ( F_161 ( V_2 , V_623 , NULL , 0 ) ==
V_624 ) {
F_51 ( V_180 L_55 ,
V_13 -> V_170 ) ;
return - V_579 ;
}
}
F_66 ( V_2 , V_470 , V_625 , V_2 -> V_275 ) ;
F_66 ( V_2 , V_470 , V_626 , V_627 ) ;
F_150 ( V_2 , V_628 , V_629 , V_2 -> V_278 ) ;
F_150 ( V_2 , V_628 , V_630 , V_2 -> V_277 ) ;
F_66 ( V_2 , V_628 , V_631 , V_2 -> V_279 ) ;
F_66 ( V_2 , V_628 , V_632 , V_2 -> V_280 ) ;
F_66 ( V_2 , V_470 , V_471 , V_2 -> V_272 ) ;
F_151 ( V_2 , V_593 , V_633 ,
V_2 -> V_13 -> V_89 , 6 ) ;
F_66 ( V_2 , V_178 , V_525 , V_526 ) ;
F_150 ( V_2 , V_178 , V_527 , 1 ) ;
F_150 ( V_2 , V_178 , V_634 , V_2 -> V_286 ) ;
F_151 ( V_2 , V_216 , V_524 , V_499 , 4 ) ;
F_66 ( V_2 , V_178 , V_635 , V_2 -> V_83 ) ;
if ( V_2 -> V_45 )
F_58 ( V_2 ) ;
else
F_158 ( V_2 ) ;
if ( V_449 == V_75 ) {
union V_220 V_221 ;
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
V_221 . V_223 . V_224 = V_225 ;
memset ( V_221 . V_223 . V_197 , 0 , V_226 ) ;
F_70 ( V_2 -> V_13 , V_227 , & V_221 , NULL ) ;
}
return 0 ;
}
static void F_139 ( struct V_1 * V_2 , int V_560 ,
void * V_371 , int V_636 )
{
if ( V_371 )
F_33 ( V_2 -> V_13 , F_2 ( V_2 , V_637 ) ,
V_371 , V_636 ) ;
F_15 ( V_2 , F_2 ( V_2 , V_561 ) , V_560 ) ;
F_15 ( V_2 , F_2 ( V_2 , V_559 ) , 0 ) ;
}
static int F_161 ( struct V_1 * V_2 , int V_560 ,
void * V_371 , int V_636 )
{
int V_18 , V_23 ;
F_139 ( V_2 , V_560 , V_371 , V_636 ) ;
for ( V_18 = 5000 ; V_18 ; V_18 -- ) {
V_23 = F_13 ( V_2 , F_2 ( V_2 , V_559 ) ) ;
if ( V_23 != V_562 &&
V_23 != V_563 )
break;
F_162 ( 20 ) ;
}
if ( V_18 == 0 ) {
F_51 ( V_169 L_1 , V_2 -> V_13 -> V_170 ) ;
V_23 = V_638 ;
} else {
if ( V_560 != V_623 )
V_23 = V_564 ;
}
return V_23 ;
}
static T_2 F_67 ( struct V_1 * V_2 , T_2 type , T_2 V_305 )
{
struct V_639 V_234 ;
V_234 . type = type ;
V_234 . V_618 = 1 ;
V_234 . V_305 = V_305 ;
F_161 ( V_2 , V_640 , & V_234 , V_641 + 1 ) ;
return F_13 ( V_2 , F_2 ( V_2 , V_637 + V_641 ) ) ;
}
static void F_66 ( struct V_1 * V_2 , T_2 type , T_2 V_305 , T_2 V_15 )
{
struct V_639 V_234 ;
V_234 . type = type ;
V_234 . V_618 = 1 ;
V_234 . V_305 = V_305 ;
V_234 . V_15 [ 0 ] = V_15 ;
F_161 ( V_2 , V_642 , & V_234 , V_641 + 1 ) ;
}
static void F_150 ( struct V_1 * V_2 , T_2 type , T_2 V_305 ,
T_1 V_15 )
{
struct V_639 V_234 ;
V_234 . type = type ;
V_234 . V_618 = 2 ;
V_234 . V_305 = V_305 ;
V_234 . V_15 [ 0 ] = V_15 ;
V_234 . V_15 [ 1 ] = V_15 >> 8 ;
F_161 ( V_2 , V_642 , & V_234 , V_641 + 2 ) ;
}
static void F_151 ( struct V_1 * V_2 , T_2 type , T_2 V_305 ,
T_2 * V_15 , int V_643 )
{
struct V_639 V_234 ;
V_234 . type = type ;
V_234 . V_618 = V_643 ;
V_234 . V_305 = V_305 ;
if ( V_643 > V_644 )
F_51 ( V_169 L_56 , V_2 -> V_13 -> V_170 ) ;
memcpy ( V_234 . V_15 , V_15 , V_643 ) ;
F_161 ( V_2 , V_642 , & V_234 , V_641 + V_643 ) ;
}
static void F_57 ( struct V_1 * V_2 , T_2 type , T_2 V_305 ,
T_2 * V_15 , int V_643 )
{
struct V_639 V_234 ;
V_234 . type = type ;
V_234 . V_618 = V_643 ;
V_234 . V_305 = V_305 ;
if ( V_643 > V_644 )
F_51 ( V_169 L_56 , V_2 -> V_13 -> V_170 ) ;
F_161 ( V_2 , V_640 , & V_234 , V_641 + V_643 ) ;
F_36 ( V_2 -> V_13 , V_15 ,
F_2 ( V_2 , V_637 + V_641 ) , V_643 ) ;
}
static void F_14 ( struct V_12 * V_13 , T_1 V_15 )
{
int V_18 ;
F_12 ( V_15 , V_13 -> V_14 + V_645 ) ;
for ( V_18 = 0 ; V_15 != F_10 ( V_13 -> V_14 + V_645 ) && V_18 < 10 ; V_18 ++ )
F_12 ( V_15 , V_13 -> V_14 + V_645 ) ;
}
static void F_33 ( struct V_12 * V_13 , T_1 V_646 ,
const unsigned char * V_647 , T_1 V_38 )
{
int V_18 ;
F_14 ( V_13 , V_646 ) ;
if ( V_646 % 2 ) {
F_7 ( V_13 , V_17 , * V_647 ) ;
V_647 ++ ; V_38 -- ;
}
for ( V_18 = V_38 ; V_18 > 1 ; V_18 -= 2 ) {
T_2 V_648 = * V_647 ++ ;
T_2 V_649 = * V_647 ++ ;
F_11 ( V_13 , V_17 , V_648 | ( V_649 << 8 ) ) ;
}
if ( V_18 )
F_7 ( V_13 , V_17 , * V_647 ) ;
}
static void F_36 ( struct V_12 * V_13 , unsigned char * V_646 ,
T_1 V_647 , T_1 V_38 )
{
int V_18 ;
F_14 ( V_13 , V_647 ) ;
if ( V_647 % 2 ) {
* V_646 = F_5 ( V_13 , V_17 ) ;
V_646 ++ ; V_38 -- ;
}
for ( V_18 = V_38 ; V_18 > 1 ; V_18 -= 2 ) {
T_1 V_650 = F_9 ( V_13 , V_17 ) ;
* V_646 ++ = V_650 ;
* V_646 ++ = V_650 >> 8 ;
}
if ( V_18 )
* V_646 = F_5 ( V_13 , V_17 ) ;
}
static void F_52 ( struct V_12 * V_13 , T_1 V_651 )
{
F_12 ( F_10 ( V_13 -> V_14 + V_230 ) | V_651 , V_13 -> V_14 + V_230 ) ;
}
static void F_49 ( struct V_12 * V_13 , T_1 V_651 )
{
F_12 ( F_10 ( V_13 -> V_14 + V_230 ) & ~ V_651 , V_13 -> V_14 + V_230 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_18 , V_393 = 20 ;
V_652:
for ( V_18 = 5000 ; V_18 ; V_18 -- ) {
if ( ! F_13 ( V_2 , F_1 ( V_2 , V_653 ) ) )
break;
F_162 ( 20 ) ;
}
if ( ! V_18 )
return 0 ;
F_15 ( V_2 , F_1 ( V_2 , V_172 ) , 1 ) ;
if ( F_13 ( V_2 , F_1 ( V_2 , V_653 ) ) ) {
F_15 ( V_2 , F_1 ( V_2 , V_172 ) , 0 ) ;
if ( ! V_393 -- )
return 0 ;
goto V_652;
}
return 1 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_16 , T_4 V_15 )
{
F_14 ( V_2 -> V_13 , V_16 ) ;
F_11 ( V_2 -> V_13 , V_17 , V_15 ) ;
F_11 ( V_2 -> V_13 , V_17 , V_15 >> 16 ) ;
}
