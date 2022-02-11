static void F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
memset ( & V_4 -> V_5 . V_6 , 0 , sizeof( struct V_7 ) ) ;
V_4 -> V_5 . V_6 . V_8 = V_2 -> V_9 . V_10 ;
V_4 -> V_5 . V_6 . V_11 = V_2 -> V_9 . V_12 ;
V_4 -> V_5 . V_6 . V_13 = V_14 ;
if ( V_2 -> V_15 == V_16 ) {
V_4 -> V_5 . V_6 . V_17 = V_16 ;
V_4 -> V_5 . V_6 . V_18 = ( V_4 -> V_5 . V_6 . V_8 * 3 ) / 2 ;
V_4 -> V_5 . V_6 . V_19 = V_4 -> V_5 . V_6 . V_11 * V_4 -> V_5 . V_6 . V_18 ;
} else {
V_4 -> V_5 . V_6 . V_18 = V_2 -> V_20 / 4 ;
V_4 -> V_5 . V_6 . V_19 = V_2 -> V_21 + sizeof( struct V_22 ) ;
if ( F_2 ( V_2 -> type ) )
V_4 -> V_5 . V_6 . V_17 = V_23 ;
else
V_4 -> V_5 . V_6 . V_17 = V_24 ;
}
F_3 ( L_1
L_2 ,
V_4 -> V_5 . V_6 . V_8 ,
V_4 -> V_5 . V_6 . V_11 ,
V_4 -> V_5 . V_6 . V_18 ,
V_4 -> V_5 . V_6 . V_19 ,
( V_4 -> V_5 . V_6 . V_17 ) & 255 ,
( V_4 -> V_5 . V_6 . V_17 >> 8 ) & 255 ,
( V_4 -> V_5 . V_6 . V_17 >> 16 ) & 255 ,
( V_4 -> V_5 . V_6 . V_17 >> 24 ) & 255 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> type != V_25 ) {
F_3 ( L_3 ) ;
return - V_26 ;
}
switch ( V_4 -> V_5 . V_6 . V_17 ) {
case V_16 :
break;
case V_23 :
if ( F_5 ( V_2 -> type ) ) {
F_3 ( L_4 ) ;
return - V_26 ;
}
break;
case V_24 :
if ( F_2 ( V_2 -> type ) ) {
F_3 ( L_5 ) ;
return - V_26 ;
}
break;
default:
F_3 ( L_6 ) ;
return - V_26 ;
}
if ( V_4 -> V_5 . V_6 . V_8 > V_2 -> V_27 . V_10 )
V_4 -> V_5 . V_6 . V_8 = V_2 -> V_27 . V_10 ;
else if ( V_4 -> V_5 . V_6 . V_8 < V_2 -> V_28 . V_10 )
V_4 -> V_5 . V_6 . V_8 = V_2 -> V_28 . V_10 ;
if ( V_4 -> V_5 . V_6 . V_11 > V_2 -> V_27 . V_12 )
V_4 -> V_5 . V_6 . V_11 = V_2 -> V_27 . V_12 ;
else if ( V_4 -> V_5 . V_6 . V_11 < V_2 -> V_28 . V_12 )
V_4 -> V_5 . V_6 . V_11 = V_2 -> V_28 . V_12 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_29 , V_30 , V_31 , V_32 , V_17 ;
V_29 = F_4 ( V_2 , V_4 ) ;
if ( V_29 < 0 )
return V_29 ;
V_17 = V_4 -> V_5 . V_6 . V_17 ;
V_32 = V_2 -> V_33 ;
V_31 = 0 ;
V_30 = V_2 -> V_34 ;
if ( V_4 -> V_5 . V_6 . V_35 ) {
V_32 = ( V_4 -> V_5 . V_6 . V_35 & V_36 ) >> V_37 ;
V_31 = ! ! ( V_4 -> V_5 . V_6 . V_35 & V_38 ) ;
V_30 = ( V_4 -> V_5 . V_6 . V_35 & V_39 ) >> V_40 ;
if ( V_30 == 0 )
V_30 = V_2 -> V_34 ;
}
if ( V_17 != V_16 &&
V_17 != V_23 &&
V_17 != V_24 )
return - V_26 ;
if ( V_2 -> V_41 )
return - V_42 ;
F_3 ( L_7
L_8 ,
V_4 -> V_5 . V_6 . V_8 , V_4 -> V_5 . V_6 . V_11 , V_30 ,
V_32 , V_31 ,
( V_17 ) & 255 ,
( V_17 >> 8 ) & 255 ,
( V_17 >> 16 ) & 255 ,
( V_17 >> 24 ) & 255 ) ;
V_29 = F_7 ( V_2 ,
V_4 -> V_5 . V_6 . V_8 ,
V_4 -> V_5 . V_6 . V_11 ,
V_30 ,
V_32 ,
V_31 ) ;
F_3 ( L_9 , V_29 ) ;
if ( V_29 )
return V_29 ;
V_2 -> V_15 = V_17 ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_43 * V_43 , void * V_44 , struct V_45 * V_46 )
{
struct V_47 * V_48 = F_9 ( V_43 ) ;
struct V_1 * V_2 = F_10 ( V_43 ) ;
strcpy ( V_46 -> V_49 , V_50 ) ;
F_11 ( V_46 -> V_51 , V_48 -> V_52 , sizeof( V_46 -> V_51 ) ) ;
F_12 ( V_2 -> V_53 , V_46 -> V_54 , sizeof( V_46 -> V_54 ) ) ;
V_46 -> V_55 = V_56 ;
V_46 -> V_57 =
V_58 |
V_59 |
V_60 ;
return 0 ;
}
static int F_13 ( struct V_43 * V_43 , void * V_44 , struct V_61 * V_62 )
{
if ( V_62 -> V_63 )
return - V_26 ;
strcpy ( V_62 -> V_52 , L_10 ) ;
return 0 ;
}
static int F_14 ( struct V_43 * V_43 , void * V_44 , unsigned int * V_62 )
{
* V_62 = 0 ;
return 0 ;
}
static int F_15 ( struct V_43 * V_43 , void * V_44 , unsigned int V_62 )
{
return V_62 ? - V_26 : 0 ;
}
static int F_16 ( struct V_43 * V_43 , void * V_44 , struct V_64 * V_65 )
{
int V_62 , V_66 ;
T_1 V_67 ;
V_67 = V_65 -> V_67 ;
if ( V_67 & V_68 ) {
V_67 &= V_69 ;
V_67 ++ ;
V_66 = - 1 ;
for ( V_62 = 0 ; V_62 < F_17 ( V_70 ) ; V_62 ++ ) {
if ( V_70 [ V_62 ] . V_67 < V_67 )
continue;
if ( V_66 >= 0
&& V_70 [ V_62 ] . V_67 > V_70 [ V_66 ] . V_67 )
continue;
V_66 = V_62 ;
}
if ( V_66 < 0 )
return - V_26 ;
memcpy ( V_65 , & V_70 [ V_66 ] , sizeof V_70 [ 0 ] ) ;
return 0 ;
}
for ( V_62 = 0 ; V_62 < sizeof( V_70 ) / sizeof( struct V_64 ) ; V_62 ++ ) {
if ( V_70 [ V_62 ] . V_67 == V_65 -> V_67 ) {
F_3 ( L_11 ) ;
memcpy ( V_65 , & V_70 [ V_62 ] , sizeof( struct V_64 ) ) ;
return 0 ;
}
}
return - V_26 ;
}
static int F_18 ( struct V_43 * V_43 , void * V_44 , struct V_71 * V_65 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
int V_29 ;
switch ( V_65 -> V_67 ) {
case V_72 :
V_65 -> V_73 = F_19 ( V_2 ) ;
if ( V_65 -> V_73 < 0 )
return - V_26 ;
return 0 ;
case V_74 :
V_65 -> V_73 = F_20 ( V_2 ) ;
if ( V_65 -> V_73 < 0 )
return - V_26 ;
return 0 ;
case V_75 :
V_29 = F_21 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_76 :
V_65 -> V_73 = F_22 ( V_2 ) ;
if ( V_65 -> V_73 < 0 )
return - V_26 ;
return 0 ;
case V_77 :
V_29 = F_23 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 >>= 8 ;
return 0 ;
case V_78 :
V_29 = F_24 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 >>= 8 ;
return 0 ;
case V_79 :
V_29 = F_25 ( V_2 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 = ( V_29 == V_80 ) ? 0 : 1 ;
return 0 ;
case V_81 :
V_29 = F_26 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 >>= 8 ;
return 0 ;
case V_82 :
V_29 = F_26 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 = ( V_65 -> V_73 < 0 ) ? 1 : 0 ;
return 0 ;
case V_83 :
V_29 = F_27 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_84 :
V_29 = F_28 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_85 :
V_29 = F_29 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 = ( V_65 -> V_73 == - 1 ? 1 : 0 ) ;
return 0 ;
case V_86 :
V_29 = F_29 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 >>= 10 ;
return 0 ;
case V_87 :
V_29 = F_30 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_88 :
V_29 = F_31 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
V_65 -> V_73 = ( V_65 -> V_73 ? 1 : 0 ) ;
return 0 ;
case V_89 :
V_29 = F_32 ( V_2 , & V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_90 :
case V_91 :
case V_92 :
return - V_26 ;
}
return - V_26 ;
}
static int F_33 ( struct V_43 * V_43 , void * V_44 , struct V_71 * V_65 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
int V_29 ;
switch ( V_65 -> V_67 ) {
case V_72 :
V_65 -> V_73 <<= 9 ;
V_29 = F_34 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_74 :
V_65 -> V_73 <<= 10 ;
V_29 = F_35 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_75 :
V_29 = F_36 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_76 :
V_65 -> V_73 <<= 11 ;
V_29 = F_37 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_77 :
V_65 -> V_73 <<= 8 ;
V_29 = F_38 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_78 :
V_65 -> V_73 <<= 8 ;
V_29 = F_39 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_79 :
V_65 -> V_73 = ( V_65 -> V_73 == 0 ) ? V_80 : V_93 ;
V_29 = F_40 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_83 :
V_65 -> V_73 <<= 8 ;
V_29 = F_41 ( V_2 , V_65 -> V_73 ? 0 : 1 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_82 :
if ( V_65 -> V_73 == 0 )
return 0 ;
V_29 = F_42 ( V_2 , V_65 -> V_73 , 0 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_81 :
V_65 -> V_73 <<= 8 ;
V_29 = F_42 ( V_2 , 0 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_90 :
if ( F_43 ( V_2 ) )
return - V_26 ;
return 0 ;
case V_91 :
if ( F_44 ( V_2 ) )
return - V_26 ;
return 0 ;
case V_92 :
if ( F_45 ( V_2 ) )
return - V_26 ;
return 0 ;
case V_84 :
V_29 = F_46 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_85 :
V_65 -> V_73 = ( V_65 -> V_73 == 1 ) ? - 1 : 0 ;
V_29 = F_47 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_86 :
V_65 -> V_73 <<= 10 ;
V_29 = F_47 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_87 :
V_29 = F_48 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
case V_88 :
V_29 = F_49 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
case V_89 :
V_29 = F_50 ( V_2 , V_65 -> V_73 ) ;
if ( V_29 < 0 )
return - V_26 ;
return 0 ;
}
return - V_26 ;
}
static int F_51 ( struct V_43 * V_43 , void * V_44 , struct V_94 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
switch ( V_4 -> V_63 ) {
case 0 :
V_4 -> V_17 = V_2 -> type <= 646 ? V_23 : V_24 ;
V_4 -> V_95 = V_96 ;
F_11 ( V_4 -> V_97 , L_12 , sizeof( V_4 -> V_97 ) ) ;
break;
case 1 :
V_4 -> V_17 = V_16 ;
F_11 ( V_4 -> V_97 , L_13 , sizeof( V_4 -> V_97 ) ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_52 ( struct V_43 * V_43 , void * V_44 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
F_3 ( L_14 ,
V_2 -> V_98 . V_10 , V_2 -> V_98 . V_12 ) ;
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_53 ( struct V_43 * V_43 , void * V_44 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
return F_4 ( V_2 , V_4 ) ;
}
static int F_54 ( struct V_43 * V_43 , void * V_44 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
return F_6 ( V_2 , V_4 ) ;
}
static int F_55 ( struct V_43 * V_43 , void * V_44 , struct V_99 * V_100 )
{
int V_101 ;
F_3 ( L_15 , V_100 -> V_102 ) ;
if ( V_100 -> type != V_25 )
return - V_26 ;
if ( V_100 -> V_103 != V_104 )
return - V_26 ;
V_101 = V_100 -> V_102 ;
if ( V_101 < 2 )
V_101 = 2 ;
else if ( V_101 > V_105 )
V_101 = V_105 ;
V_100 -> V_102 = V_105 ;
return 0 ;
}
static int F_56 ( struct V_43 * V_43 , void * V_44 , struct V_106 * V_107 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
int V_63 ;
F_3 ( L_16 , V_107 -> V_63 ) ;
if ( V_107 -> type != V_25 ) {
F_3 ( L_17 ) ;
return - V_26 ;
}
V_63 = V_107 -> V_63 ;
if ( V_63 < 0 || V_63 >= V_105 ) {
F_3 ( L_18 , V_107 -> V_63 ) ;
return - V_26 ;
}
V_107 -> V_108 . V_109 = V_63 * V_2 -> V_110 ;
if ( V_2 -> V_15 != V_16 )
V_107 -> V_111 = V_2 -> V_21 + sizeof( struct V_22 ) ;
else
V_107 -> V_111 = V_2 -> V_9 . V_112 ;
V_107 -> V_13 = V_14 ;
V_107 -> V_103 = V_104 ;
V_107 -> V_113 = V_2 -> V_110 ;
F_57 ( L_19 , V_107 -> V_63 ) ;
F_57 ( L_20 , V_107 -> V_108 . V_109 ) ;
F_57 ( L_21 , V_107 -> V_111 ) ;
return 0 ;
}
static int F_58 ( struct V_43 * V_43 , void * V_44 , struct V_106 * V_107 )
{
F_3 ( L_22 , V_107 -> V_63 ) ;
if ( V_107 -> type != V_25 )
return - V_26 ;
if ( V_107 -> V_103 != V_104 )
return - V_26 ;
if ( V_107 -> V_63 >= V_105 )
return - V_26 ;
V_107 -> V_95 |= V_114 ;
V_107 -> V_95 &= ~ V_115 ;
return 0 ;
}
static int F_59 ( struct V_43 * V_43 , void * V_44 , struct V_106 * V_107 )
{
F_60 ( V_116 , V_117 ) ;
struct V_1 * V_2 = F_10 ( V_43 ) ;
int V_29 ;
F_3 ( L_23 ) ;
if ( V_107 -> type != V_25 )
return - V_26 ;
F_61 ( & V_2 -> V_118 , & V_116 ) ;
while ( V_2 -> V_119 == NULL ) {
if ( V_2 -> V_120 ) {
F_62 ( & V_2 -> V_118 , & V_116 ) ;
F_63 ( V_121 ) ;
return - V_2 -> V_120 ;
}
if ( F_64 ( V_117 ) ) {
F_62 ( & V_2 -> V_118 , & V_116 ) ;
F_63 ( V_121 ) ;
return - V_122 ;
}
F_65 ( & V_2 -> V_123 ) ;
F_66 () ;
F_63 ( V_124 ) ;
F_67 ( & V_2 -> V_123 ) ;
}
F_62 ( & V_2 -> V_118 , & V_116 ) ;
F_63 ( V_121 ) ;
F_3 ( L_24 ) ;
V_29 = F_68 ( V_2 ) ;
if ( V_29 )
return - V_125 ;
F_3 ( L_25 ) ;
V_107 -> V_63 = V_2 -> V_126 ;
if ( V_2 -> V_15 != V_16 )
V_107 -> V_111 = V_2 -> V_21 + sizeof( struct V_22 ) ;
else
V_107 -> V_111 = V_2 -> V_9 . V_112 ;
V_107 -> V_95 = V_127 ;
V_107 -> V_13 = V_14 ;
F_69 ( & V_107 -> V_128 ) ;
V_107 -> V_129 = 0 ;
V_107 -> V_103 = V_104 ;
V_107 -> V_108 . V_109 = V_2 -> V_126 * V_2 -> V_110 ;
V_107 -> V_113 = V_2 -> V_110 ;
F_70 ( V_2 ) ;
F_3 ( L_26 , V_107 -> V_63 ) ;
F_3 ( L_27 , V_107 -> V_113 ) ;
F_3 ( L_28 , V_107 -> V_108 . V_109 ) ;
F_3 ( L_29 , V_107 -> V_111 ) ;
F_3 ( L_30 ) ;
return 0 ;
}
static int F_71 ( struct V_43 * V_43 , void * V_44 , enum V_130 V_62 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
return F_72 ( V_2 ) ;
}
static int F_73 ( struct V_43 * V_43 , void * V_44 , enum V_130 V_62 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
F_74 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_43 * V_43 , void * V_44 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
unsigned int V_62 = 0 , V_63 = V_132 -> V_63 ;
if ( V_132 -> V_133 == V_16 ) {
for ( V_62 = 0 ; V_62 < V_134 ; V_62 ++ ) {
if ( V_2 -> V_135 & ( 1UL << V_62 ) ) {
if ( ! V_63 -- ) {
V_132 -> type = V_136 ;
V_132 -> V_137 . V_8 = V_138 [ V_62 ] . V_10 ;
V_132 -> V_137 . V_11 = V_138 [ V_62 ] . V_12 ;
return 0 ;
}
}
}
} else if ( V_132 -> V_63 == 0 &&
( ( V_132 -> V_133 == V_23 && F_2 ( V_2 -> type ) ) ||
( V_132 -> V_133 == V_24 && F_5 ( V_2 -> type ) ) ) ) {
V_132 -> type = V_136 ;
V_132 -> V_137 . V_8 = V_2 -> V_139 . V_10 ;
V_132 -> V_137 . V_11 = V_2 -> V_139 . V_12 ;
return 0 ;
}
return - V_26 ;
}
static int F_76 ( struct V_43 * V_43 , void * V_44 ,
struct V_140 * V_141 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
int V_112 = - 1 ;
unsigned int V_62 ;
for ( V_62 = 0 ; V_62 < V_134 ; V_62 ++ ) {
if ( V_138 [ V_62 ] . V_10 == V_141 -> V_8 &&
V_138 [ V_62 ] . V_12 == V_141 -> V_11 ) {
V_112 = V_62 ;
break;
}
}
if ( V_112 < 0 || V_141 -> V_133 != V_16 )
return - V_26 ;
V_62 = F_77 ( V_2 , V_141 -> V_63 , V_112 ) ;
if ( ! V_62 )
return - V_26 ;
V_141 -> type = V_142 ;
V_141 -> V_137 . V_143 = 1 ;
V_141 -> V_137 . V_144 = V_62 ;
return 0 ;
}
static long F_78 ( struct V_43 * V_43 , void * V_44 , bool V_145 ,
int V_146 , void * V_147 )
{
struct V_1 * V_2 = F_10 ( V_43 ) ;
return F_79 ( V_2 , V_146 , V_147 ) ;
}
