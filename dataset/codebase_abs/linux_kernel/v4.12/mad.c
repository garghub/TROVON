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
int F_13 ( const struct V_26 * V_27 )
{
return ( ( V_27 -> V_22 & V_28 ) ||
( V_27 -> V_22 == V_29 ) ||
( ( V_27 -> V_8 == V_30 ) &&
( V_27 -> V_31 & V_32 ) ) ) ;
}
struct V_33 * F_14 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
struct V_19 * V_20 ,
T_1 V_34 ,
T_2 V_35 ,
T_3 V_36 ,
void * V_37 ,
T_4 V_38 )
{
struct V_1 * V_39 ;
struct V_33 * V_40 = F_15 ( - V_41 ) ;
struct V_42 * V_43 ;
struct V_19 * V_44 = NULL ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
struct V_21 * V_22 ;
int V_49 , V_50 ;
unsigned long V_6 ;
T_1 V_8 , V_51 ;
V_50 = F_7 ( V_11 ) ;
if ( V_50 == - 1 ) {
F_16 ( & V_3 -> V_52 ,
L_1 ,
V_11 ) ;
goto V_53;
}
if ( V_34 && V_34 != V_54 ) {
F_16 ( & V_3 -> V_52 ,
L_2 ,
V_34 ) ;
goto V_53;
}
if ( V_20 ) {
if ( V_20 -> V_55 >= V_56 ) {
F_16 ( & V_3 -> V_52 ,
L_3 ,
V_20 -> V_55 ) ;
goto V_53;
}
if ( ! V_36 ) {
F_16 ( & V_3 -> V_52 ,
L_4 ) ;
goto V_53;
}
if ( V_20 -> V_8 >= V_57 ) {
if ( V_20 -> V_8 !=
V_9 ) {
F_16 ( & V_3 -> V_52 ,
L_5 ,
V_20 -> V_8 ) ;
goto V_53;
}
} else if ( V_20 -> V_8 == 0 ) {
F_16 ( & V_3 -> V_52 ,
L_6 ) ;
goto V_53;
} else if ( F_9 ( V_20 -> V_8 ) ) {
if ( ! F_10 ( V_20 -> V_16 ) ) {
F_16 ( & V_3 -> V_52 ,
L_7 ,
V_20 -> V_8 ) ;
goto V_53;
}
}
if ( ! F_17 ( V_20 -> V_8 ) ) {
if ( V_34 ) {
F_16 ( & V_3 -> V_52 ,
L_8 ,
V_20 -> V_8 ) ;
goto V_53;
}
}
if ( V_11 == V_12 ) {
if ( ( V_20 -> V_8 !=
V_58 ) &&
( V_20 -> V_8 !=
V_9 ) ) {
F_16 ( & V_3 -> V_52 ,
L_9 ,
V_20 -> V_8 ) ;
goto V_53;
}
} else {
if ( ( V_20 -> V_8 ==
V_58 ) ||
( V_20 -> V_8 ==
V_9 ) ) {
F_16 ( & V_3 -> V_52 ,
L_10 ,
V_20 -> V_8 ) ;
goto V_53;
}
}
} else {
if ( ! V_35 )
goto V_53;
if ( V_38 & V_59 )
goto V_53;
}
V_39 = F_3 ( V_3 , V_4 ) ;
if ( ! V_39 ) {
F_16 ( & V_3 -> V_52 ,
L_11 ,
V_4 ) ;
V_40 = F_15 ( - V_60 ) ;
goto V_53;
}
if ( ! V_39 -> V_61 [ V_50 ] . V_62 ) {
F_16 ( & V_3 -> V_52 ,
L_12 , V_50 ) ;
V_40 = F_15 ( - V_63 ) ;
goto V_53;
}
V_43 = F_18 ( sizeof *V_43 , V_64 ) ;
if ( ! V_43 ) {
V_40 = F_15 ( - V_65 ) ;
goto V_53;
}
if ( V_20 ) {
V_44 = F_19 ( V_20 , sizeof *V_44 , V_64 ) ;
if ( ! V_44 ) {
V_40 = F_15 ( - V_65 ) ;
goto V_66;
}
}
V_43 -> V_61 = & V_39 -> V_61 [ V_50 ] ;
V_43 -> V_44 = V_44 ;
V_43 -> V_67 . V_34 = V_34 ;
V_43 -> V_67 . V_3 = V_3 ;
V_43 -> V_67 . V_36 = V_36 ;
V_43 -> V_67 . V_35 = V_35 ;
V_43 -> V_67 . V_37 = V_37 ;
V_43 -> V_67 . V_62 = V_39 -> V_61 [ V_50 ] . V_62 ;
V_43 -> V_67 . V_4 = V_4 ;
V_43 -> V_67 . V_6 = V_38 ;
F_20 ( & V_43 -> V_68 ) ;
F_21 ( & V_43 -> V_69 ) ;
F_21 ( & V_43 -> V_70 ) ;
F_21 ( & V_43 -> V_71 ) ;
F_21 ( & V_43 -> V_72 ) ;
F_22 ( & V_43 -> V_73 , V_74 ) ;
F_21 ( & V_43 -> V_75 ) ;
F_23 ( & V_43 -> V_76 , V_77 ) ;
F_24 ( & V_43 -> V_78 , 1 ) ;
F_25 ( & V_43 -> V_79 ) ;
F_4 ( & V_39 -> V_80 , V_6 ) ;
V_43 -> V_67 . V_81 = ++ V_82 ;
if ( V_20 ) {
V_8 = F_6 ( V_20 -> V_8 ) ;
if ( ! F_9 ( V_8 ) ) {
V_46 = V_39 -> V_83 [ V_20 ->
V_55 ] . V_46 ;
if ( V_46 ) {
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
if ( F_12 ( & V_22 ,
V_20 ) )
goto V_84;
}
}
V_49 = F_26 ( V_20 , V_43 ,
V_8 ) ;
} else {
V_48 = V_39 -> V_83 [ V_20 ->
V_55 ] . V_48 ;
if ( V_48 ) {
V_51 = F_8 ( V_8 ) ;
V_18 = V_48 -> V_18 [ V_51 ] ;
if ( V_18 ) {
if ( F_11 (
V_18 ,
V_20 ) )
goto V_84;
}
}
V_49 = F_27 ( V_20 , V_43 ) ;
}
if ( V_49 ) {
V_40 = F_15 ( V_49 ) ;
goto V_84;
}
}
F_28 ( & V_43 -> V_85 , & V_39 -> V_85 ) ;
F_5 ( & V_39 -> V_80 , V_6 ) ;
return & V_43 -> V_67 ;
V_84:
F_5 ( & V_39 -> V_80 , V_6 ) ;
F_29 ( V_44 ) ;
V_66:
F_29 ( V_43 ) ;
V_53:
return V_40 ;
}
static inline int F_30 ( int V_86 )
{
return ( V_86 &
(
V_87 ) ) ;
}
static inline int F_31 ( int V_86 )
{
return ( V_86 &
( V_88 ) ) ;
}
static int F_32 ( struct V_89 * V_61 ,
struct V_90 * V_91 )
{
struct V_90 * * V_92 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_93 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_94 ; V_23 ++ )
if ( ! V_61 -> V_95 [ V_23 ] )
break;
if ( V_23 == V_61 -> V_94 ) {
V_92 = F_33 ( V_61 -> V_95 ,
sizeof V_91 *
( V_61 -> V_94 + 1 ) ,
V_96 ) ;
if ( ! V_92 ) {
V_23 = - V_65 ;
goto V_97;
}
V_61 -> V_95 = V_92 ;
V_61 -> V_94 ++ ;
}
V_61 -> V_95 [ V_23 ] = V_91 ;
F_34 ( & V_61 -> V_98 ) ;
V_97:
F_5 ( & V_61 -> V_93 , V_6 ) ;
return V_23 ;
}
struct V_33 * F_35 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
int V_86 ,
T_5 V_99 ,
T_3 V_36 ,
void * V_37 )
{
struct V_1 * V_39 ;
struct V_33 * V_40 ;
struct V_90 * V_91 ;
int V_50 ;
if ( ( F_30 ( V_86 ) && ! V_99 ) ||
( F_31 ( V_86 ) && ! V_36 ) ) {
V_40 = F_15 ( - V_41 ) ;
goto V_53;
}
V_50 = F_7 ( V_11 ) ;
if ( V_50 == - 1 ) {
V_40 = F_15 ( - V_41 ) ;
goto V_53;
}
V_39 = F_3 ( V_3 , V_4 ) ;
if ( ! V_39 ) {
V_40 = F_15 ( - V_60 ) ;
goto V_53;
}
V_91 = F_18 ( sizeof *V_91 , V_64 ) ;
if ( ! V_91 ) {
V_40 = F_15 ( - V_65 ) ;
goto V_53;
}
V_91 -> V_61 = & V_39 -> V_61 [ V_50 ] ;
V_91 -> V_67 . V_3 = V_3 ;
V_91 -> V_67 . V_36 = V_36 ;
V_91 -> V_67 . V_99 = V_99 ;
V_91 -> V_67 . V_37 = V_37 ;
V_91 -> V_67 . V_62 = V_39 -> V_61 [ V_50 ] . V_62 ;
V_91 -> V_67 . V_4 = V_4 ;
V_91 -> V_86 = V_86 ;
F_25 ( & V_91 -> V_79 ) ;
V_91 -> V_100 = F_32 (
& V_39 -> V_61 [ V_50 ] ,
V_91 ) ;
if ( V_91 -> V_100 < 0 ) {
V_40 = F_15 ( V_91 -> V_100 ) ;
goto V_101;
}
F_24 ( & V_91 -> V_78 , 1 ) ;
return & V_91 -> V_67 ;
V_101:
F_29 ( V_91 ) ;
V_53:
return V_40 ;
}
static inline void F_36 ( struct V_42 * V_43 )
{
if ( F_37 ( & V_43 -> V_78 ) )
F_38 ( & V_43 -> V_79 ) ;
}
static inline void F_39 ( struct V_90 * V_91 )
{
if ( F_37 ( & V_91 -> V_78 ) )
F_38 ( & V_91 -> V_79 ) ;
}
static void F_40 ( struct V_42 * V_43 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_41 ( V_43 ) ;
V_39 = V_43 -> V_61 -> V_39 ;
F_42 ( & V_43 -> V_73 ) ;
F_4 ( & V_39 -> V_80 , V_6 ) ;
F_43 ( V_43 ) ;
F_44 ( & V_43 -> V_85 ) ;
F_5 ( & V_39 -> V_80 , V_6 ) ;
F_45 ( V_39 -> V_102 ) ;
F_46 ( V_43 ) ;
F_36 ( V_43 ) ;
F_47 ( & V_43 -> V_79 ) ;
F_29 ( V_43 -> V_44 ) ;
F_29 ( V_43 ) ;
}
static void F_48 ( struct V_90 * V_91 )
{
struct V_89 * V_61 ;
unsigned long V_6 ;
V_61 = V_91 -> V_61 ;
F_4 ( & V_61 -> V_93 , V_6 ) ;
V_61 -> V_95 [ V_91 -> V_100 ] = NULL ;
F_49 ( & V_61 -> V_98 ) ;
F_5 ( & V_61 -> V_93 , V_6 ) ;
F_39 ( V_91 ) ;
F_47 ( & V_91 -> V_79 ) ;
F_29 ( V_91 ) ;
}
void F_50 ( struct V_33 * V_103 )
{
struct V_42 * V_43 ;
struct V_90 * V_91 ;
if ( V_103 -> V_81 ) {
V_43 = F_51 ( V_103 ,
struct V_42 ,
V_67 ) ;
F_40 ( V_43 ) ;
} else {
V_91 = F_51 ( V_103 ,
struct V_90 ,
V_67 ) ;
F_48 ( V_91 ) ;
}
}
static void F_52 ( struct V_104 * V_105 )
{
struct V_106 * V_107 ;
unsigned long V_6 ;
F_53 ( ! V_105 -> V_107 ) ;
V_107 = V_105 -> V_107 ;
F_4 ( & V_107 -> V_68 , V_6 ) ;
F_44 ( & V_105 -> V_108 ) ;
V_107 -> V_109 -- ;
F_5 ( & V_107 -> V_68 , V_6 ) ;
}
static void F_54 ( struct V_89 * V_61 ,
struct V_110 * V_111 ,
struct V_112 * V_113 ,
int V_86 )
{
struct V_90 * V_91 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_93 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_94 ; V_23 ++ ) {
V_91 = V_61 -> V_95 [ V_23 ] ;
if ( ! V_91 ||
! ( V_91 -> V_86 & V_86 ) )
continue;
F_34 ( & V_91 -> V_78 ) ;
F_5 ( & V_61 -> V_93 , V_6 ) ;
V_91 -> V_67 . V_99 ( & V_91 -> V_67 ,
V_111 , V_113 ) ;
F_39 ( V_91 ) ;
F_4 ( & V_61 -> V_93 , V_6 ) ;
}
F_5 ( & V_61 -> V_93 , V_6 ) ;
}
static void F_55 ( struct V_89 * V_61 ,
struct V_114 * V_115 ,
int V_86 )
{
struct V_90 * V_91 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_93 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_94 ; V_23 ++ ) {
V_91 = V_61 -> V_95 [ V_23 ] ;
if ( ! V_91 ||
! ( V_91 -> V_86 & V_86 ) )
continue;
F_34 ( & V_91 -> V_78 ) ;
F_5 ( & V_61 -> V_93 , V_6 ) ;
V_91 -> V_67 . V_36 ( & V_91 -> V_67 , NULL ,
V_115 ) ;
F_39 ( V_91 ) ;
F_4 ( & V_61 -> V_93 , V_6 ) ;
}
F_5 ( & V_61 -> V_93 , V_6 ) ;
}
static void F_56 ( struct V_116 * V_62 , struct V_117 * V_118 , T_6 V_119 ,
T_6 V_120 , T_1 V_4 , struct V_121 * V_122 )
{
memset ( V_122 , 0 , sizeof *V_122 ) ;
V_122 -> V_123 = V_118 ;
V_122 -> V_124 = V_125 ;
V_122 -> V_126 = V_127 ;
V_122 -> V_120 = V_120 ;
V_122 -> V_128 = sizeof( struct V_129 ) + sizeof( struct V_130 ) ;
V_122 -> V_131 = V_132 ;
V_122 -> V_62 = V_62 ;
V_122 -> V_119 = V_119 ;
V_122 -> V_133 = 0 ;
V_122 -> V_134 = 0 ;
V_122 -> V_4 = V_4 ;
}
static T_7 F_57 ( const struct V_135 * V_136 )
{
return sizeof( struct V_135 ) + V_136 -> V_137 ;
}
static struct V_135 * F_58 ( T_7 V_137 , T_8 V_6 )
{
T_7 V_138 = sizeof( struct V_135 ) + V_137 ;
struct V_135 * V_40 = F_18 ( V_138 , V_6 ) ;
if ( V_40 )
V_40 -> V_137 = V_137 ;
return V_40 ;
}
static T_7 F_59 ( const struct V_1 * V_39 )
{
return F_60 ( V_39 -> V_3 , V_39 -> V_4 ) ;
}
static T_7 F_61 ( const struct V_135 * V_136 )
{
return sizeof( struct V_130 ) + V_136 -> V_137 ;
}
static int F_62 ( struct V_42 * V_43 ,
struct V_139 * V_140 )
{
int V_40 = 0 ;
struct V_141 * V_142 = V_140 -> V_111 . V_143 ;
struct V_144 * V_144 = (struct V_144 * ) V_142 ;
unsigned long V_6 ;
struct V_145 * V_146 ;
struct V_135 * V_147 ;
struct V_1 * V_39 ;
struct V_42 * V_148 = NULL ;
struct V_2 * V_3 = V_43 -> V_67 . V_3 ;
T_1 V_4 ;
struct V_121 V_149 ;
struct V_150 * V_151 = & V_140 -> V_151 ;
T_7 V_137 = F_59 ( V_43 -> V_61 -> V_39 ) ;
T_6 V_152 = 0 ;
T_6 V_153 ;
bool V_154 = F_63 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
if ( F_64 ( V_3 ) &&
V_142 -> V_8 == V_9 )
V_4 = V_151 -> V_4 ;
else
V_4 = V_43 -> V_67 . V_4 ;
if ( V_154 && V_142 -> V_155 == V_156 ) {
T_4 V_157 ;
if ( ( F_65 ( V_144 )
? V_144 -> V_158 . V_159 . V_160 : V_144 -> V_158 . V_159 . V_161 ) ==
V_162 &&
F_66 ( V_144 ,
F_64 ( V_3 ) ,
V_4 ) == V_163 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_13 ) ;
goto V_97;
}
V_157 = F_68 ( V_144 -> V_158 . V_159 . V_161 ) ;
if ( V_157 != F_68 ( V_162 ) &&
V_157 & 0xffff0000 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_14 ,
V_157 ) ;
goto V_97;
}
V_153 = ( T_6 ) ( V_157 & 0x0000ffff ) ;
if ( F_69 ( V_144 , V_3 ) == V_163 &&
F_70 ( V_144 , V_3 ) == V_163 )
goto V_97;
} else {
if ( ( F_71 ( V_142 ) ? V_142 -> V_160 : V_142 -> V_161 ) ==
V_164 &&
F_72 ( V_142 , F_64 ( V_3 ) , V_4 ) ==
V_163 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_15 ) ;
goto V_97;
}
V_153 = F_73 ( V_142 -> V_161 ) ;
if ( F_74 ( V_142 , V_3 ) == V_163 &&
F_75 ( V_142 , V_3 ) == V_163 )
goto V_97;
}
V_146 = F_76 ( sizeof *V_146 , V_96 ) ;
if ( ! V_146 ) {
V_40 = - V_65 ;
goto V_97;
}
V_146 -> V_147 = NULL ;
V_146 -> V_148 = NULL ;
V_147 = F_58 ( V_137 , V_96 ) ;
if ( ! V_147 ) {
V_40 = - V_65 ;
F_29 ( V_146 ) ;
goto V_97;
}
F_56 ( V_43 -> V_67 . V_62 ,
V_151 -> V_165 . V_123 , V_153 ,
V_151 -> V_120 ,
V_151 -> V_4 , & V_149 ) ;
if ( V_154 && V_142 -> V_166 == V_167 ) {
V_149 . V_128 = V_140 -> V_111 . V_168
+ V_140 -> V_111 . V_169
+ sizeof( struct V_130 ) ;
}
V_40 = V_3 -> V_170 ( V_3 , 0 , V_4 , & V_149 , NULL ,
( const struct V_26 * ) V_142 , V_137 ,
(struct V_26 * ) V_147 -> V_143 ,
& V_137 , & V_152 ) ;
switch ( V_40 )
{
case V_171 | V_172 :
if ( F_13 ( ( const struct V_26 * ) V_147 -> V_143 ) &&
V_43 -> V_67 . V_36 ) {
V_146 -> V_147 = V_147 ;
V_146 -> V_148 = V_43 ;
F_34 ( & V_43 -> V_78 ) ;
} else
F_29 ( V_147 ) ;
break;
case V_171 | V_173 :
F_29 ( V_147 ) ;
break;
case V_171 :
V_39 = F_3 ( V_43 -> V_67 . V_3 ,
V_43 -> V_67 . V_4 ) ;
if ( V_39 ) {
memcpy ( V_147 -> V_143 , V_142 , V_147 -> V_137 ) ;
V_148 = F_77 ( V_39 ,
( const struct V_26 * ) V_147 -> V_143 ) ;
}
if ( ! V_39 || ! V_148 ) {
F_29 ( V_147 ) ;
break;
}
V_146 -> V_147 = V_147 ;
V_146 -> V_148 = V_148 ;
break;
default:
F_29 ( V_147 ) ;
F_29 ( V_146 ) ;
V_40 = - V_41 ;
goto V_97;
}
V_146 -> V_140 = V_140 ;
if ( V_154 ) {
V_146 -> V_140 -> V_151 . V_120 = V_152 ;
V_146 -> V_174 = V_137 ;
}
F_34 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_28 ( & V_146 -> V_175 , & V_43 -> V_75 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
F_78 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_76 ) ;
V_40 = 1 ;
V_97:
return V_40 ;
}
static int F_79 ( int V_168 , int V_169 , T_7 V_137 )
{
int V_176 , V_177 ;
V_176 = V_137 - V_168 ;
if ( V_169 && V_176 ) {
V_177 = V_176 - V_169 % V_176 ;
return V_177 == V_176 ? 0 : V_177 ;
} else
return V_176 ;
}
static void F_80 ( struct V_139 * V_140 )
{
struct V_178 * V_179 , * V_180 ;
F_81 (s, t, &mad_send_wr->rmpp_list, list) {
F_44 ( & V_179 -> V_108 ) ;
F_29 ( V_179 ) ;
}
}
static int F_82 ( struct V_139 * V_151 ,
T_7 V_137 , T_8 V_181 )
{
struct V_110 * V_111 = & V_151 -> V_111 ;
struct V_182 * V_183 = V_111 -> V_143 ;
struct V_178 * V_184 = NULL ;
int V_185 , V_176 , V_177 ;
V_111 -> V_176 = V_137 - V_111 -> V_168 ;
V_111 -> V_186 = V_137 - V_187 ;
V_176 = V_111 -> V_176 ;
V_177 = V_151 -> V_177 ;
for ( V_185 = V_111 -> V_169 + V_177 ; V_185 > 0 ; V_185 -= V_176 ) {
V_184 = F_76 ( sizeof ( * V_184 ) + V_176 , V_181 ) ;
if ( ! V_184 ) {
F_80 ( V_151 ) ;
return - V_65 ;
}
V_184 -> V_188 = ++ V_111 -> V_189 ;
F_28 ( & V_184 -> V_108 , & V_151 -> V_72 ) ;
}
if ( V_177 )
memset ( V_184 -> V_190 + V_176 - V_177 , 0 , V_177 ) ;
V_183 -> V_191 . V_34 = V_151 -> V_43 ->
V_67 . V_34 ;
V_183 -> V_191 . V_192 = V_193 ;
F_83 ( & V_183 -> V_191 , V_194 ) ;
V_151 -> V_195 = F_51 ( V_151 -> V_72 . V_196 ,
struct V_178 , V_108 ) ;
V_151 -> V_197 = V_151 -> V_195 ;
return 0 ;
}
int F_84 ( const struct V_33 * V_67 )
{
return V_67 -> V_34 && ! ( V_67 -> V_6 & V_59 ) ;
}
struct V_110 * F_85 ( struct V_33 * V_103 ,
T_4 V_198 , T_6 V_120 ,
int V_199 ,
int V_168 , int V_169 ,
T_8 V_181 ,
T_1 V_166 )
{
struct V_42 * V_43 ;
struct V_139 * V_140 ;
int V_177 , V_200 , V_40 , V_138 ;
void * V_201 ;
T_7 V_137 ;
bool V_154 ;
V_43 = F_51 ( V_103 , struct V_42 ,
V_67 ) ;
V_154 = F_63 ( V_103 -> V_3 , V_103 -> V_4 ) ;
if ( V_154 && V_166 == V_167 )
V_137 = sizeof( struct V_202 ) ;
else
V_137 = sizeof( struct V_129 ) ;
V_177 = F_79 ( V_168 , V_169 , V_137 ) ;
V_200 = V_168 + V_169 + V_177 ;
if ( F_84 ( V_103 ) ) {
if ( ! V_199 && V_200 > V_137 )
return F_15 ( - V_41 ) ;
} else
if ( V_199 || V_200 > V_137 )
return F_15 ( - V_41 ) ;
V_138 = V_199 ? V_168 : V_137 ;
V_201 = F_18 ( sizeof *V_140 + V_138 , V_181 ) ;
if ( ! V_201 )
return F_15 ( - V_65 ) ;
V_140 = V_201 + V_138 ;
F_21 ( & V_140 -> V_72 ) ;
V_140 -> V_111 . V_143 = V_201 ;
V_140 -> V_111 . V_168 = V_168 ;
V_140 -> V_111 . V_169 = V_169 ;
V_140 -> V_177 = V_177 ;
V_140 -> V_43 = V_43 ;
V_140 -> V_203 [ 0 ] . V_204 = V_168 ;
V_140 -> V_203 [ 0 ] . V_205 = V_103 -> V_62 -> V_206 -> V_207 ;
if ( V_154 && V_166 == V_167 &&
V_169 < V_137 - V_168 )
V_140 -> V_203 [ 1 ] . V_204 = V_169 ;
else
V_140 -> V_203 [ 1 ] . V_204 = V_137 - V_168 ;
V_140 -> V_203 [ 1 ] . V_205 = V_103 -> V_62 -> V_206 -> V_207 ;
V_140 -> V_105 . V_118 . V_208 = V_209 ;
V_140 -> V_151 . V_165 . V_123 = & V_140 -> V_105 . V_118 ;
V_140 -> V_151 . V_165 . V_203 = V_140 -> V_203 ;
V_140 -> V_151 . V_165 . V_210 = 2 ;
V_140 -> V_151 . V_165 . V_126 = V_211 ;
V_140 -> V_151 . V_165 . V_212 = V_213 ;
V_140 -> V_151 . V_198 = V_198 ;
V_140 -> V_151 . V_214 = V_215 ;
V_140 -> V_151 . V_120 = V_120 ;
if ( V_199 ) {
V_40 = F_82 ( V_140 , V_137 , V_181 ) ;
if ( V_40 ) {
F_29 ( V_201 ) ;
return F_15 ( V_40 ) ;
}
}
V_140 -> V_111 . V_103 = V_103 ;
F_34 ( & V_43 -> V_78 ) ;
return & V_140 -> V_111 ;
}
int F_86 ( T_1 V_8 )
{
if ( V_8 == V_216 )
return V_217 ;
else if ( ( V_8 == V_218 ) ||
( V_8 == V_219 ) ||
( V_8 == V_220 ) )
return V_221 ;
else if ( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) )
return V_222 ;
else
return V_223 ;
}
int F_17 ( T_1 V_8 )
{
if ( ( V_8 == V_216 ) ||
( V_8 == V_218 ) ||
( V_8 == V_219 ) ||
( V_8 == V_220 ) ||
( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) ) )
return 1 ;
return 0 ;
}
void * F_87 ( struct V_110 * V_111 , int V_224 )
{
struct V_139 * V_140 ;
struct V_225 * V_108 ;
V_140 = F_51 ( V_111 , struct V_139 ,
V_111 ) ;
V_108 = & V_140 -> V_195 -> V_108 ;
if ( V_140 -> V_195 -> V_188 < V_224 ) {
F_2 (mad_send_wr->cur_seg, list, list)
if ( V_140 -> V_195 -> V_188 == V_224 )
break;
} else if ( V_140 -> V_195 -> V_188 > V_224 ) {
F_88 (mad_send_wr->cur_seg, list, list)
if ( V_140 -> V_195 -> V_188 == V_224 )
break;
}
return V_140 -> V_195 -> V_190 ;
}
static inline void * F_89 ( struct V_139 * V_140 )
{
if ( V_140 -> V_111 . V_189 )
return F_87 ( & V_140 -> V_111 ,
V_140 -> V_224 ) ;
else
return V_140 -> V_111 . V_143 +
V_140 -> V_111 . V_168 ;
}
void F_90 ( struct V_110 * V_111 )
{
struct V_42 * V_43 ;
struct V_139 * V_140 ;
V_43 = F_51 ( V_111 -> V_103 ,
struct V_42 , V_67 ) ;
V_140 = F_51 ( V_111 , struct V_139 ,
V_111 ) ;
F_80 ( V_140 ) ;
F_29 ( V_111 -> V_143 ) ;
F_36 ( V_43 ) ;
}
int F_91 ( struct V_139 * V_140 )
{
struct V_89 * V_61 ;
struct V_225 * V_108 ;
struct V_226 * V_227 ;
struct V_33 * V_103 ;
struct V_228 * V_229 ;
unsigned long V_6 ;
int V_40 ;
V_61 = V_140 -> V_43 -> V_61 ;
V_140 -> V_105 . V_107 = & V_61 -> V_230 ;
V_140 -> V_105 . V_118 . V_208 = V_209 ;
V_140 -> V_151 . V_165 . V_123 = & V_140 -> V_105 . V_118 ;
V_103 = V_140 -> V_111 . V_103 ;
V_229 = V_140 -> V_203 ;
V_229 [ 0 ] . V_231 = F_92 ( V_103 -> V_3 ,
V_140 -> V_111 . V_143 ,
V_229 [ 0 ] . V_204 ,
V_232 ) ;
if ( F_93 ( F_94 ( V_103 -> V_3 , V_229 [ 0 ] . V_231 ) ) )
return - V_65 ;
V_140 -> V_233 = V_229 [ 0 ] . V_231 ;
V_229 [ 1 ] . V_231 = F_92 ( V_103 -> V_3 ,
F_89 ( V_140 ) ,
V_229 [ 1 ] . V_204 ,
V_232 ) ;
if ( F_93 ( F_94 ( V_103 -> V_3 , V_229 [ 1 ] . V_231 ) ) ) {
F_95 ( V_103 -> V_3 ,
V_140 -> V_233 ,
V_229 [ 0 ] . V_204 , V_232 ) ;
return - V_65 ;
}
V_140 -> V_234 = V_229 [ 1 ] . V_231 ;
F_4 ( & V_61 -> V_230 . V_68 , V_6 ) ;
if ( V_61 -> V_230 . V_109 < V_61 -> V_230 . V_235 ) {
V_40 = F_96 ( V_103 -> V_62 , & V_140 -> V_151 . V_165 ,
& V_227 ) ;
V_108 = & V_61 -> V_230 . V_108 ;
} else {
V_40 = 0 ;
V_108 = & V_61 -> V_236 ;
}
if ( ! V_40 ) {
V_61 -> V_230 . V_109 ++ ;
F_28 ( & V_140 -> V_105 . V_108 , V_108 ) ;
}
F_5 ( & V_61 -> V_230 . V_68 , V_6 ) ;
if ( V_40 ) {
F_95 ( V_103 -> V_3 ,
V_140 -> V_233 ,
V_229 [ 0 ] . V_204 , V_232 ) ;
F_95 ( V_103 -> V_3 ,
V_140 -> V_234 ,
V_229 [ 1 ] . V_204 , V_232 ) ;
}
return V_40 ;
}
int F_97 ( struct V_110 * V_111 ,
struct V_110 * * V_237 )
{
struct V_42 * V_43 ;
struct V_110 * V_238 ;
struct V_139 * V_140 ;
unsigned long V_6 ;
int V_40 = - V_41 ;
for (; V_111 ; V_111 = V_238 ) {
V_140 = F_51 ( V_111 ,
struct V_139 ,
V_111 ) ;
V_43 = V_140 -> V_43 ;
if ( ! V_111 -> V_103 -> V_35 ||
( V_111 -> V_239 &&
! V_111 -> V_103 -> V_36 ) ) {
V_40 = - V_41 ;
goto error;
}
if ( ! F_17 ( ( (struct V_26 * ) V_111 -> V_143 ) -> V_8 ) ) {
if ( V_43 -> V_67 . V_34 ) {
V_40 = - V_41 ;
goto error;
}
}
V_238 = V_111 -> V_196 ;
V_140 -> V_151 . V_240 = V_111 -> V_240 ;
if ( ( (struct V_26 * ) V_111 -> V_143 ) -> V_8 ==
V_9 ) {
V_40 = F_62 ( V_43 ,
V_140 ) ;
if ( V_40 < 0 )
goto error;
else if ( V_40 == 1 )
continue;
}
V_140 -> V_241 = ( (struct V_26 * ) V_111 -> V_143 ) -> V_241 ;
V_140 -> V_242 = F_98 ( V_111 -> V_239 ) ;
V_140 -> V_243 = V_111 -> V_244 ;
V_140 -> V_245 = V_111 -> V_244 ;
V_111 -> V_244 = 0 ;
V_140 -> V_78 = 1 + ( V_140 -> V_242 > 0 ) ;
V_140 -> V_124 = V_125 ;
F_34 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_28 ( & V_140 -> V_85 ,
& V_43 -> V_69 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( F_84 ( & V_43 -> V_67 ) ) {
V_40 = F_99 ( V_140 ) ;
if ( V_40 >= 0 && V_40 != V_246 )
V_40 = F_91 ( V_140 ) ;
} else
V_40 = F_91 ( V_140 ) ;
if ( V_40 < 0 ) {
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_44 ( & V_140 -> V_85 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
F_49 ( & V_43 -> V_78 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_237 )
* V_237 = V_111 ;
return V_40 ;
}
void F_100 ( struct V_114 * V_115 )
{
struct V_247 * V_248 , * V_249 ;
struct V_250 * V_251 ;
struct V_135 * V_252 ;
struct V_225 V_253 ;
F_21 ( & V_253 ) ;
F_101 ( & V_115 -> V_72 , & V_253 ) ;
F_81 (mad_recv_buf, temp_recv_buf,
&free_list, list) {
V_115 = F_51 ( V_248 , struct V_114 ,
V_254 ) ;
V_251 = F_51 ( V_115 ,
struct V_250 ,
V_255 ) ;
V_252 = F_51 ( V_251 , struct V_135 ,
V_256 ) ;
F_29 ( V_252 ) ;
}
}
struct V_33 * F_102 ( struct V_116 * V_62 ,
T_1 V_34 ,
T_2 V_35 ,
T_3 V_36 ,
void * V_37 )
{
return F_15 ( - V_41 ) ;
}
int F_103 ( struct V_33 * V_103 ,
struct V_121 * V_122 )
{
F_67 ( & V_103 -> V_3 -> V_52 ,
L_16 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * * V_22 ,
struct V_19 * V_20 )
{
int V_23 ;
F_104 (i, mad_reg_req->method_mask, IB_MGMT_MAX_METHODS) {
if ( ( * V_22 ) -> V_67 [ V_23 ] ) {
F_105 ( L_17 , V_23 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_106 ( struct V_21 * * V_22 )
{
* V_22 = F_18 ( sizeof ** V_22 , V_96 ) ;
return ( * V_22 ) ? 0 : ( - V_65 ) ;
}
static int F_107 ( struct V_21 * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_257 ; V_23 ++ )
if ( V_22 -> V_67 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_108 ( struct V_45 * V_46 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_57 ; V_23 ++ )
if ( V_46 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_109 ( struct V_17 * V_18 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( V_18 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_110 ( struct V_17 * V_18 ,
const char * V_16 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( ! memcmp ( V_18 -> V_16 [ V_23 ] , V_16 , 3 ) )
return V_23 ;
return - 1 ;
}
static int F_111 ( struct V_47 * V_48 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_258 ; V_23 ++ )
if ( V_48 -> V_18 [ V_23 ] )
return 1 ;
return 0 ;
}
static void F_112 ( struct V_21 * V_22 ,
struct V_42 * V_67 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_257 ; V_23 ++ ) {
if ( V_22 -> V_67 [ V_23 ] == V_67 ) {
V_22 -> V_67 [ V_23 ] = NULL ;
}
}
}
static int F_26 ( struct V_19 * V_20 ,
struct V_42 * V_259 ,
T_1 V_8 )
{
struct V_1 * V_39 ;
struct V_45 * * V_46 ;
struct V_21 * * V_22 ;
int V_23 , V_40 ;
V_39 = V_259 -> V_61 -> V_39 ;
V_46 = & V_39 -> V_83 [ V_20 -> V_55 ] . V_46 ;
if ( ! * V_46 ) {
* V_46 = F_18 ( sizeof ** V_46 , V_96 ) ;
if ( ! * V_46 ) {
V_40 = - V_65 ;
goto V_53;
}
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ( V_40 = F_106 ( V_22 ) ) )
goto V_101;
} else {
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ! * V_22 ) {
if ( ( V_40 = F_106 ( V_22 ) ) )
goto V_53;
}
}
if ( F_12 ( V_22 , V_20 ) )
goto V_66;
F_104 ( V_23 , V_20 -> V_260 , V_257 )
( * V_22 ) -> V_67 [ V_23 ] = V_259 ;
return 0 ;
V_66:
F_112 ( * V_22 , V_259 ) ;
if ( ! F_107 ( * V_22 ) ) {
F_29 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
goto V_53;
V_101:
F_29 ( * V_46 ) ;
* V_46 = NULL ;
V_53:
return V_40 ;
}
static int F_27 ( struct V_19 * V_20 ,
struct V_42 * V_259 )
{
struct V_1 * V_39 ;
struct V_47 * * V_261 ;
struct V_47 * V_48 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_21 * * V_22 ;
int V_23 , V_40 = - V_65 ;
T_1 V_51 ;
V_51 = F_8 ( V_20 -> V_8 ) ;
V_39 = V_259 -> V_61 -> V_39 ;
V_261 = & V_39 -> V_83 [
V_20 -> V_55 ] . V_48 ;
if ( ! * V_261 ) {
V_48 = F_18 ( sizeof *V_48 , V_96 ) ;
if ( ! V_48 )
goto V_53;
* V_261 = V_48 ;
}
if ( ! ( * V_261 ) -> V_18 [ V_51 ] ) {
V_18 = F_18 ( sizeof *V_18 , V_96 ) ;
if ( ! V_18 )
goto V_101;
( * V_261 ) -> V_18 [ V_51 ] = V_18 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( ( * V_261 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ) {
V_22 = & ( * V_261 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_53 ( ! * V_22 ) ;
goto V_262;
}
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! F_10 ( ( * V_261 ) -> V_18 [
V_51 ] -> V_16 [ V_23 ] ) ) {
V_22 = & ( * V_261 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_53 ( * V_22 ) ;
if ( ( V_40 = F_106 ( V_22 ) ) )
goto V_66;
memcpy ( ( * V_261 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ;
goto V_262;
}
}
F_67 ( & V_259 -> V_67 . V_3 -> V_52 , L_18 ) ;
goto V_66;
V_262:
if ( F_12 ( V_22 , V_20 ) )
goto V_84;
F_104 ( V_23 , V_20 -> V_260 , V_257 )
( * V_22 ) -> V_67 [ V_23 ] = V_259 ;
return 0 ;
V_84:
F_112 ( * V_22 , V_259 ) ;
if ( ! F_107 ( * V_22 ) ) {
F_29 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
V_66:
if ( V_18 ) {
( * V_261 ) -> V_18 [ V_51 ] = NULL ;
F_29 ( V_18 ) ;
}
V_101:
if ( V_48 ) {
* V_261 = NULL ;
F_29 ( V_48 ) ;
}
V_53:
return V_40 ;
}
static void F_43 ( struct V_42 * V_259 )
{
struct V_1 * V_39 ;
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
int V_263 ;
T_1 V_8 ;
if ( ! V_259 -> V_44 ) {
goto V_97;
}
V_39 = V_259 -> V_61 -> V_39 ;
V_8 = F_6 ( V_259 -> V_44 -> V_8 ) ;
V_46 = V_39 -> V_83 [
V_259 -> V_44 -> V_55 ] . V_46 ;
if ( ! V_46 )
goto V_264;
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
F_112 ( V_22 , V_259 ) ;
if ( ! F_107 ( V_22 ) ) {
F_29 ( V_22 ) ;
V_46 -> V_25 [ V_8 ] = NULL ;
if ( ! F_108 ( V_46 ) ) {
F_29 ( V_46 ) ;
V_39 -> V_83 [
V_259 -> V_44 ->
V_55 ] . V_46 = NULL ;
}
}
}
V_264:
if ( ! F_9 ( V_8 ) )
goto V_97;
V_8 = F_8 ( V_259 -> V_44 -> V_8 ) ;
V_48 = V_39 -> V_83 [
V_259 -> V_44 -> V_55 ] . V_48 ;
if ( ! V_48 )
goto V_97;
V_18 = V_48 -> V_18 [ V_8 ] ;
if ( V_18 ) {
V_263 = F_110 ( V_18 , V_259 -> V_44 -> V_16 ) ;
if ( V_263 < 0 )
goto V_97;
V_22 = V_18 -> V_25 [ V_263 ] ;
if ( V_22 ) {
F_112 ( V_22 , V_259 ) ;
if ( ! F_107 ( V_22 ) ) {
F_29 ( V_22 ) ;
V_18 -> V_25 [ V_263 ] = NULL ;
memset ( V_18 -> V_16 [ V_263 ] , 0 , 3 ) ;
if ( ! F_109 ( V_18 ) ) {
F_29 ( V_18 ) ;
V_48 -> V_18 [ V_8 ] = NULL ;
if ( ! F_111 ( V_48 ) ) {
F_29 ( V_48 ) ;
V_39 -> V_83 [
V_259 -> V_44 ->
V_55 ] .
V_48 = NULL ;
}
}
}
}
}
V_97:
return;
}
static struct V_42 *
F_77 ( struct V_1 * V_39 ,
const struct V_26 * V_265 )
{
struct V_42 * V_103 = NULL ;
unsigned long V_6 ;
F_4 ( & V_39 -> V_80 , V_6 ) ;
if ( F_13 ( V_265 ) ) {
T_4 V_81 ;
struct V_42 * V_5 ;
V_81 = F_113 ( V_265 -> V_241 ) >> 32 ;
F_2 (entry, &port_priv->agent_list, agent_list) {
if ( V_5 -> V_67 . V_81 == V_81 ) {
V_103 = V_5 ;
break;
}
}
} else {
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
const struct V_266 * V_267 ;
int V_263 ;
if ( V_265 -> V_155 >= V_56 )
goto V_97;
if ( ! F_9 ( V_265 -> V_8 ) ) {
V_46 = V_39 -> V_83 [
V_265 -> V_155 ] . V_46 ;
if ( ! V_46 )
goto V_97;
if ( F_6 ( V_265 -> V_8 ) >=
F_114 ( V_46 -> V_25 ) )
goto V_97;
V_22 = V_46 -> V_25 [ F_6 (
V_265 -> V_8 ) ] ;
if ( V_22 )
V_103 = V_22 -> V_67 [ V_265 -> V_22 &
~ V_28 ] ;
} else {
V_48 = V_39 -> V_83 [
V_265 -> V_155 ] . V_48 ;
if ( ! V_48 )
goto V_97;
V_18 = V_48 -> V_18 [ F_8 (
V_265 -> V_8 ) ] ;
if ( ! V_18 )
goto V_97;
V_267 = ( const struct V_266 * ) V_265 ;
V_263 = F_110 ( V_18 , V_267 -> V_16 ) ;
if ( V_263 == - 1 )
goto V_97;
V_22 = V_18 -> V_25 [ V_263 ] ;
if ( V_22 ) {
V_103 = V_22 -> V_67 [ V_265 -> V_22 &
~ V_28 ] ;
}
}
}
if ( V_103 ) {
if ( V_103 -> V_67 . V_36 )
F_34 ( & V_103 -> V_78 ) ;
else {
F_16 ( & V_39 -> V_3 -> V_52 ,
L_19 ,
& V_103 -> V_67 , V_39 -> V_4 ) ;
V_103 = NULL ;
}
}
V_97:
F_5 ( & V_39 -> V_80 , V_6 ) ;
return V_103 ;
}
static int F_115 ( const struct V_26 * V_265 ,
const struct V_89 * V_61 ,
bool V_154 )
{
int V_268 = 0 ;
T_4 V_269 = V_61 -> V_62 -> V_269 ;
if ( V_265 -> V_166 != V_270 &&
( ! V_154 || V_265 -> V_166 != V_167 ) ) {
F_105 ( L_20 ,
V_265 -> V_166 , V_154 ? L_21 : L_22 ) ;
goto V_97;
}
if ( ( V_265 -> V_8 == V_58 ) ||
( V_265 -> V_8 == V_9 ) ) {
if ( V_269 == 0 )
V_268 = 1 ;
} else {
if ( ( V_265 -> V_8 == V_271 ) &&
( V_265 -> V_272 != V_273 ) &&
( V_265 -> V_22 != V_274 ) )
goto V_97;
if ( V_269 != 0 )
V_268 = 1 ;
}
V_97:
return V_268 ;
}
static int F_116 ( const struct V_42 * V_43 ,
const struct V_26 * V_265 )
{
struct V_182 * V_183 ;
V_183 = (struct V_182 * ) V_265 ;
return ! V_43 -> V_67 . V_34 ||
! F_84 ( & V_43 -> V_67 ) ||
! ( F_117 ( & V_183 -> V_191 ) &
V_194 ) ||
( V_183 -> V_191 . V_192 == V_193 ) ;
}
static inline int F_118 ( const struct V_139 * V_165 ,
const struct V_114 * V_275 )
{
return ( (struct V_26 * ) ( V_165 -> V_111 . V_143 ) ) -> V_8 ==
V_275 -> V_254 . V_143 -> V_265 . V_8 ;
}
static inline int F_119 ( const struct V_42 * V_43 ,
const struct V_139 * V_165 ,
const struct V_114 * V_275 )
{
struct V_276 V_277 ;
T_1 V_278 , V_279 ;
union V_280 V_281 ;
struct V_2 * V_3 = V_43 -> V_67 . V_3 ;
T_1 V_4 = V_43 -> V_67 . V_4 ;
T_1 V_282 ;
bool V_283 ;
V_278 = F_13 ( (struct V_26 * ) V_165 -> V_111 . V_143 ) ;
V_279 = F_13 ( & V_275 -> V_254 . V_143 -> V_265 ) ;
if ( V_278 == V_279 )
return 0 ;
if ( F_120 ( V_165 -> V_111 . V_240 , & V_277 ) )
return 0 ;
V_283 = ! ! ( F_121 ( & V_277 ) & V_284 ) ;
if ( V_283 != ! ! ( V_275 -> V_122 -> V_285 & V_286 ) )
return 0 ;
if ( ! V_278 && V_279 ) {
if ( ! V_283 ) {
if ( F_122 ( V_3 , V_4 , & V_282 ) )
return 0 ;
return ( ! V_282 || ! ( ( F_123 ( & V_277 ) ^
V_275 -> V_122 -> V_134 ) &
( ( 1 << V_282 ) - 1 ) ) ) ;
} else {
const struct V_287 * V_288 =
F_124 ( & V_277 ) ;
if ( F_125 ( V_3 , V_4 ,
V_288 -> V_289 , & V_281 , NULL ) )
return 0 ;
return ! memcmp ( V_281 . V_290 , V_275 -> V_254 . V_288 -> V_291 . V_290 ,
16 ) ;
}
}
if ( ! V_283 )
return F_126 ( & V_277 ) == V_275 -> V_122 -> V_119 ;
else
return ! memcmp ( F_124 ( & V_277 ) -> V_291 . V_290 ,
V_275 -> V_254 . V_288 -> V_281 . V_290 ,
16 ) ;
}
static inline int F_127 ( T_1 V_46 )
{
return ( V_46 == V_9 ) ;
}
struct V_139 *
F_128 ( const struct V_42 * V_43 ,
const struct V_114 * V_122 )
{
struct V_139 * V_165 ;
const struct V_26 * V_265 ;
V_265 = & V_122 -> V_254 . V_143 -> V_265 ;
F_2 (wr, &mad_agent_priv->wait_list, agent_list) {
if ( ( V_165 -> V_241 == V_265 -> V_241 ) &&
F_118 ( V_165 , V_122 ) &&
( F_127 ( V_265 -> V_8 ) ||
F_119 ( V_43 , V_165 , V_122 ) ) )
return ( V_165 -> V_124 == V_125 ) ? V_165 : NULL ;
}
F_2 (wr, &mad_agent_priv->send_list, agent_list) {
if ( F_116 ( V_43 , V_165 -> V_111 . V_143 ) &&
V_165 -> V_241 == V_265 -> V_241 &&
V_165 -> V_242 &&
F_118 ( V_165 , V_122 ) &&
( F_127 ( V_265 -> V_8 ) ||
F_119 ( V_43 , V_165 , V_122 ) ) )
return ( V_165 -> V_124 == V_125 ) ? V_165 : NULL ;
}
return NULL ;
}
void F_129 ( struct V_139 * V_140 )
{
V_140 -> V_242 = 0 ;
if ( V_140 -> V_78 == 1 )
F_130 ( & V_140 -> V_85 ,
& V_140 -> V_43 -> V_71 ) ;
}
static void F_131 ( struct V_42 * V_43 ,
struct V_114 * V_115 )
{
struct V_139 * V_140 ;
struct V_112 V_113 ;
unsigned long V_6 ;
F_21 ( & V_115 -> V_72 ) ;
F_132 ( & V_115 -> V_254 . V_108 , & V_115 -> V_72 ) ;
if ( F_84 ( & V_43 -> V_67 ) ) {
V_115 = F_133 ( V_43 ,
V_115 ) ;
if ( ! V_115 ) {
F_36 ( V_43 ) ;
return;
}
}
if ( F_13 ( & V_115 -> V_254 . V_143 -> V_265 ) ) {
F_4 ( & V_43 -> V_68 , V_6 ) ;
V_140 = F_128 ( V_43 , V_115 ) ;
if ( ! V_140 ) {
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( ! F_84 ( & V_43 -> V_67 )
&& F_17 ( V_115 -> V_254 . V_143 -> V_265 . V_8 )
&& ( F_117 ( & ( (struct V_182 * ) V_115 -> V_254 . V_143 ) -> V_191 )
& V_194 ) ) {
V_43 -> V_67 . V_36 (
& V_43 -> V_67 , NULL ,
V_115 ) ;
F_49 ( & V_43 -> V_78 ) ;
} else {
F_100 ( V_115 ) ;
F_36 ( V_43 ) ;
return;
}
} else {
F_129 ( V_140 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_43 -> V_67 . V_36 (
& V_43 -> V_67 ,
& V_140 -> V_111 ,
V_115 ) ;
F_49 ( & V_43 -> V_78 ) ;
V_113 . V_124 = V_125 ;
V_113 . V_292 = 0 ;
V_113 . V_111 = & V_140 -> V_111 ;
F_134 ( V_140 , & V_113 ) ;
}
} else {
V_43 -> V_67 . V_36 ( & V_43 -> V_67 , NULL ,
V_115 ) ;
F_36 ( V_43 ) ;
}
}
static enum V_293 F_135 ( const struct V_1 * V_39 ,
const struct V_89 * V_61 ,
const struct V_121 * V_122 ,
int V_4 ,
struct V_135 * V_294 ,
struct V_135 * V_295 )
{
enum V_296 V_297 ;
struct V_141 * V_142 = (struct V_141 * ) V_294 -> V_143 ;
if ( F_136 ( V_142 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_298 ) ==
V_163 )
return V_163 ;
V_297 = F_137 ( V_142 ) ;
if ( V_297 == V_299 )
return V_300 ;
if ( V_297 == V_301 ) {
if ( F_72 ( V_142 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ) == V_163 )
return V_163 ;
if ( F_74 ( V_142 , V_39 -> V_3 ) == V_163 )
return V_163 ;
} else if ( F_64 ( V_39 -> V_3 ) ) {
memcpy ( V_295 , V_294 , F_57 ( V_295 ) ) ;
V_295 -> V_256 . V_255 . V_122 = & V_295 -> V_256 . V_122 ;
V_295 -> V_256 . V_255 . V_254 . V_143 = (struct V_129 * ) V_295 -> V_143 ;
V_295 -> V_256 . V_255 . V_254 . V_288 = & V_295 -> V_288 ;
F_138 ( ( const struct V_26 * ) V_295 -> V_143 ,
& V_295 -> V_288 , V_122 ,
V_39 -> V_3 ,
F_139 ( V_142 ) ,
V_61 -> V_62 -> V_269 ,
V_295 -> V_137 ,
false ) ;
return V_163 ;
}
return V_300 ;
}
static bool F_140 ( const struct V_135 * V_294 ,
struct V_135 * V_295 ,
T_7 * V_302 , bool V_154 )
{
const struct V_26 * V_303 = ( const struct V_26 * ) V_294 -> V_143 ;
struct V_26 * V_304 = (struct V_26 * ) V_295 -> V_143 ;
if ( V_303 -> V_22 == V_305 ||
V_303 -> V_22 == V_306 ) {
memcpy ( V_295 , V_294 , F_57 ( V_295 ) ) ;
V_295 -> V_256 . V_255 . V_122 = & V_295 -> V_256 . V_122 ;
V_295 -> V_256 . V_255 . V_254 . V_143 = (struct V_129 * ) V_295 -> V_143 ;
V_295 -> V_256 . V_255 . V_254 . V_288 = & V_295 -> V_288 ;
V_304 -> V_22 = V_307 ;
V_304 -> V_124 = F_141 ( V_308 ) ;
if ( V_303 -> V_8 == V_9 )
V_304 -> V_124 |= V_309 ;
if ( V_154 && V_303 -> V_166 == V_167 ) {
if ( V_303 -> V_8 ==
V_58 ||
V_303 -> V_8 ==
V_9 )
* V_302 = F_142 (
(struct V_144 * ) V_294 -> V_143 ) ;
else
* V_302 = sizeof( struct V_26 ) ;
}
return true ;
} else {
return false ;
}
}
static enum V_293
F_143 ( struct V_1 * V_39 ,
struct V_89 * V_61 ,
struct V_121 * V_122 ,
int V_4 ,
struct V_135 * V_294 ,
struct V_135 * V_295 )
{
enum V_296 V_297 ;
struct V_144 * V_142 = (struct V_144 * ) V_294 -> V_143 ;
if ( F_144 ( V_142 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_298 ) ==
V_163 )
return V_163 ;
V_297 = F_145 ( V_142 ) ;
if ( V_297 == V_299 )
return V_300 ;
if ( V_297 == V_301 ) {
if ( F_66 ( V_142 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ) == V_163 )
return V_163 ;
if ( F_69 ( V_142 , V_39 -> V_3 ) ==
V_163 )
return V_163 ;
} else if ( F_64 ( V_39 -> V_3 ) ) {
memcpy ( V_295 , V_294 , F_57 ( V_295 ) ) ;
V_295 -> V_256 . V_255 . V_122 = & V_295 -> V_256 . V_122 ;
V_295 -> V_256 . V_255 . V_254 . V_202 =
(struct V_202 * ) V_295 -> V_143 ;
V_295 -> V_256 . V_255 . V_254 . V_288 = & V_295 -> V_288 ;
F_138 ( ( const struct V_26 * ) V_295 -> V_143 ,
& V_295 -> V_288 , V_122 ,
V_39 -> V_3 ,
F_146 ( V_142 ) ,
V_61 -> V_62 -> V_269 ,
V_294 -> V_256 . V_122 . V_128 ,
true ) ;
return V_163 ;
}
return V_300 ;
}
static enum V_293
F_147 ( struct V_1 * V_39 ,
struct V_89 * V_61 ,
struct V_121 * V_122 ,
int V_4 ,
struct V_135 * V_294 ,
struct V_135 * V_295 ,
bool V_154 )
{
struct V_26 * V_265 = (struct V_26 * ) V_294 -> V_143 ;
if ( V_154 && V_265 -> V_166 == V_167 &&
V_265 -> V_155 == V_156 )
return F_143 ( V_39 , V_61 , V_122 , V_4 , V_294 ,
V_295 ) ;
return F_135 ( V_39 , V_61 , V_122 , V_4 , V_294 , V_295 ) ;
}
static void F_148 ( struct V_310 * V_311 , struct V_121 * V_122 )
{
struct V_1 * V_39 = V_311 -> V_312 ;
struct V_104 * V_105 =
F_51 ( V_122 -> V_123 , struct V_104 , V_118 ) ;
struct V_89 * V_61 ;
struct V_250 * V_251 ;
struct V_135 * V_294 , * V_295 = NULL ;
struct V_42 * V_103 ;
int V_4 ;
int V_40 = V_171 ;
T_7 V_137 ;
T_6 V_313 = 0 ;
bool V_154 ;
if ( F_149 ( & V_39 -> V_314 ) )
return;
if ( V_122 -> V_124 != V_125 ) {
return;
}
V_61 = V_105 -> V_107 -> V_61 ;
F_52 ( V_105 ) ;
V_154 = F_63 ( V_61 -> V_39 -> V_3 ,
V_61 -> V_39 -> V_4 ) ;
V_251 = F_51 ( V_105 , struct V_250 ,
V_105 ) ;
V_294 = F_51 ( V_251 , struct V_135 , V_256 ) ;
F_95 ( V_39 -> V_3 ,
V_294 -> V_256 . V_315 ,
F_61 ( V_294 ) ,
V_316 ) ;
V_294 -> V_256 . V_122 = * V_122 ;
V_294 -> V_256 . V_255 . V_122 = & V_294 -> V_256 . V_122 ;
if ( V_154 && ( (struct V_26 * ) ( V_294 -> V_143 ) ) -> V_166 == V_167 ) {
V_294 -> V_256 . V_255 . V_317 = V_122 -> V_128 - sizeof( struct V_130 ) ;
V_294 -> V_256 . V_255 . V_318 = sizeof( struct V_202 ) ;
} else {
V_294 -> V_256 . V_255 . V_317 = sizeof( struct V_129 ) ;
V_294 -> V_256 . V_255 . V_318 = sizeof( struct V_129 ) ;
}
V_294 -> V_256 . V_255 . V_254 . V_143 = (struct V_129 * ) V_294 -> V_143 ;
V_294 -> V_256 . V_255 . V_254 . V_288 = & V_294 -> V_288 ;
if ( F_150 ( & V_61 -> V_98 ) )
F_55 ( V_61 , & V_294 -> V_256 . V_255 , V_88 ) ;
if ( ! F_115 ( ( const struct V_26 * ) V_294 -> V_143 , V_61 , V_154 ) )
goto V_97;
V_137 = V_294 -> V_137 ;
V_295 = F_58 ( V_137 , V_64 ) ;
if ( ! V_295 )
goto V_97;
if ( F_64 ( V_39 -> V_3 ) )
V_4 = V_122 -> V_4 ;
else
V_4 = V_39 -> V_4 ;
if ( ( (struct V_26 * ) V_294 -> V_143 ) -> V_8 ==
V_9 ) {
if ( F_147 ( V_39 , V_61 , V_122 , V_4 , V_294 ,
V_295 , V_154 )
== V_163 )
goto V_97;
}
if ( V_39 -> V_3 -> V_170 ) {
V_40 = V_39 -> V_3 -> V_170 ( V_39 -> V_3 , 0 ,
V_39 -> V_4 ,
V_122 , & V_294 -> V_288 ,
( const struct V_26 * ) V_294 -> V_143 ,
V_294 -> V_137 ,
(struct V_26 * ) V_295 -> V_143 ,
& V_137 , & V_313 ) ;
if ( V_154 )
V_122 -> V_120 = V_313 ;
if ( V_40 & V_171 ) {
if ( V_40 & V_173 )
goto V_97;
if ( V_40 & V_172 ) {
F_138 ( ( const struct V_26 * ) V_295 -> V_143 ,
& V_294 -> V_288 , V_122 ,
V_39 -> V_3 ,
V_4 ,
V_61 -> V_62 -> V_269 ,
V_137 , V_154 ) ;
goto V_97;
}
}
}
V_103 = F_77 ( V_39 , ( const struct V_26 * ) V_294 -> V_143 ) ;
if ( V_103 ) {
F_131 ( V_103 , & V_294 -> V_256 . V_255 ) ;
V_294 = NULL ;
} else if ( ( V_40 & V_171 ) &&
F_140 ( V_294 , V_295 , & V_137 , V_154 ) ) {
F_138 ( ( const struct V_26 * ) V_295 -> V_143 , & V_294 -> V_288 , V_122 ,
V_39 -> V_3 , V_4 ,
V_61 -> V_62 -> V_269 , V_137 , V_154 ) ;
}
V_97:
if ( V_295 ) {
F_151 ( V_61 , V_295 ) ;
F_29 ( V_294 ) ;
} else
F_151 ( V_61 , V_294 ) ;
}
static void F_152 ( struct V_42 * V_43 )
{
struct V_139 * V_140 ;
unsigned long V_319 ;
if ( F_153 ( & V_43 -> V_70 ) ) {
F_42 ( & V_43 -> V_73 ) ;
} else {
V_140 = F_154 ( V_43 -> V_70 . V_196 ,
struct V_139 ,
V_85 ) ;
if ( F_155 ( V_43 -> V_242 ,
V_140 -> V_242 ) ) {
V_43 -> V_242 = V_140 -> V_242 ;
V_319 = V_140 -> V_242 - V_320 ;
if ( ( long ) V_319 <= 0 )
V_319 = 1 ;
F_156 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_73 , V_319 ) ;
}
}
}
static void F_157 ( struct V_139 * V_140 )
{
struct V_42 * V_43 ;
struct V_139 * V_321 ;
struct V_225 * V_322 ;
unsigned long V_319 ;
V_43 = V_140 -> V_43 ;
F_44 ( & V_140 -> V_85 ) ;
V_319 = V_140 -> V_242 ;
V_140 -> V_242 += V_320 ;
if ( V_319 ) {
F_158 (list_item, &mad_agent_priv->wait_list) {
V_321 = F_154 ( V_322 ,
struct V_139 ,
V_85 ) ;
if ( F_155 ( V_140 -> V_242 ,
V_321 -> V_242 ) )
break;
}
}
else
V_322 = & V_43 -> V_70 ;
F_132 ( & V_140 -> V_85 , V_322 ) ;
if ( V_43 -> V_70 . V_196 == & V_140 -> V_85 )
F_156 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_73 , V_319 ) ;
}
void F_159 ( struct V_139 * V_140 ,
int V_239 )
{
V_140 -> V_242 = F_98 ( V_239 ) ;
F_157 ( V_140 ) ;
}
void F_134 ( struct V_139 * V_140 ,
struct V_112 * V_113 )
{
struct V_42 * V_43 ;
unsigned long V_6 ;
int V_40 ;
V_43 = V_140 -> V_43 ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
if ( F_84 ( & V_43 -> V_67 ) ) {
V_40 = F_160 ( V_140 , V_113 ) ;
if ( V_40 == V_246 )
goto V_208;
} else
V_40 = V_323 ;
if ( V_113 -> V_124 != V_125 &&
V_140 -> V_124 == V_125 ) {
V_140 -> V_124 = V_113 -> V_124 ;
V_140 -> V_78 -= ( V_140 -> V_242 > 0 ) ;
}
if ( -- V_140 -> V_78 > 0 ) {
if ( V_140 -> V_78 == 1 && V_140 -> V_242 &&
V_140 -> V_124 == V_125 ) {
F_157 ( V_140 ) ;
}
goto V_208;
}
F_44 ( & V_140 -> V_85 ) ;
F_152 ( V_43 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_140 -> V_124 != V_125 )
V_113 -> V_124 = V_140 -> V_124 ;
if ( V_40 == V_324 )
F_161 ( V_113 ) ;
else
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
V_113 ) ;
F_36 ( V_43 ) ;
return;
V_208:
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static void V_209 ( struct V_310 * V_311 , struct V_121 * V_122 )
{
struct V_1 * V_39 = V_311 -> V_312 ;
struct V_104 * V_105 =
F_51 ( V_122 -> V_123 , struct V_104 , V_118 ) ;
struct V_139 * V_140 , * V_325 ;
struct V_89 * V_61 ;
struct V_106 * V_230 ;
struct V_226 * V_227 ;
struct V_112 V_113 ;
unsigned long V_6 ;
int V_40 ;
if ( F_149 ( & V_39 -> V_314 ) )
return;
if ( V_122 -> V_124 != V_125 ) {
if ( ! F_162 ( V_39 , V_122 ) )
return;
}
V_140 = F_51 ( V_105 , struct V_139 ,
V_105 ) ;
V_230 = V_105 -> V_107 ;
V_61 = V_230 -> V_61 ;
V_326:
F_95 ( V_140 -> V_111 . V_103 -> V_3 ,
V_140 -> V_233 ,
V_140 -> V_203 [ 0 ] . V_204 , V_232 ) ;
F_95 ( V_140 -> V_111 . V_103 -> V_3 ,
V_140 -> V_234 ,
V_140 -> V_203 [ 1 ] . V_204 , V_232 ) ;
V_325 = NULL ;
F_4 ( & V_230 -> V_68 , V_6 ) ;
F_44 ( & V_105 -> V_108 ) ;
if ( V_230 -> V_109 -- > V_230 -> V_235 ) {
V_105 = F_51 ( V_61 -> V_236 . V_196 ,
struct V_104 , V_108 ) ;
V_325 = F_51 ( V_105 ,
struct V_139 ,
V_105 ) ;
F_130 ( & V_105 -> V_108 , & V_230 -> V_108 ) ;
}
F_5 ( & V_230 -> V_68 , V_6 ) ;
V_113 . V_111 = & V_140 -> V_111 ;
V_113 . V_124 = V_122 -> V_124 ;
V_113 . V_292 = V_122 -> V_292 ;
if ( F_150 ( & V_61 -> V_98 ) )
F_54 ( V_61 , & V_140 -> V_111 , & V_113 ,
V_87 ) ;
F_134 ( V_140 , & V_113 ) ;
if ( V_325 ) {
V_40 = F_96 ( V_61 -> V_62 , & V_325 -> V_151 . V_165 ,
& V_227 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_23 , V_40 ) ;
V_140 = V_325 ;
V_122 -> V_124 = V_327 ;
goto V_326;
}
}
}
static void F_163 ( struct V_89 * V_61 )
{
struct V_139 * V_140 ;
struct V_104 * V_105 ;
unsigned long V_6 ;
F_4 ( & V_61 -> V_230 . V_68 , V_6 ) ;
F_2 (mad_list, &qp_info->send_queue.list, list) {
V_140 = F_51 ( V_105 ,
struct V_139 ,
V_105 ) ;
V_140 -> V_326 = 1 ;
}
F_5 ( & V_61 -> V_230 . V_68 , V_6 ) ;
}
static bool F_162 ( struct V_1 * V_39 ,
struct V_121 * V_122 )
{
struct V_104 * V_105 =
F_51 ( V_122 -> V_123 , struct V_104 , V_118 ) ;
struct V_89 * V_61 = V_105 -> V_107 -> V_61 ;
struct V_139 * V_140 ;
int V_40 ;
V_140 = F_51 ( V_105 , struct V_139 ,
V_105 ) ;
if ( V_122 -> V_124 == V_328 ) {
if ( V_140 -> V_326 ) {
struct V_226 * V_227 ;
V_140 -> V_326 = 0 ;
V_40 = F_96 ( V_61 -> V_62 , & V_140 -> V_151 . V_165 ,
& V_227 ) ;
if ( ! V_40 )
return false ;
}
} else {
struct V_329 * V_277 ;
V_277 = F_76 ( sizeof *V_277 , V_64 ) ;
if ( V_277 ) {
V_277 -> V_330 = V_331 ;
V_277 -> V_332 = V_333 ;
V_40 = F_164 ( V_61 -> V_62 , V_277 ,
V_334 | V_335 ) ;
F_29 ( V_277 ) ;
if ( V_40 )
F_67 ( & V_39 -> V_3 -> V_52 ,
L_24 ,
V_336 , V_40 ) ;
else
F_163 ( V_61 ) ;
}
}
return true ;
}
static void F_41 ( struct V_42 * V_43 )
{
unsigned long V_6 ;
struct V_139 * V_140 , * V_321 ;
struct V_112 V_113 ;
struct V_225 V_337 ;
F_21 ( & V_337 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_81 (mad_send_wr, temp_mad_send_wr,
&mad_agent_priv->send_list, agent_list) {
if ( V_140 -> V_124 == V_125 ) {
V_140 -> V_124 = V_328 ;
V_140 -> V_78 -= ( V_140 -> V_242 > 0 ) ;
}
}
F_101 ( & V_43 -> V_70 , & V_337 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_113 . V_124 = V_328 ;
V_113 . V_292 = 0 ;
F_81 (mad_send_wr, temp_mad_send_wr,
&cancel_list, agent_list) {
V_113 . V_111 = & V_140 -> V_111 ;
F_44 ( & V_140 -> V_85 ) ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_113 ) ;
F_49 ( & V_43 -> V_78 ) ;
}
}
static struct V_139 *
F_165 ( struct V_42 * V_43 ,
struct V_110 * V_111 )
{
struct V_139 * V_140 ;
F_2 (mad_send_wr, &mad_agent_priv->wait_list,
agent_list) {
if ( & V_140 -> V_111 == V_111 )
return V_140 ;
}
F_2 (mad_send_wr, &mad_agent_priv->send_list,
agent_list) {
if ( F_116 ( V_43 ,
V_140 -> V_111 . V_143 ) &&
& V_140 -> V_111 == V_111 )
return V_140 ;
}
return NULL ;
}
int F_166 ( struct V_33 * V_103 ,
struct V_110 * V_111 , T_4 V_239 )
{
struct V_42 * V_43 ;
struct V_139 * V_140 ;
unsigned long V_6 ;
int V_338 ;
V_43 = F_51 ( V_103 , struct V_42 ,
V_67 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
V_140 = F_165 ( V_43 , V_111 ) ;
if ( ! V_140 || V_140 -> V_124 != V_125 ) {
F_5 ( & V_43 -> V_68 , V_6 ) ;
return - V_41 ;
}
V_338 = ( ! V_140 -> V_242 || V_140 -> V_78 > 1 ) ;
if ( ! V_239 ) {
V_140 -> V_124 = V_328 ;
V_140 -> V_78 -= ( V_140 -> V_242 > 0 ) ;
}
V_140 -> V_111 . V_239 = V_239 ;
if ( V_338 )
V_140 -> V_242 = F_98 ( V_239 ) ;
else
F_159 ( V_140 , V_239 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
return 0 ;
}
void F_167 ( struct V_33 * V_103 ,
struct V_110 * V_111 )
{
F_166 ( V_103 , V_111 , 0 ) ;
}
static void V_77 ( struct V_339 * V_340 )
{
struct V_42 * V_43 ;
struct V_145 * V_146 ;
struct V_42 * V_148 ;
unsigned long V_6 ;
int V_341 ;
struct V_121 V_122 ;
struct V_112 V_113 ;
bool V_154 ;
V_43 =
F_51 ( V_340 , struct V_42 , V_76 ) ;
V_154 = F_63 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_153 ( & V_43 -> V_75 ) ) {
V_146 = F_154 ( V_43 -> V_75 . V_196 ,
struct V_145 ,
V_175 ) ;
F_44 ( & V_146 -> V_175 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_341 = 0 ;
if ( V_146 -> V_147 ) {
T_1 V_166 ;
V_148 = V_146 -> V_148 ;
if ( ! V_148 ) {
F_67 ( & V_43 -> V_67 . V_3 -> V_52 ,
L_25 ) ;
V_341 = 1 ;
goto V_342;
}
F_56 ( V_148 -> V_67 . V_62 ,
V_146 -> V_140 -> V_151 . V_165 . V_123 ,
F_73 ( V_164 ) ,
V_146 -> V_140 -> V_151 . V_120 ,
V_148 -> V_67 . V_4 , & V_122 ) ;
V_146 -> V_147 -> V_256 . V_255 . V_122 = & V_122 ;
V_166 = ( (struct V_26 * ) ( V_146 -> V_147 -> V_143 ) ) -> V_166 ;
if ( V_154 && V_166 == V_167 ) {
V_146 -> V_147 -> V_256 . V_255 . V_317 = V_146 -> V_174 ;
V_146 -> V_147 -> V_256 . V_255 . V_318 = sizeof( struct V_202 ) ;
} else {
V_146 -> V_147 -> V_256 . V_255 . V_317 = sizeof( struct V_129 ) ;
V_146 -> V_147 -> V_256 . V_255 . V_318 = sizeof( struct V_129 ) ;
}
F_21 ( & V_146 -> V_147 -> V_256 . V_255 . V_72 ) ;
F_132 ( & V_146 -> V_147 -> V_256 . V_255 . V_254 . V_108 ,
& V_146 -> V_147 -> V_256 . V_255 . V_72 ) ;
V_146 -> V_147 -> V_256 . V_255 . V_254 . V_288 = NULL ;
V_146 -> V_147 -> V_256 . V_255 . V_254 . V_143 =
(struct V_129 * ) V_146 -> V_147 -> V_143 ;
if ( F_150 ( & V_148 -> V_61 -> V_98 ) )
F_55 ( V_148 -> V_61 ,
& V_146 -> V_147 -> V_256 . V_255 ,
V_88 ) ;
V_148 -> V_67 . V_36 (
& V_148 -> V_67 ,
& V_146 -> V_140 -> V_111 ,
& V_146 -> V_147 -> V_256 . V_255 ) ;
F_4 ( & V_148 -> V_68 , V_6 ) ;
F_49 ( & V_148 -> V_78 ) ;
F_5 ( & V_148 -> V_68 , V_6 ) ;
}
V_342:
V_113 . V_124 = V_125 ;
V_113 . V_292 = 0 ;
V_113 . V_111 = & V_146 -> V_140 -> V_111 ;
if ( F_150 ( & V_43 -> V_61 -> V_98 ) )
F_54 ( V_43 -> V_61 ,
& V_146 -> V_140 -> V_111 ,
& V_113 , V_87 ) ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_113 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_49 ( & V_43 -> V_78 ) ;
if ( V_341 )
F_29 ( V_146 -> V_147 ) ;
F_29 ( V_146 ) ;
}
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static int F_168 ( struct V_139 * V_140 )
{
int V_40 ;
if ( ! V_140 -> V_245 )
return - V_343 ;
V_140 -> V_245 -- ;
V_140 -> V_111 . V_244 ++ ;
V_140 -> V_242 = F_98 ( V_140 -> V_111 . V_239 ) ;
if ( F_84 ( & V_140 -> V_43 -> V_67 ) ) {
V_40 = F_169 ( V_140 ) ;
switch ( V_40 ) {
case V_323 :
V_40 = F_91 ( V_140 ) ;
break;
case V_246 :
V_40 = 0 ;
break;
default:
V_40 = - V_344 ;
break;
}
} else
V_40 = F_91 ( V_140 ) ;
if ( ! V_40 ) {
V_140 -> V_78 ++ ;
F_28 ( & V_140 -> V_85 ,
& V_140 -> V_43 -> V_69 ) ;
}
return V_40 ;
}
static void V_74 ( struct V_339 * V_340 )
{
struct V_42 * V_43 ;
struct V_139 * V_140 ;
struct V_112 V_113 ;
unsigned long V_6 , V_319 ;
V_43 = F_51 ( V_340 , struct V_42 ,
V_73 . V_340 ) ;
V_113 . V_292 = 0 ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_153 ( & V_43 -> V_70 ) ) {
V_140 = F_154 ( V_43 -> V_70 . V_196 ,
struct V_139 ,
V_85 ) ;
if ( F_155 ( V_140 -> V_242 , V_320 ) ) {
V_319 = V_140 -> V_242 - V_320 ;
if ( ( long ) V_319 <= 0 )
V_319 = 1 ;
F_170 ( V_43 -> V_61 ->
V_39 -> V_102 ,
& V_43 -> V_73 , V_319 ) ;
break;
}
F_44 ( & V_140 -> V_85 ) ;
if ( V_140 -> V_124 == V_125 &&
! F_168 ( V_140 ) )
continue;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_140 -> V_124 == V_125 )
V_113 . V_124 = V_345 ;
else
V_113 . V_124 = V_140 -> V_124 ;
V_113 . V_111 = & V_140 -> V_111 ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_113 ) ;
F_49 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
}
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static int F_151 ( struct V_89 * V_61 ,
struct V_135 * V_143 )
{
unsigned long V_6 ;
int V_346 , V_40 ;
struct V_135 * V_147 ;
struct V_228 V_203 ;
struct V_347 V_348 , * V_349 ;
struct V_106 * V_350 = & V_61 -> V_350 ;
V_203 . V_205 = V_61 -> V_39 -> V_206 -> V_207 ;
V_348 . V_196 = NULL ;
V_348 . V_203 = & V_203 ;
V_348 . V_210 = 1 ;
do {
if ( V_143 ) {
V_147 = V_143 ;
V_143 = NULL ;
} else {
V_147 = F_58 ( F_59 ( V_61 -> V_39 ) ,
V_96 ) ;
if ( ! V_147 ) {
V_40 = - V_65 ;
break;
}
}
V_203 . V_204 = F_61 ( V_147 ) ;
V_203 . V_231 = F_92 ( V_61 -> V_39 -> V_3 ,
& V_147 -> V_288 ,
F_61 ( V_147 ) ,
V_316 ) ;
if ( F_93 ( F_94 ( V_61 -> V_39 -> V_3 ,
V_203 . V_231 ) ) ) {
V_40 = - V_65 ;
break;
}
V_147 -> V_256 . V_315 = V_203 . V_231 ;
V_147 -> V_256 . V_105 . V_107 = V_350 ;
V_147 -> V_256 . V_105 . V_118 . V_208 = F_148 ;
V_348 . V_123 = & V_147 -> V_256 . V_105 . V_118 ;
F_4 ( & V_350 -> V_68 , V_6 ) ;
V_346 = ( ++ V_350 -> V_109 < V_350 -> V_235 ) ;
F_28 ( & V_147 -> V_256 . V_105 . V_108 , & V_350 -> V_108 ) ;
F_5 ( & V_350 -> V_68 , V_6 ) ;
V_40 = F_171 ( V_61 -> V_62 , & V_348 , & V_349 ) ;
if ( V_40 ) {
F_4 ( & V_350 -> V_68 , V_6 ) ;
F_44 ( & V_147 -> V_256 . V_105 . V_108 ) ;
V_350 -> V_109 -- ;
F_5 ( & V_350 -> V_68 , V_6 ) ;
F_95 ( V_61 -> V_39 -> V_3 ,
V_147 -> V_256 . V_315 ,
F_61 ( V_147 ) ,
V_316 ) ;
F_29 ( V_147 ) ;
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_26 , V_40 ) ;
break;
}
} while ( V_346 );
return V_40 ;
}
static void F_172 ( struct V_89 * V_61 )
{
struct V_250 * V_251 ;
struct V_135 * V_294 ;
struct V_104 * V_105 ;
if ( ! V_61 -> V_62 )
return;
while ( ! F_153 ( & V_61 -> V_350 . V_108 ) ) {
V_105 = F_154 ( V_61 -> V_350 . V_108 . V_196 ,
struct V_104 , V_108 ) ;
V_251 = F_51 ( V_105 ,
struct V_250 ,
V_105 ) ;
V_294 = F_51 ( V_251 , struct V_135 ,
V_256 ) ;
F_44 ( & V_105 -> V_108 ) ;
F_95 ( V_61 -> V_39 -> V_3 ,
V_294 -> V_256 . V_315 ,
F_61 ( V_294 ) ,
V_316 ) ;
F_29 ( V_294 ) ;
}
V_61 -> V_350 . V_109 = 0 ;
}
static int F_173 ( struct V_1 * V_39 )
{
int V_40 , V_23 ;
struct V_329 * V_277 ;
struct V_116 * V_62 ;
T_6 V_120 ;
V_277 = F_76 ( sizeof *V_277 , V_64 ) ;
if ( ! V_277 )
return - V_65 ;
V_40 = F_174 ( V_39 -> V_3 , V_39 -> V_4 ,
V_351 , & V_120 ) ;
if ( V_40 )
V_120 = 0 ;
for ( V_23 = 0 ; V_23 < V_352 ; V_23 ++ ) {
V_62 = V_39 -> V_61 [ V_23 ] . V_62 ;
if ( ! V_62 )
continue;
V_277 -> V_330 = V_353 ;
V_277 -> V_120 = V_120 ;
V_277 -> V_354 = ( V_62 -> V_269 == 0 ) ? 0 : V_355 ;
V_40 = F_164 ( V_62 , V_277 , V_334 |
V_356 | V_357 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_27 ,
V_23 , V_40 ) ;
goto V_97;
}
V_277 -> V_330 = V_358 ;
V_40 = F_164 ( V_62 , V_277 , V_334 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_28 ,
V_23 , V_40 ) ;
goto V_97;
}
V_277 -> V_330 = V_331 ;
V_277 -> V_359 = V_360 ;
V_40 = F_164 ( V_62 , V_277 , V_334 | V_361 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_29 ,
V_23 , V_40 ) ;
goto V_97;
}
}
V_40 = F_175 ( V_39 -> V_311 , V_362 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_30 ,
V_40 ) ;
goto V_97;
}
for ( V_23 = 0 ; V_23 < V_352 ; V_23 ++ ) {
if ( ! V_39 -> V_61 [ V_23 ] . V_62 )
continue;
V_40 = F_151 ( & V_39 -> V_61 [ V_23 ] , NULL ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_31 ) ;
goto V_97;
}
}
V_97:
F_29 ( V_277 ) ;
return V_40 ;
}
static void F_176 ( struct V_363 * V_364 , void * V_365 )
{
struct V_89 * V_61 = V_365 ;
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_32 ,
V_364 -> V_364 , V_61 -> V_62 -> V_269 ) ;
}
static void F_177 ( struct V_89 * V_61 ,
struct V_106 * V_107 )
{
V_107 -> V_61 = V_61 ;
V_107 -> V_109 = 0 ;
F_20 ( & V_107 -> V_68 ) ;
F_21 ( & V_107 -> V_108 ) ;
}
static void F_178 ( struct V_1 * V_39 ,
struct V_89 * V_61 )
{
V_61 -> V_39 = V_39 ;
F_177 ( V_61 , & V_61 -> V_230 ) ;
F_177 ( V_61 , & V_61 -> V_350 ) ;
F_21 ( & V_61 -> V_236 ) ;
F_20 ( & V_61 -> V_93 ) ;
V_61 -> V_95 = NULL ;
V_61 -> V_94 = 0 ;
F_24 ( & V_61 -> V_98 , 0 ) ;
}
static int F_179 ( struct V_89 * V_61 ,
enum V_10 V_11 )
{
struct V_366 V_367 ;
int V_40 ;
memset ( & V_367 , 0 , sizeof V_367 ) ;
V_367 . V_368 = V_61 -> V_39 -> V_311 ;
V_367 . V_369 = V_61 -> V_39 -> V_311 ;
V_367 . V_370 = V_371 ;
V_367 . V_372 . V_373 = V_374 ;
V_367 . V_372 . V_375 = V_376 ;
V_367 . V_372 . V_377 = V_378 ;
V_367 . V_372 . V_379 = V_380 ;
V_367 . V_11 = V_11 ;
V_367 . V_4 = V_61 -> V_39 -> V_4 ;
V_367 . V_365 = V_61 ;
V_367 . V_381 = F_176 ;
V_61 -> V_62 = F_180 ( V_61 -> V_39 -> V_206 , & V_367 ) ;
if ( F_181 ( V_61 -> V_62 ) ) {
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_33 ,
F_7 ( V_11 ) ) ;
V_40 = F_182 ( V_61 -> V_62 ) ;
goto error;
}
V_61 -> V_230 . V_235 = V_374 ;
V_61 -> V_350 . V_235 = V_376 ;
return 0 ;
error:
return V_40 ;
}
static void F_183 ( struct V_89 * V_61 )
{
if ( ! V_61 -> V_62 )
return;
F_184 ( V_61 -> V_62 ) ;
F_29 ( V_61 -> V_95 ) ;
}
static int F_185 ( struct V_2 * V_3 ,
int V_4 )
{
int V_40 , V_382 ;
struct V_1 * V_39 ;
unsigned long V_6 ;
char V_383 [ sizeof "ib_mad123"];
int V_384 ;
if ( F_186 ( F_60 ( V_3 , V_4 ) < V_385 ) )
return - V_386 ;
if ( F_186 ( F_63 ( V_3 , V_4 ) &&
F_60 ( V_3 , V_4 ) < V_387 ) )
return - V_386 ;
V_39 = F_18 ( sizeof *V_39 , V_64 ) ;
if ( ! V_39 )
return - V_65 ;
V_39 -> V_3 = V_3 ;
V_39 -> V_4 = V_4 ;
F_20 ( & V_39 -> V_80 ) ;
F_21 ( & V_39 -> V_85 ) ;
F_178 ( V_39 , & V_39 -> V_61 [ 0 ] ) ;
F_178 ( V_39 , & V_39 -> V_61 [ 1 ] ) ;
V_382 = V_374 + V_376 ;
V_384 = F_187 ( V_3 , V_4 ) ;
if ( V_384 )
V_382 *= 2 ;
V_39 -> V_311 = F_188 ( V_39 -> V_3 , V_39 , V_382 , 0 ,
V_388 ) ;
if ( F_181 ( V_39 -> V_311 ) ) {
F_67 ( & V_3 -> V_52 , L_34 ) ;
V_40 = F_182 ( V_39 -> V_311 ) ;
goto V_66;
}
V_39 -> V_206 = F_189 ( V_3 , 0 ) ;
if ( F_181 ( V_39 -> V_206 ) ) {
F_67 ( & V_3 -> V_52 , L_35 ) ;
V_40 = F_182 ( V_39 -> V_206 ) ;
goto V_84;
}
if ( V_384 ) {
V_40 = F_179 ( & V_39 -> V_61 [ 0 ] , V_12 ) ;
if ( V_40 )
goto V_389;
}
V_40 = F_179 ( & V_39 -> V_61 [ 1 ] , V_13 ) ;
if ( V_40 )
goto V_390;
snprintf ( V_383 , sizeof V_383 , L_36 , V_4 ) ;
V_39 -> V_102 = F_190 ( V_383 , V_391 ) ;
if ( ! V_39 -> V_102 ) {
V_40 = - V_65 ;
goto V_392;
}
F_4 ( & V_7 , V_6 ) ;
F_28 ( & V_39 -> V_314 , & V_393 ) ;
F_5 ( & V_7 , V_6 ) ;
V_40 = F_173 ( V_39 ) ;
if ( V_40 ) {
F_67 ( & V_3 -> V_52 , L_37 ) ;
goto V_394;
}
return 0 ;
V_394:
F_4 ( & V_7 , V_6 ) ;
F_191 ( & V_39 -> V_314 ) ;
F_5 ( & V_7 , V_6 ) ;
F_192 ( V_39 -> V_102 ) ;
V_392:
F_183 ( & V_39 -> V_61 [ 1 ] ) ;
V_390:
F_183 ( & V_39 -> V_61 [ 0 ] ) ;
V_389:
F_193 ( V_39 -> V_206 ) ;
V_84:
F_194 ( V_39 -> V_311 ) ;
F_172 ( & V_39 -> V_61 [ 1 ] ) ;
F_172 ( & V_39 -> V_61 [ 0 ] ) ;
V_66:
F_29 ( V_39 ) ;
return V_40 ;
}
static int F_195 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
V_39 = F_1 ( V_3 , V_4 ) ;
if ( V_39 == NULL ) {
F_5 ( & V_7 , V_6 ) ;
F_67 ( & V_3 -> V_52 , L_38 , V_4 ) ;
return - V_60 ;
}
F_191 ( & V_39 -> V_314 ) ;
F_5 ( & V_7 , V_6 ) ;
F_192 ( V_39 -> V_102 ) ;
F_183 ( & V_39 -> V_61 [ 1 ] ) ;
F_183 ( & V_39 -> V_61 [ 0 ] ) ;
F_193 ( V_39 -> V_206 ) ;
F_194 ( V_39 -> V_311 ) ;
F_172 ( & V_39 -> V_61 [ 1 ] ) ;
F_172 ( & V_39 -> V_61 [ 0 ] ) ;
F_29 ( V_39 ) ;
return 0 ;
}
static void F_196 ( struct V_2 * V_3 )
{
int V_395 , V_23 ;
V_395 = F_197 ( V_3 ) ;
for ( V_23 = V_395 ; V_23 <= F_198 ( V_3 ) ; V_23 ++ ) {
if ( ! F_199 ( V_3 , V_23 ) )
continue;
if ( F_185 ( V_3 , V_23 ) ) {
F_67 ( & V_3 -> V_52 , L_39 , V_23 ) ;
goto error;
}
if ( F_200 ( V_3 , V_23 ) ) {
F_67 ( & V_3 -> V_52 ,
L_40 , V_23 ) ;
goto V_396;
}
}
return;
V_396:
if ( F_195 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_41 , V_23 ) ;
error:
while ( -- V_23 >= V_395 ) {
if ( ! F_199 ( V_3 , V_23 ) )
continue;
if ( F_201 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 ,
L_42 , V_23 ) ;
if ( F_195 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_41 , V_23 ) ;
}
}
static void F_202 ( struct V_2 * V_3 , void * V_397 )
{
int V_23 ;
for ( V_23 = F_197 ( V_3 ) ; V_23 <= F_198 ( V_3 ) ; V_23 ++ ) {
if ( ! F_199 ( V_3 , V_23 ) )
continue;
if ( F_201 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 ,
L_42 , V_23 ) ;
if ( F_195 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_41 , V_23 ) ;
}
}
int F_203 ( void )
{
V_376 = F_204 ( V_376 , V_398 ) ;
V_376 = F_205 ( V_376 , V_399 ) ;
V_374 = F_204 ( V_374 , V_398 ) ;
V_374 = F_205 ( V_374 , V_399 ) ;
F_21 ( & V_393 ) ;
if ( F_206 ( & V_400 ) ) {
F_105 ( L_43 ) ;
return - V_41 ;
}
return 0 ;
}
void F_207 ( void )
{
F_208 ( & V_400 ) ;
}
