static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_6 * V_7 = F_5 ( V_3 -> V_8 ) ;
struct V_9 * V_10 ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
F_6 ( V_3 , 0 , V_10 -> V_12 . V_12 . V_13 . V_14 ) ;
if ( F_7 ( V_3 , 0 ) > F_8 ( V_3 , 0 ) )
return - V_15 ;
V_5 -> V_16 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
if ( V_3 -> V_8 -> type != V_17 ) {
unsigned long V_18 = F_9 ( V_3 , 0 ) ;
if ( ! F_10 ( V_18 + V_10 -> V_19 ) ||
! F_10 ( V_18 + V_10 -> V_20 ) ||
! F_10 ( V_18 + V_10 -> V_21 ) ||
! F_10 ( V_18 + V_10 -> V_22 ) ) {
F_11 ( L_1 ) ;
return - V_15 ;
}
}
return 0 ;
}
static int F_12 ( struct V_8 * V_23 ,
const void * V_24 ,
unsigned int * V_25 , unsigned int * V_26 ,
unsigned int V_27 [] , void * V_28 [] )
{
const struct V_29 * V_12 = V_24 ;
struct V_6 * V_7 = F_5 ( V_23 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( V_12 && V_12 -> V_12 . V_13 . V_14 < V_10 -> V_12 . V_12 . V_13 . V_14 )
return - V_15 ;
if ( V_23 -> V_30 + * V_25 < 3 )
* V_25 = 3 - V_23 -> V_30 ;
* V_26 = 1 ;
V_27 [ 0 ] = V_12 ? V_12 -> V_12 . V_13 . V_14 : V_10 -> V_12 . V_12 . V_13 . V_14 ;
V_28 [ 0 ] = V_10 -> V_31 ;
F_13 ( V_7 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_3 )
{
struct V_2 * V_5 = F_4 ( V_3 ) ;
struct V_1 * V_32 = F_1 ( V_5 ) ;
struct V_6 * V_7 = F_5 ( V_3 -> V_8 ) ;
struct V_9 * V_10 ;
unsigned long V_33 ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
F_15 ( & V_10 -> V_34 , V_33 ) ;
F_16 ( & V_32 -> V_35 , & V_10 -> V_36 ) ;
F_17 ( & V_10 -> V_34 , V_33 ) ;
}
static int F_18 ( struct V_8 * V_23 , unsigned int V_37 )
{
struct V_38 * V_39 =
V_40 -> V_41 ;
struct V_6 * V_7 = F_5 ( V_23 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_42 * V_43 = & V_7 -> V_44 ;
struct V_1 * V_32 , * V_45 ;
unsigned long V_18 , V_33 ;
int V_46 ;
F_15 ( & V_10 -> V_34 , V_33 ) ;
V_7 -> V_47 = 0 ;
if ( V_39 -> V_48 ) {
V_46 = V_39 -> V_48 ( V_7 -> V_44 . V_49 .
V_50 , V_7 -> V_44 . V_49 . V_51 ) ;
if ( V_46 < 0 ) {
F_11 ( L_2 ) ;
goto V_52;
}
}
V_46 = F_19 ( V_43 , V_7 -> V_53 + 2 ) ;
if ( V_46 < 0 )
goto V_52;
V_50 = V_46 ;
F_20 ( V_7 , V_46 ) ;
V_10 -> V_54 = V_10 -> V_55 =
F_21 ( V_10 -> V_36 . V_56 ,
struct V_1 , V_35 ) ;
F_22 ( & V_10 -> V_55 -> V_35 ) ;
F_17 ( & V_10 -> V_34 , V_33 ) ;
V_18 = F_9 ( & V_10 -> V_55 -> V_3 . V_57 , 0 ) ;
V_10 -> V_58 ( ( V_18 + V_10 -> V_19 ) ,
( V_18 + V_10 -> V_20 ) ,
( V_18 + V_10 -> V_21 ) ,
( V_18 + V_10 -> V_22 ) ) ;
V_59 [ V_11 ] [ V_7 -> V_53 ] = 1 ;
if ( V_60 == V_7 -> V_53 ) {
F_23 () ;
F_24 ( 1 ) ;
F_25 ( 1 ) ;
if ( V_39 -> V_61 [ V_60 ] . V_62 )
F_26 ( 1 ) ;
}
if ( V_63 == V_7 -> V_53 || V_50 == 2 ) {
F_27 () ;
F_28 ( 1 ) ;
F_29 ( 1 ) ;
if ( V_39 -> V_61 [ V_63 ] . V_62 )
F_30 ( 1 ) ;
}
return 0 ;
V_52:
F_31 (buf, tmp, &common->dma_queue, list) {
F_22 ( & V_32 -> V_35 ) ;
F_32 ( & V_32 -> V_3 . V_57 , V_64 ) ;
}
F_17 ( & V_10 -> V_34 , V_33 ) ;
return V_46 ;
}
static void F_33 ( struct V_8 * V_23 )
{
struct V_6 * V_7 = F_5 ( V_23 ) ;
struct V_9 * V_10 ;
unsigned long V_33 ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( V_60 == V_7 -> V_53 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_63 == V_7 -> V_53 || V_50 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
F_15 ( & V_10 -> V_34 , V_33 ) ;
if ( V_10 -> V_55 == V_10 -> V_54 ) {
F_32 ( & V_10 -> V_55 -> V_3 . V_57 ,
V_65 ) ;
} else {
if ( V_10 -> V_55 != NULL )
F_32 ( & V_10 -> V_55 -> V_3 . V_57 ,
V_65 ) ;
if ( V_10 -> V_54 != NULL )
F_32 ( & V_10 -> V_54 -> V_3 . V_57 ,
V_65 ) ;
}
while ( ! F_34 ( & V_10 -> V_36 ) ) {
V_10 -> V_54 = F_21 ( V_10 -> V_36 . V_56 ,
struct V_1 , V_35 ) ;
F_22 ( & V_10 -> V_54 -> V_35 ) ;
F_32 ( & V_10 -> V_54 -> V_3 . V_57 ,
V_65 ) ;
}
F_17 ( & V_10 -> V_34 , V_33 ) ;
}
static void F_35 ( struct V_9 * V_10 )
{
unsigned long V_18 = 0 ;
F_36 ( & V_10 -> V_34 ) ;
V_10 -> V_54 = F_21 ( V_10 -> V_36 . V_56 ,
struct V_1 , V_35 ) ;
F_22 ( & V_10 -> V_54 -> V_35 ) ;
F_37 ( & V_10 -> V_34 ) ;
V_18 = F_9 ( & V_10 -> V_54 -> V_3 . V_57 , 0 ) ;
V_10 -> V_58 ( V_18 + V_10 -> V_19 ,
V_18 + V_10 -> V_20 ,
V_18 + V_10 -> V_21 ,
V_18 + V_10 -> V_22 ) ;
}
static void F_38 ( int V_66 , struct V_9 * V_10 )
{
if ( 0 == V_66 ) {
if ( V_10 -> V_55 == V_10 -> V_54 )
return;
F_39 ( & V_10 -> V_55 -> V_3 . V_67 ) ;
F_32 ( & V_10 -> V_55 -> V_3 . V_57 ,
V_68 ) ;
V_10 -> V_55 = V_10 -> V_54 ;
} else if ( 1 == V_66 ) {
F_36 ( & V_10 -> V_34 ) ;
if ( F_34 ( & V_10 -> V_36 )
|| ( V_10 -> V_55 != V_10 -> V_54 ) ) {
F_37 ( & V_10 -> V_34 ) ;
return;
}
F_37 ( & V_10 -> V_34 ) ;
F_35 ( V_10 ) ;
}
}
static T_1 F_40 ( int V_69 , void * V_70 )
{
struct V_71 * V_72 = & V_73 ;
struct V_6 * V_7 ;
struct V_9 * V_10 ;
int V_66 = - 1 , V_74 ;
int V_53 = 0 ;
V_53 = * ( int * ) ( V_70 ) ;
if ( ! F_41 ( V_53 + 2 ) )
return V_75 ;
V_7 = V_72 -> V_72 [ V_53 ] ;
for ( V_74 = 0 ; V_74 < V_76 ; V_74 ++ ) {
V_10 = & V_7 -> V_10 [ V_74 ] ;
if ( 1 == V_7 -> V_44 . V_49 . V_77 ) {
F_36 ( & V_10 -> V_34 ) ;
if ( F_34 ( & V_10 -> V_36 ) ) {
F_37 ( & V_10 -> V_34 ) ;
continue;
}
F_37 ( & V_10 -> V_34 ) ;
if ( ! V_59 [ V_74 ] [ V_53 ] ) {
F_39 (
& V_10 -> V_55 -> V_3 . V_67 ) ;
F_32 ( & V_10 -> V_55 -> V_3 . V_57 ,
V_68 ) ;
V_10 -> V_55 = V_10 -> V_54 ;
}
V_59 [ V_74 ] [ V_53 ] = 0 ;
F_35 ( V_10 ) ;
} else {
if ( V_59 [ V_74 ] [ V_53 ] ) {
V_59 [ V_74 ] [ V_53 ] = 0 ;
continue;
}
if ( 0 == V_74 ) {
V_7 -> V_47 ^= 1 ;
V_66 = F_42 ( V_7 -> V_53 + 2 ) ;
if ( V_66 != V_7 -> V_47 ) {
if ( 0 == V_66 )
V_7 -> V_47 = V_66 ;
return V_78 ;
}
}
F_38 ( V_66 , V_10 ) ;
}
}
return V_78 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_79 * V_80 = & V_7 -> V_81 ;
struct V_42 * V_44 = & V_7 -> V_44 ;
struct V_82 * V_49 = & V_44 -> V_49 ;
const struct V_82 * V_83 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_84 ; V_74 ++ ) {
V_83 = & V_85 [ V_74 ] ;
if ( V_83 -> V_51 == 0 ) {
F_44 ( 2 , V_86 , L_3 ) ;
if ( V_83 -> V_87 & V_80 -> V_87 ) {
memcpy ( V_49 , V_83 , sizeof( * V_83 ) ) ;
break;
}
}
}
if ( V_74 == V_84 ) {
F_44 ( 1 , V_86 , L_4 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_79 * V_80 = & V_7 -> V_81 ;
struct V_42 * V_44 = & V_7 -> V_44 ;
struct V_82 * V_49 = & V_44 -> V_49 ;
if ( ! V_80 -> V_87 && ! V_80 -> V_88 . V_89 . V_90 )
return - V_15 ;
if ( V_80 -> V_87 ) {
if ( F_43 ( V_7 ) )
return - V_15 ;
}
V_10 -> V_12 . V_12 . V_13 . V_91 = V_92 ;
V_10 -> V_12 . V_12 . V_13 . V_93 = V_49 -> V_93 ;
V_10 -> V_12 . V_12 . V_13 . V_90 = V_49 -> V_90 ;
F_44 ( 1 , V_86 , L_5 ,
V_10 -> V_12 . V_12 . V_13 . V_93 , V_10 -> V_12 . V_12 . V_13 . V_90 ) ;
V_10 -> V_90 = V_49 -> V_90 ;
V_10 -> V_93 = V_49 -> V_93 ;
V_10 -> V_12 . V_12 . V_13 . V_14 = V_10 -> V_90 * V_10 -> V_93 * 2 ;
if ( V_80 -> V_87 )
V_10 -> V_12 . V_12 . V_13 . V_94 = V_95 ;
else
V_10 -> V_12 . V_12 . V_13 . V_94 = V_96 ;
if ( V_7 -> V_44 . V_49 . V_77 )
V_10 -> V_12 . V_12 . V_13 . V_16 = V_97 ;
else
V_10 -> V_12 . V_12 . V_13 . V_16 = V_98 ;
return 0 ;
}
static void F_13 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_42 * V_44 = & V_7 -> V_44 ;
enum V_99 V_16 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
struct V_79 * V_80 = & V_7 -> V_81 ;
unsigned int V_100 , V_14 ;
if ( V_101 == V_10 -> V_12 . V_12 . V_13 . V_16 ) {
if ( V_7 -> V_44 . V_49 . V_77 )
V_80 -> V_102 = V_97 ;
else
V_80 -> V_102 = V_98 ;
} else {
V_80 -> V_102 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
}
V_14 = V_10 -> V_12 . V_12 . V_13 . V_14 ;
V_100 = V_10 -> V_12 . V_12 . V_13 . V_103 ;
if ( ( V_97 == V_80 -> V_102 ) ||
( V_98 == V_80 -> V_102 ) ) {
V_10 -> V_19 = 0 ;
V_10 -> V_20 = V_100 ;
V_10 -> V_21 = V_14 / 2 ;
V_10 -> V_22 = V_14 / 2 + V_100 ;
} else if ( V_104 == V_80 -> V_102 ) {
V_10 -> V_19 = 0 ;
V_10 -> V_20 = V_14 / 4 ;
V_10 -> V_21 = V_14 / 2 ;
V_10 -> V_22 = V_10 -> V_21 + V_14 / 4 ;
} else if ( V_105 == V_80 -> V_102 ) {
V_10 -> V_20 = 0 ;
V_10 -> V_19 = V_14 / 4 ;
V_10 -> V_22 = V_14 / 2 ;
V_10 -> V_21 = V_10 -> V_22 + V_14 / 4 ;
}
if ( ( V_97 == V_80 -> V_102 ) ||
( V_98 == V_80 -> V_102 ) ) {
V_44 -> V_106 . V_107 = 1 ;
} else {
V_44 -> V_106 . V_107 = 0 ;
}
if ( V_7 -> V_44 . V_49 . V_77 == 1 ) {
V_44 -> V_106 . V_100 =
V_10 -> V_12 . V_12 . V_13 . V_103 ;
} else {
if ( ( V_16 == V_101 ) ||
( V_16 == V_98 ) )
V_44 -> V_106 . V_100 =
V_10 -> V_12 . V_12 . V_13 . V_103 * 2 ;
else
V_44 -> V_106 . V_100 =
V_10 -> V_12 . V_12 . V_13 . V_103 ;
}
V_7 -> V_44 . V_106 . V_87 = V_7 -> V_44 . V_49 . V_87 ;
}
static void F_20 ( struct V_6 * V_7 , int V_108 )
{
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( V_63 == V_7 -> V_53 ) {
V_10 -> V_58 = V_109 ;
} else {
if ( 2 == V_108 )
V_10 -> V_58 = V_110 ;
else
V_10 -> V_58 = V_111 ;
}
}
static int F_46 ( struct V_112 * V_112 , void * V_113 ,
struct V_114 * V_115 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
V_115 -> V_116 = V_117 | V_118 ;
V_115 -> V_119 = V_115 -> V_116 | V_120 ;
F_47 ( V_115 -> V_121 , V_122 , sizeof( V_115 -> V_121 ) ) ;
snprintf ( V_115 -> V_123 , sizeof( V_115 -> V_123 ) , L_6 ,
F_48 ( V_40 ) ) ;
F_47 ( V_115 -> V_124 , V_83 -> V_125 , sizeof( V_115 -> V_124 ) ) ;
return 0 ;
}
static int F_49 ( struct V_112 * V_112 , void * V_113 ,
struct V_126 * V_12 )
{
if ( V_12 -> V_127 != 0 )
return - V_15 ;
V_12 -> type = V_128 ;
strcpy ( V_12 -> V_129 , L_7 ) ;
V_12 -> V_91 = V_92 ;
V_12 -> V_33 = 0 ;
return 0 ;
}
static int F_50 ( struct V_112 * V_112 , void * V_113 ,
struct V_29 * V_12 )
{
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( V_10 -> V_12 . type != V_12 -> type )
return - V_15 ;
if ( F_45 ( V_7 ) )
return - V_15 ;
* V_12 = V_10 -> V_12 ;
return 0 ;
}
static int F_53 ( struct V_112 * V_112 , void * V_113 ,
struct V_29 * V_12 )
{
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_132 * V_133 = & V_12 -> V_12 . V_13 ;
if ( V_133 -> V_91 != V_92 )
V_133 -> V_91 = V_10 -> V_12 . V_12 . V_13 . V_91 ;
if ( F_45 ( V_7 ) )
return - V_15 ;
V_133 -> V_94 = V_10 -> V_12 . V_12 . V_13 . V_94 ;
V_133 -> V_16 = V_10 -> V_12 . V_12 . V_13 . V_16 ;
V_133 -> V_103 = V_10 -> V_12 . V_12 . V_13 . V_93 ;
V_133 -> V_93 = V_10 -> V_12 . V_12 . V_13 . V_93 ;
V_133 -> V_90 = V_10 -> V_12 . V_12 . V_13 . V_90 ;
V_133 -> V_14 = V_133 -> V_103 * V_133 -> V_90 * 2 ;
return 0 ;
}
static int F_54 ( struct V_112 * V_112 , void * V_113 ,
struct V_29 * V_12 )
{
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_132 * V_133 = & V_12 -> V_12 . V_13 ;
int V_46 ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
V_46 = F_53 ( V_112 , V_113 , V_12 ) ;
if ( V_46 )
return V_46 ;
V_10 -> V_12 . V_12 . V_13 = * V_133 ;
V_10 -> V_12 = * V_12 ;
return 0 ;
}
static int F_56 ( struct V_112 * V_112 , void * V_113 , T_2 V_136 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_46 ;
if ( V_83 -> V_61 [ V_7 -> V_53 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_61 [ V_7 -> V_53 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_144 )
return - V_142 ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
if ( ! ( V_136 & V_145 ) )
return - V_15 ;
V_7 -> V_81 . V_87 = V_136 ;
memset ( & V_7 -> V_81 . V_88 , 0 , sizeof( V_7 -> V_81 . V_88 ) ) ;
if ( F_45 ( V_7 ) )
return - V_15 ;
V_10 -> V_12 . V_12 . V_13 . V_103 = V_10 -> V_12 . V_12 . V_13 . V_93 ;
V_46 = F_57 ( & V_73 . V_146 , 1 , V_81 ,
V_147 , V_136 ) ;
if ( V_46 < 0 ) {
F_11 ( L_8 ) ;
return V_46 ;
}
V_46 = F_57 ( & V_73 . V_146 , 1 , V_81 ,
V_148 , V_136 ) ;
if ( V_46 < 0 )
F_11 ( L_9 ) ;
return V_46 ;
}
static int F_58 ( struct V_112 * V_112 , void * V_113 , T_2 * V_149 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
if ( V_83 -> V_61 [ V_7 -> V_53 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_61 [ V_7 -> V_53 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_144 )
return - V_142 ;
* V_149 = V_7 -> V_81 . V_87 ;
return 0 ;
}
static int F_59 ( struct V_112 * V_112 , void * V_150 ,
struct V_139 * V_140 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
V_138 = & V_83 -> V_61 [ V_7 -> V_53 ] ;
if ( V_140 -> V_127 >= V_138 -> V_151 ) {
F_44 ( 1 , V_86 , L_10 ) ;
return - V_15 ;
}
* V_140 = V_138 -> V_141 [ V_140 -> V_127 ] . V_140 ;
return 0 ;
}
static int
F_60 ( struct V_38 * V_152 ,
struct V_137 * V_138 , int V_127 )
{
struct V_153 * V_154 ;
const char * V_155 ;
int V_74 ;
F_44 ( 2 , V_86 , L_11 ) ;
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
static int F_61 ( struct V_38 * V_152 ,
struct V_6 * V_7 , int V_127 )
{
struct V_137 * V_138 =
& V_152 -> V_61 [ V_7 -> V_53 ] ;
struct V_159 * V_160 = NULL ;
T_3 V_161 = 0 , V_140 = 0 ;
int V_162 ;
int V_46 ;
V_162 = F_60 ( V_152 , V_138 , V_127 ) ;
if ( V_162 >= 0 )
V_160 = V_73 . V_160 [ V_162 ] ;
if ( V_160 ) {
V_161 = V_138 -> V_141 [ V_127 ] . V_163 ;
V_140 = V_138 -> V_141 [ V_127 ] . V_164 ;
V_46 = F_62 ( V_160 , V_81 , V_165 , V_161 , V_140 , 0 ) ;
if ( V_46 < 0 && V_46 != - V_166 ) {
F_11 ( L_12 ) ;
return V_46 ;
}
}
V_7 -> V_143 = V_127 ;
V_7 -> V_160 = V_160 ;
if ( V_138 -> V_141 != NULL )
V_7 -> V_167 . V_168 = V_138 -> V_141 [ V_127 ] . V_140 . V_149 ;
return 0 ;
}
static int F_63 ( struct V_112 * V_112 , void * V_113 , unsigned int V_74 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
V_138 = & V_83 -> V_61 [ V_7 -> V_53 ] ;
if ( V_74 >= V_138 -> V_151 )
return - V_15 ;
return F_61 ( V_83 , V_7 , V_74 ) ;
}
static int F_64 ( struct V_112 * V_112 , void * V_113 , unsigned int * V_74 )
{
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
* V_74 = V_7 -> V_143 ;
return 0 ;
}
static int
F_65 ( struct V_112 * V_112 , void * V_113 ,
struct V_169 * V_170 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_46 ;
if ( V_83 -> V_61 [ V_7 -> V_53 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_61 [ V_7 -> V_53 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_171 )
return - V_142 ;
V_170 -> V_172 = 0 ;
V_46 = F_62 ( V_7 -> V_160 , V_172 , V_173 , V_170 ) ;
if ( V_46 == - V_166 || V_46 == - V_174 )
return - V_15 ;
return V_46 ;
}
static int F_66 ( struct V_112 * V_112 , void * V_113 ,
struct V_175 * V_170 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_42 * V_44 = & V_7 -> V_44 ;
struct V_9 * V_10 = & V_7 -> V_10 [ V_11 ] ;
struct V_82 * V_49 = & V_44 -> V_49 ;
struct V_79 * V_80 = & V_7 -> V_81 ;
struct V_176 * V_89 = & V_80 -> V_88 . V_89 ;
struct V_137 * V_138 ;
struct V_139 V_140 ;
int V_46 ;
if ( V_83 -> V_61 [ V_7 -> V_53 ] . V_141 == NULL )
return - V_142 ;
V_138 = & V_83 -> V_61 [ V_7 -> V_53 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_171 )
return - V_142 ;
if ( F_55 ( & V_10 -> V_134 ) )
return - V_135 ;
if ( V_170 -> type != V_177 ) {
F_44 ( 2 , V_86 , L_13 ) ;
return - V_15 ;
}
V_46 = F_62 ( V_7 -> V_160 , V_81 , V_178 , V_170 ) ;
if ( V_46 == - V_166 || V_46 == - V_174 )
V_46 = 0 ;
if ( V_46 < 0 ) {
F_44 ( 2 , V_86 , L_14 ) ;
return V_46 ;
}
if ( ! ( V_170 -> V_89 . V_93 && V_170 -> V_89 . V_90 &&
( V_170 -> V_89 . V_179 ||
V_170 -> V_89 . V_180 ||
V_170 -> V_89 . V_181 ) &&
V_170 -> V_89 . V_182 &&
( V_170 -> V_89 . V_183 ||
V_170 -> V_89 . V_184 ) ) ) {
F_44 ( 2 , V_86 , L_15
L_16
L_17
L_18
L_19 ) ;
return - V_15 ;
}
V_80 -> V_88 = * V_170 ;
V_49 -> V_185 = F_67 ( V_89 ) - 8 ;
V_49 -> V_186 = V_89 -> V_93 ;
V_49 -> V_187 = 1 ;
V_49 -> V_188 = V_89 -> V_184 + V_89 -> V_183 + 1 ;
V_49 -> V_189 = F_68 ( V_89 ) ;
if ( V_89 -> V_190 ) {
if ( V_89 -> V_191 || V_89 -> V_192 || V_89 -> V_193 ) {
V_49 -> V_194 = V_49 -> V_189 / 2 -
( V_89 -> V_182 - 1 ) ;
V_49 -> V_195 = V_49 -> V_189 / 2 + 1 ;
V_49 -> V_196 = V_49 -> V_195 + V_89 -> V_193 +
V_89 -> V_191 + 1 ;
V_49 -> V_197 = V_49 -> V_189 -
( V_89 -> V_192 - 1 ) ;
} else {
F_44 ( 2 , V_86 , L_20
L_21 ) ;
return - V_15 ;
}
} else {
V_49 -> V_194 = V_49 -> V_189 - ( V_89 -> V_182 - 1 ) ;
}
strncpy ( V_49 -> V_158 , L_22 ,
V_198 ) ;
V_49 -> V_93 = V_89 -> V_93 ;
V_49 -> V_90 = V_89 -> V_90 ;
V_49 -> V_77 = V_89 -> V_190 ? 0 : 1 ;
V_49 -> V_50 = 0 ;
V_49 -> V_199 = 0 ;
V_49 -> V_200 = 0 ;
V_49 -> V_51 = 1 ;
V_49 -> V_87 = 0 ;
V_80 -> V_87 = 0 ;
return 0 ;
}
static int F_69 ( struct V_112 * V_112 , void * V_113 ,
struct V_175 * V_170 )
{
struct V_38 * V_83 = V_40 -> V_41 ;
struct V_130 * V_131 = F_51 ( V_112 ) ;
struct V_6 * V_7 = F_52 ( V_131 ) ;
struct V_137 * V_138 ;
struct V_79 * V_80 = & V_7 -> V_81 ;
struct V_139 V_140 ;
if ( V_83 -> V_61 [ V_7 -> V_53 ] . V_141 == NULL )
goto error;
V_138 = & V_83 -> V_61 [ V_7 -> V_53 ] ;
V_140 = V_138 -> V_141 [ V_7 -> V_143 ] . V_140 ;
if ( V_140 . V_119 != V_171 )
goto error;
* V_170 = V_80 -> V_88 ;
return 0 ;
error:
return - V_142 ;
}
static int F_70 ( struct V_112 * V_201 , void * V_113 )
{
F_71 ( & V_73 . V_146 , 0 , V_202 , V_203 ) ;
return 0 ;
}
static int F_72 ( void )
{
int V_204 ;
int V_52 , V_74 , V_205 ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_73 . V_72 [ V_74 ] =
F_73 ( sizeof( struct V_6 ) , V_207 ) ;
if ( ! V_73 . V_72 [ V_74 ] ) {
V_204 = V_74 ;
V_52 = - V_208 ;
goto V_209;
}
}
return 0 ;
V_209:
for ( V_205 = 0 ; V_205 < V_204 ; V_205 ++ )
F_74 ( V_73 . V_72 [ V_205 ] ) ;
return V_52 ;
}
static int F_75 ( struct V_210 * V_211 ,
struct V_159 * V_212 ,
struct V_213 * V_214 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_73 . V_83 -> V_156 ; V_74 ++ )
if ( ! strcmp ( V_73 . V_83 -> V_157 [ V_74 ] . V_158 ,
V_212 -> V_158 ) ) {
V_73 . V_160 [ V_74 ] = V_212 ;
V_73 . V_160 [ V_74 ] -> V_215 = 1 << V_74 ;
return 0 ;
}
return - V_15 ;
}
static int F_76 ( void )
{
struct V_9 * V_10 ;
struct V_130 * V_131 ;
struct V_6 * V_7 ;
struct V_8 * V_216 ;
int V_205 , V_52 , V_217 ;
for ( V_205 = 0 ; V_205 < V_206 ; V_205 ++ ) {
V_7 = V_73 . V_72 [ V_205 ] ;
for ( V_217 = 0 ; V_217 < V_76 ; V_217 ++ ) {
V_10 = & V_7 -> V_10 [ V_217 ] ;
F_77 ( & V_10 -> V_34 ) ;
F_78 ( & V_10 -> V_218 ) ;
V_10 -> V_58 = NULL ;
V_10 -> V_19 = 0 ;
V_10 -> V_20 = 0 ;
V_10 -> V_21 = 0 ;
V_10 -> V_22 = 0 ;
V_10 -> V_55 = NULL ;
V_10 -> V_54 = NULL ;
memset ( & V_10 -> V_12 , 0 , sizeof( V_10 -> V_12 ) ) ;
}
V_7 -> V_219 = 0 ;
if ( V_73 . V_83 -> V_156 )
V_7 -> V_160 = V_73 . V_160 [ 0 ] ;
V_7 -> V_53 = V_205 ;
memset ( & V_7 -> V_44 , 0 , sizeof( V_7 -> V_44 ) ) ;
V_7 -> V_10 [ V_11 ] . V_12 . type =
V_128 ;
V_52 = F_61 ( V_73 . V_83 , V_7 , 0 ) ;
if ( V_52 )
goto V_220;
V_7 -> V_81 . V_87 = V_221 ;
memset ( & V_7 -> V_81 . V_88 , 0 , sizeof( V_7 -> V_81 . V_88 ) ) ;
F_45 ( V_7 ) ;
V_216 = & V_10 -> V_134 ;
V_216 -> type = V_128 ;
V_216 -> V_222 = V_223 | V_224 | V_225 ;
V_216 -> V_226 = V_7 ;
V_216 -> V_227 = & V_228 ;
V_216 -> V_229 = & V_230 ;
V_216 -> V_231 = sizeof( struct V_1 ) ;
V_216 -> V_232 = V_233 ;
V_216 -> V_234 = 1 ;
V_216 -> V_218 = & V_10 -> V_218 ;
V_52 = F_79 ( V_216 ) ;
if ( V_52 ) {
F_11 ( L_23 ) ;
goto V_220;
}
V_10 -> V_31 = F_80 ( V_40 ) ;
if ( F_81 ( V_10 -> V_31 ) ) {
F_11 ( L_24 ) ;
V_52 = F_82 ( V_10 -> V_31 ) ;
goto V_220;
}
F_83 ( & V_10 -> V_36 ) ;
F_44 ( 1 , V_86 , L_25 ,
V_7 , & V_7 -> V_167 ) ;
V_131 = & V_7 -> V_167 ;
F_47 ( V_131 -> V_158 , V_122 , sizeof( V_131 -> V_158 ) ) ;
V_131 -> V_235 = V_236 ;
V_131 -> V_237 = & V_238 ;
V_131 -> V_239 = & V_240 ;
V_131 -> V_146 = & V_73 . V_146 ;
V_131 -> V_241 = V_242 ;
V_131 -> V_243 = V_216 ;
V_131 -> V_218 = & V_10 -> V_218 ;
F_84 ( & V_7 -> V_167 , V_7 ) ;
V_52 = F_85 ( V_131 , V_244 ,
( V_205 ? 3 : 2 ) ) ;
if ( V_52 < 0 )
goto V_220;
}
return 0 ;
V_220:
for ( V_217 = 0 ; V_217 < V_205 ; V_217 ++ ) {
V_7 = V_73 . V_72 [ V_217 ] ;
V_10 = & V_7 -> V_10 [ V_217 ] ;
F_86 ( V_10 -> V_31 ) ;
F_87 ( & V_7 -> V_167 ) ;
}
return V_52 ;
}
static int F_88 ( struct V_210 * V_211 )
{
return F_76 () ;
}
static T_4 int F_89 ( struct V_245 * V_246 )
{
struct V_153 * V_247 ;
struct V_248 * V_249 ;
struct V_250 * V_251 ;
int V_156 ;
int V_252 = 0 ;
int V_74 , V_52 ;
V_40 = & V_246 -> V_72 ;
V_52 = F_72 () ;
if ( V_52 ) {
F_90 ( V_40 -> V_121 , L_26 ) ;
return V_52 ;
}
V_52 = F_91 ( V_40 , & V_73 . V_146 ) ;
if ( V_52 ) {
F_90 ( V_40 -> V_121 , L_27 ) ;
return V_52 ;
}
while ( ( V_251 = F_92 ( V_246 , V_253 , V_252 ) ) ) {
V_52 = F_93 ( & V_246 -> V_72 , V_251 -> V_254 , F_40 ,
V_255 , V_122 ,
( void * ) ( & V_73 . V_72 [ V_252 ] ->
V_53 ) ) ;
if ( V_52 ) {
V_52 = - V_15 ;
F_11 ( L_28 ) ;
goto V_256;
}
V_252 ++ ;
}
V_73 . V_83 = V_246 -> V_72 . V_41 ;
V_156 = V_73 . V_83 -> V_156 ;
V_247 = V_73 . V_83 -> V_157 ;
V_73 . V_160 = F_73 ( sizeof( struct V_159 * ) * V_156 ,
V_207 ) ;
if ( V_73 . V_160 == NULL ) {
F_11 ( L_29 ) ;
V_52 = - V_208 ;
goto V_256;
}
if ( ! V_73 . V_83 -> V_257 ) {
V_249 = F_94 ( 1 ) ;
for ( V_74 = 0 ; V_74 < V_156 ; V_74 ++ ) {
V_73 . V_160 [ V_74 ] =
F_95 ( & V_73 . V_146 ,
V_249 ,
& V_247 [ V_74 ] .
V_258 ,
NULL ) ;
if ( ! V_73 . V_160 [ V_74 ] ) {
F_11 ( L_30 ) ;
V_52 = - V_174 ;
goto V_259;
}
if ( V_73 . V_160 [ V_74 ] )
V_73 . V_160 [ V_74 ] -> V_215 = 1 << V_74 ;
}
F_76 () ;
} else {
V_73 . V_211 . V_260 = V_73 . V_83 -> V_214 ;
V_73 . V_211 . V_261 = V_73 . V_83 -> V_257 [ 0 ] ;
V_73 . V_211 . V_262 = F_75 ;
V_73 . V_211 . V_263 = F_88 ;
V_52 = F_96 ( & V_73 . V_146 ,
& V_73 . V_211 ) ;
if ( V_52 ) {
F_11 ( L_31 ) ;
V_52 = - V_15 ;
goto V_259;
}
}
return 0 ;
V_259:
F_74 ( V_73 . V_160 ) ;
V_256:
F_97 ( & V_73 . V_146 ) ;
return V_52 ;
}
static int F_98 ( struct V_245 * V_264 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
int V_74 ;
F_97 ( & V_73 . V_146 ) ;
F_74 ( V_73 . V_160 ) ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_7 = V_73 . V_72 [ V_74 ] ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
F_86 ( V_10 -> V_31 ) ;
F_87 ( & V_7 -> V_167 ) ;
F_74 ( V_73 . V_72 [ V_74 ] ) ;
}
return 0 ;
}
static int F_99 ( struct V_264 * V_72 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_7 = V_73 . V_72 [ V_74 ] ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( ! F_100 ( & V_10 -> V_134 ) )
continue;
F_101 ( & V_10 -> V_218 ) ;
if ( V_7 -> V_53 == V_60 ) {
F_25 ( 0 ) ;
F_24 ( 0 ) ;
}
if ( V_7 -> V_53 == V_63 ||
V_50 == 2 ) {
F_29 ( 0 ) ;
F_28 ( 0 ) ;
}
F_102 ( & V_10 -> V_218 ) ;
}
return 0 ;
}
static int F_103 ( struct V_264 * V_72 )
{
struct V_9 * V_10 ;
struct V_6 * V_7 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_206 ; V_74 ++ ) {
V_7 = V_73 . V_72 [ V_74 ] ;
V_10 = & V_7 -> V_10 [ V_11 ] ;
if ( ! F_100 ( & V_10 -> V_134 ) )
continue;
F_101 ( & V_10 -> V_218 ) ;
if ( V_7 -> V_53 == V_60 ) {
F_25 ( 1 ) ;
F_24 ( 1 ) ;
}
if ( V_7 -> V_53 == V_63 ||
V_50 == 2 ) {
F_29 ( 1 ) ;
F_28 ( 1 ) ;
}
F_102 ( & V_10 -> V_218 ) ;
}
return 0 ;
}
