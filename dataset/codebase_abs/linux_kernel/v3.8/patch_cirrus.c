static inline int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_2 , V_5 -> V_6 , 0 ,
V_7 , V_3 ) ;
return F_3 ( V_2 , V_5 -> V_6 , 0 ,
V_8 , 0 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_9 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_2 , V_5 -> V_6 , 0 ,
V_7 , V_3 ) ;
F_2 ( V_2 , V_5 -> V_6 , 0 ,
V_10 , V_9 ) ;
}
static int F_5 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_6 ( V_2 , & V_5 -> V_15 , V_14 ,
V_12 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
unsigned int V_16 ,
unsigned int V_17 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_8 ( V_2 , & V_5 -> V_15 ,
V_16 , V_17 , V_14 ) ;
}
static int F_9 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_10 ( V_2 , & V_5 -> V_15 ) ;
}
static int F_11 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_12 ( V_2 , & V_5 -> V_15 ) ;
}
static int F_13 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_14 ( V_2 , & V_5 -> V_15 ) ;
}
static int F_15 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
unsigned int V_16 ,
unsigned int V_17 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_16 ( V_2 , & V_5 -> V_15 , V_16 ,
V_17 , V_14 ) ;
}
static int F_17 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
return F_18 ( V_2 , & V_5 -> V_15 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_18 )
F_2 ( V_2 , V_5 -> V_18 , 0 ,
V_19 ,
V_5 -> V_20 [ V_5 -> V_21 ] ) ;
}
static int F_20 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
unsigned int V_16 ,
unsigned int V_17 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_18 = V_5 -> V_22 [ V_5 -> V_21 ] ;
V_5 -> V_23 = V_16 ;
V_5 -> V_24 = V_17 ;
F_19 ( V_2 ) ;
F_21 ( V_2 , V_5 -> V_18 , V_16 , 0 , V_17 ) ;
return 0 ;
}
static int F_22 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_23 ( V_2 , V_5 -> V_18 ) ;
V_5 -> V_18 = 0 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_25 * V_26 = V_5 -> V_27 ;
V_2 -> V_28 = V_26 ;
V_2 -> V_29 = 0 ;
V_26 -> V_30 = L_1 ;
V_26 -> V_31 [ V_32 ] = V_33 ;
V_26 -> V_31 [ V_32 ] . V_34 = V_5 -> V_35 [ 0 ] ;
V_26 -> V_31 [ V_32 ] . V_36 =
V_5 -> V_15 . V_37 ;
if ( V_5 -> V_38 )
V_26 -> V_31 [ V_32 ] . V_39 =
V_40 ;
V_26 -> V_31 [ V_41 ] = V_42 ;
V_26 -> V_31 [ V_41 ] . V_34 =
V_5 -> V_22 [ V_5 -> V_21 ] ;
V_2 -> V_29 ++ ;
if ( ! V_5 -> V_15 . V_43 && ! V_5 -> V_44 )
return 0 ;
V_26 ++ ;
V_26 -> V_30 = L_2 ;
V_26 -> V_45 = V_5 -> V_46 . V_47 [ 0 ] ;
if ( ! V_26 -> V_45 )
V_26 -> V_45 = V_48 ;
if ( V_5 -> V_15 . V_43 ) {
V_26 -> V_31 [ V_32 ] =
V_49 ;
V_26 -> V_31 [ V_32 ] . V_34 =
V_5 -> V_15 . V_43 ;
}
if ( V_5 -> V_44 ) {
V_26 -> V_31 [ V_41 ] =
V_50 ;
V_26 -> V_31 [ V_41 ] . V_34 = V_5 -> V_44 ;
}
V_2 -> V_29 ++ ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_51 )
{
T_1 V_52 ;
if ( ! V_51 )
return 0 ;
if ( F_26 ( V_2 , V_51 , & V_52 , 1 ) != 1 )
return 0 ;
return V_52 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
T_1 V_51 = V_54 -> V_55 [ V_3 ] . V_51 ;
unsigned int V_56 ;
if ( ! F_28 ( V_2 , V_51 ) )
return 0 ;
V_56 = F_29 ( V_2 , V_51 ) ;
return ( F_30 ( V_56 ) != V_57 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_1 V_51 ,
unsigned int * V_58 )
{
int V_59 , V_3 ;
T_1 V_34 ;
V_34 = V_2 -> V_60 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_61 ; V_59 ++ , V_34 ++ ) {
unsigned int type ;
type = F_32 ( F_33 ( V_2 , V_34 ) ) ;
if ( type != V_62 )
continue;
V_3 = F_34 ( V_2 , V_34 , V_51 , false ) ;
if ( V_3 >= 0 ) {
* V_58 = V_3 ;
return V_34 ;
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_34 )
{
unsigned int V_56 ;
V_56 = F_29 ( V_2 , V_34 ) ;
return ( F_36 ( V_56 ) != V_63 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
int V_59 , V_64 ;
T_1 V_52 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_65 ; V_59 ++ ) {
V_52 = F_25 ( V_2 , V_54 -> V_66 [ V_59 ] ) ;
if ( ! V_52 )
break;
V_5 -> V_35 [ V_59 ] = V_52 ;
}
V_5 -> V_15 . V_67 = V_59 ;
V_5 -> V_15 . V_68 = V_5 -> V_35 ;
V_5 -> V_15 . V_37 = V_59 * 2 ;
if ( V_54 -> V_69 == V_70 && V_59 == 2 )
V_5 -> V_38 = 1 ;
V_64 = 0 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_71 ; V_59 ++ ) {
V_52 = F_25 ( V_2 , V_54 -> V_72 [ V_59 ] ) ;
if ( ! V_52 )
break;
if ( ! V_59 )
V_5 -> V_15 . V_73 = V_52 ;
else
V_5 -> V_15 . V_74 [ V_64 ++ ] = V_52 ;
}
for ( V_59 = 0 ; V_59 < V_54 -> V_75 ; V_59 ++ ) {
V_52 = F_25 ( V_2 , V_54 -> V_76 [ V_59 ] ) ;
if ( ! V_52 )
break;
V_5 -> V_15 . V_74 [ V_64 ++ ] = V_52 ;
}
if ( V_54 -> V_69 == V_70 ) {
V_54 -> V_75 = V_54 -> V_65 ;
memcpy ( V_54 -> V_76 , V_54 -> V_66 ,
sizeof( V_54 -> V_76 ) ) ;
V_54 -> V_65 = 0 ;
memset ( V_54 -> V_66 , 0 , sizeof( V_54 -> V_66 ) ) ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_77 ; V_59 ++ ) {
T_1 V_51 = V_54 -> V_55 [ V_59 ] . V_51 ;
V_5 -> V_78 [ V_5 -> V_77 ] = V_59 ;
V_5 -> V_79 [ V_59 ] = V_5 -> V_77 ++ ;
V_5 -> V_21 = V_59 ;
V_5 -> V_22 [ V_59 ] = F_31 ( V_2 , V_51 , & V_5 -> V_20 [ V_59 ] ) ;
}
if ( ! V_5 -> V_77 )
return 0 ;
if ( V_5 -> V_77 == 2 &&
V_54 -> V_55 [ 0 ] . type == V_80 &&
V_54 -> V_55 [ 1 ] . type == V_80 ) {
if ( F_27 ( V_2 , V_54 -> V_55 [ 0 ] . V_51 ) ) {
if ( ! F_27 ( V_2 , V_54 -> V_55 [ 1 ] . V_51 ) ) {
V_5 -> V_81 = 1 ;
V_5 -> V_82 = 0 ;
}
} else {
if ( F_27 ( V_2 , V_54 -> V_55 [ 1 ] . V_51 ) ) {
V_5 -> V_81 = 1 ;
V_5 -> V_82 = 1 ;
}
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
T_1 V_34 ;
if ( ! V_54 -> V_83 )
return 0 ;
if ( F_26 ( V_2 , V_54 -> V_84 [ 0 ] , & V_34 , 1 ) < 1 )
return 0 ;
V_5 -> V_15 . V_43 = V_34 ;
V_5 -> V_15 . V_85 = 1 ;
if ( V_54 -> V_83 > 1 &&
F_26 ( V_2 , V_54 -> V_84 [ 1 ] , & V_34 , 1 ) > 0 ) {
V_5 -> V_86 [ 0 ] = V_34 ;
V_2 -> V_86 = V_5 -> V_86 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
int V_3 ;
if ( V_54 -> V_87 )
V_5 -> V_44 = F_31 ( V_2 , V_54 -> V_87 , & V_3 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , const char * V_30 , int V_88 ,
unsigned int V_89 , int V_90 , struct V_91 * * V_92 )
{
char V_93 [ 44 ] ;
struct V_94 V_95 =
F_42 ( V_93 , V_88 , 0 , 0 , V_96 ) ;
V_95 . V_97 = V_89 ;
snprintf ( V_93 , sizeof( V_93 ) , L_3 , V_30 , V_98 [ V_90 ] ) ;
* V_92 = F_43 ( & V_95 , V_2 ) ;
( * V_92 ) -> V_99 . V_100 = V_101 ;
return F_44 ( V_2 , 0 , * V_92 ) ;
}
static int F_45 ( struct V_1 * V_2 , const char * V_30 ,
int V_88 , unsigned int V_89 , int V_90 ,
struct V_91 * * V_92 )
{
char V_93 [ 44 ] ;
struct V_94 V_95 =
F_46 ( V_93 , V_88 , 0 , 0 , V_96 ) ;
V_95 . V_97 = V_89 ;
snprintf ( V_93 , sizeof( V_93 ) , L_4 , V_30 , V_98 [ V_90 ] ) ;
* V_92 = F_43 ( & V_95 , V_2 ) ;
( * V_92 ) -> V_99 . V_100 = V_101 ;
return F_44 ( V_2 , 0 , * V_92 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_1 V_52 )
{
unsigned int V_102 ;
V_102 = F_48 ( V_2 , V_52 , V_96 ) ;
V_102 &= ~ ( 0x7f << V_103 ) ;
V_102 |= ( ( V_102 >> V_104 ) & 0x7f )
<< V_103 ;
F_49 ( V_2 , V_52 , V_96 , V_102 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_52 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_105 [ 4 ] ;
int V_106 ;
V_5 -> V_107 =
F_51 ( L_5 , NULL ) ;
V_106 = F_44 ( V_2 , V_52 , V_5 -> V_107 ) ;
if ( V_106 < 0 )
return V_106 ;
F_52 ( V_2 , V_52 , V_96 , V_105 ) ;
V_5 -> V_108 =
F_51 ( L_6 , V_105 ) ;
V_106 = F_44 ( V_2 , V_52 , V_5 -> V_108 ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_52 , int V_3 ,
int V_109 , int type )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const char * V_30 ;
int V_106 , V_88 ;
struct V_91 * V_110 ;
static const char * const V_111 [] = {
L_7 , L_8 , L_9
} ;
static const char * const V_65 [] = {
L_10 , L_11 , L_12
} ;
F_47 ( V_2 , V_52 ) ;
if ( ! V_5 -> V_107 ) {
V_106 = F_50 ( V_2 , V_52 ) ;
if ( V_106 < 0 )
return V_106 ;
}
V_88 = 0 ;
switch ( type ) {
case V_112 :
V_30 = L_13 ;
V_88 = V_3 ;
break;
case V_70 :
if ( V_5 -> V_38 )
V_30 = V_3 ? L_9 : L_14 ;
else if ( V_109 > 1 )
V_30 = V_111 [ V_3 ] ;
else
V_30 = L_14 ;
break;
default:
if ( V_109 > 1 )
V_30 = V_65 [ V_3 ] ;
else
V_30 = L_15 ;
break;
}
V_106 = F_41 ( V_2 , V_30 , V_88 ,
F_54 ( V_52 , 3 , 0 , V_96 ) , 0 , & V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_55 ( V_5 -> V_107 , V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_45 ( V_2 , V_30 , V_88 ,
F_54 ( V_52 , 3 , 0 , V_96 ) , 0 , & V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_55 ( V_5 -> V_108 , V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
int V_59 , V_106 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_65 ; V_59 ++ ) {
V_106 = F_53 ( V_2 , F_25 ( V_2 , V_54 -> V_66 [ V_59 ] ) ,
V_59 , V_54 -> V_65 , V_54 -> V_69 ) ;
if ( V_106 < 0 )
return V_106 ;
}
for ( V_59 = 0 ; V_59 < V_54 -> V_71 ; V_59 ++ ) {
V_106 = F_53 ( V_2 , F_25 ( V_2 , V_54 -> V_72 [ V_59 ] ) ,
V_59 , V_54 -> V_71 , V_112 ) ;
if ( V_106 < 0 )
return V_106 ;
}
for ( V_59 = 0 ; V_59 < V_54 -> V_75 ; V_59 ++ ) {
V_106 = F_53 ( V_2 , F_25 ( V_2 , V_54 -> V_76 [ V_59 ] ) ,
V_59 , V_54 -> V_75 , V_70 ) ;
if ( V_106 < 0 )
return V_106 ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_113 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 == V_3 && ! V_113 )
return 0 ;
if ( V_5 -> V_18 && V_5 -> V_18 != V_5 -> V_22 [ V_3 ] ) {
F_58 ( V_2 , V_5 -> V_18 , 1 ) ;
V_5 -> V_18 = V_5 -> V_22 [ V_3 ] ;
F_21 ( V_2 , V_5 -> V_18 ,
V_5 -> V_23 , 0 ,
V_5 -> V_24 ) ;
}
V_5 -> V_21 = V_3 ;
F_19 ( V_2 ) ;
return 1 ;
}
static int F_59 ( struct V_91 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
unsigned int V_3 ;
V_116 -> type = V_117 ;
V_116 -> V_118 = 1 ;
V_116 -> V_119 . V_120 . V_121 = V_5 -> V_77 ;
if ( V_116 -> V_119 . V_120 . V_122 >= V_5 -> V_77 )
V_116 -> V_119 . V_120 . V_122 = V_5 -> V_77 - 1 ;
V_3 = V_5 -> V_78 [ V_116 -> V_119 . V_120 . V_122 ] ;
F_61 ( V_2 , V_54 -> V_55 [ V_3 ] . V_51 , V_54 ,
V_116 -> V_119 . V_120 . V_30 ,
sizeof( V_116 -> V_119 . V_120 . V_30 ) , NULL ) ;
return 0 ;
}
static int F_62 ( struct V_91 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_124 -> V_119 . V_120 . V_122 [ 0 ] = V_5 -> V_79 [ V_5 -> V_21 ] ;
return 0 ;
}
static int F_63 ( struct V_91 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_3 = V_124 -> V_119 . V_120 . V_122 [ 0 ] ;
if ( V_3 >= V_5 -> V_77 )
return - V_125 ;
V_3 = V_5 -> V_78 [ V_3 ] ;
return F_57 ( V_2 , V_3 , 0 ) ;
}
static const struct V_126 * F_64 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_126 * V_129 ;
int V_59 , V_130 ;
V_129 = F_65 ( sizeof( * V_129 ) + sizeof( long ) * ( V_5 -> V_77 + 1 ) ,
V_131 ) ;
if ( ! V_129 )
return NULL ;
V_129 -> V_128 = V_128 ;
V_130 = 0 ;
for ( V_59 = 0 ; V_59 < V_132 ; V_59 ++ ) {
if ( ! V_5 -> V_22 [ V_59 ] )
continue;
V_129 -> V_133 [ V_130 ++ ] =
F_54 ( V_5 -> V_22 [ V_59 ] , 3 ,
V_5 -> V_20 [ V_59 ] , V_134 ) ;
}
return V_129 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_53 * V_54 ,
int V_122 )
{
T_1 V_51 = V_54 -> V_55 [ V_122 ] . V_51 ;
T_2 V_102 ;
const char * V_135 ;
struct V_91 * V_110 ;
if ( ! ( F_33 ( V_2 , V_51 ) & V_136 ) )
return 0 ;
V_102 = F_48 ( V_2 , V_51 , V_134 ) ;
V_102 = ( V_102 & V_137 ) >> V_103 ;
if ( V_102 <= 1 )
return 0 ;
V_135 = F_67 ( V_2 , V_54 , V_122 ) ;
return F_45 ( V_2 , V_135 , 0 ,
F_54 ( V_51 , 3 , 0 , V_134 ) , 1 , & V_110 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_59 , V_106 ;
if ( ! V_5 -> V_77 )
return 0 ;
V_5 -> V_138 [ 0 ] = F_64 ( V_2 , & V_139 ) ;
V_5 -> V_138 [ 1 ] = F_64 ( V_2 , & V_140 ) ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
struct V_91 * V_110 ;
int V_130 ;
if ( ! V_5 -> V_138 [ V_59 ] )
return - V_141 ;
V_110 = F_43 ( & V_142 [ V_59 ] , V_2 ) ;
if ( ! V_110 )
return - V_141 ;
V_110 -> V_97 = ( long ) V_5 -> V_138 [ V_59 ] ;
V_106 = F_44 ( V_2 , 0 , V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
for ( V_130 = 0 ; V_130 < V_132 ; V_130 ++ ) {
if ( ! V_5 -> V_22 [ V_130 ] )
continue;
V_106 = F_69 ( V_2 , V_110 , 0 , V_5 -> V_22 [ V_130 ] ) ;
if ( V_106 < 0 )
return V_106 ;
}
}
if ( V_5 -> V_77 > 1 && ! V_5 -> V_81 ) {
V_106 = F_44 ( V_2 , 0 ,
F_43 ( & V_143 , V_2 ) ) ;
if ( V_106 < 0 )
return V_106 ;
}
for ( V_59 = 0 ; V_59 < V_5 -> V_77 ; V_59 ++ ) {
V_106 = F_66 ( V_2 , & V_5 -> V_46 , V_59 ) ;
if ( V_106 < 0 )
return V_106 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_106 ;
if ( ! V_5 -> V_15 . V_43 )
return 0 ;
V_106 = F_71 ( V_2 , V_5 -> V_15 . V_43 ,
V_5 -> V_15 . V_43 ,
V_5 -> V_27 [ 1 ] . V_45 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_72 ( V_2 , & V_5 -> V_15 ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_44 )
return F_74 ( V_2 , V_5 -> V_44 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
unsigned int V_146 ;
unsigned int V_147 ;
T_1 V_34 ;
int V_59 ;
V_147 = 0 ;
if ( V_54 -> V_83 ) {
V_34 = V_54 -> V_84 [ 0 ] ;
if ( F_28 ( V_2 , V_34 ) ) {
if ( F_76 ( V_2 , V_34 )
)
V_147 = 1 ;
}
}
V_146 = 0 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_71 ; V_59 ++ ) {
V_34 = V_54 -> V_72 [ V_59 ] ;
if ( ! F_28 ( V_2 , V_34 ) )
continue;
V_146 = F_76 ( V_2 , V_34 ) ;
if ( V_146 )
break;
}
for ( V_59 = 0 ; V_59 < V_54 -> V_75 ; V_59 ++ ) {
int V_148 = V_146 ? 0 : V_149 ;
if ( V_147 && ( V_5 -> V_6 == V_150 ) )
V_148 = 0 ;
V_34 = V_54 -> V_76 [ V_59 ] ;
F_77 ( V_2 , V_34 , V_148 ) ;
}
if ( V_5 -> V_151 ) {
unsigned int V_152 = V_146 ?
V_5 -> V_151 : V_5 -> V_153 ;
F_2 ( V_2 , 0x01 , 0 ,
V_154 , V_152 ) ;
}
if ( V_5 -> V_6 == V_150 ) {
for ( V_59 = 0 ; V_59 < V_54 -> V_71 ; V_59 ++ ) {
V_34 = V_54 -> V_72 [ V_59 ] ;
F_77 ( V_2 , V_34 ,
( V_147 && V_5 -> V_155 ) ? 0 : V_156 ) ;
}
if ( V_54 -> V_83 ) {
V_34 = V_54 -> V_84 [ 0 ] ;
F_77 ( V_2 , V_34 ,
V_147 ? V_149 : 0 ) ;
}
}
}
static void F_78 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
T_1 V_34 ;
unsigned int V_157 ;
V_34 = V_54 -> V_55 [ V_5 -> V_82 ] . V_51 ;
V_157 = F_76 ( V_2 , V_34 ) ;
if ( V_5 -> V_6 == V_158 ) {
if ( V_157 )
F_57 ( V_2 , V_5 -> V_82 , 0 ) ;
else
F_57 ( V_2 , ! V_5 -> V_82 , 0 ) ;
} else {
if ( V_157 ) {
if ( V_5 -> V_21 != V_5 -> V_82 ) {
V_5 -> V_159 = V_5 -> V_21 ;
V_5 -> V_21 = V_5 -> V_82 ;
}
} else {
V_5 -> V_21 = V_5 -> V_159 ;
}
F_19 ( V_2 ) ;
}
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_5 -> V_15 . V_67 ; V_59 ++ )
F_2 ( V_2 , V_5 -> V_15 . V_68 [ V_59 ] , 0 ,
V_160 , V_161 ) ;
if ( V_5 -> V_15 . V_73 )
F_2 ( V_2 , V_5 -> V_15 . V_73 , 0 ,
V_160 , V_161 ) ;
for ( V_59 = 0 ; V_59 < F_80 ( V_5 -> V_15 . V_74 ) ; V_59 ++ ) {
if ( ! V_5 -> V_15 . V_74 [ V_59 ] )
break;
F_2 ( V_2 , V_5 -> V_15 . V_74 [ V_59 ] , 0 ,
V_160 , V_161 ) ;
}
for ( V_59 = 0 ; V_59 < V_54 -> V_65 ; V_59 ++ )
F_77 ( V_2 , V_54 -> V_66 [ V_59 ] , V_149 ) ;
for ( V_59 = 0 ; V_59 < V_54 -> V_71 ; V_59 ++ ) {
T_1 V_34 = V_54 -> V_72 [ V_59 ] ;
F_77 ( V_2 , V_34 , V_156 ) ;
if ( ! V_54 -> V_75 )
continue;
if ( F_33 ( V_2 , V_34 ) & V_162 ) {
F_81 ( V_2 , V_34 , V_163 , F_75 ) ;
V_5 -> V_164 = 1 ;
}
}
for ( V_59 = 0 ; V_59 < V_54 -> V_75 ; V_59 ++ )
F_77 ( V_2 , V_54 -> V_76 [ V_59 ] , V_149 ) ;
if ( V_5 -> V_164 || V_5 -> V_165 )
F_75 ( V_2 , NULL ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
unsigned int V_9 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_77 ; V_59 ++ ) {
unsigned int V_166 ;
T_1 V_51 = V_54 -> V_55 [ V_59 ] . V_51 ;
if ( ! V_5 -> V_22 [ V_59 ] )
continue;
V_166 = V_167 ;
if ( V_54 -> V_55 [ V_59 ] . type == V_80 )
V_166 |= F_83 ( V_2 , V_51 ) ;
F_77 ( V_2 , V_51 , V_166 ) ;
F_2 ( V_2 , V_5 -> V_22 [ V_59 ] , 0 ,
V_160 ,
F_84 ( V_5 -> V_20 [ V_59 ] ) ) ;
if ( V_5 -> V_81 && V_5 -> V_82 == V_59 )
F_81 ( V_2 , V_51 , V_168 , F_78 ) ;
}
if ( V_5 -> V_6 == V_158 ) {
F_57 ( V_2 , V_5 -> V_21 , 1 ) ;
if ( V_5 -> V_81 )
F_78 ( V_2 , NULL ) ;
V_9 = F_1 ( V_2 , V_169 ) ;
if ( F_35 ( V_2 , V_170 ) )
V_9 |= 1 << 4 ;
if ( F_35 ( V_2 , V_171 ) )
V_9 |= 1 << 3 ;
F_4 ( V_2 , V_169 , V_9 ) ;
} else {
if ( V_5 -> V_81 )
F_78 ( V_2 , NULL ) ;
else {
V_5 -> V_18 = V_5 -> V_22 [ V_5 -> V_21 ] ;
F_19 ( V_2 ) ;
}
}
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
V_9 = 0x0002 ;
V_9 |= 0x0008 ;
if ( F_35 ( V_2 , V_172 ) )
V_9 |= 0x4000 ;
F_4 ( V_2 , V_173 , V_9 ) ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_87 ( V_2 , V_174 ) ;
F_87 ( V_2 , V_175 ) ;
F_88 ( V_2 ) ;
if ( V_5 -> V_176 ) {
F_2 ( V_2 , 0x01 , 0 , V_177 ,
V_5 -> V_176 ) ;
F_2 ( V_2 , 0x01 , 0 , V_178 ,
V_5 -> V_179 ) ;
F_2 ( V_2 , 0x01 , 0 , V_154 ,
V_5 -> V_180 ) ;
}
F_79 ( V_2 ) ;
F_82 ( V_2 ) ;
F_85 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_106 ;
V_106 = F_56 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_68 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_70 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_73 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_86 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_90 ( V_2 , & V_5 -> V_46 ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_92 ( V_5 -> V_138 [ 0 ] ) ;
F_92 ( V_5 -> V_138 [ 1 ] ) ;
F_93 ( & V_5 -> V_181 ) ;
F_92 ( V_2 -> V_5 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_106 ;
V_106 = F_95 ( V_2 , & V_5 -> V_46 , NULL ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_37 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_38 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_39 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_40 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 ,
const struct V_182 * V_183 , int V_184 )
{
if ( V_184 == V_185 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_151 = 2 ;
V_5 -> V_153 = 8 ;
V_5 -> V_176 = V_5 -> V_179 =
V_5 -> V_151 | V_5 -> V_153 ;
}
}
static void F_97 ( struct V_1 * V_2 ,
const struct V_182 * V_183 , int V_184 )
{
if ( V_184 == V_185 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_151 = 4 ;
V_5 -> V_153 = 8 ;
V_5 -> V_176 = V_5 -> V_179 =
V_5 -> V_151 | V_5 -> V_153 ;
}
}
static int F_98 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_106 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_131 ) ;
if ( ! V_5 )
return - V_141 ;
V_2 -> V_5 = V_5 ;
F_99 ( & V_5 -> V_181 ) ;
V_5 -> V_6 = V_158 ;
F_100 ( V_2 , V_186 , V_187 ,
V_188 ) ;
F_101 ( V_2 , V_185 ) ;
V_106 = F_94 ( V_2 ) ;
if ( V_106 < 0 )
goto error;
V_2 -> V_189 = V_190 ;
F_101 ( V_2 , V_191 ) ;
return 0 ;
error:
F_91 ( V_2 ) ;
V_2 -> V_5 = NULL ;
return V_106 ;
}
static void F_102 ( struct V_1 * V_2 ,
const struct V_182 * V_183 , int V_184 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_184 == V_185 )
V_5 -> V_155 = 1 ;
}
static int F_103 ( struct V_91 * V_114 ,
struct V_115 * V_116 )
{
V_116 -> type = V_192 ;
V_116 -> V_118 = 1 ;
V_116 -> V_119 . integer . V_193 = 0 ;
V_116 -> V_119 . integer . V_194 = 3 ;
return 0 ;
}
static int F_104 ( struct V_91 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
V_124 -> V_119 . integer . V_119 [ 0 ] =
F_1 ( V_2 , V_195 ) & 0x0003 ;
return 0 ;
}
static int F_105 ( struct V_91 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
unsigned int V_196 = V_124 -> V_119 . integer . V_119 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_195 ) ;
unsigned int V_197 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_196 & 0x0003 ) ;
if ( V_197 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_195 , V_9 ) ;
return 1 ;
}
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_198 , V_9 ;
V_9 = F_1 ( V_2 , V_199 ) ;
if ( V_5 -> V_176 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_155 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_199 , V_9 ) ;
if ( ( V_5 -> V_176 || V_5 -> V_155 ) &&
F_35 ( V_2 , V_200 ) ) {
V_198 = F_29 ( V_2 , V_200 ) ;
V_198 &= ~ V_201 ;
V_198 |= ( V_63 << V_202 ) ;
F_107 ( V_2 , V_200 , V_198 ) ;
}
}
static void F_108 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_83 ; V_59 ++ ) {
T_1 V_34 = V_54 -> V_84 [ V_59 ] ;
if ( ! V_54 -> V_75 )
continue;
if ( F_33 ( V_2 , V_34 ) & V_162 ) {
F_81 ( V_2 , V_34 , V_203 , F_75 ) ;
V_5 -> V_165 = 1 ;
}
}
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_150 ) {
F_87 ( V_2 , V_204 ) ;
F_87 ( V_2 , V_205 ) ;
F_106 ( V_2 ) ;
}
if ( V_5 -> V_176 ) {
F_2 ( V_2 , 0x01 , 0 , V_177 ,
V_5 -> V_176 ) ;
F_2 ( V_2 , 0x01 , 0 , V_178 ,
V_5 -> V_179 ) ;
F_2 ( V_2 , 0x01 , 0 , V_154 ,
V_5 -> V_180 ) ;
}
F_79 ( V_2 ) ;
F_82 ( V_2 ) ;
F_108 ( V_2 ) ;
return 0 ;
}
static int F_110 ( struct V_91 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
return F_111 ( & V_5 -> V_206 , V_116 ) ;
}
static int F_112 ( struct V_91 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_124 -> V_119 . V_120 . V_122 [ 0 ] = V_5 -> V_21 ;
return 0 ;
}
static int F_113 ( struct V_91 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_60 ( V_114 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
return F_114 ( V_2 , & V_5 -> V_206 , V_124 ,
V_5 -> V_22 [ 0 ] , & V_5 -> V_21 ) ;
}
static int F_115 ( struct V_1 * V_2 , int V_122 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
const struct V_207 * V_208 = & V_5 -> V_206 ;
T_1 V_51 = V_54 -> V_55 [ V_122 ] . V_51 ;
struct V_91 * V_110 ;
T_2 V_102 ;
if ( ! ( F_33 ( V_2 , V_51 ) & V_136 ) )
return 0 ;
V_102 = F_48 ( V_2 , V_51 , V_134 ) ;
V_102 = ( V_102 & V_137 ) >> V_103 ;
if ( V_102 <= 1 )
return 0 ;
return F_45 ( V_2 , V_208 -> V_121 [ V_122 ] . V_135 , 0 ,
F_54 ( V_51 , 3 , 0 , V_134 ) , 1 , & V_110 ) ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
struct V_207 * V_208 = & V_5 -> V_206 ;
int V_59 , V_106 , V_209 ;
const char * V_135 ;
if ( ! V_5 -> V_77 )
return 0 ;
V_5 -> V_138 [ 0 ] = F_64 ( V_2 , & V_139 ) ;
V_5 -> V_138 [ 1 ] = F_64 ( V_2 , & V_140 ) ;
for ( V_59 = 0 ; V_59 < 2 ; V_59 ++ ) {
struct V_91 * V_110 ;
int V_130 ;
if ( ! V_5 -> V_138 [ V_59 ] )
return - V_141 ;
V_110 = F_43 ( & V_142 [ V_59 ] , V_2 ) ;
if ( ! V_110 )
return - V_141 ;
V_110 -> V_97 = ( long ) V_5 -> V_138 [ V_59 ] ;
V_106 = F_44 ( V_2 , 0 , V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
for ( V_130 = 0 ; V_130 < V_132 ; V_130 ++ ) {
if ( ! V_5 -> V_22 [ V_130 ] )
continue;
V_106 = F_69 ( V_2 , V_110 , 0 , V_5 -> V_22 [ V_130 ] ) ;
if ( V_106 < 0 )
return V_106 ;
}
}
for ( V_59 = 0 ; V_59 < V_5 -> V_77 ; V_59 ++ ) {
V_135 = F_67 ( V_2 , V_54 , V_59 ) ;
F_117 ( V_208 , V_135 , V_5 -> V_20 [ V_59 ] , & V_209 ) ;
V_106 = F_115 ( V_2 , V_59 ) ;
if ( V_106 < 0 )
return V_106 ;
}
if ( ( V_5 -> V_77 == 2 && ! V_5 -> V_81 ) ||
( V_5 -> V_77 == 3 ) ) {
V_106 = F_44 ( V_2 , V_5 -> V_22 [ 0 ] ,
F_43 ( & V_210 , V_2 ) ) ;
if ( V_106 < 0 )
return V_106 ;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
T_1 V_52 = V_211 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
struct V_91 * V_110 ;
int V_106 ;
char * V_30 = L_16 ;
F_47 ( V_2 , V_52 ) ;
V_106 = F_41 ( V_2 , V_30 , 0 ,
F_54 ( V_52 , 3 , 0 , V_96 ) , 0 , & V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_45 ( V_2 , V_30 , 0 ,
F_54 ( V_52 , 3 , 0 , V_96 ) , 0 , & V_110 ) ;
if ( V_106 < 0 )
return V_106 ;
if ( V_54 -> V_75 && ( V_5 -> V_6 == V_150 ) ) {
V_106 = F_44 ( V_2 , 0 ,
F_43 ( & V_212 , V_2 ) ) ;
if ( V_106 < 0 )
return V_106 ;
}
return V_106 ;
}
static int F_119 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_106 ;
V_106 = F_118 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_116 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_70 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_109 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_90 ( V_2 , & V_5 -> V_46 ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_53 * V_54 = & V_5 -> V_46 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_54 -> V_77 ; V_59 ++ ) {
T_1 V_51 = V_54 -> V_55 [ V_59 ] . V_51 ;
V_5 -> V_22 [ V_59 ] = F_31 ( V_2 , V_51 , & V_5 -> V_20 [ V_59 ] ) ;
V_5 -> V_21 = V_5 -> V_159 = V_59 ;
V_5 -> V_77 ++ ;
if ( F_27 ( V_2 , V_59 ) && V_54 -> V_77 >= 2 ) {
V_5 -> V_81 = 1 ;
V_5 -> V_82 = V_59 ;
}
}
return 0 ;
}
static int F_121 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_106 ;
V_106 = F_95 ( V_2 , & V_5 -> V_46 , NULL ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_37 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_120 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_39 ( V_2 ) ;
if ( V_106 < 0 )
return V_106 ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
F_123 ( V_2 ) ;
F_2 ( V_2 , V_211 , 0 ,
V_213 , V_214 ) ;
F_2 ( V_2 , V_215 , 0 ,
V_213 , V_214 ) ;
if ( V_5 -> V_6 == V_150 ) {
V_9 = F_1 ( V_2 , V_199 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_199 , V_9 ) ;
}
return 0 ;
}
static int F_124 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_106 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_131 ) ;
if ( ! V_5 )
return - V_141 ;
V_2 -> V_5 = V_5 ;
F_99 ( & V_5 -> V_181 ) ;
V_5 -> V_6 = V_150 ;
F_100 ( V_2 , V_216 , V_217 ,
V_218 ) ;
F_101 ( V_2 , V_185 ) ;
F_106 ( V_2 ) ;
V_106 = F_121 ( V_2 ) ;
if ( V_106 < 0 )
goto error;
V_2 -> V_189 = V_219 ;
F_101 ( V_2 , V_191 ) ;
return 0 ;
error:
F_91 ( V_2 ) ;
V_2 -> V_5 = NULL ;
return V_106 ;
}
static int F_125 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_106 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_131 ) ;
if ( ! V_5 )
return - V_141 ;
V_2 -> V_5 = V_5 ;
F_99 ( & V_5 -> V_181 ) ;
V_5 -> V_6 = V_220 ;
V_106 = F_121 ( V_2 ) ;
if ( V_106 < 0 )
goto error;
V_2 -> V_189 = V_219 ;
return 0 ;
error:
F_91 ( V_2 ) ;
V_2 -> V_5 = NULL ;
return V_106 ;
}
static int T_3 F_126 ( void )
{
return F_127 ( & V_221 ) ;
}
static void T_4 F_128 ( void )
{
F_129 ( & V_221 ) ;
}
