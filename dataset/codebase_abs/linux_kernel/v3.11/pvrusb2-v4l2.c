static int F_1 ( struct V_1 * V_1 , void * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
memcpy ( V_4 , & V_12 , sizeof( struct V_3 ) ) ;
F_2 ( V_4 -> V_13 , F_3 ( V_9 ) ,
sizeof( V_4 -> V_13 ) ) ;
F_2 ( V_4 -> V_14 , F_4 ( V_9 ) , sizeof( V_4 -> V_14 ) ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 , void * V_2 , enum V_15 * V_16 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_17 * V_18 = V_6 -> V_19 ;
* V_16 = F_6 ( & V_18 -> V_20 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , void * V_2 , enum V_15 V_20 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_17 * V_18 = V_6 -> V_19 ;
return F_8 ( & V_18 -> V_20 , & V_6 -> V_20 , V_20 ) ;
}
static int F_9 ( struct V_1 * V_1 , void * V_2 , T_1 * V_21 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_22 = 0 ;
int V_23 ;
V_23 = F_10 (
F_11 ( V_9 , V_24 ) , & V_22 ) ;
* V_21 = V_22 ;
return V_23 ;
}
static int F_12 ( struct V_1 * V_1 , void * V_2 , T_1 V_21 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
return F_13 (
F_11 ( V_9 , V_24 ) , V_21 ) ;
}
static int F_14 ( struct V_1 * V_1 , void * V_2 , T_1 * V_21 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_22 = 0 ;
int V_23 ;
V_23 = F_10 (
F_11 ( V_9 , V_25 ) , & V_22 ) ;
* V_21 = V_22 ;
return V_23 ;
}
static int F_15 ( struct V_1 * V_1 , void * V_2 , struct V_26 * V_27 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_28 * V_29 ;
struct V_26 V_30 ;
unsigned int V_31 ;
int V_22 ;
V_29 = F_11 ( V_9 , V_32 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_33 = V_27 -> V_33 ;
if ( V_27 -> V_33 >= V_6 -> V_34 )
return - V_35 ;
V_22 = V_6 -> V_36 [ V_27 -> V_33 ] ;
switch ( V_22 ) {
case V_37 :
case V_38 :
case V_39 :
V_30 . type = V_40 ;
break;
case V_41 :
case V_42 :
V_30 . type = V_43 ;
break;
default:
return - V_35 ;
}
V_31 = 0 ;
F_16 ( V_29 , V_22 ,
V_30 . V_44 , sizeof( V_30 . V_44 ) - 1 , & V_31 ) ;
V_30 . V_44 [ V_31 ] = 0 ;
* V_27 = V_30 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_1 , void * V_2 , unsigned int * V_45 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned int V_46 ;
struct V_28 * V_29 ;
int V_22 ;
int V_23 ;
V_29 = F_11 ( V_9 , V_32 ) ;
V_22 = 0 ;
V_23 = F_10 ( V_29 , & V_22 ) ;
* V_45 = 0 ;
for ( V_46 = 0 ; V_46 < V_6 -> V_34 ; V_46 ++ ) {
if ( V_6 -> V_36 [ V_46 ] == V_22 ) {
* V_45 = V_46 ;
break;
}
}
return V_23 ;
}
static int F_18 ( struct V_1 * V_1 , void * V_2 , unsigned int V_47 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_47 >= V_6 -> V_34 )
return - V_35 ;
return F_13 (
F_11 ( V_9 , V_32 ) ,
V_6 -> V_36 [ V_47 ] ) ;
}
static int F_19 ( struct V_1 * V_1 , void * V_2 , struct V_48 * V_49 )
{
if ( V_49 -> V_33 > 0 )
return - V_35 ;
strncpy ( V_49 -> V_44 , L_1 , 14 ) ;
V_49 -> V_50 = V_51 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , void * V_2 , struct V_48 * V_49 )
{
V_49 -> V_33 = 0 ;
strncpy ( V_49 -> V_44 , L_1 , 14 ) ;
V_49 -> V_50 = V_51 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 , void * V_2 , const struct V_48 * V_52 )
{
if ( V_52 -> V_33 )
return - V_35 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_1 , void * V_2 , struct V_53 * V_54 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_54 -> V_33 != 0 )
return - V_35 ;
F_23 ( V_9 ) ;
return F_24 ( V_9 , V_54 ) ;
}
static int F_25 ( struct V_1 * V_1 , void * V_2 , const struct V_53 * V_54 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( V_54 -> V_33 != 0 )
return - V_35 ;
return F_13 (
F_11 ( V_9 , V_55 ) ,
V_54 -> V_56 ) ;
}
static int F_26 ( struct V_1 * V_1 , void * V_2 , const struct V_57 * V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned long V_59 ;
struct V_53 V_54 ;
int V_60 ;
struct V_28 * V_61 ;
int V_23 ;
V_23 = F_24 ( V_9 , & V_54 ) ;
if ( V_23 != 0 )
return V_23 ;
V_61 = F_11 ( V_9 , V_32 ) ;
V_23 = F_10 ( V_61 , & V_60 ) ;
if ( V_23 != 0 )
return V_23 ;
if ( V_58 -> type == V_62 ) {
if ( V_60 != V_39 )
F_13 ( V_61 , V_39 ) ;
} else {
if ( V_60 == V_39 )
F_13 ( V_61 , V_37 ) ;
}
V_59 = V_58 -> V_63 ;
if ( V_54 . V_50 & V_64 )
V_59 = ( V_59 * 125 ) / 2 ;
else
V_59 = V_59 * 62500 ;
return F_13 (
F_11 ( V_9 , V_65 ) , V_59 ) ;
}
static int F_27 ( struct V_1 * V_1 , void * V_2 , struct V_57 * V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_22 = 0 ;
int V_60 ;
struct V_53 V_54 ;
int V_23 ;
V_23 = F_24 ( V_9 , & V_54 ) ;
if ( V_23 != 0 )
return V_23 ;
V_23 = F_10 (
F_11 ( V_9 , V_65 ) ,
& V_22 ) ;
if ( V_23 != 0 )
return V_23 ;
F_10 (
F_11 ( V_9 , V_32 ) ,
& V_60 ) ;
if ( V_60 == V_39 )
V_58 -> type = V_62 ;
else
V_58 -> type = V_66 ;
if ( V_54 . V_50 & V_64 )
V_22 = ( V_22 * 2 ) / 125 ;
else
V_22 /= 62500 ;
V_58 -> V_63 = V_22 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , void * V_2 , struct V_67 * V_68 )
{
if ( V_68 -> V_33 != 0 )
return - V_35 ;
memcpy ( V_68 , V_69 , sizeof( struct V_67 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , void * V_2 , struct V_70 * V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_22 ;
memcpy ( V_58 , & V_71 [ V_72 ] , sizeof( struct V_70 ) ) ;
V_22 = 0 ;
F_10 (
F_11 ( V_9 , V_73 ) ,
& V_22 ) ;
V_58 -> V_74 . V_75 . V_76 = V_22 ;
V_22 = 0 ;
F_10 (
F_11 ( V_9 , V_77 ) ,
& V_22 ) ;
V_58 -> V_74 . V_75 . V_78 = V_22 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , void * V_2 , struct V_70 * V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_79 , V_80 , V_81 ;
struct V_28 * V_82 , * V_83 ;
int V_84 = V_58 -> V_74 . V_75 . V_78 ;
int V_85 = V_58 -> V_74 . V_75 . V_76 ;
V_82 = F_11 ( V_9 , V_73 ) ;
V_83 = F_11 ( V_9 , V_77 ) ;
V_79 = F_31 ( V_82 ) ;
V_80 = F_32 ( V_82 ) ;
F_33 ( V_82 , & V_81 ) ;
if ( V_85 == - 1 )
V_85 = V_81 ;
else if ( V_85 < V_79 )
V_85 = V_79 ;
else if ( V_85 > V_80 )
V_85 = V_80 ;
V_79 = F_31 ( V_83 ) ;
V_80 = F_32 ( V_83 ) ;
F_33 ( V_83 , & V_81 ) ;
if ( V_84 == - 1 )
V_84 = V_81 ;
else if ( V_84 < V_79 )
V_84 = V_79 ;
else if ( V_84 > V_80 )
V_84 = V_80 ;
memcpy ( V_58 , & V_71 [ V_72 ] ,
sizeof( struct V_70 ) ) ;
V_58 -> V_74 . V_75 . V_76 = V_85 ;
V_58 -> V_74 . V_75 . V_78 = V_84 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , void * V_2 , struct V_70 * V_58 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_28 * V_82 , * V_83 ;
int V_23 = F_30 ( V_1 , V_6 , V_58 ) ;
if ( V_23 )
return V_23 ;
V_82 = F_11 ( V_9 , V_73 ) ;
V_83 = F_11 ( V_9 , V_77 ) ;
F_13 ( V_82 , V_58 -> V_74 . V_75 . V_76 ) ;
F_13 ( V_83 , V_58 -> V_74 . V_75 . V_78 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , void * V_2 , enum V_86 V_45 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_87 * V_88 = V_6 -> V_88 ;
int V_23 ;
if ( ! V_6 -> V_88 -> V_89 ) {
return - V_90 ;
}
V_23 = F_36 ( V_9 , V_88 -> V_91 ) ;
if ( V_23 < 0 )
return V_23 ;
return F_37 ( V_9 , ! 0 ) ;
}
static int F_38 ( struct V_1 * V_1 , void * V_2 , enum V_86 V_45 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
if ( ! V_6 -> V_88 -> V_89 ) {
return - V_90 ;
}
return F_37 ( V_9 , 0 ) ;
}
static int F_39 ( struct V_1 * V_1 , void * V_2 ,
struct V_92 * V_93 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_28 * V_29 ;
int V_22 ;
if ( V_93 -> V_94 & V_95 ) {
V_29 = F_40 (
V_9 , ( V_93 -> V_94 & ~ V_95 ) ) ;
if ( V_29 )
V_93 -> V_94 = F_41 ( V_29 ) ;
} else {
V_29 = F_42 ( V_9 , V_93 -> V_94 ) ;
}
if ( ! V_29 ) {
F_43 ( V_96 ,
L_2 ,
V_93 -> V_94 ) ;
return - V_35 ;
}
F_43 ( V_96 ,
L_3 ,
V_93 -> V_94 , F_44 ( V_29 ) ,
F_45 ( V_29 ) ) ;
F_2 ( V_93 -> V_44 , F_45 ( V_29 ) , sizeof( V_93 -> V_44 ) ) ;
V_93 -> V_97 = F_46 ( V_29 ) ;
F_33 ( V_29 , & V_22 ) ;
V_93 -> V_98 = V_22 ;
switch ( F_47 ( V_29 ) ) {
case V_99 :
V_93 -> type = V_100 ;
V_93 -> V_101 = 0 ;
V_93 -> V_102 = F_48 ( V_29 ) - 1 ;
V_93 -> V_103 = 1 ;
break;
case V_104 :
V_93 -> type = V_105 ;
V_93 -> V_101 = 0 ;
V_93 -> V_102 = 1 ;
V_93 -> V_103 = 1 ;
break;
case V_106 :
V_93 -> type = V_107 ;
V_93 -> V_101 = F_31 ( V_29 ) ;
V_93 -> V_102 = F_32 ( V_29 ) ;
V_93 -> V_103 = 1 ;
break;
default:
F_43 ( V_96 ,
L_4 ,
V_93 -> V_94 , F_44 ( V_29 ) ) ;
return - V_35 ;
}
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , void * V_2 , struct V_108 * V_109 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
unsigned int V_31 = 0 ;
int V_23 ;
V_23 = F_16 ( F_42 ( V_9 , V_109 -> V_94 ) ,
V_109 -> V_33 ,
V_109 -> V_44 , sizeof( V_109 -> V_44 ) - 1 ,
& V_31 ) ;
V_109 -> V_44 [ V_31 ] = 0 ;
return V_23 ;
}
static int F_50 ( struct V_1 * V_1 , void * V_2 , struct V_110 * V_93 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_22 = 0 ;
int V_23 ;
V_23 = F_10 ( F_42 ( V_9 , V_93 -> V_94 ) ,
& V_22 ) ;
V_93 -> V_111 = V_22 ;
return V_23 ;
}
static int F_51 ( struct V_1 * V_1 , void * V_2 , struct V_110 * V_93 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
return F_13 ( F_42 ( V_9 , V_93 -> V_94 ) ,
V_93 -> V_111 ) ;
}
static int F_52 ( struct V_1 * V_1 , void * V_2 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_114 * V_115 ;
unsigned int V_46 ;
int V_22 ;
int V_23 ;
V_23 = 0 ;
for ( V_46 = 0 ; V_46 < V_113 -> V_116 ; V_46 ++ ) {
V_115 = V_113 -> V_117 + V_46 ;
V_23 = F_10 (
F_42 ( V_9 , V_115 -> V_94 ) , & V_22 ) ;
if ( V_23 ) {
V_113 -> V_118 = V_46 ;
return V_23 ;
}
V_115 -> V_119 = 0 ;
V_115 -> V_111 = V_22 ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_1 , void * V_2 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_114 * V_115 ;
unsigned int V_46 ;
int V_23 ;
V_23 = 0 ;
for ( V_46 = 0 ; V_46 < V_113 -> V_116 ; V_46 ++ ) {
V_115 = V_113 -> V_117 + V_46 ;
V_23 = F_13 (
F_42 ( V_9 , V_115 -> V_94 ) ,
V_115 -> V_111 ) ;
if ( V_23 ) {
V_113 -> V_118 = V_46 ;
return V_23 ;
}
}
return 0 ;
}
static int F_54 ( struct V_1 * V_1 , void * V_2 ,
struct V_112 * V_113 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
struct V_114 * V_115 ;
struct V_28 * V_120 ;
unsigned int V_46 ;
for ( V_46 = 0 ; V_46 < V_113 -> V_116 ; V_46 ++ ) {
V_115 = V_113 -> V_117 + V_46 ;
V_120 = F_42 ( V_9 , V_115 -> V_94 ) ;
if ( ! V_120 ) {
V_113 -> V_118 = V_46 ;
return - V_35 ;
}
}
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , void * V_2 , struct V_121 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_23 ;
if ( V_4 -> type != V_122 )
return - V_35 ;
V_23 = F_56 ( V_9 , V_4 ) ;
V_4 -> type = V_122 ;
return V_23 ;
}
static int F_57 ( struct V_1 * V_1 , void * V_2 , struct V_123 * V_124 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_22 = 0 ;
int V_23 ;
if ( V_124 -> type != V_122 )
return - V_35 ;
V_23 = F_10 (
F_11 ( V_9 , V_125 ) , & V_22 ) ;
if ( V_23 != 0 )
return - V_35 ;
V_124 -> V_126 . V_127 = V_22 ;
V_23 = F_10 (
F_11 ( V_9 , V_128 ) , & V_22 ) ;
if ( V_23 != 0 )
return - V_35 ;
V_124 -> V_126 . V_129 = V_22 ;
V_23 = F_10 (
F_11 ( V_9 , V_130 ) , & V_22 ) ;
if ( V_23 != 0 )
return - V_35 ;
V_124 -> V_126 . V_76 = V_22 ;
V_23 = F_10 (
F_11 ( V_9 , V_131 ) , & V_22 ) ;
if ( V_23 != 0 )
return - V_35 ;
V_124 -> V_126 . V_78 = V_22 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_1 , void * V_2 , const struct V_123 * V_124 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
int V_23 ;
if ( V_124 -> type != V_122 )
return - V_35 ;
V_23 = F_13 (
F_11 ( V_9 , V_125 ) ,
V_124 -> V_126 . V_127 ) ;
if ( V_23 != 0 )
return - V_35 ;
V_23 = F_13 (
F_11 ( V_9 , V_128 ) ,
V_124 -> V_126 . V_129 ) ;
if ( V_23 != 0 )
return - V_35 ;
V_23 = F_13 (
F_11 ( V_9 , V_130 ) ,
V_124 -> V_126 . V_76 ) ;
if ( V_23 != 0 )
return - V_35 ;
V_23 = F_13 (
F_11 ( V_9 , V_131 ) ,
V_124 -> V_126 . V_78 ) ;
if ( V_23 != 0 )
return - V_35 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_1 , void * V_2 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
F_60 ( V_9 ) ;
return 0 ;
}
static void F_61 ( struct V_87 * V_132 )
{
struct V_8 * V_9 = V_132 -> V_133 -> V_10 . V_11 -> V_9 ;
enum V_134 V_135 = V_132 -> V_91 ;
char V_136 [ 80 ] ;
unsigned int V_137 ;
V_137 = F_62 ( V_136 , sizeof( V_136 ) - 1 ,
L_5 ,
F_63 ( & V_132 -> V_138 ) ,
F_64 ( V_135 ) ) ;
V_136 [ V_137 ] = 0 ;
F_65 ( V_9 , V_132 -> V_139 , - 1 ) ;
V_132 -> V_133 = NULL ;
V_132 -> V_89 = NULL ;
F_66 ( & V_132 -> V_138 ) ;
F_67 ( V_140 L_6 , V_136 ) ;
}
static void F_68 ( struct V_87 * V_132 )
{
if ( ! V_132 ) return;
if ( ! V_132 -> V_138 . V_141 -> V_142 ) return;
V_132 -> V_138 . V_141 -> V_142 = NULL ;
F_69 ( & V_132 -> V_138 . V_142 , NULL , V_143 ) ;
}
static void F_70 ( struct V_17 * V_18 )
{
if ( V_18 -> V_144 ) {
F_61 ( V_18 -> V_144 ) ;
V_18 -> V_144 = NULL ;
}
if ( V_18 -> V_145 ) {
F_61 ( V_18 -> V_145 ) ;
V_18 -> V_145 = NULL ;
}
F_43 ( V_146 , L_7 , V_18 ) ;
F_71 ( & V_18 -> V_10 ) ;
F_72 ( V_18 ) ;
}
static void F_73 ( struct V_147 * V_148 )
{
struct V_87 * V_142 ;
V_142 = F_74 ( V_148 , struct V_87 , V_138 ) ;
F_72 ( V_142 ) ;
}
static void F_75 ( struct V_149 * V_150 )
{
struct V_17 * V_18 ;
V_18 = F_74 ( V_150 , struct V_17 , V_10 ) ;
if ( ! V_18 -> V_10 . V_11 -> V_151 ) return;
F_68 ( V_18 -> V_144 ) ;
F_68 ( V_18 -> V_145 ) ;
if ( V_18 -> V_152 ) return;
F_70 ( V_18 ) ;
}
static long F_76 ( struct V_1 * V_1 ,
unsigned int V_153 , unsigned long V_154 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_17 * V_18 = V_6 -> V_19 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
long V_23 = - V_35 ;
if ( V_155 & V_96 )
F_77 ( F_78 ( V_9 ) , V_153 ) ;
if ( ! F_79 ( V_9 ) ) {
F_43 ( V_156 ,
L_8 ) ;
return - V_157 ;
}
switch ( V_153 ) {
case V_158 :
case V_159 :
case V_160 :
case V_161 :
case V_162 :
V_23 = F_80 ( & V_18 -> V_20 , V_6 -> V_20 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_81 ( V_1 , V_153 , V_154 ) ;
F_82 ( V_9 ) ;
if ( V_23 < 0 ) {
if ( V_155 & V_96 ) {
F_43 ( V_96 ,
L_9 , V_23 ) ;
} else {
if ( V_155 & V_96 ) {
F_43 ( V_96 ,
L_9
L_10 , V_23 ) ;
F_77 ( F_78 ( V_9 ) ,
V_153 ) ;
}
}
} else {
F_43 ( V_96 ,
L_11 ,
V_23 , V_23 ) ;
}
return V_23 ;
}
static int F_83 ( struct V_1 * V_1 )
{
struct V_5 * V_163 = V_1 -> V_7 ;
struct V_17 * V_18 = V_163 -> V_19 ;
struct V_8 * V_9 = V_163 -> V_10 . V_11 -> V_9 ;
F_43 ( V_164 , L_12 ) ;
if ( V_163 -> V_165 ) {
struct V_166 * V_167 ;
F_37 ( V_9 , 0 ) ;
V_167 = F_84 ( V_163 -> V_165 ) ;
if ( V_167 ) F_85 ( V_167 , NULL , NULL ) ;
F_86 ( V_163 -> V_165 ) ;
V_163 -> V_165 = NULL ;
}
F_87 ( & V_18 -> V_20 , V_163 -> V_20 ) ;
V_1 -> V_7 = NULL ;
if ( V_163 -> V_168 ) {
V_163 -> V_168 -> V_169 = V_163 -> V_169 ;
} else {
V_18 -> V_170 = V_163 -> V_169 ;
}
if ( V_163 -> V_169 ) {
V_163 -> V_169 -> V_168 = V_163 -> V_168 ;
} else {
V_18 -> V_152 = V_163 -> V_168 ;
}
V_163 -> V_168 = NULL ;
V_163 -> V_169 = NULL ;
V_163 -> V_19 = NULL ;
F_71 ( & V_163 -> V_10 ) ;
F_43 ( V_146 ,
L_13 , V_163 ) ;
if ( V_163 -> V_36 ) {
F_72 ( V_163 -> V_36 ) ;
V_163 -> V_36 = NULL ;
}
F_72 ( V_163 ) ;
if ( V_18 -> V_10 . V_11 -> V_151 && ! V_18 -> V_152 ) {
F_70 ( V_18 ) ;
}
return 0 ;
}
static int F_88 ( struct V_1 * V_1 )
{
struct V_87 * V_132 ;
struct V_5 * V_163 ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
unsigned int V_171 = 0 ;
unsigned int V_34 , V_46 ;
int V_23 = 0 ;
V_132 = F_74 ( F_89 ( V_1 ) , struct V_87 , V_138 ) ;
V_18 = V_132 -> V_133 ;
V_9 = V_18 -> V_10 . V_9 ;
F_43 ( V_164 , L_14 ) ;
if ( ! F_79 ( V_9 ) ) {
F_43 ( V_164 ,
L_15 ) ;
return - V_172 ;
}
V_163 = F_90 ( sizeof( * V_163 ) , V_173 ) ;
if ( ! V_163 ) {
return - V_174 ;
}
F_91 ( & V_163 -> V_175 ) ;
V_163 -> V_88 = V_132 ;
F_43 ( V_146 , L_16 , V_163 ) ;
F_92 ( & V_163 -> V_10 , V_18 -> V_10 . V_11 ) ;
if ( V_132 -> V_176 == V_177 ) {
V_171 = ( 1 << V_39 ) ;
} else {
V_171 = ( ( 1 << V_39 ) |
( 1 << V_37 ) |
( 1 << V_42 ) |
( 1 << V_41 ) ) ;
}
V_23 = F_93 ( & V_163 -> V_10 , V_171 ) ;
if ( V_23 ) {
F_71 ( & V_163 -> V_10 ) ;
F_43 ( V_146 ,
L_17 ,
V_163 ) ;
F_72 ( V_163 ) ;
return V_23 ;
}
V_171 &= F_94 ( V_9 ) ;
V_34 = 0 ;
for ( V_46 = 0 ; V_46 < ( sizeof( V_171 ) << 3 ) ; V_46 ++ ) {
if ( V_171 & ( 1 << V_46 ) ) V_34 ++ ;
}
V_163 -> V_34 = V_34 ;
V_163 -> V_36 = F_90 ( V_34 , V_173 ) ;
if ( ! V_163 -> V_36 ) {
F_71 ( & V_163 -> V_10 ) ;
F_43 ( V_146 ,
L_18 ,
V_163 ) ;
F_72 ( V_163 ) ;
return - V_174 ;
}
V_34 = 0 ;
for ( V_46 = 0 ; V_46 < ( sizeof( V_171 ) << 3 ) ; V_46 ++ ) {
if ( ! ( V_171 & ( 1 << V_46 ) ) ) continue;
V_163 -> V_36 [ V_34 ++ ] = V_46 ;
}
V_163 -> V_168 = NULL ;
V_163 -> V_169 = V_18 -> V_170 ;
if ( V_18 -> V_170 ) {
V_18 -> V_170 -> V_168 = V_163 ;
} else {
V_18 -> V_152 = V_163 ;
}
V_18 -> V_170 = V_163 ;
V_163 -> V_19 = V_18 ;
V_163 -> V_1 = V_1 ;
V_1 -> V_7 = V_163 ;
F_95 ( & V_18 -> V_20 , & V_163 -> V_20 ) ;
V_163 -> V_178 = F_96 ( V_9 ) ;
return 0 ;
}
static void F_97 ( struct V_5 * V_163 )
{
F_98 ( & V_163 -> V_175 ) ;
}
static int F_99 ( struct V_5 * V_6 )
{
int V_23 ;
struct V_166 * V_167 ;
struct V_8 * V_9 ;
if ( V_6 -> V_165 ) return 0 ;
if ( ! V_6 -> V_88 -> V_89 ) {
return - V_90 ;
}
if ( ( V_23 = F_100 ( & V_6 -> V_10 ,
V_6 -> V_88 -> V_89 ) ) != 0 ) {
return V_23 ;
}
V_6 -> V_165 = F_101 ( V_6 -> V_88 -> V_89 ) ;
if ( ! V_6 -> V_165 ) {
F_100 ( & V_6 -> V_10 , NULL ) ;
return - V_174 ;
}
V_9 = V_6 -> V_10 . V_11 -> V_9 ;
V_167 = V_6 -> V_88 -> V_89 -> V_89 ;
F_85 ( V_167 , ( V_179 ) F_97 , V_6 ) ;
F_36 ( V_9 , V_6 -> V_88 -> V_91 ) ;
if ( ( V_23 = F_37 ( V_9 , ! 0 ) ) < 0 ) return V_23 ;
return F_102 ( V_6 -> V_165 , ! 0 ) ;
}
static T_2 F_103 ( struct V_1 * V_1 ,
char T_3 * V_180 , T_4 V_116 , T_5 * V_181 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_23 ;
if ( V_6 -> V_178 ) {
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
char * V_182 ;
int V_183 , V_184 ;
int V_185 = 0 ;
unsigned int V_186 = * V_181 ;
V_182 = F_104 ( V_187 , V_173 ) ;
if ( ! V_182 ) return - V_174 ;
while ( V_116 ) {
V_183 = V_116 ;
if ( V_183 > V_187 ) V_183 = V_187 ;
V_184 = F_105 ( V_9 , V_186 , V_182 , V_183 ) ;
if ( V_184 < 0 ) {
V_185 = V_184 ;
break;
}
if ( ! V_184 ) break;
if ( F_106 ( V_180 , V_182 , V_184 ) ) {
V_185 = - V_157 ;
break;
}
V_186 += V_184 ;
V_185 += V_184 ;
V_180 += V_184 ;
V_116 -= V_184 ;
* V_181 += V_184 ;
}
F_72 ( V_182 ) ;
return V_185 ;
}
if ( ! V_6 -> V_165 ) {
V_23 = F_99 ( V_6 ) ;
if ( V_23 ) {
return V_23 ;
}
}
for (; ; ) {
V_23 = F_107 ( V_6 -> V_165 , V_180 , V_116 ) ;
if ( V_23 >= 0 ) break;
if ( V_23 != - V_188 ) break;
if ( V_1 -> V_189 & V_190 ) break;
V_23 = F_108 (
V_6 -> V_175 ,
F_109 ( V_6 -> V_165 ) >= 0 ) ;
if ( V_23 < 0 ) break;
}
return V_23 ;
}
static unsigned int F_110 ( struct V_1 * V_1 , T_6 * V_191 )
{
unsigned int V_192 = 0 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_23 ;
if ( V_6 -> V_178 ) {
V_192 |= V_193 | V_194 ;
return V_192 ;
}
if ( ! V_6 -> V_165 ) {
V_23 = F_99 ( V_6 ) ;
if ( V_23 ) return V_195 ;
}
F_111 ( V_1 , & V_6 -> V_175 , V_191 ) ;
if ( F_109 ( V_6 -> V_165 ) >= 0 ) {
V_192 |= V_193 | V_194 ;
}
return V_192 ;
}
static void F_112 ( struct V_87 * V_132 ,
struct V_17 * V_18 ,
int V_176 )
{
int V_196 ;
int V_197 ;
struct V_8 * V_9 ;
int * V_198 = NULL ;
V_132 -> V_133 = V_18 ;
V_9 = V_18 -> V_10 . V_11 -> V_9 ;
V_132 -> V_176 = V_176 ;
switch ( V_176 ) {
case V_199 :
V_132 -> V_89 = & V_18 -> V_10 . V_11 -> V_200 ;
V_132 -> V_91 = V_201 ;
V_132 -> V_139 = V_202 ;
V_198 = V_203 ;
if ( ! V_132 -> V_89 ) {
F_113 ( V_204
L_19
L_20 ) ;
return;
}
break;
case V_205 :
V_132 -> V_91 = V_206 ;
V_132 -> V_139 = V_207 ;
V_198 = V_208 ;
break;
case V_177 :
V_132 -> V_89 = & V_18 -> V_10 . V_11 -> V_200 ;
V_132 -> V_91 = V_201 ;
V_132 -> V_139 = V_209 ;
V_198 = V_210 ;
break;
default:
F_113 ( V_204 L_21
L_22 ) ;
return;
}
V_132 -> V_138 = V_211 ;
V_132 -> V_138 . V_212 = F_73 ;
V_132 -> V_138 . V_213 = & V_214 ;
{
int V_22 ;
F_10 (
F_11 ( V_9 ,
V_215 ) , & V_22 ) ;
V_132 -> V_138 . V_216 = ( T_1 ) V_22 ;
}
V_196 = - 1 ;
V_197 = F_114 ( V_9 ) ;
if ( V_198 && ( V_197 >= 0 ) && ( V_197 < V_217 ) ) {
V_196 = V_198 [ V_197 ] ;
}
F_115 ( V_9 , & V_132 -> V_138 ) ;
if ( ( F_116 ( & V_132 -> V_138 ,
V_132 -> V_176 , V_196 ) < 0 ) &&
( F_116 ( & V_132 -> V_138 ,
V_132 -> V_176 , - 1 ) < 0 ) ) {
F_113 ( V_204
L_23 ) ;
}
F_67 ( V_140 L_24 ,
F_63 ( & V_132 -> V_138 ) ,
F_64 ( V_132 -> V_91 ) ) ;
F_65 ( V_9 ,
V_132 -> V_139 , V_132 -> V_138 . V_218 ) ;
}
struct V_17 * F_117 ( struct V_219 * V_220 )
{
struct V_17 * V_18 ;
V_18 = F_90 ( sizeof( * V_18 ) , V_173 ) ;
if ( ! V_18 ) return V_18 ;
F_92 ( & V_18 -> V_10 , V_220 ) ;
F_43 ( V_146 , L_25 , V_18 ) ;
V_18 -> V_10 . V_221 = F_75 ;
V_18 -> V_144 = F_90 ( sizeof( * V_18 -> V_144 ) , V_173 ) ;
if ( ! V_18 -> V_144 ) goto V_222;
F_112 ( V_18 -> V_144 , V_18 , V_199 ) ;
if ( F_94 ( V_18 -> V_10 . V_11 -> V_9 ) &
( 1 << V_39 ) ) {
V_18 -> V_145 = F_90 ( sizeof( * V_18 -> V_145 ) , V_173 ) ;
if ( ! V_18 -> V_145 ) goto V_222;
F_112 ( V_18 -> V_145 , V_18 , V_177 ) ;
}
return V_18 ;
V_222:
F_43 ( V_146 , L_26 , V_18 ) ;
F_70 ( V_18 ) ;
return NULL ;
}
