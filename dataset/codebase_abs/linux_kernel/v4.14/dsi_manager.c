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
struct V_1 * V_16 = F_1 ( V_17 ) ;
struct V_18 * V_19 ;
int V_20 ;
if ( ! F_6 () ) {
V_20 = F_7 ( V_1 -> V_21 , true ) ;
if ( V_20 )
return V_20 ;
F_8 ( V_1 -> V_22 , V_23 ) ;
V_19 = F_9 ( V_1 -> V_22 ) ;
V_20 = F_10 ( V_1 -> V_21 , V_19 ) ;
} else if ( ! V_13 ) {
V_20 = 0 ;
} else {
struct V_1 * V_24 = F_11 ( V_2 ) ?
V_1 : V_13 ;
struct V_1 * V_25 = F_11 ( V_2 ) ?
V_13 : V_1 ;
V_20 = F_7 ( V_25 -> V_21 , false ) ;
if ( V_20 )
return V_20 ;
V_20 = F_7 ( V_24 -> V_21 , true ) ;
if ( V_20 )
return V_20 ;
F_8 ( V_14 -> V_22 ,
V_26 ) ;
F_8 ( V_16 -> V_22 ,
V_27 ) ;
V_19 = F_9 ( V_14 -> V_22 ) ;
V_20 = F_10 ( V_1 -> V_21 , V_19 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_10 ( V_13 -> V_21 , V_19 ) ;
}
return V_20 ;
}
static int F_12 ( struct V_1 * V_1 , int V_28 ,
struct V_29 * V_30 )
{
struct V_31 V_32 ;
int V_20 ;
F_13 ( V_1 -> V_21 , & V_32 ) ;
V_20 = F_14 ( V_1 -> V_22 , V_28 , & V_32 ) ;
F_15 ( V_1 -> V_22 , V_30 ) ;
return V_20 ;
}
static int
F_16 ( int V_2 ,
struct V_29 V_30 [ V_5 ] )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_33 = F_1 ( V_15 ) ;
struct V_1 * V_34 = F_1 ( V_17 ) ;
int V_28 = F_6 () ? V_15 : V_2 ;
int V_20 ;
if ( F_6 () && V_33 && V_34 ) {
if ( ! V_33 -> V_35 && ! V_34 -> V_35 ) {
F_17 ( V_33 -> V_21 ) ;
F_17 ( V_34 -> V_21 ) ;
V_20 = F_12 ( V_33 , V_28 ,
& V_30 [ V_15 ] ) ;
if ( V_20 )
return V_20 ;
V_20 = F_12 ( V_34 , V_28 ,
& V_30 [ V_17 ] ) ;
if ( V_20 ) {
F_18 ( V_33 -> V_22 ) ;
return V_20 ;
}
}
} else {
F_17 ( V_1 -> V_21 ) ;
V_20 = F_12 ( V_1 , V_28 , & V_30 [ V_2 ] ) ;
if ( V_20 )
return V_20 ;
}
V_1 -> V_35 = true ;
return 0 ;
}
static void F_19 ( int V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_33 = F_1 ( V_15 ) ;
struct V_1 * V_34 = F_1 ( V_17 ) ;
V_1 -> V_35 = false ;
if ( F_6 () && V_33 && V_34 ) {
if ( ! V_33 -> V_35 && ! V_34 -> V_35 ) {
F_18 ( V_34 -> V_22 ) ;
F_18 ( V_33 -> V_22 ) ;
}
} else {
F_18 ( V_1 -> V_22 ) ;
}
}
static inline int F_20 ( struct V_36 * V_37 )
{
struct V_38 * V_38 = F_21 ( V_37 ) ;
return V_38 -> V_2 ;
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_41 * V_41 = F_23 ( V_40 ) ;
return V_41 -> V_2 ;
}
static enum V_42 F_24 (
struct V_36 * V_37 , bool V_43 )
{
int V_2 = F_20 ( V_37 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_13 = F_2 ( V_2 ) ;
struct V_44 * V_45 = V_37 -> V_46 -> V_47 ;
struct V_48 * V_49 = V_45 -> V_49 ;
F_25 ( L_4 , V_2 ) ;
if ( ! V_1 -> V_50 ) {
V_1 -> V_50 = F_26 ( V_1 -> V_21 ,
& V_1 -> V_51 ) ;
if ( ! V_1 -> V_50 && F_6 () &&
! F_11 ( V_2 ) && V_13 )
V_1 -> V_50 = F_26 (
V_13 -> V_21 , NULL ) ;
if ( V_1 -> V_50 && V_49 -> V_52 -> V_53 ) {
bool V_54 = ! ( V_1 -> V_51 &
V_55 ) ;
struct V_56 * V_57 =
F_27 ( V_1 ) ;
V_49 -> V_52 -> V_53 ( V_49 , V_57 , V_54 ) ;
}
if ( V_1 -> V_50 && F_6 () )
F_28 ( & V_37 -> V_58 ,
V_37 -> V_46 -> V_59 . V_60 , 0 ) ;
if ( V_1 -> V_50 && F_6 () &&
V_13 && V_13 -> V_50 ) {
bool V_54 = ! ( V_1 -> V_51 &
V_55 ) ;
struct V_56 * V_57 = F_27 (
F_1 ( V_61 ) ) ;
struct V_56 * V_62 = F_27 (
F_1 ( V_63 ) ) ;
if ( V_49 -> V_52 -> V_64 )
V_49 -> V_52 -> V_64 ( V_49 , V_57 ,
V_62 , V_54 ) ;
else
F_29 ( L_5 ) ;
}
}
return V_1 -> V_50 ? V_65 :
V_66 ;
}
static void F_30 ( struct V_36 * V_37 )
{
struct V_38 * V_38 = F_21 ( V_37 ) ;
F_25 ( L_6 ) ;
F_31 ( V_37 ) ;
F_32 ( V_38 ) ;
}
static void F_33 ( struct V_36 * V_37 )
{
struct V_67 * V_68 , * V_69 ;
F_34 (mode, m, &connector->probed_modes, head) {
V_68 -> clock >>= 1 ;
V_68 -> V_70 >>= 1 ;
V_68 -> V_71 >>= 1 ;
V_68 -> V_72 >>= 1 ;
V_68 -> V_73 >>= 1 ;
F_35 ( V_68 ) ;
}
}
static int F_36 (
struct V_36 * V_37 , int V_2 )
{
struct V_67 * V_68 ;
char V_74 [ 8 ] = { 'M' , 'S' , 'M' , 'D' , 'U' , 'D' , 'S' , 'I' } ;
if ( V_37 -> V_75 ) {
F_25 ( L_7 ) ;
return 0 ;
}
V_68 = F_37 ( & V_37 -> V_76 ,
struct V_67 ,
V_77 ) ;
if ( ! V_68 )
return - V_78 ;
V_37 -> V_75 = F_38 (
V_37 -> V_46 , V_74 ) ;
if ( ! V_37 -> V_75 )
V_37 -> V_75 = F_39 (
V_37 -> V_46 , V_74 ) ;
if ( ! V_37 -> V_75 ) {
F_29 ( L_8 , V_79 ) ;
return - V_80 ;
}
V_37 -> V_81 = true ;
V_37 -> V_82 = true ;
V_37 -> V_83 = V_68 -> V_70 ;
V_37 -> V_84 = V_68 -> V_85 ;
V_37 -> V_86 = 2 ;
V_37 -> V_87 = 1 ;
V_37 -> V_88 = 0 ;
V_37 -> V_89 = ( V_2 == V_90 ) ? 1 : 0 ;
return 0 ;
}
static int F_40 ( struct V_36 * V_37 )
{
int V_2 = F_20 ( V_37 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_91 * V_50 = V_1 -> V_50 ;
int V_20 , V_92 ;
if ( ! V_50 )
return 0 ;
F_41 ( V_50 , V_37 ) ;
V_92 = F_42 ( V_50 ) ;
F_43 ( V_50 ) ;
if ( ! V_92 )
return 0 ;
if ( F_6 () ) {
F_33 ( V_37 ) ;
V_20 = F_36 ( V_37 , V_2 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_44 ( V_37 ) ;
if ( V_20 ) {
F_29 ( L_9 ,
V_79 , V_20 ) ;
return V_20 ;
}
}
return V_92 ;
}
static int F_45 ( struct V_36 * V_37 ,
struct V_67 * V_68 )
{
int V_2 = F_20 ( V_37 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_56 * V_57 = F_27 ( V_1 ) ;
struct V_44 * V_45 = V_37 -> V_46 -> V_47 ;
struct V_48 * V_49 = V_45 -> V_49 ;
long V_93 , V_94 ;
F_25 ( L_6 ) ;
V_94 = 1000 * V_68 -> clock ;
V_93 = V_49 -> V_52 -> V_95 ( V_49 , V_94 , V_57 ) ;
F_25 ( L_10 , V_94 , V_93 ) ;
if ( V_93 != V_94 )
return V_96 ;
return V_97 ;
}
static struct V_56 *
F_46 ( struct V_36 * V_37 )
{
int V_2 = F_20 ( V_37 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_25 ( L_6 ) ;
return F_27 ( V_1 ) ;
}
static void F_47 ( struct V_39 * V_40 )
{
int V_2 = F_22 ( V_40 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_98 = F_1 ( V_99 ) ;
struct V_100 * V_21 = V_1 -> V_21 ;
struct V_91 * V_50 = V_1 -> V_50 ;
struct V_29 V_101 [ V_5 ] ;
bool V_10 = F_6 () ;
int V_20 ;
F_25 ( L_4 , V_2 ) ;
if ( ! F_48 ( V_1 ) )
return;
V_20 = F_16 ( V_2 , V_101 ) ;
if ( V_20 )
goto V_102;
if ( V_10 && ( V_99 == V_2 ) )
return;
V_20 = F_49 ( V_21 , & V_101 [ V_2 ] ) ;
if ( V_20 ) {
F_29 ( L_11 , V_79 , V_2 , V_20 ) ;
goto V_103;
}
if ( V_10 && V_98 ) {
V_20 = F_49 ( V_98 -> V_21 ,
& V_101 [ V_99 ] ) ;
if ( V_20 ) {
F_29 ( L_12 ,
V_79 , V_20 ) ;
goto V_104;
}
}
if ( V_50 ) {
V_20 = F_50 ( V_50 ) ;
if ( V_20 ) {
F_29 ( L_13 , V_79 ,
V_2 , V_20 ) ;
goto V_105;
}
}
V_20 = F_51 ( V_21 ) ;
if ( V_20 ) {
F_29 ( L_14 , V_79 , V_2 , V_20 ) ;
goto V_106;
}
if ( V_10 && V_98 ) {
V_20 = F_51 ( V_98 -> V_21 ) ;
if ( V_20 ) {
F_29 ( L_15 , V_79 , V_20 ) ;
goto V_107;
}
}
if ( V_50 ) {
V_20 = F_52 ( V_50 ) ;
if ( V_20 ) {
F_29 ( L_16 , V_79 , V_2 ,
V_20 ) ;
goto V_108;
}
}
return;
V_108:
if ( V_10 && V_98 )
F_53 ( V_98 -> V_21 ) ;
V_107:
F_53 ( V_21 ) ;
V_106:
if ( V_50 )
F_54 ( V_50 ) ;
V_105:
if ( V_10 && V_98 )
F_55 ( V_98 -> V_21 ) ;
V_104:
F_55 ( V_21 ) ;
V_103:
F_19 ( V_2 ) ;
V_102:
return;
}
static void F_56 ( struct V_39 * V_40 )
{
F_25 ( L_6 ) ;
}
static void F_57 ( struct V_39 * V_40 )
{
F_25 ( L_6 ) ;
}
static void F_58 ( struct V_39 * V_40 )
{
int V_2 = F_22 ( V_40 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_98 = F_1 ( V_99 ) ;
struct V_100 * V_21 = V_1 -> V_21 ;
struct V_91 * V_50 = V_1 -> V_50 ;
bool V_10 = F_6 () ;
int V_20 ;
F_25 ( L_4 , V_2 ) ;
if ( ! F_48 ( V_1 ) )
return;
if ( V_10 && ( V_99 == V_2 ) )
goto V_109;
if ( V_50 ) {
V_20 = F_59 ( V_50 ) ;
if ( V_20 )
F_29 ( L_17 , V_79 , V_2 ,
V_20 ) ;
}
V_20 = F_53 ( V_21 ) ;
if ( V_20 )
F_29 ( L_18 , V_79 , V_2 , V_20 ) ;
if ( V_10 && V_98 ) {
V_20 = F_53 ( V_98 -> V_21 ) ;
if ( V_20 )
F_29 ( L_19 , V_79 , V_20 ) ;
}
if ( V_50 ) {
V_20 = F_54 ( V_50 ) ;
if ( V_20 )
F_29 ( L_20 , V_79 ,
V_2 , V_20 ) ;
}
V_20 = F_55 ( V_21 ) ;
if ( V_20 )
F_29 ( L_21 , V_79 , V_2 , V_20 ) ;
if ( V_10 && V_98 ) {
V_20 = F_55 ( V_98 -> V_21 ) ;
if ( V_20 )
F_29 ( L_22 ,
V_79 , V_20 ) ;
}
V_109:
F_19 ( V_2 ) ;
}
static void F_60 ( struct V_39 * V_40 ,
struct V_67 * V_68 ,
struct V_67 * V_110 )
{
int V_2 = F_22 ( V_40 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_13 = F_2 ( V_2 ) ;
struct V_100 * V_21 = V_1 -> V_21 ;
bool V_10 = F_6 () ;
F_25 ( L_23 ,
V_68 -> V_58 . V_2 , V_68 -> V_111 ,
V_68 -> V_112 , V_68 -> clock ,
V_68 -> V_70 , V_68 -> V_71 ,
V_68 -> V_72 , V_68 -> V_73 ,
V_68 -> V_85 , V_68 -> V_113 ,
V_68 -> V_114 , V_68 -> V_115 ,
V_68 -> type , V_68 -> V_116 ) ;
if ( V_10 && ( V_99 == V_2 ) )
return;
F_61 ( V_21 , V_110 ) ;
if ( V_10 && V_13 )
F_61 ( V_13 -> V_21 , V_110 ) ;
}
struct V_36 * F_62 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_36 * V_37 = NULL ;
struct V_38 * V_38 ;
int V_20 ;
V_38 = F_63 ( sizeof( * V_38 ) , V_117 ) ;
if ( ! V_38 )
return F_64 ( - V_80 ) ;
V_38 -> V_2 = V_2 ;
V_37 = & V_38 -> V_58 ;
V_20 = F_65 ( V_1 -> V_46 , V_37 ,
& V_118 , V_119 ) ;
if ( V_20 )
return F_64 ( V_20 ) ;
F_66 ( V_37 , & V_120 ) ;
V_37 -> V_121 = V_122 ;
V_37 -> V_123 = 0 ;
V_37 -> V_124 = 0 ;
F_67 ( V_37 , V_1 -> V_57 ) ;
return V_37 ;
}
struct V_39 * F_68 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_39 * V_40 = NULL ;
struct V_41 * V_41 ;
struct V_56 * V_57 ;
int V_20 ;
V_41 = F_69 ( V_1 -> V_46 -> V_46 ,
sizeof( * V_41 ) , V_117 ) ;
if ( ! V_41 ) {
V_20 = - V_80 ;
goto V_125;
}
V_41 -> V_2 = V_2 ;
V_57 = V_1 -> V_57 ;
V_40 = & V_41 -> V_58 ;
V_40 -> V_52 = & V_126 ;
V_20 = F_70 ( V_57 , V_40 , NULL ) ;
if ( V_20 )
goto V_125;
return V_40 ;
V_125:
if ( V_40 )
F_71 ( V_40 ) ;
return F_64 ( V_20 ) ;
}
struct V_36 * F_72 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_127 * V_46 = V_1 -> V_46 ;
struct V_56 * V_57 ;
struct V_39 * V_128 , * V_129 ;
struct V_36 * V_37 ;
struct V_130 * V_131 ;
V_128 = V_1 -> V_40 ;
V_129 = V_1 -> V_132 =
F_73 ( V_1 -> V_21 ) ;
V_57 = V_1 -> V_57 ;
F_70 ( V_57 , V_129 , V_128 ) ;
V_131 = & V_46 -> V_59 . V_131 ;
F_74 (connector, connector_list, head) {
int V_133 ;
for ( V_133 = 0 ; V_133 < V_134 ; V_133 ++ ) {
if ( V_37 -> V_135 [ V_133 ] == V_57 -> V_58 . V_2 )
return V_37 ;
}
}
return F_64 ( - V_136 ) ;
}
void F_71 ( struct V_39 * V_40 )
{
}
int F_75 ( int V_2 , const struct V_137 * V_138 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_139 = F_1 ( V_140 ) ;
struct V_100 * V_21 = V_1 -> V_21 ;
bool V_141 = ( V_138 -> V_142 && V_138 -> V_143 ) ;
bool V_144 = ( F_76 () && ! V_141 ) ;
int V_20 ;
if ( ! V_138 -> V_145 || ! V_138 -> V_146 )
return 0 ;
if ( V_144 && ( V_2 == V_140 ) )
return V_141 ? V_138 -> V_143 : V_138 -> V_146 ;
if ( V_144 && V_139 ) {
V_20 = F_77 ( V_139 -> V_21 , V_138 ) ;
if ( V_20 ) {
F_29 ( L_24 ,
V_79 , V_20 ) ;
return V_20 ;
}
}
V_20 = F_77 ( V_21 , V_138 ) ;
if ( V_20 ) {
F_29 ( L_25 , V_79 , V_20 ) ;
goto V_147;
}
V_20 = V_141 ? F_78 ( V_21 , V_138 ) :
F_79 ( V_21 , V_138 ) ;
F_80 ( V_21 , V_138 ) ;
V_147:
if ( V_144 && V_139 )
F_80 ( V_139 -> V_21 , V_138 ) ;
return V_20 ;
}
bool F_81 ( int V_2 , T_2 V_148 , T_2 V_149 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_139 = F_1 ( V_140 ) ;
struct V_100 * V_21 = V_1 -> V_21 ;
if ( F_76 () && ( V_2 == V_140 ) )
return false ;
if ( F_76 () && V_139 )
F_82 ( V_139 -> V_21 , V_148 , V_149 ) ;
F_82 ( V_21 , V_148 , V_149 ) ;
return true ;
}
void F_83 ( int V_2 , T_2 V_51 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_127 * V_46 = V_1 -> V_46 ;
struct V_44 * V_45 ;
struct V_48 * V_49 ;
struct V_56 * V_57 ;
if ( ! V_46 )
return;
V_45 = V_46 -> V_47 ;
V_49 = V_45 -> V_49 ;
V_57 = F_27 ( V_1 ) ;
if ( V_57 && V_49 -> V_52 -> V_53 )
if ( ! ( V_51 & V_55 ) )
V_49 -> V_52 -> V_53 ( V_49 , V_57 , true ) ;
}
int F_84 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = & V_3 ;
int V_2 = V_1 -> V_2 ;
int V_20 ;
if ( V_2 > V_5 ) {
F_29 ( L_26 , V_79 , V_2 ) ;
return - V_78 ;
}
if ( V_9 -> V_4 [ V_2 ] ) {
F_29 ( L_27 , V_79 , V_2 ) ;
return - V_150 ;
}
V_9 -> V_4 [ V_2 ] = V_1 ;
V_20 = F_3 ( V_1 -> V_151 -> V_46 . V_152 , V_2 ) ;
if ( V_20 ) {
F_29 ( L_28 , V_79 ) ;
goto V_125;
}
V_20 = F_5 ( V_2 ) ;
if ( V_20 ) {
F_29 ( L_29 ,
V_79 , V_2 ) ;
goto V_125;
}
return 0 ;
V_125:
V_9 -> V_4 [ V_2 ] = NULL ;
return V_20 ;
}
void F_85 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = & V_3 ;
if ( V_1 -> V_21 )
F_86 ( V_1 -> V_21 ) ;
V_9 -> V_4 [ V_1 -> V_2 ] = NULL ;
}
