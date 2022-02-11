static inline void F_1 ( const T_1 V_1 , T_2 V_2 )
{
F_2 ( V_2 , V_3 . V_4 + V_1 ) ;
}
static inline T_2 F_3 ( const T_1 V_1 )
{
return F_4 ( V_3 . V_4 + V_1 ) ;
}
static T_2 F_5 ( enum V_5 V_6 , enum V_7 V_8 )
{
const struct V_9 V_10 = V_11 [ V_6 ] . V_12 [ V_8 ] ;
return F_6 ( V_10 . V_13 , V_10 . V_14 , V_10 . V_15 ) ;
}
static void F_7 ( enum V_5 V_6 ,
enum V_7 V_8 , int V_2 ) {
const struct V_9 V_10 = V_11 [ V_6 ] . V_12 [ V_8 ] ;
const bool V_16 = V_10 . V_13 == V_17 || V_10 . V_13 == V_18 ;
unsigned long V_19 ;
if ( V_16 )
F_8 ( & V_3 . V_20 , V_19 ) ;
F_9 ( V_10 . V_13 , V_2 , V_10 . V_14 , V_10 . V_15 ) ;
if ( V_16 )
F_10 ( & V_3 . V_20 , V_19 ) ;
}
static void F_11 ( void )
{
int V_21 , V_22 ;
F_12 ( L_1 ) ;
F_13 ( V_23 ) ;
F_13 ( V_24 ) ;
F_13 ( V_25 ) ;
F_13 ( V_26 ) ;
if ( F_14 ( V_27 ) ||
F_14 ( V_28 ) )
F_13 ( V_29 ) ;
if ( F_14 ( V_30 ) ) {
F_13 ( V_31 ) ;
F_13 ( V_32 ) ;
}
if ( F_14 ( V_33 ) ) {
F_13 ( V_34 ) ;
F_13 ( V_35 ) ;
}
for ( V_21 = 0 ; V_21 < F_15 () ; V_21 ++ ) {
F_13 ( F_16 ( V_21 ) ) ;
F_13 ( F_17 ( V_21 ) ) ;
F_13 ( F_18 ( V_21 ) ) ;
if ( V_21 == V_36 )
continue;
F_13 ( F_19 ( V_21 ) ) ;
F_13 ( F_20 ( V_21 ) ) ;
F_13 ( F_21 ( V_21 ) ) ;
F_13 ( F_22 ( V_21 ) ) ;
F_13 ( F_23 ( V_21 ) ) ;
F_13 ( F_24 ( V_21 ) ) ;
F_13 ( F_25 ( V_21 ) ) ;
if ( F_14 ( V_37 ) ) {
F_13 ( F_26 ( V_21 ) ) ;
F_13 ( F_27 ( V_21 ) ) ;
F_13 ( F_28 ( V_21 ) ) ;
}
}
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ ) {
F_13 ( F_30 ( V_21 ) ) ;
F_13 ( F_31 ( V_21 ) ) ;
F_13 ( F_32 ( V_21 ) ) ;
F_13 ( F_33 ( V_21 ) ) ;
F_13 ( F_34 ( V_21 ) ) ;
F_13 ( F_35 ( V_21 ) ) ;
F_13 ( F_36 ( V_21 ) ) ;
F_13 ( F_37 ( V_21 ) ) ;
if ( F_14 ( V_38 ) )
F_13 ( F_38 ( V_21 ) ) ;
if ( V_21 == V_39 ) {
F_13 ( F_39 ( V_21 ) ) ;
F_13 ( F_40 ( V_21 ) ) ;
continue;
}
F_13 ( F_41 ( V_21 ) ) ;
F_13 ( F_42 ( V_21 ) ) ;
F_13 ( F_43 ( V_21 ) ) ;
F_13 ( F_44 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_45 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_46 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_13 ( F_47 ( V_21 , V_22 ) ) ;
if ( F_14 ( V_40 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_48 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_41 ) ) {
F_13 ( F_49 ( V_21 ) ) ;
F_13 ( F_50 ( V_21 ) ) ;
F_13 ( F_51 ( V_21 ) ) ;
F_13 ( F_52 ( V_21 ) ) ;
F_13 ( F_53 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_54 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_55 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_13 ( F_56 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_42 ) )
F_13 ( F_57 ( V_21 ) ) ;
}
if ( F_14 ( V_43 ) )
F_13 ( V_44 ) ;
V_3 . V_45 = true ;
F_12 ( L_2 ) ;
}
static void F_58 ( void )
{
int V_21 , V_22 ;
F_12 ( L_3 ) ;
if ( ! V_3 . V_45 )
return;
F_59 ( V_25 ) ;
F_59 ( V_26 ) ;
if ( F_14 ( V_27 ) ||
F_14 ( V_28 ) )
F_59 ( V_29 ) ;
if ( F_14 ( V_30 ) )
F_59 ( V_32 ) ;
if ( F_14 ( V_33 ) )
F_59 ( V_35 ) ;
for ( V_21 = 0 ; V_21 < F_15 () ; V_21 ++ ) {
F_59 ( F_16 ( V_21 ) ) ;
F_59 ( F_17 ( V_21 ) ) ;
F_59 ( F_18 ( V_21 ) ) ;
if ( V_21 == V_36 )
continue;
F_59 ( F_19 ( V_21 ) ) ;
F_59 ( F_20 ( V_21 ) ) ;
F_59 ( F_21 ( V_21 ) ) ;
F_59 ( F_22 ( V_21 ) ) ;
F_59 ( F_23 ( V_21 ) ) ;
F_59 ( F_24 ( V_21 ) ) ;
F_59 ( F_25 ( V_21 ) ) ;
if ( F_14 ( V_37 ) ) {
F_59 ( F_26 ( V_21 ) ) ;
F_59 ( F_27 ( V_21 ) ) ;
F_59 ( F_28 ( V_21 ) ) ;
}
}
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ ) {
F_59 ( F_30 ( V_21 ) ) ;
F_59 ( F_31 ( V_21 ) ) ;
F_59 ( F_32 ( V_21 ) ) ;
F_59 ( F_33 ( V_21 ) ) ;
F_59 ( F_34 ( V_21 ) ) ;
F_59 ( F_35 ( V_21 ) ) ;
F_59 ( F_36 ( V_21 ) ) ;
F_59 ( F_37 ( V_21 ) ) ;
if ( F_14 ( V_38 ) )
F_59 ( F_38 ( V_21 ) ) ;
if ( V_21 == V_39 ) {
F_59 ( F_39 ( V_21 ) ) ;
F_59 ( F_40 ( V_21 ) ) ;
continue;
}
F_59 ( F_41 ( V_21 ) ) ;
F_59 ( F_42 ( V_21 ) ) ;
F_59 ( F_43 ( V_21 ) ) ;
F_59 ( F_44 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_45 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_46 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_59 ( F_47 ( V_21 , V_22 ) ) ;
if ( F_14 ( V_40 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_48 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_41 ) ) {
F_59 ( F_49 ( V_21 ) ) ;
F_59 ( F_50 ( V_21 ) ) ;
F_59 ( F_51 ( V_21 ) ) ;
F_59 ( F_52 ( V_21 ) ) ;
F_59 ( F_53 ( V_21 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_54 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_55 ( V_21 , V_22 ) ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_59 ( F_56 ( V_21 , V_22 ) ) ;
}
if ( F_14 ( V_42 ) )
F_59 ( F_57 ( V_21 ) ) ;
}
if ( F_14 ( V_43 ) )
F_59 ( V_44 ) ;
F_59 ( V_24 ) ;
if ( F_14 ( V_30 ) )
F_59 ( V_31 ) ;
if ( F_14 ( V_33 ) )
F_59 ( V_34 ) ;
F_60 ( V_46 ) ;
F_59 ( V_23 ) ;
F_12 ( L_4 ) ;
}
int F_61 ( void )
{
int V_47 ;
F_12 ( L_5 ) ;
V_47 = F_62 ( & V_3 . V_48 -> V_49 ) ;
F_63 ( V_47 < 0 ) ;
return V_47 < 0 ? V_47 : 0 ;
}
void F_64 ( void )
{
int V_47 ;
F_12 ( L_6 ) ;
V_47 = F_65 ( & V_3 . V_48 -> V_49 ) ;
F_63 ( V_47 < 0 && V_47 != - V_50 ) ;
}
T_2 F_66 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_51 ;
}
T_2 F_67 ( enum V_5 V_6 )
{
if ( V_6 == V_36 && V_3 . V_52 -> V_53 )
return 0 ;
return V_11 [ V_6 ] . V_54 ;
}
T_2 F_68 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_55 ;
}
T_2 F_69 ( void )
{
return V_56 ;
}
bool F_70 ( enum V_5 V_6 )
{
return F_5 ( V_6 , V_57 ) == 1 ;
}
void F_71 ( enum V_5 V_6 )
{
F_63 ( F_72 ( V_6 ) == false ) ;
F_63 ( F_70 ( V_6 ) ) ;
F_12 ( L_7 , V_11 [ V_6 ] . V_58 ) ;
F_7 ( V_6 , V_57 , 1 ) ;
}
bool F_73 ( void )
{
return F_6 ( V_59 , 6 , 6 ) == 1 ;
}
void F_74 ( void )
{
enum V_60 V_61 = V_62 ;
bool V_63 , V_64 ;
V_63 = F_6 ( F_75 ( V_61 ) , 0 , 0 ) == 1 ;
if ( ! V_63 )
return;
V_64 = F_6 ( V_59 , 6 , 6 ) == 1 ;
if ( V_64 ) {
F_76 ( L_8 ) ;
return;
}
F_9 ( V_59 , 1 , 6 , 6 ) ;
}
static void F_77 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_1 ( F_78 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_79 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_1 ( F_80 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_81 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_1 ( F_82 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_83 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_84 ( V_61 == V_39 ) ;
F_1 ( F_85 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_86 ( enum V_60 V_61 , int V_13 ,
T_2 V_65 )
{
F_84 ( V_61 == V_39 ) ;
F_1 ( F_87 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_88 ( enum V_60 V_61 , int V_13 , T_2 V_65 )
{
F_84 ( V_61 == V_39 ) ;
F_1 ( F_89 ( V_61 , V_13 ) , V_65 ) ;
}
static void F_90 ( enum V_60 V_61 , int V_66 ,
int V_67 , int V_68 ,
enum V_69 V_70 )
{
const struct V_71 * V_72 , * V_73 ;
int V_21 ;
V_72 = F_91 ( V_66 , true ) ;
V_73 = F_91 ( V_67 , V_68 ) ;
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
T_2 V_74 , V_75 ;
V_74 = F_92 ( V_72 [ V_21 ] . V_76 , 7 , 0 )
| F_92 ( V_72 [ V_21 ] . V_77 , 15 , 8 )
| F_92 ( V_72 [ V_21 ] . V_78 , 23 , 16 )
| F_92 ( V_72 [ V_21 ] . V_79 , 31 , 24 ) ;
V_75 = F_92 ( V_72 [ V_21 ] . V_80 , 7 , 0 )
| F_92 ( V_73 [ V_21 ] . V_77 , 15 , 8 )
| F_92 ( V_73 [ V_21 ] . V_78 , 23 , 16 )
| F_92 ( V_73 [ V_21 ] . V_79 , 31 , 24 ) ;
if ( V_70 == V_81 ) {
F_77 ( V_61 , V_21 , V_74 ) ;
F_79 ( V_61 , V_21 , V_75 ) ;
} else {
F_83 ( V_61 , V_21 , V_74 ) ;
F_86 ( V_61 , V_21 , V_75 ) ;
}
}
if ( V_68 ) {
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ ) {
T_2 V_82 ;
V_82 = F_92 ( V_73 [ V_21 ] . V_76 , 7 , 0 )
| F_92 ( V_73 [ V_21 ] . V_80 , 15 , 8 ) ;
if ( V_70 == V_81 )
F_81 ( V_61 , V_21 , V_82 ) ;
else
F_88 ( V_61 , V_21 , V_82 ) ;
}
}
}
static void F_93 ( enum V_60 V_61 ,
const struct V_83 * V_84 )
{
#define F_94 ( T_3 , T_4 ) (FLD_VAL(x, 26, 16) | FLD_VAL(y, 10, 0))
F_1 ( F_95 ( V_61 , 0 ) , F_94 ( V_84 -> V_85 , V_84 -> V_86 ) ) ;
F_1 ( F_95 ( V_61 , 1 ) , F_94 ( V_84 -> V_87 , V_84 -> V_88 ) ) ;
F_1 ( F_95 ( V_61 , 2 ) , F_94 ( V_84 -> V_89 , V_84 -> V_90 ) ) ;
F_1 ( F_95 ( V_61 , 3 ) , F_94 ( V_84 -> V_91 , V_84 -> V_92 ) ) ;
F_1 ( F_95 ( V_61 , 4 ) , F_94 ( 0 , V_84 -> V_93 ) ) ;
F_9 ( F_75 ( V_61 ) , V_84 -> V_94 , 11 , 11 ) ;
#undef F_94
}
static void F_96 ( void )
{
int V_21 ;
int V_95 = F_29 () ;
int V_96 = F_97 () ;
const struct V_83 V_97 = {
298 , 409 , 0 , 298 , - 208 , - 100 , 298 , 0 , 517 , 0 ,
} ;
const struct V_83 V_98 = {
66 , 112 , - 38 , 129 , - 94 , - 74 , 25 , - 18 , 112 , 0 ,
} ;
for ( V_21 = 1 ; V_21 < V_95 ; V_21 ++ )
F_93 ( V_21 , & V_97 ) ;
for (; V_21 < V_96 ; V_21 ++ )
F_93 ( V_21 , & V_98 ) ;
}
static void F_98 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_99 ( V_61 ) , V_99 ) ;
}
static void F_100 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_101 ( V_61 ) , V_99 ) ;
}
static void F_102 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_103 ( V_61 ) , V_99 ) ;
}
static void F_104 ( enum V_60 V_61 , T_2 V_99 )
{
F_1 ( F_105 ( V_61 ) , V_99 ) ;
}
static void F_106 ( enum V_60 V_61 ,
enum V_100 V_101 , int T_3 , int T_4 )
{
T_2 V_2 ;
if ( ( V_101 & V_102 ) == 0 )
return;
V_2 = F_92 ( T_4 , 26 , 16 ) | F_92 ( T_3 , 10 , 0 ) ;
F_1 ( F_107 ( V_61 ) , V_2 ) ;
}
static void F_108 ( enum V_60 V_61 , int V_103 ,
int V_104 )
{
T_2 V_2 = F_92 ( V_104 - 1 , 26 , 16 ) | F_92 ( V_103 - 1 , 10 , 0 ) ;
if ( V_61 == V_39 || V_61 == V_62 )
F_1 ( F_109 ( V_61 ) , V_2 ) ;
else
F_1 ( F_110 ( V_61 ) , V_2 ) ;
}
static void F_111 ( enum V_60 V_61 , int V_103 ,
int V_104 )
{
T_2 V_2 ;
F_84 ( V_61 == V_39 ) ;
V_2 = F_92 ( V_104 - 1 , 26 , 16 ) | F_92 ( V_103 - 1 , 10 , 0 ) ;
if ( V_61 == V_62 )
F_1 ( F_110 ( V_61 ) , V_2 ) ;
else
F_1 ( F_109 ( V_61 ) , V_2 ) ;
}
static void F_112 ( enum V_60 V_61 ,
enum V_100 V_101 , T_5 V_105 )
{
if ( ( V_101 & V_106 ) == 0 )
return;
F_9 ( F_75 ( V_61 ) , V_105 , 27 , 26 ) ;
}
static void F_113 ( void )
{
int V_21 ;
if ( ! F_14 ( V_28 ) )
return;
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ )
F_9 ( F_75 ( V_21 ) , 1 , 25 , 25 ) ;
}
static void F_114 ( enum V_60 V_61 ,
enum V_100 V_101 , bool V_63 )
{
if ( ( V_101 & V_107 ) == 0 )
return;
F_9 ( F_75 ( V_61 ) , V_63 ? 1 : 0 , 28 , 28 ) ;
}
static void F_115 ( enum V_60 V_61 ,
enum V_100 V_101 , T_5 V_108 )
{
static const unsigned V_109 [] = { 0 , 8 , 16 , 24 , } ;
int V_110 ;
if ( ( V_101 & V_111 ) == 0 )
return;
V_110 = V_109 [ V_61 ] ;
F_9 ( V_112 , V_108 , V_110 + 7 , V_110 ) ;
}
static void F_116 ( enum V_60 V_61 , T_6 V_113 )
{
F_1 ( F_117 ( V_61 ) , V_113 ) ;
}
static void F_118 ( enum V_60 V_61 , T_6 V_113 )
{
F_1 ( F_119 ( V_61 ) , V_113 ) ;
}
static void F_120 ( enum V_60 V_61 ,
enum V_114 V_115 )
{
T_2 V_116 = 0 ;
if ( V_61 != V_39 ) {
switch ( V_115 ) {
case V_117 :
V_116 = 0x0 ; break;
case V_118 :
V_116 = 0x1 ; break;
case V_119 :
V_116 = 0x2 ; break;
case V_120 :
V_116 = 0x4 ; break;
case V_121 :
V_116 = 0x5 ; break;
case V_122 :
V_116 = 0x6 ; break;
case V_123 :
V_116 = 0x7 ; break;
case V_124 :
V_116 = 0x8 ; break;
case V_125 :
V_116 = 0x9 ; break;
case V_126 :
V_116 = 0xa ; break;
case V_127 :
V_116 = 0xb ; break;
case V_128 :
V_116 = 0xc ; break;
case V_129 :
V_116 = 0xd ; break;
case V_130 :
V_116 = 0xe ; break;
case V_131 :
V_116 = 0xf ; break;
default:
F_121 () ; return;
}
} else {
switch ( V_115 ) {
case V_132 :
V_116 = 0x0 ; break;
case V_133 :
V_116 = 0x1 ; break;
case V_134 :
V_116 = 0x2 ; break;
case V_135 :
V_116 = 0x3 ; break;
case V_120 :
V_116 = 0x4 ; break;
case V_121 :
V_116 = 0x5 ; break;
case V_122 :
V_116 = 0x6 ; break;
case V_123 :
V_116 = 0x7 ; break;
case V_124 :
V_116 = 0x8 ; break;
case V_125 :
V_116 = 0x9 ; break;
case V_118 :
V_116 = 0xa ; break;
case V_119 :
V_116 = 0xb ; break;
case V_128 :
V_116 = 0xc ; break;
case V_129 :
V_116 = 0xd ; break;
case V_130 :
V_116 = 0xe ; break;
case V_131 :
V_116 = 0xf ; break;
default:
F_121 () ; return;
}
}
F_9 ( F_75 ( V_61 ) , V_116 , 4 , 1 ) ;
}
static void F_122 ( enum V_60 V_61 ,
enum V_136 V_137 )
{
if ( F_14 ( V_138 ) == 0 )
return;
if ( V_137 == V_139 )
F_9 ( F_75 ( V_61 ) , 1 , 29 , 29 ) ;
else
F_9 ( F_75 ( V_61 ) , 0 , 29 , 29 ) ;
}
void F_123 ( enum V_60 V_61 , enum V_5 V_6 )
{
int V_110 ;
T_2 V_2 ;
int V_140 = 0 , V_141 = 0 ;
switch ( V_61 ) {
case V_39 :
V_110 = 8 ;
break;
case V_142 :
case V_143 :
case V_144 :
V_110 = 16 ;
break;
default:
F_121 () ;
return;
}
V_2 = F_3 ( F_75 ( V_61 ) ) ;
if ( F_14 ( V_30 ) ) {
switch ( V_6 ) {
case V_145 :
V_140 = 0 ;
V_141 = 0 ;
break;
case V_36 :
V_140 = 1 ;
V_141 = 0 ;
break;
case V_146 :
V_140 = 0 ;
V_141 = 1 ;
break;
case V_147 :
if ( F_14 ( V_33 ) ) {
V_140 = 0 ;
V_141 = 2 ;
} else {
F_121 () ;
return;
}
break;
default:
F_121 () ;
return;
}
V_2 = F_124 ( V_2 , V_140 , V_110 , V_110 ) ;
V_2 = F_124 ( V_2 , V_141 , 31 , 30 ) ;
} else {
V_2 = F_124 ( V_2 , V_6 , V_110 , V_110 ) ;
}
F_1 ( F_75 ( V_61 ) , V_2 ) ;
}
static enum V_5 F_125 ( enum V_60 V_61 )
{
int V_110 ;
T_2 V_2 ;
enum V_5 V_6 ;
switch ( V_61 ) {
case V_39 :
V_110 = 8 ;
break;
case V_142 :
case V_143 :
case V_144 :
V_110 = 16 ;
break;
default:
F_121 () ;
return 0 ;
}
V_2 = F_3 ( F_75 ( V_61 ) ) ;
if ( F_14 ( V_33 ) ) {
if ( F_126 ( V_2 , 31 , 30 ) == 0 )
V_6 = F_126 ( V_2 , V_110 , V_110 ) ;
else if ( F_126 ( V_2 , 31 , 30 ) == 1 )
V_6 = V_146 ;
else
V_6 = V_147 ;
} else if ( F_14 ( V_30 ) ) {
if ( F_126 ( V_2 , 31 , 30 ) == 0 )
V_6 = F_126 ( V_2 , V_110 , V_110 ) ;
else
V_6 = V_146 ;
} else {
V_6 = F_126 ( V_2 , V_110 , V_110 ) ;
}
return V_6 ;
}
void F_127 ( enum V_148 V_6 )
{
enum V_60 V_61 = V_62 ;
F_9 ( F_75 ( V_61 ) , V_6 , 18 , 16 ) ;
}
static void F_128 ( enum V_60 V_61 ,
enum V_149 V_150 )
{
static const unsigned V_109 [] = { 6 , 14 , 14 , 14 , 14 , } ;
int V_110 ;
V_110 = V_109 [ V_61 ] ;
F_9 ( F_75 ( V_61 ) , V_150 , V_110 + 1 , V_110 ) ;
}
static void F_129 ( void )
{
int V_21 ;
const int V_150 = V_151 ;
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 )
F_128 ( V_21 , V_150 ) ;
}
static T_2 F_130 ( enum V_60 V_61 )
{
unsigned V_152 = F_131 () ;
return V_152 * 8 ;
}
void F_132 ( bool V_63 )
{
if ( V_63 ) {
F_133 ( L_9 ) ;
return;
}
F_9 ( V_18 , V_63 , 9 , 9 ) ;
}
static void F_134 ( enum V_5 V_6 , bool V_63 )
{
if ( V_6 == V_36 )
return;
F_7 ( V_6 , V_153 , V_63 ) ;
}
static void F_135 ( enum V_5 V_6 ,
const struct V_154 * V_155 )
{
T_2 V_156 , V_157 , V_158 ;
if ( ! F_136 ( V_6 ) )
return;
V_156 = F_92 ( V_155 -> V_159 , 31 , 22 ) | F_92 ( V_155 -> V_160 , 20 , 11 ) |
F_92 ( V_155 -> V_161 , 9 , 0 ) ;
V_157 = F_92 ( V_155 -> V_162 , 31 , 22 ) | F_92 ( V_155 -> V_163 , 20 , 11 ) |
F_92 ( V_155 -> V_164 , 9 , 0 ) ;
V_158 = F_92 ( V_155 -> V_165 , 31 , 22 ) | F_92 ( V_155 -> V_166 , 20 , 11 ) |
F_92 ( V_155 -> V_167 , 9 , 0 ) ;
F_1 ( F_137 ( V_6 ) , V_156 ) ;
F_1 ( F_138 ( V_6 ) , V_157 ) ;
F_1 ( F_139 ( V_6 ) , V_158 ) ;
}
static void F_140 ( enum V_60 V_61 , bool V_63 )
{
T_2 V_2 ;
F_84 ( V_61 == V_39 ) ;
V_2 = F_3 ( F_75 ( V_61 ) ) ;
V_2 = F_124 ( V_2 , V_63 , 9 , 9 ) ;
F_1 ( F_75 ( V_61 ) , V_2 ) ;
}
static void F_141 ( enum V_60 V_61 ,
enum V_100 V_101 , bool V_63 )
{
static const unsigned V_109 [] = { 5 , 10 , 10 , 10 } ;
int V_110 ;
if ( ( V_101 & V_168 ) == 0 )
return;
V_110 = V_109 [ V_61 ] ;
F_9 ( F_75 ( V_61 ) , V_63 , V_110 , V_110 ) ;
}
static void F_142 ( enum V_5 V_6 , T_1 V_103 ,
T_1 V_104 )
{
T_2 V_2 ;
V_2 = F_92 ( V_104 - 1 , V_3 . V_52 -> V_169 , 16 ) |
F_92 ( V_103 - 1 , V_3 . V_52 -> V_170 , 0 ) ;
F_1 ( F_143 ( V_6 ) , V_2 ) ;
}
static void F_144 ( void )
{
T_2 V_171 ;
int V_172 ;
T_5 V_173 , V_174 ;
T_2 V_152 ;
int V_21 ;
V_152 = F_145 () ;
F_146 ( V_175 , & V_173 , & V_174 ) ;
for ( V_172 = 0 ; V_172 < V_3 . V_52 -> V_176 ; ++ V_172 ) {
V_171 = F_6 ( F_147 ( V_172 ) , V_173 , V_174 ) ;
V_171 *= V_152 ;
V_3 . V_177 [ V_172 ] = V_171 ;
V_3 . V_178 [ V_172 ] = V_172 ;
}
if ( V_3 . V_52 -> V_179 ) {
T_2 V_82 ;
V_82 = F_3 ( V_180 ) ;
V_82 = F_124 ( V_82 , 4 , 2 , 0 ) ;
V_82 = F_124 ( V_82 , 4 , 5 , 3 ) ;
V_82 = F_124 ( V_82 , 0 , 26 , 24 ) ;
V_82 = F_124 ( V_82 , 0 , 29 , 27 ) ;
F_1 ( V_180 , V_82 ) ;
V_3 . V_178 [ V_39 ] = V_62 ;
V_3 . V_178 [ V_62 ] = V_39 ;
}
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 ) {
T_2 V_15 , V_14 ;
const bool V_181 = false ;
const bool V_182 = false ;
F_148 ( V_21 , & V_15 , & V_14 ,
V_181 , V_182 ) ;
F_149 ( V_21 , V_15 , V_14 ) ;
}
}
static T_2 F_150 ( enum V_60 V_61 )
{
int V_172 ;
T_2 V_171 = 0 ;
for ( V_172 = 0 ; V_172 < V_3 . V_52 -> V_176 ; ++ V_172 ) {
if ( V_3 . V_178 [ V_172 ] == V_61 )
V_171 += V_3 . V_177 [ V_172 ] ;
}
return V_171 ;
}
void F_149 ( enum V_60 V_61 , T_2 V_15 , T_2 V_14 )
{
T_5 V_183 , V_184 , V_185 , V_186 ;
T_2 V_152 ;
V_152 = F_145 () ;
F_63 ( V_15 % V_152 != 0 ) ;
F_63 ( V_14 % V_152 != 0 ) ;
V_15 /= V_152 ;
V_14 /= V_152 ;
F_146 ( V_187 , & V_183 , & V_184 ) ;
F_146 ( V_188 , & V_185 , & V_186 ) ;
F_12 ( L_10 ,
V_61 ,
F_6 ( F_151 ( V_61 ) ,
V_185 , V_186 ) * V_152 ,
F_6 ( F_151 ( V_61 ) ,
V_183 , V_184 ) * V_152 ,
V_15 * V_152 , V_14 * V_152 ) ;
F_1 ( F_151 ( V_61 ) ,
F_92 ( V_14 , V_183 , V_184 ) |
F_92 ( V_15 , V_185 , V_186 ) ) ;
if ( F_14 ( V_38 ) && V_3 . V_52 -> V_189 &&
V_61 != V_62 )
F_1 ( F_152 ( V_61 ) , F_153 ( V_14 , 0xfffu ) ) ;
}
void F_154 ( bool V_63 )
{
if ( ! F_14 ( V_190 ) ) {
F_63 ( V_63 ) ;
return;
}
F_12 ( L_11 , V_63 ? L_12 : L_13 ) ;
F_9 ( V_18 , V_63 ? 1 : 0 , 14 , 14 ) ;
}
void F_148 ( enum V_60 V_61 ,
T_2 * V_191 , T_2 * V_192 , bool V_181 ,
bool V_182 )
{
unsigned V_193 = F_145 () ;
unsigned V_194 , V_195 , V_150 ;
int V_21 ;
V_150 = F_130 ( V_61 ) ;
V_194 = F_150 ( V_61 ) ;
if ( V_181 ) {
V_195 = 0 ;
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 )
V_195 += F_150 ( V_21 ) ;
} else {
V_195 = V_194 ;
}
if ( V_182 && F_14 ( V_196 ) ) {
* V_191 = V_194 - V_150 * 2 ;
* V_192 = V_195 - V_150 ;
} else if ( V_61 == V_62 ) {
* V_191 = 0 ;
* V_192 = V_150 ;
} else {
* V_191 = V_194 - V_150 ;
* V_192 = V_195 - V_193 ;
}
}
static void F_155 ( enum V_60 V_61 , bool V_63 )
{
int V_197 ;
if ( V_61 == V_39 )
V_197 = 14 ;
else
V_197 = 23 ;
F_9 ( F_75 ( V_61 ) , V_63 , V_197 , V_197 ) ;
}
static void F_156 ( enum V_60 V_61 ,
int V_15 , int V_14 )
{
F_1 ( F_157 ( V_61 ) ,
F_92 ( V_14 , 31 , 16 ) | F_92 ( V_15 , 15 , 0 ) ) ;
}
static void F_158 ( void )
{
int V_21 ;
F_1 ( V_198 ,
( 1 << 0 ) |
( 0 << 2 ) ) ;
for ( V_21 = 0 ; V_21 < F_29 () ; ++ V_21 ) {
T_2 V_171 = F_150 ( V_21 ) ;
T_2 V_152 = F_145 () ;
T_2 V_15 , V_14 ;
F_155 ( V_21 , true ) ;
V_15 = V_171 * 4 / 8 / V_152 ;
V_14 = V_171 * 5 / 8 / V_152 ;
F_156 ( V_21 , V_15 , V_14 ) ;
}
}
static void F_159 ( enum V_60 V_61 ,
int V_199 , int V_200 ,
enum V_69 V_70 )
{
T_2 V_2 ;
if ( V_70 == V_81 ) {
T_5 V_201 , V_202 , V_203 , V_204 ;
F_146 ( V_205 ,
& V_201 , & V_202 ) ;
F_146 ( V_206 ,
& V_203 , & V_204 ) ;
V_2 = F_92 ( V_200 , V_203 , V_204 ) |
F_92 ( V_199 , V_201 , V_202 ) ;
F_1 ( F_160 ( V_61 ) , V_2 ) ;
} else {
V_2 = F_92 ( V_200 , 28 , 16 ) | F_92 ( V_199 , 12 , 0 ) ;
F_1 ( F_161 ( V_61 ) , V_2 ) ;
}
}
static void F_162 ( enum V_60 V_61 , int V_207 , int V_208 )
{
T_2 V_2 ;
T_5 V_209 , V_210 , V_211 , V_212 ;
F_146 ( V_213 , & V_209 , & V_210 ) ;
F_146 ( V_214 , & V_211 , & V_212 ) ;
V_2 = F_92 ( V_208 , V_211 , V_212 ) |
F_92 ( V_207 , V_209 , V_210 ) ;
F_1 ( F_163 ( V_61 ) , V_2 ) ;
}
static void F_164 ( enum V_60 V_61 , int V_207 , int V_208 )
{
T_2 V_2 ;
T_5 V_209 , V_210 , V_211 , V_212 ;
F_146 ( V_213 , & V_209 , & V_210 ) ;
F_146 ( V_214 , & V_211 , & V_212 ) ;
V_2 = F_92 ( V_208 , V_211 , V_212 ) |
F_92 ( V_207 , V_209 , V_210 ) ;
F_1 ( F_165 ( V_61 ) , V_2 ) ;
}
static void F_166 ( enum V_60 V_61 , int V_207 ,
int V_208 )
{
T_2 V_2 ;
V_2 = F_92 ( V_208 , 26 , 16 ) | F_92 ( V_207 , 10 , 0 ) ;
F_1 ( F_167 ( V_61 ) , V_2 ) ;
}
static void F_168 ( enum V_60 V_61 , int V_207 ,
int V_208 )
{
T_2 V_2 ;
V_2 = F_92 ( V_208 , 26 , 16 ) | F_92 ( V_207 , 10 , 0 ) ;
F_1 ( F_169 ( V_61 ) , V_2 ) ;
}
static void F_170 ( enum V_60 V_61 ,
T_1 V_215 , T_1 V_216 ,
T_1 V_217 , T_1 V_218 ,
bool V_68 , T_5 V_219 ,
enum V_69 V_70 )
{
int V_66 , V_67 ;
V_66 = 1024 * V_215 / V_217 ;
V_67 = 1024 * V_216 / V_218 ;
F_90 ( V_61 , V_66 , V_67 , V_68 ,
V_70 ) ;
F_159 ( V_61 , V_66 , V_67 , V_70 ) ;
}
static void F_171 ( enum V_60 V_61 ,
T_1 V_215 , T_1 V_216 , T_1 V_217 , T_1 V_218 ,
bool V_220 , enum V_114 V_115 , T_5 V_219 )
{
int V_221 , V_222 ;
int V_223 , V_224 ;
int V_225 , V_226 ;
int V_1 ;
struct V_227 {
T_7 V_228 , V_229 ;
T_7 V_230 , V_231 ;
T_7 V_232 , V_233 ;
T_7 V_234 , V_235 ;
};
const struct V_227 * V_236 ;
const struct V_227 * V_237 ;
static const struct V_227 V_238 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ 1 , 2 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ - 1 , 2 , - 1 , 2 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_227 V_239 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 3 , 4 , - 1 , 4 } ,
{ - 1 , 4 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 4 , - 3 , 4 } ,
{ - 3 , 4 , - 3 , 4 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_227 V_240 [ 4 ] = {
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , - 1 , 1 , 0 , 1 } ,
} ;
switch ( V_219 ) {
case V_241 :
V_1 = 0 ;
break;
case V_242 :
V_1 = 1 ;
break;
case V_243 :
V_1 = 2 ;
break;
case V_244 :
V_1 = 3 ;
break;
default:
F_121 () ;
return;
}
switch ( V_115 ) {
case V_117 :
if ( V_220 )
V_236 = V_239 ;
else
V_236 = V_238 ;
break;
case V_126 :
case V_127 :
V_236 = V_240 ;
break;
default:
F_121 () ;
return;
}
V_237 = & V_236 [ V_1 ] ;
V_225 = 1024 * V_215 / V_217 ;
V_226 = 1024 * V_216 / V_218 ;
V_221 = ( V_237 -> V_228 * V_225 / V_237 -> V_229 ) % 1024 ;
V_222 = ( V_237 -> V_230 * V_225 / V_237 -> V_231 ) % 1024 ;
V_223 = ( V_237 -> V_232 * V_226 / V_237 -> V_233 ) % 1024 ;
V_224 = ( V_237 -> V_234 * V_226 / V_237 -> V_235 ) % 1024 ;
F_166 ( V_61 , V_221 , V_223 ) ;
F_168 ( V_61 , V_222 , V_224 ) ;
}
static void F_172 ( enum V_60 V_61 ,
T_1 V_215 , T_1 V_216 ,
T_1 V_217 , T_1 V_218 ,
bool V_220 , bool V_68 ,
bool V_245 , enum V_114 V_115 ,
T_5 V_219 )
{
int V_246 = 0 ;
int V_247 = 0 ;
T_2 V_248 ;
F_170 ( V_61 , V_215 , V_216 ,
V_217 , V_218 , V_68 ,
V_219 , V_81 ) ;
V_248 = F_3 ( F_75 ( V_61 ) ) ;
V_248 &= ~ ( ( 0x3 << 5 ) | ( 0x1 << 21 ) ) ;
V_248 |= ( V_215 != V_217 ) ? ( 1 << 5 ) : 0 ;
V_248 |= ( V_216 != V_218 ) ? ( 1 << 6 ) : 0 ;
V_248 |= V_68 ? ( 1 << 21 ) : 0 ;
if ( F_14 ( V_249 ) ) {
V_248 &= ~ ( 0x3 << 7 ) ;
V_248 |= ( V_215 <= V_217 ) ? 0 : ( 1 << 7 ) ;
V_248 |= ( V_216 <= V_218 ) ? 0 : ( 1 << 8 ) ;
}
if ( F_14 ( V_250 ) ) {
V_248 &= ~ ( 0x1 << 22 ) ;
V_248 |= V_68 ? ( 1 << 22 ) : 0 ;
}
F_1 ( F_75 ( V_61 ) , V_248 ) ;
if ( V_220 && ! V_245 ) {
V_247 = 0 ;
V_246 = ( ( 1024 * V_216 / V_218 ) / 2 ) & 0x3ff ;
if ( V_246 >= 1024 / 2 ) {
V_247 = 1024 / 2 ;
V_246 -= V_247 ;
}
}
F_162 ( V_61 , 0 , V_246 ) ;
F_164 ( V_61 , 0 , V_247 ) ;
}
static void F_173 ( enum V_60 V_61 ,
T_1 V_215 , T_1 V_216 ,
T_1 V_217 , T_1 V_218 ,
bool V_220 , bool V_68 ,
bool V_245 , enum V_114 V_115 ,
T_5 V_219 )
{
int V_251 = V_217 != V_215 ;
int V_252 = V_218 != V_216 ;
bool V_253 = V_61 != V_62 ? true : false ;
if ( ! F_14 ( V_41 ) )
return;
if ( ( V_115 != V_126 &&
V_115 != V_127 &&
V_115 != V_117 ) ) {
if ( V_61 != V_62 )
F_9 ( F_174 ( V_61 ) , 0 , 8 , 8 ) ;
return;
}
F_171 ( V_61 , V_215 , V_216 , V_217 ,
V_218 , V_220 , V_115 , V_219 ) ;
switch ( V_115 ) {
case V_117 :
if ( V_253 ) {
V_216 >>= 1 ;
V_215 >>= 1 ;
} else {
V_216 <<= 1 ;
V_215 <<= 1 ;
}
break;
case V_126 :
case V_127 :
if ( V_219 == V_241 ||
V_219 == V_243 ) {
if ( V_253 )
V_215 >>= 1 ;
else
V_215 <<= 1 ;
}
if ( V_219 != V_241 )
V_251 = V_252 = true ;
break;
default:
F_121 () ;
return;
}
if ( V_217 != V_215 )
V_251 = true ;
if ( V_218 != V_216 )
V_252 = true ;
F_170 ( V_61 , V_215 , V_216 ,
V_217 , V_218 , V_68 ,
V_219 , V_254 ) ;
if ( V_61 != V_62 )
F_9 ( F_174 ( V_61 ) ,
( V_251 || V_252 ) ? 1 : 0 , 8 , 8 ) ;
F_9 ( F_75 ( V_61 ) , V_251 ? 1 : 0 , 5 , 5 ) ;
F_9 ( F_75 ( V_61 ) , V_252 ? 1 : 0 , 6 , 6 ) ;
}
static void F_175 ( enum V_60 V_61 ,
T_1 V_215 , T_1 V_216 ,
T_1 V_217 , T_1 V_218 ,
bool V_220 , bool V_68 ,
bool V_245 , enum V_114 V_115 ,
T_5 V_219 )
{
F_84 ( V_61 == V_39 ) ;
F_172 ( V_61 ,
V_215 , V_216 ,
V_217 , V_218 ,
V_220 , V_68 ,
V_245 , V_115 ,
V_219 ) ;
F_173 ( V_61 ,
V_215 , V_216 ,
V_217 , V_218 ,
V_220 , V_68 ,
V_245 , V_115 ,
V_219 ) ;
}
static void F_176 ( enum V_60 V_61 , T_5 V_219 ,
enum V_136 V_137 ,
bool V_255 , enum V_114 V_115 )
{
bool V_256 = false ;
int V_257 = 0 ;
if ( V_115 == V_126 ||
V_115 == V_127 ) {
if ( V_255 ) {
switch ( V_219 ) {
case V_241 :
V_257 = 2 ;
break;
case V_242 :
V_257 = 1 ;
break;
case V_243 :
V_257 = 0 ;
break;
case V_244 :
V_257 = 3 ;
break;
}
} else {
switch ( V_219 ) {
case V_241 :
V_257 = 0 ;
break;
case V_242 :
V_257 = 1 ;
break;
case V_243 :
V_257 = 2 ;
break;
case V_244 :
V_257 = 3 ;
break;
}
}
if ( V_219 == V_242 || V_219 == V_244 )
V_256 = true ;
else
V_256 = false ;
}
if ( V_115 == V_117 &&
V_137 != V_139 )
V_257 = 1 ;
F_9 ( F_75 ( V_61 ) , V_257 , 13 , 12 ) ;
if ( F_14 ( V_258 ) )
F_9 ( F_75 ( V_61 ) ,
V_256 ? 1 : 0 , 18 , 18 ) ;
if ( V_115 == V_117 ) {
bool V_259 = ( V_137 == V_139 ) &&
( V_219 == V_241 ||
V_219 == V_243 ) ;
F_9 ( F_75 ( V_61 ) , V_259 , 22 , 22 ) ;
}
}
static int F_177 ( enum V_114 V_115 )
{
switch ( V_115 ) {
case V_132 :
return 1 ;
case V_133 :
return 2 ;
case V_134 :
return 4 ;
case V_135 :
case V_117 :
return 8 ;
case V_120 :
case V_122 :
case V_121 :
case V_126 :
case V_127 :
case V_119 :
case V_118 :
case V_123 :
case V_131 :
return 16 ;
case V_125 :
return 24 ;
case V_124 :
case V_128 :
case V_129 :
case V_130 :
return 32 ;
default:
F_121 () ;
return 0 ;
}
}
static T_6 F_178 ( int V_260 , T_5 V_261 )
{
if ( V_260 == 1 )
return 1 ;
else if ( V_260 > 1 )
return 1 + ( V_260 - 1 ) * V_261 ;
else if ( V_260 < 0 )
return 1 - ( - V_260 + 1 ) * V_261 ;
else
F_121 () ;
return 0 ;
}
static void F_179 ( T_5 V_219 , bool V_262 ,
T_1 V_263 ,
T_1 V_103 , T_1 V_104 ,
enum V_114 V_115 , bool V_245 ,
unsigned int V_264 ,
unsigned * V_265 , unsigned * V_266 ,
T_6 * V_267 , T_6 * V_268 , int V_269 , int V_270 )
{
T_5 V_261 ;
switch ( V_115 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
F_121 () ;
return;
case V_126 :
case V_127 :
V_261 = 4 ;
break;
default:
V_261 = F_177 ( V_115 ) / 8 ;
break;
}
F_12 ( L_14 , V_219 , V_263 ,
V_103 , V_104 ) ;
switch ( V_219 + V_262 * 4 ) {
case V_241 :
case V_243 :
if ( V_115 == V_126 ||
V_115 == V_127 )
V_103 = V_103 >> 1 ;
case V_242 :
case V_244 :
* V_266 = 0 ;
if ( V_264 )
* V_265 = V_264 * V_263 * V_261 ;
else
* V_265 = 0 ;
* V_267 = F_178 ( 1 +
( V_270 * V_263 - V_269 * V_103 ) +
( V_245 ? V_263 : 0 ) , V_261 ) ;
* V_268 = F_178 ( V_269 , V_261 ) ;
break;
case V_241 + 4 :
case V_243 + 4 :
if ( V_115 == V_126 ||
V_115 == V_127 )
V_103 = V_103 >> 1 ;
case V_242 + 4 :
case V_244 + 4 :
* V_266 = 0 ;
if ( V_264 )
* V_265 = V_264 * V_263 * V_261 ;
else
* V_265 = 0 ;
* V_267 = F_178 ( 1 -
( V_270 * V_263 + V_269 * V_103 ) -
( V_245 ? V_263 : 0 ) , V_261 ) ;
* V_268 = F_178 ( V_269 , V_261 ) ;
break;
default:
F_121 () ;
return;
}
}
static void F_180 ( T_5 V_219 , bool V_262 ,
T_1 V_263 ,
T_1 V_103 , T_1 V_104 ,
enum V_114 V_115 , bool V_245 ,
unsigned int V_264 ,
unsigned * V_265 , unsigned * V_266 ,
T_6 * V_267 , T_6 * V_268 , int V_269 , int V_270 )
{
T_5 V_261 ;
T_1 V_271 , V_272 ;
switch ( V_115 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
F_121 () ;
return;
default:
V_261 = F_177 ( V_115 ) / 8 ;
break;
}
F_12 ( L_14 , V_219 , V_263 ,
V_103 , V_104 ) ;
if ( V_219 == V_241 || V_219 == V_243 ) {
V_271 = V_103 ;
V_272 = V_104 ;
} else {
V_271 = V_104 ;
V_272 = V_103 ;
}
switch ( V_219 + V_262 * 4 ) {
case V_241 :
* V_266 = 0 ;
if ( V_264 )
* V_265 = * V_266 + V_264 * V_263 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( 1 +
( V_270 * V_263 - V_271 * V_269 ) +
( V_245 ? V_263 : 0 ) , V_261 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_268 = F_178 ( V_269 , 2 * V_261 ) ;
else
* V_268 = F_178 ( V_269 , V_261 ) ;
break;
case V_242 :
* V_266 = V_263 * ( V_272 - 1 ) * V_261 ;
if ( V_264 )
* V_265 = * V_266 + V_264 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( V_263 * ( V_272 * V_269 - 1 ) +
V_270 + ( V_245 ? 1 : 0 ) , V_261 ) ;
* V_268 = F_178 ( - V_269 * V_263 , V_261 ) ;
break;
case V_243 :
* V_266 = ( V_263 * ( V_272 - 1 ) + V_271 - 1 ) * V_261 ;
if ( V_264 )
* V_265 = * V_266 - V_264 * V_263 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( - 1 -
( V_270 * V_263 - V_271 * V_269 ) -
( V_245 ? V_263 : 0 ) , V_261 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_268 = F_178 ( - V_269 , 2 * V_261 ) ;
else
* V_268 = F_178 ( - V_269 , V_261 ) ;
break;
case V_244 :
* V_266 = ( V_271 - 1 ) * V_261 ;
if ( V_264 )
* V_265 = * V_266 - V_264 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( - V_263 * ( V_272 * V_269 - 1 ) -
V_270 - ( V_245 ? 1 : 0 ) , V_261 ) ;
* V_268 = F_178 ( V_269 * V_263 , V_261 ) ;
break;
case V_241 + 4 :
* V_266 = ( V_271 - 1 ) * V_261 ;
if ( V_264 )
* V_265 = * V_266 + V_264 * V_263 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( V_270 * V_263 * 2 - 1 +
( V_245 ? V_263 : 0 ) ,
V_261 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_268 = F_178 ( - V_269 , 2 * V_261 ) ;
else
* V_268 = F_178 ( - V_269 , V_261 ) ;
break;
case V_242 + 4 :
* V_266 = 0 ;
if ( V_264 )
* V_265 = * V_266 + V_264 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( - V_263 * ( V_272 * V_269 - 1 ) +
V_270 + ( V_245 ? 1 : 0 ) ,
V_261 ) ;
* V_268 = F_178 ( V_269 * V_263 , V_261 ) ;
break;
case V_243 + 4 :
* V_266 = V_263 * ( V_272 - 1 ) * V_261 ;
if ( V_264 )
* V_265 = * V_266 - V_264 * V_263 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( 1 - V_270 * V_263 * 2 -
( V_245 ? V_263 : 0 ) ,
V_261 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_268 = F_178 ( V_269 , 2 * V_261 ) ;
else
* V_268 = F_178 ( V_269 , V_261 ) ;
break;
case V_244 + 4 :
* V_266 = ( V_263 * ( V_272 - 1 ) + V_271 - 1 ) * V_261 ;
if ( V_264 )
* V_265 = * V_266 - V_264 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( V_263 * ( V_272 * V_269 - 1 ) -
V_270 - ( V_245 ? 1 : 0 ) ,
V_261 ) ;
* V_268 = F_178 ( - V_269 * V_263 , V_261 ) ;
break;
default:
F_121 () ;
return;
}
}
static void F_181 ( T_1 V_263 , T_1 V_103 ,
enum V_114 V_115 , bool V_245 ,
unsigned int V_264 , unsigned * V_265 , unsigned * V_266 ,
T_6 * V_267 , T_6 * V_268 , int V_269 , int V_270 )
{
T_5 V_261 ;
switch ( V_115 ) {
case V_132 :
case V_133 :
case V_134 :
case V_135 :
F_121 () ;
return;
default:
V_261 = F_177 ( V_115 ) / 8 ;
break;
}
F_12 ( L_15 , V_263 , V_103 ) ;
* V_266 = 0 ;
if ( V_264 )
* V_265 = * V_266 + V_264 * V_263 * V_261 ;
else
* V_265 = * V_266 ;
* V_267 = F_178 ( 1 + ( V_270 * V_263 - V_103 * V_269 ) +
( V_245 ? V_263 : 0 ) , V_261 ) ;
if ( V_115 == V_126 ||
V_115 == V_127 )
* V_268 = F_178 ( V_269 , 2 * V_261 ) ;
else
* V_268 = F_178 ( V_269 , V_261 ) ;
}
static int F_182 ( unsigned long V_273 , unsigned long V_274 ,
const struct V_275 * V_276 , T_1 V_277 ,
T_1 V_103 , T_1 V_104 , T_1 V_217 , T_1 V_218 ,
bool V_68 )
{
const int V_278 = F_183 ( V_104 , V_218 ) ;
unsigned long V_279 ;
static const T_5 V_280 [ 3 ] = { 8 , 10 , 20 } ;
T_8 V_2 , V_281 ;
int V_21 ;
V_279 = V_276 -> V_282 + V_276 -> V_283 + V_276 -> V_284 + V_276 -> V_285 - V_217 ;
V_21 = 0 ;
if ( V_218 < V_104 )
V_21 ++ ;
if ( V_217 < V_103 )
V_21 ++ ;
V_281 = F_184 ( ( T_8 ) ( V_276 -> V_285 + V_276 -> V_284 + V_276 -> V_283 ) * V_274 , V_273 ) ;
F_12 ( L_16 , V_281 , V_280 [ V_21 ] ) ;
if ( V_281 <= V_280 [ V_21 ] )
return - V_286 ;
if ( ! V_68 )
return 0 ;
V_2 = F_184 ( ( T_8 ) ( V_279 - V_277 ) * V_274 , V_273 ) ;
F_12 ( L_17 ,
V_2 , F_185 ( 0 , V_278 - 2 ) * V_103 ) ;
if ( V_2 < F_185 ( 0 , V_278 - 2 ) * V_103 )
return - V_286 ;
V_2 = F_184 ( ( T_8 ) V_279 * V_274 , V_273 ) ;
F_12 ( L_18 ,
V_2 , F_185 ( 0 , V_278 - 1 ) * V_103 ) ;
if ( V_2 < F_185 ( 0 , V_278 - 1 ) * V_103 )
return - V_286 ;
return 0 ;
}
static unsigned long F_186 ( unsigned long V_273 ,
const struct V_275 * V_287 , T_1 V_103 ,
T_1 V_104 , T_1 V_217 , T_1 V_218 ,
enum V_114 V_115 )
{
T_2 V_288 = 0 ;
T_8 V_289 ;
if ( V_104 <= V_218 && V_103 <= V_217 )
return ( unsigned long ) V_273 ;
if ( V_104 > V_218 ) {
unsigned int V_290 = V_287 -> V_282 ;
V_289 = ( T_8 ) V_273 * V_104 * V_217 ;
F_187 ( V_289 , 2 * V_218 * V_290 ) ;
V_288 = V_289 ;
if ( V_104 > 2 * V_218 ) {
if ( V_290 == V_217 )
return 0 ;
V_289 = ( T_8 ) V_273 * ( V_104 - 2 * V_218 ) * V_217 ;
F_187 ( V_289 , 2 * V_218 * ( V_290 - V_217 ) ) ;
V_288 = F_188 ( T_2 , V_288 , V_289 ) ;
}
}
if ( V_103 > V_217 ) {
V_289 = ( T_8 ) V_273 * V_103 ;
F_187 ( V_289 , V_217 ) ;
V_288 = F_188 ( T_2 , V_288 , V_289 ) ;
if ( V_115 == V_124 )
V_288 <<= 1 ;
}
return V_288 ;
}
static unsigned long F_189 ( unsigned long V_273 , T_1 V_103 ,
T_1 V_104 , T_1 V_217 , T_1 V_218 , bool V_291 )
{
if ( V_104 > V_218 && V_103 > V_217 )
return V_273 * 4 ;
else
return V_273 * 2 ;
}
static unsigned long F_190 ( unsigned long V_273 , T_1 V_103 ,
T_1 V_104 , T_1 V_217 , T_1 V_218 , bool V_291 )
{
unsigned int V_292 , V_293 ;
if ( V_103 > 3 * V_217 )
V_292 = 4 ;
else if ( V_103 > 2 * V_217 )
V_292 = 3 ;
else if ( V_103 > V_217 )
V_292 = 2 ;
else
V_292 = 1 ;
if ( V_104 > V_218 )
V_293 = 2 ;
else
V_293 = 1 ;
return V_273 * V_293 * V_292 ;
}
static unsigned long F_191 ( unsigned long V_273 , T_1 V_103 ,
T_1 V_104 , T_1 V_217 , T_1 V_218 , bool V_291 )
{
if ( V_291 )
return 1 ;
if ( V_103 > V_217 )
return F_183 ( V_273 , V_217 ) * V_103 ;
else
return V_273 ;
}
static int F_192 ( unsigned long V_273 , unsigned long V_274 ,
const struct V_275 * V_287 ,
T_1 V_103 , T_1 V_104 , T_1 V_217 , T_1 V_218 ,
enum V_114 V_115 , bool * V_68 ,
int * V_269 , int * V_270 , int * V_294 , int * V_295 ,
T_1 V_277 , unsigned long * V_288 , bool V_291 )
{
int error ;
T_1 V_296 , V_297 ;
int V_298 = F_153 ( * V_294 , * V_295 ) ;
const int V_299 =
F_193 ( V_300 ) ;
* V_68 = false ;
do {
V_297 = V_104 / * V_295 ;
V_296 = V_103 / * V_294 ;
* V_288 = V_3 . V_52 -> V_301 ( V_273 , V_296 ,
V_297 , V_217 , V_218 , V_291 ) ;
error = ( V_296 > V_299 || ! * V_288 ||
* V_288 > F_194 () ) ;
if ( error ) {
if ( * V_294 == * V_295 ) {
* V_294 = V_298 ;
++ * V_295 ;
} else {
F_195 ( * V_294 , * V_295 ) ;
if ( * V_294 < * V_295 )
++ * V_294 ;
}
}
} while ( * V_294 <= * V_269 && * V_295 <= * V_270 && error );
if ( error ) {
F_76 ( L_19 ) ;
return - V_286 ;
}
if ( V_296 > V_299 ) {
F_76 ( L_20 ) ;
return - V_286 ;
}
return 0 ;
}
static int F_196 ( unsigned long V_273 , unsigned long V_274 ,
const struct V_275 * V_287 ,
T_1 V_103 , T_1 V_104 , T_1 V_217 , T_1 V_218 ,
enum V_114 V_115 , bool * V_68 ,
int * V_269 , int * V_270 , int * V_294 , int * V_295 ,
T_1 V_277 , unsigned long * V_288 , bool V_291 )
{
int error ;
T_1 V_296 , V_297 ;
const int V_299 =
F_193 ( V_300 ) ;
do {
V_297 = V_104 / * V_295 ;
V_296 = V_103 / * V_294 ;
* V_68 = V_297 > V_218 ;
if ( V_296 > V_299 )
if ( V_297 > V_218 &&
V_297 < V_218 * 2 )
* V_68 = false ;
V_302:
if ( * V_68 )
* V_288 = F_186 ( V_273 , V_287 ,
V_296 , V_297 , V_217 ,
V_218 , V_115 ) ;
else
* V_288 = V_3 . V_52 -> V_301 ( V_273 , V_296 ,
V_297 , V_217 , V_218 ,
V_291 ) ;
error = F_182 ( V_273 , V_274 , V_287 ,
V_277 , V_296 , V_297 , V_217 ,
V_218 , * V_68 ) ;
if ( error && * V_68 ) {
* V_68 = false ;
goto V_302;
}
error = ( error || V_296 > V_299 * 2 ||
( V_296 > V_299 && * V_68 ) ||
! * V_288 || * V_288 > F_194 () ) ;
if ( ! error ) {
if ( V_296 / 4 > V_217 )
error = 1 ;
if ( * V_68 ) {
if ( V_297 / 4 > V_218 )
error = 1 ;
} else {
if ( V_297 / 2 > V_218 )
error = 1 ;
}
}
if ( error )
++ * V_295 ;
} while ( * V_294 <= * V_269 && * V_295 <= * V_270 && error );
if ( error ) {
F_76 ( L_19 ) ;
return - V_286 ;
}
if ( F_182 ( V_273 , V_274 , V_287 , V_277 , V_296 ,
V_297 , V_217 , V_218 , * V_68 ) ) {
F_76 ( L_21 ) ;
return - V_286 ;
}
if ( V_296 > ( V_299 * 2 ) ) {
F_76 ( L_22 ) ;
F_76 ( L_23 ) ;
return - V_286 ;
}
if ( V_296 > V_299 && * V_68 ) {
F_76 ( L_24 ) ;
return - V_286 ;
}
return 0 ;
}
static int F_197 ( unsigned long V_273 , unsigned long V_274 ,
const struct V_275 * V_287 ,
T_1 V_103 , T_1 V_104 , T_1 V_217 , T_1 V_218 ,
enum V_114 V_115 , bool * V_68 ,
int * V_269 , int * V_270 , int * V_294 , int * V_295 ,
T_1 V_277 , unsigned long * V_288 , bool V_291 )
{
T_1 V_296 , V_303 ;
int V_304 = * V_294 ;
T_1 V_297 = V_104 / * V_295 ;
const int V_299 =
F_193 ( V_300 ) ;
const int V_305 = F_193 ( V_306 ) ;
if ( V_291 ) {
V_303 = V_217 * V_305 ;
} else {
V_303 = F_194 () /
F_183 ( V_273 , V_217 ) ;
}
* V_294 = F_183 ( V_103 , V_303 ) ;
* V_294 = * V_294 > V_304 ? * V_294 : V_304 ;
if ( * V_294 > * V_269 )
return - V_286 ;
do {
V_296 = V_103 / * V_294 ;
} while ( * V_294 <= * V_269 &&
V_296 > V_299 && ++ * V_294 );
if ( V_296 > V_299 ) {
F_76 ( L_25 ) ;
return - V_286 ;
}
* V_288 = V_3 . V_52 -> V_301 ( V_273 , V_296 , V_297 ,
V_217 , V_218 , V_291 ) ;
return 0 ;
}
static int F_198 ( unsigned long V_273 , unsigned long V_274 ,
enum V_100 V_101 ,
const struct V_275 * V_287 ,
T_1 V_103 , T_1 V_104 , T_1 V_217 , T_1 V_218 ,
enum V_114 V_115 , bool * V_68 ,
int * V_269 , int * V_270 , T_1 V_277 ,
enum V_136 V_137 , bool V_291 )
{
const int V_305 = F_193 ( V_306 ) ;
const int V_307 = 16 ;
unsigned long V_288 = 0 ;
int V_294 , V_295 , V_308 ;
if ( V_103 == V_217 && V_104 == V_218 )
return 0 ;
if ( V_273 == 0 || V_287 -> V_309 == 0 ) {
F_76 ( L_26 ) ;
return - V_286 ;
}
if ( ( V_101 & V_310 ) == 0 )
return - V_286 ;
if ( V_291 ) {
* V_269 = * V_270 = 1 ;
} else {
* V_269 = V_307 ;
* V_270 = ( V_137 == V_139 &&
F_14 ( V_138 ) ) ?
2 : V_307 ;
}
if ( V_115 == V_132 ||
V_115 == V_133 ||
V_115 == V_134 ||
V_115 == V_135 ) {
* V_269 = 1 ;
* V_270 = 1 ;
* V_68 = false ;
return 0 ;
}
V_294 = F_183 ( F_183 ( V_103 , V_217 ) , V_305 ) ;
V_295 = F_183 ( F_183 ( V_104 , V_218 ) , V_305 ) ;
if ( V_294 > * V_269 || V_217 > V_103 * 8 )
return - V_286 ;
if ( V_295 > * V_270 || V_218 > V_104 * 8 )
return - V_286 ;
V_308 = V_3 . V_52 -> V_311 ( V_273 , V_274 , V_287 , V_103 , V_104 ,
V_217 , V_218 , V_115 , V_68 ,
V_269 , V_270 , & V_294 , & V_295 , V_277 , & V_288 ,
V_291 ) ;
if ( V_308 )
return V_308 ;
F_12 ( L_27 ,
V_103 , V_104 ,
V_217 , V_218 ,
V_217 / V_103 , F_199 ( V_217 , V_103 ) ,
V_218 / V_104 , F_199 ( V_218 , V_104 ) ,
V_294 , V_295 ,
V_103 / V_294 , V_104 / V_295 ,
V_217 / ( V_103 / V_294 ) , F_199 ( V_217 , V_103 / V_294 ) ,
V_218 / ( V_104 / V_295 ) , F_199 ( V_218 , V_104 / V_295 ) ,
* V_68 ? 5 : 3 ,
V_288 , F_194 () ) ;
if ( ! V_288 || V_288 > F_194 () ) {
F_76 ( L_28
L_29
L_30 ,
V_288 , F_194 () ) ;
return - V_286 ;
}
* V_269 = V_294 ;
* V_270 = V_295 ;
return 0 ;
}
int F_200 ( enum V_60 V_61 , enum V_5 V_6 ,
const struct V_312 * V_313 ,
const struct V_275 * V_314 ,
int * V_269 , int * V_270 )
{
enum V_100 V_101 = F_201 ( V_61 ) ;
bool V_68 = true ;
bool V_245 = false ;
T_1 V_297 = V_313 -> V_104 ;
T_1 V_296 = V_313 -> V_103 ;
bool V_220 = V_314 -> V_315 ;
T_1 V_217 , V_218 ;
int V_277 = V_313 -> V_277 ;
unsigned long V_273 = F_202 ( V_6 ) ;
unsigned long V_274 = F_203 ( V_6 ) ;
V_217 = V_313 -> V_217 == 0 ? V_313 -> V_103 : V_313 -> V_217 ;
V_218 = V_313 -> V_218 == 0 ? V_313 -> V_104 : V_313 -> V_218 ;
if ( V_220 && V_313 -> V_104 == V_218 )
V_245 = true ;
if ( V_220 ) {
if ( V_245 )
V_297 /= 2 ;
V_218 /= 2 ;
F_12 ( L_31 ,
V_297 , V_218 ) ;
}
if ( ! F_204 ( V_61 , V_313 -> V_115 ) )
return - V_286 ;
return F_198 ( V_273 , V_274 , V_101 , V_314 , V_296 ,
V_297 , V_217 , V_218 , V_313 -> V_115 ,
& V_68 , V_269 , V_270 , V_277 ,
V_313 -> V_137 , false ) ;
}
static int F_205 ( enum V_60 V_61 ,
enum V_100 V_101 , T_2 V_99 , T_2 V_316 ,
T_1 V_263 , int V_277 , int V_317 , T_1 V_103 , T_1 V_104 ,
T_1 V_217 , T_1 V_218 , enum V_114 V_115 ,
T_5 V_219 , bool V_262 , T_5 V_105 , T_5 V_318 ,
T_5 V_108 , enum V_136 V_137 ,
bool V_319 , const struct V_275 * V_287 ,
bool V_291 )
{
bool V_68 = true ;
bool V_245 = false ;
int V_47 , V_320 = 0 ;
unsigned V_265 , V_266 ;
T_6 V_267 ;
T_6 V_268 ;
T_1 V_321 , V_322 ;
unsigned int V_264 = 0 ;
T_1 V_297 = V_104 ;
T_1 V_296 = V_103 ;
int V_269 = 1 , V_270 = 1 ;
bool V_220 = V_287 -> V_315 ;
unsigned long V_273 = F_206 ( V_61 ) ;
unsigned long V_274 = F_207 ( V_61 ) ;
if ( V_99 == 0 && V_137 != V_139 )
return - V_286 ;
switch ( V_115 ) {
case V_126 :
case V_127 :
case V_117 :
if ( V_296 & 1 ) {
F_76 ( L_32 ,
V_296 ) ;
return - V_286 ;
}
break;
default:
break;
}
V_217 = V_217 == 0 ? V_103 : V_217 ;
V_218 = V_218 == 0 ? V_104 : V_218 ;
if ( V_220 && V_104 == V_218 )
V_245 = true ;
if ( V_220 ) {
if ( V_245 )
V_297 /= 2 ;
V_317 /= 2 ;
V_218 /= 2 ;
F_12 ( L_33
L_34 , V_297 , V_317 ,
V_218 ) ;
}
if ( ! F_204 ( V_61 , V_115 ) )
return - V_286 ;
V_47 = F_198 ( V_273 , V_274 , V_101 , V_287 , V_296 ,
V_297 , V_217 , V_218 , V_115 ,
& V_68 , & V_269 , & V_270 , V_277 ,
V_137 , V_291 ) ;
if ( V_47 )
return V_47 ;
V_296 = V_296 / V_269 ;
V_297 = V_297 / V_270 ;
if ( V_269 > 1 || V_270 > 1 )
F_12 ( L_35 ,
V_269 , V_270 , V_296 , V_297 ) ;
switch ( V_115 ) {
case V_126 :
case V_127 :
case V_117 :
if ( V_296 & 1 ) {
F_12 ( L_36 ) ;
F_12 ( L_37 ,
V_296 , V_296 & ~ 1 ) ;
V_296 &= ~ 1 ;
}
break;
default:
break;
}
if ( V_115 == V_126 ||
V_115 == V_127 ||
V_115 == V_117 )
V_320 = 1 ;
if ( V_220 && ! V_245 ) {
if ( ! V_297 || V_297 == V_218 )
V_264 = 0 ;
else
V_264 = V_297 / V_218 / 2 ;
}
if ( V_245 )
V_264 = 1 ;
V_265 = 0 ;
V_266 = 0 ;
V_267 = 0 ;
V_268 = 0 ;
if ( V_61 == V_62 ) {
V_321 = V_217 ;
V_322 = V_218 ;
} else {
V_321 = V_296 ;
V_322 = V_104 ;
}
if ( V_137 == V_139 )
F_181 ( V_263 , V_321 ,
V_115 , V_245 , V_264 ,
& V_265 , & V_266 , & V_267 , & V_268 ,
V_269 , V_270 ) ;
else if ( V_137 == V_323 )
F_180 ( V_219 , V_262 , V_263 ,
V_321 , V_322 ,
V_115 , V_245 , V_264 ,
& V_265 , & V_266 , & V_267 , & V_268 ,
V_269 , V_270 ) ;
else
F_179 ( V_219 , V_262 ,
V_263 , V_321 , V_322 ,
V_115 , V_245 , V_264 ,
& V_265 , & V_266 , & V_267 , & V_268 ,
V_269 , V_270 ) ;
F_12 ( L_38 ,
V_265 , V_266 , V_267 , V_268 ) ;
F_120 ( V_61 , V_115 ) ;
F_122 ( V_61 , V_137 ) ;
F_98 ( V_61 , V_99 + V_265 ) ;
F_100 ( V_61 , V_99 + V_266 ) ;
if ( V_117 == V_115 ) {
F_102 ( V_61 , V_316 + V_265 ) ;
F_104 ( V_61 , V_316 + V_266 ) ;
}
if ( V_3 . V_52 -> V_324 )
V_267 += V_268 - 1 ;
F_118 ( V_61 , V_267 ) ;
F_116 ( V_61 , V_268 ) ;
F_12 ( L_39 , V_277 , V_317 , V_296 ,
V_297 , V_217 , V_218 ) ;
F_106 ( V_61 , V_101 , V_277 , V_317 ) ;
F_108 ( V_61 , V_296 , V_297 ) ;
if ( V_101 & V_310 ) {
F_175 ( V_61 , V_296 , V_297 , V_217 ,
V_218 , V_220 , V_68 , V_245 ,
V_115 , V_219 ) ;
F_111 ( V_61 , V_217 , V_218 ) ;
F_140 ( V_61 , V_320 ) ;
}
F_176 ( V_61 , V_219 , V_137 , V_262 ,
V_115 ) ;
F_112 ( V_61 , V_101 , V_105 ) ;
F_114 ( V_61 , V_101 , V_318 ) ;
F_115 ( V_61 , V_101 , V_108 ) ;
F_141 ( V_61 , V_101 , V_319 ) ;
return 0 ;
}
int F_208 ( enum V_60 V_61 , const struct V_312 * V_313 ,
bool V_319 , const struct V_275 * V_287 ,
bool V_291 )
{
int V_47 ;
enum V_100 V_101 = F_201 ( V_61 ) ;
enum V_5 V_6 ;
V_6 = F_125 ( V_61 ) ;
F_12 ( L_40
L_41 ,
V_61 , & V_313 -> V_99 , & V_313 -> V_316 , V_313 -> V_263 , V_313 -> V_277 ,
V_313 -> V_317 , V_313 -> V_103 , V_313 -> V_104 , V_313 -> V_217 , V_313 -> V_218 ,
V_313 -> V_115 , V_313 -> V_219 , V_313 -> V_262 , V_6 , V_319 ) ;
V_47 = F_205 ( V_61 , V_101 , V_313 -> V_99 , V_313 -> V_316 ,
V_313 -> V_263 , V_313 -> V_277 , V_313 -> V_317 , V_313 -> V_103 , V_313 -> V_104 ,
V_313 -> V_217 , V_313 -> V_218 , V_313 -> V_115 , V_313 -> V_219 ,
V_313 -> V_262 , V_313 -> V_105 , V_313 -> V_318 , V_313 -> V_108 ,
V_313 -> V_137 , V_319 , V_287 , V_291 ) ;
return V_47 ;
}
int F_209 ( const struct V_325 * V_326 ,
bool V_291 , const struct V_275 * V_287 )
{
int V_47 ;
T_2 V_248 ;
enum V_60 V_61 = V_62 ;
const int V_277 = 0 , V_317 = 0 ;
const T_5 V_105 = 0 , V_108 = 0 ;
const bool V_319 = false ;
bool V_327 ;
int V_296 = V_287 -> V_282 ;
int V_297 = V_287 -> V_328 ;
enum V_100 V_101 =
V_310 | V_107 ;
F_12 ( L_42
L_43 , V_326 -> V_99 , V_326 -> V_316 , V_296 ,
V_297 , V_326 -> V_103 , V_326 -> V_104 , V_326 -> V_115 , V_326 -> V_219 ,
V_326 -> V_262 ) ;
V_47 = F_205 ( V_61 , V_101 , V_326 -> V_99 , V_326 -> V_316 ,
V_326 -> V_329 , V_277 , V_317 , V_296 , V_297 , V_326 -> V_103 ,
V_326 -> V_104 , V_326 -> V_115 , V_326 -> V_219 , V_326 -> V_262 , V_105 ,
V_326 -> V_318 , V_108 , V_326 -> V_137 ,
V_319 , V_287 , V_291 ) ;
switch ( V_326 -> V_115 ) {
case V_122 :
case V_125 :
case V_121 :
case V_119 :
case V_120 :
case V_123 :
case V_131 :
case V_118 :
V_327 = true ;
break;
default:
V_327 = false ;
break;
}
V_248 = F_3 ( F_75 ( V_61 ) ) ;
V_248 = F_124 ( V_248 , V_327 , 10 , 10 ) ;
V_248 = F_124 ( V_248 , V_291 , 19 , 19 ) ;
F_1 ( F_75 ( V_61 ) , V_248 ) ;
return V_47 ;
}
int F_210 ( enum V_60 V_61 , bool V_63 )
{
F_12 ( L_44 , V_61 , V_63 ) ;
F_9 ( F_75 ( V_61 ) , V_63 ? 1 : 0 , 0 , 0 ) ;
return 0 ;
}
bool F_211 ( enum V_60 V_61 )
{
return F_6 ( F_75 ( V_61 ) , 0 , 0 ) ;
}
void F_212 ( enum V_5 V_6 , bool V_63 )
{
F_7 ( V_6 , V_330 , V_63 ) ;
F_5 ( V_6 , V_330 ) ;
}
bool F_72 ( enum V_5 V_6 )
{
return ! ! F_5 ( V_6 , V_330 ) ;
}
void F_213 ( bool V_63 )
{
F_210 ( V_62 , V_63 ) ;
}
bool F_214 ( void )
{
return F_211 ( V_62 ) ;
}
static void F_215 ( bool V_331 )
{
if ( ! F_14 ( V_332 ) )
return;
F_9 ( V_17 , V_331 ? 1 : 0 , 29 , 29 ) ;
}
void F_216 ( bool V_63 )
{
if ( ! F_14 ( V_333 ) )
return;
F_9 ( V_17 , V_63 ? 1 : 0 , 28 , 28 ) ;
}
void F_217 ( bool V_63 )
{
if ( ! F_14 ( V_334 ) )
return;
F_9 ( V_17 , V_63 ? 1 : 0 , 27 , 27 ) ;
}
static void F_218 ( enum V_5 V_6 , bool V_63 )
{
F_7 ( V_6 , V_335 , V_63 ) ;
}
static void F_219 ( enum V_5 V_6 )
{
F_7 ( V_6 , V_336 , 1 ) ;
}
void F_220 ( enum V_337 V_338 )
{
F_9 ( V_18 , V_338 , 2 , 1 ) ;
}
static void F_221 ( enum V_5 V_6 , T_2 V_339 )
{
F_1 ( F_222 ( V_6 ) , V_339 ) ;
}
static void F_223 ( enum V_5 V_340 ,
enum V_341 type ,
T_2 V_342 )
{
F_7 ( V_340 , V_343 , type ) ;
F_1 ( F_224 ( V_340 ) , V_342 ) ;
}
static void F_225 ( enum V_5 V_340 , bool V_63 )
{
F_7 ( V_340 , V_344 , V_63 ) ;
}
static void F_226 ( enum V_5 V_340 ,
bool V_63 )
{
if ( ! F_14 ( V_27 ) )
return;
if ( V_340 == V_145 )
F_9 ( V_18 , V_63 , 18 , 18 ) ;
else if ( V_340 == V_36 )
F_9 ( V_18 , V_63 , 19 , 19 ) ;
}
void F_227 ( enum V_5 V_6 ,
const struct V_345 * V_346 )
{
F_221 ( V_6 , V_346 -> V_347 ) ;
F_223 ( V_6 , V_346 -> V_348 , V_346 -> V_342 ) ;
F_225 ( V_6 , V_346 -> V_349 ) ;
F_226 ( V_6 ,
V_346 -> V_350 ) ;
if ( F_14 ( V_37 ) ) {
F_134 ( V_6 , V_346 -> V_351 ) ;
F_135 ( V_6 , & V_346 -> V_352 ) ;
}
}
static void F_228 ( enum V_5 V_6 , T_5 V_353 )
{
int V_354 ;
switch ( V_353 ) {
case 12 :
V_354 = 0 ;
break;
case 16 :
V_354 = 1 ;
break;
case 18 :
V_354 = 2 ;
break;
case 24 :
V_354 = 3 ;
break;
default:
F_121 () ;
return;
}
F_7 ( V_6 , V_355 , V_354 ) ;
}
static void F_229 ( enum V_356 V_338 )
{
T_2 V_248 ;
int V_357 , V_358 ;
switch ( V_338 ) {
case V_359 :
V_357 = 0 ;
V_358 = 0 ;
break;
case V_360 :
V_357 = 1 ;
V_358 = 0 ;
break;
case V_361 :
V_357 = 1 ;
V_358 = 1 ;
break;
default:
F_121 () ;
return;
}
V_248 = F_3 ( V_17 ) ;
V_248 = F_124 ( V_248 , V_357 , 15 , 15 ) ;
V_248 = F_124 ( V_248 , V_358 , 16 , 16 ) ;
F_1 ( V_17 , V_248 ) ;
}
static void F_230 ( enum V_5 V_6 , bool V_63 )
{
F_7 ( V_6 , V_362 , V_63 ) ;
}
void F_231 ( enum V_5 V_6 ,
const struct V_363 * V_364 )
{
F_229 ( V_364 -> V_365 ) ;
F_230 ( V_6 , V_364 -> V_366 ) ;
F_218 ( V_6 , V_364 -> V_367 ) ;
F_232 ( V_6 , & V_364 -> V_368 ) ;
F_228 ( V_6 , V_364 -> V_369 ) ;
F_215 ( V_364 -> V_370 ) ;
F_219 ( V_6 ) ;
}
static bool F_233 ( T_1 V_103 , T_1 V_104 )
{
return V_103 <= V_3 . V_52 -> V_371 &&
V_104 <= V_3 . V_52 -> V_372 ;
}
static bool F_234 ( int V_284 , int V_283 , int V_285 ,
int V_373 , int V_374 , int V_375 )
{
if ( V_284 < 1 || V_284 > V_3 . V_52 -> V_376 ||
V_283 < 1 || V_283 > V_3 . V_52 -> V_377 ||
V_285 < 1 || V_285 > V_3 . V_52 -> V_377 ||
V_373 < 1 || V_373 > V_3 . V_52 -> V_376 ||
V_374 < 0 || V_374 > V_3 . V_52 -> V_378 ||
V_375 < 0 || V_375 > V_3 . V_52 -> V_378 )
return false ;
return true ;
}
static bool F_235 ( enum V_5 V_6 ,
unsigned long V_273 )
{
if ( F_136 ( V_6 ) )
return V_273 <= V_3 . V_52 -> V_379 ? true : false ;
else
return V_273 <= V_3 . V_52 -> V_380 ? true : false ;
}
bool F_236 ( enum V_5 V_6 ,
const struct V_275 * V_314 )
{
if ( ! F_233 ( V_314 -> V_282 , V_314 -> V_328 ) )
return false ;
if ( ! F_235 ( V_6 , V_314 -> V_309 ) )
return false ;
if ( F_136 ( V_6 ) ) {
if ( V_314 -> V_315 )
return false ;
if ( ! F_234 ( V_314 -> V_284 , V_314 -> V_283 ,
V_314 -> V_285 , V_314 -> V_373 , V_314 -> V_374 ,
V_314 -> V_375 ) )
return false ;
}
return true ;
}
static void F_237 ( enum V_5 V_6 , int V_284 ,
int V_283 , int V_285 , int V_373 , int V_374 , int V_375 ,
enum V_381 V_382 ,
enum V_381 V_383 ,
enum V_384 V_385 ,
enum V_381 V_386 ,
enum V_384 V_387 )
{
T_2 V_388 , V_389 , V_248 ;
bool V_390 , V_391 , V_392 , V_393 , V_394 , V_395 ;
V_388 = F_92 ( V_284 - 1 , V_3 . V_52 -> V_396 , 0 ) |
F_92 ( V_283 - 1 , V_3 . V_52 -> V_397 , 8 ) |
F_92 ( V_285 - 1 , V_3 . V_52 -> V_398 , 20 ) ;
V_389 = F_92 ( V_373 - 1 , V_3 . V_52 -> V_396 , 0 ) |
F_92 ( V_374 , V_3 . V_52 -> V_397 , 8 ) |
F_92 ( V_375 , V_3 . V_52 -> V_398 , 20 ) ;
F_1 ( F_238 ( V_6 ) , V_388 ) ;
F_1 ( F_239 ( V_6 ) , V_389 ) ;
switch ( V_382 ) {
case V_399 :
V_393 = true ;
break;
case V_400 :
V_393 = false ;
break;
default:
F_121 () ;
}
switch ( V_383 ) {
case V_399 :
V_394 = true ;
break;
case V_400 :
V_394 = false ;
break;
default:
F_121 () ;
}
switch ( V_386 ) {
case V_399 :
V_395 = true ;
break;
case V_400 :
V_395 = false ;
break;
default:
F_121 () ;
}
switch ( V_385 ) {
case V_401 :
V_392 = false ;
break;
case V_402 :
V_392 = true ;
break;
default:
F_121 () ;
}
V_390 = true ;
switch ( V_387 ) {
case V_402 :
V_391 = false ;
break;
case V_401 :
V_391 = true ;
break;
default:
F_121 () ;
}
V_248 = F_92 ( V_390 , 17 , 17 ) |
F_92 ( V_391 , 16 , 16 ) |
F_92 ( V_395 , 15 , 15 ) |
F_92 ( V_392 , 14 , 14 ) |
F_92 ( V_394 , 13 , 13 ) |
F_92 ( V_393 , 12 , 12 ) ;
F_1 ( F_240 ( V_6 ) , V_248 ) ;
if ( V_3 . V_403 ) {
const int V_109 [] = {
[ V_145 ] = 0 ,
[ V_146 ] = 1 ,
[ V_147 ] = 2 ,
} ;
T_2 V_404 , V_2 ;
V_404 = ( 1 << 0 ) | ( 1 << 3 ) | ( 1 << 6 ) ;
V_2 = ( V_391 << 0 ) | ( V_392 << 3 ) | ( V_390 << 6 ) ;
V_404 <<= 16 + V_109 [ V_6 ] ;
V_2 <<= 16 + V_109 [ V_6 ] ;
F_241 ( V_3 . V_403 , V_3 . V_405 ,
V_404 , V_2 ) ;
}
}
void F_242 ( enum V_5 V_6 ,
const struct V_275 * V_314 )
{
unsigned V_406 , V_407 ;
unsigned long V_408 , V_409 ;
struct V_275 V_276 = * V_314 ;
F_12 ( L_45 , V_6 , V_276 . V_282 , V_276 . V_328 ) ;
if ( ! F_236 ( V_6 , & V_276 ) ) {
F_121 () ;
return;
}
if ( F_136 ( V_6 ) ) {
F_237 ( V_6 , V_276 . V_284 , V_276 . V_283 , V_276 . V_285 , V_276 . V_373 ,
V_276 . V_374 , V_276 . V_375 , V_276 . V_382 , V_276 . V_383 ,
V_276 . V_385 , V_276 . V_386 , V_276 . V_387 ) ;
V_406 = V_276 . V_282 + V_276 . V_283 + V_276 . V_284 + V_276 . V_285 ;
V_407 = V_276 . V_328 + V_276 . V_374 + V_276 . V_373 + V_276 . V_375 ;
V_408 = V_314 -> V_309 / V_406 ;
V_409 = V_314 -> V_309 / V_406 / V_407 ;
F_12 ( L_46 , V_314 -> V_309 ) ;
F_12 ( L_47 ,
V_276 . V_284 , V_276 . V_283 , V_276 . V_285 , V_276 . V_373 , V_276 . V_374 , V_276 . V_375 ) ;
F_12 ( L_48 ,
V_276 . V_382 , V_276 . V_383 , V_276 . V_385 ,
V_276 . V_386 , V_276 . V_387 ) ;
F_12 ( L_49 , V_408 , V_409 ) ;
} else {
if ( V_276 . V_315 == true )
V_276 . V_328 /= 2 ;
}
F_142 ( V_6 , V_276 . V_282 , V_276 . V_328 ) ;
}
static void F_243 ( enum V_5 V_6 , T_1 V_410 ,
T_1 V_411 )
{
F_84 ( V_410 < 1 ) ;
F_84 ( V_411 < 1 ) ;
F_1 ( F_244 ( V_6 ) ,
F_92 ( V_410 , 23 , 16 ) | F_92 ( V_411 , 7 , 0 ) ) ;
if ( F_14 ( V_43 ) == false &&
V_6 == V_145 )
V_3 . V_412 = F_245 () / V_410 ;
}
static void F_246 ( enum V_5 V_6 , int * V_410 ,
int * V_411 )
{
T_2 V_248 ;
V_248 = F_3 ( F_244 ( V_6 ) ) ;
* V_410 = F_126 ( V_248 , 23 , 16 ) ;
* V_411 = F_126 ( V_248 , 7 , 0 ) ;
}
unsigned long F_245 ( void )
{
struct V_413 * V_414 ;
unsigned long V_47 = 0 ;
switch ( F_247 () ) {
case V_415 :
V_47 = F_248 () ;
break;
case V_416 :
V_414 = F_249 ( L_50 ) ;
if ( ! V_414 )
V_414 = F_249 ( L_51 ) ;
V_47 = V_414 -> V_417 . V_418 [ 0 ] ;
break;
case V_419 :
V_414 = F_249 ( L_52 ) ;
if ( ! V_414 )
V_414 = F_249 ( L_53 ) ;
V_47 = V_414 -> V_417 . V_418 [ 0 ] ;
break;
default:
F_121 () ;
return 0 ;
}
return V_47 ;
}
unsigned long F_203 ( enum V_5 V_6 )
{
struct V_413 * V_414 ;
int V_420 ;
unsigned long V_47 ;
T_2 V_248 ;
if ( F_136 ( V_6 ) ) {
V_248 = F_3 ( F_244 ( V_6 ) ) ;
V_420 = F_126 ( V_248 , 23 , 16 ) ;
switch ( F_250 ( V_6 ) ) {
case V_415 :
V_47 = F_248 () ;
break;
case V_416 :
V_414 = F_249 ( L_50 ) ;
if ( ! V_414 )
V_414 = F_249 ( L_51 ) ;
V_47 = V_414 -> V_417 . V_418 [ 0 ] ;
break;
case V_419 :
V_414 = F_249 ( L_52 ) ;
if ( ! V_414 )
V_414 = F_249 ( L_53 ) ;
V_47 = V_414 -> V_417 . V_418 [ 0 ] ;
break;
default:
F_121 () ;
return 0 ;
}
return V_47 / V_420 ;
} else {
return F_245 () ;
}
}
unsigned long F_202 ( enum V_5 V_6 )
{
unsigned long V_47 ;
if ( F_136 ( V_6 ) ) {
int V_421 ;
T_2 V_248 ;
V_248 = F_3 ( F_244 ( V_6 ) ) ;
V_421 = F_126 ( V_248 , 7 , 0 ) ;
V_47 = F_203 ( V_6 ) ;
return V_47 / V_421 ;
} else {
return V_3 . V_422 ;
}
}
void F_251 ( unsigned long V_273 )
{
V_3 . V_422 = V_273 ;
}
unsigned long F_194 ( void )
{
return V_3 . V_412 ;
}
static unsigned long F_206 ( enum V_60 V_61 )
{
enum V_5 V_6 ;
if ( V_61 == V_62 )
return 0 ;
V_6 = F_125 ( V_61 ) ;
return F_202 ( V_6 ) ;
}
static unsigned long F_207 ( enum V_60 V_61 )
{
enum V_5 V_6 ;
if ( V_61 == V_62 )
return 0 ;
V_6 = F_125 ( V_61 ) ;
return F_203 ( V_6 ) ;
}
static void F_252 ( struct V_423 * V_424 , enum V_5 V_6 )
{
int V_420 , V_421 ;
enum V_425 V_426 ;
F_253 ( V_424 , L_54 , V_11 [ V_6 ] . V_58 ) ;
V_426 = F_250 ( V_6 ) ;
F_253 ( V_424 , L_55 , V_11 [ V_6 ] . V_58 ,
F_254 ( V_426 ) ,
F_255 ( V_426 ) ) ;
F_246 ( V_6 , & V_420 , & V_421 ) ;
F_253 ( V_424 , L_56 ,
F_203 ( V_6 ) , V_420 ) ;
F_253 ( V_424 , L_57 ,
F_202 ( V_6 ) , V_421 ) ;
}
void F_256 ( struct V_423 * V_424 )
{
int V_420 ;
T_2 V_248 ;
enum V_425 V_427 = F_247 () ;
if ( F_61 () )
return;
F_253 ( V_424 , L_58 ) ;
F_253 ( V_424 , L_59 ,
F_254 ( V_427 ) ,
F_255 ( V_427 ) ) ;
F_253 ( V_424 , L_60 , F_245 () ) ;
if ( F_14 ( V_43 ) ) {
F_253 ( V_424 , L_61 ) ;
V_248 = F_3 ( V_428 ) ;
V_420 = F_126 ( V_248 , 23 , 16 ) ;
F_253 ( V_424 , L_56 ,
( F_245 () / V_420 ) , V_420 ) ;
}
F_252 ( V_424 , V_145 ) ;
if ( F_14 ( V_30 ) )
F_252 ( V_424 , V_146 ) ;
if ( F_14 ( V_33 ) )
F_252 ( V_424 , V_147 ) ;
F_64 () ;
}
static void F_257 ( struct V_423 * V_424 )
{
int V_21 , V_22 ;
const char * V_429 [] = {
[ V_145 ] = L_62 ,
[ V_36 ] = L_63 ,
[ V_146 ] = L_64 ,
[ V_147 ] = L_65 ,
} ;
const char * V_430 [] = {
[ V_39 ] = L_66 ,
[ V_142 ] = L_67 ,
[ V_143 ] = L_68 ,
[ V_144 ] = L_69 ,
} ;
const char * * V_431 ;
#define F_258 ( V_47 ) seq_printf(s, "%-50s %08x\n", #r, dispc_read_reg(r))
if ( F_61 () )
return;
F_258 ( V_432 ) ;
F_258 ( V_433 ) ;
F_258 ( V_434 ) ;
F_258 ( V_435 ) ;
F_258 ( V_436 ) ;
F_258 ( V_17 ) ;
F_258 ( V_18 ) ;
F_258 ( V_437 ) ;
F_258 ( V_438 ) ;
F_258 ( V_439 ) ;
if ( F_14 ( V_27 ) ||
F_14 ( V_28 ) )
F_258 ( V_112 ) ;
if ( F_14 ( V_30 ) ) {
F_258 ( V_59 ) ;
F_258 ( V_440 ) ;
}
if ( F_14 ( V_33 ) ) {
F_258 ( V_441 ) ;
F_258 ( V_442 ) ;
}
if ( F_14 ( V_443 ) )
F_258 ( V_198 ) ;
#undef F_258
#define F_259 ( V_21 , V_58 ) name(i)
#define F_258 ( V_21 , V_47 ) seq_printf(s, "%s(%s)%*s %08x\n", #r, p_names[i], \
(int)(48 - strlen(#r) - strlen(p_names[i])), " ", \
dispc_read_reg(DISPC_REG(i, r)))
V_431 = V_429 ;
for ( V_21 = 0 ; V_21 < F_15 () ; V_21 ++ ) {
F_258 ( V_21 , F_222 ) ;
F_258 ( V_21 , F_224 ) ;
F_258 ( V_21 , F_143 ) ;
if ( V_21 == V_36 )
continue;
F_258 ( V_21 , F_238 ) ;
F_258 ( V_21 , F_239 ) ;
F_258 ( V_21 , F_240 ) ;
F_258 ( V_21 , F_244 ) ;
F_258 ( V_21 , V_444 ) ;
F_258 ( V_21 , V_445 ) ;
F_258 ( V_21 , V_446 ) ;
if ( F_14 ( V_37 ) ) {
F_258 ( V_21 , F_137 ) ;
F_258 ( V_21 , F_138 ) ;
F_258 ( V_21 , F_139 ) ;
}
}
V_431 = V_430 ;
for ( V_21 = 0 ; V_21 < F_29 () ; V_21 ++ ) {
F_258 ( V_21 , F_99 ) ;
F_258 ( V_21 , F_101 ) ;
F_258 ( V_21 , F_107 ) ;
F_258 ( V_21 , F_109 ) ;
F_258 ( V_21 , F_75 ) ;
F_258 ( V_21 , F_151 ) ;
F_258 ( V_21 , F_147 ) ;
F_258 ( V_21 , F_119 ) ;
F_258 ( V_21 , F_117 ) ;
if ( F_14 ( V_38 ) )
F_258 ( V_21 , F_152 ) ;
if ( F_14 ( V_443 ) )
F_258 ( V_21 , F_157 ) ;
if ( V_21 == V_39 ) {
F_258 ( V_21 , V_447 ) ;
F_258 ( V_21 , V_448 ) ;
continue;
}
F_258 ( V_21 , F_160 ) ;
F_258 ( V_21 , F_110 ) ;
F_258 ( V_21 , F_163 ) ;
F_258 ( V_21 , F_165 ) ;
if ( F_14 ( V_41 ) ) {
F_258 ( V_21 , F_103 ) ;
F_258 ( V_21 , F_105 ) ;
F_258 ( V_21 , F_161 ) ;
F_258 ( V_21 , F_167 ) ;
F_258 ( V_21 , F_169 ) ;
}
if ( F_14 ( V_42 ) )
F_258 ( V_21 , F_174 ) ;
}
#undef F_259
#undef F_258
#define F_259 ( V_61 , V_58 , V_21 ) name(plane, i)
#define F_258 ( V_61 , V_58 , V_21 ) \
seq_printf(s, "%s_%d(%s)%*s %08x\n", #name, i, p_names[plane], \
(int)(46 - strlen(#name) - strlen(p_names[plane])), " ", \
dispc_read_reg(DISPC_REG(plane, name, i)))
for ( V_21 = 1 ; V_21 < F_29 () ; V_21 ++ ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_258 ( V_21 , F_78 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_258 ( V_21 , F_80 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 5 ; V_22 ++ )
F_258 ( V_21 , F_95 , V_22 ) ;
if ( F_14 ( V_40 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_258 ( V_21 , F_82 , V_22 ) ;
}
if ( F_14 ( V_41 ) ) {
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_258 ( V_21 , F_85 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_258 ( V_21 , F_87 , V_22 ) ;
for ( V_22 = 0 ; V_22 < 8 ; V_22 ++ )
F_258 ( V_21 , F_89 , V_22 ) ;
}
}
F_64 () ;
#undef F_259
#undef F_258
}
int F_260 ( unsigned long F_245 ,
struct V_449 * V_417 )
{
if ( V_417 -> V_410 > 255 || V_417 -> V_410 == 0 )
return - V_286 ;
if ( V_417 -> V_411 < 1 || V_417 -> V_411 > 255 )
return - V_286 ;
V_417 -> V_450 = F_245 / V_417 -> V_410 ;
V_417 -> V_451 = V_417 -> V_450 / V_417 -> V_411 ;
return 0 ;
}
bool F_261 ( unsigned long V_3 ,
unsigned long V_452 , unsigned long V_453 ,
T_9 V_454 , void * V_455 )
{
int V_456 , V_457 , V_458 ;
int V_459 , V_460 , V_461 ;
unsigned long V_451 , V_450 ;
unsigned long V_462 ;
unsigned long V_463 , V_464 ;
unsigned V_465 ;
unsigned long V_466 ;
#ifdef F_262
V_465 = F_262 ;
#else
V_465 = 0 ;
#endif
V_463 = F_263 ( V_467 ) ;
V_464 = F_193 ( V_467 ) ;
V_462 = F_193 ( V_468 ) ;
V_452 = V_452 ? V_452 : 1 ;
V_453 = V_453 ? V_453 : V_469 ;
V_457 = F_185 ( F_183 ( V_3 , V_462 ) , 1ul ) ;
V_458 = F_153 ( V_3 / V_452 , 255ul ) ;
for ( V_456 = V_457 ; V_456 <= V_458 ; ++ V_456 ) {
V_450 = V_3 / V_456 ;
V_460 = F_185 ( F_183 ( V_450 , V_453 ) , V_463 ) ;
V_461 = F_153 ( V_450 / V_452 , V_464 ) ;
for ( V_459 = V_460 ; V_459 <= V_461 ; ++ V_459 ) {
V_451 = V_450 / V_459 ;
if ( F_14 ( V_43 ) )
V_466 = F_194 () ;
else
V_466 = V_450 ;
if ( V_466 < V_451 * V_465 )
continue;
if ( V_454 ( V_456 , V_459 , V_450 , V_451 , V_455 ) )
return true ;
}
}
return false ;
}
void F_232 ( enum V_5 V_6 ,
const struct V_449 * V_417 )
{
F_12 ( L_70 , V_417 -> V_450 , V_417 -> V_410 ) ;
F_12 ( L_71 , V_417 -> V_451 , V_417 -> V_411 ) ;
F_243 ( V_6 , V_417 -> V_410 , V_417 -> V_411 ) ;
}
int F_264 ( enum V_5 V_6 ,
struct V_449 * V_417 )
{
unsigned long V_466 ;
V_466 = F_245 () ;
V_417 -> V_410 = F_6 ( F_244 ( V_6 ) , 23 , 16 ) ;
V_417 -> V_411 = F_6 ( F_244 ( V_6 ) , 7 , 0 ) ;
V_417 -> V_450 = V_466 / V_417 -> V_410 ;
V_417 -> V_451 = V_417 -> V_450 / V_417 -> V_411 ;
return 0 ;
}
T_2 F_265 ( void )
{
return F_3 ( V_435 ) ;
}
void F_60 ( T_2 V_404 )
{
F_1 ( V_435 , V_404 ) ;
}
T_2 F_266 ( void )
{
return F_3 ( V_436 ) ;
}
void F_267 ( T_2 V_404 )
{
T_2 V_470 = F_3 ( V_436 ) ;
F_60 ( ( V_404 ^ V_470 ) & V_404 ) ;
F_1 ( V_436 , V_404 ) ;
}
void F_268 ( void )
{
F_9 ( V_433 , 2 , 4 , 3 ) ;
}
void F_269 ( void )
{
F_9 ( V_433 , 1 , 4 , 3 ) ;
}
static void F_270 ( void )
{
T_2 V_248 ;
if ( F_14 ( V_43 ) ) {
V_248 = F_3 ( V_428 ) ;
V_248 = F_124 ( V_248 , 1 , 0 , 0 ) ;
V_248 = F_124 ( V_248 , 1 , 23 , 16 ) ;
F_1 ( V_428 , V_248 ) ;
V_3 . V_412 = F_245 () ;
}
if ( F_14 ( V_471 ) )
F_9 ( V_18 , 1 , 9 , 9 ) ;
F_96 () ;
F_220 ( V_472 ) ;
F_144 () ;
F_129 () ;
F_113 () ;
if ( V_3 . V_52 -> V_473 )
F_9 ( V_474 , 1 , 0 , 0 ) ;
if ( F_14 ( V_443 ) )
F_158 () ;
}
static int F_271 ( struct V_475 * V_48 )
{
const struct V_476 * V_477 ;
struct V_476 * V_478 ;
V_478 = F_272 ( & V_48 -> V_49 , sizeof( * V_478 ) , V_479 ) ;
if ( ! V_478 ) {
F_273 ( & V_48 -> V_49 , L_72 ) ;
return - V_480 ;
}
switch ( F_274 () ) {
case V_481 :
V_477 = & V_482 ;
break;
case V_483 :
V_477 = & V_484 ;
break;
case V_485 :
case V_486 :
case V_487 :
case V_488 :
V_477 = & V_489 ;
break;
case V_490 :
case V_491 :
case V_492 :
V_477 = & V_493 ;
break;
case V_494 :
case V_495 :
V_477 = & V_496 ;
break;
default:
return - V_497 ;
}
memcpy ( V_478 , V_477 , sizeof( * V_478 ) ) ;
V_3 . V_52 = V_478 ;
return 0 ;
}
static T_10 F_275 ( int V_498 , void * V_499 )
{
if ( ! V_3 . V_500 )
return V_501 ;
return V_3 . V_502 ( V_498 , V_3 . V_503 ) ;
}
int F_276 ( T_11 V_504 , void * V_505 )
{
int V_47 ;
if ( V_3 . V_502 != NULL )
return - V_506 ;
V_3 . V_502 = V_504 ;
V_3 . V_503 = V_505 ;
F_277 () ;
V_47 = F_278 ( & V_3 . V_48 -> V_49 , V_3 . V_498 , F_275 ,
V_507 , L_73 , & V_3 ) ;
if ( V_47 ) {
V_3 . V_502 = NULL ;
V_3 . V_503 = NULL ;
}
return V_47 ;
}
void F_279 ( void * V_505 )
{
F_280 ( & V_3 . V_48 -> V_49 , V_3 . V_498 , & V_3 ) ;
V_3 . V_502 = NULL ;
V_3 . V_503 = NULL ;
}
static int F_281 ( struct V_508 * V_49 , struct V_508 * V_509 , void * V_455 )
{
struct V_475 * V_48 = F_282 ( V_49 ) ;
T_2 V_510 ;
int V_47 = 0 ;
struct V_511 * V_512 ;
struct V_513 * V_514 = V_48 -> V_49 . V_515 ;
V_3 . V_48 = V_48 ;
F_283 ( & V_3 . V_20 ) ;
V_47 = F_271 ( V_3 . V_48 ) ;
if ( V_47 )
return V_47 ;
V_512 = F_284 ( V_3 . V_48 , V_516 , 0 ) ;
if ( ! V_512 ) {
F_76 ( L_74 ) ;
return - V_286 ;
}
V_3 . V_4 = F_285 ( & V_48 -> V_49 , V_512 -> V_173 ,
F_286 ( V_512 ) ) ;
if ( ! V_3 . V_4 ) {
F_76 ( L_75 ) ;
return - V_480 ;
}
V_3 . V_498 = F_287 ( V_3 . V_48 , 0 ) ;
if ( V_3 . V_498 < 0 ) {
F_76 ( L_76 ) ;
return - V_497 ;
}
if ( V_514 && F_288 ( V_514 , L_77 ) ) {
V_3 . V_403 = F_289 ( V_514 , L_77 ) ;
if ( F_290 ( V_3 . V_403 ) ) {
F_273 ( & V_48 -> V_49 , L_78 ) ;
return F_291 ( V_3 . V_403 ) ;
}
if ( F_292 ( V_514 , L_77 , 1 ,
& V_3 . V_405 ) ) {
F_273 ( & V_48 -> V_49 , L_79 ) ;
return - V_286 ;
}
}
F_293 ( & V_48 -> V_49 ) ;
V_47 = F_61 () ;
if ( V_47 )
goto V_517;
F_270 () ;
V_510 = F_3 ( V_432 ) ;
F_294 ( & V_48 -> V_49 , L_80 ,
F_126 ( V_510 , 7 , 4 ) , F_126 ( V_510 , 3 , 0 ) ) ;
F_64 () ;
F_295 () ;
F_296 ( L_81 , F_257 ) ;
return 0 ;
V_517:
F_297 ( & V_48 -> V_49 ) ;
return V_47 ;
}
static void F_298 ( struct V_508 * V_49 , struct V_508 * V_509 ,
void * V_455 )
{
F_297 ( V_49 ) ;
F_299 () ;
}
static int F_300 ( struct V_475 * V_48 )
{
return F_301 ( & V_48 -> V_49 , & V_518 ) ;
}
static int F_302 ( struct V_475 * V_48 )
{
F_303 ( & V_48 -> V_49 , & V_518 ) ;
return 0 ;
}
static int F_304 ( struct V_508 * V_49 )
{
V_3 . V_500 = false ;
F_277 () ;
F_305 ( V_3 . V_498 ) ;
F_11 () ;
return 0 ;
}
static int F_306 ( struct V_508 * V_49 )
{
if ( F_6 ( V_18 , 2 , 1 ) != V_472 ) {
F_270 () ;
F_58 () ;
}
V_3 . V_500 = true ;
F_277 () ;
return 0 ;
}
int T_12 F_307 ( void )
{
return F_308 ( & V_519 ) ;
}
void F_309 ( void )
{
F_310 ( & V_519 ) ;
}
