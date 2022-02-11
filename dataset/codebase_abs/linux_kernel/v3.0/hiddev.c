static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
unsigned int V_6 = V_5 -> V_7 & ~ V_8 ;
unsigned int V_9 = V_5 -> V_7 & V_8 ;
struct V_10 * V_11 ;
struct V_1 * V_12 ;
struct V_13 * V_14 ;
if ( V_5 -> V_15 < V_16 ||
V_5 -> V_15 > V_17 )
return NULL ;
V_11 = V_3 -> V_11 +
( V_5 -> V_15 - V_16 ) ;
switch ( V_6 ) {
case 0 :
break;
case V_18 :
if ( F_2 ( & V_11 -> V_19 ) )
return NULL ;
V_14 = V_11 -> V_19 . V_20 ;
V_12 = F_3 ( V_14 , struct V_1 , V_14 ) ;
V_5 -> V_7 = V_12 -> V_21 ;
break;
case V_22 :
V_12 = V_11 -> V_23 [ V_9 ] ;
if ( ! V_12 )
return NULL ;
V_14 = V_12 -> V_14 . V_20 ;
if ( V_14 == & V_11 -> V_19 )
return NULL ;
V_12 = F_3 ( V_14 , struct V_1 , V_14 ) ;
V_5 -> V_7 = V_12 -> V_21 ;
break;
default:
return NULL ;
}
return V_11 -> V_23 [ V_5 -> V_7 ] ;
}
static struct V_24 *
F_4 ( struct V_2 * V_3 , struct V_25 * V_26 )
{
int V_27 , V_28 ;
struct V_1 * V_12 ;
struct V_10 * V_11 ;
struct V_24 * V_29 ;
if ( V_26 -> V_15 < V_16 ||
V_26 -> V_15 > V_17 )
return NULL ;
V_11 = V_3 -> V_11 +
( V_26 -> V_15 - V_16 ) ;
F_5 (report, &report_enum->report_list, list) {
for ( V_27 = 0 ; V_27 < V_12 -> V_30 ; V_27 ++ ) {
V_29 = V_12 -> V_29 [ V_27 ] ;
for ( V_28 = 0 ; V_28 < V_29 -> V_31 ; V_28 ++ ) {
if ( V_29 -> V_32 [ V_28 ] . V_3 == V_26 -> V_33 ) {
V_26 -> V_7 = V_12 -> V_21 ;
V_26 -> V_34 = V_27 ;
V_26 -> V_35 = V_28 ;
return V_29 ;
}
}
}
}
return NULL ;
}
static void F_6 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_36 * V_36 = V_3 -> V_36 ;
struct V_37 * V_14 ;
unsigned long V_6 ;
F_7 ( & V_36 -> V_38 , V_6 ) ;
F_5 (list, &hiddev->list, node) {
if ( V_26 -> V_34 != V_39 ||
( V_14 -> V_6 & V_40 ) != 0 ) {
V_14 -> V_41 [ V_14 -> V_42 ] = * V_26 ;
V_14 -> V_42 = ( V_14 -> V_42 + 1 ) &
( V_43 - 1 ) ;
F_8 ( & V_14 -> V_44 , V_45 , V_46 ) ;
}
}
F_9 ( & V_36 -> V_38 , V_6 ) ;
F_10 ( & V_36 -> V_47 ) ;
}
void F_11 ( struct V_2 * V_3 , struct V_24 * V_29 ,
struct V_48 * V_32 , T_1 V_49 )
{
unsigned type = V_29 -> V_15 ;
struct V_25 V_26 ;
V_26 . V_15 =
( type == V_50 ) ? V_51 :
( ( type == V_52 ) ? V_53 :
( ( type == V_54 ) ? V_55 : 0 ) ) ;
V_26 . V_7 = V_29 -> V_12 -> V_21 ;
V_26 . V_34 = V_29 -> V_56 ;
V_26 . V_35 = ( V_32 - V_29 -> V_32 ) ;
V_26 . V_33 = V_32 -> V_3 ;
V_26 . V_49 = V_49 ;
F_6 ( V_3 , & V_26 ) ;
}
void F_12 ( struct V_2 * V_3 , struct V_1 * V_12 )
{
unsigned type = V_12 -> type ;
struct V_25 V_26 ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
V_26 . V_15 =
( type == V_50 ) ? V_51 :
( ( type == V_52 ) ? V_53 :
( ( type == V_54 ) ? V_55 : 0 ) ) ;
V_26 . V_7 = V_12 -> V_21 ;
V_26 . V_34 = V_39 ;
F_6 ( V_3 , & V_26 ) ;
}
static int F_13 ( int V_57 , struct V_58 * V_58 , int V_59 )
{
struct V_37 * V_14 = V_58 -> V_60 ;
return F_14 ( V_57 , V_58 , V_59 , & V_14 -> V_44 ) ;
}
static int F_15 ( struct V_61 * V_61 , struct V_58 * V_58 )
{
struct V_37 * V_14 = V_58 -> V_60 ;
unsigned long V_6 ;
F_7 ( & V_14 -> V_36 -> V_38 , V_6 ) ;
F_16 ( & V_14 -> V_62 ) ;
F_9 ( & V_14 -> V_36 -> V_38 , V_6 ) ;
F_17 ( & V_14 -> V_36 -> V_63 ) ;
if ( ! -- V_14 -> V_36 -> V_64 ) {
if ( V_14 -> V_36 -> V_65 ) {
F_18 ( V_14 -> V_36 -> V_3 ) ;
F_19 ( V_14 -> V_36 -> V_3 ) ;
} else {
F_20 ( & V_14 -> V_36 -> V_63 ) ;
F_21 ( V_14 -> V_36 ) ;
F_21 ( V_14 ) ;
return 0 ;
}
}
F_20 ( & V_14 -> V_36 -> V_63 ) ;
F_21 ( V_14 ) ;
return 0 ;
}
static int F_22 ( struct V_61 * V_61 , struct V_58 * V_58 )
{
struct V_37 * V_14 ;
struct V_66 * V_67 ;
struct V_2 * V_3 ;
struct V_36 * V_36 ;
int V_68 ;
V_67 = F_23 ( F_24 ( V_61 ) ) ;
if ( ! V_67 )
return - V_69 ;
V_3 = F_25 ( V_67 ) ;
V_36 = V_3 -> V_36 ;
if ( ! ( V_14 = F_26 ( sizeof( struct V_37 ) , V_70 ) ) )
return - V_71 ;
F_27 ( & V_14 -> V_72 ) ;
V_14 -> V_36 = V_36 ;
V_58 -> V_60 = V_14 ;
if ( V_14 -> V_36 -> V_65 ) {
if ( ! V_14 -> V_36 -> V_64 ++ ) {
V_68 = F_28 ( V_36 -> V_3 ) ;
if ( V_68 < 0 ) {
V_68 = - V_73 ;
goto V_74;
}
}
} else {
V_68 = - V_69 ;
goto V_74;
}
F_29 ( & V_14 -> V_36 -> V_38 ) ;
F_30 ( & V_14 -> V_62 , & V_36 -> V_14 ) ;
F_31 ( & V_14 -> V_36 -> V_38 ) ;
F_17 ( & V_36 -> V_63 ) ;
if ( ! V_14 -> V_36 -> V_64 ++ )
if ( V_14 -> V_36 -> V_65 ) {
struct V_2 * V_3 = V_36 -> V_3 ;
V_68 = F_32 ( V_3 ) ;
if ( V_68 < 0 ) {
V_68 = - V_73 ;
goto V_75;
}
F_28 ( V_3 ) ;
}
F_20 ( & V_36 -> V_63 ) ;
return 0 ;
V_75:
F_20 ( & V_36 -> V_63 ) ;
V_74:
V_58 -> V_60 = NULL ;
F_21 ( V_14 ) ;
return V_68 ;
}
static T_2 F_33 ( struct V_58 * V_58 , const char T_3 * V_41 , T_4 V_76 , T_5 * V_77 )
{
return - V_78 ;
}
static T_2 F_34 ( struct V_58 * V_58 , char T_3 * V_41 , T_4 V_76 , T_5 * V_77 )
{
F_35 ( V_47 ) ;
struct V_37 * V_14 = V_58 -> V_60 ;
int V_79 ;
int V_80 ;
V_79 = ( ( V_14 -> V_6 & V_81 ) != 0 ) ?
sizeof( struct V_25 ) : sizeof( struct V_82 ) ;
if ( V_76 < V_79 )
return 0 ;
V_80 = F_36 ( & V_14 -> V_72 ) ;
if ( V_80 )
return - V_83 ;
while ( V_80 == 0 ) {
if ( V_14 -> V_42 == V_14 -> V_84 ) {
F_37 ( & V_14 -> V_36 -> V_47 , & V_47 , V_85 ) ;
while ( V_14 -> V_42 == V_14 -> V_84 ) {
if ( V_58 -> V_86 & V_87 ) {
V_80 = - V_88 ;
break;
}
if ( F_38 ( V_89 ) ) {
V_80 = - V_83 ;
break;
}
if ( ! V_14 -> V_36 -> V_65 ) {
V_80 = - V_73 ;
break;
}
F_20 ( & V_14 -> V_72 ) ;
F_39 () ;
if ( F_36 ( & V_14 -> V_72 ) ) {
F_40 ( & V_14 -> V_36 -> V_47 , & V_47 ) ;
return - V_90 ;
}
F_41 ( V_85 ) ;
}
F_40 ( & V_14 -> V_36 -> V_47 , & V_47 ) ;
}
if ( V_80 ) {
F_20 ( & V_14 -> V_72 ) ;
return V_80 ;
}
while ( V_14 -> V_42 != V_14 -> V_84 &&
V_80 + V_79 <= V_76 ) {
if ( ( V_14 -> V_6 & V_81 ) == 0 ) {
if ( V_14 -> V_41 [ V_14 -> V_84 ] . V_34 != V_39 ) {
struct V_82 V_91 ;
V_91 . V_3 = V_14 -> V_41 [ V_14 -> V_84 ] . V_33 ;
V_91 . V_49 = V_14 -> V_41 [ V_14 -> V_84 ] . V_49 ;
if ( F_42 ( V_41 + V_80 , & V_91 , sizeof( struct V_82 ) ) ) {
F_20 ( & V_14 -> V_72 ) ;
return - V_92 ;
}
V_80 += sizeof( struct V_82 ) ;
}
} else {
if ( V_14 -> V_41 [ V_14 -> V_84 ] . V_34 != V_39 ||
( V_14 -> V_6 & V_40 ) != 0 ) {
if ( F_42 ( V_41 + V_80 , V_14 -> V_41 + V_14 -> V_84 , sizeof( struct V_25 ) ) ) {
F_20 ( & V_14 -> V_72 ) ;
return - V_92 ;
}
V_80 += sizeof( struct V_25 ) ;
}
}
V_14 -> V_84 = ( V_14 -> V_84 + 1 ) & ( V_43 - 1 ) ;
}
}
F_20 ( & V_14 -> V_72 ) ;
return V_80 ;
}
static unsigned int F_43 ( struct V_58 * V_58 , T_6 * V_47 )
{
struct V_37 * V_14 = V_58 -> V_60 ;
F_44 ( V_58 , & V_14 -> V_36 -> V_47 , V_47 ) ;
if ( V_14 -> V_42 != V_14 -> V_84 )
return V_93 | V_94 ;
if ( ! V_14 -> V_36 -> V_65 )
return V_95 | V_96 ;
return 0 ;
}
static T_7 int F_45 ( struct V_36 * V_36 , unsigned int V_97 , void T_3 * V_98 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_4 V_5 ;
struct V_99 * V_100 = NULL ;
struct V_25 * V_26 ;
struct V_1 * V_12 ;
struct V_24 * V_29 ;
int V_27 ;
V_100 = F_46 ( sizeof( struct V_99 ) , V_70 ) ;
if ( ! V_100 )
return - V_71 ;
V_26 = & V_100 -> V_26 ;
if ( V_97 == V_101 || V_97 == V_102 ) {
if ( F_47 ( V_100 , V_98 ,
sizeof( * V_100 ) ) )
goto V_103;
} else {
if ( F_47 ( V_26 , V_98 , sizeof( * V_26 ) ) )
goto V_103;
}
switch ( V_97 ) {
case V_104 :
V_5 . V_15 = V_26 -> V_15 ;
V_5 . V_7 = V_26 -> V_7 ;
if ( ( V_12 = F_1 ( V_3 , & V_5 ) ) == NULL )
goto V_105;
if ( V_26 -> V_34 >= V_12 -> V_30 )
goto V_105;
V_29 = V_12 -> V_29 [ V_26 -> V_34 ] ;
if ( V_26 -> V_35 >= V_29 -> V_31 )
goto V_105;
V_26 -> V_33 = V_29 -> V_32 [ V_26 -> V_35 ] . V_3 ;
if ( F_42 ( V_98 , V_26 , sizeof( * V_26 ) ) )
goto V_103;
goto V_106;
default:
if ( V_97 != V_107 &&
V_97 != V_101 &&
V_26 -> V_15 == V_51 )
goto V_105;
if ( V_26 -> V_7 == V_108 ) {
V_29 = F_4 ( V_3 , V_26 ) ;
if ( V_29 == NULL )
goto V_105;
} else {
V_5 . V_15 = V_26 -> V_15 ;
V_5 . V_7 = V_26 -> V_7 ;
if ( ( V_12 = F_1 ( V_3 , & V_5 ) ) == NULL )
goto V_105;
if ( V_26 -> V_34 >= V_12 -> V_30 )
goto V_105;
V_29 = V_12 -> V_29 [ V_26 -> V_34 ] ;
if ( V_97 == V_109 ) {
if ( V_26 -> V_35 >= V_29 -> V_31 )
goto V_105;
} else if ( V_26 -> V_35 >= V_29 -> V_110 )
goto V_105;
else if ( ( V_97 == V_101 || V_97 == V_102 ) &&
( V_100 -> V_111 > V_112 ||
V_26 -> V_35 + V_100 -> V_111 > V_29 -> V_110 ) )
goto V_105;
}
switch ( V_97 ) {
case V_107 :
V_26 -> V_49 = V_29 -> V_49 [ V_26 -> V_35 ] ;
if ( F_42 ( V_98 , V_26 , sizeof( * V_26 ) ) )
goto V_103;
goto V_106;
case V_113 :
V_29 -> V_49 [ V_26 -> V_35 ] = V_26 -> V_49 ;
goto V_106;
case V_109 :
V_27 = V_29 -> V_32 [ V_26 -> V_35 ] . V_114 ;
F_21 ( V_100 ) ;
return V_27 ;
case V_101 :
for ( V_27 = 0 ; V_27 < V_100 -> V_111 ; V_27 ++ )
V_100 -> V_115 [ V_27 ] =
V_29 -> V_49 [ V_26 -> V_35 + V_27 ] ;
if ( F_42 ( V_98 , V_100 ,
sizeof( * V_100 ) ) )
goto V_103;
goto V_106;
case V_102 :
for ( V_27 = 0 ; V_27 < V_100 -> V_111 ; V_27 ++ )
V_29 -> V_49 [ V_26 -> V_35 + V_27 ] =
V_100 -> V_115 [ V_27 ] ;
goto V_106;
}
V_106:
F_21 ( V_100 ) ;
return 0 ;
V_103:
F_21 ( V_100 ) ;
return - V_92 ;
V_105:
F_21 ( V_100 ) ;
return - V_78 ;
}
}
static T_7 int F_48 ( struct V_36 * V_36 , unsigned int V_97 , void T_3 * V_98 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_116 * V_117 = F_49 ( V_3 ) ;
int V_118 , V_119 ;
char * V_120 ;
if ( F_50 ( V_118 , ( int T_3 * ) V_98 ) )
return - V_92 ;
if ( ( V_120 = F_46 ( V_121 , V_70 ) ) == NULL )
return - V_71 ;
if ( ( V_119 = F_51 ( V_117 , V_118 , V_120 , V_121 - 1 ) ) < 0 ) {
F_21 ( V_120 ) ;
return - V_78 ;
}
if ( F_42 ( V_98 + sizeof( int ) , V_120 , V_119 + 1 ) ) {
F_21 ( V_120 ) ;
return - V_92 ;
}
F_21 ( V_120 ) ;
return V_119 ;
}
static long F_52 ( struct V_58 * V_58 , unsigned int V_97 , unsigned long V_122 )
{
struct V_37 * V_14 = V_58 -> V_60 ;
struct V_36 * V_36 = V_14 -> V_36 ;
struct V_2 * V_3 ;
struct V_123 V_124 ;
struct V_4 V_5 ;
struct V_125 V_126 ;
struct V_127 V_128 ;
struct V_1 * V_12 ;
struct V_24 * V_29 ;
void T_3 * V_98 = ( void T_3 * ) V_122 ;
int V_27 , V_129 = - V_78 ;
F_17 ( & V_36 -> V_63 ) ;
if ( ! V_36 -> V_65 ) {
V_129 = - V_69 ;
goto V_130;
}
V_3 = V_36 -> V_3 ;
switch ( V_97 ) {
case V_131 :
V_129 = F_53 ( V_132 , ( int T_3 * ) V_122 ) ?
- V_92 : 0 ;
break;
case V_133 :
if ( V_122 < 0 || V_122 >= V_3 -> V_134 )
break;
for ( V_27 = 0 ; V_27 < V_3 -> V_135 ; V_27 ++ )
if ( V_3 -> V_136 [ V_27 ] . type ==
V_137 && V_122 -- == 0 )
break;
if ( V_27 < V_3 -> V_135 )
V_129 = V_3 -> V_136 [ V_27 ] . V_32 ;
break;
case V_138 :
{
struct V_116 * V_117 = F_49 ( V_3 ) ;
struct V_139 * V_140 = V_3 -> V_141 ;
V_128 . V_142 = V_143 ;
V_128 . V_144 = V_117 -> V_145 -> V_144 ;
V_128 . V_146 = V_117 -> V_146 ;
V_128 . V_147 = V_140 -> V_147 ;
V_128 . V_148 = F_54 ( V_117 -> V_149 . V_150 ) ;
V_128 . V_151 = F_54 ( V_117 -> V_149 . V_152 ) ;
V_128 . V_153 = F_54 ( V_117 -> V_149 . V_154 ) ;
V_128 . V_155 = V_3 -> V_134 ;
V_129 = F_42 ( V_98 , & V_128 , sizeof( V_128 ) ) ?
- V_92 : 0 ;
break;
}
case V_156 :
V_129 = F_53 ( V_14 -> V_6 , ( int T_3 * ) V_122 ) ?
- V_92 : 0 ;
break;
case V_157 :
{
int V_158 ;
if ( F_50 ( V_158 , ( int T_3 * ) V_122 ) ) {
V_129 = - V_92 ;
break;
}
if ( ( V_158 & ~ V_159 ) != 0 ||
( ( V_158 & V_40 ) != 0 &&
( V_158 & V_81 ) == 0 ) )
break;
V_14 -> V_6 = V_158 ;
V_129 = 0 ;
break;
}
case V_160 :
V_129 = F_48 ( V_36 , V_97 , V_98 ) ;
break;
case V_161 :
F_55 ( V_3 ) ;
V_129 = 0 ;
break;
case V_162 :
if ( F_47 ( & V_5 , V_98 , sizeof( V_5 ) ) ) {
V_129 = - V_92 ;
break;
}
if ( V_5 . V_15 == V_53 )
break;
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
F_56 ( V_3 , V_12 , V_163 ) ;
F_57 ( V_3 ) ;
V_129 = 0 ;
break;
case V_164 :
if ( F_47 ( & V_5 , V_98 , sizeof( V_5 ) ) ) {
V_129 = - V_92 ;
break;
}
if ( V_5 . V_15 == V_51 )
break;
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
F_56 ( V_3 , V_12 , V_165 ) ;
F_57 ( V_3 ) ;
V_129 = 0 ;
break;
case V_166 :
if ( F_47 ( & V_5 , V_98 , sizeof( V_5 ) ) ) {
V_129 = - V_92 ;
break;
}
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
V_5 . V_167 = V_12 -> V_30 ;
V_129 = F_42 ( V_98 , & V_5 , sizeof( V_5 ) ) ?
- V_92 : 0 ;
break;
case V_168 :
if ( F_47 ( & V_126 , V_98 , sizeof( V_126 ) ) ) {
V_129 = - V_92 ;
break;
}
V_5 . V_15 = V_126 . V_15 ;
V_5 . V_7 = V_126 . V_7 ;
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
if ( V_126 . V_34 >= V_12 -> V_30 )
break;
V_29 = V_12 -> V_29 [ V_126 . V_34 ] ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_15 = V_5 . V_15 ;
V_126 . V_7 = V_5 . V_7 ;
V_126 . V_34 = V_29 -> V_110 - 1 ;
V_126 . V_31 = V_29 -> V_31 ;
V_126 . V_6 = V_29 -> V_6 ;
V_126 . V_169 = V_29 -> V_169 ;
V_126 . V_170 = V_29 -> V_170 ;
V_126 . V_171 = V_29 -> V_171 ;
V_126 . V_172 = V_29 -> V_172 ;
V_126 . V_173 = V_29 -> V_173 ;
V_126 . V_174 = V_29 -> V_174 ;
V_126 . V_175 = V_29 -> V_175 ;
V_126 . V_176 = V_29 -> V_176 ;
V_126 . V_177 = V_29 -> V_177 ;
V_129 = F_42 ( V_98 , & V_126 , sizeof( V_126 ) ) ?
- V_92 : 0 ;
break;
case V_104 :
case V_107 :
case V_113 :
case V_101 :
case V_102 :
case V_109 :
V_129 = F_45 ( V_36 , V_97 , V_98 ) ;
break;
case V_178 :
if ( F_47 ( & V_124 , V_98 , sizeof( V_124 ) ) ) {
V_129 = - V_92 ;
break;
}
if ( V_124 . V_56 >= V_3 -> V_135 )
break;
V_124 . type = V_3 -> V_136 [ V_124 . V_56 ] . type ;
V_124 . V_32 = V_3 -> V_136 [ V_124 . V_56 ] . V_32 ;
V_124 . V_179 = V_3 -> V_136 [ V_124 . V_56 ] . V_179 ;
V_129 = F_42 ( V_98 , & V_124 , sizeof( V_124 ) ) ?
- V_92 : 0 ;
break;
default:
if ( F_58 ( V_97 ) != 'H' || F_59 ( V_97 ) != V_180 )
break;
if ( F_60 ( V_97 ) == F_60 ( F_61 ( 0 ) ) ) {
int V_119 = strlen ( V_3 -> V_181 ) + 1 ;
if ( V_119 > F_62 ( V_97 ) )
V_119 = F_62 ( V_97 ) ;
V_129 = F_42 ( V_98 , V_3 -> V_181 , V_119 ) ?
- V_92 : V_119 ;
break;
}
if ( F_60 ( V_97 ) == F_60 ( F_63 ( 0 ) ) ) {
int V_119 = strlen ( V_3 -> V_182 ) + 1 ;
if ( V_119 > F_62 ( V_97 ) )
V_119 = F_62 ( V_97 ) ;
V_129 = F_42 ( V_98 , V_3 -> V_182 , V_119 ) ?
- V_92 : V_119 ;
break;
}
}
V_130:
F_20 ( & V_36 -> V_63 ) ;
return V_129 ;
}
static long F_64 ( struct V_58 * V_58 , unsigned int V_97 , unsigned long V_122 )
{
return F_52 ( V_58 , V_97 , ( unsigned long ) F_65 ( V_122 ) ) ;
}
static char * F_66 ( struct V_183 * V_117 , T_8 * V_184 )
{
return F_67 ( V_70 , L_1 , F_68 ( V_117 ) ) ;
}
int F_69 ( struct V_2 * V_3 , unsigned int V_185 )
{
struct V_36 * V_36 ;
struct V_139 * V_140 = V_3 -> V_141 ;
int V_80 ;
if ( ! V_185 ) {
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_135 ; V_27 ++ )
if ( V_3 -> V_136 [ V_27 ] . type ==
V_137 &&
! F_70 ( V_3 -> V_136 [ V_27 ] . V_32 ) )
break;
if ( V_27 == V_3 -> V_135 )
return - 1 ;
}
if ( ! ( V_36 = F_26 ( sizeof( struct V_36 ) , V_70 ) ) )
return - 1 ;
F_71 ( & V_36 -> V_47 ) ;
F_72 ( & V_36 -> V_14 ) ;
F_73 ( & V_36 -> V_38 ) ;
F_27 ( & V_36 -> V_63 ) ;
V_3 -> V_36 = V_36 ;
V_36 -> V_3 = V_3 ;
V_36 -> V_65 = 1 ;
V_80 = F_74 ( V_140 -> V_67 , & V_186 ) ;
if ( V_80 ) {
F_75 ( V_3 , L_2 ) ;
V_3 -> V_36 = NULL ;
F_21 ( V_36 ) ;
return - 1 ;
}
return 0 ;
}
void F_76 ( struct V_2 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_36 ;
struct V_139 * V_140 = V_3 -> V_141 ;
F_17 ( & V_36 -> V_63 ) ;
V_36 -> V_65 = 0 ;
F_77 ( V_140 -> V_67 , & V_186 ) ;
if ( V_36 -> V_64 ) {
F_20 ( & V_36 -> V_63 ) ;
F_18 ( V_36 -> V_3 ) ;
F_10 ( & V_36 -> V_47 ) ;
} else {
F_20 ( & V_36 -> V_63 ) ;
F_21 ( V_36 ) ;
}
}
