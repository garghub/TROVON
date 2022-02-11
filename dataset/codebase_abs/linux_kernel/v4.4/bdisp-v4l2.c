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
V_25 -> V_29 = V_24 -> V_29 ;
V_25 -> V_30 = V_24 -> V_30 ;
V_25 -> V_4 &= ~ V_31 ;
V_25 -> V_4 |= V_24 -> V_4 &
V_31 ;
F_16 ( V_24 , V_22 ) ;
F_16 ( V_25 , V_22 ) ;
F_17 ( V_3 -> V_5 -> V_32 . V_33 ,
V_3 -> V_26 . V_27 ) ;
}
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_2 * V_34 ;
struct V_5 * V_35 = V_3 -> V_5 ;
int V_8 ;
F_13 ( V_3 -> V_5 -> V_20 , L_3 , V_28 ) ;
F_19 ( & V_35 -> V_36 ) ;
V_34 = F_20 ( V_35 -> V_32 . V_33 ) ;
if ( ! F_21 ( V_37 , & V_35 -> V_1 ) || ( V_34 != V_3 ) )
return 0 ;
F_1 ( V_38 , V_3 ) ;
V_8 = F_22 ( V_35 -> V_39 ,
! F_5 ( V_38 , V_3 ) ,
V_40 ) ;
if ( ! V_8 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_4 , V_28 ) ;
return - V_41 ;
}
return 0 ;
}
static void F_23 ( struct V_2 * V_3 )
{
int V_8 ;
V_8 = F_18 ( V_3 ) ;
if ( ( V_8 == - V_41 ) || ( V_3 -> V_1 & V_42 ) ) {
F_4 ( V_38 | V_42 ,
V_3 ) ;
F_11 ( V_3 , V_43 ) ;
}
}
static void F_24 ( void * V_44 )
{
F_23 ( (struct V_2 * ) V_44 ) ;
}
static int F_25 ( struct V_2 * V_3 , struct V_45 * V_46 ,
struct V_14 * V_47 , T_2 * V_48 )
{
if ( ! V_46 || ! V_47 )
return - V_21 ;
V_48 [ 0 ] = F_26 ( V_46 , 0 ) ;
if ( V_47 -> V_11 -> V_49 > 1 )
V_48 [ 1 ] = ( T_2 ) ( V_48 [ 0 ] +
V_47 -> V_50 * V_47 -> V_51 ) ;
if ( V_47 -> V_11 -> V_49 > 2 )
V_48 [ 2 ] = ( T_2 ) ( V_48 [ 1 ] +
( V_47 -> V_50 * V_47 -> V_51 ) / 4 ) ;
if ( V_47 -> V_11 -> V_49 > 3 )
F_13 ( V_3 -> V_5 -> V_20 , L_5 ) ;
F_13 ( V_3 -> V_5 -> V_20 ,
L_6 ,
V_28 , & V_48 [ 0 ] , & V_48 [ 1 ] , & V_48 [ 2 ] ) ;
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
V_8 = F_25 ( V_3 , & V_24 -> V_52 , V_17 , V_17 -> V_48 ) ;
if ( V_8 )
return V_8 ;
V_25 = F_29 ( V_3 -> V_26 . V_27 ) ;
V_8 = F_25 ( V_3 , & V_25 -> V_52 , V_19 , V_19 -> V_48 ) ;
if ( V_8 )
return V_8 ;
V_25 -> V_29 = V_24 -> V_29 ;
return 0 ;
}
static void F_30 ( void * V_44 )
{
struct V_2 * V_3 = V_44 ;
struct V_5 * V_35 ;
unsigned long V_4 ;
int V_53 = 0 ;
if ( F_12 ( ! V_3 , L_2 ) )
return;
V_35 = V_3 -> V_5 ;
F_13 ( V_35 -> V_20 , L_3 , V_28 ) ;
F_2 ( & V_35 -> V_6 , V_4 ) ;
if ( V_35 -> V_32 . V_3 != V_3 ) {
F_13 ( V_35 -> V_20 , L_7 ,
V_35 -> V_32 . V_3 , V_3 ) ;
V_3 -> V_1 |= V_54 ;
V_35 -> V_32 . V_3 = V_3 ;
}
if ( V_3 -> V_1 & V_38 ) {
V_3 -> V_1 &= ~ V_38 ;
V_3 -> V_1 |= V_42 ;
F_31 ( & V_35 -> V_39 ) ;
goto V_55;
}
V_53 = F_27 ( V_3 ) ;
if ( V_53 ) {
F_9 ( V_35 -> V_20 , L_8 ) ;
goto V_55;
}
F_32 ( V_35 ) ;
V_53 = F_33 ( V_35 ) ;
if ( V_53 ) {
F_9 ( V_35 -> V_20 , L_9 ) ;
goto V_55;
}
V_53 = F_34 ( V_3 ) ;
if ( V_53 ) {
F_9 ( V_35 -> V_20 , L_10 ) ;
goto V_55;
}
F_35 ( V_35 -> V_56 , & V_35 -> V_36 ,
V_40 ) ;
F_36 ( V_37 , & V_35 -> V_1 ) ;
V_55:
V_3 -> V_1 &= ~ V_54 ;
F_3 ( & V_35 -> V_6 , V_4 ) ;
if ( V_53 )
F_11 ( V_3 , V_43 ) ;
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
const void * V_74 ,
unsigned int * V_75 , unsigned int * V_49 ,
unsigned int V_76 [] , void * V_77 [] )
{
const struct V_78 * V_11 = V_74 ;
struct V_2 * V_3 = F_46 ( V_73 ) ;
struct V_14 * V_47 = F_8 ( V_3 , V_73 -> type ) ;
if ( F_47 ( V_47 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_47 ) ;
return F_48 ( V_47 ) ;
}
if ( ! V_47 -> V_11 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_13 ) ;
return - V_21 ;
}
if ( V_11 && V_11 -> V_11 . V_79 . V_80 < V_47 -> V_80 )
return - V_21 ;
* V_49 = 1 ;
V_76 [ 0 ] = V_11 ? V_11 -> V_11 . V_79 . V_80 : V_47 -> V_80 ;
V_77 [ 0 ] = V_3 -> V_5 -> V_81 ;
return 0 ;
}
static int F_49 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_46 ( V_46 -> V_72 ) ;
struct V_14 * V_47 = F_8 ( V_3 , V_46 -> V_72 -> type ) ;
if ( F_47 ( V_47 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_47 ) ;
return F_48 ( V_47 ) ;
}
if ( V_46 -> V_72 -> type == V_18 )
F_50 ( V_46 , 0 , V_47 -> V_80 ) ;
return 0 ;
}
static void F_51 ( struct V_45 * V_46 )
{
struct V_23 * V_82 = F_52 ( V_46 ) ;
struct V_2 * V_3 = F_46 ( V_46 -> V_72 ) ;
if ( ! F_53 ( V_46 , 0 ) ) {
F_13 ( V_3 -> V_5 -> V_20 , L_14 ) ;
F_54 ( V_46 , V_83 ) ;
return;
}
if ( V_3 -> V_26 . V_27 )
F_55 ( V_3 -> V_26 . V_27 , V_82 ) ;
}
static int F_56 ( struct V_72 * V_84 , unsigned int V_85 )
{
struct V_2 * V_3 = V_84 -> V_86 ;
struct V_23 * V_87 ;
int V_8 = F_57 ( V_3 -> V_5 -> V_20 ) ;
if ( V_8 < 0 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_15 ) ;
if ( V_84 -> type == V_16 ) {
while ( ( V_87 = F_14 ( V_3 -> V_26 . V_27 ) ) )
F_16 ( V_87 , V_88 ) ;
} else {
while ( ( V_87 = F_15 ( V_3 -> V_26 . V_27 ) ) )
F_16 ( V_87 , V_88 ) ;
}
return V_8 ;
}
return 0 ;
}
static void F_58 ( struct V_72 * V_84 )
{
struct V_2 * V_3 = V_84 -> V_86 ;
F_23 ( V_3 ) ;
F_59 ( V_3 -> V_5 -> V_20 ) ;
}
static int F_60 ( void * V_44 ,
struct V_72 * V_89 , struct V_72 * V_90 )
{
struct V_2 * V_3 = V_44 ;
int V_8 ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
V_89 -> type = V_16 ;
V_89 -> V_91 = V_92 | V_93 ;
V_89 -> V_86 = V_3 ;
V_89 -> V_94 = & V_95 ;
V_89 -> V_96 = & V_97 ;
V_89 -> V_98 = sizeof( struct V_99 ) ;
V_89 -> V_100 = V_101 ;
V_89 -> V_102 = & V_3 -> V_5 -> V_102 ;
V_8 = F_61 ( V_89 ) ;
if ( V_8 )
return V_8 ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
V_90 -> type = V_18 ;
V_90 -> V_91 = V_92 | V_93 ;
V_90 -> V_86 = V_3 ;
V_90 -> V_94 = & V_95 ;
V_90 -> V_96 = & V_97 ;
V_90 -> V_98 = sizeof( struct V_99 ) ;
V_90 -> V_100 = V_101 ;
V_90 -> V_102 = & V_3 -> V_5 -> V_102 ;
return F_61 ( V_90 ) ;
}
static int F_62 ( struct V_103 * V_103 )
{
struct V_5 * V_35 = F_63 ( V_103 ) ;
struct V_2 * V_3 = NULL ;
int V_8 ;
if ( F_64 ( & V_35 -> V_102 ) )
return - V_104 ;
V_3 = F_65 ( sizeof( * V_3 ) , V_105 ) ;
if ( ! V_3 ) {
V_8 = - V_106 ;
goto V_107;
}
V_3 -> V_5 = V_35 ;
if ( F_66 ( V_3 ) ) {
F_9 ( V_35 -> V_20 , L_16 ) ;
V_8 = - V_106 ;
goto V_108;
}
F_67 ( & V_3 -> V_26 , V_35 -> V_32 . V_109 ) ;
V_8 = F_40 ( V_3 ) ;
if ( V_8 ) {
F_9 ( V_35 -> V_20 , L_17 ) ;
goto V_110;
}
V_3 -> V_26 . V_67 = & V_3 -> V_67 ;
V_103 -> V_111 = & V_3 -> V_26 ;
F_68 ( & V_3 -> V_26 ) ;
V_3 -> V_17 = V_112 ;
V_3 -> V_19 = V_112 ;
V_3 -> V_26 . V_27 = F_69 ( V_35 -> V_32 . V_33 , V_3 ,
F_60 ) ;
if ( F_47 ( V_3 -> V_26 . V_27 ) ) {
F_9 ( V_35 -> V_20 , L_18 ) ;
V_8 = F_48 ( V_3 -> V_26 . V_27 ) ;
goto V_113;
}
V_35 -> V_32 . V_114 ++ ;
F_36 ( V_115 , & V_35 -> V_1 ) ;
F_13 ( V_35 -> V_20 , L_19 , V_3 ) ;
F_70 ( & V_35 -> V_102 ) ;
return 0 ;
V_113:
F_44 ( V_3 ) ;
V_110:
F_71 ( & V_3 -> V_26 ) ;
F_72 ( & V_3 -> V_26 ) ;
F_73 ( V_3 ) ;
V_108:
F_74 ( V_3 ) ;
V_107:
F_70 ( & V_35 -> V_102 ) ;
return V_8 ;
}
static int F_75 ( struct V_103 * V_103 )
{
struct V_2 * V_3 = F_76 ( V_103 -> V_111 ) ;
struct V_5 * V_35 = V_3 -> V_5 ;
F_13 ( V_35 -> V_20 , L_3 , V_28 ) ;
if ( F_64 ( & V_35 -> V_102 ) )
return - V_104 ;
F_77 ( V_3 -> V_26 . V_27 ) ;
F_44 ( V_3 ) ;
F_71 ( & V_3 -> V_26 ) ;
F_72 ( & V_3 -> V_26 ) ;
if ( -- V_35 -> V_32 . V_114 <= 0 )
F_78 ( V_115 , & V_35 -> V_1 ) ;
F_73 ( V_3 ) ;
F_74 ( V_3 ) ;
F_70 ( & V_35 -> V_102 ) ;
return 0 ;
}
static int F_79 ( struct V_103 * V_103 , void * V_26 ,
struct V_116 * V_117 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_5 * V_35 = V_3 -> V_5 ;
F_80 ( V_117 -> V_118 , V_35 -> V_119 -> V_120 , sizeof( V_117 -> V_118 ) ) ;
F_80 ( V_117 -> V_121 , V_35 -> V_119 -> V_120 , sizeof( V_117 -> V_121 ) ) ;
snprintf ( V_117 -> V_122 , sizeof( V_117 -> V_122 ) , L_20 ,
V_123 , V_35 -> V_60 ) ;
V_117 -> V_124 = V_125 | V_126 ;
V_117 -> V_127 = V_117 -> V_124 | V_128 ;
return 0 ;
}
static int F_81 ( struct V_103 * V_103 , void * V_26 , struct V_129 * V_130 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
const struct V_9 * V_11 ;
if ( V_130 -> V_131 >= F_7 ( V_13 ) )
return - V_21 ;
V_11 = & V_13 [ V_130 -> V_131 ] ;
if ( ( V_11 -> V_10 == V_132 ) &&
( V_130 -> type == V_18 ) ) {
F_13 ( V_3 -> V_5 -> V_20 , L_21 ) ;
return - V_21 ;
}
V_130 -> V_10 = V_11 -> V_10 ;
return 0 ;
}
static int F_82 ( struct V_103 * V_103 , void * V_26 , struct V_78 * V_130 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_133 * V_79 = & V_130 -> V_11 . V_79 ;
struct V_14 * V_47 = F_8 ( V_3 , V_130 -> type ) ;
if ( F_47 ( V_47 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_47 ) ;
return F_48 ( V_47 ) ;
}
V_79 = & V_130 -> V_11 . V_79 ;
V_79 -> V_134 = V_47 -> V_134 ;
V_79 -> V_51 = V_47 -> V_51 ;
V_79 -> V_10 = V_47 -> V_11 -> V_10 ;
V_79 -> V_135 = V_47 -> V_135 ;
V_79 -> V_50 = V_47 -> V_50 ;
V_79 -> V_80 = V_47 -> V_80 ;
V_79 -> V_136 = ( V_130 -> type == V_16 ) ?
V_47 -> V_136 : V_112 . V_136 ;
return 0 ;
}
static int F_83 ( struct V_103 * V_103 , void * V_26 , struct V_78 * V_130 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_133 * V_79 = & V_130 -> V_11 . V_79 ;
const struct V_9 * V_137 ;
T_1 V_138 , V_139 ;
V_137 = F_6 ( V_79 -> V_10 ) ;
if ( ! V_137 ) {
F_13 ( V_3 -> V_5 -> V_20 , L_22 ,
V_79 -> V_10 ) ;
return - V_21 ;
}
if ( ( V_137 -> V_10 == V_132 ) &&
( V_130 -> type == V_18 ) ) {
F_13 ( V_3 -> V_5 -> V_20 , L_21 ) ;
return - V_21 ;
}
if ( ( V_130 -> type == V_18 ) ||
( V_79 -> V_135 != V_140 ) )
V_79 -> V_135 = V_141 ;
V_138 = V_79 -> V_134 ;
V_139 = V_79 -> V_51 ;
F_84 ( & V_79 -> V_134 ,
V_142 , V_143 ,
F_85 ( V_137 -> V_144 ) - 1 ,
& V_79 -> V_51 ,
V_145 , V_146 ,
F_85 ( V_137 -> V_147 ) - 1 ,
0 ) ;
if ( ( V_79 -> V_134 != V_138 ) || ( V_79 -> V_51 != V_139 ) )
F_13 ( V_3 -> V_5 -> V_20 ,
L_23 , V_28 ,
V_138 , V_139 , V_79 -> V_134 , V_79 -> V_51 ) ;
V_79 -> V_50 = ( V_79 -> V_134 * V_137 -> V_148 ) / 8 ;
V_79 -> V_80 = ( V_79 -> V_134 * V_79 -> V_51 * V_137 -> V_149 ) / 8 ;
if ( V_130 -> type == V_18 )
V_79 -> V_136 = V_112 . V_136 ;
return 0 ;
}
static int F_86 ( struct V_103 * V_103 , void * V_26 , struct V_78 * V_130 )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_72 * V_73 ;
struct V_14 * V_47 ;
struct V_133 * V_79 ;
int V_8 ;
T_1 V_1 ;
V_8 = F_83 ( V_103 , V_26 , V_130 ) ;
if ( V_8 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_24 ) ;
return V_8 ;
}
V_73 = F_87 ( V_3 -> V_26 . V_27 , V_130 -> type ) ;
if ( F_88 ( V_73 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_25 , V_130 -> type ) ;
return - V_150 ;
}
V_47 = ( V_130 -> type == V_16 ) ?
& V_3 -> V_17 : & V_3 -> V_19 ;
V_79 = & V_130 -> V_11 . V_79 ;
V_47 -> V_11 = F_6 ( V_79 -> V_10 ) ;
if ( ! V_47 -> V_11 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_22 ,
V_79 -> V_10 ) ;
return - V_21 ;
}
V_47 -> V_134 = V_79 -> V_134 ;
V_47 -> V_51 = V_79 -> V_51 ;
V_47 -> V_50 = V_79 -> V_50 ;
V_47 -> V_80 = V_79 -> V_80 ;
V_47 -> V_135 = V_79 -> V_135 ;
if ( V_130 -> type == V_16 )
V_47 -> V_136 = V_79 -> V_136 ;
V_47 -> V_151 . V_134 = V_47 -> V_134 ;
V_47 -> V_151 . V_51 = V_47 -> V_51 ;
V_47 -> V_151 . V_152 = 0 ;
V_47 -> V_151 . V_153 = 0 ;
V_1 = V_54 ;
V_1 |= ( V_130 -> type == V_18 ) ?
V_154 : V_155 ;
F_1 ( V_1 , V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_103 * V_103 , void * V_26 ,
struct V_156 * V_157 )
{
struct V_14 * V_47 ;
struct V_2 * V_3 = F_76 ( V_26 ) ;
V_47 = F_8 ( V_3 , V_157 -> type ) ;
if ( F_47 ( V_47 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_47 ) ;
return F_48 ( V_47 ) ;
}
switch ( V_157 -> type ) {
case V_16 :
switch ( V_157 -> V_158 ) {
case V_159 :
V_157 -> V_160 = V_47 -> V_151 ;
break;
case V_161 :
case V_162 :
V_157 -> V_160 . V_152 = 0 ;
V_157 -> V_160 . V_153 = 0 ;
V_157 -> V_160 . V_134 = V_47 -> V_134 ;
V_157 -> V_160 . V_51 = V_47 -> V_51 ;
break;
default:
F_9 ( V_3 -> V_5 -> V_20 , L_26 ) ;
return - V_21 ;
}
break;
case V_18 :
switch ( V_157 -> V_158 ) {
case V_163 :
case V_164 :
V_157 -> V_160 = V_47 -> V_151 ;
break;
case V_165 :
case V_166 :
V_157 -> V_160 . V_152 = 0 ;
V_157 -> V_160 . V_153 = 0 ;
V_157 -> V_160 . V_134 = V_47 -> V_134 ;
V_157 -> V_160 . V_51 = V_47 -> V_51 ;
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
static int F_90 ( struct V_167 * V_168 , struct V_167 * V_169 )
{
if ( V_168 -> V_152 < V_169 -> V_152 || V_168 -> V_153 < V_169 -> V_153 )
return 0 ;
if ( V_168 -> V_152 + V_168 -> V_134 > V_169 -> V_152 + V_169 -> V_134 )
return 0 ;
if ( V_168 -> V_153 + V_168 -> V_51 > V_169 -> V_153 + V_169 -> V_51 )
return 0 ;
return 1 ;
}
static int F_91 ( struct V_103 * V_103 , void * V_26 ,
struct V_156 * V_157 )
{
struct V_14 * V_47 ;
struct V_2 * V_3 = F_76 ( V_26 ) ;
struct V_167 * V_170 , V_55 ;
bool V_171 = false ;
if ( ( V_157 -> type == V_16 ) &&
( V_157 -> V_158 == V_159 ) )
V_171 = true ;
if ( ( V_157 -> type == V_18 ) &&
( V_157 -> V_158 == V_163 ) )
V_171 = true ;
if ( ! V_171 ) {
F_9 ( V_3 -> V_5 -> V_20 , L_28 ) ;
return - V_21 ;
}
V_47 = F_8 ( V_3 , V_157 -> type ) ;
if ( F_47 ( V_47 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_12 , V_47 ) ;
return F_48 ( V_47 ) ;
}
V_170 = & V_157 -> V_160 ;
V_55 = * V_170 ;
V_55 . V_152 = F_92 ( V_170 -> V_152 , V_47 -> V_11 -> V_144 ) ;
V_55 . V_153 = F_92 ( V_170 -> V_153 , V_47 -> V_11 -> V_147 ) ;
if ( ( V_55 . V_152 < 0 ) || ( V_55 . V_152 >= V_47 -> V_134 ) ||
( V_55 . V_153 < 0 ) || ( V_55 . V_153 >= V_47 -> V_51 ) ) {
F_9 ( V_3 -> V_5 -> V_20 ,
L_29 ,
V_55 . V_134 , V_55 . V_51 , V_55 . V_152 , V_55 . V_153 ,
V_47 -> V_134 , V_47 -> V_51 ) ;
return - V_21 ;
}
V_55 . V_134 = F_92 ( V_170 -> V_134 , V_47 -> V_11 -> V_144 ) ;
V_55 . V_51 = F_92 ( V_170 -> V_51 , V_47 -> V_11 -> V_144 ) ;
if ( ( ( V_55 . V_152 + V_55 . V_134 ) > V_47 -> V_134 ) ||
( ( V_55 . V_153 + V_55 . V_51 ) > V_47 -> V_51 ) ) {
F_9 ( V_3 -> V_5 -> V_20 ,
L_29 ,
V_55 . V_134 , V_55 . V_51 , V_55 . V_152 , V_55 . V_153 ,
V_47 -> V_134 , V_47 -> V_51 ) ;
return - V_21 ;
}
if ( V_157 -> V_4 & V_172 && ! F_90 ( & V_55 , V_170 ) )
return - V_173 ;
if ( V_157 -> V_4 & V_174 && ! F_90 ( V_170 , & V_55 ) )
return - V_173 ;
if ( ( V_55 . V_152 != V_170 -> V_152 ) || ( V_55 . V_153 != V_170 -> V_153 ) ||
( V_55 . V_134 != V_170 -> V_134 ) || ( V_55 . V_51 != V_170 -> V_51 ) ) {
F_13 ( V_3 -> V_5 -> V_20 ,
L_30 ,
V_28 , V_170 -> V_134 , V_170 -> V_51 , V_170 -> V_152 , V_170 -> V_153 ,
V_55 . V_134 , V_55 . V_51 , V_55 . V_152 , V_55 . V_153 ) ;
* V_170 = V_55 ;
}
V_47 -> V_151 = V_55 ;
F_1 ( V_54 , V_3 ) ;
return 0 ;
}
static int F_93 ( struct V_103 * V_103 , void * V_26 , enum V_15 type )
{
struct V_2 * V_3 = F_76 ( V_26 ) ;
if ( ( type == V_16 ) &&
! F_5 ( V_155 , V_3 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_31 ) ;
return - V_21 ;
}
if ( ( type == V_18 ) &&
! F_5 ( V_154 , V_3 ) ) {
F_9 ( V_3 -> V_5 -> V_20 , L_32 ) ;
return - V_21 ;
}
return F_94 ( V_103 , V_3 -> V_26 . V_27 , type ) ;
}
static int F_95 ( struct V_5 * V_35 )
{
int V_8 ;
if ( ! V_35 )
return - V_175 ;
V_35 -> V_109 . V_176 = & V_177 ;
V_35 -> V_109 . V_178 = & V_179 ;
V_35 -> V_109 . V_180 = V_181 ;
V_35 -> V_109 . V_102 = & V_35 -> V_102 ;
V_35 -> V_109 . V_182 = V_183 ;
V_35 -> V_109 . V_184 = & V_35 -> V_184 ;
snprintf ( V_35 -> V_109 . V_120 , sizeof( V_35 -> V_109 . V_120 ) , L_33 ,
V_123 , V_35 -> V_60 ) ;
F_96 ( & V_35 -> V_109 , V_35 ) ;
V_35 -> V_32 . V_109 = & V_35 -> V_109 ;
V_35 -> V_32 . V_33 = F_97 ( & V_185 ) ;
if ( F_47 ( V_35 -> V_32 . V_33 ) ) {
F_9 ( V_35 -> V_20 , L_34 ) ;
return F_48 ( V_35 -> V_32 . V_33 ) ;
}
V_8 = F_98 ( & V_35 -> V_109 , V_186 , - 1 ) ;
if ( V_8 ) {
F_9 ( V_35 -> V_20 ,
L_35 , V_28 ) ;
F_99 ( V_35 -> V_32 . V_33 ) ;
return V_8 ;
}
return 0 ;
}
static void F_100 ( struct V_5 * V_35 )
{
if ( ! V_35 )
return;
if ( V_35 -> V_32 . V_33 )
F_99 ( V_35 -> V_32 . V_33 ) ;
F_101 ( V_35 -> V_32 . V_109 ) ;
}
static T_3 F_102 ( int V_187 , void * V_44 )
{
struct V_5 * V_35 = V_44 ;
struct V_2 * V_3 ;
F_103 ( & V_35 -> V_6 ) ;
F_104 ( V_35 ) ;
F_19 ( & V_35 -> V_36 ) ;
if ( ! F_105 ( V_37 , & V_35 -> V_1 ) )
goto V_188;
if ( F_105 ( V_189 , & V_35 -> V_1 ) ) {
F_36 ( V_190 , & V_35 -> V_1 ) ;
F_31 ( & V_35 -> V_39 ) ;
goto V_188;
}
V_3 = F_20 ( V_35 -> V_32 . V_33 ) ;
if ( ! V_3 || ! V_3 -> V_26 . V_27 )
goto V_188;
F_106 ( & V_35 -> V_6 ) ;
F_11 ( V_3 , V_83 ) ;
if ( F_5 ( V_38 , V_3 ) ) {
F_4 ( V_38 , V_3 ) ;
F_31 ( & V_35 -> V_39 ) ;
}
return V_191 ;
V_188:
F_106 ( & V_35 -> V_6 ) ;
return V_191 ;
}
static T_3 F_107 ( int V_187 , void * V_44 )
{
if ( F_108 ( (struct V_5 * ) V_44 ) )
return V_192 ;
else
return V_193 ;
}
static void F_109 ( struct V_194 * V_195 )
{
struct V_196 * V_197 = F_110 ( V_195 ) ;
struct V_5 * V_35 = F_39 ( V_197 , struct V_5 ,
V_36 ) ;
struct V_2 * V_3 ;
V_3 = F_20 ( V_35 -> V_32 . V_33 ) ;
F_9 ( V_3 -> V_5 -> V_20 , L_36 ) ;
F_103 ( & V_35 -> V_6 ) ;
F_78 ( V_37 , & V_35 -> V_1 ) ;
F_106 ( & V_35 -> V_6 ) ;
F_33 ( V_35 ) ;
F_11 ( V_3 , V_43 ) ;
}
static int F_111 ( struct V_5 * V_35 )
{
unsigned long V_4 ;
int V_198 ;
F_2 ( & V_35 -> V_6 , V_4 ) ;
if ( ! F_21 ( V_37 , & V_35 -> V_1 ) ) {
F_3 ( & V_35 -> V_6 , V_4 ) ;
return 0 ;
}
F_78 ( V_190 , & V_35 -> V_1 ) ;
F_36 ( V_189 , & V_35 -> V_1 ) ;
F_3 ( & V_35 -> V_6 , V_4 ) ;
V_198 = F_22 ( V_35 -> V_39 ,
F_21 ( V_190 , & V_35 -> V_1 ) ,
V_40 ) ;
F_78 ( V_189 , & V_35 -> V_1 ) ;
if ( ! V_198 ) {
F_9 ( V_35 -> V_20 , L_4 , V_28 ) ;
return - V_199 ;
}
return 0 ;
}
static int F_112 ( struct V_5 * V_35 )
{
struct V_2 * V_3 ;
unsigned long V_4 ;
F_2 ( & V_35 -> V_6 , V_4 ) ;
V_3 = V_35 -> V_32 . V_3 ;
V_35 -> V_32 . V_3 = NULL ;
F_3 ( & V_35 -> V_6 , V_4 ) ;
if ( F_105 ( V_190 , & V_35 -> V_1 ) )
F_11 ( V_3 , V_43 ) ;
return 0 ;
}
static int F_113 ( struct V_200 * V_20 )
{
struct V_5 * V_35 = F_114 ( V_20 ) ;
int V_8 = F_115 ( V_35 -> clock ) ;
if ( V_8 )
return V_8 ;
return F_112 ( V_35 ) ;
}
static int F_116 ( struct V_200 * V_20 )
{
struct V_5 * V_35 = F_114 ( V_20 ) ;
int V_8 = F_111 ( V_35 ) ;
if ( ! V_8 )
F_117 ( V_35 -> clock ) ;
return V_8 ;
}
static int F_118 ( struct V_200 * V_20 )
{
struct V_5 * V_35 = F_114 ( V_20 ) ;
unsigned long V_4 ;
int V_201 ;
F_2 ( & V_35 -> V_6 , V_4 ) ;
V_201 = F_21 ( V_115 , & V_35 -> V_1 ) ;
F_3 ( & V_35 -> V_6 , V_4 ) ;
if ( ! V_201 )
return 0 ;
if ( ! F_119 ( V_20 ) )
return F_113 ( V_20 ) ;
return 0 ;
}
static int F_120 ( struct V_200 * V_20 )
{
if ( ! F_119 ( V_20 ) )
return F_116 ( V_20 ) ;
return 0 ;
}
static int F_121 ( struct V_202 * V_119 )
{
struct V_5 * V_35 = F_122 ( V_119 ) ;
F_100 ( V_35 ) ;
F_123 ( V_35 -> V_20 ) ;
F_124 ( V_35 -> V_81 ) ;
F_125 ( & V_119 -> V_20 ) ;
F_126 ( V_35 ) ;
F_127 ( & V_35 -> V_184 ) ;
if ( ! F_47 ( V_35 -> clock ) )
F_128 ( V_35 -> clock ) ;
F_13 ( & V_119 -> V_20 , L_37 , V_119 -> V_120 ) ;
return 0 ;
}
static int F_129 ( struct V_202 * V_119 )
{
struct V_5 * V_35 ;
struct V_203 * V_204 ;
struct V_200 * V_20 = & V_119 -> V_20 ;
int V_8 ;
F_13 ( V_20 , L_3 , V_28 ) ;
V_35 = F_130 ( V_20 , sizeof( struct V_5 ) , V_105 ) ;
if ( ! V_35 )
return - V_106 ;
V_35 -> V_119 = V_119 ;
V_35 -> V_20 = V_20 ;
F_131 ( V_119 , V_35 ) ;
if ( V_20 -> V_205 )
V_35 -> V_60 = F_132 ( V_119 -> V_20 . V_205 , V_123 ) ;
else
V_35 -> V_60 = V_119 -> V_60 ;
F_133 ( & V_35 -> V_39 ) ;
F_134 ( & V_35 -> V_36 , F_109 ) ;
V_35 -> V_56 = F_135 ( V_123 ) ;
F_136 ( & V_35 -> V_6 ) ;
F_137 ( & V_35 -> V_102 ) ;
V_204 = F_138 ( V_119 , V_206 , 0 ) ;
V_35 -> V_207 = F_139 ( V_20 , V_204 ) ;
if ( F_47 ( V_35 -> V_207 ) ) {
F_9 ( V_20 , L_38 ) ;
return F_48 ( V_35 -> V_207 ) ;
}
V_35 -> clock = F_140 ( V_20 , V_123 ) ;
if ( F_47 ( V_35 -> clock ) ) {
F_9 ( V_20 , L_39 ) ;
return F_48 ( V_35 -> clock ) ;
}
V_8 = F_141 ( V_35 -> clock ) ;
if ( V_8 < 0 ) {
F_9 ( V_20 , L_40 ) ;
V_35 -> clock = F_10 ( - V_21 ) ;
return V_8 ;
}
V_204 = F_138 ( V_119 , V_208 , 0 ) ;
if ( ! V_204 ) {
F_9 ( V_20 , L_41 ) ;
goto V_209;
}
V_8 = F_142 ( V_20 , V_204 -> V_210 , F_107 ,
F_102 , V_211 ,
V_119 -> V_120 , V_35 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_42 ) ;
goto V_209;
}
V_8 = F_143 ( V_20 , & V_35 -> V_184 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_43 ) ;
goto V_209;
}
V_8 = F_144 ( V_35 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_44 ) ;
goto V_212;
}
F_145 ( V_20 ) ;
V_8 = F_57 ( V_20 ) ;
if ( V_8 < 0 ) {
F_9 ( V_20 , L_45 ) ;
goto V_213;
}
V_35 -> V_81 = F_146 ( V_20 ) ;
if ( F_47 ( V_35 -> V_81 ) ) {
V_8 = F_48 ( V_35 -> V_81 ) ;
goto V_214;
}
if ( F_147 ( V_35 -> V_20 ) ) {
F_9 ( V_35 -> V_20 , L_46 ) ;
V_8 = - V_106 ;
goto V_215;
}
V_8 = F_95 ( V_35 ) ;
if ( V_8 ) {
F_9 ( V_20 , L_43 ) ;
goto V_216;
}
F_148 ( V_20 , L_47 , V_123 ,
V_35 -> V_60 , V_35 -> V_109 . V_217 ) ;
F_59 ( V_20 ) ;
return 0 ;
V_216:
F_123 ( V_35 -> V_20 ) ;
V_215:
F_124 ( V_35 -> V_81 ) ;
V_214:
F_59 ( V_20 ) ;
V_213:
F_126 ( V_35 ) ;
V_212:
F_127 ( & V_35 -> V_184 ) ;
V_209:
if ( ! F_47 ( V_35 -> clock ) )
F_128 ( V_35 -> clock ) ;
return V_8 ;
}
