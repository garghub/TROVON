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
V_14 = F_48 ( V_56 ) ;
if ( V_14 )
goto V_94;
V_56 -> V_95 = V_1 ;
F_49 ( V_93 ) ;
V_56 -> V_96 ++ ;
V_93 -> V_97 [ V_56 -> V_2 ] = V_56 ;
return 0 ;
V_94:
F_50 ( & V_1 -> V_7 ) ;
return V_14 ;
}
static int F_51 ( struct V_55 * V_56 , struct V_98 * V_99 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( V_56 -> V_15 , L_19 , V_21 ) ;
return F_52 ( & V_1 -> V_7 , V_56 , V_99 ) ;
}
static int F_53 ( struct V_100 * V_7 , struct V_55 * V_56 )
{
struct V_1 * V_1 = F_45 ( V_7 , struct V_1 , V_7 ) ;
int V_14 = - V_40 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( V_1 -> V_6 )
goto V_6;
V_14 = F_54 ( V_1 -> V_17 ) ;
if ( V_14 )
goto V_101;
F_36 ( V_102 , & V_56 -> V_29 ) ;
V_1 -> V_17 -> V_103 = 1 ;
V_1 -> V_104 -> V_15 = V_1 -> V_15 ;
if ( F_18 ( V_1 -> V_104 , V_105 ) ) {
F_19 ( & V_1 -> V_17 -> V_15 ,
L_20 , V_21 ) ;
goto V_106;
}
V_1 -> V_107 = V_108 | V_109 ;
if ( F_55 ( V_1 , V_1 -> V_107 ) < 0 &&
( V_1 -> V_48 & V_110 ) )
goto V_111;
F_56 ( V_1 -> V_17 ) ;
if ( F_37 ( V_1 , V_105 ) )
goto V_112;
F_3 ( & V_1 -> V_5 ) ;
return 0 ;
V_112:
V_1 -> V_107 = 0 ;
F_55 ( V_1 , V_1 -> V_107 ) ;
V_111:
F_57 ( V_1 -> V_104 ) ;
V_106:
F_56 ( V_1 -> V_17 ) ;
V_101:
V_6:
F_3 ( & V_1 -> V_5 ) ;
return V_14 ;
}
static void F_58 ( struct V_100 * V_7 )
{
struct V_1 * V_1 = F_45 ( V_7 , struct V_1 , V_7 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_59 ( V_113 , V_1 -> V_8 ) ;
F_6 ( V_1 ) ;
F_60 ( V_1 -> V_17 ) ;
F_61 ( V_1 -> V_49 ) ;
F_61 ( V_1 ) ;
}
static void F_62 ( struct V_100 * V_7 )
{
struct V_1 * V_1 = F_45 ( V_7 , struct V_1 , V_7 ) ;
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_2 ( & V_1 -> V_5 ) ;
if ( ! V_1 -> V_6 ) {
F_54 ( V_1 -> V_17 ) ;
F_55 ( V_1 , V_1 -> V_107 = 0 ) ;
F_57 ( V_1 -> V_104 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_57 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_57 ( V_1 -> V_80 [ V_22 ] ) ;
V_1 -> V_17 -> V_103 = 0 ;
F_56 ( V_1 -> V_17 ) ;
}
F_3 ( & V_1 -> V_5 ) ;
}
static void F_63 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_50 ( & V_1 -> V_7 ) ;
}
static void F_64 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_65 ( & V_1 -> V_7 ) ;
}
static void F_66 ( struct V_55 * V_56 , struct V_98 * V_99 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_67 ( & V_1 -> V_7 , V_56 , V_99 ) ;
}
static int F_68 ( struct V_55 * V_56 ,
const unsigned char * V_12 , int V_96 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
int V_114 ;
unsigned long V_29 ;
int V_23 ;
struct V_24 * V_25 ;
if ( ! V_96 )
return 0 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_21 , V_21 , V_96 ) ;
F_13 ( & V_1 -> V_30 , V_29 ) ;
V_23 = F_11 ( V_1 ) ;
if ( V_23 < 0 ) {
F_14 ( & V_1 -> V_30 , V_29 ) ;
return 0 ;
}
V_25 = & V_1 -> V_25 [ V_23 ] ;
V_96 = ( V_96 > V_1 -> V_115 ) ? V_1 -> V_115 : V_96 ;
F_21 ( & V_1 -> V_39 -> V_15 , L_22 , V_21 , V_96 ) ;
memcpy ( V_25 -> V_12 , V_12 , V_96 ) ;
V_25 -> V_13 = V_96 ;
F_14 ( & V_1 -> V_30 , V_29 ) ;
V_114 = F_20 ( V_1 , V_23 ) ;
if ( V_114 < 0 )
return V_114 ;
return V_96 ;
}
static int F_69 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
return F_12 ( V_1 ) ? V_1 -> V_115 : 0 ;
}
static int F_70 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
if ( V_1 -> V_6 )
return 0 ;
return ( V_27 - F_12 ( V_1 ) ) * V_1 -> V_115 ;
}
static void F_71 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
F_72 ( & V_1 -> V_87 ) ;
V_1 -> V_89 = 1 ;
F_73 ( & V_1 -> V_87 ) ;
}
static void F_74 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
unsigned int V_116 ;
F_72 ( & V_1 -> V_87 ) ;
V_116 = V_1 -> V_88 ;
V_1 -> V_88 = 0 ;
V_1 -> V_89 = 0 ;
F_73 ( & V_1 -> V_87 ) ;
if ( V_116 )
F_37 ( V_1 , V_105 ) ;
}
static int F_75 ( struct V_55 * V_56 , int V_117 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
int V_14 ;
V_14 = F_76 ( V_1 , V_117 ? 0xffff : 0 ) ;
if ( V_14 < 0 )
F_10 ( & V_1 -> V_17 -> V_15 , L_23 ,
V_21 ) ;
return V_14 ;
}
static int F_77 ( struct V_55 * V_56 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
return ( V_1 -> V_107 & V_108 ? V_118 : 0 ) |
( V_1 -> V_107 & V_109 ? V_119 : 0 ) |
( V_1 -> V_67 & V_69 ? V_120 : 0 ) |
( V_1 -> V_67 & V_71 ? V_121 : 0 ) |
( V_1 -> V_67 & V_68 ? V_122 : 0 ) |
V_123 ;
}
static int F_78 ( struct V_55 * V_56 ,
unsigned int V_124 , unsigned int V_125 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
unsigned int V_57 ;
V_57 = V_1 -> V_107 ;
V_124 = ( V_124 & V_118 ? V_108 : 0 ) |
( V_124 & V_119 ? V_109 : 0 ) ;
V_125 = ( V_125 & V_118 ? V_108 : 0 ) |
( V_125 & V_119 ? V_109 : 0 ) ;
V_57 = ( V_57 & ~ V_125 ) | V_124 ;
if ( V_1 -> V_107 == V_57 )
return 0 ;
return F_55 ( V_1 , V_1 -> V_107 = V_57 ) ;
}
static int F_79 ( struct V_55 * V_56 ,
unsigned int V_126 , unsigned long V_127 )
{
return - V_128 ;
}
static void F_80 ( struct V_55 * V_56 ,
struct V_129 * V_130 )
{
struct V_1 * V_1 = V_56 -> V_95 ;
struct V_129 * V_131 = V_56 -> V_131 ;
struct V_132 V_133 ;
int V_57 = V_1 -> V_107 ;
V_133 . V_134 = F_81 ( F_82 ( V_56 ) ) ;
V_133 . V_135 = V_131 -> V_136 & V_137 ? 2 : 0 ;
V_133 . V_138 = V_131 -> V_136 & V_139 ?
( V_131 -> V_136 & V_140 ? 1 : 2 ) +
( V_131 -> V_136 & V_141 ? 2 : 0 ) : 0 ;
V_133 . V_142 = V_143 [ ( V_131 -> V_136 & V_144 ) >> 4 ] ;
V_1 -> V_66 = ( ( V_131 -> V_136 & V_145 ) != 0 ) ;
if ( ! V_133 . V_134 ) {
V_133 . V_134 = V_1 -> line . V_134 ;
V_57 &= ~ V_108 ;
} else
V_57 |= V_108 ;
if ( V_57 != V_1 -> V_107 )
F_55 ( V_1 , V_1 -> V_107 = V_57 ) ;
if ( memcmp ( & V_1 -> line , & V_133 , sizeof V_133 ) ) {
memcpy ( & V_1 -> line , & V_133 , sizeof V_133 ) ;
F_10 ( & V_1 -> V_17 -> V_15 , L_24 ,
V_21 ,
F_83 ( V_133 . V_134 ) ,
V_133 . V_135 , V_133 . V_138 ,
V_133 . V_142 ) ;
F_84 ( V_1 , & V_1 -> line ) ;
}
}
static void F_85 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
struct V_146 * V_147 = F_86 ( V_1 -> V_17 ) ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ )
F_87 ( V_147 , V_1 -> V_115 , V_25 -> V_12 , V_25 -> V_36 ) ;
}
static void F_88 ( struct V_1 * V_1 )
{
struct V_146 * V_147 = F_86 ( V_1 -> V_17 ) ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_87 ( V_147 , V_1 -> V_148 ,
V_1 -> V_149 [ V_22 ] . V_150 , V_1 -> V_149 [ V_22 ] . V_151 ) ;
}
static int F_89 ( struct V_1 * V_1 )
{
int V_22 ;
struct V_24 * V_25 ;
for ( V_25 = & V_1 -> V_25 [ 0 ] , V_22 = 0 ; V_22 < V_27 ; V_22 ++ , V_25 ++ ) {
V_25 -> V_12 = F_90 ( V_1 -> V_15 , V_1 -> V_115 , V_105 ,
& V_25 -> V_36 ) ;
if ( ! V_25 -> V_12 ) {
while ( V_22 != 0 ) {
-- V_22 ;
-- V_25 ;
F_87 ( V_1 -> V_15 , V_1 -> V_115 ,
V_25 -> V_12 , V_25 -> V_36 ) ;
}
return - V_152 ;
}
}
return 0 ;
}
static int F_91 ( struct V_46 * V_47 ,
const struct V_153 * V_154 )
{
struct V_155 * V_156 = NULL ;
struct V_157 * V_158 = NULL ;
unsigned char * V_159 = V_47 -> V_18 -> V_160 ;
int V_161 = V_47 -> V_18 -> V_162 ;
struct V_46 * V_163 ;
struct V_46 * V_164 ;
struct V_165 * V_166 = NULL ;
struct V_165 * V_167 = NULL ;
struct V_165 * V_168 = NULL ;
struct V_146 * V_147 = F_86 ( V_47 ) ;
struct V_1 * V_1 ;
int V_8 ;
int V_169 , V_148 ;
T_3 * V_12 ;
T_3 V_170 = 0 ;
T_3 V_171 = 0 ;
int V_172 = - 1 ;
int V_173 = - 1 ;
unsigned long V_174 ;
int V_175 ;
int V_22 ;
int V_176 = 0 ;
V_174 = ( unsigned long ) V_154 -> V_177 ;
V_175 = ( V_174 == V_178 ) ? 1 : V_179 ;
if ( V_174 == V_180 ) {
V_164 = F_92 ( V_147 , 1 ) ;
V_163 = F_92 ( V_147 , 0 ) ;
goto V_181;
}
if ( ! V_159 ) {
F_19 ( & V_47 -> V_15 , L_25 ) ;
return - V_182 ;
}
if ( ! V_161 ) {
if ( V_47 -> V_183 -> V_184 &&
V_47 -> V_183 -> V_184 -> V_162 &&
V_47 -> V_183 -> V_184 -> V_160 ) {
F_10 ( & V_47 -> V_15 ,
L_26 ) ;
V_161 = V_47 -> V_183 -> V_184 -> V_162 ;
V_159 = V_47 -> V_183 -> V_184 -> V_160 ;
} else {
F_19 ( & V_47 -> V_15 ,
L_27 ) ;
return - V_182 ;
}
}
while ( V_161 > 0 ) {
if ( V_159 [ 1 ] != V_185 ) {
F_19 ( & V_47 -> V_15 , L_28 ) ;
goto V_186;
}
switch ( V_159 [ 2 ] ) {
case V_187 :
if ( V_156 ) {
F_19 ( & V_47 -> V_15 , L_29
L_30 ) ;
goto V_186;
}
V_156 = (struct V_155 * ) V_159 ;
break;
case V_188 :
V_158 = (struct V_157 * ) V_159 ;
break;
case V_189 :
break;
case V_190 :
V_170 = V_159 [ 3 ] ;
break;
case V_191 :
V_171 = V_159 [ 3 ] ;
V_172 = V_159 [ 4 ] ;
if ( ( V_174 & V_192 ) == 0 && ( V_171 & 3 ) != 3 )
F_19 ( & V_47 -> V_15 , L_31 ) ;
break;
default:
F_10 ( & V_47 -> V_15 , L_32
L_33 ,
V_159 [ 2 ] , V_159 [ 0 ] ) ;
break;
}
V_186:
V_161 -= V_159 [ 0 ] ;
V_159 += V_159 [ 0 ] ;
}
if ( ! V_156 ) {
if ( V_172 > 0 ) {
F_10 ( & V_47 -> V_15 , L_34 ) ;
if ( V_174 & V_193 )
V_164 = F_92 ( V_147 , 0 ) ;
else
V_164 = F_92 ( V_147 , ( V_173 = V_172 ) ) ;
V_163 = V_47 ;
} else {
if ( V_47 -> V_183 -> V_19 . V_194 != 3 ) {
F_10 ( & V_47 -> V_15 , L_35 ) ;
return - V_40 ;
} else {
F_93 ( & V_47 -> V_15 , L_36 ) ;
V_176 = 1 ;
V_163 = V_164 = V_47 ;
goto V_195;
}
}
} else {
V_163 = F_92 ( V_147 , V_156 -> V_196 ) ;
V_164 = F_92 ( V_147 , ( V_173 = V_156 -> V_197 ) ) ;
if ( ! V_163 || ! V_164 ) {
F_10 ( & V_47 -> V_15 , L_37 ) ;
return - V_40 ;
}
}
if ( V_173 != V_172 )
F_10 ( & V_47 -> V_15 , L_38 ) ;
if ( V_163 == V_164 ) {
F_93 ( & V_47 -> V_15 , L_39 ) ;
V_176 = 1 ;
V_174 |= V_198 ;
if ( V_164 -> V_183 -> V_19 . V_194 != 3 ) {
F_19 ( & V_47 -> V_15 , L_40 ) ;
return - V_182 ;
}
V_195:
for ( V_22 = 0 ; V_22 < 3 ; V_22 ++ ) {
struct V_165 * V_199 ;
V_199 = & V_164 -> V_183 -> V_184 [ V_22 ] . V_19 ;
if ( F_94 ( V_199 ) )
V_166 = V_199 ;
else if ( F_95 ( V_199 ) )
V_168 = V_199 ;
else if ( F_96 ( V_199 ) )
V_167 = V_199 ;
else
return - V_182 ;
}
if ( ! V_166 || ! V_167 || ! V_168 )
return - V_40 ;
else
goto V_200;
}
V_181:
if ( V_164 -> V_183 -> V_19 . V_201
!= V_202 ) {
if ( V_163 -> V_183 -> V_19 . V_201
== V_202 ) {
struct V_46 * V_203 ;
F_10 ( & V_47 -> V_15 ,
L_41 ) ;
V_203 = V_163 ;
V_163 = V_164 ;
V_164 = V_203 ;
} else {
return - V_182 ;
}
}
if ( ! V_176 && V_47 != V_163 )
return - V_40 ;
if ( ! V_176 && F_97 ( V_164 ) ) {
F_10 ( & V_47 -> V_15 , L_42 ) ;
return - V_204 ;
}
if ( V_164 -> V_183 -> V_19 . V_194 < 2 )
return - V_182 ;
V_166 = & V_163 -> V_183 -> V_184 [ 0 ] . V_19 ;
V_167 = & V_164 -> V_183 -> V_184 [ 0 ] . V_19 ;
V_168 = & V_164 -> V_183 -> V_184 [ 1 ] . V_19 ;
if ( ! F_98 ( V_167 ) ) {
struct V_165 * V_203 ;
F_10 ( & V_47 -> V_15 ,
L_43 ) ;
V_203 = V_167 ;
V_167 = V_168 ;
V_168 = V_203 ;
}
V_200:
F_10 ( & V_47 -> V_15 , L_44 ) ;
V_1 = F_99 ( sizeof( struct V_1 ) , V_105 ) ;
if ( V_1 == NULL ) {
F_19 ( & V_47 -> V_15 , L_45 ) ;
goto V_205;
}
V_8 = F_5 ( V_1 ) ;
if ( V_8 == V_9 ) {
F_19 ( & V_47 -> V_15 , L_46 ) ;
F_61 ( V_1 ) ;
return - V_40 ;
}
V_169 = F_100 ( V_166 ) ;
V_148 = F_100 ( V_167 ) *
( V_174 == V_178 ? 1 : 2 ) ;
V_1 -> V_176 = V_176 ;
V_1 -> V_115 = F_100 ( V_168 ) * 20 ;
V_1 -> V_17 = V_163 ;
V_1 -> V_39 = V_164 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_15 = V_147 ;
V_1 -> V_48 = V_170 ;
if ( V_174 & V_198 )
V_1 -> V_48 &= ~ V_110 ;
V_1 -> V_169 = V_169 ;
V_1 -> V_148 = V_148 ;
V_1 -> V_82 = V_175 ;
F_101 ( & V_1 -> V_90 , F_44 ) ;
F_102 ( & V_1 -> V_30 ) ;
F_102 ( & V_1 -> V_87 ) ;
F_103 ( & V_1 -> V_5 ) ;
V_1 -> V_206 = F_104 ( V_147 , V_167 -> V_207 ) ;
V_1 -> V_208 = F_105 ( V_167 ) ;
if ( V_1 -> V_208 )
V_1 -> V_209 = V_167 -> V_209 ;
F_106 ( & V_1 -> V_7 ) ;
V_1 -> V_7 . V_210 = & V_211 ;
V_12 = F_90 ( V_147 , V_169 , V_105 , & V_1 -> V_212 ) ;
if ( ! V_12 ) {
F_19 ( & V_47 -> V_15 , L_47 ) ;
goto V_213;
}
V_1 -> V_214 = V_12 ;
if ( F_89 ( V_1 ) < 0 ) {
F_19 ( & V_47 -> V_15 , L_48 ) ;
goto V_215;
}
V_1 -> V_104 = F_107 ( 0 , V_105 ) ;
if ( ! V_1 -> V_104 ) {
F_19 ( & V_47 -> V_15 , L_49 ) ;
goto V_216;
}
for ( V_22 = 0 ; V_22 < V_175 ; V_22 ++ ) {
struct V_84 * V_85 = & ( V_1 -> V_149 [ V_22 ] ) ;
struct V_33 * V_33 ;
V_85 -> V_150 = F_90 ( V_1 -> V_15 , V_148 , V_105 ,
& V_85 -> V_151 ) ;
if ( ! V_85 -> V_150 ) {
F_19 ( & V_47 -> V_15 , L_50
L_51 ) ;
goto V_217;
}
V_85 -> V_2 = V_22 ;
V_85 -> V_86 = V_1 ;
V_33 = F_107 ( 0 , V_105 ) ;
if ( ! V_33 ) {
F_19 ( & V_47 -> V_15 ,
L_52 ) ;
goto V_217;
}
V_33 -> V_218 |= V_219 ;
V_33 -> V_35 = V_85 -> V_151 ;
if ( V_1 -> V_208 ) {
F_108 ( V_33 , V_1 -> V_15 ,
V_1 -> V_206 ,
V_85 -> V_150 ,
V_1 -> V_148 ,
F_41 , V_85 ,
V_1 -> V_209 ) ;
} else {
F_109 ( V_33 , V_1 -> V_15 ,
V_1 -> V_206 ,
V_85 -> V_150 ,
V_1 -> V_148 ,
F_41 , V_85 ) ;
}
V_1 -> V_80 [ V_22 ] = V_33 ;
F_110 ( V_22 , & V_1 -> V_79 ) ;
}
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ ) {
struct V_24 * V_220 = & ( V_1 -> V_25 [ V_22 ] ) ;
V_220 -> V_33 = F_107 ( 0 , V_105 ) ;
if ( V_220 -> V_33 == NULL ) {
F_19 ( & V_47 -> V_15 ,
L_53 ) ;
goto V_221;
}
if ( F_105 ( V_168 ) )
F_108 ( V_220 -> V_33 , V_147 ,
F_111 ( V_147 , V_168 -> V_207 ) ,
NULL , V_1 -> V_115 , F_42 , V_220 , V_168 -> V_209 ) ;
else
F_109 ( V_220 -> V_33 , V_147 ,
F_111 ( V_147 , V_168 -> V_207 ) ,
NULL , V_1 -> V_115 , F_42 , V_220 ) ;
V_220 -> V_33 -> V_218 |= V_219 ;
V_220 -> V_86 = V_1 ;
}
F_112 ( V_47 , V_1 ) ;
V_22 = F_113 ( & V_47 -> V_15 , & V_222 ) ;
if ( V_22 < 0 )
goto V_221;
if ( V_158 ) {
V_1 -> V_49 = F_114 ( V_158 -> V_223 - 4 , V_105 ) ;
if ( ! V_1 -> V_49 )
goto V_224;
V_1 -> V_50 = V_158 -> V_223 - 4 ;
memcpy ( V_1 -> V_49 , ( T_3 * ) & V_158 -> V_225 ,
V_158 -> V_223 - 4 ) ;
V_1 -> V_51 = V_158 -> V_226 ;
V_22 = F_113 ( & V_47 -> V_15 , & V_227 ) ;
if ( V_22 < 0 ) {
F_61 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
V_1 -> V_50 = 0 ;
goto V_224;
}
V_22 = F_113 ( & V_47 -> V_15 ,
& V_228 ) ;
if ( V_22 < 0 ) {
F_115 ( & V_47 -> V_15 , & V_227 ) ;
F_61 ( V_1 -> V_49 ) ;
V_1 -> V_49 = NULL ;
V_1 -> V_50 = 0 ;
goto V_224;
}
}
V_224:
F_108 ( V_1 -> V_104 , V_147 ,
F_116 ( V_147 , V_166 -> V_207 ) ,
V_1 -> V_214 , V_169 , F_29 , V_1 ,
V_166 -> V_209 ? V_166 -> V_209 : 0xff ) ;
V_1 -> V_104 -> V_218 |= V_219 ;
V_1 -> V_104 -> V_35 = V_1 -> V_212 ;
F_117 ( & V_47 -> V_15 , L_54 , V_8 ) ;
F_55 ( V_1 , V_1 -> V_107 ) ;
V_1 -> line . V_134 = F_81 ( 9600 ) ;
V_1 -> line . V_142 = 8 ;
F_84 ( V_1 , & V_1 -> line ) ;
F_118 ( & V_229 , V_164 , V_1 ) ;
F_112 ( V_164 , V_1 ) ;
F_119 ( V_163 ) ;
F_120 ( V_113 , V_8 , & V_163 -> V_15 ) ;
return 0 ;
V_221:
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_121 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
V_217:
for ( V_22 = 0 ; V_22 < V_175 ; V_22 ++ )
F_121 ( V_1 -> V_80 [ V_22 ] ) ;
F_88 ( V_1 ) ;
F_121 ( V_1 -> V_104 ) ;
V_216:
F_85 ( V_1 ) ;
V_215:
F_87 ( V_147 , V_169 , V_1 -> V_214 , V_1 -> V_212 ) ;
V_213:
F_6 ( V_1 ) ;
F_61 ( V_1 ) ;
V_205:
return - V_152 ;
}
static void F_122 ( struct V_1 * V_1 )
{
int V_22 ;
F_10 ( & V_1 -> V_17 -> V_15 , L_19 , V_21 ) ;
F_57 ( V_1 -> V_104 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_57 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_57 ( V_1 -> V_80 [ V_22 ] ) ;
F_123 ( & V_1 -> V_90 ) ;
}
static void F_124 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_146 * V_147 = F_86 ( V_47 ) ;
struct V_55 * V_56 ;
int V_22 ;
F_10 ( & V_47 -> V_15 , L_19 , V_21 ) ;
if ( ! V_1 )
return;
F_2 ( & V_1 -> V_5 ) ;
V_1 -> V_6 = true ;
if ( V_1 -> V_49 ) {
F_115 ( & V_1 -> V_17 -> V_15 ,
& V_227 ) ;
F_115 ( & V_1 -> V_17 -> V_15 ,
& V_228 ) ;
}
F_115 ( & V_1 -> V_17 -> V_15 , & V_222 ) ;
F_112 ( V_1 -> V_17 , NULL ) ;
F_112 ( V_1 -> V_39 , NULL ) ;
F_3 ( & V_1 -> V_5 ) ;
V_56 = F_30 ( & V_1 -> V_7 ) ;
if ( V_56 ) {
F_125 ( V_56 ) ;
F_33 ( V_56 ) ;
}
F_122 ( V_1 ) ;
F_121 ( V_1 -> V_104 ) ;
for ( V_22 = 0 ; V_22 < V_27 ; V_22 ++ )
F_121 ( V_1 -> V_25 [ V_22 ] . V_33 ) ;
for ( V_22 = 0 ; V_22 < V_1 -> V_82 ; V_22 ++ )
F_121 ( V_1 -> V_80 [ V_22 ] ) ;
F_85 ( V_1 ) ;
F_87 ( V_147 , V_1 -> V_169 , V_1 -> V_214 , V_1 -> V_212 ) ;
F_88 ( V_1 ) ;
if ( ! V_1 -> V_176 )
F_126 ( & V_229 , V_47 == V_1 -> V_17 ?
V_1 -> V_39 : V_1 -> V_17 ) ;
F_50 ( & V_1 -> V_7 ) ;
}
static int F_127 ( struct V_46 * V_47 , T_4 V_230 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
int V_231 ;
if ( F_128 ( V_230 ) ) {
int V_232 ;
F_72 ( & V_1 -> V_30 ) ;
V_232 = V_1 -> V_31 ;
F_73 ( & V_1 -> V_30 ) ;
if ( V_232 )
return - V_204 ;
}
F_72 ( & V_1 -> V_87 ) ;
F_129 ( & V_1 -> V_30 ) ;
V_231 = V_1 -> V_41 ++ ;
F_130 ( & V_1 -> V_30 ) ;
F_73 ( & V_1 -> V_87 ) ;
if ( V_231 )
return 0 ;
if ( F_131 ( V_233 , & V_1 -> V_7 . V_29 ) )
F_122 ( V_1 ) ;
return 0 ;
}
static int F_132 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_24 * V_25 ;
int V_234 = 0 ;
int V_231 ;
F_72 ( & V_1 -> V_87 ) ;
V_1 -> V_41 -= 1 ;
V_231 = V_1 -> V_41 ;
F_73 ( & V_1 -> V_87 ) ;
if ( V_231 )
return 0 ;
if ( F_131 ( V_233 , & V_1 -> V_7 . V_29 ) ) {
V_234 = F_18 ( V_1 -> V_104 , V_235 ) ;
F_72 ( & V_1 -> V_30 ) ;
if ( V_1 -> V_42 ) {
V_25 = V_1 -> V_42 ;
V_1 -> V_42 = NULL ;
F_73 ( & V_1 -> V_30 ) ;
F_17 ( V_1 , V_25 ) ;
} else {
F_73 ( & V_1 -> V_30 ) ;
}
if ( V_234 < 0 )
goto V_236;
V_234 = F_37 ( V_1 , V_235 ) ;
}
V_236:
return V_234 ;
}
static int F_133 ( struct V_46 * V_47 )
{
struct V_1 * V_1 = F_26 ( V_47 ) ;
struct V_55 * V_56 ;
if ( F_131 ( V_233 , & V_1 -> V_7 . V_29 ) ) {
V_56 = F_30 ( & V_1 -> V_7 ) ;
if ( V_56 ) {
F_32 ( V_56 ) ;
F_33 ( V_56 ) ;
}
}
return F_132 ( V_47 ) ;
}
static int T_5 F_134 ( void )
{
int V_14 ;
V_113 = F_135 ( V_9 ) ;
if ( ! V_113 )
return - V_152 ;
V_113 -> V_237 = V_238 ,
V_113 -> V_239 = L_55 ,
V_113 -> V_240 = L_56 ,
V_113 -> V_241 = V_242 ,
V_113 -> V_243 = 0 ,
V_113 -> type = V_244 ,
V_113 -> V_245 = V_246 ,
V_113 -> V_29 = V_247 | V_248 ;
V_113 -> V_249 = V_250 ;
V_113 -> V_249 . V_136 = V_251 | V_252 | V_253 |
V_254 | V_145 ;
F_136 ( V_113 , & V_255 ) ;
V_14 = F_137 ( V_113 ) ;
if ( V_14 ) {
F_138 ( V_113 ) ;
return V_14 ;
}
V_14 = F_139 ( & V_229 ) ;
if ( V_14 ) {
F_140 ( V_113 ) ;
F_138 ( V_113 ) ;
return V_14 ;
}
F_141 (KERN_INFO KBUILD_MODNAME L_57 DRIVER_DESC L_58 ) ;
return 0 ;
}
static void T_6 F_142 ( void )
{
F_143 ( & V_229 ) ;
F_140 ( V_113 ) ;
F_138 ( V_113 ) ;
}
