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
static int F_20 ( struct V_1 * V_1 , int V_23 )
{
unsigned long V_29 ;
struct V_24 * V_25 = & V_1 -> V_25 [ V_23 ] ;
int V_32 ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
if ( ! V_1 -> V_15 ) {
V_25 -> V_26 = 0 ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
return - V_40 ;
}
F_21 ( & V_1 -> V_39 -> V_15 , L_3 , V_21 ,
V_1 -> V_41 ) ;
F_22 ( V_1 -> V_17 ) ;
if ( V_1 -> V_41 ) {
if ( ! V_1 -> V_42 )
V_1 -> V_42 = V_25 ;
else
F_16 ( V_1 -> V_17 ) ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
return 0 ;
}
F_23 ( V_1 -> V_15 ) ;
V_32 = F_17 ( V_1 , V_25 ) ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
return V_32 ;
}
static T_1 F_24
( struct V_43 * V_15 , struct V_44 * V_45 , char * V_12 )
{
struct V_46 * V_47 = F_25 ( V_15 ) ;
struct V_1 * V_1 = F_26 ( V_47 ) ;
return sprintf ( V_12 , L_4 , V_1 -> V_48 ) ;
}
static T_1 F_27
( struct V_43 * V_15 , struct V_44 * V_45 , char * V_12 )
{
struct V_46 * V_47 = F_25 ( V_15 ) ;
struct V_1 * V_1 = F_26 ( V_47 ) ;
memcpy ( V_12 , V_1 -> V_49 , V_1 -> V_50 ) ;
return V_1 -> V_50 ;
}
static T_1 F_28
( struct V_43 * V_15 , struct V_44 * V_45 , char * V_12 )
{
struct V_46 * V_47 = F_25 ( V_15 ) ;
struct V_1 * V_1 = F_26 ( V_47 ) ;
return sprintf ( V_12 , L_4 , V_1 -> V_51 ) ;
}
static void F_29 ( struct V_33 * V_33 )
{
struct V_1 * V_1 = V_33 -> V_52 ;
struct V_53 * V_54 = V_33 -> V_34 ;
unsigned char * V_39 ;
int V_55 ;
int V_14 ;
int V_56 = V_33 -> V_56 ;
switch ( V_56 ) {
case 0 :
break;
case - V_57 :
case - V_58 :
case - V_59 :
F_10 ( & V_1 -> V_17 -> V_15 ,
L_5 ,
V_21 , V_56 ) ;
return;
default:
F_10 ( & V_1 -> V_17 -> V_15 ,
L_6 ,
V_21 , V_56 ) ;
goto exit;
}
F_23 ( V_1 -> V_15 ) ;
V_39 = ( unsigned char * ) ( V_54 + 1 ) ;
switch ( V_54 -> V_60 ) {
case V_61 :
F_10 ( & V_1 -> V_17 -> V_15 , L_7 ,
V_21 , V_54 -> V_62 ) ;
break;
case V_63 :
V_55 = F_30 ( V_39 ) ;
if ( ! V_1 -> V_64 && ( V_1 -> V_65 & ~ V_55 & V_66 ) ) {
F_10 ( & V_1 -> V_17 -> V_15 , L_8 ,
V_21 ) ;
F_31 ( & V_1 -> V_7 , false ) ;
}
V_1 -> V_65 = V_55 ;
F_10 ( & V_1 -> V_17 -> V_15 ,
L_9
L_10 ,
V_21 ,
V_1 -> V_65 & V_66 ? '+' : '-' ,
V_1 -> V_65 & V_67 ? '+' : '-' ,
V_1 -> V_65 & V_68 ? '+' : '-' ,
V_1 -> V_65 & V_69 ? '+' : '-' ,
V_1 -> V_65 & V_70 ? '+' : '-' ,
V_1 -> V_65 & V_71 ? '+' : '-' ,
V_1 -> V_65 & V_72 ? '+' : '-' ) ;
break;
default:
F_10 ( & V_1 -> V_17 -> V_15 ,
L_11
L_12 ,
V_21 ,
V_54 -> V_60 , V_54 -> V_73 ,
V_54 -> V_74 , V_39 [ 0 ] , V_39 [ 1 ] ) ;
break;
}
exit:
V_14 = F_18 ( V_33 , V_38 ) ;
if ( V_14 )
F_19 ( & V_1 -> V_17 -> V_15 , L_13 ,
V_21 , V_14 ) ;
}
static int F_32 ( struct V_1 * V_1 , int V_2 , T_2 V_75 )
{
int V_76 ;
if ( ! F_33 ( V_2 , & V_1 -> V_77 ) )
return 0 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_14 , V_21 , V_2 ) ;
V_76 = F_18 ( V_1 -> V_78 [ V_2 ] , V_75 ) ;
if ( V_76 ) {
if ( V_76 != - V_79 ) {
F_19 ( & V_1 -> V_39 -> V_15 ,
L_13 ,
V_21 , V_76 ) ;
}
F_34 ( V_2 , & V_1 -> V_77 ) ;
return V_76 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_2 V_75 )
{
int V_76 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_80 ; ++ V_22 ) {
V_76 = F_32 ( V_1 , V_22 , V_75 ) ;
if ( V_76 )
return V_76 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_1 , struct V_33 * V_33 )
{
if ( ! V_33 -> V_81 )
return;
F_37 ( & V_1 -> V_7 , V_33 -> V_34 ,
V_33 -> V_81 ) ;
F_38 ( & V_1 -> V_7 ) ;
}
static void F_39 ( struct V_33 * V_33 )
{
struct V_82 * V_83 = V_33 -> V_52 ;
struct V_1 * V_1 = V_83 -> V_84 ;
unsigned long V_29 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_15 , V_21 ,
V_83 -> V_2 , V_33 -> V_81 ) ;
F_34 ( V_83 -> V_2 , & V_1 -> V_77 ) ;
if ( ! V_1 -> V_15 ) {
F_10 ( & V_1 -> V_39 -> V_15 , L_16 , V_21 ) ;
return;
}
F_23 ( V_1 -> V_15 ) ;
if ( V_33 -> V_56 ) {
F_10 ( & V_1 -> V_39 -> V_15 , L_17 ,
V_21 , V_33 -> V_56 ) ;
return;
}
F_36 ( V_1 , V_33 ) ;
F_13 ( & V_1 -> V_85 , V_29 ) ;
V_1 -> V_86 = V_1 -> V_87 ;
if ( ! V_1 -> V_86 && ! V_1 -> V_41 ) {
F_14 ( & V_1 -> V_85 , V_29 ) ;
F_32 ( V_1 , V_83 -> V_2 , V_38 ) ;
} else {
F_14 ( & V_1 -> V_85 , V_29 ) ;
}
}
static void F_40 ( struct V_33 * V_33 )
{
struct V_24 * V_25 = V_33 -> V_52 ;
struct V_1 * V_1 = V_25 -> V_84 ;
unsigned long V_29 ;
if ( V_33 -> V_56 || ( V_33 -> V_81 != V_33 -> V_37 ) )
F_21 ( & V_1 -> V_39 -> V_15 , L_18 ,
V_21 ,
V_33 -> V_81 ,
V_33 -> V_37 ,
V_33 -> V_56 ) ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
F_15 ( V_1 , V_25 ) ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
F_41 ( & V_1 -> V_88 ) ;
}
static void F_42 ( struct V_89 * V_88 )
{
struct V_1 * V_1 = F_43 ( V_88 , struct V_1 , V_88 ) ;
F_21 ( & V_1 -> V_39 -> V_15 , L_19 , V_21 ) ;
F_44 ( & V_1 -> V_7 ) ;
}
static int F_45 ( struct V_90 * V_91 , struct V_92 * V_93 )
{
struct V_1 * V_1 ;
int V_14 ;
F_10 ( V_93 -> V_15 , L_19 , V_21 ) ;
V_1 = F_1 ( V_93 -> V_2 ) ;
if ( ! V_1 )
return - V_40 ;
V_14 = F_46 ( V_91 , V_93 ) ;
if ( V_14 )
goto V_94;
V_93 -> V_95 = V_1 ;
return 0 ;
V_94:
F_47 ( & V_1 -> V_7 ) ;
return V_14 ;
}
static int F_48 ( struct V_92 * V_93 , struct V_96 * V_97 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
F_10 ( V_93 -> V_15 , L_19 , V_21 ) ;
return F_49 ( & V_1 -> V_7 , V_93 , V_97 ) ;
}
static int F_50 ( struct V_98 * V_7 , struct V_92 * V_93 )
{
struct V_1 * V_1 = F_43 ( V_7 , struct V_1 , V_7 ) ;
int V_14 = - V_40 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 )
goto V_6;
V_14 = F_51 ( V_1 -> V_17 ) ;
if ( V_14 )
goto V_99;
F_34 ( V_100 , & V_93 -> V_29 ) ;
V_1 -> V_17 -> V_101 = 1 ;
V_1 -> V_102 -> V_15 = V_1 -> V_15 ;
if ( F_18 ( V_1 -> V_102 , V_103 ) ) {
F_19 ( & V_1 -> V_17 -> V_15 ,
L_20 , V_21 ) ;
goto V_104;
}
V_1 -> V_105 = V_106 | V_107 ;
if ( F_52 ( V_1 , V_1 -> V_105 ) < 0 &&
( V_1 -> V_48 & V_108 ) )
goto V_109;
F_53 ( V_1 -> V_17 ) ;
F_54 ( & V_1 -> V_85 ) ;
V_1 -> V_86 = 0 ;
V_1 -> V_87 = 0 ;
F_55 ( & V_1 -> V_85 ) ;
if ( F_35 ( V_1 , V_103 ) )
goto V_110;
F_3 ( & V_1 -> V_5 ) ;
return 0 ;
V_110:
V_1 -> V_105 = 0 ;
F_52 ( V_1 , V_1 -> V_105 ) ;
V_109:
F_56 ( V_1 -> V_102 ) ;
V_104:
F_53 ( V_1 -> V_17 ) ;
V_99:
V_6:
F_3 ( & V_1 -> V_5 ) ;
return V_14 ;
}
static void F_57 ( struct V_98 * V_7 )
{
struct V_1 * V_1 = F_43 ( V_7 , struct V_1 , V_7 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_6 ( V_1 ) ;
F_58 ( V_1 -> V_17 ) ;
F_59 ( V_1 -> V_49 ) ;
F_59 ( V_1 ) ;
}
static void F_60 ( struct V_98 * V_7 )
{
struct V_1 * V_1 = F_43 ( V_7 , struct V_1 , V_7 ) ;
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( ! V_1 -> V_6 ) {
F_51 ( V_1 -> V_17 ) ;
F_52 ( V_1 , V_1 -> V_105 = 0 ) ;
F_56 ( V_1 -> V_102 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_56 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_80 ; V_22 ++ )
F_56 ( V_1 -> V_78 [ V_22 ] ) ;
V_1 -> V_17 -> V_101 = 0 ;
F_53 ( V_1 -> V_17 ) ;
}
F_3 ( & V_1 -> V_5 ) ;
}
static void F_61 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_47 ( & V_1 -> V_7 ) ;
}
static void F_62 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_63 ( & V_1 -> V_7 ) ;
}
static void F_64 ( struct V_92 * V_93 , struct V_96 * V_97 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_65 ( & V_1 -> V_7 , V_93 , V_97 ) ;
}
static int F_66 ( struct V_92 * V_93 ,
const unsigned char * V_12 , int V_111 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
int V_112 ;
unsigned long V_29 ;
int V_23 ;
struct V_24 * V_25 ;
if ( ! V_111 )
return 0 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_21 , V_21 , V_111 ) ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
V_23 = F_11 ( V_1 ) ;
if ( V_23 < 0 ) {
F_14 ( & V_1 -> V_30 , V_29 ) ;
return 0 ;
}
V_25 = & V_1 -> V_25 [ V_23 ] ;
V_111 = ( V_111 > V_1 -> V_113 ) ? V_1 -> V_113 : V_111 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_22 , V_21 , V_111 ) ;
memcpy ( V_25 -> V_12 , V_12 , V_111 ) ;
V_25 -> V_13 = V_111 ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
V_112 = F_20 ( V_1 , V_23 ) ;
if ( V_112 < 0 )
return V_112 ;
return V_111 ;
}
static int F_67 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
return F_12 ( V_1 ) ? V_1 -> V_113 : 0 ;
}
static int F_68 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
if ( V_1 -> V_6 )
return 0 ;
return ( V_27 - F_12 ( V_1 ) ) * V_1 -> V_113 ;
}
static void F_69 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
F_54 ( & V_1 -> V_85 ) ;
V_1 -> V_87 = 1 ;
F_55 ( & V_1 -> V_85 ) ;
}
static void F_70 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
unsigned int V_114 ;
F_54 ( & V_1 -> V_85 ) ;
V_114 = V_1 -> V_86 ;
V_1 -> V_86 = 0 ;
V_1 -> V_87 = 0 ;
F_55 ( & V_1 -> V_85 ) ;
if ( V_114 )
F_35 ( V_1 , V_103 ) ;
}
static int F_71 ( struct V_92 * V_93 , int V_115 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
int V_14 ;
V_14 = F_72 ( V_1 , V_115 ? 0xffff : 0 ) ;
if ( V_14 < 0 )
F_10 ( & V_1 -> V_17 -> V_15 , L_23 ,
V_21 ) ;
return V_14 ;
}
static int F_73 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
return ( V_1 -> V_105 & V_106 ? V_116 : 0 ) |
( V_1 -> V_105 & V_107 ? V_117 : 0 ) |
( V_1 -> V_65 & V_67 ? V_118 : 0 ) |
( V_1 -> V_65 & V_69 ? V_119 : 0 ) |
( V_1 -> V_65 & V_66 ? V_120 : 0 ) |
V_121 ;
}
static int F_74 ( struct V_92 * V_93 ,
unsigned int V_122 , unsigned int V_123 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
unsigned int V_55 ;
V_55 = V_1 -> V_105 ;
V_122 = ( V_122 & V_116 ? V_106 : 0 ) |
( V_122 & V_117 ? V_107 : 0 ) ;
V_123 = ( V_123 & V_116 ? V_106 : 0 ) |
( V_123 & V_117 ? V_107 : 0 ) ;
V_55 = ( V_55 & ~ V_123 ) | V_122 ;
if ( V_1 -> V_105 == V_55 )
return 0 ;
return F_52 ( V_1 , V_1 -> V_105 = V_55 ) ;
}
static int F_75 ( struct V_1 * V_1 , struct V_124 T_3 * V_125 )
{
struct V_124 V_126 ;
if ( ! V_125 )
return - V_127 ;
memset ( & V_126 , 0 , sizeof( V_126 ) ) ;
V_126 . V_29 = V_128 ;
V_126 . V_129 = V_1 -> V_113 ;
V_126 . V_130 = F_76 ( V_1 -> line . V_131 ) ;
V_126 . V_132 = V_1 -> V_7 . V_132 / 10 ;
V_126 . V_133 = V_1 -> V_7 . V_133 == V_134 ?
V_134 :
V_1 -> V_7 . V_133 / 10 ;
if ( F_77 ( V_125 , & V_126 , sizeof( V_126 ) ) )
return - V_135 ;
else
return 0 ;
}
static int F_78 ( struct V_1 * V_1 ,
struct V_124 T_3 * V_136 )
{
struct V_124 V_137 ;
unsigned int V_133 , V_132 ;
int V_14 = 0 ;
if ( F_79 ( & V_137 , V_136 , sizeof( V_137 ) ) )
return - V_135 ;
V_132 = V_137 . V_132 * 10 ;
V_133 = V_137 . V_133 == V_134 ?
V_134 : V_137 . V_133 * 10 ;
F_2 ( & V_1 -> V_7 . V_5 ) ;
if ( ! F_80 ( V_138 ) ) {
if ( ( V_132 != V_1 -> V_7 . V_132 ) ||
( V_133 != V_1 -> V_7 . V_133 ) )
V_14 = - V_79 ;
else
V_14 = - V_139 ;
} else {
V_1 -> V_7 . V_132 = V_132 ;
V_1 -> V_7 . V_133 = V_133 ;
}
F_3 ( & V_1 -> V_7 . V_5 ) ;
return V_14 ;
}
static int F_81 ( struct V_92 * V_93 ,
unsigned int V_140 , unsigned long V_141 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
int V_142 = - V_143 ;
switch ( V_140 ) {
case V_144 :
V_142 = F_75 ( V_1 , (struct V_124 T_3 * ) V_141 ) ;
break;
case V_145 :
V_142 = F_78 ( V_1 , (struct V_124 T_3 * ) V_141 ) ;
break;
}
return V_142 ;
}
static void F_82 ( struct V_92 * V_93 ,
struct V_146 * V_147 )
{
struct V_1 * V_1 = V_93 -> V_95 ;
struct V_146 * V_148 = & V_93 -> V_148 ;
struct V_149 V_150 ;
int V_55 = V_1 -> V_105 ;
V_150 . V_131 = F_83 ( F_84 ( V_93 ) ) ;
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
V_1 -> V_64 = ( ( V_148 -> V_152 & V_164 ) != 0 ) ;
if ( ! V_150 . V_131 ) {
V_150 . V_131 = V_1 -> line . V_131 ;
V_55 &= ~ V_106 ;
} else
V_55 |= V_106 ;
if ( V_55 != V_1 -> V_105 )
F_52 ( V_1 , V_1 -> V_105 = V_55 ) ;
if ( memcmp ( & V_1 -> line , & V_150 , sizeof V_150 ) ) {
memcpy ( & V_1 -> line , & V_150 , sizeof V_150 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_24 ,
V_21 ,
F_76 ( V_150 . V_131 ) ,
V_150 . V_151 , V_150 . V_154 ,
V_150 . V_160 ) ;
F_85 ( V_1 , & V_1 -> line ) ;
}
}
static void F_86 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
struct V_165 * V_166 = F_87 ( V_1 -> V_17 ) ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ )
F_88 ( V_166 , V_1 -> V_113 , V_25 -> V_12 , V_25 -> V_36 ) ;
}
static void F_89 ( struct V_1 * V_1 )
{
struct V_165 * V_166 = F_87 ( V_1 -> V_17 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_80 ; V_22 ++ )
F_88 ( V_166 , V_1 -> V_167 ,
V_1 -> V_168 [ V_22 ] . V_169 , V_1 -> V_168 [ V_22 ] . V_170 ) ;
}
static int F_90 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ ) {
V_25 -> V_12 = F_91 ( V_1 -> V_15 , V_1 -> V_113 , V_103 ,
& V_25 -> V_36 ) ;
if ( ! V_25 -> V_12 ) {
while ( V_22 != 0 ) {
-- V_22 ;
-- V_25 ;
F_88 ( V_1 -> V_15 , V_1 -> V_113 ,
V_25 -> V_12 , V_25 -> V_36 ) ;
}
return - V_171 ;
}
}
return 0 ;
}
static int F_92 ( struct V_46 * V_47 ,
const struct V_172 * V_173 )
{
struct V_174 * V_175 = NULL ;
struct V_176 * V_177 = NULL ;
unsigned char * V_178 = V_47 -> V_18 -> V_179 ;
int V_180 = V_47 -> V_18 -> V_181 ;
struct V_46 * V_182 ;
struct V_46 * V_183 ;
struct V_184 * V_185 = NULL ;
struct V_184 * V_186 = NULL ;
struct V_184 * V_187 = NULL ;
struct V_165 * V_166 = F_87 ( V_47 ) ;
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
struct V_43 * V_196 ;
int V_142 = - V_171 ;
V_193 = ( unsigned long ) V_173 -> V_197 ;
if ( V_193 == V_198 )
return - V_40 ;
V_194 = ( V_193 == V_199 ) ? 1 : V_200 ;
if ( V_193 == V_201 ) {
V_183 = F_93 ( V_166 , 1 ) ;
V_182 = F_93 ( V_166 , 0 ) ;
goto V_202;
}
if ( ! V_178 ) {
F_19 ( & V_47 -> V_15 , L_25 ) ;
return - V_127 ;
}
if ( ! V_180 ) {
if ( V_47 -> V_203 -> V_204 &&
V_47 -> V_203 -> V_204 -> V_181 &&
V_47 -> V_203 -> V_204 -> V_179 ) {
F_10 ( & V_47 -> V_15 ,
L_26 ) ;
V_180 = V_47 -> V_203 -> V_204 -> V_181 ;
V_178 = V_47 -> V_203 -> V_204 -> V_179 ;
} else {
F_19 ( & V_47 -> V_15 ,
L_27 ) ;
return - V_127 ;
}
}
while ( V_180 > 0 ) {
if ( V_178 [ 1 ] != V_205 ) {
F_19 ( & V_47 -> V_15 , L_28 ) ;
goto V_206;
}
switch ( V_178 [ 2 ] ) {
case V_207 :
if ( V_175 ) {
F_19 ( & V_47 -> V_15 , L_29
L_30 ) ;
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
F_19 ( & V_47 -> V_15 , L_31 ) ;
break;
default:
F_10 ( & V_47 -> V_15 , L_32
L_33 ,
V_178 [ 2 ] , V_178 [ 0 ] ) ;
break;
}
V_206:
V_180 -= V_178 [ 0 ] ;
V_178 += V_178 [ 0 ] ;
}
if ( ! V_175 ) {
if ( V_191 > 0 ) {
F_10 ( & V_47 -> V_15 , L_34 ) ;
if ( V_193 & V_213 )
V_183 = F_93 ( V_166 , 0 ) ;
else
V_183 = F_93 ( V_166 , ( V_192 = V_191 ) ) ;
V_182 = V_47 ;
} else {
if ( V_47 -> V_203 -> V_19 . V_214 != 3 ) {
F_10 ( & V_47 -> V_15 , L_35 ) ;
return - V_40 ;
} else {
F_94 ( & V_47 -> V_15 , L_36 ) ;
V_195 = 1 ;
V_182 = V_183 = V_47 ;
goto V_215;
}
}
} else {
V_182 = F_93 ( V_166 , V_175 -> V_216 ) ;
V_183 = F_93 ( V_166 , ( V_192 = V_175 -> V_217 ) ) ;
if ( ! V_182 || ! V_183 ) {
F_10 ( & V_47 -> V_15 , L_37 ) ;
return - V_40 ;
}
}
if ( V_192 != V_191 )
F_10 ( & V_47 -> V_15 , L_38 ) ;
if ( V_182 == V_183 ) {
F_94 ( & V_47 -> V_15 , L_39 ) ;
V_195 = 1 ;
V_193 |= V_218 ;
if ( V_183 -> V_203 -> V_19 . V_214 != 3 ) {
F_19 ( & V_47 -> V_15 , L_40 ) ;
return - V_127 ;
}
V_215:
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ ) {
struct V_184 * V_219 ;
V_219 = & V_183 -> V_203 -> V_204 [ V_22 ] . V_19 ;
if ( F_95 ( V_219 ) )
V_185 = V_219 ;
else if ( F_96 ( V_219 ) )
V_187 = V_219 ;
else if ( F_97 ( V_219 ) )
V_186 = V_219 ;
else
return - V_127 ;
}
if ( ! V_185 || ! V_186 || ! V_187 )
return - V_40 ;
else
goto V_220;
}
V_202:
if ( V_183 -> V_203 -> V_19 . V_221
!= V_222 ) {
if ( V_182 -> V_203 -> V_19 . V_221
== V_222 ) {
struct V_46 * V_223 ;
F_10 ( & V_47 -> V_15 ,
L_41 ) ;
V_223 = V_182 ;
V_182 = V_183 ;
V_183 = V_223 ;
} else {
return - V_127 ;
}
}
if ( ! V_195 && V_47 != V_182 )
return - V_40 ;
if ( ! V_195 && F_98 ( V_183 ) ) {
F_10 ( & V_47 -> V_15 , L_42 ) ;
return - V_224 ;
}
if ( V_183 -> V_203 -> V_19 . V_214 < 2 ||
V_182 -> V_203 -> V_19 . V_214 == 0 )
return - V_127 ;
V_185 = & V_182 -> V_203 -> V_204 [ 0 ] . V_19 ;
V_186 = & V_183 -> V_203 -> V_204 [ 0 ] . V_19 ;
V_187 = & V_183 -> V_203 -> V_204 [ 1 ] . V_19 ;
if ( ! F_99 ( V_186 ) ) {
struct V_184 * V_223 ;
F_10 ( & V_47 -> V_15 ,
L_43 ) ;
V_223 = V_186 ;
V_186 = V_187 ;
V_187 = V_223 ;
}
V_220:
F_10 ( & V_47 -> V_15 , L_44 ) ;
V_1 = F_100 ( sizeof( struct V_1 ) , V_103 ) ;
if ( V_1 == NULL ) {
F_19 ( & V_47 -> V_15 , L_45 ) ;
goto V_225;
}
V_8 = F_5 ( V_1 ) ;
if ( V_8 == V_9 ) {
F_19 ( & V_47 -> V_15 , L_46 ) ;
F_59 ( V_1 ) ;
return - V_40 ;
}
V_188 = F_101 ( V_185 ) ;
V_167 = F_101 ( V_186 ) *
( V_193 == V_199 ? 1 : 2 ) ;
V_1 -> V_195 = V_195 ;
V_1 -> V_113 = F_101 ( V_187 ) * 20 ;
V_1 -> V_17 = V_182 ;
V_1 -> V_39 = V_183 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_15 = V_166 ;
V_1 -> V_48 = V_189 ;
if ( V_193 & V_218 )
V_1 -> V_48 &= ~ V_108 ;
V_1 -> V_188 = V_188 ;
V_1 -> V_167 = V_167 ;
V_1 -> V_80 = V_194 ;
F_102 ( & V_1 -> V_88 , F_42 ) ;
F_103 ( & V_1 -> V_30 ) ;
F_103 ( & V_1 -> V_85 ) ;
F_104 ( & V_1 -> V_5 ) ;
V_1 -> V_226 = F_105 ( V_166 , V_186 -> V_227 ) ;
V_1 -> V_228 = F_106 ( V_186 ) ;
if ( V_1 -> V_228 )
V_1 -> V_229 = V_186 -> V_229 ;
F_107 ( & V_1 -> V_7 ) ;
V_1 -> V_7 . V_230 = & V_231 ;
V_12 = F_91 ( V_166 , V_188 , V_103 , & V_1 -> V_232 ) ;
if ( ! V_12 ) {
F_19 ( & V_47 -> V_15 , L_47 ) ;
goto V_233;
}
V_1 -> V_234 = V_12 ;
if ( F_90 ( V_1 ) < 0 ) {
F_19 ( & V_47 -> V_15 , L_48 ) ;
goto V_235;
}
V_1 -> V_102 = F_108 ( 0 , V_103 ) ;
if ( ! V_1 -> V_102 ) {
F_19 ( & V_47 -> V_15 , L_49 ) ;
goto V_236;
}
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ ) {
struct V_82 * V_83 = & ( V_1 -> V_168 [ V_22 ] ) ;
struct V_33 * V_33 ;
V_83 -> V_169 = F_91 ( V_1 -> V_15 , V_167 , V_103 ,
& V_83 -> V_170 ) ;
if ( ! V_83 -> V_169 ) {
F_19 ( & V_47 -> V_15 , L_50
L_51 ) ;
goto V_237;
}
V_83 -> V_2 = V_22 ;
V_83 -> V_84 = V_1 ;
V_33 = F_108 ( 0 , V_103 ) ;
if ( ! V_33 ) {
F_19 ( & V_47 -> V_15 ,
L_52 ) ;
goto V_237;
}
V_33 -> V_238 |= V_239 ;
V_33 -> V_35 = V_83 -> V_170 ;
if ( V_1 -> V_228 ) {
F_109 ( V_33 , V_1 -> V_15 ,
V_1 -> V_226 ,
V_83 -> V_169 ,
V_1 -> V_167 ,
F_39 , V_83 ,
V_1 -> V_229 ) ;
} else {
F_110 ( V_33 , V_1 -> V_15 ,
V_1 -> V_226 ,
V_83 -> V_169 ,
V_1 -> V_167 ,
F_39 , V_83 ) ;
}
V_1 -> V_78 [ V_22 ] = V_33 ;
F_111 ( V_22 , & V_1 -> V_77 ) ;
}
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ ) {
struct V_24 * V_240 = & ( V_1 -> V_25 [ V_22 ] ) ;
V_240 -> V_33 = F_108 ( 0 , V_103 ) ;
if ( V_240 -> V_33 == NULL ) {
F_19 ( & V_47 -> V_15 ,
L_53 ) ;
goto V_241;
}
if ( F_106 ( V_187 ) )
F_109 ( V_240 -> V_33 , V_166 ,
F_112 ( V_166 , V_187 -> V_227 ) ,
NULL , V_1 -> V_113 , F_40 , V_240 , V_187 -> V_229 ) ;
else
F_110 ( V_240 -> V_33 , V_166 ,
F_113 ( V_166 , V_187 -> V_227 ) ,
NULL , V_1 -> V_113 , F_40 , V_240 ) ;
V_240 -> V_33 -> V_238 |= V_239 ;
V_240 -> V_84 = V_1 ;
}
F_114 ( V_47 , V_1 ) ;
V_22 = F_115 ( & V_47 -> V_15 , & V_242 ) ;
if ( V_22 < 0 )
goto V_241;
if ( V_177 ) {
V_1 -> V_49 = F_116 ( V_177 -> V_243 - 4 , V_103 ) ;
if ( ! V_1 -> V_49 )
goto V_244;
V_1 -> V_50 = V_177 -> V_243 - 4 ;
memcpy ( V_1 -> V_49 , ( T_4 * ) & V_177 -> V_245 ,
V_177 -> V_243 - 4 ) ;
V_1 -> V_51 = V_177 -> V_246 ;
V_22 = F_115 ( & V_47 -> V_15 , & V_247 ) ;
if ( V_22 < 0 ) {
F_59 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
V_1 -> V_50 = 0 ;
goto V_244;
}
V_22 = F_115 ( & V_47 -> V_15 ,
& V_248 ) ;
if ( V_22 < 0 ) {
F_117 ( & V_47 -> V_15 , & V_247 ) ;
F_59 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
V_1 -> V_50 = 0 ;
goto V_244;
}
}
V_244:
F_109 ( V_1 -> V_102 , V_166 ,
F_118 ( V_166 , V_185 -> V_227 ) ,
V_1 -> V_234 , V_188 , F_29 , V_1 ,
V_185 -> V_229 ? V_185 -> V_229 : 0xff ) ;
V_1 -> V_102 -> V_238 |= V_239 ;
V_1 -> V_102 -> V_35 = V_1 -> V_232 ;
F_119 ( & V_47 -> V_15 , L_54 , V_8 ) ;
F_52 ( V_1 , V_1 -> V_105 ) ;
V_1 -> line . V_131 = F_83 ( 9600 ) ;
V_1 -> line . V_160 = 8 ;
F_85 ( V_1 , & V_1 -> line ) ;
F_120 ( & V_249 , V_183 , V_1 ) ;
F_114 ( V_183 , V_1 ) ;
F_121 ( V_182 ) ;
V_196 = F_122 ( & V_1 -> V_7 , V_250 , V_8 ,
& V_182 -> V_15 ) ;
if ( F_123 ( V_196 ) ) {
V_142 = F_124 ( V_196 ) ;
goto V_251;
}
return 0 ;
V_251:
if ( V_1 -> V_49 ) {
F_117 ( & V_1 -> V_17 -> V_15 ,
& V_247 ) ;
F_117 ( & V_1 -> V_17 -> V_15 ,
& V_248 ) ;
}
F_117 ( & V_1 -> V_17 -> V_15 , & V_242 ) ;
V_241:
F_114 ( V_47 , NULL ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_125 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
V_237:
for ( V_22 = 0 ; V_22 < V_194 ; V_22 ++ )
F_125 ( V_1 -> V_78 [ V_22 ] ) ;
F_89 ( V_1 ) ;
F_125 ( V_1 -> V_102 ) ;
V_236:
F_86 ( V_1 ) ;
V_235:
F_88 ( V_166 , V_188 , V_1 -> V_234 , V_1 -> V_232 ) ;
V_233:
F_6 ( V_1 ) ;
F_59 ( V_1 ) ;
V_225:
return V_142 ;
}
static void F_126 ( struct V_1 * V_1 )
{
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_56 ( V_1 -> V_102 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_56 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_80 ; V_22 ++ )
F_56 ( V_1 -> V_78 [ V_22 ] ) ;
F_127 ( & V_1 -> V_88 ) ;
}
static void F_128 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_165 * V_166 = F_87 ( V_47 ) ;
struct V_92 * V_93 ;
int V_22 ;
F_10 ( & V_47 -> V_15 , L_19 , V_21 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_5 ) ;
V_1 -> V_6 = true ;
if ( V_1 -> V_49 ) {
F_117 ( & V_1 -> V_17 -> V_15 ,
& V_247 ) ;
F_117 ( & V_1 -> V_17 -> V_15 ,
& V_248 ) ;
}
F_117 ( & V_1 -> V_17 -> V_15 , & V_242 ) ;
F_114 ( V_1 -> V_17 , NULL ) ;
F_114 ( V_1 -> V_39 , NULL ) ;
F_3 ( & V_1 -> V_5 ) ;
V_93 = F_129 ( & V_1 -> V_7 ) ;
if ( V_93 ) {
F_130 ( V_93 ) ;
F_131 ( V_93 ) ;
}
F_126 ( V_1 ) ;
F_132 ( V_250 , V_1 -> V_8 ) ;
F_125 ( V_1 -> V_102 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_125 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_80 ; V_22 ++ )
F_125 ( V_1 -> V_78 [ V_22 ] ) ;
F_86 ( V_1 ) ;
F_88 ( V_166 , V_1 -> V_188 , V_1 -> V_234 , V_1 -> V_232 ) ;
F_89 ( V_1 ) ;
if ( ! V_1 -> V_195 )
F_133 ( & V_249 , V_47 == V_1 -> V_17 ?
V_1 -> V_39 : V_1 -> V_17 ) ;
F_47 ( & V_1 -> V_7 ) ;
}
static int F_134 ( struct V_46 * V_47 , T_5 V_252 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
int V_253 ;
if ( F_135 ( V_252 ) ) {
int V_254 ;
F_54 ( & V_1 -> V_30 ) ;
V_254 = V_1 -> V_31 ;
F_55 ( & V_1 -> V_30 ) ;
if ( V_254 )
return - V_224 ;
}
F_54 ( & V_1 -> V_85 ) ;
F_136 ( & V_1 -> V_30 ) ;
V_253 = V_1 -> V_41 ++ ;
F_137 ( & V_1 -> V_30 ) ;
F_55 ( & V_1 -> V_85 ) ;
if ( V_253 )
return 0 ;
if ( F_138 ( V_255 , & V_1 -> V_7 . V_29 ) )
F_126 ( V_1 ) ;
return 0 ;
}
static int F_139 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_24 * V_25 ;
int V_142 = 0 ;
int V_253 ;
F_54 ( & V_1 -> V_85 ) ;
V_1 -> V_41 -= 1 ;
V_253 = V_1 -> V_41 ;
F_55 ( & V_1 -> V_85 ) ;
if ( V_253 )
return 0 ;
if ( F_138 ( V_255 , & V_1 -> V_7 . V_29 ) ) {
V_142 = F_18 ( V_1 -> V_102 , V_256 ) ;
F_54 ( & V_1 -> V_30 ) ;
if ( V_1 -> V_42 ) {
V_25 = V_1 -> V_42 ;
V_1 -> V_42 = NULL ;
F_55 ( & V_1 -> V_30 ) ;
F_17 ( V_1 , V_25 ) ;
} else {
F_55 ( & V_1 -> V_30 ) ;
}
if ( V_142 < 0 )
goto V_257;
V_142 = F_35 ( V_1 , V_256 ) ;
}
V_257:
return V_142 ;
}
static int F_140 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
if ( F_138 ( V_255 , & V_1 -> V_7 . V_29 ) )
F_31 ( & V_1 -> V_7 , false ) ;
return F_139 ( V_47 ) ;
}
static int T_6 F_141 ( void )
{
int V_14 ;
V_250 = F_142 ( V_9 ) ;
if ( ! V_250 )
return - V_171 ;
V_250 -> V_258 = L_55 ,
V_250 -> V_259 = L_56 ,
V_250 -> V_260 = V_261 ,
V_250 -> V_262 = 0 ,
V_250 -> type = V_263 ,
V_250 -> V_264 = V_265 ,
V_250 -> V_29 = V_266 | V_267 ;
V_250 -> V_268 = V_269 ;
V_250 -> V_268 . V_152 = V_270 | V_163 | V_271 |
V_272 | V_164 ;
F_143 ( V_250 , & V_273 ) ;
V_14 = F_144 ( V_250 ) ;
if ( V_14 ) {
F_145 ( V_250 ) ;
return V_14 ;
}
V_14 = F_146 ( & V_249 ) ;
if ( V_14 ) {
F_147 ( V_250 ) ;
F_145 ( V_250 ) ;
return V_14 ;
}
F_148 (KERN_INFO KBUILD_MODNAME L_57 DRIVER_DESC L_58 ) ;
return 0 ;
}
static void T_7 F_149 ( void )
{
F_150 ( & V_249 ) ;
F_147 ( V_250 ) ;
F_145 ( V_250 ) ;
}
