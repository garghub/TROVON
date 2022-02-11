static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + ( V_3 << V_5 ) ) ;
}
static inline void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_6 )
{
F_4 ( V_6 , V_2 -> V_4 + ( V_3 << V_5 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_7 ;
T_1 V_6 ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
F_3 ( V_2 , V_9 , V_3 ) ;
F_7 () ;
V_6 = F_1 ( V_2 , V_10 ) ;
F_8 ( & V_2 -> V_8 , V_7 ) ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_6 )
{
unsigned long V_7 ;
F_6 ( & V_2 -> V_8 , V_7 ) ;
F_3 ( V_2 , V_9 , V_3 ) ;
F_7 () ;
F_3 ( V_2 , V_10 , V_6 ) ;
F_7 () ;
F_8 ( & V_2 -> V_8 , V_7 ) ;
}
static T_2 F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_6 ;
V_6 = F_11 ( V_2 , V_3 ) << 16 ;
V_6 |= F_11 ( V_2 , V_3 + 2 ) ;
return V_6 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_6 )
{
F_13 ( V_2 , V_3 , V_6 >> 16 ) ;
F_13 ( V_2 , V_3 + 2 , V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_11 )
{
unsigned long V_12 = V_13 + F_15 ( 100 ) ;
F_13 ( V_2 , V_14 , V_11 ) ;
F_7 () ;
while ( F_11 ( V_2 , V_14 ) != 0 ) {
if ( F_16 ( V_13 , V_12 ) )
return - V_15 ;
F_17 () ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 , T_3 * V_16 , int V_17 )
{
T_1 V_18 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 += 2 ) {
V_18 = F_11 ( V_2 , V_20 ) ;
* V_16 ++ = V_18 >> 8 ;
* V_16 ++ = V_18 ;
}
V_18 = F_11 ( V_2 , V_20 ) ;
V_18 = F_11 ( V_2 , V_20 ) ;
}
static void F_19 ( struct V_1 * V_2 , T_3 * V_16 , int V_17 )
{
T_1 V_18 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_17 ; V_19 += 2 ) {
V_18 = * V_16 ++ << 8 ;
V_18 |= * V_16 ++ ;
F_13 ( V_2 , V_21 , V_18 ) ;
}
F_12 ( V_2 , V_22 , V_17 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
F_12 ( V_2 , V_25 ,
V_24 -> V_26 [ 0 ] << 24 |
V_24 -> V_26 [ 1 ] << 16 |
V_24 -> V_26 [ 2 ] << 8 |
V_24 -> V_26 [ 3 ] ) ;
F_13 ( V_2 , V_27 ,
V_24 -> V_26 [ 4 ] << 8 |
V_24 -> V_26 [ 5 ] ) ;
F_7 () ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_28 , V_29 ) ;
F_7 () ;
F_22 ( 5 ) ;
F_3 ( V_2 , V_28 , V_2 -> V_30 ?
F_23 ( 7 ) | V_31 | V_32 :
F_23 ( 7 ) | V_31 ) ;
F_7 () ;
F_13 ( V_2 , V_33 , 0 ) ;
F_20 ( V_2 ) ;
F_12 ( V_2 , V_34 , 64 << 24 ) ;
F_12 ( V_2 , V_35 , 0 ) ;
F_12 ( V_2 , V_36 , 64 << 24 ) ;
F_12 ( V_2 , V_37 , 0 ) ;
F_13 ( V_2 , V_38 , 0x00ff ) ;
F_7 () ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_39 , V_2 -> V_40 ?
V_41 : V_42 ) ;
F_7 () ;
F_14 ( V_2 , V_43 ) ;
F_13 ( V_2 , V_44 , V_45 | V_46 ) ;
F_13 ( V_2 , V_33 , V_47 ) ;
F_7 () ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_33 , 0 ) ;
F_7 () ;
F_14 ( V_2 , V_48 ) ;
}
static void F_26 ( struct V_23 * V_24 ,
struct V_49 * V_50 )
{
F_27 ( V_50 -> V_51 , V_52 , sizeof( V_50 -> V_51 ) ) ;
F_27 ( V_50 -> V_53 , V_54 , sizeof( V_50 -> V_53 ) ) ;
F_27 ( V_50 -> V_55 , F_28 ( V_24 -> V_56 . V_57 ) ,
sizeof( V_50 -> V_55 ) ) ;
}
static T_2 F_29 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
if ( F_31 ( V_2 -> V_58 ) )
return ! ! F_32 ( V_2 -> V_58 ) ;
return 1 ;
}
static T_2 F_33 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
return V_2 -> V_59 ;
}
static void F_34 ( struct V_23 * V_24 , T_2 V_60 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
V_2 -> V_59 = V_60 ;
}
static int F_35 ( struct V_23 * V_24 )
{
return V_61 ;
}
static void F_36 ( struct V_23 * V_24 ,
struct V_62 * V_63 , void * V_64 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
T_3 * V_16 = V_64 ;
T_1 V_3 ;
T_1 V_6 ;
V_63 -> V_53 = 1 ;
for ( V_3 = 0 ; V_3 < V_61 ; V_3 += 2 ) {
switch ( V_3 & 0x23f ) {
case V_21 :
case V_20 :
V_6 = 0xffff ;
break;
default:
V_6 = F_11 ( V_2 , V_3 ) ;
break;
}
* V_16 ++ = V_6 >> 8 ;
* V_16 ++ = V_6 ;
}
}
static void F_37 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
F_38 ( V_24 ) ;
F_21 ( V_2 ) ;
F_24 ( V_2 ) ;
V_24 -> V_65 . V_66 ++ ;
V_24 -> V_67 = V_13 ;
F_39 ( V_24 ) ;
}
static int F_40 ( struct V_68 * V_69 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
F_38 ( V_24 ) ;
F_19 ( V_2 , V_69 -> V_6 , V_69 -> V_17 ) ;
F_7 () ;
V_24 -> V_65 . V_70 ++ ;
V_24 -> V_65 . V_71 += V_69 -> V_17 ;
F_41 ( V_69 ) ;
F_42 ( V_2 , V_72 , V_24 , L_1 ) ;
F_14 ( V_2 , V_73 ) ;
return V_74 ;
}
static int F_43 ( struct V_75 * V_76 , int V_77 )
{
struct V_1 * V_2 = F_44 ( V_76 , struct V_1 , V_76 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
struct V_68 * V_69 ;
int V_78 ;
T_1 V_79 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
T_2 V_80 = F_10 ( V_2 , V_81 ) ;
if ( V_80 == 0 )
break;
V_79 = F_11 ( V_2 , V_20 ) ;
V_69 = F_45 ( V_24 , F_46 ( V_79 , 2 ) ) ;
if ( F_47 ( ! V_69 ) ) {
T_2 V_19 ;
for ( V_19 = 0 ; V_19 < V_80 ; V_19 += 2 )
F_11 ( V_2 , V_20 ) ;
V_24 -> V_65 . V_82 ++ ;
return - V_83 ;
}
F_48 ( V_69 , V_79 ) ;
F_18 ( V_2 , V_69 -> V_6 , V_79 ) ;
V_69 -> V_84 = F_49 ( V_69 , V_24 ) ;
F_50 ( V_69 ) ;
V_24 -> V_65 . V_85 ++ ;
V_24 -> V_65 . V_86 += V_79 ;
}
if ( V_78 < V_77 ) {
F_13 ( V_2 , V_33 , V_47 ) ;
F_7 () ;
F_51 ( V_76 ) ;
}
return V_78 ;
}
static T_4 F_52 ( int V_87 , void * V_88 )
{
struct V_23 * V_24 = V_88 ;
struct V_1 * V_2 = F_30 ( V_24 ) ;
int V_89 = F_11 ( V_2 , V_90 ) ;
if ( ! V_89 )
return V_91 ;
F_13 ( V_2 , V_90 , V_89 ) ;
F_7 () ;
if ( V_89 & V_46 ) {
F_42 ( V_2 , V_92 , V_24 , L_2 ) ;
F_39 ( V_24 ) ;
}
if ( V_89 & V_45 ) {
if ( F_53 ( & V_2 -> V_76 ) ) {
F_13 ( V_2 , V_33 , 0 ) ;
F_7 () ;
F_54 ( & V_2 -> V_76 ) ;
}
}
return V_93 ;
}
static T_4 F_55 ( int V_87 , void * V_88 )
{
struct V_23 * V_24 = V_88 ;
struct V_1 * V_2 = F_30 ( V_24 ) ;
if ( F_56 ( V_24 ) ) {
if ( F_32 ( V_2 -> V_58 ) != 0 ) {
F_57 ( V_2 , V_94 , V_24 , L_3 ) ;
F_58 ( V_24 ) ;
} else {
F_57 ( V_2 , V_94 , V_24 , L_4 ) ;
F_59 ( V_24 ) ;
}
}
return V_93 ;
}
static void F_60 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
bool V_95 = ( V_24 -> V_7 & V_96 ) != 0 ;
if ( V_2 -> V_40 != V_95 ) {
V_2 -> V_40 = V_95 ;
F_24 ( V_2 ) ;
}
}
static int F_61 ( struct V_23 * V_24 , void * V_3 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
struct V_97 * V_98 = V_3 ;
if ( ! F_62 ( V_98 -> V_99 ) )
return - V_100 ;
memcpy ( V_24 -> V_26 , V_98 -> V_99 , V_101 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
F_57 ( V_2 , V_102 , V_24 , L_5 ) ;
F_24 ( V_2 ) ;
F_64 ( & V_2 -> V_76 ) ;
F_65 ( V_24 ) ;
if ( ! F_31 ( V_2 -> V_58 ) ||
F_32 ( V_2 -> V_58 ) != 0 )
F_58 ( V_24 ) ;
return 0 ;
}
static int F_66 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_30 ( V_24 ) ;
F_57 ( V_2 , V_103 , V_24 , L_6 ) ;
F_25 ( V_2 ) ;
F_59 ( V_24 ) ;
F_38 ( V_24 ) ;
F_67 ( & V_2 -> V_76 ) ;
return 0 ;
}
static int F_68 ( struct V_104 * V_105 )
{
struct V_106 * V_6 = F_69 ( & V_105 -> V_56 ) ;
struct V_23 * V_24 = F_70 ( V_105 ) ;
struct V_1 * V_2 = F_30 ( V_24 ) ;
const char * V_107 = F_71 ( V_24 ) ;
struct V_108 * V_109 ;
int V_110 ;
int V_87 ;
int V_111 ;
if ( V_6 && F_62 ( V_6 -> V_112 ) ) {
memcpy ( V_24 -> V_26 , V_6 -> V_112 , V_101 ) ;
} else {
F_72 ( V_24 ) ;
}
V_109 = F_73 ( V_105 , V_113 , 0 ) ;
V_2 -> V_4 = F_74 ( & V_105 -> V_56 , V_109 ) ;
if ( F_75 ( V_2 -> V_4 ) )
return F_76 ( V_2 -> V_4 ) ;
V_110 = F_77 ( V_109 ) ;
F_78 ( & V_2 -> V_8 ) ;
V_2 -> V_30 = V_110 < V_114 ;
if ( V_2 -> V_30 ) {
V_2 -> V_115 = F_5 ;
V_2 -> V_116 = F_9 ;
} else {
V_2 -> V_115 = F_1 ;
V_2 -> V_116 = F_3 ;
}
F_21 ( V_2 ) ;
if ( F_11 ( V_2 , V_117 ) != V_118 )
return - V_119 ;
V_87 = F_79 ( V_105 , 0 ) ;
if ( V_87 < 0 )
return V_87 ;
V_111 = F_80 ( V_87 , F_52 ,
V_120 , V_107 , V_24 ) ;
if ( V_111 < 0 )
return V_111 ;
V_2 -> V_87 = V_87 ;
V_2 -> V_58 = V_6 ? V_6 -> V_58 : - V_121 ;
if ( F_31 ( V_2 -> V_58 ) ) {
char * V_122 = F_81 ( & V_105 -> V_56 , 16 , V_123 ) ;
if ( ! V_122 )
return - V_83 ;
snprintf ( V_122 , 16 , L_7 , V_107 ) ;
V_2 -> V_124 = F_82 ( V_2 -> V_58 ) ;
if ( F_83 ( V_2 -> V_124 , F_55 ,
V_125 | V_126 ,
V_122 , V_2 -> V_24 ) < 0 )
V_2 -> V_58 = - V_121 ;
}
F_84 ( V_24 , L_8 , ( V_127 ) V_109 -> V_128 , V_87 ) ;
return 0 ;
}
static int F_85 ( struct V_104 * V_105 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
int V_129 ;
V_24 = F_86 ( sizeof( * V_2 ) ) ;
if ( ! V_24 )
return - V_83 ;
F_87 ( V_24 , & V_105 -> V_56 ) ;
F_88 ( V_105 , V_24 ) ;
V_2 = F_30 ( V_24 ) ;
V_2 -> V_24 = V_24 ;
V_24 -> V_130 = & V_131 ;
V_24 -> V_132 = & V_133 ;
V_24 -> V_134 = V_135 ;
F_89 ( V_24 , & V_2 -> V_76 , F_43 , 16 ) ;
V_24 -> V_136 |= V_137 ;
V_129 = F_90 ( V_24 ) ;
if ( V_129 < 0 )
goto V_138;
V_129 = F_68 ( V_105 ) ;
if ( V_129 < 0 )
goto V_139;
return 0 ;
V_139:
F_91 ( V_24 ) ;
V_138:
F_92 ( V_24 ) ;
return V_129 ;
}
static int F_93 ( struct V_104 * V_105 )
{
struct V_23 * V_24 = F_70 ( V_105 ) ;
struct V_1 * V_2 = F_30 ( V_24 ) ;
F_21 ( V_2 ) ;
F_94 ( V_2 -> V_87 , V_24 ) ;
if ( F_31 ( V_2 -> V_58 ) )
F_94 ( V_2 -> V_124 , V_24 ) ;
F_91 ( V_24 ) ;
F_92 ( V_24 ) ;
return 0 ;
}
static int F_95 ( struct V_140 * V_56 )
{
struct V_104 * V_105 = F_96 ( V_56 ) ;
struct V_23 * V_24 = F_70 ( V_105 ) ;
struct V_1 * V_2 = F_30 ( V_24 ) ;
if ( F_56 ( V_24 ) ) {
F_59 ( V_24 ) ;
F_97 ( V_24 ) ;
F_25 ( V_2 ) ;
}
return 0 ;
}
static int F_98 ( struct V_140 * V_56 )
{
struct V_104 * V_105 = F_96 ( V_56 ) ;
struct V_23 * V_24 = F_70 ( V_105 ) ;
struct V_1 * V_2 = F_30 ( V_24 ) ;
if ( ! F_56 ( V_24 ) ) {
F_21 ( V_2 ) ;
F_24 ( V_2 ) ;
F_99 ( V_24 ) ;
if ( ! F_31 ( V_2 -> V_58 ) ||
F_32 ( V_2 -> V_58 ) != 0 )
F_58 ( V_24 ) ;
}
return 0 ;
}
