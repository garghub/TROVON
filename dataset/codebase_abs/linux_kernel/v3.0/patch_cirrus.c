static inline int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_2 , V_4 , 0 ,
V_5 , V_3 ) ;
return F_3 ( V_2 , V_4 , 0 ,
V_6 , 0 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
F_2 ( V_2 , V_4 , 0 ,
V_5 , V_3 ) ;
F_2 ( V_2 , V_4 , 0 ,
V_8 , V_7 ) ;
}
static int F_5 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
return F_6 ( V_2 , & V_14 -> V_15 , V_12 ,
V_10 ) ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_16 ,
unsigned int V_17 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
return F_8 ( V_2 , & V_14 -> V_15 ,
V_16 , V_17 , V_12 ) ;
}
static int F_9 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
return F_10 ( V_2 , & V_14 -> V_15 ) ;
}
static int F_11 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
return F_12 ( V_2 , & V_14 -> V_15 ) ;
}
static int F_13 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
return F_14 ( V_2 , & V_14 -> V_15 ) ;
}
static int F_15 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_16 ,
unsigned int V_17 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
return F_16 ( V_2 , & V_14 -> V_15 , V_16 ,
V_17 , V_12 ) ;
}
static int F_17 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
return F_18 ( V_2 , & V_14 -> V_15 ) ;
}
static int F_19 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
unsigned int V_16 ,
unsigned int V_17 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_18 = V_14 -> V_19 [ V_14 -> V_20 ] ;
V_14 -> V_21 = V_16 ;
V_14 -> V_22 = V_17 ;
F_20 ( V_2 , V_14 -> V_18 , V_16 , 0 , V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_22 ( V_2 , V_14 -> V_18 ) ;
V_14 -> V_18 = 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_23 * V_24 = V_14 -> V_25 ;
V_2 -> V_26 = V_24 ;
V_2 -> V_27 = 0 ;
V_24 -> V_28 = L_1 ;
V_24 -> V_29 [ V_30 ] = V_31 ;
V_24 -> V_29 [ V_30 ] . V_32 = V_14 -> V_33 [ 0 ] ;
V_24 -> V_29 [ V_30 ] . V_34 =
V_14 -> V_15 . V_35 ;
V_24 -> V_29 [ V_36 ] = V_37 ;
V_24 -> V_29 [ V_36 ] . V_32 =
V_14 -> V_19 [ V_14 -> V_20 ] ;
V_2 -> V_27 ++ ;
if ( ! V_14 -> V_15 . V_38 && ! V_14 -> V_39 )
return 0 ;
V_24 ++ ;
V_24 -> V_28 = L_2 ;
V_24 -> V_40 = V_14 -> V_41 . V_42 [ 0 ] ;
if ( ! V_24 -> V_40 )
V_24 -> V_40 = V_43 ;
if ( V_14 -> V_15 . V_38 ) {
V_24 -> V_29 [ V_30 ] =
V_44 ;
V_24 -> V_29 [ V_30 ] . V_32 =
V_14 -> V_15 . V_38 ;
}
if ( V_14 -> V_39 ) {
V_24 -> V_29 [ V_36 ] =
V_45 ;
V_24 -> V_29 [ V_36 ] . V_32 = V_14 -> V_39 ;
}
V_2 -> V_27 ++ ;
return 0 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 V_46 )
{
T_1 V_47 ;
if ( ! V_46 )
return 0 ;
if ( F_25 ( V_2 , V_46 , & V_47 , 1 ) != 1 )
return 0 ;
return V_47 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
T_1 V_46 = V_49 -> V_50 [ V_3 ] . V_46 ;
unsigned int V_51 ;
if ( ! F_27 ( V_2 , V_46 ) )
return 0 ;
V_51 = F_28 ( V_2 , V_46 ) ;
return ( F_29 ( V_51 ) != V_52 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 , T_1 V_46 ,
unsigned int * V_53 )
{
int V_54 ;
T_1 V_32 ;
V_32 = V_2 -> V_55 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_56 ; V_54 ++ , V_32 ++ ) {
T_1 V_57 [ 2 ] ;
unsigned int type ;
int V_58 , V_59 ;
type = F_31 ( F_32 ( V_2 , V_32 ) ) ;
if ( type != V_60 )
continue;
V_59 = F_25 ( V_2 , V_32 , V_57 ,
F_33 ( V_57 ) ) ;
if ( V_59 <= 0 )
continue;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_57 [ V_58 ] == V_46 ) {
* V_53 = V_58 ;
return V_32 ;
}
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_32 )
{
unsigned int V_51 ;
V_51 = F_28 ( V_2 , V_32 ) ;
return ( F_35 ( V_51 ) != V_61 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
int V_54 , V_62 ;
T_1 V_47 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_63 ; V_54 ++ ) {
V_47 = F_24 ( V_2 , V_49 -> V_64 [ V_54 ] ) ;
if ( ! V_47 )
break;
V_14 -> V_33 [ V_54 ] = V_47 ;
}
V_14 -> V_15 . V_65 = V_54 ;
V_14 -> V_15 . V_66 = V_14 -> V_33 ;
V_14 -> V_15 . V_35 = V_54 * 2 ;
V_62 = 0 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_67 ; V_54 ++ ) {
V_47 = F_24 ( V_2 , V_49 -> V_68 [ V_54 ] ) ;
if ( ! V_47 )
break;
if ( ! V_54 )
V_14 -> V_15 . V_69 = V_47 ;
else
V_14 -> V_15 . V_70 [ V_62 ++ ] = V_47 ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_71 ; V_54 ++ ) {
V_47 = F_24 ( V_2 , V_49 -> V_72 [ V_54 ] ) ;
if ( ! V_47 )
break;
V_14 -> V_15 . V_70 [ V_62 ++ ] = V_47 ;
}
if ( V_49 -> V_73 == V_74 ) {
V_49 -> V_71 = V_49 -> V_63 ;
memcpy ( V_49 -> V_72 , V_49 -> V_64 ,
sizeof( V_49 -> V_72 ) ) ;
V_49 -> V_63 = 0 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_75 ; V_54 ++ ) {
T_1 V_46 = V_49 -> V_50 [ V_54 ] . V_46 ;
V_14 -> V_76 [ V_14 -> V_75 ] = V_54 ;
V_14 -> V_77 [ V_54 ] = V_14 -> V_75 ++ ;
V_14 -> V_20 = V_54 ;
V_14 -> V_19 [ V_54 ] = F_30 ( V_2 , V_46 , & V_14 -> V_78 [ V_54 ] ) ;
}
if ( ! V_14 -> V_75 )
return 0 ;
if ( V_14 -> V_75 == 2 &&
V_49 -> V_50 [ 0 ] . type == V_79 &&
V_49 -> V_50 [ 1 ] . type == V_79 ) {
if ( F_26 ( V_2 , V_49 -> V_50 [ 0 ] . V_46 ) ) {
if ( ! F_26 ( V_2 , V_49 -> V_50 [ 1 ] . V_46 ) ) {
V_14 -> V_80 = 1 ;
V_14 -> V_81 = 0 ;
}
} else {
if ( F_26 ( V_2 , V_49 -> V_50 [ 1 ] . V_46 ) ) {
V_14 -> V_80 = 1 ;
V_14 -> V_81 = 1 ;
}
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
T_1 V_32 ;
if ( ! V_49 -> V_82 )
return 0 ;
if ( F_25 ( V_2 , V_49 -> V_83 [ 0 ] , & V_32 , 1 ) < 1 )
return 0 ;
V_14 -> V_15 . V_38 = V_32 ;
V_14 -> V_15 . V_84 = 1 ;
if ( V_49 -> V_82 > 1 &&
F_25 ( V_2 , V_49 -> V_83 [ 1 ] , & V_32 , 1 ) > 0 ) {
V_14 -> V_85 [ 0 ] = V_32 ;
V_2 -> V_85 = V_14 -> V_85 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
int V_3 ;
if ( V_49 -> V_86 )
V_14 -> V_39 = F_30 ( V_2 , V_49 -> V_86 , & V_3 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , const char * V_28 , int V_87 ,
unsigned int V_88 , int V_89 , struct V_90 * * V_91 )
{
char V_92 [ 44 ] ;
struct V_93 V_94 =
F_41 ( V_92 , V_87 , 0 , 0 , V_95 ) ;
V_94 . V_96 = V_88 ;
snprintf ( V_92 , sizeof( V_92 ) , L_3 , V_28 , V_97 [ V_89 ] ) ;
* V_91 = F_42 ( & V_94 , V_2 ) ;
( * V_91 ) -> V_98 . V_99 = V_100 ;
return F_43 ( V_2 , 0 , * V_91 ) ;
}
static int F_44 ( struct V_1 * V_2 , const char * V_28 ,
int V_87 , unsigned int V_88 , int V_89 ,
struct V_90 * * V_91 )
{
char V_92 [ 32 ] ;
struct V_93 V_94 =
F_45 ( V_92 , V_87 , 0 , 0 , V_95 ) ;
V_94 . V_96 = V_88 ;
snprintf ( V_92 , sizeof( V_92 ) , L_4 , V_28 , V_97 [ V_89 ] ) ;
* V_91 = F_42 ( & V_94 , V_2 ) ;
( * V_91 ) -> V_98 . V_99 = V_100 ;
return F_43 ( V_2 , 0 , * V_91 ) ;
}
static void F_46 ( struct V_1 * V_2 , T_1 V_47 )
{
unsigned int V_101 ;
V_101 = F_47 ( V_2 , V_47 , V_95 ) ;
V_101 &= ~ ( 0x7f << V_102 ) ;
V_101 |= ( ( V_101 >> V_103 ) & 0x7f )
<< V_102 ;
F_48 ( V_2 , V_47 , V_95 , V_101 ) ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_47 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned int V_104 [ 4 ] ;
int V_105 ;
V_14 -> V_106 =
F_50 ( L_5 , NULL ) ;
V_105 = F_43 ( V_2 , V_47 , V_14 -> V_106 ) ;
if ( V_105 < 0 )
return V_105 ;
F_51 ( V_2 , V_47 , V_95 , V_104 ) ;
V_14 -> V_107 =
F_50 ( L_6 , V_104 ) ;
V_105 = F_43 ( V_2 , V_47 , V_14 -> V_107 ) ;
if ( V_105 < 0 )
return V_105 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_47 , int V_3 ,
int V_108 , int type )
{
struct V_13 * V_14 = V_2 -> V_14 ;
const char * V_28 ;
int V_105 , V_87 ;
struct V_90 * V_109 ;
static const char * const V_110 [] = {
L_7 , L_8 , L_9
} ;
static const char * const V_63 [] = {
L_10 , L_11 , L_12
} ;
F_46 ( V_2 , V_47 ) ;
if ( ! V_14 -> V_106 ) {
V_105 = F_49 ( V_2 , V_47 ) ;
if ( V_105 < 0 )
return V_105 ;
}
V_87 = 0 ;
switch ( type ) {
case V_111 :
V_28 = L_13 ;
V_87 = V_3 ;
break;
case V_74 :
if ( V_108 > 1 )
V_28 = V_110 [ V_3 ] ;
else
V_28 = L_14 ;
break;
default:
if ( V_108 > 1 )
V_28 = V_63 [ V_3 ] ;
else
V_28 = L_15 ;
break;
}
V_105 = F_40 ( V_2 , V_28 , V_87 ,
F_53 ( V_47 , 3 , 0 , V_95 ) , 0 , & V_109 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_54 ( V_14 -> V_106 , V_109 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_44 ( V_2 , V_28 , V_87 ,
F_53 ( V_47 , 3 , 0 , V_95 ) , 0 , & V_109 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_54 ( V_14 -> V_107 , V_109 ) ;
if ( V_105 < 0 )
return V_105 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
int V_54 , V_105 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_63 ; V_54 ++ ) {
V_105 = F_52 ( V_2 , F_24 ( V_2 , V_49 -> V_64 [ V_54 ] ) ,
V_54 , V_49 -> V_63 , V_49 -> V_73 ) ;
if ( V_105 < 0 )
return V_105 ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_67 ; V_54 ++ ) {
V_105 = F_52 ( V_2 , F_24 ( V_2 , V_49 -> V_68 [ V_54 ] ) ,
V_54 , V_49 -> V_67 , V_111 ) ;
if ( V_105 < 0 )
return V_105 ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_71 ; V_54 ++ ) {
V_105 = F_52 ( V_2 , F_24 ( V_2 , V_49 -> V_72 [ V_54 ] ) ,
V_54 , V_49 -> V_71 , V_74 ) ;
if ( V_105 < 0 )
return V_105 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_112 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_20 == V_3 && ! V_112 )
return 0 ;
if ( V_14 -> V_18 && V_14 -> V_18 != V_14 -> V_19 [ V_3 ] ) {
F_57 ( V_2 , V_14 -> V_18 , 1 ) ;
V_14 -> V_18 = V_14 -> V_19 [ V_3 ] ;
F_20 ( V_2 , V_14 -> V_18 ,
V_14 -> V_21 , 0 ,
V_14 -> V_22 ) ;
}
F_2 ( V_2 , V_14 -> V_18 , 0 ,
V_113 ,
V_14 -> V_78 [ V_3 ] ) ;
V_14 -> V_20 = V_3 ;
return 1 ;
}
static int F_58 ( struct V_90 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_2 = F_59 ( V_114 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
unsigned int V_3 ;
V_116 -> type = V_117 ;
V_116 -> V_118 = 1 ;
V_116 -> V_119 . V_120 . V_121 = V_14 -> V_75 ;
if ( V_116 -> V_119 . V_120 . V_122 >= V_14 -> V_75 )
V_116 -> V_119 . V_120 . V_122 = V_14 -> V_75 - 1 ;
V_3 = V_14 -> V_76 [ V_116 -> V_119 . V_120 . V_122 ] ;
strcpy ( V_116 -> V_119 . V_120 . V_28 ,
F_60 ( V_2 , V_49 -> V_50 [ V_3 ] . V_46 , 1 ) ) ;
return 0 ;
}
static int F_61 ( struct V_90 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_59 ( V_114 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
V_124 -> V_119 . V_120 . V_122 [ 0 ] = V_14 -> V_77 [ V_14 -> V_20 ] ;
return 0 ;
}
static int F_62 ( struct V_90 * V_114 ,
struct V_123 * V_124 )
{
struct V_1 * V_2 = F_59 ( V_114 ) ;
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned int V_3 = V_124 -> V_119 . V_120 . V_122 [ 0 ] ;
if ( V_3 >= V_14 -> V_75 )
return - V_125 ;
V_3 = V_14 -> V_76 [ V_3 ] ;
return F_56 ( V_2 , V_3 , 0 ) ;
}
static const struct V_126 * F_63 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_126 * V_129 ;
int V_54 , V_130 ;
V_129 = F_64 ( sizeof( * V_129 ) + sizeof( long ) * ( V_14 -> V_75 + 1 ) ,
V_131 ) ;
if ( ! V_129 )
return NULL ;
V_129 -> V_128 = V_128 ;
V_130 = 0 ;
for ( V_54 = 0 ; V_54 < V_132 ; V_54 ++ ) {
if ( ! V_14 -> V_19 [ V_54 ] )
continue;
V_129 -> V_133 [ V_130 ++ ] =
F_53 ( V_14 -> V_19 [ V_54 ] , 3 ,
V_14 -> V_78 [ V_54 ] , V_134 ) ;
}
return V_129 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
int V_122 )
{
T_1 V_46 = V_49 -> V_50 [ V_122 ] . V_46 ;
T_2 V_101 ;
const char * V_135 ;
struct V_90 * V_109 ;
if ( ! ( F_32 ( V_2 , V_46 ) & V_136 ) )
return 0 ;
V_101 = F_47 ( V_2 , V_46 , V_134 ) ;
V_101 = ( V_101 & V_137 ) >> V_102 ;
if ( V_101 <= 1 )
return 0 ;
V_135 = F_66 ( V_2 , V_49 , V_122 ) ;
return F_44 ( V_2 , V_135 , 0 ,
F_53 ( V_46 , 3 , 0 , V_134 ) , 1 , & V_109 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_54 , V_105 ;
if ( ! V_14 -> V_75 )
return 0 ;
V_14 -> V_138 [ 0 ] = F_63 ( V_2 , & V_139 ) ;
V_14 -> V_138 [ 1 ] = F_63 ( V_2 , & V_140 ) ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
struct V_90 * V_109 ;
int V_130 ;
if ( ! V_14 -> V_138 [ V_54 ] )
return - V_141 ;
V_109 = F_42 ( & V_142 [ V_54 ] , V_2 ) ;
if ( ! V_109 )
return - V_141 ;
V_109 -> V_96 = ( long ) V_14 -> V_138 [ V_54 ] ;
V_105 = F_43 ( V_2 , 0 , V_109 ) ;
if ( V_105 < 0 )
return V_105 ;
for ( V_130 = 0 ; V_130 < V_132 ; V_130 ++ ) {
if ( ! V_14 -> V_19 [ V_130 ] )
continue;
V_105 = F_68 ( V_2 , V_109 , 0 , V_14 -> V_19 [ V_130 ] ) ;
if ( V_105 < 0 )
return V_105 ;
}
}
if ( V_14 -> V_75 > 1 && ! V_14 -> V_80 ) {
V_105 = F_43 ( V_2 , 0 ,
F_42 ( & V_143 , V_2 ) ) ;
if ( V_105 < 0 )
return V_105 ;
}
for ( V_54 = 0 ; V_54 < V_14 -> V_75 ; V_54 ++ ) {
V_105 = F_65 ( V_2 , & V_14 -> V_41 , V_54 ) ;
if ( V_105 < 0 )
return V_105 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_105 ;
if ( ! V_14 -> V_15 . V_38 )
return 0 ;
V_105 = F_70 ( V_2 , V_14 -> V_15 . V_38 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_71 ( V_2 , & V_14 -> V_15 ) ;
if ( V_105 < 0 )
return V_105 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_39 )
return F_73 ( V_2 , V_14 -> V_39 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
unsigned int V_144 ;
T_1 V_32 ;
int V_54 ;
V_144 = 0 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_67 ; V_54 ++ ) {
V_32 = V_49 -> V_68 [ V_54 ] ;
if ( ! F_27 ( V_2 , V_32 ) )
continue;
V_144 = F_75 ( V_2 , V_32 ) ;
if ( V_144 )
break;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_71 ; V_54 ++ ) {
V_32 = V_49 -> V_72 [ V_54 ] ;
F_2 ( V_2 , V_32 , 0 ,
V_145 ,
V_144 ? 0 : V_146 ) ;
}
if ( V_14 -> V_147 == V_148 ||
V_14 -> V_147 == V_149 ||
V_14 -> V_147 == V_150 ) {
unsigned int V_151 = V_144 ? 0x02 : 0x08 ;
F_2 ( V_2 , 0x01 , 0 ,
V_152 , V_151 ) ;
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
T_1 V_32 ;
unsigned int V_153 ;
V_32 = V_49 -> V_50 [ V_14 -> V_81 ] . V_46 ;
V_153 = F_75 ( V_2 , V_32 ) ;
if ( V_153 )
F_56 ( V_2 , V_14 -> V_81 , 0 ) ;
else
F_56 ( V_2 , ! V_14 -> V_81 , 0 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_14 -> V_15 . V_65 ; V_54 ++ )
F_2 ( V_2 , V_14 -> V_15 . V_66 [ V_54 ] , 0 ,
V_154 , V_155 ) ;
if ( V_14 -> V_15 . V_69 )
F_2 ( V_2 , V_14 -> V_15 . V_69 , 0 ,
V_154 , V_155 ) ;
for ( V_54 = 0 ; V_54 < F_33 ( V_14 -> V_15 . V_70 ) ; V_54 ++ ) {
if ( ! V_14 -> V_15 . V_70 [ V_54 ] )
break;
F_2 ( V_2 , V_14 -> V_15 . V_70 [ V_54 ] , 0 ,
V_154 , V_155 ) ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_63 ; V_54 ++ )
F_2 ( V_2 , V_49 -> V_64 [ V_54 ] , 0 ,
V_145 , V_146 ) ;
for ( V_54 = 0 ; V_54 < V_49 -> V_67 ; V_54 ++ ) {
T_1 V_32 = V_49 -> V_68 [ V_54 ] ;
F_2 ( V_2 , V_32 , 0 ,
V_145 , V_156 ) ;
if ( ! V_49 -> V_71 )
continue;
if ( F_27 ( V_2 , V_32 ) ) {
F_2 ( V_2 , V_32 , 0 ,
V_157 ,
V_158 | V_159 ) ;
V_14 -> V_160 = 1 ;
}
}
for ( V_54 = 0 ; V_54 < V_49 -> V_71 ; V_54 ++ )
F_2 ( V_2 , V_49 -> V_72 [ V_54 ] , 0 ,
V_145 , V_146 ) ;
if ( V_14 -> V_160 )
F_74 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_48 * V_49 = & V_14 -> V_41 ;
unsigned int V_7 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_75 ; V_54 ++ ) {
unsigned int V_161 ;
T_1 V_46 = V_49 -> V_50 [ V_54 ] . V_46 ;
if ( ! V_14 -> V_19 [ V_54 ] )
continue;
V_161 = V_162 ;
if ( V_49 -> V_50 [ V_54 ] . type == V_79 ) {
unsigned int V_101 = F_79 ( V_2 , V_46 ) ;
V_101 >>= V_163 ;
if ( V_101 & V_164 )
V_161 = V_165 ;
}
F_2 ( V_2 , V_46 , 0 ,
V_145 , V_161 ) ;
F_2 ( V_2 , V_14 -> V_19 [ V_54 ] , 0 ,
V_154 ,
F_80 ( V_14 -> V_78 [ V_54 ] ) ) ;
if ( V_14 -> V_80 && V_14 -> V_81 == V_54 )
F_2 ( V_2 , V_46 , 0 ,
V_157 ,
V_158 | V_166 ) ;
}
F_56 ( V_2 , V_14 -> V_20 , 1 ) ;
if ( V_14 -> V_80 )
F_76 ( V_2 ) ;
V_7 = 0x000a ;
if ( F_34 ( V_2 , V_167 ) )
V_7 |= 0x0500 ;
if ( F_34 ( V_2 , V_168 ) )
V_7 |= 0x1800 ;
F_4 ( V_2 , V_169 , V_7 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned int V_7 ;
V_7 = 0x0002 ;
V_7 |= 0x0008 ;
if ( F_34 ( V_2 , V_170 ) )
V_7 |= 0x4000 ;
F_4 ( V_2 , V_171 , V_7 ) ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_83 ( V_2 , V_172 ) ;
F_83 ( V_2 , V_173 ) ;
if ( V_14 -> V_174 ) {
F_2 ( V_2 , 0x01 , 0 , V_175 ,
V_14 -> V_174 ) ;
F_2 ( V_2 , 0x01 , 0 , V_176 ,
V_14 -> V_177 ) ;
F_2 ( V_2 , 0x01 , 0 , V_152 ,
V_14 -> V_178 ) ;
}
F_77 ( V_2 ) ;
F_78 ( V_2 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 )
{
int V_105 ;
V_105 = F_55 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_67 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_69 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_72 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
return F_82 ( V_2 ) ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_86 ( V_14 -> V_138 [ 0 ] ) ;
F_86 ( V_14 -> V_138 [ 1 ] ) ;
F_86 ( V_2 -> V_14 ) ;
}
static void F_87 ( struct V_1 * V_2 , unsigned int V_179 )
{
switch ( ( V_179 >> 26 ) & 0x7f ) {
case V_159 :
F_74 ( V_2 ) ;
break;
case V_166 :
F_76 ( V_2 ) ;
break;
}
}
static int F_88 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_105 ;
V_105 = F_89 ( V_2 , & V_14 -> V_41 , NULL ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_36 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_37 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_38 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
V_105 = F_39 ( V_2 ) ;
if ( V_105 < 0 )
return V_105 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 , int V_180 )
{
const struct V_181 * V_49 = V_182 [ V_180 ] ;
if ( ! V_49 )
return;
for (; V_49 -> V_32 ; V_49 ++ )
F_91 ( V_2 , V_49 -> V_32 , V_49 -> V_51 ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_105 ;
V_14 = F_64 ( sizeof( * V_14 ) , V_131 ) ;
if ( ! V_14 )
return - V_141 ;
V_2 -> V_14 = V_14 ;
V_14 -> V_147 =
F_93 ( V_2 , V_183 ,
V_184 , V_185 ) ;
if ( V_14 -> V_147 >= 0 )
F_90 ( V_2 , V_14 -> V_147 ) ;
switch ( V_14 -> V_147 ) {
case V_150 :
case V_148 :
case V_149 :
V_14 -> V_174 = 0x0a ;
V_14 -> V_177 = 0x0a ;
break;
}
V_105 = F_88 ( V_2 ) ;
if ( V_105 < 0 )
goto error;
V_2 -> V_186 = V_187 ;
return 0 ;
error:
F_86 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
return V_105 ;
}
static int T_3 F_94 ( void )
{
return F_95 ( & V_188 ) ;
}
static void T_4 F_96 ( void )
{
F_97 ( & V_188 ) ;
}
