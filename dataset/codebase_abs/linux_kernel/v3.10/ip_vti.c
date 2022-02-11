static struct V_1 * F_1 ( struct V_2 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
unsigned V_5 = F_2 ( V_3 ) ;
unsigned V_6 = F_2 ( V_4 ) ;
struct V_1 * V_7 ;
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
F_4 (t, ipn->tunnels_r_l[h0 ^ h1])
if ( V_4 == V_7 -> V_11 . V_12 . V_13 &&
V_3 == V_7 -> V_11 . V_12 . V_14 && ( V_7 -> V_15 -> V_16 & V_17 ) )
return V_7 ;
F_4 (t, ipn->tunnels_r[h0])
if ( V_3 == V_7 -> V_11 . V_12 . V_14 && ( V_7 -> V_15 -> V_16 & V_17 ) )
return V_7 ;
F_4 (t, ipn->tunnels_l[h1])
if ( V_4 == V_7 -> V_11 . V_12 . V_13 && ( V_7 -> V_15 -> V_16 & V_17 ) )
return V_7 ;
F_4 (t, ipn->tunnels_wc[0])
if ( V_7 && ( V_7 -> V_15 -> V_16 & V_17 ) )
return V_7 ;
return NULL ;
}
static struct V_1 T_2 * * F_5 ( struct V_8 * V_9 ,
struct V_18 * V_11 )
{
T_1 V_3 = V_11 -> V_12 . V_14 ;
T_1 V_4 = V_11 -> V_12 . V_13 ;
unsigned V_19 = 0 ;
int V_20 = 0 ;
if ( V_3 ) {
V_20 |= 2 ;
V_19 ^= F_2 ( V_3 ) ;
}
if ( V_4 ) {
V_20 |= 1 ;
V_19 ^= F_2 ( V_4 ) ;
}
return & V_9 -> V_21 [ V_20 ] [ V_19 ] ;
}
static inline struct V_1 T_2 * * F_6 ( struct V_8 * V_9 ,
struct V_1 * V_7 )
{
return F_5 ( V_9 , & V_7 -> V_11 ) ;
}
static void F_7 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
struct V_1 T_2 * * V_22 ;
struct V_1 * V_23 ;
for ( V_22 = F_6 ( V_9 , V_7 ) ;
( V_23 = F_8 ( * V_22 ) ) != NULL ;
V_22 = & V_23 -> V_24 ) {
if ( V_7 == V_23 ) {
F_9 ( * V_22 , V_7 -> V_24 ) ;
break;
}
}
}
static void F_10 ( struct V_8 * V_9 , struct V_1 * V_7 )
{
struct V_1 T_2 * * V_22 = F_6 ( V_9 , V_7 ) ;
F_9 ( V_7 -> V_24 , F_8 ( * V_22 ) ) ;
F_9 ( * V_22 , V_7 ) ;
}
static struct V_1 * F_11 ( struct V_2 * V_2 ,
struct V_18 * V_11 ,
int V_25 )
{
T_1 V_3 = V_11 -> V_12 . V_14 ;
T_1 V_4 = V_11 -> V_12 . V_13 ;
struct V_1 * V_7 , * V_26 ;
struct V_1 T_2 * * V_22 ;
struct V_27 * V_15 ;
char V_28 [ V_29 ] ;
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
for ( V_22 = F_5 ( V_9 , V_11 ) ;
( V_7 = F_8 ( * V_22 ) ) != NULL ;
V_22 = & V_7 -> V_24 ) {
if ( V_4 == V_7 -> V_11 . V_12 . V_13 && V_3 == V_7 -> V_11 . V_12 . V_14 )
return V_7 ;
}
if ( ! V_25 )
return NULL ;
if ( V_11 -> V_28 [ 0 ] )
F_12 ( V_28 , V_11 -> V_28 , V_29 ) ;
else
strcpy ( V_28 , L_1 ) ;
V_15 = F_13 ( sizeof( * V_7 ) , V_28 , V_30 ) ;
if ( V_15 == NULL )
return NULL ;
F_14 ( V_15 , V_2 ) ;
V_26 = F_15 ( V_15 ) ;
V_26 -> V_11 = * V_11 ;
V_15 -> V_31 = & V_32 ;
F_16 ( V_15 ) ;
if ( F_17 ( V_15 ) < 0 )
goto V_33;
F_18 ( V_15 ) ;
F_10 ( V_9 , V_26 ) ;
return V_26 ;
V_33:
F_19 ( V_15 ) ;
return NULL ;
}
static void F_20 ( struct V_27 * V_15 )
{
struct V_2 * V_2 = F_21 ( V_15 ) ;
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
F_7 ( V_9 , F_15 ( V_15 ) ) ;
F_22 ( V_15 ) ;
}
static int F_23 ( struct V_34 * V_35 , T_3 V_36 )
{
struct V_37 * V_12 = (struct V_37 * ) V_35 -> V_38 ;
const int type = F_24 ( V_35 ) -> type ;
const int V_39 = F_24 ( V_35 ) -> V_39 ;
struct V_1 * V_7 ;
int V_40 ;
switch ( type ) {
default:
case V_41 :
return 0 ;
case V_42 :
switch ( V_39 ) {
case V_43 :
case V_44 :
return 0 ;
default:
break;
}
break;
case V_45 :
if ( V_39 != V_46 )
return 0 ;
break;
}
V_40 = - V_47 ;
V_7 = F_1 ( F_21 ( V_35 -> V_15 ) , V_12 -> V_14 , V_12 -> V_13 ) ;
if ( V_7 == NULL )
goto V_48;
if ( type == V_42 && V_39 == V_49 ) {
F_25 ( V_35 , F_21 ( V_35 -> V_15 ) , V_36 ,
V_7 -> V_11 . V_50 , 0 , V_51 , 0 ) ;
V_40 = 0 ;
goto V_48;
}
V_40 = 0 ;
if ( V_7 -> V_11 . V_12 . V_52 == 0 && type == V_45 )
goto V_48;
if ( F_26 ( V_53 , V_7 -> V_54 + V_55 ) )
V_7 -> V_56 ++ ;
else
V_7 -> V_56 = 1 ;
V_7 -> V_54 = V_53 ;
V_48:
return V_40 ;
}
static int F_27 ( struct V_34 * V_35 )
{
struct V_1 * V_57 ;
const struct V_37 * V_12 = F_28 ( V_35 ) ;
V_57 = F_1 ( F_21 ( V_35 -> V_15 ) , V_12 -> V_13 , V_12 -> V_14 ) ;
if ( V_57 != NULL ) {
struct V_58 * V_59 ;
if ( ! F_29 ( NULL , V_60 , V_35 ) )
return - 1 ;
V_59 = F_30 ( V_57 -> V_15 -> V_59 ) ;
F_31 ( & V_59 -> V_61 ) ;
V_59 -> V_62 ++ ;
V_59 -> V_63 += V_35 -> V_64 ;
F_32 ( & V_59 -> V_61 ) ;
V_35 -> V_65 = 0 ;
F_33 ( V_35 ) ;
V_35 -> V_15 = V_57 -> V_15 ;
return 1 ;
}
return - 1 ;
}
static T_4 F_34 ( struct V_34 * V_35 , struct V_27 * V_15 )
{
struct V_1 * V_57 = F_15 ( V_15 ) ;
struct V_58 * V_59 ;
struct V_37 * V_66 = & V_57 -> V_11 . V_12 ;
T_5 V_67 ;
struct V_68 * V_69 ;
struct V_27 * V_70 ;
struct V_37 * V_71 = F_28 ( V_35 ) ;
T_1 V_72 = V_66 -> V_14 ;
struct V_73 V_74 ;
if ( V_35 -> V_75 != F_35 ( V_76 ) )
goto V_77;
V_67 = V_71 -> V_67 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
F_36 ( & V_74 , V_57 -> V_11 . V_50 ,
F_37 ( V_57 -> V_11 . V_78 ) , F_38 ( V_67 ) ,
V_79 ,
V_51 , 0 ,
V_72 , V_66 -> V_13 , 0 , 0 ) ;
V_69 = F_39 ( F_21 ( V_15 ) , & V_74 ) ;
if ( F_40 ( V_69 ) ) {
V_15 -> V_80 . V_81 ++ ;
goto V_82;
}
if ( ! V_69 -> V_72 . V_83 ||
V_69 -> V_72 . V_83 -> V_84 . V_85 != V_86 ) {
V_15 -> V_80 . V_81 ++ ;
goto V_82;
}
V_70 = V_69 -> V_72 . V_15 ;
if ( V_70 == V_15 ) {
F_41 ( V_69 ) ;
V_15 -> V_80 . V_87 ++ ;
goto V_77;
}
if ( V_57 -> V_56 > 0 ) {
if ( F_26 ( V_53 ,
V_57 -> V_54 + V_55 ) ) {
V_57 -> V_56 -- ;
F_42 ( V_35 ) ;
} else
V_57 -> V_56 = 0 ;
}
memset ( F_43 ( V_35 ) , 0 , sizeof( * F_43 ( V_35 ) ) ) ;
F_44 ( V_35 ) ;
F_45 ( V_35 , & V_69 -> V_72 ) ;
F_46 ( V_35 ) ;
V_35 -> V_15 = F_47 ( V_35 ) -> V_15 ;
V_59 = F_30 ( V_15 -> V_59 ) ;
F_48 ( V_59 , & V_15 -> V_80 ) ;
return V_88 ;
V_82:
F_42 ( V_35 ) ;
V_77:
V_15 -> V_80 . V_89 ++ ;
F_49 ( V_35 ) ;
return V_88 ;
}
static int F_16 ( struct V_27 * V_15 )
{
struct V_27 * V_70 = NULL ;
struct V_1 * V_57 ;
struct V_37 * V_12 ;
V_57 = F_15 ( V_15 ) ;
V_12 = & V_57 -> V_11 . V_12 ;
if ( V_12 -> V_14 ) {
struct V_68 * V_69 ;
struct V_73 V_74 ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
F_36 ( & V_74 , V_57 -> V_11 . V_50 ,
F_37 ( V_57 -> V_11 . V_78 ) ,
F_38 ( V_12 -> V_67 ) , V_79 ,
V_51 , 0 ,
V_12 -> V_14 , V_12 -> V_13 , 0 , 0 ) ;
V_69 = F_39 ( F_21 ( V_15 ) , & V_74 ) ;
if ( ! F_40 ( V_69 ) ) {
V_70 = V_69 -> V_72 . V_15 ;
F_41 ( V_69 ) ;
}
V_15 -> V_16 |= V_90 ;
}
if ( ! V_70 && V_57 -> V_11 . V_50 )
V_70 = F_50 ( F_21 ( V_15 ) , V_57 -> V_11 . V_50 ) ;
if ( V_70 ) {
V_15 -> V_91 = V_70 -> V_91 +
sizeof( struct V_37 ) ;
V_15 -> V_92 = V_70 -> V_92 ;
}
V_15 -> V_93 = V_57 -> V_11 . V_50 ;
return V_15 -> V_92 ;
}
static int
F_51 ( struct V_27 * V_15 , struct V_94 * V_95 , int V_96 )
{
int V_40 = 0 ;
struct V_18 V_97 ;
struct V_1 * V_7 ;
struct V_2 * V_2 = F_21 ( V_15 ) ;
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
switch ( V_96 ) {
case V_98 :
V_7 = NULL ;
if ( V_15 == V_9 -> V_99 ) {
if ( F_52 ( & V_97 , V_95 -> V_100 . V_101 ,
sizeof( V_97 ) ) ) {
V_40 = - V_102 ;
break;
}
V_7 = F_11 ( V_2 , & V_97 , 0 ) ;
}
if ( V_7 == NULL )
V_7 = F_15 ( V_15 ) ;
memcpy ( & V_97 , & V_7 -> V_11 , sizeof( V_97 ) ) ;
V_97 . V_103 |= V_104 | V_105 ;
V_97 . V_106 |= V_104 ;
if ( F_53 ( V_95 -> V_100 . V_101 , & V_97 , sizeof( V_97 ) ) )
V_40 = - V_102 ;
break;
case V_107 :
case V_108 :
V_40 = - V_109 ;
if ( ! F_54 ( V_2 -> V_110 , V_111 ) )
goto V_112;
V_40 = - V_102 ;
if ( F_52 ( & V_97 , V_95 -> V_100 . V_101 , sizeof( V_97 ) ) )
goto V_112;
V_40 = - V_113 ;
if ( V_97 . V_12 . V_114 != 4 || V_97 . V_12 . V_75 != V_51 ||
V_97 . V_12 . V_115 != 5 )
goto V_112;
V_7 = F_11 ( V_2 , & V_97 , V_96 == V_107 ) ;
if ( V_15 != V_9 -> V_99 && V_96 == V_108 ) {
if ( V_7 != NULL ) {
if ( V_7 -> V_15 != V_15 ) {
V_40 = - V_116 ;
break;
}
} else {
if ( ( ( V_15 -> V_16 & V_90 ) &&
! V_97 . V_12 . V_14 ) ||
( ! ( V_15 -> V_16 & V_90 ) &&
V_97 . V_12 . V_14 ) ) {
V_40 = - V_113 ;
break;
}
V_7 = F_15 ( V_15 ) ;
F_7 ( V_9 , V_7 ) ;
F_55 () ;
V_7 -> V_11 . V_12 . V_13 = V_97 . V_12 . V_13 ;
V_7 -> V_11 . V_12 . V_14 = V_97 . V_12 . V_14 ;
V_7 -> V_11 . V_78 = V_97 . V_78 ;
V_7 -> V_11 . V_117 = V_97 . V_117 ;
V_7 -> V_11 . V_12 . V_75 = V_51 ;
memcpy ( V_15 -> V_118 , & V_97 . V_12 . V_13 , 4 ) ;
memcpy ( V_15 -> V_119 , & V_97 . V_12 . V_14 , 4 ) ;
F_10 ( V_9 , V_7 ) ;
F_56 ( V_15 ) ;
}
}
if ( V_7 ) {
V_40 = 0 ;
if ( V_96 == V_108 ) {
V_7 -> V_11 . V_78 = V_97 . V_78 ;
V_7 -> V_11 . V_117 = V_97 . V_117 ;
if ( V_7 -> V_11 . V_50 != V_97 . V_50 ) {
V_7 -> V_11 . V_50 = V_97 . V_50 ;
F_16 ( V_15 ) ;
F_56 ( V_15 ) ;
}
}
V_97 . V_103 |= V_104 | V_105 ;
V_97 . V_106 |= V_104 ;
if ( F_53 ( V_95 -> V_100 . V_101 , & V_7 -> V_11 ,
sizeof( V_97 ) ) )
V_40 = - V_102 ;
} else
V_40 = ( V_96 == V_107 ? - V_120 : - V_47 ) ;
break;
case V_121 :
V_40 = - V_109 ;
if ( ! F_54 ( V_2 -> V_110 , V_111 ) )
goto V_112;
if ( V_15 == V_9 -> V_99 ) {
V_40 = - V_102 ;
if ( F_52 ( & V_97 , V_95 -> V_100 . V_101 ,
sizeof( V_97 ) ) )
goto V_112;
V_40 = - V_47 ;
V_7 = F_11 ( V_2 , & V_97 , 0 ) ;
if ( V_7 == NULL )
goto V_112;
V_40 = - V_109 ;
if ( V_7 -> V_15 == V_9 -> V_99 )
goto V_112;
V_15 = V_7 -> V_15 ;
}
F_57 ( V_15 ) ;
V_40 = 0 ;
break;
default:
V_40 = - V_113 ;
}
V_112:
return V_40 ;
}
static int F_58 ( struct V_27 * V_15 , int V_122 )
{
if ( V_122 < 68 || V_122 > 0xFFF8 )
return - V_113 ;
V_15 -> V_92 = V_122 ;
return 0 ;
}
static void F_59 ( struct V_27 * V_15 )
{
F_60 ( V_15 -> V_59 ) ;
F_19 ( V_15 ) ;
}
static void V_30 ( struct V_27 * V_15 )
{
V_15 -> V_123 = & V_124 ;
V_15 -> V_125 = F_59 ;
V_15 -> type = V_126 ;
V_15 -> V_91 = V_127 + sizeof( struct V_37 ) ;
V_15 -> V_92 = V_128 ;
V_15 -> V_16 = V_129 ;
V_15 -> V_93 = 0 ;
V_15 -> V_130 = 4 ;
V_15 -> V_131 |= V_132 ;
V_15 -> V_131 |= V_133 ;
V_15 -> V_134 &= ~ V_135 ;
}
static int F_61 ( struct V_27 * V_15 )
{
struct V_1 * V_57 = F_15 ( V_15 ) ;
V_57 -> V_15 = V_15 ;
strcpy ( V_57 -> V_11 . V_28 , V_15 -> V_28 ) ;
memcpy ( V_15 -> V_118 , & V_57 -> V_11 . V_12 . V_13 , 4 ) ;
memcpy ( V_15 -> V_119 , & V_57 -> V_11 . V_12 . V_14 , 4 ) ;
V_15 -> V_59 = F_62 ( struct V_58 ) ;
if ( ! V_15 -> V_59 )
return - V_136 ;
return 0 ;
}
static int T_6 F_63 ( struct V_27 * V_15 )
{
struct V_1 * V_57 = F_15 ( V_15 ) ;
struct V_37 * V_12 = & V_57 -> V_11 . V_12 ;
struct V_8 * V_9 = F_3 ( F_21 ( V_15 ) , V_10 ) ;
V_57 -> V_15 = V_15 ;
strcpy ( V_57 -> V_11 . V_28 , V_15 -> V_28 ) ;
V_12 -> V_114 = 4 ;
V_12 -> V_75 = V_51 ;
V_12 -> V_115 = 5 ;
V_15 -> V_59 = F_62 ( struct V_58 ) ;
if ( ! V_15 -> V_59 )
return - V_136 ;
F_18 ( V_15 ) ;
F_9 ( V_9 -> V_137 [ 0 ] , V_57 ) ;
return 0 ;
}
static void F_64 ( struct V_8 * V_9 , struct V_138 * V_139 )
{
int V_20 ;
for ( V_20 = 1 ; V_20 < 4 ; V_20 ++ ) {
int V_19 ;
for ( V_19 = 0 ; V_19 < V_140 ; V_19 ++ ) {
struct V_1 * V_7 ;
V_7 = F_8 ( V_9 -> V_21 [ V_20 ] [ V_19 ] ) ;
while ( V_7 != NULL ) {
F_65 ( V_7 -> V_15 , V_139 ) ;
V_7 = F_8 ( V_7 -> V_24 ) ;
}
}
}
}
static int T_6 F_66 ( struct V_2 * V_2 )
{
int V_40 ;
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
V_9 -> V_21 [ 0 ] = V_9 -> V_137 ;
V_9 -> V_21 [ 1 ] = V_9 -> V_141 ;
V_9 -> V_21 [ 2 ] = V_9 -> V_142 ;
V_9 -> V_21 [ 3 ] = V_9 -> V_143 ;
V_9 -> V_99 = F_13 ( sizeof( struct V_1 ) ,
L_2 ,
V_30 ) ;
if ( ! V_9 -> V_99 ) {
V_40 = - V_136 ;
goto V_144;
}
F_14 ( V_9 -> V_99 , V_2 ) ;
V_40 = F_63 ( V_9 -> V_99 ) ;
if ( V_40 )
goto V_145;
V_9 -> V_99 -> V_31 = & V_32 ;
V_40 = F_67 ( V_9 -> V_99 ) ;
if ( V_40 )
goto V_145;
return 0 ;
V_145:
F_59 ( V_9 -> V_99 ) ;
V_144:
return V_40 ;
}
static void T_7 F_68 ( struct V_2 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
F_69 ( V_146 ) ;
F_70 () ;
F_64 ( V_9 , & V_146 ) ;
F_71 ( & V_146 ) ;
F_72 () ;
}
static int F_73 ( struct V_147 * V_148 [] , struct V_147 * V_38 [] )
{
return 0 ;
}
static void F_74 ( struct V_147 * V_38 [] ,
struct V_18 * V_11 )
{
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_12 . V_75 = V_51 ;
if ( ! V_38 )
return;
if ( V_38 [ V_149 ] )
V_11 -> V_50 = F_75 ( V_38 [ V_149 ] ) ;
if ( V_38 [ V_150 ] )
V_11 -> V_78 = F_76 ( V_38 [ V_150 ] ) ;
if ( V_38 [ V_151 ] )
V_11 -> V_117 = F_76 ( V_38 [ V_151 ] ) ;
if ( V_38 [ V_152 ] )
V_11 -> V_12 . V_13 = F_76 ( V_38 [ V_152 ] ) ;
if ( V_38 [ V_153 ] )
V_11 -> V_12 . V_14 = F_76 ( V_38 [ V_153 ] ) ;
}
static int F_77 ( struct V_2 * V_154 , struct V_27 * V_15 ,
struct V_147 * V_148 [] , struct V_147 * V_38 [] )
{
struct V_1 * V_26 ;
struct V_2 * V_2 = F_21 ( V_15 ) ;
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
int V_92 ;
int V_40 ;
V_26 = F_15 ( V_15 ) ;
F_74 ( V_38 , & V_26 -> V_11 ) ;
if ( F_11 ( V_2 , & V_26 -> V_11 , 0 ) )
return - V_116 ;
V_92 = F_16 ( V_15 ) ;
if ( ! V_148 [ V_155 ] )
V_15 -> V_92 = V_92 ;
V_40 = F_17 ( V_15 ) ;
if ( V_40 )
goto V_48;
F_18 ( V_15 ) ;
F_10 ( V_9 , V_26 ) ;
V_48:
return V_40 ;
}
static int F_78 ( struct V_27 * V_15 , struct V_147 * V_148 [] ,
struct V_147 * V_38 [] )
{
struct V_1 * V_7 , * V_26 ;
struct V_2 * V_2 = F_21 ( V_15 ) ;
struct V_8 * V_9 = F_3 ( V_2 , V_10 ) ;
struct V_18 V_97 ;
int V_92 ;
if ( V_15 == V_9 -> V_99 )
return - V_113 ;
V_26 = F_15 ( V_15 ) ;
F_74 ( V_38 , & V_97 ) ;
V_7 = F_11 ( V_2 , & V_97 , 0 ) ;
if ( V_7 ) {
if ( V_7 -> V_15 != V_15 )
return - V_116 ;
} else {
V_7 = V_26 ;
F_7 ( V_9 , V_7 ) ;
V_7 -> V_11 . V_12 . V_13 = V_97 . V_12 . V_13 ;
V_7 -> V_11 . V_12 . V_14 = V_97 . V_12 . V_14 ;
V_7 -> V_11 . V_78 = V_97 . V_78 ;
V_7 -> V_11 . V_117 = V_97 . V_117 ;
if ( V_15 -> type != V_156 ) {
memcpy ( V_15 -> V_118 , & V_97 . V_12 . V_13 , 4 ) ;
memcpy ( V_15 -> V_119 , & V_97 . V_12 . V_14 , 4 ) ;
}
F_10 ( V_9 , V_7 ) ;
F_56 ( V_15 ) ;
}
if ( V_7 -> V_11 . V_50 != V_97 . V_50 ) {
V_7 -> V_11 . V_50 = V_97 . V_50 ;
V_92 = F_16 ( V_15 ) ;
if ( ! V_148 [ V_155 ] )
V_15 -> V_92 = V_92 ;
F_56 ( V_15 ) ;
}
return 0 ;
}
static T_8 F_79 ( const struct V_27 * V_15 )
{
return
F_80 ( 4 ) +
F_80 ( 4 ) +
F_80 ( 4 ) +
F_80 ( 4 ) +
F_80 ( 4 ) +
0 ;
}
static int F_81 ( struct V_34 * V_35 , const struct V_27 * V_15 )
{
struct V_1 * V_7 = F_15 ( V_15 ) ;
struct V_18 * V_97 = & V_7 -> V_11 ;
F_82 ( V_35 , V_149 , V_97 -> V_50 ) ;
F_83 ( V_35 , V_150 , V_97 -> V_78 ) ;
F_83 ( V_35 , V_151 , V_97 -> V_117 ) ;
F_83 ( V_35 , V_152 , V_97 -> V_12 . V_13 ) ;
F_83 ( V_35 , V_153 , V_97 -> V_12 . V_14 ) ;
return 0 ;
}
static int T_9 F_84 ( void )
{
int V_40 ;
F_85 ( L_3 ) ;
V_40 = F_86 ( & V_157 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_87 ( & V_158 ) ;
if ( V_40 < 0 ) {
F_88 ( & V_157 ) ;
F_85 ( V_159 L_4 ) ;
}
V_40 = F_89 ( & V_32 ) ;
if ( V_40 < 0 )
goto V_160;
return V_40 ;
V_160:
F_90 ( & V_158 ) ;
F_88 ( & V_157 ) ;
return V_40 ;
}
static void T_10 F_91 ( void )
{
F_92 ( & V_32 ) ;
if ( F_90 ( & V_158 ) )
F_85 ( L_5 ) ;
F_88 ( & V_157 ) ;
}
