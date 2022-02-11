static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 V_5 = { 0 } ;
int V_6 ;
F_2 (i) {
const struct V_4 * V_7 = F_3 ( V_3 -> V_7 , V_6 ) ;
V_5 . V_8 += V_7 -> V_8 ;
V_5 . V_9 += V_7 -> V_9 ;
V_5 . V_10 += V_7 -> V_10 ;
V_5 . V_11 += V_7 -> V_11 ;
}
V_3 -> V_12 . V_8 = V_5 . V_8 ;
V_3 -> V_12 . V_9 = V_5 . V_9 ;
V_3 -> V_12 . V_10 = V_5 . V_10 ;
V_3 -> V_12 . V_11 = V_5 . V_11 ;
return & V_3 -> V_12 ;
}
static struct V_13 * F_4 ( struct V_14 * V_14 ,
T_1 V_15 , T_1 V_16 )
{
unsigned int V_17 = F_5 ( V_15 ) ;
unsigned int V_18 = F_5 ( V_16 ) ;
struct V_13 * V_19 ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
F_7 (ipn->tunnels_r_l[h0 ^ h1])
if ( V_16 == V_19 -> V_23 . V_24 . V_25 &&
V_15 == V_19 -> V_23 . V_24 . V_26 && ( V_19 -> V_3 -> V_27 & V_28 ) )
return V_19 ;
F_7 (ipn->tunnels_r[h0])
if ( V_15 == V_19 -> V_23 . V_24 . V_26 && ( V_19 -> V_3 -> V_27 & V_28 ) )
return V_19 ;
F_7 (ipn->tunnels_l[h1])
if ( V_16 == V_19 -> V_23 . V_24 . V_25 && ( V_19 -> V_3 -> V_27 & V_28 ) )
return V_19 ;
V_19 = F_8 ( V_21 -> V_29 [ 0 ] ) ;
if ( V_19 && ( V_19 -> V_3 -> V_27 & V_28 ) )
return V_19 ;
return NULL ;
}
static struct V_13 T_2 * * F_9 ( struct V_20 * V_21 ,
struct V_30 * V_23 )
{
T_1 V_15 = V_23 -> V_24 . V_26 ;
T_1 V_16 = V_23 -> V_24 . V_25 ;
unsigned int V_31 = 0 ;
int V_32 = 0 ;
if ( V_15 ) {
V_32 |= 2 ;
V_31 ^= F_5 ( V_15 ) ;
}
if ( V_16 ) {
V_32 |= 1 ;
V_31 ^= F_5 ( V_16 ) ;
}
return & V_21 -> V_33 [ V_32 ] [ V_31 ] ;
}
static inline struct V_13 T_2 * * F_10 ( struct V_20 * V_21 ,
struct V_13 * V_19 )
{
return F_9 ( V_21 , & V_19 -> V_23 ) ;
}
static void F_11 ( struct V_20 * V_21 , struct V_13 * V_19 )
{
struct V_13 T_2 * * V_34 ;
struct V_13 * V_35 ;
for ( V_34 = F_10 ( V_21 , V_19 ) ;
( V_35 = F_12 ( * V_34 ) ) != NULL ;
V_34 = & V_35 -> V_36 ) {
if ( V_19 == V_35 ) {
F_13 ( * V_34 , V_19 -> V_36 ) ;
break;
}
}
}
static void F_14 ( struct V_20 * V_21 , struct V_13 * V_19 )
{
struct V_13 T_2 * * V_34 = F_10 ( V_21 , V_19 ) ;
F_13 ( V_19 -> V_36 , F_12 ( * V_34 ) ) ;
F_13 ( * V_34 , V_19 ) ;
}
static struct V_13 * F_15 ( struct V_14 * V_14 ,
struct V_30 * V_23 , int V_37 )
{
T_1 V_15 = V_23 -> V_24 . V_26 ;
T_1 V_16 = V_23 -> V_24 . V_25 ;
struct V_13 * V_19 , * V_38 ;
struct V_13 T_2 * * V_34 ;
struct V_2 * V_3 ;
char V_39 [ V_40 ] ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
for ( V_34 = F_9 ( V_21 , V_23 ) ;
( V_19 = F_12 ( * V_34 ) ) != NULL ;
V_34 = & V_19 -> V_36 ) {
if ( V_16 == V_19 -> V_23 . V_24 . V_25 && V_15 == V_19 -> V_23 . V_24 . V_26 )
return V_19 ;
}
if ( ! V_37 )
return NULL ;
if ( V_23 -> V_39 [ 0 ] )
F_16 ( V_39 , V_23 -> V_39 , V_40 ) ;
else
strcpy ( V_39 , L_1 ) ;
V_3 = F_17 ( sizeof( * V_19 ) , V_39 , V_41 ) ;
if ( V_3 == NULL )
return NULL ;
F_18 ( V_3 , V_14 ) ;
V_38 = F_19 ( V_3 ) ;
V_38 -> V_23 = * V_23 ;
if ( F_20 ( V_3 ) < 0 )
goto V_42;
if ( F_21 ( V_3 ) < 0 )
goto V_42;
strcpy ( V_38 -> V_23 . V_39 , V_3 -> V_39 ) ;
F_22 ( V_3 ) ;
F_14 ( V_21 , V_38 ) ;
return V_38 ;
V_42:
F_23 ( V_3 ) ;
return NULL ;
}
static void F_24 ( struct V_2 * V_3 )
{
struct V_14 * V_14 = F_25 ( V_3 ) ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
if ( V_3 == V_21 -> V_43 )
F_26 ( V_21 -> V_29 [ 0 ] , NULL ) ;
else
F_11 ( V_21 , F_19 ( V_3 ) ) ;
F_27 ( V_3 ) ;
}
static int F_28 ( struct V_44 * V_45 , T_3 V_46 )
{
const struct V_47 * V_24 = ( const struct V_47 * ) V_45 -> V_48 ;
const int type = F_29 ( V_45 ) -> type ;
const int V_49 = F_29 ( V_45 ) -> V_49 ;
struct V_13 * V_19 ;
int V_50 ;
switch ( type ) {
default:
case V_51 :
return 0 ;
case V_52 :
switch ( V_49 ) {
case V_53 :
case V_54 :
return 0 ;
case V_55 :
return 0 ;
default:
break;
}
break;
case V_56 :
if ( V_49 != V_57 )
return 0 ;
break;
}
V_50 = - V_58 ;
F_30 () ;
V_19 = F_4 ( F_25 ( V_45 -> V_3 ) , V_24 -> V_26 , V_24 -> V_25 ) ;
if ( V_19 == NULL || V_19 -> V_23 . V_24 . V_26 == 0 )
goto V_59;
V_50 = 0 ;
if ( V_19 -> V_23 . V_24 . V_60 == 0 && type == V_56 )
goto V_59;
if ( F_31 ( V_61 , V_19 -> V_62 + V_63 ) )
V_19 -> V_64 ++ ;
else
V_19 -> V_64 = 1 ;
V_19 -> V_62 = V_61 ;
V_59:
F_32 () ;
return V_50 ;
}
static inline void F_33 ( const struct V_47 * V_65 ,
struct V_44 * V_45 )
{
struct V_47 * V_66 = F_34 ( V_45 ) ;
if ( F_35 ( V_65 -> V_67 ) )
F_36 ( V_66 ) ;
}
static int F_37 ( struct V_44 * V_45 )
{
struct V_13 * V_68 ;
const struct V_47 * V_24 = F_34 ( V_45 ) ;
F_30 () ;
V_68 = F_4 ( F_25 ( V_45 -> V_3 ) , V_24 -> V_25 , V_24 -> V_26 ) ;
if ( V_68 != NULL ) {
struct V_4 * V_7 ;
if ( ! F_38 ( NULL , V_69 , V_45 ) ) {
F_32 () ;
F_39 ( V_45 ) ;
return 0 ;
}
F_40 ( V_45 ) ;
V_45 -> V_70 = V_45 -> V_71 ;
F_41 ( V_45 ) ;
V_45 -> V_72 = F_42 ( V_73 ) ;
V_45 -> V_74 = V_75 ;
V_7 = F_43 ( V_68 -> V_3 -> V_7 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_45 -> V_76 ;
F_44 ( V_45 , V_68 -> V_3 ) ;
F_33 ( V_24 , V_45 ) ;
F_45 ( V_45 ) ;
F_32 () ;
return 0 ;
}
F_32 () ;
return - 1 ;
}
static T_4 F_46 ( struct V_44 * V_45 , struct V_2 * V_3 )
{
struct V_13 * V_68 = F_19 ( V_3 ) ;
struct V_4 * V_7 ;
const struct V_47 * V_77 = & V_68 -> V_23 . V_24 ;
T_5 V_67 = V_68 -> V_23 . V_24 . V_67 ;
T_6 V_78 = V_77 -> V_79 ;
struct V_80 * V_81 ;
struct V_2 * V_82 ;
const struct V_47 * V_83 = F_34 ( V_45 ) ;
struct V_47 * V_24 ;
unsigned int V_84 ;
T_1 V_85 = V_77 -> V_26 ;
struct V_86 V_87 ;
int V_88 ;
if ( V_45 -> V_72 != F_42 ( V_73 ) )
goto V_89;
if ( V_67 & 1 )
V_67 = V_83 -> V_67 ;
if ( ! V_85 ) {
if ( ( V_81 = F_47 ( V_45 ) ) == NULL ) {
V_3 -> V_12 . V_90 ++ ;
goto V_89;
}
V_85 = V_81 -> V_91 ;
}
V_81 = F_48 ( F_25 ( V_3 ) , & V_87 , NULL ,
V_85 , V_77 -> V_25 ,
0 , 0 ,
V_92 , F_49 ( V_67 ) ,
V_68 -> V_23 . V_93 ) ;
if ( F_50 ( V_81 ) ) {
V_3 -> V_12 . V_94 ++ ;
goto V_95;
}
V_82 = V_81 -> V_85 . V_3 ;
if ( V_82 == V_3 ) {
F_51 ( V_81 ) ;
V_3 -> V_12 . V_96 ++ ;
goto V_89;
}
V_78 |= V_83 -> V_79 & F_42 ( V_97 ) ;
if ( V_78 ) {
V_88 = F_52 ( & V_81 -> V_85 ) - sizeof( struct V_47 ) ;
if ( V_88 < 68 ) {
V_3 -> V_12 . V_96 ++ ;
F_51 ( V_81 ) ;
goto V_89;
}
if ( F_53 ( V_45 ) )
F_53 ( V_45 ) -> V_98 -> V_99 ( F_53 ( V_45 ) , V_88 ) ;
if ( ( V_83 -> V_79 & F_42 ( V_97 ) ) &&
V_88 < F_54 ( V_83 -> V_100 ) ) {
F_55 ( V_45 , V_52 , V_55 ,
F_56 ( V_88 ) ) ;
F_51 ( V_81 ) ;
goto V_89;
}
}
if ( V_68 -> V_64 > 0 ) {
if ( F_31 ( V_61 ,
V_68 -> V_62 + V_63 ) ) {
V_68 -> V_64 -- ;
F_57 ( V_45 ) ;
} else
V_68 -> V_64 = 0 ;
}
V_84 = ( F_58 ( V_82 ) + sizeof( struct V_47 ) ) ;
if ( F_59 ( V_45 ) < V_84 || F_60 ( V_45 ) ||
( F_61 ( V_45 ) && ! F_62 ( V_45 , 0 ) ) ) {
struct V_44 * V_101 = F_63 ( V_45 , V_84 ) ;
if ( ! V_101 ) {
F_51 ( V_81 ) ;
V_3 -> V_12 . V_102 ++ ;
F_64 ( V_45 ) ;
return V_103 ;
}
if ( V_45 -> V_104 )
F_65 ( V_101 , V_45 -> V_104 ) ;
F_64 ( V_45 ) ;
V_45 = V_101 ;
V_83 = F_34 ( V_45 ) ;
}
V_45 -> V_105 = V_45 -> V_71 ;
F_66 ( V_45 , sizeof( struct V_47 ) ) ;
F_41 ( V_45 ) ;
memset ( & ( F_67 ( V_45 ) -> V_106 ) , 0 , sizeof( F_67 ( V_45 ) -> V_106 ) ) ;
F_67 ( V_45 ) -> V_27 &= ~ ( V_107 | V_108 |
V_109 ) ;
F_68 ( V_45 ) ;
F_69 ( V_45 , & V_81 -> V_85 ) ;
V_24 = F_34 ( V_45 ) ;
V_24 -> V_110 = 4 ;
V_24 -> V_111 = sizeof( struct V_47 ) >> 2 ;
V_24 -> V_79 = V_78 ;
V_24 -> V_72 = V_92 ;
V_24 -> V_67 = F_70 ( V_67 , V_83 -> V_67 ) ;
V_24 -> V_26 = V_87 . V_26 ;
V_24 -> V_25 = V_87 . V_25 ;
if ( ( V_24 -> V_60 = V_77 -> V_60 ) == 0 )
V_24 -> V_60 = V_83 -> V_60 ;
F_71 ( V_45 ) ;
V_7 = F_43 ( V_3 -> V_7 ) ;
F_72 ( V_7 , & V_3 -> V_12 ) ;
return V_103 ;
V_95:
F_57 ( V_45 ) ;
V_89:
V_3 -> V_12 . V_112 ++ ;
F_64 ( V_45 ) ;
return V_103 ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_2 * V_82 = NULL ;
struct V_13 * V_68 ;
const struct V_47 * V_24 ;
V_68 = F_19 ( V_3 ) ;
V_24 = & V_68 -> V_23 . V_24 ;
if ( V_24 -> V_26 ) {
struct V_80 * V_81 ;
struct V_86 V_87 ;
V_81 = F_48 ( F_25 ( V_3 ) , & V_87 , NULL ,
V_24 -> V_26 , V_24 -> V_25 ,
0 , 0 ,
V_92 ,
F_49 ( V_24 -> V_67 ) ,
V_68 -> V_23 . V_93 ) ;
if ( ! F_50 ( V_81 ) ) {
V_82 = V_81 -> V_85 . V_3 ;
F_51 ( V_81 ) ;
}
V_3 -> V_27 |= V_113 ;
}
if ( ! V_82 && V_68 -> V_23 . V_93 )
V_82 = F_74 ( F_25 ( V_3 ) , V_68 -> V_23 . V_93 ) ;
if ( V_82 ) {
V_3 -> V_114 = V_82 -> V_114 + sizeof( struct V_47 ) ;
V_3 -> V_88 = V_82 -> V_88 - sizeof( struct V_47 ) ;
}
V_3 -> V_115 = V_68 -> V_23 . V_93 ;
}
static int
F_75 ( struct V_2 * V_3 , struct V_116 * V_117 , int V_118 )
{
int V_50 = 0 ;
struct V_30 V_119 ;
struct V_13 * V_19 ;
struct V_14 * V_14 = F_25 ( V_3 ) ;
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
switch ( V_118 ) {
case V_120 :
V_19 = NULL ;
if ( V_3 == V_21 -> V_43 ) {
if ( F_76 ( & V_119 , V_117 -> V_121 . V_122 , sizeof( V_119 ) ) ) {
V_50 = - V_123 ;
break;
}
V_19 = F_15 ( V_14 , & V_119 , 0 ) ;
}
if ( V_19 == NULL )
V_19 = F_19 ( V_3 ) ;
memcpy ( & V_119 , & V_19 -> V_23 , sizeof( V_119 ) ) ;
if ( F_77 ( V_117 -> V_121 . V_122 , & V_119 , sizeof( V_119 ) ) )
V_50 = - V_123 ;
break;
case V_124 :
case V_125 :
V_50 = - V_126 ;
if ( ! F_78 ( V_127 ) )
goto V_128;
V_50 = - V_123 ;
if ( F_76 ( & V_119 , V_117 -> V_121 . V_122 , sizeof( V_119 ) ) )
goto V_128;
V_50 = - V_129 ;
if ( V_119 . V_24 . V_110 != 4 || V_119 . V_24 . V_72 != V_92 ||
V_119 . V_24 . V_111 != 5 || ( V_119 . V_24 . V_79 & F_42 ( ~ V_97 ) ) )
goto V_128;
if ( V_119 . V_24 . V_60 )
V_119 . V_24 . V_79 |= F_42 ( V_97 ) ;
V_19 = F_15 ( V_14 , & V_119 , V_118 == V_124 ) ;
if ( V_3 != V_21 -> V_43 && V_118 == V_125 ) {
if ( V_19 != NULL ) {
if ( V_19 -> V_3 != V_3 ) {
V_50 = - V_130 ;
break;
}
} else {
if ( ( ( V_3 -> V_27 & V_113 ) && ! V_119 . V_24 . V_26 ) ||
( ! ( V_3 -> V_27 & V_113 ) && V_119 . V_24 . V_26 ) ) {
V_50 = - V_129 ;
break;
}
V_19 = F_19 ( V_3 ) ;
F_11 ( V_21 , V_19 ) ;
F_79 () ;
V_19 -> V_23 . V_24 . V_25 = V_119 . V_24 . V_25 ;
V_19 -> V_23 . V_24 . V_26 = V_119 . V_24 . V_26 ;
memcpy ( V_3 -> V_131 , & V_119 . V_24 . V_25 , 4 ) ;
memcpy ( V_3 -> V_132 , & V_119 . V_24 . V_26 , 4 ) ;
F_14 ( V_21 , V_19 ) ;
F_80 ( V_3 ) ;
}
}
if ( V_19 ) {
V_50 = 0 ;
if ( V_118 == V_125 ) {
V_19 -> V_23 . V_24 . V_60 = V_119 . V_24 . V_60 ;
V_19 -> V_23 . V_24 . V_67 = V_119 . V_24 . V_67 ;
V_19 -> V_23 . V_24 . V_79 = V_119 . V_24 . V_79 ;
if ( V_19 -> V_23 . V_93 != V_119 . V_93 ) {
V_19 -> V_23 . V_93 = V_119 . V_93 ;
F_73 ( V_3 ) ;
F_80 ( V_3 ) ;
}
}
if ( F_77 ( V_117 -> V_121 . V_122 , & V_19 -> V_23 , sizeof( V_119 ) ) )
V_50 = - V_123 ;
} else
V_50 = ( V_118 == V_124 ? - V_133 : - V_58 ) ;
break;
case V_134 :
V_50 = - V_126 ;
if ( ! F_78 ( V_127 ) )
goto V_128;
if ( V_3 == V_21 -> V_43 ) {
V_50 = - V_123 ;
if ( F_76 ( & V_119 , V_117 -> V_121 . V_122 , sizeof( V_119 ) ) )
goto V_128;
V_50 = - V_58 ;
if ( ( V_19 = F_15 ( V_14 , & V_119 , 0 ) ) == NULL )
goto V_128;
V_50 = - V_126 ;
if ( V_19 -> V_3 == V_21 -> V_43 )
goto V_128;
V_3 = V_19 -> V_3 ;
}
F_81 ( V_3 ) ;
V_50 = 0 ;
break;
default:
V_50 = - V_129 ;
}
V_128:
return V_50 ;
}
static int F_82 ( struct V_2 * V_3 , int V_135 )
{
if ( V_135 < 68 || V_135 > 0xFFF8 - sizeof( struct V_47 ) )
return - V_129 ;
V_3 -> V_88 = V_135 ;
return 0 ;
}
static void F_23 ( struct V_2 * V_3 )
{
F_83 ( V_3 -> V_7 ) ;
F_84 ( V_3 ) ;
}
static void V_41 ( struct V_2 * V_3 )
{
V_3 -> V_136 = & V_137 ;
V_3 -> V_138 = F_23 ;
V_3 -> type = V_139 ;
V_3 -> V_114 = V_140 + sizeof( struct V_47 ) ;
V_3 -> V_88 = V_141 - sizeof( struct V_47 ) ;
V_3 -> V_27 = V_142 ;
V_3 -> V_115 = 0 ;
V_3 -> V_143 = 4 ;
V_3 -> V_144 |= V_145 ;
V_3 -> V_144 |= V_146 ;
V_3 -> V_147 &= ~ V_148 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_13 * V_68 = F_19 ( V_3 ) ;
V_68 -> V_3 = V_3 ;
memcpy ( V_3 -> V_131 , & V_68 -> V_23 . V_24 . V_25 , 4 ) ;
memcpy ( V_3 -> V_132 , & V_68 -> V_23 . V_24 . V_26 , 4 ) ;
F_73 ( V_3 ) ;
V_3 -> V_7 = F_85 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_149 ;
return 0 ;
}
static int T_7 F_86 ( struct V_2 * V_3 )
{
struct V_13 * V_68 = F_19 ( V_3 ) ;
struct V_47 * V_24 = & V_68 -> V_23 . V_24 ;
struct V_20 * V_21 = F_6 ( F_25 ( V_3 ) , V_22 ) ;
V_68 -> V_3 = V_3 ;
strcpy ( V_68 -> V_23 . V_39 , V_3 -> V_39 ) ;
V_24 -> V_110 = 4 ;
V_24 -> V_72 = V_92 ;
V_24 -> V_111 = 5 ;
V_3 -> V_7 = F_85 ( struct V_4 ) ;
if ( ! V_3 -> V_7 )
return - V_149 ;
F_22 ( V_3 ) ;
F_13 ( V_21 -> V_29 [ 0 ] , V_68 ) ;
return 0 ;
}
static void F_87 ( struct V_20 * V_21 , struct V_150 * V_151 )
{
int V_32 ;
for ( V_32 = 1 ; V_32 < 4 ; V_32 ++ ) {
int V_31 ;
for ( V_31 = 0 ; V_31 < V_152 ; V_31 ++ ) {
struct V_13 * V_19 ;
V_19 = F_12 ( V_21 -> V_33 [ V_32 ] [ V_31 ] ) ;
while ( V_19 != NULL ) {
F_88 ( V_19 -> V_3 , V_151 ) ;
V_19 = F_12 ( V_19 -> V_36 ) ;
}
}
}
}
static int T_7 F_89 ( struct V_14 * V_14 )
{
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
struct V_13 * V_19 ;
int V_50 ;
V_21 -> V_33 [ 0 ] = V_21 -> V_29 ;
V_21 -> V_33 [ 1 ] = V_21 -> V_153 ;
V_21 -> V_33 [ 2 ] = V_21 -> V_154 ;
V_21 -> V_33 [ 3 ] = V_21 -> V_155 ;
V_21 -> V_43 = F_17 ( sizeof( struct V_13 ) ,
L_2 ,
V_41 ) ;
if ( ! V_21 -> V_43 ) {
V_50 = - V_149 ;
goto V_156;
}
F_18 ( V_21 -> V_43 , V_14 ) ;
V_50 = F_86 ( V_21 -> V_43 ) ;
if ( V_50 )
goto V_157;
if ( ( V_50 = F_90 ( V_21 -> V_43 ) ) )
goto V_157;
V_19 = F_19 ( V_21 -> V_43 ) ;
strcpy ( V_19 -> V_23 . V_39 , V_21 -> V_43 -> V_39 ) ;
return 0 ;
V_157:
F_23 ( V_21 -> V_43 ) ;
V_156:
return V_50 ;
}
static void T_8 F_91 ( struct V_14 * V_14 )
{
struct V_20 * V_21 = F_6 ( V_14 , V_22 ) ;
F_92 ( V_158 ) ;
F_93 () ;
F_87 ( V_21 , & V_158 ) ;
F_88 ( V_21 -> V_43 , & V_158 ) ;
F_94 ( & V_158 ) ;
F_95 () ;
}
static int T_9 F_96 ( void )
{
int V_50 ;
F_97 ( V_159 ) ;
V_50 = F_98 ( & V_160 ) ;
if ( V_50 < 0 )
return V_50 ;
V_50 = F_99 ( & V_161 , V_162 ) ;
if ( V_50 < 0 ) {
F_100 ( & V_160 ) ;
F_101 ( L_3 , V_163 ) ;
}
return V_50 ;
}
static void T_10 F_102 ( void )
{
if ( F_103 ( & V_161 , V_162 ) )
F_101 ( L_4 , V_163 ) ;
F_100 ( & V_160 ) ;
}
