static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = V_3 -> V_6 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_10 * V_11 ;
unsigned long V_12 ;
F_6 ( 2 , V_13 , L_1 ) ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
F_7 ( V_3 , 0 , V_11 -> V_15 . V_15 . V_16 . V_17 ) ;
if ( F_8 ( V_3 , 0 ) > F_9 ( V_3 , 0 ) )
return - V_18 ;
V_5 -> V_19 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
V_12 = F_10 ( V_3 , 0 ) ;
if ( ! F_11 ( ( V_12 + V_11 -> V_20 ) , 8 ) ||
! F_11 ( ( V_12 + V_11 -> V_21 ) , 8 ) ||
! F_11 ( ( V_12 + V_11 -> V_22 ) , 8 ) ||
! F_11 ( ( V_12 + V_11 -> V_23 ) , 8 ) ) {
F_6 ( 1 , V_13 , L_2 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_12 ( struct V_6 * V_24 ,
const void * V_25 ,
unsigned int * V_26 , unsigned int * V_27 ,
unsigned int V_28 [] , void * V_29 [] )
{
const struct V_30 * V_15 = V_25 ;
struct V_8 * V_9 = F_5 ( V_24 ) ;
struct V_10 * V_11 ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
F_6 ( 2 , V_13 , L_3 ) ;
if ( V_15 && V_15 -> V_15 . V_16 . V_17 < V_11 -> V_15 . V_15 . V_16 . V_17 )
return - V_18 ;
if ( V_24 -> V_31 + * V_26 < 3 )
* V_26 = 3 - V_24 -> V_31 ;
* V_27 = 1 ;
V_28 [ 0 ] = V_15 ? V_15 -> V_15 . V_16 . V_17 : V_11 -> V_15 . V_15 . V_16 . V_17 ;
V_29 [ 0 ] = V_11 -> V_32 ;
F_13 ( V_9 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_8 * V_9 = F_5 ( V_3 -> V_6 ) ;
struct V_1 * V_33 = F_1 ( V_5 ) ;
struct V_10 * V_11 ;
unsigned long V_34 ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
F_6 ( 2 , V_13 , L_4 ) ;
F_15 ( & V_11 -> V_35 , V_34 ) ;
F_16 ( & V_33 -> V_36 , & V_11 -> V_37 ) ;
F_17 ( & V_11 -> V_35 , V_34 ) ;
}
static int F_18 ( struct V_6 * V_24 , unsigned int V_38 )
{
struct V_39 * V_40 =
V_41 -> V_42 ;
struct V_8 * V_9 = F_5 ( V_24 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_43 * V_44 = & V_9 -> V_45 ;
struct V_1 * V_33 , * V_46 ;
unsigned long V_12 , V_34 ;
int V_47 ;
F_15 ( & V_11 -> V_35 , V_34 ) ;
V_9 -> V_48 = 0 ;
if ( V_40 -> V_49 ) {
V_47 = V_40 ->
V_49 ( V_44 -> V_50 . V_51 ) ;
if ( V_47 < 0 ) {
F_6 ( 1 , V_13 , L_5 ) ;
goto V_52;
}
}
V_47 = F_19 ( V_9 -> V_53 , V_54 , V_55 , 1 ) ;
if ( V_47 && V_47 != - V_56 && V_47 != - V_57 ) {
F_6 ( 1 , V_13 , L_6 ) ;
goto V_52;
}
V_47 = F_20 ( V_44 , V_9 -> V_58 ) ;
if ( V_47 < 0 ) {
F_6 ( 1 , V_13 , L_7 ) ;
goto V_52;
}
V_51 = V_47 ;
F_21 ( V_9 , V_47 ) ;
V_11 -> V_59 = V_11 -> V_60 = F_22 ( V_11 -> V_37 . V_61 ,
struct V_1 , V_36 ) ;
F_23 ( & V_11 -> V_59 -> V_36 ) ;
F_17 ( & V_11 -> V_35 , V_34 ) ;
V_12 = F_10 ( & V_11 -> V_59 -> V_3 . V_62 , 0 ) ;
V_11 -> V_63 ( V_12 + V_11 -> V_20 ,
V_12 + V_11 -> V_21 ,
V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ) ;
V_64 [ V_14 ] [ V_9 -> V_58 ] = 1 ;
if ( V_65 == V_9 -> V_58 ) {
F_24 () ;
F_25 ( 1 ) ;
F_26 ( 1 ) ;
}
if ( V_66 == V_9 -> V_58 ||
V_51 == 2 ) {
F_27 () ;
F_28 ( 1 ) ;
F_29 ( 1 ) ;
}
return 0 ;
V_52:
F_30 (buf, tmp, &common->dma_queue, list) {
F_23 ( & V_33 -> V_36 ) ;
F_31 ( & V_33 -> V_3 . V_62 , V_67 ) ;
}
F_17 ( & V_11 -> V_35 , V_34 ) ;
return V_47 ;
}
static void F_32 ( struct V_6 * V_24 )
{
struct V_8 * V_9 = F_5 ( V_24 ) ;
struct V_10 * V_11 ;
unsigned long V_34 ;
int V_47 ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( V_65 == V_9 -> V_58 ) {
F_26 ( 0 ) ;
F_25 ( 0 ) ;
}
if ( V_66 == V_9 -> V_58 ||
V_51 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
V_51 = 0 ;
V_47 = F_19 ( V_9 -> V_53 , V_54 , V_55 , 0 ) ;
if ( V_47 && V_47 != - V_56 && V_47 != - V_57 )
F_6 ( 1 , V_13 , L_8 ) ;
F_15 ( & V_11 -> V_35 , V_34 ) ;
if ( V_11 -> V_59 == V_11 -> V_60 ) {
F_31 ( & V_11 -> V_59 -> V_3 . V_62 ,
V_68 ) ;
} else {
if ( V_11 -> V_59 != NULL )
F_31 ( & V_11 -> V_59 -> V_3 . V_62 ,
V_68 ) ;
if ( V_11 -> V_60 != NULL )
F_31 ( & V_11 -> V_60 -> V_3 . V_62 ,
V_68 ) ;
}
while ( ! F_33 ( & V_11 -> V_37 ) ) {
V_11 -> V_60 = F_22 ( V_11 -> V_37 . V_61 ,
struct V_1 , V_36 ) ;
F_23 ( & V_11 -> V_60 -> V_36 ) ;
F_31 ( & V_11 -> V_60 -> V_3 . V_62 ,
V_68 ) ;
}
F_17 ( & V_11 -> V_35 , V_34 ) ;
}
static void F_34 ( struct V_10 * V_11 )
{
F_35 ( & V_11 -> V_59 -> V_3 . V_69 ) ;
F_31 ( & V_11 -> V_59 -> V_3 . V_62 , V_70 ) ;
V_11 -> V_59 = V_11 -> V_60 ;
}
static void F_36 ( struct V_10 * V_11 )
{
unsigned long V_12 = 0 ;
F_37 ( & V_11 -> V_35 ) ;
V_11 -> V_60 = F_22 ( V_11 -> V_37 . V_61 ,
struct V_1 , V_36 ) ;
F_23 ( & V_11 -> V_60 -> V_36 ) ;
F_38 ( & V_11 -> V_35 ) ;
V_12 = F_10 ( & V_11 -> V_60 -> V_3 . V_62 , 0 ) ;
V_11 -> V_63 ( V_12 + V_11 -> V_20 ,
V_12 + V_11 -> V_21 ,
V_12 + V_11 -> V_22 ,
V_12 + V_11 -> V_23 ) ;
}
static T_1 F_39 ( int V_71 , void * V_72 )
{
struct V_73 * V_74 = & V_75 ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_58 = 0 ;
int V_76 = - 1 , V_77 ;
V_58 = * ( int * ) ( V_72 ) ;
if ( ! F_40 ( V_58 ) )
return V_78 ;
V_9 = V_74 -> V_74 [ V_58 ] ;
for ( V_77 = 0 ; V_77 < V_79 ; V_77 ++ ) {
V_11 = & V_9 -> V_11 [ V_77 ] ;
if ( 1 == V_9 -> V_45 . V_50 . V_80 ) {
F_37 ( & V_11 -> V_35 ) ;
if ( F_33 ( & V_11 -> V_37 ) ) {
F_38 ( & V_11 -> V_35 ) ;
continue;
}
F_38 ( & V_11 -> V_35 ) ;
if ( ! V_64 [ V_77 ] [ V_58 ] )
F_34 ( V_11 ) ;
V_64 [ V_77 ] [ V_58 ] = 0 ;
F_36 ( V_11 ) ;
V_64 [ V_77 ] [ V_58 ] = 0 ;
} else {
if ( V_64 [ V_77 ] [ V_58 ] ) {
V_64 [ V_77 ] [ V_58 ] = 0 ;
continue;
}
if ( 0 == V_77 ) {
V_9 -> V_48 ^= 1 ;
V_76 = F_41 ( V_9 -> V_58 ) ;
if ( V_76 != V_9 -> V_48 ) {
if ( 0 == V_76 )
V_9 -> V_48 = V_76 ;
return V_81 ;
}
}
if ( 0 == V_76 ) {
if ( V_11 -> V_59 == V_11 -> V_60 )
continue;
F_34 ( V_11 ) ;
} else if ( 1 == V_76 ) {
F_37 ( & V_11 -> V_35 ) ;
if ( F_33 ( & V_11 -> V_37 ) ||
( V_11 -> V_59 != V_11 -> V_60 ) ) {
F_38 ( & V_11 -> V_35 ) ;
continue;
}
F_38 ( & V_11 -> V_35 ) ;
F_36 ( V_11 ) ;
}
}
}
return V_81 ;
}
static int F_42 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_43 * V_45 = & V_9 -> V_45 ;
const struct V_82 * V_83 ;
struct V_82 * V_50 = & V_45 -> V_50 ;
struct V_84 * V_85 = & V_9 -> V_54 ;
int V_86 ;
F_6 ( 2 , V_13 , L_9 ) ;
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ ) {
V_83 = & V_88 [ V_86 ] ;
if ( V_83 -> V_89 == 0 ) {
F_6 ( 2 , V_13 , L_10 ) ;
if ( V_83 -> V_90 & V_85 -> V_90 ) {
memcpy ( V_50 , V_83 , sizeof( * V_83 ) ) ;
break;
}
} else {
F_6 ( 2 , V_13 , L_11 ) ;
if ( ! memcmp ( & V_83 -> V_91 , & V_85 -> V_91 ,
sizeof( V_85 -> V_91 ) ) ) {
memcpy ( V_50 , V_83 , sizeof( * V_83 ) ) ;
break;
}
}
}
if ( V_86 == V_87 )
return - V_18 ;
V_11 -> V_15 . V_15 . V_16 . V_92 = V_50 -> V_92 ;
V_11 -> V_92 = V_50 -> V_92 ;
V_11 -> V_15 . V_15 . V_16 . V_93 = V_50 -> V_93 ;
V_11 -> V_93 = V_50 -> V_93 ;
V_11 -> V_15 . V_15 . V_16 . V_17 = V_11 -> V_93 * V_11 -> V_92 * 2 ;
V_11 -> V_15 . V_15 . V_16 . V_94 = V_50 -> V_92 ;
V_45 -> V_95 . V_96 = V_50 -> V_92 ;
V_45 -> V_95 . V_97 = V_50 -> V_80 ;
if ( V_85 -> V_90 )
V_11 -> V_15 . V_15 . V_16 . V_98 = V_99 ;
else
V_11 -> V_15 . V_15 . V_16 . V_98 = V_100 ;
if ( V_9 -> V_45 . V_50 . V_80 )
V_11 -> V_15 . V_15 . V_16 . V_19 = V_101 ;
else
V_11 -> V_15 . V_15 . V_16 . V_19 = V_102 ;
if ( V_9 -> V_45 . V_103 . V_104 == V_105 )
V_11 -> V_15 . V_15 . V_16 . V_106 = V_107 ;
else
V_11 -> V_15 . V_15 . V_16 . V_106 = V_108 ;
V_11 -> V_15 . type = V_109 ;
return 0 ;
}
static void F_13 ( struct V_8 * V_9 )
{
unsigned int V_96 , V_17 ;
struct V_84 * V_85 = & ( V_9 -> V_54 ) ;
struct V_43 * V_45 = & V_9 -> V_45 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
enum V_110 V_19 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
F_6 ( 2 , V_13 , L_12 ) ;
if ( V_111 == V_19 ) {
if ( V_45 -> V_50 . V_80 )
V_85 -> V_112 = V_101 ;
else
V_85 -> V_112 = V_102 ;
} else
V_85 -> V_112 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
V_17 = V_11 -> V_15 . V_15 . V_16 . V_17 ;
V_96 = V_11 -> V_15 . V_15 . V_16 . V_94 ;
if ( ( V_101 == V_85 -> V_112 ) ||
( V_102 == V_85 -> V_112 ) ) {
V_11 -> V_20 = 0 ;
V_11 -> V_21 = V_96 ;
V_11 -> V_22 = V_17 / 2 ;
V_11 -> V_23 = V_17 / 2 + V_96 ;
} else if ( V_113 == V_85 -> V_112 ) {
V_11 -> V_20 = 0 ;
V_11 -> V_21 = V_17 / 4 ;
V_11 -> V_22 = V_17 / 2 ;
V_11 -> V_23 = V_11 -> V_22 + V_17 / 4 ;
} else if ( V_114 == V_85 -> V_112 ) {
V_11 -> V_21 = 0 ;
V_11 -> V_20 = V_17 / 4 ;
V_11 -> V_23 = V_17 / 2 ;
V_11 -> V_22 = V_11 -> V_23 + V_17 / 4 ;
}
if ( ( V_101 == V_85 -> V_112 ) ||
( V_102 == V_85 -> V_112 ) )
V_45 -> V_95 . V_97 = 1 ;
else
V_45 -> V_95 . V_97 = 0 ;
if ( 1 == V_45 -> V_50 . V_80 )
V_45 -> V_95 . V_96 =
V_11 -> V_15 . V_15 . V_16 . V_94 ;
else {
if ( ( V_19 == V_111 )
|| ( V_19 == V_102 ) )
V_45 -> V_95 . V_96 =
V_11 -> V_15 . V_15 . V_16 . V_94 * 2 ;
else
V_45 -> V_95 . V_96 =
V_11 -> V_15 . V_15 . V_16 . V_94 ;
}
V_9 -> V_45 . V_95 . V_90 = V_45 -> V_50 . V_90 ;
}
static inline enum V_110 F_43 (
struct V_115 * V_103 )
{
return ( V_103 -> V_104 == V_105 ) ? V_101 :
V_102 ;
}
static void F_21 ( struct V_8 * V_9 , int V_116 )
{
struct V_10 * V_11 ;
F_6 ( 2 , V_13 , L_13 ) ;
V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
if ( V_66 == V_9 -> V_58 )
V_11 -> V_63 = V_117 ;
else if ( 2 == V_116 )
V_11 -> V_63 = V_118 ;
else
V_11 -> V_63 = V_119 ;
}
static int F_44 (
struct V_39 * V_120 ,
struct V_121 * V_122 ,
int V_123 )
{
struct V_124 * V_125 ;
const char * V_126 ;
int V_77 ;
F_6 ( 2 , V_13 , L_14 ) ;
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
static int F_45 (
struct V_39 * V_120 ,
struct V_8 * V_9 ,
int V_86 )
{
struct V_121 * V_122 =
& V_120 -> V_130 [ V_9 -> V_58 ] ;
struct V_124 * V_125 = NULL ;
struct V_131 * V_53 = NULL ;
T_2 V_132 = 0 , V_133 = 0 ;
int V_134 ;
int V_47 ;
V_134 = F_44 ( V_120 , V_122 , V_86 ) ;
if ( V_134 >= 0 ) {
V_53 = V_75 . V_53 [ V_134 ] ;
V_125 = & V_120 -> V_125 [ V_134 ] ;
}
if ( V_53 && V_120 -> V_135 ) {
V_47 = V_120 -> V_135 ( V_9 -> V_58 ,
V_125 -> V_129 ) ;
if ( V_47 < 0 ) {
F_6 ( 1 , V_13 , L_15 \
L_16 ,
V_125 -> V_129 , V_86 ) ;
return V_47 ;
}
}
if ( V_53 ) {
V_132 = V_122 -> V_127 [ V_86 ] . V_136 ;
V_133 = V_122 -> V_127 [ V_86 ] . V_137 ;
V_47 = F_19 ( V_53 , V_54 , V_138 ,
V_132 , V_133 , 0 ) ;
if ( V_47 < 0 && V_47 != - V_56 ) {
F_6 ( 1 , V_13 , L_17 ) ;
return V_47 ;
}
}
V_9 -> V_139 = V_86 ;
V_9 -> V_53 = V_53 ;
V_9 -> V_45 . V_103 = V_122 -> V_140 ;
V_9 -> V_141 . V_142 = V_122 -> V_127 [ V_86 ] . V_132 . V_143 ;
return 0 ;
}
static int F_46 ( struct V_144 * V_144 , void * V_145 , T_3 * V_146 )
{
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
int V_47 = 0 ;
F_6 ( 2 , V_13 , L_18 ) ;
V_47 = F_19 ( V_9 -> V_53 , V_54 , V_149 , V_146 ) ;
if ( V_47 == - V_56 || V_47 == - V_57 )
return - V_150 ;
if ( V_47 ) {
F_6 ( 1 , V_13 , L_19 ) ;
return V_47 ;
}
return 0 ;
}
static int F_49 ( struct V_144 * V_144 , void * V_145 , T_3 * V_143 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
F_6 ( 2 , V_13 , L_20 ) ;
if ( V_83 -> V_130 [ V_9 -> V_58 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
V_132 = V_122 -> V_127 [ V_9 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_153 )
return - V_150 ;
* V_143 = V_9 -> V_54 . V_90 ;
return 0 ;
}
static int F_50 ( struct V_144 * V_144 , void * V_145 , T_3 V_146 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_47 ;
F_6 ( 2 , V_13 , L_21 ) ;
if ( V_83 -> V_130 [ V_9 -> V_58 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
V_132 = V_122 -> V_127 [ V_9 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_153 )
return - V_150 ;
if ( F_51 ( & V_11 -> V_154 ) )
return - V_155 ;
V_9 -> V_54 . V_90 = V_146 ;
memset ( & V_9 -> V_54 . V_91 , 0 , sizeof( V_9 -> V_54 . V_91 ) ) ;
if ( F_42 ( V_9 ) ) {
F_52 ( L_22 ) ;
return - V_18 ;
}
V_47 = F_19 ( V_9 -> V_53 , V_54 , V_156 , V_146 ) ;
if ( V_47 && V_47 != - V_56 && V_47 != - V_57 ) {
F_6 ( 1 , V_13 , L_23 ) ;
return V_47 ;
}
return 0 ;
}
static int F_53 ( struct V_144 * V_144 , void * V_145 ,
struct V_151 * V_132 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_121 * V_122 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
if ( V_132 -> V_86 >= V_122 -> V_157 )
return - V_18 ;
memcpy ( V_132 , & V_122 -> V_127 [ V_132 -> V_86 ] . V_132 ,
sizeof( * V_132 ) ) ;
return 0 ;
}
static int F_54 ( struct V_144 * V_144 , void * V_145 , unsigned int * V_86 )
{
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
* V_86 = V_9 -> V_139 ;
return 0 ;
}
static int F_55 ( struct V_144 * V_144 , void * V_145 , unsigned int V_86 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_121 * V_122 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
if ( V_86 >= V_122 -> V_157 )
return - V_18 ;
if ( F_51 ( & V_11 -> V_154 ) )
return - V_155 ;
return F_45 ( V_83 , V_9 , V_86 ) ;
}
static int F_56 ( struct V_144 * V_144 , void * V_145 ,
struct V_158 * V_15 )
{
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
if ( V_15 -> V_86 != 0 ) {
F_6 ( 1 , V_13 , L_24 ) ;
return - V_18 ;
}
if ( V_9 -> V_45 . V_103 . V_104 == V_105 ) {
V_15 -> type = V_109 ;
strcpy ( V_15 -> V_159 , L_25 ) ;
V_15 -> V_106 = V_107 ;
} else {
V_15 -> type = V_109 ;
strcpy ( V_15 -> V_159 , L_26 ) ;
V_15 -> V_106 = V_108 ;
}
return 0 ;
}
static int F_57 ( struct V_144 * V_144 , void * V_145 ,
struct V_30 * V_15 )
{
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_160 * V_161 = & V_15 -> V_15 . V_16 ;
struct V_10 * V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
struct V_43 * V_43 = & V_9 -> V_45 ;
if ( V_43 -> V_103 . V_104 == V_105 ) {
if ( V_161 -> V_106 != V_107 )
V_161 -> V_106 = V_107 ;
} else {
if ( V_161 -> V_106 != V_108 )
V_161 -> V_106 = V_108 ;
}
V_11 -> V_15 . V_15 . V_16 . V_106 = V_161 -> V_106 ;
F_42 ( V_9 ) ;
V_161 -> V_19 = V_11 -> V_15 . V_15 . V_16 . V_19 ;
V_161 -> V_98 = V_11 -> V_15 . V_15 . V_16 . V_98 ;
V_161 -> V_94 = V_11 -> V_15 . V_15 . V_16 . V_92 ;
V_161 -> V_92 = V_11 -> V_15 . V_15 . V_16 . V_92 ;
V_161 -> V_93 = V_11 -> V_15 . V_15 . V_16 . V_93 ;
V_161 -> V_17 = V_161 -> V_94 * V_161 -> V_93 * 2 ;
V_161 -> V_145 = 0 ;
return 0 ;
}
static int F_58 ( struct V_144 * V_144 , void * V_145 ,
struct V_30 * V_15 )
{
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( V_11 -> V_15 . type != V_15 -> type )
return - V_18 ;
* V_15 = V_11 -> V_15 ;
return 0 ;
}
static int F_59 ( struct V_144 * V_144 , void * V_145 ,
struct V_30 * V_15 )
{
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
int V_47 ;
F_6 ( 2 , V_13 , L_27 , V_162 ) ;
if ( F_51 ( & V_11 -> V_154 ) )
return - V_155 ;
V_47 = F_57 ( V_144 , V_145 , V_15 ) ;
if ( V_47 )
return V_47 ;
V_11 -> V_15 = * V_15 ;
return 0 ;
}
static int F_60 ( struct V_144 * V_144 , void * V_145 ,
struct V_163 * V_164 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
V_164 -> V_165 = V_166 | V_167 ;
V_164 -> V_152 = V_164 -> V_165 | V_168 ;
F_61 ( V_164 -> V_169 , V_170 , sizeof( V_164 -> V_169 ) ) ;
snprintf ( V_164 -> V_171 , sizeof( V_164 -> V_171 ) , L_28 ,
F_62 ( V_41 ) ) ;
F_61 ( V_164 -> V_172 , V_83 -> V_173 , sizeof( V_164 -> V_172 ) ) ;
return 0 ;
}
static int
F_63 ( struct V_144 * V_144 , void * V_145 ,
struct V_174 * V_175 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_47 ;
if ( V_83 -> V_130 [ V_9 -> V_58 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
V_132 = V_122 -> V_127 [ V_9 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
V_175 -> V_177 = 0 ;
V_47 = F_19 ( V_9 -> V_53 , V_177 , V_178 , V_175 ) ;
if ( V_47 == - V_56 || V_47 == - V_57 )
return - V_18 ;
return V_47 ;
}
static int
F_64 ( struct V_144 * V_144 , void * V_145 ,
struct V_179 * V_175 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_47 ;
if ( V_83 -> V_130 [ V_9 -> V_58 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
V_132 = V_122 -> V_127 [ V_9 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
V_47 = F_19 ( V_9 -> V_53 , V_54 , V_180 , V_175 ) ;
if ( V_47 == - V_56 || V_47 == - V_57 )
return - V_150 ;
return V_47 ;
}
static int F_65 ( struct V_144 * V_144 , void * V_145 ,
struct V_179 * V_175 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_43 * V_45 = & V_9 -> V_45 ;
struct V_82 * V_50 = & V_45 -> V_50 ;
struct V_10 * V_11 = & V_9 -> V_11 [ V_14 ] ;
struct V_84 * V_85 = & V_9 -> V_54 ;
struct V_181 * V_182 = & V_85 -> V_91 . V_182 ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
int V_47 ;
if ( V_83 -> V_130 [ V_9 -> V_58 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
V_132 = V_122 -> V_127 [ V_9 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
if ( V_175 -> type != V_183 ) {
F_6 ( 2 , V_13 , L_29 ) ;
return - V_18 ;
}
if ( F_51 ( & V_11 -> V_154 ) )
return - V_155 ;
V_47 = F_19 ( V_9 -> V_53 , V_54 , V_184 , V_175 ) ;
if ( V_47 == - V_56 || V_47 == - V_57 )
V_47 = 0 ;
if ( V_47 < 0 ) {
F_6 ( 2 , V_13 , L_30 ) ;
return V_47 ;
}
if ( ! ( V_175 -> V_182 . V_92 && V_175 -> V_182 . V_93 &&
( V_175 -> V_182 . V_185 ||
V_175 -> V_182 . V_186 ||
V_175 -> V_182 . V_187 ) &&
V_175 -> V_182 . V_188 &&
( V_175 -> V_182 . V_189 ||
V_175 -> V_182 . V_190 ) ) ) {
F_6 ( 2 , V_13 , L_31
L_32
L_33
L_34
L_35 ) ;
return - V_18 ;
}
V_85 -> V_91 = * V_175 ;
V_50 -> V_191 = F_66 ( V_182 ) - 8 ;
V_50 -> V_192 = V_182 -> V_92 ;
V_50 -> V_193 = 1 ;
V_50 -> V_194 = V_182 -> V_190 + V_182 -> V_189 + 1 ;
V_50 -> V_195 = F_67 ( V_182 ) ;
if ( V_182 -> V_196 ) {
if ( V_182 -> V_197 || V_182 -> V_198 || V_182 -> V_199 ) {
V_50 -> V_200 = V_50 -> V_195 / 2 -
( V_182 -> V_188 - 1 ) ;
V_50 -> V_201 = V_50 -> V_195 / 2 + 1 ;
V_50 -> V_202 = V_50 -> V_201 + V_182 -> V_199 +
V_182 -> V_197 + 1 ;
V_50 -> V_203 = V_50 -> V_195 -
( V_182 -> V_198 - 1 ) ;
} else {
F_6 ( 2 , V_13 , L_36
L_37 ) ;
return - V_18 ;
}
} else {
V_50 -> V_200 = V_50 -> V_195 - ( V_182 -> V_188 - 1 ) ;
}
strncpy ( V_50 -> V_129 , L_38 , V_204 ) ;
V_50 -> V_92 = V_182 -> V_92 ;
V_50 -> V_93 = V_182 -> V_93 ;
V_50 -> V_80 = V_182 -> V_196 ? 0 : 1 ;
V_50 -> V_51 = 0 ;
V_50 -> V_205 = 0 ;
V_50 -> V_206 = 0 ;
V_50 -> V_89 = 1 ;
V_50 -> V_90 = 0 ;
V_85 -> V_90 = 0 ;
return 0 ;
}
static int F_68 ( struct V_144 * V_144 , void * V_145 ,
struct V_179 * V_175 )
{
struct V_39 * V_83 = V_41 -> V_42 ;
struct V_147 * V_148 = F_47 ( V_144 ) ;
struct V_8 * V_9 = F_48 ( V_148 ) ;
struct V_84 * V_85 = & V_9 -> V_54 ;
struct V_121 * V_122 ;
struct V_151 V_132 ;
if ( V_83 -> V_130 [ V_9 -> V_58 ] . V_127 == NULL )
return - V_150 ;
V_122 = & V_83 -> V_130 [ V_9 -> V_58 ] ;
V_132 = V_122 -> V_127 [ V_9 -> V_139 ] . V_132 ;
if ( V_132 . V_152 != V_176 )
return - V_150 ;
* V_175 = V_85 -> V_91 ;
return 0 ;
}
static int F_69 ( struct V_144 * V_207 , void * V_145 )
{
F_70 ( & V_75 . V_208 , 0 , V_209 , V_210 ) ;
return 0 ;
}
static int F_71 ( void )
{
int V_52 , V_77 , V_211 ;
int V_212 ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_75 . V_74 [ V_77 ] =
F_72 ( sizeof( * V_75 . V_74 [ V_77 ] ) , V_214 ) ;
if ( ! V_75 . V_74 [ V_77 ] ) {
V_212 = V_77 ;
V_52 = - V_215 ;
goto V_216;
}
}
return 0 ;
V_216:
for ( V_211 = 0 ; V_211 < V_212 ; V_211 ++ )
F_73 ( V_75 . V_74 [ V_211 ] ) ;
return V_52 ;
}
static int F_74 ( struct V_217 * V_218 ,
struct V_131 * V_219 ,
struct V_220 * V_221 )
{
int V_77 ;
for ( V_77 = 0 ; V_77 < V_75 . V_83 -> V_128 ; V_77 ++ )
if ( ! strcmp ( V_75 . V_83 -> V_125 [ V_77 ] . V_129 ,
V_219 -> V_129 ) ) {
V_75 . V_53 [ V_77 ] = V_219 ;
return 0 ;
}
return - V_18 ;
}
static int F_75 ( void )
{
struct V_10 * V_11 ;
struct V_147 * V_148 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_211 , V_52 , V_222 ;
for ( V_211 = 0 ; V_211 < V_213 ; V_211 ++ ) {
V_9 = V_75 . V_74 [ V_211 ] ;
V_9 -> V_58 = V_211 ;
V_11 = & ( V_9 -> V_11 [ V_14 ] ) ;
F_76 ( & V_11 -> V_35 ) ;
F_77 ( & V_11 -> V_223 ) ;
V_52 = F_45 ( V_75 . V_83 , V_9 , 0 ) ;
if ( V_52 )
goto V_224;
V_9 -> V_54 . V_90 = V_225 ;
memset ( & V_9 -> V_54 . V_91 , 0 , sizeof( V_9 -> V_54 . V_91 ) ) ;
F_42 ( V_9 ) ;
V_7 = & V_11 -> V_154 ;
V_7 -> type = V_109 ;
V_7 -> V_226 = V_227 | V_228 | V_229 ;
V_7 -> V_230 = V_9 ;
V_7 -> V_231 = & V_232 ;
V_7 -> V_233 = & V_234 ;
V_7 -> V_235 = sizeof( struct V_1 ) ;
V_7 -> V_236 = V_237 ;
V_7 -> V_238 = 1 ;
V_7 -> V_223 = & V_11 -> V_223 ;
V_52 = F_78 ( V_7 ) ;
if ( V_52 ) {
F_52 ( L_39 ) ;
goto V_224;
}
V_11 -> V_32 = F_79 ( V_41 ) ;
if ( F_80 ( V_11 -> V_32 ) ) {
F_52 ( L_40 ) ;
V_52 = F_81 ( V_11 -> V_32 ) ;
goto V_224;
}
F_82 ( & V_11 -> V_37 ) ;
V_148 = & V_9 -> V_141 ;
F_61 ( V_148 -> V_129 , V_170 , sizeof( V_148 -> V_129 ) ) ;
V_148 -> V_239 = V_240 ;
V_148 -> V_241 = & V_242 ;
V_148 -> V_243 = & V_244 ;
V_148 -> V_208 = & V_75 . V_208 ;
V_148 -> V_245 = V_246 ;
V_148 -> V_247 = V_7 ;
V_148 -> V_223 = & V_11 -> V_223 ;
F_83 ( & V_9 -> V_141 , V_9 ) ;
V_52 = F_84 ( V_148 ,
V_248 , ( V_211 ? 1 : 0 ) ) ;
if ( V_52 )
goto V_224;
}
F_85 ( & V_75 . V_208 , L_41 ) ;
return 0 ;
V_224:
for ( V_222 = 0 ; V_222 < V_211 ; V_222 ++ ) {
V_9 = V_75 . V_74 [ V_222 ] ;
V_11 = & V_9 -> V_11 [ V_222 ] ;
F_86 ( V_11 -> V_32 ) ;
F_87 ( & V_9 -> V_141 ) ;
}
F_73 ( V_75 . V_53 ) ;
F_88 ( & V_75 . V_208 ) ;
return V_52 ;
}
static int F_89 ( struct V_217 * V_218 )
{
return F_75 () ;
}
static T_4 int F_90 ( struct V_249 * V_250 )
{
struct V_124 * V_251 ;
struct V_252 * V_253 ;
struct V_254 * V_255 ;
int V_128 ;
int V_256 = 0 ;
int V_77 , V_52 ;
V_41 = & V_250 -> V_74 ;
V_52 = F_71 () ;
if ( V_52 ) {
F_91 ( V_41 -> V_169 , L_42 ) ;
return V_52 ;
}
V_52 = F_92 ( V_41 , & V_75 . V_208 ) ;
if ( V_52 ) {
F_91 ( V_41 -> V_169 , L_43 ) ;
return V_52 ;
}
while ( ( V_255 = F_93 ( V_250 , V_257 , V_256 ) ) ) {
V_52 = F_94 ( & V_250 -> V_74 , V_255 -> V_258 , F_39 ,
V_259 , V_170 ,
( void * ) ( & V_75 . V_74 [ V_256 ] ->
V_58 ) ) ;
if ( V_52 ) {
V_52 = - V_18 ;
goto V_260;
}
V_256 ++ ;
}
V_75 . V_83 = V_250 -> V_74 . V_42 ;
V_128 = V_75 . V_83 -> V_128 ;
V_75 . V_53 = F_72 ( sizeof( struct V_131 * ) * V_128 ,
V_214 ) ;
if ( V_75 . V_53 == NULL ) {
F_52 ( L_44 ) ;
V_52 = - V_215 ;
goto V_260;
}
if ( ! V_75 . V_83 -> V_261 ) {
V_253 = F_95 ( 1 ) ;
for ( V_77 = 0 ; V_77 < V_128 ; V_77 ++ ) {
V_251 = & V_75 . V_83 -> V_125 [ V_77 ] ;
V_75 . V_53 [ V_77 ] =
F_96 ( & V_75 . V_208 ,
V_253 ,
& V_251 ->
V_262 ,
NULL ) ;
if ( ! V_75 . V_53 [ V_77 ] ) {
F_52 ( L_45 ) ;
V_52 = - V_57 ;
goto V_263;
}
F_85 ( & V_75 . V_208 ,
L_46 ,
V_251 -> V_129 ) ;
}
F_75 () ;
} else {
V_75 . V_218 . V_264 = V_75 . V_83 -> V_221 ;
V_75 . V_218 . V_265 = V_75 . V_83 -> V_261 [ 0 ] ;
V_75 . V_218 . V_266 = F_74 ;
V_75 . V_218 . V_267 = F_89 ;
V_52 = F_97 ( & V_75 . V_208 ,
& V_75 . V_218 ) ;
if ( V_52 ) {
F_52 ( L_47 ) ;
V_52 = - V_18 ;
goto V_263;
}
}
return 0 ;
V_263:
F_73 ( V_75 . V_53 ) ;
V_260:
F_88 ( & V_75 . V_208 ) ;
return V_52 ;
}
static int F_98 ( struct V_249 * V_268 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_77 ;
F_88 ( & V_75 . V_208 ) ;
F_73 ( V_75 . V_53 ) ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_9 = V_75 . V_74 [ V_77 ] ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
F_86 ( V_11 -> V_32 ) ;
F_87 ( & V_9 -> V_141 ) ;
F_73 ( V_75 . V_74 [ V_77 ] ) ;
}
return 0 ;
}
static int F_99 ( struct V_268 * V_74 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_9 = V_75 . V_74 [ V_77 ] ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( ! F_100 ( & V_11 -> V_154 ) )
continue;
F_101 ( & V_11 -> V_223 ) ;
if ( V_9 -> V_58 == V_65 ) {
F_26 ( 0 ) ;
F_25 ( 0 ) ;
}
if ( V_9 -> V_58 == V_66 ||
V_51 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
F_102 ( & V_11 -> V_223 ) ;
}
return 0 ;
}
static int F_103 ( struct V_268 * V_74 )
{
struct V_10 * V_11 ;
struct V_8 * V_9 ;
int V_77 ;
for ( V_77 = 0 ; V_77 < V_213 ; V_77 ++ ) {
V_9 = V_75 . V_74 [ V_77 ] ;
V_11 = & V_9 -> V_11 [ V_14 ] ;
if ( ! F_100 ( & V_11 -> V_154 ) )
continue;
F_101 ( & V_11 -> V_223 ) ;
if ( V_9 -> V_58 == V_65 ) {
F_26 ( 1 ) ;
F_25 ( 1 ) ;
}
if ( V_9 -> V_58 == V_66 ||
V_51 == 2 ) {
F_29 ( 1 ) ;
F_28 ( 1 ) ;
}
F_102 ( & V_11 -> V_223 ) ;
}
return 0 ;
}
