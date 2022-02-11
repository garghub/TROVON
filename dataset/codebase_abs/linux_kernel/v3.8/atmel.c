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
static int F_71 ( char * V_233 , struct V_1 * V_2 )
{
int V_18 ;
char * V_194 = V_233 ;
char * V_234 , * V_235 , * V_236 ;
V_194 += sprintf ( V_194 , L_5 ,
V_237 , V_238 ) ;
if ( V_2 -> V_74 != V_166 ) {
V_194 += sprintf ( V_194 , L_6
L_7 ,
V_2 -> V_5 . V_239 ,
V_2 -> V_5 . V_240 ,
V_2 -> V_5 . V_241 ) ;
if ( V_2 -> V_242 != V_243 )
V_194 += sprintf ( V_194 , L_8 ) ;
else if ( V_2 -> V_244 )
V_194 += sprintf ( V_194 , L_9 ,
V_2 -> V_245 ) ;
else
V_194 += sprintf ( V_194 , L_10 ,
V_2 -> V_245 ) ;
switch ( V_2 -> V_242 ) {
case V_246 :
V_236 = L_11 ;
break;
case V_247 :
V_236 = L_12 ;
break;
case V_243 :
V_236 = L_13 ;
break;
default:
V_236 = L_14 ;
}
V_235 = L_14 ;
for ( V_18 = 0 ; V_18 < F_53 ( V_218 ) ; V_18 ++ )
if ( V_2 -> V_215 == V_218 [ V_18 ] . V_215 )
V_235 = V_218 [ V_18 ] . V_170 ;
V_194 += sprintf ( V_194 , L_15 , V_236 ) ;
V_194 += sprintf ( V_194 , L_16 , V_235 ) ;
V_194 += sprintf ( V_194 , L_17 ,
V_2 -> V_106 ? L_18 : L_19 ) ;
V_194 += sprintf ( V_194 , L_20 ,
V_2 -> V_45 ? L_21 : L_22 ) ;
}
switch ( V_2 -> V_74 ) {
case V_248 :
V_234 = L_23 ;
break;
case V_249 :
V_234 = L_24 ;
break;
case V_250 :
V_234 = L_25 ;
break;
case V_251 :
V_234 = L_26 ;
break;
case V_75 :
V_234 = L_27 ;
break;
case V_252 :
V_234 = L_28 ;
break;
case V_177 :
V_234 = L_29 ;
break;
case V_166 :
V_234 = L_30 ;
break;
default:
V_234 = L_14 ;
}
V_194 += sprintf ( V_194 , L_31 , V_234 ) ;
return V_194 - V_233 ;
}
static int F_72 ( char * V_253 , char * * V_254 , T_6 V_255 ,
int V_256 , int * V_257 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
int V_38 = F_71 ( V_253 , V_2 ) ;
if ( V_38 <= V_255 + V_256 )
* V_257 = 1 ;
* V_254 = V_253 + V_255 ;
V_38 -= V_255 ;
if ( V_38 > V_256 )
V_38 = V_256 ;
if ( V_38 < 0 )
V_38 = 0 ;
return V_38 ;
}
struct V_12 * F_73 ( unsigned short V_153 , unsigned long V_258 ,
const T_7 V_259 ,
struct V_260 * V_261 ,
int (* F_74)( void * ) , void * V_71 )
{
struct V_262 * V_263 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_264 ;
V_13 = F_75 ( sizeof( * V_2 ) ) ;
if ( ! V_13 )
return NULL ;
if ( F_76 ( V_13 , V_13 -> V_170 ) < 0 ) {
F_51 ( V_265 L_32 ) ;
goto V_266;
}
V_2 = F_24 ( V_13 ) ;
V_2 -> V_13 = V_13 ;
V_2 -> V_261 = V_261 ;
V_2 -> V_72 = F_74 ;
V_2 -> V_71 = V_71 ;
V_2 -> V_244 = NULL ;
V_2 -> V_245 [ 0 ] = '\0' ;
V_2 -> V_267 = V_259 ;
if ( V_244 )
strcpy ( V_2 -> V_245 , V_244 ) ;
V_2 -> V_228 = F_74 ? V_229 : V_268 ;
V_2 -> V_74 = V_166 ;
V_2 -> V_106 = 0 ;
if ( V_2 -> V_228 == V_229 ) {
V_2 -> F_44 = 1 ;
V_2 -> V_141 = V_2 -> V_142 = 0 ;
} else
V_2 -> F_44 = 0 ;
V_2 -> V_269 = V_270 ;
V_2 -> V_271 = 0 ;
memset ( V_2 -> V_124 , 0xff , sizeof( V_2 -> V_124 ) ) ;
memset ( V_2 -> V_91 , 0 , 6 ) ;
V_2 -> V_93 [ 0 ] = 0xFF ;
V_2 -> V_272 = 0 ;
V_2 -> V_273 = V_270 ;
V_2 -> V_274 = V_275 ;
V_2 -> V_85 = V_174 ;
V_2 -> V_276 = 0 ;
V_2 -> V_214 = 0 ;
V_2 -> V_215 = 0 ;
V_2 -> V_48 = 3 ;
V_2 -> V_277 = 1 ;
V_2 -> V_199 = 4 ;
V_2 -> V_278 = 0 ;
V_2 -> V_203 [ 0 ] = '\0' ;
V_2 -> V_205 = 0 ;
V_2 -> V_202 = 0 ;
V_2 -> V_279 = 2346 ;
V_2 -> V_280 = 2347 ;
V_2 -> V_281 = 7 ;
V_2 -> V_282 = 4 ;
V_2 -> V_83 = 0 ;
V_2 -> V_283 = 0 ;
V_2 -> V_284 = 0 ;
V_2 -> V_285 = 0 ;
V_2 -> V_52 = V_2 -> V_56 = V_57 ;
V_2 -> V_45 = 0 ;
memset ( V_2 -> V_286 , 0 , sizeof( V_2 -> V_286 ) ) ;
memset ( V_2 -> V_287 , 0 , sizeof( V_2 -> V_287 ) ) ;
V_2 -> V_288 = V_2 -> V_289 = 100 ;
V_2 -> V_290 = 1 ;
F_77 ( & V_2 -> V_201 ) ;
F_78 ( & V_2 -> V_77 ) ;
F_78 ( & V_2 -> V_76 ) ;
V_2 -> V_201 . V_291 = V_292 ;
V_2 -> V_201 . V_15 = ( unsigned long ) V_13 ;
V_13 -> V_293 = & V_294 ;
V_13 -> V_295 = & V_296 ;
V_13 -> V_153 = V_153 ;
V_13 -> V_14 = V_258 ;
F_79 ( V_13 , V_261 ) ;
if ( ( V_264 = F_80 ( V_13 -> V_153 , F_48 , V_297 , V_13 -> V_170 , V_13 ) ) ) {
F_51 ( V_265 L_33 , V_13 -> V_170 , V_153 , V_264 ) ;
goto V_266;
}
if ( ! F_81 ( V_13 -> V_14 , 32 ,
V_2 -> V_228 == V_229 ? L_34 : L_35 ) ) {
goto V_298;
}
if ( F_82 ( V_13 ) )
goto V_299;
if ( ! F_83 ( V_13 ) ) {
F_84 ( V_13 ) ;
goto V_299;
}
F_85 ( V_13 ) ;
V_263 = F_86 ( L_36 , 0 , NULL , F_72 , V_2 ) ;
if ( ! V_263 )
F_51 ( V_300 L_37 ) ;
F_51 ( V_180 L_38 ,
V_13 -> V_170 , V_237 , V_238 , V_13 -> V_89 ) ;
return V_13 ;
V_299:
F_87 ( V_13 -> V_14 , 32 ) ;
V_298:
F_88 ( V_13 -> V_153 , V_13 ) ;
V_266:
F_89 ( V_13 ) ;
return NULL ;
}
void F_90 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
F_64 ( & V_2 -> V_201 ) ;
F_84 ( V_13 ) ;
F_91 ( L_36 , NULL ) ;
F_88 ( V_13 -> V_153 , V_13 ) ;
F_92 ( V_2 -> V_244 ) ;
F_87 ( V_13 -> V_14 , 32 ) ;
F_89 ( V_13 ) ;
}
static int F_93 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_303 * V_304 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_304 -> V_68 == 0 ) {
V_2 -> V_276 = 1 ;
} else {
int V_306 = ( V_304 -> V_68 & V_307 ) - 1 ;
V_2 -> V_276 = 0 ;
if ( V_304 -> V_222 > V_308 )
return - V_309 ;
if ( V_306 != 0 )
return - V_192 ;
memcpy ( V_2 -> V_204 , V_305 , V_304 -> V_222 ) ;
V_2 -> V_202 = V_304 -> V_222 ;
}
return - V_310 ;
}
static int F_94 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_303 * V_304 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_202 != 0 ) {
memcpy ( V_305 , V_2 -> V_204 , V_2 -> V_202 ) ;
V_304 -> V_222 = V_2 -> V_202 ;
} else {
memcpy ( V_305 , V_2 -> V_203 , V_2 -> V_205 ) ;
V_304 -> V_222 = V_2 -> V_205 ;
}
V_304 -> V_68 = ! V_2 -> V_276 ;
return 0 ;
}
static int F_95 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_195 * V_311 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
memcpy ( V_311 -> V_197 , V_2 -> V_93 , 6 ) ;
V_311 -> V_224 = V_225 ;
return 0 ;
}
static int F_96 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_303 * V_304 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_304 -> V_222 > 0 ) {
int V_306 = ( V_304 -> V_68 & V_307 ) - 1 ;
int V_312 = V_2 -> V_283 ;
if ( V_304 -> V_222 > 13 ) {
return - V_192 ;
}
if ( V_306 < 0 || V_306 >= 4 )
V_306 = V_312 ;
else
V_2 -> V_283 = V_306 ;
if ( V_304 -> V_222 > 5 )
V_2 -> V_287 [ V_306 ] = 13 ;
else
if ( V_304 -> V_222 > 0 )
V_2 -> V_287 [ V_306 ] = 5 ;
else
V_2 -> V_287 [ V_306 ] = 0 ;
if ( ! ( V_304 -> V_68 & V_313 ) ) {
memset ( V_2 -> V_286 [ V_306 ] , 0 , 13 ) ;
memcpy ( V_2 -> V_286 [ V_306 ] , V_305 , V_304 -> V_222 ) ;
}
if ( V_306 == V_312 &&
V_2 -> V_287 [ V_306 ] > 0 ) {
V_2 -> V_83 = 1 ;
V_2 -> V_285 = 1 ;
if ( V_2 -> V_287 [ V_306 ] > 5 ) {
V_2 -> V_56 = V_54 ;
V_2 -> V_284 = 2 ;
} else {
V_2 -> V_56 = V_53 ;
V_2 -> V_284 = 1 ;
}
}
} else {
int V_306 = ( V_304 -> V_68 & V_307 ) - 1 ;
if ( V_306 >= 0 && V_306 < 4 ) {
V_2 -> V_283 = V_306 ;
} else
if ( ! ( V_304 -> V_68 & V_314 ) )
return - V_192 ;
}
if ( V_304 -> V_68 & V_315 ) {
V_2 -> V_83 = 0 ;
V_2 -> V_284 = 0 ;
V_2 -> V_56 = V_57 ;
} else {
V_2 -> V_83 = 1 ;
if ( V_2 -> V_287 [ V_2 -> V_283 ] > 5 ) {
V_2 -> V_56 = V_54 ;
V_2 -> V_284 = 2 ;
} else {
V_2 -> V_56 = V_53 ;
V_2 -> V_284 = 1 ;
}
}
if ( V_304 -> V_68 & V_316 )
V_2 -> V_285 = 1 ;
if ( V_304 -> V_68 & V_317 )
V_2 -> V_285 = 0 ;
return - V_310 ;
}
static int F_97 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_303 * V_304 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_306 = ( V_304 -> V_68 & V_307 ) - 1 ;
if ( ! V_2 -> V_83 )
V_304 -> V_68 = V_315 ;
else {
if ( V_2 -> V_285 )
V_304 -> V_68 = V_316 ;
else
V_304 -> V_68 = V_317 ;
}
if ( V_306 < 0 || V_306 >= 4 )
V_306 = V_2 -> V_283 ;
V_304 -> V_68 |= V_306 + 1 ;
V_304 -> V_222 = V_2 -> V_287 [ V_306 ] ;
if ( V_304 -> V_222 > 16 ) {
V_304 -> V_222 = 0 ;
} else {
memset ( V_305 , 0 , 16 ) ;
memcpy ( V_305 , V_2 -> V_286 [ V_306 ] , V_304 -> V_222 ) ;
}
return 0 ;
}
static int F_98 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
union V_220 * V_221 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_303 * V_318 = & V_221 -> V_318 ;
struct V_319 * V_320 = (struct V_319 * ) V_305 ;
int V_321 , V_322 , V_323 = V_320 -> V_323 , V_324 = 1 ;
V_321 = V_318 -> V_68 & V_307 ;
if ( V_321 ) {
if ( V_321 < 1 || V_321 > 4 )
return - V_192 ;
V_321 -- ;
} else
V_321 = V_2 -> V_283 ;
if ( V_318 -> V_68 & V_315 )
V_323 = V_325 ;
if ( V_320 -> V_326 & V_327 ) {
V_2 -> V_283 = V_321 ;
V_324 = V_320 -> V_322 > 0 ? 1 : 0 ;
}
if ( V_324 ) {
switch ( V_323 ) {
case V_325 :
V_2 -> V_83 = 0 ;
V_2 -> V_284 = 0 ;
V_2 -> V_56 = V_57 ;
break;
case V_328 :
if ( V_320 -> V_322 > 5 ) {
V_2 -> V_287 [ V_321 ] = 13 ;
V_2 -> V_56 = V_54 ;
V_2 -> V_284 = 2 ;
} else if ( V_320 -> V_322 > 0 ) {
V_2 -> V_287 [ V_321 ] = 5 ;
V_2 -> V_56 = V_53 ;
V_2 -> V_284 = 1 ;
} else {
return - V_192 ;
}
V_2 -> V_83 = 1 ;
memset ( V_2 -> V_286 [ V_321 ] , 0 , 13 ) ;
V_322 = V_231 ( ( int ) V_320 -> V_322 , V_2 -> V_287 [ V_321 ] ) ;
memcpy ( V_2 -> V_286 [ V_321 ] , V_320 -> V_329 , V_322 ) ;
break;
default:
return - V_192 ;
}
}
return - V_310 ;
}
static int F_99 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
union V_220 * V_221 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_303 * V_318 = & V_221 -> V_318 ;
struct V_319 * V_320 = (struct V_319 * ) V_305 ;
int V_321 , V_330 ;
V_330 = V_318 -> V_222 - sizeof( * V_320 ) ;
if ( V_330 < 0 )
return - V_192 ;
V_321 = V_318 -> V_68 & V_307 ;
if ( V_321 ) {
if ( V_321 < 1 || V_321 > 4 )
return - V_192 ;
V_321 -- ;
} else
V_321 = V_2 -> V_283 ;
V_318 -> V_68 = V_321 + 1 ;
memset ( V_320 , 0 , sizeof( * V_320 ) ) ;
if ( ! V_2 -> V_83 ) {
V_320 -> V_323 = V_325 ;
V_320 -> V_322 = 0 ;
V_318 -> V_68 |= V_315 ;
} else {
if ( V_2 -> V_284 > 0 )
V_320 -> V_323 = V_328 ;
else
return - V_192 ;
V_320 -> V_322 = V_2 -> V_287 [ V_321 ] ;
memcpy ( V_320 -> V_329 , V_2 -> V_286 [ V_321 ] , V_320 -> V_322 ) ;
V_318 -> V_68 |= V_331 ;
}
return 0 ;
}
static int F_100 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
union V_220 * V_221 , char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_332 * V_333 = & V_221 -> V_333 ;
switch ( V_333 -> V_68 & V_334 ) {
case V_335 :
case V_336 :
case V_337 :
case V_338 :
case V_339 :
case V_340 :
break;
case V_341 :
V_2 -> V_285 = V_333 -> V_342 ? 1 : 0 ;
break;
case V_343 : {
if ( V_333 -> V_342 & V_344 ) {
V_2 -> V_285 = 1 ;
} else if ( V_333 -> V_342 & V_345 ) {
V_2 -> V_285 = 0 ;
} else
return - V_192 ;
break;
}
case V_346 :
if ( V_333 -> V_342 > 0 )
return - V_347 ;
break;
default:
return - V_347 ;
}
return - V_310 ;
}
static int F_101 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
union V_220 * V_221 , char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_332 * V_333 = & V_221 -> V_333 ;
switch ( V_333 -> V_68 & V_334 ) {
case V_341 :
V_333 -> V_342 = V_2 -> V_285 ;
break;
case V_343 :
if ( V_2 -> V_285 == 1 )
V_333 -> V_342 = V_344 ;
else
V_333 -> V_342 = V_345 ;
break;
case V_346 :
V_333 -> V_342 = 0 ;
break;
default:
return - V_347 ;
}
return 0 ;
}
static int F_102 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
char * V_348 ,
char * V_305 )
{
strcpy ( V_348 , L_39 ) ;
return 0 ;
}
static int F_103 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_349 -> V_350 == 0 ) {
V_2 -> V_48 = 3 ;
V_2 -> V_277 = 1 ;
} else {
V_2 -> V_277 = 0 ;
if ( ( V_349 -> V_342 < 4 ) && ( V_349 -> V_342 >= 0 ) ) {
V_2 -> V_48 = V_349 -> V_342 ;
} else {
switch ( V_349 -> V_342 ) {
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
return - V_310 ;
}
static int F_104 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
T_8 * V_351 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( * V_351 != V_86 && * V_351 != V_174 )
return - V_192 ;
V_2 -> V_85 = * V_351 ;
return - V_310 ;
}
static int F_105 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
T_8 * V_351 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
* V_351 = V_2 -> V_85 ;
return 0 ;
}
static int F_106 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_277 ) {
V_349 -> V_350 = 0 ;
V_349 -> V_342 = 11000000 ;
} else {
V_349 -> V_350 = 1 ;
switch ( V_2 -> V_48 ) {
case 0 :
V_349 -> V_342 = 1000000 ;
break;
case 1 :
V_349 -> V_342 = 2000000 ;
break;
case 2 :
V_349 -> V_342 = 5500000 ;
break;
case 3 :
V_349 -> V_342 = 11000000 ;
break;
}
}
return 0 ;
}
static int F_107 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_2 -> V_278 = V_349 -> V_352 ? 0 : 1 ;
return - V_310 ;
}
static int F_108 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_349 -> V_352 = V_2 -> V_278 ? 0 : 1 ;
V_349 -> V_68 = V_353 ;
return 0 ;
}
static int F_109 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( ! V_349 -> V_352 && ( V_349 -> V_68 & V_354 ) ) {
if ( V_349 -> V_68 & V_355 )
V_2 -> V_282 = V_349 -> V_342 ;
else if ( V_349 -> V_68 & V_356 )
V_2 -> V_281 = V_349 -> V_342 ;
else {
V_2 -> V_282 = V_349 -> V_342 ;
V_2 -> V_281 = V_349 -> V_342 ;
}
return - V_310 ;
}
return - V_192 ;
}
static int F_110 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_349 -> V_352 = 0 ;
if ( V_349 -> V_68 & V_355 ) {
V_349 -> V_68 = V_354 | V_355 ;
V_349 -> V_342 = V_2 -> V_282 ;
} else {
V_349 -> V_68 = V_354 ;
V_349 -> V_342 = V_2 -> V_281 ;
if ( V_2 -> V_282 != V_2 -> V_281 )
V_349 -> V_68 |= V_356 ;
}
return 0 ;
}
static int F_111 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_357 = V_349 -> V_342 ;
if ( V_349 -> V_352 )
V_357 = 2347 ;
if ( ( V_357 < 0 ) || ( V_357 > 2347 ) ) {
return - V_192 ;
}
V_2 -> V_280 = V_357 ;
return - V_310 ;
}
static int F_112 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_349 -> V_342 = V_2 -> V_280 ;
V_349 -> V_352 = ( V_349 -> V_342 >= 2347 ) ;
V_349 -> V_350 = 1 ;
return 0 ;
}
static int F_113 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_358 = V_349 -> V_342 ;
if ( V_349 -> V_352 )
V_358 = 2346 ;
if ( ( V_358 < 256 ) || ( V_358 > 2346 ) ) {
return - V_192 ;
}
V_358 &= ~ 0x1 ;
V_2 -> V_279 = V_358 ;
return - V_310 ;
}
static int F_114 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_332 * V_349 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_349 -> V_342 = V_2 -> V_279 ;
V_349 -> V_352 = ( V_349 -> V_342 >= 2346 ) ;
V_349 -> V_350 = 1 ;
return 0 ;
}
static int F_115 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_359 * V_360 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_264 = - V_310 ;
if ( V_360 -> V_361 == 1 ) {
int V_362 = V_360 -> V_363 / 100000 ;
V_360 -> V_361 = 0 ;
V_360 -> V_363 = F_116 ( V_362 ) ;
}
if ( ( V_360 -> V_363 > 1000 ) || ( V_360 -> V_361 > 0 ) )
V_264 = - V_347 ;
else {
int V_199 = V_360 -> V_363 ;
if ( F_68 ( V_2 , V_199 ) == 0 ) {
V_2 -> V_199 = V_199 ;
} else {
V_264 = - V_192 ;
}
}
return V_264 ;
}
static int F_117 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_359 * V_360 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
V_360 -> V_363 = V_2 -> V_199 ;
V_360 -> V_361 = 0 ;
return 0 ;
}
static int F_118 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_303 * V_304 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
unsigned long V_68 ;
if ( V_2 -> V_74 == V_166 )
return - V_364 ;
if ( F_119 ( V_270 , V_2 -> V_273 + 20 * V_365 ) )
V_2 -> V_212 = V_213 ;
V_2 -> V_273 = V_270 ;
if ( V_2 -> V_212 == V_366 )
return - V_367 ;
F_64 ( & V_2 -> V_201 ) ;
F_27 ( & V_2 -> V_77 , V_68 ) ;
V_2 -> V_212 = V_366 ;
V_2 -> V_368 = 0 ;
F_54 ( V_2 , 0 ) ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
return 0 ;
}
static int F_120 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_303 * V_304 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_18 ;
char * V_369 = V_305 ;
struct V_370 V_371 ;
if ( V_2 -> V_212 != V_372 )
return - V_364 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
V_371 . V_373 = V_227 ;
V_371 . V_374 . V_223 . V_224 = V_225 ;
memcpy ( V_371 . V_374 . V_223 . V_197 , V_2 -> V_375 [ V_18 ] . V_91 , 6 ) ;
V_369 = F_121 ( V_302 , V_369 ,
V_305 + V_376 ,
& V_371 , V_377 ) ;
V_371 . V_374 . V_15 . V_222 = V_2 -> V_375 [ V_18 ] . V_378 ;
if ( V_371 . V_374 . V_15 . V_222 > 32 )
V_371 . V_374 . V_15 . V_222 = 32 ;
V_371 . V_373 = V_379 ;
V_371 . V_374 . V_15 . V_68 = 1 ;
V_369 = F_122 ( V_302 , V_369 ,
V_305 + V_376 ,
& V_371 , V_2 -> V_375 [ V_18 ] . V_203 ) ;
V_371 . V_373 = V_380 ;
V_371 . V_374 . V_381 = V_2 -> V_375 [ V_18 ] . V_382 ;
V_369 = F_121 ( V_302 , V_369 ,
V_305 + V_376 ,
& V_371 , V_383 ) ;
V_371 . V_373 = V_384 ;
V_371 . V_374 . V_385 . V_363 = V_2 -> V_375 [ V_18 ] . V_199 ;
V_371 . V_374 . V_385 . V_361 = 0 ;
V_369 = F_121 ( V_302 , V_369 ,
V_305 + V_376 ,
& V_371 , V_386 ) ;
V_371 . V_373 = V_387 ;
V_371 . V_374 . V_182 . V_183 = V_2 -> V_375 [ V_18 ] . V_388 ;
V_371 . V_374 . V_182 . V_182 = V_371 . V_374 . V_182 . V_183 ;
V_369 = F_121 ( V_302 , V_369 ,
V_305 + V_376 ,
& V_371 , V_389 ) ;
V_371 . V_373 = V_390 ;
if ( V_2 -> V_375 [ V_18 ] . V_391 )
V_371 . V_374 . V_15 . V_68 = V_331 | V_313 ;
else
V_371 . V_374 . V_15 . V_68 = V_315 ;
V_371 . V_374 . V_15 . V_222 = 0 ;
V_369 = F_122 ( V_302 , V_369 ,
V_305 + V_376 ,
& V_371 , NULL ) ;
}
V_304 -> V_222 = ( V_369 - V_305 ) ;
V_304 -> V_68 = 0 ;
return 0 ;
}
static int F_123 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_303 * V_304 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
struct V_392 * V_393 = (struct V_392 * ) V_305 ;
int V_394 , V_18 , V_395 ;
V_304 -> V_222 = sizeof( struct V_392 ) ;
memset ( V_393 , 0 , sizeof( struct V_392 ) ) ;
V_393 -> V_396 = 0x0000 ;
V_393 -> V_397 = 0x0000 ;
V_393 -> V_398 = 0 ;
for ( V_395 = 0 ; V_395 < F_53 ( V_218 ) ; V_395 ++ )
if ( V_2 -> V_215 == V_218 [ V_395 ] . V_215 ) {
V_393 -> V_398 = V_218 [ V_395 ] . V_232 - V_218 [ V_395 ] . V_231 + 1 ;
break;
}
if ( V_393 -> V_398 != 0 ) {
for ( V_394 = 0 , V_18 = V_218 [ V_395 ] . V_231 ; V_18 <= V_218 [ V_395 ] . V_232 ; V_18 ++ ) {
V_393 -> V_385 [ V_394 ] . V_18 = V_18 ;
V_393 -> V_385 [ V_394 ] . V_363 = ( F_124 ( V_18 ) *
100000 ) ;
V_393 -> V_385 [ V_394 ++ ] . V_361 = 1 ;
}
V_393 -> V_399 = V_394 ;
}
V_393 -> V_400 . V_182 = 100 ;
V_393 -> V_400 . V_183 = 100 ;
V_393 -> V_400 . V_187 = 0 ;
V_393 -> V_400 . V_184 = V_188 ;
V_393 -> V_401 . V_182 = 50 ;
V_393 -> V_401 . V_183 = 50 ;
V_393 -> V_401 . V_187 = 0 ;
V_393 -> V_401 . V_184 = V_188 ;
V_393 -> V_402 = 0 ;
V_393 -> V_403 [ 0 ] = 1000000 ;
V_393 -> V_403 [ 1 ] = 2000000 ;
V_393 -> V_403 [ 2 ] = 5500000 ;
V_393 -> V_403 [ 3 ] = 11000000 ;
V_393 -> V_404 = 4 ;
V_393 -> V_405 = 0 ;
V_393 -> V_406 = 2347 ;
V_393 -> V_407 = 256 ;
V_393 -> V_408 = 2346 ;
V_393 -> V_409 [ 0 ] = 5 ;
V_393 -> V_409 [ 1 ] = 13 ;
V_393 -> V_410 = 2 ;
V_393 -> V_411 = 4 ;
V_393 -> V_412 = V_353 ;
V_393 -> V_413 = V_353 ;
V_393 -> V_414 = 0 ;
V_393 -> V_415 = V_416 ;
V_393 -> V_417 = V_416 ;
V_393 -> V_418 = V_354 ;
V_393 -> V_419 = V_354 ;
V_393 -> V_420 = 0 ;
V_393 -> V_421 = 1 ;
V_393 -> V_422 = 65535 ;
return 0 ;
}
static int F_125 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
struct V_195 * V_311 ,
char * V_305 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
int V_18 ;
static const T_2 V_423 [] = { 0xFF , 0xFF , 0xFF , 0xFF , 0xFF , 0xFF } ;
static const T_2 V_255 [] = { 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
unsigned long V_68 ;
if ( V_311 -> V_224 != V_225 )
return - V_192 ;
if ( ! memcmp ( V_423 , V_311 -> V_197 , 6 ) ||
! memcmp ( V_255 , V_311 -> V_197 , 6 ) ) {
F_64 ( & V_2 -> V_201 ) ;
F_27 ( & V_2 -> V_77 , V_68 ) ;
F_54 ( V_2 , 1 ) ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
return 0 ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
if ( memcmp ( V_2 -> V_375 [ V_18 ] . V_91 , V_311 -> V_197 , 6 ) == 0 ) {
if ( ! V_2 -> V_83 && V_2 -> V_375 [ V_18 ] . V_391 ) {
return - V_192 ;
} else if ( V_2 -> V_83 && ! V_2 -> V_375 [ V_18 ] . V_391 ) {
return - V_192 ;
} else {
F_64 ( & V_2 -> V_201 ) ;
F_27 ( & V_2 -> V_77 , V_68 ) ;
F_126 ( V_2 , V_18 ) ;
F_28 ( & V_2 -> V_77 , V_68 ) ;
return 0 ;
}
}
}
return - V_192 ;
}
static int F_127 ( struct V_12 * V_13 ,
struct V_301 * V_302 ,
void * V_424 ,
char * V_305 )
{
return F_63 ( V_13 ) ;
}
static int F_128 ( struct V_12 * V_13 , struct V_425 * V_426 , int V_373 )
{
int V_18 , V_264 = 0 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
T_9 V_427 ;
struct V_428 * V_429 = (struct V_428 * ) V_426 ;
unsigned char * V_430 ;
char V_431 [ V_432 + 1 ] ;
switch ( V_373 ) {
case V_433 :
V_429 -> V_374 . V_333 . V_342 = V_434 ;
break;
case V_435 :
if ( F_129 ( & V_427 , V_426 -> V_436 , sizeof( V_427 ) ) ) {
V_264 = - V_437 ;
break;
}
if ( ! F_130 ( V_438 ) ) {
V_264 = - V_439 ;
break;
}
if ( ! ( V_430 = F_131 ( V_427 . V_38 , V_440 ) ) ) {
V_264 = - V_441 ;
break;
}
if ( F_129 ( V_430 , V_427 . V_15 , V_427 . V_38 ) ) {
F_92 ( V_430 ) ;
V_264 = - V_437 ;
break;
}
F_92 ( V_2 -> V_244 ) ;
V_2 -> V_244 = V_430 ;
V_2 -> V_442 = V_427 . V_38 ;
strncpy ( V_2 -> V_245 , V_427 . V_443 , 31 ) ;
V_2 -> V_245 [ 31 ] = '\0' ;
break;
case V_444 :
if ( F_129 ( V_431 , V_426 -> V_436 , V_432 ) ) {
V_264 = - V_437 ;
break;
}
if ( ! F_130 ( V_438 ) ) {
V_264 = - V_439 ;
break;
}
V_431 [ V_432 ] = 0 ;
V_264 = - V_192 ;
for ( V_18 = 0 ; V_18 < F_53 ( V_218 ) ; V_18 ++ ) {
char * V_445 = V_218 [ V_18 ] . V_170 ;
char * V_446 = V_431 ;
while ( * V_445 ) {
char V_447 = * V_445 ++ ;
char V_448 = * V_446 ++ ;
if ( tolower ( V_447 ) != tolower ( V_448 ) )
break;
}
if ( ! * V_445 && ! * V_446 ) {
V_2 -> V_214 = V_218 [ V_18 ] . V_215 ;
V_264 = 0 ;
}
}
if ( V_264 == 0 && V_2 -> V_74 != V_166 )
V_264 = F_63 ( V_13 ) ;
break;
default:
V_264 = - V_347 ;
}
return V_264 ;
}
static void F_55 ( struct V_1 * V_2 , int V_449 )
{
int V_450 = V_2 -> V_74 ;
if ( V_449 == V_450 )
return;
V_2 -> V_74 = V_449 ;
if ( V_449 == V_75 ) {
F_132 ( V_2 -> V_13 ) ;
F_133 ( V_2 -> V_13 ) ;
}
if ( V_450 == V_75 ) {
F_85 ( V_2 -> V_13 ) ;
if ( F_134 ( V_2 -> V_13 ) )
F_30 ( V_2 -> V_13 ) ;
V_2 -> V_271 = 0 ;
}
}
static void F_54 ( struct V_1 * V_2 , int V_451 )
{
struct {
T_2 V_91 [ 6 ] ;
T_2 V_203 [ V_308 ] ;
T_2 V_452 ;
T_2 V_199 ;
T_10 V_453 ;
T_10 V_454 ;
T_10 V_455 ;
T_2 V_456 ;
T_2 V_205 ;
} V_373 ;
memset ( V_373 . V_91 , 0xff , 6 ) ;
if ( V_2 -> V_368 ) {
V_373 . V_205 = V_2 -> V_205 ;
memcpy ( V_373 . V_203 , V_2 -> V_203 , V_2 -> V_205 ) ;
V_373 . V_454 = F_32 ( 10 ) ;
V_373 . V_455 = F_32 ( 50 ) ;
} else {
V_2 -> V_206 = 0 ;
V_373 . V_205 = 0 ;
V_373 . V_454 = F_32 ( 10 ) ;
V_373 . V_455 = F_32 ( 120 ) ;
}
V_373 . V_456 = 0 ;
if ( ! V_451 )
V_373 . V_456 |= V_457 ;
V_373 . V_199 = ( V_2 -> V_199 & 0x7f ) ;
V_373 . V_452 = V_458 ;
V_373 . V_453 = F_32 ( V_2 -> V_85 == V_86 ?
V_459 : V_460 ) ;
F_135 ( V_2 , V_461 , & V_373 , sizeof( V_373 ) ) ;
F_55 ( V_2 , V_248 ) ;
}
static void F_136 ( struct V_1 * V_2 , int type )
{
struct {
T_2 V_91 [ 6 ] ;
T_2 V_203 [ V_308 ] ;
T_2 V_453 ;
T_2 V_199 ;
T_10 V_462 ;
T_2 V_205 ;
T_2 V_463 ;
} V_373 ;
V_373 . V_205 = V_2 -> V_205 ;
memcpy ( V_373 . V_203 , V_2 -> V_203 , V_2 -> V_205 ) ;
memcpy ( V_373 . V_91 , V_2 -> V_93 , 6 ) ;
V_373 . V_199 = ( V_2 -> V_199 & 0x7f ) ;
V_373 . V_453 = type ;
V_373 . V_462 = F_32 ( 2000 ) ;
F_135 ( V_2 , V_464 , & V_373 , sizeof( V_373 ) ) ;
}
static void V_254 ( struct V_1 * V_2 , int type )
{
struct {
T_2 V_91 [ 6 ] ;
T_2 V_203 [ V_308 ] ;
T_2 V_453 ;
T_2 V_199 ;
T_2 V_205 ;
T_2 V_463 [ 3 ] ;
} V_373 ;
V_373 . V_205 = V_2 -> V_205 ;
memcpy ( V_373 . V_203 , V_2 -> V_203 , V_2 -> V_205 ) ;
memcpy ( V_373 . V_91 , V_2 -> V_91 , 6 ) ;
V_373 . V_453 = type ;
V_373 . V_199 = ( V_2 -> V_199 & 0x7f ) ;
F_135 ( V_2 , V_465 , & V_373 , sizeof( V_373 ) ) ;
}
static void F_137 ( struct V_1 * V_2 , T_1 V_466 ,
T_2 V_199 )
{
int V_467 = 0 ;
int V_468 = V_466 & V_469 ?
V_470 : V_275 ;
if ( V_2 -> V_274 != V_468 ) {
V_2 -> V_274 = V_468 ;
V_467 = 1 ;
F_66 ( V_2 , V_471 , V_472 , V_468 ) ;
}
if ( V_2 -> V_199 != V_199 ) {
V_2 -> V_199 = V_199 ;
V_467 = 1 ;
F_66 ( V_2 , V_216 , V_473 , V_199 ) ;
}
if ( V_467 ) {
V_2 -> V_175 = 0 ;
F_55 ( V_2 , V_249 ) ;
if ( V_2 -> V_85 == V_174 )
F_136 ( V_2 , V_460 ) ;
else
F_136 ( V_2 , V_459 ) ;
}
}
static void F_138 ( struct V_1 * V_2 , T_1 system ,
T_2 * V_474 , int V_475 )
{
struct V_66 V_67 ;
struct V_476 V_477 ;
V_67 . V_95 = F_32 ( V_150 | V_478 ) ;
V_67 . V_81 = F_32 ( 0x8000 ) ;
V_67 . V_82 = 0 ;
memcpy ( V_67 . V_87 , V_2 -> V_93 , 6 ) ;
memcpy ( V_67 . V_88 , V_2 -> V_13 -> V_89 , 6 ) ;
memcpy ( V_67 . V_90 , V_2 -> V_93 , 6 ) ;
if ( V_2 -> V_83 && V_2 -> V_210 != 1 )
V_67 . V_95 |= F_32 ( V_84 ) ;
V_477 . V_323 = F_32 ( system ) ;
V_477 . V_23 = 0 ;
V_477 . V_479 = F_32 ( V_2 -> V_210 ) ;
V_2 -> V_211 = V_2 -> V_210 + 1 ;
V_2 -> V_210 += 2 ;
if ( V_475 != 0 ) {
V_477 . V_480 = 16 ;
V_477 . V_481 = V_475 ;
memcpy ( V_477 . V_482 , V_474 , V_475 ) ;
F_34 ( V_2 , & V_67 , ( T_2 * ) & V_477 , 8 + V_475 ) ;
} else {
F_34 ( V_2 , & V_67 , ( T_2 * ) & V_477 , 6 ) ;
}
}
static void F_139 ( struct V_1 * V_2 , int V_483 )
{
T_2 * V_484 ;
int V_485 ;
struct V_66 V_67 ;
struct V_486 {
T_10 V_466 ;
T_10 V_290 ;
T_2 V_487 [ 6 ] ;
T_2 V_488 ;
T_2 V_489 ;
T_2 V_490 [ V_308 ] ;
T_2 V_491 ;
T_2 V_492 ;
T_2 V_493 [ 4 ] ;
} V_98 ;
V_67 . V_95 = F_32 ( V_150 |
( V_483 ? V_494 : V_495 ) ) ;
V_67 . V_81 = F_32 ( 0x8000 ) ;
V_67 . V_82 = 0 ;
memcpy ( V_67 . V_87 , V_2 -> V_93 , 6 ) ;
memcpy ( V_67 . V_88 , V_2 -> V_13 -> V_89 , 6 ) ;
memcpy ( V_67 . V_90 , V_2 -> V_93 , 6 ) ;
V_98 . V_466 = F_32 ( V_496 ) ;
if ( V_2 -> V_83 )
V_98 . V_466 |= F_32 ( V_497 ) ;
if ( V_2 -> V_274 == V_470 )
V_98 . V_466 |= F_32 ( V_469 ) ;
V_98 . V_290 = F_32 ( V_2 -> V_290 * V_2 -> V_289 ) ;
if ( V_483 ) {
memcpy ( V_98 . V_487 , V_2 -> V_93 , 6 ) ;
V_484 = & V_98 . V_488 ;
V_485 = 18 + V_2 -> V_205 ;
} else {
V_484 = & V_98 . V_487 [ 0 ] ;
V_485 = 12 + V_2 -> V_205 ;
}
V_484 [ 0 ] = V_498 ;
V_484 [ 1 ] = V_2 -> V_205 ;
memcpy ( V_484 + 2 , V_2 -> V_203 , V_2 -> V_205 ) ;
V_484 [ 2 + V_2 -> V_205 ] = V_499 ;
V_484 [ 3 + V_2 -> V_205 ] = 4 ;
memcpy ( V_484 + 4 + V_2 -> V_205 , V_500 , 4 ) ;
F_34 ( V_2 , & V_67 , ( void * ) & V_98 , V_485 ) ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_66 * V_67 )
{
if ( F_41 ( V_67 -> V_95 ) & V_110 )
return memcmp ( V_67 -> V_90 , V_2 -> V_93 , 6 ) == 0 ;
else
return memcmp ( V_67 -> V_88 , V_2 -> V_93 , 6 ) == 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
int V_18 ;
int V_501 = - 128 ;
int V_502 = - 1 ;
if ( V_2 -> V_206 == 0 )
return - 1 ;
if ( V_2 -> V_276 ) {
V_2 -> V_503 = 0 ;
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
if ( V_2 -> V_85 == V_2 -> V_375 [ V_18 ] . V_382 &&
( ( ! V_2 -> V_83 && ! V_2 -> V_375 [ V_18 ] . V_391 ) ||
( V_2 -> V_83 && V_2 -> V_375 [ V_18 ] . V_391 ) ) &&
! ( V_2 -> V_375 [ V_18 ] . V_199 & 0x80 ) ) {
V_501 = V_2 -> V_375 [ V_18 ] . V_388 ;
V_2 -> V_503 = V_502 = V_18 ;
}
}
return V_502 ;
}
for ( V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ ) {
if ( V_2 -> V_205 == V_2 -> V_375 [ V_18 ] . V_378 &&
memcmp ( V_2 -> V_203 , V_2 -> V_375 [ V_18 ] . V_203 , V_2 -> V_205 ) == 0 &&
V_2 -> V_85 == V_2 -> V_375 [ V_18 ] . V_382 &&
F_68 ( V_2 , V_2 -> V_375 [ V_18 ] . V_199 ) == 0 ) {
if ( V_2 -> V_375 [ V_18 ] . V_388 >= V_501 ) {
V_501 = V_2 -> V_375 [ V_18 ] . V_388 ;
V_502 = V_18 ;
}
}
}
return V_502 ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_66 * V_67 , T_1 V_466 ,
T_1 V_289 , T_2 V_199 , T_2 V_504 , T_2 V_489 ,
T_2 * V_490 , int V_505 )
{
T_2 * V_506 = V_466 & V_496 ? V_67 -> V_88 : V_67 -> V_90 ;
int V_18 , V_306 ;
for ( V_306 = - 1 , V_18 = 0 ; V_18 < V_2 -> V_206 ; V_18 ++ )
if ( memcmp ( V_506 , V_2 -> V_375 [ V_18 ] . V_91 , 6 ) == 0 )
V_306 = V_18 ;
if ( V_306 == - 1 ) {
if ( V_2 -> V_206 == V_507 )
return;
V_306 = V_2 -> V_206 ++ ;
memcpy ( V_2 -> V_375 [ V_306 ] . V_91 , V_506 , 6 ) ;
V_2 -> V_375 [ V_306 ] . V_388 = V_504 ;
} else {
if ( V_504 > V_2 -> V_375 [ V_306 ] . V_388 )
V_2 -> V_375 [ V_306 ] . V_388 = V_504 ;
if ( V_505 )
return;
}
V_2 -> V_375 [ V_306 ] . V_199 = V_199 ;
V_2 -> V_375 [ V_306 ] . V_289 = V_289 ;
V_2 -> V_375 [ V_306 ] . V_391 = V_466 & V_497 ;
memcpy ( V_2 -> V_375 [ V_306 ] . V_203 , V_490 , V_489 ) ;
V_2 -> V_375 [ V_306 ] . V_378 = V_489 ;
if ( V_466 & V_508 )
V_2 -> V_375 [ V_306 ] . V_382 = V_86 ;
else if ( V_466 & V_496 )
V_2 -> V_375 [ V_306 ] . V_382 = V_174 ;
V_2 -> V_375 [ V_306 ] . V_274 = V_466 & V_469 ?
V_470 : V_275 ;
}
static void F_143 ( struct V_1 * V_2 , T_1 V_509 )
{
struct V_476 * V_477 = (struct V_476 * ) V_2 -> V_125 ;
T_1 V_23 = F_41 ( V_477 -> V_23 ) ;
T_1 V_510 = F_41 ( V_477 -> V_479 ) ;
T_1 system = F_41 ( V_477 -> V_323 ) ;
if ( V_23 == V_511 && ! V_2 -> V_83 ) {
if ( V_2 -> V_272 ) {
F_55 ( V_2 , V_252 ) ;
F_139 ( V_2 , 1 ) ;
return;
} else {
F_55 ( V_2 , V_251 ) ;
F_139 ( V_2 , 0 ) ;
return;
}
}
if ( V_23 == V_511 && V_2 -> V_83 ) {
int V_512 = 0 ;
if ( V_510 != V_2 -> V_211 )
return;
if ( system == V_513 ) {
if ( V_510 == 0x0002 ) {
V_512 = 1 ;
}
} else if ( system == V_514 ) {
if ( V_510 == 0x0002 &&
V_477 -> V_480 == V_515 ) {
F_138 ( V_2 , system , V_477 -> V_482 , V_477 -> V_481 ) ;
return;
} else if ( V_510 == 0x0004 ) {
V_512 = 1 ;
}
}
if ( V_512 ) {
if ( V_2 -> V_272 ) {
F_55 ( V_2 , V_252 ) ;
F_139 ( V_2 , 1 ) ;
return;
} else {
F_55 ( V_2 , V_251 ) ;
F_139 ( V_2 , 0 ) ;
return;
}
}
}
if ( V_23 == V_516 ) {
if ( system == V_513 ) {
V_2 -> V_210 = 0x001 ;
V_2 -> V_285 = 1 ;
F_138 ( V_2 , V_514 , NULL , 0 ) ;
return;
} else if ( system == V_514
&& V_2 -> V_83 ) {
V_2 -> V_210 = 0x001 ;
V_2 -> V_285 = 0 ;
F_138 ( V_2 , V_513 , NULL , 0 ) ;
return;
} else if ( V_2 -> V_276 ) {
int V_517 ;
V_2 -> V_375 [ ( int ) ( V_2 -> V_503 ) ] . V_199 |= 0x80 ;
if ( ( V_517 = F_141 ( V_2 ) ) != - 1 ) {
F_126 ( V_2 , V_517 ) ;
return;
}
}
}
V_2 -> V_207 = 0 ;
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
}
static void F_144 ( struct V_1 * V_2 , T_1 V_509 , T_1 V_518 )
{
struct V_519 {
T_10 V_466 ;
T_10 V_23 ;
T_10 V_520 ;
T_2 V_480 ;
T_2 V_222 ;
T_2 V_493 [ 4 ] ;
} * V_521 = (struct V_519 * ) V_2 -> V_125 ;
T_1 V_23 = F_41 ( V_521 -> V_23 ) ;
T_1 V_520 = F_41 ( V_521 -> V_520 ) ;
T_1 V_522 = V_521 -> V_222 > 4 ? 4 : V_521 -> V_222 ;
union V_220 V_221 ;
if ( V_509 < 8 + V_522 )
return;
if ( V_23 == V_511 ) {
if ( V_518 == V_523 )
V_2 -> V_208 = 0 ;
else
V_2 -> V_209 = 0 ;
F_145 ( V_2 , V_178 ,
V_524 , V_520 & 0x3fff ) ;
F_146 ( V_2 , V_216 ,
V_525 , V_521 -> V_493 , V_522 ) ;
if ( V_2 -> V_278 == 0 ) {
V_2 -> V_290 = 1 ;
F_66 ( V_2 , V_178 ,
V_526 , V_527 ) ;
F_145 ( V_2 , V_178 ,
V_528 , 1 ) ;
} else {
V_2 -> V_290 = 2 ;
F_66 ( V_2 , V_178 ,
V_526 , V_529 ) ;
F_145 ( V_2 , V_178 ,
V_528 , 2 ) ;
}
V_2 -> V_175 = 1 ;
V_2 -> V_272 = 1 ;
F_55 ( V_2 , V_75 ) ;
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
memcpy ( V_221 . V_223 . V_197 , V_2 -> V_93 , V_226 ) ;
V_221 . V_223 . V_224 = V_225 ;
F_70 ( V_2 -> V_13 , V_227 , & V_221 , NULL ) ;
return;
}
if ( V_518 == V_523 &&
V_23 != V_530 &&
V_23 != V_531 &&
V_2 -> V_208 < V_532 ) {
F_147 ( & V_2 -> V_201 , V_270 + V_533 ) ;
V_2 -> V_208 ++ ;
F_139 ( V_2 , 0 ) ;
return;
}
if ( V_518 == V_534 &&
V_23 != V_530 &&
V_23 != V_531 &&
V_2 -> V_208 < V_532 ) {
F_147 ( & V_2 -> V_201 , V_270 + V_533 ) ;
V_2 -> V_209 ++ ;
F_139 ( V_2 , 1 ) ;
return;
}
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
if ( V_2 -> V_276 ) {
int V_517 ;
V_2 -> V_375 [ ( int ) ( V_2 -> V_503 ) ] . V_199 |= 0x80 ;
if ( ( V_517 = F_141 ( V_2 ) ) != - 1 )
F_126 ( V_2 , V_517 ) ;
}
}
static void F_126 ( struct V_1 * V_2 , int V_517 )
{
struct V_535 * V_506 = & V_2 -> V_375 [ V_517 ] ;
memcpy ( V_2 -> V_93 , V_506 -> V_91 , 6 ) ;
memcpy ( V_2 -> V_203 , V_506 -> V_203 , V_2 -> V_205 = V_506 -> V_378 ) ;
if ( V_2 -> V_45 )
F_58 ( V_2 ) ;
if ( V_506 -> V_382 == V_86 &&
V_2 -> V_85 != V_86 &&
V_2 -> V_278 ) {
V_2 -> V_278 = 0 ;
V_2 -> V_290 = 1 ;
F_66 ( V_2 , V_178 ,
V_526 , V_527 ) ;
F_145 ( V_2 , V_178 ,
V_528 , 1 ) ;
}
V_2 -> V_85 = V_506 -> V_382 ;
V_2 -> V_199 = V_506 -> V_199 & 0x7f ;
V_2 -> V_289 = V_506 -> V_289 ;
if ( V_2 -> V_274 != V_506 -> V_274 ) {
V_2 -> V_274 = V_506 -> V_274 ;
F_66 ( V_2 , V_471 ,
V_472 , V_506 -> V_274 ) ;
}
if ( ! V_2 -> V_83 && V_506 -> V_391 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
return;
}
if ( V_2 -> V_83 && ! V_506 -> V_391 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
return;
}
F_55 ( V_2 , V_249 ) ;
if ( V_2 -> V_85 == V_174 )
F_136 ( V_2 , V_460 ) ;
else
F_136 ( V_2 , V_459 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
int V_517 ;
if ( ! V_2 -> V_276 ) {
F_54 ( V_2 , 1 ) ;
} else {
V_2 -> V_375 [ ( int ) ( V_2 -> V_503 ) ] . V_199 |= 0x80 ;
if ( ( V_517 = F_141 ( V_2 ) ) != - 1 )
F_126 ( V_2 , V_517 ) ;
else
F_54 ( V_2 , 0 ) ;
}
}
static void F_149 ( struct V_1 * V_2 , T_2 V_504 )
{
T_2 V_536 = V_2 -> V_126 . V_182 . V_183 ;
T_2 V_501 = 42 ;
switch ( V_2 -> V_267 ) {
case V_537 :
V_501 = 63 ;
break;
default:
break;
}
V_504 = V_504 * 100 / V_501 ;
if ( ( V_504 + V_536 ) % 2 )
V_2 -> V_126 . V_182 . V_183 = ( V_504 + V_536 ) / 2 + 1 ;
else
V_2 -> V_126 . V_182 . V_183 = ( V_504 + V_536 ) / 2 ;
V_2 -> V_126 . V_182 . V_184 |= V_538 ;
V_2 -> V_126 . V_182 . V_184 &= ~ V_186 ;
}
static void F_60 ( struct V_1 * V_2 )
{
unsigned long V_539 = ( V_270 - V_2 -> V_269 ) / V_365 ;
while ( V_539 -- ) {
V_2 -> V_269 += V_365 ;
V_2 -> V_126 . V_182 . V_182 = V_2 -> V_126 . V_182 . V_182 / 2 ;
V_2 -> V_126 . V_182 . V_182 +=
V_2 -> V_540 * V_2 -> V_289 * ( V_2 -> V_126 . V_182 . V_183 + 100 ) / 4000 ;
V_2 -> V_540 = 0 ;
}
V_2 -> V_126 . V_182 . V_184 |= V_541 ;
V_2 -> V_126 . V_182 . V_184 &= ~ V_185 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_66 * V_67 ,
T_1 V_509 , T_2 V_504 )
{
T_1 V_518 ;
V_518 = F_41 ( V_67 -> V_95 ) & V_542 ;
switch ( V_518 ) {
case V_543 :
case V_544 :
{
struct V_545 {
T_11 V_546 ;
T_10 V_547 ;
T_10 V_466 ;
T_2 V_488 ;
T_2 V_548 ;
T_2 V_549 ;
T_2 V_550 ;
T_2 V_551 ;
T_2 V_552 ;
} * V_190 = (struct V_545 * ) V_2 -> V_125 ;
T_2 V_199 , V_550 , V_548 ;
T_12 V_546 = F_150 ( V_190 -> V_546 ) ;
T_1 V_553 = F_41 ( V_190 -> V_547 ) ;
T_1 V_466 = F_41 ( V_190 -> V_466 ) ;
T_2 * V_554 = V_2 -> V_125 ;
V_548 = V_190 -> V_548 ;
if ( V_509 < 14 || V_509 < V_548 + 15 )
return;
V_550 = V_554 [ V_190 -> V_548 + 15 ] ;
if ( V_509 < V_548 + V_550 + 18 )
return;
if ( V_548 > V_308 )
return;
V_199 = V_554 [ V_548 + V_550 + 18 ] ;
if ( V_2 -> V_74 == V_75 ) {
F_149 ( V_2 , V_504 ) ;
if ( F_140 ( V_2 , V_67 ) ) {
V_2 -> V_540 ++ ;
F_60 ( V_2 ) ;
if ( V_2 -> V_271 ) {
T_4 V_555 = V_546 - V_2 -> V_271 ;
int V_556 = V_555 / ( V_553 * 1000 ) ;
if ( V_556 > 1 )
V_2 -> V_126 . V_189 . V_190 += V_556 - 1 ;
}
V_2 -> V_271 = V_546 ;
F_137 ( V_2 , V_466 , V_199 ) ;
}
}
if ( V_2 -> V_74 == V_248 )
F_142 ( V_2 , V_67 , V_466 ,
V_553 , V_199 , V_504 ,
V_548 ,
& V_190 -> V_549 ,
V_518 == V_543 ) ;
}
break;
case V_478 :
if ( V_2 -> V_74 == V_250 )
F_143 ( V_2 , V_509 ) ;
break;
case V_523 :
case V_534 :
if ( V_2 -> V_74 == V_251 ||
V_2 -> V_74 == V_252 )
F_144 ( V_2 , V_509 , V_518 ) ;
break;
case V_557 :
if ( V_2 -> V_175 &&
V_2 -> V_85 == V_174 &&
F_140 ( V_2 , V_67 ) ) {
V_2 -> V_272 = 0 ;
V_2 -> V_175 = 0 ;
F_55 ( V_2 , V_249 ) ;
F_136 ( V_2 , V_460 ) ;
}
break;
case V_558 :
if ( V_2 -> V_85 == V_174 &&
F_140 ( V_2 , V_67 ) ) {
V_2 -> V_272 = 0 ;
F_55 ( V_2 , V_249 ) ;
F_136 ( V_2 , V_460 ) ;
}
break;
}
}
static void V_292 ( T_13 V_445 )
{
struct V_12 * V_13 = (struct V_12 * ) V_445 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
unsigned long V_68 ;
if ( V_2 -> V_71 && V_2 -> V_72 &&
! (* V_2 -> V_72 )( V_2 -> V_71 ) )
return;
F_27 ( & V_2 -> V_77 , V_68 ) ;
switch ( V_2 -> V_74 ) {
case V_250 :
if ( V_2 -> V_207 >= V_559 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
V_2 -> V_207 = 0 ;
F_148 ( V_2 ) ;
} else {
int V_477 = V_513 ;
V_2 -> V_207 ++ ;
V_2 -> V_210 = 0x0001 ;
F_147 ( & V_2 -> V_201 , V_270 + V_533 ) ;
if ( V_2 -> V_83 && V_2 -> V_285 )
V_477 = V_514 ;
F_138 ( V_2 , V_477 , NULL , 0 ) ;
}
break;
case V_251 :
if ( V_2 -> V_208 == V_532 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
V_2 -> V_208 = 0 ;
F_148 ( V_2 ) ;
} else {
V_2 -> V_208 ++ ;
F_147 ( & V_2 -> V_201 , V_270 + V_533 ) ;
F_139 ( V_2 , 0 ) ;
}
break;
case V_252 :
if ( V_2 -> V_209 == V_532 ) {
F_55 ( V_2 , V_177 ) ;
V_2 -> V_175 = 0 ;
V_2 -> V_209 = 0 ;
F_148 ( V_2 ) ;
} else {
V_2 -> V_209 ++ ;
F_147 ( & V_2 -> V_201 , V_270 + V_533 ) ;
F_139 ( V_2 , 1 ) ;
}
break;
default:
break;
}
F_28 ( & V_2 -> V_77 , V_68 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_2 V_23 = F_13 ( V_2 , F_2 ( V_2 , V_560 ) ) ;
T_2 V_561 = F_13 ( V_2 , F_2 ( V_2 , V_562 ) ) ;
int V_368 ;
union V_220 V_221 ;
if ( V_23 == V_563 ||
V_23 == V_564 )
return;
switch ( V_561 ) {
case V_465 :
if ( V_23 == V_565 ) {
V_2 -> V_272 = V_2 -> V_175 ;
F_57 ( V_2 , V_178 , V_179 ,
( T_2 * ) V_2 -> V_93 , 6 ) ;
F_55 ( V_2 , V_75 ) ;
}
break;
case V_461 :
V_368 = V_2 -> V_368 ;
V_2 -> V_368 = 0 ;
if ( V_23 != V_565 ) {
F_54 ( V_2 , 1 ) ;
} else {
int V_517 = F_141 ( V_2 ) ;
int V_566 = 1 ;
if ( V_517 != - 1 ) {
F_126 ( V_2 , V_517 ) ;
} else if ( V_2 -> V_85 == V_86 &&
V_2 -> V_205 != 0 ) {
V_254 ( V_2 , V_459 ) ;
} else {
V_2 -> V_368 = ! V_368 ;
F_54 ( V_2 , 1 ) ;
V_566 = 0 ;
}
V_2 -> V_212 = V_372 ;
if ( V_566 ) {
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
F_70 ( V_2 -> V_13 , V_567 , & V_221 , NULL ) ;
}
}
break;
case V_568 :
V_2 -> V_368 = 0 ;
if ( V_23 != V_565 )
return;
V_2 -> V_212 = V_372 ;
if ( V_2 -> V_175 ) {
F_55 ( V_2 , V_75 ) ;
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
F_70 ( V_2 -> V_13 , V_567 , & V_221 , NULL ) ;
} else {
F_54 ( V_2 , 1 ) ;
}
break;
case V_464 :
if ( V_23 == V_565 ) {
if ( V_2 -> V_85 == V_86 ) {
V_2 -> V_272 = V_2 -> V_175 ;
F_55 ( V_2 , V_75 ) ;
} else {
int V_477 = V_513 ;
V_2 -> V_207 = 0 ;
F_55 ( V_2 , V_250 ) ;
F_147 ( & V_2 -> V_201 , V_270 + V_533 ) ;
V_2 -> V_210 = 0x0001 ;
if ( V_2 -> V_83 && V_2 -> V_285 )
V_477 = V_514 ;
F_138 ( V_2 , V_477 , NULL , 0 ) ;
}
return;
}
F_54 ( V_2 , 1 ) ;
}
}
static int F_151 ( struct V_1 * V_2 )
{
struct V_569 * V_570 = & V_2 -> V_5 ;
T_1 V_571 , V_572 ;
int V_18 ;
if ( V_2 -> V_242 == V_247 )
F_52 ( V_2 -> V_13 , V_573 ) ;
F_49 ( V_2 -> V_13 , 0x0040 ) ;
F_11 ( V_2 -> V_13 , V_574 , V_575 ) ;
if ( V_2 -> V_242 == V_247 )
F_152 ( 100 ) ;
for ( V_18 = V_576 ; V_18 ; V_18 -- ) {
V_571 = F_9 ( V_2 -> V_13 , V_577 ) ;
V_572 = F_9 ( V_2 -> V_13 , V_578 ) ;
if ( V_572 & V_579 )
break;
if ( V_571 & V_579 &&
V_2 -> V_228 == V_229 )
break;
}
if ( V_18 == 0 ) {
F_51 ( V_169 L_40 , V_2 -> V_13 -> V_170 ) ;
return - V_580 ;
}
if ( ( V_2 -> V_4 = F_9 ( V_2 -> V_13 , V_581 ) ) == 0xffff ) {
F_51 ( V_169 L_41 , V_2 -> V_13 -> V_170 ) ;
return - V_582 ;
}
F_15 ( V_2 , F_1 ( V_2 , V_583 ) , V_584 ) ;
for ( V_18 = V_576 ; V_18 ; V_18 -- ) {
V_571 = F_9 ( V_2 -> V_13 , V_577 ) ;
V_572 = F_9 ( V_2 -> V_13 , V_578 ) ;
if ( V_572 & V_585 )
break;
if ( V_571 & V_585 &&
V_2 -> V_228 == V_229 )
break;
}
if ( V_18 == 0 ) {
F_51 ( V_169 L_42 ,
V_2 -> V_13 -> V_170 ) ;
return - V_580 ;
}
if ( ( V_572 & V_585 ) &&
! ( F_9 ( V_2 -> V_13 , V_578 ) & V_586 ) ) {
F_51 ( V_169 L_43 , V_2 -> V_13 -> V_170 ) ;
return - V_580 ;
}
if ( ( V_571 & V_585 ) &&
! ( F_9 ( V_2 -> V_13 , V_577 ) & V_586 ) ) {
F_51 ( V_169 L_44 , V_2 -> V_13 -> V_170 ) ;
return - V_580 ;
}
F_36 ( V_2 -> V_13 , ( unsigned char * ) V_570 ,
V_2 -> V_4 , sizeof( * V_570 ) ) ;
V_570 -> V_31 = F_41 ( V_570 -> V_31 ) ;
V_570 -> V_32 = F_41 ( V_570 -> V_32 ) ;
V_570 -> V_10 = F_41 ( V_570 -> V_10 ) ;
V_570 -> V_22 = F_41 ( V_570 -> V_22 ) ;
V_570 -> V_587 = F_41 ( V_570 -> V_587 ) ;
V_570 -> V_588 = F_41 ( V_570 -> V_588 ) ;
V_570 -> V_8 = F_41 ( V_570 -> V_8 ) ;
V_570 -> V_132 = F_41 ( V_570 -> V_132 ) ;
V_570 -> V_241 = F_41 ( V_570 -> V_241 ) ;
V_570 -> V_6 = F_41 ( V_570 -> V_6 ) ;
V_570 -> V_239 = F_41 ( V_570 -> V_239 ) ;
V_570 -> V_240 = F_41 ( V_570 -> V_240 ) ;
V_570 -> V_589 = F_41 ( V_570 -> V_589 ) ;
V_570 -> V_590 = F_41 ( V_570 -> V_590 ) ;
return 0 ;
}
static int F_83 ( struct V_12 * V_13 )
{
int V_264 = 0 ;
struct V_1 * V_2 = F_24 ( V_13 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
F_152 ( 500 ) ;
if ( F_9 ( V_13 , V_581 ) == 0 ) {
int V_18 ;
V_2 -> V_242 = V_243 ;
F_11 ( V_13 , V_574 , V_591 ) ;
F_33 ( V_13 , 0 , V_592 , sizeof( V_592 ) ) ;
F_52 ( V_13 , V_573 ) ;
F_49 ( V_2 -> V_13 , 0x0040 ) ;
F_11 ( V_13 , V_574 , V_575 ) ;
for ( V_18 = V_576 ; V_18 ; V_18 -- )
if ( F_9 ( V_13 , V_578 ) & V_579 )
break;
if ( V_18 == 0 ) {
F_51 ( V_169 L_45 , V_13 -> V_170 ) ;
} else {
F_36 ( V_13 , V_13 -> V_89 , F_9 ( V_13 , V_581 ) , 6 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
V_264 = 1 ;
}
} else if ( F_9 ( V_13 , V_593 ) == 0 ) {
V_2 -> V_242 = V_246 ;
F_11 ( V_13 , V_574 , 1 ) ;
F_36 ( V_13 , V_13 -> V_89 , 0xc000 , 6 ) ;
F_11 ( V_13 , V_574 , 0x200 ) ;
V_264 = 1 ;
} else {
V_2 -> V_242 = V_247 ;
if ( F_151 ( V_2 ) == 0 ) {
F_57 ( V_2 , V_594 , 0 , V_13 -> V_89 , 6 ) ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_13 , V_230 , 0x0060 ) ;
F_11 ( V_13 , V_230 , 0x0040 ) ;
V_264 = 1 ;
}
}
if ( V_264 ) {
if ( V_13 -> V_89 [ 0 ] == 0xFF ) {
static const T_2 V_595 [] = {
0x00 , 0x04 , 0x25 , 0x00 , 0x00 , 0x00
} ;
F_51 ( V_169 L_46 , V_13 -> V_170 ) ;
memcpy ( V_13 -> V_89 , V_595 , 6 ) ;
}
}
return V_264 ;
}
static void F_153 ( struct V_1 * V_2 )
{
struct {
T_2 V_83 ;
T_2 V_283 ;
T_2 V_463 ;
T_2 V_285 ;
T_4 V_596 ;
T_4 V_597 ;
T_2 V_286 [ V_598 ] [ 13 ] ;
T_2 V_284 ;
T_2 V_599 [ 3 ] ;
} V_600 ;
int V_18 ;
V_600 . V_83 = V_2 -> V_83 ;
if ( V_2 -> V_83 ) {
if ( V_2 -> V_287 [ V_2 -> V_283 ] > 5 )
V_600 . V_284 = 2 ;
else
V_600 . V_284 = 1 ;
} else {
V_600 . V_284 = 0 ;
}
V_600 . V_283 = V_2 -> V_283 ;
V_600 . V_285 = V_2 -> V_285 ;
for ( V_18 = 0 ; V_18 < V_598 ; V_18 ++ )
memcpy ( V_600 . V_286 [ V_18 ] , V_2 -> V_286 [ V_18 ] , 13 ) ;
F_146 ( V_2 , V_601 , 0 , ( T_2 * ) & V_600 , sizeof( V_600 ) ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct {
T_2 V_602 [ V_598 ] [ V_603 ] ;
T_2 V_604 [ 6 ] ;
T_2 V_83 ;
T_2 V_283 ;
T_2 V_605 ;
T_2 V_285 ;
T_2 V_606 ;
T_2 V_463 ;
T_4 V_596 ;
T_4 V_597 ;
T_2 V_607 [ 4 ] [ 8 ] ;
} V_600 ;
int V_18 ;
V_600 . V_83 = V_2 -> V_83 ;
V_600 . V_285 = V_2 -> V_285 ;
memcpy ( V_600 . V_604 , V_2 -> V_93 , 6 ) ;
memset ( V_600 . V_602 , 0 , sizeof( V_600 . V_602 ) ) ;
if ( V_2 -> V_83 ) {
memset ( V_600 . V_607 , 0 , sizeof( V_600 . V_607 ) ) ;
V_600 . V_283 = V_600 . V_605 = 255 ;
for ( V_18 = 0 ; V_18 < V_598 ; V_18 ++ ) {
if ( V_2 -> V_287 [ V_18 ] > 0 ) {
memcpy ( V_600 . V_602 [ V_18 ] , V_2 -> V_286 [ V_18 ] , V_603 ) ;
if ( V_18 == V_2 -> V_283 ) {
V_600 . V_283 = V_18 ;
V_600 . V_602 [ V_18 ] [ V_603 - 1 ] = 7 ;
V_600 . V_602 [ V_18 ] [ V_603 - 2 ] = V_2 -> V_56 ;
} else {
V_600 . V_605 = V_18 ;
V_2 -> V_52 = V_2 -> V_56 ;
V_600 . V_602 [ V_18 ] [ V_603 - 1 ] = 1 ;
V_600 . V_602 [ V_18 ] [ V_603 - 2 ] = V_2 -> V_52 ;
}
}
}
if ( V_600 . V_283 == 255 )
V_600 . V_283 = V_600 . V_605 != 255 ? V_600 . V_605 : 0 ;
if ( V_600 . V_605 == 255 )
V_600 . V_605 = V_600 . V_283 ;
}
F_146 ( V_2 , V_601 , 0 , ( T_2 * ) & V_600 , sizeof( V_600 ) ) ;
}
static int F_65 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_24 ( V_13 ) ;
T_2 V_608 ;
int V_450 = V_2 -> V_74 ;
int V_200 = 0 ;
static char * V_609 [] = {
L_47 ,
L_48 ,
NULL
} ;
if ( V_2 -> V_228 == V_229 )
F_11 ( V_2 -> V_13 , V_230 , 0x0060 ) ;
F_11 ( V_2 -> V_13 , V_230 , 0x0040 ) ;
if ( V_2 -> V_242 == V_243 ) {
const struct V_244 * V_610 = NULL ;
const unsigned char * V_611 ;
int V_38 = V_2 -> V_442 ;
if ( ! ( V_611 = V_2 -> V_244 ) ) {
if ( V_2 -> V_267 == V_612 ) {
if ( strlen ( V_2 -> V_245 ) == 0 ) {
F_51 ( V_180
L_49 ,
V_13 -> V_170 ) ;
F_51 ( V_180
L_50 ,
V_13 -> V_170 ) ;
strcpy ( V_2 -> V_245 , L_51 ) ;
}
V_200 = F_154 ( & V_610 , V_2 -> V_245 , V_2 -> V_261 ) ;
if ( V_200 != 0 ) {
F_51 ( V_169
L_52 ,
V_13 -> V_170 , V_2 -> V_245 ) ;
return V_200 ;
}
} else {
int V_613 = 0 ;
int V_614 = 0 ;
while ( V_615 [ V_613 ] . V_259 != V_2 -> V_267
&& V_615 [ V_613 ] . V_259 != V_612 )
V_613 ++ ;
if ( V_615 [ V_613 ] . V_259 != V_612 ) {
int V_18 ;
for ( V_18 = 0 ; V_609 [ V_18 ] ; V_18 ++ ) {
snprintf ( V_2 -> V_245 , 32 , L_53 , V_615 [ V_613 ] . V_616 ,
V_609 [ V_18 ] , V_615 [ V_613 ] . V_617 ) ;
V_2 -> V_245 [ 31 ] = '\0' ;
if ( F_154 ( & V_610 , V_2 -> V_245 , V_2 -> V_261 ) == 0 ) {
V_614 = 1 ;
break;
}
}
}
if ( ! V_614 ) {
F_51 ( V_169
L_54 ,
V_13 -> V_170 , V_2 -> V_245 ) ;
V_2 -> V_245 [ 0 ] = '\0' ;
return - V_618 ;
}
}
V_611 = V_610 -> V_15 ;
V_38 = V_610 -> V_619 ;
}
if ( V_38 <= 0x6000 ) {
F_11 ( V_2 -> V_13 , V_574 , V_591 ) ;
F_33 ( V_2 -> V_13 , 0 , V_611 , V_38 ) ;
F_52 ( V_2 -> V_13 , V_573 ) ;
} else {
F_52 ( V_2 -> V_13 , V_573 ) ;
F_11 ( V_2 -> V_13 , V_574 , V_591 ) ;
F_33 ( V_2 -> V_13 , 0 , V_611 , 0x6000 ) ;
F_11 ( V_2 -> V_13 , V_574 , 0x2ff ) ;
F_33 ( V_2 -> V_13 , 0x8000 , & V_611 [ 0x6000 ] , V_38 - 0x6000 ) ;
}
F_155 ( V_610 ) ;
}
V_200 = F_151 ( V_2 ) ;
if ( V_200 != 0 )
return V_200 ;
V_2 -> V_45 = ( V_2 -> V_5 . V_239 == 4 ) ;
V_2 -> V_620 = ( V_2 -> V_5 . V_239 == 5 ) ;
F_15 ( V_2 , F_1 ( V_2 , V_621 ) , 0xff ) ;
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
V_608 = F_13 ( V_2 , F_1 ( V_2 , V_583 ) ) ;
F_15 ( V_2 , F_1 ( V_2 , V_583 ) ,
V_608 | V_622 ) ;
V_2 -> V_130 = 0 ;
V_608 = F_13 ( V_2 , F_1 ( V_2 , V_583 ) ) ;
F_15 ( V_2 , F_1 ( V_2 , V_583 ) ,
V_608 | V_623 ) ;
if ( ! V_2 -> V_620 ) {
if ( F_156 ( V_2 , V_624 , NULL , 0 ) ==
V_625 ) {
F_51 ( V_180 L_55 ,
V_13 -> V_170 ) ;
return - V_580 ;
}
}
F_66 ( V_2 , V_471 , V_626 , V_2 -> V_277 ) ;
F_66 ( V_2 , V_471 , V_627 , V_628 ) ;
F_145 ( V_2 , V_629 , V_630 , V_2 -> V_280 ) ;
F_145 ( V_2 , V_629 , V_631 , V_2 -> V_279 ) ;
F_66 ( V_2 , V_629 , V_632 , V_2 -> V_281 ) ;
F_66 ( V_2 , V_629 , V_633 , V_2 -> V_282 ) ;
F_66 ( V_2 , V_471 , V_472 , V_2 -> V_274 ) ;
F_146 ( V_2 , V_594 , V_634 ,
V_2 -> V_13 -> V_89 , 6 ) ;
F_66 ( V_2 , V_178 , V_526 , V_527 ) ;
F_145 ( V_2 , V_178 , V_528 , 1 ) ;
F_145 ( V_2 , V_178 , V_635 , V_2 -> V_288 ) ;
F_146 ( V_2 , V_216 , V_525 , V_500 , 4 ) ;
F_66 ( V_2 , V_178 , V_636 , V_2 -> V_83 ) ;
if ( V_2 -> V_45 )
F_58 ( V_2 ) ;
else
F_153 ( V_2 ) ;
if ( V_450 == V_75 ) {
union V_220 V_221 ;
V_221 . V_15 . V_222 = 0 ;
V_221 . V_15 . V_68 = 0 ;
V_221 . V_223 . V_224 = V_225 ;
memset ( V_221 . V_223 . V_197 , 0 , V_226 ) ;
F_70 ( V_2 -> V_13 , V_227 , & V_221 , NULL ) ;
}
return 0 ;
}
static void F_135 ( struct V_1 * V_2 , int V_561 ,
void * V_373 , int V_637 )
{
if ( V_373 )
F_33 ( V_2 -> V_13 , F_2 ( V_2 , V_638 ) ,
V_373 , V_637 ) ;
F_15 ( V_2 , F_2 ( V_2 , V_562 ) , V_561 ) ;
F_15 ( V_2 , F_2 ( V_2 , V_560 ) , 0 ) ;
}
static int F_156 ( struct V_1 * V_2 , int V_561 ,
void * V_373 , int V_637 )
{
int V_18 , V_23 ;
F_135 ( V_2 , V_561 , V_373 , V_637 ) ;
for ( V_18 = 5000 ; V_18 ; V_18 -- ) {
V_23 = F_13 ( V_2 , F_2 ( V_2 , V_560 ) ) ;
if ( V_23 != V_563 &&
V_23 != V_564 )
break;
F_157 ( 20 ) ;
}
if ( V_18 == 0 ) {
F_51 ( V_169 L_1 , V_2 -> V_13 -> V_170 ) ;
V_23 = V_639 ;
} else {
if ( V_561 != V_624 )
V_23 = V_565 ;
}
return V_23 ;
}
static T_2 F_67 ( struct V_1 * V_2 , T_2 type , T_2 V_306 )
{
struct V_640 V_363 ;
V_363 . type = type ;
V_363 . V_619 = 1 ;
V_363 . V_306 = V_306 ;
F_156 ( V_2 , V_641 , & V_363 , V_642 + 1 ) ;
return F_13 ( V_2 , F_2 ( V_2 , V_638 + V_642 ) ) ;
}
static void F_66 ( struct V_1 * V_2 , T_2 type , T_2 V_306 , T_2 V_15 )
{
struct V_640 V_363 ;
V_363 . type = type ;
V_363 . V_619 = 1 ;
V_363 . V_306 = V_306 ;
V_363 . V_15 [ 0 ] = V_15 ;
F_156 ( V_2 , V_643 , & V_363 , V_642 + 1 ) ;
}
static void F_145 ( struct V_1 * V_2 , T_2 type , T_2 V_306 ,
T_1 V_15 )
{
struct V_640 V_363 ;
V_363 . type = type ;
V_363 . V_619 = 2 ;
V_363 . V_306 = V_306 ;
V_363 . V_15 [ 0 ] = V_15 ;
V_363 . V_15 [ 1 ] = V_15 >> 8 ;
F_156 ( V_2 , V_643 , & V_363 , V_642 + 2 ) ;
}
static void F_146 ( struct V_1 * V_2 , T_2 type , T_2 V_306 ,
T_2 * V_15 , int V_644 )
{
struct V_640 V_363 ;
V_363 . type = type ;
V_363 . V_619 = V_644 ;
V_363 . V_306 = V_306 ;
if ( V_644 > V_645 )
F_51 ( V_169 L_56 , V_2 -> V_13 -> V_170 ) ;
memcpy ( V_363 . V_15 , V_15 , V_644 ) ;
F_156 ( V_2 , V_643 , & V_363 , V_642 + V_644 ) ;
}
static void F_57 ( struct V_1 * V_2 , T_2 type , T_2 V_306 ,
T_2 * V_15 , int V_644 )
{
struct V_640 V_363 ;
V_363 . type = type ;
V_363 . V_619 = V_644 ;
V_363 . V_306 = V_306 ;
if ( V_644 > V_645 )
F_51 ( V_169 L_56 , V_2 -> V_13 -> V_170 ) ;
F_156 ( V_2 , V_641 , & V_363 , V_642 + V_644 ) ;
F_36 ( V_2 -> V_13 , V_15 ,
F_2 ( V_2 , V_638 + V_642 ) , V_644 ) ;
}
static void F_14 ( struct V_12 * V_13 , T_1 V_15 )
{
int V_18 ;
F_12 ( V_15 , V_13 -> V_14 + V_646 ) ;
for ( V_18 = 0 ; V_15 != F_10 ( V_13 -> V_14 + V_646 ) && V_18 < 10 ; V_18 ++ )
F_12 ( V_15 , V_13 -> V_14 + V_646 ) ;
}
static void F_33 ( struct V_12 * V_13 , T_1 V_647 ,
const unsigned char * V_648 , T_1 V_38 )
{
int V_18 ;
F_14 ( V_13 , V_647 ) ;
if ( V_647 % 2 ) {
F_7 ( V_13 , V_17 , * V_648 ) ;
V_648 ++ ; V_38 -- ;
}
for ( V_18 = V_38 ; V_18 > 1 ; V_18 -= 2 ) {
T_2 V_649 = * V_648 ++ ;
T_2 V_650 = * V_648 ++ ;
F_11 ( V_13 , V_17 , V_649 | ( V_650 << 8 ) ) ;
}
if ( V_18 )
F_7 ( V_13 , V_17 , * V_648 ) ;
}
static void F_36 ( struct V_12 * V_13 , unsigned char * V_647 ,
T_1 V_648 , T_1 V_38 )
{
int V_18 ;
F_14 ( V_13 , V_648 ) ;
if ( V_648 % 2 ) {
* V_647 = F_5 ( V_13 , V_17 ) ;
V_647 ++ ; V_38 -- ;
}
for ( V_18 = V_38 ; V_18 > 1 ; V_18 -= 2 ) {
T_1 V_651 = F_9 ( V_13 , V_17 ) ;
* V_647 ++ = V_651 ;
* V_647 ++ = V_651 >> 8 ;
}
if ( V_18 )
* V_647 = F_5 ( V_13 , V_17 ) ;
}
static void F_52 ( struct V_12 * V_13 , T_1 V_652 )
{
F_12 ( F_10 ( V_13 -> V_14 + V_230 ) | V_652 , V_13 -> V_14 + V_230 ) ;
}
static void F_49 ( struct V_12 * V_13 , T_1 V_652 )
{
F_12 ( F_10 ( V_13 -> V_14 + V_230 ) & ~ V_652 , V_13 -> V_14 + V_230 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
int V_18 , V_395 = 20 ;
V_653:
for ( V_18 = 5000 ; V_18 ; V_18 -- ) {
if ( ! F_13 ( V_2 , F_1 ( V_2 , V_654 ) ) )
break;
F_157 ( 20 ) ;
}
if ( ! V_18 )
return 0 ;
F_15 ( V_2 , F_1 ( V_2 , V_172 ) , 1 ) ;
if ( F_13 ( V_2 , F_1 ( V_2 , V_654 ) ) ) {
F_15 ( V_2 , F_1 ( V_2 , V_172 ) , 0 ) ;
if ( ! V_395 -- )
return 0 ;
goto V_653;
}
return 1 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_16 , T_4 V_15 )
{
F_14 ( V_2 -> V_13 , V_16 ) ;
F_11 ( V_2 -> V_13 , V_17 , V_15 ) ;
F_11 ( V_2 -> V_13 , V_17 , V_15 >> 16 ) ;
}
