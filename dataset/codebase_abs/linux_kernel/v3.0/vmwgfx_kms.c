void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( & V_2 -> V_3 ) ;
if ( V_2 -> V_4 )
F_3 ( & V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 ) ;
F_6 ( & V_2 -> V_7 ) ;
}
int F_7 ( struct V_8 * V_9 ,
T_1 * V_10 , T_1 V_11 , T_1 V_12 ,
T_1 V_13 , T_1 V_14 )
{
struct {
T_1 V_15 ;
T_2 V_16 ;
} * V_15 ;
T_1 V_17 = V_11 * V_12 * 4 ;
T_1 V_18 = sizeof( * V_15 ) + V_17 ;
if ( ! V_10 )
return - V_19 ;
V_15 = F_8 ( V_9 , V_18 ) ;
if ( F_9 ( V_15 == NULL ) ) {
F_10 ( L_1 ) ;
return - V_20 ;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
memcpy ( & V_15 [ 1 ] , V_10 , V_17 ) ;
V_15 -> V_15 = F_11 ( V_21 ) ;
V_15 -> V_16 . V_22 = F_11 ( 0 ) ;
V_15 -> V_16 . V_11 = F_11 ( V_11 ) ;
V_15 -> V_16 . V_12 = F_11 ( V_12 ) ;
V_15 -> V_16 . V_13 = F_11 ( V_13 ) ;
V_15 -> V_16 . V_14 = F_11 ( V_14 ) ;
F_12 ( V_9 , V_18 ) ;
return 0 ;
}
void F_13 ( struct V_8 * V_9 ,
bool V_23 , int V_24 , int V_25 )
{
T_3 T_4 * V_26 = V_9 -> V_27 ;
T_5 V_28 ;
F_14 ( V_23 ? 1 : 0 , V_26 + V_29 ) ;
F_14 ( V_24 , V_26 + V_30 ) ;
F_14 ( V_25 , V_26 + V_31 ) ;
V_28 = F_15 ( V_26 + V_32 ) ;
F_14 ( ++ V_28 , V_26 + V_32 ) ;
}
int F_16 ( struct V_33 * V_5 , struct V_34 * V_35 ,
T_5 V_36 , T_5 V_11 , T_5 V_12 )
{
struct V_8 * V_9 = F_17 ( V_5 -> V_37 ) ;
struct V_38 * V_39 = F_18 ( V_35 ) -> V_39 ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_43 = NULL ;
int V_44 ;
if ( V_36 ) {
V_44 = F_20 ( V_9 , V_39 ,
V_36 , & V_41 ) ;
if ( ! V_44 ) {
if ( ! V_41 -> V_45 . V_10 ) {
F_10 ( L_2 ) ;
return - V_19 ;
}
} else {
V_44 = F_21 ( V_39 ,
V_36 , & V_43 ) ;
if ( V_44 ) {
F_10 ( L_3 , V_44 ) ;
return - V_19 ;
}
}
}
if ( V_2 -> V_3 ) {
V_2 -> V_3 -> V_45 . V_5 = NULL ;
F_2 ( & V_2 -> V_3 ) ;
}
if ( V_2 -> V_4 )
F_3 ( & V_2 -> V_4 ) ;
if ( V_41 ) {
V_2 -> V_3 = V_41 ;
V_2 -> V_3 -> V_45 . V_5 = V_5 ;
V_2 -> V_46 = V_2 -> V_3 -> V_45 . V_47 ;
F_7 ( V_9 , V_41 -> V_45 . V_10 ,
64 , 64 , V_2 -> V_48 , V_2 -> V_49 ) ;
} else if ( V_43 ) {
struct V_50 V_51 ;
unsigned long V_52 ;
unsigned long V_53 ;
void * V_54 ;
bool V_55 ;
V_2 -> V_4 = V_43 ;
V_52 = 0 ;
V_53 = ( 64 * 64 * 4 ) >> V_56 ;
V_44 = F_22 ( & V_43 -> V_57 , true , false , false , 0 ) ;
if ( F_9 ( V_44 != 0 ) ) {
F_10 ( L_4 ) ;
return - V_19 ;
}
V_44 = F_23 ( & V_43 -> V_57 , V_52 , V_53 , & V_51 ) ;
if ( F_9 ( V_44 != 0 ) )
goto V_58;
V_54 = F_24 ( & V_51 , & V_55 ) ;
F_7 ( V_9 , V_54 , 64 , 64 ,
V_2 -> V_48 , V_2 -> V_49 ) ;
F_25 ( & V_51 ) ;
V_58:
F_26 ( & V_43 -> V_57 ) ;
} else {
F_13 ( V_9 , false , 0 , 0 ) ;
return 0 ;
}
F_13 ( V_9 , true , V_2 -> V_59 , V_2 -> V_60 ) ;
return 0 ;
}
int F_27 ( struct V_33 * V_5 , int V_24 , int V_25 )
{
struct V_8 * V_9 = F_17 ( V_5 -> V_37 ) ;
struct V_1 * V_2 = F_19 ( V_5 ) ;
bool V_61 = V_2 -> V_3 || V_2 -> V_4 ? true : false ;
V_2 -> V_59 = V_24 + V_5 -> V_24 ;
V_2 -> V_60 = V_25 + V_5 -> V_25 ;
F_13 ( V_9 , V_61 ,
V_2 -> V_59 , V_2 -> V_60 ) ;
return 0 ;
}
void F_28 ( struct V_40 * V_62 ,
struct V_38 * V_39 ,
struct V_63 * V_64 ,
T_6 * V_65 )
{
struct V_50 V_51 ;
unsigned long V_52 ;
unsigned long V_53 ;
T_7 * V_66 ;
unsigned V_67 ;
void * V_54 ;
bool V_55 ;
struct V_68 {
T_6 V_65 ;
T_8 V_69 ;
} * V_15 ;
int V_44 ;
V_15 = F_29 ( V_65 , struct V_68 , V_65 ) ;
if ( ! V_62 -> V_45 . V_10 )
return;
if ( V_15 -> V_69 . V_70 . V_71 != 0 || V_15 -> V_69 . V_70 . V_72 != 0 ) {
F_10 ( L_5 ) ;
return;
}
if ( V_15 -> V_65 . V_73 < 64 ) {
F_10 ( L_6 ) ;
return;
}
V_66 = ( T_7 * ) & V_15 [ 1 ] ;
V_67 = ( V_15 -> V_65 . V_73 - sizeof( T_8 ) ) /
sizeof( T_7 ) ;
if ( V_15 -> V_69 . V_74 . V_75 != ( 64 * 4 ) ||
V_15 -> V_69 . V_74 . V_76 . V_77 % V_78 ||
V_66 -> V_24 != 0 || V_66 -> V_25 != 0 || V_66 -> V_79 != 0 ||
V_66 -> V_80 != 0 || V_66 -> V_81 != 0 || V_66 -> V_82 != 0 ||
V_66 -> V_83 != 64 || V_66 -> V_84 != 64 || V_66 -> V_85 != 1 ||
V_67 != 1 ) {
F_10 ( L_7 ) ;
return;
}
V_52 = V_15 -> V_69 . V_74 . V_76 . V_77 >> V_56 ;
V_53 = ( 64 * 64 * 4 ) >> V_56 ;
V_44 = F_22 ( V_64 , true , false , false , 0 ) ;
if ( F_9 ( V_44 != 0 ) ) {
F_10 ( L_4 ) ;
return;
}
V_44 = F_23 ( V_64 , V_52 , V_53 , & V_51 ) ;
if ( F_9 ( V_44 != 0 ) )
goto V_58;
V_54 = F_24 ( & V_51 , & V_55 ) ;
memcpy ( V_62 -> V_45 . V_10 , V_54 , 64 * 64 * 4 ) ;
V_62 -> V_45 . V_47 ++ ;
F_25 ( & V_51 ) ;
V_58:
F_26 ( V_64 ) ;
}
void F_30 ( struct V_8 * V_9 )
{
struct V_86 * V_37 = V_9 -> V_37 ;
struct V_1 * V_2 ;
struct V_33 * V_5 ;
F_31 ( & V_37 -> V_87 . V_88 ) ;
F_32 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_19 ( V_5 ) ;
if ( ! V_2 -> V_3 ||
V_2 -> V_46 == V_2 -> V_3 -> V_45 . V_47 )
continue;
V_2 -> V_46 = V_2 -> V_3 -> V_45 . V_47 ;
F_7 ( V_9 ,
V_2 -> V_3 -> V_45 . V_10 ,
64 , 64 , V_2 -> V_48 , V_2 -> V_49 ) ;
}
F_33 ( & V_37 -> V_87 . V_88 ) ;
}
int F_34 ( struct V_89 * V_90 ,
struct V_34 * V_35 ,
unsigned int * V_36 )
{
if ( V_36 )
V_36 = 0 ;
return 0 ;
}
void F_35 ( struct V_91 * V_92 )
{
struct V_93 * V_94 ;
F_31 ( & V_92 -> V_95 ) ;
F_32 (entry, &vmaster->fb_surf, head) {
if ( F_36 ( & V_94 -> V_96 ) )
( void ) V_94 -> V_96 . V_97 . V_98 ( & V_94 -> V_96 . V_97 ) ;
( void ) F_36 ( & V_94 -> V_96 ) ;
}
F_33 ( & V_92 -> V_95 ) ;
}
void F_37 ( struct V_89 * V_99 )
{
struct V_93 * V_100 =
F_38 ( V_99 ) ;
struct V_91 * V_92 = V_91 ( V_100 -> V_101 ) ;
F_31 ( & V_92 -> V_95 ) ;
F_39 ( & V_100 -> V_102 ) ;
F_33 ( & V_92 -> V_95 ) ;
F_36 ( & V_100 -> V_96 ) ;
F_40 ( & V_100 -> V_101 ) ;
F_41 ( V_99 ) ;
F_2 ( & V_100 -> V_41 ) ;
F_42 ( V_100 ) ;
}
static void F_43 ( struct V_103 * V_97 )
{
struct V_104 * V_96 =
F_29 ( V_97 , struct V_104 , V_97 ) ;
struct V_93 * V_100 =
F_29 ( V_96 , struct V_93 , V_96 ) ;
struct V_40 * V_105 = V_100 -> V_41 ;
struct V_89 * V_99 = & V_100 -> V_57 . V_57 ;
struct V_8 * V_9 = F_17 ( V_99 -> V_37 ) ;
struct {
T_6 V_65 ;
T_9 V_106 ;
T_10 V_107 ;
} * V_15 ;
F_31 ( & V_100 -> V_108 ) ;
if ( ! V_100 -> V_109 )
goto V_110;
V_15 = F_8 ( V_9 , sizeof( * V_15 ) ) ;
if ( F_9 ( V_15 == NULL ) )
goto V_111;
V_15 -> V_65 . V_22 = F_11 ( V_112 ) ;
V_15 -> V_65 . V_73 = F_11 ( sizeof( V_15 -> V_106 ) + sizeof( V_15 -> V_107 ) ) ;
V_15 -> V_106 . V_113 = F_11 ( V_105 -> V_114 . V_22 ) ;
V_15 -> V_107 . V_24 = F_11 ( 0 ) ;
V_15 -> V_107 . V_25 = F_11 ( 0 ) ;
V_15 -> V_107 . V_80 = V_15 -> V_107 . V_24 ;
V_15 -> V_107 . V_81 = V_15 -> V_107 . V_25 ;
V_15 -> V_107 . V_83 = F_11 ( V_99 -> V_11 ) ;
V_15 -> V_107 . V_84 = F_11 ( V_99 -> V_12 ) ;
V_100 -> V_109 = false ;
F_12 ( V_9 , sizeof( * V_15 ) ) ;
V_111:
F_44 ( & V_100 -> V_96 , V_115 ) ;
V_110:
F_33 ( & V_100 -> V_108 ) ;
}
int F_45 ( struct V_89 * V_99 ,
struct V_34 * V_35 ,
unsigned V_116 , unsigned V_117 ,
struct V_118 * V_119 ,
unsigned V_120 )
{
struct V_8 * V_9 = F_17 ( V_99 -> V_37 ) ;
struct V_91 * V_92 = V_91 ( V_35 -> V_101 ) ;
struct V_93 * V_100 =
F_38 ( V_99 ) ;
struct V_40 * V_105 = V_100 -> V_41 ;
struct V_118 V_121 ;
T_10 * V_107 ;
int V_122 , V_123 = 1 ;
int V_44 ;
struct {
T_6 V_65 ;
T_9 V_106 ;
T_10 V_107 ;
} * V_15 ;
if ( F_9 ( V_100 -> V_101 != V_35 -> V_101 ) )
return - V_19 ;
V_44 = F_46 ( & V_92 -> V_124 , true ) ;
if ( F_9 ( V_44 != 0 ) )
return V_44 ;
if ( ! V_120 ||
! ( V_9 -> V_125 . V_126 &
V_127 ) ) {
int V_44 ;
F_31 ( & V_100 -> V_108 ) ;
V_100 -> V_109 = true ;
V_44 = F_44 ( & V_100 -> V_96 , V_115 ) ;
F_33 ( & V_100 -> V_108 ) ;
if ( V_44 ) {
F_43 ( & V_100 -> V_96 . V_97 ) ;
}
F_47 ( & V_92 -> V_124 ) ;
return 0 ;
}
if ( ! V_120 ) {
V_120 = 1 ;
V_119 = & V_121 ;
V_121 . V_128 = V_121 . y1 = 0 ;
V_121 . V_129 = V_99 -> V_11 ;
V_121 . V_130 = V_99 -> V_12 ;
} else if ( V_116 & V_131 ) {
V_120 /= 2 ;
V_123 = 2 ;
}
V_15 = F_8 ( V_9 , sizeof( * V_15 ) + ( V_120 - 1 ) * sizeof( V_15 -> V_107 ) ) ;
if ( F_9 ( V_15 == NULL ) ) {
F_10 ( L_1 ) ;
F_47 ( & V_92 -> V_124 ) ;
return - V_20 ;
}
memset ( V_15 , 0 , sizeof( * V_15 ) ) ;
V_15 -> V_65 . V_22 = F_11 ( V_112 ) ;
V_15 -> V_65 . V_73 = F_11 ( sizeof( V_15 -> V_106 ) + V_120 * sizeof( V_15 -> V_107 ) ) ;
V_15 -> V_106 . V_113 = F_11 ( V_105 -> V_114 . V_22 ) ;
for ( V_122 = 0 , V_107 = & V_15 -> V_107 ; V_122 < V_120 ; V_122 ++ , V_107 ++ , V_119 += V_123 ) {
V_107 -> V_24 = F_48 ( V_119 -> V_128 ) ;
V_107 -> V_25 = F_48 ( V_119 -> y1 ) ;
V_107 -> V_80 = V_107 -> V_24 ;
V_107 -> V_81 = V_107 -> V_25 ;
V_107 -> V_83 = F_48 ( V_119 -> V_129 - V_119 -> V_128 ) ;
V_107 -> V_84 = F_48 ( V_119 -> V_130 - V_119 -> y1 ) ;
}
F_12 ( V_9 , sizeof( * V_15 ) + ( V_120 - 1 ) * sizeof( V_15 -> V_107 ) ) ;
F_47 ( & V_92 -> V_124 ) ;
return 0 ;
}
static int F_49 ( struct V_8 * V_9 ,
struct V_34 * V_35 ,
struct V_40 * V_41 ,
struct V_132 * * V_133 ,
const struct V_134
* V_135 )
{
struct V_86 * V_37 = V_9 -> V_37 ;
struct V_93 * V_100 ;
enum V_136 V_137 ;
struct V_91 * V_92 = V_91 ( V_35 -> V_101 ) ;
int V_44 ;
if ( F_9 ( V_41 -> V_138 [ 0 ] != 1 ||
V_41 -> V_139 != 1 ||
V_41 -> V_140 [ 0 ] . V_11 < V_135 -> V_11 ||
V_41 -> V_140 [ 0 ] . V_12 < V_135 -> V_12 ||
V_41 -> V_140 [ 0 ] . V_141 != 1 ) ) {
F_10 ( L_8
L_9 ) ;
return - V_19 ;
}
switch ( V_135 -> V_141 ) {
case 32 :
V_137 = V_142 ;
break;
case 24 :
V_137 = V_143 ;
break;
case 16 :
V_137 = V_144 ;
break;
case 15 :
V_137 = V_145 ;
break;
default:
F_10 ( L_10 , V_135 -> V_141 ) ;
return - V_19 ;
}
if ( F_9 ( V_137 != V_41 -> V_137 ) ) {
F_10 ( L_11 ) ;
return - V_19 ;
}
V_100 = F_50 ( sizeof( * V_100 ) , V_146 ) ;
if ( ! V_100 ) {
V_44 = - V_20 ;
goto V_147;
}
V_44 = F_51 ( V_37 , & V_100 -> V_57 . V_57 ,
& V_148 ) ;
if ( V_44 )
goto V_149;
if ( ! F_52 ( V_41 ) ) {
F_10 ( L_12 , V_41 ) ;
goto V_150;
}
V_100 -> V_57 . V_57 . V_151 = V_135 -> V_152 ;
V_100 -> V_57 . V_57 . V_75 = V_135 -> V_75 ;
V_100 -> V_57 . V_57 . V_141 = V_135 -> V_141 ;
V_100 -> V_57 . V_57 . V_11 = V_135 -> V_11 ;
V_100 -> V_57 . V_57 . V_12 = V_135 -> V_12 ;
V_100 -> V_57 . V_153 = & V_154 ;
V_100 -> V_57 . V_155 = & V_156 ;
V_100 -> V_41 = V_41 ;
V_100 -> V_101 = F_53 ( V_35 -> V_101 ) ;
F_54 ( & V_100 -> V_108 ) ;
F_31 ( & V_92 -> V_95 ) ;
F_55 ( & V_100 -> V_96 , & F_43 ) ;
F_56 ( & V_100 -> V_102 , & V_92 -> V_157 ) ;
F_33 ( & V_92 -> V_95 ) ;
* V_133 = & V_100 -> V_57 ;
return 0 ;
V_150:
F_41 ( & V_100 -> V_57 . V_57 ) ;
V_149:
F_42 ( V_100 ) ;
V_147:
return V_44 ;
}
void F_57 ( struct V_89 * V_99 )
{
struct V_158 * V_159 =
F_58 ( V_99 ) ;
F_41 ( V_99 ) ;
F_3 ( & V_159 -> V_160 ) ;
F_42 ( V_159 ) ;
}
int F_59 ( struct V_89 * V_99 ,
struct V_34 * V_35 ,
unsigned V_116 , unsigned V_117 ,
struct V_118 * V_119 ,
unsigned V_120 )
{
struct V_8 * V_9 = F_17 ( V_99 -> V_37 ) ;
struct V_91 * V_92 = V_91 ( V_35 -> V_101 ) ;
struct V_118 V_121 ;
int V_44 ;
struct {
T_5 V_65 ;
T_11 V_106 ;
} * V_15 ;
int V_122 , V_161 = 1 ;
V_44 = F_46 ( & V_92 -> V_124 , true ) ;
if ( F_9 ( V_44 != 0 ) )
return V_44 ;
if ( ! V_120 ) {
V_120 = 1 ;
V_119 = & V_121 ;
V_121 . V_128 = V_121 . y1 = 0 ;
V_121 . V_129 = V_99 -> V_11 ;
V_121 . V_130 = V_99 -> V_12 ;
} else if ( V_116 & V_131 ) {
V_120 /= 2 ;
V_161 = 2 ;
}
V_15 = F_8 ( V_9 , sizeof( * V_15 ) * V_120 ) ;
if ( F_9 ( V_15 == NULL ) ) {
F_10 ( L_1 ) ;
F_47 ( & V_92 -> V_124 ) ;
return - V_20 ;
}
for ( V_122 = 0 ; V_122 < V_120 ; V_122 ++ , V_119 += V_161 ) {
V_15 [ V_122 ] . V_65 = F_11 ( V_162 ) ;
V_15 [ V_122 ] . V_106 . V_24 = F_11 ( V_119 -> V_128 ) ;
V_15 [ V_122 ] . V_106 . V_25 = F_11 ( V_119 -> y1 ) ;
V_15 [ V_122 ] . V_106 . V_11 = F_11 ( V_119 -> V_129 - V_119 -> V_128 ) ;
V_15 [ V_122 ] . V_106 . V_12 = F_11 ( V_119 -> V_130 - V_119 -> y1 ) ;
}
F_12 ( V_9 , sizeof( * V_15 ) * V_120 ) ;
F_47 ( & V_92 -> V_124 ) ;
return 0 ;
}
static int V_154 ( struct V_132 * V_163 )
{
struct V_8 * V_9 = F_17 ( V_163 -> V_57 . V_37 ) ;
struct V_93 * V_100 =
F_38 ( & V_163 -> V_57 ) ;
unsigned long V_73 = V_100 -> V_57 . V_57 . V_75 * V_100 -> V_57 . V_57 . V_12 ;
int V_44 ;
V_100 -> V_160 = F_50 ( sizeof( * V_100 -> V_160 ) , V_146 ) ;
if ( F_9 ( V_100 -> V_160 == NULL ) )
return - V_20 ;
F_60 ( V_9 ) ;
V_44 = F_61 ( V_9 , V_100 -> V_160 , V_73 ,
& V_164 ,
false , & V_165 ) ;
F_62 ( V_9 ) ;
if ( F_9 ( V_44 != 0 ) )
V_100 -> V_160 = NULL ;
return V_44 ;
}
static int V_156 ( struct V_132 * V_163 )
{
struct V_63 * V_64 ;
struct V_93 * V_100 =
F_38 ( & V_163 -> V_57 ) ;
if ( F_9 ( V_100 -> V_160 == NULL ) )
return 0 ;
V_64 = & V_100 -> V_160 -> V_57 ;
F_63 ( & V_64 ) ;
V_100 -> V_160 = NULL ;
return 0 ;
}
static int F_64 ( struct V_132 * V_163 )
{
struct V_8 * V_9 = F_17 ( V_163 -> V_57 . V_37 ) ;
struct V_158 * V_159 =
F_58 ( & V_163 -> V_57 ) ;
int V_44 ;
F_60 ( V_9 ) ;
V_44 = F_65 ( V_9 , V_159 -> V_160 ) ;
F_62 ( V_9 ) ;
F_66 ( V_44 != 0 ) ;
return 0 ;
}
static int F_67 ( struct V_132 * V_163 )
{
struct V_8 * V_9 = F_17 ( V_163 -> V_57 . V_37 ) ;
struct V_158 * V_159 =
F_58 ( & V_163 -> V_57 ) ;
if ( ! V_159 -> V_160 ) {
F_66 ( ! V_159 -> V_160 ) ;
return 0 ;
}
return F_68 ( V_9 , V_159 -> V_160 ) ;
}
static int F_69 ( struct V_8 * V_9 ,
struct V_42 * V_43 ,
struct V_132 * * V_133 ,
const struct V_134
* V_135 )
{
struct V_86 * V_37 = V_9 -> V_37 ;
struct V_158 * V_159 ;
unsigned int V_166 ;
int V_44 ;
V_166 = V_135 -> V_12 * V_135 -> V_75 ;
if ( F_9 ( V_166 > V_43 -> V_57 . V_167 * V_78 ) ) {
F_10 ( L_13
L_9 ) ;
return - V_19 ;
}
V_159 = F_50 ( sizeof( * V_159 ) , V_146 ) ;
if ( ! V_159 ) {
V_44 = - V_20 ;
goto V_147;
}
V_44 = F_51 ( V_37 , & V_159 -> V_57 . V_57 ,
& V_168 ) ;
if ( V_44 )
goto V_149;
if ( ! F_70 ( V_43 ) ) {
F_10 ( L_14 , V_43 ) ;
goto V_150;
}
V_159 -> V_57 . V_57 . V_151 = V_135 -> V_152 ;
V_159 -> V_57 . V_57 . V_75 = V_135 -> V_75 ;
V_159 -> V_57 . V_57 . V_141 = V_135 -> V_141 ;
V_159 -> V_57 . V_57 . V_11 = V_135 -> V_11 ;
V_159 -> V_57 . V_57 . V_12 = V_135 -> V_12 ;
V_159 -> V_57 . V_153 = F_64 ;
V_159 -> V_57 . V_155 = F_67 ;
V_159 -> V_160 = V_43 ;
* V_133 = & V_159 -> V_57 ;
return 0 ;
V_150:
F_41 ( & V_159 -> V_57 . V_57 ) ;
V_149:
F_42 ( V_159 ) ;
V_147:
return V_44 ;
}
static struct V_89 * F_71 ( struct V_86 * V_37 ,
struct V_34 * V_35 ,
struct V_134 * V_135 )
{
struct V_8 * V_9 = F_17 ( V_37 ) ;
struct V_38 * V_39 = F_18 ( V_35 ) -> V_39 ;
struct V_132 * V_163 = NULL ;
struct V_40 * V_41 = NULL ;
struct V_42 * V_64 = NULL ;
T_12 V_169 ;
int V_44 ;
V_169 = V_135 -> V_75 * V_135 -> V_12 ;
if ( F_9 ( V_169 > ( T_12 ) V_9 -> V_170 ) ) {
F_10 ( L_15 ) ;
return NULL ;
}
V_44 = F_20 ( V_9 , V_39 ,
V_135 -> V_36 , & V_41 ) ;
if ( V_44 )
goto V_171;
if ( ! V_41 -> V_172 )
goto V_173;
V_44 = F_49 ( V_9 , V_35 , V_41 ,
& V_163 , V_135 ) ;
F_2 ( & V_41 ) ;
if ( V_44 ) {
F_10 ( L_16 , V_44 ) ;
return F_72 ( V_44 ) ;
}
return & V_163 -> V_57 ;
V_171:
F_73 ( L_17 , V_174 ) ;
V_44 = F_21 ( V_39 , V_135 -> V_36 , & V_64 ) ;
if ( V_44 ) {
F_10 ( L_18 , V_44 ) ;
return F_72 ( - V_175 ) ;
}
V_44 = F_69 ( V_9 , V_64 , & V_163 ,
V_135 ) ;
F_3 ( & V_64 ) ;
if ( V_44 ) {
F_10 ( L_16 , V_44 ) ;
return F_72 ( V_44 ) ;
}
return & V_163 -> V_57 ;
V_173:
F_10 ( L_19 ) ;
F_2 ( & V_41 ) ;
return F_72 ( - V_19 ) ;
}
int F_74 ( struct V_8 * V_9 )
{
struct V_86 * V_37 = V_9 -> V_37 ;
int V_44 ;
F_75 ( V_37 ) ;
V_37 -> V_87 . V_176 = & V_177 ;
V_37 -> V_87 . V_178 = 1 ;
V_37 -> V_87 . V_179 = 1 ;
V_37 -> V_87 . V_180 = 8192 ;
V_37 -> V_87 . V_181 = 8192 ;
V_44 = F_76 ( V_9 ) ;
return 0 ;
}
int F_77 ( struct V_8 * V_9 )
{
F_78 ( V_9 -> V_37 ) ;
F_79 ( V_9 ) ;
return 0 ;
}
int F_80 ( struct V_86 * V_37 , void * V_182 ,
struct V_34 * V_35 )
{
struct V_183 * V_184 = V_182 ;
struct V_1 * V_2 ;
struct V_185 * V_186 ;
struct V_33 * V_5 ;
int V_44 = 0 ;
F_31 ( & V_37 -> V_87 . V_88 ) ;
if ( V_184 -> V_116 & V_187 ) {
F_32 (crtc, &dev->mode_config.crtc_list, head) {
V_2 = F_19 ( V_5 ) ;
V_2 -> V_48 = V_184 -> V_188 ;
V_2 -> V_49 = V_184 -> V_189 ;
}
F_33 ( & V_37 -> V_87 . V_88 ) ;
return 0 ;
}
V_186 = F_81 ( V_37 , V_184 -> V_190 , V_191 ) ;
if ( ! V_186 ) {
V_44 = - V_19 ;
goto V_133;
}
V_5 = F_82 ( V_186 ) ;
V_2 = F_19 ( V_5 ) ;
V_2 -> V_48 = V_184 -> V_188 ;
V_2 -> V_49 = V_184 -> V_189 ;
V_133:
F_33 ( & V_37 -> V_87 . V_88 ) ;
return V_44 ;
}
void F_83 ( struct V_8 * F_17 ,
unsigned V_11 , unsigned V_12 , unsigned V_75 ,
unsigned V_192 , unsigned V_141 )
{
if ( F_17 -> V_126 & V_193 )
F_84 ( F_17 , V_194 , V_75 ) ;
else if ( F_85 ( F_17 ) )
F_14 ( V_75 , F_17 -> V_27 + V_195 ) ;
F_84 ( F_17 , V_196 , V_11 ) ;
F_84 ( F_17 , V_197 , V_12 ) ;
F_84 ( F_17 , V_198 , V_192 ) ;
F_84 ( F_17 , V_199 , V_141 ) ;
F_84 ( F_17 , V_200 , 0x00ff0000 ) ;
F_84 ( F_17 , V_201 , 0x0000ff00 ) ;
F_84 ( F_17 , V_202 , 0x000000ff ) ;
}
int F_86 ( struct V_8 * F_17 )
{
struct V_203 * V_204 ;
T_5 V_122 ;
F_17 -> V_205 = F_87 ( F_17 , V_196 ) ;
F_17 -> V_206 = F_87 ( F_17 , V_197 ) ;
F_17 -> V_207 = F_87 ( F_17 , V_199 ) ;
F_17 -> V_208 = F_87 ( F_17 , V_198 ) ;
F_17 -> V_209 = F_87 ( F_17 , V_210 ) ;
F_17 -> V_211 = F_87 ( F_17 , V_200 ) ;
F_17 -> V_212 = F_87 ( F_17 , V_202 ) ;
F_17 -> V_213 = F_87 ( F_17 , V_201 ) ;
if ( F_17 -> V_126 & V_193 )
F_17 -> V_214 =
F_87 ( F_17 , V_194 ) ;
else if ( F_85 ( F_17 ) )
F_17 -> V_214 = F_15 ( F_17 -> V_27 +
V_195 ) ;
if ( ! ( F_17 -> V_126 & V_215 ) )
return 0 ;
F_17 -> V_216 = F_87 ( F_17 ,
V_217 ) ;
if ( F_17 -> V_216 == 0 )
F_17 -> V_216 = 1 ;
for ( V_122 = 0 ; V_122 < F_17 -> V_216 ; ++ V_122 ) {
V_204 = & F_17 -> V_218 [ V_122 ] ;
F_84 ( F_17 , V_219 , V_122 ) ;
V_204 -> V_220 = F_87 ( F_17 , V_221 ) ;
V_204 -> V_222 = F_87 ( F_17 , V_223 ) ;
V_204 -> V_224 = F_87 ( F_17 , V_225 ) ;
V_204 -> V_11 = F_87 ( F_17 , V_226 ) ;
V_204 -> V_12 = F_87 ( F_17 , V_227 ) ;
F_84 ( F_17 , V_219 , V_228 ) ;
if ( V_122 == 0 && F_17 -> V_216 == 1 &&
V_204 -> V_11 == 0 && V_204 -> V_12 == 0 ) {
V_204 -> V_11 = F_17 -> V_205 - V_204 -> V_222 ;
V_204 -> V_12 = F_17 -> V_206 - V_204 -> V_224 ;
}
}
return 0 ;
}
int F_88 ( struct V_8 * F_17 )
{
struct V_203 * V_204 ;
T_5 V_122 ;
F_84 ( F_17 , V_196 , F_17 -> V_205 ) ;
F_84 ( F_17 , V_197 , F_17 -> V_206 ) ;
F_84 ( F_17 , V_199 , F_17 -> V_207 ) ;
F_84 ( F_17 , V_198 , F_17 -> V_208 ) ;
F_84 ( F_17 , V_210 , F_17 -> V_209 ) ;
F_84 ( F_17 , V_200 , F_17 -> V_211 ) ;
F_84 ( F_17 , V_201 , F_17 -> V_213 ) ;
F_84 ( F_17 , V_202 , F_17 -> V_212 ) ;
if ( F_17 -> V_126 & V_193 )
F_84 ( F_17 , V_194 ,
F_17 -> V_214 ) ;
else if ( F_85 ( F_17 ) )
F_14 ( F_17 -> V_214 ,
F_17 -> V_27 + V_195 ) ;
if ( ! ( F_17 -> V_126 & V_215 ) )
return 0 ;
for ( V_122 = 0 ; V_122 < F_17 -> V_216 ; ++ V_122 ) {
V_204 = & F_17 -> V_218 [ V_122 ] ;
F_84 ( F_17 , V_219 , V_122 ) ;
F_84 ( F_17 , V_221 , V_204 -> V_220 ) ;
F_84 ( F_17 , V_223 , V_204 -> V_222 ) ;
F_84 ( F_17 , V_225 , V_204 -> V_224 ) ;
F_84 ( F_17 , V_226 , V_204 -> V_11 ) ;
F_84 ( F_17 , V_227 , V_204 -> V_12 ) ;
F_84 ( F_17 , V_219 , V_228 ) ;
}
return 0 ;
}
int F_89 ( struct V_86 * V_37 , void * V_182 ,
struct V_34 * V_35 )
{
struct V_8 * V_9 = F_17 ( V_37 ) ;
struct V_229 * V_184 =
(struct V_229 * ) V_182 ;
struct V_91 * V_92 = V_91 ( V_35 -> V_101 ) ;
void T_13 * V_230 ;
struct V_231 * V_232 ;
unsigned V_233 ;
int V_44 ;
V_44 = F_46 ( & V_92 -> V_124 , true ) ;
if ( F_9 ( V_44 != 0 ) )
return V_44 ;
if ( ! V_184 -> V_234 ) {
struct V_231 V_235 = { 0 , 0 , 800 , 600 } ;
F_90 ( V_9 , 1 , & V_235 ) ;
goto V_110;
}
V_233 = V_184 -> V_234 * sizeof( struct V_231 ) ;
V_232 = F_50 ( V_233 , V_146 ) ;
if ( F_9 ( ! V_232 ) ) {
V_44 = - V_20 ;
goto V_110;
}
V_230 = ( void T_13 * ) ( unsigned long ) V_184 -> V_232 ;
V_44 = F_91 ( V_232 , V_230 , V_233 ) ;
if ( F_9 ( V_44 != 0 ) ) {
F_10 ( L_20 ) ;
V_44 = - V_236 ;
goto V_237;
}
F_90 ( V_9 , V_184 -> V_234 , V_232 ) ;
V_237:
F_42 ( V_232 ) ;
V_110:
F_47 ( & V_92 -> V_124 ) ;
return V_44 ;
}
bool F_92 ( struct V_8 * V_9 ,
T_5 V_75 ,
T_5 V_12 )
{
return ( ( T_12 ) V_75 * ( T_12 ) V_12 ) < ( T_12 ) V_9 -> V_170 ;
}
T_1 F_93 ( struct V_86 * V_37 , int V_5 )
{
return 0 ;
}
