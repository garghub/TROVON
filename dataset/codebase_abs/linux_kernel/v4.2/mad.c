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
V_43 -> V_66 . V_67 = F_19 ( V_39 -> V_61 [ V_50 ] . V_62 -> V_68 ,
V_69 ) ;
if ( F_20 ( V_43 -> V_66 . V_67 ) ) {
V_40 = F_15 ( - V_65 ) ;
goto V_70;
}
if ( V_20 ) {
V_44 = F_21 ( V_20 , sizeof *V_44 , V_64 ) ;
if ( ! V_44 ) {
V_40 = F_15 ( - V_65 ) ;
goto V_71;
}
}
V_43 -> V_61 = & V_39 -> V_61 [ V_50 ] ;
V_43 -> V_44 = V_44 ;
V_43 -> V_66 . V_34 = V_34 ;
V_43 -> V_66 . V_3 = V_3 ;
V_43 -> V_66 . V_36 = V_36 ;
V_43 -> V_66 . V_35 = V_35 ;
V_43 -> V_66 . V_37 = V_37 ;
V_43 -> V_66 . V_62 = V_39 -> V_61 [ V_50 ] . V_62 ;
V_43 -> V_66 . V_4 = V_4 ;
V_43 -> V_66 . V_6 = V_38 ;
F_22 ( & V_43 -> V_72 ) ;
F_23 ( & V_43 -> V_73 ) ;
F_23 ( & V_43 -> V_74 ) ;
F_23 ( & V_43 -> V_75 ) ;
F_23 ( & V_43 -> V_76 ) ;
F_24 ( & V_43 -> V_77 , V_78 ) ;
F_23 ( & V_43 -> V_79 ) ;
F_25 ( & V_43 -> V_80 , V_81 ) ;
F_26 ( & V_43 -> V_82 , 1 ) ;
F_27 ( & V_43 -> V_83 ) ;
F_4 ( & V_39 -> V_84 , V_6 ) ;
V_43 -> V_66 . V_85 = ++ V_86 ;
if ( V_20 ) {
V_8 = F_6 ( V_20 -> V_8 ) ;
if ( ! F_9 ( V_8 ) ) {
V_46 = V_39 -> V_87 [ V_20 ->
V_55 ] . V_46 ;
if ( V_46 ) {
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
if ( F_12 ( & V_22 ,
V_20 ) )
goto V_88;
}
}
V_49 = F_28 ( V_20 , V_43 ,
V_8 ) ;
} else {
V_48 = V_39 -> V_87 [ V_20 ->
V_55 ] . V_48 ;
if ( V_48 ) {
V_51 = F_8 ( V_8 ) ;
V_18 = V_48 -> V_18 [ V_51 ] ;
if ( V_18 ) {
if ( F_11 (
V_18 ,
V_20 ) )
goto V_88;
}
}
V_49 = F_29 ( V_20 , V_43 ) ;
}
if ( V_49 ) {
V_40 = F_15 ( V_49 ) ;
goto V_88;
}
}
F_30 ( & V_43 -> V_89 , & V_39 -> V_89 ) ;
F_5 ( & V_39 -> V_84 , V_6 ) ;
return & V_43 -> V_66 ;
V_88:
F_5 ( & V_39 -> V_84 , V_6 ) ;
F_31 ( V_44 ) ;
V_71:
F_32 ( V_43 -> V_66 . V_67 ) ;
V_70:
F_31 ( V_43 ) ;
V_53:
return V_40 ;
}
static inline int F_33 ( int V_90 )
{
return ( V_90 &
(
V_91 ) ) ;
}
static inline int F_34 ( int V_90 )
{
return ( V_90 &
( V_92 ) ) ;
}
static int F_35 ( struct V_93 * V_61 ,
struct V_94 * V_95 )
{
struct V_94 * * V_96 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_97 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_98 ; V_23 ++ )
if ( ! V_61 -> V_99 [ V_23 ] )
break;
if ( V_23 == V_61 -> V_98 ) {
V_96 = F_36 ( V_61 -> V_99 ,
sizeof V_95 *
( V_61 -> V_98 + 1 ) ,
V_100 ) ;
if ( ! V_96 ) {
V_23 = - V_65 ;
goto V_101;
}
V_61 -> V_99 = V_96 ;
V_61 -> V_98 ++ ;
}
V_61 -> V_99 [ V_23 ] = V_95 ;
F_37 ( & V_61 -> V_102 ) ;
V_101:
F_5 ( & V_61 -> V_97 , V_6 ) ;
return V_23 ;
}
struct V_33 * F_38 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
int V_90 ,
T_5 V_103 ,
T_3 V_36 ,
void * V_37 )
{
struct V_1 * V_39 ;
struct V_33 * V_40 ;
struct V_94 * V_95 ;
int V_50 ;
if ( ( F_33 ( V_90 ) && ! V_103 ) ||
( F_34 ( V_90 ) && ! V_36 ) ) {
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
V_95 = F_18 ( sizeof *V_95 , V_64 ) ;
if ( ! V_95 ) {
V_40 = F_15 ( - V_65 ) ;
goto V_53;
}
V_95 -> V_61 = & V_39 -> V_61 [ V_50 ] ;
V_95 -> V_66 . V_3 = V_3 ;
V_95 -> V_66 . V_36 = V_36 ;
V_95 -> V_66 . V_103 = V_103 ;
V_95 -> V_66 . V_37 = V_37 ;
V_95 -> V_66 . V_62 = V_39 -> V_61 [ V_50 ] . V_62 ;
V_95 -> V_66 . V_4 = V_4 ;
V_95 -> V_90 = V_90 ;
F_27 ( & V_95 -> V_83 ) ;
V_95 -> V_104 = F_35 (
& V_39 -> V_61 [ V_50 ] ,
V_95 ) ;
if ( V_95 -> V_104 < 0 ) {
V_40 = F_15 ( V_95 -> V_104 ) ;
goto V_70;
}
F_26 ( & V_95 -> V_82 , 1 ) ;
return & V_95 -> V_66 ;
V_70:
F_31 ( V_95 ) ;
V_53:
return V_40 ;
}
static inline void F_39 ( struct V_42 * V_43 )
{
if ( F_40 ( & V_43 -> V_82 ) )
F_41 ( & V_43 -> V_83 ) ;
}
static inline void F_42 ( struct V_94 * V_95 )
{
if ( F_40 ( & V_95 -> V_82 ) )
F_41 ( & V_95 -> V_83 ) ;
}
static void F_43 ( struct V_42 * V_43 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_44 ( V_43 ) ;
V_39 = V_43 -> V_61 -> V_39 ;
F_45 ( & V_43 -> V_77 ) ;
F_4 ( & V_39 -> V_84 , V_6 ) ;
F_46 ( V_43 ) ;
F_47 ( & V_43 -> V_89 ) ;
F_5 ( & V_39 -> V_84 , V_6 ) ;
F_48 ( V_39 -> V_105 ) ;
F_49 ( V_43 ) ;
F_39 ( V_43 ) ;
F_50 ( & V_43 -> V_83 ) ;
F_31 ( V_43 -> V_44 ) ;
F_32 ( V_43 -> V_66 . V_67 ) ;
F_31 ( V_43 ) ;
}
static void F_51 ( struct V_94 * V_95 )
{
struct V_93 * V_61 ;
unsigned long V_6 ;
V_61 = V_95 -> V_61 ;
F_4 ( & V_61 -> V_97 , V_6 ) ;
V_61 -> V_99 [ V_95 -> V_104 ] = NULL ;
F_52 ( & V_61 -> V_102 ) ;
F_5 ( & V_61 -> V_97 , V_6 ) ;
F_42 ( V_95 ) ;
F_50 ( & V_95 -> V_83 ) ;
F_31 ( V_95 ) ;
}
int F_53 ( struct V_33 * V_106 )
{
struct V_42 * V_43 ;
struct V_94 * V_95 ;
if ( V_106 -> V_85 ) {
V_43 = F_54 ( V_106 ,
struct V_42 ,
V_66 ) ;
F_43 ( V_43 ) ;
} else {
V_95 = F_54 ( V_106 ,
struct V_94 ,
V_66 ) ;
F_51 ( V_95 ) ;
}
return 0 ;
}
static void F_55 ( struct V_107 * V_108 )
{
struct V_109 * V_110 ;
unsigned long V_6 ;
F_56 ( ! V_108 -> V_110 ) ;
V_110 = V_108 -> V_110 ;
F_4 ( & V_110 -> V_72 , V_6 ) ;
F_47 ( & V_108 -> V_111 ) ;
V_110 -> V_112 -- ;
F_5 ( & V_110 -> V_72 , V_6 ) ;
}
static void F_57 ( struct V_93 * V_61 ,
struct V_113 * V_114 ,
struct V_115 * V_116 ,
int V_90 )
{
struct V_94 * V_95 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_97 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_98 ; V_23 ++ ) {
V_95 = V_61 -> V_99 [ V_23 ] ;
if ( ! V_95 ||
! ( V_95 -> V_90 & V_90 ) )
continue;
F_37 ( & V_95 -> V_82 ) ;
F_5 ( & V_61 -> V_97 , V_6 ) ;
V_95 -> V_66 . V_103 ( & V_95 -> V_66 ,
V_114 , V_116 ) ;
F_42 ( V_95 ) ;
F_4 ( & V_61 -> V_97 , V_6 ) ;
}
F_5 ( & V_61 -> V_97 , V_6 ) ;
}
static void F_58 ( struct V_93 * V_61 ,
struct V_117 * V_118 ,
int V_90 )
{
struct V_94 * V_95 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_97 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_98 ; V_23 ++ ) {
V_95 = V_61 -> V_99 [ V_23 ] ;
if ( ! V_95 ||
! ( V_95 -> V_90 & V_90 ) )
continue;
F_37 ( & V_95 -> V_82 ) ;
F_5 ( & V_61 -> V_97 , V_6 ) ;
V_95 -> V_66 . V_36 ( & V_95 -> V_66 ,
V_118 ) ;
F_42 ( V_95 ) ;
F_4 ( & V_61 -> V_97 , V_6 ) ;
}
F_5 ( & V_61 -> V_97 , V_6 ) ;
}
static void F_59 ( struct V_119 * V_62 ,
T_6 V_120 , T_7 V_121 , T_7 V_122 , T_1 V_4 ,
struct V_123 * V_124 )
{
memset ( V_124 , 0 , sizeof *V_124 ) ;
V_124 -> V_120 = V_120 ;
V_124 -> V_125 = V_126 ;
V_124 -> V_127 = V_128 ;
V_124 -> V_122 = V_122 ;
V_124 -> V_129 = sizeof( struct V_130 ) + sizeof( struct V_131 ) ;
V_124 -> V_132 = V_133 ;
V_124 -> V_62 = V_62 ;
V_124 -> V_121 = V_121 ;
V_124 -> V_134 = 0 ;
V_124 -> V_135 = 0 ;
V_124 -> V_4 = V_4 ;
}
static T_8 F_60 ( const struct V_136 * V_137 )
{
return sizeof( struct V_136 ) + V_137 -> V_138 ;
}
static struct V_136 * F_61 ( T_8 V_138 , T_9 V_6 )
{
T_8 V_139 = sizeof( struct V_136 ) + V_138 ;
struct V_136 * V_40 = F_18 ( V_139 , V_6 ) ;
if ( V_40 )
V_40 -> V_138 = V_138 ;
return V_40 ;
}
static T_8 F_62 ( const struct V_1 * V_39 )
{
return F_63 ( V_39 -> V_3 , V_39 -> V_4 ) ;
}
static T_8 F_64 ( const struct V_136 * V_137 )
{
return sizeof( struct V_131 ) + V_137 -> V_138 ;
}
static int F_65 ( struct V_42 * V_43 ,
struct V_140 * V_141 )
{
int V_40 = 0 ;
struct V_142 * V_143 = V_141 -> V_114 . V_144 ;
struct V_145 * V_145 = (struct V_145 * ) V_143 ;
unsigned long V_6 ;
struct V_146 * V_147 ;
struct V_136 * V_148 ;
struct V_1 * V_39 ;
struct V_42 * V_149 = NULL ;
struct V_2 * V_3 = V_43 -> V_66 . V_3 ;
T_1 V_4 ;
struct V_123 V_150 ;
struct V_151 * V_152 = & V_141 -> V_152 ;
T_8 V_138 = F_62 ( V_43 -> V_61 -> V_39 ) ;
T_7 V_153 = 0 ;
T_7 V_154 ;
bool V_155 = F_66 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
if ( F_67 ( V_3 ) &&
V_143 -> V_8 == V_9 )
V_4 = V_152 -> V_156 . V_157 . V_4 ;
else
V_4 = V_43 -> V_66 . V_4 ;
if ( V_155 && V_143 -> V_158 == V_159 ) {
T_4 V_160 ;
if ( ( F_68 ( V_145 )
? V_145 -> V_161 . V_162 . V_163 : V_145 -> V_161 . V_162 . V_164 ) ==
V_165 &&
F_69 ( V_145 ,
F_67 ( V_3 ) ,
V_4 ) == V_166 ) {
V_40 = - V_41 ;
F_70 ( & V_3 -> V_52 , L_13 ) ;
goto V_101;
}
V_160 = F_71 ( V_145 -> V_161 . V_162 . V_164 ) ;
if ( V_160 != F_71 ( V_165 ) &&
V_160 & 0xffff0000 ) {
V_40 = - V_41 ;
F_70 ( & V_3 -> V_52 , L_14 ,
V_160 ) ;
goto V_101;
}
V_154 = ( T_7 ) ( V_160 & 0x0000ffff ) ;
if ( F_72 ( V_145 , V_3 ) == V_166 &&
F_73 ( V_145 , V_3 ) == V_166 )
goto V_101;
} else {
if ( ( F_74 ( V_143 ) ? V_143 -> V_163 : V_143 -> V_164 ) ==
V_167 &&
F_75 ( V_143 , F_67 ( V_3 ) , V_4 ) ==
V_166 ) {
V_40 = - V_41 ;
F_70 ( & V_3 -> V_52 , L_15 ) ;
goto V_101;
}
V_154 = F_76 ( V_143 -> V_164 ) ;
if ( F_77 ( V_143 , V_3 ) == V_166 &&
F_78 ( V_143 , V_3 ) == V_166 )
goto V_101;
}
V_147 = F_79 ( sizeof *V_147 , V_100 ) ;
if ( ! V_147 ) {
V_40 = - V_65 ;
F_70 ( & V_3 -> V_52 , L_16 ) ;
goto V_101;
}
V_147 -> V_148 = NULL ;
V_147 -> V_149 = NULL ;
V_148 = F_61 ( V_138 , V_100 ) ;
if ( ! V_148 ) {
V_40 = - V_65 ;
F_70 ( & V_3 -> V_52 , L_17 ) ;
F_31 ( V_147 ) ;
goto V_101;
}
F_59 ( V_43 -> V_66 . V_62 ,
V_152 -> V_120 , V_154 ,
V_152 -> V_156 . V_157 . V_122 ,
V_152 -> V_156 . V_157 . V_4 , & V_150 ) ;
if ( V_155 && V_143 -> V_168 == V_169 ) {
V_150 . V_129 = V_141 -> V_114 . V_170
+ V_141 -> V_114 . V_171
+ sizeof( struct V_131 ) ;
}
V_40 = V_3 -> V_172 ( V_3 , 0 , V_4 , & V_150 , NULL ,
( const struct V_26 * ) V_143 , V_138 ,
(struct V_26 * ) V_148 -> V_144 ,
& V_138 , & V_153 ) ;
switch ( V_40 )
{
case V_173 | V_174 :
if ( F_13 ( ( const struct V_26 * ) V_148 -> V_144 ) &&
V_43 -> V_66 . V_36 ) {
V_147 -> V_148 = V_148 ;
V_147 -> V_149 = V_43 ;
F_37 ( & V_43 -> V_82 ) ;
} else
F_31 ( V_148 ) ;
break;
case V_173 | V_175 :
F_31 ( V_148 ) ;
break;
case V_173 :
V_39 = F_3 ( V_43 -> V_66 . V_3 ,
V_43 -> V_66 . V_4 ) ;
if ( V_39 ) {
memcpy ( V_148 -> V_144 , V_143 , V_148 -> V_138 ) ;
V_149 = F_80 ( V_39 ,
( const struct V_26 * ) V_148 -> V_144 ) ;
}
if ( ! V_39 || ! V_149 ) {
F_31 ( V_148 ) ;
break;
}
V_147 -> V_148 = V_148 ;
V_147 -> V_149 = V_149 ;
break;
default:
F_31 ( V_148 ) ;
F_31 ( V_147 ) ;
V_40 = - V_41 ;
goto V_101;
}
V_147 -> V_141 = V_141 ;
if ( V_155 ) {
V_147 -> V_141 -> V_152 . V_156 . V_157 . V_122 = V_153 ;
V_147 -> V_176 = V_138 ;
}
F_37 ( & V_43 -> V_82 ) ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
F_30 ( & V_147 -> V_177 , & V_43 -> V_79 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
F_81 ( V_43 -> V_61 -> V_39 -> V_105 ,
& V_43 -> V_80 ) ;
V_40 = 1 ;
V_101:
return V_40 ;
}
static int F_82 ( int V_170 , int V_171 , T_8 V_138 )
{
int V_178 , V_179 ;
V_178 = V_138 - V_170 ;
if ( V_171 && V_178 ) {
V_179 = V_178 - V_171 % V_178 ;
return V_179 == V_178 ? 0 : V_179 ;
} else
return V_178 ;
}
static void F_83 ( struct V_140 * V_141 )
{
struct V_180 * V_181 , * V_182 ;
F_84 (s, t, &mad_send_wr->rmpp_list, list) {
F_47 ( & V_181 -> V_111 ) ;
F_31 ( V_181 ) ;
}
}
static int F_85 ( struct V_140 * V_152 ,
T_8 V_138 , T_9 V_183 )
{
struct V_113 * V_114 = & V_152 -> V_114 ;
struct V_184 * V_185 = V_114 -> V_144 ;
struct V_180 * V_186 = NULL ;
int V_187 , V_178 , V_179 ;
V_114 -> V_178 = V_138 - V_114 -> V_170 ;
V_114 -> V_188 = V_138 - V_189 ;
V_178 = V_114 -> V_178 ;
V_179 = V_152 -> V_179 ;
for ( V_187 = V_114 -> V_171 + V_179 ; V_187 > 0 ; V_187 -= V_178 ) {
V_186 = F_79 ( sizeof ( * V_186 ) + V_178 , V_183 ) ;
if ( ! V_186 ) {
F_70 ( & V_114 -> V_106 -> V_3 -> V_52 ,
L_18 ,
sizeof ( * V_186 ) + V_178 , V_183 ) ;
F_83 ( V_152 ) ;
return - V_65 ;
}
V_186 -> V_190 = ++ V_114 -> V_191 ;
F_30 ( & V_186 -> V_111 , & V_152 -> V_76 ) ;
}
if ( V_179 )
memset ( V_186 -> V_192 + V_178 - V_179 , 0 , V_179 ) ;
V_185 -> V_193 . V_34 = V_152 -> V_43 ->
V_66 . V_34 ;
V_185 -> V_193 . V_194 = V_195 ;
F_86 ( & V_185 -> V_193 , V_196 ) ;
V_152 -> V_197 = F_54 ( V_152 -> V_76 . V_198 ,
struct V_180 , V_111 ) ;
V_152 -> V_199 = V_152 -> V_197 ;
return 0 ;
}
int F_87 ( const struct V_33 * V_66 )
{
return V_66 -> V_34 && ! ( V_66 -> V_6 & V_59 ) ;
}
struct V_113 * F_88 ( struct V_33 * V_106 ,
T_4 V_200 , T_7 V_122 ,
int V_201 ,
int V_170 , int V_171 ,
T_9 V_183 ,
T_1 V_168 )
{
struct V_42 * V_43 ;
struct V_140 * V_141 ;
int V_179 , V_202 , V_40 , V_139 ;
void * V_203 ;
T_8 V_138 ;
bool V_155 ;
V_43 = F_54 ( V_106 , struct V_42 ,
V_66 ) ;
V_155 = F_66 ( V_106 -> V_3 , V_106 -> V_4 ) ;
if ( V_155 && V_168 == V_169 )
V_138 = sizeof( struct V_204 ) ;
else
V_138 = sizeof( struct V_130 ) ;
V_179 = F_82 ( V_170 , V_171 , V_138 ) ;
V_202 = V_170 + V_171 + V_179 ;
if ( F_87 ( V_106 ) ) {
if ( ! V_201 && V_202 > V_138 )
return F_15 ( - V_41 ) ;
} else
if ( V_201 || V_202 > V_138 )
return F_15 ( - V_41 ) ;
V_139 = V_201 ? V_170 : V_138 ;
V_203 = F_18 ( sizeof *V_141 + V_139 , V_183 ) ;
if ( ! V_203 )
return F_15 ( - V_65 ) ;
V_141 = V_203 + V_139 ;
F_23 ( & V_141 -> V_76 ) ;
V_141 -> V_114 . V_144 = V_203 ;
V_141 -> V_114 . V_170 = V_170 ;
V_141 -> V_114 . V_171 = V_171 ;
V_141 -> V_179 = V_179 ;
V_141 -> V_43 = V_43 ;
V_141 -> V_205 [ 0 ] . V_206 = V_170 ;
V_141 -> V_205 [ 0 ] . V_207 = V_106 -> V_67 -> V_207 ;
if ( V_155 && V_168 == V_169 &&
V_171 < V_138 - V_170 )
V_141 -> V_205 [ 1 ] . V_206 = V_171 ;
else
V_141 -> V_205 [ 1 ] . V_206 = V_138 - V_170 ;
V_141 -> V_205 [ 1 ] . V_207 = V_106 -> V_67 -> V_207 ;
V_141 -> V_152 . V_120 = ( unsigned long ) V_141 ;
V_141 -> V_152 . V_205 = V_141 -> V_205 ;
V_141 -> V_152 . V_208 = 2 ;
V_141 -> V_152 . V_127 = V_209 ;
V_141 -> V_152 . V_210 = V_211 ;
V_141 -> V_152 . V_156 . V_157 . V_200 = V_200 ;
V_141 -> V_152 . V_156 . V_157 . V_212 = V_213 ;
V_141 -> V_152 . V_156 . V_157 . V_122 = V_122 ;
if ( V_201 ) {
V_40 = F_85 ( V_141 , V_138 , V_183 ) ;
if ( V_40 ) {
F_31 ( V_203 ) ;
return F_15 ( V_40 ) ;
}
}
V_141 -> V_114 . V_106 = V_106 ;
F_37 ( & V_43 -> V_82 ) ;
return & V_141 -> V_114 ;
}
int F_89 ( T_1 V_8 )
{
if ( V_8 == V_214 )
return V_215 ;
else if ( ( V_8 == V_216 ) ||
( V_8 == V_217 ) ||
( V_8 == V_218 ) )
return V_219 ;
else if ( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) )
return V_220 ;
else
return V_221 ;
}
int F_17 ( T_1 V_8 )
{
if ( ( V_8 == V_214 ) ||
( V_8 == V_216 ) ||
( V_8 == V_217 ) ||
( V_8 == V_218 ) ||
( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) ) )
return 1 ;
return 0 ;
}
void * F_90 ( struct V_113 * V_114 , int V_222 )
{
struct V_140 * V_141 ;
struct V_223 * V_111 ;
V_141 = F_54 ( V_114 , struct V_140 ,
V_114 ) ;
V_111 = & V_141 -> V_197 -> V_111 ;
if ( V_141 -> V_197 -> V_190 < V_222 ) {
F_2 (mad_send_wr->cur_seg, list, list)
if ( V_141 -> V_197 -> V_190 == V_222 )
break;
} else if ( V_141 -> V_197 -> V_190 > V_222 ) {
F_91 (mad_send_wr->cur_seg, list, list)
if ( V_141 -> V_197 -> V_190 == V_222 )
break;
}
return V_141 -> V_197 -> V_192 ;
}
static inline void * F_92 ( struct V_140 * V_141 )
{
if ( V_141 -> V_114 . V_191 )
return F_90 ( & V_141 -> V_114 ,
V_141 -> V_222 ) ;
else
return V_141 -> V_114 . V_144 +
V_141 -> V_114 . V_170 ;
}
void F_93 ( struct V_113 * V_114 )
{
struct V_42 * V_43 ;
struct V_140 * V_141 ;
V_43 = F_54 ( V_114 -> V_106 ,
struct V_42 , V_66 ) ;
V_141 = F_54 ( V_114 , struct V_140 ,
V_114 ) ;
F_83 ( V_141 ) ;
F_31 ( V_114 -> V_144 ) ;
F_39 ( V_43 ) ;
}
int F_94 ( struct V_140 * V_141 )
{
struct V_93 * V_61 ;
struct V_223 * V_111 ;
struct V_151 * V_224 ;
struct V_33 * V_106 ;
struct V_225 * V_226 ;
unsigned long V_6 ;
int V_40 ;
V_61 = V_141 -> V_43 -> V_61 ;
V_141 -> V_152 . V_120 = ( unsigned long ) & V_141 -> V_108 ;
V_141 -> V_108 . V_110 = & V_61 -> V_227 ;
V_106 = V_141 -> V_114 . V_106 ;
V_226 = V_141 -> V_205 ;
V_226 [ 0 ] . V_228 = F_95 ( V_106 -> V_3 ,
V_141 -> V_114 . V_144 ,
V_226 [ 0 ] . V_206 ,
V_229 ) ;
if ( F_96 ( F_97 ( V_106 -> V_3 , V_226 [ 0 ] . V_228 ) ) )
return - V_65 ;
V_141 -> V_230 = V_226 [ 0 ] . V_228 ;
V_226 [ 1 ] . V_228 = F_95 ( V_106 -> V_3 ,
F_92 ( V_141 ) ,
V_226 [ 1 ] . V_206 ,
V_229 ) ;
if ( F_96 ( F_97 ( V_106 -> V_3 , V_226 [ 1 ] . V_228 ) ) ) {
F_98 ( V_106 -> V_3 ,
V_141 -> V_230 ,
V_226 [ 0 ] . V_206 , V_229 ) ;
return - V_65 ;
}
V_141 -> V_231 = V_226 [ 1 ] . V_228 ;
F_4 ( & V_61 -> V_227 . V_72 , V_6 ) ;
if ( V_61 -> V_227 . V_112 < V_61 -> V_227 . V_232 ) {
V_40 = F_99 ( V_106 -> V_62 , & V_141 -> V_152 ,
& V_224 ) ;
V_111 = & V_61 -> V_227 . V_111 ;
} else {
V_40 = 0 ;
V_111 = & V_61 -> V_233 ;
}
if ( ! V_40 ) {
V_61 -> V_227 . V_112 ++ ;
F_30 ( & V_141 -> V_108 . V_111 , V_111 ) ;
}
F_5 ( & V_61 -> V_227 . V_72 , V_6 ) ;
if ( V_40 ) {
F_98 ( V_106 -> V_3 ,
V_141 -> V_230 ,
V_226 [ 0 ] . V_206 , V_229 ) ;
F_98 ( V_106 -> V_3 ,
V_141 -> V_231 ,
V_226 [ 1 ] . V_206 , V_229 ) ;
}
return V_40 ;
}
int F_100 ( struct V_113 * V_114 ,
struct V_113 * * V_234 )
{
struct V_42 * V_43 ;
struct V_113 * V_235 ;
struct V_140 * V_141 ;
unsigned long V_6 ;
int V_40 = - V_41 ;
for (; V_114 ; V_114 = V_235 ) {
V_141 = F_54 ( V_114 ,
struct V_140 ,
V_114 ) ;
V_43 = V_141 -> V_43 ;
if ( ! V_114 -> V_106 -> V_35 ||
( V_114 -> V_236 &&
! V_114 -> V_106 -> V_36 ) ) {
V_40 = - V_41 ;
goto error;
}
if ( ! F_17 ( ( (struct V_26 * ) V_114 -> V_144 ) -> V_8 ) ) {
if ( V_43 -> V_66 . V_34 ) {
V_40 = - V_41 ;
goto error;
}
}
V_235 = V_114 -> V_198 ;
V_141 -> V_152 . V_156 . V_157 . V_237 = V_114 -> V_237 ;
if ( ( (struct V_26 * ) V_114 -> V_144 ) -> V_8 ==
V_9 ) {
V_40 = F_65 ( V_43 ,
V_141 ) ;
if ( V_40 < 0 )
goto error;
else if ( V_40 == 1 )
continue;
}
V_141 -> V_238 = ( (struct V_26 * ) V_114 -> V_144 ) -> V_238 ;
V_141 -> V_239 = F_101 ( V_114 -> V_236 ) ;
V_141 -> V_240 = V_114 -> V_241 ;
V_141 -> V_242 = V_114 -> V_241 ;
V_114 -> V_241 = 0 ;
V_141 -> V_82 = 1 + ( V_141 -> V_239 > 0 ) ;
V_141 -> V_125 = V_126 ;
F_37 ( & V_43 -> V_82 ) ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
F_30 ( & V_141 -> V_89 ,
& V_43 -> V_73 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
if ( F_87 ( & V_43 -> V_66 ) ) {
V_40 = F_102 ( V_141 ) ;
if ( V_40 >= 0 && V_40 != V_243 )
V_40 = F_94 ( V_141 ) ;
} else
V_40 = F_94 ( V_141 ) ;
if ( V_40 < 0 ) {
F_4 ( & V_43 -> V_72 , V_6 ) ;
F_47 ( & V_141 -> V_89 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
F_52 ( & V_43 -> V_82 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_234 )
* V_234 = V_114 ;
return V_40 ;
}
void F_103 ( struct V_117 * V_118 )
{
struct V_244 * V_245 , * V_246 ;
struct V_247 * V_248 ;
struct V_136 * V_249 ;
struct V_223 V_250 ;
F_23 ( & V_250 ) ;
F_104 ( & V_118 -> V_76 , & V_250 ) ;
F_84 (mad_recv_buf, temp_recv_buf,
&free_list, list) {
V_118 = F_54 ( V_245 , struct V_117 ,
V_251 ) ;
V_248 = F_54 ( V_118 ,
struct V_247 ,
V_252 ) ;
V_249 = F_54 ( V_248 , struct V_136 ,
V_253 ) ;
F_31 ( V_249 ) ;
}
}
struct V_33 * F_105 ( struct V_119 * V_62 ,
T_1 V_34 ,
T_2 V_35 ,
T_3 V_36 ,
void * V_37 )
{
return F_15 ( - V_41 ) ;
}
int F_106 ( struct V_33 * V_106 ,
struct V_123 * V_124 )
{
F_70 ( & V_106 -> V_3 -> V_52 ,
L_19 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * * V_22 ,
struct V_19 * V_20 )
{
int V_23 ;
F_107 (i, mad_reg_req->method_mask, IB_MGMT_MAX_METHODS) {
if ( ( * V_22 ) -> V_66 [ V_23 ] ) {
F_108 ( L_20 , V_23 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_109 ( struct V_21 * * V_22 )
{
* V_22 = F_18 ( sizeof ** V_22 , V_100 ) ;
if ( ! * V_22 ) {
F_108 ( L_21 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_110 ( struct V_21 * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_254 ; V_23 ++ )
if ( V_22 -> V_66 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_111 ( struct V_45 * V_46 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_57 ; V_23 ++ )
if ( V_46 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_112 ( struct V_17 * V_18 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( V_18 -> V_25 [ V_23 ] )
return 1 ;
return 0 ;
}
static int F_113 ( struct V_17 * V_18 ,
const char * V_16 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ )
if ( ! memcmp ( V_18 -> V_16 [ V_23 ] , V_16 , 3 ) )
return V_23 ;
return - 1 ;
}
static int F_114 ( struct V_47 * V_48 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_255 ; V_23 ++ )
if ( V_48 -> V_18 [ V_23 ] )
return 1 ;
return 0 ;
}
static void F_115 ( struct V_21 * V_22 ,
struct V_42 * V_66 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_254 ; V_23 ++ ) {
if ( V_22 -> V_66 [ V_23 ] == V_66 ) {
V_22 -> V_66 [ V_23 ] = NULL ;
}
}
}
static int F_28 ( struct V_19 * V_20 ,
struct V_42 * V_256 ,
T_1 V_8 )
{
struct V_1 * V_39 ;
struct V_45 * * V_46 ;
struct V_21 * * V_22 ;
int V_23 , V_40 ;
V_39 = V_256 -> V_61 -> V_39 ;
V_46 = & V_39 -> V_87 [ V_20 -> V_55 ] . V_46 ;
if ( ! * V_46 ) {
* V_46 = F_18 ( sizeof ** V_46 , V_100 ) ;
if ( ! * V_46 ) {
F_70 ( & V_256 -> V_66 . V_3 -> V_52 ,
L_22 ) ;
V_40 = - V_65 ;
goto V_53;
}
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ( V_40 = F_109 ( V_22 ) ) )
goto V_70;
} else {
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ! * V_22 ) {
if ( ( V_40 = F_109 ( V_22 ) ) )
goto V_53;
}
}
if ( F_12 ( V_22 , V_20 ) )
goto V_71;
F_107 ( V_23 , V_20 -> V_257 , V_254 )
( * V_22 ) -> V_66 [ V_23 ] = V_256 ;
return 0 ;
V_71:
F_115 ( * V_22 , V_256 ) ;
if ( ! F_110 ( * V_22 ) ) {
F_31 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
goto V_53;
V_70:
F_31 ( * V_46 ) ;
* V_46 = NULL ;
V_53:
return V_40 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_42 * V_256 )
{
struct V_1 * V_39 ;
struct V_47 * * V_258 ;
struct V_47 * V_48 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_21 * * V_22 ;
int V_23 , V_40 = - V_65 ;
T_1 V_51 ;
V_51 = F_8 ( V_20 -> V_8 ) ;
V_39 = V_256 -> V_61 -> V_39 ;
V_258 = & V_39 -> V_87 [
V_20 -> V_55 ] . V_48 ;
if ( ! * V_258 ) {
V_48 = F_18 ( sizeof *V_48 , V_100 ) ;
if ( ! V_48 ) {
F_70 ( & V_256 -> V_66 . V_3 -> V_52 ,
L_23 ) ;
goto V_53;
}
* V_258 = V_48 ;
}
if ( ! ( * V_258 ) -> V_18 [ V_51 ] ) {
V_18 = F_18 ( sizeof *V_18 , V_100 ) ;
if ( ! V_18 ) {
F_70 ( & V_256 -> V_66 . V_3 -> V_52 ,
L_24 ) ;
goto V_70;
}
( * V_258 ) -> V_18 [ V_51 ] = V_18 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( ( * V_258 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ) {
V_22 = & ( * V_258 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_56 ( ! * V_22 ) ;
goto V_259;
}
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! F_10 ( ( * V_258 ) -> V_18 [
V_51 ] -> V_16 [ V_23 ] ) ) {
V_22 = & ( * V_258 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_56 ( * V_22 ) ;
if ( ( V_40 = F_109 ( V_22 ) ) )
goto V_71;
memcpy ( ( * V_258 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ;
goto V_259;
}
}
F_70 ( & V_256 -> V_66 . V_3 -> V_52 , L_25 ) ;
goto V_71;
V_259:
if ( F_12 ( V_22 , V_20 ) )
goto V_88;
F_107 ( V_23 , V_20 -> V_257 , V_254 )
( * V_22 ) -> V_66 [ V_23 ] = V_256 ;
return 0 ;
V_88:
F_115 ( * V_22 , V_256 ) ;
if ( ! F_110 ( * V_22 ) ) {
F_31 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
V_71:
if ( V_18 ) {
( * V_258 ) -> V_18 [ V_51 ] = NULL ;
F_31 ( V_18 ) ;
}
V_70:
if ( V_48 ) {
* V_258 = NULL ;
F_31 ( V_48 ) ;
}
V_53:
return V_40 ;
}
static void F_46 ( struct V_42 * V_256 )
{
struct V_1 * V_39 ;
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
int V_260 ;
T_1 V_8 ;
if ( ! V_256 -> V_44 ) {
goto V_101;
}
V_39 = V_256 -> V_61 -> V_39 ;
V_8 = F_6 ( V_256 -> V_44 -> V_8 ) ;
V_46 = V_39 -> V_87 [
V_256 -> V_44 -> V_55 ] . V_46 ;
if ( ! V_46 )
goto V_261;
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
F_115 ( V_22 , V_256 ) ;
if ( ! F_110 ( V_22 ) ) {
F_31 ( V_22 ) ;
V_46 -> V_25 [ V_8 ] = NULL ;
if ( ! F_111 ( V_46 ) ) {
F_31 ( V_46 ) ;
V_39 -> V_87 [
V_256 -> V_44 ->
V_55 ] . V_46 = NULL ;
}
}
}
V_261:
if ( ! F_9 ( V_8 ) )
goto V_101;
V_8 = F_8 ( V_256 -> V_44 -> V_8 ) ;
V_48 = V_39 -> V_87 [
V_256 -> V_44 -> V_55 ] . V_48 ;
if ( ! V_48 )
goto V_101;
V_18 = V_48 -> V_18 [ V_8 ] ;
if ( V_18 ) {
V_260 = F_113 ( V_18 , V_256 -> V_44 -> V_16 ) ;
if ( V_260 < 0 )
goto V_101;
V_22 = V_18 -> V_25 [ V_260 ] ;
if ( V_22 ) {
F_115 ( V_22 , V_256 ) ;
if ( ! F_110 ( V_22 ) ) {
F_31 ( V_22 ) ;
V_18 -> V_25 [ V_260 ] = NULL ;
memset ( V_18 -> V_16 [ V_260 ] , 0 , 3 ) ;
if ( ! F_112 ( V_18 ) ) {
F_31 ( V_18 ) ;
V_48 -> V_18 [ V_8 ] = NULL ;
if ( ! F_114 ( V_48 ) ) {
F_31 ( V_48 ) ;
V_39 -> V_87 [
V_256 -> V_44 ->
V_55 ] .
V_48 = NULL ;
}
}
}
}
}
V_101:
return;
}
static struct V_42 *
F_80 ( struct V_1 * V_39 ,
const struct V_26 * V_262 )
{
struct V_42 * V_106 = NULL ;
unsigned long V_6 ;
F_4 ( & V_39 -> V_84 , V_6 ) ;
if ( F_13 ( V_262 ) ) {
T_4 V_85 ;
struct V_42 * V_5 ;
V_85 = F_116 ( V_262 -> V_238 ) >> 32 ;
F_2 (entry, &port_priv->agent_list, agent_list) {
if ( V_5 -> V_66 . V_85 == V_85 ) {
V_106 = V_5 ;
break;
}
}
} else {
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
const struct V_263 * V_264 ;
int V_260 ;
if ( V_262 -> V_158 >= V_56 )
goto V_101;
if ( ! F_9 ( V_262 -> V_8 ) ) {
V_46 = V_39 -> V_87 [
V_262 -> V_158 ] . V_46 ;
if ( ! V_46 )
goto V_101;
if ( F_6 ( V_262 -> V_8 ) >=
V_254 )
goto V_101;
V_22 = V_46 -> V_25 [ F_6 (
V_262 -> V_8 ) ] ;
if ( V_22 )
V_106 = V_22 -> V_66 [ V_262 -> V_22 &
~ V_28 ] ;
} else {
V_48 = V_39 -> V_87 [
V_262 -> V_158 ] . V_48 ;
if ( ! V_48 )
goto V_101;
V_18 = V_48 -> V_18 [ F_8 (
V_262 -> V_8 ) ] ;
if ( ! V_18 )
goto V_101;
V_264 = ( const struct V_263 * ) V_262 ;
V_260 = F_113 ( V_18 , V_264 -> V_16 ) ;
if ( V_260 == - 1 )
goto V_101;
V_22 = V_18 -> V_25 [ V_260 ] ;
if ( V_22 ) {
V_106 = V_22 -> V_66 [ V_262 -> V_22 &
~ V_28 ] ;
}
}
}
if ( V_106 ) {
if ( V_106 -> V_66 . V_36 )
F_37 ( & V_106 -> V_82 ) ;
else {
F_16 ( & V_39 -> V_3 -> V_52 ,
L_26 ,
& V_106 -> V_66 , V_39 -> V_4 ) ;
V_106 = NULL ;
}
}
V_101:
F_5 ( & V_39 -> V_84 , V_6 ) ;
return V_106 ;
}
static int F_117 ( const struct V_26 * V_262 ,
const struct V_93 * V_61 ,
bool V_155 )
{
int V_265 = 0 ;
T_4 V_266 = V_61 -> V_62 -> V_266 ;
if ( V_262 -> V_168 != V_267 &&
( ! V_155 || V_262 -> V_168 != V_169 ) ) {
F_108 ( L_27 ,
V_262 -> V_168 , V_155 ? L_28 : L_29 ) ;
goto V_101;
}
if ( ( V_262 -> V_8 == V_58 ) ||
( V_262 -> V_8 == V_9 ) ) {
if ( V_266 == 0 )
V_265 = 1 ;
} else {
if ( V_266 != 0 )
V_265 = 1 ;
}
V_101:
return V_265 ;
}
static int F_118 ( const struct V_42 * V_43 ,
const struct V_26 * V_262 )
{
struct V_184 * V_185 ;
V_185 = (struct V_184 * ) V_262 ;
return ! V_43 -> V_66 . V_34 ||
! F_87 ( & V_43 -> V_66 ) ||
! ( F_119 ( & V_185 -> V_193 ) &
V_196 ) ||
( V_185 -> V_193 . V_194 == V_195 ) ;
}
static inline int F_120 ( const struct V_140 * V_156 ,
const struct V_117 * V_268 )
{
return ( (struct V_26 * ) ( V_156 -> V_114 . V_144 ) ) -> V_8 ==
V_268 -> V_251 . V_144 -> V_262 . V_8 ;
}
static inline int F_121 ( const struct V_42 * V_43 ,
const struct V_140 * V_156 ,
const struct V_117 * V_268 )
{
struct V_269 V_270 ;
T_1 V_271 , V_272 ;
union V_273 V_274 ;
struct V_2 * V_3 = V_43 -> V_66 . V_3 ;
T_1 V_4 = V_43 -> V_66 . V_4 ;
T_1 V_275 ;
V_271 = F_13 ( (struct V_26 * ) V_156 -> V_114 . V_144 ) ;
V_272 = F_13 ( & V_268 -> V_251 . V_144 -> V_262 ) ;
if ( V_271 == V_272 )
return 0 ;
if ( F_122 ( V_156 -> V_114 . V_237 , & V_270 ) )
return 0 ;
if ( ! ! ( V_270 . V_276 & V_277 ) !=
! ! ( V_268 -> V_124 -> V_278 & V_279 ) )
return 0 ;
if ( ! V_271 && V_272 ) {
if ( ! ( V_270 . V_276 & V_277 ) ) {
if ( F_123 ( V_3 , V_4 , & V_275 ) )
return 0 ;
return ( ! V_275 || ! ( ( V_270 . V_280 ^
V_268 -> V_124 -> V_135 ) &
( ( 1 << V_275 ) - 1 ) ) ) ;
} else {
if ( F_124 ( V_3 , V_4 ,
V_270 . V_281 . V_282 , & V_274 ) )
return 0 ;
return ! memcmp ( V_274 . V_283 , V_268 -> V_251 . V_281 -> V_284 . V_283 ,
16 ) ;
}
}
if ( ! ( V_270 . V_276 & V_277 ) )
return V_270 . V_285 == V_268 -> V_124 -> V_121 ;
else
return ! memcmp ( V_270 . V_281 . V_284 . V_283 , V_268 -> V_251 . V_281 -> V_274 . V_283 ,
16 ) ;
}
static inline int F_125 ( T_1 V_46 )
{
return ( V_46 == V_9 ) ;
}
struct V_140 *
F_126 ( const struct V_42 * V_43 ,
const struct V_117 * V_124 )
{
struct V_140 * V_156 ;
const struct V_26 * V_262 ;
V_262 = & V_124 -> V_251 . V_144 -> V_262 ;
F_2 (wr, &mad_agent_priv->wait_list, agent_list) {
if ( ( V_156 -> V_238 == V_262 -> V_238 ) &&
F_120 ( V_156 , V_124 ) &&
( F_125 ( V_262 -> V_8 ) ||
F_121 ( V_43 , V_156 , V_124 ) ) )
return ( V_156 -> V_125 == V_126 ) ? V_156 : NULL ;
}
F_2 (wr, &mad_agent_priv->send_list, agent_list) {
if ( F_118 ( V_43 , V_156 -> V_114 . V_144 ) &&
V_156 -> V_238 == V_262 -> V_238 &&
V_156 -> V_239 &&
F_120 ( V_156 , V_124 ) &&
( F_125 ( V_262 -> V_8 ) ||
F_121 ( V_43 , V_156 , V_124 ) ) )
return ( V_156 -> V_125 == V_126 ) ? V_156 : NULL ;
}
return NULL ;
}
void F_127 ( struct V_140 * V_141 )
{
V_141 -> V_239 = 0 ;
if ( V_141 -> V_82 == 1 )
F_128 ( & V_141 -> V_89 ,
& V_141 -> V_43 -> V_75 ) ;
}
static void F_129 ( struct V_42 * V_43 ,
struct V_117 * V_118 )
{
struct V_140 * V_141 ;
struct V_115 V_116 ;
unsigned long V_6 ;
F_23 ( & V_118 -> V_76 ) ;
F_130 ( & V_118 -> V_251 . V_111 , & V_118 -> V_76 ) ;
if ( F_87 ( & V_43 -> V_66 ) ) {
V_118 = F_131 ( V_43 ,
V_118 ) ;
if ( ! V_118 ) {
F_39 ( V_43 ) ;
return;
}
}
if ( F_13 ( & V_118 -> V_251 . V_144 -> V_262 ) ) {
F_4 ( & V_43 -> V_72 , V_6 ) ;
V_141 = F_126 ( V_43 , V_118 ) ;
if ( ! V_141 ) {
F_5 ( & V_43 -> V_72 , V_6 ) ;
if ( ! F_87 ( & V_43 -> V_66 )
&& F_17 ( V_118 -> V_251 . V_144 -> V_262 . V_8 )
&& ( F_119 ( & ( (struct V_184 * ) V_118 -> V_251 . V_144 ) -> V_193 )
& V_196 ) ) {
V_118 -> V_124 -> V_120 = 0 ;
V_43 -> V_66 . V_36 ( & V_43 -> V_66 ,
V_118 ) ;
F_52 ( & V_43 -> V_82 ) ;
} else {
F_103 ( V_118 ) ;
F_39 ( V_43 ) ;
return;
}
} else {
F_127 ( V_141 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
V_118 -> V_124 -> V_120 = ( unsigned long ) & V_141 -> V_114 ;
V_43 -> V_66 . V_36 ( & V_43 -> V_66 ,
V_118 ) ;
F_52 ( & V_43 -> V_82 ) ;
V_116 . V_125 = V_126 ;
V_116 . V_286 = 0 ;
V_116 . V_114 = & V_141 -> V_114 ;
F_132 ( V_141 , & V_116 ) ;
}
} else {
V_43 -> V_66 . V_36 ( & V_43 -> V_66 ,
V_118 ) ;
F_39 ( V_43 ) ;
}
}
static enum V_287 F_133 ( const struct V_1 * V_39 ,
const struct V_93 * V_61 ,
const struct V_123 * V_124 ,
int V_4 ,
struct V_136 * V_288 ,
struct V_136 * V_289 )
{
enum V_290 V_291 ;
struct V_142 * V_143 = (struct V_142 * ) V_288 -> V_144 ;
if ( F_134 ( V_143 ,
F_67 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_292 ) ==
V_166 )
return V_166 ;
V_291 = F_135 ( V_143 ) ;
if ( V_291 == V_293 )
return V_294 ;
if ( V_291 == V_295 ) {
if ( F_75 ( V_143 ,
F_67 ( V_39 -> V_3 ) ,
V_4 ) == V_166 )
return V_166 ;
if ( F_77 ( V_143 , V_39 -> V_3 ) == V_166 )
return V_166 ;
} else if ( F_67 ( V_39 -> V_3 ) ) {
memcpy ( V_289 , V_288 , F_60 ( V_289 ) ) ;
V_289 -> V_253 . V_252 . V_124 = & V_289 -> V_253 . V_124 ;
V_289 -> V_253 . V_252 . V_251 . V_144 = (struct V_130 * ) V_289 -> V_144 ;
V_289 -> V_253 . V_252 . V_251 . V_281 = & V_289 -> V_281 ;
F_136 ( ( const struct V_26 * ) V_289 -> V_144 ,
& V_289 -> V_281 , V_124 ,
V_39 -> V_3 ,
F_137 ( V_143 ) ,
V_61 -> V_62 -> V_266 ,
V_289 -> V_138 ,
false ) ;
return V_166 ;
}
return V_294 ;
}
static bool F_138 ( const struct V_136 * V_288 ,
struct V_136 * V_289 ,
T_8 * V_296 , bool V_155 )
{
const struct V_26 * V_297 = ( const struct V_26 * ) V_288 -> V_144 ;
struct V_26 * V_298 = (struct V_26 * ) V_289 -> V_144 ;
if ( V_297 -> V_22 == V_299 ||
V_297 -> V_22 == V_300 ) {
memcpy ( V_289 , V_288 , F_60 ( V_289 ) ) ;
V_289 -> V_253 . V_252 . V_124 = & V_289 -> V_253 . V_124 ;
V_289 -> V_253 . V_252 . V_251 . V_144 = (struct V_130 * ) V_289 -> V_144 ;
V_289 -> V_253 . V_252 . V_251 . V_281 = & V_289 -> V_281 ;
V_298 -> V_22 = V_301 ;
V_298 -> V_125 = F_139 ( V_302 ) ;
if ( V_297 -> V_8 == V_9 )
V_298 -> V_125 |= V_303 ;
if ( V_155 && V_297 -> V_168 == V_169 ) {
if ( V_297 -> V_8 ==
V_58 ||
V_297 -> V_8 ==
V_9 )
* V_296 = F_140 (
(struct V_145 * ) V_288 -> V_144 ) ;
else
* V_296 = sizeof( struct V_26 ) ;
}
return true ;
} else {
return false ;
}
}
static enum V_287
F_141 ( struct V_1 * V_39 ,
struct V_93 * V_61 ,
struct V_123 * V_124 ,
int V_4 ,
struct V_136 * V_288 ,
struct V_136 * V_289 )
{
enum V_290 V_291 ;
struct V_145 * V_143 = (struct V_145 * ) V_288 -> V_144 ;
if ( F_142 ( V_143 ,
F_67 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_292 ) ==
V_166 )
return V_166 ;
V_291 = F_143 ( V_143 ) ;
if ( V_291 == V_293 )
return V_294 ;
if ( V_291 == V_295 ) {
if ( F_69 ( V_143 ,
F_67 ( V_39 -> V_3 ) ,
V_4 ) == V_166 )
return V_166 ;
if ( F_72 ( V_143 , V_39 -> V_3 ) ==
V_166 )
return V_166 ;
} else if ( F_67 ( V_39 -> V_3 ) ) {
memcpy ( V_289 , V_288 , F_60 ( V_289 ) ) ;
V_289 -> V_253 . V_252 . V_124 = & V_289 -> V_253 . V_124 ;
V_289 -> V_253 . V_252 . V_251 . V_204 =
(struct V_204 * ) V_289 -> V_144 ;
V_289 -> V_253 . V_252 . V_251 . V_281 = & V_289 -> V_281 ;
F_136 ( ( const struct V_26 * ) V_289 -> V_144 ,
& V_289 -> V_281 , V_124 ,
V_39 -> V_3 ,
F_144 ( V_143 ) ,
V_61 -> V_62 -> V_266 ,
V_288 -> V_253 . V_124 . V_129 ,
true ) ;
return V_166 ;
}
return V_294 ;
}
static enum V_287
F_145 ( struct V_1 * V_39 ,
struct V_93 * V_61 ,
struct V_123 * V_124 ,
int V_4 ,
struct V_136 * V_288 ,
struct V_136 * V_289 ,
bool V_155 )
{
struct V_26 * V_262 = (struct V_26 * ) V_288 -> V_144 ;
if ( V_155 && V_262 -> V_168 == V_169 &&
V_262 -> V_158 == V_304 )
return F_141 ( V_39 , V_61 , V_124 , V_4 , V_288 ,
V_289 ) ;
return F_133 ( V_39 , V_61 , V_124 , V_4 , V_288 , V_289 ) ;
}
static void F_146 ( struct V_1 * V_39 ,
struct V_123 * V_124 )
{
struct V_93 * V_61 ;
struct V_247 * V_248 ;
struct V_136 * V_288 , * V_289 = NULL ;
struct V_107 * V_108 ;
struct V_42 * V_106 ;
int V_4 ;
int V_40 = V_173 ;
T_8 V_138 ;
T_7 V_305 = 0 ;
bool V_155 ;
V_108 = (struct V_107 * ) ( unsigned long ) V_124 -> V_120 ;
V_61 = V_108 -> V_110 -> V_61 ;
F_55 ( V_108 ) ;
V_155 = F_66 ( V_61 -> V_39 -> V_3 ,
V_61 -> V_39 -> V_4 ) ;
V_248 = F_54 ( V_108 , struct V_247 ,
V_108 ) ;
V_288 = F_54 ( V_248 , struct V_136 , V_253 ) ;
F_98 ( V_39 -> V_3 ,
V_288 -> V_253 . V_306 ,
F_64 ( V_288 ) ,
V_307 ) ;
V_288 -> V_253 . V_124 = * V_124 ;
V_288 -> V_253 . V_252 . V_124 = & V_288 -> V_253 . V_124 ;
if ( V_155 && ( (struct V_26 * ) ( V_288 -> V_144 ) ) -> V_168 == V_169 ) {
V_288 -> V_253 . V_252 . V_308 = V_124 -> V_129 - sizeof( struct V_131 ) ;
V_288 -> V_253 . V_252 . V_309 = sizeof( struct V_204 ) ;
} else {
V_288 -> V_253 . V_252 . V_308 = sizeof( struct V_130 ) ;
V_288 -> V_253 . V_252 . V_309 = sizeof( struct V_130 ) ;
}
V_288 -> V_253 . V_252 . V_251 . V_144 = (struct V_130 * ) V_288 -> V_144 ;
V_288 -> V_253 . V_252 . V_251 . V_281 = & V_288 -> V_281 ;
if ( F_147 ( & V_61 -> V_102 ) )
F_58 ( V_61 , & V_288 -> V_253 . V_252 , V_92 ) ;
if ( ! F_117 ( ( const struct V_26 * ) V_288 -> V_144 , V_61 , V_155 ) )
goto V_101;
V_138 = V_288 -> V_138 ;
V_289 = F_61 ( V_138 , V_64 ) ;
if ( ! V_289 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_30 ) ;
goto V_101;
}
if ( F_67 ( V_39 -> V_3 ) )
V_4 = V_124 -> V_4 ;
else
V_4 = V_39 -> V_4 ;
if ( ( (struct V_26 * ) V_288 -> V_144 ) -> V_8 ==
V_9 ) {
if ( F_145 ( V_39 , V_61 , V_124 , V_4 , V_288 ,
V_289 , V_155 )
== V_166 )
goto V_101;
}
if ( V_39 -> V_3 -> V_172 ) {
V_40 = V_39 -> V_3 -> V_172 ( V_39 -> V_3 , 0 ,
V_39 -> V_4 ,
V_124 , & V_288 -> V_281 ,
( const struct V_26 * ) V_288 -> V_144 ,
V_288 -> V_138 ,
(struct V_26 * ) V_289 -> V_144 ,
& V_138 , & V_305 ) ;
if ( V_155 )
V_124 -> V_122 = V_305 ;
if ( V_40 & V_173 ) {
if ( V_40 & V_175 )
goto V_101;
if ( V_40 & V_174 ) {
F_136 ( ( const struct V_26 * ) V_289 -> V_144 ,
& V_288 -> V_281 , V_124 ,
V_39 -> V_3 ,
V_4 ,
V_61 -> V_62 -> V_266 ,
V_138 , V_155 ) ;
goto V_101;
}
}
}
V_106 = F_80 ( V_39 , ( const struct V_26 * ) V_288 -> V_144 ) ;
if ( V_106 ) {
F_129 ( V_106 , & V_288 -> V_253 . V_252 ) ;
V_288 = NULL ;
} else if ( ( V_40 & V_173 ) &&
F_138 ( V_288 , V_289 , & V_138 , V_155 ) ) {
F_136 ( ( const struct V_26 * ) V_289 -> V_144 , & V_288 -> V_281 , V_124 ,
V_39 -> V_3 , V_4 ,
V_61 -> V_62 -> V_266 , V_138 , V_155 ) ;
}
V_101:
if ( V_289 ) {
F_148 ( V_61 , V_289 ) ;
F_31 ( V_288 ) ;
} else
F_148 ( V_61 , V_288 ) ;
}
static void F_149 ( struct V_42 * V_43 )
{
struct V_140 * V_141 ;
unsigned long V_310 ;
if ( F_150 ( & V_43 -> V_74 ) ) {
F_45 ( & V_43 -> V_77 ) ;
} else {
V_141 = F_151 ( V_43 -> V_74 . V_198 ,
struct V_140 ,
V_89 ) ;
if ( F_152 ( V_43 -> V_239 ,
V_141 -> V_239 ) ) {
V_43 -> V_239 = V_141 -> V_239 ;
V_310 = V_141 -> V_239 - V_311 ;
if ( ( long ) V_310 <= 0 )
V_310 = 1 ;
F_153 ( V_43 -> V_61 -> V_39 -> V_105 ,
& V_43 -> V_77 , V_310 ) ;
}
}
}
static void F_154 ( struct V_140 * V_141 )
{
struct V_42 * V_43 ;
struct V_140 * V_312 ;
struct V_223 * V_313 ;
unsigned long V_310 ;
V_43 = V_141 -> V_43 ;
F_47 ( & V_141 -> V_89 ) ;
V_310 = V_141 -> V_239 ;
V_141 -> V_239 += V_311 ;
if ( V_310 ) {
F_155 (list_item, &mad_agent_priv->wait_list) {
V_312 = F_151 ( V_313 ,
struct V_140 ,
V_89 ) ;
if ( F_152 ( V_141 -> V_239 ,
V_312 -> V_239 ) )
break;
}
}
else
V_313 = & V_43 -> V_74 ;
F_130 ( & V_141 -> V_89 , V_313 ) ;
if ( V_43 -> V_74 . V_198 == & V_141 -> V_89 )
F_153 ( V_43 -> V_61 -> V_39 -> V_105 ,
& V_43 -> V_77 , V_310 ) ;
}
void F_156 ( struct V_140 * V_141 ,
int V_236 )
{
V_141 -> V_239 = F_101 ( V_236 ) ;
F_154 ( V_141 ) ;
}
void F_132 ( struct V_140 * V_141 ,
struct V_115 * V_116 )
{
struct V_42 * V_43 ;
unsigned long V_6 ;
int V_40 ;
V_43 = V_141 -> V_43 ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
if ( F_87 ( & V_43 -> V_66 ) ) {
V_40 = F_157 ( V_141 , V_116 ) ;
if ( V_40 == V_243 )
goto V_314;
} else
V_40 = V_315 ;
if ( V_116 -> V_125 != V_126 &&
V_141 -> V_125 == V_126 ) {
V_141 -> V_125 = V_116 -> V_125 ;
V_141 -> V_82 -= ( V_141 -> V_239 > 0 ) ;
}
if ( -- V_141 -> V_82 > 0 ) {
if ( V_141 -> V_82 == 1 && V_141 -> V_239 &&
V_141 -> V_125 == V_126 ) {
F_154 ( V_141 ) ;
}
goto V_314;
}
F_47 ( & V_141 -> V_89 ) ;
F_149 ( V_43 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
if ( V_141 -> V_125 != V_126 )
V_116 -> V_125 = V_141 -> V_125 ;
if ( V_40 == V_316 )
F_158 ( V_116 ) ;
else
V_43 -> V_66 . V_35 ( & V_43 -> V_66 ,
V_116 ) ;
F_39 ( V_43 ) ;
return;
V_314:
F_5 ( & V_43 -> V_72 , V_6 ) ;
}
static void F_159 ( struct V_1 * V_39 ,
struct V_123 * V_124 )
{
struct V_140 * V_141 , * V_317 ;
struct V_107 * V_108 ;
struct V_93 * V_61 ;
struct V_109 * V_227 ;
struct V_151 * V_224 ;
struct V_115 V_116 ;
unsigned long V_6 ;
int V_40 ;
V_108 = (struct V_107 * ) ( unsigned long ) V_124 -> V_120 ;
V_141 = F_54 ( V_108 , struct V_140 ,
V_108 ) ;
V_227 = V_108 -> V_110 ;
V_61 = V_227 -> V_61 ;
V_318:
F_98 ( V_141 -> V_114 . V_106 -> V_3 ,
V_141 -> V_230 ,
V_141 -> V_205 [ 0 ] . V_206 , V_229 ) ;
F_98 ( V_141 -> V_114 . V_106 -> V_3 ,
V_141 -> V_231 ,
V_141 -> V_205 [ 1 ] . V_206 , V_229 ) ;
V_317 = NULL ;
F_4 ( & V_227 -> V_72 , V_6 ) ;
F_47 ( & V_108 -> V_111 ) ;
if ( V_227 -> V_112 -- > V_227 -> V_232 ) {
V_108 = F_54 ( V_61 -> V_233 . V_198 ,
struct V_107 , V_111 ) ;
V_317 = F_54 ( V_108 ,
struct V_140 ,
V_108 ) ;
F_128 ( & V_108 -> V_111 , & V_227 -> V_111 ) ;
}
F_5 ( & V_227 -> V_72 , V_6 ) ;
V_116 . V_114 = & V_141 -> V_114 ;
V_116 . V_125 = V_124 -> V_125 ;
V_116 . V_286 = V_124 -> V_286 ;
if ( F_147 ( & V_61 -> V_102 ) )
F_57 ( V_61 , & V_141 -> V_114 , & V_116 ,
V_91 ) ;
F_132 ( V_141 , & V_116 ) ;
if ( V_317 ) {
V_40 = F_99 ( V_61 -> V_62 , & V_317 -> V_152 ,
& V_224 ) ;
if ( V_40 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_31 , V_40 ) ;
V_141 = V_317 ;
V_124 -> V_125 = V_319 ;
goto V_318;
}
}
}
static void F_160 ( struct V_93 * V_61 )
{
struct V_140 * V_141 ;
struct V_107 * V_108 ;
unsigned long V_6 ;
F_4 ( & V_61 -> V_227 . V_72 , V_6 ) ;
F_2 (mad_list, &qp_info->send_queue.list, list) {
V_141 = F_54 ( V_108 ,
struct V_140 ,
V_108 ) ;
V_141 -> V_318 = 1 ;
}
F_5 ( & V_61 -> V_227 . V_72 , V_6 ) ;
}
static void F_161 ( struct V_1 * V_39 ,
struct V_123 * V_124 )
{
struct V_107 * V_108 ;
struct V_93 * V_61 ;
struct V_140 * V_141 ;
int V_40 ;
V_108 = (struct V_107 * ) ( unsigned long ) V_124 -> V_120 ;
V_61 = V_108 -> V_110 -> V_61 ;
if ( V_108 -> V_110 == & V_61 -> V_320 )
return;
V_141 = F_54 ( V_108 , struct V_140 ,
V_108 ) ;
if ( V_124 -> V_125 == V_321 ) {
if ( V_141 -> V_318 ) {
struct V_151 * V_224 ;
V_141 -> V_318 = 0 ;
V_40 = F_99 ( V_61 -> V_62 , & V_141 -> V_152 ,
& V_224 ) ;
if ( V_40 )
F_159 ( V_39 , V_124 ) ;
} else
F_159 ( V_39 , V_124 ) ;
} else {
struct V_322 * V_270 ;
V_270 = F_79 ( sizeof *V_270 , V_64 ) ;
if ( V_270 ) {
V_270 -> V_323 = V_324 ;
V_270 -> V_325 = V_326 ;
V_40 = F_162 ( V_61 -> V_62 , V_270 ,
V_327 | V_328 ) ;
F_31 ( V_270 ) ;
if ( V_40 )
F_70 ( & V_39 -> V_3 -> V_52 ,
L_32 ,
V_40 ) ;
else
F_160 ( V_61 ) ;
}
F_159 ( V_39 , V_124 ) ;
}
}
static void F_163 ( struct V_329 * V_330 )
{
struct V_1 * V_39 ;
struct V_123 V_124 ;
V_39 = F_54 ( V_330 , struct V_1 , V_330 ) ;
F_164 ( V_39 -> V_331 , V_332 ) ;
while ( F_165 ( V_39 -> V_331 , 1 , & V_124 ) == 1 ) {
if ( V_124 . V_125 == V_126 ) {
switch ( V_124 . V_127 ) {
case V_333 :
F_159 ( V_39 , & V_124 ) ;
break;
case V_128 :
F_146 ( V_39 , & V_124 ) ;
break;
default:
F_56 ( 1 ) ;
break;
}
} else
F_161 ( V_39 , & V_124 ) ;
}
}
static void F_44 ( struct V_42 * V_43 )
{
unsigned long V_6 ;
struct V_140 * V_141 , * V_312 ;
struct V_115 V_116 ;
struct V_223 V_334 ;
F_23 ( & V_334 ) ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
F_84 (mad_send_wr, temp_mad_send_wr,
&mad_agent_priv->send_list, agent_list) {
if ( V_141 -> V_125 == V_126 ) {
V_141 -> V_125 = V_321 ;
V_141 -> V_82 -= ( V_141 -> V_239 > 0 ) ;
}
}
F_104 ( & V_43 -> V_74 , & V_334 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
V_116 . V_125 = V_321 ;
V_116 . V_286 = 0 ;
F_84 (mad_send_wr, temp_mad_send_wr,
&cancel_list, agent_list) {
V_116 . V_114 = & V_141 -> V_114 ;
F_47 ( & V_141 -> V_89 ) ;
V_43 -> V_66 . V_35 ( & V_43 -> V_66 ,
& V_116 ) ;
F_52 ( & V_43 -> V_82 ) ;
}
}
static struct V_140 *
F_166 ( struct V_42 * V_43 ,
struct V_113 * V_114 )
{
struct V_140 * V_141 ;
F_2 (mad_send_wr, &mad_agent_priv->wait_list,
agent_list) {
if ( & V_141 -> V_114 == V_114 )
return V_141 ;
}
F_2 (mad_send_wr, &mad_agent_priv->send_list,
agent_list) {
if ( F_118 ( V_43 ,
V_141 -> V_114 . V_144 ) &&
& V_141 -> V_114 == V_114 )
return V_141 ;
}
return NULL ;
}
int F_167 ( struct V_33 * V_106 ,
struct V_113 * V_114 , T_4 V_236 )
{
struct V_42 * V_43 ;
struct V_140 * V_141 ;
unsigned long V_6 ;
int V_335 ;
V_43 = F_54 ( V_106 , struct V_42 ,
V_66 ) ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
V_141 = F_166 ( V_43 , V_114 ) ;
if ( ! V_141 || V_141 -> V_125 != V_126 ) {
F_5 ( & V_43 -> V_72 , V_6 ) ;
return - V_41 ;
}
V_335 = ( ! V_141 -> V_239 || V_141 -> V_82 > 1 ) ;
if ( ! V_236 ) {
V_141 -> V_125 = V_321 ;
V_141 -> V_82 -= ( V_141 -> V_239 > 0 ) ;
}
V_141 -> V_114 . V_236 = V_236 ;
if ( V_335 )
V_141 -> V_239 = F_101 ( V_236 ) ;
else
F_156 ( V_141 , V_236 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
return 0 ;
}
void F_168 ( struct V_33 * V_106 ,
struct V_113 * V_114 )
{
F_167 ( V_106 , V_114 , 0 ) ;
}
static void V_81 ( struct V_329 * V_330 )
{
struct V_42 * V_43 ;
struct V_146 * V_147 ;
struct V_42 * V_149 ;
unsigned long V_6 ;
int V_336 ;
struct V_123 V_124 ;
struct V_115 V_116 ;
bool V_155 ;
V_43 =
F_54 ( V_330 , struct V_42 , V_80 ) ;
V_155 = F_66 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
while ( ! F_150 ( & V_43 -> V_79 ) ) {
V_147 = F_151 ( V_43 -> V_79 . V_198 ,
struct V_146 ,
V_177 ) ;
F_47 ( & V_147 -> V_177 ) ;
F_5 ( & V_43 -> V_72 , V_6 ) ;
V_336 = 0 ;
if ( V_147 -> V_148 ) {
T_1 V_168 ;
V_149 = V_147 -> V_149 ;
if ( ! V_149 ) {
F_70 ( & V_43 -> V_66 . V_3 -> V_52 ,
L_33 ) ;
V_336 = 1 ;
goto V_337;
}
F_59 ( V_149 -> V_66 . V_62 ,
( unsigned long ) V_147 -> V_141 ,
F_76 ( V_167 ) ,
V_147 -> V_141 -> V_152 . V_156 . V_157 . V_122 ,
V_149 -> V_66 . V_4 , & V_124 ) ;
V_147 -> V_148 -> V_253 . V_252 . V_124 = & V_124 ;
V_168 = ( (struct V_26 * ) ( V_147 -> V_148 -> V_144 ) ) -> V_168 ;
if ( V_155 && V_168 == V_169 ) {
V_147 -> V_148 -> V_253 . V_252 . V_308 = V_147 -> V_176 ;
V_147 -> V_148 -> V_253 . V_252 . V_309 = sizeof( struct V_204 ) ;
} else {
V_147 -> V_148 -> V_253 . V_252 . V_308 = sizeof( struct V_130 ) ;
V_147 -> V_148 -> V_253 . V_252 . V_309 = sizeof( struct V_130 ) ;
}
F_23 ( & V_147 -> V_148 -> V_253 . V_252 . V_76 ) ;
F_130 ( & V_147 -> V_148 -> V_253 . V_252 . V_251 . V_111 ,
& V_147 -> V_148 -> V_253 . V_252 . V_76 ) ;
V_147 -> V_148 -> V_253 . V_252 . V_251 . V_281 = NULL ;
V_147 -> V_148 -> V_253 . V_252 . V_251 . V_144 =
(struct V_130 * ) V_147 -> V_148 -> V_144 ;
if ( F_147 ( & V_149 -> V_61 -> V_102 ) )
F_58 ( V_149 -> V_61 ,
& V_147 -> V_148 -> V_253 . V_252 ,
V_92 ) ;
V_149 -> V_66 . V_36 (
& V_149 -> V_66 ,
& V_147 -> V_148 -> V_253 . V_252 ) ;
F_4 ( & V_149 -> V_72 , V_6 ) ;
F_52 ( & V_149 -> V_82 ) ;
F_5 ( & V_149 -> V_72 , V_6 ) ;
}
V_337:
V_116 . V_125 = V_126 ;
V_116 . V_286 = 0 ;
V_116 . V_114 = & V_147 -> V_141 -> V_114 ;
if ( F_147 ( & V_43 -> V_61 -> V_102 ) )
F_57 ( V_43 -> V_61 ,
& V_147 -> V_141 -> V_114 ,
& V_116 , V_91 ) ;
V_43 -> V_66 . V_35 ( & V_43 -> V_66 ,
& V_116 ) ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
F_52 ( & V_43 -> V_82 ) ;
if ( V_336 )
F_31 ( V_147 -> V_148 ) ;
F_31 ( V_147 ) ;
}
F_5 ( & V_43 -> V_72 , V_6 ) ;
}
static int F_169 ( struct V_140 * V_141 )
{
int V_40 ;
if ( ! V_141 -> V_242 )
return - V_338 ;
V_141 -> V_242 -- ;
V_141 -> V_114 . V_241 ++ ;
V_141 -> V_239 = F_101 ( V_141 -> V_114 . V_236 ) ;
if ( F_87 ( & V_141 -> V_43 -> V_66 ) ) {
V_40 = F_170 ( V_141 ) ;
switch ( V_40 ) {
case V_315 :
V_40 = F_94 ( V_141 ) ;
break;
case V_243 :
V_40 = 0 ;
break;
default:
V_40 = - V_339 ;
break;
}
} else
V_40 = F_94 ( V_141 ) ;
if ( ! V_40 ) {
V_141 -> V_82 ++ ;
F_30 ( & V_141 -> V_89 ,
& V_141 -> V_43 -> V_73 ) ;
}
return V_40 ;
}
static void V_78 ( struct V_329 * V_330 )
{
struct V_42 * V_43 ;
struct V_140 * V_141 ;
struct V_115 V_116 ;
unsigned long V_6 , V_310 ;
V_43 = F_54 ( V_330 , struct V_42 ,
V_77 . V_330 ) ;
V_116 . V_286 = 0 ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
while ( ! F_150 ( & V_43 -> V_74 ) ) {
V_141 = F_151 ( V_43 -> V_74 . V_198 ,
struct V_140 ,
V_89 ) ;
if ( F_152 ( V_141 -> V_239 , V_311 ) ) {
V_310 = V_141 -> V_239 - V_311 ;
if ( ( long ) V_310 <= 0 )
V_310 = 1 ;
F_171 ( V_43 -> V_61 ->
V_39 -> V_105 ,
& V_43 -> V_77 , V_310 ) ;
break;
}
F_47 ( & V_141 -> V_89 ) ;
if ( V_141 -> V_125 == V_126 &&
! F_169 ( V_141 ) )
continue;
F_5 ( & V_43 -> V_72 , V_6 ) ;
if ( V_141 -> V_125 == V_126 )
V_116 . V_125 = V_340 ;
else
V_116 . V_125 = V_141 -> V_125 ;
V_116 . V_114 = & V_141 -> V_114 ;
V_43 -> V_66 . V_35 ( & V_43 -> V_66 ,
& V_116 ) ;
F_52 ( & V_43 -> V_82 ) ;
F_4 ( & V_43 -> V_72 , V_6 ) ;
}
F_5 ( & V_43 -> V_72 , V_6 ) ;
}
static void F_172 ( struct V_341 * V_331 , void * V_342 )
{
struct V_1 * V_39 = V_331 -> V_343 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
if ( ! F_150 ( & V_39 -> V_344 ) )
F_81 ( V_39 -> V_105 , & V_39 -> V_330 ) ;
F_5 ( & V_7 , V_6 ) ;
}
static int F_148 ( struct V_93 * V_61 ,
struct V_136 * V_144 )
{
unsigned long V_6 ;
int V_345 , V_40 ;
struct V_136 * V_148 ;
struct V_225 V_205 ;
struct V_346 V_347 , * V_348 ;
struct V_109 * V_320 = & V_61 -> V_320 ;
V_205 . V_207 = ( * V_61 -> V_39 -> V_67 ) . V_207 ;
V_347 . V_198 = NULL ;
V_347 . V_205 = & V_205 ;
V_347 . V_208 = 1 ;
do {
if ( V_144 ) {
V_148 = V_144 ;
V_144 = NULL ;
} else {
V_148 = F_61 ( F_62 ( V_61 -> V_39 ) ,
V_100 ) ;
if ( ! V_148 ) {
F_70 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_34 ) ;
V_40 = - V_65 ;
break;
}
}
V_205 . V_206 = F_64 ( V_148 ) ;
V_205 . V_228 = F_95 ( V_61 -> V_39 -> V_3 ,
& V_148 -> V_281 ,
F_64 ( V_148 ) ,
V_307 ) ;
if ( F_96 ( F_97 ( V_61 -> V_39 -> V_3 ,
V_205 . V_228 ) ) ) {
V_40 = - V_65 ;
break;
}
V_148 -> V_253 . V_306 = V_205 . V_228 ;
V_347 . V_120 = ( unsigned long ) & V_148 -> V_253 . V_108 ;
V_148 -> V_253 . V_108 . V_110 = V_320 ;
F_4 ( & V_320 -> V_72 , V_6 ) ;
V_345 = ( ++ V_320 -> V_112 < V_320 -> V_232 ) ;
F_30 ( & V_148 -> V_253 . V_108 . V_111 , & V_320 -> V_111 ) ;
F_5 ( & V_320 -> V_72 , V_6 ) ;
V_40 = F_173 ( V_61 -> V_62 , & V_347 , & V_348 ) ;
if ( V_40 ) {
F_4 ( & V_320 -> V_72 , V_6 ) ;
F_47 ( & V_148 -> V_253 . V_108 . V_111 ) ;
V_320 -> V_112 -- ;
F_5 ( & V_320 -> V_72 , V_6 ) ;
F_98 ( V_61 -> V_39 -> V_3 ,
V_148 -> V_253 . V_306 ,
F_64 ( V_148 ) ,
V_307 ) ;
F_31 ( V_148 ) ;
F_70 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_35 , V_40 ) ;
break;
}
} while ( V_345 );
return V_40 ;
}
static void F_174 ( struct V_93 * V_61 )
{
struct V_247 * V_248 ;
struct V_136 * V_288 ;
struct V_107 * V_108 ;
if ( ! V_61 -> V_62 )
return;
while ( ! F_150 ( & V_61 -> V_320 . V_111 ) ) {
V_108 = F_151 ( V_61 -> V_320 . V_111 . V_198 ,
struct V_107 , V_111 ) ;
V_248 = F_54 ( V_108 ,
struct V_247 ,
V_108 ) ;
V_288 = F_54 ( V_248 , struct V_136 ,
V_253 ) ;
F_47 ( & V_108 -> V_111 ) ;
F_98 ( V_61 -> V_39 -> V_3 ,
V_288 -> V_253 . V_306 ,
F_64 ( V_288 ) ,
V_307 ) ;
F_31 ( V_288 ) ;
}
V_61 -> V_320 . V_112 = 0 ;
}
static int F_175 ( struct V_1 * V_39 )
{
int V_40 , V_23 ;
struct V_322 * V_270 ;
struct V_119 * V_62 ;
T_7 V_122 ;
V_270 = F_79 ( sizeof *V_270 , V_64 ) ;
if ( ! V_270 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_36 ) ;
return - V_65 ;
}
V_40 = F_176 ( V_39 -> V_3 , V_39 -> V_4 ,
V_349 , & V_122 ) ;
if ( V_40 )
V_122 = 0 ;
for ( V_23 = 0 ; V_23 < V_350 ; V_23 ++ ) {
V_62 = V_39 -> V_61 [ V_23 ] . V_62 ;
if ( ! V_62 )
continue;
V_270 -> V_323 = V_351 ;
V_270 -> V_122 = V_122 ;
V_270 -> V_352 = ( V_62 -> V_266 == 0 ) ? 0 : V_353 ;
V_40 = F_162 ( V_62 , V_270 , V_327 |
V_354 | V_355 ) ;
if ( V_40 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_37 ,
V_23 , V_40 ) ;
goto V_101;
}
V_270 -> V_323 = V_356 ;
V_40 = F_162 ( V_62 , V_270 , V_327 ) ;
if ( V_40 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_38 ,
V_23 , V_40 ) ;
goto V_101;
}
V_270 -> V_323 = V_324 ;
V_270 -> V_357 = V_358 ;
V_40 = F_162 ( V_62 , V_270 , V_327 | V_359 ) ;
if ( V_40 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_39 ,
V_23 , V_40 ) ;
goto V_101;
}
}
V_40 = F_164 ( V_39 -> V_331 , V_332 ) ;
if ( V_40 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_40 ,
V_40 ) ;
goto V_101;
}
for ( V_23 = 0 ; V_23 < V_350 ; V_23 ++ ) {
if ( ! V_39 -> V_61 [ V_23 ] . V_62 )
continue;
V_40 = F_148 ( & V_39 -> V_61 [ V_23 ] , NULL ) ;
if ( V_40 ) {
F_70 ( & V_39 -> V_3 -> V_52 ,
L_41 ) ;
goto V_101;
}
}
V_101:
F_31 ( V_270 ) ;
return V_40 ;
}
static void F_177 ( struct V_360 * V_361 , void * V_362 )
{
struct V_93 * V_61 = V_362 ;
F_70 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_42 ,
V_361 -> V_361 , V_61 -> V_62 -> V_266 ) ;
}
static void F_178 ( struct V_93 * V_61 ,
struct V_109 * V_110 )
{
V_110 -> V_61 = V_61 ;
V_110 -> V_112 = 0 ;
F_22 ( & V_110 -> V_72 ) ;
F_23 ( & V_110 -> V_111 ) ;
}
static void F_179 ( struct V_1 * V_39 ,
struct V_93 * V_61 )
{
V_61 -> V_39 = V_39 ;
F_178 ( V_61 , & V_61 -> V_227 ) ;
F_178 ( V_61 , & V_61 -> V_320 ) ;
F_23 ( & V_61 -> V_233 ) ;
F_22 ( & V_61 -> V_97 ) ;
V_61 -> V_99 = NULL ;
V_61 -> V_98 = 0 ;
F_26 ( & V_61 -> V_102 , 0 ) ;
}
static int F_180 ( struct V_93 * V_61 ,
enum V_10 V_11 )
{
struct V_363 V_364 ;
int V_40 ;
memset ( & V_364 , 0 , sizeof V_364 ) ;
V_364 . V_365 = V_61 -> V_39 -> V_331 ;
V_364 . V_366 = V_61 -> V_39 -> V_331 ;
V_364 . V_367 = V_368 ;
V_364 . V_369 . V_370 = V_371 ;
V_364 . V_369 . V_372 = V_373 ;
V_364 . V_369 . V_374 = V_375 ;
V_364 . V_369 . V_376 = V_377 ;
V_364 . V_11 = V_11 ;
V_364 . V_4 = V_61 -> V_39 -> V_4 ;
V_364 . V_362 = V_61 ;
V_364 . V_378 = F_177 ;
V_61 -> V_62 = F_181 ( V_61 -> V_39 -> V_68 , & V_364 ) ;
if ( F_20 ( V_61 -> V_62 ) ) {
F_70 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_43 ,
F_7 ( V_11 ) ) ;
V_40 = F_182 ( V_61 -> V_62 ) ;
goto error;
}
V_61 -> V_227 . V_232 = V_371 ;
V_61 -> V_320 . V_232 = V_373 ;
return 0 ;
error:
return V_40 ;
}
static void F_183 ( struct V_93 * V_61 )
{
if ( ! V_61 -> V_62 )
return;
F_184 ( V_61 -> V_62 ) ;
F_31 ( V_61 -> V_99 ) ;
}
static int F_185 ( struct V_2 * V_3 ,
int V_4 )
{
int V_40 , V_379 ;
struct V_1 * V_39 ;
unsigned long V_6 ;
char V_380 [ sizeof "ib_mad123"];
int V_381 ;
struct V_382 V_383 = {} ;
if ( F_186 ( F_63 ( V_3 , V_4 ) < V_384 ) )
return - V_385 ;
if ( F_186 ( F_66 ( V_3 , V_4 ) &&
F_63 ( V_3 , V_4 ) < V_386 ) )
return - V_385 ;
V_39 = F_18 ( sizeof *V_39 , V_64 ) ;
if ( ! V_39 ) {
F_70 ( & V_3 -> V_52 , L_44 ) ;
return - V_65 ;
}
V_39 -> V_3 = V_3 ;
V_39 -> V_4 = V_4 ;
F_22 ( & V_39 -> V_84 ) ;
F_23 ( & V_39 -> V_89 ) ;
F_179 ( V_39 , & V_39 -> V_61 [ 0 ] ) ;
F_179 ( V_39 , & V_39 -> V_61 [ 1 ] ) ;
V_379 = V_371 + V_373 ;
V_381 = F_187 ( V_3 , V_4 ) ;
if ( V_381 )
V_379 *= 2 ;
V_383 . V_387 = V_379 ;
V_39 -> V_331 = F_188 ( V_39 -> V_3 ,
F_172 ,
NULL , V_39 , & V_383 ) ;
if ( F_20 ( V_39 -> V_331 ) ) {
F_70 ( & V_3 -> V_52 , L_45 ) ;
V_40 = F_182 ( V_39 -> V_331 ) ;
goto V_71;
}
V_39 -> V_68 = F_189 ( V_3 ) ;
if ( F_20 ( V_39 -> V_68 ) ) {
F_70 ( & V_3 -> V_52 , L_46 ) ;
V_40 = F_182 ( V_39 -> V_68 ) ;
goto V_88;
}
V_39 -> V_67 = F_19 ( V_39 -> V_68 , V_69 ) ;
if ( F_20 ( V_39 -> V_67 ) ) {
F_70 ( & V_3 -> V_52 , L_47 ) ;
V_40 = F_182 ( V_39 -> V_67 ) ;
goto V_388;
}
if ( V_381 ) {
V_40 = F_180 ( & V_39 -> V_61 [ 0 ] , V_12 ) ;
if ( V_40 )
goto V_389;
}
V_40 = F_180 ( & V_39 -> V_61 [ 1 ] , V_13 ) ;
if ( V_40 )
goto V_390;
snprintf ( V_380 , sizeof V_380 , L_48 , V_4 ) ;
V_39 -> V_105 = F_190 ( V_380 ) ;
if ( ! V_39 -> V_105 ) {
V_40 = - V_65 ;
goto V_391;
}
F_25 ( & V_39 -> V_330 , F_163 ) ;
F_4 ( & V_7 , V_6 ) ;
F_30 ( & V_39 -> V_344 , & V_392 ) ;
F_5 ( & V_7 , V_6 ) ;
V_40 = F_175 ( V_39 ) ;
if ( V_40 ) {
F_70 ( & V_3 -> V_52 , L_49 ) ;
goto V_393;
}
return 0 ;
V_393:
F_4 ( & V_7 , V_6 ) ;
F_191 ( & V_39 -> V_344 ) ;
F_5 ( & V_7 , V_6 ) ;
F_192 ( V_39 -> V_105 ) ;
V_391:
F_183 ( & V_39 -> V_61 [ 1 ] ) ;
V_390:
F_183 ( & V_39 -> V_61 [ 0 ] ) ;
V_389:
F_32 ( V_39 -> V_67 ) ;
V_388:
F_193 ( V_39 -> V_68 ) ;
V_88:
F_194 ( V_39 -> V_331 ) ;
F_174 ( & V_39 -> V_61 [ 1 ] ) ;
F_174 ( & V_39 -> V_61 [ 0 ] ) ;
V_71:
F_31 ( V_39 ) ;
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
F_70 ( & V_3 -> V_52 , L_50 , V_4 ) ;
return - V_60 ;
}
F_191 ( & V_39 -> V_344 ) ;
F_5 ( & V_7 , V_6 ) ;
F_192 ( V_39 -> V_105 ) ;
F_183 ( & V_39 -> V_61 [ 1 ] ) ;
F_183 ( & V_39 -> V_61 [ 0 ] ) ;
F_32 ( V_39 -> V_67 ) ;
F_193 ( V_39 -> V_68 ) ;
F_194 ( V_39 -> V_331 ) ;
F_174 ( & V_39 -> V_61 [ 1 ] ) ;
F_174 ( & V_39 -> V_61 [ 0 ] ) ;
F_31 ( V_39 ) ;
return 0 ;
}
static void F_196 ( struct V_2 * V_3 )
{
int V_394 , V_23 ;
V_394 = F_197 ( V_3 ) ;
for ( V_23 = V_394 ; V_23 <= F_198 ( V_3 ) ; V_23 ++ ) {
if ( ! F_199 ( V_3 , V_23 ) )
continue;
if ( F_185 ( V_3 , V_23 ) ) {
F_70 ( & V_3 -> V_52 , L_51 , V_23 ) ;
goto error;
}
if ( F_200 ( V_3 , V_23 ) ) {
F_70 ( & V_3 -> V_52 ,
L_52 , V_23 ) ;
goto V_395;
}
}
return;
V_395:
if ( F_195 ( V_3 , V_23 ) )
F_70 ( & V_3 -> V_52 , L_53 , V_23 ) ;
error:
while ( -- V_23 >= V_394 ) {
if ( ! F_199 ( V_3 , V_23 ) )
continue;
if ( F_201 ( V_3 , V_23 ) )
F_70 ( & V_3 -> V_52 ,
L_54 , V_23 ) ;
if ( F_195 ( V_3 , V_23 ) )
F_70 ( & V_3 -> V_52 , L_53 , V_23 ) ;
}
}
static void F_202 ( struct V_2 * V_3 )
{
int V_23 ;
for ( V_23 = F_197 ( V_3 ) ; V_23 <= F_198 ( V_3 ) ; V_23 ++ ) {
if ( ! F_199 ( V_3 , V_23 ) )
continue;
if ( F_201 ( V_3 , V_23 ) )
F_70 ( & V_3 -> V_52 ,
L_54 , V_23 ) ;
if ( F_195 ( V_3 , V_23 ) )
F_70 ( & V_3 -> V_52 , L_53 , V_23 ) ;
}
}
static int T_10 F_203 ( void )
{
V_373 = F_204 ( V_373 , V_396 ) ;
V_373 = F_205 ( V_373 , V_397 ) ;
V_371 = F_204 ( V_371 , V_396 ) ;
V_371 = F_205 ( V_371 , V_397 ) ;
F_23 ( & V_392 ) ;
if ( F_206 ( & V_398 ) ) {
F_108 ( L_55 ) ;
return - V_41 ;
}
return 0 ;
}
static void T_11 F_207 ( void )
{
F_208 ( & V_398 ) ;
}
