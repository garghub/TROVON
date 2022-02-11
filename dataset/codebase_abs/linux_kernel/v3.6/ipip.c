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
default:
break;
}
break;
case V_63 :
if ( V_57 != V_64 )
return 0 ;
break;
case V_65 :
break;
}
V_58 = - V_66 ;
F_32 () ;
V_27 = F_6 ( F_27 ( V_53 -> V_3 ) , V_32 -> V_34 , V_32 -> V_33 ) ;
if ( V_27 == NULL )
goto V_67;
if ( type == V_60 && V_57 == V_68 ) {
F_33 ( V_53 , F_27 ( V_53 -> V_3 ) , V_54 ,
V_27 -> V_3 -> V_69 , 0 , V_70 , 0 ) ;
V_58 = 0 ;
goto V_67;
}
if ( type == V_65 ) {
F_34 ( V_53 , F_27 ( V_53 -> V_3 ) , V_27 -> V_3 -> V_69 , 0 ,
V_70 , 0 ) ;
V_58 = 0 ;
goto V_67;
}
if ( V_27 -> V_31 . V_32 . V_34 == 0 )
goto V_67;
V_58 = 0 ;
if ( V_27 -> V_31 . V_32 . V_71 == 0 && type == V_63 )
goto V_67;
if ( F_35 ( V_72 , V_27 -> V_73 + V_74 ) )
V_27 -> V_75 ++ ;
else
V_27 -> V_75 = 1 ;
V_27 -> V_73 = V_72 ;
V_67:
F_36 () ;
return V_58 ;
}
static inline void F_37 ( const struct V_55 * V_76 ,
struct V_52 * V_53 )
{
struct V_55 * V_77 = F_38 ( V_53 ) ;
if ( F_39 ( V_76 -> V_78 ) )
F_40 ( V_77 ) ;
}
static int F_41 ( struct V_52 * V_53 )
{
struct V_21 * V_79 ;
const struct V_55 * V_32 = F_38 ( V_53 ) ;
F_32 () ;
V_79 = F_6 ( F_27 ( V_53 -> V_3 ) , V_32 -> V_33 , V_32 -> V_34 ) ;
if ( V_79 != NULL ) {
struct V_6 * V_7 ;
if ( ! F_42 ( NULL , V_80 , V_53 ) ) {
F_36 () ;
F_43 ( V_53 ) ;
return 0 ;
}
F_44 ( V_53 ) ;
V_53 -> V_81 = V_53 -> V_82 ;
F_45 ( V_53 ) ;
V_53 -> V_83 = F_46 ( V_84 ) ;
V_53 -> V_85 = V_86 ;
V_7 = F_47 ( V_79 -> V_3 -> V_7 ) ;
F_48 ( & V_7 -> V_13 ) ;
V_7 -> V_8 ++ ;
V_7 -> V_9 += V_53 -> V_87 ;
F_49 ( & V_7 -> V_13 ) ;
F_50 ( V_53 , V_79 -> V_3 ) ;
F_37 ( V_32 , V_53 ) ;
F_51 ( V_53 ) ;
F_36 () ;
return 0 ;
}
F_36 () ;
return - 1 ;
}
static T_5 F_52 ( struct V_52 * V_53 , struct V_2 * V_3 )
{
struct V_21 * V_79 = F_21 ( V_3 ) ;
struct V_6 * V_7 ;
const struct V_55 * V_88 = & V_79 -> V_31 . V_32 ;
T_6 V_78 = V_79 -> V_31 . V_32 . V_78 ;
T_7 V_89 = V_88 -> V_90 ;
struct V_91 * V_92 ;
struct V_2 * V_93 ;
const struct V_55 * V_94 = F_38 ( V_53 ) ;
struct V_55 * V_32 ;
unsigned int V_95 ;
T_2 V_96 = V_88 -> V_34 ;
struct V_97 V_98 ;
int V_99 ;
if ( V_53 -> V_83 != F_46 ( V_84 ) )
goto V_100;
if ( V_78 & 1 )
V_78 = V_94 -> V_78 ;
if ( ! V_96 ) {
if ( ( V_92 = F_53 ( V_53 ) ) == NULL ) {
V_3 -> V_15 . V_14 ++ ;
goto V_100;
}
V_96 = F_54 ( V_92 , V_94 -> V_34 ) ;
}
V_92 = F_55 ( F_27 ( V_3 ) , & V_98 , NULL ,
V_96 , V_88 -> V_33 ,
0 , 0 ,
V_70 , F_56 ( V_78 ) ,
V_79 -> V_31 . V_101 ) ;
if ( F_57 ( V_92 ) ) {
V_3 -> V_15 . V_16 ++ ;
goto V_102;
}
V_93 = V_92 -> V_96 . V_3 ;
if ( V_93 == V_3 ) {
F_58 ( V_92 ) ;
V_3 -> V_15 . V_20 ++ ;
goto V_100;
}
V_89 |= V_94 -> V_90 & F_46 ( V_103 ) ;
if ( V_89 ) {
V_99 = F_59 ( & V_92 -> V_96 ) - sizeof( struct V_55 ) ;
if ( V_99 < 68 ) {
V_3 -> V_15 . V_20 ++ ;
F_58 ( V_92 ) ;
goto V_100;
}
if ( F_60 ( V_53 ) )
F_60 ( V_53 ) -> V_104 -> V_105 ( F_60 ( V_53 ) , NULL , V_53 , V_99 ) ;
if ( ( V_94 -> V_90 & F_46 ( V_103 ) ) &&
V_99 < F_61 ( V_94 -> V_106 ) ) {
F_62 ( V_53 , V_60 , V_68 ,
F_63 ( V_99 ) ) ;
F_58 ( V_92 ) ;
goto V_100;
}
}
if ( V_79 -> V_75 > 0 ) {
if ( F_35 ( V_72 ,
V_79 -> V_73 + V_74 ) ) {
V_79 -> V_75 -- ;
F_64 ( V_53 ) ;
} else
V_79 -> V_75 = 0 ;
}
V_95 = ( F_65 ( V_93 ) + sizeof( struct V_55 ) ) ;
if ( F_66 ( V_53 ) < V_95 || F_67 ( V_53 ) ||
( F_68 ( V_53 ) && ! F_69 ( V_53 , 0 ) ) ) {
struct V_52 * V_107 = F_70 ( V_53 , V_95 ) ;
if ( ! V_107 ) {
F_58 ( V_92 ) ;
V_3 -> V_15 . V_17 ++ ;
F_71 ( V_53 ) ;
return V_108 ;
}
if ( V_53 -> V_109 )
F_72 ( V_107 , V_53 -> V_109 ) ;
F_71 ( V_53 ) ;
V_53 = V_107 ;
V_94 = F_38 ( V_53 ) ;
}
V_53 -> V_110 = V_53 -> V_82 ;
F_73 ( V_53 , sizeof( struct V_55 ) ) ;
F_45 ( V_53 ) ;
memset ( & ( F_74 ( V_53 ) -> V_111 ) , 0 , sizeof( F_74 ( V_53 ) -> V_111 ) ) ;
F_74 ( V_53 ) -> V_35 &= ~ ( V_112 | V_113 |
V_114 ) ;
F_75 ( V_53 ) ;
F_76 ( V_53 , & V_92 -> V_96 ) ;
V_32 = F_38 ( V_53 ) ;
V_32 -> V_115 = 4 ;
V_32 -> V_116 = sizeof( struct V_55 ) >> 2 ;
V_32 -> V_90 = V_89 ;
V_32 -> V_83 = V_70 ;
V_32 -> V_78 = F_77 ( V_78 , V_94 -> V_78 ) ;
V_32 -> V_34 = V_98 . V_34 ;
V_32 -> V_33 = V_98 . V_33 ;
if ( ( V_32 -> V_71 = V_88 -> V_71 ) == 0 )
V_32 -> V_71 = V_94 -> V_71 ;
F_78 ( V_53 ) ;
V_7 = F_47 ( V_3 -> V_7 ) ;
F_79 ( V_7 , & V_3 -> V_15 ) ;
return V_108 ;
V_102:
F_64 ( V_53 ) ;
V_100:
V_3 -> V_15 . V_19 ++ ;
F_71 ( V_53 ) ;
return V_108 ;
}
static void F_80 ( struct V_2 * V_3 )
{
struct V_2 * V_93 = NULL ;
struct V_21 * V_79 ;
const struct V_55 * V_32 ;
V_79 = F_21 ( V_3 ) ;
V_32 = & V_79 -> V_31 . V_32 ;
if ( V_32 -> V_34 ) {
struct V_91 * V_92 ;
struct V_97 V_98 ;
V_92 = F_55 ( F_27 ( V_3 ) , & V_98 , NULL ,
V_32 -> V_34 , V_32 -> V_33 ,
0 , 0 ,
V_70 ,
F_56 ( V_32 -> V_78 ) ,
V_79 -> V_31 . V_101 ) ;
if ( ! F_57 ( V_92 ) ) {
V_93 = V_92 -> V_96 . V_3 ;
F_58 ( V_92 ) ;
}
V_3 -> V_35 |= V_117 ;
}
if ( ! V_93 && V_79 -> V_31 . V_101 )
V_93 = F_81 ( F_27 ( V_3 ) , V_79 -> V_31 . V_101 ) ;
if ( V_93 ) {
V_3 -> V_118 = V_93 -> V_118 + sizeof( struct V_55 ) ;
V_3 -> V_99 = V_93 -> V_99 - sizeof( struct V_55 ) ;
}
V_3 -> V_119 = V_79 -> V_31 . V_101 ;
}
static int
F_82 ( struct V_2 * V_3 , struct V_120 * V_121 , int V_122 )
{
int V_58 = 0 ;
struct V_38 V_123 ;
struct V_21 * V_27 ;
struct V_22 * V_22 = F_27 ( V_3 ) ;
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
switch ( V_122 ) {
case V_124 :
V_27 = NULL ;
if ( V_3 == V_29 -> V_51 ) {
if ( F_83 ( & V_123 , V_121 -> V_125 . V_126 , sizeof( V_123 ) ) ) {
V_58 = - V_127 ;
break;
}
V_27 = F_17 ( V_22 , & V_123 , 0 ) ;
}
if ( V_27 == NULL )
V_27 = F_21 ( V_3 ) ;
memcpy ( & V_123 , & V_27 -> V_31 , sizeof( V_123 ) ) ;
if ( F_84 ( V_121 -> V_125 . V_126 , & V_123 , sizeof( V_123 ) ) )
V_58 = - V_127 ;
break;
case V_128 :
case V_129 :
V_58 = - V_130 ;
if ( ! F_85 ( V_131 ) )
goto V_132;
V_58 = - V_127 ;
if ( F_83 ( & V_123 , V_121 -> V_125 . V_126 , sizeof( V_123 ) ) )
goto V_132;
V_58 = - V_133 ;
if ( V_123 . V_32 . V_115 != 4 || V_123 . V_32 . V_83 != V_70 ||
V_123 . V_32 . V_116 != 5 || ( V_123 . V_32 . V_90 & F_46 ( ~ V_103 ) ) )
goto V_132;
if ( V_123 . V_32 . V_71 )
V_123 . V_32 . V_90 |= F_46 ( V_103 ) ;
V_27 = F_17 ( V_22 , & V_123 , V_122 == V_128 ) ;
if ( V_3 != V_29 -> V_51 && V_122 == V_129 ) {
if ( V_27 != NULL ) {
if ( V_27 -> V_3 != V_3 ) {
V_58 = - V_134 ;
break;
}
} else {
if ( ( ( V_3 -> V_35 & V_117 ) && ! V_123 . V_32 . V_34 ) ||
( ! ( V_3 -> V_35 & V_117 ) && V_123 . V_32 . V_34 ) ) {
V_58 = - V_133 ;
break;
}
V_27 = F_21 ( V_3 ) ;
F_13 ( V_29 , V_27 ) ;
F_86 () ;
V_27 -> V_31 . V_32 . V_33 = V_123 . V_32 . V_33 ;
V_27 -> V_31 . V_32 . V_34 = V_123 . V_32 . V_34 ;
memcpy ( V_3 -> V_135 , & V_123 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_136 , & V_123 . V_32 . V_34 , 4 ) ;
F_16 ( V_29 , V_27 ) ;
F_87 ( V_3 ) ;
}
}
if ( V_27 ) {
V_58 = 0 ;
if ( V_122 == V_129 ) {
V_27 -> V_31 . V_32 . V_71 = V_123 . V_32 . V_71 ;
V_27 -> V_31 . V_32 . V_78 = V_123 . V_32 . V_78 ;
V_27 -> V_31 . V_32 . V_90 = V_123 . V_32 . V_90 ;
if ( V_27 -> V_31 . V_101 != V_123 . V_101 ) {
V_27 -> V_31 . V_101 = V_123 . V_101 ;
F_80 ( V_3 ) ;
F_87 ( V_3 ) ;
}
}
if ( F_84 ( V_121 -> V_125 . V_126 , & V_27 -> V_31 , sizeof( V_123 ) ) )
V_58 = - V_127 ;
} else
V_58 = ( V_122 == V_128 ? - V_137 : - V_66 ) ;
break;
case V_138 :
V_58 = - V_130 ;
if ( ! F_85 ( V_131 ) )
goto V_132;
if ( V_3 == V_29 -> V_51 ) {
V_58 = - V_127 ;
if ( F_83 ( & V_123 , V_121 -> V_125 . V_126 , sizeof( V_123 ) ) )
goto V_132;
V_58 = - V_66 ;
if ( ( V_27 = F_17 ( V_22 , & V_123 , 0 ) ) == NULL )
goto V_132;
V_58 = - V_130 ;
if ( V_27 -> V_3 == V_29 -> V_51 )
goto V_132;
V_3 = V_27 -> V_3 ;
}
F_88 ( V_3 ) ;
V_58 = 0 ;
break;
default:
V_58 = - V_133 ;
}
V_132:
return V_58 ;
}
static int F_89 ( struct V_2 * V_3 , int V_139 )
{
if ( V_139 < 68 || V_139 > 0xFFF8 - sizeof( struct V_55 ) )
return - V_133 ;
V_3 -> V_99 = V_139 ;
return 0 ;
}
static void F_25 ( struct V_2 * V_3 )
{
F_90 ( V_3 -> V_7 ) ;
F_91 ( V_3 ) ;
}
static void V_49 ( struct V_2 * V_3 )
{
V_3 -> V_140 = & V_141 ;
V_3 -> V_142 = F_25 ;
V_3 -> type = V_143 ;
V_3 -> V_118 = V_144 + sizeof( struct V_55 ) ;
V_3 -> V_99 = V_145 - sizeof( struct V_55 ) ;
V_3 -> V_35 = V_146 ;
V_3 -> V_119 = 0 ;
V_3 -> V_147 = 4 ;
V_3 -> V_148 |= V_149 ;
V_3 -> V_148 |= V_150 ;
V_3 -> V_151 &= ~ V_152 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_21 * V_79 = F_21 ( V_3 ) ;
V_79 -> V_3 = V_3 ;
memcpy ( V_3 -> V_135 , & V_79 -> V_31 . V_32 . V_33 , 4 ) ;
memcpy ( V_3 -> V_136 , & V_79 -> V_31 . V_32 . V_34 , 4 ) ;
F_80 ( V_3 ) ;
V_3 -> V_7 = F_92 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_153 ;
return 0 ;
}
static int T_8 F_93 ( struct V_2 * V_3 )
{
struct V_21 * V_79 = F_21 ( V_3 ) ;
struct V_55 * V_32 = & V_79 -> V_31 . V_32 ;
struct V_28 * V_29 = F_8 ( F_27 ( V_3 ) , V_30 ) ;
V_79 -> V_3 = V_3 ;
strcpy ( V_79 -> V_31 . V_47 , V_3 -> V_47 ) ;
V_32 -> V_115 = 4 ;
V_32 -> V_83 = V_70 ;
V_32 -> V_116 = 5 ;
V_3 -> V_7 = F_92 ( struct V_6 ) ;
if ( ! V_3 -> V_7 )
return - V_153 ;
F_24 ( V_3 ) ;
F_15 ( V_29 -> V_37 [ 0 ] , V_79 ) ;
return 0 ;
}
static void F_94 ( struct V_28 * V_29 , struct V_154 * V_155 )
{
int V_40 ;
for ( V_40 = 1 ; V_40 < 4 ; V_40 ++ ) {
int V_39 ;
for ( V_39 = 0 ; V_39 < V_156 ; V_39 ++ ) {
struct V_21 * V_27 ;
V_27 = F_14 ( V_29 -> V_41 [ V_40 ] [ V_39 ] ) ;
while ( V_27 != NULL ) {
F_95 ( V_27 -> V_3 , V_155 ) ;
V_27 = F_14 ( V_27 -> V_44 ) ;
}
}
}
}
static int T_8 F_96 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
struct V_21 * V_27 ;
int V_58 ;
V_29 -> V_41 [ 0 ] = V_29 -> V_37 ;
V_29 -> V_41 [ 1 ] = V_29 -> V_157 ;
V_29 -> V_41 [ 2 ] = V_29 -> V_158 ;
V_29 -> V_41 [ 3 ] = V_29 -> V_159 ;
V_29 -> V_51 = F_19 ( sizeof( struct V_21 ) ,
L_2 ,
V_49 ) ;
if ( ! V_29 -> V_51 ) {
V_58 = - V_153 ;
goto V_160;
}
F_20 ( V_29 -> V_51 , V_22 ) ;
V_58 = F_93 ( V_29 -> V_51 ) ;
if ( V_58 )
goto V_161;
if ( ( V_58 = F_97 ( V_29 -> V_51 ) ) )
goto V_161;
V_27 = F_21 ( V_29 -> V_51 ) ;
strcpy ( V_27 -> V_31 . V_47 , V_29 -> V_51 -> V_47 ) ;
return 0 ;
V_161:
F_25 ( V_29 -> V_51 ) ;
V_160:
return V_58 ;
}
static void T_9 F_98 ( struct V_22 * V_22 )
{
struct V_28 * V_29 = F_8 ( V_22 , V_30 ) ;
F_99 ( V_162 ) ;
F_100 () ;
F_94 ( V_29 , & V_162 ) ;
F_95 ( V_29 -> V_51 , & V_162 ) ;
F_101 ( & V_162 ) ;
F_102 () ;
}
static int T_10 F_103 ( void )
{
int V_58 ;
F_104 ( V_163 ) ;
V_58 = F_105 ( & V_164 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_106 ( & V_165 , V_166 ) ;
if ( V_58 < 0 ) {
F_107 ( & V_164 ) ;
F_108 ( L_3 , V_167 ) ;
}
return V_58 ;
}
static void T_11 F_109 ( void )
{
if ( F_110 ( & V_165 , V_166 ) )
F_108 ( L_4 , V_167 ) ;
F_107 ( & V_164 ) ;
}
