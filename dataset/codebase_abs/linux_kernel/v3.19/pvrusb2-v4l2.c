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
static int F_5 ( struct V_1 * V_1 , void * V_2 , enum V_28 * V_29 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_30 * V_31 = V_6 -> V_32 ;
* V_29 = F_6 ( & V_31 -> V_33 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , void * V_2 , enum V_28 V_33 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_30 * V_31 = V_6 -> V_32 ;
return F_8 ( & V_31 -> V_33 , & V_6 -> V_33 , V_33 ) ;
}
static int F_9 ( struct V_1 * V_1 , void * V_2 , T_1 * V_34 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_35 = 0 ;
int V_36 ;
V_36 = F_10 (
F_11 ( V_9 , V_37 ) , & V_35 ) ;
* V_34 = V_35 ;
return V_36 ;
}
static int F_12 ( struct V_1 * V_1 , void * V_2 , T_1 V_34 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
return F_13 (
F_11 ( V_9 , V_37 ) , V_34 ) ;
}
static int F_14 ( struct V_1 * V_1 , void * V_2 , T_1 * V_34 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_35 = 0 ;
int V_36 ;
V_36 = F_10 (
F_11 ( V_9 , V_38 ) , & V_35 ) ;
* V_34 = V_35 ;
return V_36 ;
}
static int F_15 ( struct V_1 * V_1 , void * V_2 , struct V_39 * V_40 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_41 * V_42 ;
struct V_39 V_43 ;
unsigned int V_44 ;
int V_35 ;
V_42 = F_11 ( V_9 , V_45 ) ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_46 = V_40 -> V_46 ;
if ( V_40 -> V_46 >= V_6 -> V_47 )
return - V_48 ;
V_35 = V_6 -> V_49 [ V_40 -> V_46 ] ;
switch ( V_35 ) {
case V_50 :
case V_51 :
case V_52 :
V_43 . type = V_53 ;
break;
case V_54 :
case V_55 :
V_43 . type = V_56 ;
break;
default:
return - V_48 ;
}
V_44 = 0 ;
F_16 ( V_42 , V_35 ,
V_43 . V_57 , sizeof( V_43 . V_57 ) - 1 , & V_44 ) ;
V_43 . V_57 [ V_44 ] = 0 ;
* V_40 = V_43 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , void * V_2 , unsigned int * V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned int V_59 ;
struct V_41 * V_42 ;
int V_35 ;
int V_36 ;
V_42 = F_11 ( V_9 , V_45 ) ;
V_35 = 0 ;
V_36 = F_10 ( V_42 , & V_35 ) ;
* V_58 = 0 ;
for ( V_59 = 0 ; V_59 < V_6 -> V_47 ; V_59 ++ ) {
if ( V_6 -> V_49 [ V_59 ] == V_35 ) {
* V_58 = V_59 ;
break;
}
}
return V_36 ;
}
static int F_18 ( struct V_1 * V_1 , void * V_2 , unsigned int V_60 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_60 >= V_6 -> V_47 )
return - V_48 ;
return F_13 (
F_11 ( V_9 , V_45 ) ,
V_6 -> V_49 [ V_60 ] ) ;
}
static int F_19 ( struct V_1 * V_1 , void * V_2 , struct V_61 * V_62 )
{
if ( V_62 -> V_46 > 0 )
return - V_48 ;
strncpy ( V_62 -> V_57 , L_2 , 14 ) ;
V_62 -> V_63 = V_64 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , void * V_2 , struct V_61 * V_62 )
{
V_62 -> V_46 = 0 ;
strncpy ( V_62 -> V_57 , L_2 , 14 ) ;
V_62 -> V_63 = V_64 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , void * V_2 , const struct V_61 * V_65 )
{
if ( V_65 -> V_46 )
return - V_48 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 , void * V_2 , struct V_66 * V_67 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_67 -> V_46 != 0 )
return - V_48 ;
F_23 ( V_9 ) ;
return F_24 ( V_9 , V_67 ) ;
}
static int F_25 ( struct V_1 * V_1 , void * V_2 , const struct V_66 * V_67 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_67 -> V_46 != 0 )
return - V_48 ;
return F_13 (
F_11 ( V_9 , V_68 ) ,
V_67 -> V_69 ) ;
}
static int F_26 ( struct V_1 * V_1 , void * V_2 , const struct V_70 * V_71 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned long V_72 ;
struct V_66 V_67 ;
int V_73 ;
struct V_41 * V_74 ;
int V_36 ;
V_36 = F_24 ( V_9 , & V_67 ) ;
if ( V_36 != 0 )
return V_36 ;
V_74 = F_11 ( V_9 , V_45 ) ;
V_36 = F_10 ( V_74 , & V_73 ) ;
if ( V_36 != 0 )
return V_36 ;
if ( V_71 -> type == V_75 ) {
if ( V_73 != V_52 )
F_13 ( V_74 , V_52 ) ;
} else {
if ( V_73 == V_52 )
F_13 ( V_74 , V_50 ) ;
}
V_72 = V_71 -> V_76 ;
if ( V_67 . V_63 & V_77 )
V_72 = ( V_72 * 125 ) / 2 ;
else
V_72 = V_72 * 62500 ;
return F_13 (
F_11 ( V_9 , V_78 ) , V_72 ) ;
}
static int F_27 ( struct V_1 * V_1 , void * V_2 , struct V_70 * V_71 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_35 = 0 ;
int V_73 ;
struct V_66 V_67 ;
int V_36 ;
V_36 = F_24 ( V_9 , & V_67 ) ;
if ( V_36 != 0 )
return V_36 ;
V_36 = F_10 (
F_11 ( V_9 , V_78 ) ,
& V_35 ) ;
if ( V_36 != 0 )
return V_36 ;
F_10 (
F_11 ( V_9 , V_45 ) ,
& V_73 ) ;
if ( V_73 == V_52 )
V_71 -> type = V_75 ;
else
V_71 -> type = V_79 ;
if ( V_67 . V_63 & V_77 )
V_35 = ( V_35 * 2 ) / 125 ;
else
V_35 /= 62500 ;
V_71 -> V_76 = V_35 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , void * V_2 , struct V_80 * V_81 )
{
if ( V_81 -> V_46 != 0 )
return - V_48 ;
memcpy ( V_81 , V_82 , sizeof( struct V_80 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , void * V_2 , struct V_83 * V_71 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_35 ;
memcpy ( V_71 , & V_84 [ V_85 ] , sizeof( struct V_83 ) ) ;
V_35 = 0 ;
F_10 (
F_11 ( V_9 , V_86 ) ,
& V_35 ) ;
V_71 -> V_87 . V_88 . V_89 = V_35 ;
V_35 = 0 ;
F_10 (
F_11 ( V_9 , V_90 ) ,
& V_35 ) ;
V_71 -> V_87 . V_88 . V_91 = V_35 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , void * V_2 , struct V_83 * V_71 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_92 , V_93 , V_94 ;
struct V_41 * V_95 , * V_96 ;
int V_97 = V_71 -> V_87 . V_88 . V_91 ;
int V_98 = V_71 -> V_87 . V_88 . V_89 ;
V_95 = F_11 ( V_9 , V_86 ) ;
V_96 = F_11 ( V_9 , V_90 ) ;
V_92 = F_31 ( V_95 ) ;
V_93 = F_32 ( V_95 ) ;
F_33 ( V_95 , & V_94 ) ;
if ( V_98 == - 1 )
V_98 = V_94 ;
else if ( V_98 < V_92 )
V_98 = V_92 ;
else if ( V_98 > V_93 )
V_98 = V_93 ;
V_92 = F_31 ( V_96 ) ;
V_93 = F_32 ( V_96 ) ;
F_33 ( V_96 , & V_94 ) ;
if ( V_97 == - 1 )
V_97 = V_94 ;
else if ( V_97 < V_92 )
V_97 = V_92 ;
else if ( V_97 > V_93 )
V_97 = V_93 ;
memcpy ( V_71 , & V_84 [ V_85 ] ,
sizeof( struct V_83 ) ) ;
V_71 -> V_87 . V_88 . V_89 = V_98 ;
V_71 -> V_87 . V_88 . V_91 = V_97 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , void * V_2 , struct V_83 * V_71 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_41 * V_95 , * V_96 ;
int V_36 = F_30 ( V_1 , V_6 , V_71 ) ;
if ( V_36 )
return V_36 ;
V_95 = F_11 ( V_9 , V_86 ) ;
V_96 = F_11 ( V_9 , V_90 ) ;
F_13 ( V_95 , V_71 -> V_87 . V_88 . V_89 ) ;
F_13 ( V_96 , V_71 -> V_87 . V_88 . V_91 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , void * V_2 , enum V_99 V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_100 * V_22 = V_6 -> V_22 ;
int V_36 ;
if ( ! V_6 -> V_22 -> V_101 ) {
return - V_102 ;
}
V_36 = F_36 ( V_9 , V_22 -> V_103 ) ;
if ( V_36 < 0 )
return V_36 ;
return F_37 ( V_9 , ! 0 ) ;
}
static int F_38 ( struct V_1 * V_1 , void * V_2 , enum V_99 V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( ! V_6 -> V_22 -> V_101 ) {
return - V_102 ;
}
return F_37 ( V_9 , 0 ) ;
}
static int F_39 ( struct V_1 * V_1 , void * V_2 ,
struct V_104 * V_105 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_41 * V_42 ;
int V_35 ;
if ( V_105 -> V_106 & V_107 ) {
V_42 = F_40 (
V_9 , ( V_105 -> V_106 & ~ V_107 ) ) ;
if ( V_42 )
V_105 -> V_106 = F_41 ( V_42 ) ;
} else {
V_42 = F_42 ( V_9 , V_105 -> V_106 ) ;
}
if ( ! V_42 ) {
F_43 ( V_108 ,
L_3 ,
V_105 -> V_106 ) ;
return - V_48 ;
}
F_43 ( V_108 ,
L_4 ,
V_105 -> V_106 , F_44 ( V_42 ) ,
F_45 ( V_42 ) ) ;
F_2 ( V_105 -> V_57 , F_45 ( V_42 ) , sizeof( V_105 -> V_57 ) ) ;
V_105 -> V_109 = F_46 ( V_42 ) ;
F_33 ( V_42 , & V_35 ) ;
V_105 -> V_110 = V_35 ;
switch ( F_47 ( V_42 ) ) {
case V_111 :
V_105 -> type = V_112 ;
V_105 -> V_113 = 0 ;
V_105 -> V_114 = F_48 ( V_42 ) - 1 ;
V_105 -> V_115 = 1 ;
break;
case V_116 :
V_105 -> type = V_117 ;
V_105 -> V_113 = 0 ;
V_105 -> V_114 = 1 ;
V_105 -> V_115 = 1 ;
break;
case V_118 :
V_105 -> type = V_119 ;
V_105 -> V_113 = F_31 ( V_42 ) ;
V_105 -> V_114 = F_32 ( V_42 ) ;
V_105 -> V_115 = 1 ;
break;
default:
F_43 ( V_108 ,
L_5 ,
V_105 -> V_106 , F_44 ( V_42 ) ) ;
return - V_48 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , void * V_2 , struct V_120 * V_121 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned int V_44 = 0 ;
int V_36 ;
V_36 = F_16 ( F_42 ( V_9 , V_121 -> V_106 ) ,
V_121 -> V_46 ,
V_121 -> V_57 , sizeof( V_121 -> V_57 ) - 1 ,
& V_44 ) ;
V_121 -> V_57 [ V_44 ] = 0 ;
return V_36 ;
}
static int F_50 ( struct V_1 * V_1 , void * V_2 , struct V_122 * V_105 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_35 = 0 ;
int V_36 ;
V_36 = F_10 ( F_42 ( V_9 , V_105 -> V_106 ) ,
& V_35 ) ;
V_105 -> V_123 = V_35 ;
return V_36 ;
}
static int F_51 ( struct V_1 * V_1 , void * V_2 , struct V_122 * V_105 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
return F_13 ( F_42 ( V_9 , V_105 -> V_106 ) ,
V_105 -> V_123 ) ;
}
static int F_52 ( struct V_1 * V_1 , void * V_2 ,
struct V_124 * V_125 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_126 * V_127 ;
unsigned int V_59 ;
int V_35 ;
int V_36 ;
V_36 = 0 ;
for ( V_59 = 0 ; V_59 < V_125 -> V_128 ; V_59 ++ ) {
V_127 = V_125 -> V_129 + V_59 ;
V_36 = F_10 (
F_42 ( V_9 , V_127 -> V_106 ) , & V_35 ) ;
if ( V_36 ) {
V_125 -> V_130 = V_59 ;
return V_36 ;
}
V_127 -> V_131 = 0 ;
V_127 -> V_123 = V_35 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , void * V_2 ,
struct V_124 * V_125 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_126 * V_127 ;
unsigned int V_59 ;
int V_36 ;
V_36 = 0 ;
for ( V_59 = 0 ; V_59 < V_125 -> V_128 ; V_59 ++ ) {
V_127 = V_125 -> V_129 + V_59 ;
V_36 = F_13 (
F_42 ( V_9 , V_127 -> V_106 ) ,
V_127 -> V_123 ) ;
if ( V_36 ) {
V_125 -> V_130 = V_59 ;
return V_36 ;
}
}
return 0 ;
}
static int F_54 ( struct V_1 * V_1 , void * V_2 ,
struct V_124 * V_125 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_126 * V_127 ;
struct V_41 * V_132 ;
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_125 -> V_128 ; V_59 ++ ) {
V_127 = V_125 -> V_129 + V_59 ;
V_132 = F_42 ( V_9 , V_127 -> V_106 ) ;
if ( ! V_132 ) {
V_125 -> V_130 = V_59 ;
return - V_48 ;
}
}
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , void * V_2 , struct V_133 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_36 ;
if ( V_4 -> type != V_134 )
return - V_48 ;
V_36 = F_56 ( V_9 , V_4 ) ;
V_4 -> type = V_134 ;
return V_36 ;
}
static int F_57 ( struct V_1 * V_1 , void * V_2 , struct V_135 * V_136 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_35 = 0 ;
int V_36 ;
if ( V_136 -> type != V_134 )
return - V_48 ;
V_36 = F_10 (
F_11 ( V_9 , V_137 ) , & V_35 ) ;
if ( V_36 != 0 )
return - V_48 ;
V_136 -> V_138 . V_139 = V_35 ;
V_36 = F_10 (
F_11 ( V_9 , V_140 ) , & V_35 ) ;
if ( V_36 != 0 )
return - V_48 ;
V_136 -> V_138 . V_141 = V_35 ;
V_36 = F_10 (
F_11 ( V_9 , V_142 ) , & V_35 ) ;
if ( V_36 != 0 )
return - V_48 ;
V_136 -> V_138 . V_89 = V_35 ;
V_36 = F_10 (
F_11 ( V_9 , V_143 ) , & V_35 ) ;
if ( V_36 != 0 )
return - V_48 ;
V_136 -> V_138 . V_91 = V_35 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_1 , void * V_2 , const struct V_135 * V_136 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_36 ;
if ( V_136 -> type != V_134 )
return - V_48 ;
V_36 = F_13 (
F_11 ( V_9 , V_137 ) ,
V_136 -> V_138 . V_139 ) ;
if ( V_36 != 0 )
return - V_48 ;
V_36 = F_13 (
F_11 ( V_9 , V_140 ) ,
V_136 -> V_138 . V_141 ) ;
if ( V_36 != 0 )
return - V_48 ;
V_36 = F_13 (
F_11 ( V_9 , V_142 ) ,
V_136 -> V_138 . V_89 ) ;
if ( V_36 != 0 )
return - V_48 ;
V_36 = F_13 (
F_11 ( V_9 , V_143 ) ,
V_136 -> V_138 . V_91 ) ;
if ( V_36 != 0 )
return - V_48 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_1 , void * V_2 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
F_60 ( V_9 ) ;
return 0 ;
}
static void F_61 ( struct V_100 * V_144 )
{
struct V_8 * V_9 = V_144 -> V_145 -> V_10 . V_11 -> V_9 ;
enum V_146 V_147 = V_144 -> V_103 ;
char V_148 [ 80 ] ;
unsigned int V_149 ;
V_149 = F_62 ( V_148 , sizeof( V_148 ) - 1 ,
L_6 ,
F_63 ( & V_144 -> V_23 ) ,
F_64 ( V_147 ) ) ;
V_148 [ V_149 ] = 0 ;
F_65 ( V_9 , V_144 -> V_150 , - 1 ) ;
V_144 -> V_145 = NULL ;
V_144 -> V_101 = NULL ;
F_66 ( & V_144 -> V_23 ) ;
F_67 ( V_151 L_7 , V_148 ) ;
}
static void F_68 ( struct V_100 * V_144 )
{
if ( ! V_144 ) return;
if ( ! V_144 -> V_23 . V_152 -> V_153 ) return;
V_144 -> V_23 . V_152 -> V_153 = NULL ;
F_69 ( & V_144 -> V_23 . V_153 , NULL , V_154 ) ;
}
static void F_70 ( struct V_30 * V_31 )
{
if ( V_31 -> V_155 ) {
F_61 ( V_31 -> V_155 ) ;
V_31 -> V_155 = NULL ;
}
if ( V_31 -> V_156 ) {
F_61 ( V_31 -> V_156 ) ;
V_31 -> V_156 = NULL ;
}
F_43 ( V_157 , L_8 , V_31 ) ;
F_71 ( & V_31 -> V_10 ) ;
F_72 ( V_31 ) ;
}
static void F_73 ( struct V_158 * V_159 )
{
struct V_100 * V_153 ;
V_153 = F_74 ( V_159 , struct V_100 , V_23 ) ;
F_72 ( V_153 ) ;
}
static void F_75 ( struct V_160 * V_161 )
{
struct V_30 * V_31 ;
V_31 = F_74 ( V_161 , struct V_30 , V_10 ) ;
if ( ! V_31 -> V_10 . V_11 -> V_162 ) return;
F_68 ( V_31 -> V_155 ) ;
F_68 ( V_31 -> V_156 ) ;
if ( V_31 -> V_163 ) return;
F_70 ( V_31 ) ;
}
static long F_76 ( struct V_1 * V_1 ,
unsigned int V_164 , unsigned long V_165 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_30 * V_31 = V_6 -> V_32 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
long V_36 = - V_48 ;
if ( V_166 & V_108 )
F_77 ( F_78 ( V_9 ) , V_164 ) ;
if ( ! F_79 ( V_9 ) ) {
F_43 ( V_167 ,
L_9 ) ;
return - V_168 ;
}
switch ( V_164 ) {
case V_169 :
case V_170 :
case V_171 :
case V_172 :
case V_173 :
V_36 = F_80 ( & V_31 -> V_33 , V_6 -> V_33 ) ;
if ( V_36 )
return V_36 ;
}
V_36 = F_81 ( V_1 , V_164 , V_165 ) ;
F_82 ( V_9 ) ;
if ( V_36 < 0 ) {
if ( V_166 & V_108 ) {
F_43 ( V_108 ,
L_10
L_11 , V_36 ) ;
F_77 ( F_78 ( V_9 ) , V_164 ) ;
}
} else {
F_43 ( V_108 ,
L_12 ,
V_36 , V_36 ) ;
}
return V_36 ;
}
static int F_83 ( struct V_1 * V_1 )
{
struct V_5 * V_174 = V_1 -> V_7 ;
struct V_30 * V_31 = V_174 -> V_32 ;
struct V_8 * V_9 = V_174 -> V_10 . V_11 -> V_9 ;
F_43 ( V_175 , L_13 ) ;
if ( V_174 -> V_176 ) {
struct V_177 * V_178 ;
F_37 ( V_9 , 0 ) ;
V_178 = F_84 ( V_174 -> V_176 ) ;
if ( V_178 ) F_85 ( V_178 , NULL , NULL ) ;
F_86 ( V_174 -> V_176 ) ;
V_174 -> V_176 = NULL ;
}
F_87 ( & V_31 -> V_33 , V_174 -> V_33 ) ;
V_1 -> V_7 = NULL ;
if ( V_174 -> V_179 ) {
V_174 -> V_179 -> V_180 = V_174 -> V_180 ;
} else {
V_31 -> V_181 = V_174 -> V_180 ;
}
if ( V_174 -> V_180 ) {
V_174 -> V_180 -> V_179 = V_174 -> V_179 ;
} else {
V_31 -> V_163 = V_174 -> V_179 ;
}
V_174 -> V_179 = NULL ;
V_174 -> V_180 = NULL ;
V_174 -> V_32 = NULL ;
F_71 ( & V_174 -> V_10 ) ;
F_43 ( V_157 ,
L_14 , V_174 ) ;
if ( V_174 -> V_49 ) {
F_72 ( V_174 -> V_49 ) ;
V_174 -> V_49 = NULL ;
}
F_72 ( V_174 ) ;
if ( V_31 -> V_10 . V_11 -> V_162 && ! V_31 -> V_163 ) {
F_70 ( V_31 ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_1 )
{
struct V_100 * V_144 ;
struct V_5 * V_174 ;
struct V_30 * V_31 ;
struct V_8 * V_9 ;
unsigned int V_182 = 0 ;
unsigned int V_47 , V_59 ;
int V_36 = 0 ;
V_144 = F_74 ( F_89 ( V_1 ) , struct V_100 , V_23 ) ;
V_31 = V_144 -> V_145 ;
V_9 = V_31 -> V_10 . V_9 ;
F_43 ( V_175 , L_15 ) ;
if ( ! F_79 ( V_9 ) ) {
F_43 ( V_175 ,
L_16 ) ;
return - V_183 ;
}
V_174 = F_90 ( sizeof( * V_174 ) , V_184 ) ;
if ( ! V_174 ) {
return - V_185 ;
}
F_91 ( & V_174 -> V_186 ) ;
V_174 -> V_22 = V_144 ;
F_43 ( V_157 , L_17 , V_174 ) ;
F_92 ( & V_174 -> V_10 , V_31 -> V_10 . V_11 ) ;
if ( V_144 -> V_187 == V_27 ) {
V_182 = ( 1 << V_52 ) ;
} else {
V_182 = ( ( 1 << V_52 ) |
( 1 << V_50 ) |
( 1 << V_55 ) |
( 1 << V_54 ) ) ;
}
V_36 = F_93 ( & V_174 -> V_10 , V_182 ) ;
if ( V_36 ) {
F_71 ( & V_174 -> V_10 ) ;
F_43 ( V_157 ,
L_18 ,
V_174 ) ;
F_72 ( V_174 ) ;
return V_36 ;
}
V_182 &= F_94 ( V_9 ) ;
V_47 = 0 ;
for ( V_59 = 0 ; V_59 < ( sizeof( V_182 ) << 3 ) ; V_59 ++ ) {
if ( V_182 & ( 1 << V_59 ) ) V_47 ++ ;
}
V_174 -> V_47 = V_47 ;
V_174 -> V_49 = F_90 ( V_47 , V_184 ) ;
if ( ! V_174 -> V_49 ) {
F_71 ( & V_174 -> V_10 ) ;
F_43 ( V_157 ,
L_19 ,
V_174 ) ;
F_72 ( V_174 ) ;
return - V_185 ;
}
V_47 = 0 ;
for ( V_59 = 0 ; V_59 < ( sizeof( V_182 ) << 3 ) ; V_59 ++ ) {
if ( ! ( V_182 & ( 1 << V_59 ) ) ) continue;
V_174 -> V_49 [ V_47 ++ ] = V_59 ;
}
V_174 -> V_179 = NULL ;
V_174 -> V_180 = V_31 -> V_181 ;
if ( V_31 -> V_181 ) {
V_31 -> V_181 -> V_179 = V_174 ;
} else {
V_31 -> V_163 = V_174 ;
}
V_31 -> V_181 = V_174 ;
V_174 -> V_32 = V_31 ;
V_174 -> V_1 = V_1 ;
V_1 -> V_7 = V_174 ;
F_95 ( & V_31 -> V_33 , & V_174 -> V_33 ) ;
V_174 -> V_188 = F_96 ( V_9 ) ;
return 0 ;
}
static void F_97 ( struct V_5 * V_174 )
{
F_98 ( & V_174 -> V_186 ) ;
}
static int F_99 ( struct V_5 * V_6 )
{
int V_36 ;
struct V_177 * V_178 ;
struct V_8 * V_9 ;
if ( V_6 -> V_176 ) return 0 ;
if ( ! V_6 -> V_22 -> V_101 ) {
return - V_102 ;
}
if ( ( V_36 = F_100 ( & V_6 -> V_10 ,
V_6 -> V_22 -> V_101 ) ) != 0 ) {
return V_36 ;
}
V_6 -> V_176 = F_101 ( V_6 -> V_22 -> V_101 ) ;
if ( ! V_6 -> V_176 ) {
F_100 ( & V_6 -> V_10 , NULL ) ;
return - V_185 ;
}
V_9 = V_6 -> V_10 . V_11 -> V_9 ;
V_178 = V_6 -> V_22 -> V_101 -> V_101 ;
F_85 ( V_178 , ( V_189 ) F_97 , V_6 ) ;
F_36 ( V_9 , V_6 -> V_22 -> V_103 ) ;
if ( ( V_36 = F_37 ( V_9 , ! 0 ) ) < 0 ) return V_36 ;
return F_102 ( V_6 -> V_176 , ! 0 ) ;
}
static T_2 F_103 ( struct V_1 * V_1 ,
char T_3 * V_190 , T_4 V_128 , T_5 * V_191 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_36 ;
if ( V_6 -> V_188 ) {
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
char * V_192 ;
int V_193 , V_194 ;
int V_195 = 0 ;
unsigned int V_196 = * V_191 ;
V_192 = F_104 ( V_197 , V_184 ) ;
if ( ! V_192 ) return - V_185 ;
while ( V_128 ) {
V_193 = V_128 ;
if ( V_193 > V_197 ) V_193 = V_197 ;
V_194 = F_105 ( V_9 , V_196 , V_192 , V_193 ) ;
if ( V_194 < 0 ) {
V_195 = V_194 ;
break;
}
if ( ! V_194 ) break;
if ( F_106 ( V_190 , V_192 , V_194 ) ) {
V_195 = - V_168 ;
break;
}
V_196 += V_194 ;
V_195 += V_194 ;
V_190 += V_194 ;
V_128 -= V_194 ;
* V_191 += V_194 ;
}
F_72 ( V_192 ) ;
return V_195 ;
}
if ( ! V_6 -> V_176 ) {
V_36 = F_99 ( V_6 ) ;
if ( V_36 ) {
return V_36 ;
}
}
for (; ; ) {
V_36 = F_107 ( V_6 -> V_176 , V_190 , V_128 ) ;
if ( V_36 >= 0 ) break;
if ( V_36 != - V_198 ) break;
if ( V_1 -> V_199 & V_200 ) break;
V_36 = F_108 (
V_6 -> V_186 ,
F_109 ( V_6 -> V_176 ) >= 0 ) ;
if ( V_36 < 0 ) break;
}
return V_36 ;
}
static unsigned int F_110 ( struct V_1 * V_1 , T_6 * V_201 )
{
unsigned int V_202 = 0 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_36 ;
if ( V_6 -> V_188 ) {
V_202 |= V_203 | V_204 ;
return V_202 ;
}
if ( ! V_6 -> V_176 ) {
V_36 = F_99 ( V_6 ) ;
if ( V_36 ) return V_205 ;
}
F_111 ( V_1 , & V_6 -> V_186 , V_201 ) ;
if ( F_109 ( V_6 -> V_176 ) >= 0 ) {
V_202 |= V_203 | V_204 ;
}
return V_202 ;
}
static void F_112 ( struct V_100 * V_144 ,
struct V_30 * V_31 ,
int V_187 )
{
int V_206 ;
int V_207 ;
struct V_8 * V_9 ;
int * V_208 = NULL ;
V_144 -> V_145 = V_31 ;
V_9 = V_31 -> V_10 . V_11 -> V_9 ;
V_144 -> V_187 = V_187 ;
switch ( V_187 ) {
case V_25 :
V_144 -> V_101 = & V_31 -> V_10 . V_11 -> V_209 ;
V_144 -> V_103 = V_210 ;
V_144 -> V_150 = V_211 ;
V_208 = V_212 ;
if ( ! V_144 -> V_101 ) {
F_113 ( V_213
L_20
L_21 ) ;
return;
}
break;
case V_214 :
V_144 -> V_103 = V_215 ;
V_144 -> V_150 = V_216 ;
V_208 = V_217 ;
break;
case V_27 :
V_144 -> V_101 = & V_31 -> V_10 . V_11 -> V_209 ;
V_144 -> V_103 = V_210 ;
V_144 -> V_150 = V_218 ;
V_208 = V_219 ;
break;
default:
F_113 ( V_213 L_22
L_23 ) ;
return;
}
V_144 -> V_23 = V_220 ;
V_144 -> V_23 . V_221 = F_73 ;
V_144 -> V_23 . V_222 = & V_223 ;
{
int V_35 ;
F_10 (
F_11 ( V_9 ,
V_224 ) , & V_35 ) ;
V_144 -> V_23 . V_225 = ( T_1 ) V_35 ;
}
V_206 = - 1 ;
V_207 = F_114 ( V_9 ) ;
if ( V_208 && ( V_207 >= 0 ) && ( V_207 < V_226 ) ) {
V_206 = V_208 [ V_207 ] ;
}
F_115 ( V_9 , & V_144 -> V_23 ) ;
if ( ( F_116 ( & V_144 -> V_23 ,
V_144 -> V_187 , V_206 ) < 0 ) &&
( F_116 ( & V_144 -> V_23 ,
V_144 -> V_187 , - 1 ) < 0 ) ) {
F_113 ( V_213
L_24 ) ;
}
F_67 ( V_151 L_25 ,
F_63 ( & V_144 -> V_23 ) ,
F_64 ( V_144 -> V_103 ) ) ;
F_65 ( V_9 ,
V_144 -> V_150 , V_144 -> V_23 . V_227 ) ;
}
struct V_30 * F_117 ( struct V_228 * V_229 )
{
struct V_30 * V_31 ;
V_31 = F_90 ( sizeof( * V_31 ) , V_184 ) ;
if ( ! V_31 ) return V_31 ;
F_92 ( & V_31 -> V_10 , V_229 ) ;
F_43 ( V_157 , L_26 , V_31 ) ;
V_31 -> V_10 . V_230 = F_75 ;
V_31 -> V_155 = F_90 ( sizeof( * V_31 -> V_155 ) , V_184 ) ;
if ( ! V_31 -> V_155 ) goto V_231;
F_112 ( V_31 -> V_155 , V_31 , V_25 ) ;
if ( F_94 ( V_31 -> V_10 . V_11 -> V_9 ) &
( 1 << V_52 ) ) {
V_31 -> V_156 = F_90 ( sizeof( * V_31 -> V_156 ) , V_184 ) ;
if ( ! V_31 -> V_156 ) goto V_231;
F_112 ( V_31 -> V_156 , V_31 , V_27 ) ;
}
return V_31 ;
V_231:
F_43 ( V_157 , L_27 , V_31 ) ;
F_70 ( V_31 ) ;
return NULL ;
}
