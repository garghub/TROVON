static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 ) ;
}
static int F_4 ( struct V_1 * V_5 ,
T_1 V_6 , T_1 V_7 ,
T_2 V_8 , int V_9 )
{
unsigned int V_10 ;
F_5 ( & V_5 -> V_5 . V_3 , L_1 ,
V_6 , V_7 , V_8 , V_9 ) ;
V_10 = ( V_8 << 4 ) ;
F_6 ( & V_5 -> V_5 , V_6 , 0 ,
V_11 , V_10 ) ;
F_6 ( & V_5 -> V_5 , V_6 , 0 ,
V_12 , V_9 ) ;
return 0 ;
}
static void
F_7 ( struct V_1 * V_5 , T_1 V_7 ,
int V_13 , int V_14 )
{
int V_10 ;
V_10 = ( V_13 << 5 ) | ( V_14 & 0x1f ) ;
F_6 ( & V_5 -> V_5 , V_7 , 0 ,
V_15 , V_10 ) ;
}
static int F_8 ( struct V_1 * V_5 ,
T_1 V_6 , T_1 V_7 )
{
T_3 V_16 [ V_17 + V_18 ] ;
struct V_19 V_20 ;
T_4 * V_21 = ( T_4 * ) & V_20 ;
int V_22 ;
int V_23 ;
F_9 ( & V_20 ) ;
V_20 . V_24 = 2 ;
F_6 ( & V_5 -> V_5 , V_6 , 0 ,
V_25 , V_20 . V_24 - 1 ) ;
V_22 = F_10 ( & V_20 , V_16 , sizeof( V_16 ) ) ;
if ( V_22 < 0 )
return V_22 ;
F_7 ( V_5 , V_7 , 0x0 , 0x0 ) ;
F_6 ( & V_5 -> V_5 , V_7 , 0 ,
V_26 , V_27 ) ;
F_7 ( V_5 , V_7 , 0x0 , 0x0 ) ;
for ( V_23 = 0 ; V_23 < sizeof( V_20 ) ; V_23 ++ )
F_6 ( & V_5 -> V_5 , V_7 , 0 ,
V_28 , V_21 [ V_23 ] ) ;
F_7 ( V_5 , V_7 , 0x0 , 0x0 ) ;
F_6 ( & V_5 -> V_5 , V_7 , 0 ,
V_26 , V_29 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_30 ,
struct V_31 * V_32 , unsigned int V_33 )
{
if ( ! F_12 ( & V_30 -> V_5 , V_32 -> V_34 -> V_35 ,
V_33 ) )
F_6 ( & V_30 -> V_5 , V_32 -> V_34 -> V_35 , 0 ,
V_36 , V_33 ) ;
if ( ! F_12 ( & V_30 -> V_5 , V_32 -> V_37 -> V_35 ,
V_33 ) )
F_6 ( & V_30 -> V_5 , V_32 -> V_37 -> V_35 , 0 ,
V_36 , V_33 ) ;
}
static int F_13 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_5 = F_14 ( V_41 ) ;
struct V_42 * V_43 = V_5 -> V_44 ;
struct V_31 * V_32 ;
struct V_45 * V_46 ;
int V_22 ;
if ( V_41 -> V_47 > 0 ) {
F_15 ( & V_5 -> V_5 . V_3 , L_2 ) ;
return - V_48 ;
}
V_32 = & V_43 -> V_32 [ V_41 -> V_47 ] ;
V_46 = (struct V_45 * ) F_16 ( V_41 , V_39 ) ;
F_5 ( & V_5 -> V_5 . V_3 , L_3 ,
V_46 -> V_8 , V_46 -> V_9 ) ;
V_22 = F_8 ( V_5 , V_32 -> V_37 -> V_35 ,
V_32 -> V_34 -> V_35 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_4 ( V_5 , V_32 -> V_37 -> V_35 ,
V_32 -> V_34 -> V_35 , V_46 -> V_8 , V_46 -> V_9 ) ;
}
static int F_17 ( struct V_38 * V_39 ,
struct V_49 * V_50 , struct V_40 * V_41 )
{
struct V_1 * V_5 = F_14 ( V_41 ) ;
struct V_45 * V_46 ;
if ( V_41 -> V_47 > 0 ) {
F_15 ( & V_5 -> V_5 . V_3 , L_2 ) ;
return - V_48 ;
}
V_46 = F_18 ( sizeof( * V_46 ) , V_51 ) ;
if ( ! V_46 )
return - V_52 ;
V_46 -> V_9 = F_19 ( F_20 ( V_50 ) ,
F_21 ( V_50 ) , F_22 ( V_50 ) ,
24 , 0 ) ;
F_23 ( V_41 , V_39 , ( void * ) V_46 ) ;
return 0 ;
}
static int F_24 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_30 = F_14 ( V_41 ) ;
struct V_45 * V_46 ;
struct V_42 * V_43 = V_30 -> V_44 ;
struct V_31 * V_32 ;
V_32 = & V_43 -> V_32 [ V_41 -> V_47 ] ;
F_6 ( & V_30 -> V_5 , V_32 -> V_37 -> V_35 , 0 ,
V_11 , 0 ) ;
F_6 ( & V_30 -> V_5 , V_32 -> V_37 -> V_35 , 0 ,
V_12 , 0 ) ;
V_46 = (struct V_45 * ) F_16 ( V_41 , V_39 ) ;
F_23 ( V_41 , V_39 , NULL ) ;
F_25 ( V_46 ) ;
return 0 ;
}
static int F_26 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_5 = F_14 ( V_41 ) ;
struct V_42 * V_43 = V_5 -> V_44 ;
struct V_31 * V_32 ;
int V_10 ;
if ( V_41 -> V_47 > 0 ) {
F_15 ( & V_5 -> V_5 . V_3 , L_2 ) ;
return - V_48 ;
}
V_32 = & V_43 -> V_32 [ V_41 -> V_47 ] ;
V_10 = F_27 ( & V_5 -> V_5 , V_32 -> V_34 -> V_35 , 0 ,
V_53 , 0 ) ;
F_28 ( & V_5 -> V_5 . V_3 , L_4 , V_10 ) ;
if ( ( ! ( V_10 & V_54 ) ) || ( ! ( V_10 & V_55 ) ) ) {
F_15 ( & V_5 -> V_5 . V_3 , L_5 , V_10 ) ;
return - V_48 ;
}
F_11 ( V_5 , V_32 , V_56 ) ;
F_6 ( & V_5 -> V_5 , V_32 -> V_34 -> V_35 , 0 ,
V_57 , V_58 ) ;
F_29 ( V_39 -> V_59 , 0 ,
V_60 , 2 ) ;
return 0 ;
}
static void F_30 ( struct V_38 * V_39 ,
struct V_40 * V_41 )
{
struct V_1 * V_5 = F_14 ( V_41 ) ;
struct V_42 * V_43 = V_5 -> V_44 ;
struct V_31 * V_32 ;
V_32 = & V_43 -> V_32 [ V_41 -> V_47 ] ;
F_11 ( V_5 , V_32 , V_61 ) ;
F_6 ( & V_5 -> V_5 , V_32 -> V_34 -> V_35 , 0 ,
V_57 , V_62 ) ;
}
static int
F_31 ( struct V_4 * V_5 , struct V_63 * V_37 )
{
int V_64 ;
V_37 -> V_65 . V_66 = V_37 -> V_65 . V_67 = 2 ;
V_64 = F_32 ( V_5 , V_37 -> V_35 ,
& V_37 -> V_65 . V_68 ,
& V_37 -> V_65 . V_69 ,
& V_37 -> V_65 . V_70 ) ;
if ( V_64 < 0 )
F_15 ( & V_5 -> V_3 ,
L_6 ,
V_37 -> V_35 , V_64 ) ;
return V_64 ;
}
static void F_33 ( struct V_71 * V_72 ,
enum V_73 V_47 ,
const char * V_74 , const char * V_75 )
{
V_72 -> V_47 = V_47 ;
V_72 -> V_76 = V_74 ;
V_72 -> V_77 = V_75 ;
V_72 -> V_78 = V_79 ;
V_72 -> V_80 = 0 ;
V_72 -> V_81 = NULL ;
V_72 -> V_82 = 0 ;
V_72 -> V_83 = NULL ;
}
static void F_34 ( struct V_84 * V_85 ,
const char * V_86 , const char * V_87 , const char * V_88 )
{
V_85 -> V_86 = V_86 ;
V_85 -> V_89 = V_88 ;
V_85 -> V_87 = V_87 ;
V_85 -> V_90 = NULL ;
}
static void F_35 ( struct V_91 * V_92 ,
struct V_31 * V_32 )
{
struct V_84 V_85 [ 1 ] ;
struct V_71 V_93 [ 2 ] = { { 0 } } ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
F_33 ( & V_93 [ 0 ] , V_94 ,
L_7 , NULL ) ;
F_33 ( & V_93 [ 1 ] , V_95 ,
L_8 , L_9 ) ;
F_34 ( & V_85 [ 0 ] , L_7 , NULL , L_8 ) ;
F_36 ( V_92 , V_93 , F_37 ( V_93 ) ) ;
F_38 ( V_92 , V_85 , F_37 ( V_85 ) ) ;
}
static int F_39 ( struct V_1 * V_30 )
{
struct V_42 * V_43 = V_30 -> V_44 ;
struct V_31 * V_32 = & V_43 -> V_32 [ 0 ] ;
struct V_63 * V_37 ;
struct V_96 * V_34 ;
if ( F_40 ( & V_43 -> V_97 ) || F_40 ( & V_43 -> V_98 ) )
return - V_99 ;
V_37 = F_41 ( & V_43 -> V_97 , struct V_63 , V_100 ) ;
V_34 = F_41 ( & V_43 -> V_98 , struct V_96 , V_100 ) ;
V_32 -> V_101 = 0 ;
V_32 -> V_34 = V_34 ;
V_32 -> V_37 = V_37 ;
F_6 ( & V_30 -> V_5 , V_34 -> V_35 , 0 ,
V_102 , V_103 ) ;
F_6 ( & V_30 -> V_5 , V_37 -> V_35 , 0 ,
V_104 , 1 ) ;
F_6 ( & V_30 -> V_5 , V_37 -> V_35 , 0 ,
V_105 , 0 ) ;
F_6 ( & V_30 -> V_5 , V_34 -> V_35 , 0 ,
V_106 , 0 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_30 , T_1 V_35 )
{
struct V_42 * V_43 = V_30 -> V_44 ;
struct V_63 * V_37 ;
V_37 = F_18 ( sizeof( * V_37 ) , V_51 ) ;
if ( ! V_37 )
return - V_52 ;
V_37 -> V_35 = V_35 ;
F_43 ( & V_37 -> V_100 , & V_43 -> V_97 ) ;
V_43 -> V_107 ++ ;
return F_31 ( & V_30 -> V_5 , V_37 ) ;
}
static int F_44 ( struct V_1 * V_30 , T_1 V_35 )
{
struct V_42 * V_43 = V_30 -> V_44 ;
struct V_96 * V_34 ;
V_34 = F_18 ( sizeof( * V_34 ) , V_51 ) ;
if ( ! V_34 )
return - V_52 ;
V_34 -> V_35 = V_35 ;
F_43 ( & V_34 -> V_100 , & V_43 -> V_98 ) ;
V_43 -> V_108 ++ ;
return 0 ;
}
static int F_45 ( struct V_1 * V_30 )
{
T_1 V_35 ;
int V_23 , V_109 ;
struct V_4 * V_5 = & V_30 -> V_5 ;
struct V_42 * V_43 = V_30 -> V_44 ;
int V_22 ;
V_109 = F_46 ( V_5 , V_5 -> V_110 , & V_35 ) ;
if ( ! V_35 || V_109 <= 0 ) {
F_47 ( & V_5 -> V_3 , L_10 ) ;
return - V_99 ;
}
V_5 -> V_109 = V_109 ;
V_5 -> V_111 = V_35 ;
for ( V_23 = 0 ; V_23 < V_5 -> V_109 ; V_23 ++ , V_35 ++ ) {
unsigned int V_112 ;
unsigned int type ;
V_112 = F_48 ( V_5 , V_35 ) ;
type = F_49 ( V_112 ) ;
if ( ! ( V_112 & V_113 ) )
continue;
switch ( type ) {
case V_114 :
V_22 = F_42 ( V_30 , V_35 ) ;
if ( V_22 < 0 )
return V_22 ;
break;
case V_115 :
V_22 = F_44 ( V_30 , V_35 ) ;
if ( V_22 < 0 )
return V_22 ;
break;
}
}
V_5 -> V_116 = V_35 ;
if ( ! V_43 -> V_108 || ! V_43 -> V_107 )
return - V_117 ;
return F_39 ( V_30 ) ;
}
static int F_50 ( struct V_118 * V_119 )
{
struct V_1 * V_30 = F_51 ( V_119 ) ;
struct V_42 * V_43 = V_30 -> V_44 ;
struct V_91 * V_92 =
F_52 ( & V_119 -> V_120 ) ;
V_30 -> V_121 = V_119 ;
F_35 ( V_92 , & V_43 -> V_32 [ 0 ] ) ;
V_30 -> V_122 = V_92 -> V_122 -> V_123 ;
F_53 ( & V_30 -> V_5 . V_3 ) ;
F_54 ( & V_30 -> V_5 . V_3 ) ;
F_55 ( & V_30 -> V_5 . V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_118 * V_119 )
{
struct V_1 * V_30 = F_51 ( V_119 ) ;
F_57 ( & V_30 -> V_5 . V_3 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_30 )
{
struct V_4 * V_119 = & V_30 -> V_5 ;
struct V_42 * V_124 ;
int V_22 = 0 ;
V_124 = F_59 ( & V_119 -> V_3 , sizeof( * V_124 ) , V_51 ) ;
if ( V_124 == NULL )
return - V_52 ;
V_30 -> V_44 = V_124 ;
F_60 ( & V_119 -> V_3 , V_30 ) ;
F_61 ( & V_124 -> V_98 ) ;
F_61 ( & V_124 -> V_97 ) ;
V_22 = F_45 ( V_30 ) ;
if ( V_22 < 0 )
return V_22 ;
return F_62 ( & V_119 -> V_3 , & V_125 ,
V_126 , F_37 ( V_126 ) ) ;
}
static int F_63 ( struct V_1 * V_30 )
{
struct V_42 * V_43 = V_30 -> V_44 ;
struct V_96 * V_34 , * V_127 ;
struct V_63 * V_37 , * V_128 ;
F_64 ( & V_30 -> V_5 . V_3 ) ;
F_65 (cvt, cvt_next, &hdmi->cvt_list, head) {
F_66 ( & V_37 -> V_100 ) ;
F_25 ( V_37 ) ;
}
F_65 (pin, pin_next, &hdmi->pin_list, head) {
F_66 ( & V_34 -> V_100 ) ;
F_25 ( V_34 ) ;
}
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_30 -> V_5 ;
struct V_129 * V_130 = V_5 -> V_130 ;
int V_64 ;
F_5 ( V_3 , L_11 , V_131 ) ;
if ( ! V_130 )
return 0 ;
if ( ! F_12 ( V_5 , V_5 -> V_110 , V_61 ) )
F_6 ( V_5 , V_5 -> V_110 , 0 ,
V_36 , V_61 ) ;
V_64 = F_68 ( V_130 , false ) ;
if ( V_64 < 0 ) {
F_15 ( V_130 -> V_3 , L_12 ) ;
return V_64 ;
}
return 0 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_30 -> V_5 ;
struct V_129 * V_130 = V_5 -> V_130 ;
int V_64 ;
F_5 ( V_3 , L_11 , V_131 ) ;
if ( ! V_130 )
return 0 ;
V_64 = F_68 ( V_130 , true ) ;
if ( V_64 < 0 ) {
F_15 ( V_130 -> V_3 , L_12 ) ;
return V_64 ;
}
if ( ! F_12 ( V_5 , V_5 -> V_110 , V_56 ) )
F_6 ( V_5 , V_5 -> V_110 , 0 ,
V_36 , V_56 ) ;
return 0 ;
}
static int T_5 F_70 ( void )
{
return F_71 ( & V_132 ) ;
}
static void T_6 F_72 ( void )
{
F_73 ( & V_132 ) ;
}
