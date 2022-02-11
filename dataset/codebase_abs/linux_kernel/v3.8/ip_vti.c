static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_1 * V_4 )
{
int V_5 ;
F_2 (i) {
const struct V_6 * V_7 = F_3 ( V_3 -> V_7 , V_5 ) ;
T_1 V_8 , V_9 , V_10 , V_11 ;
unsigned int V_12 ;
do {
V_12 = F_4 ( & V_7 -> V_13 ) ;
V_8 = V_7 -> V_8 ;
V_10 = V_7 -> V_10 ;
V_9 = V_7 -> V_9 ;
V_11 = V_7 -> V_11 ;
} while ( F_5 ( & V_7 -> V_13 , V_12 ) );
V_4 -> V_8 += V_8 ;
V_4 -> V_10 += V_10 ;
V_4 -> V_9 += V_9 ;
V_4 -> V_11 += V_11 ;
}
V_4 -> V_14 = V_3 -> V_15 . V_14 ;
V_4 -> V_16 = V_3 -> V_15 . V_16 ;
V_4 -> V_17 = V_3 -> V_15 . V_17 ;
V_4 -> V_18 = V_3 -> V_15 . V_18 ;
V_4 -> V_19 = V_3 -> V_15 . V_19 ;
V_4 -> V_20 = V_3 -> V_15 . V_20 ;
V_4 -> V_21 = V_3 -> V_15 . V_21 ;
V_4 -> V_22 = V_3 -> V_15 . V_22 ;
V_4 -> V_23 = V_3 -> V_15 . V_23 ;
V_4 -> V_24 = V_3 -> V_15 . V_24 ;
return V_4 ;
}
static struct V_25 * F_6 ( struct V_26 * V_26 ,
T_2 V_27 , T_2 V_28 )
{
unsigned V_29 = F_7 ( V_27 ) ;
unsigned V_30 = F_7 ( V_28 ) ;
struct V_25 * V_31 ;
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
F_9 (t, ipn->tunnels_r_l[h0 ^ h1])
if ( V_28 == V_31 -> V_35 . V_36 . V_37 &&
V_27 == V_31 -> V_35 . V_36 . V_38 && ( V_31 -> V_3 -> V_39 & V_40 ) )
return V_31 ;
F_9 (t, ipn->tunnels_r[h0])
if ( V_27 == V_31 -> V_35 . V_36 . V_38 && ( V_31 -> V_3 -> V_39 & V_40 ) )
return V_31 ;
F_9 (t, ipn->tunnels_l[h1])
if ( V_28 == V_31 -> V_35 . V_36 . V_37 && ( V_31 -> V_3 -> V_39 & V_40 ) )
return V_31 ;
F_9 (t, ipn->tunnels_wc[0])
if ( V_31 && ( V_31 -> V_3 -> V_39 & V_40 ) )
return V_31 ;
return NULL ;
}
static struct V_25 T_3 * * F_10 ( struct V_32 * V_33 ,
struct V_41 * V_35 )
{
T_2 V_27 = V_35 -> V_36 . V_38 ;
T_2 V_28 = V_35 -> V_36 . V_37 ;
unsigned V_42 = 0 ;
int V_43 = 0 ;
if ( V_27 ) {
V_43 |= 2 ;
V_42 ^= F_7 ( V_27 ) ;
}
if ( V_28 ) {
V_43 |= 1 ;
V_42 ^= F_7 ( V_28 ) ;
}
return & V_33 -> V_44 [ V_43 ] [ V_42 ] ;
}
static inline struct V_25 T_3 * * F_11 ( struct V_32 * V_33 ,
struct V_25 * V_31 )
{
return F_10 ( V_33 , & V_31 -> V_35 ) ;
}
static void F_12 ( struct V_32 * V_33 , struct V_25 * V_31 )
{
struct V_25 T_3 * * V_45 ;
struct V_25 * V_46 ;
for ( V_45 = F_11 ( V_33 , V_31 ) ;
( V_46 = F_13 ( * V_45 ) ) != NULL ;
V_45 = & V_46 -> V_47 ) {
if ( V_31 == V_46 ) {
F_14 ( * V_45 , V_31 -> V_47 ) ;
break;
}
}
}
static void F_15 ( struct V_32 * V_33 , struct V_25 * V_31 )
{
struct V_25 T_3 * * V_45 = F_11 ( V_33 , V_31 ) ;
F_14 ( V_31 -> V_47 , F_13 ( * V_45 ) ) ;
F_14 ( * V_45 , V_31 ) ;
}
static struct V_25 * F_16 ( struct V_26 * V_26 ,
struct V_41 * V_35 ,
int V_48 )
{
T_2 V_27 = V_35 -> V_36 . V_38 ;
T_2 V_28 = V_35 -> V_36 . V_37 ;
struct V_25 * V_31 , * V_49 ;
struct V_25 T_3 * * V_45 ;
struct V_2 * V_3 ;
char V_50 [ V_51 ] ;
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
for ( V_45 = F_10 ( V_33 , V_35 ) ;
( V_31 = F_13 ( * V_45 ) ) != NULL ;
V_45 = & V_31 -> V_47 ) {
if ( V_28 == V_31 -> V_35 . V_36 . V_37 && V_27 == V_31 -> V_35 . V_36 . V_38 )
return V_31 ;
}
if ( ! V_48 )
return NULL ;
if ( V_35 -> V_50 [ 0 ] )
F_17 ( V_50 , V_35 -> V_50 , V_51 ) ;
else
strcpy ( V_50 , L_1 ) ;
V_3 = F_18 ( sizeof( * V_31 ) , V_50 , V_52 ) ;
if ( V_3 == NULL )
return NULL ;
F_19 ( V_3 , V_26 ) ;
V_49 = F_20 ( V_3 ) ;
V_49 -> V_35 = * V_35 ;
V_3 -> V_53 = & V_54 ;
F_21 ( V_3 ) ;
if ( F_22 ( V_3 ) < 0 )
goto V_55;
F_23 ( V_3 ) ;
F_15 ( V_33 , V_49 ) ;
return V_49 ;
V_55:
F_24 ( V_3 ) ;
return NULL ;
}
static void F_25 ( struct V_2 * V_3 )
{
struct V_26 * V_26 = F_26 ( V_3 ) ;
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
F_12 ( V_33 , F_20 ( V_3 ) ) ;
F_27 ( V_3 ) ;
}
static int F_28 ( struct V_56 * V_57 , T_4 V_58 )
{
struct V_59 * V_36 = (struct V_59 * ) V_57 -> V_60 ;
const int type = F_29 ( V_57 ) -> type ;
const int V_61 = F_29 ( V_57 ) -> V_61 ;
struct V_25 * V_31 ;
int V_62 ;
switch ( type ) {
default:
case V_63 :
return 0 ;
case V_64 :
switch ( V_61 ) {
case V_65 :
case V_66 :
return 0 ;
default:
break;
}
break;
case V_67 :
if ( V_61 != V_68 )
return 0 ;
break;
}
V_62 = - V_69 ;
V_31 = F_6 ( F_26 ( V_57 -> V_3 ) , V_36 -> V_38 , V_36 -> V_37 ) ;
if ( V_31 == NULL )
goto V_70;
if ( type == V_64 && V_61 == V_71 ) {
F_30 ( V_57 , F_26 ( V_57 -> V_3 ) , V_58 ,
V_31 -> V_35 . V_72 , 0 , V_73 , 0 ) ;
V_62 = 0 ;
goto V_70;
}
V_62 = 0 ;
if ( V_31 -> V_35 . V_36 . V_74 == 0 && type == V_67 )
goto V_70;
if ( F_31 ( V_75 , V_31 -> V_76 + V_77 ) )
V_31 -> V_78 ++ ;
else
V_31 -> V_78 = 1 ;
V_31 -> V_76 = V_75 ;
V_70:
return V_62 ;
}
static int F_32 ( struct V_56 * V_57 )
{
struct V_25 * V_79 ;
const struct V_59 * V_36 = F_33 ( V_57 ) ;
V_79 = F_6 ( F_26 ( V_57 -> V_3 ) , V_36 -> V_37 , V_36 -> V_38 ) ;
if ( V_79 != NULL ) {
struct V_6 * V_7 ;
if ( ! F_34 ( NULL , V_80 , V_57 ) )
return - 1 ;
V_7 = F_35 ( V_79 -> V_3 -> V_7 ) ;
F_36 ( & V_7 -> V_13 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_57 -> V_81 ;
F_37 ( & V_7 -> V_13 ) ;
V_57 -> V_82 = 0 ;
F_38 ( V_57 ) ;
V_57 -> V_3 = V_79 -> V_3 ;
return 1 ;
}
return - 1 ;
}
static T_5 F_39 ( struct V_56 * V_57 , struct V_2 * V_3 )
{
struct V_25 * V_79 = F_20 ( V_3 ) ;
struct V_6 * V_7 ;
struct V_59 * V_83 = & V_79 -> V_35 . V_36 ;
T_6 V_84 ;
struct V_85 * V_86 ;
struct V_2 * V_87 ;
struct V_59 * V_88 = F_33 ( V_57 ) ;
T_2 V_89 = V_83 -> V_38 ;
struct V_90 V_91 ;
if ( V_57 -> V_92 != F_40 ( V_93 ) )
goto V_94;
V_84 = V_88 -> V_84 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
F_41 ( & V_91 , V_79 -> V_35 . V_72 ,
F_42 ( V_79 -> V_35 . V_95 ) , F_43 ( V_84 ) ,
V_96 ,
V_73 , 0 ,
V_89 , V_83 -> V_37 , 0 , 0 ) ;
V_86 = F_44 ( F_26 ( V_3 ) , & V_91 ) ;
if ( F_45 ( V_86 ) ) {
V_3 -> V_15 . V_21 ++ ;
goto V_97;
}
if ( ! V_86 -> V_89 . V_98 ||
V_86 -> V_89 . V_98 -> V_99 . V_100 != V_101 ) {
V_3 -> V_15 . V_21 ++ ;
goto V_97;
}
V_87 = V_86 -> V_89 . V_3 ;
if ( V_87 == V_3 ) {
F_46 ( V_86 ) ;
V_3 -> V_15 . V_102 ++ ;
goto V_94;
}
if ( V_79 -> V_78 > 0 ) {
if ( F_31 ( V_75 ,
V_79 -> V_76 + V_77 ) ) {
V_79 -> V_78 -- ;
F_47 ( V_57 ) ;
} else
V_79 -> V_78 = 0 ;
}
F_48 ( V_57 ) -> V_39 &= ~ ( V_103 | V_104 |
V_105 ) ;
F_49 ( V_57 ) ;
F_50 ( V_57 , & V_86 -> V_89 ) ;
F_51 ( V_57 ) ;
V_57 -> V_3 = F_52 ( V_57 ) -> V_3 ;
V_7 = F_35 ( V_3 -> V_7 ) ;
F_53 ( V_7 , & V_3 -> V_15 ) ;
return V_106 ;
V_97:
F_47 ( V_57 ) ;
V_94:
V_3 -> V_15 . V_24 ++ ;
F_54 ( V_57 ) ;
return V_106 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_2 * V_87 = NULL ;
struct V_25 * V_79 ;
struct V_59 * V_36 ;
V_79 = F_20 ( V_3 ) ;
V_36 = & V_79 -> V_35 . V_36 ;
if ( V_36 -> V_38 ) {
struct V_85 * V_86 ;
struct V_90 V_91 ;
memset ( & V_91 , 0 , sizeof( V_91 ) ) ;
F_41 ( & V_91 , V_79 -> V_35 . V_72 ,
F_42 ( V_79 -> V_35 . V_95 ) ,
F_43 ( V_36 -> V_84 ) , V_96 ,
V_73 , 0 ,
V_36 -> V_38 , V_36 -> V_37 , 0 , 0 ) ;
V_86 = F_44 ( F_26 ( V_3 ) , & V_91 ) ;
if ( ! F_45 ( V_86 ) ) {
V_87 = V_86 -> V_89 . V_3 ;
F_46 ( V_86 ) ;
}
V_3 -> V_39 |= V_107 ;
}
if ( ! V_87 && V_79 -> V_35 . V_72 )
V_87 = F_55 ( F_26 ( V_3 ) , V_79 -> V_35 . V_72 ) ;
if ( V_87 ) {
V_3 -> V_108 = V_87 -> V_108 +
sizeof( struct V_59 ) ;
V_3 -> V_109 = V_87 -> V_109 ;
}
V_3 -> V_110 = V_79 -> V_35 . V_72 ;
return V_3 -> V_109 ;
}
static int
F_56 ( struct V_2 * V_3 , struct V_111 * V_112 , int V_113 )
{
int V_62 = 0 ;
struct V_41 V_114 ;
struct V_25 * V_31 ;
struct V_26 * V_26 = F_26 ( V_3 ) ;
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
switch ( V_113 ) {
case V_115 :
V_31 = NULL ;
if ( V_3 == V_33 -> V_116 ) {
if ( F_57 ( & V_114 , V_112 -> V_117 . V_118 ,
sizeof( V_114 ) ) ) {
V_62 = - V_119 ;
break;
}
V_31 = F_16 ( V_26 , & V_114 , 0 ) ;
}
if ( V_31 == NULL )
V_31 = F_20 ( V_3 ) ;
memcpy ( & V_114 , & V_31 -> V_35 , sizeof( V_114 ) ) ;
V_114 . V_120 |= V_121 | V_122 ;
V_114 . V_123 |= V_121 ;
if ( F_58 ( V_112 -> V_117 . V_118 , & V_114 , sizeof( V_114 ) ) )
V_62 = - V_119 ;
break;
case V_124 :
case V_125 :
V_62 = - V_126 ;
if ( ! F_59 ( V_26 -> V_127 , V_128 ) )
goto V_129;
V_62 = - V_119 ;
if ( F_57 ( & V_114 , V_112 -> V_117 . V_118 , sizeof( V_114 ) ) )
goto V_129;
V_62 = - V_130 ;
if ( V_114 . V_36 . V_131 != 4 || V_114 . V_36 . V_92 != V_73 ||
V_114 . V_36 . V_132 != 5 )
goto V_129;
V_31 = F_16 ( V_26 , & V_114 , V_113 == V_124 ) ;
if ( V_3 != V_33 -> V_116 && V_113 == V_125 ) {
if ( V_31 != NULL ) {
if ( V_31 -> V_3 != V_3 ) {
V_62 = - V_133 ;
break;
}
} else {
if ( ( ( V_3 -> V_39 & V_107 ) &&
! V_114 . V_36 . V_38 ) ||
( ! ( V_3 -> V_39 & V_107 ) &&
V_114 . V_36 . V_38 ) ) {
V_62 = - V_130 ;
break;
}
V_31 = F_20 ( V_3 ) ;
F_12 ( V_33 , V_31 ) ;
F_60 () ;
V_31 -> V_35 . V_36 . V_37 = V_114 . V_36 . V_37 ;
V_31 -> V_35 . V_36 . V_38 = V_114 . V_36 . V_38 ;
V_31 -> V_35 . V_95 = V_114 . V_95 ;
V_31 -> V_35 . V_134 = V_114 . V_134 ;
V_31 -> V_35 . V_36 . V_92 = V_73 ;
memcpy ( V_3 -> V_135 , & V_114 . V_36 . V_37 , 4 ) ;
memcpy ( V_3 -> V_136 , & V_114 . V_36 . V_38 , 4 ) ;
F_15 ( V_33 , V_31 ) ;
F_61 ( V_3 ) ;
}
}
if ( V_31 ) {
V_62 = 0 ;
if ( V_113 == V_125 ) {
V_31 -> V_35 . V_95 = V_114 . V_95 ;
V_31 -> V_35 . V_134 = V_114 . V_134 ;
if ( V_31 -> V_35 . V_72 != V_114 . V_72 ) {
V_31 -> V_35 . V_72 = V_114 . V_72 ;
F_21 ( V_3 ) ;
F_61 ( V_3 ) ;
}
}
V_114 . V_120 |= V_121 | V_122 ;
V_114 . V_123 |= V_121 ;
if ( F_58 ( V_112 -> V_117 . V_118 , & V_31 -> V_35 ,
sizeof( V_114 ) ) )
V_62 = - V_119 ;
} else
V_62 = ( V_113 == V_124 ? - V_137 : - V_69 ) ;
break;
case V_138 :
V_62 = - V_126 ;
if ( ! F_59 ( V_26 -> V_127 , V_128 ) )
goto V_129;
if ( V_3 == V_33 -> V_116 ) {
V_62 = - V_119 ;
if ( F_57 ( & V_114 , V_112 -> V_117 . V_118 ,
sizeof( V_114 ) ) )
goto V_129;
V_62 = - V_69 ;
V_31 = F_16 ( V_26 , & V_114 , 0 ) ;
if ( V_31 == NULL )
goto V_129;
V_62 = - V_126 ;
if ( V_31 -> V_3 == V_33 -> V_116 )
goto V_129;
V_3 = V_31 -> V_3 ;
}
F_62 ( V_3 ) ;
V_62 = 0 ;
break;
default:
V_62 = - V_130 ;
}
V_129:
return V_62 ;
}
static int F_63 ( struct V_2 * V_3 , int V_139 )
{
if ( V_139 < 68 || V_139 > 0xFFF8 )
return - V_130 ;
V_3 -> V_109 = V_139 ;
return 0 ;
}
static void F_64 ( struct V_2 * V_3 )
{
F_65 ( V_3 -> V_7 ) ;
F_24 ( V_3 ) ;
}
static void V_52 ( struct V_2 * V_3 )
{
V_3 -> V_140 = & V_141 ;
V_3 -> V_142 = F_64 ;
V_3 -> type = V_143 ;
V_3 -> V_108 = V_144 + sizeof( struct V_59 ) ;
V_3 -> V_109 = V_145 ;
V_3 -> V_39 = V_146 ;
V_3 -> V_110 = 0 ;
V_3 -> V_147 = 4 ;
V_3 -> V_148 |= V_149 ;
V_3 -> V_148 |= V_150 ;
V_3 -> V_151 &= ~ V_152 ;
}
static int F_66 ( struct V_2 * V_3 )
{
struct V_25 * V_79 = F_20 ( V_3 ) ;
V_79 -> V_3 = V_3 ;
strcpy ( V_79 -> V_35 . V_50 , V_3 -> V_50 ) ;
memcpy ( V_3 -> V_135 , & V_79 -> V_35 . V_36 . V_37 , 4 ) ;
memcpy ( V_3 -> V_136 , & V_79 -> V_35 . V_36 . V_38 , 4 ) ;
V_3 -> V_7 = F_67 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_153 ;
return 0 ;
}
static int T_7 F_68 ( struct V_2 * V_3 )
{
struct V_25 * V_79 = F_20 ( V_3 ) ;
struct V_59 * V_36 = & V_79 -> V_35 . V_36 ;
struct V_32 * V_33 = F_8 ( F_26 ( V_3 ) , V_34 ) ;
V_79 -> V_3 = V_3 ;
strcpy ( V_79 -> V_35 . V_50 , V_3 -> V_50 ) ;
V_36 -> V_131 = 4 ;
V_36 -> V_92 = V_73 ;
V_36 -> V_132 = 5 ;
V_3 -> V_7 = F_67 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_153 ;
F_23 ( V_3 ) ;
F_14 ( V_33 -> V_154 [ 0 ] , V_79 ) ;
return 0 ;
}
static void F_69 ( struct V_32 * V_33 , struct V_155 * V_156 )
{
int V_43 ;
for ( V_43 = 1 ; V_43 < 4 ; V_43 ++ ) {
int V_42 ;
for ( V_42 = 0 ; V_42 < V_157 ; V_42 ++ ) {
struct V_25 * V_31 ;
V_31 = F_13 ( V_33 -> V_44 [ V_43 ] [ V_42 ] ) ;
while ( V_31 != NULL ) {
F_70 ( V_31 -> V_3 , V_156 ) ;
V_31 = F_13 ( V_31 -> V_47 ) ;
}
}
}
}
static int T_7 F_71 ( struct V_26 * V_26 )
{
int V_62 ;
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
V_33 -> V_44 [ 0 ] = V_33 -> V_154 ;
V_33 -> V_44 [ 1 ] = V_33 -> V_158 ;
V_33 -> V_44 [ 2 ] = V_33 -> V_159 ;
V_33 -> V_44 [ 3 ] = V_33 -> V_160 ;
V_33 -> V_116 = F_18 ( sizeof( struct V_25 ) ,
L_2 ,
V_52 ) ;
if ( ! V_33 -> V_116 ) {
V_62 = - V_153 ;
goto V_161;
}
F_19 ( V_33 -> V_116 , V_26 ) ;
V_62 = F_68 ( V_33 -> V_116 ) ;
if ( V_62 )
goto V_162;
V_33 -> V_116 -> V_53 = & V_54 ;
V_62 = F_72 ( V_33 -> V_116 ) ;
if ( V_62 )
goto V_162;
return 0 ;
V_162:
F_64 ( V_33 -> V_116 ) ;
V_161:
return V_62 ;
}
static void T_8 F_73 ( struct V_26 * V_26 )
{
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
F_74 ( V_163 ) ;
F_75 () ;
F_69 ( V_33 , & V_163 ) ;
F_76 ( & V_163 ) ;
F_77 () ;
}
static int F_78 ( struct V_164 * V_165 [] , struct V_164 * V_60 [] )
{
return 0 ;
}
static void F_79 ( struct V_164 * V_60 [] ,
struct V_41 * V_35 )
{
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_36 . V_92 = V_73 ;
if ( ! V_60 )
return;
if ( V_60 [ V_166 ] )
V_35 -> V_72 = F_80 ( V_60 [ V_166 ] ) ;
if ( V_60 [ V_167 ] )
V_35 -> V_95 = F_81 ( V_60 [ V_167 ] ) ;
if ( V_60 [ V_168 ] )
V_35 -> V_134 = F_81 ( V_60 [ V_168 ] ) ;
if ( V_60 [ V_169 ] )
V_35 -> V_36 . V_37 = F_81 ( V_60 [ V_169 ] ) ;
if ( V_60 [ V_170 ] )
V_35 -> V_36 . V_38 = F_81 ( V_60 [ V_170 ] ) ;
}
static int F_82 ( struct V_26 * V_171 , struct V_2 * V_3 ,
struct V_164 * V_165 [] , struct V_164 * V_60 [] )
{
struct V_25 * V_49 ;
struct V_26 * V_26 = F_26 ( V_3 ) ;
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
int V_109 ;
int V_62 ;
V_49 = F_20 ( V_3 ) ;
F_79 ( V_60 , & V_49 -> V_35 ) ;
if ( F_16 ( V_26 , & V_49 -> V_35 , 0 ) )
return - V_133 ;
V_109 = F_21 ( V_3 ) ;
if ( ! V_165 [ V_172 ] )
V_3 -> V_109 = V_109 ;
V_62 = F_22 ( V_3 ) ;
if ( V_62 )
goto V_70;
F_23 ( V_3 ) ;
F_15 ( V_33 , V_49 ) ;
V_70:
return V_62 ;
}
static int F_83 ( struct V_2 * V_3 , struct V_164 * V_165 [] ,
struct V_164 * V_60 [] )
{
struct V_25 * V_31 , * V_49 ;
struct V_26 * V_26 = F_26 ( V_3 ) ;
struct V_32 * V_33 = F_8 ( V_26 , V_34 ) ;
struct V_41 V_114 ;
int V_109 ;
if ( V_3 == V_33 -> V_116 )
return - V_130 ;
V_49 = F_20 ( V_3 ) ;
F_79 ( V_60 , & V_114 ) ;
V_31 = F_16 ( V_26 , & V_114 , 0 ) ;
if ( V_31 ) {
if ( V_31 -> V_3 != V_3 )
return - V_133 ;
} else {
V_31 = V_49 ;
F_12 ( V_33 , V_31 ) ;
V_31 -> V_35 . V_36 . V_37 = V_114 . V_36 . V_37 ;
V_31 -> V_35 . V_36 . V_38 = V_114 . V_36 . V_38 ;
V_31 -> V_35 . V_95 = V_114 . V_95 ;
V_31 -> V_35 . V_134 = V_114 . V_134 ;
if ( V_3 -> type != V_173 ) {
memcpy ( V_3 -> V_135 , & V_114 . V_36 . V_37 , 4 ) ;
memcpy ( V_3 -> V_136 , & V_114 . V_36 . V_38 , 4 ) ;
}
F_15 ( V_33 , V_31 ) ;
F_61 ( V_3 ) ;
}
if ( V_31 -> V_35 . V_72 != V_114 . V_72 ) {
V_31 -> V_35 . V_72 = V_114 . V_72 ;
V_109 = F_21 ( V_3 ) ;
if ( ! V_165 [ V_172 ] )
V_3 -> V_109 = V_109 ;
F_61 ( V_3 ) ;
}
return 0 ;
}
static T_9 F_84 ( const struct V_2 * V_3 )
{
return
F_85 ( 4 ) +
F_85 ( 4 ) +
F_85 ( 4 ) +
F_85 ( 4 ) +
F_85 ( 4 ) +
0 ;
}
static int F_86 ( struct V_56 * V_57 , const struct V_2 * V_3 )
{
struct V_25 * V_31 = F_20 ( V_3 ) ;
struct V_41 * V_114 = & V_31 -> V_35 ;
F_87 ( V_57 , V_166 , V_114 -> V_72 ) ;
F_88 ( V_57 , V_167 , V_114 -> V_95 ) ;
F_88 ( V_57 , V_168 , V_114 -> V_134 ) ;
F_88 ( V_57 , V_169 , V_114 -> V_36 . V_37 ) ;
F_88 ( V_57 , V_170 , V_114 -> V_36 . V_38 ) ;
return 0 ;
}
static int T_10 F_89 ( void )
{
int V_62 ;
F_90 ( L_3 ) ;
V_62 = F_91 ( & V_174 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_92 ( & V_175 ) ;
if ( V_62 < 0 ) {
F_93 ( & V_174 ) ;
F_90 ( V_176 L_4 ) ;
}
V_62 = F_94 ( & V_54 ) ;
if ( V_62 < 0 )
goto V_177;
return V_62 ;
V_177:
F_95 ( & V_175 ) ;
F_93 ( & V_174 ) ;
return V_62 ;
}
static void T_11 F_96 ( void )
{
F_97 ( & V_54 ) ;
if ( F_95 ( & V_175 ) )
F_90 ( L_5 ) ;
F_93 ( & V_174 ) ;
}
