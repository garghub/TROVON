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
if ( F_12 ( V_33 ) && V_3 . V_49 -> V_185 &&
V_58 != V_59 )
F_1 ( F_150 ( V_58 ) , F_151 ( V_14 , 0xfffu ) ) ;
}
void F_152 ( bool V_60 )
{
if ( ! F_12 ( V_186 ) ) {
F_62 ( V_60 ) ;
return;
}
F_10 ( L_12 , V_60 ? L_13 : L_14 ) ;
F_8 ( V_150 , V_60 ? 1 : 0 , 14 , 14 ) ;
}
void F_153 ( enum V_57 V_58 ,
T_2 * V_187 , T_2 * V_188 , bool V_189 ,
bool V_190 )
{
unsigned V_191 = F_144 () ;
unsigned V_192 , V_193 , V_147 ;
int V_16 ;
V_147 = F_129 ( V_58 ) ;
V_192 = F_147 ( V_58 ) ;
if ( V_189 ) {
V_193 = 0 ;
for ( V_16 = 0 ; V_16 < F_27 () ; ++ V_16 )
V_193 += F_147 ( V_16 ) ;
} else {
V_193 = V_192 ;
}
if ( V_190 && F_12 ( V_194 ) ) {
* V_187 = V_192 - V_147 * 2 ;
* V_188 = V_193 - V_147 ;
} else if ( V_58 == V_59 ) {
* V_187 = 0 ;
* V_188 = V_147 ;
} else {
* V_187 = V_192 - V_147 ;
* V_188 = V_193 - V_191 ;
}
}
static void F_154 ( enum V_57 V_58 ,
int V_195 , int V_196 ,
enum V_66 V_67 )
{
T_2 V_2 ;
if ( V_67 == V_78 ) {
T_5 V_197 , V_198 , V_199 , V_200 ;
F_145 ( V_201 ,
& V_197 , & V_198 ) ;
F_145 ( V_202 ,
& V_199 , & V_200 ) ;
V_2 = F_91 ( V_196 , V_199 , V_200 ) |
F_91 ( V_195 , V_197 , V_198 ) ;
F_1 ( F_155 ( V_58 ) , V_2 ) ;
} else {
V_2 = F_91 ( V_196 , 28 , 16 ) | F_91 ( V_195 , 12 , 0 ) ;
F_1 ( F_156 ( V_58 ) , V_2 ) ;
}
}
static void F_157 ( enum V_57 V_58 , int V_203 , int V_204 )
{
T_2 V_2 ;
T_5 V_205 , V_206 , V_207 , V_208 ;
F_145 ( V_209 , & V_205 , & V_206 ) ;
F_145 ( V_210 , & V_207 , & V_208 ) ;
V_2 = F_91 ( V_204 , V_207 , V_208 ) |
F_91 ( V_203 , V_205 , V_206 ) ;
F_1 ( F_158 ( V_58 ) , V_2 ) ;
}
static void F_159 ( enum V_57 V_58 , int V_203 , int V_204 )
{
T_2 V_2 ;
T_5 V_205 , V_206 , V_207 , V_208 ;
F_145 ( V_209 , & V_205 , & V_206 ) ;
F_145 ( V_210 , & V_207 , & V_208 ) ;
V_2 = F_91 ( V_204 , V_207 , V_208 ) |
F_91 ( V_203 , V_205 , V_206 ) ;
F_1 ( F_160 ( V_58 ) , V_2 ) ;
}
static void F_161 ( enum V_57 V_58 , int V_203 ,
int V_204 )
{
T_2 V_2 ;
V_2 = F_91 ( V_204 , 26 , 16 ) | F_91 ( V_203 , 10 , 0 ) ;
F_1 ( F_162 ( V_58 ) , V_2 ) ;
}
static void F_163 ( enum V_57 V_58 , int V_203 ,
int V_204 )
{
T_2 V_2 ;
V_2 = F_91 ( V_204 , 26 , 16 ) | F_91 ( V_203 , 10 , 0 ) ;
F_1 ( F_164 ( V_58 ) , V_2 ) ;
}
static void F_165 ( enum V_57 V_58 ,
T_1 V_211 , T_1 V_212 ,
T_1 V_213 , T_1 V_214 ,
bool V_65 , T_5 V_215 ,
enum V_66 V_67 )
{
int V_63 , V_64 ;
V_63 = 1024 * V_211 / V_213 ;
V_64 = 1024 * V_212 / V_214 ;
F_89 ( V_58 , V_63 , V_64 , V_65 ,
V_67 ) ;
F_154 ( V_58 , V_63 , V_64 , V_67 ) ;
}
static void F_166 ( enum V_57 V_58 ,
T_1 V_211 , T_1 V_212 , T_1 V_213 , T_1 V_214 ,
bool V_216 , enum V_111 V_112 , T_5 V_215 )
{
int V_217 , V_218 ;
int V_219 , V_220 ;
int V_221 , V_222 ;
int V_1 ;
struct V_223 {
T_7 V_224 , V_225 ;
T_7 V_226 , V_227 ;
T_7 V_228 , V_229 ;
T_7 V_230 , V_231 ;
};
const struct V_223 * V_232 ;
const struct V_223 * V_233 ;
static const struct V_223 V_234 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ 1 , 2 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ - 1 , 2 , - 1 , 2 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_223 V_235 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 3 , 4 , - 1 , 4 } ,
{ - 1 , 4 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 4 , - 3 , 4 } ,
{ - 3 , 4 , - 3 , 4 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_223 V_236 [ 4 ] = {
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , - 1 , 1 , 0 , 1 } ,
} ;
switch ( V_215 ) {
case V_237 :
V_1 = 0 ;
break;
case V_238 :
V_1 = 1 ;
break;
case V_239 :
V_1 = 2 ;
break;
case V_240 :
V_1 = 3 ;
break;
default:
F_120 () ;
return;
}
switch ( V_112 ) {
case V_114 :
if ( V_216 )
V_232 = V_235 ;
else
V_232 = V_234 ;
break;
case V_123 :
case V_124 :
V_232 = V_236 ;
break;
default:
F_120 () ;
return;
}
V_233 = & V_232 [ V_1 ] ;
V_221 = 1024 * V_211 / V_213 ;
V_222 = 1024 * V_212 / V_214 ;
V_217 = ( V_233 -> V_224 * V_221 / V_233 -> V_225 ) % 1024 ;
V_218 = ( V_233 -> V_226 * V_221 / V_233 -> V_227 ) % 1024 ;
V_219 = ( V_233 -> V_228 * V_222 / V_233 -> V_229 ) % 1024 ;
V_220 = ( V_233 -> V_230 * V_222 / V_233 -> V_231 ) % 1024 ;
F_161 ( V_58 , V_217 , V_219 ) ;
F_163 ( V_58 , V_218 , V_220 ) ;
}
static void F_167 ( enum V_57 V_58 ,
T_1 V_211 , T_1 V_212 ,
T_1 V_213 , T_1 V_214 ,
bool V_216 , bool V_65 ,
bool V_241 , enum V_111 V_112 ,
T_5 V_215 )
{
int V_242 = 0 ;
int V_243 = 0 ;
T_2 V_244 ;
F_165 ( V_58 , V_211 , V_212 ,
V_213 , V_214 , V_65 ,
V_215 , V_78 ) ;
V_244 = F_3 ( F_74 ( V_58 ) ) ;
V_244 &= ~ ( ( 0x3 << 5 ) | ( 0x1 << 21 ) ) ;
V_244 |= ( V_211 != V_213 ) ? ( 1 << 5 ) : 0 ;
V_244 |= ( V_212 != V_214 ) ? ( 1 << 6 ) : 0 ;
V_244 |= V_65 ? ( 1 << 21 ) : 0 ;
if ( F_12 ( V_245 ) ) {
V_244 &= ~ ( 0x3 << 7 ) ;
V_244 |= ( V_211 <= V_213 ) ? 0 : ( 1 << 7 ) ;
V_244 |= ( V_212 <= V_214 ) ? 0 : ( 1 << 8 ) ;
}
if ( F_12 ( V_246 ) ) {
V_244 &= ~ ( 0x1 << 22 ) ;
V_244 |= V_65 ? ( 1 << 22 ) : 0 ;
}
F_1 ( F_74 ( V_58 ) , V_244 ) ;
if ( V_216 && ! V_241 ) {
V_243 = 0 ;
V_242 = ( ( 1024 * V_212 / V_214 ) / 2 ) & 0x3ff ;
if ( V_242 >= 1024 / 2 ) {
V_243 = 1024 / 2 ;
V_242 -= V_243 ;
}
}
F_157 ( V_58 , 0 , V_242 ) ;
F_159 ( V_58 , 0 , V_243 ) ;
}
static void F_168 ( enum V_57 V_58 ,
T_1 V_211 , T_1 V_212 ,
T_1 V_213 , T_1 V_214 ,
bool V_216 , bool V_65 ,
bool V_241 , enum V_111 V_112 ,
T_5 V_215 )
{
int V_247 = V_213 != V_211 ;
int V_248 = V_214 != V_212 ;
bool V_249 = V_58 != V_59 ? true : false ;
if ( ! F_12 ( V_36 ) )
return;
if ( ( V_112 != V_123 &&
V_112 != V_124 &&
V_112 != V_114 ) ) {
if ( V_58 != V_59 )
F_8 ( F_169 ( V_58 ) , 0 , 8 , 8 ) ;
return;
}
F_166 ( V_58 , V_211 , V_212 , V_213 ,
V_214 , V_216 , V_112 , V_215 ) ;
switch ( V_112 ) {
case V_114 :
if ( V_249 ) {
V_212 >>= 1 ;
V_211 >>= 1 ;
} else {
V_212 <<= 1 ;
V_211 <<= 1 ;
}
break;
case V_123 :
case V_124 :
if ( V_215 == V_237 ||
V_215 == V_239 ) {
if ( V_249 )
V_211 >>= 1 ;
else
V_211 <<= 1 ;
}
if ( V_215 != V_237 )
V_247 = V_248 = true ;
break;
default:
F_120 () ;
return;
}
if ( V_213 != V_211 )
V_247 = true ;
if ( V_214 != V_212 )
V_248 = true ;
F_165 ( V_58 , V_211 , V_212 ,
V_213 , V_214 , V_65 ,
V_215 , V_250 ) ;
if ( V_58 != V_59 )
F_8 ( F_169 ( V_58 ) ,
( V_247 || V_248 ) ? 1 : 0 , 8 , 8 ) ;
F_8 ( F_74 ( V_58 ) , V_247 ? 1 : 0 , 5 , 5 ) ;
F_8 ( F_74 ( V_58 ) , V_248 ? 1 : 0 , 6 , 6 ) ;
}
static void F_170 ( enum V_57 V_58 ,
T_1 V_211 , T_1 V_212 ,
T_1 V_213 , T_1 V_214 ,
bool V_216 , bool V_65 ,
bool V_241 , enum V_111 V_112 ,
T_5 V_215 )
{
F_83 ( V_58 == V_34 ) ;
F_167 ( V_58 ,
V_211 , V_212 ,
V_213 , V_214 ,
V_216 , V_65 ,
V_241 , V_112 ,
V_215 ) ;
F_168 ( V_58 ,
V_211 , V_212 ,
V_213 , V_214 ,
V_216 , V_65 ,
V_241 , V_112 ,
V_215 ) ;
}
static void F_171 ( enum V_57 V_58 , T_5 V_215 ,
enum V_133 V_134 ,
bool V_251 , enum V_111 V_112 )
{
bool V_252 = false ;
int V_253 = 0 ;
if ( V_112 == V_123 ||
V_112 == V_124 ) {
if ( V_251 ) {
switch ( V_215 ) {
case V_237 :
V_253 = 2 ;
break;
case V_238 :
V_253 = 1 ;
break;
case V_239 :
V_253 = 0 ;
break;
case V_240 :
V_253 = 3 ;
break;
}
} else {
switch ( V_215 ) {
case V_237 :
V_253 = 0 ;
break;
case V_238 :
V_253 = 1 ;
break;
case V_239 :
V_253 = 2 ;
break;
case V_240 :
V_253 = 3 ;
break;
}
}
if ( V_215 == V_238 || V_215 == V_240 )
V_252 = true ;
else
V_252 = false ;
}
F_8 ( F_74 ( V_58 ) , V_253 , 13 , 12 ) ;
if ( F_12 ( V_254 ) )
F_8 ( F_74 ( V_58 ) ,
V_252 ? 1 : 0 , 18 , 18 ) ;
if ( V_112 == V_114 ) {
bool V_255 = ( V_134 == V_136 ) &&
( V_215 == V_237 ||
V_215 == V_239 ) ;
F_8 ( F_74 ( V_58 ) , V_255 , 22 , 22 ) ;
}
}
static int F_172 ( enum V_111 V_112 )
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
static T_6 F_173 ( int V_256 , T_5 V_257 )
{
if ( V_256 == 1 )
return 1 ;
else if ( V_256 > 1 )
return 1 + ( V_256 - 1 ) * V_257 ;
else if ( V_256 < 0 )
return 1 - ( - V_256 + 1 ) * V_257 ;
else
F_120 () ;
return 0 ;
}
static void F_174 ( T_5 V_215 , bool V_258 ,
T_1 V_259 ,
T_1 V_100 , T_1 V_101 ,
enum V_111 V_112 , bool V_241 ,
unsigned int V_260 ,
unsigned * V_261 , unsigned * V_262 ,
T_6 * V_263 , T_6 * V_264 , int V_265 , int V_266 )
{
T_5 V_257 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
case V_123 :
case V_124 :
V_257 = 4 ;
break;
default:
V_257 = F_172 ( V_112 ) / 8 ;
break;
}
F_10 ( L_15 , V_215 , V_259 ,
V_100 , V_101 ) ;
switch ( V_215 + V_258 * 4 ) {
case V_237 :
case V_239 :
if ( V_112 == V_123 ||
V_112 == V_124 )
V_100 = V_100 >> 1 ;
case V_238 :
case V_240 :
* V_262 = 0 ;
if ( V_260 )
* V_261 = V_260 * V_259 * V_257 ;
else
* V_261 = 0 ;
* V_263 = F_173 ( 1 +
( V_266 * V_259 - V_265 * V_100 ) +
( V_241 ? V_259 : 0 ) , V_257 ) ;
* V_264 = F_173 ( V_265 , V_257 ) ;
break;
case V_237 + 4 :
case V_239 + 4 :
if ( V_112 == V_123 ||
V_112 == V_124 )
V_100 = V_100 >> 1 ;
case V_238 + 4 :
case V_240 + 4 :
* V_262 = 0 ;
if ( V_260 )
* V_261 = V_260 * V_259 * V_257 ;
else
* V_261 = 0 ;
* V_263 = F_173 ( 1 -
( V_266 * V_259 + V_265 * V_100 ) -
( V_241 ? V_259 : 0 ) , V_257 ) ;
* V_264 = F_173 ( V_265 , V_257 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_175 ( T_5 V_215 , bool V_258 ,
T_1 V_259 ,
T_1 V_100 , T_1 V_101 ,
enum V_111 V_112 , bool V_241 ,
unsigned int V_260 ,
unsigned * V_261 , unsigned * V_262 ,
T_6 * V_263 , T_6 * V_264 , int V_265 , int V_266 )
{
T_5 V_257 ;
T_1 V_267 , V_268 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
default:
V_257 = F_172 ( V_112 ) / 8 ;
break;
}
F_10 ( L_15 , V_215 , V_259 ,
V_100 , V_101 ) ;
if ( V_215 == V_237 || V_215 == V_239 ) {
V_267 = V_100 ;
V_268 = V_101 ;
} else {
V_267 = V_101 ;
V_268 = V_100 ;
}
switch ( V_215 + V_258 * 4 ) {
case V_237 :
* V_262 = 0 ;
if ( V_260 )
* V_261 = * V_262 + V_260 * V_259 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( 1 +
( V_266 * V_259 - V_267 * V_265 ) +
( V_241 ? V_259 : 0 ) , V_257 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_264 = F_173 ( V_265 , 2 * V_257 ) ;
else
* V_264 = F_173 ( V_265 , V_257 ) ;
break;
case V_238 :
* V_262 = V_259 * ( V_268 - 1 ) * V_257 ;
if ( V_260 )
* V_261 = * V_262 + V_260 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( V_259 * ( V_268 * V_265 - 1 ) +
V_266 + ( V_241 ? 1 : 0 ) , V_257 ) ;
* V_264 = F_173 ( - V_265 * V_259 , V_257 ) ;
break;
case V_239 :
* V_262 = ( V_259 * ( V_268 - 1 ) + V_267 - 1 ) * V_257 ;
if ( V_260 )
* V_261 = * V_262 - V_260 * V_259 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( - 1 -
( V_266 * V_259 - V_267 * V_265 ) -
( V_241 ? V_259 : 0 ) , V_257 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_264 = F_173 ( - V_265 , 2 * V_257 ) ;
else
* V_264 = F_173 ( - V_265 , V_257 ) ;
break;
case V_240 :
* V_262 = ( V_267 - 1 ) * V_257 ;
if ( V_260 )
* V_261 = * V_262 - V_260 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( - V_259 * ( V_268 * V_265 - 1 ) -
V_266 - ( V_241 ? 1 : 0 ) , V_257 ) ;
* V_264 = F_173 ( V_265 * V_259 , V_257 ) ;
break;
case V_237 + 4 :
* V_262 = ( V_267 - 1 ) * V_257 ;
if ( V_260 )
* V_261 = * V_262 + V_260 * V_259 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( V_266 * V_259 * 2 - 1 +
( V_241 ? V_259 : 0 ) ,
V_257 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_264 = F_173 ( - V_265 , 2 * V_257 ) ;
else
* V_264 = F_173 ( - V_265 , V_257 ) ;
break;
case V_238 + 4 :
* V_262 = 0 ;
if ( V_260 )
* V_261 = * V_262 + V_260 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( - V_259 * ( V_268 * V_265 - 1 ) +
V_266 + ( V_241 ? 1 : 0 ) ,
V_257 ) ;
* V_264 = F_173 ( V_265 * V_259 , V_257 ) ;
break;
case V_239 + 4 :
* V_262 = V_259 * ( V_268 - 1 ) * V_257 ;
if ( V_260 )
* V_261 = * V_262 - V_260 * V_259 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( 1 - V_266 * V_259 * 2 -
( V_241 ? V_259 : 0 ) ,
V_257 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_264 = F_173 ( V_265 , 2 * V_257 ) ;
else
* V_264 = F_173 ( V_265 , V_257 ) ;
break;
case V_240 + 4 :
* V_262 = ( V_259 * ( V_268 - 1 ) + V_267 - 1 ) * V_257 ;
if ( V_260 )
* V_261 = * V_262 - V_260 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( V_259 * ( V_268 * V_265 - 1 ) -
V_266 - ( V_241 ? 1 : 0 ) ,
V_257 ) ;
* V_264 = F_173 ( - V_265 * V_259 , V_257 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_176 ( T_1 V_259 , T_1 V_100 ,
enum V_111 V_112 , bool V_241 ,
unsigned int V_260 , unsigned * V_261 , unsigned * V_262 ,
T_6 * V_263 , T_6 * V_264 , int V_265 , int V_266 )
{
T_5 V_257 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
default:
V_257 = F_172 ( V_112 ) / 8 ;
break;
}
F_10 ( L_16 , V_259 , V_100 ) ;
* V_262 = 0 ;
if ( V_260 )
* V_261 = * V_262 + V_260 * V_259 * V_257 ;
else
* V_261 = * V_262 ;
* V_263 = F_173 ( 1 + ( V_266 * V_259 - V_100 * V_265 ) +
( V_241 ? V_259 : 0 ) , V_257 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_264 = F_173 ( V_265 , 2 * V_257 ) ;
else
* V_264 = F_173 ( V_265 , V_257 ) ;
}
static int F_177 ( unsigned long V_269 , unsigned long V_270 ,
const struct V_271 * V_272 , T_1 V_273 ,
T_1 V_100 , T_1 V_101 , T_1 V_213 , T_1 V_214 ,
bool V_65 )
{
const int V_274 = F_178 ( V_101 , V_214 ) ;
unsigned long V_275 ;
static const T_5 V_276 [ 3 ] = { 8 , 10 , 20 } ;
T_8 V_2 , V_277 ;
int V_16 ;
V_275 = V_272 -> V_278 + V_272 -> V_279 + V_272 -> V_280 + V_272 -> V_281 - V_213 ;
V_16 = 0 ;
if ( V_214 < V_101 )
V_16 ++ ;
if ( V_213 < V_100 )
V_16 ++ ;
V_277 = F_179 ( ( T_8 ) ( V_272 -> V_281 + V_272 -> V_280 + V_272 -> V_279 ) * V_270 , V_269 ) ;
F_10 ( L_17 , V_277 , V_276 [ V_16 ] ) ;
if ( V_277 <= V_276 [ V_16 ] )
return - V_282 ;
if ( ! V_65 )
return 0 ;
V_2 = F_179 ( ( T_8 ) ( V_275 - V_273 ) * V_270 , V_269 ) ;
F_10 ( L_18 ,
V_2 , F_180 ( 0 , V_274 - 2 ) * V_100 ) ;
if ( V_2 < F_180 ( 0 , V_274 - 2 ) * V_100 )
return - V_282 ;
V_2 = F_179 ( ( T_8 ) V_275 * V_270 , V_269 ) ;
F_10 ( L_19 ,
V_2 , F_180 ( 0 , V_274 - 1 ) * V_100 ) ;
if ( V_2 < F_180 ( 0 , V_274 - 1 ) * V_100 )
return - V_282 ;
return 0 ;
}
static unsigned long F_181 ( unsigned long V_269 ,
const struct V_271 * V_283 , T_1 V_100 ,
T_1 V_101 , T_1 V_213 , T_1 V_214 ,
enum V_111 V_112 )
{
T_2 V_284 = 0 ;
T_8 V_285 ;
if ( V_101 <= V_214 && V_100 <= V_213 )
return ( unsigned long ) V_269 ;
if ( V_101 > V_214 ) {
unsigned int V_286 = V_283 -> V_278 ;
V_285 = V_269 * V_101 * V_213 ;
F_182 ( V_285 , 2 * V_214 * V_286 ) ;
V_284 = V_285 ;
if ( V_101 > 2 * V_214 ) {
if ( V_286 == V_213 )
return 0 ;
V_285 = V_269 * ( V_101 - 2 * V_214 ) * V_213 ;
F_182 ( V_285 , 2 * V_214 * ( V_286 - V_213 ) ) ;
V_284 = F_183 ( T_2 , V_284 , V_285 ) ;
}
}
if ( V_100 > V_213 ) {
V_285 = V_269 * V_100 ;
F_182 ( V_285 , V_213 ) ;
V_284 = F_183 ( T_2 , V_284 , V_285 ) ;
if ( V_112 == V_121 )
V_284 <<= 1 ;
}
return V_284 ;
}
static unsigned long F_184 ( unsigned long V_269 , T_1 V_100 ,
T_1 V_101 , T_1 V_213 , T_1 V_214 , bool V_287 )
{
if ( V_101 > V_214 && V_100 > V_213 )
return V_269 * 4 ;
else
return V_269 * 2 ;
}
static unsigned long F_185 ( unsigned long V_269 , T_1 V_100 ,
T_1 V_101 , T_1 V_213 , T_1 V_214 , bool V_287 )
{
unsigned int V_288 , V_289 ;
if ( V_100 > 3 * V_213 )
V_288 = 4 ;
else if ( V_100 > 2 * V_213 )
V_288 = 3 ;
else if ( V_100 > V_213 )
V_288 = 2 ;
else
V_288 = 1 ;
if ( V_101 > V_214 )
V_289 = 2 ;
else
V_289 = 1 ;
return V_269 * V_289 * V_288 ;
}
static unsigned long F_186 ( unsigned long V_269 , T_1 V_100 ,
T_1 V_101 , T_1 V_213 , T_1 V_214 , bool V_287 )
{
if ( V_287 )
return 1 ;
if ( V_100 > V_213 )
return F_178 ( V_269 , V_213 ) * V_100 ;
else
return V_269 ;
}
static int F_187 ( unsigned long V_269 , unsigned long V_270 ,
const struct V_271 * V_283 ,
T_1 V_100 , T_1 V_101 , T_1 V_213 , T_1 V_214 ,
enum V_111 V_112 , bool * V_65 ,
int * V_265 , int * V_266 , int * V_290 , int * V_291 ,
T_1 V_273 , unsigned long * V_284 , bool V_287 )
{
int error ;
T_1 V_292 , V_293 ;
int V_294 = F_151 ( * V_290 , * V_291 ) ;
const int V_295 =
F_188 ( V_296 ) ;
* V_65 = false ;
do {
V_293 = V_101 / * V_291 ;
V_292 = V_100 / * V_290 ;
* V_284 = V_3 . V_49 -> V_297 ( V_269 , V_292 ,
V_293 , V_213 , V_214 , V_287 ) ;
error = ( V_292 > V_295 || ! * V_284 ||
* V_284 > F_189 () ) ;
if ( error ) {
if ( * V_290 == * V_291 ) {
* V_290 = V_294 ;
++ * V_291 ;
} else {
F_190 ( * V_290 , * V_291 ) ;
if ( * V_290 < * V_291 )
++ * V_290 ;
}
}
} while ( * V_290 <= * V_265 && * V_291 <= * V_266 && error );
if ( V_292 > V_295 ) {
F_75 ( L_20 ) ;
return - V_282 ;
}
return 0 ;
}
static int F_191 ( unsigned long V_269 , unsigned long V_270 ,
const struct V_271 * V_283 ,
T_1 V_100 , T_1 V_101 , T_1 V_213 , T_1 V_214 ,
enum V_111 V_112 , bool * V_65 ,
int * V_265 , int * V_266 , int * V_290 , int * V_291 ,
T_1 V_273 , unsigned long * V_284 , bool V_287 )
{
int error ;
T_1 V_292 , V_293 ;
int V_294 = F_151 ( * V_290 , * V_291 ) ;
const int V_295 =
F_188 ( V_296 ) ;
do {
V_293 = V_101 / * V_291 ;
V_292 = V_100 / * V_290 ;
* V_65 = V_293 > V_214 ;
if ( V_292 > V_295 )
if ( V_293 > V_214 &&
V_293 < V_214 * 2 )
* V_65 = false ;
V_298:
if ( * V_65 )
* V_284 = F_181 ( V_269 , V_283 ,
V_292 , V_293 , V_213 ,
V_214 , V_112 ) ;
else
* V_284 = V_3 . V_49 -> V_297 ( V_269 , V_292 ,
V_293 , V_213 , V_214 ,
V_287 ) ;
error = F_177 ( V_269 , V_270 , V_283 ,
V_273 , V_292 , V_293 , V_213 ,
V_214 , * V_65 ) ;
if ( error && * V_65 ) {
* V_65 = false ;
goto V_298;
}
error = ( error || V_292 > V_295 * 2 ||
( V_292 > V_295 && * V_65 ) ||
! * V_284 || * V_284 > F_189 () ) ;
if ( error ) {
if ( * V_290 == * V_291 ) {
* V_290 = V_294 ;
++ * V_291 ;
} else {
F_190 ( * V_290 , * V_291 ) ;
if ( * V_290 < * V_291 )
++ * V_290 ;
}
}
} while ( * V_290 <= * V_265 && * V_291 <= * V_266 && error );
if ( F_177 ( V_269 , V_270 , V_283 , V_273 , V_100 ,
V_101 , V_213 , V_214 , * V_65 ) ) {
F_75 ( L_21 ) ;
return - V_282 ;
}
if ( V_292 > ( V_295 * 2 ) ) {
F_75 ( L_22 ) ;
F_75 ( L_23 ) ;
return - V_282 ;
}
if ( V_292 > V_295 && * V_65 ) {
F_75 ( L_24 ) ;
return - V_282 ;
}
return 0 ;
}
static int F_192 ( unsigned long V_269 , unsigned long V_270 ,
const struct V_271 * V_283 ,
T_1 V_100 , T_1 V_101 , T_1 V_213 , T_1 V_214 ,
enum V_111 V_112 , bool * V_65 ,
int * V_265 , int * V_266 , int * V_290 , int * V_291 ,
T_1 V_273 , unsigned long * V_284 , bool V_287 )
{
T_1 V_292 , V_299 ;
int V_300 = * V_290 ;
T_1 V_293 = V_101 / * V_291 ;
const int V_295 =
F_188 ( V_296 ) ;
const int V_301 = F_188 ( V_302 ) ;
if ( V_287 ) {
V_299 = V_213 * V_301 ;
} else {
V_299 = F_189 () /
F_178 ( V_269 , V_213 ) ;
}
* V_290 = F_178 ( V_100 , V_299 ) ;
* V_290 = * V_290 > V_300 ? * V_290 : V_300 ;
if ( * V_290 > * V_265 )
return - V_282 ;
do {
V_292 = V_100 / * V_290 ;
} while ( * V_290 <= * V_265 &&
V_292 > V_295 && ++ * V_290 );
if ( V_292 > V_295 ) {
F_75 ( L_25 ) ;
return - V_282 ;
}
* V_284 = V_3 . V_49 -> V_297 ( V_269 , V_292 , V_293 ,
V_213 , V_214 , V_287 ) ;
return 0 ;
}
static int F_193 ( unsigned long V_269 , unsigned long V_270 ,
enum V_97 V_98 ,
const struct V_271 * V_283 ,
T_1 V_100 , T_1 V_101 , T_1 V_213 , T_1 V_214 ,
enum V_111 V_112 , bool * V_65 ,
int * V_265 , int * V_266 , T_1 V_273 ,
enum V_133 V_134 , bool V_287 )
{
const int V_301 = F_188 ( V_302 ) ;
const int V_303 = 16 ;
unsigned long V_284 = 0 ;
int V_290 , V_291 , V_304 ;
if ( V_100 == V_213 && V_101 == V_214 )
return 0 ;
if ( ( V_98 & V_305 ) == 0 )
return - V_282 ;
if ( V_287 ) {
* V_265 = * V_266 = 1 ;
} else {
* V_265 = V_303 ;
* V_266 = ( V_134 == V_136 &&
F_12 ( V_135 ) ) ?
2 : V_303 ;
}
if ( V_112 == V_129 ||
V_112 == V_130 ||
V_112 == V_131 ||
V_112 == V_132 ) {
* V_265 = 1 ;
* V_266 = 1 ;
* V_65 = false ;
return 0 ;
}
V_290 = F_178 ( F_178 ( V_100 , V_213 ) , V_301 ) ;
V_291 = F_178 ( F_178 ( V_101 , V_214 ) , V_301 ) ;
if ( V_290 > * V_265 || V_213 > V_100 * 8 )
return - V_282 ;
if ( V_291 > * V_266 || V_214 > V_101 * 8 )
return - V_282 ;
V_304 = V_3 . V_49 -> V_306 ( V_269 , V_270 , V_283 , V_100 , V_101 ,
V_213 , V_214 , V_112 , V_65 ,
V_265 , V_266 , & V_290 , & V_291 , V_273 , & V_284 ,
V_287 ) ;
if ( V_304 )
return V_304 ;
F_10 ( L_26 , V_284 ) ;
F_10 ( L_27 , F_189 () ) ;
if ( ! V_284 || V_284 > F_189 () ) {
F_75 ( L_28
L_29
L_27 ,
V_284 , F_189 () ) ;
return - V_282 ;
}
* V_265 = V_290 ;
* V_266 = V_291 ;
return 0 ;
}
int F_194 ( enum V_57 V_58 , enum V_5 V_6 ,
const struct V_307 * V_308 ,
const struct V_271 * V_309 ,
int * V_265 , int * V_266 )
{
enum V_97 V_98 = F_195 ( V_58 ) ;
bool V_65 = true ;
bool V_241 = false ;
T_1 V_293 = V_308 -> V_101 ;
T_1 V_292 = V_308 -> V_100 ;
bool V_216 = V_309 -> V_310 ;
T_1 V_213 , V_214 ;
int V_273 = V_308 -> V_273 ;
unsigned long V_269 = F_196 ( V_6 ) ;
unsigned long V_270 = F_197 ( V_6 ) ;
V_213 = V_308 -> V_213 == 0 ? V_308 -> V_100 : V_308 -> V_213 ;
V_214 = V_308 -> V_214 == 0 ? V_308 -> V_101 : V_308 -> V_214 ;
if ( V_216 && V_308 -> V_101 == V_214 )
V_241 = true ;
if ( V_216 ) {
if ( V_241 )
V_293 /= 2 ;
V_214 /= 2 ;
F_10 ( L_30 ,
V_293 , V_214 ) ;
}
if ( ! F_198 ( V_58 , V_308 -> V_112 ) )
return - V_282 ;
return F_193 ( V_269 , V_270 , V_98 , V_309 , V_292 ,
V_293 , V_213 , V_214 , V_308 -> V_112 ,
& V_65 , V_265 , V_266 , V_273 ,
V_308 -> V_134 , false ) ;
}
static int F_199 ( enum V_57 V_58 ,
enum V_97 V_98 , T_2 V_96 , T_2 V_311 ,
T_1 V_259 , int V_273 , int V_312 , T_1 V_100 , T_1 V_101 ,
T_1 V_213 , T_1 V_214 , enum V_111 V_112 ,
T_5 V_215 , bool V_258 , T_5 V_102 , T_5 V_313 ,
T_5 V_105 , enum V_133 V_134 ,
bool V_314 , const struct V_271 * V_283 ,
bool V_287 )
{
bool V_65 = true ;
bool V_241 = false ;
int V_44 , V_315 = 0 ;
unsigned V_261 , V_262 ;
T_6 V_263 ;
T_6 V_264 ;
T_1 V_316 , V_317 ;
unsigned int V_260 = 0 ;
T_1 V_293 = V_101 ;
T_1 V_292 = V_100 ;
int V_265 = 1 , V_266 = 1 ;
bool V_216 = V_283 -> V_310 ;
unsigned long V_269 = F_200 ( V_58 ) ;
unsigned long V_270 = F_201 ( V_58 ) ;
if ( V_96 == 0 )
return - V_282 ;
V_213 = V_213 == 0 ? V_100 : V_213 ;
V_214 = V_214 == 0 ? V_101 : V_214 ;
if ( V_216 && V_101 == V_214 )
V_241 = true ;
if ( V_216 ) {
if ( V_241 )
V_293 /= 2 ;
V_312 /= 2 ;
V_214 /= 2 ;
F_10 ( L_31
L_32 , V_293 , V_312 ,
V_214 ) ;
}
if ( ! F_198 ( V_58 , V_112 ) )
return - V_282 ;
V_44 = F_193 ( V_269 , V_270 , V_98 , V_283 , V_292 ,
V_293 , V_213 , V_214 , V_112 ,
& V_65 , & V_265 , & V_266 , V_273 ,
V_134 , V_287 ) ;
if ( V_44 )
return V_44 ;
V_292 = V_292 / V_265 ;
V_293 = V_293 / V_266 ;
if ( V_112 == V_123 ||
V_112 == V_124 ||
V_112 == V_114 )
V_315 = 1 ;
if ( V_216 && ! V_241 ) {
if ( ! V_293 || V_293 == V_214 )
V_260 = 0 ;
else
V_260 = V_293 / V_214 / 2 ;
}
if ( V_241 )
V_260 = 1 ;
V_261 = 0 ;
V_262 = 0 ;
V_263 = 0 ;
V_264 = 0 ;
if ( V_58 == V_59 ) {
V_316 = V_213 ;
V_317 = V_214 ;
} else {
V_316 = V_292 ;
V_317 = V_101 ;
}
if ( V_134 == V_136 )
F_176 ( V_259 , V_316 ,
V_112 , V_241 , V_260 ,
& V_261 , & V_262 , & V_263 , & V_264 ,
V_265 , V_266 ) ;
else if ( V_134 == V_318 )
F_175 ( V_215 , V_258 , V_259 ,
V_316 , V_317 ,
V_112 , V_241 , V_260 ,
& V_261 , & V_262 , & V_263 , & V_264 ,
V_265 , V_266 ) ;
else
F_174 ( V_215 , V_258 ,
V_259 , V_316 , V_317 ,
V_112 , V_241 , V_260 ,
& V_261 , & V_262 , & V_263 , & V_264 ,
V_265 , V_266 ) ;
F_10 ( L_33 ,
V_261 , V_262 , V_263 , V_264 ) ;
F_119 ( V_58 , V_112 ) ;
F_121 ( V_58 , V_134 ) ;
F_97 ( V_58 , V_96 + V_261 ) ;
F_99 ( V_58 , V_96 + V_262 ) ;
if ( V_114 == V_112 ) {
F_101 ( V_58 , V_311 + V_261 ) ;
F_103 ( V_58 , V_311 + V_262 ) ;
}
F_117 ( V_58 , V_263 ) ;
F_115 ( V_58 , V_264 ) ;
F_10 ( L_34 , V_273 , V_312 , V_292 ,
V_293 , V_213 , V_214 ) ;
F_105 ( V_58 , V_98 , V_273 , V_312 ) ;
F_107 ( V_58 , V_292 , V_293 ) ;
if ( V_98 & V_305 ) {
F_170 ( V_58 , V_292 , V_293 , V_213 ,
V_214 , V_216 , V_65 , V_241 ,
V_112 , V_215 ) ;
F_110 ( V_58 , V_213 , V_214 ) ;
F_139 ( V_58 , V_315 ) ;
}
F_171 ( V_58 , V_215 , V_134 , V_258 ,
V_112 ) ;
F_111 ( V_58 , V_98 , V_102 ) ;
F_113 ( V_58 , V_98 , V_313 ) ;
F_114 ( V_58 , V_98 , V_105 ) ;
F_140 ( V_58 , V_98 , V_314 ) ;
return 0 ;
}
int F_202 ( enum V_57 V_58 , const struct V_307 * V_308 ,
bool V_314 , const struct V_271 * V_283 ,
bool V_287 )
{
int V_44 ;
enum V_97 V_98 = F_195 ( V_58 ) ;
enum V_5 V_6 ;
V_6 = F_124 ( V_58 ) ;
F_10 ( L_35
L_36 ,
V_58 , V_308 -> V_96 , V_308 -> V_311 , V_308 -> V_259 , V_308 -> V_273 ,
V_308 -> V_312 , V_308 -> V_100 , V_308 -> V_101 , V_308 -> V_213 , V_308 -> V_214 ,
V_308 -> V_112 , V_308 -> V_215 , V_308 -> V_258 , V_6 , V_314 ) ;
V_44 = F_199 ( V_58 , V_98 , V_308 -> V_96 , V_308 -> V_311 ,
V_308 -> V_259 , V_308 -> V_273 , V_308 -> V_312 , V_308 -> V_100 , V_308 -> V_101 ,
V_308 -> V_213 , V_308 -> V_214 , V_308 -> V_112 , V_308 -> V_215 ,
V_308 -> V_258 , V_308 -> V_102 , V_308 -> V_313 , V_308 -> V_105 ,
V_308 -> V_134 , V_314 , V_283 , V_287 ) ;
return V_44 ;
}
int F_203 ( const struct V_319 * V_320 ,
bool V_287 , const struct V_271 * V_283 )
{
int V_44 ;
T_2 V_244 ;
enum V_57 V_58 = V_59 ;
const int V_273 = 0 , V_312 = 0 ;
const T_5 V_102 = 0 , V_105 = 0 ;
const bool V_314 = false ;
bool V_321 ;
int V_292 = V_283 -> V_278 ;
int V_293 = V_283 -> V_322 ;
enum V_97 V_98 =
V_305 | V_104 ;
F_10 ( L_37
L_38 , V_320 -> V_96 , V_320 -> V_311 , V_292 ,
V_293 , V_320 -> V_100 , V_320 -> V_101 , V_320 -> V_112 , V_320 -> V_215 ,
V_320 -> V_258 ) ;
V_44 = F_199 ( V_58 , V_98 , V_320 -> V_96 , V_320 -> V_311 ,
V_320 -> V_323 , V_273 , V_312 , V_292 , V_293 , V_320 -> V_100 ,
V_320 -> V_101 , V_320 -> V_112 , V_320 -> V_215 , V_320 -> V_258 , V_102 ,
V_320 -> V_313 , V_105 , V_320 -> V_134 ,
V_314 , V_283 , V_287 ) ;
switch ( V_320 -> V_112 ) {
case V_119 :
case V_122 :
case V_118 :
case V_116 :
case V_117 :
case V_120 :
case V_128 :
case V_115 :
V_321 = true ;
break;
default:
V_321 = false ;
break;
}
V_244 = F_3 ( F_74 ( V_58 ) ) ;
V_244 = F_123 ( V_244 , V_321 , 10 , 10 ) ;
V_244 = F_123 ( V_244 , V_287 , 19 , 19 ) ;
F_1 ( F_74 ( V_58 ) , V_244 ) ;
return V_44 ;
}
int F_204 ( enum V_57 V_58 , bool V_60 )
{
F_10 ( L_39 , V_58 , V_60 ) ;
F_8 ( F_74 ( V_58 ) , V_60 ? 1 : 0 , 0 , 0 ) ;
return 0 ;
}
bool F_205 ( enum V_57 V_58 )
{
return F_6 ( F_74 ( V_58 ) , 0 , 0 ) ;
}
void F_206 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_324 , V_60 ) ;
F_5 ( V_6 , V_324 ) ;
}
bool F_71 ( enum V_5 V_6 )
{
return ! ! F_5 ( V_6 , V_324 ) ;
}
void F_207 ( bool V_60 )
{
F_204 ( V_59 , V_60 ) ;
}
bool F_208 ( void )
{
return F_205 ( V_59 ) ;
}
static void F_209 ( bool V_325 )
{
if ( ! F_12 ( V_326 ) )
return;
F_8 ( V_327 , V_325 ? 1 : 0 , 29 , 29 ) ;
}
void F_210 ( bool V_60 )
{
if ( ! F_12 ( V_328 ) )
return;
F_8 ( V_327 , V_60 ? 1 : 0 , 28 , 28 ) ;
}
void F_211 ( bool V_60 )
{
if ( ! F_12 ( V_329 ) )
return;
F_8 ( V_327 , V_60 ? 1 : 0 , 27 , 27 ) ;
}
static void F_212 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_330 , V_60 ) ;
}
static void F_213 ( enum V_5 V_6 )
{
F_7 ( V_6 , V_331 , 1 ) ;
}
void F_214 ( enum V_332 V_333 )
{
F_8 ( V_150 , V_333 , 2 , 1 ) ;
}
static void F_215 ( enum V_5 V_6 , T_2 V_334 )
{
F_1 ( F_216 ( V_6 ) , V_334 ) ;
}
static void F_217 ( enum V_5 V_335 ,
enum V_336 type ,
T_2 V_337 )
{
F_7 ( V_335 , V_338 , type ) ;
F_1 ( F_218 ( V_335 ) , V_337 ) ;
}
static void F_219 ( enum V_5 V_335 , bool V_60 )
{
F_7 ( V_335 , V_339 , V_60 ) ;
}
static void F_220 ( enum V_5 V_335 ,
bool V_60 )
{
if ( ! F_12 ( V_22 ) )
return;
if ( V_335 == V_142 )
F_8 ( V_150 , V_60 , 18 , 18 ) ;
else if ( V_335 == V_31 )
F_8 ( V_150 , V_60 , 19 , 19 ) ;
}
void F_221 ( enum V_5 V_6 ,
const struct V_340 * V_341 )
{
F_215 ( V_6 , V_341 -> V_342 ) ;
F_217 ( V_6 , V_341 -> V_343 , V_341 -> V_337 ) ;
F_219 ( V_6 , V_341 -> V_344 ) ;
F_220 ( V_6 ,
V_341 -> V_345 ) ;
if ( F_12 ( V_32 ) ) {
F_133 ( V_6 , V_341 -> V_346 ) ;
F_134 ( V_6 , & V_341 -> V_347 ) ;
}
}
static void F_222 ( enum V_5 V_6 , T_5 V_348 )
{
int V_349 ;
switch ( V_348 ) {
case 12 :
V_349 = 0 ;
break;
case 16 :
V_349 = 1 ;
break;
case 18 :
V_349 = 2 ;
break;
case 24 :
V_349 = 3 ;
break;
default:
F_120 () ;
return;
}
F_7 ( V_6 , V_350 , V_349 ) ;
}
static void F_223 ( enum V_351 V_333 )
{
T_2 V_244 ;
int V_352 , V_353 ;
switch ( V_333 ) {
case V_354 :
V_352 = 0 ;
V_353 = 0 ;
break;
case V_355 :
V_352 = 1 ;
V_353 = 0 ;
break;
case V_356 :
V_352 = 1 ;
V_353 = 1 ;
break;
default:
F_120 () ;
return;
}
V_244 = F_3 ( V_327 ) ;
V_244 = F_123 ( V_244 , V_352 , 15 , 15 ) ;
V_244 = F_123 ( V_244 , V_353 , 16 , 16 ) ;
F_1 ( V_327 , V_244 ) ;
}
static void F_224 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_357 , V_60 ) ;
}
void F_225 ( enum V_5 V_6 ,
const struct V_358 * V_359 )
{
F_223 ( V_359 -> V_360 ) ;
F_224 ( V_6 , V_359 -> V_361 ) ;
F_212 ( V_6 , V_359 -> V_362 ) ;
F_226 ( V_6 , & V_359 -> V_363 ) ;
F_222 ( V_6 , V_359 -> V_364 ) ;
F_209 ( V_359 -> V_365 ) ;
F_213 ( V_6 ) ;
}
static bool F_227 ( T_1 V_100 , T_1 V_101 )
{
return V_100 <= V_3 . V_49 -> V_366 &&
V_101 <= V_3 . V_49 -> V_367 ;
}
static bool F_228 ( int V_280 , int V_279 , int V_281 ,
int V_368 , int V_369 , int V_370 )
{
if ( V_280 < 1 || V_280 > V_3 . V_49 -> V_371 ||
V_279 < 1 || V_279 > V_3 . V_49 -> V_372 ||
V_281 < 1 || V_281 > V_3 . V_49 -> V_372 ||
V_368 < 1 || V_368 > V_3 . V_49 -> V_371 ||
V_369 < 0 || V_369 > V_3 . V_49 -> V_373 ||
V_370 < 0 || V_370 > V_3 . V_49 -> V_373 )
return false ;
return true ;
}
static bool F_229 ( enum V_5 V_6 ,
unsigned long V_269 )
{
if ( F_135 ( V_6 ) )
return V_269 <= V_3 . V_49 -> V_374 ? true : false ;
else
return V_269 <= V_3 . V_49 -> V_375 ? true : false ;
}
bool F_230 ( enum V_5 V_6 ,
const struct V_271 * V_309 )
{
bool V_376 ;
V_376 = F_227 ( V_309 -> V_278 , V_309 -> V_322 ) ;
V_376 &= F_229 ( V_6 , V_309 -> V_377 * 1000 ) ;
if ( F_135 ( V_6 ) ) {
V_376 &= F_228 ( V_309 -> V_280 , V_309 -> V_279 ,
V_309 -> V_281 , V_309 -> V_368 , V_309 -> V_369 ,
V_309 -> V_370 ) ;
}
return V_376 ;
}
static void F_231 ( enum V_5 V_6 , int V_280 ,
int V_279 , int V_281 , int V_368 , int V_369 , int V_370 ,
enum V_378 V_379 ,
enum V_378 V_380 ,
enum V_381 V_382 ,
enum V_378 V_383 ,
enum V_381 V_384 )
{
T_2 V_385 , V_386 , V_244 ;
bool V_387 , V_388 , V_389 ;
V_385 = F_91 ( V_280 - 1 , V_3 . V_49 -> V_390 , 0 ) |
F_91 ( V_279 - 1 , V_3 . V_49 -> V_391 , 8 ) |
F_91 ( V_281 - 1 , V_3 . V_49 -> V_392 , 20 ) ;
V_386 = F_91 ( V_368 - 1 , V_3 . V_49 -> V_390 , 0 ) |
F_91 ( V_369 , V_3 . V_49 -> V_391 , 8 ) |
F_91 ( V_370 , V_3 . V_49 -> V_392 , 20 ) ;
F_1 ( F_232 ( V_6 ) , V_385 ) ;
F_1 ( F_233 ( V_6 ) , V_386 ) ;
switch ( V_382 ) {
case V_393 :
V_389 = false ;
break;
case V_394 :
V_389 = true ;
break;
case V_395 :
default:
F_120 () ;
}
switch ( V_384 ) {
case V_395 :
V_387 = false ;
V_388 = false ;
break;
case V_394 :
V_387 = true ;
V_388 = false ;
break;
case V_393 :
V_387 = true ;
V_388 = true ;
break;
default:
F_120 () ;
}
V_244 = F_3 ( F_234 ( V_6 ) ) ;
V_244 |= F_91 ( V_387 , 17 , 17 ) ;
V_244 |= F_91 ( V_388 , 16 , 16 ) ;
V_244 |= F_91 ( V_383 , 15 , 15 ) ;
V_244 |= F_91 ( V_389 , 14 , 14 ) ;
V_244 |= F_91 ( V_380 , 13 , 13 ) ;
V_244 |= F_91 ( V_379 , 12 , 12 ) ;
F_1 ( F_234 ( V_6 ) , V_244 ) ;
}
void F_235 ( enum V_5 V_6 ,
const struct V_271 * V_309 )
{
unsigned V_396 , V_397 ;
unsigned long V_398 , V_399 ;
struct V_271 V_272 = * V_309 ;
F_10 ( L_40 , V_6 , V_272 . V_278 , V_272 . V_322 ) ;
if ( ! F_230 ( V_6 , & V_272 ) ) {
F_120 () ;
return;
}
if ( F_135 ( V_6 ) ) {
F_231 ( V_6 , V_272 . V_280 , V_272 . V_279 , V_272 . V_281 , V_272 . V_368 ,
V_272 . V_369 , V_272 . V_370 , V_272 . V_379 , V_272 . V_380 ,
V_272 . V_382 , V_272 . V_383 , V_272 . V_384 ) ;
V_396 = V_272 . V_278 + V_272 . V_279 + V_272 . V_280 + V_272 . V_281 ;
V_397 = V_272 . V_322 + V_272 . V_369 + V_272 . V_368 + V_272 . V_370 ;
V_398 = ( V_309 -> V_377 * 1000 ) / V_396 ;
V_399 = ( V_309 -> V_377 * 1000 ) / V_396 / V_397 ;
F_10 ( L_41 , V_309 -> V_377 ) ;
F_10 ( L_42 ,
V_272 . V_280 , V_272 . V_279 , V_272 . V_281 , V_272 . V_368 , V_272 . V_369 , V_272 . V_370 ) ;
F_10 ( L_43 ,
V_272 . V_379 , V_272 . V_380 , V_272 . V_382 ,
V_272 . V_383 , V_272 . V_384 ) ;
F_10 ( L_44 , V_398 , V_399 ) ;
} else {
if ( V_272 . V_310 == true )
V_272 . V_322 /= 2 ;
}
F_141 ( V_6 , V_272 . V_278 , V_272 . V_322 ) ;
}
static void F_236 ( enum V_5 V_6 , T_1 V_400 ,
T_1 V_401 )
{
F_83 ( V_400 < 1 ) ;
F_83 ( V_401 < 1 ) ;
F_1 ( F_237 ( V_6 ) ,
F_91 ( V_400 , 23 , 16 ) | F_91 ( V_401 , 7 , 0 ) ) ;
if ( F_12 ( V_38 ) == false &&
V_6 == V_142 )
V_3 . V_402 = F_238 () / V_400 ;
}
static void F_239 ( enum V_5 V_6 , int * V_400 ,
int * V_401 )
{
T_2 V_244 ;
V_244 = F_3 ( F_237 ( V_6 ) ) ;
* V_400 = F_125 ( V_244 , 23 , 16 ) ;
* V_401 = F_125 ( V_244 , 7 , 0 ) ;
}
unsigned long F_238 ( void )
{
struct V_403 * V_404 ;
unsigned long V_44 = 0 ;
switch ( F_240 () ) {
case V_405 :
V_44 = F_241 () ;
break;
case V_406 :
V_404 = F_242 ( 0 ) ;
V_44 = F_243 ( V_404 ) ;
break;
case V_407 :
V_404 = F_242 ( 1 ) ;
V_44 = F_243 ( V_404 ) ;
break;
default:
F_120 () ;
return 0 ;
}
return V_44 ;
}
unsigned long F_197 ( enum V_5 V_6 )
{
struct V_403 * V_404 ;
int V_408 ;
unsigned long V_44 ;
T_2 V_244 ;
if ( F_135 ( V_6 ) ) {
V_244 = F_3 ( F_237 ( V_6 ) ) ;
V_408 = F_125 ( V_244 , 23 , 16 ) ;
switch ( F_244 ( V_6 ) ) {
case V_405 :
V_44 = F_241 () ;
break;
case V_406 :
V_404 = F_242 ( 0 ) ;
V_44 = F_243 ( V_404 ) ;
break;
case V_407 :
V_404 = F_242 ( 1 ) ;
V_44 = F_243 ( V_404 ) ;
break;
default:
F_120 () ;
return 0 ;
}
return V_44 / V_408 ;
} else {
return F_238 () ;
}
}
unsigned long F_196 ( enum V_5 V_6 )
{
unsigned long V_44 ;
if ( F_135 ( V_6 ) ) {
int V_409 ;
T_2 V_244 ;
V_244 = F_3 ( F_237 ( V_6 ) ) ;
V_409 = F_125 ( V_244 , 7 , 0 ) ;
V_44 = F_197 ( V_6 ) ;
return V_44 / V_409 ;
} else {
return V_3 . V_410 ;
}
}
void F_245 ( unsigned long V_269 )
{
V_3 . V_410 = V_269 ;
}
unsigned long F_189 ( void )
{
return V_3 . V_402 ;
}
static unsigned long F_200 ( enum V_57 V_58 )
{
enum V_5 V_6 ;
if ( V_58 == V_59 )
return 0 ;
V_6 = F_124 ( V_58 ) ;
return F_196 ( V_6 ) ;
}
static unsigned long F_201 ( enum V_57 V_58 )
{
enum V_5 V_6 ;
if ( V_58 == V_59 )
return 0 ;
V_6 = F_124 ( V_58 ) ;
return F_197 ( V_6 ) ;
}
static void F_246 ( struct V_411 * V_412 , enum V_5 V_6 )
{
int V_408 , V_409 ;
enum V_413 V_414 ;
F_247 ( V_412 , L_45 , V_11 [ V_6 ] . V_55 ) ;
V_414 = F_244 ( V_6 ) ;
F_247 ( V_412 , L_46 , V_11 [ V_6 ] . V_55 ,
F_248 ( V_414 ) ,
F_249 ( V_414 ) ) ;
F_239 ( V_6 , & V_408 , & V_409 ) ;
F_247 ( V_412 , L_47 ,
F_197 ( V_6 ) , V_408 ) ;
F_247 ( V_412 , L_48 ,
F_196 ( V_6 ) , V_409 ) ;
}
void F_250 ( struct V_411 * V_412 )
{
int V_408 ;
T_2 V_244 ;
enum V_413 V_415 = F_240 () ;
if ( F_60 () )
return;
F_247 ( V_412 , L_49 ) ;
F_247 ( V_412 , L_50 ,
F_248 ( V_415 ) ,
F_249 ( V_415 ) ) ;
F_247 ( V_412 , L_51 , F_238 () ) ;
if ( F_12 ( V_38 ) ) {
F_247 ( V_412 , L_52 ) ;
V_244 = F_3 ( V_416 ) ;
V_408 = F_125 ( V_244 , 23 , 16 ) ;
F_247 ( V_412 , L_47 ,
( F_238 () / V_408 ) , V_408 ) ;
}
F_246 ( V_412 , V_142 ) ;
if ( F_12 ( V_25 ) )
F_246 ( V_412 , V_143 ) ;
if ( F_12 ( V_28 ) )
F_246 ( V_412 , V_144 ) ;
F_63 () ;
}
static void F_251 ( struct V_411 * V_412 )
{
int V_16 , V_17 ;
const char * V_417 [] = {
[ V_142 ] = L_53 ,
[ V_31 ] = L_54 ,
[ V_143 ] = L_55 ,
[ V_144 ] = L_56 ,
} ;
const char * V_418 [] = {
[ V_34 ] = L_57 ,
[ V_139 ] = L_58 ,
[ V_140 ] = L_59 ,
[ V_141 ] = L_60 ,
} ;
const char * * V_419 ;
#define F_252 ( V_44 ) seq_printf(s, "%-50s %08x\n", #r, dispc_read_reg(r))
if ( F_60 () )
return;
F_252 ( V_420 ) ;
F_252 ( V_421 ) ;
F_252 ( V_422 ) ;
F_252 ( V_423 ) ;
F_252 ( V_424 ) ;
F_252 ( V_327 ) ;
F_252 ( V_150 ) ;
F_252 ( V_425 ) ;
F_252 ( V_426 ) ;
F_252 ( V_427 ) ;
if ( F_12 ( V_22 ) ||
F_12 ( V_23 ) )
F_252 ( V_109 ) ;
if ( F_12 ( V_25 ) ) {
F_252 ( V_56 ) ;
F_252 ( V_428 ) ;
}
if ( F_12 ( V_28 ) ) {
F_252 ( V_429 ) ;
F_252 ( V_430 ) ;
}
if ( F_12 ( V_431 ) )
F_252 ( V_432 ) ;
#undef F_252
#define F_253 ( V_16 , V_55 ) name(i)
#define F_252 ( V_16 , V_44 ) seq_printf(s, "%s(%s)%*s %08x\n", #r, p_names[i], \
(int)(48 - strlen(#r) - strlen(p_names[i])), " ", \
dispc_read_reg(DISPC_REG(i, r)))
V_419 = V_417 ;
for ( V_16 = 0 ; V_16 < F_13 () ; V_16 ++ ) {
F_252 ( V_16 , F_216 ) ;
F_252 ( V_16 , F_218 ) ;
F_252 ( V_16 , F_142 ) ;
if ( V_16 == V_31 )
continue;
F_252 ( V_16 , F_216 ) ;
F_252 ( V_16 , F_218 ) ;
F_252 ( V_16 , F_232 ) ;
F_252 ( V_16 , F_233 ) ;
F_252 ( V_16 , F_234 ) ;
F_252 ( V_16 , F_237 ) ;
F_252 ( V_16 , F_142 ) ;
F_252 ( V_16 , V_433 ) ;
F_252 ( V_16 , V_434 ) ;
F_252 ( V_16 , V_435 ) ;
if ( F_12 ( V_32 ) ) {
F_252 ( V_16 , F_136 ) ;
F_252 ( V_16 , F_137 ) ;
F_252 ( V_16 , F_138 ) ;
}
}
V_419 = V_418 ;
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ ) {
F_252 ( V_16 , F_98 ) ;
F_252 ( V_16 , F_100 ) ;
F_252 ( V_16 , F_106 ) ;
F_252 ( V_16 , F_108 ) ;
F_252 ( V_16 , F_74 ) ;
F_252 ( V_16 , F_149 ) ;
F_252 ( V_16 , F_146 ) ;
F_252 ( V_16 , F_118 ) ;
F_252 ( V_16 , F_116 ) ;
if ( F_12 ( V_33 ) )
F_252 ( V_16 , F_150 ) ;
if ( V_16 == V_34 ) {
F_252 ( V_16 , V_436 ) ;
F_252 ( V_16 , V_437 ) ;
continue;
}
F_252 ( V_16 , F_155 ) ;
F_252 ( V_16 , F_109 ) ;
F_252 ( V_16 , F_158 ) ;
F_252 ( V_16 , F_160 ) ;
if ( F_12 ( V_36 ) ) {
F_252 ( V_16 , F_102 ) ;
F_252 ( V_16 , F_104 ) ;
F_252 ( V_16 , F_156 ) ;
F_252 ( V_16 , F_162 ) ;
F_252 ( V_16 , F_164 ) ;
}
if ( F_12 ( V_37 ) )
F_252 ( V_16 , F_169 ) ;
if ( F_12 ( V_33 ) )
F_252 ( V_16 , F_150 ) ;
if ( F_12 ( V_431 ) )
F_252 ( V_16 , V_438 ) ;
}
#undef F_253
#undef F_252
#define F_253 ( V_58 , V_55 , V_16 ) name(plane, i)
#define F_252 ( V_58 , V_55 , V_16 ) \
seq_printf(s, "%s_%d(%s)%*s %08x\n", #name, i, p_names[plane], \
(int)(46 - strlen(#name) - strlen(p_names[plane])), " ", \
dispc_read_reg(DISPC_REG(plane, name, i)))
for ( V_16 = 1 ; V_16 < F_27 () ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_252 ( V_16 , F_77 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_252 ( V_16 , F_79 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ )
F_252 ( V_16 , F_94 , V_17 ) ;
if ( F_12 ( V_35 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_252 ( V_16 , F_81 , V_17 ) ;
}
if ( F_12 ( V_36 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_252 ( V_16 , F_84 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_252 ( V_16 , F_86 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_252 ( V_16 , F_88 , V_17 ) ;
}
}
F_63 () ;
#undef F_253
#undef F_252
}
int F_254 ( unsigned long F_238 ,
struct V_439 * V_440 )
{
if ( V_440 -> V_400 > 255 || V_440 -> V_400 == 0 )
return - V_282 ;
if ( V_440 -> V_401 < 1 || V_440 -> V_401 > 255 )
return - V_282 ;
V_440 -> V_441 = F_238 / V_440 -> V_400 ;
V_440 -> V_442 = V_440 -> V_441 / V_440 -> V_401 ;
return 0 ;
}
bool F_255 ( unsigned long V_3 ,
unsigned long V_443 , unsigned long V_444 ,
T_9 V_445 , void * V_446 )
{
int V_447 , V_448 , V_449 ;
int V_450 , V_451 , V_452 ;
unsigned long V_442 , V_441 ;
unsigned long V_453 ;
unsigned long V_454 , V_455 ;
unsigned V_456 ;
unsigned long V_457 ;
#ifdef F_256
V_456 = F_256 ;
#else
V_456 = 0 ;
#endif
V_454 = F_257 ( V_458 ) ;
V_455 = F_188 ( V_458 ) ;
V_453 = F_188 ( V_459 ) ;
V_443 = V_443 ? V_443 : 1 ;
V_444 = V_444 ? V_444 : V_460 ;
V_448 = F_180 ( F_178 ( V_3 , V_453 ) , 1ul ) ;
V_449 = F_151 ( V_3 / V_443 , 255ul ) ;
for ( V_447 = V_448 ; V_447 <= V_449 ; ++ V_447 ) {
V_441 = V_3 / V_447 ;
V_451 = F_180 ( F_178 ( V_441 , V_444 ) , V_454 ) ;
V_452 = F_151 ( V_441 / V_443 , V_455 ) ;
for ( V_450 = V_451 ; V_450 <= V_452 ; ++ V_450 ) {
V_442 = V_441 / V_450 ;
if ( F_12 ( V_38 ) )
V_457 = F_189 () ;
else
V_457 = V_441 ;
if ( V_457 < V_442 * V_456 )
continue;
if ( V_445 ( V_447 , V_450 , V_441 , V_442 , V_446 ) )
return true ;
}
}
return false ;
}
void F_226 ( enum V_5 V_6 ,
const struct V_439 * V_440 )
{
F_10 ( L_61 , V_440 -> V_441 , V_440 -> V_400 ) ;
F_10 ( L_62 , V_440 -> V_442 , V_440 -> V_401 ) ;
F_236 ( V_6 , V_440 -> V_400 , V_440 -> V_401 ) ;
}
int F_258 ( enum V_5 V_6 ,
struct V_439 * V_440 )
{
unsigned long V_457 ;
V_457 = F_238 () ;
V_440 -> V_400 = F_6 ( F_237 ( V_6 ) , 23 , 16 ) ;
V_440 -> V_401 = F_6 ( F_237 ( V_6 ) , 7 , 0 ) ;
V_440 -> V_441 = V_457 / V_440 -> V_400 ;
V_440 -> V_442 = V_440 -> V_441 / V_440 -> V_401 ;
return 0 ;
}
T_2 F_259 ( void )
{
return F_3 ( V_423 ) ;
}
void F_59 ( T_2 V_461 )
{
F_1 ( V_423 , V_461 ) ;
}
T_2 F_260 ( void )
{
return F_3 ( V_424 ) ;
}
void F_261 ( T_2 V_461 )
{
T_2 V_462 = F_3 ( V_424 ) ;
F_59 ( ( V_461 ^ V_462 ) & V_461 ) ;
F_1 ( V_424 , V_461 ) ;
}
void F_262 ( void )
{
F_8 ( V_421 , 2 , 4 , 3 ) ;
}
void F_263 ( void )
{
F_8 ( V_421 , 1 , 4 , 3 ) ;
}
static void F_264 ( void )
{
T_2 V_244 ;
if ( F_12 ( V_38 ) ) {
V_244 = F_3 ( V_416 ) ;
V_244 = F_123 ( V_244 , 1 , 0 , 0 ) ;
V_244 = F_123 ( V_244 , 1 , 23 , 16 ) ;
F_1 ( V_416 , V_244 ) ;
V_3 . V_402 = F_238 () ;
}
if ( F_12 ( V_463 ) )
F_8 ( V_150 , 1 , 9 , 9 ) ;
F_95 () ;
F_214 ( V_464 ) ;
F_143 () ;
F_128 () ;
F_112 () ;
if ( V_3 . V_49 -> V_465 )
F_8 ( V_466 , 1 , 0 , 0 ) ;
}
static int T_10 F_265 ( struct V_403 * V_45 )
{
const struct V_467 * V_468 ;
struct V_467 * V_469 ;
V_469 = F_266 ( & V_45 -> V_46 , sizeof( * V_469 ) , V_470 ) ;
if ( ! V_469 ) {
F_267 ( & V_45 -> V_46 , L_63 ) ;
return - V_471 ;
}
switch ( F_268 () ) {
case V_472 :
V_468 = & V_473 ;
break;
case V_474 :
V_468 = & V_475 ;
break;
case V_476 :
case V_477 :
case V_478 :
V_468 = & V_479 ;
break;
case V_480 :
case V_481 :
case V_482 :
V_468 = & V_483 ;
break;
case V_484 :
V_468 = & V_485 ;
break;
default:
return - V_486 ;
}
memcpy ( V_469 , V_468 , sizeof( * V_469 ) ) ;
V_3 . V_49 = V_469 ;
return 0 ;
}
int F_269 ( T_11 V_487 , void * V_488 )
{
return F_270 ( & V_3 . V_45 -> V_46 , V_3 . V_489 , V_487 ,
V_490 , L_64 , V_488 ) ;
}
void F_271 ( void * V_488 )
{
F_272 ( & V_3 . V_45 -> V_46 , V_3 . V_489 , V_488 ) ;
}
static int T_10 F_273 ( struct V_403 * V_45 )
{
T_2 V_491 ;
int V_44 = 0 ;
struct V_492 * V_493 ;
V_3 . V_45 = V_45 ;
V_44 = F_265 ( V_3 . V_45 ) ;
if ( V_44 )
return V_44 ;
V_493 = F_274 ( V_3 . V_45 , V_494 , 0 ) ;
if ( ! V_493 ) {
F_75 ( L_65 ) ;
return - V_282 ;
}
V_3 . V_4 = F_275 ( & V_45 -> V_46 , V_493 -> V_171 ,
F_276 ( V_493 ) ) ;
if ( ! V_3 . V_4 ) {
F_75 ( L_66 ) ;
return - V_471 ;
}
V_3 . V_489 = F_277 ( V_3 . V_45 , 0 ) ;
if ( V_3 . V_489 < 0 ) {
F_75 ( L_67 ) ;
return - V_486 ;
}
F_278 ( & V_45 -> V_46 ) ;
V_44 = F_60 () ;
if ( V_44 )
goto V_495;
F_264 () ;
V_491 = F_3 ( V_420 ) ;
F_279 ( & V_45 -> V_46 , L_68 ,
F_125 ( V_491 , 7 , 4 ) , F_125 ( V_491 , 3 , 0 ) ) ;
F_63 () ;
F_280 () ;
F_281 ( L_69 , F_251 ) ;
return 0 ;
V_495:
F_282 ( & V_45 -> V_46 ) ;
return V_44 ;
}
static int T_12 F_283 ( struct V_403 * V_45 )
{
F_282 ( & V_45 -> V_46 ) ;
F_284 () ;
return 0 ;
}
static int F_285 ( struct V_496 * V_46 )
{
F_9 () ;
return 0 ;
}
static int F_286 ( struct V_496 * V_46 )
{
F_264 () ;
F_57 () ;
return 0 ;
}
int T_10 F_287 ( void )
{
return F_288 ( & V_497 , F_273 ) ;
}
void T_12 F_289 ( void )
{
F_290 ( & V_497 ) ;
}
