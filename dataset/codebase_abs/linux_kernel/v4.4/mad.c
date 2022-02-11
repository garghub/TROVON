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
F_16 ( & V_3 -> V_52 , L_11 ) ;
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
int F_50 ( struct V_33 * V_103 )
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
return 0 ;
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
V_91 -> V_67 . V_36 ( & V_91 -> V_67 ,
V_115 ) ;
F_39 ( V_91 ) ;
F_4 ( & V_61 -> V_93 , V_6 ) ;
}
F_5 ( & V_61 -> V_93 , V_6 ) ;
}
static void F_56 ( struct V_116 * V_62 ,
T_6 V_117 , T_7 V_118 , T_7 V_119 , T_1 V_4 ,
struct V_120 * V_121 )
{
memset ( V_121 , 0 , sizeof *V_121 ) ;
V_121 -> V_117 = V_117 ;
V_121 -> V_122 = V_123 ;
V_121 -> V_124 = V_125 ;
V_121 -> V_119 = V_119 ;
V_121 -> V_126 = sizeof( struct V_127 ) + sizeof( struct V_128 ) ;
V_121 -> V_129 = V_130 ;
V_121 -> V_62 = V_62 ;
V_121 -> V_118 = V_118 ;
V_121 -> V_131 = 0 ;
V_121 -> V_132 = 0 ;
V_121 -> V_4 = V_4 ;
}
static T_8 F_57 ( const struct V_133 * V_134 )
{
return sizeof( struct V_133 ) + V_134 -> V_135 ;
}
static struct V_133 * F_58 ( T_8 V_135 , T_9 V_6 )
{
T_8 V_136 = sizeof( struct V_133 ) + V_135 ;
struct V_133 * V_40 = F_18 ( V_136 , V_6 ) ;
if ( V_40 )
V_40 -> V_135 = V_135 ;
return V_40 ;
}
static T_8 F_59 ( const struct V_1 * V_39 )
{
return F_60 ( V_39 -> V_3 , V_39 -> V_4 ) ;
}
static T_8 F_61 ( const struct V_133 * V_134 )
{
return sizeof( struct V_128 ) + V_134 -> V_135 ;
}
static int F_62 ( struct V_42 * V_43 ,
struct V_137 * V_138 )
{
int V_40 = 0 ;
struct V_139 * V_140 = V_138 -> V_111 . V_141 ;
struct V_142 * V_142 = (struct V_142 * ) V_140 ;
unsigned long V_6 ;
struct V_143 * V_144 ;
struct V_133 * V_145 ;
struct V_1 * V_39 ;
struct V_42 * V_146 = NULL ;
struct V_2 * V_3 = V_43 -> V_67 . V_3 ;
T_1 V_4 ;
struct V_120 V_147 ;
struct V_148 * V_149 = & V_138 -> V_149 ;
T_8 V_135 = F_59 ( V_43 -> V_61 -> V_39 ) ;
T_7 V_150 = 0 ;
T_7 V_151 ;
bool V_152 = F_63 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
if ( F_64 ( V_3 ) &&
V_140 -> V_8 == V_9 )
V_4 = V_149 -> V_4 ;
else
V_4 = V_43 -> V_67 . V_4 ;
if ( V_152 && V_140 -> V_153 == V_154 ) {
T_4 V_155 ;
if ( ( F_65 ( V_142 )
? V_142 -> V_156 . V_157 . V_158 : V_142 -> V_156 . V_157 . V_159 ) ==
V_160 &&
F_66 ( V_142 ,
F_64 ( V_3 ) ,
V_4 ) == V_161 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_13 ) ;
goto V_97;
}
V_155 = F_68 ( V_142 -> V_156 . V_157 . V_159 ) ;
if ( V_155 != F_68 ( V_160 ) &&
V_155 & 0xffff0000 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_14 ,
V_155 ) ;
goto V_97;
}
V_151 = ( T_7 ) ( V_155 & 0x0000ffff ) ;
if ( F_69 ( V_142 , V_3 ) == V_161 &&
F_70 ( V_142 , V_3 ) == V_161 )
goto V_97;
} else {
if ( ( F_71 ( V_140 ) ? V_140 -> V_158 : V_140 -> V_159 ) ==
V_162 &&
F_72 ( V_140 , F_64 ( V_3 ) , V_4 ) ==
V_161 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_15 ) ;
goto V_97;
}
V_151 = F_73 ( V_140 -> V_159 ) ;
if ( F_74 ( V_140 , V_3 ) == V_161 &&
F_75 ( V_140 , V_3 ) == V_161 )
goto V_97;
}
V_144 = F_76 ( sizeof *V_144 , V_96 ) ;
if ( ! V_144 ) {
V_40 = - V_65 ;
F_67 ( & V_3 -> V_52 , L_16 ) ;
goto V_97;
}
V_144 -> V_145 = NULL ;
V_144 -> V_146 = NULL ;
V_145 = F_58 ( V_135 , V_96 ) ;
if ( ! V_145 ) {
V_40 = - V_65 ;
F_67 ( & V_3 -> V_52 , L_17 ) ;
F_29 ( V_144 ) ;
goto V_97;
}
F_56 ( V_43 -> V_67 . V_62 ,
V_149 -> V_163 . V_117 , V_151 ,
V_149 -> V_119 ,
V_149 -> V_4 , & V_147 ) ;
if ( V_152 && V_140 -> V_164 == V_165 ) {
V_147 . V_126 = V_138 -> V_111 . V_166
+ V_138 -> V_111 . V_167
+ sizeof( struct V_128 ) ;
}
V_40 = V_3 -> V_168 ( V_3 , 0 , V_4 , & V_147 , NULL ,
( const struct V_26 * ) V_140 , V_135 ,
(struct V_26 * ) V_145 -> V_141 ,
& V_135 , & V_150 ) ;
switch ( V_40 )
{
case V_169 | V_170 :
if ( F_13 ( ( const struct V_26 * ) V_145 -> V_141 ) &&
V_43 -> V_67 . V_36 ) {
V_144 -> V_145 = V_145 ;
V_144 -> V_146 = V_43 ;
F_34 ( & V_43 -> V_78 ) ;
} else
F_29 ( V_145 ) ;
break;
case V_169 | V_171 :
F_29 ( V_145 ) ;
break;
case V_169 :
V_39 = F_3 ( V_43 -> V_67 . V_3 ,
V_43 -> V_67 . V_4 ) ;
if ( V_39 ) {
memcpy ( V_145 -> V_141 , V_140 , V_145 -> V_135 ) ;
V_146 = F_77 ( V_39 ,
( const struct V_26 * ) V_145 -> V_141 ) ;
}
if ( ! V_39 || ! V_146 ) {
F_29 ( V_145 ) ;
break;
}
V_144 -> V_145 = V_145 ;
V_144 -> V_146 = V_146 ;
break;
default:
F_29 ( V_145 ) ;
F_29 ( V_144 ) ;
V_40 = - V_41 ;
goto V_97;
}
V_144 -> V_138 = V_138 ;
if ( V_152 ) {
V_144 -> V_138 -> V_149 . V_119 = V_150 ;
V_144 -> V_172 = V_135 ;
}
F_34 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_28 ( & V_144 -> V_173 , & V_43 -> V_75 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
F_78 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_76 ) ;
V_40 = 1 ;
V_97:
return V_40 ;
}
static int F_79 ( int V_166 , int V_167 , T_8 V_135 )
{
int V_174 , V_175 ;
V_174 = V_135 - V_166 ;
if ( V_167 && V_174 ) {
V_175 = V_174 - V_167 % V_174 ;
return V_175 == V_174 ? 0 : V_175 ;
} else
return V_174 ;
}
static void F_80 ( struct V_137 * V_138 )
{
struct V_176 * V_177 , * V_178 ;
F_81 (s, t, &mad_send_wr->rmpp_list, list) {
F_44 ( & V_177 -> V_108 ) ;
F_29 ( V_177 ) ;
}
}
static int F_82 ( struct V_137 * V_149 ,
T_8 V_135 , T_9 V_179 )
{
struct V_110 * V_111 = & V_149 -> V_111 ;
struct V_180 * V_181 = V_111 -> V_141 ;
struct V_176 * V_182 = NULL ;
int V_183 , V_174 , V_175 ;
V_111 -> V_174 = V_135 - V_111 -> V_166 ;
V_111 -> V_184 = V_135 - V_185 ;
V_174 = V_111 -> V_174 ;
V_175 = V_149 -> V_175 ;
for ( V_183 = V_111 -> V_167 + V_175 ; V_183 > 0 ; V_183 -= V_174 ) {
V_182 = F_76 ( sizeof ( * V_182 ) + V_174 , V_179 ) ;
if ( ! V_182 ) {
F_67 ( & V_111 -> V_103 -> V_3 -> V_52 ,
L_18 ,
sizeof ( * V_182 ) + V_174 , V_179 ) ;
F_80 ( V_149 ) ;
return - V_65 ;
}
V_182 -> V_186 = ++ V_111 -> V_187 ;
F_28 ( & V_182 -> V_108 , & V_149 -> V_72 ) ;
}
if ( V_175 )
memset ( V_182 -> V_188 + V_174 - V_175 , 0 , V_175 ) ;
V_181 -> V_189 . V_34 = V_149 -> V_43 ->
V_67 . V_34 ;
V_181 -> V_189 . V_190 = V_191 ;
F_83 ( & V_181 -> V_189 , V_192 ) ;
V_149 -> V_193 = F_51 ( V_149 -> V_72 . V_194 ,
struct V_176 , V_108 ) ;
V_149 -> V_195 = V_149 -> V_193 ;
return 0 ;
}
int F_84 ( const struct V_33 * V_67 )
{
return V_67 -> V_34 && ! ( V_67 -> V_6 & V_59 ) ;
}
struct V_110 * F_85 ( struct V_33 * V_103 ,
T_4 V_196 , T_7 V_119 ,
int V_197 ,
int V_166 , int V_167 ,
T_9 V_179 ,
T_1 V_164 )
{
struct V_42 * V_43 ;
struct V_137 * V_138 ;
int V_175 , V_198 , V_40 , V_136 ;
void * V_199 ;
T_8 V_135 ;
bool V_152 ;
V_43 = F_51 ( V_103 , struct V_42 ,
V_67 ) ;
V_152 = F_63 ( V_103 -> V_3 , V_103 -> V_4 ) ;
if ( V_152 && V_164 == V_165 )
V_135 = sizeof( struct V_200 ) ;
else
V_135 = sizeof( struct V_127 ) ;
V_175 = F_79 ( V_166 , V_167 , V_135 ) ;
V_198 = V_166 + V_167 + V_175 ;
if ( F_84 ( V_103 ) ) {
if ( ! V_197 && V_198 > V_135 )
return F_15 ( - V_41 ) ;
} else
if ( V_197 || V_198 > V_135 )
return F_15 ( - V_41 ) ;
V_136 = V_197 ? V_166 : V_135 ;
V_199 = F_18 ( sizeof *V_138 + V_136 , V_179 ) ;
if ( ! V_199 )
return F_15 ( - V_65 ) ;
V_138 = V_199 + V_136 ;
F_21 ( & V_138 -> V_72 ) ;
V_138 -> V_111 . V_141 = V_199 ;
V_138 -> V_111 . V_166 = V_166 ;
V_138 -> V_111 . V_167 = V_167 ;
V_138 -> V_175 = V_175 ;
V_138 -> V_43 = V_43 ;
V_138 -> V_201 [ 0 ] . V_202 = V_166 ;
V_138 -> V_201 [ 0 ] . V_203 = V_103 -> V_62 -> V_204 -> V_205 ;
if ( V_152 && V_164 == V_165 &&
V_167 < V_135 - V_166 )
V_138 -> V_201 [ 1 ] . V_202 = V_167 ;
else
V_138 -> V_201 [ 1 ] . V_202 = V_135 - V_166 ;
V_138 -> V_201 [ 1 ] . V_203 = V_103 -> V_62 -> V_204 -> V_205 ;
V_138 -> V_149 . V_163 . V_117 = ( unsigned long ) V_138 ;
V_138 -> V_149 . V_163 . V_201 = V_138 -> V_201 ;
V_138 -> V_149 . V_163 . V_206 = 2 ;
V_138 -> V_149 . V_163 . V_124 = V_207 ;
V_138 -> V_149 . V_163 . V_208 = V_209 ;
V_138 -> V_149 . V_196 = V_196 ;
V_138 -> V_149 . V_210 = V_211 ;
V_138 -> V_149 . V_119 = V_119 ;
if ( V_197 ) {
V_40 = F_82 ( V_138 , V_135 , V_179 ) ;
if ( V_40 ) {
F_29 ( V_199 ) ;
return F_15 ( V_40 ) ;
}
}
V_138 -> V_111 . V_103 = V_103 ;
F_34 ( & V_43 -> V_78 ) ;
return & V_138 -> V_111 ;
}
int F_86 ( T_1 V_8 )
{
if ( V_8 == V_212 )
return V_213 ;
else if ( ( V_8 == V_214 ) ||
( V_8 == V_215 ) ||
( V_8 == V_216 ) )
return V_217 ;
else if ( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) )
return V_218 ;
else
return V_219 ;
}
int F_17 ( T_1 V_8 )
{
if ( ( V_8 == V_212 ) ||
( V_8 == V_214 ) ||
( V_8 == V_215 ) ||
( V_8 == V_216 ) ||
( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) ) )
return 1 ;
return 0 ;
}
void * F_87 ( struct V_110 * V_111 , int V_220 )
{
struct V_137 * V_138 ;
struct V_221 * V_108 ;
V_138 = F_51 ( V_111 , struct V_137 ,
V_111 ) ;
V_108 = & V_138 -> V_193 -> V_108 ;
if ( V_138 -> V_193 -> V_186 < V_220 ) {
F_2 (mad_send_wr->cur_seg, list, list)
if ( V_138 -> V_193 -> V_186 == V_220 )
break;
} else if ( V_138 -> V_193 -> V_186 > V_220 ) {
F_88 (mad_send_wr->cur_seg, list, list)
if ( V_138 -> V_193 -> V_186 == V_220 )
break;
}
return V_138 -> V_193 -> V_188 ;
}
static inline void * F_89 ( struct V_137 * V_138 )
{
if ( V_138 -> V_111 . V_187 )
return F_87 ( & V_138 -> V_111 ,
V_138 -> V_220 ) ;
else
return V_138 -> V_111 . V_141 +
V_138 -> V_111 . V_166 ;
}
void F_90 ( struct V_110 * V_111 )
{
struct V_42 * V_43 ;
struct V_137 * V_138 ;
V_43 = F_51 ( V_111 -> V_103 ,
struct V_42 , V_67 ) ;
V_138 = F_51 ( V_111 , struct V_137 ,
V_111 ) ;
F_80 ( V_138 ) ;
F_29 ( V_111 -> V_141 ) ;
F_36 ( V_43 ) ;
}
int F_91 ( struct V_137 * V_138 )
{
struct V_89 * V_61 ;
struct V_221 * V_108 ;
struct V_222 * V_223 ;
struct V_33 * V_103 ;
struct V_224 * V_225 ;
unsigned long V_6 ;
int V_40 ;
V_61 = V_138 -> V_43 -> V_61 ;
V_138 -> V_149 . V_163 . V_117 = ( unsigned long ) & V_138 -> V_105 ;
V_138 -> V_105 . V_107 = & V_61 -> V_226 ;
V_103 = V_138 -> V_111 . V_103 ;
V_225 = V_138 -> V_201 ;
V_225 [ 0 ] . V_227 = F_92 ( V_103 -> V_3 ,
V_138 -> V_111 . V_141 ,
V_225 [ 0 ] . V_202 ,
V_228 ) ;
if ( F_93 ( F_94 ( V_103 -> V_3 , V_225 [ 0 ] . V_227 ) ) )
return - V_65 ;
V_138 -> V_229 = V_225 [ 0 ] . V_227 ;
V_225 [ 1 ] . V_227 = F_92 ( V_103 -> V_3 ,
F_89 ( V_138 ) ,
V_225 [ 1 ] . V_202 ,
V_228 ) ;
if ( F_93 ( F_94 ( V_103 -> V_3 , V_225 [ 1 ] . V_227 ) ) ) {
F_95 ( V_103 -> V_3 ,
V_138 -> V_229 ,
V_225 [ 0 ] . V_202 , V_228 ) ;
return - V_65 ;
}
V_138 -> V_230 = V_225 [ 1 ] . V_227 ;
F_4 ( & V_61 -> V_226 . V_68 , V_6 ) ;
if ( V_61 -> V_226 . V_109 < V_61 -> V_226 . V_231 ) {
V_40 = F_96 ( V_103 -> V_62 , & V_138 -> V_149 . V_163 ,
& V_223 ) ;
V_108 = & V_61 -> V_226 . V_108 ;
} else {
V_40 = 0 ;
V_108 = & V_61 -> V_232 ;
}
if ( ! V_40 ) {
V_61 -> V_226 . V_109 ++ ;
F_28 ( & V_138 -> V_105 . V_108 , V_108 ) ;
}
F_5 ( & V_61 -> V_226 . V_68 , V_6 ) ;
if ( V_40 ) {
F_95 ( V_103 -> V_3 ,
V_138 -> V_229 ,
V_225 [ 0 ] . V_202 , V_228 ) ;
F_95 ( V_103 -> V_3 ,
V_138 -> V_230 ,
V_225 [ 1 ] . V_202 , V_228 ) ;
}
return V_40 ;
}
int F_97 ( struct V_110 * V_111 ,
struct V_110 * * V_233 )
{
struct V_42 * V_43 ;
struct V_110 * V_234 ;
struct V_137 * V_138 ;
unsigned long V_6 ;
int V_40 = - V_41 ;
for (; V_111 ; V_111 = V_234 ) {
V_138 = F_51 ( V_111 ,
struct V_137 ,
V_111 ) ;
V_43 = V_138 -> V_43 ;
if ( ! V_111 -> V_103 -> V_35 ||
( V_111 -> V_235 &&
! V_111 -> V_103 -> V_36 ) ) {
V_40 = - V_41 ;
goto error;
}
if ( ! F_17 ( ( (struct V_26 * ) V_111 -> V_141 ) -> V_8 ) ) {
if ( V_43 -> V_67 . V_34 ) {
V_40 = - V_41 ;
goto error;
}
}
V_234 = V_111 -> V_194 ;
V_138 -> V_149 . V_236 = V_111 -> V_236 ;
if ( ( (struct V_26 * ) V_111 -> V_141 ) -> V_8 ==
V_9 ) {
V_40 = F_62 ( V_43 ,
V_138 ) ;
if ( V_40 < 0 )
goto error;
else if ( V_40 == 1 )
continue;
}
V_138 -> V_237 = ( (struct V_26 * ) V_111 -> V_141 ) -> V_237 ;
V_138 -> V_238 = F_98 ( V_111 -> V_235 ) ;
V_138 -> V_239 = V_111 -> V_240 ;
V_138 -> V_241 = V_111 -> V_240 ;
V_111 -> V_240 = 0 ;
V_138 -> V_78 = 1 + ( V_138 -> V_238 > 0 ) ;
V_138 -> V_122 = V_123 ;
F_34 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_28 ( & V_138 -> V_85 ,
& V_43 -> V_69 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( F_84 ( & V_43 -> V_67 ) ) {
V_40 = F_99 ( V_138 ) ;
if ( V_40 >= 0 && V_40 != V_242 )
V_40 = F_91 ( V_138 ) ;
} else
V_40 = F_91 ( V_138 ) ;
if ( V_40 < 0 ) {
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_44 ( & V_138 -> V_85 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
F_49 ( & V_43 -> V_78 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_233 )
* V_233 = V_111 ;
return V_40 ;
}
void F_100 ( struct V_114 * V_115 )
{
struct V_243 * V_244 , * V_245 ;
struct V_246 * V_247 ;
struct V_133 * V_248 ;
struct V_221 V_249 ;
F_21 ( & V_249 ) ;
F_101 ( & V_115 -> V_72 , & V_249 ) ;
F_81 (mad_recv_buf, temp_recv_buf,
&free_list, list) {
V_115 = F_51 ( V_244 , struct V_114 ,
V_250 ) ;
V_247 = F_51 ( V_115 ,
struct V_246 ,
V_251 ) ;
V_248 = F_51 ( V_247 , struct V_133 ,
V_252 ) ;
F_29 ( V_248 ) ;
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
struct V_120 * V_121 )
{
F_67 ( & V_103 -> V_3 -> V_52 ,
L_19 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * * V_22 ,
struct V_19 * V_20 )
{
int V_23 ;
F_104 (i, mad_reg_req->method_mask, IB_MGMT_MAX_METHODS) {
if ( ( * V_22 ) -> V_67 [ V_23 ] ) {
F_105 ( L_20 , V_23 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_106 ( struct V_21 * * V_22 )
{
* V_22 = F_18 ( sizeof ** V_22 , V_96 ) ;
if ( ! * V_22 ) {
F_105 ( L_21 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_107 ( struct V_21 * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_253 ; V_23 ++ )
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
for ( V_23 = 0 ; V_23 < V_254 ; V_23 ++ )
if ( V_48 -> V_18 [ V_23 ] )
return 1 ;
return 0 ;
}
static void F_112 ( struct V_21 * V_22 ,
struct V_42 * V_67 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_253 ; V_23 ++ ) {
if ( V_22 -> V_67 [ V_23 ] == V_67 ) {
V_22 -> V_67 [ V_23 ] = NULL ;
}
}
}
static int F_26 ( struct V_19 * V_20 ,
struct V_42 * V_255 ,
T_1 V_8 )
{
struct V_1 * V_39 ;
struct V_45 * * V_46 ;
struct V_21 * * V_22 ;
int V_23 , V_40 ;
V_39 = V_255 -> V_61 -> V_39 ;
V_46 = & V_39 -> V_83 [ V_20 -> V_55 ] . V_46 ;
if ( ! * V_46 ) {
* V_46 = F_18 ( sizeof ** V_46 , V_96 ) ;
if ( ! * V_46 ) {
F_67 ( & V_255 -> V_67 . V_3 -> V_52 ,
L_22 ) ;
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
F_104 ( V_23 , V_20 -> V_256 , V_253 )
( * V_22 ) -> V_67 [ V_23 ] = V_255 ;
return 0 ;
V_66:
F_112 ( * V_22 , V_255 ) ;
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
struct V_42 * V_255 )
{
struct V_1 * V_39 ;
struct V_47 * * V_257 ;
struct V_47 * V_48 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_21 * * V_22 ;
int V_23 , V_40 = - V_65 ;
T_1 V_51 ;
V_51 = F_8 ( V_20 -> V_8 ) ;
V_39 = V_255 -> V_61 -> V_39 ;
V_257 = & V_39 -> V_83 [
V_20 -> V_55 ] . V_48 ;
if ( ! * V_257 ) {
V_48 = F_18 ( sizeof *V_48 , V_96 ) ;
if ( ! V_48 ) {
F_67 ( & V_255 -> V_67 . V_3 -> V_52 ,
L_23 ) ;
goto V_53;
}
* V_257 = V_48 ;
}
if ( ! ( * V_257 ) -> V_18 [ V_51 ] ) {
V_18 = F_18 ( sizeof *V_18 , V_96 ) ;
if ( ! V_18 ) {
F_67 ( & V_255 -> V_67 . V_3 -> V_52 ,
L_24 ) ;
goto V_101;
}
( * V_257 ) -> V_18 [ V_51 ] = V_18 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( ( * V_257 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ) {
V_22 = & ( * V_257 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_53 ( ! * V_22 ) ;
goto V_258;
}
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! F_10 ( ( * V_257 ) -> V_18 [
V_51 ] -> V_16 [ V_23 ] ) ) {
V_22 = & ( * V_257 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_53 ( * V_22 ) ;
if ( ( V_40 = F_106 ( V_22 ) ) )
goto V_66;
memcpy ( ( * V_257 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ;
goto V_258;
}
}
F_67 ( & V_255 -> V_67 . V_3 -> V_52 , L_25 ) ;
goto V_66;
V_258:
if ( F_12 ( V_22 , V_20 ) )
goto V_84;
F_104 ( V_23 , V_20 -> V_256 , V_253 )
( * V_22 ) -> V_67 [ V_23 ] = V_255 ;
return 0 ;
V_84:
F_112 ( * V_22 , V_255 ) ;
if ( ! F_107 ( * V_22 ) ) {
F_29 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
V_66:
if ( V_18 ) {
( * V_257 ) -> V_18 [ V_51 ] = NULL ;
F_29 ( V_18 ) ;
}
V_101:
if ( V_48 ) {
* V_257 = NULL ;
F_29 ( V_48 ) ;
}
V_53:
return V_40 ;
}
static void F_43 ( struct V_42 * V_255 )
{
struct V_1 * V_39 ;
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
int V_259 ;
T_1 V_8 ;
if ( ! V_255 -> V_44 ) {
goto V_97;
}
V_39 = V_255 -> V_61 -> V_39 ;
V_8 = F_6 ( V_255 -> V_44 -> V_8 ) ;
V_46 = V_39 -> V_83 [
V_255 -> V_44 -> V_55 ] . V_46 ;
if ( ! V_46 )
goto V_260;
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
F_112 ( V_22 , V_255 ) ;
if ( ! F_107 ( V_22 ) ) {
F_29 ( V_22 ) ;
V_46 -> V_25 [ V_8 ] = NULL ;
if ( ! F_108 ( V_46 ) ) {
F_29 ( V_46 ) ;
V_39 -> V_83 [
V_255 -> V_44 ->
V_55 ] . V_46 = NULL ;
}
}
}
V_260:
if ( ! F_9 ( V_8 ) )
goto V_97;
V_8 = F_8 ( V_255 -> V_44 -> V_8 ) ;
V_48 = V_39 -> V_83 [
V_255 -> V_44 -> V_55 ] . V_48 ;
if ( ! V_48 )
goto V_97;
V_18 = V_48 -> V_18 [ V_8 ] ;
if ( V_18 ) {
V_259 = F_110 ( V_18 , V_255 -> V_44 -> V_16 ) ;
if ( V_259 < 0 )
goto V_97;
V_22 = V_18 -> V_25 [ V_259 ] ;
if ( V_22 ) {
F_112 ( V_22 , V_255 ) ;
if ( ! F_107 ( V_22 ) ) {
F_29 ( V_22 ) ;
V_18 -> V_25 [ V_259 ] = NULL ;
memset ( V_18 -> V_16 [ V_259 ] , 0 , 3 ) ;
if ( ! F_109 ( V_18 ) ) {
F_29 ( V_18 ) ;
V_48 -> V_18 [ V_8 ] = NULL ;
if ( ! F_111 ( V_48 ) ) {
F_29 ( V_48 ) ;
V_39 -> V_83 [
V_255 -> V_44 ->
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
const struct V_26 * V_261 )
{
struct V_42 * V_103 = NULL ;
unsigned long V_6 ;
F_4 ( & V_39 -> V_80 , V_6 ) ;
if ( F_13 ( V_261 ) ) {
T_4 V_81 ;
struct V_42 * V_5 ;
V_81 = F_113 ( V_261 -> V_237 ) >> 32 ;
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
const struct V_262 * V_263 ;
int V_259 ;
if ( V_261 -> V_153 >= V_56 )
goto V_97;
if ( ! F_9 ( V_261 -> V_8 ) ) {
V_46 = V_39 -> V_83 [
V_261 -> V_153 ] . V_46 ;
if ( ! V_46 )
goto V_97;
if ( F_6 ( V_261 -> V_8 ) >=
V_253 )
goto V_97;
V_22 = V_46 -> V_25 [ F_6 (
V_261 -> V_8 ) ] ;
if ( V_22 )
V_103 = V_22 -> V_67 [ V_261 -> V_22 &
~ V_28 ] ;
} else {
V_48 = V_39 -> V_83 [
V_261 -> V_153 ] . V_48 ;
if ( ! V_48 )
goto V_97;
V_18 = V_48 -> V_18 [ F_8 (
V_261 -> V_8 ) ] ;
if ( ! V_18 )
goto V_97;
V_263 = ( const struct V_262 * ) V_261 ;
V_259 = F_110 ( V_18 , V_263 -> V_16 ) ;
if ( V_259 == - 1 )
goto V_97;
V_22 = V_18 -> V_25 [ V_259 ] ;
if ( V_22 ) {
V_103 = V_22 -> V_67 [ V_261 -> V_22 &
~ V_28 ] ;
}
}
}
if ( V_103 ) {
if ( V_103 -> V_67 . V_36 )
F_34 ( & V_103 -> V_78 ) ;
else {
F_16 ( & V_39 -> V_3 -> V_52 ,
L_26 ,
& V_103 -> V_67 , V_39 -> V_4 ) ;
V_103 = NULL ;
}
}
V_97:
F_5 ( & V_39 -> V_80 , V_6 ) ;
return V_103 ;
}
static int F_114 ( const struct V_26 * V_261 ,
const struct V_89 * V_61 ,
bool V_152 )
{
int V_264 = 0 ;
T_4 V_265 = V_61 -> V_62 -> V_265 ;
if ( V_261 -> V_164 != V_266 &&
( ! V_152 || V_261 -> V_164 != V_165 ) ) {
F_105 ( L_27 ,
V_261 -> V_164 , V_152 ? L_28 : L_29 ) ;
goto V_97;
}
if ( ( V_261 -> V_8 == V_58 ) ||
( V_261 -> V_8 == V_9 ) ) {
if ( V_265 == 0 )
V_264 = 1 ;
} else {
if ( ( V_261 -> V_8 == V_267 ) &&
( V_261 -> V_268 != V_269 ) &&
( V_261 -> V_22 != V_270 ) )
goto V_97;
if ( V_265 != 0 )
V_264 = 1 ;
}
V_97:
return V_264 ;
}
static int F_115 ( const struct V_42 * V_43 ,
const struct V_26 * V_261 )
{
struct V_180 * V_181 ;
V_181 = (struct V_180 * ) V_261 ;
return ! V_43 -> V_67 . V_34 ||
! F_84 ( & V_43 -> V_67 ) ||
! ( F_116 ( & V_181 -> V_189 ) &
V_192 ) ||
( V_181 -> V_189 . V_190 == V_191 ) ;
}
static inline int F_117 ( const struct V_137 * V_163 ,
const struct V_114 * V_271 )
{
return ( (struct V_26 * ) ( V_163 -> V_111 . V_141 ) ) -> V_8 ==
V_271 -> V_250 . V_141 -> V_261 . V_8 ;
}
static inline int F_118 ( const struct V_42 * V_43 ,
const struct V_137 * V_163 ,
const struct V_114 * V_271 )
{
struct V_272 V_273 ;
T_1 V_274 , V_275 ;
union V_276 V_277 ;
struct V_2 * V_3 = V_43 -> V_67 . V_3 ;
T_1 V_4 = V_43 -> V_67 . V_4 ;
T_1 V_278 ;
V_274 = F_13 ( (struct V_26 * ) V_163 -> V_111 . V_141 ) ;
V_275 = F_13 ( & V_271 -> V_250 . V_141 -> V_261 ) ;
if ( V_274 == V_275 )
return 0 ;
if ( F_119 ( V_163 -> V_111 . V_236 , & V_273 ) )
return 0 ;
if ( ! ! ( V_273 . V_279 & V_280 ) !=
! ! ( V_271 -> V_121 -> V_281 & V_282 ) )
return 0 ;
if ( ! V_274 && V_275 ) {
if ( ! ( V_273 . V_279 & V_280 ) ) {
if ( F_120 ( V_3 , V_4 , & V_278 ) )
return 0 ;
return ( ! V_278 || ! ( ( V_273 . V_283 ^
V_271 -> V_121 -> V_132 ) &
( ( 1 << V_278 ) - 1 ) ) ) ;
} else {
if ( F_121 ( V_3 , V_4 ,
V_273 . V_284 . V_285 , & V_277 , NULL ) )
return 0 ;
return ! memcmp ( V_277 . V_286 , V_271 -> V_250 . V_284 -> V_287 . V_286 ,
16 ) ;
}
}
if ( ! ( V_273 . V_279 & V_280 ) )
return V_273 . V_288 == V_271 -> V_121 -> V_118 ;
else
return ! memcmp ( V_273 . V_284 . V_287 . V_286 , V_271 -> V_250 . V_284 -> V_277 . V_286 ,
16 ) ;
}
static inline int F_122 ( T_1 V_46 )
{
return ( V_46 == V_9 ) ;
}
struct V_137 *
F_123 ( const struct V_42 * V_43 ,
const struct V_114 * V_121 )
{
struct V_137 * V_163 ;
const struct V_26 * V_261 ;
V_261 = & V_121 -> V_250 . V_141 -> V_261 ;
F_2 (wr, &mad_agent_priv->wait_list, agent_list) {
if ( ( V_163 -> V_237 == V_261 -> V_237 ) &&
F_117 ( V_163 , V_121 ) &&
( F_122 ( V_261 -> V_8 ) ||
F_118 ( V_43 , V_163 , V_121 ) ) )
return ( V_163 -> V_122 == V_123 ) ? V_163 : NULL ;
}
F_2 (wr, &mad_agent_priv->send_list, agent_list) {
if ( F_115 ( V_43 , V_163 -> V_111 . V_141 ) &&
V_163 -> V_237 == V_261 -> V_237 &&
V_163 -> V_238 &&
F_117 ( V_163 , V_121 ) &&
( F_122 ( V_261 -> V_8 ) ||
F_118 ( V_43 , V_163 , V_121 ) ) )
return ( V_163 -> V_122 == V_123 ) ? V_163 : NULL ;
}
return NULL ;
}
void F_124 ( struct V_137 * V_138 )
{
V_138 -> V_238 = 0 ;
if ( V_138 -> V_78 == 1 )
F_125 ( & V_138 -> V_85 ,
& V_138 -> V_43 -> V_71 ) ;
}
static void F_126 ( struct V_42 * V_43 ,
struct V_114 * V_115 )
{
struct V_137 * V_138 ;
struct V_112 V_113 ;
unsigned long V_6 ;
F_21 ( & V_115 -> V_72 ) ;
F_127 ( & V_115 -> V_250 . V_108 , & V_115 -> V_72 ) ;
if ( F_84 ( & V_43 -> V_67 ) ) {
V_115 = F_128 ( V_43 ,
V_115 ) ;
if ( ! V_115 ) {
F_36 ( V_43 ) ;
return;
}
}
if ( F_13 ( & V_115 -> V_250 . V_141 -> V_261 ) ) {
F_4 ( & V_43 -> V_68 , V_6 ) ;
V_138 = F_123 ( V_43 , V_115 ) ;
if ( ! V_138 ) {
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( ! F_84 ( & V_43 -> V_67 )
&& F_17 ( V_115 -> V_250 . V_141 -> V_261 . V_8 )
&& ( F_116 ( & ( (struct V_180 * ) V_115 -> V_250 . V_141 ) -> V_189 )
& V_192 ) ) {
V_115 -> V_121 -> V_117 = 0 ;
V_43 -> V_67 . V_36 ( & V_43 -> V_67 ,
V_115 ) ;
F_49 ( & V_43 -> V_78 ) ;
} else {
F_100 ( V_115 ) ;
F_36 ( V_43 ) ;
return;
}
} else {
F_124 ( V_138 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_115 -> V_121 -> V_117 = ( unsigned long ) & V_138 -> V_111 ;
V_43 -> V_67 . V_36 ( & V_43 -> V_67 ,
V_115 ) ;
F_49 ( & V_43 -> V_78 ) ;
V_113 . V_122 = V_123 ;
V_113 . V_289 = 0 ;
V_113 . V_111 = & V_138 -> V_111 ;
F_129 ( V_138 , & V_113 ) ;
}
} else {
V_43 -> V_67 . V_36 ( & V_43 -> V_67 ,
V_115 ) ;
F_36 ( V_43 ) ;
}
}
static enum V_290 F_130 ( const struct V_1 * V_39 ,
const struct V_89 * V_61 ,
const struct V_120 * V_121 ,
int V_4 ,
struct V_133 * V_291 ,
struct V_133 * V_292 )
{
enum V_293 V_294 ;
struct V_139 * V_140 = (struct V_139 * ) V_291 -> V_141 ;
if ( F_131 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_295 ) ==
V_161 )
return V_161 ;
V_294 = F_132 ( V_140 ) ;
if ( V_294 == V_296 )
return V_297 ;
if ( V_294 == V_298 ) {
if ( F_72 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ) == V_161 )
return V_161 ;
if ( F_74 ( V_140 , V_39 -> V_3 ) == V_161 )
return V_161 ;
} else if ( F_64 ( V_39 -> V_3 ) ) {
memcpy ( V_292 , V_291 , F_57 ( V_292 ) ) ;
V_292 -> V_252 . V_251 . V_121 = & V_292 -> V_252 . V_121 ;
V_292 -> V_252 . V_251 . V_250 . V_141 = (struct V_127 * ) V_292 -> V_141 ;
V_292 -> V_252 . V_251 . V_250 . V_284 = & V_292 -> V_284 ;
F_133 ( ( const struct V_26 * ) V_292 -> V_141 ,
& V_292 -> V_284 , V_121 ,
V_39 -> V_3 ,
F_134 ( V_140 ) ,
V_61 -> V_62 -> V_265 ,
V_292 -> V_135 ,
false ) ;
return V_161 ;
}
return V_297 ;
}
static bool F_135 ( const struct V_133 * V_291 ,
struct V_133 * V_292 ,
T_8 * V_299 , bool V_152 )
{
const struct V_26 * V_300 = ( const struct V_26 * ) V_291 -> V_141 ;
struct V_26 * V_301 = (struct V_26 * ) V_292 -> V_141 ;
if ( V_300 -> V_22 == V_302 ||
V_300 -> V_22 == V_303 ) {
memcpy ( V_292 , V_291 , F_57 ( V_292 ) ) ;
V_292 -> V_252 . V_251 . V_121 = & V_292 -> V_252 . V_121 ;
V_292 -> V_252 . V_251 . V_250 . V_141 = (struct V_127 * ) V_292 -> V_141 ;
V_292 -> V_252 . V_251 . V_250 . V_284 = & V_292 -> V_284 ;
V_301 -> V_22 = V_304 ;
V_301 -> V_122 = F_136 ( V_305 ) ;
if ( V_300 -> V_8 == V_9 )
V_301 -> V_122 |= V_306 ;
if ( V_152 && V_300 -> V_164 == V_165 ) {
if ( V_300 -> V_8 ==
V_58 ||
V_300 -> V_8 ==
V_9 )
* V_299 = F_137 (
(struct V_142 * ) V_291 -> V_141 ) ;
else
* V_299 = sizeof( struct V_26 ) ;
}
return true ;
} else {
return false ;
}
}
static enum V_290
F_138 ( struct V_1 * V_39 ,
struct V_89 * V_61 ,
struct V_120 * V_121 ,
int V_4 ,
struct V_133 * V_291 ,
struct V_133 * V_292 )
{
enum V_293 V_294 ;
struct V_142 * V_140 = (struct V_142 * ) V_291 -> V_141 ;
if ( F_139 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_295 ) ==
V_161 )
return V_161 ;
V_294 = F_140 ( V_140 ) ;
if ( V_294 == V_296 )
return V_297 ;
if ( V_294 == V_298 ) {
if ( F_66 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ) == V_161 )
return V_161 ;
if ( F_69 ( V_140 , V_39 -> V_3 ) ==
V_161 )
return V_161 ;
} else if ( F_64 ( V_39 -> V_3 ) ) {
memcpy ( V_292 , V_291 , F_57 ( V_292 ) ) ;
V_292 -> V_252 . V_251 . V_121 = & V_292 -> V_252 . V_121 ;
V_292 -> V_252 . V_251 . V_250 . V_200 =
(struct V_200 * ) V_292 -> V_141 ;
V_292 -> V_252 . V_251 . V_250 . V_284 = & V_292 -> V_284 ;
F_133 ( ( const struct V_26 * ) V_292 -> V_141 ,
& V_292 -> V_284 , V_121 ,
V_39 -> V_3 ,
F_141 ( V_140 ) ,
V_61 -> V_62 -> V_265 ,
V_291 -> V_252 . V_121 . V_126 ,
true ) ;
return V_161 ;
}
return V_297 ;
}
static enum V_290
F_142 ( struct V_1 * V_39 ,
struct V_89 * V_61 ,
struct V_120 * V_121 ,
int V_4 ,
struct V_133 * V_291 ,
struct V_133 * V_292 ,
bool V_152 )
{
struct V_26 * V_261 = (struct V_26 * ) V_291 -> V_141 ;
if ( V_152 && V_261 -> V_164 == V_165 &&
V_261 -> V_153 == V_307 )
return F_138 ( V_39 , V_61 , V_121 , V_4 , V_291 ,
V_292 ) ;
return F_130 ( V_39 , V_61 , V_121 , V_4 , V_291 , V_292 ) ;
}
static void F_143 ( struct V_1 * V_39 ,
struct V_120 * V_121 )
{
struct V_89 * V_61 ;
struct V_246 * V_247 ;
struct V_133 * V_291 , * V_292 = NULL ;
struct V_104 * V_105 ;
struct V_42 * V_103 ;
int V_4 ;
int V_40 = V_169 ;
T_8 V_135 ;
T_7 V_308 = 0 ;
bool V_152 ;
V_105 = (struct V_104 * ) ( unsigned long ) V_121 -> V_117 ;
V_61 = V_105 -> V_107 -> V_61 ;
F_52 ( V_105 ) ;
V_152 = F_63 ( V_61 -> V_39 -> V_3 ,
V_61 -> V_39 -> V_4 ) ;
V_247 = F_51 ( V_105 , struct V_246 ,
V_105 ) ;
V_291 = F_51 ( V_247 , struct V_133 , V_252 ) ;
F_95 ( V_39 -> V_3 ,
V_291 -> V_252 . V_309 ,
F_61 ( V_291 ) ,
V_310 ) ;
V_291 -> V_252 . V_121 = * V_121 ;
V_291 -> V_252 . V_251 . V_121 = & V_291 -> V_252 . V_121 ;
if ( V_152 && ( (struct V_26 * ) ( V_291 -> V_141 ) ) -> V_164 == V_165 ) {
V_291 -> V_252 . V_251 . V_311 = V_121 -> V_126 - sizeof( struct V_128 ) ;
V_291 -> V_252 . V_251 . V_312 = sizeof( struct V_200 ) ;
} else {
V_291 -> V_252 . V_251 . V_311 = sizeof( struct V_127 ) ;
V_291 -> V_252 . V_251 . V_312 = sizeof( struct V_127 ) ;
}
V_291 -> V_252 . V_251 . V_250 . V_141 = (struct V_127 * ) V_291 -> V_141 ;
V_291 -> V_252 . V_251 . V_250 . V_284 = & V_291 -> V_284 ;
if ( F_144 ( & V_61 -> V_98 ) )
F_55 ( V_61 , & V_291 -> V_252 . V_251 , V_88 ) ;
if ( ! F_114 ( ( const struct V_26 * ) V_291 -> V_141 , V_61 , V_152 ) )
goto V_97;
V_135 = V_291 -> V_135 ;
V_292 = F_58 ( V_135 , V_64 ) ;
if ( ! V_292 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_30 ) ;
goto V_97;
}
if ( F_64 ( V_39 -> V_3 ) )
V_4 = V_121 -> V_4 ;
else
V_4 = V_39 -> V_4 ;
if ( ( (struct V_26 * ) V_291 -> V_141 ) -> V_8 ==
V_9 ) {
if ( F_142 ( V_39 , V_61 , V_121 , V_4 , V_291 ,
V_292 , V_152 )
== V_161 )
goto V_97;
}
if ( V_39 -> V_3 -> V_168 ) {
V_40 = V_39 -> V_3 -> V_168 ( V_39 -> V_3 , 0 ,
V_39 -> V_4 ,
V_121 , & V_291 -> V_284 ,
( const struct V_26 * ) V_291 -> V_141 ,
V_291 -> V_135 ,
(struct V_26 * ) V_292 -> V_141 ,
& V_135 , & V_308 ) ;
if ( V_152 )
V_121 -> V_119 = V_308 ;
if ( V_40 & V_169 ) {
if ( V_40 & V_171 )
goto V_97;
if ( V_40 & V_170 ) {
F_133 ( ( const struct V_26 * ) V_292 -> V_141 ,
& V_291 -> V_284 , V_121 ,
V_39 -> V_3 ,
V_4 ,
V_61 -> V_62 -> V_265 ,
V_135 , V_152 ) ;
goto V_97;
}
}
}
V_103 = F_77 ( V_39 , ( const struct V_26 * ) V_291 -> V_141 ) ;
if ( V_103 ) {
F_126 ( V_103 , & V_291 -> V_252 . V_251 ) ;
V_291 = NULL ;
} else if ( ( V_40 & V_169 ) &&
F_135 ( V_291 , V_292 , & V_135 , V_152 ) ) {
F_133 ( ( const struct V_26 * ) V_292 -> V_141 , & V_291 -> V_284 , V_121 ,
V_39 -> V_3 , V_4 ,
V_61 -> V_62 -> V_265 , V_135 , V_152 ) ;
}
V_97:
if ( V_292 ) {
F_145 ( V_61 , V_292 ) ;
F_29 ( V_291 ) ;
} else
F_145 ( V_61 , V_291 ) ;
}
static void F_146 ( struct V_42 * V_43 )
{
struct V_137 * V_138 ;
unsigned long V_313 ;
if ( F_147 ( & V_43 -> V_70 ) ) {
F_42 ( & V_43 -> V_73 ) ;
} else {
V_138 = F_148 ( V_43 -> V_70 . V_194 ,
struct V_137 ,
V_85 ) ;
if ( F_149 ( V_43 -> V_238 ,
V_138 -> V_238 ) ) {
V_43 -> V_238 = V_138 -> V_238 ;
V_313 = V_138 -> V_238 - V_314 ;
if ( ( long ) V_313 <= 0 )
V_313 = 1 ;
F_150 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_73 , V_313 ) ;
}
}
}
static void F_151 ( struct V_137 * V_138 )
{
struct V_42 * V_43 ;
struct V_137 * V_315 ;
struct V_221 * V_316 ;
unsigned long V_313 ;
V_43 = V_138 -> V_43 ;
F_44 ( & V_138 -> V_85 ) ;
V_313 = V_138 -> V_238 ;
V_138 -> V_238 += V_314 ;
if ( V_313 ) {
F_152 (list_item, &mad_agent_priv->wait_list) {
V_315 = F_148 ( V_316 ,
struct V_137 ,
V_85 ) ;
if ( F_149 ( V_138 -> V_238 ,
V_315 -> V_238 ) )
break;
}
}
else
V_316 = & V_43 -> V_70 ;
F_127 ( & V_138 -> V_85 , V_316 ) ;
if ( V_43 -> V_70 . V_194 == & V_138 -> V_85 )
F_150 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_73 , V_313 ) ;
}
void F_153 ( struct V_137 * V_138 ,
int V_235 )
{
V_138 -> V_238 = F_98 ( V_235 ) ;
F_151 ( V_138 ) ;
}
void F_129 ( struct V_137 * V_138 ,
struct V_112 * V_113 )
{
struct V_42 * V_43 ;
unsigned long V_6 ;
int V_40 ;
V_43 = V_138 -> V_43 ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
if ( F_84 ( & V_43 -> V_67 ) ) {
V_40 = F_154 ( V_138 , V_113 ) ;
if ( V_40 == V_242 )
goto V_317;
} else
V_40 = V_318 ;
if ( V_113 -> V_122 != V_123 &&
V_138 -> V_122 == V_123 ) {
V_138 -> V_122 = V_113 -> V_122 ;
V_138 -> V_78 -= ( V_138 -> V_238 > 0 ) ;
}
if ( -- V_138 -> V_78 > 0 ) {
if ( V_138 -> V_78 == 1 && V_138 -> V_238 &&
V_138 -> V_122 == V_123 ) {
F_151 ( V_138 ) ;
}
goto V_317;
}
F_44 ( & V_138 -> V_85 ) ;
F_146 ( V_43 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_138 -> V_122 != V_123 )
V_113 -> V_122 = V_138 -> V_122 ;
if ( V_40 == V_319 )
F_155 ( V_113 ) ;
else
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
V_113 ) ;
F_36 ( V_43 ) ;
return;
V_317:
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static void F_156 ( struct V_1 * V_39 ,
struct V_120 * V_121 )
{
struct V_137 * V_138 , * V_320 ;
struct V_104 * V_105 ;
struct V_89 * V_61 ;
struct V_106 * V_226 ;
struct V_222 * V_223 ;
struct V_112 V_113 ;
unsigned long V_6 ;
int V_40 ;
V_105 = (struct V_104 * ) ( unsigned long ) V_121 -> V_117 ;
V_138 = F_51 ( V_105 , struct V_137 ,
V_105 ) ;
V_226 = V_105 -> V_107 ;
V_61 = V_226 -> V_61 ;
V_321:
F_95 ( V_138 -> V_111 . V_103 -> V_3 ,
V_138 -> V_229 ,
V_138 -> V_201 [ 0 ] . V_202 , V_228 ) ;
F_95 ( V_138 -> V_111 . V_103 -> V_3 ,
V_138 -> V_230 ,
V_138 -> V_201 [ 1 ] . V_202 , V_228 ) ;
V_320 = NULL ;
F_4 ( & V_226 -> V_68 , V_6 ) ;
F_44 ( & V_105 -> V_108 ) ;
if ( V_226 -> V_109 -- > V_226 -> V_231 ) {
V_105 = F_51 ( V_61 -> V_232 . V_194 ,
struct V_104 , V_108 ) ;
V_320 = F_51 ( V_105 ,
struct V_137 ,
V_105 ) ;
F_125 ( & V_105 -> V_108 , & V_226 -> V_108 ) ;
}
F_5 ( & V_226 -> V_68 , V_6 ) ;
V_113 . V_111 = & V_138 -> V_111 ;
V_113 . V_122 = V_121 -> V_122 ;
V_113 . V_289 = V_121 -> V_289 ;
if ( F_144 ( & V_61 -> V_98 ) )
F_54 ( V_61 , & V_138 -> V_111 , & V_113 ,
V_87 ) ;
F_129 ( V_138 , & V_113 ) ;
if ( V_320 ) {
V_40 = F_96 ( V_61 -> V_62 , & V_320 -> V_149 . V_163 ,
& V_223 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_31 , V_40 ) ;
V_138 = V_320 ;
V_121 -> V_122 = V_322 ;
goto V_321;
}
}
}
static void F_157 ( struct V_89 * V_61 )
{
struct V_137 * V_138 ;
struct V_104 * V_105 ;
unsigned long V_6 ;
F_4 ( & V_61 -> V_226 . V_68 , V_6 ) ;
F_2 (mad_list, &qp_info->send_queue.list, list) {
V_138 = F_51 ( V_105 ,
struct V_137 ,
V_105 ) ;
V_138 -> V_321 = 1 ;
}
F_5 ( & V_61 -> V_226 . V_68 , V_6 ) ;
}
static void F_158 ( struct V_1 * V_39 ,
struct V_120 * V_121 )
{
struct V_104 * V_105 ;
struct V_89 * V_61 ;
struct V_137 * V_138 ;
int V_40 ;
V_105 = (struct V_104 * ) ( unsigned long ) V_121 -> V_117 ;
V_61 = V_105 -> V_107 -> V_61 ;
if ( V_105 -> V_107 == & V_61 -> V_323 )
return;
V_138 = F_51 ( V_105 , struct V_137 ,
V_105 ) ;
if ( V_121 -> V_122 == V_324 ) {
if ( V_138 -> V_321 ) {
struct V_222 * V_223 ;
V_138 -> V_321 = 0 ;
V_40 = F_96 ( V_61 -> V_62 , & V_138 -> V_149 . V_163 ,
& V_223 ) ;
if ( V_40 )
F_156 ( V_39 , V_121 ) ;
} else
F_156 ( V_39 , V_121 ) ;
} else {
struct V_325 * V_273 ;
V_273 = F_76 ( sizeof *V_273 , V_64 ) ;
if ( V_273 ) {
V_273 -> V_326 = V_327 ;
V_273 -> V_328 = V_329 ;
V_40 = F_159 ( V_61 -> V_62 , V_273 ,
V_330 | V_331 ) ;
F_29 ( V_273 ) ;
if ( V_40 )
F_67 ( & V_39 -> V_3 -> V_52 ,
L_32 ,
V_40 ) ;
else
F_157 ( V_61 ) ;
}
F_156 ( V_39 , V_121 ) ;
}
}
static void F_160 ( struct V_332 * V_333 )
{
struct V_1 * V_39 ;
struct V_120 V_121 ;
V_39 = F_51 ( V_333 , struct V_1 , V_333 ) ;
F_161 ( V_39 -> V_334 , V_335 ) ;
while ( F_162 ( V_39 -> V_334 , 1 , & V_121 ) == 1 ) {
if ( V_121 . V_122 == V_123 ) {
switch ( V_121 . V_124 ) {
case V_336 :
F_156 ( V_39 , & V_121 ) ;
break;
case V_125 :
F_143 ( V_39 , & V_121 ) ;
break;
default:
F_53 ( 1 ) ;
break;
}
} else
F_158 ( V_39 , & V_121 ) ;
}
}
static void F_41 ( struct V_42 * V_43 )
{
unsigned long V_6 ;
struct V_137 * V_138 , * V_315 ;
struct V_112 V_113 ;
struct V_221 V_337 ;
F_21 ( & V_337 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_81 (mad_send_wr, temp_mad_send_wr,
&mad_agent_priv->send_list, agent_list) {
if ( V_138 -> V_122 == V_123 ) {
V_138 -> V_122 = V_324 ;
V_138 -> V_78 -= ( V_138 -> V_238 > 0 ) ;
}
}
F_101 ( & V_43 -> V_70 , & V_337 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_113 . V_122 = V_324 ;
V_113 . V_289 = 0 ;
F_81 (mad_send_wr, temp_mad_send_wr,
&cancel_list, agent_list) {
V_113 . V_111 = & V_138 -> V_111 ;
F_44 ( & V_138 -> V_85 ) ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_113 ) ;
F_49 ( & V_43 -> V_78 ) ;
}
}
static struct V_137 *
F_163 ( struct V_42 * V_43 ,
struct V_110 * V_111 )
{
struct V_137 * V_138 ;
F_2 (mad_send_wr, &mad_agent_priv->wait_list,
agent_list) {
if ( & V_138 -> V_111 == V_111 )
return V_138 ;
}
F_2 (mad_send_wr, &mad_agent_priv->send_list,
agent_list) {
if ( F_115 ( V_43 ,
V_138 -> V_111 . V_141 ) &&
& V_138 -> V_111 == V_111 )
return V_138 ;
}
return NULL ;
}
int F_164 ( struct V_33 * V_103 ,
struct V_110 * V_111 , T_4 V_235 )
{
struct V_42 * V_43 ;
struct V_137 * V_138 ;
unsigned long V_6 ;
int V_338 ;
V_43 = F_51 ( V_103 , struct V_42 ,
V_67 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
V_138 = F_163 ( V_43 , V_111 ) ;
if ( ! V_138 || V_138 -> V_122 != V_123 ) {
F_5 ( & V_43 -> V_68 , V_6 ) ;
return - V_41 ;
}
V_338 = ( ! V_138 -> V_238 || V_138 -> V_78 > 1 ) ;
if ( ! V_235 ) {
V_138 -> V_122 = V_324 ;
V_138 -> V_78 -= ( V_138 -> V_238 > 0 ) ;
}
V_138 -> V_111 . V_235 = V_235 ;
if ( V_338 )
V_138 -> V_238 = F_98 ( V_235 ) ;
else
F_153 ( V_138 , V_235 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
return 0 ;
}
void F_165 ( struct V_33 * V_103 ,
struct V_110 * V_111 )
{
F_164 ( V_103 , V_111 , 0 ) ;
}
static void V_77 ( struct V_332 * V_333 )
{
struct V_42 * V_43 ;
struct V_143 * V_144 ;
struct V_42 * V_146 ;
unsigned long V_6 ;
int V_339 ;
struct V_120 V_121 ;
struct V_112 V_113 ;
bool V_152 ;
V_43 =
F_51 ( V_333 , struct V_42 , V_76 ) ;
V_152 = F_63 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_147 ( & V_43 -> V_75 ) ) {
V_144 = F_148 ( V_43 -> V_75 . V_194 ,
struct V_143 ,
V_173 ) ;
F_44 ( & V_144 -> V_173 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_339 = 0 ;
if ( V_144 -> V_145 ) {
T_1 V_164 ;
V_146 = V_144 -> V_146 ;
if ( ! V_146 ) {
F_67 ( & V_43 -> V_67 . V_3 -> V_52 ,
L_33 ) ;
V_339 = 1 ;
goto V_340;
}
F_56 ( V_146 -> V_67 . V_62 ,
( unsigned long ) V_144 -> V_138 ,
F_73 ( V_162 ) ,
V_144 -> V_138 -> V_149 . V_119 ,
V_146 -> V_67 . V_4 , & V_121 ) ;
V_144 -> V_145 -> V_252 . V_251 . V_121 = & V_121 ;
V_164 = ( (struct V_26 * ) ( V_144 -> V_145 -> V_141 ) ) -> V_164 ;
if ( V_152 && V_164 == V_165 ) {
V_144 -> V_145 -> V_252 . V_251 . V_311 = V_144 -> V_172 ;
V_144 -> V_145 -> V_252 . V_251 . V_312 = sizeof( struct V_200 ) ;
} else {
V_144 -> V_145 -> V_252 . V_251 . V_311 = sizeof( struct V_127 ) ;
V_144 -> V_145 -> V_252 . V_251 . V_312 = sizeof( struct V_127 ) ;
}
F_21 ( & V_144 -> V_145 -> V_252 . V_251 . V_72 ) ;
F_127 ( & V_144 -> V_145 -> V_252 . V_251 . V_250 . V_108 ,
& V_144 -> V_145 -> V_252 . V_251 . V_72 ) ;
V_144 -> V_145 -> V_252 . V_251 . V_250 . V_284 = NULL ;
V_144 -> V_145 -> V_252 . V_251 . V_250 . V_141 =
(struct V_127 * ) V_144 -> V_145 -> V_141 ;
if ( F_144 ( & V_146 -> V_61 -> V_98 ) )
F_55 ( V_146 -> V_61 ,
& V_144 -> V_145 -> V_252 . V_251 ,
V_88 ) ;
V_146 -> V_67 . V_36 (
& V_146 -> V_67 ,
& V_144 -> V_145 -> V_252 . V_251 ) ;
F_4 ( & V_146 -> V_68 , V_6 ) ;
F_49 ( & V_146 -> V_78 ) ;
F_5 ( & V_146 -> V_68 , V_6 ) ;
}
V_340:
V_113 . V_122 = V_123 ;
V_113 . V_289 = 0 ;
V_113 . V_111 = & V_144 -> V_138 -> V_111 ;
if ( F_144 ( & V_43 -> V_61 -> V_98 ) )
F_54 ( V_43 -> V_61 ,
& V_144 -> V_138 -> V_111 ,
& V_113 , V_87 ) ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_113 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_49 ( & V_43 -> V_78 ) ;
if ( V_339 )
F_29 ( V_144 -> V_145 ) ;
F_29 ( V_144 ) ;
}
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static int F_166 ( struct V_137 * V_138 )
{
int V_40 ;
if ( ! V_138 -> V_241 )
return - V_341 ;
V_138 -> V_241 -- ;
V_138 -> V_111 . V_240 ++ ;
V_138 -> V_238 = F_98 ( V_138 -> V_111 . V_235 ) ;
if ( F_84 ( & V_138 -> V_43 -> V_67 ) ) {
V_40 = F_167 ( V_138 ) ;
switch ( V_40 ) {
case V_318 :
V_40 = F_91 ( V_138 ) ;
break;
case V_242 :
V_40 = 0 ;
break;
default:
V_40 = - V_342 ;
break;
}
} else
V_40 = F_91 ( V_138 ) ;
if ( ! V_40 ) {
V_138 -> V_78 ++ ;
F_28 ( & V_138 -> V_85 ,
& V_138 -> V_43 -> V_69 ) ;
}
return V_40 ;
}
static void V_74 ( struct V_332 * V_333 )
{
struct V_42 * V_43 ;
struct V_137 * V_138 ;
struct V_112 V_113 ;
unsigned long V_6 , V_313 ;
V_43 = F_51 ( V_333 , struct V_42 ,
V_73 . V_333 ) ;
V_113 . V_289 = 0 ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_147 ( & V_43 -> V_70 ) ) {
V_138 = F_148 ( V_43 -> V_70 . V_194 ,
struct V_137 ,
V_85 ) ;
if ( F_149 ( V_138 -> V_238 , V_314 ) ) {
V_313 = V_138 -> V_238 - V_314 ;
if ( ( long ) V_313 <= 0 )
V_313 = 1 ;
F_168 ( V_43 -> V_61 ->
V_39 -> V_102 ,
& V_43 -> V_73 , V_313 ) ;
break;
}
F_44 ( & V_138 -> V_85 ) ;
if ( V_138 -> V_122 == V_123 &&
! F_166 ( V_138 ) )
continue;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_138 -> V_122 == V_123 )
V_113 . V_122 = V_343 ;
else
V_113 . V_122 = V_138 -> V_122 ;
V_113 . V_111 = & V_138 -> V_111 ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_113 ) ;
F_49 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
}
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static void F_169 ( struct V_344 * V_334 , void * V_345 )
{
struct V_1 * V_39 = V_334 -> V_346 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
if ( ! F_147 ( & V_39 -> V_347 ) )
F_78 ( V_39 -> V_102 , & V_39 -> V_333 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static int F_145 ( struct V_89 * V_61 ,
struct V_133 * V_141 )
{
unsigned long V_6 ;
int V_348 , V_40 ;
struct V_133 * V_145 ;
struct V_224 V_201 ;
struct V_349 V_350 , * V_351 ;
struct V_106 * V_323 = & V_61 -> V_323 ;
V_201 . V_203 = V_61 -> V_39 -> V_204 -> V_205 ;
V_350 . V_194 = NULL ;
V_350 . V_201 = & V_201 ;
V_350 . V_206 = 1 ;
do {
if ( V_141 ) {
V_145 = V_141 ;
V_141 = NULL ;
} else {
V_145 = F_58 ( F_59 ( V_61 -> V_39 ) ,
V_96 ) ;
if ( ! V_145 ) {
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_34 ) ;
V_40 = - V_65 ;
break;
}
}
V_201 . V_202 = F_61 ( V_145 ) ;
V_201 . V_227 = F_92 ( V_61 -> V_39 -> V_3 ,
& V_145 -> V_284 ,
F_61 ( V_145 ) ,
V_310 ) ;
if ( F_93 ( F_94 ( V_61 -> V_39 -> V_3 ,
V_201 . V_227 ) ) ) {
V_40 = - V_65 ;
break;
}
V_145 -> V_252 . V_309 = V_201 . V_227 ;
V_350 . V_117 = ( unsigned long ) & V_145 -> V_252 . V_105 ;
V_145 -> V_252 . V_105 . V_107 = V_323 ;
F_4 ( & V_323 -> V_68 , V_6 ) ;
V_348 = ( ++ V_323 -> V_109 < V_323 -> V_231 ) ;
F_28 ( & V_145 -> V_252 . V_105 . V_108 , & V_323 -> V_108 ) ;
F_5 ( & V_323 -> V_68 , V_6 ) ;
V_40 = F_170 ( V_61 -> V_62 , & V_350 , & V_351 ) ;
if ( V_40 ) {
F_4 ( & V_323 -> V_68 , V_6 ) ;
F_44 ( & V_145 -> V_252 . V_105 . V_108 ) ;
V_323 -> V_109 -- ;
F_5 ( & V_323 -> V_68 , V_6 ) ;
F_95 ( V_61 -> V_39 -> V_3 ,
V_145 -> V_252 . V_309 ,
F_61 ( V_145 ) ,
V_310 ) ;
F_29 ( V_145 ) ;
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_35 , V_40 ) ;
break;
}
} while ( V_348 );
return V_40 ;
}
static void F_171 ( struct V_89 * V_61 )
{
struct V_246 * V_247 ;
struct V_133 * V_291 ;
struct V_104 * V_105 ;
if ( ! V_61 -> V_62 )
return;
while ( ! F_147 ( & V_61 -> V_323 . V_108 ) ) {
V_105 = F_148 ( V_61 -> V_323 . V_108 . V_194 ,
struct V_104 , V_108 ) ;
V_247 = F_51 ( V_105 ,
struct V_246 ,
V_105 ) ;
V_291 = F_51 ( V_247 , struct V_133 ,
V_252 ) ;
F_44 ( & V_105 -> V_108 ) ;
F_95 ( V_61 -> V_39 -> V_3 ,
V_291 -> V_252 . V_309 ,
F_61 ( V_291 ) ,
V_310 ) ;
F_29 ( V_291 ) ;
}
V_61 -> V_323 . V_109 = 0 ;
}
static int F_172 ( struct V_1 * V_39 )
{
int V_40 , V_23 ;
struct V_325 * V_273 ;
struct V_116 * V_62 ;
T_7 V_119 ;
V_273 = F_76 ( sizeof *V_273 , V_64 ) ;
if ( ! V_273 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_36 ) ;
return - V_65 ;
}
V_40 = F_173 ( V_39 -> V_3 , V_39 -> V_4 ,
V_352 , & V_119 ) ;
if ( V_40 )
V_119 = 0 ;
for ( V_23 = 0 ; V_23 < V_353 ; V_23 ++ ) {
V_62 = V_39 -> V_61 [ V_23 ] . V_62 ;
if ( ! V_62 )
continue;
V_273 -> V_326 = V_354 ;
V_273 -> V_119 = V_119 ;
V_273 -> V_355 = ( V_62 -> V_265 == 0 ) ? 0 : V_356 ;
V_40 = F_159 ( V_62 , V_273 , V_330 |
V_357 | V_358 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_37 ,
V_23 , V_40 ) ;
goto V_97;
}
V_273 -> V_326 = V_359 ;
V_40 = F_159 ( V_62 , V_273 , V_330 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_38 ,
V_23 , V_40 ) ;
goto V_97;
}
V_273 -> V_326 = V_327 ;
V_273 -> V_360 = V_361 ;
V_40 = F_159 ( V_62 , V_273 , V_330 | V_362 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_39 ,
V_23 , V_40 ) ;
goto V_97;
}
}
V_40 = F_161 ( V_39 -> V_334 , V_335 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_40 ,
V_40 ) ;
goto V_97;
}
for ( V_23 = 0 ; V_23 < V_353 ; V_23 ++ ) {
if ( ! V_39 -> V_61 [ V_23 ] . V_62 )
continue;
V_40 = F_145 ( & V_39 -> V_61 [ V_23 ] , NULL ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_41 ) ;
goto V_97;
}
}
V_97:
F_29 ( V_273 ) ;
return V_40 ;
}
static void F_174 ( struct V_363 * V_364 , void * V_365 )
{
struct V_89 * V_61 = V_365 ;
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_42 ,
V_364 -> V_364 , V_61 -> V_62 -> V_265 ) ;
}
static void F_175 ( struct V_89 * V_61 ,
struct V_106 * V_107 )
{
V_107 -> V_61 = V_61 ;
V_107 -> V_109 = 0 ;
F_20 ( & V_107 -> V_68 ) ;
F_21 ( & V_107 -> V_108 ) ;
}
static void F_176 ( struct V_1 * V_39 ,
struct V_89 * V_61 )
{
V_61 -> V_39 = V_39 ;
F_175 ( V_61 , & V_61 -> V_226 ) ;
F_175 ( V_61 , & V_61 -> V_323 ) ;
F_21 ( & V_61 -> V_232 ) ;
F_20 ( & V_61 -> V_93 ) ;
V_61 -> V_95 = NULL ;
V_61 -> V_94 = 0 ;
F_24 ( & V_61 -> V_98 , 0 ) ;
}
static int F_177 ( struct V_89 * V_61 ,
enum V_10 V_11 )
{
struct V_366 V_367 ;
int V_40 ;
memset ( & V_367 , 0 , sizeof V_367 ) ;
V_367 . V_368 = V_61 -> V_39 -> V_334 ;
V_367 . V_369 = V_61 -> V_39 -> V_334 ;
V_367 . V_370 = V_371 ;
V_367 . V_372 . V_373 = V_374 ;
V_367 . V_372 . V_375 = V_376 ;
V_367 . V_372 . V_377 = V_378 ;
V_367 . V_372 . V_379 = V_380 ;
V_367 . V_11 = V_11 ;
V_367 . V_4 = V_61 -> V_39 -> V_4 ;
V_367 . V_365 = V_61 ;
V_367 . V_381 = F_174 ;
V_61 -> V_62 = F_178 ( V_61 -> V_39 -> V_204 , & V_367 ) ;
if ( F_179 ( V_61 -> V_62 ) ) {
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_43 ,
F_7 ( V_11 ) ) ;
V_40 = F_180 ( V_61 -> V_62 ) ;
goto error;
}
V_61 -> V_226 . V_231 = V_374 ;
V_61 -> V_323 . V_231 = V_376 ;
return 0 ;
error:
return V_40 ;
}
static void F_181 ( struct V_89 * V_61 )
{
if ( ! V_61 -> V_62 )
return;
F_182 ( V_61 -> V_62 ) ;
F_29 ( V_61 -> V_95 ) ;
}
static int F_183 ( struct V_2 * V_3 ,
int V_4 )
{
int V_40 , V_382 ;
struct V_1 * V_39 ;
unsigned long V_6 ;
char V_383 [ sizeof "ib_mad123"];
int V_384 ;
struct V_385 V_386 = {} ;
if ( F_184 ( F_60 ( V_3 , V_4 ) < V_387 ) )
return - V_388 ;
if ( F_184 ( F_63 ( V_3 , V_4 ) &&
F_60 ( V_3 , V_4 ) < V_389 ) )
return - V_388 ;
V_39 = F_18 ( sizeof *V_39 , V_64 ) ;
if ( ! V_39 ) {
F_67 ( & V_3 -> V_52 , L_44 ) ;
return - V_65 ;
}
V_39 -> V_3 = V_3 ;
V_39 -> V_4 = V_4 ;
F_20 ( & V_39 -> V_80 ) ;
F_21 ( & V_39 -> V_85 ) ;
F_176 ( V_39 , & V_39 -> V_61 [ 0 ] ) ;
F_176 ( V_39 , & V_39 -> V_61 [ 1 ] ) ;
V_382 = V_374 + V_376 ;
V_384 = F_185 ( V_3 , V_4 ) ;
if ( V_384 )
V_382 *= 2 ;
V_386 . V_390 = V_382 ;
V_39 -> V_334 = F_186 ( V_39 -> V_3 ,
F_169 ,
NULL , V_39 , & V_386 ) ;
if ( F_179 ( V_39 -> V_334 ) ) {
F_67 ( & V_3 -> V_52 , L_45 ) ;
V_40 = F_180 ( V_39 -> V_334 ) ;
goto V_66;
}
V_39 -> V_204 = F_187 ( V_3 ) ;
if ( F_179 ( V_39 -> V_204 ) ) {
F_67 ( & V_3 -> V_52 , L_46 ) ;
V_40 = F_180 ( V_39 -> V_204 ) ;
goto V_84;
}
if ( V_384 ) {
V_40 = F_177 ( & V_39 -> V_61 [ 0 ] , V_12 ) ;
if ( V_40 )
goto V_391;
}
V_40 = F_177 ( & V_39 -> V_61 [ 1 ] , V_13 ) ;
if ( V_40 )
goto V_392;
snprintf ( V_383 , sizeof V_383 , L_47 , V_4 ) ;
V_39 -> V_102 = F_188 ( V_383 ) ;
if ( ! V_39 -> V_102 ) {
V_40 = - V_65 ;
goto V_393;
}
F_23 ( & V_39 -> V_333 , F_160 ) ;
F_4 ( & V_7 , V_6 ) ;
F_28 ( & V_39 -> V_347 , & V_394 ) ;
F_5 ( & V_7 , V_6 ) ;
V_40 = F_172 ( V_39 ) ;
if ( V_40 ) {
F_67 ( & V_3 -> V_52 , L_48 ) ;
goto V_395;
}
return 0 ;
V_395:
F_4 ( & V_7 , V_6 ) ;
F_189 ( & V_39 -> V_347 ) ;
F_5 ( & V_7 , V_6 ) ;
F_190 ( V_39 -> V_102 ) ;
V_393:
F_181 ( & V_39 -> V_61 [ 1 ] ) ;
V_392:
F_181 ( & V_39 -> V_61 [ 0 ] ) ;
V_391:
F_191 ( V_39 -> V_204 ) ;
V_84:
F_192 ( V_39 -> V_334 ) ;
F_171 ( & V_39 -> V_61 [ 1 ] ) ;
F_171 ( & V_39 -> V_61 [ 0 ] ) ;
V_66:
F_29 ( V_39 ) ;
return V_40 ;
}
static int F_193 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
V_39 = F_1 ( V_3 , V_4 ) ;
if ( V_39 == NULL ) {
F_5 ( & V_7 , V_6 ) ;
F_67 ( & V_3 -> V_52 , L_49 , V_4 ) ;
return - V_60 ;
}
F_189 ( & V_39 -> V_347 ) ;
F_5 ( & V_7 , V_6 ) ;
F_190 ( V_39 -> V_102 ) ;
F_181 ( & V_39 -> V_61 [ 1 ] ) ;
F_181 ( & V_39 -> V_61 [ 0 ] ) ;
F_191 ( V_39 -> V_204 ) ;
F_192 ( V_39 -> V_334 ) ;
F_171 ( & V_39 -> V_61 [ 1 ] ) ;
F_171 ( & V_39 -> V_61 [ 0 ] ) ;
F_29 ( V_39 ) ;
return 0 ;
}
static void F_194 ( struct V_2 * V_3 )
{
int V_396 , V_23 ;
V_396 = F_195 ( V_3 ) ;
for ( V_23 = V_396 ; V_23 <= F_196 ( V_3 ) ; V_23 ++ ) {
if ( ! F_197 ( V_3 , V_23 ) )
continue;
if ( F_183 ( V_3 , V_23 ) ) {
F_67 ( & V_3 -> V_52 , L_50 , V_23 ) ;
goto error;
}
if ( F_198 ( V_3 , V_23 ) ) {
F_67 ( & V_3 -> V_52 ,
L_51 , V_23 ) ;
goto V_397;
}
}
return;
V_397:
if ( F_193 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_52 , V_23 ) ;
error:
while ( -- V_23 >= V_396 ) {
if ( ! F_197 ( V_3 , V_23 ) )
continue;
if ( F_199 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 ,
L_53 , V_23 ) ;
if ( F_193 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_52 , V_23 ) ;
}
}
static void F_200 ( struct V_2 * V_3 , void * V_398 )
{
int V_23 ;
for ( V_23 = F_195 ( V_3 ) ; V_23 <= F_196 ( V_3 ) ; V_23 ++ ) {
if ( ! F_197 ( V_3 , V_23 ) )
continue;
if ( F_199 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 ,
L_53 , V_23 ) ;
if ( F_193 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_52 , V_23 ) ;
}
}
static int T_10 F_201 ( void )
{
V_376 = F_202 ( V_376 , V_399 ) ;
V_376 = F_203 ( V_376 , V_400 ) ;
V_374 = F_202 ( V_374 , V_399 ) ;
V_374 = F_203 ( V_374 , V_400 ) ;
F_21 ( & V_394 ) ;
if ( F_204 ( & V_401 ) ) {
F_105 ( L_54 ) ;
return - V_41 ;
}
return 0 ;
}
static void T_11 F_205 ( void )
{
F_206 ( & V_401 ) ;
}
