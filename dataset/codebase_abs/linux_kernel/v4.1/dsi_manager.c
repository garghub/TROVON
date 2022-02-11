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
static inline int F_5 ( struct V_13 * V_14 )
{
struct V_15 * V_15 = F_6 ( V_14 ) ;
return V_15 -> V_2 ;
}
static int F_7 ( struct V_16 * V_17 )
{
struct V_18 * V_18 = F_8 ( V_17 ) ;
return V_18 -> V_2 ;
}
static enum V_19 F_9 (
struct V_13 * V_14 , bool V_20 )
{
int V_2 = F_5 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_21 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_14 -> V_24 -> V_25 ;
struct V_26 * V_27 = V_23 -> V_27 ;
F_10 ( L_4 , V_2 ) ;
if ( ! V_1 -> V_28 ) {
V_1 -> V_28 = F_11 ( V_1 -> V_29 ,
& V_1 -> V_30 ) ;
if ( ! V_1 -> V_28 && F_12 () &&
! F_13 ( V_2 ) && V_21 )
V_1 -> V_28 = F_11 (
V_21 -> V_29 , NULL ) ;
if ( V_1 -> V_28 && F_12 () )
F_14 ( & V_14 -> V_31 ,
V_14 -> V_24 -> V_32 . V_33 , 0 ) ;
if ( V_1 -> V_28 && F_12 () &&
V_21 && V_21 -> V_28 ) {
bool V_34 = ! ( V_1 -> V_30 &
V_35 ) ;
struct V_36 * V_37 = F_15 (
F_1 ( V_38 ) ) ;
struct V_36 * V_39 = F_15 (
F_1 ( V_40 ) ) ;
if ( V_27 -> V_41 -> V_42 )
V_27 -> V_41 -> V_42 ( V_27 , V_37 ,
V_39 , V_34 ) ;
else
F_16 ( L_5 ) ;
}
}
return V_1 -> V_28 ? V_43 :
V_44 ;
}
static void F_17 ( struct V_13 * V_14 )
{
F_10 ( L_6 ) ;
F_18 ( V_14 ) ;
F_19 ( V_14 ) ;
}
static void F_20 ( struct V_13 * V_14 )
{
struct V_45 * V_46 , * V_47 ;
F_21 (mode, m, &connector->probed_modes, head) {
V_46 -> clock >>= 1 ;
V_46 -> V_48 >>= 1 ;
V_46 -> V_49 >>= 1 ;
V_46 -> V_50 >>= 1 ;
V_46 -> V_51 >>= 1 ;
F_22 ( V_46 ) ;
}
}
static int F_23 (
struct V_13 * V_14 , int V_2 )
{
struct V_45 * V_46 ;
char V_52 [ 8 ] = { 'M' , 'S' , 'M' , 'D' , 'U' , 'D' , 'S' , 'I' } ;
if ( V_14 -> V_53 ) {
F_10 ( L_7 ) ;
return 0 ;
}
V_46 = F_24 ( & V_14 -> V_54 ,
struct V_45 ,
V_55 ) ;
if ( ! V_46 )
return - V_56 ;
V_14 -> V_53 = F_25 (
V_14 -> V_24 , V_52 ) ;
if ( ! V_14 -> V_53 )
V_14 -> V_53 = F_26 (
V_14 -> V_24 , V_52 ) ;
if ( ! V_14 -> V_53 ) {
F_16 ( L_8 , V_57 ) ;
return - V_58 ;
}
V_14 -> V_59 = true ;
V_14 -> V_60 = true ;
V_14 -> V_61 = V_46 -> V_48 ;
V_14 -> V_62 = V_46 -> V_63 ;
V_14 -> V_64 = 2 ;
V_14 -> V_65 = 1 ;
V_14 -> V_66 = 0 ;
V_14 -> V_67 = ( V_2 == V_68 ) ? 1 : 0 ;
return 0 ;
}
static int F_27 ( struct V_13 * V_14 )
{
int V_2 = F_5 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_69 * V_28 = V_1 -> V_28 ;
int V_70 , V_71 ;
if ( ! V_28 )
return 0 ;
F_28 ( V_28 , V_14 ) ;
V_71 = F_29 ( V_28 ) ;
F_30 ( V_28 ) ;
if ( ! V_71 )
return 0 ;
if ( F_12 () ) {
F_20 ( V_14 ) ;
V_70 = F_23 ( V_14 , V_2 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_31 ( V_14 ) ;
if ( V_70 ) {
F_16 ( L_9 ,
V_57 , V_70 ) ;
return V_70 ;
}
}
return V_71 ;
}
static int F_32 ( struct V_13 * V_14 ,
struct V_45 * V_46 )
{
int V_2 = F_5 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_36 * V_37 = F_15 ( V_1 ) ;
struct V_22 * V_23 = V_14 -> V_24 -> V_25 ;
struct V_26 * V_27 = V_23 -> V_27 ;
long V_72 , V_73 ;
F_10 ( L_6 ) ;
V_73 = 1000 * V_46 -> clock ;
V_72 = V_27 -> V_41 -> V_74 ( V_27 , V_73 , V_37 ) ;
F_10 ( L_10 , V_73 , V_72 ) ;
if ( V_72 != V_73 )
return V_75 ;
return V_76 ;
}
static struct V_36 *
F_33 ( struct V_13 * V_14 )
{
int V_2 = F_5 ( V_14 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
F_10 ( L_6 ) ;
return F_15 ( V_1 ) ;
}
static void F_34 ( struct V_16 * V_17 )
{
int V_2 = F_7 ( V_17 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_77 = F_1 ( V_78 ) ;
struct V_79 * V_29 = V_1 -> V_29 ;
struct V_69 * V_28 = V_1 -> V_28 ;
bool V_10 = F_12 () ;
int V_70 ;
F_10 ( L_4 , V_2 ) ;
if ( ! V_28 || ( V_10 && ( V_78 == V_2 ) ) )
return;
V_70 = F_35 ( V_29 ) ;
if ( V_70 ) {
F_16 ( L_11 , V_57 , V_2 , V_70 ) ;
goto V_80;
}
if ( V_10 && V_77 ) {
V_70 = F_35 ( V_77 -> V_29 ) ;
if ( V_70 ) {
F_16 ( L_12 ,
V_57 , V_70 ) ;
goto V_81;
}
}
V_70 = F_36 ( V_28 ) ;
if ( V_70 ) {
F_16 ( L_13 , V_57 , V_2 , V_70 ) ;
goto V_82;
}
V_70 = F_37 ( V_29 ) ;
if ( V_70 ) {
F_16 ( L_14 , V_57 , V_2 , V_70 ) ;
goto V_83;
}
if ( V_10 && V_77 ) {
V_70 = F_37 ( V_77 -> V_29 ) ;
if ( V_70 ) {
F_16 ( L_15 , V_57 , V_70 ) ;
goto V_84;
}
}
V_70 = F_38 ( V_28 ) ;
if ( V_70 ) {
F_16 ( L_16 , V_57 , V_2 , V_70 ) ;
goto V_85;
}
return;
V_85:
if ( V_10 && V_77 )
F_39 ( V_77 -> V_29 ) ;
V_84:
F_39 ( V_29 ) ;
V_83:
F_40 ( V_28 ) ;
V_82:
if ( V_10 && V_77 )
F_41 ( V_77 -> V_29 ) ;
V_81:
F_41 ( V_29 ) ;
V_80:
return;
}
static void F_42 ( struct V_16 * V_17 )
{
F_10 ( L_6 ) ;
}
static void F_43 ( struct V_16 * V_17 )
{
F_10 ( L_6 ) ;
}
static void F_44 ( struct V_16 * V_17 )
{
int V_2 = F_7 ( V_17 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_77 = F_1 ( V_78 ) ;
struct V_79 * V_29 = V_1 -> V_29 ;
struct V_69 * V_28 = V_1 -> V_28 ;
bool V_10 = F_12 () ;
int V_70 ;
F_10 ( L_4 , V_2 ) ;
if ( ! V_28 || ( V_10 && ( V_78 == V_2 ) ) )
return;
V_70 = F_45 ( V_28 ) ;
if ( V_70 )
F_16 ( L_17 , V_57 , V_2 , V_70 ) ;
V_70 = F_39 ( V_29 ) ;
if ( V_70 )
F_16 ( L_18 , V_57 , V_2 , V_70 ) ;
if ( V_10 && V_77 ) {
V_70 = F_39 ( V_77 -> V_29 ) ;
if ( V_70 )
F_16 ( L_19 , V_57 , V_70 ) ;
}
V_70 = F_40 ( V_28 ) ;
if ( V_70 )
F_16 ( L_20 , V_57 , V_2 , V_70 ) ;
V_70 = F_41 ( V_29 ) ;
if ( V_70 )
F_16 ( L_21 , V_57 , V_2 , V_70 ) ;
if ( V_10 && V_77 ) {
V_70 = F_41 ( V_77 -> V_29 ) ;
if ( V_70 )
F_16 ( L_22 ,
V_57 , V_70 ) ;
}
}
static void F_46 ( struct V_16 * V_17 ,
struct V_45 * V_46 ,
struct V_45 * V_86 )
{
int V_2 = F_7 ( V_17 ) ;
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_21 = F_2 ( V_2 ) ;
struct V_79 * V_29 = V_1 -> V_29 ;
bool V_10 = F_12 () ;
F_10 ( L_23 ,
V_46 -> V_31 . V_2 , V_46 -> V_87 ,
V_46 -> V_88 , V_46 -> clock ,
V_46 -> V_48 , V_46 -> V_49 ,
V_46 -> V_50 , V_46 -> V_51 ,
V_46 -> V_63 , V_46 -> V_89 ,
V_46 -> V_90 , V_46 -> V_91 ,
V_46 -> type , V_46 -> V_92 ) ;
if ( V_10 && ( V_78 == V_2 ) )
return;
F_47 ( V_29 , V_86 ) ;
if ( V_10 && V_21 )
F_47 ( V_21 -> V_29 , V_86 ) ;
}
struct V_13 * F_48 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_13 * V_14 = NULL ;
struct V_15 * V_15 ;
int V_70 , V_93 ;
V_15 = F_49 ( V_1 -> V_24 -> V_24 ,
sizeof( * V_15 ) , V_94 ) ;
if ( ! V_15 ) {
V_70 = - V_58 ;
goto V_95;
}
V_15 -> V_2 = V_2 ;
V_14 = & V_15 -> V_31 ;
V_70 = F_50 ( V_1 -> V_24 , V_14 ,
& V_96 , V_97 ) ;
if ( V_70 )
goto V_95;
F_51 ( V_14 , & V_98 ) ;
V_14 -> V_99 = V_100 ;
V_14 -> V_101 = 0 ;
V_14 -> V_102 = 0 ;
V_70 = F_52 ( V_14 ) ;
if ( V_70 )
goto V_95;
for ( V_93 = 0 ; V_93 < V_103 ; V_93 ++ )
F_53 ( V_14 ,
V_1 -> V_104 [ V_93 ] ) ;
return V_14 ;
V_95:
if ( V_14 )
F_17 ( V_14 ) ;
return F_54 ( V_70 ) ;
}
struct V_16 * F_55 ( T_1 V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_16 * V_17 = NULL ;
struct V_18 * V_18 ;
int V_70 ;
V_18 = F_49 ( V_1 -> V_24 -> V_24 ,
sizeof( * V_18 ) , V_94 ) ;
if ( ! V_18 ) {
V_70 = - V_58 ;
goto V_95;
}
V_18 -> V_2 = V_2 ;
V_17 = & V_18 -> V_31 ;
V_17 -> V_41 = & V_105 ;
V_70 = F_56 ( V_1 -> V_24 , V_17 ) ;
if ( V_70 )
goto V_95;
return V_17 ;
V_95:
if ( V_17 )
F_57 ( V_17 ) ;
return F_54 ( V_70 ) ;
}
void F_57 ( struct V_16 * V_17 )
{
}
int F_58 ( int V_2 ,
const unsigned long V_106 , const unsigned long V_107 ,
T_2 * V_108 , T_2 * V_109 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_110 * V_111 = V_1 -> V_111 ;
int V_70 ;
V_70 = F_59 ( V_111 , F_12 () , V_106 , V_107 ) ;
if ( V_70 )
return V_70 ;
V_1 -> V_112 = true ;
F_60 ( V_111 , V_108 , V_109 ) ;
return 0 ;
}
void F_61 ( int V_2 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_113 = F_1 ( V_114 ) ;
struct V_1 * V_115 = F_1 ( V_116 ) ;
struct V_110 * V_111 = V_1 -> V_111 ;
V_1 -> V_112 = false ;
if ( F_12 () && V_113 && V_115 ) {
if ( ! V_113 -> V_112 && ! V_115 -> V_112 ) {
F_62 ( V_115 -> V_111 ) ;
F_62 ( V_113 -> V_111 ) ;
}
} else {
F_62 ( V_111 ) ;
}
}
int F_63 ( int V_2 , const struct V_117 * V_118 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_119 = F_1 ( V_120 ) ;
struct V_79 * V_29 = V_1 -> V_29 ;
bool V_121 = ( V_118 -> V_122 && V_118 -> V_123 ) ;
bool V_124 = ( F_64 () && ! V_121 ) ;
int V_70 ;
if ( ! V_118 -> V_125 || ! V_118 -> V_126 )
return 0 ;
if ( V_124 && ( V_2 == V_120 ) )
return V_121 ? V_118 -> V_123 : V_118 -> V_126 ;
if ( V_124 && V_119 ) {
V_70 = F_65 ( V_119 -> V_29 , V_118 ) ;
if ( V_70 ) {
F_16 ( L_24 ,
V_57 , V_70 ) ;
return V_70 ;
}
}
V_70 = F_65 ( V_29 , V_118 ) ;
if ( V_70 ) {
F_16 ( L_25 , V_57 , V_70 ) ;
goto V_127;
}
V_70 = V_121 ? F_66 ( V_29 , V_118 ) :
F_67 ( V_29 , V_118 ) ;
F_68 ( V_29 , V_118 ) ;
V_127:
if ( V_124 && V_119 )
F_68 ( V_119 -> V_29 , V_118 ) ;
return V_70 ;
}
bool F_69 ( int V_2 , T_2 V_128 , T_2 V_129 )
{
struct V_1 * V_1 = F_1 ( V_2 ) ;
struct V_1 * V_119 = F_1 ( V_120 ) ;
struct V_79 * V_29 = V_1 -> V_29 ;
if ( F_64 () && ( V_2 == V_120 ) )
return false ;
if ( F_64 () && V_119 )
F_70 ( V_119 -> V_29 , V_128 , V_129 ) ;
F_70 ( V_29 , V_128 , V_129 ) ;
return true ;
}
int F_71 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = & V_3 ;
int V_2 = V_1 -> V_2 ;
struct V_1 * V_21 = F_2 ( V_2 ) ;
int V_70 ;
if ( V_2 > V_5 ) {
F_16 ( L_26 , V_57 , V_2 ) ;
return - V_56 ;
}
if ( V_9 -> V_4 [ V_2 ] ) {
F_16 ( L_27 , V_57 , V_2 ) ;
return - V_130 ;
}
V_9 -> V_4 [ V_2 ] = V_1 ;
V_70 = F_3 ( V_1 -> V_131 -> V_24 . V_132 , V_2 ) ;
if ( V_70 ) {
F_16 ( L_28 , V_57 ) ;
return V_70 ;
}
if ( ! F_12 () ) {
V_70 = F_72 ( V_1 -> V_29 , true ) ;
} else if ( ! V_21 ) {
return 0 ;
} else {
struct V_1 * V_113 = F_13 ( V_2 ) ?
V_1 : V_21 ;
struct V_1 * V_115 = F_13 ( V_2 ) ?
V_21 : V_1 ;
V_70 = F_72 ( V_115 -> V_29 , false ) ;
if ( V_70 )
return V_70 ;
V_70 = F_72 ( V_113 -> V_29 , true ) ;
}
return V_70 ;
}
void F_73 ( struct V_1 * V_1 )
{
struct V_8 * V_9 = & V_3 ;
if ( V_1 -> V_29 )
F_74 ( V_1 -> V_29 ) ;
V_9 -> V_4 [ V_1 -> V_2 ] = NULL ;
}
