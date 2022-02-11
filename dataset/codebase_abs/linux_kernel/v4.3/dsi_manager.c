static inline struct V_1 * F_1 ( int V_2 )
{
return V_3 . V_4 [ V_2 ] ;
}
static inline struct V_1 * F_2 ( int V_2 )
{
return V_3 . V_4 [ ( V_2 + 1 ) % V_5 ] ;
}
static int F_3 ( struct V_6 * V_7 , int V_2 )
{
struct V_8 * V_9 = & V_3 ;
if ( ! V_9 -> V_10 )
V_9 -> V_10 = F_4 (
V_7 , L_1 ) ;
if ( V_9 -> V_10 ) {
if ( F_4 ( V_7 , L_2 ) )
V_9 -> V_11 = V_2 ;
if ( ! V_9 -> V_12 )
V_9 -> V_12 = F_4 (
V_7 , L_3 ) ;
}
return 0 ;
}
static int F_5 ( int V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_13 = F_2 ( V_2 ) ;
struct V_1 * V_14 = F_1 ( V_15 ) ;
struct V_16 * V_17 ;
int V_18 ;
if ( ! F_6 () ) {
V_18 = F_7 ( V_1 -> V_19 , true ) ;
if ( V_18 )
return V_18 ;
V_17 = F_8 ( V_1 -> V_20 ) ;
V_18 = F_9 ( V_1 -> V_19 , V_17 ) ;
} else if ( ! V_13 ) {
V_18 = 0 ;
} else {
struct V_1 * V_21 = F_10 ( V_2 ) ?
V_1 : V_13 ;
struct V_1 * V_22 = F_10 ( V_2 ) ?
V_13 : V_1 ;
V_18 = F_7 ( V_22 -> V_19 , false ) ;
if ( V_18 )
return V_18 ;
V_18 = F_7 ( V_21 -> V_19 , true ) ;
if ( V_18 )
return V_18 ;
V_17 = F_8 ( V_14 -> V_20 ) ;
V_18 = F_9 ( V_1 -> V_19 , V_17 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_9 ( V_13 -> V_19 , V_17 ) ;
}
return V_18 ;
}
static inline int F_11 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_12 ( V_24 ) ;
return V_25 -> V_2 ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_28 * V_28 = F_14 ( V_27 ) ;
return V_28 -> V_2 ;
}
static enum V_29 F_15 (
struct V_23 * V_24 , bool V_30 )
{
int V_2 = F_11 ( V_24 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_13 = F_2 ( V_2 ) ;
struct V_31 * V_32 = V_24 -> V_33 -> V_34 ;
struct V_35 * V_36 = V_32 -> V_36 ;
F_16 ( L_4 , V_2 ) ;
if ( ! V_1 -> V_37 ) {
V_1 -> V_37 = F_17 ( V_1 -> V_19 ,
& V_1 -> V_38 ) ;
if ( ! V_1 -> V_37 && F_6 () &&
! F_10 ( V_2 ) && V_13 )
V_1 -> V_37 = F_17 (
V_13 -> V_19 , NULL ) ;
if ( V_1 -> V_37 && F_6 () )
F_18 ( & V_24 -> V_39 ,
V_24 -> V_33 -> V_40 . V_41 , 0 ) ;
if ( V_1 -> V_37 && F_6 () &&
V_13 && V_13 -> V_37 ) {
bool V_42 = ! ( V_1 -> V_38 &
V_43 ) ;
struct V_44 * V_45 = F_19 (
F_1 ( V_46 ) ) ;
struct V_44 * V_47 = F_19 (
F_1 ( V_48 ) ) ;
if ( V_36 -> V_49 -> V_50 )
V_36 -> V_49 -> V_50 ( V_36 , V_45 ,
V_47 , V_42 ) ;
else
F_20 ( L_5 ) ;
}
}
return V_1 -> V_37 ? V_51 :
V_52 ;
}
static void F_21 ( struct V_23 * V_24 )
{
F_16 ( L_6 ) ;
F_22 ( V_24 ) ;
F_23 ( V_24 ) ;
}
static void F_24 ( struct V_23 * V_24 )
{
struct V_53 * V_54 , * V_55 ;
F_25 (mode, m, &connector->probed_modes, head) {
V_54 -> clock >>= 1 ;
V_54 -> V_56 >>= 1 ;
V_54 -> V_57 >>= 1 ;
V_54 -> V_58 >>= 1 ;
V_54 -> V_59 >>= 1 ;
F_26 ( V_54 ) ;
}
}
static int F_27 (
struct V_23 * V_24 , int V_2 )
{
struct V_53 * V_54 ;
char V_60 [ 8 ] = { 'M' , 'S' , 'M' , 'D' , 'U' , 'D' , 'S' , 'I' } ;
if ( V_24 -> V_61 ) {
F_16 ( L_7 ) ;
return 0 ;
}
V_54 = F_28 ( & V_24 -> V_62 ,
struct V_53 ,
V_63 ) ;
if ( ! V_54 )
return - V_64 ;
V_24 -> V_61 = F_29 (
V_24 -> V_33 , V_60 ) ;
if ( ! V_24 -> V_61 )
V_24 -> V_61 = F_30 (
V_24 -> V_33 , V_60 ) ;
if ( ! V_24 -> V_61 ) {
F_20 ( L_8 , V_65 ) ;
return - V_66 ;
}
V_24 -> V_67 = true ;
V_24 -> V_68 = true ;
V_24 -> V_69 = V_54 -> V_56 ;
V_24 -> V_70 = V_54 -> V_71 ;
V_24 -> V_72 = 2 ;
V_24 -> V_73 = 1 ;
V_24 -> V_74 = 0 ;
V_24 -> V_75 = ( V_2 == V_76 ) ? 1 : 0 ;
return 0 ;
}
static int F_31 ( struct V_23 * V_24 )
{
int V_2 = F_11 ( V_24 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_77 * V_37 = V_1 -> V_37 ;
int V_18 , V_78 ;
if ( ! V_37 )
return 0 ;
F_32 ( V_37 , V_24 ) ;
V_78 = F_33 ( V_37 ) ;
F_34 ( V_37 ) ;
if ( ! V_78 )
return 0 ;
if ( F_6 () ) {
F_24 ( V_24 ) ;
V_18 = F_27 ( V_24 , V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_35 ( V_24 ) ;
if ( V_18 ) {
F_20 ( L_9 ,
V_65 , V_18 ) ;
return V_18 ;
}
}
return V_78 ;
}
static int F_36 ( struct V_23 * V_24 ,
struct V_53 * V_54 )
{
int V_2 = F_11 ( V_24 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_44 * V_45 = F_19 ( V_1 ) ;
struct V_31 * V_32 = V_24 -> V_33 -> V_34 ;
struct V_35 * V_36 = V_32 -> V_36 ;
long V_79 , V_80 ;
F_16 ( L_6 ) ;
V_80 = 1000 * V_54 -> clock ;
V_79 = V_36 -> V_49 -> V_81 ( V_36 , V_80 , V_45 ) ;
F_16 ( L_10 , V_80 , V_79 ) ;
if ( V_79 != V_80 )
return V_82 ;
return V_83 ;
}
static struct V_44 *
F_37 ( struct V_23 * V_24 )
{
int V_2 = F_11 ( V_24 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_16 ( L_6 ) ;
return F_19 ( V_1 ) ;
}
static void F_38 ( struct V_26 * V_27 )
{
int V_2 = F_13 ( V_27 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_84 = F_1 ( V_85 ) ;
struct V_86 * V_19 = V_1 -> V_19 ;
struct V_77 * V_37 = V_1 -> V_37 ;
bool V_10 = F_6 () ;
int V_18 ;
F_16 ( L_4 , V_2 ) ;
if ( ! F_39 ( V_1 ) ||
( V_10 && ( V_85 == V_2 ) ) )
return;
V_18 = F_40 ( V_19 ) ;
if ( V_18 ) {
F_20 ( L_11 , V_65 , V_2 , V_18 ) ;
goto V_87;
}
if ( V_10 && V_84 ) {
V_18 = F_40 ( V_84 -> V_19 ) ;
if ( V_18 ) {
F_20 ( L_12 ,
V_65 , V_18 ) ;
goto V_88;
}
}
if ( V_37 ) {
V_18 = F_41 ( V_37 ) ;
if ( V_18 ) {
F_20 ( L_13 , V_65 ,
V_2 , V_18 ) ;
goto V_89;
}
}
V_18 = F_42 ( V_19 ) ;
if ( V_18 ) {
F_20 ( L_14 , V_65 , V_2 , V_18 ) ;
goto V_90;
}
if ( V_10 && V_84 ) {
V_18 = F_42 ( V_84 -> V_19 ) ;
if ( V_18 ) {
F_20 ( L_15 , V_65 , V_18 ) ;
goto V_91;
}
}
if ( V_37 ) {
V_18 = F_43 ( V_37 ) ;
if ( V_18 ) {
F_20 ( L_16 , V_65 , V_2 ,
V_18 ) ;
goto V_92;
}
}
return;
V_92:
if ( V_10 && V_84 )
F_44 ( V_84 -> V_19 ) ;
V_91:
F_44 ( V_19 ) ;
V_90:
if ( V_37 )
F_45 ( V_37 ) ;
V_89:
if ( V_10 && V_84 )
F_46 ( V_84 -> V_19 ) ;
V_88:
F_46 ( V_19 ) ;
V_87:
return;
}
static void F_47 ( struct V_26 * V_27 )
{
F_16 ( L_6 ) ;
}
static void F_48 ( struct V_26 * V_27 )
{
F_16 ( L_6 ) ;
}
static void F_49 ( struct V_26 * V_27 )
{
int V_2 = F_13 ( V_27 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_84 = F_1 ( V_85 ) ;
struct V_86 * V_19 = V_1 -> V_19 ;
struct V_77 * V_37 = V_1 -> V_37 ;
bool V_10 = F_6 () ;
int V_18 ;
F_16 ( L_4 , V_2 ) ;
if ( ! F_39 ( V_1 ) ||
( V_10 && ( V_85 == V_2 ) ) )
return;
if ( V_37 ) {
V_18 = F_50 ( V_37 ) ;
if ( V_18 )
F_20 ( L_17 , V_65 , V_2 ,
V_18 ) ;
}
V_18 = F_44 ( V_19 ) ;
if ( V_18 )
F_20 ( L_18 , V_65 , V_2 , V_18 ) ;
if ( V_10 && V_84 ) {
V_18 = F_44 ( V_84 -> V_19 ) ;
if ( V_18 )
F_20 ( L_19 , V_65 , V_18 ) ;
}
if ( V_37 ) {
V_18 = F_45 ( V_37 ) ;
if ( V_18 )
F_20 ( L_20 , V_65 ,
V_2 , V_18 ) ;
}
V_18 = F_46 ( V_19 ) ;
if ( V_18 )
F_20 ( L_21 , V_65 , V_2 , V_18 ) ;
if ( V_10 && V_84 ) {
V_18 = F_46 ( V_84 -> V_19 ) ;
if ( V_18 )
F_20 ( L_22 ,
V_65 , V_18 ) ;
}
}
static void F_51 ( struct V_26 * V_27 ,
struct V_53 * V_54 ,
struct V_53 * V_93 )
{
int V_2 = F_13 ( V_27 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_13 = F_2 ( V_2 ) ;
struct V_86 * V_19 = V_1 -> V_19 ;
bool V_10 = F_6 () ;
F_16 ( L_23 ,
V_54 -> V_39 . V_2 , V_54 -> V_94 ,
V_54 -> V_95 , V_54 -> clock ,
V_54 -> V_56 , V_54 -> V_57 ,
V_54 -> V_58 , V_54 -> V_59 ,
V_54 -> V_71 , V_54 -> V_96 ,
V_54 -> V_97 , V_54 -> V_98 ,
V_54 -> type , V_54 -> V_99 ) ;
if ( V_10 && ( V_85 == V_2 ) )
return;
F_52 ( V_19 , V_93 ) ;
if ( V_10 && V_13 )
F_52 ( V_13 -> V_19 , V_93 ) ;
}
struct V_23 * F_53 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_23 * V_24 = NULL ;
struct V_25 * V_25 ;
int V_18 , V_100 ;
V_25 = F_54 ( V_1 -> V_33 -> V_33 ,
sizeof( * V_25 ) , V_101 ) ;
if ( ! V_25 ) {
V_18 = - V_66 ;
goto V_102;
}
V_25 -> V_2 = V_2 ;
V_24 = & V_25 -> V_39 ;
V_18 = F_55 ( V_1 -> V_33 , V_24 ,
& V_103 , V_104 ) ;
if ( V_18 )
goto V_102;
F_56 ( V_24 , & V_105 ) ;
V_24 -> V_106 = V_107 ;
V_24 -> V_108 = 0 ;
V_24 -> V_109 = 0 ;
V_18 = F_57 ( V_24 ) ;
if ( V_18 )
goto V_102;
for ( V_100 = 0 ; V_100 < V_110 ; V_100 ++ )
F_58 ( V_24 ,
V_1 -> V_111 [ V_100 ] ) ;
return V_24 ;
V_102:
if ( V_24 )
F_21 ( V_24 ) ;
return F_59 ( V_18 ) ;
}
struct V_26 * F_60 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_28 ;
int V_18 ;
V_28 = F_54 ( V_1 -> V_33 -> V_33 ,
sizeof( * V_28 ) , V_101 ) ;
if ( ! V_28 ) {
V_18 = - V_66 ;
goto V_102;
}
V_28 -> V_2 = V_2 ;
V_27 = & V_28 -> V_39 ;
V_27 -> V_49 = & V_112 ;
V_18 = F_61 ( V_1 -> V_33 , V_27 ) ;
if ( V_18 )
goto V_102;
return V_27 ;
V_102:
if ( V_27 )
F_62 ( V_27 ) ;
return F_59 ( V_18 ) ;
}
struct V_23 * F_63 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_113 * V_33 = V_1 -> V_33 ;
struct V_44 * V_45 ;
struct V_26 * V_114 , * V_115 ;
struct V_23 * V_24 ;
struct V_116 * V_117 ;
V_114 = V_1 -> V_27 ;
V_115 = V_1 -> V_118 =
F_64 ( V_1 -> V_19 ) ;
V_45 = V_1 -> V_111 [ V_119 ] ;
V_114 -> V_120 = V_115 ;
V_115 -> V_45 = V_45 ;
F_61 ( V_33 , V_115 ) ;
V_117 = & V_33 -> V_40 . V_117 ;
F_65 (connector, connector_list, head) {
int V_100 ;
for ( V_100 = 0 ; V_100 < V_121 ; V_100 ++ ) {
if ( V_24 -> V_122 [ V_100 ] == V_45 -> V_39 . V_2 )
return V_24 ;
}
}
return F_59 ( - V_123 ) ;
}
void F_62 ( struct V_26 * V_27 )
{
}
int F_66 ( int V_2 ,
const unsigned long V_124 , const unsigned long V_125 ,
T_2 * V_126 , T_2 * V_127 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_128 * V_20 = V_1 -> V_20 ;
int V_129 = F_6 () ? V_15 : V_2 ;
struct V_16 * V_130 = F_8 ( V_1 -> V_20 ) ;
int V_18 ;
V_18 = F_67 ( V_20 , V_129 , V_124 , V_125 ) ;
if ( V_18 )
return V_18 ;
if ( ! F_6 () || ( V_2 == V_15 ) ) {
V_18 = F_68 ( V_130 ) ;
if ( V_18 ) {
F_20 ( L_24 , V_65 ) ;
F_69 ( V_20 ) ;
return V_18 ;
}
}
V_1 -> V_131 = true ;
F_70 ( V_20 , V_126 , V_127 ) ;
return 0 ;
}
void F_71 ( int V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_21 = F_1 ( V_15 ) ;
struct V_1 * V_22 = F_1 ( V_132 ) ;
struct V_128 * V_20 = V_1 -> V_20 ;
struct V_16 * V_130 = F_8 ( V_1 -> V_20 ) ;
if ( ! F_6 () || ( V_2 == V_15 ) )
F_72 ( V_130 ) ;
V_1 -> V_131 = false ;
if ( F_6 () && V_21 && V_22 ) {
if ( ! V_21 -> V_131 && ! V_22 -> V_131 ) {
F_69 ( V_22 -> V_20 ) ;
F_69 ( V_21 -> V_20 ) ;
}
} else {
F_69 ( V_20 ) ;
}
}
int F_73 ( int V_2 , const struct V_133 * V_134 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_135 = F_1 ( V_136 ) ;
struct V_86 * V_19 = V_1 -> V_19 ;
bool V_137 = ( V_134 -> V_138 && V_134 -> V_139 ) ;
bool V_140 = ( F_74 () && ! V_137 ) ;
int V_18 ;
if ( ! V_134 -> V_141 || ! V_134 -> V_142 )
return 0 ;
if ( V_140 && ( V_2 == V_136 ) )
return V_137 ? V_134 -> V_139 : V_134 -> V_142 ;
if ( V_140 && V_135 ) {
V_18 = F_75 ( V_135 -> V_19 , V_134 ) ;
if ( V_18 ) {
F_20 ( L_25 ,
V_65 , V_18 ) ;
return V_18 ;
}
}
V_18 = F_75 ( V_19 , V_134 ) ;
if ( V_18 ) {
F_20 ( L_26 , V_65 , V_18 ) ;
goto V_143;
}
V_18 = V_137 ? F_76 ( V_19 , V_134 ) :
F_77 ( V_19 , V_134 ) ;
F_78 ( V_19 , V_134 ) ;
V_143:
if ( V_140 && V_135 )
F_78 ( V_135 -> V_19 , V_134 ) ;
return V_18 ;
}
bool F_79 ( int V_2 , T_2 V_144 , T_2 V_145 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_135 = F_1 ( V_136 ) ;
struct V_86 * V_19 = V_1 -> V_19 ;
if ( F_74 () && ( V_2 == V_136 ) )
return false ;
if ( F_74 () && V_135 )
F_80 ( V_135 -> V_19 , V_144 , V_145 ) ;
F_80 ( V_19 , V_144 , V_145 ) ;
return true ;
}
int F_81 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = & V_3 ;
int V_2 = V_1 -> V_2 ;
int V_18 ;
if ( V_2 > V_5 ) {
F_20 ( L_27 , V_65 , V_2 ) ;
return - V_64 ;
}
if ( V_9 -> V_4 [ V_2 ] ) {
F_20 ( L_28 , V_65 , V_2 ) ;
return - V_146 ;
}
V_9 -> V_4 [ V_2 ] = V_1 ;
V_18 = F_3 ( V_1 -> V_147 -> V_33 . V_148 , V_2 ) ;
if ( V_18 ) {
F_20 ( L_29 , V_65 ) ;
goto V_102;
}
V_18 = F_5 ( V_2 ) ;
if ( V_18 ) {
F_20 ( L_30 ,
V_65 , V_2 ) ;
goto V_102;
}
return 0 ;
V_102:
V_9 -> V_4 [ V_2 ] = NULL ;
return V_18 ;
}
void F_82 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = & V_3 ;
if ( V_1 -> V_19 )
F_83 ( V_1 -> V_19 ) ;
V_9 -> V_4 [ V_1 -> V_2 ] = NULL ;
}
