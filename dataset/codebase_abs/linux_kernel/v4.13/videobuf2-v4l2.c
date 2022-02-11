static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
if ( ! F_2 ( V_4 -> type ) )
return 0 ;
if ( V_4 -> V_5 . V_6 == NULL ) {
F_3 ( 1 , L_1 ) ;
return - V_7 ;
}
if ( V_4 -> V_8 < V_2 -> V_9 || V_4 -> V_8 > V_10 ) {
F_3 ( 1 , L_2 ,
V_2 -> V_9 , V_4 -> V_8 ) ;
return - V_7 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const void * V_11 )
{
return F_1 ( V_2 , V_11 ) ;
}
static int F_5 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
unsigned int V_8 ;
unsigned int V_12 ;
unsigned int V_13 ;
if ( ! F_6 ( V_4 -> type ) )
return 0 ;
if ( F_2 ( V_4 -> type ) ) {
for ( V_13 = 0 ; V_13 < V_2 -> V_9 ; ++ V_13 ) {
V_8 = ( V_4 -> V_14 == V_15 ||
V_4 -> V_14 == V_16 )
? V_4 -> V_5 . V_6 [ V_13 ] . V_8
: V_2 -> V_6 [ V_13 ] . V_8 ;
V_12 = V_4 -> V_5 . V_6 [ V_13 ] . V_12
? V_4 -> V_5 . V_6 [ V_13 ] . V_12 : V_8 ;
if ( V_4 -> V_5 . V_6 [ V_13 ] . V_12 > V_8 )
return - V_7 ;
if ( V_4 -> V_5 . V_6 [ V_13 ] . V_17 > 0 &&
V_4 -> V_5 . V_6 [ V_13 ] . V_17 >= V_12 )
return - V_7 ;
}
} else {
V_8 = ( V_4 -> V_14 == V_15 )
? V_4 -> V_8 : V_2 -> V_6 [ 0 ] . V_8 ;
if ( V_4 -> V_12 > V_8 )
return - V_7 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 , const void * V_11 )
{
const struct V_3 * V_4 = V_11 ;
struct V_18 * V_19 = F_8 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_20 ;
if ( V_21 -> V_22 ) {
if ( V_21 -> V_23 )
V_2 -> V_24 = F_9 ( & V_4 -> V_24 ) ;
V_19 -> V_25 |= V_4 -> V_25 & V_26 ;
if ( V_4 -> V_25 & V_26 )
V_19 -> V_27 = V_4 -> V_27 ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
static bool V_28 ;
if ( V_28 )
return;
V_28 = true ;
F_11 ( 1 ) ;
F_12 ( L_3 ) ;
if ( V_2 -> V_20 -> V_29 )
F_12 ( L_4 ) ;
else
F_12 ( L_5 ) ;
}
static int F_13 ( struct V_20 * V_21 , struct V_3 * V_4 ,
const char * V_30 )
{
if ( V_4 -> type != V_21 -> type ) {
F_3 ( 1 , L_6 , V_30 ) ;
return - V_7 ;
}
if ( V_4 -> V_31 >= V_21 -> V_32 ) {
F_3 ( 1 , L_7 , V_30 ) ;
return - V_7 ;
}
if ( V_21 -> V_33 [ V_4 -> V_31 ] == NULL ) {
F_3 ( 1 , L_8 , V_30 ) ;
return - V_7 ;
}
if ( V_4 -> V_14 != V_21 -> V_14 ) {
F_3 ( 1 , L_9 , V_30 ) ;
return - V_7 ;
}
return F_1 ( V_21 -> V_33 [ V_4 -> V_31 ] , V_4 ) ;
}
static void F_14 ( struct V_1 * V_2 , void * V_11 )
{
struct V_3 * V_4 = V_11 ;
struct V_18 * V_19 = F_8 ( V_2 ) ;
struct V_20 * V_21 = V_2 -> V_20 ;
unsigned int V_13 ;
V_4 -> V_31 = V_2 -> V_31 ;
V_4 -> type = V_2 -> type ;
V_4 -> V_14 = V_2 -> V_14 ;
V_4 -> V_12 = 0 ;
V_4 -> V_25 = V_19 -> V_25 ;
V_4 -> V_34 = V_19 -> V_34 ;
V_4 -> V_24 = F_15 ( V_2 -> V_24 ) ;
V_4 -> V_27 = V_19 -> V_27 ;
V_4 -> V_35 = V_19 -> V_35 ;
V_4 -> V_36 = 0 ;
V_4 -> V_37 = 0 ;
if ( V_21 -> V_38 ) {
V_4 -> V_8 = V_2 -> V_9 ;
for ( V_13 = 0 ; V_13 < V_2 -> V_9 ; ++ V_13 ) {
struct V_39 * V_40 = & V_4 -> V_5 . V_6 [ V_13 ] ;
struct V_41 * V_42 = & V_2 -> V_6 [ V_13 ] ;
V_40 -> V_12 = V_42 -> V_12 ;
V_40 -> V_8 = V_42 -> V_8 ;
if ( V_21 -> V_14 == V_43 )
V_40 -> V_5 . V_44 = V_42 -> V_5 . V_45 ;
else if ( V_21 -> V_14 == V_15 )
V_40 -> V_5 . V_46 = V_42 -> V_5 . V_46 ;
else if ( V_21 -> V_14 == V_16 )
V_40 -> V_5 . V_47 = V_42 -> V_5 . V_47 ;
V_40 -> V_17 = V_42 -> V_17 ;
memset ( V_40 -> V_37 , 0 , sizeof( V_40 -> V_37 ) ) ;
}
} else {
V_4 -> V_8 = V_2 -> V_6 [ 0 ] . V_8 ;
V_4 -> V_12 = V_2 -> V_6 [ 0 ] . V_12 ;
if ( V_21 -> V_14 == V_43 )
V_4 -> V_5 . V_45 = V_2 -> V_6 [ 0 ] . V_5 . V_45 ;
else if ( V_21 -> V_14 == V_15 )
V_4 -> V_5 . V_46 = V_2 -> V_6 [ 0 ] . V_5 . V_46 ;
else if ( V_21 -> V_14 == V_16 )
V_4 -> V_5 . V_47 = V_2 -> V_6 [ 0 ] . V_5 . V_47 ;
}
V_4 -> V_25 &= ~ V_48 ;
V_4 -> V_25 |= V_21 -> V_49 & V_50 ;
if ( ! V_21 -> V_23 ) {
V_4 -> V_25 &= ~ V_51 ;
V_4 -> V_25 |= V_21 -> V_49 & V_51 ;
}
switch ( V_2 -> V_52 ) {
case V_53 :
case V_54 :
V_4 -> V_25 |= V_55 ;
break;
case V_56 :
V_4 -> V_25 |= V_57 ;
case V_58 :
V_4 -> V_25 |= V_59 ;
break;
case V_60 :
V_4 -> V_25 |= V_61 ;
break;
case V_62 :
case V_63 :
case V_64 :
break;
}
if ( F_16 ( V_21 , V_2 ) )
V_4 -> V_25 |= V_65 ;
if ( ! V_21 -> V_22 &&
V_4 -> V_25 & V_59 &&
V_4 -> V_25 & V_66 )
V_21 -> V_67 = true ;
}
static int F_17 ( struct V_1 * V_2 ,
const void * V_11 , struct V_41 * V_6 )
{
struct V_20 * V_21 = V_2 -> V_20 ;
const struct V_3 * V_4 = V_11 ;
struct V_18 * V_19 = F_8 ( V_2 ) ;
unsigned int V_13 ;
int V_68 ;
V_68 = F_5 ( V_2 , V_4 ) ;
if ( V_68 < 0 ) {
F_3 ( 1 , L_10 , V_68 ) ;
return V_68 ;
}
if ( V_4 -> V_34 == V_69 && V_21 -> V_22 ) {
F_3 ( 1 , L_11 ) ;
return - V_7 ;
}
V_2 -> V_24 = 0 ;
V_19 -> V_35 = 0 ;
if ( F_2 ( V_4 -> type ) ) {
if ( V_4 -> V_14 == V_15 ) {
for ( V_13 = 0 ; V_13 < V_2 -> V_9 ; ++ V_13 ) {
V_6 [ V_13 ] . V_5 . V_46 =
V_4 -> V_5 . V_6 [ V_13 ] . V_5 . V_46 ;
V_6 [ V_13 ] . V_8 =
V_4 -> V_5 . V_6 [ V_13 ] . V_8 ;
}
}
if ( V_4 -> V_14 == V_16 ) {
for ( V_13 = 0 ; V_13 < V_2 -> V_9 ; ++ V_13 ) {
V_6 [ V_13 ] . V_5 . V_47 =
V_4 -> V_5 . V_6 [ V_13 ] . V_5 . V_47 ;
V_6 [ V_13 ] . V_8 =
V_4 -> V_5 . V_6 [ V_13 ] . V_8 ;
}
}
if ( F_6 ( V_4 -> type ) ) {
for ( V_13 = 0 ; V_13 < V_2 -> V_9 ; ++ V_13 ) {
struct V_41 * V_40 = & V_6 [ V_13 ] ;
struct V_39 * V_42 = & V_4 -> V_5 . V_6 [ V_13 ] ;
if ( V_42 -> V_12 == 0 )
F_10 ( V_2 ) ;
if ( V_2 -> V_20 -> V_29 )
V_40 -> V_12 = V_42 -> V_12 ;
else
V_40 -> V_12 = V_42 -> V_12 ?
V_42 -> V_12 : V_40 -> V_8 ;
V_40 -> V_17 = V_42 -> V_17 ;
}
}
} else {
if ( V_4 -> V_14 == V_15 ) {
V_6 [ 0 ] . V_5 . V_46 = V_4 -> V_5 . V_46 ;
V_6 [ 0 ] . V_8 = V_4 -> V_8 ;
}
if ( V_4 -> V_14 == V_16 ) {
V_6 [ 0 ] . V_5 . V_47 = V_4 -> V_5 . V_47 ;
V_6 [ 0 ] . V_8 = V_4 -> V_8 ;
}
if ( F_6 ( V_4 -> type ) ) {
if ( V_4 -> V_12 == 0 )
F_10 ( V_2 ) ;
if ( V_2 -> V_20 -> V_29 )
V_6 [ 0 ] . V_12 = V_4 -> V_12 ;
else
V_6 [ 0 ] . V_12 = V_4 -> V_12 ?
V_4 -> V_12 : V_6 [ 0 ] . V_8 ;
} else
V_6 [ 0 ] . V_12 = 0 ;
}
V_19 -> V_25 = V_4 -> V_25 & ~ V_48 ;
if ( ! V_2 -> V_20 -> V_23 || ! F_6 ( V_4 -> type ) ) {
V_19 -> V_25 &= ~ V_51 ;
}
if ( F_6 ( V_4 -> type ) ) {
V_19 -> V_25 &= ~ V_26 ;
V_19 -> V_34 = V_4 -> V_34 ;
} else {
V_19 -> V_25 &= ~ V_70 ;
}
return 0 ;
}
int F_18 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_68 ;
if ( V_4 -> type != V_21 -> type ) {
F_3 ( 1 , L_12 ) ;
return - V_7 ;
}
if ( V_4 -> V_31 >= V_21 -> V_32 ) {
F_3 ( 1 , L_13 ) ;
return - V_7 ;
}
V_2 = V_21 -> V_33 [ V_4 -> V_31 ] ;
V_68 = F_1 ( V_2 , V_4 ) ;
if ( ! V_68 )
F_19 ( V_21 , V_4 -> V_31 , V_4 ) ;
return V_68 ;
}
int F_20 ( struct V_20 * V_21 , struct V_71 * V_72 )
{
int V_68 = F_21 ( V_21 , V_72 -> V_14 , V_72 -> type ) ;
return V_68 ? V_68 : F_22 ( V_21 , V_72 -> V_14 , & V_72 -> V_73 ) ;
}
int F_23 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
int V_68 ;
if ( F_24 ( V_21 ) ) {
F_3 ( 1 , L_14 ) ;
return - V_74 ;
}
V_68 = F_13 ( V_21 , V_4 , L_15 ) ;
return V_68 ? V_68 : F_25 ( V_21 , V_4 -> V_31 , V_4 ) ;
}
int F_26 ( struct V_20 * V_21 , struct V_75 * V_76 )
{
unsigned V_77 = 1 ;
unsigned V_78 [ V_79 ] ;
struct V_80 * V_81 = & V_76 -> V_82 ;
int V_68 = F_21 ( V_21 , V_76 -> V_14 , V_81 -> type ) ;
unsigned V_83 ;
V_76 -> V_31 = V_21 -> V_32 ;
if ( V_76 -> V_73 == 0 )
return V_68 != - V_74 ? V_68 : 0 ;
switch ( V_81 -> type ) {
case V_84 :
case V_85 :
V_77 = V_81 -> V_86 . V_87 . V_9 ;
if ( V_77 == 0 ||
V_77 > V_79 )
return - V_7 ;
for ( V_83 = 0 ; V_83 < V_77 ; V_83 ++ )
V_78 [ V_83 ] =
V_81 -> V_86 . V_87 . V_88 [ V_83 ] . V_89 ;
break;
case V_90 :
case V_91 :
V_78 [ 0 ] = V_81 -> V_86 . V_92 . V_89 ;
break;
case V_93 :
case V_94 :
V_78 [ 0 ] = V_81 -> V_86 . V_95 . V_96 *
( V_81 -> V_86 . V_95 . V_73 [ 0 ] + V_81 -> V_86 . V_95 . V_73 [ 1 ] ) ;
break;
case V_97 :
case V_98 :
V_78 [ 0 ] = V_81 -> V_86 . V_99 . V_100 ;
break;
case V_101 :
case V_102 :
V_78 [ 0 ] = V_81 -> V_86 . V_103 . V_104 ;
break;
case V_105 :
V_78 [ 0 ] = V_81 -> V_86 . V_106 . V_104 ;
break;
default:
return - V_7 ;
}
for ( V_83 = 0 ; V_83 < V_77 ; V_83 ++ )
if ( V_78 [ V_83 ] == 0 )
return - V_7 ;
return V_68 ? V_68 : F_27 ( V_21 , V_76 -> V_14 ,
& V_76 -> V_73 , V_77 , V_78 ) ;
}
int F_28 ( struct V_20 * V_21 , struct V_3 * V_4 )
{
int V_68 ;
if ( F_24 ( V_21 ) ) {
F_3 ( 1 , L_14 ) ;
return - V_74 ;
}
V_68 = F_13 ( V_21 , V_4 , L_16 ) ;
return V_68 ? V_68 : F_29 ( V_21 , V_4 -> V_31 , V_4 ) ;
}
int F_30 ( struct V_20 * V_21 , struct V_3 * V_4 , bool V_107 )
{
int V_68 ;
if ( F_24 ( V_21 ) ) {
F_3 ( 1 , L_14 ) ;
return - V_74 ;
}
if ( V_4 -> type != V_21 -> type ) {
F_3 ( 1 , L_17 ) ;
return - V_7 ;
}
V_68 = F_31 ( V_21 , NULL , V_4 , V_107 ) ;
V_4 -> V_25 &= ~ V_59 ;
return V_68 ;
}
int F_32 ( struct V_20 * V_21 , enum V_108 type )
{
if ( F_24 ( V_21 ) ) {
F_3 ( 1 , L_14 ) ;
return - V_74 ;
}
return F_33 ( V_21 , type ) ;
}
int F_34 ( struct V_20 * V_21 , enum V_108 type )
{
if ( F_24 ( V_21 ) ) {
F_3 ( 1 , L_14 ) ;
return - V_74 ;
}
return F_35 ( V_21 , type ) ;
}
int F_36 ( struct V_20 * V_21 , struct V_109 * V_110 )
{
return F_37 ( V_21 , & V_110 -> V_47 , V_110 -> type , V_110 -> V_31 ,
V_110 -> V_13 , V_110 -> V_25 ) ;
}
int F_38 ( struct V_20 * V_21 )
{
if ( F_11 ( ! V_21 ) ||
F_11 ( V_21 -> V_49 &
~ ( V_50 |
V_51 ) ) )
return - V_7 ;
F_11 ( ( V_21 -> V_49 & V_50 ) ==
V_111 ) ;
if ( F_11 ( V_43 != ( int ) V_112 )
|| F_11 ( V_15 != ( int ) V_113 )
|| F_11 ( V_16 != ( int ) V_114 ) )
return - V_7 ;
if ( V_21 -> V_115 == 0 )
V_21 -> V_115 = sizeof( struct V_18 ) ;
V_21 -> V_116 = & V_117 ;
V_21 -> V_38 = F_2 ( V_21 -> type ) ;
V_21 -> V_22 = F_6 ( V_21 -> type ) ;
V_21 -> V_23 = ( V_21 -> V_49 & V_50 )
== V_118 ;
V_21 -> V_119 = true ;
return F_39 ( V_21 ) ;
}
void F_40 ( struct V_20 * V_21 )
{
F_41 ( V_21 ) ;
}
unsigned int F_42 ( struct V_20 * V_21 , struct V_120 * V_120 , T_1 * V_121 )
{
struct V_122 * V_123 = F_43 ( V_120 ) ;
unsigned long V_124 = F_44 ( V_121 ) ;
unsigned int V_125 = 0 ;
if ( F_45 ( V_126 , & V_123 -> V_25 ) ) {
struct V_127 * V_128 = V_120 -> V_129 ;
if ( F_46 ( V_128 ) )
V_125 = V_130 ;
else if ( V_124 & V_130 )
F_47 ( V_120 , & V_128 -> V_121 , V_121 ) ;
}
return V_125 | F_48 ( V_21 , V_120 , V_121 ) ;
}
static inline bool F_49 ( struct V_122 * V_131 , struct V_120 * V_120 )
{
return V_131 -> V_132 -> V_133 && V_131 -> V_132 -> V_133 != V_120 -> V_129 ;
}
int F_50 ( struct V_120 * V_120 , void * V_134 ,
struct V_71 * V_135 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
int V_125 = F_21 ( V_131 -> V_132 , V_135 -> V_14 , V_135 -> type ) ;
if ( V_125 )
return V_125 ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
V_125 = F_22 ( V_131 -> V_132 , V_135 -> V_14 , & V_135 -> V_73 ) ;
if ( V_125 == 0 )
V_131 -> V_132 -> V_133 = V_135 -> V_73 ? V_120 -> V_129 : NULL ;
return V_125 ;
}
int F_51 ( struct V_120 * V_120 , void * V_134 ,
struct V_75 * V_135 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
int V_125 = F_21 ( V_131 -> V_132 , V_135 -> V_14 ,
V_135 -> V_82 . type ) ;
V_135 -> V_31 = V_131 -> V_132 -> V_32 ;
if ( V_135 -> V_73 == 0 )
return V_125 != - V_74 ? V_125 : 0 ;
if ( V_125 )
return V_125 ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
V_125 = F_26 ( V_131 -> V_132 , V_135 ) ;
if ( V_125 == 0 )
V_131 -> V_132 -> V_133 = V_120 -> V_129 ;
return V_125 ;
}
int F_52 ( struct V_120 * V_120 , void * V_134 ,
struct V_3 * V_135 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
return F_23 ( V_131 -> V_132 , V_135 ) ;
}
int F_53 ( struct V_120 * V_120 , void * V_134 , struct V_3 * V_135 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
return F_18 ( V_131 -> V_132 , V_135 ) ;
}
int F_54 ( struct V_120 * V_120 , void * V_134 , struct V_3 * V_135 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
return F_28 ( V_131 -> V_132 , V_135 ) ;
}
int F_55 ( struct V_120 * V_120 , void * V_134 , struct V_3 * V_135 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
return F_30 ( V_131 -> V_132 , V_135 , V_120 -> V_136 & V_137 ) ;
}
int F_56 ( struct V_120 * V_120 , void * V_134 , enum V_108 V_83 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
return F_32 ( V_131 -> V_132 , V_83 ) ;
}
int F_57 ( struct V_120 * V_120 , void * V_134 , enum V_108 V_83 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
return F_34 ( V_131 -> V_132 , V_83 ) ;
}
int F_58 ( struct V_120 * V_120 , void * V_134 , struct V_109 * V_135 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
if ( F_49 ( V_131 , V_120 ) )
return - V_74 ;
return F_36 ( V_131 -> V_132 , V_135 ) ;
}
int F_59 ( struct V_120 * V_120 , struct V_138 * V_139 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
return F_60 ( V_131 -> V_132 , V_139 ) ;
}
int F_61 ( struct V_120 * V_120 , struct V_140 * V_141 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
if ( V_141 )
F_62 ( V_141 ) ;
if ( V_120 -> V_129 == V_131 -> V_132 -> V_133 ) {
F_40 ( V_131 -> V_132 ) ;
V_131 -> V_132 -> V_133 = NULL ;
}
if ( V_141 )
F_63 ( V_141 ) ;
return F_64 ( V_120 ) ;
}
int F_65 ( struct V_120 * V_120 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
struct V_140 * V_141 = V_131 -> V_132 -> V_141 ? V_131 -> V_132 -> V_141 : V_131 -> V_141 ;
return F_61 ( V_120 , V_141 ) ;
}
T_2 F_66 ( struct V_120 * V_120 , const char T_3 * V_142 ,
T_4 V_73 , T_5 * V_143 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
struct V_140 * V_141 = V_131 -> V_132 -> V_141 ? V_131 -> V_132 -> V_141 : V_131 -> V_141 ;
int V_144 = - V_74 ;
if ( ! ( V_131 -> V_132 -> V_145 & V_146 ) )
return - V_7 ;
if ( V_141 && F_67 ( V_141 ) )
return - V_147 ;
if ( F_49 ( V_131 , V_120 ) )
goto exit;
V_144 = F_68 ( V_131 -> V_132 , V_142 , V_73 , V_143 ,
V_120 -> V_136 & V_137 ) ;
if ( V_131 -> V_132 -> V_148 )
V_131 -> V_132 -> V_133 = V_120 -> V_129 ;
exit:
if ( V_141 )
F_63 ( V_141 ) ;
return V_144 ;
}
T_2 F_69 ( struct V_120 * V_120 , char T_3 * V_142 ,
T_4 V_73 , T_5 * V_143 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
struct V_140 * V_141 = V_131 -> V_132 -> V_141 ? V_131 -> V_132 -> V_141 : V_131 -> V_141 ;
int V_144 = - V_74 ;
if ( ! ( V_131 -> V_132 -> V_145 & V_149 ) )
return - V_7 ;
if ( V_141 && F_67 ( V_141 ) )
return - V_147 ;
if ( F_49 ( V_131 , V_120 ) )
goto exit;
V_144 = F_70 ( V_131 -> V_132 , V_142 , V_73 , V_143 ,
V_120 -> V_136 & V_137 ) ;
if ( V_131 -> V_132 -> V_148 )
V_131 -> V_132 -> V_133 = V_120 -> V_129 ;
exit:
if ( V_141 )
F_63 ( V_141 ) ;
return V_144 ;
}
unsigned int F_71 ( struct V_120 * V_120 , T_1 * V_121 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
struct V_20 * V_21 = V_131 -> V_132 ;
struct V_140 * V_141 = V_21 -> V_141 ? V_21 -> V_141 : V_131 -> V_141 ;
unsigned V_125 ;
void * V_148 ;
F_11 ( ! V_141 ) ;
if ( V_141 && F_67 ( V_141 ) )
return V_150 ;
V_148 = V_21 -> V_148 ;
V_125 = F_42 ( V_131 -> V_132 , V_120 , V_121 ) ;
if ( ! V_148 && V_21 -> V_148 )
V_21 -> V_133 = V_120 -> V_129 ;
if ( V_141 )
F_63 ( V_141 ) ;
return V_125 ;
}
unsigned long F_72 ( struct V_120 * V_120 , unsigned long V_151 ,
unsigned long V_152 , unsigned long V_153 , unsigned long V_25 )
{
struct V_122 * V_131 = F_43 ( V_120 ) ;
return F_73 ( V_131 -> V_132 , V_151 , V_152 , V_153 , V_25 ) ;
}
void F_74 ( struct V_20 * V_154 )
{
F_63 ( V_154 -> V_141 ) ;
}
void F_75 ( struct V_20 * V_154 )
{
F_62 ( V_154 -> V_141 ) ;
}
