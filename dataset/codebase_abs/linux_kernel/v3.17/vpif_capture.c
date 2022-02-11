static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_4 ;
struct V_6 * V_7 = F_4 ( V_5 ) ;
struct V_8 * V_9 ;
unsigned long V_10 ;
F_5 ( 2 , V_11 , L_1 ) ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_6 ( V_3 , 0 , V_9 -> V_13 . V_13 . V_14 . V_15 ) ;
if ( F_7 ( V_3 , 0 ) > F_8 ( V_3 , 0 ) )
return - V_16 ;
V_3 -> V_17 . V_18 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
V_10 = F_9 ( V_3 , 0 ) ;
if ( ! F_10 ( ( V_10 + V_9 -> V_19 ) , 8 ) ||
! F_10 ( ( V_10 + V_9 -> V_20 ) , 8 ) ||
! F_10 ( ( V_10 + V_9 -> V_21 ) , 8 ) ||
! F_10 ( ( V_10 + V_9 -> V_22 ) , 8 ) ) {
F_5 ( 1 , V_11 , L_2 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_11 ( struct V_4 * V_23 ,
const struct V_24 * V_13 ,
unsigned int * V_25 , unsigned int * V_26 ,
unsigned int V_27 [] , void * V_28 [] )
{
struct V_6 * V_7 = F_4 ( V_23 ) ;
struct V_8 * V_9 ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_5 ( 2 , V_11 , L_3 ) ;
if ( V_13 && V_13 -> V_13 . V_14 . V_15 < V_9 -> V_13 . V_13 . V_14 . V_15 )
return - V_16 ;
if ( V_23 -> V_29 + * V_25 < 3 )
* V_25 = 3 - V_23 -> V_29 ;
* V_26 = 1 ;
V_27 [ 0 ] = V_13 ? V_13 -> V_13 . V_14 . V_15 : V_9 -> V_13 . V_13 . V_14 . V_15 ;
V_28 [ 0 ] = V_9 -> V_30 ;
F_12 ( V_7 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = F_4 ( V_3 -> V_4 ) ;
struct V_1 * V_31 = F_1 ( V_3 ) ;
struct V_8 * V_9 ;
unsigned long V_32 ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_5 ( 2 , V_11 , L_4 ) ;
F_14 ( & V_9 -> V_33 , V_32 ) ;
F_15 ( & V_31 -> V_34 , & V_9 -> V_35 ) ;
F_16 ( & V_9 -> V_33 , V_32 ) ;
}
static int F_17 ( struct V_4 * V_23 , unsigned int V_36 )
{
struct V_37 * V_38 =
V_39 -> V_40 ;
struct V_6 * V_7 = F_4 ( V_23 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_41 * V_42 = & V_7 -> V_43 ;
struct V_1 * V_31 , * V_44 ;
unsigned long V_10 , V_32 ;
int V_45 ;
F_14 ( & V_9 -> V_33 , V_32 ) ;
V_7 -> V_46 = 0 ;
if ( V_38 -> V_47 ) {
V_45 = V_38 ->
V_47 ( V_42 -> V_48 . V_49 ) ;
if ( V_45 < 0 ) {
F_5 ( 1 , V_11 , L_5 ) ;
goto V_50;
}
}
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_53 , 1 ) ;
if ( V_45 && V_45 != - V_54 && V_45 != - V_55 ) {
F_5 ( 1 , V_11 , L_6 ) ;
goto V_50;
}
V_45 = F_19 ( V_42 , V_7 -> V_56 ) ;
if ( V_45 < 0 ) {
F_5 ( 1 , V_11 , L_7 ) ;
goto V_50;
}
V_49 = V_45 ;
F_20 ( V_7 , V_45 ) ;
V_9 -> V_57 = V_9 -> V_58 = F_21 ( V_9 -> V_35 . V_59 ,
struct V_1 , V_34 ) ;
F_22 ( & V_9 -> V_57 -> V_34 ) ;
F_16 ( & V_9 -> V_33 , V_32 ) ;
V_9 -> V_57 -> V_3 . V_60 = V_61 ;
V_10 = F_9 ( & V_9 -> V_57 -> V_3 , 0 ) ;
V_9 -> V_62 ( V_10 + V_9 -> V_19 ,
V_10 + V_9 -> V_20 ,
V_10 + V_9 -> V_21 ,
V_10 + V_9 -> V_22 ) ;
V_63 [ V_12 ] [ V_7 -> V_56 ] = 1 ;
if ( V_64 == V_7 -> V_56 ) {
F_23 () ;
F_24 ( 1 ) ;
F_25 ( 1 ) ;
}
if ( V_65 == V_7 -> V_56 ||
V_49 == 2 ) {
F_26 () ;
F_27 ( 1 ) ;
F_28 ( 1 ) ;
}
return 0 ;
V_50:
F_29 (buf, tmp, &common->dma_queue, list) {
F_22 ( & V_31 -> V_34 ) ;
F_30 ( & V_31 -> V_3 , V_66 ) ;
}
F_16 ( & V_9 -> V_33 , V_32 ) ;
return V_45 ;
}
static void F_31 ( struct V_4 * V_23 )
{
struct V_6 * V_7 = F_4 ( V_23 ) ;
struct V_8 * V_9 ;
unsigned long V_32 ;
int V_45 ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( V_64 == V_7 -> V_56 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_65 == V_7 -> V_56 ||
V_49 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
V_49 = 0 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_53 , 0 ) ;
if ( V_45 && V_45 != - V_54 && V_45 != - V_55 )
F_5 ( 1 , V_11 , L_8 ) ;
F_14 ( & V_9 -> V_33 , V_32 ) ;
if ( V_9 -> V_57 == V_9 -> V_58 ) {
F_30 ( & V_9 -> V_57 -> V_3 , V_67 ) ;
} else {
if ( V_9 -> V_57 != NULL )
F_30 ( & V_9 -> V_57 -> V_3 ,
V_67 ) ;
if ( V_9 -> V_58 != NULL )
F_30 ( & V_9 -> V_58 -> V_3 ,
V_67 ) ;
}
while ( ! F_32 ( & V_9 -> V_35 ) ) {
V_9 -> V_58 = F_21 ( V_9 -> V_35 . V_59 ,
struct V_1 , V_34 ) ;
F_22 ( & V_9 -> V_58 -> V_34 ) ;
F_30 ( & V_9 -> V_58 -> V_3 , V_67 ) ;
}
F_16 ( & V_9 -> V_33 , V_32 ) ;
}
static void F_33 ( struct V_8 * V_9 )
{
F_34 ( & V_9 -> V_57 -> V_3 . V_17 . V_68 ) ;
F_30 ( & V_9 -> V_57 -> V_3 ,
V_69 ) ;
V_9 -> V_57 = V_9 -> V_58 ;
}
static void F_35 ( struct V_8 * V_9 )
{
unsigned long V_10 = 0 ;
F_36 ( & V_9 -> V_33 ) ;
V_9 -> V_58 = F_21 ( V_9 -> V_35 . V_59 ,
struct V_1 , V_34 ) ;
F_22 ( & V_9 -> V_58 -> V_34 ) ;
F_37 ( & V_9 -> V_33 ) ;
V_9 -> V_58 -> V_3 . V_60 = V_61 ;
V_10 = F_9 ( & V_9 -> V_58 -> V_3 , 0 ) ;
V_9 -> V_62 ( V_10 + V_9 -> V_19 ,
V_10 + V_9 -> V_20 ,
V_10 + V_9 -> V_21 ,
V_10 + V_9 -> V_22 ) ;
}
static T_1 F_38 ( int V_70 , void * V_71 )
{
struct V_72 * V_73 = & V_74 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
enum V_75 V_18 ;
int V_56 = 0 ;
int V_76 = - 1 , V_77 ;
V_56 = * ( int * ) ( V_71 ) ;
if ( ! F_39 ( V_56 ) )
return V_78 ;
V_7 = V_73 -> V_73 [ V_56 ] ;
V_18 = V_7 -> V_9 [ V_12 ] . V_13 . V_13 . V_14 . V_18 ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
V_9 = & V_7 -> V_9 [ V_77 ] ;
if ( 1 == V_7 -> V_43 . V_48 . V_80 ) {
F_36 ( & V_9 -> V_33 ) ;
if ( F_32 ( & V_9 -> V_35 ) ) {
F_37 ( & V_9 -> V_33 ) ;
continue;
}
F_37 ( & V_9 -> V_33 ) ;
if ( ! V_63 [ V_77 ] [ V_56 ] )
F_33 ( V_9 ) ;
V_63 [ V_77 ] [ V_56 ] = 0 ;
F_35 ( V_9 ) ;
V_63 [ V_77 ] [ V_56 ] = 0 ;
} else {
if ( V_63 [ V_77 ] [ V_56 ] ) {
V_63 [ V_77 ] [ V_56 ] = 0 ;
continue;
}
if ( 0 == V_77 ) {
V_7 -> V_46 ^= 1 ;
V_76 = F_40 ( V_7 -> V_56 ) ;
if ( V_76 != V_7 -> V_46 ) {
if ( 0 == V_76 )
V_7 -> V_46 = V_76 ;
return V_81 ;
}
}
if ( 0 == V_76 ) {
if ( V_9 -> V_57 == V_9 -> V_58 )
continue;
F_33 ( V_9 ) ;
} else if ( 1 == V_76 ) {
F_36 ( & V_9 -> V_33 ) ;
if ( F_32 ( & V_9 -> V_35 ) ||
( V_9 -> V_57 != V_9 -> V_58 ) ) {
F_37 ( & V_9 -> V_33 ) ;
continue;
}
F_37 ( & V_9 -> V_33 ) ;
F_35 ( V_9 ) ;
}
}
}
return V_81 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_41 * V_43 = & V_7 -> V_43 ;
const struct V_82 * V_83 ;
struct V_82 * V_48 = & V_43 -> V_48 ;
struct V_84 * V_85 = & V_7 -> V_52 ;
int V_86 ;
F_5 ( 2 , V_11 , L_9 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
V_83 = & V_88 [ V_86 ] ;
if ( V_83 -> V_89 == 0 ) {
F_5 ( 2 , V_11 , L_10 ) ;
if ( V_83 -> V_90 & V_85 -> V_90 ) {
memcpy ( V_48 , V_83 , sizeof( * V_83 ) ) ;
break;
}
} else {
F_5 ( 2 , V_11 , L_11 ) ;
if ( ! memcmp ( & V_83 -> V_91 , & V_85 -> V_91 ,
sizeof( V_85 -> V_91 ) ) ) {
memcpy ( V_48 , V_83 , sizeof( * V_83 ) ) ;
break;
}
}
}
if ( V_86 == V_87 )
return - V_16 ;
V_9 -> V_13 . V_13 . V_14 . V_92 = V_48 -> V_92 ;
V_9 -> V_92 = V_48 -> V_92 ;
V_9 -> V_13 . V_13 . V_14 . V_93 = V_48 -> V_93 ;
V_9 -> V_93 = V_48 -> V_93 ;
V_9 -> V_13 . V_13 . V_14 . V_15 = V_9 -> V_93 * V_9 -> V_92 * 2 ;
V_9 -> V_13 . V_13 . V_14 . V_94 = V_48 -> V_92 ;
V_43 -> V_95 . V_96 = V_48 -> V_92 ;
V_43 -> V_95 . V_97 = V_48 -> V_80 ;
if ( V_85 -> V_90 )
V_9 -> V_13 . V_13 . V_14 . V_98 = V_99 ;
else
V_9 -> V_13 . V_13 . V_14 . V_98 = V_100 ;
if ( V_7 -> V_43 . V_48 . V_80 )
V_9 -> V_13 . V_13 . V_14 . V_18 = V_101 ;
else
V_9 -> V_13 . V_13 . V_14 . V_18 = V_102 ;
if ( V_7 -> V_43 . V_103 . V_104 == V_105 )
V_9 -> V_13 . V_13 . V_14 . V_106 = V_107 ;
else
V_9 -> V_13 . V_13 . V_14 . V_106 = V_108 ;
V_9 -> V_13 . type = V_109 ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
unsigned int V_96 , V_110 , V_15 ;
struct V_84 * V_85 = & ( V_7 -> V_52 ) ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
enum V_75 V_18 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
F_5 ( 2 , V_11 , L_12 ) ;
if ( V_111 == V_18 ) {
if ( V_43 -> V_48 . V_80 )
V_85 -> V_112 = V_101 ;
else
V_85 -> V_112 = V_102 ;
} else
V_85 -> V_112 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
V_15 = V_9 -> V_13 . V_13 . V_14 . V_15 ;
V_96 = V_9 -> V_13 . V_13 . V_14 . V_94 ;
V_110 = V_15 / ( V_96 * 2 ) ;
if ( ( V_101 == V_85 -> V_112 ) ||
( V_102 == V_85 -> V_112 ) ) {
V_9 -> V_19 = 0 ;
V_9 -> V_20 = V_96 ;
V_9 -> V_21 = V_15 / 2 ;
V_9 -> V_22 = V_15 / 2 + V_96 ;
} else if ( V_113 == V_85 -> V_112 ) {
V_9 -> V_19 = 0 ;
V_9 -> V_20 = V_15 / 4 ;
V_9 -> V_21 = V_15 / 2 ;
V_9 -> V_22 = V_9 -> V_21 + V_15 / 4 ;
} else if ( V_114 == V_85 -> V_112 ) {
V_9 -> V_20 = 0 ;
V_9 -> V_19 = V_15 / 4 ;
V_9 -> V_22 = V_15 / 2 ;
V_9 -> V_21 = V_9 -> V_22 + V_15 / 4 ;
}
if ( ( V_101 == V_85 -> V_112 ) ||
( V_102 == V_85 -> V_112 ) )
V_43 -> V_95 . V_97 = 1 ;
else
V_43 -> V_95 . V_97 = 0 ;
if ( 1 == V_43 -> V_48 . V_80 )
V_43 -> V_95 . V_96 =
V_9 -> V_13 . V_13 . V_14 . V_94 ;
else {
if ( ( V_18 == V_111 )
|| ( V_18 == V_102 ) )
V_43 -> V_95 . V_96 =
V_9 -> V_13 . V_13 . V_14 . V_94 * 2 ;
else
V_43 -> V_95 . V_96 =
V_9 -> V_13 . V_13 . V_14 . V_94 ;
}
V_7 -> V_43 . V_95 . V_90 = V_43 -> V_48 . V_90 ;
}
static inline enum V_75 F_42 (
struct V_115 * V_103 )
{
return ( V_103 -> V_104 == V_105 ) ? V_101 :
V_102 ;
}
static void F_20 ( struct V_6 * V_7 , int V_116 )
{
struct V_8 * V_9 ;
F_5 ( 2 , V_11 , L_13 ) ;
V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
if ( V_65 == V_7 -> V_56 )
V_9 -> V_62 = V_117 ;
else if ( 2 == V_116 )
V_9 -> V_62 = V_118 ;
else
V_9 -> V_62 = V_119 ;
}
static int F_43 (
struct V_37 * V_120 ,
struct V_121 * V_122 ,
int V_123 )
{
struct V_124 * V_125 ;
const char * V_126 ;
int V_77 ;
F_5 ( 2 , V_11 , L_14 ) ;
V_126 = V_122 -> V_127 [ V_123 ] . V_126 ;
if ( V_126 == NULL )
return - 1 ;
for ( V_77 = 0 ; V_77 < V_120 -> V_128 ; V_77 ++ ) {
V_125 = & V_120 -> V_125 [ V_77 ] ;
if ( ! strcmp ( V_125 -> V_129 , V_126 ) )
return V_77 ;
}
return - 1 ;
}
static int F_44 (
struct V_37 * V_120 ,
struct V_6 * V_7 ,
int V_86 )
{
struct V_121 * V_122 =
& V_120 -> V_130 [ V_7 -> V_56 ] ;
struct V_124 * V_125 = NULL ;
struct V_131 * V_51 = NULL ;
T_2 V_132 = 0 , V_133 = 0 ;
int V_134 ;
int V_45 ;
V_134 = F_43 ( V_120 , V_122 , V_86 ) ;
if ( V_134 >= 0 ) {
V_51 = V_74 . V_51 [ V_134 ] ;
V_125 = & V_120 -> V_125 [ V_134 ] ;
}
if ( V_51 && V_120 -> V_135 ) {
V_45 = V_120 -> V_135 ( V_7 -> V_56 ,
V_125 -> V_129 ) ;
if ( V_45 < 0 ) {
F_5 ( 1 , V_11 , L_15 \
L_16 ,
V_125 -> V_129 , V_86 ) ;
return V_45 ;
}
}
if ( V_51 ) {
V_132 = V_122 -> V_127 [ V_86 ] . V_136 ;
V_133 = V_122 -> V_127 [ V_86 ] . V_137 ;
V_45 = F_18 ( V_51 , V_52 , V_138 ,
V_132 , V_133 , 0 ) ;
if ( V_45 < 0 && V_45 != - V_54 ) {
F_5 ( 1 , V_11 , L_17 ) ;
return V_45 ;
}
}
V_7 -> V_139 = V_86 ;
V_7 -> V_51 = V_51 ;
V_7 -> V_43 . V_103 = V_122 -> V_140 ;
V_7 -> V_141 -> V_142 = V_122 -> V_127 [ V_86 ] . V_132 . V_143 ;
return 0 ;
}
static int F_45 ( struct V_144 * V_144 , void * V_145 , T_3 * V_146 )
{
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
int V_45 = 0 ;
F_5 ( 2 , V_11 , L_18 ) ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_149 , V_146 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_150 ;
if ( V_45 ) {
F_5 ( 1 , V_11 , L_19 ) ;
return V_45 ;
}
return 0 ;
}
static int F_48 ( struct V_144 * V_144 , void * V_145 , T_3 * V_143 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
F_5 ( 2 , V_11 , L_20 ) ;
if ( V_83 -> V_130 [ V_7 -> V_56 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
V_132 = V_122 -> V_127 [ V_7 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_153 )
return - V_150 ;
* V_143 = V_7 -> V_52 . V_90 ;
return 0 ;
}
static int F_49 ( struct V_144 * V_144 , void * V_145 , T_3 V_146 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_45 ;
F_5 ( 2 , V_11 , L_21 ) ;
if ( V_83 -> V_130 [ V_7 -> V_56 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
V_132 = V_122 -> V_127 [ V_7 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_153 )
return - V_150 ;
if ( F_50 ( & V_9 -> V_154 ) )
return - V_155 ;
V_7 -> V_52 . V_90 = V_146 ;
memset ( & V_7 -> V_52 . V_91 , 0 , sizeof( V_7 -> V_52 . V_91 ) ) ;
if ( F_41 ( V_7 ) ) {
F_51 ( L_22 ) ;
return - V_16 ;
}
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_156 , V_146 ) ;
if ( V_45 && V_45 != - V_54 && V_45 != - V_55 ) {
F_5 ( 1 , V_11 , L_23 ) ;
return V_45 ;
}
return 0 ;
}
static int F_52 ( struct V_144 * V_144 , void * V_145 ,
struct V_151 * V_132 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_121 * V_122 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
if ( V_132 -> V_86 >= V_122 -> V_157 )
return - V_16 ;
memcpy ( V_132 , & V_122 -> V_127 [ V_132 -> V_86 ] . V_132 ,
sizeof( * V_132 ) ) ;
return 0 ;
}
static int F_53 ( struct V_144 * V_144 , void * V_145 , unsigned int * V_86 )
{
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
* V_86 = V_7 -> V_139 ;
return 0 ;
}
static int F_54 ( struct V_144 * V_144 , void * V_145 , unsigned int V_86 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_121 * V_122 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
if ( V_86 >= V_122 -> V_157 )
return - V_16 ;
if ( F_50 ( & V_9 -> V_154 ) )
return - V_155 ;
return F_44 ( V_83 , V_7 , V_86 ) ;
}
static int F_55 ( struct V_144 * V_144 , void * V_145 ,
struct V_158 * V_13 )
{
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
if ( V_13 -> V_86 != 0 ) {
F_5 ( 1 , V_11 , L_24 ) ;
return - V_16 ;
}
if ( V_7 -> V_43 . V_103 . V_104 == V_105 ) {
V_13 -> type = V_109 ;
strcpy ( V_13 -> V_159 , L_25 ) ;
V_13 -> V_106 = V_107 ;
} else {
V_13 -> type = V_109 ;
strcpy ( V_13 -> V_159 , L_26 ) ;
V_13 -> V_106 = V_108 ;
}
return 0 ;
}
static int F_56 ( struct V_144 * V_144 , void * V_145 ,
struct V_24 * V_13 )
{
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_160 * V_161 = & V_13 -> V_13 . V_14 ;
struct V_8 * V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
struct V_41 * V_41 = & V_7 -> V_43 ;
if ( V_41 -> V_103 . V_104 == V_105 ) {
if ( V_161 -> V_106 != V_107 )
V_161 -> V_106 = V_107 ;
} else {
if ( V_161 -> V_106 != V_108 )
V_161 -> V_106 = V_108 ;
}
V_9 -> V_13 . V_13 . V_14 . V_106 = V_161 -> V_106 ;
F_41 ( V_7 ) ;
V_161 -> V_18 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
V_161 -> V_98 = V_9 -> V_13 . V_13 . V_14 . V_98 ;
V_161 -> V_94 = V_9 -> V_13 . V_13 . V_14 . V_92 ;
V_161 -> V_92 = V_9 -> V_13 . V_13 . V_14 . V_92 ;
V_161 -> V_93 = V_9 -> V_13 . V_13 . V_14 . V_93 ;
V_161 -> V_15 = V_161 -> V_94 * V_161 -> V_93 * 2 ;
V_161 -> V_145 = 0 ;
return 0 ;
}
static int F_57 ( struct V_144 * V_144 , void * V_145 ,
struct V_24 * V_13 )
{
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( V_9 -> V_13 . type != V_13 -> type )
return - V_16 ;
* V_13 = V_9 -> V_13 ;
return 0 ;
}
static int F_58 ( struct V_144 * V_144 , void * V_145 ,
struct V_24 * V_13 )
{
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
int V_45 ;
F_5 ( 2 , V_11 , L_27 , V_162 ) ;
if ( F_50 ( & V_9 -> V_154 ) )
return - V_155 ;
V_45 = F_56 ( V_144 , V_145 , V_13 ) ;
if ( V_45 )
return V_45 ;
V_9 -> V_13 = * V_13 ;
return 0 ;
}
static int F_59 ( struct V_144 * V_144 , void * V_145 ,
struct V_163 * V_164 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
V_164 -> V_165 = V_166 | V_167 ;
V_164 -> V_152 = V_164 -> V_165 | V_168 ;
F_60 ( V_164 -> V_169 , V_170 , sizeof( V_164 -> V_169 ) ) ;
snprintf ( V_164 -> V_171 , sizeof( V_164 -> V_171 ) , L_28 ,
F_61 ( V_39 ) ) ;
F_60 ( V_164 -> V_172 , V_83 -> V_173 , sizeof( V_164 -> V_172 ) ) ;
return 0 ;
}
static int
F_62 ( struct V_144 * V_144 , void * V_145 ,
struct V_174 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_45 ;
if ( V_83 -> V_130 [ V_7 -> V_56 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
V_132 = V_122 -> V_127 [ V_7 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
V_175 -> V_177 = 0 ;
V_45 = F_18 ( V_7 -> V_51 , V_177 , V_178 , V_175 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_16 ;
return V_45 ;
}
static int
F_63 ( struct V_144 * V_144 , void * V_145 ,
struct V_179 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_45 ;
if ( V_83 -> V_130 [ V_7 -> V_56 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
V_132 = V_122 -> V_127 [ V_7 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_180 , V_175 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_150 ;
return V_45 ;
}
static int F_64 ( struct V_144 * V_144 , void * V_145 ,
struct V_179 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_82 * V_48 = & V_43 -> V_48 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_84 * V_85 = & V_7 -> V_52 ;
struct V_181 * V_182 = & V_85 -> V_91 . V_182 ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_45 ;
if ( V_83 -> V_130 [ V_7 -> V_56 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
V_132 = V_122 -> V_127 [ V_7 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
if ( V_175 -> type != V_183 ) {
F_5 ( 2 , V_11 , L_29 ) ;
return - V_16 ;
}
if ( F_50 ( & V_9 -> V_154 ) )
return - V_155 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_184 , V_175 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
V_45 = 0 ;
if ( V_45 < 0 ) {
F_5 ( 2 , V_11 , L_30 ) ;
return V_45 ;
}
if ( ! ( V_175 -> V_182 . V_92 && V_175 -> V_182 . V_93 &&
( V_175 -> V_182 . V_185 ||
V_175 -> V_182 . V_186 ||
V_175 -> V_182 . V_187 ) &&
V_175 -> V_182 . V_188 &&
( V_175 -> V_182 . V_189 ||
V_175 -> V_182 . V_190 ) ) ) {
F_5 ( 2 , V_11 , L_31
L_32
L_33
L_34
L_35 ) ;
return - V_16 ;
}
V_85 -> V_91 = * V_175 ;
V_48 -> V_191 = F_65 ( V_182 ) - 8 ;
V_48 -> V_192 = V_182 -> V_92 ;
V_48 -> V_193 = 1 ;
V_48 -> V_194 = V_182 -> V_190 + V_182 -> V_189 + 1 ;
V_48 -> V_195 = F_66 ( V_182 ) ;
if ( V_182 -> V_196 ) {
if ( V_182 -> V_197 || V_182 -> V_198 || V_182 -> V_199 ) {
V_48 -> V_200 = V_48 -> V_195 / 2 -
( V_182 -> V_188 - 1 ) ;
V_48 -> V_201 = V_48 -> V_195 / 2 + 1 ;
V_48 -> V_202 = V_48 -> V_201 + V_182 -> V_199 +
V_182 -> V_197 + 1 ;
V_48 -> V_203 = V_48 -> V_195 -
( V_182 -> V_198 - 1 ) ;
} else {
F_5 ( 2 , V_11 , L_36
L_37 ) ;
return - V_16 ;
}
} else {
V_48 -> V_200 = V_48 -> V_195 - ( V_182 -> V_188 - 1 ) ;
}
strncpy ( V_48 -> V_129 , L_38 , V_204 ) ;
V_48 -> V_92 = V_182 -> V_92 ;
V_48 -> V_93 = V_182 -> V_93 ;
V_48 -> V_80 = V_182 -> V_196 ? 0 : 1 ;
V_48 -> V_49 = 0 ;
V_48 -> V_205 = 0 ;
V_48 -> V_206 = 0 ;
V_48 -> V_89 = 1 ;
V_48 -> V_90 = 0 ;
V_85 -> V_90 = 0 ;
return 0 ;
}
static int F_67 ( struct V_144 * V_144 , void * V_145 ,
struct V_179 * V_175 )
{
struct V_37 * V_83 = V_39 -> V_40 ;
struct V_147 * V_148 = F_46 ( V_144 ) ;
struct V_6 * V_7 = F_47 ( V_148 ) ;
struct V_84 * V_85 = & V_7 -> V_52 ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
if ( V_83 -> V_130 [ V_7 -> V_56 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_7 -> V_56 ] ;
V_132 = V_122 -> V_127 [ V_7 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
* V_175 = V_85 -> V_91 ;
return 0 ;
}
static int F_68 ( struct V_144 * V_207 , void * V_145 )
{
F_69 ( & V_74 . V_208 , 0 , V_209 , V_210 ) ;
return 0 ;
}
static int F_70 ( void )
{
int V_50 , V_77 , V_211 ;
int V_212 ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_74 . V_73 [ V_77 ] =
F_71 ( sizeof( * V_74 . V_73 [ V_77 ] ) , V_214 ) ;
if ( ! V_74 . V_73 [ V_77 ] ) {
V_212 = V_77 ;
V_50 = - V_215 ;
goto V_216;
}
}
return 0 ;
V_216:
for ( V_211 = 0 ; V_211 < V_212 ; V_211 ++ )
F_72 ( V_74 . V_73 [ V_211 ] ) ;
return V_50 ;
}
static int F_73 ( struct V_217 * V_218 ,
struct V_131 * V_219 ,
struct V_220 * V_221 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_74 . V_83 -> V_128 ; V_77 ++ )
if ( ! strcmp ( V_74 . V_83 -> V_125 [ V_77 ] . V_129 ,
V_219 -> V_129 ) ) {
V_74 . V_51 [ V_77 ] = V_219 ;
return 0 ;
}
return - V_16 ;
}
static int F_74 ( void )
{
struct V_8 * V_9 ;
struct V_147 * V_148 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
int V_77 , V_211 , V_50 , V_222 ;
for ( V_211 = 0 ; V_211 < V_213 ; V_211 ++ ) {
V_7 = V_74 . V_73 [ V_211 ] ;
V_7 -> V_56 = V_211 ;
V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
F_75 ( & V_9 -> V_33 ) ;
F_76 ( & V_9 -> V_223 ) ;
V_50 = F_44 ( V_74 . V_83 , V_7 , 0 ) ;
if ( V_50 )
goto V_224;
V_7 -> V_52 . V_90 = V_225 ;
memset ( & V_7 -> V_52 . V_91 , 0 , sizeof( V_7 -> V_52 . V_91 ) ) ;
F_41 ( V_7 ) ;
V_5 = & V_9 -> V_154 ;
V_5 -> type = V_109 ;
V_5 -> V_226 = V_227 | V_228 | V_229 ;
V_5 -> V_230 = V_7 ;
V_5 -> V_231 = & V_232 ;
V_5 -> V_233 = & V_234 ;
V_5 -> V_235 = sizeof( struct V_1 ) ;
V_5 -> V_236 = V_237 ;
V_5 -> V_238 = 1 ;
V_5 -> V_223 = & V_9 -> V_223 ;
V_50 = F_77 ( V_5 ) ;
if ( V_50 ) {
F_51 ( L_39 ) ;
goto V_224;
}
V_9 -> V_30 = F_78 ( V_39 ) ;
if ( F_79 ( V_9 -> V_30 ) ) {
F_51 ( L_40 ) ;
V_50 = F_80 ( V_9 -> V_30 ) ;
goto V_224;
}
F_81 ( & V_9 -> V_35 ) ;
V_148 = V_7 -> V_141 ;
F_60 ( V_148 -> V_129 , V_170 , sizeof( V_148 -> V_129 ) ) ;
V_148 -> V_239 = V_240 ;
V_148 -> V_241 = & V_242 ;
V_148 -> V_243 = & V_244 ;
V_148 -> V_208 = & V_74 . V_208 ;
V_148 -> V_245 = V_246 ;
V_148 -> V_247 = V_5 ;
V_148 -> V_223 = & V_9 -> V_223 ;
F_82 ( V_7 -> V_141 , V_7 ) ;
V_50 = F_83 ( V_148 ,
V_248 , ( V_211 ? 1 : 0 ) ) ;
if ( V_50 )
goto V_224;
}
F_84 ( & V_74 . V_208 , L_41 ) ;
return 0 ;
V_224:
for ( V_222 = 0 ; V_222 < V_211 ; V_222 ++ ) {
V_7 = V_74 . V_73 [ V_222 ] ;
V_9 = & V_7 -> V_9 [ V_222 ] ;
F_85 ( V_9 -> V_30 ) ;
F_86 ( V_7 -> V_141 ) ;
}
F_72 ( V_74 . V_51 ) ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_240 ( V_7 -> V_141 ) ;
}
F_87 ( & V_74 . V_208 ) ;
return V_50 ;
}
static int F_88 ( struct V_217 * V_218 )
{
return F_74 () ;
}
static T_4 int F_89 ( struct V_249 * V_250 )
{
struct V_124 * V_251 ;
int V_77 , V_211 , V_50 ;
int V_252 = 0 ;
struct V_253 * V_254 ;
struct V_6 * V_7 ;
struct V_147 * V_255 ;
struct V_256 * V_257 ;
int V_128 ;
V_39 = & V_250 -> V_73 ;
V_50 = F_70 () ;
if ( V_50 ) {
F_90 ( V_39 -> V_169 , L_42 ) ;
return V_50 ;
}
V_50 = F_91 ( V_39 , & V_74 . V_208 ) ;
if ( V_50 ) {
F_90 ( V_39 -> V_169 , L_43 ) ;
return V_50 ;
}
while ( ( V_257 = F_92 ( V_250 , V_258 , V_252 ) ) ) {
V_50 = F_93 ( & V_250 -> V_73 , V_257 -> V_259 , F_38 ,
V_260 , V_170 ,
( void * ) ( & V_74 . V_73 [ V_252 ] ->
V_56 ) ) ;
if ( V_50 ) {
V_50 = - V_16 ;
goto V_261;
}
V_252 ++ ;
}
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_255 = F_94 () ;
if ( NULL == V_255 ) {
for ( V_211 = 0 ; V_211 < V_77 ; V_211 ++ ) {
V_7 = V_74 . V_73 [ V_211 ] ;
V_240 ( V_7 -> V_141 ) ;
}
V_50 = - V_215 ;
goto V_261;
}
V_7 -> V_141 = V_255 ;
}
V_74 . V_83 = V_250 -> V_73 . V_40 ;
V_128 = V_74 . V_83 -> V_128 ;
V_74 . V_51 = F_71 ( sizeof( struct V_131 * ) * V_128 ,
V_214 ) ;
if ( V_74 . V_51 == NULL ) {
F_51 ( L_44 ) ;
V_50 = - V_215 ;
goto V_262;
}
if ( ! V_74 . V_83 -> V_263 ) {
V_254 = F_95 ( 1 ) ;
for ( V_77 = 0 ; V_77 < V_128 ; V_77 ++ ) {
V_251 = & V_74 . V_83 -> V_125 [ V_77 ] ;
V_74 . V_51 [ V_77 ] =
F_96 ( & V_74 . V_208 ,
V_254 ,
& V_251 ->
V_264 ,
NULL ) ;
if ( ! V_74 . V_51 [ V_77 ] ) {
F_51 ( L_45 ) ;
V_50 = - V_55 ;
goto V_265;
}
F_84 ( & V_74 . V_208 ,
L_46 ,
V_251 -> V_129 ) ;
}
F_74 () ;
} else {
V_74 . V_218 . V_266 = V_74 . V_83 -> V_221 ;
V_74 . V_218 . V_267 = V_74 . V_83 -> V_263 [ 0 ] ;
V_74 . V_218 . V_268 = F_73 ;
V_74 . V_218 . V_269 = F_88 ;
V_50 = F_97 ( & V_74 . V_208 ,
& V_74 . V_218 ) ;
if ( V_50 ) {
F_51 ( L_47 ) ;
V_50 = - V_16 ;
goto V_265;
}
}
return 0 ;
V_265:
F_72 ( V_74 . V_51 ) ;
V_262:
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_240 ( V_7 -> V_141 ) ;
}
V_261:
F_87 ( & V_74 . V_208 ) ;
return V_50 ;
}
static int F_98 ( struct V_249 * V_270 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_77 ;
F_87 ( & V_74 . V_208 ) ;
F_72 ( V_74 . V_51 ) ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_85 ( V_9 -> V_30 ) ;
F_86 ( V_7 -> V_141 ) ;
F_72 ( V_74 . V_73 [ V_77 ] ) ;
}
return 0 ;
}
static int F_99 ( struct V_270 * V_73 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( ! F_100 ( & V_9 -> V_154 ) )
continue;
F_101 ( & V_9 -> V_223 ) ;
if ( V_7 -> V_56 == V_64 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_7 -> V_56 == V_65 ||
V_49 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
F_102 ( & V_9 -> V_223 ) ;
}
return 0 ;
}
static int F_103 ( struct V_270 * V_73 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_7 = V_74 . V_73 [ V_77 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( ! F_100 ( & V_9 -> V_154 ) )
continue;
F_101 ( & V_9 -> V_223 ) ;
if ( V_7 -> V_56 == V_64 ) {
F_25 ( 1 ) ;
F_24 ( 1 ) ;
}
if ( V_7 -> V_56 == V_65 ||
V_49 == 2 ) {
F_28 ( 1 ) ;
F_27 ( 1 ) ;
}
F_102 ( & V_9 -> V_223 ) ;
}
return 0 ;
}
