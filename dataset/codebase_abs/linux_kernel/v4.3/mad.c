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
V_4 = V_149 -> V_153 . V_154 . V_4 ;
else
V_4 = V_43 -> V_67 . V_4 ;
if ( V_152 && V_140 -> V_155 == V_156 ) {
T_4 V_157 ;
if ( ( F_65 ( V_142 )
? V_142 -> V_158 . V_159 . V_160 : V_142 -> V_158 . V_159 . V_161 ) ==
V_162 &&
F_66 ( V_142 ,
F_64 ( V_3 ) ,
V_4 ) == V_163 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_13 ) ;
goto V_97;
}
V_157 = F_68 ( V_142 -> V_158 . V_159 . V_161 ) ;
if ( V_157 != F_68 ( V_162 ) &&
V_157 & 0xffff0000 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_14 ,
V_157 ) ;
goto V_97;
}
V_151 = ( T_7 ) ( V_157 & 0x0000ffff ) ;
if ( F_69 ( V_142 , V_3 ) == V_163 &&
F_70 ( V_142 , V_3 ) == V_163 )
goto V_97;
} else {
if ( ( F_71 ( V_140 ) ? V_140 -> V_160 : V_140 -> V_161 ) ==
V_164 &&
F_72 ( V_140 , F_64 ( V_3 ) , V_4 ) ==
V_163 ) {
V_40 = - V_41 ;
F_67 ( & V_3 -> V_52 , L_15 ) ;
goto V_97;
}
V_151 = F_73 ( V_140 -> V_161 ) ;
if ( F_74 ( V_140 , V_3 ) == V_163 &&
F_75 ( V_140 , V_3 ) == V_163 )
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
V_149 -> V_117 , V_151 ,
V_149 -> V_153 . V_154 . V_119 ,
V_149 -> V_153 . V_154 . V_4 , & V_147 ) ;
if ( V_152 && V_140 -> V_165 == V_166 ) {
V_147 . V_126 = V_138 -> V_111 . V_167
+ V_138 -> V_111 . V_168
+ sizeof( struct V_128 ) ;
}
V_40 = V_3 -> V_169 ( V_3 , 0 , V_4 , & V_147 , NULL ,
( const struct V_26 * ) V_140 , V_135 ,
(struct V_26 * ) V_145 -> V_141 ,
& V_135 , & V_150 ) ;
switch ( V_40 )
{
case V_170 | V_171 :
if ( F_13 ( ( const struct V_26 * ) V_145 -> V_141 ) &&
V_43 -> V_67 . V_36 ) {
V_144 -> V_145 = V_145 ;
V_144 -> V_146 = V_43 ;
F_34 ( & V_43 -> V_78 ) ;
} else
F_29 ( V_145 ) ;
break;
case V_170 | V_172 :
F_29 ( V_145 ) ;
break;
case V_170 :
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
V_144 -> V_138 -> V_149 . V_153 . V_154 . V_119 = V_150 ;
V_144 -> V_173 = V_135 ;
}
F_34 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_28 ( & V_144 -> V_174 , & V_43 -> V_75 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
F_78 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_76 ) ;
V_40 = 1 ;
V_97:
return V_40 ;
}
static int F_79 ( int V_167 , int V_168 , T_8 V_135 )
{
int V_175 , V_176 ;
V_175 = V_135 - V_167 ;
if ( V_168 && V_175 ) {
V_176 = V_175 - V_168 % V_175 ;
return V_176 == V_175 ? 0 : V_176 ;
} else
return V_175 ;
}
static void F_80 ( struct V_137 * V_138 )
{
struct V_177 * V_178 , * V_179 ;
F_81 (s, t, &mad_send_wr->rmpp_list, list) {
F_44 ( & V_178 -> V_108 ) ;
F_29 ( V_178 ) ;
}
}
static int F_82 ( struct V_137 * V_149 ,
T_8 V_135 , T_9 V_180 )
{
struct V_110 * V_111 = & V_149 -> V_111 ;
struct V_181 * V_182 = V_111 -> V_141 ;
struct V_177 * V_183 = NULL ;
int V_184 , V_175 , V_176 ;
V_111 -> V_175 = V_135 - V_111 -> V_167 ;
V_111 -> V_185 = V_135 - V_186 ;
V_175 = V_111 -> V_175 ;
V_176 = V_149 -> V_176 ;
for ( V_184 = V_111 -> V_168 + V_176 ; V_184 > 0 ; V_184 -= V_175 ) {
V_183 = F_76 ( sizeof ( * V_183 ) + V_175 , V_180 ) ;
if ( ! V_183 ) {
F_67 ( & V_111 -> V_103 -> V_3 -> V_52 ,
L_18 ,
sizeof ( * V_183 ) + V_175 , V_180 ) ;
F_80 ( V_149 ) ;
return - V_65 ;
}
V_183 -> V_187 = ++ V_111 -> V_188 ;
F_28 ( & V_183 -> V_108 , & V_149 -> V_72 ) ;
}
if ( V_176 )
memset ( V_183 -> V_189 + V_175 - V_176 , 0 , V_176 ) ;
V_182 -> V_190 . V_34 = V_149 -> V_43 ->
V_67 . V_34 ;
V_182 -> V_190 . V_191 = V_192 ;
F_83 ( & V_182 -> V_190 , V_193 ) ;
V_149 -> V_194 = F_51 ( V_149 -> V_72 . V_195 ,
struct V_177 , V_108 ) ;
V_149 -> V_196 = V_149 -> V_194 ;
return 0 ;
}
int F_84 ( const struct V_33 * V_67 )
{
return V_67 -> V_34 && ! ( V_67 -> V_6 & V_59 ) ;
}
struct V_110 * F_85 ( struct V_33 * V_103 ,
T_4 V_197 , T_7 V_119 ,
int V_198 ,
int V_167 , int V_168 ,
T_9 V_180 ,
T_1 V_165 )
{
struct V_42 * V_43 ;
struct V_137 * V_138 ;
int V_176 , V_199 , V_40 , V_136 ;
void * V_200 ;
T_8 V_135 ;
bool V_152 ;
V_43 = F_51 ( V_103 , struct V_42 ,
V_67 ) ;
V_152 = F_63 ( V_103 -> V_3 , V_103 -> V_4 ) ;
if ( V_152 && V_165 == V_166 )
V_135 = sizeof( struct V_201 ) ;
else
V_135 = sizeof( struct V_127 ) ;
V_176 = F_79 ( V_167 , V_168 , V_135 ) ;
V_199 = V_167 + V_168 + V_176 ;
if ( F_84 ( V_103 ) ) {
if ( ! V_198 && V_199 > V_135 )
return F_15 ( - V_41 ) ;
} else
if ( V_198 || V_199 > V_135 )
return F_15 ( - V_41 ) ;
V_136 = V_198 ? V_167 : V_135 ;
V_200 = F_18 ( sizeof *V_138 + V_136 , V_180 ) ;
if ( ! V_200 )
return F_15 ( - V_65 ) ;
V_138 = V_200 + V_136 ;
F_21 ( & V_138 -> V_72 ) ;
V_138 -> V_111 . V_141 = V_200 ;
V_138 -> V_111 . V_167 = V_167 ;
V_138 -> V_111 . V_168 = V_168 ;
V_138 -> V_176 = V_176 ;
V_138 -> V_43 = V_43 ;
V_138 -> V_202 [ 0 ] . V_203 = V_167 ;
V_138 -> V_202 [ 0 ] . V_204 = V_103 -> V_62 -> V_205 -> V_206 ;
if ( V_152 && V_165 == V_166 &&
V_168 < V_135 - V_167 )
V_138 -> V_202 [ 1 ] . V_203 = V_168 ;
else
V_138 -> V_202 [ 1 ] . V_203 = V_135 - V_167 ;
V_138 -> V_202 [ 1 ] . V_204 = V_103 -> V_62 -> V_205 -> V_206 ;
V_138 -> V_149 . V_117 = ( unsigned long ) V_138 ;
V_138 -> V_149 . V_202 = V_138 -> V_202 ;
V_138 -> V_149 . V_207 = 2 ;
V_138 -> V_149 . V_124 = V_208 ;
V_138 -> V_149 . V_209 = V_210 ;
V_138 -> V_149 . V_153 . V_154 . V_197 = V_197 ;
V_138 -> V_149 . V_153 . V_154 . V_211 = V_212 ;
V_138 -> V_149 . V_153 . V_154 . V_119 = V_119 ;
if ( V_198 ) {
V_40 = F_82 ( V_138 , V_135 , V_180 ) ;
if ( V_40 ) {
F_29 ( V_200 ) ;
return F_15 ( V_40 ) ;
}
}
V_138 -> V_111 . V_103 = V_103 ;
F_34 ( & V_43 -> V_78 ) ;
return & V_138 -> V_111 ;
}
int F_86 ( T_1 V_8 )
{
if ( V_8 == V_213 )
return V_214 ;
else if ( ( V_8 == V_215 ) ||
( V_8 == V_216 ) ||
( V_8 == V_217 ) )
return V_218 ;
else if ( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) )
return V_219 ;
else
return V_220 ;
}
int F_17 ( T_1 V_8 )
{
if ( ( V_8 == V_213 ) ||
( V_8 == V_215 ) ||
( V_8 == V_216 ) ||
( V_8 == V_217 ) ||
( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) ) )
return 1 ;
return 0 ;
}
void * F_87 ( struct V_110 * V_111 , int V_221 )
{
struct V_137 * V_138 ;
struct V_222 * V_108 ;
V_138 = F_51 ( V_111 , struct V_137 ,
V_111 ) ;
V_108 = & V_138 -> V_194 -> V_108 ;
if ( V_138 -> V_194 -> V_187 < V_221 ) {
F_2 (mad_send_wr->cur_seg, list, list)
if ( V_138 -> V_194 -> V_187 == V_221 )
break;
} else if ( V_138 -> V_194 -> V_187 > V_221 ) {
F_88 (mad_send_wr->cur_seg, list, list)
if ( V_138 -> V_194 -> V_187 == V_221 )
break;
}
return V_138 -> V_194 -> V_189 ;
}
static inline void * F_89 ( struct V_137 * V_138 )
{
if ( V_138 -> V_111 . V_188 )
return F_87 ( & V_138 -> V_111 ,
V_138 -> V_221 ) ;
else
return V_138 -> V_111 . V_141 +
V_138 -> V_111 . V_167 ;
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
struct V_222 * V_108 ;
struct V_148 * V_223 ;
struct V_33 * V_103 ;
struct V_224 * V_225 ;
unsigned long V_6 ;
int V_40 ;
V_61 = V_138 -> V_43 -> V_61 ;
V_138 -> V_149 . V_117 = ( unsigned long ) & V_138 -> V_105 ;
V_138 -> V_105 . V_107 = & V_61 -> V_226 ;
V_103 = V_138 -> V_111 . V_103 ;
V_225 = V_138 -> V_202 ;
V_225 [ 0 ] . V_227 = F_92 ( V_103 -> V_3 ,
V_138 -> V_111 . V_141 ,
V_225 [ 0 ] . V_203 ,
V_228 ) ;
if ( F_93 ( F_94 ( V_103 -> V_3 , V_225 [ 0 ] . V_227 ) ) )
return - V_65 ;
V_138 -> V_229 = V_225 [ 0 ] . V_227 ;
V_225 [ 1 ] . V_227 = F_92 ( V_103 -> V_3 ,
F_89 ( V_138 ) ,
V_225 [ 1 ] . V_203 ,
V_228 ) ;
if ( F_93 ( F_94 ( V_103 -> V_3 , V_225 [ 1 ] . V_227 ) ) ) {
F_95 ( V_103 -> V_3 ,
V_138 -> V_229 ,
V_225 [ 0 ] . V_203 , V_228 ) ;
return - V_65 ;
}
V_138 -> V_230 = V_225 [ 1 ] . V_227 ;
F_4 ( & V_61 -> V_226 . V_68 , V_6 ) ;
if ( V_61 -> V_226 . V_109 < V_61 -> V_226 . V_231 ) {
V_40 = F_96 ( V_103 -> V_62 , & V_138 -> V_149 ,
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
V_225 [ 0 ] . V_203 , V_228 ) ;
F_95 ( V_103 -> V_3 ,
V_138 -> V_230 ,
V_225 [ 1 ] . V_203 , V_228 ) ;
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
V_234 = V_111 -> V_195 ;
V_138 -> V_149 . V_153 . V_154 . V_236 = V_111 -> V_236 ;
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
struct V_222 V_249 ;
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
if ( V_261 -> V_155 >= V_56 )
goto V_97;
if ( ! F_9 ( V_261 -> V_8 ) ) {
V_46 = V_39 -> V_83 [
V_261 -> V_155 ] . V_46 ;
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
V_261 -> V_155 ] . V_48 ;
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
if ( V_261 -> V_165 != V_266 &&
( ! V_152 || V_261 -> V_165 != V_166 ) ) {
F_105 ( L_27 ,
V_261 -> V_165 , V_152 ? L_28 : L_29 ) ;
goto V_97;
}
if ( ( V_261 -> V_8 == V_58 ) ||
( V_261 -> V_8 == V_9 ) ) {
if ( V_265 == 0 )
V_264 = 1 ;
} else {
if ( V_265 != 0 )
V_264 = 1 ;
}
V_97:
return V_264 ;
}
static int F_115 ( const struct V_42 * V_43 ,
const struct V_26 * V_261 )
{
struct V_181 * V_182 ;
V_182 = (struct V_181 * ) V_261 ;
return ! V_43 -> V_67 . V_34 ||
! F_84 ( & V_43 -> V_67 ) ||
! ( F_116 ( & V_182 -> V_190 ) &
V_193 ) ||
( V_182 -> V_190 . V_191 == V_192 ) ;
}
static inline int F_117 ( const struct V_137 * V_153 ,
const struct V_114 * V_267 )
{
return ( (struct V_26 * ) ( V_153 -> V_111 . V_141 ) ) -> V_8 ==
V_267 -> V_250 . V_141 -> V_261 . V_8 ;
}
static inline int F_118 ( const struct V_42 * V_43 ,
const struct V_137 * V_153 ,
const struct V_114 * V_267 )
{
struct V_268 V_269 ;
T_1 V_270 , V_271 ;
union V_272 V_273 ;
struct V_2 * V_3 = V_43 -> V_67 . V_3 ;
T_1 V_4 = V_43 -> V_67 . V_4 ;
T_1 V_274 ;
V_270 = F_13 ( (struct V_26 * ) V_153 -> V_111 . V_141 ) ;
V_271 = F_13 ( & V_267 -> V_250 . V_141 -> V_261 ) ;
if ( V_270 == V_271 )
return 0 ;
if ( F_119 ( V_153 -> V_111 . V_236 , & V_269 ) )
return 0 ;
if ( ! ! ( V_269 . V_275 & V_276 ) !=
! ! ( V_267 -> V_121 -> V_277 & V_278 ) )
return 0 ;
if ( ! V_270 && V_271 ) {
if ( ! ( V_269 . V_275 & V_276 ) ) {
if ( F_120 ( V_3 , V_4 , & V_274 ) )
return 0 ;
return ( ! V_274 || ! ( ( V_269 . V_279 ^
V_267 -> V_121 -> V_132 ) &
( ( 1 << V_274 ) - 1 ) ) ) ;
} else {
if ( F_121 ( V_3 , V_4 ,
V_269 . V_280 . V_281 , & V_273 ) )
return 0 ;
return ! memcmp ( V_273 . V_282 , V_267 -> V_250 . V_280 -> V_283 . V_282 ,
16 ) ;
}
}
if ( ! ( V_269 . V_275 & V_276 ) )
return V_269 . V_284 == V_267 -> V_121 -> V_118 ;
else
return ! memcmp ( V_269 . V_280 . V_283 . V_282 , V_267 -> V_250 . V_280 -> V_273 . V_282 ,
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
struct V_137 * V_153 ;
const struct V_26 * V_261 ;
V_261 = & V_121 -> V_250 . V_141 -> V_261 ;
F_2 (wr, &mad_agent_priv->wait_list, agent_list) {
if ( ( V_153 -> V_237 == V_261 -> V_237 ) &&
F_117 ( V_153 , V_121 ) &&
( F_122 ( V_261 -> V_8 ) ||
F_118 ( V_43 , V_153 , V_121 ) ) )
return ( V_153 -> V_122 == V_123 ) ? V_153 : NULL ;
}
F_2 (wr, &mad_agent_priv->send_list, agent_list) {
if ( F_115 ( V_43 , V_153 -> V_111 . V_141 ) &&
V_153 -> V_237 == V_261 -> V_237 &&
V_153 -> V_238 &&
F_117 ( V_153 , V_121 ) &&
( F_122 ( V_261 -> V_8 ) ||
F_118 ( V_43 , V_153 , V_121 ) ) )
return ( V_153 -> V_122 == V_123 ) ? V_153 : NULL ;
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
&& ( F_116 ( & ( (struct V_181 * ) V_115 -> V_250 . V_141 ) -> V_190 )
& V_193 ) ) {
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
V_113 . V_285 = 0 ;
V_113 . V_111 = & V_138 -> V_111 ;
F_129 ( V_138 , & V_113 ) ;
}
} else {
V_43 -> V_67 . V_36 ( & V_43 -> V_67 ,
V_115 ) ;
F_36 ( V_43 ) ;
}
}
static enum V_286 F_130 ( const struct V_1 * V_39 ,
const struct V_89 * V_61 ,
const struct V_120 * V_121 ,
int V_4 ,
struct V_133 * V_287 ,
struct V_133 * V_288 )
{
enum V_289 V_290 ;
struct V_139 * V_140 = (struct V_139 * ) V_287 -> V_141 ;
if ( F_131 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_291 ) ==
V_163 )
return V_163 ;
V_290 = F_132 ( V_140 ) ;
if ( V_290 == V_292 )
return V_293 ;
if ( V_290 == V_294 ) {
if ( F_72 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ) == V_163 )
return V_163 ;
if ( F_74 ( V_140 , V_39 -> V_3 ) == V_163 )
return V_163 ;
} else if ( F_64 ( V_39 -> V_3 ) ) {
memcpy ( V_288 , V_287 , F_57 ( V_288 ) ) ;
V_288 -> V_252 . V_251 . V_121 = & V_288 -> V_252 . V_121 ;
V_288 -> V_252 . V_251 . V_250 . V_141 = (struct V_127 * ) V_288 -> V_141 ;
V_288 -> V_252 . V_251 . V_250 . V_280 = & V_288 -> V_280 ;
F_133 ( ( const struct V_26 * ) V_288 -> V_141 ,
& V_288 -> V_280 , V_121 ,
V_39 -> V_3 ,
F_134 ( V_140 ) ,
V_61 -> V_62 -> V_265 ,
V_288 -> V_135 ,
false ) ;
return V_163 ;
}
return V_293 ;
}
static bool F_135 ( const struct V_133 * V_287 ,
struct V_133 * V_288 ,
T_8 * V_295 , bool V_152 )
{
const struct V_26 * V_296 = ( const struct V_26 * ) V_287 -> V_141 ;
struct V_26 * V_297 = (struct V_26 * ) V_288 -> V_141 ;
if ( V_296 -> V_22 == V_298 ||
V_296 -> V_22 == V_299 ) {
memcpy ( V_288 , V_287 , F_57 ( V_288 ) ) ;
V_288 -> V_252 . V_251 . V_121 = & V_288 -> V_252 . V_121 ;
V_288 -> V_252 . V_251 . V_250 . V_141 = (struct V_127 * ) V_288 -> V_141 ;
V_288 -> V_252 . V_251 . V_250 . V_280 = & V_288 -> V_280 ;
V_297 -> V_22 = V_300 ;
V_297 -> V_122 = F_136 ( V_301 ) ;
if ( V_296 -> V_8 == V_9 )
V_297 -> V_122 |= V_302 ;
if ( V_152 && V_296 -> V_165 == V_166 ) {
if ( V_296 -> V_8 ==
V_58 ||
V_296 -> V_8 ==
V_9 )
* V_295 = F_137 (
(struct V_142 * ) V_287 -> V_141 ) ;
else
* V_295 = sizeof( struct V_26 ) ;
}
return true ;
} else {
return false ;
}
}
static enum V_286
F_138 ( struct V_1 * V_39 ,
struct V_89 * V_61 ,
struct V_120 * V_121 ,
int V_4 ,
struct V_133 * V_287 ,
struct V_133 * V_288 )
{
enum V_289 V_290 ;
struct V_142 * V_140 = (struct V_142 * ) V_287 -> V_141 ;
if ( F_139 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_291 ) ==
V_163 )
return V_163 ;
V_290 = F_140 ( V_140 ) ;
if ( V_290 == V_292 )
return V_293 ;
if ( V_290 == V_294 ) {
if ( F_66 ( V_140 ,
F_64 ( V_39 -> V_3 ) ,
V_4 ) == V_163 )
return V_163 ;
if ( F_69 ( V_140 , V_39 -> V_3 ) ==
V_163 )
return V_163 ;
} else if ( F_64 ( V_39 -> V_3 ) ) {
memcpy ( V_288 , V_287 , F_57 ( V_288 ) ) ;
V_288 -> V_252 . V_251 . V_121 = & V_288 -> V_252 . V_121 ;
V_288 -> V_252 . V_251 . V_250 . V_201 =
(struct V_201 * ) V_288 -> V_141 ;
V_288 -> V_252 . V_251 . V_250 . V_280 = & V_288 -> V_280 ;
F_133 ( ( const struct V_26 * ) V_288 -> V_141 ,
& V_288 -> V_280 , V_121 ,
V_39 -> V_3 ,
F_141 ( V_140 ) ,
V_61 -> V_62 -> V_265 ,
V_287 -> V_252 . V_121 . V_126 ,
true ) ;
return V_163 ;
}
return V_293 ;
}
static enum V_286
F_142 ( struct V_1 * V_39 ,
struct V_89 * V_61 ,
struct V_120 * V_121 ,
int V_4 ,
struct V_133 * V_287 ,
struct V_133 * V_288 ,
bool V_152 )
{
struct V_26 * V_261 = (struct V_26 * ) V_287 -> V_141 ;
if ( V_152 && V_261 -> V_165 == V_166 &&
V_261 -> V_155 == V_303 )
return F_138 ( V_39 , V_61 , V_121 , V_4 , V_287 ,
V_288 ) ;
return F_130 ( V_39 , V_61 , V_121 , V_4 , V_287 , V_288 ) ;
}
static void F_143 ( struct V_1 * V_39 ,
struct V_120 * V_121 )
{
struct V_89 * V_61 ;
struct V_246 * V_247 ;
struct V_133 * V_287 , * V_288 = NULL ;
struct V_104 * V_105 ;
struct V_42 * V_103 ;
int V_4 ;
int V_40 = V_170 ;
T_8 V_135 ;
T_7 V_304 = 0 ;
bool V_152 ;
V_105 = (struct V_104 * ) ( unsigned long ) V_121 -> V_117 ;
V_61 = V_105 -> V_107 -> V_61 ;
F_52 ( V_105 ) ;
V_152 = F_63 ( V_61 -> V_39 -> V_3 ,
V_61 -> V_39 -> V_4 ) ;
V_247 = F_51 ( V_105 , struct V_246 ,
V_105 ) ;
V_287 = F_51 ( V_247 , struct V_133 , V_252 ) ;
F_95 ( V_39 -> V_3 ,
V_287 -> V_252 . V_305 ,
F_61 ( V_287 ) ,
V_306 ) ;
V_287 -> V_252 . V_121 = * V_121 ;
V_287 -> V_252 . V_251 . V_121 = & V_287 -> V_252 . V_121 ;
if ( V_152 && ( (struct V_26 * ) ( V_287 -> V_141 ) ) -> V_165 == V_166 ) {
V_287 -> V_252 . V_251 . V_307 = V_121 -> V_126 - sizeof( struct V_128 ) ;
V_287 -> V_252 . V_251 . V_308 = sizeof( struct V_201 ) ;
} else {
V_287 -> V_252 . V_251 . V_307 = sizeof( struct V_127 ) ;
V_287 -> V_252 . V_251 . V_308 = sizeof( struct V_127 ) ;
}
V_287 -> V_252 . V_251 . V_250 . V_141 = (struct V_127 * ) V_287 -> V_141 ;
V_287 -> V_252 . V_251 . V_250 . V_280 = & V_287 -> V_280 ;
if ( F_144 ( & V_61 -> V_98 ) )
F_55 ( V_61 , & V_287 -> V_252 . V_251 , V_88 ) ;
if ( ! F_114 ( ( const struct V_26 * ) V_287 -> V_141 , V_61 , V_152 ) )
goto V_97;
V_135 = V_287 -> V_135 ;
V_288 = F_58 ( V_135 , V_64 ) ;
if ( ! V_288 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_30 ) ;
goto V_97;
}
if ( F_64 ( V_39 -> V_3 ) )
V_4 = V_121 -> V_4 ;
else
V_4 = V_39 -> V_4 ;
if ( ( (struct V_26 * ) V_287 -> V_141 ) -> V_8 ==
V_9 ) {
if ( F_142 ( V_39 , V_61 , V_121 , V_4 , V_287 ,
V_288 , V_152 )
== V_163 )
goto V_97;
}
if ( V_39 -> V_3 -> V_169 ) {
V_40 = V_39 -> V_3 -> V_169 ( V_39 -> V_3 , 0 ,
V_39 -> V_4 ,
V_121 , & V_287 -> V_280 ,
( const struct V_26 * ) V_287 -> V_141 ,
V_287 -> V_135 ,
(struct V_26 * ) V_288 -> V_141 ,
& V_135 , & V_304 ) ;
if ( V_152 )
V_121 -> V_119 = V_304 ;
if ( V_40 & V_170 ) {
if ( V_40 & V_172 )
goto V_97;
if ( V_40 & V_171 ) {
F_133 ( ( const struct V_26 * ) V_288 -> V_141 ,
& V_287 -> V_280 , V_121 ,
V_39 -> V_3 ,
V_4 ,
V_61 -> V_62 -> V_265 ,
V_135 , V_152 ) ;
goto V_97;
}
}
}
V_103 = F_77 ( V_39 , ( const struct V_26 * ) V_287 -> V_141 ) ;
if ( V_103 ) {
F_126 ( V_103 , & V_287 -> V_252 . V_251 ) ;
V_287 = NULL ;
} else if ( ( V_40 & V_170 ) &&
F_135 ( V_287 , V_288 , & V_135 , V_152 ) ) {
F_133 ( ( const struct V_26 * ) V_288 -> V_141 , & V_287 -> V_280 , V_121 ,
V_39 -> V_3 , V_4 ,
V_61 -> V_62 -> V_265 , V_135 , V_152 ) ;
}
V_97:
if ( V_288 ) {
F_145 ( V_61 , V_288 ) ;
F_29 ( V_287 ) ;
} else
F_145 ( V_61 , V_287 ) ;
}
static void F_146 ( struct V_42 * V_43 )
{
struct V_137 * V_138 ;
unsigned long V_309 ;
if ( F_147 ( & V_43 -> V_70 ) ) {
F_42 ( & V_43 -> V_73 ) ;
} else {
V_138 = F_148 ( V_43 -> V_70 . V_195 ,
struct V_137 ,
V_85 ) ;
if ( F_149 ( V_43 -> V_238 ,
V_138 -> V_238 ) ) {
V_43 -> V_238 = V_138 -> V_238 ;
V_309 = V_138 -> V_238 - V_310 ;
if ( ( long ) V_309 <= 0 )
V_309 = 1 ;
F_150 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_73 , V_309 ) ;
}
}
}
static void F_151 ( struct V_137 * V_138 )
{
struct V_42 * V_43 ;
struct V_137 * V_311 ;
struct V_222 * V_312 ;
unsigned long V_309 ;
V_43 = V_138 -> V_43 ;
F_44 ( & V_138 -> V_85 ) ;
V_309 = V_138 -> V_238 ;
V_138 -> V_238 += V_310 ;
if ( V_309 ) {
F_152 (list_item, &mad_agent_priv->wait_list) {
V_311 = F_148 ( V_312 ,
struct V_137 ,
V_85 ) ;
if ( F_149 ( V_138 -> V_238 ,
V_311 -> V_238 ) )
break;
}
}
else
V_312 = & V_43 -> V_70 ;
F_127 ( & V_138 -> V_85 , V_312 ) ;
if ( V_43 -> V_70 . V_195 == & V_138 -> V_85 )
F_150 ( V_43 -> V_61 -> V_39 -> V_102 ,
& V_43 -> V_73 , V_309 ) ;
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
goto V_313;
} else
V_40 = V_314 ;
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
goto V_313;
}
F_44 ( & V_138 -> V_85 ) ;
F_146 ( V_43 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_138 -> V_122 != V_123 )
V_113 -> V_122 = V_138 -> V_122 ;
if ( V_40 == V_315 )
F_155 ( V_113 ) ;
else
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
V_113 ) ;
F_36 ( V_43 ) ;
return;
V_313:
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static void F_156 ( struct V_1 * V_39 ,
struct V_120 * V_121 )
{
struct V_137 * V_138 , * V_316 ;
struct V_104 * V_105 ;
struct V_89 * V_61 ;
struct V_106 * V_226 ;
struct V_148 * V_223 ;
struct V_112 V_113 ;
unsigned long V_6 ;
int V_40 ;
V_105 = (struct V_104 * ) ( unsigned long ) V_121 -> V_117 ;
V_138 = F_51 ( V_105 , struct V_137 ,
V_105 ) ;
V_226 = V_105 -> V_107 ;
V_61 = V_226 -> V_61 ;
V_317:
F_95 ( V_138 -> V_111 . V_103 -> V_3 ,
V_138 -> V_229 ,
V_138 -> V_202 [ 0 ] . V_203 , V_228 ) ;
F_95 ( V_138 -> V_111 . V_103 -> V_3 ,
V_138 -> V_230 ,
V_138 -> V_202 [ 1 ] . V_203 , V_228 ) ;
V_316 = NULL ;
F_4 ( & V_226 -> V_68 , V_6 ) ;
F_44 ( & V_105 -> V_108 ) ;
if ( V_226 -> V_109 -- > V_226 -> V_231 ) {
V_105 = F_51 ( V_61 -> V_232 . V_195 ,
struct V_104 , V_108 ) ;
V_316 = F_51 ( V_105 ,
struct V_137 ,
V_105 ) ;
F_125 ( & V_105 -> V_108 , & V_226 -> V_108 ) ;
}
F_5 ( & V_226 -> V_68 , V_6 ) ;
V_113 . V_111 = & V_138 -> V_111 ;
V_113 . V_122 = V_121 -> V_122 ;
V_113 . V_285 = V_121 -> V_285 ;
if ( F_144 ( & V_61 -> V_98 ) )
F_54 ( V_61 , & V_138 -> V_111 , & V_113 ,
V_87 ) ;
F_129 ( V_138 , & V_113 ) ;
if ( V_316 ) {
V_40 = F_96 ( V_61 -> V_62 , & V_316 -> V_149 ,
& V_223 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_31 , V_40 ) ;
V_138 = V_316 ;
V_121 -> V_122 = V_318 ;
goto V_317;
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
V_138 -> V_317 = 1 ;
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
if ( V_105 -> V_107 == & V_61 -> V_319 )
return;
V_138 = F_51 ( V_105 , struct V_137 ,
V_105 ) ;
if ( V_121 -> V_122 == V_320 ) {
if ( V_138 -> V_317 ) {
struct V_148 * V_223 ;
V_138 -> V_317 = 0 ;
V_40 = F_96 ( V_61 -> V_62 , & V_138 -> V_149 ,
& V_223 ) ;
if ( V_40 )
F_156 ( V_39 , V_121 ) ;
} else
F_156 ( V_39 , V_121 ) ;
} else {
struct V_321 * V_269 ;
V_269 = F_76 ( sizeof *V_269 , V_64 ) ;
if ( V_269 ) {
V_269 -> V_322 = V_323 ;
V_269 -> V_324 = V_325 ;
V_40 = F_159 ( V_61 -> V_62 , V_269 ,
V_326 | V_327 ) ;
F_29 ( V_269 ) ;
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
static void F_160 ( struct V_328 * V_329 )
{
struct V_1 * V_39 ;
struct V_120 V_121 ;
V_39 = F_51 ( V_329 , struct V_1 , V_329 ) ;
F_161 ( V_39 -> V_330 , V_331 ) ;
while ( F_162 ( V_39 -> V_330 , 1 , & V_121 ) == 1 ) {
if ( V_121 . V_122 == V_123 ) {
switch ( V_121 . V_124 ) {
case V_332 :
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
struct V_137 * V_138 , * V_311 ;
struct V_112 V_113 ;
struct V_222 V_333 ;
F_21 ( & V_333 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_81 (mad_send_wr, temp_mad_send_wr,
&mad_agent_priv->send_list, agent_list) {
if ( V_138 -> V_122 == V_123 ) {
V_138 -> V_122 = V_320 ;
V_138 -> V_78 -= ( V_138 -> V_238 > 0 ) ;
}
}
F_101 ( & V_43 -> V_70 , & V_333 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_113 . V_122 = V_320 ;
V_113 . V_285 = 0 ;
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
int V_334 ;
V_43 = F_51 ( V_103 , struct V_42 ,
V_67 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
V_138 = F_163 ( V_43 , V_111 ) ;
if ( ! V_138 || V_138 -> V_122 != V_123 ) {
F_5 ( & V_43 -> V_68 , V_6 ) ;
return - V_41 ;
}
V_334 = ( ! V_138 -> V_238 || V_138 -> V_78 > 1 ) ;
if ( ! V_235 ) {
V_138 -> V_122 = V_320 ;
V_138 -> V_78 -= ( V_138 -> V_238 > 0 ) ;
}
V_138 -> V_111 . V_235 = V_235 ;
if ( V_334 )
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
static void V_77 ( struct V_328 * V_329 )
{
struct V_42 * V_43 ;
struct V_143 * V_144 ;
struct V_42 * V_146 ;
unsigned long V_6 ;
int V_335 ;
struct V_120 V_121 ;
struct V_112 V_113 ;
bool V_152 ;
V_43 =
F_51 ( V_329 , struct V_42 , V_76 ) ;
V_152 = F_63 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_147 ( & V_43 -> V_75 ) ) {
V_144 = F_148 ( V_43 -> V_75 . V_195 ,
struct V_143 ,
V_174 ) ;
F_44 ( & V_144 -> V_174 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_335 = 0 ;
if ( V_144 -> V_145 ) {
T_1 V_165 ;
V_146 = V_144 -> V_146 ;
if ( ! V_146 ) {
F_67 ( & V_43 -> V_67 . V_3 -> V_52 ,
L_33 ) ;
V_335 = 1 ;
goto V_336;
}
F_56 ( V_146 -> V_67 . V_62 ,
( unsigned long ) V_144 -> V_138 ,
F_73 ( V_164 ) ,
V_144 -> V_138 -> V_149 . V_153 . V_154 . V_119 ,
V_146 -> V_67 . V_4 , & V_121 ) ;
V_144 -> V_145 -> V_252 . V_251 . V_121 = & V_121 ;
V_165 = ( (struct V_26 * ) ( V_144 -> V_145 -> V_141 ) ) -> V_165 ;
if ( V_152 && V_165 == V_166 ) {
V_144 -> V_145 -> V_252 . V_251 . V_307 = V_144 -> V_173 ;
V_144 -> V_145 -> V_252 . V_251 . V_308 = sizeof( struct V_201 ) ;
} else {
V_144 -> V_145 -> V_252 . V_251 . V_307 = sizeof( struct V_127 ) ;
V_144 -> V_145 -> V_252 . V_251 . V_308 = sizeof( struct V_127 ) ;
}
F_21 ( & V_144 -> V_145 -> V_252 . V_251 . V_72 ) ;
F_127 ( & V_144 -> V_145 -> V_252 . V_251 . V_250 . V_108 ,
& V_144 -> V_145 -> V_252 . V_251 . V_72 ) ;
V_144 -> V_145 -> V_252 . V_251 . V_250 . V_280 = NULL ;
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
V_336:
V_113 . V_122 = V_123 ;
V_113 . V_285 = 0 ;
V_113 . V_111 = & V_144 -> V_138 -> V_111 ;
if ( F_144 ( & V_43 -> V_61 -> V_98 ) )
F_54 ( V_43 -> V_61 ,
& V_144 -> V_138 -> V_111 ,
& V_113 , V_87 ) ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_113 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_49 ( & V_43 -> V_78 ) ;
if ( V_335 )
F_29 ( V_144 -> V_145 ) ;
F_29 ( V_144 ) ;
}
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static int F_166 ( struct V_137 * V_138 )
{
int V_40 ;
if ( ! V_138 -> V_241 )
return - V_337 ;
V_138 -> V_241 -- ;
V_138 -> V_111 . V_240 ++ ;
V_138 -> V_238 = F_98 ( V_138 -> V_111 . V_235 ) ;
if ( F_84 ( & V_138 -> V_43 -> V_67 ) ) {
V_40 = F_167 ( V_138 ) ;
switch ( V_40 ) {
case V_314 :
V_40 = F_91 ( V_138 ) ;
break;
case V_242 :
V_40 = 0 ;
break;
default:
V_40 = - V_338 ;
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
static void V_74 ( struct V_328 * V_329 )
{
struct V_42 * V_43 ;
struct V_137 * V_138 ;
struct V_112 V_113 ;
unsigned long V_6 , V_309 ;
V_43 = F_51 ( V_329 , struct V_42 ,
V_73 . V_329 ) ;
V_113 . V_285 = 0 ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_147 ( & V_43 -> V_70 ) ) {
V_138 = F_148 ( V_43 -> V_70 . V_195 ,
struct V_137 ,
V_85 ) ;
if ( F_149 ( V_138 -> V_238 , V_310 ) ) {
V_309 = V_138 -> V_238 - V_310 ;
if ( ( long ) V_309 <= 0 )
V_309 = 1 ;
F_168 ( V_43 -> V_61 ->
V_39 -> V_102 ,
& V_43 -> V_73 , V_309 ) ;
break;
}
F_44 ( & V_138 -> V_85 ) ;
if ( V_138 -> V_122 == V_123 &&
! F_166 ( V_138 ) )
continue;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_138 -> V_122 == V_123 )
V_113 . V_122 = V_339 ;
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
static void F_169 ( struct V_340 * V_330 , void * V_341 )
{
struct V_1 * V_39 = V_330 -> V_342 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
if ( ! F_147 ( & V_39 -> V_343 ) )
F_78 ( V_39 -> V_102 , & V_39 -> V_329 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static int F_145 ( struct V_89 * V_61 ,
struct V_133 * V_141 )
{
unsigned long V_6 ;
int V_344 , V_40 ;
struct V_133 * V_145 ;
struct V_224 V_202 ;
struct V_345 V_346 , * V_347 ;
struct V_106 * V_319 = & V_61 -> V_319 ;
V_202 . V_204 = V_61 -> V_39 -> V_205 -> V_206 ;
V_346 . V_195 = NULL ;
V_346 . V_202 = & V_202 ;
V_346 . V_207 = 1 ;
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
V_202 . V_203 = F_61 ( V_145 ) ;
V_202 . V_227 = F_92 ( V_61 -> V_39 -> V_3 ,
& V_145 -> V_280 ,
F_61 ( V_145 ) ,
V_306 ) ;
if ( F_93 ( F_94 ( V_61 -> V_39 -> V_3 ,
V_202 . V_227 ) ) ) {
V_40 = - V_65 ;
break;
}
V_145 -> V_252 . V_305 = V_202 . V_227 ;
V_346 . V_117 = ( unsigned long ) & V_145 -> V_252 . V_105 ;
V_145 -> V_252 . V_105 . V_107 = V_319 ;
F_4 ( & V_319 -> V_68 , V_6 ) ;
V_344 = ( ++ V_319 -> V_109 < V_319 -> V_231 ) ;
F_28 ( & V_145 -> V_252 . V_105 . V_108 , & V_319 -> V_108 ) ;
F_5 ( & V_319 -> V_68 , V_6 ) ;
V_40 = F_170 ( V_61 -> V_62 , & V_346 , & V_347 ) ;
if ( V_40 ) {
F_4 ( & V_319 -> V_68 , V_6 ) ;
F_44 ( & V_145 -> V_252 . V_105 . V_108 ) ;
V_319 -> V_109 -- ;
F_5 ( & V_319 -> V_68 , V_6 ) ;
F_95 ( V_61 -> V_39 -> V_3 ,
V_145 -> V_252 . V_305 ,
F_61 ( V_145 ) ,
V_306 ) ;
F_29 ( V_145 ) ;
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_35 , V_40 ) ;
break;
}
} while ( V_344 );
return V_40 ;
}
static void F_171 ( struct V_89 * V_61 )
{
struct V_246 * V_247 ;
struct V_133 * V_287 ;
struct V_104 * V_105 ;
if ( ! V_61 -> V_62 )
return;
while ( ! F_147 ( & V_61 -> V_319 . V_108 ) ) {
V_105 = F_148 ( V_61 -> V_319 . V_108 . V_195 ,
struct V_104 , V_108 ) ;
V_247 = F_51 ( V_105 ,
struct V_246 ,
V_105 ) ;
V_287 = F_51 ( V_247 , struct V_133 ,
V_252 ) ;
F_44 ( & V_105 -> V_108 ) ;
F_95 ( V_61 -> V_39 -> V_3 ,
V_287 -> V_252 . V_305 ,
F_61 ( V_287 ) ,
V_306 ) ;
F_29 ( V_287 ) ;
}
V_61 -> V_319 . V_109 = 0 ;
}
static int F_172 ( struct V_1 * V_39 )
{
int V_40 , V_23 ;
struct V_321 * V_269 ;
struct V_116 * V_62 ;
T_7 V_119 ;
V_269 = F_76 ( sizeof *V_269 , V_64 ) ;
if ( ! V_269 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_36 ) ;
return - V_65 ;
}
V_40 = F_173 ( V_39 -> V_3 , V_39 -> V_4 ,
V_348 , & V_119 ) ;
if ( V_40 )
V_119 = 0 ;
for ( V_23 = 0 ; V_23 < V_349 ; V_23 ++ ) {
V_62 = V_39 -> V_61 [ V_23 ] . V_62 ;
if ( ! V_62 )
continue;
V_269 -> V_322 = V_350 ;
V_269 -> V_119 = V_119 ;
V_269 -> V_351 = ( V_62 -> V_265 == 0 ) ? 0 : V_352 ;
V_40 = F_159 ( V_62 , V_269 , V_326 |
V_353 | V_354 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_37 ,
V_23 , V_40 ) ;
goto V_97;
}
V_269 -> V_322 = V_355 ;
V_40 = F_159 ( V_62 , V_269 , V_326 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_38 ,
V_23 , V_40 ) ;
goto V_97;
}
V_269 -> V_322 = V_323 ;
V_269 -> V_356 = V_357 ;
V_40 = F_159 ( V_62 , V_269 , V_326 | V_358 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_39 ,
V_23 , V_40 ) ;
goto V_97;
}
}
V_40 = F_161 ( V_39 -> V_330 , V_331 ) ;
if ( V_40 ) {
F_67 ( & V_39 -> V_3 -> V_52 ,
L_40 ,
V_40 ) ;
goto V_97;
}
for ( V_23 = 0 ; V_23 < V_349 ; V_23 ++ ) {
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
F_29 ( V_269 ) ;
return V_40 ;
}
static void F_174 ( struct V_359 * V_360 , void * V_361 )
{
struct V_89 * V_61 = V_361 ;
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_42 ,
V_360 -> V_360 , V_61 -> V_62 -> V_265 ) ;
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
F_175 ( V_61 , & V_61 -> V_319 ) ;
F_21 ( & V_61 -> V_232 ) ;
F_20 ( & V_61 -> V_93 ) ;
V_61 -> V_95 = NULL ;
V_61 -> V_94 = 0 ;
F_24 ( & V_61 -> V_98 , 0 ) ;
}
static int F_177 ( struct V_89 * V_61 ,
enum V_10 V_11 )
{
struct V_362 V_363 ;
int V_40 ;
memset ( & V_363 , 0 , sizeof V_363 ) ;
V_363 . V_364 = V_61 -> V_39 -> V_330 ;
V_363 . V_365 = V_61 -> V_39 -> V_330 ;
V_363 . V_366 = V_367 ;
V_363 . V_368 . V_369 = V_370 ;
V_363 . V_368 . V_371 = V_372 ;
V_363 . V_368 . V_373 = V_374 ;
V_363 . V_368 . V_375 = V_376 ;
V_363 . V_11 = V_11 ;
V_363 . V_4 = V_61 -> V_39 -> V_4 ;
V_363 . V_361 = V_61 ;
V_363 . V_377 = F_174 ;
V_61 -> V_62 = F_178 ( V_61 -> V_39 -> V_205 , & V_363 ) ;
if ( F_179 ( V_61 -> V_62 ) ) {
F_67 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_43 ,
F_7 ( V_11 ) ) ;
V_40 = F_180 ( V_61 -> V_62 ) ;
goto error;
}
V_61 -> V_226 . V_231 = V_370 ;
V_61 -> V_319 . V_231 = V_372 ;
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
int V_40 , V_378 ;
struct V_1 * V_39 ;
unsigned long V_6 ;
char V_379 [ sizeof "ib_mad123"];
int V_380 ;
struct V_381 V_382 = {} ;
if ( F_184 ( F_60 ( V_3 , V_4 ) < V_383 ) )
return - V_384 ;
if ( F_184 ( F_63 ( V_3 , V_4 ) &&
F_60 ( V_3 , V_4 ) < V_385 ) )
return - V_384 ;
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
V_378 = V_370 + V_372 ;
V_380 = F_185 ( V_3 , V_4 ) ;
if ( V_380 )
V_378 *= 2 ;
V_382 . V_386 = V_378 ;
V_39 -> V_330 = F_186 ( V_39 -> V_3 ,
F_169 ,
NULL , V_39 , & V_382 ) ;
if ( F_179 ( V_39 -> V_330 ) ) {
F_67 ( & V_3 -> V_52 , L_45 ) ;
V_40 = F_180 ( V_39 -> V_330 ) ;
goto V_66;
}
V_39 -> V_205 = F_187 ( V_3 ) ;
if ( F_179 ( V_39 -> V_205 ) ) {
F_67 ( & V_3 -> V_52 , L_46 ) ;
V_40 = F_180 ( V_39 -> V_205 ) ;
goto V_84;
}
if ( V_380 ) {
V_40 = F_177 ( & V_39 -> V_61 [ 0 ] , V_12 ) ;
if ( V_40 )
goto V_387;
}
V_40 = F_177 ( & V_39 -> V_61 [ 1 ] , V_13 ) ;
if ( V_40 )
goto V_388;
snprintf ( V_379 , sizeof V_379 , L_47 , V_4 ) ;
V_39 -> V_102 = F_188 ( V_379 ) ;
if ( ! V_39 -> V_102 ) {
V_40 = - V_65 ;
goto V_389;
}
F_23 ( & V_39 -> V_329 , F_160 ) ;
F_4 ( & V_7 , V_6 ) ;
F_28 ( & V_39 -> V_343 , & V_390 ) ;
F_5 ( & V_7 , V_6 ) ;
V_40 = F_172 ( V_39 ) ;
if ( V_40 ) {
F_67 ( & V_3 -> V_52 , L_48 ) ;
goto V_391;
}
return 0 ;
V_391:
F_4 ( & V_7 , V_6 ) ;
F_189 ( & V_39 -> V_343 ) ;
F_5 ( & V_7 , V_6 ) ;
F_190 ( V_39 -> V_102 ) ;
V_389:
F_181 ( & V_39 -> V_61 [ 1 ] ) ;
V_388:
F_181 ( & V_39 -> V_61 [ 0 ] ) ;
V_387:
F_191 ( V_39 -> V_205 ) ;
V_84:
F_192 ( V_39 -> V_330 ) ;
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
F_189 ( & V_39 -> V_343 ) ;
F_5 ( & V_7 , V_6 ) ;
F_190 ( V_39 -> V_102 ) ;
F_181 ( & V_39 -> V_61 [ 1 ] ) ;
F_181 ( & V_39 -> V_61 [ 0 ] ) ;
F_191 ( V_39 -> V_205 ) ;
F_192 ( V_39 -> V_330 ) ;
F_171 ( & V_39 -> V_61 [ 1 ] ) ;
F_171 ( & V_39 -> V_61 [ 0 ] ) ;
F_29 ( V_39 ) ;
return 0 ;
}
static void F_194 ( struct V_2 * V_3 )
{
int V_392 , V_23 ;
V_392 = F_195 ( V_3 ) ;
for ( V_23 = V_392 ; V_23 <= F_196 ( V_3 ) ; V_23 ++ ) {
if ( ! F_197 ( V_3 , V_23 ) )
continue;
if ( F_183 ( V_3 , V_23 ) ) {
F_67 ( & V_3 -> V_52 , L_50 , V_23 ) ;
goto error;
}
if ( F_198 ( V_3 , V_23 ) ) {
F_67 ( & V_3 -> V_52 ,
L_51 , V_23 ) ;
goto V_393;
}
}
return;
V_393:
if ( F_193 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_52 , V_23 ) ;
error:
while ( -- V_23 >= V_392 ) {
if ( ! F_197 ( V_3 , V_23 ) )
continue;
if ( F_199 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 ,
L_53 , V_23 ) ;
if ( F_193 ( V_3 , V_23 ) )
F_67 ( & V_3 -> V_52 , L_52 , V_23 ) ;
}
}
static void F_200 ( struct V_2 * V_3 , void * V_394 )
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
V_372 = F_202 ( V_372 , V_395 ) ;
V_372 = F_203 ( V_372 , V_396 ) ;
V_370 = F_202 ( V_370 , V_395 ) ;
V_370 = F_203 ( V_370 , V_396 ) ;
F_21 ( & V_390 ) ;
if ( F_204 ( & V_397 ) ) {
F_105 ( L_54 ) ;
return - V_41 ;
}
return 0 ;
}
static void T_11 F_205 ( void )
{
F_206 ( & V_397 ) ;
}
