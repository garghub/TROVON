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
static int F_61 ( struct V_1 * V_1 , void * V_2 , struct V_132 * V_133 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
T_2 V_22 ;
int V_23 ;
V_23 = F_62 (
V_9 , & V_133 -> V_134 , V_133 -> V_135 ,
0 , & V_22 ) ;
V_133 -> V_22 = V_22 ;
return V_23 ;
}
static int F_63 ( struct V_1 * V_1 , void * V_2 , const struct V_132 * V_133 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
T_2 V_22 ;
int V_23 ;
V_22 = V_133 -> V_22 ;
V_23 = F_62 (
V_9 , & V_133 -> V_134 , V_133 -> V_135 ,
1 , & V_22 ) ;
return V_23 ;
}
static void F_64 ( struct V_87 * V_136 )
{
struct V_8 * V_9 = V_136 -> V_137 -> V_10 . V_11 -> V_9 ;
enum V_138 V_139 = V_136 -> V_91 ;
char V_140 [ 80 ] ;
unsigned int V_141 ;
V_141 = F_65 ( V_140 , sizeof( V_140 ) - 1 ,
L_5 ,
F_66 ( & V_136 -> V_142 ) ,
F_67 ( V_139 ) ) ;
V_140 [ V_141 ] = 0 ;
F_68 ( V_9 , V_136 -> V_143 , - 1 ) ;
V_136 -> V_137 = NULL ;
V_136 -> V_89 = NULL ;
F_69 ( & V_136 -> V_142 ) ;
F_70 ( V_144 L_6 , V_140 ) ;
}
static void F_71 ( struct V_87 * V_136 )
{
if ( ! V_136 ) return;
if ( ! V_136 -> V_142 . V_145 ) return;
V_136 -> V_142 . V_145 = NULL ;
F_72 ( & V_136 -> V_142 . V_146 , NULL , V_147 ) ;
}
static void F_73 ( struct V_17 * V_18 )
{
if ( V_18 -> V_148 ) {
F_64 ( V_18 -> V_148 ) ;
V_18 -> V_148 = NULL ;
}
if ( V_18 -> V_149 ) {
F_64 ( V_18 -> V_149 ) ;
V_18 -> V_149 = NULL ;
}
F_43 ( V_150 , L_7 , V_18 ) ;
F_74 ( & V_18 -> V_10 ) ;
F_75 ( V_18 ) ;
}
static void F_76 ( struct V_151 * V_152 )
{
struct V_87 * V_146 ;
V_146 = F_77 ( V_152 , struct V_87 , V_142 ) ;
F_75 ( V_146 ) ;
}
static void F_78 ( struct V_153 * V_154 )
{
struct V_17 * V_18 ;
V_18 = F_77 ( V_154 , struct V_17 , V_10 ) ;
if ( ! V_18 -> V_10 . V_11 -> V_155 ) return;
F_71 ( V_18 -> V_148 ) ;
F_71 ( V_18 -> V_149 ) ;
if ( V_18 -> V_156 ) return;
F_73 ( V_18 ) ;
}
static long F_79 ( struct V_1 * V_1 ,
unsigned int V_157 , unsigned long V_158 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
struct V_17 * V_18 = V_6 -> V_19 ;
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
long V_23 = - V_35 ;
if ( V_159 & V_96 )
F_80 ( F_81 ( V_9 ) , V_157 ) ;
if ( ! F_82 ( V_9 ) ) {
F_43 ( V_160 ,
L_8 ) ;
return - V_161 ;
}
switch ( V_157 ) {
case V_162 :
case V_163 :
case V_164 :
case V_165 :
case V_166 :
V_23 = F_83 ( & V_18 -> V_20 , V_6 -> V_20 ) ;
if ( V_23 )
return V_23 ;
}
V_23 = F_84 ( V_1 , V_157 , V_158 ) ;
F_85 ( V_9 ) ;
if ( V_23 < 0 ) {
if ( V_159 & V_96 ) {
F_43 ( V_96 ,
L_9 , V_23 ) ;
} else {
if ( V_159 & V_96 ) {
F_43 ( V_96 ,
L_9
L_10 , V_23 ) ;
F_80 ( F_81 ( V_9 ) ,
V_157 ) ;
}
}
} else {
F_43 ( V_96 ,
L_11 ,
V_23 , V_23 ) ;
}
return V_23 ;
}
static int F_86 ( struct V_1 * V_1 )
{
struct V_5 * V_167 = V_1 -> V_7 ;
struct V_17 * V_18 = V_167 -> V_19 ;
struct V_8 * V_9 = V_167 -> V_10 . V_11 -> V_9 ;
F_43 ( V_168 , L_12 ) ;
if ( V_167 -> V_169 ) {
struct V_170 * V_171 ;
F_37 ( V_9 , 0 ) ;
V_171 = F_87 ( V_167 -> V_169 ) ;
if ( V_171 ) F_88 ( V_171 , NULL , NULL ) ;
F_89 ( V_167 -> V_169 ) ;
V_167 -> V_169 = NULL ;
}
F_90 ( & V_18 -> V_20 , V_167 -> V_20 ) ;
V_1 -> V_7 = NULL ;
if ( V_167 -> V_172 ) {
V_167 -> V_172 -> V_173 = V_167 -> V_173 ;
} else {
V_18 -> V_174 = V_167 -> V_173 ;
}
if ( V_167 -> V_173 ) {
V_167 -> V_173 -> V_172 = V_167 -> V_172 ;
} else {
V_18 -> V_156 = V_167 -> V_172 ;
}
V_167 -> V_172 = NULL ;
V_167 -> V_173 = NULL ;
V_167 -> V_19 = NULL ;
F_74 ( & V_167 -> V_10 ) ;
F_43 ( V_150 ,
L_13 , V_167 ) ;
if ( V_167 -> V_36 ) {
F_75 ( V_167 -> V_36 ) ;
V_167 -> V_36 = NULL ;
}
F_75 ( V_167 ) ;
if ( V_18 -> V_10 . V_11 -> V_155 && ! V_18 -> V_156 ) {
F_73 ( V_18 ) ;
}
return 0 ;
}
static int F_91 ( struct V_1 * V_1 )
{
struct V_87 * V_136 ;
struct V_5 * V_167 ;
struct V_17 * V_18 ;
struct V_8 * V_9 ;
unsigned int V_175 = 0 ;
unsigned int V_34 , V_46 ;
int V_23 = 0 ;
V_136 = F_77 ( F_92 ( V_1 ) , struct V_87 , V_142 ) ;
V_18 = V_136 -> V_137 ;
V_9 = V_18 -> V_10 . V_9 ;
F_43 ( V_168 , L_14 ) ;
if ( ! F_82 ( V_9 ) ) {
F_43 ( V_168 ,
L_15 ) ;
return - V_176 ;
}
V_167 = F_93 ( sizeof( * V_167 ) , V_177 ) ;
if ( ! V_167 ) {
return - V_178 ;
}
F_94 ( & V_167 -> V_179 ) ;
V_167 -> V_88 = V_136 ;
F_43 ( V_150 , L_16 , V_167 ) ;
F_95 ( & V_167 -> V_10 , V_18 -> V_10 . V_11 ) ;
if ( V_136 -> V_180 == V_181 ) {
V_175 = ( 1 << V_39 ) ;
} else {
V_175 = ( ( 1 << V_39 ) |
( 1 << V_37 ) |
( 1 << V_42 ) |
( 1 << V_41 ) ) ;
}
V_23 = F_96 ( & V_167 -> V_10 , V_175 ) ;
if ( V_23 ) {
F_74 ( & V_167 -> V_10 ) ;
F_43 ( V_150 ,
L_17 ,
V_167 ) ;
F_75 ( V_167 ) ;
return V_23 ;
}
V_175 &= F_97 ( V_9 ) ;
V_34 = 0 ;
for ( V_46 = 0 ; V_46 < ( sizeof( V_175 ) << 3 ) ; V_46 ++ ) {
if ( V_175 & ( 1 << V_46 ) ) V_34 ++ ;
}
V_167 -> V_34 = V_34 ;
V_167 -> V_36 = F_93 ( V_34 , V_177 ) ;
if ( ! V_167 -> V_36 ) {
F_74 ( & V_167 -> V_10 ) ;
F_43 ( V_150 ,
L_18 ,
V_167 ) ;
F_75 ( V_167 ) ;
return - V_178 ;
}
V_34 = 0 ;
for ( V_46 = 0 ; V_46 < ( sizeof( V_175 ) << 3 ) ; V_46 ++ ) {
if ( ! ( V_175 & ( 1 << V_46 ) ) ) continue;
V_167 -> V_36 [ V_34 ++ ] = V_46 ;
}
V_167 -> V_172 = NULL ;
V_167 -> V_173 = V_18 -> V_174 ;
if ( V_18 -> V_174 ) {
V_18 -> V_174 -> V_172 = V_167 ;
} else {
V_18 -> V_156 = V_167 ;
}
V_18 -> V_174 = V_167 ;
V_167 -> V_19 = V_18 ;
V_167 -> V_1 = V_1 ;
V_1 -> V_7 = V_167 ;
F_98 ( & V_18 -> V_20 , & V_167 -> V_20 ) ;
V_167 -> V_182 = F_99 ( V_9 ) ;
return 0 ;
}
static void F_100 ( struct V_5 * V_167 )
{
F_101 ( & V_167 -> V_179 ) ;
}
static int F_102 ( struct V_5 * V_6 )
{
int V_23 ;
struct V_170 * V_171 ;
struct V_8 * V_9 ;
if ( V_6 -> V_169 ) return 0 ;
if ( ! V_6 -> V_88 -> V_89 ) {
return - V_90 ;
}
if ( ( V_23 = F_103 ( & V_6 -> V_10 ,
V_6 -> V_88 -> V_89 ) ) != 0 ) {
return V_23 ;
}
V_6 -> V_169 = F_104 ( V_6 -> V_88 -> V_89 ) ;
if ( ! V_6 -> V_169 ) {
F_103 ( & V_6 -> V_10 , NULL ) ;
return - V_178 ;
}
V_9 = V_6 -> V_10 . V_11 -> V_9 ;
V_171 = V_6 -> V_88 -> V_89 -> V_89 ;
F_88 ( V_171 , ( V_183 ) F_100 , V_6 ) ;
F_36 ( V_9 , V_6 -> V_88 -> V_91 ) ;
if ( ( V_23 = F_37 ( V_9 , ! 0 ) ) < 0 ) return V_23 ;
return F_105 ( V_6 -> V_169 , ! 0 ) ;
}
static T_3 F_106 ( struct V_1 * V_1 ,
char T_4 * V_184 , T_5 V_116 , T_6 * V_185 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
int V_23 ;
if ( V_6 -> V_182 ) {
struct V_8 * V_9 = V_6 -> V_10 . V_11 -> V_9 ;
char * V_186 ;
int V_187 , V_188 ;
int V_189 = 0 ;
unsigned int V_190 = * V_185 ;
V_186 = F_107 ( V_191 , V_177 ) ;
if ( ! V_186 ) return - V_178 ;
while ( V_116 ) {
V_187 = V_116 ;
if ( V_187 > V_191 ) V_187 = V_191 ;
V_188 = F_108 ( V_9 , V_190 , V_186 , V_187 ) ;
if ( V_188 < 0 ) {
V_189 = V_188 ;
break;
}
if ( ! V_188 ) break;
if ( F_109 ( V_184 , V_186 , V_188 ) ) {
V_189 = - V_161 ;
break;
}
V_190 += V_188 ;
V_189 += V_188 ;
V_184 += V_188 ;
V_116 -= V_188 ;
* V_185 += V_188 ;
}
F_75 ( V_186 ) ;
return V_189 ;
}
if ( ! V_6 -> V_169 ) {
V_23 = F_102 ( V_6 ) ;
if ( V_23 ) {
return V_23 ;
}
}
for (; ; ) {
V_23 = F_110 ( V_6 -> V_169 , V_184 , V_116 ) ;
if ( V_23 >= 0 ) break;
if ( V_23 != - V_192 ) break;
if ( V_1 -> V_193 & V_194 ) break;
V_23 = F_111 (
V_6 -> V_179 ,
F_112 ( V_6 -> V_169 ) >= 0 ) ;
if ( V_23 < 0 ) break;
}
return V_23 ;
}
static unsigned int F_113 ( struct V_1 * V_1 , T_7 * V_195 )
{
unsigned int V_196 = 0 ;
struct V_5 * V_6 = V_1 -> V_7 ;
int V_23 ;
if ( V_6 -> V_182 ) {
V_196 |= V_197 | V_198 ;
return V_196 ;
}
if ( ! V_6 -> V_169 ) {
V_23 = F_102 ( V_6 ) ;
if ( V_23 ) return V_199 ;
}
F_114 ( V_1 , & V_6 -> V_179 , V_195 ) ;
if ( F_112 ( V_6 -> V_169 ) >= 0 ) {
V_196 |= V_197 | V_198 ;
}
return V_196 ;
}
static void F_115 ( struct V_87 * V_136 ,
struct V_17 * V_18 ,
int V_180 )
{
struct V_200 * V_201 ;
int V_202 ;
int V_203 ;
struct V_8 * V_9 ;
int * V_204 = NULL ;
V_136 -> V_137 = V_18 ;
V_9 = V_18 -> V_10 . V_11 -> V_9 ;
V_201 = F_116 ( V_9 ) ;
V_136 -> V_180 = V_180 ;
switch ( V_180 ) {
case V_205 :
V_136 -> V_89 = & V_18 -> V_10 . V_11 -> V_206 ;
V_136 -> V_91 = V_207 ;
V_136 -> V_143 = V_208 ;
V_204 = V_209 ;
if ( ! V_136 -> V_89 ) {
F_117 ( V_210
L_19
L_20 ) ;
return;
}
break;
case V_211 :
V_136 -> V_91 = V_212 ;
V_136 -> V_143 = V_213 ;
V_204 = V_214 ;
break;
case V_181 :
V_136 -> V_89 = & V_18 -> V_10 . V_11 -> V_206 ;
V_136 -> V_91 = V_207 ;
V_136 -> V_143 = V_215 ;
V_204 = V_216 ;
break;
default:
F_117 ( V_210 L_21
L_22 ) ;
return;
}
V_136 -> V_142 = V_217 ;
V_136 -> V_142 . V_218 = F_76 ;
V_136 -> V_142 . V_219 = & V_220 ;
{
int V_22 ;
F_10 (
F_11 ( V_9 ,
V_221 ) , & V_22 ) ;
V_136 -> V_142 . V_222 = ( T_1 ) V_22 ;
}
V_202 = - 1 ;
V_203 = F_118 ( V_9 ) ;
if ( V_204 && ( V_203 >= 0 ) && ( V_203 < V_223 ) ) {
V_202 = V_204 [ V_203 ] ;
}
V_136 -> V_142 . V_145 = & V_201 -> V_146 ;
if ( ( F_119 ( & V_136 -> V_142 ,
V_136 -> V_180 , V_202 ) < 0 ) &&
( F_119 ( & V_136 -> V_142 ,
V_136 -> V_180 , - 1 ) < 0 ) ) {
F_117 ( V_210
L_23 ) ;
}
F_70 ( V_144 L_24 ,
F_66 ( & V_136 -> V_142 ) ,
F_67 ( V_136 -> V_91 ) ) ;
F_68 ( V_9 ,
V_136 -> V_143 , V_136 -> V_142 . V_224 ) ;
}
struct V_17 * F_120 ( struct V_225 * V_226 )
{
struct V_17 * V_18 ;
V_18 = F_93 ( sizeof( * V_18 ) , V_177 ) ;
if ( ! V_18 ) return V_18 ;
F_95 ( & V_18 -> V_10 , V_226 ) ;
F_43 ( V_150 , L_25 , V_18 ) ;
V_18 -> V_10 . V_227 = F_78 ;
V_18 -> V_148 = F_93 ( sizeof( * V_18 -> V_148 ) , V_177 ) ;
if ( ! V_18 -> V_148 ) goto V_228;
F_115 ( V_18 -> V_148 , V_18 , V_205 ) ;
if ( F_97 ( V_18 -> V_10 . V_11 -> V_9 ) &
( 1 << V_39 ) ) {
V_18 -> V_149 = F_93 ( sizeof( * V_18 -> V_149 ) , V_177 ) ;
if ( ! V_18 -> V_149 ) goto V_228;
F_115 ( V_18 -> V_149 , V_18 , V_181 ) ;
}
return V_18 ;
V_228:
F_43 ( V_150 , L_26 , V_18 ) ;
F_73 ( V_18 ) ;
return NULL ;
}
