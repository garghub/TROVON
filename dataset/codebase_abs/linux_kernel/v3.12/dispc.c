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
F_8 ( V_10 . V_13 , V_2 , V_10 . V_14 , V_10 . V_15 ) ;
}
static void F_9 ( void )
{
int V_16 , V_17 ;
F_10 ( L_1 ) ;
F_11 ( V_18 ) ;
F_11 ( V_19 ) ;
F_11 ( V_20 ) ;
F_11 ( V_21 ) ;
if ( F_12 ( V_22 ) ||
F_12 ( V_23 ) )
F_11 ( V_24 ) ;
if ( F_12 ( V_25 ) ) {
F_11 ( V_26 ) ;
F_11 ( V_27 ) ;
}
if ( F_12 ( V_28 ) ) {
F_11 ( V_29 ) ;
F_11 ( V_30 ) ;
}
for ( V_16 = 0 ; V_16 < F_13 () ; V_16 ++ ) {
F_11 ( F_14 ( V_16 ) ) ;
F_11 ( F_15 ( V_16 ) ) ;
F_11 ( F_16 ( V_16 ) ) ;
if ( V_16 == V_31 )
continue;
F_11 ( F_17 ( V_16 ) ) ;
F_11 ( F_18 ( V_16 ) ) ;
F_11 ( F_19 ( V_16 ) ) ;
F_11 ( F_20 ( V_16 ) ) ;
F_11 ( F_21 ( V_16 ) ) ;
F_11 ( F_22 ( V_16 ) ) ;
F_11 ( F_23 ( V_16 ) ) ;
if ( F_12 ( V_32 ) ) {
F_11 ( F_24 ( V_16 ) ) ;
F_11 ( F_25 ( V_16 ) ) ;
F_11 ( F_26 ( V_16 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ ) {
F_11 ( F_28 ( V_16 ) ) ;
F_11 ( F_29 ( V_16 ) ) ;
F_11 ( F_30 ( V_16 ) ) ;
F_11 ( F_31 ( V_16 ) ) ;
F_11 ( F_32 ( V_16 ) ) ;
F_11 ( F_33 ( V_16 ) ) ;
F_11 ( F_34 ( V_16 ) ) ;
F_11 ( F_35 ( V_16 ) ) ;
if ( F_12 ( V_33 ) )
F_11 ( F_36 ( V_16 ) ) ;
if ( V_16 == V_34 ) {
F_11 ( F_37 ( V_16 ) ) ;
F_11 ( F_38 ( V_16 ) ) ;
continue;
}
F_11 ( F_39 ( V_16 ) ) ;
F_11 ( F_40 ( V_16 ) ) ;
F_11 ( F_41 ( V_16 ) ) ;
F_11 ( F_42 ( V_16 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_11 ( F_43 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_11 ( F_44 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ )
F_11 ( F_45 ( V_16 , V_17 ) ) ;
if ( F_12 ( V_35 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_11 ( F_46 ( V_16 , V_17 ) ) ;
}
if ( F_12 ( V_36 ) ) {
F_11 ( F_47 ( V_16 ) ) ;
F_11 ( F_48 ( V_16 ) ) ;
F_11 ( F_49 ( V_16 ) ) ;
F_11 ( F_50 ( V_16 ) ) ;
F_11 ( F_51 ( V_16 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_11 ( F_52 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_11 ( F_53 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_11 ( F_54 ( V_16 , V_17 ) ) ;
}
if ( F_12 ( V_37 ) )
F_11 ( F_55 ( V_16 ) ) ;
}
if ( F_12 ( V_38 ) )
F_11 ( V_39 ) ;
V_3 . V_40 = F_56 () ;
V_3 . V_41 = true ;
F_10 ( L_2 , V_3 . V_40 ) ;
}
static void F_57 ( void )
{
int V_16 , V_17 , V_42 ;
F_10 ( L_3 ) ;
if ( ! V_3 . V_41 )
return;
V_42 = F_56 () ;
if ( V_42 >= 0 && V_42 == V_3 . V_40 )
return;
F_10 ( L_4 ,
V_3 . V_40 , V_42 ) ;
F_58 ( V_20 ) ;
F_58 ( V_21 ) ;
if ( F_12 ( V_22 ) ||
F_12 ( V_23 ) )
F_58 ( V_24 ) ;
if ( F_12 ( V_25 ) )
F_58 ( V_27 ) ;
if ( F_12 ( V_28 ) )
F_58 ( V_30 ) ;
for ( V_16 = 0 ; V_16 < F_13 () ; V_16 ++ ) {
F_58 ( F_14 ( V_16 ) ) ;
F_58 ( F_15 ( V_16 ) ) ;
F_58 ( F_16 ( V_16 ) ) ;
if ( V_16 == V_31 )
continue;
F_58 ( F_17 ( V_16 ) ) ;
F_58 ( F_18 ( V_16 ) ) ;
F_58 ( F_19 ( V_16 ) ) ;
F_58 ( F_20 ( V_16 ) ) ;
F_58 ( F_21 ( V_16 ) ) ;
F_58 ( F_22 ( V_16 ) ) ;
F_58 ( F_23 ( V_16 ) ) ;
if ( F_12 ( V_32 ) ) {
F_58 ( F_24 ( V_16 ) ) ;
F_58 ( F_25 ( V_16 ) ) ;
F_58 ( F_26 ( V_16 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ ) {
F_58 ( F_28 ( V_16 ) ) ;
F_58 ( F_29 ( V_16 ) ) ;
F_58 ( F_30 ( V_16 ) ) ;
F_58 ( F_31 ( V_16 ) ) ;
F_58 ( F_32 ( V_16 ) ) ;
F_58 ( F_33 ( V_16 ) ) ;
F_58 ( F_34 ( V_16 ) ) ;
F_58 ( F_35 ( V_16 ) ) ;
if ( F_12 ( V_33 ) )
F_58 ( F_36 ( V_16 ) ) ;
if ( V_16 == V_34 ) {
F_58 ( F_37 ( V_16 ) ) ;
F_58 ( F_38 ( V_16 ) ) ;
continue;
}
F_58 ( F_39 ( V_16 ) ) ;
F_58 ( F_40 ( V_16 ) ) ;
F_58 ( F_41 ( V_16 ) ) ;
F_58 ( F_42 ( V_16 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_58 ( F_43 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_58 ( F_44 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ )
F_58 ( F_45 ( V_16 , V_17 ) ) ;
if ( F_12 ( V_35 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_58 ( F_46 ( V_16 , V_17 ) ) ;
}
if ( F_12 ( V_36 ) ) {
F_58 ( F_47 ( V_16 ) ) ;
F_58 ( F_48 ( V_16 ) ) ;
F_58 ( F_49 ( V_16 ) ) ;
F_58 ( F_50 ( V_16 ) ) ;
F_58 ( F_51 ( V_16 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_58 ( F_52 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_58 ( F_53 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_58 ( F_54 ( V_16 , V_17 ) ) ;
}
if ( F_12 ( V_37 ) )
F_58 ( F_55 ( V_16 ) ) ;
}
if ( F_12 ( V_38 ) )
F_58 ( V_39 ) ;
F_58 ( V_19 ) ;
if ( F_12 ( V_25 ) )
F_58 ( V_26 ) ;
if ( F_12 ( V_28 ) )
F_58 ( V_29 ) ;
F_59 ( V_43 ) ;
F_58 ( V_18 ) ;
F_10 ( L_5 ) ;
}
int F_60 ( void )
{
int V_44 ;
F_10 ( L_6 ) ;
V_44 = F_61 ( & V_3 . V_45 -> V_46 ) ;
F_62 ( V_44 < 0 ) ;
return V_44 < 0 ? V_44 : 0 ;
}
void F_63 ( void )
{
int V_44 ;
F_10 ( L_7 ) ;
V_44 = F_64 ( & V_3 . V_45 -> V_46 ) ;
F_62 ( V_44 < 0 && V_44 != - V_47 ) ;
}
T_2 F_65 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_48 ;
}
T_2 F_66 ( enum V_5 V_6 )
{
if ( V_6 == V_31 && V_3 . V_49 -> V_50 )
return 0 ;
return V_11 [ V_6 ] . V_51 ;
}
T_2 F_67 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_52 ;
}
T_2 F_68 ( void )
{
return V_53 ;
}
bool F_69 ( enum V_5 V_6 )
{
return F_5 ( V_6 , V_54 ) == 1 ;
}
void F_70 ( enum V_5 V_6 )
{
F_62 ( F_71 ( V_6 ) == false ) ;
F_62 ( F_69 ( V_6 ) ) ;
F_10 ( L_8 , V_11 [ V_6 ] . V_55 ) ;
F_7 ( V_6 , V_54 , 1 ) ;
}
bool F_72 ( void )
{
return F_6 ( V_56 , 6 , 6 ) == 1 ;
}
void F_73 ( void )
{
enum V_57 V_58 = V_59 ;
bool V_60 , V_61 ;
V_60 = F_6 ( F_74 ( V_58 ) , 0 , 0 ) == 1 ;
if ( ! V_60 )
return;
V_61 = F_6 ( V_56 , 6 , 6 ) == 1 ;
if ( V_61 ) {
F_75 ( L_9 ) ;
return;
}
F_8 ( V_56 , 1 , 6 , 6 ) ;
}
static void F_76 ( enum V_57 V_58 , int V_13 , T_2 V_62 )
{
F_1 ( F_77 ( V_58 , V_13 ) , V_62 ) ;
}
static void F_78 ( enum V_57 V_58 , int V_13 , T_2 V_62 )
{
F_1 ( F_79 ( V_58 , V_13 ) , V_62 ) ;
}
static void F_80 ( enum V_57 V_58 , int V_13 , T_2 V_62 )
{
F_1 ( F_81 ( V_58 , V_13 ) , V_62 ) ;
}
static void F_82 ( enum V_57 V_58 , int V_13 , T_2 V_62 )
{
F_83 ( V_58 == V_34 ) ;
F_1 ( F_84 ( V_58 , V_13 ) , V_62 ) ;
}
static void F_85 ( enum V_57 V_58 , int V_13 ,
T_2 V_62 )
{
F_83 ( V_58 == V_34 ) ;
F_1 ( F_86 ( V_58 , V_13 ) , V_62 ) ;
}
static void F_87 ( enum V_57 V_58 , int V_13 , T_2 V_62 )
{
F_83 ( V_58 == V_34 ) ;
F_1 ( F_88 ( V_58 , V_13 ) , V_62 ) ;
}
static void F_89 ( enum V_57 V_58 , int V_63 ,
int V_64 , int V_65 ,
enum V_66 V_67 )
{
const struct V_68 * V_69 , * V_70 ;
int V_16 ;
V_69 = F_90 ( V_63 , true ) ;
V_70 = F_90 ( V_64 , V_65 ) ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
T_2 V_71 , V_72 ;
V_71 = F_91 ( V_69 [ V_16 ] . V_73 , 7 , 0 )
| F_91 ( V_69 [ V_16 ] . V_74 , 15 , 8 )
| F_91 ( V_69 [ V_16 ] . V_75 , 23 , 16 )
| F_91 ( V_69 [ V_16 ] . V_76 , 31 , 24 ) ;
V_72 = F_91 ( V_69 [ V_16 ] . V_77 , 7 , 0 )
| F_91 ( V_70 [ V_16 ] . V_74 , 15 , 8 )
| F_91 ( V_70 [ V_16 ] . V_75 , 23 , 16 )
| F_91 ( V_70 [ V_16 ] . V_76 , 31 , 24 ) ;
if ( V_67 == V_78 ) {
F_76 ( V_58 , V_16 , V_71 ) ;
F_78 ( V_58 , V_16 , V_72 ) ;
} else {
F_82 ( V_58 , V_16 , V_71 ) ;
F_85 ( V_58 , V_16 , V_72 ) ;
}
}
if ( V_65 ) {
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
T_2 V_79 ;
V_79 = F_91 ( V_70 [ V_16 ] . V_73 , 7 , 0 )
| F_91 ( V_70 [ V_16 ] . V_77 , 15 , 8 ) ;
if ( V_67 == V_78 )
F_80 ( V_58 , V_16 , V_79 ) ;
else
F_87 ( V_58 , V_16 , V_79 ) ;
}
}
}
static void F_92 ( enum V_57 V_58 ,
const struct V_80 * V_81 )
{
#define F_93 ( T_3 , T_4 ) (FLD_VAL(x, 26, 16) | FLD_VAL(y, 10, 0))
F_1 ( F_94 ( V_58 , 0 ) , F_93 ( V_81 -> V_82 , V_81 -> V_83 ) ) ;
F_1 ( F_94 ( V_58 , 1 ) , F_93 ( V_81 -> V_84 , V_81 -> V_85 ) ) ;
F_1 ( F_94 ( V_58 , 2 ) , F_93 ( V_81 -> V_86 , V_81 -> V_87 ) ) ;
F_1 ( F_94 ( V_58 , 3 ) , F_93 ( V_81 -> V_88 , V_81 -> V_89 ) ) ;
F_1 ( F_94 ( V_58 , 4 ) , F_93 ( 0 , V_81 -> V_90 ) ) ;
F_8 ( F_74 ( V_58 ) , V_81 -> V_91 , 11 , 11 ) ;
#undef F_93
}
static void F_95 ( void )
{
int V_16 ;
int V_92 = F_27 () ;
int V_93 = F_96 () ;
const struct V_80 V_94 = {
298 , 409 , 0 , 298 , - 208 , - 100 , 298 , 0 , 517 , 0 ,
} ;
const struct V_80 V_95 = {
66 , 112 , - 38 , 129 , - 94 , - 74 , 25 , - 18 , 112 , 0 ,
} ;
for ( V_16 = 1 ; V_16 < V_92 ; V_16 ++ )
F_92 ( V_16 , & V_94 ) ;
for (; V_16 < V_93 ; V_16 ++ )
F_92 ( V_16 , & V_95 ) ;
}
static void F_97 ( enum V_57 V_58 , T_2 V_96 )
{
F_1 ( F_98 ( V_58 ) , V_96 ) ;
}
static void F_99 ( enum V_57 V_58 , T_2 V_96 )
{
F_1 ( F_100 ( V_58 ) , V_96 ) ;
}
static void F_101 ( enum V_57 V_58 , T_2 V_96 )
{
F_1 ( F_102 ( V_58 ) , V_96 ) ;
}
static void F_103 ( enum V_57 V_58 , T_2 V_96 )
{
F_1 ( F_104 ( V_58 ) , V_96 ) ;
}
static void F_105 ( enum V_57 V_58 ,
enum V_97 V_98 , int T_3 , int T_4 )
{
T_2 V_2 ;
if ( ( V_98 & V_99 ) == 0 )
return;
V_2 = F_91 ( T_4 , 26 , 16 ) | F_91 ( T_3 , 10 , 0 ) ;
F_1 ( F_106 ( V_58 ) , V_2 ) ;
}
static void F_107 ( enum V_57 V_58 , int V_100 ,
int V_101 )
{
T_2 V_2 = F_91 ( V_101 - 1 , 26 , 16 ) | F_91 ( V_100 - 1 , 10 , 0 ) ;
if ( V_58 == V_34 || V_58 == V_59 )
F_1 ( F_108 ( V_58 ) , V_2 ) ;
else
F_1 ( F_109 ( V_58 ) , V_2 ) ;
}
static void F_110 ( enum V_57 V_58 , int V_100 ,
int V_101 )
{
T_2 V_2 ;
F_83 ( V_58 == V_34 ) ;
V_2 = F_91 ( V_101 - 1 , 26 , 16 ) | F_91 ( V_100 - 1 , 10 , 0 ) ;
if ( V_58 == V_59 )
F_1 ( F_109 ( V_58 ) , V_2 ) ;
else
F_1 ( F_108 ( V_58 ) , V_2 ) ;
}
static void F_111 ( enum V_57 V_58 ,
enum V_97 V_98 , T_5 V_102 )
{
if ( ( V_98 & V_103 ) == 0 )
return;
F_8 ( F_74 ( V_58 ) , V_102 , 27 , 26 ) ;
}
static void F_112 ( void )
{
int V_16 ;
if ( ! F_12 ( V_23 ) )
return;
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ )
F_8 ( F_74 ( V_16 ) , 1 , 25 , 25 ) ;
}
static void F_113 ( enum V_57 V_58 ,
enum V_97 V_98 , bool V_60 )
{
if ( ( V_98 & V_104 ) == 0 )
return;
F_8 ( F_74 ( V_58 ) , V_60 ? 1 : 0 , 28 , 28 ) ;
}
static void F_114 ( enum V_57 V_58 ,
enum V_97 V_98 , T_5 V_105 )
{
static const unsigned V_106 [] = { 0 , 8 , 16 , 24 , } ;
int V_107 ;
if ( ( V_98 & V_108 ) == 0 )
return;
V_107 = V_106 [ V_58 ] ;
F_8 ( V_109 , V_105 , V_107 + 7 , V_107 ) ;
}
static void F_115 ( enum V_57 V_58 , T_6 V_110 )
{
F_1 ( F_116 ( V_58 ) , V_110 ) ;
}
static void F_117 ( enum V_57 V_58 , T_6 V_110 )
{
F_1 ( F_118 ( V_58 ) , V_110 ) ;
}
static void F_119 ( enum V_57 V_58 ,
enum V_111 V_112 )
{
T_2 V_113 = 0 ;
if ( V_58 != V_34 ) {
switch ( V_112 ) {
case V_114 :
V_113 = 0x0 ; break;
case V_115 :
V_113 = 0x1 ; break;
case V_116 :
V_113 = 0x2 ; break;
case V_117 :
V_113 = 0x4 ; break;
case V_118 :
V_113 = 0x5 ; break;
case V_119 :
V_113 = 0x6 ; break;
case V_120 :
V_113 = 0x7 ; break;
case V_121 :
V_113 = 0x8 ; break;
case V_122 :
V_113 = 0x9 ; break;
case V_123 :
V_113 = 0xa ; break;
case V_124 :
V_113 = 0xb ; break;
case V_125 :
V_113 = 0xc ; break;
case V_126 :
V_113 = 0xd ; break;
case V_127 :
V_113 = 0xe ; break;
case V_128 :
V_113 = 0xf ; break;
default:
F_120 () ; return;
}
} else {
switch ( V_112 ) {
case V_129 :
V_113 = 0x0 ; break;
case V_130 :
V_113 = 0x1 ; break;
case V_131 :
V_113 = 0x2 ; break;
case V_132 :
V_113 = 0x3 ; break;
case V_117 :
V_113 = 0x4 ; break;
case V_118 :
V_113 = 0x5 ; break;
case V_119 :
V_113 = 0x6 ; break;
case V_120 :
V_113 = 0x7 ; break;
case V_121 :
V_113 = 0x8 ; break;
case V_122 :
V_113 = 0x9 ; break;
case V_115 :
V_113 = 0xa ; break;
case V_116 :
V_113 = 0xb ; break;
case V_125 :
V_113 = 0xc ; break;
case V_126 :
V_113 = 0xd ; break;
case V_127 :
V_113 = 0xe ; break;
case V_128 :
V_113 = 0xf ; break;
default:
F_120 () ; return;
}
}
F_8 ( F_74 ( V_58 ) , V_113 , 4 , 1 ) ;
}
static void F_121 ( enum V_57 V_58 ,
enum V_133 V_134 )
{
if ( F_12 ( V_135 ) == 0 )
return;
if ( V_134 == V_136 )
F_8 ( F_74 ( V_58 ) , 1 , 29 , 29 ) ;
else
F_8 ( F_74 ( V_58 ) , 0 , 29 , 29 ) ;
}
void F_122 ( enum V_57 V_58 , enum V_5 V_6 )
{
int V_107 ;
T_2 V_2 ;
int V_137 = 0 , V_138 = 0 ;
switch ( V_58 ) {
case V_34 :
V_107 = 8 ;
break;
case V_139 :
case V_140 :
case V_141 :
V_107 = 16 ;
break;
default:
F_120 () ;
return;
}
V_2 = F_3 ( F_74 ( V_58 ) ) ;
if ( F_12 ( V_25 ) ) {
switch ( V_6 ) {
case V_142 :
V_137 = 0 ;
V_138 = 0 ;
break;
case V_31 :
V_137 = 1 ;
V_138 = 0 ;
break;
case V_143 :
V_137 = 0 ;
V_138 = 1 ;
break;
case V_144 :
if ( F_12 ( V_28 ) ) {
V_137 = 0 ;
V_138 = 2 ;
} else {
F_120 () ;
return;
}
break;
default:
F_120 () ;
return;
}
V_2 = F_123 ( V_2 , V_137 , V_107 , V_107 ) ;
V_2 = F_123 ( V_2 , V_138 , 31 , 30 ) ;
} else {
V_2 = F_123 ( V_2 , V_6 , V_107 , V_107 ) ;
}
F_1 ( F_74 ( V_58 ) , V_2 ) ;
}
static enum V_5 F_124 ( enum V_57 V_58 )
{
int V_107 ;
T_2 V_2 ;
enum V_5 V_6 ;
switch ( V_58 ) {
case V_34 :
V_107 = 8 ;
break;
case V_139 :
case V_140 :
case V_141 :
V_107 = 16 ;
break;
default:
F_120 () ;
return 0 ;
}
V_2 = F_3 ( F_74 ( V_58 ) ) ;
if ( F_12 ( V_28 ) ) {
if ( F_125 ( V_2 , 31 , 30 ) == 0 )
V_6 = F_125 ( V_2 , V_107 , V_107 ) ;
else if ( F_125 ( V_2 , 31 , 30 ) == 1 )
V_6 = V_143 ;
else
V_6 = V_144 ;
} else if ( F_12 ( V_25 ) ) {
if ( F_125 ( V_2 , 31 , 30 ) == 0 )
V_6 = F_125 ( V_2 , V_107 , V_107 ) ;
else
V_6 = V_143 ;
} else {
V_6 = F_125 ( V_2 , V_107 , V_107 ) ;
}
return V_6 ;
}
void F_126 ( enum V_145 V_6 )
{
enum V_57 V_58 = V_59 ;
F_8 ( F_74 ( V_58 ) , V_6 , 18 , 16 ) ;
}
static void F_127 ( enum V_57 V_58 ,
enum V_146 V_147 )
{
static const unsigned V_106 [] = { 6 , 14 , 14 , 14 , 14 , } ;
int V_107 ;
V_107 = V_106 [ V_58 ] ;
F_8 ( F_74 ( V_58 ) , V_147 , V_107 + 1 , V_107 ) ;
}
static void F_128 ( void )
{
int V_16 ;
const int V_147 = V_148 ;
for ( V_16 = 0 ; V_16 < F_27 () ; ++ V_16 )
F_127 ( V_16 , V_147 ) ;
}
static T_2 F_129 ( enum V_57 V_58 )
{
unsigned V_149 = F_130 () ;
return V_149 * 8 ;
}
void F_131 ( bool V_60 )
{
if ( V_60 ) {
F_132 ( L_10 ) ;
return;
}
F_8 ( V_150 , V_60 , 9 , 9 ) ;
}
static void F_133 ( enum V_5 V_6 , bool V_60 )
{
if ( V_6 == V_31 )
return;
F_7 ( V_6 , V_151 , V_60 ) ;
}
static void F_134 ( enum V_5 V_6 ,
const struct V_152 * V_153 )
{
T_2 V_154 , V_155 , V_156 ;
if ( ! F_135 ( V_6 ) )
return;
V_154 = F_91 ( V_153 -> V_157 , 31 , 22 ) | F_91 ( V_153 -> V_158 , 20 , 11 ) |
F_91 ( V_153 -> V_159 , 9 , 0 ) ;
V_155 = F_91 ( V_153 -> V_160 , 31 , 22 ) | F_91 ( V_153 -> V_161 , 20 , 11 ) |
F_91 ( V_153 -> V_162 , 9 , 0 ) ;
V_156 = F_91 ( V_153 -> V_163 , 31 , 22 ) | F_91 ( V_153 -> V_164 , 20 , 11 ) |
F_91 ( V_153 -> V_165 , 9 , 0 ) ;
F_1 ( F_136 ( V_6 ) , V_154 ) ;
F_1 ( F_137 ( V_6 ) , V_155 ) ;
F_1 ( F_138 ( V_6 ) , V_156 ) ;
}
static void F_139 ( enum V_57 V_58 , bool V_60 )
{
T_2 V_2 ;
F_83 ( V_58 == V_34 ) ;
V_2 = F_3 ( F_74 ( V_58 ) ) ;
V_2 = F_123 ( V_2 , V_60 , 9 , 9 ) ;
F_1 ( F_74 ( V_58 ) , V_2 ) ;
}
static void F_140 ( enum V_57 V_58 ,
enum V_97 V_98 , bool V_60 )
{
static const unsigned V_106 [] = { 5 , 10 , 10 , 10 } ;
int V_107 ;
if ( ( V_98 & V_166 ) == 0 )
return;
V_107 = V_106 [ V_58 ] ;
F_8 ( F_74 ( V_58 ) , V_60 , V_107 , V_107 ) ;
}
static void F_141 ( enum V_5 V_6 , T_1 V_100 ,
T_1 V_101 )
{
T_2 V_2 ;
V_2 = F_91 ( V_101 - 1 , V_3 . V_49 -> V_167 , 16 ) |
F_91 ( V_100 - 1 , V_3 . V_49 -> V_168 , 0 ) ;
F_1 ( F_142 ( V_6 ) , V_2 ) ;
}
static void F_143 ( void )
{
T_2 V_169 ;
int V_170 ;
T_5 V_171 , V_172 ;
T_2 V_149 ;
V_149 = F_144 () ;
F_145 ( V_173 , & V_171 , & V_172 ) ;
for ( V_170 = 0 ; V_170 < V_3 . V_49 -> V_174 ; ++ V_170 ) {
V_169 = F_6 ( F_146 ( V_170 ) , V_171 , V_172 ) ;
V_169 *= V_149 ;
V_3 . V_175 [ V_170 ] = V_169 ;
V_3 . V_176 [ V_170 ] = V_170 ;
}
if ( V_3 . V_49 -> V_177 ) {
T_2 V_79 ;
V_79 = F_3 ( V_178 ) ;
V_79 = F_123 ( V_79 , 4 , 2 , 0 ) ;
V_79 = F_123 ( V_79 , 4 , 5 , 3 ) ;
V_79 = F_123 ( V_79 , 0 , 26 , 24 ) ;
V_79 = F_123 ( V_79 , 0 , 29 , 27 ) ;
F_1 ( V_178 , V_79 ) ;
V_3 . V_176 [ V_34 ] = V_59 ;
V_3 . V_176 [ V_59 ] = V_34 ;
}
}
static T_2 F_147 ( enum V_57 V_58 )
{
int V_170 ;
T_2 V_169 = 0 ;
for ( V_170 = 0 ; V_170 < V_3 . V_49 -> V_174 ; ++ V_170 ) {
if ( V_3 . V_176 [ V_170 ] == V_58 )
V_169 += V_3 . V_175 [ V_170 ] ;
}
return V_169 ;
}
void F_148 ( enum V_57 V_58 , T_2 V_15 , T_2 V_14 )
{
T_5 V_179 , V_180 , V_181 , V_182 ;
T_2 V_149 ;
V_149 = F_144 () ;
F_62 ( V_15 % V_149 != 0 ) ;
F_62 ( V_14 % V_149 != 0 ) ;
V_15 /= V_149 ;
V_14 /= V_149 ;
F_145 ( V_183 , & V_179 , & V_180 ) ;
F_145 ( V_184 , & V_181 , & V_182 ) ;
F_10 ( L_11 ,
V_58 ,
F_6 ( F_149 ( V_58 ) ,
V_181 , V_182 ) * V_149 ,
F_6 ( F_149 ( V_58 ) ,
V_179 , V_180 ) * V_149 ,
V_15 * V_149 , V_14 * V_149 ) ;
F_1 ( F_149 ( V_58 ) ,
F_91 ( V_14 , V_179 , V_180 ) |
F_91 ( V_15 , V_181 , V_182 ) ) ;
}
void F_150 ( bool V_60 )
{
if ( ! F_12 ( V_185 ) ) {
F_62 ( V_60 ) ;
return;
}
F_10 ( L_12 , V_60 ? L_13 : L_14 ) ;
F_8 ( V_150 , V_60 ? 1 : 0 , 14 , 14 ) ;
}
void F_151 ( enum V_57 V_58 ,
T_2 * V_186 , T_2 * V_187 , bool V_188 ,
bool V_189 )
{
unsigned V_190 = F_144 () ;
unsigned V_191 , V_192 , V_147 ;
int V_16 ;
V_147 = F_129 ( V_58 ) ;
V_191 = F_147 ( V_58 ) ;
if ( V_188 ) {
V_192 = 0 ;
for ( V_16 = 0 ; V_16 < F_27 () ; ++ V_16 )
V_192 += F_147 ( V_16 ) ;
} else {
V_192 = V_191 ;
}
if ( V_189 && F_12 ( V_193 ) ) {
* V_186 = V_191 - V_147 * 2 ;
* V_187 = V_192 - V_147 ;
} else if ( V_58 == V_59 ) {
* V_186 = 0 ;
* V_187 = V_147 ;
} else {
* V_186 = V_191 - V_147 ;
* V_187 = V_192 - V_190 ;
}
}
static void F_152 ( enum V_57 V_58 ,
int V_194 , int V_195 ,
enum V_66 V_67 )
{
T_2 V_2 ;
if ( V_67 == V_78 ) {
T_5 V_196 , V_197 , V_198 , V_199 ;
F_145 ( V_200 ,
& V_196 , & V_197 ) ;
F_145 ( V_201 ,
& V_198 , & V_199 ) ;
V_2 = F_91 ( V_195 , V_198 , V_199 ) |
F_91 ( V_194 , V_196 , V_197 ) ;
F_1 ( F_153 ( V_58 ) , V_2 ) ;
} else {
V_2 = F_91 ( V_195 , 28 , 16 ) | F_91 ( V_194 , 12 , 0 ) ;
F_1 ( F_154 ( V_58 ) , V_2 ) ;
}
}
static void F_155 ( enum V_57 V_58 , int V_202 , int V_203 )
{
T_2 V_2 ;
T_5 V_204 , V_205 , V_206 , V_207 ;
F_145 ( V_208 , & V_204 , & V_205 ) ;
F_145 ( V_209 , & V_206 , & V_207 ) ;
V_2 = F_91 ( V_203 , V_206 , V_207 ) |
F_91 ( V_202 , V_204 , V_205 ) ;
F_1 ( F_156 ( V_58 ) , V_2 ) ;
}
static void F_157 ( enum V_57 V_58 , int V_202 , int V_203 )
{
T_2 V_2 ;
T_5 V_204 , V_205 , V_206 , V_207 ;
F_145 ( V_208 , & V_204 , & V_205 ) ;
F_145 ( V_209 , & V_206 , & V_207 ) ;
V_2 = F_91 ( V_203 , V_206 , V_207 ) |
F_91 ( V_202 , V_204 , V_205 ) ;
F_1 ( F_158 ( V_58 ) , V_2 ) ;
}
static void F_159 ( enum V_57 V_58 , int V_202 ,
int V_203 )
{
T_2 V_2 ;
V_2 = F_91 ( V_203 , 26 , 16 ) | F_91 ( V_202 , 10 , 0 ) ;
F_1 ( F_160 ( V_58 ) , V_2 ) ;
}
static void F_161 ( enum V_57 V_58 , int V_202 ,
int V_203 )
{
T_2 V_2 ;
V_2 = F_91 ( V_203 , 26 , 16 ) | F_91 ( V_202 , 10 , 0 ) ;
F_1 ( F_162 ( V_58 ) , V_2 ) ;
}
static void F_163 ( enum V_57 V_58 ,
T_1 V_210 , T_1 V_211 ,
T_1 V_212 , T_1 V_213 ,
bool V_65 , T_5 V_214 ,
enum V_66 V_67 )
{
int V_63 , V_64 ;
V_63 = 1024 * V_210 / V_212 ;
V_64 = 1024 * V_211 / V_213 ;
F_89 ( V_58 , V_63 , V_64 , V_65 ,
V_67 ) ;
F_152 ( V_58 , V_63 , V_64 , V_67 ) ;
}
static void F_164 ( enum V_57 V_58 ,
T_1 V_210 , T_1 V_211 , T_1 V_212 , T_1 V_213 ,
bool V_215 , enum V_111 V_112 , T_5 V_214 )
{
int V_216 , V_217 ;
int V_218 , V_219 ;
int V_220 , V_221 ;
int V_1 ;
struct V_222 {
T_7 V_223 , V_224 ;
T_7 V_225 , V_226 ;
T_7 V_227 , V_228 ;
T_7 V_229 , V_230 ;
};
const struct V_222 * V_231 ;
const struct V_222 * V_232 ;
static const struct V_222 V_233 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ 1 , 2 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ - 1 , 2 , - 1 , 2 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_222 V_234 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 3 , 4 , - 1 , 4 } ,
{ - 1 , 4 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 4 , - 3 , 4 } ,
{ - 3 , 4 , - 3 , 4 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_222 V_235 [ 4 ] = {
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , - 1 , 1 , 0 , 1 } ,
} ;
switch ( V_214 ) {
case V_236 :
V_1 = 0 ;
break;
case V_237 :
V_1 = 1 ;
break;
case V_238 :
V_1 = 2 ;
break;
case V_239 :
V_1 = 3 ;
break;
default:
F_120 () ;
return;
}
switch ( V_112 ) {
case V_114 :
if ( V_215 )
V_231 = V_234 ;
else
V_231 = V_233 ;
break;
case V_123 :
case V_124 :
V_231 = V_235 ;
break;
default:
F_120 () ;
return;
}
V_232 = & V_231 [ V_1 ] ;
V_220 = 1024 * V_210 / V_212 ;
V_221 = 1024 * V_211 / V_213 ;
V_216 = ( V_232 -> V_223 * V_220 / V_232 -> V_224 ) % 1024 ;
V_217 = ( V_232 -> V_225 * V_220 / V_232 -> V_226 ) % 1024 ;
V_218 = ( V_232 -> V_227 * V_221 / V_232 -> V_228 ) % 1024 ;
V_219 = ( V_232 -> V_229 * V_221 / V_232 -> V_230 ) % 1024 ;
F_159 ( V_58 , V_216 , V_218 ) ;
F_161 ( V_58 , V_217 , V_219 ) ;
}
static void F_165 ( enum V_57 V_58 ,
T_1 V_210 , T_1 V_211 ,
T_1 V_212 , T_1 V_213 ,
bool V_215 , bool V_65 ,
bool V_240 , enum V_111 V_112 ,
T_5 V_214 )
{
int V_241 = 0 ;
int V_242 = 0 ;
T_2 V_243 ;
F_163 ( V_58 , V_210 , V_211 ,
V_212 , V_213 , V_65 ,
V_214 , V_78 ) ;
V_243 = F_3 ( F_74 ( V_58 ) ) ;
V_243 &= ~ ( ( 0x3 << 5 ) | ( 0x1 << 21 ) ) ;
V_243 |= ( V_210 != V_212 ) ? ( 1 << 5 ) : 0 ;
V_243 |= ( V_211 != V_213 ) ? ( 1 << 6 ) : 0 ;
V_243 |= V_65 ? ( 1 << 21 ) : 0 ;
if ( F_12 ( V_244 ) ) {
V_243 &= ~ ( 0x3 << 7 ) ;
V_243 |= ( V_210 <= V_212 ) ? 0 : ( 1 << 7 ) ;
V_243 |= ( V_211 <= V_213 ) ? 0 : ( 1 << 8 ) ;
}
if ( F_12 ( V_245 ) ) {
V_243 &= ~ ( 0x1 << 22 ) ;
V_243 |= V_65 ? ( 1 << 22 ) : 0 ;
}
F_1 ( F_74 ( V_58 ) , V_243 ) ;
if ( V_215 && ! V_240 ) {
V_242 = 0 ;
V_241 = ( ( 1024 * V_211 / V_213 ) / 2 ) & 0x3ff ;
if ( V_241 >= 1024 / 2 ) {
V_242 = 1024 / 2 ;
V_241 -= V_242 ;
}
}
F_155 ( V_58 , 0 , V_241 ) ;
F_157 ( V_58 , 0 , V_242 ) ;
}
static void F_166 ( enum V_57 V_58 ,
T_1 V_210 , T_1 V_211 ,
T_1 V_212 , T_1 V_213 ,
bool V_215 , bool V_65 ,
bool V_240 , enum V_111 V_112 ,
T_5 V_214 )
{
int V_246 = V_212 != V_210 ;
int V_247 = V_213 != V_211 ;
bool V_248 = V_58 != V_59 ? true : false ;
if ( ! F_12 ( V_36 ) )
return;
if ( ( V_112 != V_123 &&
V_112 != V_124 &&
V_112 != V_114 ) ) {
if ( V_58 != V_59 )
F_8 ( F_167 ( V_58 ) , 0 , 8 , 8 ) ;
return;
}
F_164 ( V_58 , V_210 , V_211 , V_212 ,
V_213 , V_215 , V_112 , V_214 ) ;
switch ( V_112 ) {
case V_114 :
if ( V_248 ) {
V_211 >>= 1 ;
V_210 >>= 1 ;
} else {
V_211 <<= 1 ;
V_210 <<= 1 ;
}
break;
case V_123 :
case V_124 :
if ( V_214 == V_236 ||
V_214 == V_238 ) {
if ( V_248 )
V_210 >>= 1 ;
else
V_210 <<= 1 ;
}
if ( V_214 != V_236 )
V_246 = V_247 = true ;
break;
default:
F_120 () ;
return;
}
if ( V_212 != V_210 )
V_246 = true ;
if ( V_213 != V_211 )
V_247 = true ;
F_163 ( V_58 , V_210 , V_211 ,
V_212 , V_213 , V_65 ,
V_214 , V_249 ) ;
if ( V_58 != V_59 )
F_8 ( F_167 ( V_58 ) ,
( V_246 || V_247 ) ? 1 : 0 , 8 , 8 ) ;
F_8 ( F_74 ( V_58 ) , V_246 ? 1 : 0 , 5 , 5 ) ;
F_8 ( F_74 ( V_58 ) , V_247 ? 1 : 0 , 6 , 6 ) ;
}
static void F_168 ( enum V_57 V_58 ,
T_1 V_210 , T_1 V_211 ,
T_1 V_212 , T_1 V_213 ,
bool V_215 , bool V_65 ,
bool V_240 , enum V_111 V_112 ,
T_5 V_214 )
{
F_83 ( V_58 == V_34 ) ;
F_165 ( V_58 ,
V_210 , V_211 ,
V_212 , V_213 ,
V_215 , V_65 ,
V_240 , V_112 ,
V_214 ) ;
F_166 ( V_58 ,
V_210 , V_211 ,
V_212 , V_213 ,
V_215 , V_65 ,
V_240 , V_112 ,
V_214 ) ;
}
static void F_169 ( enum V_57 V_58 , T_5 V_214 ,
enum V_133 V_134 ,
bool V_250 , enum V_111 V_112 )
{
bool V_251 = false ;
int V_252 = 0 ;
if ( V_112 == V_123 ||
V_112 == V_124 ) {
if ( V_250 ) {
switch ( V_214 ) {
case V_236 :
V_252 = 2 ;
break;
case V_237 :
V_252 = 1 ;
break;
case V_238 :
V_252 = 0 ;
break;
case V_239 :
V_252 = 3 ;
break;
}
} else {
switch ( V_214 ) {
case V_236 :
V_252 = 0 ;
break;
case V_237 :
V_252 = 1 ;
break;
case V_238 :
V_252 = 2 ;
break;
case V_239 :
V_252 = 3 ;
break;
}
}
if ( V_214 == V_237 || V_214 == V_239 )
V_251 = true ;
else
V_251 = false ;
}
F_8 ( F_74 ( V_58 ) , V_252 , 13 , 12 ) ;
if ( F_12 ( V_253 ) )
F_8 ( F_74 ( V_58 ) ,
V_251 ? 1 : 0 , 18 , 18 ) ;
if ( V_112 == V_114 ) {
bool V_254 = ( V_134 == V_136 ) &&
( V_214 == V_236 ||
V_214 == V_238 ) ;
F_8 ( F_74 ( V_58 ) , V_254 , 22 , 22 ) ;
}
}
static int F_170 ( enum V_111 V_112 )
{
switch ( V_112 ) {
case V_129 :
return 1 ;
case V_130 :
return 2 ;
case V_131 :
return 4 ;
case V_132 :
case V_114 :
return 8 ;
case V_117 :
case V_119 :
case V_118 :
case V_123 :
case V_124 :
case V_116 :
case V_115 :
case V_120 :
case V_128 :
return 16 ;
case V_122 :
return 24 ;
case V_121 :
case V_125 :
case V_126 :
case V_127 :
return 32 ;
default:
F_120 () ;
return 0 ;
}
}
static T_6 F_171 ( int V_255 , T_5 V_256 )
{
if ( V_255 == 1 )
return 1 ;
else if ( V_255 > 1 )
return 1 + ( V_255 - 1 ) * V_256 ;
else if ( V_255 < 0 )
return 1 - ( - V_255 + 1 ) * V_256 ;
else
F_120 () ;
return 0 ;
}
static void F_172 ( T_5 V_214 , bool V_257 ,
T_1 V_258 ,
T_1 V_100 , T_1 V_101 ,
enum V_111 V_112 , bool V_240 ,
unsigned int V_259 ,
unsigned * V_260 , unsigned * V_261 ,
T_6 * V_262 , T_6 * V_263 , int V_264 , int V_265 )
{
T_5 V_256 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
case V_123 :
case V_124 :
V_256 = 4 ;
break;
default:
V_256 = F_170 ( V_112 ) / 8 ;
break;
}
F_10 ( L_15 , V_214 , V_258 ,
V_100 , V_101 ) ;
switch ( V_214 + V_257 * 4 ) {
case V_236 :
case V_238 :
if ( V_112 == V_123 ||
V_112 == V_124 )
V_100 = V_100 >> 1 ;
case V_237 :
case V_239 :
* V_261 = 0 ;
if ( V_259 )
* V_260 = V_259 * V_258 * V_256 ;
else
* V_260 = 0 ;
* V_262 = F_171 ( 1 +
( V_265 * V_258 - V_264 * V_100 ) +
( V_240 ? V_258 : 0 ) , V_256 ) ;
* V_263 = F_171 ( V_264 , V_256 ) ;
break;
case V_236 + 4 :
case V_238 + 4 :
if ( V_112 == V_123 ||
V_112 == V_124 )
V_100 = V_100 >> 1 ;
case V_237 + 4 :
case V_239 + 4 :
* V_261 = 0 ;
if ( V_259 )
* V_260 = V_259 * V_258 * V_256 ;
else
* V_260 = 0 ;
* V_262 = F_171 ( 1 -
( V_265 * V_258 + V_264 * V_100 ) -
( V_240 ? V_258 : 0 ) , V_256 ) ;
* V_263 = F_171 ( V_264 , V_256 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_173 ( T_5 V_214 , bool V_257 ,
T_1 V_258 ,
T_1 V_100 , T_1 V_101 ,
enum V_111 V_112 , bool V_240 ,
unsigned int V_259 ,
unsigned * V_260 , unsigned * V_261 ,
T_6 * V_262 , T_6 * V_263 , int V_264 , int V_265 )
{
T_5 V_256 ;
T_1 V_266 , V_267 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
default:
V_256 = F_170 ( V_112 ) / 8 ;
break;
}
F_10 ( L_15 , V_214 , V_258 ,
V_100 , V_101 ) ;
if ( V_214 == V_236 || V_214 == V_238 ) {
V_266 = V_100 ;
V_267 = V_101 ;
} else {
V_266 = V_101 ;
V_267 = V_100 ;
}
switch ( V_214 + V_257 * 4 ) {
case V_236 :
* V_261 = 0 ;
if ( V_259 )
* V_260 = * V_261 + V_259 * V_258 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( 1 +
( V_265 * V_258 - V_266 * V_264 ) +
( V_240 ? V_258 : 0 ) , V_256 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_263 = F_171 ( V_264 , 2 * V_256 ) ;
else
* V_263 = F_171 ( V_264 , V_256 ) ;
break;
case V_237 :
* V_261 = V_258 * ( V_267 - 1 ) * V_256 ;
if ( V_259 )
* V_260 = * V_261 + V_259 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( V_258 * ( V_267 * V_264 - 1 ) +
V_265 + ( V_240 ? 1 : 0 ) , V_256 ) ;
* V_263 = F_171 ( - V_264 * V_258 , V_256 ) ;
break;
case V_238 :
* V_261 = ( V_258 * ( V_267 - 1 ) + V_266 - 1 ) * V_256 ;
if ( V_259 )
* V_260 = * V_261 - V_259 * V_258 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( - 1 -
( V_265 * V_258 - V_266 * V_264 ) -
( V_240 ? V_258 : 0 ) , V_256 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_263 = F_171 ( - V_264 , 2 * V_256 ) ;
else
* V_263 = F_171 ( - V_264 , V_256 ) ;
break;
case V_239 :
* V_261 = ( V_266 - 1 ) * V_256 ;
if ( V_259 )
* V_260 = * V_261 - V_259 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( - V_258 * ( V_267 * V_264 - 1 ) -
V_265 - ( V_240 ? 1 : 0 ) , V_256 ) ;
* V_263 = F_171 ( V_264 * V_258 , V_256 ) ;
break;
case V_236 + 4 :
* V_261 = ( V_266 - 1 ) * V_256 ;
if ( V_259 )
* V_260 = * V_261 + V_259 * V_258 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( V_265 * V_258 * 2 - 1 +
( V_240 ? V_258 : 0 ) ,
V_256 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_263 = F_171 ( - V_264 , 2 * V_256 ) ;
else
* V_263 = F_171 ( - V_264 , V_256 ) ;
break;
case V_237 + 4 :
* V_261 = 0 ;
if ( V_259 )
* V_260 = * V_261 + V_259 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( - V_258 * ( V_267 * V_264 - 1 ) +
V_265 + ( V_240 ? 1 : 0 ) ,
V_256 ) ;
* V_263 = F_171 ( V_264 * V_258 , V_256 ) ;
break;
case V_238 + 4 :
* V_261 = V_258 * ( V_267 - 1 ) * V_256 ;
if ( V_259 )
* V_260 = * V_261 - V_259 * V_258 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( 1 - V_265 * V_258 * 2 -
( V_240 ? V_258 : 0 ) ,
V_256 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_263 = F_171 ( V_264 , 2 * V_256 ) ;
else
* V_263 = F_171 ( V_264 , V_256 ) ;
break;
case V_239 + 4 :
* V_261 = ( V_258 * ( V_267 - 1 ) + V_266 - 1 ) * V_256 ;
if ( V_259 )
* V_260 = * V_261 - V_259 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( V_258 * ( V_267 * V_264 - 1 ) -
V_265 - ( V_240 ? 1 : 0 ) ,
V_256 ) ;
* V_263 = F_171 ( - V_264 * V_258 , V_256 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_174 ( T_1 V_258 , T_1 V_100 ,
enum V_111 V_112 , bool V_240 ,
unsigned int V_259 , unsigned * V_260 , unsigned * V_261 ,
T_6 * V_262 , T_6 * V_263 , int V_264 , int V_265 )
{
T_5 V_256 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
default:
V_256 = F_170 ( V_112 ) / 8 ;
break;
}
F_10 ( L_16 , V_258 , V_100 ) ;
* V_261 = 0 ;
if ( V_259 )
* V_260 = * V_261 + V_259 * V_258 * V_256 ;
else
* V_260 = * V_261 ;
* V_262 = F_171 ( 1 + ( V_265 * V_258 - V_100 * V_264 ) +
( V_240 ? V_258 : 0 ) , V_256 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_263 = F_171 ( V_264 , 2 * V_256 ) ;
else
* V_263 = F_171 ( V_264 , V_256 ) ;
}
static int F_175 ( unsigned long V_268 , unsigned long V_269 ,
const struct V_270 * V_271 , T_1 V_272 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 )
{
const int V_273 = F_176 ( V_101 , V_213 ) ;
unsigned long V_274 ;
static const T_5 V_275 [ 3 ] = { 8 , 10 , 20 } ;
T_8 V_2 , V_276 ;
int V_16 ;
V_274 = V_271 -> V_277 + V_271 -> V_278 + V_271 -> V_279 + V_271 -> V_280 - V_212 ;
V_16 = 0 ;
if ( V_213 < V_101 )
V_16 ++ ;
if ( V_212 < V_100 )
V_16 ++ ;
V_276 = F_177 ( ( T_8 ) ( V_271 -> V_280 + V_271 -> V_279 + V_271 -> V_278 ) * V_269 , V_268 ) ;
F_10 ( L_17 , V_276 , V_275 [ V_16 ] ) ;
if ( V_276 <= V_275 [ V_16 ] )
return - V_281 ;
V_2 = F_177 ( ( T_8 ) ( V_274 - V_272 ) * V_269 , V_268 ) ;
F_10 ( L_18 ,
V_2 , F_178 ( 0 , V_273 - 2 ) * V_100 ) ;
if ( V_2 < F_178 ( 0 , V_273 - 2 ) * V_100 )
return - V_281 ;
V_2 = F_177 ( ( T_8 ) V_274 * V_269 , V_268 ) ;
F_10 ( L_19 ,
V_2 , F_178 ( 0 , V_273 - 1 ) * V_100 ) ;
if ( V_2 < F_178 ( 0 , V_273 - 1 ) * V_100 )
return - V_281 ;
return 0 ;
}
static unsigned long F_179 ( unsigned long V_268 ,
const struct V_270 * V_282 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 )
{
T_2 V_283 = 0 ;
T_8 V_284 ;
if ( V_101 <= V_213 && V_100 <= V_212 )
return ( unsigned long ) V_268 ;
if ( V_101 > V_213 ) {
unsigned int V_285 = V_282 -> V_277 ;
V_284 = V_268 * V_101 * V_212 ;
F_180 ( V_284 , 2 * V_213 * V_285 ) ;
V_283 = V_284 ;
if ( V_101 > 2 * V_213 ) {
if ( V_285 == V_212 )
return 0 ;
V_284 = V_268 * ( V_101 - 2 * V_213 ) * V_212 ;
F_180 ( V_284 , 2 * V_213 * ( V_285 - V_212 ) ) ;
V_283 = F_181 ( T_2 , V_283 , V_284 ) ;
}
}
if ( V_100 > V_212 ) {
V_284 = V_268 * V_100 ;
F_180 ( V_284 , V_212 ) ;
V_283 = F_181 ( T_2 , V_283 , V_284 ) ;
if ( V_112 == V_121 )
V_283 <<= 1 ;
}
return V_283 ;
}
static unsigned long F_182 ( unsigned long V_268 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 , bool V_286 )
{
if ( V_101 > V_213 && V_100 > V_212 )
return V_268 * 4 ;
else
return V_268 * 2 ;
}
static unsigned long F_183 ( unsigned long V_268 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 , bool V_286 )
{
unsigned int V_287 , V_288 ;
if ( V_100 > 3 * V_212 )
V_287 = 4 ;
else if ( V_100 > 2 * V_212 )
V_287 = 3 ;
else if ( V_100 > V_212 )
V_287 = 2 ;
else
V_287 = 1 ;
if ( V_101 > V_213 )
V_288 = 2 ;
else
V_288 = 1 ;
return V_268 * V_288 * V_287 ;
}
static unsigned long F_184 ( unsigned long V_268 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 , bool V_286 )
{
if ( V_286 )
return 1 ;
if ( V_100 > V_212 )
return F_176 ( V_268 , V_212 ) * V_100 ;
else
return V_268 ;
}
static int F_185 ( unsigned long V_268 , unsigned long V_269 ,
const struct V_270 * V_282 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_264 , int * V_265 , int * V_289 , int * V_290 ,
T_1 V_272 , unsigned long * V_283 , bool V_286 )
{
int error ;
T_1 V_291 , V_292 ;
int V_293 = F_186 ( * V_289 , * V_290 ) ;
const int V_294 =
F_187 ( V_295 ) ;
* V_65 = false ;
do {
V_292 = F_176 ( V_101 , * V_290 ) ;
V_291 = F_176 ( V_100 , * V_289 ) ;
* V_283 = V_3 . V_49 -> V_296 ( V_268 , V_291 ,
V_292 , V_212 , V_213 , V_286 ) ;
error = ( V_291 > V_294 || ! * V_283 ||
* V_283 > F_188 () ) ;
if ( error ) {
if ( * V_289 == * V_290 ) {
* V_289 = V_293 ;
++ * V_290 ;
} else {
F_189 ( * V_289 , * V_290 ) ;
if ( * V_289 < * V_290 )
++ * V_289 ;
}
}
} while ( * V_289 <= * V_264 && * V_290 <= * V_265 && error );
if ( V_291 > V_294 ) {
F_75 ( L_20 ) ;
return - V_281 ;
}
return 0 ;
}
static int F_190 ( unsigned long V_268 , unsigned long V_269 ,
const struct V_270 * V_282 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_264 , int * V_265 , int * V_289 , int * V_290 ,
T_1 V_272 , unsigned long * V_283 , bool V_286 )
{
int error ;
T_1 V_291 , V_292 ;
int V_293 = F_186 ( * V_289 , * V_290 ) ;
const int V_294 =
F_187 ( V_295 ) ;
do {
V_292 = F_176 ( V_101 , * V_290 ) ;
V_291 = F_176 ( V_100 , * V_289 ) ;
* V_283 = F_179 ( V_268 , V_282 ,
V_291 , V_292 , V_212 , V_213 , V_112 ) ;
error = F_175 ( V_268 , V_269 , V_282 ,
V_272 , V_291 , V_292 , V_212 ,
V_213 ) ;
if ( V_291 > V_294 )
if ( V_292 > V_213 &&
V_292 < V_213 * 2 )
* V_65 = false ;
if ( ! * V_65 )
* V_283 = V_3 . V_49 -> V_296 ( V_268 , V_291 ,
V_292 , V_212 , V_213 ,
V_286 ) ;
error = ( error || V_291 > V_294 * 2 ||
( V_291 > V_294 && * V_65 ) ||
! * V_283 || * V_283 > F_188 () ) ;
if ( error ) {
if ( * V_289 == * V_290 ) {
* V_289 = V_293 ;
++ * V_290 ;
} else {
F_189 ( * V_289 , * V_290 ) ;
if ( * V_289 < * V_290 )
++ * V_289 ;
}
}
} while ( * V_289 <= * V_264 && * V_290 <= * V_265 && error );
if ( F_175 ( V_268 , V_269 , V_282 , V_272 , V_100 ,
V_101 , V_212 , V_213 ) ) {
F_75 ( L_21 ) ;
return - V_281 ;
}
if ( V_291 > ( V_294 * 2 ) ) {
F_75 ( L_22 ) ;
F_75 ( L_23 ) ;
return - V_281 ;
}
if ( V_291 > V_294 && * V_65 ) {
F_75 ( L_24 ) ;
return - V_281 ;
}
return 0 ;
}
static int F_191 ( unsigned long V_268 , unsigned long V_269 ,
const struct V_270 * V_282 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_264 , int * V_265 , int * V_289 , int * V_290 ,
T_1 V_272 , unsigned long * V_283 , bool V_286 )
{
T_1 V_291 , V_297 ;
int V_298 = * V_289 ;
T_1 V_292 = F_176 ( V_101 , * V_290 ) ;
const int V_294 =
F_187 ( V_295 ) ;
const int V_299 = F_187 ( V_300 ) ;
if ( V_286 ) {
V_297 = V_212 * V_299 ;
} else {
V_297 = F_188 () /
F_176 ( V_268 , V_212 ) ;
}
* V_289 = F_176 ( V_100 , V_297 ) ;
* V_289 = * V_289 > V_298 ? * V_289 : V_298 ;
if ( * V_289 > * V_264 )
return - V_281 ;
do {
V_291 = F_176 ( V_100 , * V_289 ) ;
} while ( * V_289 <= * V_264 &&
V_291 > V_294 && ++ * V_289 );
if ( V_291 > V_294 ) {
F_75 ( L_25 ) ;
return - V_281 ;
}
* V_283 = V_3 . V_49 -> V_296 ( V_268 , V_291 , V_292 ,
V_212 , V_213 , V_286 ) ;
return 0 ;
}
static int F_192 ( unsigned long V_268 , unsigned long V_269 ,
enum V_97 V_98 ,
const struct V_270 * V_282 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_264 , int * V_265 , T_1 V_272 ,
enum V_133 V_134 , bool V_286 )
{
const int V_299 = F_187 ( V_300 ) ;
const int V_301 = 16 ;
unsigned long V_283 = 0 ;
int V_289 , V_290 , V_302 ;
if ( V_100 == V_212 && V_101 == V_213 )
return 0 ;
if ( ( V_98 & V_303 ) == 0 )
return - V_281 ;
if ( V_286 ) {
* V_264 = * V_265 = 1 ;
} else {
* V_264 = V_301 ;
* V_265 = ( V_134 == V_136 &&
F_12 ( V_135 ) ) ?
2 : V_301 ;
}
if ( V_112 == V_129 ||
V_112 == V_130 ||
V_112 == V_131 ||
V_112 == V_132 ) {
* V_264 = 1 ;
* V_265 = 1 ;
* V_65 = false ;
return 0 ;
}
V_289 = F_176 ( F_176 ( V_100 , V_212 ) , V_299 ) ;
V_290 = F_176 ( F_176 ( V_101 , V_213 ) , V_299 ) ;
if ( V_289 > * V_264 || V_212 > V_100 * 8 )
return - V_281 ;
if ( V_290 > * V_265 || V_213 > V_101 * 8 )
return - V_281 ;
V_302 = V_3 . V_49 -> V_304 ( V_268 , V_269 , V_282 , V_100 , V_101 ,
V_212 , V_213 , V_112 , V_65 ,
V_264 , V_265 , & V_289 , & V_290 , V_272 , & V_283 ,
V_286 ) ;
if ( V_302 )
return V_302 ;
F_10 ( L_26 , V_283 ) ;
F_10 ( L_27 , F_188 () ) ;
if ( ! V_283 || V_283 > F_188 () ) {
F_75 ( L_28
L_29
L_27 ,
V_283 , F_188 () ) ;
return - V_281 ;
}
* V_264 = V_289 ;
* V_265 = V_290 ;
return 0 ;
}
int F_193 ( enum V_57 V_58 , enum V_5 V_6 ,
const struct V_305 * V_306 ,
const struct V_270 * V_307 ,
int * V_264 , int * V_265 )
{
enum V_97 V_98 = F_194 ( V_58 ) ;
bool V_65 = true ;
bool V_240 = 0 ;
T_1 V_292 = V_306 -> V_101 ;
T_1 V_291 = V_306 -> V_100 ;
bool V_215 = V_307 -> V_308 ;
T_1 V_212 , V_213 ;
int V_272 = V_306 -> V_272 ;
unsigned long V_268 = F_195 ( V_6 ) ;
unsigned long V_269 = F_196 ( V_6 ) ;
V_212 = V_306 -> V_212 == 0 ? V_306 -> V_100 : V_306 -> V_212 ;
V_213 = V_306 -> V_213 == 0 ? V_306 -> V_101 : V_306 -> V_213 ;
if ( V_215 && V_306 -> V_101 == V_213 )
V_240 = 1 ;
if ( V_215 ) {
if ( V_240 )
V_292 /= 2 ;
V_213 /= 2 ;
F_10 ( L_30 ,
V_292 , V_213 ) ;
}
if ( ! F_197 ( V_58 , V_306 -> V_112 ) )
return - V_281 ;
return F_192 ( V_268 , V_269 , V_98 , V_307 , V_291 ,
V_292 , V_212 , V_213 , V_306 -> V_112 ,
& V_65 , V_264 , V_265 , V_272 ,
V_306 -> V_134 , false ) ;
}
static int F_198 ( enum V_57 V_58 ,
enum V_97 V_98 , T_2 V_96 , T_2 V_309 ,
T_1 V_258 , int V_272 , int V_310 , T_1 V_100 , T_1 V_101 ,
T_1 V_212 , T_1 V_213 , enum V_111 V_112 ,
T_5 V_214 , bool V_257 , T_5 V_102 , T_5 V_311 ,
T_5 V_105 , enum V_133 V_134 ,
bool V_312 , const struct V_270 * V_282 ,
bool V_286 )
{
bool V_65 = true ;
bool V_240 = 0 ;
int V_44 , V_313 = 0 ;
unsigned V_260 , V_261 ;
T_6 V_262 ;
T_6 V_263 ;
T_1 V_314 , V_315 ;
unsigned int V_259 = 0 ;
T_1 V_292 = V_101 ;
T_1 V_291 = V_100 ;
int V_264 = 1 , V_265 = 1 ;
bool V_215 = V_282 -> V_308 ;
unsigned long V_268 = F_199 ( V_58 ) ;
unsigned long V_269 = F_200 ( V_58 ) ;
if ( V_96 == 0 )
return - V_281 ;
V_212 = V_212 == 0 ? V_100 : V_212 ;
V_213 = V_213 == 0 ? V_101 : V_213 ;
if ( V_215 && V_101 == V_213 )
V_240 = 1 ;
if ( V_215 ) {
if ( V_240 )
V_292 /= 2 ;
V_310 /= 2 ;
V_213 /= 2 ;
F_10 ( L_31
L_32 , V_292 , V_310 ,
V_213 ) ;
}
if ( ! F_197 ( V_58 , V_112 ) )
return - V_281 ;
V_44 = F_192 ( V_268 , V_269 , V_98 , V_282 , V_291 ,
V_292 , V_212 , V_213 , V_112 ,
& V_65 , & V_264 , & V_265 , V_272 ,
V_134 , V_286 ) ;
if ( V_44 )
return V_44 ;
V_291 = F_176 ( V_291 , V_264 ) ;
V_292 = F_176 ( V_292 , V_265 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 ||
V_112 == V_114 )
V_313 = 1 ;
if ( V_215 && ! V_240 ) {
if ( ! V_292 || V_292 == V_213 )
V_259 = 0 ;
else
V_259 = V_292 / V_213 / 2 ;
}
if ( V_240 )
V_259 = 1 ;
V_260 = 0 ;
V_261 = 0 ;
V_262 = 0 ;
V_263 = 0 ;
if ( V_58 == V_59 ) {
V_314 = V_212 ;
V_315 = V_213 ;
} else {
V_314 = V_291 ;
V_315 = V_101 ;
}
if ( V_134 == V_136 )
F_174 ( V_258 , V_314 ,
V_112 , V_240 , V_259 ,
& V_260 , & V_261 , & V_262 , & V_263 ,
V_264 , V_265 ) ;
else if ( V_134 == V_316 )
F_173 ( V_214 , V_257 , V_258 ,
V_314 , V_315 ,
V_112 , V_240 , V_259 ,
& V_260 , & V_261 , & V_262 , & V_263 ,
V_264 , V_265 ) ;
else
F_172 ( V_214 , V_257 ,
V_258 , V_314 , V_315 ,
V_112 , V_240 , V_259 ,
& V_260 , & V_261 , & V_262 , & V_263 ,
V_264 , V_265 ) ;
F_10 ( L_33 ,
V_260 , V_261 , V_262 , V_263 ) ;
F_119 ( V_58 , V_112 ) ;
F_121 ( V_58 , V_134 ) ;
F_97 ( V_58 , V_96 + V_260 ) ;
F_99 ( V_58 , V_96 + V_261 ) ;
if ( V_114 == V_112 ) {
F_101 ( V_58 , V_309 + V_260 ) ;
F_103 ( V_58 , V_309 + V_261 ) ;
}
F_117 ( V_58 , V_262 ) ;
F_115 ( V_58 , V_263 ) ;
F_10 ( L_34 , V_272 , V_310 , V_291 ,
V_292 , V_212 , V_213 ) ;
F_105 ( V_58 , V_98 , V_272 , V_310 ) ;
F_107 ( V_58 , V_291 , V_292 ) ;
if ( V_98 & V_303 ) {
F_168 ( V_58 , V_291 , V_292 , V_212 ,
V_213 , V_215 , V_65 , V_240 ,
V_112 , V_214 ) ;
F_110 ( V_58 , V_212 , V_213 ) ;
F_139 ( V_58 , V_313 ) ;
}
F_169 ( V_58 , V_214 , V_134 , V_257 ,
V_112 ) ;
F_111 ( V_58 , V_98 , V_102 ) ;
F_113 ( V_58 , V_98 , V_311 ) ;
F_114 ( V_58 , V_98 , V_105 ) ;
F_140 ( V_58 , V_98 , V_312 ) ;
return 0 ;
}
int F_201 ( enum V_57 V_58 , const struct V_305 * V_306 ,
bool V_312 , const struct V_270 * V_282 ,
bool V_286 )
{
int V_44 ;
enum V_97 V_98 = F_194 ( V_58 ) ;
enum V_5 V_6 ;
V_6 = F_124 ( V_58 ) ;
F_10 ( L_35
L_36 ,
V_58 , V_306 -> V_96 , V_306 -> V_309 , V_306 -> V_258 , V_306 -> V_272 ,
V_306 -> V_310 , V_306 -> V_100 , V_306 -> V_101 , V_306 -> V_212 , V_306 -> V_213 ,
V_306 -> V_112 , V_306 -> V_214 , V_306 -> V_257 , V_6 , V_312 ) ;
V_44 = F_198 ( V_58 , V_98 , V_306 -> V_96 , V_306 -> V_309 ,
V_306 -> V_258 , V_306 -> V_272 , V_306 -> V_310 , V_306 -> V_100 , V_306 -> V_101 ,
V_306 -> V_212 , V_306 -> V_213 , V_306 -> V_112 , V_306 -> V_214 ,
V_306 -> V_257 , V_306 -> V_102 , V_306 -> V_311 , V_306 -> V_105 ,
V_306 -> V_134 , V_312 , V_282 , V_286 ) ;
return V_44 ;
}
int F_202 ( const struct V_317 * V_318 ,
bool V_286 , const struct V_270 * V_282 )
{
int V_44 ;
T_2 V_243 ;
enum V_57 V_58 = V_59 ;
const int V_272 = 0 , V_310 = 0 ;
const T_5 V_102 = 0 , V_105 = 0 ;
const bool V_312 = false ;
bool V_319 ;
int V_291 = V_282 -> V_277 ;
int V_292 = V_282 -> V_320 ;
enum V_97 V_98 =
V_303 | V_104 ;
F_10 ( L_37
L_38 , V_318 -> V_96 , V_318 -> V_309 , V_291 ,
V_292 , V_318 -> V_100 , V_318 -> V_101 , V_318 -> V_112 , V_318 -> V_214 ,
V_318 -> V_257 ) ;
V_44 = F_198 ( V_58 , V_98 , V_318 -> V_96 , V_318 -> V_309 ,
V_318 -> V_321 , V_272 , V_310 , V_291 , V_292 , V_318 -> V_100 ,
V_318 -> V_101 , V_318 -> V_112 , V_318 -> V_214 , V_318 -> V_257 , V_102 ,
V_318 -> V_311 , V_105 , V_318 -> V_134 ,
V_312 , V_282 , V_286 ) ;
switch ( V_318 -> V_112 ) {
case V_119 :
case V_122 :
case V_118 :
case V_116 :
case V_117 :
case V_120 :
case V_128 :
case V_115 :
V_319 = true ;
break;
default:
V_319 = false ;
break;
}
V_243 = F_3 ( F_74 ( V_58 ) ) ;
V_243 = F_123 ( V_243 , V_319 , 10 , 10 ) ;
V_243 = F_123 ( V_243 , V_286 , 19 , 19 ) ;
F_1 ( F_74 ( V_58 ) , V_243 ) ;
return V_44 ;
}
int F_203 ( enum V_57 V_58 , bool V_60 )
{
F_10 ( L_39 , V_58 , V_60 ) ;
F_8 ( F_74 ( V_58 ) , V_60 ? 1 : 0 , 0 , 0 ) ;
return 0 ;
}
bool F_204 ( enum V_57 V_58 )
{
return F_6 ( F_74 ( V_58 ) , 0 , 0 ) ;
}
void F_205 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_322 , V_60 ) ;
F_5 ( V_6 , V_322 ) ;
}
bool F_71 ( enum V_5 V_6 )
{
return ! ! F_5 ( V_6 , V_322 ) ;
}
void F_206 ( bool V_60 )
{
F_203 ( V_59 , V_60 ) ;
}
bool F_207 ( void )
{
return F_204 ( V_59 ) ;
}
static void F_208 ( bool V_323 )
{
if ( ! F_12 ( V_324 ) )
return;
F_8 ( V_325 , V_323 ? 1 : 0 , 29 , 29 ) ;
}
void F_209 ( bool V_60 )
{
if ( ! F_12 ( V_326 ) )
return;
F_8 ( V_325 , V_60 ? 1 : 0 , 28 , 28 ) ;
}
void F_210 ( bool V_60 )
{
if ( ! F_12 ( V_327 ) )
return;
F_8 ( V_325 , V_60 ? 1 : 0 , 27 , 27 ) ;
}
static void F_211 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_328 , V_60 ) ;
}
static void F_212 ( enum V_5 V_6 )
{
F_7 ( V_6 , V_329 , 1 ) ;
}
void F_213 ( enum V_330 V_331 )
{
F_8 ( V_150 , V_331 , 2 , 1 ) ;
}
static void F_214 ( enum V_5 V_6 , T_2 V_332 )
{
F_1 ( F_215 ( V_6 ) , V_332 ) ;
}
static void F_216 ( enum V_5 V_333 ,
enum V_334 type ,
T_2 V_335 )
{
F_7 ( V_333 , V_336 , type ) ;
F_1 ( F_217 ( V_333 ) , V_335 ) ;
}
static void F_218 ( enum V_5 V_333 , bool V_60 )
{
F_7 ( V_333 , V_337 , V_60 ) ;
}
static void F_219 ( enum V_5 V_333 ,
bool V_60 )
{
if ( ! F_12 ( V_22 ) )
return;
if ( V_333 == V_142 )
F_8 ( V_150 , V_60 , 18 , 18 ) ;
else if ( V_333 == V_31 )
F_8 ( V_150 , V_60 , 19 , 19 ) ;
}
void F_220 ( enum V_5 V_6 ,
const struct V_338 * V_339 )
{
F_214 ( V_6 , V_339 -> V_340 ) ;
F_216 ( V_6 , V_339 -> V_341 , V_339 -> V_335 ) ;
F_218 ( V_6 , V_339 -> V_342 ) ;
F_219 ( V_6 ,
V_339 -> V_343 ) ;
if ( F_12 ( V_32 ) ) {
F_133 ( V_6 , V_339 -> V_344 ) ;
F_134 ( V_6 , & V_339 -> V_345 ) ;
}
}
static void F_221 ( enum V_5 V_6 , T_5 V_346 )
{
int V_347 ;
switch ( V_346 ) {
case 12 :
V_347 = 0 ;
break;
case 16 :
V_347 = 1 ;
break;
case 18 :
V_347 = 2 ;
break;
case 24 :
V_347 = 3 ;
break;
default:
F_120 () ;
return;
}
F_7 ( V_6 , V_348 , V_347 ) ;
}
static void F_222 ( enum V_349 V_331 )
{
T_2 V_243 ;
int V_350 , V_351 ;
switch ( V_331 ) {
case V_352 :
V_350 = 0 ;
V_351 = 0 ;
break;
case V_353 :
V_350 = 1 ;
V_351 = 0 ;
break;
case V_354 :
V_350 = 1 ;
V_351 = 1 ;
break;
default:
F_120 () ;
return;
}
V_243 = F_3 ( V_325 ) ;
V_243 = F_123 ( V_243 , V_350 , 15 , 15 ) ;
V_243 = F_123 ( V_243 , V_351 , 16 , 16 ) ;
F_1 ( V_325 , V_243 ) ;
}
static void F_223 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_355 , V_60 ) ;
}
void F_224 ( enum V_5 V_6 ,
const struct V_356 * V_357 )
{
F_222 ( V_357 -> V_358 ) ;
F_223 ( V_6 , V_357 -> V_359 ) ;
F_211 ( V_6 , V_357 -> V_360 ) ;
F_225 ( V_6 , & V_357 -> V_361 ) ;
F_221 ( V_6 , V_357 -> V_362 ) ;
F_208 ( V_357 -> V_363 ) ;
F_212 ( V_6 ) ;
}
static bool F_226 ( T_1 V_100 , T_1 V_101 )
{
return V_100 <= V_3 . V_49 -> V_364 &&
V_101 <= V_3 . V_49 -> V_365 ;
}
static bool F_227 ( int V_279 , int V_278 , int V_280 ,
int V_366 , int V_367 , int V_368 )
{
if ( V_279 < 1 || V_279 > V_3 . V_49 -> V_369 ||
V_278 < 1 || V_278 > V_3 . V_49 -> V_370 ||
V_280 < 1 || V_280 > V_3 . V_49 -> V_370 ||
V_366 < 1 || V_366 > V_3 . V_49 -> V_369 ||
V_367 < 0 || V_367 > V_3 . V_49 -> V_371 ||
V_368 < 0 || V_368 > V_3 . V_49 -> V_371 )
return false ;
return true ;
}
static bool F_228 ( enum V_5 V_6 ,
unsigned long V_268 )
{
if ( F_135 ( V_6 ) )
return V_268 <= V_3 . V_49 -> V_372 ? true : false ;
else
return V_268 <= V_3 . V_49 -> V_373 ? true : false ;
}
bool F_229 ( enum V_5 V_6 ,
const struct V_270 * V_307 )
{
bool V_374 ;
V_374 = F_226 ( V_307 -> V_277 , V_307 -> V_320 ) ;
V_374 &= F_228 ( V_6 , V_307 -> V_375 * 1000 ) ;
if ( F_135 ( V_6 ) ) {
V_374 &= F_227 ( V_307 -> V_279 , V_307 -> V_278 ,
V_307 -> V_280 , V_307 -> V_366 , V_307 -> V_367 ,
V_307 -> V_368 ) ;
}
return V_374 ;
}
static void F_230 ( enum V_5 V_6 , int V_279 ,
int V_278 , int V_280 , int V_366 , int V_367 , int V_368 ,
enum V_376 V_377 ,
enum V_376 V_378 ,
enum V_379 V_380 ,
enum V_376 V_381 ,
enum V_379 V_382 )
{
T_2 V_383 , V_384 , V_243 ;
bool V_385 , V_386 , V_387 ;
V_383 = F_91 ( V_279 - 1 , V_3 . V_49 -> V_388 , 0 ) |
F_91 ( V_278 - 1 , V_3 . V_49 -> V_389 , 8 ) |
F_91 ( V_280 - 1 , V_3 . V_49 -> V_390 , 20 ) ;
V_384 = F_91 ( V_366 - 1 , V_3 . V_49 -> V_388 , 0 ) |
F_91 ( V_367 , V_3 . V_49 -> V_389 , 8 ) |
F_91 ( V_368 , V_3 . V_49 -> V_390 , 20 ) ;
F_1 ( F_231 ( V_6 ) , V_383 ) ;
F_1 ( F_232 ( V_6 ) , V_384 ) ;
switch ( V_380 ) {
case V_391 :
V_387 = false ;
break;
case V_392 :
V_387 = true ;
break;
case V_393 :
default:
F_120 () ;
}
switch ( V_382 ) {
case V_393 :
V_385 = false ;
V_386 = false ;
break;
case V_392 :
V_385 = true ;
V_386 = false ;
break;
case V_391 :
V_385 = true ;
V_386 = true ;
break;
default:
F_120 () ;
} ;
V_243 = F_3 ( F_233 ( V_6 ) ) ;
V_243 |= F_91 ( V_385 , 17 , 17 ) ;
V_243 |= F_91 ( V_386 , 16 , 16 ) ;
V_243 |= F_91 ( V_381 , 15 , 15 ) ;
V_243 |= F_91 ( V_387 , 14 , 14 ) ;
V_243 |= F_91 ( V_378 , 13 , 13 ) ;
V_243 |= F_91 ( V_377 , 12 , 12 ) ;
F_1 ( F_233 ( V_6 ) , V_243 ) ;
}
void F_234 ( enum V_5 V_6 ,
const struct V_270 * V_307 )
{
unsigned V_394 , V_395 ;
unsigned long V_396 , V_397 ;
struct V_270 V_271 = * V_307 ;
F_10 ( L_40 , V_6 , V_271 . V_277 , V_271 . V_320 ) ;
if ( ! F_229 ( V_6 , & V_271 ) ) {
F_120 () ;
return;
}
if ( F_135 ( V_6 ) ) {
F_230 ( V_6 , V_271 . V_279 , V_271 . V_278 , V_271 . V_280 , V_271 . V_366 ,
V_271 . V_367 , V_271 . V_368 , V_271 . V_377 , V_271 . V_378 ,
V_271 . V_380 , V_271 . V_381 , V_271 . V_382 ) ;
V_394 = V_271 . V_277 + V_271 . V_278 + V_271 . V_279 + V_271 . V_280 ;
V_395 = V_271 . V_320 + V_271 . V_367 + V_271 . V_366 + V_271 . V_368 ;
V_396 = ( V_307 -> V_375 * 1000 ) / V_394 ;
V_397 = ( V_307 -> V_375 * 1000 ) / V_394 / V_395 ;
F_10 ( L_41 , V_307 -> V_375 ) ;
F_10 ( L_42 ,
V_271 . V_279 , V_271 . V_278 , V_271 . V_280 , V_271 . V_366 , V_271 . V_367 , V_271 . V_368 ) ;
F_10 ( L_43 ,
V_271 . V_377 , V_271 . V_378 , V_271 . V_380 ,
V_271 . V_381 , V_271 . V_382 ) ;
F_10 ( L_44 , V_396 , V_397 ) ;
} else {
if ( V_271 . V_308 == true )
V_271 . V_320 /= 2 ;
}
F_141 ( V_6 , V_271 . V_277 , V_271 . V_320 ) ;
}
static void F_235 ( enum V_5 V_6 , T_1 V_398 ,
T_1 V_399 )
{
F_83 ( V_398 < 1 ) ;
F_83 ( V_399 < 1 ) ;
F_1 ( F_236 ( V_6 ) ,
F_91 ( V_398 , 23 , 16 ) | F_91 ( V_399 , 7 , 0 ) ) ;
if ( F_12 ( V_38 ) == false &&
V_6 == V_142 )
V_3 . V_400 = F_237 () / V_398 ;
}
static void F_238 ( enum V_5 V_6 , int * V_398 ,
int * V_399 )
{
T_2 V_243 ;
V_243 = F_3 ( F_236 ( V_6 ) ) ;
* V_398 = F_125 ( V_243 , 23 , 16 ) ;
* V_399 = F_125 ( V_243 , 7 , 0 ) ;
}
unsigned long F_237 ( void )
{
struct V_401 * V_402 ;
unsigned long V_44 = 0 ;
switch ( F_239 () ) {
case V_403 :
V_44 = F_240 () ;
break;
case V_404 :
V_402 = F_241 ( 0 ) ;
V_44 = F_242 ( V_402 ) ;
break;
case V_405 :
V_402 = F_241 ( 1 ) ;
V_44 = F_242 ( V_402 ) ;
break;
default:
F_120 () ;
return 0 ;
}
return V_44 ;
}
unsigned long F_196 ( enum V_5 V_6 )
{
struct V_401 * V_402 ;
int V_406 ;
unsigned long V_44 ;
T_2 V_243 ;
if ( F_135 ( V_6 ) ) {
V_243 = F_3 ( F_236 ( V_6 ) ) ;
V_406 = F_125 ( V_243 , 23 , 16 ) ;
switch ( F_243 ( V_6 ) ) {
case V_403 :
V_44 = F_240 () ;
break;
case V_404 :
V_402 = F_241 ( 0 ) ;
V_44 = F_242 ( V_402 ) ;
break;
case V_405 :
V_402 = F_241 ( 1 ) ;
V_44 = F_242 ( V_402 ) ;
break;
default:
F_120 () ;
return 0 ;
}
return V_44 / V_406 ;
} else {
return F_237 () ;
}
}
unsigned long F_195 ( enum V_5 V_6 )
{
unsigned long V_44 ;
if ( F_135 ( V_6 ) ) {
int V_407 ;
T_2 V_243 ;
V_243 = F_3 ( F_236 ( V_6 ) ) ;
V_407 = F_125 ( V_243 , 7 , 0 ) ;
V_44 = F_196 ( V_6 ) ;
return V_44 / V_407 ;
} else {
return V_3 . V_408 ;
}
}
void F_244 ( unsigned long V_268 )
{
V_3 . V_408 = V_268 ;
}
unsigned long F_188 ( void )
{
return V_3 . V_400 ;
}
static unsigned long F_199 ( enum V_57 V_58 )
{
enum V_5 V_6 ;
if ( V_58 == V_59 )
return 0 ;
V_6 = F_124 ( V_58 ) ;
return F_195 ( V_6 ) ;
}
static unsigned long F_200 ( enum V_57 V_58 )
{
enum V_5 V_6 ;
if ( V_58 == V_59 )
return 0 ;
V_6 = F_124 ( V_58 ) ;
return F_196 ( V_6 ) ;
}
static void F_245 ( struct V_409 * V_410 , enum V_5 V_6 )
{
int V_406 , V_407 ;
enum V_411 V_412 ;
F_246 ( V_410 , L_45 , V_11 [ V_6 ] . V_55 ) ;
V_412 = F_243 ( V_6 ) ;
F_246 ( V_410 , L_46 , V_11 [ V_6 ] . V_55 ,
F_247 ( V_412 ) ,
F_248 ( V_412 ) ) ;
F_238 ( V_6 , & V_406 , & V_407 ) ;
F_246 ( V_410 , L_47 ,
F_196 ( V_6 ) , V_406 ) ;
F_246 ( V_410 , L_48 ,
F_195 ( V_6 ) , V_407 ) ;
}
void F_249 ( struct V_409 * V_410 )
{
int V_406 ;
T_2 V_243 ;
enum V_411 V_413 = F_239 () ;
if ( F_60 () )
return;
F_246 ( V_410 , L_49 ) ;
F_246 ( V_410 , L_50 ,
F_247 ( V_413 ) ,
F_248 ( V_413 ) ) ;
F_246 ( V_410 , L_51 , F_237 () ) ;
if ( F_12 ( V_38 ) ) {
F_246 ( V_410 , L_52 ) ;
V_243 = F_3 ( V_414 ) ;
V_406 = F_125 ( V_243 , 23 , 16 ) ;
F_246 ( V_410 , L_47 ,
( F_237 () / V_406 ) , V_406 ) ;
}
F_245 ( V_410 , V_142 ) ;
if ( F_12 ( V_25 ) )
F_245 ( V_410 , V_143 ) ;
if ( F_12 ( V_28 ) )
F_245 ( V_410 , V_144 ) ;
F_63 () ;
}
static void F_250 ( struct V_409 * V_410 )
{
int V_16 , V_17 ;
const char * V_415 [] = {
[ V_142 ] = L_53 ,
[ V_31 ] = L_54 ,
[ V_143 ] = L_55 ,
[ V_144 ] = L_56 ,
} ;
const char * V_416 [] = {
[ V_34 ] = L_57 ,
[ V_139 ] = L_58 ,
[ V_140 ] = L_59 ,
[ V_141 ] = L_60 ,
} ;
const char * * V_417 ;
#define F_251 ( V_44 ) seq_printf(s, "%-50s %08x\n", #r, dispc_read_reg(r))
if ( F_60 () )
return;
F_251 ( V_418 ) ;
F_251 ( V_419 ) ;
F_251 ( V_420 ) ;
F_251 ( V_421 ) ;
F_251 ( V_422 ) ;
F_251 ( V_325 ) ;
F_251 ( V_150 ) ;
F_251 ( V_423 ) ;
F_251 ( V_424 ) ;
F_251 ( V_425 ) ;
if ( F_12 ( V_22 ) ||
F_12 ( V_23 ) )
F_251 ( V_109 ) ;
if ( F_12 ( V_25 ) ) {
F_251 ( V_56 ) ;
F_251 ( V_426 ) ;
}
if ( F_12 ( V_28 ) ) {
F_251 ( V_427 ) ;
F_251 ( V_428 ) ;
}
#undef F_251
#define F_252 ( V_16 , V_55 ) name(i)
#define F_251 ( V_16 , V_44 ) seq_printf(s, "%s(%s)%*s %08x\n", #r, p_names[i], \
(int)(48 - strlen(#r) - strlen(p_names[i])), " ", \
dispc_read_reg(DISPC_REG(i, r)))
V_417 = V_415 ;
for ( V_16 = 0 ; V_16 < F_13 () ; V_16 ++ ) {
F_251 ( V_16 , F_215 ) ;
F_251 ( V_16 , F_217 ) ;
F_251 ( V_16 , F_142 ) ;
if ( V_16 == V_31 )
continue;
F_251 ( V_16 , F_215 ) ;
F_251 ( V_16 , F_217 ) ;
F_251 ( V_16 , F_231 ) ;
F_251 ( V_16 , F_232 ) ;
F_251 ( V_16 , F_233 ) ;
F_251 ( V_16 , F_236 ) ;
F_251 ( V_16 , F_142 ) ;
F_251 ( V_16 , V_429 ) ;
F_251 ( V_16 , V_430 ) ;
F_251 ( V_16 , V_431 ) ;
if ( F_12 ( V_32 ) ) {
F_251 ( V_16 , F_136 ) ;
F_251 ( V_16 , F_137 ) ;
F_251 ( V_16 , F_138 ) ;
}
}
V_417 = V_416 ;
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ ) {
F_251 ( V_16 , F_98 ) ;
F_251 ( V_16 , F_100 ) ;
F_251 ( V_16 , F_106 ) ;
F_251 ( V_16 , F_108 ) ;
F_251 ( V_16 , F_74 ) ;
F_251 ( V_16 , F_149 ) ;
F_251 ( V_16 , F_146 ) ;
F_251 ( V_16 , F_118 ) ;
F_251 ( V_16 , F_116 ) ;
if ( F_12 ( V_33 ) )
F_251 ( V_16 , V_432 ) ;
if ( V_16 == V_34 ) {
F_251 ( V_16 , V_433 ) ;
F_251 ( V_16 , V_434 ) ;
continue;
}
F_251 ( V_16 , F_153 ) ;
F_251 ( V_16 , F_109 ) ;
F_251 ( V_16 , F_156 ) ;
F_251 ( V_16 , F_158 ) ;
if ( F_12 ( V_36 ) ) {
F_251 ( V_16 , F_102 ) ;
F_251 ( V_16 , F_104 ) ;
F_251 ( V_16 , F_154 ) ;
F_251 ( V_16 , F_160 ) ;
F_251 ( V_16 , F_162 ) ;
}
if ( F_12 ( V_37 ) )
F_251 ( V_16 , F_167 ) ;
if ( F_12 ( V_33 ) )
F_251 ( V_16 , V_432 ) ;
}
#undef F_252
#undef F_251
#define F_252 ( V_58 , V_55 , V_16 ) name(plane, i)
#define F_251 ( V_58 , V_55 , V_16 ) \
seq_printf(s, "%s_%d(%s)%*s %08x\n", #name, i, p_names[plane], \
(int)(46 - strlen(#name) - strlen(p_names[plane])), " ", \
dispc_read_reg(DISPC_REG(plane, name, i)))
for ( V_16 = 1 ; V_16 < F_27 () ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_77 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_79 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ )
F_251 ( V_16 , F_94 , V_17 ) ;
if ( F_12 ( V_35 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_81 , V_17 ) ;
}
if ( F_12 ( V_36 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_84 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_86 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_88 , V_17 ) ;
}
}
F_63 () ;
#undef F_252
#undef F_251
}
int F_253 ( unsigned long F_237 ,
struct V_435 * V_436 )
{
if ( V_436 -> V_398 > 255 || V_436 -> V_398 == 0 )
return - V_281 ;
if ( V_436 -> V_399 < 1 || V_436 -> V_399 > 255 )
return - V_281 ;
V_436 -> V_437 = F_237 / V_436 -> V_398 ;
V_436 -> V_438 = V_436 -> V_437 / V_436 -> V_399 ;
return 0 ;
}
bool F_254 ( unsigned long V_3 ,
unsigned long V_439 , unsigned long V_440 ,
T_9 V_441 , void * V_442 )
{
int V_443 , V_444 , V_445 ;
int V_446 , V_447 , V_448 ;
unsigned long V_438 , V_437 ;
unsigned long V_449 ;
unsigned long V_450 , V_451 ;
unsigned V_452 ;
unsigned long V_453 ;
#ifdef F_255
V_452 = F_255 ;
#else
V_452 = 0 ;
#endif
V_450 = F_256 ( V_454 ) ;
V_451 = F_187 ( V_454 ) ;
V_449 = F_187 ( V_455 ) ;
V_439 = V_439 ? V_439 : 1 ;
V_440 = V_440 ? V_440 : V_456 ;
V_444 = F_178 ( F_176 ( V_3 , V_449 ) , 1ul ) ;
V_445 = F_186 ( V_3 / V_439 , 255ul ) ;
for ( V_443 = V_444 ; V_443 <= V_445 ; ++ V_443 ) {
V_437 = V_3 / V_443 ;
V_447 = F_178 ( F_176 ( V_437 , V_440 ) , V_450 ) ;
V_448 = F_186 ( V_437 / V_439 , V_451 ) ;
for ( V_446 = V_447 ; V_446 <= V_448 ; ++ V_446 ) {
V_438 = V_437 / V_446 ;
if ( F_12 ( V_38 ) )
V_453 = F_188 () ;
else
V_453 = V_437 ;
if ( V_453 < V_438 * V_452 )
continue;
if ( V_441 ( V_443 , V_446 , V_437 , V_438 , V_442 ) )
return true ;
}
}
return false ;
}
void F_225 ( enum V_5 V_6 ,
const struct V_435 * V_436 )
{
F_10 ( L_61 , V_436 -> V_437 , V_436 -> V_398 ) ;
F_10 ( L_62 , V_436 -> V_438 , V_436 -> V_399 ) ;
F_235 ( V_6 , V_436 -> V_398 , V_436 -> V_399 ) ;
}
int F_257 ( enum V_5 V_6 ,
struct V_435 * V_436 )
{
unsigned long V_453 ;
V_453 = F_237 () ;
V_436 -> V_398 = F_6 ( F_236 ( V_6 ) , 23 , 16 ) ;
V_436 -> V_399 = F_6 ( F_236 ( V_6 ) , 7 , 0 ) ;
V_436 -> V_437 = V_453 / V_436 -> V_398 ;
V_436 -> V_438 = V_436 -> V_437 / V_436 -> V_399 ;
return 0 ;
}
T_2 F_258 ( void )
{
return F_3 ( V_421 ) ;
}
void F_59 ( T_2 V_457 )
{
F_1 ( V_421 , V_457 ) ;
}
T_2 F_259 ( void )
{
return F_3 ( V_422 ) ;
}
void F_260 ( T_2 V_457 )
{
T_2 V_458 = F_3 ( V_422 ) ;
F_59 ( ( V_457 ^ V_458 ) & V_457 ) ;
F_1 ( V_422 , V_457 ) ;
}
void F_261 ( void )
{
F_8 ( V_419 , 2 , 4 , 3 ) ;
}
void F_262 ( void )
{
F_8 ( V_419 , 1 , 4 , 3 ) ;
}
static void F_263 ( void )
{
T_2 V_243 ;
if ( F_12 ( V_38 ) ) {
V_243 = F_3 ( V_414 ) ;
V_243 = F_123 ( V_243 , 1 , 0 , 0 ) ;
V_243 = F_123 ( V_243 , 1 , 23 , 16 ) ;
F_1 ( V_414 , V_243 ) ;
V_3 . V_400 = F_237 () ;
}
if ( F_12 ( V_459 ) )
F_8 ( V_150 , 1 , 9 , 9 ) ;
F_95 () ;
F_213 ( V_460 ) ;
F_143 () ;
F_128 () ;
F_112 () ;
if ( V_3 . V_49 -> V_461 )
F_8 ( V_462 , 1 , 0 , 0 ) ;
}
static int T_10 F_264 ( struct V_401 * V_45 )
{
const struct V_463 * V_464 ;
struct V_463 * V_465 ;
V_465 = F_265 ( & V_45 -> V_46 , sizeof( * V_465 ) , V_466 ) ;
if ( ! V_465 ) {
F_266 ( & V_45 -> V_46 , L_63 ) ;
return - V_467 ;
}
switch ( F_267 () ) {
case V_468 :
V_464 = & V_469 ;
break;
case V_470 :
V_464 = & V_471 ;
break;
case V_472 :
case V_473 :
case V_474 :
V_464 = & V_475 ;
break;
case V_476 :
case V_477 :
case V_478 :
V_464 = & V_479 ;
break;
case V_480 :
V_464 = & V_481 ;
break;
default:
return - V_482 ;
}
memcpy ( V_465 , V_464 , sizeof( * V_465 ) ) ;
V_3 . V_49 = V_465 ;
return 0 ;
}
int F_268 ( T_11 V_483 , void * V_484 )
{
return F_269 ( & V_3 . V_45 -> V_46 , V_3 . V_485 , V_483 ,
V_486 , L_64 , V_484 ) ;
}
void F_270 ( void * V_484 )
{
F_271 ( & V_3 . V_45 -> V_46 , V_3 . V_485 , V_484 ) ;
}
static int T_10 F_272 ( struct V_401 * V_45 )
{
T_2 V_487 ;
int V_44 = 0 ;
struct V_488 * V_489 ;
V_3 . V_45 = V_45 ;
V_44 = F_264 ( V_3 . V_45 ) ;
if ( V_44 )
return V_44 ;
V_489 = F_273 ( V_3 . V_45 , V_490 , 0 ) ;
if ( ! V_489 ) {
F_75 ( L_65 ) ;
return - V_281 ;
}
V_3 . V_4 = F_274 ( & V_45 -> V_46 , V_489 -> V_171 ,
F_275 ( V_489 ) ) ;
if ( ! V_3 . V_4 ) {
F_75 ( L_66 ) ;
return - V_467 ;
}
V_3 . V_485 = F_276 ( V_3 . V_45 , 0 ) ;
if ( V_3 . V_485 < 0 ) {
F_75 ( L_67 ) ;
return - V_482 ;
}
F_277 ( & V_45 -> V_46 ) ;
F_278 ( & V_45 -> V_46 ) ;
V_44 = F_60 () ;
if ( V_44 )
goto V_491;
F_263 () ;
V_487 = F_3 ( V_418 ) ;
F_279 ( & V_45 -> V_46 , L_68 ,
F_125 ( V_487 , 7 , 4 ) , F_125 ( V_487 , 3 , 0 ) ) ;
F_63 () ;
F_280 () ;
F_281 ( L_69 , F_250 ) ;
return 0 ;
V_491:
F_282 ( & V_45 -> V_46 ) ;
return V_44 ;
}
static int T_12 F_283 ( struct V_401 * V_45 )
{
F_282 ( & V_45 -> V_46 ) ;
F_284 () ;
return 0 ;
}
static int F_285 ( struct V_492 * V_46 )
{
F_9 () ;
return 0 ;
}
static int F_286 ( struct V_492 * V_46 )
{
F_57 () ;
return 0 ;
}
int T_10 F_287 ( void )
{
return F_288 ( & V_493 , F_272 ) ;
}
void T_12 F_289 ( void )
{
F_290 ( & V_493 ) ;
}
