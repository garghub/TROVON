static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
struct V_5 V_6 [ 2 ] ;
T_1 V_7 , V_8 = 0 ;
if ( ! V_2 -> V_9 )
return - V_10 ;
V_6 [ 0 ] . V_11 = V_2 -> V_11 ;
V_6 [ 0 ] . V_12 = 0 ;
V_6 [ 0 ] . V_13 = 1 ;
V_6 [ 0 ] . V_14 = & V_7 ;
V_6 [ 1 ] . V_11 = V_2 -> V_11 ;
V_6 [ 1 ] . V_12 = V_15 ;
V_6 [ 1 ] . V_13 = 1 ;
V_6 [ 1 ] . V_14 = & V_8 ;
V_7 = V_3 ;
V_4 = F_2 ( V_2 -> V_9 , V_6 , 2 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_8 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_16 )
{
int V_4 ;
struct V_5 V_6 [ 1 ] ;
unsigned char V_17 [ 2 ] ;
if ( ! V_2 -> V_9 )
return - V_10 ;
V_6 -> V_11 = V_2 -> V_11 ;
V_6 -> V_12 = 0 ;
V_6 -> V_13 = 2 ;
V_6 -> V_14 = V_17 ;
V_17 [ 0 ] = V_3 ;
V_17 [ 1 ] = V_16 ;
V_4 = F_2 ( V_2 -> V_9 , V_6 , 1 ) ;
if ( V_4 >= 0 )
return 0 ;
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_16 , T_1 V_18 )
{
int V_19 ;
V_19 = F_1 ( V_2 , V_3 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 &= ( ~ V_18 ) ;
V_16 &= V_18 ;
V_16 |= V_19 ;
V_19 = F_3 ( V_2 , V_3 , V_16 ) ;
if ( V_19 )
return V_19 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
const struct V_20 * V_21 )
{
int V_4 ;
const struct V_20 * V_22 = V_21 ;
while ( ! ( ( V_22 -> V_3 == V_23 )
&& ( V_22 -> V_16 == V_24 ) ) ) {
V_4 = F_3 ( V_2 , V_22 -> V_3 , V_22 -> V_16 ) ;
if ( V_4 ) {
F_6 ( & V_2 -> V_25 , L_1 ) ;
return V_4 ;
}
V_22 ++ ;
}
return 0 ;
}
static struct V_26 * F_7 ( int V_27 )
{
int V_28 ;
if ( V_27 < V_29 )
return NULL ;
for ( V_28 = 0 ; V_28 < F_8 ( V_30 ) ; V_28 ++ )
if ( V_30 [ V_28 ] . V_31 . V_27 == V_27 )
return & V_30 [ V_28 ] ;
return NULL ;
}
static enum V_32 F_9 ( struct V_33 * V_34 ,
unsigned int V_35 ,
unsigned int V_36 )
{
enum V_32 V_37 ;
unsigned long V_38 = V_35 * V_36 ;
struct V_39 * V_40 = V_34 -> V_41 ;
for ( V_37 = V_42 ; V_37 < V_43 ; V_37 ++ ) {
if ( V_44 [ V_37 + 1 ] . V_36
* V_44 [ V_37 + 1 ] . V_35 > V_38 ) {
F_10 ( & V_40 -> V_1 -> V_25 , L_2 , V_37 ) ;
return V_37 ;
}
}
F_10 ( & V_40 -> V_1 -> V_25 , L_3 ) ;
return V_43 ;
}
static int F_11 ( struct V_33 * V_34 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
struct V_45 * V_46 = & V_40 -> V_46 ;
enum V_32 V_37 = F_9 ( V_34 , V_46 -> V_35 , V_46 -> V_36 ) ;
struct V_47 * V_48 = & V_40 -> V_49 ;
enum V_50 V_51 ;
int V_4 ;
T_2 V_52 ;
T_1 V_16 ;
V_4 = F_5 (
V_40 -> V_1 , V_40 -> V_53 -> V_54 () ) ;
if ( V_4 )
return V_4 ;
V_16 = V_55 [ V_37 ] -> V_16 ;
F_10 ( & V_40 -> V_1 -> V_25 ,
L_4 , V_37 ) ;
V_4 = F_12 ( V_40 -> V_1 ,
V_55 [ V_37 ] -> V_3 , V_16 ) ;
if ( V_4 )
return V_4 ;
switch ( V_46 -> V_56 ) {
default:
case V_57 :
V_51 = V_58 ;
break;
case V_59 :
V_51 = V_60 ;
break;
}
F_10 ( & V_40 -> V_1 -> V_25 ,
L_5 , V_51 ) ;
V_16 = V_61 [ V_51 ] -> V_16 ;
V_4 = F_12 ( V_40 -> V_1 ,
V_61 [ V_51 ] -> V_3 , V_16 ) ;
if ( V_4 )
return V_4 ;
V_52 = V_48 -> V_62 / V_48 -> V_63 ;
if ( V_52 <= V_64 ) {
V_16 = F_1 ( V_40 -> V_1 , 0x02 ) ;
V_16 |= 0x80 ;
F_3 ( V_40 -> V_1 , 0x02 , V_16 ) ;
}
return 0 ;
}
static int F_13 ( struct V_33 * V_34 ,
struct V_65 * V_31 )
{
struct V_26 * V_66 ;
V_66 = F_7 ( V_31 -> V_27 ) ;
if ( V_66 == NULL )
return - V_67 ;
* V_31 = V_66 -> V_31 ;
return 0 ;
}
static int F_14 ( struct V_33 * V_34 ,
struct V_68 * V_69 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
struct V_1 * V_2 = V_40 -> V_1 ;
int V_16 , V_70 ;
struct V_26 * V_71 ;
if ( V_69 -> V_27 == V_72 ) {
int V_73 , V_74 ;
V_74 = F_1 ( V_2 ,
F_15 ( V_75 ) ) ;
if ( V_74 < 0 )
return V_74 ;
V_73 = F_1 ( V_2 ,
F_15 ( V_76 ) ) ;
if ( V_73 < 0 )
return V_73 ;
V_69 -> V_77 = ( ( V_74 & 0x1f ) << 8 ) | ( V_73 ) ;
return 0 ;
}
V_71 = F_7 ( V_69 -> V_27 ) ;
if ( V_71 == NULL )
return - V_67 ;
V_70 = F_1 ( V_2 , F_15 ( V_71 -> V_3 ) ) ;
if ( V_70 < 0 )
return V_70 ;
V_16 = V_70 & F_16 ( V_71 -> V_3 ) ;
V_16 >>= V_71 -> V_78 ;
if ( V_16 < 0 )
return V_16 ;
if ( V_69 -> V_27 == V_79 || V_69 -> V_27 == V_80 )
V_16 ^= V_40 -> V_53 -> V_81 () ;
V_69 -> V_77 = V_16 ;
return 0 ;
}
static int F_17 ( struct V_33 * V_34 ,
struct V_68 * V_69 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
struct V_1 * V_2 = V_40 -> V_1 ;
struct V_26 * V_71 ;
int V_16 = V_69 -> V_77 ;
if ( V_69 -> V_27 == V_72 ) {
int V_73 , V_74 ;
V_73 = V_16 & F_16 ( V_76 ) ;
V_74 = ( V_16 >> 8 ) & F_16 ( V_75 ) ;
if ( F_12 ( V_2 ,
V_75 , V_74 ) )
return - V_82 ;
if ( F_12 ( V_2 ,
V_76 , V_73 ) )
return - V_82 ;
return 0 ;
}
V_71 = F_7 ( V_69 -> V_27 ) ;
if ( V_71 == NULL )
return - V_67 ;
if ( V_69 -> V_27 == V_79 || V_69 -> V_27 == V_80 )
V_16 ^= V_40 -> V_53 -> V_81 () ;
V_16 = V_16 << V_71 -> V_78 ;
if ( F_12 ( V_2 , V_71 -> V_3 , V_16 ) )
return - V_82 ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 ,
struct V_83 * V_84 )
{
int V_85 = V_84 -> V_85 ;
switch ( V_84 -> type ) {
case V_86 :
if ( V_85 >= V_87 )
return - V_67 ;
break;
default:
return - V_67 ;
}
V_84 -> V_12 = V_88 [ V_85 ] . V_12 ;
F_19 ( V_84 -> V_89 , V_88 [ V_85 ] . V_89 ,
sizeof( V_84 -> V_89 ) ) ;
V_84 -> V_56 = V_88 [ V_85 ] . V_56 ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 ,
struct V_90 * V_91 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
enum V_32 V_37 ;
int V_92 ;
struct V_45 * V_46 = & V_91 -> V_84 . V_46 ;
V_37 = F_9 ( V_34 , V_46 -> V_35 , V_46 -> V_36 ) ;
F_10 ( & V_40 -> V_1 -> V_25 , L_6 ,
V_37 , ( unsigned long ) V_87 ) ;
V_46 -> V_35 = V_44 [ V_37 ] . V_35 ;
V_46 -> V_36 = V_44 [ V_37 ] . V_36 ;
for ( V_92 = 0 ; V_92 < V_87 ; V_92 ++ )
if ( V_46 -> V_56 == V_88 [ V_92 ] . V_56 )
break;
if ( V_92 == V_87 )
V_92 = 0 ;
V_46 -> V_56 = V_88 [ V_92 ] . V_56 ;
V_46 -> V_93 = V_94 ;
V_46 -> V_95 = V_46 -> V_35 * V_96 ;
V_46 -> V_97 = V_46 -> V_95 * V_46 -> V_36 ;
V_46 -> V_41 = 0 ;
F_10 ( & V_40 -> V_1 -> V_25 , L_7 ,
V_46 -> V_56 ) ;
switch ( V_46 -> V_56 ) {
case V_59 :
default:
V_46 -> V_98 = V_99 ;
break;
case V_57 :
V_46 -> V_98 = V_100 ;
break;
}
return 0 ;
}
static int F_21 ( struct V_33 * V_34 ,
struct V_90 * V_91 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
struct V_45 * V_46 = & V_91 -> V_84 . V_46 ;
int V_101 ;
V_101 = F_20 ( V_34 , V_91 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_11 ( V_34 ) ;
V_40 -> V_46 = * V_46 ;
return V_101 ;
}
static int F_22 ( struct V_33 * V_34 ,
struct V_90 * V_91 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
V_91 -> V_84 . V_46 = V_40 -> V_46 ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 ,
struct V_102 * V_103 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
struct V_104 * V_105 = & V_103 -> V_106 . V_107 ;
if ( V_103 -> type != V_86 )
return - V_67 ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
V_103 -> type = V_86 ;
V_105 -> V_108 = V_109 ;
V_105 -> V_49 = V_40 -> V_49 ;
return 0 ;
}
static int F_24 ( struct V_33 * V_34 ,
struct V_102 * V_103 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
struct V_47 * V_49 = & V_103 -> V_106 . V_107 . V_49 ;
T_2 V_52 ;
int V_101 ;
if ( V_103 -> type != V_86 )
return - V_67 ;
if ( ( V_49 -> V_63 == 0 )
|| ( V_49 -> V_62 == 0 ) ) {
V_49 -> V_62 = V_110 ;
V_49 -> V_63 = 1 ;
}
V_52 = V_49 -> V_62 / V_49 -> V_63 ;
if ( V_52 > V_111 ) {
V_49 -> V_62 = V_111 ;
V_49 -> V_63 = 1 ;
} else if ( V_52 < V_112 ) {
V_49 -> V_62 = V_112 ;
V_49 -> V_63 = 1 ;
}
V_40 -> V_49 = * V_49 ;
V_101 = F_11 ( V_34 ) ;
return V_101 ;
}
static int F_25 ( struct V_33 * V_34 , int V_113 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
return V_40 -> V_53 -> V_114 ( V_113 ) ;
}
static int F_26 ( struct V_33 * V_34 , struct V_115 * V_116 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
struct V_47 * V_49 = & V_40 -> V_49 ;
T_2 V_117 ;
T_2 V_52 ;
int V_101 ;
V_101 = V_40 -> V_53 -> V_118 ( V_116 ) ;
if ( V_101 )
return V_101 ;
V_52 = V_49 -> V_62 / V_49 -> V_63 ;
V_117 = ( V_52 <= V_64 ) ?
( 2457 * V_52 ) / V_119 :
( 2457 * V_52 ) / V_111 ;
V_117 *= 10000 ;
V_117 = F_27 ( V_117 , ( T_2 ) V_120 ) ;
V_117 = F_28 ( V_117 , ( T_2 ) V_121 ) ;
V_116 -> V_122 . V_123 . V_124 = V_117 ;
return 0 ;
}
static int F_29 ( struct V_33 * V_34 , void * V_14 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
return V_40 -> V_53 -> V_125 ( V_34 , V_14 , & V_40 -> V_46 ) ;
}
static int F_30 ( struct V_33 * V_34 )
{
return - V_126 ;
}
static int F_31 ( struct V_33 * V_34 )
{
return F_11 ( V_34 ) ;
}
static int F_32 ( struct V_33 * V_34 )
{
return 0 ;
}
static int F_33 ( struct V_33 * V_34 )
{
struct V_39 * V_40 = V_34 -> V_41 ;
int V_70 ;
V_70 = F_1 ( V_40 -> V_1 , 0x01 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( V_70 == 0 ) {
F_6 ( & V_40 -> V_1 -> V_25 , L_8 ) ;
return - V_82 ;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
const struct V_127 * V_128 )
{
struct V_39 * V_40 = & V_129 ;
if ( F_35 ( V_2 ) )
return - V_126 ;
V_40 -> V_53 = V_2 -> V_25 . V_53 ;
if ( V_40 -> V_53 == NULL
|| ! V_40 -> V_53 -> V_130 () )
return - V_10 ;
V_40 -> V_33 = & V_131 ;
V_40 -> V_1 = V_2 ;
F_36 ( V_2 , V_40 ) ;
V_40 -> V_46 . V_35 = V_44 [ V_132 ] . V_35 ;
V_40 -> V_46 . V_36 = V_44 [ V_132 ] . V_36 ;
V_40 -> V_46 . V_56 = V_57 ;
return F_37 ( V_40 -> V_33 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = F_35 ( V_2 ) ;
if ( ! V_2 -> V_9 )
return - V_10 ;
F_39 ( V_40 -> V_33 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
int V_101 ;
V_101 = F_41 ( & V_133 ) ;
if ( V_101 )
F_42 ( L_9 V_134 L_10 ,
V_135 ) ;
return V_101 ;
}
static void T_4 F_43 ( void )
{
F_44 ( & V_133 ) ;
}
