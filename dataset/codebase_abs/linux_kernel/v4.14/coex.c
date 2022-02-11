static enum V_1
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 ;
enum V_1 V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 ;
F_2 () ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) {
F_4 () ;
return V_16 ;
}
V_8 = V_17 ;
if ( V_3 -> V_18 -> V_19 ) {
F_4 () ;
return V_8 ;
}
V_9 = * ( ( T_1 * ) V_7 -> V_20 ) ;
V_10 = F_5 ( V_3 -> V_21 . V_10 ) ;
V_11 =
F_5 ( V_3 -> V_21 . V_11 ) ;
if ( V_10 == V_9 )
V_8 = F_5 ( V_3 -> V_22 . V_23 ) ;
else if ( V_11 == V_9 )
V_8 = F_5 ( V_3 -> V_22 . V_24 ) ;
F_4 () ;
return V_8 ;
}
int F_6 ( struct V_2 * V_3 )
{
struct V_25 V_26 = {} ;
T_2 V_27 ;
F_7 ( & V_3 -> V_28 ) ;
if ( F_8 ( V_3 -> V_29 != V_30 ) ) {
switch ( V_3 -> V_29 ) {
case V_31 :
V_27 = V_32 ;
break;
case V_33 :
V_27 = V_34 ;
break;
default:
F_9 ( 1 ) ;
V_27 = 0 ;
}
V_26 . V_27 = F_10 ( V_27 ) ;
goto V_35;
}
V_27 = V_36 . V_37 ? V_38 : V_39 ;
V_26 . V_27 = F_10 ( V_27 ) ;
if ( V_40 )
V_26 . V_41 |=
F_10 ( V_42 ) ;
if ( F_11 ( V_3 ) )
V_26 . V_41 |= F_10 ( V_43 ) ;
V_26 . V_41 |= F_10 ( V_44 ) ;
V_35:
memset ( & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
return F_12 ( V_3 , V_45 , 0 , sizeof( V_26 ) , & V_26 ) ;
}
static int F_13 ( struct V_2 * V_3 , T_3 V_46 ,
bool V_47 )
{
struct V_48 V_49 = {} ;
struct V_50 * V_51 ;
T_2 V_52 ;
int V_8 ;
V_51 = F_14 ( V_3 , V_46 ) ;
if ( ! V_51 )
return 0 ;
if ( V_51 -> V_53 == V_47 )
return 0 ;
V_52 = V_51 -> V_46 ;
if ( V_47 )
V_52 |= V_54 ;
F_15 ( V_3 , L_1 ,
V_47 ? L_2 : L_3 , V_46 ) ;
V_49 . V_55 = F_10 ( V_52 ) ;
V_51 -> V_53 = V_47 ;
V_8 = F_12 ( V_3 , V_56 , V_57 ,
sizeof( V_49 ) , & V_49 ) ;
return V_8 ;
}
static inline
void F_16 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_47 , int V_58 )
{
struct V_59 * V_60 = F_17 ( V_5 ) ;
V_60 -> V_61 . V_62 = V_58 ;
V_60 -> V_61 . V_63 =
V_47 ? - V_64 : 0 ;
V_60 -> V_61 . V_65 =
V_47 ? - V_66 : 0 ;
}
static void F_18 ( void * V_67 , T_3 * V_68 ,
struct V_4 * V_5 )
{
struct V_59 * V_60 = F_17 ( V_5 ) ;
struct V_69 * V_70 = V_67 ;
struct V_2 * V_3 = V_70 -> V_3 ;
struct V_6 * V_7 ;
enum V_71 V_72 = V_73 ;
T_2 V_74 ;
int V_75 ;
F_7 ( & V_3 -> V_28 ) ;
switch ( V_5 -> type ) {
case V_76 :
break;
case V_77 :
if ( ! V_60 -> V_78 )
return;
break;
default:
return;
}
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) ) {
if ( V_5 -> type == V_76 ) {
F_19 ( V_3 , V_5 , V_79 ,
V_72 ) ;
F_13 ( V_3 , V_60 -> V_80 ,
false ) ;
F_16 ( V_3 , V_5 , false , 0 ) ;
}
return;
}
V_74 = F_5 ( V_70 -> V_81 -> V_74 ) ;
if ( V_74 >= V_82 )
V_72 = V_83 ;
else if ( V_74 >= V_84 )
V_72 = V_85 ;
if ( ! V_5 -> V_86 . V_87 )
V_72 = V_73 ;
if ( V_60 -> V_88 &&
( V_3 -> V_22 . V_89 & F_20 ( V_60 -> V_88 -> V_90 ) ) )
V_72 = V_73 ;
F_15 ( V_70 -> V_3 ,
L_4 ,
V_60 -> V_90 , V_74 , V_72 ) ;
if ( V_5 -> type == V_76 )
F_19 ( V_3 , V_5 , V_79 ,
V_72 ) ;
if ( F_21 ( V_60 ) ) {
V_70 -> V_91 = true ;
V_70 -> V_92 = V_70 -> V_93 ;
V_70 -> V_93 = V_7 ;
}
if ( V_5 -> type == V_77 ) {
if ( ! V_60 -> V_78 )
return;
if ( V_7 == V_70 -> V_93 )
return;
if ( ! V_70 -> V_91 ) {
V_70 -> V_92 = V_70 -> V_93 ;
V_70 -> V_93 = V_7 ;
} else {
V_70 -> V_92 = V_7 ;
}
return;
}
if ( ! V_70 -> V_93 || V_70 -> V_93 == V_7 )
V_70 -> V_93 = V_7 ;
else if ( ! V_70 -> V_92 )
V_70 -> V_92 = V_7 ;
if ( F_1 ( V_3 , V_5 ) == V_94 ||
V_3 -> V_18 -> V_19 || ! V_5 -> V_86 . V_87 ||
F_5 ( V_3 -> V_22 . V_74 ) == V_95 ) {
F_13 ( V_3 , V_60 -> V_80 , false ) ;
F_16 ( V_3 , V_5 , false , 0 ) ;
return;
}
V_75 = V_60 -> V_61 . V_96 ;
if ( ! V_75 )
V_75 = - 100 ;
if ( V_75 > - V_64 ) {
if ( F_13 ( V_3 , V_60 -> V_80 , true ) )
F_22 ( V_3 , L_5 ) ;
} else if ( V_75 < - V_66 ) {
if ( F_13 ( V_3 , V_60 -> V_80 , false ) )
F_22 ( V_3 , L_5 ) ;
}
F_16 ( V_3 , V_5 , true , V_75 ) ;
}
static void F_23 ( struct V_2 * V_3 )
{
struct V_69 V_70 = {
. V_3 = V_3 ,
. V_81 = & V_3 -> V_22 ,
} ;
struct V_97 V_49 = {} ;
T_3 V_98 ;
if ( F_8 ( V_3 -> V_29 != V_30 ) )
return;
F_2 () ;
F_24 (
V_3 -> V_99 , V_100 ,
F_18 , & V_70 ) ;
if ( V_70 . V_93 ) {
struct V_6 * V_13 = V_70 . V_93 ;
if ( F_9 ( ! V_13 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_101 < V_102 ) {
V_98 = 0 ;
} else {
if ( V_13 -> V_12 . V_103 >
V_13 -> V_12 . V_13 -> V_104 )
V_98 = 2 ;
else
V_98 = 1 ;
}
V_49 . V_105 =
V_106 [ V_13 -> V_12 . V_13 -> V_107 ] [ V_98 ] ;
V_49 . V_10 =
F_10 ( * ( ( T_1 * ) V_70 . V_93 -> V_20 ) ) ;
}
if ( V_70 . V_92 ) {
struct V_6 * V_13 = V_70 . V_92 ;
if ( F_9 ( ! V_70 . V_92 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_101 < V_102 ) {
V_98 = 0 ;
} else {
if ( V_13 -> V_12 . V_103 >
V_13 -> V_12 . V_13 -> V_104 )
V_98 = 2 ;
else
V_98 = 1 ;
}
V_49 . V_108 =
V_106 [ V_13 -> V_12 . V_13 -> V_107 ] [ V_98 ] ;
V_49 . V_11 =
F_10 ( * ( ( T_1 * ) V_70 . V_92 -> V_20 ) ) ;
}
F_4 () ;
if ( memcmp ( & V_49 , & V_3 -> V_21 , sizeof( V_49 ) ) ) {
if ( F_12 ( V_3 , V_109 , 0 ,
sizeof( V_49 ) , & V_49 ) )
F_22 ( V_3 , L_6 ) ;
memcpy ( & V_3 -> V_21 , & V_49 , sizeof( V_49 ) ) ;
}
}
void F_25 ( struct V_2 * V_3 ,
struct V_110 * V_111 )
{
struct V_112 * V_113 = F_26 ( V_111 ) ;
struct V_114 * V_81 = ( void * ) V_113 -> V_70 ;
if ( ! F_27 ( V_3 ) ) {
struct V_115 * V_116 = ( void * ) V_113 -> V_70 ;
V_3 -> V_22 . V_117 [ 0 ] = V_116 -> V_117 [ 0 ] ;
V_3 -> V_22 . V_117 [ 1 ] = V_116 -> V_117 [ 1 ] ;
V_3 -> V_22 . V_117 [ 2 ] = V_116 -> V_117 [ 2 ] ;
V_3 -> V_22 . V_117 [ 3 ] = V_116 -> V_117 [ 3 ] ;
V_3 -> V_22 . V_118 = V_116 -> V_118 ;
V_3 -> V_22 . V_119 = V_116 -> V_119 ;
V_3 -> V_22 . V_23 = V_116 -> V_23 ;
V_3 -> V_22 . V_24 = V_116 -> V_24 ;
V_3 -> V_22 . V_74 =
V_116 -> V_74 ;
V_3 -> V_22 . V_120 = V_116 -> V_120 ;
V_3 -> V_22 . V_89 = V_116 -> V_89 ;
} else {
memcpy ( & V_3 -> V_22 , V_81 , sizeof( V_3 -> V_22 ) ) ;
}
F_15 ( V_3 , L_7 ) ;
F_15 ( V_3 , L_8 ,
V_3 -> V_22 . V_119 ) ;
F_15 ( V_3 , L_9 ,
F_5 ( V_3 -> V_22 . V_23 ) ) ;
F_15 ( V_3 , L_10 ,
F_5 ( V_3 -> V_22 . V_24 ) ) ;
F_15 ( V_3 , L_11 ,
F_5 ( V_3 -> V_22 . V_74 ) ) ;
F_23 ( V_3 ) ;
}
void F_28 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_121 V_122 )
{
struct V_59 * V_60 = F_17 ( V_5 ) ;
int V_8 ;
F_7 ( & V_3 -> V_28 ) ;
if ( F_8 ( V_3 -> V_29 != V_30 ) )
return;
if ( V_60 -> V_80 == V_123 )
return;
if ( F_5 ( V_3 -> V_22 . V_74 ) == V_95 )
return;
F_15 ( V_3 , L_12 , V_5 -> V_86 . V_124 ,
V_122 == V_125 ? L_13 : L_14 ) ;
if ( V_122 == V_126 || V_3 -> V_18 -> V_19 ||
F_1 ( V_3 , V_5 ) == V_94 )
V_8 = F_13 ( V_3 , V_60 -> V_80 ,
false ) ;
else
V_8 = F_13 ( V_3 , V_60 -> V_80 , true ) ;
if ( V_8 )
F_22 ( V_3 , L_15 ) ;
}
T_1 F_29 ( struct V_2 * V_3 ,
struct V_127 * V_128 )
{
struct V_50 * V_51 = F_30 ( V_128 ) ;
struct V_59 * V_60 = F_17 ( V_51 -> V_5 ) ;
struct V_129 * V_88 = V_60 -> V_88 ;
enum V_1 V_130 ;
if ( V_3 -> V_22 . V_120 & F_20 ( V_88 -> V_90 ) )
return V_131 ;
if ( F_5 ( V_3 -> V_22 . V_74 ) <
V_82 )
return V_131 ;
V_130 = F_1 ( V_3 , V_51 -> V_5 ) ;
if ( V_130 == V_94 || V_130 == V_16 )
return V_131 ;
return V_132 ;
}
bool F_31 ( struct V_2 * V_3 ,
struct V_127 * V_128 )
{
struct V_50 * V_51 = F_30 ( V_128 ) ;
struct V_59 * V_60 = F_17 ( V_51 -> V_5 ) ;
struct V_129 * V_88 = V_60 -> V_88 ;
enum V_1 V_130 ;
if ( V_3 -> V_22 . V_120 & F_20 ( V_88 -> V_90 ) )
return true ;
if ( F_5 ( V_3 -> V_22 . V_74 ) <
V_82 )
return true ;
V_130 = F_1 ( V_3 , V_51 -> V_5 ) ;
return V_130 != V_94 ;
}
bool F_32 ( struct V_2 * V_3 , T_3 V_133 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( V_133 & V_3 -> V_18 -> V_134 )
return true ;
return F_5 ( V_3 -> V_22 . V_74 ) <
V_82 ;
}
bool F_33 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
return F_5 ( V_3 -> V_22 . V_74 ) < V_82 ;
}
bool F_34 ( struct V_2 * V_3 ,
enum V_135 V_14 )
{
T_2 V_136 = F_5 ( V_3 -> V_22 . V_74 ) ;
if ( V_14 != V_15 )
return false ;
return V_136 >= V_84 ;
}
T_3 F_35 ( struct V_2 * V_3 , struct V_137 * V_138 ,
struct V_139 * V_140 , T_3 V_141 )
{
T_4 V_142 = V_138 -> V_143 ;
bool V_144 = F_11 ( V_3 ) ;
if ( V_140 -> V_14 != V_15 )
return 0 ;
if ( F_8 ( V_3 -> V_145 ) )
return V_3 -> V_145 - 1 ;
if ( F_36 ( F_37 ( V_142 ) ) ) {
if ( F_36 ( F_38 ( V_142 ) ) ) {
switch ( V_141 ) {
case V_146 :
return V_144 ? 1 : 0 ;
case V_147 :
return V_144 ? 2 : 3 ;
case V_148 :
return 3 ;
default:
return 0 ;
}
} else if ( F_39 ( V_138 -> V_149 ) ) {
return 3 ;
} else
return 0 ;
} else if ( F_40 ( V_142 ) ) {
return F_41 ( V_142 ) ? 0 : 3 ;
} else if ( F_42 ( V_142 ) ) {
return 3 ;
}
return 0 ;
}
void F_43 ( struct V_2 * V_3 )
{
F_23 ( V_3 ) ;
}
