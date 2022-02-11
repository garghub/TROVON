static unsigned int F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 , V_3 , V_4 ;
for ( V_2 = V_3 = 0 ; V_2 < V_5 ; V_2 ++ ) {
if ( V_6 [ V_2 ] != V_7 || ! V_1 -> V_8 [ V_2 ] )
continue;
V_4 = F_2 ( V_1 -> V_8 [ V_2 ] ) ;
if ( V_4 )
V_3 |= F_3 ( V_2 ) ;
}
return V_3 ;
}
static void F_4 ( struct V_1 * V_1 , unsigned int V_3 )
{
if ( V_3 & V_9 ) {
if ( V_1 -> V_8 [ V_10 ] )
F_5 ( V_1 -> V_8 [ V_10 ] ,
V_3 & V_11 ) ;
if ( V_3 & V_12 )
F_5 ( V_1 -> V_8 [ V_13 ] ,
V_3 & V_12 ) ;
} else {
if ( V_1 -> V_8 [ V_10 ] )
F_6 ( V_1 -> V_8 [ V_10 ] ) ;
if ( V_3 & V_12 )
F_6 ( V_1 -> V_8 [ V_13 ] ) ;
}
}
static int F_7 ( struct V_14 * V_15 , T_1 V_16 , T_1 V_17 ,
void * V_18 , T_2 V_19 )
{
struct V_20 V_21 [ 2 ] ;
int V_22 ;
V_21 [ 0 ] . V_23 = V_16 ;
V_21 [ 0 ] . V_24 = 0 ;
V_21 [ 0 ] . V_19 = 1 ;
V_21 [ 0 ] . V_18 = & V_17 ;
V_21 [ 1 ] . V_23 = V_16 ;
V_21 [ 1 ] . V_24 = V_25 ;
V_21 [ 1 ] . V_19 = V_19 ;
V_21 [ 1 ] . V_18 = V_18 ;
V_22 = F_8 ( V_15 , V_21 , F_9 ( V_21 ) ) ;
if ( V_22 < 0 )
return V_22 ;
return V_22 == F_9 ( V_21 ) ? V_19 : 0 ;
}
static int F_10 ( struct V_1 * V_1 , bool V_26 , T_1 V_23 , void * V_18 ,
T_2 V_19 )
{
return F_7 ( V_1 -> V_15 , V_26 ? 0x51 : 0x50 , V_23 , V_18 , V_19 ) ;
}
static int F_11 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
struct V_27 * V_28 ;
int V_22 ;
if ( ! F_12 ( V_15 , V_29 ) )
return - V_30 ;
V_1 -> V_15 = V_15 ;
V_1 -> V_31 = F_10 ;
V_28 = F_13 ( V_1 -> V_32 , V_15 ) ;
if ( F_14 ( V_28 ) )
return F_15 ( V_28 ) ;
V_28 -> V_33 = L_1 ;
V_28 -> V_34 = ~ 0 ;
V_22 = F_16 ( V_28 ) ;
if ( V_22 < 0 ) {
F_17 ( V_28 ) ;
return V_22 ;
}
V_1 -> V_28 = V_28 ;
return 0 ;
}
static unsigned int F_18 ( struct V_1 * V_1 )
{
return V_1 -> V_35 ( V_1 ) ;
}
static void F_19 ( struct V_1 * V_1 , unsigned int V_3 )
{
V_1 -> V_36 ( V_1 , V_3 ) ;
}
static int F_20 ( struct V_1 * V_1 , bool V_26 , T_1 V_23 , void * V_18 , T_2 V_19 )
{
return V_1 -> V_31 ( V_1 , V_26 , V_23 , V_18 , V_19 ) ;
}
static unsigned int F_21 ( void * V_18 , T_2 V_19 )
{
T_1 * V_37 , V_38 ;
for ( V_37 = V_18 , V_38 = 0 ; V_19 ; V_37 ++ , V_19 -- )
V_38 += * V_37 ;
return V_38 ;
}
static void F_22 ( struct V_1 * V_1 )
{
F_23 ( V_1 -> V_32 , L_2 ,
V_1 -> V_3 & V_11 ? 1 : 0 , 1 ) ;
V_1 -> V_3 |= V_11 ;
F_19 ( V_1 , V_1 -> V_3 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
F_23 ( V_1 -> V_32 , L_2 ,
V_1 -> V_3 & V_11 ? 1 : 0 , 0 ) ;
V_1 -> V_3 &= ~ V_11 ;
F_19 ( V_1 , V_1 -> V_3 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
unsigned int V_3 = V_1 -> V_3 ;
if ( V_3 & V_11 )
return;
F_19 ( V_1 , V_3 | V_11 ) ;
F_26 ( V_39 ) ;
F_19 ( V_1 , V_3 ) ;
}
static void F_27 ( struct V_1 * V_1 , unsigned int V_40 )
{
if ( V_40 )
F_28 ( V_41 , & V_1 -> V_40 ,
V_40 ) ;
else
F_29 ( & V_1 -> V_40 ) ;
}
static void F_30 ( struct V_1 * V_1 , unsigned int V_3 ,
unsigned int V_40 )
{
V_1 -> V_42 = V_3 ;
F_27 ( V_1 , V_40 ) ;
}
static void F_31 ( struct V_1 * V_1 , unsigned int V_3 , unsigned int V_40 )
{
V_1 -> V_43 = V_3 ;
F_27 ( V_1 , V_40 ) ;
}
static void F_32 ( struct V_1 * V_1 )
{
F_33 ( V_1 -> V_44 ) ;
F_34 ( V_1 -> V_45 ) ;
F_35 ( V_1 -> V_44 ) ;
F_36 ( V_1 -> V_44 ) ;
V_1 -> V_44 = NULL ;
}
static void F_37 ( struct V_1 * V_1 )
{
struct V_46 * V_47 ;
int V_48 ;
F_38 ( V_49 ) ;
V_47 = F_39 ( V_1 -> V_28 , V_50 ) ;
if ( F_14 ( V_47 ) ) {
F_40 ( V_1 -> V_32 , L_3 , F_15 ( V_47 ) ) ;
return;
}
if ( ! V_47 ) {
F_41 ( V_1 -> V_32 , L_4 ) ;
return;
}
V_48 = F_42 ( V_1 -> V_45 , V_47 ) ;
if ( V_48 ) {
F_35 ( V_47 ) ;
F_36 ( V_47 ) ;
F_40 ( V_1 -> V_32 , L_5 , V_48 ) ;
return;
}
V_1 -> V_44 = V_47 ;
F_43 ( V_47 ) ;
}
static void F_44 ( struct V_1 * V_1 )
{
F_45 ( V_1 -> V_45 ) ;
F_30 ( V_1 , V_51 , 0 ) ;
}
static void F_46 ( struct V_1 * V_1 )
{
F_47 ( V_1 -> V_45 ) ;
}
static void F_48 ( struct V_1 * V_1 )
{
unsigned int V_52 = V_1 -> V_3 & V_53 ;
if ( V_1 -> V_54 . V_55 . V_56 & V_57 )
V_52 ^= V_53 ;
if ( V_52 )
F_30 ( V_1 , V_58 , 0 ) ;
else
F_44 ( V_1 ) ;
}
static void F_49 ( struct V_1 * V_1 , bool V_59 )
{
if ( V_1 -> V_60 && ! -- V_1 -> V_60 ) {
F_40 ( V_1 -> V_32 , L_6 ) ;
F_30 ( V_1 , V_61 , 0 ) ;
} else {
if ( V_59 )
F_40 ( V_1 -> V_32 , L_7 ) ;
F_30 ( V_1 , V_62 , V_63 ) ;
}
}
static void F_50 ( struct V_1 * V_1 )
{
F_24 ( V_1 ) ;
F_30 ( V_1 , V_64 , V_65 ) ;
V_1 -> V_60 = 5 ;
if ( V_1 -> V_54 . V_66 . V_67 ||
V_1 -> V_54 . V_66 . V_68 ||
V_1 -> V_54 . V_66 . V_69 )
F_37 ( V_1 ) ;
}
static int F_51 ( struct V_1 * V_1 )
{
struct V_70 V_54 ;
char V_71 [ 17 ] ;
char V_72 [ 17 ] ;
char V_73 [ 17 ] ;
char V_74 [ 9 ] ;
char V_75 [ 5 ] ;
T_1 V_38 ;
int V_48 ;
V_48 = F_20 ( V_1 , false , 0 , & V_54 , sizeof( V_54 ) ) ;
if ( V_48 < 0 ) {
F_40 ( V_1 -> V_32 , L_8 , V_48 ) ;
return - V_76 ;
}
if ( V_48 != sizeof( V_54 ) ) {
F_40 ( V_1 -> V_32 , L_9 , V_48 ) ;
return - V_76 ;
}
V_38 = F_21 ( & V_54 . V_66 , sizeof( V_54 . V_66 ) - 1 ) ;
if ( V_38 != V_54 . V_66 . V_77 ) {
F_40 ( V_1 -> V_32 ,
L_10 ,
V_38 ) ;
F_52 ( V_78 , L_11 , V_79 ,
16 , 1 , & V_54 , sizeof( V_54 . V_66 ) - 1 , true ) ;
return - V_30 ;
}
V_38 = F_21 ( & V_54 . V_55 , sizeof( V_54 . V_55 ) - 1 ) ;
if ( V_38 != V_54 . V_55 . V_80 ) {
F_40 ( V_1 -> V_32 ,
L_12 ,
V_38 ) ;
memset ( & V_54 . V_55 , 0 , sizeof( V_54 . V_55 ) ) ;
}
V_1 -> V_54 = V_54 ;
memcpy ( V_71 , V_1 -> V_54 . V_66 . V_81 , 16 ) ;
V_71 [ 16 ] = '\0' ;
memcpy ( V_72 , V_1 -> V_54 . V_66 . V_82 , 16 ) ;
V_72 [ 16 ] = '\0' ;
memcpy ( V_75 , V_1 -> V_54 . V_66 . V_83 , 4 ) ;
V_75 [ 4 ] = '\0' ;
memcpy ( V_73 , V_1 -> V_54 . V_55 . V_84 , 16 ) ;
V_73 [ 16 ] = '\0' ;
memcpy ( V_74 , V_1 -> V_54 . V_55 . V_85 , 8 ) ;
V_74 [ 8 ] = '\0' ;
F_41 ( V_1 -> V_32 , L_13 , V_71 , V_72 , V_75 , V_73 , V_74 ) ;
if ( V_1 -> V_54 . V_66 . V_86 != V_87 ||
V_1 -> V_54 . V_66 . V_88 != V_89 ) {
F_40 ( V_1 -> V_32 , L_14 ,
V_1 -> V_54 . V_66 . V_86 , V_1 -> V_54 . V_66 . V_88 ) ;
return - V_30 ;
}
return F_53 ( V_1 -> V_45 , & V_1 -> V_54 ) ;
}
static void F_54 ( struct V_1 * V_1 )
{
F_55 ( V_1 -> V_45 ) ;
if ( V_1 -> V_44 )
F_32 ( V_1 ) ;
F_22 ( V_1 ) ;
memset ( & V_1 -> V_54 , 0 , sizeof( V_1 -> V_54 ) ) ;
F_41 ( V_1 -> V_32 , L_15 ) ;
}
static void F_56 ( struct V_1 * V_1 , unsigned int V_90 )
{
F_57 ( & V_1 -> V_91 ) ;
F_23 ( V_1 -> V_32 , L_16 ,
V_1 -> V_43 , V_1 -> V_92 , V_1 -> V_42 , V_90 ) ;
switch ( V_1 -> V_43 ) {
default:
if ( V_90 == V_93 ) {
F_22 ( V_1 ) ;
F_31 ( V_1 , V_94 , V_95 ) ;
}
break;
case V_94 :
if ( V_90 == V_96 ) {
F_31 ( V_1 , V_97 , 0 ) ;
} else if ( V_90 == V_98 ) {
int V_48 = F_51 ( V_1 ) ;
if ( V_48 == 0 )
F_31 ( V_1 , V_99 , 0 ) ;
else if ( V_48 == - V_76 )
F_27 ( V_1 , V_100 ) ;
else
F_31 ( V_1 , V_101 , 0 ) ;
}
break;
case V_99 :
case V_101 :
if ( V_90 == V_96 ) {
F_54 ( V_1 ) ;
F_31 ( V_1 , V_97 , 0 ) ;
}
break;
}
switch ( V_1 -> V_92 ) {
default:
if ( V_90 == V_102 )
V_1 -> V_92 = V_103 ;
break;
case V_103 :
if ( V_90 == V_104 ) {
if ( ! V_1 -> V_44 )
F_22 ( V_1 ) ;
V_1 -> V_92 = V_105 ;
}
break;
}
if ( V_1 -> V_42 != V_106 &&
( V_1 -> V_43 != V_99 ||
V_1 -> V_92 != V_103 ) ) {
if ( V_1 -> V_42 == V_51 &&
V_1 -> V_92 == V_103 )
F_46 ( V_1 ) ;
if ( V_1 -> V_44 )
F_32 ( V_1 ) ;
F_30 ( V_1 , V_106 , 0 ) ;
F_58 ( & V_1 -> V_91 ) ;
return;
}
switch ( V_1 -> V_42 ) {
case V_106 :
if ( V_1 -> V_43 == V_99 &&
V_1 -> V_92 == V_103 )
F_50 ( V_1 ) ;
break;
case V_64 :
if ( V_90 == V_98 && V_1 -> V_3 & V_107 )
F_49 ( V_1 , true ) ;
else if ( V_90 == V_98 || V_90 == V_108 )
F_48 ( V_1 ) ;
break;
case V_58 :
if ( V_90 == V_109 )
F_49 ( V_1 , true ) ;
else if ( V_90 ==
( V_1 -> V_54 . V_55 . V_56 & V_57 ?
V_110 : V_111 ) )
F_44 ( V_1 ) ;
break;
case V_51 :
if ( V_90 == V_109 ) {
F_46 ( V_1 ) ;
F_49 ( V_1 , true ) ;
} else if ( V_90 ==
( V_1 -> V_54 . V_55 . V_56 & V_57 ?
V_111 : V_110 ) ) {
F_46 ( V_1 ) ;
F_30 ( V_1 , V_58 , 0 ) ;
}
break;
case V_62 :
if ( V_90 == V_98 ) {
F_25 ( V_1 ) ;
F_30 ( V_1 , V_112 , V_65 ) ;
}
break;
case V_112 :
if ( V_90 == V_98 && V_1 -> V_3 & V_107 ) {
F_49 ( V_1 , false ) ;
} else if ( V_90 == V_98 || V_90 == V_108 ) {
F_41 ( V_1 -> V_32 , L_17 ) ;
F_48 ( V_1 ) ;
}
break;
case V_61 :
break;
}
F_23 ( V_1 -> V_32 , L_18 ,
V_1 -> V_43 , V_1 -> V_92 , V_1 -> V_42 ) ;
F_58 ( & V_1 -> V_91 ) ;
}
static void F_59 ( struct V_1 * V_1 )
{
F_56 ( V_1 , V_102 ) ;
}
static void F_60 ( struct V_1 * V_1 )
{
F_56 ( V_1 , V_104 ) ;
}
static int F_61 ( struct V_1 * V_1 , struct V_113 * V_114 )
{
if ( V_1 -> V_54 . V_55 . V_115 ) {
V_114 -> type = V_116 ;
V_114 -> V_117 = V_118 ;
} else {
V_114 -> type = V_119 ;
V_114 -> V_117 = V_120 ;
}
return 0 ;
}
static int F_62 ( struct V_1 * V_1 , struct V_121 * V_122 ,
T_1 * V_123 )
{
unsigned int V_124 , V_125 , V_19 ;
int V_22 ;
if ( V_122 -> V_19 == 0 )
return - V_30 ;
V_124 = V_122 -> V_126 ;
V_125 = V_122 -> V_126 + V_122 -> V_19 ;
if ( V_124 < V_120 ) {
V_19 = F_63 (unsigned int, last, ETH_MODULE_SFF_8079_LEN) ;
V_19 -= V_124 ;
V_22 = V_1 -> V_31 ( V_1 , false , V_124 , V_123 , V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
V_124 += V_19 ;
V_123 += V_19 ;
}
if ( V_124 >= V_120 &&
V_124 < V_118 ) {
V_19 = F_63 (unsigned int, last, ETH_MODULE_SFF_8472_LEN) ;
V_19 -= V_124 ;
V_124 -= V_120 ;
V_22 = V_1 -> V_31 ( V_1 , true , V_124 , V_123 , V_19 ) ;
if ( V_22 < 0 )
return V_22 ;
}
return 0 ;
}
static void F_64 ( struct V_127 * V_128 )
{
struct V_1 * V_1 = F_65 ( V_128 , struct V_1 , V_40 . V_128 ) ;
F_66 () ;
F_56 ( V_1 , V_98 ) ;
F_67 () ;
}
static void F_68 ( struct V_1 * V_1 )
{
unsigned int V_3 , V_2 , V_129 ;
V_3 = F_18 ( V_1 ) ;
V_129 = V_3 ^ V_1 -> V_3 ;
V_129 &= V_9 | V_53 | V_107 ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ )
if ( V_129 & F_3 ( V_2 ) )
F_23 ( V_1 -> V_32 , L_19 , V_130 [ V_2 ] ,
! ! ( V_1 -> V_3 & F_3 ( V_2 ) ) , ! ! ( V_3 & F_3 ( V_2 ) ) ) ;
V_3 |= V_1 -> V_3 & ( V_11 | V_12 ) ;
V_1 -> V_3 = V_3 ;
F_66 () ;
if ( V_129 & V_9 )
F_56 ( V_1 , V_3 & V_9 ?
V_93 : V_96 ) ;
if ( V_129 & V_107 )
F_56 ( V_1 , V_3 & V_107 ?
V_109 : V_108 ) ;
if ( V_129 & V_53 )
F_56 ( V_1 , V_3 & V_53 ?
V_110 : V_111 ) ;
F_67 () ;
}
static T_3 F_69 ( int V_131 , void * V_123 )
{
struct V_1 * V_1 = V_123 ;
F_68 ( V_1 ) ;
return V_132 ;
}
static void F_70 ( struct V_127 * V_128 )
{
struct V_1 * V_1 = F_65 ( V_128 , struct V_1 , V_133 . V_128 ) ;
F_68 ( V_1 ) ;
F_28 ( V_134 , & V_1 -> V_133 , V_135 ) ;
}
static struct V_1 * F_71 ( struct V_136 * V_32 )
{
struct V_1 * V_1 ;
V_1 = F_72 ( sizeof( * V_1 ) , V_137 ) ;
if ( ! V_1 )
return F_73 ( - V_138 ) ;
V_1 -> V_32 = V_32 ;
F_74 ( & V_1 -> V_91 ) ;
F_75 ( & V_1 -> V_133 , F_70 ) ;
F_75 ( & V_1 -> V_40 , F_64 ) ;
return V_1 ;
}
static void F_76 ( void * V_123 )
{
struct V_1 * V_1 = V_123 ;
F_77 ( & V_1 -> V_133 ) ;
F_77 ( & V_1 -> V_40 ) ;
if ( V_1 -> V_28 ) {
F_78 ( V_1 -> V_28 ) ;
F_17 ( V_1 -> V_28 ) ;
}
if ( V_1 -> V_15 )
F_79 ( V_1 -> V_15 ) ;
F_80 ( V_1 ) ;
}
static int F_81 ( struct V_139 * V_140 )
{
struct V_1 * V_1 ;
bool V_133 = false ;
int V_131 , V_48 , V_2 ;
V_1 = F_71 ( & V_140 -> V_32 ) ;
if ( F_14 ( V_1 ) )
return F_15 ( V_1 ) ;
F_82 ( V_140 , V_1 ) ;
V_48 = F_83 ( V_1 -> V_32 , F_76 , V_1 ) ;
if ( V_48 < 0 )
return V_48 ;
if ( V_140 -> V_32 . V_141 ) {
struct V_142 * V_143 = V_140 -> V_32 . V_141 ;
struct V_142 * V_144 ;
V_144 = F_84 ( V_143 , L_20 , 0 ) ;
if ( V_144 ) {
struct V_14 * V_15 ;
V_15 = F_85 ( V_144 ) ;
F_86 ( V_144 ) ;
if ( ! V_15 )
return - V_145 ;
V_48 = F_11 ( V_1 , V_15 ) ;
if ( V_48 < 0 ) {
F_79 ( V_15 ) ;
return V_48 ;
}
}
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
V_1 -> V_8 [ V_2 ] = F_87 ( V_1 -> V_32 ,
V_130 [ V_2 ] , V_6 [ V_2 ] ) ;
if ( F_14 ( V_1 -> V_8 [ V_2 ] ) )
return F_15 ( V_1 -> V_8 [ V_2 ] ) ;
}
V_1 -> V_35 = F_1 ;
V_1 -> V_36 = F_4 ;
}
V_1 -> V_45 = F_88 ( V_1 -> V_32 , V_1 , & V_146 ) ;
if ( ! V_1 -> V_45 )
return - V_138 ;
V_1 -> V_3 = F_18 ( V_1 ) | V_11 ;
if ( V_1 -> V_8 [ V_13 ] &&
F_2 ( V_1 -> V_8 [ V_13 ] ) )
V_1 -> V_3 |= V_12 ;
F_19 ( V_1 , V_1 -> V_3 ) ;
F_22 ( V_1 ) ;
F_66 () ;
if ( V_1 -> V_3 & V_9 )
F_56 ( V_1 , V_93 ) ;
F_67 () ;
for ( V_2 = 0 ; V_2 < V_5 ; V_2 ++ ) {
if ( V_6 [ V_2 ] != V_7 || ! V_1 -> V_8 [ V_2 ] )
continue;
V_131 = F_89 ( V_1 -> V_8 [ V_2 ] ) ;
if ( ! V_131 ) {
V_133 = true ;
continue;
}
V_48 = F_90 ( V_1 -> V_32 , V_131 , NULL , F_69 ,
V_147 |
V_148 |
V_149 ,
F_91 ( V_1 -> V_32 ) , V_1 ) ;
if ( V_48 )
V_133 = true ;
}
if ( V_133 )
F_28 ( V_134 , & V_1 -> V_133 , V_135 ) ;
return 0 ;
}
static int F_92 ( struct V_139 * V_140 )
{
struct V_1 * V_1 = F_93 ( V_140 ) ;
F_94 ( V_1 -> V_45 ) ;
return 0 ;
}
static int F_95 ( void )
{
V_135 = F_96 ( 100 ) ;
return F_97 ( & V_150 ) ;
}
static void F_98 ( void )
{
F_99 ( & V_150 ) ;
}
