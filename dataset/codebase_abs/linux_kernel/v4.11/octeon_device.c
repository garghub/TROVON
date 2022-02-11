static void F_1 ( int V_1 , int V_2 )
{
if ( V_2 < 0 || V_2 > ( V_3 - 1 ) )
V_2 = V_4 ;
V_5 [ V_1 ] . V_2 = V_2 ;
}
void F_2 ( int V_2 )
{
int V_6 ;
memset ( V_7 , 0 , ( sizeof( void * ) * V_8 ) ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
F_1 ( V_6 , V_2 ) ;
}
static void * F_3 ( struct V_7 * V_9 ,
T_1 V_10 )
{
T_2 V_1 = V_9 -> V_11 ;
void * V_12 = NULL ;
switch ( V_5 [ V_1 ] . V_2 ) {
case V_4 :
if ( V_9 -> V_13 == V_14 ) {
V_12 = & V_15 ;
} else if ( ( V_9 -> V_13 == V_16 ) &&
( V_10 == V_17 ) ) {
V_12 = & V_18 ;
} else if ( ( V_9 -> V_13 == V_16 ) &&
( V_10 == V_19 ) ) {
V_12 = & V_20 ;
} else if ( V_9 -> V_13 == V_21 ) {
V_12 = & V_22 ;
} else if ( V_9 -> V_13 == V_23 ) {
V_12 = & V_22 ;
}
break;
default:
break;
}
return V_12 ;
}
static int F_4 ( struct V_7 * V_9 , void * V_24 )
{
switch ( V_9 -> V_13 ) {
case V_14 :
case V_16 :
return F_5 ( V_9 , V_24 ) ;
case V_21 :
case V_23 :
return 0 ;
default:
break;
}
return 1 ;
}
void * F_6 ( struct V_7 * V_9 , T_1 V_10 )
{
void * V_24 = NULL ;
V_24 = F_3 ( V_9 , V_10 ) ;
if ( ! V_24 )
return NULL ;
if ( F_4 ( V_9 , V_24 ) ) {
F_7 ( & V_9 -> V_25 -> V_26 , L_1 ) ;
return NULL ;
}
return V_24 ;
}
char * F_8 ( T_3 * V_27 )
{
T_4 V_28 = ( T_4 ) F_9 ( V_27 ) ;
if ( V_28 > V_29 || V_28 < 0 )
return V_30 [ V_31 ] ;
return V_30 [ V_28 ] ;
}
static char * F_10 ( T_2 V_32 )
{
if ( V_32 <= V_33 )
return V_34 [ V_32 - V_35 ] ;
return V_34 [ V_36 - V_35 ] ;
}
void F_11 ( struct V_7 * V_9 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < F_12 ( V_9 ) ; V_6 ++ ) {
if ( V_9 -> V_37 . V_38 & F_13 ( V_6 ) )
F_14 ( V_9 -> V_39 [ V_6 ] ) ;
}
for ( V_6 = 0 ; V_6 < F_15 ( V_9 ) ; V_6 ++ ) {
if ( V_9 -> V_37 . V_40 & F_13 ( V_6 ) )
F_14 ( V_9 -> V_41 [ V_6 ] ) ;
}
V_6 = V_9 -> V_11 ;
F_14 ( V_9 ) ;
V_7 [ V_6 ] = NULL ;
V_42 -- ;
}
static struct V_7 * F_16 ( T_2 V_43 ,
T_2 V_44 )
{
struct V_7 * V_9 ;
T_5 * V_45 = NULL ;
T_2 V_46 = 0 , V_47 = 0 , V_48 ;
switch ( V_43 ) {
case V_16 :
case V_14 :
V_47 = sizeof( struct V_49 ) ;
break;
case V_21 :
V_47 = sizeof( struct V_50 ) ;
break;
case V_23 :
V_47 = sizeof( struct V_51 ) ;
break;
default:
F_17 ( L_2 ,
V_52 ,
V_43 ) ;
return NULL ;
}
if ( V_47 & 0x7 )
V_47 += ( 8 - ( V_47 & 0x7 ) ) ;
V_46 = sizeof( struct V_7 ) ;
if ( V_46 & 0x7 )
V_46 += ( 8 - ( V_46 & 0x7 ) ) ;
if ( V_44 & 0x7 )
V_44 += ( 8 - ( V_44 & 0x7 ) ) ;
V_48 = V_46 + V_44 + V_47 +
( sizeof( struct V_53 ) * V_54 ) ;
V_45 = F_18 ( V_48 ) ;
if ( ! V_45 )
return NULL ;
memset ( V_45 , 0 , V_48 ) ;
V_9 = (struct V_7 * ) V_45 ;
V_9 -> V_55 = ( void * ) ( V_45 + V_46 ) ;
V_9 -> V_56 = ( void * ) ( V_45 + V_46 + V_44 ) ;
V_9 -> V_57 . V_58 = (struct V_53 * )
( V_45 + V_46 + V_44 + V_47 ) ;
return V_9 ;
}
struct V_7 * F_19 ( T_2 V_43 ,
T_2 V_44 )
{
T_2 V_59 = 0 ;
struct V_7 * V_9 = NULL ;
for ( V_59 = 0 ; V_59 < V_8 ; V_59 ++ )
if ( ! V_7 [ V_59 ] )
break;
if ( V_59 == V_8 )
return NULL ;
V_9 = F_16 ( V_43 , V_44 ) ;
if ( ! V_9 )
return NULL ;
F_20 ( & V_9 -> V_60 ) ;
F_20 ( & V_9 -> V_61 ) ;
V_42 ++ ;
V_7 [ V_59 ] = V_9 ;
V_9 -> V_11 = V_59 ;
snprintf ( V_9 -> V_62 , sizeof( V_9 -> V_62 ) ,
L_3 , ( V_9 -> V_11 ) ) ;
return V_9 ;
}
int
F_21 ( struct V_7 * V_9 )
{
int V_6 , V_63 = 0 ;
struct V_64 * V_65 ;
int V_66 ;
int V_48 ;
if ( F_22 ( V_9 ) )
V_63 = V_9 -> V_67 . V_68 ;
else if ( F_23 ( V_9 ) )
V_63 = V_9 -> V_67 . V_69 ;
V_48 = sizeof( struct V_64 ) * V_63 ;
V_9 -> V_65 = F_18 ( V_48 ) ;
if ( ! V_9 -> V_65 )
return 1 ;
memset ( V_9 -> V_65 , 0 , V_48 ) ;
for ( V_6 = 0 ; V_6 < V_63 ; V_6 ++ ) {
V_65 = & V_9 -> V_65 [ V_6 ] ;
V_65 -> V_70 = V_9 ;
V_65 -> V_71 = V_6 ;
V_65 -> V_72 = V_6 ;
V_65 -> V_73 = V_9 -> V_73 [ V_6 ] ;
V_66 = V_6 % F_24 () ;
F_25 ( V_66 , & V_65 -> V_74 ) ;
if ( V_9 -> V_13 == V_21 )
V_65 -> V_75 = V_6 + V_9 -> V_67 . V_76 ;
else
V_65 -> V_75 = V_6 ;
}
return 0 ;
}
void
F_26 ( struct V_7 * V_9 )
{
F_14 ( V_9 -> V_65 ) ;
}
int F_27 ( struct V_7 * V_9 )
{
T_2 V_77 = 0 ;
T_2 V_78 = 0 ;
union V_79 V_80 ;
int V_81 = F_28 ( V_78 % F_24 () ) ;
if ( F_29 ( V_9 ) )
V_77 =
F_30 ( F_31 ( V_9 , V_82 ) ) ;
else if ( F_22 ( V_9 ) )
V_77 = F_30 ( F_31 ( V_9 , V_83 ) ) ;
else if ( F_23 ( V_9 ) )
V_77 = F_30 ( F_31 ( V_9 , V_84 ) ) ;
V_9 -> V_85 = 0 ;
V_9 -> V_41 [ 0 ] = F_32 ( sizeof( * V_9 -> V_41 [ 0 ] ) ,
V_81 ) ;
if ( ! V_9 -> V_41 [ 0 ] )
V_9 -> V_41 [ 0 ] =
F_18 ( sizeof( struct V_86 ) ) ;
if ( ! V_9 -> V_41 [ 0 ] )
return 1 ;
memset ( V_9 -> V_41 [ 0 ] , 0 , sizeof( struct V_86 ) ) ;
V_9 -> V_41 [ 0 ] -> V_87 = 0 ;
V_9 -> V_41 [ 0 ] -> V_88 = ( void * ) ( V_89 ) 0 ;
V_9 -> V_41 [ 0 ] -> V_90 = 0 ;
V_80 . V_91 = 0 ;
V_80 . V_92 . V_93 = V_78 ;
V_80 . V_92 . V_94 = V_9 -> V_95 . V_94 ;
V_80 . V_92 . V_96 = 0 ;
V_80 . V_92 . V_97 = 0 ;
if ( F_33 ( V_9 , V_80 , V_77 ) ) {
F_14 ( V_9 -> V_41 [ 0 ] ) ;
V_9 -> V_41 [ 0 ] = NULL ;
return 1 ;
}
V_9 -> V_85 ++ ;
return 0 ;
}
int F_34 ( struct V_7 * V_9 )
{
T_2 V_77 = 0 ;
T_2 V_98 = 0 ;
T_2 V_99 = 0 ;
int V_81 = F_28 ( V_99 % F_24 () ) ;
if ( F_29 ( V_9 ) ) {
V_77 =
F_35 ( F_31 ( V_9 , V_82 ) ) ;
V_98 =
F_36 ( F_31 ( V_9 , V_82 ) ) ;
} else if ( F_22 ( V_9 ) ) {
V_77 = F_35 ( F_31 ( V_9 , V_83 ) ) ;
V_98 = F_36 ( F_31 ( V_9 , V_83 ) ) ;
} else if ( F_23 ( V_9 ) ) {
V_77 = F_35 ( F_31 ( V_9 , V_84 ) ) ;
V_98 = F_36 ( F_31 ( V_9 , V_84 ) ) ;
}
V_9 -> V_100 = 0 ;
V_9 -> V_39 [ 0 ] = F_32 ( sizeof( * V_9 -> V_39 [ 0 ] ) , V_81 ) ;
if ( ! V_9 -> V_39 [ 0 ] )
V_9 -> V_39 [ 0 ] = F_18 ( sizeof( * V_9 -> V_39 [ 0 ] ) ) ;
if ( ! V_9 -> V_39 [ 0 ] )
return 1 ;
if ( F_37 ( V_9 , V_99 , V_77 , V_98 , NULL ) ) {
F_14 ( V_9 -> V_39 [ V_99 ] ) ;
V_9 -> V_39 [ V_99 ] = NULL ;
return 1 ;
}
V_9 -> V_100 ++ ;
return 0 ;
}
int F_38 ( struct V_7 * V_9 )
{
int V_101 = V_102 ;
if ( F_29 ( V_9 ) ) {
F_39 ( V_9 , V_103 , 0 ) ;
F_39 ( V_9 , V_104 , 0 ) ;
} else if ( V_9 -> V_13 == V_23 ) {
T_2 V_93 ;
for ( V_93 = 0 ; V_93 < V_9 -> V_67 . V_69 ; V_93 ++ ) {
V_91 V_105 = F_40 (
V_9 , F_41 ( V_93 ) ) ;
while ( ( V_105 & V_106 ) &&
! ( V_105 & V_107 ) &&
V_101 ) {
V_105 = F_40 (
V_9 , F_42 ( V_93 ) ) ;
V_101 -- ;
}
if ( ! V_101 ) {
F_7 ( & V_9 -> V_25 -> V_26 ,
L_4 ,
V_93 ) ;
return - 1 ;
}
V_105 = V_105 & ~ V_106 ;
F_43 ( V_9 ,
F_42 ( V_93 ) ,
V_105 ) ;
V_105 = F_40 (
V_9 , F_42 ( V_93 ) ) ;
if ( V_105 & V_106 ) {
F_7 ( & V_9 -> V_25 -> V_26 ,
L_5 , V_93 ) ;
return - 1 ;
}
}
}
return 0 ;
}
void F_44 ( struct V_7 * V_9 ,
T_2 V_93 ,
T_2 V_108 )
{
T_2 V_105 = 0 ;
if ( F_29 ( V_9 ) ) {
V_105 = F_45 ( V_9 , V_104 ) ;
if ( V_108 )
V_105 = V_105 | ( 1 << V_93 ) ;
else
V_105 = V_105 & ( ~ ( 1 << V_93 ) ) ;
F_39 ( V_9 , V_104 , V_105 ) ;
}
}
int F_46 ( struct V_7 * V_9 )
{
T_2 V_6 ;
V_9 -> V_57 . V_109 = 0 ;
for ( V_6 = 0 ; V_6 < V_54 ; V_6 ++ ) {
V_9 -> V_57 . V_58 [ V_6 ] . V_110 = 0 ;
F_47 ( & V_9 -> V_57 . V_58 [ V_6 ] . V_111 ) ;
}
for ( V_6 = 0 ; V_6 <= V_112 ; V_6 ++ )
F_48 ( V_9 , V_6 , NULL ) ;
F_20 ( & V_9 -> V_57 . V_113 ) ;
return 0 ;
}
void F_49 ( struct V_7 * V_9 )
{
T_2 V_6 ;
struct V_114 V_115 , * V_116 , * V_117 ;
F_47 ( & V_115 ) ;
F_50 ( & V_9 -> V_57 . V_113 ) ;
for ( V_6 = 0 ; V_6 < V_54 ; V_6 ++ ) {
struct V_114 * V_57 ;
V_57 = & V_9 -> V_57 . V_58 [ V_6 ] . V_111 ;
while ( V_57 -> V_118 != V_57 ) {
V_116 = V_57 -> V_118 ;
F_51 ( V_116 ) ;
F_52 ( V_116 , & V_115 ) ;
}
V_9 -> V_57 . V_58 [ V_6 ] . V_110 = 0 ;
}
V_9 -> V_57 . V_109 = 0 ;
F_53 ( & V_9 -> V_57 . V_113 ) ;
F_54 (temp, tmp2, &freelist) {
F_51 ( V_116 ) ;
F_14 ( V_116 ) ;
}
}
T_6
F_55 ( struct V_7 * V_119 , T_1 V_110 ,
T_1 V_120 )
{
T_2 V_121 ;
struct V_114 * V_57 ;
T_6 V_122 = NULL ;
T_1 V_123 = F_56 ( V_110 , V_120 ) ;
V_121 = V_123 & V_124 ;
F_50 ( & V_119 -> V_57 . V_113 ) ;
if ( V_119 -> V_57 . V_109 == 0 ) {
F_53 ( & V_119 -> V_57 . V_113 ) ;
return NULL ;
}
if ( ! ( V_119 -> V_57 . V_58 [ V_121 ] . V_110 ) ) {
F_53 ( & V_119 -> V_57 . V_113 ) ;
return NULL ;
}
if ( V_119 -> V_57 . V_58 [ V_121 ] . V_110 == V_123 ) {
V_122 = V_119 -> V_57 . V_58 [ V_121 ] . V_125 ;
} else {
F_57 (dispatch,
&octeon_dev->dispatch.dlist[idx].list) {
if ( ( (struct V_53 * ) V_57 ) -> V_110 ==
V_123 ) {
V_122 = ( (struct V_53 * )
V_57 ) -> V_125 ;
break;
}
}
}
F_53 ( & V_119 -> V_57 . V_113 ) ;
return V_122 ;
}
int
F_58 ( struct V_7 * V_9 ,
T_1 V_110 ,
T_1 V_120 ,
T_6 V_122 , void * V_126 )
{
T_2 V_121 ;
T_6 V_127 ;
T_1 V_123 = F_56 ( V_110 , V_120 ) ;
V_121 = V_123 & V_124 ;
F_50 ( & V_9 -> V_57 . V_113 ) ;
if ( V_9 -> V_57 . V_58 [ V_121 ] . V_110 == 0 ) {
V_9 -> V_57 . V_58 [ V_121 ] . V_110 = V_123 ;
V_9 -> V_57 . V_58 [ V_121 ] . V_125 = V_122 ;
V_9 -> V_57 . V_58 [ V_121 ] . V_128 = V_126 ;
V_9 -> V_57 . V_109 ++ ;
F_53 ( & V_9 -> V_57 . V_113 ) ;
return 0 ;
}
F_53 ( & V_9 -> V_57 . V_113 ) ;
V_127 = F_55 ( V_9 , V_110 , V_120 ) ;
if ( ! V_127 ) {
struct V_53 * V_57 ;
F_59 ( & V_9 -> V_25 -> V_26 ,
L_6 ) ;
V_57 = (struct V_53 * )
F_18 ( sizeof( struct V_53 ) ) ;
if ( ! V_57 ) {
F_7 ( & V_9 -> V_25 -> V_26 ,
L_7 ) ;
return 1 ;
}
V_57 -> V_110 = V_123 ;
V_57 -> V_125 = V_122 ;
V_57 -> V_128 = V_126 ;
F_50 ( & V_9 -> V_57 . V_113 ) ;
F_60 ( & V_57 -> V_111 , & V_9 -> V_57 . V_58 [ V_121 ] . V_111 ) ;
V_9 -> V_57 . V_109 ++ ;
F_53 ( & V_9 -> V_57 . V_113 ) ;
} else {
F_7 ( & V_9 -> V_25 -> V_26 ,
L_8 ,
V_110 , V_120 ) ;
return 1 ;
}
return 0 ;
}
int F_61 ( struct V_129 * V_130 , void * V_45 )
{
T_2 V_6 ;
char V_131 [ 16 ] ;
struct V_7 * V_9 = (struct V_7 * ) V_45 ;
struct V_132 * V_133 = V_130 -> V_133 ;
struct V_134 * V_135 = NULL ;
T_2 V_136 = 0 ;
if ( F_29 ( V_9 ) )
V_136 =
F_62 ( F_31 ( V_9 , V_82 ) ) ;
else if ( F_22 ( V_9 ) )
V_136 =
F_62 ( F_31 ( V_9 , V_83 ) ) ;
if ( F_9 ( & V_9 -> V_137 ) >= V_138 ) {
F_7 ( & V_9 -> V_25 -> V_26 , L_9 ,
F_9 ( & V_9 -> V_137 ) ) ;
goto V_139;
}
strncpy ( V_131 ,
F_10 (
( T_2 ) V_133 -> V_140 . V_141 . V_32 ) ,
sizeof( V_131 ) - 1 ) ;
V_9 -> V_32 = ( T_2 ) V_133 -> V_140 . V_141 . V_32 ;
if ( V_133 -> V_140 . V_141 . V_32 == V_142 ) {
V_9 -> V_143 . V_144 =
( T_2 ) V_133 -> V_140 . V_141 . V_144 ;
V_9 -> V_143 . V_145 =
( T_2 ) V_133 -> V_140 . V_141 . V_145 ;
}
if ( V_9 -> V_143 . V_144 < V_136 ) {
F_7 ( & V_9 -> V_25 -> V_26 ,
L_10 ,
V_136 , V_9 -> V_143 . V_144 ) ;
goto V_139;
}
V_9 -> V_143 . V_146 = V_133 -> V_140 . V_141 . V_146 ;
V_9 -> V_143 . V_32 = ( T_2 ) V_133 -> V_140 . V_141 . V_32 ;
V_9 -> V_95 . V_32 = ( T_2 ) V_133 -> V_140 . V_141 . V_32 ;
V_9 -> V_95 . V_94 = V_133 -> V_140 . V_141 . V_94 ;
for ( V_6 = 0 ; V_6 < V_9 -> V_85 ; V_6 ++ )
V_9 -> V_41 [ V_6 ] -> V_80 . V_92 . V_94 = V_9 -> V_95 . V_94 ;
F_63 ( & V_9 -> V_137 , V_147 ) ;
V_135 = & V_148 [ V_9 -> V_11 ] ;
if ( V_133 -> V_149 [ 0 ] != sizeof( * V_135 ) ) {
F_59 ( & V_9 -> V_25 -> V_26 , L_11 ,
( T_2 ) sizeof( * V_135 ) ,
V_133 -> V_149 [ 0 ] ) ;
}
memcpy ( V_135 , F_64 ( V_133 -> V_150 [ 0 ] ) , sizeof( * V_135 ) ) ;
strncpy ( V_9 -> V_151 . V_152 , V_135 -> V_153 , V_154 ) ;
strncpy ( V_9 -> V_151 . V_155 , V_135 -> V_156 ,
V_157 ) ;
F_65 ( ( V_91 * ) V_135 , ( sizeof( * V_135 ) >> 3 ) ) ;
V_9 -> V_151 . V_158 = V_135 -> V_159 ;
V_9 -> V_151 . V_160 = V_135 -> V_161 ;
F_66 ( & V_9 -> V_25 -> V_26 ,
L_12 ,
V_131 , F_67 ( V_135 -> V_162 ) ) ;
V_139:
for ( V_6 = 0 ; V_6 < V_133 -> V_163 ; V_6 ++ )
F_68 ( V_133 -> V_150 [ V_6 ] ) ;
F_69 ( V_130 ) ;
return 0 ;
}
int F_70 ( struct V_7 * V_9 , T_2 V_93 )
{
if ( V_9 && ( V_93 < F_15 ( V_9 ) ) &&
( V_9 -> V_37 . V_40 & F_13 ( V_93 ) ) )
return V_9 -> V_41 [ V_93 ] -> V_164 ;
return - 1 ;
}
int F_71 ( struct V_7 * V_9 , T_2 V_93 )
{
if ( V_9 && ( V_93 < F_12 ( V_9 ) ) &&
( V_9 -> V_37 . V_38 & F_13 ( V_93 ) ) )
return V_9 -> V_39 [ V_93 ] -> V_164 ;
return - 1 ;
}
struct V_165 * F_72 ( struct V_7 * V_9 )
{
struct V_165 * V_166 = NULL ;
if ( F_29 ( V_9 ) ) {
V_166 =
(struct V_165 * ) ( F_31 ( V_9 , V_82 ) ) ;
} else if ( F_22 ( V_9 ) ) {
V_166 = (struct V_165 * )
( F_31 ( V_9 , V_83 ) ) ;
} else if ( F_23 ( V_9 ) ) {
V_166 = (struct V_165 * )
( F_31 ( V_9 , V_84 ) ) ;
}
return V_166 ;
}
struct V_7 * F_73 ( T_2 V_11 )
{
if ( V_11 >= V_8 )
return NULL ;
else
return V_7 [ V_11 ] ;
}
V_91 F_74 ( struct V_7 * V_9 , V_91 V_167 )
{
V_91 V_168 ;
unsigned long V_169 ;
T_2 V_170 , V_171 ;
F_75 ( & V_9 -> V_60 , V_169 ) ;
V_171 = ( V_167 >> 32 ) ;
if ( ( V_9 -> V_13 == V_14 ) ||
( V_9 -> V_13 == V_16 ) ||
( V_9 -> V_13 == V_21 ) )
V_171 |= 0x00060000 ;
F_76 ( V_171 , V_9 -> V_172 . V_173 ) ;
V_170 = F_77 ( V_9 -> V_172 . V_173 ) ;
F_76 ( V_167 & 0xffffffff , V_9 -> V_172 . V_174 ) ;
V_170 = F_77 ( V_9 -> V_172 . V_174 ) ;
V_168 = F_78 ( V_9 -> V_172 . V_175 ) ;
F_79 ( & V_9 -> V_60 , V_169 ) ;
return V_168 ;
}
void F_80 ( struct V_7 * V_9 ,
V_91 V_176 ,
V_91 V_167 )
{
T_2 V_170 ;
unsigned long V_169 ;
F_75 ( & V_9 -> V_60 , V_169 ) ;
F_81 ( V_167 , V_9 -> V_172 . V_177 ) ;
F_76 ( V_176 >> 32 , V_9 -> V_172 . V_178 ) ;
V_170 = F_77 ( V_9 -> V_172 . V_178 ) ;
F_76 ( V_176 & 0xffffffff , V_9 -> V_172 . V_179 ) ;
F_79 ( & V_9 -> V_60 , V_169 ) ;
}
int F_82 ( struct V_7 * V_9 )
{
V_91 V_180 = 0 ;
V_91 V_181 ;
if ( F_22 ( V_9 ) ) {
V_181 = F_74 ( V_9 , V_182 ) ;
V_180 =
( V_181 & V_183 ) ;
} else {
V_181 = F_74 ( V_9 , V_184 ) ;
V_180 =
( V_181 & V_185 ) ;
}
return V_180 ? 0 : 1 ;
}
int F_83 ( struct V_7 * V_9 , T_2 * V_186 )
{
int V_12 = 1 ;
T_2 V_187 ;
if ( ! V_186 )
return V_12 ;
for ( V_187 = 0 ; ( V_12 != 0 ) && ( ( * V_186 == 0 ) || ( V_187 <= * V_186 ) ) ;
V_187 += V_188 / 10 ) {
V_12 = F_82 ( V_9 ) ;
if ( V_12 )
F_84 ( V_188 / 10 ) ;
}
return V_12 ;
}
int F_85 ( void * V_26 )
{
struct V_7 * V_119 = (struct V_7 * ) V_26 ;
T_2 V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
if ( V_7 [ V_6 ] == V_119 )
return V_119 -> V_11 ;
return - 1 ;
}
void F_86 ( struct V_189 * V_39 , struct V_86 * V_40 )
{
V_91 V_190 ;
struct V_7 * V_9 = NULL ;
if ( V_39 ) {
F_50 ( & V_39 -> V_113 ) ;
F_76 ( V_39 -> V_191 , V_39 -> V_192 ) ;
V_39 -> V_191 = 0 ;
F_87 () ;
F_53 ( & V_39 -> V_113 ) ;
V_9 = V_39 -> V_70 ;
}
if ( V_40 ) {
F_50 ( & V_40 -> V_113 ) ;
F_76 ( V_40 -> V_193 , V_40 -> V_194 ) ;
V_40 -> V_193 = 0 ;
F_87 () ;
F_53 ( & V_40 -> V_113 ) ;
V_9 = V_40 -> V_70 ;
}
if ( V_9 && ( F_22 ( V_9 ) || F_23 ( V_9 ) ) ) {
if ( V_39 )
F_81 ( V_195 , V_39 -> V_192 ) ;
else if ( V_40 ) {
V_190 = F_78 ( V_40 -> V_194 ) ;
F_81 ( ( ( V_190 & 0xFFFFFFFF00000000ULL ) |
V_195 ) ,
V_40 -> V_194 ) ;
}
}
}
