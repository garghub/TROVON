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
V_26 -> V_31 [ V_38 ] = V_39 ;
V_26 -> V_31 [ V_38 ] . V_34 =
V_5 -> V_22 [ V_5 -> V_21 ] ;
V_2 -> V_29 ++ ;
if ( ! V_5 -> V_15 . V_40 && ! V_5 -> V_41 )
return 0 ;
V_26 ++ ;
V_26 -> V_30 = L_2 ;
V_26 -> V_42 = V_5 -> V_43 . V_44 [ 0 ] ;
if ( ! V_26 -> V_42 )
V_26 -> V_42 = V_45 ;
if ( V_5 -> V_15 . V_40 ) {
V_26 -> V_31 [ V_32 ] =
V_46 ;
V_26 -> V_31 [ V_32 ] . V_34 =
V_5 -> V_15 . V_40 ;
}
if ( V_5 -> V_41 ) {
V_26 -> V_31 [ V_38 ] =
V_47 ;
V_26 -> V_31 [ V_38 ] . V_34 = V_5 -> V_41 ;
}
V_2 -> V_29 ++ ;
return 0 ;
}
static T_1 F_25 ( struct V_1 * V_2 , T_1 V_48 )
{
T_1 V_49 ;
if ( ! V_48 )
return 0 ;
if ( F_26 ( V_2 , V_48 , & V_49 , 1 ) != 1 )
return 0 ;
return V_49 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
T_1 V_48 = V_51 -> V_52 [ V_3 ] . V_48 ;
unsigned int V_53 ;
if ( ! F_28 ( V_2 , V_48 ) )
return 0 ;
V_53 = F_29 ( V_2 , V_48 ) ;
return ( F_30 ( V_53 ) != V_54 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_1 V_48 ,
unsigned int * V_55 )
{
int V_56 , V_3 ;
T_1 V_34 ;
V_34 = V_2 -> V_57 ;
for ( V_56 = 0 ; V_56 < V_2 -> V_58 ; V_56 ++ , V_34 ++ ) {
unsigned int type ;
type = F_32 ( F_33 ( V_2 , V_34 ) ) ;
if ( type != V_59 )
continue;
V_3 = F_34 ( V_2 , V_34 , V_48 , false ) ;
if ( V_3 >= 0 ) {
* V_55 = V_3 ;
return V_34 ;
}
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_34 )
{
unsigned int V_53 ;
V_53 = F_29 ( V_2 , V_34 ) ;
return ( F_36 ( V_53 ) != V_60 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
int V_56 , V_61 ;
T_1 V_49 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_62 ; V_56 ++ ) {
V_49 = F_25 ( V_2 , V_51 -> V_63 [ V_56 ] ) ;
if ( ! V_49 )
break;
V_5 -> V_35 [ V_56 ] = V_49 ;
}
V_5 -> V_15 . V_64 = V_56 ;
V_5 -> V_15 . V_65 = V_5 -> V_35 ;
V_5 -> V_15 . V_37 = V_56 * 2 ;
V_61 = 0 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_66 ; V_56 ++ ) {
V_49 = F_25 ( V_2 , V_51 -> V_67 [ V_56 ] ) ;
if ( ! V_49 )
break;
if ( ! V_56 )
V_5 -> V_15 . V_68 = V_49 ;
else
V_5 -> V_15 . V_69 [ V_61 ++ ] = V_49 ;
}
for ( V_56 = 0 ; V_56 < V_51 -> V_70 ; V_56 ++ ) {
V_49 = F_25 ( V_2 , V_51 -> V_71 [ V_56 ] ) ;
if ( ! V_49 )
break;
V_5 -> V_15 . V_69 [ V_61 ++ ] = V_49 ;
}
if ( V_51 -> V_72 == V_73 ) {
V_51 -> V_70 = V_51 -> V_62 ;
memcpy ( V_51 -> V_71 , V_51 -> V_63 ,
sizeof( V_51 -> V_71 ) ) ;
V_51 -> V_62 = 0 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_74 ; V_56 ++ ) {
T_1 V_48 = V_51 -> V_52 [ V_56 ] . V_48 ;
V_5 -> V_75 [ V_5 -> V_74 ] = V_56 ;
V_5 -> V_76 [ V_56 ] = V_5 -> V_74 ++ ;
V_5 -> V_21 = V_56 ;
V_5 -> V_22 [ V_56 ] = F_31 ( V_2 , V_48 , & V_5 -> V_20 [ V_56 ] ) ;
}
if ( ! V_5 -> V_74 )
return 0 ;
if ( V_5 -> V_74 == 2 &&
V_51 -> V_52 [ 0 ] . type == V_77 &&
V_51 -> V_52 [ 1 ] . type == V_77 ) {
if ( F_27 ( V_2 , V_51 -> V_52 [ 0 ] . V_48 ) ) {
if ( ! F_27 ( V_2 , V_51 -> V_52 [ 1 ] . V_48 ) ) {
V_5 -> V_78 = 1 ;
V_5 -> V_79 = 0 ;
}
} else {
if ( F_27 ( V_2 , V_51 -> V_52 [ 1 ] . V_48 ) ) {
V_5 -> V_78 = 1 ;
V_5 -> V_79 = 1 ;
}
}
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
T_1 V_34 ;
if ( ! V_51 -> V_80 )
return 0 ;
if ( F_26 ( V_2 , V_51 -> V_81 [ 0 ] , & V_34 , 1 ) < 1 )
return 0 ;
V_5 -> V_15 . V_40 = V_34 ;
V_5 -> V_15 . V_82 = 1 ;
if ( V_51 -> V_80 > 1 &&
F_26 ( V_2 , V_51 -> V_81 [ 1 ] , & V_34 , 1 ) > 0 ) {
V_5 -> V_83 [ 0 ] = V_34 ;
V_2 -> V_83 = V_5 -> V_83 ;
}
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
int V_3 ;
if ( V_51 -> V_84 )
V_5 -> V_41 = F_31 ( V_2 , V_51 -> V_84 , & V_3 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , const char * V_30 , int V_85 ,
unsigned int V_86 , int V_87 , struct V_88 * * V_89 )
{
char V_90 [ 44 ] ;
struct V_91 V_92 =
F_42 ( V_90 , V_85 , 0 , 0 , V_93 ) ;
V_92 . V_94 = V_86 ;
snprintf ( V_90 , sizeof( V_90 ) , L_3 , V_30 , V_95 [ V_87 ] ) ;
* V_89 = F_43 ( & V_92 , V_2 ) ;
( * V_89 ) -> V_96 . V_97 = V_98 ;
return F_44 ( V_2 , 0 , * V_89 ) ;
}
static int F_45 ( struct V_1 * V_2 , const char * V_30 ,
int V_85 , unsigned int V_86 , int V_87 ,
struct V_88 * * V_89 )
{
char V_90 [ 44 ] ;
struct V_91 V_92 =
F_46 ( V_90 , V_85 , 0 , 0 , V_93 ) ;
V_92 . V_94 = V_86 ;
snprintf ( V_90 , sizeof( V_90 ) , L_4 , V_30 , V_95 [ V_87 ] ) ;
* V_89 = F_43 ( & V_92 , V_2 ) ;
( * V_89 ) -> V_96 . V_97 = V_98 ;
return F_44 ( V_2 , 0 , * V_89 ) ;
}
static void F_47 ( struct V_1 * V_2 , T_1 V_49 )
{
unsigned int V_99 ;
V_99 = F_48 ( V_2 , V_49 , V_93 ) ;
V_99 &= ~ ( 0x7f << V_100 ) ;
V_99 |= ( ( V_99 >> V_101 ) & 0x7f )
<< V_100 ;
F_49 ( V_2 , V_49 , V_93 , V_99 ) ;
}
static int F_50 ( struct V_1 * V_2 , T_1 V_49 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_102 [ 4 ] ;
int V_103 ;
V_5 -> V_104 =
F_51 ( L_5 , NULL ) ;
V_103 = F_44 ( V_2 , V_49 , V_5 -> V_104 ) ;
if ( V_103 < 0 )
return V_103 ;
F_52 ( V_2 , V_49 , V_93 , V_102 ) ;
V_5 -> V_105 =
F_51 ( L_6 , V_102 ) ;
V_103 = F_44 ( V_2 , V_49 , V_5 -> V_105 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_1 V_49 , int V_3 ,
int V_106 , int type )
{
struct V_4 * V_5 = V_2 -> V_5 ;
const char * V_30 ;
int V_103 , V_85 ;
struct V_88 * V_107 ;
static const char * const V_108 [] = {
L_7 , L_8 , L_9
} ;
static const char * const V_62 [] = {
L_10 , L_11 , L_12
} ;
F_47 ( V_2 , V_49 ) ;
if ( ! V_5 -> V_104 ) {
V_103 = F_50 ( V_2 , V_49 ) ;
if ( V_103 < 0 )
return V_103 ;
}
V_85 = 0 ;
switch ( type ) {
case V_109 :
V_30 = L_13 ;
V_85 = V_3 ;
break;
case V_73 :
if ( V_106 > 1 )
V_30 = V_108 [ V_3 ] ;
else
V_30 = L_14 ;
break;
default:
if ( V_106 > 1 )
V_30 = V_62 [ V_3 ] ;
else
V_30 = L_15 ;
break;
}
V_103 = F_41 ( V_2 , V_30 , V_85 ,
F_54 ( V_49 , 3 , 0 , V_93 ) , 0 , & V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_55 ( V_5 -> V_104 , V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_45 ( V_2 , V_30 , V_85 ,
F_54 ( V_49 , 3 , 0 , V_93 ) , 0 , & V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_55 ( V_5 -> V_105 , V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
int V_56 , V_103 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_62 ; V_56 ++ ) {
V_103 = F_53 ( V_2 , F_25 ( V_2 , V_51 -> V_63 [ V_56 ] ) ,
V_56 , V_51 -> V_62 , V_51 -> V_72 ) ;
if ( V_103 < 0 )
return V_103 ;
}
for ( V_56 = 0 ; V_56 < V_51 -> V_66 ; V_56 ++ ) {
V_103 = F_53 ( V_2 , F_25 ( V_2 , V_51 -> V_67 [ V_56 ] ) ,
V_56 , V_51 -> V_66 , V_109 ) ;
if ( V_103 < 0 )
return V_103 ;
}
for ( V_56 = 0 ; V_56 < V_51 -> V_70 ; V_56 ++ ) {
V_103 = F_53 ( V_2 , F_25 ( V_2 , V_51 -> V_71 [ V_56 ] ) ,
V_56 , V_51 -> V_70 , V_73 ) ;
if ( V_103 < 0 )
return V_103 ;
}
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_110 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_21 == V_3 && ! V_110 )
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
static int F_59 ( struct V_88 * V_111 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
unsigned int V_3 ;
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_116 . V_117 . V_118 = V_5 -> V_74 ;
if ( V_113 -> V_116 . V_117 . V_119 >= V_5 -> V_74 )
V_113 -> V_116 . V_117 . V_119 = V_5 -> V_74 - 1 ;
V_3 = V_5 -> V_75 [ V_113 -> V_116 . V_117 . V_119 ] ;
strcpy ( V_113 -> V_116 . V_117 . V_30 ,
F_61 ( V_2 , V_51 -> V_52 [ V_3 ] . V_48 , 1 ) ) ;
return 0 ;
}
static int F_62 ( struct V_88 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_121 -> V_116 . V_117 . V_119 [ 0 ] = V_5 -> V_76 [ V_5 -> V_21 ] ;
return 0 ;
}
static int F_63 ( struct V_88 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_3 = V_121 -> V_116 . V_117 . V_119 [ 0 ] ;
if ( V_3 >= V_5 -> V_74 )
return - V_122 ;
V_3 = V_5 -> V_75 [ V_3 ] ;
return F_57 ( V_2 , V_3 , 0 ) ;
}
static const struct V_123 * F_64 ( struct V_1 * V_2 ,
struct V_124 * V_125 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_123 * V_126 ;
int V_56 , V_127 ;
V_126 = F_65 ( sizeof( * V_126 ) + sizeof( long ) * ( V_5 -> V_74 + 1 ) ,
V_128 ) ;
if ( ! V_126 )
return NULL ;
V_126 -> V_125 = V_125 ;
V_127 = 0 ;
for ( V_56 = 0 ; V_56 < V_129 ; V_56 ++ ) {
if ( ! V_5 -> V_22 [ V_56 ] )
continue;
V_126 -> V_130 [ V_127 ++ ] =
F_54 ( V_5 -> V_22 [ V_56 ] , 3 ,
V_5 -> V_20 [ V_56 ] , V_131 ) ;
}
return V_126 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
int V_119 )
{
T_1 V_48 = V_51 -> V_52 [ V_119 ] . V_48 ;
T_2 V_99 ;
const char * V_132 ;
struct V_88 * V_107 ;
if ( ! ( F_33 ( V_2 , V_48 ) & V_133 ) )
return 0 ;
V_99 = F_48 ( V_2 , V_48 , V_131 ) ;
V_99 = ( V_99 & V_134 ) >> V_100 ;
if ( V_99 <= 1 )
return 0 ;
V_132 = F_67 ( V_2 , V_51 , V_119 ) ;
return F_45 ( V_2 , V_132 , 0 ,
F_54 ( V_48 , 3 , 0 , V_131 ) , 1 , & V_107 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_56 , V_103 ;
if ( ! V_5 -> V_74 )
return 0 ;
V_5 -> V_135 [ 0 ] = F_64 ( V_2 , & V_136 ) ;
V_5 -> V_135 [ 1 ] = F_64 ( V_2 , & V_137 ) ;
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
struct V_88 * V_107 ;
int V_127 ;
if ( ! V_5 -> V_135 [ V_56 ] )
return - V_138 ;
V_107 = F_43 ( & V_139 [ V_56 ] , V_2 ) ;
if ( ! V_107 )
return - V_138 ;
V_107 -> V_94 = ( long ) V_5 -> V_135 [ V_56 ] ;
V_103 = F_44 ( V_2 , 0 , V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
for ( V_127 = 0 ; V_127 < V_129 ; V_127 ++ ) {
if ( ! V_5 -> V_22 [ V_127 ] )
continue;
V_103 = F_69 ( V_2 , V_107 , 0 , V_5 -> V_22 [ V_127 ] ) ;
if ( V_103 < 0 )
return V_103 ;
}
}
if ( V_5 -> V_74 > 1 && ! V_5 -> V_78 ) {
V_103 = F_44 ( V_2 , 0 ,
F_43 ( & V_140 , V_2 ) ) ;
if ( V_103 < 0 )
return V_103 ;
}
for ( V_56 = 0 ; V_56 < V_5 -> V_74 ; V_56 ++ ) {
V_103 = F_66 ( V_2 , & V_5 -> V_43 , V_56 ) ;
if ( V_103 < 0 )
return V_103 ;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_103 ;
if ( ! V_5 -> V_15 . V_40 )
return 0 ;
V_103 = F_71 ( V_2 , V_5 -> V_15 . V_40 ,
V_5 -> V_15 . V_40 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_72 ( V_2 , & V_5 -> V_15 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_41 )
return F_74 ( V_2 , V_5 -> V_41 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
unsigned int V_141 ;
unsigned int V_142 ;
T_1 V_34 ;
int V_56 ;
V_142 = 0 ;
if ( V_51 -> V_80 ) {
V_34 = V_51 -> V_81 [ 0 ] ;
if ( F_28 ( V_2 , V_34 ) ) {
if ( F_76 ( V_2 , V_34 )
)
V_142 = 1 ;
}
}
V_141 = 0 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_66 ; V_56 ++ ) {
V_34 = V_51 -> V_67 [ V_56 ] ;
if ( ! F_28 ( V_2 , V_34 ) )
continue;
V_141 = F_76 ( V_2 , V_34 ) ;
if ( V_141 )
break;
}
for ( V_56 = 0 ; V_56 < V_51 -> V_70 ; V_56 ++ ) {
V_34 = V_51 -> V_71 [ V_56 ] ;
F_2 ( V_2 , V_34 , 0 ,
V_143 ,
V_141 ? 0 : V_144 ) ;
if ( V_5 -> V_6 == V_145 ) {
F_2 ( V_2 , V_34 , 0 ,
V_143 ,
V_142 ? 0 : V_144 ) ;
}
}
if ( V_5 -> V_146 ) {
unsigned int V_147 = V_141 ?
V_5 -> V_146 : V_5 -> V_148 ;
F_2 ( V_2 , 0x01 , 0 ,
V_149 , V_147 ) ;
}
if ( V_5 -> V_6 == V_145 ) {
for ( V_56 = 0 ; V_56 < V_51 -> V_66 ; V_56 ++ ) {
V_34 = V_51 -> V_67 [ V_56 ] ;
F_2 ( V_2 , V_34 , 0 ,
V_143 ,
( V_142 && V_5 -> V_150 ) ? 0 : V_151 ) ;
}
if ( V_51 -> V_80 ) {
V_34 = V_51 -> V_81 [ 0 ] ;
F_2 ( V_2 , V_34 , 0 ,
V_143 ,
V_142 ? V_144 : 0 ) ;
}
}
}
static void F_77 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
T_1 V_34 ;
unsigned int V_152 ;
V_34 = V_51 -> V_52 [ V_5 -> V_79 ] . V_48 ;
V_152 = F_76 ( V_2 , V_34 ) ;
if ( V_5 -> V_6 == V_145 ) {
if ( V_152 ) {
V_5 -> V_153 = V_5 -> V_21 ;
V_5 -> V_21 = V_5 -> V_79 ;
} else {
V_5 -> V_21 = V_5 -> V_153 ;
}
F_19 ( V_2 ) ;
} else {
if ( V_152 )
F_57 ( V_2 , V_5 -> V_79 , 0 ) ;
else
F_57 ( V_2 , ! V_5 -> V_79 , 0 ) ;
}
}
static void F_78 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_5 -> V_15 . V_64 ; V_56 ++ )
F_2 ( V_2 , V_5 -> V_15 . V_65 [ V_56 ] , 0 ,
V_154 , V_155 ) ;
if ( V_5 -> V_15 . V_68 )
F_2 ( V_2 , V_5 -> V_15 . V_68 , 0 ,
V_154 , V_155 ) ;
for ( V_56 = 0 ; V_56 < F_79 ( V_5 -> V_15 . V_69 ) ; V_56 ++ ) {
if ( ! V_5 -> V_15 . V_69 [ V_56 ] )
break;
F_2 ( V_2 , V_5 -> V_15 . V_69 [ V_56 ] , 0 ,
V_154 , V_155 ) ;
}
for ( V_56 = 0 ; V_56 < V_51 -> V_62 ; V_56 ++ )
F_2 ( V_2 , V_51 -> V_63 [ V_56 ] , 0 ,
V_143 , V_144 ) ;
for ( V_56 = 0 ; V_56 < V_51 -> V_66 ; V_56 ++ ) {
T_1 V_34 = V_51 -> V_67 [ V_56 ] ;
F_2 ( V_2 , V_34 , 0 ,
V_143 , V_151 ) ;
if ( ! V_51 -> V_70 )
continue;
if ( F_33 ( V_2 , V_34 ) & V_156 ) {
F_2 ( V_2 , V_34 , 0 ,
V_157 ,
V_158 | V_159 ) ;
V_5 -> V_160 = 1 ;
}
}
for ( V_56 = 0 ; V_56 < V_51 -> V_70 ; V_56 ++ )
F_2 ( V_2 , V_51 -> V_71 [ V_56 ] , 0 ,
V_143 , V_144 ) ;
if ( V_5 -> V_160 || V_5 -> V_161 )
F_75 ( V_2 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
unsigned int V_9 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_74 ; V_56 ++ ) {
unsigned int V_162 ;
T_1 V_48 = V_51 -> V_52 [ V_56 ] . V_48 ;
if ( ! V_5 -> V_22 [ V_56 ] )
continue;
V_162 = V_163 ;
if ( V_51 -> V_52 [ V_56 ] . type == V_77 ) {
unsigned int V_99 = F_81 ( V_2 , V_48 ) ;
V_99 >>= V_164 ;
if ( V_99 & V_165 )
V_162 = V_166 ;
}
F_2 ( V_2 , V_48 , 0 ,
V_143 , V_162 ) ;
F_2 ( V_2 , V_5 -> V_22 [ V_56 ] , 0 ,
V_154 ,
F_82 ( V_5 -> V_20 [ V_56 ] ) ) ;
if ( V_5 -> V_78 && V_5 -> V_79 == V_56 )
F_2 ( V_2 , V_48 , 0 ,
V_157 ,
V_158 | V_167 ) ;
}
if ( V_5 -> V_6 == V_145 ) {
if ( V_5 -> V_78 )
F_77 ( V_2 ) ;
else {
V_5 -> V_18 = V_5 -> V_22 [ V_5 -> V_21 ] ;
F_19 ( V_2 ) ;
}
} else {
F_57 ( V_2 , V_5 -> V_21 , 1 ) ;
if ( V_5 -> V_78 )
F_77 ( V_2 ) ;
V_9 = 0x000a ;
if ( F_35 ( V_2 , V_168 ) )
V_9 |= 0x0500 ;
if ( F_35 ( V_2 , V_169 ) )
V_9 |= 0x1800 ;
F_4 ( V_2 , V_170 , V_9 ) ;
}
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
V_9 = 0x0002 ;
V_9 |= 0x0008 ;
if ( F_35 ( V_2 , V_171 ) )
V_9 |= 0x4000 ;
F_4 ( V_2 , V_172 , V_9 ) ;
}
static int F_84 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_85 ( V_2 , V_173 ) ;
F_85 ( V_2 , V_174 ) ;
if ( V_5 -> V_175 ) {
F_2 ( V_2 , 0x01 , 0 , V_176 ,
V_5 -> V_175 ) ;
F_2 ( V_2 , 0x01 , 0 , V_177 ,
V_5 -> V_178 ) ;
F_2 ( V_2 , 0x01 , 0 , V_149 ,
V_5 -> V_179 ) ;
}
F_78 ( V_2 ) ;
F_80 ( V_2 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
int V_103 ;
V_103 = F_56 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_68 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_70 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_73 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
return F_84 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_88 ( V_5 -> V_135 [ 0 ] ) ;
F_88 ( V_5 -> V_135 [ 1 ] ) ;
F_88 ( V_2 -> V_5 ) ;
}
static void F_89 ( struct V_1 * V_2 , unsigned int V_180 )
{
switch ( ( V_180 >> 26 ) & 0x7f ) {
case V_159 :
F_75 ( V_2 ) ;
break;
case V_167 :
F_77 ( V_2 ) ;
break;
}
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_103 ;
V_103 = F_91 ( V_2 , & V_5 -> V_43 , NULL ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_37 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_38 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_39 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_40 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 , int V_181 ,
const struct V_182 * * V_183 )
{
const struct V_182 * V_51 = V_183 [ V_181 ] ;
if ( ! V_51 )
return;
for (; V_51 -> V_34 ; V_51 ++ )
F_93 ( V_2 , V_51 -> V_34 , V_51 -> V_53 ) ;
}
static int F_94 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_103 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_128 ) ;
if ( ! V_5 )
return - V_138 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_6 = V_184 ;
V_5 -> V_185 =
F_95 ( V_2 , V_186 ,
V_187 , V_188 ) ;
if ( V_5 -> V_185 < 0 )
V_5 -> V_185 =
F_96 ( V_2 ,
V_186 , NULL , V_189 ) ;
if ( V_5 -> V_185 >= 0 )
F_92 ( V_2 , V_5 -> V_185 , V_190 ) ;
switch ( V_5 -> V_185 ) {
case V_191 :
case V_192 :
case V_193 :
case V_194 :
V_5 -> V_146 = 2 ;
V_5 -> V_148 = 8 ;
V_5 -> V_175 = V_5 -> V_178 =
V_5 -> V_146 | V_5 -> V_148 ;
break;
}
V_103 = F_90 ( V_2 ) ;
if ( V_103 < 0 )
goto error;
V_2 -> V_195 = V_196 ;
return 0 ;
error:
F_88 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return V_103 ;
}
static int F_97 ( struct V_88 * V_111 ,
struct V_112 * V_113 )
{
V_113 -> type = V_197 ;
V_113 -> V_115 = 1 ;
V_113 -> V_116 . integer . V_198 = 0 ;
V_113 -> V_116 . integer . V_199 = 3 ;
return 0 ;
}
static int F_98 ( struct V_88 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
V_121 -> V_116 . integer . V_116 [ 0 ] =
F_1 ( V_2 , V_200 ) & 0x0003 ;
return 0 ;
}
static int F_99 ( struct V_88 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
unsigned int V_201 = V_121 -> V_116 . integer . V_116 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_200 ) ;
unsigned int V_202 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_201 & 0x0003 ) ;
if ( V_202 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_200 , V_9 ) ;
return 1 ;
}
}
static void F_100 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_203 , V_9 ;
V_9 = F_1 ( V_2 , V_204 ) ;
if ( V_5 -> V_175 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_150 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_204 , V_9 ) ;
if ( ( V_5 -> V_175 || V_5 -> V_150 ) &&
F_35 ( V_2 , V_205 ) ) {
V_203 = F_29 ( V_2 , V_205 ) ;
V_203 &= ~ V_206 ;
V_203 |= ( V_60 << V_207 ) ;
F_93 ( V_2 , V_205 , V_203 ) ;
}
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_80 ; V_56 ++ ) {
T_1 V_34 = V_51 -> V_81 [ V_56 ] ;
if ( ! V_51 -> V_70 )
continue;
if ( F_33 ( V_2 , V_34 ) & V_156 ) {
F_2 ( V_2 , V_34 , 0 ,
V_157 ,
V_158 | V_208 ) ;
V_5 -> V_161 = 1 ;
}
}
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_85 ( V_2 , V_209 ) ;
F_85 ( V_2 , V_210 ) ;
F_100 ( V_2 ) ;
if ( V_5 -> V_175 ) {
F_2 ( V_2 , 0x01 , 0 , V_176 ,
V_5 -> V_175 ) ;
F_2 ( V_2 , 0x01 , 0 , V_177 ,
V_5 -> V_178 ) ;
F_2 ( V_2 , 0x01 , 0 , V_149 ,
V_5 -> V_179 ) ;
}
F_78 ( V_2 ) ;
F_80 ( V_2 ) ;
F_101 ( V_2 ) ;
return 0 ;
}
static int F_103 ( struct V_88 * V_111 ,
struct V_112 * V_113 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
return F_104 ( & V_5 -> V_211 , V_113 ) ;
}
static int F_105 ( struct V_88 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
V_121 -> V_116 . V_117 . V_119 [ 0 ] = V_5 -> V_21 ;
return 0 ;
}
static int F_106 ( struct V_88 * V_111 ,
struct V_120 * V_121 )
{
struct V_1 * V_2 = F_60 ( V_111 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
return F_107 ( V_2 , & V_5 -> V_211 , V_121 ,
V_5 -> V_22 [ 0 ] , & V_5 -> V_21 ) ;
}
static int F_108 ( struct V_1 * V_2 , int V_119 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
const struct V_212 * V_213 = & V_5 -> V_211 ;
T_1 V_48 = V_51 -> V_52 [ V_119 ] . V_48 ;
struct V_88 * V_107 ;
T_2 V_99 ;
if ( ! ( F_33 ( V_2 , V_48 ) & V_133 ) )
return 0 ;
V_99 = F_48 ( V_2 , V_48 , V_131 ) ;
V_99 = ( V_99 & V_134 ) >> V_100 ;
if ( V_99 <= 1 )
return 0 ;
return F_45 ( V_2 , V_213 -> V_118 [ V_119 ] . V_132 , 0 ,
F_54 ( V_48 , 3 , 0 , V_131 ) , 1 , & V_107 ) ;
}
static int F_109 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
struct V_212 * V_213 = & V_5 -> V_211 ;
int V_56 , V_103 , V_214 ;
const char * V_132 ;
if ( ! V_5 -> V_74 )
return 0 ;
V_5 -> V_135 [ 0 ] = F_64 ( V_2 , & V_136 ) ;
V_5 -> V_135 [ 1 ] = F_64 ( V_2 , & V_137 ) ;
for ( V_56 = 0 ; V_56 < 2 ; V_56 ++ ) {
struct V_88 * V_107 ;
int V_127 ;
if ( ! V_5 -> V_135 [ V_56 ] )
return - V_138 ;
V_107 = F_43 ( & V_139 [ V_56 ] , V_2 ) ;
if ( ! V_107 )
return - V_138 ;
V_107 -> V_94 = ( long ) V_5 -> V_135 [ V_56 ] ;
V_103 = F_44 ( V_2 , 0 , V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
for ( V_127 = 0 ; V_127 < V_129 ; V_127 ++ ) {
if ( ! V_5 -> V_22 [ V_127 ] )
continue;
V_103 = F_69 ( V_2 , V_107 , 0 , V_5 -> V_22 [ V_127 ] ) ;
if ( V_103 < 0 )
return V_103 ;
}
}
for ( V_56 = 0 ; V_56 < V_5 -> V_74 ; V_56 ++ ) {
V_132 = F_67 ( V_2 , V_51 , V_56 ) ;
F_110 ( V_213 , V_132 , V_5 -> V_20 [ V_56 ] , & V_214 ) ;
V_103 = F_108 ( V_2 , V_56 ) ;
if ( V_103 < 0 )
return V_103 ;
}
if ( ( V_5 -> V_74 == 2 && ! V_5 -> V_78 ) ||
( V_5 -> V_74 == 3 ) ) {
V_103 = F_44 ( V_2 , V_5 -> V_22 [ 0 ] ,
F_43 ( & V_215 , V_2 ) ) ;
if ( V_103 < 0 )
return V_103 ;
}
return 0 ;
}
static int F_111 ( struct V_1 * V_2 )
{
T_1 V_49 = V_216 ;
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
struct V_88 * V_107 ;
int V_103 ;
char * V_30 = L_16 ;
F_47 ( V_2 , V_49 ) ;
if ( ! V_5 -> V_104 ) {
V_103 = F_50 ( V_2 , V_49 ) ;
if ( V_103 < 0 )
return V_103 ;
}
V_103 = F_41 ( V_2 , V_30 , 0 ,
F_54 ( V_49 , 3 , 0 , V_93 ) , 0 , & V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_55 ( V_5 -> V_104 , V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_45 ( V_2 , V_30 , 0 ,
F_54 ( V_49 , 3 , 0 , V_93 ) , 0 , & V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_55 ( V_5 -> V_105 , V_107 ) ;
if ( V_103 < 0 )
return V_103 ;
if ( V_51 -> V_70 ) {
V_103 = F_44 ( V_2 , 0 ,
F_43 ( & V_217 , V_2 ) ) ;
if ( V_103 < 0 )
return V_103 ;
}
return V_103 ;
}
static int F_112 ( struct V_1 * V_2 )
{
int V_103 ;
V_103 = F_111 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_109 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_70 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
return F_102 ( V_2 ) ;
}
static void F_113 ( struct V_1 * V_2 , unsigned int V_180 )
{
switch ( ( V_180 >> 26 ) & 0x3f ) {
case V_159 :
case V_208 :
F_75 ( V_2 ) ;
break;
case V_167 :
F_77 ( V_2 ) ;
break;
}
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_50 * V_51 = & V_5 -> V_43 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_51 -> V_74 ; V_56 ++ ) {
T_1 V_48 = V_51 -> V_52 [ V_56 ] . V_48 ;
V_5 -> V_22 [ V_56 ] = F_31 ( V_2 , V_48 , & V_5 -> V_20 [ V_56 ] ) ;
V_5 -> V_21 = V_5 -> V_153 = V_56 ;
V_5 -> V_74 ++ ;
if ( F_27 ( V_2 , V_56 ) && V_51 -> V_74 >= 2 ) {
V_5 -> V_78 = 1 ;
V_5 -> V_79 = V_56 ;
}
}
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_103 ;
V_103 = F_91 ( V_2 , & V_5 -> V_43 , NULL ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_37 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_114 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
V_103 = F_39 ( V_2 ) ;
if ( V_103 < 0 )
return V_103 ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 , T_3 V_218 )
{
unsigned int V_9 ;
F_117 ( V_2 ) ;
F_2 ( V_2 , V_216 , 0 ,
V_219 , V_220 ) ;
F_2 ( V_2 , V_221 , 0 ,
V_219 , V_220 ) ;
V_9 = F_1 ( V_2 , V_204 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_204 , V_9 ) ;
return 0 ;
}
static int F_118 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_103 ;
V_5 = F_65 ( sizeof( * V_5 ) , V_128 ) ;
if ( ! V_5 )
return - V_138 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_6 = V_145 ;
V_5 -> V_185 =
F_95 ( V_2 , V_222 ,
V_223 , V_224 ) ;
if ( V_5 -> V_185 >= 0 )
F_92 ( V_2 , V_5 -> V_185 , V_225 ) ;
switch ( V_5 -> V_185 ) {
case V_226 :
F_119 ( L_17 ,
V_223 [ V_5 -> V_185 ] ) ;
V_5 -> V_150 = 1 ;
break;
}
F_100 ( V_2 ) ;
V_103 = F_115 ( V_2 ) ;
if ( V_103 < 0 )
goto error;
V_2 -> V_195 = V_227 ;
return 0 ;
error:
F_88 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
return V_103 ;
}
static int T_4 F_120 ( void )
{
return F_121 ( & V_228 ) ;
}
static void T_5 F_122 ( void )
{
F_123 ( & V_228 ) ;
}
