static T_1 F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
unsigned long V_5 = 0 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_3 , V_1 ) ;
if ( V_1 >= V_8 ) {
V_5 = F_3 ( ( void * ) V_1 ) ;
} else if ( V_7 && ( V_7 -> V_9 & V_10 ) && ( V_7 -> V_11 ) ) {
V_5 = ( V_7 -> V_11 << V_12 ) + ( V_1 - V_7 -> V_13 ) ;
} else {
int V_14 , V_15 = 1 ;
struct V_16 * V_17 ;
F_4 ( & V_4 -> V_3 -> V_18 ) ;
V_14 = F_5 ( V_4 , V_4 -> V_3 ,
V_1 , V_15 , 1 , 0 , & V_17 , NULL ) ;
F_6 ( & V_4 -> V_3 -> V_18 ) ;
if ( V_14 == V_15 ) {
V_5 = F_7 ( F_8 ( & V_17 [ 0 ] ) +
( V_1 & ~ V_19 ) ) ;
} else {
F_9 ( L_1 ) ;
return 0 ;
}
}
return V_5 ;
}
static int F_10 ( struct V_20 * V_21 ,
struct V_22 * V_23 ,
enum V_24 V_25 )
{
struct V_26 * V_27 = V_21 -> V_28 ;
struct V_29 * V_30 ;
unsigned long V_31 ;
V_30 = & V_27 -> V_32 -> V_30 [ V_33 ] ;
if ( V_34 == V_23 -> V_35 ) {
V_23 -> V_36 = V_30 -> V_36 ;
V_23 -> V_37 = V_30 -> V_37 ;
V_23 -> V_38 = V_23 -> V_36 * V_23 -> V_37 ;
V_23 -> V_25 = V_25 ;
}
V_23 -> V_35 = V_39 ;
if ( V_40 == V_30 -> V_41 ) {
if ( ! V_23 -> V_42 ) {
F_9 ( L_2 ) ;
return - V_43 ;
}
V_23 -> V_44 = F_1 ( V_23 -> V_42 ) ;
if ( ! F_11 ( V_23 -> V_44 ) )
goto V_45;
}
V_31 = V_23 -> V_44 ;
if ( V_21 -> V_46 && ( V_47 != V_21 -> type ) ) {
if ( ! F_11 ( V_31 + V_30 -> V_48 ) ||
! F_11 ( V_31 + V_30 -> V_49 ) ||
! F_11 ( V_31 + V_30 -> V_50 ) ||
! F_11 ( V_31 + V_30 -> V_51 ) )
goto V_45;
}
return 0 ;
V_45:
F_9 ( L_3 ) ;
return - V_43 ;
}
static int F_12 ( struct V_20 * V_21 , unsigned int * V_52 ,
unsigned int * V_38 )
{
struct V_26 * V_27 = V_21 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_55 != V_30 -> V_41 )
return 0 ;
* V_38 = V_56 . V_57 [ V_54 -> V_58 ] ;
if ( * V_52 < V_56 . V_59 )
* V_52 = V_56 . V_59 ;
return 0 ;
}
static void F_13 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = V_21 -> V_28 ;
struct V_29 * V_30 ;
V_30 = & V_27 -> V_32 -> V_30 [ V_33 ] ;
F_14 ( & V_23 -> V_60 , & V_30 -> V_61 ) ;
V_23 -> V_35 = V_62 ;
}
static void F_15 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
struct V_26 * V_27 = V_21 -> V_28 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 ;
unsigned int V_63 = 0 ;
V_30 = & V_54 -> V_30 [ V_33 ] ;
F_16 ( V_21 , V_23 ) ;
V_23 -> V_35 = V_34 ;
if ( V_55 != V_30 -> V_41 )
return;
V_63 = V_56 . V_57 [ V_54 -> V_58 ] ;
}
static void F_17 ( struct V_29 * V_30 )
{
unsigned long V_31 = 0 ;
V_30 -> V_64 = F_18 ( V_30 -> V_61 . V_65 ,
struct V_22 , V_60 ) ;
F_19 ( & V_30 -> V_64 -> V_60 ) ;
V_30 -> V_64 -> V_35 = V_66 ;
V_31 = F_20 ( V_30 -> V_64 ) ;
V_30 -> V_67 ( V_31 + V_30 -> V_48 ,
V_31 + V_30 -> V_49 ,
V_31 + V_30 -> V_50 ,
V_31 + V_30 -> V_51 ) ;
}
static void F_21 ( int V_68 , struct V_29 * V_30 )
{
if ( 0 == V_68 ) {
if ( V_30 -> V_69 == V_30 -> V_64 )
return;
F_22 ( & V_30 -> V_69 -> V_70 ) ;
V_30 -> V_69 -> V_35 = V_71 ;
F_23 ( & V_30 -> V_69 -> V_72 ) ;
V_30 -> V_69 = V_30 -> V_64 ;
} else if ( 1 == V_68 ) {
if ( F_24 ( & V_30 -> V_61 )
|| ( V_30 -> V_69 != V_30 -> V_64 ) ) {
return;
}
F_17 ( V_30 ) ;
}
}
static T_2 F_25 ( int V_73 , void * V_74 )
{
struct V_75 * V_76 = & V_77 ;
struct V_53 * V_54 ;
struct V_29 * V_30 ;
enum V_24 V_25 ;
int V_68 = - 1 , V_78 ;
int V_58 = 0 ;
V_58 = * ( int * ) ( V_74 ) ;
V_54 = V_76 -> V_76 [ V_58 ] ;
V_25 = V_54 -> V_30 [ V_33 ] . V_79 . V_79 . V_80 . V_25 ;
for ( V_78 = 0 ; V_78 < V_81 ; V_78 ++ ) {
V_30 = & V_54 -> V_30 [ V_78 ] ;
if ( 0 == V_30 -> V_82 )
continue;
if ( 1 == V_54 -> V_83 . V_84 . V_85 ) {
if ( F_24 ( & V_30 -> V_61 ) )
continue;
if ( ! V_86 [ V_78 ] [ V_58 ] ) {
F_22 ( & V_30 -> V_69 -> V_70 ) ;
V_30 -> V_69 -> V_35 = V_71 ;
F_23 ( & V_30 -> V_69 -> V_72 ) ;
V_30 -> V_69 = V_30 -> V_64 ;
}
V_86 [ V_78 ] [ V_58 ] = 0 ;
F_17 ( V_30 ) ;
} else {
if ( V_86 [ V_78 ] [ V_58 ] ) {
V_86 [ V_78 ] [ V_58 ] = 0 ;
continue;
}
if ( 0 == V_78 ) {
V_54 -> V_87 ^= 1 ;
V_68 = F_26 ( V_54 -> V_58 + 2 ) ;
if ( V_68 != V_54 -> V_87 ) {
if ( 0 == V_68 )
V_54 -> V_87 = V_68 ;
return V_88 ;
}
}
F_21 ( V_68 , V_30 ) ;
}
}
return V_88 ;
}
static int F_27 ( struct V_53 * V_54 )
{
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_92 * V_83 = & V_54 -> V_83 ;
struct V_93 * V_84 = & V_83 -> V_84 ;
const struct V_93 * V_94 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_95 ; V_78 ++ ) {
V_94 = & V_96 [ V_78 ] ;
if ( V_94 -> V_97 == 0 ) {
F_28 ( 2 , V_98 , L_4 ) ;
if ( V_94 -> V_99 & V_90 -> V_99 ) {
memcpy ( V_84 , V_94 , sizeof( * V_94 ) ) ;
break;
}
} else {
F_28 ( 2 , V_98 , L_5 ) ;
if ( V_94 -> V_100 == V_90 -> V_100 ) {
memcpy ( V_84 , V_94 , sizeof( * V_94 ) ) ;
break;
}
}
}
if ( V_78 == V_95 ) {
F_28 ( 1 , V_98 , L_6 ) ;
return - V_43 ;
}
return 0 ;
}
static int F_29 ( struct V_53 * V_54 )
{
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_92 * V_83 = & V_54 -> V_83 ;
struct V_93 * V_84 = & V_83 -> V_84 ;
if ( ! V_90 -> V_99 && ! V_90 -> V_100 && ! V_90 -> V_101 . V_37 )
return - V_43 ;
if ( V_90 -> V_99 || V_90 -> V_100 ) {
if ( F_27 ( V_54 ) )
return - V_43 ;
}
V_30 -> V_79 . V_79 . V_80 . V_36 = V_84 -> V_36 ;
V_30 -> V_79 . V_79 . V_80 . V_37 = V_84 -> V_37 ;
F_28 ( 1 , V_98 , L_7 ,
V_30 -> V_79 . V_79 . V_80 . V_36 , V_30 -> V_79 . V_79 . V_80 . V_37 ) ;
V_30 -> V_37 = V_84 -> V_37 ;
V_30 -> V_36 = V_84 -> V_36 ;
return 0 ;
}
static void F_30 ( struct V_53 * V_54 )
{
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_92 * V_83 = & V_54 -> V_83 ;
enum V_24 V_25 = V_30 -> V_79 . V_79 . V_80 . V_25 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
unsigned int V_102 , V_103 , V_104 ;
if ( V_105 == V_30 -> V_79 . V_79 . V_80 . V_25 ) {
if ( V_54 -> V_83 . V_84 . V_85 )
V_90 -> V_106 = V_107 ;
else
V_90 -> V_106 = V_108 ;
} else {
V_90 -> V_106 = V_30 -> V_79 . V_79 . V_80 . V_25 ;
}
if ( V_40 == V_30 -> V_41 )
V_104 = V_30 -> V_79 . V_79 . V_80 . V_104 ;
else
V_104 = V_56 . V_57 [ V_54 -> V_58 ] ;
V_102 = V_30 -> V_79 . V_79 . V_80 . V_109 ;
V_103 = V_104 / ( V_102 * 2 ) ;
if ( ( V_107 == V_90 -> V_106 ) ||
( V_108 == V_90 -> V_106 ) ) {
V_30 -> V_48 = 0 ;
V_30 -> V_49 = V_102 ;
V_30 -> V_50 = V_104 / 2 ;
V_30 -> V_51 = V_104 / 2 + V_102 ;
} else if ( V_110 == V_90 -> V_106 ) {
V_30 -> V_48 = 0 ;
V_30 -> V_49 = V_104 / 4 ;
V_30 -> V_50 = V_104 / 2 ;
V_30 -> V_51 = V_30 -> V_50 + V_104 / 4 ;
} else if ( V_111 == V_90 -> V_106 ) {
V_30 -> V_49 = 0 ;
V_30 -> V_48 = V_104 / 4 ;
V_30 -> V_51 = V_104 / 2 ;
V_30 -> V_50 = V_30 -> V_51 + V_104 / 4 ;
}
if ( ( V_107 == V_90 -> V_106 ) ||
( V_108 == V_90 -> V_106 ) ) {
V_83 -> V_112 . V_113 = 1 ;
} else {
V_83 -> V_112 . V_113 = 0 ;
}
if ( V_54 -> V_83 . V_84 . V_85 == 1 ) {
V_83 -> V_112 . V_102 =
V_30 -> V_79 . V_79 . V_80 . V_109 ;
} else {
if ( ( V_25 == V_105 ) ||
( V_25 == V_108 ) )
V_83 -> V_112 . V_102 =
V_30 -> V_79 . V_79 . V_80 . V_109 * 2 ;
else
V_83 -> V_112 . V_102 =
V_30 -> V_79 . V_79 . V_80 . V_109 ;
}
V_54 -> V_83 . V_112 . V_99 = V_54 -> V_83 . V_84 . V_99 ;
}
static void F_31 ( struct V_53 * V_54 )
{
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
V_30 -> V_79 . V_79 . V_80 . V_25 = V_105 ;
if ( V_56 . V_114 [ V_54 -> V_58 ] == 0 )
V_30 -> V_41 = V_40 ;
else
V_30 -> V_41 = V_55 ;
V_30 -> V_79 . V_79 . V_80 . V_104 =
V_56 . V_57 [ V_54 -> V_58 ] ;
V_30 -> V_79 . V_79 . V_80 . V_115 = V_116 ;
V_30 -> V_79 . type = V_117 ;
}
static int F_32 ( struct V_53 * V_54 ,
struct V_118 * V_119 )
{
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
enum V_24 V_25 = V_119 -> V_25 ;
T_1 V_104 , V_102 , V_103 ;
if ( V_119 -> V_115 != V_116 )
goto V_120;
if ( ! ( F_33 ( V_25 ) ) )
goto V_120;
if ( V_119 -> V_109 <= 0 )
goto V_121;
if ( V_40 == V_30 -> V_41 )
V_104 = V_119 -> V_104 ;
else
V_104 = V_56 . V_57 [ V_54 -> V_58 ] ;
if ( F_29 ( V_54 ) )
return - V_43 ;
V_102 = V_119 -> V_109 ;
V_103 = V_104 / ( V_102 * 2 ) ;
if ( ( V_102 < V_54 -> V_83 . V_84 . V_36 ) ||
( V_103 < V_54 -> V_83 . V_84 . V_37 ) )
goto V_121;
if ( ! F_11 ( V_102 ) ) {
F_9 ( L_8 ) ;
return - V_43 ;
}
V_119 -> V_36 = V_30 -> V_79 . V_79 . V_80 . V_36 ;
V_119 -> V_37 = V_30 -> V_79 . V_79 . V_80 . V_37 ;
return 0 ;
V_120:
F_9 ( L_9 ) ;
return - V_43 ;
V_121:
F_9 ( L_10 ) ;
return - V_43 ;
}
static void F_34 ( struct V_53 * V_54 , int V_122 )
{
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_123 == V_54 -> V_58 ) {
V_30 -> V_67 = V_124 ;
} else {
if ( 2 == V_122 )
V_30 -> V_67 = V_125 ;
else
V_30 -> V_67 = V_126 ;
}
}
static int F_35 ( struct V_127 * V_128 , struct V_6 * V_7 )
{
struct V_26 * V_27 = V_128 -> V_129 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & ( V_54 -> V_30 [ V_33 ] ) ;
F_28 ( 2 , V_98 , L_11 ) ;
return F_36 ( & V_30 -> V_130 , V_7 ) ;
}
static unsigned int F_37 ( struct V_127 * V_128 , T_3 * V_131 )
{
struct V_26 * V_27 = V_128 -> V_129 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_30 -> V_82 )
return F_38 ( V_128 , & V_30 -> V_130 , V_131 ) ;
return 0 ;
}
static int F_39 ( struct V_127 * V_128 )
{
struct V_132 * V_133 = F_40 ( V_128 ) ;
struct V_53 * V_54 = NULL ;
struct V_26 * V_27 = NULL ;
V_54 = F_41 ( V_133 ) ;
V_27 = F_42 ( sizeof( struct V_26 ) , V_134 ) ;
if ( V_27 == NULL ) {
F_9 ( L_12 ) ;
return - V_135 ;
}
V_128 -> V_129 = V_27 ;
V_27 -> V_32 = V_54 ;
V_27 -> V_136 = 0 ;
if ( ! V_54 -> V_136 ) {
V_27 -> V_136 = 1 ;
V_54 -> V_136 = 1 ;
memset ( & V_54 -> V_83 , 0 , sizeof( V_54 -> V_83 ) ) ;
}
F_43 ( & V_54 -> V_137 ) ;
V_27 -> V_138 [ V_33 ] = 0 ;
V_27 -> V_139 = V_140 ;
F_44 ( & V_54 -> V_139 , & V_27 -> V_139 ) ;
return 0 ;
}
static int F_45 ( struct V_127 * V_128 )
{
struct V_26 * V_27 = V_128 -> V_129 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_27 -> V_138 [ V_33 ] ) {
V_30 -> V_141 = 0 ;
if ( V_142 == V_54 -> V_58 ) {
F_46 ( 0 ) ;
F_47 ( 0 ) ;
}
if ( ( V_123 == V_54 -> V_58 ) ||
( 2 == V_30 -> V_82 ) ) {
F_48 ( 0 ) ;
F_49 ( 0 ) ;
}
V_30 -> V_82 = 0 ;
F_50 ( & V_30 -> V_130 ) ;
F_51 ( & V_30 -> V_130 ) ;
V_30 -> V_114 =
V_56 . V_114 [ V_54 -> V_58 ] ;
}
F_52 ( & V_54 -> V_137 ) ;
if ( V_27 -> V_136 )
V_54 -> V_136 = 0 ;
F_53 ( & V_54 -> V_139 , V_27 -> V_139 ) ;
V_128 -> V_129 = NULL ;
V_27 -> V_136 = 0 ;
F_54 ( V_27 ) ;
return 0 ;
}
static int F_55 ( struct V_127 * V_127 , void * V_143 ,
struct V_144 * V_145 )
{
struct V_146 * V_94 = V_147 -> V_148 ;
V_145 -> V_149 = V_150 ;
V_145 -> V_151 = V_152 | V_153 ;
F_56 ( V_145 -> V_154 , L_13 , sizeof( V_145 -> V_154 ) ) ;
F_56 ( V_145 -> V_155 , L_14 , sizeof( V_145 -> V_155 ) ) ;
F_56 ( V_145 -> V_156 , V_94 -> V_157 , sizeof( V_145 -> V_156 ) ) ;
return 0 ;
}
static int F_57 ( struct V_127 * V_127 , void * V_143 ,
struct V_158 * V_79 )
{
if ( V_79 -> V_159 != 0 ) {
F_9 ( L_15 ) ;
return - V_43 ;
}
V_79 -> type = V_117 ;
strcpy ( V_79 -> V_160 , L_16 ) ;
V_79 -> V_115 = V_116 ;
return 0 ;
}
static int F_58 ( struct V_127 * V_127 , void * V_143 ,
struct V_161 * V_79 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_30 -> V_79 . type != V_79 -> type )
return - V_43 ;
if ( F_29 ( V_54 ) )
return - V_43 ;
* V_79 = V_30 -> V_79 ;
return 0 ;
}
static int F_59 ( struct V_127 * V_127 , void * V_143 ,
struct V_161 * V_79 )
{
struct V_26 * V_27 = V_143 ;
struct V_118 * V_119 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
int V_162 = 0 ;
if ( ( V_142 == V_54 -> V_58 )
|| ( V_123 == V_54 -> V_58 ) ) {
if ( ! V_27 -> V_136 ) {
F_28 ( 1 , V_98 , L_17 ) ;
return - V_163 ;
}
V_162 = F_60 ( & V_54 -> V_139 , V_27 -> V_139 ) ;
if ( 0 != V_162 )
return V_162 ;
V_27 -> V_136 = 1 ;
}
if ( V_30 -> V_82 ) {
F_28 ( 1 , V_98 , L_18 ) ;
return - V_163 ;
}
V_119 = & V_79 -> V_79 . V_80 ;
V_162 = F_32 ( V_54 , V_119 ) ;
if ( V_162 )
return V_162 ;
V_30 -> V_79 . V_79 . V_80 = * V_119 ;
V_30 -> V_79 = * V_79 ;
return 0 ;
}
static int F_61 ( struct V_127 * V_127 , void * V_143 ,
struct V_161 * V_79 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_118 * V_119 = & V_79 -> V_79 . V_80 ;
int V_162 = 0 ;
V_162 = F_32 ( V_54 , V_119 ) ;
if ( V_162 ) {
* V_119 = V_30 -> V_79 . V_79 . V_80 ;
V_119 -> V_104 = V_119 -> V_36 * V_119 -> V_37 * 2 ;
}
return V_162 ;
}
static int F_62 ( struct V_127 * V_127 , void * V_143 ,
struct V_164 * V_165 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 ;
enum V_24 V_25 ;
T_4 V_159 = 0 ;
if ( ( V_142 == V_54 -> V_58 )
|| ( V_123 == V_54 -> V_58 ) ) {
if ( ! V_27 -> V_136 ) {
F_9 ( L_17 ) ;
return - V_163 ;
}
}
if ( V_117 != V_165 -> type )
return - V_43 ;
V_159 = V_33 ;
V_30 = & V_54 -> V_30 [ V_159 ] ;
if ( V_30 -> V_79 . type != V_165 -> type )
return - V_43 ;
if ( 0 != V_30 -> V_141 )
return - V_163 ;
if ( V_165 -> type == V_117 ) {
if ( V_30 -> V_79 . V_79 . V_80 . V_25 == V_105 )
V_25 = V_108 ;
else
V_25 = V_30 -> V_79 . V_79 . V_80 . V_25 ;
} else {
V_25 = V_166 ;
}
F_63 ( & V_30 -> V_130 ,
& V_167 , NULL ,
& V_30 -> V_168 ,
V_165 -> type , V_25 ,
sizeof( struct V_22 ) , V_27 ,
& V_30 -> V_169 ) ;
V_27 -> V_138 [ V_159 ] = 1 ;
V_30 -> V_141 = 1 ;
V_30 -> V_41 = V_165 -> V_41 ;
F_64 ( & V_30 -> V_61 ) ;
return F_65 ( & V_30 -> V_130 , V_165 ) ;
}
static int F_66 ( struct V_127 * V_127 , void * V_143 ,
struct V_170 * V_171 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_30 -> V_79 . type != V_171 -> type )
return - V_43 ;
return F_67 ( & V_30 -> V_130 , V_171 ) ;
}
static int F_68 ( struct V_127 * V_127 , void * V_143 , struct V_170 * V_172 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_170 V_171 = * V_172 ;
struct V_22 * V_173 ;
unsigned long V_31 = 0 ;
unsigned long V_174 ;
int V_162 = 0 ;
if ( V_30 -> V_79 . type != V_171 . type )
return - V_43 ;
if ( ! V_27 -> V_138 [ V_33 ] ) {
F_9 ( L_19 ) ;
return - V_175 ;
}
if ( ! ( F_24 ( & V_30 -> V_61 ) ) ||
( V_30 -> V_69 != V_30 -> V_64 ) ||
! ( V_30 -> V_82 ) ||
( V_30 -> V_82 && ( 0 == V_54 -> V_87 ) ) )
return F_69 ( & V_30 -> V_130 , V_172 ) ;
F_70 ( & V_30 -> V_130 . V_176 ) ;
V_173 = V_30 -> V_130 . V_177 [ V_171 . V_159 ] ;
if ( V_173 -> V_41 != V_171 . V_41 ) {
F_9 ( L_20 ) ;
goto V_178;
}
if ( ( V_173 -> V_35 == V_62 ) ||
( V_173 -> V_35 == V_66 ) ) {
F_9 ( L_21 ) ;
goto V_178;
}
switch ( V_173 -> V_41 ) {
case V_55 :
if ( V_173 -> V_42 == 0 )
goto V_178;
break;
case V_40 :
if ( V_171 . V_179 < V_173 -> V_180 )
goto V_178;
if ( ( V_34 != V_173 -> V_35 )
&& ( V_173 -> V_42 != V_171 . V_181 . V_182 ) ) {
F_15 ( & V_30 -> V_130 , V_173 ) ;
V_173 -> V_42 = V_171 . V_181 . V_182 ;
}
break;
default:
goto V_178;
}
F_71 ( V_174 ) ;
V_162 = F_10 ( & V_30 -> V_130 , V_173 ,
V_30 -> V_130 . V_25 ) ;
if ( V_162 < 0 ) {
F_72 ( V_174 ) ;
goto V_178;
}
V_173 -> V_35 = V_66 ;
V_31 = V_173 -> V_44 ;
V_30 -> V_64 = V_173 ;
if ( V_171 . type != V_47 ) {
V_30 -> V_67 ( ( V_31 + V_30 -> V_48 ) ,
( V_31 + V_30 -> V_49 ) ,
( V_31 + V_30 -> V_50 ) ,
( V_31 + V_30 -> V_51 ) ) ;
}
F_72 ( V_174 ) ;
F_14 ( & V_173 -> V_183 , & V_30 -> V_130 . V_183 ) ;
F_73 ( & V_30 -> V_130 . V_176 ) ;
return 0 ;
V_178:
F_73 ( & V_30 -> V_130 . V_176 ) ;
return - V_43 ;
}
static int F_74 ( struct V_127 * V_127 , void * V_143 , T_5 * V_184 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
int V_162 = 0 ;
if ( ! ( * V_184 & V_185 ) )
return - V_43 ;
if ( V_30 -> V_82 ) {
F_9 ( L_22 ) ;
return - V_163 ;
}
V_54 -> V_91 . V_99 = * V_184 ;
V_54 -> V_91 . V_100 = V_186 ;
memset ( & V_54 -> V_91 . V_101 , 0 , sizeof( V_54 -> V_91 . V_101 ) ) ;
if ( F_29 ( V_54 ) )
return - V_43 ;
if ( ( V_54 -> V_83 . V_84 . V_36 *
V_54 -> V_83 . V_84 . V_37 * 2 ) >
V_56 . V_57 [ V_54 -> V_58 ] ) {
F_9 ( L_23 ) ;
return - V_43 ;
}
V_30 -> V_79 . V_79 . V_80 . V_109 = V_30 -> V_79 . V_79 . V_80 . V_36 ;
F_31 ( V_54 ) ;
V_162 = F_75 ( & V_77 . V_187 , 1 , V_91 ,
V_188 , * V_184 ) ;
if ( V_162 < 0 ) {
F_9 ( L_24 ) ;
return V_162 ;
}
V_162 = F_75 ( & V_77 . V_187 , 1 , V_189 ,
V_190 , * V_184 ) ;
if ( V_162 < 0 )
F_9 ( L_25 ) ;
return V_162 ;
}
static int F_76 ( struct V_127 * V_127 , void * V_143 , T_5 * V_191 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
* V_191 = V_54 -> V_91 . V_99 ;
return 0 ;
}
static int F_77 ( struct V_127 * V_127 , void * V_143 , struct V_170 * V_192 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
return F_78 ( & V_30 -> V_130 , V_192 ,
( V_127 -> V_193 & V_194 ) ) ;
}
static int F_79 ( struct V_127 * V_127 , void * V_143 ,
enum V_195 V_196 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_53 * V_197 = V_77 . V_76 [ ! V_54 -> V_58 ] ;
struct V_92 * V_198 = & V_54 -> V_83 ;
struct V_146 * V_199 =
V_147 -> V_148 ;
unsigned long V_31 = 0 ;
int V_162 = 0 ;
if ( V_196 != V_117 ) {
F_9 ( L_26 ) ;
return - V_43 ;
}
if ( ! V_27 -> V_138 [ V_33 ] ) {
F_9 ( L_19 ) ;
return - V_175 ;
}
if ( V_30 -> V_82 ) {
F_9 ( L_27 ) ;
return - V_163 ;
}
if ( ( V_54 -> V_58 == V_142
&& V_197 -> V_30 [ V_33 ] . V_82 &&
V_54 -> V_83 . V_84 . V_200 == 0 )
|| ( ( V_54 -> V_58 == V_123 )
&& ( 2 == V_197 -> V_30 [ V_33 ] . V_82 ) ) ) {
F_9 ( L_28 ) ;
return - V_163 ;
}
V_162 = F_32 ( V_54 , & V_30 -> V_79 . V_79 . V_80 ) ;
if ( V_162 < 0 )
return V_162 ;
V_162 = F_80 ( & V_30 -> V_130 ) ;
if ( V_162 < 0 ) {
F_9 ( L_29 ) ;
return V_162 ;
}
if ( F_24 ( & V_30 -> V_61 ) ) {
F_9 ( L_30 ) ;
return - V_201 ;
}
V_30 -> V_64 = V_30 -> V_69 =
F_18 ( V_30 -> V_61 . V_65 ,
struct V_22 , V_60 ) ;
F_19 ( & V_30 -> V_69 -> V_60 ) ;
V_30 -> V_69 -> V_35 = V_66 ;
V_54 -> V_87 = 0 ;
V_30 -> V_82 = 1 ;
if ( V_196 == V_117 ) {
V_31 = V_30 -> V_69 -> V_44 ;
F_30 ( V_54 ) ;
if ( ( V_54 -> V_83 . V_84 . V_85 &&
( ( V_30 -> V_79 . V_79 . V_80 . V_25 != V_107 )
&& ( V_30 -> V_79 . V_79 . V_80 . V_25 != V_105 ) ) )
|| ( ! V_54 -> V_83 . V_84 . V_85
&& ( V_30 -> V_79 . V_79 . V_80 . V_25 == V_107 ) ) ) {
F_9 ( L_31 ) ;
return - V_43 ;
}
V_162 =
V_199 -> V_202 ( V_54 -> V_83 . V_84 . V_200 ,
V_54 -> V_83 . V_84 . V_97 ) ;
if ( V_162 < 0 ) {
F_9 ( L_32 ) ;
return V_162 ;
}
V_162 = F_81 ( V_198 , V_54 -> V_58 + 2 ) ;
if ( V_162 < 0 )
return V_162 ;
V_30 -> V_82 = V_162 ;
F_34 ( V_54 , V_162 ) ;
V_30 -> V_67 ( ( V_31 + V_30 -> V_48 ) ,
( V_31 + V_30 -> V_49 ) ,
( V_31 + V_30 -> V_50 ) ,
( V_31 + V_30 -> V_51 ) ) ;
if ( V_142 == V_54 -> V_58 ) {
F_82 () ;
F_47 ( 1 ) ;
F_46 ( 1 ) ;
}
if ( ( V_123 == V_54 -> V_58 )
|| ( V_30 -> V_82 == 2 ) ) {
F_83 () ;
F_49 ( 1 ) ;
F_48 ( 1 ) ;
}
V_86 [ V_33 ] [ V_54 -> V_58 ] = 1 ;
}
return V_162 ;
}
static int F_84 ( struct V_127 * V_127 , void * V_143 ,
enum V_195 V_196 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_196 != V_117 ) {
F_9 ( L_26 ) ;
return - V_43 ;
}
if ( ! V_27 -> V_138 [ V_33 ] ) {
F_9 ( L_19 ) ;
return - V_175 ;
}
if ( ! V_30 -> V_82 ) {
F_9 ( L_27 ) ;
return - V_43 ;
}
if ( V_196 == V_117 ) {
if ( V_142 == V_54 -> V_58 ) {
F_46 ( 0 ) ;
F_47 ( 0 ) ;
}
if ( ( V_123 == V_54 -> V_58 ) ||
( 2 == V_30 -> V_82 ) ) {
F_48 ( 0 ) ;
F_49 ( 0 ) ;
}
}
V_30 -> V_82 = 0 ;
return F_85 ( & V_30 -> V_130 ) ;
}
static int F_86 ( struct V_127 * V_127 , void * V_143 ,
struct V_203 * V_204 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_117 != V_204 -> type )
return - V_43 ;
V_204 -> V_205 . V_206 = V_204 -> V_205 . V_207 = 0 ;
V_204 -> V_208 . V_206 = V_204 -> V_208 . V_207 = 0 ;
V_204 -> V_208 . V_37 = V_204 -> V_205 . V_37 = V_30 -> V_37 ;
V_204 -> V_208 . V_36 = V_204 -> V_205 . V_36 = V_30 -> V_36 ;
return 0 ;
}
static int F_87 ( struct V_127 * V_127 , void * V_27 ,
struct V_209 * V_210 )
{
struct V_146 * V_94 = V_147 -> V_148 ;
if ( V_210 -> V_159 >= V_94 -> V_211 ) {
F_28 ( 1 , V_98 , L_33 ) ;
return - V_43 ;
}
strcpy ( V_210 -> V_212 , V_94 -> V_210 [ V_210 -> V_159 ] ) ;
V_210 -> type = V_213 ;
V_210 -> V_191 = V_185 ;
return 0 ;
}
static int F_88 ( struct V_127 * V_127 , void * V_143 , unsigned int V_78 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
int V_162 = 0 ;
if ( V_30 -> V_82 ) {
F_9 ( L_18 ) ;
return - V_163 ;
}
V_162 = F_75 ( & V_77 . V_187 , 1 , V_91 ,
V_214 , 0 , V_78 , 0 ) ;
if ( V_162 < 0 )
F_9 ( L_24 ) ;
V_90 -> V_215 = V_78 ;
return V_162 ;
}
static int F_89 ( struct V_127 * V_127 , void * V_143 , unsigned int * V_78 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
* V_78 = V_90 -> V_215 ;
return 0 ;
}
static int F_90 ( struct V_127 * V_127 , void * V_143 , enum V_216 * V_192 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
* V_192 = F_91 ( & V_54 -> V_139 ) ;
return 0 ;
}
static int F_92 ( struct V_127 * V_127 , void * V_143 , enum V_216 V_192 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
return F_93 ( & V_54 -> V_139 , & V_27 -> V_139 , V_192 ) ;
}
static int F_94 ( struct V_127 * V_127 , void * V_143 ,
struct V_217 * V_218 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
return F_95 ( V_77 . V_219 [ V_90 -> V_215 ] ,
V_91 , V_220 , V_218 ) ;
}
static int F_96 ( struct V_127 * V_127 , void * V_143 ,
struct V_221 * V_218 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_89 * V_90 = & V_54 -> V_91 ;
int V_162 = 0 ;
if ( V_30 -> V_82 ) {
F_28 ( 1 , V_98 , L_22 ) ;
return - V_163 ;
}
V_162 = F_60 ( & V_54 -> V_139 , V_27 -> V_139 ) ;
if ( V_162 != 0 )
return V_162 ;
V_27 -> V_136 = 1 ;
if ( F_97 ( & V_30 -> V_169 ) )
return - V_222 ;
V_54 -> V_91 . V_100 = V_218 -> V_218 ;
V_54 -> V_91 . V_99 = V_223 ;
memset ( & V_54 -> V_91 . V_101 , 0 , sizeof( V_54 -> V_91 . V_101 ) ) ;
if ( F_29 ( V_54 ) ) {
V_162 = - V_43 ;
} else {
F_31 ( V_54 ) ;
V_162 = F_95 ( V_77 . V_219 [ V_90 -> V_215 ] ,
V_91 , V_224 , V_218 ) ;
}
F_73 ( & V_30 -> V_169 ) ;
return V_162 ;
}
static int F_98 ( struct V_127 * V_127 , void * V_143 ,
struct V_221 * V_218 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
V_218 -> V_218 = V_54 -> V_91 . V_100 ;
return 0 ;
}
static int F_99 ( struct V_127 * V_127 , void * V_143 ,
struct V_225 * V_226 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_92 * V_83 = & V_54 -> V_83 ;
struct V_93 * V_84 = & V_83 -> V_84 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_227 * V_228 = & V_90 -> V_101 ;
int V_162 ;
if ( V_226 -> type != V_229 ) {
F_28 ( 2 , V_98 , L_34 ) ;
return - V_43 ;
}
V_162 = F_95 ( V_77 . V_219 [ V_90 -> V_215 ] ,
V_91 , V_230 , V_226 ) ;
if ( V_162 == - V_231 ) {
F_28 ( 2 , V_98 , L_35
L_36 ) ;
return - V_43 ;
}
if ( V_162 < 0 ) {
F_28 ( 2 , V_98 , L_37 ) ;
return V_162 ;
}
if ( ! ( V_226 -> V_228 . V_36 && V_226 -> V_228 . V_37 &&
( V_226 -> V_228 . V_232 ||
V_226 -> V_228 . V_233 ||
V_226 -> V_228 . V_234 ) &&
V_226 -> V_228 . V_235 &&
( V_226 -> V_228 . V_236 ||
V_226 -> V_228 . V_237 ) ) ) {
F_28 ( 2 , V_98 , L_38
L_39
L_40
L_41
L_42 ) ;
return - V_43 ;
}
* V_228 = V_226 -> V_228 ;
V_84 -> V_238 = V_228 -> V_232 + V_228 -> V_233 +
V_228 -> V_234 - 8 ;
V_84 -> V_239 = V_228 -> V_36 ;
V_84 -> V_240 = 1 ;
V_84 -> V_241 = V_228 -> V_237 + V_228 -> V_236 + 1 ;
if ( V_228 -> V_242 ) {
if ( V_228 -> V_243 || V_228 -> V_244 || V_228 -> V_245 ) {
V_84 -> V_246 = V_228 -> V_37 * 2 +
V_228 -> V_235 + V_228 -> V_237 + V_228 -> V_236 +
V_228 -> V_244 + V_228 -> V_245 +
V_228 -> V_243 ;
V_84 -> V_247 = V_84 -> V_246 / 2 -
( V_228 -> V_235 - 1 ) ;
V_84 -> V_248 = V_84 -> V_246 / 2 + 1 ;
V_84 -> V_249 = V_84 -> V_248 + V_228 -> V_245 +
V_228 -> V_243 + 1 ;
V_84 -> V_250 = V_84 -> V_246 -
( V_228 -> V_244 - 1 ) ;
} else {
F_28 ( 2 , V_98 , L_43
L_44 ) ;
return - V_43 ;
}
} else {
V_84 -> V_246 = V_228 -> V_37 + V_228 -> V_235 +
V_228 -> V_237 + V_228 -> V_236 ;
V_84 -> V_247 = V_84 -> V_246 - ( V_228 -> V_235 - 1 ) ;
}
strncpy ( V_84 -> V_212 , L_45 ,
V_251 ) ;
V_84 -> V_36 = V_228 -> V_36 ;
V_84 -> V_37 = V_228 -> V_37 ;
V_84 -> V_85 = V_228 -> V_242 ? 0 : 1 ;
V_84 -> V_200 = 0 ;
V_84 -> V_252 = 0 ;
V_84 -> V_253 = 0 ;
V_84 -> V_97 = 1 ;
V_84 -> V_99 = 0 ;
V_84 -> V_100 = V_186 ;
V_90 -> V_99 = 0 ;
V_90 -> V_100 = V_186 ;
return 0 ;
}
static int F_100 ( struct V_127 * V_127 , void * V_143 ,
struct V_225 * V_226 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_227 * V_228 = & V_90 -> V_101 ;
V_226 -> V_228 = * V_228 ;
return 0 ;
}
static int F_101 ( struct V_127 * V_127 , void * V_143 ,
struct V_254 * V_255 )
{
V_255 -> V_256 = V_257 ;
V_255 -> V_258 = 0 ;
if ( V_255 -> V_259 . type != V_260 &&
V_255 -> V_259 . type != V_261 ) {
F_28 ( 2 , V_98 , L_46 ) ;
return - V_43 ;
}
return F_75 ( & V_77 . V_187 , 0 , V_189 ,
V_262 , V_255 ) ;
}
static int F_102 ( struct V_127 * V_127 , void * V_143 ,
struct V_263 * V_264 ) {
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
return F_95 ( V_77 . V_219 [ V_90 -> V_215 ] , V_189 ,
V_265 , V_264 ) ;
}
static int F_103 ( struct V_127 * V_127 , void * V_143 ,
struct V_263 * V_264 ) {
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
return F_95 ( V_77 . V_219 [ V_90 -> V_215 ] , V_189 ,
V_266 , V_264 ) ;
}
static int F_104 ( struct V_127 * V_128 , void * V_143 )
{
F_105 ( & V_77 . V_187 , 0 , V_189 , V_267 ) ;
return 0 ;
}
static int F_106 ( void )
{
int V_268 ;
int V_269 ;
int V_270 ;
int V_271 = 0 , V_78 , V_272 ;
if ( ( V_273 > 0 ) &&
( V_273 < V_56 . V_59 ) )
V_273 = V_56 . V_59 ;
if ( ( V_274 > 0 ) &&
( V_274 < V_56 . V_59 ) )
V_274 = V_56 . V_59 ;
if ( V_275 < V_56 . V_276 [ V_142 ] )
V_275 =
V_56 . V_276 [ V_142 ] ;
if ( V_277 < V_56 . V_276 [ V_123 ] )
V_277 =
V_56 . V_276 [ V_123 ] ;
V_56 . V_114 [ V_142 ] = V_273 ;
if ( V_273 ) {
V_56 . V_57 [ V_142 ] =
V_275 ;
}
V_56 . V_114 [ V_123 ] = V_274 ;
if ( V_274 ) {
V_56 . V_57 [ V_123 ] =
V_277 ;
}
for ( V_78 = 0 ; V_78 < V_278 ; V_78 ++ ) {
V_77 . V_76 [ V_78 ] =
F_42 ( sizeof( struct V_53 ) , V_134 ) ;
if ( ! V_77 . V_76 [ V_78 ] ) {
V_268 = V_78 ;
V_271 = - V_135 ;
goto V_279;
}
}
V_268 = V_278 ;
V_269 = V_280 ;
V_270 = V_56 . V_114 [ V_78 - 1 ] ;
return 0 ;
V_279:
for ( V_272 = 0 ; V_272 < V_268 ; V_272 ++ )
F_54 ( V_77 . V_76 [ V_272 ] ) ;
return V_271 ;
}
static T_6 int F_107 ( struct V_281 * V_282 )
{
struct V_283 * V_284 ;
struct V_146 * V_94 ;
int V_78 , V_272 = 0 , V_285 , V_21 , V_181 , V_271 = 0 ;
struct V_286 * V_287 ;
struct V_29 * V_30 ;
struct V_53 * V_54 ;
struct V_132 * V_288 ;
struct V_289 * V_14 ;
int V_290 ;
V_147 = & V_282 -> V_76 ;
V_271 = F_106 () ;
if ( V_271 ) {
F_108 ( V_147 -> V_154 , L_47 ) ;
return V_271 ;
}
V_271 = F_109 ( V_147 , & V_77 . V_187 ) ;
if ( V_271 ) {
F_108 ( V_147 -> V_154 , L_48 ) ;
return V_271 ;
}
V_285 = 0 ;
while ( ( V_14 = F_110 ( V_282 , V_291 , V_285 ) ) ) {
for ( V_78 = V_14 -> V_292 ; V_78 <= V_14 -> V_293 ; V_78 ++ ) {
if ( F_111 ( V_78 , F_25 , V_294 ,
L_49 ,
( void * ) ( & V_77 . V_76 [ V_285 ] -> V_58 ) ) ) {
V_271 = - V_163 ;
goto V_295;
}
}
V_285 ++ ;
}
for ( V_78 = 0 ; V_78 < V_278 ; V_78 ++ ) {
V_54 = V_77 . V_76 [ V_78 ] ;
V_288 = F_112 () ;
if ( V_288 == NULL ) {
for ( V_272 = 0 ; V_272 < V_78 ; V_272 ++ ) {
V_54 = V_77 . V_76 [ V_272 ] ;
F_113 ( V_54 -> V_296 ) ;
}
V_271 = - V_135 ;
goto V_295;
}
* V_288 = V_297 ;
V_288 -> V_187 = & V_77 . V_187 ;
V_288 -> V_298 = F_113 ;
snprintf ( V_288 -> V_212 , sizeof( V_288 -> V_212 ) ,
L_50 ,
( V_150 >> 16 ) & 0xff ,
( V_150 >> 8 ) & 0xff ,
( V_150 ) & 0xff ) ;
V_54 -> V_296 = V_288 ;
}
for ( V_272 = 0 ; V_272 < V_278 ; V_272 ++ ) {
V_54 = V_77 . V_76 [ V_272 ] ;
F_114 ( & V_54 -> V_137 , 0 ) ;
for ( V_285 = 0 ; V_285 < V_81 ; V_285 ++ ) {
V_54 -> V_30 [ V_285 ] . V_114 = 0 ;
V_30 = & V_54 -> V_30 [ V_285 ] ;
V_30 -> V_141 = 0 ;
V_30 -> V_82 = 0 ;
F_115 ( & V_30 -> V_168 ) ;
F_116 ( & V_30 -> V_169 ) ;
V_30 -> V_114 = 0 ;
V_30 -> V_67 = NULL ;
V_30 -> V_48 = V_30 -> V_49 = 0 ;
V_30 -> V_50 = V_30 -> V_51 = 0 ;
V_30 -> V_69 = V_30 -> V_64 = NULL ;
memset ( & V_30 -> V_79 , 0 , sizeof( V_30 -> V_79 ) ) ;
V_30 -> V_114 = V_56 . V_114 [ V_285 ] ;
}
V_54 -> V_136 = 0 ;
V_54 -> V_58 = V_272 ;
if ( V_272 < 2 )
V_54 -> V_30 [ V_33 ] . V_114 =
V_56 . V_114 [ V_54 -> V_58 ] ;
else
V_54 -> V_30 [ V_33 ] . V_114 = 0 ;
memset ( & V_54 -> V_83 , 0 , sizeof( V_54 -> V_83 ) ) ;
F_117 ( & V_54 -> V_139 ) ;
V_54 -> V_30 [ V_33 ] . V_79 . type =
V_117 ;
V_54 -> V_296 -> V_169 = & V_30 -> V_169 ;
F_28 ( 1 , V_98 , L_51 ,
( int ) V_54 , ( int ) & V_54 -> V_296 ) ;
V_271 = F_118 ( V_54 -> V_296 ,
V_299 , ( V_272 ? 3 : 2 ) ) ;
if ( V_271 < 0 )
goto V_300;
F_119 ( V_54 -> V_296 , V_54 ) ;
}
V_287 = F_120 ( 1 ) ;
V_94 = V_282 -> V_76 . V_148 ;
V_290 = V_94 -> V_290 ;
V_284 = V_94 -> V_301 ;
V_77 . V_219 = F_42 ( sizeof( struct V_302 * ) * V_290 ,
V_134 ) ;
if ( V_77 . V_219 == NULL ) {
F_9 ( L_52 ) ;
V_271 = - V_135 ;
goto V_300;
}
for ( V_78 = 0 ; V_78 < V_290 ; V_78 ++ ) {
V_77 . V_219 [ V_78 ] = F_121 ( & V_77 . V_187 ,
V_287 ,
& V_284 [ V_78 ] . V_303 ,
NULL ) ;
if ( ! V_77 . V_219 [ V_78 ] ) {
F_9 ( L_53 ) ;
goto V_304;
}
if ( V_77 . V_219 [ V_78 ] )
V_77 . V_219 [ V_78 ] -> V_305 = 1 << V_78 ;
}
F_122 ( & V_77 . V_187 ,
L_54 ) ;
return 0 ;
V_304:
F_54 ( V_77 . V_219 ) ;
V_300:
for ( V_285 = 0 ; V_285 < V_272 ; V_285 ++ ) {
V_54 = V_77 . V_76 [ V_285 ] ;
F_123 ( V_54 -> V_296 ) ;
F_113 ( V_54 -> V_296 ) ;
V_54 -> V_296 = NULL ;
}
V_295:
F_124 ( & V_77 . V_187 ) ;
F_9 ( L_55 ) ;
for ( V_21 = V_285 ; V_285 >= 0 ; V_285 -- ) {
for ( V_181 = V_78 ; V_181 >= V_14 -> V_292 ; V_181 -- )
F_125 ( V_181 , ( void * ) ( & V_77 . V_76 [ V_285 ] -> V_58 ) ) ;
V_14 = F_110 ( V_282 , V_291 , V_285 - 1 ) ;
V_181 = V_14 -> V_293 ;
}
return V_271 ;
}
static int F_126 ( struct V_281 * V_306 )
{
struct V_53 * V_54 ;
int V_78 ;
F_124 ( & V_77 . V_187 ) ;
for ( V_78 = 0 ; V_78 < V_278 ; V_78 ++ ) {
V_54 = V_77 . V_76 [ V_78 ] ;
F_123 ( V_54 -> V_296 ) ;
V_54 -> V_296 = NULL ;
}
return 0 ;
}
static T_6 int F_127 ( void )
{
return F_128 ( & V_307 ) ;
}
static void F_129 ( void )
{
struct V_281 * V_282 ;
struct V_289 * V_14 ;
int V_308 ;
int V_78 = 0 ;
V_282 = F_130 ( V_147 , struct V_281 , V_76 ) ;
while ( ( V_14 = F_110 ( V_282 , V_291 , V_78 ) ) ) {
for ( V_308 = V_14 -> V_292 ; V_308 <= V_14 -> V_293 ; V_308 ++ )
F_125 ( V_308 ,
( void * ) ( & V_77 . V_76 [ V_78 ] -> V_58 ) ) ;
V_78 ++ ;
}
F_131 ( & V_307 ) ;
F_54 ( V_77 . V_219 ) ;
for ( V_78 = 0 ; V_78 < V_278 ; V_78 ++ )
F_54 ( V_77 . V_76 [ V_78 ] ) ;
}
