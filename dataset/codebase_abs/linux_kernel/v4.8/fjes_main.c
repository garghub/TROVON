static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = { V_5 , NULL } ;
char V_6 [ sizeof( V_7 ) + 1 ] ;
struct V_8 * V_9 ;
union V_10 * V_11 ;
T_1 V_12 ;
int V_13 ;
V_12 = F_2 ( V_2 -> V_14 , L_1 , NULL , & V_4 ) ;
if ( F_3 ( V_12 ) )
return - V_15 ;
V_11 = V_4 . V_16 ;
V_13 = F_4 ( ( V_17 * ) V_11 -> string . V_16 ,
V_11 -> string . V_18 , V_19 ,
V_6 , sizeof( V_6 ) - 1 ) ;
V_6 [ V_13 ] = 0 ;
if ( strncmp ( V_7 , V_6 , strlen ( V_7 ) ) != 0 ) {
F_5 ( V_4 . V_16 ) ;
return - V_15 ;
}
F_5 ( V_4 . V_16 ) ;
V_12 = F_6 ( V_2 -> V_14 , V_20 ,
V_21 , V_22 ) ;
if ( F_3 ( V_12 ) )
return - V_15 ;
V_9 = F_7 ( V_23 , 0 , V_22 ,
F_8 ( V_22 ) ) ;
V_2 -> V_24 = V_9 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = (struct V_8 * ) F_10 ( V_2 ) ;
F_11 ( V_9 ) ;
return 0 ;
}
static T_1
V_21 ( struct V_25 * V_26 , void * V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 = V_27 ;
switch ( V_26 -> type ) {
case V_34 :
V_29 = & V_26 -> V_27 . V_35 ;
V_33 [ 0 ] . V_36 = V_29 -> V_37 . V_38 ;
V_33 [ 0 ] . V_39 = V_29 -> V_37 . V_38 +
V_29 -> V_37 . V_40 - 1 ;
break;
case V_41 :
V_31 = & V_26 -> V_27 . V_31 ;
if ( V_31 -> V_42 != 1 )
return V_43 ;
V_33 [ 1 ] . V_36 = V_31 -> V_44 [ 0 ] ;
V_33 [ 1 ] . V_39 = V_31 -> V_44 [ 0 ] ;
break;
default:
break;
}
return V_45 ;
}
static int F_12 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_49 ;
int V_13 = - 1 ;
V_47 -> V_50 = true ;
if ( ! F_13 ( & V_47 -> V_51 ) ) {
F_14 ( V_47 -> V_52 ,
& V_47 -> V_51 ,
V_53 ) ;
}
if ( ! V_47 -> V_54 ) {
V_13 = F_15 ( V_47 -> V_55 . V_56 . V_31 , V_57 ,
V_58 , V_49 -> V_59 , V_47 ) ;
if ( V_13 )
V_47 -> V_54 = false ;
else
V_47 -> V_54 = true ;
}
return V_13 ;
}
static void F_16 ( struct V_46 * V_47 )
{
struct V_60 * V_55 = & V_47 -> V_55 ;
V_47 -> V_50 = false ;
F_17 ( & V_47 -> V_51 ) ;
F_18 ( V_55 , V_61 , true ) ;
if ( V_47 -> V_54 ) {
F_19 ( V_47 -> V_55 . V_56 . V_31 , V_47 ) ;
V_47 -> V_54 = false ;
}
}
static int F_20 ( struct V_48 * V_49 )
{
struct V_46 * V_47 = F_21 ( V_49 ) ;
struct V_60 * V_55 = & V_47 -> V_55 ;
int V_13 ;
if ( V_47 -> V_62 )
return - V_63 ;
V_13 = F_22 ( V_47 ) ;
if ( V_13 )
goto V_64;
V_55 -> V_65 = 0 ;
V_55 -> V_66 = 0 ;
F_23 ( & V_47 -> V_67 ) ;
F_24 ( V_55 ) ;
V_13 = F_12 ( V_47 ) ;
if ( V_13 )
goto V_68;
F_18 ( V_55 , V_61 , false ) ;
F_25 ( V_49 ) ;
F_26 ( V_49 ) ;
return 0 ;
V_68:
F_16 ( V_47 ) ;
F_27 ( & V_47 -> V_67 ) ;
V_64:
F_28 ( V_47 ) ;
return V_13 ;
}
static int F_29 ( struct V_48 * V_49 )
{
struct V_46 * V_47 = F_21 ( V_49 ) ;
struct V_60 * V_55 = & V_47 -> V_55 ;
unsigned long V_69 ;
int V_70 ;
F_30 ( V_49 ) ;
F_31 ( V_49 ) ;
F_32 ( V_55 ) ;
F_27 ( & V_47 -> V_67 ) ;
F_33 ( & V_55 -> V_71 , V_69 ) ;
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
if ( F_34 ( V_55 , V_70 ) ==
V_74 )
V_47 -> V_55 . V_75 [ V_70 ]
. V_76 . V_77 -> V_78 . V_79 &=
~ V_80 ;
}
F_35 ( & V_55 -> V_71 , V_69 ) ;
F_16 ( V_47 ) ;
F_17 ( & V_47 -> V_51 ) ;
F_36 ( & V_47 -> V_81 ) ;
V_47 -> V_82 = 0 ;
F_36 ( & V_47 -> V_83 ) ;
F_36 ( & V_47 -> V_84 ) ;
F_36 ( & V_55 -> V_85 ) ;
F_36 ( & V_55 -> V_86 ) ;
F_37 ( V_55 ) ;
F_28 ( V_47 ) ;
return 0 ;
}
static int F_22 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_87 * V_88 ;
struct V_60 * V_55 = & V_47 -> V_55 ;
unsigned long V_69 ;
int V_13 ;
int V_70 ;
F_38 ( & V_55 -> V_89 . V_90 ) ;
V_13 = F_39 ( V_55 ) ;
switch ( V_13 ) {
case 0 :
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
V_55 -> V_75 [ V_70 ] . V_91 =
V_55 -> V_89 . V_92 -> V_77 . V_77 [ V_70 ] . V_91 ;
V_55 -> V_75 [ V_70 ] . V_93 =
V_55 -> V_89 . V_92 -> V_77 . V_77 [ V_70 ] . V_93 ;
}
break;
default:
case - V_94 :
case - V_95 :
V_47 -> V_96 = true ;
F_40 ( & V_55 -> V_89 . V_90 ) ;
return V_13 ;
}
F_40 ( & V_55 -> V_89 . V_90 ) ;
for ( V_70 = 0 ; V_70 < ( V_55 -> V_72 ) ; V_70 ++ ) {
if ( ( V_70 != V_55 -> V_73 ) &&
( V_55 -> V_75 [ V_70 ] . V_91 ==
V_97 ) ) {
F_41 ( V_55 , V_70 ,
V_98 ) ;
}
}
F_42 ( V_99 * V_55 -> V_72 ) ;
for ( V_70 = 0 ; V_70 < ( V_55 -> V_72 ) ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
V_88 = & V_55 -> V_75 [ V_70 ] ;
F_33 ( & V_55 -> V_71 , V_69 ) ;
F_43 ( & V_88 -> V_76 , V_49 -> V_100 ,
V_49 -> V_101 ) ;
F_35 ( & V_55 -> V_71 , V_69 ) ;
if ( F_44 ( V_55 , V_70 ) ) {
F_38 ( & V_55 -> V_89 . V_90 ) ;
V_13 =
F_45 ( V_55 , V_70 , V_88 ) ;
F_40 ( & V_55 -> V_89 . V_90 ) ;
switch ( V_13 ) {
case 0 :
break;
case - V_94 :
case - V_95 :
default:
V_47 -> V_96 = true ;
return V_13 ;
}
}
}
return 0 ;
}
static void F_28 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_102 V_103 ;
struct V_87 * V_88 ;
struct V_60 * V_55 = & V_47 -> V_55 ;
bool V_104 = false ;
unsigned long V_69 ;
int V_13 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
F_38 ( & V_55 -> V_89 . V_90 ) ;
V_13 = F_46 ( V_55 , V_70 ) ;
F_40 ( & V_55 -> V_89 . V_90 ) ;
if ( V_13 )
V_104 = true ;
V_88 = & V_55 -> V_75 [ V_70 ] ;
F_33 ( & V_55 -> V_71 , V_69 ) ;
F_43 ( & V_88 -> V_76 ,
V_49 -> V_100 , V_49 -> V_101 ) ;
F_35 ( & V_55 -> V_71 , V_69 ) ;
F_47 ( V_70 , & V_55 -> V_65 ) ;
}
if ( V_104 || V_47 -> V_96 ) {
V_13 = F_48 ( V_55 ) ;
V_47 -> V_96 = false ;
if ( V_13 )
V_47 -> V_62 = true ;
V_55 -> V_89 . V_105 = 0 ;
memset ( ( void * ) & V_103 , 0 , sizeof( V_103 ) ) ;
V_103 . V_106 = V_55 -> V_89 . V_107 ;
V_103 . V_108 = F_49 ( V_55 -> V_89 . V_109 ) ;
V_103 . V_110 = V_55 -> V_89 . V_111 ;
V_103 . V_112 = F_49 ( V_55 -> V_89 . V_92 ) ;
V_103 . V_113 = F_49 ( V_55 -> V_89 . V_114 -> V_115 ) ;
F_50 ( V_55 , & V_103 ) ;
}
}
static void F_51 ( struct V_116 * V_117 )
{
struct V_46 * V_47 = F_52 ( V_117 ,
struct V_46 , V_84 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_60 * V_55 = & V_47 -> V_55 ;
int V_118 , V_119 ;
enum V_120 V_121 ;
int V_72 , V_73 , V_122 ;
union V_123 * V_77 ;
int V_124 ;
if ( ( ( long ) V_125 -
F_53 ( V_49 ) ) > V_126 ) {
F_54 ( V_49 ) ;
return;
}
V_73 = V_55 -> V_73 ;
V_72 = V_55 -> V_72 ;
for ( V_124 = 0 ; V_124 < 5 ; V_124 ++ ) {
V_118 = 1 ;
for ( V_122 = 0 ; V_122 < V_72 ; V_122 ++ ) {
if ( V_73 == V_122 )
continue;
V_121 = F_34 ( V_55 , V_122 ) ;
V_119 = ( V_121 == V_74 ) ;
if ( ! V_119 )
continue;
V_77 = V_47 -> V_55 . V_75 [ V_122 ] . V_76 . V_77 ;
if ( ! ( V_77 -> V_78 . V_79 & V_127 ) )
return;
if ( F_55 ( V_77 -> V_78 . V_128 , V_77 -> V_78 . V_129 ,
V_77 -> V_78 . V_130 ) ) {
V_118 = 0 ;
break;
}
}
if ( V_118 ) {
F_54 ( V_49 ) ;
return;
}
}
F_56 ( 50 , 100 ) ;
F_57 ( V_47 -> V_131 , & V_47 -> V_84 ) ;
}
static void F_58 ( struct V_116 * V_117 )
{
struct V_46 * V_47 = F_52 ( V_117 ,
struct V_46 , V_132 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
F_59 () ;
F_60 ( V_49 ) ;
F_61 () ;
}
static void F_62 ( struct V_116 * V_117 )
{
struct V_46 * V_47 = F_52 ( V_117 ,
struct V_46 , V_83 ) ;
struct V_60 * V_55 = & V_47 -> V_55 ;
enum V_120 V_121 ;
int V_72 , V_73 , V_122 ;
V_73 = V_55 -> V_73 ;
V_72 = V_55 -> V_72 ;
for ( V_122 = 0 ; V_122 < V_72 ; V_122 ++ )
V_55 -> V_75 [ V_122 ] . V_133 = 0 ;
for ( V_122 = 0 ; V_122 < V_72 ; V_122 ++ ) {
if ( V_122 == V_73 )
continue;
V_121 = F_34 ( V_55 , V_122 ) ;
if ( V_121 == V_74 ) {
V_55 -> V_75 [ V_122 ] . V_133 =
V_55 -> V_75 [ V_122 ] . V_76 . V_77 -> V_78 . V_134 ;
if ( V_55 -> V_75 [ V_122 ] . V_133 ==
V_135 ) {
V_55 -> V_75 [ V_122 ] . V_76 . V_77 -> V_78 . V_134 =
V_136 ;
}
}
}
for ( V_122 = 0 ; V_122 < V_72 ; V_122 ++ ) {
if ( V_122 == V_73 )
continue;
V_121 = F_34 ( V_55 , V_122 ) ;
if ( ( V_55 -> V_75 [ V_122 ] . V_133 ==
V_135 ) &&
( V_121 == V_74 ) &&
! ( V_55 -> V_75 [ V_122 ] . V_137 . V_77 -> V_78 . V_79 &
V_80 ) ) {
F_41 ( V_55 , V_122 ,
V_138 ) ;
}
}
F_56 ( 500 , 1000 ) ;
}
static int F_63 ( struct V_46 * V_47 , int V_139 ,
void * V_27 , T_2 V_140 )
{
int V_141 ;
V_141 = F_64 ( & V_47 -> V_55 . V_75 [ V_139 ] . V_76 ,
V_27 , V_140 ) ;
if ( V_141 )
return V_141 ;
V_47 -> V_55 . V_75 [ V_139 ] . V_76 . V_77 -> V_78 . V_134 =
V_135 ;
if ( ! F_65 ( & V_47 -> V_83 ) )
F_57 ( V_47 -> V_131 ,
& V_47 -> V_83 ) ;
V_141 = 0 ;
return V_141 ;
}
static T_3
F_66 ( struct V_142 * V_143 , struct V_48 * V_49 )
{
struct V_46 * V_47 = F_21 ( V_49 ) ;
struct V_60 * V_55 = & V_47 -> V_55 ;
int V_72 , V_73 , V_144 ;
enum V_120 V_121 ;
struct V_145 * V_146 ;
char V_147 [ V_148 ] ;
bool V_149 , V_150 ;
struct V_151 * V_152 ;
T_4 V_153 = 0 ;
T_4 V_154 = 0 ;
T_3 V_155 ;
char * V_27 ;
int V_140 ;
V_155 = V_156 ;
V_149 = false ;
V_146 = F_67 ( V_49 , V_153 ) ;
V_152 = (struct V_151 * ) V_143 -> V_27 ;
V_73 = V_55 -> V_73 ;
V_150 = ( F_68 ( V_143 , & V_154 ) == 0 ) ? true : false ;
V_27 = V_143 -> V_27 ;
V_140 = V_143 -> V_140 ;
if ( F_69 ( V_152 -> V_157 ) ) {
V_144 = 0 ;
V_72 = V_55 -> V_72 ;
V_149 = true ;
} else if ( F_70 ( V_152 -> V_157 ) ) {
V_144 = V_152 -> V_157 [ V_158 - 1 ] ;
V_72 = V_144 + 1 ;
if ( ( V_152 -> V_157 [ 0 ] == 0x02 ) &&
( 0x00 == ( V_152 -> V_157 [ 1 ] | V_152 -> V_157 [ 2 ] |
V_152 -> V_157 [ 3 ] | V_152 -> V_157 [ 4 ] ) ) &&
( V_144 < V_55 -> V_72 ) ) {
;
} else {
V_144 = 0 ;
V_72 = 0 ;
V_155 = V_156 ;
V_47 -> V_159 . V_160 += 1 ;
V_55 -> V_75 [ V_73 ] . V_161 . V_160 += 1 ;
V_47 -> V_159 . V_162 += V_140 ;
V_55 -> V_75 [ V_73 ] . V_161 . V_162 += V_140 ;
}
} else {
V_144 = 0 ;
V_72 = 0 ;
V_155 = V_156 ;
V_47 -> V_159 . V_160 += 1 ;
V_55 -> V_75 [ V_73 ] . V_161 . V_160 += 1 ;
V_47 -> V_159 . V_162 += V_140 ;
V_55 -> V_75 [ V_73 ] . V_161 . V_162 += V_140 ;
}
for (; V_144 < V_72 ; V_144 ++ ) {
if ( V_73 == V_144 )
continue;
V_121 = F_34 ( V_55 , V_144 ) ;
if ( V_121 != V_74 ) {
V_155 = V_156 ;
} else if ( ! F_71 (
& V_47 -> V_55 . V_75 [ V_144 ] . V_137 , 0 ) ) {
V_47 -> V_159 . V_163 += 1 ;
V_55 -> V_75 [ V_144 ] . V_161
. V_163 += 1 ;
V_155 = V_156 ;
} else if ( ! F_72 (
& V_47 -> V_55 . V_75 [ V_144 ] . V_137 ,
V_49 -> V_101 ) ) {
V_47 -> V_159 . V_164 += 1 ;
V_55 -> V_75 [ V_144 ] . V_161 . V_164 += 1 ;
V_47 -> V_159 . V_165 += 1 ;
V_55 -> V_75 [ V_144 ] . V_161 . V_165 += 1 ;
V_155 = V_156 ;
} else if ( V_150 &&
! F_73 (
& V_47 -> V_55 . V_75 [ V_144 ] . V_137 ,
V_154 ) ) {
V_155 = V_156 ;
} else {
if ( V_140 < V_148 ) {
memset ( V_147 , 0 , V_148 ) ;
memcpy ( V_147 , V_143 -> V_27 , V_143 -> V_140 ) ;
V_140 = V_148 ;
V_27 = V_147 ;
}
if ( V_47 -> V_166 == 0 ) {
V_47 -> V_167 = V_125 ;
V_47 -> V_166 = 1 ;
} else {
V_47 -> V_166 ++ ;
}
if ( F_63 ( V_47 , V_144 , V_27 , V_140 ) ) {
if ( V_149 ) {
V_155 = V_156 ;
} else if (
( ( long ) V_125 -
( long ) V_47 -> V_167 ) >=
V_168 ) {
V_47 -> V_159 . V_169 += 1 ;
V_55 -> V_75 [ V_144 ] . V_161
. V_169 += 1 ;
V_47 -> V_159 . V_165 += 1 ;
V_55 -> V_75 [ V_144 ] . V_161
. V_165 += 1 ;
V_155 = V_156 ;
} else {
F_74 ( V_49 ) ;
F_75 ( V_146 ) ;
if ( ! F_65 ( & V_47 -> V_84 ) )
F_57 ( V_47 -> V_131 ,
& V_47 -> V_84 ) ;
V_155 = V_170 ;
}
} else {
if ( ! V_149 ) {
V_47 -> V_159 . V_160 += 1 ;
V_55 -> V_75 [ V_144 ] . V_161
. V_160 += 1 ;
V_47 -> V_159 . V_162 += V_140 ;
V_55 -> V_75 [ V_144 ] . V_161
. V_162 += V_140 ;
}
V_47 -> V_166 = 0 ;
V_155 = V_156 ;
}
}
}
if ( V_155 == V_156 ) {
F_76 ( V_143 ) ;
if ( V_149 ) {
V_47 -> V_159 . V_160 += 1 ;
V_55 -> V_75 [ V_73 ] . V_161 . V_160 += 1 ;
V_47 -> V_159 . V_162 += 1 ;
V_55 -> V_75 [ V_73 ] . V_161 . V_162 += V_140 ;
}
}
return V_155 ;
}
static void F_77 ( struct V_48 * V_49 )
{
struct V_145 * V_171 = F_67 ( V_49 , 0 ) ;
F_78 ( V_171 ) ;
}
static struct V_172 *
F_79 ( struct V_48 * V_49 , struct V_172 * V_173 )
{
struct V_46 * V_47 = F_21 ( V_49 ) ;
memcpy ( V_173 , & V_47 -> V_159 , sizeof( struct V_172 ) ) ;
return V_173 ;
}
static int F_80 ( struct V_48 * V_49 , int V_174 )
{
struct V_46 * V_47 = F_21 ( V_49 ) ;
bool V_175 = F_81 ( V_49 ) ;
struct V_60 * V_55 = & V_47 -> V_55 ;
unsigned long V_69 ;
int V_155 = - V_176 ;
int V_177 , V_70 ;
for ( V_177 = 0 ; V_178 [ V_177 ] != 0 ; V_177 ++ ) {
if ( V_174 <= V_178 [ V_177 ] ) {
V_174 = V_178 [ V_177 ] ;
if ( V_174 == V_49 -> V_101 )
return 0 ;
V_155 = 0 ;
break;
}
}
if ( V_155 )
return V_155 ;
if ( V_175 ) {
F_33 ( & V_55 -> V_71 , V_69 ) ;
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
V_55 -> V_75 [ V_70 ] . V_76 . V_77 -> V_78 . V_79 &=
~ V_127 ;
}
F_35 ( & V_55 -> V_71 , V_69 ) ;
F_30 ( V_49 ) ;
F_31 ( V_49 ) ;
F_36 ( & V_47 -> V_84 ) ;
F_27 ( & V_47 -> V_67 ) ;
F_42 ( 1000 ) ;
F_30 ( V_49 ) ;
}
V_49 -> V_101 = V_174 ;
if ( V_175 ) {
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
F_33 ( & V_55 -> V_71 , V_69 ) ;
F_43 ( & V_55 -> V_75 [ V_70 ] . V_76 ,
V_49 -> V_100 ,
V_49 -> V_101 ) ;
V_55 -> V_75 [ V_70 ] . V_76 . V_77 -> V_78 . V_79 |=
V_127 ;
F_35 ( & V_55 -> V_71 , V_69 ) ;
}
F_82 ( V_49 ) ;
F_26 ( V_49 ) ;
F_23 ( & V_47 -> V_67 ) ;
F_83 ( & V_47 -> V_67 ) ;
}
return V_155 ;
}
static int F_84 ( struct V_48 * V_49 ,
T_5 V_179 , T_4 V_180 )
{
struct V_46 * V_47 = F_21 ( V_49 ) ;
bool V_155 = true ;
int V_122 ;
for ( V_122 = 0 ; V_122 < V_47 -> V_55 . V_72 ; V_122 ++ ) {
if ( V_122 == V_47 -> V_55 . V_73 )
continue;
if ( ! F_73 (
& V_47 -> V_55 . V_75 [ V_122 ] . V_76 , V_180 ) )
V_155 = F_85 (
& V_47 -> V_55 . V_75 [ V_122 ] . V_76 , V_180 ) ;
}
return V_155 ? 0 : - V_181 ;
}
static int F_86 ( struct V_48 * V_49 ,
T_5 V_179 , T_4 V_180 )
{
struct V_46 * V_47 = F_21 ( V_49 ) ;
int V_122 ;
for ( V_122 = 0 ; V_122 < V_47 -> V_55 . V_72 ; V_122 ++ ) {
if ( V_122 == V_47 -> V_55 . V_73 )
continue;
F_87 ( & V_47 -> V_55 . V_75 [ V_122 ] . V_76 , V_180 ) ;
}
return 0 ;
}
static void F_88 ( struct V_46 * V_47 ,
int V_182 )
{
struct V_60 * V_55 = & V_47 -> V_55 ;
enum V_120 V_12 ;
unsigned long V_69 ;
V_12 = F_34 ( V_55 , V_182 ) ;
switch ( V_12 ) {
case V_183 :
case V_184 :
default:
break;
case V_185 :
if ( V_182 < V_55 -> V_73 ) {
F_33 ( & V_55 -> V_71 , V_69 ) ;
V_55 -> V_75 [ V_182 ] . V_76 . V_77 -> V_78 . V_79 |=
V_186 ;
F_35 ( & V_55 -> V_71 , V_69 ) ;
F_47 ( V_182 , & V_55 -> V_65 ) ;
F_89 ( V_182 , & V_47 -> V_82 ) ;
if ( ! F_65 ( & V_47 -> V_81 ) )
F_57 ( V_47 -> V_52 ,
& V_47 -> V_81 ) ;
}
break;
case V_74 :
if ( V_55 -> V_75 [ V_182 ] . V_137 . V_77 -> V_78 . V_79 &
V_187 ) {
F_89 ( V_182 , & V_55 -> V_66 ) ;
if ( ! F_65 ( & V_55 -> V_86 ) )
F_57 ( V_47 -> V_52 ,
& V_55 -> V_86 ) ;
}
break;
}
}
static void F_90 ( struct V_46 * V_47 , int V_182 )
{
struct V_60 * V_55 = & V_47 -> V_55 ;
enum V_120 V_12 ;
unsigned long V_69 ;
F_89 ( V_182 , & V_55 -> V_89 . V_188 ) ;
V_12 = F_34 ( V_55 , V_182 ) ;
switch ( V_12 ) {
case V_185 :
F_33 ( & V_55 -> V_71 , V_69 ) ;
V_55 -> V_75 [ V_182 ] . V_76 . V_77 -> V_78 . V_79 |=
V_186 ;
F_35 ( & V_55 -> V_71 , V_69 ) ;
F_47 ( V_182 , & V_55 -> V_65 ) ;
case V_183 :
case V_184 :
default:
F_89 ( V_182 , & V_47 -> V_82 ) ;
if ( ! F_65 ( & V_47 -> V_81 ) )
F_57 ( V_47 -> V_52 ,
& V_47 -> V_81 ) ;
break;
case V_74 :
F_89 ( V_182 , & V_55 -> V_66 ) ;
if ( ! F_65 ( & V_55 -> V_86 ) )
F_57 ( V_47 -> V_52 , & V_55 -> V_86 ) ;
break;
}
}
static void F_91 ( struct V_46 * V_47 ,
int V_182 )
{
struct V_60 * V_55 = & V_47 -> V_55 ;
if ( ! F_65 ( & V_55 -> V_85 ) )
F_57 ( V_47 -> V_52 , & V_55 -> V_85 ) ;
}
static T_6 V_57 ( int V_31 , void * V_27 )
{
struct V_46 * V_47 = V_27 ;
struct V_60 * V_55 = & V_47 -> V_55 ;
T_6 V_155 ;
T_7 V_189 ;
V_189 = F_24 ( V_55 ) ;
if ( V_189 & V_190 ) {
if ( V_189 & V_138 )
F_92 ( V_47 , V_189 & V_191 ) ;
if ( V_189 & V_192 )
F_90 ( V_47 , V_189 & V_191 ) ;
if ( V_189 & V_193 )
F_88 ( V_47 , V_189 & V_191 ) ;
if ( V_189 & V_194 )
F_18 ( V_55 ,
V_194 , true ) ;
if ( V_189 & V_98 )
F_91 ( V_47 , V_189 & V_191 ) ;
V_155 = V_195 ;
} else {
V_155 = V_196 ;
}
return V_155 ;
}
static int F_93 ( struct V_46 * V_47 ,
int V_197 )
{
struct V_60 * V_55 = & V_47 -> V_55 ;
enum V_120 V_121 ;
int V_72 , V_198 ;
int V_124 ;
V_72 = V_55 -> V_72 ;
V_197 = ( V_197 + 1 + V_72 ) % V_72 ;
for ( V_124 = 0 ; V_124 < V_72 ; V_124 ++ ) {
V_198 = ( V_197 + V_124 ) % V_72 ;
if ( V_198 == V_55 -> V_73 )
continue;
V_121 = F_34 ( V_55 , V_198 ) ;
if ( V_121 == V_74 ) {
if ( ! F_94 (
& V_55 -> V_75 [ V_198 ] . V_137 ) )
return V_198 ;
}
}
return - 1 ;
}
static void * F_95 ( struct V_46 * V_47 , T_2 * V_199 ,
int * V_198 )
{
void * V_200 ;
* V_198 = F_93 ( V_47 , * V_198 ) ;
if ( * V_198 < 0 )
return NULL ;
V_200 =
F_96 (
& V_47 -> V_55 . V_75 [ * V_198 ] . V_137 , V_199 ) ;
return V_200 ;
}
static void F_97 ( struct V_46 * V_47 , int V_198 )
{
F_98 ( & V_47 -> V_55 . V_75 [ V_198 ] . V_137 ) ;
}
static void F_92 ( struct V_46 * V_47 , int V_182 )
{
struct V_60 * V_55 = & V_47 -> V_55 ;
F_18 ( V_55 , V_138 , true ) ;
V_47 -> V_201 = true ;
F_83 ( & V_47 -> V_67 ) ;
}
static int F_99 ( struct V_202 * V_67 , int V_203 )
{
struct V_46 * V_47 =
F_52 ( V_67 , struct V_46 , V_67 ) ;
struct V_48 * V_49 = V_67 -> V_204 ;
struct V_60 * V_55 = & V_47 -> V_55 ;
struct V_142 * V_143 ;
int V_205 = 0 ;
int V_198 = 0 ;
int V_70 ;
T_2 V_206 ;
void * V_200 ;
F_100 ( & V_55 -> V_71 ) ;
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
if ( F_34 ( V_55 , V_70 ) ==
V_74 )
V_47 -> V_55 . V_75 [ V_70 ]
. V_76 . V_77 -> V_78 . V_79 |= V_80 ;
}
F_101 ( & V_55 -> V_71 ) ;
while ( V_205 < V_203 ) {
F_102 ( & V_47 -> V_55 ) ;
V_200 = F_95 ( V_47 , & V_206 , & V_198 ) ;
if ( V_200 ) {
V_143 = F_103 ( V_67 , V_206 ) ;
if ( ! V_143 ) {
V_47 -> V_159 . V_207 += 1 ;
V_55 -> V_75 [ V_198 ] . V_161
. V_207 += 1 ;
V_47 -> V_159 . V_208 += 1 ;
V_55 -> V_75 [ V_198 ] . V_161
. V_208 += 1 ;
} else {
memcpy ( F_104 ( V_143 , V_206 ) ,
V_200 , V_206 ) ;
V_143 -> V_209 = F_105 ( V_143 , V_49 ) ;
V_143 -> V_210 = V_211 ;
F_106 ( V_143 ) ;
V_205 ++ ;
V_47 -> V_159 . V_212 += 1 ;
V_55 -> V_75 [ V_198 ] . V_161
. V_212 += 1 ;
V_47 -> V_159 . V_213 += V_206 ;
V_55 -> V_75 [ V_198 ] . V_161
. V_213 += V_206 ;
if ( F_69 (
( (struct V_151 * ) V_200 ) -> V_157 ) ) {
V_47 -> V_159 . V_214 += 1 ;
V_55 -> V_75 [ V_198 ] . V_161
. V_214 += 1 ;
}
}
F_97 ( V_47 , V_198 ) ;
V_47 -> V_201 = true ;
} else {
break;
}
}
if ( V_205 < V_203 ) {
F_107 ( V_67 ) ;
if ( V_47 -> V_201 ) {
V_47 -> V_215 = V_125 ;
V_47 -> V_201 = false ;
}
if ( ( ( long ) V_125 - ( long ) V_47 -> V_215 ) < 3 ) {
F_108 ( V_67 ) ;
} else {
F_100 ( & V_55 -> V_71 ) ;
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
if ( F_34 ( V_55 , V_70 ) ==
V_74 )
V_47 -> V_55 . V_75 [ V_70 ] . V_76
. V_77 -> V_78 . V_79 &=
~ V_80 ;
}
F_101 ( & V_55 -> V_71 ) ;
F_18 ( V_55 , V_138 , false ) ;
}
}
return V_205 ;
}
static int F_109 ( struct V_8 * V_9 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_32 * V_33 ;
struct V_60 * V_55 ;
int V_216 ;
V_216 = - V_217 ;
V_49 = F_110 ( sizeof( struct V_46 ) , L_2 ,
V_218 , V_219 ,
V_220 ) ;
if ( ! V_49 )
goto V_221;
F_111 ( V_49 , & V_9 -> V_204 ) ;
F_112 ( & V_9 -> V_204 , V_49 ) ;
V_47 = F_21 ( V_49 ) ;
V_47 -> V_49 = V_49 ;
V_47 -> V_9 = V_9 ;
V_55 = & V_47 -> V_55 ;
V_55 -> V_222 = V_47 ;
V_216 = F_113 ( V_47 ) ;
if ( V_216 )
goto V_223;
F_114 ( & V_47 -> V_132 , F_58 ) ;
V_47 -> V_96 = false ;
V_47 -> V_62 = false ;
V_47 -> V_131 = F_115 ( V_23 L_3 , V_224 , 0 ) ;
V_47 -> V_52 = F_115 ( V_23 L_4 ,
V_224 , 0 ) ;
F_114 ( & V_47 -> V_84 , F_51 ) ;
F_114 ( & V_47 -> V_83 ,
F_62 ) ;
F_114 ( & V_47 -> V_81 , V_225 ) ;
V_47 -> V_82 = 0 ;
F_116 ( & V_47 -> V_51 , V_226 ) ;
V_47 -> V_50 = false ;
V_33 = F_117 ( V_9 , V_227 , 0 ) ;
V_55 -> V_56 . V_36 = V_33 -> V_36 ;
V_55 -> V_56 . V_228 = F_118 ( V_33 ) ;
V_55 -> V_56 . V_31 = F_119 ( V_9 , 0 ) ;
V_216 = F_120 ( & V_47 -> V_55 ) ;
if ( V_216 )
goto V_223;
V_49 -> V_100 [ 0 ] = 2 ;
V_49 -> V_100 [ 1 ] = 0 ;
V_49 -> V_100 [ 2 ] = 0 ;
V_49 -> V_100 [ 3 ] = 0 ;
V_49 -> V_100 [ 4 ] = 0 ;
V_49 -> V_100 [ 5 ] = V_55 -> V_73 ;
V_216 = F_121 ( V_49 ) ;
if ( V_216 )
goto V_229;
F_31 ( V_49 ) ;
return 0 ;
V_229:
F_122 ( & V_47 -> V_55 ) ;
V_223:
F_123 ( V_49 ) ;
V_221:
return V_216 ;
}
static int F_124 ( struct V_8 * V_9 )
{
struct V_48 * V_49 = F_125 ( & V_9 -> V_204 ) ;
struct V_46 * V_47 = F_21 ( V_49 ) ;
struct V_60 * V_55 = & V_47 -> V_55 ;
F_17 ( & V_47 -> V_51 ) ;
F_36 ( & V_47 -> V_81 ) ;
F_36 ( & V_47 -> V_83 ) ;
F_36 ( & V_47 -> V_84 ) ;
if ( V_47 -> V_52 )
F_126 ( V_47 -> V_52 ) ;
if ( V_47 -> V_131 )
F_126 ( V_47 -> V_131 ) ;
F_127 ( V_49 ) ;
F_122 ( V_55 ) ;
F_128 ( & V_47 -> V_67 ) ;
F_123 ( V_49 ) ;
return 0 ;
}
static int F_113 ( struct V_46 * V_47 )
{
struct V_48 * V_49 = V_47 -> V_49 ;
F_129 ( V_49 , & V_47 -> V_67 , F_99 , 64 ) ;
return 0 ;
}
static void V_219 ( struct V_48 * V_49 )
{
F_130 ( V_49 ) ;
V_49 -> V_230 = V_231 ;
V_49 -> V_232 = & V_233 ;
F_131 ( V_49 ) ;
V_49 -> V_101 = V_178 [ 3 ] ;
V_49 -> V_69 |= V_234 ;
V_49 -> V_235 |= V_236 | V_237 ;
}
static void V_226 ( struct V_116 * V_117 )
{
struct V_46 * V_47 = F_52 ( F_132 ( V_117 ) ,
struct V_46 , V_51 ) ;
F_133 () ;
V_57 ( V_47 -> V_55 . V_56 . V_31 , V_47 ) ;
F_134 () ;
if ( F_93 ( V_47 , 0 ) >= 0 )
F_83 ( & V_47 -> V_67 ) ;
if ( V_47 -> V_50 ) {
if ( ! F_13 ( & V_47 -> V_51 ) )
F_14 ( V_47 -> V_52 ,
& V_47 -> V_51 ,
V_53 ) ;
}
}
static void V_225 ( struct V_116 * V_117 )
{
struct V_46 * V_47 =
F_52 ( V_117 , struct V_46 , V_81 ) ;
struct V_48 * V_49 = V_47 -> V_49 ;
struct V_60 * V_55 = & V_47 -> V_55 ;
int V_238 , V_239 ;
int V_72 , V_73 , V_70 ;
int V_240 , V_241 ;
T_8 V_82 ;
unsigned long V_69 ;
int V_242 = 0 ;
int V_243 ;
int V_155 ;
V_73 = V_55 -> V_73 ;
V_72 = V_55 -> V_72 ;
V_82 = V_47 -> V_82 ;
V_47 -> V_82 = 0 ;
while ( ( V_82 || V_55 -> V_65 ) &&
( V_242 < 3000 ) ) {
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
V_243 = F_135 ( V_55 -> V_89 . V_114 ,
V_70 ) ;
V_240 = F_136 ( V_70 , & V_55 -> V_65 ) ;
V_241 = V_55 -> V_75 [ V_70 ] . V_137 . V_77 -> V_78 . V_79 &
V_186 ;
V_238 = F_136 ( V_70 , & V_82 ) ;
V_239 = F_136 ( V_70 ,
& V_55 -> V_89 . V_188 ) ;
if ( ( ! V_240 ||
( V_243 && ( ! V_243 || ! V_241 ) ) ) &&
( V_243 || ! V_238 || ! V_239 ) )
continue;
F_38 ( & V_55 -> V_89 . V_90 ) ;
V_155 = F_46 ( V_55 , V_70 ) ;
switch ( V_155 ) {
case 0 :
break;
case - V_94 :
case - V_95 :
default:
if ( ! F_65 (
& V_47 -> V_132 ) ) {
V_47 -> V_96 = true ;
F_137 (
& V_47 -> V_132 ) ;
}
break;
}
F_40 ( & V_55 -> V_89 . V_90 ) ;
F_33 ( & V_55 -> V_71 , V_69 ) ;
F_43 ( & V_55 -> V_75 [ V_70 ] . V_76 ,
V_49 -> V_100 , V_49 -> V_101 ) ;
F_35 ( & V_55 -> V_71 , V_69 ) ;
F_47 ( V_70 , & V_55 -> V_65 ) ;
F_47 ( V_70 , & V_82 ) ;
F_47 ( V_70 ,
& V_55 -> V_89 . V_188 ) ;
}
F_42 ( 100 ) ;
V_242 += 100 ;
}
if ( V_55 -> V_89 . V_188 ) {
for ( V_70 = 0 ; V_70 < V_55 -> V_72 ; V_70 ++ ) {
if ( V_70 == V_55 -> V_73 )
continue;
if ( F_136 ( V_70 ,
& V_55 -> V_89 . V_188 ) ) {
F_38 ( & V_55 -> V_89 . V_90 ) ;
V_155 = F_46 ( V_55 , V_70 ) ;
switch ( V_155 ) {
case 0 :
break;
case - V_94 :
case - V_95 :
default:
if ( ! F_65 (
& V_47 -> V_132 ) ) {
V_47 -> V_96 = true ;
F_137 (
& V_47 -> V_132 ) ;
}
break;
}
F_40 ( & V_55 -> V_89 . V_90 ) ;
F_33 ( & V_55 -> V_71 , V_69 ) ;
F_43 (
& V_55 -> V_75 [ V_70 ] . V_76 ,
V_49 -> V_100 , V_49 -> V_101 ) ;
F_35 ( & V_55 -> V_71 ,
V_69 ) ;
F_47 ( V_70 , & V_55 -> V_65 ) ;
F_47 ( V_70 , & V_82 ) ;
F_47 ( V_70 , & V_55 -> V_89 . V_188 ) ;
}
if ( F_136 ( V_70 , & V_82 ) ) {
F_33 ( & V_55 -> V_71 , V_69 ) ;
V_55 -> V_75 [ V_70 ] . V_76 . V_77 -> V_78 . V_79 &=
~ V_186 ;
F_35 ( & V_55 -> V_71 ,
V_69 ) ;
}
}
}
}
static int T_9 F_138 ( void )
{
int V_13 ;
F_139 ( L_5 ,
V_244 , V_245 , V_246 ) ;
V_13 = F_140 ( & V_247 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_141 ( & V_248 ) ;
if ( V_13 < 0 )
goto V_249;
return 0 ;
V_249:
F_142 ( & V_247 ) ;
return V_13 ;
}
static void T_10 F_143 ( void )
{
F_144 ( & V_248 ) ;
F_142 ( & V_247 ) ;
}
