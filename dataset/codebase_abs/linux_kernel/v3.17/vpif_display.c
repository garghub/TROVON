static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_4 ( V_3 -> V_6 ) ;
struct V_7 * V_8 ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
F_5 ( V_3 , 0 , V_8 -> V_10 . V_10 . V_11 . V_12 ) ;
if ( F_6 ( V_3 , 0 ) > F_7 ( V_3 , 0 ) )
return - V_13 ;
V_3 -> V_14 . V_15 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
if ( V_3 -> V_6 -> type != V_16 ) {
unsigned long V_17 = F_8 ( V_3 , 0 ) ;
if ( ! F_9 ( V_17 + V_8 -> V_18 ) ||
! F_9 ( V_17 + V_8 -> V_19 ) ||
! F_9 ( V_17 + V_8 -> V_20 ) ||
! F_9 ( V_17 + V_8 -> V_21 ) ) {
F_10 ( L_1 ) ;
return - V_13 ;
}
}
return 0 ;
}
static int F_11 ( struct V_6 * V_22 ,
const struct V_23 * V_10 ,
unsigned int * V_24 , unsigned int * V_25 ,
unsigned int V_26 [] , void * V_27 [] )
{
struct V_4 * V_5 = F_4 ( V_22 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_10 && V_10 -> V_10 . V_11 . V_12 < V_8 -> V_10 . V_10 . V_11 . V_12 )
return - V_13 ;
if ( V_22 -> V_28 + * V_24 < 3 )
* V_24 = 3 - V_22 -> V_28 ;
* V_25 = 1 ;
V_26 [ 0 ] = V_10 ? V_10 -> V_10 . V_11 . V_12 : V_8 -> V_10 . V_10 . V_11 . V_12 ;
V_27 [ 0 ] = V_8 -> V_29 ;
F_12 ( V_5 ) ;
return 0 ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_4 ( V_3 -> V_6 ) ;
struct V_7 * V_8 ;
unsigned long V_31 ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
F_14 ( & V_8 -> V_32 , V_31 ) ;
F_15 ( & V_30 -> V_33 , & V_8 -> V_34 ) ;
F_16 ( & V_8 -> V_32 , V_31 ) ;
}
static int F_17 ( struct V_6 * V_22 , unsigned int V_35 )
{
struct V_36 * V_37 =
V_38 -> V_39 ;
struct V_4 * V_5 = F_4 ( V_22 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_40 * V_41 = & V_5 -> V_42 ;
struct V_1 * V_30 , * V_43 ;
unsigned long V_17 , V_31 ;
int V_44 ;
F_14 ( & V_8 -> V_32 , V_31 ) ;
V_5 -> V_45 = 0 ;
if ( V_37 -> V_46 ) {
V_44 = V_37 -> V_46 ( V_5 -> V_42 . V_47 .
V_48 , V_5 -> V_42 . V_47 . V_49 ) ;
if ( V_44 < 0 ) {
F_10 ( L_2 ) ;
goto V_50;
}
}
V_44 = F_18 ( V_41 , V_5 -> V_51 + 2 ) ;
if ( V_44 < 0 )
goto V_50;
V_48 = V_44 ;
F_19 ( V_5 , V_44 ) ;
V_8 -> V_52 = V_8 -> V_53 =
F_20 ( V_8 -> V_34 . V_54 ,
struct V_1 , V_33 ) ;
F_21 ( & V_8 -> V_53 -> V_33 ) ;
F_16 ( & V_8 -> V_32 , V_31 ) ;
V_8 -> V_53 -> V_3 . V_55 = V_56 ;
V_17 = F_8 ( & V_8 -> V_53 -> V_3 , 0 ) ;
V_8 -> V_57 ( ( V_17 + V_8 -> V_18 ) ,
( V_17 + V_8 -> V_19 ) ,
( V_17 + V_8 -> V_20 ) ,
( V_17 + V_8 -> V_21 ) ) ;
V_58 [ V_9 ] [ V_5 -> V_51 ] = 1 ;
if ( V_59 == V_5 -> V_51 ) {
F_22 () ;
F_23 ( 1 ) ;
F_24 ( 1 ) ;
if ( V_37 -> V_60 [ V_59 ] . V_61 )
F_25 ( 1 ) ;
}
if ( V_62 == V_5 -> V_51 || V_48 == 2 ) {
F_26 () ;
F_27 ( 1 ) ;
F_28 ( 1 ) ;
if ( V_37 -> V_60 [ V_62 ] . V_61 )
F_29 ( 1 ) ;
}
return 0 ;
V_50:
F_30 (buf, tmp, &common->dma_queue, list) {
F_21 ( & V_30 -> V_33 ) ;
F_31 ( & V_30 -> V_3 , V_63 ) ;
}
F_16 ( & V_8 -> V_32 , V_31 ) ;
return V_44 ;
}
static void F_32 ( struct V_6 * V_22 )
{
struct V_4 * V_5 = F_4 ( V_22 ) ;
struct V_7 * V_8 ;
unsigned long V_31 ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_59 == V_5 -> V_51 ) {
F_24 ( 0 ) ;
F_23 ( 0 ) ;
}
if ( V_62 == V_5 -> V_51 || V_48 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
F_14 ( & V_8 -> V_32 , V_31 ) ;
if ( V_8 -> V_53 == V_8 -> V_52 ) {
F_31 ( & V_8 -> V_53 -> V_3 , V_64 ) ;
} else {
if ( V_8 -> V_53 != NULL )
F_31 ( & V_8 -> V_53 -> V_3 ,
V_64 ) ;
if ( V_8 -> V_52 != NULL )
F_31 ( & V_8 -> V_52 -> V_3 ,
V_64 ) ;
}
while ( ! F_33 ( & V_8 -> V_34 ) ) {
V_8 -> V_52 = F_20 ( V_8 -> V_34 . V_54 ,
struct V_1 , V_33 ) ;
F_21 ( & V_8 -> V_52 -> V_33 ) ;
F_31 ( & V_8 -> V_52 -> V_3 , V_64 ) ;
}
F_16 ( & V_8 -> V_32 , V_31 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
unsigned long V_17 = 0 ;
F_35 ( & V_8 -> V_32 ) ;
V_8 -> V_52 = F_20 ( V_8 -> V_34 . V_54 ,
struct V_1 , V_33 ) ;
F_21 ( & V_8 -> V_52 -> V_33 ) ;
F_36 ( & V_8 -> V_32 ) ;
V_8 -> V_52 -> V_3 . V_55 = V_56 ;
V_17 = F_8 ( & V_8 -> V_52 -> V_3 , 0 ) ;
V_8 -> V_57 ( V_17 + V_8 -> V_18 ,
V_17 + V_8 -> V_19 ,
V_17 + V_8 -> V_20 ,
V_17 + V_8 -> V_21 ) ;
}
static void F_37 ( int V_65 , struct V_7 * V_8 )
{
if ( 0 == V_65 ) {
if ( V_8 -> V_53 == V_8 -> V_52 )
return;
F_38 ( & V_8 -> V_53 -> V_3 . V_14 . V_66 ) ;
F_31 ( & V_8 -> V_53 -> V_3 ,
V_67 ) ;
V_8 -> V_53 = V_8 -> V_52 ;
} else if ( 1 == V_65 ) {
F_35 ( & V_8 -> V_32 ) ;
if ( F_33 ( & V_8 -> V_34 )
|| ( V_8 -> V_53 != V_8 -> V_52 ) ) {
F_36 ( & V_8 -> V_32 ) ;
return;
}
F_36 ( & V_8 -> V_32 ) ;
F_34 ( V_8 ) ;
}
}
static T_1 F_39 ( int V_68 , void * V_69 )
{
struct V_70 * V_71 = & V_72 ;
struct V_4 * V_5 ;
struct V_7 * V_8 ;
enum V_73 V_15 ;
int V_65 = - 1 , V_74 ;
int V_51 = 0 ;
V_51 = * ( int * ) ( V_69 ) ;
if ( ! F_40 ( V_51 + 2 ) )
return V_75 ;
V_5 = V_71 -> V_71 [ V_51 ] ;
V_15 = V_5 -> V_8 [ V_9 ] . V_10 . V_10 . V_11 . V_15 ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
V_8 = & V_5 -> V_8 [ V_74 ] ;
if ( 1 == V_5 -> V_42 . V_47 . V_77 ) {
F_35 ( & V_8 -> V_32 ) ;
if ( F_33 ( & V_8 -> V_34 ) ) {
F_36 ( & V_8 -> V_32 ) ;
continue;
}
F_36 ( & V_8 -> V_32 ) ;
if ( ! V_58 [ V_74 ] [ V_51 ] ) {
F_38 ( & V_8 -> V_53 -> V_3 .
V_14 . V_66 ) ;
F_31 ( & V_8 -> V_53 -> V_3 ,
V_67 ) ;
V_8 -> V_53 = V_8 -> V_52 ;
}
V_58 [ V_74 ] [ V_51 ] = 0 ;
F_34 ( V_8 ) ;
} else {
if ( V_58 [ V_74 ] [ V_51 ] ) {
V_58 [ V_74 ] [ V_51 ] = 0 ;
continue;
}
if ( 0 == V_74 ) {
V_5 -> V_45 ^= 1 ;
V_65 = F_41 ( V_5 -> V_51 + 2 ) ;
if ( V_65 != V_5 -> V_45 ) {
if ( 0 == V_65 )
V_5 -> V_45 = V_65 ;
return V_78 ;
}
}
F_37 ( V_65 , V_8 ) ;
}
}
return V_78 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_79 * V_80 = & V_5 -> V_81 ;
struct V_40 * V_42 = & V_5 -> V_42 ;
struct V_82 * V_47 = & V_42 -> V_47 ;
const struct V_82 * V_83 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_84 ; V_74 ++ ) {
V_83 = & V_85 [ V_74 ] ;
if ( V_83 -> V_49 == 0 ) {
F_43 ( 2 , V_86 , L_3 ) ;
if ( V_83 -> V_87 & V_80 -> V_87 ) {
memcpy ( V_47 , V_83 , sizeof( * V_83 ) ) ;
break;
}
}
}
if ( V_74 == V_84 ) {
F_43 ( 1 , V_86 , L_4 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_44 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_79 * V_80 = & V_5 -> V_81 ;
struct V_40 * V_42 = & V_5 -> V_42 ;
struct V_82 * V_47 = & V_42 -> V_47 ;
if ( ! V_80 -> V_87 && ! V_80 -> V_88 . V_89 . V_90 )
return - V_13 ;
if ( V_80 -> V_87 ) {
if ( F_42 ( V_5 ) )
return - V_13 ;
}
V_8 -> V_10 . V_10 . V_11 . V_91 = V_92 ;
V_8 -> V_10 . V_10 . V_11 . V_93 = V_47 -> V_93 ;
V_8 -> V_10 . V_10 . V_11 . V_90 = V_47 -> V_90 ;
F_43 ( 1 , V_86 , L_5 ,
V_8 -> V_10 . V_10 . V_11 . V_93 , V_8 -> V_10 . V_10 . V_11 . V_90 ) ;
V_8 -> V_90 = V_47 -> V_90 ;
V_8 -> V_93 = V_47 -> V_93 ;
V_8 -> V_10 . V_10 . V_11 . V_12 = V_8 -> V_90 * V_8 -> V_93 * 2 ;
if ( V_80 -> V_87 )
V_8 -> V_10 . V_10 . V_11 . V_94 = V_95 ;
else
V_8 -> V_10 . V_10 . V_11 . V_94 = V_96 ;
if ( V_5 -> V_42 . V_47 . V_77 )
V_8 -> V_10 . V_10 . V_11 . V_15 = V_97 ;
else
V_8 -> V_10 . V_10 . V_11 . V_15 = V_98 ;
return 0 ;
}
static void F_12 ( struct V_4 * V_5 )
{
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_40 * V_42 = & V_5 -> V_42 ;
enum V_73 V_15 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
struct V_79 * V_80 = & V_5 -> V_81 ;
unsigned int V_99 , V_100 , V_12 ;
if ( V_101 == V_8 -> V_10 . V_10 . V_11 . V_15 ) {
if ( V_5 -> V_42 . V_47 . V_77 )
V_80 -> V_102 = V_97 ;
else
V_80 -> V_102 = V_98 ;
} else {
V_80 -> V_102 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
}
V_12 = V_8 -> V_10 . V_10 . V_11 . V_12 ;
V_99 = V_8 -> V_10 . V_10 . V_11 . V_103 ;
V_100 = V_12 / ( V_99 * 2 ) ;
if ( ( V_97 == V_80 -> V_102 ) ||
( V_98 == V_80 -> V_102 ) ) {
V_8 -> V_18 = 0 ;
V_8 -> V_19 = V_99 ;
V_8 -> V_20 = V_12 / 2 ;
V_8 -> V_21 = V_12 / 2 + V_99 ;
} else if ( V_104 == V_80 -> V_102 ) {
V_8 -> V_18 = 0 ;
V_8 -> V_19 = V_12 / 4 ;
V_8 -> V_20 = V_12 / 2 ;
V_8 -> V_21 = V_8 -> V_20 + V_12 / 4 ;
} else if ( V_105 == V_80 -> V_102 ) {
V_8 -> V_19 = 0 ;
V_8 -> V_18 = V_12 / 4 ;
V_8 -> V_21 = V_12 / 2 ;
V_8 -> V_20 = V_8 -> V_21 + V_12 / 4 ;
}
if ( ( V_97 == V_80 -> V_102 ) ||
( V_98 == V_80 -> V_102 ) ) {
V_42 -> V_106 . V_107 = 1 ;
} else {
V_42 -> V_106 . V_107 = 0 ;
}
if ( V_5 -> V_42 . V_47 . V_77 == 1 ) {
V_42 -> V_106 . V_99 =
V_8 -> V_10 . V_10 . V_11 . V_103 ;
} else {
if ( ( V_15 == V_101 ) ||
( V_15 == V_98 ) )
V_42 -> V_106 . V_99 =
V_8 -> V_10 . V_10 . V_11 . V_103 * 2 ;
else
V_42 -> V_106 . V_99 =
V_8 -> V_10 . V_10 . V_11 . V_103 ;
}
V_5 -> V_42 . V_106 . V_87 = V_5 -> V_42 . V_47 . V_87 ;
}
static void F_19 ( struct V_4 * V_5 , int V_108 )
{
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_62 == V_5 -> V_51 ) {
V_8 -> V_57 = V_109 ;
} else {
if ( 2 == V_108 )
V_8 -> V_57 = V_110 ;
else
V_8 -> V_57 = V_111 ;
}
}
static int F_45 ( struct V_112 * V_112 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
V_115 -> V_116 = V_117 | V_118 ;
V_115 -> V_119 = V_115 -> V_116 | V_120 ;
F_46 ( V_115 -> V_121 , V_122 , sizeof( V_115 -> V_121 ) ) ;
snprintf ( V_115 -> V_123 , sizeof( V_115 -> V_123 ) , L_6 ,
F_47 ( V_38 ) ) ;
F_46 ( V_115 -> V_124 , V_83 -> V_125 , sizeof( V_115 -> V_124 ) ) ;
return 0 ;
}
static int F_48 ( struct V_112 * V_112 , void * V_113 ,
struct V_126 * V_10 )
{
if ( V_10 -> V_127 != 0 )
return - V_13 ;
V_10 -> type = V_128 ;
strcpy ( V_10 -> V_129 , L_7 ) ;
V_10 -> V_91 = V_92 ;
V_10 -> V_31 = 0 ;
return 0 ;
}
static int F_49 ( struct V_112 * V_112 , void * V_113 ,
struct V_23 * V_10 )
{
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( V_8 -> V_10 . type != V_10 -> type )
return - V_13 ;
if ( F_44 ( V_5 ) )
return - V_13 ;
* V_10 = V_8 -> V_10 ;
return 0 ;
}
static int F_52 ( struct V_112 * V_112 , void * V_113 ,
struct V_23 * V_10 )
{
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_132 * V_133 = & V_10 -> V_10 . V_11 ;
if ( V_133 -> V_91 != V_92 )
V_133 -> V_91 = V_8 -> V_10 . V_10 . V_11 . V_91 ;
if ( F_44 ( V_5 ) )
return - V_13 ;
V_133 -> V_94 = V_8 -> V_10 . V_10 . V_11 . V_94 ;
V_133 -> V_15 = V_8 -> V_10 . V_10 . V_11 . V_15 ;
V_133 -> V_103 = V_8 -> V_10 . V_10 . V_11 . V_93 ;
V_133 -> V_93 = V_8 -> V_10 . V_10 . V_11 . V_93 ;
V_133 -> V_90 = V_8 -> V_10 . V_10 . V_11 . V_90 ;
V_133 -> V_12 = V_133 -> V_103 * V_133 -> V_90 * 2 ;
return 0 ;
}
static int F_53 ( struct V_112 * V_112 , void * V_113 ,
struct V_23 * V_10 )
{
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_132 * V_133 = & V_10 -> V_10 . V_11 ;
int V_44 ;
if ( F_54 ( & V_8 -> V_134 ) )
return - V_135 ;
V_44 = F_52 ( V_112 , V_113 , V_10 ) ;
if ( V_44 )
return V_44 ;
V_8 -> V_10 . V_10 . V_11 = * V_133 ;
V_8 -> V_10 = * V_10 ;
return 0 ;
}
static int F_55 ( struct V_112 * V_112 , void * V_113 , T_2 V_136 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_44 ;
if ( V_83 -> V_60 [ V_5 -> V_51 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_60 [ V_5 -> V_51 ] ;
V_140 = V_138 -> V_141 [ V_5 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_144 )
return - V_142 ;
if ( F_54 ( & V_8 -> V_134 ) )
return - V_135 ;
if ( ! ( V_136 & V_145 ) )
return - V_13 ;
V_5 -> V_81 . V_87 = V_136 ;
memset ( & V_5 -> V_81 . V_88 , 0 , sizeof( V_5 -> V_81 . V_88 ) ) ;
if ( F_44 ( V_5 ) )
return - V_13 ;
V_8 -> V_10 . V_10 . V_11 . V_103 = V_8 -> V_10 . V_10 . V_11 . V_93 ;
V_44 = F_56 ( & V_72 . V_146 , 1 , V_81 ,
V_147 , V_136 ) ;
if ( V_44 < 0 ) {
F_10 ( L_8 ) ;
return V_44 ;
}
V_44 = F_56 ( & V_72 . V_146 , 1 , V_81 ,
V_148 , V_136 ) ;
if ( V_44 < 0 )
F_10 ( L_9 ) ;
return V_44 ;
}
static int F_57 ( struct V_112 * V_112 , void * V_113 , T_2 * V_149 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
if ( V_83 -> V_60 [ V_5 -> V_51 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_60 [ V_5 -> V_51 ] ;
V_140 = V_138 -> V_141 [ V_5 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_144 )
return - V_142 ;
* V_149 = V_5 -> V_81 . V_87 ;
return 0 ;
}
static int F_58 ( struct V_112 * V_112 , void * V_150 ,
struct V_139 * V_140 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_137 * V_138 ;
V_138 = & V_83 -> V_60 [ V_5 -> V_51 ] ;
if ( V_140 -> V_127 >= V_138 -> V_151 ) {
F_43 ( 1 , V_86 , L_10 ) ;
return - V_13 ;
}
* V_140 = V_138 -> V_141 [ V_140 -> V_127 ] . V_140 ;
return 0 ;
}
static int
F_59 ( struct V_36 * V_152 ,
struct V_137 * V_138 , int V_127 )
{
struct V_153 * V_154 ;
const char * V_155 ;
int V_74 ;
F_43 ( 2 , V_86 , L_11 ) ;
if ( V_138 -> V_141 == NULL )
return - 1 ;
V_155 = V_138 -> V_141 [ V_127 ] . V_155 ;
if ( V_155 == NULL )
return - 1 ;
for ( V_74 = 0 ; V_74 < V_152 -> V_156 ; V_74 ++ ) {
V_154 = & V_152 -> V_157 [ V_74 ] ;
if ( ! strcmp ( V_154 -> V_158 , V_155 ) )
return V_74 ;
}
return - 1 ;
}
static int F_60 ( struct V_36 * V_152 ,
struct V_4 * V_5 , int V_127 )
{
struct V_137 * V_138 =
& V_152 -> V_60 [ V_5 -> V_51 ] ;
struct V_153 * V_154 = NULL ;
struct V_159 * V_160 = NULL ;
T_3 V_161 = 0 , V_140 = 0 ;
int V_162 ;
int V_44 ;
V_162 = F_59 ( V_152 , V_138 , V_127 ) ;
if ( V_162 >= 0 ) {
V_160 = V_72 . V_160 [ V_162 ] ;
V_154 = & V_152 -> V_157 [ V_162 ] ;
}
if ( V_160 ) {
V_161 = V_138 -> V_141 [ V_127 ] . V_163 ;
V_140 = V_138 -> V_141 [ V_127 ] . V_164 ;
V_44 = F_61 ( V_160 , V_81 , V_165 , V_161 , V_140 , 0 ) ;
if ( V_44 < 0 && V_44 != - V_166 ) {
F_10 ( L_12 ) ;
return V_44 ;
}
}
V_5 -> V_143 = V_127 ;
V_5 -> V_160 = V_160 ;
if ( V_138 -> V_141 != NULL )
V_5 -> V_167 -> V_168 = V_138 -> V_141 [ V_127 ] . V_140 . V_149 ;
return 0 ;
}
static int F_62 ( struct V_112 * V_112 , void * V_113 , unsigned int V_74 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( F_54 ( & V_8 -> V_134 ) )
return - V_135 ;
V_138 = & V_83 -> V_60 [ V_5 -> V_51 ] ;
if ( V_74 >= V_138 -> V_151 )
return - V_13 ;
return F_60 ( V_83 , V_5 , V_74 ) ;
}
static int F_63 ( struct V_112 * V_112 , void * V_113 , unsigned int * V_74 )
{
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
* V_74 = V_5 -> V_143 ;
return 0 ;
}
static int
F_64 ( struct V_112 * V_112 , void * V_113 ,
struct V_169 * V_170 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_44 ;
if ( V_83 -> V_60 [ V_5 -> V_51 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_60 [ V_5 -> V_51 ] ;
V_140 = V_138 -> V_141 [ V_5 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_171 )
return - V_142 ;
V_170 -> V_172 = 0 ;
V_44 = F_61 ( V_5 -> V_160 , V_172 , V_173 , V_170 ) ;
if ( V_44 == - V_166 || V_44 == - V_174 )
return - V_13 ;
return V_44 ;
}
static int F_65 ( struct V_112 * V_112 , void * V_113 ,
struct V_175 * V_170 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_40 * V_42 = & V_5 -> V_42 ;
struct V_7 * V_8 = & V_5 -> V_8 [ V_9 ] ;
struct V_82 * V_47 = & V_42 -> V_47 ;
struct V_79 * V_80 = & V_5 -> V_81 ;
struct V_176 * V_89 = & V_80 -> V_88 . V_89 ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_44 ;
if ( V_83 -> V_60 [ V_5 -> V_51 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_60 [ V_5 -> V_51 ] ;
V_140 = V_138 -> V_141 [ V_5 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_171 )
return - V_142 ;
if ( F_54 ( & V_8 -> V_134 ) )
return - V_135 ;
if ( V_170 -> type != V_177 ) {
F_43 ( 2 , V_86 , L_13 ) ;
return - V_13 ;
}
V_44 = F_61 ( V_5 -> V_160 , V_81 , V_178 , V_170 ) ;
if ( V_44 == - V_166 || V_44 == - V_174 )
V_44 = 0 ;
if ( V_44 < 0 ) {
F_43 ( 2 , V_86 , L_14 ) ;
return V_44 ;
}
if ( ! ( V_170 -> V_89 . V_93 && V_170 -> V_89 . V_90 &&
( V_170 -> V_89 . V_179 ||
V_170 -> V_89 . V_180 ||
V_170 -> V_89 . V_181 ) &&
V_170 -> V_89 . V_182 &&
( V_170 -> V_89 . V_183 ||
V_170 -> V_89 . V_184 ) ) ) {
F_43 ( 2 , V_86 , L_15
L_16
L_17
L_18
L_19 ) ;
return - V_13 ;
}
V_80 -> V_88 = * V_170 ;
V_47 -> V_185 = F_66 ( V_89 ) - 8 ;
V_47 -> V_186 = V_89 -> V_93 ;
V_47 -> V_187 = 1 ;
V_47 -> V_188 = V_89 -> V_184 + V_89 -> V_183 + 1 ;
V_47 -> V_189 = F_67 ( V_89 ) ;
if ( V_89 -> V_190 ) {
if ( V_89 -> V_191 || V_89 -> V_192 || V_89 -> V_193 ) {
V_47 -> V_194 = V_47 -> V_189 / 2 -
( V_89 -> V_182 - 1 ) ;
V_47 -> V_195 = V_47 -> V_189 / 2 + 1 ;
V_47 -> V_196 = V_47 -> V_195 + V_89 -> V_193 +
V_89 -> V_191 + 1 ;
V_47 -> V_197 = V_47 -> V_189 -
( V_89 -> V_192 - 1 ) ;
} else {
F_43 ( 2 , V_86 , L_20
L_21 ) ;
return - V_13 ;
}
} else {
V_47 -> V_194 = V_47 -> V_189 - ( V_89 -> V_182 - 1 ) ;
}
strncpy ( V_47 -> V_158 , L_22 ,
V_198 ) ;
V_47 -> V_93 = V_89 -> V_93 ;
V_47 -> V_90 = V_89 -> V_90 ;
V_47 -> V_77 = V_89 -> V_190 ? 0 : 1 ;
V_47 -> V_48 = 0 ;
V_47 -> V_199 = 0 ;
V_47 -> V_200 = 0 ;
V_47 -> V_49 = 1 ;
V_47 -> V_87 = 0 ;
V_80 -> V_87 = 0 ;
return 0 ;
}
static int F_68 ( struct V_112 * V_112 , void * V_113 ,
struct V_175 * V_170 )
{
struct V_36 * V_83 = V_38 -> V_39 ;
struct V_130 * V_131 = F_50 ( V_112 ) ;
struct V_4 * V_5 = F_51 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_79 * V_80 = & V_5 -> V_81 ;
struct V_139 V_140 ;
if ( V_83 -> V_60 [ V_5 -> V_51 ] . V_141 == NULL )
goto error;
V_138 = & V_83 -> V_60 [ V_5 -> V_51 ] ;
V_140 = V_138 -> V_141 [ V_5 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_171 )
goto error;
* V_170 = V_80 -> V_88 ;
return 0 ;
error:
return - V_142 ;
}
static int F_69 ( struct V_112 * V_201 , void * V_113 )
{
F_70 ( & V_72 . V_146 , 0 , V_202 , V_203 ) ;
return 0 ;
}
static int F_71 ( void )
{
int V_204 ;
int V_50 , V_74 , V_205 ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_72 . V_71 [ V_74 ] =
F_72 ( sizeof( struct V_4 ) , V_207 ) ;
if ( ! V_72 . V_71 [ V_74 ] ) {
V_204 = V_74 ;
V_50 = - V_208 ;
goto V_209;
}
}
return 0 ;
V_209:
for ( V_205 = 0 ; V_205 < V_204 ; V_205 ++ )
F_73 ( V_72 . V_71 [ V_205 ] ) ;
return V_50 ;
}
static int F_74 ( struct V_210 * V_211 ,
struct V_159 * V_212 ,
struct V_213 * V_214 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_72 . V_83 -> V_156 ; V_74 ++ )
if ( ! strcmp ( V_72 . V_83 -> V_157 [ V_74 ] . V_158 ,
V_212 -> V_158 ) ) {
V_72 . V_160 [ V_74 ] = V_212 ;
V_72 . V_160 [ V_74 ] -> V_215 = 1 << V_74 ;
return 0 ;
}
return - V_13 ;
}
static int F_75 ( void )
{
struct V_7 * V_8 ;
struct V_130 * V_131 ;
struct V_4 * V_5 ;
struct V_6 * V_216 ;
int V_205 , V_50 , V_217 ;
for ( V_205 = 0 ; V_205 < V_206 ; V_205 ++ ) {
V_5 = V_72 . V_71 [ V_205 ] ;
for ( V_217 = 0 ; V_217 < V_76 ; V_217 ++ ) {
V_8 = & V_5 -> V_8 [ V_217 ] ;
F_76 ( & V_8 -> V_32 ) ;
F_77 ( & V_8 -> V_218 ) ;
V_8 -> V_57 = NULL ;
V_8 -> V_18 = 0 ;
V_8 -> V_19 = 0 ;
V_8 -> V_20 = 0 ;
V_8 -> V_21 = 0 ;
V_8 -> V_53 = NULL ;
V_8 -> V_52 = NULL ;
memset ( & V_8 -> V_10 , 0 , sizeof( V_8 -> V_10 ) ) ;
}
V_5 -> V_219 = 0 ;
if ( V_72 . V_83 -> V_156 )
V_5 -> V_160 = V_72 . V_160 [ 0 ] ;
V_5 -> V_51 = V_205 ;
memset ( & V_5 -> V_42 , 0 , sizeof( V_5 -> V_42 ) ) ;
V_5 -> V_8 [ V_9 ] . V_10 . type =
V_128 ;
V_50 = F_60 ( V_72 . V_83 , V_5 , 0 ) ;
if ( V_50 )
goto V_220;
V_5 -> V_81 . V_87 = V_221 ;
memset ( & V_5 -> V_81 . V_88 , 0 , sizeof( V_5 -> V_81 . V_88 ) ) ;
F_44 ( V_5 ) ;
V_216 = & V_8 -> V_134 ;
V_216 -> type = V_128 ;
V_216 -> V_222 = V_223 | V_224 | V_225 ;
V_216 -> V_226 = V_5 ;
V_216 -> V_227 = & V_228 ;
V_216 -> V_229 = & V_230 ;
V_216 -> V_231 = sizeof( struct V_1 ) ;
V_216 -> V_232 = V_233 ;
V_216 -> V_234 = 1 ;
V_216 -> V_218 = & V_8 -> V_218 ;
V_50 = F_78 ( V_216 ) ;
if ( V_50 ) {
F_10 ( L_23 ) ;
goto V_220;
}
V_8 -> V_29 = F_79 ( V_38 ) ;
if ( F_80 ( V_8 -> V_29 ) ) {
F_10 ( L_24 ) ;
V_50 = F_81 ( V_8 -> V_29 ) ;
goto V_220;
}
F_82 ( & V_8 -> V_34 ) ;
F_43 ( 1 , V_86 , L_25 ,
( int ) V_5 , ( int ) & V_5 -> V_167 ) ;
V_131 = V_5 -> V_167 ;
F_46 ( V_131 -> V_158 , V_122 , sizeof( V_131 -> V_158 ) ) ;
V_131 -> V_235 = V_236 ;
V_131 -> V_237 = & V_238 ;
V_131 -> V_239 = & V_240 ;
V_131 -> V_146 = & V_72 . V_146 ;
V_131 -> V_241 = V_242 ;
V_131 -> V_243 = V_216 ;
V_131 -> V_218 = & V_8 -> V_218 ;
F_83 ( V_5 -> V_167 , V_5 ) ;
V_50 = F_84 ( V_131 , V_244 ,
( V_205 ? 3 : 2 ) ) ;
if ( V_50 < 0 )
goto V_220;
}
return 0 ;
V_220:
for ( V_217 = 0 ; V_217 < V_205 ; V_217 ++ ) {
V_5 = V_72 . V_71 [ V_217 ] ;
V_8 = & V_5 -> V_8 [ V_217 ] ;
F_85 ( V_8 -> V_29 ) ;
F_86 ( V_5 -> V_167 ) ;
V_236 ( V_5 -> V_167 ) ;
V_5 -> V_167 = NULL ;
}
return V_50 ;
}
static int F_87 ( struct V_210 * V_211 )
{
return F_75 () ;
}
static T_4 int F_88 ( struct V_245 * V_246 )
{
struct V_153 * V_247 ;
int V_74 , V_205 = 0 , V_50 = 0 ;
int V_248 = 0 ;
struct V_249 * V_250 ;
struct V_4 * V_5 ;
struct V_130 * V_251 ;
struct V_252 * V_253 ;
int V_156 ;
V_38 = & V_246 -> V_71 ;
V_50 = F_71 () ;
if ( V_50 ) {
F_89 ( V_38 -> V_121 , L_26 ) ;
return V_50 ;
}
V_50 = F_90 ( V_38 , & V_72 . V_146 ) ;
if ( V_50 ) {
F_89 ( V_38 -> V_121 , L_27 ) ;
return V_50 ;
}
while ( ( V_253 = F_91 ( V_246 , V_254 , V_248 ) ) ) {
V_50 = F_92 ( & V_246 -> V_71 , V_253 -> V_255 , F_39 ,
V_256 , V_122 ,
( void * ) ( & V_72 . V_71 [ V_248 ] ->
V_51 ) ) ;
if ( V_50 ) {
V_50 = - V_13 ;
F_10 ( L_28 ) ;
goto V_257;
}
V_248 ++ ;
}
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_5 = V_72 . V_71 [ V_74 ] ;
V_251 = F_93 () ;
if ( V_251 == NULL ) {
for ( V_205 = 0 ; V_205 < V_74 ; V_205 ++ ) {
V_5 = V_72 . V_71 [ V_205 ] ;
V_236 ( V_5 -> V_167 ) ;
}
V_50 = - V_208 ;
goto V_257;
}
V_5 -> V_167 = V_251 ;
}
V_72 . V_83 = V_246 -> V_71 . V_39 ;
V_156 = V_72 . V_83 -> V_156 ;
V_247 = V_72 . V_83 -> V_157 ;
V_72 . V_160 = F_72 ( sizeof( struct V_159 * ) * V_156 ,
V_207 ) ;
if ( V_72 . V_160 == NULL ) {
F_10 ( L_29 ) ;
V_50 = - V_208 ;
goto V_258;
}
if ( ! V_72 . V_83 -> V_259 ) {
V_250 = F_94 ( 1 ) ;
for ( V_74 = 0 ; V_74 < V_156 ; V_74 ++ ) {
V_72 . V_160 [ V_74 ] =
F_95 ( & V_72 . V_146 ,
V_250 ,
& V_247 [ V_74 ] .
V_260 ,
NULL ) ;
if ( ! V_72 . V_160 [ V_74 ] ) {
F_10 ( L_30 ) ;
V_50 = - V_174 ;
goto V_261;
}
if ( V_72 . V_160 [ V_74 ] )
V_72 . V_160 [ V_74 ] -> V_215 = 1 << V_74 ;
}
F_75 () ;
} else {
V_72 . V_211 . V_262 = V_72 . V_83 -> V_214 ;
V_72 . V_211 . V_263 = V_72 . V_83 -> V_259 [ 0 ] ;
V_72 . V_211 . V_264 = F_74 ;
V_72 . V_211 . V_265 = F_87 ;
V_50 = F_96 ( & V_72 . V_146 ,
& V_72 . V_211 ) ;
if ( V_50 ) {
F_10 ( L_31 ) ;
V_50 = - V_13 ;
goto V_261;
}
}
return 0 ;
V_261:
F_73 ( V_72 . V_160 ) ;
V_258:
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_5 = V_72 . V_71 [ V_74 ] ;
V_236 ( V_5 -> V_167 ) ;
}
V_257:
F_97 ( & V_72 . V_146 ) ;
return V_50 ;
}
static int F_98 ( struct V_245 * V_266 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
int V_74 ;
F_97 ( & V_72 . V_146 ) ;
F_73 ( V_72 . V_160 ) ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_5 = V_72 . V_71 [ V_74 ] ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
F_85 ( V_8 -> V_29 ) ;
F_86 ( V_5 -> V_167 ) ;
V_5 -> V_167 = NULL ;
F_73 ( V_72 . V_71 [ V_74 ] ) ;
}
return 0 ;
}
static int F_99 ( struct V_266 * V_71 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_5 = V_72 . V_71 [ V_74 ] ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( ! F_100 ( & V_8 -> V_134 ) )
continue;
F_101 ( & V_8 -> V_218 ) ;
if ( V_5 -> V_51 == V_59 ) {
F_24 ( 0 ) ;
F_23 ( 0 ) ;
}
if ( V_5 -> V_51 == V_62 ||
V_48 == 2 ) {
F_28 ( 0 ) ;
F_27 ( 0 ) ;
}
F_102 ( & V_8 -> V_218 ) ;
}
return 0 ;
}
static int F_103 ( struct V_266 * V_71 )
{
struct V_7 * V_8 ;
struct V_4 * V_5 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_5 = V_72 . V_71 [ V_74 ] ;
V_8 = & V_5 -> V_8 [ V_9 ] ;
if ( ! F_100 ( & V_8 -> V_134 ) )
continue;
F_101 ( & V_8 -> V_218 ) ;
if ( V_5 -> V_51 == V_59 ) {
F_24 ( 1 ) ;
F_23 ( 1 ) ;
}
if ( V_5 -> V_51 == V_62 ||
V_48 == 2 ) {
F_28 ( 1 ) ;
F_27 ( 1 ) ;
}
F_102 ( & V_8 -> V_218 ) ;
}
return 0 ;
}
