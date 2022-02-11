static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
V_4 -> V_6 . V_7 = V_8 ;
V_5 = ( F_2 ( V_4 ) ? V_9 : 0 ) ;
return V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
return V_13 [ V_11 -> V_14 ] . V_15 ;
}
struct V_16 * F_4 ( int V_17 )
{
return & V_13 [ V_17 ] ;
}
static int F_5 ( struct V_18 * V_19 , struct V_20 * V_21 ,
T_1 V_22 , int * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
unsigned char * V_26 ;
F_6 ( ( V_27 L_1 ) ) ;
if ( V_22 >= 2 * 1024 * 1024 ) {
if( V_22 >= 4 * 1024 * 1024 ) {
V_25 -> V_28 = 255 ;
V_25 -> V_29 = 63 ;
} else {
V_25 -> V_28 = 128 ;
V_25 -> V_29 = 32 ;
}
} else {
V_25 -> V_28 = 64 ;
V_25 -> V_29 = 32 ;
}
V_25 -> V_30 = F_7 ( V_22 , V_25 -> V_28 * V_25 -> V_29 ) ;
V_26 = F_8 ( V_21 ) ;
if ( ! V_26 )
return 0 ;
if( * ( V_31 * ) ( V_26 + 0x40 ) == F_9 ( 0xaa55 ) ) {
struct V_32 * V_33 = (struct V_32 * ) V_26 ;
struct V_32 * V_34 = V_33 ;
int V_35 = V_25 -> V_30 ;
int V_36 ;
unsigned char V_37 , V_38 ;
for( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_37 = V_34 -> V_37 ;
V_38 = V_34 -> V_39 & 0x3f ;
if( V_37 == 63 ) {
V_25 -> V_28 = 64 ;
V_25 -> V_29 = 32 ;
break;
} else if( V_37 == 127 ) {
V_25 -> V_28 = 128 ;
V_25 -> V_29 = 32 ;
break;
} else if( V_37 == 254 ) {
V_25 -> V_28 = 255 ;
V_25 -> V_29 = 63 ;
break;
}
V_34 ++ ;
}
if ( V_36 == 4 ) {
V_37 = V_33 -> V_37 ;
V_38 = V_33 -> V_39 & 0x3f ;
}
V_25 -> V_30 = F_7 ( V_22 , V_25 -> V_28 * V_25 -> V_29 ) ;
if ( V_36 < 4 && V_38 == V_25 -> V_29 ) {
if ( V_25 -> V_30 != V_35 )
F_6 ( ( V_27 L_2 ,
V_25 -> V_28 , V_25 -> V_29 , V_36 ) ) ;
} else if ( V_37 > 0 || V_38 > 0 ) {
F_6 ( ( V_27 L_3 ,
V_37 + 1 , V_38 , V_36 ) ) ;
F_6 ( ( V_27 L_4 ,
V_25 -> V_28 , V_25 -> V_29 ) ) ;
}
}
F_10 ( V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_10 * V_40 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
int V_42 , V_43 ;
unsigned int V_44 = 0 ;
unsigned int V_45 = 0 ;
V_42 = F_12 ( F_13 ( V_19 ) ) ;
V_43 = F_14 ( V_19 ) ;
if ( V_42 < V_46 && V_43 < V_47 &&
V_40 -> V_48 [ V_42 ] [ V_43 ] . V_17 == V_49 ) {
V_44 = V_40 -> V_48 [ V_42 ] [ V_43 ] . V_50 ;
V_45 = 1 ;
goto V_51;
}
if ( V_40 -> V_52 && ( V_19 -> type == V_53 ) )
V_19 -> V_54 = 1 ;
if ( V_19 -> type == V_53
&& F_13 ( V_19 ) != V_55
&& ( ! V_40 -> V_52 || V_19 -> V_56 )
&& ( ! V_40 -> V_57 || ( F_13 ( V_19 ) != 2 ) ) ) {
if ( V_58 == 0 )
return - V_59 ;
if ( V_58 < 0 )
V_19 -> V_60 = 1 ;
}
if ( V_19 -> V_61
&& V_19 -> type == V_53
&& ( ! V_40 -> V_57 || ( F_13 ( V_19 ) != 2 ) )
&& ! V_19 -> V_60 ) {
struct V_18 * V_11 ;
struct V_1 * V_41 = V_19 -> V_41 ;
unsigned V_62 = 0 ;
unsigned V_63 = 0 ;
unsigned V_64 ;
V_45 = 1 ;
for ( V_64 = 0 ; V_64 < V_40 -> V_65 ; ++ V_64 )
if ( V_40 -> V_66 [ V_64 ] . V_67 )
++ V_62 ;
F_15 (dev, host) {
if ( V_11 -> V_61
&& V_11 -> type == V_53
&& ( ! V_40 -> V_57 || ( F_13 ( V_19 ) != 2 ) )
&& ! V_11 -> V_60 ) {
if ( ( F_13 ( V_11 ) != V_55 )
|| ! V_40 -> V_66 [ F_14 ( V_11 ) ] . V_67 ) {
++ V_62 ;
}
} else {
++ V_63 ;
}
}
if ( V_62 == 0 )
++ V_62 ;
V_44 = ( V_41 -> V_68 - V_63 ) / V_62 ;
}
V_51:
if ( V_45 && V_19 -> V_69 -> V_70 < ( 45 * V_71 ) )
F_16 ( V_19 -> V_69 , 45 * V_71 ) ;
if ( V_44 > 256 )
V_44 = 256 ;
else if ( V_44 < 1 )
V_44 = 1 ;
F_17 ( V_19 , V_44 ) ;
V_19 -> V_61 = 1 ;
return 0 ;
}
static int F_18 ( struct V_18 * V_19 , int V_44 )
{
struct V_10 * V_40 = (struct V_10 * ) ( V_19 -> V_41 -> V_12 ) ;
int V_42 , V_43 , V_72 = 0 ;
V_42 = F_12 ( F_13 ( V_19 ) ) ;
V_43 = F_14 ( V_19 ) ;
if ( V_42 < V_46 && V_43 < V_47 &&
V_40 -> V_48 [ V_42 ] [ V_43 ] . V_17 == V_49 )
V_72 = 1 ;
if ( V_19 -> V_61 && ( V_19 -> type == V_53 ) &&
( F_13 ( V_19 ) == V_55 ) ) {
struct V_18 * V_11 ;
struct V_1 * V_41 = V_19 -> V_41 ;
unsigned V_36 = 0 ;
F_15 (dev, host) {
if ( V_11 -> V_61 && ( V_11 -> type == V_53 ) &&
( F_13 ( V_11 ) == V_55 ) )
++ V_36 ;
++ V_36 ;
}
if ( V_36 >= V_41 -> V_68 )
V_36 = V_41 -> V_68 - 1 ;
if ( V_44 > ( V_41 -> V_68 - V_36 ) )
V_44 = V_41 -> V_68 - V_36 ;
if ( V_44 > 256 )
V_44 = 256 ;
else if ( V_44 < 2 )
V_44 = 2 ;
return F_17 ( V_19 , V_44 ) ;
} else if ( V_72 ) {
F_17 ( V_19 , V_40 -> V_48 [ V_42 ] [ V_43 ] . V_50 ) ;
} else {
F_17 ( V_19 , 1 ) ;
}
return V_19 -> V_73 ;
}
static T_2 F_19 ( struct V_74 * V_11 , struct V_75 * V_76 , char * V_26 )
{
struct V_18 * V_19 = F_20 ( V_11 ) ;
struct V_10 * V_40 = (struct V_10 * ) ( V_19 -> V_41 -> V_12 ) ;
if ( F_13 ( V_19 ) != V_55 )
return snprintf ( V_26 , V_77 , V_19 -> V_60
? L_5 :
( ( V_40 -> V_52 && ( V_19 -> type == V_53 ) ) ? L_6 : L_7 ) ) ;
return snprintf ( V_26 , V_77 , L_8 ,
F_21 ( V_40 -> V_66 [ F_14 ( V_19 ) ] . type ) ) ;
}
static T_2 F_22 ( struct V_74 * V_11 ,
struct V_75 * V_76 , char * V_26 )
{
struct V_18 * V_19 = F_20 ( V_11 ) ;
struct V_10 * V_40 = (struct V_10 * ) ( V_19 -> V_41 -> V_12 ) ;
unsigned char V_78 [ 16 ] ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
if ( F_13 ( V_19 ) == V_55 )
memcpy ( V_78 , V_40 -> V_66 [ F_14 ( V_19 ) ] . V_79 , sizeof( V_78 ) ) ;
return snprintf ( V_26 , 16 * 2 + 2 ,
L_9 ,
V_78 [ 0 ] , V_78 [ 1 ] , V_78 [ 2 ] , V_78 [ 3 ] ,
V_78 [ 4 ] , V_78 [ 5 ] , V_78 [ 6 ] , V_78 [ 7 ] ,
V_78 [ 8 ] , V_78 [ 9 ] , V_78 [ 10 ] , V_78 [ 11 ] ,
V_78 [ 12 ] , V_78 [ 13 ] , V_78 [ 14 ] , V_78 [ 15 ] ) ;
}
static int F_23 ( struct V_18 * V_19 , int V_4 , void T_3 * V_80 )
{
struct V_10 * V_11 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( ! F_24 ( V_81 ) )
return - V_82 ;
return F_25 ( V_11 , V_4 , V_80 ) ;
}
static int F_26 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_74 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
int V_83 , V_84 ;
T_4 V_85 , V_64 ;
int V_86 = V_9 ;
V_85 = F_12 ( F_27 ( V_4 ) ) ;
V_64 = F_28 ( V_4 ) ;
if ( V_40 -> V_48 [ V_85 ] [ V_64 ] . V_17 == V_49 ) {
struct V_87 * V_87 ;
struct V_88 * V_89 ;
int V_90 ;
T_5 V_91 ;
T_6 V_92 ;
F_29 ( L_10 ,
V_93 ,
V_41 -> V_94 , F_13 ( V_11 ) , F_14 ( V_11 ) , ( int ) V_11 -> V_95 ) ;
V_84 = 0 ;
for ( V_83 = 0 ; V_83 < ( V_41 -> V_68 + V_96 ) ; ++ V_83 ) {
V_87 = & V_40 -> V_97 [ V_83 ] ;
if ( * ( V_98 * ) V_87 -> V_99 != 0 &&
( V_87 -> V_100 & V_101 ) &&
( V_87 -> V_102 == V_4 ) ) {
V_84 = 1 ;
V_92 = ( (struct V_103 * )
V_87 -> V_99 ) -> V_104 ;
break;
}
}
if ( ! V_84 )
return V_86 ;
V_87 = F_30 ( V_40 ) ;
if ( ! V_87 )
return V_86 ;
V_89 = (struct V_88 * ) V_87 -> V_99 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_89 = V_105 ;
V_89 -> V_106 = V_40 -> V_48 [ V_85 ] [ V_64 ] . V_107 ;
V_89 -> V_95 [ 1 ] = V_4 -> V_74 -> V_95 ;
V_91 = ( T_5 ) V_87 -> V_108 ;
V_89 -> V_109 = F_31 ( ( T_4 ) ( V_91 >> 32 ) ) ;
V_89 -> V_110 = F_31 ( ( T_4 ) ( V_91 & 0xffffffff ) ) ;
V_89 -> V_111 = F_31 ( V_112 ) ;
V_87 -> V_113 = sizeof( * V_89 ) ;
V_4 -> V_6 . V_114 = 0 ;
V_90 = F_32 ( V_115 , V_87 ,
( V_116 ) V_117 ,
( void * ) V_4 ) ;
for ( V_83 = 0 ; V_83 < 120 ; ++ V_83 ) {
if ( V_4 -> V_6 . V_114 ) {
V_86 = V_118 ;
break;
}
F_33 ( 1000 ) ;
}
if ( V_86 != V_118 )
F_29 ( L_11 ,
V_93 ) ;
} else {
F_29 (
L_12
L_13 ,
V_93 , V_93 ,
V_41 -> V_94 , F_13 ( V_11 ) , F_14 ( V_11 ) ,
( int ) V_11 -> V_95 ) ;
switch ( V_4 -> V_119 [ 0 ] ) {
case V_120 :
if ( ! ( V_40 -> V_121 ) ||
! ( V_40 -> V_122 ) ||
( ( V_4 -> V_119 [ 1 ] & 0x1f ) != V_123 ) )
break;
case V_124 :
case V_125 :
for ( V_83 = 0 ;
V_83 < ( V_41 -> V_68 + V_96 ) ;
++ V_83 ) {
struct V_87 * V_87 = & V_40 -> V_97 [ V_83 ] ;
if ( V_87 -> V_99 -> V_126 . V_127 &&
( V_87 -> V_100 & V_128 ) &&
( V_87 -> V_102 == V_4 ) ) {
V_87 -> V_100 |=
V_129 ;
V_4 -> V_6 . V_7 =
V_130 ;
V_86 = V_118 ;
}
}
break;
case V_131 :
for ( V_83 = 0 ;
V_83 < ( V_41 -> V_68 + V_96 ) ;
++ V_83 ) {
struct V_3 * V_132 ;
struct V_87 * V_87 = & V_40 -> V_97 [ V_83 ] ;
V_132 = V_87 -> V_102 ;
if ( ( V_87 -> V_99 -> V_126 . V_127 &
F_31
( V_133 | V_134 ) ) &&
( V_87 -> V_100 & V_128 ) &&
( ( V_132 ) ) &&
( V_132 -> V_74 == V_4 -> V_74 ) ) {
V_87 -> V_100 |=
V_129 ;
V_132 -> V_6 . V_7 =
V_130 ;
if ( V_132 == V_4 )
V_86 = V_118 ;
}
}
break;
}
}
return V_86 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_74 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
int V_83 ;
T_4 V_85 , V_64 ;
int V_86 = V_9 ;
V_85 = F_12 ( F_27 ( V_4 ) ) ;
V_64 = F_28 ( V_4 ) ;
if ( V_85 < V_46 && V_64 < V_47 &&
V_40 -> V_48 [ V_85 ] [ V_64 ] . V_17 == V_49 ) {
struct V_87 * V_87 ;
int V_90 ;
T_5 V_91 ;
V_98 V_132 ;
F_29 ( L_14 ,
V_93 ) ;
V_87 = F_30 ( V_40 ) ;
if ( ! V_87 )
return V_86 ;
if ( V_40 -> V_48 [ V_85 ] [ V_64 ] . V_135 == 0 ) {
struct V_88 * V_89 ;
V_89 = (struct V_88 * ) V_87 -> V_99 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> V_89 = V_136 ;
V_89 -> V_106 = V_40 -> V_48 [ V_85 ] [ V_64 ] . V_107 ;
V_89 -> V_95 [ 1 ] = V_4 -> V_74 -> V_95 ;
V_91 = ( T_5 ) V_87 -> V_108 ;
V_89 -> V_109 = F_31
( ( T_4 ) ( V_91 >> 32 ) ) ;
V_89 -> V_110 = F_31
( ( T_4 ) ( V_91 & 0xffffffff ) ) ;
V_89 -> V_111 = F_31 ( V_112 ) ;
V_87 -> V_113 = sizeof( * V_89 ) ;
V_132 = V_115 ;
V_40 -> V_48 [ V_85 ] [ V_64 ] . V_135 ++ ;
} else if ( V_40 -> V_48 [ V_85 ] [ V_64 ] . V_135 >= 1 ) {
struct V_137 * V_138 ;
V_138 = (struct V_137 * ) V_87 -> V_99 ;
memset ( V_138 , 0 , sizeof( * V_138 ) ) ;
V_138 -> V_106 = V_40 -> V_48 [ V_85 ] [ V_64 ] . V_107 ;
V_91 = ( T_5 ) V_87 -> V_108 ;
V_138 -> V_109 = F_31 ( ( T_4 ) ( V_91 >> 32 ) ) ;
V_138 -> V_110 = F_31
( ( T_4 ) ( V_91 & 0xffffffff ) ) ;
V_138 -> V_111 = F_31 ( V_112 ) ;
V_87 -> V_113 = sizeof( * V_138 ) ;
V_132 = V_139 ;
V_40 -> V_48 [ V_85 ] [ V_64 ] . V_135 = 0 ;
}
V_4 -> V_6 . V_114 = 0 ;
V_90 = F_32 ( V_132 , V_87 ,
( V_116 ) V_117 ,
( void * ) V_4 ) ;
for ( V_83 = 0 ; V_83 < 120 ; ++ V_83 ) {
if ( V_4 -> V_6 . V_114 ) {
V_86 = V_118 ;
break;
}
F_33 ( 1000 ) ;
}
if ( V_86 != V_118 )
F_29 ( L_15 ,
V_93 ) ;
} else {
struct V_3 * V_132 ;
unsigned long V_100 ;
for ( V_83 = 0 ;
V_83 < ( V_41 -> V_68 + V_96 ) ;
++ V_83 ) {
struct V_87 * V_87 = & V_40 -> V_97 [ V_83 ] ;
if ( V_87 -> V_99 -> V_126 . V_127 &&
( V_87 -> V_100 & V_128 ) &&
( V_87 -> V_102 == V_4 ) ) {
V_87 -> V_100 |= V_129 ;
V_4 -> V_6 . V_7 = V_130 ;
}
}
F_29 ( L_14 ,
V_93 ) ;
V_83 = F_35 ( V_40 ) ;
if ( V_83 )
return V_83 ;
for ( V_83 = 60 ; V_83 ; -- V_83 ) {
int V_140 = V_40 -> V_141 ;
if ( V_140 == 0 )
F_15 (dev, host) {
F_36 ( & V_11 -> V_142 , V_100 ) ;
F_37 (command, &dev->cmd_list,
list) {
if ( ( V_132 != V_4 ) &&
( V_132 -> V_6 . V_7 ==
V_143 ) ) {
V_140 ++ ;
break;
}
}
F_38 ( & V_11 -> V_142 , V_100 ) ;
if ( V_140 )
break;
}
if ( V_140 == 0 )
return V_118 ;
F_39 ( 1 ) ;
}
F_29 ( L_16 , V_93 ) ;
if ( ( ( V_40 -> V_144 . V_145 &
V_146 ) ||
( V_40 -> V_144 . V_145 &
V_147 ) ) &&
V_148 &&
( ( V_148 != 1 ) ||
! ( V_40 -> V_144 . V_145 &
V_149 ) ) ) {
F_40 ( V_40 , 2 , V_150 ) ;
}
V_86 = V_118 ;
}
return V_86 ;
}
static int F_41 ( struct V_151 * V_151 , struct V_152 * V_152 )
{
struct V_10 * V_40 ;
unsigned V_153 = F_42 ( V_151 ) ;
int V_154 = - V_155 ;
F_43 ( & V_156 ) ;
F_37 (aac, &aac_devices, entry) {
if ( V_40 -> V_157 == V_153 ) {
V_152 -> V_158 = V_40 ;
V_154 = 0 ;
break;
}
}
F_44 ( & V_156 ) ;
return V_154 ;
}
static long F_45 ( struct V_152 * V_152 ,
unsigned int V_4 , unsigned long V_80 )
{
struct V_10 * V_40 = (struct V_10 * ) V_152 -> V_158 ;
if ( ! F_24 ( V_81 ) )
return - V_82 ;
return F_25 ( V_40 , V_4 , ( void T_3 * ) V_80 ) ;
}
static long F_46 ( struct V_10 * V_11 , unsigned V_4 , unsigned long V_80 )
{
long V_86 ;
switch ( V_4 ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
case V_167 :
case V_168 :
case V_169 :
V_86 = F_25 ( V_11 , V_4 , ( void T_3 * ) V_80 ) ;
break;
case V_170 : {
struct V_171 T_3 * V_172 ;
V_172 = F_47 ( sizeof( * V_172 ) ) ;
V_86 = 0 ;
if ( F_48 ( V_172 , sizeof( * V_172 ) ) )
V_86 = - V_173 ;
if ( F_49 ( V_172 , ( void T_3 * ) V_80 , sizeof( struct V_171 ) - sizeof( T_4 ) ) )
V_86 = - V_173 ;
if ( ! V_86 )
V_86 = F_25 ( V_11 , V_4 , V_172 ) ;
break;
}
default:
V_86 = - V_174 ;
break;
}
return V_86 ;
}
static int F_50 ( struct V_18 * V_19 , int V_4 , void T_3 * V_80 )
{
struct V_10 * V_11 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( ! F_24 ( V_81 ) )
return - V_82 ;
return F_46 ( V_11 , V_4 , ( unsigned long ) V_80 ) ;
}
static long F_51 ( struct V_152 * V_152 , unsigned V_4 , unsigned long V_80 )
{
if ( ! F_24 ( V_81 ) )
return - V_82 ;
return F_46 ( V_152 -> V_158 , V_4 , V_80 ) ;
}
static T_2 F_52 ( struct V_74 * V_74 ,
struct V_75 * V_76 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
int V_175 ;
if ( V_11 -> V_144 . V_176 [ 0 ] ) {
char * V_177 = V_11 -> V_144 . V_176 ;
while ( * V_177 && * V_177 != ' ' )
++ V_177 ;
while ( * V_177 == ' ' )
++ V_177 ;
V_175 = snprintf ( V_26 , V_77 , L_8 , V_177 ) ;
} else
V_175 = snprintf ( V_26 , V_77 , L_8 ,
V_13 [ V_11 -> V_14 ] . V_178 ) ;
return V_175 ;
}
static T_2 F_54 ( struct V_74 * V_74 ,
struct V_75 * V_76 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
struct V_179 * V_180 ;
int V_175 ;
V_180 = & V_11 -> V_144 ;
if ( V_180 -> V_176 [ 0 ] ) {
char * V_177 = V_180 -> V_176 ;
while ( * V_177 && * V_177 != ' ' )
++ V_177 ;
V_175 = snprintf ( V_26 , V_77 , L_17 ,
( int ) ( V_177 - ( char * ) V_180 -> V_176 ) ,
V_180 -> V_176 ) ;
} else
V_175 = snprintf ( V_26 , V_77 , L_8 ,
V_13 [ V_11 -> V_14 ] . V_181 ) ;
return V_175 ;
}
static T_2 F_55 ( struct V_74 * V_182 ,
struct V_75 * V_76 , char * V_26 )
{
int V_175 = 0 ;
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_182 ) -> V_12 ;
if ( F_56 ( F_6 ( V_183 ) ) )
V_175 = snprintf ( V_26 , V_77 , L_18 ) ;
#ifdef F_57
V_175 += snprintf ( V_26 + V_175 , V_77 - V_175 ,
L_19 ) ;
#endif
if ( V_11 -> V_121 && V_11 -> V_122 )
V_175 += snprintf ( V_26 + V_175 , V_77 - V_175 ,
L_20 ) ;
if ( V_11 -> V_52 )
V_175 += snprintf ( V_26 + V_175 , V_77 - V_175 , L_21 ) ;
if ( V_11 -> V_144 . V_145 &
V_184 )
V_175 += snprintf ( V_26 + V_175 , V_77 - V_175 ,
L_22 ) ;
if ( V_11 -> V_185 )
V_175 += snprintf ( V_26 + V_175 , V_77 - V_175 , L_23 ) ;
return V_175 ;
}
static T_2 F_58 ( struct V_74 * V_74 ,
struct V_75 * V_76 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
int V_175 , V_186 ;
V_186 = F_59 ( V_11 -> V_187 . V_188 ) ;
V_175 = snprintf ( V_26 , V_77 , L_24 ,
V_186 >> 24 , ( V_186 >> 16 ) & 0xff , V_186 & 0xff ,
F_59 ( V_11 -> V_187 . V_189 ) ) ;
return V_175 ;
}
static T_2 F_60 ( struct V_74 * V_74 ,
struct V_75 * V_76 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
int V_175 , V_186 ;
V_186 = F_59 ( V_11 -> V_187 . V_190 ) ;
V_175 = snprintf ( V_26 , V_77 , L_24 ,
V_186 >> 24 , ( V_186 >> 16 ) & 0xff , V_186 & 0xff ,
F_59 ( V_11 -> V_187 . V_191 ) ) ;
return V_175 ;
}
static T_2 F_61 ( struct V_74 * V_74 ,
struct V_75 * V_76 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
int V_175 , V_186 ;
V_186 = F_59 ( V_11 -> V_187 . V_192 ) ;
V_175 = snprintf ( V_26 , V_77 , L_24 ,
V_186 >> 24 , ( V_186 >> 16 ) & 0xff , V_186 & 0xff ,
F_59 ( V_11 -> V_187 . V_193 ) ) ;
return V_175 ;
}
static T_2 F_62 ( struct V_74 * V_74 ,
struct V_75 * V_76 ,
char * V_26 )
{
return snprintf ( V_26 , V_77 , L_8 , V_194 ) ;
}
static T_2 F_63 ( struct V_74 * V_74 ,
struct V_75 * V_76 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
int V_175 = 0 ;
if ( F_59 ( V_11 -> V_187 . V_195 [ 0 ] ) != 0xBAD0 )
V_175 = snprintf ( V_26 , 16 , L_25 ,
F_59 ( V_11 -> V_187 . V_195 [ 0 ] ) ) ;
if ( V_175 &&
! memcmp ( & V_11 -> V_144 . V_196 [
sizeof( V_11 -> V_144 . V_196 ) - V_175 ] ,
V_26 , V_175 - 1 ) )
V_175 = snprintf ( V_26 , 16 , L_17 ,
( int ) sizeof( V_11 -> V_144 . V_196 ) ,
V_11 -> V_144 . V_196 ) ;
return F_64 ( V_175 , 16 ) ;
}
static T_2 F_65 ( struct V_74 * V_74 ,
struct V_75 * V_76 , char * V_26 )
{
return snprintf ( V_26 , V_77 , L_26 ,
F_53 ( V_74 ) -> V_197 ) ;
}
static T_2 F_66 ( struct V_74 * V_74 ,
struct V_75 * V_76 , char * V_26 )
{
return snprintf ( V_26 , V_77 , L_26 ,
F_53 ( V_74 ) -> V_198 ) ;
}
static T_2 F_67 ( struct V_74 * V_74 ,
struct V_75 * V_76 ,
const char * V_26 , T_7 V_83 )
{
int V_199 = - V_200 ;
int V_201 = 0 ;
struct V_10 * V_40 ;
if ( ! F_24 ( V_202 ) )
return V_199 ;
V_40 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
V_201 = V_26 [ 0 ] == '!' ? 1 : 0 ;
V_199 = F_40 ( V_40 , V_201 , V_150 ) ;
if ( V_199 >= 0 )
V_199 = V_83 ;
return V_199 ;
}
static T_2 F_68 ( struct V_74 * V_74 ,
struct V_75 * V_76 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_53 ( V_74 ) -> V_12 ;
int V_175 , V_186 ;
V_186 = F_69 ( V_11 ) ;
if ( ( V_186 == 0 ) && V_11 -> V_141 )
V_186 = - V_203 ;
V_175 = snprintf ( V_26 , V_77 , L_27 , V_186 ) ;
return V_175 ;
}
T_2 F_70 ( struct V_74 * V_74 , char * V_26 )
{
return F_63 ( V_74 , & V_204 , V_26 ) ;
}
static void F_71 ( struct V_10 * V_40 )
{
int V_205 ;
V_40 -> V_206 = 1 ;
F_72 ( V_40 ) ;
if ( V_40 -> V_207 ) {
int V_205 ;
for ( V_205 = 0 ; V_205 < ( V_40 -> V_208 -> V_68 + V_96 ) ; V_205 ++ ) {
struct V_87 * V_87 = & V_40 -> V_97 [ V_205 ] ;
if ( ! ( V_87 -> V_99 -> V_126 . V_127 & F_31 ( V_134 | V_133 ) ) &&
( V_87 -> V_99 -> V_126 . V_127 & F_31 ( V_209 ) ) )
F_73 ( & V_87 -> V_210 ) ;
}
F_74 ( V_40 -> V_211 ) ;
}
F_75 ( V_40 ) ;
if ( V_40 -> V_212 -> V_74 == V_213 ||
V_40 -> V_212 -> V_74 == V_214 ||
V_40 -> V_212 -> V_74 == V_215 ||
V_40 -> V_212 -> V_74 == V_216 ) {
if ( V_40 -> V_217 > 1 ) {
for ( V_205 = 0 ; V_205 < V_40 -> V_217 ; V_205 ++ ) {
F_76 ( F_77 ( V_40 -> V_212 , V_205 ) ,
& ( V_40 -> V_218 [ V_205 ] ) ) ;
}
} else {
F_76 ( V_40 -> V_212 -> V_219 ,
& ( V_40 -> V_218 [ 0 ] ) ) ;
}
} else {
F_76 ( V_40 -> V_212 -> V_219 , V_40 ) ;
}
if ( V_40 -> V_185 )
F_78 ( V_40 -> V_212 ) ;
else if ( V_40 -> V_217 > 1 )
F_79 ( V_40 -> V_212 ) ;
}
static void F_80 ( void )
{
V_220 = F_81 ( 0 , L_28 , & V_221 ) ;
if ( V_220 < 0 ) {
F_29 ( L_29 ) ;
}
}
static int F_82 ( struct V_222 * V_212 , const struct V_223 * V_157 )
{
unsigned V_224 = V_157 -> V_225 ;
struct V_1 * V_2 ;
struct V_10 * V_40 ;
struct V_226 * V_227 = & V_228 ;
int error = - V_155 ;
int V_229 = 0 ;
T_5 V_230 ;
extern int V_231 ;
if ( V_212 -> V_74 == V_214 )
V_212 -> V_232 = 1 ;
F_37 (aac, &aac_devices, entry) {
if ( V_40 -> V_157 > V_229 )
break;
V_227 = & V_40 -> V_34 ;
V_229 ++ ;
}
F_83 ( V_212 , V_233 | V_234 |
V_235 ) ;
error = F_84 ( V_212 ) ;
if ( error )
goto V_236;
error = - V_155 ;
if ( V_13 [ V_224 ] . V_237 & V_238 )
V_230 = F_85 ( 31 ) ;
else
V_230 = F_85 ( 32 ) ;
if ( F_86 ( V_212 , V_230 ) ||
F_87 ( V_212 , V_230 ) )
goto V_239;
F_88 ( V_212 ) ;
V_2 = F_89 ( & V_240 , sizeof( struct V_10 ) ) ;
if ( ! V_2 )
goto V_239;
V_2 -> V_219 = V_212 -> V_219 ;
V_2 -> V_229 = V_229 ;
V_2 -> V_241 = 16 ;
V_2 -> V_242 = 1 ;
if ( V_220 == V_243 )
F_80 () ;
V_40 = (struct V_10 * ) V_2 -> V_12 ;
V_40 -> V_244 = F_90 ( V_212 , 0 ) ;
V_40 -> V_208 = V_2 ;
V_40 -> V_212 = V_212 ;
V_40 -> V_15 = V_240 . V_15 ;
V_40 -> V_157 = V_2 -> V_229 ;
V_40 -> V_14 = V_224 ;
F_91 ( & V_40 -> V_34 ) ;
V_40 -> V_97 = F_92 ( sizeof( struct V_87 ) * ( V_2 -> V_68 + V_96 ) , V_245 ) ;
if ( ! V_40 -> V_97 )
goto V_246;
F_93 ( & V_40 -> V_247 ) ;
F_94 ( & V_40 -> V_248 ) ;
V_40 -> V_249 = V_250 ;
if ( ( * V_13 [ V_224 ] . V_251 ) ( V_40 ) )
goto V_252;
if ( V_40 -> V_253 ) {
if ( V_231 )
F_95 ( V_254 L_30
L_31
L_32 ,
V_40 -> V_15 ,
V_40 -> V_157 ) ;
else
F_95 ( V_254 L_33
L_34
L_35 ,
V_40 -> V_15 ,
V_40 -> V_157 ) ;
}
V_40 -> V_211 = F_96 ( V_255 , V_40 , V_93 ) ;
if ( F_97 ( V_40 -> V_211 ) ) {
F_95 ( V_256 L_36 ) ;
error = F_98 ( V_40 -> V_211 ) ;
V_40 -> V_211 = NULL ;
goto V_257;
}
if ( V_13 [ V_224 ] . V_237 & V_238 )
if ( F_86 ( V_212 , F_85 ( 32 ) ) )
goto V_257;
V_40 -> V_258 = V_13 [ V_224 ] . V_259 ;
error = F_99 ( V_40 ) ;
if ( error < 0 )
goto V_257;
if ( ( V_13 [ V_224 ] . V_237 & V_260 ) &&
( V_2 -> V_261 > 34 ) ) {
V_2 -> V_261 = 34 ;
V_2 -> V_262 = ( V_2 -> V_261 * 8 ) + 112 ;
}
if ( ( V_13 [ V_224 ] . V_237 & V_263 ) &&
( V_2 -> V_261 > 17 ) ) {
V_2 -> V_261 = 17 ;
V_2 -> V_262 = ( V_2 -> V_261 * 8 ) + 112 ;
}
error = F_100 ( V_212 ,
( V_40 -> V_187 . V_264 & V_265 ) ?
( V_2 -> V_262 << 9 ) : 65536 ) ;
if ( error )
goto V_257;
if ( V_13 [ V_224 ] . V_237 & V_260 )
V_40 -> V_266 = 1 ;
else
V_40 -> V_266 = 0 ;
if ( V_40 -> V_267 || V_58 || V_40 -> V_52 )
V_2 -> V_197 = V_40 -> V_258 ;
else
V_2 -> V_197 = 0 ;
F_101 ( V_40 , 0 ) ;
F_102 ( V_40 ) ;
F_103 ( & V_40 -> V_34 , V_227 ) ;
V_2 -> V_198 = V_40 -> V_65 ;
if ( V_2 -> V_198 < V_40 -> V_268 )
V_2 -> V_198 = V_40 -> V_268 ;
if ( V_2 -> V_198 < V_269 )
V_2 -> V_198 = V_269 ;
else
V_2 -> V_270 = V_2 -> V_198 ;
if ( ! V_40 -> V_271 && V_13 [ V_224 ] . V_237 & V_272 )
F_104 ( V_40 , 0 , 2 , 0 , NULL ) ;
V_2 -> V_273 = V_274 ;
F_105 ( V_212 , V_2 ) ;
error = F_106 ( V_2 , & V_212 -> V_11 ) ;
if ( error )
goto V_257;
F_107 ( V_2 ) ;
F_108 ( V_212 ) ;
F_109 ( V_212 ) ;
return 0 ;
V_257:
F_71 ( V_40 ) ;
V_252:
F_110 ( V_40 ) ;
if ( V_40 -> V_275 )
F_111 ( V_40 -> V_212 , V_40 -> V_276 , V_40 -> V_275 ,
V_40 -> V_277 ) ;
F_10 ( V_40 -> V_278 ) ;
F_112 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_97 ) ;
F_10 ( V_40 -> V_66 ) ;
V_246:
F_113 ( V_2 ) ;
V_239:
F_114 ( V_212 ) ;
V_236:
return error ;
}
static void F_115 ( struct V_10 * V_40 )
{
F_75 ( V_40 ) ;
F_116 ( V_40 ) ;
}
static int F_117 ( struct V_10 * V_11 )
{
unsigned long V_90 ;
while ( ! ( ( V_90 = F_118 ( V_11 , V_279 . V_280 ) ) & V_281 )
|| V_90 == 0xffffffff )
F_33 ( 20 ) ;
F_75 ( V_11 ) ;
F_119 ( V_11 ) ;
if ( ( V_11 -> V_212 -> V_74 == V_214 ||
V_11 -> V_212 -> V_74 == V_215 ||
V_11 -> V_212 -> V_74 == V_216 ) )
F_120 ( V_11 ) ;
if ( V_11 -> V_282 )
F_121 ( V_11 , V_283 ) ;
if ( F_122 ( V_11 ) )
goto V_284;
F_119 ( V_11 ) ;
F_123 ( V_11 ) ;
if ( ! V_11 -> V_253 ) {
V_11 -> V_251 -> V_285 . V_286 = F_31 ( V_11 -> V_217 ) ;
F_124 ( V_11 ) ;
}
return 0 ;
V_284:
return - 1 ;
}
static int F_125 ( struct V_222 * V_212 , T_8 V_287 )
{
struct V_1 * V_2 = F_126 ( V_212 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_127 ( V_2 ) ;
F_72 ( V_40 ) ;
F_115 ( V_40 ) ;
F_105 ( V_212 , V_2 ) ;
F_109 ( V_212 ) ;
F_114 ( V_212 ) ;
F_128 ( V_212 , F_129 ( V_212 , V_287 ) ) ;
return 0 ;
}
static int F_130 ( struct V_222 * V_212 )
{
struct V_1 * V_2 = F_126 ( V_212 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
int V_5 ;
F_128 ( V_212 , V_288 ) ;
F_131 ( V_212 , V_288 , 0 ) ;
F_132 ( V_212 ) ;
V_5 = F_84 ( V_212 ) ;
if ( V_5 )
goto V_289;
F_88 ( V_212 ) ;
if ( F_117 ( V_40 ) )
goto V_289;
V_40 -> V_206 = 0 ;
F_133 ( V_2 ) ;
return 0 ;
V_289:
F_95 ( V_254 L_37 , V_40 -> V_15 , V_40 -> V_157 ) ;
F_113 ( V_2 ) ;
F_114 ( V_212 ) ;
return - V_155 ;
}
static void F_134 ( struct V_222 * V_11 )
{
struct V_1 * V_2 = F_126 ( V_11 ) ;
F_127 ( V_2 ) ;
F_71 ( (struct V_10 * ) V_2 -> V_12 ) ;
}
static void F_135 ( struct V_222 * V_212 )
{
struct V_1 * V_2 = F_126 ( V_212 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_136 ( V_2 ) ;
F_71 ( V_40 ) ;
F_110 ( V_40 ) ;
F_111 ( V_40 -> V_212 , V_40 -> V_276 , V_40 -> V_275 ,
V_40 -> V_277 ) ;
F_10 ( V_40 -> V_278 ) ;
F_112 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_97 ) ;
F_10 ( V_40 -> V_66 ) ;
F_137 ( & V_40 -> V_34 ) ;
F_113 ( V_2 ) ;
F_114 ( V_212 ) ;
if ( F_138 ( & V_228 ) ) {
F_139 ( V_220 , L_28 ) ;
V_220 = V_243 ;
}
}
static void F_140 ( struct V_10 * V_40 )
{
int V_205 ;
struct V_3 * V_4 ;
for ( V_205 = 0 ; V_205 < V_40 -> V_208 -> V_68 ; V_205 ++ ) {
V_4 = (struct V_3 * ) V_40 -> V_97 [ V_205 ] . V_102 ;
if ( V_4 && ( V_4 -> V_6 . V_7 == V_143 ) ) {
F_141 ( V_4 ) ;
if ( V_40 -> V_290 )
V_4 -> V_291 = V_292 << 16 ;
else
V_4 -> V_291 = V_293 << 16 ;
V_4 -> V_294 ( V_4 ) ;
}
}
}
static T_9 F_142 ( struct V_222 * V_212 ,
enum V_295 error )
{
struct V_1 * V_2 = F_126 ( V_212 ) ;
struct V_10 * V_40 = F_143 ( V_2 ) ;
F_144 ( & V_212 -> V_11 , L_38 , error ) ;
switch ( error ) {
case V_296 :
return V_297 ;
case V_298 :
V_40 -> V_290 = 1 ;
F_127 ( V_40 -> V_208 ) ;
F_140 ( V_40 ) ;
F_115 ( V_40 ) ;
F_145 ( V_212 ) ;
F_112 ( V_40 , 0 ) ;
return V_299 ;
case V_300 :
V_40 -> V_290 = 1 ;
F_140 ( V_40 ) ;
return V_301 ;
}
return V_299 ;
}
static T_9 F_146 ( struct V_222 * V_212 )
{
F_144 ( & V_212 -> V_11 , L_39 ) ;
return V_299 ;
}
static T_9 F_147 ( struct V_222 * V_212 )
{
F_144 ( & V_212 -> V_11 , L_40 ) ;
F_132 ( V_212 ) ;
if ( F_84 ( V_212 ) ) {
F_148 ( & V_212 -> V_11 ,
L_41 ) ;
goto V_289;
}
F_88 ( V_212 ) ;
if ( F_149 ( V_212 ) ) {
F_144 ( & V_212 -> V_11 , L_42 ) ;
goto V_289;
}
return V_302 ;
V_289:
F_144 ( & V_212 -> V_11 , L_43 ) ;
return V_301 ;
}
static void F_150 ( struct V_222 * V_212 )
{
struct V_1 * V_2 = F_126 ( V_212 ) ;
struct V_18 * V_19 = NULL ;
struct V_10 * V_40 = (struct V_10 * ) F_143 ( V_2 ) ;
F_151 ( V_212 ) ;
if ( F_112 ( V_40 , V_40 -> V_249 ) ) {
F_144 ( & V_212 -> V_11 , L_44 ) ;
V_40 -> V_303 = V_304 ;
if ( F_112 ( V_40 , V_250 ) ) {
F_148 ( & V_212 -> V_11 ,
L_45 ) ;
return;
}
}
F_33 ( 10000 ) ;
F_117 ( V_40 ) ;
V_40 -> V_206 = 0 ;
V_40 -> V_290 = 0 ;
F_152 (sdev, shost)
if ( V_19 -> V_305 == V_306 )
V_19 -> V_305 = V_307 ;
F_133 ( V_40 -> V_208 ) ;
F_107 ( V_40 -> V_208 ) ;
F_109 ( V_212 ) ;
F_144 ( & V_212 -> V_11 , L_46 ) ;
}
static int T_10 F_153 ( void )
{
int error ;
F_95 ( V_254 L_47 ,
V_93 , V_194 ) ;
error = F_154 ( & V_308 ) ;
if ( error < 0 )
return error ;
F_80 () ;
return 0 ;
}
static void T_11 F_155 ( void )
{
if ( V_220 > - 1 )
F_139 ( V_220 , L_28 ) ;
F_156 ( & V_308 ) ;
}
