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
V_49 = F_26 ( & V_43 -> V_67 , V_11 ) ;
if ( V_49 ) {
V_40 = F_15 ( V_49 ) ;
goto V_80;
}
F_4 ( & V_39 -> V_81 , V_6 ) ;
V_43 -> V_67 . V_82 = ++ V_83 ;
if ( V_20 ) {
V_8 = F_6 ( V_20 -> V_8 ) ;
if ( ! F_9 ( V_8 ) ) {
V_46 = V_39 -> V_84 [ V_20 ->
V_55 ] . V_46 ;
if ( V_46 ) {
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
if ( F_12 ( & V_22 ,
V_20 ) )
goto V_85;
}
}
V_49 = F_27 ( V_20 , V_43 ,
V_8 ) ;
} else {
V_48 = V_39 -> V_84 [ V_20 ->
V_55 ] . V_48 ;
if ( V_48 ) {
V_51 = F_8 ( V_8 ) ;
V_18 = V_48 -> V_18 [ V_51 ] ;
if ( V_18 ) {
if ( F_11 (
V_18 ,
V_20 ) )
goto V_85;
}
}
V_49 = F_28 ( V_20 , V_43 ) ;
}
if ( V_49 ) {
V_40 = F_15 ( V_49 ) ;
goto V_85;
}
}
F_29 ( & V_43 -> V_86 , & V_39 -> V_86 ) ;
F_5 ( & V_39 -> V_81 , V_6 ) ;
return & V_43 -> V_67 ;
V_85:
F_5 ( & V_39 -> V_81 , V_6 ) ;
F_30 ( & V_43 -> V_67 ) ;
V_80:
F_31 ( V_44 ) ;
V_66:
F_31 ( V_43 ) ;
V_53:
return V_40 ;
}
static inline int F_32 ( int V_87 )
{
return ( V_87 &
(
V_88 ) ) ;
}
static inline int F_33 ( int V_87 )
{
return ( V_87 &
( V_89 ) ) ;
}
static int F_34 ( struct V_90 * V_61 ,
struct V_91 * V_92 )
{
struct V_91 * * V_93 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_94 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_95 ; V_23 ++ )
if ( ! V_61 -> V_96 [ V_23 ] )
break;
if ( V_23 == V_61 -> V_95 ) {
V_93 = F_35 ( V_61 -> V_96 ,
sizeof V_92 *
( V_61 -> V_95 + 1 ) ,
V_97 ) ;
if ( ! V_93 ) {
V_23 = - V_65 ;
goto V_98;
}
V_61 -> V_96 = V_93 ;
V_61 -> V_95 ++ ;
}
V_61 -> V_96 [ V_23 ] = V_92 ;
F_36 ( & V_61 -> V_99 ) ;
V_98:
F_5 ( & V_61 -> V_94 , V_6 ) ;
return V_23 ;
}
struct V_33 * F_37 ( struct V_2 * V_3 ,
T_1 V_4 ,
enum V_10 V_11 ,
int V_87 ,
T_5 V_100 ,
T_3 V_36 ,
void * V_37 )
{
struct V_1 * V_39 ;
struct V_33 * V_40 ;
struct V_91 * V_92 ;
int V_50 ;
int V_101 ;
if ( ( F_32 ( V_87 ) && ! V_100 ) ||
( F_33 ( V_87 ) && ! V_36 ) ) {
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
V_92 = F_18 ( sizeof *V_92 , V_64 ) ;
if ( ! V_92 ) {
V_40 = F_15 ( - V_65 ) ;
goto V_53;
}
V_92 -> V_61 = & V_39 -> V_61 [ V_50 ] ;
V_92 -> V_67 . V_3 = V_3 ;
V_92 -> V_67 . V_36 = V_36 ;
V_92 -> V_67 . V_100 = V_100 ;
V_92 -> V_67 . V_37 = V_37 ;
V_92 -> V_67 . V_62 = V_39 -> V_61 [ V_50 ] . V_62 ;
V_92 -> V_67 . V_4 = V_4 ;
V_92 -> V_87 = V_87 ;
F_25 ( & V_92 -> V_79 ) ;
V_101 = F_26 ( & V_92 -> V_67 , V_11 ) ;
if ( V_101 ) {
V_40 = F_15 ( V_101 ) ;
goto V_102;
}
V_92 -> V_103 = F_34 (
& V_39 -> V_61 [ V_50 ] ,
V_92 ) ;
if ( V_92 -> V_103 < 0 ) {
V_40 = F_15 ( V_92 -> V_103 ) ;
goto V_66;
}
F_24 ( & V_92 -> V_78 , 1 ) ;
return & V_92 -> V_67 ;
V_66:
F_30 ( & V_92 -> V_67 ) ;
V_102:
F_31 ( V_92 ) ;
V_53:
return V_40 ;
}
static inline void F_38 ( struct V_42 * V_43 )
{
if ( F_39 ( & V_43 -> V_78 ) )
F_40 ( & V_43 -> V_79 ) ;
}
static inline void F_41 ( struct V_91 * V_92 )
{
if ( F_39 ( & V_92 -> V_78 ) )
F_40 ( & V_92 -> V_79 ) ;
}
static void F_42 ( struct V_42 * V_43 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_43 ( V_43 ) ;
V_39 = V_43 -> V_61 -> V_39 ;
F_44 ( & V_43 -> V_73 ) ;
F_4 ( & V_39 -> V_81 , V_6 ) ;
F_45 ( V_43 ) ;
F_46 ( & V_43 -> V_86 ) ;
F_5 ( & V_39 -> V_81 , V_6 ) ;
F_47 ( V_39 -> V_104 ) ;
F_48 ( V_43 ) ;
F_38 ( V_43 ) ;
F_49 ( & V_43 -> V_79 ) ;
F_30 ( & V_43 -> V_67 ) ;
F_31 ( V_43 -> V_44 ) ;
F_31 ( V_43 ) ;
}
static void F_50 ( struct V_91 * V_92 )
{
struct V_90 * V_61 ;
unsigned long V_6 ;
V_61 = V_92 -> V_61 ;
F_4 ( & V_61 -> V_94 , V_6 ) ;
V_61 -> V_96 [ V_92 -> V_103 ] = NULL ;
F_51 ( & V_61 -> V_99 ) ;
F_5 ( & V_61 -> V_94 , V_6 ) ;
F_41 ( V_92 ) ;
F_49 ( & V_92 -> V_79 ) ;
F_30 ( & V_92 -> V_67 ) ;
F_31 ( V_92 ) ;
}
void F_52 ( struct V_33 * V_105 )
{
struct V_42 * V_43 ;
struct V_91 * V_92 ;
if ( V_105 -> V_82 ) {
V_43 = F_53 ( V_105 ,
struct V_42 ,
V_67 ) ;
F_42 ( V_43 ) ;
} else {
V_92 = F_53 ( V_105 ,
struct V_91 ,
V_67 ) ;
F_50 ( V_92 ) ;
}
}
static void F_54 ( struct V_106 * V_107 )
{
struct V_108 * V_109 ;
unsigned long V_6 ;
F_55 ( ! V_107 -> V_109 ) ;
V_109 = V_107 -> V_109 ;
F_4 ( & V_109 -> V_68 , V_6 ) ;
F_46 ( & V_107 -> V_110 ) ;
V_109 -> V_111 -- ;
F_5 ( & V_109 -> V_68 , V_6 ) ;
}
static void F_56 ( struct V_90 * V_61 ,
struct V_112 * V_113 ,
struct V_114 * V_115 ,
int V_87 )
{
struct V_91 * V_92 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_94 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_95 ; V_23 ++ ) {
V_92 = V_61 -> V_96 [ V_23 ] ;
if ( ! V_92 ||
! ( V_92 -> V_87 & V_87 ) )
continue;
F_36 ( & V_92 -> V_78 ) ;
F_5 ( & V_61 -> V_94 , V_6 ) ;
V_92 -> V_67 . V_100 ( & V_92 -> V_67 ,
V_113 , V_115 ) ;
F_41 ( V_92 ) ;
F_4 ( & V_61 -> V_94 , V_6 ) ;
}
F_5 ( & V_61 -> V_94 , V_6 ) ;
}
static void F_57 ( struct V_90 * V_61 ,
struct V_116 * V_117 ,
int V_87 )
{
struct V_91 * V_92 ;
unsigned long V_6 ;
int V_23 ;
F_4 ( & V_61 -> V_94 , V_6 ) ;
for ( V_23 = 0 ; V_23 < V_61 -> V_95 ; V_23 ++ ) {
V_92 = V_61 -> V_96 [ V_23 ] ;
if ( ! V_92 ||
! ( V_92 -> V_87 & V_87 ) )
continue;
F_36 ( & V_92 -> V_78 ) ;
F_5 ( & V_61 -> V_94 , V_6 ) ;
V_92 -> V_67 . V_36 ( & V_92 -> V_67 , NULL ,
V_117 ) ;
F_41 ( V_92 ) ;
F_4 ( & V_61 -> V_94 , V_6 ) ;
}
F_5 ( & V_61 -> V_94 , V_6 ) ;
}
static void F_58 ( struct V_118 * V_62 , struct V_119 * V_120 , T_6 V_121 ,
T_6 V_122 , T_1 V_4 , struct V_123 * V_124 )
{
memset ( V_124 , 0 , sizeof *V_124 ) ;
V_124 -> V_125 = V_120 ;
V_124 -> V_126 = V_127 ;
V_124 -> V_128 = V_129 ;
V_124 -> V_122 = V_122 ;
V_124 -> V_130 = sizeof( struct V_131 ) + sizeof( struct V_132 ) ;
V_124 -> V_133 = V_134 ;
V_124 -> V_62 = V_62 ;
V_124 -> V_121 = V_121 ;
V_124 -> V_135 = 0 ;
V_124 -> V_136 = 0 ;
V_124 -> V_4 = V_4 ;
}
static T_7 F_59 ( const struct V_137 * V_138 )
{
return sizeof( struct V_137 ) + V_138 -> V_139 ;
}
static struct V_137 * F_60 ( T_7 V_139 , T_8 V_6 )
{
T_7 V_140 = sizeof( struct V_137 ) + V_139 ;
struct V_137 * V_40 = F_18 ( V_140 , V_6 ) ;
if ( V_40 )
V_40 -> V_139 = V_139 ;
return V_40 ;
}
static T_7 F_61 ( const struct V_1 * V_39 )
{
return F_62 ( V_39 -> V_3 , V_39 -> V_4 ) ;
}
static T_7 F_63 ( const struct V_137 * V_138 )
{
return sizeof( struct V_132 ) + V_138 -> V_139 ;
}
static int F_64 ( struct V_42 * V_43 ,
struct V_141 * V_142 )
{
int V_40 = 0 ;
struct V_143 * V_144 = V_142 -> V_113 . V_145 ;
struct V_146 * V_146 = (struct V_146 * ) V_144 ;
unsigned long V_6 ;
struct V_147 * V_148 ;
struct V_137 * V_149 ;
struct V_1 * V_39 ;
struct V_42 * V_150 = NULL ;
struct V_2 * V_3 = V_43 -> V_67 . V_3 ;
T_1 V_4 ;
struct V_123 V_151 ;
struct V_152 * V_153 = & V_142 -> V_153 ;
T_7 V_139 = F_61 ( V_43 -> V_61 -> V_39 ) ;
T_6 V_154 = 0 ;
T_6 V_155 ;
bool V_156 = F_65 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
if ( F_66 ( V_3 ) &&
V_144 -> V_8 == V_9 )
V_4 = V_153 -> V_4 ;
else
V_4 = V_43 -> V_67 . V_4 ;
if ( V_156 && V_144 -> V_157 == V_158 ) {
T_4 V_159 ;
if ( ( F_67 ( V_146 )
? V_146 -> V_160 . V_161 . V_162 : V_146 -> V_160 . V_161 . V_163 ) ==
V_164 &&
F_68 ( V_146 ,
F_66 ( V_3 ) ,
V_4 ) == V_165 ) {
V_40 = - V_41 ;
F_69 ( & V_3 -> V_52 , L_13 ) ;
goto V_98;
}
V_159 = F_70 ( V_146 -> V_160 . V_161 . V_163 ) ;
if ( V_159 != F_70 ( V_164 ) &&
V_159 & 0xffff0000 ) {
V_40 = - V_41 ;
F_69 ( & V_3 -> V_52 , L_14 ,
V_159 ) ;
goto V_98;
}
V_155 = ( T_6 ) ( V_159 & 0x0000ffff ) ;
if ( F_71 ( V_146 , V_3 ) == V_165 &&
F_72 ( V_146 , V_3 ) == V_165 )
goto V_98;
} else {
if ( ( F_73 ( V_144 ) ? V_144 -> V_162 : V_144 -> V_163 ) ==
V_166 &&
F_74 ( V_144 , F_66 ( V_3 ) , V_4 ) ==
V_165 ) {
V_40 = - V_41 ;
F_69 ( & V_3 -> V_52 , L_15 ) ;
goto V_98;
}
V_155 = F_75 ( V_144 -> V_163 ) ;
if ( F_76 ( V_144 , V_3 ) == V_165 &&
F_77 ( V_144 , V_3 ) == V_165 )
goto V_98;
}
V_148 = F_78 ( sizeof *V_148 , V_97 ) ;
if ( ! V_148 ) {
V_40 = - V_65 ;
goto V_98;
}
V_148 -> V_149 = NULL ;
V_148 -> V_150 = NULL ;
V_149 = F_60 ( V_139 , V_97 ) ;
if ( ! V_149 ) {
V_40 = - V_65 ;
F_31 ( V_148 ) ;
goto V_98;
}
F_58 ( V_43 -> V_67 . V_62 ,
V_153 -> V_167 . V_125 , V_155 ,
V_153 -> V_122 ,
V_153 -> V_4 , & V_151 ) ;
if ( V_156 && V_144 -> V_168 == V_169 ) {
V_151 . V_130 = V_142 -> V_113 . V_170
+ V_142 -> V_113 . V_171
+ sizeof( struct V_132 ) ;
}
V_40 = V_3 -> V_172 ( V_3 , 0 , V_4 , & V_151 , NULL ,
( const struct V_26 * ) V_144 , V_139 ,
(struct V_26 * ) V_149 -> V_145 ,
& V_139 , & V_154 ) ;
switch ( V_40 )
{
case V_173 | V_174 :
if ( F_13 ( ( const struct V_26 * ) V_149 -> V_145 ) &&
V_43 -> V_67 . V_36 ) {
V_148 -> V_149 = V_149 ;
V_148 -> V_150 = V_43 ;
F_36 ( & V_43 -> V_78 ) ;
} else
F_31 ( V_149 ) ;
break;
case V_173 | V_175 :
F_31 ( V_149 ) ;
break;
case V_173 :
V_39 = F_3 ( V_43 -> V_67 . V_3 ,
V_43 -> V_67 . V_4 ) ;
if ( V_39 ) {
memcpy ( V_149 -> V_145 , V_144 , V_149 -> V_139 ) ;
V_150 = F_79 ( V_39 ,
( const struct V_26 * ) V_149 -> V_145 ) ;
}
if ( ! V_39 || ! V_150 ) {
F_31 ( V_149 ) ;
break;
}
V_148 -> V_149 = V_149 ;
V_148 -> V_150 = V_150 ;
break;
default:
F_31 ( V_149 ) ;
F_31 ( V_148 ) ;
V_40 = - V_41 ;
goto V_98;
}
V_148 -> V_142 = V_142 ;
if ( V_156 ) {
V_148 -> V_142 -> V_153 . V_122 = V_154 ;
V_148 -> V_176 = V_139 ;
}
F_36 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_29 ( & V_148 -> V_177 , & V_43 -> V_75 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
F_80 ( V_43 -> V_61 -> V_39 -> V_104 ,
& V_43 -> V_76 ) ;
V_40 = 1 ;
V_98:
return V_40 ;
}
static int F_81 ( int V_170 , int V_171 , T_7 V_139 )
{
int V_178 , V_179 ;
V_178 = V_139 - V_170 ;
if ( V_171 && V_178 ) {
V_179 = V_178 - V_171 % V_178 ;
return V_179 == V_178 ? 0 : V_179 ;
} else
return V_178 ;
}
static void F_82 ( struct V_141 * V_142 )
{
struct V_180 * V_181 , * V_182 ;
F_83 (s, t, &mad_send_wr->rmpp_list, list) {
F_46 ( & V_181 -> V_110 ) ;
F_31 ( V_181 ) ;
}
}
static int F_84 ( struct V_141 * V_153 ,
T_7 V_139 , T_8 V_183 )
{
struct V_112 * V_113 = & V_153 -> V_113 ;
struct V_184 * V_185 = V_113 -> V_145 ;
struct V_180 * V_186 = NULL ;
int V_187 , V_178 , V_179 ;
V_113 -> V_178 = V_139 - V_113 -> V_170 ;
V_113 -> V_188 = V_139 - V_189 ;
V_178 = V_113 -> V_178 ;
V_179 = V_153 -> V_179 ;
for ( V_187 = V_113 -> V_171 + V_179 ; V_187 > 0 ; V_187 -= V_178 ) {
V_186 = F_78 ( sizeof ( * V_186 ) + V_178 , V_183 ) ;
if ( ! V_186 ) {
F_82 ( V_153 ) ;
return - V_65 ;
}
V_186 -> V_190 = ++ V_113 -> V_191 ;
F_29 ( & V_186 -> V_110 , & V_153 -> V_72 ) ;
}
if ( V_179 )
memset ( V_186 -> V_192 + V_178 - V_179 , 0 , V_179 ) ;
V_185 -> V_193 . V_34 = V_153 -> V_43 ->
V_67 . V_34 ;
V_185 -> V_193 . V_194 = V_195 ;
F_85 ( & V_185 -> V_193 , V_196 ) ;
V_153 -> V_197 = F_53 ( V_153 -> V_72 . V_198 ,
struct V_180 , V_110 ) ;
V_153 -> V_199 = V_153 -> V_197 ;
return 0 ;
}
int F_86 ( const struct V_33 * V_67 )
{
return V_67 -> V_34 && ! ( V_67 -> V_6 & V_59 ) ;
}
struct V_112 * F_87 ( struct V_33 * V_105 ,
T_4 V_200 , T_6 V_122 ,
int V_201 ,
int V_170 , int V_171 ,
T_8 V_183 ,
T_1 V_168 )
{
struct V_42 * V_43 ;
struct V_141 * V_142 ;
int V_179 , V_202 , V_40 , V_140 ;
void * V_203 ;
T_7 V_139 ;
bool V_156 ;
V_43 = F_53 ( V_105 , struct V_42 ,
V_67 ) ;
V_156 = F_65 ( V_105 -> V_3 , V_105 -> V_4 ) ;
if ( V_156 && V_168 == V_169 )
V_139 = sizeof( struct V_204 ) ;
else
V_139 = sizeof( struct V_131 ) ;
V_179 = F_81 ( V_170 , V_171 , V_139 ) ;
V_202 = V_170 + V_171 + V_179 ;
if ( F_86 ( V_105 ) ) {
if ( ! V_201 && V_202 > V_139 )
return F_15 ( - V_41 ) ;
} else
if ( V_201 || V_202 > V_139 )
return F_15 ( - V_41 ) ;
V_140 = V_201 ? V_170 : V_139 ;
V_203 = F_18 ( sizeof *V_142 + V_140 , V_183 ) ;
if ( ! V_203 )
return F_15 ( - V_65 ) ;
V_142 = V_203 + V_140 ;
F_21 ( & V_142 -> V_72 ) ;
V_142 -> V_113 . V_145 = V_203 ;
V_142 -> V_113 . V_170 = V_170 ;
V_142 -> V_113 . V_171 = V_171 ;
V_142 -> V_179 = V_179 ;
V_142 -> V_43 = V_43 ;
V_142 -> V_205 [ 0 ] . V_206 = V_170 ;
V_142 -> V_205 [ 0 ] . V_207 = V_105 -> V_62 -> V_208 -> V_209 ;
if ( V_156 && V_168 == V_169 &&
V_171 < V_139 - V_170 )
V_142 -> V_205 [ 1 ] . V_206 = V_171 ;
else
V_142 -> V_205 [ 1 ] . V_206 = V_139 - V_170 ;
V_142 -> V_205 [ 1 ] . V_207 = V_105 -> V_62 -> V_208 -> V_209 ;
V_142 -> V_107 . V_120 . V_210 = V_211 ;
V_142 -> V_153 . V_167 . V_125 = & V_142 -> V_107 . V_120 ;
V_142 -> V_153 . V_167 . V_205 = V_142 -> V_205 ;
V_142 -> V_153 . V_167 . V_212 = 2 ;
V_142 -> V_153 . V_167 . V_128 = V_213 ;
V_142 -> V_153 . V_167 . V_214 = V_215 ;
V_142 -> V_153 . V_200 = V_200 ;
V_142 -> V_153 . V_216 = V_217 ;
V_142 -> V_153 . V_122 = V_122 ;
if ( V_201 ) {
V_40 = F_84 ( V_142 , V_139 , V_183 ) ;
if ( V_40 ) {
F_31 ( V_203 ) ;
return F_15 ( V_40 ) ;
}
}
V_142 -> V_113 . V_105 = V_105 ;
F_36 ( & V_43 -> V_78 ) ;
return & V_142 -> V_113 ;
}
int F_88 ( T_1 V_8 )
{
if ( V_8 == V_218 )
return V_219 ;
else if ( ( V_8 == V_220 ) ||
( V_8 == V_221 ) ||
( V_8 == V_222 ) )
return V_223 ;
else if ( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) )
return V_224 ;
else
return V_225 ;
}
int F_17 ( T_1 V_8 )
{
if ( ( V_8 == V_218 ) ||
( V_8 == V_220 ) ||
( V_8 == V_221 ) ||
( V_8 == V_222 ) ||
( ( V_8 >= V_14 ) &&
( V_8 <= V_15 ) ) )
return 1 ;
return 0 ;
}
void * F_89 ( struct V_112 * V_113 , int V_226 )
{
struct V_141 * V_142 ;
struct V_227 * V_110 ;
V_142 = F_53 ( V_113 , struct V_141 ,
V_113 ) ;
V_110 = & V_142 -> V_197 -> V_110 ;
if ( V_142 -> V_197 -> V_190 < V_226 ) {
F_2 (mad_send_wr->cur_seg, list, list)
if ( V_142 -> V_197 -> V_190 == V_226 )
break;
} else if ( V_142 -> V_197 -> V_190 > V_226 ) {
F_90 (mad_send_wr->cur_seg, list, list)
if ( V_142 -> V_197 -> V_190 == V_226 )
break;
}
return V_142 -> V_197 -> V_192 ;
}
static inline void * F_91 ( struct V_141 * V_142 )
{
if ( V_142 -> V_113 . V_191 )
return F_89 ( & V_142 -> V_113 ,
V_142 -> V_226 ) ;
else
return V_142 -> V_113 . V_145 +
V_142 -> V_113 . V_170 ;
}
void F_92 ( struct V_112 * V_113 )
{
struct V_42 * V_43 ;
struct V_141 * V_142 ;
V_43 = F_53 ( V_113 -> V_105 ,
struct V_42 , V_67 ) ;
V_142 = F_53 ( V_113 , struct V_141 ,
V_113 ) ;
F_82 ( V_142 ) ;
F_31 ( V_113 -> V_145 ) ;
F_38 ( V_43 ) ;
}
int F_93 ( struct V_141 * V_142 )
{
struct V_90 * V_61 ;
struct V_227 * V_110 ;
struct V_228 * V_229 ;
struct V_33 * V_105 ;
struct V_230 * V_231 ;
unsigned long V_6 ;
int V_40 ;
V_61 = V_142 -> V_43 -> V_61 ;
V_142 -> V_107 . V_109 = & V_61 -> V_232 ;
V_142 -> V_107 . V_120 . V_210 = V_211 ;
V_142 -> V_153 . V_167 . V_125 = & V_142 -> V_107 . V_120 ;
V_105 = V_142 -> V_113 . V_105 ;
V_231 = V_142 -> V_205 ;
V_231 [ 0 ] . V_233 = F_94 ( V_105 -> V_3 ,
V_142 -> V_113 . V_145 ,
V_231 [ 0 ] . V_206 ,
V_234 ) ;
if ( F_95 ( F_96 ( V_105 -> V_3 , V_231 [ 0 ] . V_233 ) ) )
return - V_65 ;
V_142 -> V_235 = V_231 [ 0 ] . V_233 ;
V_231 [ 1 ] . V_233 = F_94 ( V_105 -> V_3 ,
F_91 ( V_142 ) ,
V_231 [ 1 ] . V_206 ,
V_234 ) ;
if ( F_95 ( F_96 ( V_105 -> V_3 , V_231 [ 1 ] . V_233 ) ) ) {
F_97 ( V_105 -> V_3 ,
V_142 -> V_235 ,
V_231 [ 0 ] . V_206 , V_234 ) ;
return - V_65 ;
}
V_142 -> V_236 = V_231 [ 1 ] . V_233 ;
F_4 ( & V_61 -> V_232 . V_68 , V_6 ) ;
if ( V_61 -> V_232 . V_111 < V_61 -> V_232 . V_237 ) {
V_40 = F_98 ( V_105 -> V_62 , & V_142 -> V_153 . V_167 ,
& V_229 ) ;
V_110 = & V_61 -> V_232 . V_110 ;
} else {
V_40 = 0 ;
V_110 = & V_61 -> V_238 ;
}
if ( ! V_40 ) {
V_61 -> V_232 . V_111 ++ ;
F_29 ( & V_142 -> V_107 . V_110 , V_110 ) ;
}
F_5 ( & V_61 -> V_232 . V_68 , V_6 ) ;
if ( V_40 ) {
F_97 ( V_105 -> V_3 ,
V_142 -> V_235 ,
V_231 [ 0 ] . V_206 , V_234 ) ;
F_97 ( V_105 -> V_3 ,
V_142 -> V_236 ,
V_231 [ 1 ] . V_206 , V_234 ) ;
}
return V_40 ;
}
int F_99 ( struct V_112 * V_113 ,
struct V_112 * * V_239 )
{
struct V_42 * V_43 ;
struct V_112 * V_240 ;
struct V_141 * V_142 ;
unsigned long V_6 ;
int V_40 = - V_41 ;
for (; V_113 ; V_113 = V_240 ) {
V_142 = F_53 ( V_113 ,
struct V_141 ,
V_113 ) ;
V_43 = V_142 -> V_43 ;
V_40 = F_100 ( V_43 ,
V_142 -> V_153 . V_122 ) ;
if ( V_40 )
goto error;
if ( ! V_113 -> V_105 -> V_35 ||
( V_113 -> V_241 &&
! V_113 -> V_105 -> V_36 ) ) {
V_40 = - V_41 ;
goto error;
}
if ( ! F_17 ( ( (struct V_26 * ) V_113 -> V_145 ) -> V_8 ) ) {
if ( V_43 -> V_67 . V_34 ) {
V_40 = - V_41 ;
goto error;
}
}
V_240 = V_113 -> V_198 ;
V_142 -> V_153 . V_242 = V_113 -> V_242 ;
if ( ( (struct V_26 * ) V_113 -> V_145 ) -> V_8 ==
V_9 ) {
V_40 = F_64 ( V_43 ,
V_142 ) ;
if ( V_40 < 0 )
goto error;
else if ( V_40 == 1 )
continue;
}
V_142 -> V_243 = ( (struct V_26 * ) V_113 -> V_145 ) -> V_243 ;
V_142 -> V_244 = F_101 ( V_113 -> V_241 ) ;
V_142 -> V_245 = V_113 -> V_246 ;
V_142 -> V_247 = V_113 -> V_246 ;
V_113 -> V_246 = 0 ;
V_142 -> V_78 = 1 + ( V_142 -> V_244 > 0 ) ;
V_142 -> V_126 = V_127 ;
F_36 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_29 ( & V_142 -> V_86 ,
& V_43 -> V_69 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( F_86 ( & V_43 -> V_67 ) ) {
V_40 = F_102 ( V_142 ) ;
if ( V_40 >= 0 && V_40 != V_248 )
V_40 = F_93 ( V_142 ) ;
} else
V_40 = F_93 ( V_142 ) ;
if ( V_40 < 0 ) {
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_46 ( & V_142 -> V_86 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
F_51 ( & V_43 -> V_78 ) ;
goto error;
}
}
return 0 ;
error:
if ( V_239 )
* V_239 = V_113 ;
return V_40 ;
}
void F_103 ( struct V_116 * V_117 )
{
struct V_249 * V_250 , * V_251 ;
struct V_252 * V_253 ;
struct V_137 * V_254 ;
struct V_227 V_255 ;
F_21 ( & V_255 ) ;
F_104 ( & V_117 -> V_72 , & V_255 ) ;
F_83 (mad_recv_buf, temp_recv_buf,
&free_list, list) {
V_117 = F_53 ( V_250 , struct V_116 ,
V_256 ) ;
V_253 = F_53 ( V_117 ,
struct V_252 ,
V_257 ) ;
V_254 = F_53 ( V_253 , struct V_137 ,
V_258 ) ;
F_31 ( V_254 ) ;
}
}
struct V_33 * F_105 ( struct V_118 * V_62 ,
T_1 V_34 ,
T_2 V_35 ,
T_3 V_36 ,
void * V_37 )
{
return F_15 ( - V_41 ) ;
}
int F_106 ( struct V_33 * V_105 ,
struct V_123 * V_124 )
{
F_69 ( & V_105 -> V_3 -> V_52 ,
L_16 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * * V_22 ,
struct V_19 * V_20 )
{
int V_23 ;
F_107 (i, mad_reg_req->method_mask, IB_MGMT_MAX_METHODS) {
if ( ( * V_22 ) -> V_67 [ V_23 ] ) {
F_108 ( L_17 , V_23 ) ;
return - V_41 ;
}
}
return 0 ;
}
static int F_109 ( struct V_21 * * V_22 )
{
* V_22 = F_18 ( sizeof ** V_22 , V_97 ) ;
return ( * V_22 ) ? 0 : ( - V_65 ) ;
}
static int F_110 ( struct V_21 * V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_259 ; V_23 ++ )
if ( V_22 -> V_67 [ V_23 ] )
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
for ( V_23 = 0 ; V_23 < V_260 ; V_23 ++ )
if ( V_48 -> V_18 [ V_23 ] )
return 1 ;
return 0 ;
}
static void F_115 ( struct V_21 * V_22 ,
struct V_42 * V_67 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_259 ; V_23 ++ ) {
if ( V_22 -> V_67 [ V_23 ] == V_67 ) {
V_22 -> V_67 [ V_23 ] = NULL ;
}
}
}
static int F_27 ( struct V_19 * V_20 ,
struct V_42 * V_261 ,
T_1 V_8 )
{
struct V_1 * V_39 ;
struct V_45 * * V_46 ;
struct V_21 * * V_22 ;
int V_23 , V_40 ;
V_39 = V_261 -> V_61 -> V_39 ;
V_46 = & V_39 -> V_84 [ V_20 -> V_55 ] . V_46 ;
if ( ! * V_46 ) {
* V_46 = F_18 ( sizeof ** V_46 , V_97 ) ;
if ( ! * V_46 ) {
V_40 = - V_65 ;
goto V_53;
}
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ( V_40 = F_109 ( V_22 ) ) )
goto V_102;
} else {
V_22 = & ( * V_46 ) -> V_25 [ V_8 ] ;
if ( ! * V_22 ) {
if ( ( V_40 = F_109 ( V_22 ) ) )
goto V_53;
}
}
if ( F_12 ( V_22 , V_20 ) )
goto V_66;
F_107 ( V_23 , V_20 -> V_262 , V_259 )
( * V_22 ) -> V_67 [ V_23 ] = V_261 ;
return 0 ;
V_66:
F_115 ( * V_22 , V_261 ) ;
if ( ! F_110 ( * V_22 ) ) {
F_31 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
goto V_53;
V_102:
F_31 ( * V_46 ) ;
* V_46 = NULL ;
V_53:
return V_40 ;
}
static int F_28 ( struct V_19 * V_20 ,
struct V_42 * V_261 )
{
struct V_1 * V_39 ;
struct V_47 * * V_263 ;
struct V_47 * V_48 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_21 * * V_22 ;
int V_23 , V_40 = - V_65 ;
T_1 V_51 ;
V_51 = F_8 ( V_20 -> V_8 ) ;
V_39 = V_261 -> V_61 -> V_39 ;
V_263 = & V_39 -> V_84 [
V_20 -> V_55 ] . V_48 ;
if ( ! * V_263 ) {
V_48 = F_18 ( sizeof *V_48 , V_97 ) ;
if ( ! V_48 )
goto V_53;
* V_263 = V_48 ;
}
if ( ! ( * V_263 ) -> V_18 [ V_51 ] ) {
V_18 = F_18 ( sizeof *V_18 , V_97 ) ;
if ( ! V_18 )
goto V_102;
( * V_263 ) -> V_18 [ V_51 ] = V_18 ;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! memcmp ( ( * V_263 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ) {
V_22 = & ( * V_263 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_55 ( ! * V_22 ) ;
goto V_264;
}
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
if ( ! F_10 ( ( * V_263 ) -> V_18 [
V_51 ] -> V_16 [ V_23 ] ) ) {
V_22 = & ( * V_263 ) -> V_18 [
V_51 ] -> V_25 [ V_23 ] ;
F_55 ( * V_22 ) ;
if ( ( V_40 = F_109 ( V_22 ) ) )
goto V_66;
memcpy ( ( * V_263 ) -> V_18 [ V_51 ] -> V_16 [ V_23 ] ,
V_20 -> V_16 , 3 ) ;
goto V_264;
}
}
F_69 ( & V_261 -> V_67 . V_3 -> V_52 , L_18 ) ;
goto V_66;
V_264:
if ( F_12 ( V_22 , V_20 ) )
goto V_80;
F_107 ( V_23 , V_20 -> V_262 , V_259 )
( * V_22 ) -> V_67 [ V_23 ] = V_261 ;
return 0 ;
V_80:
F_115 ( * V_22 , V_261 ) ;
if ( ! F_110 ( * V_22 ) ) {
F_31 ( * V_22 ) ;
* V_22 = NULL ;
}
V_40 = - V_41 ;
V_66:
if ( V_18 ) {
( * V_263 ) -> V_18 [ V_51 ] = NULL ;
F_31 ( V_18 ) ;
}
V_102:
if ( V_48 ) {
* V_263 = NULL ;
F_31 ( V_48 ) ;
}
V_53:
return V_40 ;
}
static void F_45 ( struct V_42 * V_261 )
{
struct V_1 * V_39 ;
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
int V_265 ;
T_1 V_8 ;
if ( ! V_261 -> V_44 ) {
goto V_98;
}
V_39 = V_261 -> V_61 -> V_39 ;
V_8 = F_6 ( V_261 -> V_44 -> V_8 ) ;
V_46 = V_39 -> V_84 [
V_261 -> V_44 -> V_55 ] . V_46 ;
if ( ! V_46 )
goto V_266;
V_22 = V_46 -> V_25 [ V_8 ] ;
if ( V_22 ) {
F_115 ( V_22 , V_261 ) ;
if ( ! F_110 ( V_22 ) ) {
F_31 ( V_22 ) ;
V_46 -> V_25 [ V_8 ] = NULL ;
if ( ! F_111 ( V_46 ) ) {
F_31 ( V_46 ) ;
V_39 -> V_84 [
V_261 -> V_44 ->
V_55 ] . V_46 = NULL ;
}
}
}
V_266:
if ( ! F_9 ( V_8 ) )
goto V_98;
V_8 = F_8 ( V_261 -> V_44 -> V_8 ) ;
V_48 = V_39 -> V_84 [
V_261 -> V_44 -> V_55 ] . V_48 ;
if ( ! V_48 )
goto V_98;
V_18 = V_48 -> V_18 [ V_8 ] ;
if ( V_18 ) {
V_265 = F_113 ( V_18 , V_261 -> V_44 -> V_16 ) ;
if ( V_265 < 0 )
goto V_98;
V_22 = V_18 -> V_25 [ V_265 ] ;
if ( V_22 ) {
F_115 ( V_22 , V_261 ) ;
if ( ! F_110 ( V_22 ) ) {
F_31 ( V_22 ) ;
V_18 -> V_25 [ V_265 ] = NULL ;
memset ( V_18 -> V_16 [ V_265 ] , 0 , 3 ) ;
if ( ! F_112 ( V_18 ) ) {
F_31 ( V_18 ) ;
V_48 -> V_18 [ V_8 ] = NULL ;
if ( ! F_114 ( V_48 ) ) {
F_31 ( V_48 ) ;
V_39 -> V_84 [
V_261 -> V_44 ->
V_55 ] .
V_48 = NULL ;
}
}
}
}
}
V_98:
return;
}
static struct V_42 *
F_79 ( struct V_1 * V_39 ,
const struct V_26 * V_267 )
{
struct V_42 * V_105 = NULL ;
unsigned long V_6 ;
F_4 ( & V_39 -> V_81 , V_6 ) ;
if ( F_13 ( V_267 ) ) {
T_4 V_82 ;
struct V_42 * V_5 ;
V_82 = F_116 ( V_267 -> V_243 ) >> 32 ;
F_2 (entry, &port_priv->agent_list, agent_list) {
if ( V_5 -> V_67 . V_82 == V_82 ) {
V_105 = V_5 ;
break;
}
}
} else {
struct V_45 * V_46 ;
struct V_21 * V_22 ;
struct V_47 * V_48 ;
struct V_17 * V_18 ;
const struct V_268 * V_269 ;
int V_265 ;
if ( V_267 -> V_157 >= V_56 )
goto V_98;
if ( ! F_9 ( V_267 -> V_8 ) ) {
V_46 = V_39 -> V_84 [
V_267 -> V_157 ] . V_46 ;
if ( ! V_46 )
goto V_98;
if ( F_6 ( V_267 -> V_8 ) >=
F_117 ( V_46 -> V_25 ) )
goto V_98;
V_22 = V_46 -> V_25 [ F_6 (
V_267 -> V_8 ) ] ;
if ( V_22 )
V_105 = V_22 -> V_67 [ V_267 -> V_22 &
~ V_28 ] ;
} else {
V_48 = V_39 -> V_84 [
V_267 -> V_157 ] . V_48 ;
if ( ! V_48 )
goto V_98;
V_18 = V_48 -> V_18 [ F_8 (
V_267 -> V_8 ) ] ;
if ( ! V_18 )
goto V_98;
V_269 = ( const struct V_268 * ) V_267 ;
V_265 = F_113 ( V_18 , V_269 -> V_16 ) ;
if ( V_265 == - 1 )
goto V_98;
V_22 = V_18 -> V_25 [ V_265 ] ;
if ( V_22 ) {
V_105 = V_22 -> V_67 [ V_267 -> V_22 &
~ V_28 ] ;
}
}
}
if ( V_105 ) {
if ( V_105 -> V_67 . V_36 )
F_36 ( & V_105 -> V_78 ) ;
else {
F_16 ( & V_39 -> V_3 -> V_52 ,
L_19 ,
& V_105 -> V_67 , V_39 -> V_4 ) ;
V_105 = NULL ;
}
}
V_98:
F_5 ( & V_39 -> V_81 , V_6 ) ;
return V_105 ;
}
static int F_118 ( const struct V_26 * V_267 ,
const struct V_90 * V_61 ,
bool V_156 )
{
int V_270 = 0 ;
T_4 V_271 = V_61 -> V_62 -> V_271 ;
if ( V_267 -> V_168 != V_272 &&
( ! V_156 || V_267 -> V_168 != V_169 ) ) {
F_108 ( L_20 ,
V_267 -> V_168 , V_156 ? L_21 : L_22 ) ;
goto V_98;
}
if ( ( V_267 -> V_8 == V_58 ) ||
( V_267 -> V_8 == V_9 ) ) {
if ( V_271 == 0 )
V_270 = 1 ;
} else {
if ( ( V_267 -> V_8 == V_273 ) &&
( V_267 -> V_274 != V_275 ) &&
( V_267 -> V_22 != V_276 ) )
goto V_98;
if ( V_271 != 0 )
V_270 = 1 ;
}
V_98:
return V_270 ;
}
static int F_119 ( const struct V_42 * V_43 ,
const struct V_26 * V_267 )
{
struct V_184 * V_185 ;
V_185 = (struct V_184 * ) V_267 ;
return ! V_43 -> V_67 . V_34 ||
! F_86 ( & V_43 -> V_67 ) ||
! ( F_120 ( & V_185 -> V_193 ) &
V_196 ) ||
( V_185 -> V_193 . V_194 == V_195 ) ;
}
static inline int F_121 ( const struct V_141 * V_167 ,
const struct V_116 * V_277 )
{
return ( (struct V_26 * ) ( V_167 -> V_113 . V_145 ) ) -> V_8 ==
V_277 -> V_256 . V_145 -> V_267 . V_8 ;
}
static inline int F_122 ( const struct V_42 * V_43 ,
const struct V_141 * V_167 ,
const struct V_116 * V_277 )
{
struct V_278 V_279 ;
T_1 V_280 , V_281 ;
union V_282 V_283 ;
struct V_2 * V_3 = V_43 -> V_67 . V_3 ;
T_1 V_4 = V_43 -> V_67 . V_4 ;
T_1 V_284 ;
bool V_285 ;
V_280 = F_13 ( (struct V_26 * ) V_167 -> V_113 . V_145 ) ;
V_281 = F_13 ( & V_277 -> V_256 . V_145 -> V_267 ) ;
if ( V_280 == V_281 )
return 0 ;
if ( F_123 ( V_167 -> V_113 . V_242 , & V_279 ) )
return 0 ;
V_285 = ! ! ( F_124 ( & V_279 ) & V_286 ) ;
if ( V_285 != ! ! ( V_277 -> V_124 -> V_287 & V_288 ) )
return 0 ;
if ( ! V_280 && V_281 ) {
if ( ! V_285 ) {
if ( F_125 ( V_3 , V_4 , & V_284 ) )
return 0 ;
return ( ! V_284 || ! ( ( F_126 ( & V_279 ) ^
V_277 -> V_124 -> V_136 ) &
( ( 1 << V_284 ) - 1 ) ) ) ;
} else {
const struct V_289 * V_290 =
F_127 ( & V_279 ) ;
if ( F_128 ( V_3 , V_4 ,
V_290 -> V_291 , & V_283 , NULL ) )
return 0 ;
return ! memcmp ( V_283 . V_292 , V_277 -> V_256 . V_290 -> V_293 . V_292 ,
16 ) ;
}
}
if ( ! V_285 )
return F_129 ( & V_279 ) == V_277 -> V_124 -> V_121 ;
else
return ! memcmp ( F_127 ( & V_279 ) -> V_293 . V_292 ,
V_277 -> V_256 . V_290 -> V_283 . V_292 ,
16 ) ;
}
static inline int F_130 ( T_1 V_46 )
{
return ( V_46 == V_9 ) ;
}
struct V_141 *
F_131 ( const struct V_42 * V_43 ,
const struct V_116 * V_124 )
{
struct V_141 * V_167 ;
const struct V_26 * V_267 ;
V_267 = & V_124 -> V_256 . V_145 -> V_267 ;
F_2 (wr, &mad_agent_priv->wait_list, agent_list) {
if ( ( V_167 -> V_243 == V_267 -> V_243 ) &&
F_121 ( V_167 , V_124 ) &&
( F_130 ( V_267 -> V_8 ) ||
F_122 ( V_43 , V_167 , V_124 ) ) )
return ( V_167 -> V_126 == V_127 ) ? V_167 : NULL ;
}
F_2 (wr, &mad_agent_priv->send_list, agent_list) {
if ( F_119 ( V_43 , V_167 -> V_113 . V_145 ) &&
V_167 -> V_243 == V_267 -> V_243 &&
V_167 -> V_244 &&
F_121 ( V_167 , V_124 ) &&
( F_130 ( V_267 -> V_8 ) ||
F_122 ( V_43 , V_167 , V_124 ) ) )
return ( V_167 -> V_126 == V_127 ) ? V_167 : NULL ;
}
return NULL ;
}
void F_132 ( struct V_141 * V_142 )
{
V_142 -> V_244 = 0 ;
if ( V_142 -> V_78 == 1 )
F_133 ( & V_142 -> V_86 ,
& V_142 -> V_43 -> V_71 ) ;
}
static void F_134 ( struct V_42 * V_43 ,
struct V_116 * V_117 )
{
struct V_141 * V_142 ;
struct V_114 V_115 ;
unsigned long V_6 ;
int V_40 ;
V_40 = F_100 ( V_43 ,
V_117 -> V_124 -> V_122 ) ;
if ( V_40 ) {
F_103 ( V_117 ) ;
F_38 ( V_43 ) ;
}
F_21 ( & V_117 -> V_72 ) ;
F_135 ( & V_117 -> V_256 . V_110 , & V_117 -> V_72 ) ;
if ( F_86 ( & V_43 -> V_67 ) ) {
V_117 = F_136 ( V_43 ,
V_117 ) ;
if ( ! V_117 ) {
F_38 ( V_43 ) ;
return;
}
}
if ( F_13 ( & V_117 -> V_256 . V_145 -> V_267 ) ) {
F_4 ( & V_43 -> V_68 , V_6 ) ;
V_142 = F_131 ( V_43 , V_117 ) ;
if ( ! V_142 ) {
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( ! F_86 ( & V_43 -> V_67 )
&& F_17 ( V_117 -> V_256 . V_145 -> V_267 . V_8 )
&& ( F_120 ( & ( (struct V_184 * ) V_117 -> V_256 . V_145 ) -> V_193 )
& V_196 ) ) {
V_43 -> V_67 . V_36 (
& V_43 -> V_67 , NULL ,
V_117 ) ;
F_51 ( & V_43 -> V_78 ) ;
} else {
F_103 ( V_117 ) ;
F_38 ( V_43 ) ;
return;
}
} else {
F_132 ( V_142 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_43 -> V_67 . V_36 (
& V_43 -> V_67 ,
& V_142 -> V_113 ,
V_117 ) ;
F_51 ( & V_43 -> V_78 ) ;
V_115 . V_126 = V_127 ;
V_115 . V_294 = 0 ;
V_115 . V_113 = & V_142 -> V_113 ;
F_137 ( V_142 , & V_115 ) ;
}
} else {
V_43 -> V_67 . V_36 ( & V_43 -> V_67 , NULL ,
V_117 ) ;
F_38 ( V_43 ) ;
}
return;
}
static enum V_295 F_138 ( const struct V_1 * V_39 ,
const struct V_90 * V_61 ,
const struct V_123 * V_124 ,
int V_4 ,
struct V_137 * V_296 ,
struct V_137 * V_297 )
{
enum V_298 V_299 ;
struct V_143 * V_144 = (struct V_143 * ) V_296 -> V_145 ;
if ( F_139 ( V_144 ,
F_66 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_300 ) ==
V_165 )
return V_165 ;
V_299 = F_140 ( V_144 ) ;
if ( V_299 == V_301 )
return V_302 ;
if ( V_299 == V_303 ) {
if ( F_74 ( V_144 ,
F_66 ( V_39 -> V_3 ) ,
V_4 ) == V_165 )
return V_165 ;
if ( F_76 ( V_144 , V_39 -> V_3 ) == V_165 )
return V_165 ;
} else if ( F_66 ( V_39 -> V_3 ) ) {
memcpy ( V_297 , V_296 , F_59 ( V_297 ) ) ;
V_297 -> V_258 . V_257 . V_124 = & V_297 -> V_258 . V_124 ;
V_297 -> V_258 . V_257 . V_256 . V_145 = (struct V_131 * ) V_297 -> V_145 ;
V_297 -> V_258 . V_257 . V_256 . V_290 = & V_297 -> V_290 ;
F_141 ( ( const struct V_26 * ) V_297 -> V_145 ,
& V_297 -> V_290 , V_124 ,
V_39 -> V_3 ,
F_142 ( V_144 ) ,
V_61 -> V_62 -> V_271 ,
V_297 -> V_139 ,
false ) ;
return V_165 ;
}
return V_302 ;
}
static bool F_143 ( const struct V_137 * V_296 ,
struct V_137 * V_297 ,
T_7 * V_304 , bool V_156 )
{
const struct V_26 * V_305 = ( const struct V_26 * ) V_296 -> V_145 ;
struct V_26 * V_306 = (struct V_26 * ) V_297 -> V_145 ;
if ( V_305 -> V_22 == V_307 ||
V_305 -> V_22 == V_308 ) {
memcpy ( V_297 , V_296 , F_59 ( V_297 ) ) ;
V_297 -> V_258 . V_257 . V_124 = & V_297 -> V_258 . V_124 ;
V_297 -> V_258 . V_257 . V_256 . V_145 = (struct V_131 * ) V_297 -> V_145 ;
V_297 -> V_258 . V_257 . V_256 . V_290 = & V_297 -> V_290 ;
V_306 -> V_22 = V_309 ;
V_306 -> V_126 = F_144 ( V_310 ) ;
if ( V_305 -> V_8 == V_9 )
V_306 -> V_126 |= V_311 ;
if ( V_156 && V_305 -> V_168 == V_169 ) {
if ( V_305 -> V_8 ==
V_58 ||
V_305 -> V_8 ==
V_9 )
* V_304 = F_145 (
(struct V_146 * ) V_296 -> V_145 ) ;
else
* V_304 = sizeof( struct V_26 ) ;
}
return true ;
} else {
return false ;
}
}
static enum V_295
F_146 ( struct V_1 * V_39 ,
struct V_90 * V_61 ,
struct V_123 * V_124 ,
int V_4 ,
struct V_137 * V_296 ,
struct V_137 * V_297 )
{
enum V_298 V_299 ;
struct V_146 * V_144 = (struct V_146 * ) V_296 -> V_145 ;
if ( F_147 ( V_144 ,
F_66 ( V_39 -> V_3 ) ,
V_4 ,
V_39 -> V_3 -> V_300 ) ==
V_165 )
return V_165 ;
V_299 = F_148 ( V_144 ) ;
if ( V_299 == V_301 )
return V_302 ;
if ( V_299 == V_303 ) {
if ( F_68 ( V_144 ,
F_66 ( V_39 -> V_3 ) ,
V_4 ) == V_165 )
return V_165 ;
if ( F_71 ( V_144 , V_39 -> V_3 ) ==
V_165 )
return V_165 ;
} else if ( F_66 ( V_39 -> V_3 ) ) {
memcpy ( V_297 , V_296 , F_59 ( V_297 ) ) ;
V_297 -> V_258 . V_257 . V_124 = & V_297 -> V_258 . V_124 ;
V_297 -> V_258 . V_257 . V_256 . V_204 =
(struct V_204 * ) V_297 -> V_145 ;
V_297 -> V_258 . V_257 . V_256 . V_290 = & V_297 -> V_290 ;
F_141 ( ( const struct V_26 * ) V_297 -> V_145 ,
& V_297 -> V_290 , V_124 ,
V_39 -> V_3 ,
F_149 ( V_144 ) ,
V_61 -> V_62 -> V_271 ,
V_296 -> V_258 . V_124 . V_130 ,
true ) ;
return V_165 ;
}
return V_302 ;
}
static enum V_295
F_150 ( struct V_1 * V_39 ,
struct V_90 * V_61 ,
struct V_123 * V_124 ,
int V_4 ,
struct V_137 * V_296 ,
struct V_137 * V_297 ,
bool V_156 )
{
struct V_26 * V_267 = (struct V_26 * ) V_296 -> V_145 ;
if ( V_156 && V_267 -> V_168 == V_169 &&
V_267 -> V_157 == V_158 )
return F_146 ( V_39 , V_61 , V_124 , V_4 , V_296 ,
V_297 ) ;
return F_138 ( V_39 , V_61 , V_124 , V_4 , V_296 , V_297 ) ;
}
static void F_151 ( struct V_312 * V_313 , struct V_123 * V_124 )
{
struct V_1 * V_39 = V_313 -> V_314 ;
struct V_106 * V_107 =
F_53 ( V_124 -> V_125 , struct V_106 , V_120 ) ;
struct V_90 * V_61 ;
struct V_252 * V_253 ;
struct V_137 * V_296 , * V_297 = NULL ;
struct V_42 * V_105 ;
int V_4 ;
int V_40 = V_173 ;
T_7 V_139 ;
T_6 V_315 = 0 ;
bool V_156 ;
if ( F_152 ( & V_39 -> V_316 ) )
return;
if ( V_124 -> V_126 != V_127 ) {
return;
}
V_61 = V_107 -> V_109 -> V_61 ;
F_54 ( V_107 ) ;
V_156 = F_65 ( V_61 -> V_39 -> V_3 ,
V_61 -> V_39 -> V_4 ) ;
V_253 = F_53 ( V_107 , struct V_252 ,
V_107 ) ;
V_296 = F_53 ( V_253 , struct V_137 , V_258 ) ;
F_97 ( V_39 -> V_3 ,
V_296 -> V_258 . V_317 ,
F_63 ( V_296 ) ,
V_318 ) ;
V_296 -> V_258 . V_124 = * V_124 ;
V_296 -> V_258 . V_257 . V_124 = & V_296 -> V_258 . V_124 ;
if ( V_156 && ( (struct V_26 * ) ( V_296 -> V_145 ) ) -> V_168 == V_169 ) {
V_296 -> V_258 . V_257 . V_319 = V_124 -> V_130 - sizeof( struct V_132 ) ;
V_296 -> V_258 . V_257 . V_320 = sizeof( struct V_204 ) ;
} else {
V_296 -> V_258 . V_257 . V_319 = sizeof( struct V_131 ) ;
V_296 -> V_258 . V_257 . V_320 = sizeof( struct V_131 ) ;
}
V_296 -> V_258 . V_257 . V_256 . V_145 = (struct V_131 * ) V_296 -> V_145 ;
V_296 -> V_258 . V_257 . V_256 . V_290 = & V_296 -> V_290 ;
if ( F_153 ( & V_61 -> V_99 ) )
F_57 ( V_61 , & V_296 -> V_258 . V_257 , V_89 ) ;
if ( ! F_118 ( ( const struct V_26 * ) V_296 -> V_145 , V_61 , V_156 ) )
goto V_98;
V_139 = V_296 -> V_139 ;
V_297 = F_60 ( V_139 , V_64 ) ;
if ( ! V_297 )
goto V_98;
if ( F_66 ( V_39 -> V_3 ) )
V_4 = V_124 -> V_4 ;
else
V_4 = V_39 -> V_4 ;
if ( ( (struct V_26 * ) V_296 -> V_145 ) -> V_8 ==
V_9 ) {
if ( F_150 ( V_39 , V_61 , V_124 , V_4 , V_296 ,
V_297 , V_156 )
== V_165 )
goto V_98;
}
if ( V_39 -> V_3 -> V_172 ) {
V_40 = V_39 -> V_3 -> V_172 ( V_39 -> V_3 , 0 ,
V_39 -> V_4 ,
V_124 , & V_296 -> V_290 ,
( const struct V_26 * ) V_296 -> V_145 ,
V_296 -> V_139 ,
(struct V_26 * ) V_297 -> V_145 ,
& V_139 , & V_315 ) ;
if ( V_156 )
V_124 -> V_122 = V_315 ;
if ( V_40 & V_173 ) {
if ( V_40 & V_175 )
goto V_98;
if ( V_40 & V_174 ) {
F_141 ( ( const struct V_26 * ) V_297 -> V_145 ,
& V_296 -> V_290 , V_124 ,
V_39 -> V_3 ,
V_4 ,
V_61 -> V_62 -> V_271 ,
V_139 , V_156 ) ;
goto V_98;
}
}
}
V_105 = F_79 ( V_39 , ( const struct V_26 * ) V_296 -> V_145 ) ;
if ( V_105 ) {
F_134 ( V_105 , & V_296 -> V_258 . V_257 ) ;
V_296 = NULL ;
} else if ( ( V_40 & V_173 ) &&
F_143 ( V_296 , V_297 , & V_139 , V_156 ) ) {
F_141 ( ( const struct V_26 * ) V_297 -> V_145 , & V_296 -> V_290 , V_124 ,
V_39 -> V_3 , V_4 ,
V_61 -> V_62 -> V_271 , V_139 , V_156 ) ;
}
V_98:
if ( V_297 ) {
F_154 ( V_61 , V_297 ) ;
F_31 ( V_296 ) ;
} else
F_154 ( V_61 , V_296 ) ;
}
static void F_155 ( struct V_42 * V_43 )
{
struct V_141 * V_142 ;
unsigned long V_321 ;
if ( F_156 ( & V_43 -> V_70 ) ) {
F_44 ( & V_43 -> V_73 ) ;
} else {
V_142 = F_157 ( V_43 -> V_70 . V_198 ,
struct V_141 ,
V_86 ) ;
if ( F_158 ( V_43 -> V_244 ,
V_142 -> V_244 ) ) {
V_43 -> V_244 = V_142 -> V_244 ;
V_321 = V_142 -> V_244 - V_322 ;
if ( ( long ) V_321 <= 0 )
V_321 = 1 ;
F_159 ( V_43 -> V_61 -> V_39 -> V_104 ,
& V_43 -> V_73 , V_321 ) ;
}
}
}
static void F_160 ( struct V_141 * V_142 )
{
struct V_42 * V_43 ;
struct V_141 * V_323 ;
struct V_227 * V_324 ;
unsigned long V_321 ;
V_43 = V_142 -> V_43 ;
F_46 ( & V_142 -> V_86 ) ;
V_321 = V_142 -> V_244 ;
V_142 -> V_244 += V_322 ;
if ( V_321 ) {
F_161 (list_item, &mad_agent_priv->wait_list) {
V_323 = F_157 ( V_324 ,
struct V_141 ,
V_86 ) ;
if ( F_158 ( V_142 -> V_244 ,
V_323 -> V_244 ) )
break;
}
}
else
V_324 = & V_43 -> V_70 ;
F_135 ( & V_142 -> V_86 , V_324 ) ;
if ( V_43 -> V_70 . V_198 == & V_142 -> V_86 )
F_159 ( V_43 -> V_61 -> V_39 -> V_104 ,
& V_43 -> V_73 , V_321 ) ;
}
void F_162 ( struct V_141 * V_142 ,
int V_241 )
{
V_142 -> V_244 = F_101 ( V_241 ) ;
F_160 ( V_142 ) ;
}
void F_137 ( struct V_141 * V_142 ,
struct V_114 * V_115 )
{
struct V_42 * V_43 ;
unsigned long V_6 ;
int V_40 ;
V_43 = V_142 -> V_43 ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
if ( F_86 ( & V_43 -> V_67 ) ) {
V_40 = F_163 ( V_142 , V_115 ) ;
if ( V_40 == V_248 )
goto V_210;
} else
V_40 = V_325 ;
if ( V_115 -> V_126 != V_127 &&
V_142 -> V_126 == V_127 ) {
V_142 -> V_126 = V_115 -> V_126 ;
V_142 -> V_78 -= ( V_142 -> V_244 > 0 ) ;
}
if ( -- V_142 -> V_78 > 0 ) {
if ( V_142 -> V_78 == 1 && V_142 -> V_244 &&
V_142 -> V_126 == V_127 ) {
F_160 ( V_142 ) ;
}
goto V_210;
}
F_46 ( & V_142 -> V_86 ) ;
F_155 ( V_43 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_142 -> V_126 != V_127 )
V_115 -> V_126 = V_142 -> V_126 ;
if ( V_40 == V_326 )
F_164 ( V_115 ) ;
else
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
V_115 ) ;
F_38 ( V_43 ) ;
return;
V_210:
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static void V_211 ( struct V_312 * V_313 , struct V_123 * V_124 )
{
struct V_1 * V_39 = V_313 -> V_314 ;
struct V_106 * V_107 =
F_53 ( V_124 -> V_125 , struct V_106 , V_120 ) ;
struct V_141 * V_142 , * V_327 ;
struct V_90 * V_61 ;
struct V_108 * V_232 ;
struct V_228 * V_229 ;
struct V_114 V_115 ;
unsigned long V_6 ;
int V_40 ;
if ( F_152 ( & V_39 -> V_316 ) )
return;
if ( V_124 -> V_126 != V_127 ) {
if ( ! F_165 ( V_39 , V_124 ) )
return;
}
V_142 = F_53 ( V_107 , struct V_141 ,
V_107 ) ;
V_232 = V_107 -> V_109 ;
V_61 = V_232 -> V_61 ;
V_328:
F_97 ( V_142 -> V_113 . V_105 -> V_3 ,
V_142 -> V_235 ,
V_142 -> V_205 [ 0 ] . V_206 , V_234 ) ;
F_97 ( V_142 -> V_113 . V_105 -> V_3 ,
V_142 -> V_236 ,
V_142 -> V_205 [ 1 ] . V_206 , V_234 ) ;
V_327 = NULL ;
F_4 ( & V_232 -> V_68 , V_6 ) ;
F_46 ( & V_107 -> V_110 ) ;
if ( V_232 -> V_111 -- > V_232 -> V_237 ) {
V_107 = F_53 ( V_61 -> V_238 . V_198 ,
struct V_106 , V_110 ) ;
V_327 = F_53 ( V_107 ,
struct V_141 ,
V_107 ) ;
F_133 ( & V_107 -> V_110 , & V_232 -> V_110 ) ;
}
F_5 ( & V_232 -> V_68 , V_6 ) ;
V_115 . V_113 = & V_142 -> V_113 ;
V_115 . V_126 = V_124 -> V_126 ;
V_115 . V_294 = V_124 -> V_294 ;
if ( F_153 ( & V_61 -> V_99 ) )
F_56 ( V_61 , & V_142 -> V_113 , & V_115 ,
V_88 ) ;
F_137 ( V_142 , & V_115 ) ;
if ( V_327 ) {
V_40 = F_98 ( V_61 -> V_62 , & V_327 -> V_153 . V_167 ,
& V_229 ) ;
if ( V_40 ) {
F_69 ( & V_39 -> V_3 -> V_52 ,
L_23 , V_40 ) ;
V_142 = V_327 ;
V_124 -> V_126 = V_329 ;
goto V_328;
}
}
}
static void F_166 ( struct V_90 * V_61 )
{
struct V_141 * V_142 ;
struct V_106 * V_107 ;
unsigned long V_6 ;
F_4 ( & V_61 -> V_232 . V_68 , V_6 ) ;
F_2 (mad_list, &qp_info->send_queue.list, list) {
V_142 = F_53 ( V_107 ,
struct V_141 ,
V_107 ) ;
V_142 -> V_328 = 1 ;
}
F_5 ( & V_61 -> V_232 . V_68 , V_6 ) ;
}
static bool F_165 ( struct V_1 * V_39 ,
struct V_123 * V_124 )
{
struct V_106 * V_107 =
F_53 ( V_124 -> V_125 , struct V_106 , V_120 ) ;
struct V_90 * V_61 = V_107 -> V_109 -> V_61 ;
struct V_141 * V_142 ;
int V_40 ;
V_142 = F_53 ( V_107 , struct V_141 ,
V_107 ) ;
if ( V_124 -> V_126 == V_330 ) {
if ( V_142 -> V_328 ) {
struct V_228 * V_229 ;
V_142 -> V_328 = 0 ;
V_40 = F_98 ( V_61 -> V_62 , & V_142 -> V_153 . V_167 ,
& V_229 ) ;
if ( ! V_40 )
return false ;
}
} else {
struct V_331 * V_279 ;
V_279 = F_78 ( sizeof *V_279 , V_64 ) ;
if ( V_279 ) {
V_279 -> V_332 = V_333 ;
V_279 -> V_334 = V_335 ;
V_40 = F_167 ( V_61 -> V_62 , V_279 ,
V_336 | V_337 ) ;
F_31 ( V_279 ) ;
if ( V_40 )
F_69 ( & V_39 -> V_3 -> V_52 ,
L_24 ,
V_338 , V_40 ) ;
else
F_166 ( V_61 ) ;
}
}
return true ;
}
static void F_43 ( struct V_42 * V_43 )
{
unsigned long V_6 ;
struct V_141 * V_142 , * V_323 ;
struct V_114 V_115 ;
struct V_227 V_339 ;
F_21 ( & V_339 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_83 (mad_send_wr, temp_mad_send_wr,
&mad_agent_priv->send_list, agent_list) {
if ( V_142 -> V_126 == V_127 ) {
V_142 -> V_126 = V_330 ;
V_142 -> V_78 -= ( V_142 -> V_244 > 0 ) ;
}
}
F_104 ( & V_43 -> V_70 , & V_339 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_115 . V_126 = V_330 ;
V_115 . V_294 = 0 ;
F_83 (mad_send_wr, temp_mad_send_wr,
&cancel_list, agent_list) {
V_115 . V_113 = & V_142 -> V_113 ;
F_46 ( & V_142 -> V_86 ) ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_115 ) ;
F_51 ( & V_43 -> V_78 ) ;
}
}
static struct V_141 *
F_168 ( struct V_42 * V_43 ,
struct V_112 * V_113 )
{
struct V_141 * V_142 ;
F_2 (mad_send_wr, &mad_agent_priv->wait_list,
agent_list) {
if ( & V_142 -> V_113 == V_113 )
return V_142 ;
}
F_2 (mad_send_wr, &mad_agent_priv->send_list,
agent_list) {
if ( F_119 ( V_43 ,
V_142 -> V_113 . V_145 ) &&
& V_142 -> V_113 == V_113 )
return V_142 ;
}
return NULL ;
}
int F_169 ( struct V_33 * V_105 ,
struct V_112 * V_113 , T_4 V_241 )
{
struct V_42 * V_43 ;
struct V_141 * V_142 ;
unsigned long V_6 ;
int V_340 ;
V_43 = F_53 ( V_105 , struct V_42 ,
V_67 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
V_142 = F_168 ( V_43 , V_113 ) ;
if ( ! V_142 || V_142 -> V_126 != V_127 ) {
F_5 ( & V_43 -> V_68 , V_6 ) ;
return - V_41 ;
}
V_340 = ( ! V_142 -> V_244 || V_142 -> V_78 > 1 ) ;
if ( ! V_241 ) {
V_142 -> V_126 = V_330 ;
V_142 -> V_78 -= ( V_142 -> V_244 > 0 ) ;
}
V_142 -> V_113 . V_241 = V_241 ;
if ( V_340 )
V_142 -> V_244 = F_101 ( V_241 ) ;
else
F_162 ( V_142 , V_241 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
return 0 ;
}
void F_170 ( struct V_33 * V_105 ,
struct V_112 * V_113 )
{
F_169 ( V_105 , V_113 , 0 ) ;
}
static void V_77 ( struct V_341 * V_342 )
{
struct V_42 * V_43 ;
struct V_147 * V_148 ;
struct V_42 * V_150 ;
unsigned long V_6 ;
int V_343 ;
struct V_123 V_124 ;
struct V_114 V_115 ;
bool V_156 ;
V_43 =
F_53 ( V_342 , struct V_42 , V_76 ) ;
V_156 = F_65 ( V_43 -> V_61 -> V_39 -> V_3 ,
V_43 -> V_61 -> V_39 -> V_4 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_156 ( & V_43 -> V_75 ) ) {
V_148 = F_157 ( V_43 -> V_75 . V_198 ,
struct V_147 ,
V_177 ) ;
F_46 ( & V_148 -> V_177 ) ;
F_5 ( & V_43 -> V_68 , V_6 ) ;
V_343 = 0 ;
if ( V_148 -> V_149 ) {
T_1 V_168 ;
V_150 = V_148 -> V_150 ;
if ( ! V_150 ) {
F_69 ( & V_43 -> V_67 . V_3 -> V_52 ,
L_25 ) ;
V_343 = 1 ;
goto V_344;
}
F_58 ( V_150 -> V_67 . V_62 ,
V_148 -> V_142 -> V_153 . V_167 . V_125 ,
F_75 ( V_166 ) ,
V_148 -> V_142 -> V_153 . V_122 ,
V_150 -> V_67 . V_4 , & V_124 ) ;
V_148 -> V_149 -> V_258 . V_257 . V_124 = & V_124 ;
V_168 = ( (struct V_26 * ) ( V_148 -> V_149 -> V_145 ) ) -> V_168 ;
if ( V_156 && V_168 == V_169 ) {
V_148 -> V_149 -> V_258 . V_257 . V_319 = V_148 -> V_176 ;
V_148 -> V_149 -> V_258 . V_257 . V_320 = sizeof( struct V_204 ) ;
} else {
V_148 -> V_149 -> V_258 . V_257 . V_319 = sizeof( struct V_131 ) ;
V_148 -> V_149 -> V_258 . V_257 . V_320 = sizeof( struct V_131 ) ;
}
F_21 ( & V_148 -> V_149 -> V_258 . V_257 . V_72 ) ;
F_135 ( & V_148 -> V_149 -> V_258 . V_257 . V_256 . V_110 ,
& V_148 -> V_149 -> V_258 . V_257 . V_72 ) ;
V_148 -> V_149 -> V_258 . V_257 . V_256 . V_290 = NULL ;
V_148 -> V_149 -> V_258 . V_257 . V_256 . V_145 =
(struct V_131 * ) V_148 -> V_149 -> V_145 ;
if ( F_153 ( & V_150 -> V_61 -> V_99 ) )
F_57 ( V_150 -> V_61 ,
& V_148 -> V_149 -> V_258 . V_257 ,
V_89 ) ;
V_150 -> V_67 . V_36 (
& V_150 -> V_67 ,
& V_148 -> V_142 -> V_113 ,
& V_148 -> V_149 -> V_258 . V_257 ) ;
F_4 ( & V_150 -> V_68 , V_6 ) ;
F_51 ( & V_150 -> V_78 ) ;
F_5 ( & V_150 -> V_68 , V_6 ) ;
}
V_344:
V_115 . V_126 = V_127 ;
V_115 . V_294 = 0 ;
V_115 . V_113 = & V_148 -> V_142 -> V_113 ;
if ( F_153 ( & V_43 -> V_61 -> V_99 ) )
F_56 ( V_43 -> V_61 ,
& V_148 -> V_142 -> V_113 ,
& V_115 , V_88 ) ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_115 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
F_51 ( & V_43 -> V_78 ) ;
if ( V_343 )
F_31 ( V_148 -> V_149 ) ;
F_31 ( V_148 ) ;
}
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static int F_171 ( struct V_141 * V_142 )
{
int V_40 ;
if ( ! V_142 -> V_247 )
return - V_345 ;
V_142 -> V_247 -- ;
V_142 -> V_113 . V_246 ++ ;
V_142 -> V_244 = F_101 ( V_142 -> V_113 . V_241 ) ;
if ( F_86 ( & V_142 -> V_43 -> V_67 ) ) {
V_40 = F_172 ( V_142 ) ;
switch ( V_40 ) {
case V_325 :
V_40 = F_93 ( V_142 ) ;
break;
case V_248 :
V_40 = 0 ;
break;
default:
V_40 = - V_346 ;
break;
}
} else
V_40 = F_93 ( V_142 ) ;
if ( ! V_40 ) {
V_142 -> V_78 ++ ;
F_29 ( & V_142 -> V_86 ,
& V_142 -> V_43 -> V_69 ) ;
}
return V_40 ;
}
static void V_74 ( struct V_341 * V_342 )
{
struct V_42 * V_43 ;
struct V_141 * V_142 ;
struct V_114 V_115 ;
unsigned long V_6 , V_321 ;
V_43 = F_53 ( V_342 , struct V_42 ,
V_73 . V_342 ) ;
V_115 . V_294 = 0 ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
while ( ! F_156 ( & V_43 -> V_70 ) ) {
V_142 = F_157 ( V_43 -> V_70 . V_198 ,
struct V_141 ,
V_86 ) ;
if ( F_158 ( V_142 -> V_244 , V_322 ) ) {
V_321 = V_142 -> V_244 - V_322 ;
if ( ( long ) V_321 <= 0 )
V_321 = 1 ;
F_173 ( V_43 -> V_61 ->
V_39 -> V_104 ,
& V_43 -> V_73 , V_321 ) ;
break;
}
F_46 ( & V_142 -> V_86 ) ;
if ( V_142 -> V_126 == V_127 &&
! F_171 ( V_142 ) )
continue;
F_5 ( & V_43 -> V_68 , V_6 ) ;
if ( V_142 -> V_126 == V_127 )
V_115 . V_126 = V_347 ;
else
V_115 . V_126 = V_142 -> V_126 ;
V_115 . V_113 = & V_142 -> V_113 ;
V_43 -> V_67 . V_35 ( & V_43 -> V_67 ,
& V_115 ) ;
F_51 ( & V_43 -> V_78 ) ;
F_4 ( & V_43 -> V_68 , V_6 ) ;
}
F_5 ( & V_43 -> V_68 , V_6 ) ;
}
static int F_154 ( struct V_90 * V_61 ,
struct V_137 * V_145 )
{
unsigned long V_6 ;
int V_348 , V_40 ;
struct V_137 * V_149 ;
struct V_230 V_205 ;
struct V_349 V_350 , * V_351 ;
struct V_108 * V_352 = & V_61 -> V_352 ;
V_205 . V_207 = V_61 -> V_39 -> V_208 -> V_209 ;
V_350 . V_198 = NULL ;
V_350 . V_205 = & V_205 ;
V_350 . V_212 = 1 ;
do {
if ( V_145 ) {
V_149 = V_145 ;
V_145 = NULL ;
} else {
V_149 = F_60 ( F_61 ( V_61 -> V_39 ) ,
V_97 ) ;
if ( ! V_149 ) {
V_40 = - V_65 ;
break;
}
}
V_205 . V_206 = F_63 ( V_149 ) ;
V_205 . V_233 = F_94 ( V_61 -> V_39 -> V_3 ,
& V_149 -> V_290 ,
F_63 ( V_149 ) ,
V_318 ) ;
if ( F_95 ( F_96 ( V_61 -> V_39 -> V_3 ,
V_205 . V_233 ) ) ) {
V_40 = - V_65 ;
break;
}
V_149 -> V_258 . V_317 = V_205 . V_233 ;
V_149 -> V_258 . V_107 . V_109 = V_352 ;
V_149 -> V_258 . V_107 . V_120 . V_210 = F_151 ;
V_350 . V_125 = & V_149 -> V_258 . V_107 . V_120 ;
F_4 ( & V_352 -> V_68 , V_6 ) ;
V_348 = ( ++ V_352 -> V_111 < V_352 -> V_237 ) ;
F_29 ( & V_149 -> V_258 . V_107 . V_110 , & V_352 -> V_110 ) ;
F_5 ( & V_352 -> V_68 , V_6 ) ;
V_40 = F_174 ( V_61 -> V_62 , & V_350 , & V_351 ) ;
if ( V_40 ) {
F_4 ( & V_352 -> V_68 , V_6 ) ;
F_46 ( & V_149 -> V_258 . V_107 . V_110 ) ;
V_352 -> V_111 -- ;
F_5 ( & V_352 -> V_68 , V_6 ) ;
F_97 ( V_61 -> V_39 -> V_3 ,
V_149 -> V_258 . V_317 ,
F_63 ( V_149 ) ,
V_318 ) ;
F_31 ( V_149 ) ;
F_69 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_26 , V_40 ) ;
break;
}
} while ( V_348 );
return V_40 ;
}
static void F_175 ( struct V_90 * V_61 )
{
struct V_252 * V_253 ;
struct V_137 * V_296 ;
struct V_106 * V_107 ;
if ( ! V_61 -> V_62 )
return;
while ( ! F_156 ( & V_61 -> V_352 . V_110 ) ) {
V_107 = F_157 ( V_61 -> V_352 . V_110 . V_198 ,
struct V_106 , V_110 ) ;
V_253 = F_53 ( V_107 ,
struct V_252 ,
V_107 ) ;
V_296 = F_53 ( V_253 , struct V_137 ,
V_258 ) ;
F_46 ( & V_107 -> V_110 ) ;
F_97 ( V_61 -> V_39 -> V_3 ,
V_296 -> V_258 . V_317 ,
F_63 ( V_296 ) ,
V_318 ) ;
F_31 ( V_296 ) ;
}
V_61 -> V_352 . V_111 = 0 ;
}
static int F_176 ( struct V_1 * V_39 )
{
int V_40 , V_23 ;
struct V_331 * V_279 ;
struct V_118 * V_62 ;
T_6 V_122 ;
V_279 = F_78 ( sizeof *V_279 , V_64 ) ;
if ( ! V_279 )
return - V_65 ;
V_40 = F_177 ( V_39 -> V_3 , V_39 -> V_4 ,
V_353 , & V_122 ) ;
if ( V_40 )
V_122 = 0 ;
for ( V_23 = 0 ; V_23 < V_354 ; V_23 ++ ) {
V_62 = V_39 -> V_61 [ V_23 ] . V_62 ;
if ( ! V_62 )
continue;
V_279 -> V_332 = V_355 ;
V_279 -> V_122 = V_122 ;
V_279 -> V_356 = ( V_62 -> V_271 == 0 ) ? 0 : V_357 ;
V_40 = F_167 ( V_62 , V_279 , V_336 |
V_358 | V_359 ) ;
if ( V_40 ) {
F_69 ( & V_39 -> V_3 -> V_52 ,
L_27 ,
V_23 , V_40 ) ;
goto V_98;
}
V_279 -> V_332 = V_360 ;
V_40 = F_167 ( V_62 , V_279 , V_336 ) ;
if ( V_40 ) {
F_69 ( & V_39 -> V_3 -> V_52 ,
L_28 ,
V_23 , V_40 ) ;
goto V_98;
}
V_279 -> V_332 = V_333 ;
V_279 -> V_361 = V_362 ;
V_40 = F_167 ( V_62 , V_279 , V_336 | V_363 ) ;
if ( V_40 ) {
F_69 ( & V_39 -> V_3 -> V_52 ,
L_29 ,
V_23 , V_40 ) ;
goto V_98;
}
}
V_40 = F_178 ( V_39 -> V_313 , V_364 ) ;
if ( V_40 ) {
F_69 ( & V_39 -> V_3 -> V_52 ,
L_30 ,
V_40 ) ;
goto V_98;
}
for ( V_23 = 0 ; V_23 < V_354 ; V_23 ++ ) {
if ( ! V_39 -> V_61 [ V_23 ] . V_62 )
continue;
V_40 = F_154 ( & V_39 -> V_61 [ V_23 ] , NULL ) ;
if ( V_40 ) {
F_69 ( & V_39 -> V_3 -> V_52 ,
L_31 ) ;
goto V_98;
}
}
V_98:
F_31 ( V_279 ) ;
return V_40 ;
}
static void F_179 ( struct V_365 * V_366 , void * V_367 )
{
struct V_90 * V_61 = V_367 ;
F_69 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_32 ,
V_366 -> V_366 , V_61 -> V_62 -> V_271 ) ;
}
static void F_180 ( struct V_90 * V_61 ,
struct V_108 * V_109 )
{
V_109 -> V_61 = V_61 ;
V_109 -> V_111 = 0 ;
F_20 ( & V_109 -> V_68 ) ;
F_21 ( & V_109 -> V_110 ) ;
}
static void F_181 ( struct V_1 * V_39 ,
struct V_90 * V_61 )
{
V_61 -> V_39 = V_39 ;
F_180 ( V_61 , & V_61 -> V_232 ) ;
F_180 ( V_61 , & V_61 -> V_352 ) ;
F_21 ( & V_61 -> V_238 ) ;
F_20 ( & V_61 -> V_94 ) ;
V_61 -> V_96 = NULL ;
V_61 -> V_95 = 0 ;
F_24 ( & V_61 -> V_99 , 0 ) ;
}
static int F_182 ( struct V_90 * V_61 ,
enum V_10 V_11 )
{
struct V_368 V_369 ;
int V_40 ;
memset ( & V_369 , 0 , sizeof V_369 ) ;
V_369 . V_370 = V_61 -> V_39 -> V_313 ;
V_369 . V_371 = V_61 -> V_39 -> V_313 ;
V_369 . V_372 = V_373 ;
V_369 . V_374 . V_375 = V_376 ;
V_369 . V_374 . V_377 = V_378 ;
V_369 . V_374 . V_379 = V_380 ;
V_369 . V_374 . V_381 = V_382 ;
V_369 . V_11 = V_11 ;
V_369 . V_4 = V_61 -> V_39 -> V_4 ;
V_369 . V_367 = V_61 ;
V_369 . V_383 = F_179 ;
V_61 -> V_62 = F_183 ( V_61 -> V_39 -> V_208 , & V_369 ) ;
if ( F_184 ( V_61 -> V_62 ) ) {
F_69 ( & V_61 -> V_39 -> V_3 -> V_52 ,
L_33 ,
F_7 ( V_11 ) ) ;
V_40 = F_185 ( V_61 -> V_62 ) ;
goto error;
}
V_61 -> V_232 . V_237 = V_376 ;
V_61 -> V_352 . V_237 = V_378 ;
return 0 ;
error:
return V_40 ;
}
static void F_186 ( struct V_90 * V_61 )
{
if ( ! V_61 -> V_62 )
return;
F_187 ( V_61 -> V_62 ) ;
F_31 ( V_61 -> V_96 ) ;
}
static int F_188 ( struct V_2 * V_3 ,
int V_4 )
{
int V_40 , V_384 ;
struct V_1 * V_39 ;
unsigned long V_6 ;
char V_385 [ sizeof "ib_mad123"];
int V_386 ;
if ( F_189 ( F_62 ( V_3 , V_4 ) < V_387 ) )
return - V_388 ;
if ( F_189 ( F_65 ( V_3 , V_4 ) &&
F_62 ( V_3 , V_4 ) < V_389 ) )
return - V_388 ;
V_39 = F_18 ( sizeof *V_39 , V_64 ) ;
if ( ! V_39 )
return - V_65 ;
V_39 -> V_3 = V_3 ;
V_39 -> V_4 = V_4 ;
F_20 ( & V_39 -> V_81 ) ;
F_21 ( & V_39 -> V_86 ) ;
F_181 ( V_39 , & V_39 -> V_61 [ 0 ] ) ;
F_181 ( V_39 , & V_39 -> V_61 [ 1 ] ) ;
V_384 = V_376 + V_378 ;
V_386 = F_190 ( V_3 , V_4 ) ;
if ( V_386 )
V_384 *= 2 ;
V_39 -> V_313 = F_191 ( V_39 -> V_3 , V_39 , V_384 , 0 ,
V_390 ) ;
if ( F_184 ( V_39 -> V_313 ) ) {
F_69 ( & V_3 -> V_52 , L_34 ) ;
V_40 = F_185 ( V_39 -> V_313 ) ;
goto V_66;
}
V_39 -> V_208 = F_192 ( V_3 , 0 ) ;
if ( F_184 ( V_39 -> V_208 ) ) {
F_69 ( & V_3 -> V_52 , L_35 ) ;
V_40 = F_185 ( V_39 -> V_208 ) ;
goto V_80;
}
if ( V_386 ) {
V_40 = F_182 ( & V_39 -> V_61 [ 0 ] , V_12 ) ;
if ( V_40 )
goto V_391;
}
V_40 = F_182 ( & V_39 -> V_61 [ 1 ] , V_13 ) ;
if ( V_40 )
goto V_392;
snprintf ( V_385 , sizeof V_385 , L_36 , V_4 ) ;
V_39 -> V_104 = F_193 ( V_385 , V_393 ) ;
if ( ! V_39 -> V_104 ) {
V_40 = - V_65 ;
goto V_394;
}
F_4 ( & V_7 , V_6 ) ;
F_29 ( & V_39 -> V_316 , & V_395 ) ;
F_5 ( & V_7 , V_6 ) ;
V_40 = F_176 ( V_39 ) ;
if ( V_40 ) {
F_69 ( & V_3 -> V_52 , L_37 ) ;
goto V_396;
}
return 0 ;
V_396:
F_4 ( & V_7 , V_6 ) ;
F_194 ( & V_39 -> V_316 ) ;
F_5 ( & V_7 , V_6 ) ;
F_195 ( V_39 -> V_104 ) ;
V_394:
F_186 ( & V_39 -> V_61 [ 1 ] ) ;
V_392:
F_186 ( & V_39 -> V_61 [ 0 ] ) ;
V_391:
F_196 ( V_39 -> V_208 ) ;
V_80:
F_197 ( V_39 -> V_313 ) ;
F_175 ( & V_39 -> V_61 [ 1 ] ) ;
F_175 ( & V_39 -> V_61 [ 0 ] ) ;
V_66:
F_31 ( V_39 ) ;
return V_40 ;
}
static int F_198 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_39 ;
unsigned long V_6 ;
F_4 ( & V_7 , V_6 ) ;
V_39 = F_1 ( V_3 , V_4 ) ;
if ( V_39 == NULL ) {
F_5 ( & V_7 , V_6 ) ;
F_69 ( & V_3 -> V_52 , L_38 , V_4 ) ;
return - V_60 ;
}
F_194 ( & V_39 -> V_316 ) ;
F_5 ( & V_7 , V_6 ) ;
F_195 ( V_39 -> V_104 ) ;
F_186 ( & V_39 -> V_61 [ 1 ] ) ;
F_186 ( & V_39 -> V_61 [ 0 ] ) ;
F_196 ( V_39 -> V_208 ) ;
F_197 ( V_39 -> V_313 ) ;
F_175 ( & V_39 -> V_61 [ 1 ] ) ;
F_175 ( & V_39 -> V_61 [ 0 ] ) ;
F_31 ( V_39 ) ;
return 0 ;
}
static void F_199 ( struct V_2 * V_3 )
{
int V_397 , V_23 ;
V_397 = F_200 ( V_3 ) ;
for ( V_23 = V_397 ; V_23 <= F_201 ( V_3 ) ; V_23 ++ ) {
if ( ! F_202 ( V_3 , V_23 ) )
continue;
if ( F_188 ( V_3 , V_23 ) ) {
F_69 ( & V_3 -> V_52 , L_39 , V_23 ) ;
goto error;
}
if ( F_203 ( V_3 , V_23 ) ) {
F_69 ( & V_3 -> V_52 ,
L_40 , V_23 ) ;
goto V_398;
}
}
return;
V_398:
if ( F_198 ( V_3 , V_23 ) )
F_69 ( & V_3 -> V_52 , L_41 , V_23 ) ;
error:
while ( -- V_23 >= V_397 ) {
if ( ! F_202 ( V_3 , V_23 ) )
continue;
if ( F_204 ( V_3 , V_23 ) )
F_69 ( & V_3 -> V_52 ,
L_42 , V_23 ) ;
if ( F_198 ( V_3 , V_23 ) )
F_69 ( & V_3 -> V_52 , L_41 , V_23 ) ;
}
}
static void F_205 ( struct V_2 * V_3 , void * V_399 )
{
int V_23 ;
for ( V_23 = F_200 ( V_3 ) ; V_23 <= F_201 ( V_3 ) ; V_23 ++ ) {
if ( ! F_202 ( V_3 , V_23 ) )
continue;
if ( F_204 ( V_3 , V_23 ) )
F_69 ( & V_3 -> V_52 ,
L_42 , V_23 ) ;
if ( F_198 ( V_3 , V_23 ) )
F_69 ( & V_3 -> V_52 , L_41 , V_23 ) ;
}
}
int F_206 ( void )
{
V_378 = F_207 ( V_378 , V_400 ) ;
V_378 = F_208 ( V_378 , V_401 ) ;
V_376 = F_207 ( V_376 , V_400 ) ;
V_376 = F_208 ( V_376 , V_401 ) ;
F_21 ( & V_395 ) ;
if ( F_209 ( & V_402 ) ) {
F_108 ( L_43 ) ;
return - V_41 ;
}
return 0 ;
}
void F_210 ( void )
{
F_211 ( & V_402 ) ;
}
