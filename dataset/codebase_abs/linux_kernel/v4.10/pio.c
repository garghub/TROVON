static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = ( ( ( T_1 ) V_2 -> V_6 + 1 ) << 12 ) ;
V_5 |= V_4 -> V_6 ;
return V_5 ;
}
static
struct V_1 * F_2 ( struct V_7 * V_8 ,
T_1 V_5 ,
struct V_3 * * V_4 )
{
struct V_9 * V_10 = & V_8 -> V_10 ;
struct V_1 * V_2 = NULL ;
unsigned int V_11 ;
switch ( V_5 & 0xF000 ) {
case 0x1000 :
V_2 = V_10 -> V_12 ;
break;
case 0x2000 :
V_2 = V_10 -> V_13 ;
break;
case 0x3000 :
V_2 = V_10 -> V_14 ;
break;
case 0x4000 :
V_2 = V_10 -> V_15 ;
break;
case 0x5000 :
V_2 = V_10 -> V_16 ;
break;
}
if ( F_3 ( ! V_2 ) )
return NULL ;
V_11 = ( V_5 & 0x0FFF ) ;
if ( F_3 ( V_11 >= F_4 ( V_2 -> V_17 ) ) )
return NULL ;
* V_4 = & V_2 -> V_17 [ V_11 ] ;
return V_2 ;
}
static T_1 F_5 ( struct V_7 * V_8 ,
unsigned int V_6 )
{
static const T_1 V_18 [] = {
V_19 ,
V_20 ,
V_21 ,
V_22 ,
V_23 ,
V_24 ,
V_25 ,
V_26 ,
} ;
static const T_1 V_27 [] = {
V_28 ,
V_29 ,
V_30 ,
V_31 ,
V_32 ,
V_33 ,
} ;
if ( V_8 -> V_8 -> V_34 >= 11 ) {
F_3 ( V_6 >= F_4 ( V_27 ) ) ;
return V_27 [ V_6 ] ;
}
F_3 ( V_6 >= F_4 ( V_18 ) ) ;
return V_18 [ V_6 ] ;
}
static T_1 F_6 ( struct V_7 * V_8 )
{
if ( V_8 -> V_8 -> V_34 >= 11 )
return 0x18 ;
return 0 ;
}
static T_1 F_7 ( struct V_7 * V_8 )
{
if ( V_8 -> V_8 -> V_34 >= 11 )
return 0x38 ;
return 8 ;
}
static struct V_1 * F_8 ( struct V_7 * V_8 ,
unsigned int V_6 )
{
struct V_1 * V_2 ;
struct V_3 * V_35 ;
unsigned int V_36 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_38 = V_8 -> V_8 -> V_34 ;
V_2 -> V_39 = F_5 ( V_8 , V_6 ) +
F_6 ( V_8 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_40 = V_41 ;
if ( V_2 -> V_38 >= 8 ) {
V_2 -> V_42 = 1920 ;
} else {
V_2 -> V_42 = F_10 ( V_2 , V_43 ) ;
V_2 -> V_42 -= 80 ;
}
F_11 ( & V_2 -> V_44 ) ;
for ( V_36 = 0 ; V_36 < F_4 ( V_2 -> V_17 ) ; V_36 ++ ) {
V_35 = & ( V_2 -> V_17 [ V_36 ] ) ;
F_11 ( & V_35 -> V_45 ) ;
V_35 -> V_6 = V_36 ;
V_35 -> V_46 = V_2 ;
F_12 ( & V_35 -> V_45 , & V_2 -> V_44 ) ;
}
return V_2 ;
}
static struct V_47 * F_13 ( struct V_7 * V_8 ,
unsigned int V_6 )
{
struct V_47 * V_2 ;
V_2 = F_9 ( sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_38 = V_8 -> V_8 -> V_34 ;
V_2 -> V_39 = F_5 ( V_8 , V_6 ) +
F_7 ( V_8 ) ;
F_14 ( V_8 , V_6 , 1 ) ;
return V_2 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned int V_36 ;
for ( V_36 = 0 ; V_36 < F_4 ( V_2 -> V_17 ) ; V_36 ++ ) {
V_4 = & ( V_2 -> V_17 [ V_36 ] ) ;
if ( V_4 -> V_48 ) {
F_16 ( V_2 -> V_8 -> V_49 -> V_50 , V_4 -> V_48 ) ;
V_4 -> V_48 = NULL ;
}
}
}
static void F_17 ( struct V_1 * V_2 ,
const char * V_51 )
{
if ( ! V_2 )
return;
F_15 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static void F_19 ( struct V_47 * V_2 ,
const char * V_51 )
{
if ( ! V_2 )
return;
F_18 ( V_2 ) ;
}
void F_20 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
if ( ! F_21 ( V_8 ) )
return;
V_10 = & V_8 -> V_10 ;
F_22 ( V_10 , V_52 ) ;
F_23 ( V_10 , V_16 ) ;
F_23 ( V_10 , V_15 ) ;
F_23 ( V_10 , V_14 ) ;
F_23 ( V_10 , V_13 ) ;
F_23 ( V_10 , V_12 ) ;
}
int F_24 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = & V_8 -> V_10 ;
int V_53 = - V_54 ;
F_25 ( V_8 , V_55 , F_26 ( V_8 , V_55 )
& ~ V_56 ) ;
F_27 ( V_8 , V_57 , V_58 , 0 ) ;
V_10 -> V_12 = F_8 ( V_8 , 0 ) ;
if ( ! V_10 -> V_12 )
goto V_59;
V_10 -> V_13 = F_8 ( V_8 , 1 ) ;
if ( ! V_10 -> V_13 )
goto V_60;
V_10 -> V_14 = F_8 ( V_8 , 2 ) ;
if ( ! V_10 -> V_14 )
goto V_61;
V_10 -> V_15 = F_8 ( V_8 , 3 ) ;
if ( ! V_10 -> V_15 )
goto V_62;
V_10 -> V_16 = F_8 ( V_8 , 4 ) ;
if ( ! V_10 -> V_16 )
goto V_63;
V_10 -> V_52 = F_13 ( V_8 , 0 ) ;
if ( ! V_10 -> V_52 )
goto V_64;
F_28 ( V_8 -> V_49 , L_1 ) ;
V_53 = 0 ;
V_59:
return V_53 ;
V_64:
F_23 ( V_10 , V_16 ) ;
V_63:
F_23 ( V_10 , V_15 ) ;
V_62:
F_23 ( V_10 , V_14 ) ;
V_61:
F_23 ( V_10 , V_13 ) ;
V_60:
F_23 ( V_10 , V_12 ) ;
return V_53 ;
}
static struct V_1 * F_29 ( struct V_7 * V_8 ,
T_2 V_65 )
{
struct V_1 * V_2 ;
if ( V_8 -> V_66 ) {
switch ( V_65 ) {
default:
F_3 ( 1 ) ;
case 0 :
V_2 = V_8 -> V_10 . V_15 ;
break;
case 1 :
V_2 = V_8 -> V_10 . V_14 ;
break;
case 2 :
V_2 = V_8 -> V_10 . V_13 ;
break;
case 3 :
V_2 = V_8 -> V_10 . V_12 ;
break;
}
} else
V_2 = V_8 -> V_10 . V_13 ;
return V_2 ;
}
static T_1 F_30 ( struct V_1 * V_2 ,
T_1 V_67 ,
const void * V_68 ,
unsigned int V_69 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_70 * V_49 = V_8 -> V_49 ;
const T_2 * V_71 = V_68 ;
V_67 |= V_72 | V_73 ;
F_31 ( V_2 , V_74 , V_67 ) ;
F_32 ( V_8 , V_71 , ( V_69 & ~ 1 ) ,
V_2 -> V_39 + V_75 ,
sizeof( T_1 ) ) ;
if ( V_69 & 1 ) {
T_2 * V_76 = V_49 -> V_77 ;
F_33 ( sizeof( V_49 -> V_77 ) < 2 ) ;
V_67 &= ~ V_73 ;
F_31 ( V_2 , V_74 , V_67 ) ;
V_76 [ 0 ] = V_71 [ V_69 - 1 ] ;
V_76 [ 1 ] = 0 ;
F_32 ( V_8 , V_76 , 2 ,
V_2 -> V_39 + V_75 ,
sizeof( T_1 ) ) ;
}
return V_67 ;
}
static void F_34 ( struct V_3 * V_4 ,
const T_2 * V_78 , unsigned int V_79 )
{
struct V_1 * V_2 = V_4 -> V_46 ;
const char * V_80 = V_4 -> V_48 -> V_71 ;
unsigned int V_81 = V_4 -> V_48 -> V_82 ;
T_1 V_67 ;
V_67 = F_10 ( V_2 , V_74 ) ;
V_67 |= V_83 ;
V_67 &= ~ V_84 ;
V_67 = F_30 ( V_2 , V_67 , V_78 , V_79 ) ;
V_67 = F_30 ( V_2 , V_67 , V_80 , V_81 ) ;
V_67 |= V_84 ;
F_31 ( V_2 , V_74 , V_67 ) ;
}
static T_3 F_35 ( struct V_1 * V_2 ,
T_3 V_67 ,
const void * V_68 ,
unsigned int V_69 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_70 * V_49 = V_8 -> V_49 ;
const T_2 * V_71 = V_68 ;
V_67 |= V_85 | V_86 |
V_87 | V_88 ;
F_36 ( V_2 , V_89 , V_67 ) ;
F_32 ( V_8 , V_71 , ( V_69 & ~ 3 ) ,
V_2 -> V_39 + V_90 ,
sizeof( T_3 ) ) ;
if ( V_69 & 3 ) {
T_2 * V_76 = V_49 -> V_77 ;
F_33 ( sizeof( V_49 -> V_77 ) < 4 ) ;
memset ( V_76 , 0 , 4 ) ;
V_67 &= ~ ( V_86 | V_87 |
V_88 ) ;
switch ( V_69 & 3 ) {
case 3 :
V_67 |= V_87 | V_86 ;
V_76 [ 0 ] = V_71 [ V_69 - 3 ] ;
V_76 [ 1 ] = V_71 [ V_69 - 2 ] ;
V_76 [ 2 ] = V_71 [ V_69 - 1 ] ;
break;
case 2 :
V_67 |= V_86 ;
V_76 [ 0 ] = V_71 [ V_69 - 2 ] ;
V_76 [ 1 ] = V_71 [ V_69 - 1 ] ;
break;
case 1 :
V_76 [ 0 ] = V_71 [ V_69 - 1 ] ;
break;
}
F_36 ( V_2 , V_89 , V_67 ) ;
F_32 ( V_8 , V_76 , 4 ,
V_2 -> V_39 + V_90 ,
sizeof( T_3 ) ) ;
}
return V_67 ;
}
static void F_37 ( struct V_3 * V_4 ,
const T_2 * V_78 , unsigned int V_79 )
{
struct V_1 * V_2 = V_4 -> V_46 ;
const char * V_80 = V_4 -> V_48 -> V_71 ;
unsigned int V_81 = V_4 -> V_48 -> V_82 ;
T_3 V_67 ;
V_67 = F_38 ( V_2 , V_89 ) ;
V_67 |= V_91 ;
V_67 &= ~ V_92 ;
V_67 = F_35 ( V_2 , V_67 , V_78 , V_79 ) ;
V_67 = F_35 ( V_2 , V_67 , V_80 , V_81 ) ;
V_67 |= V_92 ;
F_36 ( V_2 , V_74 , V_67 ) ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_93 * V_48 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_70 * V_49 = V_8 -> V_49 ;
struct V_3 * V_4 ;
T_1 V_5 ;
int V_53 ;
unsigned int V_79 ;
struct V_94 * V_95 = F_40 ( V_48 ) ;
struct V_96 * V_97 = (struct V_96 * ) V_49 -> V_98 ;
F_3 ( F_41 ( & V_2 -> V_44 ) ) ;
V_4 = F_42 ( V_2 -> V_44 . V_99 ,
struct V_3 , V_45 ) ;
V_5 = F_1 ( V_2 , V_4 ) ;
V_79 = F_43 ( V_8 ) ;
F_33 ( sizeof( V_49 -> V_98 ) < sizeof( struct V_96 ) ) ;
F_3 ( sizeof( V_49 -> V_98 ) < V_79 ) ;
V_53 = F_44 ( V_8 , ( T_2 * ) V_97 , V_48 ,
V_95 , V_5 ) ;
if ( V_53 )
return V_53 ;
if ( V_95 -> V_100 & V_101 ) {
F_27 ( V_8 , V_57 ,
V_102 , V_5 ) ;
}
V_4 -> V_48 = V_48 ;
if ( V_2 -> V_38 >= 8 )
F_37 ( V_4 , ( const T_2 * ) V_97 , V_79 ) ;
else
F_34 ( V_4 , ( const T_2 * ) V_97 , V_79 ) ;
F_45 ( & V_4 -> V_45 ) ;
V_2 -> V_103 += F_46 ( V_48 -> V_82 + V_79 , 4 ) ;
V_2 -> V_40 -= 1 ;
return 0 ;
}
int F_47 ( struct V_7 * V_8 , struct V_93 * V_48 )
{
struct V_1 * V_2 ;
struct V_104 * V_78 ;
unsigned int V_79 , V_105 ;
int V_53 = 0 ;
struct V_94 * V_95 = F_40 ( V_48 ) ;
V_78 = (struct V_104 * ) V_48 -> V_71 ;
if ( V_95 -> V_100 & V_101 ) {
V_2 = V_8 -> V_10 . V_16 ;
V_78 -> V_106 |= F_48 ( V_107 ) ;
} else {
V_2 = F_29 ( V_8 , F_49 ( V_48 ) ) ;
}
V_79 = F_43 ( V_8 ) ;
V_105 = F_46 ( V_48 -> V_82 + V_79 , 4 ) ;
if ( F_50 ( V_105 > V_2 -> V_42 ) ) {
V_53 = - V_108 ;
F_28 ( V_8 -> V_49 , L_2 ) ;
goto V_59;
}
if ( F_50 ( V_2 -> V_40 == 0 ) ) {
V_53 = - V_108 ;
F_51 ( V_8 -> V_49 , L_3 ) ;
goto V_59;
}
F_3 ( V_2 -> V_103 > V_2 -> V_42 ) ;
if ( V_105 > ( V_2 -> V_42 - V_2 -> V_103 ) ) {
V_53 = - V_109 ;
F_52 ( V_8 -> V_49 -> V_50 , F_49 ( V_48 ) ) ;
V_2 -> V_110 = true ;
goto V_59;
}
V_2 -> V_65 = F_49 ( V_48 ) ;
V_53 = F_39 ( V_2 , V_48 ) ;
if ( F_50 ( V_53 == - V_111 ) ) {
F_16 ( V_8 -> V_49 -> V_50 , V_48 ) ;
V_53 = 0 ;
goto V_59;
}
if ( F_50 ( V_53 ) ) {
F_53 ( V_8 -> V_49 , L_4 ) ;
goto V_59;
}
F_3 ( V_2 -> V_103 > V_2 -> V_42 ) ;
if ( ( ( V_2 -> V_42 - V_2 -> V_103 ) < F_46 ( 2 + 2 + 6 , 4 ) ) ||
( V_2 -> V_40 == 0 ) ) {
F_52 ( V_8 -> V_49 -> V_50 , F_49 ( V_48 ) ) ;
V_2 -> V_110 = true ;
}
V_59:
return V_53 ;
}
void F_54 ( struct V_7 * V_8 ,
const struct V_112 * V_113 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 = NULL ;
unsigned int V_105 ;
struct V_94 * V_95 ;
V_2 = F_2 ( V_8 , V_113 -> V_5 , & V_4 ) ;
if ( F_50 ( ! V_2 ) )
return;
F_3 ( ! V_4 ) ;
V_95 = F_40 ( V_4 -> V_48 ) ;
F_55 ( V_8 , V_95 , V_113 ) ;
V_105 = V_4 -> V_48 -> V_82 + F_43 ( V_8 ) ;
V_105 = F_46 ( V_105 , 4 ) ;
V_2 -> V_103 -= V_105 ;
V_2 -> V_40 += 1 ;
F_56 ( V_8 -> V_49 -> V_50 , V_4 -> V_48 ) ;
V_4 -> V_48 = NULL ;
F_12 ( & V_4 -> V_45 , & V_2 -> V_44 ) ;
if ( V_2 -> V_110 ) {
F_57 ( V_8 -> V_49 -> V_50 , V_2 -> V_65 ) ;
V_2 -> V_110 = false ;
}
}
static bool F_58 ( struct V_47 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
struct V_70 * V_49 = V_8 -> V_49 ;
T_1 V_82 ;
T_3 V_114 = 0 ;
unsigned int V_36 , V_115 ;
struct V_93 * V_48 ;
const char * V_116 = NULL ;
struct V_117 * V_118 =
(struct V_117 * ) V_49 -> V_98 ;
T_4 V_119 = sizeof( * V_118 ) ;
F_33 ( sizeof( V_49 -> V_98 ) < sizeof( * V_118 ) ) ;
switch ( V_8 -> V_120 . V_121 ) {
case V_122 :
case V_123 :
V_119 -= sizeof( V_118 -> V_124 ) -
sizeof( V_118 -> V_125 ) ;
break;
case V_126 :
break;
}
memset ( V_118 , 0 , V_119 ) ;
if ( V_2 -> V_38 >= 8 ) {
T_3 V_67 ;
V_67 = F_59 ( V_2 , V_127 ) ;
if ( ! ( V_67 & V_128 ) )
return false ;
F_60 ( V_2 , V_127 ,
V_128 ) ;
for ( V_36 = 0 ; V_36 < 10 ; V_36 ++ ) {
V_67 = F_59 ( V_2 , V_127 ) ;
if ( V_67 & V_129 )
goto V_130;
F_61 ( 10 ) ;
}
} else {
T_1 V_67 ;
V_67 = F_62 ( V_2 , V_131 ) ;
if ( ! ( V_67 & V_132 ) )
return false ;
F_63 ( V_2 , V_131 ,
V_132 ) ;
for ( V_36 = 0 ; V_36 < 10 ; V_36 ++ ) {
V_67 = F_62 ( V_2 , V_131 ) ;
if ( V_67 & V_133 )
goto V_130;
F_61 ( 10 ) ;
}
}
F_28 ( V_2 -> V_8 -> V_49 , L_5 ) ;
return true ;
V_130:
if ( V_2 -> V_38 >= 8 ) {
F_64 ( V_8 , V_118 , V_119 ,
V_2 -> V_39 + V_134 ,
sizeof( T_3 ) ) ;
} else {
F_64 ( V_8 , V_118 , V_119 ,
V_2 -> V_39 + V_135 ,
sizeof( T_1 ) ) ;
}
V_82 = F_65 ( V_118 -> V_81 ) ;
if ( F_50 ( V_82 > 0x700 ) ) {
V_116 = L_6 ;
goto V_136;
}
if ( F_50 ( V_82 == 0 ) ) {
V_116 = L_7 ;
goto V_136;
}
switch ( V_8 -> V_120 . V_121 ) {
case V_126 :
V_114 = F_66 ( V_118 -> V_124 . V_137 ) ;
break;
case V_122 :
case V_123 :
V_114 = F_66 ( V_118 -> V_125 . V_137 ) ;
break;
}
if ( V_114 & V_138 ) {
if ( ! ( V_2 -> V_8 -> V_49 -> V_139 & V_140 ) ) {
V_116 = L_8 ;
goto V_136;
}
}
V_115 = ( V_114 & V_141 ) ? 2 : 0 ;
V_48 = F_67 ( V_82 + V_115 + 2 ) ;
if ( F_50 ( ! V_48 ) ) {
V_116 = L_9 ;
goto V_136;
}
F_68 ( V_48 , 2 ) ;
F_69 ( V_48 , V_82 + V_115 ) ;
if ( V_2 -> V_38 >= 8 ) {
F_64 ( V_8 , V_48 -> V_71 + V_115 , ( V_82 & ~ 3 ) ,
V_2 -> V_39 + V_134 ,
sizeof( T_3 ) ) ;
if ( V_82 & 3 ) {
T_2 * V_76 = V_49 -> V_77 ;
F_33 ( sizeof( V_49 -> V_77 ) < 4 ) ;
F_64 ( V_8 , V_76 , 4 ,
V_2 -> V_39 + V_134 ,
sizeof( T_3 ) ) ;
switch ( V_82 & 3 ) {
case 3 :
V_48 -> V_71 [ V_82 + V_115 - 3 ] = V_76 [ 0 ] ;
V_48 -> V_71 [ V_82 + V_115 - 2 ] = V_76 [ 1 ] ;
V_48 -> V_71 [ V_82 + V_115 - 1 ] = V_76 [ 2 ] ;
break;
case 2 :
V_48 -> V_71 [ V_82 + V_115 - 2 ] = V_76 [ 0 ] ;
V_48 -> V_71 [ V_82 + V_115 - 1 ] = V_76 [ 1 ] ;
break;
case 1 :
V_48 -> V_71 [ V_82 + V_115 - 1 ] = V_76 [ 0 ] ;
break;
}
}
} else {
F_64 ( V_8 , V_48 -> V_71 + V_115 , ( V_82 & ~ 1 ) ,
V_2 -> V_39 + V_135 ,
sizeof( T_1 ) ) ;
if ( V_82 & 1 ) {
T_2 * V_76 = V_49 -> V_77 ;
F_33 ( sizeof( V_49 -> V_77 ) < 2 ) ;
F_64 ( V_8 , V_76 , 2 ,
V_2 -> V_39 + V_135 ,
sizeof( T_1 ) ) ;
V_48 -> V_71 [ V_82 + V_115 - 1 ] = V_76 [ 0 ] ;
}
}
F_70 ( V_2 -> V_8 , V_48 , V_118 ) ;
return true ;
V_136:
if ( V_116 )
F_28 ( V_2 -> V_8 -> V_49 , L_10 , V_116 ) ;
if ( V_2 -> V_38 >= 8 )
F_60 ( V_2 , V_127 , V_129 ) ;
else
F_63 ( V_2 , V_131 , V_133 ) ;
return true ;
}
void F_71 ( struct V_47 * V_2 )
{
unsigned int V_142 = 0 ;
bool V_143 ;
while ( 1 ) {
V_143 = ( F_58 ( V_2 ) == 0 ) ;
if ( V_143 )
break;
F_72 () ;
if ( F_73 ( ++ V_142 > 10000 ) )
break;
}
}
static void F_74 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 >= 8 ) {
F_36 ( V_2 , V_89 ,
F_38 ( V_2 , V_89 )
| V_144 ) ;
} else {
F_31 ( V_2 , V_74 ,
F_10 ( V_2 , V_74 )
| V_145 ) ;
}
}
static void F_75 ( struct V_1 * V_2 )
{
if ( V_2 -> V_38 >= 8 ) {
F_36 ( V_2 , V_89 ,
F_38 ( V_2 , V_89 )
& ~ V_144 ) ;
} else {
F_31 ( V_2 , V_74 ,
F_10 ( V_2 , V_74 )
& ~ V_145 ) ;
}
}
void F_76 ( struct V_7 * V_8 )
{
F_77 ( V_8 , V_146 ) ;
F_74 ( V_8 -> V_10 . V_12 ) ;
F_74 ( V_8 -> V_10 . V_13 ) ;
F_74 ( V_8 -> V_10 . V_14 ) ;
F_74 ( V_8 -> V_10 . V_15 ) ;
F_74 ( V_8 -> V_10 . V_16 ) ;
}
void F_78 ( struct V_7 * V_8 )
{
F_75 ( V_8 -> V_10 . V_16 ) ;
F_75 ( V_8 -> V_10 . V_15 ) ;
F_75 ( V_8 -> V_10 . V_14 ) ;
F_75 ( V_8 -> V_10 . V_13 ) ;
F_75 ( V_8 -> V_10 . V_12 ) ;
F_77 ( V_8 , 0 ) ;
}
