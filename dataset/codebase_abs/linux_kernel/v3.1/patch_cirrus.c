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
static int F_19 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
unsigned int V_16 ,
unsigned int V_17 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_18 = V_5 -> V_19 [ V_5 -> V_20 ] ;
V_5 -> V_21 = V_16 ;
V_5 -> V_22 = V_17 ;
F_20 ( V_2 , V_5 -> V_18 , V_16 , 0 , V_17 ) ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_22 ( V_2 , V_5 -> V_18 ) ;
V_5 -> V_18 = 0 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_23 * V_24 = V_5 -> V_25 ;
V_2 -> V_26 = V_24 ;
V_2 -> V_27 = 0 ;
V_24 -> V_28 = L_1 ;
V_24 -> V_29 [ V_30 ] = V_31 ;
V_24 -> V_29 [ V_30 ] . V_32 = V_5 -> V_33 [ 0 ] ;
V_24 -> V_29 [ V_30 ] . V_34 =
V_5 -> V_15 . V_35 ;
V_24 -> V_29 [ V_36 ] = V_37 ;
V_24 -> V_29 [ V_36 ] . V_32 =
V_5 -> V_19 [ V_5 -> V_20 ] ;
V_2 -> V_27 ++ ;
if ( ! V_5 -> V_15 . V_38 && ! V_5 -> V_39 )
return 0 ;
V_24 ++ ;
V_24 -> V_28 = L_2 ;
V_24 -> V_40 = V_5 -> V_41 . V_42 [ 0 ] ;
if ( ! V_24 -> V_40 )
V_24 -> V_40 = V_43 ;
if ( V_5 -> V_15 . V_38 ) {
V_24 -> V_29 [ V_30 ] =
V_44 ;
V_24 -> V_29 [ V_30 ] . V_32 =
V_5 -> V_15 . V_38 ;
}
if ( V_5 -> V_39 ) {
V_24 -> V_29 [ V_36 ] =
V_45 ;
V_24 -> V_29 [ V_36 ] . V_32 = V_5 -> V_39 ;
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
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
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
int V_54 , V_3 ;
T_1 V_32 ;
V_32 = V_2 -> V_55 ;
for ( V_54 = 0 ; V_54 < V_2 -> V_56 ; V_54 ++ , V_32 ++ ) {
unsigned int type ;
type = F_31 ( F_32 ( V_2 , V_32 ) ) ;
if ( type != V_57 )
continue;
V_3 = F_33 ( V_2 , V_32 , V_46 , false ) ;
if ( V_3 >= 0 ) {
* V_53 = V_3 ;
return V_32 ;
}
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 , T_1 V_32 )
{
unsigned int V_51 ;
V_51 = F_28 ( V_2 , V_32 ) ;
return ( F_35 ( V_51 ) != V_58 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
int V_54 , V_59 ;
T_1 V_47 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_60 ; V_54 ++ ) {
V_47 = F_24 ( V_2 , V_49 -> V_61 [ V_54 ] ) ;
if ( ! V_47 )
break;
V_5 -> V_33 [ V_54 ] = V_47 ;
}
V_5 -> V_15 . V_62 = V_54 ;
V_5 -> V_15 . V_63 = V_5 -> V_33 ;
V_5 -> V_15 . V_35 = V_54 * 2 ;
V_59 = 0 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_64 ; V_54 ++ ) {
V_47 = F_24 ( V_2 , V_49 -> V_65 [ V_54 ] ) ;
if ( ! V_47 )
break;
if ( ! V_54 )
V_5 -> V_15 . V_66 = V_47 ;
else
V_5 -> V_15 . V_67 [ V_59 ++ ] = V_47 ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_68 ; V_54 ++ ) {
V_47 = F_24 ( V_2 , V_49 -> V_69 [ V_54 ] ) ;
if ( ! V_47 )
break;
V_5 -> V_15 . V_67 [ V_59 ++ ] = V_47 ;
}
if ( V_49 -> V_70 == V_71 ) {
V_49 -> V_68 = V_49 -> V_60 ;
memcpy ( V_49 -> V_69 , V_49 -> V_61 ,
sizeof( V_49 -> V_69 ) ) ;
V_49 -> V_60 = 0 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_72 ; V_54 ++ ) {
T_1 V_46 = V_49 -> V_50 [ V_54 ] . V_46 ;
V_5 -> V_73 [ V_5 -> V_72 ] = V_54 ;
V_5 -> V_74 [ V_54 ] = V_5 -> V_72 ++ ;
V_5 -> V_20 = V_54 ;
V_5 -> V_19 [ V_54 ] = F_30 ( V_2 , V_46 , & V_5 -> V_75 [ V_54 ] ) ;
}
if ( ! V_5 -> V_72 )
return 0 ;
if ( V_5 -> V_72 == 2 &&
V_49 -> V_50 [ 0 ] . type == V_76 &&
V_49 -> V_50 [ 1 ] . type == V_76 ) {
if ( F_26 ( V_2 , V_49 -> V_50 [ 0 ] . V_46 ) ) {
if ( ! F_26 ( V_2 , V_49 -> V_50 [ 1 ] . V_46 ) ) {
V_5 -> V_77 = 1 ;
V_5 -> V_78 = 0 ;
}
} else {
if ( F_26 ( V_2 , V_49 -> V_50 [ 1 ] . V_46 ) ) {
V_5 -> V_77 = 1 ;
V_5 -> V_78 = 1 ;
}
}
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
T_1 V_32 ;
if ( ! V_49 -> V_79 )
return 0 ;
if ( F_25 ( V_2 , V_49 -> V_80 [ 0 ] , & V_32 , 1 ) < 1 )
return 0 ;
V_5 -> V_15 . V_38 = V_32 ;
V_5 -> V_15 . V_81 = 1 ;
if ( V_49 -> V_79 > 1 &&
F_25 ( V_2 , V_49 -> V_80 [ 1 ] , & V_32 , 1 ) > 0 ) {
V_5 -> V_82 [ 0 ] = V_32 ;
V_2 -> V_82 = V_5 -> V_82 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
int V_3 ;
if ( V_49 -> V_83 )
V_5 -> V_39 = F_30 ( V_2 , V_49 -> V_83 , & V_3 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , const char * V_28 , int V_84 ,
unsigned int V_85 , int V_86 , struct V_87 * * V_88 )
{
char V_89 [ 44 ] ;
struct V_90 V_91 =
F_41 ( V_89 , V_84 , 0 , 0 , V_92 ) ;
V_91 . V_93 = V_85 ;
snprintf ( V_89 , sizeof( V_89 ) , L_3 , V_28 , V_94 [ V_86 ] ) ;
* V_88 = F_42 ( & V_91 , V_2 ) ;
( * V_88 ) -> V_95 . V_96 = V_97 ;
return F_43 ( V_2 , 0 , * V_88 ) ;
}
static int F_44 ( struct V_1 * V_2 , const char * V_28 ,
int V_84 , unsigned int V_85 , int V_86 ,
struct V_87 * * V_88 )
{
char V_89 [ 44 ] ;
struct V_90 V_91 =
F_45 ( V_89 , V_84 , 0 , 0 , V_92 ) ;
V_91 . V_93 = V_85 ;
snprintf ( V_89 , sizeof( V_89 ) , L_4 , V_28 , V_94 [ V_86 ] ) ;
* V_88 = F_42 ( & V_91 , V_2 ) ;
( * V_88 ) -> V_95 . V_96 = V_97 ;
return F_43 ( V_2 , 0 , * V_88 ) ;
}
static void F_46 ( struct V_1 * V_2 , T_1 V_47 )
{
unsigned int V_98 ;
V_98 = F_47 ( V_2 , V_47 , V_92 ) ;
V_98 &= ~ ( 0x7f << V_99 ) ;
V_98 |= ( ( V_98 >> V_100 ) & 0x7f )
<< V_99 ;
F_48 ( V_2 , V_47 , V_92 , V_98 ) ;
}
static int F_49 ( struct V_1 * V_2 , T_1 V_47 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_101 [ 4 ] ;
int V_102 ;
V_5 -> V_103 =
F_50 ( L_5 , NULL ) ;
V_102 = F_43 ( V_2 , V_47 , V_5 -> V_103 ) ;
if ( V_102 < 0 )
return V_102 ;
F_51 ( V_2 , V_47 , V_92 , V_101 ) ;
V_5 -> V_104 =
F_50 ( L_6 , V_101 ) ;
V_102 = F_43 ( V_2 , V_47 , V_5 -> V_104 ) ;
if ( V_102 < 0 )
return V_102 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , T_1 V_47 , int V_3 ,
int V_105 , int type )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const char * V_28 ;
int V_102 , V_84 ;
struct V_87 * V_106 ;
static const char * const V_107 [] = {
L_7 , L_8 , L_9
} ;
static const char * const V_60 [] = {
L_10 , L_11 , L_12
} ;
F_46 ( V_2 , V_47 ) ;
if ( ! V_5 -> V_103 ) {
V_102 = F_49 ( V_2 , V_47 ) ;
if ( V_102 < 0 )
return V_102 ;
}
V_84 = 0 ;
switch ( type ) {
case V_108 :
V_28 = L_13 ;
V_84 = V_3 ;
break;
case V_71 :
if ( V_105 > 1 )
V_28 = V_107 [ V_3 ] ;
else
V_28 = L_14 ;
break;
default:
if ( V_105 > 1 )
V_28 = V_60 [ V_3 ] ;
else
V_28 = L_15 ;
break;
}
V_102 = F_40 ( V_2 , V_28 , V_84 ,
F_53 ( V_47 , 3 , 0 , V_92 ) , 0 , & V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_54 ( V_5 -> V_103 , V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_44 ( V_2 , V_28 , V_84 ,
F_53 ( V_47 , 3 , 0 , V_92 ) , 0 , & V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_54 ( V_5 -> V_104 , V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
int V_54 , V_102 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_60 ; V_54 ++ ) {
V_102 = F_52 ( V_2 , F_24 ( V_2 , V_49 -> V_61 [ V_54 ] ) ,
V_54 , V_49 -> V_60 , V_49 -> V_70 ) ;
if ( V_102 < 0 )
return V_102 ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_64 ; V_54 ++ ) {
V_102 = F_52 ( V_2 , F_24 ( V_2 , V_49 -> V_65 [ V_54 ] ) ,
V_54 , V_49 -> V_64 , V_108 ) ;
if ( V_102 < 0 )
return V_102 ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_68 ; V_54 ++ ) {
V_102 = F_52 ( V_2 , F_24 ( V_2 , V_49 -> V_69 [ V_54 ] ) ,
V_54 , V_49 -> V_68 , V_71 ) ;
if ( V_102 < 0 )
return V_102 ;
}
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_109 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_20 == V_3 && ! V_109 )
return 0 ;
if ( V_5 -> V_18 && V_5 -> V_18 != V_5 -> V_19 [ V_3 ] ) {
F_57 ( V_2 , V_5 -> V_18 , 1 ) ;
V_5 -> V_18 = V_5 -> V_19 [ V_3 ] ;
F_20 ( V_2 , V_5 -> V_18 ,
V_5 -> V_21 , 0 ,
V_5 -> V_22 ) ;
}
F_2 ( V_2 , V_5 -> V_18 , 0 ,
V_110 ,
V_5 -> V_75 [ V_3 ] ) ;
V_5 -> V_20 = V_3 ;
return 1 ;
}
static int F_58 ( struct V_87 * V_111 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
unsigned int V_3 ;
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_116 . V_117 . V_118 = V_5 -> V_72 ;
if ( V_113 -> V_116 . V_117 . V_119 >= V_5 -> V_72 )
V_113 -> V_116 . V_117 . V_119 = V_5 -> V_72 - 1 ;
V_3 = V_5 -> V_73 [ V_113 -> V_116 . V_117 . V_119 ] ;
strcpy ( V_113 -> V_116 . V_117 . V_28 ,
F_60 ( V_2 , V_49 -> V_50 [ V_3 ] . V_46 , 1 ) ) ;
return 0 ;
}
static int F_61 ( struct V_87 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_121 -> V_116 . V_117 . V_119 [ 0 ] = V_5 -> V_74 [ V_5 -> V_20 ] ;
return 0 ;
}
static int F_62 ( struct V_87 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_3 = V_121 -> V_116 . V_117 . V_119 [ 0 ] ;
if ( V_3 >= V_5 -> V_72 )
return - V_122 ;
V_3 = V_5 -> V_73 [ V_3 ] ;
return F_56 ( V_2 , V_3 , 0 ) ;
}
static const struct V_123 * F_63 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_123 * V_126 ;
int V_54 , V_127 ;
V_126 = F_64 ( sizeof( * V_126 ) + sizeof( long ) * ( V_5 -> V_72 + 1 ) ,
V_128 ) ;
if ( ! V_126 )
return NULL ;
V_126 -> V_125 = V_125 ;
V_127 = 0 ;
for ( V_54 = 0 ; V_54 < V_129 ; V_54 ++ ) {
if ( ! V_5 -> V_19 [ V_54 ] )
continue;
V_126 -> V_130 [ V_127 ++ ] =
F_53 ( V_5 -> V_19 [ V_54 ] , 3 ,
V_5 -> V_75 [ V_54 ] , V_131 ) ;
}
return V_126 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
int V_119 )
{
T_1 V_46 = V_49 -> V_50 [ V_119 ] . V_46 ;
T_2 V_98 ;
const char * V_132 ;
struct V_87 * V_106 ;
if ( ! ( F_32 ( V_2 , V_46 ) & V_133 ) )
return 0 ;
V_98 = F_47 ( V_2 , V_46 , V_131 ) ;
V_98 = ( V_98 & V_134 ) >> V_99 ;
if ( V_98 <= 1 )
return 0 ;
V_132 = F_66 ( V_2 , V_49 , V_119 ) ;
return F_44 ( V_2 , V_132 , 0 ,
F_53 ( V_46 , 3 , 0 , V_131 ) , 1 , & V_106 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_54 , V_102 ;
if ( ! V_5 -> V_72 )
return 0 ;
V_5 -> V_135 [ 0 ] = F_63 ( V_2 , & V_136 ) ;
V_5 -> V_135 [ 1 ] = F_63 ( V_2 , & V_137 ) ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
struct V_87 * V_106 ;
int V_127 ;
if ( ! V_5 -> V_135 [ V_54 ] )
return - V_138 ;
V_106 = F_42 ( & V_139 [ V_54 ] , V_2 ) ;
if ( ! V_106 )
return - V_138 ;
V_106 -> V_93 = ( long ) V_5 -> V_135 [ V_54 ] ;
V_102 = F_43 ( V_2 , 0 , V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
for ( V_127 = 0 ; V_127 < V_129 ; V_127 ++ ) {
if ( ! V_5 -> V_19 [ V_127 ] )
continue;
V_102 = F_68 ( V_2 , V_106 , 0 , V_5 -> V_19 [ V_127 ] ) ;
if ( V_102 < 0 )
return V_102 ;
}
}
if ( V_5 -> V_72 > 1 && ! V_5 -> V_77 ) {
V_102 = F_43 ( V_2 , 0 ,
F_42 ( & V_140 , V_2 ) ) ;
if ( V_102 < 0 )
return V_102 ;
}
for ( V_54 = 0 ; V_54 < V_5 -> V_72 ; V_54 ++ ) {
V_102 = F_65 ( V_2 , & V_5 -> V_41 , V_54 ) ;
if ( V_102 < 0 )
return V_102 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_102 ;
if ( ! V_5 -> V_15 . V_38 )
return 0 ;
V_102 = F_70 ( V_2 , V_5 -> V_15 . V_38 ,
V_5 -> V_15 . V_38 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_71 ( V_2 , & V_5 -> V_15 ) ;
if ( V_102 < 0 )
return V_102 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_39 )
return F_73 ( V_2 , V_5 -> V_39 ) ;
return 0 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
unsigned int V_141 ;
unsigned int V_142 ;
T_1 V_32 ;
int V_54 ;
V_142 = 0 ;
if ( V_49 -> V_79 ) {
V_32 = V_49 -> V_80 [ 0 ] ;
if ( F_27 ( V_2 , V_32 ) ) {
if ( F_75 ( V_2 , V_32 )
)
V_142 = 1 ;
}
}
V_141 = 0 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_64 ; V_54 ++ ) {
V_32 = V_49 -> V_65 [ V_54 ] ;
if ( ! F_27 ( V_2 , V_32 ) )
continue;
V_141 = F_75 ( V_2 , V_32 ) ;
if ( V_141 )
break;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_68 ; V_54 ++ ) {
V_32 = V_49 -> V_69 [ V_54 ] ;
F_2 ( V_2 , V_32 , 0 ,
V_143 ,
V_141 ? 0 : V_144 ) ;
if ( V_5 -> V_6 == V_145 ) {
F_2 ( V_2 , V_32 , 0 ,
V_143 ,
V_142 ? 0 : V_144 ) ;
}
}
if ( V_5 -> V_146 == V_147 ||
V_5 -> V_146 == V_148 ||
V_5 -> V_146 == V_149 ) {
unsigned int V_150 = V_141 ? 0x02 : 0x08 ;
F_2 ( V_2 , 0x01 , 0 ,
V_151 , V_150 ) ;
}
if ( V_5 -> V_6 == V_145 ) {
for ( V_54 = 0 ; V_54 < V_49 -> V_64 ; V_54 ++ ) {
V_32 = V_49 -> V_65 [ V_54 ] ;
F_2 ( V_2 , V_32 , 0 ,
V_143 ,
( V_142 && V_5 -> V_152 ) ? 0 : V_153 ) ;
}
if ( V_49 -> V_79 ) {
V_32 = V_49 -> V_80 [ 0 ] ;
F_2 ( V_2 , V_32 , 0 ,
V_143 ,
V_142 ? V_144 : 0 ) ;
}
}
}
static void F_76 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
T_1 V_32 ;
unsigned int V_154 ;
V_32 = V_49 -> V_50 [ V_5 -> V_78 ] . V_46 ;
V_154 = F_75 ( V_2 , V_32 ) ;
if ( V_5 -> V_6 == V_145 ) {
if ( V_154 ) {
V_5 -> V_155 = V_5 -> V_20 ;
V_5 -> V_20 = V_5 -> V_78 ;
} else {
V_5 -> V_20 = V_5 -> V_155 ;
}
F_77 ( V_2 , V_5 -> V_18 , 0 ,
V_110 ,
V_5 -> V_75 [ V_5 -> V_20 ] ) ;
} else {
if ( V_154 )
F_56 ( V_2 , V_5 -> V_78 , 0 ) ;
else
F_56 ( V_2 , ! V_5 -> V_78 , 0 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_5 -> V_15 . V_62 ; V_54 ++ )
F_2 ( V_2 , V_5 -> V_15 . V_63 [ V_54 ] , 0 ,
V_156 , V_157 ) ;
if ( V_5 -> V_15 . V_66 )
F_2 ( V_2 , V_5 -> V_15 . V_66 , 0 ,
V_156 , V_157 ) ;
for ( V_54 = 0 ; V_54 < F_79 ( V_5 -> V_15 . V_67 ) ; V_54 ++ ) {
if ( ! V_5 -> V_15 . V_67 [ V_54 ] )
break;
F_2 ( V_2 , V_5 -> V_15 . V_67 [ V_54 ] , 0 ,
V_156 , V_157 ) ;
}
for ( V_54 = 0 ; V_54 < V_49 -> V_60 ; V_54 ++ )
F_2 ( V_2 , V_49 -> V_61 [ V_54 ] , 0 ,
V_143 , V_144 ) ;
for ( V_54 = 0 ; V_54 < V_49 -> V_64 ; V_54 ++ ) {
T_1 V_32 = V_49 -> V_65 [ V_54 ] ;
F_2 ( V_2 , V_32 , 0 ,
V_143 , V_153 ) ;
if ( ! V_49 -> V_68 )
continue;
if ( F_32 ( V_2 , V_32 ) & V_158 ) {
F_2 ( V_2 , V_32 , 0 ,
V_159 ,
V_160 | V_161 ) ;
V_5 -> V_162 = 1 ;
}
}
for ( V_54 = 0 ; V_54 < V_49 -> V_68 ; V_54 ++ )
F_2 ( V_2 , V_49 -> V_69 [ V_54 ] , 0 ,
V_143 , V_144 ) ;
if ( V_5 -> V_162 || V_5 -> V_163 )
F_74 ( V_2 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
unsigned int V_9 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_72 ; V_54 ++ ) {
unsigned int V_164 ;
T_1 V_46 = V_49 -> V_50 [ V_54 ] . V_46 ;
if ( ! V_5 -> V_19 [ V_54 ] )
continue;
V_164 = V_165 ;
if ( V_49 -> V_50 [ V_54 ] . type == V_76 ) {
unsigned int V_98 = F_81 ( V_2 , V_46 ) ;
V_98 >>= V_166 ;
if ( V_98 & V_167 )
V_164 = V_168 ;
}
F_2 ( V_2 , V_46 , 0 ,
V_143 , V_164 ) ;
F_2 ( V_2 , V_5 -> V_19 [ V_54 ] , 0 ,
V_156 ,
F_82 ( V_5 -> V_75 [ V_54 ] ) ) ;
if ( V_5 -> V_77 && V_5 -> V_78 == V_54 )
F_2 ( V_2 , V_46 , 0 ,
V_159 ,
V_160 | V_169 ) ;
}
if ( V_5 -> V_6 == V_145 ) {
if ( V_5 -> V_77 )
F_76 ( V_2 ) ;
else {
V_5 -> V_18 = V_5 -> V_19 [ V_5 -> V_20 ] ;
F_2 ( V_2 , V_5 -> V_18 , 0 ,
V_110 ,
V_5 -> V_75 [ V_5 -> V_20 ] ) ;
}
} else {
F_56 ( V_2 , V_5 -> V_20 , 1 ) ;
if ( V_5 -> V_77 )
F_76 ( V_2 ) ;
V_9 = 0x000a ;
if ( F_34 ( V_2 , V_170 ) )
V_9 |= 0x0500 ;
if ( F_34 ( V_2 , V_171 ) )
V_9 |= 0x1800 ;
F_4 ( V_2 , V_172 , V_9 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
V_9 = 0x0002 ;
V_9 |= 0x0008 ;
if ( F_34 ( V_2 , V_173 ) )
V_9 |= 0x4000 ;
F_4 ( V_2 , V_174 , V_9 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_85 ( V_2 , V_175 ) ;
F_85 ( V_2 , V_176 ) ;
if ( V_5 -> V_177 ) {
F_2 ( V_2 , 0x01 , 0 , V_178 ,
V_5 -> V_177 ) ;
F_2 ( V_2 , 0x01 , 0 , V_179 ,
V_5 -> V_180 ) ;
F_2 ( V_2 , 0x01 , 0 , V_151 ,
V_5 -> V_181 ) ;
}
F_78 ( V_2 ) ;
F_80 ( V_2 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_102 ;
V_102 = F_55 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_67 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_69 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_72 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
return F_84 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_88 ( V_5 -> V_135 [ 0 ] ) ;
F_88 ( V_5 -> V_135 [ 1 ] ) ;
F_88 ( V_2 -> V_5 ) ;
}
static void F_89 ( struct V_1 * V_2 , unsigned int V_182 )
{
switch ( ( V_182 >> 26 ) & 0x7f ) {
case V_161 :
F_74 ( V_2 ) ;
break;
case V_169 :
F_76 ( V_2 ) ;
break;
}
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_102 ;
V_102 = F_91 ( V_2 , & V_5 -> V_41 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_36 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_37 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_38 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_39 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , int V_183 ,
const struct V_184 * * V_185 )
{
const struct V_184 * V_49 = V_185 [ V_183 ] ;
if ( ! V_49 )
return;
for (; V_49 -> V_32 ; V_49 ++ )
F_93 ( V_2 , V_49 -> V_32 , V_49 -> V_51 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_102 ;
V_5 = F_64 ( sizeof( * V_5 ) , V_128 ) ;
if ( ! V_5 )
return - V_138 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_6 = V_186 ;
V_5 -> V_146 =
F_95 ( V_2 , V_187 ,
V_188 , V_189 ) ;
if ( V_5 -> V_146 >= 0 )
F_92 ( V_2 , V_5 -> V_146 , V_190 ) ;
switch ( V_5 -> V_146 ) {
case V_149 :
case V_147 :
case V_148 :
V_5 -> V_177 = 0x0a ;
V_5 -> V_180 = 0x0a ;
break;
}
V_102 = F_90 ( V_2 ) ;
if ( V_102 < 0 )
goto error;
V_2 -> V_191 = V_192 ;
return 0 ;
error:
F_88 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return V_102 ;
}
static int F_96 ( struct V_87 * V_111 ,
struct V_112 * V_113 )
{
V_113 -> type = V_193 ;
V_113 -> V_115 = 1 ;
V_113 -> V_116 . integer . V_194 = 0 ;
V_113 -> V_116 . integer . V_195 = 3 ;
return 0 ;
}
static int F_97 ( struct V_87 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
V_121 -> V_116 . integer . V_116 [ 0 ] =
F_1 ( V_2 , V_196 ) & 0x0003 ;
return 0 ;
}
static int F_98 ( struct V_87 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
unsigned int V_197 = V_121 -> V_116 . integer . V_116 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_196 ) ;
unsigned int V_198 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_197 & 0x0003 ) ;
if ( V_198 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_196 , V_9 ) ;
return 1 ;
}
}
static void F_99 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_199 , V_9 ;
V_9 = F_1 ( V_2 , V_200 ) ;
if ( V_5 -> V_177 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_152 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_200 , V_9 ) ;
if ( ( V_5 -> V_177 || V_5 -> V_152 ) &&
F_34 ( V_2 , V_201 ) ) {
V_199 = F_28 ( V_2 , V_201 ) ;
V_199 &= ~ V_202 ;
V_199 |= ( V_58 << V_203 ) ;
F_93 ( V_2 , V_201 , V_199 ) ;
}
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_79 ; V_54 ++ ) {
T_1 V_32 = V_49 -> V_80 [ V_54 ] ;
if ( ! V_49 -> V_68 )
continue;
if ( F_32 ( V_2 , V_32 ) & V_158 ) {
F_2 ( V_2 , V_32 , 0 ,
V_159 ,
V_160 | V_204 ) ;
V_5 -> V_163 = 1 ;
}
}
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_85 ( V_2 , V_205 ) ;
F_85 ( V_2 , V_206 ) ;
F_99 ( V_2 ) ;
if ( V_5 -> V_177 ) {
F_2 ( V_2 , 0x01 , 0 , V_178 ,
V_5 -> V_177 ) ;
F_2 ( V_2 , 0x01 , 0 , V_179 ,
V_5 -> V_180 ) ;
F_2 ( V_2 , 0x01 , 0 , V_151 ,
V_5 -> V_181 ) ;
}
F_78 ( V_2 ) ;
F_80 ( V_2 ) ;
F_100 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_87 * V_111 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
return F_103 ( & V_5 -> V_207 , V_113 ) ;
}
static int F_104 ( struct V_87 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_121 -> V_116 . V_117 . V_119 [ 0 ] = V_5 -> V_20 ;
return 0 ;
}
static int F_105 ( struct V_87 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_59 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
return F_106 ( V_2 , & V_5 -> V_207 , V_121 ,
V_5 -> V_19 [ 0 ] , & V_5 -> V_20 ) ;
}
static int F_107 ( struct V_1 * V_2 , int V_119 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
const struct V_208 * V_209 = & V_5 -> V_207 ;
T_1 V_46 = V_49 -> V_50 [ V_119 ] . V_46 ;
struct V_87 * V_106 ;
T_2 V_98 ;
if ( ! ( F_32 ( V_2 , V_46 ) & V_133 ) )
return 0 ;
V_98 = F_47 ( V_2 , V_46 , V_131 ) ;
V_98 = ( V_98 & V_134 ) >> V_99 ;
if ( V_98 <= 1 )
return 0 ;
return F_44 ( V_2 , V_209 -> V_118 [ V_119 ] . V_132 , 0 ,
F_53 ( V_46 , 3 , 0 , V_131 ) , 1 , & V_106 ) ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
struct V_208 * V_209 = & V_5 -> V_207 ;
int V_54 , V_102 , V_210 ;
const char * V_132 ;
if ( ! V_5 -> V_72 )
return 0 ;
V_5 -> V_135 [ 0 ] = F_63 ( V_2 , & V_136 ) ;
V_5 -> V_135 [ 1 ] = F_63 ( V_2 , & V_137 ) ;
for ( V_54 = 0 ; V_54 < 2 ; V_54 ++ ) {
struct V_87 * V_106 ;
int V_127 ;
if ( ! V_5 -> V_135 [ V_54 ] )
return - V_138 ;
V_106 = F_42 ( & V_139 [ V_54 ] , V_2 ) ;
if ( ! V_106 )
return - V_138 ;
V_106 -> V_93 = ( long ) V_5 -> V_135 [ V_54 ] ;
V_102 = F_43 ( V_2 , 0 , V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
for ( V_127 = 0 ; V_127 < V_129 ; V_127 ++ ) {
if ( ! V_5 -> V_19 [ V_127 ] )
continue;
V_102 = F_68 ( V_2 , V_106 , 0 , V_5 -> V_19 [ V_127 ] ) ;
if ( V_102 < 0 )
return V_102 ;
}
}
for ( V_54 = 0 ; V_54 < V_5 -> V_72 ; V_54 ++ ) {
V_132 = F_66 ( V_2 , V_49 , V_54 ) ;
F_109 ( V_209 , V_132 , V_5 -> V_75 [ V_54 ] , & V_210 ) ;
V_102 = F_107 ( V_2 , V_54 ) ;
if ( V_102 < 0 )
return V_102 ;
}
if ( ( V_5 -> V_72 == 2 && ! V_5 -> V_77 ) ||
( V_5 -> V_72 == 3 ) ) {
V_102 = F_43 ( V_2 , V_5 -> V_19 [ 0 ] ,
F_42 ( & V_211 , V_2 ) ) ;
if ( V_102 < 0 )
return V_102 ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 )
{
T_1 V_47 = V_212 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
struct V_87 * V_106 ;
int V_102 ;
char * V_28 = L_16 ;
F_46 ( V_2 , V_47 ) ;
if ( ! V_5 -> V_103 ) {
V_102 = F_49 ( V_2 , V_47 ) ;
if ( V_102 < 0 )
return V_102 ;
}
V_102 = F_40 ( V_2 , V_28 , 0 ,
F_53 ( V_47 , 3 , 0 , V_92 ) , 0 , & V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_54 ( V_5 -> V_103 , V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_44 ( V_2 , V_28 , 0 ,
F_53 ( V_47 , 3 , 0 , V_92 ) , 0 , & V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_54 ( V_5 -> V_104 , V_106 ) ;
if ( V_102 < 0 )
return V_102 ;
if ( V_49 -> V_68 ) {
V_102 = F_43 ( V_2 , 0 ,
F_42 ( & V_213 , V_2 ) ) ;
if ( V_102 < 0 )
return V_102 ;
}
return V_102 ;
}
static int F_111 ( struct V_1 * V_2 )
{
int V_102 ;
V_102 = F_110 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_108 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_69 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
return F_101 ( V_2 ) ;
}
static void F_112 ( struct V_1 * V_2 , unsigned int V_182 )
{
switch ( ( V_182 >> 26 ) & 0x3f ) {
case V_161 :
case V_204 :
F_74 ( V_2 ) ;
break;
case V_169 :
F_76 ( V_2 ) ;
break;
}
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_48 * V_49 = & V_5 -> V_41 ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_49 -> V_72 ; V_54 ++ ) {
T_1 V_46 = V_49 -> V_50 [ V_54 ] . V_46 ;
V_5 -> V_19 [ V_54 ] = F_30 ( V_2 , V_46 , & V_5 -> V_75 [ V_54 ] ) ;
V_5 -> V_20 = V_5 -> V_155 = V_54 ;
V_5 -> V_72 ++ ;
if ( F_26 ( V_2 , V_54 ) && V_49 -> V_72 >= 2 ) {
V_5 -> V_77 = 1 ;
V_5 -> V_78 = V_54 ;
}
}
return 0 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_102 ;
V_102 = F_91 ( V_2 , & V_5 -> V_41 , NULL ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_36 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_113 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_38 ( V_2 ) ;
if ( V_102 < 0 )
return V_102 ;
return 0 ;
}
static int F_115 ( struct V_1 * V_2 , T_3 V_214 )
{
unsigned int V_9 ;
F_116 ( V_2 ) ;
F_2 ( V_2 , V_212 , 0 ,
V_215 , V_216 ) ;
F_2 ( V_2 , V_217 , 0 ,
V_215 , V_216 ) ;
V_9 = F_1 ( V_2 , V_200 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_200 , V_9 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_102 ;
V_5 = F_64 ( sizeof( * V_5 ) , V_128 ) ;
if ( ! V_5 )
return - V_138 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_6 = V_145 ;
V_5 -> V_146 =
F_95 ( V_2 , V_218 ,
V_219 , V_220 ) ;
if ( V_5 -> V_146 >= 0 )
F_92 ( V_2 , V_5 -> V_146 , V_221 ) ;
switch ( V_5 -> V_146 ) {
case V_222 :
F_118 ( L_17 ,
V_219 [ V_5 -> V_146 ] ) ;
V_5 -> V_152 = 1 ;
break;
}
F_99 ( V_2 ) ;
V_102 = F_114 ( V_2 ) ;
if ( V_102 < 0 )
goto error;
V_2 -> V_191 = V_223 ;
return 0 ;
error:
F_88 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return V_102 ;
}
static int T_4 F_119 ( void )
{
return F_120 ( & V_224 ) ;
}
static void T_5 F_121 ( void )
{
F_122 ( & V_224 ) ;
}
