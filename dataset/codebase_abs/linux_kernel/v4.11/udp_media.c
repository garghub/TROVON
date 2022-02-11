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
V_2 -> V_14 = V_15 ;
}
static int F_7 ( struct V_9 * V_16 , char * V_17 , int V_18 )
{
struct V_1 * V_10 = (struct V_1 * ) & V_16 -> V_13 ;
if ( F_2 ( V_10 -> V_3 ) == V_4 )
snprintf ( V_17 , V_18 , L_1 , & V_10 -> V_5 , F_2 ( V_10 -> V_19 ) ) ;
else if ( F_2 ( V_10 -> V_3 ) == V_20 )
snprintf ( V_17 , V_18 , L_2 , & V_10 -> V_8 , F_2 ( V_10 -> V_19 ) ) ;
else
F_8 ( L_3 ) ;
return 0 ;
}
static int F_9 ( struct V_21 * V_22 , struct V_9 * V_16 ,
char * V_23 )
{
struct V_1 * V_10 ;
V_10 = (struct V_1 * ) ( V_23 + V_24 ) ;
if ( V_23 [ V_25 ] != V_12 )
return - V_26 ;
F_6 ( V_16 , V_10 ) ;
return 0 ;
}
static int F_10 ( char * V_23 , struct V_9 * V_16 )
{
memset ( V_23 , 0 , V_27 ) ;
V_23 [ V_25 ] = V_12 ;
memcpy ( V_23 + V_24 , V_16 -> V_13 ,
sizeof( struct V_1 ) ) ;
return 0 ;
}
static int F_11 ( struct V_28 * V_28 , struct V_29 * V_30 ,
struct V_31 * V_32 , struct V_1 * V_33 ,
struct V_1 * V_34 )
{
int V_35 , V_36 = 0 ;
struct V_37 * V_38 ;
if ( V_34 -> V_3 == F_12 ( V_4 ) ) {
struct V_39 V_40 = {
. V_41 = V_34 -> V_5 . V_6 ,
. V_42 = V_33 -> V_5 . V_6 ,
. V_43 = V_30 -> V_44 ,
. V_45 = V_46
} ;
V_38 = F_13 ( V_28 , & V_40 ) ;
if ( F_14 ( V_38 ) ) {
V_36 = F_15 ( V_38 ) ;
goto V_47;
}
V_30 -> V_48 = V_38 -> V_34 . V_48 ;
V_35 = F_16 ( & V_38 -> V_34 ) ;
F_17 ( V_38 , V_32 -> V_49 -> V_50 , V_30 , V_33 -> V_5 . V_6 ,
V_34 -> V_5 . V_6 , 0 , V_35 , 0 , V_33 -> V_19 ,
V_34 -> V_19 , false , true ) ;
#if F_4 ( V_7 )
} else {
struct V_51 * V_52 ;
struct V_53 V_54 = {
. V_55 = V_32 -> V_56 ,
. V_41 = V_34 -> V_8 ,
. V_42 = V_33 -> V_8 ,
. V_57 = V_46
} ;
V_36 = V_58 -> V_59 ( V_28 , V_32 -> V_49 -> V_50 , & V_52 ,
& V_54 ) ;
if ( V_36 )
goto V_47;
V_35 = F_18 ( V_52 ) ;
V_36 = F_19 ( V_52 , V_32 -> V_49 -> V_50 , V_30 ,
V_52 -> V_48 , & V_33 -> V_8 ,
& V_34 -> V_8 , 0 , V_35 , 0 , V_33 -> V_19 ,
V_34 -> V_19 , false ) ;
#endif
}
return V_36 ;
V_47:
F_20 ( V_30 ) ;
return V_36 ;
}
static int F_21 ( struct V_28 * V_28 , struct V_29 * V_30 ,
struct V_21 * V_22 ,
struct V_9 * V_2 )
{
struct V_1 * V_33 = (struct V_1 * ) & V_22 -> V_2 . V_13 ;
struct V_1 * V_34 = (struct V_1 * ) & V_2 -> V_13 ;
struct V_60 * V_61 ;
struct V_31 * V_32 ;
int V_36 = 0 ;
if ( F_22 ( V_30 ) < V_62 ) {
V_36 = F_23 ( V_30 , V_62 , 0 , V_63 ) ;
if ( V_36 )
goto V_64;
}
F_24 ( V_30 , F_12 ( V_65 ) ) ;
V_32 = F_25 ( V_22 -> V_66 ) ;
if ( ! V_32 ) {
V_36 = - V_67 ;
goto V_64;
}
if ( V_2 -> V_14 != V_68 )
return F_11 ( V_28 , V_30 , V_32 , V_33 , V_34 ) ;
F_26 (rcast, &ub->rcast.list, list) {
struct V_29 * V_69 ;
V_69 = F_27 ( V_30 , V_63 ) ;
if ( ! V_69 ) {
V_36 = - V_70 ;
goto V_64;
}
V_36 = F_11 ( V_28 , V_69 , V_32 , V_33 , & V_61 -> V_2 ) ;
if ( V_36 ) {
F_20 ( V_69 ) ;
goto V_64;
}
}
V_36 = 0 ;
V_64:
F_20 ( V_30 ) ;
return V_36 ;
}
static bool F_28 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_60 * V_61 , * V_71 ;
struct V_31 * V_32 ;
V_32 = F_25 ( V_22 -> V_66 ) ;
if ( ! V_32 ) {
F_29 ( L_4 ) ;
return false ;
}
F_30 (rcast, tmp, &ub->rcast.list, list) {
if ( ! memcmp ( & V_61 -> V_2 , V_2 , sizeof( struct V_1 ) ) )
return true ;
}
return false ;
}
static int F_31 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_60 * V_61 ;
struct V_31 * V_32 ;
V_32 = F_25 ( V_22 -> V_66 ) ;
if ( ! V_32 )
return - V_67 ;
V_61 = F_32 ( sizeof( * V_61 ) , V_63 ) ;
if ( ! V_61 )
return - V_70 ;
memcpy ( & V_61 -> V_2 , V_2 , sizeof( struct V_1 ) ) ;
if ( F_2 ( V_2 -> V_3 ) == V_4 )
F_33 ( L_5 , & V_61 -> V_2 . V_5 ) ;
#if F_4 ( V_7 )
else if ( F_2 ( V_2 -> V_3 ) == V_20 )
F_33 ( L_6 , & V_61 -> V_2 . V_8 ) ;
#endif
V_22 -> V_72 . V_14 = V_68 ;
F_34 ( & V_61 -> V_73 , & V_32 -> V_61 . V_73 ) ;
return 0 ;
}
static int F_35 ( struct V_21 * V_22 , struct V_29 * V_30 )
{
struct V_1 V_33 = { 0 } ;
struct V_1 * V_34 ;
V_34 = (struct V_1 * ) & V_22 -> V_72 . V_13 ;
if ( F_1 ( V_34 ) )
return 0 ;
V_33 . V_19 = F_36 ( V_30 ) -> V_74 ;
if ( F_37 ( V_30 ) -> V_75 == 4 ) {
struct V_76 * V_76 = F_37 ( V_30 ) ;
V_33 . V_3 = F_12 ( V_4 ) ;
V_33 . V_5 . V_6 = V_76 -> V_42 ;
if ( F_3 ( V_76 -> V_41 ) )
return 0 ;
#if F_4 ( V_7 )
} else if ( F_37 ( V_30 ) -> V_75 == 6 ) {
struct V_77 * V_76 = F_38 ( V_30 ) ;
V_33 . V_3 = F_12 ( V_20 ) ;
V_33 . V_8 = V_76 -> V_42 ;
if ( F_5 ( & V_76 -> V_41 ) )
return 0 ;
#endif
} else {
return 0 ;
}
if ( F_39 ( F_28 ( V_22 , & V_33 ) ) )
return 0 ;
return F_31 ( V_22 , & V_33 ) ;
}
static int F_40 ( struct V_78 * V_50 , struct V_29 * V_30 )
{
struct V_31 * V_32 ;
struct V_21 * V_22 ;
struct V_79 * V_80 ;
int V_36 ;
V_32 = F_41 ( V_50 ) ;
if ( ! V_32 ) {
F_29 ( L_7 ) ;
goto V_64;
}
F_42 ( V_30 , sizeof( struct V_81 ) ) ;
V_80 = F_43 ( V_30 ) ;
F_44 () ;
V_22 = F_25 ( V_32 -> V_82 ) ;
if ( ! V_22 )
goto V_83;
if ( V_22 && F_45 ( 0 , & V_22 -> V_84 ) ) {
F_46 ( F_47 ( V_50 ) , V_30 , V_22 ) ;
F_48 () ;
return 0 ;
}
if ( F_49 ( F_50 ( V_80 ) == V_85 ) ) {
V_36 = F_35 ( V_22 , V_30 ) ;
if ( V_36 )
goto V_83;
}
F_46 ( F_47 ( V_50 ) , V_30 , V_22 ) ;
F_48 () ;
return 0 ;
V_83:
F_48 () ;
V_64:
F_20 ( V_30 ) ;
return 0 ;
}
static int F_51 ( struct V_31 * V_32 , struct V_1 * V_86 )
{
int V_36 = 0 ;
struct V_87 V_88 ;
struct V_78 * V_50 = V_32 -> V_49 -> V_50 ;
if ( F_2 ( V_86 -> V_3 ) == V_4 ) {
V_88 . V_89 = V_86 -> V_5 ;
V_88 . V_90 = V_32 -> V_56 ;
V_36 = F_52 ( V_50 , & V_88 ) ;
#if F_4 ( V_7 )
} else {
V_36 = V_58 -> V_91 ( V_50 , V_32 -> V_56 ,
& V_86 -> V_8 ) ;
#endif
}
return V_36 ;
}
static int F_53 ( struct V_29 * V_30 ,
struct V_1 * V_2 , int V_92 )
{
if ( F_2 ( V_2 -> V_3 ) == V_4 ) {
struct V_93 V_94 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_95 = V_96 ;
V_94 . V_97 = V_2 -> V_19 ;
V_94 . V_98 . V_6 = V_2 -> V_5 . V_6 ;
if ( F_54 ( V_30 , V_92 , sizeof( V_94 ) , & V_94 ) )
return - V_99 ;
#if F_4 ( V_7 )
} else if ( F_2 ( V_2 -> V_3 ) == V_20 ) {
struct V_100 V_101 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_102 = V_103 ;
V_101 . V_104 = V_2 -> V_19 ;
memcpy ( & V_101 . V_105 , & V_2 -> V_8 , sizeof( struct V_106 ) ) ;
if ( F_54 ( V_30 , V_92 , sizeof( V_101 ) , & V_101 ) )
return - V_99 ;
#endif
}
return 0 ;
}
int F_55 ( struct V_29 * V_30 , struct V_107 * V_108 )
{
T_1 V_109 = V_108 -> args [ 0 ] ;
T_1 V_110 = V_108 -> args [ 1 ] ;
T_1 V_111 = F_56 ( V_108 -> V_30 ) . V_111 ;
struct V_60 * V_61 , * V_71 ;
struct V_21 * V_22 ;
struct V_31 * V_32 ;
void * V_80 ;
int V_36 ;
int V_112 ;
if ( ! V_109 && ! V_110 ) {
struct V_28 * V_28 = F_47 ( V_30 -> V_50 ) ;
struct V_113 * V_114 [ V_115 + 1 ] ;
struct V_113 * * V_116 ;
char * V_117 ;
V_36 = F_57 ( V_108 -> V_118 , & V_116 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_116 [ V_119 ] )
return - V_26 ;
V_36 = F_58 ( V_114 , V_115 ,
V_116 [ V_119 ] ,
V_120 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_114 [ V_121 ] )
return - V_26 ;
V_117 = F_59 ( V_114 [ V_121 ] ) ;
F_60 () ;
V_22 = F_61 ( V_28 , V_117 ) ;
if ( ! V_22 ) {
F_62 () ;
return - V_26 ;
}
V_109 = V_22 -> V_122 ;
} else {
struct V_28 * V_28 = F_47 ( V_30 -> V_50 ) ;
struct V_123 * V_124 = F_63 ( V_28 , V_125 ) ;
F_60 () ;
V_22 = F_64 ( V_124 -> V_126 [ V_109 ] ) ;
if ( ! V_22 ) {
F_62 () ;
return - V_26 ;
}
}
V_32 = F_25 ( V_22 -> V_66 ) ;
if ( ! V_32 ) {
F_62 () ;
return - V_26 ;
}
V_112 = 0 ;
F_30 (rcast, tmp, &ub->rcast.list, list) {
if ( V_112 < V_110 )
goto V_127;
V_80 = F_65 ( V_30 , V_111 , V_108 -> V_118 -> V_128 ,
& V_129 , V_130 ,
V_131 ) ;
if ( ! V_80 )
goto V_132;
V_36 = F_53 ( V_30 , & V_61 -> V_2 ,
V_133 ) ;
if ( V_36 ) {
F_66 ( V_30 , V_80 ) ;
goto V_132;
}
F_67 ( V_30 , V_80 ) ;
V_127:
V_112 ++ ;
}
V_132:
F_62 () ;
V_108 -> args [ 0 ] = V_109 ;
V_108 -> args [ 1 ] = V_112 ;
return V_30 -> V_134 ;
}
int F_68 ( struct V_135 * V_23 , struct V_21 * V_22 )
{
struct V_1 * V_33 = (struct V_1 * ) & V_22 -> V_2 . V_13 ;
struct V_1 * V_34 ;
struct V_31 * V_32 ;
struct V_113 * V_136 ;
V_32 = F_25 ( V_22 -> V_66 ) ;
if ( ! V_32 )
return - V_67 ;
V_136 = F_69 ( V_23 -> V_30 , V_137 ) ;
if ( ! V_136 )
goto V_138;
if ( F_53 ( V_23 -> V_30 , V_33 , V_139 ) )
goto V_138;
V_34 = (struct V_1 * ) & V_22 -> V_72 . V_13 ;
if ( F_53 ( V_23 -> V_30 , V_34 , V_133 ) )
goto V_138;
if ( ! F_70 ( & V_32 -> V_61 . V_73 ) ) {
if ( F_71 ( V_23 -> V_30 , V_140 ) )
goto V_138;
}
F_72 ( V_23 -> V_30 , V_136 ) ;
return 0 ;
V_138:
F_73 ( V_23 -> V_30 , V_136 ) ;
return - V_99 ;
}
static int F_74 ( struct V_113 * V_141 , struct V_1 * V_2 ,
T_1 * V_142 )
{
struct V_143 V_144 ;
F_75 ( & V_144 , V_141 , sizeof( V_144 ) ) ;
if ( V_144 . V_145 == V_96 ) {
struct V_93 * V_94 = (struct V_93 * ) & V_144 ;
V_2 -> V_3 = F_12 ( V_4 ) ;
V_2 -> V_19 = V_94 -> V_97 ;
V_2 -> V_5 . V_6 = V_94 -> V_98 . V_6 ;
return 0 ;
#if F_4 ( V_7 )
} else if ( V_144 . V_145 == V_103 ) {
struct V_100 * V_101 = (struct V_100 * ) & V_144 ;
V_2 -> V_3 = F_12 ( V_20 ) ;
V_2 -> V_19 = V_101 -> V_104 ;
memcpy ( & V_2 -> V_8 , & V_101 -> V_105 , sizeof( struct V_106 ) ) ;
if ( V_142 ) {
int V_146 ;
V_146 = F_76 ( & V_101 -> V_105 ) ;
if ( F_77 ( V_146 ) &&
! V_101 -> V_147 ) {
return - V_26 ;
}
* V_142 = V_101 -> V_147 ? : 0 ;
}
return 0 ;
#endif
}
return - V_148 ;
}
int F_78 ( struct V_21 * V_22 , struct V_113 * V_149 )
{
int V_36 ;
struct V_1 V_2 = { 0 } ;
struct V_113 * V_150 [ V_151 + 1 ] ;
struct V_1 * V_34 ;
if ( F_58 ( V_150 , V_151 , V_149 , V_152 ) )
return - V_26 ;
if ( ! V_150 [ V_133 ] )
return - V_26 ;
V_36 = F_74 ( V_150 [ V_133 ] , & V_2 , NULL ) ;
if ( V_36 )
return V_36 ;
V_34 = (struct V_1 * ) & V_22 -> V_72 . V_13 ;
if ( F_1 ( V_34 ) ) {
F_8 ( L_8 ) ;
return - V_26 ;
}
if ( F_28 ( V_22 , & V_2 ) )
return 0 ;
return F_31 ( V_22 , & V_2 ) ;
}
static int F_79 ( struct V_28 * V_28 , struct V_21 * V_22 ,
struct V_113 * V_116 [] )
{
int V_36 = - V_26 ;
struct V_31 * V_32 ;
struct V_1 V_86 = { 0 } ;
struct V_1 V_153 = { 0 } ;
struct V_154 V_155 = { 0 } ;
struct V_156 V_157 = { NULL } ;
struct V_113 * V_150 [ V_151 + 1 ] ;
V_32 = F_80 ( sizeof( * V_32 ) , V_63 ) ;
if ( ! V_32 )
return - V_70 ;
F_81 ( & V_32 -> V_61 . V_73 ) ;
if ( ! V_116 [ V_137 ] )
goto V_36;
if ( F_58 ( V_150 , V_151 ,
V_116 [ V_137 ] ,
V_152 ) )
goto V_36;
if ( ! V_150 [ V_139 ] || ! V_150 [ V_133 ] ) {
F_8 ( L_9 ) ;
V_36 = - V_26 ;
goto V_36;
}
V_36 = F_74 ( V_150 [ V_139 ] , & V_153 ,
& V_32 -> V_56 ) ;
if ( V_36 )
goto V_36;
V_36 = F_74 ( V_150 [ V_133 ] , & V_86 , NULL ) ;
if ( V_36 )
goto V_36;
V_22 -> V_72 . V_11 = V_12 ;
V_22 -> V_72 . V_14 = V_15 ;
F_82 ( V_22 -> V_66 , V_32 ) ;
F_82 ( V_32 -> V_82 , V_22 ) ;
F_6 ( & V_22 -> V_2 , & V_153 ) ;
if ( V_153 . V_3 == F_12 ( V_4 ) ) {
struct V_158 * V_48 ;
V_48 = F_83 ( V_28 , V_153 . V_5 . V_6 , false ) ;
if ( ! V_48 ) {
V_36 = - V_67 ;
goto V_36;
}
V_155 . V_159 = V_96 ;
V_155 . V_160 . V_6 = F_84 ( V_161 ) ;
V_155 . V_162 = false ;
V_32 -> V_56 = V_48 -> V_56 ;
if ( F_85 ( V_48 , sizeof( struct V_76 ) +
sizeof( struct V_81 ) ) ) {
V_36 = - V_26 ;
goto V_36;
}
V_22 -> V_163 = V_48 -> V_163 - sizeof( struct V_76 )
- sizeof( struct V_81 ) ;
#if F_4 ( V_7 )
} else if ( V_153 . V_3 == F_12 ( V_20 ) ) {
V_155 . V_159 = V_103 ;
V_155 . V_164 = true ;
V_155 . V_165 = true ;
V_155 . V_166 = V_167 ;
V_22 -> V_163 = 1280 ;
#endif
} else {
V_36 = - V_168 ;
goto V_36;
}
V_155 . V_169 = V_153 . V_19 ;
V_36 = F_86 ( V_28 , & V_155 , & V_32 -> V_49 ) ;
if ( V_36 )
goto V_36;
V_157 . V_170 = V_32 ;
V_157 . V_171 = 1 ;
V_157 . V_172 = F_40 ;
V_157 . V_173 = NULL ;
F_87 ( V_28 , V_32 -> V_49 , & V_157 ) ;
memcpy ( & V_22 -> V_72 . V_13 , & V_86 , sizeof( V_86 ) ) ;
if ( F_1 ( & V_86 ) )
V_36 = F_51 ( V_32 , & V_86 ) ;
else
V_36 = F_31 ( V_22 , & V_86 ) ;
if ( V_36 )
goto V_36;
return 0 ;
V_36:
if ( V_32 -> V_49 )
F_88 ( V_32 -> V_49 ) ;
F_89 ( V_32 ) ;
return V_36 ;
}
static void F_90 ( struct V_174 * V_175 )
{
struct V_31 * V_32 = F_91 ( V_175 , struct V_31 , V_175 ) ;
struct V_60 * V_61 , * V_71 ;
F_30 (rcast, tmp, &ub->rcast.list, list) {
F_92 ( & V_61 -> V_73 ) ;
F_93 ( V_61 , V_176 ) ;
}
if ( V_32 -> V_49 )
F_88 ( V_32 -> V_49 ) ;
F_94 () ;
F_89 ( V_32 ) ;
}
static void F_95 ( struct V_21 * V_22 )
{
struct V_31 * V_32 ;
V_32 = F_25 ( V_22 -> V_66 ) ;
if ( ! V_32 ) {
F_8 ( L_4 ) ;
return;
}
if ( V_32 -> V_49 )
F_96 ( V_32 -> V_49 -> V_50 , V_177 ) ;
F_97 ( V_32 -> V_82 , NULL ) ;
F_98 ( & V_32 -> V_175 , F_90 ) ;
F_99 ( & V_32 -> V_175 ) ;
}
