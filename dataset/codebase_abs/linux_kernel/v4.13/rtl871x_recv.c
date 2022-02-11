void F_1 ( struct V_1 * V_2 )
{
memset ( ( V_3 * ) V_2 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
}
T_1 F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
T_1 V_10 ;
union V_11 * V_12 ;
memset ( ( unsigned char * ) V_7 , 0 , sizeof( struct V_6 ) ) ;
F_2 ( & V_7 -> V_4 ) ;
F_3 ( & V_7 -> V_13 ) ;
F_3 ( & V_7 -> V_14 ) ;
V_7 -> V_15 = V_9 ;
V_7 -> V_16 = V_17 ;
V_7 -> V_18 = F_5 ( V_17 *
sizeof( union V_11 ) + V_19 ,
V_20 ) ;
if ( V_7 -> V_18 == NULL )
return V_21 ;
F_6 ( V_7 -> V_18 ) ;
V_7 -> V_22 = V_7 -> V_18 +
V_19 -
( ( V_23 ) ( V_7 -> V_18 ) &
( V_19 - 1 ) ) ;
V_12 = (union V_11 * ) V_7 -> V_22 ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ ) {
F_7 ( & ( V_12 -> V_24 . V_25 ) ) ;
F_8 ( & ( V_12 -> V_24 . V_25 ) ,
& ( V_7 -> V_13 . V_26 ) ) ;
F_9 ( V_9 , V_12 ) ;
V_12 -> V_24 . V_27 . V_15 = V_9 ;
V_12 ++ ;
}
V_7 -> V_28 = 1 ;
return F_10 ( V_7 , V_9 ) ;
}
void F_11 ( struct V_6 * V_7 )
{
F_12 ( V_7 -> V_18 ) ;
F_13 ( V_7 ) ;
}
union V_11 * F_14 ( struct V_29 * V_30 )
{
unsigned long V_31 ;
union V_11 * V_12 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
F_15 ( & V_30 -> V_4 , V_31 ) ;
V_12 = F_16 ( & V_30 -> V_26 ,
union V_11 , V_24 . V_27 . V_25 ) ;
if ( V_12 ) {
F_17 ( & V_12 -> V_24 . V_27 . V_25 ) ;
V_9 = V_12 -> V_24 . V_27 . V_15 ;
if ( V_9 != NULL ) {
V_7 = & V_9 -> V_32 ;
if ( V_30 == & V_7 -> V_13 )
V_7 -> V_16 -- ;
}
}
F_18 ( & V_30 -> V_4 , V_31 ) ;
return V_12 ;
}
void F_19 ( struct V_29 * V_33 ,
struct V_29 * V_30 )
{
union V_11 * V_12 ;
struct V_34 * V_35 , * V_36 ;
F_20 ( & V_33 -> V_4 ) ;
V_36 = & V_33 -> V_26 ;
V_35 = V_36 -> V_37 ;
while ( ! F_21 ( V_36 , V_35 ) ) {
V_12 = F_22 ( V_35 , union V_11 , V_24 . V_25 ) ;
V_35 = V_35 -> V_37 ;
F_23 ( V_12 , V_30 ) ;
}
F_24 ( & V_33 -> V_4 ) ;
}
T_1 F_25 ( struct V_8 * V_15 ,
union V_11 * V_12 )
{
T_1 V_10 , V_38 = V_39 ;
T_2 V_40 ;
V_3 V_41 [ 8 ] ;
V_3 V_42 = false ;
V_3 * V_43 , * V_44 , * V_45 ;
V_3 * V_46 , V_47 , * V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 = & V_12 -> V_24 . V_27 . V_53 ;
struct V_54 * V_55 = & V_15 -> V_56 ;
V_50 = F_26 ( & V_15 -> V_57 , & V_52 -> V_58 [ 0 ] ) ;
if ( V_52 -> V_59 == V_60 ) {
if ( V_50 != NULL ) {
if ( F_27 ( V_52 -> V_61 ) ) {
V_48 = V_12 -> V_24 . V_27 . V_62 +
V_52 -> V_63 ;
V_47 = V_48 [ 3 ] ;
V_46 = & V_55 -> V_64 [ ( ( ( V_47 >>
6 ) & 0x3 ) ) - 1 ] . V_65 [ 0 ] ;
if ( ! V_55 -> V_66 )
return V_21 ;
} else {
V_46 = & V_50 -> V_67 . V_65 [ 0 ] ;
}
V_40 = V_12 -> V_24 . V_27 . V_68 - V_52 -> V_63 -
V_52 -> V_69 - V_52 -> V_70 - 8 ;
V_43 = V_12 -> V_24 . V_27 . V_62 ;
V_44 = V_43 + V_52 -> V_63 +
V_52 -> V_69 ;
F_28 ( V_46 , V_43 , V_44 , V_40 ,
& V_41 [ 0 ] ,
( unsigned char ) V_52 -> V_71 ) ;
V_45 = V_44 + V_40 ;
V_42 = false ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
if ( V_41 [ V_10 ] != * ( V_45 + V_10 ) )
V_42 = true ;
}
if ( V_42 ) {
if ( V_52 -> V_72 )
F_29 ( V_15 ,
( V_3 ) F_27 ( V_52 -> V_61 ) ) ;
V_38 = V_21 ;
} else {
if ( ! V_55 -> V_73 &&
F_27 ( V_52 -> V_61 ) )
V_55 -> V_73 = true ;
}
F_30 ( V_12 , 8 ) ;
}
}
return V_38 ;
}
union V_11 * F_31 ( struct V_8 * V_9 ,
union V_11 * V_74 )
{
struct V_51 * V_52 = & V_74 -> V_24 . V_27 . V_53 ;
struct V_54 * V_55 = & V_9 -> V_56 ;
union V_11 * V_75 = V_74 ;
if ( ( V_52 -> V_59 > 0 ) && ( ( V_52 -> V_72 == 0 ) ||
V_55 -> V_76 ) ) {
V_55 -> V_77 = false ;
switch ( V_52 -> V_59 ) {
case V_78 :
case V_79 :
F_32 ( V_9 , ( V_3 * ) V_74 ) ;
break;
case V_60 :
F_33 ( V_9 , ( V_3 * ) V_74 ) ;
break;
case V_80 :
F_34 ( V_9 , ( V_3 * ) V_74 ) ;
break;
default:
break;
}
} else if ( V_52 -> V_72 == 1 ) {
V_55 -> V_77 = true ;
}
return V_75 ;
}
union V_11 * F_35 ( struct V_8 * V_15 ,
union V_11 * V_74 )
{
V_3 * V_81 , * V_82 ;
T_3 V_83 ;
struct V_84 * V_85 ;
struct V_49 * V_86 ;
struct V_87 * V_88 ;
union V_11 * V_89 ;
T_4 V_90 ;
V_88 = & V_15 -> V_57 ;
V_82 = F_36 ( V_74 ) ;
V_85 = & V_74 -> V_24 . V_27 ;
V_81 = V_85 -> V_53 . V_58 ;
V_86 = F_26 ( V_88 , V_81 ) ;
V_83 = V_15 -> V_56 . V_91 ;
if ( V_83 == 2 ) {
V_82 = V_82 + V_85 -> V_53 . V_63 + V_92 ;
memcpy ( & V_90 , V_82 , 2 ) ;
F_37 ( & V_90 ) ;
if ( ( V_86 != NULL ) && ( V_86 -> V_93 ) ) {
if ( V_90 == 0x888e ) {
V_89 = V_74 ;
} else {
F_23 ( V_74 ,
& V_15 -> V_32 . V_13 ) ;
V_89 = NULL ;
}
} else {
V_89 = V_74 ;
if ( V_90 == 0x888e ) {
V_89 = V_74 ;
}
}
} else {
V_89 = V_74 ;
}
return V_89 ;
}
static T_1 F_38 ( union V_11 * V_74 , V_3 V_94 ,
struct V_95 * V_96 )
{
T_1 V_97 = V_74 -> V_24 . V_27 . V_53 . V_71 ;
T_4 V_98 = ( ( V_74 -> V_24 . V_27 . V_53 . V_99 & 0xffff ) << 4 ) |
( V_74 -> V_24 . V_27 . V_53 . V_100 & 0xf ) ;
if ( V_97 > 15 )
return V_21 ;
if ( V_98 == V_96 -> V_101 [ V_97 ] )
return V_21 ;
V_96 -> V_101 [ V_97 ] = V_98 ;
return V_39 ;
}
static T_1 F_39 ( struct V_8 * V_15 ,
union V_11 * V_74 ,
struct V_49 * * V_86 )
{
V_3 * V_82 = V_74 -> V_24 . V_27 . V_62 ;
T_1 V_102 = V_39 ;
struct V_51 * V_103 = & V_74 -> V_24 . V_27 . V_53 ;
struct V_87 * V_88 = & V_15 -> V_57 ;
struct V_104 * V_105 = & V_15 -> V_106 ;
V_3 * V_107 = F_40 ( V_105 ) ;
V_3 * V_108 = F_41 ( & V_15 -> V_109 ) ;
V_3 * V_110 = NULL ;
T_1 V_111 = F_27 ( V_103 -> V_112 ) ;
if ( F_42 ( V_105 , V_113 ) ||
F_42 ( V_105 , V_114 ) ) {
if ( ! memcmp ( V_108 , V_103 -> V_115 , V_116 ) )
return V_21 ;
if ( ( memcmp ( V_108 , V_103 -> V_112 , V_116 ) ) && ( ! V_111 ) )
return V_21 ;
if ( F_43 ( V_103 -> V_117 ) ||
F_43 ( V_107 ) ||
( memcmp ( V_103 -> V_117 , V_107 , V_116 ) ) )
return V_21 ;
V_110 = V_103 -> V_115 ;
} else if ( F_42 ( V_105 , V_118 ) ) {
if ( memcmp ( V_103 -> V_117 , V_103 -> V_115 , V_116 ) )
return V_21 ;
V_110 = V_103 -> V_117 ;
} else if ( F_42 ( V_105 , V_119 ) ) {
if ( V_111 ) {
if ( ! F_27 ( V_103 -> V_117 ) )
return V_21 ;
} else {
if ( memcmp ( V_103 -> V_117 , V_103 -> V_112 , V_116 ) )
return V_21 ;
V_110 = V_103 -> V_115 ;
}
} else if ( F_42 ( V_105 , V_120 ) ) {
memcpy ( V_103 -> V_112 , F_44 ( V_82 ) , V_116 ) ;
memcpy ( V_103 -> V_115 , F_45 ( V_82 ) , V_116 ) ;
memcpy ( V_103 -> V_117 , F_46 ( V_82 ) , V_116 ) ;
memcpy ( V_103 -> V_61 , V_103 -> V_112 , V_116 ) ;
memcpy ( V_103 -> V_58 , V_103 -> V_115 , V_116 ) ;
V_110 = V_107 ;
} else {
V_102 = V_21 ;
}
if ( V_111 )
* V_86 = F_47 ( V_15 ) ;
else
* V_86 = F_26 ( V_88 , V_110 ) ;
if ( * V_86 == NULL ) {
if ( F_42 ( V_105 , V_120 ) )
V_15 -> V_121 . V_122 ++ ;
return V_21 ;
}
return V_102 ;
}
static T_1 F_48 ( struct V_8 * V_15 ,
union V_11 * V_74 ,
struct V_49 * * V_86 )
{
V_3 * V_82 = V_74 -> V_24 . V_27 . V_62 ;
struct V_51 * V_103 = & V_74 -> V_24 . V_27 . V_53 ;
struct V_87 * V_88 = & V_15 -> V_57 ;
struct V_104 * V_105 = & V_15 -> V_106 ;
V_3 * V_107 = F_40 ( V_105 ) ;
V_3 * V_108 = F_41 ( & V_15 -> V_109 ) ;
T_1 V_111 = F_27 ( V_103 -> V_112 ) ;
if ( F_42 ( V_105 , V_118 ) &&
F_42 ( V_105 , V_123 ) ) {
if ( ( F_49 ( V_82 ) ) == V_124 )
return V_21 ;
if ( ( F_49 ( V_82 ) & V_125 ) ==
V_125 ) {
if ( F_49 ( V_82 ) & ( F_50 ( 4 ) | F_50 ( 5 ) | F_50 ( 6 ) ) )
return V_21 ;
}
if ( ! memcmp ( V_108 , V_103 -> V_115 , V_116 ) )
return V_21 ;
if ( ( memcmp ( V_108 , V_103 -> V_112 , V_116 ) ) && ( ! V_111 ) )
return V_21 ;
if ( F_43 ( V_103 -> V_117 ) ||
F_43 ( V_107 ) ||
( memcmp ( V_103 -> V_117 , V_107 , V_116 ) ) )
return V_21 ;
if ( V_111 )
* V_86 = F_47 ( V_15 ) ;
else
* V_86 = F_26 ( V_88 , V_103 -> V_117 ) ;
if ( * V_86 == NULL )
return V_21 ;
} else if ( F_42 ( V_105 , V_120 ) &&
F_42 ( V_105 , V_123 ) ) {
memcpy ( V_103 -> V_112 , F_44 ( V_82 ) , V_116 ) ;
memcpy ( V_103 -> V_115 , F_45 ( V_82 ) , V_116 ) ;
memcpy ( V_103 -> V_117 , F_46 ( V_82 ) , V_116 ) ;
memcpy ( V_103 -> V_61 , V_103 -> V_112 , V_116 ) ;
memcpy ( V_103 -> V_58 , V_103 -> V_115 , V_116 ) ;
memcpy ( V_103 -> V_117 , V_107 , V_116 ) ;
* V_86 = F_26 ( V_88 , V_103 -> V_117 ) ;
if ( * V_86 == NULL )
return V_21 ;
} else {
return V_21 ;
}
return V_39 ;
}
static T_1 F_51 ( struct V_8 * V_15 ,
union V_11 * V_74 ,
struct V_49 * * V_86 )
{
struct V_51 * V_103 = & V_74 -> V_24 . V_27 . V_53 ;
struct V_87 * V_88 = & V_15 -> V_57 ;
struct V_104 * V_105 = & V_15 -> V_106 ;
unsigned char * V_107 = F_40 ( V_105 ) ;
if ( F_42 ( V_105 , V_119 ) ) {
if ( memcmp ( V_103 -> V_117 , V_107 , V_116 ) )
return V_21 ;
* V_86 = F_26 ( V_88 , V_103 -> V_115 ) ;
if ( * V_86 == NULL )
return V_21 ;
}
return V_39 ;
}
static T_1 F_52 ( struct V_8 * V_15 ,
union V_11 * V_74 )
{
return V_21 ;
}
static T_1 F_53 ( struct V_8 * V_15 ,
union V_11 * V_74 )
{
return V_21 ;
}
static T_1 F_54 ( struct V_8 * V_15 ,
union V_11 * V_74 )
{
int V_38 ;
V_3 V_94 ;
V_3 * V_126 , * V_127 , * V_128 ;
struct V_49 * V_86 = NULL ;
V_3 * V_82 = V_74 -> V_24 . V_27 . V_62 ;
struct V_51 * V_103 = & V_74 -> V_24 . V_27 . V_53 ;
struct V_54 * V_55 = & V_15 -> V_56 ;
V_94 = F_55 ( V_82 ) ;
V_127 = F_56 ( V_82 ) ;
V_126 = F_57 ( V_82 ) ;
V_128 = F_58 ( V_82 ) ;
if ( V_128 == NULL )
return V_21 ;
memcpy ( V_103 -> V_112 , V_127 , V_116 ) ;
memcpy ( V_103 -> V_115 , V_126 , V_116 ) ;
memcpy ( V_103 -> V_117 , V_128 , V_116 ) ;
switch ( V_103 -> V_129 ) {
case 0 :
memcpy ( V_103 -> V_61 , V_127 , V_116 ) ;
memcpy ( V_103 -> V_58 , V_126 , V_116 ) ;
V_38 = F_39 ( V_15 , V_74 , & V_86 ) ;
break;
case 1 :
memcpy ( V_103 -> V_61 , V_127 , V_116 ) ;
memcpy ( V_103 -> V_58 , V_128 , V_116 ) ;
V_38 = F_48 ( V_15 , V_74 , & V_86 ) ;
break;
case 2 :
memcpy ( V_103 -> V_61 , V_128 , V_116 ) ;
memcpy ( V_103 -> V_58 , V_126 , V_116 ) ;
V_38 = F_51 ( V_15 , V_74 , & V_86 ) ;
break;
case 3 :
memcpy ( V_103 -> V_61 , F_44 ( V_82 ) , V_116 ) ;
memcpy ( V_103 -> V_58 , F_45 ( V_82 ) , V_116 ) ;
return V_21 ;
default:
return V_21 ;
}
if ( V_38 == V_21 )
return V_21 ;
if ( V_86 == NULL )
return V_21 ;
V_74 -> V_24 . V_27 . V_86 = V_86 ;
V_103 -> V_130 = 0 ;
if ( V_103 -> V_131 == 1 ) {
V_103 -> V_71 = F_59 ( ( V_82 + 24 ) ) ;
V_103 -> V_132 = F_60 ( ( V_82 + 24 ) ) ;
V_103 -> V_130 = F_61 ( ( V_82 + 24 ) ) ;
V_103 -> V_63 = V_103 -> V_129 == 3 ? 32 : 26 ;
} else {
V_103 -> V_71 = 0 ;
V_103 -> V_63 = ( V_103 -> V_129 == 3 ) ? 30 : 24 ;
}
if ( V_103 -> V_133 )
V_103 -> V_63 += 4 ;
V_74 -> V_24 . V_27 . V_134 =
& V_86 -> V_135 [ V_103 -> V_71 ] ;
if ( F_38 ( V_74 , V_94 , & V_86 -> V_136 . V_137 ) ==
V_21 )
return V_21 ;
if ( V_103 -> V_138 ) {
F_62 ( V_55 , V_86 , V_103 -> V_59 ,
F_27 ( V_103 -> V_61 ) ) ;
F_63 ( V_103 -> V_69 , V_103 -> V_70 ,
V_103 -> V_59 ) ;
} else {
V_103 -> V_59 = 0 ;
V_103 -> V_69 = V_103 -> V_70 = 0 ;
}
return V_39 ;
}
T_1 F_64 ( struct V_8 * V_15 ,
union V_11 * V_74 )
{
V_3 type ;
V_3 V_139 ;
T_1 V_140 = V_39 ;
struct V_51 * V_103 = & V_74 -> V_24 . V_27 . V_53 ;
V_3 * V_82 = V_74 -> V_24 . V_27 . V_62 ;
V_3 V_141 = ( unsigned char ) ( * V_82 ) & 0x3 ;
if ( V_141 != 0 )
return V_21 ;
type = F_65 ( V_82 ) ;
V_139 = F_49 ( V_82 ) ;
V_103 -> V_129 = F_66 ( V_82 ) ;
V_103 -> V_100 = F_67 ( V_82 ) ;
V_103 -> V_99 = F_68 ( V_82 ) ;
V_103 -> V_142 = F_69 ( V_82 ) ;
V_103 -> V_143 = F_70 ( V_82 ) ;
V_103 -> V_144 = F_71 ( V_82 ) ;
V_103 -> V_138 = F_72 ( V_82 ) ;
V_103 -> V_133 = F_73 ( V_82 ) ;
switch ( type ) {
case V_145 :
V_140 = F_53 ( V_15 , V_74 ) ;
break;
case V_146 :
V_140 = F_52 ( V_15 , V_74 ) ;
break;
case V_147 :
V_103 -> V_131 = ( V_139 & F_50 ( 7 ) ) ? 1 : 0 ;
V_140 = F_54 ( V_15 , V_74 ) ;
break;
default:
return V_21 ;
}
return V_140 ;
}
T_1 F_74 ( union V_11 * V_12 )
{
T_1 V_148 ;
T_4 V_68 ;
V_3 V_149 ;
V_3 * V_150 ;
struct V_151 * V_152 ;
struct V_8 * V_15 = V_12 -> V_24 . V_27 . V_15 ;
struct V_104 * V_105 = & V_15 -> V_106 ;
V_3 * V_82 = F_36 ( V_12 ) ;
struct V_51 * V_103 = & V_12 -> V_24 . V_27 . V_53 ;
if ( V_103 -> V_59 )
F_30 ( V_12 , V_103 -> V_70 ) ;
V_152 = (struct V_151 * ) ( V_82 + V_103 -> V_63 +
V_103 -> V_69 ) ;
V_150 = V_82 + V_103 -> V_63 + V_103 -> V_69 + V_153 ;
if ( ( ! memcmp ( V_152 , ( void * ) V_154 , V_153 ) &&
( memcmp ( V_150 , ( void * ) V_155 , 2 ) ) &&
( memcmp ( V_150 , ( void * ) V_156 , 2 ) ) ) ||
! memcmp ( V_152 , ( void * ) V_157 , V_153 ) ) {
V_149 = true ;
} else {
V_149 = false ;
}
V_148 = V_103 -> V_63 + V_103 -> V_69 +
( V_149 ? V_153 : 0 ) ;
V_68 = V_12 -> V_24 . V_27 . V_68 - V_148 ;
if ( F_42 ( V_105 , V_120 ) ) {
V_82 += V_148 ;
* V_82 = 0x87 ;
* ( V_82 + 1 ) = 0x12 ;
V_82 = F_75 ( V_12 , ( V_148 -
sizeof( struct V_158 ) + 2 ) - 24 ) ;
if ( ! V_82 )
return V_21 ;
memcpy ( V_82 , F_76 ( V_12 ) , 24 ) ;
V_82 += 24 ;
} else {
V_82 = F_75 ( V_12 , ( V_148 -
sizeof( struct V_158 ) + ( V_149 ? 2 : 0 ) ) ) ;
if ( ! V_82 )
return V_21 ;
}
memcpy ( V_82 , V_103 -> V_112 , V_116 ) ;
memcpy ( V_82 + V_116 , V_103 -> V_115 , V_116 ) ;
if ( ! V_149 ) {
T_5 V_159 = F_77 ( V_68 ) ;
memcpy ( V_82 + 12 , & V_159 , 2 ) ;
}
return V_39 ;
}
T_6 F_78 ( union V_11 * V_12 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
T_6 V_102 = V_39 ;
V_9 = V_12 -> V_24 . V_27 . V_15 ;
V_7 = & ( V_9 -> V_32 ) ;
V_9 -> V_160 . V_161 ( V_9 , V_162 ) ;
V_102 = F_79 ( V_9 , V_12 ) ;
if ( V_102 == V_21 )
goto V_163;
V_7 -> V_164 ++ ;
V_7 -> V_165 += ( T_3 ) ( V_12 -> V_24 . V_27 . V_166 -
V_12 -> V_24 . V_27 . V_62 ) ;
return V_102 ;
V_163:
V_7 -> V_167 ++ ;
V_9 -> V_121 . V_122 = V_7 -> V_167 ;
return V_102 ;
}
