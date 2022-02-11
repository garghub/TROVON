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
V_10 = F_9 ( & V_9 -> V_57 -> V_3 , 0 ) ;
V_9 -> V_60 ( V_10 + V_9 -> V_19 ,
V_10 + V_9 -> V_20 ,
V_10 + V_9 -> V_21 ,
V_10 + V_9 -> V_22 ) ;
V_61 [ V_12 ] [ V_7 -> V_56 ] = 1 ;
if ( V_62 == V_7 -> V_56 ) {
F_23 () ;
F_24 ( 1 ) ;
F_25 ( 1 ) ;
}
if ( V_63 == V_7 -> V_56 ||
V_49 == 2 ) {
F_26 () ;
F_27 ( 1 ) ;
F_28 ( 1 ) ;
}
return 0 ;
V_50:
F_29 (buf, tmp, &common->dma_queue, list) {
F_22 ( & V_31 -> V_34 ) ;
F_30 ( & V_31 -> V_3 , V_64 ) ;
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
if ( V_62 == V_7 -> V_56 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_63 == V_7 -> V_56 ||
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
F_30 ( & V_9 -> V_57 -> V_3 , V_65 ) ;
} else {
if ( V_9 -> V_57 != NULL )
F_30 ( & V_9 -> V_57 -> V_3 ,
V_65 ) ;
if ( V_9 -> V_58 != NULL )
F_30 ( & V_9 -> V_58 -> V_3 ,
V_65 ) ;
}
while ( ! F_32 ( & V_9 -> V_35 ) ) {
V_9 -> V_58 = F_21 ( V_9 -> V_35 . V_59 ,
struct V_1 , V_34 ) ;
F_22 ( & V_9 -> V_58 -> V_34 ) ;
F_30 ( & V_9 -> V_58 -> V_3 , V_65 ) ;
}
F_16 ( & V_9 -> V_33 , V_32 ) ;
}
static void F_33 ( struct V_8 * V_9 )
{
F_34 ( & V_9 -> V_57 -> V_3 . V_17 . V_66 ) ;
F_30 ( & V_9 -> V_57 -> V_3 ,
V_67 ) ;
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
V_10 = F_9 ( & V_9 -> V_58 -> V_3 , 0 ) ;
V_9 -> V_60 ( V_10 + V_9 -> V_19 ,
V_10 + V_9 -> V_20 ,
V_10 + V_9 -> V_21 ,
V_10 + V_9 -> V_22 ) ;
}
static T_1 F_38 ( int V_68 , void * V_69 )
{
struct V_70 * V_71 = & V_72 ;
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_56 = 0 ;
int V_73 = - 1 , V_74 ;
V_56 = * ( int * ) ( V_69 ) ;
if ( ! F_39 ( V_56 ) )
return V_75 ;
V_7 = V_71 -> V_71 [ V_56 ] ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
V_9 = & V_7 -> V_9 [ V_74 ] ;
if ( 1 == V_7 -> V_43 . V_48 . V_77 ) {
F_36 ( & V_9 -> V_33 ) ;
if ( F_32 ( & V_9 -> V_35 ) ) {
F_37 ( & V_9 -> V_33 ) ;
continue;
}
F_37 ( & V_9 -> V_33 ) ;
if ( ! V_61 [ V_74 ] [ V_56 ] )
F_33 ( V_9 ) ;
V_61 [ V_74 ] [ V_56 ] = 0 ;
F_35 ( V_9 ) ;
V_61 [ V_74 ] [ V_56 ] = 0 ;
} else {
if ( V_61 [ V_74 ] [ V_56 ] ) {
V_61 [ V_74 ] [ V_56 ] = 0 ;
continue;
}
if ( 0 == V_74 ) {
V_7 -> V_46 ^= 1 ;
V_73 = F_40 ( V_7 -> V_56 ) ;
if ( V_73 != V_7 -> V_46 ) {
if ( 0 == V_73 )
V_7 -> V_46 = V_73 ;
return V_78 ;
}
}
if ( 0 == V_73 ) {
if ( V_9 -> V_57 == V_9 -> V_58 )
continue;
F_33 ( V_9 ) ;
} else if ( 1 == V_73 ) {
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
return V_78 ;
}
static int F_41 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_41 * V_43 = & V_7 -> V_43 ;
const struct V_79 * V_80 ;
struct V_79 * V_48 = & V_43 -> V_48 ;
struct V_81 * V_82 = & V_7 -> V_52 ;
int V_83 ;
F_5 ( 2 , V_11 , L_9 ) ;
for ( V_83 = 0 ; V_83 < V_84 ; V_83 ++ ) {
V_80 = & V_85 [ V_83 ] ;
if ( V_80 -> V_86 == 0 ) {
F_5 ( 2 , V_11 , L_10 ) ;
if ( V_80 -> V_87 & V_82 -> V_87 ) {
memcpy ( V_48 , V_80 , sizeof( * V_80 ) ) ;
break;
}
} else {
F_5 ( 2 , V_11 , L_11 ) ;
if ( ! memcmp ( & V_80 -> V_88 , & V_82 -> V_88 ,
sizeof( V_82 -> V_88 ) ) ) {
memcpy ( V_48 , V_80 , sizeof( * V_80 ) ) ;
break;
}
}
}
if ( V_83 == V_84 )
return - V_16 ;
V_9 -> V_13 . V_13 . V_14 . V_89 = V_48 -> V_89 ;
V_9 -> V_89 = V_48 -> V_89 ;
V_9 -> V_13 . V_13 . V_14 . V_90 = V_48 -> V_90 ;
V_9 -> V_90 = V_48 -> V_90 ;
V_9 -> V_13 . V_13 . V_14 . V_15 = V_9 -> V_90 * V_9 -> V_89 * 2 ;
V_9 -> V_13 . V_13 . V_14 . V_91 = V_48 -> V_89 ;
V_43 -> V_92 . V_93 = V_48 -> V_89 ;
V_43 -> V_92 . V_94 = V_48 -> V_77 ;
if ( V_82 -> V_87 )
V_9 -> V_13 . V_13 . V_14 . V_95 = V_96 ;
else
V_9 -> V_13 . V_13 . V_14 . V_95 = V_97 ;
if ( V_7 -> V_43 . V_48 . V_77 )
V_9 -> V_13 . V_13 . V_14 . V_18 = V_98 ;
else
V_9 -> V_13 . V_13 . V_14 . V_18 = V_99 ;
if ( V_7 -> V_43 . V_100 . V_101 == V_102 )
V_9 -> V_13 . V_13 . V_14 . V_103 = V_104 ;
else
V_9 -> V_13 . V_13 . V_14 . V_103 = V_105 ;
V_9 -> V_13 . type = V_106 ;
return 0 ;
}
static void F_12 ( struct V_6 * V_7 )
{
unsigned int V_93 , V_15 ;
struct V_81 * V_82 = & ( V_7 -> V_52 ) ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
enum V_107 V_18 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
F_5 ( 2 , V_11 , L_12 ) ;
if ( V_108 == V_18 ) {
if ( V_43 -> V_48 . V_77 )
V_82 -> V_109 = V_98 ;
else
V_82 -> V_109 = V_99 ;
} else
V_82 -> V_109 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
V_15 = V_9 -> V_13 . V_13 . V_14 . V_15 ;
V_93 = V_9 -> V_13 . V_13 . V_14 . V_91 ;
if ( ( V_98 == V_82 -> V_109 ) ||
( V_99 == V_82 -> V_109 ) ) {
V_9 -> V_19 = 0 ;
V_9 -> V_20 = V_93 ;
V_9 -> V_21 = V_15 / 2 ;
V_9 -> V_22 = V_15 / 2 + V_93 ;
} else if ( V_110 == V_82 -> V_109 ) {
V_9 -> V_19 = 0 ;
V_9 -> V_20 = V_15 / 4 ;
V_9 -> V_21 = V_15 / 2 ;
V_9 -> V_22 = V_9 -> V_21 + V_15 / 4 ;
} else if ( V_111 == V_82 -> V_109 ) {
V_9 -> V_20 = 0 ;
V_9 -> V_19 = V_15 / 4 ;
V_9 -> V_22 = V_15 / 2 ;
V_9 -> V_21 = V_9 -> V_22 + V_15 / 4 ;
}
if ( ( V_98 == V_82 -> V_109 ) ||
( V_99 == V_82 -> V_109 ) )
V_43 -> V_92 . V_94 = 1 ;
else
V_43 -> V_92 . V_94 = 0 ;
if ( 1 == V_43 -> V_48 . V_77 )
V_43 -> V_92 . V_93 =
V_9 -> V_13 . V_13 . V_14 . V_91 ;
else {
if ( ( V_18 == V_108 )
|| ( V_18 == V_99 ) )
V_43 -> V_92 . V_93 =
V_9 -> V_13 . V_13 . V_14 . V_91 * 2 ;
else
V_43 -> V_92 . V_93 =
V_9 -> V_13 . V_13 . V_14 . V_91 ;
}
V_7 -> V_43 . V_92 . V_87 = V_43 -> V_48 . V_87 ;
}
static inline enum V_107 F_42 (
struct V_112 * V_100 )
{
return ( V_100 -> V_101 == V_102 ) ? V_98 :
V_99 ;
}
static void F_20 ( struct V_6 * V_7 , int V_113 )
{
struct V_8 * V_9 ;
F_5 ( 2 , V_11 , L_13 ) ;
V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
if ( V_63 == V_7 -> V_56 )
V_9 -> V_60 = V_114 ;
else if ( 2 == V_113 )
V_9 -> V_60 = V_115 ;
else
V_9 -> V_60 = V_116 ;
}
static int F_43 (
struct V_37 * V_117 ,
struct V_118 * V_119 ,
int V_120 )
{
struct V_121 * V_122 ;
const char * V_123 ;
int V_74 ;
F_5 ( 2 , V_11 , L_14 ) ;
V_123 = V_119 -> V_124 [ V_120 ] . V_123 ;
if ( V_123 == NULL )
return - 1 ;
for ( V_74 = 0 ; V_74 < V_117 -> V_125 ; V_74 ++ ) {
V_122 = & V_117 -> V_122 [ V_74 ] ;
if ( ! strcmp ( V_122 -> V_126 , V_123 ) )
return V_74 ;
}
return - 1 ;
}
static int F_44 (
struct V_37 * V_117 ,
struct V_6 * V_7 ,
int V_83 )
{
struct V_118 * V_119 =
& V_117 -> V_127 [ V_7 -> V_56 ] ;
struct V_121 * V_122 = NULL ;
struct V_128 * V_51 = NULL ;
T_2 V_129 = 0 , V_130 = 0 ;
int V_131 ;
int V_45 ;
V_131 = F_43 ( V_117 , V_119 , V_83 ) ;
if ( V_131 >= 0 ) {
V_51 = V_72 . V_51 [ V_131 ] ;
V_122 = & V_117 -> V_122 [ V_131 ] ;
}
if ( V_51 && V_117 -> V_132 ) {
V_45 = V_117 -> V_132 ( V_7 -> V_56 ,
V_122 -> V_126 ) ;
if ( V_45 < 0 ) {
F_5 ( 1 , V_11 , L_15 \
L_16 ,
V_122 -> V_126 , V_83 ) ;
return V_45 ;
}
}
if ( V_51 ) {
V_129 = V_119 -> V_124 [ V_83 ] . V_133 ;
V_130 = V_119 -> V_124 [ V_83 ] . V_134 ;
V_45 = F_18 ( V_51 , V_52 , V_135 ,
V_129 , V_130 , 0 ) ;
if ( V_45 < 0 && V_45 != - V_54 ) {
F_5 ( 1 , V_11 , L_17 ) ;
return V_45 ;
}
}
V_7 -> V_136 = V_83 ;
V_7 -> V_51 = V_51 ;
V_7 -> V_43 . V_100 = V_119 -> V_137 ;
V_7 -> V_138 . V_139 = V_119 -> V_124 [ V_83 ] . V_129 . V_140 ;
return 0 ;
}
static int F_45 ( struct V_141 * V_141 , void * V_142 , T_3 * V_143 )
{
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
int V_45 = 0 ;
F_5 ( 2 , V_11 , L_18 ) ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_146 , V_143 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_147 ;
if ( V_45 ) {
F_5 ( 1 , V_11 , L_19 ) ;
return V_45 ;
}
return 0 ;
}
static int F_48 ( struct V_141 * V_141 , void * V_142 , T_3 * V_140 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_118 * V_119 ;
struct V_148 V_129 ;
F_5 ( 2 , V_11 , L_20 ) ;
if ( V_80 -> V_127 [ V_7 -> V_56 ] . V_124 == NULL )
return - V_147 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
V_129 = V_119 -> V_124 [ V_7 -> V_136 ] . V_129 ;
if ( V_129 . V_149 != V_150 )
return - V_147 ;
* V_140 = V_7 -> V_52 . V_87 ;
return 0 ;
}
static int F_49 ( struct V_141 * V_141 , void * V_142 , T_3 V_143 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_118 * V_119 ;
struct V_148 V_129 ;
int V_45 ;
F_5 ( 2 , V_11 , L_21 ) ;
if ( V_80 -> V_127 [ V_7 -> V_56 ] . V_124 == NULL )
return - V_147 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
V_129 = V_119 -> V_124 [ V_7 -> V_136 ] . V_129 ;
if ( V_129 . V_149 != V_150 )
return - V_147 ;
if ( F_50 ( & V_9 -> V_151 ) )
return - V_152 ;
V_7 -> V_52 . V_87 = V_143 ;
memset ( & V_7 -> V_52 . V_88 , 0 , sizeof( V_7 -> V_52 . V_88 ) ) ;
if ( F_41 ( V_7 ) ) {
F_51 ( L_22 ) ;
return - V_16 ;
}
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_153 , V_143 ) ;
if ( V_45 && V_45 != - V_54 && V_45 != - V_55 ) {
F_5 ( 1 , V_11 , L_23 ) ;
return V_45 ;
}
return 0 ;
}
static int F_52 ( struct V_141 * V_141 , void * V_142 ,
struct V_148 * V_129 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_118 * V_119 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
if ( V_129 -> V_83 >= V_119 -> V_154 )
return - V_16 ;
memcpy ( V_129 , & V_119 -> V_124 [ V_129 -> V_83 ] . V_129 ,
sizeof( * V_129 ) ) ;
return 0 ;
}
static int F_53 ( struct V_141 * V_141 , void * V_142 , unsigned int * V_83 )
{
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
* V_83 = V_7 -> V_136 ;
return 0 ;
}
static int F_54 ( struct V_141 * V_141 , void * V_142 , unsigned int V_83 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_118 * V_119 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
if ( V_83 >= V_119 -> V_154 )
return - V_16 ;
if ( F_50 ( & V_9 -> V_151 ) )
return - V_152 ;
return F_44 ( V_80 , V_7 , V_83 ) ;
}
static int F_55 ( struct V_141 * V_141 , void * V_142 ,
struct V_155 * V_13 )
{
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
if ( V_13 -> V_83 != 0 ) {
F_5 ( 1 , V_11 , L_24 ) ;
return - V_16 ;
}
if ( V_7 -> V_43 . V_100 . V_101 == V_102 ) {
V_13 -> type = V_106 ;
strcpy ( V_13 -> V_156 , L_25 ) ;
V_13 -> V_103 = V_104 ;
} else {
V_13 -> type = V_106 ;
strcpy ( V_13 -> V_156 , L_26 ) ;
V_13 -> V_103 = V_105 ;
}
return 0 ;
}
static int F_56 ( struct V_141 * V_141 , void * V_142 ,
struct V_24 * V_13 )
{
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_157 * V_158 = & V_13 -> V_13 . V_14 ;
struct V_8 * V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
struct V_41 * V_41 = & V_7 -> V_43 ;
if ( V_41 -> V_100 . V_101 == V_102 ) {
if ( V_158 -> V_103 != V_104 )
V_158 -> V_103 = V_104 ;
} else {
if ( V_158 -> V_103 != V_105 )
V_158 -> V_103 = V_105 ;
}
V_9 -> V_13 . V_13 . V_14 . V_103 = V_158 -> V_103 ;
F_41 ( V_7 ) ;
V_158 -> V_18 = V_9 -> V_13 . V_13 . V_14 . V_18 ;
V_158 -> V_95 = V_9 -> V_13 . V_13 . V_14 . V_95 ;
V_158 -> V_91 = V_9 -> V_13 . V_13 . V_14 . V_89 ;
V_158 -> V_89 = V_9 -> V_13 . V_13 . V_14 . V_89 ;
V_158 -> V_90 = V_9 -> V_13 . V_13 . V_14 . V_90 ;
V_158 -> V_15 = V_158 -> V_91 * V_158 -> V_90 * 2 ;
V_158 -> V_142 = 0 ;
return 0 ;
}
static int F_57 ( struct V_141 * V_141 , void * V_142 ,
struct V_24 * V_13 )
{
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( V_9 -> V_13 . type != V_13 -> type )
return - V_16 ;
* V_13 = V_9 -> V_13 ;
return 0 ;
}
static int F_58 ( struct V_141 * V_141 , void * V_142 ,
struct V_24 * V_13 )
{
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
int V_45 ;
F_5 ( 2 , V_11 , L_27 , V_159 ) ;
if ( F_50 ( & V_9 -> V_151 ) )
return - V_152 ;
V_45 = F_56 ( V_141 , V_142 , V_13 ) ;
if ( V_45 )
return V_45 ;
V_9 -> V_13 = * V_13 ;
return 0 ;
}
static int F_59 ( struct V_141 * V_141 , void * V_142 ,
struct V_160 * V_161 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
V_161 -> V_162 = V_163 | V_164 ;
V_161 -> V_149 = V_161 -> V_162 | V_165 ;
F_60 ( V_161 -> V_166 , V_167 , sizeof( V_161 -> V_166 ) ) ;
snprintf ( V_161 -> V_168 , sizeof( V_161 -> V_168 ) , L_28 ,
F_61 ( V_39 ) ) ;
F_60 ( V_161 -> V_169 , V_80 -> V_170 , sizeof( V_161 -> V_169 ) ) ;
return 0 ;
}
static int
F_62 ( struct V_141 * V_141 , void * V_142 ,
struct V_171 * V_172 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_118 * V_119 ;
struct V_148 V_129 ;
int V_45 ;
if ( V_80 -> V_127 [ V_7 -> V_56 ] . V_124 == NULL )
return - V_147 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
V_129 = V_119 -> V_124 [ V_7 -> V_136 ] . V_129 ;
if ( V_129 . V_149 != V_173 )
return - V_147 ;
V_172 -> V_174 = 0 ;
V_45 = F_18 ( V_7 -> V_51 , V_174 , V_175 , V_172 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_16 ;
return V_45 ;
}
static int
F_63 ( struct V_141 * V_141 , void * V_142 ,
struct V_176 * V_172 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_118 * V_119 ;
struct V_148 V_129 ;
int V_45 ;
if ( V_80 -> V_127 [ V_7 -> V_56 ] . V_124 == NULL )
return - V_147 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
V_129 = V_119 -> V_124 [ V_7 -> V_136 ] . V_129 ;
if ( V_129 . V_149 != V_173 )
return - V_147 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_177 , V_172 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
return - V_147 ;
return V_45 ;
}
static int F_64 ( struct V_141 * V_141 , void * V_142 ,
struct V_176 * V_172 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_41 * V_43 = & V_7 -> V_43 ;
struct V_79 * V_48 = & V_43 -> V_48 ;
struct V_8 * V_9 = & V_7 -> V_9 [ V_12 ] ;
struct V_81 * V_82 = & V_7 -> V_52 ;
struct V_178 * V_179 = & V_82 -> V_88 . V_179 ;
struct V_118 * V_119 ;
struct V_148 V_129 ;
int V_45 ;
if ( V_80 -> V_127 [ V_7 -> V_56 ] . V_124 == NULL )
return - V_147 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
V_129 = V_119 -> V_124 [ V_7 -> V_136 ] . V_129 ;
if ( V_129 . V_149 != V_173 )
return - V_147 ;
if ( V_172 -> type != V_180 ) {
F_5 ( 2 , V_11 , L_29 ) ;
return - V_16 ;
}
if ( F_50 ( & V_9 -> V_151 ) )
return - V_152 ;
V_45 = F_18 ( V_7 -> V_51 , V_52 , V_181 , V_172 ) ;
if ( V_45 == - V_54 || V_45 == - V_55 )
V_45 = 0 ;
if ( V_45 < 0 ) {
F_5 ( 2 , V_11 , L_30 ) ;
return V_45 ;
}
if ( ! ( V_172 -> V_179 . V_89 && V_172 -> V_179 . V_90 &&
( V_172 -> V_179 . V_182 ||
V_172 -> V_179 . V_183 ||
V_172 -> V_179 . V_184 ) &&
V_172 -> V_179 . V_185 &&
( V_172 -> V_179 . V_186 ||
V_172 -> V_179 . V_187 ) ) ) {
F_5 ( 2 , V_11 , L_31
L_32
L_33
L_34
L_35 ) ;
return - V_16 ;
}
V_82 -> V_88 = * V_172 ;
V_48 -> V_188 = F_65 ( V_179 ) - 8 ;
V_48 -> V_189 = V_179 -> V_89 ;
V_48 -> V_190 = 1 ;
V_48 -> V_191 = V_179 -> V_187 + V_179 -> V_186 + 1 ;
V_48 -> V_192 = F_66 ( V_179 ) ;
if ( V_179 -> V_193 ) {
if ( V_179 -> V_194 || V_179 -> V_195 || V_179 -> V_196 ) {
V_48 -> V_197 = V_48 -> V_192 / 2 -
( V_179 -> V_185 - 1 ) ;
V_48 -> V_198 = V_48 -> V_192 / 2 + 1 ;
V_48 -> V_199 = V_48 -> V_198 + V_179 -> V_196 +
V_179 -> V_194 + 1 ;
V_48 -> V_200 = V_48 -> V_192 -
( V_179 -> V_195 - 1 ) ;
} else {
F_5 ( 2 , V_11 , L_36
L_37 ) ;
return - V_16 ;
}
} else {
V_48 -> V_197 = V_48 -> V_192 - ( V_179 -> V_185 - 1 ) ;
}
strncpy ( V_48 -> V_126 , L_38 , V_201 ) ;
V_48 -> V_89 = V_179 -> V_89 ;
V_48 -> V_90 = V_179 -> V_90 ;
V_48 -> V_77 = V_179 -> V_193 ? 0 : 1 ;
V_48 -> V_49 = 0 ;
V_48 -> V_202 = 0 ;
V_48 -> V_203 = 0 ;
V_48 -> V_86 = 1 ;
V_48 -> V_87 = 0 ;
V_82 -> V_87 = 0 ;
return 0 ;
}
static int F_67 ( struct V_141 * V_141 , void * V_142 ,
struct V_176 * V_172 )
{
struct V_37 * V_80 = V_39 -> V_40 ;
struct V_144 * V_145 = F_46 ( V_141 ) ;
struct V_6 * V_7 = F_47 ( V_145 ) ;
struct V_81 * V_82 = & V_7 -> V_52 ;
struct V_118 * V_119 ;
struct V_148 V_129 ;
if ( V_80 -> V_127 [ V_7 -> V_56 ] . V_124 == NULL )
return - V_147 ;
V_119 = & V_80 -> V_127 [ V_7 -> V_56 ] ;
V_129 = V_119 -> V_124 [ V_7 -> V_136 ] . V_129 ;
if ( V_129 . V_149 != V_173 )
return - V_147 ;
* V_172 = V_82 -> V_88 ;
return 0 ;
}
static int F_68 ( struct V_141 * V_204 , void * V_142 )
{
F_69 ( & V_72 . V_205 , 0 , V_206 , V_207 ) ;
return 0 ;
}
static int F_70 ( void )
{
int V_50 , V_74 , V_208 ;
int V_209 ;
for ( V_74 = 0 ; V_74 < V_210 ; V_74 ++ ) {
V_72 . V_71 [ V_74 ] =
F_71 ( sizeof( * V_72 . V_71 [ V_74 ] ) , V_211 ) ;
if ( ! V_72 . V_71 [ V_74 ] ) {
V_209 = V_74 ;
V_50 = - V_212 ;
goto V_213;
}
}
return 0 ;
V_213:
for ( V_208 = 0 ; V_208 < V_209 ; V_208 ++ )
F_72 ( V_72 . V_71 [ V_208 ] ) ;
return V_50 ;
}
static int F_73 ( struct V_214 * V_215 ,
struct V_128 * V_216 ,
struct V_217 * V_218 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_72 . V_80 -> V_125 ; V_74 ++ )
if ( ! strcmp ( V_72 . V_80 -> V_122 [ V_74 ] . V_126 ,
V_216 -> V_126 ) ) {
V_72 . V_51 [ V_74 ] = V_216 ;
return 0 ;
}
return - V_16 ;
}
static int F_74 ( void )
{
struct V_8 * V_9 ;
struct V_144 * V_145 ;
struct V_6 * V_7 ;
struct V_4 * V_5 ;
int V_208 , V_50 , V_219 ;
for ( V_208 = 0 ; V_208 < V_210 ; V_208 ++ ) {
V_7 = V_72 . V_71 [ V_208 ] ;
V_7 -> V_56 = V_208 ;
V_9 = & ( V_7 -> V_9 [ V_12 ] ) ;
F_75 ( & V_9 -> V_33 ) ;
F_76 ( & V_9 -> V_220 ) ;
V_50 = F_44 ( V_72 . V_80 , V_7 , 0 ) ;
if ( V_50 )
goto V_221;
V_7 -> V_52 . V_87 = V_222 ;
memset ( & V_7 -> V_52 . V_88 , 0 , sizeof( V_7 -> V_52 . V_88 ) ) ;
F_41 ( V_7 ) ;
V_5 = & V_9 -> V_151 ;
V_5 -> type = V_106 ;
V_5 -> V_223 = V_224 | V_225 | V_226 ;
V_5 -> V_227 = V_7 ;
V_5 -> V_228 = & V_229 ;
V_5 -> V_230 = & V_231 ;
V_5 -> V_232 = sizeof( struct V_1 ) ;
V_5 -> V_233 = V_234 ;
V_5 -> V_235 = 1 ;
V_5 -> V_220 = & V_9 -> V_220 ;
V_50 = F_77 ( V_5 ) ;
if ( V_50 ) {
F_51 ( L_39 ) ;
goto V_221;
}
V_9 -> V_30 = F_78 ( V_39 ) ;
if ( F_79 ( V_9 -> V_30 ) ) {
F_51 ( L_40 ) ;
V_50 = F_80 ( V_9 -> V_30 ) ;
goto V_221;
}
F_81 ( & V_9 -> V_35 ) ;
V_145 = & V_7 -> V_138 ;
F_60 ( V_145 -> V_126 , V_167 , sizeof( V_145 -> V_126 ) ) ;
V_145 -> V_236 = V_237 ;
V_145 -> V_238 = & V_239 ;
V_145 -> V_240 = & V_241 ;
V_145 -> V_205 = & V_72 . V_205 ;
V_145 -> V_242 = V_243 ;
V_145 -> V_244 = V_5 ;
V_145 -> V_220 = & V_9 -> V_220 ;
F_82 ( & V_7 -> V_138 , V_7 ) ;
V_50 = F_83 ( V_145 ,
V_245 , ( V_208 ? 1 : 0 ) ) ;
if ( V_50 )
goto V_221;
}
F_84 ( & V_72 . V_205 , L_41 ) ;
return 0 ;
V_221:
for ( V_219 = 0 ; V_219 < V_208 ; V_219 ++ ) {
V_7 = V_72 . V_71 [ V_219 ] ;
V_9 = & V_7 -> V_9 [ V_219 ] ;
F_85 ( V_9 -> V_30 ) ;
F_86 ( & V_7 -> V_138 ) ;
}
F_72 ( V_72 . V_51 ) ;
F_87 ( & V_72 . V_205 ) ;
return V_50 ;
}
static int F_88 ( struct V_214 * V_215 )
{
return F_74 () ;
}
static T_4 int F_89 ( struct V_246 * V_247 )
{
struct V_121 * V_248 ;
struct V_249 * V_250 ;
struct V_251 * V_252 ;
int V_125 ;
int V_253 = 0 ;
int V_74 , V_50 ;
V_39 = & V_247 -> V_71 ;
V_50 = F_70 () ;
if ( V_50 ) {
F_90 ( V_39 -> V_166 , L_42 ) ;
return V_50 ;
}
V_50 = F_91 ( V_39 , & V_72 . V_205 ) ;
if ( V_50 ) {
F_90 ( V_39 -> V_166 , L_43 ) ;
return V_50 ;
}
while ( ( V_252 = F_92 ( V_247 , V_254 , V_253 ) ) ) {
V_50 = F_93 ( & V_247 -> V_71 , V_252 -> V_255 , F_38 ,
V_256 , V_167 ,
( void * ) ( & V_72 . V_71 [ V_253 ] ->
V_56 ) ) ;
if ( V_50 ) {
V_50 = - V_16 ;
goto V_257;
}
V_253 ++ ;
}
V_72 . V_80 = V_247 -> V_71 . V_40 ;
V_125 = V_72 . V_80 -> V_125 ;
V_72 . V_51 = F_71 ( sizeof( struct V_128 * ) * V_125 ,
V_211 ) ;
if ( V_72 . V_51 == NULL ) {
F_51 ( L_44 ) ;
V_50 = - V_212 ;
goto V_257;
}
if ( ! V_72 . V_80 -> V_258 ) {
V_250 = F_94 ( 1 ) ;
for ( V_74 = 0 ; V_74 < V_125 ; V_74 ++ ) {
V_248 = & V_72 . V_80 -> V_122 [ V_74 ] ;
V_72 . V_51 [ V_74 ] =
F_95 ( & V_72 . V_205 ,
V_250 ,
& V_248 ->
V_259 ,
NULL ) ;
if ( ! V_72 . V_51 [ V_74 ] ) {
F_51 ( L_45 ) ;
V_50 = - V_55 ;
goto V_260;
}
F_84 ( & V_72 . V_205 ,
L_46 ,
V_248 -> V_126 ) ;
}
F_74 () ;
} else {
V_72 . V_215 . V_261 = V_72 . V_80 -> V_218 ;
V_72 . V_215 . V_262 = V_72 . V_80 -> V_258 [ 0 ] ;
V_72 . V_215 . V_263 = F_73 ;
V_72 . V_215 . V_264 = F_88 ;
V_50 = F_96 ( & V_72 . V_205 ,
& V_72 . V_215 ) ;
if ( V_50 ) {
F_51 ( L_47 ) ;
V_50 = - V_16 ;
goto V_260;
}
}
return 0 ;
V_260:
F_72 ( V_72 . V_51 ) ;
V_257:
F_87 ( & V_72 . V_205 ) ;
return V_50 ;
}
static int F_97 ( struct V_246 * V_265 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_74 ;
F_87 ( & V_72 . V_205 ) ;
F_72 ( V_72 . V_51 ) ;
for ( V_74 = 0 ; V_74 < V_210 ; V_74 ++ ) {
V_7 = V_72 . V_71 [ V_74 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
F_85 ( V_9 -> V_30 ) ;
F_86 ( & V_7 -> V_138 ) ;
F_72 ( V_72 . V_71 [ V_74 ] ) ;
}
return 0 ;
}
static int F_98 ( struct V_265 * V_71 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_210 ; V_74 ++ ) {
V_7 = V_72 . V_71 [ V_74 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( ! F_99 ( & V_9 -> V_151 ) )
continue;
F_100 ( & V_9 -> V_220 ) ;
if ( V_7 -> V_56 == V_62 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_7 -> V_56 == V_63 ||
V_49 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
F_101 ( & V_9 -> V_220 ) ;
}
return 0 ;
}
static int F_102 ( struct V_265 * V_71 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_210 ; V_74 ++ ) {
V_7 = V_72 . V_71 [ V_74 ] ;
V_9 = & V_7 -> V_9 [ V_12 ] ;
if ( ! F_99 ( & V_9 -> V_151 ) )
continue;
F_100 ( & V_9 -> V_220 ) ;
if ( V_7 -> V_56 == V_62 ) {
F_25 ( 1 ) ;
F_24 ( 1 ) ;
}
if ( V_7 -> V_56 == V_63 ||
V_49 == 2 ) {
F_28 ( 1 ) ;
F_27 ( 1 ) ;
}
F_101 ( & V_9 -> V_220 ) ;
}
return 0 ;
}
