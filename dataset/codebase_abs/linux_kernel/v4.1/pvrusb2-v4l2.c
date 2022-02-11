static int F_1 ( struct V_1 * V_1 , void * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
F_2 ( V_4 -> V_12 , L_1 , sizeof( V_4 -> V_12 ) ) ;
F_2 ( V_4 -> V_13 , F_3 ( V_9 ) ,
sizeof( V_4 -> V_13 ) ) ;
F_2 ( V_4 -> V_14 , F_4 ( V_9 ) , sizeof( V_4 -> V_14 ) ) ;
V_4 -> V_15 = V_16 | V_17 |
V_18 | V_19 |
V_20 | V_21 ;
switch ( V_6 -> V_22 -> V_23 . V_24 ) {
case V_25 :
V_4 -> V_26 = V_16 | V_18 ;
break;
case V_27 :
V_4 -> V_26 = V_19 ;
break;
}
V_4 -> V_26 |= V_17 | V_20 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , void * V_2 , T_1 * V_28 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_29 = 0 ;
int V_30 ;
V_30 = F_6 (
F_7 ( V_9 , V_31 ) , & V_29 ) ;
* V_28 = V_29 ;
return V_30 ;
}
static int F_8 ( struct V_1 * V_1 , void * V_2 , T_1 V_28 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
return F_9 (
F_7 ( V_9 , V_31 ) , V_28 ) ;
}
static int F_10 ( struct V_1 * V_1 , void * V_2 , T_1 * V_28 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_29 = 0 ;
int V_30 ;
V_30 = F_6 (
F_7 ( V_9 , V_32 ) , & V_29 ) ;
* V_28 = V_29 ;
return V_30 ;
}
static int F_11 ( struct V_1 * V_1 , void * V_2 , struct V_33 * V_34 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_35 * V_36 ;
struct V_33 V_37 ;
unsigned int V_38 ;
int V_29 ;
V_36 = F_7 ( V_9 , V_39 ) ;
memset ( & V_37 , 0 , sizeof( V_37 ) ) ;
V_37 . V_40 = V_34 -> V_40 ;
if ( V_34 -> V_40 >= V_6 -> V_41 )
return - V_42 ;
V_29 = V_6 -> V_43 [ V_34 -> V_40 ] ;
switch ( V_29 ) {
case V_44 :
case V_45 :
case V_46 :
V_37 . type = V_47 ;
break;
case V_48 :
case V_49 :
V_37 . type = V_50 ;
break;
default:
return - V_42 ;
}
V_38 = 0 ;
F_12 ( V_36 , V_29 ,
V_37 . V_51 , sizeof( V_37 . V_51 ) - 1 , & V_38 ) ;
V_37 . V_51 [ V_38 ] = 0 ;
* V_34 = V_37 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 , void * V_2 , unsigned int * V_52 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned int V_53 ;
struct V_35 * V_36 ;
int V_29 ;
int V_30 ;
V_36 = F_7 ( V_9 , V_39 ) ;
V_29 = 0 ;
V_30 = F_6 ( V_36 , & V_29 ) ;
* V_52 = 0 ;
for ( V_53 = 0 ; V_53 < V_6 -> V_41 ; V_53 ++ ) {
if ( V_6 -> V_43 [ V_53 ] == V_29 ) {
* V_52 = V_53 ;
break;
}
}
return V_30 ;
}
static int F_14 ( struct V_1 * V_1 , void * V_2 , unsigned int V_54 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_54 >= V_6 -> V_41 )
return - V_42 ;
return F_9 (
F_7 ( V_9 , V_39 ) ,
V_6 -> V_43 [ V_54 ] ) ;
}
static int F_15 ( struct V_1 * V_1 , void * V_2 , struct V_55 * V_56 )
{
if ( V_56 -> V_40 > 0 )
return - V_42 ;
strncpy ( V_56 -> V_51 , L_2 , 14 ) ;
V_56 -> V_57 = V_58 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_1 , void * V_2 , struct V_55 * V_56 )
{
V_56 -> V_40 = 0 ;
strncpy ( V_56 -> V_51 , L_2 , 14 ) ;
V_56 -> V_57 = V_58 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , void * V_2 , const struct V_55 * V_59 )
{
if ( V_59 -> V_40 )
return - V_42 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , void * V_2 , struct V_60 * V_61 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_61 -> V_40 != 0 )
return - V_42 ;
F_19 ( V_9 ) ;
return F_20 ( V_9 , V_61 ) ;
}
static int F_21 ( struct V_1 * V_1 , void * V_2 , const struct V_60 * V_61 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_61 -> V_40 != 0 )
return - V_42 ;
return F_9 (
F_7 ( V_9 , V_62 ) ,
V_61 -> V_63 ) ;
}
static int F_22 ( struct V_1 * V_1 , void * V_2 , const struct V_64 * V_65 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned long V_66 ;
struct V_60 V_61 ;
int V_67 ;
struct V_35 * V_68 ;
int V_30 ;
V_30 = F_20 ( V_9 , & V_61 ) ;
if ( V_30 != 0 )
return V_30 ;
V_68 = F_7 ( V_9 , V_39 ) ;
V_30 = F_6 ( V_68 , & V_67 ) ;
if ( V_30 != 0 )
return V_30 ;
if ( V_65 -> type == V_69 ) {
if ( V_67 != V_46 )
F_9 ( V_68 , V_46 ) ;
} else {
if ( V_67 == V_46 )
F_9 ( V_68 , V_44 ) ;
}
V_66 = V_65 -> V_70 ;
if ( V_61 . V_57 & V_71 )
V_66 = ( V_66 * 125 ) / 2 ;
else
V_66 = V_66 * 62500 ;
return F_9 (
F_7 ( V_9 , V_72 ) , V_66 ) ;
}
static int F_23 ( struct V_1 * V_1 , void * V_2 , struct V_64 * V_65 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_29 = 0 ;
int V_67 ;
struct V_60 V_61 ;
int V_30 ;
V_30 = F_20 ( V_9 , & V_61 ) ;
if ( V_30 != 0 )
return V_30 ;
V_30 = F_6 (
F_7 ( V_9 , V_72 ) ,
& V_29 ) ;
if ( V_30 != 0 )
return V_30 ;
F_6 (
F_7 ( V_9 , V_39 ) ,
& V_67 ) ;
if ( V_67 == V_46 )
V_65 -> type = V_69 ;
else
V_65 -> type = V_73 ;
if ( V_61 . V_57 & V_71 )
V_29 = ( V_29 * 2 ) / 125 ;
else
V_29 /= 62500 ;
V_65 -> V_70 = V_29 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_1 , void * V_2 , struct V_74 * V_75 )
{
if ( V_75 -> V_40 != 0 )
return - V_42 ;
memcpy ( V_75 , V_76 , sizeof( struct V_74 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_1 , void * V_2 , struct V_77 * V_65 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_29 ;
memcpy ( V_65 , & V_78 [ V_79 ] , sizeof( struct V_77 ) ) ;
V_29 = 0 ;
F_6 (
F_7 ( V_9 , V_80 ) ,
& V_29 ) ;
V_65 -> V_81 . V_82 . V_83 = V_29 ;
V_29 = 0 ;
F_6 (
F_7 ( V_9 , V_84 ) ,
& V_29 ) ;
V_65 -> V_81 . V_82 . V_85 = V_29 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , void * V_2 , struct V_77 * V_65 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_86 , V_87 , V_88 ;
struct V_35 * V_89 , * V_90 ;
int V_91 = V_65 -> V_81 . V_82 . V_85 ;
int V_92 = V_65 -> V_81 . V_82 . V_83 ;
V_89 = F_7 ( V_9 , V_80 ) ;
V_90 = F_7 ( V_9 , V_84 ) ;
V_86 = F_27 ( V_89 ) ;
V_87 = F_28 ( V_89 ) ;
F_29 ( V_89 , & V_88 ) ;
if ( V_92 == - 1 )
V_92 = V_88 ;
else if ( V_92 < V_86 )
V_92 = V_86 ;
else if ( V_92 > V_87 )
V_92 = V_87 ;
V_86 = F_27 ( V_90 ) ;
V_87 = F_28 ( V_90 ) ;
F_29 ( V_90 , & V_88 ) ;
if ( V_91 == - 1 )
V_91 = V_88 ;
else if ( V_91 < V_86 )
V_91 = V_86 ;
else if ( V_91 > V_87 )
V_91 = V_87 ;
memcpy ( V_65 , & V_78 [ V_79 ] ,
sizeof( struct V_77 ) ) ;
V_65 -> V_81 . V_82 . V_83 = V_92 ;
V_65 -> V_81 . V_82 . V_85 = V_91 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , void * V_2 , struct V_77 * V_65 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_35 * V_89 , * V_90 ;
int V_30 = F_26 ( V_1 , V_6 , V_65 ) ;
if ( V_30 )
return V_30 ;
V_89 = F_7 ( V_9 , V_80 ) ;
V_90 = F_7 ( V_9 , V_84 ) ;
F_9 ( V_89 , V_65 -> V_81 . V_82 . V_83 ) ;
F_9 ( V_90 , V_65 -> V_81 . V_82 . V_85 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , void * V_2 , enum V_93 V_52 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_94 * V_22 = V_6 -> V_22 ;
int V_30 ;
if ( ! V_6 -> V_22 -> V_95 ) {
return - V_96 ;
}
V_30 = F_32 ( V_9 , V_22 -> V_97 ) ;
if ( V_30 < 0 )
return V_30 ;
return F_33 ( V_9 , ! 0 ) ;
}
static int F_34 ( struct V_1 * V_1 , void * V_2 , enum V_93 V_52 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( ! V_6 -> V_22 -> V_95 ) {
return - V_96 ;
}
return F_33 ( V_9 , 0 ) ;
}
static int F_35 ( struct V_1 * V_1 , void * V_2 ,
struct V_98 * V_99 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_35 * V_36 ;
int V_29 ;
if ( V_99 -> V_100 & V_101 ) {
V_36 = F_36 (
V_9 , ( V_99 -> V_100 & ~ V_101 ) ) ;
if ( V_36 )
V_99 -> V_100 = F_37 ( V_36 ) ;
} else {
V_36 = F_38 ( V_9 , V_99 -> V_100 ) ;
}
if ( ! V_36 ) {
F_39 ( V_102 ,
L_3 ,
V_99 -> V_100 ) ;
return - V_42 ;
}
F_39 ( V_102 ,
L_4 ,
V_99 -> V_100 , F_40 ( V_36 ) ,
F_41 ( V_36 ) ) ;
F_2 ( V_99 -> V_51 , F_41 ( V_36 ) , sizeof( V_99 -> V_51 ) ) ;
V_99 -> V_103 = F_42 ( V_36 ) ;
F_29 ( V_36 , & V_29 ) ;
V_99 -> V_104 = V_29 ;
switch ( F_43 ( V_36 ) ) {
case V_105 :
V_99 -> type = V_106 ;
V_99 -> V_107 = 0 ;
V_99 -> V_108 = F_44 ( V_36 ) - 1 ;
V_99 -> V_109 = 1 ;
break;
case V_110 :
V_99 -> type = V_111 ;
V_99 -> V_107 = 0 ;
V_99 -> V_108 = 1 ;
V_99 -> V_109 = 1 ;
break;
case V_112 :
V_99 -> type = V_113 ;
V_99 -> V_107 = F_27 ( V_36 ) ;
V_99 -> V_108 = F_28 ( V_36 ) ;
V_99 -> V_109 = 1 ;
break;
default:
F_39 ( V_102 ,
L_5 ,
V_99 -> V_100 , F_40 ( V_36 ) ) ;
return - V_42 ;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , void * V_2 , struct V_114 * V_115 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned int V_38 = 0 ;
int V_30 ;
V_30 = F_12 ( F_38 ( V_9 , V_115 -> V_100 ) ,
V_115 -> V_40 ,
V_115 -> V_51 , sizeof( V_115 -> V_51 ) - 1 ,
& V_38 ) ;
V_115 -> V_51 [ V_38 ] = 0 ;
return V_30 ;
}
static int F_46 ( struct V_1 * V_1 , void * V_2 , struct V_116 * V_99 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_29 = 0 ;
int V_30 ;
V_30 = F_6 ( F_38 ( V_9 , V_99 -> V_100 ) ,
& V_29 ) ;
V_99 -> V_117 = V_29 ;
return V_30 ;
}
static int F_47 ( struct V_1 * V_1 , void * V_2 , struct V_116 * V_99 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
return F_9 ( F_38 ( V_9 , V_99 -> V_100 ) ,
V_99 -> V_117 ) ;
}
static int F_48 ( struct V_1 * V_1 , void * V_2 ,
struct V_118 * V_119 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_120 * V_121 ;
unsigned int V_53 ;
int V_29 ;
int V_30 ;
V_30 = 0 ;
for ( V_53 = 0 ; V_53 < V_119 -> V_122 ; V_53 ++ ) {
V_121 = V_119 -> V_123 + V_53 ;
V_30 = F_6 (
F_38 ( V_9 , V_121 -> V_100 ) , & V_29 ) ;
if ( V_30 ) {
V_119 -> V_124 = V_53 ;
return V_30 ;
}
V_121 -> V_125 = 0 ;
V_121 -> V_117 = V_29 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , void * V_2 ,
struct V_118 * V_119 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_120 * V_121 ;
unsigned int V_53 ;
int V_30 ;
V_30 = 0 ;
for ( V_53 = 0 ; V_53 < V_119 -> V_122 ; V_53 ++ ) {
V_121 = V_119 -> V_123 + V_53 ;
V_30 = F_9 (
F_38 ( V_9 , V_121 -> V_100 ) ,
V_121 -> V_117 ) ;
if ( V_30 ) {
V_119 -> V_124 = V_53 ;
return V_30 ;
}
}
return 0 ;
}
static int F_50 ( struct V_1 * V_1 , void * V_2 ,
struct V_118 * V_119 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_120 * V_121 ;
struct V_35 * V_126 ;
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_119 -> V_122 ; V_53 ++ ) {
V_121 = V_119 -> V_123 + V_53 ;
V_126 = F_38 ( V_9 , V_121 -> V_100 ) ;
if ( ! V_126 ) {
V_119 -> V_124 = V_53 ;
return - V_42 ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , void * V_2 , struct V_127 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_30 ;
if ( V_4 -> type != V_128 )
return - V_42 ;
V_30 = F_52 ( V_9 , V_4 ) ;
V_4 -> type = V_128 ;
return V_30 ;
}
static int F_53 ( struct V_1 * V_1 , void * V_2 , struct V_129 * V_130 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_29 = 0 ;
int V_30 ;
if ( V_130 -> type != V_128 )
return - V_42 ;
V_30 = F_6 (
F_7 ( V_9 , V_131 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_130 -> V_132 . V_133 = V_29 ;
V_30 = F_6 (
F_7 ( V_9 , V_134 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_130 -> V_132 . V_135 = V_29 ;
V_30 = F_6 (
F_7 ( V_9 , V_136 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_130 -> V_132 . V_83 = V_29 ;
V_30 = F_6 (
F_7 ( V_9 , V_137 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_130 -> V_132 . V_85 = V_29 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_1 , void * V_2 , const struct V_129 * V_130 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_30 ;
if ( V_130 -> type != V_128 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_131 ) ,
V_130 -> V_132 . V_133 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_134 ) ,
V_130 -> V_132 . V_135 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_136 ) ,
V_130 -> V_132 . V_83 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_137 ) ,
V_130 -> V_132 . V_85 ) ;
if ( V_30 != 0 )
return - V_42 ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , void * V_2 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
F_56 ( V_9 ) ;
return 0 ;
}
static void F_57 ( struct V_94 * V_138 )
{
struct V_8 * V_9 = V_138 -> V_139 -> V_10 . V_11 -> V_9 ;
enum V_140 V_141 = V_138 -> V_97 ;
char V_142 [ 80 ] ;
unsigned int V_143 ;
V_143 = F_58 ( V_142 , sizeof( V_142 ) - 1 ,
L_6 ,
F_59 ( & V_138 -> V_23 ) ,
F_60 ( V_141 ) ) ;
V_142 [ V_143 ] = 0 ;
F_61 ( V_9 , V_138 -> V_144 , - 1 ) ;
V_138 -> V_139 = NULL ;
V_138 -> V_95 = NULL ;
F_62 ( & V_138 -> V_23 ) ;
F_63 ( V_145 L_7 , V_142 ) ;
}
static void F_64 ( struct V_94 * V_138 )
{
if ( ! V_138 ) return;
if ( ! V_138 -> V_23 . V_146 -> V_147 ) return;
V_138 -> V_23 . V_146 -> V_147 = NULL ;
F_65 ( & V_138 -> V_23 . V_147 , NULL , V_148 ) ;
}
static void F_66 ( struct V_149 * V_150 )
{
if ( V_150 -> V_151 ) {
F_57 ( V_150 -> V_151 ) ;
V_150 -> V_151 = NULL ;
}
if ( V_150 -> V_152 ) {
F_57 ( V_150 -> V_152 ) ;
V_150 -> V_152 = NULL ;
}
F_39 ( V_153 , L_8 , V_150 ) ;
F_67 ( & V_150 -> V_10 ) ;
F_68 ( V_150 ) ;
}
static void F_69 ( struct V_154 * V_155 )
{
struct V_94 * V_147 ;
V_147 = F_70 ( V_155 , struct V_94 , V_23 ) ;
F_68 ( V_147 ) ;
}
static void F_71 ( struct V_156 * V_157 )
{
struct V_149 * V_150 ;
V_150 = F_70 ( V_157 , struct V_149 , V_10 ) ;
if ( ! V_150 -> V_10 . V_11 -> V_158 ) return;
F_64 ( V_150 -> V_151 ) ;
F_64 ( V_150 -> V_152 ) ;
if ( ! F_72 ( & V_150 -> V_151 -> V_23 . V_159 ) ||
! F_72 ( & V_150 -> V_152 -> V_23 . V_159 ) )
return;
F_66 ( V_150 ) ;
}
static long F_73 ( struct V_1 * V_1 ,
unsigned int V_160 , unsigned long V_161 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
long V_30 = - V_42 ;
if ( V_162 & V_102 )
F_74 ( F_75 ( V_9 ) , V_160 ) ;
if ( ! F_76 ( V_9 ) ) {
F_39 ( V_163 ,
L_9 ) ;
return - V_164 ;
}
V_30 = F_77 ( V_1 , V_160 , V_161 ) ;
F_78 ( V_9 ) ;
if ( V_30 < 0 ) {
if ( V_162 & V_102 ) {
F_39 ( V_102 ,
L_10
L_11 , V_30 ) ;
F_74 ( F_75 ( V_9 ) , V_160 ) ;
}
} else {
F_39 ( V_102 ,
L_12 ,
V_30 , V_30 ) ;
}
return V_30 ;
}
static int F_79 ( struct V_1 * V_1 )
{
struct V_5 * V_165 = V_1 -> V_7 ;
struct V_149 * V_150 = V_165 -> V_22 -> V_139 ;
struct V_8 * V_9 = V_165 -> V_10 . V_11 -> V_9 ;
F_39 ( V_166 , L_13 ) ;
if ( V_165 -> V_167 ) {
struct V_168 * V_169 ;
F_33 ( V_9 , 0 ) ;
V_169 = F_80 ( V_165 -> V_167 ) ;
if ( V_169 ) F_81 ( V_169 , NULL , NULL ) ;
F_82 ( V_165 -> V_167 ) ;
V_165 -> V_167 = NULL ;
}
F_83 ( & V_165 -> V_6 ) ;
F_84 ( & V_165 -> V_6 ) ;
V_1 -> V_7 = NULL ;
F_67 ( & V_165 -> V_10 ) ;
F_39 ( V_153 ,
L_14 , V_165 ) ;
if ( V_165 -> V_43 ) {
F_68 ( V_165 -> V_43 ) ;
V_165 -> V_43 = NULL ;
}
F_68 ( V_165 ) ;
if ( V_150 -> V_10 . V_11 -> V_158 &&
F_72 ( & V_150 -> V_151 -> V_23 . V_159 ) &&
F_72 ( & V_150 -> V_152 -> V_23 . V_159 ) ) {
F_66 ( V_150 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_1 )
{
struct V_94 * V_138 ;
struct V_5 * V_165 ;
struct V_149 * V_150 ;
struct V_8 * V_9 ;
unsigned int V_170 = 0 ;
unsigned int V_41 , V_53 ;
int V_30 = 0 ;
V_138 = F_70 ( F_86 ( V_1 ) , struct V_94 , V_23 ) ;
V_150 = V_138 -> V_139 ;
V_9 = V_150 -> V_10 . V_9 ;
F_39 ( V_166 , L_15 ) ;
if ( ! F_76 ( V_9 ) ) {
F_39 ( V_166 ,
L_16 ) ;
return - V_171 ;
}
V_165 = F_87 ( sizeof( * V_165 ) , V_172 ) ;
if ( ! V_165 ) {
return - V_173 ;
}
F_88 ( & V_165 -> V_6 , & V_138 -> V_23 ) ;
F_89 ( & V_165 -> V_174 ) ;
V_165 -> V_22 = V_138 ;
F_39 ( V_153 , L_17 , V_165 ) ;
F_90 ( & V_165 -> V_10 , V_150 -> V_10 . V_11 ) ;
if ( V_138 -> V_175 == V_27 ) {
V_170 = ( 1 << V_46 ) ;
} else {
V_170 = ( ( 1 << V_46 ) |
( 1 << V_44 ) |
( 1 << V_49 ) |
( 1 << V_48 ) ) ;
}
V_30 = F_91 ( & V_165 -> V_10 , V_170 ) ;
if ( V_30 ) {
F_67 ( & V_165 -> V_10 ) ;
F_39 ( V_153 ,
L_18 ,
V_165 ) ;
F_68 ( V_165 ) ;
return V_30 ;
}
V_170 &= F_92 ( V_9 ) ;
V_41 = 0 ;
for ( V_53 = 0 ; V_53 < ( sizeof( V_170 ) << 3 ) ; V_53 ++ ) {
if ( V_170 & ( 1 << V_53 ) ) V_41 ++ ;
}
V_165 -> V_41 = V_41 ;
V_165 -> V_43 = F_87 ( V_41 , V_172 ) ;
if ( ! V_165 -> V_43 ) {
F_67 ( & V_165 -> V_10 ) ;
F_39 ( V_153 ,
L_19 ,
V_165 ) ;
F_68 ( V_165 ) ;
return - V_173 ;
}
V_41 = 0 ;
for ( V_53 = 0 ; V_53 < ( sizeof( V_170 ) << 3 ) ; V_53 ++ ) {
if ( ! ( V_170 & ( 1 << V_53 ) ) ) continue;
V_165 -> V_43 [ V_41 ++ ] = V_53 ;
}
V_165 -> V_1 = V_1 ;
V_1 -> V_7 = V_165 ;
V_165 -> V_176 = F_93 ( V_9 ) ;
F_94 ( & V_165 -> V_6 ) ;
return 0 ;
}
static void F_95 ( struct V_5 * V_165 )
{
F_96 ( & V_165 -> V_174 ) ;
}
static int F_97 ( struct V_5 * V_6 )
{
int V_30 ;
struct V_168 * V_169 ;
struct V_8 * V_9 ;
if ( V_6 -> V_167 ) return 0 ;
if ( ! V_6 -> V_22 -> V_95 ) {
return - V_96 ;
}
if ( ( V_30 = F_98 ( & V_6 -> V_10 ,
V_6 -> V_22 -> V_95 ) ) != 0 ) {
return V_30 ;
}
V_6 -> V_167 = F_99 ( V_6 -> V_22 -> V_95 ) ;
if ( ! V_6 -> V_167 ) {
F_98 ( & V_6 -> V_10 , NULL ) ;
return - V_173 ;
}
V_9 = V_6 -> V_10 . V_11 -> V_9 ;
V_169 = V_6 -> V_22 -> V_95 -> V_95 ;
F_81 ( V_169 , ( V_177 ) F_95 , V_6 ) ;
F_32 ( V_9 , V_6 -> V_22 -> V_97 ) ;
if ( ( V_30 = F_33 ( V_9 , ! 0 ) ) < 0 ) return V_30 ;
return F_100 ( V_6 -> V_167 , ! 0 ) ;
}
static T_2 F_101 ( struct V_1 * V_1 ,
char T_3 * V_178 , T_4 V_122 , T_5 * V_179 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_30 ;
if ( V_6 -> V_176 ) {
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
char * V_180 ;
int V_181 , V_182 ;
int V_183 = 0 ;
unsigned int V_184 = * V_179 ;
V_180 = F_102 ( V_185 , V_172 ) ;
if ( ! V_180 ) return - V_173 ;
while ( V_122 ) {
V_181 = V_122 ;
if ( V_181 > V_185 ) V_181 = V_185 ;
V_182 = F_103 ( V_9 , V_184 , V_180 , V_181 ) ;
if ( V_182 < 0 ) {
V_183 = V_182 ;
break;
}
if ( ! V_182 ) break;
if ( F_104 ( V_178 , V_180 , V_182 ) ) {
V_183 = - V_164 ;
break;
}
V_184 += V_182 ;
V_183 += V_182 ;
V_178 += V_182 ;
V_122 -= V_182 ;
* V_179 += V_182 ;
}
F_68 ( V_180 ) ;
return V_183 ;
}
if ( ! V_6 -> V_167 ) {
V_30 = F_97 ( V_6 ) ;
if ( V_30 ) {
return V_30 ;
}
}
for (; ; ) {
V_30 = F_105 ( V_6 -> V_167 , V_178 , V_122 ) ;
if ( V_30 >= 0 ) break;
if ( V_30 != - V_186 ) break;
if ( V_1 -> V_187 & V_188 ) break;
V_30 = F_106 (
V_6 -> V_174 ,
F_107 ( V_6 -> V_167 ) >= 0 ) ;
if ( V_30 < 0 ) break;
}
return V_30 ;
}
static unsigned int F_108 ( struct V_1 * V_1 , T_6 * V_189 )
{
unsigned int V_190 = 0 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_30 ;
if ( V_6 -> V_176 ) {
V_190 |= V_191 | V_192 ;
return V_190 ;
}
if ( ! V_6 -> V_167 ) {
V_30 = F_97 ( V_6 ) ;
if ( V_30 ) return V_193 ;
}
F_109 ( V_1 , & V_6 -> V_174 , V_189 ) ;
if ( F_107 ( V_6 -> V_167 ) >= 0 ) {
V_190 |= V_191 | V_192 ;
}
return V_190 ;
}
static void F_110 ( struct V_94 * V_138 ,
struct V_149 * V_150 ,
int V_175 )
{
int V_194 ;
int V_195 ;
struct V_8 * V_9 ;
int * V_196 = NULL ;
V_138 -> V_139 = V_150 ;
V_9 = V_150 -> V_10 . V_11 -> V_9 ;
V_138 -> V_175 = V_175 ;
switch ( V_175 ) {
case V_25 :
V_138 -> V_95 = & V_150 -> V_10 . V_11 -> V_197 ;
V_138 -> V_97 = V_198 ;
V_138 -> V_144 = V_199 ;
V_196 = V_200 ;
if ( ! V_138 -> V_95 ) {
F_111 ( V_201
L_20
L_21 ) ;
return;
}
break;
case V_202 :
V_138 -> V_97 = V_203 ;
V_138 -> V_144 = V_204 ;
V_196 = V_205 ;
break;
case V_27 :
V_138 -> V_95 = & V_150 -> V_10 . V_11 -> V_197 ;
V_138 -> V_97 = V_198 ;
V_138 -> V_144 = V_206 ;
V_196 = V_207 ;
break;
default:
F_111 ( V_201 L_22
L_23 ) ;
return;
}
V_138 -> V_23 = V_208 ;
V_138 -> V_23 . V_209 = F_69 ;
V_138 -> V_23 . V_210 = & V_211 ;
{
int V_29 ;
F_6 (
F_7 ( V_9 ,
V_212 ) , & V_29 ) ;
V_138 -> V_23 . V_213 = ( T_1 ) V_29 ;
}
V_194 = - 1 ;
V_195 = F_112 ( V_9 ) ;
if ( V_196 && ( V_195 >= 0 ) && ( V_195 < V_214 ) ) {
V_194 = V_196 [ V_195 ] ;
}
F_113 ( V_9 , & V_138 -> V_23 ) ;
if ( ( F_114 ( & V_138 -> V_23 ,
V_138 -> V_175 , V_194 ) < 0 ) &&
( F_114 ( & V_138 -> V_23 ,
V_138 -> V_175 , - 1 ) < 0 ) ) {
F_111 ( V_201
L_24 ) ;
}
F_63 ( V_145 L_25 ,
F_59 ( & V_138 -> V_23 ) ,
F_60 ( V_138 -> V_97 ) ) ;
F_61 ( V_9 ,
V_138 -> V_144 , V_138 -> V_23 . V_215 ) ;
}
struct V_149 * F_115 ( struct V_216 * V_217 )
{
struct V_149 * V_150 ;
V_150 = F_87 ( sizeof( * V_150 ) , V_172 ) ;
if ( ! V_150 ) return V_150 ;
F_90 ( & V_150 -> V_10 , V_217 ) ;
F_39 ( V_153 , L_26 , V_150 ) ;
V_150 -> V_10 . V_218 = F_71 ;
V_150 -> V_151 = F_87 ( sizeof( * V_150 -> V_151 ) , V_172 ) ;
if ( ! V_150 -> V_151 ) goto V_219;
F_110 ( V_150 -> V_151 , V_150 , V_25 ) ;
if ( F_92 ( V_150 -> V_10 . V_11 -> V_9 ) &
( 1 << V_46 ) ) {
V_150 -> V_152 = F_87 ( sizeof( * V_150 -> V_152 ) , V_172 ) ;
if ( ! V_150 -> V_152 ) goto V_219;
F_110 ( V_150 -> V_152 , V_150 , V_27 ) ;
}
return V_150 ;
V_219:
F_39 ( V_153 , L_27 , V_150 ) ;
F_66 ( V_150 ) ;
return NULL ;
}
