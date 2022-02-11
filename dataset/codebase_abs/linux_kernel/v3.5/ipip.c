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
return V_4 ;
}
static struct V_21 * F_6 ( struct V_22 * V_22 ,
T_2 V_23 , T_2 V_24 )
{
unsigned int V_25 = F_7 ( V_23 ) ;
unsigned int V_26 = F_7 ( V_24 ) ;
struct V_21 * V_27 ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_9 (ipn->tunnels_r_l[h0 ^ h1])
if ( V_24 == V_27 -> V_31 . V_32 . V_33 &&
V_23 == V_27 -> V_31 . V_32 . V_34 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
F_9 (ipn->tunnels_r[h0])
if ( V_23 == V_27 -> V_31 . V_32 . V_34 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
F_9 (ipn->tunnels_l[h1])
if ( V_24 == V_27 -> V_31 . V_32 . V_33 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
V_27 = F_10 ( V_29 -> V_37 [ 0 ] ) ;
if ( V_27 && ( V_27 -> V_3 -> V_35 & V_36 ) )
return V_27 ;
return NULL ;
}
static struct V_21 T_3 * * F_11 ( struct V_28 * V_29 ,
struct V_38 * V_31 )
{
T_2 V_23 = V_31 -> V_32 . V_34 ;
T_2 V_24 = V_31 -> V_32 . V_33 ;
unsigned int V_39 = 0 ;
int V_40 = 0 ;
if ( V_23 ) {
V_40 |= 2 ;
V_39 ^= F_7 ( V_23 ) ;
}
if ( V_24 ) {
V_40 |= 1 ;
V_39 ^= F_7 ( V_24 ) ;
}
return & V_29 -> V_41 [ V_40 ] [ V_39 ] ;
}
static inline struct V_21 T_3 * * F_12 ( struct V_28 * V_29 ,
struct V_21 * V_27 )
{
return F_11 ( V_29 , & V_27 -> V_31 ) ;
}
static void F_13 ( struct V_28 * V_29 , struct V_21 * V_27 )
{
struct V_21 T_3 * * V_42 ;
struct V_21 * V_43 ;
for ( V_42 = F_12 ( V_29 , V_27 ) ;
( V_43 = F_14 ( * V_42 ) ) != NULL ;
V_42 = & V_43 -> V_44 ) {
if ( V_27 == V_43 ) {
F_15 ( * V_42 , V_27 -> V_44 ) ;
break;
}
}
}
static void F_16 ( struct V_28 * V_29 , struct V_21 * V_27 )
{
struct V_21 T_3 * * V_42 = F_12 ( V_29 , V_27 ) ;
F_15 ( V_27 -> V_44 , F_14 ( * V_42 ) ) ;
F_15 ( * V_42 , V_27 ) ;
}
static struct V_21 * F_17 ( struct V_22 * V_22 ,
struct V_38 * V_31 , int V_45 )
{
T_2 V_23 = V_31 -> V_32 . V_34 ;
T_2 V_24 = V_31 -> V_32 . V_33 ;
struct V_21 * V_27 , * V_46 ;
struct V_21 T_3 * * V_42 ;
struct V_2 * V_3 ;
char V_47 [ V_48 ] ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
for ( V_42 = F_11 ( V_29 , V_31 ) ;
( V_27 = F_14 ( * V_42 ) ) != NULL ;
V_42 = & V_27 -> V_44 ) {
if ( V_24 == V_27 -> V_31 . V_32 . V_33 && V_23 == V_27 -> V_31 . V_32 . V_34 )
return V_27 ;
}
if ( ! V_45 )
return NULL ;
if ( V_31 -> V_47 [ 0 ] )
F_18 ( V_47 , V_31 -> V_47 , V_48 ) ;
else
strcpy ( V_47 , L_1 ) ;
V_3 = F_19 ( sizeof( * V_27 ) , V_47 , V_49 ) ;
if ( V_3 == NULL )
return NULL ;
F_20 ( V_3 , V_22 ) ;
V_46 = F_21 ( V_3 ) ;
V_46 -> V_31 = * V_31 ;
if ( F_22 ( V_3 ) < 0 )
goto V_50;
if ( F_23 ( V_3 ) < 0 )
goto V_50;
strcpy ( V_46 -> V_31 . V_47 , V_3 -> V_47 ) ;
F_24 ( V_3 ) ;
F_16 ( V_29 , V_46 ) ;
return V_46 ;
V_50:
F_25 ( V_3 ) ;
return NULL ;
}
static void F_26 ( struct V_2 * V_3 )
{
struct V_22 * V_22 = F_27 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
if ( V_3 == V_29 -> V_51 )
F_28 ( V_29 -> V_37 [ 0 ] , NULL ) ;
else
F_13 ( V_29 , F_21 ( V_3 ) ) ;
F_29 ( V_3 ) ;
}
static int F_30 ( struct V_52 * V_53 , T_4 V_54 )
{
const struct V_55 * V_32 = ( const struct V_55 * ) V_53 -> V_56 ;
const int type = F_31 ( V_53 ) -> type ;
const int V_57 = F_31 ( V_53 ) -> V_57 ;
struct V_21 * V_27 ;
int V_58 ;
switch ( type ) {
default:
case V_59 :
return 0 ;
case V_60 :
switch ( V_57 ) {
case V_61 :
case V_62 :
return 0 ;
case V_63 :
return 0 ;
default:
break;
}
break;
case V_64 :
if ( V_57 != V_65 )
return 0 ;
break;
}
V_58 = - V_66 ;
F_32 () ;
V_27 = F_6 ( F_27 ( V_53 -> V_3 ) , V_32 -> V_34 , V_32 -> V_33 ) ;
if ( V_27 == NULL || V_27 -> V_31 . V_32 . V_34 == 0 )
goto V_67;
V_58 = 0 ;
if ( V_27 -> V_31 . V_32 . V_68 == 0 && type == V_64 )
goto V_67;
if ( F_33 ( V_69 , V_27 -> V_70 + V_71 ) )
V_27 -> V_72 ++ ;
else
V_27 -> V_72 = 1 ;
V_27 -> V_70 = V_69 ;
V_67:
F_34 () ;
return V_58 ;
}
static inline void F_35 ( const struct V_55 * V_73 ,
struct V_52 * V_53 )
{
struct V_55 * V_74 = F_36 ( V_53 ) ;
if ( F_37 ( V_73 -> V_75 ) )
F_38 ( V_74 ) ;
}
static int F_39 ( struct V_52 * V_53 )
{
struct V_21 * V_76 ;
const struct V_55 * V_32 = F_36 ( V_53 ) ;
F_32 () ;
V_76 = F_6 ( F_27 ( V_53 -> V_3 ) , V_32 -> V_33 , V_32 -> V_34 ) ;
if ( V_76 != NULL ) {
struct V_6 * V_7 ;
if ( ! F_40 ( NULL , V_77 , V_53 ) ) {
F_34 () ;
F_41 ( V_53 ) ;
return 0 ;
}
F_42 ( V_53 ) ;
V_53 -> V_78 = V_53 -> V_79 ;
F_43 ( V_53 ) ;
V_53 -> V_80 = F_44 ( V_81 ) ;
V_53 -> V_82 = V_83 ;
V_7 = F_45 ( V_76 -> V_3 -> V_7 ) ;
F_46 ( & V_7 -> V_13 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_53 -> V_84 ;
F_47 ( & V_7 -> V_13 ) ;
F_48 ( V_53 , V_76 -> V_3 ) ;
F_35 ( V_32 , V_53 ) ;
F_49 ( V_53 ) ;
F_34 () ;
return 0 ;
}
F_34 () ;
return - 1 ;
}
static T_5 F_50 ( struct V_52 * V_53 , struct V_2 * V_3 )
{
struct V_21 * V_76 = F_21 ( V_3 ) ;
struct V_6 * V_7 ;
const struct V_55 * V_85 = & V_76 -> V_31 . V_32 ;
T_6 V_75 = V_76 -> V_31 . V_32 . V_75 ;
T_7 V_86 = V_85 -> V_87 ;
struct V_88 * V_89 ;
struct V_2 * V_90 ;
const struct V_55 * V_91 = F_36 ( V_53 ) ;
struct V_55 * V_32 ;
unsigned int V_92 ;
T_2 V_93 = V_85 -> V_34 ;
struct V_94 V_95 ;
int V_96 ;
if ( V_53 -> V_80 != F_44 ( V_81 ) )
goto V_97;
if ( V_75 & 1 )
V_75 = V_91 -> V_75 ;
if ( ! V_93 ) {
if ( ( V_89 = F_51 ( V_53 ) ) == NULL ) {
V_3 -> V_15 . V_14 ++ ;
goto V_97;
}
V_93 = V_89 -> V_98 ;
}
V_89 = F_52 ( F_27 ( V_3 ) , & V_95 , NULL ,
V_93 , V_85 -> V_33 ,
0 , 0 ,
V_99 , F_53 ( V_75 ) ,
V_76 -> V_31 . V_100 ) ;
if ( F_54 ( V_89 ) ) {
V_3 -> V_15 . V_16 ++ ;
goto V_101;
}
V_90 = V_89 -> V_93 . V_3 ;
if ( V_90 == V_3 ) {
F_55 ( V_89 ) ;
V_3 -> V_15 . V_20 ++ ;
goto V_97;
}
V_86 |= V_91 -> V_87 & F_44 ( V_102 ) ;
if ( V_86 ) {
V_96 = F_56 ( & V_89 -> V_93 ) - sizeof( struct V_55 ) ;
if ( V_96 < 68 ) {
V_3 -> V_15 . V_20 ++ ;
F_55 ( V_89 ) ;
goto V_97;
}
if ( F_57 ( V_53 ) )
F_57 ( V_53 ) -> V_103 -> V_104 ( F_57 ( V_53 ) , V_96 ) ;
if ( ( V_91 -> V_87 & F_44 ( V_102 ) ) &&
V_96 < F_58 ( V_91 -> V_105 ) ) {
F_59 ( V_53 , V_60 , V_63 ,
F_60 ( V_96 ) ) ;
F_55 ( V_89 ) ;
goto V_97;
}
}
if ( V_76 -> V_72 > 0 ) {
if ( F_33 ( V_69 ,
V_76 -> V_70 + V_71 ) ) {
V_76 -> V_72 -- ;
F_61 ( V_53 ) ;
} else
V_76 -> V_72 = 0 ;
}
V_92 = ( F_62 ( V_90 ) + sizeof( struct V_55 ) ) ;
if ( F_63 ( V_53 ) < V_92 || F_64 ( V_53 ) ||
( F_65 ( V_53 ) && ! F_66 ( V_53 , 0 ) ) ) {
struct V_52 * V_106 = F_67 ( V_53 , V_92 ) ;
if ( ! V_106 ) {
F_55 ( V_89 ) ;
V_3 -> V_15 . V_17 ++ ;
F_68 ( V_53 ) ;
return V_107 ;
}
if ( V_53 -> V_108 )
F_69 ( V_106 , V_53 -> V_108 ) ;
F_68 ( V_53 ) ;
V_53 = V_106 ;
V_91 = F_36 ( V_53 ) ;
}
V_53 -> V_109 = V_53 -> V_79 ;
F_70 ( V_53 , sizeof( struct V_55 ) ) ;
F_43 ( V_53 ) ;
memset ( & ( F_71 ( V_53 ) -> V_110 ) , 0 , sizeof( F_71 ( V_53 ) -> V_110 ) ) ;
F_71 ( V_53 ) -> V_35 &= ~ ( V_111 | V_112 |
V_113 ) ;
F_72 ( V_53 ) ;
F_73 ( V_53 , & V_89 -> V_93 ) ;
V_32 = F_36 ( V_53 ) ;
V_32 -> V_114 = 4 ;
V_32 -> V_115 = sizeof( struct V_55 ) >> 2 ;
V_32 -> V_87 = V_86 ;
V_32 -> V_80 = V_99 ;
V_32 -> V_75 = F_74 ( V_75 , V_91 -> V_75 ) ;
V_32 -> V_34 = V_95 . V_34 ;
V_32 -> V_33 = V_95 . V_33 ;
if ( ( V_32 -> V_68 = V_85 -> V_68 ) == 0 )
V_32 -> V_68 = V_91 -> V_68 ;
F_75 ( V_53 ) ;
V_7 = F_45 ( V_3 -> V_7 ) ;
F_76 ( V_7 , & V_3 -> V_15 ) ;
return V_107 ;
V_101:
F_61 ( V_53 ) ;
V_97:
V_3 -> V_15 . V_19 ++ ;
F_68 ( V_53 ) ;
return V_107 ;
}
static void F_77 ( struct V_2 * V_3 )
{
struct V_2 * V_90 = NULL ;
struct V_21 * V_76 ;
const struct V_55 * V_32 ;
V_76 = F_21 ( V_3 ) ;
V_32 = & V_76 -> V_31 . V_32 ;
if ( V_32 -> V_34 ) {
struct V_88 * V_89 ;
struct V_94 V_95 ;
V_89 = F_52 ( F_27 ( V_3 ) , & V_95 , NULL ,
V_32 -> V_34 , V_32 -> V_33 ,
0 , 0 ,
V_99 ,
F_53 ( V_32 -> V_75 ) ,
V_76 -> V_31 . V_100 ) ;
if ( ! F_54 ( V_89 ) ) {
V_90 = V_89 -> V_93 . V_3 ;
F_55 ( V_89 ) ;
}
V_3 -> V_35 |= V_116 ;
}
if ( ! V_90 && V_76 -> V_31 . V_100 )
V_90 = F_78 ( F_27 ( V_3 ) , V_76 -> V_31 . V_100 ) ;
if ( V_90 ) {
V_3 -> V_117 = V_90 -> V_117 + sizeof( struct V_55 ) ;
V_3 -> V_96 = V_90 -> V_96 - sizeof( struct V_55 ) ;
}
V_3 -> V_118 = V_76 -> V_31 . V_100 ;
}
static int
F_79 ( struct V_2 * V_3 , struct V_119 * V_120 , int V_121 )
{
int V_58 = 0 ;
struct V_38 V_122 ;
struct V_21 * V_27 ;
struct V_22 * V_22 = F_27 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
switch ( V_121 ) {
case V_123 :
V_27 = NULL ;
if ( V_3 == V_29 -> V_51 ) {
if ( F_80 ( & V_122 , V_120 -> V_124 . V_125 , sizeof( V_122 ) ) ) {
V_58 = - V_126 ;
break;
}
V_27 = F_17 ( V_22 , & V_122 , 0 ) ;
}
if ( V_27 == NULL )
V_27 = F_21 ( V_3 ) ;
memcpy ( & V_122 , & V_27 -> V_31 , sizeof( V_122 ) ) ;
if ( F_81 ( V_120 -> V_124 . V_125 , & V_122 , sizeof( V_122 ) ) )
V_58 = - V_126 ;
break;
case V_127 :
case V_128 :
V_58 = - V_129 ;
if ( ! F_82 ( V_130 ) )
goto V_131;
V_58 = - V_126 ;
if ( F_80 ( & V_122 , V_120 -> V_124 . V_125 , sizeof( V_122 ) ) )
goto V_131;
V_58 = - V_132 ;
if ( V_122 . V_32 . V_114 != 4 || V_122 . V_32 . V_80 != V_99 ||
V_122 . V_32 . V_115 != 5 || ( V_122 . V_32 . V_87 & F_44 ( ~ V_102 ) ) )
goto V_131;
if ( V_122 . V_32 . V_68 )
V_122 . V_32 . V_87 |= F_44 ( V_102 ) ;
V_27 = F_17 ( V_22 , & V_122 , V_121 == V_127 ) ;
if ( V_3 != V_29 -> V_51 && V_121 == V_128 ) {
if ( V_27 != NULL ) {
if ( V_27 -> V_3 != V_3 ) {
V_58 = - V_133 ;
break;
}
} else {
if ( ( ( V_3 -> V_35 & V_116 ) && ! V_122 . V_32 . V_34 ) ||
( ! ( V_3 -> V_35 & V_116 ) && V_122 . V_32 . V_34 ) ) {
V_58 = - V_132 ;
break;
}
V_27 = F_21 ( V_3 ) ;
F_13 ( V_29 , V_27 ) ;
F_83 () ;
V_27 -> V_31 . V_32 . V_33 = V_122 . V_32 . V_33 ;
V_27 -> V_31 . V_32 . V_34 = V_122 . V_32 . V_34 ;
memcpy ( V_3 -> V_134 , & V_122 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_135 , & V_122 . V_32 . V_34 , 4 ) ;
F_16 ( V_29 , V_27 ) ;
F_84 ( V_3 ) ;
}
}
if ( V_27 ) {
V_58 = 0 ;
if ( V_121 == V_128 ) {
V_27 -> V_31 . V_32 . V_68 = V_122 . V_32 . V_68 ;
V_27 -> V_31 . V_32 . V_75 = V_122 . V_32 . V_75 ;
V_27 -> V_31 . V_32 . V_87 = V_122 . V_32 . V_87 ;
if ( V_27 -> V_31 . V_100 != V_122 . V_100 ) {
V_27 -> V_31 . V_100 = V_122 . V_100 ;
F_77 ( V_3 ) ;
F_84 ( V_3 ) ;
}
}
if ( F_81 ( V_120 -> V_124 . V_125 , & V_27 -> V_31 , sizeof( V_122 ) ) )
V_58 = - V_126 ;
} else
V_58 = ( V_121 == V_127 ? - V_136 : - V_66 ) ;
break;
case V_137 :
V_58 = - V_129 ;
if ( ! F_82 ( V_130 ) )
goto V_131;
if ( V_3 == V_29 -> V_51 ) {
V_58 = - V_126 ;
if ( F_80 ( & V_122 , V_120 -> V_124 . V_125 , sizeof( V_122 ) ) )
goto V_131;
V_58 = - V_66 ;
if ( ( V_27 = F_17 ( V_22 , & V_122 , 0 ) ) == NULL )
goto V_131;
V_58 = - V_129 ;
if ( V_27 -> V_3 == V_29 -> V_51 )
goto V_131;
V_3 = V_27 -> V_3 ;
}
F_85 ( V_3 ) ;
V_58 = 0 ;
break;
default:
V_58 = - V_132 ;
}
V_131:
return V_58 ;
}
static int F_86 ( struct V_2 * V_3 , int V_138 )
{
if ( V_138 < 68 || V_138 > 0xFFF8 - sizeof( struct V_55 ) )
return - V_132 ;
V_3 -> V_96 = V_138 ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
F_87 ( V_3 -> V_7 ) ;
F_88 ( V_3 ) ;
}
static void V_49 ( struct V_2 * V_3 )
{
V_3 -> V_139 = & V_140 ;
V_3 -> V_141 = F_25 ;
V_3 -> type = V_142 ;
V_3 -> V_117 = V_143 + sizeof( struct V_55 ) ;
V_3 -> V_96 = V_144 - sizeof( struct V_55 ) ;
V_3 -> V_35 = V_145 ;
V_3 -> V_118 = 0 ;
V_3 -> V_146 = 4 ;
V_3 -> V_147 |= V_148 ;
V_3 -> V_147 |= V_149 ;
V_3 -> V_150 &= ~ V_151 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_21 * V_76 = F_21 ( V_3 ) ;
V_76 -> V_3 = V_3 ;
memcpy ( V_3 -> V_134 , & V_76 -> V_31 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_135 , & V_76 -> V_31 . V_32 . V_34 , 4 ) ;
F_77 ( V_3 ) ;
V_3 -> V_7 = F_89 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_152 ;
return 0 ;
}
static int T_8 F_90 ( struct V_2 * V_3 )
{
struct V_21 * V_76 = F_21 ( V_3 ) ;
struct V_55 * V_32 = & V_76 -> V_31 . V_32 ;
struct V_28 * V_29 = F_8 ( F_27 ( V_3 ) , V_30 ) ;
V_76 -> V_3 = V_3 ;
strcpy ( V_76 -> V_31 . V_47 , V_3 -> V_47 ) ;
V_32 -> V_114 = 4 ;
V_32 -> V_80 = V_99 ;
V_32 -> V_115 = 5 ;
V_3 -> V_7 = F_89 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_152 ;
F_24 ( V_3 ) ;
F_15 ( V_29 -> V_37 [ 0 ] , V_76 ) ;
return 0 ;
}
static void F_91 ( struct V_28 * V_29 , struct V_153 * V_154 )
{
int V_40 ;
for ( V_40 = 1 ; V_40 < 4 ; V_40 ++ ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_155 ; V_39 ++ ) {
struct V_21 * V_27 ;
V_27 = F_14 ( V_29 -> V_41 [ V_40 ] [ V_39 ] ) ;
while ( V_27 != NULL ) {
F_92 ( V_27 -> V_3 , V_154 ) ;
V_27 = F_14 ( V_27 -> V_44 ) ;
}
}
}
}
static int T_8 F_93 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
struct V_21 * V_27 ;
int V_58 ;
V_29 -> V_41 [ 0 ] = V_29 -> V_37 ;
V_29 -> V_41 [ 1 ] = V_29 -> V_156 ;
V_29 -> V_41 [ 2 ] = V_29 -> V_157 ;
V_29 -> V_41 [ 3 ] = V_29 -> V_158 ;
V_29 -> V_51 = F_19 ( sizeof( struct V_21 ) ,
L_2 ,
V_49 ) ;
if ( ! V_29 -> V_51 ) {
V_58 = - V_152 ;
goto V_159;
}
F_20 ( V_29 -> V_51 , V_22 ) ;
V_58 = F_90 ( V_29 -> V_51 ) ;
if ( V_58 )
goto V_160;
if ( ( V_58 = F_94 ( V_29 -> V_51 ) ) )
goto V_160;
V_27 = F_21 ( V_29 -> V_51 ) ;
strcpy ( V_27 -> V_31 . V_47 , V_29 -> V_51 -> V_47 ) ;
return 0 ;
V_160:
F_25 ( V_29 -> V_51 ) ;
V_159:
return V_58 ;
}
static void T_9 F_95 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_96 ( V_161 ) ;
F_97 () ;
F_91 ( V_29 , & V_161 ) ;
F_92 ( V_29 -> V_51 , & V_161 ) ;
F_98 ( & V_161 ) ;
F_99 () ;
}
static int T_10 F_100 ( void )
{
int V_58 ;
F_101 ( V_162 ) ;
V_58 = F_102 ( & V_163 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_103 ( & V_164 , V_165 ) ;
if ( V_58 < 0 ) {
F_104 ( & V_163 ) ;
F_105 ( L_3 , V_166 ) ;
}
return V_58 ;
}
static void T_11 F_106 ( void )
{
if ( F_107 ( & V_164 , V_165 ) )
F_105 ( L_4 , V_166 ) ;
F_104 ( & V_163 ) ;
}
