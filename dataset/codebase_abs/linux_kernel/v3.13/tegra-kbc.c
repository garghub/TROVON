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
F_21 ( V_15 -> V_77 ) ;
F_22 ( 100 ) ;
F_23 ( V_15 -> V_77 ) ;
F_22 ( 100 ) ;
F_18 ( V_15 ) ;
F_17 ( V_15 , false ) ;
F_10 ( V_15 -> V_78 , V_15 -> V_22 + V_79 ) ;
V_76 = F_24 ( V_15 -> V_76 , V_80 ) ;
V_17 = F_25 ( V_76 ) ;
V_17 |= F_26 ( 1 ) ;
V_17 |= V_39 ;
V_17 |= V_81 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_82 ) ;
V_15 -> V_50 = F_27 ( ( V_17 & 0xfffff ) * 32 ) ;
V_15 -> V_11 = 0 ;
while ( 1 ) {
V_17 = F_6 ( V_15 -> V_22 + V_43 ) ;
V_17 >>= 4 ;
if ( ! V_17 )
break;
V_17 = F_6 ( V_15 -> V_22 + V_23 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_83 ) ;
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
F_32 ( V_15 -> V_77 ) ;
}
static int F_33 ( struct V_1 * V_84 )
{
struct V_14 * V_15 = F_34 ( V_84 ) ;
return F_19 ( V_15 ) ;
}
static void F_35 ( struct V_1 * V_84 )
{
struct V_14 * V_15 = F_34 ( V_84 ) ;
return F_29 ( V_15 ) ;
}
static bool F_36 ( const struct V_14 * V_15 ,
unsigned int * V_85 )
{
int V_7 ;
* V_85 = 0 ;
for ( V_7 = 0 ; V_7 < V_60 ; V_7 ++ ) {
const struct V_86 * V_71 = & V_15 -> V_71 [ V_7 ] ;
switch ( V_71 -> type ) {
case V_72 :
if ( V_71 -> V_73 >= V_15 -> V_57 -> V_58 ) {
F_37 ( V_15 -> V_84 ,
L_1 ,
V_7 , V_71 -> V_73 ) ;
return false ;
}
( * V_85 ) ++ ;
break;
case V_74 :
if ( V_71 -> V_73 >= V_15 -> V_57 -> V_87 ) {
F_37 ( V_15 -> V_84 ,
L_2 ,
V_7 , V_71 -> V_73 ) ;
return false ;
}
break;
case V_75 :
break;
default:
F_37 ( V_15 -> V_84 ,
L_3 ,
V_71 -> type , V_71 -> V_73 ) ;
return false ;
}
}
return true ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_88 * V_89 = V_15 -> V_84 -> V_90 ;
T_1 V_91 ;
int V_7 ;
T_1 V_85 = 0 ;
T_1 V_92 = 0 ;
T_1 V_93 [ V_60 ] ;
T_1 V_94 [ V_60 ] ;
int V_95 ;
int V_96 ;
if ( ! F_39 ( V_89 , L_4 , & V_91 ) )
V_15 -> V_76 = V_91 ;
if ( ! F_39 ( V_89 , L_5 , & V_91 ) )
V_15 -> V_78 = V_91 ;
if ( F_40 ( V_89 , L_6 , NULL ) )
V_15 -> V_31 = true ;
if ( F_40 ( V_89 , L_7 , NULL ) )
V_15 -> V_56 = true ;
if ( ! F_41 ( V_89 , L_8 , & V_95 ) ) {
F_37 ( V_15 -> V_84 , L_9 ) ;
return - V_97 ;
}
V_85 = V_95 / sizeof( T_1 ) ;
if ( ! F_41 ( V_89 , L_10 , & V_95 ) ) {
F_37 ( V_15 -> V_84 , L_11 ) ;
return - V_97 ;
}
V_92 = V_95 / sizeof( T_1 ) ;
if ( V_85 > V_15 -> V_57 -> V_58 ) {
F_37 ( V_15 -> V_84 ,
L_12 ) ;
return - V_98 ;
}
if ( V_92 > V_15 -> V_57 -> V_87 ) {
F_37 ( V_15 -> V_84 ,
L_13 ) ;
return - V_98 ;
}
if ( ! F_41 ( V_89 , L_14 , & V_95 ) ) {
F_37 ( V_15 -> V_84 , L_15 ) ;
return - V_97 ;
}
if ( ! V_85 || ! V_92 || ( ( V_85 + V_92 ) > V_60 ) ) {
F_37 ( V_15 -> V_84 ,
L_16 ) ;
return - V_98 ;
}
for ( V_7 = 0 ; V_7 < V_15 -> V_99 ; V_7 ++ )
V_15 -> V_71 [ V_7 ] . type = V_75 ;
V_96 = F_42 ( V_89 , L_8 ,
V_94 , V_85 ) ;
if ( V_96 < 0 ) {
F_37 ( V_15 -> V_84 , L_17 ) ;
return - V_98 ;
}
V_96 = F_42 ( V_89 , L_10 ,
V_93 , V_92 ) ;
if ( V_96 < 0 ) {
F_37 ( V_15 -> V_84 , L_18 ) ;
return - V_98 ;
}
for ( V_7 = 0 ; V_7 < V_85 ; V_7 ++ ) {
V_15 -> V_71 [ V_94 [ V_7 ] ] . type = V_72 ;
V_15 -> V_71 [ V_94 [ V_7 ] ] . V_73 = V_7 ;
}
for ( V_7 = 0 ; V_7 < V_92 ; V_7 ++ ) {
V_15 -> V_71 [ V_93 [ V_7 ] ] . type = V_74 ;
V_15 -> V_71 [ V_93 [ V_7 ] ] . V_73 = V_7 ;
}
return 0 ;
}
static int F_43 ( struct V_100 * V_101 )
{
struct V_14 * V_15 ;
struct V_102 * V_103 ;
int V_104 ;
int V_85 = 0 ;
unsigned int V_76 ;
unsigned int V_105 ;
unsigned int V_106 ;
const struct V_107 * V_108 ;
V_108 = F_44 ( V_109 , & V_101 -> V_84 ) ;
V_15 = F_45 ( & V_101 -> V_84 , sizeof( * V_15 ) , V_110 ) ;
if ( ! V_15 ) {
F_37 ( & V_101 -> V_84 , L_19 ) ;
return - V_111 ;
}
V_15 -> V_84 = & V_101 -> V_84 ;
V_15 -> V_57 = V_108 -> V_40 ;
V_15 -> V_34 = V_15 -> V_57 -> V_58 *
V_15 -> V_57 -> V_87 ;
V_15 -> V_99 = V_15 -> V_57 -> V_58 +
V_15 -> V_57 -> V_87 ;
V_106 = V_15 -> V_34 ;
F_46 ( & V_15 -> V_42 ) ;
V_104 = F_38 ( V_15 ) ;
if ( V_104 )
return V_104 ;
if ( ! F_36 ( V_15 , & V_85 ) )
return - V_98 ;
V_15 -> V_48 = F_47 ( V_101 , 0 ) ;
if ( V_15 -> V_48 < 0 ) {
F_37 ( & V_101 -> V_84 , L_20 ) ;
return - V_112 ;
}
V_15 -> V_35 = F_48 ( & V_101 -> V_84 ) ;
if ( ! V_15 -> V_35 ) {
F_37 ( & V_101 -> V_84 , L_21 ) ;
return - V_111 ;
}
F_49 ( & V_15 -> V_46 , F_11 , ( unsigned long ) V_15 ) ;
V_103 = F_50 ( V_101 , V_113 , 0 ) ;
V_15 -> V_22 = F_51 ( & V_101 -> V_84 , V_103 ) ;
if ( F_52 ( V_15 -> V_22 ) )
return F_53 ( V_15 -> V_22 ) ;
V_15 -> V_77 = F_54 ( & V_101 -> V_84 , NULL ) ;
if ( F_52 ( V_15 -> V_77 ) ) {
F_37 ( & V_101 -> V_84 , L_22 ) ;
return F_53 ( V_15 -> V_77 ) ;
}
V_76 = F_24 ( V_15 -> V_76 , V_80 ) ;
V_105 = ( V_114 + V_76 ) * V_85 ;
V_15 -> V_45 = V_115 + V_105 + V_15 -> V_78 ;
V_15 -> V_45 = F_55 ( V_15 -> V_45 , V_116 ) ;
V_15 -> V_35 -> V_117 = V_101 -> V_117 ;
V_15 -> V_35 -> V_118 . V_119 = V_120 ;
V_15 -> V_35 -> V_84 . V_121 = & V_101 -> V_84 ;
V_15 -> V_35 -> V_122 = F_33 ;
V_15 -> V_35 -> V_123 = F_35 ;
if ( V_15 -> V_124 && V_15 -> V_30 )
V_106 *= 2 ;
V_104 = F_56 ( V_15 -> V_124 , NULL ,
V_106 ,
V_15 -> V_57 -> V_87 ,
V_15 -> V_28 , V_15 -> V_35 ) ;
if ( V_104 ) {
F_37 ( & V_101 -> V_84 , L_23 ) ;
return V_104 ;
}
F_57 ( V_125 , V_15 -> V_35 -> V_126 ) ;
F_58 ( V_15 -> V_35 , V_12 , V_13 ) ;
F_59 ( V_15 -> V_35 , V_15 ) ;
V_104 = F_60 ( & V_101 -> V_84 , V_15 -> V_48 , F_16 ,
V_127 | V_128 , V_101 -> V_117 , V_15 ) ;
if ( V_104 ) {
F_37 ( & V_101 -> V_84 , L_24 ) ;
return V_104 ;
}
F_30 ( V_15 -> V_48 ) ;
V_104 = F_61 ( V_15 -> V_35 ) ;
if ( V_104 ) {
F_37 ( & V_101 -> V_84 , L_25 ) ;
return V_104 ;
}
F_62 ( V_101 , V_15 ) ;
F_63 ( & V_101 -> V_84 , V_15 -> V_56 ) ;
return 0 ;
}
static void F_64 ( struct V_14 * V_15 , bool V_37 )
{
T_1 V_17 ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
if ( V_37 )
V_17 |= V_129 ;
else
V_17 &= ~ V_129 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
}
static int F_65 ( struct V_130 * V_84 )
{
struct V_100 * V_101 = F_66 ( V_84 ) ;
struct V_14 * V_15 = F_67 ( V_101 ) ;
F_68 ( & V_15 -> V_35 -> V_131 ) ;
if ( F_69 ( & V_101 -> V_84 ) ) {
F_30 ( V_15 -> V_48 ) ;
F_31 ( & V_15 -> V_46 ) ;
F_9 ( V_15 , false ) ;
F_10 ( 0x7 , V_15 -> V_22 + V_43 ) ;
V_15 -> V_132 = F_6 ( V_15 -> V_22 + V_133 ) ;
F_10 ( 0 , V_15 -> V_22 + V_133 ) ;
F_17 ( V_15 , true ) ;
F_70 ( 30 ) ;
V_15 -> V_52 = false ;
F_64 ( V_15 , true ) ;
F_28 ( V_15 -> V_48 ) ;
F_71 ( V_15 -> V_48 ) ;
} else {
if ( V_15 -> V_35 -> V_134 )
F_29 ( V_15 ) ;
}
F_72 ( & V_15 -> V_35 -> V_131 ) ;
return 0 ;
}
static int F_73 ( struct V_130 * V_84 )
{
struct V_100 * V_101 = F_66 ( V_84 ) ;
struct V_14 * V_15 = F_67 ( V_101 ) ;
int V_104 = 0 ;
F_68 ( & V_15 -> V_35 -> V_131 ) ;
if ( F_69 ( & V_101 -> V_84 ) ) {
F_74 ( V_15 -> V_48 ) ;
F_17 ( V_15 , false ) ;
F_64 ( V_15 , false ) ;
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
V_104 = F_19 ( V_15 ) ;
}
F_72 ( & V_15 -> V_35 -> V_131 ) ;
return V_104 ;
}
