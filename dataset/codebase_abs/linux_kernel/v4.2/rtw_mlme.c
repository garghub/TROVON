int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
int V_10 = V_11 ;
V_8 -> V_12 = ( T_1 * ) V_2 ;
V_8 -> V_13 = NULL ;
V_8 -> V_14 = 0 ;
V_8 -> V_15 . V_16 . V_17 = V_18 ;
V_8 -> V_19 = V_20 ;
F_2 ( & ( V_8 -> V_21 ) ) ;
F_3 ( & ( V_8 -> V_22 ) ) ;
F_3 ( & ( V_8 -> V_23 ) ) ;
F_4 ( V_8 , 0 ) ;
memset ( & V_8 -> V_24 , 0 , sizeof( struct V_25 ) ) ;
V_4 = F_5 ( V_26 * ( sizeof( struct V_5 ) ) ) ;
if ( V_4 == NULL ) {
V_10 = V_27 ;
goto exit;
}
V_8 -> V_28 = V_4 ;
V_6 = (struct V_5 * ) V_4 ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ ) {
F_6 ( & ( V_6 -> V_29 ) ) ;
F_7 ( & ( V_6 -> V_29 ) , & ( V_8 -> V_22 . V_30 ) ) ;
V_6 ++ ;
}
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
exit:
return V_10 ;
}
static void F_10 ( T_1 * * V_31 , T_2 * V_32 )
{
F_11 ( * V_31 ) ;
* V_32 = 0 ;
* V_31 = NULL ;
}
void F_12 ( struct V_7 * V_8 )
{
F_13 ( & V_8 -> V_33 , & V_8 -> V_34 ) ;
F_13 ( & V_8 -> V_35 , & V_8 -> V_36 ) ;
F_10 ( & V_8 -> V_37 , & V_8 -> V_38 ) ;
F_10 ( & V_8 -> V_39 , & V_8 -> V_40 ) ;
F_10 ( & V_8 -> V_41 , & V_8 -> V_42 ) ;
F_10 ( & V_8 -> V_43 , & V_8 -> V_44 ) ;
F_10 ( & V_8 -> V_45 , & V_8 -> V_46 ) ;
F_10 ( & V_8 -> V_47 , & V_8 -> V_48 ) ;
F_10 ( & V_8 -> V_49 , & V_8 -> V_50 ) ;
F_10 ( & V_8 -> V_51 , & V_8 -> V_52 ) ;
F_10 ( & V_8 -> V_53 , & V_8 -> V_54 ) ;
}
void F_12 ( struct V_7 * V_8 )
{
}
void F_14 ( struct V_7 * V_8 )
{
F_12 ( V_8 ) ;
if ( V_8 ) {
if ( V_8 -> V_28 )
F_15 ( V_8 -> V_28 ) ;
}
}
struct V_5 * F_16 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
struct V_55 * V_56 = & V_8 -> V_22 ;
struct V_57 * V_58 = NULL ;
F_17 ( & V_56 -> V_21 ) ;
if ( F_18 ( & V_56 -> V_30 ) ) {
V_6 = NULL ;
goto exit;
}
V_58 = V_56 -> V_30 . V_59 ;
V_6 = F_19 ( V_58 , struct V_5 , V_29 ) ;
F_20 ( & V_6 -> V_29 ) ;
F_21 ( V_60 , V_61 , ( L_1 , V_58 ) ) ;
V_6 -> V_62 = 0 ;
V_6 -> V_63 = false ;
V_6 -> V_64 = V_65 ;
V_6 -> V_66 = 0 ;
V_6 -> V_67 = 0 ;
V_8 -> V_68 ++ ;
exit:
F_22 ( & V_56 -> V_21 ) ;
return V_6 ;
}
static void F_23 ( struct V_7 * V_8 , struct V_5 * V_6 , T_1 V_69 )
{
T_2 V_70 , V_71 ;
T_2 V_72 = V_73 ;
struct V_55 * V_56 = & ( V_8 -> V_22 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_63 )
return;
V_70 = V_65 ;
if ( ( F_24 ( V_8 , V_74 ) ) ||
( F_24 ( V_8 , V_75 ) ) )
V_72 = 1 ;
if ( ! V_69 ) {
V_71 = ( V_70 - V_6 -> V_64 ) / V_76 ;
if ( V_71 < V_72 )
return;
}
F_17 ( & V_56 -> V_21 ) ;
F_20 ( & ( V_6 -> V_29 ) ) ;
F_7 ( & ( V_6 -> V_29 ) , & ( V_56 -> V_30 ) ) ;
V_8 -> V_68 -- ;
F_22 ( & V_56 -> V_21 ) ;
}
void F_25 ( struct V_7 * V_8 , struct V_5 * V_6 )
{
struct V_55 * V_56 = & ( V_8 -> V_22 ) ;
if ( V_6 == NULL )
return;
if ( V_6 -> V_63 )
return;
F_20 ( & ( V_6 -> V_29 ) ) ;
F_7 ( & ( V_6 -> V_29 ) , F_26 ( V_56 ) ) ;
V_8 -> V_68 -- ;
}
struct V_5 * F_27 ( struct V_55 * V_23 , T_1 * V_77 )
{
struct V_57 * V_78 , * V_58 ;
struct V_5 * V_6 = NULL ;
T_1 V_79 [ V_80 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
if ( ! memcmp ( V_79 , V_77 , V_80 ) ) {
V_6 = NULL ;
goto exit;
}
V_78 = F_26 ( V_23 ) ;
V_58 = V_78 -> V_59 ;
while ( V_58 != V_78 ) {
V_6 = F_19 ( V_58 , struct V_5 , V_29 ) ;
if ( ! memcmp ( V_77 , V_6 -> V_16 . V_81 , V_80 ) )
break;
V_58 = V_58 -> V_59 ;
}
if ( V_58 == V_78 )
V_6 = NULL ;
exit:
return V_6 ;
}
void F_28 ( struct V_1 * V_2 , T_1 V_69 )
{
struct V_57 * V_78 , * V_58 ;
struct V_5 * V_6 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_55 * V_23 = & V_8 -> V_23 ;
F_17 ( & V_23 -> V_21 ) ;
V_78 = F_26 ( V_23 ) ;
V_58 = V_78 -> V_59 ;
while ( V_78 != V_58 ) {
V_6 = F_19 ( V_58 , struct V_5 , V_29 ) ;
V_58 = V_58 -> V_59 ;
F_23 ( V_8 , V_6 , V_69 ) ;
}
F_22 ( & V_23 -> V_21 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
int V_10 ;
if ( V_2 -> V_82 || V_2 -> V_83 ||
( F_24 ( & V_2 -> V_9 , V_84 ) == false ) ) {
F_21 ( V_60 , V_61 ,
( L_2 ,
V_2 -> V_82 , V_2 -> V_83 ) ) ;
V_10 = false ;
} else {
V_10 = true ;
}
return V_10 ;
}
void F_30 ( T_1 * V_85 )
{
T_2 V_86 = V_65 ;
V_85 [ 0 ] = 0x02 ;
V_85 [ 1 ] = 0x11 ;
V_85 [ 2 ] = 0x87 ;
V_85 [ 3 ] = ( T_1 ) ( V_86 & 0xff ) ;
V_85 [ 4 ] = ( T_1 ) ( ( V_86 >> 8 ) & 0xff ) ;
V_85 [ 5 ] = ( T_1 ) ( ( V_86 >> 16 ) & 0xff ) ;
return;
}
T_1 * F_31 ( T_1 * V_87 )
{
return V_87 + 8 + 2 ;
}
T_3 F_32 ( struct V_88 * V_89 )
{
T_4 V_90 ;
memcpy ( ( T_1 * ) & V_90 , F_31 ( V_89 -> V_91 ) , 2 ) ;
return F_33 ( V_90 ) ;
}
T_1 * F_34 ( T_1 * V_87 )
{
return V_87 + 8 ;
}
static struct V_5 * F_35 ( struct V_7 * V_8 )
{
return F_16 ( V_8 ) ;
}
static void F_36 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_25 ( V_8 , V_6 ) ;
}
int F_37 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
int V_92 = true ;
struct V_93 * V_94 = & V_1 -> V_95 ;
if ( ( V_94 -> V_96 != V_97 ) &&
( V_6 -> V_16 . V_98 == 0 ) )
V_92 = false ;
else if ( ( V_94 -> V_96 == V_97 ) &&
( V_6 -> V_16 . V_98 == 1 ) )
V_92 = false ;
else
V_92 = true ;
return V_92 ;
}
static int F_38 ( struct V_88 * V_99 , struct V_88 * V_100 )
{
return ( V_99 -> V_101 . V_102 == V_100 -> V_101 . V_102 ) &&
! memcmp ( V_99 -> V_101 . V_101 , V_100 -> V_101 . V_101 , V_99 -> V_101 . V_102 ) ;
}
int F_39 ( struct V_88 * V_103 , struct V_88 * V_104 )
{
T_3 V_105 , V_106 ;
T_4 V_107 , V_108 ;
memcpy ( ( T_1 * ) & V_107 , F_31 ( V_103 -> V_91 ) , 2 ) ;
memcpy ( ( T_1 * ) & V_108 , F_31 ( V_104 -> V_91 ) , 2 ) ;
V_105 = F_33 ( V_107 ) ;
V_106 = F_33 ( V_108 ) ;
return ( ( V_103 -> V_101 . V_102 == V_104 -> V_101 . V_102 ) &&
( ( ! memcmp ( V_103 -> V_81 , V_104 -> V_81 , V_80 ) ) == true ) &&
( ( ! memcmp ( V_103 -> V_101 . V_101 , V_104 -> V_101 . V_101 , V_103 -> V_101 . V_102 ) ) == true ) &&
( ( V_105 & V_109 ) ==
( V_106 & V_109 ) ) &&
( ( V_105 & V_110 ) ==
( V_106 & V_110 ) ) ) ;
}
struct V_5 * F_40 ( struct V_55 * V_23 )
{
struct V_57 * V_58 , * V_78 ;
struct V_5 * V_111 = NULL ;
struct V_5 * V_112 = NULL ;
V_78 = F_26 ( V_23 ) ;
V_58 = V_78 -> V_59 ;
while ( 1 ) {
if ( V_78 == V_58 )
break;
V_111 = F_19 ( V_58 , struct V_5 , V_29 ) ;
if ( ! V_111 -> V_63 ) {
if ( V_112 == NULL || F_41 ( V_112 -> V_64 , V_111 -> V_64 ) )
V_112 = V_111 ;
}
V_58 = V_58 -> V_59 ;
}
return V_112 ;
}
void F_42 ( struct V_88 * V_104 , struct V_88 * V_103 ,
struct V_1 * V_2 , bool V_113 )
{
long V_114 = V_104 -> V_115 ;
T_1 V_116 = V_103 -> V_117 . V_118 ;
T_1 V_119 ;
T_1 V_120 ;
long V_121 ;
F_43 ( V_2 , V_104 , V_103 ) ;
if ( F_24 ( & V_2 -> V_9 , V_84 ) && F_39 ( & ( V_2 -> V_9 . V_15 . V_16 ) , V_103 ) ) {
V_119 = V_2 -> V_122 . V_123 ;
V_120 = V_2 -> V_122 . V_124 ;
if ( V_116 != 101 )
V_121 = ( V_103 -> V_115 + V_104 -> V_115 * 4 ) / 5 ;
else
V_121 = V_114 ;
} else {
if ( V_116 != 101 ) {
V_119 = ( ( T_2 ) ( V_103 -> V_117 . V_125 ) + ( T_2 ) ( V_104 -> V_117 . V_125 ) * 4 ) / 5 ;
V_120 = ( ( T_2 ) ( V_103 -> V_117 . V_118 ) + ( T_2 ) ( V_104 -> V_117 . V_118 ) * 4 ) / 5 ;
V_121 = ( V_103 -> V_115 + V_104 -> V_115 * 4 ) / 5 ;
} else {
V_119 = V_104 -> V_117 . V_125 ;
V_120 = V_104 -> V_117 . V_118 ;
V_121 = V_104 -> V_115 ;
}
}
if ( V_113 )
memcpy ( ( T_1 * ) V_104 , ( T_1 * ) V_103 , F_44 ( V_103 ) ) ;
V_104 -> V_117 . V_125 = V_119 ;
V_104 -> V_117 . V_118 = V_120 ;
V_104 -> V_115 = V_121 ;
}
static void F_45 ( struct V_1 * V_1 , struct V_88 * V_6 )
{
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
if ( ( F_24 ( V_8 , V_84 ) == true ) &&
( F_39 ( & ( V_8 -> V_15 . V_16 ) , V_6 ) ) ) {
F_42 ( & ( V_8 -> V_15 . V_16 ) , V_6 , V_1 , true ) ;
F_46 ( V_1 , ( V_8 -> V_15 . V_16 . V_91 ) + sizeof( struct V_126 ) ,
V_8 -> V_15 . V_16 . V_127 ) ;
}
}
void F_47 ( struct V_1 * V_1 , struct V_88 * V_128 )
{
struct V_57 * V_58 , * V_78 ;
T_2 V_129 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_55 * V_30 = & ( V_8 -> V_23 ) ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_112 = NULL ;
F_17 ( & V_30 -> V_21 ) ;
V_78 = F_26 ( V_30 ) ;
V_58 = V_78 -> V_59 ;
while ( V_78 != V_58 ) {
V_6 = F_19 ( V_58 , struct V_5 , V_29 ) ;
if ( F_39 ( & ( V_6 -> V_16 ) , V_128 ) )
break;
if ( ( V_112 == ( (struct V_5 * ) 0 ) ) ||
F_41 ( V_112 -> V_64 , V_6 -> V_64 ) )
V_112 = V_6 ;
V_58 = V_58 -> V_59 ;
}
if ( V_78 == V_58 ) {
if ( F_18 ( & ( V_8 -> V_22 . V_30 ) ) ) {
V_6 = V_112 ;
F_48 ( V_1 , V_130 , & ( V_128 -> V_117 . V_131 ) ) ;
memcpy ( & ( V_6 -> V_16 ) , V_128 , F_44 ( V_128 ) ) ;
V_6 -> V_63 = false ;
V_6 -> V_64 = V_65 ;
V_6 -> V_62 = 0 ;
V_6 -> V_66 = 0 ;
V_6 -> V_67 = 0 ;
if ( V_6 -> V_16 . V_117 . V_118 == 101 )
V_6 -> V_16 . V_117 . V_118 = 0 ;
} else {
V_6 = F_35 ( V_8 ) ;
if ( V_6 == NULL ) {
F_21 ( V_60 , V_132 , ( L_3 ) ) ;
goto exit;
}
V_129 = F_44 ( V_128 ) ;
V_128 -> V_133 = V_129 ;
F_48 ( V_1 , V_130 , & ( V_128 -> V_117 . V_131 ) ) ;
memcpy ( & ( V_6 -> V_16 ) , V_128 , V_129 ) ;
V_6 -> V_64 = V_65 ;
if ( V_6 -> V_16 . V_117 . V_118 == 101 )
V_6 -> V_16 . V_117 . V_118 = 0 ;
F_7 ( & ( V_6 -> V_29 ) , & ( V_30 -> V_30 ) ) ;
}
} else {
bool V_113 = true ;
V_6 -> V_64 = V_65 ;
if ( ( V_6 -> V_16 . V_127 > V_128 -> V_127 ) && ( V_128 -> V_134 [ 0 ] == 1 ) )
V_113 = false ;
F_42 ( & ( V_6 -> V_16 ) , V_128 , V_1 , V_113 ) ;
}
exit:
F_22 ( & V_30 -> V_21 ) ;
}
static void F_49 ( struct V_1 * V_1 ,
struct V_88 * V_6 )
{
F_45 ( V_1 , V_6 ) ;
F_47 ( V_1 , V_6 ) ;
}
static int F_50 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
struct V_93 * V_94 = & V_1 -> V_95 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
T_2 V_135 ;
T_2 V_136 ;
T_5 V_137 ;
int V_138 = true ;
V_135 = V_94 -> V_139 ;
V_136 = V_6 -> V_16 . V_98 ;
if ( F_24 ( V_8 , V_140 ) ) {
if ( F_51 ( V_6 -> V_16 . V_91 + V_141 , V_6 -> V_16 . V_127 - V_141 , NULL , & V_137 ) != NULL )
return true ;
else
return false ;
}
if ( V_1 -> V_142 . V_143 == 1 ) {
if ( ( V_135 == V_144 ) && ( V_136 != 0 ) )
V_138 = false ;
}
if ( ( V_135 != V_144 ) && ( V_136 == 0 ) ) {
F_52 ( L_4 , V_135 , V_136 ) ;
V_138 = false ;
}
if ( F_24 ( V_8 , V_75 ) == true ) {
if ( V_6 -> V_16 . V_17 != V_8 -> V_15 . V_16 . V_17 )
V_138 = false ;
}
return V_138 ;
}
void F_53 ( struct V_1 * V_1 , T_1 * V_4 )
{
F_21 ( V_60 , V_132 , ( L_5 ) ) ;
return;
}
void F_54 ( struct V_1 * V_1 , T_1 * V_4 )
{
T_2 V_145 ;
struct V_88 * V_6 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
V_6 = (struct V_88 * ) V_4 ;
F_21 ( V_60 , V_61 , ( L_6 , V_6 -> V_101 . V_101 ) ) ;
V_145 = F_44 ( V_6 ) ;
if ( V_145 > ( sizeof( struct V_88 ) ) ) {
F_21 ( V_60 , V_132 , ( L_7 ) ) ;
return;
}
F_17 ( & V_8 -> V_21 ) ;
if ( ( F_24 ( V_8 , V_74 ) ) == true ) {
if ( ! memcmp ( & ( V_8 -> V_15 . V_16 . V_81 ) , V_6 -> V_81 , V_80 ) ) {
struct V_5 * V_146 = NULL ;
memcpy ( V_8 -> V_15 . V_16 . V_91 , V_6 -> V_91 , 8 ) ;
F_17 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_146 = F_27 ( & V_8 -> V_23 , V_6 -> V_81 ) ;
if ( V_146 ) {
memcpy ( V_146 -> V_16 . V_91 , V_6 -> V_91 , 8 ) ;
F_22 ( & V_8 -> V_23 . V_21 ) ;
goto exit;
}
F_22 ( & V_8 -> V_23 . V_21 ) ;
}
}
if ( ( F_24 ( V_8 , V_147 ) ) == false ) {
if ( V_6 -> V_101 . V_101 [ 0 ] == 0 )
V_6 -> V_101 . V_102 = 0 ;
F_49 ( V_1 , V_6 ) ;
}
exit:
F_22 ( & V_8 -> V_21 ) ;
return;
}
void F_55 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
F_17 ( & V_8 -> V_21 ) ;
if ( V_8 -> V_39 ) {
V_8 -> V_40 = 0 ;
F_11 ( V_8 -> V_39 ) ;
V_8 -> V_39 = NULL ;
}
F_21 ( V_60 , V_61 , ( L_8 , F_56 ( V_8 ) ) ) ;
if ( F_24 ( V_8 , V_148 ) ) {
F_57 ( & V_8 -> V_149 ) ;
F_58 ( V_8 , V_148 ) ;
} else {
F_21 ( V_60 , V_132 , ( L_9 , F_56 ( V_8 ) ) ) ;
}
F_59 ( & V_1 -> V_122 ) ;
if ( V_8 -> V_150 ) {
if ( ( F_24 ( V_8 , V_75 ) == true ) ) {
if ( F_24 ( V_8 , V_84 ) == false ) {
F_60 ( V_8 , V_147 ) ;
if ( F_61 ( V_8 ) == V_11 ) {
F_62 ( & V_8 -> V_151 ,
V_65 + F_63 ( V_152 ) ) ;
} else {
struct V_88 * V_153 = & ( V_1 -> V_142 . V_154 ) ;
T_1 * V_85 = V_1 -> V_142 . V_154 . V_81 ;
F_58 ( V_8 , V_148 ) ;
F_21 ( V_60 , V_132 , ( L_10 ) ) ;
memcpy ( & V_153 -> V_101 , & V_8 -> V_24 , sizeof( struct V_25 ) ) ;
F_64 ( V_1 ) ;
F_30 ( V_85 ) ;
V_8 -> V_14 = V_74 ;
if ( F_65 ( V_1 ) != V_11 )
F_21 ( V_60 , V_132 , ( L_11 ) ) ;
V_8 -> V_150 = false ;
}
}
} else {
int V_155 ;
F_60 ( V_8 , V_147 ) ;
V_8 -> V_150 = false ;
V_155 = F_61 ( V_8 ) ;
if ( V_11 == V_155 ) {
F_62 ( & V_8 -> V_151 ,
V_65 + F_63 ( V_152 ) ) ;
} else if ( V_155 == 2 ) {
F_58 ( V_8 , V_147 ) ;
F_66 ( V_1 ) ;
} else {
F_52 ( L_12 , V_8 -> V_156 ) ;
if ( V_8 -> V_156 != 0 ) {
if ( -- V_8 -> V_156 == 0 ||
V_11 != F_67 ( V_1 , & V_8 -> V_24 , 1 , NULL , 0 ) ) {
V_8 -> V_156 = 0 ;
F_68 ( V_1 , 1 ) ;
F_69 ( V_1 ) ;
} else {
V_8 -> V_150 = true ;
}
}
F_58 ( V_8 , V_147 ) ;
}
}
}
F_70 ( V_1 ) ;
F_22 ( & V_8 -> V_21 ) ;
F_71 ( V_1 ) ;
}
void F_72 ( struct V_1 * V_1 , T_1 * V_4 )
{
}
void F_73 ( struct V_1 * V_1 , T_1 * V_4 )
{
}
static void F_74 ( struct V_7 * V_8 )
{
struct V_55 * V_56 = & V_8 -> V_22 ;
struct V_55 * V_157 = & V_8 -> V_23 ;
struct V_57 * V_58 , * V_78 , * V_158 ;
F_21 ( V_60 , V_159 , ( L_13 ) ) ;
F_17 ( & V_157 -> V_21 ) ;
F_17 ( & V_56 -> V_21 ) ;
V_78 = F_26 ( V_157 ) ;
V_58 = V_78 -> V_59 ;
while ( V_58 != V_78 ) {
V_158 = V_58 -> V_59 ;
F_20 ( V_58 ) ;
F_7 ( V_58 , & V_56 -> V_30 ) ;
V_58 = V_158 ;
V_8 -> V_68 -- ;
}
F_22 ( & V_56 -> V_21 ) ;
F_22 ( & V_157 -> V_21 ) ;
}
void F_68 ( struct V_1 * V_1 , int V_160 )
{
struct V_5 * V_111 = NULL ;
struct V_7 * V_8 = & V_1 -> V_9 ;
struct V_161 * V_162 = & V_1 -> V_163 ;
struct V_5 * V_164 = & V_8 -> V_15 ;
F_21 ( V_60 , V_159 , ( L_14 ) ) ;
F_21 ( V_60 , V_61 ,
( L_15 ,
V_164 -> V_16 . V_81 , V_164 -> V_16 . V_101 . V_101 ) ) ;
if ( F_24 ( V_8 , V_165 | V_166 ) ) {
struct V_167 * V_168 ;
V_168 = F_75 ( & V_1 -> V_163 , V_164 -> V_16 . V_81 ) ;
F_17 ( & ( V_162 -> V_169 ) ) ;
F_76 ( V_1 , V_168 ) ;
F_22 ( & V_162 -> V_169 ) ;
}
if ( F_24 ( V_8 , V_75 | V_74 | V_166 ) ) {
struct V_167 * V_168 ;
F_77 ( V_1 ) ;
V_168 = F_78 ( V_1 ) ;
F_17 ( & ( V_162 -> V_169 ) ) ;
F_76 ( V_1 , V_168 ) ;
F_22 ( & V_162 -> V_169 ) ;
F_79 ( V_1 ) ;
}
if ( V_160 )
F_17 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_111 = F_27 ( & V_8 -> V_23 , V_164 -> V_16 . V_81 ) ;
if ( V_111 )
V_111 -> V_63 = false ;
else
F_21 ( V_60 , V_132 , ( L_16 ) ) ;
if ( ( F_24 ( V_8 , V_74 ) && ( V_1 -> V_163 . V_170 == 1 ) ) )
F_36 ( V_8 , V_111 ) ;
if ( V_160 )
F_22 ( & V_8 -> V_23 . V_21 ) ;
V_8 -> V_171 = 0 ;
}
void F_66 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
F_21 ( V_60 , V_132 , ( L_17 ) ) ;
V_8 -> V_150 = false ;
if ( ! F_24 ( & V_2 -> V_9 , V_84 ) ) {
F_60 ( V_8 , V_84 ) ;
F_80 ( V_2 , V_172 ) ;
F_81 ( V_2 ) ;
}
V_8 -> V_156 = 0 ;
F_82 ( V_2 , 3000 ) ;
F_21 ( V_60 , V_132 , ( L_18 , F_56 ( V_8 ) ) ) ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
F_21 ( V_60 , V_132 , ( L_19 ) ) ;
F_58 ( V_8 , V_147 | V_140 ) ;
if ( V_8 -> V_156 > 0 )
F_58 ( V_8 , V_84 ) ;
if ( F_24 ( & V_2 -> V_9 , V_84 ) ||
( V_8 -> V_156 <= 0 ) ) {
F_83 ( V_2 ) ;
F_58 ( V_8 , V_84 ) ;
F_80 ( V_2 , V_173 ) ;
F_8 ( V_2 ) ;
}
F_84 ( V_2 , V_174 , 1 ) ;
}
inline void F_85 ( struct V_1 * V_2 , bool V_175 )
{
F_86 ( V_2 , V_175 ) ;
}
void F_87 ( struct V_1 * V_1 )
{
T_2 V_176 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_177 * V_178 = & ( V_1 -> V_179 ) ;
V_176 = V_65 ;
V_178 -> V_180 = true ;
while ( F_24 ( V_8 , V_148 ) &&
F_88 ( V_176 ) <= 200 ) {
if ( V_1 -> V_82 || V_1 -> V_83 )
break;
F_52 ( V_181 L_20 , F_89 ( V_1 -> V_182 ) ) ;
F_90 ( 20 ) ;
}
if ( F_24 ( V_8 , V_148 ) ) {
if ( ! V_1 -> V_82 && ! V_1 -> V_83 )
F_52 ( V_181 L_21 , F_89 ( V_1 -> V_182 ) ) ;
F_85 ( V_1 , true ) ;
}
V_178 -> V_180 = false ;
}
static struct V_167 * F_91 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
int V_3 ;
struct V_167 * V_183 , * V_168 = NULL ;
struct V_184 * V_185 ;
struct V_161 * V_162 = & V_2 -> V_163 ;
V_168 = F_75 ( V_162 , V_6 -> V_16 . V_81 ) ;
if ( V_168 == NULL )
V_168 = F_92 ( V_162 , V_6 -> V_16 . V_81 ) ;
if ( V_168 ) {
F_52 ( L_22 , V_186 ) ;
V_168 -> V_66 = V_6 -> V_67 ;
V_168 -> V_187 = 0 ;
F_93 ( V_2 , V_188 , V_168 , true ) ;
if ( V_2 -> V_95 . V_189 == V_190 ) {
V_2 -> V_95 . V_191 = false ;
V_2 -> V_95 . V_192 = false ;
V_2 -> V_95 . V_193 = false ;
V_168 -> V_194 = true ;
V_168 -> V_195 = V_2 -> V_95 . V_96 ;
memset ( ( T_1 * ) & V_168 -> V_196 , 0 , sizeof( union V_197 ) ) ;
memset ( ( T_1 * ) & V_168 -> V_198 , 0 , sizeof( union V_197 ) ) ;
memset ( ( T_1 * ) & V_168 -> V_199 , 0 , sizeof( union V_197 ) ) ;
memset ( ( T_1 * ) & V_168 -> V_200 , 0 , sizeof( union V_201 ) ) ;
memset ( ( T_1 * ) & V_168 -> V_202 , 0 , sizeof( union V_201 ) ) ;
}
if ( V_2 -> V_95 . V_203 != 0 ) {
V_168 -> V_194 = true ;
V_2 -> V_95 . V_203 = 0 ;
}
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_185 = & V_168 -> V_204 [ V_3 ] ;
V_185 -> V_205 = false ;
V_185 -> V_206 = 0xffff ;
V_185 -> V_207 = 0xffff ;
V_185 -> V_208 = 64 ;
}
V_183 = F_78 ( V_2 ) ;
if ( V_183 ) {
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
V_185 = & V_183 -> V_204 [ V_3 ] ;
V_185 -> V_205 = false ;
V_185 -> V_206 = 0xffff ;
V_185 -> V_207 = 0xffff ;
V_185 -> V_208 = 64 ;
}
}
F_94 ( V_2 , V_168 ) ;
}
return V_168 ;
}
static void F_95 ( struct V_1 * V_2 , struct V_5 * V_209 , struct V_5 * V_6 )
{
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_5 * V_15 = & ( V_8 -> V_15 ) ;
F_52 ( L_22 , V_186 ) ;
F_21 ( V_60 , V_61 ,
( L_23 ,
F_56 ( V_8 ) , V_6 -> V_16 . V_81 ) ) ;
memcpy ( & V_15 -> V_16 , & V_6 -> V_16 , V_6 -> V_16 . V_133 ) ;
V_15 -> V_16 . V_127 = V_209 -> V_16 . V_127 ;
memcpy ( & V_15 -> V_16 . V_91 [ 0 ] , & V_209 -> V_16 . V_91 [ 0 ] , V_210 ) ;
V_15 -> V_66 = V_6 -> V_67 ;
F_59 ( & V_2 -> V_122 ) ;
V_2 -> V_122 . V_123 = V_209 -> V_16 . V_117 . V_125 ;
V_2 -> V_122 . V_124 = V_209 -> V_16 . V_117 . V_118 ;
V_2 -> V_122 . V_211 = F_96 ( V_209 -> V_16 . V_117 . V_125 ) ;
F_59 ( & V_2 -> V_122 ) ;
switch ( V_6 -> V_16 . V_17 ) {
case V_212 :
if ( V_8 -> V_14 & V_140 )
V_8 -> V_14 = V_165 | V_140 ;
else
V_8 -> V_14 = V_165 ;
break;
case V_213 :
V_8 -> V_14 = V_75 ;
break;
default:
V_8 -> V_14 = V_214 ;
F_21 ( V_60 , V_132 , ( L_24 ) ) ;
break;
}
F_46 ( V_2 , ( V_15 -> V_16 . V_91 ) +
sizeof( struct V_126 ) ,
( V_15 -> V_16 . V_127 ) ) ;
F_97 ( V_2 , V_15 -> V_16 . V_91 , V_15 -> V_16 . V_127 ) ;
}
void F_98 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_167 * V_215 = NULL , * V_216 = NULL ;
struct V_161 * V_162 = & V_1 -> V_163 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
struct V_5 * V_15 = & ( V_8 -> V_15 ) ;
struct V_5 * V_217 = NULL , * V_209 = NULL ;
unsigned int V_218 = false ;
F_21 ( V_60 , V_61 , ( L_25 , V_6 -> V_67 ) ) ;
F_99 ( V_1 ) ;
if ( V_8 -> V_24 . V_102 == 0 )
F_21 ( V_60 , V_132 , ( L_26 ) ) ;
else
F_21 ( V_60 , V_132 , ( L_27 , V_8 -> V_24 . V_101 ) ) ;
V_218 = ! memcmp ( V_6 -> V_16 . V_81 , V_15 -> V_16 . V_81 , V_80 ) ;
V_6 -> V_16 . V_133 = F_44 ( & V_6 -> V_16 ) ;
if ( V_6 -> V_16 . V_133 > sizeof( struct V_88 ) ) {
F_21 ( V_60 , V_132 , ( L_28 ) ) ;
return;
}
F_17 ( & V_8 -> V_21 ) ;
F_21 ( V_60 , V_61 , ( L_29 ) ) ;
if ( V_6 -> V_67 > 0 ) {
F_17 ( & ( V_8 -> V_23 . V_21 ) ) ;
if ( F_24 ( V_8 , V_147 ) ) {
if ( F_24 ( V_8 , V_84 ) ) {
if ( V_218 ) {
V_209 = F_27 ( & V_8 -> V_23 , V_15 -> V_16 . V_81 ) ;
} else {
V_217 = F_27 ( & V_8 -> V_23 , V_15 -> V_16 . V_81 ) ;
if ( V_217 )
V_217 -> V_63 = false ;
V_216 = F_75 ( V_162 , V_15 -> V_16 . V_81 ) ;
if ( V_216 ) {
F_17 ( & ( V_162 -> V_169 ) ) ;
F_76 ( V_1 , V_216 ) ;
F_22 ( & V_162 -> V_169 ) ;
}
V_209 = F_27 ( & V_8 -> V_23 , V_6 -> V_16 . V_81 ) ;
if ( F_24 ( V_8 , V_165 ) == true ) {
if ( V_209 )
V_209 -> V_63 = true ;
}
}
} else {
V_209 = F_27 ( & V_8 -> V_23 , V_6 -> V_16 . V_81 ) ;
if ( F_24 ( V_8 , V_165 ) == true ) {
if ( V_209 )
V_209 -> V_63 = true ;
}
}
if ( V_209 ) {
F_95 ( V_1 , V_209 , V_6 ) ;
} else {
F_21 ( V_60 , V_132 , ( L_30 ) ) ;
F_22 ( & V_8 -> V_23 . V_21 ) ;
goto V_219;
}
if ( F_24 ( V_8 , V_165 ) == true ) {
V_215 = F_91 ( V_1 , V_6 ) ;
if ( V_215 == NULL ) {
F_21 ( V_60 , V_132 , ( L_31 ) ) ;
F_22 ( & V_8 -> V_23 . V_21 ) ;
goto V_219;
}
}
if ( F_24 ( V_8 , V_165 ) == true ) {
F_66 ( V_1 ) ;
} else {
F_21 ( V_60 , V_61 , ( L_32 , F_56 ( V_8 ) ) ) ;
}
F_57 ( & V_8 -> V_151 ) ;
F_21 ( V_60 , V_61 , ( L_33 ) ) ;
} else {
F_21 ( V_60 , V_132 , ( L_34 , F_56 ( V_8 ) ) ) ;
F_22 ( & V_8 -> V_23 . V_21 ) ;
goto V_219;
}
F_22 ( & V_8 -> V_23 . V_21 ) ;
} else if ( V_6 -> V_67 == - 4 ) {
F_100 ( V_1 ) ;
F_62 ( & V_8 -> V_151 ,
V_65 + F_63 ( 1 ) ) ;
if ( ( F_24 ( V_8 , V_147 ) ) == true ) {
F_21 ( V_60 , V_132 , ( L_35 , F_56 ( V_8 ) ) ) ;
F_58 ( V_8 , V_147 ) ;
}
} else {
F_62 ( & V_8 -> V_151 ,
V_65 + F_63 ( 1 ) ) ;
F_58 ( V_8 , V_147 ) ;
}
V_219:
F_22 ( & V_8 -> V_21 ) ;
}
void F_101 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
F_102 ( V_1 , V_6 -> V_67 ) ;
F_71 ( V_1 ) ;
}
static T_1 F_103 ( struct V_1 * V_2 )
{
T_1 V_187 ;
#if F_104 ( V_220 )
T_1 V_66 ;
struct V_7 * V_8 = & ( V_2 -> V_9 ) ;
struct V_161 * V_162 = & V_2 -> V_163 ;
#endif
struct V_177 * V_178 = & ( V_2 -> V_179 ) ;
struct V_221 * V_222 = & ( V_178 -> V_223 ) ;
#if F_104 ( V_220 )
if ( F_24 ( V_8 , V_166 ) ) {
for ( V_66 = ( V_162 -> V_224 ) ; V_66 > 0 ; V_66 -- ) {
if ( V_162 -> V_225 [ V_66 - 1 ] != NULL )
break;
}
V_187 = V_66 + 1 ;
} else
#endif
{
for ( V_187 = ( V_226 - 1 ) ; V_187 >= V_227 ; V_187 -- ) {
if ( V_222 -> V_228 [ V_187 ] . V_229 == 1 )
break;
}
}
return V_187 ;
}
void F_105 ( struct V_1 * V_1 , struct V_167 * V_168 )
{
T_3 V_230 ;
T_1 V_231 ;
if ( V_168 == NULL )
return;
V_231 = F_103 ( V_1 ) ;
F_106 ( V_1 , V_232 , ( T_1 * ) & V_231 ) ;
V_230 = ( V_168 -> V_187 << 8 ) | 1 ;
F_106 ( V_1 , V_233 , ( T_1 * ) & V_230 ) ;
}
void F_107 ( struct V_1 * V_1 , T_1 * V_4 )
{
struct V_167 * V_168 ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_234 * V_235 = (struct V_234 * ) V_4 ;
struct V_5 * V_15 = & ( V_8 -> V_15 ) ;
struct V_5 * V_209 = NULL ;
if ( F_108 ( V_1 , V_235 -> V_236 ) == false )
return;
#if F_104 ( V_220 )
if ( F_24 ( V_8 , V_166 ) ) {
V_168 = F_75 ( & V_1 -> V_163 , V_235 -> V_236 ) ;
if ( V_168 ) {
F_109 ( V_1 , V_168 ) ;
F_105 ( V_1 , V_168 ) ;
}
return;
}
#endif
V_168 = F_75 ( & V_1 -> V_163 , V_235 -> V_236 ) ;
if ( V_168 != NULL ) {
F_21 ( V_60 , V_132 , ( L_36 ) ) ;
return;
}
V_168 = F_92 ( & V_1 -> V_163 , V_235 -> V_236 ) ;
if ( V_168 == NULL ) {
F_21 ( V_60 , V_132 , ( L_37 ) ) ;
return;
}
V_168 -> V_237 = 0 ;
V_168 -> V_187 = ( T_5 ) V_235 -> V_238 ;
F_52 ( L_22 , V_186 ) ;
F_93 ( V_1 , V_188 , V_168 , true ) ;
F_105 ( V_1 , V_168 ) ;
if ( V_1 -> V_95 . V_189 == V_190 )
V_168 -> V_195 = V_1 -> V_95 . V_96 ;
V_168 -> V_194 = false ;
F_17 ( & V_8 -> V_21 ) ;
if ( ( F_24 ( V_8 , V_74 ) ) ||
( F_24 ( V_8 , V_75 ) ) ) {
if ( V_1 -> V_163 . V_170 == 2 ) {
F_17 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_209 = F_27 ( & V_8 -> V_23 , V_15 -> V_16 . V_81 ) ;
if ( V_209 )
V_209 -> V_63 = true ;
F_22 ( & V_8 -> V_23 . V_21 ) ;
F_66 ( V_1 ) ;
}
}
F_22 ( & V_8 -> V_21 ) ;
F_110 ( V_1 , V_168 ) ;
}
void F_111 ( struct V_1 * V_1 , T_1 * V_4 )
{
int V_187 = - 1 ;
struct V_167 * V_168 ;
struct V_5 * V_111 = NULL ;
struct V_88 * V_153 = NULL ;
T_1 * V_85 = NULL ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
struct V_239 * V_240 = (struct V_239 * ) V_4 ;
struct V_161 * V_162 = & V_1 -> V_163 ;
struct V_5 * V_164 = & ( V_8 -> V_15 ) ;
V_168 = F_75 ( & V_1 -> V_163 , V_240 -> V_236 ) ;
if ( V_168 )
V_187 = V_168 -> V_187 ;
else
V_187 = V_240 -> V_187 ;
F_52 ( L_38 , V_186 , V_187 , V_240 -> V_236 ) ;
if ( V_187 >= 0 ) {
T_3 V_230 ;
V_230 = ( V_187 << 8 ) | 0 ;
F_106 ( V_1 , V_233 , ( T_1 * ) & V_230 ) ;
}
if ( F_24 ( V_8 , V_166 ) )
return;
F_112 ( V_1 ) ;
F_17 ( & V_8 -> V_21 ) ;
if ( F_24 ( V_8 , V_165 ) ) {
if ( V_8 -> V_156 > 0 )
V_8 -> V_156 -- ;
else if ( V_8 -> V_156 == 0 )
V_8 -> V_156 = V_1 -> V_142 . V_241 ;
if ( * ( ( unsigned short * ) ( V_240 -> V_242 ) ) != V_243 )
V_8 -> V_156 = 0 ;
F_113 ( V_1 ) ;
F_68 ( V_1 , 1 ) ;
F_69 ( V_1 ) ;
F_17 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_111 = F_27 ( & V_8 -> V_23 , V_164 -> V_16 . V_81 ) ;
if ( V_111 ) {
V_111 -> V_63 = false ;
F_36 ( V_8 , V_111 ) ;
}
F_22 ( & V_8 -> V_23 . V_21 ) ;
F_114 ( V_1 , V_164 ) ;
}
if ( F_24 ( V_8 , V_74 ) ||
F_24 ( V_8 , V_75 ) ) {
F_17 ( & ( V_162 -> V_169 ) ) ;
F_76 ( V_1 , V_168 ) ;
F_22 ( & V_162 -> V_169 ) ;
if ( V_1 -> V_163 . V_170 == 1 ) {
F_17 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_111 = F_27 ( & V_8 -> V_23 , V_164 -> V_16 . V_81 ) ;
if ( V_111 ) {
V_111 -> V_63 = false ;
F_36 ( V_8 , V_111 ) ;
}
F_22 ( & V_8 -> V_23 . V_21 ) ;
V_153 = & ( V_1 -> V_142 . V_154 ) ;
V_85 = V_1 -> V_142 . V_154 . V_81 ;
memcpy ( V_153 , & V_164 -> V_16 , F_44 ( & V_164 -> V_16 ) ) ;
memcpy ( & V_153 -> V_101 , & V_8 -> V_24 , sizeof( struct V_25 ) ) ;
F_64 ( V_1 ) ;
F_30 ( V_85 ) ;
if ( F_24 ( V_8 , V_75 ) ) {
F_60 ( V_8 , V_74 ) ;
F_58 ( V_8 , V_75 ) ;
}
if ( F_65 ( V_1 ) != V_11 )
F_21 ( V_244 , V_132 , ( L_39 ) ) ;
}
}
F_22 ( & V_8 -> V_21 ) ;
}
void F_115 ( struct V_1 * V_2 , T_1 * V_4 )
{
F_21 ( V_60 , V_132 , ( L_40 ) ) ;
}
void F_116 ( unsigned long V_245 )
{
struct V_1 * V_1 = (struct V_1 * ) V_245 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
int V_246 ;
F_52 ( L_41 , V_186 , F_56 ( V_8 ) ) ;
if ( V_1 -> V_82 || V_1 -> V_83 )
return;
F_17 ( & V_8 -> V_21 ) ;
if ( V_8 -> V_156 > 0 ) {
while ( 1 ) {
V_8 -> V_156 -- ;
if ( V_8 -> V_156 != 0 ) {
F_52 ( L_42 , V_186 ) ;
V_246 = F_117 ( V_1 ) ;
if ( V_11 != V_246 ) {
F_52 ( L_43 , V_186 , V_246 ) ;
continue;
}
break;
} else {
F_52 ( L_44 , V_186 ) ;
F_69 ( V_1 ) ;
break;
}
}
} else {
F_69 ( V_1 ) ;
F_74 ( V_8 ) ;
}
F_22 ( & V_8 -> V_21 ) ;
}
void F_118 ( unsigned long V_245 )
{
struct V_1 * V_1 = (struct V_1 * ) V_245 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
F_52 ( V_247 L_45 , F_119 ( V_1 ) , F_56 ( V_8 ) ) ;
F_17 ( & V_8 -> V_21 ) ;
F_58 ( V_8 , V_148 ) ;
F_22 ( & V_8 -> V_21 ) ;
F_85 ( V_1 , true ) ;
}
static void F_120 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
if ( V_8 -> V_248 > 0 ) {
V_8 -> V_248 -- ;
if ( V_8 -> V_248 == 0 ) {
F_52 ( L_22 , V_186 ) ;
F_121 ( V_2 , NULL , 0 ) ;
V_8 -> V_248 = V_249 ;
}
}
}
void F_122 ( unsigned long V_245 )
{
struct V_1 * V_1 = (struct V_1 * ) V_245 ;
struct V_250 * V_251 = & V_1 -> V_142 ;
if ( ! V_1 )
return;
if ( ! V_1 -> V_252 )
goto exit;
if ( ( V_1 -> V_82 ) || ( V_1 -> V_83 ) )
goto exit;
if ( V_1 -> V_253 )
goto exit;
F_123 ( V_1 ) ;
if ( V_251 -> V_143 == 1 ) {
F_120 ( V_1 ) ;
}
exit:
F_62 ( & V_1 -> V_9 . V_254 ,
V_65 + F_63 ( 2000 ) ) ;
}
static int F_124 ( struct V_7 * V_8
, struct V_5 * * V_255 , struct V_5 * V_256 )
{
int V_257 = false ;
struct V_1 * V_1 = F_19 ( V_8 , struct V_1 , V_9 ) ;
if ( V_8 -> V_258 ) {
if ( memcmp ( V_256 -> V_16 . V_81 , V_8 -> V_259 , V_80 ) )
goto exit;
}
if ( V_8 -> V_24 . V_102 ) {
if ( V_256 -> V_16 . V_101 . V_102 != V_8 -> V_24 . V_102 ||
! memcmp ( V_256 -> V_16 . V_101 . V_101 , V_8 -> V_24 . V_101 , V_8 -> V_24 . V_102 ) == false )
goto exit;
}
if ( F_50 ( V_1 , V_256 ) == false )
goto exit;
if ( V_8 -> V_156 ) {
if ( F_88 ( ( T_2 ) V_256 -> V_64 ) >= V_260 ||
F_38 ( & V_256 -> V_16 , & V_8 -> V_15 . V_16 ) == false )
goto exit;
}
if ( * V_255 == NULL || ( * V_255 ) -> V_16 . V_115 < V_256 -> V_16 . V_115 ) {
* V_255 = V_256 ;
V_257 = true ;
}
if ( V_257 ) {
F_52 ( L_46 ,
V_8 -> V_258 ,
V_8 -> V_24 . V_101 ,
( * V_255 ) -> V_16 . V_101 . V_101 ,
( * V_255 ) -> V_16 . V_81 ,
( int ) ( * V_255 ) -> V_16 . V_115 ) ;
F_52 ( L_47 , V_8 -> V_156 ) ;
}
exit:
return V_257 ;
}
int F_61 ( struct V_7 * V_8 )
{
int V_92 ;
struct V_57 * V_78 ;
struct V_1 * V_1 ;
struct V_55 * V_30 = & ( V_8 -> V_23 ) ;
struct V_5 * V_6 = NULL ;
struct V_5 * V_255 = NULL ;
T_1 V_261 = false ;
F_17 ( & ( V_8 -> V_23 . V_21 ) ) ;
V_78 = F_26 ( V_30 ) ;
V_1 = (struct V_1 * ) V_8 -> V_12 ;
V_8 -> V_13 = V_78 -> V_59 ;
while ( V_78 != V_8 -> V_13 ) {
V_6 = F_19 ( V_8 -> V_13 , struct V_5 , V_29 ) ;
if ( V_6 == NULL ) {
F_21 ( V_60 , V_132 , ( L_48 , V_186 ) ) ;
V_92 = V_27 ;
goto exit;
}
V_8 -> V_13 = V_8 -> V_13 -> V_59 ;
F_124 ( V_8 , & V_255 , V_6 ) ;
}
if ( V_255 == NULL ) {
F_52 ( L_49 , V_186 ) ;
V_92 = V_27 ;
goto exit;
} else {
F_52 ( L_50 , V_186 ,
V_255 -> V_16 . V_101 . V_101 , V_255 -> V_16 . V_81 ,
V_255 -> V_16 . V_262 . V_263 ) ;
}
if ( F_24 ( V_8 , V_84 ) == true ) {
F_52 ( L_51 , V_186 ) ;
F_125 ( V_1 , 0 , true ) ;
F_69 ( V_1 ) ;
F_68 ( V_1 , 0 ) ;
}
F_48 ( V_1 , V_264 , & ( V_261 ) ) ;
if ( V_261 ) {
T_1 V_265 ;
F_48 ( V_1 , V_130 , & ( V_265 ) ) ;
F_52 ( L_52 ,
( 2 == V_255 -> V_16 . V_117 . V_131 ) ? L_53 : L_54 ,
( 2 == V_265 ) ? L_53 : L_54
) ;
}
V_92 = F_126 ( V_1 , V_255 ) ;
exit:
F_22 ( & V_8 -> V_23 . V_21 ) ;
return V_92 ;
}
int F_127 ( struct V_1 * V_1 , struct V_93 * V_94 )
{
struct V_266 * V_267 ;
struct V_268 * V_269 ;
struct V_270 * V_271 = & ( V_1 -> V_272 ) ;
int V_10 = V_11 ;
V_267 = F_128 ( sizeof( struct V_266 ) , V_273 ) ;
if ( V_267 == NULL ) {
V_10 = V_27 ;
goto exit;
}
V_269 = F_128 ( sizeof( struct V_268 ) , V_273 ) ;
if ( V_269 == NULL ) {
F_11 ( V_267 ) ;
V_10 = V_27 ;
goto exit;
}
memset ( V_269 , 0 , sizeof( struct V_268 ) ) ;
V_269 -> V_274 = ( unsigned char ) V_94 -> V_189 ;
V_267 -> V_275 = V_276 ;
V_267 -> V_277 = ( unsigned char * ) V_269 ;
V_267 -> V_278 = ( sizeof( struct V_268 ) ) ;
V_267 -> V_279 = NULL ;
V_267 -> V_280 = 0 ;
F_6 ( & V_267 -> V_29 ) ;
F_21 ( V_60 , V_132 ,
( L_55 ,
V_94 -> V_189 ) ) ;
V_10 = F_129 ( V_271 , V_267 ) ;
exit:
return V_10 ;
}
int F_130 ( struct V_1 * V_1 , struct V_93 * V_94 , int V_281 , T_1 V_282 )
{
T_1 V_283 ;
struct V_266 * V_267 ;
struct V_284 * V_285 ;
struct V_270 * V_271 = & ( V_1 -> V_272 ) ;
struct V_7 * V_8 = & ( V_1 -> V_9 ) ;
int V_10 = V_11 ;
V_267 = F_128 ( sizeof( struct V_266 ) , V_273 ) ;
if ( V_267 == NULL )
return V_27 ;
V_285 = F_128 ( sizeof( struct V_284 ) , V_273 ) ;
if ( V_285 == NULL ) {
V_10 = V_27 ;
goto V_286;
}
memset ( V_285 , 0 , sizeof( struct V_284 ) ) ;
if ( V_94 -> V_189 == V_190 ) {
V_285 -> V_287 = ( unsigned char ) V_94 -> V_288 ;
F_21 ( V_60 , V_132 ,
( L_56 ,
V_285 -> V_287 ) ) ;
} else {
V_285 -> V_287 = ( T_1 ) V_94 -> V_96 ;
F_21 ( V_60 , V_132 ,
( L_57 ,
V_285 -> V_287 ) ) ;
}
V_285 -> V_281 = ( T_1 ) V_281 ;
V_285 -> V_282 = V_282 ;
V_8 -> V_171 |= F_131 ( V_285 -> V_281 ) ;
F_52 ( L_58 ,
V_285 -> V_287 , V_285 -> V_281 , V_8 -> V_171 ) ;
F_21 ( V_60 , V_132 ,
( L_59 ,
V_285 -> V_287 , V_281 ) ) ;
switch ( V_285 -> V_287 ) {
case V_289 :
V_283 = 5 ;
memcpy ( & ( V_285 -> V_290 [ 0 ] ) , & ( V_94 -> V_291 [ V_281 ] . V_292 [ 0 ] ) , V_283 ) ;
break;
case V_293 :
V_283 = 13 ;
memcpy ( & ( V_285 -> V_290 [ 0 ] ) , & ( V_94 -> V_291 [ V_281 ] . V_292 [ 0 ] ) , V_283 ) ;
break;
case V_294 :
V_283 = 16 ;
memcpy ( & V_285 -> V_290 , & V_94 -> V_295 [ V_281 ] , V_283 ) ;
V_285 -> V_296 = 1 ;
break;
case V_297 :
V_283 = 16 ;
memcpy ( & V_285 -> V_290 , & V_94 -> V_295 [ V_281 ] , V_283 ) ;
V_285 -> V_296 = 1 ;
break;
default:
F_21 ( V_60 , V_132 ,
( L_60 ,
V_94 -> V_96 ) ) ;
V_10 = V_27 ;
goto V_298;
}
V_267 -> V_275 = V_299 ;
V_267 -> V_277 = ( T_1 * ) V_285 ;
V_267 -> V_278 = ( sizeof( struct V_284 ) ) ;
V_267 -> V_279 = NULL ;
V_267 -> V_280 = 0 ;
F_6 ( & V_267 -> V_29 ) ;
V_10 = F_129 ( V_271 , V_267 ) ;
return V_10 ;
V_298:
F_11 ( V_285 ) ;
V_286:
F_11 ( V_267 ) ;
return V_10 ;
}
int F_132 ( struct V_1 * V_1 , T_1 * V_300 , T_1 * V_301 , T_5 V_302 , T_5 V_303 )
{
unsigned int V_304 = 0 ;
unsigned int V_3 , V_305 ;
V_3 = 12 ;
while ( V_3 < V_302 ) {
V_304 = V_303 ;
if ( V_300 [ V_3 ] == 0xDD && V_300 [ V_3 + 2 ] == 0x00 && V_300 [ V_3 + 3 ] == 0x50 && V_300 [ V_3 + 4 ] == 0xF2 && V_300 [ V_3 + 5 ] == 0x02 && V_3 + 5 < V_302 ) {
for ( V_305 = V_3 ; V_305 < V_3 + 9 ; V_305 ++ ) {
V_301 [ V_304 ] = V_300 [ V_305 ] ;
V_304 ++ ;
}
V_301 [ V_303 + 1 ] = 0x07 ;
V_301 [ V_303 + 6 ] = 0x00 ;
V_301 [ V_303 + 8 ] = 0x00 ;
break;
}
V_3 += ( V_300 [ V_3 + 1 ] + 2 ) ;
}
return V_304 ;
}
static int F_133 ( struct V_1 * V_306 , T_1 * V_307 )
{
struct V_93 * V_94 = & V_306 -> V_95 ;
int V_3 = 0 ;
do {
if ( ( V_94 -> V_308 [ V_3 ] . V_309 ) &&
( ! memcmp ( V_94 -> V_308 [ V_3 ] . V_310 , V_307 , V_80 ) ) ) {
break;
} else {
V_3 ++ ;
}
} while ( V_3 < V_311 );
if ( V_3 == V_311 )
V_3 = - 1 ;
return V_3 ;
}
static int F_134 ( struct V_1 * V_306 , int V_312 , T_1 * V_87 , T_5 V_313 )
{
struct V_93 * V_94 = & V_306 -> V_95 ;
if ( V_87 [ 13 ] <= 20 ) {
V_87 [ V_313 ] = 1 ;
V_313 ++ ;
V_87 [ V_313 ] = 0 ;
V_313 ++ ;
memcpy ( & V_87 [ V_313 ] , & V_94 -> V_308 [ V_312 ] . V_314 , 16 ) ;
V_313 += 16 ;
V_87 [ 13 ] += 18 ;
}
return V_313 ;
}
int F_135 ( struct V_1 * V_1 , T_1 * V_300 , T_1 * V_301 , T_5 V_302 )
{
T_1 V_315 ;
T_5 V_304 ;
int V_312 ;
struct V_7 * V_8 = & V_1 -> V_9 ;
struct V_93 * V_94 = & V_1 -> V_95 ;
T_5 V_316 = V_94 -> V_317 ;
T_5 V_318 = V_94 -> V_139 ;
F_21 ( V_60 , V_159 ,
( L_61 ,
V_316 , V_318 ) ) ;
memcpy ( V_301 , V_300 , 12 ) ;
V_304 = 12 ;
if ( ( V_316 == V_319 ) ||
( V_316 == V_320 ) )
V_315 = V_321 ;
if ( ( V_316 == V_322 ) ||
( V_316 == V_323 ) )
V_315 = V_324 ;
if ( F_24 ( V_8 , V_140 ) ) {
memcpy ( V_301 + V_304 , V_94 -> V_325 , V_94 -> V_203 ) ;
V_304 += V_94 -> V_203 ;
} else if ( ( V_315 == V_321 ) || ( V_315 == V_324 ) ) {
memcpy ( & V_301 [ V_304 ] , & V_94 -> V_326 [ 0 ] , V_94 -> V_326 [ 1 ] + 2 ) ;
V_304 += V_94 -> V_326 [ 1 ] + 2 ;
F_136 ( V_1 , V_315 , V_94 -> V_326 ) ;
}
V_312 = F_133 ( V_1 , V_8 -> V_259 ) ;
if ( V_312 < 0 ) {
return V_304 ;
} else {
if ( V_315 == V_324 )
V_304 = F_134 ( V_1 , V_312 , V_301 , V_304 ) ;
}
return V_304 ;
}
void F_137 ( struct V_1 * V_1 )
{
struct V_250 * V_251 = & V_1 -> V_142 ;
struct V_327 * V_328 = & V_1 -> V_329 ;
struct V_88 * V_153 = & V_251 -> V_154 ;
T_1 * V_330 = F_138 ( V_328 ) ;
memcpy ( V_153 -> V_81 , V_330 , V_80 ) ;
memcpy ( & V_153 -> V_101 , & V_251 -> V_331 , sizeof( struct V_25 ) ) ;
V_153 -> V_262 . V_133 = sizeof( struct V_332 ) ;
V_153 -> V_262 . V_333 = 100 ;
V_153 -> V_262 . V_334 . V_133 = 0 ;
V_153 -> V_262 . V_334 . V_335 = 0 ;
V_153 -> V_262 . V_334 . V_336 = 0 ;
V_153 -> V_262 . V_334 . V_337 = 0 ;
}
void F_64 ( struct V_1 * V_1 )
{
int V_338 = 0 ;
struct V_250 * V_251 = & V_1 -> V_142 ;
struct V_88 * V_153 = & V_251 -> V_154 ;
struct V_93 * V_94 = & V_1 -> V_95 ;
struct V_5 * V_15 = & V_1 -> V_9 . V_15 ;
V_153 -> V_98 = ( V_94 -> V_96 > 0 ? 1 : 0 ) ;
V_153 -> V_115 = 0 ;
switch ( V_251 -> V_339 ) {
case V_340 :
V_153 -> V_341 = ( V_342 ) ;
break;
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
V_153 -> V_341 = ( V_348 ) ;
break;
case V_349 :
case V_350 :
V_153 -> V_341 = ( V_351 ) ;
break;
case V_352 :
if ( V_251 -> V_353 > 14 )
V_153 -> V_341 = ( V_351 ) ;
else
V_153 -> V_341 = ( V_348 ) ;
break;
default:
break;
}
V_153 -> V_262 . V_263 = ( V_251 -> V_353 ) ;
F_21 ( V_60 , V_61 ,
( L_62 ,
V_251 -> V_353 , V_153 -> V_262 . V_263 ) ) ;
if ( V_15 -> V_16 . V_17 == V_213 )
V_153 -> V_262 . V_354 = ( 0 ) ;
V_153 -> V_17 = ( V_15 -> V_16 . V_17 ) ;
V_338 = F_139 ( V_251 ) ;
V_153 -> V_127 = V_338 ;
V_153 -> V_133 = F_44 ( (struct V_88 * ) V_153 ) ;
}
void F_99 ( struct V_1 * V_1 )
{
}
void F_140 ( struct V_1 * V_2 )
{
T_1 V_355 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_356 * V_357 = & V_8 -> V_358 ;
V_8 -> V_359 = 0 ;
V_8 -> V_360 = 0 ;
V_357 -> V_361 = false ;
if ( V_357 -> V_362 ) {
if ( V_2 -> V_142 . V_143 == 1 )
V_355 = 1 ;
else
V_355 = 0 ;
F_106 ( V_2 , V_363 , ( T_1 * ) ( & V_355 ) ) ;
} else {
V_355 = 1 ;
F_106 ( V_2 , V_363 , ( T_1 * ) ( & V_355 ) ) ;
}
}
unsigned int F_141 ( struct V_1 * V_2 , T_1 * V_300 , T_1 * V_301 , T_5 V_302 , T_5 * V_364 )
{
T_2 V_365 , V_366 ;
enum V_367 V_368 ;
unsigned char * V_369 ;
struct V_370 V_371 ;
unsigned char V_372 [] = { 0x00 , 0x50 , 0xf2 , 0x02 , 0x00 , 0x01 , 0x00 } ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_373 * V_374 = & V_8 -> V_375 ;
struct V_356 * V_357 = & V_8 -> V_358 ;
T_2 V_376 , V_377 ;
V_357 -> V_362 = false ;
V_369 = F_142 ( V_300 + 12 , V_378 , & V_365 , V_302 - 12 ) ;
if ( V_369 && V_365 > 0 ) {
if ( V_374 -> V_237 == 0 ) {
V_366 = * V_364 ;
F_143 ( V_301 + V_366 , V_379 ,
V_380 , V_372 , V_364 ) ;
V_374 -> V_237 = 1 ;
}
V_366 = * V_364 ;
memset ( & V_371 , 0 , sizeof( struct V_370 ) ) ;
V_371 . V_381 = V_382 |
V_383 |
V_384 |
V_385 |
V_386 ;
F_48 ( V_2 , V_387 , & V_376 ) ;
F_48 ( V_2 , V_388 , & V_377 ) ;
F_48 ( V_2 , V_389 , & V_368 ) ;
V_371 . V_390 = ( V_368 & 0x03 ) ;
if ( V_2 -> V_95 . V_96 == V_297 )
V_371 . V_390 |= ( V_391 & ( 0x07 << 2 ) ) ;
else
V_371 . V_390 |= ( V_391 & 0x00 ) ;
F_143 ( V_301 + V_366 , V_378 ,
sizeof( struct V_370 ) , ( unsigned char * ) & V_371 , V_364 ) ;
V_357 -> V_362 = true ;
V_369 = F_142 ( V_300 + 12 , V_392 , & V_365 , V_302 - 12 ) ;
if ( V_369 && ( V_365 == sizeof( struct V_393 ) ) ) {
V_366 = * V_364 ;
F_143 ( V_301 + V_366 , V_392 , V_365 , V_369 + 2 , V_364 ) ;
}
}
return V_357 -> V_362 ;
}
void F_97 ( struct V_1 * V_2 , T_1 * V_394 , T_5 V_313 )
{
T_1 * V_369 , V_395 ;
int V_145 ;
struct V_370 * V_396 ;
struct V_7 * V_8 = & V_2 -> V_9 ;
struct V_356 * V_357 = & V_8 -> V_358 ;
struct V_250 * V_251 = & V_2 -> V_142 ;
struct V_177 * V_178 = & V_2 -> V_179 ;
struct V_221 * V_222 = & ( V_178 -> V_223 ) ;
if ( ! V_357 -> V_362 )
return;
if ( ( ! V_222 -> V_397 ) || ( ! V_222 -> V_398 ) )
return;
F_52 ( L_63 ) ;
if ( ( ! V_357 -> V_361 ) && ( V_251 -> V_361 == 1 ) ) {
if ( V_251 -> V_143 == 1 )
V_357 -> V_361 = false ;
else
V_357 -> V_361 = true ;
} else if ( V_251 -> V_361 == 2 ) {
V_357 -> V_361 = true ;
}
V_145 = 0 ;
V_369 = F_142 ( V_394 + sizeof( struct V_126 ) , V_378 , & V_145 , V_313 - sizeof( struct V_126 ) ) ;
if ( V_369 && V_145 > 0 ) {
V_396 = (struct V_370 * ) ( V_369 + 2 ) ;
V_395 = V_396 -> V_390 & V_399 ;
V_395 = 1 << ( V_395 + 3 ) ;
V_357 -> V_400 = V_395 ;
}
V_145 = 0 ;
V_369 = F_142 ( V_394 + sizeof( struct V_126 ) , V_392 , & V_145 , V_313 - sizeof( struct V_126 ) ) ;
if ( ( V_251 -> V_401 ) &&
( F_33 ( V_222 -> V_402 . V_403 . V_404 . V_405 ) & F_131 ( 1 ) ) &&
( V_222 -> V_406 . V_407 [ 0 ] & F_131 ( 2 ) ) ) {
int V_3 ;
T_1 V_408 ;
V_2 -> V_409 . V_410 ( V_2 , V_411 , ( T_1 * ) ( & V_408 ) ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( ( V_408 == V_412 ) || ( V_408 == V_413 ) )
V_222 -> V_402 . V_403 . V_404 . V_414 [ V_3 ] &= V_415 [ V_3 ] ;
else
V_222 -> V_402 . V_403 . V_404 . V_414 [ V_3 ] &= V_416 [ V_3 ] ;
}
V_178 -> V_417 = V_418 ;
switch ( ( V_222 -> V_406 . V_407 [ 0 ] & 0x3 ) ) {
case V_419 :
V_178 -> V_420 = V_421 ;
break;
case V_422 :
V_178 -> V_420 = V_423 ;
break;
default:
V_178 -> V_420 = V_424 ;
break;
}
}
V_222 -> V_425 = ( F_33 ( V_222 -> V_402 . V_403 . V_404 . V_405 ) & 0x0C ) >> 2 ;
if ( V_222 -> V_425 == V_426 )
F_52 ( L_64 , V_186 ) ;
V_222 -> V_427 = V_222 -> V_406 . V_407 [ 1 ] & 0x3 ;
}
void F_144 ( struct V_1 * V_2 , struct V_428 * V_429 )
{
T_1 V_430 ;
int V_431 ;
struct V_167 * V_168 = NULL ;
struct V_356 * V_357 ;
struct V_432 * V_433 = & V_429 -> V_434 ;
T_6 V_435 = F_145 ( V_433 -> V_436 ) ;
if ( V_435 || ( V_2 -> V_9 . V_437 . V_438 < 100 ) )
return;
V_431 = V_433 -> V_431 ;
if ( V_433 -> V_168 )
V_168 = V_433 -> V_168 ;
else
V_168 = F_75 ( & V_2 -> V_163 , V_433 -> V_436 ) ;
if ( V_168 == NULL )
return;
V_357 = & V_168 -> V_358 ;
if ( ( V_357 -> V_362 ) && ( V_357 -> V_361 ) ) {
V_430 = ( V_357 -> V_439 >> V_431 ) & 0x1 ;
V_430 |= ( V_357 -> V_440 >> V_431 ) & 0x1 ;
if ( 0 == V_430 ) {
F_52 ( L_65 , V_431 ) ;
V_168 -> V_358 . V_440 |= F_131 ( ( T_1 ) V_431 ) ;
F_146 ( V_2 , ( T_1 ) V_431 , V_433 -> V_436 ) ;
}
}
}
void F_147 ( struct V_1 * V_2 , struct V_5 * V_164 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
F_17 ( & V_8 -> V_21 ) ;
F_114 ( V_2 , V_164 ) ;
F_22 ( & V_8 -> V_21 ) ;
}
void F_114 ( struct V_1 * V_2 , struct V_5 * V_164 )
{
struct V_7 * V_8 = & V_2 -> V_9 ;
int V_246 ;
struct V_5 * V_6 ;
if ( V_164 != NULL )
V_6 = V_164 ;
else
V_6 = & V_8 -> V_15 ;
if ( 0 < V_8 -> V_156 ) {
F_52 ( L_66 ,
V_6 -> V_16 . V_101 . V_101 , V_6 -> V_16 . V_81 ,
V_6 -> V_16 . V_101 . V_102 ) ;
memcpy ( & V_8 -> V_24 , & V_6 -> V_16 . V_101 , sizeof( struct V_25 ) ) ;
V_8 -> V_258 = false ;
while ( 1 ) {
V_246 = F_117 ( V_2 ) ;
if ( V_11 == V_246 ) {
break;
} else {
F_52 ( L_67 , V_246 ) ;
V_8 -> V_156 -- ;
if ( 0 < V_8 -> V_156 ) {
continue;
} else {
F_52 ( L_68 , V_186 , __LINE__ ) ;
F_69 ( V_2 ) ;
break;
}
}
}
}
}
