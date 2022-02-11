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
F_19 ( V_14 -> V_36 -> V_3 , V_66 ) ;
} else {
F_20 ( & V_14 -> V_36 -> V_63 ) ;
F_21 ( V_14 -> V_36 ) ;
F_22 ( V_14 ) ;
return 0 ;
}
}
F_20 ( & V_14 -> V_36 -> V_63 ) ;
F_22 ( V_14 ) ;
return 0 ;
}
static int F_23 ( struct V_61 * V_61 , struct V_58 * V_58 )
{
struct V_37 * V_14 ;
struct V_67 * V_68 ;
struct V_2 * V_3 ;
struct V_36 * V_36 ;
int V_69 ;
V_68 = F_24 ( F_25 ( V_61 ) ) ;
if ( ! V_68 )
return - V_70 ;
V_3 = F_26 ( V_68 ) ;
V_36 = V_3 -> V_36 ;
if ( ! ( V_14 = F_27 ( sizeof( struct V_37 ) ) ) )
return - V_71 ;
F_28 ( & V_14 -> V_72 ) ;
V_14 -> V_36 = V_36 ;
V_58 -> V_60 = V_14 ;
if ( V_14 -> V_36 -> V_65 ) {
if ( ! V_14 -> V_36 -> V_64 ++ ) {
V_69 = F_29 ( V_36 -> V_3 ) ;
if ( V_69 < 0 )
goto V_73;
}
} else {
V_69 = - V_70 ;
goto V_73;
}
F_30 ( & V_14 -> V_36 -> V_38 ) ;
F_31 ( & V_14 -> V_62 , & V_36 -> V_14 ) ;
F_32 ( & V_14 -> V_36 -> V_38 ) ;
F_17 ( & V_36 -> V_63 ) ;
if ( ! V_14 -> V_36 -> V_64 ++ )
if ( V_14 -> V_36 -> V_65 ) {
struct V_2 * V_3 = V_36 -> V_3 ;
V_69 = F_19 ( V_3 , V_74 ) ;
if ( V_69 < 0 )
goto V_75;
V_69 = F_29 ( V_3 ) ;
if ( V_69 < 0 )
goto V_76;
}
F_20 ( & V_36 -> V_63 ) ;
return 0 ;
V_76:
F_19 ( V_3 , V_66 ) ;
V_75:
F_20 ( & V_36 -> V_63 ) ;
V_73:
V_58 -> V_60 = NULL ;
F_22 ( V_14 ) ;
return V_69 ;
}
static T_2 F_33 ( struct V_58 * V_58 , const char T_3 * V_41 , T_4 V_77 , T_5 * V_78 )
{
return - V_79 ;
}
static T_2 F_34 ( struct V_58 * V_58 , char T_3 * V_41 , T_4 V_77 , T_5 * V_78 )
{
F_35 ( V_47 ) ;
struct V_37 * V_14 = V_58 -> V_60 ;
int V_80 ;
int V_81 ;
V_80 = ( ( V_14 -> V_6 & V_82 ) != 0 ) ?
sizeof( struct V_25 ) : sizeof( struct V_83 ) ;
if ( V_77 < V_80 )
return 0 ;
V_81 = F_36 ( & V_14 -> V_72 ) ;
if ( V_81 )
return - V_84 ;
while ( V_81 == 0 ) {
if ( V_14 -> V_42 == V_14 -> V_85 ) {
F_37 ( & V_14 -> V_36 -> V_47 , & V_47 , V_86 ) ;
while ( V_14 -> V_42 == V_14 -> V_85 ) {
if ( F_38 ( V_87 ) ) {
V_81 = - V_84 ;
break;
}
if ( ! V_14 -> V_36 -> V_65 ) {
V_81 = - V_88 ;
break;
}
if ( V_58 -> V_89 & V_90 ) {
V_81 = - V_91 ;
break;
}
F_20 ( & V_14 -> V_72 ) ;
F_39 () ;
if ( F_36 ( & V_14 -> V_72 ) ) {
F_40 ( & V_14 -> V_36 -> V_47 , & V_47 ) ;
return - V_92 ;
}
F_41 ( V_86 ) ;
}
F_40 ( & V_14 -> V_36 -> V_47 , & V_47 ) ;
}
if ( V_81 ) {
F_20 ( & V_14 -> V_72 ) ;
return V_81 ;
}
while ( V_14 -> V_42 != V_14 -> V_85 &&
V_81 + V_80 <= V_77 ) {
if ( ( V_14 -> V_6 & V_82 ) == 0 ) {
if ( V_14 -> V_41 [ V_14 -> V_85 ] . V_34 != V_39 ) {
struct V_83 V_93 ;
V_93 . V_3 = V_14 -> V_41 [ V_14 -> V_85 ] . V_33 ;
V_93 . V_49 = V_14 -> V_41 [ V_14 -> V_85 ] . V_49 ;
if ( F_42 ( V_41 + V_81 , & V_93 , sizeof( struct V_83 ) ) ) {
F_20 ( & V_14 -> V_72 ) ;
return - V_94 ;
}
V_81 += sizeof( struct V_83 ) ;
}
} else {
if ( V_14 -> V_41 [ V_14 -> V_85 ] . V_34 != V_39 ||
( V_14 -> V_6 & V_40 ) != 0 ) {
if ( F_42 ( V_41 + V_81 , V_14 -> V_41 + V_14 -> V_85 , sizeof( struct V_25 ) ) ) {
F_20 ( & V_14 -> V_72 ) ;
return - V_94 ;
}
V_81 += sizeof( struct V_25 ) ;
}
}
V_14 -> V_85 = ( V_14 -> V_85 + 1 ) & ( V_43 - 1 ) ;
}
}
F_20 ( & V_14 -> V_72 ) ;
return V_81 ;
}
static unsigned int F_43 ( struct V_58 * V_58 , T_6 * V_47 )
{
struct V_37 * V_14 = V_58 -> V_60 ;
F_44 ( V_58 , & V_14 -> V_36 -> V_47 , V_47 ) ;
if ( V_14 -> V_42 != V_14 -> V_85 )
return V_95 | V_96 ;
if ( ! V_14 -> V_36 -> V_65 )
return V_97 | V_98 ;
return 0 ;
}
static T_7 int F_45 ( struct V_36 * V_36 , unsigned int V_99 , void T_3 * V_100 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_4 V_5 ;
struct V_101 * V_102 = NULL ;
struct V_25 * V_26 ;
struct V_1 * V_12 ;
struct V_24 * V_29 ;
int V_27 ;
V_102 = F_46 ( sizeof( struct V_101 ) , V_103 ) ;
if ( ! V_102 )
return - V_71 ;
V_26 = & V_102 -> V_26 ;
if ( V_99 == V_104 || V_99 == V_105 ) {
if ( F_47 ( V_102 , V_100 ,
sizeof( * V_102 ) ) )
goto V_106;
} else {
if ( F_47 ( V_26 , V_100 , sizeof( * V_26 ) ) )
goto V_106;
}
switch ( V_99 ) {
case V_107 :
V_5 . V_15 = V_26 -> V_15 ;
V_5 . V_7 = V_26 -> V_7 ;
if ( ( V_12 = F_1 ( V_3 , & V_5 ) ) == NULL )
goto V_108;
if ( V_26 -> V_34 >= V_12 -> V_30 )
goto V_108;
V_29 = V_12 -> V_29 [ V_26 -> V_34 ] ;
if ( V_26 -> V_35 >= V_29 -> V_31 )
goto V_108;
V_26 -> V_33 = V_29 -> V_32 [ V_26 -> V_35 ] . V_3 ;
if ( F_42 ( V_100 , V_26 , sizeof( * V_26 ) ) )
goto V_106;
goto V_109;
default:
if ( V_99 != V_110 &&
V_99 != V_104 &&
V_26 -> V_15 == V_51 )
goto V_108;
if ( V_26 -> V_7 == V_111 ) {
V_29 = F_4 ( V_3 , V_26 ) ;
if ( V_29 == NULL )
goto V_108;
} else {
V_5 . V_15 = V_26 -> V_15 ;
V_5 . V_7 = V_26 -> V_7 ;
if ( ( V_12 = F_1 ( V_3 , & V_5 ) ) == NULL )
goto V_108;
if ( V_26 -> V_34 >= V_12 -> V_30 )
goto V_108;
V_29 = V_12 -> V_29 [ V_26 -> V_34 ] ;
if ( V_99 == V_112 ) {
if ( V_26 -> V_35 >= V_29 -> V_31 )
goto V_108;
} else if ( V_26 -> V_35 >= V_29 -> V_113 )
goto V_108;
}
if ( ( V_99 == V_104 || V_99 == V_105 ) &&
( V_102 -> V_114 > V_115 ||
V_26 -> V_35 + V_102 -> V_114 > V_29 -> V_113 ) )
goto V_108;
switch ( V_99 ) {
case V_110 :
V_26 -> V_49 = V_29 -> V_49 [ V_26 -> V_35 ] ;
if ( F_42 ( V_100 , V_26 , sizeof( * V_26 ) ) )
goto V_106;
goto V_109;
case V_116 :
V_29 -> V_49 [ V_26 -> V_35 ] = V_26 -> V_49 ;
goto V_109;
case V_112 :
V_27 = V_29 -> V_32 [ V_26 -> V_35 ] . V_117 ;
F_21 ( V_102 ) ;
return V_27 ;
case V_104 :
for ( V_27 = 0 ; V_27 < V_102 -> V_114 ; V_27 ++ )
V_102 -> V_118 [ V_27 ] =
V_29 -> V_49 [ V_26 -> V_35 + V_27 ] ;
if ( F_42 ( V_100 , V_102 ,
sizeof( * V_102 ) ) )
goto V_106;
goto V_109;
case V_105 :
for ( V_27 = 0 ; V_27 < V_102 -> V_114 ; V_27 ++ )
V_29 -> V_49 [ V_26 -> V_35 + V_27 ] =
V_102 -> V_118 [ V_27 ] ;
goto V_109;
}
V_109:
F_21 ( V_102 ) ;
return 0 ;
V_106:
F_21 ( V_102 ) ;
return - V_94 ;
V_108:
F_21 ( V_102 ) ;
return - V_79 ;
}
}
static T_7 int F_48 ( struct V_36 * V_36 , unsigned int V_99 , void T_3 * V_100 )
{
struct V_2 * V_3 = V_36 -> V_3 ;
struct V_119 * V_120 = F_49 ( V_3 ) ;
int V_121 , V_122 ;
char * V_123 ;
if ( F_50 ( V_121 , ( int T_3 * ) V_100 ) )
return - V_94 ;
if ( ( V_123 = F_46 ( V_124 , V_103 ) ) == NULL )
return - V_71 ;
if ( ( V_122 = F_51 ( V_120 , V_121 , V_123 , V_124 - 1 ) ) < 0 ) {
F_21 ( V_123 ) ;
return - V_79 ;
}
if ( F_42 ( V_100 + sizeof( int ) , V_123 , V_122 + 1 ) ) {
F_21 ( V_123 ) ;
return - V_94 ;
}
F_21 ( V_123 ) ;
return V_122 ;
}
static long F_52 ( struct V_58 * V_58 , unsigned int V_99 , unsigned long V_125 )
{
struct V_37 * V_14 = V_58 -> V_60 ;
struct V_36 * V_36 = V_14 -> V_36 ;
struct V_2 * V_3 ;
struct V_126 V_127 ;
struct V_4 V_5 ;
struct V_128 V_129 ;
struct V_130 V_131 ;
struct V_1 * V_12 ;
struct V_24 * V_29 ;
void T_3 * V_100 = ( void T_3 * ) V_125 ;
int V_27 , V_132 = - V_79 ;
F_17 ( & V_36 -> V_63 ) ;
if ( ! V_36 -> V_65 ) {
V_132 = - V_70 ;
goto V_133;
}
V_3 = V_36 -> V_3 ;
switch ( V_99 ) {
case V_134 :
V_132 = F_53 ( V_135 , ( int T_3 * ) V_125 ) ?
- V_94 : 0 ;
break;
case V_136 :
if ( V_125 >= V_3 -> V_137 )
break;
for ( V_27 = 0 ; V_27 < V_3 -> V_138 ; V_27 ++ )
if ( V_3 -> V_139 [ V_27 ] . type ==
V_140 && V_125 -- == 0 )
break;
if ( V_27 < V_3 -> V_138 )
V_132 = V_3 -> V_139 [ V_27 ] . V_32 ;
break;
case V_141 :
{
struct V_119 * V_120 = F_49 ( V_3 ) ;
struct V_142 * V_143 = V_3 -> V_144 ;
memset ( & V_131 , 0 , sizeof( V_131 ) ) ;
V_131 . V_145 = V_146 ;
V_131 . V_147 = V_120 -> V_148 -> V_147 ;
V_131 . V_149 = V_120 -> V_149 ;
V_131 . V_150 = V_143 -> V_150 ;
V_131 . V_151 = F_54 ( V_120 -> V_152 . V_153 ) ;
V_131 . V_154 = F_54 ( V_120 -> V_152 . V_155 ) ;
V_131 . V_156 = F_54 ( V_120 -> V_152 . V_157 ) ;
V_131 . V_158 = V_3 -> V_137 ;
V_132 = F_42 ( V_100 , & V_131 , sizeof( V_131 ) ) ?
- V_94 : 0 ;
break;
}
case V_159 :
V_132 = F_53 ( V_14 -> V_6 , ( int T_3 * ) V_125 ) ?
- V_94 : 0 ;
break;
case V_160 :
{
int V_161 ;
if ( F_50 ( V_161 , ( int T_3 * ) V_125 ) ) {
V_132 = - V_94 ;
break;
}
if ( ( V_161 & ~ V_162 ) != 0 ||
( ( V_161 & V_40 ) != 0 &&
( V_161 & V_82 ) == 0 ) )
break;
V_14 -> V_6 = V_161 ;
V_132 = 0 ;
break;
}
case V_163 :
V_132 = F_48 ( V_36 , V_99 , V_100 ) ;
break;
case V_164 :
F_55 ( V_3 ) ;
V_36 -> V_165 = true ;
V_132 = 0 ;
break;
case V_166 :
if ( F_47 ( & V_5 , V_100 , sizeof( V_5 ) ) ) {
V_132 = - V_94 ;
break;
}
if ( V_5 . V_15 == V_53 )
break;
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
F_56 ( V_3 , V_12 , V_167 ) ;
F_57 ( V_3 ) ;
V_132 = 0 ;
break;
case V_168 :
if ( F_47 ( & V_5 , V_100 , sizeof( V_5 ) ) ) {
V_132 = - V_94 ;
break;
}
if ( V_5 . V_15 == V_51 )
break;
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
F_56 ( V_3 , V_12 , V_169 ) ;
F_57 ( V_3 ) ;
V_132 = 0 ;
break;
case V_170 :
if ( F_47 ( & V_5 , V_100 , sizeof( V_5 ) ) ) {
V_132 = - V_94 ;
break;
}
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
V_5 . V_171 = V_12 -> V_30 ;
V_132 = F_42 ( V_100 , & V_5 , sizeof( V_5 ) ) ?
- V_94 : 0 ;
break;
case V_172 :
if ( F_47 ( & V_129 , V_100 , sizeof( V_129 ) ) ) {
V_132 = - V_94 ;
break;
}
V_5 . V_15 = V_129 . V_15 ;
V_5 . V_7 = V_129 . V_7 ;
V_12 = F_1 ( V_3 , & V_5 ) ;
if ( V_12 == NULL )
break;
if ( V_129 . V_34 >= V_12 -> V_30 )
break;
V_29 = V_12 -> V_29 [ V_129 . V_34 ] ;
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
V_129 . V_15 = V_5 . V_15 ;
V_129 . V_7 = V_5 . V_7 ;
V_129 . V_34 = V_29 -> V_113 - 1 ;
V_129 . V_31 = V_29 -> V_31 ;
V_129 . V_6 = V_29 -> V_6 ;
V_129 . V_173 = V_29 -> V_173 ;
V_129 . V_174 = V_29 -> V_174 ;
V_129 . V_175 = V_29 -> V_175 ;
V_129 . V_176 = V_29 -> V_176 ;
V_129 . V_177 = V_29 -> V_177 ;
V_129 . V_178 = V_29 -> V_178 ;
V_129 . V_179 = V_29 -> V_179 ;
V_129 . V_180 = V_29 -> V_180 ;
V_129 . V_181 = V_29 -> V_181 ;
V_132 = F_42 ( V_100 , & V_129 , sizeof( V_129 ) ) ?
- V_94 : 0 ;
break;
case V_107 :
case V_110 :
case V_116 :
case V_104 :
case V_105 :
case V_112 :
if ( ! V_36 -> V_165 ) {
F_55 ( V_3 ) ;
V_36 -> V_165 = true ;
}
V_132 = F_45 ( V_36 , V_99 , V_100 ) ;
break;
case V_182 :
if ( F_47 ( & V_127 , V_100 , sizeof( V_127 ) ) ) {
V_132 = - V_94 ;
break;
}
if ( V_127 . V_56 >= V_3 -> V_138 )
break;
V_127 . type = V_3 -> V_139 [ V_127 . V_56 ] . type ;
V_127 . V_32 = V_3 -> V_139 [ V_127 . V_56 ] . V_32 ;
V_127 . V_183 = V_3 -> V_139 [ V_127 . V_56 ] . V_183 ;
V_132 = F_42 ( V_100 , & V_127 , sizeof( V_127 ) ) ?
- V_94 : 0 ;
break;
default:
if ( F_58 ( V_99 ) != 'H' || F_59 ( V_99 ) != V_184 )
break;
if ( F_60 ( V_99 ) == F_60 ( F_61 ( 0 ) ) ) {
int V_122 = strlen ( V_3 -> V_185 ) + 1 ;
if ( V_122 > F_62 ( V_99 ) )
V_122 = F_62 ( V_99 ) ;
V_132 = F_42 ( V_100 , V_3 -> V_185 , V_122 ) ?
- V_94 : V_122 ;
break;
}
if ( F_60 ( V_99 ) == F_60 ( F_63 ( 0 ) ) ) {
int V_122 = strlen ( V_3 -> V_186 ) + 1 ;
if ( V_122 > F_62 ( V_99 ) )
V_122 = F_62 ( V_99 ) ;
V_132 = F_42 ( V_100 , V_3 -> V_186 , V_122 ) ?
- V_94 : V_122 ;
break;
}
}
V_133:
F_20 ( & V_36 -> V_63 ) ;
return V_132 ;
}
static long F_64 ( struct V_58 * V_58 , unsigned int V_99 , unsigned long V_125 )
{
return F_52 ( V_58 , V_99 , ( unsigned long ) F_65 ( V_125 ) ) ;
}
static char * F_66 ( struct V_187 * V_120 , T_8 * V_188 )
{
return F_67 ( V_103 , L_1 , F_68 ( V_120 ) ) ;
}
int F_69 ( struct V_2 * V_3 , unsigned int V_189 )
{
struct V_36 * V_36 ;
struct V_142 * V_143 = V_3 -> V_144 ;
int V_81 ;
if ( ! V_189 ) {
unsigned int V_27 ;
for ( V_27 = 0 ; V_27 < V_3 -> V_138 ; V_27 ++ )
if ( V_3 -> V_139 [ V_27 ] . type ==
V_140 &&
! F_70 ( V_3 -> V_139 [ V_27 ] . V_32 ) )
break;
if ( V_27 == V_3 -> V_138 )
return - 1 ;
}
if ( ! ( V_36 = F_71 ( sizeof( struct V_36 ) , V_103 ) ) )
return - 1 ;
F_72 ( & V_36 -> V_47 ) ;
F_73 ( & V_36 -> V_14 ) ;
F_74 ( & V_36 -> V_38 ) ;
F_28 ( & V_36 -> V_63 ) ;
V_3 -> V_36 = V_36 ;
V_36 -> V_3 = V_3 ;
V_36 -> V_65 = 1 ;
V_81 = F_75 ( V_143 -> V_68 , & V_190 ) ;
if ( V_81 ) {
F_76 ( V_3 , L_2 ) ;
V_3 -> V_36 = NULL ;
F_21 ( V_36 ) ;
return - 1 ;
}
V_36 -> V_165 = V_3 -> V_191 & V_192 ;
V_36 -> V_193 = V_143 -> V_68 -> V_193 ;
return 0 ;
}
void F_77 ( struct V_2 * V_3 )
{
struct V_36 * V_36 = V_3 -> V_36 ;
struct V_142 * V_143 = V_3 -> V_144 ;
F_78 ( V_143 -> V_68 , & V_190 ) ;
F_17 ( & V_36 -> V_63 ) ;
V_36 -> V_65 = 0 ;
if ( V_36 -> V_64 ) {
F_20 ( & V_36 -> V_63 ) ;
F_18 ( V_36 -> V_3 ) ;
F_10 ( & V_36 -> V_47 ) ;
} else {
F_20 ( & V_36 -> V_63 ) ;
F_21 ( V_36 ) ;
}
}
