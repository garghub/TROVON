static void F_1 ( struct V_1 * V_2 , bool V_3 )
{
T_1 V_4 ;
if ( V_3 ) {
V_4 = F_2 ( V_2 , V_5 + 1 ) ;
F_3 ( V_2 , V_5 + 1 , V_4 | 0x04 ) ;
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 | 0x01 ) ;
V_4 = F_2 ( V_2 , V_6 + 2 ) ;
F_3 ( V_2 , V_6 + 2 , V_4 & 0xf7 ) ;
} else {
V_4 = F_2 ( V_2 , V_6 ) ;
F_3 ( V_2 , V_6 , V_4 & 0xfe ) ;
F_3 ( V_2 , V_6 + 1 , 0x00 ) ;
}
}
static int
F_4 ( struct V_1 * V_2 , T_2 V_7 , void * V_8 , T_2 V_9 )
{
T_1 V_10 ;
T_1 V_11 = ( T_1 ) ( V_7 & 0x07 ) ;
if ( V_9 > V_12 )
return V_13 ;
V_10 = ( F_2 ( V_2 , V_6 + 2 ) & 0xF8 ) | V_11 ;
F_3 ( V_2 , V_6 + 2 , V_10 ) ;
return F_5 ( V_2 , V_14 , V_9 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 , void * V_8 , T_2 V_9 )
{
int V_15 = V_16 ;
T_2 V_17 , V_18 ;
T_2 V_7 , V_19 ;
T_1 * V_20 = ( T_1 * ) V_8 ;
V_17 = V_9 / V_12 ;
V_18 = V_9 % V_12 ;
for ( V_7 = 0 ; V_7 < V_17 ; V_7 ++ ) {
V_19 = V_7 * V_12 ;
V_15 = F_4 ( V_2 , V_7 , V_20 + V_19 ,
V_12 ) ;
if ( V_15 == V_13 )
goto exit;
}
if ( V_18 ) {
V_19 = V_17 * V_12 ;
V_7 = V_17 ;
V_15 = F_4 ( V_2 , V_7 , V_20 + V_19 ,
V_18 ) ;
if ( V_15 == V_13 )
goto exit;
}
F_7 ( V_21 , V_22 ,
( L_1 ) ) ;
exit:
return V_15 ;
}
static int F_8 ( struct V_1 * V_2 )
{
T_2 V_23 = 0 ;
T_2 V_24 ;
do {
V_24 = F_9 ( V_2 , V_6 ) ;
if ( V_24 & V_25 )
break;
} while ( V_23 ++ < V_26 );
if ( V_23 >= V_26 ) {
F_7 ( V_21 , V_27 ,
( L_2 ,
V_28 , V_24 ) ) ;
return V_13 ;
}
F_7 ( V_21 , V_22 ,
( L_3 , V_28 ,
V_24 ) ) ;
V_24 = F_9 ( V_2 , V_6 ) ;
V_24 |= V_29 ;
V_24 &= ~ V_30 ;
F_10 ( V_2 , V_6 , V_24 ) ;
V_23 = 0 ;
do {
V_24 = F_9 ( V_2 , V_6 ) ;
if ( V_24 & V_30 ) {
F_7 ( V_21 , V_22 ,
( L_4
L_5 ,
V_28 , V_24 ) ) ;
return V_16 ;
}
F_11 ( 5 ) ;
} while ( V_23 ++ < V_26 );
F_7 ( V_21 , V_27 ,
( L_6 ,
V_28 , V_24 ) ) ;
return V_13 ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
T_1 V_33 ;
T_1 V_34 = 100 ;
if ( ! ( F_14 ( V_2 ) &&
( ( V_32 -> V_35 < 0x21 ) ||
( V_32 -> V_35 == 0x21 &&
V_32 -> V_36 < 0x01 ) ) ) ) {
F_3 ( V_2 , V_37 + 3 , 0x20 ) ;
V_33 = F_2 ( V_2 , V_5 + 1 ) ;
while ( V_33 & F_15 ( 2 ) ) {
V_34 -- ;
if ( V_34 == 0 )
break;
F_11 ( 50 ) ;
V_33 = F_2 ( V_2 , V_5 + 1 ) ;
}
F_7 ( V_21 , V_22 ,
( L_7 , V_28 ,
V_34 ) ) ;
if ( ( V_34 == 0 ) ) {
V_33 = F_2 ( V_2 , V_5 + 1 ) ;
F_3 ( V_2 , V_5 + 1 ,
V_33 & ~ F_15 ( 2 ) ) ;
}
}
}
int F_16 ( struct V_1 * V_2 )
{
int V_38 = V_16 ;
T_1 V_39 = 0 ;
unsigned long V_40 ;
struct V_31 * V_32 = F_13 ( V_2 ) ;
struct V_41 * V_42 = F_17 ( V_2 ) ;
struct V_43 * V_43 = F_18 ( V_42 ) ;
struct V_44 * V_45 = NULL ;
const struct V_46 * V_47 ;
char * V_48 ;
T_1 * V_49 = NULL ;
T_1 * V_50 ;
int V_51 ;
static int V_52 ;
F_7 ( V_21 , V_22 , ( L_8 , V_28 ) ) ;
if ( F_19 ( V_32 -> V_53 ) ) {
V_48 = L_9 ;
F_7 ( V_21 , V_22 ,
( L_10
L_11 ) ) ;
} else if ( F_20 ( V_32 -> V_53 ) ) {
if ( V_2 -> V_54 . V_55 == 1 ) {
V_48 = L_12 ;
F_21 ( L_13
L_14 ) ;
} else {
if ( F_22 ( V_2 ) ) {
V_48 = L_15 ;
F_21 ( L_16
L_17 ) ;
} else {
V_48 = L_12 ;
F_21 ( L_18
L_19 ) ;
}
}
} else {
F_7 ( V_21 , V_27 ,
( L_20 , V_28 ) ) ;
V_38 = V_13 ;
goto Exit;
}
F_23 ( L_21 , V_48 ) ;
if ( F_24 ( & V_47 , V_48 , V_43 ) ) {
F_25 ( L_22 ) ;
V_38 = V_13 ;
goto Exit;
}
if ( ! V_47 ) {
F_25 ( L_23 , V_48 ) ;
V_38 = V_13 ;
goto Exit;
}
V_49 = F_26 ( V_47 -> V_56 , V_47 -> V_9 , V_57 ) ;
if ( ! V_49 ) {
V_38 = V_13 ;
goto Exit;
}
V_50 = V_49 ;
V_51 = V_47 -> V_9 ;
F_27 ( V_47 ) ;
V_45 = (struct V_44 * ) V_49 ;
V_32 -> V_35 = F_28 ( V_45 -> V_58 ) ;
V_32 -> V_36 = V_45 -> V_59 ;
V_32 -> V_60 = F_28 ( V_45 -> V_61 ) ;
F_21 ( L_24 ,
V_28 , V_32 -> V_35 ,
V_32 -> V_36 , V_32 -> V_60 ) ;
if ( ! V_52 ++ )
F_23 ( L_25
L_26 , V_62 , V_32 -> V_35 ,
V_32 -> V_36 ,
V_32 -> V_60 ) ;
if ( F_29 ( V_45 ) ) {
V_50 = V_50 + 32 ;
V_51 = V_51 - 32 ;
}
if ( F_2 ( V_2 , V_6 ) & V_63 ) {
F_12 ( V_2 ) ;
F_3 ( V_2 , V_6 , 0x00 ) ;
}
F_1 ( V_2 , true ) ;
V_40 = V_64 ;
while ( 1 ) {
F_3 ( V_2 , V_6 ,
F_2 ( V_2 , V_6 ) |
V_25 ) ;
V_38 = F_6 ( V_2 , V_50 , V_51 ) ;
if ( V_38 == V_16 ||
( F_30 ( V_64 - V_40 ) > 500 &&
V_39 ++ >= 3 ) )
break;
F_21 ( L_27
L_28 , V_28 , V_39 ,
F_30 ( V_64 - V_40 ) ) ;
}
F_1 ( V_2 , false ) ;
if ( V_16 != V_38 ) {
F_21 ( L_29 ) ;
goto Exit;
}
V_38 = F_8 ( V_2 ) ;
if ( V_16 != V_38 ) {
F_7 ( V_21 , V_27 ,
( L_29 ) ) ;
goto Exit;
}
F_7 ( V_21 , V_22 ,
( L_30 ) ) ;
Exit:
F_31 ( V_49 ) ;
return V_38 ;
}
void F_32 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
V_2 -> V_65 . V_66 = false ;
V_32 -> V_67 = 0 ;
}
static T_1
F_33 ( struct V_1 * V_2 , T_1 V_68 )
{
T_1 V_69 = false ;
T_2 V_24 = 0 ;
F_21 ( L_31 , V_28 , V_68 ) ;
V_24 = F_9 ( V_2 , V_70 ) ;
V_69 = true ;
switch ( V_68 ) {
case 0 :
V_24 = ( V_24 & ~ V_71 ) |
F_34 ( V_72 ) ;
break;
case 1 :
V_24 = ( V_24 & ~ V_71 ) |
F_34 ( V_73 ) ;
break;
case 2 :
V_24 = ( V_24 & ~ V_71 ) |
F_34 ( V_74 ) ;
break;
case 3 :
V_24 = ( V_24 & ~ V_71 ) |
F_34 ( V_75 ) ;
break;
default:
V_24 = ( V_24 & ~ V_71 ) |
F_34 ( V_72 ) ;
V_69 = false ;
break;
}
F_10 ( V_2 , V_70 , V_24 ) ;
return V_69 ;
}
static void
F_35 ( struct V_1 * V_2 ,
T_3 V_76 , T_3 V_77 , T_1 * V_78 )
{
T_1 * V_79 = NULL ;
T_3 V_80 = 0 ;
T_1 V_19 , V_81 ;
T_1 V_82 , V_83 , V_84 ;
T_3 V_85 , V_86 , V_87 ;
struct V_31 * V_32 = F_13 ( V_2 ) ;
if ( ( V_76 + V_77 ) > V_88 ) {
F_21 ( L_32 ,
V_28 , V_76 , V_77 ) ;
return;
}
V_79 = F_36 ( V_88 , V_57 ) ;
if ( V_79 == NULL ) {
F_21 ( L_33 , V_28 ) ;
return;
}
memset ( V_79 , 0xFF , V_88 ) ;
F_33 ( V_2 , 0 ) ;
while ( F_37 ( V_80 ) ) {
F_38 ( V_2 , V_80 ++ , & V_82 ) ;
if ( V_82 == 0xFF ) {
F_21 ( L_34 , V_28 ,
V_80 ) ;
break;
}
if ( F_39 ( V_82 ) ) {
V_19 = F_40 ( V_82 ) ;
F_38 ( V_2 , V_80 ++ , & V_83 ) ;
if ( F_41 ( V_83 ) ) {
continue;
}
V_19 |= ( ( V_83 & 0xF0 ) >> 1 ) ;
V_81 = ( V_83 & 0x0F ) ;
} else {
V_19 = ( ( V_82 >> 4 ) & 0x0f ) ;
V_81 = ( V_82 & 0x0f ) ;
}
if ( V_19 < V_89 ) {
T_3 V_90 ;
V_90 = V_19 * V_91 ;
for ( V_85 = 0 ; V_85 < V_92 ; V_85 ++ ) {
if ( ! ( V_81 & ( 0x01 << V_85 ) ) ) {
F_38 ( V_2 , V_80 ++ ,
& V_84 ) ;
V_79 [ V_90 ] = V_84 ;
F_38 ( V_2 , V_80 ++ ,
& V_84 ) ;
V_79 [ V_90 + 1 ] = V_84 ;
}
V_90 += 2 ;
}
} else {
F_21 ( V_93 L_35 ,
V_28 , V_19 ) ;
V_80 += F_42 ( V_81 ) * 2 ;
}
}
for ( V_85 = 0 ; V_85 < V_77 ; V_85 ++ )
V_78 [ V_85 ] = V_79 [ V_76 + V_85 ] ;
F_43 ( V_2 , V_94 ,
V_95 , & V_86 ) ;
V_87 = V_80 - 1 ;
V_32 -> V_96 = V_87 ;
F_31 ( V_79 ) ;
}
static void
F_44 ( struct V_1 * V_2 ,
T_3 V_76 , T_3 V_77 , T_1 * V_78 )
{
T_1 * V_79 ;
T_1 V_68 ;
T_3 V_80 ;
T_1 V_82 , V_83 , V_84 ;
T_1 V_19 , V_81 ;
T_3 V_85 , V_86 , V_87 ;
struct V_31 * V_32 = F_13 ( V_2 ) ;
if ( ( V_76 + V_77 ) > V_97 ) {
F_21 ( L_32 ,
V_28 , V_76 , V_77 ) ;
return;
}
V_79 = F_36 ( V_97 , V_57 ) ;
if ( V_79 == NULL ) {
F_21 ( L_36 , V_28 ) ;
return;
}
memset ( V_79 , 0xFF , V_97 ) ;
F_43 ( V_2 , V_98 ,
V_99 , & V_86 ) ;
for ( V_68 = 1 ; V_68 < V_100 ; V_68 ++ ) {
if ( F_33 ( V_2 , V_68 ) == false ) {
F_21 ( L_37 ,
V_28 ) ;
goto exit;
}
V_80 = 0 ;
while ( F_37 ( V_80 ) ) {
F_38 ( V_2 , V_80 ++ , & V_82 ) ;
if ( V_82 == 0xFF )
break;
if ( F_39 ( V_82 ) ) {
V_19 = F_40 ( V_82 ) ;
F_38 ( V_2 , V_80 ++ ,
& V_83 ) ;
if ( F_41 ( V_83 ) ) {
continue;
}
V_19 |= ( ( V_83 & 0xF0 ) >> 1 ) ;
V_81 = ( V_83 & 0x0F ) ;
} else {
V_19 = ( ( V_82 >> 4 ) & 0x0f ) ;
V_81 = ( V_82 & 0x0f ) ;
}
if ( V_19 < V_101 ) {
T_3 V_90 ;
V_90 = V_19 * V_91 ;
for ( V_85 = 0 ; V_85 < V_92 ; V_85 ++ ) {
if ( ! ( V_81 & ( 0x01 << V_85 ) ) ) {
F_38 ( V_2 ,
V_80 ++ ,
& V_84 ) ;
V_79 [ V_90 ] = V_84 ;
F_38 ( V_2 ,
V_80 ++ ,
& V_84 ) ;
V_79 [ V_90 + 1 ] = V_84 ;
}
V_90 += 2 ;
}
} else {
F_21 ( V_93
L_35 ,
V_28 , V_19 ) ;
V_80 += F_42 ( V_81 ) * 2 ;
}
}
if ( ( V_80 - 1 ) < V_86 ) {
F_21 ( L_38 ,
V_28 , V_68 , V_80 - 1 ) ;
break;
}
}
F_33 ( V_2 , 0 ) ;
for ( V_85 = 0 ; V_85 < V_77 ; V_85 ++ )
V_78 [ V_85 ] = V_79 [ V_76 + V_85 ] ;
F_43 ( V_2 , V_98 ,
V_95 , & V_86 ) ;
V_87 = ( V_102 * ( V_68 - 1 ) ) + V_80 - 1 ;
V_32 -> V_103 = V_87 ;
exit:
F_31 ( V_79 ) ;
}
void
F_45 ( struct V_1 * V_2 ,
T_1 V_104 , T_3 V_76 , T_3 V_77 , T_1 * V_78 )
{
if ( V_104 == V_94 )
F_35 ( V_2 , V_76 , V_77 , V_78 ) ;
else
F_44 ( V_2 , V_76 , V_77 , V_78 ) ;
}
T_3 F_46 ( struct V_1 * V_2 )
{
T_3 V_105 = 0 ;
T_1 V_106 = 0 , V_107 = 0 ;
T_1 V_108 , V_109 = 0 ;
struct V_31 * V_32 = F_13 ( V_2 ) ;
V_105 = V_32 -> V_96 ;
F_21 ( L_39 , V_28 , V_105 ) ;
F_33 ( V_2 , 0 ) ;
while ( F_37 ( V_105 ) ) {
if ( F_47 ( V_2 , V_105 , & V_108 ) ==
V_13 ) {
F_21 ( V_93 L_40
L_41 , V_28 , V_105 ) ;
break;
}
if ( V_108 == 0xFF )
break;
if ( F_39 ( V_108 ) ) {
V_106 = F_40 ( V_108 ) ;
V_105 ++ ;
F_47 ( V_2 , V_105 , & V_108 ) ;
if ( F_41 ( V_108 ) ) {
continue;
}
V_106 |= ( ( V_108 & 0xF0 ) >> 1 ) ;
V_107 = V_108 & 0x0F ;
} else {
V_106 = ( V_108 >> 4 ) & 0x0F ;
V_107 = V_108 & 0x0F ;
}
V_109 = F_42 ( V_107 ) ;
V_105 += ( V_109 * 2 ) + 1 ;
}
V_32 -> V_96 = V_105 ;
F_21 ( L_42 , V_28 , V_105 ) ;
return V_105 ;
}
T_3 F_48 ( struct V_1 * V_2 )
{
T_3 V_110 ;
T_3 V_105 ;
T_1 V_68 , V_111 ;
T_1 V_106 = 0 , V_107 = 0 ;
T_1 V_108 , V_109 = 0 ;
T_3 V_112 = 0 ;
struct V_31 * V_32 = F_13 ( V_2 ) ;
V_110 = V_32 -> V_103 ;
V_105 = ( T_3 ) ( ( V_110 % V_102 ) ) ;
V_111 = ( T_1 ) ( 1 + ( V_110 / V_102 ) ) ;
F_21 ( L_43 , V_28 , V_111 ,
V_105 ) ;
F_43 ( V_2 , V_98 ,
V_99 , & V_112 ) ;
for ( V_68 = V_111 ; V_68 < V_100 ; V_68 ++ ) {
if ( F_33 ( V_2 , V_68 ) == false ) {
F_21 ( V_93 L_44 ,
V_28 , V_68 ) ;
V_68 = V_100 ;
break;
}
if ( V_68 != V_111 )
V_105 = 0 ;
while ( F_37 ( V_105 ) ) {
if ( F_47 ( V_2 , V_105 ,
& V_108 ) == V_13 ) {
F_21 ( V_93 L_45
L_46 ,
V_28 , V_105 ) ;
V_68 = V_100 ;
break;
}
if ( V_108 == 0xFF )
break;
if ( F_39 ( V_108 ) ) {
V_106 = F_40 ( V_108 ) ;
V_105 ++ ;
F_47 ( V_2 , V_105 ,
& V_108 ) ;
if ( F_41 ( V_108 ) ) {
V_105 ++ ;
continue;
}
V_106 |= ( ( V_108 & 0xF0 ) >> 1 ) ;
V_107 = V_108 & 0x0F ;
} else {
V_106 = ( V_108 >> 4 ) & 0x0F ;
V_107 = V_108 & 0x0F ;
}
V_109 = F_42 ( V_107 ) ;
V_105 += ( V_109 * 2 ) + 1 ;
}
if ( V_105 < V_112 ) {
break;
}
}
V_112 = ( ( V_68 - 1 ) * V_102 ) + V_105 ;
V_32 -> V_103 = V_112 ;
F_21 ( L_42 , V_28 , V_112 ) ;
return V_112 ;
}
void F_49 ( struct V_1 * V_2 )
{
T_2 V_24 ;
struct V_113 V_114 ;
struct V_31 * V_32 ;
V_32 = F_13 ( V_2 ) ;
V_24 = F_9 ( V_2 , V_115 ) ;
V_114 . V_116 = V_117 ;
V_114 . V_118 = ( ( V_24 & V_119 ) ? V_120 : V_121 ) ;
V_114 . V_122 = V_123 ;
V_114 . V_124 =
( ( V_24 & V_125 ) ? V_126 : V_127 ) ;
V_114 . V_128 = ( V_24 & V_129 ) >> V_130 ;
V_32 -> V_131 = ( ( V_24 & V_132 ) ?
V_133 : V_134 ) ;
V_24 = F_9 ( V_2 , V_135 ) ;
V_114 . V_136 = ( ( V_24 & V_137 ) >> 20 ) ;
V_32 -> V_138 = V_139 ;
V_24 = F_9 ( V_2 , V_140 ) ;
V_32 -> V_138 |=
( ( V_24 & V_141 ) ? V_142 : 0 ) ;
V_32 -> V_138 |= ( ( V_24 & V_143 ) ? V_144 : 0 ) ;
V_32 -> V_138 |=
( ( V_24 & V_145 ) ? V_146 : 0 ) ;
V_32 -> V_147 =
( ( V_24 & V_148 ) ? V_149 :
V_150 ) ;
F_50 ( V_114 ) ;
V_32 -> V_53 = V_114 ;
if ( F_51 ( V_114 ) )
V_32 -> V_151 = V_152 ;
else if ( F_52 ( V_114 ) )
V_32 -> V_151 = V_153 ;
else
V_32 -> V_151 = V_154 ;
F_53 ( L_47 , V_32 -> V_151 ) ;
}
void F_54 ( struct V_1 * V_2 , T_1 V_155 , T_1 V_156 )
{
T_1 V_157 ;
V_157 = F_2 ( V_2 , V_158 ) ;
V_157 |= V_155 ;
V_157 &= ~ V_156 ;
F_3 ( V_2 , V_158 , V_157 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( V_2 , V_158 , 0x1010 ) ;
F_56 ( V_2 , V_159 , 0x6404 ) ;
if ( F_57 ( & V_2 -> V_160 , V_161 ) == false )
F_3 ( V_2 , V_162 ,
V_163 ) ;
F_3 ( V_2 , V_164 , V_165 ) ;
F_56 ( V_2 , V_166 , 0x660F ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
F_7 ( V_167 , V_22 , ( L_48 ) ) ;
V_32 -> V_168 |= F_15 ( 6 ) ;
F_3 ( V_2 , V_169 + 2 ,
V_32 -> V_168 ) ;
F_3 ( V_2 , V_159 + 1 , 0xff ) ;
V_32 -> V_170 |= F_15 ( 0 ) ;
F_3 ( V_2 , V_159 + 2 , V_32 -> V_170 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
F_7 ( V_167 , V_22 , ( L_49 ) ) ;
V_32 -> V_168 &= ~ F_15 ( 6 ) ;
F_3 ( V_2 , V_169 + 2 ,
V_32 -> V_168 ) ;
F_3 ( V_2 , V_159 + 1 , 0x64 ) ;
V_32 -> V_170 &= ~ F_15 ( 0 ) ;
F_3 ( V_2 , V_159 + 2 , V_32 -> V_170 ) ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_171 ,
T_1 V_172 )
{
F_54 ( V_2 , V_173 | V_174 | V_175 ,
0 ) ;
F_3 ( V_2 , V_176 + 1 , 0x6F ) ;
}
void F_61 ( struct V_1 * V_2 )
{
T_2 V_24 ;
struct V_177 * V_178 = & V_2 -> V_179 ;
struct V_180 * V_181 = & V_178 -> V_182 ;
F_56 ( V_2 , V_183 , 2 ) ;
F_56 ( V_2 , V_184 , V_181 -> V_185 ) ;
F_55 ( V_2 ) ;
F_3 ( V_2 , V_186 , 0x09 ) ;
V_24 = F_9 ( V_2 , V_187 ) ;
V_24 &= ~ V_188 ;
F_10 ( V_2 , V_187 , V_24 ) ;
V_24 |= V_188 ;
F_10 ( V_2 , V_187 , V_24 ) ;
if ( F_57 ( & V_2 -> V_160 , V_189 |
V_190 | V_191 ) == true ) {
F_3 ( V_2 , V_192 , 0x50 ) ;
F_3 ( V_2 , V_193 , 0x50 ) ;
}
F_60 ( V_2 , true , true ) ;
F_58 ( V_2 ) ;
F_54 ( V_2 , V_175 , 0 ) ;
}
void F_62 ( struct V_1 * V_194 ,
enum V_195 V_196 ,
void * V_197 , bool V_198 )
{
struct V_31 * V_32 = F_13 ( V_194 ) ;
struct V_199 * V_200 = & V_32 -> V_201 ;
switch ( V_196 ) {
case V_202 :
{
struct V_203 * V_204 = (struct V_203 * ) V_197 ;
if ( V_198 ) {
F_21 ( L_50 , V_204 -> V_205 ) ;
F_63 ( V_200 ,
V_206 ,
V_204 -> V_205 , V_204 ) ;
} else {
F_21 ( L_51 , V_204 -> V_205 ) ;
F_63 ( V_200 ,
V_206 ,
V_204 -> V_205 , NULL ) ;
}
}
break;
case V_207 :
F_64 ( V_200 , V_208 , V_198 ) ;
break;
case V_209 :
F_64 ( V_200 , V_210 , V_198 ) ;
break;
default:
break;
}
}
void F_65 ( struct V_1 * V_211 , bool V_3 )
{
if ( V_3 ) {
F_21 ( L_52 ) ;
F_3 ( V_211 , V_212 + 1 ,
F_2 ( V_211 , V_212 + 1 ) |
F_15 ( 1 ) ) ;
} else {
F_21 ( L_53 ) ;
F_3 ( V_211 , V_212 + 1 ,
F_2 ( V_211 , V_212 + 1 ) &
~ F_15 ( 1 ) ) ;
}
}
bool F_66 ( T_1 V_213 )
{
bool V_15 = false ;
if ( V_213 == V_214 )
V_15 = true ;
return V_15 ;
}
int F_67 ( struct V_1 * V_2 , struct V_215 * V_216 )
{
int V_15 = V_16 ;
T_1 V_85 = 0 ;
if ( V_216 == NULL ) {
F_21 ( L_54 , V_28 ) ;
V_15 = V_13 ;
goto exit;
}
switch ( V_216 -> V_213 ) {
case V_217 :
F_7 ( V_21 , V_22 ,
( L_55 , V_216 -> V_218 ) ) ;
break;
case V_214 :
F_68 ( V_2 , V_216 -> V_218 ) ;
break;
case V_219 :
break;
case V_220 :
F_7 ( V_21 , V_22 ,
( L_56 ) ) ;
for ( V_85 = 0 ; V_85 < V_216 -> V_221 ; V_85 ++ ) {
F_7 ( V_21 , V_22 ,
( L_57 , V_85 ,
V_216 -> V_218 [ V_85 ] ) ) ;
}
break;
case V_222 :
F_7 ( V_21 , V_22 ,
( L_58 ) ) ;
F_7 ( V_21 , V_22 ,
( L_59
L_60 , V_216 -> V_218 [ 0 ] ,
V_216 -> V_218 [ 1 ] , V_216 -> V_218 [ 2 ] ,
V_216 -> V_218 [ 3 ] , V_216 -> V_218 [ 4 ] ) ) ;
break;
case V_223 :
F_21 ( L_61 , V_28 ) ;
F_69 ( V_2 ,
V_216 -> V_218 , V_216 -> V_221 ) ;
break;
default:
V_15 = V_13 ;
break;
}
exit:
return V_15 ;
}
void F_68 ( struct V_1 * V_211 , void * V_50 )
{
struct V_224 * V_225 = V_50 ;
struct V_226 * V_227 = & V_211 -> V_228 . V_229 ;
if ( V_225 -> V_230 && V_211 -> V_228 . V_231 ) {
if ( V_225 -> V_232 )
F_70 ( & V_227 ,
V_233 ) ;
else
F_70 ( & V_227 ,
V_234 ) ;
}
}
void F_71 ( struct V_1 * V_2 )
{
T_1 V_235 ;
V_235 = F_2 ( V_2 , V_236 ) ;
V_235 |= F_15 ( 7 ) ;
F_3 ( V_2 , V_236 , V_235 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
T_1 V_235 ;
V_235 = F_2 ( V_2 , V_236 ) ;
if ( ! ( V_235 & F_15 ( 7 ) ) ) {
V_235 |= F_15 ( 7 ) ;
F_3 ( V_2 , V_236 , V_235 ) ;
}
}
void F_73 ( struct V_1 * V_2 )
{
T_1 V_235 ;
V_235 = F_2 ( V_2 , V_236 ) ;
V_235 &= ~ F_15 ( 7 ) ;
F_3 ( V_2 , V_236 , V_235 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_31 * V_32 ;
struct V_237 * V_238 ;
T_1 V_85 ;
V_32 = F_13 ( V_2 ) ;
V_238 = & V_32 -> V_239 ;
V_32 -> V_240 = false ;
V_32 -> V_241 = false ;
if ( ! V_2 -> V_65 . V_242 )
V_32 -> V_67 = 0 ;
V_32 -> V_241 = false ;
V_238 -> V_243 = 0 ;
V_238 -> V_244 = 0 ;
for ( V_85 = 0 ; V_85 < V_245 ; V_85 ++ )
V_238 -> V_246 [ V_85 ] = 0 ;
V_32 -> V_96 = 0 ;
V_32 -> V_103 = 0 ;
}
T_1 F_75 ( struct V_1 * V_2 )
{
T_1 V_9 = 0 ;
T_2 V_247 ;
V_247 = F_76 ( V_2 , V_248 ) ;
V_9 = ( V_247 & V_249 ) ? 6 : 4 ;
F_53 ( L_62 , V_9 == 4 ? L_63 : L_64 ) ;
return V_9 ;
}
static int F_77 ( struct V_1 * V_2 , T_2 V_250 , T_2 V_56 )
{
int V_251 = V_16 ;
T_4 V_252 = 0 ;
T_2 V_253 = F_78 ( V_250 ) | F_79 ( V_56 ) |
F_80 ( V_254 ) ;
T_3 V_255 = V_256 ;
F_10 ( V_2 , V_255 , V_253 ) ;
do {
V_253 = F_9 ( V_2 , V_255 ) ;
if ( V_257 == F_81 ( V_253 ) ) {
break;
}
if ( V_252 > V_258 ) {
F_7 ( V_21 , V_27 ,
( L_65
L_66 , V_250 ) ) ;
V_251 = V_13 ;
break;
}
} while ( V_252 ++ );
return V_251 ;
}
int F_82 ( struct V_1 * V_2 , T_2 V_259 )
{
int V_251 = V_16 ;
T_2 V_85 ;
T_2 V_260 = V_259 ;
T_2 V_261 = V_262 ;
for ( V_85 = 0 ; V_85 < ( V_260 - 1 ) ; V_85 ++ ) {
V_251 = F_77 ( V_2 , V_85 , V_85 + 1 ) ;
if ( V_251 != V_16 ) {
return V_251 ;
}
}
V_251 = F_77 ( V_2 , ( V_260 - 1 ) , 0xFF ) ;
if ( V_251 != V_16 ) {
return V_251 ;
}
for ( V_85 = V_260 ; V_85 < V_261 ; V_85 ++ ) {
V_251 = F_77 ( V_2 , V_85 , ( V_85 + 1 ) ) ;
if ( V_16 != V_251 ) {
return V_251 ;
}
}
V_251 = F_77 ( V_2 , V_261 , V_260 ) ;
if ( V_251 != V_16 ) {
return V_251 ;
}
return V_251 ;
}
static void F_83 ( struct V_1 * V_2 )
{
T_2 V_24 ;
T_2 V_263 ;
F_56 ( V_2 , V_264 + 2 , 0x0000 ) ;
V_24 = F_9 ( V_2 , V_264 ) & 0xFFFF00FF ;
V_263 = V_24 & 0x000000FF ;
V_24 |= ( ( V_263 << 8 ) | 0x00FF0000 ) ;
F_10 ( V_2 , V_264 , V_24 ) ;
F_56 ( V_2 , V_265 , 0x0000 ) ;
V_24 = F_9 ( V_2 , V_266 ) & 0xFFFF001F ;
V_263 = V_24 & 0x0000001F ;
V_24 |= ( ( V_263 << 8 ) | 0x001D0000 ) ;
F_10 ( V_2 , V_266 , V_24 ) ;
F_56 ( V_2 , V_267 , 0x8080 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
T_1 V_10 ;
F_3 ( V_2 , V_268 , 0xFF ) ;
F_85 ( V_2 , V_269 , 0x0 , V_270 , 0x0 ) ;
V_10 = V_271 ;
F_3 ( V_2 , V_272 , V_10 ) ;
V_10 = V_273 | V_274 | V_275 ;
F_3 ( V_2 , V_5 , V_10 ) ;
V_10 &= ~ V_275 ;
F_3 ( V_2 , V_5 , V_10 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
bool V_276 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
if ( F_14 ( V_2 ) && ( V_32 -> V_35 <= 0x20 ) ) {
T_3 V_277 ;
F_3 ( V_2 , V_6 , 0 ) ;
V_277 = F_76 ( V_2 , V_5 ) ;
F_56 ( V_2 , V_5 ,
V_277 & ~ V_278 ) ;
V_277 = F_76 ( V_2 , V_5 ) & 0x0FFF ;
F_56 ( V_2 , V_5 ,
V_277 | V_279 | V_280 ) ;
V_277 = F_76 ( V_2 , V_5 ) ;
F_56 ( V_2 , V_5 ,
V_277 | V_278 ) ;
} else {
T_1 V_281 = 0 ;
T_1 V_157 ;
V_157 = F_2 ( V_2 , V_6 ) ;
if ( ( V_157 & F_15 ( 1 ) ) && V_2 -> V_282 ) {
F_3 ( V_2 , V_283 , 0x20 ) ;
F_3 ( V_2 , V_284 , 0x00 ) ;
F_3 ( V_2 , V_285 , 0x00 ) ;
F_3 ( V_2 , V_37 + 3 , 0x20 ) ;
while ( ( V_281 ++ < 100 ) &&
( F_76 ( V_2 , V_5 ) &
V_278 ) ) {
F_11 ( 50 ) ;
}
if ( V_281 >= 100 ) {
F_3 ( V_2 ,
V_5 + 1 , 0x50 ) ;
F_87 ( 10 ) ;
}
}
F_3 ( V_2 , V_5 + 1 , 0x54 ) ;
F_3 ( V_2 , V_6 , 0 ) ;
}
if ( V_276 ) {
F_56 ( V_2 , V_286 , 0x70A3 ) ;
F_3 ( V_2 , V_287 , 0x80 ) ;
F_56 ( V_2 , V_288 , 0x880F ) ;
F_3 ( V_2 , V_289 , 0xF9 ) ;
} else {
F_3 ( V_2 , V_290 , 0x00 ) ;
}
}
static void F_88 ( struct V_1 * V_2 )
{
F_56 ( V_2 , V_286 , 0x70a3 ) ;
F_3 ( V_2 , V_289 + 1 , 0x82 ) ;
}
static void F_89 ( struct V_1 * V_2 , bool V_276 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
T_3 V_291 ;
T_1 V_10 ;
if ( V_276 ) {
F_3 ( V_2 , V_292 , 0x04 ) ;
V_10 = F_2 ( V_2 , V_293 ) ;
V_10 &= ~ V_294 ;
F_3 ( V_2 , V_293 , V_10 ) ;
}
V_10 = 0x23 ;
if ( F_90 ( V_32 -> V_53 ) )
V_10 |= F_15 ( 3 ) ;
F_3 ( V_2 , V_295 , V_10 ) ;
if ( V_276 ) {
V_291 = V_296 | V_297 | V_298 ;
} else {
V_291 = V_296 | V_297 | V_298 ;
}
F_56 ( V_2 , V_299 , V_291 ) ;
F_3 ( V_2 , V_300 , 0x0e ) ;
}
int F_91 ( struct V_1 * V_2 , T_1 V_301 )
{
if ( V_2 -> V_302 ) {
return V_16 ;
}
F_84 ( V_2 ) ;
F_86 ( V_2 , false ) ;
F_83 ( V_2 ) ;
F_89 ( V_2 , false ) ;
F_7 ( V_167 , V_22 ,
( L_67 ) ) ;
return V_16 ;
}
int F_92 ( struct V_1 * V_2 )
{
if ( V_2 -> V_302 ) {
return V_16 ;
}
F_84 ( V_2 ) ;
F_86 ( V_2 , true ) ;
F_83 ( V_2 ) ;
F_88 ( V_2 ) ;
F_89 ( V_2 , true ) ;
return V_16 ;
}
void F_93 ( struct V_1 * V_2 , T_1 * V_303 )
{
struct V_304 * V_305 = F_94 ( V_2 ) ;
if ( ! V_305 -> V_306 ) {
if ( ! V_305 -> V_307 ) {
F_95 ( V_2 , V_94 ) ;
memcpy ( V_303 , V_305 -> V_308 ,
V_309 ) ;
}
} else {
F_7 ( V_167 , V_310 ,
( L_68 ) ) ;
if ( ! V_305 -> V_307 )
F_95 ( V_2 , V_94 ) ;
memcpy ( V_303 , V_305 -> V_308 ,
V_309 ) ;
}
}
void F_96 ( struct V_1 * V_2 , T_1 * V_311 )
{
struct V_304 * V_305 = F_94 ( V_2 ) ;
T_3 V_312 ;
V_312 = F_28 ( * ( ( T_3 * ) V_311 ) ) ;
if ( V_312 != V_313 ) {
F_21 ( L_69 , V_312 ) ;
V_305 -> V_306 = true ;
} else {
V_305 -> V_306 = false ;
}
F_7 ( V_21 , V_22 ,
( L_70 , V_312 ) ) ;
}
static void F_97 ( T_1 V_314 , void * V_315 , void * V_316 )
{
switch ( V_314 ) {
case V_317 :
{
T_1 * V_318 , * V_319 ;
V_318 = ( T_1 * ) V_315 ;
V_319 = ( T_1 * ) V_316 ;
if ( * V_318 <= 63 )
* V_319 = * V_318 ;
else {
F_7 ( V_167 , V_27 ,
( L_71
L_72 ,
* V_318 , V_320 ) ) ;
* V_319 = V_320 ;
}
}
break;
default:
break;
}
}
static void
F_98 ( struct V_321 * V_322 ,
T_1 * V_303 , bool V_323 )
{
T_2 V_324 , V_325 , V_326 , V_327 = 1 ;
memset ( V_322 , 0 , sizeof( * V_322 ) ) ;
if ( V_323 ) {
for ( V_326 = 0 ; V_326 < V_328 ; V_326 ++ ) {
for ( V_324 = 0 ; V_324 < V_327 ; V_324 ++ ) {
V_322 -> V_329 [ V_324 ] [ V_326 ] =
V_320 ;
V_322 -> V_330 [ V_324 ] [ V_326 ] =
V_320 ;
V_322 -> V_331 [ V_324 ] [ V_326 ] =
V_332 ;
V_322 -> V_333 [ V_324 ] [ V_326 ] =
V_334 ;
V_322 -> V_335 [ V_324 ] [ V_326 ] =
V_336 ;
V_322 -> V_337 [ V_324 ] [ V_326 ] =
V_338 ;
V_322 -> V_339 [ V_324 ] [ V_326 ] =
V_340 ;
}
}
V_322 -> V_341 [ 0 ] = V_342 ;
return;
}
for ( V_324 = 0 ; V_324 < V_327 ; V_324 ++ ) {
for ( V_326 = 0 ; V_326 < V_328 ; V_326 ++ ) {
V_325 =
V_343 + ( V_324 * 3 ) + V_326 ;
F_97 ( V_317 , & V_303 [ V_325 ] ,
& V_322 -> V_329 [ V_324 ] [ V_326 ] ) ;
V_325 = V_344 +
( V_324 * 3 ) + V_326 ;
F_97 ( V_317 , & V_303 [ V_325 ] ,
& V_322 -> V_330 [ V_324 ] [ V_326 ] ) ;
}
}
for ( V_326 = 0 ; V_326 < V_328 ; V_326 ++ ) {
for ( V_324 = 0 ; V_324 < V_327 ; V_324 ++ ) {
V_322 -> V_331 [ V_324 ] [ V_326 ] = 0 ;
V_322 -> V_333 [ V_324 ] [ V_326 ] =
( V_303
[ V_345 +
V_326 ] >> ( V_324 * 4 ) ) & 0xF ;
if ( V_322 -> V_333 [ V_324 ] [ V_326 ] & F_15 ( 3 ) )
V_322 -> V_333 [ V_324 ] [ V_326 ] |= 0xF0 ;
V_322 -> V_335 [ V_324 ] [ V_326 ] =
( V_303 [ V_346 +
V_326 ] >> ( V_324 * 4 ) ) & 0xF ;
V_322 -> V_337 [ V_324 ] [ V_326 ] =
( V_303 [ V_347 +
V_326 ] >> ( V_324 * 4 ) ) & 0xF ;
V_322 -> V_339 [ V_324 ] [ V_326 ] =
( V_303 [ V_348 +
V_326 ] >> ( V_324 * 4 ) ) & 0xF ;
}
}
V_322 -> V_341 [ 0 ] = V_303 [ V_349 ] ;
}
static T_1 F_99 ( T_1 V_350 )
{
T_1 V_326 = 0 ;
if ( V_350 < 3 )
V_326 = 0 ;
else if ( V_350 < 9 )
V_326 = 1 ;
else
V_326 = 2 ;
return V_326 ;
}
void
F_100 ( struct V_1 * V_2 ,
T_1 * V_303 , bool V_323 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
struct V_321 V_322 ;
T_1 V_324 , V_351 , V_326 , V_327 = 1 ;
T_1 V_352 , V_353 ;
F_98 ( & V_322 , V_303 , V_323 ) ;
for ( V_324 = 0 ; V_324 < V_327 ; V_324 ++ ) {
for ( V_351 = 0 ; V_351 < V_354 ; V_351 ++ ) {
V_326 = F_99 ( V_351 ) ;
V_32 -> V_355 [ V_324 ] [ V_351 ] =
V_322 . V_329 [ V_324 ] [ V_326 ] ;
V_32 -> V_356 [ V_324 ] [ V_351 ] =
V_322 . V_330 [ V_324 ] [ V_326 ] ;
V_32 -> V_357 [ V_324 ] [ V_351 ] =
V_322 . V_333 [ V_324 ] [ V_326 ] ;
V_32 -> V_358 [ V_324 ] [ V_351 ] =
V_322 . V_335 [ V_324 ] [ V_326 ] ;
V_32 -> V_359 [ V_324 ] [ V_351 ] =
V_322 . V_339 [ V_324 ] [ V_326 ] ;
V_32 -> V_360 [ V_324 ] [ V_351 ] =
V_322 . V_337 [ V_324 ] [ V_326 ] ;
V_352 = V_322 . V_330 [ V_324 ] [ V_326 ] ;
V_353 = V_322 . V_331 [ V_324 ] [ V_326 ] ;
V_32 -> V_361 [ V_324 ] [ V_351 ] =
( V_352 > V_353 ) ? ( V_352 - V_353 ) : 0 ;
}
}
for ( V_324 = 0 ; V_324 < V_362 ; V_324 ++ ) {
for ( V_351 = 0 ; V_351 < V_354 ; V_351 ++ ) {
F_7 ( V_167 , V_22 ,
( L_73
L_74 ,
V_324 , V_351 ,
V_32 -> V_355 [ V_324 ] [ V_351 ] ,
V_32 -> V_356 [ V_324 ] [ V_351 ] ,
V_32 -> V_361 [ V_324 ] [ V_351 ] ) ) ;
}
}
for ( V_351 = 0 ; V_351 < V_354 ; V_351 ++ ) {
F_7 ( V_167 , V_22 ,
( L_75 , V_351 ,
V_32 -> V_357 [ V_269 ] [ V_351 ] ,
V_32 -> V_357 [ V_269 ] [ V_351 ] ) ) ;
}
for ( V_351 = 0 ; V_351 < V_354 ; V_351 ++ )
F_7 ( V_167 , V_22 ,
( L_76 , V_351 ,
V_32 -> V_358 [ V_269 ] [ V_351 ] ) ) ;
for ( V_351 = 0 ; V_351 < V_354 ; V_351 ++ ) {
F_7 ( V_167 , V_22 ,
( L_77 , V_351 ,
V_32 -> V_357 [ V_363 ] [ V_351 ] ,
V_32 -> V_357 [ V_363 ] [ V_351 ] ) ) ;
}
for ( V_351 = 0 ; V_351 < V_354 ; V_351 ++ )
F_7 ( V_167 , V_22 ,
( L_78 , V_351 ,
V_32 -> V_358 [ V_363 ] [ V_351 ] ) ) ;
if ( ! V_323 ) {
struct V_364 * V_365 = & V_2 -> V_54 ;
if ( V_365 -> V_366 == 0xff ) {
if ( V_303 [ V_367 ] == 0xff )
V_32 -> V_368 = 0 ;
else
V_32 -> V_368 =
V_303 [ V_367 ] & 0x7 ;
} else {
V_32 -> V_368 =
V_365 -> V_366 ;
}
} else {
V_32 -> V_368 = 0 ;
}
F_7 ( V_167 , V_22 ,
( L_79 , V_32 -> V_368 ) ) ;
if ( ! V_323 )
V_32 -> V_369 = true ;
}
void
F_101 ( struct V_1 * V_2 ,
T_1 * V_311 , bool V_323 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
T_1 V_370 ;
T_2 V_371 ;
if ( ! V_323 ) {
V_371 = F_9 ( V_2 , V_140 ) ;
if ( V_371 & V_143 )
V_32 -> V_372 = 1 ;
else
V_32 -> V_372 = 0 ;
V_32 -> V_373 = V_374 ;
V_370 = V_311 [ V_375 ] ;
V_32 -> V_376 = ( V_370 & 0x1 ) ;
V_32 -> V_377 = ( ( V_370 & 0x10 ) >> 4 ) ;
V_32 -> V_378 = ( ( V_370 & 0x20 ) >> 5 ) ;
} else {
V_32 -> V_372 = 0 ;
V_32 -> V_373 = V_374 ;
V_32 -> V_376 = V_379 ;
V_32 -> V_377 = 0 ;
V_32 -> V_378 = V_380 ;
}
F_102 ( V_2 ) ;
}
void
F_103 ( struct V_1 * V_2 ,
T_1 * V_311 , bool V_323 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
if ( ! V_323 )
V_32 -> V_381 = V_311 [ V_382 ] ;
else
V_32 -> V_381 = 1 ;
F_7 ( V_167 , V_22 ,
( L_80 ,
V_32 -> V_381 ) ) ;
}
void
F_104 ( struct V_1 * V_2 ,
T_1 * V_311 , bool V_323 )
{
V_2 -> V_160 . V_383 =
F_105 ( V_2 , V_311 ?
V_311 [ V_384 ] : 0xFF ,
V_2 -> V_54 . V_385 ,
V_386 ,
V_323 ) ;
F_21 ( L_81 ,
V_2 -> V_160 . V_383 ) ;
}
void
F_106 ( struct V_1 * V_2 ,
T_1 * V_311 , bool V_323 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
if ( ! V_323 ) {
V_32 -> V_387 = V_311 [ V_388 ] ;
V_32 -> V_389 =
V_311 [ V_390 ] ;
} else {
V_32 -> V_387 = 0 ;
V_32 -> V_389 = 0 ;
}
F_7 ( V_167 , V_22 ,
( L_82 , V_32 -> V_387 ) ) ;
F_7 ( V_167 , V_22 ,
( L_83 ,
V_32 -> V_389 ) ) ;
}
void
F_107 ( struct V_1 * V_2 ,
T_1 * V_311 , bool V_323 )
{
}
void
F_108 ( struct V_1 * V_2 ,
T_1 * V_311 , bool V_323 )
{
}
void
F_109 ( struct V_1 * V_391 ,
T_1 * V_311 , T_1 V_323 )
{
struct V_31 * V_32 = F_13 ( V_391 ) ;
if ( ! V_323 ) {
V_32 -> V_392 = V_311 [ V_393 ] ;
if ( V_32 -> V_392 == 0xFF )
V_32 -> V_392 = V_394 ;
} else {
V_32 -> V_392 = V_394 ;
}
F_7 ( V_167 , V_22 ,
( L_84 , V_28 ,
V_32 -> V_392 ) ) ;
}
void
F_110 ( struct V_1 * V_2 ,
T_1 * V_303 , bool V_395 )
{
struct V_31 * V_32 = F_13 ( V_2 ) ;
if ( ! V_395 )
V_32 -> V_396 =
V_303 [ V_397 ] ;
else
V_32 -> V_396 = V_398 ;
if ( ( V_32 -> V_396 == 0xff ) || V_395 ) {
V_32 -> V_399 = true ;
V_32 -> V_396 = V_398 ;
}
F_21 ( L_85 , V_28 ,
V_32 -> V_396 ) ;
}
static void F_111 ( struct V_400 * V_401 )
{
T_3 * V_402 = ( T_3 * ) V_401 ;
T_2 V_252 = 16 ;
T_2 V_403 ;
T_3 V_404 = 0 ;
V_401 -> V_405 &= F_112 ( 0xffff0000 ) ;
for ( V_403 = 0 ; V_403 < V_252 ; V_403 ++ ) {
V_404 ^= F_28 ( * ( V_402 + V_403 ) ) ;
}
V_401 -> V_405 |= F_112 ( V_404 & 0x0000ffff ) ;
}
void F_113 ( struct V_1 * V_2 , T_1 * V_406 ,
T_2 V_407 , T_1 V_408 , T_1 V_409 )
{
struct V_400 * V_401 ;
V_401 = (struct V_400 * ) V_406 ;
memset ( V_406 , 0 , V_410 ) ;
V_401 -> V_411 |= F_112 ( V_412 | V_413 | V_414 ) ;
V_401 -> V_411 |= F_112 ( ( ( V_410 + V_415 ) <<
V_416 ) & 0x00ff0000 ) ;
V_401 -> V_411 |= F_112 ( V_407 & 0x0000ffff ) ;
V_401 -> V_417 |= F_112 ( ( V_418 << V_419 ) & 0x00001f00 ) ;
if ( V_408 ) {
V_401 -> V_417 |= F_112 ( V_420 ) ;
} else {
V_401 -> V_421 |= F_112 ( F_15 ( 7 ) ) ;
V_401 -> V_422 |= F_112 ( ( 8 << 28 ) ) ;
}
if ( true == V_409 ) {
V_401 -> V_423 |= F_112 ( F_15 ( 23 ) ) ;
}
V_401 -> V_421 |= F_112 ( F_15 ( 8 ) ) ;
F_111 ( V_401 ) ;
}
void F_114 ( struct V_1 * V_2 , T_1 V_424 )
{
T_1 V_157 ;
if ( V_424 == V_425 || V_424 == V_426 ) {
F_59 ( V_2 ) ;
V_157 = V_173 | V_174 | V_427 ;
F_54 ( V_2 , V_157 , ~ V_157 ) ;
} else if ( V_424 == V_428 ) {
F_58 ( V_2 ) ;
V_157 = V_173 | V_174 | V_175 ;
F_54 ( V_2 , V_157 , ~ V_157 ) ;
} else if ( V_424 == V_429 ) {
F_115 ( V_2 ) ;
F_58 ( V_2 ) ;
V_157 = V_173 | V_175 ;
F_54 ( V_2 , V_157 , ~ V_157 ) ;
F_10 ( V_2 , V_430 , 0x7000228e ) ;
F_56 ( V_2 , V_431 , 0xFFFF ) ;
F_56 ( V_2 , V_432 , 0x0400 ) ;
F_3 ( V_2 , V_164 , 0x02 ) ;
F_3 ( V_2 , V_162 , 0x05 ) ;
F_3 ( V_2 , V_183 , 0x0a ) ;
F_56 ( V_2 , V_166 , 0x00 ) ;
F_56 ( V_2 , V_159 , 0xff04 ) ;
F_56 ( V_2 , V_433 , 0x7fff ) ;
F_3 ( V_2 , V_434 , F_15 ( 0 ) ) ;
V_157 = V_173 | V_174 |
V_435 | V_175 ;
F_54 ( V_2 , V_157 , ~ V_157 ) ;
}
V_157 = F_2 ( V_2 , V_436 ) ;
V_157 = ( V_157 & 0xC ) | V_424 ;
F_3 ( V_2 , V_436 , V_157 ) ;
}
void F_116 ( struct V_1 * V_2 , T_1 * V_235 )
{
T_1 V_437 = 0 ;
T_2 V_438 ;
V_438 = V_439 ;
for ( V_437 = 0 ; V_437 < 6 ; V_437 ++ )
F_3 ( V_2 , ( V_438 + V_437 ) , V_235 [ V_437 ] ) ;
}
void F_117 ( struct V_1 * V_2 , T_1 * V_235 )
{
T_1 V_437 = 0 ;
T_2 V_440 ;
V_440 = V_441 ;
for ( V_437 = 0 ; V_437 < 6 ; V_437 ++ )
F_3 ( V_2 , ( V_440 + V_437 ) , V_235 [ V_437 ] ) ;
}
void F_118 ( struct V_1 * V_2 )
{
T_5 V_442 ;
T_2 V_443 ;
struct V_177 * V_178 = & V_2 -> V_179 ;
struct V_180 * V_181 = & V_178 -> V_182 ;
V_442 = V_178 -> V_444 -
F_119 ( V_178 -> V_444 ,
( V_181 -> V_185 * 1024 ) ) - 1024 ;
if ( ( ( V_181 -> V_445 & 0x03 ) == V_428 ) ||
( ( V_181 -> V_445 & 0x03 ) == V_429 ) ) {
F_59 ( V_2 ) ;
}
V_443 = V_446 ;
F_54 ( V_2 , 0 , V_174 ) ;
F_10 ( V_2 , V_443 , V_442 ) ;
F_10 ( V_2 , V_443 + 4 , V_442 >> 32 ) ;
F_54 ( V_2 , V_174 , 0 ) ;
if ( ( ( V_181 -> V_445 & 0x03 ) == V_428 ) ||
( ( V_181 -> V_445 & 0x03 ) == V_429 ) )
F_58 ( V_2 ) ;
}
void F_120 ( struct V_1 * V_2 )
{
F_56 ( V_2 , V_431 , 0 ) ;
F_3 ( V_2 , V_434 , F_15 ( 0 ) ) ;
F_54 ( V_2 , V_173 , 0 ) ;
}
void F_121 ( struct V_1 * V_2 , T_1 type )
{
T_1 V_447 = 0x30 ;
struct V_31 * V_32 = F_13 ( V_2 ) ;
struct V_448 * V_449 = & V_2 -> V_160 ;
if ( type == 0 ) {
T_2 V_450 ;
F_56 ( V_2 , V_431 , 0xFFFF ) ;
V_450 = F_9 ( V_2 , V_430 ) ;
V_450 |= V_451 | V_452 ;
F_10 ( V_2 , V_430 , V_450 ) ;
if ( F_57 ( V_449 , V_161 ) == true )
V_447 =
( V_32 -> V_453 == V_454 ) ? 7 : 48 ;
else
V_447 = 0x7 ;
} else if ( type == 1 ) {
F_56 ( V_2 , V_431 , 0 ) ;
} else if ( type == 2 ) {
F_54 ( V_2 , 0 , V_173 ) ;
if ( F_57 ( V_449 ,
V_189 | V_190 ) ) {
F_3 ( V_2 , 0x542 , 0x02 ) ;
V_447 = 0x7 ;
}
}
F_56 ( V_2 , V_455 ,
V_447 << V_456 | V_447 <<
V_457 ) ;
switch ( type ) {
case 0 :
F_122 ( V_2 , true ) ;
break;
case 1 :
F_122 ( V_2 , false ) ;
break;
case 2 :
break;
}
}
