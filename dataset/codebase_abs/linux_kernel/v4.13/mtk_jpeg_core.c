static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 (
struct V_5 * V_6 )
{
return F_2 ( F_4 ( V_6 ) , struct V_4 , V_7 ) ;
}
static int F_5 ( struct V_8 * V_8 , void * V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_6 ( V_8 ) ;
F_7 ( V_11 -> V_14 , V_15 L_1 , sizeof( V_11 -> V_14 ) ) ;
F_7 ( V_11 -> V_16 , V_15 L_1 , sizeof( V_11 -> V_16 ) ) ;
snprintf ( V_11 -> V_17 , sizeof( V_11 -> V_17 ) , L_2 ,
F_8 ( V_13 -> V_18 ) ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 , int V_21 ,
struct V_22 * V_23 , T_1 type )
{
int V_24 , V_25 = 0 ;
for ( V_24 = 0 ; V_24 < V_21 ; ++ V_24 ) {
if ( V_20 [ V_24 ] . V_26 & type ) {
if ( V_25 == V_23 -> V_27 )
break;
++ V_25 ;
}
}
if ( V_24 >= V_21 )
return - V_28 ;
V_23 -> V_29 = V_20 [ V_24 ] . V_30 ;
return 0 ;
}
static int F_10 ( struct V_8 * V_8 , void * V_9 ,
struct V_22 * V_23 )
{
return F_9 ( V_20 , V_31 , V_23 ,
V_32 ) ;
}
static int F_11 ( struct V_8 * V_8 , void * V_9 ,
struct V_22 * V_23 )
{
return F_9 ( V_20 , V_31 , V_23 ,
V_33 ) ;
}
static struct V_34 * F_12 ( struct V_1 * V_35 ,
enum V_36 type )
{
if ( F_13 ( type ) )
return & V_35 -> V_37 ;
return & V_35 -> V_38 ;
}
static struct V_19 * F_14 ( struct V_1 * V_35 ,
T_1 V_29 ,
unsigned int V_39 )
{
unsigned int V_40 , V_41 ;
V_41 = ( V_39 == V_42 ) ?
V_33 :
V_32 ;
for ( V_40 = 0 ; V_40 < V_31 ; V_40 ++ ) {
struct V_19 * V_43 = & V_20 [ V_40 ] ;
if ( V_43 -> V_30 == V_29 && V_43 -> V_26 & V_41 )
return V_43 ;
}
return NULL ;
}
static void F_15 ( T_1 * V_44 , unsigned int V_45 ,
unsigned int V_46 , unsigned int V_47 ,
T_1 * V_48 , unsigned int V_49 ,
unsigned int V_50 , unsigned int V_51 )
{
int V_52 , V_53 , V_54 , V_55 ;
V_52 = * V_44 ;
V_53 = * V_48 ;
V_54 = 1 << V_47 ;
V_55 = 1 << V_51 ;
F_16 ( V_44 , V_45 , V_46 , V_47 , V_48 , V_49 , V_50 , V_51 , 0 ) ;
if ( * V_44 < V_52 && ( * V_44 + V_54 ) <= V_46 )
* V_44 += V_54 ;
if ( * V_48 < V_53 && ( * V_48 + V_55 ) <= V_50 )
* V_48 += V_55 ;
}
static void F_17 ( struct V_1 * V_35 ,
struct V_56 * V_23 )
{
struct V_57 * V_58 = & V_23 -> V_43 . V_58 ;
struct V_34 * V_59 ;
int V_24 ;
V_59 = F_12 ( V_35 , V_23 -> type ) ;
V_58 -> V_52 = V_59 -> V_44 ;
V_58 -> V_53 = V_59 -> V_48 ;
V_58 -> V_29 = V_59 -> V_43 -> V_30 ;
V_58 -> V_60 = V_59 -> V_43 -> V_61 ;
for ( V_24 = 0 ; V_24 < V_58 -> V_60 ; V_24 ++ ) {
V_58 -> V_62 [ V_24 ] . V_63 = V_59 -> V_63 [ V_24 ] ;
V_58 -> V_62 [ V_24 ] . V_64 = V_59 -> V_64 [ V_24 ] ;
}
}
static int F_18 ( struct V_56 * V_23 ,
struct V_19 * V_43 ,
struct V_1 * V_35 , int V_65 )
{
struct V_57 * V_58 = & V_23 -> V_43 . V_58 ;
struct V_12 * V_13 = V_35 -> V_13 ;
int V_24 ;
memset ( V_58 -> V_66 , 0 , sizeof( V_58 -> V_66 ) ) ;
V_58 -> V_67 = V_68 ;
if ( V_35 -> V_69 != V_70 ) {
F_17 ( V_35 , V_23 ) ;
goto V_71;
}
V_58 -> V_60 = V_43 -> V_61 ;
V_58 -> V_29 = V_43 -> V_30 ;
if ( V_65 == V_42 ) {
struct V_72 * V_73 = & V_58 -> V_62 [ 0 ] ;
F_15 ( & V_58 -> V_52 , V_74 ,
V_75 , 0 ,
& V_58 -> V_53 , V_76 ,
V_77 , 0 ) ;
memset ( V_73 -> V_66 , 0 , sizeof( V_73 -> V_66 ) ) ;
V_73 -> V_63 = 0 ;
V_73 -> V_64 = F_19 ( V_73 -> V_64 , 128 ) ;
if ( V_73 -> V_64 == 0 )
V_73 -> V_64 = V_78 ;
goto V_71;
}
F_15 ( & V_58 -> V_52 , V_74 ,
V_75 , V_43 -> V_79 ,
& V_58 -> V_53 , V_76 ,
V_77 , V_43 -> V_80 ) ;
for ( V_24 = 0 ; V_24 < V_43 -> V_61 ; V_24 ++ ) {
struct V_72 * V_73 = & V_58 -> V_62 [ V_24 ] ;
T_1 V_81 = V_58 -> V_52 * V_43 -> V_82 [ V_24 ] / 4 ;
T_1 V_48 = V_58 -> V_53 * V_43 -> V_83 [ V_24 ] / 4 ;
memset ( V_73 -> V_66 , 0 , sizeof( V_73 -> V_66 ) ) ;
V_73 -> V_63 = V_81 ;
V_73 -> V_64 = V_81 * V_48 ;
}
V_71:
F_20 ( 2 , V_84 , & V_13 -> V_85 , L_3 ,
V_58 -> V_52 , V_58 -> V_53 ) ;
for ( V_24 = 0 ; V_24 < V_58 -> V_60 ; V_24 ++ ) {
F_20 ( 2 , V_84 , & V_13 -> V_85 ,
L_4 ,
V_24 ,
V_58 -> V_62 [ V_24 ] . V_63 ,
V_58 -> V_62 [ V_24 ] . V_64 ) ;
}
return 0 ;
}
static int F_21 ( struct V_8 * V_8 , void * V_9 ,
struct V_56 * V_23 )
{
struct V_86 * V_87 ;
struct V_34 * V_59 = NULL ;
struct V_57 * V_58 = & V_23 -> V_43 . V_58 ;
struct V_1 * V_35 = F_1 ( V_9 ) ;
struct V_12 * V_13 = V_35 -> V_13 ;
int V_24 ;
V_87 = F_22 ( V_35 -> V_3 . V_88 , V_23 -> type ) ;
if ( ! V_87 )
return - V_28 ;
V_59 = F_12 ( V_35 , V_23 -> type ) ;
memset ( V_58 -> V_66 , 0 , sizeof( V_58 -> V_66 ) ) ;
V_58 -> V_52 = V_59 -> V_44 ;
V_58 -> V_53 = V_59 -> V_48 ;
V_58 -> V_67 = V_68 ;
V_58 -> V_29 = V_59 -> V_43 -> V_30 ;
V_58 -> V_60 = V_59 -> V_43 -> V_61 ;
V_58 -> V_89 = V_35 -> V_89 ;
V_58 -> V_90 = V_35 -> V_90 ;
V_58 -> V_91 = V_35 -> V_91 ;
V_58 -> V_92 = V_35 -> V_92 ;
F_20 ( 1 , V_84 , & V_13 -> V_85 , L_5 ,
V_23 -> type ,
( V_58 -> V_29 & 0xff ) ,
( V_58 -> V_29 >> 8 & 0xff ) ,
( V_58 -> V_29 >> 16 & 0xff ) ,
( V_58 -> V_29 >> 24 & 0xff ) ,
V_58 -> V_52 , V_58 -> V_53 ) ;
for ( V_24 = 0 ; V_24 < V_58 -> V_60 ; V_24 ++ ) {
struct V_72 * V_73 = & V_58 -> V_62 [ V_24 ] ;
V_73 -> V_63 = V_59 -> V_63 [ V_24 ] ;
V_73 -> V_64 = V_59 -> V_64 [ V_24 ] ;
memset ( V_73 -> V_66 , 0 , sizeof( V_73 -> V_66 ) ) ;
F_20 ( 1 , V_84 , & V_13 -> V_85 ,
L_4 ,
V_24 ,
V_73 -> V_63 ,
V_73 -> V_64 ) ;
}
return 0 ;
}
static int F_23 ( struct V_8 * V_8 , void * V_9 ,
struct V_56 * V_23 )
{
struct V_1 * V_35 = F_1 ( V_9 ) ;
struct V_19 * V_43 ;
V_43 = F_14 ( V_35 , V_23 -> V_43 . V_58 . V_29 ,
V_93 ) ;
if ( ! V_43 )
V_43 = V_35 -> V_38 . V_43 ;
F_20 ( 2 , V_84 , & V_35 -> V_13 -> V_85 , L_6 ,
V_23 -> type ,
( V_43 -> V_30 & 0xff ) ,
( V_43 -> V_30 >> 8 & 0xff ) ,
( V_43 -> V_30 >> 16 & 0xff ) ,
( V_43 -> V_30 >> 24 & 0xff ) ) ;
return F_18 ( V_23 , V_43 , V_35 , V_93 ) ;
}
static int F_24 ( struct V_8 * V_8 , void * V_9 ,
struct V_56 * V_23 )
{
struct V_1 * V_35 = F_1 ( V_9 ) ;
struct V_19 * V_43 ;
V_43 = F_14 ( V_35 , V_23 -> V_43 . V_58 . V_29 ,
V_42 ) ;
if ( ! V_43 )
V_43 = V_35 -> V_37 . V_43 ;
F_20 ( 2 , V_84 , & V_35 -> V_13 -> V_85 , L_6 ,
V_23 -> type ,
( V_43 -> V_30 & 0xff ) ,
( V_43 -> V_30 >> 8 & 0xff ) ,
( V_43 -> V_30 >> 16 & 0xff ) ,
( V_43 -> V_30 >> 24 & 0xff ) ) ;
return F_18 ( V_23 , V_43 , V_35 , V_42 ) ;
}
static int F_25 ( struct V_1 * V_35 ,
struct V_56 * V_23 )
{
struct V_86 * V_87 ;
struct V_34 * V_59 = NULL ;
struct V_57 * V_58 = & V_23 -> V_43 . V_58 ;
struct V_12 * V_13 = V_35 -> V_13 ;
unsigned int V_94 ;
int V_24 ;
V_87 = F_22 ( V_35 -> V_3 . V_88 , V_23 -> type ) ;
if ( ! V_87 )
return - V_28 ;
V_59 = F_12 ( V_35 , V_23 -> type ) ;
if ( F_26 ( V_87 ) ) {
F_27 ( & V_13 -> V_85 , L_7 ) ;
return - V_95 ;
}
V_94 = F_13 ( V_23 -> type ) ?
V_42 : V_93 ;
V_59 -> V_43 = F_14 ( V_35 , V_58 -> V_29 , V_94 ) ;
V_59 -> V_44 = V_58 -> V_52 ;
V_59 -> V_48 = V_58 -> V_53 ;
V_35 -> V_89 = V_58 -> V_89 ;
V_35 -> V_90 = V_58 -> V_90 ;
V_35 -> V_91 = V_58 -> V_91 ;
V_35 -> V_92 = V_58 -> V_92 ;
F_20 ( 1 , V_84 , & V_13 -> V_85 , L_8 ,
V_23 -> type ,
( V_59 -> V_43 -> V_30 & 0xff ) ,
( V_59 -> V_43 -> V_30 >> 8 & 0xff ) ,
( V_59 -> V_43 -> V_30 >> 16 & 0xff ) ,
( V_59 -> V_43 -> V_30 >> 24 & 0xff ) ,
V_59 -> V_44 , V_59 -> V_48 ) ;
for ( V_24 = 0 ; V_24 < V_59 -> V_43 -> V_61 ; V_24 ++ ) {
V_59 -> V_63 [ V_24 ] = V_58 -> V_62 [ V_24 ] . V_63 ;
V_59 -> V_64 [ V_24 ] = V_58 -> V_62 [ V_24 ] . V_64 ;
F_20 ( 1 , V_84 , & V_13 -> V_85 ,
L_4 ,
V_24 , V_59 -> V_63 [ V_24 ] , V_59 -> V_64 [ V_24 ] ) ;
}
return 0 ;
}
static int F_28 ( struct V_8 * V_8 , void * V_9 ,
struct V_56 * V_23 )
{
int V_96 ;
V_96 = F_24 ( V_8 , V_9 , V_23 ) ;
if ( V_96 )
return V_96 ;
return F_25 ( F_1 ( V_9 ) , V_23 ) ;
}
static int F_29 ( struct V_8 * V_8 , void * V_9 ,
struct V_56 * V_23 )
{
int V_96 ;
V_96 = F_23 ( V_8 , V_9 , V_23 ) ;
if ( V_96 )
return V_96 ;
return F_25 ( F_1 ( V_9 ) , V_23 ) ;
}
static void F_30 ( struct V_1 * V_35 )
{
static const struct V_97 V_98 = {
. type = V_99 ,
. V_100 . V_101 . V_102 =
V_103 ,
} ;
F_31 ( & V_35 -> V_3 , & V_98 ) ;
}
static int F_32 ( struct V_2 * V_3 ,
const struct V_104 * V_105 )
{
switch ( V_105 -> type ) {
case V_99 :
return F_33 ( V_3 , V_105 ) ;
default:
return - V_28 ;
}
}
static int F_34 ( struct V_8 * V_8 , void * V_9 ,
struct V_106 * V_107 )
{
struct V_1 * V_35 = F_1 ( V_9 ) ;
if ( V_107 -> type != V_108 )
return - V_28 ;
switch ( V_107 -> V_109 ) {
case V_110 :
case V_111 :
V_107 -> V_112 . V_52 = V_35 -> V_37 . V_44 ;
V_107 -> V_112 . V_53 = V_35 -> V_37 . V_48 ;
V_107 -> V_112 . V_113 = 0 ;
V_107 -> V_112 . V_114 = 0 ;
break;
case V_115 :
case V_116 :
V_107 -> V_112 . V_52 = V_35 -> V_38 . V_44 ;
V_107 -> V_112 . V_53 = V_35 -> V_38 . V_48 ;
V_107 -> V_112 . V_113 = 0 ;
V_107 -> V_112 . V_114 = 0 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_35 ( struct V_8 * V_8 , void * V_9 ,
struct V_106 * V_107 )
{
struct V_1 * V_35 = F_1 ( V_9 ) ;
if ( V_107 -> type != V_108 )
return - V_28 ;
switch ( V_107 -> V_109 ) {
case V_110 :
V_107 -> V_112 . V_113 = 0 ;
V_107 -> V_112 . V_114 = 0 ;
V_107 -> V_112 . V_52 = V_35 -> V_37 . V_44 ;
V_107 -> V_112 . V_53 = V_35 -> V_37 . V_48 ;
break;
default:
return - V_28 ;
}
return 0 ;
}
static int F_36 ( struct V_8 * V_8 , void * V_9 , struct V_117 * V_118 )
{
struct V_2 * V_3 = V_8 -> V_119 ;
struct V_1 * V_35 = F_1 ( V_9 ) ;
struct V_86 * V_87 ;
struct V_5 * V_6 ;
struct V_4 * V_120 ;
if ( V_118 -> type != V_121 )
goto V_71;
V_87 = F_22 ( V_3 -> V_88 , V_118 -> type ) ;
if ( V_118 -> V_27 >= V_87 -> V_122 ) {
F_37 ( V_35 -> V_13 -> V_18 , L_9 ) ;
return - V_28 ;
}
V_6 = V_87 -> V_123 [ V_118 -> V_27 ] ;
V_120 = F_3 ( V_6 ) ;
V_120 -> V_26 = ( V_118 -> V_124 . V_125 [ 0 ] . V_126 == 0 ) ?
V_127 : V_128 ;
V_71:
return F_38 ( V_8 , V_3 -> V_88 , V_118 ) ;
}
static int F_39 ( struct V_86 * V_129 ,
unsigned int * V_122 ,
unsigned int * V_60 ,
unsigned int V_130 [] ,
struct V_131 * V_132 [] )
{
struct V_1 * V_35 = F_40 ( V_129 ) ;
struct V_34 * V_59 = NULL ;
struct V_12 * V_13 = V_35 -> V_13 ;
int V_24 ;
F_20 ( 1 , V_84 , & V_13 -> V_85 , L_10 ,
V_129 -> type , * V_122 ) ;
V_59 = F_12 ( V_35 , V_129 -> type ) ;
if ( ! V_59 )
return - V_28 ;
* V_60 = V_59 -> V_43 -> V_61 ;
for ( V_24 = 0 ; V_24 < V_59 -> V_43 -> V_61 ; V_24 ++ ) {
V_130 [ V_24 ] = V_59 -> V_64 [ V_24 ] ;
F_20 ( 1 , V_84 , & V_13 -> V_85 , L_11 ,
V_24 , V_130 [ V_24 ] ) ;
}
return 0 ;
}
static int F_41 ( struct V_5 * V_6 )
{
struct V_1 * V_35 = F_40 ( V_6 -> V_86 ) ;
struct V_34 * V_59 = NULL ;
int V_24 ;
V_59 = F_12 ( V_35 , V_6 -> V_86 -> type ) ;
if ( ! V_59 )
return - V_28 ;
for ( V_24 = 0 ; V_24 < V_59 -> V_43 -> V_61 ; V_24 ++ )
F_42 ( V_6 , V_24 , V_59 -> V_64 [ V_24 ] ) ;
return 0 ;
}
static bool F_43 ( struct V_1 * V_35 ,
struct V_133 * V_134 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
struct V_34 * V_59 ;
V_59 = & V_35 -> V_37 ;
if ( V_59 -> V_44 != V_134 -> V_135 || V_59 -> V_48 != V_134 -> V_136 ) {
F_20 ( 1 , V_84 , & V_13 -> V_85 , L_12 ) ;
return true ;
}
V_59 = & V_35 -> V_38 ;
if ( V_59 -> V_43 != F_14 ( V_35 , V_134 -> V_137 ,
V_93 ) ) {
F_20 ( 1 , V_84 , & V_13 -> V_85 , L_13 ) ;
return true ;
}
return false ;
}
static void F_44 ( struct V_1 * V_35 ,
struct V_133 * V_134 )
{
struct V_12 * V_13 = V_35 -> V_13 ;
struct V_34 * V_59 ;
int V_24 ;
V_59 = & V_35 -> V_37 ;
V_59 -> V_44 = V_134 -> V_135 ;
V_59 -> V_48 = V_134 -> V_136 ;
V_59 = & V_35 -> V_38 ;
V_59 -> V_44 = V_134 -> V_138 ;
V_59 -> V_48 = V_134 -> V_139 ;
V_59 -> V_43 = F_14 ( V_35 ,
V_134 -> V_137 ,
V_93 ) ;
for ( V_24 = 0 ; V_24 < V_59 -> V_43 -> V_61 ; V_24 ++ ) {
V_59 -> V_63 [ V_24 ] = V_134 -> V_140 [ V_24 ] ;
V_59 -> V_64 [ V_24 ] = V_134 -> V_141 [ V_24 ] ;
}
F_20 ( 1 , V_84 , & V_13 -> V_85 ,
L_14 ,
( V_134 -> V_137 & 0xff ) ,
( V_134 -> V_137 >> 8 & 0xff ) ,
( V_134 -> V_137 >> 16 & 0xff ) ,
( V_134 -> V_137 >> 24 & 0xff ) ,
V_134 -> V_135 , V_134 -> V_136 ,
V_134 -> V_138 , V_134 -> V_139 ) ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_1 * V_35 = F_40 ( V_6 -> V_86 ) ;
struct V_133 * V_134 ;
struct V_12 * V_13 = V_35 -> V_13 ;
struct V_4 * V_120 ;
bool V_142 ;
F_20 ( 2 , V_84 , & V_13 -> V_85 , L_15 ,
V_6 -> V_86 -> type , V_6 -> V_27 , V_6 ) ;
if ( V_6 -> V_86 -> type != V_121 )
goto V_71;
V_120 = F_3 ( V_6 ) ;
V_134 = & V_120 -> V_143 ;
memset ( V_134 , 0 , sizeof( * V_134 ) ) ;
if ( V_120 -> V_26 & V_127 ) {
F_20 ( 1 , V_84 , & V_13 -> V_85 , L_16 ) ;
goto V_71;
}
V_142 = F_46 ( V_134 , ( V_144 * ) F_47 ( V_6 , 0 ) ,
F_48 ( V_6 , 0 ) ) ;
if ( ! V_142 ) {
F_27 ( & V_13 -> V_85 , L_17 ) ;
F_49 ( V_6 , V_145 ) ;
return;
}
if ( V_35 -> V_69 == V_70 ) {
struct V_86 * V_146 = F_22 (
V_35 -> V_3 . V_88 , V_147 ) ;
F_30 ( V_35 ) ;
F_44 ( V_35 , V_134 ) ;
V_35 -> V_69 = F_50 ( V_146 ) ?
V_148 : V_149 ;
}
V_71:
F_51 ( V_35 -> V_3 . V_88 , F_4 ( V_6 ) ) ;
}
static void * F_52 ( struct V_1 * V_35 ,
enum V_36 type )
{
if ( F_13 ( type ) )
return F_53 ( V_35 -> V_3 . V_88 ) ;
else
return F_54 ( V_35 -> V_3 . V_88 ) ;
}
static int F_55 ( struct V_86 * V_129 , unsigned int V_150 )
{
struct V_1 * V_35 = F_40 ( V_129 ) ;
struct V_5 * V_6 ;
int V_96 = 0 ;
V_96 = F_56 ( V_35 -> V_13 -> V_18 ) ;
if ( V_96 < 0 )
goto V_151;
return 0 ;
V_151:
while ( ( V_6 = F_52 ( V_35 , V_129 -> type ) ) )
F_57 ( F_4 ( V_6 ) , V_152 ) ;
return V_96 ;
}
static void F_58 ( struct V_86 * V_129 )
{
struct V_1 * V_35 = F_40 ( V_129 ) ;
struct V_5 * V_6 ;
if ( V_35 -> V_69 == V_148 &&
! F_13 ( V_129 -> type ) ) {
struct V_4 * V_153 ;
V_6 = F_59 ( V_35 -> V_3 . V_88 ) ;
V_153 = F_3 ( V_6 ) ;
F_44 ( V_35 , & V_153 -> V_143 ) ;
V_35 -> V_69 = V_149 ;
} else if ( F_13 ( V_129 -> type ) ) {
V_35 -> V_69 = V_70 ;
}
while ( ( V_6 = F_52 ( V_35 , V_129 -> type ) ) )
F_57 ( F_4 ( V_6 ) , V_145 ) ;
F_60 ( V_35 -> V_13 -> V_18 ) ;
}
static void F_61 ( struct V_1 * V_35 ,
struct V_5 * V_153 ,
struct V_154 * V_155 )
{
V_155 -> V_156 = F_62 ( V_153 , 0 ) ;
V_155 -> V_157 = V_155 -> V_156 +
F_19 ( F_48 ( V_153 , 0 ) , 16 ) ;
V_155 -> V_158 = F_19 ( F_63 ( V_153 , 0 ) , 128 ) ;
}
static int F_64 ( struct V_1 * V_35 ,
struct V_133 * V_134 ,
struct V_5 * V_159 ,
struct V_160 * V_161 )
{
int V_24 ;
if ( V_134 -> V_162 != V_159 -> V_60 ) {
F_37 ( V_35 -> V_13 -> V_18 , L_18 ,
V_134 -> V_162 , V_159 -> V_60 ) ;
return - V_28 ;
}
for ( V_24 = 0 ; V_24 < V_159 -> V_60 ; V_24 ++ ) {
if ( F_63 ( V_159 , V_24 ) < V_134 -> V_141 [ V_24 ] ) {
F_37 ( V_35 -> V_13 -> V_18 ,
L_19 ,
F_63 ( V_159 , 0 ) ,
V_134 -> V_141 [ V_24 ] ) ;
return - V_28 ;
}
V_161 -> V_163 [ V_24 ] = F_62 ( V_159 , V_24 ) ;
}
return 0 ;
}
static void F_65 ( void * V_9 )
{
struct V_1 * V_35 = V_9 ;
struct V_12 * V_13 = V_35 -> V_13 ;
struct V_5 * V_153 , * V_159 ;
enum V_164 V_165 = V_145 ;
unsigned long V_26 ;
struct V_4 * V_120 ;
struct V_154 V_155 ;
struct V_160 V_161 ;
int V_24 ;
V_153 = F_59 ( V_35 -> V_3 . V_88 ) ;
V_159 = F_66 ( V_35 -> V_3 . V_88 ) ;
V_120 = F_3 ( V_153 ) ;
if ( V_120 -> V_26 & V_127 ) {
for ( V_24 = 0 ; V_24 < V_159 -> V_60 ; V_24 ++ )
F_42 ( V_159 , V_24 , 0 ) ;
V_165 = V_166 ;
goto V_167;
}
if ( F_43 ( V_35 , & V_120 -> V_143 ) ) {
F_30 ( V_35 ) ;
V_35 -> V_69 = V_148 ;
F_67 ( V_13 -> V_168 , V_35 -> V_3 . V_88 ) ;
return;
}
F_61 ( V_35 , V_153 , & V_155 ) ;
if ( F_64 ( V_35 , & V_120 -> V_143 , V_159 , & V_161 ) )
goto V_167;
F_68 ( & V_13 -> V_169 , V_26 ) ;
F_69 ( V_13 -> V_170 ) ;
F_70 ( V_13 -> V_170 ,
& V_120 -> V_143 , & V_155 , & V_161 ) ;
F_71 ( V_13 -> V_170 ) ;
F_72 ( & V_13 -> V_169 , V_26 ) ;
return;
V_167:
F_53 ( V_35 -> V_3 . V_88 ) ;
F_54 ( V_35 -> V_3 . V_88 ) ;
F_57 ( F_4 ( V_153 ) , V_165 ) ;
F_57 ( F_4 ( V_159 ) , V_165 ) ;
F_67 ( V_13 -> V_168 , V_35 -> V_3 . V_88 ) ;
}
static int F_73 ( void * V_9 )
{
struct V_1 * V_35 = V_9 ;
return ( V_35 -> V_69 == V_149 ) ? 1 : 0 ;
}
static void F_74 ( void * V_9 )
{
}
static int F_75 ( void * V_9 , struct V_86 * V_171 ,
struct V_86 * V_146 )
{
struct V_1 * V_35 = V_9 ;
int V_96 ;
V_171 -> type = V_121 ;
V_171 -> V_172 = V_173 | V_174 ;
V_171 -> V_175 = V_35 ;
V_171 -> V_176 = sizeof( struct V_4 ) ;
V_171 -> V_177 = & V_178 ;
V_171 -> V_179 = & V_180 ;
V_171 -> V_181 = V_182 ;
V_171 -> V_183 = & V_35 -> V_13 -> V_183 ;
V_171 -> V_18 = V_35 -> V_13 -> V_18 ;
V_96 = F_76 ( V_171 ) ;
if ( V_96 )
return V_96 ;
V_146 -> type = V_147 ;
V_146 -> V_172 = V_173 | V_174 ;
V_146 -> V_175 = V_35 ;
V_146 -> V_176 = sizeof( struct V_184 ) ;
V_146 -> V_177 = & V_178 ;
V_146 -> V_179 = & V_180 ;
V_146 -> V_181 = V_182 ;
V_146 -> V_183 = & V_35 -> V_13 -> V_183 ;
V_146 -> V_18 = V_35 -> V_13 -> V_18 ;
V_96 = F_76 ( V_146 ) ;
return V_96 ;
}
static void F_77 ( struct V_12 * V_13 )
{
int V_96 ;
V_96 = F_78 ( V_13 -> V_185 ) ;
if ( V_96 )
F_37 ( V_13 -> V_18 , L_20 , V_96 ) ;
F_79 ( V_13 -> V_186 ) ;
F_79 ( V_13 -> V_187 ) ;
}
static void F_80 ( struct V_12 * V_13 )
{
F_81 ( V_13 -> V_187 ) ;
F_81 ( V_13 -> V_186 ) ;
F_82 ( V_13 -> V_185 ) ;
}
static T_2 F_83 ( int V_188 , void * V_9 )
{
struct V_12 * V_13 = V_9 ;
struct V_1 * V_35 ;
struct V_5 * V_153 , * V_159 ;
struct V_4 * V_120 ;
enum V_164 V_165 = V_145 ;
T_1 V_189 ;
T_1 V_190 ;
int V_24 ;
V_190 = F_84 ( V_13 -> V_170 ) ;
V_189 = F_85 ( V_190 ) ;
V_35 = F_86 ( V_13 -> V_168 ) ;
if ( ! V_35 ) {
F_27 ( & V_13 -> V_85 , L_21 ) ;
return V_191 ;
}
V_153 = F_53 ( V_35 -> V_3 . V_88 ) ;
V_159 = F_54 ( V_35 -> V_3 . V_88 ) ;
V_120 = F_3 ( V_153 ) ;
if ( V_189 >= V_192 )
F_69 ( V_13 -> V_170 ) ;
if ( V_189 != V_193 ) {
F_37 ( V_13 -> V_18 , L_22 ) ;
goto V_167;
}
for ( V_24 = 0 ; V_24 < V_159 -> V_60 ; V_24 ++ )
F_42 ( V_159 , V_24 ,
V_120 -> V_143 . V_141 [ V_24 ] ) ;
V_165 = V_166 ;
V_167:
F_57 ( F_4 ( V_153 ) , V_165 ) ;
F_57 ( F_4 ( V_159 ) , V_165 ) ;
F_67 ( V_13 -> V_168 , V_35 -> V_3 . V_88 ) ;
return V_191 ;
}
static void F_87 ( struct V_1 * V_35 )
{
struct V_34 * V_129 = & V_35 -> V_37 ;
int V_24 ;
V_35 -> V_89 = V_194 ,
V_35 -> V_90 = V_195 ;
V_35 -> V_92 = V_196 ;
V_35 -> V_91 = V_197 ;
V_129 -> V_43 = F_14 ( V_35 , V_198 ,
V_42 ) ;
V_129 -> V_44 = V_74 ;
V_129 -> V_48 = V_76 ;
V_129 -> V_63 [ 0 ] = 0 ;
V_129 -> V_64 [ 0 ] = V_78 ;
V_129 = & V_35 -> V_38 ;
V_129 -> V_43 = F_14 ( V_35 , V_199 ,
V_93 ) ;
V_129 -> V_44 = V_74 ;
V_129 -> V_48 = V_76 ;
for ( V_24 = 0 ; V_24 < V_129 -> V_43 -> V_61 ; V_24 ++ ) {
T_1 V_81 = V_129 -> V_44 * V_129 -> V_43 -> V_82 [ V_24 ] / 4 ;
T_1 V_48 = V_129 -> V_48 * V_129 -> V_43 -> V_83 [ V_24 ] / 4 ;
V_129 -> V_63 [ V_24 ] = V_81 ;
V_129 -> V_64 [ V_24 ] = V_81 * V_48 ;
}
}
static int F_88 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = F_6 ( V_8 ) ;
struct V_200 * V_201 = F_89 ( V_8 ) ;
struct V_1 * V_35 ;
int V_96 = 0 ;
V_35 = F_90 ( sizeof( * V_35 ) , V_202 ) ;
if ( ! V_35 )
return - V_203 ;
if ( F_91 ( & V_13 -> V_183 ) ) {
V_96 = - V_204 ;
goto free;
}
F_92 ( & V_35 -> V_3 , V_201 ) ;
V_8 -> V_119 = & V_35 -> V_3 ;
F_93 ( & V_35 -> V_3 ) ;
V_35 -> V_13 = V_13 ;
V_35 -> V_3 . V_88 = F_94 ( V_13 -> V_168 , V_35 ,
F_75 ) ;
if ( F_95 ( V_35 -> V_3 . V_88 ) ) {
V_96 = F_96 ( V_35 -> V_3 . V_88 ) ;
goto error;
}
F_87 ( V_35 ) ;
F_97 ( & V_13 -> V_183 ) ;
return 0 ;
error:
F_98 ( & V_35 -> V_3 ) ;
F_99 ( & V_35 -> V_3 ) ;
F_97 ( & V_13 -> V_183 ) ;
free:
F_100 ( V_35 ) ;
return V_96 ;
}
static int F_101 ( struct V_8 * V_8 )
{
struct V_12 * V_13 = F_6 ( V_8 ) ;
struct V_1 * V_35 = F_1 ( V_8 -> V_119 ) ;
F_102 ( & V_13 -> V_183 ) ;
F_103 ( V_35 -> V_3 . V_88 ) ;
F_98 ( & V_35 -> V_3 ) ;
F_99 ( & V_35 -> V_3 ) ;
F_100 ( V_35 ) ;
F_97 ( & V_13 -> V_183 ) ;
return 0 ;
}
static int F_104 ( struct V_12 * V_13 )
{
struct V_205 * V_206 ;
struct V_207 * V_208 ;
V_206 = F_105 ( V_13 -> V_18 -> V_209 , L_23 , 0 ) ;
if ( ! V_206 )
return - V_28 ;
V_208 = F_106 ( V_206 ) ;
if ( F_107 ( ! V_208 ) ) {
F_108 ( V_206 ) ;
return - V_28 ;
}
F_108 ( V_206 ) ;
V_13 -> V_185 = & V_208 -> V_18 ;
V_13 -> V_187 = F_109 ( V_13 -> V_18 , L_24 ) ;
if ( F_95 ( V_13 -> V_187 ) )
return - V_28 ;
V_13 -> V_186 = F_109 ( V_13 -> V_18 , L_25 ) ;
if ( F_95 ( V_13 -> V_186 ) )
return - V_28 ;
return 0 ;
}
static int F_110 ( struct V_207 * V_208 )
{
struct V_12 * V_13 ;
struct V_210 * V_211 ;
int V_212 ;
int V_96 ;
V_13 = F_111 ( & V_208 -> V_18 , sizeof( * V_13 ) , V_202 ) ;
if ( ! V_13 )
return - V_203 ;
F_112 ( & V_13 -> V_183 ) ;
F_113 ( & V_13 -> V_169 ) ;
V_13 -> V_18 = & V_208 -> V_18 ;
V_211 = F_114 ( V_208 , V_213 , 0 ) ;
V_13 -> V_170 = F_115 ( & V_208 -> V_18 , V_211 ) ;
if ( F_95 ( V_13 -> V_170 ) ) {
V_96 = F_96 ( V_13 -> V_170 ) ;
return V_96 ;
}
V_211 = F_114 ( V_208 , V_214 , 0 ) ;
V_212 = F_116 ( V_208 , 0 ) ;
if ( ! V_211 || V_212 < 0 ) {
F_37 ( & V_208 -> V_18 , L_26 , V_212 ) ;
V_96 = - V_28 ;
return V_96 ;
}
V_96 = F_117 ( & V_208 -> V_18 , V_212 , F_83 , 0 ,
V_208 -> V_215 , V_13 ) ;
if ( V_96 ) {
F_37 ( & V_208 -> V_18 , L_27 ,
V_212 , V_96 ) ;
V_96 = - V_28 ;
goto V_216;
}
V_96 = F_104 ( V_13 ) ;
if ( V_96 ) {
F_37 ( & V_208 -> V_18 , L_28 , V_96 ) ;
goto V_217;
}
V_96 = F_118 ( & V_208 -> V_18 , & V_13 -> V_85 ) ;
if ( V_96 ) {
F_37 ( & V_208 -> V_18 , L_29 ) ;
V_96 = - V_28 ;
goto V_218;
}
V_13 -> V_168 = F_119 ( & V_219 ) ;
if ( F_95 ( V_13 -> V_168 ) ) {
F_27 ( & V_13 -> V_85 , L_30 ) ;
V_96 = F_96 ( V_13 -> V_168 ) ;
goto V_220;
}
V_13 -> V_221 = F_120 () ;
if ( ! V_13 -> V_221 ) {
V_96 = - V_203 ;
goto V_222;
}
snprintf ( V_13 -> V_221 -> V_215 , sizeof( V_13 -> V_221 -> V_215 ) ,
L_31 , V_15 ) ;
V_13 -> V_221 -> V_223 = & V_224 ;
V_13 -> V_221 -> V_225 = & V_226 ;
V_13 -> V_221 -> V_227 = - 1 ;
V_13 -> V_221 -> V_228 = V_229 ;
V_13 -> V_221 -> V_183 = & V_13 -> V_183 ;
V_13 -> V_221 -> V_85 = & V_13 -> V_85 ;
V_13 -> V_221 -> V_230 = V_231 ;
V_13 -> V_221 -> V_232 = V_233 |
V_234 ;
V_96 = F_121 ( V_13 -> V_221 , V_235 , 3 ) ;
if ( V_96 ) {
F_27 ( & V_13 -> V_85 , L_32 ) ;
goto V_236;
}
F_122 ( V_13 -> V_221 , V_13 ) ;
F_123 ( & V_13 -> V_85 ,
L_33 ,
V_13 -> V_221 -> V_25 , V_237 , V_13 -> V_221 -> V_227 ) ;
F_124 ( V_208 , V_13 ) ;
F_125 ( & V_208 -> V_18 ) ;
return 0 ;
V_236:
V_229 ( V_13 -> V_221 ) ;
V_222:
F_126 ( V_13 -> V_168 ) ;
V_220:
F_127 ( & V_13 -> V_85 ) ;
V_218:
V_217:
V_216:
return V_96 ;
}
static int F_128 ( struct V_207 * V_208 )
{
struct V_12 * V_13 = F_129 ( V_208 ) ;
F_130 ( & V_208 -> V_18 ) ;
F_131 ( V_13 -> V_221 ) ;
V_229 ( V_13 -> V_221 ) ;
F_126 ( V_13 -> V_168 ) ;
F_127 ( & V_13 -> V_85 ) ;
return 0 ;
}
static T_3 int F_132 ( struct V_131 * V_18 )
{
struct V_12 * V_13 = F_133 ( V_18 ) ;
F_69 ( V_13 -> V_170 ) ;
F_80 ( V_13 ) ;
return 0 ;
}
static T_3 int F_134 ( struct V_131 * V_18 )
{
struct V_12 * V_13 = F_133 ( V_18 ) ;
F_77 ( V_13 ) ;
F_69 ( V_13 -> V_170 ) ;
return 0 ;
}
static T_3 int F_135 ( struct V_131 * V_18 )
{
int V_96 ;
if ( F_136 ( V_18 ) )
return 0 ;
V_96 = F_132 ( V_18 ) ;
return V_96 ;
}
static T_3 int F_137 ( struct V_131 * V_18 )
{
int V_96 ;
if ( F_136 ( V_18 ) )
return 0 ;
V_96 = F_134 ( V_18 ) ;
return V_96 ;
}
