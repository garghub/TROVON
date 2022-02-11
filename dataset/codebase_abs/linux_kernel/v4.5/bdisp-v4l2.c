static inline void F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
unsigned long V_4 ;
F_2 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
V_3 -> V_1 |= V_1 ;
F_3 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
}
static inline void F_4 ( T_1 V_1 , struct V_2 * V_3 )
{
unsigned long V_4 ;
F_2 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
V_3 -> V_1 &= ~ V_1 ;
F_3 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
}
static inline bool F_5 ( T_1 V_7 , struct V_2 * V_3 )
{
unsigned long V_4 ;
bool V_8 ;
F_2 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
V_8 = ( V_3 -> V_1 & V_7 ) == V_7 ;
F_3 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
return V_8 ;
}
static const struct V_9 * F_6 ( T_1 V_10 )
{
const struct V_9 * V_11 ;
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < F_7 ( V_13 ) ; V_12 ++ ) {
V_11 = & V_13 [ V_12 ] ;
if ( V_11 -> V_10 == V_10 )
return V_11 ;
}
return NULL ;
}
static struct V_14 * F_8 ( struct V_2 * V_3 ,
enum V_15 type )
{
switch ( type ) {
case V_16 :
return & V_3 -> V_17 ;
case V_18 :
return & V_3 -> V_19 ;
default:
F_9 ( V_3 -> V_5 -> V_20 ,
L_1 , type ) ;
break;
}
return F_10 ( - V_21 ) ;
}
static void F_11 ( struct V_2 * V_3 , int V_22 )
{
struct V_23 * V_24 , * V_25 ;
if ( F_12 ( ! V_3 || ! V_3 -> V_26 . V_27 , L_2 ) )
return;
F_13 ( V_3 -> V_5 -> V_20 , L_3 , V_28 ) ;
V_24 = F_14 ( V_3 -> V_26 . V_27 ) ;
V_25 = F_15 ( V_3 -> V_26 . V_27 ) ;
if ( V_24 && V_25 ) {
V_25 -> V_29 . V_30 = V_24 -> V_29 . V_30 ;
V_25 -> V_31 = V_24 -> V_31 ;
V_25 -> V_4 &= ~ V_32 ;
V_25 -> V_4 |= V_24 -> V_4 &
V_32 ;
F_16 ( V_24 , V_22 ) ;
F_16 ( V_25 , V_22 ) ;
F_17 ( V_3 -> V_5 -> V_33 . V_34 ,
V_3 -> V_26 . V_27 ) ;
}
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_2 * V_35 ;
struct V_5 * V_36 = V_3 -> V_5 ;
int V_8 ;
F_13 ( V_3 -> V_5 -> V_20 , L_3 , V_28 ) ;
F_19 ( & V_36 -> V_37 ) ;
V_35 = F_20 ( V_36 -> V_33 . V_34 ) ;
if ( ! F_21 ( V_38 , & V_36 -> V_1 ) || ( V_35 != V_3 ) )
return 0 ;
F_1 ( V_39 , V_3 ) ;
V_8 = F_22 ( V_36 -> V_40 ,
! F_5 ( V_39 , V_3 ) ,
V_41 ) ;
if ( ! V_8 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_4 , V_28 ) ;
return - V_42 ;
}
return 0 ;
}
static void F_23 ( struct V_2 * V_3 )
{
int V_8 ;
V_8 = F_18 ( V_3 ) ;
if ( ( V_8 == - V_42 ) || ( V_3 -> V_1 & V_43 ) ) {
F_4 ( V_39 | V_43 ,
V_3 ) ;
F_11 ( V_3 , V_44 ) ;
}
}
static void F_24 ( void * V_45 )
{
F_23 ( (struct V_2 * ) V_45 ) ;
}
static int F_25 ( struct V_2 * V_3 , struct V_46 * V_47 ,
struct V_14 * V_48 , T_2 * V_49 )
{
if ( ! V_47 || ! V_48 )
return - V_21 ;
V_49 [ 0 ] = F_26 ( V_47 , 0 ) ;
if ( V_48 -> V_11 -> V_50 > 1 )
V_49 [ 1 ] = ( T_2 ) ( V_49 [ 0 ] +
V_48 -> V_51 * V_48 -> V_52 ) ;
if ( V_48 -> V_11 -> V_50 > 2 )
V_49 [ 2 ] = ( T_2 ) ( V_49 [ 1 ] +
( V_48 -> V_51 * V_48 -> V_52 ) / 4 ) ;
if ( V_48 -> V_11 -> V_50 > 3 )
F_13 ( V_3 -> V_5 -> V_20 , L_5 ) ;
F_13 ( V_3 -> V_5 -> V_20 ,
L_6 ,
V_28 , & V_49 [ 0 ] , & V_49 [ 1 ] , & V_49 [ 2 ] ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_14 * V_17 , * V_19 ;
struct V_23 * V_24 , * V_25 ;
int V_8 ;
V_17 = & V_3 -> V_17 ;
V_19 = & V_3 -> V_19 ;
V_24 = F_28 ( V_3 -> V_26 . V_27 ) ;
V_8 = F_25 ( V_3 , & V_24 -> V_29 , V_17 , V_17 -> V_49 ) ;
if ( V_8 )
return V_8 ;
V_25 = F_29 ( V_3 -> V_26 . V_27 ) ;
V_8 = F_25 ( V_3 , & V_25 -> V_29 , V_19 , V_19 -> V_49 ) ;
if ( V_8 )
return V_8 ;
V_25 -> V_29 . V_30 = V_24 -> V_29 . V_30 ;
return 0 ;
}
static void F_30 ( void * V_45 )
{
struct V_2 * V_3 = V_45 ;
struct V_5 * V_36 ;
unsigned long V_4 ;
int V_53 = 0 ;
if ( F_12 ( ! V_3 , L_2 ) )
return;
V_36 = V_3 -> V_5 ;
F_13 ( V_36 -> V_20 , L_3 , V_28 ) ;
F_2 ( & V_36 -> V_6 , V_4 ) ;
if ( V_36 -> V_33 . V_3 != V_3 ) {
F_13 ( V_36 -> V_20 , L_7 ,
V_36 -> V_33 . V_3 , V_3 ) ;
V_3 -> V_1 |= V_54 ;
V_36 -> V_33 . V_3 = V_3 ;
}
if ( V_3 -> V_1 & V_39 ) {
V_3 -> V_1 &= ~ V_39 ;
V_3 -> V_1 |= V_43 ;
F_31 ( & V_36 -> V_40 ) ;
goto V_55;
}
V_53 = F_27 ( V_3 ) ;
if ( V_53 ) {
F_9 ( V_36 -> V_20 , L_8 ) ;
goto V_55;
}
F_32 ( V_36 ) ;
V_53 = F_33 ( V_36 ) ;
if ( V_53 ) {
F_9 ( V_36 -> V_20 , L_9 ) ;
goto V_55;
}
V_53 = F_34 ( V_3 ) ;
if ( V_53 ) {
F_9 ( V_36 -> V_20 , L_10 ) ;
goto V_55;
}
F_35 ( V_36 -> V_56 , & V_36 -> V_37 ,
V_41 ) ;
F_36 ( V_38 , & V_36 -> V_1 ) ;
V_55:
V_3 -> V_1 &= ~ V_54 ;
F_3 ( & V_36 -> V_6 , V_4 ) ;
if ( V_53 )
F_11 ( V_3 , V_44 ) ;
}
static int F_37 ( struct V_2 * V_3 , struct V_57 * V_58 )
{
if ( V_58 -> V_4 & V_59 )
return 0 ;
switch ( V_58 -> V_60 ) {
case V_61 :
V_3 -> V_62 = V_58 -> V_63 ;
break;
case V_64 :
V_3 -> V_65 = V_58 -> V_63 ;
break;
default:
F_9 ( V_3 -> V_5 -> V_20 , L_11 , V_58 -> V_60 ) ;
return - V_21 ;
}
V_3 -> V_1 |= V_54 ;
return 0 ;
}
static int F_38 ( struct V_57 * V_58 )
{
struct V_2 * V_3 = F_39 ( V_58 -> V_66 , struct V_2 ,
V_67 ) ;
unsigned long V_4 ;
int V_8 ;
F_2 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
V_8 = F_37 ( V_3 , V_58 ) ;
F_3 ( & V_3 -> V_5 -> V_6 , V_4 ) ;
return V_8 ;
}
static int F_40 ( struct V_2 * V_3 )
{
if ( V_3 -> V_68 )
return 0 ;
F_41 ( & V_3 -> V_67 , V_69 ) ;
V_3 -> V_70 . V_62 = F_42 ( & V_3 -> V_67 ,
& V_71 , V_61 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_70 . V_65 = F_42 ( & V_3 -> V_67 ,
& V_71 , V_64 , 0 , 1 , 1 , 0 ) ;
if ( V_3 -> V_67 . error ) {
int V_53 = V_3 -> V_67 . error ;
F_43 ( & V_3 -> V_67 ) ;
return V_53 ;
}
V_3 -> V_68 = true ;
return 0 ;
}
static void F_44 ( struct V_2 * V_3 )
{
if ( V_3 -> V_68 ) {
F_43 ( & V_3 -> V_67 ) ;
V_3 -> V_68 = false ;
}
}
static int F_45 ( struct V_72 * V_73 ,
unsigned int * V_74 , unsigned int * V_50 ,
unsigned int V_75 [] , void * V_76 [] )
{
struct V_2 * V_3 = F_46 ( V_73 ) ;
struct V_14 * V_48 = F_8 ( V_3 , V_73 -> type ) ;
if ( F_47 ( V_48 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_48 ) ;
return F_48 ( V_48 ) ;
}
if ( ! V_48 -> V_11 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_13 ) ;
return - V_21 ;
}
V_76 [ 0 ] = V_3 -> V_5 -> V_77 ;
if ( * V_50 )
return V_75 [ 0 ] < V_48 -> V_78 ? - V_21 : 0 ;
* V_50 = 1 ;
V_75 [ 0 ] = V_48 -> V_78 ;
return 0 ;
}
static int F_49 ( struct V_46 * V_47 )
{
struct V_2 * V_3 = F_46 ( V_47 -> V_72 ) ;
struct V_14 * V_48 = F_8 ( V_3 , V_47 -> V_72 -> type ) ;
if ( F_47 ( V_48 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_48 ) ;
return F_48 ( V_48 ) ;
}
if ( V_47 -> V_72 -> type == V_18 )
F_50 ( V_47 , 0 , V_48 -> V_78 ) ;
return 0 ;
}
static void F_51 ( struct V_46 * V_47 )
{
struct V_23 * V_79 = F_52 ( V_47 ) ;
struct V_2 * V_3 = F_46 ( V_47 -> V_72 ) ;
if ( ! F_53 ( V_47 , 0 ) ) {
F_13 ( V_3 -> V_5 -> V_20 , L_14 ) ;
F_54 ( V_47 , V_80 ) ;
return;
}
if ( V_3 -> V_26 . V_27 )
F_55 ( V_3 -> V_26 . V_27 , V_79 ) ;
}
static int F_56 ( struct V_72 * V_81 , unsigned int V_82 )
{
struct V_2 * V_3 = V_81 -> V_83 ;
struct V_23 * V_84 ;
int V_8 = F_57 ( V_3 -> V_5 -> V_20 ) ;
if ( V_8 < 0 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_15 ) ;
if ( V_81 -> type == V_16 ) {
while ( ( V_84 = F_14 ( V_3 -> V_26 . V_27 ) ) )
F_16 ( V_84 , V_85 ) ;
} else {
while ( ( V_84 = F_15 ( V_3 -> V_26 . V_27 ) ) )
F_16 ( V_84 , V_85 ) ;
}
return V_8 ;
}
return 0 ;
}
static void F_58 ( struct V_72 * V_81 )
{
struct V_2 * V_3 = V_81 -> V_83 ;
F_23 ( V_3 ) ;
F_59 ( V_3 -> V_5 -> V_20 ) ;
}
static int F_60 ( void * V_45 ,
struct V_72 * V_86 , struct V_72 * V_87 )
{
struct V_2 * V_3 = V_45 ;
int V_8 ;
memset ( V_86 , 0 , sizeof( * V_86 ) ) ;
V_86 -> type = V_16 ;
V_86 -> V_88 = V_89 | V_90 ;
V_86 -> V_83 = V_3 ;
V_86 -> V_91 = & V_92 ;
V_86 -> V_93 = & V_94 ;
V_86 -> V_95 = sizeof( struct V_96 ) ;
V_86 -> V_97 = V_98 ;
V_86 -> V_99 = & V_3 -> V_5 -> V_99 ;
V_8 = F_61 ( V_86 ) ;
if ( V_8 )
return V_8 ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
V_87 -> type = V_18 ;
V_87 -> V_88 = V_89 | V_90 ;
V_87 -> V_83 = V_3 ;
V_87 -> V_91 = & V_92 ;
V_87 -> V_93 = & V_94 ;
V_87 -> V_95 = sizeof( struct V_96 ) ;
V_87 -> V_97 = V_98 ;
V_87 -> V_99 = & V_3 -> V_5 -> V_99 ;
return F_61 ( V_87 ) ;
}
static int F_62 ( struct V_100 * V_100 )
{
struct V_5 * V_36 = F_63 ( V_100 ) ;
struct V_2 * V_3 = NULL ;
int V_8 ;
if ( F_64 ( & V_36 -> V_99 ) )
return - V_101 ;
V_3 = F_65 ( sizeof( * V_3 ) , V_102 ) ;
if ( ! V_3 ) {
V_8 = - V_103 ;
goto V_104;
}
V_3 -> V_5 = V_36 ;
if ( F_66 ( V_3 ) ) {
F_9 ( V_36 -> V_20 , L_16 ) ;
V_8 = - V_103 ;
goto V_105;
}
F_67 ( & V_3 -> V_26 , V_36 -> V_33 . V_106 ) ;
V_8 = F_40 ( V_3 ) ;
if ( V_8 ) {
F_9 ( V_36 -> V_20 , L_17 ) ;
goto V_107;
}
V_3 -> V_26 . V_67 = & V_3 -> V_67 ;
V_100 -> V_108 = & V_3 -> V_26 ;
F_68 ( & V_3 -> V_26 ) ;
V_3 -> V_17 = V_109 ;
V_3 -> V_19 = V_109 ;
V_3 -> V_26 . V_27 = F_69 ( V_36 -> V_33 . V_34 , V_3 ,
F_60 ) ;
if ( F_47 ( V_3 -> V_26 . V_27 ) ) {
F_9 ( V_36 -> V_20 , L_18 ) ;
V_8 = F_48 ( V_3 -> V_26 . V_27 ) ;
goto V_110;
}
V_36 -> V_33 . V_111 ++ ;
F_36 ( V_112 , & V_36 -> V_1 ) ;
F_13 ( V_36 -> V_20 , L_19 , V_3 ) ;
F_70 ( & V_36 -> V_99 ) ;
return 0 ;
V_110:
F_44 ( V_3 ) ;
V_107:
F_71 ( & V_3 -> V_26 ) ;
F_72 ( & V_3 -> V_26 ) ;
F_73 ( V_3 ) ;
V_105:
F_74 ( V_3 ) ;
V_104:
F_70 ( & V_36 -> V_99 ) ;
return V_8 ;
}
static int F_75 ( struct V_100 * V_100 )
{
struct V_2 * V_3 = F_76 ( V_100 -> V_108 ) ;
struct V_5 * V_36 = V_3 -> V_5 ;
F_13 ( V_36 -> V_20 , L_3 , V_28 ) ;
if ( F_64 ( & V_36 -> V_99 ) )
return - V_101 ;
F_77 ( V_3 -> V_26 . V_27 ) ;
F_44 ( V_3 ) ;
F_71 ( & V_3 -> V_26 ) ;
F_72 ( & V_3 -> V_26 ) ;
if ( -- V_36 -> V_33 . V_111 <= 0 )
F_78 ( V_112 , & V_36 -> V_1 ) ;
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
F_70 ( & V_36 -> V_99 ) ;
return 0 ;
}
static int F_79 ( struct V_100 * V_100 , void * V_26 ,
struct V_113 * V_114 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_5 * V_36 = V_3 -> V_5 ;
F_80 ( V_114 -> V_115 , V_36 -> V_116 -> V_117 , sizeof( V_114 -> V_115 ) ) ;
F_80 ( V_114 -> V_118 , V_36 -> V_116 -> V_117 , sizeof( V_114 -> V_118 ) ) ;
snprintf ( V_114 -> V_119 , sizeof( V_114 -> V_119 ) , L_20 ,
V_120 , V_36 -> V_60 ) ;
V_114 -> V_121 = V_122 | V_123 ;
V_114 -> V_124 = V_114 -> V_121 | V_125 ;
return 0 ;
}
static int F_81 ( struct V_100 * V_100 , void * V_26 , struct V_126 * V_127 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
const struct V_9 * V_11 ;
if ( V_127 -> V_128 >= F_7 ( V_13 ) )
return - V_21 ;
V_11 = & V_13 [ V_127 -> V_128 ] ;
if ( ( V_11 -> V_10 == V_129 ) &&
( V_127 -> type == V_18 ) ) {
F_13 ( V_3 -> V_5 -> V_20 , L_21 ) ;
return - V_21 ;
}
V_127 -> V_10 = V_11 -> V_10 ;
return 0 ;
}
static int F_82 ( struct V_100 * V_100 , void * V_26 , struct V_130 * V_127 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_131 * V_132 = & V_127 -> V_11 . V_132 ;
struct V_14 * V_48 = F_8 ( V_3 , V_127 -> type ) ;
if ( F_47 ( V_48 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_48 ) ;
return F_48 ( V_48 ) ;
}
V_132 = & V_127 -> V_11 . V_132 ;
V_132 -> V_133 = V_48 -> V_133 ;
V_132 -> V_52 = V_48 -> V_52 ;
V_132 -> V_10 = V_48 -> V_11 -> V_10 ;
V_132 -> V_134 = V_48 -> V_134 ;
V_132 -> V_51 = V_48 -> V_51 ;
V_132 -> V_78 = V_48 -> V_78 ;
V_132 -> V_135 = ( V_127 -> type == V_16 ) ?
V_48 -> V_135 : V_109 . V_135 ;
return 0 ;
}
static int F_83 ( struct V_100 * V_100 , void * V_26 , struct V_130 * V_127 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_131 * V_132 = & V_127 -> V_11 . V_132 ;
const struct V_9 * V_136 ;
T_1 V_137 , V_138 ;
V_136 = F_6 ( V_132 -> V_10 ) ;
if ( ! V_136 ) {
F_13 ( V_3 -> V_5 -> V_20 , L_22 ,
V_132 -> V_10 ) ;
return - V_21 ;
}
if ( ( V_136 -> V_10 == V_129 ) &&
( V_127 -> type == V_18 ) ) {
F_13 ( V_3 -> V_5 -> V_20 , L_21 ) ;
return - V_21 ;
}
if ( ( V_127 -> type == V_18 ) ||
( V_132 -> V_134 != V_139 ) )
V_132 -> V_134 = V_140 ;
V_137 = V_132 -> V_133 ;
V_138 = V_132 -> V_52 ;
F_84 ( & V_132 -> V_133 ,
V_141 , V_142 ,
F_85 ( V_136 -> V_143 ) - 1 ,
& V_132 -> V_52 ,
V_144 , V_145 ,
F_85 ( V_136 -> V_146 ) - 1 ,
0 ) ;
if ( ( V_132 -> V_133 != V_137 ) || ( V_132 -> V_52 != V_138 ) )
F_13 ( V_3 -> V_5 -> V_20 ,
L_23 , V_28 ,
V_137 , V_138 , V_132 -> V_133 , V_132 -> V_52 ) ;
V_132 -> V_51 = ( V_132 -> V_133 * V_136 -> V_147 ) / 8 ;
V_132 -> V_78 = ( V_132 -> V_133 * V_132 -> V_52 * V_136 -> V_148 ) / 8 ;
if ( V_127 -> type == V_18 )
V_132 -> V_135 = V_109 . V_135 ;
return 0 ;
}
static int F_86 ( struct V_100 * V_100 , void * V_26 , struct V_130 * V_127 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_72 * V_73 ;
struct V_14 * V_48 ;
struct V_131 * V_132 ;
int V_8 ;
T_1 V_1 ;
V_8 = F_83 ( V_100 , V_26 , V_127 ) ;
if ( V_8 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_24 ) ;
return V_8 ;
}
V_73 = F_87 ( V_3 -> V_26 . V_27 , V_127 -> type ) ;
if ( F_88 ( V_73 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_25 , V_127 -> type ) ;
return - V_149 ;
}
V_48 = ( V_127 -> type == V_16 ) ?
& V_3 -> V_17 : & V_3 -> V_19 ;
V_132 = & V_127 -> V_11 . V_132 ;
V_48 -> V_11 = F_6 ( V_132 -> V_10 ) ;
if ( ! V_48 -> V_11 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_22 ,
V_132 -> V_10 ) ;
return - V_21 ;
}
V_48 -> V_133 = V_132 -> V_133 ;
V_48 -> V_52 = V_132 -> V_52 ;
V_48 -> V_51 = V_132 -> V_51 ;
V_48 -> V_78 = V_132 -> V_78 ;
V_48 -> V_134 = V_132 -> V_134 ;
if ( V_127 -> type == V_16 )
V_48 -> V_135 = V_132 -> V_135 ;
V_48 -> V_150 . V_133 = V_48 -> V_133 ;
V_48 -> V_150 . V_52 = V_48 -> V_52 ;
V_48 -> V_150 . V_151 = 0 ;
V_48 -> V_150 . V_152 = 0 ;
V_1 = V_54 ;
V_1 |= ( V_127 -> type == V_18 ) ?
V_153 : V_154 ;
F_1 ( V_1 , V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_100 * V_100 , void * V_26 ,
struct V_155 * V_156 )
{
struct V_14 * V_48 ;
struct V_2 * V_3 = F_76 ( V_26 ) ;
V_48 = F_8 ( V_3 , V_156 -> type ) ;
if ( F_47 ( V_48 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_48 ) ;
return F_48 ( V_48 ) ;
}
switch ( V_156 -> type ) {
case V_16 :
switch ( V_156 -> V_157 ) {
case V_158 :
V_156 -> V_159 = V_48 -> V_150 ;
break;
case V_160 :
case V_161 :
V_156 -> V_159 . V_151 = 0 ;
V_156 -> V_159 . V_152 = 0 ;
V_156 -> V_159 . V_133 = V_48 -> V_133 ;
V_156 -> V_159 . V_52 = V_48 -> V_52 ;
break;
default:
F_9 ( V_3 -> V_5 -> V_20 , L_26 ) ;
return - V_21 ;
}
break;
case V_18 :
switch ( V_156 -> V_157 ) {
case V_162 :
case V_163 :
V_156 -> V_159 = V_48 -> V_150 ;
break;
case V_164 :
case V_165 :
V_156 -> V_159 . V_151 = 0 ;
V_156 -> V_159 . V_152 = 0 ;
V_156 -> V_159 . V_133 = V_48 -> V_133 ;
V_156 -> V_159 . V_52 = V_48 -> V_52 ;
break;
default:
F_9 ( V_3 -> V_5 -> V_20 , L_26 ) ;
return - V_21 ;
}
break;
default:
F_9 ( V_3 -> V_5 -> V_20 , L_27 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_90 ( struct V_166 * V_167 , struct V_166 * V_168 )
{
if ( V_167 -> V_151 < V_168 -> V_151 || V_167 -> V_152 < V_168 -> V_152 )
return 0 ;
if ( V_167 -> V_151 + V_167 -> V_133 > V_168 -> V_151 + V_168 -> V_133 )
return 0 ;
if ( V_167 -> V_152 + V_167 -> V_52 > V_168 -> V_152 + V_168 -> V_52 )
return 0 ;
return 1 ;
}
static int F_91 ( struct V_100 * V_100 , void * V_26 ,
struct V_155 * V_156 )
{
struct V_14 * V_48 ;
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_166 * V_169 , V_55 ;
bool V_170 = false ;
if ( ( V_156 -> type == V_16 ) &&
( V_156 -> V_157 == V_158 ) )
V_170 = true ;
if ( ( V_156 -> type == V_18 ) &&
( V_156 -> V_157 == V_162 ) )
V_170 = true ;
if ( ! V_170 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_28 ) ;
return - V_21 ;
}
V_48 = F_8 ( V_3 , V_156 -> type ) ;
if ( F_47 ( V_48 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_48 ) ;
return F_48 ( V_48 ) ;
}
V_169 = & V_156 -> V_159 ;
V_55 = * V_169 ;
V_55 . V_151 = F_92 ( V_169 -> V_151 , V_48 -> V_11 -> V_143 ) ;
V_55 . V_152 = F_92 ( V_169 -> V_152 , V_48 -> V_11 -> V_146 ) ;
if ( ( V_55 . V_151 < 0 ) || ( V_55 . V_151 >= V_48 -> V_133 ) ||
( V_55 . V_152 < 0 ) || ( V_55 . V_152 >= V_48 -> V_52 ) ) {
F_9 ( V_3 -> V_5 -> V_20 ,
L_29 ,
V_55 . V_133 , V_55 . V_52 , V_55 . V_151 , V_55 . V_152 ,
V_48 -> V_133 , V_48 -> V_52 ) ;
return - V_21 ;
}
V_55 . V_133 = F_92 ( V_169 -> V_133 , V_48 -> V_11 -> V_143 ) ;
V_55 . V_52 = F_92 ( V_169 -> V_52 , V_48 -> V_11 -> V_143 ) ;
if ( ( ( V_55 . V_151 + V_55 . V_133 ) > V_48 -> V_133 ) ||
( ( V_55 . V_152 + V_55 . V_52 ) > V_48 -> V_52 ) ) {
F_9 ( V_3 -> V_5 -> V_20 ,
L_29 ,
V_55 . V_133 , V_55 . V_52 , V_55 . V_151 , V_55 . V_152 ,
V_48 -> V_133 , V_48 -> V_52 ) ;
return - V_21 ;
}
if ( V_156 -> V_4 & V_171 && ! F_90 ( & V_55 , V_169 ) )
return - V_172 ;
if ( V_156 -> V_4 & V_173 && ! F_90 ( V_169 , & V_55 ) )
return - V_172 ;
if ( ( V_55 . V_151 != V_169 -> V_151 ) || ( V_55 . V_152 != V_169 -> V_152 ) ||
( V_55 . V_133 != V_169 -> V_133 ) || ( V_55 . V_52 != V_169 -> V_52 ) ) {
F_13 ( V_3 -> V_5 -> V_20 ,
L_30 ,
V_28 , V_169 -> V_133 , V_169 -> V_52 , V_169 -> V_151 , V_169 -> V_152 ,
V_55 . V_133 , V_55 . V_52 , V_55 . V_151 , V_55 . V_152 ) ;
* V_169 = V_55 ;
}
V_48 -> V_150 = V_55 ;
F_1 ( V_54 , V_3 ) ;
return 0 ;
}
static int F_93 ( struct V_100 * V_100 , void * V_26 , enum V_15 type )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
if ( ( type == V_16 ) &&
! F_5 ( V_154 , V_3 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_31 ) ;
return - V_21 ;
}
if ( ( type == V_18 ) &&
! F_5 ( V_153 , V_3 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_32 ) ;
return - V_21 ;
}
return F_94 ( V_100 , V_3 -> V_26 . V_27 , type ) ;
}
static int F_95 ( struct V_5 * V_36 )
{
int V_8 ;
if ( ! V_36 )
return - V_174 ;
V_36 -> V_106 . V_175 = & V_176 ;
V_36 -> V_106 . V_177 = & V_178 ;
V_36 -> V_106 . V_179 = V_180 ;
V_36 -> V_106 . V_99 = & V_36 -> V_99 ;
V_36 -> V_106 . V_181 = V_182 ;
V_36 -> V_106 . V_183 = & V_36 -> V_183 ;
snprintf ( V_36 -> V_106 . V_117 , sizeof( V_36 -> V_106 . V_117 ) , L_33 ,
V_120 , V_36 -> V_60 ) ;
F_96 ( & V_36 -> V_106 , V_36 ) ;
V_36 -> V_33 . V_106 = & V_36 -> V_106 ;
V_36 -> V_33 . V_34 = F_97 ( & V_184 ) ;
if ( F_47 ( V_36 -> V_33 . V_34 ) ) {
F_9 ( V_36 -> V_20 , L_34 ) ;
return F_48 ( V_36 -> V_33 . V_34 ) ;
}
V_8 = F_98 ( & V_36 -> V_106 , V_185 , - 1 ) ;
if ( V_8 ) {
F_9 ( V_36 -> V_20 ,
L_35 , V_28 ) ;
F_99 ( V_36 -> V_33 . V_34 ) ;
return V_8 ;
}
return 0 ;
}
static void F_100 ( struct V_5 * V_36 )
{
if ( ! V_36 )
return;
if ( V_36 -> V_33 . V_34 )
F_99 ( V_36 -> V_33 . V_34 ) ;
F_101 ( V_36 -> V_33 . V_106 ) ;
}
static T_3 F_102 ( int V_186 , void * V_45 )
{
struct V_5 * V_36 = V_45 ;
struct V_2 * V_3 ;
F_103 ( & V_36 -> V_6 ) ;
F_104 ( V_36 ) ;
F_19 ( & V_36 -> V_37 ) ;
if ( ! F_105 ( V_38 , & V_36 -> V_1 ) )
goto V_187;
if ( F_105 ( V_188 , & V_36 -> V_1 ) ) {
F_36 ( V_189 , & V_36 -> V_1 ) ;
F_31 ( & V_36 -> V_40 ) ;
goto V_187;
}
V_3 = F_20 ( V_36 -> V_33 . V_34 ) ;
if ( ! V_3 || ! V_3 -> V_26 . V_27 )
goto V_187;
F_106 ( & V_36 -> V_6 ) ;
F_11 ( V_3 , V_80 ) ;
if ( F_5 ( V_39 , V_3 ) ) {
F_4 ( V_39 , V_3 ) ;
F_31 ( & V_36 -> V_40 ) ;
}
return V_190 ;
V_187:
F_106 ( & V_36 -> V_6 ) ;
return V_190 ;
}
static T_3 F_107 ( int V_186 , void * V_45 )
{
if ( F_108 ( (struct V_5 * ) V_45 ) )
return V_191 ;
else
return V_192 ;
}
static void F_109 ( struct V_193 * V_194 )
{
struct V_195 * V_196 = F_110 ( V_194 ) ;
struct V_5 * V_36 = F_39 ( V_196 , struct V_5 ,
V_37 ) ;
struct V_2 * V_3 ;
V_3 = F_20 ( V_36 -> V_33 . V_34 ) ;
F_9 ( V_3 -> V_5 -> V_20 , L_36 ) ;
F_103 ( & V_36 -> V_6 ) ;
F_78 ( V_38 , & V_36 -> V_1 ) ;
F_106 ( & V_36 -> V_6 ) ;
F_33 ( V_36 ) ;
F_11 ( V_3 , V_44 ) ;
}
static int F_111 ( struct V_5 * V_36 )
{
unsigned long V_4 ;
int V_197 ;
F_2 ( & V_36 -> V_6 , V_4 ) ;
if ( ! F_21 ( V_38 , & V_36 -> V_1 ) ) {
F_3 ( & V_36 -> V_6 , V_4 ) ;
return 0 ;
}
F_78 ( V_189 , & V_36 -> V_1 ) ;
F_36 ( V_188 , & V_36 -> V_1 ) ;
F_3 ( & V_36 -> V_6 , V_4 ) ;
V_197 = F_22 ( V_36 -> V_40 ,
F_21 ( V_189 , & V_36 -> V_1 ) ,
V_41 ) ;
F_78 ( V_188 , & V_36 -> V_1 ) ;
if ( ! V_197 ) {
F_9 ( V_36 -> V_20 , L_4 , V_28 ) ;
return - V_198 ;
}
return 0 ;
}
static int F_112 ( struct V_5 * V_36 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
F_2 ( & V_36 -> V_6 , V_4 ) ;
V_3 = V_36 -> V_33 . V_3 ;
V_36 -> V_33 . V_3 = NULL ;
F_3 ( & V_36 -> V_6 , V_4 ) ;
if ( F_105 ( V_189 , & V_36 -> V_1 ) )
F_11 ( V_3 , V_44 ) ;
return 0 ;
}
static int F_113 ( struct V_199 * V_20 )
{
struct V_5 * V_36 = F_114 ( V_20 ) ;
int V_8 = F_115 ( V_36 -> clock ) ;
if ( V_8 )
return V_8 ;
return F_112 ( V_36 ) ;
}
static int F_116 ( struct V_199 * V_20 )
{
struct V_5 * V_36 = F_114 ( V_20 ) ;
int V_8 = F_111 ( V_36 ) ;
if ( ! V_8 )
F_117 ( V_36 -> clock ) ;
return V_8 ;
}
static int F_118 ( struct V_199 * V_20 )
{
struct V_5 * V_36 = F_114 ( V_20 ) ;
unsigned long V_4 ;
int V_200 ;
F_2 ( & V_36 -> V_6 , V_4 ) ;
V_200 = F_21 ( V_112 , & V_36 -> V_1 ) ;
F_3 ( & V_36 -> V_6 , V_4 ) ;
if ( ! V_200 )
return 0 ;
if ( ! F_119 ( V_20 ) )
return F_113 ( V_20 ) ;
return 0 ;
}
static int F_120 ( struct V_199 * V_20 )
{
if ( ! F_119 ( V_20 ) )
return F_116 ( V_20 ) ;
return 0 ;
}
static int F_121 ( struct V_201 * V_116 )
{
struct V_5 * V_36 = F_122 ( V_116 ) ;
F_100 ( V_36 ) ;
F_123 ( V_36 -> V_20 ) ;
F_124 ( V_36 -> V_77 ) ;
F_125 ( & V_116 -> V_20 ) ;
F_126 ( V_36 ) ;
F_127 ( & V_36 -> V_183 ) ;
if ( ! F_47 ( V_36 -> clock ) )
F_128 ( V_36 -> clock ) ;
F_13 ( & V_116 -> V_20 , L_37 , V_116 -> V_117 ) ;
return 0 ;
}
static int F_129 ( struct V_201 * V_116 )
{
struct V_5 * V_36 ;
struct V_202 * V_203 ;
struct V_199 * V_20 = & V_116 -> V_20 ;
int V_8 ;
F_13 ( V_20 , L_3 , V_28 ) ;
V_36 = F_130 ( V_20 , sizeof( struct V_5 ) , V_102 ) ;
if ( ! V_36 )
return - V_103 ;
V_36 -> V_116 = V_116 ;
V_36 -> V_20 = V_20 ;
F_131 ( V_116 , V_36 ) ;
if ( V_20 -> V_204 )
V_36 -> V_60 = F_132 ( V_116 -> V_20 . V_204 , V_120 ) ;
else
V_36 -> V_60 = V_116 -> V_60 ;
F_133 ( & V_36 -> V_40 ) ;
F_134 ( & V_36 -> V_37 , F_109 ) ;
V_36 -> V_56 = F_135 ( V_120 ) ;
F_136 ( & V_36 -> V_6 ) ;
F_137 ( & V_36 -> V_99 ) ;
V_203 = F_138 ( V_116 , V_205 , 0 ) ;
V_36 -> V_206 = F_139 ( V_20 , V_203 ) ;
if ( F_47 ( V_36 -> V_206 ) ) {
F_9 ( V_20 , L_38 ) ;
return F_48 ( V_36 -> V_206 ) ;
}
V_36 -> clock = F_140 ( V_20 , V_120 ) ;
if ( F_47 ( V_36 -> clock ) ) {
F_9 ( V_20 , L_39 ) ;
return F_48 ( V_36 -> clock ) ;
}
V_8 = F_141 ( V_36 -> clock ) ;
if ( V_8 < 0 ) {
F_9 ( V_20 , L_40 ) ;
V_36 -> clock = F_10 ( - V_21 ) ;
return V_8 ;
}
V_203 = F_138 ( V_116 , V_207 , 0 ) ;
if ( ! V_203 ) {
F_9 ( V_20 , L_41 ) ;
goto V_208;
}
V_8 = F_142 ( V_20 , V_203 -> V_209 , F_107 ,
F_102 , V_210 ,
V_116 -> V_117 , V_36 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_42 ) ;
goto V_208;
}
V_8 = F_143 ( V_20 , & V_36 -> V_183 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_43 ) ;
goto V_208;
}
V_8 = F_144 ( V_36 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_44 ) ;
goto V_211;
}
F_145 ( V_20 ) ;
V_8 = F_57 ( V_20 ) ;
if ( V_8 < 0 ) {
F_9 ( V_20 , L_45 ) ;
goto V_212;
}
V_36 -> V_77 = F_146 ( V_20 ) ;
if ( F_47 ( V_36 -> V_77 ) ) {
V_8 = F_48 ( V_36 -> V_77 ) ;
goto V_213;
}
if ( F_147 ( V_36 -> V_20 ) ) {
F_9 ( V_36 -> V_20 , L_46 ) ;
V_8 = - V_103 ;
goto V_214;
}
V_8 = F_95 ( V_36 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_43 ) ;
goto V_215;
}
F_148 ( V_20 , L_47 , V_120 ,
V_36 -> V_60 , V_36 -> V_106 . V_216 ) ;
F_59 ( V_20 ) ;
return 0 ;
V_215:
F_123 ( V_36 -> V_20 ) ;
V_214:
F_124 ( V_36 -> V_77 ) ;
V_213:
F_59 ( V_20 ) ;
V_212:
F_126 ( V_36 ) ;
V_211:
F_127 ( & V_36 -> V_183 ) ;
V_208:
if ( ! F_47 ( V_36 -> clock ) )
F_128 ( V_36 -> clock ) ;
return V_8 ;
}
