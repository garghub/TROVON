static inline struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (entry, &ib_mad_port_list, port_list) {
if ( V_5 -> V_3 == V_3 && V_5 -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
static inline struct V_1 *
F_3 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
F_5 ( & V_7 , V_6 ) ;
return V_5 ;
}
static inline T_1 F_6 ( T_1 V_8 )
{
return V_8 == V_9 ?
0 : V_8 ;
}
static int F_7 ( enum V_10 V_11 )
{
switch ( V_11 )
{
case V_12 :
return 0 ;
case V_13 :
return 1 ;
default:
return - 1 ;
}
}
static int F_8 ( T_1 V_8 )
{
return V_8 - V_14 ;
}
static int F_9 ( T_1 V_8 )
{
if ( ( V_8 < V_14 ) ||
( V_8 > V_15 ) )
return 0 ;
return 1 ;
}
static int F_10 ( char * V_16 )
{
if ( V_16 [ 0 ] || V_16 [ 1 ] || V_16 [ 2 ] )
return 1 ;
return 0 ;
}
static int F_11 (
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( V_18 -> V_16 [ V_23 ] , V_20 -> V_16 , 3 ) ) {
V_22 = V_18 -> V_25 [ V_23 ] ;
if ( V_22 ) {
if ( F_12 ( & V_22 , V_20 ) )
return 1 ;
else
break;
}
}
}
return 0 ;
}
int F_13 ( struct V_26 * V_27 )
{
return ( ( V_27 -> V_28 . V_22 & V_29 ) ||
( V_27 -> V_28 . V_22 == V_30 ) ||
( ( V_27 -> V_28 . V_8 == V_31 ) &&
( V_27 -> V_28 . V_32 & V_33 ) ) ) ;
}
struct V_34 * F_14 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
struct V_19 * V_20 ,
T_1 V_35 ,
T_2 V_36 ,
T_3 V_37 ,
void * V_38 ,
T_4 V_39 )
{
struct V_1 * V_40 ;
struct V_34 * V_41 = F_15 ( - V_42 ) ;
struct V_43 * V_44 ;
struct V_19 * V_45 = NULL ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_17 * V_18 ;
struct V_21 * V_22 ;
int V_50 , V_51 ;
unsigned long V_6 ;
T_1 V_8 , V_52 ;
V_51 = F_7 ( V_11 ) ;
if ( V_51 == - 1 ) {
F_16 ( & V_3 -> V_53 ,
L_1 ,
V_11 ) ;
goto V_54;
}
if ( V_35 && V_35 != V_55 ) {
F_16 ( & V_3 -> V_53 ,
L_2 ,
V_35 ) ;
goto V_54;
}
if ( V_20 ) {
if ( V_20 -> V_56 >= V_57 ) {
F_16 ( & V_3 -> V_53 ,
L_3 ,
V_20 -> V_56 ) ;
goto V_54;
}
if ( ! V_37 ) {
F_16 ( & V_3 -> V_53 ,
L_4 ) ;
goto V_54;
}
if ( V_20 -> V_8 >= V_58 ) {
if ( V_20 -> V_8 !=
V_9 ) {
F_16 ( & V_3 -> V_53 ,
L_5 ,
V_20 -> V_8 ) ;
goto V_54;
}
} else if ( V_20 -> V_8 == 0 ) {
F_16 ( & V_3 -> V_53 ,
L_6 ) ;
goto V_54;
} else if ( F_9 ( V_20 -> V_8 ) ) {
if ( ! F_10 ( V_20 -> V_16 ) ) {
F_16 ( & V_3 -> V_53 ,
L_7 ,
V_20 -> V_8 ) ;
goto V_54;
}
}
if ( ! F_17 ( V_20 -> V_8 ) ) {
if ( V_35 ) {
F_16 ( & V_3 -> V_53 ,
L_8 ,
V_20 -> V_8 ) ;
goto V_54;
}
}
if ( V_11 == V_12 ) {
if ( ( V_20 -> V_8 !=
V_59 ) &&
( V_20 -> V_8 !=
V_9 ) ) {
F_16 ( & V_3 -> V_53 ,
L_9 ,
V_20 -> V_8 ) ;
goto V_54;
}
} else {
if ( ( V_20 -> V_8 ==
V_59 ) ||
( V_20 -> V_8 ==
V_9 ) ) {
F_16 ( & V_3 -> V_53 ,
L_10 ,
V_20 -> V_8 ) ;
goto V_54;
}
}
} else {
if ( ! V_36 )
goto V_54;
if ( V_39 & V_60 )
goto V_54;
}
V_40 = F_3 ( V_3 , V_4 ) ;
if ( ! V_40 ) {
F_16 ( & V_3 -> V_53 , L_11 ) ;
V_41 = F_15 ( - V_61 ) ;
goto V_54;
}
if ( ! V_40 -> V_62 [ V_51 ] . V_63 ) {
F_16 ( & V_3 -> V_53 ,
L_12 , V_51 ) ;
V_41 = F_15 ( - V_64 ) ;
goto V_54;
}
V_44 = F_18 ( sizeof *V_44 , V_65 ) ;
if ( ! V_44 ) {
V_41 = F_15 ( - V_66 ) ;
goto V_54;
}
V_44 -> V_67 . V_68 = F_19 ( V_40 -> V_62 [ V_51 ] . V_63 -> V_69 ,
V_70 ) ;
if ( F_20 ( V_44 -> V_67 . V_68 ) ) {
V_41 = F_15 ( - V_66 ) ;
goto V_71;
}
if ( V_20 ) {
V_45 = F_21 ( V_20 , sizeof *V_45 , V_65 ) ;
if ( ! V_45 ) {
V_41 = F_15 ( - V_66 ) ;
goto V_72;
}
}
V_44 -> V_62 = & V_40 -> V_62 [ V_51 ] ;
V_44 -> V_45 = V_45 ;
V_44 -> V_67 . V_35 = V_35 ;
V_44 -> V_67 . V_3 = V_3 ;
V_44 -> V_67 . V_37 = V_37 ;
V_44 -> V_67 . V_36 = V_36 ;
V_44 -> V_67 . V_38 = V_38 ;
V_44 -> V_67 . V_63 = V_40 -> V_62 [ V_51 ] . V_63 ;
V_44 -> V_67 . V_4 = V_4 ;
V_44 -> V_67 . V_6 = V_39 ;
F_22 ( & V_44 -> V_73 ) ;
F_23 ( & V_44 -> V_74 ) ;
F_23 ( & V_44 -> V_75 ) ;
F_23 ( & V_44 -> V_76 ) ;
F_23 ( & V_44 -> V_77 ) ;
F_24 ( & V_44 -> V_78 , V_79 ) ;
F_23 ( & V_44 -> V_80 ) ;
F_25 ( & V_44 -> V_81 , V_82 ) ;
F_26 ( & V_44 -> V_83 , 1 ) ;
F_27 ( & V_44 -> V_84 ) ;
F_4 ( & V_40 -> V_85 , V_6 ) ;
V_44 -> V_67 . V_86 = ++ V_87 ;
if ( V_20 ) {
V_8 = F_6 ( V_20 -> V_8 ) ;
if ( ! F_9 ( V_8 ) ) {
V_47 = V_40 -> V_88 [ V_20 ->
V_56 ] . V_47 ;
if ( V_47 ) {
V_22 = V_47 -> V_25 [ V_8 ] ;
if ( V_22 ) {
if ( F_12 ( & V_22 ,
V_20 ) )
goto V_89;
}
}
V_50 = F_28 ( V_20 , V_44 ,
V_8 ) ;
} else {
V_49 = V_40 -> V_88 [ V_20 ->
V_56 ] . V_49 ;
if ( V_49 ) {
V_52 = F_8 ( V_8 ) ;
V_18 = V_49 -> V_18 [ V_52 ] ;
if ( V_18 ) {
if ( F_11 (
V_18 ,
V_20 ) )
goto V_89;
}
}
V_50 = F_29 ( V_20 , V_44 ) ;
}
if ( V_50 ) {
V_41 = F_15 ( V_50 ) ;
goto V_89;
}
}
F_30 ( & V_44 -> V_90 , & V_40 -> V_90 ) ;
F_5 ( & V_40 -> V_85 , V_6 ) ;
return & V_44 -> V_67 ;
V_89:
F_5 ( & V_40 -> V_85 , V_6 ) ;
F_31 ( V_45 ) ;
V_72:
F_32 ( V_44 -> V_67 . V_68 ) ;
V_71:
F_31 ( V_44 ) ;
V_54:
return V_41 ;
}
static inline int F_33 ( int V_91 )
{
return ( V_91 &
(
V_92 ) ) ;
}
static inline int F_34 ( int V_91 )
{
return ( V_91 &
( V_93 ) ) ;
}
static int F_35 ( struct V_94 * V_62 ,
struct V_95 * V_96 )
{
struct V_95 * * V_97 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_62 -> V_98 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_62 -> V_99 ; V_23 ++ )
if ( ! V_62 -> V_100 [ V_23 ] )
break;
if ( V_23 == V_62 -> V_99 ) {
V_97 = F_36 ( V_62 -> V_100 ,
sizeof V_96 *
( V_62 -> V_99 + 1 ) ,
V_101 ) ;
if ( ! V_97 ) {
V_23 = - V_66 ;
goto V_102;
}
V_62 -> V_100 = V_97 ;
V_62 -> V_99 ++ ;
}
V_62 -> V_100 [ V_23 ] = V_96 ;
F_37 ( & V_62 -> V_103 ) ;
V_102:
F_5 ( & V_62 -> V_98 , V_6 ) ;
return V_23 ;
}
struct V_34 * F_38 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
int V_91 ,
T_5 V_104 ,
T_3 V_37 ,
void * V_38 )
{
struct V_1 * V_40 ;
struct V_34 * V_41 ;
struct V_95 * V_96 ;
int V_51 ;
if ( ( F_33 ( V_91 ) && ! V_104 ) ||
( F_34 ( V_91 ) && ! V_37 ) ) {
V_41 = F_15 ( - V_42 ) ;
goto V_54;
}
V_51 = F_7 ( V_11 ) ;
if ( V_51 == - 1 ) {
V_41 = F_15 ( - V_42 ) ;
goto V_54;
}
V_40 = F_3 ( V_3 , V_4 ) ;
if ( ! V_40 ) {
V_41 = F_15 ( - V_61 ) ;
goto V_54;
}
V_96 = F_18 ( sizeof *V_96 , V_65 ) ;
if ( ! V_96 ) {
V_41 = F_15 ( - V_66 ) ;
goto V_54;
}
V_96 -> V_62 = & V_40 -> V_62 [ V_51 ] ;
V_96 -> V_67 . V_3 = V_3 ;
V_96 -> V_67 . V_37 = V_37 ;
V_96 -> V_67 . V_104 = V_104 ;
V_96 -> V_67 . V_38 = V_38 ;
V_96 -> V_67 . V_63 = V_40 -> V_62 [ V_51 ] . V_63 ;
V_96 -> V_67 . V_4 = V_4 ;
V_96 -> V_91 = V_91 ;
F_27 ( & V_96 -> V_84 ) ;
V_96 -> V_105 = F_35 (
& V_40 -> V_62 [ V_51 ] ,
V_96 ) ;
if ( V_96 -> V_105 < 0 ) {
V_41 = F_15 ( V_96 -> V_105 ) ;
goto V_71;
}
F_26 ( & V_96 -> V_83 , 1 ) ;
return & V_96 -> V_67 ;
V_71:
F_31 ( V_96 ) ;
V_54:
return V_41 ;
}
static inline void F_39 ( struct V_43 * V_44 )
{
if ( F_40 ( & V_44 -> V_83 ) )
F_41 ( & V_44 -> V_84 ) ;
}
static inline void F_42 ( struct V_95 * V_96 )
{
if ( F_40 ( & V_96 -> V_83 ) )
F_41 ( & V_96 -> V_84 ) ;
}
static void F_43 ( struct V_43 * V_44 )
{
struct V_1 * V_40 ;
unsigned long V_6 ;
F_44 ( V_44 ) ;
V_40 = V_44 -> V_62 -> V_40 ;
F_45 ( & V_44 -> V_78 ) ;
F_4 ( & V_40 -> V_85 , V_6 ) ;
F_46 ( V_44 ) ;
F_47 ( & V_44 -> V_90 ) ;
F_5 ( & V_40 -> V_85 , V_6 ) ;
F_48 ( V_40 -> V_106 ) ;
F_49 ( V_44 ) ;
F_39 ( V_44 ) ;
F_50 ( & V_44 -> V_84 ) ;
F_31 ( V_44 -> V_45 ) ;
F_32 ( V_44 -> V_67 . V_68 ) ;
F_31 ( V_44 ) ;
}
static void F_51 ( struct V_95 * V_96 )
{
struct V_94 * V_62 ;
unsigned long V_6 ;
V_62 = V_96 -> V_62 ;
F_4 ( & V_62 -> V_98 , V_6 ) ;
V_62 -> V_100 [ V_96 -> V_105 ] = NULL ;
F_52 ( & V_62 -> V_103 ) ;
F_5 ( & V_62 -> V_98 , V_6 ) ;
F_42 ( V_96 ) ;
F_50 ( & V_96 -> V_84 ) ;
F_31 ( V_96 ) ;
}
int F_53 ( struct V_34 * V_107 )
{
struct V_43 * V_44 ;
struct V_95 * V_96 ;
if ( V_107 -> V_86 ) {
V_44 = F_54 ( V_107 ,
struct V_43 ,
V_67 ) ;
F_43 ( V_44 ) ;
} else {
V_96 = F_54 ( V_107 ,
struct V_95 ,
V_67 ) ;
F_51 ( V_96 ) ;
}
return 0 ;
}
static void F_55 ( struct V_108 * V_109 )
{
struct V_110 * V_111 ;
unsigned long V_6 ;
F_56 ( ! V_109 -> V_111 ) ;
V_111 = V_109 -> V_111 ;
F_4 ( & V_111 -> V_73 , V_6 ) ;
F_47 ( & V_109 -> V_112 ) ;
V_111 -> V_113 -- ;
F_5 ( & V_111 -> V_73 , V_6 ) ;
}
static void F_57 ( struct V_94 * V_62 ,
struct V_114 * V_115 ,
struct V_116 * V_117 ,
int V_91 )
{
struct V_95 * V_96 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_62 -> V_98 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_62 -> V_99 ; V_23 ++ ) {
V_96 = V_62 -> V_100 [ V_23 ] ;
if ( ! V_96 ||
! ( V_96 -> V_91 & V_91 ) )
continue;
F_37 ( & V_96 -> V_83 ) ;
F_5 ( & V_62 -> V_98 , V_6 ) ;
V_96 -> V_67 . V_104 ( & V_96 -> V_67 ,
V_115 , V_117 ) ;
F_42 ( V_96 ) ;
F_4 ( & V_62 -> V_98 , V_6 ) ;
}
F_5 ( & V_62 -> V_98 , V_6 ) ;
}
static void F_58 ( struct V_94 * V_62 ,
struct V_118 * V_119 ,
int V_91 )
{
struct V_95 * V_96 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_62 -> V_98 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_62 -> V_99 ; V_23 ++ ) {
V_96 = V_62 -> V_100 [ V_23 ] ;
if ( ! V_96 ||
! ( V_96 -> V_91 & V_91 ) )
continue;
F_37 ( & V_96 -> V_83 ) ;
F_5 ( & V_62 -> V_98 , V_6 ) ;
V_96 -> V_67 . V_37 ( & V_96 -> V_67 ,
V_119 ) ;
F_42 ( V_96 ) ;
F_4 ( & V_62 -> V_98 , V_6 ) ;
}
F_5 ( & V_62 -> V_98 , V_6 ) ;
}
static void F_59 ( struct V_120 * V_63 ,
T_6 V_121 , T_7 V_122 , T_7 V_123 , T_1 V_4 ,
struct V_124 * V_125 )
{
memset ( V_125 , 0 , sizeof *V_125 ) ;
V_125 -> V_121 = V_121 ;
V_125 -> V_126 = V_127 ;
V_125 -> V_128 = V_129 ;
V_125 -> V_123 = V_123 ;
V_125 -> V_130 = sizeof( struct V_26 ) + sizeof( struct V_131 ) ;
V_125 -> V_132 = V_133 ;
V_125 -> V_63 = V_63 ;
V_125 -> V_122 = V_122 ;
V_125 -> V_134 = 0 ;
V_125 -> V_135 = 0 ;
V_125 -> V_4 = V_4 ;
}
static int F_60 ( struct V_43 * V_44 ,
struct V_136 * V_137 )
{
int V_41 = 0 ;
struct V_138 * V_139 = V_137 -> V_115 . V_27 ;
unsigned long V_6 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_1 * V_40 ;
struct V_43 * V_144 = NULL ;
struct V_2 * V_3 = V_44 -> V_67 . V_3 ;
T_1 V_4 ;
struct V_124 V_145 ;
struct V_146 * V_147 = & V_137 -> V_147 ;
if ( V_3 -> V_148 == V_149 &&
V_139 -> V_8 == V_9 )
V_4 = V_147 -> V_150 . V_151 . V_4 ;
else
V_4 = V_44 -> V_67 . V_4 ;
if ( ( F_61 ( V_139 ) ? V_139 -> V_152 : V_139 -> V_153 ) ==
V_154 &&
F_62 ( V_139 , V_3 -> V_148 , V_4 ) ==
V_155 ) {
V_41 = - V_42 ;
F_63 ( & V_3 -> V_53 , L_13 ) ;
goto V_102;
}
if ( F_64 ( V_139 , V_3 ) == V_155 &&
F_65 ( V_139 , V_3 ) == V_155 )
goto V_102;
V_141 = F_66 ( sizeof *V_141 , V_101 ) ;
if ( ! V_141 ) {
V_41 = - V_66 ;
F_63 ( & V_3 -> V_53 , L_14 ) ;
goto V_102;
}
V_141 -> V_143 = NULL ;
V_141 -> V_144 = NULL ;
V_143 = F_67 ( V_156 , V_101 ) ;
if ( ! V_143 ) {
V_41 = - V_66 ;
F_63 ( & V_3 -> V_53 , L_15 ) ;
F_31 ( V_141 ) ;
goto V_102;
}
F_59 ( V_44 -> V_67 . V_63 ,
V_147 -> V_121 , F_68 ( V_139 -> V_153 ) ,
V_147 -> V_150 . V_151 . V_123 ,
V_147 -> V_150 . V_151 . V_4 , & V_145 ) ;
V_41 = V_3 -> V_157 ( V_3 , 0 , V_4 , & V_145 , NULL ,
(struct V_26 * ) V_139 ,
(struct V_26 * ) & V_143 -> V_27 ) ;
switch ( V_41 )
{
case V_158 | V_159 :
if ( F_13 ( & V_143 -> V_27 . V_27 ) &&
V_44 -> V_67 . V_37 ) {
V_141 -> V_143 = V_143 ;
V_141 -> V_144 = V_44 ;
F_37 ( & V_44 -> V_83 ) ;
} else
F_69 ( V_156 , V_143 ) ;
break;
case V_158 | V_160 :
F_69 ( V_156 , V_143 ) ;
break;
case V_158 :
V_40 = F_3 ( V_44 -> V_67 . V_3 ,
V_44 -> V_67 . V_4 ) ;
if ( V_40 ) {
memcpy ( & V_143 -> V_27 . V_27 , V_139 , sizeof( struct V_26 ) ) ;
V_144 = F_70 ( V_40 ,
& V_143 -> V_27 . V_27 ) ;
}
if ( ! V_40 || ! V_144 ) {
F_69 ( V_156 , V_143 ) ;
break;
}
V_141 -> V_143 = V_143 ;
V_141 -> V_144 = V_144 ;
break;
default:
F_69 ( V_156 , V_143 ) ;
F_31 ( V_141 ) ;
V_41 = - V_42 ;
goto V_102;
}
V_141 -> V_137 = V_137 ;
F_37 ( & V_44 -> V_83 ) ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
F_30 ( & V_141 -> V_161 , & V_44 -> V_80 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
F_71 ( V_44 -> V_62 -> V_40 -> V_106 ,
& V_44 -> V_81 ) ;
V_41 = 1 ;
V_102:
return V_41 ;
}
static int F_72 ( int V_162 , int V_163 )
{
int V_164 , V_165 ;
V_164 = sizeof( struct V_26 ) - V_162 ;
if ( V_163 && V_164 ) {
V_165 = V_164 - V_163 % V_164 ;
return V_165 == V_164 ? 0 : V_165 ;
} else
return V_164 ;
}
static void F_73 ( struct V_136 * V_137 )
{
struct V_166 * V_167 , * V_168 ;
F_74 (s, t, &mad_send_wr->rmpp_list, list) {
F_47 ( & V_167 -> V_112 ) ;
F_31 ( V_167 ) ;
}
}
static int F_75 ( struct V_136 * V_147 ,
T_8 V_169 )
{
struct V_114 * V_115 = & V_147 -> V_115 ;
struct V_170 * V_171 = V_115 -> V_27 ;
struct V_166 * V_172 = NULL ;
int V_173 , V_164 , V_165 ;
V_115 -> V_164 = sizeof ( struct V_26 ) - V_115 -> V_162 ;
V_164 = V_115 -> V_164 ;
V_165 = V_147 -> V_165 ;
for ( V_173 = V_115 -> V_163 + V_165 ; V_173 > 0 ; V_173 -= V_164 ) {
V_172 = F_66 ( sizeof ( * V_172 ) + V_164 , V_169 ) ;
if ( ! V_172 ) {
F_63 ( & V_115 -> V_107 -> V_3 -> V_53 ,
L_16 ,
sizeof ( * V_172 ) + V_164 , V_169 ) ;
F_73 ( V_147 ) ;
return - V_66 ;
}
V_172 -> V_174 = ++ V_115 -> V_175 ;
F_30 ( & V_172 -> V_112 , & V_147 -> V_77 ) ;
}
if ( V_165 )
memset ( V_172 -> V_176 + V_164 - V_165 , 0 , V_165 ) ;
V_171 -> V_177 . V_35 = V_147 -> V_44 ->
V_67 . V_35 ;
V_171 -> V_177 . V_178 = V_179 ;
F_76 ( & V_171 -> V_177 , V_180 ) ;
V_147 -> V_181 = F_54 ( V_147 -> V_77 . V_182 ,
struct V_166 , V_112 ) ;
V_147 -> V_183 = V_147 -> V_181 ;
return 0 ;
}
int F_77 ( struct V_34 * V_67 )
{
return V_67 -> V_35 && ! ( V_67 -> V_6 & V_60 ) ;
}
struct V_114 * F_78 ( struct V_34 * V_107 ,
T_4 V_184 , T_7 V_123 ,
int V_185 ,
int V_162 , int V_163 ,
T_8 V_169 )
{
struct V_43 * V_44 ;
struct V_136 * V_137 ;
int V_165 , V_186 , V_41 , V_187 ;
void * V_188 ;
V_44 = F_54 ( V_107 , struct V_43 ,
V_67 ) ;
V_165 = F_72 ( V_162 , V_163 ) ;
V_186 = V_162 + V_163 + V_165 ;
if ( F_77 ( V_107 ) ) {
if ( ! V_185 && V_186 > sizeof( struct V_26 ) )
return F_15 ( - V_42 ) ;
} else
if ( V_185 || V_186 > sizeof( struct V_26 ) )
return F_15 ( - V_42 ) ;
V_187 = V_185 ? V_162 : sizeof( struct V_26 ) ;
V_188 = F_18 ( sizeof *V_137 + V_187 , V_169 ) ;
if ( ! V_188 )
return F_15 ( - V_66 ) ;
V_137 = V_188 + V_187 ;
F_23 ( & V_137 -> V_77 ) ;
V_137 -> V_115 . V_27 = V_188 ;
V_137 -> V_115 . V_162 = V_162 ;
V_137 -> V_115 . V_163 = V_163 ;
V_137 -> V_165 = V_165 ;
V_137 -> V_44 = V_44 ;
V_137 -> V_189 [ 0 ] . V_190 = V_162 ;
V_137 -> V_189 [ 0 ] . V_191 = V_107 -> V_68 -> V_191 ;
V_137 -> V_189 [ 1 ] . V_190 = sizeof( struct V_26 ) - V_162 ;
V_137 -> V_189 [ 1 ] . V_191 = V_107 -> V_68 -> V_191 ;
V_137 -> V_147 . V_121 = ( unsigned long ) V_137 ;
V_137 -> V_147 . V_189 = V_137 -> V_189 ;
V_137 -> V_147 . V_192 = 2 ;
V_137 -> V_147 . V_128 = V_193 ;
V_137 -> V_147 . V_194 = V_195 ;
V_137 -> V_147 . V_150 . V_151 . V_184 = V_184 ;
V_137 -> V_147 . V_150 . V_151 . V_196 = V_197 ;
V_137 -> V_147 . V_150 . V_151 . V_123 = V_123 ;
if ( V_185 ) {
V_41 = F_75 ( V_137 , V_169 ) ;
if ( V_41 ) {
F_31 ( V_188 ) ;
return F_15 ( V_41 ) ;
}
}
V_137 -> V_115 . V_107 = V_107 ;
F_37 ( & V_44 -> V_83 ) ;
return & V_137 -> V_115 ;
}
int F_79 ( T_1 V_8 )
{
if ( V_8 == V_198 )
return V_199 ;
else if ( ( V_8 == V_200 ) ||
( V_8 == V_201 ) ||
( V_8 == V_202 ) )
return V_203 ;
else if ( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) )
return V_204 ;
else
return V_205 ;
}
int F_17 ( T_1 V_8 )
{
if ( ( V_8 == V_198 ) ||
( V_8 == V_200 ) ||
( V_8 == V_201 ) ||
( V_8 == V_202 ) ||
( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) ) )
return 1 ;
return 0 ;
}
void * F_80 ( struct V_114 * V_115 , int V_206 )
{
struct V_136 * V_137 ;
struct V_207 * V_112 ;
V_137 = F_54 ( V_115 , struct V_136 ,
V_115 ) ;
V_112 = & V_137 -> V_181 -> V_112 ;
if ( V_137 -> V_181 -> V_174 < V_206 ) {
F_2 (mad_send_wr->cur_seg, list, list)
if ( V_137 -> V_181 -> V_174 == V_206 )
break;
} else if ( V_137 -> V_181 -> V_174 > V_206 ) {
F_81 (mad_send_wr->cur_seg, list, list)
if ( V_137 -> V_181 -> V_174 == V_206 )
break;
}
return V_137 -> V_181 -> V_176 ;
}
static inline void * F_82 ( struct V_136 * V_137 )
{
if ( V_137 -> V_115 . V_175 )
return F_80 ( & V_137 -> V_115 ,
V_137 -> V_206 ) ;
else
return V_137 -> V_115 . V_27 +
V_137 -> V_115 . V_162 ;
}
void F_83 ( struct V_114 * V_115 )
{
struct V_43 * V_44 ;
struct V_136 * V_137 ;
V_44 = F_54 ( V_115 -> V_107 ,
struct V_43 , V_67 ) ;
V_137 = F_54 ( V_115 , struct V_136 ,
V_115 ) ;
F_73 ( V_137 ) ;
F_31 ( V_115 -> V_27 ) ;
F_39 ( V_44 ) ;
}
int F_84 ( struct V_136 * V_137 )
{
struct V_94 * V_62 ;
struct V_207 * V_112 ;
struct V_146 * V_208 ;
struct V_34 * V_107 ;
struct V_209 * V_210 ;
unsigned long V_6 ;
int V_41 ;
V_62 = V_137 -> V_44 -> V_62 ;
V_137 -> V_147 . V_121 = ( unsigned long ) & V_137 -> V_109 ;
V_137 -> V_109 . V_111 = & V_62 -> V_211 ;
V_107 = V_137 -> V_115 . V_107 ;
V_210 = V_137 -> V_189 ;
V_210 [ 0 ] . V_212 = F_85 ( V_107 -> V_3 ,
V_137 -> V_115 . V_27 ,
V_210 [ 0 ] . V_190 ,
V_213 ) ;
if ( F_86 ( F_87 ( V_107 -> V_3 , V_210 [ 0 ] . V_212 ) ) )
return - V_66 ;
V_137 -> V_214 = V_210 [ 0 ] . V_212 ;
V_210 [ 1 ] . V_212 = F_85 ( V_107 -> V_3 ,
F_82 ( V_137 ) ,
V_210 [ 1 ] . V_190 ,
V_213 ) ;
if ( F_86 ( F_87 ( V_107 -> V_3 , V_210 [ 1 ] . V_212 ) ) ) {
F_88 ( V_107 -> V_3 ,
V_137 -> V_214 ,
V_210 [ 0 ] . V_190 , V_213 ) ;
return - V_66 ;
}
V_137 -> V_215 = V_210 [ 1 ] . V_212 ;
F_4 ( & V_62 -> V_211 . V_73 , V_6 ) ;
if ( V_62 -> V_211 . V_113 < V_62 -> V_211 . V_216 ) {
V_41 = F_89 ( V_107 -> V_63 , & V_137 -> V_147 ,
& V_208 ) ;
V_112 = & V_62 -> V_211 . V_112 ;
} else {
V_41 = 0 ;
V_112 = & V_62 -> V_217 ;
}
if ( ! V_41 ) {
V_62 -> V_211 . V_113 ++ ;
F_30 ( & V_137 -> V_109 . V_112 , V_112 ) ;
}
F_5 ( & V_62 -> V_211 . V_73 , V_6 ) ;
if ( V_41 ) {
F_88 ( V_107 -> V_3 ,
V_137 -> V_214 ,
V_210 [ 0 ] . V_190 , V_213 ) ;
F_88 ( V_107 -> V_3 ,
V_137 -> V_215 ,
V_210 [ 1 ] . V_190 , V_213 ) ;
}
return V_41 ;
}
int F_90 ( struct V_114 * V_115 ,
struct V_114 * * V_218 )
{
struct V_43 * V_44 ;
struct V_114 * V_219 ;
struct V_136 * V_137 ;
unsigned long V_6 ;
int V_41 = - V_42 ;
for (; V_115 ; V_115 = V_219 ) {
V_137 = F_54 ( V_115 ,
struct V_136 ,
V_115 ) ;
V_44 = V_137 -> V_44 ;
if ( ! V_115 -> V_107 -> V_36 ||
( V_115 -> V_220 &&
! V_115 -> V_107 -> V_37 ) ) {
V_41 = - V_42 ;
goto error;
}
if ( ! F_17 ( ( (struct V_221 * ) V_115 -> V_27 ) -> V_8 ) ) {
if ( V_44 -> V_67 . V_35 ) {
V_41 = - V_42 ;
goto error;
}
}
V_219 = V_115 -> V_182 ;
V_137 -> V_147 . V_150 . V_151 . V_222 = V_115 -> V_222 ;
if ( ( (struct V_221 * ) V_115 -> V_27 ) -> V_8 ==
V_9 ) {
V_41 = F_60 ( V_44 ,
V_137 ) ;
if ( V_41 < 0 )
goto error;
else if ( V_41 == 1 )
continue;
}
V_137 -> V_223 = ( (struct V_221 * ) V_115 -> V_27 ) -> V_223 ;
V_137 -> V_224 = F_91 ( V_115 -> V_220 ) ;
V_137 -> V_225 = V_115 -> V_226 ;
V_137 -> V_227 = V_115 -> V_226 ;
V_115 -> V_226 = 0 ;
V_137 -> V_83 = 1 + ( V_137 -> V_224 > 0 ) ;
V_137 -> V_126 = V_127 ;
F_37 ( & V_44 -> V_83 ) ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
F_30 ( & V_137 -> V_90 ,
& V_44 -> V_74 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
if ( F_77 ( & V_44 -> V_67 ) ) {
V_41 = F_92 ( V_137 ) ;
if ( V_41 >= 0 && V_41 != V_228 )
V_41 = F_84 ( V_137 ) ;
} else
V_41 = F_84 ( V_137 ) ;
if ( V_41 < 0 ) {
F_4 ( & V_44 -> V_73 , V_6 ) ;
F_47 ( & V_137 -> V_90 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
F_52 ( & V_44 -> V_83 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_218 )
* V_218 = V_115 ;
return V_41 ;
}
void F_93 ( struct V_118 * V_119 )
{
struct V_229 * V_230 , * V_231 ;
struct V_232 * V_233 ;
struct V_142 * V_234 ;
struct V_207 V_235 ;
F_23 ( & V_235 ) ;
F_94 ( & V_119 -> V_77 , & V_235 ) ;
F_74 (mad_recv_buf, temp_recv_buf,
&free_list, list) {
V_119 = F_54 ( V_230 , struct V_118 ,
V_236 ) ;
V_233 = F_54 ( V_119 ,
struct V_232 ,
V_237 ) ;
V_234 = F_54 ( V_233 , struct V_142 ,
V_238 ) ;
F_69 ( V_156 , V_234 ) ;
}
}
struct V_34 * F_95 ( struct V_120 * V_63 ,
T_1 V_35 ,
T_2 V_36 ,
T_3 V_37 ,
void * V_38 )
{
return F_15 ( - V_42 ) ;
}
int F_96 ( struct V_34 * V_107 ,
struct V_124 * V_125 )
{
F_63 ( & V_107 -> V_3 -> V_53 ,
L_17 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * * V_22 ,
struct V_19 * V_20 )
{
int V_23 ;
F_97 (i, mad_reg_req->method_mask, IB_MGMT_MAX_METHODS) {
if ( ( * V_22 ) -> V_67 [ V_23 ] ) {
F_98 ( L_18 , V_23 ) ;
return - V_42 ;
}
}
return 0 ;
}
static int F_99 ( struct V_21 * * V_22 )
{
* V_22 = F_18 ( sizeof ** V_22 , V_101 ) ;
if ( ! * V_22 ) {
F_98 ( L_19 ) ;
return - V_66 ;
}
return 0 ;
}
static int F_100 ( struct V_21 * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_239 ; V_23 ++ )
if ( V_22 -> V_67 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_101 ( struct V_46 * V_47 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_58 ; V_23 ++ )
if ( V_47 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_102 ( struct V_17 * V_18 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( V_18 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_103 ( struct V_17 * V_18 ,
char * V_16 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( ! memcmp ( V_18 -> V_16 [ V_23 ] , V_16 , 3 ) )
return V_23 ;
return - 1 ;
}
static int F_104 ( struct V_48 * V_49 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_240 ; V_23 ++ )
if ( V_49 -> V_18 [ V_23 ] )
return 1 ;
return 0 ;
}
static void F_105 ( struct V_21 * V_22 ,
struct V_43 * V_67 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_239 ; V_23 ++ ) {
if ( V_22 -> V_67 [ V_23 ] == V_67 ) {
V_22 -> V_67 [ V_23 ] = NULL ;
}
}
}
static int F_28 ( struct V_19 * V_20 ,
struct V_43 * V_241 ,
T_1 V_8 )
{
struct V_1 * V_40 ;
struct V_46 * * V_47 ;
struct V_21 * * V_22 ;
int V_23 , V_41 ;
V_40 = V_241 -> V_62 -> V_40 ;
V_47 = & V_40 -> V_88 [ V_20 -> V_56 ] . V_47 ;
if ( ! * V_47 ) {
* V_47 = F_18 ( sizeof ** V_47 , V_101 ) ;
if ( ! * V_47 ) {
F_63 ( & V_241 -> V_67 . V_3 -> V_53 ,
L_20 ) ;
V_41 = - V_66 ;
goto V_54;
}
V_22 = & ( * V_47 ) -> V_25 [ V_8 ] ;
if ( ( V_41 = F_99 ( V_22 ) ) )
goto V_71;
} else {
V_22 = & ( * V_47 ) -> V_25 [ V_8 ] ;
if ( ! * V_22 ) {
if ( ( V_41 = F_99 ( V_22 ) ) )
goto V_54;
}
}
if ( F_12 ( V_22 , V_20 ) )
goto V_72;
F_97 ( V_23 , V_20 -> V_242 , V_239 )
( * V_22 ) -> V_67 [ V_23 ] = V_241 ;
return 0 ;
V_72:
F_105 ( * V_22 , V_241 ) ;
if ( ! F_100 ( * V_22 ) ) {
F_31 ( * V_22 ) ;
* V_22 = NULL ;
}
V_41 = - V_42 ;
goto V_54;
V_71:
F_31 ( * V_47 ) ;
* V_47 = NULL ;
V_54:
return V_41 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_43 * V_241 )
{
struct V_1 * V_40 ;
struct V_48 * * V_243 ;
struct V_48 * V_49 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_21 * * V_22 ;
int V_23 , V_41 = - V_66 ;
T_1 V_52 ;
V_52 = F_8 ( V_20 -> V_8 ) ;
V_40 = V_241 -> V_62 -> V_40 ;
V_243 = & V_40 -> V_88 [
V_20 -> V_56 ] . V_49 ;
if ( ! * V_243 ) {
V_49 = F_18 ( sizeof *V_49 , V_101 ) ;
if ( ! V_49 ) {
F_63 ( & V_241 -> V_67 . V_3 -> V_53 ,
L_21 ) ;
goto V_54;
}
* V_243 = V_49 ;
}
if ( ! ( * V_243 ) -> V_18 [ V_52 ] ) {
V_18 = F_18 ( sizeof *V_18 , V_101 ) ;
if ( ! V_18 ) {
F_63 ( & V_241 -> V_67 . V_3 -> V_53 ,
L_22 ) ;
goto V_71;
}
( * V_243 ) -> V_18 [ V_52 ] = V_18 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( ( * V_243 ) -> V_18 [ V_52 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ) {
V_22 = & ( * V_243 ) -> V_18 [
V_52 ] -> V_25 [ V_23 ] ;
F_56 ( ! * V_22 ) ;
goto V_244;
}
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! F_10 ( ( * V_243 ) -> V_18 [
V_52 ] -> V_16 [ V_23 ] ) ) {
V_22 = & ( * V_243 ) -> V_18 [
V_52 ] -> V_25 [ V_23 ] ;
F_56 ( * V_22 ) ;
if ( ( V_41 = F_99 ( V_22 ) ) )
goto V_72;
memcpy ( ( * V_243 ) -> V_18 [ V_52 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ;
goto V_244;
}
}
F_63 ( & V_241 -> V_67 . V_3 -> V_53 , L_23 ) ;
goto V_72;
V_244:
if ( F_12 ( V_22 , V_20 ) )
goto V_89;
F_97 ( V_23 , V_20 -> V_242 , V_239 )
( * V_22 ) -> V_67 [ V_23 ] = V_241 ;
return 0 ;
V_89:
F_105 ( * V_22 , V_241 ) ;
if ( ! F_100 ( * V_22 ) ) {
F_31 ( * V_22 ) ;
* V_22 = NULL ;
}
V_41 = - V_42 ;
V_72:
if ( V_18 ) {
( * V_243 ) -> V_18 [ V_52 ] = NULL ;
F_31 ( V_18 ) ;
}
V_71:
if ( V_49 ) {
* V_243 = NULL ;
F_31 ( V_49 ) ;
}
V_54:
return V_41 ;
}
static void F_46 ( struct V_43 * V_241 )
{
struct V_1 * V_40 ;
struct V_46 * V_47 ;
struct V_21 * V_22 ;
struct V_48 * V_49 ;
struct V_17 * V_18 ;
int V_245 ;
T_1 V_8 ;
if ( ! V_241 -> V_45 ) {
goto V_102;
}
V_40 = V_241 -> V_62 -> V_40 ;
V_8 = F_6 ( V_241 -> V_45 -> V_8 ) ;
V_47 = V_40 -> V_88 [
V_241 -> V_45 -> V_56 ] . V_47 ;
if ( ! V_47 )
goto V_246;
V_22 = V_47 -> V_25 [ V_8 ] ;
if ( V_22 ) {
F_105 ( V_22 , V_241 ) ;
if ( ! F_100 ( V_22 ) ) {
F_31 ( V_22 ) ;
V_47 -> V_25 [ V_8 ] = NULL ;
if ( ! F_101 ( V_47 ) ) {
F_31 ( V_47 ) ;
V_40 -> V_88 [
V_241 -> V_45 ->
V_56 ] . V_47 = NULL ;
}
}
}
V_246:
if ( ! F_9 ( V_8 ) )
goto V_102;
V_8 = F_8 ( V_241 -> V_45 -> V_8 ) ;
V_49 = V_40 -> V_88 [
V_241 -> V_45 -> V_56 ] . V_49 ;
if ( ! V_49 )
goto V_102;
V_18 = V_49 -> V_18 [ V_8 ] ;
if ( V_18 ) {
V_245 = F_103 ( V_18 , V_241 -> V_45 -> V_16 ) ;
if ( V_245 < 0 )
goto V_102;
V_22 = V_18 -> V_25 [ V_245 ] ;
if ( V_22 ) {
F_105 ( V_22 , V_241 ) ;
if ( ! F_100 ( V_22 ) ) {
F_31 ( V_22 ) ;
V_18 -> V_25 [ V_245 ] = NULL ;
memset ( V_18 -> V_16 [ V_245 ] , 0 , 3 ) ;
if ( ! F_102 ( V_18 ) ) {
F_31 ( V_18 ) ;
V_49 -> V_18 [ V_8 ] = NULL ;
if ( ! F_104 ( V_49 ) ) {
F_31 ( V_49 ) ;
V_40 -> V_88 [
V_241 -> V_45 ->
V_56 ] .
V_49 = NULL ;
}
}
}
}
}
V_102:
return;
}
static struct V_43 *
F_70 ( struct V_1 * V_40 ,
struct V_26 * V_27 )
{
struct V_43 * V_107 = NULL ;
unsigned long V_6 ;
F_4 ( & V_40 -> V_85 , V_6 ) ;
if ( F_13 ( V_27 ) ) {
T_4 V_86 ;
struct V_43 * V_5 ;
V_86 = F_106 ( V_27 -> V_28 . V_223 ) >> 32 ;
F_2 (entry, &port_priv->agent_list, agent_list) {
if ( V_5 -> V_67 . V_86 == V_86 ) {
V_107 = V_5 ;
break;
}
}
} else {
struct V_46 * V_47 ;
struct V_21 * V_22 ;
struct V_48 * V_49 ;
struct V_17 * V_18 ;
struct V_247 * V_248 ;
int V_245 ;
if ( V_27 -> V_28 . V_249 >= V_57 )
goto V_102;
if ( ! F_9 ( V_27 -> V_28 . V_8 ) ) {
V_47 = V_40 -> V_88 [
V_27 -> V_28 . V_249 ] . V_47 ;
if ( ! V_47 )
goto V_102;
if ( F_6 ( V_27 -> V_28 . V_8 ) >=
V_239 )
goto V_102;
V_22 = V_47 -> V_25 [ F_6 (
V_27 -> V_28 . V_8 ) ] ;
if ( V_22 )
V_107 = V_22 -> V_67 [ V_27 -> V_28 . V_22 &
~ V_29 ] ;
} else {
V_49 = V_40 -> V_88 [
V_27 -> V_28 . V_249 ] . V_49 ;
if ( ! V_49 )
goto V_102;
V_18 = V_49 -> V_18 [ F_8 (
V_27 -> V_28 . V_8 ) ] ;
if ( ! V_18 )
goto V_102;
V_248 = (struct V_247 * ) V_27 ;
V_245 = F_103 ( V_18 , V_248 -> V_16 ) ;
if ( V_245 == - 1 )
goto V_102;
V_22 = V_18 -> V_25 [ V_245 ] ;
if ( V_22 ) {
V_107 = V_22 -> V_67 [ V_27 -> V_28 . V_22 &
~ V_29 ] ;
}
}
}
if ( V_107 ) {
if ( V_107 -> V_67 . V_37 )
F_37 ( & V_107 -> V_83 ) ;
else {
F_16 ( & V_40 -> V_3 -> V_53 ,
L_24 ,
& V_107 -> V_67 , V_40 -> V_4 ) ;
V_107 = NULL ;
}
}
V_102:
F_5 ( & V_40 -> V_85 , V_6 ) ;
return V_107 ;
}
static int F_107 ( struct V_26 * V_27 , T_4 V_250 )
{
int V_251 = 0 ;
if ( V_27 -> V_28 . V_252 != V_253 ) {
F_98 ( L_25 ,
V_27 -> V_28 . V_252 ) ;
goto V_102;
}
if ( ( V_27 -> V_28 . V_8 == V_59 ) ||
( V_27 -> V_28 . V_8 == V_9 ) ) {
if ( V_250 == 0 )
V_251 = 1 ;
} else {
if ( V_250 != 0 )
V_251 = 1 ;
}
V_102:
return V_251 ;
}
static int F_108 ( struct V_43 * V_44 ,
struct V_221 * V_28 )
{
struct V_170 * V_171 ;
V_171 = (struct V_170 * ) V_28 ;
return ! V_44 -> V_67 . V_35 ||
! F_77 ( & V_44 -> V_67 ) ||
! ( F_109 ( & V_171 -> V_177 ) &
V_180 ) ||
( V_171 -> V_177 . V_178 == V_179 ) ;
}
static inline int F_110 ( struct V_136 * V_150 ,
struct V_118 * V_254 )
{
return ( (struct V_26 * ) ( V_150 -> V_115 . V_27 ) ) -> V_28 . V_8 ==
V_254 -> V_236 . V_27 -> V_28 . V_8 ;
}
static inline int F_111 ( struct V_43 * V_44 ,
struct V_136 * V_150 ,
struct V_118 * V_254 )
{
struct V_255 V_256 ;
T_1 V_257 , V_258 ;
union V_259 V_260 ;
struct V_2 * V_3 = V_44 -> V_67 . V_3 ;
T_1 V_4 = V_44 -> V_67 . V_4 ;
T_1 V_261 ;
V_257 = F_13 ( (struct V_26 * ) V_150 -> V_115 . V_27 ) ;
V_258 = F_13 ( V_254 -> V_236 . V_27 ) ;
if ( V_257 == V_258 )
return 0 ;
if ( F_112 ( V_150 -> V_115 . V_222 , & V_256 ) )
return 0 ;
if ( ! ! ( V_256 . V_262 & V_263 ) !=
! ! ( V_254 -> V_125 -> V_264 & V_265 ) )
return 0 ;
if ( ! V_257 && V_258 ) {
if ( ! ( V_256 . V_262 & V_263 ) ) {
if ( F_113 ( V_3 , V_4 , & V_261 ) )
return 0 ;
return ( ! V_261 || ! ( ( V_256 . V_266 ^
V_254 -> V_125 -> V_135 ) &
( ( 1 << V_261 ) - 1 ) ) ) ;
} else {
if ( F_114 ( V_3 , V_4 ,
V_256 . V_267 . V_268 , & V_260 ) )
return 0 ;
return ! memcmp ( V_260 . V_269 , V_254 -> V_236 . V_267 -> V_270 . V_269 ,
16 ) ;
}
}
if ( ! ( V_256 . V_262 & V_263 ) )
return V_256 . V_271 == V_254 -> V_125 -> V_122 ;
else
return ! memcmp ( V_256 . V_267 . V_270 . V_269 , V_254 -> V_236 . V_267 -> V_260 . V_269 ,
16 ) ;
}
static inline int F_115 ( T_1 V_47 )
{
return ( V_47 == V_9 ) ;
}
struct V_136 *
F_116 ( struct V_43 * V_44 ,
struct V_118 * V_125 )
{
struct V_136 * V_150 ;
struct V_26 * V_27 ;
V_27 = (struct V_26 * ) V_125 -> V_236 . V_27 ;
F_2 (wr, &mad_agent_priv->wait_list, agent_list) {
if ( ( V_150 -> V_223 == V_27 -> V_28 . V_223 ) &&
F_110 ( V_150 , V_125 ) &&
( F_115 ( V_125 -> V_236 . V_27 -> V_28 . V_8 ) ||
F_111 ( V_44 , V_150 , V_125 ) ) )
return ( V_150 -> V_126 == V_127 ) ? V_150 : NULL ;
}
F_2 (wr, &mad_agent_priv->send_list, agent_list) {
if ( F_108 ( V_44 , V_150 -> V_115 . V_27 ) &&
V_150 -> V_223 == V_27 -> V_28 . V_223 &&
V_150 -> V_224 &&
F_110 ( V_150 , V_125 ) &&
( F_115 ( V_125 -> V_236 . V_27 -> V_28 . V_8 ) ||
F_111 ( V_44 , V_150 , V_125 ) ) )
return ( V_150 -> V_126 == V_127 ) ? V_150 : NULL ;
}
return NULL ;
}
void F_117 ( struct V_136 * V_137 )
{
V_137 -> V_224 = 0 ;
if ( V_137 -> V_83 == 1 )
F_118 ( & V_137 -> V_90 ,
& V_137 -> V_44 -> V_76 ) ;
}
static void F_119 ( struct V_43 * V_44 ,
struct V_118 * V_119 )
{
struct V_136 * V_137 ;
struct V_116 V_117 ;
unsigned long V_6 ;
F_23 ( & V_119 -> V_77 ) ;
F_120 ( & V_119 -> V_236 . V_112 , & V_119 -> V_77 ) ;
if ( F_77 ( & V_44 -> V_67 ) ) {
V_119 = F_121 ( V_44 ,
V_119 ) ;
if ( ! V_119 ) {
F_39 ( V_44 ) ;
return;
}
}
if ( F_13 ( V_119 -> V_236 . V_27 ) ) {
F_4 ( & V_44 -> V_73 , V_6 ) ;
V_137 = F_116 ( V_44 , V_119 ) ;
if ( ! V_137 ) {
F_5 ( & V_44 -> V_73 , V_6 ) ;
if ( ! F_77 ( & V_44 -> V_67 )
&& F_17 ( V_119 -> V_236 . V_27 -> V_28 . V_8 )
&& ( F_109 ( & ( (struct V_170 * ) V_119 -> V_236 . V_27 ) -> V_177 )
& V_180 ) ) {
V_119 -> V_125 -> V_121 = 0 ;
V_44 -> V_67 . V_37 ( & V_44 -> V_67 ,
V_119 ) ;
F_52 ( & V_44 -> V_83 ) ;
} else {
F_93 ( V_119 ) ;
F_39 ( V_44 ) ;
return;
}
} else {
F_117 ( V_137 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
V_119 -> V_125 -> V_121 = ( unsigned long ) & V_137 -> V_115 ;
V_44 -> V_67 . V_37 ( & V_44 -> V_67 ,
V_119 ) ;
F_52 ( & V_44 -> V_83 ) ;
V_117 . V_126 = V_127 ;
V_117 . V_272 = 0 ;
V_117 . V_115 = & V_137 -> V_115 ;
F_122 ( V_137 , & V_117 ) ;
}
} else {
V_44 -> V_67 . V_37 ( & V_44 -> V_67 ,
V_119 ) ;
F_39 ( V_44 ) ;
}
}
static bool F_123 ( struct V_142 * V_273 ,
struct V_142 * V_274 )
{
if ( V_273 -> V_27 . V_27 . V_28 . V_22 == V_275 ||
V_273 -> V_27 . V_27 . V_28 . V_22 == V_276 ) {
memcpy ( V_274 , V_273 , sizeof *V_274 ) ;
V_274 -> V_238 . V_237 . V_125 = & V_274 -> V_238 . V_125 ;
V_274 -> V_238 . V_237 . V_236 . V_27 = & V_274 -> V_27 . V_27 ;
V_274 -> V_238 . V_237 . V_236 . V_267 = & V_274 -> V_267 ;
V_274 -> V_27 . V_27 . V_28 . V_22 = V_277 ;
V_274 -> V_27 . V_27 . V_28 . V_126 =
F_124 ( V_278 ) ;
if ( V_273 -> V_27 . V_27 . V_28 . V_8 == V_9 )
V_274 -> V_27 . V_27 . V_28 . V_126 |= V_279 ;
return true ;
} else {
return false ;
}
}
static void F_125 ( struct V_1 * V_40 ,
struct V_124 * V_125 )
{
struct V_94 * V_62 ;
struct V_232 * V_233 ;
struct V_142 * V_273 , * V_274 = NULL ;
struct V_108 * V_109 ;
struct V_43 * V_107 ;
int V_4 ;
int V_41 = V_158 ;
V_109 = (struct V_108 * ) ( unsigned long ) V_125 -> V_121 ;
V_62 = V_109 -> V_111 -> V_62 ;
F_55 ( V_109 ) ;
V_233 = F_54 ( V_109 , struct V_232 ,
V_109 ) ;
V_273 = F_54 ( V_233 , struct V_142 , V_238 ) ;
F_88 ( V_40 -> V_3 ,
V_273 -> V_238 . V_280 ,
sizeof( struct V_142 ) -
sizeof( struct V_232 ) ,
V_281 ) ;
V_273 -> V_238 . V_125 = * V_125 ;
V_273 -> V_238 . V_237 . V_125 = & V_273 -> V_238 . V_125 ;
V_273 -> V_238 . V_237 . V_282 = sizeof( struct V_26 ) ;
V_273 -> V_238 . V_237 . V_236 . V_27 = & V_273 -> V_27 . V_27 ;
V_273 -> V_238 . V_237 . V_236 . V_267 = & V_273 -> V_267 ;
if ( F_126 ( & V_62 -> V_103 ) )
F_58 ( V_62 , & V_273 -> V_238 . V_237 , V_93 ) ;
if ( ! F_107 ( & V_273 -> V_27 . V_27 , V_62 -> V_63 -> V_250 ) )
goto V_102;
V_274 = F_67 ( V_156 , V_65 ) ;
if ( ! V_274 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_26 ) ;
goto V_102;
}
if ( V_40 -> V_3 -> V_148 == V_149 )
V_4 = V_125 -> V_4 ;
else
V_4 = V_40 -> V_4 ;
if ( V_273 -> V_27 . V_27 . V_28 . V_8 ==
V_9 ) {
enum V_283 V_284 ;
if ( F_127 ( & V_273 -> V_27 . V_139 ,
V_40 -> V_3 -> V_148 ,
V_4 ,
V_40 -> V_3 -> V_285 ) ==
V_155 )
goto V_102;
V_284 = F_128 ( & V_273 -> V_27 . V_139 ) ;
if ( V_284 == V_286 )
goto V_141;
if ( V_284 == V_287 ) {
if ( F_62 ( & V_273 -> V_27 . V_139 ,
V_40 -> V_3 -> V_148 ,
V_4 ) == V_155 )
goto V_102;
if ( F_64 ( & V_273 -> V_27 . V_139 , V_40 -> V_3 ) == V_155 )
goto V_102;
} else if ( V_40 -> V_3 -> V_148 == V_149 ) {
memcpy ( V_274 , V_273 , sizeof( * V_274 ) ) ;
V_274 -> V_238 . V_237 . V_125 = & V_274 -> V_238 . V_125 ;
V_274 -> V_238 . V_237 . V_236 . V_27 = & V_274 -> V_27 . V_27 ;
V_274 -> V_238 . V_237 . V_236 . V_267 = & V_274 -> V_267 ;
F_129 ( & V_274 -> V_27 . V_27 ,
& V_274 -> V_267 , V_125 ,
V_40 -> V_3 ,
F_130 ( & V_273 -> V_27 . V_139 ) ,
V_62 -> V_63 -> V_250 ) ;
goto V_102;
}
}
V_141:
if ( V_40 -> V_3 -> V_157 ) {
V_41 = V_40 -> V_3 -> V_157 ( V_40 -> V_3 , 0 ,
V_40 -> V_4 ,
V_125 , & V_273 -> V_267 ,
& V_273 -> V_27 . V_27 ,
& V_274 -> V_27 . V_27 ) ;
if ( V_41 & V_158 ) {
if ( V_41 & V_160 )
goto V_102;
if ( V_41 & V_159 ) {
F_129 ( & V_274 -> V_27 . V_27 ,
& V_273 -> V_267 , V_125 ,
V_40 -> V_3 ,
V_4 ,
V_62 -> V_63 -> V_250 ) ;
goto V_102;
}
}
}
V_107 = F_70 ( V_40 , & V_273 -> V_27 . V_27 ) ;
if ( V_107 ) {
F_119 ( V_107 , & V_273 -> V_238 . V_237 ) ;
V_273 = NULL ;
} else if ( ( V_41 & V_158 ) &&
F_123 ( V_273 , V_274 ) ) {
F_129 ( & V_274 -> V_27 . V_27 , & V_273 -> V_267 , V_125 ,
V_40 -> V_3 , V_4 , V_62 -> V_63 -> V_250 ) ;
}
V_102:
if ( V_274 ) {
F_131 ( V_62 , V_274 ) ;
if ( V_273 )
F_69 ( V_156 , V_273 ) ;
} else
F_131 ( V_62 , V_273 ) ;
}
static void F_132 ( struct V_43 * V_44 )
{
struct V_136 * V_137 ;
unsigned long V_288 ;
if ( F_133 ( & V_44 -> V_75 ) ) {
F_45 ( & V_44 -> V_78 ) ;
} else {
V_137 = F_134 ( V_44 -> V_75 . V_182 ,
struct V_136 ,
V_90 ) ;
if ( F_135 ( V_44 -> V_224 ,
V_137 -> V_224 ) ) {
V_44 -> V_224 = V_137 -> V_224 ;
V_288 = V_137 -> V_224 - V_289 ;
if ( ( long ) V_288 <= 0 )
V_288 = 1 ;
F_136 ( V_44 -> V_62 -> V_40 -> V_106 ,
& V_44 -> V_78 , V_288 ) ;
}
}
}
static void F_137 ( struct V_136 * V_137 )
{
struct V_43 * V_44 ;
struct V_136 * V_290 ;
struct V_207 * V_291 ;
unsigned long V_288 ;
V_44 = V_137 -> V_44 ;
F_47 ( & V_137 -> V_90 ) ;
V_288 = V_137 -> V_224 ;
V_137 -> V_224 += V_289 ;
if ( V_288 ) {
F_138 (list_item, &mad_agent_priv->wait_list) {
V_290 = F_134 ( V_291 ,
struct V_136 ,
V_90 ) ;
if ( F_135 ( V_137 -> V_224 ,
V_290 -> V_224 ) )
break;
}
}
else
V_291 = & V_44 -> V_75 ;
F_120 ( & V_137 -> V_90 , V_291 ) ;
if ( V_44 -> V_75 . V_182 == & V_137 -> V_90 )
F_136 ( V_44 -> V_62 -> V_40 -> V_106 ,
& V_44 -> V_78 , V_288 ) ;
}
void F_139 ( struct V_136 * V_137 ,
int V_220 )
{
V_137 -> V_224 = F_91 ( V_220 ) ;
F_137 ( V_137 ) ;
}
void F_122 ( struct V_136 * V_137 ,
struct V_116 * V_117 )
{
struct V_43 * V_44 ;
unsigned long V_6 ;
int V_41 ;
V_44 = V_137 -> V_44 ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
if ( F_77 ( & V_44 -> V_67 ) ) {
V_41 = F_140 ( V_137 , V_117 ) ;
if ( V_41 == V_228 )
goto V_292;
} else
V_41 = V_293 ;
if ( V_117 -> V_126 != V_127 &&
V_137 -> V_126 == V_127 ) {
V_137 -> V_126 = V_117 -> V_126 ;
V_137 -> V_83 -= ( V_137 -> V_224 > 0 ) ;
}
if ( -- V_137 -> V_83 > 0 ) {
if ( V_137 -> V_83 == 1 && V_137 -> V_224 &&
V_137 -> V_126 == V_127 ) {
F_137 ( V_137 ) ;
}
goto V_292;
}
F_47 ( & V_137 -> V_90 ) ;
F_132 ( V_44 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
if ( V_137 -> V_126 != V_127 )
V_117 -> V_126 = V_137 -> V_126 ;
if ( V_41 == V_294 )
F_141 ( V_117 ) ;
else
V_44 -> V_67 . V_36 ( & V_44 -> V_67 ,
V_117 ) ;
F_39 ( V_44 ) ;
return;
V_292:
F_5 ( & V_44 -> V_73 , V_6 ) ;
}
static void F_142 ( struct V_1 * V_40 ,
struct V_124 * V_125 )
{
struct V_136 * V_137 , * V_295 ;
struct V_108 * V_109 ;
struct V_94 * V_62 ;
struct V_110 * V_211 ;
struct V_146 * V_208 ;
struct V_116 V_117 ;
unsigned long V_6 ;
int V_41 ;
V_109 = (struct V_108 * ) ( unsigned long ) V_125 -> V_121 ;
V_137 = F_54 ( V_109 , struct V_136 ,
V_109 ) ;
V_211 = V_109 -> V_111 ;
V_62 = V_211 -> V_62 ;
V_296:
F_88 ( V_137 -> V_115 . V_107 -> V_3 ,
V_137 -> V_214 ,
V_137 -> V_189 [ 0 ] . V_190 , V_213 ) ;
F_88 ( V_137 -> V_115 . V_107 -> V_3 ,
V_137 -> V_215 ,
V_137 -> V_189 [ 1 ] . V_190 , V_213 ) ;
V_295 = NULL ;
F_4 ( & V_211 -> V_73 , V_6 ) ;
F_47 ( & V_109 -> V_112 ) ;
if ( V_211 -> V_113 -- > V_211 -> V_216 ) {
V_109 = F_54 ( V_62 -> V_217 . V_182 ,
struct V_108 , V_112 ) ;
V_295 = F_54 ( V_109 ,
struct V_136 ,
V_109 ) ;
F_118 ( & V_109 -> V_112 , & V_211 -> V_112 ) ;
}
F_5 ( & V_211 -> V_73 , V_6 ) ;
V_117 . V_115 = & V_137 -> V_115 ;
V_117 . V_126 = V_125 -> V_126 ;
V_117 . V_272 = V_125 -> V_272 ;
if ( F_126 ( & V_62 -> V_103 ) )
F_57 ( V_62 , & V_137 -> V_115 , & V_117 ,
V_92 ) ;
F_122 ( V_137 , & V_117 ) ;
if ( V_295 ) {
V_41 = F_89 ( V_62 -> V_63 , & V_295 -> V_147 ,
& V_208 ) ;
if ( V_41 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_27 , V_41 ) ;
V_137 = V_295 ;
V_125 -> V_126 = V_297 ;
goto V_296;
}
}
}
static void F_143 ( struct V_94 * V_62 )
{
struct V_136 * V_137 ;
struct V_108 * V_109 ;
unsigned long V_6 ;
F_4 ( & V_62 -> V_211 . V_73 , V_6 ) ;
F_2 (mad_list, &qp_info->send_queue.list, list) {
V_137 = F_54 ( V_109 ,
struct V_136 ,
V_109 ) ;
V_137 -> V_296 = 1 ;
}
F_5 ( & V_62 -> V_211 . V_73 , V_6 ) ;
}
static void F_144 ( struct V_1 * V_40 ,
struct V_124 * V_125 )
{
struct V_108 * V_109 ;
struct V_94 * V_62 ;
struct V_136 * V_137 ;
int V_41 ;
V_109 = (struct V_108 * ) ( unsigned long ) V_125 -> V_121 ;
V_62 = V_109 -> V_111 -> V_62 ;
if ( V_109 -> V_111 == & V_62 -> V_298 )
return;
V_137 = F_54 ( V_109 , struct V_136 ,
V_109 ) ;
if ( V_125 -> V_126 == V_299 ) {
if ( V_137 -> V_296 ) {
struct V_146 * V_208 ;
V_137 -> V_296 = 0 ;
V_41 = F_89 ( V_62 -> V_63 , & V_137 -> V_147 ,
& V_208 ) ;
if ( V_41 )
F_142 ( V_40 , V_125 ) ;
} else
F_142 ( V_40 , V_125 ) ;
} else {
struct V_300 * V_256 ;
V_256 = F_66 ( sizeof *V_256 , V_65 ) ;
if ( V_256 ) {
V_256 -> V_301 = V_302 ;
V_256 -> V_303 = V_304 ;
V_41 = F_145 ( V_62 -> V_63 , V_256 ,
V_305 | V_306 ) ;
F_31 ( V_256 ) ;
if ( V_41 )
F_63 ( & V_40 -> V_3 -> V_53 ,
L_28 ,
V_41 ) ;
else
F_143 ( V_62 ) ;
}
F_142 ( V_40 , V_125 ) ;
}
}
static void F_146 ( struct V_307 * V_308 )
{
struct V_1 * V_40 ;
struct V_124 V_125 ;
V_40 = F_54 ( V_308 , struct V_1 , V_308 ) ;
F_147 ( V_40 -> V_309 , V_310 ) ;
while ( F_148 ( V_40 -> V_309 , 1 , & V_125 ) == 1 ) {
if ( V_125 . V_126 == V_127 ) {
switch ( V_125 . V_128 ) {
case V_311 :
F_142 ( V_40 , & V_125 ) ;
break;
case V_129 :
F_125 ( V_40 , & V_125 ) ;
break;
default:
F_56 ( 1 ) ;
break;
}
} else
F_144 ( V_40 , & V_125 ) ;
}
}
static void F_44 ( struct V_43 * V_44 )
{
unsigned long V_6 ;
struct V_136 * V_137 , * V_290 ;
struct V_116 V_117 ;
struct V_207 V_312 ;
F_23 ( & V_312 ) ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
F_74 (mad_send_wr, temp_mad_send_wr,
&mad_agent_priv->send_list, agent_list) {
if ( V_137 -> V_126 == V_127 ) {
V_137 -> V_126 = V_299 ;
V_137 -> V_83 -= ( V_137 -> V_224 > 0 ) ;
}
}
F_94 ( & V_44 -> V_75 , & V_312 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
V_117 . V_126 = V_299 ;
V_117 . V_272 = 0 ;
F_74 (mad_send_wr, temp_mad_send_wr,
&cancel_list, agent_list) {
V_117 . V_115 = & V_137 -> V_115 ;
F_47 ( & V_137 -> V_90 ) ;
V_44 -> V_67 . V_36 ( & V_44 -> V_67 ,
& V_117 ) ;
F_52 ( & V_44 -> V_83 ) ;
}
}
static struct V_136 *
F_149 ( struct V_43 * V_44 ,
struct V_114 * V_115 )
{
struct V_136 * V_137 ;
F_2 (mad_send_wr, &mad_agent_priv->wait_list,
agent_list) {
if ( & V_137 -> V_115 == V_115 )
return V_137 ;
}
F_2 (mad_send_wr, &mad_agent_priv->send_list,
agent_list) {
if ( F_108 ( V_44 , V_137 -> V_115 . V_27 ) &&
& V_137 -> V_115 == V_115 )
return V_137 ;
}
return NULL ;
}
int F_150 ( struct V_34 * V_107 ,
struct V_114 * V_115 , T_4 V_220 )
{
struct V_43 * V_44 ;
struct V_136 * V_137 ;
unsigned long V_6 ;
int V_313 ;
V_44 = F_54 ( V_107 , struct V_43 ,
V_67 ) ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
V_137 = F_149 ( V_44 , V_115 ) ;
if ( ! V_137 || V_137 -> V_126 != V_127 ) {
F_5 ( & V_44 -> V_73 , V_6 ) ;
return - V_42 ;
}
V_313 = ( ! V_137 -> V_224 || V_137 -> V_83 > 1 ) ;
if ( ! V_220 ) {
V_137 -> V_126 = V_299 ;
V_137 -> V_83 -= ( V_137 -> V_224 > 0 ) ;
}
V_137 -> V_115 . V_220 = V_220 ;
if ( V_313 )
V_137 -> V_224 = F_91 ( V_220 ) ;
else
F_139 ( V_137 , V_220 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
return 0 ;
}
void F_151 ( struct V_34 * V_107 ,
struct V_114 * V_115 )
{
F_150 ( V_107 , V_115 , 0 ) ;
}
static void V_82 ( struct V_307 * V_308 )
{
struct V_43 * V_44 ;
struct V_140 * V_141 ;
struct V_43 * V_144 ;
unsigned long V_6 ;
int V_314 ;
struct V_124 V_125 ;
struct V_116 V_117 ;
V_44 =
F_54 ( V_308 , struct V_43 , V_81 ) ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
while ( ! F_133 ( & V_44 -> V_80 ) ) {
V_141 = F_134 ( V_44 -> V_80 . V_182 ,
struct V_140 ,
V_161 ) ;
F_47 ( & V_141 -> V_161 ) ;
F_5 ( & V_44 -> V_73 , V_6 ) ;
V_314 = 0 ;
if ( V_141 -> V_143 ) {
V_144 = V_141 -> V_144 ;
if ( ! V_144 ) {
F_63 ( & V_44 -> V_67 . V_3 -> V_53 ,
L_29 ) ;
V_314 = 1 ;
goto V_315;
}
F_59 ( V_144 -> V_67 . V_63 ,
( unsigned long ) V_141 -> V_137 ,
F_68 ( V_154 ) ,
0 , V_144 -> V_67 . V_4 , & V_125 ) ;
V_141 -> V_143 -> V_238 . V_237 . V_125 = & V_125 ;
V_141 -> V_143 -> V_238 . V_237 . V_282 =
sizeof( struct V_26 ) ;
F_23 ( & V_141 -> V_143 -> V_238 . V_237 . V_77 ) ;
F_120 ( & V_141 -> V_143 -> V_238 . V_237 . V_236 . V_112 ,
& V_141 -> V_143 -> V_238 . V_237 . V_77 ) ;
V_141 -> V_143 -> V_238 . V_237 . V_236 . V_267 = NULL ;
V_141 -> V_143 -> V_238 . V_237 . V_236 . V_27 =
& V_141 -> V_143 -> V_27 . V_27 ;
if ( F_126 ( & V_144 -> V_62 -> V_103 ) )
F_58 ( V_144 -> V_62 ,
& V_141 -> V_143 -> V_238 . V_237 ,
V_93 ) ;
V_144 -> V_67 . V_37 (
& V_144 -> V_67 ,
& V_141 -> V_143 -> V_238 . V_237 ) ;
F_4 ( & V_144 -> V_73 , V_6 ) ;
F_52 ( & V_144 -> V_83 ) ;
F_5 ( & V_144 -> V_73 , V_6 ) ;
}
V_315:
V_117 . V_126 = V_127 ;
V_117 . V_272 = 0 ;
V_117 . V_115 = & V_141 -> V_137 -> V_115 ;
if ( F_126 ( & V_44 -> V_62 -> V_103 ) )
F_57 ( V_44 -> V_62 ,
& V_141 -> V_137 -> V_115 ,
& V_117 , V_92 ) ;
V_44 -> V_67 . V_36 ( & V_44 -> V_67 ,
& V_117 ) ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
F_52 ( & V_44 -> V_83 ) ;
if ( V_314 )
F_69 ( V_156 , V_141 -> V_143 ) ;
F_31 ( V_141 ) ;
}
F_5 ( & V_44 -> V_73 , V_6 ) ;
}
static int F_152 ( struct V_136 * V_137 )
{
int V_41 ;
if ( ! V_137 -> V_227 )
return - V_316 ;
V_137 -> V_227 -- ;
V_137 -> V_115 . V_226 ++ ;
V_137 -> V_224 = F_91 ( V_137 -> V_115 . V_220 ) ;
if ( F_77 ( & V_137 -> V_44 -> V_67 ) ) {
V_41 = F_153 ( V_137 ) ;
switch ( V_41 ) {
case V_293 :
V_41 = F_84 ( V_137 ) ;
break;
case V_228 :
V_41 = 0 ;
break;
default:
V_41 = - V_317 ;
break;
}
} else
V_41 = F_84 ( V_137 ) ;
if ( ! V_41 ) {
V_137 -> V_83 ++ ;
F_30 ( & V_137 -> V_90 ,
& V_137 -> V_44 -> V_74 ) ;
}
return V_41 ;
}
static void V_79 ( struct V_307 * V_308 )
{
struct V_43 * V_44 ;
struct V_136 * V_137 ;
struct V_116 V_117 ;
unsigned long V_6 , V_288 ;
V_44 = F_54 ( V_308 , struct V_43 ,
V_78 . V_308 ) ;
V_117 . V_272 = 0 ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
while ( ! F_133 ( & V_44 -> V_75 ) ) {
V_137 = F_134 ( V_44 -> V_75 . V_182 ,
struct V_136 ,
V_90 ) ;
if ( F_135 ( V_137 -> V_224 , V_289 ) ) {
V_288 = V_137 -> V_224 - V_289 ;
if ( ( long ) V_288 <= 0 )
V_288 = 1 ;
F_154 ( V_44 -> V_62 ->
V_40 -> V_106 ,
& V_44 -> V_78 , V_288 ) ;
break;
}
F_47 ( & V_137 -> V_90 ) ;
if ( V_137 -> V_126 == V_127 &&
! F_152 ( V_137 ) )
continue;
F_5 ( & V_44 -> V_73 , V_6 ) ;
if ( V_137 -> V_126 == V_127 )
V_117 . V_126 = V_318 ;
else
V_117 . V_126 = V_137 -> V_126 ;
V_117 . V_115 = & V_137 -> V_115 ;
V_44 -> V_67 . V_36 ( & V_44 -> V_67 ,
& V_117 ) ;
F_52 ( & V_44 -> V_83 ) ;
F_4 ( & V_44 -> V_73 , V_6 ) ;
}
F_5 ( & V_44 -> V_73 , V_6 ) ;
}
static void F_155 ( struct V_319 * V_309 , void * V_320 )
{
struct V_1 * V_40 = V_309 -> V_321 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
if ( ! F_133 ( & V_40 -> V_322 ) )
F_71 ( V_40 -> V_106 , & V_40 -> V_308 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static int F_131 ( struct V_94 * V_62 ,
struct V_142 * V_27 )
{
unsigned long V_6 ;
int V_323 , V_41 ;
struct V_142 * V_143 ;
struct V_209 V_189 ;
struct V_324 V_325 , * V_326 ;
struct V_110 * V_298 = & V_62 -> V_298 ;
V_189 . V_190 = sizeof *V_143 - sizeof V_143 -> V_238 ;
V_189 . V_191 = ( * V_62 -> V_40 -> V_68 ) . V_191 ;
V_325 . V_182 = NULL ;
V_325 . V_189 = & V_189 ;
V_325 . V_192 = 1 ;
do {
if ( V_27 ) {
V_143 = V_27 ;
V_27 = NULL ;
} else {
V_143 = F_67 ( V_156 , V_65 ) ;
if ( ! V_143 ) {
F_63 ( & V_62 -> V_40 -> V_3 -> V_53 ,
L_30 ) ;
V_41 = - V_66 ;
break;
}
}
V_189 . V_212 = F_85 ( V_62 -> V_40 -> V_3 ,
& V_143 -> V_267 ,
sizeof *V_143 -
sizeof V_143 -> V_238 ,
V_281 ) ;
if ( F_86 ( F_87 ( V_62 -> V_40 -> V_3 ,
V_189 . V_212 ) ) ) {
V_41 = - V_66 ;
break;
}
V_143 -> V_238 . V_280 = V_189 . V_212 ;
V_325 . V_121 = ( unsigned long ) & V_143 -> V_238 . V_109 ;
V_143 -> V_238 . V_109 . V_111 = V_298 ;
F_4 ( & V_298 -> V_73 , V_6 ) ;
V_323 = ( ++ V_298 -> V_113 < V_298 -> V_216 ) ;
F_30 ( & V_143 -> V_238 . V_109 . V_112 , & V_298 -> V_112 ) ;
F_5 ( & V_298 -> V_73 , V_6 ) ;
V_41 = F_156 ( V_62 -> V_63 , & V_325 , & V_326 ) ;
if ( V_41 ) {
F_4 ( & V_298 -> V_73 , V_6 ) ;
F_47 ( & V_143 -> V_238 . V_109 . V_112 ) ;
V_298 -> V_113 -- ;
F_5 ( & V_298 -> V_73 , V_6 ) ;
F_88 ( V_62 -> V_40 -> V_3 ,
V_143 -> V_238 . V_280 ,
sizeof *V_143 -
sizeof V_143 -> V_238 ,
V_281 ) ;
F_69 ( V_156 , V_143 ) ;
F_63 ( & V_62 -> V_40 -> V_3 -> V_53 ,
L_31 , V_41 ) ;
break;
}
} while ( V_323 );
return V_41 ;
}
static void F_157 ( struct V_94 * V_62 )
{
struct V_232 * V_233 ;
struct V_142 * V_273 ;
struct V_108 * V_109 ;
if ( ! V_62 -> V_63 )
return;
while ( ! F_133 ( & V_62 -> V_298 . V_112 ) ) {
V_109 = F_134 ( V_62 -> V_298 . V_112 . V_182 ,
struct V_108 , V_112 ) ;
V_233 = F_54 ( V_109 ,
struct V_232 ,
V_109 ) ;
V_273 = F_54 ( V_233 , struct V_142 ,
V_238 ) ;
F_47 ( & V_109 -> V_112 ) ;
F_88 ( V_62 -> V_40 -> V_3 ,
V_273 -> V_238 . V_280 ,
sizeof( struct V_142 ) -
sizeof( struct V_232 ) ,
V_281 ) ;
F_69 ( V_156 , V_273 ) ;
}
V_62 -> V_298 . V_113 = 0 ;
}
static int F_158 ( struct V_1 * V_40 )
{
int V_41 , V_23 ;
struct V_300 * V_256 ;
struct V_120 * V_63 ;
T_7 V_123 ;
V_256 = F_66 ( sizeof *V_256 , V_65 ) ;
if ( ! V_256 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_32 ) ;
return - V_66 ;
}
V_41 = F_159 ( V_40 -> V_3 , V_40 -> V_4 ,
V_327 , & V_123 ) ;
if ( V_41 )
V_123 = 0 ;
for ( V_23 = 0 ; V_23 < V_328 ; V_23 ++ ) {
V_63 = V_40 -> V_62 [ V_23 ] . V_63 ;
if ( ! V_63 )
continue;
V_256 -> V_301 = V_329 ;
V_256 -> V_123 = V_123 ;
V_256 -> V_330 = ( V_63 -> V_250 == 0 ) ? 0 : V_331 ;
V_41 = F_145 ( V_63 , V_256 , V_305 |
V_332 | V_333 ) ;
if ( V_41 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_33 ,
V_23 , V_41 ) ;
goto V_102;
}
V_256 -> V_301 = V_334 ;
V_41 = F_145 ( V_63 , V_256 , V_305 ) ;
if ( V_41 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_34 ,
V_23 , V_41 ) ;
goto V_102;
}
V_256 -> V_301 = V_302 ;
V_256 -> V_335 = V_336 ;
V_41 = F_145 ( V_63 , V_256 , V_305 | V_337 ) ;
if ( V_41 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_35 ,
V_23 , V_41 ) ;
goto V_102;
}
}
V_41 = F_147 ( V_40 -> V_309 , V_310 ) ;
if ( V_41 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_36 ,
V_41 ) ;
goto V_102;
}
for ( V_23 = 0 ; V_23 < V_328 ; V_23 ++ ) {
if ( ! V_40 -> V_62 [ V_23 ] . V_63 )
continue;
V_41 = F_131 ( & V_40 -> V_62 [ V_23 ] , NULL ) ;
if ( V_41 ) {
F_63 ( & V_40 -> V_3 -> V_53 ,
L_37 ) ;
goto V_102;
}
}
V_102:
F_31 ( V_256 ) ;
return V_41 ;
}
static void F_160 ( struct V_338 * V_339 , void * V_340 )
{
struct V_94 * V_62 = V_340 ;
F_63 ( & V_62 -> V_40 -> V_3 -> V_53 ,
L_38 ,
V_339 -> V_339 , V_62 -> V_63 -> V_250 ) ;
}
static void F_161 ( struct V_94 * V_62 ,
struct V_110 * V_111 )
{
V_111 -> V_62 = V_62 ;
V_111 -> V_113 = 0 ;
F_22 ( & V_111 -> V_73 ) ;
F_23 ( & V_111 -> V_112 ) ;
}
static void F_162 ( struct V_1 * V_40 ,
struct V_94 * V_62 )
{
V_62 -> V_40 = V_40 ;
F_161 ( V_62 , & V_62 -> V_211 ) ;
F_161 ( V_62 , & V_62 -> V_298 ) ;
F_23 ( & V_62 -> V_217 ) ;
F_22 ( & V_62 -> V_98 ) ;
V_62 -> V_100 = NULL ;
V_62 -> V_99 = 0 ;
F_26 ( & V_62 -> V_103 , 0 ) ;
}
static int F_163 ( struct V_94 * V_62 ,
enum V_10 V_11 )
{
struct V_341 V_342 ;
int V_41 ;
memset ( & V_342 , 0 , sizeof V_342 ) ;
V_342 . V_343 = V_62 -> V_40 -> V_309 ;
V_342 . V_344 = V_62 -> V_40 -> V_309 ;
V_342 . V_345 = V_346 ;
V_342 . V_347 . V_348 = V_349 ;
V_342 . V_347 . V_350 = V_351 ;
V_342 . V_347 . V_352 = V_353 ;
V_342 . V_347 . V_354 = V_355 ;
V_342 . V_11 = V_11 ;
V_342 . V_4 = V_62 -> V_40 -> V_4 ;
V_342 . V_340 = V_62 ;
V_342 . V_356 = F_160 ;
V_62 -> V_63 = F_164 ( V_62 -> V_40 -> V_69 , & V_342 ) ;
if ( F_20 ( V_62 -> V_63 ) ) {
F_63 ( & V_62 -> V_40 -> V_3 -> V_53 ,
L_39 ,
F_7 ( V_11 ) ) ;
V_41 = F_165 ( V_62 -> V_63 ) ;
goto error;
}
V_62 -> V_211 . V_216 = V_349 ;
V_62 -> V_298 . V_216 = V_351 ;
return 0 ;
error:
return V_41 ;
}
static void F_166 ( struct V_94 * V_62 )
{
if ( ! V_62 -> V_63 )
return;
F_167 ( V_62 -> V_63 ) ;
F_31 ( V_62 -> V_100 ) ;
}
static int F_168 ( struct V_2 * V_3 ,
int V_4 )
{
int V_41 , V_357 ;
struct V_1 * V_40 ;
unsigned long V_6 ;
char V_358 [ sizeof "ib_mad123"];
int V_359 ;
V_40 = F_18 ( sizeof *V_40 , V_65 ) ;
if ( ! V_40 ) {
F_63 ( & V_3 -> V_53 , L_40 ) ;
return - V_66 ;
}
V_40 -> V_3 = V_3 ;
V_40 -> V_4 = V_4 ;
F_22 ( & V_40 -> V_85 ) ;
F_23 ( & V_40 -> V_90 ) ;
F_162 ( V_40 , & V_40 -> V_62 [ 0 ] ) ;
F_162 ( V_40 , & V_40 -> V_62 [ 1 ] ) ;
V_357 = V_349 + V_351 ;
V_359 = F_169 ( V_3 , V_4 ) == V_360 ;
if ( V_359 )
V_357 *= 2 ;
V_40 -> V_309 = F_170 ( V_40 -> V_3 ,
F_155 ,
NULL , V_40 , V_357 , 0 ) ;
if ( F_20 ( V_40 -> V_309 ) ) {
F_63 ( & V_3 -> V_53 , L_41 ) ;
V_41 = F_165 ( V_40 -> V_309 ) ;
goto V_72;
}
V_40 -> V_69 = F_171 ( V_3 ) ;
if ( F_20 ( V_40 -> V_69 ) ) {
F_63 ( & V_3 -> V_53 , L_42 ) ;
V_41 = F_165 ( V_40 -> V_69 ) ;
goto V_89;
}
V_40 -> V_68 = F_19 ( V_40 -> V_69 , V_70 ) ;
if ( F_20 ( V_40 -> V_68 ) ) {
F_63 ( & V_3 -> V_53 , L_43 ) ;
V_41 = F_165 ( V_40 -> V_68 ) ;
goto V_361;
}
if ( V_359 ) {
V_41 = F_163 ( & V_40 -> V_62 [ 0 ] , V_12 ) ;
if ( V_41 )
goto V_362;
}
V_41 = F_163 ( & V_40 -> V_62 [ 1 ] , V_13 ) ;
if ( V_41 )
goto V_363;
snprintf ( V_358 , sizeof V_358 , L_44 , V_4 ) ;
V_40 -> V_106 = F_172 ( V_358 ) ;
if ( ! V_40 -> V_106 ) {
V_41 = - V_66 ;
goto V_364;
}
F_25 ( & V_40 -> V_308 , F_146 ) ;
F_4 ( & V_7 , V_6 ) ;
F_30 ( & V_40 -> V_322 , & V_365 ) ;
F_5 ( & V_7 , V_6 ) ;
V_41 = F_158 ( V_40 ) ;
if ( V_41 ) {
F_63 ( & V_3 -> V_53 , L_45 ) ;
goto V_366;
}
return 0 ;
V_366:
F_4 ( & V_7 , V_6 ) ;
F_173 ( & V_40 -> V_322 ) ;
F_5 ( & V_7 , V_6 ) ;
F_174 ( V_40 -> V_106 ) ;
V_364:
F_166 ( & V_40 -> V_62 [ 1 ] ) ;
V_363:
F_166 ( & V_40 -> V_62 [ 0 ] ) ;
V_362:
F_32 ( V_40 -> V_68 ) ;
V_361:
F_175 ( V_40 -> V_69 ) ;
V_89:
F_176 ( V_40 -> V_309 ) ;
F_157 ( & V_40 -> V_62 [ 1 ] ) ;
F_157 ( & V_40 -> V_62 [ 0 ] ) ;
V_72:
F_31 ( V_40 ) ;
return V_41 ;
}
static int F_177 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_40 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
V_40 = F_1 ( V_3 , V_4 ) ;
if ( V_40 == NULL ) {
F_5 ( & V_7 , V_6 ) ;
F_63 ( & V_3 -> V_53 , L_46 , V_4 ) ;
return - V_61 ;
}
F_173 ( & V_40 -> V_322 ) ;
F_5 ( & V_7 , V_6 ) ;
F_174 ( V_40 -> V_106 ) ;
F_166 ( & V_40 -> V_62 [ 1 ] ) ;
F_166 ( & V_40 -> V_62 [ 0 ] ) ;
F_32 ( V_40 -> V_68 ) ;
F_175 ( V_40 -> V_69 ) ;
F_176 ( V_40 -> V_309 ) ;
F_157 ( & V_40 -> V_62 [ 1 ] ) ;
F_157 ( & V_40 -> V_62 [ 0 ] ) ;
F_31 ( V_40 ) ;
return 0 ;
}
static void F_178 ( struct V_2 * V_3 )
{
int V_367 , V_368 , V_23 ;
if ( F_179 ( V_3 -> V_148 ) != V_369 )
return;
if ( V_3 -> V_148 == V_149 ) {
V_367 = 0 ;
V_368 = 0 ;
} else {
V_367 = 1 ;
V_368 = V_3 -> V_285 ;
}
for ( V_23 = V_367 ; V_23 <= V_368 ; V_23 ++ ) {
if ( F_168 ( V_3 , V_23 ) ) {
F_63 ( & V_3 -> V_53 , L_47 , V_23 ) ;
goto error;
}
if ( F_180 ( V_3 , V_23 ) ) {
F_63 ( & V_3 -> V_53 ,
L_48 , V_23 ) ;
goto V_370;
}
}
return;
V_370:
if ( F_177 ( V_3 , V_23 ) )
F_63 ( & V_3 -> V_53 , L_49 , V_23 ) ;
error:
V_23 -- ;
while ( V_23 >= V_367 ) {
if ( F_181 ( V_3 , V_23 ) )
F_63 ( & V_3 -> V_53 ,
L_50 , V_23 ) ;
if ( F_177 ( V_3 , V_23 ) )
F_63 ( & V_3 -> V_53 , L_49 , V_23 ) ;
V_23 -- ;
}
}
static void F_182 ( struct V_2 * V_3 )
{
int V_23 , V_371 , V_372 ;
if ( F_179 ( V_3 -> V_148 ) != V_369 )
return;
if ( V_3 -> V_148 == V_149 ) {
V_371 = 1 ;
V_372 = 0 ;
} else {
V_371 = V_3 -> V_285 ;
V_372 = 1 ;
}
for ( V_23 = 0 ; V_23 < V_371 ; V_23 ++ , V_372 ++ ) {
if ( F_181 ( V_3 , V_372 ) )
F_63 ( & V_3 -> V_53 ,
L_50 ,
V_372 ) ;
if ( F_177 ( V_3 , V_372 ) )
F_63 ( & V_3 -> V_53 , L_49 ,
V_372 ) ;
}
}
static int T_9 F_183 ( void )
{
int V_41 ;
V_351 = F_184 ( V_351 , V_373 ) ;
V_351 = F_185 ( V_351 , V_374 ) ;
V_349 = F_184 ( V_349 , V_373 ) ;
V_349 = F_185 ( V_349 , V_374 ) ;
V_156 = F_186 ( L_51 ,
sizeof( struct V_142 ) ,
0 ,
V_375 ,
NULL ) ;
if ( ! V_156 ) {
F_98 ( L_52 ) ;
V_41 = - V_66 ;
goto V_54;
}
F_23 ( & V_365 ) ;
if ( F_187 ( & V_376 ) ) {
F_98 ( L_53 ) ;
V_41 = - V_42 ;
goto V_71;
}
return 0 ;
V_71:
F_188 ( V_156 ) ;
V_54:
return V_41 ;
}
static void T_10 F_189 ( void )
{
F_190 ( & V_376 ) ;
F_188 ( V_156 ) ;
}
