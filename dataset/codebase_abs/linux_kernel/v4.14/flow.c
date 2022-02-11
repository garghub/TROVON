T_1 F_1 ( unsigned long V_1 )
{
struct V_2 V_3 ;
T_1 V_4 , V_5 ;
F_2 ( & V_3 ) ;
V_5 = F_3 ( V_6 - V_1 ) ;
V_4 = ( T_1 ) V_3 . V_7 * V_8 +
V_3 . V_9 / V_10 ;
return V_4 - V_5 ;
}
void F_4 ( struct V_11 * V_12 , T_2 V_13 ,
const struct V_14 * V_15 )
{
struct V_16 * V_17 ;
unsigned int V_18 = F_5 () ;
int V_19 = V_15 -> V_19 + ( F_6 ( V_15 ) ? V_20 : 0 ) ;
V_17 = F_7 ( V_12 -> V_17 [ V_18 ] ) ;
if ( F_8 ( V_17 ) ) {
F_9 ( & V_17 -> V_21 ) ;
if ( V_18 == 0 && F_10 ( V_12 -> V_22 != V_18 ) )
V_12 -> V_22 = V_18 ;
} else {
V_17 = F_7 ( V_12 -> V_17 [ 0 ] ) ;
F_9 ( & V_17 -> V_21 ) ;
if ( F_10 ( V_12 -> V_22 != V_18 ) ) {
if ( F_8 ( V_12 -> V_22 != - 1 ) &&
F_8 ( ! F_11 ( V_12 -> V_17 [ V_18 ] ) ) ) {
struct V_16 * V_23 ;
V_23 =
F_12 ( V_24 ,
V_25 |
V_26 |
V_27 |
V_28 ,
F_13 () ) ;
if ( F_8 ( V_23 ) ) {
V_23 -> V_29 = V_6 ;
V_23 -> V_30 = 1 ;
V_23 -> V_31 = V_19 ;
V_23 -> V_13 = V_13 ;
F_14 ( & V_23 -> V_21 ) ;
F_15 ( V_12 -> V_17 [ V_18 ] ,
V_23 ) ;
F_16 ( V_18 , & V_12 -> V_32 ) ;
goto V_33;
}
}
V_12 -> V_22 = V_18 ;
}
}
V_17 -> V_29 = V_6 ;
V_17 -> V_30 ++ ;
V_17 -> V_31 += V_19 ;
V_17 -> V_13 |= V_13 ;
V_33:
F_17 ( & V_17 -> V_21 ) ;
}
void F_18 ( const struct V_11 * V_12 ,
struct V_34 * V_35 ,
unsigned long * V_29 , T_2 * V_13 )
{
int V_18 ;
* V_29 = 0 ;
* V_13 = 0 ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
for ( V_18 = 0 ; V_18 < V_36 ; V_18 = F_19 ( V_18 , & V_12 -> V_32 ) ) {
struct V_16 * V_17 = F_20 ( V_12 -> V_17 [ V_18 ] ) ;
if ( V_17 ) {
F_21 ( & V_17 -> V_21 ) ;
if ( ! * V_29 || F_22 ( V_17 -> V_29 , * V_29 ) )
* V_29 = V_17 -> V_29 ;
* V_13 |= V_17 -> V_13 ;
V_35 -> V_37 += V_17 -> V_30 ;
V_35 -> V_38 += V_17 -> V_31 ;
F_23 ( & V_17 -> V_21 ) ;
}
}
}
void F_24 ( struct V_11 * V_12 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_36 ; V_18 = F_19 ( V_18 , & V_12 -> V_32 ) ) {
struct V_16 * V_17 = F_25 ( V_12 -> V_17 [ V_18 ] ) ;
if ( V_17 ) {
F_21 ( & V_17 -> V_21 ) ;
V_17 -> V_29 = 0 ;
V_17 -> V_30 = 0 ;
V_17 -> V_31 = 0 ;
V_17 -> V_13 = 0 ;
F_23 ( & V_17 -> V_21 ) ;
}
}
}
static int F_26 ( struct V_14 * V_15 , int V_19 )
{
if ( F_10 ( V_15 -> V_19 < V_19 ) )
return - V_39 ;
if ( F_10 ( ! F_27 ( V_15 , V_19 ) ) )
return - V_40 ;
return 0 ;
}
static bool F_28 ( struct V_14 * V_15 )
{
return F_27 ( V_15 , F_29 ( V_15 ) +
sizeof( struct V_41 ) ) ;
}
static int F_30 ( struct V_14 * V_15 )
{
unsigned int V_42 = F_29 ( V_15 ) ;
unsigned int V_43 ;
int V_44 ;
V_44 = F_26 ( V_15 , V_42 + sizeof( struct V_45 ) ) ;
if ( F_10 ( V_44 ) )
return V_44 ;
V_43 = F_31 ( V_15 ) ;
if ( F_10 ( V_43 < sizeof( struct V_45 ) ||
V_15 -> V_19 < V_42 + V_43 ) )
return - V_39 ;
F_32 ( V_15 , V_42 + V_43 ) ;
return 0 ;
}
static bool F_33 ( struct V_14 * V_15 )
{
int V_46 = F_34 ( V_15 ) ;
int V_47 ;
if ( F_10 ( ! F_27 ( V_15 , V_46 + sizeof( struct V_48 ) ) ) )
return false ;
V_47 = F_35 ( V_15 ) ;
if ( F_10 ( V_47 < sizeof( struct V_48 ) ||
V_15 -> V_19 < V_46 + V_47 ) )
return false ;
return true ;
}
static bool F_36 ( struct V_14 * V_15 )
{
return F_27 ( V_15 , F_34 ( V_15 ) +
sizeof( struct V_49 ) ) ;
}
static bool F_37 ( struct V_14 * V_15 )
{
return F_27 ( V_15 , F_34 ( V_15 ) +
sizeof( struct V_50 ) ) ;
}
static bool F_38 ( struct V_14 * V_15 )
{
return F_27 ( V_15 , F_34 ( V_15 ) +
sizeof( struct V_51 ) ) ;
}
static int F_39 ( struct V_14 * V_15 , struct V_52 * V_53 )
{
unsigned int V_42 = F_29 ( V_15 ) ;
unsigned int V_54 ;
int V_55 ;
struct V_56 * V_57 ;
T_3 V_58 ;
T_2 V_59 ;
int V_44 ;
V_44 = F_26 ( V_15 , V_42 + sizeof( * V_57 ) ) ;
if ( F_10 ( V_44 ) )
return V_44 ;
V_57 = F_40 ( V_15 ) ;
V_58 = V_57 -> V_58 ;
V_55 = ( V_60 * ) ( V_57 + 1 ) - V_15 -> V_61 ;
V_53 -> V_62 . V_63 = V_64 ;
V_53 -> V_62 . V_65 = F_41 ( V_57 ) ;
V_53 -> V_62 . V_66 = V_57 -> V_67 ;
V_53 -> V_68 . V_69 = * ( V_70 * ) V_57 & F_42 ( V_71 ) ;
V_53 -> V_68 . V_72 . V_73 = V_57 -> V_74 ;
V_53 -> V_68 . V_72 . V_75 = V_57 -> V_76 ;
V_55 = F_43 ( V_15 , V_55 , & V_58 , & V_59 ) ;
if ( V_59 ) {
if ( V_59 & F_44 ( ~ 0x7 ) )
V_53 -> V_62 . V_77 = V_78 ;
else
V_53 -> V_62 . V_77 = V_79 ;
} else {
V_53 -> V_62 . V_77 = V_80 ;
}
if ( F_10 ( V_55 < 0 ) )
return - V_81 ;
V_54 = V_55 - V_42 ;
F_32 ( V_15 , V_42 + V_54 ) ;
V_53 -> V_62 . V_63 = V_58 ;
return V_54 ;
}
static bool F_45 ( struct V_14 * V_15 )
{
return F_27 ( V_15 , F_34 ( V_15 ) +
sizeof( struct V_82 ) ) ;
}
static int F_46 ( struct V_14 * V_15 , struct V_83 * V_84 ,
bool V_85 )
{
struct V_83 * V_86 = (struct V_83 * ) V_15 -> V_61 ;
if ( F_8 ( ! F_47 ( V_86 -> V_87 ) ) )
return 0 ;
if ( F_10 ( V_15 -> V_19 < sizeof( struct V_83 ) + sizeof( T_2 ) ) )
return 0 ;
if ( F_10 ( ! F_27 ( V_15 , sizeof( struct V_83 ) +
sizeof( T_2 ) ) ) )
return - V_40 ;
V_86 = (struct V_83 * ) V_15 -> V_61 ;
V_84 -> V_88 = V_86 -> V_88 | F_44 ( V_89 ) ;
V_84 -> V_87 = V_86 -> V_87 ;
if ( F_10 ( V_85 ) ) {
int V_90 = V_15 -> V_61 - F_48 ( V_15 ) ;
T_4 V_88 ;
int V_44 ;
F_49 ( V_15 , V_90 ) ;
V_44 = F_50 ( V_15 , & V_88 ) ;
F_51 ( V_15 , V_90 ) ;
if ( V_44 )
return V_44 ;
F_52 ( V_15 , V_84 -> V_87 , V_88 ) ;
} else {
F_51 ( V_15 , sizeof( struct V_83 ) ) ;
}
return 1 ;
}
static void F_53 ( struct V_52 * V_53 )
{
V_53 -> V_91 . V_92 . V_88 = 0 ;
V_53 -> V_91 . V_92 . V_87 = 0 ;
V_53 -> V_91 . V_93 . V_88 = 0 ;
V_53 -> V_91 . V_93 . V_87 = 0 ;
}
static int F_54 ( struct V_14 * V_15 , struct V_52 * V_53 )
{
int V_94 ;
if ( F_6 ( V_15 ) ) {
V_53 -> V_91 . V_92 . V_88 = F_44 ( V_15 -> V_95 ) ;
V_53 -> V_91 . V_92 . V_87 = V_15 -> V_96 ;
} else {
V_94 = F_46 ( V_15 , & V_53 -> V_91 . V_92 , true ) ;
if ( V_94 <= 0 )
return V_94 ;
}
V_94 = F_46 ( V_15 , & V_53 -> V_91 . V_93 , false ) ;
if ( V_94 <= 0 )
return V_94 ;
return 0 ;
}
static T_2 F_55 ( struct V_14 * V_15 )
{
struct V_97 {
V_60 V_98 ;
V_60 V_99 ;
V_60 V_100 ;
V_60 V_101 [ 3 ] ;
T_2 V_102 ;
};
struct V_97 * V_103 ;
T_2 V_63 ;
V_63 = * ( T_2 * ) V_15 -> V_61 ;
F_51 ( V_15 , sizeof( T_2 ) ) ;
if ( F_56 ( V_63 ) )
return V_63 ;
if ( V_15 -> V_19 < sizeof( struct V_97 ) )
return F_44 ( V_104 ) ;
if ( F_10 ( ! F_27 ( V_15 , sizeof( struct V_97 ) ) ) )
return F_44 ( 0 ) ;
V_103 = (struct V_97 * ) V_15 -> V_61 ;
if ( V_103 -> V_98 != V_105 ||
V_103 -> V_99 != V_105 ||
( V_103 -> V_101 [ 0 ] | V_103 -> V_101 [ 1 ] | V_103 -> V_101 [ 2 ] ) != 0 )
return F_44 ( V_104 ) ;
F_51 ( V_15 , sizeof( struct V_97 ) ) ;
if ( F_56 ( V_103 -> V_102 ) )
return V_103 -> V_102 ;
return F_44 ( V_104 ) ;
}
static int F_57 ( struct V_14 * V_15 , struct V_52 * V_53 ,
int V_54 )
{
struct V_82 * V_106 = F_58 ( V_15 ) ;
V_53 -> V_107 . V_73 = F_44 ( V_106 -> V_108 ) ;
V_53 -> V_107 . V_75 = F_44 ( V_106 -> V_109 ) ;
memset ( & V_53 -> V_68 . V_110 , 0 , sizeof( V_53 -> V_68 . V_110 ) ) ;
if ( V_106 -> V_109 == 0 &&
( V_106 -> V_108 == V_111 ||
V_106 -> V_108 == V_112 ) ) {
int V_113 = V_15 -> V_19 - F_34 ( V_15 ) ;
struct V_114 * V_110 ;
int V_90 ;
if ( F_10 ( V_113 < sizeof( * V_110 ) ) )
return 0 ;
if ( F_10 ( F_59 ( V_15 ) ) )
return - V_40 ;
V_110 = (struct V_114 * ) F_60 ( V_15 ) ;
V_53 -> V_68 . V_110 . V_115 = V_110 -> V_115 ;
V_113 -= sizeof( * V_110 ) ;
V_90 = 0 ;
while ( V_113 >= 8 ) {
struct V_116 * V_117 =
(struct V_116 * ) ( V_110 -> V_118 + V_90 ) ;
int V_119 = V_117 -> V_120 * 8 ;
if ( F_10 ( ! V_119 || V_119 > V_113 ) )
return 0 ;
if ( V_117 -> V_121 == V_122
&& V_119 == 8 ) {
if ( F_10 ( ! F_61 ( V_53 -> V_68 . V_110 . V_123 ) ) )
goto V_124;
F_62 ( V_53 -> V_68 . V_110 . V_123 ,
& V_110 -> V_118 [ V_90 + sizeof( * V_117 ) ] ) ;
} else if ( V_117 -> V_121 == V_125
&& V_119 == 8 ) {
if ( F_10 ( ! F_61 ( V_53 -> V_68 . V_110 . V_126 ) ) )
goto V_124;
F_62 ( V_53 -> V_68 . V_110 . V_126 ,
& V_110 -> V_118 [ V_90 + sizeof( * V_117 ) ] ) ;
}
V_113 -= V_119 ;
V_90 += V_119 ;
}
}
return 0 ;
V_124:
memset ( & V_53 -> V_68 . V_110 . V_115 , 0 , sizeof( V_53 -> V_68 . V_110 . V_115 ) ) ;
memset ( V_53 -> V_68 . V_110 . V_123 , 0 , sizeof( V_53 -> V_68 . V_110 . V_123 ) ) ;
memset ( V_53 -> V_68 . V_110 . V_126 , 0 , sizeof( V_53 -> V_68 . V_110 . V_126 ) ) ;
return 0 ;
}
static int F_63 ( struct V_14 * V_15 , struct V_52 * V_53 )
{
int error ;
struct V_127 * V_91 ;
V_53 -> V_107 . V_128 = 0 ;
F_64 ( V_15 ) ;
F_53 ( V_53 ) ;
if ( F_65 ( V_53 ) == V_129 ) {
if ( F_10 ( F_47 ( V_15 -> V_130 ) ) )
return - V_39 ;
F_66 ( V_15 ) ;
} else {
V_91 = F_67 ( V_15 ) ;
F_62 ( V_53 -> V_91 . V_73 , V_91 -> V_131 ) ;
F_62 ( V_53 -> V_91 . V_75 , V_91 -> V_132 ) ;
F_51 ( V_15 , 2 * V_133 ) ;
if ( F_10 ( F_54 ( V_15 , V_53 ) ) )
return - V_40 ;
V_15 -> V_130 = F_55 ( V_15 ) ;
if ( F_10 ( V_15 -> V_130 == F_44 ( 0 ) ) )
return - V_40 ;
F_66 ( V_15 ) ;
F_49 ( V_15 , V_15 -> V_61 - F_48 ( V_15 ) ) ;
}
F_68 ( V_15 ) ;
V_53 -> V_91 . type = V_15 -> V_130 ;
if ( V_53 -> V_91 . type == F_44 ( V_134 ) ) {
struct V_45 * V_57 ;
T_2 V_90 ;
error = F_30 ( V_15 ) ;
if ( F_10 ( error ) ) {
memset ( & V_53 -> V_62 , 0 , sizeof( V_53 -> V_62 ) ) ;
memset ( & V_53 -> V_135 , 0 , sizeof( V_53 -> V_135 ) ) ;
if ( error == - V_39 ) {
V_15 -> V_136 = V_15 -> V_137 ;
error = 0 ;
}
return error ;
}
V_57 = F_69 ( V_15 ) ;
V_53 -> V_135 . V_72 . V_73 = V_57 -> V_74 ;
V_53 -> V_135 . V_72 . V_75 = V_57 -> V_76 ;
V_53 -> V_62 . V_63 = V_57 -> V_130 ;
V_53 -> V_62 . V_65 = V_57 -> V_65 ;
V_53 -> V_62 . V_66 = V_57 -> V_66 ;
V_90 = V_57 -> V_59 & F_44 ( V_138 ) ;
if ( V_90 ) {
V_53 -> V_62 . V_77 = V_78 ;
return 0 ;
}
if ( V_57 -> V_59 & F_44 ( V_139 ) )
V_53 -> V_62 . V_77 = V_79 ;
else
V_53 -> V_62 . V_77 = V_80 ;
if ( V_53 -> V_62 . V_63 == V_140 ) {
if ( F_33 ( V_15 ) ) {
struct V_48 * V_141 = F_70 ( V_15 ) ;
V_53 -> V_107 . V_73 = V_141 -> V_142 ;
V_53 -> V_107 . V_75 = V_141 -> V_143 ;
V_53 -> V_107 . V_128 = F_71 ( V_141 ) ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
} else if ( V_53 -> V_62 . V_63 == V_144 ) {
if ( F_36 ( V_15 ) ) {
struct V_49 * V_145 = F_72 ( V_15 ) ;
V_53 -> V_107 . V_73 = V_145 -> V_142 ;
V_53 -> V_107 . V_75 = V_145 -> V_143 ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
} else if ( V_53 -> V_62 . V_63 == V_146 ) {
if ( F_37 ( V_15 ) ) {
struct V_50 * V_147 = F_73 ( V_15 ) ;
V_53 -> V_107 . V_73 = V_147 -> V_142 ;
V_53 -> V_107 . V_75 = V_147 -> V_143 ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
} else if ( V_53 -> V_62 . V_63 == V_148 ) {
if ( F_38 ( V_15 ) ) {
struct V_51 * V_106 = F_74 ( V_15 ) ;
V_53 -> V_107 . V_73 = F_44 ( V_106 -> type ) ;
V_53 -> V_107 . V_75 = F_44 ( V_106 -> V_149 ) ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
}
} else if ( V_53 -> V_91 . type == F_44 ( V_150 ) ||
V_53 -> V_91 . type == F_44 ( V_151 ) ) {
struct V_41 * V_152 ;
bool V_153 = F_28 ( V_15 ) ;
V_152 = (struct V_41 * ) F_75 ( V_15 ) ;
if ( V_153 &&
V_152 -> V_154 == F_44 ( V_155 ) &&
V_152 -> V_156 == F_44 ( V_134 ) &&
V_152 -> V_157 == V_133 &&
V_152 -> V_158 == 4 ) {
if ( F_76 ( V_152 -> V_159 ) <= 0xff )
V_53 -> V_62 . V_63 = F_76 ( V_152 -> V_159 ) ;
else
V_53 -> V_62 . V_63 = 0 ;
memcpy ( & V_53 -> V_135 . V_72 . V_73 , V_152 -> V_160 , sizeof( V_53 -> V_135 . V_72 . V_73 ) ) ;
memcpy ( & V_53 -> V_135 . V_72 . V_75 , V_152 -> V_161 , sizeof( V_53 -> V_135 . V_72 . V_75 ) ) ;
F_62 ( V_53 -> V_135 . V_152 . V_162 , V_152 -> V_163 ) ;
F_62 ( V_53 -> V_135 . V_152 . V_164 , V_152 -> V_165 ) ;
} else {
memset ( & V_53 -> V_62 , 0 , sizeof( V_53 -> V_62 ) ) ;
memset ( & V_53 -> V_135 , 0 , sizeof( V_53 -> V_135 ) ) ;
}
} else if ( F_77 ( V_53 -> V_91 . type ) ) {
T_5 V_166 = V_167 ;
F_78 ( V_15 , V_15 -> V_168 ) ;
while ( 1 ) {
V_70 V_169 ;
error = F_26 ( V_15 , V_15 -> V_168 + V_166 ) ;
if ( F_10 ( error ) )
return 0 ;
memcpy ( & V_169 , F_79 ( V_15 ) , V_167 ) ;
if ( V_166 == V_167 )
memcpy ( & V_53 -> V_170 . V_171 , & V_169 , V_167 ) ;
F_78 ( V_15 , V_15 -> V_168 + V_166 ) ;
if ( V_169 & F_42 ( V_172 ) )
break;
V_166 += V_167 ;
}
} else if ( V_53 -> V_91 . type == F_44 ( V_173 ) ) {
int V_54 ;
V_54 = F_39 ( V_15 , V_53 ) ;
if ( F_10 ( V_54 < 0 ) ) {
switch ( V_54 ) {
case - V_39 :
memset ( & V_53 -> V_62 , 0 , sizeof( V_53 -> V_62 ) ) ;
memset ( & V_53 -> V_68 . V_72 , 0 , sizeof( V_53 -> V_68 . V_72 ) ) ;
case - V_81 :
V_15 -> V_136 = V_15 -> V_137 ;
error = 0 ;
break;
default:
error = V_54 ;
}
return error ;
}
if ( V_53 -> V_62 . V_77 == V_78 )
return 0 ;
if ( V_53 -> V_62 . V_63 == V_174 ) {
if ( F_33 ( V_15 ) ) {
struct V_48 * V_141 = F_70 ( V_15 ) ;
V_53 -> V_107 . V_73 = V_141 -> V_142 ;
V_53 -> V_107 . V_75 = V_141 -> V_143 ;
V_53 -> V_107 . V_128 = F_71 ( V_141 ) ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
} else if ( V_53 -> V_62 . V_63 == V_175 ) {
if ( F_36 ( V_15 ) ) {
struct V_49 * V_145 = F_72 ( V_15 ) ;
V_53 -> V_107 . V_73 = V_145 -> V_142 ;
V_53 -> V_107 . V_75 = V_145 -> V_143 ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
} else if ( V_53 -> V_62 . V_63 == V_176 ) {
if ( F_37 ( V_15 ) ) {
struct V_50 * V_147 = F_73 ( V_15 ) ;
V_53 -> V_107 . V_73 = V_147 -> V_142 ;
V_53 -> V_107 . V_75 = V_147 -> V_143 ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
} else if ( V_53 -> V_62 . V_63 == V_177 ) {
if ( F_45 ( V_15 ) ) {
error = F_57 ( V_15 , V_53 , V_54 ) ;
if ( error )
return error ;
} else {
memset ( & V_53 -> V_107 , 0 , sizeof( V_53 -> V_107 ) ) ;
}
}
}
return 0 ;
}
int F_80 ( struct V_14 * V_15 , struct V_52 * V_53 )
{
int V_94 ;
V_94 = F_63 ( V_15 , V_53 ) ;
if ( ! V_94 )
V_53 -> V_178 &= ~ V_179 ;
return V_94 ;
}
static int F_81 ( struct V_14 * V_15 )
{
switch ( V_15 -> V_180 -> type ) {
case V_155 :
return V_181 ;
case V_182 :
if ( V_15 -> V_130 == F_44 ( V_183 ) )
return V_181 ;
return V_129 ;
}
F_82 ( 1 ) ;
return - V_39 ;
}
int F_83 ( const struct V_184 * V_185 ,
struct V_14 * V_15 , struct V_52 * V_53 )
{
int V_94 , V_44 ;
if ( V_185 ) {
V_53 -> V_186 = F_84 ( V_185 ) ;
memcpy ( & V_53 -> V_187 , & V_185 -> V_53 , sizeof( V_53 -> V_187 ) ) ;
if ( V_185 -> V_188 ) {
F_85 ( ( 1 << ( sizeof( V_185 -> V_188 ) *
8 ) ) - 1
> sizeof( V_53 -> V_189 ) ) ;
F_86 ( F_87 ( V_53 , V_185 -> V_188 ) ,
V_185 ) ;
V_53 -> V_190 = V_185 -> V_188 ;
} else {
V_53 -> V_190 = 0 ;
}
} else {
V_53 -> V_186 = 0 ;
V_53 -> V_190 = 0 ;
memset ( & V_53 -> V_187 , 0 , sizeof( V_53 -> V_187 ) ) ;
}
V_53 -> V_191 . V_192 = V_15 -> V_192 ;
V_53 -> V_191 . V_193 = F_88 ( V_15 ) -> V_194 -> V_195 ;
V_53 -> V_191 . V_196 = V_15 -> V_197 ;
V_53 -> V_198 = 0 ;
V_94 = F_81 ( V_15 ) ;
if ( V_94 < 0 )
return V_94 ;
V_53 -> V_178 = V_94 ;
V_53 -> V_199 = 0 ;
V_44 = F_63 ( V_15 , V_53 ) ;
if ( ! V_44 )
F_89 ( V_15 , V_53 ) ;
return V_44 ;
}
int F_90 ( struct V_200 * V_200 , const struct V_201 * V_202 ,
struct V_14 * V_15 ,
struct V_52 * V_53 , bool log )
{
const struct V_201 * V_203 [ V_204 + 1 ] ;
T_1 V_205 = 0 ;
int V_44 ;
V_44 = F_91 ( V_202 , V_203 , & V_205 , log ) ;
if ( V_44 )
return - V_39 ;
V_44 = F_92 ( V_200 , V_203 , V_205 , V_53 , log ) ;
if ( V_44 )
return V_44 ;
V_15 -> V_130 = V_53 -> V_91 . type ;
V_44 = F_63 ( V_15 , V_53 ) ;
if ( V_44 )
return V_44 ;
if ( V_205 & ( 1 << V_206 ) &&
V_53 -> V_91 . type != F_44 ( V_134 ) )
return - V_39 ;
if ( V_205 & ( 1 << V_207 ) &&
( V_53 -> V_91 . type != F_44 ( V_173 ) ||
F_93 ( V_53 ) ) )
return - V_39 ;
return 0 ;
}
