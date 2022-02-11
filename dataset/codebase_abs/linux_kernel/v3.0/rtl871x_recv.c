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
sizeof( union V_11 ) +
V_19 ) ;
if ( V_7 -> V_18 == NULL )
return V_20 ;
memset ( V_7 -> V_18 , 0 , V_17 *
sizeof( union V_11 ) + V_19 ) ;
V_7 -> V_21 = V_7 -> V_18 +
V_19 -
( ( V_22 ) ( V_7 -> V_18 ) &
( V_19 - 1 ) ) ;
V_12 = (union V_11 * ) V_7 -> V_21 ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ ) {
F_6 ( & ( V_12 -> V_23 . V_24 ) ) ;
F_7 ( & ( V_12 -> V_23 . V_24 ) ,
& ( V_7 -> V_13 . V_25 ) ) ;
F_8 ( V_9 , V_12 ) ;
V_12 -> V_23 . V_26 . V_15 = V_9 ;
V_12 ++ ;
}
V_7 -> V_27 = 1 ;
F_9 ( & V_7 -> V_28 , 0 ) ;
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
struct V_32 * V_33 , * V_34 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
F_15 ( & V_30 -> V_4 , V_31 ) ;
if ( F_16 ( V_30 ) == true )
V_12 = NULL ;
else {
V_34 = F_17 ( V_30 ) ;
V_33 = F_18 ( V_34 ) ;
V_12 = F_19 ( V_33 , union V_11 , V_23 ) ;
F_20 ( & V_12 -> V_23 . V_26 . V_24 ) ;
V_9 = V_12 -> V_23 . V_26 . V_15 ;
if ( V_9 != NULL ) {
V_7 = & V_9 -> V_35 ;
if ( V_30 == & V_7 -> V_13 )
V_7 -> V_16 -- ;
}
}
F_21 ( & V_30 -> V_4 , V_31 ) ;
return V_12 ;
}
void F_22 ( struct V_29 * V_36 ,
struct V_29 * V_30 )
{
union V_11 * V_12 ;
struct V_32 * V_33 , * V_34 ;
F_23 ( & V_36 -> V_4 ) ;
V_34 = F_17 ( V_36 ) ;
V_33 = F_18 ( V_34 ) ;
while ( F_24 ( V_34 , V_33 ) == false ) {
V_12 = F_19 ( V_33 , union V_11 , V_23 ) ;
V_33 = F_18 ( V_33 ) ;
F_25 ( V_12 , V_30 ) ;
}
F_26 ( & V_36 -> V_4 ) ;
}
T_1 F_27 ( struct V_8 * V_15 ,
union V_11 * V_12 )
{
T_1 V_10 , V_37 = V_38 ;
T_2 V_39 ;
V_3 V_40 [ 8 ] ;
V_3 V_41 = false ;
V_3 * V_42 , * V_43 , * V_44 ;
V_3 * V_45 , V_46 , * V_47 ;
struct V_48 * V_49 ;
struct V_50 * V_51 = & V_12 -> V_23 . V_26 . V_52 ;
struct V_53 * V_54 = & V_15 -> V_55 ;
V_49 = F_28 ( & V_15 -> V_56 , & V_51 -> V_57 [ 0 ] ) ;
if ( V_51 -> V_58 == V_59 ) {
if ( V_49 != NULL ) {
if ( F_29 ( V_51 -> V_60 ) ) {
V_47 = V_12 -> V_23 . V_26 . V_61 +
V_51 -> V_62 ;
V_46 = V_47 [ 3 ] ;
V_45 = & V_54 -> V_63 [ ( ( ( V_46 >>
6 ) & 0x3 ) ) - 1 ] . V_64 [ 0 ] ;
if ( V_54 -> V_65 == false )
return V_20 ;
} else
V_45 = & V_49 -> V_66 . V_64 [ 0 ] ;
V_39 = V_12 -> V_23 . V_26 . V_67 - V_51 -> V_62 -
V_51 -> V_68 - V_51 -> V_69 - 8 ;
V_42 = V_12 -> V_23 . V_26 . V_61 ;
V_43 = V_42 + V_51 -> V_62 +
V_51 -> V_68 ;
F_30 ( V_45 , V_42 , V_43 , V_39 ,
& V_40 [ 0 ] ,
( unsigned char ) V_51 -> V_70 ) ;
V_44 = V_43 + V_39 ;
V_41 = false ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
if ( V_40 [ V_10 ] != * ( V_44 + V_10 ) )
V_41 = true ;
}
if ( V_41 == true ) {
if ( V_51 -> V_71 == true )
F_31 ( V_15 ,
( V_3 ) F_29 ( V_51 -> V_60 ) ) ;
V_37 = V_20 ;
} else {
if ( ( V_54 -> V_72 ==
false ) && ( F_29 ( V_51 -> V_60 ) ==
true ) )
V_54 -> V_72 = true ;
}
F_32 ( V_12 , 8 ) ;
}
}
return V_37 ;
}
union V_11 * F_33 ( struct V_8 * V_9 ,
union V_11 * V_73 )
{
struct V_50 * V_51 = & V_73 -> V_23 . V_26 . V_52 ;
struct V_53 * V_54 = & V_9 -> V_55 ;
union V_11 * V_74 = V_73 ;
if ( ( V_51 -> V_58 > 0 ) && ( ( V_51 -> V_71 == 0 ) ||
( V_54 -> V_75 == true ) ) ) {
V_54 -> V_76 = false ;
switch ( V_51 -> V_58 ) {
case V_77 :
case V_78 :
F_34 ( V_9 , ( V_3 * ) V_73 ) ;
break;
case V_59 :
F_35 ( V_9 , ( V_3 * ) V_73 ) ;
break;
case V_79 :
F_36 ( V_9 , ( V_3 * ) V_73 ) ;
break;
default:
break;
}
} else if ( V_51 -> V_71 == 1 )
V_54 -> V_76 = true ;
return V_74 ;
}
union V_11 * F_37 ( struct V_8 * V_15 ,
union V_11 * V_73 )
{
V_3 * V_80 , * V_81 ;
T_3 V_82 ;
struct V_83 * V_84 ;
struct V_48 * V_85 ;
struct V_86 * V_87 ;
union V_11 * V_88 ;
T_4 V_89 = 0 ;
V_87 = & V_15 -> V_56 ;
V_81 = F_38 ( V_73 ) ;
V_84 = & V_73 -> V_23 . V_26 ;
V_80 = V_84 -> V_52 . V_57 ;
V_85 = F_28 ( V_87 , V_80 ) ;
V_82 = V_15 -> V_55 . V_90 ;
if ( V_82 == 2 ) {
if ( ( V_85 != NULL ) && ( V_85 -> V_91 ) ) {
V_88 = V_73 ;
V_81 = V_81 + V_84 -> V_52 . V_62 +
V_84 -> V_52 . V_68 + V_92 ;
memcpy ( & V_89 , V_81 , 2 ) ;
V_89 = F_39 ( ( unsigned short ) V_89 ) ;
if ( V_89 == 0x888e )
V_88 = V_73 ;
else {
F_25 ( V_73 ,
& V_15 -> V_35 . V_13 ) ;
V_88 = NULL ;
}
} else {
V_88 = V_73 ;
if ( V_89 == 0x888e ) {
V_88 = V_73 ;
}
}
} else
V_88 = V_73 ;
return V_88 ;
}
static T_1 F_40 ( union V_11 * V_73 , V_3 V_93 ,
struct V_94 * V_95 )
{
T_1 V_96 = V_73 -> V_23 . V_26 . V_52 . V_70 ;
T_4 V_97 = ( ( V_73 -> V_23 . V_26 . V_52 . V_98 & 0xffff ) << 4 ) |
( V_73 -> V_23 . V_26 . V_52 . V_99 & 0xf ) ;
if ( V_96 > 15 )
return V_20 ;
if ( V_97 == V_95 -> V_100 [ V_96 ] )
return V_20 ;
V_95 -> V_100 [ V_96 ] = V_97 ;
return V_38 ;
}
static T_1 F_41 ( struct V_8 * V_15 ,
union V_11 * V_73 ,
struct V_48 * * V_85 )
{
V_3 * V_81 = V_73 -> V_23 . V_26 . V_61 ;
T_1 V_101 = V_38 ;
struct V_50 * V_102 = & V_73 -> V_23 . V_26 . V_52 ;
struct V_86 * V_87 = & V_15 -> V_56 ;
struct V_103 * V_104 = & V_15 -> V_105 ;
V_3 * V_106 = F_42 ( V_104 ) ;
V_3 * V_107 = F_43 ( & V_15 -> V_108 ) ;
V_3 * V_109 = NULL ;
T_1 V_110 = F_29 ( V_102 -> V_111 ) ;
if ( ( F_44 ( V_104 , V_112 ) == true ) ||
( F_44 ( V_104 , V_113 ) == true ) ) {
if ( ! memcmp ( V_107 , V_102 -> V_114 , V_115 ) )
return V_20 ;
if ( ( memcmp ( V_107 , V_102 -> V_111 , V_115 ) ) && ( ! V_110 ) )
return V_20 ;
if ( ! memcmp ( V_102 -> V_116 , L_1 , V_115 ) ||
! memcmp ( V_106 , L_1 , V_115 ) ||
( memcmp ( V_102 -> V_116 , V_106 , V_115 ) ) )
return V_20 ;
V_109 = V_102 -> V_114 ;
} else if ( F_44 ( V_104 , V_117 ) == true ) {
if ( memcmp ( V_102 -> V_116 , V_102 -> V_114 , V_115 ) )
return V_20 ;
V_109 = V_102 -> V_116 ;
} else if ( F_44 ( V_104 , V_118 ) == true ) {
if ( V_110 ) {
if ( ! F_29 ( V_102 -> V_116 ) )
return V_20 ;
} else {
if ( memcmp ( V_102 -> V_116 , V_102 -> V_111 , V_115 ) )
return V_20 ;
V_109 = V_102 -> V_114 ;
}
} else if ( F_44 ( V_104 , V_119 ) == true ) {
memcpy ( V_102 -> V_111 , F_45 ( V_81 ) , V_115 ) ;
memcpy ( V_102 -> V_114 , F_46 ( V_81 ) , V_115 ) ;
memcpy ( V_102 -> V_116 , F_47 ( V_81 ) , V_115 ) ;
memcpy ( V_102 -> V_60 , V_102 -> V_111 , V_115 ) ;
memcpy ( V_102 -> V_57 , V_102 -> V_114 , V_115 ) ;
V_109 = V_106 ;
} else
V_101 = V_20 ;
if ( V_110 )
* V_85 = F_48 ( V_15 ) ;
else
* V_85 = F_28 ( V_87 , V_109 ) ;
if ( * V_85 == NULL ) {
if ( F_44 ( V_104 , V_119 ) == true )
V_15 -> V_120 . V_121 ++ ;
return V_20 ;
}
return V_101 ;
}
static T_1 F_49 ( struct V_8 * V_15 ,
union V_11 * V_73 ,
struct V_48 * * V_85 )
{
V_3 * V_81 = V_73 -> V_23 . V_26 . V_61 ;
struct V_50 * V_102 = & V_73 -> V_23 . V_26 . V_52 ;
struct V_86 * V_87 = & V_15 -> V_56 ;
struct V_103 * V_104 = & V_15 -> V_105 ;
V_3 * V_106 = F_42 ( V_104 ) ;
V_3 * V_107 = F_43 ( & V_15 -> V_108 ) ;
T_1 V_110 = F_29 ( V_102 -> V_111 ) ;
if ( ( F_44 ( V_104 , V_117 ) == true )
&& ( F_44 ( V_104 , V_122 ) == true ) ) {
if ( ( F_50 ( V_81 ) ) == V_123 )
return V_20 ;
if ( ( F_50 ( V_81 ) & V_124 ) ==
V_124 ) {
if ( F_50 ( V_81 ) & ( F_51 ( 4 ) | F_51 ( 5 ) | F_51 ( 6 ) ) )
return V_20 ;
}
if ( ! memcmp ( V_107 , V_102 -> V_114 , V_115 ) )
return V_20 ;
if ( ( memcmp ( V_107 , V_102 -> V_111 , V_115 ) ) && ( ! V_110 ) )
return V_20 ;
if ( ! memcmp ( V_102 -> V_116 , L_1 , V_115 ) ||
! memcmp ( V_106 , L_1 , V_115 ) ||
( memcmp ( V_102 -> V_116 , V_106 , V_115 ) ) )
return V_20 ;
if ( V_110 )
* V_85 = F_48 ( V_15 ) ;
else
* V_85 = F_28 ( V_87 , V_102 -> V_116 ) ;
if ( * V_85 == NULL )
return V_20 ;
} else if ( ( F_44 ( V_104 , V_119 ) == true ) &&
( F_44 ( V_104 , V_122 ) == true ) ) {
memcpy ( V_102 -> V_111 , F_45 ( V_81 ) , V_115 ) ;
memcpy ( V_102 -> V_114 , F_46 ( V_81 ) , V_115 ) ;
memcpy ( V_102 -> V_116 , F_47 ( V_81 ) , V_115 ) ;
memcpy ( V_102 -> V_60 , V_102 -> V_111 , V_115 ) ;
memcpy ( V_102 -> V_57 , V_102 -> V_114 , V_115 ) ;
memcpy ( V_102 -> V_116 , V_106 , V_115 ) ;
* V_85 = F_28 ( V_87 , V_102 -> V_116 ) ;
if ( * V_85 == NULL )
return V_20 ;
} else
return V_20 ;
return V_38 ;
}
static T_1 F_52 ( struct V_8 * V_15 ,
union V_11 * V_73 ,
struct V_48 * * V_85 )
{
struct V_50 * V_102 = & V_73 -> V_23 . V_26 . V_52 ;
struct V_86 * V_87 = & V_15 -> V_56 ;
struct V_103 * V_104 = & V_15 -> V_105 ;
unsigned char * V_106 = F_42 ( V_104 ) ;
if ( F_44 ( V_104 , V_118 ) == true ) {
if ( memcmp ( V_102 -> V_116 , V_106 , V_115 ) )
return V_20 ;
* V_85 = F_28 ( V_87 , V_102 -> V_114 ) ;
if ( * V_85 == NULL )
return V_20 ;
}
return V_38 ;
}
static T_1 F_53 ( struct V_8 * V_15 ,
union V_11 * V_73 )
{
return V_20 ;
}
static T_1 F_54 ( struct V_8 * V_15 ,
union V_11 * V_73 )
{
return V_20 ;
}
static T_1 F_55 ( struct V_8 * V_15 ,
union V_11 * V_73 )
{
int V_37 ;
V_3 V_93 ;
V_3 * V_125 , * V_126 , * V_127 ;
struct V_48 * V_85 = NULL ;
V_3 * V_81 = V_73 -> V_23 . V_26 . V_61 ;
struct V_50 * V_102 = & V_73 -> V_23 . V_26 . V_52 ;
struct V_53 * V_54 = & V_15 -> V_55 ;
V_93 = F_56 ( V_81 ) ;
V_126 = F_57 ( V_81 ) ;
V_125 = F_58 ( V_81 ) ;
V_127 = F_59 ( V_81 ) ;
if ( V_127 == NULL )
return V_20 ;
memcpy ( V_102 -> V_111 , V_126 , V_115 ) ;
memcpy ( V_102 -> V_114 , V_125 , V_115 ) ;
memcpy ( V_102 -> V_116 , V_127 , V_115 ) ;
switch ( V_102 -> V_128 ) {
case 0 :
memcpy ( V_102 -> V_60 , V_126 , V_115 ) ;
memcpy ( V_102 -> V_57 , V_125 , V_115 ) ;
V_37 = F_41 ( V_15 , V_73 , & V_85 ) ;
break;
case 1 :
memcpy ( V_102 -> V_60 , V_126 , V_115 ) ;
memcpy ( V_102 -> V_57 , V_127 , V_115 ) ;
V_37 = F_49 ( V_15 , V_73 , & V_85 ) ;
break;
case 2 :
memcpy ( V_102 -> V_60 , V_127 , V_115 ) ;
memcpy ( V_102 -> V_57 , V_125 , V_115 ) ;
V_37 = F_52 ( V_15 , V_73 , & V_85 ) ;
break;
case 3 :
memcpy ( V_102 -> V_60 , F_45 ( V_81 ) , V_115 ) ;
memcpy ( V_102 -> V_57 , F_46 ( V_81 ) , V_115 ) ;
return V_20 ;
default:
return V_20 ;
}
if ( V_37 == V_20 )
return V_20 ;
if ( V_85 == NULL )
return V_20 ;
else
V_73 -> V_23 . V_26 . V_85 = V_85 ;
V_102 -> V_129 = 0 ;
if ( V_102 -> V_130 == 1 ) {
V_102 -> V_70 = F_60 ( ( V_81 + 24 ) ) ;
V_102 -> V_131 = F_61 ( ( V_81 + 24 ) ) ;
V_102 -> V_129 = F_62 ( ( V_81 + 24 ) ) ;
V_102 -> V_62 = V_102 -> V_128 == 3 ? 32 : 26 ;
} else {
V_102 -> V_70 = 0 ;
V_102 -> V_62 = ( V_102 -> V_128 == 3 ) ? 30 : 24 ;
}
if ( V_102 -> V_132 )
V_102 -> V_62 += 4 ;
V_73 -> V_23 . V_26 . V_133 =
& V_85 -> V_134 [ V_102 -> V_70 ] ;
if ( F_40 ( V_73 , V_93 , & V_85 -> V_135 . V_136 ) ==
V_20 )
return V_20 ;
if ( V_102 -> V_137 ) {
F_63 ( V_54 , V_85 , V_102 -> V_58 ,
F_29 ( V_102 -> V_60 ) ) ;
F_64 ( V_102 -> V_68 , V_102 -> V_69 ,
V_102 -> V_58 ) ;
} else {
V_102 -> V_58 = 0 ;
V_102 -> V_68 = V_102 -> V_69 = 0 ;
}
return V_38 ;
}
T_1 F_65 ( struct V_8 * V_15 ,
union V_11 * V_73 )
{
V_3 type ;
V_3 V_138 ;
T_1 V_139 = V_38 ;
struct V_50 * V_102 = & V_73 -> V_23 . V_26 . V_52 ;
V_3 * V_81 = V_73 -> V_23 . V_26 . V_61 ;
V_3 V_140 = ( unsigned char ) ( * V_81 ) & 0x3 ;
if ( V_140 != 0 )
return V_20 ;
type = F_66 ( V_81 ) ;
V_138 = F_50 ( V_81 ) ;
V_102 -> V_128 = F_67 ( V_81 ) ;
V_102 -> V_99 = F_68 ( V_81 ) ;
V_102 -> V_98 = F_69 ( V_81 ) ;
V_102 -> V_141 = F_70 ( V_81 ) ;
V_102 -> V_142 = F_71 ( V_81 ) ;
V_102 -> V_143 = F_72 ( V_81 ) ;
V_102 -> V_137 = F_73 ( V_81 ) ;
V_102 -> V_132 = F_74 ( V_81 ) ;
switch ( type ) {
case V_144 :
V_139 = F_54 ( V_15 , V_73 ) ;
break;
case V_145 :
V_139 = F_53 ( V_15 , V_73 ) ;
break;
case V_146 :
V_102 -> V_130 = ( V_138 & F_51 ( 7 ) ) ? 1 : 0 ;
V_139 = F_55 ( V_15 , V_73 ) ;
break;
default:
return V_20 ;
}
return V_139 ;
}
T_1 F_75 ( union V_11 * V_12 )
{
T_1 V_147 ;
T_4 V_148 , V_67 ;
V_3 V_149 ;
V_3 * V_150 ;
struct V_151 * V_152 ;
T_1 V_101 = V_38 ;
struct V_8 * V_15 = V_12 -> V_23 . V_26 . V_15 ;
struct V_103 * V_104 = & V_15 -> V_105 ;
V_3 * V_81 = F_38 ( V_12 ) ;
struct V_50 * V_102 = & V_12 -> V_23 . V_26 . V_52 ;
if ( V_102 -> V_58 )
F_32 ( V_12 , V_102 -> V_69 ) ;
V_152 = (struct V_151 * ) ( V_81 + V_102 -> V_62 +
V_102 -> V_68 ) ;
V_150 = V_81 + V_102 -> V_62 + V_102 -> V_68 + V_153 ;
if ( ( ! memcmp ( V_152 , ( void * ) V_154 , V_153 ) &&
( memcmp ( V_150 , ( void * ) V_155 , 2 ) ) &&
( memcmp ( V_150 , ( void * ) V_156 , 2 ) ) ) ||
! memcmp ( V_152 , ( void * ) V_157 , V_153 ) ) {
V_149 = true ;
} else {
V_149 = false ;
}
V_147 = V_102 -> V_62 + V_102 -> V_68 +
( V_149 ? V_153 : 0 ) ;
V_67 = V_12 -> V_23 . V_26 . V_67 - V_147 ;
if ( ( F_44 ( V_104 , V_119 ) == true ) ) {
V_81 += V_147 ;
* V_81 = 0x87 ;
* ( V_81 + 1 ) = 0x12 ;
V_148 = 0x8712 ;
V_81 = F_76 ( V_12 , ( V_147 -
sizeof( struct V_158 ) + 2 ) - 24 ) ;
memcpy ( V_81 , F_77 ( V_12 ) , 24 ) ;
V_81 += 24 ;
} else
V_81 = F_76 ( V_12 , ( V_147 -
sizeof( struct V_158 ) + ( V_149 ? 2 : 0 ) ) ) ;
memcpy ( V_81 , V_102 -> V_111 , V_115 ) ;
memcpy ( V_81 + V_115 , V_102 -> V_114 , V_115 ) ;
if ( ! V_149 ) {
V_67 = F_78 ( V_67 ) ;
memcpy ( V_81 + 12 , & V_67 , 2 ) ;
}
return V_101 ;
}
T_5 F_79 ( union V_11 * V_12 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_103 * V_104 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
V_3 * V_34 , * V_163 , * V_164 , * V_165 ;
struct V_29 * V_30 , * V_166 ;
T_5 V_101 = V_38 ;
struct V_167 * V_168 ;
V_9 = V_12 -> V_23 . V_26 . V_15 ;
V_168 = & V_9 -> V_169 -> V_170 ;
V_104 = & V_9 -> V_105 ;
V_7 = & ( V_9 -> V_35 ) ;
V_162 = & V_9 -> V_171 ;
V_30 = & ( V_7 -> V_13 ) ;
V_166 = & ( V_7 -> V_14 ) ;
V_34 = V_12 -> V_23 . V_26 . V_172 ;
V_163 = V_12 -> V_23 . V_26 . V_61 ;
V_164 = V_12 -> V_23 . V_26 . V_173 ;
V_165 = V_12 -> V_23 . V_26 . V_174 ;
V_160 = (struct V_159 * ) V_34 ;
V_9 -> V_175 . V_176 ( V_9 , V_177 ) ;
V_101 = F_80 ( V_9 , V_12 ) ;
if ( V_101 == V_20 )
goto V_178;
V_7 -> V_179 ++ ;
V_7 -> V_180 += ( T_3 ) ( V_12 -> V_23 . V_26 . V_173 -
V_12 -> V_23 . V_26 . V_61 ) ;
return V_101 ;
V_178:
V_7 -> V_181 ++ ;
V_9 -> V_120 . V_121 = V_7 -> V_181 ;
return V_101 ;
}
