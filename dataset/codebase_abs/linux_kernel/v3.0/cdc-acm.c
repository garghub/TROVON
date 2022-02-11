static int F_1 ( struct V_1 * V_1 , int V_2 , int V_3 ,
void * V_4 , int V_5 )
{
int V_6 = F_2 ( V_1 -> V_7 , F_3 ( V_1 -> V_7 , 0 ) ,
V_2 , V_8 , V_3 ,
V_1 -> V_9 -> V_10 [ 0 ] . V_11 . V_12 ,
V_4 , V_5 , 5000 ) ;
F_4 ( & V_1 -> V_9 -> V_7 ,
L_1 ,
V_13 , V_2 , V_3 , V_5 , V_6 ) ;
return V_6 < 0 ? V_6 : 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
int V_14 , V_15 ;
struct V_16 * V_17 ;
V_15 = 0 ;
V_14 = 0 ;
for (; ; ) {
V_17 = & V_1 -> V_17 [ V_15 ] ;
if ( ! V_17 -> V_18 ) {
V_17 -> V_18 = 1 ;
return V_15 ;
}
V_15 = ( V_15 + 1 ) % V_19 ;
if ( ++ V_14 >= V_19 )
return - 1 ;
}
}
static int F_6 ( struct V_1 * V_1 )
{
int V_14 , V_20 ;
unsigned long V_21 ;
V_20 = V_19 ;
F_7 ( & V_1 -> V_22 , V_21 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
V_20 -= V_1 -> V_17 [ V_14 ] . V_18 ;
F_8 ( & V_1 -> V_22 , V_21 ) ;
return V_20 ;
}
static void F_9 ( struct V_1 * V_1 , struct V_16 * V_17 )
{
V_17 -> V_18 = 0 ;
V_1 -> V_23 -- ;
F_10 ( V_1 -> V_9 ) ;
}
static int F_11 ( struct V_1 * V_1 , struct V_16 * V_17 )
{
int V_24 ;
V_1 -> V_23 ++ ;
V_17 -> V_25 -> V_26 = V_17 -> V_4 ;
V_17 -> V_25 -> V_27 = V_17 -> V_28 ;
V_17 -> V_25 -> V_29 = V_17 -> V_5 ;
V_17 -> V_25 -> V_7 = V_1 -> V_7 ;
V_24 = F_12 ( V_17 -> V_25 , V_30 ) ;
if ( V_24 < 0 ) {
F_13 ( & V_1 -> V_31 -> V_7 ,
L_2 ,
V_13 , V_24 ) ;
F_9 ( V_1 , V_17 ) ;
}
return V_24 ;
}
static int F_14 ( struct V_1 * V_1 , int V_15 )
{
unsigned long V_21 ;
struct V_16 * V_17 = & V_1 -> V_17 [ V_15 ] ;
int V_24 ;
F_7 ( & V_1 -> V_22 , V_21 ) ;
if ( ! V_1 -> V_7 ) {
V_17 -> V_18 = 0 ;
F_8 ( & V_1 -> V_22 , V_21 ) ;
return - V_32 ;
}
F_15 ( & V_1 -> V_31 -> V_7 , L_3 , V_13 ,
V_1 -> V_33 ) ;
F_16 ( V_1 -> V_9 ) ;
if ( V_1 -> V_33 ) {
if ( ! V_1 -> V_34 )
V_1 -> V_34 = V_17 ;
else
F_10 ( V_1 -> V_9 ) ;
F_8 ( & V_1 -> V_22 , V_21 ) ;
return 0 ;
}
F_17 ( V_1 -> V_7 ) ;
V_24 = F_11 ( V_1 , V_17 ) ;
F_8 ( & V_1 -> V_22 , V_21 ) ;
return V_24 ;
}
static T_1 F_18
( struct V_35 * V_7 , struct V_36 * V_37 , char * V_4 )
{
struct V_38 * V_39 = F_19 ( V_7 ) ;
struct V_1 * V_1 = F_20 ( V_39 ) ;
return sprintf ( V_4 , L_4 , V_1 -> V_40 ) ;
}
static T_1 F_21
( struct V_35 * V_7 , struct V_36 * V_37 , char * V_4 )
{
struct V_38 * V_39 = F_19 ( V_7 ) ;
struct V_1 * V_1 = F_20 ( V_39 ) ;
memcpy ( V_4 , V_1 -> V_41 , V_1 -> V_42 ) ;
return V_1 -> V_42 ;
}
static T_1 F_22
( struct V_35 * V_7 , struct V_36 * V_37 , char * V_4 )
{
struct V_38 * V_39 = F_19 ( V_7 ) ;
struct V_1 * V_1 = F_20 ( V_39 ) ;
return sprintf ( V_4 , L_4 , V_1 -> V_43 ) ;
}
static void F_23 ( struct V_25 * V_25 )
{
struct V_1 * V_1 = V_25 -> V_44 ;
struct V_45 * V_46 = V_25 -> V_26 ;
struct V_47 * V_48 ;
unsigned char * V_31 ;
int V_49 ;
int V_6 ;
int V_50 = V_25 -> V_50 ;
switch ( V_50 ) {
case 0 :
break;
case - V_51 :
case - V_52 :
case - V_53 :
F_4 ( & V_1 -> V_9 -> V_7 ,
L_5 ,
V_13 , V_50 ) ;
return;
default:
F_4 ( & V_1 -> V_9 -> V_7 ,
L_6 ,
V_13 , V_50 ) ;
goto exit;
}
if ( ! F_24 ( V_1 ) )
goto exit;
F_17 ( V_1 -> V_7 ) ;
V_31 = ( unsigned char * ) ( V_46 + 1 ) ;
switch ( V_46 -> V_54 ) {
case V_55 :
F_4 ( & V_1 -> V_9 -> V_7 , L_7 ,
V_13 , V_46 -> V_56 ) ;
break;
case V_57 :
V_48 = F_25 ( & V_1 -> V_58 ) ;
V_49 = F_26 ( V_31 ) ;
if ( V_48 ) {
if ( ! V_1 -> V_59 &&
( V_1 -> V_60 & ~ V_49 & V_61 ) ) {
F_4 ( & V_1 -> V_9 -> V_7 ,
L_8 , V_13 ) ;
F_27 ( V_48 ) ;
}
F_28 ( V_48 ) ;
}
V_1 -> V_60 = V_49 ;
F_4 ( & V_1 -> V_9 -> V_7 ,
L_9
L_10 ,
V_13 ,
V_1 -> V_60 & V_61 ? '+' : '-' ,
V_1 -> V_60 & V_62 ? '+' : '-' ,
V_1 -> V_60 & V_63 ? '+' : '-' ,
V_1 -> V_60 & V_64 ? '+' : '-' ,
V_1 -> V_60 & V_65 ? '+' : '-' ,
V_1 -> V_60 & V_66 ? '+' : '-' ,
V_1 -> V_60 & V_67 ? '+' : '-' ) ;
break;
default:
F_4 ( & V_1 -> V_9 -> V_7 ,
L_11
L_12 ,
V_13 ,
V_46 -> V_54 , V_46 -> V_68 ,
V_46 -> V_69 , V_31 [ 0 ] , V_31 [ 1 ] ) ;
break;
}
exit:
V_6 = F_12 ( V_25 , V_30 ) ;
if ( V_6 )
F_13 ( & V_1 -> V_9 -> V_7 , L_13 ,
V_13 , V_6 ) ;
}
static int F_29 ( struct V_1 * V_1 , int V_70 , T_2 V_71 )
{
int V_72 ;
if ( ! F_30 ( V_70 , & V_1 -> V_73 ) )
return 0 ;
F_15 ( & V_1 -> V_31 -> V_7 , L_14 , V_13 , V_70 ) ;
V_72 = F_12 ( V_1 -> V_74 [ V_70 ] , V_71 ) ;
if ( V_72 ) {
if ( V_72 != - V_75 ) {
F_13 ( & V_1 -> V_31 -> V_7 ,
L_13 ,
V_13 , V_72 ) ;
}
F_31 ( V_70 , & V_1 -> V_73 ) ;
return V_72 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_2 V_71 )
{
int V_72 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_1 -> V_76 ; ++ V_14 ) {
V_72 = F_29 ( V_1 , V_14 , V_71 ) ;
if ( V_72 )
return V_72 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_1 , struct V_25 * V_25 )
{
struct V_47 * V_48 ;
if ( ! V_25 -> V_77 )
return;
V_48 = F_25 ( & V_1 -> V_58 ) ;
if ( ! V_48 )
return;
F_34 ( V_48 , V_25 -> V_26 , V_25 -> V_77 ) ;
F_35 ( V_48 ) ;
F_28 ( V_48 ) ;
}
static void F_36 ( struct V_25 * V_25 )
{
struct V_78 * V_79 = V_25 -> V_44 ;
struct V_1 * V_1 = V_79 -> V_80 ;
unsigned long V_21 ;
F_15 ( & V_1 -> V_31 -> V_7 , L_15 , V_13 ,
V_79 -> V_70 , V_25 -> V_77 ) ;
F_31 ( V_79 -> V_70 , & V_1 -> V_73 ) ;
if ( ! V_1 -> V_7 ) {
F_4 ( & V_1 -> V_31 -> V_7 , L_16 , V_13 ) ;
return;
}
F_17 ( V_1 -> V_7 ) ;
if ( V_25 -> V_50 ) {
F_4 ( & V_1 -> V_31 -> V_7 , L_17 ,
V_13 , V_25 -> V_50 ) ;
return;
}
F_33 ( V_1 , V_25 ) ;
F_7 ( & V_1 -> V_81 , V_21 ) ;
V_1 -> V_82 = V_1 -> V_83 ;
if ( ! V_1 -> V_82 && ! V_1 -> V_33 ) {
F_8 ( & V_1 -> V_81 , V_21 ) ;
F_29 ( V_1 , V_79 -> V_70 , V_30 ) ;
} else {
F_8 ( & V_1 -> V_81 , V_21 ) ;
}
}
static void F_37 ( struct V_25 * V_25 )
{
struct V_16 * V_17 = V_25 -> V_44 ;
struct V_1 * V_1 = V_17 -> V_80 ;
unsigned long V_21 ;
if ( V_25 -> V_50 || ( V_25 -> V_77 != V_25 -> V_29 ) )
F_15 ( & V_1 -> V_31 -> V_7 , L_18 ,
V_13 ,
V_25 -> V_77 ,
V_25 -> V_29 ,
V_25 -> V_50 ) ;
F_7 ( & V_1 -> V_22 , V_21 ) ;
F_9 ( V_1 , V_17 ) ;
F_8 ( & V_1 -> V_22 , V_21 ) ;
if ( F_24 ( V_1 ) )
F_38 ( & V_1 -> V_84 ) ;
}
static void F_39 ( struct V_85 * V_84 )
{
struct V_1 * V_1 = F_40 ( V_84 , struct V_1 , V_84 ) ;
struct V_47 * V_48 ;
F_15 ( & V_1 -> V_31 -> V_7 , L_19 , V_13 ) ;
if ( ! F_24 ( V_1 ) )
return;
V_48 = F_25 ( & V_1 -> V_58 ) ;
if ( ! V_48 )
return;
F_41 ( V_48 ) ;
F_28 ( V_48 ) ;
}
static int F_42 ( struct V_47 * V_48 , struct V_86 * V_87 )
{
struct V_1 * V_1 ;
int V_88 = - V_32 ;
F_43 ( & V_89 ) ;
V_1 = V_90 [ V_48 -> V_70 ] ;
if ( ! V_1 || ! V_1 -> V_7 )
goto V_91;
else
V_88 = 0 ;
F_4 ( & V_1 -> V_9 -> V_7 , L_19 , V_13 ) ;
F_31 ( V_92 , & V_48 -> V_21 ) ;
V_48 -> V_93 = V_1 ;
F_44 ( & V_1 -> V_58 , V_48 ) ;
if ( F_45 ( V_1 -> V_9 ) < 0 )
goto V_94;
else
V_1 -> V_9 -> V_95 = 1 ;
F_43 ( & V_1 -> V_96 ) ;
if ( V_1 -> V_58 . V_97 ++ ) {
F_46 ( & V_1 -> V_96 ) ;
F_47 ( V_1 -> V_9 ) ;
goto V_91;
}
V_1 -> V_98 -> V_7 = V_1 -> V_7 ;
if ( F_12 ( V_1 -> V_98 , V_99 ) ) {
F_13 ( & V_1 -> V_9 -> V_7 ,
L_20 , V_13 ) ;
goto V_100;
}
if ( 0 > F_48 ( V_1 , V_1 -> V_101 = V_102 | V_103 ) &&
( V_1 -> V_40 & V_104 ) )
goto V_100;
F_47 ( V_1 -> V_9 ) ;
if ( F_32 ( V_1 , V_99 ) )
goto V_100;
F_31 ( V_105 , & V_1 -> V_58 . V_21 ) ;
V_88 = F_49 ( & V_1 -> V_58 , V_48 , V_87 ) ;
F_46 ( & V_1 -> V_96 ) ;
V_91:
F_46 ( & V_89 ) ;
return V_88 ;
V_100:
V_1 -> V_58 . V_97 -- ;
F_46 ( & V_1 -> V_96 ) ;
F_47 ( V_1 -> V_9 ) ;
V_94:
F_46 ( & V_89 ) ;
F_44 ( & V_1 -> V_58 , NULL ) ;
return - V_106 ;
}
static void F_50 ( struct V_1 * V_1 )
{
int V_14 ;
F_51 ( V_107 , V_1 -> V_108 ) ;
F_52 ( V_1 -> V_9 ) ;
V_90 [ V_1 -> V_108 ] = NULL ;
F_53 ( V_1 -> V_98 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
F_53 ( V_1 -> V_17 [ V_14 ] . V_25 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_76 ; V_14 ++ )
F_53 ( V_1 -> V_74 [ V_14 ] ) ;
F_54 ( V_1 -> V_41 ) ;
F_54 ( V_1 ) ;
}
static void F_55 ( struct V_1 * V_1 )
{
int V_14 ;
F_43 ( & V_89 ) ;
if ( V_1 -> V_7 ) {
F_45 ( V_1 -> V_9 ) ;
F_48 ( V_1 , V_1 -> V_101 = 0 ) ;
F_56 ( V_1 -> V_98 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
F_56 ( V_1 -> V_17 [ V_14 ] . V_25 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_76 ; V_14 ++ )
F_56 ( V_1 -> V_74 [ V_14 ] ) ;
V_1 -> V_9 -> V_95 = 0 ;
F_47 ( V_1 -> V_9 ) ;
}
F_46 ( & V_89 ) ;
}
static void F_57 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
F_58 ( & V_1 -> V_58 ) ;
F_55 ( V_1 ) ;
}
static void F_59 ( struct V_47 * V_48 , struct V_86 * V_87 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
if ( ! V_1 )
return;
if ( F_60 ( & V_1 -> V_58 , V_48 , V_87 ) == 0 ) {
F_43 ( & V_89 ) ;
if ( ! V_1 -> V_7 ) {
F_44 ( & V_1 -> V_58 , NULL ) ;
F_50 ( V_1 ) ;
V_48 -> V_93 = NULL ;
}
F_46 ( & V_89 ) ;
return;
}
F_55 ( V_1 ) ;
F_61 ( & V_1 -> V_58 , V_48 ) ;
F_44 ( & V_1 -> V_58 , NULL ) ;
}
static int F_62 ( struct V_47 * V_48 ,
const unsigned char * V_4 , int V_97 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
int V_109 ;
unsigned long V_21 ;
int V_15 ;
struct V_16 * V_17 ;
if ( ! F_24 ( V_1 ) )
return - V_110 ;
if ( ! V_97 )
return 0 ;
F_15 ( & V_1 -> V_31 -> V_7 , L_21 , V_13 , V_97 ) ;
F_7 ( & V_1 -> V_22 , V_21 ) ;
V_15 = F_5 ( V_1 ) ;
if ( V_15 < 0 ) {
F_8 ( & V_1 -> V_22 , V_21 ) ;
return 0 ;
}
V_17 = & V_1 -> V_17 [ V_15 ] ;
V_97 = ( V_97 > V_1 -> V_111 ) ? V_1 -> V_111 : V_97 ;
F_15 ( & V_1 -> V_31 -> V_7 , L_22 , V_13 , V_97 ) ;
memcpy ( V_17 -> V_4 , V_4 , V_97 ) ;
V_17 -> V_5 = V_97 ;
F_8 ( & V_1 -> V_22 , V_21 ) ;
V_109 = F_14 ( V_1 , V_15 ) ;
if ( V_109 < 0 )
return V_109 ;
return V_97 ;
}
static int F_63 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
if ( ! F_24 ( V_1 ) )
return - V_110 ;
return F_6 ( V_1 ) ? V_1 -> V_111 : 0 ;
}
static int F_64 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
if ( ! F_24 ( V_1 ) )
return 0 ;
return ( V_19 - F_6 ( V_1 ) ) * V_1 -> V_111 ;
}
static void F_65 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
if ( ! F_24 ( V_1 ) )
return;
F_66 ( & V_1 -> V_81 ) ;
V_1 -> V_83 = 1 ;
F_67 ( & V_1 -> V_81 ) ;
}
static void F_68 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
unsigned int V_112 ;
if ( ! F_24 ( V_1 ) )
return;
F_66 ( & V_1 -> V_81 ) ;
V_112 = V_1 -> V_82 ;
V_1 -> V_82 = 0 ;
V_1 -> V_83 = 0 ;
F_67 ( & V_1 -> V_81 ) ;
if ( V_112 )
F_32 ( V_1 , V_99 ) ;
}
static int F_69 ( struct V_47 * V_48 , int V_113 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
int V_6 ;
if ( ! F_24 ( V_1 ) )
return - V_110 ;
V_6 = F_70 ( V_1 , V_113 ? 0xffff : 0 ) ;
if ( V_6 < 0 )
F_4 ( & V_1 -> V_9 -> V_7 , L_23 ,
V_13 ) ;
return V_6 ;
}
static int F_71 ( struct V_47 * V_48 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
if ( ! F_24 ( V_1 ) )
return - V_110 ;
return ( V_1 -> V_101 & V_102 ? V_114 : 0 ) |
( V_1 -> V_101 & V_103 ? V_115 : 0 ) |
( V_1 -> V_60 & V_62 ? V_116 : 0 ) |
( V_1 -> V_60 & V_64 ? V_117 : 0 ) |
( V_1 -> V_60 & V_61 ? V_118 : 0 ) |
V_119 ;
}
static int F_72 ( struct V_47 * V_48 ,
unsigned int V_120 , unsigned int V_121 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
unsigned int V_49 ;
if ( ! F_24 ( V_1 ) )
return - V_110 ;
V_49 = V_1 -> V_101 ;
V_120 = ( V_120 & V_114 ? V_102 : 0 ) |
( V_120 & V_115 ? V_103 : 0 ) ;
V_121 = ( V_121 & V_114 ? V_102 : 0 ) |
( V_121 & V_115 ? V_103 : 0 ) ;
V_49 = ( V_49 & ~ V_121 ) | V_120 ;
if ( V_1 -> V_101 == V_49 )
return 0 ;
return F_48 ( V_1 , V_1 -> V_101 = V_49 ) ;
}
static int F_73 ( struct V_47 * V_48 ,
unsigned int V_122 , unsigned long V_123 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
if ( ! F_24 ( V_1 ) )
return - V_110 ;
return - V_124 ;
}
static void F_74 ( struct V_47 * V_48 ,
struct V_125 * V_126 )
{
struct V_1 * V_1 = V_48 -> V_93 ;
struct V_125 * V_127 = V_48 -> V_127 ;
struct V_128 V_129 ;
int V_49 = V_1 -> V_101 ;
if ( ! F_24 ( V_1 ) )
return;
V_129 . V_130 = F_75 ( F_76 ( V_48 ) ) ;
V_129 . V_131 = V_127 -> V_132 & V_133 ? 2 : 0 ;
V_129 . V_134 = V_127 -> V_132 & V_135 ?
( V_127 -> V_132 & V_136 ? 1 : 2 ) +
( V_127 -> V_132 & V_137 ? 2 : 0 ) : 0 ;
V_129 . V_138 = V_139 [ ( V_127 -> V_132 & V_140 ) >> 4 ] ;
V_1 -> V_59 = ( ( V_127 -> V_132 & V_141 ) != 0 ) ;
if ( ! V_129 . V_130 ) {
V_129 . V_130 = V_1 -> line . V_130 ;
V_49 &= ~ V_102 ;
} else
V_49 |= V_102 ;
if ( V_49 != V_1 -> V_101 )
F_48 ( V_1 , V_1 -> V_101 = V_49 ) ;
if ( memcmp ( & V_1 -> line , & V_129 , sizeof V_129 ) ) {
memcpy ( & V_1 -> line , & V_129 , sizeof V_129 ) ;
F_4 ( & V_1 -> V_9 -> V_7 , L_24 ,
V_13 ,
F_77 ( V_129 . V_130 ) ,
V_129 . V_131 , V_129 . V_134 ,
V_129 . V_138 ) ;
F_78 ( V_1 , & V_1 -> line ) ;
}
}
static void F_79 ( struct V_1 * V_1 )
{
int V_14 ;
struct V_16 * V_17 ;
struct V_142 * V_143 = F_80 ( V_1 -> V_9 ) ;
for ( V_17 = & V_1 -> V_17 [ 0 ] , V_14 = 0 ; V_14 < V_19 ; V_14 ++ , V_17 ++ )
F_81 ( V_143 , V_1 -> V_111 , V_17 -> V_4 , V_17 -> V_28 ) ;
}
static void F_82 ( struct V_1 * V_1 )
{
struct V_142 * V_143 = F_80 ( V_1 -> V_9 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_1 -> V_76 ; V_14 ++ )
F_81 ( V_143 , V_1 -> V_144 ,
V_1 -> V_145 [ V_14 ] . V_146 , V_1 -> V_145 [ V_14 ] . V_147 ) ;
}
static int F_83 ( struct V_1 * V_1 )
{
int V_14 ;
struct V_16 * V_17 ;
for ( V_17 = & V_1 -> V_17 [ 0 ] , V_14 = 0 ; V_14 < V_19 ; V_14 ++ , V_17 ++ ) {
V_17 -> V_4 = F_84 ( V_1 -> V_7 , V_1 -> V_111 , V_99 ,
& V_17 -> V_28 ) ;
if ( ! V_17 -> V_4 ) {
while ( V_14 != 0 ) {
-- V_14 ;
-- V_17 ;
F_81 ( V_1 -> V_7 , V_1 -> V_111 ,
V_17 -> V_4 , V_17 -> V_28 ) ;
}
return - V_148 ;
}
}
return 0 ;
}
static int F_85 ( struct V_38 * V_39 ,
const struct V_149 * V_150 )
{
struct V_151 * V_152 = NULL ;
struct V_153 * V_154 = NULL ;
unsigned char * V_155 = V_39 -> V_10 -> V_156 ;
int V_157 = V_39 -> V_10 -> V_158 ;
struct V_38 * V_159 ;
struct V_38 * V_160 ;
struct V_161 * V_162 = NULL ;
struct V_161 * V_163 = NULL ;
struct V_161 * V_164 = NULL ;
struct V_142 * V_143 = F_80 ( V_39 ) ;
struct V_1 * V_1 ;
int V_108 ;
int V_165 , V_144 ;
T_3 * V_4 ;
T_3 V_166 = 0 ;
T_3 V_167 = 0 ;
int V_168 = - 1 ;
int V_169 = - 1 ;
unsigned long V_170 ;
int V_171 ;
int V_14 ;
int V_172 = 0 ;
V_170 = ( unsigned long ) V_150 -> V_173 ;
V_171 = ( V_170 == V_174 ) ? 1 : V_175 ;
if ( V_170 == V_176 ) {
V_160 = F_86 ( V_143 , 1 ) ;
V_159 = F_86 ( V_143 , 0 ) ;
goto V_177;
}
if ( ! V_155 ) {
F_13 ( & V_39 -> V_7 , L_25 ) ;
return - V_110 ;
}
if ( ! V_157 ) {
if ( V_39 -> V_178 -> V_179 &&
V_39 -> V_178 -> V_179 -> V_158 &&
V_39 -> V_178 -> V_179 -> V_156 ) {
F_4 ( & V_39 -> V_7 ,
L_26 ) ;
V_157 = V_39 -> V_178 -> V_179 -> V_158 ;
V_155 = V_39 -> V_178 -> V_179 -> V_156 ;
} else {
F_13 ( & V_39 -> V_7 ,
L_27 ) ;
return - V_110 ;
}
}
while ( V_157 > 0 ) {
if ( V_155 [ 1 ] != V_180 ) {
F_13 ( & V_39 -> V_7 , L_28 ) ;
goto V_181;
}
switch ( V_155 [ 2 ] ) {
case V_182 :
if ( V_152 ) {
F_13 ( & V_39 -> V_7 , L_29
L_30 ) ;
goto V_181;
}
V_152 = (struct V_151 * ) V_155 ;
break;
case V_183 :
V_154 = (struct V_153 * ) V_155 ;
break;
case V_184 :
break;
case V_185 :
V_166 = V_155 [ 3 ] ;
break;
case V_186 :
V_167 = V_155 [ 3 ] ;
V_168 = V_155 [ 4 ] ;
if ( ( V_170 & V_187 ) == 0 && ( V_167 & 3 ) != 3 )
F_13 ( & V_39 -> V_7 , L_31 ) ;
break;
default:
F_4 ( & V_39 -> V_7 , L_32
L_33 ,
V_155 [ 2 ] , V_155 [ 0 ] ) ;
break;
}
V_181:
V_157 -= V_155 [ 0 ] ;
V_155 += V_155 [ 0 ] ;
}
if ( ! V_152 ) {
if ( V_168 > 0 ) {
F_4 ( & V_39 -> V_7 , L_34 ) ;
if ( V_170 & V_188 )
V_160 = F_86 ( V_143 , 0 ) ;
else
V_160 = F_86 ( V_143 , ( V_169 = V_168 ) ) ;
V_159 = V_39 ;
} else {
if ( V_39 -> V_178 -> V_11 . V_189 != 3 ) {
F_4 ( & V_39 -> V_7 , L_35 ) ;
return - V_32 ;
} else {
F_87 ( & V_39 -> V_7 , L_36 ) ;
V_172 = 1 ;
V_159 = V_160 = V_39 ;
goto V_190;
}
}
} else {
V_159 = F_86 ( V_143 , V_152 -> V_191 ) ;
V_160 = F_86 ( V_143 , ( V_169 = V_152 -> V_192 ) ) ;
if ( ! V_159 || ! V_160 ) {
F_4 ( & V_39 -> V_7 , L_37 ) ;
return - V_32 ;
}
}
if ( V_169 != V_168 )
F_4 ( & V_39 -> V_7 , L_38 ) ;
if ( V_159 == V_160 ) {
F_87 ( & V_39 -> V_7 , L_39 ) ;
V_172 = 1 ;
V_170 |= V_193 ;
if ( V_160 -> V_178 -> V_11 . V_189 != 3 ) {
F_13 ( & V_39 -> V_7 , L_40 ) ;
return - V_110 ;
}
V_190:
for ( V_14 = 0 ; V_14 < 3 ; V_14 ++ ) {
struct V_161 * V_194 ;
V_194 = & V_160 -> V_178 -> V_179 [ V_14 ] . V_11 ;
if ( F_88 ( V_194 ) )
V_162 = V_194 ;
else if ( F_89 ( V_194 ) )
V_164 = V_194 ;
else if ( F_90 ( V_194 ) )
V_163 = V_194 ;
else
return - V_110 ;
}
if ( ! V_162 || ! V_163 || ! V_164 )
return - V_32 ;
else
goto V_195;
}
V_177:
if ( V_160 -> V_178 -> V_11 . V_196
!= V_197 ) {
if ( V_159 -> V_178 -> V_11 . V_196
== V_197 ) {
struct V_38 * V_198 ;
F_4 ( & V_39 -> V_7 ,
L_41 ) ;
V_198 = V_159 ;
V_159 = V_160 ;
V_160 = V_198 ;
} else {
return - V_110 ;
}
}
if ( ! V_172 && V_39 != V_159 )
return - V_32 ;
if ( ! V_172 && F_91 ( V_160 ) ) {
F_4 ( & V_39 -> V_7 , L_42 ) ;
return - V_199 ;
}
if ( V_160 -> V_178 -> V_11 . V_189 < 2 )
return - V_110 ;
V_162 = & V_159 -> V_178 -> V_179 [ 0 ] . V_11 ;
V_163 = & V_160 -> V_178 -> V_179 [ 0 ] . V_11 ;
V_164 = & V_160 -> V_178 -> V_179 [ 1 ] . V_11 ;
if ( ! F_92 ( V_163 ) ) {
struct V_161 * V_198 ;
F_4 ( & V_39 -> V_7 ,
L_43 ) ;
V_198 = V_163 ;
V_163 = V_164 ;
V_164 = V_198 ;
}
V_195:
F_4 ( & V_39 -> V_7 , L_44 ) ;
for ( V_108 = 0 ; V_108 < V_200 && V_90 [ V_108 ] ; V_108 ++ ) ;
if ( V_108 == V_200 ) {
F_13 ( & V_39 -> V_7 , L_45 ) ;
return - V_32 ;
}
V_1 = F_93 ( sizeof( struct V_1 ) , V_99 ) ;
if ( V_1 == NULL ) {
F_13 ( & V_39 -> V_7 , L_46 ) ;
goto V_201;
}
V_165 = F_94 ( V_162 -> V_202 ) ;
V_144 = F_94 ( V_163 -> V_202 ) *
( V_170 == V_174 ? 1 : 2 ) ;
V_1 -> V_172 = V_172 ;
V_1 -> V_111 = F_94 ( V_164 -> V_202 ) * 20 ;
V_1 -> V_9 = V_159 ;
V_1 -> V_31 = V_160 ;
V_1 -> V_108 = V_108 ;
V_1 -> V_7 = V_143 ;
V_1 -> V_40 = V_166 ;
if ( V_170 & V_193 )
V_1 -> V_40 &= ~ V_104 ;
V_1 -> V_165 = V_165 ;
V_1 -> V_144 = V_144 ;
V_1 -> V_76 = V_171 ;
F_95 ( & V_1 -> V_84 , F_39 ) ;
F_96 ( & V_1 -> V_22 ) ;
F_96 ( & V_1 -> V_81 ) ;
F_97 ( & V_1 -> V_96 ) ;
V_1 -> V_203 = F_98 ( V_143 , V_163 -> V_204 ) ;
V_1 -> V_205 = F_99 ( V_163 ) ;
if ( V_1 -> V_205 )
V_1 -> V_206 = V_163 -> V_206 ;
F_100 ( & V_1 -> V_58 ) ;
V_1 -> V_58 . V_207 = & V_208 ;
V_4 = F_84 ( V_143 , V_165 , V_99 , & V_1 -> V_209 ) ;
if ( ! V_4 ) {
F_13 ( & V_39 -> V_7 , L_47 ) ;
goto V_210;
}
V_1 -> V_211 = V_4 ;
if ( F_83 ( V_1 ) < 0 ) {
F_13 ( & V_39 -> V_7 , L_48 ) ;
goto V_212;
}
V_1 -> V_98 = F_101 ( 0 , V_99 ) ;
if ( ! V_1 -> V_98 ) {
F_13 ( & V_39 -> V_7 , L_49 ) ;
goto V_213;
}
for ( V_14 = 0 ; V_14 < V_171 ; V_14 ++ ) {
struct V_78 * V_79 = & ( V_1 -> V_145 [ V_14 ] ) ;
struct V_25 * V_25 ;
V_79 -> V_146 = F_84 ( V_1 -> V_7 , V_144 , V_99 ,
& V_79 -> V_147 ) ;
if ( ! V_79 -> V_146 ) {
F_13 ( & V_39 -> V_7 , L_50
L_51 ) ;
goto V_214;
}
V_79 -> V_70 = V_14 ;
V_79 -> V_80 = V_1 ;
V_25 = F_101 ( 0 , V_99 ) ;
if ( ! V_25 ) {
F_13 ( & V_39 -> V_7 ,
L_52 ) ;
goto V_214;
}
V_25 -> V_215 |= V_216 ;
V_25 -> V_27 = V_79 -> V_147 ;
if ( V_1 -> V_205 ) {
F_102 ( V_25 , V_1 -> V_7 ,
V_1 -> V_203 ,
V_79 -> V_146 ,
V_1 -> V_144 ,
F_36 , V_79 ,
V_1 -> V_206 ) ;
} else {
F_103 ( V_25 , V_1 -> V_7 ,
V_1 -> V_203 ,
V_79 -> V_146 ,
V_1 -> V_144 ,
F_36 , V_79 ) ;
}
V_1 -> V_74 [ V_14 ] = V_25 ;
F_104 ( V_14 , & V_1 -> V_73 ) ;
}
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
struct V_16 * V_217 = & ( V_1 -> V_17 [ V_14 ] ) ;
V_217 -> V_25 = F_101 ( 0 , V_99 ) ;
if ( V_217 -> V_25 == NULL ) {
F_13 ( & V_39 -> V_7 ,
L_53 ) ;
goto V_218;
}
if ( F_99 ( V_164 ) )
F_102 ( V_217 -> V_25 , V_143 ,
F_105 ( V_143 , V_164 -> V_204 ) ,
NULL , V_1 -> V_111 , F_37 , V_217 , V_164 -> V_206 ) ;
else
F_103 ( V_217 -> V_25 , V_143 ,
F_105 ( V_143 , V_164 -> V_204 ) ,
NULL , V_1 -> V_111 , F_37 , V_217 ) ;
V_217 -> V_25 -> V_215 |= V_216 ;
V_217 -> V_80 = V_1 ;
}
F_106 ( V_39 , V_1 ) ;
V_14 = F_107 ( & V_39 -> V_7 , & V_219 ) ;
if ( V_14 < 0 )
goto V_218;
if ( V_154 ) {
V_1 -> V_41 = F_108 ( V_154 -> V_220 - 4 , V_99 ) ;
if ( ! V_1 -> V_41 )
goto V_221;
V_1 -> V_42 = V_154 -> V_220 - 4 ;
memcpy ( V_1 -> V_41 , ( T_3 * ) & V_154 -> V_222 ,
V_154 -> V_220 - 4 ) ;
V_1 -> V_43 = V_154 -> V_223 ;
V_14 = F_107 ( & V_39 -> V_7 , & V_224 ) ;
if ( V_14 < 0 ) {
F_54 ( V_1 -> V_41 ) ;
goto V_221;
}
V_14 = F_107 ( & V_39 -> V_7 ,
& V_225 ) ;
if ( V_14 < 0 ) {
F_109 ( & V_39 -> V_7 , & V_224 ) ;
F_54 ( V_1 -> V_41 ) ;
goto V_221;
}
}
V_221:
F_102 ( V_1 -> V_98 , V_143 ,
F_110 ( V_143 , V_162 -> V_204 ) ,
V_1 -> V_211 , V_165 , F_23 , V_1 ,
V_162 -> V_206 ? V_162 -> V_206 : 0xff ) ;
V_1 -> V_98 -> V_215 |= V_216 ;
V_1 -> V_98 -> V_27 = V_1 -> V_209 ;
F_111 ( & V_39 -> V_7 , L_54 , V_108 ) ;
F_48 ( V_1 , V_1 -> V_101 ) ;
V_1 -> line . V_130 = F_75 ( 9600 ) ;
V_1 -> line . V_138 = 8 ;
F_78 ( V_1 , & V_1 -> line ) ;
F_112 ( & V_226 , V_160 , V_1 ) ;
F_106 ( V_160 , V_1 ) ;
F_113 ( V_159 ) ;
F_114 ( V_107 , V_108 , & V_159 -> V_7 ) ;
V_90 [ V_108 ] = V_1 ;
return 0 ;
V_218:
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
F_53 ( V_1 -> V_17 [ V_14 ] . V_25 ) ;
V_214:
for ( V_14 = 0 ; V_14 < V_171 ; V_14 ++ )
F_53 ( V_1 -> V_74 [ V_14 ] ) ;
F_82 ( V_1 ) ;
F_53 ( V_1 -> V_98 ) ;
V_213:
F_79 ( V_1 ) ;
V_212:
F_81 ( V_143 , V_165 , V_1 -> V_211 , V_1 -> V_209 ) ;
V_210:
F_54 ( V_1 ) ;
V_201:
return - V_148 ;
}
static void F_115 ( struct V_1 * V_1 )
{
int V_14 ;
F_4 ( & V_1 -> V_9 -> V_7 , L_19 , V_13 ) ;
F_56 ( V_1 -> V_98 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ )
F_56 ( V_1 -> V_17 [ V_14 ] . V_25 ) ;
for ( V_14 = 0 ; V_14 < V_1 -> V_76 ; V_14 ++ )
F_56 ( V_1 -> V_74 [ V_14 ] ) ;
F_116 ( & V_1 -> V_84 ) ;
}
static void F_117 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_20 ( V_39 ) ;
struct V_142 * V_143 = F_80 ( V_39 ) ;
struct V_47 * V_48 ;
if ( ! V_1 )
return;
F_43 ( & V_89 ) ;
if ( V_1 -> V_41 ) {
F_109 ( & V_1 -> V_9 -> V_7 ,
& V_224 ) ;
F_109 ( & V_1 -> V_9 -> V_7 ,
& V_225 ) ;
}
F_109 ( & V_1 -> V_9 -> V_7 , & V_219 ) ;
V_1 -> V_7 = NULL ;
F_106 ( V_1 -> V_9 , NULL ) ;
F_106 ( V_1 -> V_31 , NULL ) ;
F_115 ( V_1 ) ;
F_79 ( V_1 ) ;
F_81 ( V_143 , V_1 -> V_165 , V_1 -> V_211 ,
V_1 -> V_209 ) ;
F_82 ( V_1 ) ;
if ( ! V_1 -> V_172 )
F_118 ( & V_226 , V_39 == V_1 -> V_9 ?
V_1 -> V_31 : V_1 -> V_9 ) ;
if ( V_1 -> V_58 . V_97 == 0 ) {
F_50 ( V_1 ) ;
F_46 ( & V_89 ) ;
return;
}
F_46 ( & V_89 ) ;
V_48 = F_25 ( & V_1 -> V_58 ) ;
if ( V_48 ) {
F_27 ( V_48 ) ;
F_28 ( V_48 ) ;
}
}
static int F_119 ( struct V_38 * V_39 , T_4 V_227 )
{
struct V_1 * V_1 = F_20 ( V_39 ) ;
int V_228 ;
if ( V_227 . V_229 & V_230 ) {
int V_231 ;
F_66 ( & V_1 -> V_22 ) ;
V_231 = V_1 -> V_23 ;
F_67 ( & V_1 -> V_22 ) ;
if ( V_231 )
return - V_199 ;
}
F_66 ( & V_1 -> V_81 ) ;
F_120 ( & V_1 -> V_22 ) ;
V_228 = V_1 -> V_33 ++ ;
F_121 ( & V_1 -> V_22 ) ;
F_67 ( & V_1 -> V_81 ) ;
if ( V_228 )
return 0 ;
F_43 ( & V_1 -> V_96 ) ;
if ( V_1 -> V_58 . V_97 )
F_115 ( V_1 ) ;
F_46 ( & V_1 -> V_96 ) ;
return 0 ;
}
static int F_122 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_20 ( V_39 ) ;
struct V_16 * V_17 ;
int V_88 = 0 ;
int V_228 ;
F_66 ( & V_1 -> V_81 ) ;
V_1 -> V_33 -= 1 ;
V_228 = V_1 -> V_33 ;
F_67 ( & V_1 -> V_81 ) ;
if ( V_228 )
return 0 ;
F_43 ( & V_1 -> V_96 ) ;
if ( V_1 -> V_58 . V_97 ) {
V_88 = F_12 ( V_1 -> V_98 , V_232 ) ;
F_66 ( & V_1 -> V_22 ) ;
if ( V_1 -> V_34 ) {
V_17 = V_1 -> V_34 ;
V_1 -> V_34 = NULL ;
F_67 ( & V_1 -> V_22 ) ;
F_11 ( V_1 , V_17 ) ;
} else {
F_67 ( & V_1 -> V_22 ) ;
}
if ( V_88 < 0 )
goto V_233;
V_88 = F_32 ( V_1 , V_232 ) ;
}
V_233:
F_46 ( & V_1 -> V_96 ) ;
return V_88 ;
}
static int F_123 ( struct V_38 * V_39 )
{
struct V_1 * V_1 = F_20 ( V_39 ) ;
struct V_47 * V_48 ;
F_43 ( & V_1 -> V_96 ) ;
if ( V_1 -> V_58 . V_97 ) {
V_48 = F_25 ( & V_1 -> V_58 ) ;
if ( V_48 ) {
F_27 ( V_48 ) ;
F_28 ( V_48 ) ;
}
}
F_46 ( & V_1 -> V_96 ) ;
return F_122 ( V_39 ) ;
}
static int T_5 F_124 ( void )
{
int V_6 ;
V_107 = F_125 ( V_200 ) ;
if ( ! V_107 )
return - V_148 ;
V_107 -> V_234 = V_235 ,
V_107 -> V_236 = L_55 ,
V_107 -> V_237 = L_56 ,
V_107 -> V_238 = V_239 ,
V_107 -> V_240 = 0 ,
V_107 -> type = V_241 ,
V_107 -> V_242 = V_243 ,
V_107 -> V_21 = V_244 | V_245 ;
V_107 -> V_246 = V_247 ;
V_107 -> V_246 . V_132 = V_248 | V_249 | V_250 |
V_251 | V_141 ;
F_126 ( V_107 , & V_252 ) ;
V_6 = F_127 ( V_107 ) ;
if ( V_6 ) {
F_128 ( V_107 ) ;
return V_6 ;
}
V_6 = F_129 ( & V_226 ) ;
if ( V_6 ) {
F_130 ( V_107 ) ;
F_128 ( V_107 ) ;
return V_6 ;
}
F_131 (KERN_INFO KBUILD_MODNAME L_57 DRIVER_DESC L_58 ) ;
return 0 ;
}
static void T_6 F_132 ( void )
{
F_133 ( & V_226 ) ;
F_130 ( V_107 ) ;
F_128 ( V_107 ) ;
}
