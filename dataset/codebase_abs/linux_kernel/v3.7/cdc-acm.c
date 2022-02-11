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
struct V_55 * V_56 ;
unsigned char * V_39 ;
int V_57 ;
int V_14 ;
int V_58 = V_33 -> V_58 ;
switch ( V_58 ) {
case 0 :
break;
case - V_59 :
case - V_60 :
case - V_61 :
F_10 ( & V_1 -> V_17 -> V_15 ,
L_5 ,
V_21 , V_58 ) ;
return;
default:
F_10 ( & V_1 -> V_17 -> V_15 ,
L_6 ,
V_21 , V_58 ) ;
goto exit;
}
F_23 ( V_1 -> V_15 ) ;
V_39 = ( unsigned char * ) ( V_54 + 1 ) ;
switch ( V_54 -> V_62 ) {
case V_63 :
F_10 ( & V_1 -> V_17 -> V_15 , L_7 ,
V_21 , V_54 -> V_64 ) ;
break;
case V_65 :
V_56 = F_30 ( & V_1 -> V_7 ) ;
V_57 = F_31 ( V_39 ) ;
if ( V_56 ) {
if ( ! V_1 -> V_66 &&
( V_1 -> V_67 & ~ V_57 & V_68 ) ) {
F_10 ( & V_1 -> V_17 -> V_15 ,
L_8 , V_21 ) ;
F_32 ( V_56 ) ;
}
F_33 ( V_56 ) ;
}
V_1 -> V_67 = V_57 ;
F_10 ( & V_1 -> V_17 -> V_15 ,
L_9
L_10 ,
V_21 ,
V_1 -> V_67 & V_68 ? '+' : '-' ,
V_1 -> V_67 & V_69 ? '+' : '-' ,
V_1 -> V_67 & V_70 ? '+' : '-' ,
V_1 -> V_67 & V_71 ? '+' : '-' ,
V_1 -> V_67 & V_72 ? '+' : '-' ,
V_1 -> V_67 & V_73 ? '+' : '-' ,
V_1 -> V_67 & V_74 ? '+' : '-' ) ;
break;
default:
F_10 ( & V_1 -> V_17 -> V_15 ,
L_11
L_12 ,
V_21 ,
V_54 -> V_62 , V_54 -> V_75 ,
V_54 -> V_76 , V_39 [ 0 ] , V_39 [ 1 ] ) ;
break;
}
exit:
V_14 = F_18 ( V_33 , V_38 ) ;
if ( V_14 )
F_19 ( & V_1 -> V_17 -> V_15 , L_13 ,
V_21 , V_14 ) ;
}
static int F_34 ( struct V_1 * V_1 , int V_2 , T_2 V_77 )
{
int V_78 ;
if ( ! F_35 ( V_2 , & V_1 -> V_79 ) )
return 0 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_14 , V_21 , V_2 ) ;
V_78 = F_18 ( V_1 -> V_80 [ V_2 ] , V_77 ) ;
if ( V_78 ) {
if ( V_78 != - V_81 ) {
F_19 ( & V_1 -> V_39 -> V_15 ,
L_13 ,
V_21 , V_78 ) ;
}
F_36 ( V_2 , & V_1 -> V_79 ) ;
return V_78 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_2 V_77 )
{
int V_78 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; ++ V_22 ) {
V_78 = F_34 ( V_1 , V_22 , V_77 ) ;
if ( V_78 )
return V_78 ;
}
return 0 ;
}
static void F_38 ( struct V_1 * V_1 , struct V_33 * V_33 )
{
struct V_55 * V_56 ;
if ( ! V_33 -> V_83 )
return;
V_56 = F_30 ( & V_1 -> V_7 ) ;
if ( ! V_56 )
return;
F_39 ( V_56 , V_33 -> V_34 , V_33 -> V_83 ) ;
F_40 ( V_56 ) ;
F_33 ( V_56 ) ;
}
static void F_41 ( struct V_33 * V_33 )
{
struct V_84 * V_85 = V_33 -> V_52 ;
struct V_1 * V_1 = V_85 -> V_86 ;
unsigned long V_29 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_15 , V_21 ,
V_85 -> V_2 , V_33 -> V_83 ) ;
F_36 ( V_85 -> V_2 , & V_1 -> V_79 ) ;
if ( ! V_1 -> V_15 ) {
F_10 ( & V_1 -> V_39 -> V_15 , L_16 , V_21 ) ;
return;
}
F_23 ( V_1 -> V_15 ) ;
if ( V_33 -> V_58 ) {
F_10 ( & V_1 -> V_39 -> V_15 , L_17 ,
V_21 , V_33 -> V_58 ) ;
return;
}
F_38 ( V_1 , V_33 ) ;
F_13 ( & V_1 -> V_87 , V_29 ) ;
V_1 -> V_88 = V_1 -> V_89 ;
if ( ! V_1 -> V_88 && ! V_1 -> V_41 ) {
F_14 ( & V_1 -> V_87 , V_29 ) ;
F_34 ( V_1 , V_85 -> V_2 , V_38 ) ;
} else {
F_14 ( & V_1 -> V_87 , V_29 ) ;
}
}
static void F_42 ( struct V_33 * V_33 )
{
struct V_24 * V_25 = V_33 -> V_52 ;
struct V_1 * V_1 = V_25 -> V_86 ;
unsigned long V_29 ;
if ( V_33 -> V_58 || ( V_33 -> V_83 != V_33 -> V_37 ) )
F_21 ( & V_1 -> V_39 -> V_15 , L_18 ,
V_21 ,
V_33 -> V_83 ,
V_33 -> V_37 ,
V_33 -> V_58 ) ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
F_15 ( V_1 , V_25 ) ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
F_43 ( & V_1 -> V_90 ) ;
}
static void F_44 ( struct V_91 * V_90 )
{
struct V_1 * V_1 = F_45 ( V_90 , struct V_1 , V_90 ) ;
struct V_55 * V_56 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_19 , V_21 ) ;
V_56 = F_30 ( & V_1 -> V_7 ) ;
if ( ! V_56 )
return;
F_46 ( V_56 ) ;
F_33 ( V_56 ) ;
}
static int F_47 ( struct V_92 * V_93 , struct V_55 * V_56 )
{
struct V_1 * V_1 ;
int V_14 ;
F_10 ( V_56 -> V_15 , L_19 , V_21 ) ;
V_1 = F_1 ( V_56 -> V_2 ) ;
if ( ! V_1 )
return - V_40 ;
V_14 = F_48 ( V_93 , V_56 ) ;
if ( V_14 )
goto V_94;
V_56 -> V_95 = V_1 ;
return 0 ;
V_94:
F_49 ( & V_1 -> V_7 ) ;
return V_14 ;
}
static int F_50 ( struct V_55 * V_56 , struct V_96 * V_97 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( V_56 -> V_15 , L_19 , V_21 ) ;
return F_51 ( & V_1 -> V_7 , V_56 , V_97 ) ;
}
static int F_52 ( struct V_98 * V_7 , struct V_55 * V_56 )
{
struct V_1 * V_1 = F_45 ( V_7 , struct V_1 , V_7 ) ;
int V_14 = - V_40 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 )
goto V_6;
V_14 = F_53 ( V_1 -> V_17 ) ;
if ( V_14 )
goto V_99;
F_36 ( V_100 , & V_56 -> V_29 ) ;
V_1 -> V_17 -> V_101 = 1 ;
V_1 -> V_102 -> V_15 = V_1 -> V_15 ;
if ( F_18 ( V_1 -> V_102 , V_103 ) ) {
F_19 ( & V_1 -> V_17 -> V_15 ,
L_20 , V_21 ) ;
goto V_104;
}
V_1 -> V_105 = V_106 | V_107 ;
if ( F_54 ( V_1 , V_1 -> V_105 ) < 0 &&
( V_1 -> V_48 & V_108 ) )
goto V_109;
F_55 ( V_1 -> V_17 ) ;
F_56 ( & V_1 -> V_87 ) ;
V_1 -> V_88 = 0 ;
V_1 -> V_89 = 0 ;
F_57 ( & V_1 -> V_87 ) ;
if ( F_37 ( V_1 , V_103 ) )
goto V_110;
F_3 ( & V_1 -> V_5 ) ;
return 0 ;
V_110:
V_1 -> V_105 = 0 ;
F_54 ( V_1 , V_1 -> V_105 ) ;
V_109:
F_58 ( V_1 -> V_102 ) ;
V_104:
F_55 ( V_1 -> V_17 ) ;
V_99:
V_6:
F_3 ( & V_1 -> V_5 ) ;
return V_14 ;
}
static void F_59 ( struct V_98 * V_7 )
{
struct V_1 * V_1 = F_45 ( V_7 , struct V_1 , V_7 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_60 ( V_111 , V_1 -> V_8 ) ;
F_6 ( V_1 ) ;
F_61 ( V_1 -> V_17 ) ;
F_62 ( V_1 -> V_49 ) ;
F_62 ( V_1 ) ;
}
static void F_63 ( struct V_98 * V_7 )
{
struct V_1 * V_1 = F_45 ( V_7 , struct V_1 , V_7 ) ;
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( ! V_1 -> V_6 ) {
F_53 ( V_1 -> V_17 ) ;
F_54 ( V_1 , V_1 -> V_105 = 0 ) ;
F_58 ( V_1 -> V_102 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_58 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_58 ( V_1 -> V_80 [ V_22 ] ) ;
V_1 -> V_17 -> V_101 = 0 ;
F_55 ( V_1 -> V_17 ) ;
}
F_3 ( & V_1 -> V_5 ) ;
}
static void F_64 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_49 ( & V_1 -> V_7 ) ;
}
static void F_65 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_66 ( & V_1 -> V_7 ) ;
}
static void F_67 ( struct V_55 * V_56 , struct V_96 * V_97 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_68 ( & V_1 -> V_7 , V_56 , V_97 ) ;
}
static int F_69 ( struct V_55 * V_56 ,
const unsigned char * V_12 , int V_112 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
int V_113 ;
unsigned long V_29 ;
int V_23 ;
struct V_24 * V_25 ;
if ( ! V_112 )
return 0 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_21 , V_21 , V_112 ) ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
V_23 = F_11 ( V_1 ) ;
if ( V_23 < 0 ) {
F_14 ( & V_1 -> V_30 , V_29 ) ;
return 0 ;
}
V_25 = & V_1 -> V_25 [ V_23 ] ;
V_112 = ( V_112 > V_1 -> V_114 ) ? V_1 -> V_114 : V_112 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_22 , V_21 , V_112 ) ;
memcpy ( V_25 -> V_12 , V_12 , V_112 ) ;
V_25 -> V_13 = V_112 ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
V_113 = F_20 ( V_1 , V_23 ) ;
if ( V_113 < 0 )
return V_113 ;
return V_112 ;
}
static int F_70 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
return F_12 ( V_1 ) ? V_1 -> V_114 : 0 ;
}
static int F_71 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
if ( V_1 -> V_6 )
return 0 ;
return ( V_27 - F_12 ( V_1 ) ) * V_1 -> V_114 ;
}
static void F_72 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_56 ( & V_1 -> V_87 ) ;
V_1 -> V_89 = 1 ;
F_57 ( & V_1 -> V_87 ) ;
}
static void F_73 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
unsigned int V_115 ;
F_56 ( & V_1 -> V_87 ) ;
V_115 = V_1 -> V_88 ;
V_1 -> V_88 = 0 ;
V_1 -> V_89 = 0 ;
F_57 ( & V_1 -> V_87 ) ;
if ( V_115 )
F_37 ( V_1 , V_103 ) ;
}
static int F_74 ( struct V_55 * V_56 , int V_116 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
int V_14 ;
V_14 = F_75 ( V_1 , V_116 ? 0xffff : 0 ) ;
if ( V_14 < 0 )
F_10 ( & V_1 -> V_17 -> V_15 , L_23 ,
V_21 ) ;
return V_14 ;
}
static int F_76 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
return ( V_1 -> V_105 & V_106 ? V_117 : 0 ) |
( V_1 -> V_105 & V_107 ? V_118 : 0 ) |
( V_1 -> V_67 & V_69 ? V_119 : 0 ) |
( V_1 -> V_67 & V_71 ? V_120 : 0 ) |
( V_1 -> V_67 & V_68 ? V_121 : 0 ) |
V_122 ;
}
static int F_77 ( struct V_55 * V_56 ,
unsigned int V_123 , unsigned int V_124 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
unsigned int V_57 ;
V_57 = V_1 -> V_105 ;
V_123 = ( V_123 & V_117 ? V_106 : 0 ) |
( V_123 & V_118 ? V_107 : 0 ) ;
V_124 = ( V_124 & V_117 ? V_106 : 0 ) |
( V_124 & V_118 ? V_107 : 0 ) ;
V_57 = ( V_57 & ~ V_124 ) | V_123 ;
if ( V_1 -> V_105 == V_57 )
return 0 ;
return F_54 ( V_1 , V_1 -> V_105 = V_57 ) ;
}
static int F_78 ( struct V_1 * V_1 , struct V_125 T_3 * V_126 )
{
struct V_125 V_127 ;
if ( ! V_126 )
return - V_128 ;
memset ( & V_127 , 0 , sizeof( V_127 ) ) ;
V_127 . V_29 = V_129 ;
V_127 . V_130 = V_1 -> V_114 ;
V_127 . V_131 = F_79 ( V_1 -> line . V_132 ) ;
if ( F_80 ( V_126 , & V_127 , sizeof( V_127 ) ) )
return - V_133 ;
else
return 0 ;
}
static int F_81 ( struct V_55 * V_56 ,
unsigned int V_134 , unsigned long V_135 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
int V_136 = - V_137 ;
switch ( V_134 ) {
case V_138 :
V_136 = F_78 ( V_1 , (struct V_125 T_3 * ) V_135 ) ;
break;
}
return V_136 ;
}
static void F_82 ( struct V_55 * V_56 ,
struct V_139 * V_140 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
struct V_139 * V_141 = & V_56 -> V_141 ;
struct V_142 V_143 ;
int V_57 = V_1 -> V_105 ;
V_143 . V_132 = F_83 ( F_84 ( V_56 ) ) ;
V_143 . V_144 = V_141 -> V_145 & V_146 ? 2 : 0 ;
V_143 . V_147 = V_141 -> V_145 & V_148 ?
( V_141 -> V_145 & V_149 ? 1 : 2 ) +
( V_141 -> V_145 & V_150 ? 2 : 0 ) : 0 ;
switch ( V_141 -> V_145 & V_151 ) {
case V_152 :
V_143 . V_153 = 5 ;
break;
case V_154 :
V_143 . V_153 = 6 ;
break;
case V_155 :
V_143 . V_153 = 7 ;
break;
case V_156 :
default:
V_143 . V_153 = 8 ;
break;
}
V_1 -> V_66 = ( ( V_141 -> V_145 & V_157 ) != 0 ) ;
if ( ! V_143 . V_132 ) {
V_143 . V_132 = V_1 -> line . V_132 ;
V_57 &= ~ V_106 ;
} else
V_57 |= V_106 ;
if ( V_57 != V_1 -> V_105 )
F_54 ( V_1 , V_1 -> V_105 = V_57 ) ;
if ( memcmp ( & V_1 -> line , & V_143 , sizeof V_143 ) ) {
memcpy ( & V_1 -> line , & V_143 , sizeof V_143 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_24 ,
V_21 ,
F_79 ( V_143 . V_132 ) ,
V_143 . V_144 , V_143 . V_147 ,
V_143 . V_153 ) ;
F_85 ( V_1 , & V_1 -> line ) ;
}
}
static void F_86 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
struct V_158 * V_159 = F_87 ( V_1 -> V_17 ) ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ )
F_88 ( V_159 , V_1 -> V_114 , V_25 -> V_12 , V_25 -> V_36 ) ;
}
static void F_89 ( struct V_1 * V_1 )
{
struct V_158 * V_159 = F_87 ( V_1 -> V_17 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_88 ( V_159 , V_1 -> V_160 ,
V_1 -> V_161 [ V_22 ] . V_162 , V_1 -> V_161 [ V_22 ] . V_163 ) ;
}
static int F_90 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ ) {
V_25 -> V_12 = F_91 ( V_1 -> V_15 , V_1 -> V_114 , V_103 ,
& V_25 -> V_36 ) ;
if ( ! V_25 -> V_12 ) {
while ( V_22 != 0 ) {
-- V_22 ;
-- V_25 ;
F_88 ( V_1 -> V_15 , V_1 -> V_114 ,
V_25 -> V_12 , V_25 -> V_36 ) ;
}
return - V_164 ;
}
}
return 0 ;
}
static int F_92 ( struct V_46 * V_47 ,
const struct V_165 * V_166 )
{
struct V_167 * V_168 = NULL ;
struct V_169 * V_170 = NULL ;
unsigned char * V_171 = V_47 -> V_18 -> V_172 ;
int V_173 = V_47 -> V_18 -> V_174 ;
struct V_46 * V_175 ;
struct V_46 * V_176 ;
struct V_177 * V_178 = NULL ;
struct V_177 * V_179 = NULL ;
struct V_177 * V_180 = NULL ;
struct V_158 * V_159 = F_87 ( V_47 ) ;
struct V_1 * V_1 ;
int V_8 ;
int V_181 , V_160 ;
T_4 * V_12 ;
T_4 V_182 = 0 ;
T_4 V_183 = 0 ;
int V_184 = - 1 ;
int V_185 = - 1 ;
unsigned long V_186 ;
int V_187 ;
int V_22 ;
int V_188 = 0 ;
V_186 = ( unsigned long ) V_166 -> V_189 ;
V_187 = ( V_186 == V_190 ) ? 1 : V_191 ;
if ( V_186 == V_192 ) {
V_176 = F_93 ( V_159 , 1 ) ;
V_175 = F_93 ( V_159 , 0 ) ;
goto V_193;
}
if ( ! V_171 ) {
F_19 ( & V_47 -> V_15 , L_25 ) ;
return - V_128 ;
}
if ( ! V_173 ) {
if ( V_47 -> V_194 -> V_195 &&
V_47 -> V_194 -> V_195 -> V_174 &&
V_47 -> V_194 -> V_195 -> V_172 ) {
F_10 ( & V_47 -> V_15 ,
L_26 ) ;
V_173 = V_47 -> V_194 -> V_195 -> V_174 ;
V_171 = V_47 -> V_194 -> V_195 -> V_172 ;
} else {
F_19 ( & V_47 -> V_15 ,
L_27 ) ;
return - V_128 ;
}
}
while ( V_173 > 0 ) {
if ( V_171 [ 1 ] != V_196 ) {
F_19 ( & V_47 -> V_15 , L_28 ) ;
goto V_197;
}
switch ( V_171 [ 2 ] ) {
case V_198 :
if ( V_168 ) {
F_19 ( & V_47 -> V_15 , L_29
L_30 ) ;
goto V_197;
}
V_168 = (struct V_167 * ) V_171 ;
break;
case V_199 :
V_170 = (struct V_169 * ) V_171 ;
break;
case V_200 :
break;
case V_201 :
V_182 = V_171 [ 3 ] ;
break;
case V_202 :
V_183 = V_171 [ 3 ] ;
V_184 = V_171 [ 4 ] ;
if ( ( V_186 & V_203 ) == 0 && ( V_183 & 3 ) != 3 )
F_19 ( & V_47 -> V_15 , L_31 ) ;
break;
default:
F_10 ( & V_47 -> V_15 , L_32
L_33 ,
V_171 [ 2 ] , V_171 [ 0 ] ) ;
break;
}
V_197:
V_173 -= V_171 [ 0 ] ;
V_171 += V_171 [ 0 ] ;
}
if ( ! V_168 ) {
if ( V_184 > 0 ) {
F_10 ( & V_47 -> V_15 , L_34 ) ;
if ( V_186 & V_204 )
V_176 = F_93 ( V_159 , 0 ) ;
else
V_176 = F_93 ( V_159 , ( V_185 = V_184 ) ) ;
V_175 = V_47 ;
} else {
if ( V_47 -> V_194 -> V_19 . V_205 != 3 ) {
F_10 ( & V_47 -> V_15 , L_35 ) ;
return - V_40 ;
} else {
F_94 ( & V_47 -> V_15 , L_36 ) ;
V_188 = 1 ;
V_175 = V_176 = V_47 ;
goto V_206;
}
}
} else {
V_175 = F_93 ( V_159 , V_168 -> V_207 ) ;
V_176 = F_93 ( V_159 , ( V_185 = V_168 -> V_208 ) ) ;
if ( ! V_175 || ! V_176 ) {
F_10 ( & V_47 -> V_15 , L_37 ) ;
return - V_40 ;
}
}
if ( V_185 != V_184 )
F_10 ( & V_47 -> V_15 , L_38 ) ;
if ( V_175 == V_176 ) {
F_94 ( & V_47 -> V_15 , L_39 ) ;
V_188 = 1 ;
V_186 |= V_209 ;
if ( V_176 -> V_194 -> V_19 . V_205 != 3 ) {
F_19 ( & V_47 -> V_15 , L_40 ) ;
return - V_128 ;
}
V_206:
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ ) {
struct V_177 * V_210 ;
V_210 = & V_176 -> V_194 -> V_195 [ V_22 ] . V_19 ;
if ( F_95 ( V_210 ) )
V_178 = V_210 ;
else if ( F_96 ( V_210 ) )
V_180 = V_210 ;
else if ( F_97 ( V_210 ) )
V_179 = V_210 ;
else
return - V_128 ;
}
if ( ! V_178 || ! V_179 || ! V_180 )
return - V_40 ;
else
goto V_211;
}
V_193:
if ( V_176 -> V_194 -> V_19 . V_212
!= V_213 ) {
if ( V_175 -> V_194 -> V_19 . V_212
== V_213 ) {
struct V_46 * V_214 ;
F_10 ( & V_47 -> V_15 ,
L_41 ) ;
V_214 = V_175 ;
V_175 = V_176 ;
V_176 = V_214 ;
} else {
return - V_128 ;
}
}
if ( ! V_188 && V_47 != V_175 )
return - V_40 ;
if ( ! V_188 && F_98 ( V_176 ) ) {
F_10 ( & V_47 -> V_15 , L_42 ) ;
return - V_215 ;
}
if ( V_176 -> V_194 -> V_19 . V_205 < 2 ||
V_175 -> V_194 -> V_19 . V_205 == 0 )
return - V_128 ;
V_178 = & V_175 -> V_194 -> V_195 [ 0 ] . V_19 ;
V_179 = & V_176 -> V_194 -> V_195 [ 0 ] . V_19 ;
V_180 = & V_176 -> V_194 -> V_195 [ 1 ] . V_19 ;
if ( ! F_99 ( V_179 ) ) {
struct V_177 * V_214 ;
F_10 ( & V_47 -> V_15 ,
L_43 ) ;
V_214 = V_179 ;
V_179 = V_180 ;
V_180 = V_214 ;
}
V_211:
F_10 ( & V_47 -> V_15 , L_44 ) ;
V_1 = F_100 ( sizeof( struct V_1 ) , V_103 ) ;
if ( V_1 == NULL ) {
F_19 ( & V_47 -> V_15 , L_45 ) ;
goto V_216;
}
V_8 = F_5 ( V_1 ) ;
if ( V_8 == V_9 ) {
F_19 ( & V_47 -> V_15 , L_46 ) ;
F_62 ( V_1 ) ;
return - V_40 ;
}
V_181 = F_101 ( V_178 ) ;
V_160 = F_101 ( V_179 ) *
( V_186 == V_190 ? 1 : 2 ) ;
V_1 -> V_188 = V_188 ;
V_1 -> V_114 = F_101 ( V_180 ) * 20 ;
V_1 -> V_17 = V_175 ;
V_1 -> V_39 = V_176 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_15 = V_159 ;
V_1 -> V_48 = V_182 ;
if ( V_186 & V_209 )
V_1 -> V_48 &= ~ V_108 ;
V_1 -> V_181 = V_181 ;
V_1 -> V_160 = V_160 ;
V_1 -> V_82 = V_187 ;
F_102 ( & V_1 -> V_90 , F_44 ) ;
F_103 ( & V_1 -> V_30 ) ;
F_103 ( & V_1 -> V_87 ) ;
F_104 ( & V_1 -> V_5 ) ;
V_1 -> V_217 = F_105 ( V_159 , V_179 -> V_218 ) ;
V_1 -> V_219 = F_106 ( V_179 ) ;
if ( V_1 -> V_219 )
V_1 -> V_220 = V_179 -> V_220 ;
F_107 ( & V_1 -> V_7 ) ;
V_1 -> V_7 . V_221 = & V_222 ;
V_12 = F_91 ( V_159 , V_181 , V_103 , & V_1 -> V_223 ) ;
if ( ! V_12 ) {
F_19 ( & V_47 -> V_15 , L_47 ) ;
goto V_224;
}
V_1 -> V_225 = V_12 ;
if ( F_90 ( V_1 ) < 0 ) {
F_19 ( & V_47 -> V_15 , L_48 ) ;
goto V_226;
}
V_1 -> V_102 = F_108 ( 0 , V_103 ) ;
if ( ! V_1 -> V_102 ) {
F_19 ( & V_47 -> V_15 , L_49 ) ;
goto V_227;
}
for ( V_22 = 0 ; V_22 < V_187 ; V_22 ++ ) {
struct V_84 * V_85 = & ( V_1 -> V_161 [ V_22 ] ) ;
struct V_33 * V_33 ;
V_85 -> V_162 = F_91 ( V_1 -> V_15 , V_160 , V_103 ,
& V_85 -> V_163 ) ;
if ( ! V_85 -> V_162 ) {
F_19 ( & V_47 -> V_15 , L_50
L_51 ) ;
goto V_228;
}
V_85 -> V_2 = V_22 ;
V_85 -> V_86 = V_1 ;
V_33 = F_108 ( 0 , V_103 ) ;
if ( ! V_33 ) {
F_19 ( & V_47 -> V_15 ,
L_52 ) ;
goto V_228;
}
V_33 -> V_229 |= V_230 ;
V_33 -> V_35 = V_85 -> V_163 ;
if ( V_1 -> V_219 ) {
F_109 ( V_33 , V_1 -> V_15 ,
V_1 -> V_217 ,
V_85 -> V_162 ,
V_1 -> V_160 ,
F_41 , V_85 ,
V_1 -> V_220 ) ;
} else {
F_110 ( V_33 , V_1 -> V_15 ,
V_1 -> V_217 ,
V_85 -> V_162 ,
V_1 -> V_160 ,
F_41 , V_85 ) ;
}
V_1 -> V_80 [ V_22 ] = V_33 ;
F_111 ( V_22 , & V_1 -> V_79 ) ;
}
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ ) {
struct V_24 * V_231 = & ( V_1 -> V_25 [ V_22 ] ) ;
V_231 -> V_33 = F_108 ( 0 , V_103 ) ;
if ( V_231 -> V_33 == NULL ) {
F_19 ( & V_47 -> V_15 ,
L_53 ) ;
goto V_232;
}
if ( F_106 ( V_180 ) )
F_109 ( V_231 -> V_33 , V_159 ,
F_112 ( V_159 , V_180 -> V_218 ) ,
NULL , V_1 -> V_114 , F_42 , V_231 , V_180 -> V_220 ) ;
else
F_110 ( V_231 -> V_33 , V_159 ,
F_113 ( V_159 , V_180 -> V_218 ) ,
NULL , V_1 -> V_114 , F_42 , V_231 ) ;
V_231 -> V_33 -> V_229 |= V_230 ;
V_231 -> V_86 = V_1 ;
}
F_114 ( V_47 , V_1 ) ;
V_22 = F_115 ( & V_47 -> V_15 , & V_233 ) ;
if ( V_22 < 0 )
goto V_232;
if ( V_170 ) {
V_1 -> V_49 = F_116 ( V_170 -> V_234 - 4 , V_103 ) ;
if ( ! V_1 -> V_49 )
goto V_235;
V_1 -> V_50 = V_170 -> V_234 - 4 ;
memcpy ( V_1 -> V_49 , ( T_4 * ) & V_170 -> V_236 ,
V_170 -> V_234 - 4 ) ;
V_1 -> V_51 = V_170 -> V_237 ;
V_22 = F_115 ( & V_47 -> V_15 , & V_238 ) ;
if ( V_22 < 0 ) {
F_62 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
V_1 -> V_50 = 0 ;
goto V_235;
}
V_22 = F_115 ( & V_47 -> V_15 ,
& V_239 ) ;
if ( V_22 < 0 ) {
F_117 ( & V_47 -> V_15 , & V_238 ) ;
F_62 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
V_1 -> V_50 = 0 ;
goto V_235;
}
}
V_235:
F_109 ( V_1 -> V_102 , V_159 ,
F_118 ( V_159 , V_178 -> V_218 ) ,
V_1 -> V_225 , V_181 , F_29 , V_1 ,
V_178 -> V_220 ? V_178 -> V_220 : 0xff ) ;
V_1 -> V_102 -> V_229 |= V_230 ;
V_1 -> V_102 -> V_35 = V_1 -> V_223 ;
F_119 ( & V_47 -> V_15 , L_54 , V_8 ) ;
F_54 ( V_1 , V_1 -> V_105 ) ;
V_1 -> line . V_132 = F_83 ( 9600 ) ;
V_1 -> line . V_153 = 8 ;
F_85 ( V_1 , & V_1 -> line ) ;
F_120 ( & V_240 , V_176 , V_1 ) ;
F_114 ( V_176 , V_1 ) ;
F_121 ( V_175 ) ;
F_122 ( & V_1 -> V_7 , V_111 , V_8 ,
& V_175 -> V_15 ) ;
return 0 ;
V_232:
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_123 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
V_228:
for ( V_22 = 0 ; V_22 < V_187 ; V_22 ++ )
F_123 ( V_1 -> V_80 [ V_22 ] ) ;
F_89 ( V_1 ) ;
F_123 ( V_1 -> V_102 ) ;
V_227:
F_86 ( V_1 ) ;
V_226:
F_88 ( V_159 , V_181 , V_1 -> V_225 , V_1 -> V_223 ) ;
V_224:
F_6 ( V_1 ) ;
F_62 ( V_1 ) ;
V_216:
return - V_164 ;
}
static void F_124 ( struct V_1 * V_1 )
{
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_58 ( V_1 -> V_102 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_58 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_58 ( V_1 -> V_80 [ V_22 ] ) ;
F_125 ( & V_1 -> V_90 ) ;
}
static void F_126 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_158 * V_159 = F_87 ( V_47 ) ;
struct V_55 * V_56 ;
int V_22 ;
F_10 ( & V_47 -> V_15 , L_19 , V_21 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_5 ) ;
V_1 -> V_6 = true ;
if ( V_1 -> V_49 ) {
F_117 ( & V_1 -> V_17 -> V_15 ,
& V_238 ) ;
F_117 ( & V_1 -> V_17 -> V_15 ,
& V_239 ) ;
}
F_117 ( & V_1 -> V_17 -> V_15 , & V_233 ) ;
F_114 ( V_1 -> V_17 , NULL ) ;
F_114 ( V_1 -> V_39 , NULL ) ;
F_3 ( & V_1 -> V_5 ) ;
V_56 = F_30 ( & V_1 -> V_7 ) ;
if ( V_56 ) {
F_127 ( V_56 ) ;
F_33 ( V_56 ) ;
}
F_124 ( V_1 ) ;
F_123 ( V_1 -> V_102 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_123 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_123 ( V_1 -> V_80 [ V_22 ] ) ;
F_86 ( V_1 ) ;
F_88 ( V_159 , V_1 -> V_181 , V_1 -> V_225 , V_1 -> V_223 ) ;
F_89 ( V_1 ) ;
if ( ! V_1 -> V_188 )
F_128 ( & V_240 , V_47 == V_1 -> V_17 ?
V_1 -> V_39 : V_1 -> V_17 ) ;
F_49 ( & V_1 -> V_7 ) ;
}
static int F_129 ( struct V_46 * V_47 , T_5 V_241 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
int V_242 ;
if ( F_130 ( V_241 ) ) {
int V_243 ;
F_56 ( & V_1 -> V_30 ) ;
V_243 = V_1 -> V_31 ;
F_57 ( & V_1 -> V_30 ) ;
if ( V_243 )
return - V_215 ;
}
F_56 ( & V_1 -> V_87 ) ;
F_131 ( & V_1 -> V_30 ) ;
V_242 = V_1 -> V_41 ++ ;
F_132 ( & V_1 -> V_30 ) ;
F_57 ( & V_1 -> V_87 ) ;
if ( V_242 )
return 0 ;
if ( F_133 ( V_244 , & V_1 -> V_7 . V_29 ) )
F_124 ( V_1 ) ;
return 0 ;
}
static int F_134 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_24 * V_25 ;
int V_136 = 0 ;
int V_242 ;
F_56 ( & V_1 -> V_87 ) ;
V_1 -> V_41 -= 1 ;
V_242 = V_1 -> V_41 ;
F_57 ( & V_1 -> V_87 ) ;
if ( V_242 )
return 0 ;
if ( F_133 ( V_244 , & V_1 -> V_7 . V_29 ) ) {
V_136 = F_18 ( V_1 -> V_102 , V_245 ) ;
F_56 ( & V_1 -> V_30 ) ;
if ( V_1 -> V_42 ) {
V_25 = V_1 -> V_42 ;
V_1 -> V_42 = NULL ;
F_57 ( & V_1 -> V_30 ) ;
F_17 ( V_1 , V_25 ) ;
} else {
F_57 ( & V_1 -> V_30 ) ;
}
if ( V_136 < 0 )
goto V_246;
V_136 = F_37 ( V_1 , V_245 ) ;
}
V_246:
return V_136 ;
}
static int F_135 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_55 * V_56 ;
if ( F_133 ( V_244 , & V_1 -> V_7 . V_29 ) ) {
V_56 = F_30 ( & V_1 -> V_7 ) ;
if ( V_56 ) {
F_32 ( V_56 ) ;
F_33 ( V_56 ) ;
}
}
return F_134 ( V_47 ) ;
}
static int T_6 F_136 ( void )
{
int V_14 ;
V_111 = F_137 ( V_9 ) ;
if ( ! V_111 )
return - V_164 ;
V_111 -> V_247 = L_55 ,
V_111 -> V_248 = L_56 ,
V_111 -> V_249 = V_250 ,
V_111 -> V_251 = 0 ,
V_111 -> type = V_252 ,
V_111 -> V_253 = V_254 ,
V_111 -> V_29 = V_255 | V_256 ;
V_111 -> V_257 = V_258 ;
V_111 -> V_257 . V_145 = V_259 | V_156 | V_260 |
V_261 | V_157 ;
F_138 ( V_111 , & V_262 ) ;
V_14 = F_139 ( V_111 ) ;
if ( V_14 ) {
F_140 ( V_111 ) ;
return V_14 ;
}
V_14 = F_141 ( & V_240 ) ;
if ( V_14 ) {
F_142 ( V_111 ) ;
F_140 ( V_111 ) ;
return V_14 ;
}
F_143 (KERN_INFO KBUILD_MODNAME L_57 DRIVER_DESC L_58 ) ;
return 0 ;
}
static void T_7 F_144 ( void )
{
F_145 ( & V_240 ) ;
F_142 ( V_111 ) ;
F_140 ( V_111 ) ;
}
