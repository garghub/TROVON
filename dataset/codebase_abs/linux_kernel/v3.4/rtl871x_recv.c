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
F_6 ( V_7 -> V_18 ) ;
memset ( V_7 -> V_18 , 0 , V_17 *
sizeof( union V_11 ) + V_19 ) ;
V_7 -> V_21 = V_7 -> V_18 +
V_19 -
( ( V_22 ) ( V_7 -> V_18 ) &
( V_19 - 1 ) ) ;
V_12 = (union V_11 * ) V_7 -> V_21 ;
for ( V_10 = 0 ; V_10 < V_17 ; V_10 ++ ) {
F_7 ( & ( V_12 -> V_23 . V_24 ) ) ;
F_8 ( & ( V_12 -> V_23 . V_24 ) ,
& ( V_7 -> V_13 . V_25 ) ) ;
F_9 ( V_9 , V_12 ) ;
V_12 -> V_23 . V_26 . V_15 = V_9 ;
V_12 ++ ;
}
V_7 -> V_27 = 1 ;
return F_10 ( V_7 , V_9 ) ;
}
void F_11 ( struct V_6 * V_7 )
{
F_12 ( V_7 -> V_18 ) ;
F_13 ( V_7 ) ;
}
union V_11 * F_14 ( struct V_28 * V_29 )
{
unsigned long V_30 ;
union V_11 * V_12 ;
struct V_31 * V_32 , * V_33 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
F_15 ( & V_29 -> V_4 , V_30 ) ;
if ( F_16 ( V_29 ) == true )
V_12 = NULL ;
else {
V_33 = F_17 ( V_29 ) ;
V_32 = F_18 ( V_33 ) ;
V_12 = F_19 ( V_32 , union V_11 , V_23 ) ;
F_20 ( & V_12 -> V_23 . V_26 . V_24 ) ;
V_9 = V_12 -> V_23 . V_26 . V_15 ;
if ( V_9 != NULL ) {
V_7 = & V_9 -> V_34 ;
if ( V_29 == & V_7 -> V_13 )
V_7 -> V_16 -- ;
}
}
F_21 ( & V_29 -> V_4 , V_30 ) ;
return V_12 ;
}
void F_22 ( struct V_28 * V_35 ,
struct V_28 * V_29 )
{
union V_11 * V_12 ;
struct V_31 * V_32 , * V_33 ;
F_23 ( & V_35 -> V_4 ) ;
V_33 = F_17 ( V_35 ) ;
V_32 = F_18 ( V_33 ) ;
while ( F_24 ( V_33 , V_32 ) == false ) {
V_12 = F_19 ( V_32 , union V_11 , V_23 ) ;
V_32 = F_18 ( V_32 ) ;
F_25 ( V_12 , V_29 ) ;
}
F_26 ( & V_35 -> V_4 ) ;
}
T_1 F_27 ( struct V_8 * V_15 ,
union V_11 * V_12 )
{
T_1 V_10 , V_36 = V_37 ;
T_2 V_38 ;
V_3 V_39 [ 8 ] ;
V_3 V_40 = false ;
V_3 * V_41 , * V_42 , * V_43 ;
V_3 * V_44 , V_45 , * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 = & V_12 -> V_23 . V_26 . V_51 ;
struct V_52 * V_53 = & V_15 -> V_54 ;
V_48 = F_28 ( & V_15 -> V_55 , & V_50 -> V_56 [ 0 ] ) ;
if ( V_50 -> V_57 == V_58 ) {
if ( V_48 != NULL ) {
if ( F_29 ( V_50 -> V_59 ) ) {
V_46 = V_12 -> V_23 . V_26 . V_60 +
V_50 -> V_61 ;
V_45 = V_46 [ 3 ] ;
V_44 = & V_53 -> V_62 [ ( ( ( V_45 >>
6 ) & 0x3 ) ) - 1 ] . V_63 [ 0 ] ;
if ( V_53 -> V_64 == false )
return V_20 ;
} else
V_44 = & V_48 -> V_65 . V_63 [ 0 ] ;
V_38 = V_12 -> V_23 . V_26 . V_66 - V_50 -> V_61 -
V_50 -> V_67 - V_50 -> V_68 - 8 ;
V_41 = V_12 -> V_23 . V_26 . V_60 ;
V_42 = V_41 + V_50 -> V_61 +
V_50 -> V_67 ;
F_30 ( V_44 , V_41 , V_42 , V_38 ,
& V_39 [ 0 ] ,
( unsigned char ) V_50 -> V_69 ) ;
V_43 = V_42 + V_38 ;
V_40 = false ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
if ( V_39 [ V_10 ] != * ( V_43 + V_10 ) )
V_40 = true ;
}
if ( V_40 == true ) {
if ( V_50 -> V_70 == true )
F_31 ( V_15 ,
( V_3 ) F_29 ( V_50 -> V_59 ) ) ;
V_36 = V_20 ;
} else {
if ( ( V_53 -> V_71 ==
false ) && ( F_29 ( V_50 -> V_59 ) ==
true ) )
V_53 -> V_71 = true ;
}
F_32 ( V_12 , 8 ) ;
}
}
return V_36 ;
}
union V_11 * F_33 ( struct V_8 * V_9 ,
union V_11 * V_72 )
{
struct V_49 * V_50 = & V_72 -> V_23 . V_26 . V_51 ;
struct V_52 * V_53 = & V_9 -> V_54 ;
union V_11 * V_73 = V_72 ;
if ( ( V_50 -> V_57 > 0 ) && ( ( V_50 -> V_70 == 0 ) ||
( V_53 -> V_74 == true ) ) ) {
V_53 -> V_75 = false ;
switch ( V_50 -> V_57 ) {
case V_76 :
case V_77 :
F_34 ( V_9 , ( V_3 * ) V_72 ) ;
break;
case V_58 :
F_35 ( V_9 , ( V_3 * ) V_72 ) ;
break;
case V_78 :
F_36 ( V_9 , ( V_3 * ) V_72 ) ;
break;
default:
break;
}
} else if ( V_50 -> V_70 == 1 )
V_53 -> V_75 = true ;
return V_73 ;
}
union V_11 * F_37 ( struct V_8 * V_15 ,
union V_11 * V_72 )
{
V_3 * V_79 , * V_80 ;
T_3 V_81 ;
struct V_82 * V_83 ;
struct V_47 * V_84 ;
struct V_85 * V_86 ;
union V_11 * V_87 ;
T_4 V_88 = 0 ;
V_86 = & V_15 -> V_55 ;
V_80 = F_38 ( V_72 ) ;
V_83 = & V_72 -> V_23 . V_26 ;
V_79 = V_83 -> V_51 . V_56 ;
V_84 = F_28 ( V_86 , V_79 ) ;
V_81 = V_15 -> V_54 . V_89 ;
if ( V_81 == 2 ) {
if ( ( V_84 != NULL ) && ( V_84 -> V_90 ) ) {
V_87 = V_72 ;
V_80 = V_80 + V_83 -> V_51 . V_61 +
V_83 -> V_51 . V_67 + V_91 ;
memcpy ( & V_88 , V_80 , 2 ) ;
V_88 = F_39 ( ( unsigned short ) V_88 ) ;
if ( V_88 == 0x888e )
V_87 = V_72 ;
else {
F_25 ( V_72 ,
& V_15 -> V_34 . V_13 ) ;
V_87 = NULL ;
}
} else {
V_87 = V_72 ;
if ( V_88 == 0x888e ) {
V_87 = V_72 ;
}
}
} else
V_87 = V_72 ;
return V_87 ;
}
static T_1 F_40 ( union V_11 * V_72 , V_3 V_92 ,
struct V_93 * V_94 )
{
T_1 V_95 = V_72 -> V_23 . V_26 . V_51 . V_69 ;
T_4 V_96 = ( ( V_72 -> V_23 . V_26 . V_51 . V_97 & 0xffff ) << 4 ) |
( V_72 -> V_23 . V_26 . V_51 . V_98 & 0xf ) ;
if ( V_95 > 15 )
return V_20 ;
if ( V_96 == V_94 -> V_99 [ V_95 ] )
return V_20 ;
V_94 -> V_99 [ V_95 ] = V_96 ;
return V_37 ;
}
static T_1 F_41 ( struct V_8 * V_15 ,
union V_11 * V_72 ,
struct V_47 * * V_84 )
{
V_3 * V_80 = V_72 -> V_23 . V_26 . V_60 ;
T_1 V_100 = V_37 ;
struct V_49 * V_101 = & V_72 -> V_23 . V_26 . V_51 ;
struct V_85 * V_86 = & V_15 -> V_55 ;
struct V_102 * V_103 = & V_15 -> V_104 ;
V_3 * V_105 = F_42 ( V_103 ) ;
V_3 * V_106 = F_43 ( & V_15 -> V_107 ) ;
V_3 * V_108 = NULL ;
T_1 V_109 = F_29 ( V_101 -> V_110 ) ;
if ( ( F_44 ( V_103 , V_111 ) == true ) ||
( F_44 ( V_103 , V_112 ) == true ) ) {
if ( ! memcmp ( V_106 , V_101 -> V_113 , V_114 ) )
return V_20 ;
if ( ( memcmp ( V_106 , V_101 -> V_110 , V_114 ) ) && ( ! V_109 ) )
return V_20 ;
if ( ! memcmp ( V_101 -> V_115 , L_1 , V_114 ) ||
! memcmp ( V_105 , L_1 , V_114 ) ||
( memcmp ( V_101 -> V_115 , V_105 , V_114 ) ) )
return V_20 ;
V_108 = V_101 -> V_113 ;
} else if ( F_44 ( V_103 , V_116 ) == true ) {
if ( memcmp ( V_101 -> V_115 , V_101 -> V_113 , V_114 ) )
return V_20 ;
V_108 = V_101 -> V_115 ;
} else if ( F_44 ( V_103 , V_117 ) == true ) {
if ( V_109 ) {
if ( ! F_29 ( V_101 -> V_115 ) )
return V_20 ;
} else {
if ( memcmp ( V_101 -> V_115 , V_101 -> V_110 , V_114 ) )
return V_20 ;
V_108 = V_101 -> V_113 ;
}
} else if ( F_44 ( V_103 , V_118 ) == true ) {
memcpy ( V_101 -> V_110 , F_45 ( V_80 ) , V_114 ) ;
memcpy ( V_101 -> V_113 , F_46 ( V_80 ) , V_114 ) ;
memcpy ( V_101 -> V_115 , F_47 ( V_80 ) , V_114 ) ;
memcpy ( V_101 -> V_59 , V_101 -> V_110 , V_114 ) ;
memcpy ( V_101 -> V_56 , V_101 -> V_113 , V_114 ) ;
V_108 = V_105 ;
} else
V_100 = V_20 ;
if ( V_109 )
* V_84 = F_48 ( V_15 ) ;
else
* V_84 = F_28 ( V_86 , V_108 ) ;
if ( * V_84 == NULL ) {
if ( F_44 ( V_103 , V_118 ) == true )
V_15 -> V_119 . V_120 ++ ;
return V_20 ;
}
return V_100 ;
}
static T_1 F_49 ( struct V_8 * V_15 ,
union V_11 * V_72 ,
struct V_47 * * V_84 )
{
V_3 * V_80 = V_72 -> V_23 . V_26 . V_60 ;
struct V_49 * V_101 = & V_72 -> V_23 . V_26 . V_51 ;
struct V_85 * V_86 = & V_15 -> V_55 ;
struct V_102 * V_103 = & V_15 -> V_104 ;
V_3 * V_105 = F_42 ( V_103 ) ;
V_3 * V_106 = F_43 ( & V_15 -> V_107 ) ;
T_1 V_109 = F_29 ( V_101 -> V_110 ) ;
if ( ( F_44 ( V_103 , V_116 ) == true )
&& ( F_44 ( V_103 , V_121 ) == true ) ) {
if ( ( F_50 ( V_80 ) ) == V_122 )
return V_20 ;
if ( ( F_50 ( V_80 ) & V_123 ) ==
V_123 ) {
if ( F_50 ( V_80 ) & ( F_51 ( 4 ) | F_51 ( 5 ) | F_51 ( 6 ) ) )
return V_20 ;
}
if ( ! memcmp ( V_106 , V_101 -> V_113 , V_114 ) )
return V_20 ;
if ( ( memcmp ( V_106 , V_101 -> V_110 , V_114 ) ) && ( ! V_109 ) )
return V_20 ;
if ( ! memcmp ( V_101 -> V_115 , L_1 , V_114 ) ||
! memcmp ( V_105 , L_1 , V_114 ) ||
( memcmp ( V_101 -> V_115 , V_105 , V_114 ) ) )
return V_20 ;
if ( V_109 )
* V_84 = F_48 ( V_15 ) ;
else
* V_84 = F_28 ( V_86 , V_101 -> V_115 ) ;
if ( * V_84 == NULL )
return V_20 ;
} else if ( ( F_44 ( V_103 , V_118 ) == true ) &&
( F_44 ( V_103 , V_121 ) == true ) ) {
memcpy ( V_101 -> V_110 , F_45 ( V_80 ) , V_114 ) ;
memcpy ( V_101 -> V_113 , F_46 ( V_80 ) , V_114 ) ;
memcpy ( V_101 -> V_115 , F_47 ( V_80 ) , V_114 ) ;
memcpy ( V_101 -> V_59 , V_101 -> V_110 , V_114 ) ;
memcpy ( V_101 -> V_56 , V_101 -> V_113 , V_114 ) ;
memcpy ( V_101 -> V_115 , V_105 , V_114 ) ;
* V_84 = F_28 ( V_86 , V_101 -> V_115 ) ;
if ( * V_84 == NULL )
return V_20 ;
} else
return V_20 ;
return V_37 ;
}
static T_1 F_52 ( struct V_8 * V_15 ,
union V_11 * V_72 ,
struct V_47 * * V_84 )
{
struct V_49 * V_101 = & V_72 -> V_23 . V_26 . V_51 ;
struct V_85 * V_86 = & V_15 -> V_55 ;
struct V_102 * V_103 = & V_15 -> V_104 ;
unsigned char * V_105 = F_42 ( V_103 ) ;
if ( F_44 ( V_103 , V_117 ) == true ) {
if ( memcmp ( V_101 -> V_115 , V_105 , V_114 ) )
return V_20 ;
* V_84 = F_28 ( V_86 , V_101 -> V_113 ) ;
if ( * V_84 == NULL )
return V_20 ;
}
return V_37 ;
}
static T_1 F_53 ( struct V_8 * V_15 ,
union V_11 * V_72 )
{
return V_20 ;
}
static T_1 F_54 ( struct V_8 * V_15 ,
union V_11 * V_72 )
{
return V_20 ;
}
static T_1 F_55 ( struct V_8 * V_15 ,
union V_11 * V_72 )
{
int V_36 ;
V_3 V_92 ;
V_3 * V_124 , * V_125 , * V_126 ;
struct V_47 * V_84 = NULL ;
V_3 * V_80 = V_72 -> V_23 . V_26 . V_60 ;
struct V_49 * V_101 = & V_72 -> V_23 . V_26 . V_51 ;
struct V_52 * V_53 = & V_15 -> V_54 ;
V_92 = F_56 ( V_80 ) ;
V_125 = F_57 ( V_80 ) ;
V_124 = F_58 ( V_80 ) ;
V_126 = F_59 ( V_80 ) ;
if ( V_126 == NULL )
return V_20 ;
memcpy ( V_101 -> V_110 , V_125 , V_114 ) ;
memcpy ( V_101 -> V_113 , V_124 , V_114 ) ;
memcpy ( V_101 -> V_115 , V_126 , V_114 ) ;
switch ( V_101 -> V_127 ) {
case 0 :
memcpy ( V_101 -> V_59 , V_125 , V_114 ) ;
memcpy ( V_101 -> V_56 , V_124 , V_114 ) ;
V_36 = F_41 ( V_15 , V_72 , & V_84 ) ;
break;
case 1 :
memcpy ( V_101 -> V_59 , V_125 , V_114 ) ;
memcpy ( V_101 -> V_56 , V_126 , V_114 ) ;
V_36 = F_49 ( V_15 , V_72 , & V_84 ) ;
break;
case 2 :
memcpy ( V_101 -> V_59 , V_126 , V_114 ) ;
memcpy ( V_101 -> V_56 , V_124 , V_114 ) ;
V_36 = F_52 ( V_15 , V_72 , & V_84 ) ;
break;
case 3 :
memcpy ( V_101 -> V_59 , F_45 ( V_80 ) , V_114 ) ;
memcpy ( V_101 -> V_56 , F_46 ( V_80 ) , V_114 ) ;
return V_20 ;
default:
return V_20 ;
}
if ( V_36 == V_20 )
return V_20 ;
if ( V_84 == NULL )
return V_20 ;
else
V_72 -> V_23 . V_26 . V_84 = V_84 ;
V_101 -> V_128 = 0 ;
if ( V_101 -> V_129 == 1 ) {
V_101 -> V_69 = F_60 ( ( V_80 + 24 ) ) ;
V_101 -> V_130 = F_61 ( ( V_80 + 24 ) ) ;
V_101 -> V_128 = F_62 ( ( V_80 + 24 ) ) ;
V_101 -> V_61 = V_101 -> V_127 == 3 ? 32 : 26 ;
} else {
V_101 -> V_69 = 0 ;
V_101 -> V_61 = ( V_101 -> V_127 == 3 ) ? 30 : 24 ;
}
if ( V_101 -> V_131 )
V_101 -> V_61 += 4 ;
V_72 -> V_23 . V_26 . V_132 =
& V_84 -> V_133 [ V_101 -> V_69 ] ;
if ( F_40 ( V_72 , V_92 , & V_84 -> V_134 . V_135 ) ==
V_20 )
return V_20 ;
if ( V_101 -> V_136 ) {
F_63 ( V_53 , V_84 , V_101 -> V_57 ,
F_29 ( V_101 -> V_59 ) ) ;
F_64 ( V_101 -> V_67 , V_101 -> V_68 ,
V_101 -> V_57 ) ;
} else {
V_101 -> V_57 = 0 ;
V_101 -> V_67 = V_101 -> V_68 = 0 ;
}
return V_37 ;
}
T_1 F_65 ( struct V_8 * V_15 ,
union V_11 * V_72 )
{
V_3 type ;
V_3 V_137 ;
T_1 V_138 = V_37 ;
struct V_49 * V_101 = & V_72 -> V_23 . V_26 . V_51 ;
V_3 * V_80 = V_72 -> V_23 . V_26 . V_60 ;
V_3 V_139 = ( unsigned char ) ( * V_80 ) & 0x3 ;
if ( V_139 != 0 )
return V_20 ;
type = F_66 ( V_80 ) ;
V_137 = F_50 ( V_80 ) ;
V_101 -> V_127 = F_67 ( V_80 ) ;
V_101 -> V_98 = F_68 ( V_80 ) ;
V_101 -> V_97 = F_69 ( V_80 ) ;
V_101 -> V_140 = F_70 ( V_80 ) ;
V_101 -> V_141 = F_71 ( V_80 ) ;
V_101 -> V_142 = F_72 ( V_80 ) ;
V_101 -> V_136 = F_73 ( V_80 ) ;
V_101 -> V_131 = F_74 ( V_80 ) ;
switch ( type ) {
case V_143 :
V_138 = F_54 ( V_15 , V_72 ) ;
break;
case V_144 :
V_138 = F_53 ( V_15 , V_72 ) ;
break;
case V_145 :
V_101 -> V_129 = ( V_137 & F_51 ( 7 ) ) ? 1 : 0 ;
V_138 = F_55 ( V_15 , V_72 ) ;
break;
default:
return V_20 ;
}
return V_138 ;
}
T_1 F_75 ( union V_11 * V_12 )
{
T_1 V_146 ;
T_4 V_147 , V_66 ;
V_3 V_148 ;
V_3 * V_149 ;
struct V_150 * V_151 ;
T_1 V_100 = V_37 ;
struct V_8 * V_15 = V_12 -> V_23 . V_26 . V_15 ;
struct V_102 * V_103 = & V_15 -> V_104 ;
V_3 * V_80 = F_38 ( V_12 ) ;
struct V_49 * V_101 = & V_12 -> V_23 . V_26 . V_51 ;
if ( V_101 -> V_57 )
F_32 ( V_12 , V_101 -> V_68 ) ;
V_151 = (struct V_150 * ) ( V_80 + V_101 -> V_61 +
V_101 -> V_67 ) ;
V_149 = V_80 + V_101 -> V_61 + V_101 -> V_67 + V_152 ;
if ( ( ! memcmp ( V_151 , ( void * ) V_153 , V_152 ) &&
( memcmp ( V_149 , ( void * ) V_154 , 2 ) ) &&
( memcmp ( V_149 , ( void * ) V_155 , 2 ) ) ) ||
! memcmp ( V_151 , ( void * ) V_156 , V_152 ) ) {
V_148 = true ;
} else {
V_148 = false ;
}
V_146 = V_101 -> V_61 + V_101 -> V_67 +
( V_148 ? V_152 : 0 ) ;
V_66 = V_12 -> V_23 . V_26 . V_66 - V_146 ;
if ( ( F_44 ( V_103 , V_118 ) == true ) ) {
V_80 += V_146 ;
* V_80 = 0x87 ;
* ( V_80 + 1 ) = 0x12 ;
V_147 = 0x8712 ;
V_80 = F_76 ( V_12 , ( V_146 -
sizeof( struct V_157 ) + 2 ) - 24 ) ;
memcpy ( V_80 , F_77 ( V_12 ) , 24 ) ;
V_80 += 24 ;
} else
V_80 = F_76 ( V_12 , ( V_146 -
sizeof( struct V_157 ) + ( V_148 ? 2 : 0 ) ) ) ;
memcpy ( V_80 , V_101 -> V_110 , V_114 ) ;
memcpy ( V_80 + V_114 , V_101 -> V_113 , V_114 ) ;
if ( ! V_148 ) {
V_66 = F_78 ( V_66 ) ;
memcpy ( V_80 + 12 , & V_66 , 2 ) ;
}
return V_100 ;
}
T_5 F_79 ( union V_11 * V_12 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
struct V_102 * V_103 ;
struct V_158 * V_159 ;
struct V_160 * V_161 ;
V_3 * V_33 , * V_162 , * V_163 , * V_164 ;
struct V_28 * V_29 , * V_165 ;
T_5 V_100 = V_37 ;
struct V_166 * V_167 ;
V_9 = V_12 -> V_23 . V_26 . V_15 ;
V_167 = & V_9 -> V_168 -> V_169 ;
V_103 = & V_9 -> V_104 ;
V_7 = & ( V_9 -> V_34 ) ;
V_161 = & V_9 -> V_170 ;
V_29 = & ( V_7 -> V_13 ) ;
V_165 = & ( V_7 -> V_14 ) ;
V_33 = V_12 -> V_23 . V_26 . V_171 ;
V_162 = V_12 -> V_23 . V_26 . V_60 ;
V_163 = V_12 -> V_23 . V_26 . V_172 ;
V_164 = V_12 -> V_23 . V_26 . V_173 ;
V_159 = (struct V_158 * ) V_33 ;
V_9 -> V_174 . V_175 ( V_9 , V_176 ) ;
V_100 = F_80 ( V_9 , V_12 ) ;
if ( V_100 == V_20 )
goto V_177;
V_7 -> V_178 ++ ;
V_7 -> V_179 += ( T_3 ) ( V_12 -> V_23 . V_26 . V_172 -
V_12 -> V_23 . V_26 . V_60 ) ;
return V_100 ;
V_177:
V_7 -> V_180 ++ ;
V_9 -> V_119 . V_120 = V_7 -> V_180 ;
return V_100 ;
}
