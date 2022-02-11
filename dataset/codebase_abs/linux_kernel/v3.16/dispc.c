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
V_3 . V_40 = true ;
F_10 ( L_2 ) ;
}
static void F_56 ( void )
{
int V_16 , V_17 ;
F_10 ( L_3 ) ;
if ( ! V_3 . V_40 )
return;
F_57 ( V_20 ) ;
F_57 ( V_21 ) ;
if ( F_12 ( V_22 ) ||
F_12 ( V_23 ) )
F_57 ( V_24 ) ;
if ( F_12 ( V_25 ) )
F_57 ( V_27 ) ;
if ( F_12 ( V_28 ) )
F_57 ( V_30 ) ;
for ( V_16 = 0 ; V_16 < F_13 () ; V_16 ++ ) {
F_57 ( F_14 ( V_16 ) ) ;
F_57 ( F_15 ( V_16 ) ) ;
F_57 ( F_16 ( V_16 ) ) ;
if ( V_16 == V_31 )
continue;
F_57 ( F_17 ( V_16 ) ) ;
F_57 ( F_18 ( V_16 ) ) ;
F_57 ( F_19 ( V_16 ) ) ;
F_57 ( F_20 ( V_16 ) ) ;
F_57 ( F_21 ( V_16 ) ) ;
F_57 ( F_22 ( V_16 ) ) ;
F_57 ( F_23 ( V_16 ) ) ;
if ( F_12 ( V_32 ) ) {
F_57 ( F_24 ( V_16 ) ) ;
F_57 ( F_25 ( V_16 ) ) ;
F_57 ( F_26 ( V_16 ) ) ;
}
}
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ ) {
F_57 ( F_28 ( V_16 ) ) ;
F_57 ( F_29 ( V_16 ) ) ;
F_57 ( F_30 ( V_16 ) ) ;
F_57 ( F_31 ( V_16 ) ) ;
F_57 ( F_32 ( V_16 ) ) ;
F_57 ( F_33 ( V_16 ) ) ;
F_57 ( F_34 ( V_16 ) ) ;
F_57 ( F_35 ( V_16 ) ) ;
if ( F_12 ( V_33 ) )
F_57 ( F_36 ( V_16 ) ) ;
if ( V_16 == V_34 ) {
F_57 ( F_37 ( V_16 ) ) ;
F_57 ( F_38 ( V_16 ) ) ;
continue;
}
F_57 ( F_39 ( V_16 ) ) ;
F_57 ( F_40 ( V_16 ) ) ;
F_57 ( F_41 ( V_16 ) ) ;
F_57 ( F_42 ( V_16 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_57 ( F_43 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_57 ( F_44 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ )
F_57 ( F_45 ( V_16 , V_17 ) ) ;
if ( F_12 ( V_35 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_57 ( F_46 ( V_16 , V_17 ) ) ;
}
if ( F_12 ( V_36 ) ) {
F_57 ( F_47 ( V_16 ) ) ;
F_57 ( F_48 ( V_16 ) ) ;
F_57 ( F_49 ( V_16 ) ) ;
F_57 ( F_50 ( V_16 ) ) ;
F_57 ( F_51 ( V_16 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_57 ( F_52 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_57 ( F_53 ( V_16 , V_17 ) ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_57 ( F_54 ( V_16 , V_17 ) ) ;
}
if ( F_12 ( V_37 ) )
F_57 ( F_55 ( V_16 ) ) ;
}
if ( F_12 ( V_38 ) )
F_57 ( V_39 ) ;
F_57 ( V_19 ) ;
if ( F_12 ( V_25 ) )
F_57 ( V_26 ) ;
if ( F_12 ( V_28 ) )
F_57 ( V_29 ) ;
F_58 ( V_41 ) ;
F_57 ( V_18 ) ;
F_10 ( L_4 ) ;
}
int F_59 ( void )
{
int V_42 ;
F_10 ( L_5 ) ;
V_42 = F_60 ( & V_3 . V_43 -> V_44 ) ;
F_61 ( V_42 < 0 ) ;
return V_42 < 0 ? V_42 : 0 ;
}
void F_62 ( void )
{
int V_42 ;
F_10 ( L_6 ) ;
V_42 = F_63 ( & V_3 . V_43 -> V_44 ) ;
F_61 ( V_42 < 0 && V_42 != - V_45 ) ;
}
T_2 F_64 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_46 ;
}
T_2 F_65 ( enum V_5 V_6 )
{
if ( V_6 == V_31 && V_3 . V_47 -> V_48 )
return 0 ;
return V_11 [ V_6 ] . V_49 ;
}
T_2 F_66 ( enum V_5 V_6 )
{
return V_11 [ V_6 ] . V_50 ;
}
T_2 F_67 ( void )
{
return V_51 ;
}
bool F_68 ( enum V_5 V_6 )
{
return F_5 ( V_6 , V_52 ) == 1 ;
}
void F_69 ( enum V_5 V_6 )
{
F_61 ( F_70 ( V_6 ) == false ) ;
F_61 ( F_68 ( V_6 ) ) ;
F_10 ( L_7 , V_11 [ V_6 ] . V_53 ) ;
F_7 ( V_6 , V_52 , 1 ) ;
}
bool F_71 ( void )
{
return F_6 ( V_54 , 6 , 6 ) == 1 ;
}
void F_72 ( void )
{
enum V_55 V_56 = V_57 ;
bool V_58 , V_59 ;
V_58 = F_6 ( F_73 ( V_56 ) , 0 , 0 ) == 1 ;
if ( ! V_58 )
return;
V_59 = F_6 ( V_54 , 6 , 6 ) == 1 ;
if ( V_59 ) {
F_74 ( L_8 ) ;
return;
}
F_8 ( V_54 , 1 , 6 , 6 ) ;
}
static void F_75 ( enum V_55 V_56 , int V_13 , T_2 V_60 )
{
F_1 ( F_76 ( V_56 , V_13 ) , V_60 ) ;
}
static void F_77 ( enum V_55 V_56 , int V_13 , T_2 V_60 )
{
F_1 ( F_78 ( V_56 , V_13 ) , V_60 ) ;
}
static void F_79 ( enum V_55 V_56 , int V_13 , T_2 V_60 )
{
F_1 ( F_80 ( V_56 , V_13 ) , V_60 ) ;
}
static void F_81 ( enum V_55 V_56 , int V_13 , T_2 V_60 )
{
F_82 ( V_56 == V_34 ) ;
F_1 ( F_83 ( V_56 , V_13 ) , V_60 ) ;
}
static void F_84 ( enum V_55 V_56 , int V_13 ,
T_2 V_60 )
{
F_82 ( V_56 == V_34 ) ;
F_1 ( F_85 ( V_56 , V_13 ) , V_60 ) ;
}
static void F_86 ( enum V_55 V_56 , int V_13 , T_2 V_60 )
{
F_82 ( V_56 == V_34 ) ;
F_1 ( F_87 ( V_56 , V_13 ) , V_60 ) ;
}
static void F_88 ( enum V_55 V_56 , int V_61 ,
int V_62 , int V_63 ,
enum V_64 V_65 )
{
const struct V_66 * V_67 , * V_68 ;
int V_16 ;
V_67 = F_89 ( V_61 , true ) ;
V_68 = F_89 ( V_62 , V_63 ) ;
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
T_2 V_69 , V_70 ;
V_69 = F_90 ( V_67 [ V_16 ] . V_71 , 7 , 0 )
| F_90 ( V_67 [ V_16 ] . V_72 , 15 , 8 )
| F_90 ( V_67 [ V_16 ] . V_73 , 23 , 16 )
| F_90 ( V_67 [ V_16 ] . V_74 , 31 , 24 ) ;
V_70 = F_90 ( V_67 [ V_16 ] . V_75 , 7 , 0 )
| F_90 ( V_68 [ V_16 ] . V_72 , 15 , 8 )
| F_90 ( V_68 [ V_16 ] . V_73 , 23 , 16 )
| F_90 ( V_68 [ V_16 ] . V_74 , 31 , 24 ) ;
if ( V_65 == V_76 ) {
F_75 ( V_56 , V_16 , V_69 ) ;
F_77 ( V_56 , V_16 , V_70 ) ;
} else {
F_81 ( V_56 , V_16 , V_69 ) ;
F_84 ( V_56 , V_16 , V_70 ) ;
}
}
if ( V_63 ) {
for ( V_16 = 0 ; V_16 < 8 ; V_16 ++ ) {
T_2 V_77 ;
V_77 = F_90 ( V_68 [ V_16 ] . V_71 , 7 , 0 )
| F_90 ( V_68 [ V_16 ] . V_75 , 15 , 8 ) ;
if ( V_65 == V_76 )
F_79 ( V_56 , V_16 , V_77 ) ;
else
F_86 ( V_56 , V_16 , V_77 ) ;
}
}
}
static void F_91 ( enum V_55 V_56 ,
const struct V_78 * V_79 )
{
#define F_92 ( T_3 , T_4 ) (FLD_VAL(x, 26, 16) | FLD_VAL(y, 10, 0))
F_1 ( F_93 ( V_56 , 0 ) , F_92 ( V_79 -> V_80 , V_79 -> V_81 ) ) ;
F_1 ( F_93 ( V_56 , 1 ) , F_92 ( V_79 -> V_82 , V_79 -> V_83 ) ) ;
F_1 ( F_93 ( V_56 , 2 ) , F_92 ( V_79 -> V_84 , V_79 -> V_85 ) ) ;
F_1 ( F_93 ( V_56 , 3 ) , F_92 ( V_79 -> V_86 , V_79 -> V_87 ) ) ;
F_1 ( F_93 ( V_56 , 4 ) , F_92 ( 0 , V_79 -> V_88 ) ) ;
F_8 ( F_73 ( V_56 ) , V_79 -> V_89 , 11 , 11 ) ;
#undef F_92
}
static void F_94 ( void )
{
int V_16 ;
int V_90 = F_27 () ;
int V_91 = F_95 () ;
const struct V_78 V_92 = {
298 , 409 , 0 , 298 , - 208 , - 100 , 298 , 0 , 517 , 0 ,
} ;
const struct V_78 V_93 = {
66 , 112 , - 38 , 129 , - 94 , - 74 , 25 , - 18 , 112 , 0 ,
} ;
for ( V_16 = 1 ; V_16 < V_90 ; V_16 ++ )
F_91 ( V_16 , & V_92 ) ;
for (; V_16 < V_91 ; V_16 ++ )
F_91 ( V_16 , & V_93 ) ;
}
static void F_96 ( enum V_55 V_56 , T_2 V_94 )
{
F_1 ( F_97 ( V_56 ) , V_94 ) ;
}
static void F_98 ( enum V_55 V_56 , T_2 V_94 )
{
F_1 ( F_99 ( V_56 ) , V_94 ) ;
}
static void F_100 ( enum V_55 V_56 , T_2 V_94 )
{
F_1 ( F_101 ( V_56 ) , V_94 ) ;
}
static void F_102 ( enum V_55 V_56 , T_2 V_94 )
{
F_1 ( F_103 ( V_56 ) , V_94 ) ;
}
static void F_104 ( enum V_55 V_56 ,
enum V_95 V_96 , int T_3 , int T_4 )
{
T_2 V_2 ;
if ( ( V_96 & V_97 ) == 0 )
return;
V_2 = F_90 ( T_4 , 26 , 16 ) | F_90 ( T_3 , 10 , 0 ) ;
F_1 ( F_105 ( V_56 ) , V_2 ) ;
}
static void F_106 ( enum V_55 V_56 , int V_98 ,
int V_99 )
{
T_2 V_2 = F_90 ( V_99 - 1 , 26 , 16 ) | F_90 ( V_98 - 1 , 10 , 0 ) ;
if ( V_56 == V_34 || V_56 == V_57 )
F_1 ( F_107 ( V_56 ) , V_2 ) ;
else
F_1 ( F_108 ( V_56 ) , V_2 ) ;
}
static void F_109 ( enum V_55 V_56 , int V_98 ,
int V_99 )
{
T_2 V_2 ;
F_82 ( V_56 == V_34 ) ;
V_2 = F_90 ( V_99 - 1 , 26 , 16 ) | F_90 ( V_98 - 1 , 10 , 0 ) ;
if ( V_56 == V_57 )
F_1 ( F_108 ( V_56 ) , V_2 ) ;
else
F_1 ( F_107 ( V_56 ) , V_2 ) ;
}
static void F_110 ( enum V_55 V_56 ,
enum V_95 V_96 , T_5 V_100 )
{
if ( ( V_96 & V_101 ) == 0 )
return;
F_8 ( F_73 ( V_56 ) , V_100 , 27 , 26 ) ;
}
static void F_111 ( void )
{
int V_16 ;
if ( ! F_12 ( V_23 ) )
return;
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ )
F_8 ( F_73 ( V_16 ) , 1 , 25 , 25 ) ;
}
static void F_112 ( enum V_55 V_56 ,
enum V_95 V_96 , bool V_58 )
{
if ( ( V_96 & V_102 ) == 0 )
return;
F_8 ( F_73 ( V_56 ) , V_58 ? 1 : 0 , 28 , 28 ) ;
}
static void F_113 ( enum V_55 V_56 ,
enum V_95 V_96 , T_5 V_103 )
{
static const unsigned V_104 [] = { 0 , 8 , 16 , 24 , } ;
int V_105 ;
if ( ( V_96 & V_106 ) == 0 )
return;
V_105 = V_104 [ V_56 ] ;
F_8 ( V_107 , V_103 , V_105 + 7 , V_105 ) ;
}
static void F_114 ( enum V_55 V_56 , T_6 V_108 )
{
F_1 ( F_115 ( V_56 ) , V_108 ) ;
}
static void F_116 ( enum V_55 V_56 , T_6 V_108 )
{
F_1 ( F_117 ( V_56 ) , V_108 ) ;
}
static void F_118 ( enum V_55 V_56 ,
enum V_109 V_110 )
{
T_2 V_111 = 0 ;
if ( V_56 != V_34 ) {
switch ( V_110 ) {
case V_112 :
V_111 = 0x0 ; break;
case V_113 :
V_111 = 0x1 ; break;
case V_114 :
V_111 = 0x2 ; break;
case V_115 :
V_111 = 0x4 ; break;
case V_116 :
V_111 = 0x5 ; break;
case V_117 :
V_111 = 0x6 ; break;
case V_118 :
V_111 = 0x7 ; break;
case V_119 :
V_111 = 0x8 ; break;
case V_120 :
V_111 = 0x9 ; break;
case V_121 :
V_111 = 0xa ; break;
case V_122 :
V_111 = 0xb ; break;
case V_123 :
V_111 = 0xc ; break;
case V_124 :
V_111 = 0xd ; break;
case V_125 :
V_111 = 0xe ; break;
case V_126 :
V_111 = 0xf ; break;
default:
F_119 () ; return;
}
} else {
switch ( V_110 ) {
case V_127 :
V_111 = 0x0 ; break;
case V_128 :
V_111 = 0x1 ; break;
case V_129 :
V_111 = 0x2 ; break;
case V_130 :
V_111 = 0x3 ; break;
case V_115 :
V_111 = 0x4 ; break;
case V_116 :
V_111 = 0x5 ; break;
case V_117 :
V_111 = 0x6 ; break;
case V_118 :
V_111 = 0x7 ; break;
case V_119 :
V_111 = 0x8 ; break;
case V_120 :
V_111 = 0x9 ; break;
case V_113 :
V_111 = 0xa ; break;
case V_114 :
V_111 = 0xb ; break;
case V_123 :
V_111 = 0xc ; break;
case V_124 :
V_111 = 0xd ; break;
case V_125 :
V_111 = 0xe ; break;
case V_126 :
V_111 = 0xf ; break;
default:
F_119 () ; return;
}
}
F_8 ( F_73 ( V_56 ) , V_111 , 4 , 1 ) ;
}
static void F_120 ( enum V_55 V_56 ,
enum V_131 V_132 )
{
if ( F_12 ( V_133 ) == 0 )
return;
if ( V_132 == V_134 )
F_8 ( F_73 ( V_56 ) , 1 , 29 , 29 ) ;
else
F_8 ( F_73 ( V_56 ) , 0 , 29 , 29 ) ;
}
void F_121 ( enum V_55 V_56 , enum V_5 V_6 )
{
int V_105 ;
T_2 V_2 ;
int V_135 = 0 , V_136 = 0 ;
switch ( V_56 ) {
case V_34 :
V_105 = 8 ;
break;
case V_137 :
case V_138 :
case V_139 :
V_105 = 16 ;
break;
default:
F_119 () ;
return;
}
V_2 = F_3 ( F_73 ( V_56 ) ) ;
if ( F_12 ( V_25 ) ) {
switch ( V_6 ) {
case V_140 :
V_135 = 0 ;
V_136 = 0 ;
break;
case V_31 :
V_135 = 1 ;
V_136 = 0 ;
break;
case V_141 :
V_135 = 0 ;
V_136 = 1 ;
break;
case V_142 :
if ( F_12 ( V_28 ) ) {
V_135 = 0 ;
V_136 = 2 ;
} else {
F_119 () ;
return;
}
break;
default:
F_119 () ;
return;
}
V_2 = F_122 ( V_2 , V_135 , V_105 , V_105 ) ;
V_2 = F_122 ( V_2 , V_136 , 31 , 30 ) ;
} else {
V_2 = F_122 ( V_2 , V_6 , V_105 , V_105 ) ;
}
F_1 ( F_73 ( V_56 ) , V_2 ) ;
}
static enum V_5 F_123 ( enum V_55 V_56 )
{
int V_105 ;
T_2 V_2 ;
enum V_5 V_6 ;
switch ( V_56 ) {
case V_34 :
V_105 = 8 ;
break;
case V_137 :
case V_138 :
case V_139 :
V_105 = 16 ;
break;
default:
F_119 () ;
return 0 ;
}
V_2 = F_3 ( F_73 ( V_56 ) ) ;
if ( F_12 ( V_28 ) ) {
if ( F_124 ( V_2 , 31 , 30 ) == 0 )
V_6 = F_124 ( V_2 , V_105 , V_105 ) ;
else if ( F_124 ( V_2 , 31 , 30 ) == 1 )
V_6 = V_141 ;
else
V_6 = V_142 ;
} else if ( F_12 ( V_25 ) ) {
if ( F_124 ( V_2 , 31 , 30 ) == 0 )
V_6 = F_124 ( V_2 , V_105 , V_105 ) ;
else
V_6 = V_141 ;
} else {
V_6 = F_124 ( V_2 , V_105 , V_105 ) ;
}
return V_6 ;
}
void F_125 ( enum V_143 V_6 )
{
enum V_55 V_56 = V_57 ;
F_8 ( F_73 ( V_56 ) , V_6 , 18 , 16 ) ;
}
static void F_126 ( enum V_55 V_56 ,
enum V_144 V_145 )
{
static const unsigned V_104 [] = { 6 , 14 , 14 , 14 , 14 , } ;
int V_105 ;
V_105 = V_104 [ V_56 ] ;
F_8 ( F_73 ( V_56 ) , V_145 , V_105 + 1 , V_105 ) ;
}
static void F_127 ( void )
{
int V_16 ;
const int V_145 = V_146 ;
for ( V_16 = 0 ; V_16 < F_27 () ; ++ V_16 )
F_126 ( V_16 , V_145 ) ;
}
static T_2 F_128 ( enum V_55 V_56 )
{
unsigned V_147 = F_129 () ;
return V_147 * 8 ;
}
void F_130 ( bool V_58 )
{
if ( V_58 ) {
F_131 ( L_9 ) ;
return;
}
F_8 ( V_148 , V_58 , 9 , 9 ) ;
}
static void F_132 ( enum V_5 V_6 , bool V_58 )
{
if ( V_6 == V_31 )
return;
F_7 ( V_6 , V_149 , V_58 ) ;
}
static void F_133 ( enum V_5 V_6 ,
const struct V_150 * V_151 )
{
T_2 V_152 , V_153 , V_154 ;
if ( ! F_134 ( V_6 ) )
return;
V_152 = F_90 ( V_151 -> V_155 , 31 , 22 ) | F_90 ( V_151 -> V_156 , 20 , 11 ) |
F_90 ( V_151 -> V_157 , 9 , 0 ) ;
V_153 = F_90 ( V_151 -> V_158 , 31 , 22 ) | F_90 ( V_151 -> V_159 , 20 , 11 ) |
F_90 ( V_151 -> V_160 , 9 , 0 ) ;
V_154 = F_90 ( V_151 -> V_161 , 31 , 22 ) | F_90 ( V_151 -> V_162 , 20 , 11 ) |
F_90 ( V_151 -> V_163 , 9 , 0 ) ;
F_1 ( F_135 ( V_6 ) , V_152 ) ;
F_1 ( F_136 ( V_6 ) , V_153 ) ;
F_1 ( F_137 ( V_6 ) , V_154 ) ;
}
static void F_138 ( enum V_55 V_56 , bool V_58 )
{
T_2 V_2 ;
F_82 ( V_56 == V_34 ) ;
V_2 = F_3 ( F_73 ( V_56 ) ) ;
V_2 = F_122 ( V_2 , V_58 , 9 , 9 ) ;
F_1 ( F_73 ( V_56 ) , V_2 ) ;
}
static void F_139 ( enum V_55 V_56 ,
enum V_95 V_96 , bool V_58 )
{
static const unsigned V_104 [] = { 5 , 10 , 10 , 10 } ;
int V_105 ;
if ( ( V_96 & V_164 ) == 0 )
return;
V_105 = V_104 [ V_56 ] ;
F_8 ( F_73 ( V_56 ) , V_58 , V_105 , V_105 ) ;
}
static void F_140 ( enum V_5 V_6 , T_1 V_98 ,
T_1 V_99 )
{
T_2 V_2 ;
V_2 = F_90 ( V_99 - 1 , V_3 . V_47 -> V_165 , 16 ) |
F_90 ( V_98 - 1 , V_3 . V_47 -> V_166 , 0 ) ;
F_1 ( F_141 ( V_6 ) , V_2 ) ;
}
static void F_142 ( void )
{
T_2 V_167 ;
int V_168 ;
T_5 V_169 , V_170 ;
T_2 V_147 ;
V_147 = F_143 () ;
F_144 ( V_171 , & V_169 , & V_170 ) ;
for ( V_168 = 0 ; V_168 < V_3 . V_47 -> V_172 ; ++ V_168 ) {
V_167 = F_6 ( F_145 ( V_168 ) , V_169 , V_170 ) ;
V_167 *= V_147 ;
V_3 . V_173 [ V_168 ] = V_167 ;
V_3 . V_174 [ V_168 ] = V_168 ;
}
if ( V_3 . V_47 -> V_175 ) {
T_2 V_77 ;
V_77 = F_3 ( V_176 ) ;
V_77 = F_122 ( V_77 , 4 , 2 , 0 ) ;
V_77 = F_122 ( V_77 , 4 , 5 , 3 ) ;
V_77 = F_122 ( V_77 , 0 , 26 , 24 ) ;
V_77 = F_122 ( V_77 , 0 , 29 , 27 ) ;
F_1 ( V_176 , V_77 ) ;
V_3 . V_174 [ V_34 ] = V_57 ;
V_3 . V_174 [ V_57 ] = V_34 ;
}
}
static T_2 F_146 ( enum V_55 V_56 )
{
int V_168 ;
T_2 V_167 = 0 ;
for ( V_168 = 0 ; V_168 < V_3 . V_47 -> V_172 ; ++ V_168 ) {
if ( V_3 . V_174 [ V_168 ] == V_56 )
V_167 += V_3 . V_173 [ V_168 ] ;
}
return V_167 ;
}
void F_147 ( enum V_55 V_56 , T_2 V_15 , T_2 V_14 )
{
T_5 V_177 , V_178 , V_179 , V_180 ;
T_2 V_147 ;
V_147 = F_143 () ;
F_61 ( V_15 % V_147 != 0 ) ;
F_61 ( V_14 % V_147 != 0 ) ;
V_15 /= V_147 ;
V_14 /= V_147 ;
F_144 ( V_181 , & V_177 , & V_178 ) ;
F_144 ( V_182 , & V_179 , & V_180 ) ;
F_10 ( L_10 ,
V_56 ,
F_6 ( F_148 ( V_56 ) ,
V_179 , V_180 ) * V_147 ,
F_6 ( F_148 ( V_56 ) ,
V_177 , V_178 ) * V_147 ,
V_15 * V_147 , V_14 * V_147 ) ;
F_1 ( F_148 ( V_56 ) ,
F_90 ( V_14 , V_177 , V_178 ) |
F_90 ( V_15 , V_179 , V_180 ) ) ;
if ( F_12 ( V_33 ) && V_3 . V_47 -> V_183 &&
V_56 != V_57 )
F_1 ( F_149 ( V_56 ) , F_150 ( V_14 , 0xfffu ) ) ;
}
void F_151 ( bool V_58 )
{
if ( ! F_12 ( V_184 ) ) {
F_61 ( V_58 ) ;
return;
}
F_10 ( L_11 , V_58 ? L_12 : L_13 ) ;
F_8 ( V_148 , V_58 ? 1 : 0 , 14 , 14 ) ;
}
void F_152 ( enum V_55 V_56 ,
T_2 * V_185 , T_2 * V_186 , bool V_187 ,
bool V_188 )
{
unsigned V_189 = F_143 () ;
unsigned V_190 , V_191 , V_145 ;
int V_16 ;
V_145 = F_128 ( V_56 ) ;
V_190 = F_146 ( V_56 ) ;
if ( V_187 ) {
V_191 = 0 ;
for ( V_16 = 0 ; V_16 < F_27 () ; ++ V_16 )
V_191 += F_146 ( V_16 ) ;
} else {
V_191 = V_190 ;
}
if ( V_188 && F_12 ( V_192 ) ) {
* V_185 = V_190 - V_145 * 2 ;
* V_186 = V_191 - V_145 ;
} else if ( V_56 == V_57 ) {
* V_185 = 0 ;
* V_186 = V_145 ;
} else {
* V_185 = V_190 - V_145 ;
* V_186 = V_191 - V_189 ;
}
}
static void F_153 ( enum V_55 V_56 ,
int V_193 , int V_194 ,
enum V_64 V_65 )
{
T_2 V_2 ;
if ( V_65 == V_76 ) {
T_5 V_195 , V_196 , V_197 , V_198 ;
F_144 ( V_199 ,
& V_195 , & V_196 ) ;
F_144 ( V_200 ,
& V_197 , & V_198 ) ;
V_2 = F_90 ( V_194 , V_197 , V_198 ) |
F_90 ( V_193 , V_195 , V_196 ) ;
F_1 ( F_154 ( V_56 ) , V_2 ) ;
} else {
V_2 = F_90 ( V_194 , 28 , 16 ) | F_90 ( V_193 , 12 , 0 ) ;
F_1 ( F_155 ( V_56 ) , V_2 ) ;
}
}
static void F_156 ( enum V_55 V_56 , int V_201 , int V_202 )
{
T_2 V_2 ;
T_5 V_203 , V_204 , V_205 , V_206 ;
F_144 ( V_207 , & V_203 , & V_204 ) ;
F_144 ( V_208 , & V_205 , & V_206 ) ;
V_2 = F_90 ( V_202 , V_205 , V_206 ) |
F_90 ( V_201 , V_203 , V_204 ) ;
F_1 ( F_157 ( V_56 ) , V_2 ) ;
}
static void F_158 ( enum V_55 V_56 , int V_201 , int V_202 )
{
T_2 V_2 ;
T_5 V_203 , V_204 , V_205 , V_206 ;
F_144 ( V_207 , & V_203 , & V_204 ) ;
F_144 ( V_208 , & V_205 , & V_206 ) ;
V_2 = F_90 ( V_202 , V_205 , V_206 ) |
F_90 ( V_201 , V_203 , V_204 ) ;
F_1 ( F_159 ( V_56 ) , V_2 ) ;
}
static void F_160 ( enum V_55 V_56 , int V_201 ,
int V_202 )
{
T_2 V_2 ;
V_2 = F_90 ( V_202 , 26 , 16 ) | F_90 ( V_201 , 10 , 0 ) ;
F_1 ( F_161 ( V_56 ) , V_2 ) ;
}
static void F_162 ( enum V_55 V_56 , int V_201 ,
int V_202 )
{
T_2 V_2 ;
V_2 = F_90 ( V_202 , 26 , 16 ) | F_90 ( V_201 , 10 , 0 ) ;
F_1 ( F_163 ( V_56 ) , V_2 ) ;
}
static void F_164 ( enum V_55 V_56 ,
T_1 V_209 , T_1 V_210 ,
T_1 V_211 , T_1 V_212 ,
bool V_63 , T_5 V_213 ,
enum V_64 V_65 )
{
int V_61 , V_62 ;
V_61 = 1024 * V_209 / V_211 ;
V_62 = 1024 * V_210 / V_212 ;
F_88 ( V_56 , V_61 , V_62 , V_63 ,
V_65 ) ;
F_153 ( V_56 , V_61 , V_62 , V_65 ) ;
}
static void F_165 ( enum V_55 V_56 ,
T_1 V_209 , T_1 V_210 , T_1 V_211 , T_1 V_212 ,
bool V_214 , enum V_109 V_110 , T_5 V_213 )
{
int V_215 , V_216 ;
int V_217 , V_218 ;
int V_219 , V_220 ;
int V_1 ;
struct V_221 {
T_7 V_222 , V_223 ;
T_7 V_224 , V_225 ;
T_7 V_226 , V_227 ;
T_7 V_228 , V_229 ;
};
const struct V_221 * V_230 ;
const struct V_221 * V_231 ;
static const struct V_221 V_232 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ 1 , 2 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 2 , 0 , 1 } ,
{ - 1 , 2 , - 1 , 2 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_221 V_233 [ 4 ] = {
{ 0 , 1 , 0 , 1 , - 3 , 4 , - 1 , 4 } ,
{ - 1 , 4 , - 3 , 4 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , - 1 , 4 , - 3 , 4 } ,
{ - 3 , 4 , - 3 , 4 , - 1 , 1 , 0 , 1 } ,
} ;
static const struct V_221 V_234 [ 4 ] = {
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ - 1 , 1 , 0 , 1 , 0 , 1 , 0 , 1 } ,
{ 0 , 1 , 0 , 1 , - 1 , 1 , 0 , 1 } ,
} ;
switch ( V_213 ) {
case V_235 :
V_1 = 0 ;
break;
case V_236 :
V_1 = 1 ;
break;
case V_237 :
V_1 = 2 ;
break;
case V_238 :
V_1 = 3 ;
break;
default:
F_119 () ;
return;
}
switch ( V_110 ) {
case V_112 :
if ( V_214 )
V_230 = V_233 ;
else
V_230 = V_232 ;
break;
case V_121 :
case V_122 :
V_230 = V_234 ;
break;
default:
F_119 () ;
return;
}
V_231 = & V_230 [ V_1 ] ;
V_219 = 1024 * V_209 / V_211 ;
V_220 = 1024 * V_210 / V_212 ;
V_215 = ( V_231 -> V_222 * V_219 / V_231 -> V_223 ) % 1024 ;
V_216 = ( V_231 -> V_224 * V_219 / V_231 -> V_225 ) % 1024 ;
V_217 = ( V_231 -> V_226 * V_220 / V_231 -> V_227 ) % 1024 ;
V_218 = ( V_231 -> V_228 * V_220 / V_231 -> V_229 ) % 1024 ;
F_160 ( V_56 , V_215 , V_217 ) ;
F_162 ( V_56 , V_216 , V_218 ) ;
}
static void F_166 ( enum V_55 V_56 ,
T_1 V_209 , T_1 V_210 ,
T_1 V_211 , T_1 V_212 ,
bool V_214 , bool V_63 ,
bool V_239 , enum V_109 V_110 ,
T_5 V_213 )
{
int V_240 = 0 ;
int V_241 = 0 ;
T_2 V_242 ;
F_164 ( V_56 , V_209 , V_210 ,
V_211 , V_212 , V_63 ,
V_213 , V_76 ) ;
V_242 = F_3 ( F_73 ( V_56 ) ) ;
V_242 &= ~ ( ( 0x3 << 5 ) | ( 0x1 << 21 ) ) ;
V_242 |= ( V_209 != V_211 ) ? ( 1 << 5 ) : 0 ;
V_242 |= ( V_210 != V_212 ) ? ( 1 << 6 ) : 0 ;
V_242 |= V_63 ? ( 1 << 21 ) : 0 ;
if ( F_12 ( V_243 ) ) {
V_242 &= ~ ( 0x3 << 7 ) ;
V_242 |= ( V_209 <= V_211 ) ? 0 : ( 1 << 7 ) ;
V_242 |= ( V_210 <= V_212 ) ? 0 : ( 1 << 8 ) ;
}
if ( F_12 ( V_244 ) ) {
V_242 &= ~ ( 0x1 << 22 ) ;
V_242 |= V_63 ? ( 1 << 22 ) : 0 ;
}
F_1 ( F_73 ( V_56 ) , V_242 ) ;
if ( V_214 && ! V_239 ) {
V_241 = 0 ;
V_240 = ( ( 1024 * V_210 / V_212 ) / 2 ) & 0x3ff ;
if ( V_240 >= 1024 / 2 ) {
V_241 = 1024 / 2 ;
V_240 -= V_241 ;
}
}
F_156 ( V_56 , 0 , V_240 ) ;
F_158 ( V_56 , 0 , V_241 ) ;
}
static void F_167 ( enum V_55 V_56 ,
T_1 V_209 , T_1 V_210 ,
T_1 V_211 , T_1 V_212 ,
bool V_214 , bool V_63 ,
bool V_239 , enum V_109 V_110 ,
T_5 V_213 )
{
int V_245 = V_211 != V_209 ;
int V_246 = V_212 != V_210 ;
bool V_247 = V_56 != V_57 ? true : false ;
if ( ! F_12 ( V_36 ) )
return;
if ( ( V_110 != V_121 &&
V_110 != V_122 &&
V_110 != V_112 ) ) {
if ( V_56 != V_57 )
F_8 ( F_168 ( V_56 ) , 0 , 8 , 8 ) ;
return;
}
F_165 ( V_56 , V_209 , V_210 , V_211 ,
V_212 , V_214 , V_110 , V_213 ) ;
switch ( V_110 ) {
case V_112 :
if ( V_247 ) {
V_210 >>= 1 ;
V_209 >>= 1 ;
} else {
V_210 <<= 1 ;
V_209 <<= 1 ;
}
break;
case V_121 :
case V_122 :
if ( V_213 == V_235 ||
V_213 == V_237 ) {
if ( V_247 )
V_209 >>= 1 ;
else
V_209 <<= 1 ;
}
if ( V_213 != V_235 )
V_245 = V_246 = true ;
break;
default:
F_119 () ;
return;
}
if ( V_211 != V_209 )
V_245 = true ;
if ( V_212 != V_210 )
V_246 = true ;
F_164 ( V_56 , V_209 , V_210 ,
V_211 , V_212 , V_63 ,
V_213 , V_248 ) ;
if ( V_56 != V_57 )
F_8 ( F_168 ( V_56 ) ,
( V_245 || V_246 ) ? 1 : 0 , 8 , 8 ) ;
F_8 ( F_73 ( V_56 ) , V_245 ? 1 : 0 , 5 , 5 ) ;
F_8 ( F_73 ( V_56 ) , V_246 ? 1 : 0 , 6 , 6 ) ;
}
static void F_169 ( enum V_55 V_56 ,
T_1 V_209 , T_1 V_210 ,
T_1 V_211 , T_1 V_212 ,
bool V_214 , bool V_63 ,
bool V_239 , enum V_109 V_110 ,
T_5 V_213 )
{
F_82 ( V_56 == V_34 ) ;
F_166 ( V_56 ,
V_209 , V_210 ,
V_211 , V_212 ,
V_214 , V_63 ,
V_239 , V_110 ,
V_213 ) ;
F_167 ( V_56 ,
V_209 , V_210 ,
V_211 , V_212 ,
V_214 , V_63 ,
V_239 , V_110 ,
V_213 ) ;
}
static void F_170 ( enum V_55 V_56 , T_5 V_213 ,
enum V_131 V_132 ,
bool V_249 , enum V_109 V_110 )
{
bool V_250 = false ;
int V_251 = 0 ;
if ( V_110 == V_121 ||
V_110 == V_122 ) {
if ( V_249 ) {
switch ( V_213 ) {
case V_235 :
V_251 = 2 ;
break;
case V_236 :
V_251 = 1 ;
break;
case V_237 :
V_251 = 0 ;
break;
case V_238 :
V_251 = 3 ;
break;
}
} else {
switch ( V_213 ) {
case V_235 :
V_251 = 0 ;
break;
case V_236 :
V_251 = 1 ;
break;
case V_237 :
V_251 = 2 ;
break;
case V_238 :
V_251 = 3 ;
break;
}
}
if ( V_213 == V_236 || V_213 == V_238 )
V_250 = true ;
else
V_250 = false ;
}
F_8 ( F_73 ( V_56 ) , V_251 , 13 , 12 ) ;
if ( F_12 ( V_252 ) )
F_8 ( F_73 ( V_56 ) ,
V_250 ? 1 : 0 , 18 , 18 ) ;
if ( V_110 == V_112 ) {
bool V_253 = ( V_132 == V_134 ) &&
( V_213 == V_235 ||
V_213 == V_237 ) ;
F_8 ( F_73 ( V_56 ) , V_253 , 22 , 22 ) ;
}
}
static int F_171 ( enum V_109 V_110 )
{
switch ( V_110 ) {
case V_127 :
return 1 ;
case V_128 :
return 2 ;
case V_129 :
return 4 ;
case V_130 :
case V_112 :
return 8 ;
case V_115 :
case V_117 :
case V_116 :
case V_121 :
case V_122 :
case V_114 :
case V_113 :
case V_118 :
case V_126 :
return 16 ;
case V_120 :
return 24 ;
case V_119 :
case V_123 :
case V_124 :
case V_125 :
return 32 ;
default:
F_119 () ;
return 0 ;
}
}
static T_6 F_172 ( int V_254 , T_5 V_255 )
{
if ( V_254 == 1 )
return 1 ;
else if ( V_254 > 1 )
return 1 + ( V_254 - 1 ) * V_255 ;
else if ( V_254 < 0 )
return 1 - ( - V_254 + 1 ) * V_255 ;
else
F_119 () ;
return 0 ;
}
static void F_173 ( T_5 V_213 , bool V_256 ,
T_1 V_257 ,
T_1 V_98 , T_1 V_99 ,
enum V_109 V_110 , bool V_239 ,
unsigned int V_258 ,
unsigned * V_259 , unsigned * V_260 ,
T_6 * V_261 , T_6 * V_262 , int V_263 , int V_264 )
{
T_5 V_255 ;
switch ( V_110 ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
F_119 () ;
return;
case V_121 :
case V_122 :
V_255 = 4 ;
break;
default:
V_255 = F_171 ( V_110 ) / 8 ;
break;
}
F_10 ( L_14 , V_213 , V_257 ,
V_98 , V_99 ) ;
switch ( V_213 + V_256 * 4 ) {
case V_235 :
case V_237 :
if ( V_110 == V_121 ||
V_110 == V_122 )
V_98 = V_98 >> 1 ;
case V_236 :
case V_238 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = V_258 * V_257 * V_255 ;
else
* V_259 = 0 ;
* V_261 = F_172 ( 1 +
( V_264 * V_257 - V_263 * V_98 ) +
( V_239 ? V_257 : 0 ) , V_255 ) ;
* V_262 = F_172 ( V_263 , V_255 ) ;
break;
case V_235 + 4 :
case V_237 + 4 :
if ( V_110 == V_121 ||
V_110 == V_122 )
V_98 = V_98 >> 1 ;
case V_236 + 4 :
case V_238 + 4 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = V_258 * V_257 * V_255 ;
else
* V_259 = 0 ;
* V_261 = F_172 ( 1 -
( V_264 * V_257 + V_263 * V_98 ) -
( V_239 ? V_257 : 0 ) , V_255 ) ;
* V_262 = F_172 ( V_263 , V_255 ) ;
break;
default:
F_119 () ;
return;
}
}
static void F_174 ( T_5 V_213 , bool V_256 ,
T_1 V_257 ,
T_1 V_98 , T_1 V_99 ,
enum V_109 V_110 , bool V_239 ,
unsigned int V_258 ,
unsigned * V_259 , unsigned * V_260 ,
T_6 * V_261 , T_6 * V_262 , int V_263 , int V_264 )
{
T_5 V_255 ;
T_1 V_265 , V_266 ;
switch ( V_110 ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
F_119 () ;
return;
default:
V_255 = F_171 ( V_110 ) / 8 ;
break;
}
F_10 ( L_14 , V_213 , V_257 ,
V_98 , V_99 ) ;
if ( V_213 == V_235 || V_213 == V_237 ) {
V_265 = V_98 ;
V_266 = V_99 ;
} else {
V_265 = V_99 ;
V_266 = V_98 ;
}
switch ( V_213 + V_256 * 4 ) {
case V_235 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( 1 +
( V_264 * V_257 - V_265 * V_263 ) +
( V_239 ? V_257 : 0 ) , V_255 ) ;
if ( V_110 == V_121 ||
V_110 == V_122 )
* V_262 = F_172 ( V_263 , 2 * V_255 ) ;
else
* V_262 = F_172 ( V_263 , V_255 ) ;
break;
case V_236 :
* V_260 = V_257 * ( V_266 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( V_257 * ( V_266 * V_263 - 1 ) +
V_264 + ( V_239 ? 1 : 0 ) , V_255 ) ;
* V_262 = F_172 ( - V_263 * V_257 , V_255 ) ;
break;
case V_237 :
* V_260 = ( V_257 * ( V_266 - 1 ) + V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( - 1 -
( V_264 * V_257 - V_265 * V_263 ) -
( V_239 ? V_257 : 0 ) , V_255 ) ;
if ( V_110 == V_121 ||
V_110 == V_122 )
* V_262 = F_172 ( - V_263 , 2 * V_255 ) ;
else
* V_262 = F_172 ( - V_263 , V_255 ) ;
break;
case V_238 :
* V_260 = ( V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( - V_257 * ( V_266 * V_263 - 1 ) -
V_264 - ( V_239 ? 1 : 0 ) , V_255 ) ;
* V_262 = F_172 ( V_263 * V_257 , V_255 ) ;
break;
case V_235 + 4 :
* V_260 = ( V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( V_264 * V_257 * 2 - 1 +
( V_239 ? V_257 : 0 ) ,
V_255 ) ;
if ( V_110 == V_121 ||
V_110 == V_122 )
* V_262 = F_172 ( - V_263 , 2 * V_255 ) ;
else
* V_262 = F_172 ( - V_263 , V_255 ) ;
break;
case V_236 + 4 :
* V_260 = 0 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( - V_257 * ( V_266 * V_263 - 1 ) +
V_264 + ( V_239 ? 1 : 0 ) ,
V_255 ) ;
* V_262 = F_172 ( V_263 * V_257 , V_255 ) ;
break;
case V_237 + 4 :
* V_260 = V_257 * ( V_266 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( 1 - V_264 * V_257 * 2 -
( V_239 ? V_257 : 0 ) ,
V_255 ) ;
if ( V_110 == V_121 ||
V_110 == V_122 )
* V_262 = F_172 ( V_263 , 2 * V_255 ) ;
else
* V_262 = F_172 ( V_263 , V_255 ) ;
break;
case V_238 + 4 :
* V_260 = ( V_257 * ( V_266 - 1 ) + V_265 - 1 ) * V_255 ;
if ( V_258 )
* V_259 = * V_260 - V_258 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( V_257 * ( V_266 * V_263 - 1 ) -
V_264 - ( V_239 ? 1 : 0 ) ,
V_255 ) ;
* V_262 = F_172 ( - V_263 * V_257 , V_255 ) ;
break;
default:
F_119 () ;
return;
}
}
static void F_175 ( T_1 V_257 , T_1 V_98 ,
enum V_109 V_110 , bool V_239 ,
unsigned int V_258 , unsigned * V_259 , unsigned * V_260 ,
T_6 * V_261 , T_6 * V_262 , int V_263 , int V_264 )
{
T_5 V_255 ;
switch ( V_110 ) {
case V_127 :
case V_128 :
case V_129 :
case V_130 :
F_119 () ;
return;
default:
V_255 = F_171 ( V_110 ) / 8 ;
break;
}
F_10 ( L_15 , V_257 , V_98 ) ;
* V_260 = 0 ;
if ( V_258 )
* V_259 = * V_260 + V_258 * V_257 * V_255 ;
else
* V_259 = * V_260 ;
* V_261 = F_172 ( 1 + ( V_264 * V_257 - V_98 * V_263 ) +
( V_239 ? V_257 : 0 ) , V_255 ) ;
if ( V_110 == V_121 ||
V_110 == V_122 )
* V_262 = F_172 ( V_263 , 2 * V_255 ) ;
else
* V_262 = F_172 ( V_263 , V_255 ) ;
}
static int F_176 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_270 , T_1 V_271 ,
T_1 V_98 , T_1 V_99 , T_1 V_211 , T_1 V_212 ,
bool V_63 )
{
const int V_272 = F_177 ( V_99 , V_212 ) ;
unsigned long V_273 ;
static const T_5 V_274 [ 3 ] = { 8 , 10 , 20 } ;
T_8 V_2 , V_275 ;
int V_16 ;
V_273 = V_270 -> V_276 + V_270 -> V_277 + V_270 -> V_278 + V_270 -> V_279 - V_211 ;
V_16 = 0 ;
if ( V_212 < V_99 )
V_16 ++ ;
if ( V_211 < V_98 )
V_16 ++ ;
V_275 = F_178 ( ( T_8 ) ( V_270 -> V_279 + V_270 -> V_278 + V_270 -> V_277 ) * V_268 , V_267 ) ;
F_10 ( L_16 , V_275 , V_274 [ V_16 ] ) ;
if ( V_275 <= V_274 [ V_16 ] )
return - V_280 ;
if ( ! V_63 )
return 0 ;
V_2 = F_178 ( ( T_8 ) ( V_273 - V_271 ) * V_268 , V_267 ) ;
F_10 ( L_17 ,
V_2 , F_179 ( 0 , V_272 - 2 ) * V_98 ) ;
if ( V_2 < F_179 ( 0 , V_272 - 2 ) * V_98 )
return - V_280 ;
V_2 = F_178 ( ( T_8 ) V_273 * V_268 , V_267 ) ;
F_10 ( L_18 ,
V_2 , F_179 ( 0 , V_272 - 1 ) * V_98 ) ;
if ( V_2 < F_179 ( 0 , V_272 - 1 ) * V_98 )
return - V_280 ;
return 0 ;
}
static unsigned long F_180 ( unsigned long V_267 ,
const struct V_269 * V_281 , T_1 V_98 ,
T_1 V_99 , T_1 V_211 , T_1 V_212 ,
enum V_109 V_110 )
{
T_2 V_282 = 0 ;
T_8 V_283 ;
if ( V_99 <= V_212 && V_98 <= V_211 )
return ( unsigned long ) V_267 ;
if ( V_99 > V_212 ) {
unsigned int V_284 = V_281 -> V_276 ;
V_283 = V_267 * V_99 * V_211 ;
F_181 ( V_283 , 2 * V_212 * V_284 ) ;
V_282 = V_283 ;
if ( V_99 > 2 * V_212 ) {
if ( V_284 == V_211 )
return 0 ;
V_283 = V_267 * ( V_99 - 2 * V_212 ) * V_211 ;
F_181 ( V_283 , 2 * V_212 * ( V_284 - V_211 ) ) ;
V_282 = F_182 ( T_2 , V_282 , V_283 ) ;
}
}
if ( V_98 > V_211 ) {
V_283 = V_267 * V_98 ;
F_181 ( V_283 , V_211 ) ;
V_282 = F_182 ( T_2 , V_282 , V_283 ) ;
if ( V_110 == V_119 )
V_282 <<= 1 ;
}
return V_282 ;
}
static unsigned long F_183 ( unsigned long V_267 , T_1 V_98 ,
T_1 V_99 , T_1 V_211 , T_1 V_212 , bool V_285 )
{
if ( V_99 > V_212 && V_98 > V_211 )
return V_267 * 4 ;
else
return V_267 * 2 ;
}
static unsigned long F_184 ( unsigned long V_267 , T_1 V_98 ,
T_1 V_99 , T_1 V_211 , T_1 V_212 , bool V_285 )
{
unsigned int V_286 , V_287 ;
if ( V_98 > 3 * V_211 )
V_286 = 4 ;
else if ( V_98 > 2 * V_211 )
V_286 = 3 ;
else if ( V_98 > V_211 )
V_286 = 2 ;
else
V_286 = 1 ;
if ( V_99 > V_212 )
V_287 = 2 ;
else
V_287 = 1 ;
return V_267 * V_287 * V_286 ;
}
static unsigned long F_185 ( unsigned long V_267 , T_1 V_98 ,
T_1 V_99 , T_1 V_211 , T_1 V_212 , bool V_285 )
{
if ( V_285 )
return 1 ;
if ( V_98 > V_211 )
return F_177 ( V_267 , V_211 ) * V_98 ;
else
return V_267 ;
}
static int F_186 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_281 ,
T_1 V_98 , T_1 V_99 , T_1 V_211 , T_1 V_212 ,
enum V_109 V_110 , bool * V_63 ,
int * V_263 , int * V_264 , int * V_288 , int * V_289 ,
T_1 V_271 , unsigned long * V_282 , bool V_285 )
{
int error ;
T_1 V_290 , V_291 ;
int V_292 = F_150 ( * V_288 , * V_289 ) ;
const int V_293 =
F_187 ( V_294 ) ;
* V_63 = false ;
do {
V_291 = V_99 / * V_289 ;
V_290 = V_98 / * V_288 ;
* V_282 = V_3 . V_47 -> V_295 ( V_267 , V_290 ,
V_291 , V_211 , V_212 , V_285 ) ;
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
F_74 ( L_19 ) ;
return - V_280 ;
}
return 0 ;
}
static int F_190 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_281 ,
T_1 V_98 , T_1 V_99 , T_1 V_211 , T_1 V_212 ,
enum V_109 V_110 , bool * V_63 ,
int * V_263 , int * V_264 , int * V_288 , int * V_289 ,
T_1 V_271 , unsigned long * V_282 , bool V_285 )
{
int error ;
T_1 V_290 , V_291 ;
int V_292 = F_150 ( * V_288 , * V_289 ) ;
const int V_293 =
F_187 ( V_294 ) ;
do {
V_291 = V_99 / * V_289 ;
V_290 = V_98 / * V_288 ;
* V_63 = V_291 > V_212 ;
if ( V_290 > V_293 )
if ( V_291 > V_212 &&
V_291 < V_212 * 2 )
* V_63 = false ;
V_296:
if ( * V_63 )
* V_282 = F_180 ( V_267 , V_281 ,
V_290 , V_291 , V_211 ,
V_212 , V_110 ) ;
else
* V_282 = V_3 . V_47 -> V_295 ( V_267 , V_290 ,
V_291 , V_211 , V_212 ,
V_285 ) ;
error = F_176 ( V_267 , V_268 , V_281 ,
V_271 , V_290 , V_291 , V_211 ,
V_212 , * V_63 ) ;
if ( error && * V_63 ) {
* V_63 = false ;
goto V_296;
}
error = ( error || V_290 > V_293 * 2 ||
( V_290 > V_293 && * V_63 ) ||
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
if ( F_176 ( V_267 , V_268 , V_281 , V_271 , V_98 ,
V_99 , V_211 , V_212 , * V_63 ) ) {
F_74 ( L_20 ) ;
return - V_280 ;
}
if ( V_290 > ( V_293 * 2 ) ) {
F_74 ( L_21 ) ;
F_74 ( L_22 ) ;
return - V_280 ;
}
if ( V_290 > V_293 && * V_63 ) {
F_74 ( L_23 ) ;
return - V_280 ;
}
return 0 ;
}
static int F_191 ( unsigned long V_267 , unsigned long V_268 ,
const struct V_269 * V_281 ,
T_1 V_98 , T_1 V_99 , T_1 V_211 , T_1 V_212 ,
enum V_109 V_110 , bool * V_63 ,
int * V_263 , int * V_264 , int * V_288 , int * V_289 ,
T_1 V_271 , unsigned long * V_282 , bool V_285 )
{
T_1 V_290 , V_297 ;
int V_298 = * V_288 ;
T_1 V_291 = V_99 / * V_289 ;
const int V_293 =
F_187 ( V_294 ) ;
const int V_299 = F_187 ( V_300 ) ;
if ( V_285 ) {
V_297 = V_211 * V_299 ;
} else {
V_297 = F_188 () /
F_177 ( V_267 , V_211 ) ;
}
* V_288 = F_177 ( V_98 , V_297 ) ;
* V_288 = * V_288 > V_298 ? * V_288 : V_298 ;
if ( * V_288 > * V_263 )
return - V_280 ;
do {
V_290 = V_98 / * V_288 ;
} while ( * V_288 <= * V_263 &&
V_290 > V_293 && ++ * V_288 );
if ( V_290 > V_293 ) {
F_74 ( L_24 ) ;
return - V_280 ;
}
* V_282 = V_3 . V_47 -> V_295 ( V_267 , V_290 , V_291 ,
V_211 , V_212 , V_285 ) ;
return 0 ;
}
static int F_192 ( unsigned long V_267 , unsigned long V_268 ,
enum V_95 V_96 ,
const struct V_269 * V_281 ,
T_1 V_98 , T_1 V_99 , T_1 V_211 , T_1 V_212 ,
enum V_109 V_110 , bool * V_63 ,
int * V_263 , int * V_264 , T_1 V_271 ,
enum V_131 V_132 , bool V_285 )
{
const int V_299 = F_187 ( V_300 ) ;
const int V_301 = 16 ;
unsigned long V_282 = 0 ;
int V_288 , V_289 , V_302 ;
if ( V_98 == V_211 && V_99 == V_212 )
return 0 ;
if ( ( V_96 & V_303 ) == 0 )
return - V_280 ;
if ( V_285 ) {
* V_263 = * V_264 = 1 ;
} else {
* V_263 = V_301 ;
* V_264 = ( V_132 == V_134 &&
F_12 ( V_133 ) ) ?
2 : V_301 ;
}
if ( V_110 == V_127 ||
V_110 == V_128 ||
V_110 == V_129 ||
V_110 == V_130 ) {
* V_263 = 1 ;
* V_264 = 1 ;
* V_63 = false ;
return 0 ;
}
V_288 = F_177 ( F_177 ( V_98 , V_211 ) , V_299 ) ;
V_289 = F_177 ( F_177 ( V_99 , V_212 ) , V_299 ) ;
if ( V_288 > * V_263 || V_211 > V_98 * 8 )
return - V_280 ;
if ( V_289 > * V_264 || V_212 > V_99 * 8 )
return - V_280 ;
V_302 = V_3 . V_47 -> V_304 ( V_267 , V_268 , V_281 , V_98 , V_99 ,
V_211 , V_212 , V_110 , V_63 ,
V_263 , V_264 , & V_288 , & V_289 , V_271 , & V_282 ,
V_285 ) ;
if ( V_302 )
return V_302 ;
F_10 ( L_25 , V_282 ) ;
F_10 ( L_26 , F_188 () ) ;
if ( ! V_282 || V_282 > F_188 () ) {
F_74 ( L_27
L_28
L_26 ,
V_282 , F_188 () ) ;
return - V_280 ;
}
* V_263 = V_288 ;
* V_264 = V_289 ;
return 0 ;
}
int F_193 ( enum V_55 V_56 , enum V_5 V_6 ,
const struct V_305 * V_306 ,
const struct V_269 * V_307 ,
int * V_263 , int * V_264 )
{
enum V_95 V_96 = F_194 ( V_56 ) ;
bool V_63 = true ;
bool V_239 = false ;
T_1 V_291 = V_306 -> V_99 ;
T_1 V_290 = V_306 -> V_98 ;
bool V_214 = V_307 -> V_308 ;
T_1 V_211 , V_212 ;
int V_271 = V_306 -> V_271 ;
unsigned long V_267 = F_195 ( V_6 ) ;
unsigned long V_268 = F_196 ( V_6 ) ;
V_211 = V_306 -> V_211 == 0 ? V_306 -> V_98 : V_306 -> V_211 ;
V_212 = V_306 -> V_212 == 0 ? V_306 -> V_99 : V_306 -> V_212 ;
if ( V_214 && V_306 -> V_99 == V_212 )
V_239 = true ;
if ( V_214 ) {
if ( V_239 )
V_291 /= 2 ;
V_212 /= 2 ;
F_10 ( L_29 ,
V_291 , V_212 ) ;
}
if ( ! F_197 ( V_56 , V_306 -> V_110 ) )
return - V_280 ;
return F_192 ( V_267 , V_268 , V_96 , V_307 , V_290 ,
V_291 , V_211 , V_212 , V_306 -> V_110 ,
& V_63 , V_263 , V_264 , V_271 ,
V_306 -> V_132 , false ) ;
}
static int F_198 ( enum V_55 V_56 ,
enum V_95 V_96 , T_2 V_94 , T_2 V_309 ,
T_1 V_257 , int V_271 , int V_310 , T_1 V_98 , T_1 V_99 ,
T_1 V_211 , T_1 V_212 , enum V_109 V_110 ,
T_5 V_213 , bool V_256 , T_5 V_100 , T_5 V_311 ,
T_5 V_103 , enum V_131 V_132 ,
bool V_312 , const struct V_269 * V_281 ,
bool V_285 )
{
bool V_63 = true ;
bool V_239 = false ;
int V_42 , V_313 = 0 ;
unsigned V_259 , V_260 ;
T_6 V_261 ;
T_6 V_262 ;
T_1 V_314 , V_315 ;
unsigned int V_258 = 0 ;
T_1 V_291 = V_99 ;
T_1 V_290 = V_98 ;
int V_263 = 1 , V_264 = 1 ;
bool V_214 = V_281 -> V_308 ;
unsigned long V_267 = F_199 ( V_56 ) ;
unsigned long V_268 = F_200 ( V_56 ) ;
if ( V_94 == 0 )
return - V_280 ;
V_211 = V_211 == 0 ? V_98 : V_211 ;
V_212 = V_212 == 0 ? V_99 : V_212 ;
if ( V_214 && V_99 == V_212 )
V_239 = true ;
if ( V_214 ) {
if ( V_239 )
V_291 /= 2 ;
V_310 /= 2 ;
V_212 /= 2 ;
F_10 ( L_30
L_31 , V_291 , V_310 ,
V_212 ) ;
}
if ( ! F_197 ( V_56 , V_110 ) )
return - V_280 ;
V_42 = F_192 ( V_267 , V_268 , V_96 , V_281 , V_290 ,
V_291 , V_211 , V_212 , V_110 ,
& V_63 , & V_263 , & V_264 , V_271 ,
V_132 , V_285 ) ;
if ( V_42 )
return V_42 ;
V_290 = V_290 / V_263 ;
V_291 = V_291 / V_264 ;
if ( V_110 == V_121 ||
V_110 == V_122 ||
V_110 == V_112 )
V_313 = 1 ;
if ( V_214 && ! V_239 ) {
if ( ! V_291 || V_291 == V_212 )
V_258 = 0 ;
else
V_258 = V_291 / V_212 / 2 ;
}
if ( V_239 )
V_258 = 1 ;
V_259 = 0 ;
V_260 = 0 ;
V_261 = 0 ;
V_262 = 0 ;
if ( V_56 == V_57 ) {
V_314 = V_211 ;
V_315 = V_212 ;
} else {
V_314 = V_290 ;
V_315 = V_99 ;
}
if ( V_132 == V_134 )
F_175 ( V_257 , V_314 ,
V_110 , V_239 , V_258 ,
& V_259 , & V_260 , & V_261 , & V_262 ,
V_263 , V_264 ) ;
else if ( V_132 == V_316 )
F_174 ( V_213 , V_256 , V_257 ,
V_314 , V_315 ,
V_110 , V_239 , V_258 ,
& V_259 , & V_260 , & V_261 , & V_262 ,
V_263 , V_264 ) ;
else
F_173 ( V_213 , V_256 ,
V_257 , V_314 , V_315 ,
V_110 , V_239 , V_258 ,
& V_259 , & V_260 , & V_261 , & V_262 ,
V_263 , V_264 ) ;
F_10 ( L_32 ,
V_259 , V_260 , V_261 , V_262 ) ;
F_118 ( V_56 , V_110 ) ;
F_120 ( V_56 , V_132 ) ;
F_96 ( V_56 , V_94 + V_259 ) ;
F_98 ( V_56 , V_94 + V_260 ) ;
if ( V_112 == V_110 ) {
F_100 ( V_56 , V_309 + V_259 ) ;
F_102 ( V_56 , V_309 + V_260 ) ;
}
F_116 ( V_56 , V_261 ) ;
F_114 ( V_56 , V_262 ) ;
F_10 ( L_33 , V_271 , V_310 , V_290 ,
V_291 , V_211 , V_212 ) ;
F_104 ( V_56 , V_96 , V_271 , V_310 ) ;
F_106 ( V_56 , V_290 , V_291 ) ;
if ( V_96 & V_303 ) {
F_169 ( V_56 , V_290 , V_291 , V_211 ,
V_212 , V_214 , V_63 , V_239 ,
V_110 , V_213 ) ;
F_109 ( V_56 , V_211 , V_212 ) ;
F_138 ( V_56 , V_313 ) ;
}
F_170 ( V_56 , V_213 , V_132 , V_256 ,
V_110 ) ;
F_110 ( V_56 , V_96 , V_100 ) ;
F_112 ( V_56 , V_96 , V_311 ) ;
F_113 ( V_56 , V_96 , V_103 ) ;
F_139 ( V_56 , V_96 , V_312 ) ;
return 0 ;
}
int F_201 ( enum V_55 V_56 , const struct V_305 * V_306 ,
bool V_312 , const struct V_269 * V_281 ,
bool V_285 )
{
int V_42 ;
enum V_95 V_96 = F_194 ( V_56 ) ;
enum V_5 V_6 ;
V_6 = F_123 ( V_56 ) ;
F_10 ( L_34
L_35 ,
V_56 , & V_306 -> V_94 , & V_306 -> V_309 , V_306 -> V_257 , V_306 -> V_271 ,
V_306 -> V_310 , V_306 -> V_98 , V_306 -> V_99 , V_306 -> V_211 , V_306 -> V_212 ,
V_306 -> V_110 , V_306 -> V_213 , V_306 -> V_256 , V_6 , V_312 ) ;
V_42 = F_198 ( V_56 , V_96 , V_306 -> V_94 , V_306 -> V_309 ,
V_306 -> V_257 , V_306 -> V_271 , V_306 -> V_310 , V_306 -> V_98 , V_306 -> V_99 ,
V_306 -> V_211 , V_306 -> V_212 , V_306 -> V_110 , V_306 -> V_213 ,
V_306 -> V_256 , V_306 -> V_100 , V_306 -> V_311 , V_306 -> V_103 ,
V_306 -> V_132 , V_312 , V_281 , V_285 ) ;
return V_42 ;
}
int F_202 ( const struct V_317 * V_318 ,
bool V_285 , const struct V_269 * V_281 )
{
int V_42 ;
T_2 V_242 ;
enum V_55 V_56 = V_57 ;
const int V_271 = 0 , V_310 = 0 ;
const T_5 V_100 = 0 , V_103 = 0 ;
const bool V_312 = false ;
bool V_319 ;
int V_290 = V_281 -> V_276 ;
int V_291 = V_281 -> V_320 ;
enum V_95 V_96 =
V_303 | V_102 ;
F_10 ( L_36
L_37 , V_318 -> V_94 , V_318 -> V_309 , V_290 ,
V_291 , V_318 -> V_98 , V_318 -> V_99 , V_318 -> V_110 , V_318 -> V_213 ,
V_318 -> V_256 ) ;
V_42 = F_198 ( V_56 , V_96 , V_318 -> V_94 , V_318 -> V_309 ,
V_318 -> V_321 , V_271 , V_310 , V_290 , V_291 , V_318 -> V_98 ,
V_318 -> V_99 , V_318 -> V_110 , V_318 -> V_213 , V_318 -> V_256 , V_100 ,
V_318 -> V_311 , V_103 , V_318 -> V_132 ,
V_312 , V_281 , V_285 ) ;
switch ( V_318 -> V_110 ) {
case V_117 :
case V_120 :
case V_116 :
case V_114 :
case V_115 :
case V_118 :
case V_126 :
case V_113 :
V_319 = true ;
break;
default:
V_319 = false ;
break;
}
V_242 = F_3 ( F_73 ( V_56 ) ) ;
V_242 = F_122 ( V_242 , V_319 , 10 , 10 ) ;
V_242 = F_122 ( V_242 , V_285 , 19 , 19 ) ;
F_1 ( F_73 ( V_56 ) , V_242 ) ;
return V_42 ;
}
int F_203 ( enum V_55 V_56 , bool V_58 )
{
F_10 ( L_38 , V_56 , V_58 ) ;
F_8 ( F_73 ( V_56 ) , V_58 ? 1 : 0 , 0 , 0 ) ;
return 0 ;
}
bool F_204 ( enum V_55 V_56 )
{
return F_6 ( F_73 ( V_56 ) , 0 , 0 ) ;
}
void F_205 ( enum V_5 V_6 , bool V_58 )
{
F_7 ( V_6 , V_322 , V_58 ) ;
F_5 ( V_6 , V_322 ) ;
}
bool F_70 ( enum V_5 V_6 )
{
return ! ! F_5 ( V_6 , V_322 ) ;
}
void F_206 ( bool V_58 )
{
F_203 ( V_57 , V_58 ) ;
}
bool F_207 ( void )
{
return F_204 ( V_57 ) ;
}
static void F_208 ( bool V_323 )
{
if ( ! F_12 ( V_324 ) )
return;
F_8 ( V_325 , V_323 ? 1 : 0 , 29 , 29 ) ;
}
void F_209 ( bool V_58 )
{
if ( ! F_12 ( V_326 ) )
return;
F_8 ( V_325 , V_58 ? 1 : 0 , 28 , 28 ) ;
}
void F_210 ( bool V_58 )
{
if ( ! F_12 ( V_327 ) )
return;
F_8 ( V_325 , V_58 ? 1 : 0 , 27 , 27 ) ;
}
static void F_211 ( enum V_5 V_6 , bool V_58 )
{
F_7 ( V_6 , V_328 , V_58 ) ;
}
static void F_212 ( enum V_5 V_6 )
{
F_7 ( V_6 , V_329 , 1 ) ;
}
void F_213 ( enum V_330 V_331 )
{
F_8 ( V_148 , V_331 , 2 , 1 ) ;
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
static void F_218 ( enum V_5 V_333 , bool V_58 )
{
F_7 ( V_333 , V_337 , V_58 ) ;
}
static void F_219 ( enum V_5 V_333 ,
bool V_58 )
{
if ( ! F_12 ( V_22 ) )
return;
if ( V_333 == V_140 )
F_8 ( V_148 , V_58 , 18 , 18 ) ;
else if ( V_333 == V_31 )
F_8 ( V_148 , V_58 , 19 , 19 ) ;
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
F_132 ( V_6 , V_339 -> V_344 ) ;
F_133 ( V_6 , & V_339 -> V_345 ) ;
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
F_119 () ;
return;
}
F_7 ( V_6 , V_348 , V_347 ) ;
}
static void F_222 ( enum V_349 V_331 )
{
T_2 V_242 ;
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
F_119 () ;
return;
}
V_242 = F_3 ( V_325 ) ;
V_242 = F_122 ( V_242 , V_350 , 15 , 15 ) ;
V_242 = F_122 ( V_242 , V_351 , 16 , 16 ) ;
F_1 ( V_325 , V_242 ) ;
}
static void F_223 ( enum V_5 V_6 , bool V_58 )
{
F_7 ( V_6 , V_355 , V_58 ) ;
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
static bool F_226 ( T_1 V_98 , T_1 V_99 )
{
return V_98 <= V_3 . V_47 -> V_364 &&
V_99 <= V_3 . V_47 -> V_365 ;
}
static bool F_227 ( int V_278 , int V_277 , int V_279 ,
int V_366 , int V_367 , int V_368 )
{
if ( V_278 < 1 || V_278 > V_3 . V_47 -> V_369 ||
V_277 < 1 || V_277 > V_3 . V_47 -> V_370 ||
V_279 < 1 || V_279 > V_3 . V_47 -> V_370 ||
V_366 < 1 || V_366 > V_3 . V_47 -> V_369 ||
V_367 < 0 || V_367 > V_3 . V_47 -> V_371 ||
V_368 < 0 || V_368 > V_3 . V_47 -> V_371 )
return false ;
return true ;
}
static bool F_228 ( enum V_5 V_6 ,
unsigned long V_267 )
{
if ( F_134 ( V_6 ) )
return V_267 <= V_3 . V_47 -> V_372 ? true : false ;
else
return V_267 <= V_3 . V_47 -> V_373 ? true : false ;
}
bool F_229 ( enum V_5 V_6 ,
const struct V_269 * V_307 )
{
bool V_374 ;
V_374 = F_226 ( V_307 -> V_276 , V_307 -> V_320 ) ;
V_374 &= F_228 ( V_6 , V_307 -> V_375 ) ;
if ( F_134 ( V_6 ) ) {
V_374 &= F_227 ( V_307 -> V_278 , V_307 -> V_277 ,
V_307 -> V_279 , V_307 -> V_366 , V_307 -> V_367 ,
V_307 -> V_368 ) ;
}
return V_374 ;
}
static void F_230 ( enum V_5 V_6 , int V_278 ,
int V_277 , int V_279 , int V_366 , int V_367 , int V_368 ,
enum V_376 V_377 ,
enum V_376 V_378 ,
enum V_379 V_380 ,
enum V_376 V_381 ,
enum V_379 V_382 )
{
T_2 V_383 , V_384 , V_242 ;
bool V_385 , V_386 , V_387 ;
V_383 = F_90 ( V_278 - 1 , V_3 . V_47 -> V_388 , 0 ) |
F_90 ( V_277 - 1 , V_3 . V_47 -> V_389 , 8 ) |
F_90 ( V_279 - 1 , V_3 . V_47 -> V_390 , 20 ) ;
V_384 = F_90 ( V_366 - 1 , V_3 . V_47 -> V_388 , 0 ) |
F_90 ( V_367 , V_3 . V_47 -> V_389 , 8 ) |
F_90 ( V_368 , V_3 . V_47 -> V_390 , 20 ) ;
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
F_119 () ;
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
F_119 () ;
}
V_242 = F_90 ( V_385 , 17 , 17 ) |
F_90 ( V_386 , 16 , 16 ) |
F_90 ( V_381 , 15 , 15 ) |
F_90 ( V_387 , 14 , 14 ) |
F_90 ( V_378 , 13 , 13 ) |
F_90 ( V_377 , 12 , 12 ) ;
F_1 ( F_233 ( V_6 ) , V_242 ) ;
}
void F_234 ( enum V_5 V_6 ,
const struct V_269 * V_307 )
{
unsigned V_394 , V_395 ;
unsigned long V_396 , V_397 ;
struct V_269 V_270 = * V_307 ;
F_10 ( L_39 , V_6 , V_270 . V_276 , V_270 . V_320 ) ;
if ( ! F_229 ( V_6 , & V_270 ) ) {
F_119 () ;
return;
}
if ( F_134 ( V_6 ) ) {
F_230 ( V_6 , V_270 . V_278 , V_270 . V_277 , V_270 . V_279 , V_270 . V_366 ,
V_270 . V_367 , V_270 . V_368 , V_270 . V_377 , V_270 . V_378 ,
V_270 . V_380 , V_270 . V_381 , V_270 . V_382 ) ;
V_394 = V_270 . V_276 + V_270 . V_277 + V_270 . V_278 + V_270 . V_279 ;
V_395 = V_270 . V_320 + V_270 . V_367 + V_270 . V_366 + V_270 . V_368 ;
V_396 = V_307 -> V_375 / V_394 ;
V_397 = V_307 -> V_375 / V_394 / V_395 ;
F_10 ( L_40 , V_307 -> V_375 ) ;
F_10 ( L_41 ,
V_270 . V_278 , V_270 . V_277 , V_270 . V_279 , V_270 . V_366 , V_270 . V_367 , V_270 . V_368 ) ;
F_10 ( L_42 ,
V_270 . V_377 , V_270 . V_378 , V_270 . V_380 ,
V_270 . V_381 , V_270 . V_382 ) ;
F_10 ( L_43 , V_396 , V_397 ) ;
} else {
if ( V_270 . V_308 == true )
V_270 . V_320 /= 2 ;
}
F_140 ( V_6 , V_270 . V_276 , V_270 . V_320 ) ;
}
static void F_235 ( enum V_5 V_6 , T_1 V_398 ,
T_1 V_399 )
{
F_82 ( V_398 < 1 ) ;
F_82 ( V_399 < 1 ) ;
F_1 ( F_236 ( V_6 ) ,
F_90 ( V_398 , 23 , 16 ) | F_90 ( V_399 , 7 , 0 ) ) ;
if ( F_12 ( V_38 ) == false &&
V_6 == V_140 )
V_3 . V_400 = F_237 () / V_398 ;
}
static void F_238 ( enum V_5 V_6 , int * V_398 ,
int * V_399 )
{
T_2 V_242 ;
V_242 = F_3 ( F_236 ( V_6 ) ) ;
* V_398 = F_124 ( V_242 , 23 , 16 ) ;
* V_399 = F_124 ( V_242 , 7 , 0 ) ;
}
unsigned long F_237 ( void )
{
struct V_401 * V_402 ;
unsigned long V_42 = 0 ;
switch ( F_239 () ) {
case V_403 :
V_42 = F_240 () ;
break;
case V_404 :
V_402 = F_241 ( 0 ) ;
V_42 = F_242 ( V_402 ) ;
break;
case V_405 :
V_402 = F_241 ( 1 ) ;
V_42 = F_242 ( V_402 ) ;
break;
default:
F_119 () ;
return 0 ;
}
return V_42 ;
}
unsigned long F_196 ( enum V_5 V_6 )
{
struct V_401 * V_402 ;
int V_406 ;
unsigned long V_42 ;
T_2 V_242 ;
if ( F_134 ( V_6 ) ) {
V_242 = F_3 ( F_236 ( V_6 ) ) ;
V_406 = F_124 ( V_242 , 23 , 16 ) ;
switch ( F_243 ( V_6 ) ) {
case V_403 :
V_42 = F_240 () ;
break;
case V_404 :
V_402 = F_241 ( 0 ) ;
V_42 = F_242 ( V_402 ) ;
break;
case V_405 :
V_402 = F_241 ( 1 ) ;
V_42 = F_242 ( V_402 ) ;
break;
default:
F_119 () ;
return 0 ;
}
return V_42 / V_406 ;
} else {
return F_237 () ;
}
}
unsigned long F_195 ( enum V_5 V_6 )
{
unsigned long V_42 ;
if ( F_134 ( V_6 ) ) {
int V_407 ;
T_2 V_242 ;
V_242 = F_3 ( F_236 ( V_6 ) ) ;
V_407 = F_124 ( V_242 , 7 , 0 ) ;
V_42 = F_196 ( V_6 ) ;
return V_42 / V_407 ;
} else {
return V_3 . V_408 ;
}
}
void F_244 ( unsigned long V_267 )
{
V_3 . V_408 = V_267 ;
}
unsigned long F_188 ( void )
{
return V_3 . V_400 ;
}
static unsigned long F_199 ( enum V_55 V_56 )
{
enum V_5 V_6 ;
if ( V_56 == V_57 )
return 0 ;
V_6 = F_123 ( V_56 ) ;
return F_195 ( V_6 ) ;
}
static unsigned long F_200 ( enum V_55 V_56 )
{
enum V_5 V_6 ;
if ( V_56 == V_57 )
return 0 ;
V_6 = F_123 ( V_56 ) ;
return F_196 ( V_6 ) ;
}
static void F_245 ( struct V_409 * V_410 , enum V_5 V_6 )
{
int V_406 , V_407 ;
enum V_411 V_412 ;
F_246 ( V_410 , L_44 , V_11 [ V_6 ] . V_53 ) ;
V_412 = F_243 ( V_6 ) ;
F_246 ( V_410 , L_45 , V_11 [ V_6 ] . V_53 ,
F_247 ( V_412 ) ,
F_248 ( V_412 ) ) ;
F_238 ( V_6 , & V_406 , & V_407 ) ;
F_246 ( V_410 , L_46 ,
F_196 ( V_6 ) , V_406 ) ;
F_246 ( V_410 , L_47 ,
F_195 ( V_6 ) , V_407 ) ;
}
void F_249 ( struct V_409 * V_410 )
{
int V_406 ;
T_2 V_242 ;
enum V_411 V_413 = F_239 () ;
if ( F_59 () )
return;
F_246 ( V_410 , L_48 ) ;
F_246 ( V_410 , L_49 ,
F_247 ( V_413 ) ,
F_248 ( V_413 ) ) ;
F_246 ( V_410 , L_50 , F_237 () ) ;
if ( F_12 ( V_38 ) ) {
F_246 ( V_410 , L_51 ) ;
V_242 = F_3 ( V_414 ) ;
V_406 = F_124 ( V_242 , 23 , 16 ) ;
F_246 ( V_410 , L_46 ,
( F_237 () / V_406 ) , V_406 ) ;
}
F_245 ( V_410 , V_140 ) ;
if ( F_12 ( V_25 ) )
F_245 ( V_410 , V_141 ) ;
if ( F_12 ( V_28 ) )
F_245 ( V_410 , V_142 ) ;
F_62 () ;
}
static void F_250 ( struct V_409 * V_410 )
{
int V_16 , V_17 ;
const char * V_415 [] = {
[ V_140 ] = L_52 ,
[ V_31 ] = L_53 ,
[ V_141 ] = L_54 ,
[ V_142 ] = L_55 ,
} ;
const char * V_416 [] = {
[ V_34 ] = L_56 ,
[ V_137 ] = L_57 ,
[ V_138 ] = L_58 ,
[ V_139 ] = L_59 ,
} ;
const char * * V_417 ;
#define F_251 ( V_42 ) seq_printf(s, "%-50s %08x\n", #r, dispc_read_reg(r))
if ( F_59 () )
return;
F_251 ( V_418 ) ;
F_251 ( V_419 ) ;
F_251 ( V_420 ) ;
F_251 ( V_421 ) ;
F_251 ( V_422 ) ;
F_251 ( V_325 ) ;
F_251 ( V_148 ) ;
F_251 ( V_423 ) ;
F_251 ( V_424 ) ;
F_251 ( V_425 ) ;
if ( F_12 ( V_22 ) ||
F_12 ( V_23 ) )
F_251 ( V_107 ) ;
if ( F_12 ( V_25 ) ) {
F_251 ( V_54 ) ;
F_251 ( V_426 ) ;
}
if ( F_12 ( V_28 ) ) {
F_251 ( V_427 ) ;
F_251 ( V_428 ) ;
}
if ( F_12 ( V_429 ) )
F_251 ( V_430 ) ;
#undef F_251
#define F_252 ( V_16 , V_53 ) name(i)
#define F_251 ( V_16 , V_42 ) seq_printf(s, "%s(%s)%*s %08x\n", #r, p_names[i], \
(int)(48 - strlen(#r) - strlen(p_names[i])), " ", \
dispc_read_reg(DISPC_REG(i, r)))
V_417 = V_415 ;
for ( V_16 = 0 ; V_16 < F_13 () ; V_16 ++ ) {
F_251 ( V_16 , F_215 ) ;
F_251 ( V_16 , F_217 ) ;
F_251 ( V_16 , F_141 ) ;
if ( V_16 == V_31 )
continue;
F_251 ( V_16 , F_215 ) ;
F_251 ( V_16 , F_217 ) ;
F_251 ( V_16 , F_231 ) ;
F_251 ( V_16 , F_232 ) ;
F_251 ( V_16 , F_233 ) ;
F_251 ( V_16 , F_236 ) ;
F_251 ( V_16 , F_141 ) ;
F_251 ( V_16 , V_431 ) ;
F_251 ( V_16 , V_432 ) ;
F_251 ( V_16 , V_433 ) ;
if ( F_12 ( V_32 ) ) {
F_251 ( V_16 , F_135 ) ;
F_251 ( V_16 , F_136 ) ;
F_251 ( V_16 , F_137 ) ;
}
}
V_417 = V_416 ;
for ( V_16 = 0 ; V_16 < F_27 () ; V_16 ++ ) {
F_251 ( V_16 , F_97 ) ;
F_251 ( V_16 , F_99 ) ;
F_251 ( V_16 , F_105 ) ;
F_251 ( V_16 , F_107 ) ;
F_251 ( V_16 , F_73 ) ;
F_251 ( V_16 , F_148 ) ;
F_251 ( V_16 , F_145 ) ;
F_251 ( V_16 , F_117 ) ;
F_251 ( V_16 , F_115 ) ;
if ( F_12 ( V_33 ) )
F_251 ( V_16 , F_149 ) ;
if ( V_16 == V_34 ) {
F_251 ( V_16 , V_434 ) ;
F_251 ( V_16 , V_435 ) ;
continue;
}
F_251 ( V_16 , F_154 ) ;
F_251 ( V_16 , F_108 ) ;
F_251 ( V_16 , F_157 ) ;
F_251 ( V_16 , F_159 ) ;
if ( F_12 ( V_36 ) ) {
F_251 ( V_16 , F_101 ) ;
F_251 ( V_16 , F_103 ) ;
F_251 ( V_16 , F_155 ) ;
F_251 ( V_16 , F_161 ) ;
F_251 ( V_16 , F_163 ) ;
}
if ( F_12 ( V_37 ) )
F_251 ( V_16 , F_168 ) ;
if ( F_12 ( V_33 ) )
F_251 ( V_16 , F_149 ) ;
if ( F_12 ( V_429 ) )
F_251 ( V_16 , V_436 ) ;
}
#undef F_252
#undef F_251
#define F_252 ( V_56 , V_53 , V_16 ) name(plane, i)
#define F_251 ( V_56 , V_53 , V_16 ) \
seq_printf(s, "%s_%d(%s)%*s %08x\n", #name, i, p_names[plane], \
(int)(46 - strlen(#name) - strlen(p_names[plane])), " ", \
dispc_read_reg(DISPC_REG(plane, name, i)))
for ( V_16 = 1 ; V_16 < F_27 () ; V_16 ++ ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_76 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_78 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 5 ; V_17 ++ )
F_251 ( V_16 , F_93 , V_17 ) ;
if ( F_12 ( V_35 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_80 , V_17 ) ;
}
if ( F_12 ( V_36 ) ) {
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_83 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_85 , V_17 ) ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
F_251 ( V_16 , F_87 , V_17 ) ;
}
}
F_62 () ;
#undef F_252
#undef F_251
}
int F_253 ( unsigned long F_237 ,
struct V_437 * V_438 )
{
if ( V_438 -> V_398 > 255 || V_438 -> V_398 == 0 )
return - V_280 ;
if ( V_438 -> V_399 < 1 || V_438 -> V_399 > 255 )
return - V_280 ;
V_438 -> V_439 = F_237 / V_438 -> V_398 ;
V_438 -> V_440 = V_438 -> V_439 / V_438 -> V_399 ;
return 0 ;
}
bool F_254 ( unsigned long V_3 ,
unsigned long V_441 , unsigned long V_442 ,
T_9 V_443 , void * V_444 )
{
int V_445 , V_446 , V_447 ;
int V_448 , V_449 , V_450 ;
unsigned long V_440 , V_439 ;
unsigned long V_451 ;
unsigned long V_452 , V_453 ;
unsigned V_454 ;
unsigned long V_455 ;
#ifdef F_255
V_454 = F_255 ;
#else
V_454 = 0 ;
#endif
V_452 = F_256 ( V_456 ) ;
V_453 = F_187 ( V_456 ) ;
V_451 = F_187 ( V_457 ) ;
V_441 = V_441 ? V_441 : 1 ;
V_442 = V_442 ? V_442 : V_458 ;
V_446 = F_179 ( F_177 ( V_3 , V_451 ) , 1ul ) ;
V_447 = F_150 ( V_3 / V_441 , 255ul ) ;
for ( V_445 = V_446 ; V_445 <= V_447 ; ++ V_445 ) {
V_439 = V_3 / V_445 ;
V_449 = F_179 ( F_177 ( V_439 , V_442 ) , V_452 ) ;
V_450 = F_150 ( V_439 / V_441 , V_453 ) ;
for ( V_448 = V_449 ; V_448 <= V_450 ; ++ V_448 ) {
V_440 = V_439 / V_448 ;
if ( F_12 ( V_38 ) )
V_455 = F_188 () ;
else
V_455 = V_439 ;
if ( V_455 < V_440 * V_454 )
continue;
if ( V_443 ( V_445 , V_448 , V_439 , V_440 , V_444 ) )
return true ;
}
}
return false ;
}
void F_225 ( enum V_5 V_6 ,
const struct V_437 * V_438 )
{
F_10 ( L_60 , V_438 -> V_439 , V_438 -> V_398 ) ;
F_10 ( L_61 , V_438 -> V_440 , V_438 -> V_399 ) ;
F_235 ( V_6 , V_438 -> V_398 , V_438 -> V_399 ) ;
}
int F_257 ( enum V_5 V_6 ,
struct V_437 * V_438 )
{
unsigned long V_455 ;
V_455 = F_237 () ;
V_438 -> V_398 = F_6 ( F_236 ( V_6 ) , 23 , 16 ) ;
V_438 -> V_399 = F_6 ( F_236 ( V_6 ) , 7 , 0 ) ;
V_438 -> V_439 = V_455 / V_438 -> V_398 ;
V_438 -> V_440 = V_438 -> V_439 / V_438 -> V_399 ;
return 0 ;
}
T_2 F_258 ( void )
{
return F_3 ( V_421 ) ;
}
void F_58 ( T_2 V_459 )
{
F_1 ( V_421 , V_459 ) ;
}
T_2 F_259 ( void )
{
return F_3 ( V_422 ) ;
}
void F_260 ( T_2 V_459 )
{
T_2 V_460 = F_3 ( V_422 ) ;
F_58 ( ( V_459 ^ V_460 ) & V_459 ) ;
F_1 ( V_422 , V_459 ) ;
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
T_2 V_242 ;
if ( F_12 ( V_38 ) ) {
V_242 = F_3 ( V_414 ) ;
V_242 = F_122 ( V_242 , 1 , 0 , 0 ) ;
V_242 = F_122 ( V_242 , 1 , 23 , 16 ) ;
F_1 ( V_414 , V_242 ) ;
V_3 . V_400 = F_237 () ;
}
if ( F_12 ( V_461 ) )
F_8 ( V_148 , 1 , 9 , 9 ) ;
F_94 () ;
F_213 ( V_462 ) ;
F_142 () ;
F_127 () ;
F_111 () ;
if ( V_3 . V_47 -> V_463 )
F_8 ( V_464 , 1 , 0 , 0 ) ;
}
static int T_10 F_264 ( struct V_401 * V_43 )
{
const struct V_465 * V_466 ;
struct V_465 * V_467 ;
V_467 = F_265 ( & V_43 -> V_44 , sizeof( * V_467 ) , V_468 ) ;
if ( ! V_467 ) {
F_266 ( & V_43 -> V_44 , L_62 ) ;
return - V_469 ;
}
switch ( F_267 () ) {
case V_470 :
V_466 = & V_471 ;
break;
case V_472 :
V_466 = & V_473 ;
break;
case V_474 :
case V_475 :
case V_476 :
case V_477 :
V_466 = & V_478 ;
break;
case V_479 :
case V_480 :
case V_481 :
V_466 = & V_482 ;
break;
case V_483 :
V_466 = & V_484 ;
break;
default:
return - V_485 ;
}
memcpy ( V_467 , V_466 , sizeof( * V_467 ) ) ;
V_3 . V_47 = V_467 ;
return 0 ;
}
static T_11 F_268 ( int V_486 , void * V_487 )
{
if ( ! V_3 . V_488 )
return V_489 ;
return V_3 . V_490 ( V_486 , V_3 . V_491 ) ;
}
int F_269 ( T_12 V_492 , void * V_493 )
{
int V_42 ;
if ( V_3 . V_490 != NULL )
return - V_494 ;
V_3 . V_490 = V_492 ;
V_3 . V_491 = V_493 ;
F_270 () ;
V_42 = F_271 ( & V_3 . V_43 -> V_44 , V_3 . V_486 , F_268 ,
V_495 , L_63 , & V_3 ) ;
if ( V_42 ) {
V_3 . V_490 = NULL ;
V_3 . V_491 = NULL ;
}
return V_42 ;
}
void F_272 ( void * V_493 )
{
F_273 ( & V_3 . V_43 -> V_44 , V_3 . V_486 , & V_3 ) ;
V_3 . V_490 = NULL ;
V_3 . V_491 = NULL ;
}
static int T_10 F_274 ( struct V_401 * V_43 )
{
T_2 V_496 ;
int V_42 = 0 ;
struct V_497 * V_498 ;
V_3 . V_43 = V_43 ;
V_42 = F_264 ( V_3 . V_43 ) ;
if ( V_42 )
return V_42 ;
V_498 = F_275 ( V_3 . V_43 , V_499 , 0 ) ;
if ( ! V_498 ) {
F_74 ( L_64 ) ;
return - V_280 ;
}
V_3 . V_4 = F_276 ( & V_43 -> V_44 , V_498 -> V_169 ,
F_277 ( V_498 ) ) ;
if ( ! V_3 . V_4 ) {
F_74 ( L_65 ) ;
return - V_469 ;
}
V_3 . V_486 = F_278 ( V_3 . V_43 , 0 ) ;
if ( V_3 . V_486 < 0 ) {
F_74 ( L_66 ) ;
return - V_485 ;
}
F_279 ( & V_43 -> V_44 ) ;
V_42 = F_59 () ;
if ( V_42 )
goto V_500;
F_263 () ;
V_496 = F_3 ( V_418 ) ;
F_280 ( & V_43 -> V_44 , L_67 ,
F_124 ( V_496 , 7 , 4 ) , F_124 ( V_496 , 3 , 0 ) ) ;
F_62 () ;
F_281 () ;
F_282 ( L_68 , F_250 ) ;
return 0 ;
V_500:
F_283 ( & V_43 -> V_44 ) ;
return V_42 ;
}
static int T_13 F_284 ( struct V_401 * V_43 )
{
F_283 ( & V_43 -> V_44 ) ;
F_285 () ;
return 0 ;
}
static int F_286 ( struct V_501 * V_44 )
{
V_3 . V_488 = false ;
F_270 () ;
F_287 ( V_3 . V_486 ) ;
F_9 () ;
return 0 ;
}
static int F_288 ( struct V_501 * V_44 )
{
if ( F_6 ( V_148 , 2 , 1 ) != V_462 ) {
F_263 () ;
F_56 () ;
}
V_3 . V_488 = true ;
F_270 () ;
return 0 ;
}
int T_10 F_289 ( void )
{
return F_290 ( & V_502 , F_274 ) ;
}
void T_13 F_291 ( void )
{
F_292 ( & V_502 ) ;
}
