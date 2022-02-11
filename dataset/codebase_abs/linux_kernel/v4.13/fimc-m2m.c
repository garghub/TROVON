static unsigned int F_1 ( unsigned int V_1 )
{
if ( V_1 == V_2 )
return V_3 ;
else
return V_4 ;
}
void F_2 ( struct V_5 * V_6 , int V_7 )
{
struct V_8 * V_9 , * V_10 ;
if ( ! V_6 || ! V_6 -> V_11 . V_12 )
return;
V_9 = F_3 ( V_6 -> V_11 . V_12 ) ;
V_10 = F_4 ( V_6 -> V_11 . V_12 ) ;
if ( V_9 )
F_5 ( V_9 , V_7 ) ;
if ( V_10 )
F_5 ( V_10 , V_7 ) ;
if ( V_9 && V_10 )
F_6 ( V_6 -> V_13 -> V_14 . V_15 ,
V_6 -> V_11 . V_12 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
if ( ! F_8 ( V_16 ) )
return;
F_9 ( V_17 , V_6 ) ;
F_10 ( V_16 -> V_18 ,
! F_11 ( V_17 , V_6 ) ,
V_19 ) ;
}
static int F_12 ( struct V_20 * V_21 , unsigned int V_22 )
{
struct V_5 * V_6 = V_21 -> V_23 ;
int V_24 ;
V_24 = F_13 ( & V_6 -> V_13 -> V_25 -> V_26 ) ;
return V_24 > 0 ? 0 : V_24 ;
}
static void F_14 ( struct V_20 * V_21 )
{
struct V_5 * V_6 = V_21 -> V_23 ;
F_7 ( V_6 ) ;
F_2 ( V_6 , V_27 ) ;
F_15 ( & V_6 -> V_13 -> V_25 -> V_26 ) ;
}
static void F_16 ( void * V_28 )
{
struct V_8 * V_9 , * V_10 ;
struct V_5 * V_6 = V_28 ;
struct V_29 * V_30 , * V_31 ;
struct V_13 * V_16 ;
unsigned long V_32 ;
int V_24 ;
if ( F_17 ( ! V_6 , L_1 ) )
return;
V_16 = V_6 -> V_13 ;
F_18 ( & V_16 -> V_33 , V_32 ) ;
F_19 ( V_34 , & V_16 -> V_35 ) ;
V_30 = & V_6 -> V_36 ;
V_31 = & V_6 -> V_37 ;
if ( V_6 -> V_35 & V_38 ) {
F_20 ( V_6 , V_30 ) ;
F_20 ( V_6 , V_31 ) ;
}
V_9 = F_21 ( V_6 -> V_11 . V_12 ) ;
V_24 = F_22 ( V_6 , & V_9 -> V_39 , V_30 , & V_30 -> V_40 ) ;
if ( V_24 )
goto V_41;
V_10 = F_23 ( V_6 -> V_11 . V_12 ) ;
V_24 = F_22 ( V_6 , & V_10 -> V_39 , V_31 , & V_31 -> V_40 ) ;
if ( V_24 )
goto V_41;
V_10 -> V_39 . V_42 = V_9 -> V_39 . V_42 ;
V_10 -> V_32 &= ~ V_43 ;
V_10 -> V_32 |=
V_9 -> V_32 & V_43 ;
if ( V_16 -> V_14 . V_6 != V_6 ) {
V_6 -> V_35 |= V_38 ;
V_16 -> V_14 . V_6 = V_6 ;
}
if ( V_6 -> V_35 & V_38 ) {
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
V_24 = F_27 ( V_6 ) ;
if ( V_24 )
goto V_41;
F_28 ( V_6 ) ;
F_29 ( V_6 ) ;
F_30 ( V_6 ) ;
F_31 ( V_6 ) ;
F_32 ( V_6 ) ;
F_33 ( V_6 ) ;
if ( V_16 -> V_44 -> V_45 )
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
}
F_36 ( V_16 , & V_30 -> V_40 ) ;
F_37 ( V_16 , & V_31 -> V_40 , - 1 ) ;
F_38 ( V_6 ) ;
V_6 -> V_35 &= ( V_46 | V_47 ) ;
F_39 ( V_16 , true ) ;
V_41:
F_40 ( & V_16 -> V_33 , V_32 ) ;
}
static void F_41 ( void * V_28 )
{
F_7 ( V_28 ) ;
}
static int F_42 ( struct V_20 * V_48 ,
unsigned int * V_49 , unsigned int * V_50 ,
unsigned int V_51 [] , struct V_52 * V_53 [] )
{
struct V_5 * V_6 = F_43 ( V_48 ) ;
struct V_29 * V_54 ;
int V_55 ;
V_54 = F_44 ( V_6 , V_48 -> type ) ;
if ( F_45 ( V_54 ) )
return F_46 ( V_54 ) ;
if ( ! V_54 -> V_56 )
return - V_57 ;
* V_50 = V_54 -> V_56 -> V_58 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_56 -> V_58 ; V_55 ++ )
V_51 [ V_55 ] = V_54 -> V_59 [ V_55 ] ;
return 0 ;
}
static int F_47 ( struct V_60 * V_61 )
{
struct V_5 * V_6 = F_43 ( V_61 -> V_20 ) ;
struct V_29 * V_62 ;
int V_55 ;
V_62 = F_44 ( V_6 , V_61 -> V_20 -> type ) ;
if ( F_45 ( V_62 ) )
return F_46 ( V_62 ) ;
for ( V_55 = 0 ; V_55 < V_62 -> V_56 -> V_58 ; V_55 ++ )
F_48 ( V_61 , V_55 , V_62 -> V_59 [ V_55 ] ) ;
return 0 ;
}
static void F_49 ( struct V_60 * V_61 )
{
struct V_8 * V_63 = F_50 ( V_61 ) ;
struct V_5 * V_6 = F_43 ( V_61 -> V_20 ) ;
F_51 ( V_6 -> V_11 . V_12 , V_63 ) ;
}
static int F_52 ( struct V_64 * V_64 , void * V_11 ,
struct V_65 * V_66 )
{
struct V_13 * V_16 = F_53 ( V_64 ) ;
unsigned int V_67 ;
V_67 = V_68 | V_69 |
V_70 | V_71 ;
F_54 ( & V_16 -> V_25 -> V_26 , V_66 , V_67 ) ;
return 0 ;
}
static int F_55 ( struct V_64 * V_64 , void * V_28 ,
struct V_72 * V_54 )
{
struct V_73 * V_56 ;
V_56 = F_56 ( NULL , NULL , F_1 ( V_54 -> type ) ,
V_54 -> V_74 ) ;
if ( ! V_56 )
return - V_57 ;
strncpy ( V_54 -> V_75 , V_56 -> V_76 , sizeof( V_54 -> V_75 ) - 1 ) ;
V_54 -> V_77 = V_56 -> V_78 ;
return 0 ;
}
static int F_57 ( struct V_64 * V_64 , void * V_11 ,
struct V_79 * V_54 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_29 * V_62 = F_44 ( V_6 , V_54 -> type ) ;
if ( F_45 ( V_62 ) )
return F_46 ( V_62 ) ;
F_59 ( V_62 , V_54 ) ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 , struct V_79 * V_54 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
const struct V_80 * V_81 = V_16 -> V_81 ;
struct V_82 * V_83 = & V_54 -> V_56 . V_84 ;
struct V_73 * V_56 ;
T_1 V_85 , V_86 , V_87 ;
if ( ! F_61 ( V_54 -> type ) )
return - V_57 ;
V_56 = F_56 ( & V_83 -> V_77 , NULL ,
F_1 ( V_54 -> type ) , 0 ) ;
if ( F_17 ( V_56 == NULL , L_2 ) )
return - V_57 ;
if ( V_83 -> V_88 == V_89 )
V_83 -> V_88 = V_90 ;
else if ( V_83 -> V_88 != V_90 )
return - V_57 ;
if ( V_54 -> type == V_2 ) {
V_85 = V_81 -> V_91 -> V_92 ;
V_86 = F_62 ( V_81 -> V_93 ) - 1 ;
} else {
V_85 = V_81 -> V_91 -> V_94 ;
V_86 = F_62 ( V_81 -> V_95 ) - 1 ;
}
if ( F_63 ( V_56 ) ) {
V_86 = 6 ;
V_87 = 5 ;
} else {
if ( V_81 -> V_96 == 1 )
V_87 = F_64 ( V_56 -> V_97 ) ? 0 : 1 ;
else
V_87 = F_62 ( V_81 -> V_96 ) - 1 ;
}
F_65 ( & V_83 -> V_98 , 16 , V_85 , V_86 ,
& V_83 -> V_99 , 8 , V_81 -> V_91 -> V_92 , V_87 , 0 ) ;
F_66 ( V_56 , V_83 -> V_98 , V_83 -> V_99 , & V_54 -> V_56 . V_84 ) ;
return 0 ;
}
static int F_67 ( struct V_64 * V_64 , void * V_11 ,
struct V_79 * V_54 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
return F_60 ( V_6 , V_54 ) ;
}
static void F_68 ( struct V_29 * V_62 , struct V_73 * V_56 ,
struct V_82 * V_100 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 -> V_58 ; V_55 ++ ) {
V_62 -> V_101 [ V_55 ] = V_100 -> V_102 [ V_55 ] . V_101 ;
V_62 -> V_59 [ V_55 ] = V_100 -> V_102 [ V_55 ] . V_103 ;
}
V_62 -> V_104 = V_100 -> V_98 ;
V_62 -> V_105 = V_100 -> V_99 ;
V_62 -> V_106 = V_100 -> V_98 ;
V_62 -> V_107 = V_100 -> V_99 ;
V_62 -> V_98 = V_100 -> V_98 ;
V_62 -> V_99 = V_100 -> V_99 ;
V_62 -> V_108 = 0 ;
V_62 -> V_109 = 0 ;
V_62 -> V_56 = V_56 ;
}
static int F_69 ( struct V_64 * V_64 , void * V_11 ,
struct V_79 * V_54 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_73 * V_56 ;
struct V_20 * V_48 ;
struct V_29 * V_62 ;
int V_24 ;
V_24 = F_60 ( V_6 , V_54 ) ;
if ( V_24 )
return V_24 ;
V_48 = F_70 ( V_6 -> V_11 . V_12 , V_54 -> type ) ;
if ( F_71 ( V_48 ) ) {
F_72 ( & V_16 -> V_14 . V_110 , L_3 , V_54 -> type ) ;
return - V_111 ;
}
if ( V_54 -> type == V_2 )
V_62 = & V_6 -> V_36 ;
else
V_62 = & V_6 -> V_37 ;
V_56 = F_56 ( & V_54 -> V_56 . V_84 . V_77 , NULL ,
F_1 ( V_54 -> type ) , 0 ) ;
if ( ! V_56 )
return - V_57 ;
F_68 ( V_62 , V_56 , & V_54 -> V_56 . V_84 ) ;
F_73 ( V_6 ) ;
return 0 ;
}
static int F_74 ( struct V_64 * V_64 , void * V_11 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_29 * V_62 ;
V_62 = F_44 ( V_6 , V_113 -> type ) ;
if ( F_45 ( V_62 ) )
return F_46 ( V_62 ) ;
V_113 -> V_114 . V_115 = 0 ;
V_113 -> V_114 . V_116 = 0 ;
V_113 -> V_114 . V_98 = V_62 -> V_106 ;
V_113 -> V_114 . V_99 = V_62 -> V_107 ;
V_113 -> V_117 = V_113 -> V_114 ;
return 0 ;
}
static int F_75 ( struct V_64 * V_64 , void * V_11 , struct V_118 * V_113 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_29 * V_62 ;
V_62 = F_44 ( V_6 , V_113 -> type ) ;
if ( F_45 ( V_62 ) )
return F_46 ( V_62 ) ;
V_113 -> V_119 . V_115 = V_62 -> V_108 ;
V_113 -> V_119 . V_116 = V_62 -> V_109 ;
V_113 -> V_119 . V_98 = V_62 -> V_98 ;
V_113 -> V_119 . V_99 = V_62 -> V_99 ;
return 0 ;
}
static int F_76 ( struct V_5 * V_6 , struct V_118 * V_113 )
{
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_29 * V_54 ;
T_1 V_120 , V_121 , V_122 = 0 ;
int V_55 ;
if ( V_113 -> V_119 . V_116 < 0 || V_113 -> V_119 . V_115 < 0 ) {
F_72 ( & V_16 -> V_14 . V_110 ,
L_4 ) ;
return - V_57 ;
}
if ( V_113 -> type == V_123 )
V_54 = & V_6 -> V_37 ;
else if ( V_113 -> type == V_2 )
V_54 = & V_6 -> V_36 ;
else
return - V_57 ;
V_120 = ( V_54 == & V_6 -> V_36 ) ?
V_16 -> V_81 -> V_93 : V_16 -> V_81 -> V_95 ;
if ( V_16 -> V_81 -> V_96 == 1 )
V_121 = F_64 ( V_54 -> V_56 -> V_97 ) ? 0 : 1 ;
else
V_121 = F_62 ( V_16 -> V_81 -> V_96 ) - 1 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_56 -> V_58 ; V_55 ++ )
V_122 += V_54 -> V_56 -> V_122 [ V_55 ] ;
F_65 ( & V_113 -> V_119 . V_98 , V_120 , V_54 -> V_106 ,
F_62 ( V_120 ) - 1 ,
& V_113 -> V_119 . V_99 , V_120 , V_54 -> V_107 ,
V_121 , 64 / ( F_77 ( V_122 , 8 ) ) ) ;
if ( V_113 -> V_119 . V_115 + V_113 -> V_119 . V_98 > V_54 -> V_106 )
V_113 -> V_119 . V_115 = V_54 -> V_106 - V_113 -> V_119 . V_98 ;
if ( V_113 -> V_119 . V_116 + V_113 -> V_119 . V_99 > V_54 -> V_107 )
V_113 -> V_119 . V_116 = V_54 -> V_107 - V_113 -> V_119 . V_99 ;
V_113 -> V_119 . V_115 = F_78 ( V_113 -> V_119 . V_115 , V_120 ) ;
V_113 -> V_119 . V_116 = F_78 ( V_113 -> V_119 . V_116 , V_16 -> V_81 -> V_124 ) ;
F_79 ( L_5 ,
V_113 -> V_119 . V_115 , V_113 -> V_119 . V_116 , V_113 -> V_119 . V_98 , V_113 -> V_119 . V_99 ,
V_54 -> V_104 , V_54 -> V_105 ) ;
return 0 ;
}
static int F_80 ( struct V_64 * V_64 , void * V_11 , const struct V_118 * V_125 )
{
struct V_5 * V_6 = F_58 ( V_11 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
struct V_118 V_113 = * V_125 ;
struct V_29 * V_54 ;
int V_24 ;
V_24 = F_76 ( V_6 , & V_113 ) ;
if ( V_24 )
return V_24 ;
V_54 = ( V_113 . type == V_2 ) ?
& V_6 -> V_36 : & V_6 -> V_37 ;
if ( V_113 . type == V_2 ) {
V_24 = F_81 ( V_6 , V_113 . V_119 . V_98 ,
V_113 . V_119 . V_99 , V_6 -> V_37 . V_98 ,
V_6 -> V_37 . V_99 , V_6 -> V_126 ) ;
} else {
V_24 = F_81 ( V_6 , V_6 -> V_36 . V_98 ,
V_6 -> V_36 . V_99 , V_113 . V_119 . V_98 ,
V_113 . V_119 . V_99 , V_6 -> V_126 ) ;
}
if ( V_24 ) {
F_72 ( & V_16 -> V_14 . V_110 , L_6 ) ;
return - V_57 ;
}
V_54 -> V_108 = V_113 . V_119 . V_115 ;
V_54 -> V_109 = V_113 . V_119 . V_116 ;
V_54 -> V_98 = V_113 . V_119 . V_98 ;
V_54 -> V_99 = V_113 . V_119 . V_99 ;
F_9 ( V_38 , V_6 ) ;
return 0 ;
}
static int F_82 ( void * V_28 , struct V_20 * V_127 ,
struct V_20 * V_128 )
{
struct V_5 * V_6 = V_28 ;
int V_24 ;
V_127 -> type = V_2 ;
V_127 -> V_129 = V_130 | V_131 | V_132 ;
V_127 -> V_23 = V_6 ;
V_127 -> V_133 = & V_134 ;
V_127 -> V_135 = & V_136 ;
V_127 -> V_137 = sizeof( struct V_138 ) ;
V_127 -> V_139 = V_140 ;
V_127 -> V_141 = & V_6 -> V_13 -> V_141 ;
V_127 -> V_26 = & V_6 -> V_13 -> V_25 -> V_26 ;
V_24 = F_83 ( V_127 ) ;
if ( V_24 )
return V_24 ;
V_128 -> type = V_123 ;
V_128 -> V_129 = V_130 | V_131 | V_132 ;
V_128 -> V_23 = V_6 ;
V_128 -> V_133 = & V_134 ;
V_128 -> V_135 = & V_136 ;
V_128 -> V_137 = sizeof( struct V_138 ) ;
V_128 -> V_139 = V_140 ;
V_128 -> V_141 = & V_6 -> V_13 -> V_141 ;
V_128 -> V_26 = & V_6 -> V_13 -> V_25 -> V_26 ;
return F_83 ( V_128 ) ;
}
static int F_84 ( struct V_5 * V_6 )
{
struct V_82 V_100 = {
. V_77 = V_142 ,
. V_98 = 800 ,
. V_99 = 600 ,
. V_102 [ 0 ] = {
. V_101 = 800 * 4 ,
. V_103 = 800 * 4 * 600 ,
} ,
} ;
struct V_73 * V_56 ;
V_56 = F_56 ( & V_100 . V_77 , NULL , V_143 , 0 ) ;
if ( ! V_56 )
return - V_57 ;
F_68 ( & V_6 -> V_36 , V_56 , & V_100 ) ;
F_68 ( & V_6 -> V_37 , V_56 , & V_100 ) ;
return 0 ;
}
static int F_85 ( struct V_64 * V_64 )
{
struct V_13 * V_16 = F_53 ( V_64 ) ;
struct V_5 * V_6 ;
int V_24 = - V_111 ;
F_86 ( L_7 , F_87 ( V_144 ) , V_16 -> V_35 ) ;
if ( F_88 ( & V_16 -> V_141 ) )
return - V_145 ;
if ( F_89 ( V_146 , & V_16 -> V_35 ) )
goto V_147;
V_6 = F_90 ( sizeof( * V_6 ) , V_148 ) ;
if ( ! V_6 ) {
V_24 = - V_149 ;
goto V_147;
}
F_91 ( & V_6 -> V_11 , & V_16 -> V_14 . V_110 ) ;
V_6 -> V_13 = V_16 ;
V_6 -> V_36 . V_56 = F_92 ( 0 ) ;
V_6 -> V_37 . V_56 = F_92 ( 0 ) ;
V_24 = F_93 ( V_6 ) ;
if ( V_24 )
goto V_150;
V_6 -> V_11 . V_151 = & V_6 -> V_152 . V_153 ;
V_64 -> V_154 = & V_6 -> V_11 ;
F_94 ( & V_6 -> V_11 ) ;
V_6 -> V_35 = V_46 ;
V_6 -> V_32 = 0 ;
V_6 -> V_155 = V_156 ;
V_6 -> V_157 = V_156 ;
V_6 -> V_158 . V_159 = 1 ;
V_6 -> V_11 . V_12 = F_95 ( V_16 -> V_14 . V_15 , V_6 , F_82 ) ;
if ( F_45 ( V_6 -> V_11 . V_12 ) ) {
V_24 = F_46 ( V_6 -> V_11 . V_12 ) ;
goto V_160;
}
if ( V_16 -> V_14 . V_161 ++ == 0 )
F_19 ( V_162 , & V_16 -> V_35 ) ;
V_24 = F_84 ( V_6 ) ;
if ( V_24 < 0 )
goto V_163;
F_96 ( & V_16 -> V_141 ) ;
return 0 ;
V_163:
F_97 ( V_6 -> V_11 . V_12 ) ;
V_160:
F_98 ( V_6 ) ;
F_99 ( & V_6 -> V_11 ) ;
V_150:
F_100 ( & V_6 -> V_11 ) ;
F_101 ( V_6 ) ;
V_147:
F_96 ( & V_16 -> V_141 ) ;
return V_24 ;
}
static int F_102 ( struct V_64 * V_64 )
{
struct V_5 * V_6 = F_58 ( V_64 -> V_154 ) ;
struct V_13 * V_16 = V_6 -> V_13 ;
F_79 ( L_8 ,
F_87 ( V_144 ) , V_16 -> V_35 , V_16 -> V_14 . V_161 ) ;
F_103 ( & V_16 -> V_141 ) ;
F_97 ( V_6 -> V_11 . V_12 ) ;
F_98 ( V_6 ) ;
F_99 ( & V_6 -> V_11 ) ;
F_100 ( & V_6 -> V_11 ) ;
if ( -- V_16 -> V_14 . V_161 <= 0 )
F_104 ( V_162 , & V_16 -> V_35 ) ;
F_101 ( V_6 ) ;
F_96 ( & V_16 -> V_141 ) ;
return 0 ;
}
int F_105 ( struct V_13 * V_16 ,
struct V_164 * V_165 )
{
struct V_166 * V_110 = & V_16 -> V_14 . V_110 ;
int V_24 ;
V_16 -> V_165 = V_165 ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
V_110 -> V_167 = & V_168 ;
V_110 -> V_169 = & V_170 ;
V_110 -> V_165 = V_165 ;
V_110 -> V_171 = - 1 ;
V_110 -> V_172 = V_173 ;
V_110 -> V_141 = & V_16 -> V_141 ;
V_110 -> V_174 = V_175 ;
snprintf ( V_110 -> V_76 , sizeof( V_110 -> V_76 ) , L_9 , V_16 -> V_176 ) ;
F_106 ( V_110 , V_16 ) ;
V_16 -> V_14 . V_15 = F_107 ( & V_177 ) ;
if ( F_45 ( V_16 -> V_14 . V_15 ) ) {
F_72 ( V_165 , L_10 ) ;
return F_46 ( V_16 -> V_14 . V_15 ) ;
}
V_24 = F_108 ( & V_110 -> V_178 , 0 , NULL ) ;
if ( V_24 )
goto V_179;
V_24 = F_109 ( V_110 , V_180 , - 1 ) ;
if ( V_24 )
goto V_181;
F_110 ( V_165 , L_11 ,
V_110 -> V_76 , F_111 ( V_110 ) ) ;
return 0 ;
V_181:
F_112 ( & V_110 -> V_178 ) ;
V_179:
F_113 ( V_16 -> V_14 . V_15 ) ;
return V_24 ;
}
void F_114 ( struct V_13 * V_16 )
{
if ( ! V_16 )
return;
if ( V_16 -> V_14 . V_15 )
F_113 ( V_16 -> V_14 . V_15 ) ;
if ( F_115 ( & V_16 -> V_14 . V_110 ) ) {
F_116 ( & V_16 -> V_14 . V_110 ) ;
F_112 ( & V_16 -> V_14 . V_110 . V_178 ) ;
}
}
