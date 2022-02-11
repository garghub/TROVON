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
static T_6 F_171 ( int V_254 , T_5 V_255 )
{
if ( V_254 == 1 )
return 1 ;
else if ( V_254 > 1 )
return 1 + ( V_254 - 1 ) * V_255 ;
else if ( V_254 < 0 )
return 1 - ( - V_254 + 1 ) * V_255 ;
else
F_120 () ;
return 0 ;
}
static void F_172 ( T_5 V_214 , bool V_256 ,
T_1 V_257 ,
T_1 V_100 , T_1 V_101 ,
enum V_111 V_112 , bool V_240 ,
unsigned int V_258 ,
unsigned * V_259 , unsigned * V_260 ,
T_6 * V_261 , T_6 * V_262 , int V_263 , int V_264 )
{
T_5 V_255 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
case V_123 :
case V_124 :
V_255 = 4 ;
break;
default:
V_255 = F_170 ( V_112 ) / 8 ;
break;
}
F_10 ( L_15 , V_214 , V_257 ,
V_100 , V_101 ) ;
switch ( V_214 + V_256 * 4 ) {
case V_236 :
case V_238 :
if ( V_112 == V_123 ||
V_112 == V_124 )
V_100 = V_100 >> 1 ;
case V_237 :
case V_239 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = V_258 * V_257 * V_255 ;
else
* V_259 = 0 ;
* V_261 = F_171 ( 1 +
( V_264 * V_257 - V_263 * V_100 ) +
( V_240 ? V_257 : 0 ) , V_255 ) ;
* V_262 = F_171 ( V_263 , V_255 ) ;
break;
case V_236 + 4 :
case V_238 + 4 :
if ( V_112 == V_123 ||
V_112 == V_124 )
V_100 = V_100 >> 1 ;
case V_237 + 4 :
case V_239 + 4 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = V_258 * V_257 * V_255 ;
else
* V_259 = 0 ;
* V_261 = F_171 ( 1 -
( V_264 * V_257 + V_263 * V_100 ) -
( V_240 ? V_257 : 0 ) , V_255 ) ;
* V_262 = F_171 ( V_263 , V_255 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_173 ( T_5 V_214 , bool V_256 ,
T_1 V_257 ,
T_1 V_100 , T_1 V_101 ,
enum V_111 V_112 , bool V_240 ,
unsigned int V_258 ,
unsigned * V_259 , unsigned * V_260 ,
T_6 * V_261 , T_6 * V_262 , int V_263 , int V_264 )
{
T_5 V_255 ;
T_1 V_265 , V_266 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
default:
V_255 = F_170 ( V_112 ) / 8 ;
break;
}
F_10 ( L_15 , V_214 , V_257 ,
V_100 , V_101 ) ;
if ( V_214 == V_236 || V_214 == V_238 ) {
V_265 = V_100 ;
V_266 = V_101 ;
} else {
V_265 = V_101 ;
V_266 = V_100 ;
}
switch ( V_214 + V_256 * 4 ) {
case V_236 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( 1 +
( V_264 * V_257 - V_265 * V_263 ) +
( V_240 ? V_257 : 0 ) , V_255 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_262 = F_171 ( V_263 , 2 * V_255 ) ;
else
* V_262 = F_171 ( V_263 , V_255 ) ;
break;
case V_237 :
* V_260 = V_257 * ( V_266 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( V_257 * ( V_266 * V_263 - 1 ) +
V_264 + ( V_240 ? 1 : 0 ) , V_255 ) ;
* V_262 = F_171 ( - V_263 * V_257 , V_255 ) ;
break;
case V_238 :
* V_260 = ( V_257 * ( V_266 - 1 ) + V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( - 1 -
( V_264 * V_257 - V_265 * V_263 ) -
( V_240 ? V_257 : 0 ) , V_255 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_262 = F_171 ( - V_263 , 2 * V_255 ) ;
else
* V_262 = F_171 ( - V_263 , V_255 ) ;
break;
case V_239 :
* V_260 = ( V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( - V_257 * ( V_266 * V_263 - 1 ) -
V_264 - ( V_240 ? 1 : 0 ) , V_255 ) ;
* V_262 = F_171 ( V_263 * V_257 , V_255 ) ;
break;
case V_236 + 4 :
* V_260 = ( V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( V_264 * V_257 * 2 - 1 +
( V_240 ? V_257 : 0 ) ,
V_255 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_262 = F_171 ( - V_263 , 2 * V_255 ) ;
else
* V_262 = F_171 ( - V_263 , V_255 ) ;
break;
case V_237 + 4 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( - V_257 * ( V_266 * V_263 - 1 ) +
V_264 + ( V_240 ? 1 : 0 ) ,
V_255 ) ;
* V_262 = F_171 ( V_263 * V_257 , V_255 ) ;
break;
case V_238 + 4 :
* V_260 = V_257 * ( V_266 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( 1 - V_264 * V_257 * 2 -
( V_240 ? V_257 : 0 ) ,
V_255 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_262 = F_171 ( V_263 , 2 * V_255 ) ;
else
* V_262 = F_171 ( V_263 , V_255 ) ;
break;
case V_239 + 4 :
* V_260 = ( V_257 * ( V_266 - 1 ) + V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( V_257 * ( V_266 * V_263 - 1 ) -
V_264 - ( V_240 ? 1 : 0 ) ,
V_255 ) ;
* V_262 = F_171 ( - V_263 * V_257 , V_255 ) ;
break;
default:
F_120 () ;
return;
}
}
static void F_174 ( T_1 V_257 , T_1 V_100 ,
enum V_111 V_112 , bool V_240 ,
unsigned int V_258 , unsigned * V_259 , unsigned * V_260 ,
T_6 * V_261 , T_6 * V_262 , int V_263 , int V_264 )
{
T_5 V_255 ;
switch ( V_112 ) {
case V_129 :
case V_130 :
case V_131 :
case V_132 :
F_120 () ;
return;
default:
V_255 = F_170 ( V_112 ) / 8 ;
break;
}
F_10 ( L_16 , V_257 , V_100 ) ;
* V_260 = 0 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_171 ( 1 + ( V_264 * V_257 - V_100 * V_263 ) +
( V_240 ? V_257 : 0 ) , V_255 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 )
* V_262 = F_171 ( V_263 , 2 * V_255 ) ;
else
* V_262 = F_171 ( V_263 , V_255 ) ;
}
static int F_175 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_270 , T_1 V_271 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 )
{
const int V_272 = F_176 ( V_101 , V_213 ) ;
unsigned long V_273 ;
static const T_5 V_274 [ 3 ] = { 8 , 10 , 20 } ;
T_8 V_2 , V_275 ;
int V_16 ;
V_273 = V_270 -> V_276 + V_270 -> V_277 + V_270 -> V_278 + V_270 -> V_279 - V_212 ;
V_16 = 0 ;
if ( V_213 < V_101 )
V_16 ++ ;
if ( V_212 < V_100 )
V_16 ++ ;
V_275 = F_177 ( ( T_8 ) ( V_270 -> V_279 + V_270 -> V_278 + V_270 -> V_277 ) * V_268 , V_267 ) ;
F_10 ( L_17 , V_275 , V_274 [ V_16 ] ) ;
if ( V_275 <= V_274 [ V_16 ] )
return - V_280 ;
V_2 = F_177 ( ( T_8 ) ( V_273 - V_271 ) * V_268 , V_267 ) ;
F_10 ( L_18 ,
V_2 , F_178 ( 0 , V_272 - 2 ) * V_100 ) ;
if ( V_2 < F_178 ( 0 , V_272 - 2 ) * V_100 )
return - V_280 ;
V_2 = F_177 ( ( T_8 ) V_273 * V_268 , V_267 ) ;
F_10 ( L_19 ,
V_2 , F_178 ( 0 , V_272 - 1 ) * V_100 ) ;
if ( V_2 < F_178 ( 0 , V_272 - 1 ) * V_100 )
return - V_280 ;
return 0 ;
}
static unsigned long F_179 ( unsigned long V_267 ,
const struct V_269 * V_281 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 )
{
T_2 V_282 = 0 ;
T_8 V_283 ;
if ( V_101 <= V_213 && V_100 <= V_212 )
return ( unsigned long ) V_267 ;
if ( V_101 > V_213 ) {
unsigned int V_284 = V_281 -> V_276 ;
V_283 = V_267 * V_101 * V_212 ;
F_180 ( V_283 , 2 * V_213 * V_284 ) ;
V_282 = V_283 ;
if ( V_101 > 2 * V_213 ) {
if ( V_284 == V_212 )
return 0 ;
V_283 = V_267 * ( V_101 - 2 * V_213 ) * V_212 ;
F_180 ( V_283 , 2 * V_213 * ( V_284 - V_212 ) ) ;
V_282 = F_181 ( T_2 , V_282 , V_283 ) ;
}
}
if ( V_100 > V_212 ) {
V_283 = V_267 * V_100 ;
F_180 ( V_283 , V_212 ) ;
V_282 = F_181 ( T_2 , V_282 , V_283 ) ;
if ( V_112 == V_121 )
V_282 <<= 1 ;
}
return V_282 ;
}
static unsigned long F_182 ( unsigned long V_267 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 , bool V_285 )
{
if ( V_101 > V_213 && V_100 > V_212 )
return V_267 * 4 ;
else
return V_267 * 2 ;
}
static unsigned long F_183 ( unsigned long V_267 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 , bool V_285 )
{
unsigned int V_286 , V_287 ;
if ( V_100 > 3 * V_212 )
V_286 = 4 ;
else if ( V_100 > 2 * V_212 )
V_286 = 3 ;
else if ( V_100 > V_212 )
V_286 = 2 ;
else
V_286 = 1 ;
if ( V_101 > V_213 )
V_287 = 2 ;
else
V_287 = 1 ;
return V_267 * V_287 * V_286 ;
}
static unsigned long F_184 ( unsigned long V_267 , T_1 V_100 ,
T_1 V_101 , T_1 V_212 , T_1 V_213 , bool V_285 )
{
if ( V_285 )
return 1 ;
if ( V_100 > V_212 )
return F_176 ( V_267 , V_212 ) * V_100 ;
else
return V_267 ;
}
static int F_185 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_281 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_263 , int * V_264 , int * V_288 , int * V_289 ,
T_1 V_271 , unsigned long * V_282 , bool V_285 )
{
int error ;
T_1 V_290 , V_291 ;
int V_292 = F_186 ( * V_288 , * V_289 ) ;
const int V_293 =
F_187 ( V_294 ) ;
* V_65 = false ;
do {
V_291 = F_176 ( V_101 , * V_289 ) ;
V_290 = F_176 ( V_100 , * V_288 ) ;
* V_282 = V_3 . V_49 -> V_295 ( V_267 , V_290 ,
V_291 , V_212 , V_213 , V_285 ) ;
error = ( V_290 > V_293 || ! * V_282 ||
* V_282 > F_188 () ) ;
if ( error ) {
if ( * V_288 == * V_289 ) {
* V_288 = V_292 ;
++ * V_289 ;
} else {
F_189 ( * V_288 , * V_289 ) ;
if ( * V_288 < * V_289 )
++ * V_288 ;
}
}
} while ( * V_288 <= * V_263 && * V_289 <= * V_264 && error );
if ( V_290 > V_293 ) {
F_75 ( L_20 ) ;
return - V_280 ;
}
return 0 ;
}
static int F_190 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_281 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_263 , int * V_264 , int * V_288 , int * V_289 ,
T_1 V_271 , unsigned long * V_282 , bool V_285 )
{
int error ;
T_1 V_290 , V_291 ;
int V_292 = F_186 ( * V_288 , * V_289 ) ;
const int V_293 =
F_187 ( V_294 ) ;
do {
V_291 = F_176 ( V_101 , * V_289 ) ;
V_290 = F_176 ( V_100 , * V_288 ) ;
* V_282 = F_179 ( V_267 , V_281 ,
V_290 , V_291 , V_212 , V_213 , V_112 ) ;
error = F_175 ( V_267 , V_268 , V_281 ,
V_271 , V_290 , V_291 , V_212 ,
V_213 ) ;
if ( V_290 > V_293 )
if ( V_291 > V_213 &&
V_291 < V_213 * 2 )
* V_65 = false ;
if ( ! * V_65 )
* V_282 = V_3 . V_49 -> V_295 ( V_267 , V_290 ,
V_291 , V_212 , V_213 ,
V_285 ) ;
error = ( error || V_290 > V_293 * 2 ||
( V_290 > V_293 && * V_65 ) ||
! * V_282 || * V_282 > F_188 () ) ;
if ( error ) {
if ( * V_288 == * V_289 ) {
* V_288 = V_292 ;
++ * V_289 ;
} else {
F_189 ( * V_288 , * V_289 ) ;
if ( * V_288 < * V_289 )
++ * V_288 ;
}
}
} while ( * V_288 <= * V_263 && * V_289 <= * V_264 && error );
if ( F_175 ( V_267 , V_268 , V_281 , V_271 , V_100 ,
V_101 , V_212 , V_213 ) ) {
F_75 ( L_21 ) ;
return - V_280 ;
}
if ( V_290 > ( V_293 * 2 ) ) {
F_75 ( L_22 ) ;
F_75 ( L_23 ) ;
return - V_280 ;
}
if ( V_290 > V_293 && * V_65 ) {
F_75 ( L_24 ) ;
return - V_280 ;
}
return 0 ;
}
static int F_191 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_281 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_263 , int * V_264 , int * V_288 , int * V_289 ,
T_1 V_271 , unsigned long * V_282 , bool V_285 )
{
T_1 V_290 , V_296 ;
int V_297 = * V_288 ;
T_1 V_291 = F_176 ( V_101 , * V_289 ) ;
const int V_293 =
F_187 ( V_294 ) ;
const int V_298 = F_187 ( V_299 ) ;
if ( V_285 ) {
V_296 = V_212 * V_298 ;
} else {
V_296 = F_188 () /
F_176 ( V_267 , V_212 ) ;
}
* V_288 = F_176 ( V_100 , V_296 ) ;
* V_288 = * V_288 > V_297 ? * V_288 : V_297 ;
if ( * V_288 > * V_263 )
return - V_280 ;
do {
V_290 = F_176 ( V_100 , * V_288 ) ;
} while ( * V_288 <= * V_263 &&
V_290 > V_293 && ++ * V_288 );
if ( V_290 > V_293 ) {
F_75 ( L_25 ) ;
return - V_280 ;
}
* V_282 = V_3 . V_49 -> V_295 ( V_267 , V_290 , V_291 ,
V_212 , V_213 , V_285 ) ;
return 0 ;
}
static int F_192 ( unsigned long V_267 , unsigned long V_268 ,
enum V_97 V_98 ,
const struct V_269 * V_281 ,
T_1 V_100 , T_1 V_101 , T_1 V_212 , T_1 V_213 ,
enum V_111 V_112 , bool * V_65 ,
int * V_263 , int * V_264 , T_1 V_271 ,
enum V_133 V_134 , bool V_285 )
{
const int V_298 = F_187 ( V_299 ) ;
const int V_300 = 16 ;
unsigned long V_282 = 0 ;
int V_288 , V_289 , V_301 ;
if ( V_100 == V_212 && V_101 == V_213 )
return 0 ;
if ( ( V_98 & V_302 ) == 0 )
return - V_280 ;
if ( V_285 ) {
* V_263 = * V_264 = 1 ;
} else {
* V_263 = V_300 ;
* V_264 = ( V_134 == V_136 &&
F_12 ( V_135 ) ) ?
2 : V_300 ;
}
if ( V_112 == V_129 ||
V_112 == V_130 ||
V_112 == V_131 ||
V_112 == V_132 ) {
* V_263 = 1 ;
* V_264 = 1 ;
* V_65 = false ;
return 0 ;
}
V_288 = F_176 ( F_176 ( V_100 , V_212 ) , V_298 ) ;
V_289 = F_176 ( F_176 ( V_101 , V_213 ) , V_298 ) ;
if ( V_288 > * V_263 || V_212 > V_100 * 8 )
return - V_280 ;
if ( V_289 > * V_264 || V_213 > V_101 * 8 )
return - V_280 ;
V_301 = V_3 . V_49 -> V_303 ( V_267 , V_268 , V_281 , V_100 , V_101 ,
V_212 , V_213 , V_112 , V_65 ,
V_263 , V_264 , & V_288 , & V_289 , V_271 , & V_282 ,
V_285 ) ;
if ( V_301 )
return V_301 ;
F_10 ( L_26 , V_282 ) ;
F_10 ( L_27 , F_188 () ) ;
if ( ! V_282 || V_282 > F_188 () ) {
F_75 ( L_28
L_29
L_27 ,
V_282 , F_188 () ) ;
return - V_280 ;
}
* V_263 = V_288 ;
* V_264 = V_289 ;
return 0 ;
}
int F_193 ( enum V_57 V_58 , enum V_5 V_6 ,
const struct V_304 * V_305 ,
const struct V_269 * V_306 ,
int * V_263 , int * V_264 )
{
enum V_97 V_98 = F_194 ( V_58 ) ;
bool V_65 = true ;
bool V_240 = 0 ;
T_1 V_291 = V_305 -> V_101 ;
T_1 V_290 = V_305 -> V_100 ;
bool V_215 = V_306 -> V_307 ;
T_1 V_212 , V_213 ;
int V_271 = V_305 -> V_271 ;
unsigned long V_267 = F_195 ( V_6 ) ;
unsigned long V_268 = F_196 ( V_6 ) ;
V_212 = V_305 -> V_212 == 0 ? V_305 -> V_100 : V_305 -> V_212 ;
V_213 = V_305 -> V_213 == 0 ? V_305 -> V_101 : V_305 -> V_213 ;
if ( V_215 && V_305 -> V_101 == V_213 )
V_240 = 1 ;
if ( V_215 ) {
if ( V_240 )
V_291 /= 2 ;
V_213 /= 2 ;
F_10 ( L_30 ,
V_291 , V_213 ) ;
}
if ( ! F_197 ( V_58 , V_305 -> V_112 ) )
return - V_280 ;
return F_192 ( V_267 , V_268 , V_98 , V_306 , V_290 ,
V_291 , V_212 , V_213 , V_305 -> V_112 ,
& V_65 , V_263 , V_264 , V_271 ,
V_305 -> V_134 , false ) ;
}
static int F_198 ( enum V_57 V_58 ,
enum V_97 V_98 , T_2 V_96 , T_2 V_308 ,
T_1 V_257 , int V_271 , int V_309 , T_1 V_100 , T_1 V_101 ,
T_1 V_212 , T_1 V_213 , enum V_111 V_112 ,
T_5 V_214 , bool V_256 , T_5 V_102 , T_5 V_310 ,
T_5 V_105 , enum V_133 V_134 ,
bool V_311 , const struct V_269 * V_281 ,
bool V_285 )
{
bool V_65 = true ;
bool V_240 = 0 ;
int V_44 , V_312 = 0 ;
unsigned V_259 , V_260 ;
T_6 V_261 ;
T_6 V_262 ;
T_1 V_313 , V_314 ;
unsigned int V_258 = 0 ;
T_1 V_291 = V_101 ;
T_1 V_290 = V_100 ;
int V_263 = 1 , V_264 = 1 ;
bool V_215 = V_281 -> V_307 ;
unsigned long V_267 = F_199 ( V_58 ) ;
unsigned long V_268 = F_200 ( V_58 ) ;
if ( V_96 == 0 )
return - V_280 ;
V_212 = V_212 == 0 ? V_100 : V_212 ;
V_213 = V_213 == 0 ? V_101 : V_213 ;
if ( V_215 && V_101 == V_213 )
V_240 = 1 ;
if ( V_215 ) {
if ( V_240 )
V_291 /= 2 ;
V_309 /= 2 ;
V_213 /= 2 ;
F_10 ( L_31
L_32 , V_291 , V_309 ,
V_213 ) ;
}
if ( ! F_197 ( V_58 , V_112 ) )
return - V_280 ;
V_44 = F_192 ( V_267 , V_268 , V_98 , V_281 , V_290 ,
V_291 , V_212 , V_213 , V_112 ,
& V_65 , & V_263 , & V_264 , V_271 ,
V_134 , V_285 ) ;
if ( V_44 )
return V_44 ;
V_290 = F_176 ( V_290 , V_263 ) ;
V_291 = F_176 ( V_291 , V_264 ) ;
if ( V_112 == V_123 ||
V_112 == V_124 ||
V_112 == V_114 )
V_312 = 1 ;
if ( V_215 && ! V_240 ) {
if ( ! V_291 || V_291 == V_213 )
V_258 = 0 ;
else
V_258 = V_291 / V_213 / 2 ;
}
if ( V_240 )
V_258 = 1 ;
V_259 = 0 ;
V_260 = 0 ;
V_261 = 0 ;
V_262 = 0 ;
if ( V_58 == V_59 ) {
V_313 = V_212 ;
V_314 = V_213 ;
} else {
V_313 = V_290 ;
V_314 = V_101 ;
}
if ( V_134 == V_136 )
F_174 ( V_257 , V_313 ,
V_112 , V_240 , V_258 ,
& V_259 , & V_260 , & V_261 , & V_262 ,
V_263 , V_264 ) ;
else if ( V_134 == V_315 )
F_173 ( V_214 , V_256 , V_257 ,
V_313 , V_314 ,
V_112 , V_240 , V_258 ,
& V_259 , & V_260 , & V_261 , & V_262 ,
V_263 , V_264 ) ;
else
F_172 ( V_214 , V_256 ,
V_257 , V_313 , V_314 ,
V_112 , V_240 , V_258 ,
& V_259 , & V_260 , & V_261 , & V_262 ,
V_263 , V_264 ) ;
F_10 ( L_33 ,
V_259 , V_260 , V_261 , V_262 ) ;
F_119 ( V_58 , V_112 ) ;
F_121 ( V_58 , V_134 ) ;
F_97 ( V_58 , V_96 + V_259 ) ;
F_99 ( V_58 , V_96 + V_260 ) ;
if ( V_114 == V_112 ) {
F_101 ( V_58 , V_308 + V_259 ) ;
F_103 ( V_58 , V_308 + V_260 ) ;
}
F_117 ( V_58 , V_261 ) ;
F_115 ( V_58 , V_262 ) ;
F_10 ( L_34 , V_271 , V_309 , V_290 ,
V_291 , V_212 , V_213 ) ;
F_105 ( V_58 , V_98 , V_271 , V_309 ) ;
F_107 ( V_58 , V_290 , V_291 ) ;
if ( V_98 & V_302 ) {
F_168 ( V_58 , V_290 , V_291 , V_212 ,
V_213 , V_215 , V_65 , V_240 ,
V_112 , V_214 ) ;
F_110 ( V_58 , V_212 , V_213 ) ;
F_139 ( V_58 , V_312 ) ;
}
F_169 ( V_58 , V_214 , V_256 , V_112 ) ;
F_111 ( V_58 , V_98 , V_102 ) ;
F_113 ( V_58 , V_98 , V_310 ) ;
F_114 ( V_58 , V_98 , V_105 ) ;
F_140 ( V_58 , V_98 , V_311 ) ;
return 0 ;
}
int F_201 ( enum V_57 V_58 , const struct V_304 * V_305 ,
bool V_311 , const struct V_269 * V_281 ,
bool V_285 )
{
int V_44 ;
enum V_97 V_98 = F_194 ( V_58 ) ;
enum V_5 V_6 ;
V_6 = F_124 ( V_58 ) ;
F_10 ( L_35
L_36 ,
V_58 , V_305 -> V_96 , V_305 -> V_308 , V_305 -> V_257 , V_305 -> V_271 ,
V_305 -> V_309 , V_305 -> V_100 , V_305 -> V_101 , V_305 -> V_212 , V_305 -> V_213 ,
V_305 -> V_112 , V_305 -> V_214 , V_305 -> V_256 , V_6 , V_311 ) ;
V_44 = F_198 ( V_58 , V_98 , V_305 -> V_96 , V_305 -> V_308 ,
V_305 -> V_257 , V_305 -> V_271 , V_305 -> V_309 , V_305 -> V_100 , V_305 -> V_101 ,
V_305 -> V_212 , V_305 -> V_213 , V_305 -> V_112 , V_305 -> V_214 ,
V_305 -> V_256 , V_305 -> V_102 , V_305 -> V_310 , V_305 -> V_105 ,
V_305 -> V_134 , V_311 , V_281 , V_285 ) ;
return V_44 ;
}
int F_202 ( const struct V_316 * V_317 ,
bool V_285 , const struct V_269 * V_281 )
{
int V_44 ;
T_2 V_243 ;
enum V_57 V_58 = V_59 ;
const int V_271 = 0 , V_309 = 0 ;
const T_5 V_102 = 0 , V_105 = 0 ;
const bool V_311 = false ;
bool V_318 ;
int V_290 = V_281 -> V_276 ;
int V_291 = V_281 -> V_319 ;
enum V_97 V_98 =
V_302 | V_104 ;
F_10 ( L_37
L_38 , V_317 -> V_96 , V_317 -> V_308 , V_290 ,
V_291 , V_317 -> V_100 , V_317 -> V_101 , V_317 -> V_112 , V_317 -> V_214 ,
V_317 -> V_256 ) ;
V_44 = F_198 ( V_58 , V_98 , V_317 -> V_96 , V_317 -> V_308 ,
V_317 -> V_320 , V_271 , V_309 , V_290 , V_291 , V_317 -> V_100 ,
V_317 -> V_101 , V_317 -> V_112 , V_317 -> V_214 , V_317 -> V_256 , V_102 ,
V_317 -> V_310 , V_105 , V_317 -> V_134 ,
V_311 , V_281 , V_285 ) ;
switch ( V_317 -> V_112 ) {
case V_119 :
case V_122 :
case V_118 :
case V_116 :
case V_117 :
case V_120 :
case V_128 :
case V_115 :
V_318 = true ;
break;
default:
V_318 = false ;
break;
}
V_243 = F_3 ( F_74 ( V_58 ) ) ;
V_243 = F_123 ( V_243 , V_318 , 10 , 10 ) ;
V_243 = F_123 ( V_243 , V_285 , 19 , 19 ) ;
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
F_7 ( V_6 , V_321 , V_60 ) ;
F_5 ( V_6 , V_321 ) ;
}
bool F_71 ( enum V_5 V_6 )
{
return ! ! F_5 ( V_6 , V_321 ) ;
}
void F_206 ( bool V_60 )
{
F_203 ( V_59 , V_60 ) ;
}
bool F_207 ( void )
{
return F_204 ( V_59 ) ;
}
static void F_208 ( bool V_322 )
{
if ( ! F_12 ( V_323 ) )
return;
F_8 ( V_324 , V_322 ? 1 : 0 , 29 , 29 ) ;
}
void F_209 ( bool V_60 )
{
if ( ! F_12 ( V_325 ) )
return;
F_8 ( V_324 , V_60 ? 1 : 0 , 28 , 28 ) ;
}
void F_210 ( bool V_60 )
{
if ( ! F_12 ( V_326 ) )
return;
F_8 ( V_324 , V_60 ? 1 : 0 , 27 , 27 ) ;
}
static void F_211 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_327 , V_60 ) ;
}
static void F_212 ( enum V_5 V_6 )
{
F_7 ( V_6 , V_328 , 1 ) ;
}
void F_213 ( enum V_329 V_330 )
{
F_8 ( V_150 , V_330 , 2 , 1 ) ;
}
static void F_214 ( enum V_5 V_6 , T_2 V_331 )
{
F_1 ( F_215 ( V_6 ) , V_331 ) ;
}
static void F_216 ( enum V_5 V_332 ,
enum V_333 type ,
T_2 V_334 )
{
F_7 ( V_332 , V_335 , type ) ;
F_1 ( F_217 ( V_332 ) , V_334 ) ;
}
static void F_218 ( enum V_5 V_332 , bool V_60 )
{
F_7 ( V_332 , V_336 , V_60 ) ;
}
static void F_219 ( enum V_5 V_332 ,
bool V_60 )
{
if ( ! F_12 ( V_22 ) )
return;
if ( V_332 == V_142 )
F_8 ( V_150 , V_60 , 18 , 18 ) ;
else if ( V_332 == V_31 )
F_8 ( V_150 , V_60 , 19 , 19 ) ;
}
void F_220 ( enum V_5 V_6 ,
const struct V_337 * V_338 )
{
F_214 ( V_6 , V_338 -> V_339 ) ;
F_216 ( V_6 , V_338 -> V_340 , V_338 -> V_334 ) ;
F_218 ( V_6 , V_338 -> V_341 ) ;
F_219 ( V_6 ,
V_338 -> V_342 ) ;
if ( F_12 ( V_32 ) ) {
F_133 ( V_6 , V_338 -> V_343 ) ;
F_134 ( V_6 , & V_338 -> V_344 ) ;
}
}
static void F_221 ( enum V_5 V_6 , T_5 V_345 )
{
int V_346 ;
switch ( V_345 ) {
case 12 :
V_346 = 0 ;
break;
case 16 :
V_346 = 1 ;
break;
case 18 :
V_346 = 2 ;
break;
case 24 :
V_346 = 3 ;
break;
default:
F_120 () ;
return;
}
F_7 ( V_6 , V_347 , V_346 ) ;
}
static void F_222 ( enum V_348 V_330 )
{
T_2 V_243 ;
int V_349 , V_350 ;
switch ( V_330 ) {
case V_351 :
V_349 = 0 ;
V_350 = 0 ;
break;
case V_352 :
V_349 = 1 ;
V_350 = 0 ;
break;
case V_353 :
V_349 = 1 ;
V_350 = 1 ;
break;
default:
F_120 () ;
return;
}
V_243 = F_3 ( V_324 ) ;
V_243 = F_123 ( V_243 , V_349 , 15 , 15 ) ;
V_243 = F_123 ( V_243 , V_350 , 16 , 16 ) ;
F_1 ( V_324 , V_243 ) ;
}
static void F_223 ( enum V_5 V_6 , bool V_60 )
{
F_7 ( V_6 , V_354 , V_60 ) ;
}
void F_224 ( enum V_5 V_6 ,
const struct V_355 * V_356 )
{
F_222 ( V_356 -> V_357 ) ;
F_223 ( V_6 , V_356 -> V_358 ) ;
F_211 ( V_6 , V_356 -> V_359 ) ;
F_225 ( V_6 , & V_356 -> V_360 ) ;
F_221 ( V_6 , V_356 -> V_361 ) ;
F_208 ( V_356 -> V_362 ) ;
F_212 ( V_6 ) ;
}
static bool F_226 ( T_1 V_100 , T_1 V_101 )
{
return V_100 <= V_3 . V_49 -> V_363 &&
V_101 <= V_3 . V_49 -> V_364 ;
}
static bool F_227 ( int V_278 , int V_277 , int V_279 ,
int V_365 , int V_366 , int V_367 )
{
if ( V_278 < 1 || V_278 > V_3 . V_49 -> V_368 ||
V_277 < 1 || V_277 > V_3 . V_49 -> V_369 ||
V_279 < 1 || V_279 > V_3 . V_49 -> V_369 ||
V_365 < 1 || V_365 > V_3 . V_49 -> V_368 ||
V_366 < 0 || V_366 > V_3 . V_49 -> V_370 ||
V_367 < 0 || V_367 > V_3 . V_49 -> V_370 )
return false ;
return true ;
}
bool F_228 ( enum V_5 V_6 ,
const struct V_269 * V_306 )
{
bool V_371 ;
V_371 = F_226 ( V_306 -> V_276 , V_306 -> V_319 ) ;
if ( F_135 ( V_6 ) )
V_371 = V_371 && F_227 ( V_306 -> V_278 ,
V_306 -> V_277 , V_306 -> V_279 ,
V_306 -> V_365 , V_306 -> V_366 ,
V_306 -> V_367 ) ;
return V_371 ;
}
static void F_229 ( enum V_5 V_6 , int V_278 ,
int V_277 , int V_279 , int V_365 , int V_366 , int V_367 ,
enum V_372 V_373 ,
enum V_372 V_374 ,
enum V_375 V_376 ,
enum V_372 V_377 ,
enum V_375 V_378 )
{
T_2 V_379 , V_380 , V_243 ;
bool V_381 , V_382 , V_383 ;
V_379 = F_91 ( V_278 - 1 , V_3 . V_49 -> V_384 , 0 ) |
F_91 ( V_277 - 1 , V_3 . V_49 -> V_385 , 8 ) |
F_91 ( V_279 - 1 , V_3 . V_49 -> V_386 , 20 ) ;
V_380 = F_91 ( V_365 - 1 , V_3 . V_49 -> V_384 , 0 ) |
F_91 ( V_366 , V_3 . V_49 -> V_385 , 8 ) |
F_91 ( V_367 , V_3 . V_49 -> V_386 , 20 ) ;
F_1 ( F_230 ( V_6 ) , V_379 ) ;
F_1 ( F_231 ( V_6 ) , V_380 ) ;
switch ( V_376 ) {
case V_387 :
V_383 = false ;
break;
case V_388 :
V_383 = true ;
break;
case V_389 :
default:
F_120 () ;
}
switch ( V_378 ) {
case V_389 :
V_381 = false ;
V_382 = false ;
break;
case V_388 :
V_381 = true ;
V_382 = false ;
break;
case V_387 :
V_381 = true ;
V_382 = true ;
break;
default:
F_120 () ;
} ;
V_243 = F_3 ( F_232 ( V_6 ) ) ;
V_243 |= F_91 ( V_381 , 17 , 17 ) ;
V_243 |= F_91 ( V_382 , 16 , 16 ) ;
V_243 |= F_91 ( V_377 , 15 , 15 ) ;
V_243 |= F_91 ( V_383 , 14 , 14 ) ;
V_243 |= F_91 ( V_374 , 13 , 13 ) ;
V_243 |= F_91 ( V_373 , 12 , 12 ) ;
F_1 ( F_232 ( V_6 ) , V_243 ) ;
}
void F_233 ( enum V_5 V_6 ,
const struct V_269 * V_306 )
{
unsigned V_390 , V_391 ;
unsigned long V_392 , V_393 ;
struct V_269 V_270 = * V_306 ;
F_10 ( L_40 , V_6 , V_270 . V_276 , V_270 . V_319 ) ;
if ( ! F_228 ( V_6 , & V_270 ) ) {
F_120 () ;
return;
}
if ( F_135 ( V_6 ) ) {
F_229 ( V_6 , V_270 . V_278 , V_270 . V_277 , V_270 . V_279 , V_270 . V_365 ,
V_270 . V_366 , V_270 . V_367 , V_270 . V_373 , V_270 . V_374 ,
V_270 . V_376 , V_270 . V_377 , V_270 . V_378 ) ;
V_390 = V_270 . V_276 + V_270 . V_277 + V_270 . V_278 + V_270 . V_279 ;
V_391 = V_270 . V_319 + V_270 . V_366 + V_270 . V_365 + V_270 . V_367 ;
V_392 = ( V_306 -> V_394 * 1000 ) / V_390 ;
V_393 = ( V_306 -> V_394 * 1000 ) / V_390 / V_391 ;
F_10 ( L_41 , V_306 -> V_394 ) ;
F_10 ( L_42 ,
V_270 . V_278 , V_270 . V_277 , V_270 . V_279 , V_270 . V_365 , V_270 . V_366 , V_270 . V_367 ) ;
F_10 ( L_43 ,
V_270 . V_373 , V_270 . V_374 , V_270 . V_376 ,
V_270 . V_377 , V_270 . V_378 ) ;
F_10 ( L_44 , V_392 , V_393 ) ;
} else {
if ( V_270 . V_307 == true )
V_270 . V_319 /= 2 ;
}
F_141 ( V_6 , V_270 . V_276 , V_270 . V_319 ) ;
}
static void F_234 ( enum V_5 V_6 , T_1 V_395 ,
T_1 V_396 )
{
F_83 ( V_395 < 1 ) ;
F_83 ( V_396 < 1 ) ;
F_1 ( F_235 ( V_6 ) ,
F_91 ( V_395 , 23 , 16 ) | F_91 ( V_396 , 7 , 0 ) ) ;
}
static void F_236 ( enum V_5 V_6 , int * V_395 ,
int * V_396 )
{
T_2 V_243 ;
V_243 = F_3 ( F_235 ( V_6 ) ) ;
* V_395 = F_125 ( V_243 , 23 , 16 ) ;
* V_396 = F_125 ( V_243 , 7 , 0 ) ;
}
unsigned long F_237 ( void )
{
struct V_397 * V_398 ;
unsigned long V_44 = 0 ;
switch ( F_238 () ) {
case V_399 :
V_44 = F_239 () ;
break;
case V_400 :
V_398 = F_240 ( 0 ) ;
V_44 = F_241 ( V_398 ) ;
break;
case V_401 :
V_398 = F_240 ( 1 ) ;
V_44 = F_241 ( V_398 ) ;
break;
default:
F_120 () ;
return 0 ;
}
return V_44 ;
}
unsigned long F_196 ( enum V_5 V_6 )
{
struct V_397 * V_398 ;
int V_402 ;
unsigned long V_44 ;
T_2 V_243 ;
if ( F_135 ( V_6 ) ) {
V_243 = F_3 ( F_235 ( V_6 ) ) ;
V_402 = F_125 ( V_243 , 23 , 16 ) ;
switch ( F_242 ( V_6 ) ) {
case V_399 :
V_44 = F_239 () ;
break;
case V_400 :
V_398 = F_240 ( 0 ) ;
V_44 = F_241 ( V_398 ) ;
break;
case V_401 :
V_398 = F_240 ( 1 ) ;
V_44 = F_241 ( V_398 ) ;
break;
default:
F_120 () ;
return 0 ;
}
return V_44 / V_402 ;
} else {
return F_237 () ;
}
}
unsigned long F_195 ( enum V_5 V_6 )
{
unsigned long V_44 ;
if ( F_135 ( V_6 ) ) {
int V_403 ;
T_2 V_243 ;
V_243 = F_3 ( F_235 ( V_6 ) ) ;
V_403 = F_125 ( V_243 , 7 , 0 ) ;
V_44 = F_196 ( V_6 ) ;
return V_44 / V_403 ;
} else {
enum V_404 V_405 ;
V_405 = F_243 () ;
switch ( V_405 ) {
case V_406 :
return F_244 () ;
case V_407 :
return F_245 () ;
default:
F_120 () ;
return 0 ;
}
}
}
unsigned long F_188 ( void )
{
int V_402 ;
unsigned long V_408 = F_237 () ;
if ( F_12 ( V_38 ) )
V_402 = F_6 ( V_409 , 23 , 16 ) ;
else
V_402 = F_6 ( F_235 ( V_142 ) , 23 , 16 ) ;
return V_408 / V_402 ;
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
static void F_246 ( struct V_410 * V_411 , enum V_5 V_6 )
{
int V_402 , V_403 ;
enum V_412 V_413 ;
F_247 ( V_411 , L_45 , V_11 [ V_6 ] . V_55 ) ;
V_413 = F_242 ( V_6 ) ;
F_247 ( V_411 , L_46 , V_11 [ V_6 ] . V_55 ,
F_248 ( V_413 ) ,
F_249 ( V_413 ) ) ;
F_236 ( V_6 , & V_402 , & V_403 ) ;
F_247 ( V_411 , L_47 ,
F_196 ( V_6 ) , V_402 ) ;
F_247 ( V_411 , L_48 ,
F_195 ( V_6 ) , V_403 ) ;
}
void F_250 ( struct V_410 * V_411 )
{
int V_402 ;
T_2 V_243 ;
enum V_412 V_414 = F_238 () ;
if ( F_60 () )
return;
F_247 ( V_411 , L_49 ) ;
F_247 ( V_411 , L_50 ,
F_248 ( V_414 ) ,
F_249 ( V_414 ) ) ;
F_247 ( V_411 , L_51 , F_237 () ) ;
if ( F_12 ( V_38 ) ) {
F_247 ( V_411 , L_52 ) ;
V_243 = F_3 ( V_409 ) ;
V_402 = F_125 ( V_243 , 23 , 16 ) ;
F_247 ( V_411 , L_47 ,
( F_237 () / V_402 ) , V_402 ) ;
}
F_246 ( V_411 , V_142 ) ;
if ( F_12 ( V_25 ) )
F_246 ( V_411 , V_143 ) ;
if ( F_12 ( V_28 ) )
F_246 ( V_411 , V_144 ) ;
F_63 () ;
}
static void F_251 ( struct V_410 * V_411 )
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
#define F_252 ( V_44 ) seq_printf(s, "%-50s %08x\n", #r, dispc_read_reg(r))
if ( F_60 () )
return;
F_252 ( V_418 ) ;
F_252 ( V_419 ) ;
F_252 ( V_420 ) ;
F_252 ( V_421 ) ;
F_252 ( V_422 ) ;
F_252 ( V_324 ) ;
F_252 ( V_150 ) ;
F_252 ( V_423 ) ;
F_252 ( V_424 ) ;
F_252 ( V_425 ) ;
if ( F_12 ( V_22 ) ||
F_12 ( V_23 ) )
F_252 ( V_109 ) ;
if ( F_12 ( V_25 ) ) {
F_252 ( V_56 ) ;
F_252 ( V_426 ) ;
}
if ( F_12 ( V_28 ) ) {
F_252 ( V_427 ) ;
F_252 ( V_428 ) ;
}
#undef F_252
#define F_253 ( V_16 , V_55 ) name(i)
#define F_252 ( V_16 , V_44 ) seq_printf(s, "%s(%s)%*s %08x\n", #r, p_names[i], \
(int)(48 - strlen(#r) - strlen(p_names[i])), " ", \
dispc_read_reg(DISPC_REG(i, r)))
V_417 = V_415 ;
for ( V_16 = 0 ; V_16 < F_13 () ; V_16 ++ ) {
F_252 ( V_16 , F_215 ) ;
F_252 ( V_16 , F_217 ) ;
F_252 ( V_16 , F_142 ) ;
if ( V_16 == V_31 )
continue;
F_252 ( V_16 , F_215 ) ;
F_252 ( V_16 , F_217 ) ;
F_252 ( V_16 , F_230 ) ;
F_252 ( V_16 , F_231 ) ;
F_252 ( V_16 , F_232 ) ;
F_252 ( V_16 , F_235 ) ;
F_252 ( V_16 , F_142 ) ;
F_252 ( V_16 , V_429 ) ;
F_252 ( V_16 , V_430 ) ;
F_252 ( V_16 , V_431 ) ;
if ( F_12 ( V_32 ) ) {
F_252 ( V_16 , F_136 ) ;
F_252 ( V_16 , F_137 ) ;
F_252 ( V_16 , F_138 ) ;
}
}
V_417 = V_416 ;
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
F_252 ( V_16 , V_432 ) ;
if ( V_16 == V_34 ) {
F_252 ( V_16 , V_433 ) ;
F_252 ( V_16 , V_434 ) ;
continue;
}
F_252 ( V_16 , F_153 ) ;
F_252 ( V_16 , F_109 ) ;
F_252 ( V_16 , F_156 ) ;
F_252 ( V_16 , F_158 ) ;
if ( F_12 ( V_36 ) ) {
F_252 ( V_16 , F_102 ) ;
F_252 ( V_16 , F_104 ) ;
F_252 ( V_16 , F_154 ) ;
F_252 ( V_16 , F_160 ) ;
F_252 ( V_16 , F_162 ) ;
}
if ( F_12 ( V_37 ) )
F_252 ( V_16 , F_167 ) ;
if ( F_12 ( V_33 ) )
F_252 ( V_16 , V_432 ) ;
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
void F_254 ( unsigned long V_435 , unsigned long V_436 ,
struct V_437 * V_438 )
{
T_1 V_439 , V_440 ;
unsigned long V_441 ;
T_1 V_442 , V_443 ;
T_1 V_444 , V_445 ;
V_439 = F_255 ( V_446 ) ;
V_440 = F_187 ( V_446 ) ;
V_441 = 0 ;
V_442 = 0 ;
V_444 = 0 ;
for ( V_443 = 1 ; V_443 <= 255 ; ++ V_443 ) {
unsigned long V_447 = V_436 / V_443 ;
for ( V_445 = V_439 ; V_445 <= V_440 ; ++ V_445 ) {
unsigned long V_448 = V_447 / V_445 ;
long V_449 = abs ( V_441 - V_435 ) ;
long V_450 = abs ( V_448 - V_435 ) ;
if ( V_441 == 0 || V_450 < V_449 ) {
V_441 = V_448 ;
V_442 = V_443 ;
V_444 = V_445 ;
if ( V_448 == V_435 )
goto V_451;
}
if ( V_448 < V_435 )
break;
}
if ( V_447 / V_439 < V_435 )
break;
}
V_451:
V_438 -> V_395 = V_442 ;
V_438 -> V_396 = V_444 ;
V_438 -> V_447 = V_436 / V_438 -> V_395 ;
V_438 -> V_448 = V_438 -> V_447 / V_438 -> V_396 ;
}
int F_256 ( unsigned long F_237 ,
struct V_437 * V_438 )
{
if ( V_438 -> V_395 > 255 || V_438 -> V_395 == 0 )
return - V_280 ;
if ( V_438 -> V_396 < 1 || V_438 -> V_396 > 255 )
return - V_280 ;
V_438 -> V_447 = F_237 / V_438 -> V_395 ;
V_438 -> V_448 = V_438 -> V_447 / V_438 -> V_396 ;
return 0 ;
}
void F_225 ( enum V_5 V_6 ,
const struct V_437 * V_438 )
{
F_10 ( L_61 , V_438 -> V_447 , V_438 -> V_395 ) ;
F_10 ( L_62 , V_438 -> V_448 , V_438 -> V_396 ) ;
F_234 ( V_6 , V_438 -> V_395 , V_438 -> V_396 ) ;
}
int F_257 ( enum V_5 V_6 ,
struct V_437 * V_438 )
{
unsigned long V_436 ;
V_436 = F_237 () ;
V_438 -> V_395 = F_6 ( F_235 ( V_6 ) , 23 , 16 ) ;
V_438 -> V_396 = F_6 ( F_235 ( V_6 ) , 7 , 0 ) ;
V_438 -> V_447 = V_436 / V_438 -> V_395 ;
V_438 -> V_448 = V_438 -> V_447 / V_438 -> V_396 ;
return 0 ;
}
T_2 F_258 ( void )
{
return F_3 ( V_421 ) ;
}
void F_59 ( T_2 V_452 )
{
F_1 ( V_421 , V_452 ) ;
}
T_2 F_259 ( void )
{
return F_3 ( V_422 ) ;
}
void F_260 ( T_2 V_452 )
{
T_2 V_453 = F_3 ( V_422 ) ;
F_59 ( ( V_452 ^ V_453 ) & V_452 ) ;
F_1 ( V_422 , V_452 ) ;
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
V_243 = F_3 ( V_409 ) ;
V_243 = F_123 ( V_243 , 1 , 0 , 0 ) ;
V_243 = F_123 ( V_243 , 1 , 23 , 16 ) ;
F_1 ( V_409 , V_243 ) ;
}
if ( F_12 ( V_454 ) )
F_8 ( V_150 , 1 , 9 , 9 ) ;
F_95 () ;
F_213 ( V_455 ) ;
F_143 () ;
F_128 () ;
F_112 () ;
}
static int T_9 F_264 ( struct V_397 * V_45 )
{
const struct V_456 * V_457 ;
struct V_456 * V_458 ;
V_458 = F_265 ( & V_45 -> V_46 , sizeof( * V_458 ) , V_459 ) ;
if ( ! V_458 ) {
F_266 ( & V_45 -> V_46 , L_63 ) ;
return - V_460 ;
}
switch ( F_267 () ) {
case V_461 :
V_457 = & V_462 ;
break;
case V_463 :
V_457 = & V_464 ;
break;
case V_465 :
case V_466 :
case V_467 :
V_457 = & V_468 ;
break;
case V_469 :
case V_470 :
case V_471 :
V_457 = & V_472 ;
break;
case V_473 :
V_457 = & V_474 ;
break;
default:
return - V_475 ;
}
memcpy ( V_458 , V_457 , sizeof( * V_458 ) ) ;
V_3 . V_49 = V_458 ;
return 0 ;
}
int F_268 ( T_10 V_476 , void * V_477 )
{
return F_269 ( & V_3 . V_45 -> V_46 , V_3 . V_478 , V_476 ,
V_479 , L_64 , V_477 ) ;
}
void F_270 ( void * V_477 )
{
F_271 ( & V_3 . V_45 -> V_46 , V_3 . V_478 , V_477 ) ;
}
static int T_9 F_272 ( struct V_397 * V_45 )
{
T_2 V_480 ;
int V_44 = 0 ;
struct V_481 * V_482 ;
V_3 . V_45 = V_45 ;
V_44 = F_264 ( V_3 . V_45 ) ;
if ( V_44 )
return V_44 ;
V_482 = F_273 ( V_3 . V_45 , V_483 , 0 ) ;
if ( ! V_482 ) {
F_75 ( L_65 ) ;
return - V_280 ;
}
V_3 . V_4 = F_274 ( & V_45 -> V_46 , V_482 -> V_171 ,
F_275 ( V_482 ) ) ;
if ( ! V_3 . V_4 ) {
F_75 ( L_66 ) ;
return - V_460 ;
}
V_3 . V_478 = F_276 ( V_3 . V_45 , 0 ) ;
if ( V_3 . V_478 < 0 ) {
F_75 ( L_67 ) ;
return - V_475 ;
}
F_277 ( & V_45 -> V_46 ) ;
V_44 = F_60 () ;
if ( V_44 )
goto V_484;
F_263 () ;
V_480 = F_3 ( V_418 ) ;
F_278 ( & V_45 -> V_46 , L_68 ,
F_125 ( V_480 , 7 , 4 ) , F_125 ( V_480 , 3 , 0 ) ) ;
F_63 () ;
F_279 ( L_69 , F_251 ) ;
return 0 ;
V_484:
F_280 ( & V_45 -> V_46 ) ;
return V_44 ;
}
static int T_11 F_281 ( struct V_397 * V_45 )
{
F_280 ( & V_45 -> V_46 ) ;
return 0 ;
}
static int F_282 ( struct V_485 * V_46 )
{
F_9 () ;
return 0 ;
}
static int F_283 ( struct V_485 * V_46 )
{
F_57 () ;
return 0 ;
}
int T_9 F_284 ( void )
{
return F_285 ( & V_486 , F_272 ) ;
}
void T_11 F_286 ( void )
{
F_287 ( & V_486 ) ;
}
