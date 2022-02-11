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
struct V_35 * V_36 ;
unsigned int V_53 ;
int V_29 ;
int V_30 ;
V_30 = 0 ;
for ( V_53 = 0 ; V_53 < V_119 -> V_122 ; V_53 ++ ) {
V_121 = V_119 -> V_123 + V_53 ;
V_36 = F_38 ( V_9 , V_121 -> V_100 ) ;
if ( V_36 ) {
if ( V_119 -> V_124 == V_125 )
F_29 ( V_36 , & V_29 ) ;
else
V_30 = F_6 ( V_36 , & V_29 ) ;
} else
V_30 = - V_42 ;
if ( V_30 ) {
V_119 -> V_126 = V_53 ;
return V_30 ;
}
V_121 -> V_127 = 0 ;
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
if ( V_119 -> V_124 == V_125 )
return - V_42 ;
V_30 = 0 ;
for ( V_53 = 0 ; V_53 < V_119 -> V_122 ; V_53 ++ ) {
V_121 = V_119 -> V_123 + V_53 ;
V_30 = F_9 (
F_38 ( V_9 , V_121 -> V_100 ) ,
V_121 -> V_117 ) ;
if ( V_30 ) {
V_119 -> V_126 = V_53 ;
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
struct V_35 * V_128 ;
unsigned int V_53 ;
for ( V_53 = 0 ; V_53 < V_119 -> V_122 ; V_53 ++ ) {
V_121 = V_119 -> V_123 + V_53 ;
V_128 = F_38 ( V_9 , V_121 -> V_100 ) ;
if ( ! V_128 ) {
V_119 -> V_126 = V_53 ;
return - V_42 ;
}
}
return 0 ;
}
static int F_51 ( struct V_1 * V_1 , void * V_2 , struct V_129 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_30 ;
if ( V_4 -> type != V_130 )
return - V_42 ;
V_30 = F_52 ( V_9 , V_4 ) ;
V_4 -> type = V_130 ;
return V_30 ;
}
static int F_53 ( struct V_1 * V_1 , void * V_2 ,
struct V_131 * V_132 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_129 V_4 ;
int V_29 = 0 ;
int V_30 ;
if ( V_132 -> type != V_130 )
return - V_42 ;
V_4 . type = V_130 ;
switch ( V_132 -> V_133 ) {
case V_134 :
V_30 = F_6 (
F_7 ( V_9 , V_135 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_132 -> V_136 . V_137 = V_29 ;
V_30 = F_6 (
F_7 ( V_9 , V_138 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_132 -> V_136 . V_139 = V_29 ;
V_30 = F_6 (
F_7 ( V_9 , V_140 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_132 -> V_136 . V_83 = V_29 ;
V_30 = F_6 (
F_7 ( V_9 , V_141 ) , & V_29 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_132 -> V_136 . V_85 = V_29 ;
break;
case V_142 :
V_30 = F_52 ( V_9 , & V_4 ) ;
V_132 -> V_136 = V_4 . V_143 ;
break;
case V_144 :
V_30 = F_52 ( V_9 , & V_4 ) ;
V_132 -> V_136 = V_4 . V_145 ;
break;
default:
return - V_42 ;
}
return V_30 ;
}
static int F_54 ( struct V_1 * V_1 , void * V_2 ,
struct V_131 * V_132 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_30 ;
if ( V_132 -> type != V_130 ||
V_132 -> V_133 != V_134 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_135 ) ,
V_132 -> V_136 . V_137 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_138 ) ,
V_132 -> V_136 . V_139 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_140 ) ,
V_132 -> V_136 . V_83 ) ;
if ( V_30 != 0 )
return - V_42 ;
V_30 = F_9 (
F_7 ( V_9 , V_141 ) ,
V_132 -> V_136 . V_85 ) ;
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
static void F_57 ( struct V_94 * V_146 )
{
struct V_8 * V_9 = V_146 -> V_147 -> V_10 . V_11 -> V_9 ;
enum V_148 V_149 = V_146 -> V_97 ;
char V_150 [ 80 ] ;
unsigned int V_151 ;
V_151 = F_58 ( V_150 , sizeof( V_150 ) - 1 ,
L_6 ,
F_59 ( & V_146 -> V_23 ) ,
F_60 ( V_149 ) ) ;
V_150 [ V_151 ] = 0 ;
F_61 ( V_9 , V_146 -> V_152 , - 1 ) ;
V_146 -> V_147 = NULL ;
V_146 -> V_95 = NULL ;
F_62 ( & V_146 -> V_23 ) ;
F_63 ( V_153 L_7 , V_150 ) ;
}
static void F_64 ( struct V_94 * V_146 )
{
if ( ! V_146 ) return;
if ( ! V_146 -> V_23 . V_154 -> V_155 ) return;
V_146 -> V_23 . V_154 -> V_155 = NULL ;
F_65 ( & V_146 -> V_23 . V_155 , NULL , V_156 ) ;
}
static void F_66 ( struct V_157 * V_158 )
{
if ( V_158 -> V_159 ) {
F_57 ( V_158 -> V_159 ) ;
V_158 -> V_159 = NULL ;
}
if ( V_158 -> V_160 ) {
F_57 ( V_158 -> V_160 ) ;
V_158 -> V_160 = NULL ;
}
F_39 ( V_161 , L_8 , V_158 ) ;
F_67 ( & V_158 -> V_10 ) ;
F_68 ( V_158 ) ;
}
static void F_69 ( struct V_162 * V_163 )
{
struct V_94 * V_155 ;
V_155 = F_70 ( V_163 , struct V_94 , V_23 ) ;
F_68 ( V_155 ) ;
}
static void F_71 ( struct V_164 * V_165 )
{
struct V_157 * V_158 ;
V_158 = F_70 ( V_165 , struct V_157 , V_10 ) ;
if ( ! V_158 -> V_10 . V_11 -> V_166 ) return;
F_64 ( V_158 -> V_159 ) ;
F_64 ( V_158 -> V_160 ) ;
if ( ! F_72 ( & V_158 -> V_159 -> V_23 . V_167 ) ||
! F_72 ( & V_158 -> V_160 -> V_23 . V_167 ) )
return;
F_66 ( V_158 ) ;
}
static long F_73 ( struct V_1 * V_1 ,
unsigned int V_168 , unsigned long V_169 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
long V_30 = - V_42 ;
if ( V_170 & V_102 )
F_74 ( F_75 ( V_9 ) , V_168 ) ;
if ( ! F_76 ( V_9 ) ) {
F_39 ( V_171 ,
L_9 ) ;
return - V_172 ;
}
V_30 = F_77 ( V_1 , V_168 , V_169 ) ;
F_78 ( V_9 ) ;
if ( V_30 < 0 ) {
if ( V_170 & V_102 ) {
F_39 ( V_102 ,
L_10
L_11 , V_30 ) ;
F_74 ( F_75 ( V_9 ) , V_168 ) ;
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
struct V_5 * V_173 = V_1 -> V_7 ;
struct V_157 * V_158 = V_173 -> V_22 -> V_147 ;
struct V_8 * V_9 = V_173 -> V_10 . V_11 -> V_9 ;
F_39 ( V_174 , L_13 ) ;
if ( V_173 -> V_175 ) {
struct V_176 * V_177 ;
F_33 ( V_9 , 0 ) ;
V_177 = F_80 ( V_173 -> V_175 ) ;
if ( V_177 ) F_81 ( V_177 , NULL , NULL ) ;
F_82 ( V_173 -> V_175 ) ;
V_173 -> V_175 = NULL ;
}
F_83 ( & V_173 -> V_6 ) ;
F_84 ( & V_173 -> V_6 ) ;
V_1 -> V_7 = NULL ;
F_67 ( & V_173 -> V_10 ) ;
F_39 ( V_161 ,
L_14 , V_173 ) ;
if ( V_173 -> V_43 ) {
F_68 ( V_173 -> V_43 ) ;
V_173 -> V_43 = NULL ;
}
F_68 ( V_173 ) ;
if ( V_158 -> V_10 . V_11 -> V_166 &&
F_72 ( & V_158 -> V_159 -> V_23 . V_167 ) &&
F_72 ( & V_158 -> V_160 -> V_23 . V_167 ) ) {
F_66 ( V_158 ) ;
}
return 0 ;
}
static int F_85 ( struct V_1 * V_1 )
{
struct V_94 * V_146 ;
struct V_5 * V_173 ;
struct V_157 * V_158 ;
struct V_8 * V_9 ;
unsigned int V_178 = 0 ;
unsigned int V_41 , V_53 ;
int V_30 = 0 ;
V_146 = F_70 ( F_86 ( V_1 ) , struct V_94 , V_23 ) ;
V_158 = V_146 -> V_147 ;
V_9 = V_158 -> V_10 . V_9 ;
F_39 ( V_174 , L_15 ) ;
if ( ! F_76 ( V_9 ) ) {
F_39 ( V_174 ,
L_16 ) ;
return - V_179 ;
}
V_173 = F_87 ( sizeof( * V_173 ) , V_180 ) ;
if ( ! V_173 ) {
return - V_181 ;
}
F_88 ( & V_173 -> V_6 , & V_146 -> V_23 ) ;
F_89 ( & V_173 -> V_182 ) ;
V_173 -> V_22 = V_146 ;
F_39 ( V_161 , L_17 , V_173 ) ;
F_90 ( & V_173 -> V_10 , V_158 -> V_10 . V_11 ) ;
if ( V_146 -> V_183 == V_27 ) {
V_178 = ( 1 << V_46 ) ;
} else {
V_178 = ( ( 1 << V_46 ) |
( 1 << V_44 ) |
( 1 << V_49 ) |
( 1 << V_48 ) ) ;
}
V_30 = F_91 ( & V_173 -> V_10 , V_178 ) ;
if ( V_30 ) {
F_67 ( & V_173 -> V_10 ) ;
F_39 ( V_161 ,
L_18 ,
V_173 ) ;
F_68 ( V_173 ) ;
return V_30 ;
}
V_178 &= F_92 ( V_9 ) ;
V_41 = 0 ;
for ( V_53 = 0 ; V_53 < ( sizeof( V_178 ) << 3 ) ; V_53 ++ ) {
if ( V_178 & ( 1 << V_53 ) ) V_41 ++ ;
}
V_173 -> V_41 = V_41 ;
V_173 -> V_43 = F_87 ( V_41 , V_180 ) ;
if ( ! V_173 -> V_43 ) {
F_67 ( & V_173 -> V_10 ) ;
F_39 ( V_161 ,
L_19 ,
V_173 ) ;
F_68 ( V_173 ) ;
return - V_181 ;
}
V_41 = 0 ;
for ( V_53 = 0 ; V_53 < ( sizeof( V_178 ) << 3 ) ; V_53 ++ ) {
if ( ! ( V_178 & ( 1 << V_53 ) ) ) continue;
V_173 -> V_43 [ V_41 ++ ] = V_53 ;
}
V_173 -> V_1 = V_1 ;
V_1 -> V_7 = V_173 ;
V_173 -> V_184 = F_93 ( V_9 ) ;
F_94 ( & V_173 -> V_6 ) ;
return 0 ;
}
static void F_95 ( struct V_5 * V_173 )
{
F_96 ( & V_173 -> V_182 ) ;
}
static int F_97 ( struct V_5 * V_6 )
{
int V_30 ;
struct V_176 * V_177 ;
struct V_8 * V_9 ;
if ( V_6 -> V_175 ) return 0 ;
if ( ! V_6 -> V_22 -> V_95 ) {
return - V_96 ;
}
if ( ( V_30 = F_98 ( & V_6 -> V_10 ,
V_6 -> V_22 -> V_95 ) ) != 0 ) {
return V_30 ;
}
V_6 -> V_175 = F_99 ( V_6 -> V_22 -> V_95 ) ;
if ( ! V_6 -> V_175 ) {
F_98 ( & V_6 -> V_10 , NULL ) ;
return - V_181 ;
}
V_9 = V_6 -> V_10 . V_11 -> V_9 ;
V_177 = V_6 -> V_22 -> V_95 -> V_95 ;
F_81 ( V_177 , ( V_185 ) F_95 , V_6 ) ;
F_32 ( V_9 , V_6 -> V_22 -> V_97 ) ;
if ( ( V_30 = F_33 ( V_9 , ! 0 ) ) < 0 ) return V_30 ;
return F_100 ( V_6 -> V_175 , ! 0 ) ;
}
static T_2 F_101 ( struct V_1 * V_1 ,
char T_3 * V_186 , T_4 V_122 , T_5 * V_187 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_30 ;
if ( V_6 -> V_184 ) {
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
char * V_188 ;
int V_189 , V_190 ;
int V_191 = 0 ;
unsigned int V_192 = * V_187 ;
V_188 = F_102 ( V_193 , V_180 ) ;
if ( ! V_188 ) return - V_181 ;
while ( V_122 ) {
V_189 = V_122 ;
if ( V_189 > V_193 ) V_189 = V_193 ;
V_190 = F_103 ( V_9 , V_192 , V_188 , V_189 ) ;
if ( V_190 < 0 ) {
V_191 = V_190 ;
break;
}
if ( ! V_190 ) break;
if ( F_104 ( V_186 , V_188 , V_190 ) ) {
V_191 = - V_172 ;
break;
}
V_192 += V_190 ;
V_191 += V_190 ;
V_186 += V_190 ;
V_122 -= V_190 ;
* V_187 += V_190 ;
}
F_68 ( V_188 ) ;
return V_191 ;
}
if ( ! V_6 -> V_175 ) {
V_30 = F_97 ( V_6 ) ;
if ( V_30 ) {
return V_30 ;
}
}
for (; ; ) {
V_30 = F_105 ( V_6 -> V_175 , V_186 , V_122 ) ;
if ( V_30 >= 0 ) break;
if ( V_30 != - V_194 ) break;
if ( V_1 -> V_195 & V_196 ) break;
V_30 = F_106 (
V_6 -> V_182 ,
F_107 ( V_6 -> V_175 ) >= 0 ) ;
if ( V_30 < 0 ) break;
}
return V_30 ;
}
static unsigned int F_108 ( struct V_1 * V_1 , T_6 * V_197 )
{
unsigned int V_198 = 0 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_30 ;
if ( V_6 -> V_184 ) {
V_198 |= V_199 | V_200 ;
return V_198 ;
}
if ( ! V_6 -> V_175 ) {
V_30 = F_97 ( V_6 ) ;
if ( V_30 ) return V_201 ;
}
F_109 ( V_1 , & V_6 -> V_182 , V_197 ) ;
if ( F_107 ( V_6 -> V_175 ) >= 0 ) {
V_198 |= V_199 | V_200 ;
}
return V_198 ;
}
static void F_110 ( struct V_94 * V_146 ,
struct V_157 * V_158 ,
int V_183 )
{
int V_202 ;
int V_203 ;
struct V_8 * V_9 ;
int * V_204 = NULL ;
V_146 -> V_147 = V_158 ;
V_9 = V_158 -> V_10 . V_11 -> V_9 ;
V_146 -> V_183 = V_183 ;
switch ( V_183 ) {
case V_25 :
V_146 -> V_95 = & V_158 -> V_10 . V_11 -> V_205 ;
V_146 -> V_97 = V_206 ;
V_146 -> V_152 = V_207 ;
V_204 = V_208 ;
if ( ! V_146 -> V_95 ) {
F_111 ( V_209
L_20
L_21 ) ;
return;
}
break;
case V_210 :
V_146 -> V_97 = V_211 ;
V_146 -> V_152 = V_212 ;
V_204 = V_213 ;
break;
case V_27 :
V_146 -> V_95 = & V_158 -> V_10 . V_11 -> V_205 ;
V_146 -> V_97 = V_206 ;
V_146 -> V_152 = V_214 ;
V_204 = V_215 ;
break;
default:
F_111 ( V_209 L_22
L_23 ) ;
return;
}
V_146 -> V_23 = V_216 ;
V_146 -> V_23 . V_217 = F_69 ;
V_146 -> V_23 . V_218 = & V_219 ;
{
int V_29 ;
F_6 (
F_7 ( V_9 ,
V_220 ) , & V_29 ) ;
V_146 -> V_23 . V_221 = ( T_1 ) V_29 ;
}
V_202 = - 1 ;
V_203 = F_112 ( V_9 ) ;
if ( V_204 && ( V_203 >= 0 ) && ( V_203 < V_222 ) ) {
V_202 = V_204 [ V_203 ] ;
}
F_113 ( V_9 , & V_146 -> V_23 ) ;
if ( ( F_114 ( & V_146 -> V_23 ,
V_146 -> V_183 , V_202 ) < 0 ) &&
( F_114 ( & V_146 -> V_23 ,
V_146 -> V_183 , - 1 ) < 0 ) ) {
F_111 ( V_209
L_24 ) ;
}
F_63 ( V_153 L_25 ,
F_59 ( & V_146 -> V_23 ) ,
F_60 ( V_146 -> V_97 ) ) ;
F_61 ( V_9 ,
V_146 -> V_152 , V_146 -> V_23 . V_223 ) ;
}
struct V_157 * F_115 ( struct V_224 * V_225 )
{
struct V_157 * V_158 ;
V_158 = F_87 ( sizeof( * V_158 ) , V_180 ) ;
if ( ! V_158 ) return V_158 ;
F_90 ( & V_158 -> V_10 , V_225 ) ;
F_39 ( V_161 , L_26 , V_158 ) ;
V_158 -> V_10 . V_226 = F_71 ;
V_158 -> V_159 = F_87 ( sizeof( * V_158 -> V_159 ) , V_180 ) ;
if ( ! V_158 -> V_159 ) goto V_227;
F_110 ( V_158 -> V_159 , V_158 , V_25 ) ;
if ( F_92 ( V_158 -> V_10 . V_11 -> V_9 ) &
( 1 << V_46 ) ) {
V_158 -> V_160 = F_87 ( sizeof( * V_158 -> V_160 ) , V_180 ) ;
if ( ! V_158 -> V_160 ) goto V_227;
F_110 ( V_158 -> V_160 , V_158 , V_27 ) ;
}
return V_158 ;
V_227:
F_39 ( V_161 , L_27 , V_158 ) ;
F_66 ( V_158 ) ;
return NULL ;
}
