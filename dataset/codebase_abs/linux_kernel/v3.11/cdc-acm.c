static struct V_1 * F_1 ( unsigned V_2 )
{
struct V_1 * V_1 ;
F_2 ( & V_3 ) ;
V_1 = V_4 [ V_2 ] ;
if ( V_1 ) {
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 ) {
F_3 ( & V_1 -> V_5 ) ;
V_1 = NULL ;
} else {
F_4 ( & V_1 -> V_7 ) ;
F_3 ( & V_1 -> V_5 ) ;
}
}
F_3 ( & V_3 ) ;
return V_1 ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_8 ;
F_2 ( & V_3 ) ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
if ( ! V_4 [ V_8 ] ) {
V_4 [ V_8 ] = V_1 ;
break;
}
}
F_3 ( & V_3 ) ;
return V_8 ;
}
static void F_6 ( struct V_1 * V_1 )
{
F_2 ( & V_3 ) ;
V_4 [ V_1 -> V_8 ] = NULL ;
F_3 ( & V_3 ) ;
}
static int F_7 ( struct V_1 * V_1 , int V_10 , int V_11 ,
void * V_12 , int V_13 )
{
int V_14 = F_8 ( V_1 -> V_15 , F_9 ( V_1 -> V_15 , 0 ) ,
V_10 , V_16 , V_11 ,
V_1 -> V_17 -> V_18 [ 0 ] . V_19 . V_20 ,
V_12 , V_13 , 5000 ) ;
F_10 ( & V_1 -> V_17 -> V_15 ,
L_1 ,
V_21 , V_10 , V_11 , V_13 , V_14 ) ;
return V_14 < 0 ? V_14 : 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_22 , V_23 ;
struct V_24 * V_25 ;
V_23 = 0 ;
V_22 = 0 ;
for (; ; ) {
V_25 = & V_1 -> V_25 [ V_23 ] ;
if ( ! V_25 -> V_26 ) {
V_25 -> V_26 = 1 ;
return V_23 ;
}
V_23 = ( V_23 + 1 ) % V_27 ;
if ( ++ V_22 >= V_27 )
return - 1 ;
}
}
static int F_12 ( struct V_1 * V_1 )
{
int V_22 , V_28 ;
unsigned long V_29 ;
V_28 = V_27 ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
V_28 -= V_1 -> V_25 [ V_22 ] . V_26 ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
return V_28 ;
}
static void F_15 ( struct V_1 * V_1 , struct V_24 * V_25 )
{
V_25 -> V_26 = 0 ;
V_1 -> V_31 -- ;
F_16 ( V_1 -> V_17 ) ;
}
static int F_17 ( struct V_1 * V_1 , struct V_24 * V_25 )
{
int V_32 ;
V_1 -> V_31 ++ ;
V_25 -> V_33 -> V_34 = V_25 -> V_12 ;
V_25 -> V_33 -> V_35 = V_25 -> V_36 ;
V_25 -> V_33 -> V_37 = V_25 -> V_13 ;
V_25 -> V_33 -> V_15 = V_1 -> V_15 ;
V_32 = F_18 ( V_25 -> V_33 , V_38 ) ;
if ( V_32 < 0 ) {
F_19 ( & V_1 -> V_39 -> V_15 ,
L_2 ,
V_21 , V_32 ) ;
F_15 ( V_1 , V_25 ) ;
}
return V_32 ;
}
static T_1 F_20
( struct V_40 * V_15 , struct V_41 * V_42 , char * V_12 )
{
struct V_43 * V_44 = F_21 ( V_15 ) ;
struct V_1 * V_1 = F_22 ( V_44 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_45 ) ;
}
static T_1 F_23
( struct V_40 * V_15 , struct V_41 * V_42 , char * V_12 )
{
struct V_43 * V_44 = F_21 ( V_15 ) ;
struct V_1 * V_1 = F_22 ( V_44 ) ;
memcpy ( V_12 , V_1 -> V_46 , V_1 -> V_47 ) ;
return V_1 -> V_47 ;
}
static T_1 F_24
( struct V_40 * V_15 , struct V_41 * V_42 , char * V_12 )
{
struct V_43 * V_44 = F_21 ( V_15 ) ;
struct V_1 * V_1 = F_22 ( V_44 ) ;
return sprintf ( V_12 , L_3 , V_1 -> V_48 ) ;
}
static void F_25 ( struct V_33 * V_33 )
{
struct V_1 * V_1 = V_33 -> V_49 ;
struct V_50 * V_51 = V_33 -> V_34 ;
unsigned char * V_39 ;
int V_52 ;
int V_14 ;
int V_53 = V_33 -> V_53 ;
switch ( V_53 ) {
case 0 :
break;
case - V_54 :
case - V_55 :
case - V_56 :
F_10 ( & V_1 -> V_17 -> V_15 ,
L_4 ,
V_21 , V_53 ) ;
return;
default:
F_10 ( & V_1 -> V_17 -> V_15 ,
L_5 ,
V_21 , V_53 ) ;
goto exit;
}
F_26 ( V_1 -> V_15 ) ;
V_39 = ( unsigned char * ) ( V_51 + 1 ) ;
switch ( V_51 -> V_57 ) {
case V_58 :
F_10 ( & V_1 -> V_17 -> V_15 , L_6 ,
V_21 , V_51 -> V_59 ) ;
break;
case V_60 :
V_52 = F_27 ( V_39 ) ;
if ( ! V_1 -> V_61 && ( V_1 -> V_62 & ~ V_52 & V_63 ) ) {
F_10 ( & V_1 -> V_17 -> V_15 , L_7 ,
V_21 ) ;
F_28 ( & V_1 -> V_7 , false ) ;
}
V_1 -> V_62 = V_52 ;
F_10 ( & V_1 -> V_17 -> V_15 ,
L_8
L_9 ,
V_21 ,
V_1 -> V_62 & V_63 ? '+' : '-' ,
V_1 -> V_62 & V_64 ? '+' : '-' ,
V_1 -> V_62 & V_65 ? '+' : '-' ,
V_1 -> V_62 & V_66 ? '+' : '-' ,
V_1 -> V_62 & V_67 ? '+' : '-' ,
V_1 -> V_62 & V_68 ? '+' : '-' ,
V_1 -> V_62 & V_69 ? '+' : '-' ) ;
break;
default:
F_10 ( & V_1 -> V_17 -> V_15 ,
L_10
L_11 ,
V_21 ,
V_51 -> V_57 , V_51 -> V_70 ,
V_51 -> V_71 , V_39 [ 0 ] , V_39 [ 1 ] ) ;
break;
}
exit:
V_14 = F_18 ( V_33 , V_38 ) ;
if ( V_14 )
F_19 ( & V_1 -> V_17 -> V_15 , L_12 ,
V_21 , V_14 ) ;
}
static int F_29 ( struct V_1 * V_1 , int V_2 , T_2 V_72 )
{
int V_73 ;
if ( ! F_30 ( V_2 , & V_1 -> V_74 ) )
return 0 ;
F_31 ( & V_1 -> V_39 -> V_15 , L_13 , V_21 , V_2 ) ;
V_73 = F_18 ( V_1 -> V_75 [ V_2 ] , V_72 ) ;
if ( V_73 ) {
if ( V_73 != - V_76 ) {
F_19 ( & V_1 -> V_39 -> V_15 ,
L_12 ,
V_21 , V_73 ) ;
}
F_32 ( V_2 , & V_1 -> V_74 ) ;
return V_73 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , T_2 V_72 )
{
int V_73 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_77 ; ++ V_22 ) {
V_73 = F_29 ( V_1 , V_22 , V_72 ) ;
if ( V_73 )
return V_73 ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_1 , struct V_33 * V_33 )
{
if ( ! V_33 -> V_78 )
return;
F_35 ( & V_1 -> V_7 , V_33 -> V_34 ,
V_33 -> V_78 ) ;
F_36 ( & V_1 -> V_7 ) ;
}
static void F_37 ( struct V_33 * V_33 )
{
struct V_79 * V_80 = V_33 -> V_49 ;
struct V_1 * V_1 = V_80 -> V_81 ;
unsigned long V_29 ;
F_31 ( & V_1 -> V_39 -> V_15 , L_14 , V_21 ,
V_80 -> V_2 , V_33 -> V_78 ) ;
F_32 ( V_80 -> V_2 , & V_1 -> V_74 ) ;
if ( ! V_1 -> V_15 ) {
F_10 ( & V_1 -> V_39 -> V_15 , L_15 , V_21 ) ;
return;
}
F_26 ( V_1 -> V_15 ) ;
if ( V_33 -> V_53 ) {
F_10 ( & V_1 -> V_39 -> V_15 , L_16 ,
V_21 , V_33 -> V_53 ) ;
return;
}
F_34 ( V_1 , V_33 ) ;
F_13 ( & V_1 -> V_82 , V_29 ) ;
V_1 -> V_83 = V_1 -> V_84 ;
if ( ! V_1 -> V_83 && ! V_1 -> V_85 ) {
F_14 ( & V_1 -> V_82 , V_29 ) ;
F_29 ( V_1 , V_80 -> V_2 , V_38 ) ;
} else {
F_14 ( & V_1 -> V_82 , V_29 ) ;
}
}
static void F_38 ( struct V_33 * V_33 )
{
struct V_24 * V_25 = V_33 -> V_49 ;
struct V_1 * V_1 = V_25 -> V_81 ;
unsigned long V_29 ;
if ( V_33 -> V_53 || ( V_33 -> V_78 != V_33 -> V_37 ) )
F_31 ( & V_1 -> V_39 -> V_15 , L_17 ,
V_21 ,
V_33 -> V_78 ,
V_33 -> V_37 ,
V_33 -> V_53 ) ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
F_15 ( V_1 , V_25 ) ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
F_39 ( & V_1 -> V_86 ) ;
}
static void F_40 ( struct V_87 * V_86 )
{
struct V_1 * V_1 = F_41 ( V_86 , struct V_1 , V_86 ) ;
F_31 ( & V_1 -> V_39 -> V_15 , L_18 , V_21 ) ;
F_42 ( & V_1 -> V_7 ) ;
}
static int F_43 ( struct V_88 * V_89 , struct V_90 * V_91 )
{
struct V_1 * V_1 ;
int V_14 ;
F_10 ( V_91 -> V_15 , L_18 , V_21 ) ;
V_1 = F_1 ( V_91 -> V_2 ) ;
if ( ! V_1 )
return - V_92 ;
V_14 = F_44 ( V_89 , V_91 ) ;
if ( V_14 )
goto V_93;
V_91 -> V_94 = V_1 ;
return 0 ;
V_93:
F_45 ( & V_1 -> V_7 ) ;
return V_14 ;
}
static int F_46 ( struct V_90 * V_91 , struct V_95 * V_96 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
F_10 ( V_91 -> V_15 , L_18 , V_21 ) ;
return F_47 ( & V_1 -> V_7 , V_91 , V_96 ) ;
}
static int F_48 ( struct V_97 * V_7 , struct V_90 * V_91 )
{
struct V_1 * V_1 = F_41 ( V_7 , struct V_1 , V_7 ) ;
int V_14 = - V_92 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_18 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 )
goto V_6;
V_14 = F_49 ( V_1 -> V_17 ) ;
if ( V_14 )
goto V_98;
F_32 ( V_99 , & V_91 -> V_29 ) ;
V_1 -> V_17 -> V_100 = 1 ;
V_1 -> V_101 -> V_15 = V_1 -> V_15 ;
if ( F_18 ( V_1 -> V_101 , V_102 ) ) {
F_19 ( & V_1 -> V_17 -> V_15 ,
L_19 , V_21 ) ;
goto V_103;
}
V_1 -> V_104 = V_105 | V_106 ;
if ( F_50 ( V_1 , V_1 -> V_104 ) < 0 &&
( V_1 -> V_45 & V_107 ) )
goto V_108;
F_51 ( V_1 -> V_17 ) ;
F_52 ( & V_1 -> V_82 ) ;
V_1 -> V_83 = 0 ;
V_1 -> V_84 = 0 ;
F_53 ( & V_1 -> V_82 ) ;
if ( F_33 ( V_1 , V_102 ) )
goto V_109;
F_3 ( & V_1 -> V_5 ) ;
return 0 ;
V_109:
V_1 -> V_104 = 0 ;
F_50 ( V_1 , V_1 -> V_104 ) ;
V_108:
F_54 ( V_1 -> V_101 ) ;
V_103:
F_51 ( V_1 -> V_17 ) ;
V_98:
V_6:
F_3 ( & V_1 -> V_5 ) ;
return V_14 ;
}
static void F_55 ( struct V_97 * V_7 )
{
struct V_1 * V_1 = F_41 ( V_7 , struct V_1 , V_7 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_18 , V_21 ) ;
F_6 ( V_1 ) ;
F_56 ( V_1 -> V_17 ) ;
F_57 ( V_1 -> V_46 ) ;
F_57 ( V_1 ) ;
}
static void F_58 ( struct V_97 * V_7 )
{
struct V_1 * V_1 = F_41 ( V_7 , struct V_1 , V_7 ) ;
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_18 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( ! V_1 -> V_6 ) {
F_49 ( V_1 -> V_17 ) ;
F_50 ( V_1 , V_1 -> V_104 = 0 ) ;
F_54 ( V_1 -> V_101 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_54 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_77 ; V_22 ++ )
F_54 ( V_1 -> V_75 [ V_22 ] ) ;
V_1 -> V_17 -> V_100 = 0 ;
F_51 ( V_1 -> V_17 ) ;
}
F_3 ( & V_1 -> V_5 ) ;
}
static void F_59 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_18 , V_21 ) ;
F_45 ( & V_1 -> V_7 ) ;
}
static void F_60 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_18 , V_21 ) ;
F_61 ( & V_1 -> V_7 ) ;
}
static void F_62 ( struct V_90 * V_91 , struct V_95 * V_96 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_18 , V_21 ) ;
F_63 ( & V_1 -> V_7 , V_91 , V_96 ) ;
}
static int F_64 ( struct V_90 * V_91 ,
const unsigned char * V_12 , int V_110 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
int V_111 ;
unsigned long V_29 ;
int V_23 ;
struct V_24 * V_25 ;
if ( ! V_110 )
return 0 ;
F_31 ( & V_1 -> V_39 -> V_15 , L_20 , V_21 , V_110 ) ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
V_23 = F_11 ( V_1 ) ;
if ( V_23 < 0 ) {
F_14 ( & V_1 -> V_30 , V_29 ) ;
return 0 ;
}
V_25 = & V_1 -> V_25 [ V_23 ] ;
if ( ! V_1 -> V_15 ) {
V_25 -> V_26 = 0 ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
return - V_92 ;
}
V_110 = ( V_110 > V_1 -> V_112 ) ? V_1 -> V_112 : V_110 ;
F_31 ( & V_1 -> V_39 -> V_15 , L_21 , V_21 , V_110 ) ;
memcpy ( V_25 -> V_12 , V_12 , V_110 ) ;
V_25 -> V_13 = V_110 ;
F_65 ( V_1 -> V_17 ) ;
if ( V_1 -> V_85 ) {
if ( ! V_1 -> V_113 )
V_1 -> V_113 = V_25 ;
else
F_16 ( V_1 -> V_17 ) ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
return V_110 ;
}
F_26 ( V_1 -> V_15 ) ;
V_111 = F_17 ( V_1 , V_25 ) ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
if ( V_111 < 0 )
return V_111 ;
return V_110 ;
}
static int F_66 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
return F_12 ( V_1 ) ? V_1 -> V_112 : 0 ;
}
static int F_67 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
if ( V_1 -> V_6 )
return 0 ;
return ( V_27 - F_12 ( V_1 ) ) * V_1 -> V_112 ;
}
static void F_68 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
F_52 ( & V_1 -> V_82 ) ;
V_1 -> V_84 = 1 ;
F_53 ( & V_1 -> V_82 ) ;
}
static void F_69 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
unsigned int V_114 ;
F_52 ( & V_1 -> V_82 ) ;
V_114 = V_1 -> V_83 ;
V_1 -> V_83 = 0 ;
V_1 -> V_84 = 0 ;
F_53 ( & V_1 -> V_82 ) ;
if ( V_114 )
F_33 ( V_1 , V_102 ) ;
}
static int F_70 ( struct V_90 * V_91 , int V_115 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
int V_14 ;
V_14 = F_71 ( V_1 , V_115 ? 0xffff : 0 ) ;
if ( V_14 < 0 )
F_10 ( & V_1 -> V_17 -> V_15 , L_22 ,
V_21 ) ;
return V_14 ;
}
static int F_72 ( struct V_90 * V_91 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
return ( V_1 -> V_104 & V_105 ? V_116 : 0 ) |
( V_1 -> V_104 & V_106 ? V_117 : 0 ) |
( V_1 -> V_62 & V_64 ? V_118 : 0 ) |
( V_1 -> V_62 & V_66 ? V_119 : 0 ) |
( V_1 -> V_62 & V_63 ? V_120 : 0 ) |
V_121 ;
}
static int F_73 ( struct V_90 * V_91 ,
unsigned int V_122 , unsigned int V_123 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
unsigned int V_52 ;
V_52 = V_1 -> V_104 ;
V_122 = ( V_122 & V_116 ? V_105 : 0 ) |
( V_122 & V_117 ? V_106 : 0 ) ;
V_123 = ( V_123 & V_116 ? V_105 : 0 ) |
( V_123 & V_117 ? V_106 : 0 ) ;
V_52 = ( V_52 & ~ V_123 ) | V_122 ;
if ( V_1 -> V_104 == V_52 )
return 0 ;
return F_50 ( V_1 , V_1 -> V_104 = V_52 ) ;
}
static int F_74 ( struct V_1 * V_1 , struct V_124 T_3 * V_125 )
{
struct V_124 V_126 ;
if ( ! V_125 )
return - V_127 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_29 = V_128 ;
V_126 . V_129 = V_1 -> V_112 ;
V_126 . V_130 = F_75 ( V_1 -> line . V_131 ) ;
V_126 . V_132 = V_1 -> V_7 . V_132 / 10 ;
V_126 . V_133 = V_1 -> V_7 . V_133 == V_134 ?
V_134 :
V_1 -> V_7 . V_133 / 10 ;
if ( F_76 ( V_125 , & V_126 , sizeof( V_126 ) ) )
return - V_135 ;
else
return 0 ;
}
static int F_77 ( struct V_1 * V_1 ,
struct V_124 T_3 * V_136 )
{
struct V_124 V_137 ;
unsigned int V_133 , V_132 ;
int V_14 = 0 ;
if ( F_78 ( & V_137 , V_136 , sizeof( V_137 ) ) )
return - V_135 ;
V_132 = V_137 . V_132 * 10 ;
V_133 = V_137 . V_133 == V_134 ?
V_134 : V_137 . V_133 * 10 ;
F_2 ( & V_1 -> V_7 . V_5 ) ;
if ( ! F_79 ( V_138 ) ) {
if ( ( V_132 != V_1 -> V_7 . V_132 ) ||
( V_133 != V_1 -> V_7 . V_133 ) )
V_14 = - V_76 ;
else
V_14 = - V_139 ;
} else {
V_1 -> V_7 . V_132 = V_132 ;
V_1 -> V_7 . V_133 = V_133 ;
}
F_3 ( & V_1 -> V_7 . V_5 ) ;
return V_14 ;
}
static int F_80 ( struct V_90 * V_91 ,
unsigned int V_140 , unsigned long V_141 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
int V_142 = - V_143 ;
switch ( V_140 ) {
case V_144 :
V_142 = F_74 ( V_1 , (struct V_124 T_3 * ) V_141 ) ;
break;
case V_145 :
V_142 = F_77 ( V_1 , (struct V_124 T_3 * ) V_141 ) ;
break;
}
return V_142 ;
}
static void F_81 ( struct V_90 * V_91 ,
struct V_146 * V_147 )
{
struct V_1 * V_1 = V_91 -> V_94 ;
struct V_146 * V_148 = & V_91 -> V_148 ;
struct V_149 V_150 ;
int V_52 = V_1 -> V_104 ;
V_150 . V_131 = F_82 ( F_83 ( V_91 ) ) ;
V_150 . V_151 = V_148 -> V_152 & V_153 ? 2 : 0 ;
V_150 . V_154 = V_148 -> V_152 & V_155 ?
( V_148 -> V_152 & V_156 ? 1 : 2 ) +
( V_148 -> V_152 & V_157 ? 2 : 0 ) : 0 ;
switch ( V_148 -> V_152 & V_158 ) {
case V_159 :
V_150 . V_160 = 5 ;
break;
case V_161 :
V_150 . V_160 = 6 ;
break;
case V_162 :
V_150 . V_160 = 7 ;
break;
case V_163 :
default:
V_150 . V_160 = 8 ;
break;
}
V_1 -> V_61 = ( ( V_148 -> V_152 & V_164 ) != 0 ) ;
if ( ! V_150 . V_131 ) {
V_150 . V_131 = V_1 -> line . V_131 ;
V_52 &= ~ V_105 ;
} else
V_52 |= V_105 ;
if ( V_52 != V_1 -> V_104 )
F_50 ( V_1 , V_1 -> V_104 = V_52 ) ;
if ( memcmp ( & V_1 -> line , & V_150 , sizeof V_150 ) ) {
memcpy ( & V_1 -> line , & V_150 , sizeof V_150 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_23 ,
V_21 ,
F_75 ( V_150 . V_131 ) ,
V_150 . V_151 , V_150 . V_154 ,
V_150 . V_160 ) ;
F_84 ( V_1 , & V_1 -> line ) ;
}
}
static void F_85 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
struct V_165 * V_166 = F_86 ( V_1 -> V_17 ) ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ )
F_87 ( V_166 , V_1 -> V_112 , V_25 -> V_12 , V_25 -> V_36 ) ;
}
static void F_88 ( struct V_1 * V_1 )
{
struct V_165 * V_166 = F_86 ( V_1 -> V_17 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_77 ; V_22 ++ )
F_87 ( V_166 , V_1 -> V_167 ,
V_1 -> V_168 [ V_22 ] . V_169 , V_1 -> V_168 [ V_22 ] . V_170 ) ;
}
static int F_89 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ ) {
V_25 -> V_12 = F_90 ( V_1 -> V_15 , V_1 -> V_112 , V_102 ,
& V_25 -> V_36 ) ;
if ( ! V_25 -> V_12 ) {
while ( V_22 != 0 ) {
-- V_22 ;
-- V_25 ;
F_87 ( V_1 -> V_15 , V_1 -> V_112 ,
V_25 -> V_12 , V_25 -> V_36 ) ;
}
return - V_171 ;
}
}
return 0 ;
}
static int F_91 ( struct V_43 * V_44 ,
const struct V_172 * V_173 )
{
struct V_174 * V_175 = NULL ;
struct V_176 * V_177 = NULL ;
unsigned char * V_178 = V_44 -> V_18 -> V_179 ;
int V_180 = V_44 -> V_18 -> V_181 ;
struct V_43 * V_182 ;
struct V_43 * V_183 ;
struct V_184 * V_185 = NULL ;
struct V_184 * V_186 = NULL ;
struct V_184 * V_187 = NULL ;
struct V_165 * V_166 = F_86 ( V_44 ) ;
struct V_1 * V_1 ;
int V_8 ;
int V_188 , V_167 ;
T_4 * V_12 ;
T_4 V_189 = 0 ;
T_4 V_190 = 0 ;
int V_191 = - 1 ;
int V_192 = - 1 ;
unsigned long V_193 ;
int V_194 ;
int V_22 ;
int V_195 = 0 ;
struct V_40 * V_196 ;
int V_142 = - V_171 ;
V_193 = ( unsigned long ) V_173 -> V_197 ;
if ( V_193 == V_198 )
return - V_92 ;
V_194 = ( V_193 == V_199 ) ? 1 : V_200 ;
if ( V_193 == V_201 ) {
V_183 = F_92 ( V_166 , 1 ) ;
V_182 = F_92 ( V_166 , 0 ) ;
goto V_202;
}
if ( ! V_178 ) {
F_19 ( & V_44 -> V_15 , L_24 ) ;
return - V_127 ;
}
if ( ! V_180 ) {
if ( V_44 -> V_203 -> V_204 &&
V_44 -> V_203 -> V_204 -> V_181 &&
V_44 -> V_203 -> V_204 -> V_179 ) {
F_10 ( & V_44 -> V_15 ,
L_25 ) ;
V_180 = V_44 -> V_203 -> V_204 -> V_181 ;
V_178 = V_44 -> V_203 -> V_204 -> V_179 ;
} else {
F_19 ( & V_44 -> V_15 ,
L_26 ) ;
return - V_127 ;
}
}
while ( V_180 > 0 ) {
if ( V_178 [ 1 ] != V_205 ) {
F_19 ( & V_44 -> V_15 , L_27 ) ;
goto V_206;
}
switch ( V_178 [ 2 ] ) {
case V_207 :
if ( V_175 ) {
F_19 ( & V_44 -> V_15 , L_28
L_29 ) ;
goto V_206;
}
V_175 = (struct V_174 * ) V_178 ;
break;
case V_208 :
V_177 = (struct V_176 * ) V_178 ;
break;
case V_209 :
break;
case V_210 :
V_189 = V_178 [ 3 ] ;
break;
case V_211 :
V_190 = V_178 [ 3 ] ;
V_191 = V_178 [ 4 ] ;
if ( ( V_193 & V_212 ) == 0 && ( V_190 & 3 ) != 3 )
F_19 ( & V_44 -> V_15 , L_30 ) ;
break;
default:
F_10 ( & V_44 -> V_15 , L_31
L_32 ,
V_178 [ 2 ] , V_178 [ 0 ] ) ;
break;
}
V_206:
V_180 -= V_178 [ 0 ] ;
V_178 += V_178 [ 0 ] ;
}
if ( ! V_175 ) {
if ( V_191 > 0 ) {
F_10 ( & V_44 -> V_15 , L_33 ) ;
if ( V_193 & V_213 )
V_183 = F_92 ( V_166 , 0 ) ;
else
V_183 = F_92 ( V_166 , ( V_192 = V_191 ) ) ;
V_182 = V_44 ;
} else {
if ( V_44 -> V_203 -> V_19 . V_214 != 3 ) {
F_10 ( & V_44 -> V_15 , L_34 ) ;
return - V_92 ;
} else {
F_93 ( & V_44 -> V_15 , L_35 ) ;
V_195 = 1 ;
V_182 = V_183 = V_44 ;
goto V_215;
}
}
} else {
V_182 = F_92 ( V_166 , V_175 -> V_216 ) ;
V_183 = F_92 ( V_166 , ( V_192 = V_175 -> V_217 ) ) ;
if ( ! V_182 || ! V_183 ) {
F_10 ( & V_44 -> V_15 , L_36 ) ;
return - V_92 ;
}
}
if ( V_192 != V_191 )
F_10 ( & V_44 -> V_15 , L_37 ) ;
if ( V_182 == V_183 ) {
F_93 ( & V_44 -> V_15 , L_38 ) ;
V_195 = 1 ;
V_193 |= V_218 ;
if ( V_183 -> V_203 -> V_19 . V_214 != 3 ) {
F_19 ( & V_44 -> V_15 , L_39 ) ;
return - V_127 ;
}
V_215:
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ ) {
struct V_184 * V_219 ;
V_219 = & V_183 -> V_203 -> V_204 [ V_22 ] . V_19 ;
if ( F_94 ( V_219 ) )
V_185 = V_219 ;
else if ( F_95 ( V_219 ) )
V_187 = V_219 ;
else if ( F_96 ( V_219 ) )
V_186 = V_219 ;
else
return - V_127 ;
}
if ( ! V_185 || ! V_186 || ! V_187 )
return - V_92 ;
else
goto V_220;
}
V_202:
if ( V_183 -> V_203 -> V_19 . V_221
!= V_222 ) {
if ( V_182 -> V_203 -> V_19 . V_221
== V_222 ) {
struct V_43 * V_223 ;
F_10 ( & V_44 -> V_15 ,
L_40 ) ;
V_223 = V_182 ;
V_182 = V_183 ;
V_183 = V_223 ;
} else {
return - V_127 ;
}
}
if ( ! V_195 && V_44 != V_182 )
return - V_92 ;
if ( ! V_195 && F_97 ( V_183 ) ) {
F_10 ( & V_44 -> V_15 , L_41 ) ;
return - V_224 ;
}
if ( V_183 -> V_203 -> V_19 . V_214 < 2 ||
V_182 -> V_203 -> V_19 . V_214 == 0 )
return - V_127 ;
V_185 = & V_182 -> V_203 -> V_204 [ 0 ] . V_19 ;
V_186 = & V_183 -> V_203 -> V_204 [ 0 ] . V_19 ;
V_187 = & V_183 -> V_203 -> V_204 [ 1 ] . V_19 ;
if ( ! F_98 ( V_186 ) ) {
struct V_184 * V_223 ;
F_10 ( & V_44 -> V_15 ,
L_42 ) ;
V_223 = V_186 ;
V_186 = V_187 ;
V_187 = V_223 ;
}
V_220:
F_10 ( & V_44 -> V_15 , L_43 ) ;
V_1 = F_99 ( sizeof( struct V_1 ) , V_102 ) ;
if ( V_1 == NULL ) {
F_19 ( & V_44 -> V_15 , L_44 ) ;
goto V_225;
}
V_8 = F_5 ( V_1 ) ;
if ( V_8 == V_9 ) {
F_19 ( & V_44 -> V_15 , L_45 ) ;
F_57 ( V_1 ) ;
return - V_92 ;
}
V_188 = F_100 ( V_185 ) ;
V_167 = F_100 ( V_186 ) *
( V_193 == V_199 ? 1 : 2 ) ;
V_1 -> V_195 = V_195 ;
V_1 -> V_112 = F_100 ( V_187 ) * 20 ;
V_1 -> V_17 = V_182 ;
V_1 -> V_39 = V_183 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_15 = V_166 ;
V_1 -> V_45 = V_189 ;
if ( V_193 & V_218 )
V_1 -> V_45 &= ~ V_107 ;
V_1 -> V_188 = V_188 ;
V_1 -> V_167 = V_167 ;
V_1 -> V_77 = V_194 ;
F_101 ( & V_1 -> V_86 , F_40 ) ;
F_102 ( & V_1 -> V_30 ) ;
F_102 ( & V_1 -> V_82 ) ;
F_103 ( & V_1 -> V_5 ) ;
V_1 -> V_226 = F_104 ( V_166 , V_186 -> V_227 ) ;
V_1 -> V_228 = F_105 ( V_186 ) ;
if ( V_1 -> V_228 )
V_1 -> V_229 = V_186 -> V_229 ;
F_106 ( & V_1 -> V_7 ) ;
V_1 -> V_7 . V_230 = & V_231 ;
V_12 = F_90 ( V_166 , V_188 , V_102 , & V_1 -> V_232 ) ;
if ( ! V_12 ) {
F_19 ( & V_44 -> V_15 , L_46 ) ;
goto V_233;
}
V_1 -> V_234 = V_12 ;
if ( F_89 ( V_1 ) < 0 ) {
F_19 ( & V_44 -> V_15 , L_47 ) ;
goto V_235;
}
V_1 -> V_101 = F_107 ( 0 , V_102 ) ;
if ( ! V_1 -> V_101 ) {
F_19 ( & V_44 -> V_15 , L_48 ) ;
goto V_236;
}
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ ) {
struct V_79 * V_80 = & ( V_1 -> V_168 [ V_22 ] ) ;
struct V_33 * V_33 ;
V_80 -> V_169 = F_90 ( V_1 -> V_15 , V_167 , V_102 ,
& V_80 -> V_170 ) ;
if ( ! V_80 -> V_169 ) {
F_19 ( & V_44 -> V_15 , L_49
L_50 ) ;
goto V_237;
}
V_80 -> V_2 = V_22 ;
V_80 -> V_81 = V_1 ;
V_33 = F_107 ( 0 , V_102 ) ;
if ( ! V_33 ) {
F_19 ( & V_44 -> V_15 ,
L_51 ) ;
goto V_237;
}
V_33 -> V_238 |= V_239 ;
V_33 -> V_35 = V_80 -> V_170 ;
if ( V_1 -> V_228 ) {
F_108 ( V_33 , V_1 -> V_15 ,
V_1 -> V_226 ,
V_80 -> V_169 ,
V_1 -> V_167 ,
F_37 , V_80 ,
V_1 -> V_229 ) ;
} else {
F_109 ( V_33 , V_1 -> V_15 ,
V_1 -> V_226 ,
V_80 -> V_169 ,
V_1 -> V_167 ,
F_37 , V_80 ) ;
}
V_1 -> V_75 [ V_22 ] = V_33 ;
F_110 ( V_22 , & V_1 -> V_74 ) ;
}
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ ) {
struct V_24 * V_240 = & ( V_1 -> V_25 [ V_22 ] ) ;
V_240 -> V_33 = F_107 ( 0 , V_102 ) ;
if ( V_240 -> V_33 == NULL ) {
F_19 ( & V_44 -> V_15 ,
L_52 ) ;
goto V_241;
}
if ( F_105 ( V_187 ) )
F_108 ( V_240 -> V_33 , V_166 ,
F_111 ( V_166 , V_187 -> V_227 ) ,
NULL , V_1 -> V_112 , F_38 , V_240 , V_187 -> V_229 ) ;
else
F_109 ( V_240 -> V_33 , V_166 ,
F_112 ( V_166 , V_187 -> V_227 ) ,
NULL , V_1 -> V_112 , F_38 , V_240 ) ;
V_240 -> V_33 -> V_238 |= V_239 ;
V_240 -> V_81 = V_1 ;
}
F_113 ( V_44 , V_1 ) ;
V_22 = F_114 ( & V_44 -> V_15 , & V_242 ) ;
if ( V_22 < 0 )
goto V_241;
if ( V_177 ) {
V_1 -> V_46 = F_115 ( V_177 -> V_243 - 4 , V_102 ) ;
if ( ! V_1 -> V_46 )
goto V_244;
V_1 -> V_47 = V_177 -> V_243 - 4 ;
memcpy ( V_1 -> V_46 , ( T_4 * ) & V_177 -> V_245 ,
V_177 -> V_243 - 4 ) ;
V_1 -> V_48 = V_177 -> V_246 ;
V_22 = F_114 ( & V_44 -> V_15 , & V_247 ) ;
if ( V_22 < 0 ) {
F_57 ( V_1 -> V_46 ) ;
V_1 -> V_46 = NULL ;
V_1 -> V_47 = 0 ;
goto V_244;
}
V_22 = F_114 ( & V_44 -> V_15 ,
& V_248 ) ;
if ( V_22 < 0 ) {
F_116 ( & V_44 -> V_15 , & V_247 ) ;
F_57 ( V_1 -> V_46 ) ;
V_1 -> V_46 = NULL ;
V_1 -> V_47 = 0 ;
goto V_244;
}
}
V_244:
F_108 ( V_1 -> V_101 , V_166 ,
F_117 ( V_166 , V_185 -> V_227 ) ,
V_1 -> V_234 , V_188 , F_25 , V_1 ,
V_185 -> V_229 ? V_185 -> V_229 : 0xff ) ;
V_1 -> V_101 -> V_238 |= V_239 ;
V_1 -> V_101 -> V_35 = V_1 -> V_232 ;
F_118 ( & V_44 -> V_15 , L_53 , V_8 ) ;
F_50 ( V_1 , V_1 -> V_104 ) ;
V_1 -> line . V_131 = F_82 ( 9600 ) ;
V_1 -> line . V_160 = 8 ;
F_84 ( V_1 , & V_1 -> line ) ;
F_119 ( & V_249 , V_183 , V_1 ) ;
F_113 ( V_183 , V_1 ) ;
F_120 ( V_182 ) ;
V_196 = F_121 ( & V_1 -> V_7 , V_250 , V_8 ,
& V_182 -> V_15 ) ;
if ( F_122 ( V_196 ) ) {
V_142 = F_123 ( V_196 ) ;
goto V_251;
}
return 0 ;
V_251:
if ( V_1 -> V_46 ) {
F_116 ( & V_1 -> V_17 -> V_15 ,
& V_247 ) ;
F_116 ( & V_1 -> V_17 -> V_15 ,
& V_248 ) ;
}
F_116 ( & V_1 -> V_17 -> V_15 , & V_242 ) ;
V_241:
F_113 ( V_44 , NULL ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_124 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
V_237:
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ )
F_124 ( V_1 -> V_75 [ V_22 ] ) ;
F_88 ( V_1 ) ;
F_124 ( V_1 -> V_101 ) ;
V_236:
F_85 ( V_1 ) ;
V_235:
F_87 ( V_166 , V_188 , V_1 -> V_234 , V_1 -> V_232 ) ;
V_233:
F_6 ( V_1 ) ;
F_57 ( V_1 ) ;
V_225:
return V_142 ;
}
static void F_125 ( struct V_1 * V_1 )
{
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_18 , V_21 ) ;
F_54 ( V_1 -> V_101 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_54 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_77 ; V_22 ++ )
F_54 ( V_1 -> V_75 [ V_22 ] ) ;
F_126 ( & V_1 -> V_86 ) ;
}
static void F_127 ( struct V_43 * V_44 )
{
struct V_1 * V_1 = F_22 ( V_44 ) ;
struct V_165 * V_166 = F_86 ( V_44 ) ;
struct V_90 * V_91 ;
int V_22 ;
F_10 ( & V_44 -> V_15 , L_18 , V_21 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_5 ) ;
V_1 -> V_6 = true ;
if ( V_1 -> V_46 ) {
F_116 ( & V_1 -> V_17 -> V_15 ,
& V_247 ) ;
F_116 ( & V_1 -> V_17 -> V_15 ,
& V_248 ) ;
}
F_116 ( & V_1 -> V_17 -> V_15 , & V_242 ) ;
F_113 ( V_1 -> V_17 , NULL ) ;
F_113 ( V_1 -> V_39 , NULL ) ;
F_3 ( & V_1 -> V_5 ) ;
V_91 = F_128 ( & V_1 -> V_7 ) ;
if ( V_91 ) {
F_129 ( V_91 ) ;
F_130 ( V_91 ) ;
}
F_125 ( V_1 ) ;
F_131 ( V_250 , V_1 -> V_8 ) ;
F_124 ( V_1 -> V_101 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_124 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_77 ; V_22 ++ )
F_124 ( V_1 -> V_75 [ V_22 ] ) ;
F_85 ( V_1 ) ;
F_87 ( V_166 , V_1 -> V_188 , V_1 -> V_234 , V_1 -> V_232 ) ;
F_88 ( V_1 ) ;
if ( ! V_1 -> V_195 )
F_132 ( & V_249 , V_44 == V_1 -> V_17 ?
V_1 -> V_39 : V_1 -> V_17 ) ;
F_45 ( & V_1 -> V_7 ) ;
}
static int F_133 ( struct V_43 * V_44 , T_5 V_252 )
{
struct V_1 * V_1 = F_22 ( V_44 ) ;
int V_253 ;
if ( F_134 ( V_252 ) ) {
int V_254 ;
F_52 ( & V_1 -> V_30 ) ;
V_254 = V_1 -> V_31 ;
F_53 ( & V_1 -> V_30 ) ;
if ( V_254 )
return - V_224 ;
}
F_52 ( & V_1 -> V_82 ) ;
F_135 ( & V_1 -> V_30 ) ;
V_253 = V_1 -> V_85 ++ ;
F_136 ( & V_1 -> V_30 ) ;
F_53 ( & V_1 -> V_82 ) ;
if ( V_253 )
return 0 ;
if ( F_137 ( V_255 , & V_1 -> V_7 . V_29 ) )
F_125 ( V_1 ) ;
return 0 ;
}
static int F_138 ( struct V_43 * V_44 )
{
struct V_1 * V_1 = F_22 ( V_44 ) ;
struct V_24 * V_25 ;
int V_142 = 0 ;
int V_253 ;
F_52 ( & V_1 -> V_82 ) ;
V_1 -> V_85 -= 1 ;
V_253 = V_1 -> V_85 ;
F_53 ( & V_1 -> V_82 ) ;
if ( V_253 )
return 0 ;
if ( F_137 ( V_255 , & V_1 -> V_7 . V_29 ) ) {
V_142 = F_18 ( V_1 -> V_101 , V_256 ) ;
F_52 ( & V_1 -> V_30 ) ;
if ( V_1 -> V_113 ) {
V_25 = V_1 -> V_113 ;
V_1 -> V_113 = NULL ;
F_53 ( & V_1 -> V_30 ) ;
F_17 ( V_1 , V_25 ) ;
} else {
F_53 ( & V_1 -> V_30 ) ;
}
if ( V_142 < 0 )
goto V_257;
V_142 = F_33 ( V_1 , V_256 ) ;
}
V_257:
return V_142 ;
}
static int F_139 ( struct V_43 * V_44 )
{
struct V_1 * V_1 = F_22 ( V_44 ) ;
if ( F_137 ( V_255 , & V_1 -> V_7 . V_29 ) )
F_28 ( & V_1 -> V_7 , false ) ;
return F_138 ( V_44 ) ;
}
static int T_6 F_140 ( void )
{
int V_14 ;
V_250 = F_141 ( V_9 ) ;
if ( ! V_250 )
return - V_171 ;
V_250 -> V_258 = L_54 ,
V_250 -> V_259 = L_55 ,
V_250 -> V_260 = V_261 ,
V_250 -> V_262 = 0 ,
V_250 -> type = V_263 ,
V_250 -> V_264 = V_265 ,
V_250 -> V_29 = V_266 | V_267 ;
V_250 -> V_268 = V_269 ;
V_250 -> V_268 . V_152 = V_270 | V_163 | V_271 |
V_272 | V_164 ;
F_142 ( V_250 , & V_273 ) ;
V_14 = F_143 ( V_250 ) ;
if ( V_14 ) {
F_144 ( V_250 ) ;
return V_14 ;
}
V_14 = F_145 ( & V_249 ) ;
if ( V_14 ) {
F_146 ( V_250 ) ;
F_144 ( V_250 ) ;
return V_14 ;
}
F_147 (KERN_INFO KBUILD_MODNAME L_56 DRIVER_DESC L_57 ) ;
return 0 ;
}
static void T_7 F_148 ( void )
{
F_149 ( & V_249 ) ;
F_146 ( V_250 ) ;
F_144 ( V_250 ) ;
}
