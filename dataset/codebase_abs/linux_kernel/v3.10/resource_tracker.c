static inline const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 : return L_1 ;
case V_4 : return L_2 ;
default: return L_3 ;
}
}
static void * F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
struct V_8 * V_9 = V_6 -> V_8 ;
while ( V_9 ) {
struct V_10 * V_11 = F_3 ( V_9 , struct V_10 ,
V_9 ) ;
if ( V_7 < V_11 -> V_7 )
V_9 = V_9 -> V_12 ;
else if ( V_7 > V_11 -> V_7 )
V_9 = V_9 -> V_13 ;
else
return V_11 ;
}
return NULL ;
}
static int F_4 ( struct V_5 * V_6 , struct V_10 * V_11 )
{
struct V_8 * * V_14 = & ( V_6 -> V_8 ) , * V_15 = NULL ;
while ( * V_14 ) {
struct V_10 * V_16 = F_3 ( * V_14 , struct V_10 ,
V_9 ) ;
V_15 = * V_14 ;
if ( V_11 -> V_7 < V_16 -> V_7 )
V_14 = & ( ( * V_14 ) -> V_12 ) ;
else if ( V_11 -> V_7 > V_16 -> V_7 )
V_14 = & ( ( * V_14 ) -> V_13 ) ;
else
return - V_17 ;
}
F_5 ( & V_11 -> V_9 , V_15 , V_14 ) ;
F_6 ( & V_11 -> V_9 , V_6 ) ;
return 0 ;
}
static const char * F_7 ( enum V_18 V_19 )
{
switch ( V_19 ) {
case V_20 : return L_4 ;
case V_21 : return L_5 ;
case V_22 : return L_6 ;
case V_23 : return L_7 ;
case V_24 : return L_8 ;
case V_25 : return L_9 ;
case V_26 : return L_10 ;
case V_27 : return L_11 ;
case V_28 : return L_12 ;
case V_29 : return L_13 ;
default: return L_14 ;
} ;
}
int F_8 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
int V_34 ;
int V_35 ;
V_33 -> V_36 . V_37 . V_38 . V_39 =
F_9 ( V_31 -> V_40 * sizeof( struct V_39 ) ,
V_41 ) ;
if ( ! V_33 -> V_36 . V_37 . V_38 . V_39 )
return - V_42 ;
for ( V_34 = 0 ; V_34 < V_31 -> V_40 ; V_34 ++ ) {
for ( V_35 = 0 ; V_35 < V_43 ; ++ V_35 )
F_10 ( & V_33 -> V_36 . V_37 . V_38 .
V_39 [ V_34 ] . V_44 [ V_35 ] ) ;
F_11 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_34 ] . V_45 ) ;
}
F_12 ( V_31 , L_15 ,
V_31 -> V_40 ) ;
for ( V_34 = 0 ; V_34 < V_43 ; V_34 ++ )
V_33 -> V_36 . V_37 . V_38 . V_46 [ V_34 ] = V_47 ;
F_13 ( & V_33 -> V_36 . V_37 . V_38 . V_48 ) ;
return 0 ;
}
void F_14 ( struct V_30 * V_31 ,
enum V_49 type )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
int V_34 ;
if ( V_33 -> V_36 . V_37 . V_38 . V_39 ) {
if ( type != V_50 )
for ( V_34 = 0 ; V_34 < V_31 -> V_40 ; V_34 ++ )
if ( type == V_51 ||
V_31 -> V_52 . V_53 != V_34 )
F_15 ( V_31 , V_34 ) ;
if ( type != V_54 ) {
F_16 ( V_33 -> V_36 . V_37 . V_38 . V_39 ) ;
V_33 -> V_36 . V_37 . V_38 . V_39 = NULL ;
}
}
}
static void F_17 ( struct V_30 * V_31 , int V_55 ,
struct V_56 * V_57 )
{
T_2 V_58 = * ( T_2 * ) ( V_57 -> V_59 + 64 ) ;
T_2 V_60 = * ( T_2 * ) ( V_57 -> V_59 + 35 ) ;
T_2 V_61 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
int V_62 ;
V_62 = ( V_58 >> 6 & 1 ) + 1 ;
V_61 = V_33 -> V_63 [ V_55 ] [ V_62 - 1 ] [ V_60 ] ;
* ( T_2 * ) ( V_57 -> V_59 + 35 ) = V_61 ;
}
static void F_18 ( struct V_30 * V_31 , struct V_56 * V_57 ,
T_2 V_55 )
{
struct V_64 * V_65 = V_57 -> V_59 + 8 ;
enum V_66 V_67 = F_19 ( * ( V_68 * ) V_57 -> V_59 ) ;
T_3 V_69 = ( F_19 ( V_65 -> V_70 ) >> 16 ) & 0xff ;
if ( V_71 == V_69 )
V_65 -> V_72 . V_73 = 0x80 | V_55 ;
if ( V_74 == V_69 || V_75 == V_69 ) {
if ( V_67 & V_76 )
V_65 -> V_72 . V_73 = V_55 & 0x7F ;
if ( V_67 & V_77 )
V_65 -> V_78 . V_73 = V_55 & 0x7F ;
}
}
static int F_20 ( struct V_30 * V_31 ,
struct V_56 * V_57 ,
T_2 V_55 )
{
struct V_64 * V_79 = V_57 -> V_59 + 8 ;
struct V_80 * V_81 ;
struct V_32 * V_33 ;
T_3 V_82 ;
int V_62 ;
V_62 = ( V_79 -> V_72 . V_83 & 0x40 ) ? 2 : 1 ;
V_33 = V_32 ( V_31 ) ;
V_81 = & V_33 -> V_36 . V_37 . V_84 [ V_55 ] . V_85 [ V_62 ] ;
if ( V_86 != V_81 -> V_2 . V_87 ) {
V_82 = ( F_19 ( V_79 -> V_70 ) >> 16 ) & 0xff ;
if ( V_74 == V_82 )
return - V_88 ;
V_79 -> V_89 &= ~ F_21 ( V_90 ) ;
if ( 0 != V_81 -> V_2 . V_87 ) {
V_79 -> V_72 . V_91 =
V_92 |
V_93 |
V_94 ;
} else {
V_79 -> V_72 . V_91 =
V_92 |
V_95 ;
}
V_79 -> V_72 . V_96 |= V_97 ;
V_79 -> V_72 . V_98 = V_81 -> V_99 ;
V_79 -> V_72 . V_100 |= V_101 | V_102 ;
V_79 -> V_72 . V_103 |= V_104 | V_105 ;
V_79 -> V_72 . V_83 &= 0xC7 ;
V_79 -> V_72 . V_83 |= ( V_81 -> V_2 . V_106 ) << 3 ;
}
if ( V_81 -> V_2 . V_107 ) {
V_79 -> V_72 . V_103 |= V_108 ;
V_79 -> V_72 . V_109 = ( 0x80 & V_79 -> V_72 . V_109 ) + V_81 -> V_110 ;
}
return 0 ;
}
static int F_22 ( struct V_30 * V_31 )
{
return V_31 -> V_52 . V_111 - 1 ;
}
static void * F_23 ( struct V_30 * V_31 , T_1 V_7 ,
enum V_18 type )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
return F_2 ( & V_33 -> V_36 . V_37 . V_38 . V_46 [ type ] ,
V_7 ) ;
}
static int F_24 ( struct V_30 * V_31 , int V_55 , T_1 V_7 ,
enum V_18 type ,
void * V_11 )
{
struct V_10 * V_112 ;
int V_113 = 0 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_23 ( V_31 , V_7 , type ) ;
if ( ! V_112 ) {
V_113 = - V_114 ;
goto exit;
}
if ( V_112 -> V_2 == V_115 ) {
V_113 = - V_116 ;
goto exit;
}
if ( V_112 -> V_117 != V_55 ) {
V_113 = - V_118 ;
goto exit;
}
V_112 -> V_119 = V_112 -> V_2 ;
V_112 -> V_2 = V_115 ;
if ( V_11 )
* ( (struct V_10 * * ) V_11 ) = V_112 ;
exit:
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
int F_28 ( struct V_30 * V_31 ,
enum V_18 type ,
T_1 V_7 , int * V_55 )
{
struct V_10 * V_112 ;
int V_113 = - V_120 ;
int V_121 = V_7 ;
if ( type == V_20 )
V_121 &= 0x7fffff ;
F_29 ( F_26 ( V_31 ) ) ;
V_112 = F_23 ( V_31 , V_121 , type ) ;
if ( V_112 ) {
* V_55 = V_112 -> V_117 ;
V_113 = 0 ;
}
F_30 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static void F_31 ( struct V_30 * V_31 , int V_55 , T_1 V_7 ,
enum V_18 type )
{
struct V_10 * V_112 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_23 ( V_31 , V_7 , type ) ;
if ( V_112 )
V_112 -> V_2 = V_112 -> V_119 ;
F_27 ( F_26 ( V_31 ) ) ;
}
static struct V_10 * F_32 ( int V_121 )
{
struct V_122 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_125 ;
V_123 -> V_126 = V_121 ;
F_10 ( & V_123 -> V_127 ) ;
F_13 ( & V_123 -> V_128 ) ;
F_33 ( & V_123 -> V_129 , 0 ) ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_34 ( int V_121 , int V_130 )
{
struct V_131 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_130 = V_130 ;
V_123 -> V_124 . V_2 = V_4 ;
F_33 ( & V_123 -> V_129 , 0 ) ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_35 ( int V_121 , int V_132 )
{
struct V_133 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_134 ;
V_123 -> V_132 = V_132 ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_36 ( int V_121 )
{
struct V_135 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_136 ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_37 ( int V_121 )
{
struct V_137 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_138 ;
F_33 ( & V_123 -> V_129 , 0 ) ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_38 ( int V_121 )
{
struct V_139 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_140 ;
F_33 ( & V_123 -> V_129 , 0 ) ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_39 ( int V_121 )
{
struct V_141 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_142 ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_40 ( int V_121 )
{
struct V_143 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_144 ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_41 ( T_1 V_121 , int V_145 )
{
struct V_146 * V_123 ;
V_123 = F_9 ( sizeof *V_123 , V_41 ) ;
if ( ! V_123 )
return NULL ;
V_123 -> V_124 . V_7 = V_121 ;
V_123 -> V_124 . V_2 = V_147 ;
V_123 -> V_145 = V_145 ;
return & V_123 -> V_124 ;
}
static struct V_10 * F_42 ( T_1 V_121 , enum V_18 type , int V_55 ,
int V_148 )
{
struct V_10 * V_123 ;
switch ( type ) {
case V_20 :
V_123 = F_32 ( V_121 ) ;
break;
case V_23 :
V_123 = F_35 ( V_121 , V_148 ) ;
break;
case V_24 :
V_123 = F_34 ( V_121 , V_148 ) ;
break;
case V_26 :
V_123 = F_36 ( V_121 ) ;
break;
case V_21 :
V_123 = F_37 ( V_121 ) ;
break;
case V_22 :
V_123 = F_38 ( V_121 ) ;
break;
case V_25 :
F_43 ( V_149 L_16 ) ;
return NULL ;
case V_27 :
V_123 = F_39 ( V_121 ) ;
break;
case V_29 :
V_123 = F_40 ( V_121 ) ;
break;
case V_28 :
V_123 = F_41 ( V_121 , V_148 ) ;
break;
default:
return NULL ;
}
if ( V_123 )
V_123 -> V_117 = V_55 ;
return V_123 ;
}
static int F_44 ( struct V_30 * V_31 , int V_55 , T_1 V_150 , int V_151 ,
enum V_18 type , int V_148 )
{
int V_34 ;
int V_113 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_10 * * V_152 ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_5 * V_6 = & V_154 -> V_46 [ type ] ;
V_152 = F_9 ( V_151 * sizeof *V_152 , V_41 ) ;
if ( ! V_152 )
return - V_42 ;
for ( V_34 = 0 ; V_34 < V_151 ; ++ V_34 ) {
V_152 [ V_34 ] = F_42 ( V_150 + V_34 , type , V_55 , V_148 ) ;
if ( ! V_152 [ V_34 ] ) {
for ( -- V_34 ; V_34 >= 0 ; -- V_34 )
F_16 ( V_152 [ V_34 ] ) ;
F_16 ( V_152 ) ;
return - V_42 ;
}
}
F_25 ( F_26 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_151 ; ++ V_34 ) {
if ( F_23 ( V_31 , V_150 + V_34 , type ) ) {
V_113 = - V_17 ;
goto V_155;
}
V_113 = F_4 ( V_6 , V_152 [ V_34 ] ) ;
if ( V_113 )
goto V_155;
F_45 ( & V_152 [ V_34 ] -> V_156 ,
& V_154 -> V_39 [ V_55 ] . V_44 [ type ] ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_152 ) ;
return 0 ;
V_155:
for ( -- V_34 ; V_34 >= V_150 ; -- V_34 )
F_46 ( & V_152 [ V_34 ] -> V_9 , V_6 ) ;
F_27 ( F_26 ( V_31 ) ) ;
for ( V_34 = 0 ; V_34 < V_151 ; ++ V_34 )
F_16 ( V_152 [ V_34 ] ) ;
F_16 ( V_152 ) ;
return V_113 ;
}
static int F_47 ( struct V_122 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_157 || F_48 ( & V_11 -> V_129 ) ||
! F_49 ( & V_11 -> V_127 ) ) {
F_50 ( L_17 ,
V_11 -> V_124 . V_2 , F_48 ( & V_11 -> V_129 ) ) ;
return - V_116 ;
} else if ( V_11 -> V_124 . V_2 != V_125 ) {
return - V_118 ;
}
return 0 ;
}
static int F_51 ( struct V_131 * V_11 , int V_130 )
{
if ( V_11 -> V_124 . V_2 == V_3 ||
F_48 ( & V_11 -> V_129 ) ) {
F_43 ( V_158 L_18 ,
V_159 , __LINE__ ,
F_1 ( V_11 -> V_124 . V_2 ) ,
F_48 ( & V_11 -> V_129 ) ) ;
return - V_116 ;
} else if ( V_11 -> V_124 . V_2 != V_4 )
return - V_118 ;
else if ( V_11 -> V_130 != V_130 )
return - V_88 ;
return 0 ;
}
static int F_52 ( struct V_133 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_160 )
return - V_116 ;
else if ( V_11 -> V_124 . V_2 != V_134 )
return - V_118 ;
return 0 ;
}
static int F_53 ( struct V_135 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_160 )
return - V_116 ;
else if ( V_11 -> V_124 . V_2 != V_134 )
return - V_118 ;
return 0 ;
}
static int F_54 ( struct V_141 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_161 )
return - V_116 ;
else if ( V_11 -> V_124 . V_2 != V_142 )
return - V_118 ;
return 0 ;
}
static int F_55 ( struct V_143 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_162 )
return - V_116 ;
else if ( V_11 -> V_124 . V_2 != V_144 )
return - V_118 ;
return 0 ;
}
static int F_56 ( struct V_146 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_163 )
return - V_116 ;
else if ( V_11 -> V_124 . V_2 != V_147 )
return - V_118 ;
return 0 ;
}
static int F_57 ( struct V_137 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_164 )
return - V_116 ;
else if ( V_11 -> V_124 . V_2 != V_138 )
return - V_118 ;
return 0 ;
}
static int F_58 ( struct V_139 * V_11 )
{
if ( V_11 -> V_124 . V_2 == V_165 )
return - V_116 ;
else if ( V_11 -> V_124 . V_2 != V_140 )
return - V_118 ;
return 0 ;
}
static int F_59 ( struct V_10 * V_11 , enum V_18 type , int V_148 )
{
switch ( type ) {
case V_20 :
return F_47 ( (struct V_122 * ) V_11 ) ;
case V_21 :
return F_57 ( (struct V_137 * ) V_11 ) ;
case V_22 :
return F_58 ( (struct V_139 * ) V_11 ) ;
case V_23 :
return F_52 ( (struct V_133 * ) V_11 ) ;
case V_24 :
return F_51 ( (struct V_131 * ) V_11 , V_148 ) ;
case V_25 :
return - V_166 ;
case V_26 :
return F_53 ( (struct V_135 * ) V_11 ) ;
case V_27 :
return F_54 ( (struct V_141 * ) V_11 ) ;
case V_29 :
return F_55 ( (struct V_143 * ) V_11 ) ;
case V_28 :
return F_56 ( (struct V_146 * ) V_11 ) ;
default:
return - V_88 ;
}
}
static int F_60 ( struct V_30 * V_31 , int V_55 , T_1 V_150 , int V_151 ,
enum V_18 type , int V_148 )
{
T_1 V_34 ;
int V_113 ;
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_112 ;
F_25 ( F_26 ( V_31 ) ) ;
for ( V_34 = V_150 ; V_34 < V_150 + V_151 ; ++ V_34 ) {
V_112 = F_2 ( & V_154 -> V_46 [ type ] , V_34 ) ;
if ( ! V_112 ) {
V_113 = - V_120 ;
goto V_167;
}
if ( V_112 -> V_117 != V_55 ) {
V_113 = - V_118 ;
goto V_167;
}
V_113 = F_59 ( V_112 , type , V_148 ) ;
if ( V_113 )
goto V_167;
}
for ( V_34 = V_150 ; V_34 < V_150 + V_151 ; ++ V_34 ) {
V_112 = F_2 ( & V_154 -> V_46 [ type ] , V_34 ) ;
F_46 ( & V_112 -> V_9 , & V_154 -> V_46 [ type ] ) ;
F_61 ( & V_112 -> V_156 ) ;
F_16 ( V_112 ) ;
}
V_113 = 0 ;
V_167:
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static int F_62 ( struct V_30 * V_31 , int V_55 , int V_145 ,
enum V_168 V_2 , struct V_122 * * V_169 ,
int V_170 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_122 * V_112 ;
int V_113 = 0 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_2 ( & V_154 -> V_46 [ V_20 ] , V_145 ) ;
if ( ! V_112 )
V_113 = - V_120 ;
else if ( V_112 -> V_124 . V_117 != V_55 )
V_113 = - V_118 ;
else {
switch ( V_2 ) {
case V_157 :
F_12 ( V_31 , L_19 ,
V_159 , V_112 -> V_124 . V_7 ) ;
V_113 = - V_116 ;
break;
case V_125 :
if ( V_112 -> V_124 . V_2 == V_171 && ! V_170 )
break;
F_12 ( V_31 , L_20 , V_112 -> V_124 . V_7 ) ;
V_113 = - V_88 ;
break;
case V_171 :
if ( ( V_112 -> V_124 . V_2 == V_125 && V_170 ) ||
V_112 -> V_124 . V_2 == V_172 )
break;
else {
F_12 ( V_31 , L_20 ,
V_112 -> V_124 . V_7 ) ;
V_113 = - V_88 ;
}
break;
case V_172 :
if ( V_112 -> V_124 . V_2 != V_171 )
V_113 = - V_88 ;
break;
default:
V_113 = - V_88 ;
}
if ( ! V_113 ) {
V_112 -> V_124 . V_119 = V_112 -> V_124 . V_2 ;
V_112 -> V_124 . V_173 = V_2 ;
V_112 -> V_124 . V_2 = V_157 ;
if ( V_169 )
* V_169 = V_112 ;
}
}
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static int F_63 ( struct V_30 * V_31 , int V_55 , int V_174 ,
enum V_175 V_2 , struct V_133 * * V_176 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_133 * V_112 ;
int V_113 = 0 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_2 ( & V_154 -> V_46 [ V_23 ] , V_174 ) ;
if ( ! V_112 )
V_113 = - V_120 ;
else if ( V_112 -> V_124 . V_117 != V_55 )
V_113 = - V_118 ;
else {
switch ( V_2 ) {
case V_160 :
V_113 = - V_88 ;
break;
case V_134 :
if ( V_112 -> V_124 . V_2 != V_177 )
V_113 = - V_88 ;
break;
case V_177 :
if ( V_112 -> V_124 . V_2 != V_134 &&
V_112 -> V_124 . V_2 != V_178 )
V_113 = - V_88 ;
break;
case V_178 :
if ( V_112 -> V_124 . V_2 != V_177 )
V_113 = - V_88 ;
break;
default:
V_113 = - V_88 ;
}
if ( ! V_113 ) {
V_112 -> V_124 . V_119 = V_112 -> V_124 . V_2 ;
V_112 -> V_124 . V_173 = V_2 ;
V_112 -> V_124 . V_2 = V_160 ;
if ( V_176 )
* V_176 = V_112 ;
}
}
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static int F_64 ( struct V_30 * V_31 , int V_55 , int V_174 ,
enum V_179 V_2 , struct V_135 * * V_180 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_135 * V_112 ;
int V_113 = 0 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_2 ( & V_154 -> V_46 [ V_26 ] , V_174 ) ;
if ( ! V_112 )
V_113 = - V_120 ;
else if ( V_112 -> V_124 . V_117 != V_55 )
V_113 = - V_118 ;
else {
switch ( V_2 ) {
case V_181 :
V_113 = - V_88 ;
break;
case V_136 :
if ( V_112 -> V_124 . V_2 != V_182 )
V_113 = - V_88 ;
break;
case V_182 :
if ( V_112 -> V_124 . V_2 != V_136 )
V_113 = - V_88 ;
break;
default:
V_113 = - V_88 ;
}
if ( ! V_113 ) {
V_112 -> V_124 . V_119 = V_112 -> V_124 . V_2 ;
V_112 -> V_124 . V_173 = V_2 ;
V_112 -> V_124 . V_2 = V_181 ;
if ( V_180 )
* V_180 = V_112 ;
}
}
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static int F_65 ( struct V_30 * V_31 , int V_55 , int V_183 ,
enum V_184 V_2 , struct V_137 * * V_185 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_137 * V_112 ;
int V_113 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_2 ( & V_154 -> V_46 [ V_21 ] , V_183 ) ;
if ( ! V_112 )
V_113 = - V_120 ;
else if ( V_112 -> V_124 . V_117 != V_55 )
V_113 = - V_118 ;
else {
switch ( V_2 ) {
case V_164 :
V_113 = - V_116 ;
break;
case V_138 :
if ( V_112 -> V_124 . V_2 != V_186 )
V_113 = - V_88 ;
else if ( F_48 ( & V_112 -> V_129 ) )
V_113 = - V_116 ;
else
V_113 = 0 ;
break;
case V_186 :
if ( V_112 -> V_124 . V_2 != V_138 )
V_113 = - V_88 ;
else
V_113 = 0 ;
break;
default:
V_113 = - V_88 ;
}
if ( ! V_113 ) {
V_112 -> V_124 . V_119 = V_112 -> V_124 . V_2 ;
V_112 -> V_124 . V_173 = V_2 ;
V_112 -> V_124 . V_2 = V_164 ;
if ( V_185 )
* V_185 = V_112 ;
}
}
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static int F_66 ( struct V_30 * V_31 , int V_55 , int V_174 ,
enum V_184 V_2 , struct V_139 * * V_187 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_139 * V_112 ;
int V_113 = 0 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_2 ( & V_154 -> V_46 [ V_22 ] , V_174 ) ;
if ( ! V_112 )
V_113 = - V_120 ;
else if ( V_112 -> V_124 . V_117 != V_55 )
V_113 = - V_118 ;
else {
switch ( V_2 ) {
case V_165 :
V_113 = - V_88 ;
break;
case V_140 :
if ( V_112 -> V_124 . V_2 != V_188 )
V_113 = - V_88 ;
else if ( F_48 ( & V_112 -> V_129 ) )
V_113 = - V_116 ;
break;
case V_188 :
if ( V_112 -> V_124 . V_2 != V_140 )
V_113 = - V_88 ;
break;
default:
V_113 = - V_88 ;
}
if ( ! V_113 ) {
V_112 -> V_124 . V_119 = V_112 -> V_124 . V_2 ;
V_112 -> V_124 . V_173 = V_2 ;
V_112 -> V_124 . V_2 = V_165 ;
if ( V_187 )
* V_187 = V_112 ;
}
}
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static void F_67 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_121 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_112 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_2 ( & V_154 -> V_46 [ type ] , V_121 ) ;
if ( V_112 && ( V_112 -> V_117 == V_55 ) )
V_112 -> V_2 = V_112 -> V_119 ;
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_68 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_121 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_10 * V_112 ;
F_25 ( F_26 ( V_31 ) ) ;
V_112 = F_2 ( & V_154 -> V_46 [ type ] , V_121 ) ;
if ( V_112 && ( V_112 -> V_117 == V_55 ) )
V_112 -> V_2 = V_112 -> V_173 ;
F_27 ( F_26 ( V_31 ) ) ;
}
static int F_69 ( struct V_30 * V_31 , int V_55 , int V_145 )
{
return F_70 ( V_31 , V_145 ) &&
( F_71 ( V_31 ) || F_72 ( V_31 , V_55 , V_145 ) ) ;
}
static int F_73 ( struct V_30 * V_31 , int V_145 )
{
return V_145 < V_31 -> V_52 . V_189 [ V_190 ] ;
}
static int F_74 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_113 ;
int V_151 ;
int V_195 ;
int V_150 ;
int V_145 ;
switch ( V_191 ) {
case V_196 :
V_151 = F_75 ( & V_193 ) ;
V_195 = F_76 ( & V_193 ) ;
V_113 = F_77 ( V_31 , V_151 , V_195 , & V_150 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_44 ( V_31 , V_55 , V_150 , V_151 , V_20 , 0 ) ;
if ( V_113 ) {
F_78 ( V_31 , V_150 , V_151 ) ;
return V_113 ;
}
F_79 ( V_194 , V_150 ) ;
break;
case V_197 :
V_145 = F_75 ( & V_193 ) & 0x7fffff ;
if ( F_69 ( V_31 , V_55 , V_145 ) ) {
V_113 = F_44 ( V_31 , V_55 , V_145 , 1 , V_20 , 0 ) ;
if ( V_113 )
return V_113 ;
}
V_113 = F_62 ( V_31 , V_55 , V_145 , V_171 ,
NULL , 1 ) ;
if ( V_113 )
return V_113 ;
if ( ! F_73 ( V_31 , V_145 ) ) {
V_113 = F_80 ( V_31 , V_145 ) ;
if ( V_113 ) {
F_67 ( V_31 , V_55 , V_20 , V_145 ) ;
return V_113 ;
}
}
F_68 ( V_31 , V_55 , V_20 , V_145 ) ;
break;
default:
V_113 = - V_88 ;
break;
}
return V_113 ;
}
static int F_81 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_113 = - V_88 ;
int V_150 ;
int V_130 ;
if ( V_191 != V_198 )
return V_113 ;
V_130 = F_75 ( & V_193 ) ;
V_150 = F_82 ( V_31 , V_130 ) ;
if ( V_150 == - 1 )
return - V_42 ;
V_113 = F_44 ( V_31 , V_55 , V_150 , 1 , V_24 , V_130 ) ;
if ( V_113 )
F_83 ( V_31 , V_150 , V_130 ) ;
else
F_79 ( V_194 , V_150 ) ;
return V_113 ;
}
static int F_84 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_113 = - V_88 ;
int V_174 ;
int V_121 ;
struct V_133 * V_176 ;
switch ( V_191 ) {
case V_196 :
V_174 = F_85 ( V_31 ) ;
if ( V_174 == - 1 )
break;
V_121 = V_174 & F_22 ( V_31 ) ;
V_113 = F_44 ( V_31 , V_55 , V_121 , 1 , V_23 , V_174 ) ;
if ( V_113 ) {
F_86 ( V_31 , V_174 ) ;
break;
}
F_79 ( V_194 , V_174 ) ;
break;
case V_197 :
V_174 = F_75 ( & V_193 ) ;
V_121 = V_174 & F_22 ( V_31 ) ;
V_113 = F_63 ( V_31 , V_55 , V_121 ,
V_177 , & V_176 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_87 ( V_31 , V_176 -> V_132 ) ;
if ( V_113 ) {
F_67 ( V_31 , V_55 , V_23 , V_121 ) ;
return V_113 ;
}
F_68 ( V_31 , V_55 , V_23 , V_121 ) ;
break;
}
return V_113 ;
}
static int F_88 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_183 ;
int V_113 ;
switch ( V_191 ) {
case V_198 :
V_113 = F_89 ( V_31 , & V_183 ) ;
if ( V_113 )
break;
V_113 = F_44 ( V_31 , V_55 , V_183 , 1 , V_21 , 0 ) ;
if ( V_113 ) {
F_90 ( V_31 , V_183 ) ;
break;
}
F_79 ( V_194 , V_183 ) ;
break;
default:
V_113 = - V_88 ;
}
return V_113 ;
}
static int F_91 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_199 ;
int V_113 ;
switch ( V_191 ) {
case V_198 :
V_113 = F_92 ( V_31 , & V_199 ) ;
if ( V_113 )
break;
V_113 = F_44 ( V_31 , V_55 , V_199 , 1 , V_22 , 0 ) ;
if ( V_113 ) {
F_93 ( V_31 , V_199 ) ;
break;
}
F_79 ( V_194 , V_199 ) ;
break;
default:
V_113 = - V_88 ;
}
return V_113 ;
}
static int F_94 ( struct V_30 * V_31 , int V_55 , T_1 V_200 , int V_62 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_201 * V_11 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
V_11 -> V_200 = V_200 ;
V_11 -> V_62 = ( T_2 ) V_62 ;
F_45 ( & V_11 -> V_156 ,
& V_154 -> V_39 [ V_55 ] . V_44 [ V_25 ] ) ;
return 0 ;
}
static void F_95 ( struct V_30 * V_31 , int V_55 , T_1 V_200 ,
int V_62 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_203 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
struct V_201 * V_11 , * V_204 ;
F_96 (res, tmp, mac_list, list) {
if ( V_11 -> V_200 == V_200 && V_11 -> V_62 == ( T_2 ) V_62 ) {
F_61 ( & V_11 -> V_156 ) ;
F_16 ( V_11 ) ;
break;
}
}
}
static void F_97 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_203 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
struct V_201 * V_11 , * V_204 ;
F_96 (res, tmp, mac_list, list) {
F_61 ( & V_11 -> V_156 ) ;
F_98 ( V_31 , V_11 -> V_62 , V_11 -> V_200 ) ;
F_16 ( V_11 ) ;
}
}
static int F_99 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_113 = - V_88 ;
int V_62 ;
T_1 V_200 ;
if ( V_191 != V_198 )
return V_113 ;
V_62 = F_75 ( V_194 ) ;
V_200 = V_193 ;
V_113 = F_100 ( V_31 , V_62 , V_200 ) ;
if ( V_113 >= 0 ) {
F_79 ( V_194 , V_113 ) ;
V_113 = 0 ;
}
if ( ! V_113 ) {
V_113 = F_94 ( V_31 , V_55 , V_200 , V_62 ) ;
if ( V_113 )
F_98 ( V_31 , V_62 , V_200 ) ;
}
return V_113 ;
}
static int F_101 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
return 0 ;
}
static int F_102 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
T_3 V_174 ;
int V_113 ;
if ( V_191 != V_196 )
return - V_88 ;
V_113 = F_103 ( V_31 , & V_174 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_44 ( V_31 , V_55 , V_174 , 1 , V_27 , 0 ) ;
if ( V_113 )
F_104 ( V_31 , V_174 ) ;
else
F_79 ( V_194 , V_174 ) ;
return V_113 ;
}
static int F_105 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
T_3 V_205 ;
int V_113 ;
if ( V_191 != V_196 )
return - V_88 ;
V_113 = F_106 ( V_31 , & V_205 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_44 ( V_31 , V_55 , V_205 , 1 , V_29 , 0 ) ;
if ( V_113 )
F_107 ( V_31 , V_205 ) ;
else
F_79 ( V_194 , V_205 ) ;
return V_113 ;
}
int F_108 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_210 = V_207 -> V_211 ;
switch ( V_207 -> V_212 ) {
case V_20 :
V_113 = F_74 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_24 :
V_113 = F_81 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_23 :
V_113 = F_84 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_21 :
V_113 = F_88 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_22 :
V_113 = F_91 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_25 :
V_113 = F_99 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_213 :
V_113 = F_101 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_27 :
V_113 = F_102 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_29 :
V_113 = F_105 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
default:
V_113 = - V_88 ;
break;
}
return V_113 ;
}
static int F_109 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 )
{
int V_113 ;
int V_151 ;
int V_150 ;
int V_145 ;
switch ( V_191 ) {
case V_196 :
V_150 = F_75 ( & V_193 ) & 0x7fffff ;
V_151 = F_76 ( & V_193 ) ;
V_113 = F_60 ( V_31 , V_55 , V_150 , V_151 , V_20 , 0 ) ;
if ( V_113 )
break;
F_78 ( V_31 , V_150 , V_151 ) ;
break;
case V_197 :
V_145 = F_75 ( & V_193 ) & 0x7fffff ;
V_113 = F_62 ( V_31 , V_55 , V_145 , V_125 ,
NULL , 0 ) ;
if ( V_113 )
return V_113 ;
if ( ! F_73 ( V_31 , V_145 ) )
F_110 ( V_31 , V_145 ) ;
F_68 ( V_31 , V_55 , V_20 , V_145 ) ;
if ( F_69 ( V_31 , V_55 , V_145 ) )
V_113 = F_60 ( V_31 , V_55 , V_145 , 1 , V_20 , 0 ) ;
break;
default:
V_113 = - V_88 ;
break;
}
return V_113 ;
}
static int F_111 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_113 = - V_88 ;
int V_150 ;
int V_130 ;
if ( V_191 != V_198 )
return V_113 ;
V_150 = F_75 ( & V_193 ) ;
V_130 = F_76 ( & V_193 ) ;
V_113 = F_60 ( V_31 , V_55 , V_150 , 1 , V_24 , V_130 ) ;
if ( ! V_113 )
F_83 ( V_31 , V_150 , V_130 ) ;
return V_113 ;
}
static int F_112 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 )
{
int V_113 = - V_88 ;
int V_174 ;
int V_121 ;
struct V_133 * V_176 ;
switch ( V_191 ) {
case V_196 :
V_174 = F_75 ( & V_193 ) ;
V_121 = V_174 & F_22 ( V_31 ) ;
V_113 = F_24 ( V_31 , V_55 , V_121 , V_23 , & V_176 ) ;
if ( V_113 )
break;
V_174 = V_176 -> V_132 ;
F_31 ( V_31 , V_55 , V_121 , V_23 ) ;
V_113 = F_60 ( V_31 , V_55 , V_121 , 1 , V_23 , 0 ) ;
if ( V_113 )
break;
F_86 ( V_31 , V_174 ) ;
break;
case V_197 :
V_174 = F_75 ( & V_193 ) ;
V_121 = V_174 & F_22 ( V_31 ) ;
V_113 = F_63 ( V_31 , V_55 , V_121 ,
V_134 , & V_176 ) ;
if ( V_113 )
return V_113 ;
F_113 ( V_31 , V_176 -> V_132 ) ;
F_68 ( V_31 , V_55 , V_23 , V_121 ) ;
return V_113 ;
break;
default:
V_113 = - V_88 ;
break;
}
return V_113 ;
}
static int F_114 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_183 ;
int V_113 ;
switch ( V_191 ) {
case V_198 :
V_183 = F_75 ( & V_193 ) ;
V_113 = F_60 ( V_31 , V_55 , V_183 , 1 , V_21 , 0 ) ;
if ( V_113 )
break;
F_90 ( V_31 , V_183 ) ;
break;
default:
V_113 = - V_88 ;
break;
}
return V_113 ;
}
static int F_115 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_199 ;
int V_113 ;
switch ( V_191 ) {
case V_198 :
V_199 = F_75 ( & V_193 ) ;
V_113 = F_60 ( V_31 , V_55 , V_199 , 1 , V_22 , 0 ) ;
if ( V_113 )
break;
F_93 ( V_31 , V_199 ) ;
break;
default:
V_113 = - V_88 ;
break;
}
return V_113 ;
}
static int F_116 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_62 ;
int V_113 = 0 ;
switch ( V_191 ) {
case V_198 :
V_62 = F_75 ( V_194 ) ;
F_95 ( V_31 , V_55 , V_193 , V_62 ) ;
F_98 ( V_31 , V_62 , V_193 ) ;
break;
default:
V_113 = - V_88 ;
break;
}
return V_113 ;
}
static int F_117 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
return 0 ;
}
static int F_118 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_174 ;
int V_113 ;
if ( V_191 != V_196 )
return - V_88 ;
V_174 = F_75 ( & V_193 ) ;
V_113 = F_60 ( V_31 , V_55 , V_174 , 1 , V_27 , 0 ) ;
if ( V_113 )
return V_113 ;
F_104 ( V_31 , V_174 ) ;
return V_113 ;
}
static int F_119 ( struct V_30 * V_31 , int V_55 , int V_191 , int V_192 ,
T_1 V_193 , T_1 * V_194 )
{
int V_205 ;
int V_113 ;
if ( V_191 != V_196 )
return - V_88 ;
V_205 = F_75 ( & V_193 ) ;
V_113 = F_60 ( V_31 , V_55 , V_205 , 1 , V_29 , 0 ) ;
if ( V_113 )
return V_113 ;
F_107 ( V_31 , V_205 ) ;
return V_113 ;
}
int F_120 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 = - V_88 ;
int V_210 = V_207 -> V_211 ;
switch ( V_207 -> V_212 ) {
case V_20 :
V_113 = F_109 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 ) ;
break;
case V_24 :
V_113 = F_111 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_23 :
V_113 = F_112 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 ) ;
break;
case V_21 :
V_113 = F_114 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_22 :
V_113 = F_115 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_25 :
V_113 = F_116 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_213 :
V_113 = F_117 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_27 :
V_113 = F_118 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
break;
case V_29 :
V_113 = F_119 ( V_31 , V_55 , V_207 -> V_211 , V_210 ,
V_207 -> V_193 , & V_207 -> V_194 ) ;
default:
break;
}
return V_113 ;
}
static int F_121 ( struct V_214 * V_176 )
{
return ( F_19 ( V_176 -> V_70 ) >> 9 ) & 1 ;
}
static int F_122 ( struct V_214 * V_176 )
{
return ( int ) F_123 ( V_176 -> V_215 ) & 0xfffffff8 ;
}
static int F_124 ( struct V_214 * V_176 )
{
return F_19 ( V_176 -> V_216 ) ;
}
static T_3 F_125 ( struct V_214 * V_176 )
{
return F_19 ( V_176 -> V_217 ) & 0x00ffffff ;
}
static int F_126 ( struct V_214 * V_176 )
{
return F_19 ( V_176 -> V_217 ) & V_218 ;
}
static int F_127 ( struct V_214 * V_176 )
{
return F_19 ( V_176 -> V_70 ) & V_219 ;
}
static int F_128 ( struct V_214 * V_176 )
{
return F_19 ( V_176 -> V_70 ) & V_220 ;
}
static int F_129 ( struct V_64 * V_79 )
{
return F_19 ( V_79 -> V_221 ) & 0xfffffff8 ;
}
static int F_130 ( struct V_222 * V_223 )
{
return F_19 ( V_223 -> V_221 ) & 0xfffffff8 ;
}
static int F_131 ( struct V_64 * V_79 )
{
int V_224 = ( V_79 -> V_225 & 0x3f ) + 12 ;
int V_226 = ( V_79 -> V_227 >> 3 ) & 0xf ;
int V_228 = V_79 -> V_227 & 7 ;
int V_229 = ( V_79 -> V_230 >> 3 ) & 0xf ;
int V_231 = V_79 -> V_230 & 7 ;
int V_187 = ( F_19 ( V_79 -> V_199 ) >> 24 ) & 1 ;
int V_232 = ( F_19 ( V_79 -> V_70 ) >> 13 ) & 1 ;
int V_233 = ( F_19 ( V_79 -> V_126 ) >> 23 ) & 1 ;
int V_234 ;
int V_235 ;
int V_236 ;
int V_237 ;
int V_238 = ( F_19 ( V_79 -> V_239 ) >> 6 ) & 0x3f ;
V_234 = 1 << ( V_226 + V_228 + 4 ) ;
V_235 = ( V_187 | V_232 | V_233 ) ? 0 : ( 1 << ( V_229 + V_231 + 4 ) ) ;
V_237 = V_234 + V_235 ;
V_236 =
F_132 ( ( V_237 + ( V_238 << 6 ) ) >>
V_224 ) ;
return V_236 ;
}
static int F_133 ( struct V_30 * V_31 , int V_55 , int V_240 ,
int V_241 , struct V_131 * V_242 )
{
int V_243 = V_242 -> V_124 . V_7 ;
int V_244 = ( 1 << V_242 -> V_130 ) ;
if ( V_240 < V_243 || V_240 + V_241 > V_243 + V_244 )
return - V_118 ;
return 0 ;
}
int F_134 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_174 = V_207 -> V_212 ;
struct V_131 * V_242 ;
struct V_133 * V_176 ;
int V_245 = F_122 ( V_57 -> V_59 ) / V_31 -> V_52 . V_246 ;
int V_247 ;
int V_121 ;
T_3 V_248 ;
int V_249 ;
V_121 = V_174 & F_22 ( V_31 ) ;
V_113 = F_63 ( V_31 , V_55 , V_121 , V_178 , & V_176 ) ;
if ( V_113 )
return V_113 ;
if ( ! F_128 ( V_57 -> V_59 ) ) {
V_113 = - V_118 ;
goto V_250;
}
V_248 = F_125 ( V_57 -> V_59 ) ;
V_249 = ( V_248 >> 17 ) & 0x7f ;
if ( V_249 != 0 && V_249 != V_55 ) {
V_113 = - V_118 ;
goto V_250;
}
if ( F_126 ( V_57 -> V_59 ) ) {
if ( F_127 ( V_57 -> V_59 ) ) {
V_113 = - V_118 ;
goto V_250;
}
if ( ! F_128 ( V_57 -> V_59 ) ) {
V_113 = - V_118 ;
goto V_250;
}
}
V_247 = F_121 ( V_57 -> V_59 ) ;
if ( ! V_247 ) {
V_113 = F_24 ( V_31 , V_55 , V_245 , V_24 , & V_242 ) ;
if ( V_113 )
goto V_250;
V_113 = F_133 ( V_31 , V_55 , V_245 ,
F_124 ( V_57 -> V_59 ) , V_242 ) ;
if ( V_113 )
goto V_251;
V_176 -> V_242 = V_242 ;
}
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_251;
if ( ! V_247 ) {
F_136 ( & V_242 -> V_129 ) ;
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
}
F_68 ( V_31 , V_55 , V_23 , V_121 ) ;
return 0 ;
V_251:
if ( ! V_247 )
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
V_250:
F_67 ( V_31 , V_55 , V_23 , V_121 ) ;
return V_113 ;
}
int F_137 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_174 = V_207 -> V_212 ;
struct V_133 * V_176 ;
int V_121 ;
V_121 = V_174 & F_22 ( V_31 ) ;
V_113 = F_63 ( V_31 , V_55 , V_121 , V_177 , & V_176 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_250;
if ( V_176 -> V_242 )
F_138 ( & V_176 -> V_242 -> V_129 ) ;
F_68 ( V_31 , V_55 , V_23 , V_121 ) ;
return 0 ;
V_250:
F_67 ( V_31 , V_55 , V_23 , V_121 ) ;
return V_113 ;
}
int F_139 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_174 = V_207 -> V_212 ;
struct V_133 * V_176 ;
int V_121 ;
V_121 = V_174 & F_22 ( V_31 ) ;
V_113 = F_24 ( V_31 , V_55 , V_121 , V_23 , & V_176 ) ;
if ( V_113 )
return V_113 ;
if ( V_176 -> V_124 . V_119 != V_178 ) {
V_113 = - V_116 ;
goto V_167;
}
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
V_167:
F_31 ( V_31 , V_55 , V_121 , V_23 ) ;
return V_113 ;
}
static int F_140 ( struct V_64 * V_79 )
{
return F_19 ( V_79 -> V_252 ) & 0xffffff ;
}
static int F_141 ( struct V_64 * V_79 )
{
return F_19 ( V_79 -> V_253 ) & 0xffffff ;
}
static T_3 F_142 ( struct V_64 * V_79 )
{
return F_19 ( V_79 -> V_199 ) & 0x1ffffff ;
}
static void F_143 ( struct V_30 * V_31 , struct V_206 * V_207 ,
struct V_64 * V_254 )
{
T_3 V_145 = V_207 -> V_212 & 0xffffff ;
T_3 V_255 = 0 ;
if ( F_144 ( V_31 , V_145 , & V_255 ) )
return;
V_254 -> V_255 = F_21 ( V_255 ) ;
}
int F_145 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_145 = V_207 -> V_212 & 0x7fffff ;
struct V_131 * V_242 ;
struct V_122 * V_169 ;
struct V_64 * V_79 = V_57 -> V_59 + 8 ;
int V_245 = F_129 ( V_79 ) / V_31 -> V_52 . V_246 ;
int V_256 = F_131 ( V_79 ) ;
struct V_137 * V_257 ;
struct V_137 * V_258 ;
int V_259 = F_140 ( V_79 ) ;
int V_260 = F_141 ( V_79 ) ;
T_3 V_199 = F_142 ( V_79 ) & 0xffffff ;
int V_261 = ( F_142 ( V_79 ) >> 24 ) & 1 ;
struct V_139 * V_187 ;
int V_126 = F_19 ( V_79 -> V_126 ) & 0xffffff ;
V_113 = F_62 ( V_31 , V_55 , V_145 , V_172 , & V_169 , 0 ) ;
if ( V_113 )
return V_113 ;
V_169 -> V_126 = V_126 ;
V_113 = F_24 ( V_31 , V_55 , V_245 , V_24 , & V_242 ) ;
if ( V_113 )
goto V_250;
V_113 = F_133 ( V_31 , V_55 , V_245 , V_256 , V_242 ) ;
if ( V_113 )
goto V_262;
V_113 = F_24 ( V_31 , V_55 , V_259 , V_21 , & V_257 ) ;
if ( V_113 )
goto V_262;
if ( V_260 != V_259 ) {
V_113 = F_24 ( V_31 , V_55 , V_260 , V_21 , & V_258 ) ;
if ( V_113 )
goto V_263;
} else
V_258 = V_257 ;
if ( V_261 ) {
V_113 = F_24 ( V_31 , V_55 , V_199 , V_22 , & V_187 ) ;
if ( V_113 )
goto V_264;
}
F_143 ( V_31 , V_207 , V_79 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_265;
F_136 ( & V_242 -> V_129 ) ;
V_169 -> V_242 = V_242 ;
F_136 ( & V_257 -> V_129 ) ;
V_169 -> V_257 = V_257 ;
F_136 ( & V_258 -> V_129 ) ;
V_169 -> V_258 = V_258 ;
if ( V_260 != V_259 )
F_31 ( V_31 , V_55 , V_260 , V_21 ) ;
if ( V_261 ) {
F_136 ( & V_187 -> V_129 ) ;
F_31 ( V_31 , V_55 , V_199 , V_22 ) ;
V_169 -> V_187 = V_187 ;
}
F_31 ( V_31 , V_55 , V_259 , V_21 ) ;
F_31 ( V_31 , V_55 , V_245 , V_24 ) ;
F_68 ( V_31 , V_55 , V_20 , V_145 ) ;
return 0 ;
V_265:
if ( V_261 )
F_31 ( V_31 , V_55 , V_199 , V_22 ) ;
V_264:
if ( V_260 != V_259 )
F_31 ( V_31 , V_55 , V_260 , V_21 ) ;
V_263:
F_31 ( V_31 , V_55 , V_259 , V_21 ) ;
V_262:
F_31 ( V_31 , V_55 , V_245 , V_24 ) ;
V_250:
F_67 ( V_31 , V_55 , V_20 , V_145 ) ;
return V_113 ;
}
static int F_146 ( struct V_266 * V_267 )
{
return F_19 ( V_267 -> V_221 ) & 0xfffffff8 ;
}
static int F_147 ( struct V_266 * V_267 )
{
int V_268 = V_267 -> V_268 & 0x1f ;
int V_224 = ( V_267 -> V_225 & 0x3f ) + 12 ;
if ( V_268 + 5 < V_224 )
return 1 ;
return 1 << ( V_268 + 5 - V_224 ) ;
}
static int F_148 ( struct V_269 * V_270 )
{
return F_19 ( V_270 -> V_221 ) & 0xfffffff8 ;
}
static int F_149 ( struct V_269 * V_270 )
{
int V_271 = ( F_19 ( V_270 -> V_272 ) >> 24 ) & 0x1f ;
int V_224 = ( V_270 -> V_225 & 0x3f ) + 12 ;
if ( V_271 + 5 < V_224 )
return 1 ;
return 1 << ( V_271 + 5 - V_224 ) ;
}
int F_150 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_273 = V_207 -> V_212 ;
int V_7 = ( V_55 << 8 ) | V_273 ;
struct V_266 * V_267 = V_57 -> V_59 ;
int V_245 = F_146 ( V_267 ) / V_31 -> V_52 . V_246 ;
int V_256 = F_147 ( V_267 ) ;
struct V_135 * V_180 ;
struct V_131 * V_242 ;
V_113 = F_44 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_64 ( V_31 , V_55 , V_7 , V_182 , & V_180 ) ;
if ( V_113 )
goto V_274;
V_113 = F_24 ( V_31 , V_55 , V_245 , V_24 , & V_242 ) ;
if ( V_113 )
goto V_275;
V_113 = F_133 ( V_31 , V_55 , V_245 , V_256 , V_242 ) ;
if ( V_113 )
goto V_276;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_276;
F_136 ( & V_242 -> V_129 ) ;
V_180 -> V_242 = V_242 ;
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
F_68 ( V_31 , V_55 , V_26 , V_7 ) ;
return 0 ;
V_276:
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
V_275:
F_67 ( V_31 , V_55 , V_26 , V_7 ) ;
V_274:
F_60 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
return V_113 ;
}
static int F_151 ( struct V_30 * V_31 , int V_55 , int V_240 ,
int V_277 , struct V_131 * * V_11 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_131 * V_242 ;
int V_113 = - V_88 ;
F_25 ( F_26 ( V_31 ) ) ;
F_152 (mtt, &tracker->slave_list[slave].res_list[RES_MTT],
com.list) {
if ( ! F_133 ( V_31 , V_55 , V_240 , V_277 , V_242 ) ) {
* V_11 = V_242 ;
V_242 -> V_124 . V_119 = V_242 -> V_124 . V_2 ;
V_242 -> V_124 . V_2 = V_3 ;
V_113 = 0 ;
break;
}
}
F_27 ( F_26 ( V_31 ) ) ;
return V_113 ;
}
static int F_153 ( struct V_30 * V_31 ,
struct V_56 * V_57 ,
enum V_278 V_279 , T_2 V_55 )
{
T_3 V_82 ;
struct V_64 * V_65 ;
enum V_66 V_67 ;
V_65 = V_57 -> V_59 + 8 ;
V_82 = ( F_19 ( V_65 -> V_70 ) >> 16 ) & 0xff ;
V_67 = F_19 ( * ( V_68 * ) V_57 -> V_59 ) ;
switch ( V_82 ) {
case V_74 :
case V_75 :
switch ( V_279 ) {
case V_280 :
case V_281 :
case V_282 :
case V_283 :
case V_284 :
if ( V_55 != F_154 ( V_31 ) )
if ( V_67 & V_76 )
if ( V_65 -> V_72 . V_73 )
return - V_88 ;
if ( V_67 & V_77 )
if ( V_65 -> V_78 . V_73 )
return - V_88 ;
break;
default:
break;
}
break;
default:
break;
}
return 0 ;
}
int F_155 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
struct V_285 V_242 ;
T_4 * V_286 = V_57 -> V_59 ;
T_1 * V_287 = ( T_1 * ) V_286 ;
int V_34 ;
struct V_131 * V_288 = NULL ;
int V_240 = F_123 ( V_286 [ 0 ] ) ;
int V_289 = V_207 -> V_212 ;
int V_113 ;
V_113 = F_151 ( V_31 , V_55 , V_240 , V_289 , & V_288 ) ;
if ( V_113 )
return V_113 ;
V_242 . V_290 = 0 ;
V_242 . V_130 = 0 ;
V_242 . V_224 = 0 ;
for ( V_34 = 0 ; V_34 < V_289 ; ++ V_34 )
V_287 [ V_34 + 2 ] = ( F_123 ( V_286 [ V_34 + 2 ] ) & ~ 1ULL ) ;
V_113 = F_156 ( V_31 , & V_242 , F_123 ( V_286 [ 0 ] ) , V_289 ,
( ( T_1 * ) V_286 + 2 ) ) ;
if ( V_288 )
F_31 ( V_31 , V_55 , V_288 -> V_124 . V_7 , V_24 ) ;
return V_113 ;
}
int F_157 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_273 = V_207 -> V_212 ;
int V_7 = V_273 | ( V_55 << 8 ) ;
struct V_135 * V_180 ;
int V_113 ;
V_113 = F_64 ( V_31 , V_55 , V_7 , V_136 , & V_180 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_24 ( V_31 , V_55 , V_180 -> V_242 -> V_124 . V_7 , V_24 , NULL ) ;
if ( V_113 )
goto V_250;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_251;
F_138 ( & V_180 -> V_242 -> V_129 ) ;
F_31 ( V_31 , V_55 , V_180 -> V_242 -> V_124 . V_7 , V_24 ) ;
F_68 ( V_31 , V_55 , V_26 , V_7 ) ;
F_60 ( V_31 , V_55 , V_7 , 1 , V_26 , 0 ) ;
return 0 ;
V_251:
F_31 ( V_31 , V_55 , V_180 -> V_242 -> V_124 . V_7 , V_24 ) ;
V_250:
F_67 ( V_31 , V_55 , V_26 , V_7 ) ;
return V_113 ;
}
int F_158 ( struct V_30 * V_31 , int V_55 , struct V_291 * V_292 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_293 * V_294 ;
struct V_56 * V_295 ;
T_3 V_212 = 0 ;
int V_113 ;
int V_7 ;
struct V_135 * V_296 ;
if ( ! V_33 -> V_36 . V_37 . V_297 )
return - V_88 ;
V_294 = & V_33 -> V_36 . V_37 . V_297 [ V_55 ] . V_294 [ V_292 -> type ] ;
if ( V_294 -> V_273 < 0 )
return 0 ;
F_159 ( & V_33 -> V_36 . V_37 . V_298 [ V_55 ] ) ;
V_7 = ( V_55 << 8 ) | V_294 -> V_273 ;
V_113 = F_24 ( V_31 , V_55 , V_7 , V_26 , & V_296 ) ;
if ( V_113 )
goto V_299;
if ( V_296 -> V_124 . V_119 != V_182 ) {
V_113 = - V_88 ;
goto V_300;
}
V_295 = F_160 ( V_31 ) ;
if ( F_161 ( V_295 ) ) {
V_113 = F_162 ( V_295 ) ;
goto V_300;
}
if ( V_292 -> type == V_301 ) {
++ V_294 -> V_302 ;
V_292 -> V_303 . V_192 . V_302 = F_163 ( V_294 -> V_302 ) ;
}
memcpy ( V_295 -> V_59 , ( T_2 * ) V_292 , 28 ) ;
V_212 = ( V_55 & 0xff ) | ( ( V_294 -> V_273 & 0xff ) << 16 ) ;
V_113 = F_164 ( V_31 , V_295 -> V_304 , V_212 , 0 ,
V_305 , V_306 ,
V_307 ) ;
F_31 ( V_31 , V_55 , V_7 , V_26 ) ;
F_165 ( & V_33 -> V_36 . V_37 . V_298 [ V_55 ] ) ;
F_166 ( V_31 , V_295 ) ;
return V_113 ;
V_300:
F_31 ( V_31 , V_55 , V_7 , V_26 ) ;
V_299:
F_165 ( & V_33 -> V_36 . V_37 . V_298 [ V_55 ] ) ;
return V_113 ;
}
int F_167 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_273 = V_207 -> V_212 ;
int V_7 = V_273 | ( V_55 << 8 ) ;
struct V_135 * V_180 ;
int V_113 ;
V_113 = F_24 ( V_31 , V_55 , V_7 , V_26 , & V_180 ) ;
if ( V_113 )
return V_113 ;
if ( V_180 -> V_124 . V_119 != V_182 ) {
V_113 = - V_88 ;
goto V_251;
}
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
V_251:
F_31 ( V_31 , V_55 , V_7 , V_26 ) ;
return V_113 ;
}
int F_168 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_183 = V_207 -> V_212 ;
struct V_269 * V_270 = V_57 -> V_59 ;
int V_245 = F_148 ( V_270 ) / V_31 -> V_52 . V_246 ;
struct V_137 * V_185 ;
struct V_131 * V_242 ;
V_113 = F_65 ( V_31 , V_55 , V_183 , V_186 , & V_185 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_24 ( V_31 , V_55 , V_245 , V_24 , & V_242 ) ;
if ( V_113 )
goto V_275;
V_113 = F_133 ( V_31 , V_55 , V_245 , F_149 ( V_270 ) , V_242 ) ;
if ( V_113 )
goto V_276;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_276;
F_136 ( & V_242 -> V_129 ) ;
V_185 -> V_242 = V_242 ;
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
F_68 ( V_31 , V_55 , V_21 , V_183 ) ;
return 0 ;
V_276:
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
V_275:
F_67 ( V_31 , V_55 , V_21 , V_183 ) ;
return V_113 ;
}
int F_169 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_183 = V_207 -> V_212 ;
struct V_137 * V_185 ;
V_113 = F_65 ( V_31 , V_55 , V_183 , V_138 , & V_185 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_275;
F_138 ( & V_185 -> V_242 -> V_129 ) ;
F_68 ( V_31 , V_55 , V_21 , V_183 ) ;
return 0 ;
V_275:
F_67 ( V_31 , V_55 , V_21 , V_183 ) ;
return V_113 ;
}
int F_170 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_183 = V_207 -> V_212 ;
struct V_137 * V_185 ;
int V_113 ;
V_113 = F_24 ( V_31 , V_55 , V_183 , V_21 , & V_185 ) ;
if ( V_113 )
return V_113 ;
if ( V_185 -> V_124 . V_119 != V_186 )
goto V_251;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
V_251:
F_31 ( V_31 , V_55 , V_183 , V_21 ) ;
return V_113 ;
}
static int F_171 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 ,
struct V_137 * V_185 )
{
int V_113 ;
struct V_131 * V_308 ;
struct V_131 * V_242 ;
struct V_269 * V_270 = V_57 -> V_59 ;
int V_245 = F_148 ( V_270 ) / V_31 -> V_52 . V_246 ;
V_113 = F_24 ( V_31 , V_55 , V_185 -> V_242 -> V_124 . V_7 , V_24 , & V_308 ) ;
if ( V_113 )
return V_113 ;
if ( V_308 != V_185 -> V_242 ) {
V_113 = - V_88 ;
goto V_251;
}
V_113 = F_24 ( V_31 , V_55 , V_245 , V_24 , & V_242 ) ;
if ( V_113 )
goto V_251;
V_113 = F_133 ( V_31 , V_55 , V_245 , F_149 ( V_270 ) , V_242 ) ;
if ( V_113 )
goto V_309;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_309;
F_138 ( & V_308 -> V_129 ) ;
F_31 ( V_31 , V_55 , V_308 -> V_124 . V_7 , V_24 ) ;
F_136 ( & V_242 -> V_129 ) ;
V_185 -> V_242 = V_242 ;
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
return 0 ;
V_309:
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
V_251:
F_31 ( V_31 , V_55 , V_308 -> V_124 . V_7 , V_24 ) ;
return V_113 ;
}
int F_172 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_183 = V_207 -> V_212 ;
struct V_137 * V_185 ;
int V_113 ;
V_113 = F_24 ( V_31 , V_55 , V_183 , V_21 , & V_185 ) ;
if ( V_113 )
return V_113 ;
if ( V_185 -> V_124 . V_119 != V_186 )
goto V_251;
if ( V_207 -> V_211 == 0 ) {
V_113 = F_171 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 , V_185 ) ;
goto V_251;
}
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
V_251:
F_31 ( V_31 , V_55 , V_183 , V_21 ) ;
return V_113 ;
}
static int F_173 ( struct V_222 * V_223 )
{
int V_310 = ( F_19 ( V_223 -> V_311 ) >> 24 ) & 0xf ;
int V_231 = V_223 -> V_312 & 7 ;
int V_224 = ( V_223 -> V_225 & 0x3f ) + 12 ;
if ( V_310 + V_231 + 4 < V_224 )
return 1 ;
return 1 << ( V_310 + V_231 + 4 - V_224 ) ;
}
int F_174 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_199 = V_207 -> V_212 ;
struct V_131 * V_242 ;
struct V_139 * V_187 ;
struct V_222 * V_223 = V_57 -> V_59 ;
int V_245 = F_130 ( V_223 ) / V_31 -> V_52 . V_246 ;
if ( V_199 != ( F_19 ( V_223 -> V_311 ) & 0xffffff ) )
return - V_88 ;
V_113 = F_66 ( V_31 , V_55 , V_199 , V_188 , & V_187 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_24 ( V_31 , V_55 , V_245 , V_24 , & V_242 ) ;
if ( V_113 )
goto V_250;
V_113 = F_133 ( V_31 , V_55 , V_245 , F_173 ( V_223 ) ,
V_242 ) ;
if ( V_113 )
goto V_262;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_262;
F_136 ( & V_242 -> V_129 ) ;
V_187 -> V_242 = V_242 ;
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
F_68 ( V_31 , V_55 , V_22 , V_199 ) ;
return 0 ;
V_262:
F_31 ( V_31 , V_55 , V_242 -> V_124 . V_7 , V_24 ) ;
V_250:
F_67 ( V_31 , V_55 , V_22 , V_199 ) ;
return V_113 ;
}
int F_175 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_199 = V_207 -> V_212 ;
struct V_139 * V_187 ;
V_113 = F_66 ( V_31 , V_55 , V_199 , V_140 , & V_187 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_250;
F_138 ( & V_187 -> V_242 -> V_129 ) ;
if ( V_187 -> V_185 )
F_138 ( & V_187 -> V_185 -> V_129 ) ;
F_68 ( V_31 , V_55 , V_22 , V_199 ) ;
return 0 ;
V_250:
F_67 ( V_31 , V_55 , V_22 , V_199 ) ;
return V_113 ;
}
int F_176 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_199 = V_207 -> V_212 ;
struct V_139 * V_187 ;
V_113 = F_24 ( V_31 , V_55 , V_199 , V_22 , & V_187 ) ;
if ( V_113 )
return V_113 ;
if ( V_187 -> V_124 . V_119 != V_188 ) {
V_113 = - V_116 ;
goto V_167;
}
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
V_167:
F_31 ( V_31 , V_55 , V_199 , V_22 ) ;
return V_113 ;
}
int F_177 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_199 = V_207 -> V_212 ;
struct V_139 * V_187 ;
V_113 = F_24 ( V_31 , V_55 , V_199 , V_22 , & V_187 ) ;
if ( V_113 )
return V_113 ;
if ( V_187 -> V_124 . V_119 != V_188 ) {
V_113 = - V_116 ;
goto V_167;
}
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
V_167:
F_31 ( V_31 , V_55 , V_199 , V_22 ) ;
return V_113 ;
}
int F_178 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_145 = V_207 -> V_212 & 0x7fffff ;
struct V_122 * V_169 ;
V_113 = F_24 ( V_31 , V_55 , V_145 , V_20 , & V_169 ) ;
if ( V_113 )
return V_113 ;
if ( V_169 -> V_124 . V_119 != V_172 ) {
V_113 = - V_116 ;
goto V_167;
}
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
V_167:
F_31 ( V_31 , V_55 , V_145 , V_20 ) ;
return V_113 ;
}
int F_179 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
struct V_64 * V_254 = V_57 -> V_59 + 8 ;
F_143 ( V_31 , V_207 , V_254 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_178 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
}
int F_180 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
struct V_64 * V_79 = V_57 -> V_59 + 8 ;
V_113 = F_153 ( V_31 , V_57 , V_280 , V_55 ) ;
if ( V_113 )
return V_113 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_143 ( V_31 , V_207 , V_79 ) ;
V_113 = F_20 ( V_31 , V_57 , V_55 ) ;
if ( V_113 )
return V_113 ;
return F_178 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
}
int F_181 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
struct V_64 * V_254 = V_57 -> V_59 + 8 ;
V_113 = F_153 ( V_31 , V_57 , V_281 , V_55 ) ;
if ( V_113 )
return V_113 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_143 ( V_31 , V_207 , V_254 ) ;
return F_178 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
}
int F_182 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
struct V_64 * V_254 = V_57 -> V_59 + 8 ;
V_113 = F_153 ( V_31 , V_57 , V_282 , V_55 ) ;
if ( V_113 )
return V_113 ;
F_17 ( V_31 , V_55 , V_57 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_143 ( V_31 , V_207 , V_254 ) ;
return F_178 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
}
int F_183 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
struct V_64 * V_254 = V_57 -> V_59 + 8 ;
F_143 ( V_31 , V_207 , V_254 ) ;
return F_178 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
}
int F_184 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
struct V_64 * V_254 = V_57 -> V_59 + 8 ;
V_113 = F_153 ( V_31 , V_57 , V_283 , V_55 ) ;
if ( V_113 )
return V_113 ;
F_143 ( V_31 , V_207 , V_254 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_178 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
}
int F_185 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
struct V_64 * V_254 = V_57 -> V_59 + 8 ;
V_113 = F_153 ( V_31 , V_57 , V_284 , V_55 ) ;
if ( V_113 )
return V_113 ;
F_143 ( V_31 , V_207 , V_254 ) ;
F_18 ( V_31 , V_57 , ( T_2 ) V_55 ) ;
F_17 ( V_31 , V_55 , V_57 ) ;
return F_178 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
}
int F_186 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_145 = V_207 -> V_212 & 0x7fffff ;
struct V_122 * V_169 ;
V_113 = F_62 ( V_31 , V_55 , V_145 , V_171 , & V_169 , 0 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
if ( V_113 )
goto V_250;
F_138 ( & V_169 -> V_242 -> V_129 ) ;
F_138 ( & V_169 -> V_257 -> V_129 ) ;
F_138 ( & V_169 -> V_258 -> V_129 ) ;
if ( V_169 -> V_187 )
F_138 ( & V_169 -> V_187 -> V_129 ) ;
F_68 ( V_31 , V_55 , V_20 , V_145 ) ;
return 0 ;
V_250:
F_67 ( V_31 , V_55 , V_20 , V_145 ) ;
return V_113 ;
}
static struct V_313 * F_187 ( struct V_30 * V_31 , int V_55 ,
struct V_122 * V_314 , T_2 * V_315 )
{
struct V_313 * V_11 ;
F_152 (res, &rqp->mcg_list, list) {
if ( ! memcmp ( V_11 -> V_315 , V_315 , 16 ) )
return V_11 ;
}
return NULL ;
}
static int F_188 ( struct V_30 * V_31 , int V_55 , struct V_122 * V_314 ,
T_2 * V_315 , enum V_316 V_317 ,
enum V_318 V_319 , T_1 V_320 )
{
struct V_313 * V_11 ;
int V_113 ;
V_11 = F_9 ( sizeof *V_11 , V_41 ) ;
if ( ! V_11 )
return - V_42 ;
F_25 ( & V_314 -> V_128 ) ;
if ( F_187 ( V_31 , V_55 , V_314 , V_315 ) ) {
F_16 ( V_11 ) ;
V_113 = - V_17 ;
} else {
memcpy ( V_11 -> V_315 , V_315 , 16 ) ;
V_11 -> V_317 = V_317 ;
V_11 -> V_319 = V_319 ;
V_11 -> V_320 = V_320 ;
F_45 ( & V_11 -> V_156 , & V_314 -> V_127 ) ;
V_113 = 0 ;
}
F_27 ( & V_314 -> V_128 ) ;
return V_113 ;
}
static int F_189 ( struct V_30 * V_31 , int V_55 , struct V_122 * V_314 ,
T_2 * V_315 , enum V_316 V_317 ,
enum V_318 V_319 , T_1 * V_320 )
{
struct V_313 * V_11 ;
int V_113 ;
F_25 ( & V_314 -> V_128 ) ;
V_11 = F_187 ( V_31 , V_55 , V_314 , V_315 ) ;
if ( ! V_11 || V_11 -> V_317 != V_317 || V_11 -> V_319 != V_319 )
V_113 = - V_88 ;
else {
* V_320 = V_11 -> V_320 ;
F_61 ( & V_11 -> V_156 ) ;
F_16 ( V_11 ) ;
V_113 = 0 ;
}
F_27 ( & V_314 -> V_128 ) ;
return V_113 ;
}
static int F_190 ( struct V_30 * V_31 , struct V_321 * V_169 , T_2 V_315 [ 16 ] ,
int V_322 , enum V_316 V_317 ,
enum V_318 type , T_1 * V_320 )
{
switch ( V_31 -> V_52 . V_323 ) {
case V_324 :
return F_191 ( V_31 , V_169 , V_315 , V_315 [ 5 ] ,
V_322 , V_317 ,
V_320 ) ;
case V_325 :
return F_192 ( V_31 , V_169 , V_315 ,
V_322 , V_317 , type ) ;
default:
return - V_88 ;
}
}
static int F_193 ( struct V_30 * V_31 , struct V_321 * V_169 , T_2 V_315 [ 16 ] ,
enum V_316 V_317 , enum V_318 type ,
T_1 V_320 )
{
switch ( V_31 -> V_52 . V_323 ) {
case V_324 :
return F_194 ( V_31 , V_320 ) ;
case V_325 :
return F_195 ( V_31 , V_169 , V_315 , V_317 , type ) ;
default:
return - V_88 ;
}
}
int F_196 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
struct V_321 V_169 ;
T_2 * V_315 = V_57 -> V_59 ;
enum V_316 V_317 = ( V_207 -> V_212 >> 28 ) & 0x7 ;
int V_113 ;
int V_145 ;
struct V_122 * V_314 ;
T_1 V_320 = 0 ;
int V_326 = V_207 -> V_211 ;
int V_322 = V_207 -> V_212 >> 31 ;
T_2 V_327 = 2 ;
enum V_318 type = ( V_315 [ 7 ] & V_327 ) >> 1 ;
V_145 = V_207 -> V_212 & 0xffffff ;
V_113 = F_24 ( V_31 , V_55 , V_145 , V_20 , & V_314 ) ;
if ( V_113 )
return V_113 ;
V_169 . V_145 = V_145 ;
if ( V_326 ) {
V_113 = F_190 ( V_31 , & V_169 , V_315 , V_322 , V_317 ,
type , & V_320 ) ;
if ( V_113 ) {
F_50 ( L_21 , V_145 ) ;
goto V_251;
}
V_113 = F_188 ( V_31 , V_55 , V_314 , V_315 , V_317 , type , V_320 ) ;
if ( V_113 )
goto V_328;
} else {
V_113 = F_189 ( V_31 , V_55 , V_314 , V_315 , V_317 , type , & V_320 ) ;
if ( V_113 )
goto V_251;
V_113 = F_193 ( V_31 , & V_169 , V_315 , V_317 , type , V_320 ) ;
if ( V_113 )
F_50 ( L_22 ,
V_145 , V_320 ) ;
}
F_31 ( V_31 , V_55 , V_145 , V_20 ) ;
return V_113 ;
V_328:
F_193 ( V_31 , & V_169 , V_315 , V_317 , type , V_320 ) ;
V_251:
F_31 ( V_31 , V_55 , V_145 , V_20 ) ;
return V_113 ;
}
static int F_197 ( int V_55 , struct V_329 * V_330 ,
struct V_202 * V_331 )
{
struct V_201 * V_11 , * V_204 ;
T_4 V_332 ;
if ( ! F_198 ( V_330 -> V_333 . V_334 ) &&
! F_199 ( V_330 -> V_333 . V_334 ) ) {
F_96 (res, tmp, rlist, list) {
V_332 = F_200 ( V_11 -> V_200 << 16 ) ;
if ( ! memcmp ( & V_332 , V_330 -> V_333 . V_334 , V_335 ) )
return 0 ;
}
F_50 ( L_23 ,
V_330 -> V_333 . V_334 , V_55 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_201 ( struct V_30 * V_31 , int V_55 ,
struct V_56 * V_57 ,
struct V_202 * V_331 , int V_336 )
{
struct V_201 * V_11 , * V_204 ;
T_2 V_62 ;
struct V_337 * V_338 ;
struct V_339 * V_330 ;
struct V_340 * V_341 ;
struct V_342 * V_343 ;
T_4 V_332 = 0 ;
T_4 V_344 = F_200 ( V_345 << 16 ) ;
V_338 = (struct V_337 * ) V_57 -> V_59 ;
V_62 = V_338 -> V_62 ;
V_330 = (struct V_339 * ) ( V_338 + 1 ) ;
switch ( V_336 ) {
case V_346 :
V_341 =
(struct V_340 * ) ( V_330 + 1 ) ;
memmove ( V_341 , V_330 ,
sizeof( * V_341 ) + sizeof( * V_343 ) ) ;
break;
case V_347 :
case V_348 :
V_343 = (struct V_342 * )
( V_330 + 1 ) ;
memmove ( V_343 , V_330 , sizeof( * V_343 ) ) ;
break;
default:
return - V_88 ;
}
F_96 (res, tmp, rlist, list) {
if ( V_62 == V_11 -> V_62 ) {
V_332 = F_200 ( V_11 -> V_200 << 16 ) ;
break;
}
}
if ( ! V_332 ) {
F_50 ( L_24 ,
V_62 ) ;
return - V_88 ;
}
memset ( V_330 , 0 , sizeof( * V_330 ) ) ;
V_330 -> V_241 = sizeof( * V_330 ) >> 2 ;
V_330 -> V_121 = F_163 ( V_349 [ V_350 ] ) ;
memcpy ( V_330 -> V_334 , & V_332 , V_335 ) ;
memcpy ( V_330 -> V_351 , & V_344 , V_335 ) ;
return 0 ;
}
int F_202 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_331 = & V_154 -> V_39 [ V_55 ] . V_44 [ V_25 ] ;
int V_113 ;
int V_145 ;
struct V_122 * V_314 ;
struct V_337 * V_338 ;
struct V_329 * V_352 ;
int V_336 ;
if ( V_31 -> V_52 . V_323 !=
V_324 )
return - V_353 ;
V_338 = (struct V_337 * ) V_57 -> V_59 ;
V_145 = F_19 ( V_338 -> V_145 ) & 0xffffff ;
V_113 = F_24 ( V_31 , V_55 , V_145 , V_20 , & V_314 ) ;
if ( V_113 ) {
F_50 ( L_25 , V_145 ) ;
return V_113 ;
}
V_352 = (struct V_329 * ) ( V_338 + 1 ) ;
V_336 = F_203 ( F_204 ( V_352 -> V_121 ) ) ;
switch ( V_336 ) {
case V_350 :
if ( F_197 ( V_55 , V_352 , V_331 ) ) {
V_113 = - V_88 ;
goto V_354;
}
break;
case V_355 :
break;
case V_346 :
case V_347 :
case V_348 :
F_205 ( L_26 ) ;
if ( F_201 ( V_31 , V_55 , V_57 , V_331 , V_336 ) ) {
V_113 = - V_88 ;
goto V_354;
}
V_207 -> V_212 +=
sizeof( struct V_339 ) >> 2 ;
break;
default:
F_50 ( L_27 ) ;
V_113 = - V_88 ;
goto V_354;
}
V_113 = F_206 ( V_31 , V_57 -> V_304 , & V_207 -> V_194 ,
V_207 -> V_212 , 0 ,
V_356 , V_357 ,
V_307 ) ;
if ( V_113 )
goto V_354;
V_113 = F_44 ( V_31 , V_55 , V_207 -> V_194 , 1 , V_28 , V_145 ) ;
if ( V_113 ) {
F_207 ( V_31 , L_28 ) ;
F_164 ( V_31 , V_207 -> V_194 , 0 , 0 ,
V_358 , V_357 ,
V_307 ) ;
goto V_354;
}
F_136 ( & V_314 -> V_129 ) ;
V_354:
F_31 ( V_31 , V_55 , V_145 , V_20 ) ;
return V_113 ;
}
int F_208 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
struct V_122 * V_314 ;
struct V_146 * V_359 ;
if ( V_31 -> V_52 . V_323 !=
V_324 )
return - V_353 ;
V_113 = F_24 ( V_31 , V_55 , V_207 -> V_193 , V_28 , & V_359 ) ;
if ( V_113 )
return V_113 ;
F_31 ( V_31 , V_55 , V_207 -> V_193 , V_28 ) ;
V_113 = F_24 ( V_31 , V_55 , V_359 -> V_145 , V_20 , & V_314 ) ;
if ( V_113 )
return V_113 ;
V_113 = F_60 ( V_31 , V_55 , V_207 -> V_193 , 1 , V_28 , 0 ) ;
if ( V_113 ) {
F_207 ( V_31 , L_29 ) ;
goto V_167;
}
V_113 = F_164 ( V_31 , V_207 -> V_193 , 0 , 0 ,
V_358 , V_357 ,
V_307 ) ;
if ( ! V_113 )
F_138 ( & V_314 -> V_129 ) ;
V_167:
F_31 ( V_31 , V_55 , V_359 -> V_145 , V_20 ) ;
return V_113 ;
}
int F_209 ( struct V_30 * V_31 , int V_55 ,
struct V_206 * V_207 ,
struct V_56 * V_57 ,
struct V_56 * V_208 ,
struct V_209 * V_192 )
{
int V_113 ;
int V_174 = V_207 -> V_212 & 0xffff ;
V_113 = F_24 ( V_31 , V_55 , V_174 , V_27 , NULL ) ;
if ( V_113 )
return V_113 ;
V_113 = F_135 ( V_31 , V_55 , V_207 , V_57 , V_208 , V_192 ) ;
F_31 ( V_31 , V_55 , V_174 , V_27 ) ;
return V_113 ;
}
static void F_210 ( struct V_30 * V_31 , int V_55 , struct V_122 * V_314 )
{
struct V_313 * V_360 ;
struct V_313 * V_204 ;
struct V_321 V_169 ;
F_96 (rgid, tmp, &rqp->mcg_list, list) {
switch ( V_31 -> V_52 . V_323 ) {
case V_324 :
F_194 ( V_31 , V_360 -> V_320 ) ;
break;
case V_325 :
V_169 . V_145 = V_314 -> V_126 ;
( void ) F_195 ( V_31 , & V_169 , V_360 -> V_315 ,
V_360 -> V_317 , V_360 -> V_319 ) ;
break;
}
F_61 ( & V_360 -> V_156 ) ;
F_16 ( V_360 ) ;
}
}
static int F_211 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type , int V_361 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_331 = & V_154 -> V_39 [ V_55 ] . V_44 [ type ] ;
struct V_10 * V_112 ;
struct V_10 * V_204 ;
int V_362 ;
V_362 = 0 ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (r, tmp, rlist, list) {
if ( V_112 -> V_117 == V_55 ) {
if ( ! V_112 -> V_363 ) {
if ( V_112 -> V_2 == V_115 ) {
if ( V_361 )
F_12 ( V_31 ,
L_30 ,
F_7 ( type ) ,
V_112 -> V_7 ) ;
++ V_362 ;
} else {
V_112 -> V_119 = V_112 -> V_2 ;
V_112 -> V_2 = V_115 ;
V_112 -> V_363 = 1 ;
}
}
}
}
F_27 ( F_26 ( V_31 ) ) ;
return V_362 ;
}
static int F_212 ( struct V_30 * V_31 , int V_55 ,
enum V_18 type )
{
unsigned long V_364 ;
int V_362 ;
V_364 = V_365 ;
do {
V_362 = F_211 ( V_31 , V_55 , type , 0 ) ;
if ( F_213 ( V_365 , V_364 + 5 * V_366 ) )
break;
if ( V_362 )
F_214 () ;
} while ( V_362 );
if ( V_362 )
V_362 = F_211 ( V_31 , V_55 , type , 1 ) ;
return V_362 ;
}
static void F_215 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_367 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_20 ] ;
struct V_122 * V_169 ;
struct V_122 * V_204 ;
int V_2 ;
T_1 V_193 ;
int V_145 ;
int V_113 ;
V_113 = F_212 ( V_31 , V_55 , V_20 ) ;
if ( V_113 )
F_216 ( V_31 , L_31
L_32 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (qp, tmp, qp_list, com.list) {
F_27 ( F_26 ( V_31 ) ) ;
if ( V_169 -> V_124 . V_117 == V_55 ) {
V_145 = V_169 -> V_124 . V_7 ;
F_210 ( V_31 , V_55 , V_169 ) ;
V_2 = V_169 -> V_124 . V_119 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_125 :
F_25 ( F_26 ( V_31 ) ) ;
F_46 ( & V_169 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_20 ] ) ;
F_61 ( & V_169 -> V_124 . V_156 ) ;
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_169 ) ;
V_2 = 0 ;
break;
case V_171 :
if ( ! F_69 ( V_31 , V_55 , V_145 ) )
F_110 ( V_31 , V_145 ) ;
V_2 = V_125 ;
break;
case V_172 :
V_193 = V_55 ;
V_113 = F_164 ( V_31 , V_193 ,
V_169 -> V_126 , 2 ,
V_368 ,
V_357 ,
V_307 ) ;
if ( V_113 )
F_12 ( V_31 , L_33
L_34
L_35 , V_55 ,
V_169 -> V_126 ) ;
F_138 ( & V_169 -> V_257 -> V_129 ) ;
F_138 ( & V_169 -> V_258 -> V_129 ) ;
F_138 ( & V_169 -> V_242 -> V_129 ) ;
if ( V_169 -> V_187 )
F_138 ( & V_169 -> V_187 -> V_129 ) ;
V_2 = V_171 ;
break;
default:
V_2 = 0 ;
}
}
}
F_25 ( F_26 ( V_31 ) ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_217 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_369 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_22 ] ;
struct V_139 * V_187 ;
struct V_139 * V_204 ;
int V_2 ;
T_1 V_193 ;
F_218 ( V_370 ) ;
int V_199 ;
int V_113 ;
V_113 = F_212 ( V_31 , V_55 , V_22 ) ;
if ( V_113 )
F_216 ( V_31 , L_36
L_37 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (srq, tmp, srq_list, com.list) {
F_27 ( F_26 ( V_31 ) ) ;
if ( V_187 -> V_124 . V_117 == V_55 ) {
V_199 = V_187 -> V_124 . V_7 ;
V_2 = V_187 -> V_124 . V_119 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_140 :
F_93 ( V_31 , V_199 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_46 ( & V_187 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_22 ] ) ;
F_61 ( & V_187 -> V_124 . V_156 ) ;
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_187 ) ;
V_2 = 0 ;
break;
case V_188 :
V_193 = V_55 ;
V_113 = F_164 ( V_31 , V_193 , V_199 , 1 ,
V_371 ,
V_357 ,
V_307 ) ;
if ( V_113 )
F_12 ( V_31 , L_38
L_39
L_40 ,
V_55 , V_199 ) ;
F_138 ( & V_187 -> V_242 -> V_129 ) ;
if ( V_187 -> V_185 )
F_138 ( & V_187 -> V_185 -> V_129 ) ;
V_2 = V_140 ;
break;
default:
V_2 = 0 ;
}
}
}
F_25 ( F_26 ( V_31 ) ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_219 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_372 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_21 ] ;
struct V_137 * V_185 ;
struct V_137 * V_204 ;
int V_2 ;
T_1 V_193 ;
F_218 ( V_370 ) ;
int V_183 ;
int V_113 ;
V_113 = F_212 ( V_31 , V_55 , V_21 ) ;
if ( V_113 )
F_216 ( V_31 , L_41
L_37 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (cq, tmp, cq_list, com.list) {
F_27 ( F_26 ( V_31 ) ) ;
if ( V_185 -> V_124 . V_117 == V_55 && ! F_48 ( & V_185 -> V_129 ) ) {
V_183 = V_185 -> V_124 . V_7 ;
V_2 = V_185 -> V_124 . V_119 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_138 :
F_90 ( V_31 , V_183 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_46 ( & V_185 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_21 ] ) ;
F_61 ( & V_185 -> V_124 . V_156 ) ;
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_185 ) ;
V_2 = 0 ;
break;
case V_186 :
V_193 = V_55 ;
V_113 = F_164 ( V_31 , V_193 , V_183 , 1 ,
V_373 ,
V_357 ,
V_307 ) ;
if ( V_113 )
F_12 ( V_31 , L_42
L_43
L_40 ,
V_55 , V_183 ) ;
F_138 ( & V_185 -> V_242 -> V_129 ) ;
V_2 = V_138 ;
break;
default:
V_2 = 0 ;
}
}
}
F_25 ( F_26 ( V_31 ) ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_220 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_374 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_23 ] ;
struct V_133 * V_176 ;
struct V_133 * V_204 ;
int V_2 ;
T_1 V_193 ;
F_218 ( V_370 ) ;
int V_375 ;
int V_113 ;
V_113 = F_212 ( V_31 , V_55 , V_23 ) ;
if ( V_113 )
F_216 ( V_31 , L_44
L_37 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (mpt, tmp, mpt_list, com.list) {
F_27 ( F_26 ( V_31 ) ) ;
if ( V_176 -> V_124 . V_117 == V_55 ) {
V_375 = V_176 -> V_124 . V_7 ;
V_2 = V_176 -> V_124 . V_119 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_134 :
F_86 ( V_31 , V_176 -> V_132 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_46 ( & V_176 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_23 ] ) ;
F_61 ( & V_176 -> V_124 . V_156 ) ;
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_176 ) ;
V_2 = 0 ;
break;
case V_177 :
F_113 ( V_31 , V_176 -> V_132 ) ;
V_2 = V_134 ;
break;
case V_178 :
V_193 = V_55 ;
V_113 = F_164 ( V_31 , V_193 , V_375 , 0 ,
V_376 ,
V_357 ,
V_307 ) ;
if ( V_113 )
F_12 ( V_31 , L_45
L_46
L_40 ,
V_55 , V_375 ) ;
if ( V_176 -> V_242 )
F_138 ( & V_176 -> V_242 -> V_129 ) ;
V_2 = V_177 ;
break;
default:
V_2 = 0 ;
}
}
}
F_25 ( F_26 ( V_31 ) ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_221 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_377 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_24 ] ;
struct V_131 * V_242 ;
struct V_131 * V_204 ;
int V_2 ;
F_218 ( V_370 ) ;
int V_150 ;
int V_113 ;
V_113 = F_212 ( V_31 , V_55 , V_24 ) ;
if ( V_113 )
F_216 ( V_31 , L_47
L_37 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (mtt, tmp, mtt_list, com.list) {
F_27 ( F_26 ( V_31 ) ) ;
if ( V_242 -> V_124 . V_117 == V_55 ) {
V_150 = V_242 -> V_124 . V_7 ;
V_2 = V_242 -> V_124 . V_119 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_4 :
F_83 ( V_31 , V_150 ,
V_242 -> V_130 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_46 ( & V_242 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_24 ] ) ;
F_61 ( & V_242 -> V_124 . V_156 ) ;
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_242 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_25 ( F_26 ( V_31 ) ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_222 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 =
& V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_378 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_28 ] ;
struct V_146 * V_379 ;
struct V_146 * V_204 ;
int V_2 ;
T_1 V_150 ;
int V_113 ;
V_113 = F_212 ( V_31 , V_55 , V_28 ) ;
if ( V_113 )
F_216 ( V_31 , L_48 ,
V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (fs_rule, tmp, fs_rule_list, com.list) {
F_27 ( F_26 ( V_31 ) ) ;
if ( V_379 -> V_124 . V_117 == V_55 ) {
V_150 = V_379 -> V_124 . V_7 ;
V_2 = V_379 -> V_124 . V_119 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_147 :
V_113 = F_164 ( V_31 , V_150 , 0 , 0 ,
V_358 ,
V_357 ,
V_307 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_46 ( & V_379 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_28 ] ) ;
F_61 ( & V_379 -> V_124 . V_156 ) ;
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_379 ) ;
V_2 = 0 ;
break;
default:
V_2 = 0 ;
}
}
}
F_25 ( F_26 ( V_31 ) ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_223 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_380 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_26 ] ;
struct V_135 * V_180 ;
struct V_135 * V_204 ;
int V_113 ;
int V_2 ;
F_218 ( V_370 ) ;
int V_273 ;
struct V_56 * V_295 ;
V_113 = F_212 ( V_31 , V_55 , V_26 ) ;
if ( V_113 )
F_216 ( V_31 , L_49
L_37 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (eq, tmp, eq_list, com.list) {
F_27 ( F_26 ( V_31 ) ) ;
if ( V_180 -> V_124 . V_117 == V_55 ) {
V_273 = V_180 -> V_124 . V_7 ;
V_2 = V_180 -> V_124 . V_119 ;
while ( V_2 != 0 ) {
switch ( V_2 ) {
case V_136 :
F_25 ( F_26 ( V_31 ) ) ;
F_46 ( & V_180 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_26 ] ) ;
F_61 ( & V_180 -> V_124 . V_156 ) ;
F_27 ( F_26 ( V_31 ) ) ;
F_16 ( V_180 ) ;
V_2 = 0 ;
break;
case V_182 :
V_295 = F_160 ( V_31 ) ;
if ( F_161 ( V_295 ) ) {
F_214 () ;
continue;
}
V_113 = F_224 ( V_31 , V_55 , 0 ,
V_273 & 0xff , 0 ,
V_381 ,
V_357 ,
V_307 ) ;
if ( V_113 )
F_12 ( V_31 , L_50
L_51
L_40 , V_55 , V_273 ) ;
F_166 ( V_31 , V_295 ) ;
F_138 ( & V_180 -> V_242 -> V_129 ) ;
V_2 = V_136 ;
break;
default:
V_2 = 0 ;
}
}
}
F_25 ( F_26 ( V_31 ) ) ;
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_225 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_382 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_27 ] ;
struct V_141 * V_383 ;
struct V_141 * V_204 ;
int V_113 ;
int V_174 ;
V_113 = F_212 ( V_31 , V_55 , V_27 ) ;
if ( V_113 )
F_216 ( V_31 , L_52
L_37 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (counter, tmp, counter_list, com.list) {
if ( V_383 -> V_124 . V_117 == V_55 ) {
V_174 = V_383 -> V_124 . V_7 ;
F_46 ( & V_383 -> V_124 . V_9 ,
& V_154 -> V_46 [ V_27 ] ) ;
F_61 ( & V_383 -> V_124 . V_156 ) ;
F_16 ( V_383 ) ;
F_104 ( V_31 , V_174 ) ;
}
}
F_27 ( F_26 ( V_31 ) ) ;
}
static void F_226 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
struct V_153 * V_154 = & V_33 -> V_36 . V_37 . V_38 ;
struct V_202 * V_384 =
& V_154 -> V_39 [ V_55 ] . V_44 [ V_29 ] ;
struct V_143 * V_385 ;
struct V_143 * V_204 ;
int V_113 ;
int V_205 ;
V_113 = F_212 ( V_31 , V_55 , V_29 ) ;
if ( V_113 )
F_216 ( V_31 , L_53
L_37 , V_55 ) ;
F_25 ( F_26 ( V_31 ) ) ;
F_96 (xrcd, tmp, xrcdn_list, com.list) {
if ( V_385 -> V_124 . V_117 == V_55 ) {
V_205 = V_385 -> V_124 . V_7 ;
F_46 ( & V_385 -> V_124 . V_9 , & V_154 -> V_46 [ V_29 ] ) ;
F_61 ( & V_385 -> V_124 . V_156 ) ;
F_16 ( V_385 ) ;
F_107 ( V_31 , V_205 ) ;
}
}
F_27 ( F_26 ( V_31 ) ) ;
}
void F_15 ( struct V_30 * V_31 , int V_55 )
{
struct V_32 * V_33 = V_32 ( V_31 ) ;
F_159 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_55 ] . V_45 ) ;
F_97 ( V_31 , V_55 ) ;
F_222 ( V_31 , V_55 ) ;
F_215 ( V_31 , V_55 ) ;
F_217 ( V_31 , V_55 ) ;
F_219 ( V_31 , V_55 ) ;
F_220 ( V_31 , V_55 ) ;
F_223 ( V_31 , V_55 ) ;
F_221 ( V_31 , V_55 ) ;
F_225 ( V_31 , V_55 ) ;
F_226 ( V_31 , V_55 ) ;
F_165 ( & V_33 -> V_36 . V_37 . V_38 . V_39 [ V_55 ] . V_45 ) ;
}
