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
static void F_11 ( struct V_14 * V_15 , bool V_37 )
{
T_1 V_17 ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
if ( V_37 )
V_17 |= V_40 ;
else
V_17 &= ~ V_40 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
}
static void F_12 ( unsigned long V_41 )
{
struct V_14 * V_15 = (struct V_14 * ) V_41 ;
unsigned long V_42 ;
T_1 V_17 ;
unsigned int V_7 ;
F_13 ( & V_15 -> V_43 , V_42 ) ;
V_17 = ( F_6 ( V_15 -> V_22 + V_44 ) >> 4 ) & 0xf ;
if ( V_17 ) {
unsigned long V_45 ;
F_5 ( V_15 ) ;
V_45 = ( V_17 == 1 ) ? V_15 -> V_46 : 1 ;
F_14 ( & V_15 -> V_47 , V_48 + F_15 ( V_45 ) ) ;
} else {
for ( V_7 = 0 ; V_7 < V_15 -> V_11 ; V_7 ++ )
F_2 ( V_15 -> V_35 , V_15 -> V_36 [ V_7 ] , 0 ) ;
F_8 ( V_15 -> V_35 ) ;
V_15 -> V_11 = 0 ;
F_9 ( V_15 , true ) ;
}
F_16 ( & V_15 -> V_43 , V_42 ) ;
}
static T_3 F_17 ( int V_49 , void * args )
{
struct V_14 * V_15 = args ;
unsigned long V_42 ;
T_1 V_17 ;
F_13 ( & V_15 -> V_43 , V_42 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_44 ) ;
F_10 ( V_17 , V_15 -> V_22 + V_44 ) ;
if ( V_17 & V_50 ) {
F_9 ( V_15 , false ) ;
F_14 ( & V_15 -> V_47 , V_48 + V_15 -> V_51 ) ;
} else if ( V_17 & V_52 ) {
V_15 -> V_53 = true ;
}
F_16 ( & V_15 -> V_43 , V_42 ) ;
return V_54 ;
}
static void F_18 ( struct V_14 * V_15 , bool V_55 )
{
const struct V_56 * V_57 = V_15 -> V_57 ;
int V_7 ;
unsigned int V_58 ;
V_58 = ( V_55 && ! V_57 -> V_59 ) ? ~ 0 : 0 ;
for ( V_7 = 0 ; V_7 < V_60 ; V_7 ++ )
F_10 ( V_58 , V_15 -> V_22 + V_61 + V_7 * 4 ) ;
}
static void F_19 ( struct V_14 * V_15 )
{
const struct V_56 * V_57 = V_15 -> V_57 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_62 ; V_7 ++ ) {
T_1 V_63 = 5 * ( V_7 % 6 ) ;
T_1 V_64 = 4 * ( V_7 % 8 ) ;
T_1 V_65 = 0x1f << V_63 ;
T_1 V_66 = 0x0f << V_64 ;
T_1 V_67 = ( V_7 / 6 ) * 4 + V_68 ;
T_1 V_69 = ( V_7 / 8 ) * 4 + V_70 ;
T_1 V_71 = F_6 ( V_15 -> V_22 + V_67 ) ;
T_1 V_72 = F_6 ( V_15 -> V_22 + V_69 ) ;
V_71 &= ~ V_65 ;
V_72 &= ~ V_66 ;
switch ( V_57 -> V_73 [ V_7 ] . type ) {
case V_74 :
V_71 |= ( ( V_57 -> V_73 [ V_7 ] . V_75 << 1 ) | 1 ) << V_63 ;
break;
case V_76 :
V_72 |= ( ( V_57 -> V_73 [ V_7 ] . V_75 << 1 ) | 1 ) << V_64 ;
break;
case V_77 :
break;
}
F_10 ( V_71 , V_15 -> V_22 + V_67 ) ;
F_10 ( V_72 , V_15 -> V_22 + V_69 ) ;
}
}
static int F_20 ( struct V_14 * V_15 )
{
const struct V_56 * V_57 = V_15 -> V_57 ;
unsigned int V_78 ;
T_1 V_17 = 0 ;
F_21 ( V_15 -> V_79 ) ;
F_22 ( V_15 -> V_79 ) ;
F_23 ( 100 ) ;
F_24 ( V_15 -> V_79 ) ;
F_23 ( 100 ) ;
F_19 ( V_15 ) ;
F_18 ( V_15 , false ) ;
F_10 ( V_57 -> V_80 , V_15 -> V_22 + V_81 ) ;
V_78 = F_25 ( V_57 -> V_78 , V_82 ) ;
V_17 = F_26 ( V_78 ) ;
V_17 |= F_27 ( 1 ) ;
V_17 |= V_39 ;
V_17 |= V_83 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_84 ) ;
V_15 -> V_51 = F_28 ( ( V_17 & 0xfffff ) * 32 ) ;
V_15 -> V_11 = 0 ;
while ( 1 ) {
V_17 = F_6 ( V_15 -> V_22 + V_44 ) ;
V_17 >>= 4 ;
if ( ! V_17 )
break;
V_17 = F_6 ( V_15 -> V_22 + V_23 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_85 ) ;
}
F_10 ( 0x7 , V_15 -> V_22 + V_44 ) ;
F_29 ( V_15 -> V_49 ) ;
return 0 ;
}
static void F_30 ( struct V_14 * V_15 )
{
unsigned long V_42 ;
T_1 V_17 ;
F_13 ( & V_15 -> V_43 , V_42 ) ;
V_17 = F_6 ( V_15 -> V_22 + V_38 ) ;
V_17 &= ~ 1 ;
F_10 ( V_17 , V_15 -> V_22 + V_38 ) ;
F_16 ( & V_15 -> V_43 , V_42 ) ;
F_31 ( V_15 -> V_49 ) ;
F_32 ( & V_15 -> V_47 ) ;
F_33 ( V_15 -> V_79 ) ;
}
static int F_34 ( struct V_1 * V_86 )
{
struct V_14 * V_15 = F_35 ( V_86 ) ;
return F_20 ( V_15 ) ;
}
static void F_36 ( struct V_1 * V_86 )
{
struct V_14 * V_15 = F_35 ( V_86 ) ;
return F_30 ( V_15 ) ;
}
static bool T_4
F_37 ( const struct V_56 * V_57 ,
struct V_87 * V_86 , unsigned int * V_88 )
{
int V_7 ;
* V_88 = 0 ;
for ( V_7 = 0 ; V_7 < V_62 ; V_7 ++ ) {
const struct V_89 * V_73 = & V_57 -> V_73 [ V_7 ] ;
switch ( V_73 -> type ) {
case V_74 :
if ( V_73 -> V_75 >= V_60 ) {
F_38 ( V_86 ,
L_1 ,
V_7 , V_73 -> V_75 ) ;
return false ;
}
( * V_88 ) ++ ;
break;
case V_76 :
if ( V_73 -> V_75 >= V_90 ) {
F_38 ( V_86 ,
L_2 ,
V_7 , V_73 -> V_75 ) ;
return false ;
}
break;
case V_77 :
break;
default:
F_38 ( V_86 ,
L_3 ,
V_73 -> type , V_73 -> V_75 ) ;
return false ;
}
}
return true ;
}
static struct V_56 * T_4
F_39 ( struct V_91 * V_92 )
{
struct V_56 * V_57 ;
struct V_93 * V_94 = V_92 -> V_86 . V_95 ;
T_1 V_96 ;
int V_7 ;
if ( ! V_94 )
return NULL ;
V_57 = F_40 ( sizeof( * V_57 ) , V_97 ) ;
if ( ! V_57 )
return NULL ;
if ( ! F_41 ( V_94 , L_4 , & V_96 ) )
V_57 -> V_78 = V_96 ;
if ( ! F_41 ( V_94 , L_5 , & V_96 ) )
V_57 -> V_80 = V_96 ;
if ( F_42 ( V_94 , L_6 , NULL ) )
V_57 -> V_31 = true ;
if ( F_42 ( V_94 , L_7 , NULL ) )
V_57 -> V_59 = true ;
for ( V_7 = 0 ; V_7 < V_60 ; V_7 ++ ) {
V_57 -> V_73 [ V_7 ] . V_75 = V_7 ;
V_57 -> V_73 [ V_7 ] . type = V_74 ;
}
for ( V_7 = 0 ; V_7 < V_90 ; V_7 ++ ) {
V_57 -> V_73 [ V_60 + V_7 ] . V_75 = V_7 ;
V_57 -> V_73 [ V_60 + V_7 ] . type = V_76 ;
}
V_57 -> V_98 = F_43 ( V_94 , L_8 ) ;
return V_57 ;
}
static inline struct V_56 * F_39 (
struct V_91 * V_92 )
{
return NULL ;
}
static int T_4 F_44 ( struct V_91 * V_92 )
{
const struct V_56 * V_57 = V_92 -> V_86 . V_99 ;
const struct V_100 * V_98 ;
struct V_14 * V_15 ;
struct V_1 * V_1 ;
struct V_101 * V_102 ;
int V_49 ;
int V_103 ;
int V_88 = 0 ;
unsigned int V_78 ;
unsigned int V_104 ;
if ( ! V_57 )
V_57 = F_39 ( V_92 ) ;
if ( ! V_57 )
return - V_105 ;
if ( ! F_37 ( V_57 , & V_92 -> V_86 , & V_88 ) ) {
V_103 = - V_105 ;
goto V_106;
}
V_102 = F_45 ( V_92 , V_107 , 0 ) ;
if ( ! V_102 ) {
F_38 ( & V_92 -> V_86 , L_9 ) ;
V_103 = - V_108 ;
goto V_106;
}
V_49 = F_46 ( V_92 , 0 ) ;
if ( V_49 < 0 ) {
F_38 ( & V_92 -> V_86 , L_10 ) ;
V_103 = - V_108 ;
goto V_106;
}
V_15 = F_40 ( sizeof( * V_15 ) , V_97 ) ;
V_1 = F_47 () ;
if ( ! V_15 || ! V_1 ) {
V_103 = - V_109 ;
goto V_110;
}
V_15 -> V_57 = V_57 ;
V_15 -> V_35 = V_1 ;
V_15 -> V_49 = V_49 ;
F_48 ( & V_15 -> V_43 ) ;
F_49 ( & V_15 -> V_47 , F_12 , ( unsigned long ) V_15 ) ;
V_102 = F_50 ( V_102 -> V_111 , F_51 ( V_102 ) , V_92 -> V_112 ) ;
if ( ! V_102 ) {
F_38 ( & V_92 -> V_86 , L_11 ) ;
V_103 = - V_113 ;
goto V_110;
}
V_15 -> V_22 = F_52 ( V_102 -> V_111 , F_51 ( V_102 ) ) ;
if ( ! V_15 -> V_22 ) {
F_38 ( & V_92 -> V_86 , L_12 ) ;
V_103 = - V_108 ;
goto V_114;
}
V_15 -> V_79 = F_53 ( & V_92 -> V_86 , NULL ) ;
if ( F_54 ( V_15 -> V_79 ) ) {
F_38 ( & V_92 -> V_86 , L_13 ) ;
V_103 = F_55 ( V_15 -> V_79 ) ;
goto V_115;
}
V_78 = F_25 ( V_57 -> V_78 , V_82 ) ;
V_104 = ( V_116 + V_78 ) * V_88 ;
V_15 -> V_46 = V_117 + V_104 + V_57 -> V_80 ;
V_15 -> V_46 = F_56 ( V_15 -> V_46 , V_118 ) ;
V_1 -> V_112 = V_92 -> V_112 ;
V_1 -> V_119 . V_120 = V_121 ;
V_1 -> V_86 . V_122 = & V_92 -> V_86 ;
V_1 -> V_123 = F_34 ;
V_1 -> V_124 = F_36 ;
F_57 ( V_1 , V_15 ) ;
V_1 -> V_125 [ 0 ] = F_58 ( V_126 ) | F_58 ( V_127 ) ;
F_59 ( V_1 , V_12 , V_13 ) ;
V_1 -> V_28 = V_15 -> V_28 ;
V_1 -> V_128 = sizeof( V_15 -> V_28 [ 0 ] ) ;
V_1 -> V_129 = V_34 ;
if ( V_57 -> V_30 )
V_1 -> V_129 *= 2 ;
V_15 -> V_30 = V_57 -> V_30 ;
V_15 -> V_31 = V_57 -> V_31 ;
V_98 = V_57 -> V_98 ? : & V_130 ;
F_60 ( V_98 , V_27 ,
V_1 -> V_28 , V_1 -> V_131 ) ;
V_15 -> V_132 = V_57 -> V_132 ;
V_103 = F_61 ( V_15 -> V_49 , F_17 ,
V_133 | V_134 , V_92 -> V_112 , V_15 ) ;
if ( V_103 ) {
F_38 ( & V_92 -> V_86 , L_14 ) ;
goto V_135;
}
F_31 ( V_15 -> V_49 ) ;
V_103 = F_62 ( V_15 -> V_35 ) ;
if ( V_103 ) {
F_38 ( & V_92 -> V_86 , L_15 ) ;
goto V_136;
}
F_63 ( V_92 , V_15 ) ;
F_64 ( & V_92 -> V_86 , V_57 -> V_59 ) ;
if ( ! V_92 -> V_86 . V_99 )
F_65 ( V_57 -> V_98 ) ;
return 0 ;
V_136:
F_66 ( V_15 -> V_49 , V_92 ) ;
V_135:
F_67 ( V_15 -> V_79 ) ;
V_115:
F_68 ( V_15 -> V_22 ) ;
V_114:
F_69 ( V_102 -> V_111 , F_51 ( V_102 ) ) ;
V_110:
F_70 ( V_1 ) ;
F_71 ( V_15 ) ;
V_106:
if ( ! V_92 -> V_86 . V_99 ) {
F_65 ( V_57 -> V_98 ) ;
F_71 ( V_57 ) ;
}
return V_103 ;
}
static int T_5 F_72 ( struct V_91 * V_92 )
{
struct V_14 * V_15 = F_73 ( V_92 ) ;
struct V_101 * V_102 ;
F_63 ( V_92 , NULL ) ;
F_66 ( V_15 -> V_49 , V_92 ) ;
F_67 ( V_15 -> V_79 ) ;
F_74 ( V_15 -> V_35 ) ;
F_68 ( V_15 -> V_22 ) ;
V_102 = F_45 ( V_92 , V_107 , 0 ) ;
F_69 ( V_102 -> V_111 , F_51 ( V_102 ) ) ;
if ( ! V_92 -> V_86 . V_99 )
F_71 ( V_15 -> V_57 ) ;
F_71 ( V_15 ) ;
return 0 ;
}
static int F_75 ( struct V_87 * V_86 )
{
struct V_91 * V_92 = F_76 ( V_86 ) ;
struct V_14 * V_15 = F_73 ( V_92 ) ;
F_77 ( & V_15 -> V_35 -> V_137 ) ;
if ( F_78 ( & V_92 -> V_86 ) ) {
F_31 ( V_15 -> V_49 ) ;
F_32 ( & V_15 -> V_47 ) ;
F_9 ( V_15 , false ) ;
F_10 ( 0x7 , V_15 -> V_22 + V_44 ) ;
V_15 -> V_138 = F_6 ( V_15 -> V_22 + V_139 ) ;
F_10 ( 0 , V_15 -> V_22 + V_139 ) ;
F_18 ( V_15 , true ) ;
F_79 ( 30 ) ;
V_15 -> V_53 = false ;
F_11 ( V_15 , true ) ;
F_29 ( V_15 -> V_49 ) ;
F_80 ( V_15 -> V_49 ) ;
} else {
if ( V_15 -> V_35 -> V_140 )
F_30 ( V_15 ) ;
}
F_81 ( & V_15 -> V_35 -> V_137 ) ;
return 0 ;
}
static int F_82 ( struct V_87 * V_86 )
{
struct V_91 * V_92 = F_76 ( V_86 ) ;
struct V_14 * V_15 = F_73 ( V_92 ) ;
int V_103 = 0 ;
F_77 ( & V_15 -> V_35 -> V_137 ) ;
if ( F_78 ( & V_92 -> V_86 ) ) {
F_83 ( V_15 -> V_49 ) ;
F_18 ( V_15 , false ) ;
F_11 ( V_15 , false ) ;
F_10 ( V_15 -> V_138 , V_15 -> V_22 + V_139 ) ;
F_9 ( V_15 , true ) ;
if ( V_15 -> V_53 && V_15 -> V_132 ) {
F_2 ( V_15 -> V_35 , V_15 -> V_132 , 1 ) ;
F_8 ( V_15 -> V_35 ) ;
F_2 ( V_15 -> V_35 , V_15 -> V_132 , 0 ) ;
F_8 ( V_15 -> V_35 ) ;
}
} else {
if ( V_15 -> V_35 -> V_140 )
V_103 = F_20 ( V_15 ) ;
}
F_81 ( & V_15 -> V_35 -> V_137 ) ;
return V_103 ;
}
