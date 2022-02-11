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
V_9 [ V_7 ] += V_15 -> V_34 ;
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
int V_7 ;
unsigned int V_55 ;
V_55 = ( V_54 && ! V_15 -> V_56 ) ? ~ 0 : 0 ;
for ( V_7 = 0 ; V_7 < V_15 -> V_57 -> V_58 ; V_7 ++ )
F_10 ( V_55 , V_15 -> V_22 + V_59 + V_7 * 4 ) ;
}
static void F_18 ( struct V_14 * V_15 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_60 ; V_7 ++ ) {
T_1 V_61 = 5 * ( V_7 % 6 ) ;
T_1 V_62 = 4 * ( V_7 % 8 ) ;
T_1 V_63 = 0x1f << V_61 ;
T_1 V_64 = 0x0f << V_62 ;
T_1 V_65 = ( V_7 / 6 ) * 4 + V_66 ;
T_1 V_67 = ( V_7 / 8 ) * 4 + V_68 ;
T_1 V_69 = F_6 ( V_15 -> V_22 + V_65 ) ;
T_1 V_70 = F_6 ( V_15 -> V_22 + V_67 ) ;
V_69 &= ~ V_63 ;
V_70 &= ~ V_64 ;
switch ( V_15 -> V_71 [ V_7 ] . type ) {
case V_72 :
V_69 |= ( ( V_15 -> V_71 [ V_7 ] . V_73 << 1 ) | 1 ) << V_61 ;
break;
case V_74 :
V_70 |= ( ( V_15 -> V_71 [ V_7 ] . V_73 << 1 ) | 1 ) << V_62 ;
break;
case V_75 :
break;
}
F_10 ( V_69 , V_15 -> V_22 + V_65 ) ;
F_10 ( V_70 , V_15 -> V_22 + V_67 ) ;
}
}
static int F_19 ( struct V_14 * V_15 )
{
unsigned int V_76 ;
T_1 V_17 = 0 ;
F_20 ( V_15 -> V_77 ) ;
F_21 ( V_15 -> V_78 ) ;
F_22 ( 100 ) ;
F_21 ( V_15 -> V_78 ) ;
F_22 ( 100 ) ;
F_18 ( V_15 ) ;
F_17 ( V_15 , false ) ;
F_10 ( V_15 -> V_79 , V_15 -> V_22 + V_80 ) ;
V_76 = F_23 ( V_15 -> V_76 , V_81 ) ;
V_17 = F_24 ( V_76 ) ;
V_17 |= F_25 ( 1 ) ;
V_17 |= V_39 ;
V_17 |= V_82 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_83 ) ;
V_15 -> V_50 = F_26 ( ( V_17 & 0xfffff ) * 32 ) ;
V_15 -> V_11 = 0 ;
while ( 1 ) {
V_17 = F_6 ( V_15 -> V_22 + V_43 ) ;
V_17 >>= 4 ;
if ( ! V_17 )
break;
V_17 = F_6 ( V_15 -> V_22 + V_23 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_84 ) ;
}
F_10 ( 0x7 , V_15 -> V_22 + V_43 ) ;
F_27 ( V_15 -> V_48 ) ;
return 0 ;
}
static void F_28 ( struct V_14 * V_15 )
{
unsigned long V_41 ;
T_1 V_17 ;
F_12 ( & V_15 -> V_42 , V_41 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
V_17 &= ~ 1 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
F_15 ( & V_15 -> V_42 , V_41 ) ;
F_29 ( V_15 -> V_48 ) ;
F_30 ( & V_15 -> V_46 ) ;
F_31 ( V_15 -> V_77 ) ;
}
static int F_32 ( struct V_1 * V_85 )
{
struct V_14 * V_15 = F_33 ( V_85 ) ;
return F_19 ( V_15 ) ;
}
static void F_34 ( struct V_1 * V_85 )
{
struct V_14 * V_15 = F_33 ( V_85 ) ;
return F_28 ( V_15 ) ;
}
static bool F_35 ( const struct V_14 * V_15 ,
unsigned int * V_86 )
{
int V_7 ;
* V_86 = 0 ;
for ( V_7 = 0 ; V_7 < V_60 ; V_7 ++ ) {
const struct V_87 * V_71 = & V_15 -> V_71 [ V_7 ] ;
switch ( V_71 -> type ) {
case V_72 :
if ( V_71 -> V_73 >= V_15 -> V_57 -> V_58 ) {
F_36 ( V_15 -> V_85 ,
L_1 ,
V_7 , V_71 -> V_73 ) ;
return false ;
}
( * V_86 ) ++ ;
break;
case V_74 :
if ( V_71 -> V_73 >= V_15 -> V_57 -> V_88 ) {
F_36 ( V_15 -> V_85 ,
L_2 ,
V_7 , V_71 -> V_73 ) ;
return false ;
}
break;
case V_75 :
break;
default:
F_36 ( V_15 -> V_85 ,
L_3 ,
V_71 -> type , V_71 -> V_73 ) ;
return false ;
}
}
return true ;
}
static int F_37 ( struct V_14 * V_15 )
{
struct V_89 * V_90 = V_15 -> V_85 -> V_91 ;
T_1 V_92 ;
int V_7 ;
T_1 V_86 = 0 ;
T_1 V_93 = 0 ;
T_1 V_94 [ V_60 ] ;
T_1 V_95 [ V_60 ] ;
int V_96 ;
int V_97 ;
if ( ! F_38 ( V_90 , L_4 , & V_92 ) )
V_15 -> V_76 = V_92 ;
if ( ! F_38 ( V_90 , L_5 , & V_92 ) )
V_15 -> V_79 = V_92 ;
if ( F_39 ( V_90 , L_6 , NULL ) )
V_15 -> V_31 = true ;
if ( F_40 ( V_90 , L_7 ) ||
F_40 ( V_90 , L_8 ) )
V_15 -> V_56 = true ;
if ( ! F_41 ( V_90 , L_9 , & V_96 ) ) {
F_36 ( V_15 -> V_85 , L_10 ) ;
return - V_98 ;
}
V_86 = V_96 / sizeof( T_1 ) ;
if ( ! F_41 ( V_90 , L_11 , & V_96 ) ) {
F_36 ( V_15 -> V_85 , L_12 ) ;
return - V_98 ;
}
V_93 = V_96 / sizeof( T_1 ) ;
if ( V_86 > V_15 -> V_57 -> V_58 ) {
F_36 ( V_15 -> V_85 ,
L_13 ) ;
return - V_99 ;
}
if ( V_93 > V_15 -> V_57 -> V_88 ) {
F_36 ( V_15 -> V_85 ,
L_14 ) ;
return - V_99 ;
}
if ( ! F_41 ( V_90 , L_15 , & V_96 ) ) {
F_36 ( V_15 -> V_85 , L_16 ) ;
return - V_98 ;
}
if ( ! V_86 || ! V_93 || ( ( V_86 + V_93 ) > V_60 ) ) {
F_36 ( V_15 -> V_85 ,
L_17 ) ;
return - V_99 ;
}
for ( V_7 = 0 ; V_7 < V_15 -> V_100 ; V_7 ++ )
V_15 -> V_71 [ V_7 ] . type = V_75 ;
V_97 = F_42 ( V_90 , L_9 ,
V_95 , V_86 ) ;
if ( V_97 < 0 ) {
F_36 ( V_15 -> V_85 , L_18 ) ;
return - V_99 ;
}
V_97 = F_42 ( V_90 , L_11 ,
V_94 , V_93 ) ;
if ( V_97 < 0 ) {
F_36 ( V_15 -> V_85 , L_19 ) ;
return - V_99 ;
}
for ( V_7 = 0 ; V_7 < V_86 ; V_7 ++ ) {
V_15 -> V_71 [ V_95 [ V_7 ] ] . type = V_72 ;
V_15 -> V_71 [ V_95 [ V_7 ] ] . V_73 = V_7 ;
}
for ( V_7 = 0 ; V_7 < V_93 ; V_7 ++ ) {
V_15 -> V_71 [ V_94 [ V_7 ] ] . type = V_74 ;
V_15 -> V_71 [ V_94 [ V_7 ] ] . V_73 = V_7 ;
}
return 0 ;
}
static int F_43 ( struct V_101 * V_102 )
{
struct V_14 * V_15 ;
struct V_103 * V_104 ;
int V_105 ;
int V_86 = 0 ;
unsigned int V_76 ;
unsigned int V_106 ;
unsigned int V_107 ;
const struct V_108 * V_109 ;
V_109 = F_44 ( V_110 , & V_102 -> V_85 ) ;
V_15 = F_45 ( & V_102 -> V_85 , sizeof( * V_15 ) , V_111 ) ;
if ( ! V_15 ) {
F_36 ( & V_102 -> V_85 , L_20 ) ;
return - V_112 ;
}
V_15 -> V_85 = & V_102 -> V_85 ;
V_15 -> V_57 = V_109 -> V_40 ;
V_15 -> V_34 = V_15 -> V_57 -> V_58 *
V_15 -> V_57 -> V_88 ;
V_15 -> V_100 = V_15 -> V_57 -> V_58 +
V_15 -> V_57 -> V_88 ;
V_107 = V_15 -> V_34 ;
F_46 ( & V_15 -> V_42 ) ;
V_105 = F_37 ( V_15 ) ;
if ( V_105 )
return V_105 ;
if ( ! F_35 ( V_15 , & V_86 ) )
return - V_99 ;
V_15 -> V_48 = F_47 ( V_102 , 0 ) ;
if ( V_15 -> V_48 < 0 ) {
F_36 ( & V_102 -> V_85 , L_21 ) ;
return - V_113 ;
}
V_15 -> V_35 = F_48 ( & V_102 -> V_85 ) ;
if ( ! V_15 -> V_35 ) {
F_36 ( & V_102 -> V_85 , L_22 ) ;
return - V_112 ;
}
F_49 ( & V_15 -> V_46 , F_11 , ( unsigned long ) V_15 ) ;
V_104 = F_50 ( V_102 , V_114 , 0 ) ;
V_15 -> V_22 = F_51 ( & V_102 -> V_85 , V_104 ) ;
if ( F_52 ( V_15 -> V_22 ) )
return F_53 ( V_15 -> V_22 ) ;
V_15 -> V_77 = F_54 ( & V_102 -> V_85 , NULL ) ;
if ( F_52 ( V_15 -> V_77 ) ) {
F_36 ( & V_102 -> V_85 , L_23 ) ;
return F_53 ( V_15 -> V_77 ) ;
}
V_15 -> V_78 = F_55 ( & V_102 -> V_85 , L_24 ) ;
if ( F_52 ( V_15 -> V_78 ) ) {
F_36 ( & V_102 -> V_85 , L_25 ) ;
return F_53 ( V_15 -> V_78 ) ;
}
V_76 = F_23 ( V_15 -> V_76 , V_81 ) ;
V_106 = ( V_115 + V_76 ) * V_86 ;
V_15 -> V_45 = V_116 + V_106 + V_15 -> V_79 ;
V_15 -> V_45 = F_56 ( V_15 -> V_45 , V_117 ) ;
V_15 -> V_35 -> V_118 = V_102 -> V_118 ;
V_15 -> V_35 -> V_119 . V_120 = V_121 ;
V_15 -> V_35 -> V_85 . V_122 = & V_102 -> V_85 ;
V_15 -> V_35 -> V_123 = F_32 ;
V_15 -> V_35 -> V_124 = F_34 ;
if ( V_15 -> V_125 && V_15 -> V_30 )
V_107 *= 2 ;
V_105 = F_57 ( V_15 -> V_125 , NULL ,
V_107 ,
V_15 -> V_57 -> V_88 ,
V_15 -> V_28 , V_15 -> V_35 ) ;
if ( V_105 ) {
F_36 ( & V_102 -> V_85 , L_26 ) ;
return V_105 ;
}
F_58 ( V_126 , V_15 -> V_35 -> V_127 ) ;
F_59 ( V_15 -> V_35 , V_12 , V_13 ) ;
F_60 ( V_15 -> V_35 , V_15 ) ;
V_105 = F_61 ( & V_102 -> V_85 , V_15 -> V_48 , F_16 ,
V_128 , V_102 -> V_118 , V_15 ) ;
if ( V_105 ) {
F_36 ( & V_102 -> V_85 , L_27 ) ;
return V_105 ;
}
F_29 ( V_15 -> V_48 ) ;
V_105 = F_62 ( V_15 -> V_35 ) ;
if ( V_105 ) {
F_36 ( & V_102 -> V_85 , L_28 ) ;
return V_105 ;
}
F_63 ( V_102 , V_15 ) ;
F_64 ( & V_102 -> V_85 , V_15 -> V_56 ) ;
return 0 ;
}
static void F_65 ( struct V_14 * V_15 , bool V_37 )
{
T_1 V_17 ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
if ( V_37 )
V_17 |= V_129 ;
else
V_17 &= ~ V_129 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
}
static int F_66 ( struct V_130 * V_85 )
{
struct V_101 * V_102 = F_67 ( V_85 ) ;
struct V_14 * V_15 = F_68 ( V_102 ) ;
F_69 ( & V_15 -> V_35 -> V_131 ) ;
if ( F_70 ( & V_102 -> V_85 ) ) {
F_29 ( V_15 -> V_48 ) ;
F_30 ( & V_15 -> V_46 ) ;
F_9 ( V_15 , false ) ;
F_10 ( 0x7 , V_15 -> V_22 + V_43 ) ;
V_15 -> V_132 = F_6 ( V_15 -> V_22 + V_133 ) ;
F_10 ( 0 , V_15 -> V_22 + V_133 ) ;
F_17 ( V_15 , true ) ;
F_71 ( 30 ) ;
V_15 -> V_52 = false ;
F_65 ( V_15 , true ) ;
F_27 ( V_15 -> V_48 ) ;
F_72 ( V_15 -> V_48 ) ;
} else {
if ( V_15 -> V_35 -> V_134 )
F_28 ( V_15 ) ;
}
F_73 ( & V_15 -> V_35 -> V_131 ) ;
return 0 ;
}
static int F_74 ( struct V_130 * V_85 )
{
struct V_101 * V_102 = F_67 ( V_85 ) ;
struct V_14 * V_15 = F_68 ( V_102 ) ;
int V_105 = 0 ;
F_69 ( & V_15 -> V_35 -> V_131 ) ;
if ( F_70 ( & V_102 -> V_85 ) ) {
F_75 ( V_15 -> V_48 ) ;
F_17 ( V_15 , false ) ;
F_65 ( V_15 , false ) ;
F_10 ( V_15 -> V_132 , V_15 -> V_22 + V_133 ) ;
F_9 ( V_15 , true ) ;
if ( V_15 -> V_52 && V_15 -> V_135 ) {
F_2 ( V_15 -> V_35 , V_15 -> V_135 , 1 ) ;
F_8 ( V_15 -> V_35 ) ;
F_2 ( V_15 -> V_35 , V_15 -> V_135 , 0 ) ;
F_8 ( V_15 -> V_35 ) ;
}
} else {
if ( V_15 -> V_35 -> V_134 )
V_105 = F_19 ( V_15 ) ;
}
F_73 ( & V_15 -> V_35 -> V_131 ) ;
return V_105 ;
}
