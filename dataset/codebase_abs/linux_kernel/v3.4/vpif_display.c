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
V_145 -> V_149 = V_150 | V_151 ;
F_56 ( V_145 -> V_152 , L_13 , sizeof( V_145 -> V_152 ) ) ;
F_56 ( V_145 -> V_153 , L_14 , sizeof( V_145 -> V_153 ) ) ;
F_56 ( V_145 -> V_154 , V_94 -> V_155 , sizeof( V_145 -> V_154 ) ) ;
return 0 ;
}
static int F_57 ( struct V_127 * V_127 , void * V_143 ,
struct V_156 * V_79 )
{
if ( V_79 -> V_157 != 0 ) {
F_9 ( L_15 ) ;
return - V_43 ;
}
V_79 -> type = V_117 ;
strcpy ( V_79 -> V_158 , L_16 ) ;
V_79 -> V_115 = V_116 ;
return 0 ;
}
static int F_58 ( struct V_127 * V_127 , void * V_143 ,
struct V_159 * V_79 )
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
struct V_159 * V_79 )
{
struct V_26 * V_27 = V_143 ;
struct V_118 * V_119 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
int V_160 = 0 ;
if ( ( V_142 == V_54 -> V_58 )
|| ( V_123 == V_54 -> V_58 ) ) {
if ( ! V_27 -> V_136 ) {
F_28 ( 1 , V_98 , L_17 ) ;
return - V_161 ;
}
V_160 = F_60 ( & V_54 -> V_139 , V_27 -> V_139 ) ;
if ( 0 != V_160 )
return V_160 ;
V_27 -> V_136 = 1 ;
}
if ( V_30 -> V_82 ) {
F_28 ( 1 , V_98 , L_18 ) ;
return - V_161 ;
}
V_119 = & V_79 -> V_79 . V_80 ;
V_160 = F_32 ( V_54 , V_119 ) ;
if ( V_160 )
return V_160 ;
V_30 -> V_79 . V_79 . V_80 = * V_119 ;
V_30 -> V_79 = * V_79 ;
return 0 ;
}
static int F_61 ( struct V_127 * V_127 , void * V_143 ,
struct V_159 * V_79 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_118 * V_119 = & V_79 -> V_79 . V_80 ;
int V_160 = 0 ;
V_160 = F_32 ( V_54 , V_119 ) ;
if ( V_160 ) {
* V_119 = V_30 -> V_79 . V_79 . V_80 ;
V_119 -> V_104 = V_119 -> V_36 * V_119 -> V_37 * 2 ;
}
return V_160 ;
}
static int F_62 ( struct V_127 * V_127 , void * V_143 ,
struct V_162 * V_163 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 ;
enum V_24 V_25 ;
T_4 V_157 = 0 ;
if ( ( V_142 == V_54 -> V_58 )
|| ( V_123 == V_54 -> V_58 ) ) {
if ( ! V_27 -> V_136 ) {
F_9 ( L_17 ) ;
return - V_161 ;
}
}
if ( V_117 != V_163 -> type )
return - V_43 ;
V_157 = V_33 ;
V_30 = & V_54 -> V_30 [ V_157 ] ;
if ( V_30 -> V_79 . type != V_163 -> type )
return - V_43 ;
if ( 0 != V_30 -> V_141 )
return - V_161 ;
if ( V_163 -> type == V_117 ) {
if ( V_30 -> V_79 . V_79 . V_80 . V_25 == V_105 )
V_25 = V_108 ;
else
V_25 = V_30 -> V_79 . V_79 . V_80 . V_25 ;
} else {
V_25 = V_164 ;
}
F_63 ( & V_30 -> V_130 ,
& V_165 , NULL ,
& V_30 -> V_166 ,
V_163 -> type , V_25 ,
sizeof( struct V_22 ) , V_27 ,
& V_30 -> V_167 ) ;
V_27 -> V_138 [ V_157 ] = 1 ;
V_30 -> V_141 = 1 ;
V_30 -> V_41 = V_163 -> V_41 ;
F_64 ( & V_30 -> V_61 ) ;
return F_65 ( & V_30 -> V_130 , V_163 ) ;
}
static int F_66 ( struct V_127 * V_127 , void * V_143 ,
struct V_168 * V_169 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_30 -> V_79 . type != V_169 -> type )
return - V_43 ;
return F_67 ( & V_30 -> V_130 , V_169 ) ;
}
static int F_68 ( struct V_127 * V_127 , void * V_143 , struct V_168 * V_170 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_168 V_169 = * V_170 ;
struct V_22 * V_171 ;
unsigned long V_31 = 0 ;
unsigned long V_172 ;
int V_160 = 0 ;
if ( V_30 -> V_79 . type != V_169 . type )
return - V_43 ;
if ( ! V_27 -> V_138 [ V_33 ] ) {
F_9 ( L_19 ) ;
return - V_173 ;
}
if ( ! ( F_24 ( & V_30 -> V_61 ) ) ||
( V_30 -> V_69 != V_30 -> V_64 ) ||
! ( V_30 -> V_82 ) ||
( V_30 -> V_82 && ( 0 == V_54 -> V_87 ) ) )
return F_69 ( & V_30 -> V_130 , V_170 ) ;
F_70 ( & V_30 -> V_130 . V_174 ) ;
V_171 = V_30 -> V_130 . V_175 [ V_169 . V_157 ] ;
if ( V_171 -> V_41 != V_169 . V_41 ) {
F_9 ( L_20 ) ;
goto V_176;
}
if ( ( V_171 -> V_35 == V_62 ) ||
( V_171 -> V_35 == V_66 ) ) {
F_9 ( L_21 ) ;
goto V_176;
}
switch ( V_171 -> V_41 ) {
case V_55 :
if ( V_171 -> V_42 == 0 )
goto V_176;
break;
case V_40 :
if ( V_169 . V_177 < V_171 -> V_178 )
goto V_176;
if ( ( V_34 != V_171 -> V_35 )
&& ( V_171 -> V_42 != V_169 . V_179 . V_180 ) ) {
F_15 ( & V_30 -> V_130 , V_171 ) ;
V_171 -> V_42 = V_169 . V_179 . V_180 ;
}
break;
default:
goto V_176;
}
F_71 ( V_172 ) ;
V_160 = F_10 ( & V_30 -> V_130 , V_171 ,
V_30 -> V_130 . V_25 ) ;
if ( V_160 < 0 ) {
F_72 ( V_172 ) ;
goto V_176;
}
V_171 -> V_35 = V_66 ;
V_31 = V_171 -> V_44 ;
V_30 -> V_64 = V_171 ;
if ( V_169 . type != V_47 ) {
V_30 -> V_67 ( ( V_31 + V_30 -> V_48 ) ,
( V_31 + V_30 -> V_49 ) ,
( V_31 + V_30 -> V_50 ) ,
( V_31 + V_30 -> V_51 ) ) ;
}
F_72 ( V_172 ) ;
F_14 ( & V_171 -> V_181 , & V_30 -> V_130 . V_181 ) ;
F_73 ( & V_30 -> V_130 . V_174 ) ;
return 0 ;
V_176:
F_73 ( & V_30 -> V_130 . V_174 ) ;
return - V_43 ;
}
static int F_74 ( struct V_127 * V_127 , void * V_143 , T_5 * V_182 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
int V_160 = 0 ;
if ( ! ( * V_182 & V_183 ) )
return - V_43 ;
if ( V_30 -> V_82 ) {
F_9 ( L_22 ) ;
return - V_161 ;
}
V_54 -> V_91 . V_99 = * V_182 ;
V_54 -> V_91 . V_100 = V_184 ;
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
V_160 = F_75 ( & V_77 . V_185 , 1 , V_91 ,
V_186 , * V_182 ) ;
if ( V_160 < 0 ) {
F_9 ( L_24 ) ;
return V_160 ;
}
V_160 = F_75 ( & V_77 . V_185 , 1 , V_187 ,
V_188 , * V_182 ) ;
if ( V_160 < 0 )
F_9 ( L_25 ) ;
return V_160 ;
}
static int F_76 ( struct V_127 * V_127 , void * V_143 , T_5 * V_189 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
* V_189 = V_54 -> V_91 . V_99 ;
return 0 ;
}
static int F_77 ( struct V_127 * V_127 , void * V_143 , struct V_168 * V_190 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
return F_78 ( & V_30 -> V_130 , V_190 ,
( V_127 -> V_191 & V_192 ) ) ;
}
static int F_79 ( struct V_127 * V_127 , void * V_143 ,
enum V_193 V_194 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_53 * V_195 = V_77 . V_76 [ ! V_54 -> V_58 ] ;
struct V_92 * V_196 = & V_54 -> V_83 ;
struct V_146 * V_197 =
V_147 -> V_148 ;
unsigned long V_31 = 0 ;
int V_160 = 0 ;
if ( V_194 != V_117 ) {
F_9 ( L_26 ) ;
return - V_43 ;
}
if ( ! V_27 -> V_138 [ V_33 ] ) {
F_9 ( L_19 ) ;
return - V_173 ;
}
if ( V_30 -> V_82 ) {
F_9 ( L_27 ) ;
return - V_161 ;
}
if ( ( V_54 -> V_58 == V_142
&& V_195 -> V_30 [ V_33 ] . V_82 &&
V_54 -> V_83 . V_84 . V_198 == 0 )
|| ( ( V_54 -> V_58 == V_123 )
&& ( 2 == V_195 -> V_30 [ V_33 ] . V_82 ) ) ) {
F_9 ( L_28 ) ;
return - V_161 ;
}
V_160 = F_32 ( V_54 , & V_30 -> V_79 . V_79 . V_80 ) ;
if ( V_160 < 0 )
return V_160 ;
V_160 = F_80 ( & V_30 -> V_130 ) ;
if ( V_160 < 0 ) {
F_9 ( L_29 ) ;
return V_160 ;
}
if ( F_24 ( & V_30 -> V_61 ) ) {
F_9 ( L_30 ) ;
return - V_199 ;
}
V_30 -> V_64 = V_30 -> V_69 =
F_18 ( V_30 -> V_61 . V_65 ,
struct V_22 , V_60 ) ;
F_19 ( & V_30 -> V_69 -> V_60 ) ;
V_30 -> V_69 -> V_35 = V_66 ;
V_54 -> V_87 = 0 ;
V_30 -> V_82 = 1 ;
if ( V_194 == V_117 ) {
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
V_160 =
V_197 -> V_200 ( V_54 -> V_83 . V_84 . V_198 ,
V_54 -> V_83 . V_84 . V_97 ) ;
if ( V_160 < 0 ) {
F_9 ( L_32 ) ;
return V_160 ;
}
V_160 = F_81 ( V_196 , V_54 -> V_58 + 2 ) ;
if ( V_160 < 0 )
return V_160 ;
V_30 -> V_82 = V_160 ;
F_34 ( V_54 , V_160 ) ;
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
return V_160 ;
}
static int F_84 ( struct V_127 * V_127 , void * V_143 ,
enum V_193 V_194 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_194 != V_117 ) {
F_9 ( L_26 ) ;
return - V_43 ;
}
if ( ! V_27 -> V_138 [ V_33 ] ) {
F_9 ( L_19 ) ;
return - V_173 ;
}
if ( ! V_30 -> V_82 ) {
F_9 ( L_27 ) ;
return - V_43 ;
}
if ( V_194 == V_117 ) {
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
struct V_201 * V_202 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
if ( V_117 != V_202 -> type )
return - V_43 ;
V_202 -> V_203 . V_204 = V_202 -> V_203 . V_205 = 0 ;
V_202 -> V_206 . V_204 = V_202 -> V_206 . V_205 = 0 ;
V_202 -> V_206 . V_37 = V_202 -> V_203 . V_37 = V_30 -> V_37 ;
V_202 -> V_206 . V_36 = V_202 -> V_203 . V_36 = V_30 -> V_36 ;
return 0 ;
}
static int F_87 ( struct V_127 * V_127 , void * V_27 ,
struct V_207 * V_208 )
{
struct V_146 * V_94 = V_147 -> V_148 ;
if ( V_208 -> V_157 >= V_94 -> V_209 ) {
F_28 ( 1 , V_98 , L_33 ) ;
return - V_43 ;
}
strcpy ( V_208 -> V_210 , V_94 -> V_208 [ V_208 -> V_157 ] ) ;
V_208 -> type = V_211 ;
V_208 -> V_189 = V_183 ;
return 0 ;
}
static int F_88 ( struct V_127 * V_127 , void * V_143 , unsigned int V_78 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
int V_160 = 0 ;
if ( V_30 -> V_82 ) {
F_9 ( L_18 ) ;
return - V_161 ;
}
V_160 = F_75 ( & V_77 . V_185 , 1 , V_91 ,
V_212 , 0 , V_78 , 0 ) ;
if ( V_160 < 0 )
F_9 ( L_24 ) ;
V_90 -> V_213 = V_78 ;
return V_160 ;
}
static int F_89 ( struct V_127 * V_127 , void * V_143 , unsigned int * V_78 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
* V_78 = V_90 -> V_213 ;
return 0 ;
}
static int F_90 ( struct V_127 * V_127 , void * V_143 , enum V_214 * V_190 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
* V_190 = F_91 ( & V_54 -> V_139 ) ;
return 0 ;
}
static int F_92 ( struct V_127 * V_127 , void * V_143 , enum V_214 V_190 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
return F_93 ( & V_54 -> V_139 , & V_27 -> V_139 , V_190 ) ;
}
static int F_94 ( struct V_127 * V_127 , void * V_143 ,
struct V_215 * V_216 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
return F_95 ( V_77 . V_217 [ V_90 -> V_213 ] ,
V_91 , V_218 , V_216 ) ;
}
static int F_96 ( struct V_127 * V_127 , void * V_143 ,
struct V_219 * V_216 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_29 * V_30 = & V_54 -> V_30 [ V_33 ] ;
struct V_89 * V_90 = & V_54 -> V_91 ;
int V_160 = 0 ;
if ( V_30 -> V_82 ) {
F_28 ( 1 , V_98 , L_22 ) ;
return - V_161 ;
}
V_160 = F_60 ( & V_54 -> V_139 , V_27 -> V_139 ) ;
if ( V_160 != 0 )
return V_160 ;
V_27 -> V_136 = 1 ;
if ( F_97 ( & V_30 -> V_167 ) )
return - V_220 ;
V_54 -> V_91 . V_100 = V_216 -> V_216 ;
V_54 -> V_91 . V_99 = V_221 ;
memset ( & V_54 -> V_91 . V_101 , 0 , sizeof( V_54 -> V_91 . V_101 ) ) ;
if ( F_29 ( V_54 ) ) {
V_160 = - V_43 ;
} else {
F_31 ( V_54 ) ;
V_160 = F_95 ( V_77 . V_217 [ V_90 -> V_213 ] ,
V_91 , V_222 , V_216 ) ;
}
F_73 ( & V_30 -> V_167 ) ;
return V_160 ;
}
static int F_98 ( struct V_127 * V_127 , void * V_143 ,
struct V_219 * V_216 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
V_216 -> V_216 = V_54 -> V_91 . V_100 ;
return 0 ;
}
static int F_99 ( struct V_127 * V_127 , void * V_143 ,
struct V_223 * V_224 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_92 * V_83 = & V_54 -> V_83 ;
struct V_93 * V_84 = & V_83 -> V_84 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_225 * V_226 = & V_90 -> V_101 ;
int V_160 ;
if ( V_224 -> type != V_227 ) {
F_28 ( 2 , V_98 , L_34 ) ;
return - V_43 ;
}
V_160 = F_95 ( V_77 . V_217 [ V_90 -> V_213 ] ,
V_91 , V_228 , V_224 ) ;
if ( V_160 == - V_229 ) {
F_28 ( 2 , V_98 , L_35
L_36 ) ;
return - V_43 ;
}
if ( V_160 < 0 ) {
F_28 ( 2 , V_98 , L_37 ) ;
return V_160 ;
}
if ( ! ( V_224 -> V_226 . V_36 && V_224 -> V_226 . V_37 &&
( V_224 -> V_226 . V_230 ||
V_224 -> V_226 . V_231 ||
V_224 -> V_226 . V_232 ) &&
V_224 -> V_226 . V_233 &&
( V_224 -> V_226 . V_234 ||
V_224 -> V_226 . V_235 ) ) ) {
F_28 ( 2 , V_98 , L_38
L_39
L_40
L_41
L_42 ) ;
return - V_43 ;
}
* V_226 = V_224 -> V_226 ;
V_84 -> V_236 = V_226 -> V_230 + V_226 -> V_231 +
V_226 -> V_232 - 8 ;
V_84 -> V_237 = V_226 -> V_36 ;
V_84 -> V_238 = 1 ;
V_84 -> V_239 = V_226 -> V_235 + V_226 -> V_234 + 1 ;
if ( V_226 -> V_240 ) {
if ( V_226 -> V_241 || V_226 -> V_242 || V_226 -> V_243 ) {
V_84 -> V_244 = V_226 -> V_37 * 2 +
V_226 -> V_233 + V_226 -> V_235 + V_226 -> V_234 +
V_226 -> V_242 + V_226 -> V_243 +
V_226 -> V_241 ;
V_84 -> V_245 = V_84 -> V_244 / 2 -
( V_226 -> V_233 - 1 ) ;
V_84 -> V_246 = V_84 -> V_244 / 2 + 1 ;
V_84 -> V_247 = V_84 -> V_246 + V_226 -> V_243 +
V_226 -> V_241 + 1 ;
V_84 -> V_248 = V_84 -> V_244 -
( V_226 -> V_242 - 1 ) ;
} else {
F_28 ( 2 , V_98 , L_43
L_44 ) ;
return - V_43 ;
}
} else {
V_84 -> V_244 = V_226 -> V_37 + V_226 -> V_233 +
V_226 -> V_235 + V_226 -> V_234 ;
V_84 -> V_245 = V_84 -> V_244 - ( V_226 -> V_233 - 1 ) ;
}
strncpy ( V_84 -> V_210 , L_45 ,
V_249 ) ;
V_84 -> V_36 = V_226 -> V_36 ;
V_84 -> V_37 = V_226 -> V_37 ;
V_84 -> V_85 = V_226 -> V_240 ? 0 : 1 ;
V_84 -> V_198 = 0 ;
V_84 -> V_250 = 0 ;
V_84 -> V_251 = 0 ;
V_84 -> V_97 = 1 ;
V_84 -> V_99 = 0 ;
V_84 -> V_100 = V_184 ;
V_90 -> V_99 = 0 ;
V_90 -> V_100 = V_184 ;
return 0 ;
}
static int F_100 ( struct V_127 * V_127 , void * V_143 ,
struct V_223 * V_224 )
{
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
struct V_225 * V_226 = & V_90 -> V_101 ;
V_224 -> V_226 = * V_226 ;
return 0 ;
}
static int F_101 ( struct V_127 * V_127 , void * V_143 ,
struct V_252 * V_253 )
{
V_253 -> V_254 = V_255 ;
V_253 -> V_256 = 0 ;
if ( V_253 -> V_257 . type != V_258 &&
V_253 -> V_257 . type != V_259 ) {
F_28 ( 2 , V_98 , L_46 ) ;
return - V_43 ;
}
return F_75 ( & V_77 . V_185 , 0 , V_187 ,
V_260 , V_253 ) ;
}
static int F_102 ( struct V_127 * V_127 , void * V_143 ,
struct V_261 * V_262 ) {
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
return F_95 ( V_77 . V_217 [ V_90 -> V_213 ] , V_187 ,
V_263 , V_262 ) ;
}
static int F_103 ( struct V_127 * V_127 , void * V_143 ,
struct V_261 * V_262 ) {
struct V_26 * V_27 = V_143 ;
struct V_53 * V_54 = V_27 -> V_32 ;
struct V_89 * V_90 = & V_54 -> V_91 ;
return F_95 ( V_77 . V_217 [ V_90 -> V_213 ] , V_187 ,
V_264 , V_262 ) ;
}
static int F_104 ( struct V_127 * V_128 , void * V_143 )
{
F_105 ( & V_77 . V_185 , 0 , V_187 , V_265 ) ;
return 0 ;
}
static int F_106 ( void )
{
int V_266 ;
int V_267 ;
int V_268 ;
int V_269 = 0 , V_78 , V_270 ;
if ( ( V_271 > 0 ) &&
( V_271 < V_56 . V_59 ) )
V_271 = V_56 . V_59 ;
if ( ( V_272 > 0 ) &&
( V_272 < V_56 . V_59 ) )
V_272 = V_56 . V_59 ;
if ( V_273 < V_56 . V_274 [ V_142 ] )
V_273 =
V_56 . V_274 [ V_142 ] ;
if ( V_275 < V_56 . V_274 [ V_123 ] )
V_275 =
V_56 . V_274 [ V_123 ] ;
V_56 . V_114 [ V_142 ] = V_271 ;
if ( V_271 ) {
V_56 . V_57 [ V_142 ] =
V_273 ;
}
V_56 . V_114 [ V_123 ] = V_272 ;
if ( V_272 ) {
V_56 . V_57 [ V_123 ] =
V_275 ;
}
for ( V_78 = 0 ; V_78 < V_276 ; V_78 ++ ) {
V_77 . V_76 [ V_78 ] =
F_42 ( sizeof( struct V_53 ) , V_134 ) ;
if ( ! V_77 . V_76 [ V_78 ] ) {
V_266 = V_78 ;
V_269 = - V_135 ;
goto V_277;
}
}
V_266 = V_276 ;
V_267 = V_278 ;
V_268 = V_56 . V_114 [ V_78 - 1 ] ;
return 0 ;
V_277:
for ( V_270 = 0 ; V_270 < V_266 ; V_270 ++ )
F_54 ( V_77 . V_76 [ V_270 ] ) ;
return V_269 ;
}
static T_6 int F_107 ( struct V_279 * V_280 )
{
struct V_281 * V_282 ;
struct V_146 * V_94 ;
int V_78 , V_270 = 0 , V_283 , V_21 , V_179 , V_269 = 0 ;
struct V_284 * V_285 ;
struct V_29 * V_30 ;
struct V_53 * V_54 ;
struct V_132 * V_286 ;
struct V_287 * V_14 ;
int V_288 ;
V_147 = & V_280 -> V_76 ;
V_269 = F_106 () ;
if ( V_269 ) {
F_108 ( V_147 -> V_152 , L_47 ) ;
return V_269 ;
}
V_269 = F_109 ( V_147 , & V_77 . V_185 ) ;
if ( V_269 ) {
F_108 ( V_147 -> V_152 , L_48 ) ;
return V_269 ;
}
V_283 = 0 ;
while ( ( V_14 = F_110 ( V_280 , V_289 , V_283 ) ) ) {
for ( V_78 = V_14 -> V_290 ; V_78 <= V_14 -> V_291 ; V_78 ++ ) {
if ( F_111 ( V_78 , F_25 , V_292 ,
L_49 ,
( void * ) ( & V_77 . V_76 [ V_283 ] -> V_58 ) ) ) {
V_269 = - V_161 ;
goto V_293;
}
}
V_283 ++ ;
}
for ( V_78 = 0 ; V_78 < V_276 ; V_78 ++ ) {
V_54 = V_77 . V_76 [ V_78 ] ;
V_286 = F_112 () ;
if ( V_286 == NULL ) {
for ( V_270 = 0 ; V_270 < V_78 ; V_270 ++ ) {
V_54 = V_77 . V_76 [ V_270 ] ;
F_113 ( V_54 -> V_294 ) ;
}
V_269 = - V_135 ;
goto V_293;
}
* V_286 = V_295 ;
V_286 -> V_185 = & V_77 . V_185 ;
V_286 -> V_296 = F_113 ;
snprintf ( V_286 -> V_210 , sizeof( V_286 -> V_210 ) ,
L_50 ,
V_297 ) ;
V_54 -> V_294 = V_286 ;
}
for ( V_270 = 0 ; V_270 < V_276 ; V_270 ++ ) {
V_54 = V_77 . V_76 [ V_270 ] ;
F_114 ( & V_54 -> V_137 , 0 ) ;
for ( V_283 = 0 ; V_283 < V_81 ; V_283 ++ ) {
V_54 -> V_30 [ V_283 ] . V_114 = 0 ;
V_30 = & V_54 -> V_30 [ V_283 ] ;
V_30 -> V_141 = 0 ;
V_30 -> V_82 = 0 ;
F_115 ( & V_30 -> V_166 ) ;
F_116 ( & V_30 -> V_167 ) ;
V_30 -> V_114 = 0 ;
V_30 -> V_67 = NULL ;
V_30 -> V_48 = V_30 -> V_49 = 0 ;
V_30 -> V_50 = V_30 -> V_51 = 0 ;
V_30 -> V_69 = V_30 -> V_64 = NULL ;
memset ( & V_30 -> V_79 , 0 , sizeof( V_30 -> V_79 ) ) ;
V_30 -> V_114 = V_56 . V_114 [ V_283 ] ;
}
V_54 -> V_136 = 0 ;
V_54 -> V_58 = V_270 ;
if ( V_270 < 2 )
V_54 -> V_30 [ V_33 ] . V_114 =
V_56 . V_114 [ V_54 -> V_58 ] ;
else
V_54 -> V_30 [ V_33 ] . V_114 = 0 ;
memset ( & V_54 -> V_83 , 0 , sizeof( V_54 -> V_83 ) ) ;
F_117 ( & V_54 -> V_139 ) ;
V_54 -> V_30 [ V_33 ] . V_79 . type =
V_117 ;
V_54 -> V_294 -> V_167 = & V_30 -> V_167 ;
F_28 ( 1 , V_98 , L_51 ,
( int ) V_54 , ( int ) & V_54 -> V_294 ) ;
V_269 = F_118 ( V_54 -> V_294 ,
V_298 , ( V_270 ? 3 : 2 ) ) ;
if ( V_269 < 0 )
goto V_299;
F_119 ( V_54 -> V_294 , V_54 ) ;
}
V_285 = F_120 ( 1 ) ;
V_94 = V_280 -> V_76 . V_148 ;
V_288 = V_94 -> V_288 ;
V_282 = V_94 -> V_300 ;
V_77 . V_217 = F_42 ( sizeof( struct V_301 * ) * V_288 ,
V_134 ) ;
if ( V_77 . V_217 == NULL ) {
F_9 ( L_52 ) ;
V_269 = - V_135 ;
goto V_299;
}
for ( V_78 = 0 ; V_78 < V_288 ; V_78 ++ ) {
V_77 . V_217 [ V_78 ] = F_121 ( & V_77 . V_185 ,
V_285 ,
& V_282 [ V_78 ] . V_302 ,
NULL ) ;
if ( ! V_77 . V_217 [ V_78 ] ) {
F_9 ( L_53 ) ;
goto V_303;
}
if ( V_77 . V_217 [ V_78 ] )
V_77 . V_217 [ V_78 ] -> V_304 = 1 << V_78 ;
}
F_122 ( & V_77 . V_185 ,
L_54 ) ;
return 0 ;
V_303:
F_54 ( V_77 . V_217 ) ;
V_299:
for ( V_283 = 0 ; V_283 < V_270 ; V_283 ++ ) {
V_54 = V_77 . V_76 [ V_283 ] ;
F_123 ( V_54 -> V_294 ) ;
F_113 ( V_54 -> V_294 ) ;
V_54 -> V_294 = NULL ;
}
V_293:
F_124 ( & V_77 . V_185 ) ;
F_9 ( L_55 ) ;
for ( V_21 = V_283 ; V_283 >= 0 ; V_283 -- ) {
for ( V_179 = V_78 ; V_179 >= V_14 -> V_290 ; V_179 -- )
F_125 ( V_179 , ( void * ) ( & V_77 . V_76 [ V_283 ] -> V_58 ) ) ;
V_14 = F_110 ( V_280 , V_289 , V_283 - 1 ) ;
V_179 = V_14 -> V_291 ;
}
return V_269 ;
}
static int F_126 ( struct V_279 * V_305 )
{
struct V_53 * V_54 ;
int V_78 ;
F_124 ( & V_77 . V_185 ) ;
for ( V_78 = 0 ; V_78 < V_276 ; V_78 ++ ) {
V_54 = V_77 . V_76 [ V_78 ] ;
F_123 ( V_54 -> V_294 ) ;
V_54 -> V_294 = NULL ;
}
return 0 ;
}
static T_6 int F_127 ( void )
{
return F_128 ( & V_306 ) ;
}
static void F_129 ( void )
{
struct V_279 * V_280 ;
struct V_287 * V_14 ;
int V_307 ;
int V_78 = 0 ;
V_280 = F_130 ( V_147 , struct V_279 , V_76 ) ;
while ( ( V_14 = F_110 ( V_280 , V_289 , V_78 ) ) ) {
for ( V_307 = V_14 -> V_290 ; V_307 <= V_14 -> V_291 ; V_307 ++ )
F_125 ( V_307 ,
( void * ) ( & V_77 . V_76 [ V_78 ] -> V_58 ) ) ;
V_78 ++ ;
}
F_131 ( & V_306 ) ;
F_54 ( V_77 . V_217 ) ;
for ( V_78 = 0 ; V_78 < V_276 ; V_78 ++ )
F_54 ( V_77 . V_76 [ V_78 ] ) ;
}
