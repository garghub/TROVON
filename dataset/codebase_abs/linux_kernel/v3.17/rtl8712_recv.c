int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
int V_8 = V_9 ;
T_1 V_10 = 0 ;
int V_11 = 0 ;
struct V_12 * V_13 = NULL ;
F_2 ( & V_2 -> V_14 ) ;
V_2 -> V_15 = F_3 ( V_16 * sizeof( struct V_6 ) + 4 ,
V_17 ) ;
if ( V_2 -> V_15 == NULL )
return V_18 ;
V_2 -> V_19 = V_2 -> V_15 + 4 -
( ( T_1 ) ( V_2 -> V_15 ) & 3 ) ;
V_7 = (struct V_6 * ) V_2 -> V_19 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ ) {
F_4 ( & V_7 -> V_20 ) ;
F_5 ( & V_7 -> V_21 ) ;
V_8 = F_6 ( V_4 , V_7 ) ;
if ( V_8 == V_18 )
break;
V_7 -> V_22 = 0 ;
V_7 -> V_23 = V_4 ;
F_7 ( & V_7 -> V_20 ,
& ( V_2 -> V_14 . V_24 ) ) ;
V_7 ++ ;
}
V_2 -> V_25 = V_16 ;
F_8 ( & V_2 -> V_26 ,
( void (*) ( unsigned long ) ) V_26 ,
( unsigned long ) V_4 ) ;
F_9 ( & V_2 -> V_27 ) ;
F_9 ( & V_2 -> V_28 ) ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
V_13 = F_10 ( V_4 -> V_30 , V_31 +
V_32 ) ;
if ( V_13 ) {
V_10 = ( T_1 ) V_13 -> V_33 ;
V_11 = V_10 & ( V_32 - 1 ) ;
F_11 ( V_13 , ( V_32 - V_11 ) ) ;
F_12 ( & V_2 -> V_28 , V_13 ) ;
}
V_13 = NULL ;
}
return V_8 ;
}
void F_13 ( struct V_1 * V_2 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_3 * V_4 = V_2 -> V_23 ;
V_7 = (struct V_6 * ) V_2 -> V_19 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ ) {
F_14 ( V_4 , V_7 ) ;
V_7 ++ ;
}
F_15 ( V_2 -> V_15 ) ;
F_16 ( & V_2 -> V_27 ) ;
if ( F_17 ( & V_2 -> V_27 ) )
F_18 ( V_4 -> V_30 , L_1 ) ;
F_16 ( & V_2 -> V_28 ) ;
if ( F_17 ( & V_2 -> V_28 ) )
F_18 ( V_4 -> V_30 , L_2 ,
F_17 ( & V_2 -> V_28 ) ) ;
}
int F_19 ( struct V_3 * V_4 , struct V_6 * V_7 )
{
V_7 -> V_34 = 0 ;
V_7 -> V_35 = 0 ;
V_7 -> V_22 = 0 ;
if ( V_7 -> V_36 ) {
V_7 -> V_37 = V_7 -> V_36 ;
V_7 -> V_38 = V_7 -> V_36 ;
V_7 -> V_39 = V_7 -> V_36 ;
V_7 -> V_40 = V_7 -> V_37 + V_31 ;
}
return V_9 ;
}
int F_20 ( union V_41 * V_42 ,
struct V_43 * V_44 )
{
unsigned long V_45 ;
struct V_3 * V_4 = V_42 -> V_46 . V_47 . V_23 ;
struct V_1 * V_2 = & V_4 -> V_48 ;
if ( V_42 -> V_46 . V_47 . V_49 ) {
F_21 ( V_42 -> V_46 . V_47 . V_49 ) ;
V_42 -> V_46 . V_47 . V_49 = NULL ;
}
F_22 ( & V_44 -> V_50 , V_45 ) ;
F_23 ( & ( V_42 -> V_46 . V_47 . V_20 ) ) ;
F_7 ( & ( V_42 -> V_46 . V_47 . V_20 ) , & V_44 -> V_24 ) ;
if ( V_4 != NULL ) {
if ( V_44 == & V_2 -> V_51 )
V_2 -> V_52 ++ ;
}
F_24 ( & V_44 -> V_50 , V_45 ) ;
return V_9 ;
}
static void F_25 ( struct V_53 * V_54 ,
struct V_55 * V_56 )
{
T_2 * V_57 ;
struct V_58 * V_59 ;
T_3 V_60 = 0 ;
V_60 = ( F_26 ( V_56 -> V_61 ) & 0x000f0000 ) >> 16 ;
V_60 = V_60 << 3 ;
V_54 -> V_62 = ( ( F_26 ( V_56 -> V_61 ) & F_27 ( 27 ) ) >> 27 )
? 0 : 1 ;
V_54 -> V_63 = ( ( F_26 ( V_56 -> V_61 ) & F_27 ( 14 ) ) >> 14 ) ;
if ( F_26 ( V_56 -> V_64 ) & F_27 ( 13 ) ) {
V_54 -> V_65 = 1 ;
if ( F_26 ( V_56 -> V_64 ) & F_27 ( 11 ) )
V_54 -> V_66 = 1 ;
else
V_54 -> V_66 = 0 ;
if ( F_26 ( V_56 -> V_64 ) & F_27 ( 12 ) )
V_54 -> V_67 = 1 ;
else
V_54 -> V_67 = 0 ;
} else
V_54 -> V_65 = 0 ;
V_54 -> V_68 = ( V_69 ) ( ( F_26 ( V_56 -> V_64 ) ) & 0x3f ) ;
V_54 -> V_70 = ( V_69 ) ( ( F_26 ( V_56 -> V_64 ) >> 14 ) & 0x1 ) ;
if ( V_60 ) {
V_59 = (struct V_58 * ) ( V_56 + 1 ) ;
V_57 = ( T_2 * ) V_56 + 1 ;
}
}
static union V_41 * F_28 ( struct V_3 * V_23 ,
struct V_43 * V_71 )
{
struct V_72 * V_73 , * V_38 ;
V_69 * V_33 , V_74 ;
V_69 V_75 ;
struct V_76 * V_77 , * V_78 ;
union V_41 * V_79 , * V_80 ;
struct V_43 * V_44 ;
V_44 = & V_23 -> V_48 . V_51 ;
V_38 = & V_71 -> V_24 ;
V_73 = V_38 -> V_81 ;
V_79 = F_29 ( V_73 , union V_41 , V_46 ) ;
F_23 ( & V_79 -> V_46 . V_20 ) ;
V_77 = & V_79 -> V_46 . V_47 ;
V_75 = 0 ;
if ( V_75 != V_77 -> V_82 . V_83 ) {
F_20 ( V_79 , V_44 ) ;
F_30 ( V_71 , V_44 ) ;
return NULL ;
}
V_75 ++ ;
V_73 = & V_71 -> V_24 ;
V_73 = V_73 -> V_81 ;
V_33 = F_31 ( V_79 ) ;
while ( F_32 ( V_38 , V_73 ) == false ) {
V_80 = F_29 ( V_73 , union V_41 , V_46 ) ;
V_78 = & V_80 -> V_46 . V_47 ;
if ( V_75 != V_78 -> V_82 . V_83 ) {
F_20 ( V_79 , V_44 ) ;
F_30 ( V_71 , V_44 ) ;
return NULL ;
}
V_75 ++ ;
V_74 = V_78 -> V_82 . V_84 + V_78 -> V_82 . V_85 ;
F_33 ( V_80 , V_74 ) ;
F_34 ( V_79 , V_77 -> V_82 . V_86 ) ;
memcpy ( V_77 -> V_87 , V_78 -> V_88 , V_78 -> V_35 ) ;
F_35 ( V_79 , V_78 -> V_35 ) ;
V_77 -> V_82 . V_86 = V_78 -> V_82 . V_86 ;
V_73 = V_73 -> V_81 ;
}
F_30 ( V_71 , V_44 ) ;
return V_79 ;
}
union V_41 * F_36 ( struct V_3 * V_4 ,
union V_41 * V_89 )
{
V_69 V_90 ;
V_69 V_91 ;
V_69 * V_92 ;
struct V_76 * V_77 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_72 * V_38 ;
union V_41 * V_97 = NULL ;
struct V_43 * V_44 , * V_98 ;
V_96 = & V_4 -> V_99 ;
V_77 = & V_89 -> V_46 . V_47 ;
V_44 = & V_4 -> V_48 . V_51 ;
V_90 = V_77 -> V_82 . V_100 ;
V_91 = V_77 -> V_82 . V_83 ;
V_92 = V_77 -> V_82 . V_101 ;
V_94 = F_37 ( V_96 , V_92 ) ;
if ( V_94 == NULL )
V_98 = NULL ;
else
V_98 = & V_94 -> V_102 . V_71 ;
if ( ( V_90 == 0 ) && ( V_91 == 0 ) )
V_97 = V_89 ;
if ( V_90 == 1 ) {
if ( V_98 != NULL ) {
if ( V_91 == 0 ) {
if ( ! F_38 ( & V_98 -> V_24 ) ) {
F_30 ( V_98 ,
V_44 ) ;
}
}
V_38 = & V_98 -> V_24 ;
F_7 ( & V_77 -> V_20 , V_38 ) ;
V_97 = NULL ;
} else {
F_20 ( V_89 , V_44 ) ;
V_97 = NULL ;
}
}
if ( ( V_90 == 0 ) && ( V_91 != 0 ) ) {
if ( V_98 != NULL ) {
V_38 = & V_98 -> V_24 ;
F_7 ( & V_77 -> V_20 , V_38 ) ;
V_89 = F_28 ( V_4 , V_98 ) ;
V_97 = V_89 ;
} else {
F_20 ( V_89 , V_44 ) ;
V_97 = NULL ;
}
}
if ( ( V_97 != NULL ) && ( V_97 -> V_46 . V_47 . V_82 . V_103 ) ) {
if ( F_39 ( V_4 , V_97 ) == V_18 ) {
F_20 ( V_97 , V_44 ) ;
V_97 = NULL ;
}
}
return V_97 ;
}
static int F_40 ( struct V_3 * V_4 , union V_41 * V_79 )
{
int V_104 , V_105 ;
T_3 V_106 , V_107 ;
V_69 V_108 , V_5 ;
unsigned char * V_109 , * V_37 ;
struct V_53 * V_54 ;
T_4 * V_110 , * V_111 [ V_112 ] ;
struct V_1 * V_2 = & V_4 -> V_48 ;
struct V_43 * V_44 = & ( V_2 -> V_51 ) ;
V_108 = 0 ;
V_54 = & V_79 -> V_46 . V_47 . V_82 ;
F_33 ( V_79 , V_79 -> V_46 . V_47 . V_82 . V_84 ) ;
if ( V_79 -> V_46 . V_47 . V_82 . V_85 > 0 )
F_33 ( V_79 , V_79 -> V_46 . V_47 . V_82 . V_85 ) ;
V_104 = V_79 -> V_46 . V_47 . V_35 ;
V_37 = V_79 -> V_46 . V_47 . V_88 ;
while ( V_104 > V_113 ) {
V_107 = * ( ( T_3 * ) ( V_37 + 12 ) ) ;
V_107 = ( V_107 >> 8 ) +
( V_107 << 8 ) ;
if ( V_104 < ( V_114 + V_107 ) ) {
F_18 ( V_4 -> V_30 , L_3 ,
V_104 , V_107 ) ;
goto exit;
}
V_37 += V_113 ;
V_104 -= V_113 ;
V_110 = F_41 ( V_107 + 12 ) ;
if ( ! V_110 )
break;
F_11 ( V_110 , 12 ) ;
V_109 = ( V_69 * ) F_42 ( V_110 , V_107 ) ;
memcpy ( V_109 , V_37 , V_107 ) ;
V_111 [ V_108 ++ ] = V_110 ;
if ( V_108 >= V_112 ) {
F_18 ( V_4 -> V_30 , L_4 ) ;
break;
}
V_37 += V_107 ;
V_104 -= V_107 ;
if ( V_104 != 0 ) {
V_105 = 4 - ( ( V_107 + V_113 ) & 3 ) ;
if ( V_105 == 4 )
V_105 = 0 ;
if ( V_104 < V_105 )
goto exit;
V_37 += V_105 ;
V_104 -= V_105 ;
}
}
for ( V_5 = 0 ; V_5 < V_108 ; V_5 ++ ) {
V_110 = V_111 [ V_5 ] ;
V_106 = ( V_110 -> V_33 [ 6 ] << 8 ) | V_110 -> V_33 [ 7 ] ;
if ( V_110 -> V_35 >= 8 &&
( ( ! memcmp ( V_110 -> V_33 , V_115 , V_116 ) &&
V_106 != V_117 && V_106 != V_118 ) ||
! memcmp ( V_110 -> V_33 , V_119 , V_116 ) ) ) {
F_43 ( V_110 , V_116 ) ;
memcpy ( F_44 ( V_110 , V_120 ) , V_54 -> V_121 ,
V_120 ) ;
memcpy ( F_44 ( V_110 , V_120 ) , V_54 -> V_122 ,
V_120 ) ;
} else {
T_3 V_35 ;
V_35 = F_45 ( V_110 -> V_35 ) ;
memcpy ( F_44 ( V_110 , 2 ) , & V_35 , 2 ) ;
memcpy ( F_44 ( V_110 , V_120 ) , V_54 -> V_121 ,
V_120 ) ;
memcpy ( F_44 ( V_110 , V_120 ) , V_54 -> V_122 ,
V_120 ) ;
}
if ( V_110 ) {
V_110 -> V_123 =
F_46 ( V_110 , V_4 -> V_30 ) ;
V_110 -> V_124 = V_4 -> V_30 ;
if ( ( V_54 -> V_65 == 1 ) &&
( V_54 -> V_66 == 1 ) ) {
V_110 -> V_125 = V_126 ;
} else
V_110 -> V_125 = V_127 ;
F_47 ( V_110 ) ;
}
}
exit:
V_79 -> V_46 . V_47 . V_35 = 0 ;
F_20 ( V_79 , V_44 ) ;
return V_9 ;
}
void F_48 ( struct V_3 * V_4 , void * V_128 )
{
T_5 V_129 ;
V_69 * V_130 ;
T_3 V_131 , V_132 , V_60 ;
V_69 V_133 , V_134 ;
struct V_55 * V_56 ;
V_130 = ( V_69 * ) V_128 ;
V_129 = * ( T_5 * ) V_130 ;
V_131 = F_26 ( V_129 ) & 0x00003fff ;
V_56 = (struct V_55 * ) V_128 ;
V_60 = ( ( F_26 ( V_56 -> V_61 ) & 0x000f0000 ) >> 16 ) ;
V_60 = V_60 << 3 ;
V_130 += V_135 + V_60 ;
do {
V_129 = * ( T_5 * ) V_130 ;
V_132 = ( T_3 ) ( F_26 ( V_129 ) & 0xffff ) ;
V_134 = ( V_69 ) ( ( F_26 ( V_129 ) >> 24 ) & 0x7f ) ;
V_133 = ( V_69 ) ( ( F_26 ( V_129 ) >> 16 ) & 0xff ) ;
F_49 ( V_4 , ( T_5 * ) V_130 ) ;
V_130 += ( V_132 + 8 ) ;
} while ( F_26 ( V_129 ) & F_27 ( 31 ) );
}
static int F_50 ( struct V_136 * V_137 ,
T_3 V_138 )
{
V_69 V_139 = V_137 -> V_140 ;
T_3 V_141 = ( V_137 -> V_142 + V_139 - 1 ) % 4096 ;
if ( V_137 -> V_142 == 0xffff )
V_137 -> V_142 = V_138 ;
if ( F_51 ( V_138 , V_137 -> V_142 ) )
return false ;
if ( F_52 ( V_138 , V_137 -> V_142 ) )
V_137 -> V_142 = ( V_137 -> V_142 +
1 ) % 4096 ;
else if ( F_51 ( V_141 , V_138 ) ) {
if ( V_138 >= ( V_139 - 1 ) )
V_137 -> V_142 = V_138 + 1 - V_139 ;
else
V_137 -> V_142 = 4095 - ( V_139 -
( V_138 + 1 ) ) + 1 ;
}
return true ;
}
static int F_53 ( struct V_136 * V_137 ,
union V_41 * V_79 )
{
struct V_72 * V_38 , * V_73 ;
union V_41 * V_80 ;
struct V_53 * V_143 ;
struct V_43 * V_144 =
& V_137 -> V_145 ;
struct V_53 * V_54 = & V_79 -> V_46 . V_47 . V_82 ;
V_38 = & V_144 -> V_24 ;
V_73 = V_38 -> V_81 ;
while ( F_32 ( V_38 , V_73 ) == false ) {
V_80 = F_29 ( V_73 , union V_41 , V_46 ) ;
V_143 = & V_80 -> V_46 . V_47 . V_82 ;
if ( F_51 ( V_143 -> V_138 , V_54 -> V_138 ) )
V_73 = V_73 -> V_81 ;
else if ( F_52 ( V_143 -> V_138 , V_54 -> V_138 ) )
return false ;
else
break;
}
F_23 ( & ( V_79 -> V_46 . V_47 . V_20 ) ) ;
F_7 ( & ( V_79 -> V_46 . V_47 . V_20 ) , V_73 ) ;
return true ;
}
int F_54 ( struct V_3 * V_4 ,
struct V_136 * V_137 ,
int V_146 )
{
struct V_72 * V_38 , * V_73 ;
union V_41 * V_79 ;
struct V_53 * V_54 ;
int V_147 = false ;
struct V_1 * V_2 = & V_4 -> V_48 ;
struct V_43 * V_144 =
& V_137 -> V_145 ;
V_38 = & V_144 -> V_24 ;
V_73 = V_38 -> V_81 ;
if ( V_146 == true ) {
if ( F_38 ( V_38 ) )
return true ;
else {
V_79 = F_29 ( V_73 , union V_41 , V_46 ) ;
V_54 = & V_79 -> V_46 . V_47 . V_82 ;
V_137 -> V_142 = V_54 -> V_138 ;
}
}
while ( ! F_38 ( V_38 ) ) {
V_79 = F_29 ( V_73 , union V_41 , V_46 ) ;
V_54 = & V_79 -> V_46 . V_47 . V_82 ;
if ( ! F_51 ( V_137 -> V_142 , V_54 -> V_138 ) ) {
V_73 = V_73 -> V_81 ;
F_23 ( & ( V_79 -> V_46 . V_47 . V_20 ) ) ;
if ( F_52 ( V_137 -> V_142 ,
V_54 -> V_138 ) )
V_137 -> V_142 =
( V_137 -> V_142 + 1 ) % 4096 ;
if ( ! V_54 -> V_148 ) {
if ( ( V_4 -> V_149 == false ) &&
( V_4 -> V_150 == false ) ) {
F_55 ( V_4 ,
V_79 ) ;
}
} else if ( V_54 -> V_148 == 1 ) {
if ( F_40 ( V_4 , V_79 ) !=
V_9 )
F_20 ( V_79 ,
& V_2 -> V_51 ) ;
}
V_147 = false ;
} else {
V_147 = true ;
break;
}
}
return V_147 ;
}
static int F_56 ( struct V_3 * V_4 ,
union V_41 * V_79 )
{
unsigned long V_151 ;
struct V_53 * V_54 = & V_79 -> V_46 . V_47 . V_82 ;
struct V_136 * V_137 = V_79 -> V_46 . V_47 . V_137 ;
struct V_43 * V_144 =
& V_137 -> V_145 ;
if ( ! V_54 -> V_148 ) {
F_57 ( V_79 ) ;
if ( V_54 -> V_152 != 1 ) {
if ( ( V_4 -> V_149 == false ) &&
( V_4 -> V_150 == false ) ) {
F_55 ( V_4 , V_79 ) ;
return V_9 ;
} else
return V_18 ;
}
}
F_22 ( & V_144 -> V_50 , V_151 ) ;
if ( ! F_50 ( V_137 , V_54 -> V_138 ) )
goto V_153;
if ( ! F_53 ( V_137 , V_79 ) )
goto V_153;
if ( F_54 ( V_4 , V_137 , false ) ==
true ) {
F_58 ( & V_137 -> V_154 ,
V_155 ) ;
F_24 ( & V_144 -> V_50 , V_151 ) ;
} else {
F_24 ( & V_144 -> V_50 , V_151 ) ;
F_59 ( & V_137 -> V_154 ) ;
}
return V_9 ;
V_153:
F_24 ( & V_144 -> V_50 , V_151 ) ;
return V_18 ;
}
void F_60 ( void * V_156 )
{
unsigned long V_151 ;
struct V_136 * V_137 =
(struct V_136 * ) V_156 ;
struct V_3 * V_4 = V_137 -> V_4 ;
struct V_43 * V_144 =
& V_137 -> V_145 ;
if ( V_4 -> V_149 || V_4 -> V_150 )
return;
F_22 ( & V_144 -> V_50 , V_151 ) ;
F_54 ( V_4 , V_137 , true ) ;
F_24 ( & V_144 -> V_50 , V_151 ) ;
}
static int F_61 ( struct V_3 * V_4 ,
union V_41 * V_79 )
{
int V_157 = V_9 ;
struct V_158 * V_159 = & V_4 -> V_160 ;
struct V_161 * V_162 = & V_159 -> V_163 ;
if ( V_162 -> V_164 == 1 ) {
if ( F_56 ( V_4 , V_79 ) != V_9 ) {
if ( ( V_4 -> V_149 == false ) &&
( V_4 -> V_150 == false ) )
return V_18 ;
}
} else {
V_157 = F_57 ( V_79 ) ;
if ( V_157 != V_9 )
return V_157 ;
if ( ( V_4 -> V_149 == false ) &&
( V_4 -> V_150 == false ) ) {
F_55 ( V_4 , V_79 ) ;
} else
return V_18 ;
}
return V_157 ;
}
static V_69 F_62 ( T_6 V_165 )
{
if ( ( V_165 <= - 100 ) || ( V_165 >= 20 ) )
return 0 ;
else if ( V_165 >= 0 )
return 100 ;
else
return 100 + V_165 ;
}
static V_69 F_63 ( T_6 V_166 )
{
T_6 V_167 ;
V_167 = V_166 ;
if ( V_167 >= 0 )
V_167 = 0 ;
if ( V_167 <= - 33 )
V_167 = - 33 ;
V_167 = - V_167 ;
V_167 *= 3 ;
if ( V_167 == 99 )
V_167 = 100 ;
return V_167 ;
}
T_7 F_64 ( T_7 V_168 )
{
T_7 V_169 ;
if ( V_168 >= 51 && V_168 <= 100 )
V_169 = 100 ;
else if ( V_168 >= 41 && V_168 <= 50 )
V_169 = 80 + ( ( V_168 - 40 ) * 2 ) ;
else if ( V_168 >= 31 && V_168 <= 40 )
V_169 = 66 + ( V_168 - 30 ) ;
else if ( V_168 >= 21 && V_168 <= 30 )
V_169 = 54 + ( V_168 - 20 ) ;
else if ( V_168 >= 10 && V_168 <= 20 )
V_169 = 42 + ( ( ( V_168 - 10 ) * 2 ) / 3 ) ;
else if ( V_168 >= 5 && V_168 <= 9 )
V_169 = 22 + ( ( ( V_168 - 5 ) * 3 ) / 2 ) ;
else if ( V_168 >= 1 && V_168 <= 4 )
V_169 = 6 + ( ( ( V_168 - 1 ) * 3 ) / 2 ) ;
else
V_169 = V_168 ;
return V_169 ;
}
static T_7 F_65 ( struct V_3 * V_4 , V_69 V_170 )
{
T_7 V_171 ;
V_171 = ( T_7 ) ( ( V_170 + 1 ) >> 1 ) ;
V_171 -= 95 ;
return V_171 ;
}
static void F_66 ( struct V_3 * V_4 ,
union V_41 * V_79 )
{
V_69 V_5 , V_172 , V_173 ;
struct V_55 * V_56 = (struct V_55 * ) V_79 -> V_46 . V_47 . V_174 ;
struct V_58 * V_59 = (struct V_58 * ) ( V_56 + 1 ) ;
V_69 * V_175 = ( V_69 * ) ( V_56 + 1 ) ;
T_6 V_176 [ 4 ] , V_177 ;
V_69 V_178 ;
T_2 V_179 , V_180 = 0 ;
V_69 V_181 = 0 , V_182 = 0 , V_183 = 0 ;
struct V_184 * V_185 ;
V_69 V_186 ;
V_181 = ( V_79 -> V_46 . V_47 . V_82 . V_68 <= 3 ? 1 : 0 ) ;
if ( V_181 ) {
V_69 V_187 ;
V_185 = (struct V_184 * ) V_59 ;
if ( ! V_183 ) {
V_187 = V_185 -> V_188 & 0xc0 ;
V_187 = V_187 >> 6 ;
switch ( V_187 ) {
case 0x3 :
V_177 = - 40 - ( V_185 -> V_188 &
0x3e ) ;
break;
case 0x2 :
V_177 = - 20 - ( V_185 -> V_188 &
0x3e ) ;
break;
case 0x1 :
V_177 = - 2 - ( V_185 -> V_188 &
0x3e ) ;
break;
case 0x0 :
V_177 = 14 - ( V_185 -> V_188 &
0x3e ) ;
break;
}
} else {
V_187 = ( ( V_69 ) ( F_26 ( V_59 -> V_189 ) >> 8 ) ) &
0x60 ;
V_187 = V_187 >> 5 ;
switch ( V_187 ) {
case 0x3 :
V_177 = - 40 - ( ( V_185 -> V_188 &
0x1f ) << 1 ) ;
break;
case 0x2 :
V_177 = - 20 - ( ( V_185 -> V_188 &
0x1f ) << 1 ) ;
break;
case 0x1 :
V_177 = - 2 - ( ( V_185 -> V_188 &
0x1f ) << 1 ) ;
break;
case 0x0 :
V_177 = 14 - ( ( V_185 -> V_188 &
0x1f ) << 1 ) ;
break;
}
}
V_178 = F_62 ( V_177 ) ;
V_178 += 6 ;
if ( V_178 > 100 )
V_178 = 100 ;
if ( V_178 > 34 && V_178 <= 42 )
V_178 -= 2 ;
else if ( V_178 > 26 && V_178 <= 34 )
V_178 -= 6 ;
else if ( V_178 > 14 && V_178 <= 26 )
V_178 -= 8 ;
else if ( V_178 > 4 && V_178 <= 14 )
V_178 -= 4 ;
if ( V_178 > 40 )
V_186 = 100 ;
else {
V_186 = V_185 -> V_190 ;
if ( V_185 -> V_190 > 64 )
V_186 = 0 ;
else if ( V_185 -> V_190 < 20 )
V_186 = 100 ;
else
V_186 = ( ( 64 - V_186 ) * 100 ) / 44 ;
}
V_79 -> V_46 . V_47 . V_82 . V_191 = V_186 ;
V_79 -> V_46 . V_47 . V_82 . V_192 [ 0 ] = V_186 ;
V_79 -> V_46 . V_47 . V_82 . V_192 [ 1 ] = - 1 ;
} else {
for ( V_5 = 0 ; V_5 < ( ( V_4 -> V_193 . V_194 ) &
0x0f ) ; V_5 ++ ) {
V_182 ++ ;
V_176 [ V_5 ] = ( ( V_175 [ V_195 + V_5 ]
& 0x3F ) * 2 ) - 110 ;
V_179 = F_62 ( V_176 [ V_5 ] ) ;
V_180 += V_179 ;
}
V_177 = ( ( ( V_175 [ V_196 ] ) >> 1 ) & 0x7f )
- 106 ;
V_178 = F_62 ( V_177 ) ;
{
if ( V_79 -> V_46 . V_47 . V_82 . V_70 &&
V_79 -> V_46 . V_47 . V_82 . V_68 >= 20 &&
V_79 -> V_46 . V_47 . V_82 . V_68 <= 27 ) {
V_172 = 2 ;
} else {
V_172 = 1 ;
}
for ( V_5 = 0 ; V_5 < V_172 ; V_5 ++ ) {
V_173 = F_63 ( ( V_175
[ V_197 + V_5 ] ) ) ;
V_79 -> V_46 . V_47 . V_82 . V_191 =
( V_69 ) ( V_173 & 0xff ) ;
V_79 -> V_46 . V_47 . V_82 . V_192 [ V_5 ] =
( V_69 ) ( V_173 & 0xff ) ;
}
}
}
if ( V_181 )
V_79 -> V_46 . V_47 . V_82 . V_198 =
( V_69 ) F_64 ( V_178 ) ;
else {
if ( V_182 != 0 )
V_79 -> V_46 . V_47 . V_82 . V_198 =
( V_69 ) ( F_64 ( V_180 /=
V_182 ) ) ;
}
}
static void F_67 ( struct V_3 * V_4 ,
union V_41 * V_79 )
{
T_2 V_199 = 0 , V_200 ;
struct V_53 * V_54 ;
if ( V_79 == NULL || V_4 == NULL )
return;
V_54 = & V_79 -> V_46 . V_47 . V_82 ;
if ( V_54 -> V_191 != 0 ) {
if ( V_4 -> V_48 . V_201 . V_202 ++ >=
V_203 ) {
V_4 -> V_48 . V_201 . V_202 =
V_203 ;
V_199 = V_4 -> V_48 . V_201 . V_204
[ V_4 -> V_48 . V_201 . V_205 ] ;
V_4 -> V_48 . V_201 . V_206 -=
V_199 ;
}
V_4 -> V_48 . V_201 . V_206 +=
V_54 -> V_191 ;
V_4 -> V_48 . V_201 . V_204 [ V_4 ->
V_48 . V_201 . V_205 ++ ] =
V_54 -> V_191 ;
if ( V_4 -> V_48 . V_201 . V_205 >=
V_203 )
V_4 -> V_48 . V_201 . V_205 = 0 ;
V_200 = V_4 -> V_48 . V_201 . V_206 /
V_4 -> V_48 . V_201 . V_202 ;
V_4 -> V_48 . signal = ( V_69 ) V_200 ;
}
}
static void F_68 ( struct V_3 * V_4 , union V_41 * V_79 )
{
T_2 V_207 , V_208 ;
struct V_53 * V_54 = & V_79 -> V_46 . V_47 . V_82 ;
if ( V_4 -> V_48 . V_209 . V_202 ++ >=
V_210 ) {
V_4 -> V_48 . V_209 . V_202 =
V_210 ;
V_207 = V_4 -> V_48 . V_209 . V_204
[ V_4 -> V_48 . V_209 . V_205 ] ;
V_4 -> V_48 . V_209 . V_206 -= V_207 ;
}
V_4 -> V_48 . V_209 . V_206 +=
V_54 -> V_198 ;
V_4 -> V_48 . V_209 . V_204 [ V_4 -> V_48 .
V_209 . V_205 ++ ] =
V_54 -> V_198 ;
if ( V_4 -> V_48 . V_209 . V_205 >=
V_210 )
V_4 -> V_48 . V_209 . V_205 = 0 ;
V_208 = V_4 -> V_48 . V_209 . V_206 /
V_4 -> V_48 . V_209 . V_202 ;
V_4 -> V_48 . V_179 = ( T_6 ) F_65 ( V_4 , ( V_69 ) V_208 ) ;
}
static void F_69 ( struct V_3 * V_4 ,
union V_41 * V_79 )
{
F_66 ( V_4 , V_79 ) ;
F_68 ( V_4 , V_79 ) ;
F_67 ( V_4 , V_79 ) ;
}
int F_70 ( struct V_3 * V_4 , void * V_156 )
{
struct V_53 * V_54 ;
union V_41 * V_79 , * V_211 ;
int V_157 = V_9 ;
struct V_43 * V_44 = & V_4 -> V_48 . V_51 ;
struct V_158 * V_159 = & V_4 -> V_160 ;
V_79 = (union V_41 * ) V_156 ;
V_211 = V_79 ;
V_54 = & V_79 -> V_46 . V_47 . V_82 ;
if ( ( F_71 ( V_159 , V_212 ) == true ) ) {
if ( V_54 -> V_63 == 1 )
V_4 -> V_213 . V_214 ++ ;
else
V_4 -> V_213 . V_215 ++ ;
if ( F_71 ( V_159 , V_216 ) == false ) {
F_20 ( V_211 , V_44 ) ;
goto V_217;
}
}
V_157 = F_72 ( V_4 , V_79 ) ;
if ( V_157 != V_9 ) {
F_20 ( V_211 , V_44 ) ;
goto V_217;
}
F_69 ( V_4 , V_79 ) ;
V_79 = F_73 ( V_4 , V_79 ) ;
if ( V_79 == NULL ) {
V_157 = V_18 ;
goto V_217;
}
V_79 = F_36 ( V_4 , V_79 ) ;
if ( V_79 == NULL )
goto V_217;
V_79 = F_74 ( V_4 , V_79 ) ;
if ( V_79 == NULL ) {
V_157 = V_18 ;
goto V_217;
}
V_157 = F_61 ( V_4 , V_79 ) ;
if ( V_157 != V_9 ) {
F_20 ( V_211 , V_44 ) ;
goto V_217;
}
V_217:
return V_157 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
V_69 * V_36 , V_218 = 0 ;
V_69 V_219 , V_220 ;
T_5 V_131 ;
T_2 V_34 ;
struct V_55 * V_56 ;
T_3 V_221 , V_60 , V_222 , V_223 , V_224 ;
struct V_43 * V_44 ;
T_4 * V_225 = NULL ;
union V_41 * V_42 = NULL ;
struct V_1 * V_2 = & V_4 -> V_48 ;
V_44 = & ( V_2 -> V_51 ) ;
V_36 = V_13 -> V_33 ;
V_56 = (struct V_55 * ) V_36 ;
V_221 = ( F_26 ( V_56 -> V_226 ) >> 16 ) & 0xff ;
V_131 = F_26 ( V_56 -> V_61 ) & 0x00003fff ;
V_34 = V_13 -> V_35 ;
if ( V_34 < V_131 ) {
return V_18 ;
}
do {
V_56 = (struct V_55 * ) V_36 ;
V_131 = F_26 ( V_56 -> V_61 ) & 0x00003fff ;
V_220 = ( F_26 ( V_56 -> V_227 ) >> 27 ) & 0x1 ;
V_219 = ( F_26 ( V_56 -> V_226 ) >> 12 ) & 0xf ;
V_60 = ( F_26 ( V_56 -> V_61 ) & 0x000f0000 ) >> 16 ;
V_60 = V_60 << 3 ;
if ( V_131 <= 0 )
goto V_228;
if ( ( F_26 ( V_56 -> V_61 ) >> 23 ) & 0x01 )
V_218 = 2 ;
V_42 = F_76 ( V_44 ) ;
if ( V_42 == NULL )
goto V_228;
F_4 ( & V_42 -> V_46 . V_47 . V_20 ) ;
V_42 -> V_46 . V_47 . V_7 = NULL ;
V_42 -> V_46 . V_47 . V_35 = 0 ;
V_223 = V_131 + V_60 + V_135 ;
V_222 = ( T_3 ) F_77 ( V_223 , 128 ) ;
if ( ( V_220 == 1 ) && ( V_219 == 0 ) )
V_224 = 1658 ;
else
V_224 = V_223 ;
V_224 += 6 ;
V_225 = F_10 ( V_4 -> V_30 , V_224 ) ;
if ( V_225 ) {
V_42 -> V_46 . V_47 . V_49 = V_225 ;
F_11 ( V_225 , 4 - ( ( T_1 ) ( V_225 -> V_33 )
% 4 ) ) ;
F_11 ( V_225 , V_218 ) ;
memcpy ( V_225 -> V_33 , V_36 , V_223 ) ;
V_42 -> V_46 . V_47 . V_174 = V_42 -> V_46 . V_47 . V_88 =
V_42 -> V_46 . V_47 . V_87 = V_225 -> V_33 ;
V_42 -> V_46 . V_47 . V_229 = V_225 -> V_33 + V_224 ;
} else {
V_42 -> V_46 . V_47 . V_49 = F_78 ( V_13 , V_17 ) ;
if ( ! V_42 -> V_46 . V_47 . V_49 )
return V_18 ;
V_42 -> V_46 . V_47 . V_174 = V_36 ;
V_42 -> V_46 . V_47 . V_88 = V_36 ;
V_42 -> V_46 . V_47 . V_87 = V_36 ;
V_42 -> V_46 . V_47 . V_229 = V_36 + V_224 ;
}
F_35 ( V_42 , V_223 ) ;
F_33 ( V_42 , V_60 + V_135 ) ;
F_25 ( & V_42 -> V_46 . V_47 . V_82 ,
V_56 ) ;
F_79 ( V_42 ) ;
V_34 -= V_222 ;
V_36 += V_222 ;
V_221 -- ;
V_42 = NULL ;
V_225 = NULL ;
} while ( ( V_34 > 0 ) && V_221 > 0 );
V_228:
return V_9 ;
}
static void V_26 ( void * V_230 )
{
struct V_12 * V_13 ;
struct V_3 * V_4 = (struct V_3 * ) V_230 ;
struct V_1 * V_2 = & V_4 -> V_48 ;
while ( NULL != ( V_13 = F_80 ( & V_2 -> V_27 ) ) ) {
F_75 ( V_4 , V_13 ) ;
F_81 ( V_13 ) ;
V_13 -> V_35 = 0 ;
if ( ! F_82 ( V_13 ) )
F_12 ( & V_2 -> V_28 , V_13 ) ;
else
F_83 ( V_13 ) ;
}
}
