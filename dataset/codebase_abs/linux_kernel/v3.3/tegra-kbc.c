static void F_1 ( struct V_1 * V_2 ,
unsigned short V_3 [] ,
unsigned int V_4 ,
unsigned short V_5 [] ,
unsigned int V_6 )
{
unsigned int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_4 ; V_7 ++ ) {
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
if ( V_3 [ V_7 ] == V_5 [ V_8 ] )
break;
if ( V_8 == V_6 )
F_2 ( V_2 , V_3 [ V_7 ] , 0 ) ;
}
}
static void F_3 ( struct V_1 * V_2 ,
unsigned char V_9 [] ,
unsigned short V_10 [] ,
unsigned int V_11 )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_11 ; V_7 ++ ) {
F_4 ( V_2 , V_12 , V_13 , V_9 [ V_7 ] ) ;
F_2 ( V_2 , V_10 [ V_7 ] , 1 ) ;
}
}
static void F_5 ( struct V_14 * V_15 )
{
unsigned char V_9 [ V_16 ] ;
unsigned short V_10 [ V_16 ] ;
T_1 V_17 = 0 ;
unsigned int V_7 ;
unsigned int V_18 = 0 ;
bool V_19 = false ;
bool V_20 = false ;
bool V_21 = false ;
for ( V_7 = 0 ; V_7 < V_16 ; V_7 ++ ) {
if ( ( V_7 % 4 ) == 0 )
V_17 = F_6 ( V_15 -> V_22 + V_23 + V_7 ) ;
if ( V_17 & 0x80 ) {
unsigned int V_24 = V_17 & 0x07 ;
unsigned int V_25 = ( V_17 >> 3 ) & 0x0f ;
unsigned char V_26 =
F_7 ( V_25 , V_24 , V_27 ) ;
V_9 [ V_18 ] = V_26 ;
V_10 [ V_18 ] = V_15 -> V_28 [ V_26 ] ;
if ( ( V_10 [ V_18 ] == V_29 ) && V_15 -> V_30 )
V_19 = true ;
else
V_18 ++ ;
}
V_17 >>= 8 ;
}
if ( V_15 -> V_31 && V_18 >= 3 ) {
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
unsigned int V_8 ;
T_2 V_32 = V_9 [ V_7 ] & 0x07 ;
T_2 V_33 = V_9 [ V_7 ] >> V_27 ;
for ( V_8 = V_7 + 1 ; V_8 < V_18 ; V_8 ++ ) {
T_2 V_24 = V_9 [ V_8 ] & 0x07 ;
T_2 V_25 = V_9 [ V_8 ] >> V_27 ;
if ( V_24 == V_32 )
V_21 = true ;
if ( V_25 == V_33 )
V_20 = true ;
}
}
}
if ( V_19 ) {
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ ) {
V_9 [ V_7 ] += V_34 ;
V_10 [ V_7 ] = V_15 -> V_28 [ V_9 [ V_7 ] ] ;
}
}
if ( V_21 && V_20 )
return;
F_1 ( V_15 -> V_35 ,
V_15 -> V_36 , V_15 -> V_11 ,
V_10 , V_18 ) ;
F_3 ( V_15 -> V_35 , V_9 , V_10 , V_18 ) ;
F_8 ( V_15 -> V_35 ) ;
memcpy ( V_15 -> V_36 , V_10 , sizeof( V_15 -> V_36 ) ) ;
V_15 -> V_11 = V_18 ;
}
static void F_9 ( struct V_14 * V_15 , bool V_37 )
{
T_1 V_17 ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
if ( V_37 )
V_17 |= V_39 ;
else
V_17 &= ~ V_39 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
}
static void F_11 ( unsigned long V_40 )
{
struct V_14 * V_15 = (struct V_14 * ) V_40 ;
unsigned long V_41 ;
T_1 V_17 ;
unsigned int V_7 ;
F_12 ( & V_15 -> V_42 , V_41 ) ;
V_17 = ( F_6 ( V_15 -> V_22 + V_43 ) >> 4 ) & 0xf ;
if ( V_17 ) {
unsigned long V_44 ;
F_5 ( V_15 ) ;
V_44 = ( V_17 == 1 ) ? V_15 -> V_45 : 1 ;
F_13 ( & V_15 -> V_46 , V_47 + F_14 ( V_44 ) ) ;
} else {
for ( V_7 = 0 ; V_7 < V_15 -> V_11 ; V_7 ++ )
F_2 ( V_15 -> V_35 , V_15 -> V_36 [ V_7 ] , 0 ) ;
F_8 ( V_15 -> V_35 ) ;
V_15 -> V_11 = 0 ;
F_9 ( V_15 , true ) ;
}
F_15 ( & V_15 -> V_42 , V_41 ) ;
}
static T_3 F_16 ( int V_48 , void * args )
{
struct V_14 * V_15 = args ;
unsigned long V_41 ;
T_1 V_17 ;
F_12 ( & V_15 -> V_42 , V_41 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_43 ) ;
F_10 ( V_17 , V_15 -> V_22 + V_43 ) ;
if ( V_17 & V_49 ) {
F_9 ( V_15 , false ) ;
F_13 ( & V_15 -> V_46 , V_47 + V_15 -> V_50 ) ;
} else if ( V_17 & V_51 ) {
V_15 -> V_52 = true ;
}
F_15 ( & V_15 -> V_42 , V_41 ) ;
return V_53 ;
}
static void F_17 ( struct V_14 * V_15 , bool V_54 )
{
const struct V_55 * V_56 = V_15 -> V_56 ;
int V_7 ;
unsigned int V_57 ;
V_57 = ( V_54 && ! V_56 -> V_58 ) ? ~ 0 : 0 ;
for ( V_7 = 0 ; V_7 < V_59 ; V_7 ++ )
F_10 ( V_57 , V_15 -> V_22 + V_60 + V_7 * 4 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
const struct V_55 * V_56 = V_15 -> V_56 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_61 ; V_7 ++ ) {
T_1 V_62 = 5 * ( V_7 % 6 ) ;
T_1 V_63 = 4 * ( V_7 % 8 ) ;
T_1 V_64 = 0x1f << V_62 ;
T_1 V_65 = 0x0f << V_63 ;
T_1 V_66 = ( V_7 / 6 ) * 4 + V_67 ;
T_1 V_68 = ( V_7 / 8 ) * 4 + V_69 ;
T_1 V_70 = F_6 ( V_15 -> V_22 + V_66 ) ;
T_1 V_71 = F_6 ( V_15 -> V_22 + V_68 ) ;
V_70 &= ~ V_64 ;
V_71 &= ~ V_65 ;
if ( V_56 -> V_72 [ V_7 ] . V_73 )
V_70 |= ( ( V_56 -> V_72 [ V_7 ] . V_74 << 1 ) | 1 ) << V_62 ;
else
V_71 |= ( ( V_56 -> V_72 [ V_7 ] . V_74 << 1 ) | 1 ) << V_63 ;
F_10 ( V_70 , V_15 -> V_22 + V_66 ) ;
F_10 ( V_71 , V_15 -> V_22 + V_68 ) ;
}
}
static int F_19 ( struct V_14 * V_15 )
{
const struct V_55 * V_56 = V_15 -> V_56 ;
unsigned int V_75 ;
T_1 V_17 = 0 ;
F_20 ( V_15 -> V_76 ) ;
F_21 ( V_15 -> V_76 ) ;
F_22 ( 100 ) ;
F_23 ( V_15 -> V_76 ) ;
F_22 ( 100 ) ;
F_18 ( V_15 ) ;
F_17 ( V_15 , false ) ;
F_10 ( V_56 -> V_77 , V_15 -> V_22 + V_78 ) ;
V_75 = F_24 ( V_56 -> V_75 , V_79 ) ;
V_17 = F_25 ( V_75 ) ;
V_17 |= F_26 ( 1 ) ;
V_17 |= V_39 ;
V_17 |= V_80 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_81 ) ;
V_15 -> V_50 = F_27 ( ( V_17 & 0xfffff ) * 32 ) ;
V_15 -> V_11 = 0 ;
while ( 1 ) {
V_17 = F_6 ( V_15 -> V_22 + V_43 ) ;
V_17 >>= 4 ;
if ( ! V_17 )
break;
V_17 = F_6 ( V_15 -> V_22 + V_23 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_82 ) ;
}
F_10 ( 0x7 , V_15 -> V_22 + V_43 ) ;
F_28 ( V_15 -> V_48 ) ;
return 0 ;
}
static void F_29 ( struct V_14 * V_15 )
{
unsigned long V_41 ;
T_1 V_17 ;
F_12 ( & V_15 -> V_42 , V_41 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
V_17 &= ~ 1 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
F_15 ( & V_15 -> V_42 , V_41 ) ;
F_30 ( V_15 -> V_48 ) ;
F_31 ( & V_15 -> V_46 ) ;
F_32 ( V_15 -> V_76 ) ;
}
static int F_33 ( struct V_1 * V_83 )
{
struct V_14 * V_15 = F_34 ( V_83 ) ;
return F_19 ( V_15 ) ;
}
static void F_35 ( struct V_1 * V_83 )
{
struct V_14 * V_15 = F_34 ( V_83 ) ;
return F_29 ( V_15 ) ;
}
static bool T_4
F_36 ( const struct V_55 * V_56 ,
struct V_84 * V_83 , unsigned int * V_85 )
{
int V_7 ;
* V_85 = 0 ;
for ( V_7 = 0 ; V_7 < V_61 ; V_7 ++ ) {
const struct V_86 * V_72 = & V_56 -> V_72 [ V_7 ] ;
if ( V_72 -> V_73 ) {
if ( V_72 -> V_74 >= V_59 ) {
F_37 ( V_83 ,
L_1 ,
V_7 , V_72 -> V_74 ) ;
return false ;
}
( * V_85 ) ++ ;
} else {
if ( V_72 -> V_74 >= V_87 ) {
F_37 ( V_83 ,
L_2 ,
V_7 , V_72 -> V_74 ) ;
return false ;
}
}
}
return true ;
}
static struct V_55 * T_4
F_38 ( struct V_88 * V_89 )
{
struct V_55 * V_56 ;
struct V_90 * V_91 = V_89 -> V_83 . V_92 ;
if ( ! V_91 )
return NULL ;
V_56 = F_39 ( sizeof( * V_56 ) , V_93 ) ;
if ( ! V_56 )
return NULL ;
if ( ! F_40 ( V_91 , L_3 , & V_94 ) )
V_56 -> V_75 = V_94 ;
if ( ! F_40 ( V_91 , L_4 , & V_94 ) )
V_56 -> V_77 = V_94 ;
if ( F_41 ( V_91 , L_5 , NULL ) )
V_56 -> V_31 = true ;
if ( F_41 ( V_91 , L_6 , NULL ) )
V_56 -> V_58 = true ;
for ( V_7 = 0 ; V_7 < V_59 ; V_7 ++ ) {
V_56 -> V_72 [ V_7 ] . V_74 = V_7 ;
V_56 -> V_72 [ V_7 ] . V_73 = true ;
}
for ( V_7 = 0 ; V_7 < V_87 ; V_7 ++ ) {
V_56 -> V_72 [ V_59 + V_7 ] . V_74 = V_7 ;
V_56 -> V_72 [ V_59 + V_7 ] . V_73 = false ;
}
return V_56 ;
}
static inline struct V_55 * F_38 (
struct V_88 * V_89 )
{
return NULL ;
}
static int T_4 F_42 ( struct V_88 * V_89 )
{
const struct V_55 * V_56 = V_89 -> V_83 . V_95 ;
const struct V_96 * V_97 ;
struct V_14 * V_15 ;
struct V_1 * V_1 ;
struct V_98 * V_99 ;
int V_48 ;
int V_100 ;
int V_85 = 0 ;
unsigned int V_75 ;
unsigned int V_101 ;
if ( ! V_56 )
V_56 = F_38 ( V_89 ) ;
if ( ! V_56 )
return - V_102 ;
if ( ! F_36 ( V_56 , & V_89 -> V_83 , & V_85 ) ) {
V_100 = - V_102 ;
goto V_103;
}
V_99 = F_43 ( V_89 , V_104 , 0 ) ;
if ( ! V_99 ) {
F_37 ( & V_89 -> V_83 , L_7 ) ;
V_100 = - V_105 ;
goto V_103;
}
V_48 = F_44 ( V_89 , 0 ) ;
if ( V_48 < 0 ) {
F_37 ( & V_89 -> V_83 , L_8 ) ;
V_100 = - V_105 ;
goto V_103;
}
V_15 = F_39 ( sizeof( * V_15 ) , V_93 ) ;
V_1 = F_45 () ;
if ( ! V_15 || ! V_1 ) {
V_100 = - V_106 ;
goto V_107;
}
V_15 -> V_56 = V_56 ;
V_15 -> V_35 = V_1 ;
V_15 -> V_48 = V_48 ;
F_46 ( & V_15 -> V_42 ) ;
F_47 ( & V_15 -> V_46 , F_11 , ( unsigned long ) V_15 ) ;
V_99 = F_48 ( V_99 -> V_108 , F_49 ( V_99 ) , V_89 -> V_109 ) ;
if ( ! V_99 ) {
F_37 ( & V_89 -> V_83 , L_9 ) ;
V_100 = - V_110 ;
goto V_107;
}
V_15 -> V_22 = F_50 ( V_99 -> V_108 , F_49 ( V_99 ) ) ;
if ( ! V_15 -> V_22 ) {
F_37 ( & V_89 -> V_83 , L_10 ) ;
V_100 = - V_105 ;
goto V_111;
}
V_15 -> V_76 = F_51 ( & V_89 -> V_83 , NULL ) ;
if ( F_52 ( V_15 -> V_76 ) ) {
F_37 ( & V_89 -> V_83 , L_11 ) ;
V_100 = F_53 ( V_15 -> V_76 ) ;
goto V_112;
}
V_75 = F_24 ( V_56 -> V_75 , V_79 ) ;
V_101 = ( V_113 + V_75 ) * V_85 ;
V_15 -> V_45 = V_114 + V_101 + V_56 -> V_77 ;
V_15 -> V_45 = F_54 ( V_15 -> V_45 , V_115 ) ;
V_1 -> V_109 = V_89 -> V_109 ;
V_1 -> V_116 . V_117 = V_118 ;
V_1 -> V_83 . V_119 = & V_89 -> V_83 ;
V_1 -> V_120 = F_33 ;
V_1 -> V_121 = F_35 ;
F_55 ( V_1 , V_15 ) ;
V_1 -> V_122 [ 0 ] = F_56 ( V_123 ) | F_56 ( V_124 ) ;
F_57 ( V_1 , V_12 , V_13 ) ;
V_1 -> V_28 = V_15 -> V_28 ;
V_1 -> V_125 = sizeof( V_15 -> V_28 [ 0 ] ) ;
V_1 -> V_126 = V_34 ;
if ( V_56 -> V_30 )
V_1 -> V_126 *= 2 ;
V_15 -> V_30 = V_56 -> V_30 ;
V_15 -> V_31 = V_56 -> V_31 ;
V_97 = V_56 -> V_97 ? : & V_127 ;
F_58 ( V_97 , V_27 ,
V_1 -> V_28 , V_1 -> V_128 ) ;
V_15 -> V_129 = V_56 -> V_129 ;
V_100 = F_59 ( V_15 -> V_48 , F_16 ,
V_130 | V_131 , V_89 -> V_109 , V_15 ) ;
if ( V_100 ) {
F_37 ( & V_89 -> V_83 , L_12 ) ;
goto V_132;
}
F_30 ( V_15 -> V_48 ) ;
V_100 = F_60 ( V_15 -> V_35 ) ;
if ( V_100 ) {
F_37 ( & V_89 -> V_83 , L_13 ) ;
goto V_133;
}
F_61 ( V_89 , V_15 ) ;
F_62 ( & V_89 -> V_83 , V_56 -> V_58 ) ;
return 0 ;
V_133:
F_63 ( V_15 -> V_48 , V_89 ) ;
V_132:
F_64 ( V_15 -> V_76 ) ;
V_112:
F_65 ( V_15 -> V_22 ) ;
V_111:
F_66 ( V_99 -> V_108 , F_49 ( V_99 ) ) ;
V_107:
F_67 ( V_1 ) ;
F_68 ( V_15 ) ;
V_103:
if ( ! V_89 -> V_83 . V_95 )
F_68 ( V_56 ) ;
return V_100 ;
}
static int T_5 F_69 ( struct V_88 * V_89 )
{
struct V_14 * V_15 = F_70 ( V_89 ) ;
struct V_98 * V_99 ;
F_61 ( V_89 , NULL ) ;
F_63 ( V_15 -> V_48 , V_89 ) ;
F_64 ( V_15 -> V_76 ) ;
F_71 ( V_15 -> V_35 ) ;
F_65 ( V_15 -> V_22 ) ;
V_99 = F_43 ( V_89 , V_104 , 0 ) ;
F_66 ( V_99 -> V_108 , F_49 ( V_99 ) ) ;
if ( ! V_89 -> V_83 . V_95 )
F_68 ( V_15 -> V_56 ) ;
F_68 ( V_15 ) ;
return 0 ;
}
static int F_72 ( struct V_84 * V_83 )
{
struct V_88 * V_89 = F_73 ( V_83 ) ;
struct V_14 * V_15 = F_70 ( V_89 ) ;
F_74 ( & V_15 -> V_35 -> V_134 ) ;
if ( F_75 ( & V_89 -> V_83 ) ) {
F_30 ( V_15 -> V_48 ) ;
F_31 ( & V_15 -> V_46 ) ;
F_9 ( V_15 , false ) ;
F_10 ( 0x7 , V_15 -> V_22 + V_43 ) ;
V_15 -> V_135 = F_6 ( V_15 -> V_22 + V_136 ) ;
F_10 ( 0 , V_15 -> V_22 + V_136 ) ;
F_17 ( V_15 , true ) ;
F_76 ( 30 ) ;
V_15 -> V_52 = false ;
F_28 ( V_15 -> V_48 ) ;
F_77 ( V_15 -> V_48 ) ;
} else {
if ( V_15 -> V_35 -> V_137 )
F_29 ( V_15 ) ;
}
F_78 ( & V_15 -> V_35 -> V_134 ) ;
return 0 ;
}
static int F_79 ( struct V_84 * V_83 )
{
struct V_88 * V_89 = F_73 ( V_83 ) ;
struct V_14 * V_15 = F_70 ( V_89 ) ;
int V_100 = 0 ;
F_74 ( & V_15 -> V_35 -> V_134 ) ;
if ( F_75 ( & V_89 -> V_83 ) ) {
F_80 ( V_15 -> V_48 ) ;
F_17 ( V_15 , false ) ;
F_10 ( V_15 -> V_135 , V_15 -> V_22 + V_136 ) ;
F_9 ( V_15 , true ) ;
if ( V_15 -> V_52 && V_15 -> V_129 ) {
F_2 ( V_15 -> V_35 , V_15 -> V_129 , 1 ) ;
F_8 ( V_15 -> V_35 ) ;
F_2 ( V_15 -> V_35 , V_15 -> V_129 , 0 ) ;
F_8 ( V_15 -> V_35 ) ;
}
} else {
if ( V_15 -> V_35 -> V_137 )
V_100 = F_19 ( V_15 ) ;
}
F_78 ( & V_15 -> V_35 -> V_134 ) ;
return V_100 ;
}
