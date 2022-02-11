static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) == V_4 )
return F_3 ( V_2 -> V_5 . V_6 ) ;
#if F_4 ( V_7 )
else
return F_5 ( & V_2 -> V_8 ) ;
#endif
return 0 ;
}
static void F_6 ( struct V_9 * V_2 ,
struct V_1 * V_10 )
{
memset ( V_2 , 0 , sizeof( struct V_9 ) ) ;
V_2 -> V_11 = V_12 ;
memcpy ( V_2 -> V_13 , V_10 , sizeof( struct V_1 ) ) ;
if ( F_1 ( V_10 ) )
V_2 -> V_14 = 1 ;
}
static int F_7 ( struct V_9 * V_15 , char * V_16 , int V_17 )
{
struct V_1 * V_10 = (struct V_1 * ) & V_15 -> V_13 ;
if ( F_2 ( V_10 -> V_3 ) == V_4 )
snprintf ( V_16 , V_17 , L_1 , & V_10 -> V_5 , F_2 ( V_10 -> V_18 ) ) ;
else if ( F_2 ( V_10 -> V_3 ) == V_19 )
snprintf ( V_16 , V_17 , L_2 , & V_10 -> V_8 , F_2 ( V_10 -> V_18 ) ) ;
else
F_8 ( L_3 ) ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 , struct V_9 * V_15 ,
char * V_22 )
{
struct V_1 * V_10 ;
V_10 = (struct V_1 * ) ( V_22 + V_23 ) ;
if ( V_22 [ V_24 ] != V_12 )
return - V_25 ;
F_6 ( V_15 , V_10 ) ;
return 0 ;
}
static int F_10 ( char * V_22 , struct V_9 * V_15 )
{
memset ( V_22 , 0 , V_26 ) ;
V_22 [ V_24 ] = V_12 ;
memcpy ( V_22 + V_23 , V_15 -> V_13 ,
sizeof( struct V_1 ) ) ;
return 0 ;
}
static int F_11 ( struct V_27 * V_27 , struct V_28 * V_29 ,
struct V_30 * V_31 , struct V_1 * V_32 ,
struct V_1 * V_33 )
{
int V_34 , V_35 = 0 ;
struct V_36 * V_37 ;
if ( V_33 -> V_3 == F_12 ( V_4 ) ) {
struct V_38 V_39 = {
. V_40 = V_33 -> V_5 . V_6 ,
. V_41 = V_32 -> V_5 . V_6 ,
. V_42 = V_29 -> V_43 ,
. V_44 = V_45
} ;
V_37 = F_13 ( V_27 , & V_39 ) ;
if ( F_14 ( V_37 ) ) {
V_35 = F_15 ( V_37 ) ;
goto V_46;
}
V_29 -> V_47 = V_37 -> V_33 . V_47 ;
V_34 = F_16 ( & V_37 -> V_33 ) ;
F_17 ( V_37 , V_31 -> V_48 -> V_49 , V_29 , V_32 -> V_5 . V_6 ,
V_33 -> V_5 . V_6 , 0 , V_34 , 0 , V_32 -> V_18 ,
V_33 -> V_18 , false , true ) ;
#if F_4 ( V_7 )
} else {
struct V_50 * V_51 ;
struct V_52 V_53 = {
. V_54 = V_31 -> V_55 ,
. V_40 = V_33 -> V_8 ,
. V_41 = V_32 -> V_8 ,
. V_56 = V_45
} ;
V_35 = V_57 -> V_58 ( V_27 , V_31 -> V_48 -> V_49 , & V_51 ,
& V_53 ) ;
if ( V_35 )
goto V_46;
V_34 = F_18 ( V_51 ) ;
V_35 = F_19 ( V_51 , V_31 -> V_48 -> V_49 , V_29 ,
V_51 -> V_47 , & V_32 -> V_8 ,
& V_33 -> V_8 , 0 , V_34 , 0 , V_32 -> V_18 ,
V_33 -> V_18 , false ) ;
#endif
}
return V_35 ;
V_46:
F_20 ( V_29 ) ;
return V_35 ;
}
static int F_21 ( struct V_27 * V_27 , struct V_28 * V_29 ,
struct V_20 * V_21 ,
struct V_9 * V_2 )
{
struct V_1 * V_32 = (struct V_1 * ) & V_21 -> V_2 . V_13 ;
struct V_1 * V_33 = (struct V_1 * ) & V_2 -> V_13 ;
struct V_59 * V_60 ;
struct V_30 * V_31 ;
int V_35 = 0 ;
if ( F_22 ( V_29 ) < V_61 ) {
V_35 = F_23 ( V_29 , V_61 , 0 , V_62 ) ;
if ( V_35 )
goto V_63;
}
F_24 ( V_29 , F_12 ( V_64 ) ) ;
V_31 = F_25 ( V_21 -> V_65 ) ;
if ( ! V_31 ) {
V_35 = - V_66 ;
goto V_63;
}
if ( ! V_2 -> V_14 || F_26 ( & V_31 -> V_60 . V_67 ) )
return F_11 ( V_27 , V_29 , V_31 , V_32 , V_33 ) ;
F_27 (rcast, &ub->rcast.list, list) {
struct V_28 * V_68 ;
V_68 = F_28 ( V_29 , V_62 ) ;
if ( ! V_68 ) {
V_35 = - V_69 ;
goto V_63;
}
V_35 = F_11 ( V_27 , V_68 , V_31 , V_32 , & V_60 -> V_2 ) ;
if ( V_35 ) {
F_20 ( V_68 ) ;
goto V_63;
}
}
V_35 = 0 ;
V_63:
F_20 ( V_29 ) ;
return V_35 ;
}
static bool F_29 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
struct V_59 * V_60 , * V_70 ;
struct V_30 * V_31 ;
V_31 = F_25 ( V_21 -> V_65 ) ;
if ( ! V_31 ) {
F_30 ( L_4 ) ;
return false ;
}
F_31 (rcast, tmp, &ub->rcast.list, list) {
if ( ! memcmp ( & V_60 -> V_2 , V_2 , sizeof( struct V_1 ) ) )
return true ;
}
return false ;
}
static int F_32 ( struct V_20 * V_21 ,
struct V_1 * V_2 )
{
struct V_59 * V_60 ;
struct V_30 * V_31 ;
V_31 = F_25 ( V_21 -> V_65 ) ;
if ( ! V_31 )
return - V_66 ;
V_60 = F_33 ( sizeof( * V_60 ) , V_62 ) ;
if ( ! V_60 )
return - V_69 ;
memcpy ( & V_60 -> V_2 , V_2 , sizeof( struct V_1 ) ) ;
if ( F_2 ( V_2 -> V_3 ) == V_4 )
F_34 ( L_5 , & V_60 -> V_2 . V_5 ) ;
#if F_4 ( V_7 )
else if ( F_2 ( V_2 -> V_3 ) == V_19 )
F_34 ( L_6 , & V_60 -> V_2 . V_8 ) ;
#endif
F_35 ( & V_60 -> V_67 , & V_31 -> V_60 . V_67 ) ;
return 0 ;
}
static int F_36 ( struct V_20 * V_21 , struct V_28 * V_29 )
{
struct V_1 V_32 = { 0 } ;
struct V_1 * V_33 ;
V_33 = (struct V_1 * ) & V_21 -> V_71 . V_13 ;
if ( F_1 ( V_33 ) )
return 0 ;
V_32 . V_18 = F_37 ( V_29 ) -> V_72 ;
if ( F_38 ( V_29 ) -> V_73 == 4 ) {
struct V_74 * V_74 = F_38 ( V_29 ) ;
V_32 . V_3 = F_12 ( V_4 ) ;
V_32 . V_5 . V_6 = V_74 -> V_41 ;
if ( F_3 ( V_74 -> V_40 ) )
return 0 ;
#if F_4 ( V_7 )
} else if ( F_38 ( V_29 ) -> V_73 == 6 ) {
struct V_75 * V_74 = F_39 ( V_29 ) ;
V_32 . V_3 = F_12 ( V_19 ) ;
V_32 . V_8 = V_74 -> V_41 ;
if ( F_5 ( & V_74 -> V_40 ) )
return 0 ;
#endif
} else {
return 0 ;
}
if ( F_40 ( F_29 ( V_21 , & V_32 ) ) )
return 0 ;
return F_32 ( V_21 , & V_32 ) ;
}
static int F_41 ( struct V_76 * V_49 , struct V_28 * V_29 )
{
struct V_30 * V_31 ;
struct V_20 * V_21 ;
struct V_77 * V_78 ;
int V_35 ;
V_31 = F_42 ( V_49 ) ;
if ( ! V_31 ) {
F_30 ( L_7 ) ;
goto V_63;
}
F_43 ( V_29 , sizeof( struct V_79 ) ) ;
V_78 = F_44 ( V_29 ) ;
F_45 () ;
V_21 = F_25 ( V_31 -> V_80 ) ;
if ( ! V_21 )
goto V_81;
if ( V_21 && F_46 ( 0 , & V_21 -> V_82 ) ) {
F_47 ( F_48 ( V_49 ) , V_29 , V_21 ) ;
F_49 () ;
return 0 ;
}
if ( F_50 ( F_51 ( V_78 ) == V_83 ) ) {
V_35 = F_36 ( V_21 , V_29 ) ;
if ( V_35 )
goto V_81;
}
F_47 ( F_48 ( V_49 ) , V_29 , V_21 ) ;
F_49 () ;
return 0 ;
V_81:
F_49 () ;
V_63:
F_20 ( V_29 ) ;
return 0 ;
}
static int F_52 ( struct V_30 * V_31 , struct V_1 * V_84 )
{
int V_35 = 0 ;
struct V_85 V_86 ;
struct V_76 * V_49 = V_31 -> V_48 -> V_49 ;
if ( F_2 ( V_84 -> V_3 ) == V_4 ) {
V_86 . V_87 = V_84 -> V_5 ;
V_86 . V_88 = V_31 -> V_55 ;
V_35 = F_53 ( V_49 , & V_86 ) ;
#if F_4 ( V_7 )
} else {
V_35 = V_57 -> V_89 ( V_49 , V_31 -> V_55 ,
& V_84 -> V_8 ) ;
#endif
}
return V_35 ;
}
static int F_54 ( struct V_28 * V_29 ,
struct V_1 * V_2 , int V_90 )
{
if ( F_2 ( V_2 -> V_3 ) == V_4 ) {
struct V_91 V_92 ;
memset ( & V_92 , 0 , sizeof( V_92 ) ) ;
V_92 . V_93 = V_94 ;
V_92 . V_95 = V_2 -> V_18 ;
V_92 . V_96 . V_6 = V_2 -> V_5 . V_6 ;
if ( F_55 ( V_29 , V_90 , sizeof( V_92 ) , & V_92 ) )
return - V_97 ;
#if F_4 ( V_7 )
} else if ( F_2 ( V_2 -> V_3 ) == V_19 ) {
struct V_98 V_99 ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_100 = V_101 ;
V_99 . V_102 = V_2 -> V_18 ;
memcpy ( & V_99 . V_103 , & V_2 -> V_8 , sizeof( struct V_104 ) ) ;
if ( F_55 ( V_29 , V_90 , sizeof( V_99 ) , & V_99 ) )
return - V_97 ;
#endif
}
return 0 ;
}
int F_56 ( struct V_28 * V_29 , struct V_105 * V_106 )
{
T_1 V_107 = V_106 -> args [ 0 ] ;
T_1 V_108 = V_106 -> args [ 1 ] ;
T_1 V_109 = F_57 ( V_106 -> V_29 ) . V_109 ;
struct V_59 * V_60 , * V_70 ;
struct V_20 * V_21 ;
struct V_30 * V_31 ;
void * V_78 ;
int V_35 ;
int V_110 ;
if ( ! V_107 && ! V_108 ) {
struct V_27 * V_27 = F_48 ( V_29 -> V_49 ) ;
struct V_111 * V_112 [ V_113 + 1 ] ;
struct V_111 * * V_114 ;
char * V_115 ;
V_35 = F_58 ( V_106 -> V_116 , & V_114 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_114 [ V_117 ] )
return - V_25 ;
V_35 = F_59 ( V_112 , V_113 ,
V_114 [ V_117 ] ,
V_118 ) ;
if ( V_35 )
return V_35 ;
if ( ! V_112 [ V_119 ] )
return - V_25 ;
V_115 = F_60 ( V_112 [ V_119 ] ) ;
F_61 () ;
V_21 = F_62 ( V_27 , V_115 ) ;
if ( ! V_21 ) {
F_63 () ;
return - V_25 ;
}
V_107 = V_21 -> V_120 ;
} else {
struct V_27 * V_27 = F_48 ( V_29 -> V_49 ) ;
struct V_121 * V_122 = F_64 ( V_27 , V_123 ) ;
F_61 () ;
V_21 = F_65 ( V_122 -> V_124 [ V_107 ] ) ;
if ( ! V_21 ) {
F_63 () ;
return - V_25 ;
}
}
V_31 = F_25 ( V_21 -> V_65 ) ;
if ( ! V_31 ) {
F_63 () ;
return - V_25 ;
}
V_110 = 0 ;
F_31 (rcast, tmp, &ub->rcast.list, list) {
if ( V_110 < V_108 )
goto V_125;
V_78 = F_66 ( V_29 , V_109 , V_106 -> V_116 -> V_126 ,
& V_127 , V_128 ,
V_129 ) ;
if ( ! V_78 )
goto V_130;
V_35 = F_54 ( V_29 , & V_60 -> V_2 ,
V_131 ) ;
if ( V_35 ) {
F_67 ( V_29 , V_78 ) ;
goto V_130;
}
F_68 ( V_29 , V_78 ) ;
V_125:
V_110 ++ ;
}
V_130:
F_63 () ;
V_106 -> args [ 0 ] = V_107 ;
V_106 -> args [ 1 ] = V_110 ;
return V_29 -> V_132 ;
}
int F_69 ( struct V_133 * V_22 , struct V_20 * V_21 )
{
struct V_1 * V_32 = (struct V_1 * ) & V_21 -> V_2 . V_13 ;
struct V_1 * V_33 ;
struct V_30 * V_31 ;
struct V_111 * V_134 ;
V_31 = F_25 ( V_21 -> V_65 ) ;
if ( ! V_31 )
return - V_66 ;
V_134 = F_70 ( V_22 -> V_29 , V_135 ) ;
if ( ! V_134 )
goto V_136;
if ( F_54 ( V_22 -> V_29 , V_32 , V_137 ) )
goto V_136;
V_33 = (struct V_1 * ) & V_21 -> V_71 . V_13 ;
if ( F_54 ( V_22 -> V_29 , V_33 , V_131 ) )
goto V_136;
if ( ! F_26 ( & V_31 -> V_60 . V_67 ) ) {
if ( F_71 ( V_22 -> V_29 , V_138 ) )
goto V_136;
}
F_72 ( V_22 -> V_29 , V_134 ) ;
return 0 ;
V_136:
F_73 ( V_22 -> V_29 , V_134 ) ;
return - V_97 ;
}
static int F_74 ( struct V_111 * V_139 , struct V_1 * V_2 ,
T_1 * V_140 )
{
struct V_141 V_142 ;
F_75 ( & V_142 , V_139 , sizeof( V_142 ) ) ;
if ( V_142 . V_143 == V_94 ) {
struct V_91 * V_92 = (struct V_91 * ) & V_142 ;
V_2 -> V_3 = F_12 ( V_4 ) ;
V_2 -> V_18 = V_92 -> V_95 ;
V_2 -> V_5 . V_6 = V_92 -> V_96 . V_6 ;
return 0 ;
#if F_4 ( V_7 )
} else if ( V_142 . V_143 == V_101 ) {
struct V_98 * V_99 = (struct V_98 * ) & V_142 ;
V_2 -> V_3 = F_12 ( V_19 ) ;
V_2 -> V_18 = V_99 -> V_102 ;
memcpy ( & V_2 -> V_8 , & V_99 -> V_103 , sizeof( struct V_104 ) ) ;
if ( V_140 ) {
int V_144 ;
V_144 = F_76 ( & V_99 -> V_103 ) ;
if ( F_77 ( V_144 ) &&
! V_99 -> V_145 ) {
return - V_25 ;
}
* V_140 = V_99 -> V_145 ? : 0 ;
}
return 0 ;
#endif
}
return - V_146 ;
}
int F_78 ( struct V_20 * V_21 , struct V_111 * V_147 )
{
int V_35 ;
struct V_1 V_2 = { 0 } ;
struct V_111 * V_148 [ V_149 + 1 ] ;
struct V_1 * V_33 ;
if ( F_59 ( V_148 , V_149 , V_147 , V_150 ) )
return - V_25 ;
if ( ! V_148 [ V_131 ] )
return - V_25 ;
V_35 = F_74 ( V_148 [ V_131 ] , & V_2 , NULL ) ;
if ( V_35 )
return V_35 ;
V_33 = (struct V_1 * ) & V_21 -> V_71 . V_13 ;
if ( F_1 ( V_33 ) ) {
F_8 ( L_8 ) ;
return - V_25 ;
}
if ( F_29 ( V_21 , & V_2 ) )
return 0 ;
return F_32 ( V_21 , & V_2 ) ;
}
static int F_79 ( struct V_27 * V_27 , struct V_20 * V_21 ,
struct V_111 * V_114 [] )
{
int V_35 = - V_25 ;
struct V_30 * V_31 ;
struct V_1 V_84 = { 0 } ;
struct V_1 V_151 = { 0 } ;
struct V_152 V_153 = { 0 } ;
struct V_154 V_155 = { NULL } ;
struct V_111 * V_148 [ V_149 + 1 ] ;
V_31 = F_80 ( sizeof( * V_31 ) , V_62 ) ;
if ( ! V_31 )
return - V_69 ;
F_81 ( & V_31 -> V_60 . V_67 ) ;
if ( ! V_114 [ V_135 ] )
goto V_35;
if ( F_59 ( V_148 , V_149 ,
V_114 [ V_135 ] ,
V_150 ) )
goto V_35;
if ( ! V_148 [ V_137 ] || ! V_148 [ V_131 ] ) {
F_8 ( L_9 ) ;
V_35 = - V_25 ;
goto V_35;
}
V_35 = F_74 ( V_148 [ V_137 ] , & V_151 ,
& V_31 -> V_55 ) ;
if ( V_35 )
goto V_35;
V_35 = F_74 ( V_148 [ V_131 ] , & V_84 , NULL ) ;
if ( V_35 )
goto V_35;
V_21 -> V_71 . V_11 = V_12 ;
V_21 -> V_71 . V_14 = 1 ;
F_82 ( V_21 -> V_65 , V_31 ) ;
F_82 ( V_31 -> V_80 , V_21 ) ;
F_6 ( & V_21 -> V_2 , & V_151 ) ;
if ( V_151 . V_3 == F_12 ( V_4 ) ) {
struct V_156 * V_47 ;
V_47 = F_83 ( V_27 , V_151 . V_5 . V_6 , false ) ;
if ( ! V_47 ) {
V_35 = - V_66 ;
goto V_35;
}
V_153 . V_157 = V_94 ;
V_153 . V_158 . V_6 = F_84 ( V_159 ) ;
V_153 . V_160 = false ;
V_31 -> V_55 = V_47 -> V_55 ;
if ( F_85 ( V_47 , sizeof( struct V_74 ) +
sizeof( struct V_79 ) ) ) {
V_35 = - V_25 ;
goto V_35;
}
V_21 -> V_161 = V_47 -> V_161 - sizeof( struct V_74 )
- sizeof( struct V_79 ) ;
#if F_4 ( V_7 )
} else if ( V_151 . V_3 == F_12 ( V_19 ) ) {
V_153 . V_157 = V_101 ;
V_153 . V_162 = true ;
V_153 . V_163 = true ;
V_153 . V_164 = V_165 ;
V_21 -> V_161 = 1280 ;
#endif
} else {
V_35 = - V_166 ;
goto V_35;
}
V_153 . V_167 = V_151 . V_18 ;
V_35 = F_86 ( V_27 , & V_153 , & V_31 -> V_48 ) ;
if ( V_35 )
goto V_35;
V_155 . V_168 = V_31 ;
V_155 . V_169 = 1 ;
V_155 . V_170 = F_41 ;
V_155 . V_171 = NULL ;
F_87 ( V_27 , V_31 -> V_48 , & V_155 ) ;
memcpy ( & V_21 -> V_71 . V_13 , & V_84 , sizeof( V_84 ) ) ;
if ( F_1 ( & V_84 ) )
V_35 = F_52 ( V_31 , & V_84 ) ;
else
V_35 = F_32 ( V_21 , & V_84 ) ;
if ( V_35 )
goto V_35;
return 0 ;
V_35:
if ( V_31 -> V_48 )
F_88 ( V_31 -> V_48 ) ;
F_89 ( V_31 ) ;
return V_35 ;
}
static void F_90 ( struct V_172 * V_173 )
{
struct V_30 * V_31 = F_91 ( V_173 , struct V_30 , V_173 ) ;
struct V_59 * V_60 , * V_70 ;
F_31 (rcast, tmp, &ub->rcast.list, list) {
F_92 ( & V_60 -> V_67 ) ;
F_93 ( V_60 , V_174 ) ;
}
if ( V_31 -> V_48 )
F_88 ( V_31 -> V_48 ) ;
F_94 () ;
F_89 ( V_31 ) ;
}
static void F_95 ( struct V_20 * V_21 )
{
struct V_30 * V_31 ;
V_31 = F_25 ( V_21 -> V_65 ) ;
if ( ! V_31 ) {
F_8 ( L_4 ) ;
return;
}
if ( V_31 -> V_48 )
F_96 ( V_31 -> V_48 -> V_49 , V_175 ) ;
F_97 ( V_31 -> V_80 , NULL ) ;
F_98 ( & V_31 -> V_173 , F_90 ) ;
F_99 ( & V_31 -> V_173 ) ;
}
